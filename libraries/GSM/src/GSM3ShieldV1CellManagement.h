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
#ifndef __GSM3_SHIELDV1CELLMANAGEMENT__
#define __GSM3_SHIELDV1CELLMANAGEMENT__

#include <GSM3ShieldV1ModemCore.h>
#include <GSM3MobileCellManagement.h>
#include <GSM3ShieldV1CellManagement.h>

class GSM3ShieldV1CellManagement : public GSM3MobileCellManagement, public GSM3ShieldV1BaseProvider
{		
	public:
		
		/** 
			Constructor
		*/
		GSM3ShieldV1CellManagement();

		/** 
			Manages modem response
			
			@param from 		Initial byte of buffer
			@param to 			Final byte of buffer
		 */
		void manageResponse(byte from, byte to);
		
		/**
			Update cells attribute with the last information.
		 
			@param set if includes 1 to 6 neighbours or only current cell
			@return number of cells included in cells attribute
		*/		
		uint8_t updateLocation(bool neighbours = false);
		
		/**
			Return the cells array pointer
			
			@return the pointer to cells struct
		 */
		Cell* getCells(){return cells;};
		
		/**
			Return the cells array pointer
			
			@return the pointer to cells struct
		 */
		uint8_t getNumberCells(){return cellsLength;};
		
		/**
			Return if neighbours mode is active
			
			@return true if neighbours mode was activated, false if was not
		 */
		bool getNeighboursActivated(){return neighboursActivated;};
		
		/**
			getICCID
		 */
		int8_t getICCID(char *iccid);
		
		/**
			getIMEI
		 */
		int8_t getIMEI(char *imei);
		
		/**
			getPowerData
		 */
		int8_t getPowerData(char *info);
		
		/** 
			Get last command status
			
			@return returns 0 if last command is still executing, 1 success, >1 error
		 */
		int ready(){return GSM3ShieldV1BaseProvider::ready();};

	private:	
	
		// Location variables
		uint8_t cellsLength;
		Cell cells[7];
		bool neighboursActivated;
		
		// Pointer to save ICCID
		char *bufferICCID;
		
		// Pointer to save IMEI
		char *bufferIMEI;
		
		// Pointer to save power data
		char *powerData;
	
		/**
			Continue to updateLocation function
			
			@param set if includes 1 to 6 neighbours or only current cell
		 */
		void updateLocationContinue();
		
		/**
			Continue to getICCID function
		 */
		void getICCIDContinue();
		
		/**
			Continue to getIMEI function
		 */
		void getIMEIContinue();
		
		/**
			Continue to getPowerData function
		 */
		void getPowerDataContinue();
		
		/**
			Parsers for AT commands
		 */
		bool parseQENG_available(bool& rsp);
		bool parseQCCID_available(bool& rsp);
		bool parseGSN_available(bool& rsp);
		bool parseCBC_available(bool& rsp);
		
		/**
			Special parser for neighbours cells
		 */
		bool extractNeighbours(bool &rsp);
		
		/**
			Special reader from buffer for neighbours response
			
			@return each character of buffer
		 */
		int readCompleteResponse();
};

#endif