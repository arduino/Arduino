/*
  wiring_shift.c - shiftOut() function
  Part of Arduino - http://www.arduino.cc/

  Copyright (c) 2005-2006 David A. Mellis

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

  $Id: wiring.c 248 2007-02-03 15:36:30Z mellis $
*/

#include "wiring_private.h"

uint8_t shiftIn(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder) {
	uint8_t value = 0;
	uint8_t i = 0;
	uint8_t bitIndex = 0;

	if ((bitOrder != LSBFIRST) && (bitOrder != MSBFIRST)) { return 0; } // check error condition

	for (; i < 8; ++i) {
		bitIndex = (((bitOrder == LSBFIRST) * i) + ((bitOrder != LSBFIRST) * (7 - i)));

		digitalWrite(clockPin, HIGH);
		value |= digitalRead(dataPin) << bitIndex;
		digitalWrite(clockPin, LOW);
	}
	
	return value;
}

void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t val) {
	uint8_t i = 0;
	uint8_t bitMask = 0;

	if ((bitOrder != LSBFIRST) && (bitOrder != MSBFIRST)) { return 0; } // check error condition

	for (; i < 8; ++i)  {
		bitMask = (1 << (((bitOrder == LSBFIRST) * i) + ((bitOrder != LSBFIRST) * (7 - i))));

		digitalWrite(dataPin, !!(val & bitMask));
		digitalWrite(clockPin, HIGH);
		digitalWrite(clockPin, LOW);		
	}
}
