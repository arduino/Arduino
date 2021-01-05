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
import cc.arduino.contributions.libraries.ContributedLibraryReleases;
import cc.arduino.contributions.packages.ContributedPlatform;
import cc.arduino.contributions.ui.FilteredAbstractTableModel;
import processing.app.BaseNoGui;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.function.Predicate;

@SuppressWarnings("serial")
public class LibrariesIndexTableModel
    extends FilteredAbstractTableModel<ContributedLibraryReleases> {

  private final List<ContributedLibraryReleases> contributions = new ArrayList<>();

  private final String[] columnNames = { "Description" };

  private final Class<?>[] columnTypes = { ContributedPlatform.class };

  Predicate<ContributedLibraryReleases> selectedCategoryFilter = null;
  String selectedFilters[] = null;

  public void updateIndexFilter(String filters[],
                                Predicate<ContributedLibraryReleases> additionalFilter) {
    selectedCategoryFilter = additionalFilter;
    selectedFilters = filters;
    update();
  }

  /**
   * Check if <b>string</b> contains all the substrings in <b>set</b>. The
   * compare is case insensitive.
   *
   * @param string
   * @param filters
   * @return <b>true<b> if all the strings in <b>set</b> are contained in
   *         <b>string</b>.
   */
  private boolean stringContainsAll(String string, String filters[]) {
    if (string == null) {
      return false;
    }

    if (filters == null) {
      return true;
    }

    for (String filter : filters) {
      if (!string.toLowerCase().contains(filter.toLowerCase())) {
        return false;
      }
    }

    return true;
  }

  @Override
  public int getColumnCount() {
    return columnNames.length;
  }

  @Override
  public int getRowCount() {
    return contributions.size();
  }

  @Override
  public String getColumnName(int column) {
    return columnNames[column];
  }

  @Override
  public Class<?> getColumnClass(int colum) {
    return columnTypes[colum];
  }

  @Override
  public void setValueAt(Object value, int row, int col) {
    fireTableCellUpdated(row, col);
  }

  @Override
  public Object getValueAt(int row, int col) {
    if (row >= contributions.size()) {
      return null;
    }
    ContributedLibraryReleases contribution = contributions.get(row);
    return contribution;// .getSelected();
  }

  @Override
  public boolean isCellEditable(int row, int col) {
    return true;
  }

  public ContributedLibraryReleases getReleases(int row) {
    return contributions.get(row);
  }

  public ContributedLibrary getSelectedRelease(int row) {
    return contributions.get(row).getSelected();
  }

  public void update() {
    updateContributions();
    fireTableDataChanged();
  }

  private boolean filterCondition(ContributedLibraryReleases lib) {
    if (selectedCategoryFilter != null && !selectedCategoryFilter.test(lib)) {
      return false;
    }

    ContributedLibrary latest = lib.getLatest();
    String compoundTargetSearchText = latest.getName() + " "
                                      + latest.getParagraph() + " "
                                      + latest.getSentence();
    if (latest.getProvidesIncludes() != null) {
      compoundTargetSearchText += " " + latest.getProvidesIncludes();
    }
    if (!stringContainsAll(compoundTargetSearchText, selectedFilters)) {
      return false;
    }

    return true;
  }

  public void updateLibrary(ContributedLibrary lib) {
    // Find the row interested in the change
    int row = -1;
    for (ContributedLibraryReleases releases : contributions) {
      if (releases.shouldContain(lib))
        row = contributions.indexOf(releases);
    }

    updateContributions();

    // If the library is found in the list send update event
    // or insert event on the specific row...
    for (ContributedLibraryReleases releases : contributions) {
      if (releases.shouldContain(lib)) {
        if (row == -1) {
          row = contributions.indexOf(releases);
          fireTableRowsInserted(row, row);
        } else {
          fireTableRowsUpdated(row, row);
        }
        return;
      }
    }
    // ...otherwise send a row deleted event
    fireTableRowsDeleted(row, row);
  }

  private List<ContributedLibraryReleases> rebuildContributionsFromIndex() {
    List<ContributedLibraryReleases> res = new ArrayList<>();
    BaseNoGui.librariesIndexer.getIndex().getLibraries(). //
        forEach(lib -> {
          for (ContributedLibraryReleases contribution : res) {
            if (!contribution.shouldContain(lib))
              continue;
            contribution.add(lib);
            return;
          }

          res.add(new ContributedLibraryReleases(lib));
        });
    return res;
  }

  private void updateContributions() {
    List<ContributedLibraryReleases> all = rebuildContributionsFromIndex();
    contributions.clear();
    all.stream().filter(this::filterCondition).forEach(contributions::add);
    Collections.sort(contributions,
                     new ContributedLibraryReleasesComparator("Arduino"));
  }

}
