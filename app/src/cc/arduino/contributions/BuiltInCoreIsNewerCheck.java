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

package cc.arduino.contributions;

import cc.arduino.contributions.packages.ContributedPlatform;
import processing.app.Base;
import processing.app.BaseNoGui;
import processing.app.I18n;
import processing.app.PreferencesData;

import javax.swing.*;
import java.util.List;
import java.util.Optional;
import java.util.stream.Collectors;

import static processing.app.I18n.tr;

public class BuiltInCoreIsNewerCheck implements Runnable {

  private final Base base;

  public BuiltInCoreIsNewerCheck(Base base) {
    this.base = base;
  }

  @Override
  public void run() {
    try {
      builtInPackageIsNewerCheck();
    } catch (InterruptedException e) {
      e.printStackTrace();
    }
  }

  private void builtInPackageIsNewerCheck() throws InterruptedException {
    if (PreferencesData.getInteger("builtin_platform_is_newer", -1) >= BaseNoGui.REVISION) {
      return;
    }

    List<ContributedPlatform> contributedPlatforms = BaseNoGui.indexer
        .getPackages().stream() //
        .map(pack -> pack.getPlatforms()) //
        .flatMap(platfs -> platfs.stream()) //
        .collect(Collectors.toList());

    Optional<ContributedPlatform> mayInstalledBuiltIn = contributedPlatforms
        .stream() //
        .filter(p -> p.isInstalled()) //
        .filter(p -> p.isBuiltIn()) //
        .findFirst();
    if (!mayInstalledBuiltIn.isPresent()) {
      return;
    }
    final ContributedPlatform installedBuiltIn = mayInstalledBuiltIn.get();

    ContributedPlatform installedNotBuiltIn = BaseNoGui.indexer.getInstalled(installedBuiltIn.getParentPackage().getName(), installedBuiltIn.getArchitecture());
    if (installedNotBuiltIn == null) {
      return;
    }

    while (!base.hasActiveEditor()) {
      Thread.sleep(100);
    }

    if (VersionComparator.greaterThan(installedBuiltIn.getParsedVersion(), installedNotBuiltIn.getParsedVersion())) {
      SwingUtilities.invokeLater(() -> {
        PreferencesData.setInteger("builtin_platform_is_newer", BaseNoGui.REVISION);
        assert base.hasActiveEditor();
        int chosenOption = JOptionPane.showConfirmDialog(base.getActiveEditor(), I18n.format(tr("The IDE includes an updated {0} package, but you're using an older one.\nDo you want to upgrade {0}?"), installedBuiltIn.getName()), I18n.format(tr("A newer {0} package is available"), installedBuiltIn.getName()), JOptionPane.YES_NO_OPTION, JOptionPane.QUESTION_MESSAGE);
        if (chosenOption == JOptionPane.YES_OPTION) {
          try {
            base.openBoardsManager(installedBuiltIn.getName(), "");
          } catch (Exception e) {
            e.printStackTrace();
          }
        }
      });
    }
  }
}
