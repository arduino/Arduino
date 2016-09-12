package cc.arduino.contributions.libraries.ui;

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
import cc.arduino.contributions.libraries.ContributedLibrary;
import cc.arduino.contributions.ui.InstallerTableCell;
import processing.app.Base;
import processing.app.Theme;

public class ContributedLibraryTableCellJPanel extends JPanel {

  final JButton installButton;
  final Component installButtonPlaceholder;
  final JComboBox downgradeChooser;
  final JComboBox versionToInstallChooser;
  final JButton downgradeButton;
  final JPanel buttonsPanel;
  final JPanel inactiveButtonsPanel;
  final JLabel statusLabel;

  public ContributedLibraryTableCellJPanel(JTable parentTable, Object value,
                                           boolean isSelected) {
    super();
    setLayout(new BoxLayout(this, BoxLayout.Y_AXIS));

    installButton = new JButton(tr("Install"));
    int width = installButton.getPreferredSize().width;
    installButtonPlaceholder = Box.createRigidArea(new Dimension(width, 1));

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

    ContributedLibraryReleases releases = (ContributedLibraryReleases) value;
    JTextPane description = makeNewDescription();

    // FIXME: happens on macosx, don't know why
    if (releases == null)
      return;

    ContributedLibrary selected = releases.getSelected();
    ContributedLibrary installed = releases.getInstalled();

    boolean installable, upgradable;
    if (installed == null) {
      installable = true;
      upgradable = false;
    } else {
      installable = false;
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

    String name = selected.getName();
    String author = selected.getAuthor();
    // String maintainer = selectedLib.getMaintainer();
    String website = selected.getWebsite();
    String sentence = selected.getSentence();
    String paragraph = selected.getParagraph();
    // String availableVer = selectedLib.getVersion();
    // String url = selected.getUrl();

    String midcolor = isSelected ? "#000000" : "#888888";

    String desc = "<html><body>";

    // Library name...
    desc += format("<b>{0}</b>", name);
    if (installed != null && installed.isReadOnly()) {
      desc += " Built-In ";
    }

    // ...author...
    desc += format("<font color=\"{0}\">", midcolor);
    if (author != null && !author.isEmpty()) {
      desc += format(" by <b>{0}</b>", author);
    }

    // ...version.
    if (installed != null) {
      String installedVer = installed.getParsedVersion();
      if (installedVer == null) {
        desc += " " + tr("Version unknown");
      } else {
        desc += " " + format(tr("Version <b>{0}</b>"), installedVer);
      }
    }
    desc += "</font>";

    if (installed != null) {
      desc += " <strong><font color=\"#00979D\">INSTALLED</font></strong>";
    }

    desc += "<br/>";

    // Description
    if (sentence != null) {
      desc += format("<b>{0}</b> ", sentence);
      if (paragraph != null && !paragraph.isEmpty())
        desc += format("{0}", paragraph);
      desc += "<br />";
    }
    if (author != null && !author.isEmpty()) {
      desc += format("<a href=\"{0}\">More info</a>", website);
    }

    desc += "</body></html>";
    description.setText(desc);
    description.setBackground(Color.WHITE);

    // for modelToView to work, the text area has to be sized. It doesn't
    // matter if it's visible or not.

    // See:
    // http://stackoverflow.com/questions/3081210/how-to-set-jtextarea-to-have-height-that-matches-the-size-of-a-text-it-contains
    InstallerTableCell
        .setJTextPaneDimensionToFitContainedText(description,
                                                 parentTable.getBounds().width);

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
    // description.addKeyListener(new DelegatingKeyListener(parentTable));
    add(description, 0);
    return description;
  }

  public void setButtonsVisible(boolean enabled) {
    installButton.setEnabled(enabled);
    buttonsPanel.setVisible(enabled);
    inactiveButtonsPanel.setVisible(!enabled);
  }
}
