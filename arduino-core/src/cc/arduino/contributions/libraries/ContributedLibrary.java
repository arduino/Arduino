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

public class ContributedLibrary {

  private List<ContributedLibraryRelease> releases = new LinkedList<>();
  private List<String> versions = new LinkedList<>();
  private ContributedLibraryRelease latest = null;
  private ContributedLibraryRelease selected = null;

  public ContributedLibrary(ContributedLibraryRelease release) {
    add(release);
  }

  public ContributedLibrary(List<ContributedLibraryRelease> releases) {
    releases.forEach(this::add);
  }

  public List<ContributedLibraryRelease> getReleases() {
    return releases;
  }

  public boolean shouldContain(ContributedLibraryRelease release) {
    if (latest == null) {
      return true;
    }
    return release.getName().equals(latest.getName());
  }

  public void add(ContributedLibraryRelease release) {
    if (latest == null) {
      latest = release;
    }
    releases.add(release);
    String version = release.getParsedVersion();
    if (version != null) {
      versions.add(version);
    }
    if (VersionComparator.greaterThan(version, latest.getParsedVersion())) {
      latest = release;
    }
    selected = latest;
  }

  public Optional<ContributedLibraryRelease> getInstalled() {
    return releases.stream() //
        .filter(ContributedLibraryRelease::isLibraryInstalled) //
        .reduce((x, y) -> {
          Location lx = x.getInstalledLibrary().get().getLocation();
          Location ly = y.getInstalledLibrary().get().getLocation();
          if (lx == ly) {
            return VersionComparator.max(x, y);
          }
          return lx == Location.SKETCHBOOK ? x : y;
        });
  }

  public ContributedLibraryRelease getLatest() {
    return latest;
  }

  public ContributedLibraryRelease getSelected() {
    return selected;
  }

  public void select(ContributedLibraryRelease lib) {
    for (ContributedLibraryRelease r : releases) {
      if (r == lib) {
        selected = r;
        return;
      }
    }
  }
}
