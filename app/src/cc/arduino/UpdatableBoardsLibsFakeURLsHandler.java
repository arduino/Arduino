/*
 * This file is part of Arduino.
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
 *
 * Copyright 2015 Arduino LLC (http://www.arduino.cc/)
 */

package cc.arduino;

import processing.app.Base;

import javax.swing.event.HyperlinkEvent;
import javax.swing.event.HyperlinkListener;
import java.net.URL;

public class UpdatableBoardsLibsFakeURLsHandler implements HyperlinkListener {

  private static final String BOARDSMANAGER = "boardsmanager";
  private static final String LIBRARYMANAGER = "librarymanager";

  private final Base base;

  public UpdatableBoardsLibsFakeURLsHandler(Base base) {
    this.base = base;
  }

  @Override
  public void hyperlinkUpdate(HyperlinkEvent event) {
    if (event.getEventType() != HyperlinkEvent.EventType.ACTIVATED) {
      return;
    }

    URL url = event.getURL();
    openBoardLibManager(url);
  }

  public void openBoardLibManager(URL url) {
    if (BOARDSMANAGER.equals(url.getHost())) {
      try {
        base.openBoardsManager(url.getRef() == null ? "": url.getRef() , url.getPath() == null ? "" : url.getPath().replace("/", ""));
      } catch (Exception e) {
        e.printStackTrace();
      }
      return;
    }

    if (LIBRARYMANAGER.equals(url.getHost())) {
      base.openLibraryManager(url.getRef() == null ? "": url.getRef() , url.getPath() == null ? "" : url.getPath().replace("/", ""));
      return;
    }

    throw new IllegalArgumentException(url.getHost() + " is invalid");

  }

}
