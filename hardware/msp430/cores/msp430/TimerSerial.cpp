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

#define SERIAL_BUFFER_SIZE 16

#ifndef TIMERA0_VECTOR
 #define TIMERA0_VECTOR TIMER0_A0_VECTOR
#endif /* TIMER0_A0_VECTOR */

#ifndef TIMERA1_VECTOR
 #define TIMERA1_VECTOR TIMER0_A1_VECTOR
#endif /* TIMERA1_VECTOR */

struct ring_buffer_ts
{
    volatile unsigned int head;
    volatile unsigned int tail;
    unsigned char buffer[SERIAL_BUFFER_SIZE];
};

/**
 * uint8x2_t - optimized structure storage for ISR. Fits our static variables in one register
 *             This tweak allows the ISR to use one less register saving a push and pop
 *             We also save a couple of instructions being able to write to both values with
 *             one mov.w instruction.
 */
typedef union uint8x2_t {
    //---------- word access
    uint16_t mask_data;     // access both as a word: mask is low byte, data is high byte
    //--- or --- individual byte access
    struct {
        uint8_t mask:8;     // bit mask to set data bits. Also used as a loop end flag
        uint8_t data:8;     // working value for bits received
    } b;
} uint8x2_t;

// --- ---
static volatile unsigned int USARTTXBUF;
static uint16_t TICKS_PER_BIT;
static uint16_t TICKS_PER_BIT_DIV2;
static ring_buffer_ts rx_buffer;

#if NEEDS_BUFF_PTR
 static ring_buffer_ts tx_buffer; // required for the g2231, without it we get garbage
#endif

#if !defined(__MSP430_HAS_USCI__) && !defined(__MSP430_HAS_USCI_A0__) && !defined(__MSP430_HAS_USCI_A1__) && !defined(__MSP430_HAS_EUSCI_A0__)
TimerSerial Serial;
#endif

void serialEvent() __attribute__((weak));
void serialEvent() {}

void serialEventRun(void)
{
  if (Serial.available()) serialEvent();
}

TimerSerial::TimerSerial()
{
#if NEEDS_BUFF_PTR
    _rx_buffer = &rx_buffer;
    _tx_buffer = &tx_buffer;
#endif
}

void TimerSerial::begin(register unsigned long baud)
{
	pinMode_int(DEBUG_UARTRXD, DEBUG_UARTRXD_SET_MODE);
	pinMode_int(DEBUG_UARTTXD, DEBUG_UARTTXD_SET_MODE);	

    TA0CCTL0 = OUT;                     // Set TXD Idle state as Mark = '1', +3.3 volts normal
    TA0CCTL1 = SCS | CM1 | CAP | CCIE;  // Sync TACLK and MCLK, Detect Neg Edge, Enable Capture mode and RX Interrupt
    TA0CTL = TASSEL_2 | MC_2 | TACLR;   // Clock TIMERA from SMCLK, run in continuous mode counting from to 0-0xFFFF

#if F_CPU == 1000000
    baud = (baud<=4800) ? baud : 4800;  // force 4800 for slow F_CPU
#endif

    TICKS_PER_BIT = F_CPU / baud;
    TICKS_PER_BIT_DIV2 = TICKS_PER_BIT >> 1;
}

void TimerSerial::end()
{
    while (TA0CCTL0 & CCIE) {
        ; // wait for previous xmit to finish
    }
	pinMode(DEBUG_UARTTXD, INPUT);	
}

int TimerSerial::read()
{
    register uint16_t temp_tail=rx_buffer.tail;

    if (rx_buffer.head != temp_tail) {
        uint8_t c = rx_buffer.buffer[temp_tail++];
        rx_buffer.tail = temp_tail % SERIAL_BUFFER_SIZE;
        return c;
    }
    else {
        return -1;
    }
}

int TimerSerial::available()
{
    unsigned cnt = (rx_buffer.head - rx_buffer.tail) % SERIAL_BUFFER_SIZE;

    return cnt;
}

void TimerSerial::flush()
{
    while (TA0CCTL0 & CCIE) {
        ; // wait for previous xmit to finish
    }
}

int TimerSerial::peek()
{
    register uint16_t temp_tail=rx_buffer.tail;

    if (rx_buffer.head != temp_tail) {
        return rx_buffer.buffer[temp_tail];
    }
    else {
        return -1;
    }
}

size_t TimerSerial::write(uint8_t c)
{
    // TIMERA0 disables the interrupt flag when it has sent
    // the final stop bit. While a transmit is in progress the
    // interrupt is enabled
    while (TA0CCTL0 & CCIE) {
        ; // wait for previous xmit to finish
    }

    // make the next output at least TICKS_PER_BIT in the future
    // so we don't stomp on the the stop bit from our previous xmt

    TA0CCR0 = TA0R;              // resync with current TimerA clock
    TA0CCR0 += TICKS_PER_BIT;    // setup the next timer tick
    TA0CCTL0 = OUTMOD0 + CCIE;   // set TX_PIN HIGH and reenable interrupts

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

    register unsigned value = c | 0x100;  // add stop bit '1'
    value <<= 1;            // Add the start bit '0'
    USARTTXBUF=value;       // queue up the byte for xmit
    return 1;
}


#ifndef TIMER0_A0_VECTOR
#define TIMER0_A0_VECTOR TIMERA0_VECTOR
#endif /* TIMER0_A0_VECTOR */

#ifndef __GNUC__
#pragma vector = TIMER0_A0_VECTOR
__interrupt
#else
__attribute__((interrupt(TIMER0_A0_VECTOR)))
#endif
//Timer0 A0 interrupt service routine
static void TimerSerial__TxIsr(void)
{
    TA0CCR0 += TICKS_PER_BIT;       // setup next time to send a bit, OUT will be set then

    TA0CCTL0 |= OUTMOD2;            // reset OUT (set to 0) OUTMOD2|OUTMOD0 (0b101)
    if ( USARTTXBUF & 0x01 ) {      // look at LSB if 1 then set OUT high
       TA0CCTL0 &= ~OUTMOD2;        // set OUT (set to 1) OUTMOD0 (0b001)
    }

    if (!(USARTTXBUF >>= 1)) {      // All bits transmitted ?
        TA0CCTL0 &= ~CCIE;          // disable interrupt, indicates we are done
    }
}

#define store_rxchar(c) { \
    register unsigned int next_head;\
    next_head = rx_buffer.head;\
    rx_buffer.buffer[next_head++]=c; \
    next_head %= SERIAL_BUFFER_SIZE; \
    if ( next_head != rx_buffer.tail ) { \
        rx_buffer.head = next_head; \
    } \
}

#ifndef TIMER0_A1_VECTOR
#define TIMER0_A1_VECTOR TIMERA1_VECTOR
#endif /* TIMER0_A0_VECTOR */

#ifndef __GNUC__
#pragma vector = TIMER0_A1_VECTOR
__interrupt
#else
__attribute__((interrupt(TIMER0_A1_VECTOR)))
#endif
//Timer A1 interrupt service routine
static void TimerSerial__RxIsr(void)
{
    static uint8x2_t rx_bits;               // persistent storage for data and mask. fits in one 16 bit register
    volatile uint16_t resetTAIVIFG;         // just reading TAIV will reset the interrupt flag
    resetTAIVIFG=TA0IV;(void)resetTAIVIFG;

    register uint16_t regCCTL1=TA0CCTL1;    // using a temp register provides a slight performance improvement

    TA0CCR1 += TICKS_PER_BIT;            // Setup next time to sample

    if (regCCTL1 & CAP) {                   // Are we in capture mode? If so, this is a start bit
        TA0CCR1 += TICKS_PER_BIT_DIV2;      // adjust sample time, so next sample is in the middle of the bit width
        rx_bits.mask_data = 0x0001;         // initialize both values, set data to 0x00 and mask to 0x01
        TA0CCTL1 = regCCTL1 & ~CAP;         // Switch from capture mode to compare mode
    }
    else {
        if (regCCTL1 & SCCI) {              // sampled bit value from receive latch
            rx_bits.b.data|=rx_bits.b.mask; // if latch is high, then set the bit using the sliding mask
        }

        if (!(rx_bits.b.mask <<= 1)) {      // Are all bits received? Use the mask to end loop
            store_rxchar(rx_bits.b.data);   // Store the bits into the rx_buffer
            TA0CCTL1 = regCCTL1 | CAP;      // Switch back to capture mode and wait for next start bit (HI->LOW)
        }
    }
}
