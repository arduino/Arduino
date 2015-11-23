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

import cc.arduino.contributions.DownloadableContributionBuiltInAtTheBottomComparator;
import cc.arduino.contributions.filters.InstalledPredicate;
import cc.arduino.contributions.libraries.ContributedLibrary;
import cc.arduino.contributions.ui.FilteredAbstractTableModel;

import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.stream.Collectors;

public class ContributedLibraryReleases {

  private final ContributedLibrary library;
  private final List<ContributedLibrary> releases;
  private final List<String> versions;

  private ContributedLibrary selected;

  public ContributedLibraryReleases(ContributedLibrary library) {
    this.library = library;
    this.versions = new LinkedList<>();
    this.releases = new LinkedList<>();
    this.selected = null;
    add(library);
  }

  public ContributedLibrary getLibrary() {
    return library;
  }

  public List<ContributedLibrary> getReleases() {
    return releases;
  }

  public boolean shouldContain(ContributedLibrary lib) {
    return lib.getName().equals(library.getName());
  }

  public void add(ContributedLibrary library) {
    releases.add(library);
    String version = library.getParsedVersion();
    if (version != null) {
      versions.add(version);
    }
    selected = getLatest();
  }

  public ContributedLibrary getInstalled() {
    List<ContributedLibrary> installedReleases = releases.stream().filter(new InstalledPredicate()).collect(Collectors.toList());
    Collections.sort(installedReleases, new DownloadableContributionBuiltInAtTheBottomComparator());

    if (installedReleases.isEmpty()) {
      return null;
    }

    return installedReleases.get(0);
  }

  public ContributedLibrary getLatest() {
    return FilteredAbstractTableModel.getLatestOf(releases);
  }

  public ContributedLibrary getSelected() {
    return selected;
  }

  public void select(ContributedLibrary value) {
    for (ContributedLibrary plat : releases) {
      if (plat == value) {
        selected = plat;
        return;
      }
    }
  }
}
