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

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.AbstractAction;
import javax.swing.KeyStroke;

/**
 * Class to easily define instances of the Swing Action interface.
 *
 * When using AbstractAction, you have to create a subclass that implements the
 * actionPerformed() method, and sets attributes in the constructor, which gets
 * verbose quickly. This class implements actionPerformed for you, and forwards
 * it to the ActionListener passed to the constructor (intended to be a lambda
 * expression). Additional Action attributes can be set by passing constructor
 * arguments.
 *
 * The name of this class refers to the fact that it's simple to create an
 * action using this class, but perhaps a better name can be found for it.
 *
 * @see javax.swing.Action
 */
public class SimpleAction extends AbstractAction {
  private ActionListener listener;

  /**
   * Version of ActionListener that does not take an ActionEvent as an argument
   * This can be used when you do not care about the event itself, just that it
   * happened, typically for passing a argumentless lambda or method reference
   * to the SimpleAction constructor.
   */
  public interface AnonymousActionListener {
    public void actionPerformed();
  }

  public SimpleAction(String name, ActionListener listener) {
    this(name, null, null, listener);
  }

  public SimpleAction(String name, AnonymousActionListener listener) {
    this(name, null, null, listener);
  }

  public SimpleAction(String name, KeyStroke accelerator,
                      ActionListener listener) {
    this(name, null, accelerator, listener);
  }

  public SimpleAction(String name, KeyStroke accelerator,
                      AnonymousActionListener listener) {
    this(name, null, accelerator, listener);
  }

  public SimpleAction(String name, String description,
                      ActionListener listener) {
    this(name, description, null, listener);
  }

  public SimpleAction(String name, String description,
                      AnonymousActionListener listener) {
    this(name, description, null, listener);
  }

  public SimpleAction(String name, String description, KeyStroke accelerator,
                      AnonymousActionListener listener) {
    this(name, description, accelerator,
        (ActionEvent) -> listener.actionPerformed());
  }

  public SimpleAction(String name, String description, KeyStroke accelerator,
                      ActionListener listener) {
    this.putValue(NAME, name);
    this.putValue(SHORT_DESCRIPTION, description);
    this.putValue(ACCELERATOR_KEY, accelerator);
    this.listener = listener;
  }

  @Override
  public void actionPerformed(ActionEvent e) {
    listener.actionPerformed(e);
  }
}
