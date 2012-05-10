/* -*- mode: jde; c-basic-offset: 2; indent-tabs-mode: nil -*- */

/*
  XBeePanel.java - class for talking to an XBee running XgBee firmware in a non-transparent way.
  Part of the Arduino project - http://www.arduino.cc/

  Copyright (c) 2012
  Ross Biro
  
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
  
  $Id$
*/
package processing.app;

import javax.swing.JDialog;
import javax.swing.JComboBox;
import javax.swing.JPanel;
import javax.swing.JLabel;
import javax.swing.BoxLayout;
import javax.swing.JSplitPane;
import javax.swing.JButton;
import java.awt.BorderLayout;
import java.awt.FlowLayout;
import javax.swing.border.EmptyBorder;
import java.awt.Frame;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.event.ItemListener;
import java.awt.event.ItemEvent;
import java.awt.event.WindowStateListener;
import java.awt.event.WindowEvent;

import java.util.HashSet;

import processing.app.debug.ZigBee;
import processing.app.debug.MessageConsumer;
import processing.app.Base;

public class XBeePanel extends JDialog implements ActionListener, MessageConsumer, ItemListener, WindowStateListener {

  ZigBeePanel localZigBee;
  ZigBeePanel remoteZigBee;

  JButton applyButton;
  JButton okButton;
  JButton cancelButton;
  JButton connectButton;
  JButton refreshButton;
  JComboBox remoteComboBox;
  ZigBee local;
  static boolean foundZigBee;
  static Boolean portChanged = new Boolean(true);
    
  XBeePanel() {
    super ((Frame)null, "XBee");
    addWindowStateListener(this);
    setDefaultCloseOperation(DISPOSE_ON_CLOSE);

    if (!isXBee()) {
      Base.showWarning("XBee Not Found", null, null);
      dispose();
    }

    try {
      local = ZigBee.getLocal();
    } catch (Exception e) {
      Base.showWarning("XBee Not Found", e.getMessage(), e);
    }

    JPanel localPanel = new JPanel();
    BoxLayout box1 = new BoxLayout(localPanel, BoxLayout.Y_AXIS);
    localPanel.setLayout(box1);
    localPanel.setBorder(new EmptyBorder(10, 10, 10, 10));

    JLabel port = new JLabel(Preferences.get("serial.port"));
    localPanel.add(port);
    localZigBee = new ZigBeePanel();
    localPanel.add(localZigBee);
    localZigBee.setZigBee(local);

    JPanel remotePanel = new JPanel();
    BoxLayout box2 = new BoxLayout(remotePanel, BoxLayout.Y_AXIS);
    remotePanel.setLayout(box2);
    remotePanel.setBorder(new EmptyBorder(10,10,10,10));

    try {
      ZigBee.searchForNodes();
    } catch (Exception e) {
      Base.showWarning("Unable to find remote XBees", e.getMessage(), e);
    }

    remoteComboBox = new JComboBox();
    remotePanel.add(remoteComboBox);
    remoteZigBee = new ZigBeePanel();
    remoteZigBee.addDTRComboBox();
    remotePanel.add(remoteZigBee);
    remoteZigBee.setEnabled(false);
    remoteComboBox.setEnabled(false);

    ZigBee.addStaticListener(this);
    remoteComboBox.addItemListener(this);
    JSplitPane splitPane = new JSplitPane(JSplitPane.HORIZONTAL_SPLIT, remotePanel, localPanel);
    
    populateComboBox();

    splitPane.setResizeWeight(.5);

    JPanel buttonPanel = new JPanel();
    buttonPanel.setLayout(new FlowLayout(FlowLayout.TRAILING));

    refreshButton = new JButton("Refresh");
    refreshButton.setActionCommand("refresh");
    refreshButton.addActionListener(this);

    connectButton = new JButton("Connect");
    connectButton.setActionCommand("connect");
    connectButton.addActionListener(this);
    connectButton.setEnabled(false);

    applyButton = new JButton("Apply");
    applyButton.setActionCommand("apply");
    applyButton.addActionListener(this);

    okButton = new JButton("OK");
    okButton.setActionCommand("ok");
    okButton.addActionListener(this);

    cancelButton = new JButton("Cancel");
    cancelButton.setActionCommand("cancel");
    cancelButton.addActionListener(this);

    buttonPanel.add(refreshButton);
    buttonPanel.add(connectButton);
    buttonPanel.add(applyButton);
    buttonPanel.add(okButton);
    buttonPanel.add(cancelButton);
    getContentPane().add (buttonPanel, BorderLayout.SOUTH);
    getContentPane().add(splitPane, BorderLayout.CENTER);
	    
    setSize(getPreferredSize());
    setVisible(true);
  }

  // part of the PdeMessageConsumer interface
  //
  public void message(String s) {
    // could only update that which has changed.  Would be better, but for now we will be lazy.
    populateComboBox();
  }

  public void actionPerformed(ActionEvent e) {
    if (!foundZigBee) {
      cancel();
    }

    String c = e.getActionCommand();
    if (c.equals("ok")) {
      ok();
    } else if (c.equals("cancel")) {
      cancel();
    } else if (c.equals("apply")) {
      apply();
    } else if (c.equals("connect")) {
      connect();
    } else if (c.equals("disconnect")) {
      disconnect();
      Preferences.setBoolean("XBee.port."+Preferences.get("serial.port"), false);
    } else if (c.equals("refresh")) {
      refresh();
    }
  }

  void refresh() {
    try {
      ZigBee.searchForNodes();
    } catch (Exception e) {
    }
  }

  void ok() {
    apply();
    close();
  }

  void apply() {
    localZigBee.apply();
    remoteZigBee.apply();
  }

  void cancel() {
    close();
  }

  void close() {
    dispose();
  }

  void connect() {
    try {
      ZigBee zb = (ZigBee)remoteComboBox.getSelectedItem();
      if (zb != null) {
        zb.connect();
        connectButton.setText("Disconnect");
        connectButton.setActionCommand("disconnect");
      }
    } catch (Exception e) {
      Base.showWarning("Connect Failed", e.getMessage(), e);
    }
  }

  void disconnect() {
    try {
      local.disconnect();
      connectButton.setText("Connect");
      connectButton.setActionCommand("connect");
    } catch (Exception e) {
      Base.showWarning("Disconnect Failed", e.getMessage(), e);
    }
  }

  void populateComboBox() {
    ZigBee[] z = ZigBee.getNodes();
    HashSet<ZigBee> s = new HashSet<ZigBee>();
    for (int i = 0; i < remoteComboBox.getItemCount(); ++i) {
      s.add((ZigBee)remoteComboBox.getItemAt(i));
    }
    for (int i = 0; i < z.length; ++i) {
      if (s.contains(z[i]) || z[i].getSerialNumber() == local.getSerialNumber()) {
        continue;
      }
      remoteComboBox.addItem(z[i]);
    }
    if (z.length > 1) {
      if (connectButton != null) {
        connectButton.setEnabled(true);
      }
      remoteComboBox.setEnabled(true);
      remoteZigBee.setEnabled(true);
    } else {
      if (connectButton != null) {
        connectButton.setEnabled(false);
      }
      remoteComboBox.setEnabled(false);
      remoteZigBee.setEnabled(false);
    }
    remoteComboBox.repaint(); // Might have added a name.
  }

  static public void onPortChange() {
    foundZigBee = false;
    ZigBee.onPortChanged();
    synchronized(portChanged) {
      if (Preferences.getBoolean("XBee.port."+Preferences.get("serial.port"))) {
        portChanged = false;
        foundZigBee = true;
      } else {
        portChanged = true;
      }
    }
  }


  static public boolean isXBee() {
    synchronized(portChanged) {
      if (!portChanged) {
        return foundZigBee;
      }
      portChanged = false;
    }

    try {
      ZigBee.close(); // make sure we are the only one.
      ZigBee.getLocal();
    } catch (Exception e) {
      foundZigBee = false;
      Preferences.setBoolean("XBee.port."+Preferences.get("serial.port"), false);
      return false;
    }

    Preferences.setBoolean("XBee.port."+Preferences.get("serial.port"), true);
    foundZigBee = true;
    return true;
  }

  public void itemStateChanged(ItemEvent e) {
    if (e.getStateChange() == ItemEvent.DESELECTED) {
      remoteZigBee.setZigBee(null);
    } else if (e.getStateChange() == ItemEvent.SELECTED) {
      if (e != null) {
        ZigBee zb = (ZigBee)e.getItem();
        remoteZigBee.setZigBee(zb);
        if (zb.isConnected()) {
          if (connectButton != null) {
            connectButton.setEnabled(true);
            connectButton.setText("Disconnect");
            connectButton.setActionCommand("disconnect");
          }
        } else {
          if (connectButton != null) {
            connectButton.setEnabled(true);
            connectButton.setText("Connect");
            connectButton.setActionCommand("connect");
          }
        }
        try {
          zb.updateSerialParameters();
        } catch (Exception t) {
          t.printStackTrace();
        }
      }
    }
  }

  public void windowStateChanged(WindowEvent e) {
    if (e.getNewState() == WindowEvent.WINDOW_CLOSING ||
        e.getNewState() == WindowEvent.WINDOW_CLOSED) {
      removeWindowStateListener(this);
      applyButton.removeActionListener(this);
      okButton.removeActionListener(this);
      cancelButton.removeActionListener(this);
      remoteComboBox.removeItemListener(this);
      connectButton.removeActionListener(this);
      ZigBee.addStaticListener(null);
      remoteZigBee.close();
      remoteZigBee = null;
      localZigBee.close();
      localZigBee=null;
      applyButton = null;
      connectButton=null;
      okButton = null;
      cancelButton = null;
      remoteComboBox = null;
      local = null;
    }
  }
    
}