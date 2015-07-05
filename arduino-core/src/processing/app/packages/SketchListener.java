package processing.app.packages;

import processing.app.SketchCode;
import processing.app.SketchData;

public interface SketchListener {
  
  public enum Event{
    LOAD, INSERTED, SAVED
  }
  
  void onSketchLoad(SketchData sketch);
  
  void onSketchInserted(SketchData sketch, SketchCode code);
  
  void onSketchSaved(SketchData sketch, SketchCode code);
  
}
