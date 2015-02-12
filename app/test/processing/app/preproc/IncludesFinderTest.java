package processing.app.preproc;

import org.junit.Test;
import processing.app.AbstractWithPreferencesTest;
import processing.app.BaseNoGui;
import processing.app.PreferencesData;
import processing.app.helpers.FileUtils;
import processing.app.helpers.PreferencesMap;

import java.io.File;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import static org.junit.Assert.assertEquals;

public class IncludesFinderTest extends AbstractWithPreferencesTest {

  @Test
  public void shouldListIncludes() throws Exception {
    String input = FileUtils.readFileToString(new File(IncludesFinderTest.class.getResource("SketchWithIfDef.ino").getFile()));

    PreferencesData.set("target_package", "arduino");
    PreferencesData.set("target_platform", "avr");

    PreferencesMap prefs = new PreferencesMap();
    prefs.putAll(PreferencesData.getMap());
    prefs.putAll(BaseNoGui.getTargetBoard().getPreferences());
    prefs.putAll(BaseNoGui.getTargetBoard().getContainerPlatform().getPreferences());
    prefs.put("build.arch", "AVR");

    IncludesFinder includesFinder = new IncludesFinder(prefs, true);

    Map<String, Object> context = new HashMap<String, Object>();
    context.put("source", input);
    includesFinder.preprocess(context);
    List<String> includes = (List<String>) context.get("includes");

    assertEquals(2, includes.size());
    assertEquals("empty_1.h", includes.get(0));
    assertEquals("empty_2.h", includes.get(1));
  }

}
