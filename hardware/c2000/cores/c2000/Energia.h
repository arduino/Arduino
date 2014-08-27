#ifndef Energia_h
#define Energia_h

#ifdef __cplusplus
typedef unsigned char _Bool;
#endif

#ifdef TMS320F28027
#include <F2802x_Device.h>
#include "f2802x_common/include/F2802x_DefaultISR.h"
#elif defined(TMS320F28069)
#include <F2806x_Device.h>
#include "F2806x_common/include/F2806x_DefaultISR.h"
#endif
#include <stdint.h>
#include <string.h>
#include <math.h>

#include "binary.h"

#ifdef __cplusplus
extern "C"{
#endif

#define NOT_A_PIN 0
//#define NOT_ON_TIMER 0

#define HIGH 0x1
#define LOW  0x0

#define LSBFIRST 0
#define MSBFIRST 1

#define FALLING 0
#define RISING 1
#define CHANGE 3

#define INPUT 0x0
#define OUTPUT 0x1
#define INPUT_PULLUP 0x2
#define HARDWARE 0x4
#define PORT_SELECTION0 0x10
#define PORT_SELECTION1 0x20

#define PI 3.1415926535897932384626433832795
#define HALF_PI 1.5707963267948966192313216916398
#define TWO_PI 6.283185307179586476925286766559
#define DEG_TO_RAD 0.017453292519943295769236907684886
#define RAD_TO_DEG 57.295779513082320876798154814105

//AVR defines these...added for compatibility
#define M_PI 3.141592653589793238462643
#define M_SQRT2 1.4142135623730950488016887

enum{
  NOT_ON_TIMER,
  PWM1A,
  PWM1B,
  PWM2A,
  PWM2B,
  PWM3A,
  PWM3B,
  PWM4A,
  PWM4B,
  PWM5A,
  PWM5B,
  PWM6A,
  PWM6B,
  PWM7A,
  PWM7B,
  PWM8A,
  PWM8B
  };

enum{
	NOT_A_PORT=0,
	PORT_A_1,
	PORT_A_2,
	PORT_B_1,
  PORT_B_2
};

// The following pointer to a function call calibrates the ADC and internal oscillators
#define Device_cal (void   (*)(void))0x3D7C80

// DO NOT MODIFY THIS LINE.
//#define DELAY_US(A)  DSP28x_usDelay((unsigned long)((((long double) A * 1000.0L) / (long double)(1000000000L/F_CPU)) - 9.0L) / 5.0L)
#ifdef TMS320F28027
#define DELAY_US(A)  DSP28x_usDelay((uint32_t)((((long double) A * 1000.0L) / (long double)16.667L) - 9.0L) / 5.0L)
#elif defined(TMS320F28069)
#define DELAY_US(A)  DSP28x_usDelay((uint32_t)((((long double) A * 1000.0L) / (long double)11.111L) - 9.0L) / 5.0L)
#endif

// These are defined by the linker (see F2808.cmd)
extern void* RamfuncsLoadStart;
extern void* RamfuncsLoadSize;
extern void* RamfuncsRunStart;



typedef uint8_t boolean;
typedef uint8_t byte;

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))
#define round(x)     ((x)>=0?(long)((x)+0.5):(long)((x)-0.5))
#define radians(deg) ((deg)*DEG_TO_RAD)
#define degrees(rad) ((rad)*RAD_TO_DEG)
#define sq(x) ((x)*(x))

#define interrupts() EINT
#define noInterrupts() DINT

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
void pinMode_int(uint8_t, uint8_t);
void digitalWrite(uint8_t, uint8_t);
int digitalRead(uint8_t);
uint16_t analogRead(uint8_t);
void analogWrite(uint8_t, int);
void analogReference(uint16_t);
void analogFrequency(uint32_t);
void analogResolution(uint16_t);



void delay(uint32_t milliseconds);

void attachInterrupt(uint8_t pin, uint8_t interruptNum, void (*userFunc)(void), int mode);
void detachInterrupt(uint8_t interruptNum);

extern const uint32_t digital_pin_to_timer[];
extern const uint32_t digital_pin_to_port[];
extern const uint32_t digital_pin_to_bit_mask[];
//extern const uint16_t port_to_sel0[];
//extern const uint16_t port_to_sel1[];
//extern const uint16_t port_to_sel2[];
extern const uint32_t* port_to_input[];
extern const uint32_t* port_to_output[];

#define digitalPinToPort(P)    ( digital_pin_to_port[P] )
#define digitalPinToBitMask(P) ( digital_pin_to_bit_mask[P] )
#define digitalPinToTimer(P)   ( digital_pin_to_timer[P] )
#define portDirRegister(P)     ( (volatile uint32_t *)( port_to_dir[P]) )
/* 
 * We either of the compination   PxSEL and PxSEL2   or   PxSEL0 and PxSEL1
 * So we can remap  PxSEL and PxSEL2   to   PxSEL0 and PxSEL1
*/ 
#define portSelRegister(P)     ( (volatile uint32_t *)( port_to_sel[P]) )
#define portSel2Register(P)    ( (volatile uint32_t *)( port_to_sel2[P]) )

#define portSel0Register(P)    ( (volatile uint32_t *)( port_to_sel0[P]) )
#define portSel1Register(P)    ( (volatile uint32_t *)( port_to_sel1[P]) )
#define portRenRegister(P)     ( (volatile uint32_t *)( port_to_ren[P]) )
#define portOutputRegister(P)  ( (volatile uint32_t *)( port_to_output[P]) )
#define portPullupRegister(P)  ( (volatile uint32_t *)( port_to_pullup[P]) )
#define portInputRegister(P)   ( (volatile uint32_t *)( port_to_input[P]) )
#define digitalPinToTimer(P)   ( digital_pin_to_timer[P] )

// Implemented in wiring.c
void delayMicroseconds(uint32_t us);
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
//#if defined(__MSP430_HAS_USCI__) || defined(__MSP430_HAS_EUSCI_A0__)
#include "HardwareSerial.h"
//#else
//#include "TimerSerial.h"
//#include "Wire.h"
//#endif

uint16_t makeWord(uint16_t w);
uint16_t makeWord(byte h, byte l);

#define word(...) makeWord(__VA_ARGS__)

unsigned long pulseIn(uint8_t pin, uint8_t state, unsigned long timeout = 1000000L);

void tone(uint8_t _pin, unsigned int frequency, unsigned long duration = 0);
void noTone(uint8_t _pin);

void timer( unsigned int frequency, void (*userFunc)(void));
void inline stopTimer(void);

// WMath prototypes
long random(long);
long random(long, long);
void randomSeed(unsigned int);
long map(long, long, long, long, long);

#endif

#include "pins_energia.h"

#endif


