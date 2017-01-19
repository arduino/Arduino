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

package cc.arduino.contributions.libraries.ui;

import cc.arduino.contributions.libraries.ContributedLibrary;

import java.util.Comparator;

public class ContributedLibraryReleasesComparator implements Comparator<ContributedLibraryReleases> {

  private final String firstType;

  public ContributedLibraryReleasesComparator(String firstType) {
    this.firstType = firstType;
  }

  @Override
  public int compare(ContributedLibraryReleases o1, ContributedLibraryReleases o2) {
    ContributedLibrary lib1 = o1.getLibrary();
    ContributedLibrary lib2 = o2.getLibrary();

    if (lib1.getTypes() == null || lib2.getTypes() == null) {
      return compareName(lib1, lib2);
    }
    if (lib1.getTypes().contains(firstType) && lib2.getTypes().contains(firstType)) {
      return compareName(lib1, lib2);
    }
    if (lib1.getTypes().contains(firstType)) {
      return -1;
    }
    if (lib2.getTypes().contains(firstType)) {
      return 1;
    }
    return compareName(lib1, lib2);
  }

  private int compareName(ContributedLibrary lib1, ContributedLibrary lib2) {
    return lib1.getName().compareToIgnoreCase(lib2.getName());
  }

}
