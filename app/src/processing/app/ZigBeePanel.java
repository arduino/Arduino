/* -*- mode: jde; c-basic-offset: 2; indent-tabs-mode: nil -*- */

/*
  ZigBeePanel.java - class for talking to an XBee running ZigBee firmware in a non-transparent way.
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

import processing.app.debug.MessageConsumer;
import processing.app.debug.ZigBee;

import javax.swing.JPanel;
import javax.swing.JLabel;
import javax.swing.JComboBox;
import javax.swing.JTextField;
import javax.swing.JButton;
import java.awt.Frame;
import java.awt.GridLayout;

import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.event.DocumentListener;
import javax.swing.event.DocumentEvent;
import javax.swing.text.Document;

class ZigBeePanel extends JPanel implements MessageConsumer, ActionListener, DocumentListener {

  static final String bpsValues[] = {
    "1200",
    "2400",
    "4800",
    "9600",
    "19200",
    "38400",
    "57600",
    "115200"
  };

  static final String parityValues[] = {"N", "E", "O", "M"};

  static final String stopBitValues[] = { "1", "2" };

  static final String dtrValues[] = { "D1", "D2", "D3", "D4" };

  ZigBee zb;
  boolean local;

  JTextField name;
  JLabel address64;
  JTextField address16;
  JTextField networkId;
  JComboBox bps;
  JComboBox parity;
  JButton write;
  JComboBox dtrComboBox;

  ZigBeePanel() {
    super(new GridLayout(10, 2));

    add(new JLabel("Name"));
    name = new JTextField("");
    name.getDocument().addDocumentListener(this);
    add (name);

    add(new JLabel("64 bit address"));
    address64 = new JLabel("");
    add(address64);

    add(new JLabel("16 bit address"));
    address16 = new JTextField("");
    address16.getDocument().addDocumentListener(this);
    add(address16);

    add(new JLabel("Network ID"));
    networkId = new JTextField("");
    networkId.getDocument().addDocumentListener(this);
    add(networkId);

    add(new JLabel("BPS"));
    bps = new JComboBox(bpsValues);
    bps.addActionListener(this);
    add(bps);

    add(new JLabel("Parity"));
    parity = new JComboBox(parityValues);
    parity.addActionListener(this);
    add(parity);

    add(new JLabel("Write to NVRam: "));
    write = new JButton("Write");
    write.setActionCommand("write");
    write.addActionListener(this);
    add (write);

  }

  public void close() {
    name.getDocument().removeDocumentListener(this);
    name = null;
    address64 = null;
    address16.getDocument().removeDocumentListener(this);
    address16 = null;
    networkId.getDocument().removeDocumentListener(this);
    networkId = null;
    bps.removeActionListener(this);
    bps = null;
    parity.removeActionListener(this);
    parity = null;
    write.removeActionListener(this);
    write = null;
    dtrComboBox.removeActionListener(this);
    dtrComboBox = null;
  }

  public void insertUpdate(DocumentEvent e) {
    write.setEnabled(false);
  }

  public void removeUpdate(DocumentEvent e) {
    write.setEnabled(false);
  }

  public void changedUpdate(DocumentEvent e) {
    write.setEnabled(false);
  }

  public void actionPerformed(ActionEvent e) {
    String c = e.getActionCommand();
    if (c.equals("write")) {
      // XXXXX Fixme: Does this need an are you sure dialog?
      try {
        zb.write();
      } catch (Exception ex) {
        Base.showWarning("Unable to update XBee", ex.getMessage(), ex);
        return;
      }
    } else {
      write.setEnabled(false);
    }
  }

  public void setEnabled(boolean b) {
    super.setEnabled(b);
    name.setEnabled(b);
    address16.setEnabled(b);
    networkId.setEnabled(b);
    bps.setEnabled(b);
    parity.setEnabled(b);
    write.setEnabled(false);
    if (dtrComboBox != null) {
      dtrComboBox.setEnabled(b);
    }
    
  }

  String getPrefPrefix() {
    return zb.getPrefPrefix();
  }

  public void addDTRComboBox() {
    add (new JLabel("DTR PIN"));
    dtrComboBox = new JComboBox(dtrValues);
    add(dtrComboBox);
    if (zb == null) {
      dtrComboBox.setSelectedItem("D3");
    } else {
      String prefName = getPrefPrefix() + ".DTR";
      dtrComboBox.setSelectedItem(Preferences.get(prefName));
    }
    validate();
  }

  // part of the PdeMessageConsumer interface
  //
  public void message(String s) {
    // could only update that which has changed.  Would be better, but for now we will be lazy.
    reset();
  }

  public void setZigBee(ZigBee z) {
    if (zb != z) {
      if (zb != null) {
        zb.addListener(null);
      }
      zb = z;
      if (zb != null) {
        zb.addListener(this);
      }
    }

    if(zb != null) {
      name.setText(z.getNI());
      if (z.getSerialNumber() != null) {
        address64.setText(Long.toString(z.getSerialNumber(), 16));
      }
      
      if (z.getAddress() != null) {
        address16.setText(Long.toString(z.getAddress(),16));
      }

      if (z.getPan() != null) {
        networkId.setText(Long.toString(z.getPan(), 16));
      }

      for (int i = 0; i < bpsValues.length; ++i) {
        if (z.getBps() == Long.valueOf(bpsValues[i])) {
          bps.setSelectedIndex(i);
        }
      }

      for (int i = 0; i < parityValues.length; ++i) {
        if (z.getParity() == parityValues[i].charAt(0)) {
          parity.setSelectedIndex(i);
        }
      }
      write.setEnabled(true);
    }
  }

  void reset() {
    setZigBee(zb);
  }

  void shutdown() {
    setZigBee(null);
    name = null;
    address64 = null;
    address16 = null;
    networkId = null;
    bps = null;
    parity = null;
    write = null;
    dtrComboBox = null;
  }

  void apply() {
    if(zb != null) {
      try {
        boolean changed=false;
        if (zb.getNI() != name.getText()) {
          changed = true;
          zb.setNI(name.getText().trim());
        }

        if (Short.parseShort(address16.getText(), 16) != zb.getAddress()) {
          zb.setAddress(Short.valueOf(address16.getText(), 16));
          changed = true;
        }

        if (Long.parseLong(networkId.getText(), 16) != zb.getPan()) {
          zb.setPan(Long.valueOf(networkId.getText(), 16));
          changed = true;
        }

        if (Long.valueOf(bpsValues[bps.getSelectedIndex()]) != zb.getBps()) {
          changed = true;
          zb.setBps(Long.valueOf(bpsValues[bps.getSelectedIndex()]));
        }

        if (parityValues[parity.getSelectedIndex()].charAt(0) != zb.getParity()) {
          changed = true;
          zb.setParity(parityValues[parity.getSelectedIndex()].charAt(0));
        }

        if (dtrComboBox != null) {
          Preferences.set(getPrefPrefix()+".DTR", (String)dtrComboBox.getSelectedItem());
        }

        if (changed) {
          try {
            zb.apply();
            write.setEnabled(true);
          } catch (Exception e) {
            throw e;
          }
        }
      } catch (Exception e) {
        Base.showWarning("Unable to update XBee", e.getMessage(), e);
        return;
      }
    }
  }
}