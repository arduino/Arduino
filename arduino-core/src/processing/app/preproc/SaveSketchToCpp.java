package processing.app.preproc;

import processing.app.SketchCode;
import processing.app.SketchData;

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
    SketchData sketch = (SketchData) context.get("sketch");
    String source = (String) context.get("source");

    File sketchFile = new File(buildPath, sketch.getName() + ".cpp");
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
