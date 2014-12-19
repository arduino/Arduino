
/*
  ************************************************************************
  *	HardwareSerial.cpp
  *
  *	Arduino core files for C2000
  *		Copyright (c) 2012 Eric Ma. All right reserved.
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
#include "sci_isr_handler.h"
#include "HardwareSerial.h"

HardwareSerial *SerialPtr;

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

void serialEvent();

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
#ifdef TMS320F28069
#define CPU_FREQ     90E6        // Set to 90 MHz for F28069
#else
#define CPU_FREQ     60E6        // Default = 60 MHz. Change to 50E6 for 50 MHz devices
#endif
#define LSPCLK_FREQ CPU_FREQ/4

void HardwareSerial::begin(unsigned long baud)
{

	   EALLOW;
	/* Enable internal pull-up for the selected pins */
	/* Disable internal pull-up for the selected output pins
	   to reduce power consumption. */
	// Pull-ups can be enabled or disabled disabled by the user.

		GpioCtrlRegs.GPAPUD.bit.GPIO28 = 0;    // Enable pull-up for GPIO28 (SCIRXDA)
		GpioCtrlRegs.GPAPUD.bit.GPIO29 = 1;	   // Disable pull-up for GPIO29 (SCITXDA)

	/* Set qualification for selected pins to asynch only */
	// Inputs are synchronized to SYSCLKOUT by default.
	// This will select asynch (no qualification) for the selected pins.

		GpioCtrlRegs.GPAQSEL2.bit.GPIO28 = 3;  // Asynch input GPIO28 (SCIRXDA)

	/* Configure SCI-A pins using GPIO regs*/
	// This specifies which of the possible GPIO pins will be SCI functional pins.

		GpioCtrlRegs.GPAMUX2.bit.GPIO28 = 1;   // Configure GPIO28 for SCIRXDA operation
		GpioCtrlRegs.GPAMUX2.bit.GPIO29 = 1;   // Configure GPIO29 for SCITXDA operation

	    EDIS;

	// ISR functions found within this file.
	    EALLOW;	// This is needed to write to EALLOW protected registers
	    PieVectTable.SCIRXINTA = &uart_rx_isr;
	    PieVectTable.SCITXINTA = &uart_tx_isr;
	    EDIS;   // This is needed to disable write to EALLOW protected registers

	// Note: Clocks were turned on to the SCIA peripheral
	// in the InitSysCtrl() function
	    EALLOW;
	    SysCtrlRegs.PCLKCR0.bit.SCIAENCLK = 1;      // SCI-A
	    SysCtrlRegs.LOSPCP.bit.LSPCLK = 1;          //LSPCLK = SYSCLK/2
	    EDIS;

	   	SciaRegs.SCICCR.all =0x0007;   // 1 stop bit,  No loopback
	                                     // No parity,8 char bits,
	                                     // async mode, idle-line protocol
	  	SciaRegs.SCICTL1.all =0x0003;  // enable TX, RX, internal SCICLK,
	                                     // Disable RX ERR, SLEEP, TXWAKE
	  	SciaRegs.SCICTL2.all =0x0003;
	  	SciaRegs.SCICTL2.bit.TXINTENA =1;
	  	SciaRegs.SCICTL2.bit.RXBKINTENA =1;
	    SciaRegs.SCIHBAUD    = (unsigned int)((F_CPU/(SysCtrlRegs.LOSPCP.bit.LSPCLK * 2))/(baud*8)-1)>>8 ;
	    SciaRegs.SCILBAUD    = (unsigned int)((F_CPU/(SysCtrlRegs.LOSPCP.bit.LSPCLK * 2))/(baud*8)-1)&0x00FF;
	  	//SciaRegs.SCICCR.bit.LOOPBKENA =0; // Disable loop back
	    SciaRegs.SCIFFTX.all=0xC020;
	    SciaRegs.SCIFFRX.all=0x0021;
	    SciaRegs.SCIFFCT.all=0x0;

	  	SciaRegs.SCICTL1.all =0x0023;     // Relinquish SCI from Reset


	  	SciaRegs.SCIFFTX.bit.TXFIFOXRESET=1;
	  	SciaRegs.SCIFFRX.bit.RXFIFORESET=1;

	  	// Enable interrupts required for the sci
	  	PieCtrlRegs.PIECTRL.bit.ENPIE = 1;   // Enable the PIE block
	  	PieCtrlRegs.PIEIER9.bit.INTx1=1;     // PIE Group 9, INT1
	  	PieCtrlRegs.PIEIER9.bit.INTx2=1;     // PIE Group 9, INT2
	  	IER |= 0x100;	// Enable CPU INT
	  	EINT;

}

void HardwareSerial::end()
{
	// wait for transmission of outgoing data
	while (_tx_buffer->head != _tx_buffer->tail);

	_rx_buffer->head = _rx_buffer->tail;

	// Disable the FIFO interrupts
	SciaRegs.SCIFFTX.bit.TXFFIENA = 0;
	SciaRegs.SCIFFRX.bit.RXFFIENA = 0;

}

int HardwareSerial::available(void)
{
	return (unsigned int)(SERIAL_BUFFER_SIZE + _rx_buffer->head - _rx_buffer->tail) % SERIAL_BUFFER_SIZE;
}

HardwareSerial::operator bool()
{
	return true;
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
	// return 0 here instead?
	while (i == _tx_buffer->tail);

	_tx_buffer->buffer[_tx_buffer->head] = c;
	_tx_buffer->head = i;

	//SciaRegs.SCICTL2.bit.TXINTENA =1;
	SciaRegs.SCIFFTX.bit.TXFFIENA = 1;

	return 1;
}



interrupt void uart_rx_isr(void)
{
	unsigned char c = SciaRegs.SCIRXBUF.all;
	store_char(c, &rx_buffer);

	SciaRegs.SCIFFRX.bit.RXFFOVRCLR=1;   // Clear Overflow flag
    SciaRegs.SCIFFRX.bit.RXFFINTCLR=1;   // Clear Interrupt flag

	PieCtrlRegs.PIEACK.all|=0x100;       // Issue PIE ack

}

interrupt void uart_tx_isr(void)
{
	if (tx_buffer.head == tx_buffer.tail) {
		// Buffer empty, so disable interrupts
		//SciaRegs.SCICTL2.bit.TXINTENA =0;
		SciaRegs.SCIFFTX.bit.TXFFIENA = 0;
		SciaRegs.SCIFFTX.bit.TXFFINTCLR=1;	// Clear SCI Interrupt flag
		PieCtrlRegs.PIEACK.all|=0x100;
		return;
	}

	unsigned char c = tx_buffer.buffer[tx_buffer.tail];
	tx_buffer.tail = (tx_buffer.tail + 1) % SERIAL_BUFFER_SIZE;
	SciaRegs.SCITXBUF = c;

	SciaRegs.SCIFFTX.bit.TXFFINTCLR=1;	// Clear SCI Interrupt flag
	PieCtrlRegs.PIEACK.all|=0x100;       // Issue PIE ack
}

// Preinstantiate Objects //////////////////////////////////////////////////////

HardwareSerial Serial(&rx_buffer, &tx_buffer);
