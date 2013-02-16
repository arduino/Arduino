/*
 (Ported from Arduino to Energia)

SoftwareSerial.cpp (formerly NewSoftSerial.cpp) - 
 Multi-instance software serial library for Arduino/Wiring
 -- Interrupt-driven receive and other improvements by ladyada
 (http://ladyada.net)
 -- Tuning, circular buffer, derivation from class Print/Stream,
 multi-instance support, porting to 8MHz processors,
 various optimizations, PROGMEM delay tables, inverse logic and 
 direct port writing by Mikal Hart (http://www.arduiniana.org)
 -- Pin change interrupt macros by Paul Stoffregen (http://www.pjrc.com)
 -- 20MHz processor support by Garrett Mace (http://www.macetech.com)
 -- ATmega1280/2560 support by Brett Hagman (http://www.roguerobotics.com/)
 
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
 
 The latest version of this library can always be found at
 http://arduiniana.org.
 */


// 
// Includes
// 
//#include <avr/interrupt.h>
//#include <avr/pgmspace.h>
//#include "Arduino.h"
#include "Energia.h"
#include "SoftwareSerial.h"

//
// Lookup table
//
typedef struct _DELAY_TABLE
{
  long baud;
  unsigned short rx_delay_centering;
  unsigned short rx_delay_intrabit;
  unsigned short rx_delay_stopbit;
  unsigned short tx_delay;
} 
DELAY_TABLE;

#if F_CPU == 16000000L

//formula is roughly rxintra=rxstop=tx = F_CPU / baud / 3 - 5/3
//    so, delay = 16000000 / 3 / baud - 5/3
//      and, rxcenter = 1/2 rxintra
_DELAY_TABLE table[] = 
{
  //  baud    rxcenter   rxintra    rxstop    tx
  {115200,   15,        32,        32,       32,      },
  {57600,    38,        78,        78,       78,      },
  {38400,    61,        123,       123,      123,     },
  {31250,    72,        155,       155,      155,     },
  {28800,    80,        170,       170,      170,     },
  {19200,    126,       262,       262,      262,     },
  {14400,    177,       353,       353,      353,     },
  {9600,     265,       540,       540,      540,     },
  {4800,     547,       1095,      1095,     1095,    },
  {2400,     1103,      2190,      2190,     2190,    },
  {1200,     2200,      4400,      4400,     4400,    },
  {300,      8881,      17762,     17762,    17762,   },
};

const int XMIT_START_ADJUSTMENT = 5;
#else
#error This version of SoftwareSerial supports only 16MHz processors

#endif


//
// Statics
//
SoftwareSerial *SoftwareSerial::active_object = 0;
char SoftwareSerial::_receive_buffer[_SS_MAX_RX_BUFF]; 
volatile uint8_t SoftwareSerial::_receive_buffer_tail = 0;
volatile uint8_t SoftwareSerial::_receive_buffer_head = 0;


//
// Private methods
//

/* static */
inline void SoftwareSerial::tunedDelay(uint16_t delay) { 
  //msp430:
  // don't pass in delay of zero, it will not handle it well... could add constant cost of 2 by starting with a jz .+3
  // cycles: pre + mid + post ~= 5 + delay*3
  asm volatile(
    " sub.w #1, %[delay]  \n"  //sub (not immediate, but special constant) from register: 1 cycle
    " jnz .-2            \n"   // 2 cycles regardless of branch
    :                          //no output
    : [delay] "r" (delay)      // input
    :                          // no memory clobber
  );
}

// This function sets the current object as the "listening"
// one and returns true if it replaces another 
bool SoftwareSerial::listen() {
  if (active_object != this) {
    _buffer_overflow = false;
    uint8_t oldSR = __read_status_register();
    noInterrupts();
    _receive_buffer_head = _receive_buffer_tail = 0;
    active_object = this;
    __write_status_register(oldSR);
    return true;
  }

  return false;
}

//
// The receive routine called by the interrupt handler
//
void SoftwareSerial::recv()
{
  uint8_t d = 0;

  // If RX line is high, then we don't see any start bit
  // so interrupt is probably not for us
  if (_inverse_logic ? rx_pin_read() : !rx_pin_read())
  {
    // Wait approximately 1/2 of a bit width to "center" the sample
    tunedDelay(_rx_delay_centering);

    // Read each of the 8 bits
    for (uint8_t i=0x1; i; i <<= 1)
    {
      tunedDelay(_rx_delay_intrabit);
      uint8_t noti = ~i;
      if (rx_pin_read())
        d |= i;
      else // else clause added to ensure function timing is ~balanced
      d &= noti;
    }

    // skip the stop bit
    tunedDelay(_rx_delay_stopbit);

    if (_inverse_logic)
      d = ~d;

    // if buffer full, set the overflow flag and return
    if ((_receive_buffer_tail + 1) % _SS_MAX_RX_BUFF != _receive_buffer_head) 
    {
      // save new data in buffer: tail points to where byte goes
      _receive_buffer[_receive_buffer_tail] = d; // save new byte
      _receive_buffer_tail = (_receive_buffer_tail + 1) % _SS_MAX_RX_BUFF;
    } 
    else 
    {
      _buffer_overflow = true;
    }
  }
}

void SoftwareSerial::tx_pin_write(uint8_t pin_state)
{
  if (pin_state == LOW)
    *_transmitPortRegister &= ~_transmitBitMask;
  else
    *_transmitPortRegister |= _transmitBitMask;
}

uint8_t SoftwareSerial::rx_pin_read()
{
  return *_receivePortRegister & _receiveBitMask;
}

//
// Interrupt handling
//

/* static */
void SoftwareSerial::handle_interrupt()
{
  if (active_object)
  {
    active_object->recv();
  }
}

//
// Constructor
//
SoftwareSerial::SoftwareSerial(uint8_t receivePin, uint8_t transmitPin, bool inverse_logic /* = false */) : 
_rx_delay_centering(0),
_rx_delay_intrabit(0),
_rx_delay_stopbit(0),
_tx_delay(0),
_buffer_overflow(false),
_inverse_logic(inverse_logic)
{
  setTX(transmitPin);
  setRX(receivePin);
}

//
// Destructor
//
SoftwareSerial::~SoftwareSerial()
{
  end();
}

void SoftwareSerial::setTX(uint8_t tx)
{
  pinMode(tx, OUTPUT);
  digitalWrite(tx, HIGH);
  _transmitBitMask = digitalPinToBitMask(tx);
  uint8_t port = digitalPinToPort(tx);
  _transmitPortRegister = portOutputRegister(port);
}

void SoftwareSerial::setRX(uint8_t rx)
{
  pinMode(rx, INPUT);
  if (!_inverse_logic)
    digitalWrite(rx, HIGH);  // pullup for normal logic!
  _receivePin = rx;
  _receiveBitMask = digitalPinToBitMask(rx);
  uint8_t port = digitalPinToPort(rx);
  _receivePortRegister = portInputRegister(port);
}

//
// Public methods
//

void SoftwareSerial::begin(long speed)
{
  _rx_delay_centering = _rx_delay_intrabit = _rx_delay_stopbit = _tx_delay = 0;

  for (unsigned i=0; i<sizeof(table)/sizeof(table[0]); ++i)
  {
    long baud = table[i].baud;
    if (baud == speed)
    {
      _rx_delay_centering = table[i].rx_delay_centering;
      _rx_delay_intrabit = table[i].rx_delay_intrabit;
      _rx_delay_stopbit = table[i].rx_delay_stopbit;
      _tx_delay = table[i].tx_delay;
      break;
    }
  }

  // Set up RX interrupts, but only if we have a valid RX baud rate
  if (_rx_delay_stopbit)
  {
    attachInterrupt(_receivePin, SoftwareSerial::handle_interrupt, FALLING);

    tunedDelay(_tx_delay); // if we were low this establishes the end
  }


  listen();
}

void SoftwareSerial::end()
{
  detachInterrupt(_receivePin);
}


// Read data from buffer
int SoftwareSerial::read()
{
  if (!isListening())
    return -1;

  // Empty buffer?
  if (_receive_buffer_head == _receive_buffer_tail)
    return -1;

  // Read from "head"
  uint8_t d = _receive_buffer[_receive_buffer_head]; // grab next byte
  _receive_buffer_head = (_receive_buffer_head + 1) % _SS_MAX_RX_BUFF;
  return d;
}

int SoftwareSerial::available()
{
  if (!isListening())
    return 0;

  return (_receive_buffer_tail + _SS_MAX_RX_BUFF - _receive_buffer_head) % _SS_MAX_RX_BUFF;
}

size_t SoftwareSerial::write(uint8_t b)
{
  if (_tx_delay == 0) {
    setWriteError();
    return 0;
  }

  //interrupts off
  uint8_t oldSR = __read_status_register();
  noInterrupts();

  // Write the start bit
  tx_pin_write(_inverse_logic ? HIGH : LOW);
  tunedDelay(_tx_delay + XMIT_START_ADJUSTMENT);

  // Write each of the 8 bits
  if (_inverse_logic)
  {
    for (byte mask = 0x01; mask; mask <<= 1)
    {
      if (b & mask) // choose bit
        tx_pin_write(LOW); // send 1
      else
        tx_pin_write(HIGH); // send 0

      tunedDelay(_tx_delay);
    }

    tx_pin_write(LOW); // restore pin to natural state
  }
  else
  {
    for (byte mask = 0x01; mask; mask <<= 1)
    {
      if (b & mask) // choose bit
        tx_pin_write(HIGH); // send 1
      else
        tx_pin_write(LOW); // send 0

      tunedDelay(_tx_delay);
    }

    tx_pin_write(HIGH); // restore pin to natural state
  }
  
  // turn interrupts back on if they were on before
  __write_status_register(oldSR);
  tunedDelay(_tx_delay);

  return 1;
}

void SoftwareSerial::flush()
{
  if (!isListening())
    return;

  uint8_t oldSR = __read_status_register();
  noInterrupts();
  _receive_buffer_head = _receive_buffer_tail = 0;
  __write_status_register(oldSR);
}

int SoftwareSerial::peek()
{
  if (!isListening())
    return -1;

  // Empty buffer?
  if (_receive_buffer_head == _receive_buffer_tail)
    return -1;

  // Read from "head"
  return _receive_buffer[_receive_buffer_head];
}

