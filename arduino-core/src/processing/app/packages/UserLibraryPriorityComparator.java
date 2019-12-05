/*
 * This file is part of Arduino.
 *
 * Copyright 2017 Arduino LLC (http://www.arduino.cc/)
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

import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;

import static processing.app.packages.UserLibrary.LOCATION_CORE;
import static processing.app.packages.UserLibrary.LOCATION_IDE;
import static processing.app.packages.UserLibrary.LOCATION_REF_CORE;
import static processing.app.packages.UserLibrary.LOCATION_SKETCHBOOK;

public class UserLibraryPriorityComparator implements Comparator<UserLibrary> {

  private final static Map<String, Integer> priorities = new HashMap<>();
  static {
    priorities.put(LOCATION_SKETCHBOOK, 4);
    priorities.put(LOCATION_CORE, 3);
    priorities.put(LOCATION_REF_CORE, 2);
    priorities.put(LOCATION_IDE, 1);
  }

  private String arch;

  public UserLibraryPriorityComparator(String currentArch) {
    arch = currentArch;
  }

  private boolean hasArchitecturePriority(UserLibrary x) {
    return x.getArchitectures().contains(arch);
  }

  public int priority(UserLibrary l) {
    int priority = priorities.get(l.getLocation());
    if (hasArchitecturePriority(l))
      priority += 10;
    return priority;
  }

  @Override
  public int compare(UserLibrary x, UserLibrary y) {
    if (!x.getName().equals(y.getName())) {
      throw new IllegalArgumentException("The compared libraries must have the same name");
    }
    return priority(x) - priority(y);
  }
}
