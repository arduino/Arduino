/* -*- mode: java; c-basic-offset: 2; indent-tabs-mode: nil -*- */

/*
  PdeKeywords - handles text coloring and links to html reference
  Part of the Processing project - http://processing.org

  Copyright (c) 2004-06 Ben Fry and Casey Reas
  Copyright (c) 2001-04 Massachusetts Institute of Technology

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software Foundation,
  Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

package processing.app.helpers;

import com.ricardojlrufino.eventbus.EventMessage;

import processing.app.debug.TargetBoard;

/**
 * Events for UI Interface.
 * 
 * @author Ricardo JL Rufino - (ricardo.jl.rufino@gmail.com)
 * @date 21 de mai de 2020
 */
public interface UIEvents {

  public static class BoardOrPortChange implements EventMessage { }

  public static class LibraryIndexUpdated implements EventMessage {}

  public static class PlatformChage implements EventMessage {}

  public static class EditorClosed implements EventMessage {}

  /**
   * Please do not use this event. It should only be used internally by the
   * Base.onBoardOrPortChange method. Use: {@link BoardOrPortChange}
   **/
  public static class TriggerFixBoardOrPortChange implements EventMessage {
  }
  
  public static class MenuBoardSettingsChanged implements EventMessage {
    private String custosOption;
    private TargetBoard board;

    public MenuBoardSettingsChanged(TargetBoard board, String custosOption) {
      this.board = board;
      this.custosOption = custosOption;
    }

    public TargetBoard getBoard() {
      return board;
    }

    public String getCustosOption() {
      return custosOption;
    }

  }

}
