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

package cc.arduino.packages.discoverers.serial;

import cc.arduino.packages.BoardPort;
import cc.arduino.packages.discoverers.SerialDiscovery;
import processing.app.BaseNoGui;
import processing.app.Platform;
import processing.app.debug.TargetBoard;

import java.util.*;

public class SerialBoardsLister extends TimerTask {

  private final SerialDiscovery serialDiscovery;
  private final List<BoardPort> boardPorts = new LinkedList<>();
  private List<String> oldPorts = new LinkedList<>();
  public boolean uploadInProgress = false;
  public boolean pausePolling = false;
  private BoardPort oldUploadBoardPort = null;

  public SerialBoardsLister(SerialDiscovery serialDiscovery) {
    this.serialDiscovery = serialDiscovery;
  }

  public void start(Timer timer) {
    timer.schedule(this, 0, 1000);
  }

  public synchronized void retriggerDiscovery(boolean polled) {
    Platform platform = BaseNoGui.getPlatform();
    if (platform == null) {
      return;
    }

    if (polled && pausePolling) {
      return;
    }

    List<String> ports = platform.listSerials();
    if (ports.equals(oldPorts)) {
      return;
    }

    // if (updating) {}
    // a port will disappear, another will appear
    // use this information to "merge" the boards
    // updating must be signaled by SerialUpload class

    oldPorts.clear();
    oldPorts.addAll(ports);

    for (BoardPort board : boardPorts) {
      if (ports.contains(board.toString())) {
        if (board.isOnline()) {
          ports.remove(ports.indexOf(board.toString()));
        }
      } else {
        if (uploadInProgress && board.isOnline()) {
          oldUploadBoardPort = board;
        }
        board.setOnlineStatus(false);
      }
    }

    for (String newPort : ports) {

      String[] parts = newPort.split("_");

      if (parts.length < 3) {
        // something went horribly wrong
        continue;
      }

      if (parts.length > 3) {
        // port name with _ in it (like CP2102 on OSX)
        for (int i = 1; i < (parts.length-2); i++) {
          parts[0] += "_" + parts[i];
        }
        parts[1] = parts[parts.length-2];
        parts[2] = parts[parts.length-1];
      }

      String port = parts[0];

      Map<String, Object> boardData = platform.resolveDeviceByVendorIdProductId(port, BaseNoGui.packages);

      BoardPort boardPort = null;
      boolean updatingInfos = false;
      int i = 0;
      // create new board or update existing
      for (BoardPort board : boardPorts) {
        if (board.toString().equals(newPort)) {
          updatingInfos = true;
          boardPort = boardPorts.get(i);
          break;
        }
        i++;
      }
      if (!updatingInfos) {
        boardPort = new BoardPort();
      }
      boardPort.setAddress(port);
      boardPort.setProtocol("serial");
      boardPort.setOnlineStatus(true);

      String label = port;

      if (boardData != null) {
        boardPort.getPrefs().put("vid", boardData.get("vid").toString());
        boardPort.getPrefs().put("pid", boardData.get("pid").toString());
        boardPort.setVIDPID(parts[1], parts[2]);

        String iserial = boardData.get("iserial").toString();
        if (iserial.length() >= 10) {
          boardPort.getPrefs().put("iserial", iserial);
          boardPort.setISerial(iserial);
        }
        if (uploadInProgress && oldUploadBoardPort!=null) {
          oldUploadBoardPort.getPrefs().put("iserial", iserial);
          oldUploadBoardPort.setISerial(iserial);
        }

        TargetBoard board = (TargetBoard) boardData.get("board");
        if (board != null) {
          String boardName = board.getName();
          if (boardName != null) {
            label += " (" + boardName + ")";
          }
          boardPort.setBoardName(boardName);
        }
      } else {
        if (!parts[1].equals("0000")) {
          boardPort.setVIDPID(parts[1], parts[2]);
          // ask Cloud API to match the board with known VID/PID pair
          platform.getBoardWithMatchingVidPidFromCloud(parts[1], parts[2]);
        } else {
          boardPort.setVIDPID("0000", "0000");
          boardPort.setISerial("");
        }
      }

      boardPort.setLabel(label);
      if (!updatingInfos) {
        boardPorts.add(boardPort);
      }
    }
    serialDiscovery.setSerialBoardPorts(boardPorts);
  }

  @Override
  public void run() {
     if (BaseNoGui.packages == null) {
        return;
     }
     retriggerDiscovery(true);
  }
}
