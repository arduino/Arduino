/*
  HardwareSerial.h - Hardware serial library for Wiring
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

  Modified 28 September 2010 by Mark Sproul
  Modified 14 August 2012 by Alarus
  Modified 12 April 2014 by Bouni
*/

#ifndef HardwareSerial_h
#define HardwareSerial_h

#include <inttypes.h>

#include "Stream.h"

struct ring_buffer;

class HardwareSerial : public Stream
{
  private:
    ring_buffer *_rx_buffer;
    ring_buffer *_tx_buffer;
    volatile uint8_t *_ubrrh;
    volatile uint8_t *_ubrrl;
    volatile uint8_t *_ucsra;
    volatile uint8_t *_ucsrb;
    volatile uint8_t *_ucsrc;
    volatile uint8_t *_udr;
    uint8_t _ucsz2;
    uint8_t _rxen;
    uint8_t _txen;
    uint8_t _rxcie;
    uint8_t _udrie;
    uint8_t _u2x;
    bool transmitting;
  public:
    HardwareSerial(ring_buffer *rx_buffer, ring_buffer *tx_buffer,
      volatile uint8_t *ubrrh, volatile uint8_t *ubrrl,
      volatile uint8_t *ucsra, volatile uint8_t *ucsrb,
      volatile uint8_t *ucsrc, volatile uint8_t *udr,
      uint8_t ucsz2, uint8_t rxen, uint8_t txen, uint8_t rxcie, uint8_t udrie, uint8_t u2x);
    void begin(unsigned long);
    void begin(unsigned long, unsigned int);
    void end();
    virtual int available(void);
    virtual int peek(void);
    virtual int read(void);
    virtual void flush(void);
    virtual size_t write(unsigned int);
    inline size_t write(uint8_t n) { return write((unsigned int)n); }
    inline size_t write(int8_t n) { return write((unsigned int)n); }
    inline size_t write(int n) { return write((unsigned int)n); }
    inline size_t write(unsigned long n) { return write((unsigned int)n); }
    inline size_t write(long n) { return write((unsigned int)n); }
    using Print::write; // pull in write(str) and write(buf, size) from Print
    operator bool();
};

// Define config for Serial.begin(baud, config);
#define SERIAL_5N1 0x000 //0b000000000
#define SERIAL_6N1 0x002 //0b000000010
#define SERIAL_7N1 0x004 //0b000000100
#define SERIAL_8N1 0x006 //0b000000110
#define SERIAL_9N1 0x106 //0b100000110

#define SERIAL_5N2 0x008 //0b000001000
#define SERIAL_6N2 0x00A //0b000001010
#define SERIAL_7N2 0x00C //0b000001100
#define SERIAL_8N2 0x00E //0b000001110
#define SERIAL_9N2 0x10E //0b100001110

#define SERIAL_5E1 0x020 //0b000100000
#define SERIAL_6E1 0x022 //0b000100010
#define SERIAL_7E1 0x024 //0b000100100
#define SERIAL_8E1 0x026 //0b000100110
#define SERIAL_9E1 0x126 //0b100100110

#define SERIAL_5E2 0x028 //0b000101000
#define SERIAL_6E2 0x02A //0b000101010
#define SERIAL_7E2 0x02C //0b000101100
#define SERIAL_8E2 0x02E //0b000101110
#define SERIAL_9E2 0x12E //0b100101110

#define SERIAL_5O1 0x030 //0b000110000
#define SERIAL_6O1 0x032 //0b000110010
#define SERIAL_7O1 0x034 //0b000110100
#define SERIAL_8O1 0x036 //0b000110110
#define SERIAL_9O1 0x136 //0b100110110

#define SERIAL_5O2 0x038 //0b000111000
#define SERIAL_6O2 0x03A //0b000111010
#define SERIAL_7O2 0x03C //0b000111100
#define SERIAL_8O2 0x03E //0b000111110
#define SERIAL_9O2 0x13E //0b100111110

#if defined(UBRRH) || defined(UBRR0H)
  extern HardwareSerial Serial;
#elif defined(USBCON)
  #include "USBAPI.h"
//  extern HardwareSerial Serial_;  
#endif
#if defined(UBRR1H)
  extern HardwareSerial Serial1;
#endif
#if defined(UBRR2H)
  extern HardwareSerial Serial2;
#endif
#if defined(UBRR3H)
  extern HardwareSerial Serial3;
#endif

extern void serialEventRun(void) __attribute__((weak));

#endif
