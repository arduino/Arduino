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

import static processing.app.I18n.tr;

public class ContributionsSelfCheck extends TimerTask {

  private final Base base;
  private final HyperlinkListener hyperlinkListener;
  private final ContributionsIndexer contributionsIndexer;
  private final ContributionInstaller contributionInstaller;
  private final LibrariesIndexer librariesIndexer;
  private final LibraryInstaller libraryInstaller;
  private final ProgressListener progressListener;

  private volatile boolean cancelled;
  private volatile NotificationPopup notificationPopup;

  public ContributionsSelfCheck(Base base, HyperlinkListener hyperlinkListener, ContributionsIndexer contributionsIndexer, ContributionInstaller contributionInstaller, LibrariesIndexer librariesIndexer, LibraryInstaller libraryInstaller) {
    this.base = base;
    this.hyperlinkListener = hyperlinkListener;
    this.contributionsIndexer = contributionsIndexer;
    this.contributionInstaller = contributionInstaller;
    this.librariesIndexer = librariesIndexer;
    this.libraryInstaller = libraryInstaller;
    this.progressListener = new NoopProgressListener();
    this.cancelled = false;
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
      text = I18n.format(tr("<br/>Update available for some of your {0}libraries{1}"), "<a href=\"http://librarymanager\">", "</a>");
    } else if (updatableLibraries <= 0 && updatablePlatforms > 0) {
      text = I18n.format(tr("<br/>Update available for some of your {0}boards{1}"), "<a href=\"http://boardsmanager\">", "</a>");
    } else {
      text = I18n.format(tr("<br/>Update available for some of your {0}boards{1} and {2}libraries{3}"), "<a href=\"http://boardsmanager\">", "</a>", "<a href=\"http://librarymanager\">", "</a>");
    }

    if (cancelled) {
      return;
    }

    SwingUtilities.invokeLater(() -> {
      notificationPopup = new NotificationPopup(base.getActiveEditor(), hyperlinkListener, text);
      notificationPopup.setVisible(true);
    });
  }

  @Override
  public boolean cancel() {
    cancelled = true;
    if (notificationPopup != null) {
      notificationPopup.close();
    }
    return super.cancel();
  }

  private void updateLibrariesIndex() {
    if (cancelled) {
      return;
    }
    try {
      libraryInstaller.updateIndex(progressListener);
    } catch (Exception e) {
      // ignore
    }
  }

  private void updateContributionIndex() {
    if (cancelled) {
      return;
    }
    try {
      contributionInstaller.updateIndex(progressListener);
    } catch (Exception e) {
      // ignore
    }
  }
}
