/*
 * This file is part of Arduino.
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
 *
 * Copyright 2015 Arduino LLC (http://www.arduino.cc/)
 */

package cc.arduino;

import cc.arduino.packages.BoardPort;
import cc.arduino.packages.Uploader;
import cc.arduino.packages.UploaderFactory;
import processing.app.BaseNoGui;
import processing.app.PreferencesData;
import processing.app.SketchData;
import processing.app.debug.TargetPlatform;

import java.util.LinkedList;
import java.util.List;

import static processing.app.I18n.tr;

public class UploaderUtils {

  public Uploader getUploaderByPreferences(boolean noUploadPort) {
    TargetPlatform target = BaseNoGui.getTargetPlatform();
    String board = PreferencesData.get("board");

    BoardPort boardPort = null;
    if (!noUploadPort) {
      boardPort = BaseNoGui.getDiscoveryManager().find(PreferencesData.get("serial.port"));
    }

    return new UploaderFactory().newUploader(target.getBoards().get(board), boardPort, noUploadPort);
  }

  public boolean upload(SketchData data, Uploader uploader, String buildPath, String suggestedClassName, boolean usingProgrammer, boolean noUploadPort, List<String> warningsAccumulator) throws Exception {

    if (uploader == null)
      uploader = getUploaderByPreferences(noUploadPort);

    boolean success = false;

    if (uploader.requiresAuthorization() && !PreferencesData.has(uploader.getAuthorizationKey())) {
      BaseNoGui.showError(tr("Authorization required"),
        tr("No authorization data found"), null);
    }

    boolean useNewWarningsAccumulator = false;
    if (warningsAccumulator == null) {
      warningsAccumulator = new LinkedList<String>();
      useNewWarningsAccumulator = true;
    }

    try {
      success = uploader.uploadUsingPreferences(data.getFolder(), buildPath, suggestedClassName, usingProgrammer, warningsAccumulator);
    } finally {
      if (uploader.requiresAuthorization() && !success) {
        PreferencesData.remove(uploader.getAuthorizationKey());
      }
    }

    if (useNewWarningsAccumulator) {
      for (String warning : warningsAccumulator) {
        System.out.print(tr("Warning"));
        System.out.print(": ");
        System.out.println(warning);
      }
    }

    return success;
  }


}
