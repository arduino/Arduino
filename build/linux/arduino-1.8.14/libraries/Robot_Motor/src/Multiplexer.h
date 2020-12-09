/*
  Copyright (c) 2012 Arduino LLC. All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
*/

#ifndef Multiplexer_h
#define Multiplexer_h

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class Multiplexer{
	public:
		void begin(uint8_t* selectors, uint8_t Z, uint8_t length);
		void selectPin(uint8_t num);
		int getAnalogValue();
		int getAnalogValueAt(uint8_t num);
		bool getDigitalValue();
		bool getDigitalValueAt(uint8_t num);
	private:
		uint8_t selectors[4];
		uint8_t pin_Z;
		uint8_t length;
};

#endif
