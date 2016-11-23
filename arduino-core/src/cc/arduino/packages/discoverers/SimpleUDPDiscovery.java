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

package cc.arduino.packages.discoverers;

import cc.arduino.packages.BoardPort;
import processing.app.BaseNoGui;
import cc.arduino.packages.Discovery;
import cc.arduino.packages.discoverers.simpleudp.UdpRunnable;

import java.util.LinkedList;
import java.util.List;
import java.util.Timer;

public class SimpleUDPDiscovery implements Discovery {

  private Timer udpBoardsListerTimer;
  private Thread thread;
  private UdpRunnable runner;
  //private SerialBoardsLister serialBoardsLister = new SerialBoardsLister((SerialBoardsLister)this);

  public SimpleUDPDiscovery() {
  }

  @Override
  public List<BoardPort> listDiscoveredBoards() {
    return getudpBoardPorts(false);
  }

  @Override
  public List<BoardPort> listDiscoveredBoards(boolean complete) {
    return getudpBoardPorts(complete);
  }

  private List<BoardPort> getudpBoardPorts(boolean complete) {
	  
	  zapLongNotSeen();
	  
      if (complete) {
        return new LinkedList<>(runner.udpBoardPorts);
      }
      List<BoardPort> onlineBoardPorts = new LinkedList<>();
      for (BoardPort port : runner.udpBoardPorts) {
        if (port.isOnline() == true) {
          onlineBoardPorts.add(port);
        }
      }
      return onlineBoardPorts;
  }

  public void setudpBoardPorts(List<BoardPort> newudpBoardPorts) {
  }

  public void zapLongNotSeen() {
//System.out.println("zap");
	  
      long jetzt = System.currentTimeMillis();
	  long alt = jetzt - 60000;    // 60 sekunden nicht gesehen? Alt

      List<BoardPort> timeouts = new LinkedList<>();
      for (BoardPort port : runner.udpBoardPorts) {
        if (port.getLastseen() < alt) {
          timeouts.add(port);
//System.out.println("Alt!");
        }
      }
      runner.udpBoardPorts.removeAll(timeouts);
  }

  public void setUploadInProgress(boolean param) {
    //serialBoardsLister.uploadInProgress = param;
  }

  public void pausePolling(boolean param) { 
    //serialBoardsLister.pausePolling = param;
  }

  @Override
  public void start() {
//System.out.println("SimpleUDPDiscovery.start!!!");

    runner = new UdpRunnable();
	thread = new Thread(runner);
    thread.start();
  }

  @Override
  public void stop() {
    runner.terminate();
  }
}

