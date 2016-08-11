package processing.app;

import java.awt.event.WindowEvent;
import java.awt.event.WindowFocusListener;
import java.beans.PropertyChangeEvent;
import java.beans.PropertyChangeListener;

import javax.swing.SwingUtilities;

import cc.arduino.UpdatableBoardsLibsFakeURLsHandler;
import cc.arduino.view.NotificationPopup;
import processing.app.Base;

public class NewBoardListener implements PropertyChangeListener, Runnable {
  private Base base;
  private Editor ed;

  public NewBoardListener(Base base) {
    this.base = base;
  }

  @Override
  public void propertyChange(PropertyChangeEvent event) {
        checkForNewBoardAttached();
  }

  @Override
  public void run() {
    while (base.getActiveEditor() == null) {
      try {
        Thread.sleep(1000);
      } catch (InterruptedException e) {
        e.printStackTrace();
      }
    }
    BaseNoGui.addPropertyChangeListener(this);
    checkForNewBoardAttached();
  }

  public void checkForNewBoardAttached() {
    String newBoardManagerLink = BaseNoGui.getBoardManagerLink();
    if (newBoardManagerLink.isEmpty()) {
      return;
    }

    SwingUtilities.invokeLater(() -> {

      ed = base.getActiveEditor();
      NotificationPopup notificationPopup = new NotificationPopup(ed, 
                 new UpdatableBoardsLibsFakeURLsHandler(base), 
                 newBoardManagerLink, false);
      if (ed.isFocused()) {
        notificationPopup.begin();
        return;
      }

      // If the IDE is not focused wait until it is focused again to
      // display the notification, this avoids the annoying side effect
      // to "steal" the focus from another application.
      WindowFocusListener wfl = new WindowFocusListener() {
        @Override
        public void windowLostFocus(WindowEvent evt) {
        }

        @Override
        public void windowGainedFocus(WindowEvent evt) {
          notificationPopup.begin();
          for (Editor e : base.getEditors())
            e.removeWindowFocusListener(this);
        }
      };

      for (Editor e : base.getEditors())
        e.addWindowFocusListener(wfl);
    });
  }
}
