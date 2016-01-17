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

  public EditorConsole() {
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

    SimpleAttributeSet stdOutStyle = new SimpleAttributeSet();
    StyleConstants.setForeground(stdOutStyle, Theme.getColor("console.output.color"));
    StyleConstants.setBackground(stdOutStyle, backgroundColour);
    StyleConstants.setFontSize(stdOutStyle, actualFont.getSize());
    StyleConstants.setFontFamily(stdOutStyle, actualFont.getFamily());
    StyleConstants.setBold(stdOutStyle, actualFont.isBold());
    StyleConstants.setItalic(stdOutStyle, actualFont.isItalic());

    consoleTextPane.setParagraphAttributes(stdOutStyle, true);

    SimpleAttributeSet stdErrStyle = new SimpleAttributeSet();
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
    int sizeFudge = 6; //10; // unclear why this is necessary, but it is
    setPreferredSize(new Dimension(100, (height * lines) + sizeFudge));
    setMinimumSize(new Dimension(100, (height * 5) + sizeFudge));

    EditorConsole.init(stdOutStyle, System.out, stdErrStyle, System.err);
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
