/* -*- mode: jde; c-basic-offset: 2; indent-tabs-mode: nil -*- */

/*
  ZigBeeException.java
  Part of the Arduino project - http://www.arduino.cc/

  Copyright (c) 2012
  Ross Biro
  
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
  
  $Id$
*/
package processing.app.debug;

import java.lang.Exception;
import java.lang.String;

class ZigBeeException extends Exception {
  public ZigBeeException() {
    super();
  }

  public ZigBeeException(String message) {
    super(message);
  }
  
  public ZigBeeException(String message, Throwable cause) {
    super(message, cause);
  }
  
  public ZigBeeException(Throwable cause) {
    super(cause);
  }
}
