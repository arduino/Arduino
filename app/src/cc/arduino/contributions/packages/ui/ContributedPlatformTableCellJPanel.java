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

package cc.arduino.contributions.packages.ui;

import static processing.app.I18n.format;
import static processing.app.I18n.tr;

import java.awt.Color;
import java.awt.Component;
import java.awt.Dimension;
import java.awt.Insets;

import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTable;
import javax.swing.JTextPane;
import javax.swing.border.EmptyBorder;
import javax.swing.event.HyperlinkEvent;
import javax.swing.text.Document;
import javax.swing.text.html.HTMLDocument;
import javax.swing.text.html.StyleSheet;

import cc.arduino.contributions.DownloadableContributionVersionComparator;
import cc.arduino.contributions.packages.ContributedBoard;
import cc.arduino.contributions.packages.ContributedHelp;
import cc.arduino.contributions.packages.ContributedPlatform;
import cc.arduino.contributions.ui.InstallerTableCell;
import processing.app.Base;
import processing.app.Theme;

@SuppressWarnings("serial")
public class ContributedPlatformTableCellJPanel extends JPanel {

  final JButton installButton;
  final JButton removeButton;
  final Component removeButtonPlaceholder;
  final Component installButtonPlaceholder;
  final JComboBox downgradeChooser;
  final JComboBox versionToInstallChooser;
  final JButton downgradeButton;
  final JPanel buttonsPanel;
  final JPanel inactiveButtonsPanel;
  final JLabel statusLabel;

  public ContributedPlatformTableCellJPanel() {
    super();
    setLayout(new BoxLayout(this, BoxLayout.Y_AXIS));

    {
      installButton = new JButton(tr("Install"));
      int width = installButton.getPreferredSize().width;
      installButtonPlaceholder = Box.createRigidArea(new Dimension(width, 1));
    }

    {
      removeButton = new JButton(tr("Remove"));
      int width = removeButton.getPreferredSize().width;
      removeButtonPlaceholder = Box.createRigidArea(new Dimension(width, 1));
    }

    downgradeButton = new JButton(tr("Install"));

    downgradeChooser = new JComboBox();
    downgradeChooser.addItem("-");
    downgradeChooser.setMaximumSize(downgradeChooser.getPreferredSize());
    downgradeChooser.addItemListener(e -> {
      Object selectVersionItem = downgradeChooser.getItemAt(0);
      boolean disableDowngrade = (e.getItem() == selectVersionItem);
      downgradeButton.setEnabled(!disableDowngrade);
    });

    versionToInstallChooser = new JComboBox();
    versionToInstallChooser.addItem("-");
    versionToInstallChooser
        .setMaximumSize(versionToInstallChooser.getPreferredSize());

    makeNewDescription();

    buttonsPanel = new JPanel();
    buttonsPanel.setLayout(new BoxLayout(buttonsPanel, BoxLayout.X_AXIS));
    buttonsPanel.setOpaque(false);

    buttonsPanel.add(Box.createHorizontalStrut(7));
    buttonsPanel.add(downgradeChooser);
    buttonsPanel.add(Box.createHorizontalStrut(5));
    buttonsPanel.add(downgradeButton);

    buttonsPanel.add(Box.createHorizontalGlue());

    buttonsPanel.add(versionToInstallChooser);
    buttonsPanel.add(Box.createHorizontalStrut(5));
    buttonsPanel.add(installButton);
    buttonsPanel.add(Box.createHorizontalStrut(5));
    buttonsPanel.add(removeButton);
    buttonsPanel.add(Box.createHorizontalStrut(5));
    buttonsPanel.add(Box.createHorizontalStrut(15));

    add(buttonsPanel);

    inactiveButtonsPanel = new JPanel();
    inactiveButtonsPanel
        .setLayout(new BoxLayout(inactiveButtonsPanel, BoxLayout.X_AXIS));
    inactiveButtonsPanel.setOpaque(false);

    int height = installButton.getMinimumSize().height;
    inactiveButtonsPanel.add(Box.createVerticalStrut(height));
    inactiveButtonsPanel.add(Box.createGlue());

    statusLabel = new JLabel(" ");
    inactiveButtonsPanel.add(statusLabel);
    inactiveButtonsPanel.add(Box.createHorizontalStrut(15));

    add(inactiveButtonsPanel);

    add(Box.createVerticalStrut(15));
  }

  void update(JTable parentTable, Object value, boolean isSelected,
              boolean hasBuiltInRelease) {
    ContributedPlatformReleases releases = (ContributedPlatformReleases) value;

    JTextPane description = makeNewDescription();

    // FIXME: happens on macosx, don't know why
    if (releases == null) {
      return;
    }

    ContributedPlatform selected = releases.getSelected();
    ContributedPlatform installed = releases.getInstalled();

    boolean removable, installable, upgradable;
    if (installed == null) {
      installable = true;
      removable = false;
      upgradable = false;
    } else {
      installable = false;
      removable = !installed.isReadOnly() && !hasBuiltInRelease;
      upgradable = new DownloadableContributionVersionComparator()
          .compare(selected, installed) > 0;
    }
    if (installable) {
      installButton.setText(tr("Install"));
    }
    if (upgradable) {
      installButton.setText(tr("Update"));
    }
    installButton.setVisible(installable || upgradable);
    installButtonPlaceholder.setVisible(!(installable || upgradable));
    removeButton.setVisible(removable);
    removeButtonPlaceholder.setVisible(!removable);

    String desc = "<html><body>";
    desc += "<b>" + selected.getName() + "</b>";
    if (installed != null && installed.isReadOnly()) {
      desc += " Built-In ";
    }

    String author = selected.getParentPackage().getMaintainer();
    if (author != null && !author.isEmpty()) {
      desc += " " + format("by <b>{0}</b>", author);
    }
    if (installed != null) {
      desc += " "
              + format(tr("version <b>{0}</b>"), installed.getParsedVersion())
              + " <strong><font color=\"#00979D\">INSTALLED</font></strong>";
    }
    desc += "<br />";

    desc += tr("Boards included in this package:") + "<br />";
    for (ContributedBoard board : selected.getBoards()) {
      desc += board.getName() + ", ";
    }
    if (desc.lastIndexOf(',') != -1) {
      desc = desc.substring(0, desc.lastIndexOf(',')) + ".<br />";
    }

    ContributedHelp help = null;
    if (selected.getHelp() != null) {
      help = selected.getHelp();
    } else if (selected.getParentPackage().getHelp() != null) {
      help = selected.getParentPackage().getHelp();
    }
    if (help != null) {
      String url = help.getOnline();
      if (url != null && !url.isEmpty()) {
        desc += " " + format("<a href=\"{0}\">Online help</a><br/>", url);
      }
    }

    String url = selected.getParentPackage().getWebsiteURL();
    if (url != null && !url.isEmpty()) {
      desc += " " + format("<a href=\"{0}\">More info</a>", url);
    }

    desc += "</body></html>";
    description.setText(desc);
    description.setBackground(Color.WHITE);

    // for modelToView to work, the text area has to be sized. It doesn't
    // matter if it's visible or not.

    // See:
    // http://stackoverflow.com/questions/3081210/how-to-set-jtextarea-to-have-height-that-matches-the-size-of-a-text-it-contains
    int width = parentTable.getBounds().width;
    InstallerTableCell.setJTextPaneDimensionToFitContainedText(description,
                                                               width);

    if (isSelected) {
      setBackground(parentTable.getSelectionBackground());
      setForeground(parentTable.getSelectionForeground());
    } else {
      setBackground(parentTable.getBackground());
      setForeground(parentTable.getForeground());
    }
  }

  private JTextPane makeNewDescription() {
    if (getComponentCount() > 0) {
      remove(0);
    }
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
                + "font-size: " + 10 * Theme.getScale() / 100 + "; }");
    }
    description.setOpaque(false);
    description.setBorder(new EmptyBorder(4, 7, 7, 7));
    description.setHighlighter(null);
    description.setEditable(false);
    description.addHyperlinkListener(e -> {
      if (e.getEventType() == HyperlinkEvent.EventType.ACTIVATED) {
        Base.openURL(e.getDescription());
      }
    });
    add(description, 0);
    return description;
  }

  public void setButtonsVisible(boolean enabled) {
    installButton.setEnabled(enabled);
    removeButton.setEnabled(enabled);
    buttonsPanel.setVisible(enabled);
    inactiveButtonsPanel.setVisible(!enabled);
  }

}
