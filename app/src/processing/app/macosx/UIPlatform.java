package processing.app.macosx;

import com.apple.eawt.AppEvent;
import com.apple.eawt.FullScreenAdapter;
import com.apple.eawt.FullScreenUtilities;
import processing.app.Editor;

public class UIPlatform extends processing.app.UIPlatform {

  @Override
  public void setFullScreenable(final Editor editor) {
    FullScreenUtilities.setWindowCanFullScreen(editor, true);
    FullScreenUtilities.addFullScreenListenerTo(editor, new FullScreenAdapter() {
      @Override
      public void windowEnteringFullScreen(AppEvent.FullScreenEvent fullScreenEvent) {

      }

      @Override
      public void windowEnteredFullScreen(AppEvent.FullScreenEvent fullScreenEvent) {
        editor.setFullScreen(true);
      }

      @Override
      public void windowExitingFullScreen(AppEvent.FullScreenEvent fullScreenEvent) {
      }

      @Override
      public void windowExitedFullScreen(AppEvent.FullScreenEvent fullScreenEvent) {
        editor.setFullScreen(false);
      }
    });
  }

  @Override
  public void toogleFullscreen(Editor frame) {
    ThinkDifferent.requestToggleFullScreen(frame);
  }

}
