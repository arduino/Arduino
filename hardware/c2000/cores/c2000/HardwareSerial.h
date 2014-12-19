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

struct ring_buffer;

class HardwareSerial : public Stream
{
	private:
		uint8_t lock;
		ring_buffer *_rx_buffer;
		ring_buffer *_tx_buffer;

		static void USCI0RX_ISR (void);
		static void USCI0TX_ISR (void);

	public:
		HardwareSerial(ring_buffer *rx_buffer, ring_buffer *tx_buffer);
		void begin(unsigned long);
		void end();
		virtual int available(void);
		virtual int peek(void);
		virtual int read(void);
		virtual void flush(void);
		virtual size_t write(uint8_t);
		operator bool();
		using Print::write; // pull in write(str) and write(buf, size) from Print
};

extern HardwareSerial Serial;

extern void serialEventRun(void);

#endif
