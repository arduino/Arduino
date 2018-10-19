package cc.arduino.packages.ssh;

import cc.arduino.packages.BoardPort;

abstract public class SSHSetup implements SSHClientSetupChainRing {
  @Override
  public String getIpAddress(BoardPort boardPort) {
    String[] address = boardPort.getAddress().split(":");

    return address[0];
  }

  @Override
  public Integer getPortNumber(BoardPort boardPort) {
    String[] address = boardPort.getAddress().split(":");

    if (address.length > 1 && address[1] != null) {
      return Integer.valueOf(address[1]);
    }

    return 22;
  }
}
