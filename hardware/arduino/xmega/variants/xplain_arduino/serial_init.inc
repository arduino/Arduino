/*
  serial_init.cpp - Initialize serial ports for Arduino
  Part of Arduino - http://www.arduino.cc/

  Copyright (c) 2011 Karl Backstroem

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General
  Public License along with this library; if not, write to the
  Free Software Foundation, Inc., 59 Temple Place, Suite 330,
  Boston, MA  02111-1307  USA

*/

// Preinstantiate Objects //////////////////////////////////////////////////////

SERIAL_DEFINE(Serial, C, 0);
SERIAL_DEFINE(Serial1, D, 0);
SERIAL_DEFINE(Serial2, D, 1);
SERIAL_DEFINE(Serial3, C, 1);
SERIAL_DEFINE(Serial4, E, 0);
SERIAL_DEFINE(Serial5, E, 1);
SERIAL_DEFINE(Serial6, F, 0);
SERIAL_DEFINE(Serial7, F, 1);
