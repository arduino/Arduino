/*
  Part of the Processing project - http://processing.org

  Copyright (c) 2004-06 Ben Fry and Casey Reas
  Copyright (c) 2001-04 Massachusetts Institute of Technology

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
*/

package processing.app;

import cc.arduino.ConsoleOutputStream;

import javax.swing.*;
import javax.swing.text.*;
import java.awt.*;
import java.io.PrintStream;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import static processing.app.Theme.scale;

/**
 * Message console that sits below the editing area.
 */
public class EditorConsole extends JScrollPane {

  private static ConsoleOutputStream out;
  private static ConsoleOutputStream err;
  private int startOfLine = 0;
  private int insertPosition = 0;

  // Regex for linesplitting, see insertString for comments.
  private static final Pattern newLinePattern = Pattern.compile("([^\r\n]*)([\r\n]*\n)?(\r+)?");

  public static synchronized void setCurrentEditorConsole(EditorConsole console) {
    if (out == null) {
      out = new ConsoleOutputStream(console.stdOutStyle, System.out);
      System.setOut(new PrintStream(out, true));

      err = new ConsoleOutputStream(console.stdErrStyle, System.err);
      System.setErr(new PrintStream(err, true));
    }

    out.setCurrentEditorConsole(console);
    err.setCurrentEditorConsole(console);
  }

  private final DefaultStyledDocument document;
  private final JTextPane consoleTextPane;

  private SimpleAttributeSet stdOutStyle;
  private SimpleAttributeSet stdErrStyle;

  public EditorConsole(Base base) {
    document = new DefaultStyledDocument();

    consoleTextPane = new JTextPane(document);
    consoleTextPane.setEditable(false);
    DefaultCaret caret = (DefaultCaret) consoleTextPane.getCaret();
    caret.setUpdatePolicy(DefaultCaret.NEVER_UPDATE);
    consoleTextPane.setFocusTraversalKeysEnabled(false);

    Color backgroundColour = Theme.getColor("console.color");
    consoleTextPane.setBackground(backgroundColour);

    Font consoleFont = Theme.getFont("console.font");
    Font editorFont = PreferencesData.getFont("editor.font");
    Font actualFont = new Font(consoleFont.getName(), consoleFont.getStyle(), scale(editorFont.getSize()));

    stdOutStyle = new SimpleAttributeSet();
    StyleConstants.setForeground(stdOutStyle, Theme.getColor("console.output.color"));
    StyleConstants.setBackground(stdOutStyle, backgroundColour);
    StyleConstants.setFontSize(stdOutStyle, actualFont.getSize());
    StyleConstants.setFontFamily(stdOutStyle, actualFont.getFamily());
    StyleConstants.setBold(stdOutStyle, actualFont.isBold());
    StyleConstants.setItalic(stdOutStyle, actualFont.isItalic());

    consoleTextPane.setParagraphAttributes(stdOutStyle, true);

    stdErrStyle = new SimpleAttributeSet();
    StyleConstants.setForeground(stdErrStyle, Theme.getColor("console.error.color"));
    StyleConstants.setBackground(stdErrStyle, backgroundColour);
    StyleConstants.setFontSize(stdErrStyle, actualFont.getSize());
    StyleConstants.setFontFamily(stdErrStyle, actualFont.getFamily());
    StyleConstants.setBold(stdErrStyle, actualFont.isBold());
    StyleConstants.setItalic(stdErrStyle, actualFont.isItalic());

    JPanel noWrapPanel = new JPanel(new BorderLayout());
    noWrapPanel.add(consoleTextPane);

    setViewportView(noWrapPanel);
    getVerticalScrollBar().setUnitIncrement(7);

    // calculate height of a line of text in pixels
    // and size window accordingly
    FontMetrics metrics = getFontMetrics(actualFont);
    int height = metrics.getAscent() + metrics.getDescent();
    int lines = PreferencesData.getInteger("console.lines");
    setPreferredSize(new Dimension(100, (height * lines)));
    setMinimumSize(new Dimension(100, (height * lines)));

    // Add font size adjustment listeners.
    if (base != null)
      base.addEditorFontResizeListeners(consoleTextPane);
  }

  public void applyPreferences() {

    // Update the console text pane font from the preferences.
    Font consoleFont = Theme.getFont("console.font");
    Font editorFont = PreferencesData.getFont("editor.font");
    Font actualFont = new Font(consoleFont.getName(), consoleFont.getStyle(), scale(editorFont.getSize()));

    AttributeSet stdOutStyleOld = stdOutStyle.copyAttributes();
    AttributeSet stdErrStyleOld = stdErrStyle.copyAttributes();
    StyleConstants.setFontSize(stdOutStyle, actualFont.getSize());
    StyleConstants.setFontSize(stdErrStyle, actualFont.getSize());

    // Re-insert console text with the new preferences if there were changes.
    // This assumes that the document has single-child paragraphs (default).
    if (!stdOutStyle.isEqual(stdOutStyleOld) || !stdErrStyle.isEqual(stdOutStyleOld)) {
      if (out != null)
        out.setAttibutes(stdOutStyle);
      if (err != null)
        err.setAttibutes(stdErrStyle);

      int start;
      for (int end = document.getLength() - 1; end >= 0; end = start - 1) {
        Element elem = document.getParagraphElement(end);
        start = elem.getStartOffset();
        AttributeSet attrs = elem.getElement(0).getAttributes();
        AttributeSet newAttrs;
        if (attrs.isEqual(stdErrStyleOld)) {
          newAttrs = stdErrStyle;
        } else if (attrs.isEqual(stdOutStyleOld)) {
          newAttrs = stdOutStyle;
        } else {
          continue;
        }
        try {
          String text = document.getText(start, end - start);
          document.remove(start, end - start);
          document.insertString(start, text, newAttrs);
        } catch (BadLocationException e) {
          // Should only happen when text is async removed (through clear()).
          // Accept this case, but throw an error when text could mess up.
          if (document.getLength() != 0) {
            throw new Error(e);
          }
        }
      }
    }
  }

  public void clear() {
    try {
      document.remove(0, document.getLength());
      startOfLine = 0;
      insertPosition = 0;
    } catch (BadLocationException e) {
      // ignore the error otherwise this will cause an infinite loop
      // maybe not a good idea in the long run?
    }
  }

  public void scrollDown() {
    getHorizontalScrollBar().setValue(0);
    getVerticalScrollBar().setValue(getVerticalScrollBar().getMaximum());
  }

  public boolean isEmpty() {
    return document.getLength() == 0;
  }

  public void insertString(String str, SimpleAttributeSet attributes) throws BadLocationException {
    // Separate the string into content, newlines and lone carriage
    // returns.
    //
    // Doing so allows lone CRs to move the insertPosition back to the
    // start of the line to allow overwriting the most recent line (e.g.
    // for a progress bar). Any CR or NL that are immediately followed
    // by another NL are bunched together for efficiency, since these
    // can just be inserted into the document directly and still be
    // correct.
    //
    // The regex is written so it will necessarily match any string
    // completely if applied repeatedly. This is important because any
    // part not matched would be silently dropped.
    Matcher m = newLinePattern.matcher(str);

    while (m.find()) {
      String content = m.group(1);
      String newlines = m.group(2);
      String crs = m.group(3);

      // Replace (or append if at end of the document) the content first
      int replaceLength = Math.min(content.length(), document.getLength() - insertPosition);
      document.replace(insertPosition, replaceLength, content, attributes);
      insertPosition += content.length();

      // Then insert any newlines, but always at the end of the document
      // e.g. if insertPosition is halfway a line, do not delete
      // anything, just add the newline(s) at the end).
      if (newlines != null) {
        document.insertString(document.getLength(), newlines, attributes);
        insertPosition = document.getLength();
        startOfLine = insertPosition;
      }

      // Then, for any CRs not followed by newlines, move insertPosition
      // to the start of the line. Note that if a newline follows before
      // any content in the next call to insertString, it will be added
      // at the end of the document anyway, as expected.
      if (crs != null) {
        insertPosition = startOfLine;
      }
    }
  }

  public String getText() {
    return consoleTextPane.getText();
  }

}
