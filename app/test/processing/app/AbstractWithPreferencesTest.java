/*
 * This file is part of Arduino.
 *
 * Copyright 2015 Arduino LLC (http://www.arduino.cc/)
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

package processing.app;

import static org.junit.Assert.assertEquals;
import org.junit.Before;
import org.junit.After;

import processing.app.helpers.FileUtils;

import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.util.Random;
import java.util.List;
import java.util.LinkedList;

public abstract class AbstractWithPreferencesTest {
  /**
   * Files or directories that will be deleted after each test.
   * Subclasses can add files here in @Test or @Before functions.
   */
  protected List<File> deleteAfter = new LinkedList<File>();
  protected File preferencesFile;

  @Before
  public void init() throws Exception {
    File settingsDir = Files.createTempDirectory("arduino_test_settings").toFile();
    deleteAfter.add(settingsDir);

    preferencesFile = new File(settingsDir, "preferences.txt");
    File sketchbookDir = new File(settingsDir, "sketchbook");
    sketchbookDir.mkdir();

    BaseNoGui.initPlatform();
    BaseNoGui.getPlatform().init();

    PreferencesData.init(preferencesFile);
    // Do not read anything from e.g. ~/.arduino15
    PreferencesData.set("settings.path", settingsDir.toString());
    // Do not read or write the default ~/Arduino sketchbook
    PreferencesData.set("sketchbook.path", sketchbookDir.toString());
    // Do not perform any update checks
    PreferencesData.set("update.check", sketchbookDir.toString());
    // Write the defaults, with these changes to file. This allows them
    // to be reloaded when creating a Base instance (see getBaseArgs()
    // below).
    PreferencesData.save();

    Theme.init();

    BaseNoGui.initPackages();

    Base.untitledFolder = FileUtils.createTempFolder("untitled" + new Random().nextInt(Integer.MAX_VALUE), ".tmp");
    deleteAfter.add(Base.untitledFolder);
  }

  /**
   * Returns arguments to be passed to the Base constructor or on the
   * commandline to set up the created dummy environment.
   */
  protected String[] getBaseArgs() {
    return new String[] {
      // Preferences are loaded (using --preferences-file) before
      // processing any other commandline options (e.g. --pref), so only
      // use --preferences-file here. Also, this does not affect the
      // "action" mode, for tests that require the GUI to be loaded.
      "--preferences-file", preferencesFile.toString(),
    };
  }

  /**
   * Creates a new instance of Base. Always use this rather than calling
   * it directly, to ensure the right settings are used.
   */
  protected Base createBase() throws Exception {
    Base base = new Base(getBaseArgs());
    // Doublecheck that the right preferencesFile was loaded
    assertEquals(preferencesFile, PreferencesData.preferencesFile);
    return base;
  }

  @After
  public void cleanup() throws IOException {
    for (File f : deleteAfter)
      FileUtils.recursiveDelete(f);
    deleteAfter = new LinkedList<File>();
  }
}
