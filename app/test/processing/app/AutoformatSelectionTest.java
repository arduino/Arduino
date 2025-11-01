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

package processing.app;

import org.fest.swing.fixture.JMenuItemFixture;
import org.junit.Test;
import processing.app.helpers.SketchTextAreaFixture;

import static org.junit.Assert.assertEquals;

public class AutoformatSelectionTest extends AbstractGUITest {

  private static String orig = "/**\n" + 
      "  *Docs..\n" + 
      "  */\n" + 
      "void loop() {\n" + 
      "  // LED ON\n" + 
      "digitalWrite(LED_BUILTIN, HIGH);\n" + 
      "if (true) {\n" + 
      "  delay(   1000)\n" + 
      "};\n" + 
      "  digitalWrite(LED_BUILTIN, LOW);\n" + 
      "  if (true) {delay(   1000    )}; // <<< UGLY FORMATTING\n" + 
      "}";
  
  
  @Test
  public void testSuite() {
    
    selectIfMultilineCorrectSel();
    selectIfMultilineCorrectPartialSel();
    selectIfMultilineDocs();
    selectIfSinglelineDocs();
    
  }
  
  /**
   *  select all if block   
   */
  public void selectIfMultilineCorrectSel() {
    
    
    String espected = "/**\n" + 
        "  *Docs..\n" + 
        "  */\n" + 
        "void loop() {\n" + 
        "  // LED ON\n" + 
        "digitalWrite(LED_BUILTIN, HIGH);\n" + 
        "  if (true) {\n" + 
        "    delay(   1000)\n" + 
        "  };\n" + 
        "  digitalWrite(LED_BUILTIN, LOW);\n" + 
        "  if (true) {delay(   1000    )}; // <<< UGLY FORMATTING\n" + 
        "}";
    
    validateFormat(78, 109, orig, espected); 
    
  }
  
  
  /**
   * selection starts in if (|true) and goto '}'
   * expected: format entry block
   */
  public void selectIfMultilineCorrectPartialSel() {
    
    String espected = "/**\n" + 
        "  *Docs..\n" + 
        "  */\n" + 
        "void loop() {\n" + 
        "  // LED ON\n" + 
        "digitalWrite(LED_BUILTIN, HIGH);\n" + 
        "  if (true) {\n" + 
        "    delay(   1000)\n" + 
        "  };\n" + 
        "  digitalWrite(LED_BUILTIN, LOW);\n" + 
        "  if (true) {delay(   1000    )}; // <<< UGLY FORMATTING\n" + 
        "}";
    
    validateFormat(81, 109, orig, espected); 
    
  }
  
  /**
   * selection starts in multiple docs /** *\/
   * expected: format entry block
   */
  public void selectIfMultilineDocs() {
    
    String espected = "/**\n" + 
        "   Docs..\n" + 
        "*/\n" + 
        "void loop() {\n" + 
        "  // LED ON\n" + 
        "  digitalWrite(LED_BUILTIN, HIGH);\n" + 
        "if (true) {\n" + 
        "  delay(   1000)\n" + 
        "};\n" + 
        "  digitalWrite(LED_BUILTIN, LOW);\n" + 
        "  if (true) {delay(   1000    )}; // <<< UGLY FORMATTING\n" + 
        "}";
    
    validateFormat(9, 51, orig, espected); 
    
  }
  
  /**
   * selection starts in single line coment // LED |ON
   * expected: format comment
   */
  public void selectIfSinglelineDocs() {
    
    String espected = "/**\n" + 
        "  *Docs..\n" + 
        "  */\n" + 
        "void loop() {\n" + 
        "  // LED ON\n" + 
        "  digitalWrite(LED_BUILTIN, HIGH);\n" + 
        "if (true) {\n" + 
        "  delay(   1000)\n" + 
        "};\n" + 
        "  digitalWrite(LED_BUILTIN, LOW);\n" + 
        "  if (true) {delay(   1000    )}; // <<< UGLY FORMATTING\n" + 
        "}";
    
    validateFormat(42, 56, orig, espected); 
    
  }
  
 
  public SketchTextAreaFixture validateFormat(int selStart, int selEnd, String orig, String espected) {
      JMenuItemFixture menuToolsAutoFormat = window.menuItem("menuToolsAutoFormat");
      menuToolsAutoFormat.requireEnabled();
      SketchTextAreaFixture editor = window.textArea("editor");
    
      editor.setText(orig);
  
      editor.select(selStart, selEnd); // select frist if
  
      menuToolsAutoFormat.click();
  
      assertEquals(espected, editor.getText());
  
      return editor;
    }

}
