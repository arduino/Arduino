/*
  TimerSerial.h - Timer based serial library for MSP430
  Copyright (c) 2012 Robert Wessels.  All right reserved.
  Modeled after Nicholas Zambetti's HardwareSerial.

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

#ifndef TimerSerial_h
#define TimerSerial_h

#include <inttypes.h>
#include <Stream.h>
#include <legacymsp430.h>

//TODO: Size should depend on how much RAM we have. 16 should be OK for most cases.

#define SERIAL_BUFFER_SIZE 16

#define TX_PIN BIT1	// TXD on P1.1
#define RX_PIN BIT2	// RXD on P1.2

// TODO: support other baud rates
#define TICKS_PER_BIT 104		// 9600 Baud, SMCLK=1MHz (1MHz/9600)=104
#define TICKS_PER_BIT_DIV2 51		// Time for half a bit.

struct ring_buffer
{
	unsigned char buffer[SERIAL_BUFFER_SIZE];
	volatile unsigned int head;
	volatile unsigned int tail;
};

#define ENABLE_RXDEBUG_PIN 1

#define RXDEBUG_PIN_PORT  P1    // P1
#define RXDEBUG_PIN     BIT6    // P1.6

#ifdef ENABLE_RXDEBUG_PIN
#define _SoftSerial_RxDebugPinInit() { \
    P1OUT |= RXDEBUG_PIN; \
    P1DIR |= RXDEBUG_PIN; \
}

#define _SoftSerial_ToggleRxDebugPin() { \
  P1OUT ^= RXDEBUG_PIN; \
}

#else
#define _SoftSerial_RxDebugPinInit()
#define _SoftSerial_ToggleRxDebugPin()
#endif


class TimerSerial : public Stream
{
private:
	//uint8_t txBitCnt;		// Bit count, used when transmitting byte
	//uint8_t rxBitCnt;
	//uint8_t rxData;

	//volatile unsigned int USARTTXBUF;

	bool isReceiving;		// Status for when the device is receiving

	ring_buffer *_rx_buffer;
	ring_buffer *_tx_buffer;

	void Transmit(void);
	static void TxIsr (void);
	static void RxIsr (void);
	void ProcessTxIsr(void);
	void ProcessRxIsr(void);

public:
	TimerSerial(void);
	~TimerSerial(void);
	void begin(void);
	//bool listen(void);
	void end(void);
	//bool isListening(void) { return this == active_object; }
	//bool overflow(void) { bool ret = _buffer_overflow; _buffer_overflow = false; return ret; }

	virtual size_t write(uint8_t byte);
	virtual int read(void);
	virtual int available(void);
	virtual void flush(void);
	virtual int peek(void);

	using Print::write;
};
#endif
