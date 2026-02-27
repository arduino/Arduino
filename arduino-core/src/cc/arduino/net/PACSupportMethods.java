/*
 * This file is part of Arduino.
 *
 * Copyright 2015 Arduino LLC (http://www.arduino.cc/)
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
 */

package cc.arduino.net;

import edazdarevic.commons.net.CIDRUtils;
import org.apache.commons.net.util.SubnetUtils;

import java.net.InetAddress;
import java.net.NetworkInterface;
import java.net.SocketException;
import java.net.UnknownHostException;
import java.util.Collections;
import java.util.Optional;
import java.util.regex.Pattern;

public class PACSupportMethods {

  public boolean isPlainHostName(String host) {
    return !host.contains(".");
  }

  public boolean dnsDomainIs(String host, String domain) {
    return host.contains(domain);
  }

  public boolean localHostOrDomainIs(String host, String hostdom) {
    return hostdom.contains(host);
  }

  public boolean isResolvable(String host) {
    try {
      dnsResolve(host);
      return true;
    } catch (UnknownHostException e) {
      return false;
    }
  }

  public boolean isInNet(String host, String pattern, String mask) throws UnknownHostException {
    SubnetUtils subnetUtils = new SubnetUtils(pattern, mask);
    subnetUtils.setInclusiveHostCount(true);
    return new CIDRUtils(subnetUtils.getInfo().getCidrSignature()).isInRange(host);
  }

  public String dnsResolve(String host) throws UnknownHostException {
    return InetAddress.getByName(host).getHostAddress();
  }

  public String myIpAddress() throws SocketException {
    Optional<NetworkInterface> publicIface = Collections.list(NetworkInterface.getNetworkInterfaces()).stream()
      .filter((iface) -> {
        try {
          return !iface.isLoopback();
        } catch (SocketException e) {
          throw new RuntimeException(e);
        }
      })
      .filter((iface) -> iface.getInetAddresses().hasMoreElements())
      .findFirst();

    if (publicIface.isPresent()) {
      return publicIface.get().getInetAddresses().nextElement().getHostAddress();
    }

    return "127.0.0.1";
  }

  public int dnsDomainLevels(String host) {
    return host.split("\\.").length - 1;
  }

  public boolean shExpMatch(String str, String shexp) {
    String exp = shexp.replace("*", "");
    return Pattern.compile(exp).matcher(str).find();
  }

}
