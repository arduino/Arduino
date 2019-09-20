/*
 * This file is part of Arduino.
 *
 * Copyright 2015 Arduino LLC (http://www.arduino.cc/)
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

package cc.arduino.contributions.libraries;

import cc.arduino.Constants;
import cc.arduino.contributions.DownloadableContributionsDownloader;
import cc.arduino.contributions.GPGDetachedSignatureVerifier;
import cc.arduino.contributions.GZippedJsonDownloader;
import cc.arduino.contributions.ProgressListener;
import cc.arduino.utils.ArchiveExtractor;
import cc.arduino.utils.MultiStepProgress;
import cc.arduino.utils.network.FileDownloader;
import org.apache.commons.io.FilenameUtils;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import processing.app.BaseNoGui;
import processing.app.I18n;
import processing.app.Platform;
import processing.app.helpers.FileUtils;

import java.io.File;
import java.io.IOException;
import java.net.URL;
import java.nio.file.Files;
import java.nio.file.StandardCopyOption;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

import static processing.app.I18n.tr;

public class LibraryInstaller {
  private static Logger log = LogManager.getLogger(LibraryInstaller.class);

  private final Platform platform;
  private final GPGDetachedSignatureVerifier signatureVerifier;

  public LibraryInstaller(Platform platform, GPGDetachedSignatureVerifier signatureVerifier) {
    this.platform = platform;
    this.signatureVerifier = signatureVerifier;
  }

  public synchronized void updateIndex(ProgressListener progressListener) throws Exception {
    final MultiStepProgress progress = new MultiStepProgress(3);

    DownloadableContributionsDownloader downloader = new DownloadableContributionsDownloader(BaseNoGui.librariesIndexer.getStagingFolder());
    // Step 1: Download index
    File outputFile = BaseNoGui.librariesIndexer.getIndexFile();
    // Create temp files
    String signatureFileName = FilenameUtils.getName(new URL(Constants.LIBRARY_INDEX_URL).getPath());
    File libraryIndexTemp = File.createTempFile(signatureFileName, ".tmp");
    final URL libraryURL = new URL(Constants.LIBRARY_INDEX_URL);
    final URL libraryGzURL = new URL(Constants.LIBRARY_INDEX_URL_GZ);
    final String statusText = tr("Downloading libraries index...");
    try {
      GZippedJsonDownloader gZippedJsonDownloader = new GZippedJsonDownloader(downloader, libraryURL, libraryGzURL);
      gZippedJsonDownloader.download(libraryIndexTemp, progress, statusText, progressListener, true);
    } catch (InterruptedException e) {
      // Download interrupted... just exit
      return;
    }
    progress.stepDone();

    URL signatureUrl = new URL(libraryURL.toString() + ".sig");
    if (downloader.verifyDomain(signatureUrl)) {
      if (downloader.checkSignature(progress, signatureUrl, progressListener, signatureVerifier, statusText, libraryIndexTemp)) {
        // Replace old index with the updated one
        if (libraryIndexTemp.length() > 0) {
          Files.move(libraryIndexTemp.toPath(), outputFile.toPath(), StandardCopyOption.REPLACE_EXISTING);
        }
      } else {
        FileDownloader.invalidateFiles(libraryGzURL, libraryURL, signatureUrl);
        log.error("Fail to verify the signature of {} the cached files have been removed", libraryURL);
      }
    } else {
      log.info("The domain is not selected to verify the signature. library index: {}", signatureUrl);
    }

    // Step 2: Parse index
    BaseNoGui.librariesIndexer.parseIndex();

    // Step 3: Rescan index
    rescanLibraryIndex(progress, progressListener);

  }

  public void install(ContributedLibrary lib, ProgressListener progressListener) throws Exception {
    ArrayList<ContributedLibrary> libs = new ArrayList<>();
    libs.add(lib);
    install(libs, progressListener);
  }

  public synchronized void install(List<ContributedLibrary> libs, ProgressListener progressListener) throws Exception {
    MultiStepProgress progress = new MultiStepProgress(3 * libs.size() + 1);

    for (ContributedLibrary lib : libs) {
      // Do install library (3 steps)
      performInstall(lib, progressListener, progress);
    }

    // Rescan index (1 step)
    rescanLibraryIndex(progress, progressListener);
  }

  private void performInstall(ContributedLibrary lib, ProgressListener progressListener, MultiStepProgress progress) throws Exception {
    if (lib.isLibraryInstalled()) {
      System.out.println(I18n.format(tr("Library is already installed: {0}:{1}"), lib.getName(), lib.getParsedVersion()));
      return;
    }

    File libsFolder = BaseNoGui.getSketchbookLibrariesFolder().folder;
    File destFolder = new File(libsFolder, lib.getName().replaceAll(" ", "_"));

    // Check if we are replacing an already installed lib
    LibrariesIndex index = BaseNoGui.librariesIndexer.getIndex();
    Optional<ContributedLibrary> replacedLib = index.find(lib.getName()).stream() //
        .filter(l -> l.getInstalledLibrary().isPresent()) //
        .filter(l -> l.getInstalledLibrary().get().getInstalledFolder().equals(destFolder)) //
        .findAny();
    if (!replacedLib.isPresent() && destFolder.exists()) {
      System.out.println(I18n.format(tr("Library {0} is already installed in: {1}"), lib.getName(), destFolder));
      return;
    }
    DownloadableContributionsDownloader downloader = new DownloadableContributionsDownloader(BaseNoGui.librariesIndexer.getStagingFolder());

    // Step 1: Download library
    try {
      downloader.download(lib, progress, I18n.format(tr("Downloading library: {0}"), lib.getName()), progressListener, false);
    } catch (InterruptedException e) {
      // Download interrupted... just exit
      return;
    }
    progress.stepDone();

    // TODO: Extract to temporary folders and move to the final destination only
    // once everything is successfully unpacked. If the operation fails remove
    // all the temporary folders and abort installation.

    // Step 2: Unpack library on the correct location
    progress.setStatus(I18n.format(tr("Installing library: {0}:{1}"), lib.getName(), lib.getParsedVersion()));
    progressListener.onProgress(progress);
    File tmpFolder = FileUtils.createTempFolder(libsFolder);
    try {
      new ArchiveExtractor(platform).extract(lib.getDownloadedFile(), tmpFolder, 1);
    } catch (Exception e) {
      if (tmpFolder.exists())
        FileUtils.recursiveDelete(tmpFolder);
    }
    progress.stepDone();

    // Step 3: Remove replaced library and move installed one to the correct location
    // TODO: Fix progress bar...
    if (replacedLib.isPresent()) {
      remove(replacedLib.get(), progressListener);
    }
    tmpFolder.renameTo(destFolder);
    progress.stepDone();
  }

  public synchronized void remove(ContributedLibrary lib, ProgressListener progressListener) throws IOException {
    if (lib.isIDEBuiltIn()) {
      return;
    }

    final MultiStepProgress progress = new MultiStepProgress(2);

    // Step 1: Remove library
    progress.setStatus(I18n.format(tr("Removing library: {0}:{1}"), lib.getName(), lib.getParsedVersion()));
    progressListener.onProgress(progress);
    FileUtils.recursiveDelete(lib.getInstalledLibrary().get().getInstalledFolder());
    progress.stepDone();

    // Step 2: Rescan index
    rescanLibraryIndex(progress, progressListener);
  }

  private void rescanLibraryIndex(MultiStepProgress progress, ProgressListener progressListener) {
    progress.setStatus(tr("Updating list of installed libraries"));
    progressListener.onProgress(progress);
    BaseNoGui.librariesIndexer.rescanLibraries();
    progress.stepDone();
  }
}
