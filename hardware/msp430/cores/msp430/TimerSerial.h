/*
  TimerSerial.h - Timer based serial library for MSP430
  Copyright (c) 2012 Robert Wessels.  All right reserved.
  Modeled after Nicholas Zambetti's HardwareSerial.
  and
  msp430softserial by Rick Kimball
  https://github.com/RickKimball/msp430softserial/

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


#define TX_PIN BIT1	// TXD on P1.1
#define RX_PIN BIT2	// RXD on P1.2

// running at < 16MHz requires a lower baud rate
#ifndef TIMERSERIAL_BAUD
#if F_CPU > 1000000
    #define TIMERSERIAL_BAUD 9600
#else
    #define TIMERSERIAL_BAUD 4800
#endif
#endif

#define SERIAL_BUFFER_SIZE 16

struct ring_buffer
{
	unsigned char buffer[SERIAL_BUFFER_SIZE];
	volatile unsigned int head;
	volatile unsigned int tail;
};

class TimerSerial : public Stream
{
private:
    ring_buffer *_tx_buffer;
    ring_buffer *_rx_buffer;

	void Transmit(void);

public:
	TimerSerial(void);

	void begin(unsigned long baud=TIMERSERIAL_BAUD);
	void end(void);

	virtual size_t write(uint8_t byte);
	virtual int read(void);
	virtual int available(void);
	virtual void flush(void);
	virtual int peek(void);

	using Print::write;
};

#ifndef __MSP430_HAS_USCI__
extern TimerSerial Serial;
#endif

#endif
