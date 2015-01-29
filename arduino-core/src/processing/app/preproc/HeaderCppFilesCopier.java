package processing.app.preproc;

import processing.app.BaseNoGui;
import processing.app.SketchCode;
import processing.app.SketchData;

import java.io.File;
import java.util.Map;

public class HeaderCppFilesCopier implements PreprocessorChainRing {

  private final String buildPath;

  public HeaderCppFilesCopier(String buildPath) {
    this.buildPath = buildPath;
  }

  @Override
  public void preprocess(Map<String, Object> context) throws Exception {
    SketchData sketch = (SketchData) context.get("sketch");

    for (SketchCode sc : sketch.getCodes()) {
      if (sc.isExtension("c") || sc.isExtension("cpp") || sc.isExtension("h")) {
        BaseNoGui.saveFile(sc.getProgram(), new File(buildPath, sc.getFileName()));
      }
    }
  }

}
