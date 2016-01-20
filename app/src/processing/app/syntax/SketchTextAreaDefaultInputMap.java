package processing.app.syntax;

import org.fife.ui.rsyntaxtextarea.RSyntaxTextAreaDefaultInputMap;
import org.fife.ui.rsyntaxtextarea.RSyntaxTextAreaEditorKit;
import org.fife.ui.rtextarea.RTextArea;
import org.fife.ui.rtextarea.RTextAreaEditorKit;
import processing.app.PreferencesData;

import javax.swing.*;
import javax.swing.text.DefaultEditorKit;
import java.awt.event.InputEvent;
import java.awt.event.KeyEvent;

public class SketchTextAreaDefaultInputMap extends RSyntaxTextAreaDefaultInputMap {

  public SketchTextAreaDefaultInputMap() {
    int defaultModifier = getDefaultModifier();
    int ctrl = InputEvent.CTRL_MASK;
    int alt = InputEvent.ALT_MASK;
    int shift = InputEvent.SHIFT_MASK;
    boolean isOSX = RTextArea.isOSX();
    int moveByWordMod = isOSX ? alt : defaultModifier;

    remove(KeyStroke.getKeyStroke(KeyEvent.VK_K, defaultModifier));

    // Remove a troublesome binding for the / key. By default, RSyntaxTextArea
    // binds the / KEY_TYPED event to insert a / and optionally complete any XML
    // tags. However, since this also triggeres on ctrl-slash, this means that
    // in addition to toggling comments on ctrl-slash, it also inserts a slash.
    // Since we don't need the XML completion feature anyway, just unbind it
    // here. A future version of RSyntaxTextArea might fix this, see
    // https://github.com/bobbylight/RSyntaxTextArea/issues/157.
    remove(KeyStroke.getKeyStroke('/'));

    if (PreferencesData.getBoolean("editor.advanced")) {
      put(KeyStroke.getKeyStroke(KeyEvent.VK_DOWN, alt), RTextAreaEditorKit.rtaLineDownAction);
      put(KeyStroke.getKeyStroke(KeyEvent.VK_UP, alt), RTextAreaEditorKit.rtaLineUpAction);
    } else {
      remove(KeyStroke.getKeyStroke(KeyEvent.VK_DOWN, alt));
      remove(KeyStroke.getKeyStroke(KeyEvent.VK_UP, alt));
    }

    remove(KeyStroke.getKeyStroke(KeyEvent.VK_BACK_SPACE, defaultModifier));
    put(KeyStroke.getKeyStroke(KeyEvent.VK_BACK_SPACE, moveByWordMod), RTextAreaEditorKit.rtaDeletePrevWordAction);

    if (isOSX) {
      put(KeyStroke.getKeyStroke(KeyEvent.VK_BACK_SPACE, defaultModifier), SketchTextAreaEditorKit.rtaDeleteLineToCursorAction);

      put(KeyStroke.getKeyStroke(KeyEvent.VK_UP, defaultModifier), DefaultEditorKit.beginAction);
      put(KeyStroke.getKeyStroke(KeyEvent.VK_DOWN, defaultModifier), DefaultEditorKit.endAction);

      put(KeyStroke.getKeyStroke(KeyEvent.VK_LEFT, defaultModifier | shift), DefaultEditorKit.selectionBeginLineAction);
      put(KeyStroke.getKeyStroke(KeyEvent.VK_RIGHT, defaultModifier | shift), DefaultEditorKit.selectionEndLineAction);

      remove(KeyStroke.getKeyStroke(KeyEvent.VK_J, defaultModifier));

      put(KeyStroke.getKeyStroke(KeyEvent.VK_OPEN_BRACKET, defaultModifier), RSyntaxTextAreaEditorKit.rstaDecreaseIndentAction);
      put(KeyStroke.getKeyStroke(KeyEvent.VK_CLOSE_BRACKET, defaultModifier), SketchTextAreaEditorKit.rtaIncreaseIndentAction);

      put(KeyStroke.getKeyStroke(KeyEvent.VK_UP, defaultModifier | shift), DefaultEditorKit.selectionBeginAction);
      put(KeyStroke.getKeyStroke(KeyEvent.VK_DOWN, defaultModifier | shift), DefaultEditorKit.selectionEndAction);

      if (!PreferencesData.getBoolean("editor.keys.home_and_end_beginning_end_of_doc")) {
        put(KeyStroke.getKeyStroke(KeyEvent.VK_HOME, 0), DefaultEditorKit.beginLineAction);
        put(KeyStroke.getKeyStroke(KeyEvent.VK_END, 0), DefaultEditorKit.endLineAction);
      }

      put(KeyStroke.getKeyStroke(KeyEvent.VK_A, ctrl), DefaultEditorKit.beginLineAction);
      put(KeyStroke.getKeyStroke(KeyEvent.VK_E, ctrl), DefaultEditorKit.endLineAction);
    }

    put(KeyStroke.getKeyStroke(KeyEvent.VK_DIVIDE, defaultModifier), RSyntaxTextAreaEditorKit.rstaToggleCommentAction);

    put(KeyStroke.getKeyStroke(KeyEvent.VK_KP_LEFT, 0), DefaultEditorKit.backwardAction);
    put(KeyStroke.getKeyStroke(KeyEvent.VK_KP_RIGHT, 0), DefaultEditorKit.forwardAction);
    put(KeyStroke.getKeyStroke(KeyEvent.VK_KP_DOWN, 0), DefaultEditorKit.downAction);
    put(KeyStroke.getKeyStroke(KeyEvent.VK_KP_UP, 0), DefaultEditorKit.upAction);

  }
}
