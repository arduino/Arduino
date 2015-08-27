package processing.app.windows;

import java.util.Arrays;
import java.util.List;

public class RegQueryParser {

  private String valueOfKey;

  public RegQueryParser(String regQueryOutput) {
    parse(regQueryOutput);
  }

  private void parse(String regQueryOutput) {
    List<String> rows = Arrays.asList(regQueryOutput.replace("    ", "\t").replace("\r", "\n").replace("\n\n", "\n").split("\n"));

    String row = rows.stream().filter(input -> input.startsWith("\t")).findFirst().get();

    String[] cols = row.split("\t");
    assert cols.length == 4;
    this.valueOfKey = cols[3];
  }

  public String getValueOfKey() {
    return valueOfKey;
  }
}
