package processing.app;

import org.junit.Before;
import org.junit.Test;
import org.mockito.ArgumentCaptor;

import static org.fest.assertions.Assertions.assertThat;
import static org.mockito.Mockito.*;

public class UpdateTextAreaActionTest {

  private static final String TIMESTAMP_REGEX = "\\d\\d:\\d\\d:\\d\\d.\\d\\d\\d";
  private TextAreaFIFO textAreaFIFO;
  private ArgumentCaptor<String> text;

  @Before public void setUp() {
    textAreaFIFO = mock(TextAreaFIFO.class);
    text = ArgumentCaptor.forClass(String.class);
  }

  @Test
  public void noTimestampAdded() {
    // given
    AbstractTextMonitor.UpdateTextAreaAction action = new AbstractTextMonitor.UpdateTextAreaAction(
        textAreaFIFO, false, false, "line1\nline2\r\nline3");

    // when
    action.run();

    //then
    verify(textAreaFIFO, atLeastOnce()).append(text.capture());
    assertThat(text.getValue()).startsWith("line1");
  }

  @Test
  public void all3LinesHaveTimestampAdded() {
    // given
    AbstractTextMonitor.UpdateTextAreaAction action = new AbstractTextMonitor.UpdateTextAreaAction(
        textAreaFIFO, true, false, "line1\nline2\r\nline3");

    // when
    action.run();

    //then
    verify(textAreaFIFO, atLeastOnce()).append(text.capture());
    assertThat(text.getValue()).matches(TIMESTAMP_REGEX + " -> line1\\n"
                                        + TIMESTAMP_REGEX + " -> line2\\r\\n"
                                        + TIMESTAMP_REGEX + " -> line3");
  }

  @Test
  public void emptyLinesHaveTimestampToo() {
    // given
    AbstractTextMonitor.UpdateTextAreaAction action = new AbstractTextMonitor.UpdateTextAreaAction(
        textAreaFIFO, true, false, "line_1\n\nline_2");

    // when
    action.run();

    //then
    verify(textAreaFIFO, atLeastOnce()).append(text.capture());
    assertThat(text.getValue()).matches(TIMESTAMP_REGEX + " -> line_1\\n"
                                        + TIMESTAMP_REGEX + " -> \\n"
                                        + TIMESTAMP_REGEX + " -> line_2");
  }

}