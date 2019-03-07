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
import cc.arduino.packages.Discovery;
import processing.app.BaseNoGui;

import javax.jmdns.*;
import java.net.InetAddress;
import java.util.*;

public class NetworkDiscovery implements Discovery, ServiceListener, Runnable {

  private final List<BoardPort> reachableBoardPorts = new LinkedList<>();
  private final List<BoardPort> boardPortsDiscoveredWithJmDNS = new LinkedList<>();
  private JmmDNS jmdns = null;

  private void removeDuplicateBoards(BoardPort newBoard) {
    synchronized (boardPortsDiscoveredWithJmDNS) {
      Iterator<BoardPort> iterator = boardPortsDiscoveredWithJmDNS.iterator();
      while (iterator.hasNext()) {
        BoardPort board = iterator.next();
        if (newBoard.getAddress().equals(board.getAddress())) {
          iterator.remove();
        }
      }
    }
  }

  @Override
  public void serviceAdded(ServiceEvent serviceEvent) {
  }

  @Override
  public void serviceRemoved(ServiceEvent serviceEvent) {
    String name = serviceEvent.getName();
    synchronized (boardPortsDiscoveredWithJmDNS) {
      boardPortsDiscoveredWithJmDNS.stream().filter(port -> port.getBoardName().equals(name)).forEach(boardPortsDiscoveredWithJmDNS::remove);
    }
  }

  @Override
  public void serviceResolved(ServiceEvent serviceEvent) {
    while (BaseNoGui.packages == null) {
      try {
        Thread.sleep(1000);
      } catch (InterruptedException e) {
        e.printStackTrace();
      }
    }

    ServiceInfo info = serviceEvent.getInfo();

    for (InetAddress inetAddress : info.getInet4Addresses()) {
      String address = inetAddress.getHostAddress();
      String name = serviceEvent.getName();

      BoardPort port = new BoardPort();

      String board = null;
      String description = null;
      if (info.hasData()) {
        board = info.getPropertyString("board");
        description = info.getPropertyString("description");
        port.getPrefs().put("board", board);
        port.getPrefs().put("distro_version", info.getPropertyString("distro_version"));
        port.getPrefs().put("port", "" + info.getPort());

        //Add additional fields to permit generic ota updates
        //and make sure we do not intefere with Arduino boards
        // define "ssh_upload=no" TXT property to use generic uploader
        // define "tcp_check=no" TXT property if you are not using TCP
        // define "auth_upload=yes" TXT property if you want to use authenticated generic upload
        String useSSH = info.getPropertyString("ssh_upload");
        String checkTCP = info.getPropertyString("tcp_check");
        String useAuth = info.getPropertyString("auth_upload");
        if(useSSH == null || !useSSH.contentEquals("no")) useSSH = "yes";
        if(checkTCP == null || !checkTCP.contentEquals("no")) checkTCP = "yes";
        if(useAuth == null || !useAuth.contentEquals("yes")) useAuth = "no";
        port.getPrefs().put("ssh_upload", useSSH);
        port.getPrefs().put("tcp_check", checkTCP);
        port.getPrefs().put("auth_upload", useAuth);
      }

      String label = name + " at " + address;
      if (board != null && BaseNoGui.packages != null) {
        String boardName = BaseNoGui.getPlatform().resolveDeviceByBoardID(BaseNoGui.packages, board);
        port.setBoardName(boardName);
      } else if (description != null) {
        label += " (" + description + ")";
      }

      port.setAddress(address);
      port.setProtocol("network");
      port.setLabel(label);

      synchronized (boardPortsDiscoveredWithJmDNS) {
        removeDuplicateBoards(port);
        boardPortsDiscoveredWithJmDNS.add(port);
      }
    }
  }

  public NetworkDiscovery() {

  }

  @Override
  public void run() {
    start();
  }

  @Override
  public void start() {
    System.getProperties().setProperty("net.dns.ttl", "10");
    jmdns = JmmDNS.Factory.getInstance();
    jmdns.addServiceListener("_arduino._tcp.local.", this);
  }

  @Override
  public void stop() {
    if (jmdns != null) {
      jmdns.unregisterAllServices();
    }
    // we don't close the JmmDNS instance as it's too slow
    /*
    try {
      jmdns.close();
    } catch (IOException e) {
      e.printStackTrace();
    }
    */
  }

  @Override
  public List<BoardPort> listDiscoveredBoards() {
    synchronized (reachableBoardPorts) {
      return getBoardPortsDiscoveredWithJmDNS();
    }
  }

  @Override
  public List<BoardPort> listDiscoveredBoards(boolean complete) {
    synchronized (reachableBoardPorts) {
      return new LinkedList<>(reachableBoardPorts);
    }
  }

  public void setReachableBoardPorts(List<BoardPort> newReachableBoardPorts) {
    synchronized (reachableBoardPorts) {
      reachableBoardPorts.clear();
      reachableBoardPorts.addAll(newReachableBoardPorts);
    }
  }

  public List<BoardPort> getBoardPortsDiscoveredWithJmDNS() {
    synchronized (boardPortsDiscoveredWithJmDNS) {
      return new LinkedList<>(boardPortsDiscoveredWithJmDNS);
    }
  }
}
