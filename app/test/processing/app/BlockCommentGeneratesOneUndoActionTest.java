package processing.app;

import static org.junit.Assert.assertEquals;

import java.awt.Frame;

import org.fest.swing.edt.GuiActionRunner;
import org.fest.swing.edt.GuiQuery;
import org.fest.swing.fixture.JMenuItemFixture;
import org.junit.Test;

import processing.app.helpers.RSyntaxTextAreaFixture;

public class BlockCommentGeneratesOneUndoActionTest extends AbstractGUITest {

  @Test
  public void shouldUndoAndRedo() throws Exception {
    JMenuItemFixture menuEditUndo = window.menuItem("menuEditUndo");
    menuEditUndo.requireDisabled();

    RSyntaxTextAreaFixture jEditTextArea = window.RSyntaxTextArea("editor");
    String previousText = jEditTextArea.getText();

    jEditTextArea.selectAll();

    GuiActionRunner.execute(new GuiQuery<Frame>() {

      protected Frame executeInEDT() {
        window.getEditor().handleCommentUncomment();
        return window.getEditor();
      }

    });

    menuEditUndo.requireEnabled();
    menuEditUndo.click();

    assertEquals(previousText, jEditTextArea.getText());

    menuEditUndo.requireDisabled();
  }
}
