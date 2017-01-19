/*
 * This file is part of Arduino.
 *
 * BasicUploader - generic command line uploader implementation
 *
 * Copyright (c) 2004-05
 * Hernando Barragan
 * Copyright (c) 2012
 * Cristian Maglie <c.maglie@arduino.cc>
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

package cc.arduino.packages.uploaders;

import cc.arduino.LoadVIDPIDSpecificPreferences;
import cc.arduino.packages.Uploader;
import processing.app.*;
import cc.arduino.packages.BoardPort;
import processing.app.debug.RunnerException;
import processing.app.debug.TargetPlatform;
import processing.app.helpers.PreferencesMap;
import processing.app.helpers.StringReplacer;

import java.io.File;
import java.util.ArrayList;
import java.util.List;

import static processing.app.I18n.tr;

public class SerialUploader extends Uploader {

  public SerialUploader()
  {
    super();
  }

  public SerialUploader(boolean noUploadPort)
  {
    super(noUploadPort);
  }

  @Override
  public boolean uploadUsingPreferences(File sourcePath, String buildPath, String className, boolean usingProgrammer, List<String> warningsAccumulator) throws Exception {
    // FIXME: Preferences should be reorganized
    TargetPlatform targetPlatform = BaseNoGui.getTargetPlatform();
    PreferencesMap prefs = PreferencesData.getMap();
    PreferencesMap boardPreferences = BaseNoGui.getBoardPreferences();
    if (boardPreferences != null) {
      prefs.putAll(boardPreferences);
    }
    String tool = prefs.getOrExcept("upload.tool");
    if (tool.contains(":")) {
      String[] split = tool.split(":", 2);
      targetPlatform = BaseNoGui.getCurrentTargetPlatformFromPackage(split[0]);
      tool = split[1];
    }
    prefs.putAll(targetPlatform.getTool(tool));

    if (programmerPid != null && programmerPid.isAlive()) {
      // kill the previous programmer
      programmerPid.destroyForcibly();
    }

    // if no protocol is specified for this board, assume it lacks a 
    // bootloader and upload using the selected programmer.
    if (usingProgrammer || prefs.get("upload.protocol") == null) {
      return uploadUsingProgrammer(buildPath, className);
    }

    BaseNoGui.getDiscoveryManager().getSerialDiscoverer().pausePolling(true);

    if (noUploadPort)
    {
      prefs.put("build.path", buildPath);
      prefs.put("build.project_name", className);
      if (verbose)
        prefs.put("upload.verbose", prefs.getOrExcept("upload.params.verbose"));
      else
        prefs.put("upload.verbose", prefs.getOrExcept("upload.params.quiet"));

      if (verifyUpload)
        prefs.put("upload.verify", prefs.get("upload.params.verify", ""));
      else
        prefs.put("upload.verify", prefs.get("upload.params.noverify", ""));

      boolean uploadResult;
      try {
        String pattern = prefs.getOrExcept("upload.pattern");
        String[] cmd = StringReplacer.formatAndSplit(pattern, prefs, true);
        uploadResult = executeUploadCommand(cmd);
      } catch (Exception e) {
        throw new RunnerException(e);
      } finally {
        BaseNoGui.getDiscoveryManager().getSerialDiscoverer().pausePolling(false);
      }
      return uploadResult;
    }

    // need to do a little dance for Leonardo and derivatives:
    // open then close the port at the magic baudrate (usually 1200 bps) first
    // to signal to the sketch that it should reset into bootloader. after doing
    // this wait a moment for the bootloader to enumerate. On Windows, also must
    // deal with the fact that the COM port number changes from bootloader to
    // sketch.
    String t = prefs.get("upload.use_1200bps_touch");
    boolean doTouch = t != null && t.equals("true");

    t = prefs.get("upload.wait_for_upload_port");
    boolean waitForUploadPort = (t != null) && t.equals("true");

    String userSelectedUploadPort = prefs.getOrExcept("serial.port");
    String actualUploadPort = null;

    if (doTouch) {
      try {
        // Toggle 1200 bps on selected serial port to force board reset.
        List<String> before = Serial.list();
        if (before.contains(userSelectedUploadPort)) {
          if (verbose)
            System.out.println(
              I18n.format(tr("Forcing reset using 1200bps open/close on port {0}"), userSelectedUploadPort));
          Serial.touchForCDCReset(userSelectedUploadPort);
        }
        Thread.sleep(400);
        if (waitForUploadPort) {
          // Scanning for available ports seems to open the port or
          // otherwise assert DTR, which would cancel the WDT reset if
          // it happened within 250 ms. So we wait until the reset should
          // have already occurred before we start scanning.
          actualUploadPort = waitForUploadPort(userSelectedUploadPort, before);

    	  // on OS X, if the port is opened too quickly after it is detected,
    	  // a "Resource busy" error occurs, add a delay to workaround this,
          // apply to other platforms as well.
    	  Thread.sleep(250);
        }
      } catch (SerialException e) {
        throw new RunnerException(e);
      } catch (InterruptedException e) {
        throw new RunnerException(e.getMessage());
      } finally {
        BaseNoGui.getDiscoveryManager().getSerialDiscoverer().pausePolling(false);
      }
      if (actualUploadPort == null) {
        actualUploadPort = userSelectedUploadPort;
      }
      prefs.put("serial.port", actualUploadPort);
      if (actualUploadPort.startsWith("/dev/")) {
        prefs.put("serial.port.file", actualUploadPort.substring(5));
      } else {
        prefs.put("serial.port.file", actualUploadPort);
      }

      // retrigger a discovery
      BaseNoGui.getDiscoveryManager().getSerialDiscoverer().setUploadInProgress(true);
      Thread.sleep(100);
      BaseNoGui.getDiscoveryManager().getSerialDiscoverer().forceRefresh();
      Thread.sleep(100);
    }

    BoardPort boardPort = BaseNoGui.getDiscoveryManager().find(PreferencesData.get("serial.port"));
    try {
      prefs.put("serial.port.iserial", boardPort.getPrefs().getOrExcept("iserial"));
    } catch (Exception e) {
      // if serial port does not contain an iserial field
    }

    prefs.put("build.path", buildPath);
    prefs.put("build.project_name", className);
    if (verbose) {
      prefs.put("upload.verbose", prefs.getOrExcept("upload.params.verbose"));
    } else {
      prefs.put("upload.verbose", prefs.getOrExcept("upload.params.quiet"));
    }

    if (verifyUpload)
      prefs.put("upload.verify", prefs.get("upload.params.verify", ""));
    else
      prefs.put("upload.verify", prefs.get("upload.params.noverify", ""));

    boolean uploadResult;
    try {
      String pattern = prefs.getOrExcept("upload.pattern");
      String[] cmd = StringReplacer.formatAndSplit(pattern, prefs, true);
      uploadResult = executeUploadCommand(cmd);
    } catch (RunnerException e) {
      throw e;
    } catch (Exception e) {
      throw new RunnerException(e);
    } finally {
      BaseNoGui.getDiscoveryManager().getSerialDiscoverer().pausePolling(false);
    }

    BaseNoGui.getDiscoveryManager().getSerialDiscoverer().setUploadInProgress(false);
    BaseNoGui.getDiscoveryManager().getSerialDiscoverer().pausePolling(false);

    String finalUploadPort = null;
    if (uploadResult && doTouch) {
      try {
        if (waitForUploadPort) {
          // For Due/Leonardo wait until the bootloader serial port disconnects and the
          // sketch serial port reconnects (or timeout after a few seconds if the
          // sketch port never comes back). Doing this saves users from accidentally
          // opening Serial Monitor on the soon-to-be-orphaned bootloader port.
          Thread.sleep(1000);
          long started = System.currentTimeMillis();
          while (System.currentTimeMillis() - started < 2000) {
            List<String> portList = Serial.list();
            if (portList.contains(userSelectedUploadPort)) {
              finalUploadPort = userSelectedUploadPort;
              break;
            }
            Thread.sleep(250);
          }
        }
      } catch (InterruptedException ex) {
        // noop
      }
    }

    if (finalUploadPort == null) {
      finalUploadPort = actualUploadPort;
    }
    if (finalUploadPort == null) {
      finalUploadPort = userSelectedUploadPort;
    }
    BaseNoGui.selectSerialPort(finalUploadPort);

    return uploadResult;
  }

  private String waitForUploadPort(String uploadPort, List<String> before) throws InterruptedException, RunnerException {
    // Wait for a port to appear on the list
    int elapsed = 0;
    while (elapsed < 10000) {
      List<String> now = Serial.list();
      List<String> diff = new ArrayList<>(now);
      diff.removeAll(before);
      if (verbose) {
        System.out.print("PORTS {");
        for (String p : before)
          System.out.print(p + ", ");
        System.out.print("} / {");
        for (String p : now)
          System.out.print(p + ", ");
        System.out.print("} => {");
        for (String p : diff)
          System.out.print(p + ", ");
        System.out.println("}");
      }
      if (diff.size() > 0) {
        String newPort = diff.get(0);
        if (verbose)
          System.out.println("Found upload port: " + newPort);
        return newPort;
      }

      // Keep track of port that disappears
      before = now;
      Thread.sleep(250);
      elapsed += 250;

      // On Windows and OS X, it can take a few seconds for the port to disappear and
      // come back, so use a time out before assuming that the selected port is the
      // bootloader (not the sketch).
      if (elapsed >= 5000 && now.contains(uploadPort)) {
        if (verbose)
          System.out.println("Uploading using selected port: " + uploadPort);
        return uploadPort;
      }
    }

    // Something happened while detecting port
    throw new RunnerException(tr("Couldn't find a Board on the selected port. Check that you have the correct port selected.  If it is correct, try pressing the board's reset button after initiating the upload."), false);
  }

  private boolean uploadUsingProgrammer(String buildPath, String className) throws Exception {

    TargetPlatform targetPlatform = BaseNoGui.getTargetPlatform();
    String programmer = PreferencesData.get("programmer");
    if (programmer.contains(":")) {
      String[] split = programmer.split(":", 2);
      targetPlatform = BaseNoGui.getCurrentTargetPlatformFromPackage(split[0]);
      programmer = split[1];
    }

    PreferencesMap prefs = PreferencesData.getMap();
    PreferencesMap boardPreferences = BaseNoGui.getBoardPreferences();
    if (boardPreferences != null) {
      prefs.putAll(boardPreferences);
    }
    PreferencesMap programmerPrefs = targetPlatform.getProgrammer(programmer);
    if (programmerPrefs == null)
      throw new RunnerException(
          tr("Please select a programmer from Tools->Programmer menu"));
    prefs.putAll(targetPlatform.getTool(programmerPrefs.getOrExcept("program.tool")));
    prefs.putAll(programmerPrefs);

    prefs.put("build.path", buildPath);
    prefs.put("build.project_name", className);

    if (verbose)
      prefs.put("program.verbose", prefs.getOrExcept("program.params.verbose"));
    else
      prefs.put("program.verbose", prefs.getOrExcept("program.params.quiet"));

    if (verifyUpload)
      prefs.put("program.verify", prefs.get("program.params.verify", ""));
    else
      prefs.put("program.verify", prefs.get("program.params.noverify", ""));

    try {
      // if (prefs.get("program.disable_flushing") == null
      // || prefs.get("program.disable_flushing").toLowerCase().equals("false"))
      // {
      // flushSerialBuffer();
      // }

      String pattern = prefs.getOrExcept("program.pattern");
      String[] cmd = StringReplacer.formatAndSplit(pattern, prefs, true);
      return executeUploadCommand(cmd);
    } catch (RunnerException e) {
      throw e;
    } catch (Exception e) {
      throw new RunnerException(e);
    }
  }

  @Override
  public boolean burnBootloader() throws Exception {
    TargetPlatform targetPlatform = BaseNoGui.getTargetPlatform();

    // Find preferences for the selected programmer
    PreferencesMap programmerPrefs;
    String programmer = PreferencesData.get("programmer");
    if (programmer.contains(":")) {
      String[] split = programmer.split(":", 2);
      TargetPlatform platform = BaseNoGui.getCurrentTargetPlatformFromPackage(split[0]);
      programmer = split[1];
      programmerPrefs = platform.getProgrammer(programmer);
    } else {
      programmerPrefs = targetPlatform.getProgrammer(programmer);
    }
    if (programmerPrefs == null)
      throw new RunnerException(
          tr("Please select a programmer from Tools->Programmer menu"));

    // Build configuration for the current programmer
    PreferencesMap prefs = PreferencesData.getMap();
    PreferencesMap boardPreferences = BaseNoGui.getBoardPreferences();
    if (boardPreferences != null) {
      prefs.putAll(boardPreferences);
    }
    prefs.putAll(programmerPrefs);

    // Create configuration for bootloader tool
    PreferencesMap toolPrefs = new PreferencesMap();
    String tool = prefs.getOrExcept("bootloader.tool");
    if (tool.contains(":")) {
      String[] split = tool.split(":", 2);
      TargetPlatform platform = BaseNoGui.getCurrentTargetPlatformFromPackage(split[0]);
      tool = split[1];
      toolPrefs.putAll(platform.getTool(tool));
      if (toolPrefs.size() == 0)
        throw new RunnerException(I18n.format(tr("Could not find tool {0} from package {1}"), tool, split[0]));
    }
    toolPrefs.putAll(targetPlatform.getTool(tool));
    if (toolPrefs.size() == 0)
      throw new RunnerException(I18n.format(tr("Could not find tool {0}"), tool));

    // Merge tool with global configuration
    prefs.putAll(toolPrefs);
    if (verbose) {
      prefs.put("erase.verbose", prefs.getOrExcept("erase.params.verbose"));
      prefs.put("bootloader.verbose", prefs.getOrExcept("bootloader.params.verbose"));
    } else {
      prefs.put("erase.verbose", prefs.getOrExcept("erase.params.quiet"));
      prefs.put("bootloader.verbose", prefs.getOrExcept("bootloader.params.quiet"));
    }

    new LoadVIDPIDSpecificPreferences().load(prefs);

    String pattern = prefs.getOrExcept("erase.pattern");
    String[] cmd = StringReplacer.formatAndSplit(pattern, prefs, true);
    if (!executeUploadCommand(cmd))
      return false;

    pattern = prefs.getOrExcept("bootloader.pattern");
    cmd = StringReplacer.formatAndSplit(pattern, prefs, true);
    return executeUploadCommand(cmd);
  }
}
