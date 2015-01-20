package processing.app.debug;

import java.io.File;
import java.util.List;

public class Utils {

  public static String prepareIncludes(List<File> includeFolders) {
    StringBuilder sb = new StringBuilder();
    for (File p : includeFolders) {
      sb.append(" \"-I").append(p.getAbsolutePath()).append('"');
    }

    // Remove first space
    return sb.substring(1).toString();
  }

}
