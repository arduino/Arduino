package processing.app;

import java.io.File;

import javax.swing.event.DocumentEvent;
import javax.swing.event.DocumentListener;
import javax.swing.text.Document;

public class SketchCodeDocument implements DocumentListener {

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

  public void setDocument(Document document) {
    document.addDocumentListener(this);
  }

  @Override
  public void insertUpdate(DocumentEvent e) {
    if(!code.isModified()) sketch.setModified(true);
  }


  @Override
  public void removeUpdate(DocumentEvent e) {
    if(!code.isModified()) sketch.setModified(true);
  }

  @Override
  public void changedUpdate(DocumentEvent e) {
    // ignore
  }
  
}
