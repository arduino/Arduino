/*
 * This file is part of Arduino.
 *
 * Copyright 2020 Arduino LLC (http://www.arduino.cc/)
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

import org.junit.Test;

public class SerialTest {
  class NullSerial extends Serial {
    public NullSerial() throws SerialException {
      super("none", 0, 'n', 0, 0, false, false);
    }

    @Override
    protected void message(char[] chars, int length) {
      output += new String(chars, 0, length);
    }

    String output = "";
  }

  @Test
  public void testSerialUTF8Decoder() throws Exception {
    NullSerial s = new NullSerial();
    // https://github.com/arduino/Arduino/issues/9808
    String testdata = "012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789°0123456789";
    s.processSerialEvent(testdata.getBytes());
    assertEquals(s.output, testdata);
  }
}
