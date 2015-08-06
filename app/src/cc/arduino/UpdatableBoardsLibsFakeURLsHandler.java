package cc.arduino;

import processing.app.Base;

import javax.swing.event.HyperlinkEvent;
import javax.swing.event.HyperlinkListener;
import java.net.URL;

public class UpdatableBoardsLibsFakeURLsHandler implements HyperlinkListener {

  private static final String BOARDSMANAGER = "boardsmanager";
  private static final String LIBRARYMANAGER = "librarymanager";

  private final Base base;

  public UpdatableBoardsLibsFakeURLsHandler(Base base) {
    this.base = base;
  }

  @Override
  public void hyperlinkUpdate(HyperlinkEvent event) {
    if (event.getEventType() != HyperlinkEvent.EventType.ACTIVATED) {
      return;
    }

    URL url = event.getURL();

    if (BOARDSMANAGER.equals(url.getHost())) {
      try {
        base.openBoardsManager("", "DropdownUpdatableCoresItem");
      } catch (Exception e) {
        e.printStackTrace();
      }
      return;
    }

    if (LIBRARYMANAGER.equals(url.getHost())) {
      base.openLibraryManager("DropdownUpdatableLibrariesItem");
      return;
    }

    throw new IllegalArgumentException(url.getHost() + " is invalid");
  }

}
