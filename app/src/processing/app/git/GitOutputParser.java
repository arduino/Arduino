package processing.app.git;

import java.io.InputStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class GitOutputParser {

  /**
   * It divides diff output in two parts.
   * @param in stream with diff text
   * @return result of parsing
     */
  public ParserResult diffParser(InputStream in) {
    DiffText newText = new DiffText();
    DiffText oldText = new DiffText();

    StringBuilder newBuilder = new StringBuilder();
    StringBuilder oldBuilder = new StringBuilder();

    Scanner scanner = new Scanner(in);
    while (scanner.hasNext()) {
      String string = scanner.nextLine();
      if (string.startsWith("@@")) {
        break;
      }
    }

    while (scanner.hasNext()) {
      String str = scanner.nextLine();

      if (str.startsWith("+")) {
        newText.getBeginIndexes().add(newBuilder.length());
        newBuilder.append(str.substring(1)).append("\n");
        newText.getEndIndexes().add(newBuilder.length());
        continue;
      }

      if (str.startsWith("-")) {
        oldText.getBeginIndexes().add(oldBuilder.length());
        oldBuilder.append(str.substring(1)).append("\n");
        oldText.getEndIndexes().add(oldBuilder.length());
        continue;
      }

      newBuilder.append(str).append("\n");
      oldBuilder.append(str).append("\n");
    }

    newText.text = newBuilder.toString();
    oldText.text = oldBuilder.toString();

    return new ParserResult(newText, oldText);
  }
  
  public static class ParserResult {
    private DiffText newText;
    private DiffText oldText;

    public ParserResult(DiffText newText, DiffText oldText) {
      this.newText = newText;
      this.oldText = oldText;
    }

    public DiffText getNewText() {
      return newText;
    }

    public DiffText getOldText() {
      return oldText;
    }
  }

  public static class DiffText {
    private String text;
    private List<Integer> beginIndexes = new ArrayList<>();
    private List<Integer> endIndexes = new ArrayList<>();

    public String getText() {
      return text;
    }

    public List<Integer> getBeginIndexes() {
      return beginIndexes;
    }

    public List<Integer> getEndIndexes() {
      return endIndexes;
    }
  }

}
