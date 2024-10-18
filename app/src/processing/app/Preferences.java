/*
  Part of the Processing project - http://processing.org

  Copyright (c) 2004-09 Ben Fry and Casey Reas
  Copyright (c) 2001-04 Massachusetts Institute of Technology

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

package processing.app;

import processing.app.helpers.PreferencesMap;

/**
 * Storage class for user preferences and environment settings.
 * 
 * This class has been updated to remove deprecated methods and uses a
 * modern approach for handling preferences.
 */
public class Preferences {

  /**
   * Standardized width for buttons.
   */
  static public int BUTTON_WIDTH = 80;

  /**
   * Standardized button height.
   */
  static public int BUTTON_HEIGHT = 24;

  // indents and spacing standards
  static final int GUI_SMALL = 6;

  /**
   * Retrieves a preference based on the given key.
   * @param attribute The key to retrieve the preference.
   * @return The preference value, or null if it doesn't exist.
   */
  public static String get(String attribute) {
    return PreferencesData.get(attribute);
  }

  /**
   * Retrieves a preference with a default value if the key doesn't exist.
   * @param attribute The key to retrieve the preference.
   * @param defaultValue The default value if the key is not found.
   * @return The preference value.
   */
  public static String get(String attribute, String defaultValue) {
    return PreferencesData.get(attribute, defaultValue);
  }

  /**
   * Checks if a preference exists based on the key.
   * @param key The key to check.
   * @return True if the key exists, false otherwise.
   */
  public static boolean has(String key) {
    return PreferencesData.has(key);
  }

  /**
   * Removes a preference based on the key.
   * @param key The key of the preference to remove.
   */
  public static void remove(String key) {
    PreferencesData.remove(key);
  }

  /**
   * Sets a preference with a key-value pair.
   * @param attribute The key.
   * @param value The value to store.
   */
  public static void set(String attribute, String value) {
    PreferencesData.set(attribute, value);
  }

  /**
   * Retrieves a boolean preference.
   * @param attribute The key to retrieve.
   * @return The boolean value, false if not found.
   */
  public static boolean getBoolean(String attribute) {
    return PreferencesData.getBoolean(attribute);
  }

  /**
   * Sets a boolean preference.
   * @param attribute The key.
   * @param value The boolean value to set.
   */
  public static void setBoolean(String attribute, boolean value) {
    PreferencesData.setBoolean(attribute, value);
  }

  /**
   * Retrieves an integer preference.
   * @param attribute The key to retrieve.
   * @return The integer value, or 0 if not found.
   */
  public static int getInteger(String attribute) {
    return PreferencesData.getInteger(attribute);
  }

  /**
   * Retrieves an integer preference with a default value.
   * @param attribute The key to retrieve.
   * @param defaultValue The default value to return if not found.
   * @return The integer value.
   */
  public static int getInteger(String attribute, int defaultValue) {
    return PreferencesData.getInteger(attribute, defaultValue);
  }

  /**
   * Sets an integer preference.
   * @param key The key.
   * @param value The integer value to store.
   */
  public static void setInteger(String key, int value) {
    PreferencesData.setInteger(key, value);
  }

  /**
   * Retrieves the preference map.
   * @return The preferences map.
   */
  public static PreferencesMap getMap() {
    return PreferencesData.getMap();
  }

  /**
   * Sets whether the preferences should be saved.
   * @param value True to enable saving, false otherwise.
   */
  public static void setDoSave(boolean value) {
    PreferencesData.setDoSave(value);
  }
}
