/*
 * This header includes pins_arduino.h to get board-specific pin data,
 * then lays out the functions for inlining digital reads & writes based
 * on that pin data.
 */
#ifndef _PIN_FUNCTIONS_H
#define _PIN_FUNCTIONS_H

#ifdef __cplusplus
extern "C" {
#endif

#define NOT_A_PIN 0
#define NOT_A_PORT 0

#define NOT_ON_TIMER 0
#define TIMER0A 1
#define TIMER0B 2
#define TIMER1A 3
#define TIMER1B 4
#define TIMER2  5
#define TIMER2A 6
#define TIMER2B 7

#define TIMER3A 8
#define TIMER3B 9
#define TIMER3C 10
#define TIMER4A 11
#define TIMER4B 12
#define TIMER4C 13
#define TIMER4D 14
#define TIMER5A 15
#define TIMER5B 16
#define TIMER5C 17

#define PA 1
#define PB 2
#define PC 3
#define PD 4
#define PE 5
#define PF 6
#define PG 7
#define PH 8
#define PJ 10
#define PK 11
#define PL 12

#include "pins_arduino.h"

__attribute__((always_inline))
static inline uint8_t digitalPinToPort(uint8_t pin) {
  return digital_pin_to_port[pin];
}

__attribute__((always_inline))
static inline volatile uint8_t *portOutputRegister(uint8_t port_idx) {
  return (volatile uint8_t *)port_to_output[port_idx];
}

__attribute__((always_inline))
static inline volatile uint8_t *portDirectionRegister(uint8_t port_idx) {
  return (volatile uint8_t *)port_to_mode[port_idx];
}

__attribute__((always_inline))
static inline volatile uint8_t *portInputRegister(uint8_t port_idx) {
  return (volatile uint8_t *)port_to_input[port_idx];
}

__attribute__((always_inline))
static inline uint8_t digitalPinToBitMask(uint8_t pin) {
  return digital_pin_to_bit_mask[pin];
}

/*
* Check if a given pin can be accessed in a single instruction.
*
* When accessing lower 32 IO ports we can use SBI/CBI instructions, which are atomic. However
* other IO ports require load+modify+store and we need to make them atomic by disabling
* interrupts.
*/
__attribute__((always_inline))
static inline int portIsAtomic(volatile uint8_t *port) {
  /* SBI/CBI instructions only work on lower 32 IO ports */
  return port <= (volatile uint8_t*) & _SFR_IO8(0x1F);
}

__attribute__((always_inline))
static inline void _pinModeClause(uint8_t pin, uint8_t mode) {
  // At this point 'pin' is always known at compile time, 'mode' might be
  const uint8_t port = digital_pin_to_port[pin];
  volatile uint8_t *dir = portDirectionRegister(port);
  volatile uint8_t *out = portOutputRegister(port);
  const uint8_t bitmask = digital_pin_to_bit_mask[pin];

  if (pin >= NUM_DIGITAL_PINS) return;

  // We can only do this w/o disabling interrupts is if 'mode'
  // is known at compile time, the direction register can use sbi/cbi
  // & we're setting output...
  if(__builtin_constant_p(mode) && portIsAtomic(dir) && (mode == OUTPUT)) {
    *dir |= bitmask;
  }  else { // Otherwise, need to disable interrupts at minimum...
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
      if(mode == INPUT_PULLUP) {
        *out |= bitmask;
      } else if(mode == INPUT) {
        *out &= ~bitmask;
      }
      if(mode == INPUT_PULLUP || mode == INPUT) {
        *dir &= ~bitmask;
      } else {
        *dir |= bitmask;
      }
    }
  }
}
#define _PINMODECLAUSE(P) case P: _pinModeClause(P, mode); break

__attribute__((always_inline))
static inline void _pinModeInline(uint8_t pin, uint8_t mode) {
  switch(pin) {
    _PINMODECLAUSE(0);
    _PINMODECLAUSE(1);
    _PINMODECLAUSE(2);
    _PINMODECLAUSE(3);
    _PINMODECLAUSE(4);
    _PINMODECLAUSE(5);
    _PINMODECLAUSE(6);
    _PINMODECLAUSE(7);
    _PINMODECLAUSE(8);
    _PINMODECLAUSE(9);
    _PINMODECLAUSE(10);
    _PINMODECLAUSE(11);
    _PINMODECLAUSE(12);
    _PINMODECLAUSE(13);
    _PINMODECLAUSE(14);
    _PINMODECLAUSE(15);
    _PINMODECLAUSE(16);
    _PINMODECLAUSE(17);
    _PINMODECLAUSE(18);
    _PINMODECLAUSE(19);
    _PINMODECLAUSE(20);
    _PINMODECLAUSE(21);
    _PINMODECLAUSE(22);
    _PINMODECLAUSE(23);
    _PINMODECLAUSE(24);
    _PINMODECLAUSE(25);
    _PINMODECLAUSE(26);
    _PINMODECLAUSE(27);
    _PINMODECLAUSE(28);
    _PINMODECLAUSE(29);
    _PINMODECLAUSE(30);
    _PINMODECLAUSE(31);
    _PINMODECLAUSE(32);
    _PINMODECLAUSE(33);
    _PINMODECLAUSE(34);
    _PINMODECLAUSE(35);
    _PINMODECLAUSE(36);
    _PINMODECLAUSE(37);
    _PINMODECLAUSE(38);
    _PINMODECLAUSE(39);
    _PINMODECLAUSE(40);
    _PINMODECLAUSE(41);
    _PINMODECLAUSE(42);
    _PINMODECLAUSE(43);
    _PINMODECLAUSE(44);
    _PINMODECLAUSE(45);
    _PINMODECLAUSE(46);
    _PINMODECLAUSE(47);
    _PINMODECLAUSE(48);
    _PINMODECLAUSE(49);
    _PINMODECLAUSE(50);
    _PINMODECLAUSE(51);
    _PINMODECLAUSE(52);
    _PINMODECLAUSE(53);
    _PINMODECLAUSE(54);
    _PINMODECLAUSE(55);
    _PINMODECLAUSE(56);
    _PINMODECLAUSE(57);
    _PINMODECLAUSE(58);
    _PINMODECLAUSE(59);
    _PINMODECLAUSE(60);
    _PINMODECLAUSE(61);
    _PINMODECLAUSE(62);
    _PINMODECLAUSE(63);
    _PINMODECLAUSE(64);
    _PINMODECLAUSE(65);
    _PINMODECLAUSE(66);
    _PINMODECLAUSE(67);
    _PINMODECLAUSE(68);
    _PINMODECLAUSE(69);
  }
}

void pinModeRuntime(uint8_t, uint8_t);

__attribute__((always_inline))
static inline void pinMode(uint8_t pin, uint8_t mode) {
  // If we know the pin number, inline directly. Otherwise make a function call.
  if(__builtin_constant_p(pin))
    _pinModeInline(pin,mode);
  else
    pinModeRuntime(pin,mode);
}


__attribute__((always_inline))
static inline void turnOffPWM(uint8_t timer)
{
  // Timer should always be known at compile time here
  switch (timer)
    {
#if defined(TCCR1A) && defined(COM1A1)
    case TIMER1A:   TCCR1A &= ~_BV(COM1A1);    break;
#endif
#if defined(TCCR1A) && defined(COM1B1)
    case TIMER1B:   TCCR1A &= ~_BV(COM1B1);    break;
#endif

#if defined(TCCR2) && defined(COM21)
    case  TIMER2:   TCCR2 &= ~_BV(COM21);      break;
#endif

#if defined(TCCR0A) && defined(COM0A1)
    case  TIMER0A:  TCCR0A &= ~_BV(COM0A1);    break;
#endif

#if defined(TIMER0B) && defined(COM0B1)
    case  TIMER0B:  TCCR0A &= ~_BV(COM0B1);    break;
#endif
#if defined(TCCR2A) && defined(COM2A1)
    case  TIMER2A:  TCCR2A &= ~_BV(COM2A1);    break;
#endif
#if defined(TCCR2A) && defined(COM2B1)
    case  TIMER2B:  TCCR2A &= ~_BV(COM2B1);    break;
#endif

#if defined(TCCR3A) && defined(COM3A1)
    case  TIMER3A:  TCCR3A &= ~_BV(COM3A1);    break;
#endif
#if defined(TCCR3A) && defined(COM3B1)
    case  TIMER3B:  TCCR3A &= ~_BV(COM3B1);    break;
#endif
#if defined(TCCR3A) && defined(COM3C1)
    case  TIMER3C:  TCCR3A &= ~_BV(COM3C1);    break;
#endif

#if defined(TCCR4A) && defined(COM4A1)
    case  TIMER4A:  TCCR4A &= ~_BV(COM4A1);    break;
#endif
#if defined(TCCR4A) && defined(COM4B1)
    case  TIMER4B:  TCCR4A &= ~_BV(COM4B1);    break;
#endif
#if defined(TCCR4A) && defined(COM4C1)
    case  TIMER4C:  TCCR4A &= ~_BV(COM4C1);    break;
#endif
#if defined(TCCR4C) && defined(COM4D1)
    case TIMER4D:	TCCR4C &= ~_BV(COM4D1);	break;
#endif

#if defined(TCCR5A)
    case  TIMER5A:  TCCR5A &= ~_BV(COM5A1);    break;
    case  TIMER5B:  TCCR5A &= ~_BV(COM5B1);    break;
    case  TIMER5C:  TCCR5A &= ~_BV(COM5C1);    break;
#endif
    }
}


__attribute__((always_inline))
static inline void _digitalWriteClause(uint8_t pin, uint8_t value) {
  // At this point 'pin' is always known at compile time, 'value' might be
  const uint8_t port = digital_pin_to_port[pin];
  volatile uint8_t *out = portOutputRegister(port);
  const uint8_t bitmask = digital_pin_to_bit_mask[pin];
  const uint8_t timer = digital_pin_to_timer[pin];

  if (pin >= NUM_DIGITAL_PINS) return;

  turnOffPWM(timer);

  if(portIsAtomic(out)) {
    // Output is a single instruction write
    if(value)
      *out |= bitmask;
    else
      *out &= ~bitmask;
  }
  else {
    // Output is non-atomic
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
    if(value)
      *out |= bitmask;
    else
      *out &= ~bitmask;
    }
  }
}
#define _DIGITALWRITECLAUSE(P) case P: _digitalWriteClause(P, value); break

__attribute__((always_inline))
static inline void _digitalWriteInline(const uint8_t pin, const uint8_t value) {
  switch(pin) {
    _DIGITALWRITECLAUSE(0);
    _DIGITALWRITECLAUSE(1);
    _DIGITALWRITECLAUSE(2);
    _DIGITALWRITECLAUSE(3);
    _DIGITALWRITECLAUSE(4);
    _DIGITALWRITECLAUSE(5);
    _DIGITALWRITECLAUSE(6);
    _DIGITALWRITECLAUSE(7);
    _DIGITALWRITECLAUSE(8);
    _DIGITALWRITECLAUSE(9);
    _DIGITALWRITECLAUSE(10);
    _DIGITALWRITECLAUSE(11);
    _DIGITALWRITECLAUSE(12);
    _DIGITALWRITECLAUSE(13);
    _DIGITALWRITECLAUSE(14);
    _DIGITALWRITECLAUSE(15);
    _DIGITALWRITECLAUSE(16);
    _DIGITALWRITECLAUSE(17);
    _DIGITALWRITECLAUSE(18);
    _DIGITALWRITECLAUSE(19);
    _DIGITALWRITECLAUSE(20);
    _DIGITALWRITECLAUSE(21);
    _DIGITALWRITECLAUSE(22);
    _DIGITALWRITECLAUSE(23);
    _DIGITALWRITECLAUSE(24);
    _DIGITALWRITECLAUSE(25);
    _DIGITALWRITECLAUSE(26);
    _DIGITALWRITECLAUSE(27);
    _DIGITALWRITECLAUSE(28);
    _DIGITALWRITECLAUSE(29);
    _DIGITALWRITECLAUSE(30);
    _DIGITALWRITECLAUSE(31);
    _DIGITALWRITECLAUSE(32);
    _DIGITALWRITECLAUSE(33);
    _DIGITALWRITECLAUSE(34);
    _DIGITALWRITECLAUSE(35);
    _DIGITALWRITECLAUSE(36);
    _DIGITALWRITECLAUSE(37);
    _DIGITALWRITECLAUSE(38);
    _DIGITALWRITECLAUSE(39);
    _DIGITALWRITECLAUSE(40);
    _DIGITALWRITECLAUSE(41);
    _DIGITALWRITECLAUSE(42);
    _DIGITALWRITECLAUSE(43);
    _DIGITALWRITECLAUSE(44);
    _DIGITALWRITECLAUSE(45);
    _DIGITALWRITECLAUSE(46);
    _DIGITALWRITECLAUSE(47);
    _DIGITALWRITECLAUSE(48);
    _DIGITALWRITECLAUSE(49);
    _DIGITALWRITECLAUSE(50);
    _DIGITALWRITECLAUSE(51);
    _DIGITALWRITECLAUSE(52);
    _DIGITALWRITECLAUSE(53);
    _DIGITALWRITECLAUSE(54);
    _DIGITALWRITECLAUSE(55);
    _DIGITALWRITECLAUSE(56);
    _DIGITALWRITECLAUSE(57);
    _DIGITALWRITECLAUSE(58);
    _DIGITALWRITECLAUSE(59);
    _DIGITALWRITECLAUSE(60);
    _DIGITALWRITECLAUSE(61);
    _DIGITALWRITECLAUSE(62);
    _DIGITALWRITECLAUSE(63);
    _DIGITALWRITECLAUSE(64);
    _DIGITALWRITECLAUSE(65);
    _DIGITALWRITECLAUSE(66);
    _DIGITALWRITECLAUSE(67);
    _DIGITALWRITECLAUSE(68);
    _DIGITALWRITECLAUSE(69);
  }
}

void _digitalWriteRuntime(uint8_t, uint8_t);

__attribute__((always_inline))
static inline void digitalWrite(uint8_t pin, uint8_t value) {
  // If we know the pin number, inline directly. Otherwise make a function call.
  if(__builtin_constant_p(pin))
    _digitalWriteInline(pin,value);
  else
    _digitalWriteRuntime(pin,value);
}


__attribute__((always_inline))
static inline uint8_t _digitalReadClause(uint8_t pin) {
  // At this point 'pin' is always known at compile time
  const uint8_t port = digital_pin_to_port[pin];
  const volatile uint8_t *in = portInputRegister(port);
  const uint8_t bitmask = digital_pin_to_bit_mask[pin];
  const uint8_t timer = digital_pin_to_timer[pin];

  if (port == NOT_A_PIN) return LOW;
  if (pin >= NUM_DIGITAL_PINS) return LOW;

  turnOffPWM(timer);

  if (*in & bitmask) return HIGH;
  return LOW;
}
#define _DIGITALREADCLAUSE(P) case P: return _digitalReadClause(P);

__attribute__((always_inline))
static inline int _digitalReadInline(uint8_t pin) {
  switch(pin) {
    _DIGITALREADCLAUSE(0);
    _DIGITALREADCLAUSE(1);
    _DIGITALREADCLAUSE(2);
    _DIGITALREADCLAUSE(3);
    _DIGITALREADCLAUSE(4);
    _DIGITALREADCLAUSE(5);
    _DIGITALREADCLAUSE(6);
    _DIGITALREADCLAUSE(7);
    _DIGITALREADCLAUSE(8);
    _DIGITALREADCLAUSE(9);
    _DIGITALREADCLAUSE(10);
    _DIGITALREADCLAUSE(11);
    _DIGITALREADCLAUSE(12);
    _DIGITALREADCLAUSE(13);
    _DIGITALREADCLAUSE(14);
    _DIGITALREADCLAUSE(15);
    _DIGITALREADCLAUSE(16);
    _DIGITALREADCLAUSE(17);
    _DIGITALREADCLAUSE(18);
    _DIGITALREADCLAUSE(19);
    _DIGITALREADCLAUSE(20);
    _DIGITALREADCLAUSE(21);
    _DIGITALREADCLAUSE(22);
    _DIGITALREADCLAUSE(23);
    _DIGITALREADCLAUSE(24);
    _DIGITALREADCLAUSE(25);
    _DIGITALREADCLAUSE(26);
    _DIGITALREADCLAUSE(27);
    _DIGITALREADCLAUSE(28);
    _DIGITALREADCLAUSE(29);
    _DIGITALREADCLAUSE(30);
    _DIGITALREADCLAUSE(31);
    _DIGITALREADCLAUSE(32);
    _DIGITALREADCLAUSE(33);
    _DIGITALREADCLAUSE(34);
    _DIGITALREADCLAUSE(35);
    _DIGITALREADCLAUSE(36);
    _DIGITALREADCLAUSE(37);
    _DIGITALREADCLAUSE(38);
    _DIGITALREADCLAUSE(39);
    _DIGITALREADCLAUSE(40);
    _DIGITALREADCLAUSE(41);
    _DIGITALREADCLAUSE(42);
    _DIGITALREADCLAUSE(43);
    _DIGITALREADCLAUSE(44);
    _DIGITALREADCLAUSE(45);
    _DIGITALREADCLAUSE(46);
    _DIGITALREADCLAUSE(47);
    _DIGITALREADCLAUSE(48);
    _DIGITALREADCLAUSE(49);
    _DIGITALREADCLAUSE(50);
    _DIGITALREADCLAUSE(51);
    _DIGITALREADCLAUSE(52);
    _DIGITALREADCLAUSE(53);
    _DIGITALREADCLAUSE(54);
    _DIGITALREADCLAUSE(55);
    _DIGITALREADCLAUSE(56);
    _DIGITALREADCLAUSE(57);
    _DIGITALREADCLAUSE(58);
    _DIGITALREADCLAUSE(59);
    _DIGITALREADCLAUSE(60);
    _DIGITALREADCLAUSE(61);
    _DIGITALREADCLAUSE(62);
    _DIGITALREADCLAUSE(63);
    _DIGITALREADCLAUSE(64);
    _DIGITALREADCLAUSE(65);
    _DIGITALREADCLAUSE(66);
    _DIGITALREADCLAUSE(67);
    _DIGITALREADCLAUSE(68);
    _DIGITALREADCLAUSE(69);
  }
}

int _digitalReadRuntime(uint8_t);

__attribute__((always_inline))
static inline int digitalRead(uint8_t pin) {
  // If we know the pin number, inline directly. Otherwise make a function call.
  if(__builtin_constant_p(pin))
    return _digitalReadInline(pin);
  else
    return _digitalReadRuntime(pin);
}

#ifdef __cplusplus
}
#endif
#endif


