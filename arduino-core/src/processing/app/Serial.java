/*
  PSerial - class for serial port goodness
  Part of the Processing project - http://processing.org

  Copyright (c) 2004 Ben Fry & Casey Reas

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General
  Public License along with this library; if not, write to the
  Free Software Foundation, Inc., 59 Temple Place, Suite 330,
  Boston, MA  02111-1307  USA
*/

package processing.app;

import static processing.app.I18n.format;
import static processing.app.I18n.tr;

import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PipedInputStream;
import java.io.PipedOutputStream;
import java.nio.charset.Charset;
import java.nio.charset.StandardCharsets;
import java.util.Arrays;
import java.util.List;

import jssc.SerialPort;
import jssc.SerialPortEvent;
import jssc.SerialPortEventListener;
import jssc.SerialPortException;

public class Serial implements SerialPortEventListener {

  //PApplet parent;

  // properties can be passed in for default values
  // otherwise defaults to 9600 N81

  // these could be made static, which might be a solution
  // for the classloading problem.. because if code ran again,
  // the static class would have an object that could be closed

  private SerialPort port;

  private PipedOutputStream decoderInRaw;
  private InputStreamReader decoderOutputUTF8;
  private final int DECODER_BUFF_SIZE = 16384;

  public Serial() throws SerialException {
    this(PreferencesData.get("serial.port"),
      PreferencesData.getInteger("serial.debug_rate", 9600),
      PreferencesData.getNonEmpty("serial.parity", "N").charAt(0),
      PreferencesData.getInteger("serial.databits", 8),
      PreferencesData.getFloat("serial.stopbits", 1),
      !BaseNoGui.getBoardPreferences().getBoolean("serial.disableRTS"),
      !BaseNoGui.getBoardPreferences().getBoolean("serial.disableDTR"));
  }

  public Serial(int irate) throws SerialException {
    this(PreferencesData.get("serial.port"), irate,
      PreferencesData.getNonEmpty("serial.parity", "N").charAt(0),
      PreferencesData.getInteger("serial.databits", 8),
      PreferencesData.getFloat("serial.stopbits", 1),
      !BaseNoGui.getBoardPreferences().getBoolean("serial.disableRTS"),
      !BaseNoGui.getBoardPreferences().getBoolean("serial.disableDTR"));
  }

  public Serial(String iname, int irate) throws SerialException {
    this(iname, irate, PreferencesData.getNonEmpty("serial.parity", "N").charAt(0),
      PreferencesData.getInteger("serial.databits", 8),
      PreferencesData.getFloat("serial.stopbits", 1),
      !BaseNoGui.getBoardPreferences().getBoolean("serial.disableRTS"),
      !BaseNoGui.getBoardPreferences().getBoolean("serial.disableDTR"));
  }

  public Serial(String iname) throws SerialException {
    this(iname, PreferencesData.getInteger("serial.debug_rate", 9600),
      PreferencesData.getNonEmpty("serial.parity", "N").charAt(0),
      PreferencesData.getInteger("serial.databits", 8),
      PreferencesData.getFloat("serial.stopbits", 1),
      !BaseNoGui.getBoardPreferences().getBoolean("serial.disableRTS"),
      !BaseNoGui.getBoardPreferences().getBoolean("serial.disableDTR"));
  }

  public static boolean touchForCDCReset(String iname) throws SerialException {
    SerialPort serialPort = new SerialPort(iname);
    try {
      serialPort.openPort();
      serialPort.setParams(1200, 8, SerialPort.STOPBITS_1, SerialPort.PARITY_NONE);
      serialPort.setDTR(false);
      serialPort.closePort();
      return true;
    } catch (SerialPortException e) {
      throw new SerialException(format(tr("Error touching serial port ''{0}''."), iname), e);
    } finally {
      if (serialPort.isOpened()) {
        try {
          serialPort.closePort();
        } catch (SerialPortException e) {
          // noop
        }
      }
    }
  }

  protected Serial(String iname, int irate, char iparity, int idatabits, float istopbits, boolean setRTS, boolean setDTR) throws SerialException {
    //if (port != null) port.close();
    //this.parent = parent;
    //parent.attach(this);

    resetDecoding(StandardCharsets.UTF_8);

    int parity = SerialPort.PARITY_NONE;
    if (iparity == 'E') parity = SerialPort.PARITY_EVEN;
    if (iparity == 'O') parity = SerialPort.PARITY_ODD;

    int stopbits = SerialPort.STOPBITS_1;
    if (istopbits == 1.5f) stopbits = SerialPort.STOPBITS_1_5;
    if (istopbits == 2) stopbits = SerialPort.STOPBITS_2;

    // This is required for unit-testing
    if (iname.equals("none")) {
      return;
    }

    try {
      port = new SerialPort(iname);
      port.openPort();
      boolean res = port.setParams(irate, idatabits, stopbits, parity, setRTS, setDTR);
      if (!res) {
        System.err.println(format(tr("Error while setting serial port parameters: {0} {1} {2} {3}"),
                                  irate, iparity, idatabits, istopbits));
      }
      port.addEventListener(this);
    } catch (SerialPortException e) {
      if (e.getPortName().startsWith("/dev") && SerialPortException.TYPE_PERMISSION_DENIED.equals(e.getExceptionType())) {
        throw new SerialException(format(tr("Error opening serial port ''{0}''. Try consulting the documentation at http://playground.arduino.cc/Linux/All#Permission"), iname));
      }
      throw new SerialException(format(tr("Error opening serial port ''{0}''."), iname), e);
    }

    if (port == null) {
      throw new SerialNotFoundException(format(tr("Serial port ''{0}'' not found. Did you select the right one from the Tools > Serial Port menu?"), iname));
    }
  }

  public void setup() {
    //parent.registerCall(this, DISPOSE);
  }

  public void dispose() throws IOException {
    if (port != null) {
      try {
        if (port.isOpened()) {
          port.closePort();  // close the port
        }
      } catch (SerialPortException e) {
        throw new IOException(e);
      } finally {
        port = null;
      }
    }
  }

  @Override
  public synchronized void serialEvent(SerialPortEvent serialEvent) {
    if (serialEvent.isRXCHAR()) {
      try {
        byte[] buf = port.readBytes(serialEvent.getEventValue());
        processSerialEvent(buf);
      } catch (SerialPortException e) {
        errorMessage("serialEvent", e);
      }
    }
  }

  public void processSerialEvent(byte[] buf) {
    int next = 0;
    int max = buf.length;
    char chars[] = new char[DECODER_BUFF_SIZE];
    try {
      while (next < max) {
        int w = Integer.min(max - next, chars.length);
        decoderInRaw.write(buf, next, w);
        next += w;
        int n = decoderOutputUTF8.read(chars);
        message(chars, n);
      }
    } catch (IOException e) {
      e.printStackTrace();
    }
  }

  /**
   * This method is intented to be extended to receive messages
   * coming from serial port.
   */
  protected void message(char[] chars, int length) {
    // Empty
  }


  /**
   * This will handle both ints, bytes and chars transparently.
   */
  public void write(int what) {  // will also cover char
    try {
      port.writeInt(what & 0xff);
    } catch (SerialPortException e) {
      errorMessage("write", e);
    }
  }


  public void write(byte bytes[]) {
    try {
      port.writeBytes(bytes);
    } catch (SerialPortException e) {
      errorMessage("write", e);
    }
  }


  /**
   * Write a String to the output. Note that this doesn't account
   * for Unicode (two bytes per char), nor will it send UTF8
   * characters.. It assumes that you mean to send a byte buffer
   * (most often the case for networking and serial i/o) and
   * will only use the bottom 8 bits of each char in the string.
   * (Meaning that internally it uses String.getBytes)
   * <p>
   * If you want to move Unicode data, you can first convert the
   * String to a byte stream in the representation of your choice
   * (i.e. UTF8 or two-byte Unicode data), and send it as a byte array.
   */
  public void write(String what) {
    write(what.getBytes());
  }

  public void setDTR(boolean state) {
    try {
      port.setDTR(state);
    } catch (SerialPortException e) {
      errorMessage("setDTR", e);
    }
  }

  public void setRTS(boolean state) {
    try {
      port.setRTS(state);
    } catch (SerialPortException e) {
      errorMessage("setRTS", e);
    }
  }

  /**
   * Reset the encoding used to convert the bytes coming in
   * before they are handed as Strings to {@Link #message(char[], int)}.
   */
  public synchronized void resetDecoding(Charset charset) {
    try {
      decoderInRaw = new PipedOutputStream();
      // add 16 extra bytes to make room for incomplete UTF-8 chars
      decoderOutputUTF8 = new InputStreamReader(new PipedInputStream(decoderInRaw, DECODER_BUFF_SIZE + 16), charset);
    } catch (IOException e) {
      // Should never happen...
      e.printStackTrace();
    }
  }

  static public List<String> list() {
    return Arrays.asList(SerialPortList.getPortNames());
  }


  /**
   * General error reporting, all corraled here just in case
   * I think of something slightly more intelligent to do.
   */
  private static void errorMessage(String where, Throwable e) {
    System.err.println(format(tr("Error inside Serial.{0}()"), where));
    e.printStackTrace();
  }
}
