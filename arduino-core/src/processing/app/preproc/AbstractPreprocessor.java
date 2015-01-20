package processing.app.preproc;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public abstract class AbstractPreprocessor implements Preprocessor {

  protected class FirstStatementPosition {
    int line;
    int charPosition;
  }

  protected FirstStatementPosition firstStatement(String input) {
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

    FirstStatementPosition firstStatementPosition = new FirstStatementPosition();
    firstStatementPosition.charPosition = charPosition;

    String[] lines = input.substring(0, charPosition).split("\n", -1);
    firstStatementPosition.line = lines.length;

    return firstStatementPosition;
  }

}
