/* -*- mode: java; c-basic-offset: 2; indent-tabs-mode: nil -*- */

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
import javax.swing.*;
import javax.swing.event.MouseInputListener;
import javax.swing.text.SimpleAttributeSet;

import cc.arduino.packages.BoardPort;
import processing.app.Editor.SerialMenuListener;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.MouseEvent;

import static processing.app.I18n.tr;
import static processing.app.Theme.scale;

import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Random;
import java.util.concurrent.Executors;
import java.util.concurrent.ScheduledExecutorService;
import java.util.concurrent.TimeUnit;

/**
 * Serial bar to show SerialBarButton(s) representing serial ports, added by Felix Rusu
 */
public class SerialBar extends JPanel {
  private final Editor editor;
  
  class SerialBarListener implements ActionListener {
    private final String serialPort;

    public SerialBarListener(String serialPort) {
      this.serialPort = serialPort;
    }

    public void actionPerformed(ActionEvent e) {
      editor.selectSerialPort(serialPort);
      editor.base.onBoardOrPortChange();
      refresh();
    }
  }

  public SerialBar(Editor editor) {
    this.editor = editor;
    setLayout(new FlowLayout(FlowLayout.LEFT));

//    JPanel that = this;
//    JButton btn = new JButton("Random");
//    btn.addActionListener(new java.awt.event.ActionListener() {
//      public void actionPerformed(java.awt.event.ActionEvent e) {
//        JLabel someLabel = new JLabel("[" + Math.random() + "]");
//        that.add(someLabel);
//        that.revalidate();
//        }
//    });
//    add(btn);
    
    Runnable serialPollRunnable = new Runnable() {
      public void run() {
        refresh();
      }
    };

    ScheduledExecutorService executor = Executors.newScheduledThreadPool(1);
    executor.scheduleAtFixedRate(serialPollRunnable, 0, 1, TimeUnit.SECONDS);
  }
  
  public void refresh() {
    String selectedPort = PreferencesData.get("serial.port");
    List<BoardPort> ports = Base.getDiscoveryManager().discovery();
    ports = editor.platform.filterPorts(ports, PreferencesData.getBoolean("serial.ports.showall"));

    StringBuilder portsString = new StringBuilder();
    for (BoardPort port : ports) {
      portsString.append("[");
      if (selectedPort.equals(port.getAddress()))
      portsString.append("!");
      portsString.append(port.getAddress());
      portsString.append("]");
    }

    Component[] buttons = this.getComponents();
    StringBuilder buttonsString = new StringBuilder();
    for (Component b : buttons) {
      if (b instanceof ShortcutBarButton)
      {
        buttonsString.append(((ShortcutBarButton)b).toString());
      }
    }

    if (!(portsString.toString().equals(buttonsString.toString()))) {
      this.removeAll();
      int count=0;
      for (BoardPort port : ports) {
        String address = port.getAddress();
        String label = port.getLabel();
        SerialBarListener listener = new SerialBarListener(address);
        ShortcutBarButton serBut = new ShortcutBarButton(label, address, null, address.equals(selectedPort), Color.RED);
        serBut.addActionListener(listener);
        this.add(serBut);
        count++;
      }
      
      if (count == 0) this.add(new JLabel(tr("No ports available...")));
      this.revalidate();
      this.repaint();
    }
  }

  public Dimension getPreferredSize() {
    return getMinimumSize();
  }

  public Dimension getMinimumSize() {
    return new Dimension(100, 32);
  }

  public Dimension getMaximumSize() {
    return new Dimension(scale(30000), 32);
  }
}