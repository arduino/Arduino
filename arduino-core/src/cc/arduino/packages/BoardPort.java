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
 * Copyright 2013 Arduino LLC (http://www.arduino.cc/)
 */

package cc.arduino.packages;

import processing.app.helpers.PreferencesMap;

public class BoardPort {

  private String address;   // unique name for this port, used by Preferences
  private String protocol;  // how to communicate, used for Ports menu sections
  private String boardName;
  private String label;     // friendly name shown in Ports menu
  private final PreferencesMap prefs; // "vendorId", "productId", "serialNumber"
  private boolean online;   // used by SerialBoardsLister (during upload??)

  public BoardPort() {
    this.prefs = new PreferencesMap();
  }

  public BoardPort(BoardPort bp) {
    prefs = new PreferencesMap(bp.prefs);
    address = bp.address;
    protocol = bp.protocol;
    boardName = bp.boardName;
    label = bp.label;
    online = bp.online;
  }

  public String getAddress() {
    return address;
  }

  public void setAddress(String address) {
    this.address = address;
  }

  public String getProtocol() {
    return protocol;
  }

  public void setProtocol(String protocol) {
    this.protocol = protocol;
  }

  public String getBoardName() {
    return boardName;
  }

  public void setBoardName(String boardName) {
    this.boardName = boardName;
  }

  public PreferencesMap getPrefs() {
    return prefs;
  }

  public void setLabel(String label) {
    this.label = label;
  }

  public String getLabel() {
    return label;
  }

  public void setOnlineStatus(boolean online) {
    this.online = online;
  }

  public boolean isOnline() {
    return online;
  }

  public void setVIDPID(String vid, String pid) {
    if (vid == null) {
      prefs.remove("vendorId");
    } else {
      prefs.put("vendorId", vid);
    }
    if (pid == null) {
      prefs.remove("productId");
    } else {
      prefs.put("productId", pid);
    }
  }

  public String getVID() {
    return prefs.get("vendorId");
  }

  public String getPID() {
    return prefs.get("productId");
  }

  public void setISerial(String iserial) {
    if (iserial == null) {
      prefs.remove("serialNumber");
    } else {
      prefs.put("serialNumber", iserial);
    }
  }
  public String getISerial() {
    return prefs.get("serialNumber");
  }

  @Override
  public String toString() {
    return this.address+"_"+getVID()+"_"+getPID();
  }
}
