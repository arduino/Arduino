/* -*- mode: java; c-basic-offset: 2; indent-tabs-mode: nil -*- */

/*
  Part of the Processing project - http://processing.org

  Copyright (c) 2005-06 Ben Fry and Casey Reas

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

import static processing.app.I18n.tr;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.URL;
import java.net.URLEncoder;
import java.nio.file.Files;
import java.nio.file.StandardCopyOption;
import java.util.List;
import java.util.Random;
import java.util.stream.Collectors;

import javax.swing.JOptionPane;

import org.apache.commons.compress.utils.IOUtils;

import processing.app.legacy.PApplet;


/**
 * Threaded class to check for updates in the background.
 * <P>
 * This is the class that handles the mind control and stuff for
 * spying on our users and stealing their personal information.
 * A random ID number is generated for each user, and hits the server
 * to check for updates. Also included is the operating system and
 * its version and the version of Java being used to run Processing.
 * <P>
 * The ID number also helps provide us a general idea of how many
 * people are using Processing, which helps us when writing grant
 * proposals and that kind of thing so that we can keep Processing free.
 */
public class UpdateCheck implements Runnable {
  Base base;

  public UpdateCheck(Base base) {
    Thread thread = new Thread(this);
    this.base = base;
    thread.start();
  }

  public void run() {
    // Ensure updates-check are made only once per day
    Long when = PreferencesData.getLong("update.last");
    long now = System.currentTimeMillis();
    final long ONE_DAY = 24 * 60 * 60 * 1000;
    if (when != null && (now - when) < ONE_DAY) {
      // don't annoy the shit outta people
      return;
    }
    PreferencesData.setLong("update.last", now);

    // Set update id
    Long id = PreferencesData.getLong("update.id");
    if (id == null) {
      // generate a random id in case none exists yet
      Random r = new Random();
      id = r.nextLong();
      PreferencesData.setLong("update.id", id);
    }

    // Check for updates of the IDE
    try {
      String info;
      info = URLEncoder.encode(id + "\t" +
                        PApplet.nf(BaseNoGui.REVISION, 4) + "\t" +
                        System.getProperty("java.version") + "\t" +
                        System.getProperty("java.vendor") + "\t" +
                        System.getProperty("os.name") + "\t" +
                        System.getProperty("os.version") + "\t" +
                        System.getProperty("os.arch"), "UTF-8");
      
      int latest = readIntFromURL("https://www.arduino.cc/latest.txt?" + info);

      String prompt =
        tr("A new version of Arduino is available,\n" +
          "would you like to visit the Arduino download page?");
        
      if (base.activeEditor != null) {
        if (latest > BaseNoGui.REVISION) {
          Object[] options = { tr("Yes"), tr("No") };
          int result = JOptionPane.showOptionDialog(base.activeEditor,
                                                    prompt,
                                                    tr("Update"),
                                                    JOptionPane.YES_NO_OPTION,
                                                    JOptionPane.QUESTION_MESSAGE,
                                                    null,
                                                    options,
                                                    options[0]);
          if (result == JOptionPane.YES_OPTION) {
            Base.openURL("https://www.arduino.cc/en/Main/Software");
          }
        }
      }
    } catch (Exception e) {
      //e.printStackTrace();
      //System.err.println("Error while trying to check for an update.");
    }
  }


  protected int readIntFromURL(String _url) throws Exception {
    List<String> lines = readFileFromURL(_url);
    return Integer.parseInt(lines.get(0));
  }

  protected List<String> readFileFromURL(String _url) throws IOException {
    URL url = new URL(_url);
    try (BufferedReader in = new BufferedReader(new InputStreamReader(url.openStream()));) {
      return in.lines().collect(Collectors.toList());
    }
  }

  protected void downloadFileFromURL(String _url, File dest) throws IOException {
    URL url = new URL(_url);
    try (InputStream in = url.openStream()) {
      try (FileOutputStream out = new FileOutputStream(dest)) {
        IOUtils.copy(in, out);
      }
    }
  }
}
