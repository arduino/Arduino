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

package cc.arduino.i18n;

import org.junit.Test;

import java.util.Map;

import static org.junit.Assert.assertEquals;

public class ExternalProcessOutputParserTest {

  @Test
  public void testParser1() throws Exception {
    Map<String, Object> output = new ExternalProcessOutputParser().parse("===WARNING: Category '{0}' in library {1} is not valid. Setting to '{2}' ||| [ Wire Uncategorized]");

    assertEquals("WARNING: Category '{0}' in library {1} is not valid. Setting to '{2}'", output.get("msg"));
    Object[] args = (Object[]) output.get("args");
    assertEquals(3, args.length);
    assertEquals("", args[0]);
    assertEquals("Wire", args[1]);
    assertEquals("Uncategorized", args[2]);
  }

  @Test
  public void testParser2() throws Exception {
    Map<String, Object> output = new ExternalProcessOutputParser().parse("===Using previously compiled file: {0} ||| [%2Ftmp%2Farduino-sketch-456612873D8321DA02916066CB8B2FE6%2Flibraries%2FBridge%2FBridge.cpp.o]");

    assertEquals("Using previously compiled file: {0}", output.get("msg"));
    Object[] args = (Object[]) output.get("args");
    assertEquals(1, args.length);
    assertEquals("/tmp/arduino-sketch-456612873D8321DA02916066CB8B2FE6/libraries/Bridge/Bridge.cpp.o", args[0]);
  }

  @Test
  public void testParser3() throws Exception {
    Map<String, Object> output = new ExternalProcessOutputParser().parse("===Using library {0} at version {1} in folder: {2} {3} {4} ||| [Stepper 1.1.1 %2Fhome%2Ffederico%2Fmateriale%2Fworks_Arduino%2FArduino%2Fbuild%2Flinux%2Fwork%2Flibraries%2FStepper  ]");

    assertEquals("Using library {0} at version {1} in folder: {2} {3} {4}", output.get("msg"));
    Object[] args = (Object[]) output.get("args");
    assertEquals(5, args.length);
    assertEquals("Stepper", args[0]);
    assertEquals("1.1.1", args[1]);
    assertEquals("/home/federico/materiale/works_Arduino/Arduino/build/linux/work/libraries/Stepper", args[2]);
    assertEquals("", args[3]);
    assertEquals("", args[4]);
  }

  @Test
  public void testParser4() throws Exception {
    Map<String, Object> output = new ExternalProcessOutputParser().parse("==={0} ||| []");

    assertEquals("{0}", output.get("msg"));
    Object[] args = (Object[]) output.get("args");
    assertEquals(0, args.length);
  }

  @Test
  public void testParser5() throws Exception {
    Map<String, Object> output = new ExternalProcessOutputParser().parse("==={0} ||| [ ]");

    assertEquals("{0}", output.get("msg"));
    Object[] args = (Object[]) output.get("args");
    assertEquals(1, args.length);
    assertEquals("", args[0]);
  }

  @Test
  public void testParser6() throws Exception {
    Map<String, Object> output = new ExternalProcessOutputParser().parse("===info ||| Progress {0} ||| [79.31]");

    assertEquals("info", output.get("level"));
    assertEquals("Progress {0}", output.get("msg"));
    Object[] args = (Object[]) output.get("args");
    assertEquals(1, args.length);
    assertEquals("79.31", args[0]);
  }

  @Test
  public void testParser7() throws Exception {
    Map<String, Object> output = new ExternalProcessOutputParser().parse("===info ||| Using library {0} at version {1} in folder: {2} {3} ||| [Bridge 1.6.0 %2Fhome%2Ffederico%2Fmateriale%2Fworks_Arduino%2FArduino%2Fbuild%2Flinux%2Fwork%2Flibraries%2FBridge ]");

    assertEquals("info", output.get("level"));
    assertEquals("Using library {0} at version {1} in folder: {2} {3}", output.get("msg"));
    Object[] args = (Object[]) output.get("args");
    assertEquals(4, args.length);
    assertEquals("Bridge", args[0]);
    assertEquals("1.6.0", args[1]);
    assertEquals("/home/federico/materiale/works_Arduino/Arduino/build/linux/work/libraries/Bridge", args[2]);
    assertEquals("", args[3]);
  }

}
