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

#include "Multiplexer.h"

void Multiplexer::begin(uint8_t* selectors, uint8_t Z, uint8_t length){
	for(uint8_t i=0;i<length;i++){
		this->selectors[i]=selectors[i];
		pinMode(selectors[i],OUTPUT);
	}
	this->length=length;
	this->pin_Z=Z;
	pinMode(pin_Z,INPUT);
}

void Multiplexer::selectPin(uint8_t num){
	for(uint8_t i=0;i<length;i++){
		//Serial.print(bitRead(num,i));
		digitalWrite(selectors[i],bitRead(num,i));
	}
	//Serial.println("");
}

int Multiplexer::getAnalogValue(){
	return analogRead(pin_Z);
}

bool Multiplexer::getDigitalValue(){
	return digitalRead(pin_Z);
}

int Multiplexer::getAnalogValueAt(uint8_t num){
	selectPin(num);
	return getAnalogValue();
}

bool Multiplexer::getDigitalValueAt(uint8_t num){
	selectPin(num);
	return getDigitalValue();
}
