/*
  ************************************************************************
  *	TimerSerial.h
  *
  *	Arduino core files for MSP430
  *		Copyright (c) 2012 Robert Wessels. All right reserved.
  *
  *
  ***********************************************************************
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

#define RX_BUFFER_SIZE     128
#define TX_BUFFER_SIZE     1024

//extern void serialEventRun(void) __attribute__((weak));
class HardwareSerial : public Stream
{
	private:
        unsigned char *txBuffer;
        volatile unsigned long txWriteIndex;
        volatile unsigned long txReadIndex;
        unsigned char *rxBuffer;
        volatile unsigned long rxWriteIndex;
        volatile unsigned long rxReadIndex;
        unsigned long uartBase;    
        void flushAll(void);
        void primeTransmit(unsigned long ulBase);
	public:
		HardwareSerial(void);
		void begin(unsigned long);
		void end(void);
		virtual int available(void);
		virtual int peek(void);
		virtual int read(void);
		virtual void flush(void);
		virtual size_t write(uint8_t);
		virtual size_t write(const uint8_t *buffer, size_t size);
		virtual size_t write(const char *str);
        void UARTIntHandler(void);
};
extern HardwareSerial Serial;
extern "C" void UART0IntHandler(void);
extern void serialEventRun(void) __attribute__((weak));
#endif
