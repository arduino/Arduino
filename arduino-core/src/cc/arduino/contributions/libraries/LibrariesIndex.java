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
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Optional;
import java.util.Set;

public class LibrariesIndex {

  // name -> library map
  private Map<String, ContributedLibrary> libraries = new HashMap<>();
  private Set<String> categories = new HashSet<>();
  private Set<String> types = new HashSet<>();

  public Collection<ContributedLibrary> getLibraries() {
    return libraries.values();
  }

  public void add(ContributedLibrary library) {
    libraries.put(library.getName(), library);
    library.getReleases().forEach(rel -> {
      categories.add(rel.getCategory());
      types.addAll(rel.getTypes());
    });
  }

  public Optional<ContributedLibrary> find(String name) {
    return Optional.ofNullable(libraries.get(name));
  }

  public Optional<ContributedLibraryRelease> find(String name, String version) {
    if (libraries.containsKey(name)) {
      return libraries.get(name).getVersion(version);
    }
    return Optional.empty();
  }

  public List<String> getCategories() {
    List<String> res = new ArrayList<>(categories);
    Collections.sort(res);
    return res;
  }

  public List<String> getTypes() {
    List<String> res = new ArrayList<>(types);
    Collections.sort(res);
    return res;
  }

  public Optional<ContributedLibraryRelease> getInstalled(String name) {
    if (libraries.containsKey(name)) {
      return libraries.get(name).getInstalled();
    }
    return Optional.empty();
  }

}
