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
import cc.arduino.packages.Discovery;
import processing.app.BaseNoGui;
import processing.app.Platform;
import processing.app.debug.TargetBoard;
import processing.app.helpers.BoardCloudResolver;

import java.util.*;

public class SerialDiscovery implements Discovery, Runnable {

  private Timer serialBoardsListerTimer;
  private final List<BoardPort> serialBoardPorts = new ArrayList<>();
  private final List<BoardPort> boardPorts = new ArrayList<>();
  private final List<String> oldPorts = new ArrayList<>();
  public boolean uploadInProgress = false;
  public boolean pausePolling = false;
  private BoardPort oldUploadBoardPort = null;
  private final BoardCloudResolver boardCloudResolver = new BoardCloudResolver();


  @Override
  public List<BoardPort> listDiscoveredBoards() {
    return listDiscoveredBoards(false);
  }

  @Override
  public List<BoardPort> listDiscoveredBoards(boolean complete) {
      if (complete) {
        return new ArrayList<>(serialBoardPorts);
      }
      List<BoardPort> onlineBoardPorts = new ArrayList<>();
      for (BoardPort port : serialBoardPorts) {
        if (port.isOnline() == true) {
          onlineBoardPorts.add(port);
        }
      }
      return onlineBoardPorts;
  }

  public void setSerialBoardPorts(List<BoardPort> newSerialBoardPorts) {
      serialBoardPorts.clear();
      serialBoardPorts.addAll(newSerialBoardPorts);
  }

  public void setUploadInProgress(boolean param) {
    uploadInProgress = param;
  }

  public void pausePolling(boolean param) {
    pausePolling = param;
  }

  @Override
  public void run() {
    start();
  }

  @Override
  public void start() {
    serialBoardsListerTimer = new Timer(SerialDiscovery.class.getName());
    serialBoardsListerTimer.schedule(new TimerTask() {
      @Override
      public void run() {
        if (BaseNoGui.packages != null && !pausePolling) {
          forceRefresh();
        }
      }
    }, 0, 1000);
  }

  @Override
  public void stop() {
    serialBoardsListerTimer.cancel();
  }

  public synchronized void forceRefresh() {
    Platform platform = BaseNoGui.getPlatform();
    if (platform == null) {
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
      int i = 0;
      // create new board or update existing
      for (BoardPort board : boardPorts) {
        if (board.toString().equals(newPort)) {
          boardPort = boardPorts.get(i);
          break;
        }
        i++;
      }
      if (boardPort == null) {
        boardPort = new BoardPort();
        boardPorts.add(boardPort);
      }
      boardPort.setAddress(port);
      boardPort.setProtocol("serial");
      boardPort.setOnlineStatus(true);

      String label = port;

      if (boardData != null) {
        boardPort.getPrefs().put("vid", boardData.get("vid").toString());
        boardPort.getPrefs().put("pid", boardData.get("pid").toString());

        String iserial = boardData.get("iserial").toString();
        if (iserial.length() >= 10) {
          boardPort.getPrefs().put("iserial", iserial);
        }
        if (uploadInProgress && oldUploadBoardPort!=null) {
          oldUploadBoardPort.getPrefs().put("iserial", iserial);
        }

        TargetBoard board = (TargetBoard) boardData.get("board");
        if (board != null) {
          String boardName = board.getName();
          boardPort.setBoardName(boardName);
        }
      } else {
        if (!parts[1].equals("0000")) {
          boardPort.getPrefs().put("vid", parts[1]);
          boardPort.getPrefs().put("pid", parts[2]);
          // ask Cloud API to match the board with known VID/PID pair
          boardCloudResolver.getBoardBy(parts[1], parts[2]);
        } else {
          boardPort.getPrefs().put("vid", "0000");
          boardPort.getPrefs().put("pid", "0000");
          boardPort.getPrefs().put("iserial", "");
        }
      }

      boardPort.setLabel(label);
    }
    setSerialBoardPorts(boardPorts);
  }
}
