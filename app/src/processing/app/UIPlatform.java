package processing.app;

import java.awt.*;

public abstract class UIPlatform {

  public void setFullScreenable(Editor editor) {
  }

  public void toogleFullscreen(Editor frame) {
    if (!frame.isFullScreen()) {
      frame.setExtendedState(Frame.MAXIMIZED_BOTH);
      frame.setAlwaysOnTop(true);
      frame.savePreviousPlacement();
      frame.setFullScreen(true);
    } else {
      frame.setExtendedState(Frame.NORMAL);
      frame.setAlwaysOnTop(false);
      frame.clearPreviousPlacement();
      frame.setFullScreen(false);
    }
  }

}
