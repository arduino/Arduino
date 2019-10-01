package cc.arduino.contributions.libraries.ui;

import static processing.app.I18n.format;
import static processing.app.I18n.tr;

import java.awt.*;
import java.util.Optional;

import javax.swing.*;
import javax.swing.border.EmptyBorder;
import javax.swing.border.TitledBorder;
import javax.swing.event.HyperlinkEvent;
import javax.swing.text.Document;
import javax.swing.text.html.HTMLDocument;
import javax.swing.text.html.StyleSheet;

import cc.arduino.contributions.DownloadableContributionVersionComparator;
import cc.arduino.contributions.libraries.ContributedLibrary;
import cc.arduino.contributions.libraries.ContributedLibraryReleases;
import cc.arduino.contributions.ui.InstallerTableCell;
import processing.app.Base;
import processing.app.PreferencesData;
import processing.app.Theme;

public class ContributedLibraryTableCellJPanel extends JPanel {

  final JButton moreInfoButton;
  final JButton installButton;
  final Component installButtonPlaceholder;
  final JComboBox downgradeChooser;
  final JComboBox versionToInstallChooser;
  final JButton downgradeButton;
  final JPanel buttonsPanel;
  final JPanel inactiveButtonsPanel;
  final JLabel statusLabel;
  final JTextPane description;
  private final String moreInfoLbl = tr("More info");

  public ContributedLibraryTableCellJPanel(JTable parentTable, Object value,
                                           boolean isSelected) {
    super();
    setLayout(new BoxLayout(this, BoxLayout.Y_AXIS));

    moreInfoButton = new JButton(moreInfoLbl);
    moreInfoButton.setVisible(false);
    installButton = new JButton(tr("Install"));
    int width = installButton.getPreferredSize().width;
    installButtonPlaceholder = Box.createRigidArea(new Dimension(width, 1));

    downgradeButton = new JButton(tr("Install"));

    downgradeChooser = new JComboBox();
    downgradeChooser.addItem("-");
    downgradeChooser.setMaximumSize(new Dimension((int)downgradeChooser.getPreferredSize().getWidth() + 50, (int)downgradeChooser.getPreferredSize().getHeight()));
    downgradeChooser.setMinimumSize(new Dimension((int)downgradeChooser.getPreferredSize().getWidth() + 50, (int)downgradeChooser.getPreferredSize().getHeight()));
    downgradeChooser.addActionListener(e -> {
      Object selectVersionItem = downgradeChooser.getItemAt(0);
      boolean disableDowngrade = (downgradeChooser.getSelectedItem() == selectVersionItem);
      downgradeButton.setEnabled(!disableDowngrade);
      if (!disableDowngrade) {
        InstallerTableCell.dropdownSelected(true);
      }
    });

    versionToInstallChooser = new JComboBox();
    versionToInstallChooser.addItem("-");
    versionToInstallChooser
        .setMaximumSize(new Dimension((int)versionToInstallChooser.getPreferredSize().getWidth() + 50, (int)versionToInstallChooser.getPreferredSize().getHeight()));
    versionToInstallChooser
        .setMinimumSize(new Dimension((int)versionToInstallChooser.getPreferredSize().getWidth() + 50, (int)versionToInstallChooser.getPreferredSize().getHeight()));

    description = makeNewDescription();
    add(description);

    buttonsPanel = new JPanel();
    buttonsPanel.setLayout(new BoxLayout(buttonsPanel, BoxLayout.X_AXIS));
    buttonsPanel.setOpaque(false);

    buttonsPanel.add(Box.createHorizontalStrut(7));
    if (PreferencesData.getBoolean("ide.accessible")) {
      buttonsPanel.add(moreInfoButton);
      buttonsPanel.add(Box.createHorizontalStrut(5));
      buttonsPanel.add(Box.createHorizontalStrut(15));
    }
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

    // FIXME: happens on macosx, don't know why
    if (releases == null)
      return;

    ContributedLibrary selected = releases.getSelected();
    TitledBorder titledBorder = BorderFactory.createTitledBorder(selected.getName());
    titledBorder.setTitleFont(getFont().deriveFont(Font.BOLD));
    setBorder(titledBorder);
    Optional<ContributedLibrary> mayInstalled = releases.getInstalled();

    boolean installable, upgradable;
    if (!mayInstalled.isPresent()) {
      installable = true;
      upgradable = false;
    } else {
      installable = false;
      upgradable = new DownloadableContributionVersionComparator()
          .compare(selected, mayInstalled.get()) > 0;
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
    final String website = selected.getWebsite();
    String sentence = selected.getSentence();
    String paragraph = selected.getParagraph();
    // String availableVer = selectedLib.getVersion();
    // String url = selected.getUrl();

    String midcolor = isSelected ? "#000000" : "#888888";

    String desc = "<html><body>";

    // Library name...
//    desc += format("<b>{0}</b>", name);
    if (mayInstalled.isPresent() && mayInstalled.get().isIDEBuiltIn()) {
      desc += " Built-In ";
    }

    // ...author...
    desc += format("<font color=\"{0}\">", midcolor);
    if (author != null && !author.isEmpty()) {
      desc += format(" by <b>{0}</b>", author);
    }

    // ...version.
    if (mayInstalled.isPresent()) {
      String installedVer = mayInstalled.get().getParsedVersion();
      if (installedVer == null) {
        desc += " " + tr("Version unknown");
      } else {
        desc += " " + format(tr("Version <b>{0}</b>"), installedVer);
      }
    }
    desc += "</font>";

    if (mayInstalled.isPresent()) {
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
      desc = setButtonOrLink(moreInfoButton, desc, moreInfoLbl, website);
    }

    desc += "</body></html>";
    description.setText(desc);
    // copy description to accessibility context for screen readers to use
    description.getAccessibleContext().setAccessibleDescription(desc);

    // for modelToView to work, the text area has to be sized. It doesn't
    // matter if it's visible or not.

    // See:
    // http://stackoverflow.com/questions/3081210/how-to-set-jtextarea-to-have-height-that-matches-the-size-of-a-text-it-contains
    InstallerTableCell
        .setJTextPaneDimensionToFitContainedText(description,
                                                 parentTable.getBounds().width);
  }

  // same function as in ContributedPlatformTableCellJPanel - is there a utils file this can move to?
  private String setButtonOrLink(JButton button, String desc, String label, String url) {
    boolean accessibleIDE = PreferencesData.getBoolean("ide.accessible");
    String retString = desc;

    if (accessibleIDE) {
      button.setVisible(true);
      button.addActionListener(e -> {
        Base.openURL(url);
      });
    }
    else {
      // if not accessible IDE, keep link the same EXCEPT that now the link text is translated!
      retString += format("<a href=\"{0}\">{1}</a><br/>", url, label);
    }

    return retString;
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
                + "color: black;"
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
    return description;
  }

  public void setButtonsVisible(boolean enabled) {
    installButton.setEnabled(enabled);
    buttonsPanel.setVisible(enabled);
    inactiveButtonsPanel.setVisible(!enabled);
  }

  public void setForeground(Color c) {
    super.setForeground(c);
    // The description is not opaque, so copy our foreground color to it.
    if (description != null)
      description.setForeground(c);
  }
}
