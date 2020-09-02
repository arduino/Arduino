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

import org.junit.Before;
import org.junit.Test;

public class EditorConsoleTest extends AbstractWithPreferencesTest {
  private EditorConsole console;

  @Before
  public void createConsole() {
    console = new EditorConsole(null);
  }

  public String escapeString(String input) {
    // This escapes backslashes, newlines and carriage returns, to get
    // more readable assertion failures.
    return input.replace("\\", "\\\\").replace("\n", "\\n").replace("\r", "\\r");
  }

  public void assertOutput(String output) {
    assertEquals(escapeString(output), escapeString(console.getText()));
  }

  @Test
  public void testHelloWorld() throws Exception {
    console.insertString("Hello, world!", null);

    assertOutput("Hello, world!");
  }

  @Test
  public void testCrNlHandling() throws Exception {
    // Do some basic tests with \r\n
    console.insertString("abc\r\ndef", null);
    assertOutput("abc\r\ndef");

    console.insertString("xyz", null);
    assertOutput("abc\r\ndefxyz");

    console.insertString("000\r\n123", null);
    assertOutput("abc\r\ndefxyz000\r\n123");

    console.insertString("\r\n", null);
    assertOutput("abc\r\ndefxyz000\r\n123\r\n");
  }

  @Test
  public void testNlHandling() throws Exception {
    // Basic tests, but with just \n
    console.insertString("abc\ndef", null);
    assertOutput("abc\ndef");

    console.insertString("xyz", null);
    assertOutput("abc\ndefxyz");

    console.insertString("000\n123", null);
    assertOutput("abc\ndefxyz000\n123");

    console.insertString("\n", null);
    assertOutput("abc\ndefxyz000\n123\n");
  }

  @Test
  public void testCrHandling() throws Exception {
    // Then test that single \r clears the current line
    console.clear();
    console.insertString("abc\rdef", null);
    assertOutput("def");

    // A single \r at the end is not added to the document
    console.insertString("\r", null);
    assertOutput("def");

    // Nor are multiple \r at the end
    console.insertString("\r\r\r", null);
    assertOutput("def");

    // But it does clear the line on the next write
    console.insertString("123", null);
    assertOutput("123");

    // Same when combined with some data
    console.insertString("\r456\r\r", null);
    assertOutput("456");

    console.insertString("000", null);
    assertOutput("000");

    // Then add a newline so preceding data is kept
    console.insertString("\r\nxxx\r", null);
    assertOutput("000\r\nxxx");

    // But data after the newline is removed
    console.insertString("yyy", null);
    assertOutput("000\r\nyyy");

    // When a \r\n is split across inserts, it becomes a lone \n
    console.insertString("\r", null);
    assertOutput("000\r\nyyy");
    console.insertString("\n", null);
    assertOutput("000\r\nyyy\n");
  }

  @Test
  public void testCrPartialOverwrite() throws Exception {
    console.insertString("abcdef\r", null);
    assertOutput("abcdef");

    console.insertString("123", null);
    assertOutput("123def");

    console.insertString("4", null);
    assertOutput("1234ef");

    console.insertString("\r\n56", null);
    assertOutput("1234ef\r\n56");
  }

  @Test
  public void testTogether() throws Exception {
    console.insertString("abc\n123456\rdef\rx\r\nyyy\nzzz\r999", null);
    assertOutput("abc\nxef456\r\nyyy\n999");
  }
}
