package cc.arduino.packages.autocomplete;

import java.io.File;

import processing.app.BaseSketch;
import processing.app.SketchCode;
import processing.app.helpers.filefilters.OnlyFilesWithExtension;
import br.com.criativasoft.cpluslibparser.LibraryScanner;
import br.com.criativasoft.cpluslibparser.SourceParser;

public class SketchCodeScanner extends LibraryScanner  {
  
  private SketchCode code;
  private BaseSketch sketch;
  
  public SketchCodeScanner(SketchCode code) {
    this(code.getSketch());
    this.code = code;
  }
  
  public SketchCodeScanner(BaseSketch sketch) {
    super();
    this.sketch = sketch;
    setSerialize(false); // not cache
    setDeserialize(false);  // not cache
  }

  @Override
  protected File[] getFilesToParse(File folder) {
    
    if(code != null){ // single file{
      
      return new File[]{code.getFile()};
      
    }else{
      
      return folder.listFiles(new OnlyFilesWithExtension("ino", "pde", "c", "cpp", "h")); 
      
    }
    
  }

  @Override
  protected void configParser(SourceParser parser, File currentFile) {
    parser.setParseInternalAttrs(true);
    if(currentFile == null) parser.setDefaultFileName(code.getFileName());
  }

  @Override
  protected String getLibraryName() {
    return SketchCompletionProvider.SKETCH_LIB_PREFIX + sketch.getName();
  }

}
