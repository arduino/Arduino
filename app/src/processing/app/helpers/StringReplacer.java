/* -*- mode: jde; c-basic-offset: 2; indent-tabs-mode: nil -*- */
/*
 StringReplacer - Utility class for expression formatting
 Part of the Arduino project - http://www.arduino.cc/

 Copyright (c) 2011 Cristian Maglie

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

 $Id$
 */
package processing.app.helpers;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

public class StringReplacer {

  public static String[] formatAndSplit(String src, Map<String, String> dict,
                                        boolean recursive) throws Exception {
    String res;

    // Recursive replace with a max depth of 10 levels.
    for (int i=0; i<10; i++) {
      // Do a replace with dictionary
      res = StringReplacer.replaceFromMapping(src, dict);
      if (!recursive)
        break;
      if (res.equals(src))
        break;
      src = res;
    }

    // Split the resulting string in arguments
    return quotedSplit(src, '"');
  }

  // Split a string into a list of space-delimited arguments
  //
  // Arguments containing spaces can be escaped by quoting with 'quoteChar'.
  // Arguments entirely enclosed by 'quoteChar' will have quotes stripped,
  // arguments where quoteChar is inside another part of the argument string (ie -DNAME="VALUE PARTS")
  // will have the quotes retained.
  public static String[] quotedSplit(String src, char quoteChar)
      throws Exception {
    List<String> res = new ArrayList<String>();
    String arg = "";
    boolean quoting = false;
    boolean quoting_instr = false;

    for(char c : src.toCharArray()) {
      if(quoting) {
        if(c == quoteChar) {
          if(quoting_instr)
            arg += quoteChar;
          res.add(arg);
          arg = "";
          quoting = false;
        } else {
          arg += c;
        }
      }
      else { // not quoting
        if(c == ' ') {
          res.add(arg);
          arg = "";
        } else if(c == quoteChar) {
          quoting = true;
          quoting_instr = arg.length() > 0;
          if(quoting_instr)
            arg += quoteChar;
        } else {
          arg += c;
        }
      }
    }

    if (quoting)
      throw new Exception("Invalid quoting: no closing '" + quoteChar +
          "' char found.");
    return res.toArray(new String[0]);
  }

  public static String replaceFromMapping(String src, Map<String, String> map) {
    return replaceFromMapping(src, map, "{", "}");
  }

  public static String replaceFromMapping(String src, Map<String, String> map,
                                          String leftDelimiter,
                                          String rightDelimiter) {
    for (String k : map.keySet()) {
      String keyword = leftDelimiter + k + rightDelimiter;
      src = src.replace(keyword, map.get(k));
    }
    return src;
  }

}
