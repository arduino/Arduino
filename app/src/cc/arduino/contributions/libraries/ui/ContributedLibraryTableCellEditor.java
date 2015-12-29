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

import static processing.app.I18n.tr;

import java.awt.Color;
import java.awt.Component;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.stream.Collectors;

import javax.swing.JComboBox;
import javax.swing.JTable;

import cc.arduino.contributions.DownloadableContributionVersionComparator;
import cc.arduino.contributions.VersionComparator;
import cc.arduino.contributions.filters.BuiltInPredicate;
import cc.arduino.contributions.filters.InstalledPredicate;
import cc.arduino.contributions.libraries.ContributedLibrary;
import cc.arduino.contributions.libraries.filters.OnlyUpstreamReleasePredicate;
import cc.arduino.contributions.ui.InstallerTableCell;
import cc.arduino.utils.ReverseComparator;

@SuppressWarnings("serial")
public class ContributedLibraryTableCellEditor extends InstallerTableCell {

  private ContributedLibraryReleases editorValue;
  private ContributedLibraryTableCellJPanel editorCell;

  @Override
  public Object getCellEditorValue() {
    return editorValue;
  }

  @Override
  public Component getTableCellEditorComponent(JTable table, Object value,
                                               boolean isSelected, int row,
                                               int column) {
    editorValue = (ContributedLibraryReleases) value;

    editorCell = new ContributedLibraryTableCellJPanel(table, value, true);
    editorCell.installButton
        .addActionListener(e -> onInstall(editorValue.getSelected(),
                                          editorValue.getInstalled()));
    editorCell.downgradeButton.addActionListener(e -> {
      JComboBox chooser = editorCell.downgradeChooser;
      ContributedLibrary lib = (ContributedLibrary) chooser.getSelectedItem();
      onInstall(lib, editorValue.getInstalled());
    });
    editorCell.versionToInstallChooser.addItemListener(e -> editorValue
        .select((ContributedLibrary) editorCell.versionToInstallChooser
            .getSelectedItem()));

    setEnabled(true);

    final ContributedLibrary installed = editorValue.getInstalled();

    List<ContributedLibrary> releases = editorValue.getReleases().stream()
        .filter(new OnlyUpstreamReleasePredicate())
        .collect(Collectors.toList());
    List<ContributedLibrary> uninstalledReleases = releases.stream()
        .filter(new InstalledPredicate().negate()).collect(Collectors.toList());

    List<ContributedLibrary> installedBuiltIn = releases.stream()
        .filter(new InstalledPredicate()).filter(new BuiltInPredicate())
        .collect(Collectors.toList());

    if (installed != null && !installedBuiltIn.contains(installed)) {
      uninstalledReleases.addAll(installedBuiltIn);
    }

    Collections.sort(uninstalledReleases, new ReverseComparator<>(
        new DownloadableContributionVersionComparator()));

    editorCell.downgradeChooser.removeAllItems();
    editorCell.downgradeChooser.addItem(tr("Select version"));

    final List<ContributedLibrary> uninstalledPreviousReleases = new LinkedList<>();
    final List<ContributedLibrary> uninstalledNewerReleases = new LinkedList<>();

    final VersionComparator versionComparator = new VersionComparator();
    uninstalledReleases.stream().forEach(input -> {
      if (installed == null
          || versionComparator.greaterThan(installed.getParsedVersion(),
                                           input.getParsedVersion())) {
        uninstalledPreviousReleases.add(input);
      } else {
        uninstalledNewerReleases.add(input);
      }
    });
    uninstalledNewerReleases.forEach(editorCell.downgradeChooser::addItem);
    uninstalledPreviousReleases.forEach(editorCell.downgradeChooser::addItem);

    editorCell.downgradeChooser
        .setVisible(installed != null
                    && (!uninstalledPreviousReleases.isEmpty()
                        || uninstalledNewerReleases.size() > 1));
    editorCell.downgradeButton
        .setVisible(installed != null
                    && (!uninstalledPreviousReleases.isEmpty()
                        || uninstalledNewerReleases.size() > 1));

    editorCell.versionToInstallChooser.removeAllItems();
    uninstalledReleases.forEach(editorCell.versionToInstallChooser::addItem);
    editorCell.versionToInstallChooser
        .setVisible(installed == null && uninstalledReleases.size() > 1);

    editorCell.setBackground(new Color(218, 227, 227)); // #dae3e3
    return editorCell;
  }

  @Override
  public void setEnabled(boolean enabled) {
    editorCell.setButtonsVisible(enabled);
  }

  public void setStatus(String status) {
    editorCell.statusLabel.setText(status);
  }

  protected void onRemove(ContributedLibrary selected) {
    // Empty
  }

  protected void onInstall(ContributedLibrary selected,
                           ContributedLibrary installed) {
    // Empty
  }

}
