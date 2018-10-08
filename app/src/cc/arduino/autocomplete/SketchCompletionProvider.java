/*
 * This file is part of Arduino.
 *
 * Copyright 2017 Arduino LLC (http://www.arduino.cc/)
 *                Ricardo JL Rufino (ricardo@criativasoft.com.br)
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

package cc.arduino.autocomplete;

import org.fife.ui.autocomplete.CompletionProvider;
import org.fife.ui.autocomplete.LanguageAwareCompletionProvider;

import processing.app.Sketch;
import processing.app.syntax.SketchTextArea;

/**
 * CompletionProvider for Arduino/CPP Language. <br/>
 * Setup basic logic for completions using {@link LanguageAwareCompletionProvider}. <br/>
 * Filtering and decision will appear in the autocomplete dialog by implementations of: {@link CompletionProvider}.<br/>
 */
public class SketchCompletionProvider extends LanguageAwareCompletionProvider {

  public SketchCompletionProvider(Sketch sketch, SketchTextArea textArea, CompletionProvider provider) {

    setDefaultCompletionProvider(provider);
    // provider.setParameterChoicesProvider(new ParameterChoicesProvider(this));
    // provider.setParameterizedCompletionParams('(', ", ", ')');

  }

}