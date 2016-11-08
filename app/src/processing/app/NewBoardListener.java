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
 * Copyright 2016 Arduino LLC (http://www.arduino.cc/)
 */

package processing.app;

import java.awt.event.WindowEvent;
import java.awt.event.WindowFocusListener;
import java.beans.PropertyChangeEvent;
import java.beans.PropertyChangeListener;

import javax.swing.SwingUtilities;

import cc.arduino.UpdatableBoardsLibsFakeURLsHandler;
import cc.arduino.view.NotificationPopup;
import processing.app.Base;

public class NewBoardListener implements PropertyChangeListener, Runnable {
  private Base base;
  private Editor ed;

  public NewBoardListener(Base base) {
    this.base = base;
  }

  @Override
  public void propertyChange(PropertyChangeEvent event) {
    checkForNewBoardAttached();
  }

  @Override
  public void run() {
    while (base.getActiveEditor() == null) {
      try {
        Thread.sleep(1000);
      } catch (InterruptedException e) {
        e.printStackTrace();
      }
    }
    BaseNoGui.addPropertyChangeListener(this);
    checkForNewBoardAttached();
  }

  public void checkForNewBoardAttached() {
    String newBoardManagerLink = BaseNoGui.getBoardManagerLink();
    if (newBoardManagerLink.isEmpty()) {
      return;
    }

    SwingUtilities.invokeLater(() -> {

      ed = base.getActiveEditor();
      NotificationPopup notificationPopup = new NotificationPopup(ed, 
                 new UpdatableBoardsLibsFakeURLsHandler(base), 
                 newBoardManagerLink, false);
      if (ed.isFocused()) {
        notificationPopup.begin();
        return;
      }

      // If the IDE is not focused wait until it is focused again to
      // display the notification, this avoids the annoying side effect
      // to "steal" the focus from another application.
      WindowFocusListener wfl = new WindowFocusListener() {
        @Override
        public void windowLostFocus(WindowEvent evt) {
        }

        @Override
        public void windowGainedFocus(WindowEvent evt) {
          notificationPopup.begin();
          for (Editor e : base.getEditors())
            e.removeWindowFocusListener(this);
        }
      };

      for (Editor e : base.getEditors())
        e.addWindowFocusListener(wfl);
    });
  }
}
