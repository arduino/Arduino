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

import cc.arduino.contributions.VersionComparator;
import processing.app.packages.UserLibraryFolder.Location;

import java.util.LinkedList;
import java.util.List;
import java.util.Optional;

public class ContributedLibraryReleases {

  private List<ContributedLibrary> releases = new LinkedList<>();
  private List<String> versions = new LinkedList<>();
  private ContributedLibrary latest = null;
  private ContributedLibrary selected = null;

  public ContributedLibraryReleases(ContributedLibrary library) {
    add(library);
  }

  public ContributedLibraryReleases(List<ContributedLibrary> libraries) {
    libraries.forEach(this::add);
  }

  public List<ContributedLibrary> getReleases() {
    return releases;
  }

  public boolean shouldContain(ContributedLibrary lib) {
    if (latest == null) {
      return true;
    }
    return lib.getName().equals(latest.getName());
  }

  public void add(ContributedLibrary library) {
    if (latest == null) {
      latest = library;
    }
    releases.add(library);
    String version = library.getParsedVersion();
    if (version != null) {
      versions.add(version);
    }
    if (VersionComparator.greaterThan(version, latest.getParsedVersion())) {
      latest = library;
    }
    selected = latest;
  }

  public Optional<ContributedLibrary> getInstalled() {
    return releases.stream() //
        .filter(ContributedLibrary::isLibraryInstalled) //
        .reduce((x, y) -> {
          Location lx = x.getInstalledLibrary().get().getLocation();
          Location ly = y.getInstalledLibrary().get().getLocation();
          if (lx == ly) {
            return VersionComparator.max(x, y);
          }
          return lx == Location.SKETCHBOOK ? x : y;
        });
  }

  public ContributedLibrary getLatest() {
    return latest;
  }

  public ContributedLibrary getSelected() {
    return selected;
  }

  public void select(ContributedLibrary lib) {
    for (ContributedLibrary r : releases) {
      if (r == lib) {
        selected = r;
        return;
      }
    }
  }
}
