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

package processing.app.windows;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.StringReader;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * Interprets the output of listComPorts.exe
 * <p>
 * https://github.com/todbot/usbSearch/
 */
public class ListComPortsParser {

  private final Pattern vidRegExp;
  private final Pattern pidRegExp;

  public ListComPortsParser() {
    vidRegExp = Pattern.compile("VID_(\\w\\w\\w\\w)");
    pidRegExp = Pattern.compile("PID_(\\w\\w\\w\\w)");
  }

  public String extractVIDAndPID(String output, String serial) throws IOException {
    BufferedReader reader = new BufferedReader(new StringReader(output));
    String line;
    while ((line = reader.readLine()) != null) {
      String[] lineParts = line.split(" ");
      if (lineParts.length > 0 && lineParts[0].toUpperCase().equals(serial.toUpperCase())) {
        String vidPidPart = lineParts[lineParts.length - 1];
        Matcher vidMatcher = vidRegExp.matcher(vidPidPart);
        Matcher pidMatcher = pidRegExp.matcher(vidPidPart);
        if (vidMatcher.find() && pidMatcher.find()) {
          return ("0x" + vidMatcher.group(1) + "_0x" + pidMatcher.group(1)).toUpperCase();
        }
      }
    }

    return null;
  }

}
