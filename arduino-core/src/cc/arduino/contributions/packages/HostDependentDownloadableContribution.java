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

package cc.arduino.contributions.packages;

import cc.arduino.contributions.DownloadableContribution;
import processing.app.Platform;

public abstract class HostDependentDownloadableContribution extends DownloadableContribution {

  public abstract String getHost();

  @Override
  public String toString() {
    return getHost() + " " + super.toString();
  }

  public boolean isCompatible(Platform platform) {
    String osName = platform.getOsName();
    assert osName != null;
    String osArch = platform.getOsArch();
    assert osArch != null;

    String host = getHost();

    if (osName.contains("Linux")) {
      if (osArch.equals("arm")) {
        // Raspberry PI, BBB or other ARM based host

        // PI: "arm-linux-gnueabihf"
        // Arch-linux on PI2: "armv7l-unknown-linux-gnueabihf"
        // Raspbian on PI2: "arm-linux-gnueabihf"
        // Ubuntu Mate on PI2: "arm-linux-gnueabihf"
        // Debian 7.9 on BBB: "arm-linux-gnueabihf"
        // Raspbian on PI Zero: "arm-linux-gnueabihf"
        return host.matches("arm.*-linux-gnueabihf");
      } else if (osArch.contains("amd64")) {
        return host.matches("x86_64-.*linux-gnu");
      } else {
        return host.matches("i[3456]86-.*linux-gnu");
      }
    }

    if (osName.contains("Windows")) {
      return host.matches("i[3456]86-.*mingw32") || host.matches("i[3456]86-.*cygwin");
    }

    if (osName.contains("Mac")) {
      if (osArch.contains("x86_64")) {
        return host.matches("x86_64-apple-darwin.*") || host.matches("i[3456]86-apple-darwin.*");
      } else {
        return host.matches("i[3456]86-apple-darwin.*");
      }
    }

    return false;
  }
}
