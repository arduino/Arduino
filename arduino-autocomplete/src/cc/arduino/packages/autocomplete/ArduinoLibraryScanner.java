/* -*- mode: java; c-basic-offset: 2; indent-tabs-mode: nil -*- */

/*
 * This file is part of Arduino.
 *
 * Copyright 2015 Ricardo JL Rufino (ricardo@criativasoft.com.br)
 * Copyright 2015 Arduino LLC
 *
 * Arduino is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * As a special exception, you may use this file as part of a free software
 * library without restriction.  Specifically, if other files instantiate
 * templates or use macros or inline functions from this file, or you compile
 * this file and link it with other files to produce an executable, this
 * file does not by itself cause the resulting executable to be covered by
 * the GNU General Public License.  This exception does not however
 * invalidate any other reasons why the executable file might be covered by
 * the GNU General Public License.
 */

package cc.arduino.packages.autocomplete;

import java.io.File;
import java.util.ArrayList;
import java.util.List;

import processing.app.helpers.filefilters.OnlyFilesWithExtension;
import processing.app.packages.UserLibrary;
import br.com.criativasoft.cpluslibparser.LibraryScanner;
import br.com.criativasoft.cpluslibparser.SourceParser;

/**
 * Scanner for Arduino libraries.
 * This class is only a bridge between the libraries and the {@link SourceParser}, making the settings and adjustments
 * @author Ricardo JL Rufino (ricardo@criativasoft.com.br) 
 * @date 20/11/2014
 */
public class ArduinoLibraryScanner extends LibraryScanner {
	
  public static final String SKETCH_LIB_PREFIX = "private:sketch:"; // for autocomplete metadata
  
  private UserLibrary library;
  
  private static final List<String> ignoredFiles = new ArrayList<String>();
  
  static{
    ignoredFiles.add("USBCore.h");
    ignoredFiles.add("USBDesc.h");
  }

  public ArduinoLibraryScanner(UserLibrary library) {
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
