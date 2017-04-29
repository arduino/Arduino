package cc.arduino.autocomplete;

import org.fife.ui.autocomplete.CompletionProvider;

import processing.app.Sketch;
import processing.app.syntax.SketchTextArea;

public class CompletionContext {

  private Sketch sketch;

  private SketchTextArea textArea;
  
  private CompletionProvider delegate; // of: AutoComplete/RSyntaxTextArea
  
  public CompletionContext(Sketch sketch, SketchTextArea textArea,CompletionProvider delegate) {
    this.sketch = sketch;
    this.textArea = textArea;
    this.delegate = delegate;
  }


  public String getAlreadyEnteredText() {
    return delegate.getAlreadyEnteredText(textArea);
  }
  
  public int getLineNumber() {
    return textArea.getCaretLineNumber();
  }

  
  public Sketch getSketch() {
    return sketch;
  }
  
  public SketchTextArea getTextArea() {
    return textArea;
  }
  
  public CompletionProvider getDelegate() {
    return delegate;
  }

}
