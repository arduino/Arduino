/* -*- mode: jde; c-basic-offset: 2; indent-tabs-mode: nil -*- */

/*
  ZigBee.java - class for talking to an XBee running ZigBee firmware in a non-transparent way.
  Part of the Arduino project - http://www.arduino.cc/

  Copyright (c) 2012
  Ross Biro
  
  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software Foundation,
  Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
  
  $Id$
*/
package processing.app.debug;

import processing.app.Base;
import processing.app.Preferences;
import processing.app.Serial;
import processing.app.SerialException;
import processing.app.debug.ZigBeeException;
import processing.app.debug.MessageConsumer;

import java.util.*;
import java.lang.*;

public class ZigBee implements MessageConsumer {
  // The API Packet Types:
  public static final byte local_at_command = 0x08;
  public static final byte local_queue_at_command = 0x09;
  public static final byte zigbee_transmit_request = 0x10;
  public static final byte zigbee_explict_address_trasmit_request = 0x11;
  public static final byte remote_at_command = 0x17;
  public static final byte create_soruce_route = 0x21;
  public static final byte local_at_command_response = -0x78; // 0x88
  public static final byte modem_status = -0x76; // 0x8a
  public static final byte zigbee_transmit_status = -0x75; // 0x8B
  public static final byte zigbee_receive_packet = -0x70; // 0x90
  public static final byte zigbee_explicit_rx_indicator = -0x6F; // 0x91
  public static final byte zigbee_io_data_sample_rx_indicator = -0x6E; // 0x92
  public static final byte xbee_sensor_read_indicator = -0x6C; // 0x94
  public static final byte node_identification_indicator = -0x6B; // 0x95
  public static final byte remote_command_response = -0x69; // 0x97
  public static final byte over_the_air_firmware_update_status = -0x60; // 0xa0
  public static final byte route_record_indicator = -0x5f; // 0xa1
  public static final byte many_to_one_route_request_indicator = -0x5d; // 0xa3

  static final long bpsValues[] = {
    1200,
    2400,
    4800,
    9600,
    19200,
    38400,
    57600,
    115200
  };


  static long internalWait = 200;
  static long writeTimeout = 10000; // give it ten seconds to write.

  static Long connectedAddress = new Long(0); // who the local xbee is connected to.

  MessageConsumer consumer;

  static MessageConsumer staticConsumer = null;

  protected enum ZigBeeCommands {
    ND {
      void process(ZigBee zb, byte[] packet, int offset) {
        if (packet.length < offset + 11) {
          return;
        }
        short address16 = (short)bytesToNum(packet, offset, 2);
        long address64 = bytesToNum(packet, offset + 2, 8);
        zb = findOrCreateRemote(address64, address16);
        try {
          zb.updatePan(getLocal().getPan());
        } catch (Exception e) {
          // Ignore it, can't happen.
          e.printStackTrace();
        }

        // Byte 10 is the signal strength, at least in XBee's.
        if (packet.length < offset + 13) {
          return;
        }
        zb.updateNI(bytesToString(packet, offset + 11, 21));

        offset = offset + 11 + zb.getNI().length() + 1;
        // next is parent network address 2 bytes
        // zb.setDeviceType(bytesToNum(packet, offset+2, 1)); // router vs end node vs coordinator
        // next is status 1 byte (reserved)
        if (packet.length < offset + 6) {
          return;
        }
        zb.setProfileID((short)bytesToNum(packet, offset + 4, 2));

        if (packet.length < offset + 8) {
          return;
        }
        zb.setManufacturerID((short)bytesToNum(packet, offset + 6, 2));
      }
    }, 
    BD {
      void process(ZigBee zb, byte[] packet, int offset)  {
        int ind = (int)bytesToNum(packet, offset, 8, packet.length - 1);
        if (ind < bpsValues.length) {
          zb.updateBps(bpsValues[ind]);
        } else {
          zb.updateBps(ind);
        }
      }
    },
    AP {
      void process(ZigBee zb, byte[] packet, int offset)  {
        // Nothing to do.  Don't query AP.
      }
    },
    NB {
      void process(ZigBee zb, byte[] packet, int offset)  {
      char b = (char)bytesToNum(packet, offset, 1, packet.length - 1);
      switch (b) {
      default:
      case 0:
        b = 'N';
        break;

      case 1:
        b = 'E';
        break;

      case 2:
        b = 'O';
        break;

      case 3:
        b = 'M';
        break;
      }
      zb.updateParity(b);
      }
    },
    SL {
        void process(ZigBee zb, byte[] packet, int offset)  {
          zb.setSL((int)bytesToNum(packet, offset, 4, packet.length - 1));
        }
      },
    SH {
      void process(ZigBee zb, byte[] packet, int offset)  {
        zb.setSH((int)bytesToNum(packet, offset, 4, packet.length - 1));
      }
    },
    DL {
      void process(ZigBee zb, byte[] packet, int offset) {
        if (zb != getLocalNoCreate()) {
          return;
        }
        zb.setDL((int)bytesToNum(packet, offset, 4, packet.length -1));
      }
    },
    DH {
      void process(ZigBee zb, byte[] packet, int offset) {
        if (zb != getLocalNoCreate()) {
          return;
        }
        zb.setDH((int)bytesToNum(packet, offset, 4, packet.length -1));
      }
    },
    NI {
      public boolean responseString = true;
      void process(ZigBee zb, byte[] packet, int offset) {
        zb.updateNI(bytesToString(packet, offset, Math.min(20, packet.length - offset - 1)));
      }
    },
    MY {
      void process(ZigBee zb, byte[] packet, int offset) {
        zb.updateAddress16((short)bytesToNum(packet, offset, 2, packet.length - 1));
      }
    },
    AC {
      void process(ZigBee zb, byte[] packet, int offset) {
        // nothing to do.
      }
    },
    ID {
      void process(ZigBee zb, byte[] packet, int offset) {
        zb.updatePan(new Long(bytesToNum(packet, offset, 4, packet.length - 1)));
      }
    };
    abstract void process(ZigBee zb, byte[] packet, int offset);
    public boolean responseString = false;
  }

  int sl;
  int sh;

  boolean slGood = false;
  boolean shGood = false;

  String nodeID; //limited to 20 characters
  Long serialNumber; // 64 bit address/serial number of node 
  Short newAddress; // 16 bit address of the node, not yet applied.
  Short address; // 16 bit address of the node

  Long newPan;  // new network of the node, not yet applied.
  Long pan;	// network of the node.

  Short profileID;  // These two identify the hardware
  Short manufacturerID; 
  long bps; // need this to make sure the remote end matches what the board expects.
  char parity; // 'E', 'O', or N;

  byte currentId = 0; // used to give each packet a new id.

  static Serial serialPort;

  String incoming;

  boolean apiMode=false;

  class Command {
    public ZigBeeCommands command;
    public boolean set;
    public Date issued;
    public boolean broadcast;
    public Object status;
    public Object response;
    public Object argument;
    public String commandString;
    public int retransmits;
    public int maxRetransmits;

    public Command() {
      retransmits = 0;
      maxRetransmits = 3;
    }

  };

  Map<Byte, Command> outstandingCommands;

  static final Object getLocalLock = new Object(); 

  static Map<Long, ZigBee> knownNodes = new HashMap<Long, ZigBee>(); // map serial_number -> XBee class.
  static ZigBee local; // The local node.  While there can be more than one.  We only deal with one at a time.

  public static void onPortChanged() {
    close();
    synchronized(knownNodes) {
      knownNodes.clear();
    }
    connectedAddress = new Long(0);
    synchronized (getLocalLock) {
      local = null;
    }
  }
    
  public static void searchForNodes() throws ZigBeeException, SerialException {
    ZigBee l = getLocal();
    l.executeCommand("ND", null, 0);
    // Nodes will automatically be populated as responses come in.
  }

  public static void searchForNodesWait() throws ZigBeeException, SerialException {
    ZigBee l = getLocal();
    l.executeCommand("ND", null, 5000);
  }

  public static ZigBee[] getNodes() {
    synchronized(knownNodes) {
      ZigBee[] z = new ZigBee[1];
      return knownNodes.values().toArray(z);
    }
  }

  public static ZigBee getConnected() throws ZigBeeException, SerialException {
    if (getNodes().length < 2) {
      searchForNodesWait();
    }

    ZigBee zb = findRemote(connectedAddress);
    if (zb == null) {
      throw new ZigBeeException ("Unable to find any remote nodes.");
    }

    return zb;
  }

  static ZigBee getLocalNoCreate() {
    synchronized(getLocalLock) {
      return local;
    }
  }

  public static void close() {
    ZigBee zb = getLocalNoCreate();
    if (zb != null) {
      try {
        zb.exitAPIMode();
        zb.closeSerial();
      } catch (Exception e) {};
    }
  }

  void closeSerial() {
    if (serialPort != null) {
      serialPort.addListener(null);
      serialPort.dispose();
      serialPort = null;
    }
  }

  static byte[] getBytes(String s) {
    byte[] b = new byte[s.length()];
    for (int i = 0; i < s.length(); ++i) {
      b[i] = (byte)s.charAt(i);
    }
    return b;
  }

  public static ZigBee getLocal() throws ZigBeeException, SerialException {
    synchronized(getLocalLock) {
      if (local != null) {
        if (serialPort == null) {
          serialPort = new Serial();
          if (local.apiMode) {
            serialPort.addListener(local);
          }
        }       
        return local;
      }

 
      try {
        ZigBee l = new ZigBee();
        local = l; // must do this first, otherwise isLocal fails.
        // l isn't really complete yet, but it's good enough for 
        // local communications.
        l.enterAPIMode();
        // Just queue up these commands and let the incoming 
        // api message processor deal with the results.
        l.executeCommand("SL", null, internalWait);
        l.executeCommand("SH", null, internalWait);
        l.executeCommand("NI", null, internalWait);
        l.executeCommand("MY", null, internalWait);
        l.executeCommand("ID", null, internalWait);
        l.executeCommand("DL", null, internalWait);
        l.executeCommand("DH", null, internalWait);

        // Can't get profile id and manufacturer_id with out doing a loop back node id.
        l.bps = Long.parseLong(Preferences.get("serial.debug_rate"));
        l.parity = Preferences.get("serial.parity").charAt(0);
        return l;
      } catch (Exception e) {
        close();
        local = null;
        e.printStackTrace();
        if (e instanceof ZigBeeException) {
          throw (ZigBeeException)e;
        } else if (e instanceof SerialException) {
          throw (SerialException)e;
        }
        throw new ZigBeeException(e.getMessage());
      }
    }
  }

  protected ZigBee() {
    consumer = null;
    incoming = null;
    outstandingCommands = new HashMap<Byte, Command>();
  }

  boolean isLocal()  {
    if (getLocalNoCreate() == this) {
      return true;
    } else {
      return false;
    }
  }

  void setDL(int l) {
    connectedAddress = new Long((connectedAddress.longValue() & ~0xFFFFFFFF) | l);
    sendMessage("DL");
    sendStaticMessage("DL");
  }

  void setDH(int l) {
    connectedAddress = new Long ((connectedAddress.longValue() & 0xFFFFFFFF) | ((long) l << 32));
    sendMessage("DH");
    sendStaticMessage("DH");
  }

  void updateNI(String s) {
    nodeID = s;
    sendMessage("NI");
    sendStaticMessage("NI"); // things use the name as part of the UI.
  }

  public void setNI(String s) throws ZigBeeException, SerialException {
    executeCommand("NI", s, internalWait);
    nodeID = s;
  }

  public String getNI() {
    return nodeID;
  }

  void setProfileID(short p) {
    profileID = p;
    sendMessage("PID");
  }

  void setManufacturerID(short m) {
    manufacturerID = m;
    sendMessage("MID");
  }

  void setSL(int s) {
    sl = s;
    slGood = true;
    if (slGood && shGood) {
      updateSerialNumberFromSLandSH();
    }
  }

  void setSH(int s) {
    sh = s;
    shGood = true;
    if (slGood && shGood) {
      updateSerialNumberFromSLandSH();
    }
  }

  public Long getSerialNumber() {
    return serialNumber;
  }

  public Short getAddress() {
    return address;
  }

  public void setAddress(Short i) throws SerialException, ZigBeeException {
    newAddress = i;
    executeCommand("MY", i, internalWait);
  }

  public Long getPan() {
    return pan;
  }

  void updatePan(Long i) {
    pan = i;
    newPan = null;
    sendMessage("PAN");
  }

  public void setPan(Long i) throws SerialException, ZigBeeException {
    newPan = i;
    executeCommand("ID", i, internalWait);
  }

  void updateBps(long b) {
    bps = b;
    sendMessage("BPS");
  }

  public void setBps(long b) throws ZigBeeException, SerialException {
    bps = b;
    for (int i = 0; i < bpsValues.length; ++i) {
      if (bpsValues[i] == b) {
        b = i;
        break;
      }
    }
    executeCommand("BD", b, internalWait);
  }

  public void updateParity(char e) {
    parity = e;
    sendMessage("PARITY");
  }

  public void setParity(char e) throws ZigBeeException, SerialException {
    parity = e;
    byte arg;
    switch (e) {
    case 'N':
    default:
      arg = 0;
      break;

    case 'E':
      arg = 1;
      break;

    case 'O':
      arg = 2;
      break;

    case 'M':
      arg = 3;
      break;
    }

    executeCommand("NB", new Byte(arg), internalWait);
  }


  public Short getProfileId() {
    return profileID;
  }

  public Short getManufacturerId() {
    return manufacturerID;
  }

  public long getBps() {
    return bps;
  }

  public char getParity() {
    return parity;
  }

  public void updateSerialParameters() throws ZigBeeException, SerialException {
    executeCommand("NB", null, internalWait);
    executeCommand("BD", null, internalWait);
  }

  void updateSerialNumberFromSLandSH() {
    synchronized(this) {
      if (!slGood || !shGood) {
        return;
      }
      slGood = false;
      shGood = false;
      updateAddress64((long)sh << 32 | (long)sl);
    }
  }

  static protected int byteToInt(byte b) {
    return (b >= 0?b:256+b);
  }

  static protected long bytesToNum(byte[] p, int o) {
    return bytesToNum(p, o, 8);
  }


  static protected String bytesToString(byte[] p, int o, int maxlen) {
    for (int i = 0; i < maxlen && i < p.length - o - 1; ++i) {
      if (p[i+o] == 0) {
        return new String(p, o, i);
      }
    }
    return new String(p, o, (p.length - o <  maxlen) ? (p.length - o) : maxlen);
  }

  static protected long bytesToNum(byte[] p, int o, int maxLen) {
    return bytesToNum(p, o, maxLen, p.length);
  }

  static protected long bytesToNum(byte[] p, int o, int maxLen, int bufflen) {
    long val = 0;
    for (int i = 0; i < maxLen && i + o < bufflen; ++i) {
      val = (val << 8) + byteToInt(p[i+o]);
    }
    return val;
  }

  /// XXXX Fixme, we might need this at some point.
  public Object waitForResponse(Command c, long timeout) {
    try {
      synchronized(c) {
        c.wait(timeout);
      }
    } catch (InterruptedException ie) {
      // ignore it.
    }
    return c.response;
  }

  public Object executeRemoteCommand(Command c, String command, Object argument, long wait) throws ZigBeeException, SerialException {
    //Don't need to be in API mode to execute remote commands.  
    byte[] packet = buildRemoteCommand(c, remote_at_command, command, argument);
    ZigBee zb = getLocal();
    return zb.sendRemote(c, packet, wait);
  }

  public Object executeCommand(String command, Object argument, long wait) throws ZigBeeException, SerialException {
    command = command.toUpperCase();
    Command c = new Command();
    try {
      c.command = ZigBeeCommands.valueOf(command);
    } catch (IllegalArgumentException iae) {
      c.command = null;
    }
    c.commandString = command;
    c.set = (argument != null);
    c.issued = new Date();
    c.broadcast = (c.command == ZigBeeCommands.NI);
    c.argument = argument;

    return executeCommand(c, wait);
  }

  public Object executeCommand(Command c, long wait) throws ZigBeeException, SerialException {
    String command = c.commandString;
    Object argument = c.argument;

    ZigBee local = getLocalNoCreate();
    local.enterAPIMode();

    if (local == this) {
      return executeLocalCommand(c, command, argument, wait);
    } else {
      return executeRemoteCommand(c, command, argument, wait);
    }
  }

  // only works locally.
  void enterCommandMode() throws ZigBeeException, SerialException {
    if (serialPort == null) {
      serialPort = new Serial();
    }
    try {
      Thread.sleep(1000);
    } catch (InterruptedException e) {}

    serialPort.addListener(null);

    String s = new String ("+++");
    serialPort.write(s);

    do {
      s = serialPort.waitForData(1500);

      if (s != null) {
        if (s.indexOf("OK") >= 0) {
          return;
        }
      }
    } while (s != null);

    close();
    throw new ZigBeeException("Unable to enter command mode.");
  }

  // only works locally.
  public void exitCommandMode() throws ZigBeeException, SerialException {
    serialPort.write("ATCN\r\n");
    serialPort.waitForData(internalWait);
  }

  // should work remotely, but probably a bad idea.
  public void enterAPIMode() throws ZigBeeException, SerialException {
    if (apiMode) {
      return;
    }

    // can't do this locally since we use API mode to execute the command.
    if (!isLocal()) {
      executeCommand("AP", new Integer(1), internalWait);
    } else {
      enterCommandMode();
      serialPort.write("ATAP1\r\n");
      serialPort.waitForData(internalWait);
      exitCommandMode();
      serialPort.addListener(this);
      apiMode = true;
    }
  }

  public void exitAPIMode() throws ZigBeeException, SerialException {
    if (!apiMode) {
      return;
    }
    executeCommand("AP", new Integer(0), internalWait);
    serialPort.addListener(null);
    serialPort.dispose();
    serialPort = null;
    apiMode = false;
  }

  // returns the argument length in bytes.
  protected int getArgumentLength(Object argument) throws ZigBeeException {
    int arglen;
    if (argument == null) {
      return 0;
    } else if (argument instanceof java.lang.Number) {
      arglen = 0;
      long num=((Number)argument).longValue();
      do {
        arglen++;
        num = num >>> 8;
      } while (num != 0);
      return arglen;
    } else if (argument instanceof String) {
      arglen = ((String)argument).length();
    } else {
      throw new ZigBeeException("Invalid argument type.");
    }
    return arglen;
  }

  // Get around java's lack of unsigned types.
  // and return the lower byte of the int bitwise.
  static protected byte intToByte(int n) {
    if ((n & 0xFF) >= 0x80) {
      n = n & 0xFF;
      n = 0x100 - n;
      return (byte)-n;
    } else {
      return (byte)(n & 0x7f);
    }
  }

  void computeChecksum(byte[] packet) {
    int offset = packet.length - 1;
    int cksum = 0;
    for (int i = 3; i < offset; ++i) {
      cksum = cksum + byteToInt(packet[i]);
    }
    packet[offset] = (byte)(-1 - cksum);
  }

  void putAddress64(byte[] packet, int offset, long address64) {
    for (int i = 0; i < 8; ++i) {
      packet[offset + i] = (byte)(address64 >> (56 - i*8));
    }
  }

  void putAddress16(byte[] packet, int offset, short address16) {
    for (int i = 0; i < 2; ++i) {
      packet[offset + i] = (byte)(address16 >> (8 - i*8));
    }
  }

  void putArgumentBytes(byte[] packet, int offset, Object argument) {
    if (argument == null) {
      return;
    } else if (argument instanceof Number) {
      long num=((Number)argument).longValue();
      if (num == 0) {
        packet[offset] = 0;
        return;
      }
      
      boolean started = false;
      for (int i = 0; i < 8; ++i) {
        int sign = num >= 0?1:-1;
        if ((num >>> 56) != 0 || started) {
          started = true;
          packet[offset] = (byte) ((num >>> 56) & 0x7f);
          if (sign < 0) {
            packet[offset] |= (byte)0x80;
          }
          offset ++;
        }
        num = num << 8;
      }
    } else if (argument instanceof String) {
      byte [] bytes = getBytes((String)argument);
      for (int i = 0; i < bytes.length; ++i) {
        packet[offset + i] = bytes[i];
      }
    }
  }

  // Doesn't check the argument is appropriate for the command.
  // Using Number won't handle -0 properly.
  // Also won't handle packets longer than 32k properly.
  public byte[] buildRemoteCommand(Command c, byte api, String command, Object argument) throws ZigBeeException {
    synchronized(this) { // don't want something to change while we are building the command.
      int length = getArgumentLength(argument) + 17 + command.length(); // Address is 10 bytes
      byte [] packet = new byte[length];
      packet[0] = 0x7e;
      packet[1] = intToByte((length-4) >> 8);
      packet[2] = intToByte(length-4);
      packet[3] = api;
      packet[4] = ++currentId;
      synchronized(outstandingCommands) {
        outstandingCommands.put(currentId, c);
      }

      if (currentId == -1) {
        // never assing id 0 to a packet. it means no id.
        currentId = 0;
      }
      putAddress64(packet, 5, serialNumber);
      if (address == null) {
        putAddress16(packet, 13, (short)-2);
      } else {
        putAddress16(packet, 13, address);
      }

      if (c.command == ZigBeeCommands.AC) {
        packet[15] = 0x2; // apply changes.
      } else {
        packet[15] = 0x0;
      }

      for (int i = 0; i < command.length(); ++i) {
        packet[16+i] = (byte)command.charAt(i);
      }

      putArgumentBytes(packet, 16+command.length(), argument);
      computeChecksum(packet);
      return packet;
    }
  }

  // Doesn't check the argument is appropriate for the command.
  // Using Number won't handle -0 properly.
  // Also won't handle packets longer than 32k properly.
  public byte[] buildLocalCommand(Command c, byte api, String command, Object argument) throws ZigBeeException {
    int length = getArgumentLength(argument) + 6 + command.length();
    byte [] packet = new byte[length];
    packet[0] = 0x7e;
    packet[1] = intToByte((length-4) >> 8);
    packet[2] = intToByte(length-4);
    packet[3] = api;
    packet[4] = ++currentId;
    synchronized(outstandingCommands) {
      outstandingCommands.put(currentId, c);
    }

    for (int i = 0; i < command.length(); ++i) {
      packet[5+i] = (byte)command.charAt(i);
    }
    putArgumentBytes(packet, 5+command.length(), argument);
    computeChecksum(packet);
    return packet;
  }

  public void sendCommand(byte[] command) throws SerialException {
    serialPort.write(command);
  }

  public Object sendRemote(Command c, byte[] command, long wait) throws SerialException {
    sendCommand(command);
    if (wait == 0) {
      return null;
    }
    return waitForResponse(c, wait);
  }

  public Object executeLocalCommand(Command c, String command, Object argument, long wait) throws ZigBeeException, SerialException {
    byte[] packet = buildLocalCommand(c, local_at_command, command, argument);

    sendCommand(packet);

    if (wait==0) {
      return null;
    }

    return waitForResponse(c, wait);
  }

  void sendMessage(String s) {
    if (consumer != null) {
      consumer.message(s);
    }
  }
 
  void sendStaticMessage(String s) {
    if (staticConsumer != null) {
      staticConsumer.message(s);
    }
  }

  public void addListener(MessageConsumer c) {
    consumer = c;
  }

  public static void addStaticListener(MessageConsumer consumer) {
    staticConsumer = consumer;
  }

  // part of the PdeMessageConsumer interface
  //
  public void message(String s) {
    while (s != null && s.length() > 0) {
      if (incoming == null) {
        int start=s.indexOf(0x7e, 0);
        if (start < 0) {
          return;
        }
        incoming = s.substring(start, 1);
        s = s.substring(start+1);
        continue;
      }
      // see if we have enough to get a packet length yet.
      int need;
      if (incoming.length() < 3) {
        need = 3 - incoming.length();
      } else {
        int len = (int)bytesToNum(getBytes(incoming), 1, 2);
        need = (len + 4) - incoming.length();
      }
      if (need <= s.length()) {
        incoming = incoming + s.substring(0, need);
        s = s.substring(need);
        if (incoming.length() == 3) {
          continue;
        }
        try {
          processIncomingPacket(incoming);
        } catch (Exception e) {
          e.printStackTrace();
        }
        incoming = null;
      } else {
        incoming = incoming + s; 
        s = null;
      }
    }
  }

  public void processIncomingPacket(String s) throws ZigBeeException, SerialException {
    if (s.charAt(0) != 0x7e) {
      return; // bogus packet.
    }

    byte[] packet = new byte[s.length()];
    String o = "ProcessIncomingPacket[" + packet.length +"] =";
    for (int i = 0; i < s.length(); ++i) {
      packet[i] = (byte)s.charAt(i);
      o = o + " 0x" + Integer.toHexString(s.charAt(i));
    }
    byte cksum = packet[packet.length - 1];
    computeChecksum(packet);
    if (cksum != packet[packet.length - 1]) {
      return ; // bogus packet
    }

    // Setup Defaults for the local packet.
    ZigBee zb = this;
    int offset=5;

    switch (packet[3]) {
    case remote_command_response:
      zb = findOrCreateRemote(longAddressFromPacket(packet, 5), shortAddressFromPacket(packet, 13));
      offset = 15; // fall through
    case local_at_command_response:
      zb.processCommandResponse(packet, offset);
      return;
    default:
      // Ignore packets we don't know what to do with.  It's in the spec.
      return;
    }
  }

  static long longAddressFromPacket(byte[] packet, int o) {
    long addr = bytesToNum(packet, o, 8);
    return addr;
  }

  static short shortAddressFromPacket(byte[] packet, int o) {
    short addr = (short)bytesToNum(packet, o, 2);
    return addr;
  }

  void updateAddress64(long address64) {
    synchronized(this) {
      if (serialNumber != null && serialNumber.longValue() == address64) {
        return;
      }

      if (serialNumber != null) {
        knownNodes.remove(serialNumber);
      }

      if (address64 != -1 && address64 != 0) {
        serialNumber = new Long(address64);
        knownNodes.put(serialNumber, this);
        sendMessage("SERIALNO");
        sendStaticMessage("SERIALNO");
      }
    }
  }

  void updateAddress16(short address16) {
    synchronized(this) {
      if (address != null && address16 == address.shortValue()) {
        return;
      }
      if (address16 == -2) {
        address = null;
      } else {
        address = new Short(address16);
        newAddress = null;
        sendMessage("ADDRESS");
      }
    }
  }

  public static ZigBee findRemote(long address64) {
    ZigBee zb;
    synchronized(knownNodes) {
      zb = knownNodes.get(new Long(address64));
    }
    return zb;
  }

  static ZigBee findOrCreateRemote(long address64, short address16) {
    ZigBee zb;
    synchronized(knownNodes) {
      zb = knownNodes.get(new Long(address64));

      if (zb == null) {
        zb = new ZigBee();
        zb.updateAddress64(address64);
      }
    }
    zb.updateAddress16(address16);
    return zb;
  }

  void processCommandResponse(byte[] packet, int offset) throws ZigBeeException, SerialException {
    String command = new String(packet, offset, 2); // commands are all 2 characters.
    Command c;
    synchronized(outstandingCommands) {
      c = outstandingCommands.get(packet[4]);
    }
    if (c == null) {
      System.err.println("Command " + command + " command already timed out or not issued.");
    } else {
      if (c.command != ZigBeeCommands.ND || packet.length == 9) {
        c.status = new Byte(packet[offset + 2]);
        synchronized(outstandingCommands) {
          outstandingCommands.values().remove(c);
        }
      } else {
        c = null;
      }
    }

    if (packet[offset+2] != 0) {
      // Need to get the message to the user.
      if (c != null && packet[offset + 2] == 4) {
        if (c.retransmits++ < c.maxRetransmits) {
          executeCommand(c, 0);
          return;
        }
      }
      if (c != null) {
        synchronized(c) {
          c.notifyAll();
        }
      }
      return;
    }
    

    // Did we get some data back as well?
    if (packet.length > offset + 4) {
      command = command.toUpperCase();
      ZigBeeCommands zbc;
      try {
        zbc = ZigBeeCommands.valueOf(command);
        if (c != null) {
          if (zbc.responseString) {
            c.response = bytesToString(packet, offset+3, packet.length - offset - 1);
          } else {
            c.response = new Long(bytesToNum(packet, offset+3, 8, packet.length - 1));
          }
        }
        zbc.process(this, packet, offset+3);
      } catch (IllegalArgumentException iae) {
        if (c != null) {
          c.response = new Long(bytesToNum(packet, offset+3, 8, packet.length - 1));
        }
        // unhandled message, just ignore it.
      }
    }

    // let any waiters know we are done.
    if (c != null) {
      synchronized(c) {
        c.notifyAll();
      }
    }
  }

  public void apply() throws ZigBeeException, SerialException {
    executeCommand("AC", null, internalWait);
    if (newAddress != null) {
      address = newAddress;
      newAddress = null;
    }

    if (newPan != null) {
      pan = newPan;
      newPan = null;
    }
  }

  public void connect() throws ZigBeeException, SerialException {
    ZigBee zb = getLocal();
    zb.connectToRemote(this);
  }

  public void disconnect() {
    connectedAddress = new Long(0);
    sendStaticMessage("DL");
  }

  void connectToRemote(ZigBee remote) throws ZigBeeException, SerialException {
    long remoteAddress = remote.getSerialNumber();
    int remoteLow = (int)remoteAddress;
    int remoteHigh = (int)(remoteAddress >>> 32);
    executeCommand("DL", new Integer(remoteLow), internalWait);
    executeCommand("DH", new Integer(remoteHigh), internalWait);
    connectedAddress = remoteAddress;
    sendStaticMessage("DL");
  }

  public boolean isConnected() {
    if (getSerialNumber().longValue() == connectedAddress.longValue()) {
      return true;
    }
    return false;
  }

  public String toString() {
    String s;
    if (nodeID != null && nodeID.length() > 0) {
      s = nodeID + " -- " + Long.toString(getSerialNumber(), 16);
    } else {
      s = Long.toString(getSerialNumber(), 16);
    }

    if (isConnected()) {
      s = "Connected " + s;
    }
    return s;
  }

  public void write() throws ZigBeeException, SerialException {
    executeCommand("WR", null, writeTimeout);
  }

  public String getPrefPrefix() {
    return ZigBee.getPrefPrefix(getSerialNumber());
  }

  public static String getPrefPrefix(long number) {
    return "XBee."+Long.toString(number, 16);
  }

}