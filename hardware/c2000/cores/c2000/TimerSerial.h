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

// running at < 3MHz requires a lower baud rate
#ifndef TIMERSERIAL_BAUD
#if F_CPU > 1000000
    #define TIMERSERIAL_BAUD 9600
#else
    #define TIMERSERIAL_BAUD 4800
#endif
#endif

#if defined(__MSP430G2231__)
 #define NEEDS_BUFF_PTR 1 // sadly, the g2231 seems to have a problem if we don't use the original structure
 struct ring_buffer_ts; // forward declaration
#else
 #define NEEDS_BUFF_PTR 0 // everything else is happy to run fully optimized
#endif

class TimerSerial : public Stream
{
public:
    TimerSerial(void);

    void begin(unsigned long baud = TIMERSERIAL_BAUD);
    void end(void);

    virtual size_t write(uint8_t byte);
    virtual int read(void);
    virtual int available(void);
    virtual void flush(void);
    virtual int peek(void);

    using Print::write;

private:

#if NEEDS_BUFF_PTR
    ring_buffer_ts *_timer_rx_buffer; // gcc seems to get confused on the g2231 without this
    ring_buffer_ts *_timer_tx_buffer;
#endif

};

//#if !defined(__MSP430_HAS_USCI__) && !defined(__MSP430_HAS_EUSCI_A0__)
extern TimerSerial timerSerial;
//#endif
extern void serialEventRun(void);// __attribute__((weak));
#endif

void xint1_isr(void);
void cpu_timer0_isr(void);
