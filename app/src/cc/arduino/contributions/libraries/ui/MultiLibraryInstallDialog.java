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

package cc.arduino.contributions.libraries.ui;

import static processing.app.I18n.format;
import static processing.app.I18n.tr;

import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.Insets;
import java.awt.Window;
import java.awt.event.WindowEvent;
import java.util.List;

import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JPanel;
import javax.swing.JTextPane;
import javax.swing.WindowConstants;
import javax.swing.border.EmptyBorder;
import javax.swing.text.Document;
import javax.swing.text.html.HTMLDocument;
import javax.swing.text.html.StyleSheet;

import cc.arduino.contributions.libraries.ContributedLibrary;
import cc.arduino.contributions.libraries.UnavailableContributedLibrary;
import processing.app.Base;
import processing.app.Theme;

public class MultiLibraryInstallDialog extends JDialog {

  enum Result {
    ALL, NONE, CANCEL
  }

  private Result result = Result.CANCEL;

  public MultiLibraryInstallDialog(Window parent, ContributedLibrary lib,
                                   List<ContributedLibrary> dependencies) {
    super(parent, format(tr("Dependencies for library {0}:{1}"), lib.getName(),
                         lib.getParsedVersion()),
        ModalityType.APPLICATION_MODAL);
    Container pane = getContentPane();
    pane.setLayout(new BorderLayout());

    pane.add(Box.createHorizontalStrut(10), BorderLayout.WEST);
    pane.add(Box.createHorizontalStrut(10), BorderLayout.EAST);

    {
      JButton cancel = new JButton(tr("Cancel"));
      cancel.addActionListener(ev -> {
        result = Result.CANCEL;
        setVisible(false);
      });

      JButton all = new JButton(tr("Install all"));
      all.addActionListener(ev -> {
        result = Result.ALL;
        setVisible(false);
      });

      JButton none = new JButton(format(tr("Install '{0}' only"), lib.getName()));
      none.addActionListener(ev -> {
        result = Result.NONE;
        setVisible(false);
      });

      Box buttonsBox = Box.createHorizontalBox();
      buttonsBox.add(all);
      buttonsBox.add(Box.createHorizontalStrut(5));
      buttonsBox.add(none);
      buttonsBox.add(Box.createHorizontalStrut(5));
      buttonsBox.add(cancel);

      JPanel buttonsPanel = new JPanel();
      buttonsPanel.setBorder(new EmptyBorder(7, 10, 7, 10));
      buttonsPanel.setLayout(new BoxLayout(buttonsPanel, BoxLayout.Y_AXIS));
      buttonsPanel.add(buttonsBox);

      pane.add(buttonsPanel, BorderLayout.SOUTH);
    }

    {
      String libName = format("<b>{0}:{1}</b>", lib.getName(),
                              lib.getParsedVersion());
      String desc = format(tr("The library {0} needs some other library<br />dependencies currently not installed:"),
                           libName);
      desc += "<br/><br/>";
      for (ContributedLibrary l : dependencies) {
        if (l.getName().equals(lib.getName()))
          continue;
        if (l.getInstalledLibrary().isPresent())
          continue;
        if (l instanceof UnavailableContributedLibrary)
          continue;
        desc += format("- <b>{0}</b><br/>", l.getName());
      }
      desc += "<br/>";
      desc += tr("Would you like to install also all the missing dependencies?");

      JTextPane textArea = makeNewDescription();
      textArea.setContentType("text/html");
      textArea.setText(desc);

      JPanel libsList = new JPanel();
      libsList.setLayout(new BoxLayout(libsList, BoxLayout.Y_AXIS));
      libsList.add(textArea);
      libsList.setBorder(new EmptyBorder(7, 7, 7, 7));
      pane.add(libsList, BorderLayout.NORTH);
    }

    pack();
    setResizable(false);
    setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);

    WindowEvent closing = new WindowEvent(this, WindowEvent.WINDOW_CLOSING);
    Base.registerWindowCloseKeys(getRootPane(), e -> dispatchEvent(closing));
  }

  // TODO Make this a method of Theme
  private JTextPane makeNewDescription() {
    JTextPane description = new JTextPane();
    description.setInheritsPopupMenu(true);
    Insets margin = description.getMargin();
    margin.bottom = 0;
    description.setMargin(margin);
    description.setContentType("text/html");
    Document doc = description.getDocument();
    if (doc instanceof HTMLDocument) {
      HTMLDocument html = (HTMLDocument) doc;
      StyleSheet s = html.getStyleSheet();
      s.addRule("body { margin: 0; padding: 0;"
                + "font-family: Verdana, Geneva, Arial, Helvetica, sans-serif;"
                + "color: black;" + "font-size: " + 15 * Theme.getScale() / 100
                + "; }");
    }
    description.setOpaque(false);
    description.setBorder(new EmptyBorder(4, 7, 7, 7));
    description.setHighlighter(null);
    description.setEditable(false);
    add(description, 0);
    return description;
  }

  public Result getInstallDepsResult() {
    return result;
  }
}
