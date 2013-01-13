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
  Modified 28 September 2010 by Mark Sproul
  Modified 14 August 2012 by Alarus
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include "Arduino.h"
#include "wiring_private.h"

// this next line disables the entire HardwareSerial.cpp,
// this is so I can support Attiny series and any other chip without a uart
#if defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H)

#include "HardwareSerial.h"

// Define constants and variables for buffering incoming serial data.  We're
// using a ring buffer (I think), in which head is the index of the location
// to which to write the next incoming character and tail is the index of the
// location from which to read.
#if (RAMEND < 1000)
  #define SERIAL_BUFFER_SIZE 16
#else
  #define SERIAL_BUFFER_SIZE 64
#endif

struct ring_buffer
{
  unsigned char * buffer;
  volatile unsigned int head;
  volatile unsigned int tail;
};

struct ring_buffer_16u{
  unsigned short * buffer;
  volatile unsigned int head;
  volatile unsigned int tail;
};

#if defined(USBCON)
  ring_buffer rx_buffer;
  ring_buffer tx_buffer;
#endif
#if defined(UBRRH) || defined(UBRR0H)
  ring_buffer rx_buffer;
  ring_buffer tx_buffer;
  ring_buffer_16u rx_buffer_16u;
  ring_buffer_16u tx_buffer_16u;
  uint8_t UART0_16_bit;
  bool txDataFinished0 = 0;
#endif
#if defined(UBRR1H)
  ring_buffer rx_buffer1;
  ring_buffer tx_buffer1;
  ring_buffer_16u rx_buffer_16u1;
  ring_buffer_16u tx_buffer_16u1;
  uint8_t UART1_16_bit;
  bool txDataFinished1 = 0;
#endif
#if defined(UBRR2H)
  ring_buffer rx_buffer2;
  ring_buffer tx_buffer2;
  ring_buffer_16u rx_buffer_16u2;
  ring_buffer_16u tx_buffer_16u2;
  uint8_t UART2_16_bit;
  bool txDataFinished2 = 0;
#endif
#if defined(UBRR3H)
  ring_buffer rx_buffer3;
  ring_buffer tx_buffer3;
  ring_buffer_16u rx_buffer_16u3;
  ring_buffer_16u tx_buffer_16u3;
  uint8_t UART3_16_bit;
  bool txDataFinished3 = 0;
#endif

#define BUILD_RX_WORD(UDregister, UCSRBregister, DEST) { \
	DEST=0; \
	DEST = (UCSRBregister >> 1) & 0x01; \
	DEST <<= 8; \
	DEST |= UDregister; \
}

inline void store_char(unsigned char c, ring_buffer *buffer)
{
  int i = (unsigned int)(buffer->head + 1) % SERIAL_BUFFER_SIZE;

  // if we should be storing the received character into the location
  // just before the tail (meaning that the head would advance to the
  // current location of the tail), we're about to overflow the buffer
  // and so we don't write the character or advance the head.
  if (i != buffer->tail) {
    buffer->buffer[buffer->head] = c;
    buffer->head = i;
  }
}

inline void store_char_16u(unsigned short data, ring_buffer_16u *buffer)
{
  int i = (unsigned int)(buffer->head + 1) % SERIAL_BUFFER_SIZE;

  // if we should be storing the received character into the location
  // just before the tail (meaning that the head would advance to the
  // current location of the tail), we're about to overflow the buffer
  // and so we don't write the character or advance the head.
  if (i != buffer->tail) {
    buffer->buffer[buffer->head] = data;
    buffer->head = i;
  }
}
#if !defined(USART0_RX_vect) && defined(USART1_RX_vect)
// do nothing - on the 32u4 the first USART is USART1
#else
#if !defined(USART_RX_vect) && !defined(SIG_USART0_RECV) && \
    !defined(SIG_UART0_RECV) && !defined(USART0_RX_vect) && \
	!defined(SIG_UART_RECV)
  #error "Don't know what the Data Received vector is called for the first UART"
#else
  void serialEvent() __attribute__((weak));
  void serialEvent() {}
  #define serialEvent_implemented
#if defined(USART_RX_vect)
  SIGNAL(USART_RX_vect)
#elif defined(SIG_USART0_RECV)
  SIGNAL(SIG_USART0_RECV)
#elif defined(SIG_UART0_RECV)
  SIGNAL(SIG_UART0_RECV)
#elif defined(USART0_RX_vect)
  SIGNAL(USART0_RX_vect)
#elif defined(SIG_UART_RECV)
  SIGNAL(SIG_UART_RECV)
#endif
  {
  #if defined(UDR0)
    if (bit_is_clear(UCSR0A, UPE0)) {
      if(!UART0_16_bit){
        unsigned short c = UDR0;
        store_char(c, &rx_buffer);
      }else{
        unsigned short dest;
        BUILD_RX_WORD(UDR0, UCSR0B, dest);
        store_char_16u(dest, &rx_buffer_16u);
      }
    } else {
      unsigned char c = UDR0;
    };
  #elif defined(UDR)
    if (bit_is_clear(UCSRA, PE)) {
      if(!UART0_16_bit){
        unsigned short c = UDR;
        store_char(c, rx_buffer);
      }else{
        unsigned short dest;
        BUILD_RX_WORD(UDR, UCSRB, dest);
        store_char_16u(dest, rx_buffer_16u);
      }
    } else {
      unsigned char c = UDR;
    };
  #else
    #error UDR not defined
  #endif
  }
#endif
#endif

#if defined(USART1_RX_vect)
  void serialEvent1() __attribute__((weak));
  void serialEvent1() {}
  #define serialEvent1_implemented
  SIGNAL(USART1_RX_vect)
  {
    if (bit_is_clear(UCSR1A, UPE1)) {
      if(!UART1_16_bit){
        unsigned short c = UDR1;
        store_char(c, &rx_buffer1);
      }else{
        unsigned short dest;
        BUILD_RX_WORD(UDR1, UCSR1B, dest);
        store_char_16u(dest, &rx_buffer_16u1);
      }
    } else {
      unsigned char c = UDR1;
    }
  }
#elif defined(SIG_USART1_RECV)
  #error SIG_USART1_RECV
#endif

#if defined(USART2_RX_vect) && defined(UDR2)
  void serialEvent2() __attribute__((weak));
  void serialEvent2() {}
  #define serialEvent2_implemented
  SIGNAL(USART2_RX_vect)
  {
    if (bit_is_clear(UCSR2A, UPE2)) {
      if(!UART2_16_bit){
        unsigned short c = UDR2;
        store_char(c, &rx_buffer2);
      }else{
        unsigned short dest;
        BUILD_RX_WORD(UDR2, UCSR2B, dest);
        store_char_16u(dest, &rx_buffer_16u2);
      }

    } else {
      unsigned char c = UDR2;
    }
  }
#elif defined(SIG_USART2_RECV)
  #error SIG_USART2_RECV
#endif

#if defined(USART3_RX_vect) && defined(UDR3)
  void serialEvent3() __attribute__((weak));
  void serialEvent3() {}
  #define serialEvent3_implemented
  SIGNAL(USART3_RX_vect)
  {
    if (bit_is_clear(UCSR3A, UPE3)) {
      if(!UART3_16_bit){
        unsigned short c = UDR3;
        store_char(c, &rx_buffer3);
      }else{
        unsigned short dest;
        BUILD_RX_WORD(UDR3, UCSR3B, dest);
        store_char_16u(dest, &rx_buffer_16u3);
      }

    } else {
      unsigned char c = UDR3;
    }
  }
#elif defined(SIG_USART3_RECV)
  #error SIG_USART3_RECV
#endif
#if !defined(USART0_TX_vect) && defined(USART1_TX_vect)
// do nothing - on the 32u4 the first USART is USART1
#else
  #define transmissionFinishedEvent0_implemented
  void transmissionFinishedEvent() __attribute__((weak));
  void transmissionFinishedEvent() {}
#endif

#ifdef USART1_TX_vect
  #define transmissionFinishedEvent1_implemented
  void transmissionFinishedEvent1() __attribute__((weak));
  void transmissionFinishedEvent1() {}
#endif

#ifdef USART2_TX_vect
  #define transmissionFinishedEvent2_implemented
  void transmissionFinishedEvent2() __attribute__((weak));
  void transmissionFinishedEvent2() {}
#endif

#ifdef USART3_TX_vect
  #define transmissionFinishedEvent3_implemented
  void transmissionFinishedEvent3() __attribute__((weak));
  void transmissionFinishedEvent3() {}
#endif

void serialEventRun(void)
{
#ifdef serialEvent_implemented
  if (Serial.available()) serialEvent();
#endif
#ifdef serialEvent1_implemented
  if (Serial1.available()) serialEvent1();
#endif
#ifdef serialEvent2_implemented
  if (Serial2.available()) serialEvent2();
#endif
#ifdef serialEvent3_implemented
  if (Serial3.available()) serialEvent3();
#endif
#ifdef transmissionFinishedEvent0_implemented
  if (txDataFinished0) {txDataFinished0 = 0; transmissionFinishedEvent();}
#endif
#ifdef transmissionFinishedEvent1_implemented
  if (txDataFinished1) {txDataFinished1 = 0; transmissionFinishedEvent1();}
#endif
#ifdef transmissionFinishedEvent2_implemented
  if (txDataFinished2) {txDataFinished2 = 0; transmissionFinishedEvent2();}
#endif
#ifdef transmissionFinishedEvent3_implemented
  if (txDataFinished3) {txDataFinished3 = 0; transmissionFinishedEvent3();}
#endif

}


#if !defined(USART0_UDRE_vect) && defined(USART1_UDRE_vect)
// do nothing - on the 32u4 the first USART is USART1
#else
#if !defined(UART0_UDRE_vect) && !defined(UART_UDRE_vect) && !defined(USART0_UDRE_vect) && !defined(USART_UDRE_vect)
  #error "Don't know what the Data Register Empty vector is called for the first UART"
#else
#if defined(UART0_UDRE_vect)
ISR(UART0_UDRE_vect)
#elif defined(UART_UDRE_vect)
ISR(UART_UDRE_vect)
#elif defined(USART0_UDRE_vect)
ISR(USART0_UDRE_vect)
#elif defined(USART_UDRE_vect)
ISR(USART_UDRE_vect)
#endif
{
  unsigned short c;
  if (!UART0_16_bit) { // If USART is in 8 bit mode load the c variable with data
    if (tx_buffer.head == tx_buffer.tail) {
      // Buffer empty, so disable interrupts
      txDataFinished0 = 1;
#if defined(UCSR0B)
      cbi(UCSR0B, UDRIE0);
#else
      cbi(UCSRB, UDRIE);
#endif
      return ;
    } else {
      // There is more data in the output buffer. Send the next byte
      c = tx_buffer.buffer[tx_buffer.tail];
      tx_buffer.tail = (tx_buffer.tail + 1) % SERIAL_BUFFER_SIZE;
    }
  }else{ // else if is in 9 bit mode check the buffer ninth bit and set it to UCSR*B
    if (tx_buffer_16u.head == tx_buffer_16u.tail) {
      // Buffer empty, so disable interrupts
      txDataFinished0 = 1;
#if defined(UCSR0B)
      cbi(UCSR0B, UDRIE0);
#else
      cbi(UCSRB, UDRIE);
#endif
      return ;
    } else {
      c = tx_buffer_16u.buffer[tx_buffer_16u.tail];
      tx_buffer_16u.tail = (tx_buffer_16u.tail + 1) % SERIAL_BUFFER_SIZE;
      if (c & 0x0100)
#if defined(UCSR0B)
        UCSR0B |= (1 << UCSRB_NINTH_BIT);
#else
        UCSRB |= (1 << UCSRB_NINTH_BIT);
#endif
      else
#if defined(UCSR0B)
        UCSR0B &= ~(1 << UCSRB_NINTH_BIT);
#else
        UCSRB &= ~(1 << UCSRB_NINTH_BIT);
#endif
    }
  }
#if defined(UDR0)
  UDR0 = c;
#elif defined(UDR)
  UDR = c;
#else
  #error UDR not defined
#endif
}
#endif
#endif

#ifdef USART1_UDRE_vect
ISR(USART1_UDRE_vect)
{
  unsigned short c;
  if (!UART1_16_bit) { // If USART is in 8 bit mode load the c variable with data
    if (tx_buffer1.head == tx_buffer1.tail) {
      txDataFinished1 = 1;
      cbi(UCSR1B, UDRIE1);
      return ;
    } else {
      c = tx_buffer1.buffer[tx_buffer1.tail];
      tx_buffer1.tail = (tx_buffer1.tail + 1) % SERIAL_BUFFER_SIZE;
    }
  }else{ // else if is in 9 bit mode check the buffer ninth bit and set it to UCSR*B
    if (tx_buffer_16u1.head == tx_buffer_16u1.tail) {
      txDataFinished1 = 1;
      cbi(UCSR1B, UDRIE1);
      return ;
    } else {
      c = tx_buffer_16u1.buffer[tx_buffer_16u1.tail];
      tx_buffer_16u1.tail = (tx_buffer_16u1.tail + 1) % SERIAL_BUFFER_SIZE;
      if (c & 0x0100)
        UCSR1B |= (1 << UCSRB_NINTH_BIT);
      else
        UCSR1B &= ~(1 << UCSRB_NINTH_BIT);
    }
  }
  UDR1 = c;
}
#endif

#ifdef USART2_UDRE_vect
ISR(USART2_UDRE_vect)
{
  unsigned short c;
  if (!UART2_16_bit) { // If USART is in 8 bit mode load the c variable with data
    if (tx_buffer2.head == tx_buffer2.tail) {
      cbi(UCSR2B, UDRIE2);
      txDataFinished2 = 1;
      return ;
    } else {
      c = tx_buffer2.buffer[tx_buffer2.tail];
      tx_buffer2.tail = (tx_buffer2.tail + 1) % SERIAL_BUFFER_SIZE;
    }
  } else { // else if is in 9 bit mode check the buffer ninth bit and set it to UCSR*B
    if (tx_buffer_16u2.head == tx_buffer_16u2.tail) {
      cbi(UCSR2B, UDRIE2);
      txDataFinished2 = 1;
      return ;
    } else {
      c = tx_buffer_16u2.buffer[tx_buffer_16u2.tail];
      tx_buffer_16u2.tail = (tx_buffer_16u2.tail + 1) % SERIAL_BUFFER_SIZE;
      if (c & 0x0100)
        UCSR2B |= (1 << UCSRB_NINTH_BIT);
      else
        UCSR2B &= ~(1 << UCSRB_NINTH_BIT);
    }
  }
  UDR2 = c;
}
#endif

#ifdef USART3_UDRE_vect
ISR(USART3_UDRE_vect)
{
  unsigned short c;
  if (!UART3_16_bit) { // If USART is in 8 bit mode load the c variable with data
    if (tx_buffer3.head == tx_buffer3.tail) {
      cbi(UCSR3B, UDRIE3);
      txDataFinished3 = 1;
      return ;
    } else {
      c = tx_buffer3.buffer[tx_buffer3.tail];
      tx_buffer3.tail = (tx_buffer3.tail + 1) % SERIAL_BUFFER_SIZE;
    }
  } else { // else if is in 9 bit mode check the buffer ninth bit and set it to UCSR*B
    if (tx_buffer_16u3.head == tx_buffer_16u3.tail) {
      cbi(UCSR3B, UDRIE3);
      txDataFinished3 = 1;
      return ;
    } else {
      c = tx_buffer_16u3.buffer[tx_buffer_16u3.tail];
      tx_buffer_16u3.tail = (tx_buffer_16u3.tail + 1) % SERIAL_BUFFER_SIZE;
      if (c & 0x0100)
        UCSR3B |= (1 << UCSRB_NINTH_BIT);
      else
        UCSR3B &= ~(1 << UCSRB_NINTH_BIT);
    }
  }
  UDR3 = c;
}
#endif


// Constructors ////////////////////////////////////////////////////////////////
HardwareSerial::HardwareSerial(ring_buffer *rx_buffer, ring_buffer *tx_buffer,
  ring_buffer_16u *rx_buffer_16u, ring_buffer_16u *tx_buffer_16u,
  volatile uint8_t *UART_16bit_mode,
  volatile uint8_t *ubrrh, volatile uint8_t *ubrrl,
  volatile uint8_t *ucsra, volatile uint8_t *ucsrb,
  volatile uint8_t *ucsrc, volatile uint8_t *udr,
  uint8_t rxen, uint8_t txen, uint8_t rxcie, uint8_t udrie, uint8_t u2x)
{
  _rx_buffer = rx_buffer;
  _rx_buffer_16u = rx_buffer_16u;

  _tx_buffer = tx_buffer;
  _tx_buffer_16u = tx_buffer_16u;

  _UART_16bit_mode = UART_16bit_mode;

  _ubrrh = ubrrh;
  _ubrrl = ubrrl;
  _ucsra = ucsra;
  _ucsrb = ucsrb;
  _ucsrc = ucsrc;
  _udr = udr;
  _rxen = rxen;
  _txen = txen;
  _rxcie = rxcie;
  _udrie = udrie;
  _u2x = u2x;

}

// Public Methods //////////////////////////////////////////////////////////////

void HardwareSerial::begin(unsigned long baud)
{
  uint16_t baud_setting;
  bool use_u2x = true;

#if F_CPU == 16000000UL
  // hardcoded exception for compatibility with the bootloader shipped
  // with the Duemilanove and previous boards and the firmware on the 8U2
  // on the Uno and Mega 2560.
  if (baud == 57600) {
    use_u2x = false;
  }
#endif

try_again:

  if (use_u2x) {
    *_ucsra = 1 << _u2x;
    baud_setting = (F_CPU / 4 / baud - 1) / 2;
  } else {
    *_ucsra = 0;
    baud_setting = (F_CPU / 8 / baud - 1) / 2;
  }

  if ((baud_setting > 4095) && use_u2x)
  {
    use_u2x = false;
    goto try_again;
  }

  // assign the baud_setting, a.k.a. ubbr (USART Baud Rate Register)
  *_ubrrh = baud_setting >> 8;
  *_ubrrl = baud_setting;

  *_UART_16bit_mode = 0;
  _rx_buffer->buffer = (unsigned char *) malloc(SERIAL_BUFFER_SIZE * sizeof(unsigned char));
  _tx_buffer->buffer = (unsigned char *) malloc(SERIAL_BUFFER_SIZE * sizeof(unsigned char));
  transmitting = false;

  sbi(*_ucsrb, _rxen);
  sbi(*_ucsrb, _txen);
  sbi(*_ucsrb, _rxcie);
  cbi(*_ucsrb, _udrie);
  cbi(*_ucsra, UPE0);
}

void HardwareSerial::begin(unsigned long baud, uint16_t config)
{
  uint16_t baud_setting;
  uint8_t current_config;
  bool use_u2x = true;

#if F_CPU == 16000000UL
  // hardcoded exception for compatibility with the bootloader shipped
  // with the Duemilanove and previous boards and the firmware on the 8U2
  // on the Uno and Mega 2560.
  if (baud == 57600) {
    use_u2x = false;
  }
#endif

try_again:

  if (use_u2x) {
    *_ucsra = 1 << _u2x;
    baud_setting = (F_CPU / 4 / baud - 1) / 2;
  } else {
    *_ucsra = 0;
    baud_setting = (F_CPU / 8 / baud - 1) / 2;
  }

  if ((baud_setting > 4095) && use_u2x)
  {
    use_u2x = false;
    goto try_again;
  }

  // assign the baud_setting, a.k.a. ubbr (USART Baud Rate Register)
  *_ubrrh = baud_setting >> 8;
  *_ubrrl = baud_setting;

  //set the data bits, parity, and stop bits
#if defined(__AVR_ATmega8__)
  config |= 0x80; // select UCSRC register (shared with UBRRH)
#endif
  *_ucsrc = config & 0x00ff;


  if (config & 0x0100) { // 9 bit transmission
    *_ucsrb |= 0x04;
    *_UART_16bit_mode = 1;
    _rx_buffer_16u->buffer = (unsigned short *) malloc(SERIAL_BUFFER_SIZE * sizeof(unsigned short));
    _tx_buffer_16u->buffer = (unsigned short *) malloc(SERIAL_BUFFER_SIZE * sizeof(unsigned short));
  }else{
    *_UART_16bit_mode = 0;
    _rx_buffer->buffer = (unsigned char *) malloc(SERIAL_BUFFER_SIZE * sizeof(unsigned char));
    _tx_buffer->buffer = (unsigned char *) malloc(SERIAL_BUFFER_SIZE * sizeof(unsigned char));
  }

  transmitting = false;

  sbi(*_ucsrb, _rxen);
  sbi(*_ucsrb, _txen);
  sbi(*_ucsrb, _rxcie);
  cbi(*_ucsrb, _udrie);
}

void HardwareSerial::end()
{
  // wait for transmission of outgoing data
  if(*_UART_16bit_mode){
    while (_tx_buffer_16u->head != _tx_buffer_16u->tail);
    _rx_buffer_16u->head = _rx_buffer_16u->tail;
    free(_tx_buffer_16u->buffer);
    free(_rx_buffer_16u->buffer);
  }else{
    while (_tx_buffer->head != _tx_buffer->tail);
    _rx_buffer->head = _rx_buffer->tail;
    free(_tx_buffer->buffer);
    free(_rx_buffer->buffer);
  }

  cbi(*_ucsrb, _rxen);
  cbi(*_ucsrb, _txen);
  cbi(*_ucsrb, _rxcie);
  cbi(*_ucsrb, _udrie);
}

void HardwareSerial::setTxFinishedCallback(void (*callback)()){
  *_tx_finished_callback = callback;
}

void HardwareSerial::setRxDataCallback(void (*callback)()){
  *_rx_data_callback =  callback;
}


int HardwareSerial::available(void)
{
  if(*_UART_16bit_mode){
    return (unsigned int)(SERIAL_BUFFER_SIZE + _rx_buffer_16u->head - _rx_buffer_16u->tail) % SERIAL_BUFFER_SIZE;
  }else{
    return (unsigned int)(SERIAL_BUFFER_SIZE + _rx_buffer->head - _rx_buffer->tail) % SERIAL_BUFFER_SIZE;
  }
}

int HardwareSerial::peek(void)
{
  if(*_UART_16bit_mode){
    if (_tx_buffer_16u->head == _tx_buffer_16u->tail) {
      return -1;
    } else {
      return _tx_buffer_16u->buffer[_tx_buffer_16u->tail];
    }
  }else{
    if (_rx_buffer->head == _rx_buffer->tail) {
      return -1;
    } else {
      return _rx_buffer->buffer[_rx_buffer->tail];
    }
  }
}

int HardwareSerial::read(void)
{
  // if the head isn't ahead of the tail, we don't have any characters
  if(*_UART_16bit_mode){
    if (_rx_buffer_16u->head == _rx_buffer_16u->tail) {
      return -1;
    } else {
      unsigned int c = _rx_buffer_16u->buffer[_rx_buffer_16u->tail];
      _rx_buffer_16u->tail = (unsigned int)(_rx_buffer_16u->tail + 1) % SERIAL_BUFFER_SIZE;
      return c;
    }
  }else{
    if (_rx_buffer->head == _rx_buffer->tail) {
      return -1;
    } else {
      unsigned char c = _rx_buffer->buffer[_rx_buffer->tail];
      _rx_buffer->tail = (unsigned int)(_rx_buffer->tail + 1) % SERIAL_BUFFER_SIZE;
      return c;
    }
  }
}

void HardwareSerial::flush()
{
  // UDR is kept full while the buffer is not empty, so TXC triggers when EMPTY && SENT
  while (transmitting && ! (*_ucsra & _BV(TXC0)));
  transmitting = false;
}
/*
size_t HardwareSerial::write(uint8_t c)
{
  return _write(c);
}

size_t HardwareSerial::write(int n){
  return _write(n);
}
*/
size_t HardwareSerial::_write(unsigned int c){
  if(*_UART_16bit_mode){
    int i = (_tx_buffer_16u->head + 1) % SERIAL_BUFFER_SIZE;
    // If the output buffer is full, there's nothing for it other than to
    // wait for the interrupt handler to empty it a bit
    // ???: return 0 here instead?
    while (i == _tx_buffer_16u->tail);
    _tx_buffer_16u->buffer[_tx_buffer_16u->head] = c;
    _tx_buffer_16u->head = i;
  }else{
    int i = (_tx_buffer->head + 1) % SERIAL_BUFFER_SIZE;
    // If the output buffer is full, there's nothing for it other than to
    // wait for the interrupt handler to empty it a bit
    // ???: return 0 here instead?
    while (i == _tx_buffer->tail);
    _tx_buffer->buffer[_tx_buffer->head] = c;
    _tx_buffer->head = i;

  }

  sbi(*_ucsrb, _udrie);
  // clear the TXC bit -- "can be cleared by writing a one to its bit location"
  transmitting = true;
  sbi(*_ucsra, TXC0);
}

HardwareSerial::operator bool() {
	return true;
}

// Preinstantiate Objects //////////////////////////////////////////////////////

#if defined(UBRRH) && defined(UBRRL)
  HardwareSerial Serial(&rx_buffer, &tx_buffer, &rx_buffer_16u, &tx_buffer_16u, &UART0_16_bit, &UBRRH, &UBRRL, &UCSRA, &UCSRB, &UCSRC, &UDR, RXEN, TXEN, RXCIE, UDRIE, U2X);
#elif defined(UBRR0H) && defined(UBRR0L)
  HardwareSerial Serial(&rx_buffer, &tx_buffer, &rx_buffer_16u, &tx_buffer_16u, &UART0_16_bit, &UBRR0H, &UBRR0L, &UCSR0A, &UCSR0B, &UCSR0C, &UDR0, RXEN0, TXEN0, RXCIE0, UDRIE0, U2X0);
#elif defined(USBCON)
  // do nothing - Serial object and buffers are initialized in CDC code
#else
  #error no serial port defined  (port 0)
#endif

#if defined(UBRR1H)
  HardwareSerial Serial1(&rx_buffer1, &tx_buffer1, &rx_buffer_16u1, &tx_buffer_16u1, &UART1_16_bit, &UBRR1H, &UBRR1L, &UCSR1A, &UCSR1B, &UCSR1C, &UDR1, RXEN1, TXEN1, RXCIE1, UDRIE1, U2X1);
#endif
#if defined(UBRR2H)
  HardwareSerial Serial2(&rx_buffer2, &tx_buffer2, &rx_buffer_16u2, &tx_buffer_16u2, &UART2_16_bit, &UBRR2H, &UBRR2L, &UCSR2A, &UCSR2B, &UCSR2C, &UDR2, RXEN2, TXEN2, RXCIE2, UDRIE2, U2X2);
#endif
#if defined(UBRR3H)
  HardwareSerial Serial3(&rx_buffer3, &tx_buffer3, &rx_buffer_16u3, &tx_buffer_16u3, &UART3_16_bit, &UBRR3H, &UBRR3L, &UCSR3A, &UCSR3B, &UCSR3C, &UDR3, RXEN3, TXEN3, RXCIE3, UDRIE3, U2X3);
#endif

#endif // whole file

