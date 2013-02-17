/*
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
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include "Arduino.h"
#include "wiring_private.h"

#include "HardwareSerial.h"

// Define constants and variables for buffering incoming serial data.  We're
// using a ring buffer (I think), in which rx_buffer_head is the index of the
// location to which to write the next incoming character and rx_buffer_tail
// is the index of the location from which to read.
#define RX_BUFFER_SIZE 128

struct ring_buffer
{
  unsigned char buffer[RX_BUFFER_SIZE];
  int head;
  int tail;
};

inline void store_char(unsigned char c, ring_buffer *rx_buffer)
{
  int i = (unsigned int)(rx_buffer->head + 1) % RX_BUFFER_SIZE;

  // if we should be storing the received character into the location
  // just before the tail (meaning that the head would advance to the
  // current location of the tail), we're about to overflow the buffer
  // and so we don't write the character or advance the head.
  if (i != rx_buffer->tail) {
    rx_buffer->buffer[rx_buffer->head] = c;
    rx_buffer->head = i;
  }
}

// Constructors ////////////////////////////////////////////////////////////////

HardwareSerial::HardwareSerial(
  ring_buffer *rx_buffer,
  USART_t     *usart,
  PORT_t      *port,
  uint8_t      in_bm,
  uint8_t      out_bm)
{
  this->_rx_buffer = rx_buffer;
  this->_usart     = usart;
  this->_port      = port;
  this->_in_bm     = in_bm;
  this->_out_bm    = out_bm;
}

// Public Methods //////////////////////////////////////////////////////////////

void HardwareSerial::begin(long baud)
{
  uint16_t baud_setting;
  uint8_t bscale = 0;
  uint32_t div1k;
  bool use_u2x;

  // TODO: Serial. Fix serial double clock.
  use_u2x = false;

  _port->DIRCLR = _in_bm;  // input
  _port->OUTSET = _out_bm; // set output high
  _port->DIRSET = _out_bm; // set to output

  // Reset flags
  _usart->CTRLB = 0;

  // set the baud rate
  if (baud > (F_CPU/(use_u2x ? 16 : 32))) return; // Baudrate is set too high

  div1k = ((F_CPU*(use_u2x ? 128UL : 64UL)) / baud) - 1024;
  while ((div1k < 2096640UL) && (bscale < 7)) {
    bscale++;
    div1k <<= 1;
  }

  baud_setting = div1k >> 10;

  _usart->BAUDCTRLA = baud_setting&0xff;
  _usart->BAUDCTRLB = (baud_setting>>8) | ((16-bscale) << 4);

  if(use_u2x)
	_usart->CTRLB |= USART_CLK2X_bm;
  
  // enable Rx and Tx
  _usart->CTRLB |= USART_RXEN_bm | USART_TXEN_bm;
  // enable interrupt
  _usart->CTRLA = (_usart->CTRLA & ~USART_RXCINTLVL_gm) | USART_RXCINTLVL_LO_gc;

  // Char size, parity and stop bits: 8N1
  _usart->CTRLC = USART_CHSIZE_8BIT_gc | USART_PMODE_DISABLED_gc;
}

void HardwareSerial::end()
{
  // disable Rx and Tx
  _usart->CTRLB &= ~(USART_RXEN_bm | USART_TXEN_bm);
  // disable interrupt
  _usart->CTRLA = (_usart->CTRLA & ~USART_RXCINTLVL_gm) | USART_RXCINTLVL_LO_gc;
}

int HardwareSerial::available(void)
{
  return (unsigned int)(RX_BUFFER_SIZE + _rx_buffer->head - _rx_buffer->tail) % RX_BUFFER_SIZE;
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
    _rx_buffer->tail = (unsigned int)(_rx_buffer->tail + 1) % RX_BUFFER_SIZE;
    return c;
  }
}

void HardwareSerial::flush()
{
  // don't reverse this or there may be problems if the RX interrupt
  // occurs after reading the value of rx_buffer_head but before writing
  // the value to rx_buffer_tail; the previous value of rx_buffer_head
  // may be written to rx_buffer_tail, making it appear as if the buffer
  // don't reverse this or there may be problems if the RX interrupt
  // occurs after reading the value of rx_buffer_head but before writing
  // the value to rx_buffer_tail; the previous value of rx_buffer_head
  // may be written to rx_buffer_tail, making it appear as if the buffer
  // were full, not empty.
  _rx_buffer->head = _rx_buffer->tail;
}

size_t HardwareSerial::write(uint8_t c)
{
  while ( !(_usart->STATUS & USART_DREIF_bm) );
  _usart->DATA = c;
  
  return 1;
}

void HardwareSerial::setIREnabled(bool enable)
{
	if(enable)
	{
		_usart->CTRLC |= USART_CMODE_IRDA_gc;
	}
	else
	{
		_usart->CTRLC &= ~USART_CMODE_IRDA_gc;
	}
}

#include "serial_init.cpp"

#if 1
// TODO: Move to diag.{c h}

extern "C" void diag_ln() {
    Serial2.println();
}

extern "C" void diag(const char* str) {
    Serial2.print(str);
}

extern "C" void diagln(const char* str) {
    diag(str);
    diag_ln();
}

extern "C" void diagN(long n) {
    Serial2.print(n);
}

extern "C" void diagN2(long n, int base) {
    Serial2.print(n,base);
}

#endif
