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
 */

package cc.arduino.packages.formatter;

import static processing.app.I18n.tr;

import processing.app.Base;
import processing.app.BaseNoGui;
import processing.app.Editor;
import processing.app.helpers.FileUtils;
import processing.app.syntax.SketchTextArea;
import processing.app.tools.Tool;

import java.io.File;
import java.io.IOException;
import java.util.regex.Pattern;
import javax.swing.text.BadLocationException;
import org.fife.ui.rsyntaxtextarea.RSyntaxDocument;
import org.fife.ui.rsyntaxtextarea.Token;

public class AStyle implements Tool {

  private static final String FORMATTER_CONF = "formatter.conf";

  private final AStyleInterface aStyleInterface;
  private final String formatterConfiguration;
  private Editor editor;

  public AStyle() {
    this.aStyleInterface = new AStyleInterface();
    File customFormatterConf = BaseNoGui.getSettingsFile(FORMATTER_CONF);
    File defaultFormatterConf = new File(Base.getContentFile("lib"), FORMATTER_CONF);

    File formatterConf;
    if (customFormatterConf.exists()) {
      formatterConf = customFormatterConf;
    } else {
      formatterConf = defaultFormatterConf;
    }
    String formatterConfiguration = "";

    try {
      formatterConfiguration = FileUtils.readFileToString(formatterConf);
    } catch (IOException e) {
      // ignored
    }
    this.formatterConfiguration = formatterConfiguration;
  }

  @Override
  public void init(Editor editor) {
    this.editor = editor;
  }

  @Override
  public void run() {

    SketchTextArea textArea = editor.getCurrentTab().getTextArea();

    String originalText = textArea.getSelectedText();

    // If no selection use all file
    if (originalText == null || originalText.isEmpty()) {

      String formattedText = aStyleInterface.AStyleMain(textArea.getText(), formatterConfiguration);
      editor.getCurrentTab().setText(formattedText);

    } else {
      try {

        // apply indentation control keywords.
        String FORMAT_ON = "\n// *INDENT-ON* DYN\n";
        String FORMAT_OFF = "\n// *INDENT-OFF* DYN\n";

        RSyntaxDocument content = (RSyntaxDocument) textArea.getDocument();

        textArea.beginAtomicEdit();

        int selStart = editor.getCurrentTab().getSelectionStart();
        int selEnd = editor.getCurrentTab().getSelectionStop();
        int lineStart = textArea.getLineOfOffset(selStart);
        int lineEnd = textArea.getLineOfOffset(selEnd);

        // Calculate offsets from begin and end of each line.
        int fristLineOffset = textArea.getLineStartOffset(lineStart);
        int lastLineOffset = textArea.getLineEndOffset(lineEnd);
        
        // Avoid multi-line comments
        fristLineOffset = navigateOffComments(textArea, fristLineOffset); // try caech (invalid selection)
        lastLineOffset = navigateOffComments(textArea, lastLineOffset); // try caech (invalid selection)
    
        // inserts change the length, use this to calculate new positios.
        int offLength = FORMAT_OFF.length();
        int onLength = FORMAT_ON.length();

        content.insertString(0, FORMAT_OFF, null);
        content.insertString(fristLineOffset + offLength, FORMAT_ON, null);
        content.insertString(lastLineOffset + offLength + onLength, FORMAT_OFF,null);
        originalText = content.getText(0, content.getLength());

        String formattedText = aStyleInterface.AStyleMain(originalText, formatterConfiguration);

        // Remove format tags
        formattedText = formattedText.replaceAll(Pattern.quote(FORMAT_OFF), "");
        formattedText = formattedText.replaceAll(Pattern.quote(FORMAT_ON), "");

        textArea.setText(formattedText);
        textArea.select(selStart, selStart);

      } catch (BadLocationException e) {
        editor.statusNotice(tr("Auto Format Error") + ": " + e.getLocalizedMessage());
        e.printStackTrace();
        return;
      } finally {
        textArea.endAtomicEdit();
      }

    }

    // mark as finished
    editor.statusNotice(tr("Auto Format finished."));
  }
  
  private int navigateOffComments(SketchTextArea textArea, int offset) throws BadLocationException {

    Token token = textArea.modelToToken(offset);

    // if line is a multiline comment, go back !!
    if (token != null && token.getType() == Token.COMMENT_MULTILINE) {

      int lineStart = textArea.getLineOfOffset(offset);
      token = textArea.getTokenListForLine(lineStart);

      while (token.getType() == Token.COMMENT_MULTILINE) {
        if (lineStart == 0)
          break;
        token = token.getNextToken();
        if (token == null)
          token = textArea.getTokenListForLine(--lineStart);
      }

      return token.getOffset();

    } else {
      return offset;
    }
    
  }
  

  @Override
  public String getMenuTitle() {
    return tr("Auto Format");
  }

}
