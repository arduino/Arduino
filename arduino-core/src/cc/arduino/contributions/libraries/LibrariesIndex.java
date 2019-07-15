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
import java.util.LinkedList;
import java.util.List;
import java.util.Optional;
import java.util.stream.Collectors;

import cc.arduino.contributions.VersionComparator;

public abstract class LibrariesIndex {

  public abstract List<ContributedLibrary> getLibraries();

  public List<ContributedLibrary> find(final String name) {
    return getLibraries().stream() //
        .filter(l -> name.equals(l.getName())) //
        .collect(Collectors.toList());
  }

  public ContributedLibrary find(String name, String version) {
    if (name == null || version == null) {
      return null;
    }
    for (ContributedLibrary lib : find(name)) {
      if (version.equals(lib.getParsedVersion())) {
        return lib;
      }
    }
    return null;
  }

  @Override
  public String toString() {
    StringBuilder sb = new StringBuilder();
    for (ContributedLibrary library : getLibraries()) {
      sb.append(library.toString());
    }
    return sb.toString();
  }

  public List<String> getCategories() {
    List<String> categories = new LinkedList<>();
    for (ContributedLibrary lib : getLibraries()) {
      if (lib.getCategory() != null && !categories.contains(lib.getCategory())) {
        categories.add(lib.getCategory());
      }
    }
    Collections.sort(categories);

    return categories;
  }

  public List<String> getTypes() {
    Collection<String> typesAccumulator = new HashSet<>();
    for (ContributedLibrary lib : getLibraries()) {
      if (lib.getTypes() != null) {
        typesAccumulator.addAll(lib.getTypes());
      }
    }

    List<String> types = new LinkedList<>(typesAccumulator);
    Collections.sort(types);

    return types;
  }

  public Optional<ContributedLibrary> getInstalled(String name) {
    ContributedLibraryReleases rel = new ContributedLibraryReleases(find(name));
    return rel.getInstalled();
  }

  public List<ContributedLibrary> resolveDependeciesOf(ContributedLibrary library) {
    List<ContributedLibrary> solution = new ArrayList<>();
    solution.add(library);
    if (resolveDependeciesOf(solution, library)) {
      return solution;
    } else {
      return null;
    }
  }

  public boolean resolveDependeciesOf(List<ContributedLibrary> solution,
                                      ContributedLibrary library) {
    List<ContributedLibraryDependency> requirements = library.getDependencies();
    if (requirements == null) {
      // No deps for this library, great!
      return true;
    }

    for (ContributedLibraryDependency dep : requirements) {

      // If the current solution already contains this dependency, skip over
      boolean alreadyInSolution = solution.stream()
          .anyMatch(l -> l.getName().equals(dep.getName()));
      if (alreadyInSolution)
        continue;

      // Generate possible matching dependencies
      List<ContributedLibrary> possibleDeps = findMatchingDependencies(dep);

      // If there are no dependencies available add as "missing" lib
      if (possibleDeps.isEmpty()) {
        solution.add(new UnavailableContributedLibrary(dep));
        continue;
      }

      // Pick the installed version if available
      ContributedLibrary selected;
      Optional<ContributedLibrary> installed = possibleDeps.stream()
          .filter(l -> l.getInstalledLibrary().isPresent()).findAny();
      if (installed.isPresent()) {
        selected = installed.get();
      } else {
        // otherwise pick the latest version
        selected = possibleDeps.stream().reduce(VersionComparator::max).get();
      }

      // Add dependency to the solution and process recursively
      solution.add(selected);
      if (!resolveDependeciesOf(solution, selected)) {
        return false;
      }
    }
    return true;
  }

  private List<ContributedLibrary> findMatchingDependencies(ContributedLibraryDependency dep) {
    List<ContributedLibrary> available = find(dep.getName());
    if (dep.getVersion() == null || dep.getVersion().isEmpty())
      return available;

    // XXX: The following part is actually never reached. The use of version
    // constraints requires a much complex backtracking algorithm, the following
    // is just a draft placeholder.

//    List<ContributedLibrary> match = available.stream()
//        // TODO: add more complex version comparators (> >= < <= ~ 1.0.* 1.*...)
//        .filter(candidate -> candidate.getParsedVersion()
//            .equals(dep.getVersionRequired()))
//        .collect(Collectors.toList());
//    return match;

    return available;
  }
}
