/*
This file is part of the GSM3 communications library for Arduino
-- Multi-transport communications platform
-- Fully asynchronous
-- Includes code for the Arduino-Telefonica GSM/GPRS Shield V1
-- Voice calls
-- SMS
-- TCP/IP connections
-- HTTP basic clients

This library has been developed by Telefónica Digital - PDI -
- Physical Internet Lab, as part as its collaboration with
Arduino and the Open Hardware Community. 

September-December 2012

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

The latest version of this library can always be found at
https://github.com/BlueVia/Official-Arduino
*/
#ifndef _GSM3MOBILECELLMANAGEMENT_
#define _GSM3MOBILECELLMANAGEMENT_

#include <Arduino.h>

struct Cell
{
	char mcc[6];
	char mnc[6];
	char lac[6];
	char cellId[8];
	char dbm[6];
};

class GSM3MobileCellManagement
{
	public:
		
		virtual inline uint8_t updateLocation(bool) {return 0;};
		
		virtual inline int8_t getICCID() {return 0;};
		
		virtual inline int8_t getIMEI() {return 0;};
		
		virtual inline int8_t getPowerData() {return 0;};
		
		virtual inline Cell* getCells(){return NULL;};
		
		virtual inline bool getNeighboursActivated(){return 0;};
		
		virtual inline uint8_t getNumberCells(){return 0;};
		
		/** Get last command status
			@return returns 0 if last command is still executing, 1 success, >1 error
		 */
		virtual int ready()=0;
};

#endif
