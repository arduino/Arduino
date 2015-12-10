/*
 * This file is part of Arduino.
 *
 * Copyright 2015 Matthijs Kooijman <matthijs@stdin.nl>
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

package processing.app.helpers;

import java.awt.Toolkit;
import java.awt.event.InputEvent;
import java.beans.PropertyChangeEvent;

import javax.swing.Action;
import javax.swing.JComponent;
import javax.swing.KeyStroke;

/**
 * This class contains some keybinding-related helper methods.
 */
public class Keys {

  private static final int CTRL = Toolkit.getDefaultToolkit()
      .getMenuShortcutKeyMask();

  /**
   * Creates a KeyCode for the "menu shortcut" + the key passed in. By default,
   * the menu shortcut is the ctrl key (hence the method name), but platforms
   * might use a different key (like the Apple key on OSX).
   *
   * keyCode should be a KeyEvent.VK_* constant (it can also be a char constant,
   * but this does not work for all characters, so is not recommended).
   */
  public static KeyStroke ctrl(int keyCode) {
    return KeyStroke.getKeyStroke(keyCode, CTRL);
  }

  /**
   * Creates a KeyCode for the "menu shortcut" + shift + the key passed in. By
   * default, the menu shortcut is the ctrl key (hence the method name), but
   * platforms might use a different key (like the Apple key on OSX).
   *
   * keyCode should be a KeyEvent.VK_* constant (it can also be a char constant,
   * but this does not work for all characters, so is not recommended).
   */
  public static KeyStroke ctrlShift(int keyCode) {
    return KeyStroke.getKeyStroke(keyCode, CTRL | InputEvent.SHIFT_MASK);
  }

  /**
   * Creates a KeyCode for the "menu shortcut" + shift + the key passed in. By
   * default, the menu shortcut is the ctrl key (hence the method name), but
   * platforms might use a different key (like the Apple key on OSX).
   *
   * keyCode should be a KeyEvent.VK_* constant (it can also be a char constant,
   * but this does not work for all characters, so is not recommended).
   */
  public static KeyStroke ctrlAlt(int keyCode) {
    return KeyStroke.getKeyStroke(keyCode, CTRL | InputEvent.ALT_MASK);
  }
}
