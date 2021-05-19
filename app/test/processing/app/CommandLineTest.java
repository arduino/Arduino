/*
 * This file is part of Arduino.
 *
 * Copyright 2017 Arduino LLC (http://www.arduino.cc/)
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

import static org.junit.Assert.*;

import java.io.File;
import java.io.IOException;
import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

import org.apache.commons.compress.utils.IOUtils;
import org.fest.assertions.Assertions;
import org.junit.BeforeClass;
import org.junit.Test;

import processing.app.helpers.OSUtils;
import processing.app.helpers.PreferencesMap;

/**
 * This extends AbstractWithPreferencesTest which initializes part of
 * the internal Arduino structures. Most of that is not required, but it
 * also conveniently sets up a settings directory and preferences file,
 * which we can use here (through getBaseArgs()).
 */
public class CommandLineTest extends AbstractWithPreferencesTest {

  private static File buildPath;
  private static File arduinoPath;

  @BeforeClass
  public static void findBuildPaths() throws Exception {
    buildPath = new File(System.getProperty("user.dir"));
    while (!new File(buildPath, "build").isDirectory()) {
      buildPath = buildPath.getParentFile();
      if (buildPath == null) {
        throw new Exception("Could not determine build path");
      }
    }
    System.out.println("found buildpath: " + buildPath);
    if (OSUtils.isLinux()) {
      arduinoPath = new File(buildPath, "build/linux/work/arduino");
    }
    if (OSUtils.isWindows()) {
      arduinoPath = new File(buildPath, "build/windows/work/arduino.exe");
    }
    if (OSUtils.isMacOS()) {
      arduinoPath = new File(buildPath,
          "build/macosx/work/Arduino.app/Contents/MacOS/Arduino");
    }
    if (!arduinoPath.canExecute()) {
      throw new Exception("Could not determine arduino location");
    }
    System.out.println("found arduino: " + arduinoPath);
  }

  public Process runArduino(boolean output, boolean success, File wd, String[] extraArgs) throws IOException, InterruptedException {
    Runtime rt = Runtime.getRuntime();

    List<String> args = new ArrayList<String>();
    args.add(arduinoPath.getAbsolutePath());
    args.addAll(Arrays.asList(getBaseArgs()));
    args.addAll(Arrays.asList(extraArgs));

    System.out.println("Running: " + String.join(" ", args));

    Process pr = rt.exec(args.toArray(new String[0]), null, wd);
    if (output) {
      IOUtils.copy(pr.getInputStream(), System.out);
      IOUtils.copy(pr.getErrorStream(), System.out);
    }
    pr.waitFor();
    if (success)
      assertEquals(0, pr.exitValue());
    return pr;
  }

  @Test
  public void testCommandLineBuildWithRelativePath() throws Exception {
    File wd = new File(buildPath, "app/testdata/sketches/Blink/");
    runArduino(true, true, wd, new String[] {
        "--board", "arduino:avr:uno",
        "--verify", "Blink.ino",
    });
  }

  @Test
  public void testCommandLinePreferencesSave() throws Exception {
    File prefFile = File.createTempFile("test_pref", ".txt");
    prefFile.deleteOnExit();

    runArduino(true, true, null, new String[] {
        "--save-prefs",
        "--preferences-file", prefFile.getAbsolutePath(),
        "--version", // avoids starting the GUI
    });

    runArduino(true, true, null, new String[] {
        "--pref", "test_pref=xxx",
        "--preferences-file", prefFile.getAbsolutePath(),
    });

    PreferencesMap prefs = new PreferencesMap(prefFile);
    assertNull("preference should not be saved", prefs.get("test_pref"));

    runArduino(true, true, null, new String[] {
        "--pref", "test_pref=xxx",
        "--preferences-file", prefFile.getAbsolutePath(),
        "--save-prefs",
    });

    prefs = new PreferencesMap(prefFile);
    assertEquals("preference should be saved", "xxx", prefs.get("test_pref"));
  }

  @Test
  public void testCommandLineVersion() throws Exception {
    Process pr = runArduino(false, true, null, new String[] {
      "--version",
    });

    Assertions.assertThat(new String(IOUtils.toByteArray(pr.getInputStream())))
        .matches("Arduino: \\d+\\.\\d+\\.\\d+.*\r?\n");
  }

  @Test
  public void testCommandLineMultipleAction() throws Exception {
    Process pr = runArduino(true, false, null, new String[] {
      "--version",
      "--verify",
    });

    Assertions.assertThat(pr.exitValue())
        .as("Multiple Action will be rejected")
        .isEqualTo(3);
  }
}
