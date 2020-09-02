package processing.app;

import static org.fest.assertions.Assertions.assertThat;

import org.junit.Before;
import org.junit.Test;

import cc.arduino.packages.BoardPort;
import processing.app.helpers.PreferencesMap;

public class UpdateTextAreaActionTest {

  private static final String TIMESTAMP_REGEX = "\\d\\d:\\d\\d:\\d\\d.\\d\\d\\d";

  class DummyTextMonitor extends AbstractTextMonitor {
    public DummyTextMonitor(BoardPort boardPort) {
      super(boardPort);
    }
  }

  @Before
  public void setup() {
    PreferencesData.defaults = new PreferencesMap();
    PreferencesData.set("editor.font", "Monospaced,plain,12");
    PreferencesData.set("gui.scale", "100");
    Theme.defaults = new PreferencesMap();
    Theme.table.put("console.font", "Monospaced,plain,12");
  }

  @Test
  public void noTimestampAdded() {
    DummyTextMonitor textMon = new DummyTextMonitor(new BoardPort());
    textMon.addTimeStampBox.setSelected(false);

    textMon.updateTextArea("line1\nline2\r\nline3");
    assertThat(textMon.textArea.getText()).matches("line1\nline2\r\nline3");
  }

  @Test
  public void all3LinesHaveTimestampAdded() {
    DummyTextMonitor textMon = new DummyTextMonitor(new BoardPort());
    textMon.addTimeStampBox.setSelected(true);

    textMon.updateTextArea("line1\nline2\r\nline3");
    assertThat(textMon.textArea.getText())
        .matches(TIMESTAMP_REGEX + " -> line1\\n" + //
                 TIMESTAMP_REGEX + " -> line2\\r\\n" + //
                 TIMESTAMP_REGEX + " -> line3");
  }

  @Test
  public void emptyLinesHaveTimestampToo() {
    DummyTextMonitor textMon = new DummyTextMonitor(new BoardPort());
    textMon.addTimeStampBox.setSelected(true);

    textMon.updateTextArea("line_1\n\nline_2");
    assertThat(textMon.textArea.getText())
        .matches(TIMESTAMP_REGEX + " -> line_1\\n" + //
                 TIMESTAMP_REGEX + " -> \\n" + //
                 TIMESTAMP_REGEX + " -> line_2");
  }

  @Test
  public void newLinesAreRememberedWhenNewBufferIsUsed() {
    DummyTextMonitor textMon = new DummyTextMonitor(new BoardPort());
    textMon.addTimeStampBox.setSelected(true);

    textMon.updateTextArea("no newline");
    assertThat(textMon.textArea.getText())
        .matches(TIMESTAMP_REGEX + " -> no newline");

    textMon.updateTextArea(" more text");
    assertThat(textMon.textArea.getText())
        .matches(TIMESTAMP_REGEX + " -> no newline more text");

    textMon.updateTextArea("\n");
    assertThat(textMon.textArea.getText())
        .matches(TIMESTAMP_REGEX + " -> no newline more text\n");

    textMon.updateTextArea("\n");
    assertThat(textMon.textArea.getText())
        .matches(TIMESTAMP_REGEX + " -> no newline more text\n" + //
                 TIMESTAMP_REGEX + " -> \n");

    textMon.updateTextArea("third line");
    assertThat(textMon.textArea.getText())
        .matches(TIMESTAMP_REGEX + " -> no newline more text\n" + //
                 TIMESTAMP_REGEX + " -> \n" + //
                 TIMESTAMP_REGEX + " -> third line");
  }
}