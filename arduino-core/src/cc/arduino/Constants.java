/*
 * This file is part of Arduino.
 *
 * Copyright 2015 Arduino LLC (http://www.arduino.cc/)
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

package cc.arduino;

import java.util.Arrays;
import java.util.List;

public class Constants {

  public static final String PREF_REMOVE_PLACEHOLDER = "___REMOVE___";
  public static final String PREF_BOARDS_MANAGER_ADDITIONAL_URLS = "boardsmanager.additional.urls";
  public static final String PREF_CONTRIBUTIONS_TRUST_ALL = "contributions.trust.all";

  public static final String DEFAULT_INDEX_FILE_NAME = "package_index.json";
  public static final String BUNDLED_INDEX_FILE_NAME = "package_index_bundled.json";
  public static final List<String> PROTECTED_PACKAGE_NAMES = Arrays.asList("arduino", "Intel");

  public static final String LIBRARY_DEVELOPMENT_FLAG_FILE = ".development";

  public static final long BOARDS_LIBS_UPDATABLE_CHECK_START_PERIOD = 60000;
  public static final long NOTIFICATION_POPUP_AUTOCLOSE_DELAY = 10000;

  public static final String PROXY_TYPE_NONE = "none";
  public static final String PROXY_TYPE_AUTO = "auto";
  public static final String PROXY_TYPE_MANUAL = "manual";
  public static final String PROXY_MANUAL_TYPE_HTTP = "HTTP";
  public static final String PROXY_MANUAL_TYPE_SOCKS = "SOCKS";
  public static final String PREF_PROXY_MANUAL_TYPE = "proxy.manual.type";
  public static final String PREF_PROXY_TYPE = "proxy.type";
  public static final String PREF_PROXY_PAC_URL = "proxy.pac.url";
  public static final String PREF_PROXY_MANUAL_HOSTNAME = "proxy.manual.hostname";
  public static final String PREF_PROXY_MANUAL_PORT = "proxy.manual.port";
  public static final String PREF_PROXY_MANUAL_USERNAME = "proxy.manual.username";
  public static final String PREF_PROXY_MANUAL_PASSWORD = "proxy.manual.password";
  public static final String PREF_PROXY_AUTO_USERNAME = "proxy.manual.username";
  public static final String PREF_PROXY_AUTO_PASSWORD = "proxy.manual.password";

  public static final String PACKAGE_INDEX_URL;
  public static final String LIBRARY_INDEX_URL;
  public static final String LIBRARY_INDEX_URL_GZ;

  public static final List<String> LIBRARY_CATEGORIES = Arrays.asList("Display", "Communication", "Signal Input/Output", "Sensors", "Device Control", "Timing", "Data Storage", "Data Processing", "Other", "Uncategorized");
  public static final List<String> LIBRARY_MANDATORY_PROPERTIES = Arrays.asList("name", "version", "author", "maintainer", "sentence", "paragraph", "url");

  static {
    String extenalPackageIndexUrl = System.getProperty("PACKAGE_INDEX_URL");
    if (extenalPackageIndexUrl != null && !"".equals(extenalPackageIndexUrl)) {
      PACKAGE_INDEX_URL = extenalPackageIndexUrl;
    } else {
      PACKAGE_INDEX_URL = "http://downloads.arduino.cc/packages/package_index.json";
    }

    String externalLibraryIndexUrl = System.getProperty("LIBRARY_INDEX_URL");
    if (externalLibraryIndexUrl != null && !externalLibraryIndexUrl.isEmpty()) {
      LIBRARY_INDEX_URL = externalLibraryIndexUrl;
      String externalLibraryIndexUrlGz = System.getProperty("LIBRARY_INDEX_URL_GZ");
      if (externalLibraryIndexUrlGz != null && !externalLibraryIndexUrlGz.isEmpty()) {
        LIBRARY_INDEX_URL_GZ = externalLibraryIndexUrlGz;
      } else {
        LIBRARY_INDEX_URL_GZ = "";
      }
    } else {
      LIBRARY_INDEX_URL = "http://downloads.arduino.cc/libraries/library_index.json";
      LIBRARY_INDEX_URL_GZ = "http://downloads.arduino.cc/libraries/library_index.json.gz";
    }
  }

}
