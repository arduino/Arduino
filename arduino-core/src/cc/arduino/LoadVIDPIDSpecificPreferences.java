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

package cc.arduino;

import cc.arduino.packages.BoardPort;
import org.apache.commons.lang3.StringUtils;
import processing.app.BaseNoGui;
import processing.app.PreferencesData;
import processing.app.helpers.PreferencesMap;

import java.util.Map;
import java.util.Optional;

public class LoadVIDPIDSpecificPreferences {

  public void load(PreferencesMap prefs) {
    BoardPort boardPort = BaseNoGui.getDiscoveryManager().find(PreferencesData.get("serial.port"));
    if (boardPort == null) {
      return;
    }

    String vid = boardPort.getPrefs().get("vid");
    String pid = boardPort.getPrefs().get("pid");
    if (StringUtils.isEmpty(vid) || StringUtils.isEmpty(pid)) {
      return;
    }

    int VIDPIDIndex = findVIDPIDIndex(prefs, vid.toUpperCase(), pid.toUpperCase());
    if (VIDPIDIndex < 0) {
      return;
    }

    prefs.putAll(prefs.subTree("vid." + VIDPIDIndex));
  }

  private int findVIDPIDIndex(PreferencesMap preferences, String vid, String pid) {
    Optional<Integer> vidPid = preferences.subTree("vid").entrySet().stream()
      .filter(keyValue -> !keyValue.getKey().contains("."))
      .filter(keyValue -> vid.equals(keyValue.getValue().toUpperCase()) && pid.equals(preferences.get("pid." + keyValue.getKey()).toUpperCase()))
      .map(Map.Entry::getKey)
      .map(Integer::valueOf)
      .findFirst();

    return vidPid.orElse(-1);
  }

}

