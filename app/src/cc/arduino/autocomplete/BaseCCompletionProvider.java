/* -*- mode: java; c-basic-offset: 2; indent-tabs-mode: nil -*- */

/*
  Part of the Arduino project - http://www.arduino.cc

  Copyright (c) 2015 Matthijs Kooijman
  Copyright (c) 2004-09 Ben Fry and Casey Reas
  Copyright (c) 2001-04 Massachusetts Institute of Technology

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License version 2
  as published by the Free Software Foundation.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software Foundation,
  Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

package cc.arduino.autocomplete;

import org.fife.ui.autocomplete.DefaultCompletionProvider;

/**
 * Base completion provider for C/C++.
 * @author Ricardo JL Rufino (ricardo@criativasoft.com.br)
 * @date 28/04/2017
 */
public class BaseCCompletionProvider extends DefaultCompletionProvider{
 
  @Override
  protected boolean isValidChar(char ch) {
    return super.isValidChar(ch) || '.' == ch || '>' == ch  || '-' == ch  || '<' == ch || '#' == ch || ':' == ch /**|| getParameterListStart() == ch */;
  }

}
