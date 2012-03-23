/* -*- mode: jde; c-basic-offset: 2; indent-tabs-mode: nil -*- */

/*
  BasicUploader - basic uploader implementation
  Part of the Arduino project - http://www.arduino.cc/

  Copyright (c) 2012
  Andrew Dalgleish

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

import java.io.*;
import java.util.*;
import java.util.zip.*;
import javax.swing.*;
import gnu.io.*;


public class BasicUploader extends Uploader  {
  public BasicUploader() {
  }

  public boolean uploadUsingPreferences(String buildPath, String className, boolean usingProgrammer)
  throws RunnerException, SerialException {
    this.verbose = verbose;


    // if no protocol is specified for this board, assume it lacks a 
    // bootloader and upload using the selected programmer.
    Map<String, String> boardPreferences = Base.getBoardPreferences();
    if (!usingProgrammer && boardPreferences.get("upload.protocol") != null) {
      // We should never get here - BasicUploader is only for using a programmer
      return false;
    }

    String programmer = Preferences.get("programmer");
    Target target = Base.getTarget();

    if (programmer.indexOf(":") != -1) {
      target = Base.targetsTable.get(programmer.substring(0, programmer.indexOf(":")));
      programmer = programmer.substring(programmer.indexOf(":") + 1);
    }
    Map<String, String> programmerPreferences = target.getProgrammers().get(programmer);

    String command = programmerPreferences.get("uploader.basic.command");
    String parameters  = programmerPreferences.get("uploader.basic.parameters");

    List commandList = new ArrayList(); 

    // Try our tools directories first, else assume the command includes the full path
    //
    if ((new File(Base.getHardwarePath() + "/tools/" + command)).exists()) {
      commandList.add(Base.getHardwarePath() + "/tools/" + command);
    } else if ((new File(Base.getHardwarePath() + "/tools/avr/bin/" + command)).exists()) {
      commandList.add(Base.getHardwarePath() + "/tools/avr/bin/" + command);
    } else {
      commandList.add(command);
    }

    // If we have any parameters, split them using the first character
    // This lets us define any character for the separator, but you always need at least one.
    // For example:
    // |param1
    // /param1/param2
    //
    if (parameters != null) {

      // Get the first character to use as a separator, and remove it
      //
      String separator = parameters.substring(0, 1);
      parameters = parameters.substring(1);

      // While we have another separator, split the first part off and remember the rest
      //
      while (parameters.indexOf(separator) != -1) {
        commandList.add(parameters.substring(0, parameters.indexOf(separator)));
	parameters = parameters.substring(parameters.indexOf(separator)+1);
      }

      // If we have any left, use it
      // 
      if (parameters != null) {
        commandList.add(parameters);
      }
    }

    // Add our hex file as the last parameter
    commandList.add(buildPath + File.separator + className + ".hex");

    return executeUploadCommand(commandList);
  }

  public boolean burnBootloader() throws RunnerException {
    // BasicUploader does not handle burning a bootloader
    return false;
  }

}
