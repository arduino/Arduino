#ifndef Energia_h
#define Energia_h

#include <msp430.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include "binary.h"
#include <avr/dtostrf.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>

#ifdef __cplusplus
extern "C"{
#endif

#define NOT_A_PORT 0
#define NOT_A_PIN 0
#define NOT_ON_TIMER 0
#define NOT_ON_ADC 0xFF

#define HIGH 0x1
#define LOW  0x0

#define LSBFIRST 0
#define MSBFIRST 1

#define RISING 0
#define FALLING 1
#define CHANGE 2

#define INPUT 0x0
#define OUTPUT 0x1
#define INPUT_PULLUP 0x2
#define INPUT_PULLDOWN 0x4
#define PORT_SELECTION0 0x10
#define PORT_SELECTION1 0x20


#define true 0x1
#define false 0x0

#define PI 3.1415926535897932384626433832795
#define HALF_PI 1.5707963267948966192313216916398
#define TWO_PI 6.283185307179586476925286766559
#define DEG_TO_RAD 0.017453292519943295769236907684886
#define RAD_TO_DEG 57.295779513082320876798154814105

#if defined(__MSP430_HAS_ADC10__)
#define DEFAULT SREF_0
#define INTERNAL1V5 (SREF_1 | REFON)
#define INTERNAL2V5 (SREF_1 | REFON | REF2_5V)
#define EXTERNAL SREF_2
#endif

#if defined(__MSP430_HAS_ADC10_B__)
#define DEFAULT ADC10SREF_0
#define INTERNAL1V5 (ADC10SREF_1 | REFON | REFVSEL_0)
#define INTERNAL2V5 (ADC10SREF_1 | REFON | REFVSEL_2)
#define EXTERNAL ADC10SREF_2
#endif

#if defined(__MSP430_HAS_ADC12_PLUS__)
#define DEFAULT (ADC12SREF_0 << 4)
#define INTERNAL1V5 ((ADC12SREF_1 << 4) | REFON | REFMSTR | REFVSEL_0)
#define INTERNAL2V0 ((ADC12SREF_1 << 4) | REFON | REFMSTR | REFVSEL_1)
#define INTERNAL2V5 ((ADC12SREF_1 << 4) | REFON | REFMSTR | REFVSEL_2)
#define EXTERNAL (ADC12SREF_2 << 4)
#endif

#if defined(__MSP430_HAS_ADC12_B__)
#define DEFAULT ADC12VRSEL_0
#define INTERNAL1V2 (ADC12VRSEL_1 | REFON | REFVSEL_0)
#define INTERNAL2V0 (ADC12VRSEL_1 | REFON | REFVSEL_1)
#define INTERNAL2V5 (ADC12VRSEL_1 | REFON | REFVSEL_2)
#define EXTERNAL ADC12VRSEL_2
#endif

#if defined(__MSP430_HAS_ADC__)
#define DEFAULT ADCSREF_0
#define INTERNAL1V5 (ADCSREF_1)
#define EXTERNAL ADCSREF_2
#endif

enum{
  P1 = 1,
  P2,
#ifdef __MSP430_HAS_PORT3_R__
  P3,
#endif
#ifdef __MSP430_HAS_PORT4_R__
  P4,
#endif
#ifdef __MSP430_HAS_PORT5_R__
  P5,
#endif
#ifdef __MSP430_HAS_PORT6_R__
  P6,
#endif
#ifdef __MSP430_HAS_PORT7_R__
  P7,
#endif
#ifdef __MSP430_HAS_PORT8_R__
  P8,
#endif
#ifdef __MSP430_HAS_PORT9_R__
  P9,
#endif
#ifdef __MSP430_HAS_PORT10_R__
  P10,
#endif
#ifdef __MSP430_HAS_PORT11_R__
  P11,
#endif
#ifdef __MSP430_HAS_PORT12_R__
  P12,
#endif
#ifdef __MSP430_HAS_PORTJ_R__
  PJ,
#endif
  };

enum{
  T0A0,     // here starts the enum for Timer pins
  T0A1,     // mapped with PxSEL0
  T0A2,
  T0A3,
  T0A4,
  T1A0,
  T1A1,
  T1A2,
  T1A3,
  T1A4,
  T1A5,
  T2A0,
  T2A1,
  T2A2,
  T0B0,
  T0B1,
  T0B2,
  T0B3,
  T0B4,
  T0B5,
  T0B6,
  T1B0,
  T1B1,
  T1B2,
  T2B0,
  T2B1,
  T2B2,
  T0A0_SEL1,  // here starts the enum for Timer pins
  T0A1_SEL1,  // mapped with PxSEL1
  T0A2_SEL1,
  T0A3_SEL1,
  T0A4_SEL1,
  T1A0_SEL1,
  T1A1_SEL1,
  T1A2_SEL1,
  T1A3_SEL1,
  T1A4_SEL1,
  T1A5_SEL1,
  T2A0_SEL1,
  T2A1_SEL1,
  T2A2_SEL1,
  T0B0_SEL1,
  T0B1_SEL1,
  T0B2_SEL1,
  T0B3_SEL1,
  T0B4_SEL1,
  T0B5_SEL1,
  T0B6_SEL1,
  T1B0_SEL1,
  T1B1_SEL1,
  T1B2_SEL1,
  T2B0_SEL1,
  T2B1_SEL1,
  T2B2_SEL1,
  T0A0_SEL01,  // here starts the enum for Timer pins
  T0A1_SEL01,  // mapped with PxSEL0 and PxSEL1
  T0A2_SEL01,
  T0A3_SEL01,
  T0A4_SEL01,
  T1A0_SEL01,
  T1A1_SEL01,
  T1A2_SEL01,
  T1A3_SEL01,
  T1A4_SEL01,
  T1A5_SEL01,
  T2A0_SEL01,
  T2A1_SEL01,
  T2A2_SEL01,
  T0B0_SEL01,
  T0B1_SEL01,
  T0B2_SEL01,
  T0B3_SEL01,
  T0B4_SEL01,
  T0B5_SEL01,
  T0B6_SEL01,
  T1B0_SEL01,
  T1B1_SEL01,
  T1B2_SEL01,
  T2B0_SEL01,
  T2B1_SEL01,
  T2B2_SEL01
  };

typedef uint8_t boolean;
typedef uint8_t byte;

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))
#define round(x)     ((x)>=0?(long)((x)+0.5):(long)((x)-0.5))
#define radians(deg) ((deg)*DEG_TO_RAD)
#define degrees(rad) ((rad)*RAD_TO_DEG)
#define sq(x) ((x)*(x))

#define interrupts() __bis_SR_register(GIE)
#define noInterrupts() __bic_SR_register(GIE)

#define clockCyclesPerMicrosecond() ( F_CPU / 1000000L )
#define clockCyclesToMicroseconds(a) ( (a) / clockCyclesPerMicrosecond() )
#define microsecondsToClockCycles(a) ( (a) * clockCyclesPerMicrosecond() )

#define lowByte(w) ((uint8_t) ((w) & 0xff))
#define highByte(w) ((uint8_t) ((w) >> 8))

#define bitRead(value, bit) (((value) >> (bit)) & 0x01)
#define bitSet(value, bit) ((value) |= (1UL << (bit)))
#define bitClear(value, bit) ((value) &= ~(1UL << (bit)))
#define bitWrite(value, bit, bitvalue) (bitvalue ? bitSet(value, bit) : bitClear(value, bit))


typedef unsigned int word;

#define bit(b) (1UL << (b))

void init(void);
void setup(void);
void loop(void);

void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t val);
uint8_t shiftIn(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder);
unsigned long pulseIn(uint8_t pin, uint8_t state, unsigned long timeout);
void pinMode(uint8_t, uint8_t);
void pinMode_int(uint8_t, uint16_t);
void digitalWrite(uint8_t, uint8_t);
int digitalRead(uint8_t);
void analogReadResolution(int res);
uint16_t analogRead(uint8_t);
void analogWrite(uint8_t, int);
void analogReference(uint16_t);
void analogFrequency(uint32_t);
void analogResolution(uint16_t);



void delay(uint32_t milliseconds);
void sleep(uint32_t milliseconds);
void sleepSeconds(uint32_t seconds);
void suspend(void);
extern volatile boolean stay_asleep;
#define wakeup() { stay_asleep = false; }

void attachInterrupt(uint8_t, void (*)(void), int mode);
void detachInterrupt(uint8_t);

extern const uint8_t digital_pin_to_timer[];
extern const uint8_t digital_pin_to_port[];
extern const uint8_t digital_pin_to_bit_mask[];
extern const uint16_t port_to_sel0[];
extern const uint16_t port_to_sel1[];
extern const uint16_t port_to_sel2[];
extern const uint16_t port_to_input[];
extern const uint16_t port_to_output[];
extern const uint16_t port_to_ren[];
extern const uint16_t port_to_pmap[];
extern const uint32_t digital_pin_to_analog_in[];

#define digitalPinToPort(P)    ( digital_pin_to_port[P] )
#define digitalPinToBitMask(P) ( digital_pin_to_bit_mask[P] )
#define digitalPinToTimer(P)   ( digital_pin_to_timer[P] )
#define digitalPinToADCIn(P)      ( digital_pin_to_analog_in[P] )
#define portDirRegister(P)     ( (volatile uint8_t *)( port_to_dir[P]) )
/*
 * We either of the compination   PxSEL and PxSEL2   or   PxSEL0 and PxSEL1
 * So we can remap  PxSEL and PxSEL2   to   PxSEL0 and PxSEL1
*/
#define portSelRegister(P)     ( (volatile uint8_t *)( port_to_sel0[P]) )
#define portSel2Register(P)    ( (volatile uint8_t *)( port_to_sel2[P]) )

#define portSel0Register(P)    ( (volatile uint8_t *)( port_to_sel0[P]) )
#define portSel1Register(P)    ( (volatile uint8_t *)( port_to_sel1[P]) )
#define portRenRegister(P)     ( (volatile uint8_t *)( port_to_ren[P]) )
#define portOutputRegister(P)  ( (volatile uint8_t *)( port_to_output[P]) )
#define portInputRegister(P)   ( (volatile uint8_t *)( port_to_input[P]) )
#define portPMReg(P)           ( (volatile uint8_t *)( port_to_pmap[P]) )
#define digitalPinToTimer(P)   ( digital_pin_to_timer[P] )

// Implemented in wiring.c
void delayMicroseconds(unsigned int us);
unsigned long micros();
unsigned long millis();
void disableWatchDog();
void enableWatchDog();

#ifdef __cplusplus
} // extern "C"
#endif

#ifdef __cplusplus
#include "WCharacter.h"
#include "WString.h"
#if defined(__MSP430_HAS_USCI__) || defined(__MSP430_HAS_USCI_A0__) || defined(__MSP430_HAS_USCI_A1__) || defined(__MSP430_HAS_EUSCI_A0__)
#include "HardwareSerial.h"
#else
#include "TimerSerial.h"
#endif

uint16_t makeWord(uint16_t w);
uint16_t makeWord(byte h, byte l);

#define word(...) makeWord(__VA_ARGS__)

unsigned long pulseIn(uint8_t pin, uint8_t state, unsigned long timeout = 1000000L);

void tone(uint8_t _pin, unsigned int frequency, unsigned long duration = 0);
void noTone(uint8_t _pin);

// WMath prototypes
long random(long);
long random(long, long);
void randomSeed(unsigned int);
long map(long, long, long, long, long);

#endif

#include "pins_energia.h"

#endif


