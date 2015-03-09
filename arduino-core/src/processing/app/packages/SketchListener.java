package processing.app.packages;

import processing.app.BaseSketch;
import processing.app.SketchCode;

public interface SketchListener {
  
  public enum Event{
    LOAD, INSERTED, SAVED
  }
  
  void onSketchLoad(BaseSketch sketch);
  
  void onSketchInserted(BaseSketch sketch, SketchCode code);
  
  void onSketchSaved(BaseSketch sketch, SketchCode code);
  
}
