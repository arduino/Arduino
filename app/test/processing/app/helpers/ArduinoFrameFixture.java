package processing.app.helpers;

import org.fest.swing.fixture.FrameFixture;
import org.fife.ui.rsyntaxtextarea.RSyntaxTextArea;

import processing.app.Editor;

public class ArduinoFrameFixture extends FrameFixture {

  private final Editor editor;

  public ArduinoFrameFixture(Editor editor) {
    super(editor);
    this.editor = editor;
  }

  public RSyntaxTextAreaFixture RSyntaxTextArea(String name) {
    return new RSyntaxTextAreaFixture(robot, (RSyntaxTextArea) this.robot.finder().find(new RSyntaxTextAreaComponentMatcher(name)));
  }

  public Editor getEditor() {
    return editor;
  }
}
