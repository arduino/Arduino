/* -*- mode: java; c-basic-offset: 2; indent-tabs-mode: nil -*- */

/*
  Part of the Processing project - http://processing.org

  Copyright (c) 2008-2009 Ben Fry and Casey Reas

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

package processing.app.windows;

import cc.arduino.os.windows.Win32KnownFolders;
import processing.app.PreferencesData;
import processing.app.legacy.PApplet;
import processing.app.legacy.PConstants;

import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.LinkedList;
import java.util.List;

import com.sun.jna.Native;
import com.sun.jna.Pointer;
import com.sun.jna.platform.win32.Shell32;
import com.sun.jna.win32.StdCallLibrary;
import com.sun.jna.win32.W32APIOptions;

public class Platform extends processing.app.Platform {

  private File settingsFolder;
  private File defaultSketchbookFolder;

  @Override
  public void init() throws Exception {
    super.init();

    checkPath();
    recoverSettingsFolderPath();
    recoverDefaultSketchbookFolder();
  }

  private void recoverSettingsFolderPath() throws Exception {
    if (PreferencesData.getBoolean("runtime.is-windows-store-app")) {
      // LocalAppData is restricted for Windows Store Apps.
      // We are forced to use a document folder to store tools.
      Path path = Win32KnownFolders.getDocumentsFolder().toPath();
      settingsFolder = path.resolve("ArduinoData").toFile();
    } else {
      Path path = Win32KnownFolders.getLocalAppDataFolder().toPath();
      settingsFolder = path.resolve("Arduino15").toFile();
    }
  }

  private Path recoverOldSettingsFolderPath() throws Exception {
    Path path = Win32KnownFolders.getRoamingAppDataFolder().toPath();
    return path.resolve("Arduino15");
  }

  private void recoverDefaultSketchbookFolder() throws Exception {
    Path path = Win32KnownFolders.getDocumentsFolder().toPath();
    defaultSketchbookFolder = path.resolve("Arduino").toFile();
  }

  /**
   * Remove extra quotes, slashes, and garbage from the Windows PATH.
   */
  protected void checkPath() {
    String path = System.getProperty("java.library.path");
    String[] pieces = PApplet.split(path, File.pathSeparatorChar);
    String[] legit = new String[pieces.length];
    int legitCount = 0;
    for (String item : pieces) {
      if (item.startsWith("\"")) {
        item = item.substring(1);
      }
      if (item.endsWith("\"")) {
        item = item.substring(0, item.length() - 1);
      }
      if (item.endsWith(File.separator)) {
        item = item.substring(0, item.length() - File.separator.length());
      }
      File directory = new File(item);
      if (!directory.exists()) {
        continue;
      }
      if (item.trim().length() == 0) {
        continue;
      }
      legit[legitCount++] = item;
    }
    legit = PApplet.subset(legit, 0, legitCount);
    String newPath = PApplet.join(legit, File.pathSeparator);
    if (!newPath.equals(path)) {
      System.setProperty("java.library.path", newPath);
    }
  }

  @Override
  public File getSettingsFolder() {
    return settingsFolder;
  }


  @Override
  public File getDefaultSketchbookFolder() throws Exception {
    return defaultSketchbookFolder;
  }

  @Override
  public void openURL(String url) throws Exception {
    if (!url.startsWith("http") && !url.startsWith("file:")) {
      // Check if we are trying to open a local file
      File file = new File(url);
      if (file.exists()) {
        // in this case convert the path to a "file:" url
        url = file.toURI().toString();
      }
    }
    if (url.startsWith("http") || url.startsWith("file:")) {
      // this allows to open the file on Windows 10 that
      // has a more strict permission policy for cmd.exe
      final int SW_SHOW = 5;
      Shell32.INSTANCE.ShellExecute(null, null, url, null, null, SW_SHOW);
      return;
    }

    // this is not guaranteed to work, because who knows if the
    // path will always be c:\progra~1 et al. also if the user has
    // a different browser set as their default (which would
    // include me) it'd be annoying to be dropped into ie.
    //Runtime.getRuntime().exec("c:\\progra~1\\intern~1\\iexplore "
    // + currentDir

    // the following uses a shell execute to launch the .html file
    // note that under cygwin, the .html files have to be chmodded +x
    // after they're unpacked from the zip file. i don't know why,
    // and don't understand what this does in terms of windows
    // permissions. without the chmod, the command prompt says
    // "Access is denied" in both cygwin and the "dos" prompt.
    //Runtime.getRuntime().exec("cmd /c " + currentDir + "\\reference\\" +
    //                    referenceFile + ".html");

    // just launching the .html file via the shell works
    // but make sure to chmod +x the .html files first
    // also place quotes around it in case there's a space
    // in the user.dir part of the url
    Runtime.getRuntime().exec("cmd /c \"" + url + "\"");
  }


  @Override
  public boolean openFolderAvailable() {
    return true;
  }


  @Override
  public void openFolder(File file) throws Exception {
    String folder = file.getAbsolutePath();

    // doesn't work
    //Runtime.getRuntime().exec("cmd /c \"" + folder + "\"");

    // works fine on winxp, prolly win2k as well
    Runtime.getRuntime().exec("explorer \"" + folder + "\"");

    // not tested
    //Runtime.getRuntime().exec("start explorer \"" + folder + "\"");
  }


  // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .


  @Override
  public String getName() {
    return PConstants.platformNames[PConstants.WINDOWS];
  }

  @Override
  public void fixPrefsFilePermissions(File prefsFile) throws IOException {
    //noop
  }

  @Override
  public List<File> postInstallScripts(File folder) {
    List<File> scripts = new LinkedList<>();
    scripts.add(new File(folder, "post_install.bat"));
    return scripts;
  }

  @Override
  public List<File> preUninstallScripts(File folder) {
    List<File> scripts = new LinkedList<>();
    scripts.add(new File(folder, "pre_uninstall.bat"));
    return scripts;
  }

  public void symlink(File something, File somewhere) throws IOException, InterruptedException {
  }

  @Override
  public void link(File something, File somewhere) throws IOException, InterruptedException {
  }

  @Override
  public void chmod(File file, int mode) throws IOException, InterruptedException {
  }

  @Override
  public void fixSettingsLocation() throws Exception {
    if (PreferencesData.getBoolean("runtime.is-windows-store-app"))
      return;

    Path oldSettingsFolder = recoverOldSettingsFolderPath();
    if (!Files.exists(oldSettingsFolder)) {
      return;
    }

    if (!Files.exists(oldSettingsFolder.resolve(Paths.get("preferences.txt")))) {
      return;
    }

    if (settingsFolder.exists()) {
      return;
    }

    Files.move(oldSettingsFolder, settingsFolder.toPath());
  }

  // Need to extend com.sun.jna.platform.win32.User32 to access
  // Win32 function GetDpiForSystem()
  interface ExtUser32 extends StdCallLibrary, com.sun.jna.platform.win32.User32 {
    ExtUser32 INSTANCE = (ExtUser32) Native.loadLibrary("user32", ExtUser32.class, W32APIOptions.DEFAULT_OPTIONS);

    public int GetDpiForSystem();

    public int SetProcessDpiAwareness(int value);

    public final int DPI_AWARENESS_INVALID = -1;
    public final int DPI_AWARENESS_UNAWARE = 0;
    public final int DPI_AWARENESS_SYSTEM_AWARE = 1;
    public final int DPI_AWARENESS_PER_MONITOR_AWARE = 2;

    public Pointer SetThreadDpiAwarenessContext(Pointer dpiContext);

    public final Pointer DPI_AWARENESS_CONTEXT_UNAWARE = new Pointer(-1);
    public final Pointer DPI_AWARENESS_CONTEXT_SYSTEM_AWARE = new Pointer(-2);
    public final Pointer DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE = new Pointer(-3);
  }

  private static int detected = detectSystemDPI();

  @Override
  public int getSystemDPI() {
    if (detected == -1)
      return super.getSystemDPI();
    return detected;
  }

  public static int detectSystemDPI() {
    try {
      ExtUser32.INSTANCE.SetProcessDpiAwareness(ExtUser32.DPI_AWARENESS_SYSTEM_AWARE);
    } catch (Throwable e) {
      // Ignore error
    }
    try {
      ExtUser32.INSTANCE.SetThreadDpiAwarenessContext(ExtUser32.DPI_AWARENESS_CONTEXT_SYSTEM_AWARE);
    } catch (Throwable e) {
      // Ignore error (call valid only on Windows 10)
    }
    try {
      return ExtUser32.INSTANCE.GetDpiForSystem();
    } catch (Throwable e) {
      // DPI detection failed, fall back with default
      System.out.println("DPI detection failed, fallback to 96 dpi");
      return -1;
    }
  }
}
