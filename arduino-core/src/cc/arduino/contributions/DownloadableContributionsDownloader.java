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

package cc.arduino.contributions;

import cc.arduino.utils.FileHash;
import cc.arduino.utils.MultiStepProgress;
import cc.arduino.utils.Progress;
import cc.arduino.utils.network.FileDownloader;
import org.apache.commons.io.FilenameUtils;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import processing.app.BaseNoGui;
import processing.app.PreferencesData;

import java.io.File;
import java.net.URL;
import java.nio.file.*;
import java.util.Collection;

import static processing.app.I18n.format;
import static processing.app.I18n.tr;

public class DownloadableContributionsDownloader {
  private static Logger log = LogManager.getLogger(DownloadableContributionsDownloader.class);

  private final File stagingFolder;

  public DownloadableContributionsDownloader(File _stagingFolder) {
    stagingFolder = _stagingFolder;
  }

  public File download(DownloadableContribution contribution, Progress progress, final String statusText, ProgressListener progressListener, boolean allowCache) throws Exception {
    return download(contribution, progress, statusText, progressListener, false, allowCache);
  }

  public File download(DownloadableContribution contribution, Progress progress, final String statusText, ProgressListener progressListener, boolean noResume, boolean allowCache) throws Exception {
    URL url = new URL(contribution.getUrl());
    // Filter out paths from file name
    String filename = new File(contribution.getArchiveFileName()).getName();
    Path outputFile = Paths.get(stagingFolder.getAbsolutePath(), filename).normalize();
    if (outputFile.toFile().isDirectory()) {
      throw new Exception(format("Can't download {0}: invalid filename or exinsting directory", contribution.getArchiveFileName()));
    }

    // Ensure the existence of staging folder
    Files.createDirectories(stagingFolder.toPath());

    if (!hasChecksum(contribution) && Files.exists(outputFile)) {
      Files.delete(outputFile);
    }

    boolean downloaded = false;
    while (true) {
      // Need to download or resume downloading?
      if (!Files.isRegularFile(outputFile, LinkOption.NOFOLLOW_LINKS) || (Files.size(outputFile) < contribution.getSize())) {
        download(url, outputFile.toFile(), progress, statusText, progressListener, noResume, allowCache);
        downloaded = true;
      }

      // Test checksum
      progress.setStatus(tr("Verifying archive integrity..."));
      progressListener.onProgress(progress);
      if (hasChecksum(contribution)) {
        String checksum = contribution.getChecksum();
        String algo = checksum.split(":")[0];
        String crc = FileHash.hash(outputFile.toFile(), algo);
        if (!crc.equalsIgnoreCase(checksum)) {
          // If the file has not been downloaded it may be a leftover of
          // a previous download that failed. In this case delete it and
          // try to download it again.
          if (!downloaded) {
            Files.delete(outputFile);
            downloaded = true; // Redundant to avoid loops in case delete fails
            continue;
          }

          // Otherwise throw the error.
          throw new Exception(tr("CRC doesn't match, file is corrupted. It may be a temporary problem, please retry later."));
        }
      }

      // Download completed successfully
      break;
    }

    contribution.setDownloaded(true);
    contribution.setDownloadedFile(outputFile.toFile());
    return outputFile.toFile();
  }

  private boolean hasChecksum(DownloadableContribution contribution) {
    String checksum = contribution.getChecksum();
    if (checksum == null || checksum.isEmpty()) {
      return false;
    }

    String algo = checksum.split(":")[0];

    return algo != null && !algo.isEmpty();
  }

  public void download(URL url, File tmpFile, Progress progress, String statusText, ProgressListener progressListener, boolean allowCache) throws Exception {
    download(url, tmpFile, progress, statusText, progressListener, false, allowCache);
  }

  public void download(URL url, File tmpFile, Progress progress, String statusText, ProgressListener progressListener, boolean noResume, boolean allowCache) throws Exception {
    final FileDownloader downloader = new FileDownloader(url, tmpFile, allowCache);
    downloader.addObserver((o, arg) -> {
      FileDownloader me = (FileDownloader) o;
      String msg = "";
      if (me.getDownloadSize() != null) {
        long downloaded = (me.getInitialSize() + me.getDownloaded()) / 1000;
        long total = (me.getInitialSize() + me.getDownloadSize()) / 1000;
        msg = format(tr("Downloaded {0}kb of {1}kb."), downloaded, total);
      }
      progress.setStatus(statusText + " " + msg);
      progress.setProgress(me.getProgress());
      progressListener.onProgress(progress);
    });
    downloader.download(noResume);
    if (!downloader.isCompleted()) {
      throw new Exception(format(tr("Error downloading {0}"), url), downloader.getError());
    }
  }

  public void downloadIndexAndSignature(MultiStepProgress progress, URL packageIndexUrl, ProgressListener progressListener, SignatureVerifier signatureVerifier) throws Exception {

    // Extract the file name from the url
    final String indexFileName = FilenameUtils.getName(packageIndexUrl.getPath());
    final File packageIndex = BaseNoGui.indexer.getIndexFile(indexFileName);

    final String statusText = tr("Downloading platforms index...");

    // Create temp files
    final File packageIndexTemp = File.createTempFile(indexFileName, ".tmp");
    try {
      // Download package index
      download(packageIndexUrl, packageIndexTemp, progress, statusText, progressListener, true, true);
      final URL signatureUrl = new URL(packageIndexUrl.toString() + ".sig");

      if (verifyDomain(packageIndexUrl)) {
        if (checkSignature(progress, signatureUrl, progressListener, signatureVerifier, statusText, packageIndexTemp)) {
          Files.move(packageIndexTemp.toPath(), packageIndex.toPath(), StandardCopyOption.REPLACE_EXISTING);
        } else {
          log.info("The cached files have been removed. {} {}", packageIndexUrl, signatureUrl);
          FileDownloader.invalidateFiles(packageIndexUrl, signatureUrl);
        }
      } else {
        // Move the package index to the destination when the signature is not necessary
        Files.move(packageIndexTemp.toPath(), packageIndex.toPath(), StandardCopyOption.REPLACE_EXISTING);
        log.info("The domain is not selected to verify the signature. will be copied into this path {}, packageIndex url: {}", packageIndex, packageIndexUrl);
      }
    } catch (Exception e) {
      log.error("Cannot download the package index from {} the package will be discard", packageIndexUrl, e);
      throw e;
    } finally {
      // Delete useless temp file
      Files.deleteIfExists(packageIndexTemp.toPath());
    }
  }

  public boolean verifyDomain(URL url) {
    final Collection<String> domain = PreferencesData.
      getCollection("http.signature_verify_domains");
    if (domain.size() == 0) {
      // Default domain
      domain.add("downloads.arduino.cc");
    }
    if (domain.contains(url.getHost())) {
      return true;
    } else {
      log.info("The domain is not selected to verify the signature. domain list: {}, url: {}", domain, url);
      return false;
    }
  }

  public boolean checkSignature(MultiStepProgress progress, URL signatureUrl, ProgressListener progressListener, SignatureVerifier signatureVerifier, String statusText, File fileToVerify) throws Exception {


    // Signature file name
    final String signatureFileName = FilenameUtils.getName(signatureUrl.getPath());
    final File packageIndexSignature = BaseNoGui.indexer.getIndexFile(signatureFileName);
    final File packageIndexSignatureTemp = File.createTempFile(signatureFileName, ".tmp");


    try {
      // Download signature
      download(signatureUrl, packageIndexSignatureTemp, progress, statusText, progressListener, true);

      if (PreferencesData.areInsecurePackagesAllowed()) {
        Files.move(packageIndexSignatureTemp.toPath(), packageIndexSignature.toPath(), StandardCopyOption.REPLACE_EXISTING);
        log.info("Allowing insecure packages because allow_insecure_packages is set to true in preferences.txt" +
          " but the signature was download");
        return true;
      }

      // Verify the signature before move the files
      final boolean signatureVerified = signatureVerifier.isSigned(fileToVerify, packageIndexSignatureTemp);
      if (signatureVerified) {
        log.info("Signature verified. url={}, signature url={}, file to verify={}, signature file={}", signatureUrl, signatureUrl, fileToVerify, packageIndexSignatureTemp);
        // Move if the signature is ok
        Files.move(packageIndexSignatureTemp.toPath(), packageIndexSignature.toPath(), StandardCopyOption.REPLACE_EXISTING);
      } else {
        log.error("{} file signature verification failed. File ignored.", signatureUrl);
        System.err.println(format(tr("{0} file signature verification failed. File ignored."), signatureUrl.toString()));
      }
      return signatureVerified;
    } catch (Exception e) {
      log.error("Cannot download the signature from {} the package will be discard", signatureUrl, e);
      throw e;
    } finally {
      Files.deleteIfExists(packageIndexSignatureTemp.toPath());
    }

  }

}
