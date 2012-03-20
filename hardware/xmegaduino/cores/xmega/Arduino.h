#ifndef Arduino_h
#define Arduino_h

#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <avr/pgmspace.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#include "binary.h"

#ifdef __cplusplus
extern "C"{
#endif

#define HIGH 0x1
#define LOW  0x0

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

#define SERIAL  0x0
#define DISPLAY 0x1

#define LSBFIRST 0
#define MSBFIRST 1

#define RISING  1
#define FALLING 2
#define LEVEL   3
#define CHANGE  4

#define AREF_INTERNAL   0
#define AREF_VCC        1
#define AREF_EXTERNAL_A 2
#define AREF_EXTERNAL_B 3

#define INTERNAL   AREF_INTERNAL
#define DEFAULT    AREF_VCC
#define EXTERNAL   AREF_EXTERNAL_A

// undefine stdlib's abs if encountered
#ifdef abs
#undef abs
#endif

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))
#define round(x)     ((x)>=0?(long)((x)+0.5):(long)((x)-0.5))
#define radians(deg) ((deg)*DEG_TO_RAD)
#define degrees(rad) ((rad)*RAD_TO_DEG)
#define sq(x) ((x)*(x))

#define interrupts() sei()
#define noInterrupts() cli()

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

typedef uint8_t boolean;
typedef uint8_t byte;

void init(void);

void pinMode(uint8_t, uint8_t);
void digitalWrite(uint8_t, uint8_t);
int digitalRead(uint8_t);
int analogRead(uint8_t);
void analogReference(uint8_t mode);
void analogWrite(uint8_t, int);

unsigned long millis(void);
unsigned long micros(void);
void delay(unsigned long);
void delayMicroseconds(unsigned int us);
unsigned long pulseIn(uint8_t pin, uint8_t state, unsigned long timeout);

void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t val);
uint8_t shiftIn(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder);

void attachInterrupt(uint8_t, void (*)(void), int mode);
void detachInterrupt(uint8_t);

void setup(void);
void loop(void);

// Get the bit location within the hardware port of the given virtual pin.
// This comes from the pins_*.c file for the active board configuration.

#define analogInPinToBit(P) (P)

extern const uint16_t PROGMEM port_to_PGM[];

extern const uint8_t PROGMEM digital_pin_to_port_PGM[];
// extern const uint8_t PROGMEM digital_pin_to_bit_PGM[];
extern const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[];
extern const uint8_t PROGMEM digital_pin_to_timer_PGM[];
extern const TC0_t* PROGMEM timer_to_tc0_PGM[];
extern const TC1_t* PROGMEM timer_to_tc1_PGM[];
#if defined(TCC2) || defined(TCD2)
extern const TC2_t* PROGMEM timer_to_tc2_PGM[];
#endif
extern const uint16_t PROGMEM timer_to_channel_register_PGM[];
extern const uint8_t PROGMEM timer_to_channel_PGM[];
extern const uint8_t PROGMEM adc_to_channel_PGM[];

// Get the bit location within the hardware port of the given virtual pin.
// This comes from the pins_*.c file for the active board configuration.
// 
// These perform slightly better as macros compared to inline functions
//
#define digitalPinToPort(P) ( pgm_read_byte( digital_pin_to_port_PGM + (P) ) )
#define digitalPinToBitMask(P) ( pgm_read_byte( digital_pin_to_bit_mask_PGM + (P) ) )
#define digitalPinToTimer(P) ( pgm_read_byte( digital_pin_to_timer_PGM + (P) ) )
#define analogInPinToBit(P) (P)
#define portRegister(P) ( (volatile PORT_t *)( pgm_read_word( port_to_PGM + (P))) )
#define portOutputRegister(P) ( (volatile uint16_t *)(portRegister(P)->OUT) )
#define portInputRegister(P)  ( (volatile uint16_t *)(portRegister(P)->IN) )
#define portModeRegister(P)   ( (volatile uint16_t *)(portRegister(P)->DIR) )
#define timerToTC0(T) ( (volatile TC0_t *)( pgm_read_word( timer_to_tc0_PGM + (T))) )
#define timerToTC1(T) ( (volatile TC1_t *)( pgm_read_word( timer_to_tc1_PGM + (T))) )
#if defined(TCC2) || defined(TCD2)
#define timerToTC2(T) ( (volatile TC2_t *)( pgm_read_word( timer_to_tc2_PGM + (T))) )
#endif
#define timerToChannel(T) ( (uint8_t)( pgm_read_word( timer_to_channel_PGM + (T))) )
#define adcToChannel(P) ( (uint8_t)( pgm_read_word( adc_to_channel_PGM + (P))) )

#define NOT_A_PIN 0
#define NOT_A_PORT 0

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

#define NOT_ON_TIMER 0

#define TIMER_C0A  1
#define TIMER_C0B  2
#define TIMER_C0C  3
#define TIMER_C0D  4
#define TIMER_C1A  5
#define TIMER_C1B  6

#define TIMER_D0A  7
#define TIMER_D0B  8
#define TIMER_D0C  9
#define TIMER_D0D 10
#define TIMER_D1A 11
#define TIMER_D1B 12

#define TIMER_E0A 13
#define TIMER_E0B 14
#define TIMER_E0C 15
#define TIMER_E0D 16
#define TIMER_E1A 17
#define TIMER_E1B 18

#define TIMER_C2LA 19
#define TIMER_C2LB 20
#define TIMER_C2LC 21
#define TIMER_C2LD 22
#define TIMER_C2HA 23
#define TIMER_C2HB 24
#define TIMER_C2HC 25
#define TIMER_C2HD 26

#define TIMER_D2LA 27
#define TIMER_D2LB 28
#define TIMER_D2LC 29
#define TIMER_D2LD 30
#define TIMER_D2HA 31
#define TIMER_D2HB 32
#define TIMER_D2HC 33
#define TIMER_D2HD 34

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
