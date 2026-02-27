/*
 * This file is part of Arduino.
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
 *
 * Copyright 2013 Arduino LLC (http://www.arduino.cc/)
 */

package cc.arduino.packages;

import static processing.app.I18n.format;
import static processing.app.I18n.tr;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.io.File;

import cc.arduino.packages.discoverers.PluggableDiscovery;
import cc.arduino.packages.discoverers.serial.SerialDiscovery;
import cc.arduino.packages.discoverers.NetworkDiscovery;
import processing.app.PreferencesData;
import processing.app.debug.TargetPackage;
import processing.app.debug.TargetPlatform;
import processing.app.helpers.PreferencesMap;
import processing.app.helpers.StringReplacer;

public class DiscoveryManager {

  private final List<Discovery> discoverers;
  private final SerialDiscovery serialDiscoverer = new SerialDiscovery();
  private final NetworkDiscovery networkDiscoverer = new NetworkDiscovery();

//  private final Map<String, TargetPackage> packages;

  public DiscoveryManager(Map<String, TargetPackage> packages) {
//    this.packages = packages;

    discoverers = new ArrayList<>();
    discoverers.add(serialDiscoverer);
    discoverers.add(networkDiscoverer);

    // Search for discoveries in installed packages
    for (TargetPackage targetPackage : packages.values()) {
      for (TargetPlatform platform: targetPackage.getPlatforms().values()) {
        //System.out.println("installed: "+platform);
        PreferencesMap prefs = platform.getPreferences().subTree("discovery");
        PreferencesMap pathPrefs = new PreferencesMap();
        File platformFolder = platform.getFolder();
        pathPrefs.put("runtime.platform.path", platformFolder.getAbsolutePath());
        pathPrefs.put("runtime.hardware.path", platformFolder.getParentFile().getAbsolutePath());
        for (String discoveryName : prefs.firstLevelMap().keySet()) {
          PreferencesMap discoveryPrefs = prefs.subTree(discoveryName);

          String pattern = discoveryPrefs.get("pattern");
          if (pattern == null) {
            System.out.println(format(tr("No recipes defined for discovery '{0}'"),discoveryName));
            continue;
          }
          try {
            if (PreferencesData.getBoolean("discovery.debug")) {
              System.out.println("found discovery: " + discoveryName + " -> " + pattern);
              System.out.println("with pathnames -> " + pathPrefs);
              System.out.println("with preferencess -> " + discoveryPrefs);
            }
            pattern = StringReplacer.replaceFromMapping(pattern, PreferencesData.getMap());
            pattern = StringReplacer.replaceFromMapping(pattern, pathPrefs);
            String[] cmd = StringReplacer.formatAndSplit(pattern, discoveryPrefs);
            discoverers.add(new PluggableDiscovery(discoveryName, cmd));
          } catch (Exception e) {
            if (PreferencesData.getBoolean("discovery.debug")) {
              System.out.println(format(tr("Could not start discovery '{0}': {1}"), discoveryName, e.getMessage()));
            }
          }
        }
      }
    }

    // Start all discoverers
    for (Discovery d : discoverers) {
      try {
        new Thread(d).start();
      } catch (Exception e) {
        System.err.println(tr("Error starting discovery method: ") + d.toString());
        e.printStackTrace();
      }
    }

    Thread closeHook = new Thread(() -> {
      for (Discovery d : discoverers) {
        try {
          d.stop();
        } catch (Exception e) {
          e.printStackTrace(); //just printing as the JVM is terminating
        }
      }
    });
    closeHook.setName("DiscoveryManager closeHook");
    Runtime.getRuntime().addShutdownHook(closeHook);
  }

  public SerialDiscovery getSerialDiscoverer() {
    return serialDiscoverer;
  }

  public List<BoardPort> discovery() {
    List<BoardPort> res = new ArrayList<>();
    for (Discovery d : discoverers) {
      res.addAll(d.listDiscoveredBoards());
    }
    return res;
  }

  public List<BoardPort> discovery(boolean complete) {
    List<BoardPort> res = new ArrayList<>();
    for (Discovery d : discoverers) {
      res.addAll(d.listDiscoveredBoards(complete));
    }
    return res;
  }

  public BoardPort find(String address) {
    for (BoardPort boardPort : discovery()) {
      if (boardPort.getAddress().equals(address)) {
        return boardPort;
      }
    }
    return null;
  }

  public BoardPort find(String address, boolean complete) {
    for (BoardPort boardPort : discovery(complete)) {
      if (boardPort.getAddress().equals(address)) {
        return boardPort;
      }
    }
    return null;
  }

}
