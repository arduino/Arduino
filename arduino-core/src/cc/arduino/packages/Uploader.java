/*
 * This file is part of Arduino.
 *
 * Uploader - abstract uploading baseclass (common to both uisp and avrdude)
 *
 * Copyright (c) 2004-05
 * Hernando Barragan
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

package cc.arduino.packages;

import processing.app.I18n;
import processing.app.PreferencesData;
import processing.app.debug.MessageConsumer;
import processing.app.debug.MessageSiphon;
import processing.app.helpers.ProcessUtils;

import java.io.File;
import java.util.Collection;
import java.util.List;
import java.util.concurrent.TimeUnit;

import org.apache.commons.lang3.StringUtils;

import static processing.app.I18n.tr;

public abstract class Uploader implements MessageConsumer {

  private static final String[] STRINGS_TO_SUPPRESS;
  private static final String[] AVRDUDE_PROBLEMS;

  static {
    STRINGS_TO_SUPPRESS = new String[] {"Connecting to programmer:",
            "Found programmer: Id = \"CATERIN\"; type = S",
            "Software Version = 1.0; No Hardware Version given.",
            "Programmer supports auto addr increment.",
            "Programmer supports buffered memory access with buffersize=128 bytes.",
            "Programmer supports the following devices:", "Device code: 0x44"};

    AVRDUDE_PROBLEMS = new String[] {"Programmer is not responding",
            "programmer is not responding",
            "protocol error", "avrdude: ser_open(): can't open device",
            "avrdude: ser_drain(): read error",
            "avrdude: ser_send(): write error",
            "avrdude: error: buffered memory access not supported."};
  }

  protected final boolean verbose;
  protected final boolean verifyUpload;

  private String error;
  protected boolean notFoundError;
  protected boolean noUploadPort;

  protected Uploader() {
    this.verbose = PreferencesData.getBoolean("upload.verbose");
    this.verifyUpload = PreferencesData.getBoolean("upload.verify");
    init(false);
  }

  protected Uploader(boolean nup) {
    this.verbose = PreferencesData.getBoolean("upload.verbose");
    this.verifyUpload = PreferencesData.getBoolean("upload.verify");
    init(nup);
  }

  private void init(boolean nup) {
    this.error = "";
    this.notFoundError = false;
    this.noUploadPort = nup;
  }

  public abstract boolean uploadUsingPreferences(File sourcePath, String buildPath, String className, boolean usingProgrammer, List<String> warningsAccumulator) throws Exception;

  public abstract boolean burnBootloader() throws Exception;

  public boolean requiresAuthorization() {
    return false;
  }

  public String getAuthorizationKey() {
    return null;
  }

  // static field for last executed programmer process ID
  static public Process programmerPid;

  protected boolean executeUploadCommand(Collection<String> command) throws Exception {
    return executeUploadCommand(command.toArray(new String[command.size()]));
  }

  protected boolean executeUploadCommand(String command[]) throws Exception {
    // Skip empty commands
    if (command == null || command.length == 0)
      return true;

    notFoundError = false;
    int result = -1;

    try {
      if (verbose) {
        for (String c : command)
          System.out.print(c + " ");
        System.out.println();
      }
      Process process = ProcessUtils.exec(command);
      programmerPid = process;
      new MessageSiphon(process.getInputStream(), this, 100);
      new MessageSiphon(process.getErrorStream(), this, 100);

      // wait for the process to finish, but not forever
      // kill the flasher process after 5 minutes to avoid 100% cpu spinning
      if (!process.waitFor(5, TimeUnit.MINUTES)) {
        process.destroyForcibly();
      }
      if (!process.isAlive()) {
        result = process.exitValue();
      } else {
        result = 0;
      }
    } catch (Exception e) {
      e.printStackTrace();
    }

    return result == 0;
  }

  public String getFailureMessage() {
    return error;
  }

  @Override
  public void message(String s) {
    // selectively suppress a bunch of avrdude output for AVR109/Caterina that should already be quelled but isn't
    if (!verbose && StringUtils.containsAny(s, STRINGS_TO_SUPPRESS)) {
      s = "";
    }

    System.err.print(s);

    // ignore cautions
    if (s.toLowerCase().contains("error")) {
      notFoundError = true;
      error = s;
      return;
    }
    if (notFoundError) {
      error = I18n.format(tr("the selected serial port {0} does not exist or your board is not connected"), s);
      return;
    }
    if (s.contains("Device is not responding")) {
      error = tr("Device is not responding, check the right serial port is selected or RESET the board right before exporting");
      return;
    }
    if (StringUtils.containsAny(s, AVRDUDE_PROBLEMS)) {
      error = tr("Problem uploading to board.  See http://www.arduino.cc/en/Guide/Troubleshooting#upload for suggestions.");
      return;
    }
    if (s.contains("Expected signature")) {
      error = tr("Wrong microcontroller found.  Did you select the right board from the Tools > Board menu?");
      return;
    }
  }
}
