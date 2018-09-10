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
 * Copyright 2018 Arduino SA (http://www.arduino.cc/)
 */

package cc.arduino.packages.discoverers;

import java.util.ArrayList;
import java.util.List;

import cc.arduino.packages.BoardPort;
import cc.arduino.packages.Discovery;
import processing.app.legacy.PApplet;

public class PluggableDiscovery implements Discovery {

  private String discoveryName;

  public PluggableDiscovery(String discoveryName, String[] cmd) {
    this.discoveryName = discoveryName;
    System.out.println("Starting: " + PApplet.join(cmd, " "));
  }

  @Override
  public void run() {
    // TODO this method is started as a new thread, it will constantly
    // communicate with the discovery tool and keep track of the discovered
    // port to be returned from listDiscoveredBoard()
    try {
      start();
      while (true) { // TODO: Find a better way to terminate discovery
        System.out.println(discoveryName + ": looping...");
        Thread.sleep(500);
      }
      // stop();
    } catch (InterruptedException e) {
      e.printStackTrace();
    } catch (Exception e) {
      e.printStackTrace();
    }
  }

  @Override
  public void start() throws Exception {
    // TODO send a START_SYNC command to the discovery tool
    // or fallback to START if not available
  }

  @Override
  public void stop() throws Exception {
    // TODO send a STOP to the discovery
  }

  @Override
  public List<BoardPort> listDiscoveredBoards() {
    // TODO return the ports discovered so far
    final List<BoardPort> empty = new ArrayList<>();
    return empty;
  }

  @Override
  public List<BoardPort> listDiscoveredBoards(boolean complete) {
    // XXX: parameter "complete "is really needed?
    // should be checked on all existing discoveries

    // TODO
    final List<BoardPort> empty = new ArrayList<>();
    return empty;
  }

  @Override
  public String toString() {
    return discoveryName;
  }
}
