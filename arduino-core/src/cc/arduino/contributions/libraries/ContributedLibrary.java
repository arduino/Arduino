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

import java.util.Collection;
import java.util.HashMap;
import java.util.Map;
import java.util.Optional;

import cc.arduino.contributions.VersionComparator;

import static processing.app.packages.UserLibrary.LOCATION_SKETCHBOOK;

public class ContributedLibrary {

  private String name;
  // version -> release map
  private Map<String, ContributedLibraryRelease> releases = new HashMap<>();
  private Optional<ContributedLibraryRelease> latest = Optional.empty();
  private Optional<ContributedLibraryRelease> selected = Optional.empty();

  public ContributedLibrary(String name) {
    this.name = name;
  }

  public String getName() {
    return name;
  }

  public Collection<ContributedLibraryRelease> getReleases() {
    return releases.values();
  }

  public Optional<ContributedLibraryRelease> getVersion(String version) {
    return Optional.ofNullable(releases.get(version));
  }

  public void addRelease(ContributedLibraryRelease release) {
    if (!latest.isPresent()) {
      latest = Optional.of(release);
    }
    String version = release.getParsedVersion();
    releases.put(version, release);
    if (VersionComparator.greaterThan(version, latest.get().getParsedVersion())) {
      latest = Optional.of(release);
    }
    selected = latest;
  }

  public Optional<ContributedLibraryRelease> getInstalled() {
    return releases.values().stream() //
        .filter(ContributedLibraryRelease::isLibraryInstalled) //
        .reduce((x, y) -> {
          String lx = x.getInstalledLibrary().get().getLocation();
          String ly = y.getInstalledLibrary().get().getLocation();
          if (lx.equals(ly)) {
            return VersionComparator.max(x, y);
          }
          return lx.equals(LOCATION_SKETCHBOOK) ? x : y;
        });
  }

  public Optional<ContributedLibraryRelease> getLatest() {
    return latest;
  }

  public Optional<ContributedLibraryRelease> getSelected() {
    return selected;
  }

  public void select(ContributedLibraryRelease lib) {
    for (ContributedLibraryRelease r : releases.values()) {
      if (r == lib) {
        selected = Optional.of(r);
        return;
      }
    }
  }
}
