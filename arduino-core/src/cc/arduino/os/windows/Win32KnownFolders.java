/*
 * This file is part of Arduino.
 *
 * Copyright 2016 Arduino LLC (http://www.arduino.cc/)
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

package cc.arduino.os.windows;

import static com.sun.jna.platform.win32.KnownFolders.FOLDERID_Documents;
import static com.sun.jna.platform.win32.KnownFolders.FOLDERID_LocalAppData;
import static com.sun.jna.platform.win32.KnownFolders.FOLDERID_RoamingAppData;

import java.io.File;
import java.io.FileNotFoundException;
import java.nio.file.Paths;

import com.sun.jna.platform.win32.Shell32Util;
import com.sun.jna.platform.win32.ShlObj;

import processing.app.PreferencesData;

public class Win32KnownFolders {

  public static File getLocalAppDataFolder() {
    try {
      return new File(Shell32Util.getKnownFolderPath(FOLDERID_LocalAppData));
    } catch (Throwable t) {
      // Ignore error if API call is not available
    }
    return new File(Shell32Util.getFolderPath(ShlObj.CSIDL_LOCAL_APPDATA));
  }

  public static File getRoamingAppDataFolder() {
    try {
      return new File(Shell32Util.getKnownFolderPath(FOLDERID_RoamingAppData));
    } catch (Throwable t) {
      // Ignore error if API call is not available
    }
    return new File(Shell32Util.getFolderPath(ShlObj.CSIDL_APPDATA));
  }

  public static File getDocumentsFolder() {
    try {
    return new File(Shell32Util.getKnownFolderPath(FOLDERID_Documents));
    } catch (Throwable t) {
      // Ignore error if API call is not available
    }
    return new File(Shell32Util.getFolderPath(ShlObj.CSIDL_MYDOCUMENTS));
  }

  public static File getLocalCacheFolder() throws FileNotFoundException {
    if (!PreferencesData.getBoolean("runtime.is-windows-store-app")) {
      throw new FileNotFoundException();
    }
    String localAppData = Shell32Util.getKnownFolderPath(FOLDERID_LocalAppData);
    String appId = PreferencesData.get("runtime.windows-store-app.id");
    return Paths.get(localAppData, "Packages", appId, "LocalCache").toFile();
  }
}
