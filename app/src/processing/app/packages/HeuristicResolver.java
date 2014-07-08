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
import java.util.LinkedList;
import java.util.Map;

import processing.app.Sketch;
import processing.app.SketchCode;
import processing.app.helpers.FileUtils;
import processing.app.helpers.filefilters.OnlyFilesWithExtension;
import processing.app.preproc.PdePreprocessor;
import processing.core.PApplet;

/**
 * This resolver uses an heuristic approach to resolve dependencies
 * without looking into metadata.
 */
public class HeuristicResolver implements LibraryResolver {

  private LibraryList libraries;
  private Map<String, Library> importToLibrary;

  public HeuristicResolver(LibraryList _libraries) {
    libraries = _libraries;
    importToLibrary = new HashMap<String, Library>();

    // Populate importToLibrary table
    for (Library library : libraries) {
      for (String header : library.getPublicHeaders()) {
        Library old = importToLibrary.get(header);
        if (old != null) {
          // If a library was already found with this header, keep
          // it if the library's name matches the header name.
          String name = header.substring(0, header.length() - 2);
          if (old.getFolder().getPath().endsWith(name))
            continue;
        }
        importToLibrary.put(header, library);
      }
    }
  }

  @Override
  public LibraryList findDirectDependencies(Sketch sketch) {
    SketchCode files[] = sketch.getCode();
    LibraryList result = new LibraryList();
    for (SketchCode code : files)
      result.addOrReplaceAll(findSourceDependencies(code.getFile(), null, null));
    return result;
  }

  /**
   * Inspect headerFile and search for dependencies
   *
   * @param headerFile
   * @param excluded
   * @param library
   */
  private LibraryList findSourceDependencies(File headerFile,
                                             List<String> excluded,
                                             Library library) {
    LibraryList res = new LibraryList();


    // Extract #includes from header file
    List<String> imports;
    String contents;
    try {
      contents = FileUtils.readFileToString(headerFile);
    } catch (IOException e) {
      e.printStackTrace();
      return res;
    }

    String importRegexp = "^\\s*#include\\s*[<\"](\\S+)[\">]";
    String[][] pieces = PApplet.matchAll(contents, importRegexp);

    // For every #include found...
    if (pieces != null) {
      for (int i = 0; i < pieces.length; i++) {
        String libImport = pieces[i][1];

        // ...check if the include is not in the exclusion list
        if (excluded != null && excluded.contains(libImport))
          continue;

        // ...check if there is a matching library
        Library depLib = importToLibrary.get(libImport);
        if (depLib == null || depLib == library)
          continue;

        // ...that we didn't see before
        if (res.contains(depLib))
          continue;

        // add the dependency
        res.add(depLib);
      }
    }

    return res;
  }

  @Override
  public Library importToLibrary(String h) {
    return importToLibrary.get(h);
  }

}
