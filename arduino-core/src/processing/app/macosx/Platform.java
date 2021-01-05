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

package processing.app.macosx;

import cc.arduino.packages.BoardPort;
import com.apple.eio.FileManager;
import org.apache.commons.exec.CommandLine;
import org.apache.commons.exec.DefaultExecutor;
import org.apache.commons.exec.Executor;
import org.apache.commons.exec.PumpStreamHandler;
import org.apache.commons.lang3.StringUtils;
import processing.app.legacy.PApplet;
import processing.app.legacy.PConstants;

import java.awt.*;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.net.URI;
import java.util.LinkedList;
import java.util.List;


/**
 * Platform handler for Mac OS X.
 */
public class Platform extends processing.app.Platform {

  private String osArch;

  @Override
  public void setLookAndFeel() throws Exception {
  }

  public Platform() {
    // For more information see:
    // http://mail.openjdk.java.net/pipermail/macosx-port-dev/2013-January/005261.html
    Toolkit.getDefaultToolkit();
  }

  @Override
  public void init() throws Exception {
    super.init();
    discoverRealOsArch();
  }

  private void discoverRealOsArch() throws IOException {
    CommandLine uname = CommandLine.parse("uname -m");
    ByteArrayOutputStream baos = new ByteArrayOutputStream();
    Executor executor = new DefaultExecutor();
    executor.setStreamHandler(new PumpStreamHandler(baos, null));
    executor.execute(uname);
    osArch = StringUtils.trim(new String(baos.toByteArray()));
  }


  @Override
  public File getSettingsFolder() throws Exception {
    return new File(getLibraryFolder(), "Arduino15");
  }


  @Override
  public File getDefaultSketchbookFolder() throws Exception {
    return new File(getDocumentsFolder(), "Arduino");
    /*
    // looking for /Users/blah/Documents/Processing
    try {
      Class clazz = Class.forName("processing.app.BaseMacOS");
      Method m = clazz.getMethod("getDocumentsFolder", new Class[] { });
      String documentsPath = (String) m.invoke(null, new Object[] { });
      sketchbookFolder = new File(documentsPath, "Arduino");

    } catch (Exception e) {
      sketchbookFolder = promptSketchbookLocation();
    }
    */
  }


  @Override
  public void openURL(String url) throws Exception {
    Desktop desktop = Desktop.getDesktop();
    if (url.startsWith("http") || url.startsWith("file:")) {
      desktop.browse(new URI(url));
    } else {
      desktop.open(new File(url));
    }
  }


  @Override
  public boolean openFolderAvailable() {
    return true;
  }


  @Override
  public void openFolder(File file) throws Exception {
    //openURL(file.getAbsolutePath());  // handles char replacement, etc
    PApplet.open(file.getAbsolutePath());
  }


  // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .


  // Some of these are supposedly constants in com.apple.eio.FileManager,
  // however they don't seem to link properly from Eclipse.

  private static final int kDocumentsFolderType =
    ('d' << 24) | ('o' << 16) | ('c' << 8) | 's';
  //static final int kPreferencesFolderType =
  //  ('p' << 24) | ('r' << 16) | ('e' << 8) | 'f';
  private static final int kDomainLibraryFolderType =
    ('d' << 24) | ('l' << 16) | ('i' << 8) | 'b';
  private static final short kUserDomain = -32763;


  // apple java extensions documentation
  // http://developer.apple.com/documentation/Java/Reference/1.5.0
  //   /appledoc/api/com/apple/eio/FileManager.html

  // carbon folder constants
  // http://developer.apple.com/documentation/Carbon/Reference
  //   /Folder_Manager/folder_manager_ref/constant_6.html#/
  //   /apple_ref/doc/uid/TP30000238/C006889

  // additional information found int the local file:
  // /System/Library/Frameworks/CoreServices.framework
  //   /Versions/Current/Frameworks/CarbonCore.framework/Headers/


  private String getLibraryFolder() throws FileNotFoundException {
    return FileManager.findFolder(kUserDomain, kDomainLibraryFolderType);
  }


  private String getDocumentsFolder() throws FileNotFoundException {
    return FileManager.findFolder(kUserDomain, kDocumentsFolderType);
  }

  @Override
  public String getName() {
    return PConstants.platformNames[PConstants.MACOSX];
  }

  @Override
  public java.util.List<BoardPort> filterPorts(java.util.List<BoardPort> ports, boolean showAll) {
    if (showAll) {
      return super.filterPorts(ports, true);
    }

    List<BoardPort> filteredPorts = new LinkedList<>();
    for (BoardPort port : ports) {
      if (!port.getAddress().startsWith("/dev/tty.")) {
        filteredPorts.add(port);
      }
    }

    return filteredPorts;
  }

  @Override
  public String getOsArch() {
    return osArch;
  }
}
