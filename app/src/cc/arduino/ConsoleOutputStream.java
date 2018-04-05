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
 *
 * Original version of this file courtesy of Rob Camick
 * <p>
 * https://tips4java.wordpress.com/2008/11/08/message-console/
 * <p>
 * About page at https://tips4java.wordpress.com/about/ says something
 * like MIT
 */

package cc.arduino;

import processing.app.EditorConsole;

import javax.swing.*;
import javax.swing.text.BadLocationException;
import javax.swing.text.SimpleAttributeSet;
import java.io.ByteArrayOutputStream;
import java.io.PrintStream;

/*
 *  Class to intercept output from a PrintStream and add it to a Document.
 *  The output can optionally be redirected to a different PrintStream.
 *  The text displayed in the Document can be color coded to indicate
 *  the output source.
 */
public class ConsoleOutputStream extends ByteArrayOutputStream {

  private final SimpleAttributeSet attributes;
  private final PrintStream printStream;
  private final Timer timer;

  private volatile EditorConsole editorConsole;
  private volatile boolean newLinePrinted;

  public ConsoleOutputStream(SimpleAttributeSet attributes, PrintStream printStream) {
    this.attributes = attributes;
    this.printStream = printStream;
    this.newLinePrinted = false;

    this.timer = new Timer(100, (e) -> {
      if (editorConsole != null && newLinePrinted) {
        editorConsole.scrollDown();
        newLinePrinted = false;
      }
    });
    timer.setRepeats(false);
  }

  public void setCurrentEditorConsole(EditorConsole console) {
    this.editorConsole = console;
  }

  public synchronized void flush() {
    String text = toString();

    if (text.length() == 0) {
      return;
    }

    printStream.print(text);
    printInConsole(text);

    reset();
  }

  private void printInConsole(String text) {
    newLinePrinted = newLinePrinted || text.contains("\n");
    if (editorConsole != null) {
      SwingUtilities.invokeLater(() -> {
        try {
          editorConsole.insertString(text, attributes);
        } catch (BadLocationException ble) {
          //ignore
        }
      });

      if (!timer.isRunning()) {
        timer.restart();
      }
    }
  }
}
