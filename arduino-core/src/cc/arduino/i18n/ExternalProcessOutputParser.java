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

import java.io.UnsupportedEncodingException;
import java.net.URLDecoder;
import java.util.*;
import java.util.regex.Pattern;
import java.util.stream.Collectors;

public class ExternalProcessOutputParser {

  private static final Pattern SPLIT = Pattern.compile(" \\|\\|\\| ");

  public Map<String, Object> parse(String s) {
    if (!s.startsWith("===")) {
      throw new IllegalArgumentException(s);
    }

    s = s.substring(3);

    Map<String, Object> output = new HashMap<>();

    String[] parts = SPLIT.split(s);

    int idx = 0;
    if (parts.length == 3) {
      output.put("level", parts[idx++]);
    }
    output.put("msg", parts[idx++]);
    output.put("args", parseArgs(parts[idx++]));

    return output;
  }

  private Object[] parseArgs(String argsAsString) {
    if (!argsAsString.startsWith("[") || !argsAsString.endsWith("]")) {
      throw new IllegalArgumentException(argsAsString);
    }

    argsAsString = argsAsString.substring(1, argsAsString.length() - 1);
    if (argsAsString.isEmpty()) {
      return new Object[0];
    }

    List<String> args = new ArrayList<>(Arrays.asList(argsAsString.split(" ")));
    List<String> additionalArgs = addAsManyEmptyArgsAsEndingSpaces(argsAsString, args);

    for (int i = 0; i < args.size(); i++) {
      try {
        args.set(i, URLDecoder.decode(args.get(i), "UTF-8"));
      } catch (UnsupportedEncodingException e) {
        throw new RuntimeException(e);
      }
    }

    args.addAll(additionalArgs);

    return args.toArray();
  }

  private List<String> addAsManyEmptyArgsAsEndingSpaces(String argsAsString, List<String> args) {
    List<String> additionalArgs = new LinkedList<>();

    if (argsAsString.charAt(argsAsString.length() - 1) == ' ') {
      String allArgsButEndingSpacesAsString = args.stream().collect(Collectors.joining(" "));
      String endingSpacesOnly = argsAsString.replace(allArgsButEndingSpacesAsString, "");
      for (int i = 0; i < endingSpacesOnly.length(); i++) {
        additionalArgs.add("");
      }
    }
    return additionalArgs;
  }
}
