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

import static processing.app.Theme.scale;

/**
 * Message console that sits below the editing area.
 */
public class EditorConsole extends JScrollPane {

  private static ConsoleOutputStream out;
  private static ConsoleOutputStream err;

  private static synchronized void init(SimpleAttributeSet outStyle, PrintStream outStream, SimpleAttributeSet errStyle, PrintStream errStream) {
    if (out != null) {
      return;
    }

    out = new ConsoleOutputStream(outStyle, outStream);
    System.setOut(new PrintStream(out, true));

    err = new ConsoleOutputStream(errStyle, errStream);
    System.setErr(new PrintStream(err, true));
  }

  public static void setCurrentEditorConsole(EditorConsole console) {
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

    EditorConsole.init(stdOutStyle, System.out, stdErrStyle, System.err);

    // Add font size adjustment listeners.
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
      out.setAttibutes(stdOutStyle);
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

  public void insertString(String line, SimpleAttributeSet attributes) throws BadLocationException {
    line = line.replace("\r\n", "\n").replace("\r", "\n");
    int offset = document.getLength();
    document.insertString(offset, line, attributes);
  }

  public String getText() {
    return consoleTextPane.getText().trim();
  }

}
