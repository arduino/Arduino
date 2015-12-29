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

#if defined(__MSP430_HAS_USCI__) || defined(__MSP430_HAS_USCI_A0__) || defined(__MSP430_HAS_USCI_A1__) || defined(__MSP430_HAS_EUSCI_A0__) || defined(__MSP430_HAS_EUSCI_A1__)
#include <inttypes.h>
#include <Stream.h>

struct ring_buffer;

class HardwareSerial : public Stream
{
	private:
		ring_buffer *_rx_buffer;
		ring_buffer *_tx_buffer;
		uint8_t uartOffset;
		uint16_t rxPinMode;
		uint16_t txPinMode;
		uint8_t rxPin;
		uint8_t txPin;
		uint8_t lock;
	public:
		HardwareSerial(ring_buffer *rx_buffer, ring_buffer *tx_buffer, uint8_t uartOffset, uint16_t rxPinMode, uint16_t txPinMode, uint8_t rxPin, uint8_t txPin)
		: _rx_buffer(rx_buffer)
		, _tx_buffer(tx_buffer)
		, uartOffset(uartOffset)
		, rxPinMode(rxPinMode)
		, txPinMode(txPinMode)
		, rxPin(rxPin)
		, txPin(txPin) {}
		void begin(unsigned long);
		void end();
		virtual int available(void);
		virtual int peek(void);
		virtual int read(void);
		virtual void flush(void);
		virtual size_t write(uint8_t);
		using Print::write; // pull in write(str) and write(buf, size) from Print
		operator bool();
};

extern HardwareSerial Serial;
extern HardwareSerial Serial1;

extern void serialEventRun(void) __attribute__((weak));

#endif
#endif
