package processing.app.preproc;

import org.apache.commons.exec.CommandLine;
import org.apache.commons.exec.Executor;
import processing.app.BaseNoGui;
import processing.app.helpers.FileUtils;
import processing.app.helpers.PreferencesMap;
import processing.app.helpers.StringReplacer;
import processing.app.legacy.PApplet;
import processing.app.tools.CollectStdOutStdErrExecutor;

import java.io.ByteArrayOutputStream;
import java.io.File;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.regex.Pattern;

public class IncludesFinder implements PreprocessorChainRing {

  private static final Pattern ALLOWED_ARG = Pattern.compile("^source$|\\-E$|\\-m$|\\-P$|\\-kb$|\\-D.*");
  private static final String INCLUDE_REGEXP = "^\\s*#include\\s*[<\"](\\S+)[\">]";

  private final PreferencesMap prefs;
  private final boolean verbose;

  public IncludesFinder(PreferencesMap prefs, boolean verbose) {
    this.prefs = prefs;
    this.verbose = verbose;
  }

  @Override
  public void preprocess(Map<String, Object> context) throws Exception {
    String source = (String) context.get("source");
    source = source + "\n";

    File file = FileUtils.saveToTempFile(source, "sketch", ".cpp");

    PreferencesMap dict = new PreferencesMap(prefs);
    dict.putAll(prefs.subTree("tools").subTree("coan"));
    dict.put("source_file", file.getAbsolutePath());

    String[] patterns = StringReplacer.formatAndSplit(dict.getOrExcept("pattern"), dict, true);
    CommandLine commandLine = new CommandLine(patterns[0]);
    for (int i = 1; i < patterns.length; i++) {
      if (ALLOWED_ARG.matcher(patterns[i]).matches() || i == patterns.length - 1) {
        commandLine.addArgument(patterns[i], false);
      }
    }
    if (verbose) {
      System.out.println(commandLine);
    }

    ByteArrayOutputStream stdout = new ByteArrayOutputStream();
    ByteArrayOutputStream stderr = new ByteArrayOutputStream();
    Executor executor = new CollectStdOutStdErrExecutor(stdout, stderr);
    executor.setExitValues(null);
    executor.execute(commandLine);

    if (!verbose) {
      file.delete();
    }

    source = new String(stdout.toByteArray());

    String[][] pieces = PApplet.matchAll(source, INCLUDE_REGEXP);

    List<String> includes = new LinkedList<String>();
    if (pieces != null) {
      for (String[] piece : pieces) {
        includes.add(piece[1]);
      }
    }

    context.put("source", source);
    context.put("includes", includes);
  }

}
