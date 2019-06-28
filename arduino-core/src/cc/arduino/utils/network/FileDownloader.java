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
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import processing.app.BaseNoGui;
import processing.app.helpers.FileUtils;

import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.io.RandomAccessFile;
import java.net.HttpURLConnection;
import java.net.SocketTimeoutException;
import java.net.URL;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Observable;
import java.util.Optional;

public class FileDownloader extends Observable {
  private static Logger log = LoggerFactory.getLogger(FileDownloader.class);

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
  private InputStream stream = null;
  private Exception error;

  public FileDownloader(URL url, File file) {
    downloadUrl = url;
    outputFile = file;
    downloaded = 0;
    initialSize = 0;
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

  public void download() throws InterruptedException {
    download(false);
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

  private void downloadFile(boolean noResume) throws InterruptedException {
    RandomAccessFile randomAccessOutputFile = null;

    try {
      setStatus(Status.CONNECTING);

      final File settingsFolder = BaseNoGui.getPlatform().getSettingsFolder();
      final String cacheFolder = Paths.get(settingsFolder.getPath(), "cache").toString();
      final FileDownloaderCache fileDownloaderCache =
        new FileDownloaderCache(cacheFolder, downloadUrl);

      final boolean isChanged = fileDownloaderCache.checkIfTheFileIsChanged();

      if (!isChanged) {
        try {
          final Optional<File> fileFromCache =
            fileDownloaderCache.getFileFromCache();
          if (fileFromCache.isPresent()) {
            FileUtils.copyFile(fileFromCache.get(), outputFile);
            setStatus(Status.COMPLETE);
            return;
          }
        } catch (Exception e) {
          log.warn(
            "Cannot get the file from the cache, will be downloaded a new one ", e.getCause());

        }
      }

      // Open file and seek to the end of it
      randomAccessOutputFile = new RandomAccessFile(outputFile, "rw");
      initialSize = randomAccessOutputFile.length();

      if (noResume && initialSize > 0) {
        // delete file and restart downloading
        Files.delete(outputFile.toPath());
        initialSize = 0;
      }

      randomAccessOutputFile.seek(initialSize);

      final HttpURLConnection connection = new HttpConnectionManager(downloadUrl)
        .makeConnection((c) -> setDownloaded(0));
      final int resp = connection.getResponseCode();

      if (resp < 200 || resp >= 300) {
        Files.delete(outputFile.toPath());
        throw new IOException("Received invalid http status code from server: " + resp);
      }

      // Check for valid content length.
      long len = connection.getContentLength();
      if (len >= 0) {
        setDownloadSize(len);
      }
      setStatus(Status.DOWNLOADING);

      synchronized (this) {
        stream = connection.getInputStream();
      }
      byte buffer[] = new byte[10240];
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
      // Set the cache whe it finish to download the file
      IOUtils.closeQuietly(randomAccessOutputFile);
      fileDownloaderCache.fillCache(outputFile);
      setStatus(Status.COMPLETE);
    } catch (InterruptedException e) {
      setStatus(Status.CANCELLED);
      // lets InterruptedException go up to the caller
      throw e;

    } catch (SocketTimeoutException e) {
      setStatus(Status.CONNECTION_TIMEOUT_ERROR);
      setError(e);

    } catch (Exception e) {
      setStatus(Status.ERROR);
      setError(e);

    } finally {
      IOUtils.closeQuietly(randomAccessOutputFile);

      synchronized (this) {
        IOUtils.closeQuietly(stream);
      }
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
