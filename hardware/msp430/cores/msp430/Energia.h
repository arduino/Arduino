#ifndef Energia_h
#define Energia_h

#include  "msp430.h"
#include <stdint.h>
#include <string.h>
#include <math.h>

#ifdef __cplusplus
extern "C"{
#endif

#define NOT_A_PORT 0
#define NOT_A_PIN 0
#define NOT_ON_TIMER 0

#define HIGH 0x1
#define LOW  0x0

#define FALLING 1
#define RISING 0

#define INPUT 0x0
#define OUTPUT 0x1

#define true 0x1
#define false 0x0

#define PI 3.1415926535897932384626433832795
#define HALF_PI 1.5707963267948966192313216916398
#define TWO_PI 6.283185307179586476925286766559
#define DEG_TO_RAD 0.017453292519943295769236907684886
#define RAD_TO_DEG 57.295779513082320876798154814105

#if defined(__MSP430_HAS_ADC10__)
#define DEFAULT SREF_0
#define INTERNAL1V5 SREF_1 + REFON
#define INTERNAL2V5 SREF_1 + REFON + REF2_5V
#define EXTERNAL SREF_2
#endif

#define P1 1
#define P2 2
#define P3 3
#define P4 4
#define P5 5
#define P6 6
#define P7 7

#define T0A0 0
#define T0A1 1
#define T0A2 2
#define T1A0 3
#define T1A1 4
#define T1A2 5
#define T1A3 6
#define T1A4 7
#define T1A5 8
#define T2A0 9
#define T2A1 10
#define T2A1 11

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

void pinMode(uint8_t, uint8_t);
void digitalWrite(uint8_t, uint8_t);
int digitalRead(uint8_t);
uint16_t analogRead(uint8_t);
void analogWrite(uint8_t, int);
void analogReference(uint16_t);

void delay(uint32_t milliseconds);

void attachInterrupt(uint8_t, void (*)(void), int mode);
void detachInterrupt(uint8_t);

extern const uint8_t digital_pin_to_timer[];
extern const uint8_t digital_pin_to_port[];
extern const uint8_t digital_pin_to_bit_mask[];
extern const uint16_t port_to_sel[];
extern const uint16_t port_to_sel2[];

#define digitalPinToPort(P) ( digital_pin_to_port[P] )
#define digitalPinToBitMask(P) ( digital_pin_to_bit_mask[P] )
#define digitalPinToTimer(P) ( digital_pin_to_timer[P] )
#define portDirRegister(P) ( (volatile uint16_t *)( port_to_dir[P]) )
#define portSelRegister(P) ( (volatile uint16_t *)( port_to_sel[P]) )
#define portSel2Register(P) ( (volatile uint16_t *)( port_to_sel2[P]) )
#define portOutputRegister(P) ( (volatile uint16_t *)( port_to_output[P]) )
#define portInputRegister(P) ( (volatile uint16_t *)( port_to_input[P]) )
#define digitalPinToTimer(P) ( digital_pin_to_timer[P] )

// Implemented in wiring.c
void delayMicroseconds(unsigned int us);
unsigned long millis();

#ifdef __cplusplus
} // extern "C"
#endif

#ifdef __cplusplus
#include "WCharacter.h"
#include "WString.h"
#include "HardwareSerial.h"

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

#include "pins_arduino.h"

#endif


