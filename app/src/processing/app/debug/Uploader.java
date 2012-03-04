/* -*- mode: jde; c-basic-offset: 2; indent-tabs-mode: nil -*- */

/*
  Uploader - abstract uploading baseclass (common to both uisp and avrdude)
  Part of the Arduino project - http://www.arduino.cc/

  Copyright (c) 2004-05
  Hernando Barragan

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
import processing.app.SerialNotFoundException;
import processing.app.I18n;
import static processing.app.I18n._;

import java.io.*;
import java.util.*;
import java.util.zip.*;
import javax.swing.*;
//#ifndef RXTX
//import javax.comm.*;
//#else
// rxtx uses package gnu.io, but all the class names
// are the same as those used by javax.comm
import gnu.io.*;
//#endif


public abstract class Uploader implements MessageConsumer  {
  static final String BUGS_URL =
    _("https://developer.berlios.de/bugs/?group_id=3590");
  static final String SUPER_BADNESS =
    I18n.format(_("Compiler error, please submit this code to {0}"), BUGS_URL);

  RunnerException exception;
  //PdePreferences preferences;

  //Serial serialPort;
  static InputStream serialInput;
  static OutputStream serialOutput;
  //int serial; // last byte of data received
  
  boolean verbose;

  //                             0      1    2     3     4     5      6    7     8      9    A      B     C     D    E     F 
  static char[] remoteD3High = {0x7e, 0x00, 0x00, 0x17, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 
                                'D', '3', 0x05, 0x00};
  static char[] remoteD3Low =  {0x7e, 0x00, 0x00, 0x17, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 
                                'D', '3', 0x04, 0x00};
  static char[] exitAPIMode =  {0x7e, 0x00, 0x00, 0x08, 0x03, 'A', 'P', 0x00, 0x00};
      

  public Uploader() {
  }

  public abstract boolean uploadUsingPreferences(String buildPath, String className, boolean usingProgrammer)
    throws RunnerException, SerialException;
  
  public abstract boolean burnBootloader() throws RunnerException;
  String computeZigBeeChecksum(char[] data) {
    char length = (char)(data.length - 4);
    if (length < 5) {
      return null;
    }
    data[1] = (char) ((length >> 8) & 0xff);
    data[2] = (char) (length & 0xff);

    char csum = 0;
    for (int i = 3; i < data.length - 1; ++i) {
      csum = (char)(csum + data[i]);
    }
    csum = (char)(0xff - (csum & 0xFF));
    data[data.length - 1] = csum;

    String s = new String();
    for (int i = 0; i <data.length; ++i) {
      s = s+" 0x"+Integer.toHexString(data[i]);
    }
    
    System.out.println("XBee Sending: " + s);

    return new String(data);
  }

  String waitForResponse(Serial s) throws SerialException {
    return waitForResponse(s, 2000);
  }

  String waitForResponse(Serial s, long time) throws SerialException {
      for (int i = 0; i < time/10; ++i ) {
        try {
          Thread.sleep(10);
        } catch (InterruptedException e) {}

        while (s.available() > 0) {
          String str;
          str = s.readString();
          System.out.println("XBee Response: " + str);
          if (s.available() == 0)
            return str;
        }
      }
      return null;
  }

  protected void executeZigBeeD3Reset() throws RunnerException, SerialException {
    try {
      Serial serialPort = new Serial(true);
      serialPort.addListener(null);

      serialPort.setDTR(true);
      serialPort.setRTS(true);

      try {
        Thread.sleep(1000);
      } catch (InterruptedException e) {}

      String s = new String ("+++");
      serialPort.write(s);

      s = waitForResponse(serialPort);
      // Enter 
      serialPort.write("ATAP1\r\n");
      s = waitForResponse(serialPort);

      serialPort.write("ATID\r\n");
      s = waitForResponse(serialPort);

      serialPort.write("ATCN\r\n");
      s = waitForResponse(serialPort);
      
      serialPort.write(computeZigBeeChecksum(remoteD3Low));
      s = waitForResponse(serialPort);

      try {
        Thread.sleep(1000);
      } catch (InterruptedException e) {}

      serialPort.write(computeZigBeeChecksum(remoteD3High));
      s = waitForResponse(serialPort);

      try {
        Thread.sleep(1000);
      } catch (InterruptedException e) {}

      serialPort.write(computeZigBeeChecksum(remoteD3Low));
      s = waitForResponse(serialPort);

      serialPort.write(computeZigBeeChecksum(exitAPIMode));
      s = waitForResponse(serialPort);

      serialPort.dispose();
    } catch (SerialNotFoundException e) {
      throw e;
    } catch(Exception e) {
      e.printStackTrace();
      throw new RunnerException(e.getMessage());
    }
  }

  
  protected void flushSerialBuffer() throws RunnerException, SerialException {
    // Cleanup the serial buffer
    try {
      Serial serialPort = new Serial();
      serialPort.addListener(null);
      byte[] readBuffer;
      while(serialPort.available() > 0) {
        readBuffer = serialPort.readBytes();
        try {
          Thread.sleep(100);
        } catch (InterruptedException e) {}
      }

      serialPort.setDTR(false);
      serialPort.setRTS(false);

      try {
        Thread.sleep(100);
      } catch (InterruptedException e) {}

      serialPort.setDTR(true);
      serialPort.setRTS(true);
      
      serialPort.dispose();
    } catch (SerialNotFoundException e) {
      throw e;
    } catch(Exception e) {
      e.printStackTrace();
      throw new RunnerException(e.getMessage());
    }
  }

  protected boolean executeUploadCommand(Collection commandDownloader) 
    throws RunnerException
  {
    firstErrorFound = false;  // haven't found any errors yet
    secondErrorFound = false;
    notFoundError = false;
    int result=0; // pre-initialized to quiet a bogus warning from jikes
    
    String userdir = System.getProperty("user.dir") + File.separator;

    try {
      String[] commandArray = new String[commandDownloader.size()];
      commandDownloader.toArray(commandArray);
      
      if (verbose || Preferences.getBoolean("upload.verbose")) {
        for(int i = 0; i < commandArray.length; i++) {
          System.out.print(commandArray[i] + " ");
        }
        System.out.println();
      }
      Process process = Runtime.getRuntime().exec(commandArray);
      new MessageSiphon(process.getInputStream(), this);
      new MessageSiphon(process.getErrorStream(), this);

      // wait for the process to finish.  if interrupted
      // before waitFor returns, continue waiting
      //
      boolean compiling = true;
      while (compiling) {
        try {
          result = process.waitFor();
          compiling = false;
        } catch (InterruptedException intExc) {
        }
      } 
      if(exception!=null) {
        exception.hideStackTrace();
        throw exception;   
      }
      if(result!=0)
        return false;
    } catch (Exception e) {
      String msg = e.getMessage();
      if ((msg != null) && (msg.indexOf("uisp: not found") != -1) && (msg.indexOf("avrdude: not found") != -1)) {
        //System.err.println("uisp is missing");
        //JOptionPane.showMessageDialog(editor.base,
        //                              "Could not find the compiler.\n" +
        //                              "uisp is missing from your PATH,\n" +
        //                              "see readme.txt for help.",
        //                              "Compiler error",
        //                              JOptionPane.ERROR_MESSAGE);
        return false;
      } else {
        e.printStackTrace();
        result = -1;
      }
    }
    //System.out.println("result2 is "+result);
    // if the result isn't a known, expected value it means that something
    // is fairly wrong, one possibility is that jikes has crashed.
    //
    if (exception != null) throw exception;

    if ((result != 0) && (result != 1 )) {
      exception = new RunnerException(SUPER_BADNESS);
      //editor.error(exception);
      //PdeBase.openURL(BUGS_URL);
      //throw new PdeException(SUPER_BADNESS);
    }

    return (result == 0); // ? true : false;      

  }

  boolean firstErrorFound;
  boolean secondErrorFound;

  // part of the PdeMessageConsumer interface
  //
  boolean notFoundError;

  public void message(String s) {
    //System.err.println("MSG: " + s);
    System.err.print(s);

    // ignore cautions
    if (s.indexOf("Error") != -1) {
      //exception = new RunnerException(s+" Check the serial port selected or your Board is connected");
      //System.out.println(s);
      notFoundError = true;
      return;
    }
    if(notFoundError) {
      //System.out.println("throwing something");
      exception = new RunnerException(I18n.format(_("the selected serial port {0} does not exist or your board is not connected"), s));
      return;
    }
    if (s.indexOf("Device is not responding") != -1 ) {
      exception =  new RunnerException(_("Device is not responding, check the right serial port is selected or RESET the board right before exporting"));
      return;
    }
    if (s.indexOf("Programmer is not responding") != -1 ||
        s.indexOf("programmer is not responding") != -1 ||
        s.indexOf("protocol error") != -1) {
      exception = new RunnerException(_("Problem uploading to board.  See http://www.arduino.cc/en/Guide/Troubleshooting#upload for suggestions."));
      return;
    }
    if (s.indexOf("Expected signature") != -1) {
      exception = new RunnerException(_("Wrong microcontroller found.  Did you select the right board from the Tools > Board menu?"));
      return;
    }
  }


}
