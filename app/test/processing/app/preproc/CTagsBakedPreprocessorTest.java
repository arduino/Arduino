package processing.app.preproc;

import org.junit.Before;
import org.junit.Test;
import processing.app.AbstractWithPreferencesTest;
import processing.app.BaseNoGui;
import processing.app.PreferencesData;
import processing.app.helpers.FileUtils;
import processing.app.helpers.PreferencesMap;

import java.io.File;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;

public class CTagsBakedPreprocessorTest extends AbstractWithPreferencesTest {

  private PreferencesMap prefs;

  @Before
  public void preparePreferences() {
    prefs = new PreferencesMap();
    prefs.putAll(PreferencesData.getMap());
    prefs.putAll(BaseNoGui.getTargetPlatform().getTool("ctags"));
    prefs.putAll(BaseNoGui.getTargetBoard().getPreferences());
    prefs.putAll(BaseNoGui.getTargetBoard().getContainerPlatform().getPreferences());
    prefs.put("build.arch", "AVR");
  }

  @Test
  public void shouldPreprocessSketchWithIfDef() throws Exception {
    Map<String, Object> context = preprocessTestSketch("SketchWithIfDef.ino");

    String preprocessedCode = (String) context.get("source");
    List<String> prototypes = (List<String>) context.get("prototypes");

    assertEquals(5, prototypes.size());
    assertEquals("void setup();", prototypes.get(0));
    assertEquals("void loop();", prototypes.get(1));
    assertEquals("void debug();", prototypes.get(2));
    assertEquals("void disabledIsDefined();", prototypes.get(3));
    assertEquals("int useMyType(MyType type);", prototypes.get(4));

    File expectedPreprocessedSketch = new File(CTagsBakedPreprocessorTest.class.getResource("SketchWithIfDef.preprocessed.ino").getFile());
    String expectedOutput = FileUtils.readFileToString(expectedPreprocessedSketch);

    assertEquals(expectedOutput, preprocessedCode);
  }

  @Test
  public void shouldPreprocessBaladuino() throws Exception {
    Map<String, Object> context = preprocessTestSketch("Baladuino.ino");

    String preprocessedCode = (String) context.get("source");
    List<String> prototypes = (List<String>) context.get("prototypes");

    assertEquals(2, prototypes.size());
    assertEquals("void setup();", prototypes.get(0));
    assertEquals("void loop();", prototypes.get(1));

    File expectedPreprocessedSketch = new File(CTagsBakedPreprocessorTest.class.getResource("Baladuino.preprocessed.ino").getFile());
    String expectedOutput = FileUtils.readFileToString(expectedPreprocessedSketch);

    assertEquals(expectedOutput, preprocessedCode);
  }

  @Test
  public void shouldPreprocessCharWithEscapedDoubleQuote() throws Exception {
    Map<String, Object> context = preprocessTestSketch("CharWithEscapedDoubleQuote.ino");

    String preprocessedCode = (String) context.get("source");
    List<String> prototypes = (List<String>) context.get("prototypes");

    assertEquals(21, prototypes.size());
    assertTrue(prototypes.contains("void setup();"));
    assertTrue(prototypes.contains("byte decToBcd( byte b );"));
    assertTrue(prototypes.contains("void sendTextMessage( char number[], char messg[] );"));

    File expectedPreprocessedSketch = new File(CTagsBakedPreprocessorTest.class.getResource("CharWithEscapedDoubleQuote.preprocessed.ino").getFile());
    String expectedOutput = FileUtils.readFileToString(expectedPreprocessedSketch);

    assertEquals(expectedOutput, preprocessedCode);
  }

  @Test
  public void shouldPreprocessIncludeBetweenMultilineComment() throws Exception {
    Map<String, Object> context = preprocessTestSketch("IncludeBetweenMultilineComment.ino");

    String preprocessedCode = (String) context.get("source");
    List<String> prototypes = (List<String>) context.get("prototypes");

    assertEquals(2, prototypes.size());
    assertEquals("void setup();", prototypes.get(0));
    assertEquals("void loop();", prototypes.get(1));

    File expectedPreprocessedSketch = new File(CTagsBakedPreprocessorTest.class.getResource("IncludeBetweenMultilineComment.preprocessed.ino").getFile());
    String expectedOutput = FileUtils.readFileToString(expectedPreprocessedSketch);

    assertEquals(expectedOutput, preprocessedCode);
  }

  @Test
  public void shouldPreprocessLineContinuations() throws Exception {
    Map<String, Object> context = preprocessTestSketch("LineContinuations.ino");

    String preprocessedCode = (String) context.get("source");
    List<String> prototypes = (List<String>) context.get("prototypes");

    assertEquals(2, prototypes.size());
    assertEquals("void setup();", prototypes.get(0));
    assertEquals("void loop();", prototypes.get(1));

    File expectedPreprocessedSketch = new File(CTagsBakedPreprocessorTest.class.getResource("LineContinuations.preprocessed.ino").getFile());
    String expectedOutput = FileUtils.readFileToString(expectedPreprocessedSketch);

    assertEquals(expectedOutput, preprocessedCode);
  }

  @Test
  public void shouldPreprocessStringWithComment() throws Exception {
    Map<String, Object> context = preprocessTestSketch("StringWithComment.ino");

    String preprocessedCode = (String) context.get("source");
    List<String> prototypes = (List<String>) context.get("prototypes");

    assertEquals(2, prototypes.size());
    assertEquals("void setup();", prototypes.get(0));
    assertEquals("void loop();", prototypes.get(1));

    File expectedPreprocessedSketch = new File(CTagsBakedPreprocessorTest.class.getResource("StringWithComment.preprocessed.ino").getFile());
    String expectedOutput = FileUtils.readFileToString(expectedPreprocessedSketch);

    assertEquals(expectedOutput, preprocessedCode);
  }

  private Map<String, Object> preprocessTestSketch(String sketchName) throws Exception {
    File sketch = new File(CTagsBakedPreprocessorTest.class.getResource(sketchName).getFile());

    String input = FileUtils.readFileToString(sketch);

    Map<String, Object> context = new HashMap<String, Object>();
    context.put("source", input);

    new IncludesFinder(prefs, true).preprocess(context);

    new CTagsBakedPreprocessor(prefs, true).preprocess(context, prefs);
    return context;
  }

}
