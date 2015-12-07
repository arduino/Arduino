package processing.app;

import java.io.File;

import javax.swing.event.DocumentEvent;
import javax.swing.event.DocumentListener;
import javax.swing.text.Document;

public class SketchCodeDocument {

  private SketchCode code;
  private Sketch sketch;

  public SketchCodeDocument(Sketch sketch, SketchCode code) {
    this.code = code;
    this.sketch = sketch;
    this.code.setMetadata(this);
  }

  public SketchCodeDocument(Sketch sketch, File file) {
    this(sketch, new SketchCode(file));
  }

  public SketchCode getCode() {
    return code;
  }

  public void setCode(SketchCode code) {
    this.code = code;
  }

  
}
