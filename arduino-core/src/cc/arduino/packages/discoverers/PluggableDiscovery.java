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

import static processing.app.I18n.format;

import java.io.InputStream;
import java.io.OutputStream;
import java.util.ArrayList;
import java.util.List;

import org.apache.commons.lang3.StringUtils;

import com.fasterxml.jackson.annotation.JsonAutoDetect.Visibility;
import com.fasterxml.jackson.annotation.PropertyAccessor;
import com.fasterxml.jackson.core.JsonFactory;
import com.fasterxml.jackson.core.JsonParser;
import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.DeserializationFeature;
import com.fasterxml.jackson.databind.JsonNode;
import com.fasterxml.jackson.databind.ObjectMapper;

import cc.arduino.packages.BoardPort;
import cc.arduino.packages.Discovery;
import processing.app.PreferencesData;

public class PluggableDiscovery implements Discovery {

  private final String discoveryName;
  private final String[] cmd;
  private final List<BoardPort> portList = new ArrayList<>();
  private Process program=null;
  private Thread pollingThread;

  private void debug(String x) {
    if (PreferencesData.getBoolean("discovery.debug"))
      System.out.println(discoveryName + ": " + x);
  }

  public PluggableDiscovery(String discoveryName, String[] cmd) {
    this.cmd = cmd;
    this.discoveryName = discoveryName;
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
      mapper.setVisibility(PropertyAccessor.ALL, Visibility.NONE);
      mapper.setVisibility(PropertyAccessor.FIELD, Visibility.ANY);
      mapper.configure(DeserializationFeature.FAIL_ON_UNKNOWN_PROPERTIES, false);

      while (program != null && program.isAlive()) {
        JsonNode tree = mapper.readTree(parser);
        if (tree == null) {
          if (program != null && program.isAlive()) {
            System.err.println(format("{0}: Invalid json message", discoveryName));
          }
          break;
        }
        debug("Received json: " + tree);

        processJsonNode(mapper, tree);
      }
      debug("thread exit normally");
    } catch (InterruptedException e) {
      debug("thread exit by interrupt");
      e.printStackTrace();
    } catch (Exception e) {
      debug("thread exit other exception");
      e.printStackTrace();
    }
    try {
      stop();
    } catch (Exception e) {
    }
  }

  private void processJsonNode(ObjectMapper mapper, JsonNode node) {
    JsonNode eventTypeNode = node.get("eventType");
    if (eventTypeNode == null) {
      System.err.println(format("{0}: Invalid message, missing eventType", discoveryName));
      return;
    }

    switch (eventTypeNode.asText()) {
    case "error":
      try {
        PluggableDiscoveryMessage msg = mapper.treeToValue(node, PluggableDiscoveryMessage.class);
        debug("error: " + msg.getMessage());
        if (msg.getMessage().contains("START_SYNC")) {
          startPolling();
        }
      } catch (JsonProcessingException e) {
        e.printStackTrace();
      }
      return;

    case "list":
      JsonNode portsNode = node.get("ports");
      if (portsNode == null) {
        System.err.println(format("{0}: Invalid message, missing ports list", discoveryName));
        return;
      }
      if (!portsNode.isArray()) {
        System.err.println(format("{0}: Invalid message, ports list should be an array", discoveryName));
        return;
      }

      synchronized (portList) {
        portList.clear();
      }
      portsNode.forEach(portNode -> {
        BoardPort port = mapJsonNodeToBoardPort(mapper, node);
        if (port != null) {
          addOrUpdate(port);
        }
      });
      return;

    // Messages for SYNC updates

    case "add":
      BoardPort addedPort = mapJsonNodeToBoardPort(mapper, node);
      if (addedPort != null) {
        addOrUpdate(addedPort);
      }
      return;

    case "remove":
      BoardPort removedPort = mapJsonNodeToBoardPort(mapper, node);
      if (removedPort != null) {
        remove(removedPort);
      }
      return;

    default:
      debug("Invalid event: " + eventTypeNode.asText());
      return;
    }
  }

  private BoardPort mapJsonNodeToBoardPort(ObjectMapper mapper, JsonNode node) {
    try {
      BoardPort port = mapper.treeToValue(node.get("port"), BoardPort.class);
      // if no label, use address
      if (port.getLabel() == null || port.getLabel().isEmpty()) {
        port.setLabel(port.getAddress());
      }
      port.searchMatchingBoard();
      return port;
    } catch (JsonProcessingException e) {
      System.err.println(format("{0}: Invalid BoardPort message", discoveryName));
      e.printStackTrace();
      return null;
    }
  }

  @Override
  public void start() throws Exception {
    try {
      debug("Starting: " + StringUtils.join(cmd, " "));
      program = Runtime.getRuntime().exec(cmd);
    } catch (Exception e) {
      program = null;
      return;
    }
    debug("START_SYNC");
    write("START_SYNC\n");
    pollingThread = null;
  }

  private void startPolling() {
    // Discovery tools not supporting START_SYNC require a periodic
    // LIST command.  A second thread is created to send these
    // commands, while the run() thread above listens for the
    // discovery tool output.
    debug("START");
    write("START\n");
    Thread pollingThread = new Thread() {
      public void run() {
        try {
          while (program != null && program.isAlive()) {
            debug("LIST");
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

  private void addOrUpdate(BoardPort port) {
    String address = port.getAddress();
    if (address == null)
      return; // address required for "add" & "remove"

    synchronized (portList) {
      // if address already on the list, discard old info
      portList.removeIf(bp -> address.equals(bp.getAddress()));
      portList.add(port);
    }
  }

  private void remove(BoardPort port) {
    String address = port.getAddress();
    if (address == null)
      return; // address required for "add" & "remove"
    synchronized (portList) {
      portList.removeIf(bp -> address.equals(bp.getAddress()));
    }
  }

  @Override
  public List<BoardPort> listDiscoveredBoards() {
    synchronized (portList) {
      return new ArrayList<>(portList);
    }
  }

  @Override
  public List<BoardPort> listDiscoveredBoards(boolean complete) {
    // XXX: parameter "complete "is really needed?
    // should be checked on all existing discoveries
    synchronized (portList) {
      return new ArrayList<>(portList);
    }
  }

  @Override
  public String toString() {
    return discoveryName;
  }
}
