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

import java.awt.AWTKeyStroke;
import java.awt.Component;
import java.awt.KeyboardFocusManager;
import java.awt.Toolkit;
import java.awt.event.InputEvent;
import java.beans.PropertyChangeEvent;
import java.util.HashSet;
import java.util.Set;

import javax.swing.Action;
import javax.swing.InputMap;
import javax.swing.JComponent;
import javax.swing.KeyStroke;

/**
 * This class contains some keybinding-related helper methods.
 */
public class Keys {

  /**
   * Register a keybinding in the given components WHEN_IN_FOCUSED_WINDOW input
   * map, runing the given action when the action's accelerator key is pressed.
   *
   * Note that this is typically automatically handled when the action is
   * assigned to a JMenuItem, but it can still be needed for other actions, or
   * actions mapped to JMenuItems in a popup menu that is not added to any
   * window normally (and thus does not fire when the popup is closed).
   *
   * When the action is disabled, the keybinding is unregistered, and when it is
   * enabled, it is registered again.
   */
  public static void bind(final JComponent component, final Action action) {
    bind(component, action,
         (KeyStroke) action.getValue(Action.ACCELERATOR_KEY));
  }

  /**
   * Register a keybinding, running the given action when the given keystroke is
   * pressed when the given component is in the focused window.
   *
   * This is typically used to bind an additional keystroke to a menu item, in
   * addition to the primary accelerator key.
   *
   * When the action is disabled, the keybinding is unregistered, and when it is
   * enabled, it is registered again.
   */
  public static void bind(final JComponent component, final Action action,
                          KeyStroke keystroke) {
    bind(component, action, keystroke, JComponent.WHEN_IN_FOCUSED_WINDOW);
  }

  /**
   * Register a keybinding to be handled in given condition, running the given
   * action when the given keystroke is pressed.
   *
   * When the action is disabled, the keybinding is unregistered, and when it is
   * enabled, it is registered again.
   *
   * @param component
   *          The component to register the keybinding on.
   * @param action
   *          The action to run when the keystroke is pressed
   * @param action
   *          The keystroke to bind
   * @param condition
   *          The condition under which to run the keystroke. Should be one of
   *          JComponent.WHEN_FOCUSED,
   *          JComponent.WHEN_ANCESTOR_OF_FOCUSED_COMPONENT or
   *          JComponent.WHEN_IN_FOCUSED_WINDOW.
   */
  public static void bind(final JComponent component, final Action action,
                          KeyStroke keystroke, int condition) {
    // The input map maps keystrokes to arbitrary objects (originally strings
    // that described the option, we just use the Action object itself).
    if (action.isEnabled())
      enableBind(component, action, keystroke, condition);

    // The action map maps the arbitrary option to an Action to execute. These
    // be kept in the component even when the action is disabled.
    component.getActionMap().put(action, action);

    // Enable and disable the binding when the action is enabled / disabled.
    action.addPropertyChangeListener((PropertyChangeEvent e) -> {
      if (e.getPropertyName().equals("enabled")) {
        if (e.getNewValue().equals(Boolean.TRUE))
          enableBind(component, action, keystroke, condition);
        else
          disableBind(component, action, keystroke, condition);
      }
    });
  }

  /**
   * Kill an existing binding from the given condition. If the binding is
   * defined on the given component, it is removed, but if it is defined through
   * a parent inputmap (typically shared by multiple components, so best not
   * touched), this adds a dummy binding for this component, that will never
   * match an action in the component's action map, effectively disabling the
   * binding.
   *
   * This method is not intended to unbind a binding created by bind(), since
   * such a binding would get re-enabled when the action is re-enabled.
   */
  public static void killBinding(final JComponent component,
                                 final KeyStroke keystroke, int condition) {
    InputMap map = component.getInputMap(condition);
    // First, try removing it
    map.remove(keystroke);
    // If the binding is defined in a parent map, defining it will not work, so
    // instead add an override that will never appear in the action map.
    if (map.get(keystroke) != null)
      map.put(keystroke, new Object());
  }

  /**
   * Kill an existing binding like above, but from all three conditions
   * (WHEN_FOCUSED, WHEN_ANCESTOR_OF_FOCUSED_COMPONENT, WHEN_IN_FOCUSED_WINDOW).
   */
  public static void killBinding(final JComponent component,
                                 final KeyStroke key) {
    killBinding(component, key, JComponent.WHEN_FOCUSED);
    killBinding(component, key, JComponent.WHEN_ANCESTOR_OF_FOCUSED_COMPONENT);
    killBinding(component, key, JComponent.WHEN_IN_FOCUSED_WINDOW);
  }

  /**
   * Remove a keystroke from the keys used to shift focus in or below the given
   * component. This modifies all sets of focus traversal keys on the given
   * component to remove the given keystroke. These sets are inherited down the
   * component hierarchy (until a component that has a custom set itself).
   */
  public static void killFocusTraversalBinding(final Component component,
                                               final KeyStroke keystroke) {
    int[] sets = { KeyboardFocusManager.FORWARD_TRAVERSAL_KEYS,
        KeyboardFocusManager.BACKWARD_TRAVERSAL_KEYS,
        KeyboardFocusManager.UP_CYCLE_TRAVERSAL_KEYS,
        KeyboardFocusManager.DOWN_CYCLE_TRAVERSAL_KEYS };
    for (int set : sets) {
      Set<AWTKeyStroke> keys = component.getFocusTraversalKeys(set);
      // keys is immutable, so create a new set to allow changes
      keys = new HashSet<>(keys);
      if (set == 0)
        keys.add(ctrlAlt('Z'));

      // If the given keystroke was present in the set, replace it with the
      // updated set with the keystroke removed.
      if (keys.remove(keystroke))
        component.setFocusTraversalKeys(set, keys);
    }
  }

  private static void enableBind(final JComponent component,
                                 final Action action, final KeyStroke keystroke,
                                 int condition) {
    component.getInputMap(condition).put(keystroke, action);
  }

  private static void disableBind(final JComponent component,
                                  final Action action,
                                  final KeyStroke keystroke, int condition) {
    component.getInputMap(condition).put(keystroke, action);
  }

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
