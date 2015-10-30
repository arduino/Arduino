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
 * Copyright 2015 Arduino LLC (http://www.arduino.cc/)
 */

package cc.arduino;

import processing.app.helpers.PreferencesMap;
import processing.app.helpers.PreferencesMapException;
import processing.app.helpers.StringReplacer;

import java.io.File;
import java.util.Arrays;
import java.util.List;
import java.util.Optional;

import static processing.app.I18n.tr;

public class CompilerUtils {

  public File findCompiledSketch(PreferencesMap prefs) throws PreferencesMapException {
    List<String> paths = Arrays.asList(
      "{build.path}/sketch/{build.project_name}.with_bootloader.hex",
      "{build.path}/sketch/{build.project_name}.hex",
      "{build.path}/{build.project_name}.with_bootloader.hex",
      "{build.path}/{build.project_name}.hex",
      "{build.path}/sketch/{build.project_name}.bin",
      "{build.path}/{build.project_name}.bin",
      "{build.path}/sketch/{build.project_name}.elf",
      "{build.path}/{build.project_name}.elf"
    );
    Optional<File> sketch = paths.stream().
      map(path -> StringReplacer.replaceFromMapping(path, prefs)).
      map(File::new).
      filter(File::exists).
      findFirst();
    return sketch.orElseThrow(() -> new IllegalStateException(tr("No compiled sketch found")));
  }

}
