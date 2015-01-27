package processing.app.preproc;

import org.apache.commons.exec.CommandLine;
import org.apache.commons.exec.Executor;
import processing.app.BaseNoGui;
import processing.app.debug.Utils;
import processing.app.helpers.FileUtils;
import processing.app.helpers.PreferencesMap;
import processing.app.helpers.StringReplacer;
import processing.app.helpers.StringUtils;
import processing.app.tools.CollectStdOutStdErrExecutor;

import java.io.ByteArrayOutputStream;
import java.io.File;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class CTagsBakedPreprocessor implements PreprocessorChainRing {

  private final PreferencesMap prefs;
  private final boolean verbose;

  public CTagsBakedPreprocessor(PreferencesMap prefs, boolean verbose) {
    this.prefs = prefs;
    this.verbose = verbose;
  }

  @Override
  public void preprocess(Map<String, Object> context) throws Exception {
    List<File> includeFolders = (List<File>) context.get("includeFolders");

    String includes = Utils.prepareIncludes(includeFolders);
    PreferencesMap dict = new PreferencesMap(prefs);
    dict.putAll(BaseNoGui.getTargetPlatform().getTool("ctags"));
    dict.put("ide_version", "" + BaseNoGui.REVISION);
    dict.put("includes", includes);

    preprocess(context, dict);
  }

  public void preprocess(Map<String, Object> context, PreferencesMap prefs) throws Exception {
    String input = (String) context.get("source");
    File file = FileUtils.saveToTempFile(input, "sketch", ".cpp");

    prefs.put("source_file", file.getAbsolutePath());

    String[] patterns = StringReplacer.formatAndSplit(prefs.getOrExcept("pattern"), prefs, true);
    CommandLine commandLine = new CommandLine(patterns[0]);
    for (int i = 1; i < patterns.length; i++) {
      commandLine.addArgument(patterns[i], false);
    }
    if (verbose) {
      System.out.println(commandLine);
    }
    ByteArrayOutputStream stdout = new ByteArrayOutputStream();
    ByteArrayOutputStream stderr = new ByteArrayOutputStream();
    Executor executor = new CollectStdOutStdErrExecutor(stdout, stderr);
    executor.execute(commandLine);

    String ctagsOutput = new String(stdout.toByteArray());
    List<String> prototypes = new CTagsParser().parse(ctagsOutput);
    context.put("prototypes", prototypes);

    Map<String, Integer> firstStatementPosition = firstStatement(input);

    StringBuilder prototypesSection = new StringBuilder();
    prototypesSection.append("#include <Arduino.h>\n");
    prototypesSection.append(StringUtils.join(prototypes, "\n")).append("\n");
    prototypesSection.append("#line ").append(firstStatementPosition.get("line")).append("\n");

    StringBuilder output = new StringBuilder(input);
    output.insert(firstStatementPosition.get("charPosition"), prototypesSection.toString());

    context.put("source", output.toString());

    if (!verbose) {
      file.delete();
    }
  }

  protected Map<String, Integer> firstStatement(String input) {
    // whitespace
    String p = "\\s+";

    // multi-line and single-line comment
    //p += "|" + "(//\\s*?$)|(/\\*\\s*?\\*/)";
    p += "|(/\\*[^*]*(?:\\*(?!/)[^*]*)*\\*/)|(//.*?$)";

    // pre-processor directive
    p += "|(#(?:\\\\\\n|.)*)";

    // pre-processor directive
    p += "|typedef.*";

    Pattern pattern = Pattern.compile(p, Pattern.MULTILINE);

    Matcher matcher = pattern.matcher(input);
    int charPosition = 0;
    while (matcher.find()) {
      if (matcher.start() != charPosition)
        break;
      charPosition = matcher.end();
    }

    Map<String, Integer> firstStatementPosition = new HashMap<String, Integer>();
    firstStatementPosition.put("charPosition", charPosition);

    String[] lines = input.substring(0, charPosition).split("\n", -1);
    firstStatementPosition.put("line", lines.length);

    return firstStatementPosition;
  }


}
