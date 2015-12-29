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

package cc.arduino.contributions.packages.ui;

import static processing.app.I18n.tr;

import java.awt.Color;
import java.awt.Component;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.stream.Collectors;

import javax.swing.JTable;

import cc.arduino.contributions.DownloadableContributionVersionComparator;
import cc.arduino.contributions.VersionComparator;
import cc.arduino.contributions.filters.BuiltInPredicate;
import cc.arduino.contributions.filters.InstalledPredicate;
import cc.arduino.contributions.packages.ContributedPlatform;
import cc.arduino.contributions.ui.InstallerTableCell;
import cc.arduino.utils.ReverseComparator;

@SuppressWarnings("serial")
public class ContributedPlatformTableCellEditor extends InstallerTableCell {

  private ContributedPlatformTableCellJPanel cell;
  private ContributedPlatformReleases value;

  @Override
  public Object getCellEditorValue() {
    return value;
  }

  @Override
  public Component getTableCellEditorComponent(JTable table, Object _value,
                                               boolean isSelected, int row,
                                               int column) {
    value = (ContributedPlatformReleases) _value;

    cell = new ContributedPlatformTableCellJPanel();
    cell.installButton.addActionListener(e -> onInstall(value.getSelected(),
                                                        value.getInstalled()));
    cell.removeButton.addActionListener(e -> onRemove(value.getInstalled()));
    cell.downgradeButton.addActionListener(e -> {
      ContributedPlatform selected = (ContributedPlatform) cell.downgradeChooser
          .getSelectedItem();
      onInstall(selected, value.getInstalled());
    });
    cell.versionToInstallChooser.addItemListener(e -> value
        .select((ContributedPlatform) cell.versionToInstallChooser
            .getSelectedItem()));

    setEnabled(true);

    final ContributedPlatform installed = value.getInstalled();

    List<ContributedPlatform> releases = new LinkedList<>(value.releases);
    List<ContributedPlatform> uninstalledReleases = releases.stream()
        .filter(new InstalledPredicate().negate()).collect(Collectors.toList());

    List<ContributedPlatform> installedBuiltIn = releases.stream()
        .filter(new InstalledPredicate()).filter(new BuiltInPredicate())
        .collect(Collectors.toList());

    if (installed != null && !installedBuiltIn.contains(installed)) {
      uninstalledReleases.addAll(installedBuiltIn);
    }

    Collections.sort(uninstalledReleases, new ReverseComparator<>(
        new DownloadableContributionVersionComparator()));

    cell.downgradeChooser.removeAllItems();
    cell.downgradeChooser.addItem(tr("Select version"));

    final List<ContributedPlatform> uninstalledPreviousReleases = new LinkedList<>();
    final List<ContributedPlatform> uninstalledNewerReleases = new LinkedList<>();

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
    uninstalledNewerReleases.forEach(cell.downgradeChooser::addItem);
    uninstalledPreviousReleases.forEach(cell.downgradeChooser::addItem);

    boolean downgradeVisible = installed != null
                               && (!uninstalledPreviousReleases.isEmpty()
                                   || uninstalledNewerReleases.size() > 1);
    cell.downgradeChooser.setVisible(downgradeVisible);
    cell.downgradeButton.setVisible(downgradeVisible);

    cell.versionToInstallChooser.removeAllItems();
    uninstalledReleases.forEach(cell.versionToInstallChooser::addItem);
    cell.versionToInstallChooser
        .setVisible(installed == null && uninstalledReleases.size() > 1);

    cell.update(table, _value, true, !installedBuiltIn.isEmpty());
    cell.setBackground(new Color(218, 227, 227)); // #dae3e3
    return cell;
  }

  @Override
  public void setEnabled(boolean enabled) {
    cell.setButtonsVisible(enabled);
  }

  public void setStatus(String status) {
    cell.statusLabel.setText(status);
  }

  protected void onRemove(ContributedPlatform contributedPlatform) {
    // Empty
  }

  protected void onInstall(ContributedPlatform contributedPlatform,
                           ContributedPlatform installed) {
    // Empty
  }

}
