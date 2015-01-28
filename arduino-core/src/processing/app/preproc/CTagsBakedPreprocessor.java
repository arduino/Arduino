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
import java.util.Arrays;
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

    String ctagsOutput = runCTagsAndGetOutput(prefs, file);

    parseCTagsOutput(context, ctagsOutput);

    StringBuilder output = new StringBuilder(input);

    int lineWhereToInsertInclude = composeIncludeSection(context);
    int charWhereToInsertInclude = charPositionOfLine(input, lineWhereToInsertInclude);
    output.insert(charWhereToInsertInclude, context.get("includeSection"));

    int lineWhereToInsertPrototypes = composePrototypeSection(context);
    int charWhereToInsertPrototypes = charPositionOfLine(input, lineWhereToInsertPrototypes) + context.get("includeSection").toString().length();
    output.insert(charWhereToInsertPrototypes, context.get("prototypesSection"));

    context.put("source", output.toString());

    if (!verbose) {
      file.delete();
    }
  }

  private int composeIncludeSection(Map<String, Object> context) {
    int firstStatementAtLine = firstStatementAtLine((String) context.get("source"));

    StringBuilder section = new StringBuilder();
    section.append("#include <Arduino.h>\n");
    section.append("#line ").append(firstStatementAtLine).append("\n");

    context.put("includeSection", section);

    return firstStatementAtLine;
  }

  private int composePrototypeSection(Map<String, Object> context) {
    int line = 1;
    if (context.containsKey("firstFunctionAtLine")) {
      line = (Integer) context.get("firstFunctionAtLine");
    }

    StringBuilder section = new StringBuilder();

    List<String> prototypes = (List<String>) context.get("prototypes");
    section.append(StringUtils.join(prototypes, "\n")).append("\n");
    section.append("#line ").append(line).append("\n");

    context.put("prototypesSection", section);

    return line;
  }

  private void parseCTagsOutput(Map<String, Object> context, String ctagsOutput) throws Exception {
    context.put("ctagsOutput", ctagsOutput);
    new CTagsParser().preprocess(context);
  }

  private String runCTagsAndGetOutput(PreferencesMap prefs, File file) throws Exception {
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

    return new String(stdout.toByteArray());
  }

  private int charPositionOfLine(String input, int firstFunctionAtLine) {
    List<String> rows = Arrays.asList(input.split("\n", -1)).subList(0, firstFunctionAtLine - 1);

    String inputUntilFirstFunction = StringUtils.join(rows, "\n", false);

    return inputUntilFirstFunction.length();
  }


  private int firstStatementAtLine(String input) {
    // whitespace
    String p = "\\s+";

    // multi-line and single-line comment
    //p += "|" + "(//\\s*?$)|(/\\*\\s*?\\*/)";
    p += "|(/\\*[^*]*(?:\\*(?!/)[^*]*)*\\*/)|(//.*?$)";

    // pre-processor directive
    p += "|(#(?:\\\\\\n|.)*)";

    Pattern pattern = Pattern.compile(p, Pattern.MULTILINE);

    Matcher matcher = pattern.matcher(input);
    int charPosition = 0;
    while (matcher.find()) {
      if (matcher.start() != charPosition) {
        break;
      }
      charPosition = matcher.end();
    }

    String[] lines = input.substring(0, charPosition).split("\n", -1);
    return lines.length;
  }

}
