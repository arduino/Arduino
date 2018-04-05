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
import cc.arduino.contributions.GZippedJsonDownloader;
import cc.arduino.contributions.ProgressListener;
import cc.arduino.utils.ArchiveExtractor;
import cc.arduino.utils.MultiStepProgress;
import processing.app.BaseNoGui;
import processing.app.I18n;
import processing.app.Platform;
import processing.app.helpers.FileUtils;

import java.io.File;
import java.io.IOException;
import java.net.URL;

import static processing.app.I18n.tr;

public class LibraryInstaller {

  private final Platform platform;

  public LibraryInstaller(Platform platform) {
    this.platform = platform;
  }

  public synchronized void updateIndex(ProgressListener progressListener) throws Exception {
    final MultiStepProgress progress = new MultiStepProgress(2);

    DownloadableContributionsDownloader downloader = new DownloadableContributionsDownloader(BaseNoGui.librariesIndexer.getStagingFolder());
    // Step 1: Download index
    File outputFile = BaseNoGui.librariesIndexer.getIndexFile();
    File tmpFile = new File(outputFile.getAbsolutePath() + ".tmp");
    try {
      GZippedJsonDownloader gZippedJsonDownloader = new GZippedJsonDownloader(downloader, new URL(Constants.LIBRARY_INDEX_URL), new URL(Constants.LIBRARY_INDEX_URL_GZ));
      gZippedJsonDownloader.download(tmpFile, progress, tr("Downloading libraries index..."), progressListener);
    } catch (InterruptedException e) {
      // Download interrupted... just exit
      return;
    }
    progress.stepDone();

    // TODO: Check downloaded index

    // Replace old index with the updated one
    if (outputFile.exists())
      outputFile.delete();
    if (!tmpFile.renameTo(outputFile))
      throw new Exception(tr("An error occurred while updating libraries index!"));

    // Step 2: Rescan index
    rescanLibraryIndex(progress, progressListener);
  }

  public synchronized void install(ContributedLibrary lib, ContributedLibrary replacedLib, ProgressListener progressListener) throws Exception {
    if (lib.isInstalled()) {
      System.out.println(I18n.format(tr("Library is already installed: {0} version {1}"), lib.getName(), lib.getParsedVersion()));
      return;
    }

    DownloadableContributionsDownloader downloader = new DownloadableContributionsDownloader(BaseNoGui.librariesIndexer.getStagingFolder());

    final MultiStepProgress progress = new MultiStepProgress(3);

    // Step 1: Download library
    try {
      downloader.download(lib, progress, I18n.format(tr("Downloading library: {0}"), lib.getName()), progressListener);
    } catch (InterruptedException e) {
      // Download interrupted... just exit
      return;
    }

    // TODO: Extract to temporary folders and move to the final destination only
    // once everything is successfully unpacked. If the operation fails remove
    // all the temporary folders and abort installation.

    // Step 2: Unpack library on the correct location
    progress.setStatus(I18n.format(tr("Installing library: {0}"), lib.getName()));
    progressListener.onProgress(progress);
    File libsFolder = BaseNoGui.librariesIndexer.getSketchbookLibrariesFolder();
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
    remove(replacedLib, progressListener);
    File destFolder = new File(libsFolder, lib.getName().replaceAll(" ", "_"));
    tmpFolder.renameTo(destFolder);
    progress.stepDone();

    // Step 4: Rescan index
    rescanLibraryIndex(progress, progressListener);
  }

  public synchronized void remove(ContributedLibrary lib, ProgressListener progressListener) throws IOException {
    if (lib == null || lib.isReadOnly()) {
      return;
    }

    final MultiStepProgress progress = new MultiStepProgress(2);

    // Step 1: Remove library
    progress.setStatus(I18n.format(tr("Removing library: {0}"), lib.getName()));
    progressListener.onProgress(progress);
    FileUtils.recursiveDelete(lib.getInstalledFolder());
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
