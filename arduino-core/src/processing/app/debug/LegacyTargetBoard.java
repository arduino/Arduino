/*
 TargetPackage - Represents a hardware package
 Part of the Arduino project - http://www.arduino.cc/

 Copyright (c) 2014 Cristian Maglie

 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software Foundation,
 Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
package processing.app.debug;

import processing.app.helpers.PreferencesMap;

import java.util.LinkedHashMap;
import java.util.Map;
import java.util.Set;

public class LegacyTargetBoard implements TargetBoard {

  private final String id;
  private final PreferencesMap prefs;
  private Map<String, PreferencesMap> menuOptions = new LinkedHashMap<>();
  private final TargetPlatform containerPlatform;

  /**
   * Create a TargetBoard based on preferences passed as argument.
   */
  public LegacyTargetBoard(String _id, PreferencesMap _prefs,
                           TargetPlatform parent) {
    containerPlatform = parent;
    id = _id;
    prefs = new PreferencesMap(_prefs);

    // Setup sub-menus
    PreferencesMap menus = prefs.firstLevelMap().get("menu");
    if (menus != null)
      menuOptions = menus.firstLevelMap();

    // Auto generate build.board if not set
    if (!prefs.containsKey("build.board")) {
      String board = containerPlatform.getId() + "_" + id;
      board = board.toUpperCase();
      prefs.put("build.board", board);
    }
  }

  @Override
  public String getName() {
    return prefs.get("name");
  }

  @Override
  public String getId() {
    return id;
  }

  @Override
  public PreferencesMap getPreferences() {
    return prefs;
  }

  @Override
  public boolean hasMenu(String menuId) {
    return menuOptions.containsKey(menuId);
  }

  @Override
  public PreferencesMap getMenuLabels(String menuId) {
    return menuOptions.get(menuId).topLevelMap();
  }

  @Override
  public String getMenuLabel(String menuId, String selectionId) {
    return getMenuLabels(menuId).get(selectionId);
  }

  @Override
  public Set<String> getMenuIds() {
    return menuOptions.keySet();
  }

  @Override
  public PreferencesMap getMenuPreferences(String menuId, String selectionId) {
    return menuOptions.get(menuId).subTree(selectionId);
  }

  @Override
  public TargetPlatform getContainerPlatform() {
    return containerPlatform;
  }

}
