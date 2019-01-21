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

import static processing.app.I18n.tr;

import java.util.Optional;

import cc.arduino.contributions.ProgressListener;
import cc.arduino.utils.MultiStepProgress;
import processing.app.BaseNoGui;
import processing.app.I18n;
import processing.app.helpers.ProcessUtils;

public class LibraryInstaller {

  public synchronized void updateIndex(ProgressListener progressListener) throws Exception {
    final MultiStepProgress progress = new MultiStepProgress(3);

    progress.setStatus(tr("Updating library index"));
    progress.stepDone();
    progressListener.onProgress(progress);

    Process pr = ProcessUtils.exec(new String[] { //
        BaseNoGui.getArduinoCliPath(), "lib", "update-index" });
    int exitCode = pr.waitFor();
    if (exitCode != 0) {
      throw new Exception(tr("An error occurred while updating libraries index!"));
    }
    progress.stepDone();

    // Step 2: Parse index
    BaseNoGui.librariesIndexer.parseIndex();

    // Step 3: Rescan index
    rescanLibraryIndex(progress, progressListener);
  }

  public synchronized void install(ContributedLibrary lib, ProgressListener progressListener) throws Exception {
    if (lib.isIDEBuiltIn()) {
      // If the desired library is available as builtin in the IDE just remove
      // the other installed in sketchbook...
      Optional<ContributedLibrary> current = lib.getReleases().getInstalled();
      if (current.isPresent()) {
        System.out.println(
          I18n.format(tr("Library {0} is available as built-in in the IDE.\nRemoving the other version {1} installed in the sketchbook..."),
            lib.getName() + ":" + lib.getVersion(), current.get().getVersion()));
        remove(current.get(), progressListener);
        return;
      }
      // ...otherwise output "library already installed"
    }

    if (lib.isLibraryInstalled()) {
      System.out.println(I18n.format(tr("Library is already installed: {0}:{1}"), lib.getName(), lib.getVersion()));
      return;
    }

    final MultiStepProgress progress = new MultiStepProgress(3);

    // Step 1: Download library
    String libTag = lib.getName() + "@" + lib.getVersion();
    Process pr = ProcessUtils.exec(new String[] { //
        BaseNoGui.getArduinoCliPath(), "lib", "install", libTag });
    int exitCode = pr.waitFor();
    if (exitCode != 0) {
      throw new Exception(tr("An error occurred while installing library!"));
    }

    // Step 2: Unpack library on the correct location
    progress.stepDone();

    // Step 3: Rescan index
    rescanLibraryIndex(progress, progressListener);
  }

  public synchronized void remove(ContributedLibrary lib, ProgressListener progressListener) throws Exception {
    final MultiStepProgress progress = new MultiStepProgress(2);

    // Step 1: Remove library
    String libTag = lib.getName() + "@" + lib.getVersion();
    Process pr = ProcessUtils.exec(new String[] { //
        BaseNoGui.getArduinoCliPath(), "lib", "uninstall", libTag });
    int exitCode = pr.waitFor();
    if (exitCode != 0) {
      throw new Exception(tr("An error occurred while uninstalling library!"));
    }
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

  // TODO: legacy messages already translated, keeping here until reused
  static {
    I18n.format(tr("Downloading library: {0}"), "libname");
    I18n.format(tr("Installing library: {0}:{1}"), "libname", "libversion");
    I18n.format(tr("Removing library: {0}:{1}"), "libname", "libversion");
  }
}
