/*
 * This file is part of Arduino.
 *
 * Copyright 2014 Arduino LLC (http://www.arduino.cc/)
 *
 * Arduino is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * As a special exception, you may use this file as part of a free software
 * library without restriction.  Specifically, if other files instantiate
 * templates or use macros or inline functions from this file, or you compile
 * this file and link it with other files to produce an executable, this
 * file does not by itself cause the resulting executable to be covered by
 * the GNU General Public License.  This exception does not however
 * invalidate any other reasons why the executable file might be covered by
 * the GNU General Public License.
 */

package cc.arduino.utils.network;

import org.apache.commons.compress.utils.IOUtils;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import processing.app.helpers.FileUtils;

import javax.script.ScriptException;
import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.io.RandomAccessFile;
import java.net.HttpURLConnection;
import java.net.SocketTimeoutException;
import java.net.URISyntaxException;
import java.net.URL;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Arrays;
import java.util.Observable;
import java.util.Optional;

public class FileDownloader extends Observable {
  private static Logger log = LogManager.getLogger(FileDownloader.class);

  public enum Status {
    CONNECTING, //
    CONNECTION_TIMEOUT_ERROR, //
    DOWNLOADING, //
    COMPLETE, //
    CANCELLED, //
    ERROR, //
  }

  private Status status;
  private long initialSize;
  private Long downloadSize = null;
  private long downloaded;
  private final URL downloadUrl;

  private final File outputFile;
  private final boolean allowCache;
  private Exception error;

  public FileDownloader(URL url, File file, boolean allowCache) {
    this.downloadUrl = url;
    this.outputFile = file;
    this.allowCache = allowCache;
    this.downloaded = 0;
    this.initialSize = 0;
  }

  public long getInitialSize() {
    return initialSize;
  }

  public Long getDownloadSize() {
    return downloadSize;
  }

  public void setDownloadSize(Long downloadSize) {
    this.downloadSize = downloadSize;
    setChanged();
    notifyObservers();
  }

  public long getDownloaded() {
    return downloaded;
  }

  private void setDownloaded(long downloaded) {
    this.downloaded = downloaded;
    setChanged();
    notifyObservers();
  }

  public float getProgress() {
    if (downloadSize == null)
      return 0;
    if (downloadSize == 0)
      return 100;
    return ((float) downloaded / downloadSize) * 100;
  }

  public Status getStatus() {
    return status;
  }

  public void setStatus(Status status) {
    this.status = status;
    setChanged();
    notifyObservers();
  }


  public void download(boolean noResume) throws InterruptedException {
    if ("file".equals(downloadUrl.getProtocol())) {
      saveLocalFile();
    } else {
      downloadFile(noResume);
    }
  }

  private void saveLocalFile() {
    try {
      Files.write(outputFile.toPath(), Files.readAllBytes(Paths.get(downloadUrl.getPath())));
      setStatus(Status.COMPLETE);
    } catch (Exception e) {
      setStatus(Status.ERROR);
      setError(e);
    }
  }

  public static void invalidateFiles(URL... filesUrl) {
    // For each file delete the file cached if exist
    Arrays.stream(filesUrl).forEach(url -> {
      try {
        FileDownloaderCache.getFileCached(url).ifPresent(fileCached -> {
          try {
            log.info("Invalidate this file {} that comes from {}", fileCached.getLocalPath(), fileCached.getRemoteURL());
            fileCached.invalidateCache();
          } catch (Exception e) {
            log.warn("Fail to invalidate cache", e);
          }
        });
      } catch (URISyntaxException | NoSuchMethodException | ScriptException | IOException e) {
        log.warn("Fail to get the file cached during the file invalidation", e);
      }
    });

  }

  private void downloadFile(boolean noResume) throws InterruptedException {

    try {
      setStatus(Status.CONNECTING);

      final Optional<FileDownloaderCache.FileCached> fileCachedOpt = FileDownloaderCache.getFileCached(downloadUrl, allowCache);
      if (fileCachedOpt.isPresent()) {
        final FileDownloaderCache.FileCached fileCached = fileCachedOpt.get();

        final Optional<File> fileFromCache = getFileCached(fileCached);
        if (fileCached.isNotChange() && fileFromCache.isPresent()) {
          // Copy the cached file in the destination file
          log.info("The file will be taken from the cache {}", fileFromCache);
          FileUtils.copyFile(fileFromCache.get(), outputFile);
        } else {
          openConnectionAndFillTheFile(noResume);

          fileCached.updateCacheFile(outputFile);
        }
      } else {
        openConnectionAndFillTheFile(noResume);
      }
      setStatus(Status.COMPLETE);

    } catch (InterruptedException e) {
      setStatus(Status.CANCELLED);
      // lets InterruptedException go up to the caller
      throw e;

    } catch (SocketTimeoutException e) {
      setStatus(Status.CONNECTION_TIMEOUT_ERROR);
      setError(e);
      log.error("The request went in socket timeout", e);

    } catch (Exception e) {
      setStatus(Status.ERROR);
      setError(e);
      log.error("The request stop", e);
    }

  }

  private Optional<File> getFileCached(FileDownloaderCache.FileCached fileCached) {

    try {
      final Optional<File> fileFromCache =
        fileCached.getFileFromCache();
      if (fileFromCache.isPresent()) {
        log.info("No need to download using cached file: {}", fileCached);
        return fileFromCache;
      } else {
        log.info(
          "The file in the cache is not in the path or the md5 validation failed: path={}, file exist={}, md5 validation={}",
          fileCached.getLocalPath(), fileCached.exists(), fileCached.md5Check());
      }
    } catch (Exception e) {
      log.warn(
        "Cannot get the file from the cache, will be downloaded a new one ", e);
    }
    log.info("The file is change {}", fileCached);
    return Optional.empty();
  }

  private void openConnectionAndFillTheFile(boolean noResume) throws Exception {
    initialSize = outputFile.length();
    if (noResume && initialSize > 0) {
      // delete file and restart downloading
      Files.deleteIfExists(outputFile.toPath());
      initialSize = 0;
    }

    final HttpURLConnection connection = new HttpConnectionManager(downloadUrl)
      .makeConnection((c) -> setDownloaded(0));
    final int resp = connection.getResponseCode();

    if (resp < 200 || resp >= 300) {
      Files.deleteIfExists(outputFile.toPath());
      throw new IOException("Received invalid http status code from server: " + resp);
    }

    RandomAccessFile randomAccessOutputFile = null;
    try {
      // Open file and seek to the end of it
      randomAccessOutputFile = new RandomAccessFile(outputFile, "rw");
      randomAccessOutputFile.seek(initialSize);
      readStreamCopyTo(randomAccessOutputFile, connection);
    } finally {
      IOUtils.closeQuietly(randomAccessOutputFile);
    }

  }

  private void readStreamCopyTo(RandomAccessFile randomAccessOutputFile, HttpURLConnection connection) throws Exception {
    InputStream stream = null;
    try {
      // Check for valid content length.
      long len = connection.getContentLength();
      if (len >= 0) {
        setDownloadSize(len);
      }
      setStatus(Status.DOWNLOADING);

      stream = connection.getInputStream();

      byte[] buffer = new byte[10240];
      while (status == Status.DOWNLOADING) {
        int read = stream.read(buffer);
        if (read == -1)
          break;

        randomAccessOutputFile.write(buffer, 0, read);
        setDownloaded(getDownloaded() + read);

        if (Thread.interrupted()) {
          randomAccessOutputFile.close();
          throw new InterruptedException();
        }
      }

      if (getDownloadSize() != null) {
        if (getDownloaded() < getDownloadSize())
          throw new Exception("Incomplete download");
      }
    } finally {
      IOUtils.closeQuietly(stream);
    }
  }

  private void setError(Exception e) {
    error = e;
  }

  public Exception getError() {
    return error;
  }

  public boolean isCompleted() {
    return status == Status.COMPLETE;
  }
}
