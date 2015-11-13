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

#if defined(__MSP430_HAS_EUSCI_A0__) || defined(__MSP430_HAS_EUSCI_A1__)
#define SERIAL_PAR_MASK ((UCPEN | UCPAR | UC7BIT | UCSPB) >> 8 )
#define SERIAL_7N1      ((UC7BIT)                         >> 8 )
#define SERIAL_8N1      ((0)                              >> 8 )
#define SERIAL_7N2      ((UC7BIT                 | UCSPB) >> 8 )
#define SERIAL_8N2      ((0                      | UCSPB) >> 8 )
#define SERIAL_7E1      ((UC7BIT | UCPEN | UCPAR)         >> 8 )
#define SERIAL_8E1      ((0      | UCPEN | UCPAR)         >> 8 )
#define SERIAL_7E2      ((UC7BIT | UCPEN | UCPAR | UCSPB) >> 8 )
#define SERIAL_8E2      ((0      | UCPEN | UCPAR | UCSPB) >> 8 )
#define SERIAL_7O1      ((UC7BIT | UCPEN)                 >> 8 )
#define SERIAL_8O1      ((0      | UCPEN)                 >> 8 )
#define SERIAL_7O2      ((UC7BIT | UCPEN         | UCSPB) >> 8 )
#define SERIAL_8O2      ((0      | UCPEN         | UCSPB) >> 8 )
#else
#define SERIAL_PAR_MASK (UCPEN | UCPAR | UC7BIT | UCSPB) 
#define SERIAL_7N1      (UC7BIT)
#define SERIAL_8N1      (0)
#define SERIAL_7N2      (UC7BIT                 | UCSPB)
#define SERIAL_8N2      (0                      | UCSPB)
#define SERIAL_7E1      (UC7BIT | UCPEN | UCPAR) 
#define SERIAL_8E1      (0      | UCPEN | UCPAR)
#define SERIAL_7E2      (UC7BIT | UCPEN | UCPAR | UCSPB)
#define SERIAL_8E2      (0      | UCPEN | UCPAR | UCSPB)
#define SERIAL_7O1      (UC7BIT | UCPEN)
#define SERIAL_8O1      (0      | UCPEN)
#define SERIAL_7O2      (UC7BIT | UCPEN         | UCSPB)
#define SERIAL_8O2      (0      | UCPEN         | UCSPB)
#endif

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
		void begin(unsigned long, uint8_t config=SERIAL_8N1);
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
