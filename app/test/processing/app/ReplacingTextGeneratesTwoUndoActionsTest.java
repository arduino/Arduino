package processing.app;

import org.fest.swing.fixture.JMenuItemFixture;
import org.junit.Test;
import processing.app.helpers.RSyntaxTextAreaFixture;

import static org.junit.Assert.assertEquals;

public class ReplacingTextGeneratesTwoUndoActionsTest extends AbstractGUITest {

  @Test
  public void shouldUndoAndRedo() throws Exception {
    JMenuItemFixture menuEditUndo = window.menuItem("menuEditUndo");
    menuEditUndo.requireDisabled();
    JMenuItemFixture menuEditRedo = window.menuItem("menuEditRedo");
    menuEditRedo.requireDisabled();

    RSyntaxTextAreaFixture RSyntaxTextArea = window.RSyntaxTextArea("editor");

    RSyntaxTextArea.setText("fake text");

    menuEditUndo.requireEnabled();
    menuEditUndo.click();

    assertEquals("", RSyntaxTextArea.getText());

    menuEditRedo.requireEnabled();
    menuEditRedo.click();

    //assertEquals("fake text", RSyntaxTextArea.getText());

    menuEditUndo.requireEnabled();
    menuEditUndo.click();
    menuEditUndo.click();
    menuEditUndo.requireDisabled();
    menuEditRedo.requireEnabled();
  }
}
