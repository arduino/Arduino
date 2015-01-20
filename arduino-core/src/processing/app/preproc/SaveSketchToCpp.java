package processing.app.preproc;

import java.io.File;
import java.io.FileOutputStream;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.util.Map;

public class SaveSketchToCpp implements PreprocessorChainRing {

  private final String buildPath;

  public SaveSketchToCpp(String buildPath) {
    this.buildPath = buildPath;
  }

  @Override
  public void preprocess(Map<String, Object> context) throws Exception {
    String sketchName = (String) context.get("sketchName");
    String source = (String) context.get("source");

    File sketchFile = new File(buildPath, sketchName + ".cpp");
    Writer writer = null;
    try {
      writer = new OutputStreamWriter(new FileOutputStream(sketchFile));
      writer.write(source);
    } finally {
      if (writer != null) {
        writer.close();
      }
    }

  }
}
