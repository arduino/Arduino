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

import static processing.app.I18n.tr;

public class Languages {

  public static final Language[] languages;

  static {
    languages = new Language[]{
      new Language(tr("System Default"), "", ""),
      new Language(tr("Acoli"), "Lwo", "ach"),
      new Language(tr("Afrikaans"), "Afrikaans", "af"),
      new Language(tr("Albanian"), "shqip", "sq"),
      new Language(tr("Arabic"), "العربية", "ar"),
      new Language(tr("Aragonese"), "Aragonés", "an"),
      new Language(tr("Armenian"), "Հայերեն", "hy"),
      new Language(tr("Asturian"), "Asturianu", "ast"),
      new Language(tr("Basque"), "Euskara", "eu"),
      new Language(tr("Belarusian"), "Беларуская мова", "be"),
      new Language(tr("Bosnian"), "Bosanski", "bs"),
      new Language(tr("Bulgarian"), "български", "bg"),
      new Language(tr("Burmese (Myanmar)"), "ဗမာစကား", "my_MM"),
      new Language(tr("Canadian French"), "Canadienne-français", "fr_CA"),
      new Language(tr("Catalan"), "Català", "ca"),
      new Language(tr("Chinese (China)"), "简体中文", "zh_CN"),
      new Language(tr("Chinese (Taiwan) (Big5)"), "台語 (Big5)", "zh_TW.Big5"),
      new Language(tr("Chinese (Taiwan)"), "台語", "zh_TW"),
      new Language(tr("Croatian"), "Hrvatski", "hr_HR"),
      new Language(tr("Czech (Czech Republic)"), "český (Czech Republic)", "cs_CZ"),
      new Language(tr("Danish (Denmark)"), "Dansk (Denmark)", "da_DK"),
      new Language(tr("Dutch"), "Nederlands", "nl"),
      new Language(tr("Dutch (Netherlands)"), "Nederlands", "nl_NL"),
      new Language(tr("English"), "English", "en"),
      new Language(tr("English (United Kingdom)"), "English (United Kingdom)", "en_GB"),
      new Language(tr("Estonian"), "Eesti", "et"),
      new Language(tr("Estonian (Estonia)"), "Eesti keel", "et_EE"),
      new Language(tr("Filipino"), "Pilipino", "fil"),
      new Language(tr("Finnish"), "Suomi", "fi"),
      new Language(tr("French"), "Français", "fr"),
      new Language(tr("Galician"), "Galego", "gl"),
      new Language(tr("Galician (Spain)"), "Galego (Spain)", "gl_ES"),
      new Language(tr("Georgian"), "საქართველოს", "ka_GE"),
      new Language(tr("German"), "Deutsch", "de_DE"),
      new Language(tr("Greek"), "ελληνικά", "el_GR"),
      new Language(tr("Hebrew"), "עברית", "he"),
      new Language(tr("Hindi"), "हिंदी", "hi"),
      new Language(tr("Hungarian"), "Magyar", "hu"),
      new Language(tr("Indonesian"), "Bahasa Indonesia", "id"),
      new Language(tr("Italian"), "Italiano", "it_IT"),
      new Language(tr("Japanese"), "日本語", "ja_JP"),
      new Language(tr("Kazakh"), "قازاق ٴتىلى", "kk"),
      new Language(tr("Korean"), "한국어", "ko_KR"),
      new Language(tr("Latvian"), "Latviešu", "lv_LV"),
      new Language(tr("Lithuaninan"), "Lietuvių Kalba", "lt_LT"),
      new Language(tr("Marathi"), "मराठी", "mr"),
      new Language(tr("Nepali"), "नेपाली", "ne"),
      new Language(tr("Norwegian Bokmål"), "Norsk bokmål", "nb_NO"),
      new Language(tr("Persian (Iran)"), "فارسی (Iran)", "fa_IR"),
      new Language(tr("Persian"), "فارسی", "fa"),
      new Language(tr("Polish"), "Język Polski", "pl"),
      new Language(tr("Portugese"), "Português", "pt"),
      new Language(tr("Portuguese (Brazil)"), "Português (Brazil)", "pt_BR"),
      new Language(tr("Portuguese (Portugal)"), "Português (Portugal)", "pt_PT"),
      new Language(tr("Romanian"), "Română", "ro"),
      new Language(tr("Russian"), "Русский", "ru"),
      new Language(tr("Slovak"), "Slovenčina", "sk"),
      new Language(tr("Slovenian"), "Slovenščina", "sl_SI"),
      new Language(tr("Spanish"), "Español", "es"),
      new Language(tr("Swedish"), "Svenska", "sv"),
      new Language(tr("Talossan"), "Talossan", "tzl"),
      new Language(tr("Tamil"), "தமிழ்", "ta"),
      new Language(tr("Telugu"), "తెలుగు", "te"),
      new Language(tr("Thai"), "ภาษาไทย", "th"),
      new Language(tr("Turkish"), "Türk", "tr"),
      new Language(tr("Ukrainian"), "Українська", "uk"),
      new Language(tr("Vietnamese"), "Tiếng Việt", "vi"),
      new Language(tr("Western Frisian"), "Western Frisian", "fy")
    };

  }

}
