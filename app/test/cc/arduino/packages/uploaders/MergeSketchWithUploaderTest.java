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

package cc.arduino.packages.uploaders;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import processing.app.helpers.FileUtils;

import java.io.File;
import java.net.URLDecoder;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.util.List;

import static org.junit.Assert.assertEquals;

public class MergeSketchWithUploaderTest {

  private File sketch;
  private File bootloader;

  @Before
  public void setup() throws Exception {
    File originalSketch = getResourceFile("/sketch.hex");
    sketch = new File(System.getProperty("java.io.tmpdir"), "sketch.hex");
    FileUtils.copyFile(originalSketch, sketch);
    removeCariageReturns(sketch);
    
    File originalBootloader = getResourceFile("/optiboot_atmega328.hex");
    bootloader = new File(System.getProperty("java.io.tmpdir"), "optiboot_atmega328.hex");
    FileUtils.copyFile(originalBootloader, bootloader);
    removeCariageReturns(bootloader);
  }

  @After
  public void removeTmpFile() {
    sketch.delete();
  }

  @Test
  public void shouldMergeWithOptiboot() throws Exception {
    assertEquals(11720, sketch.length());
    assertEquals(1432, bootloader.length());

    File bootloader = getResourceFile("/optiboot_atmega328.hex");
    new MergeSketchWithBooloader().merge(sketch, bootloader);
    assertEquals(13140, sketch.length());
  }

  private static File getResourceFile(String resourcePath) throws Exception {
    return new File(URLDecoder.decode(
        MergeSketchWithUploaderTest.class.getResource(resourcePath).getFile(), "UTF-8"));
  }

  private static void removeCariageReturns(File file) throws Exception {
    List<String> lines = Files.readAllLines(file.toPath(), StandardCharsets.UTF_8);
    StringBuilder contentBuilder = new StringBuilder();
    for(String line : lines) {
      contentBuilder.append(line).append('\n');
    }
    Files.write(file.toPath(), contentBuilder.toString().getBytes(StandardCharsets.UTF_8));
  }
}
