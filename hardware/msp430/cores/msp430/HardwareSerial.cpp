/*
  ************************************************************************
  *	HardwareSerial.cpp
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
  
  Modified 23 November 2006 by David A. Mellis
  Modified 28 September 2010 by Mark Sproul
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include "Energia.h"
#include "wiring_private.h"
#include "usci_isr_handler.h"

#if defined(__MSP430_HAS_USCI__) || defined(__MSP430_HAS_USCI_A0__) || defined(__MSP430_HAS_USCI_A1__) || defined(__MSP430_HAS_EUSCI_A0__)

#include "HardwareSerial.h"

HardwareSerial *SerialPtr;


#ifndef USE_USCI_A1
#define UCAxCTLW0     UCA0CTLW0 
#define UCAxCTL0      UCA0CTL0
#define UCAxCTL1      UCA0CTL1   
#define UCAxCTL0      UCA0CTL0   
#define UCAxBRW       UCA0BRW   
#define UCAxBR0       UCA0BR0    
#define UCAxBR1       UCA0BR1    
#define UCAxMCTL      UCA0MCTL  
#define UCAxMCTLW     UCA0MCTLW  
#define UCAxSTAT      UCA0STAT  
#define UCAxRXBUF     UCA0RXBUF 
#define UCAxTXBUF     UCA0TXBUF 
#define UCAxABCTL     UCA0ABCTL 
#define UCAxIRCTL     UCA0IRCTL 
#define UCAxIRTCTL    UCA0IRTCTL 
#define UCAxIRRCTL    UCA0IRRCTL 
#define UCAxICTL      UCA0ICTL  
#define UCAxIE        UCA0IE     
#define UCAxIFG       UCA0IFG    
#define UCAxIV        UCA0IV    
#else
#define UCAxCTLW0     UCA1CTLW0 
#define UCAxCTL0      UCA1CTL0
#define UCAxCTL1      UCA1CTL1   
#define UCAxCTL0      UCA1CTL0   
#define UCAxBRW       UCA1BRW   
#define UCAxBR0       UCA1BR0    
#define UCAxBR1       UCA1BR1    
#define UCAxMCTL      UCA1MCTL  
#define UCAxMCTLW     UCA1MCTLW  
#define UCAxSTAT      UCA1STAT  
#define UCAxRXBUF     UCA1RXBUF 
#define UCAxTXBUF     UCA1TXBUF 
#define UCAxABCTL     UCA1ABCTL 
#define UCAxIRCTL     UCA1IRCTL 
#define UCAxIRTCTL    UCA1IRTCTL 
#define UCAxIRRCTL    UCA1IRRCTL 
#define UCAxICTL      UCA1ICTL  
#define UCAxIE        UCA1IE     
#define UCAxIFG       UCA1IFG    
#define UCAxIV        UCA1IV    
#endif


#define SERIAL_BUFFER_SIZE 16

struct ring_buffer
{
	unsigned char buffer[SERIAL_BUFFER_SIZE];
	volatile unsigned int head;
	volatile unsigned int tail;
};

ring_buffer rx_buffer  =  { { 0 }, 0, 0 };
ring_buffer tx_buffer  =  { { 0 }, 0, 0 };

inline void store_char(unsigned char c, ring_buffer *buffer)
{
	unsigned int i = (unsigned int)(buffer->head + 1) % SERIAL_BUFFER_SIZE;

	// if we should be storing the received character into the location
	// just before the tail (meaning that the head would advance to the
	// current location of the tail), we're about to overflow the buffer
	// and so we don't write the character or advance the head.
	if (i != buffer->tail) {
		buffer->buffer[buffer->head] = c;
		buffer->head = i;
	}
}

void serialEvent() __attribute__((weak));
void serialEvent() {}

void serialEventRun(void)
{
  if (Serial.available()) serialEvent();
}
// Constructors ////////////////////////////////////////////////////////////////

HardwareSerial::HardwareSerial(ring_buffer *rx_buffer, ring_buffer *tx_buffer)
{
	_rx_buffer = rx_buffer;
	_tx_buffer = tx_buffer;
}

// Public Methods //////////////////////////////////////////////////////////////
#define SMCLK F_CPU //SMCLK = F_CPU for now

void HardwareSerial::begin(unsigned long baud)
{
	unsigned int mod, divider;
	unsigned char oversampling;
	
	/* Calling this dummy function prevents the linker
	 * from stripping the USCI interupt vectors.*/ 
	usci_isr_install();
	if (SMCLK/baud>=48) {                                                // requires SMCLK for oversampling
		oversampling = 1;
	}
	else {
		oversampling= 0;
	}

	divider=(SMCLK<<4)/baud;

	SerialPtr = this;

	pinMode_int(UARTRXD, UARTRXD_SET_MODE);
	pinMode_int(UARTTXD, UARTTXD_SET_MODE);	

	UCAxCTL1 = UCSWRST;
	UCAxCTL1 = UCSSEL_2;                                // SMCLK
	UCAxCTL0 = 0;
	UCAxABCTL = 0;
#if defined(__MSP430_HAS_EUSCI_A0__)
	if(!oversampling) {
		mod = ((divider&0xF)+1)&0xE;                    // UCBRSx (bit 1-3)
		divider >>=4;
	} else {
		mod = divider&0xFFF0;                           // UCBRFx = INT([(N/16) – INT(N/16)] × 16)
		divider>>=8;
	}
	UCAxBR0 = divider;
	UCAxBR1 = divider>>8;
	UCAxMCTLW = (oversampling ? UCOS16:0) | mod;
#else
	if(!oversampling) {
		mod = ((divider&0xF)+1)&0xE;                    // UCBRSx (bit 1-3)
		divider >>=4;
	} else {
		mod = ((divider&0xf8)+0x8)&0xf0;                // UCBRFx (bit 4-7)
		divider>>=8;
	}
	UCAxBR0 = divider;
	UCAxBR1 = divider>>8;
	UCAxMCTL = (unsigned char)(oversampling ? UCOS16:0) | mod;
#endif	
	UCAxCTL1 &= ~UCSWRST;
#if defined(__MSP430_HAS_USCI_A0__) || defined(__MSP430_HAS_USCI_A1__) || defined(__MSP430_HAS_EUSCI_A0__)
	UCAxIE |= UCRXIE;
#else
	UC0IE |= UCA0RXIE;
#endif	
}

void HardwareSerial::end()
{
	// wait for transmission of outgoing data
	while (_tx_buffer->head != _tx_buffer->tail);

	_rx_buffer->head = _rx_buffer->tail;
}

int HardwareSerial::available(void)
{
	return (unsigned int)(SERIAL_BUFFER_SIZE + _rx_buffer->head - _rx_buffer->tail) % SERIAL_BUFFER_SIZE;
}

int HardwareSerial::peek(void)
{
	if (_rx_buffer->head == _rx_buffer->tail) {
		return -1;
	} else {
		return _rx_buffer->buffer[_rx_buffer->tail];
	}
}

int HardwareSerial::read(void)
{
	// if the head isn't ahead of the tail, we don't have any characters
	if (_rx_buffer->head == _rx_buffer->tail) {
		return -1;
	} else {
		unsigned char c = _rx_buffer->buffer[_rx_buffer->tail];
		_rx_buffer->tail = (unsigned int)(_rx_buffer->tail + 1) % SERIAL_BUFFER_SIZE;
		return c;
	}
}

void HardwareSerial::flush()
{
	while (_tx_buffer->head != _tx_buffer->tail);
}

size_t HardwareSerial::write(uint8_t c)
{
	unsigned int i = (_tx_buffer->head + 1) % SERIAL_BUFFER_SIZE;
	
	// If the output buffer is full, there's nothing for it other than to
	// wait for the interrupt handler to empty it a bit
	// ???: return 0 here instead?
	while (i == _tx_buffer->tail);
	
	_tx_buffer->buffer[_tx_buffer->head] = c;
	_tx_buffer->head = i;

#if defined(__MSP430_HAS_USCI_A0__) || defined(__MSP430_HAS_USCI_A1__) || defined(__MSP430_HAS_EUSCI_A0__)
	UCAxIE |= UCTXIE;
#else
	UC0IE |= UCA0TXIE;
#endif	

	return 1;
}

void uart_rx_isr(void)
{
	unsigned char c = UCAxRXBUF;
	store_char(c, &rx_buffer);
}

void uart_tx_isr(void)
{
	if (tx_buffer.head == tx_buffer.tail) {
		// Buffer empty, so disable interrupts
#if defined(__MSP430_HAS_USCI_A0__) || defined(__MSP430_HAS_USCI_A1__) || defined(__MSP430_HAS_EUSCI_A0__)
		UCAxIE &= ~UCTXIE;
		UCAxIFG |= UCTXIFG;    // Set Flag again
#else
		UC0IE &= ~UCA0TXIE;
#endif	
		return;
	}

	unsigned char c = tx_buffer.buffer[tx_buffer.tail];
	tx_buffer.tail = (tx_buffer.tail + 1) % SERIAL_BUFFER_SIZE;
	UCAxTXBUF = c;
}

// Preinstantiate Objects //////////////////////////////////////////////////////

HardwareSerial Serial(&rx_buffer, &tx_buffer);

#endif
