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
import java.util.Collections;
import java.util.EnumSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Set;
import java.util.function.BiConsumer;
import java.util.function.BinaryOperator;
import java.util.function.Function;
import java.util.function.Supplier;
import java.util.stream.Collector;

import processing.app.helpers.FileUtils;

@SuppressWarnings("serial")
public class LibraryList extends LinkedList<UserLibrary> {

  public LibraryList(LibraryList libs) {
    super(libs);
  }

  public LibraryList() {
    super();
  }

  public LibraryList(List<UserLibrary> ideLibs) {
    super(ideLibs);
  }

  public synchronized UserLibrary getByName(String name) {
    for (UserLibrary l : this)
      if (l.getName().equals(name))
        return l;
    return null;
  }

  public synchronized void sort() {
    Collections.sort(this, (x, y) -> x.getName().compareToIgnoreCase(y.getName()));
  }

  public synchronized LibraryList filterLibrariesInSubfolder(File subFolder) {
    LibraryList res = new LibraryList();
    for (UserLibrary lib : this) {
      if (FileUtils.isSubDirectory(subFolder, lib.getInstalledFolder())) {
        res.add(lib);
      }
    }
    return res;
  }

  public synchronized boolean hasLibrary(UserLibrary lib) {
    for (UserLibrary l : this)
      if (l == lib) return true;
    return false;
  }

  public static Collector<UserLibrary, LibraryList, LibraryList> collector() {
    return new Collector<UserLibrary, LibraryList, LibraryList>() {
      @Override
      public Supplier<LibraryList> supplier() {
        return () -> new LibraryList();
      }

      @Override
      public BiConsumer<LibraryList, UserLibrary> accumulator() {
        return (libs, lib) -> libs.add(lib);
      }

      @Override
      public BinaryOperator<LibraryList> combiner() {
        return (we, they) -> {
          we.addAll(they);
          return we;
        };
      }

      @Override
      public Function<LibraryList, LibraryList> finisher() {
        return (libs) -> libs;
      }

      @Override
      public Set<Collector.Characteristics> characteristics() {
        return EnumSet.noneOf(Characteristics.class);
      }
    };
  }
}
