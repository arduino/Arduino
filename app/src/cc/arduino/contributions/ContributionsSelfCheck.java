package cc.arduino.contributions;

import cc.arduino.contributions.libraries.LibrariesIndexer;
import cc.arduino.contributions.libraries.LibraryInstaller;
import cc.arduino.contributions.libraries.filters.UpdatableLibraryPredicate;
import cc.arduino.contributions.packages.ContributionInstaller;
import cc.arduino.contributions.packages.ContributionsIndexer;
import cc.arduino.contributions.packages.filters.UpdatablePlatformPredicate;
import cc.arduino.view.NotificationPopup;
import processing.app.Base;
import processing.app.I18n;

import javax.swing.*;
import javax.swing.event.HyperlinkListener;
import java.util.TimerTask;

import static processing.app.I18n._;

public class ContributionsSelfCheck extends TimerTask {

  private final Base base;
  private final HyperlinkListener hyperlinkListener;
  private final ContributionsIndexer contributionsIndexer;
  private final ContributionInstaller contributionInstaller;
  private final LibrariesIndexer librariesIndexer;
  private final LibraryInstaller libraryInstaller;

  public ContributionsSelfCheck(Base base, HyperlinkListener hyperlinkListener, ContributionsIndexer contributionsIndexer, ContributionInstaller contributionInstaller, LibrariesIndexer librariesIndexer, LibraryInstaller libraryInstaller) {
    this.base = base;
    this.hyperlinkListener = hyperlinkListener;
    this.contributionsIndexer = contributionsIndexer;
    this.contributionInstaller = contributionInstaller;
    this.librariesIndexer = librariesIndexer;
    this.libraryInstaller = libraryInstaller;
  }

  @Override
  public void run() {
    updateContributionIndex();
    updateLibrariesIndex();

    long updatablePlatforms = contributionsIndexer.getPackages().stream()
      .flatMap(pack -> pack.getPlatforms().stream())
      .filter(new UpdatablePlatformPredicate(contributionsIndexer)).count();

    long updatableLibraries = librariesIndexer.getInstalledLibraries().stream()
      .filter(new UpdatableLibraryPredicate(librariesIndexer))
      .count();

    if (updatableLibraries <= 0 && updatablePlatforms <= 0) {
      return;
    }

    String text;
    if (updatableLibraries > 0 && updatablePlatforms <= 0) {
      text = I18n.format(_("Some {0}libraries{1} may be updated"), "<a href=\"http://librarymanager\">", "</a>");
    } else if (updatableLibraries <= 0 && updatablePlatforms > 0) {
      text = I18n.format(_("Some {0}boards{1} may be updated"), "<a href=\"http://boardsmanager\">", "</a>");
    } else {
      text = I18n.format(_("Some {0}boards{1} and some {2}libraries{3} may be updated"), "<a href=\"http://boardsmanager\">", "</a>", "<a href=\"http://librarymanager\">", "</a>");
    }

    SwingUtilities.invokeLater(() -> {
      new NotificationPopup(base.getActiveEditor(), hyperlinkListener, _("Updates available"), text).setVisible(true);
    });
  }

  private void updateLibrariesIndex() {
    try {
      libraryInstaller.updateIndex();
    } catch (Exception e) {
      // ignore
    }
  }

  private void updateContributionIndex() {
    try {
      contributionInstaller.updateIndex();
    } catch (Exception e) {
      // ignore
    }
  }
}
