#ifndef Energia_h
#define Energia_h

#include <stdint.h>
#include <string.h>
#include <math.h>

#include "binary.h"

#ifdef __cplusplus
extern "C"{
#endif

#define NOT_A_PORT 0
#define NOT_A_PIN 0
#define NOT_ON_TIMER 0

#define HIGH 0x1
#define LOW  0x0

#define LSBFIRST 0
#define MSBFIRST 1

#define FALLING 1
#define RISING 0

#define INPUT 0x0
#define OUTPUT 0x1
#define INPUT_PULLUP 0x2
#define INPUT_PULLDOWN 0x3

#define true 0x1
#define false 0x0

#define PI 3.1415926535897932384626433832795
#define HALF_PI 1.5707963267948966192313216916398
#define TWO_PI 6.283185307179586476925286766559
#define DEG_TO_RAD 0.017453292519943295769236907684886
#define RAD_TO_DEG 57.295779513082320876798154814105

/*#if defined(__MSP430_HAS_ADC10__)//voltage references
#define DEFAULT SREF_0
#define INTERNAL1V5 SREF_1 + REFON
#define INTERNAL2V5 SREF_1 + REFON + REF2_5V
#define EXTERNAL SREF_2
#endif*/

#define PA 1
#define PB 2
#define PC 3
#define PD 4
#define PE 5
#define PF 6

/*RGRNOTE: Not sure if it should be this format
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
#define T2A2 11
*/

#define T0CCP0 0
#define T0CCP1 1
#define T1CCP0 2
#define T1CCP1 3
#define T2CCP0 4
#define T2CCP1 5
#define T3CCP0 6
#define T3CCP1 7
#define T4CCP0 8
#define T4CCP1 9
#define T5CCP0 10
#define T5CCP1 11
#define WT0CCP0 12
#define WT0CCP1 13
#define WT1CCP0 14
#define WT1CCP1 15
#define WT2CCP0 16
#define WT2CCP1 17
#define WT3CCP0 18
#define WT3CCP1 19
#define WT4CCP0 20
#define WT4CCP1 21
#define WT5CCP0 22
#define WT5CCP1 23

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
void digitalWrite(uint8_t, uint8_t);
int digitalRead(uint8_t);
uint16_t analogRead(uint8_t);
void analogWrite(uint8_t, int);
void analogReference(uint16_t);
void analogFrequency(uint32_t);
void analogResolution(uint16_t);



void delay(uint32_t milliseconds);

void attachInterrupt(uint8_t, void (*)(void), int mode);
void detachInterrupt(uint8_t);

extern const uint8_t digital_pin_to_timer[];
extern const uint8_t digital_pin_to_port[];
extern const uint8_t digital_pin_to_bit_mask[];
extern const uint32_t port_to_afsel[];
extern const uint32_t port_to_input[];
extern const uint32_t port_to_output[];
extern const uint32_t port_to_base[];
#define digitalPinToPort(P) ( digital_pin_to_port[P] )
#define digitalPinToBitMask(P) ( digital_pin_to_bit_mask[P] )
#define digitalPinToTimer(P) ( digital_pin_to_timer[P] )
#define portDATARegister(P) ( (volatile uint32_t *)( port_to_base[P]) + 0x3FC )
#define portDIRRegister(P) ( ((volatile uint32_t *)( port_to_base[P])) + 0x400 )
#define portAFSELRegister(P) ( ((volatile uint32_t *)( port_to_base[P])) + 0x420 )
#define portPURRegister(P) ( ((volatile uint32_t *)( port_to_base[P])) + 0x510 )
#define portPDRRegister(P) ( ((volatile uint32_t *)( port_to_base[P])) + 0x514 )
//#define portOutputRegister(P) ( (volatile uint16_t *)( port_to_base[P]) )
//#define portInputRegister(P) ( (volatile uint16_t *)( port_to_base[P]) )
#define portIBERegister(P) ( ((volatile uint32_t *)( port_to_base[P])) + 0x408 )
#define portIEVRegister(P) ( ((volatile uint32_t *)( port_to_base[P])) + 0x40C )
#define portIMRegister(P) ( ((volatile uint32_t *)( port_to_base[P])) + 0x410 )
#define portRISRegister(P) ( ((volatile uint32_t *)( port_to_base[P])) + 0x414 )
#define portMISRegister(P) ( ((volatile uint32_t *)( port_to_base[P])) + 0x418 )
#define portICRRegister(P) ( ((volatile uint32_t *)( port_to_base[P])) + 0x41C )
#define portDR2RRegister(P) ( ((volatile uint32_t *)( port_to_base[P])) + 0x500 )
#define portDR4RRegister(P) ( ((volatile uint32_t *)( port_to_base[P])) + 0x504 )
#define portDR8RRegister(P) ( ((volatile uint32_t *)( port_to_base[P])) + 0x508 )
#define portODRRegister(P) ( ((volatile uint32_t *)( port_to_base[P])) + 0x50C )
#define portSLRRegister(P) ( ((volatile uint32_t *)( port_to_base[P])) + 0x510 )
#define portDENRegister(P) ( ((volatile uint32_t *)( port_to_base[P])) + 0x514 )
#define portLOCKRegister(P) ( ((volatile uint32_t *)( port_to_base[P])) + 0x518 )
#define portCRRegister(P) ( ((volatile uint32_t *)( port_to_base[P])) + 0x51C )
#define portAMSELRegister(P) ( ((volatile uint32_t *)( port_to_base[P])) + 0x520 )
#define portPCTLRegister(P) ( ((volatile uint32_t *)( port_to_base[P])) + 0x524 )
#define portADCCTLRegister(P) ( ((volatile uint32_t *)( port_to_base[P])) + 0x528 )
#define portMACTLRegister(P) ( ((volatile uint32_t *)( port_to_base[P])) + 0x52C )
#define portPeriphID4Register(P) ( ((volatile uint32_t *)( port_to_base[P])) + 0x530 )
#define portPeriphID5Register(P) ( ((volatile uint32_t *)( port_to_base[P])) + 0x534 )
#define portPeriphID6Register(P) ( ((volatile uint32_t *)( port_to_base[P])) + 0xFD0 )
#define portPeriphID7Register(P) ( ((volatile uint32_t *)( port_to_base[P])) + 0xFD4 )
#define portPeriphID0Register(P) ( ((volatile uint32_t *)( port_to_base[P])) + 0xFD8 )
#define portPeriphID1Register(P) ( ((volatile uint32_t *)( port_to_base[P])) + 0xFDC )
#define portPeriphID2Register(P) ( ((volatile uint32_t *)( port_to_base[P])) + 0xFE0 )
#define portPeriphID3Register(P) ( ((volatile uint32_t *)( port_to_base[P])) + 0xFE4 )
#define portCellID0Register(P) ( ((volatile uint32_t *)( port_to_base[P])) + 0xFE8 )
#define portCellID1Register(P) ( ((volatile uint32_t *)( port_to_base[P])) + 0xFEC )
#define portCellID2Register(P) ( ((volatile uint32_t *)( port_to_base[P])) + 0xFF0 )
#define portCellID3Register(P) ( ((volatile uint32_t *)( port_to_base[P])) + 0xFF4 )

#define digitalPinToTimer(P) ( digital_pin_to_timer[P] )

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
#ifdef __MSP430_HAS_USCI__
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



