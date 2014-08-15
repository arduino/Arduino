#ifndef Energia_h 
#define Energia_h 

#define __CC3200R1M1RGC__

#include <stdint.h>
#include <stdbool.h> 
#include <string.h> 
#include <math.h>
#include <itoa.h>

#include "inc/hw_types.h"  		
#include "inc/hw_nvic.h" 
#include "driverlib/gpio.h" 
#include "driverlib/rom_map.h"
#include "driverlib/interrupt.h"

#ifdef __cplusplus
extern "C"{ 
#endif 
    
//addition to deal with PROGMEM references in arduino
#define PSTR
#define PROGMEM
#define pgm_read_byte(x) (*x)
#define pgm_read_dword(x) (*x)
#define strcat_P strcat
#define strlen_P strlen

#define NOT_A_PORT 0
#define NOT_A_PIN 0
#define NOT_ON_TIMER 128
#define NOT_ON_ADC 0x10

#define CHANGE 4
#define FALLING 3
#define RISING 2
#define HIGH 0x1
#define LOW  0x0

#define LSBFIRST 0
#define MSBFIRST 1

#define INPUT 0x0
#define OUTPUT 0x1
#define INPUT_PULLUP 0x2
#define INPUT_PULLDOWN 0x3

#define SPI_LAST 0
#define SPI_CONTINUE 1

#define PI 3.1415926535897932384626433832795
#define HALF_PI 1.5707963267948966192313216916398
#define TWO_PI 6.283185307179586476925286766559
#define DEG_TO_RAD 0.017453292519943295769236907684886
#define RAD_TO_DEG 57.295779513082320876798154814105

#define S0 1
#define S1 2
#define S2 3
#define S3 4
#define S4 5

#define TIMERA0A 0
#define TIMERA0B 1
#define TIMERA1A 2
#define TIMERA1B 3
#define TIMERA2A 4
#define TIMERA2B 5
#define TIMERA3A 6
#define TIMERA3B 7

typedef uint8_t boolean;
typedef uint8_t byte;

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))
#define round(x)     ((x)>=0?(long)((x)+0.5):(long)((x)-0.5))
#define radians(deg) ((deg)*DEG_TO_RAD)
#define degrees(rad) ((rad)*RAD_TO_DEG)
#define sq(x) ((x)*(x))

#define interrupts() MAP_IntMasterEnable()
#define noInterrupts() MAP_IntMasterDisable()

//#define clockCyclesPerMicrosecond() ( F_CPU / 1000000L )
#define clockCyclesPerMicrosecond() ( 80000000L / 1000000L )
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
extern const uint32_t timer_to_offset[];
extern const uint8_t timer_to_ab[];
extern const uint32_t timer_to_pin_config[];
extern const uint32_t port_to_base[];
extern const uint32_t digital_pin_to_analog_in[];
extern const uint16_t digital_pin_to_pin_num[];

#define digitalPinToPort(P)       ( digital_pin_to_port[P] )
#define digitalPinToPinNum(P)     ( digital_pin_to_pin_num[P] )
#define digitalPinToBitMask(P)    ( digital_pin_to_bit_mask[P] )
#define digitalPinToTimer(P)      ( digital_pin_to_timer[P] )
#define timerToAB(P)              ( timer_to_ab[P] )
#define timerToOffset(P)          ( timer_to_offset[P] )
#define timerToPinConfig(P)       ( timer_to_pin_config[P] )
#define digitalPinToADCIn(P)      ( digital_pin_to_analog_in[P] )
#define portBASERegister(P)       ((volatile uint32_t *) port_to_base[P])
#define portDATARegister(P)       ((volatile uint32_t *)( port_to_base[P] + 0x3FC ))
#define portDIRRegister(P)        ((volatile uint32_t *)( port_to_base[P] + 0x400 ))
#define portIBERegister(P)        ((volatile uint32_t *)( port_to_base[P] + 0x408 ))
#define portIEVRegister(P)        ((volatile uint32_t *)( port_to_base[P] + 0x40C ))
#define portIMRegister(P)         ((volatile uint32_t *)( port_to_base[P] + 0x410 ))
#define portRISRegister(P)        ((volatile uint32_t *)( port_to_base[P] + 0x414 ))
#define portMISRegister(P)        ((volatile uint32_t *)( port_to_base[P] + 0x418 ))
#define portICRRegister(P)        ((volatile uint32_t *)( port_to_base[P] + 0x41C ))
#define portAFSELRegister(P)      ((volatile uint32_t *)( port_to_base[P] + 0x420 ))
#define portDR2RRegister(P)       ((volatile uint32_t *)( port_to_base[P] + 0x500 ))
#define portDR4RRegister(P)       ((volatile uint32_t *)( port_to_base[P] + 0x504 ))
#define portDR8RRegister(P)       ((volatile uint32_t *)( port_to_base[P] + 0x508 ))
#define portODRRegister(P)        ((volatile uint32_t *)( port_to_base[P] + 0x50C ))
#define portPURRegister(P)        ((volatile uint32_t *)( port_to_base[P] + 0x510 ))
#define portPDRRegister(P)        ((volatile uint32_t *)( port_to_base[P] + 0x514 ))
#define portSLRRegister(P)        ((volatile uint32_t *)( port_to_base[P] + 0x518 ))
#define portDENRegister(P)        ((volatile uint32_t *)( port_to_base[P] + 0x51C ))
#define portLOCKRegister(P)       ((volatile uint32_t *)( port_to_base[P] + 0x520 ))
#define portCRRegister(P)         ((volatile uint32_t *)( port_to_base[P] + 0x524 ))
#define portAMSELRegister(P)      ((volatile uint32_t *)( port_to_base[P] + 0x528 ))
#define portPCTLRegister(P)       ((volatile uint32_t *)( port_to_base[P] + 0x52C ))
#define portADCCTLRegister(P)     ((volatile uint32_t *)( port_to_base[P] + 0x530 ))
#define portMACTLRegister(P)      ((volatile uint32_t *)( port_to_base[P] + 0x534 ))
#define portPeriphID4Register(P)  ((volatile uint32_t *)( port_to_base[P] + 0xFD0 ))
#define portPeriphID5Register(P)  ((volatile uint32_t *)( port_to_base[P] + 0xFD4 ))
#define portPeriphID6Register(P)  ((volatile uint32_t *)( port_to_base[P] + 0xFD8 ))
#define portPeriphID7Register(P)  ((volatile uint32_t *)( port_to_base[P] + 0xFDC ))
#define portPeriphID0Register(P)  ((volatile uint32_t *)( port_to_base[P] + 0xFE0 ))
#define portPeriphID1Register(P)  ((volatile uint32_t *)( port_to_base[P] + 0xFE4 ))
#define portPeriphID2Register(P)  ((volatile uint32_t *)( port_to_base[P] + 0xFE8 ))
#define portPeriphID3Register(P)  ((volatile uint32_t *)( port_to_base[P] + 0xFEC ))
#define portCellID0Register(P)    ((volatile uint32_t *)( port_to_base[P] + 0xFF0 ))
#define portCellID1Register(P)    ((volatile uint32_t *)( port_to_base[P] + 0xFF4 ))
#define portCellID2Register(P)    ((volatile uint32_t *)( port_to_base[P] + 0xFF8 ))
#define portCellID3Register(P)    ((volatile uint32_t *)( port_to_base[P] + 0xFFC ))

// Implemented in wiring.c
void delayMicroseconds(unsigned int us);
unsigned long micros();
unsigned long millis();
void initSysTick();
void registerSysTickCb(void (*userFunc)(uint32_t));
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

void tone(uint8_t _pin, unsigned int frequency);
void tone(uint8_t _pin, unsigned int frequency, unsigned long duration);
void noTone(uint8_t _pin);

// WMath prototypes
long random(long);
long random(long, long);
void randomSeed(unsigned int);
long map(long, long, long, long, long);

#endif

#include "pins_energia.h"

#endif



