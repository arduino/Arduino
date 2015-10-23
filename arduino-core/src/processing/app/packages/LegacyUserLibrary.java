/*
 * This file is part of Arduino.
 *
 * Copyright 2014 Arduino LLC (http://www.arduino.cc/)
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
package processing.app.packages;

import java.io.File;
import java.util.Arrays;
import java.util.List;
import javax.swing.JOptionPane;

public class LegacyUserLibrary extends UserLibrary {

  private String name;

  public static LegacyUserLibrary create(File libFolder) {
  
    //Check legacy libraries for examples using .pde extensions.
	//.pde examples no longer compile as the builder uses a hard coded .ino extension.
    File examplesFolder = new File(libFolder, "examples");
    boolean hasNotifiedOfPdeExamples = false;
    
    if (examplesFolder.isDirectory()){
    
      File[] dirs = examplesFolder.listFiles();
      
      if (dirs != null){
example_verify_loop:  //Label to break out of if the user chooses not to update a library.
        for (File childDir : dirs) {
        
          if (childDir.isDirectory()){
          
            File[] sketchFiles = childDir.listFiles();
            
            for (File childFile : sketchFiles) {
            
              if (childFile.isFile()){
                if (childFile.getName().endsWith(".pde")){
                  if (!hasNotifiedOfPdeExamples){ //only prompt once per library.
                
                    int msgResult = JOptionPane.showConfirmDialog(
                      null,
                      "One or more of the examples in the library \"" + libFolder.getName() + "\" uses a file extension that is no longer compatible with the IDE." +
                      "\nSketches (and examples) since version 1.0 of the IDE are required to use '.ino' extensions!" +
                      "\nPrior to version 1.0, the extension used  was '.pde'." +
                      "\nClick yes to update the extensions of these files automatically (contents is not touched).",
                      libFolder.getName() + " contains out of date examples!",
                      JOptionPane.YES_NO_OPTION,
                      JOptionPane.QUESTION_MESSAGE);
              
                    if (msgResult == 1){
                      break example_verify_loop;
                    }
                    hasNotifiedOfPdeExamples = true;
                  }
                  childFile.renameTo(new File(childFile.getPath().replace(".pde", ".ino")));
                }
              }
            }
          }
        }
      }
    }

    // construct an old style library
    LegacyUserLibrary res = new LegacyUserLibrary();
    res.setInstalledFolder(libFolder);
    res.setInstalled(true);
    res.layout = LibraryLayout.FLAT;
    res.name = libFolder.getName();
    res.setTypes(Arrays.asList("Contributed"));
    res.setCategory("Uncategorized");
    return res;
  }

  @Override
  public String getName() {
    return name;
  }

  @Override
  public List<String> getArchitectures() {
    return Arrays.asList("*");
  }

  @Override
  public String toString() {
    return "LegacyLibrary:" + name + "\n";
  }

}
