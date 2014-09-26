/*
  ************************************************************************
  *	TimerSerial.h
  *
  *	Arduino core files for MSP430
  *		Copyright (c) 2012 Robert Wessels. All right reserved.
  *
  *
  ***********************************************************************

  2013-12-23 Limited size for RX and TX buffers, by spirilis
 
 
  Derived from:
  HardwareSerial.cpp - Hardware serial library for Wiring
  Copyright (c) 2006 Nicholas Zambetti.  All right reserved.

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
*/

#ifndef HardwareSerial_h
#define HardwareSerial_h

#include <inttypes.h>
#include "Stream.h"

#define SERIAL_BUFFER_SIZE 256

class HardwareSerial : public Stream
{
	private:
		unsigned char txBuffer[SERIAL_BUFFER_SIZE];
		unsigned long txBufferSize;
		unsigned long txWriteIndex;
		unsigned long txReadIndex;
		unsigned char rxBuffer[SERIAL_BUFFER_SIZE];
		unsigned long rxBufferSize;
		unsigned long rxWriteIndex;
		unsigned long rxReadIndex;
		unsigned long uartModule;
		unsigned long baudRate;
		void flushAll(void);
		void primeTransmit(unsigned long ulBase);

	public:
		HardwareSerial(void);
		HardwareSerial(unsigned long);
		void begin(unsigned long);
		void setBufferSize(unsigned long, unsigned long);
		void setModule(unsigned long);
		void setPins(unsigned long);
		void end(void);
		virtual int available(void);
		virtual int peek(void);
		virtual int read(void);
		virtual void flush(void);
		void UARTIntHandler(void);
		virtual size_t write(uint8_t c);
		operator bool();
		using Print::write; // pull in write(str) and write(buf, size) from Print
};

extern HardwareSerial Serial;
extern HardwareSerial Serial1;

extern "C" void UARTIntHandler(void);
extern "C" void UARTIntHandler1(void);

extern void serialEventRun(void) __attribute__((weak));
#endif
