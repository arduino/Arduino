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
import java.util.LinkedList;
import java.util.List;
import java.io.InputStream;
import java.io.OutputStream;

import cc.arduino.packages.BoardPort;
import cc.arduino.packages.Discovery;
import processing.app.legacy.PApplet;

import com.fasterxml.jackson.databind.ObjectMapper;
import com.fasterxml.jackson.databind.DeserializationFeature;
import com.fasterxml.jackson.core.JsonFactory;
import com.fasterxml.jackson.core.JsonParser;

public class PluggableDiscovery implements Discovery {

  private final String discoveryName;
  private final String[] cmd;
  private final List<BoardPort> portList;
  private Process program=null;
  private Thread pollingThread;

  public PluggableDiscovery(String discoveryName, String[] cmd) {
    this.cmd = cmd;
    this.discoveryName = discoveryName;
    portList = new LinkedList<>();
    System.out.println(discoveryName + ": Starting: " + PApplet.join(cmd, " "));
  }

  @Override
  public void run() {
    // this method is started as a new thread, it will constantly listen
    // to the discovery tool and keep track of the discovered ports
    try {
      start();
      InputStream input = program.getInputStream();
      JsonFactory factory = new JsonFactory();
      JsonParser parser = factory.createParser(input);
      ObjectMapper mapper = new ObjectMapper();
      mapper.configure(DeserializationFeature.FAIL_ON_UNKNOWN_PROPERTIES, false);

      while (program != null && program.isAlive()) {
        PluggableDiscoveryMessage msg = mapper.readValue(parser, PluggableDiscoveryMessage.class);
        if (msg != null) {
          System.out.println(discoveryName + ": received json");
          String event = msg.getEventType();
          if (event != null) {
            if (event.equals("Error: START_SYNC not supported")) {
              if (pollingThread == null) {
                startPolling();
              }
            } else {
              update(msg);
            }
          }
        }
      }
      System.out.println(discoveryName + ": thread exit normally");
    } catch (InterruptedException e) {
      System.out.println(discoveryName + ": thread exit by interrupt");
      e.printStackTrace();
    } catch (Exception e) {
      System.out.println(discoveryName + ": thread exit other exception");
      e.printStackTrace();
    }
    try {
      stop();
    } catch (Exception e) {
    }
  }

  @Override
  public void start() throws Exception {
    System.out.println(discoveryName + ": start");
    try {
      program = Runtime.getRuntime().exec(cmd);
    } catch (Exception e) {
      program = null;
      return;
    }
    write("START_SYNC\n");
    pollingThread = null;
  }

  private void startPolling() {
    // Discovery tools not supporting START_SYNC require a periodic
    // LIST command.  A second thread is created to send these
    // commands, while the run() thread above listens for the
    // discovery tool output.
    write("START\n");
    Thread pollingThread = new Thread() {
      public void run() {
        try {
          while (program != null && program.isAlive()) {
            write("LIST\n");
            sleep(2500);
          }
        } catch (Exception e) {
        }
      }
    };
    pollingThread.start();
  }

  @Override
  public void stop() throws Exception {
    if (pollingThread != null) {
      pollingThread.interrupt();
      pollingThread = null;
    }
    write("STOP\n");
    if (program != null) {
      program.destroy();
      program = null;
    }
  }

  private void write(String command) {
    if (program != null && program.isAlive()) {
      OutputStream out = program.getOutputStream();
      try {
        out.write(command.getBytes());
        out.flush();
      } catch (Exception e) {
      }
    }
  }

  private synchronized void update(PluggableDiscoveryMessage port) {
    // Update the list of discovered ports, which may involve
    // adding a new port, replacing the info for a previously
    // discovered port, or removing a port.  This function
    // must be synchronized with listDiscoveredBoards(), to
    // avoid changing the list while it's being accessed by
    // another thread.
    String address = port.getAddress();
    if (address == null) return; // address required for "add" & "remove"
    for (BoardPort bp : portList) {
      if (address.equals(bp.getAddress())) {
        // if address already on the list, discard old info
        portList.remove(bp);
      }
    }
    if (port.getEventType().equals("add")) {
      if (port.getLabel() == null) {
        // if no label, use address
        port.setLabel(address);
      }
      if (port.getProtocol() == null) {
        // if no protocol, assume serial
        port.setProtocol("serial");
      }
      portList.add(port);
    }
  }

  @Override
  public synchronized List<BoardPort> listDiscoveredBoards() {
    // return the ports discovered so far.  Because the list of
    // ports may change at any moment, a copy of the list is
    // returned for use by the rest of the IDE.  This copy
    // operation must be synchronized with update() to assure
    // a clean copy.
    final List<BoardPort> portListCopy = new ArrayList<>();
    for (BoardPort bp : portList) {
      portListCopy.add(new BoardPort(bp));
    }
    return portListCopy;
  }

  @Override
  public List<BoardPort> listDiscoveredBoards(boolean complete) {
    // XXX: parameter "complete "is really needed?
    // should be checked on all existing discoveries
    return listDiscoveredBoards();
  }

  @Override
  public String toString() {
    return discoveryName;
  }
}
