package processing.app.helpers;

import java.awt.Frame;

import org.fest.swing.core.Robot;
import org.fest.swing.fixture.FrameFixture;
import org.fife.ui.rsyntaxtextarea.RSyntaxTextArea;

public class ArduinoFrameFixture extends FrameFixture {

  public ArduinoFrameFixture(Frame target) {
    super(target);
  }

  public ArduinoFrameFixture(org.fest.swing.core.Robot robot, Frame target) {
    super(robot, target);
  }

  public ArduinoFrameFixture(Robot robot, String name) {
    super(robot, name);
  }

  public ArduinoFrameFixture(String name) {
    super(name);
  }

  public RSyntaxTextAreaFixture RSyntaxTextArea(String name) {
    return new RSyntaxTextAreaFixture(robot, (RSyntaxTextArea) this.robot.finder().find(new RSyntaxTextAreaComponentMatcher(name)));
  }
}
