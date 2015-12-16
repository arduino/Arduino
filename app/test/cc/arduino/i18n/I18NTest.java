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

package cc.arduino.i18n;

import org.junit.Test;
import processing.app.AbstractWithPreferencesTest;
import processing.app.I18n;

import java.util.Collections;
import java.util.Locale;
import java.util.Map;
import java.util.ResourceBundle;

import static org.junit.Assert.assertEquals;

public class I18NTest extends AbstractWithPreferencesTest {

  @Test
  public void testMessageFormat() throws Exception {
    Object[] args = new Object[]{"a", "b", "c"};
    String actual = I18n.format("WARNING: Category '{0}' in library {1} is not valid. Setting to '{2}'", args);
    assertEquals("WARNING: Category 'a' in library b is not valid. Setting to 'c'", actual);
  }

  @Test
  public void testMessageFormatFromExternalProcess() throws Exception {
    Map<String, Object> output = new ExternalProcessOutputParser().parse("===WARNING: Category '{0}' in library {1} is not valid. Setting to '{2}' ||| [ Wire Uncategorized]");

    String actual = I18n.format((String) output.get("msg"), (Object[]) output.get("args"));
    assertEquals("WARNING: Category '' in library Wire is not valid. Setting to 'Uncategorized'", actual);
  }

  @Test
  public void testAllLocales() {
    for (Language language : Languages.languages) {
      if (!language.getIsoCode().equals("")) {
        Locale locale = toLocale(language);
        ResourceBundle bundle = ResourceBundle.getBundle("processing.app.i18n.Resources", locale);
        if (locale.equals(bundle.getLocale())) {
          Collections.list(bundle.getKeys()).stream().map(bundle::getString).filter(key -> !key.contains("<html")).forEach(key -> {
            try {
              I18n.format(key);
            } catch (IllegalArgumentException e) {
              System.out.println(language);
              System.out.println(key);
              throw e;
            }
          });
        } else {
          System.out.println("Missing locale: " + locale);
        }
      }
    }
  }

  private Locale toLocale(Language language) {
    String[] languageParts = language.getIsoCode().split("_");
    if (languageParts.length == 2) {
      return new Locale(languageParts[0], languageParts[1]);
    }
    return new Locale(languageParts[0]);
  }
}
