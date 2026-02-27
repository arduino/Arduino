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

import processing.app.I18n;
import processing.app.debug.MessageConsumer;

import java.io.PrintStream;
import java.util.Map;

import static processing.app.I18n.tr;

public class I18NAwareMessageConsumer implements MessageConsumer {

  private final PrintStream out;
  private final PrintStream err;
  private final MessageConsumer parent;
  private final ExternalProcessOutputParser parser;

  public I18NAwareMessageConsumer(PrintStream out) {
    this(out, out, null);
  }

  public I18NAwareMessageConsumer(PrintStream out, MessageConsumer parent) {
    this(out, out, parent);
  }

  public I18NAwareMessageConsumer(PrintStream out, PrintStream err) {
    this(out, err, null);
  }

  public I18NAwareMessageConsumer(PrintStream out, PrintStream err, MessageConsumer parent) {
    this.out = out;
    this.err = err;
    this.parent = parent;
    this.parser = new ExternalProcessOutputParser();
  }

  @Override
  public void message(String s) {
    if (s.startsWith("===")) {
      Map<String, Object> parsedMessage = parser.parse(s);
      String translatedMessage = I18n.format(tr((String) parsedMessage.get("msg")), (Object[]) parsedMessage.get("args"));
      if (!parsedMessage.containsKey("level") || "".equals(parsedMessage.get("level")) || "info".equals(parsedMessage.get("level"))) {
        out.println(translatedMessage);
      } else {
        err.println(translatedMessage);
      }
      return;
    }

    if (parent != null) {
      parent.message(s);
    } else {
      out.println(s);
    }
  }
}
