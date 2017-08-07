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

package cc.arduino.autocomplete;

import java.util.ArrayList;
import java.util.List;

public class ArduinoCompletionsList extends ArrayList<ArduinoCompletion> {
}

class ArduinoCompletion {
  ArduinoCompletionDetail completion;
  String type;
  String location;
  List<ArduinoParameter> parameters;

  public ArduinoCompletionDetail getCompletion() {
    return completion;
  }

  public String getType() {
    return type;
  }

  public String getLocation() {
    return location;
  }

  public List<ArduinoParameter> getParameters() {
    return parameters;
  }
}

class ArduinoParameter {
  String name;
  String type;

  public String getName() {
    return name;
  }

  public String getType() {
    return type;
  }
}

class ArduinoCompletionDetail {
  List<CompletionChunk> chunks;
  String brief;

  public List<CompletionChunk> getChunks() {
    return chunks;
  }

  public String getBrief() {
    return brief;
  }

  public String getResultType() {
    for (CompletionChunk c : chunks) {
      if (c.res != null)
        return c.res;
    }
    return null;
  }

  public String getTypedText() {
    for (CompletionChunk c : chunks) {
      if (c.typedtext != null)
        return c.typedtext;
    }
    return null;
  }
}

class CompletionChunk {
  String typedtext;
  String t;
  String placeholder;
  String res;
  String info;
  ArduinoCompletionDetail optional;

  public String getTypedtext() {
    return typedtext;
  }

  public String getT() {
    return t;
  }

  public String getPlaceholder() {
    return placeholder;
  }

  public String getRes() {
    return res;
  }

  public ArduinoCompletionDetail getOptional() {
    return optional;
  }

  public String getInfo() {
    return info;
  }
}