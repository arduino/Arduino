/*
 * IRremote
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * For details, see http://arcfn.com/2009/08/multi-protocol-infrared-remote-library.html
 *
 * Modified by Paul Stoffregen <paul@pjrc.com> to support other boards and timers
 *
 * Interrupt code based on NECIRrcv by Joe Knapp
 * http://www.arduino.cc/cgi-bin/yabb2/YaBB.pl?num=1210243556
 * Also influenced by http://zovirl.com/2008/11/12/building-a-universal-remote-with-an-arduino/
 */

#ifndef IRremoteint_h
#define IRremoteint_h

#include <Energia.h>

// NOTE: launchpad with a M430G2553

#define IR_USE_TIMERA 

// Clock freq in kilohertz
// Defined because using F_CPU in TIMER_CONFIG_KHZ does not work.
// TIMER_CONFIG_KHZ does a calculation and using too large of a
// number causes overflow.
#define FOSC 16000

#ifdef F_CPU
#define SYSCLOCK F_CPU     // main MSP430 clock  
#else
#define SYSCLOCK 16000000  
#endif

#define ERR 0
#define DECODED 1

//#define DEBUG

// TODO: edit these to match MSP430

// defines for setting and clearing register bits
#ifndef cbi
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#endif
#ifndef sbi
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
#endif

// pulse parameters in usec
#define NEC_HDR_MARK	9000
#define NEC_HDR_SPACE	4500
#define NEC_BIT_MARK	560
#define NEC_ONE_SPACE	1690
#define NEC_ZERO_SPACE	560
#define NEC_RPT_SPACE	2250

#define SONY_HDR_MARK	2400
#define SONY_HDR_SPACE	600
#define SONY_ONE_MARK	1200
#define SONY_ZERO_MARK	600
#define SONY_RPT_LENGTH 45000

#define RC5_T1		889
#define RC5_RPT_LENGTH	46000

#define RC6_HDR_MARK	2666
#define RC6_HDR_SPACE	889
#define RC6_T1		444
#define RC6_RPT_LENGTH	46000

#define SHARP_BIT_MARK 245
#define SHARP_ONE_SPACE 1805
#define SHARP_ZERO_SPACE 795
#define SHARP_GAP 600000
#define SHARP_TOGGLE_MASK 0x3FF
#define SHARP_RPT_SPACE 3000

#define DISH_HDR_MARK 400
#define DISH_HDR_SPACE 6100
#define DISH_BIT_MARK 400
#define DISH_ONE_SPACE 1700
#define DISH_ZERO_SPACE 2800
#define DISH_RPT_SPACE 6200
#define DISH_TOP_BIT 0x8000

#define SHARP_BITS 15
#define DISH_BITS 16

#define TOLERANCE 25  // percent tolerance in measurements
#define LTOL (1.0 - TOLERANCE/100.) 
#define UTOL (1.0 + TOLERANCE/100.) 

#define _GAP 5000 // Minimum map between transmissions
#define GAP_TICKS (_GAP/USECPERTICK)

#define TICKS_LOW(us) (int) (((us)*LTOL/USECPERTICK))
#define TICKS_HIGH(us) (int) (((us)*UTOL/USECPERTICK + 1))

#ifndef DEBUG
// SH 071112 this macros have a tolerance problem.
//#define MATCH(measured_ticks, desired_us) ((measured_ticks) >= TICKS_LOW(desired_us) && (measured_ticks) <= TICKS_HIGH(desired_us))
//#define MATCH_MARK(measured_ticks, desired_us) MATCH(measured_ticks, (desired_us) + MARK_EXCESS)
//#define MATCH_SPACE(measured_ticks, desired_us) MATCH((measured_ticks), (desired_us) - MARK_EXCESS)
// Debugging versions are in IRremote.cpp
#endif

// receiver states
#define STATE_IDLE     2
#define STATE_MARK     3
#define STATE_SPACE    4
#define STATE_STOP     5

// information for the interrupt handler
typedef struct {
  uint8_t recvpin;             // pin for IR data from detector
  uint8_t rcvstate;            // state machine
  uint8_t blinkflag;           // TRUE to enable blinking of GREEN_LED on IR processing
  unsigned int timer;          // state timer, counts 50uS ticks.
  unsigned int rawbuf[RAWBUF]; // raw data
  uint8_t rawlen;              // counter of entries in rawbuf
} 
irparams_t;

// Defined in IRremote.cpp
extern volatile irparams_t irparams;

// IR detector output is active low
#define MARK  0
#define SPACE 1

#define TOPBIT 0x80000000

#define NEC_BITS 32
#define SONY_BITS 12
#define MIN_RC5_SAMPLES 11
#define MIN_RC6_SAMPLES 1

#define TIMER_PWM_PIN        P2_3
// NOTE: TIMER_PIN_SELECT depends on TIMER_PWM_PIN
// P2DIR |= BIT3; // P2.3 output
// P2SEL |= BIT3; // P2.3 option select
#define TIMER_PIN_SELECT() ({ \
  P2DIR |= BIT3;              \
  P2SEL |= BIT3;              \
})

// defines for Timer_A (16 bits)
// NOTE: Using A1 instead of A0 because A0 is used by Serial
#if defined(IR_USE_TIMERA)
#define TIMER_RESET
#define TIMER_ENABLE_PWM     (TA1CTL = TASSEL_2 + MC_1) // SMCLK, Up mode
#define TIMER_DISABLE_PWM    (TA1CTL = TASSEL_2 + MC_0) // SMCLK, Stop mode
#define TIMER_ENABLE_INTR    ({ /*TA1CTL |= TAIE;*/ TA1CCTL0 |= CCIE;}) // SH 071112 
#define TIMER_DISABLE_INTR   ({TA1CTL &= ~TAIE; TA1CCTL0 &= ~CCIE;})
#define TIMER_INTR_NAME      TIMER1_A0_VECTOR
#define TIMER_CONFIG_KHZ(val) ({ \
      TA1CCTL0 |= OUTMOD_4;	 \
      TA1CCR0 = FOSC/val/2;      \
})

// TODO: update TIMER_CONFIG_NORMAL
// need to alter the math?

//   TA1CCR0 = SYSCLOCK * USECPERTICK / 1000000;

#define TIMER_CONFIG_NORMAL() ({               \
  TA1CTL = TASSEL_2 + MC_1;                    \
  TA1CCTL0 |= OUTMOD_4;	                       \
  TA1CCR0 = SYSCLOCK * USECPERTICK / 1000000;                               \
  TA1R = 0;				       \
})
#endif

#else // unknown timer
#error "Internal code configuration error, no known IR_USE_TIMER# defined\n"
#endif

// defines for blinking the (Green) LED
// MSP430 launchpad also has RED_LED
#define BLINKLED       GREEN_LED
#define BLINKLED_ON()  (digitalWrite(BLINKLED, HIGH))
#define BLINKLED_OFF() (digitalWrite(BLINKLED, LOW))

