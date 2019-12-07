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

package cc.arduino.contributions.libraries;

import static processing.app.I18n.format;
import static processing.app.I18n.tr;
import static processing.app.packages.UserLibrary.LOCATION_CORE;
import static processing.app.packages.UserLibrary.LOCATION_REF_CORE;
import static processing.app.packages.UserLibrary.LOCATION_SKETCHBOOK;

import java.io.File;
import java.io.IOException;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Optional;

import cc.arduino.cli.ArduinoCoreInstance;
import cc.arduino.cli.commands.Lib.InstalledLibrary;
import cc.arduino.cli.commands.Lib.Library;
import cc.arduino.contributions.packages.ContributedPlatform;
import io.grpc.StatusException;
import processing.app.BaseNoGui;
import processing.app.debug.TargetPlatform;
import processing.app.helpers.FileUtils;
import processing.app.packages.LibraryList;
import processing.app.packages.UserLibrary;
import processing.app.packages.UserLibraryPriorityComparator;

public class LibrariesIndexer {

  private LibrariesIndex index;
  private final LibraryList installedLibraries = new LibraryList();

  private ArduinoCoreInstance core;

  public LibrariesIndexer(ArduinoCoreInstance core) {
    this.core = core;
  }

  public void regenerateIndex() {
    index = new LibrariesIndex();
    try {
      core.searchLibrary("").forEach(inLib -> {
        ContributedLibrary library = new ContributedLibrary(inLib.getName());
        inLib.getReleasesMap().forEach((ver, rel) -> {
          ContributedLibraryRelease release = new ContributedLibraryRelease(
              library, //
              rel.getMaintainer(), //
              rel.getAuthor(), //
              rel.getWebsite(), //
              rel.getCategory(), //
              "", // TODO: license
              rel.getParagraph(), //
              rel.getSentence(), //
              rel.getArchitecturesList(), //
              rel.getTypesList(), //
              null, // TODO: dependencies - List<ContributedLibraryDependency>
              null, // TODO: providesIncludes - List<String>
              //
              rel.getResources().getUrl(), //
              rel.getVersion(), //
              rel.getResources().getChecksum(), //
              rel.getResources().getSize(), //
              rel.getResources().getArchivefilename());
          library.addRelease(release);
        });
        index.add(library);
      });
    } catch (StatusException e) {
      e.printStackTrace();
    }

//     format(tr("Error parsing libraries index: {0}\nTry to open the Library Manager to update the libraries index."),
//     System.err.println(format(tr("Error reading libraries index: {0}"),
    rescanLibraries();
  }

  private Comparator<UserLibrary> priorityComparator = new UserLibraryPriorityComparator(
      null);

  public void addToInstalledLibraries(UserLibrary lib) throws IOException {
    UserLibrary toReplace = installedLibraries.getByName(lib.getName());
    if (toReplace == null) {
      installedLibraries.add(lib);
    } else if (priorityComparator.compare(toReplace, lib) >= 0) {
      // The current lib has priority, do nothing
    } else {
      installedLibraries.remove(toReplace);
      installedLibraries.add(lib);
    }
  }

  public void setArchitecturePriority(String arch) {
    priorityComparator = new UserLibraryPriorityComparator(arch);
  }

  public void rescanLibraries() {
    // Clear all installed flags
    installedLibraries.clear();

    if (index.getLibraries() == null) {
      return;
    }

    index.getLibraries().forEach(l -> {
      l.getReleases().forEach(r -> {
        r.unsetInstalledUserLibrary();
      });
    });

    // Rescan libraries
    List<InstalledLibrary> installedLibsMeta;
    try {
      installedLibsMeta = core.libraryList(true);
    } catch (StatusException e) {
      e.printStackTrace();
      return;
    }

    File coreLibsDir = null;
    File refcoreLibsDir = null;
    Optional<TargetPlatform> targetPlatform = BaseNoGui.getTargetPlatform();
    if (targetPlatform.isPresent()) {
      String buildCore = BaseNoGui.getBoardPreferences().get("build.core", "arduino");
      if (buildCore.contains(":")) {
        String referencedCore = buildCore.split(":")[0];
        Optional<TargetPlatform> referencedPlatform = BaseNoGui.getTargetPlatform(referencedCore, targetPlatform.get().getId());
        if (referencedPlatform.isPresent()) {
          File referencedPlatformFolder = referencedPlatform.get().getFolder();
          // Add libraries folder for the referenced platform
          refcoreLibsDir = new File(referencedPlatformFolder, "libraries");
        }
      }
      File platformFolder = targetPlatform.get().getFolder();
      // Add libraries folder for the selected platform
      coreLibsDir = new File(platformFolder, "libraries");
    }

    for (InstalledLibrary meta : installedLibsMeta) {
      Library l = meta.getLibrary();

      // Skip platform-related libraries that are not part of the currently
      // selected platform/board.
      if (l.getLocation().equals("platform")) {
        File libDir = new File(l.getInstallDir());
        boolean isCoreLib = (coreLibsDir != null)
                            && FileUtils.isSubDirectory(coreLibsDir, libDir);
        boolean isRefCoreLib = (refcoreLibsDir != null) //
                               && FileUtils.isSubDirectory(refcoreLibsDir,
                                                           libDir);
        if (!isCoreLib && !isRefCoreLib) {
          continue;
        }
      }

      UserLibrary lib = new UserLibrary( //
          new File(l.getInstallDir()), //
          l.getRealName(), //
          l.getVersion(), //
          l.getAuthor(), //
          l.getMaintainer(), //
          l.getSentence(), //
          l.getParagraph(), //
          l.getWebsite(), //
          l.getCategory(), //
          l.getLicense(), //
          l.getArchitecturesList(), //
          l.getLayout(), //
          l.getTypesList(), //
          false, // TODO: onGoingDevelopment
          null, // TODO: includes
          l.getLocation() //
      );

      try {
        String[] headers = BaseNoGui
            .headerListFromIncludePath(lib.getSrcFolder()); // TODO: Obtain from the CLI?
        if (headers.length == 0) {
          throw new IOException(format(tr("no headers files (.h) found in {0}"),
                                       lib.getSrcFolder()));
        }

        String loc = lib.getLocation();
        if (!loc.equals(LOCATION_CORE) && !loc.equals(LOCATION_REF_CORE)) {
          // Check if we can find the same library in the index
          // and mark it as installed
          index.find(lib.getName(), lib.getVersion()).ifPresent(foundLib -> {
            foundLib.setInstalledUserLibrary(lib);
            lib.setTypes(foundLib.getTypes());
          });
        }

        if (lib.getTypes().isEmpty() && loc.equals(LOCATION_SKETCHBOOK)) {
          lib.setTypes(lib.getDeclaredTypes());
        }

        if (lib.getTypes().isEmpty()) {
          lib.setTypes(Collections.singletonList("Contributed"));
        }

        addToInstalledLibraries(lib);
      } catch (Exception e) {
        e.printStackTrace();
      }
    }

    // TODO: Should be done on the CLI?
    installedLibraries.stream() //
        .filter(l -> l.getTypes().contains("Contributed")) //
        .filter(l -> l.getLocation().equals(LOCATION_CORE)
                     || l.getLocation().equals(LOCATION_REF_CORE)) //
        .forEach(l -> {
          File libFolder = l.getInstalledFolder();
          Optional<ContributedPlatform> platform = BaseNoGui.indexer
              .getPlatformByFolder(libFolder);
          if (platform.isPresent()) {
            l.setTypes(Collections.singletonList(platform.get().getCategory()));
          }
        });
  }

//          String mess = I18n.format(
//                                    tr("The library \"{0}\" cannot be used.\n"
//                                       + "Library folder names must start with a letter or number, followed by letters,\n"
//                                       + "numbers, dashes, dots and underscores. Maximum length is 63 characters."),
//                                    subfolderName);
//          BaseNoGui.showMessage(tr("Ignoring library with bad name"), mess);

//    System.out.println(I18n.format(tr("Invalid library found in {0}: {1}"),
//                                       subfolder, e.getMessage()));

  public LibrariesIndex getIndex() {
    return index;
  }

  public LibraryList getInstalledLibraries() {
    return new LibraryList(installedLibraries);
  }
}
