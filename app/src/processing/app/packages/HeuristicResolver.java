/*
 * This file is part of Arduino.
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
 *
 * Copyright 2013 Arduino LLC (http://www.arduino.cc/)
 */

package processing.app.packages;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import processing.app.helpers.FileUtils;
import processing.app.helpers.filefilters.OnlyFilesWithExtension;
import processing.app.preproc.PdePreprocessor;

/**
 * This resolver uses an heuristic approach to resolve dependencies between
 * libraries without looking into libraries metadata.
 * 
 * All libraries headers are inspected to search for #include lines, afterward
 * import dependencies are searched in the same way we do for includes in
 * sketches, i.e. looking for a library containing the requested headers.
 */
public class HeuristicResolver implements LibraryResolver {

  private LibraryList libraries;
  private Map<String, Library> importToLibrary;

  public HeuristicResolver(LibraryList _libraries, String arch) {
    libraries = _libraries;
    importToLibrary = new HashMap<String, Library>();

    // Populate importToLibrary table
    for (Library library : libraries) {
      File srcFolder = library.getSrcFolder();
      for (String header : srcFolder.list(new OnlyFilesWithExtension(".h"))) {
        importToLibrary.put(header, library);
      }
    }

    // Resolve all libraries dependencies
    for (Library library : libraries)
      library.resolvedDependencies = findLibraryDependencies(library, arch);
  }

  /**
   * Resolve dependencies for a library
   * 
   * @param library
   * @param arch
   * @return A LibraryList containing the dependencies
   */
  private LibraryList findLibraryDependencies(Library library, String arch) {
    List<File> headers = new ArrayList<File>();
    boolean recursive = !library.isPre15Lib();
    for (File folder : library.getSrcFolders(arch)) {
      List<File> files = FileUtils
          .listAllFilesWithExtension(folder, recursive, ".h", ".c", ".cpp");
      headers.addAll(files);
    }

    LibraryList result = new LibraryList();
    for (File header : headers)
      result.addOrReplaceAll(findHeaderDependencies(header, headers, library));
    return result;
  }

  /**
   * Inspect headerFile and search for dependencies
   * 
   * @param headerFile
   * @param exclusionList
   * @param library
   */
  private LibraryList findHeaderDependencies(File headerFile,
                                             List<File> exclusionList,
                                             Library library) {
    LibraryList res = new LibraryList();

    // Extract #includes from header file
    List<String> imports;
    try {
      PdePreprocessor preprocessor = new PdePreprocessor();
      String header = FileUtils.readFileToString(headerFile);
      preprocessor.writePrefix(header);
      imports = preprocessor.getExtraImports();
    } catch (IOException e) {
      e.printStackTrace();
      return res;
    }

    // For every #include found...
    for (String libImport : imports) {

      // ...check if there is a matching library...
      Library depLib = importToLibrary.get(libImport);
      if (depLib == null || depLib == library)
        continue;

      // ...and check if the include is not in the exclusion list
      boolean exclude = false;
      for (File excluded : exclusionList) {
        if (excluded.getName().equals(libImport))
          exclude = true;
      }
      if (exclude)
        continue;

      // add the dependency
      res.addOrReplace(depLib);

      System.out.println("Found dependency for " + library.getName());
      System.out.println("   " + headerFile + " uses " + libImport + " -> " +
          depLib.getName());
    }

    return res;
  }

  @Override
  public Library importToLibrary(String h) {
    return importToLibrary.get(h);
  }

}
