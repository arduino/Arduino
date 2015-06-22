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

import cc.arduino.MessageConsole;

import javax.swing.*;
import javax.swing.text.BadLocationException;
import javax.swing.text.DefaultStyledDocument;
import javax.swing.text.SimpleAttributeSet;
import javax.swing.text.StyleConstants;
import java.awt.*;


/**
 * Message console that sits below the editing area.
 * <p>
 * Debugging this class is tricky... If it's throwing exceptions,
 * don't take over System.err, and debug while watching just System.out
 * or just write println() or whatever directly to systemOut or systemErr.
 */
@SuppressWarnings("serial")
public class EditorConsole extends JScrollPane {
  private final DefaultStyledDocument document;
  private final JTextPane consoleTextPane;

  // Single static instance shared because there's only one real System.out.
  // Within the input handlers, the currentConsole variable will be used to
  // echo things to the correct location.

  public EditorConsole() {
    document = new DefaultStyledDocument();

    consoleTextPane = new JTextPane(document);
    Color backgroundColour = Theme.getColor("console.color");
    consoleTextPane.setBackground(backgroundColour);

    Font consoleFont = Theme.getFont("console.font");
    Font editorFont = PreferencesData.getFont("editor.font");
    Font actualFont = new Font(consoleFont.getName(), consoleFont.getStyle(), editorFont.getSize());

    SimpleAttributeSet stdOutStyle = new SimpleAttributeSet();
    StyleConstants.setForeground(stdOutStyle, Theme.getColor("console.output.color"));
    StyleConstants.setBackground(stdOutStyle, backgroundColour);
    StyleConstants.setFontSize(stdOutStyle, actualFont.getSize());
    StyleConstants.setFontFamily(stdOutStyle, actualFont.getFamily());
    StyleConstants.setBold(stdOutStyle, actualFont.isBold());
    StyleConstants.setItalic(stdOutStyle, actualFont.isItalic());

    SimpleAttributeSet stdErrStyle = new SimpleAttributeSet();
    StyleConstants.setForeground(stdErrStyle, Theme.getColor("console.error.color"));
    StyleConstants.setBackground(stdErrStyle, backgroundColour);
    StyleConstants.setFontSize(stdErrStyle, actualFont.getSize());
    StyleConstants.setFontFamily(stdErrStyle, actualFont.getFamily());
    StyleConstants.setBold(stdErrStyle, actualFont.isBold());
    StyleConstants.setItalic(stdErrStyle, actualFont.isItalic());

    MessageConsole messageConsole = new MessageConsole(consoleTextPane, this);
    messageConsole.redirectErr(stdErrStyle, System.err);
    messageConsole.redirectOut(stdOutStyle, System.out);
    messageConsole.setMessageLines(PreferencesData.getInteger("console.length") * 2);

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
    setPreferredSize(new Dimension(1024, (height * lines) + sizeFudge));
    setMinimumSize(new Dimension(1024, (height * 4) + sizeFudge));
  }

  public void clear() {
    try {
      document.remove(0, document.getLength());
    } catch (BadLocationException e) {
      // ignore the error otherwise this will cause an infinite loop
      // maybe not a good idea in the long run?
    }
  }

  public String getText() {
    return consoleTextPane.getText().trim();
  }
}
