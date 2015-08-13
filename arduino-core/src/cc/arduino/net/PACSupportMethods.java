package cc.arduino.net;

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

  public boolean isInNet(String host, String pattern, String mask) {
    SubnetUtils subnetUtils = new SubnetUtils(pattern, mask);
    subnetUtils.setInclusiveHostCount(true);
    return subnetUtils.getInfo().isInRange(host);
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
