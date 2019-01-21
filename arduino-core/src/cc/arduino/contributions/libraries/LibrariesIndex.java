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

import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Optional;

public abstract class LibrariesIndex {

  public abstract List<ContributedLibraryReleases> getLibraries();

  public ContributedLibraryReleases find(final String name) {
    return getLibraries().stream() //
        .filter(l -> l.getName().equals(name)) //
        .findAny() //
        .orElse(null);
  }

  public ContributedLibrary find(String name, String version) {
    if (version == null || name == null) {
      return null;
    }
    ContributedLibraryReleases releases = find(name);
    if (releases == null) {
      return null;
    }
    return releases.getReleases().get(version);
  }

  @Override
  public String toString() {
    StringBuilder sb = new StringBuilder();
    for (ContributedLibraryReleases library : getLibraries()) {
      sb.append(library.toString());
    }
    return sb.toString();
  }

  public List<String> getCategories() {
    List<String> categories = new ArrayList<>();
    getLibraries().forEach(r -> {
      r.getReleases().forEach((v, lib) -> {
        if (lib.getCategory() != null && !categories.contains(lib.getCategory())) {
          categories.add(lib.getCategory());
        }
      });
    });
    Collections.sort(categories);
    return categories;
  }

  public List<String> getTypes() {
    Collection<String> typesAccumulator = new HashSet<>();
    getLibraries().forEach(r -> {
      r.getReleases().forEach((v, lib) -> {
        if (lib.getTypes() != null) {
          typesAccumulator.addAll(lib.getTypes());
        }
      });
    });

    List<String> types = new ArrayList<>(typesAccumulator);
    Collections.sort(types);

    return types;
  }

  public Optional<ContributedLibrary> getInstalled(String name) {
    return find(name).getInstalled();
  }
}
