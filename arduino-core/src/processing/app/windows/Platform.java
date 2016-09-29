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

import cc.arduino.os.windows.FolderFinderInWindowsEnvVar;
import cc.arduino.os.windows.FolderFinderInWindowsRegistry;
import processing.app.legacy.PApplet;
import processing.app.legacy.PConstants;

import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.LinkedList;
import java.util.List;


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
    FolderFinderInWindowsRegistry findInUserShellFolders = new FolderFinderInWindowsRegistry(null, "Documents", "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\User Shell Folders", "Local AppData");
    FolderFinderInWindowsRegistry findInShellFolders = new FolderFinderInWindowsRegistry(findInUserShellFolders, "Documents", "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Shell Folders", "Local AppData");

    Path path = findInShellFolders.find();
    this.settingsFolder = path.resolve("Arduino15").toFile();
  }

  private Path recoverOldSettingsFolderPath() throws Exception {
    FolderFinderInWindowsRegistry findInUserShellFolders = new FolderFinderInWindowsRegistry(null, "Documents", "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\User Shell Folders", "AppData");
    FolderFinderInWindowsRegistry findInShellFolders = new FolderFinderInWindowsRegistry(findInUserShellFolders, "Documents", "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Shell Folders", "AppData");

    Path path = findInShellFolders.find();
    return path.resolve("Arduino15");
  }

  private void recoverDefaultSketchbookFolder() throws Exception {
    FolderFinderInWindowsEnvVar findInUserProfile = new FolderFinderInWindowsEnvVar(null, "Documents", "USERPROFILE");
    FolderFinderInWindowsRegistry findInUserShellFolders = new FolderFinderInWindowsRegistry(findInUserProfile, "Documents", "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\User Shell Folders", "Personal");
    FolderFinderInWindowsRegistry findInShellFolders = new FolderFinderInWindowsRegistry(findInUserShellFolders, "Documents", "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Shell Folders", "Personal");

    Path path = findInShellFolders.find();
    this.defaultSketchbookFolder = path.resolve("Arduino").toFile();
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
    if (url.startsWith("http") || url.startsWith("file:")) {
      // open dos prompt, give it 'start' command, which will
      // open the url properly. start by itself won't work since
      // it appears to need cmd
      Runtime.getRuntime().exec("cmd /c start \"\" \"" + url + "\"");
    } else {
      // just launching the .html file via the shell works
      // but make sure to chmod +x the .html files first
      // also place quotes around it in case there's a space
      // in the user.dir part of the url
      Runtime.getRuntime().exec("cmd /c \"" + url + "\"");
    }
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
}
