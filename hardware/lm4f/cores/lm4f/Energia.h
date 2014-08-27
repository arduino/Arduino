#ifndef Energia_h 
#define Energia_h 

#include <stdint.h>
#include <stdbool.h> 
#include <string.h> 
#include <math.h>
#include "itoa.h"
#include "part.h"

#if defined(__TM4C129XNCZAD__)
#define TARGET_IS_SNOWFLAKE_RA0
#define PART_TM4C129XNCZAD
#elif defined(__TM4C1294NCPDT__)
#define TARGET_IS_SNOWFLAKE_RA0
#define PART_TM4C1294NCPDT
#elif defined(__LM4F120H5QR__) || defined(__TM4C123GH6PM__)
#define TARGET_IS_BLIZZARD_RB1
#define PART_TM4C1233H6PM
#define PART_LM4F120H5QR
#else
#error "**** No PART defined or unsupported PART ****"
#endif

#include "binary.h" 
#include "inc/hw_types.h"  		
#include "inc/hw_nvic.h" 
#include "driverlib/gpio.h" 
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"

#ifdef __cplusplus
extern "C"{ 
#endif 

#define PSTR
#define PROGMEM
#define pgm_read_byte(x) (*x)
#define pgm_read_dword(x) (*x)
#define strcat_P strcat
#define strlen_P strlen

#define NOT_A_PORT 0
#define NOT_A_PIN 0
#define NOT_ON_TIMER 0
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

#define PA 1
#define PB 2
#define PC 3
#define PD 4
#define PE 5
#define PF 6
#define PG 7
#define PH 8
#define PJ 9
#define PK 10
#define PL 11
#define PM 12
#define PN 13
#define PP 14
#define PQ 15
#define PR 16
#define PS 17
#define PT 18

#define TIMA 0
#define TIMB 8


#ifdef __TM4C1294NCPDT__
// from Table 13-2. General-Purpose Timers Signals (128TQFP)
#define T0CCP0_0 0
#define T0CCP0_1 1
#define T0CCP0_2 2

#define T0CCP1_0 3
#define T0CCP1_1 4
#define T0CCP1_2 5

#define T1CCP0_0 6
#define T1CCP0_1 7
#define T1CCP0_2 8

#define T1CCP1_0 9
#define T1CCP1_1 10
#define T1CCP1_2 11

#define T2CCP0_0 12
#define T2CCP0_1 13

#define T2CCP1_0 14
#define T2CCP1_1 15

#define T3CCP0_0 16
#define T3CCP0_1 17
#define T3CCP0_2 18

#define T3CCP1_0 19
#define T3CCP1_1 20
#define T3CCP1_2 21

#define T4CCP0_0 22
#define T4CCP0_1 23
#define T4CCP0_2 24

#define T4CCP1_0 25
#define T4CCP1_1 26
#define T4CCP1_2 27

#define T5CCP0_0 28
#define T5CCP0_1 29

#define T5CCP1_0 30
#define T5CCP1_1 31

#define TIMER0 0
#define TIMER1 1
#define TIMER2 2
#define TIMER3 3
#define TIMER4 4
#define TIMER5 5
#define WTIMER0 6 // this is needed PWMWrite, see TimerPrescaleSet


#else
#define T0A0 0
#define T0A1 1
#define T0B0 2
#define T0B1 3
#define T1A0 4
#define T1A1 5
#define T1B0 6
#define T1B1 7
#define T2A0 8
#define T2A1 9
#define T2B 10
#define T3A 11
#define T3B 12
#define WT0A 13
#define WT0B 14
#define WT1A 15
#define WT1B 16
#define WT2A 17
#define WT2B 18
#define WT3A 19
#define WT3B 20
#define WT5A 21
#define WT5B 22

#define TIMER0 0
#define TIMER1 1
#define TIMER2 2
#define TIMER3 3
#define WTIMER0 4
#define WTIMER1 5
#define WTIMER2 6
#define WTIMER3 7
#define WTIMER5 9
#endif

typedef uint8_t boolean;
typedef uint8_t byte;

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))
#define round(x)     ((x)>=0?(long)((x)+0.5):(long)((x)-0.5))
#define radians(deg) ((deg)*DEG_TO_RAD)
#define degrees(rad) ((rad)*RAD_TO_DEG)
#define sq(x) ((x)*(x))

#define interrupts() ROM_IntMasterEnable()
#define noInterrupts() ROM_IntMasterDisable()

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
extern const uint32_t timer_to_offset[];
extern const uint8_t timer_to_ab[];
extern const uint32_t timer_to_pin_config[];
extern const uint32_t port_to_base[];
extern const uint32_t digital_pin_to_analog_in[];

#define digitalPinToPort(P)       ( digital_pin_to_port[P] )
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
void timerInit();
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



