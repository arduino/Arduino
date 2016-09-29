/* -*- mode: java; c-basic-offset: 2; indent-tabs-mode: nil -*- */

/*
  Part of the Processing project - http://processing.org

  Copyright (c) 2008 Ben Fry and Casey Reas

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

package processing.app;

import cc.arduino.packages.BoardPort;
import processing.app.debug.TargetBoard;
import processing.app.debug.TargetPackage;
import processing.app.debug.TargetPlatform;
import processing.app.legacy.PConstants;

import javax.swing.*;
import java.io.File;
import java.io.IOException;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.ArrayList;
import java.util.Arrays;

import java.net.URL;
import java.net.URLConnection;
import java.net.HttpURLConnection;
import com.fasterxml.jackson.databind.ObjectMapper;
import com.fasterxml.jackson.databind.DeserializationFeature;
import java.io.InputStream;

import static processing.app.I18n.tr;


/**
 * Used by Base for platform-specific tweaking, for instance finding the
 * sketchbook location using the Windows registry, or OS X event handling.
 * <p/>
 * The methods in this implementation are used by default, and can be
 * overridden by a subclass, if loaded by Base.main().
 * <p/>
 * These methods throw vanilla-flavored Exceptions, so that error handling
 * occurs inside Base.
 * <p/>
 * There is currently no mechanism for adding new platforms, as the setup is
 * not automated. We could use getProperty("os.arch") perhaps, but that's
 * debatable (could be upper/lowercase, have spaces, etc.. basically we don't
 * know if name is proper Java package syntax.)
 */
public class Platform {


  /**
   * Set the default L & F. While I enjoy the bounty of the sixteen possible
   * exception types that this UIManager method might throw, I feel that in
   * just this one particular case, I'm being spoiled by those engineers
   * at Sun, those Masters of the Abstractionverse. It leaves me feeling sad
   * and overweight. So instead, I'll pretend that I'm not offered eleven dozen
   * ways to report to the user exactly what went wrong, and I'll bundle them
   * all into a single catch-all "Exception". Because in the end, all I really
   * care about is whether things worked or not. And even then, I don't care.
   *
   * @throws Exception Just like I said.
   */
  public void setLookAndFeel() throws Exception {
    UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
  }


  public void init() throws Exception {
  }


  public File getSettingsFolder() throws Exception {
    // otherwise make a .processing directory int the user's home dir
    File home = new File(System.getProperty("user.home"));
    File dataFolder = new File(home, ".arduino15");
    return dataFolder;

    /*
    try {
      Class clazz = Class.forName("processing.app.macosx.ThinkDifferent");
      Method m = clazz.getMethod("getLibraryFolder", new Class[] { });
      String libraryPath = (String) m.invoke(null, new Object[] { });
      //String libraryPath = BaseMacOS.getLibraryFolder();
      File libraryFolder = new File(libraryPath);
      dataFolder = new File(libraryFolder, "Processing");

    } catch (Exception e) {
      showError("Problem getting data folder",
                "Error getting the Processing data folder.", e);
    }
    */
  }


  /**
   * @return null if not overridden, which will cause a prompt to show instead.
   * @throws Exception
   */
  public File getDefaultSketchbookFolder() throws Exception {
    return null;
  }

  public void openURL(File folder, String url) throws Exception {
    if (!url.startsWith("file://./")) {
      openURL(url);
      return;
    }

    url = url.replaceAll("file://./", folder.getCanonicalFile().toURI().toASCIIString());
    openURL(url);
  }

  public void openURL(String url) throws Exception {
    String launcher = PreferencesData.get("launcher");
    if (launcher != null) {
      Runtime.getRuntime().exec(new String[]{launcher, url});
    } else {
      showLauncherWarning();
    }
  }


  public boolean openFolderAvailable() {
    return PreferencesData.get("launcher") != null;
  }


  public void openFolder(File file) throws Exception {
    String launcher = PreferencesData.get("launcher");
    if (launcher != null) {
      String folder = file.getAbsolutePath();
      Runtime.getRuntime().exec(new String[]{launcher, folder});
    } else {
      showLauncherWarning();
    }
  }

  static {
    loadLib(new File(BaseNoGui.getContentFile("lib"), System.mapLibraryName("listSerialsj")));
  }

  private static void loadLib(File lib) {
    try {
      System.load(lib.getAbsolutePath());
    } catch (UnsatisfiedLinkError e) {
      e.printStackTrace();
      System.out.println(e.getMessage());
      System.out.println("Cannot load native library " + lib.getAbsolutePath());
      System.out.println("The program has terminated!");
      System.exit(1);
    }
  }

  private native String resolveDeviceAttachedToNative(String serial);
  private native String[] listSerialsNative();

  public String preListAllCandidateDevices() {
    return null;
  }

  public List<String> listSerials() {
    return new ArrayList<>(Arrays.asList(listSerialsNative()));
  }

  public  List<String> listSerialsNames(){
    List<String> list = new LinkedList<>();
    for (String port : listSerialsNative()) {
      list.add(port.split("_")[0]);
    }
    return list;
  }

  public static class BoardCloudAPIid {
    public BoardCloudAPIid() {   }
    private String name;
    private String architecture;
    private String id;
    public String getName() { return name; }
    public String getArchitecture() { return architecture; }
    public String getId() { return id; }
    public void setName(String tmp) { name = tmp; }
    public void setArchitecture(String tmp) { architecture = tmp; }
    public void setId(String tmp) { id = tmp; }
  }

  public synchronized void getBoardWithMatchingVidPidFromCloud(String vid, String pid) {
    // this method is less useful in Windows < WIN10 since you need drivers to be already installed
    ObjectMapper mapper = new ObjectMapper();
    mapper.configure(DeserializationFeature.FAIL_ON_UNKNOWN_PROPERTIES, false);
    try {
      URL jsonUrl = new URL("http", "api-builder.arduino.cc", 80, "/builder/v1/boards/0x"+vid+"/0x"+pid);
      URLConnection connection = jsonUrl.openConnection();
      connection.connect();
      HttpURLConnection httpConnection = (HttpURLConnection) connection;
      int code = httpConnection.getResponseCode();
      if (code == 404) {
        return;
      }
      InputStream is = httpConnection.getInputStream();
      BoardCloudAPIid board = mapper.readValue(is, BoardCloudAPIid.class);
      // Launch a popup with a link to boardmanager#board.getName()
      // replace spaces with &
      String realBoardName = board.getName().replaceAll("\\(.*?\\)", "").trim();
      String boardNameReplaced = realBoardName.replaceAll(" ", "&");
      String message = I18n.format(tr("{0}Install{1} the package to use your {2}"), "<a href=\"http://boardsmanager/all#"+boardNameReplaced+"\">", "</a>", realBoardName);
      BaseNoGui.setBoardManagerLink(message);
    } catch (Exception e) {
      // No connection no problem, fail silently
      //e.printStackTrace();
    }
  }

  public synchronized Map<String, Object> resolveDeviceByVendorIdProductId(String serial, Map<String, TargetPackage> packages) {
    String vid_pid_iSerial = resolveDeviceAttachedToNative(serial);
    for (TargetPackage targetPackage : packages.values()) {
      for (TargetPlatform targetPlatform : targetPackage.getPlatforms().values()) {
        for (TargetBoard board : targetPlatform.getBoards().values()) {
          List<String> vids = new LinkedList<>(board.getPreferences().subTree("vid", 1).values());
          if (!vids.isEmpty()) {
            List<String> pids = new LinkedList<>(board.getPreferences().subTree("pid", 1).values());
            for (int i = 0; i < vids.size(); i++) {
              String vidPid = vids.get(i) + "_" + pids.get(i);
              if (vid_pid_iSerial.toUpperCase().contains(vidPid.toUpperCase())) {
                Map<String, Object> boardData = new HashMap<>();
                boardData.put("board", board);
                boardData.put("vid", vids.get(i));
                boardData.put("pid", pids.get(i));
                boardData.put("iserial", vid_pid_iSerial.substring(vidPid.length()+1));
                return boardData;
              }
            }
          }
        }
      }
    }
    return null;
  }

  public String resolveDeviceByBoardID(Map<String, TargetPackage> packages, String boardId) {
    assert packages != null;
    assert boardId != null;
    for (TargetPackage targetPackage : packages.values()) {
      for (TargetPlatform targetPlatform : targetPackage.getPlatforms().values()) {
        for (TargetBoard board : targetPlatform.getBoards().values()) {
          if (boardId.equals(board.getId())) {
            return board.getName();
          }
        }
      }
    }
    return null;
  }

  // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

  public String getName() {
    return PConstants.platformNames[PConstants.OTHER];
  }


  // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .  


  protected void showLauncherWarning() {
    BaseNoGui.showWarning(tr("No launcher available"),
      tr("Unspecified platform, no launcher available.\nTo enable opening URLs or folders, add a \n\"launcher=/path/to/app\" line to preferences.txt"),
      null);
  }

  public List<BoardPort> filterPorts(List<BoardPort> ports, boolean aBoolean) {
    return new LinkedList<>(ports);
  }

  public void fixPrefsFilePermissions(File prefsFile) throws IOException, InterruptedException {
    Process process = Runtime.getRuntime().exec(new String[]{"chmod", "600", prefsFile.getAbsolutePath()}, null, null);
    process.waitFor();
  }

  public List<File> postInstallScripts(File folder) {
    List<File> scripts = new LinkedList<>();
    scripts.add(new File(folder, "install_script.sh"));
    scripts.add(new File(folder, "post_install.sh"));
    return scripts;
  }

  public List<File> preUninstallScripts(File folder) {
    List<File> scripts = new LinkedList<>();
    scripts.add(new File(folder, "pre_uninstall.sh"));
    return scripts;
  }

  public String getOsName() {
    return System.getProperty("os.name");
  }

  public String getOsArch() {
    return System.getProperty("os.arch");
  }

  public void symlink(String something, File somewhere) throws IOException, InterruptedException {
    Process process = Runtime.getRuntime().exec(new String[]{"ln", "-s", something, somewhere.getAbsolutePath()}, null, somewhere.getParentFile());
    process.waitFor();
  }

  public void link(File something, File somewhere) throws IOException, InterruptedException {
    Process process = Runtime.getRuntime().exec(new String[]{"ln", something.getAbsolutePath(), somewhere.getAbsolutePath()}, null, null);
    process.waitFor();
  }

  public void chmod(File file, int mode) throws IOException, InterruptedException {
    Process process = Runtime.getRuntime().exec(new String[]{"chmod", Integer.toOctalString(mode), file.getAbsolutePath()}, null, null);
    process.waitFor();
  }

  public void fixSettingsLocation() throws Exception {
    //noop
  }
}
