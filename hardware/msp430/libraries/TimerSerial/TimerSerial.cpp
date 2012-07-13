/*
  ************************************************************************
  *	TimerSerial.cpp
  *
  *	Arduino core files for MSP430
  *		Copyright (c) 2012 Robert Wessels. All right reserved.
  *
  *
  ***********************************************************************
  Derived from:
  HardwareSerial.cpp - Hardware serial library for Wiring
  Copyright (c) 2006 Nicholas Zambetti.  All right reserved.
  and
  msp430softserial by Rick Kimball
  https://github.com/RickKimball

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

#include "Energia.h"
#include "TimerSerial.h"

ring_buffer tx_buffer = { {0}, 0, 0};
ring_buffer rx_buffer = { {0}, 0, 0};
volatile unsigned int USARTTXBUF;

TimerSerial::TimerSerial()
{
	_tx_buffer = &tx_buffer;
	_rx_buffer = &rx_buffer;
}

TimerSerial::~TimerSerial()
{
	end();
}

void TimerSerial::begin()
{
	P1OUT |= TX_PIN | RX_PIN;           // Initialize all GPIO
	P1SEL |= TX_PIN + RX_PIN;           // Enabled Timer ISR function for TXD/RXD pins
	P1DIR |= TX_PIN;                    // Enable TX_PIN for output

	TACCTL0 = OUT;                      // Set TXD Idle state as Mark = '1', +3.3 volts normal
	TACCTL1 = SCS + CM1 + CAP + CCIE;   // Sync TACLK and MCLK, Detect Neg Edge, Enable Capture mode and RX Interrupt

	TACTL = TASSEL_2 + MC_2 + TACLR;    // Clock TIMERA from SMCLK, run in continuous mode counting from to 0-0xFFFF

	_SoftSerial_RxDebugPinInit();
}

void TimerSerial::end()
{
	P1SEL = ~TX_PIN;        // P1 functions select to default
	P1DIR = ~TX_PIN;        // Input
}

int TimerSerial::read()
{
	int c = -1;
        __dint(); // Disable interrupts to protect head and tail values
                  // This prevents the RX_ISR from modifying them
                  // while we are trying to read and modify
        
        if (_rx_buffer->head != _rx_buffer->tail) {
	        c = (uint8_t) _rx_buffer->buffer[_rx_buffer->tail];
	        _rx_buffer->tail = (unsigned int)(_rx_buffer->tail + 1) % SERIAL_BUFFER_SIZE;
	}
        
        __eint(); // Enable interrupts 
	
        return c;
}

int TimerSerial::available()
{
        int cnt;
        
        __dint(); // Disable interrupts to protect head and tail values
                  // This prevents the RX_ISR from modifying them
                  // while we are trying to read and modify

        cnt = (unsigned int)(SERIAL_BUFFER_SIZE + _rx_buffer->head - _rx_buffer->tail) % SERIAL_BUFFER_SIZE;

        __eint(); //Enable interrupts
        
        return cnt;
}

void TimerSerial::flush()
{
	while (_tx_buffer->head != _tx_buffer->tail);
}

int TimerSerial::peek()
{
	if (_rx_buffer->head == _rx_buffer->tail) {
		return -1;
	} else {
		return _rx_buffer->buffer[_rx_buffer->tail];
	}
}

#define store_rxchar(c) { \
	unsigned int i = (unsigned int)(rx_buffer.head + 1) % SERIAL_BUFFER_SIZE; \
	if ( i != rx_buffer.tail ) { \
		rx_buffer.buffer[rx_buffer.head] = c; \
		rx_buffer.head = i; \
	} \
}

void TimerSerial::Transmit()
{
	// make the next output at least TICKS_PER_BIT in the future
	// so we don't stomp on the the stop bit from our previous xmt

	TACCR0 = TAR;               // resync with current TimerA clock
	TACCR0 += TICKS_PER_BIT;    // setup the next timer tick
	TACCTL0 = OUTMOD0 + CCIE;   // set TX_PIN HIGH and reenable interrupts

	// now that we have set the next interrupt in motion
	// we quickly need to set the TX data. Hopefully the
	// next 2 lines happens before the next timer tick.

	// Note: This code makes great use of multiple peripherals
	//
	// In the code above, we start with a busy wait on the CCIE
	// interrupt flag. As soon as it is available, we setup the next
	// send time and then enable the interrupt. Until that time happens,
	// we have a few free cycles available to stuff the start and stop bits
	// into the data buffer before the timer ISR kicks in and handles
	// the event.  Note: if you are using a really slow clock or a really
	// fast baud rate you could run into problems if the interrupt is
	// triggered before you have finished with the USARTTXBUF

	USARTTXBUF |= 0x100;    // Add the stop bit '1'
	USARTTXBUF <<= 1;       // Add the start bit '0'
}


size_t TimerSerial::write(uint8_t b)
{	
        // TIMERA0 disables the interrupt flag when it has sent
	// the final stop bit. While a transmit is in progress the
	// interrupt is enabled
        while (TACCTL0 & CCIE) {
		; // wait for previous xmit to finish
	}

	USARTTXBUF = b;
	Transmit();
	return 1;
}

#ifndef TIMERA0_VECTOR
#define TIMERA0_VECTOR TIMER0_A0_VECTOR
#endif /* TIMER0_A0_VECTOR */

//Timer A0 interrupt service routine
__attribute__((interrupt(TIMERA0_VECTOR)))
void TimerSerial::TxIsr(void)
{
	static uint8_t txBitCnt = 10;           // 1 Start bit + 8 data bits + 1 stop bit

	if (txBitCnt == 0) {                    // All bits TXed?
		TACCTL0 &= ~CCIE;               // disable interrupt, used as a flag to SoftSerial_xmit
		txBitCnt = 10;                  // Re-load bit counter
	} else {
		TACCR0 += TICKS_PER_BIT;        // setup next time to send a bit

		if (USARTTXBUF & 0x01) {        // look at LSB and decide what to send
			TACCTL0 &= ~OUTMOD2;    // TX Mark '1'
		} else {
			TACCTL0 |= OUTMOD2;     // TX Space '0'
		}
		USARTTXBUF >>= 1;               // pull in the next bit to send
		txBitCnt--;
	}
}

#ifndef TIMERA1_VECTOR
#define TIMERA1_VECTOR TIMER0_A1_VECTOR
#endif /* TIMER0_A0_VECTOR */

//Timer A1 interrupt service routine
__attribute__((interrupt(TIMERA1_VECTOR)))
void TimerSerial::RxIsr(void)
{
	static unsigned char rxBitCnt = 8;
	static unsigned char rxData = 0;

#ifdef TIMER0_A1_VECTOR
	if ( TA0IV == TA0IV_TACCR1 ) {     // this mcu has multiple TIMERA peripherals
#else
	if ( TAIV == TAIV_TACCR1 ) {
#endif
                _SoftSerial_ToggleRxDebugPin();         // watch RXDEBUG_PIN with a scope to see sample timing
		TACCR1 += TICKS_PER_BIT;                // Setup next time to sample
		if (TACCTL1 & CAP) {                    // Is this the start bit?
			_SoftSerial_ToggleRxDebugPin(); // push it high to make a nice wave
			TACCTL1 &= ~CAP;                // Switch capture to compare mode
			TACCR1 += TICKS_PER_BIT_DIV2;   // Sample from the middle of D0
		}
		else {
			rxData >>= 1;
			if (TACCTL1 & SCCI) {            // Get bit waiting in receive latch
				rxData |= 0x80;
			}
			rxBitCnt--;
			if (rxBitCnt == 0) {             // All bits RXed?
                                store_rxchar(rxData);    // Store in ring_buffer
				rxBitCnt = 8;            // Re-load bit counter
				TACCTL1 |= CAP;          // Switch compare to capture mode
				TACCR1 += TICKS_PER_BIT; // account for the stop bit
			}
		}
	}
}
