/*
  GenericNetworkUploader - generic network uploader implementation
  makes possible to implement firmware updates over the air on any device
  Part of the Arduino project - http://www.arduino.cc/

  Copyright (c) 2004-05
  Hernando Barragan
  Copyright (c) 2012
  Cristian Maglie <c.maglie@arduino.cc>
  Copyright (c) 2015
  Hristo Gochkov <hristo.gochkov@gmail.com>

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
*/

package cc.arduino.packages.uploaders;

import cc.arduino.packages.BoardPort;
import cc.arduino.packages.Uploader;
import processing.app.*;
import processing.app.debug.RunnerException;
import processing.app.debug.TargetPlatform;
import processing.app.helpers.PreferencesMap;
import processing.app.helpers.StringReplacer;

import java.io.File;
import java.util.List;

public class GenericNetworkUploader extends Uploader {

  private final BoardPort port;

  public GenericNetworkUploader(BoardPort port) {
    this.port = port;
  }

  @Override
  public boolean requiresAuthorization() {
    return this.port.getPrefs().get("auth_upload").contentEquals("yes");
  }

  @Override
  public String getAuthorizationKey() {
    return "runtime.pwd." + this.port.getAddress();
  }

  @Override
  public boolean uploadUsingPreferences(File sourcePath, String buildPath, String className, boolean usingProgrammer, List<String> warningsAccumulator) throws Exception {
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
    
    String password = "";
    if(requiresAuthorization()){
      password = prefs.getOrExcept(getAuthorizationKey());
    }
    prefs.put("network.password", password);

    prefs.put("network.port", this.port.getPrefs().get("port"));
    
    prefs.put("build.path", buildPath);
    prefs.put("build.project_name", className);
    if (verbose) {
      prefs.put("upload.verbose", prefs.getOrExcept("upload.params.verbose"));
    } else {
      prefs.put("upload.verbose", prefs.getOrExcept("upload.params.quiet"));
    }
    
    boolean uploadResult;
    try {
      String pattern;
      //check if there is a separate pattern for network uploads
      pattern = prefs.get("upload.network_pattern");
      if(pattern == null)
        pattern = prefs.getOrExcept("upload.pattern");
      String[] cmd = StringReplacer.formatAndSplit(pattern, prefs, true);
      uploadResult = executeUploadCommand(cmd);
    } catch (RunnerException e) {
      throw e;
    } catch (Exception e) {
      throw new RunnerException(e);
    }
    return uploadResult;
  }

  @Override
  public boolean burnBootloader() throws RunnerException {
    throw new RunnerException("Burning bootloader is not supported via network!");
  }
}
