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

// The extern PROGMEM versions of each of these is for runtime lookups,
// the static const versions are for lookups when the pin is known at compile time
// (see the below inline functions, and wiring_digital.c)
// Source of the pin mappings is pins_arduino.h

extern const uint16_t PROGMEM port_to_mode_P[];
static const uint16_t port_to_mode[] = { PORT_TO_MODE };

extern const uint16_t PROGMEM port_to_output_P[];
static const uint16_t port_to_output[] = { PORT_TO_OUTPUT };

extern const uint16_t PROGMEM port_to_input_P[];
static const uint16_t port_to_input[] = { PORT_TO_INPUT };

extern const uint8_t PROGMEM digital_pin_to_port_P[];
static const uint8_t digital_pin_to_port[] = { DIGITAL_PIN_TO_PORT };

extern const uint8_t PROGMEM digital_pin_to_bit_mask_P[];
static const uint8_t digital_pin_to_bit_mask[] = { DIGITAL_PIN_TO_BIT_MASK };

  extern const uint8_t PROGMEM digital_pin_to_timer_P[];
  static const uint8_t digital_pin_to_timer[] = { DIGITAL_PIN_TO_TIMER };

__attribute__((always_inline))
static inline uint8_t digitalPinToPort(uint8_t pin) {
  return __builtin_constant_p(pin) ? digital_pin_to_port[pin]
    : pgm_read_byte( digital_pin_to_port_P + pin );
}

/* These internal lookup functions will automatically resolve from the static const
 * tables if evaluated at compile time, or the PROGMEM tables if evaluated
 * at runtime:
 */

__attribute__((always_inline))
static inline volatile uint8_t *portOutputRegister(uint8_t port_idx) {
  return (volatile uint8_t *)( __builtin_constant_p(port_idx) ?
                               port_to_output[port_idx]
                               : pgm_read_word( port_to_output_P + port_idx) );
}

__attribute__((always_inline))
static inline volatile uint8_t *portDirectionRegister(uint8_t port_idx) {
  return (volatile uint8_t *)( __builtin_constant_p(port_idx) ?
                               port_to_mode[port_idx]
                               : pgm_read_word( port_to_mode_P + port_idx ) );
}

__attribute__((always_inline))
static inline volatile uint8_t *portInputRegister(uint8_t port_idx) {
  return (volatile uint8_t *)( __builtin_constant_p(port_idx) ?
                               port_to_input[port_idx]
                               : pgm_read_word( port_to_input_P + port_idx ) );
}

__attribute__((always_inline))
static inline uint8_t digitalPinToBitMask(uint8_t pin) {
  return __builtin_constant_p(pin) ? digital_pin_to_bit_mask[pin]
    : pgm_read_byte( digital_pin_to_bit_mask_P + pin );
}

__attribute__((always_inline))
static inline uint8_t digitalPinToTimer(uint8_t pin) {
  return __builtin_constant_p(pin) ? digital_pin_to_timer[pin]
    : pgm_read_byte( digital_pin_to_timer_P + pin );
}


/*
* Check if a given pin can be accessed in a single instruction.
*
* When accessing lower 32 IO ports we can use SBI/CBI instructions, which are atomic. However
* other IO ports require load+modify+store and we need to make them atomic by disabling
* interrupts.
*
* This routine only returns true if the port is known at compile time, because
* we'll be using memory mapped I/O regardless in the latter case.
*
* We test __builtin_constant_p on pin not port because testing the latter doesn't
* work in gcc 4.3.2, although gcc 4.3.2 does successfully optimise away the
* comparison...
*
*/
__attribute__((always_inline))
static inline int portIsAtomic(uint8_t pin, volatile uint8_t *port) {
  /* SBI/CBI instructions only work on lower 32 IO ports */
  return __builtin_constant_p(pin) && (uint16_t)port <= 0x1F + __SFR_OFFSET;
}


/*
 * The following functions (pinMode, digitalWrite, digitalRead,
 * turnOffPWM) all follow a pattern:
 *
 * _xxxxInline is a version of the function that is capable of being
 * inlined at compile time. Where the pin number is known at compile
 * time, this function can optimise down to the minimal number of
 * instructions possible. The function still works adequately even
 * if the pin number is not known at compile time.
 *
 * _xxxxRuntime is an extern version of the function suitable for
 * being called at runtime (for when the pin number is not known at
 * compile time.) The implementation is in wiring_digital.c, but it
 * actually just inlines _xxxxInline to provide the matching
 * non-inline implementation.
 *
 * 'xxxx' is the actual version of the function, which just chooses
 * between _xxxxInline (inlined) or _xxxxRuntime (called
 * conventionally) at compile time, based on whether the pin number is
 * known.
 *
 */

__attribute__((always_inline))
static inline void _pinModeInline(uint8_t pin, uint8_t mode) {
  const uint8_t port = digitalPinToPort(pin);
  volatile uint8_t *dir = portDirectionRegister(port);
  volatile uint8_t *out = portOutputRegister(port);
  const uint8_t bitmask = digitalPinToBitMask(pin);

  if (pin >= NUM_DIGITAL_PINS) return;

  // We can only do this without disabling interrupts if
  // both registers can use sbi/cbi
  const int is_atomic = portIsAtomic(pin, dir)
    && ((__builtin_constant_p(mode) && mode == OUTPUT) || portIsAtomic(pin, out));
  uint8_t oldSREG;

  if(!is_atomic) { // Resolves at compile time
    oldSREG = SREG;
    cli();
  }

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

  if(!is_atomic) // Resolves at compile time
    SREG = oldSREG;
}

void _pinModeRuntime(uint8_t, uint8_t);

__attribute__((always_inline))
static inline void pinMode(uint8_t pin, uint8_t mode) {
  // If we know the pin number, inline directly. Otherwise make a function call.
  if(__builtin_constant_p(pin))
    _pinModeInline(pin,mode);
  else
    _pinModeRuntime(pin,mode);
}


__attribute__((always_inline))
static inline void _turnOffPWMInline(uint8_t pin)
{
  const uint8_t timer = digitalPinToTimer(pin);
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

void _turnOffPWMRuntime(uint8_t pin);

__attribute__((always_inline))
static inline void turnOffPWM(const uint8_t pin) {
  if(__builtin_constant_p(pin))
    _turnOffPWMInline(pin);
  else
    _turnOffPWMRuntime(pin);
}

__attribute__((always_inline))
static inline void _digitalWriteInline(const uint8_t pin, const uint8_t value) {
  const uint8_t port = digitalPinToPort(pin);
  volatile uint8_t *out = portOutputRegister(port);
  const uint8_t bitmask = digitalPinToBitMask(pin);

  if (pin >= NUM_DIGITAL_PINS) return;

  turnOffPWM(pin);

  const int is_atomic = portIsAtomic(pin, out); // Resolves at compile time

  uint8_t oldSREG;
  if(!is_atomic) { // Resolves at compile time
    oldSREG = SREG;
    cli();
  }

  if(value)
    *out |= bitmask;
  else
    *out &= ~bitmask;

  if(!is_atomic) // Resolves at compile time
    SREG = oldSREG;
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
static inline int _digitalReadInline(uint8_t pin) {
  const uint8_t port = digitalPinToPort(pin);
  const volatile uint8_t *in = portInputRegister(port);
  const uint8_t bitmask = digitalPinToBitMask(pin);

  if (port == NOT_A_PIN) return LOW;
  if (pin >= NUM_DIGITAL_PINS) return LOW;

  turnOffPWM(pin);

  if (*in & bitmask) return HIGH;
  return LOW;
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


