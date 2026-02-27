/*
 * This file is part of Arduino.
 *
 * Copyright 2019 Arduino LLC (http://www.arduino.cc/)
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


package cc.arduino.utils.network;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class CacheControl {


  // see org.apache.abdera.protocol.util.CacheControlUtil
  private static final Pattern PATTERN
    = Pattern.compile("\\s*([\\w\\-]+)\\s*(=)?\\s*(\\-?\\d+|\\\"([^\"\\\\]*(\\\\.[^\"\\\\]*)*)+\\\")?\\s*");

  private int maxAge = -1;

  private boolean isMustRevalidate = false;

  private boolean isNoCache = false;

  private boolean isNoStore = false;


  public static CacheControl valueOf(String value) {
    CacheControl cc = new CacheControl();

    if (value != null) {
      Matcher matcher = PATTERN.matcher(value);
      while (matcher.find()) {
        switch (matcher.group(1).toLowerCase()) {
          case "max-age":
            cc.setMaxAge(Integer.parseInt(matcher.group(3)));
            break;
          case "must-revalidate":
            cc.setMustRevalidate(true);
            break;
          case "no-cache":
            cc.setNoCache(true);
            break;
          case "no-store":
            cc.setNoStore(true);
            break;
          default: //ignore
        }
      }
    }
    return cc;
  }

  public void setMaxAge(int maxAge) {
    this.maxAge = maxAge;
  }

  public int getMaxAge() {
    return maxAge;
  }

  public boolean isMustRevalidate() {
    return isMustRevalidate;
  }

  public void setMustRevalidate(boolean mustRevalidate) {
    isMustRevalidate = mustRevalidate;
  }

  public boolean isNoCache() {
    return isNoCache;
  }

  public void setNoCache(boolean noCache) {
    isNoCache = noCache;
  }

  public boolean isNoStore() {
    return isNoStore;
  }

  public void setNoStore(boolean noStore) {
    isNoStore = noStore;
  }

  @Override
  public String toString() {
    return "CacheControl{" +
      "maxAge=" + maxAge +
      ", isMustRevalidate=" + isMustRevalidate +
      ", isNoCache=" + isNoCache +
      ", isNoStore=" + isNoStore +
      '}';
  }
}
