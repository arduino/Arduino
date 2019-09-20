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
 * Copyright 2015 Arduino LLC (http://www.arduino.cc/)
 */

package cc.arduino.view;

import static processing.app.Theme.scale;

import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.Frame;
import java.awt.Image;
import java.awt.Point;
import java.awt.event.*;
import java.util.Timer;
import java.util.TimerTask;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JEditorPane;
import javax.swing.JLabel;
import javax.swing.WindowConstants;
import javax.swing.border.LineBorder;
import javax.swing.event.HyperlinkListener;

import cc.arduino.Constants;
import processing.app.PreferencesData;
import processing.app.Theme;

import java.awt.event.KeyEvent;

import static processing.app.I18n.tr;

public class NotificationPopup extends JDialog {
  private Timer autoCloseTimer = new Timer(false);
  private boolean autoClose = true;
  private OptionalButtonCallbacks optionalButtonCallbacks;

  public interface OptionalButtonCallbacks {
    void onOptionalButton1Callback();
    void onOptionalButton2Callback();
  }

  public NotificationPopup(Frame parent, HyperlinkListener hyperlinkListener,
                           String message) {
    this(parent, hyperlinkListener, message, true, null, null, null);
  }

  public NotificationPopup(Frame parent, HyperlinkListener hyperlinkListener,
                           String message, boolean _autoClose) {
    this(parent, hyperlinkListener, message, _autoClose, null, null, null);
  }

  public NotificationPopup(Frame parent, HyperlinkListener hyperlinkListener,
                           String message, boolean _autoClose, OptionalButtonCallbacks listener, String button1Name, String button2Name) {
    super(parent, false);

    if (!PreferencesData.getBoolean("ide.accessible")) {
      // often auto-close is too fast for users of screen readers, so don't allow it.
      autoClose = _autoClose;
    }
    else {
      autoClose = false;
    }
    optionalButtonCallbacks = listener;

    setLayout(new FlowLayout());
    setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
    setUndecorated(true);
    setResizable(false);

    Image arduino = Theme.getLibImage("arduino", this, scale(40), scale(40));
    JLabel arduinoIcon = new JLabel(new ImageIcon(arduino));
    add(arduinoIcon);

    JEditorPane text = new JEditorPane();
    text.setBorder(new LineBorder(new Color(0, 0, 0), 0, true));
    text.setContentType("text/html"); // NOI18N
    text.setOpaque(false);
    text.setEditable(false);
    text.setText("<html><body style=\"font-family:sans-serif; font-size: "
                 + scale(14) + ";\">  " + message + "  </body></html>");
    text.addHyperlinkListener(hyperlinkListener);
    add(text);

    if (button1Name != null) {
      JButton optionalButton1 = new JButton(tr(button1Name));
      MouseAdapter button1Action = new MouseAdapter() {
        @Override
        public void mouseClicked(MouseEvent e) {
          if (optionalButtonCallbacks != null) {
            optionalButtonCallbacks.onOptionalButton1Callback();
          }
        }
      };
      optionalButton1.addMouseListener(button1Action);

      KeyListener button1Key = new KeyListener() {
        // Ignore when the key is typed - only act once the key is released
        public void keyTyped(KeyEvent e) {
          // do nothing here, wait until the key is released
        }

        // Ignore when the key is pressed - only act once the key is released
        public void keyPressed(KeyEvent e) {
          // do nothing here, wait until the key is released
        }

        public void keyReleased(KeyEvent e) {
          int key = e.getKeyCode();
          if ((key == KeyEvent.VK_ENTER) || (key == KeyEvent.VK_SPACE)) {
            optionalButtonCallbacks.onOptionalButton1Callback();
          }
        }
      };
      optionalButton1.addKeyListener(button1Key);
      add(optionalButton1);
    }

    if (button2Name != null) {
      JButton optionalButton2 = new JButton(tr(button2Name));
      MouseAdapter button2Action = new MouseAdapter() {
        @Override
        public void mouseClicked(MouseEvent e) {
          if (optionalButtonCallbacks != null) {
            optionalButtonCallbacks.onOptionalButton2Callback();
          }
        }
      };
      optionalButton2.addMouseListener(button2Action);

      KeyListener button2Key = new KeyListener() {
        // Ignore when the key is typed - only act once the key is released
        public void keyTyped(KeyEvent e) {
          // do nothing here, wait until the key is released
        }

        // Ignore when the key is pressed - only act once the key is released
        public void keyPressed(KeyEvent e) {
          // do nothing here, wait until the key is released
        }

        public void keyReleased(KeyEvent e) {
          int key = e.getKeyCode();
          if ((key == KeyEvent.VK_ENTER) || (key == KeyEvent.VK_SPACE)) {
            optionalButtonCallbacks.onOptionalButton2Callback();
          }
        }
      };
      optionalButton2.addKeyListener(button2Key);
      add(optionalButton2);
    }

    Image close = Theme.getThemeImage("close", this, scale(22), scale(22));
    JButton closeButton = new JButton(new ImageIcon(close));
    closeButton.setBorder(null);
    closeButton.setBorderPainted(false);
    closeButton.setHideActionText(true);
    closeButton.setOpaque(false);
    closeButton.setBackground(new Color(0, 0, 0, 0));
    closeButton.getAccessibleContext().setAccessibleDescription(tr("Close"));
    KeyListener closeKey = new KeyListener() {
      // Ignore when the key is typed - only act once the key is released
      public void keyTyped(KeyEvent e) {
        // do nothing here, wait until the key is released
      }

      // Ignore when the key is pressed - only act once the key is released
      public void keyPressed(KeyEvent e) {
        // do nothing here, wait until the key is released
      }

      public void keyReleased(KeyEvent e) {
        int key = e.getKeyCode();
        if ((key == KeyEvent.VK_ENTER) || (key == KeyEvent.VK_SPACE)) {
          close();
        }
      }
    };
    closeButton.addKeyListener(closeKey);
    add(closeButton);

    MouseAdapter closeOnClick = new MouseAdapter() {
      @Override
      public void mouseClicked(MouseEvent e) {
        close();
      }
    };
    addMouseListener(closeOnClick);
    text.addMouseListener(closeOnClick);
    arduinoIcon.addMouseListener(closeOnClick);
    closeButton.addMouseListener(closeOnClick);

    pack();

    updateLocation(parent);
    ComponentAdapter parentMovedListener = new ComponentAdapter() {
      @Override
      public void componentMoved(ComponentEvent e) {
        updateLocation(parent);
      }

      @Override
      public void componentResized(ComponentEvent e) {
        updateLocation(parent);
      }
    };
    parent.addComponentListener(parentMovedListener);
    addWindowListener(new WindowAdapter() {
      @Override
      public void windowClosed(WindowEvent e) {
        parent.removeComponentListener(parentMovedListener);
      }
    });
  }

  private void updateLocation(Frame parent) {
    Point parentLocation = parent.getLocation();

    int parentX = Double.valueOf(parentLocation.getX()).intValue();
    int parentY = Double.valueOf(parentLocation.getY()).intValue();
    setLocation(parentX, parentY + parent.getHeight() - getHeight());
  }

  public void close() {
    if (autoClose) {
      autoCloseTimer.cancel();
    }
    setModal(false);
    dispatchEvent(new WindowEvent(this, WindowEvent.WINDOW_CLOSING));
  }

  public void begin() {
    if (autoClose) {
      autoCloseTimer.schedule(new TimerTask() {
        @Override
        public void run() {
          close();
        }
      }, Constants.NOTIFICATION_POPUP_AUTOCLOSE_DELAY);
    }
    setVisible(true);
    if (PreferencesData.getBoolean("ide.accessible")) {
      requestFocus();
      setModal(true);
    }
  }
}
