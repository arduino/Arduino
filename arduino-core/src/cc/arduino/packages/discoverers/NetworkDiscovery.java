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
import cc.arduino.packages.discoverers.network.BoardReachabilityFilter;
import cc.arduino.packages.discoverers.network.NetworkChecker;
import org.apache.commons.compress.utils.IOUtils;
import processing.app.BaseNoGui;
import processing.app.zeroconf.jmdns.ArduinoDNSTaskStarter;

import javax.jmdns.*;
import javax.jmdns.impl.DNSTaskStarter;
import java.io.IOException;
import java.net.InetAddress;
import java.util.*;

public class NetworkDiscovery implements Discovery, ServiceListener, cc.arduino.packages.discoverers.network.NetworkTopologyListener {

  private static final int MAX_TIME_AWAITING_FOR_PACKAGES = 5000;

  private final List<BoardPort> boardPortsDiscoveredWithJmDNS;
  private final Map<InetAddress, JmDNS> mappedJmDNSs;
  private Timer networkCheckerTimer;
  private Timer boardReachabilityFilterTimer;
  private final List<BoardPort> reachableBoardPorts;

  public NetworkDiscovery() {
    DNSTaskStarter.Factory.setClassDelegate(new ArduinoDNSTaskStarter());
    this.boardPortsDiscoveredWithJmDNS = new LinkedList<>();
    this.mappedJmDNSs = new Hashtable<>();
    this.reachableBoardPorts = new LinkedList<>();
  }

  @Override
  public List<BoardPort> listDiscoveredBoards() {
    synchronized (reachableBoardPorts) {
      return new LinkedList<>(reachableBoardPorts);
    }
  }

  public void setReachableBoardPorts(List<BoardPort> newReachableBoardPorts) {
    synchronized (reachableBoardPorts) {
      this.reachableBoardPorts.clear();
      this.reachableBoardPorts.addAll(newReachableBoardPorts);
    }
  }

  public List<BoardPort> getBoardPortsDiscoveredWithJmDNS() {
    synchronized (boardPortsDiscoveredWithJmDNS) {
      return new LinkedList<>(boardPortsDiscoveredWithJmDNS);
    }
  }

  @Override
  public void start() throws IOException {
    this.networkCheckerTimer = new Timer(NetworkChecker.class.getName());
    new NetworkChecker(this, NetworkTopologyDiscovery.Factory.getInstance()).start(networkCheckerTimer);
    this.boardReachabilityFilterTimer = new Timer(BoardReachabilityFilter.class.getName());
    new BoardReachabilityFilter(this).start(boardReachabilityFilterTimer);
  }

  @Override
  public void stop() throws IOException {
    this.networkCheckerTimer.purge();
    this.boardReachabilityFilterTimer.purge();
    // we don't close each JmDNS instance as it's too slow
  }

  @Override
  public void serviceAdded(ServiceEvent serviceEvent) {
    String type = serviceEvent.getType();
    String name = serviceEvent.getName();

    JmDNS dns = serviceEvent.getDNS();

    dns.requestServiceInfo(type, name);
    ServiceInfo serviceInfo = dns.getServiceInfo(type, name);
    if (serviceInfo != null) {
      dns.requestServiceInfo(type, name);
    }
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
    int sleptFor = 0;
    while (BaseNoGui.packages == null && sleptFor <= MAX_TIME_AWAITING_FOR_PACKAGES) {
      try {
        Thread.sleep(1000);
        sleptFor += 1000;
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
        if (boardName != null) {
          label += " (" + boardName + ")";
        }
      } else if (description != null) {
        label += " (" + description + ")";
      }

      port.setAddress(address);
      port.setBoardName(name);
      port.setProtocol("network");
      port.setLabel(label);

      synchronized (boardPortsDiscoveredWithJmDNS) {
        removeDuplicateBoards(port);
        boardPortsDiscoveredWithJmDNS.add(port);
      }
    }
  }

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
  public void inetAddressAdded(InetAddress address) {
    if (mappedJmDNSs.containsKey(address)) {
      return;
    }
    try {
      JmDNS jmDNS = JmDNS.create(address);
      jmDNS.addServiceListener("_arduino._tcp.local.", this);
      mappedJmDNSs.put(address, jmDNS);
    } catch (Exception e) {
      e.printStackTrace();
    }
  }

  @Override
  public void inetAddressRemoved(InetAddress address) {
    JmDNS jmDNS = mappedJmDNSs.remove(address);
    IOUtils.closeQuietly(jmDNS);
  }
}
