/*
 * This file is part of Arduino.
 *
 * Copyright 2017 Matthijs Kooijman <matthijs@stdin.nl>
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

package processing.app.helpers;

import javax.swing.event.DocumentEvent;
import javax.swing.event.DocumentListener;

/**
 * Helper class that create a document listener that calls the given
 * TextChangeListener on any change to the document text (but not changes to
 * document attributes).
 * 
 * The TextChangeListener to be passed is intended to be a lambda function, for
 * easy definition of a callback.
 */
public class DocumentTextChangeListener implements DocumentListener {
  public interface TextChangeListener {
    public void textChanged();
  }

  private TextChangeListener onChange;

  public DocumentTextChangeListener(TextChangeListener onChange) {
    this.onChange = onChange;
  }

  @Override
  public void changedUpdate(DocumentEvent arg0) {
    /* Attributes changed, do nothing */
  }

  @Override
  public void insertUpdate(DocumentEvent arg0) {
    onChange.textChanged();
  }

  @Override
  public void removeUpdate(DocumentEvent arg0) {
    onChange.textChanged();
  }
}
