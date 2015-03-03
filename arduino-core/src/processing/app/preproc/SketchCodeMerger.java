package processing.app.preproc;

import processing.app.SketchCode;
import processing.app.SketchData;

import java.util.Map;

public class SketchCodeMerger implements PreprocessorChainRing {

  @Override
  public void preprocess(Map<String, Object> context) throws Exception {
    SketchData sketch = (SketchData) context.get("sketch");
    StringBuilder source = new StringBuilder();

    for (SketchCode code : sketch.getCodes()) {
      if (code.isExtension("ino") || code.isExtension("pde")) {
        source.append("#line 1 \"").append(code.getFileName()).append("\"").append("\n");
        source.append(code.getProgram());
        source.append("\n");
      }
    }

    context.put("lineOffset", 1);
    context.put("source", source.toString());
  }

}
