package cc.arduino.packages.autocomplete;

import java.io.File;
import java.util.ArrayList;
import java.util.List;

import processing.app.helpers.filefilters.OnlyFilesWithExtension;
import processing.app.packages.Library;
import br.com.criativasoft.cpluslibparser.LibraryScanner;
import br.com.criativasoft.cpluslibparser.SourceParser;

/**
 * Scanner for Arduino libraries.
 * This class is only a bridge between the libraries and the {@link SourceParser}, making the settings and adjustments
 * @author Ricardo JL Rufino (ricardo@criativasoft.com.br) 
 * @date 20/11/2014
 */
public class ArduinoLibraryScanner extends LibraryScanner {
  
  private Library library;
  
  private static final List<String> ignoredFiles = new ArrayList<String>();
  
  static{
    ignoredFiles.add("USBCore.h");
    ignoredFiles.add("USBDesc.h");
  }

  public ArduinoLibraryScanner(Library library) {
    this.library = library;
  }

  @Override
  protected File[] getFilesToParse(File folder) {
    
    // check /src directory
    File src = new File(folder, "src");
    if(src.exists()){
        folder =  src;
    }
    
    return folder.listFiles(new OnlyFilesWithExtension(ignoredFiles, ".h"));
  }

  @Override
  protected void configParser(SourceParser parser, File currentFile) {
    parser.addMacro("UBRR0H", "1"); // Enable Serial !
  }

  @Override
  protected String getLibraryName() {
    return library.getName();
  }

}
