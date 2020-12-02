/* IRLibHardware.h
 * Part of IRLib Library for Arduino receiving, decoding, and sending
 * infrared signals. See COPYRIGHT.txt and LICENSE.txt for more information.
 *
 * This file was formally called IRLibTimer.h but we have renamed it because it more
 * accurately reflects the fact that it contains all of the hardware specific defines.
 * It contains mostly definitions for 8-bit AVR processors. More advanced processors such as
 * SAMD21 definitions will now be defined in a separate processor specific header file.
 * NOTE: IRLibHardware.cpp is not related to hardware. See the comments in that file
 * to explain why it was created and what purpose it serves.
 */

/* This file has been significantly reconfigured for version 1.5 and greater. It now
 * allows you use a different timer for input versus output. This also allows you to
 * use no timers whatsoever by using the IRrecvPCI or IRrecvLoop for input and
 * bit-bang routines for output. Note the various "Teensy" sections have not been tested.
 */
#ifndef IRLibHardware_h
#define IRLibHardware_h

#include "Arduino.h"

//This is a default for AVRs. SAMD21 will override it.
#define IR_CLEAR_INTERRUPT {} //clear interrupt flag

// defines for setting and clearing register bits
#ifndef cbi
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#endif
#ifndef sbi
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
#endif

/* In this section we attempt to detect your hardware type and give you the choice of
 * various hardware timers to change the PWM frequency for output. In each hardware
 * section below you should un-comment only one of the choices. The defines also
 * specify the output pin number. DO NOT change the pin number unless you're using
 * non-standard hardware that would require you to do so. If you wish to use the
 * bit-bang PWM output, you will specify that AFTER this section as an override.
 */

/* Arduino Mega */
#if defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
	//#define IR_SEND_TIMER1	11
	#define IR_SEND_TIMER2		9
	//#define IR_SEND_TIMER3	5
	//#define IR_SEND_TIMER4	6
	//#define IR_SEND_TIMER5	46

/* Teensy 1.0 */
#elif defined(__AVR_AT90USB162__)
	#define IR_SEND_TIMER1	17

/* Teensy 2.0 versus Leonardo These boards use the same chip but the 
 * pinouts are different.*/
#elif defined(__AVR_ATmega32U4__)
	#ifdef CORE_TEENSY
		// it's Teensy 2.0
		//#define IR_SEND_TIMER1	14
		//#define IR_SEND_TIMER3	9
		#define IR_SEND_TIMER4_HS	10
	#else
	/* it's probably Leonardo */
		#define IR_SEND_TIMER1		9
		//#define IR_SEND_TIMER3	5
		//#define IR_SEND_TIMER4_HS	13
	#endif

/* Teensy++ 1.0 & 2.0 */
#elif defined(__AVR_AT90USB646__) || defined(__AVR_AT90USB1286__)
	//#define IR_SEND_TIMER1	25
	#define IR_SEND_TIMER2		1
	//#define IR_SEND_TIMER3	16

/*  Sanguino */
#elif defined(__AVR_ATmega644P__) || defined(__AVR_ATmega644__)
	//#define IR_SEND_TIMER1	13
	#define IR_SEND_TIMER2		14
  
/* Arduino Zero, M0, M0 Pro, Feather M0 etc. */
#elif defined (__SAMD21G18A__)
// All of the settings can be found in IRLibSAMD21.h
  #include "IRLibSAMD21.h"
  /* Pinoccio Scout */
#elif defined(__AVR_ATmega256RFR2__)
	#define IR_SEND_TIMER3		3

/* Arduino Duemilanove, Diecimila, LilyPad, Mini, Fio, etc */
#else
	//#define IR_SEND_TIMER1	9
	#define IR_SEND_TIMER2		3
#endif //end of setting IR_SEND_TIMER based on hardware detection

/* If you want to use bit-bang PWM output, you should un-comment the line below.
 * The definition must include the pin number for bit-bang output.  This could be any
 * available digital output pin. It need not be a designated PWM pin.
 * NOTE: By un-commenting this line, you are forcing the library to ignore
 * hardware detection and timer specifications above. The bit-bang frequency
 * code is not as accurate as using a hardware timer but it is more flexible and 
 * less hardware platform dependent.
 */
//#define IR_SEND_BIT_BANG  3  //Be sure to set this pin number if you un-comment

/* This is a fudge factor that adjusts bit-bang timing. Feel free to experiment
 * for best results.*/
#define IR_BIT_BANG_OVERHEAD 10

/* We are going to presume that you want to use the same hardware timer to control
 * the 50 microsecond interrupt used by the IRrecv receiver class as was specified
 * above in the hardware detection section for sending. Even if you specified bit-bang 
 * for sending, the definitions above have selected a default sending timer for you based 
 * on hardware detection. If that is correct, then do nothing below.  However if you do
 * wish to specify an IR_RECV_TIMER different than the IR_SEND_TIMER selected by the code 
 * above, then you should un-comment the IR_RECV_TIMER_OVERRIDE and also un-comment one 
 * and only one of the following IR_RECV_TIMERx lines below that.
 * NOTE: You are responsible for ensuring that the timer you are specifying is 
 * available on your hardware. You should only choose timers which are shown as available 
 * for your hardware platform as shown in the defines in the IR_SEND_TIMER section above.
 * NOTE: This discussion does not apply to SAMD 21 processors.
 */
//#define IR_RECV_TIMER_OVERRIDE
//#define IR_RECV_TIMER1
//#define IR_RECV_TIMER2
//#define IR_RECV_TIMER3
//#define IR_RECV_TIMER4
//#define IR_RECV_TIMER4_HS
//#define IR_RECV_TIMER5

// Miscellaneous defines needed for computations below
#ifdef F_CPU
#define SYSCLOCK F_CPU     // main Arduino clock
#else
#define SYSCLOCK 16000000  // main Arduino clock
#endif

/* Everything below this point is a computation based on user settings above.
 * In all likelihood you would never need to modify anything below this point
 * unless you are adding some completely new feature or seriously modifying
 * the behavior of existing features. In other words don't try this at home.
 */
#if !defined(IR_RECV_TIMER_OVERRIDE)
	#if defined(IR_SEND_TIMER1)
		#define IR_RECV_TIMER1
	#elif defined(IR_SEND_TIMER2)
		#define IR_RECV_TIMER2
	#elif defined(IR_SEND_TIMER3)
		#define IR_RECV_TIMER3
	#elif defined(IR_SEND_TIMER4)
		#define IR_RECV_TIMER4
	#elif defined(IR_SEND_TIMER4_HS)
		#define IR_RECV_TIMER4_HS
	#elif defined(IR_SEND_TIMER5)
		#define IR_RECV_TIMER5
	#elif defined(__SAMD21G18A__)//handle this one a little differently
    #define IR_RECV_TC3
  #else
		#error "Unable to set IR_RECV_TIMER"
	#endif
#endif

#if defined(IR_SEND_BIT_BANG)  //defines for bit-bang output
	#define IR_SEND_PWM_PIN	IR_SEND_BIT_BANG
	#define IR_SEND_PWM_START   unsigned int jmax=time/iLength;\
		for(unsigned int j=0;j<jmax;j++) {\
		  digitalWrite(IR_SEND_BIT_BANG, HIGH);  delayMicroseconds(onTime);\
		  digitalWrite(IR_SEND_BIT_BANG, LOW);   delayMicroseconds(offTime);}
	#define IR_SEND_MARK_TIME(time) 
	#define IR_SEND_PWM_STOP
	#define IR_SEND_CONFIG_KHZ(val)  float Length=1000.0/(float)khz;\
		iLength=int(Length+0.5); onTime=int(Length/3.0); \
		offTime=iLength-onTime-IR_BIT_BANG_OVERHEAD-(val<40);

#elif defined(IR_SEND_TIMER1) // defines for timer1 (16 bits)
	#define IR_SEND_PWM_START     (TCCR1A |= _BV(COM1A1))
	#define IR_SEND_MARK_TIME(time)  IRLibDelayUSecs(time)
	#define IR_SEND_PWM_STOP    (TCCR1A &= ~(_BV(COM1A1)))
	#define IR_SEND_CONFIG_KHZ(val) ({ \
		const uint16_t pwmval = SYSCLOCK / 2000 / (val); \
		TCCR1A = _BV(WGM11); TCCR1B = _BV(WGM13) | _BV(CS10); \
		ICR1 = pwmval; OCR1A = pwmval / 3; })
	#if defined(CORE_OC1A_PIN)
		#define IR_SEND_PWM_PIN        CORE_OC1A_PIN  /* Teensy */
	#else
		#define IR_SEND_PWM_PIN	IR_SEND_TIMER1
	#endif

#elif defined(IR_SEND_TIMER2)  // defines for timer2 (8 bits)
	#define IR_SEND_PWM_START     (TCCR2A |= _BV(COM2B1))
	#define IR_SEND_MARK_TIME(time)  IRLibDelayUSecs(time)
	#define IR_SEND_PWM_STOP    (TCCR2A &= ~(_BV(COM2B1)))
	#define IR_SEND_CONFIG_KHZ(val) ({ \
		const uint8_t pwmval = SYSCLOCK / 2000 / (val); \
		TCCR2A = _BV(WGM20);  TCCR2B = _BV(WGM22) | _BV(CS20); \
		OCR2A = pwmval; OCR2B = pwmval / 3; })
	#if defined(CORE_OC2B_PIN)
		#define IR_SEND_PWM_PIN        CORE_OC2B_PIN  /* Teensy */
	#else
		#define IR_SEND_PWM_PIN	IR_SEND_TIMER2
	#endif

#elif defined(IR_SEND_TIMER3) // defines for timer3 (16 bits)
	#define IR_SEND_PWM_START     (TCCR3A |= _BV(COM3A1))
	#define IR_SEND_MARK_TIME(time)  IRLibDelayUSecs(time)
	#define IR_SEND_PWM_STOP    (TCCR3A &= ~(_BV(COM3A1)))
	#define IR_SEND_CONFIG_KHZ(val) ({ \
		const uint16_t pwmval = SYSCLOCK / 2000 / (val); \
		TCCR3A = _BV(WGM31);   TCCR3B = _BV(WGM33) | _BV(CS30); \
		ICR3 = pwmval;   OCR3A = pwmval / 3; })
	#if defined(CORE_OC3A_PIN)
		#define IR_SEND_PWM_PIN        CORE_OC3A_PIN  /* Teensy */
	#else
		#define IR_SEND_PWM_PIN	IR_SEND_TIMER3
	#endif

#elif defined(IR_SEND_TIMER4_HS) // defines for timer4 (10 bits, high speed option)
	#define IR_SEND_PWM_START     (TCCR4A |= _BV(COM4A1))
	#define IR_SEND_MARK_TIME(time)  IRLibDelayUSecs(time)
	#define IR_SEND_PWM_STOP    (TCCR4A &= ~(_BV(COM4A1)))
	#define IR_SEND_CONFIG_KHZ(val) ({ \
		const uint16_t pwmval = SYSCLOCK / 2000 / (val); \
		TCCR4A = (1<<PWM4A);   TCCR4B = _BV(CS40); \
		TCCR4C = 0;   TCCR4D = (1<<WGM40); \
		TCCR4E = 0;   TC4H = pwmval >> 8; \
		OCR4C = pwmval;   TC4H = (pwmval / 3) >> 8;   OCR4A = (pwmval / 3) & 255; })
	#if defined(CORE_OC4A_PIN)
		#define IR_SEND_PWM_PIN        CORE_OC4A_PIN  /* Teensy */
	#else
		#define IR_SEND_PWM_PIN	IR_SEND_TIMER4_HS
	#endif

#elif defined(IR_SEND_TIMER4) // defines for timer4 (16 bits)
	#define IR_SEND_PWM_START     (TCCR4A |= _BV(COM4A1))
	#define IR_SEND_MARK_TIME(time)  IRLibDelayUSecs(time)
	#define IR_SEND_PWM_STOP    (TCCR4A &= ~(_BV(COM4A1)))
	#define IR_SEND_CONFIG_KHZ(val) ({ \
		const uint16_t pwmval = SYSCLOCK / 2000 / (val); \
		TCCR4A = _BV(WGM41); TCCR4B = _BV(WGM43) | _BV(CS40); \
		ICR4 = pwmval;   OCR4A = pwmval / 3; })
	#if defined(CORE_OC4A_PIN)
		#define IR_SEND_PWM_PIN        CORE_OC4A_PIN
	#else
		#define IR_SEND_PWM_PIN	IR_SEND_TIMER4
	#endif

#elif defined(IR_SEND_TIMER5) // defines for timer5 (16 bits)
	#define IR_SEND_PWM_START     (TCCR5A |= _BV(COM5A1))
	#define IR_SEND_MARK_TIME(time)  IRLibDelayUSecs(time)
	#define IR_SEND_PWM_STOP    (TCCR5A &= ~(_BV(COM5A1)))
	#define IR_SEND_CONFIG_KHZ(val) ({ \
		const uint16_t pwmval = SYSCLOCK / 2000 / (val); \
		TCCR5A = _BV(WGM51);   TCCR5B = _BV(WGM53) | _BV(CS50); \
		ICR5 = pwmval;   OCR5A = pwmval / 3; })
	#if defined(CORE_OC5A_PIN)
		#define IR_SEND_PWM_PIN        CORE_OC5A_PIN
	#else
		#define IR_SEND_PWM_PIN	IR_SEND_TIMER5
	#endif
#elif defined(IRLibSAMD21_h) // Used for SAMD 21
/* All of these definitions have been moved to IRLibSAMD21.h
	#define IR_SEND_PWM_START 
	#define IR_SEND_MARK_TIME(time)
	#define IR_SEND_PWM_STOP 
  #define IR_SEND_PWM_PIN	
	#define IR_SEND_CONFIG_KHZ(val) 
 */
#else // unknown timer
	#error "Internal code configuration error, no known IR_SEND_TIMER# defined\n"
#endif

/* This section sets up the 50 microsecond interval timer used by the
 * IRrecv receiver class. The various timers have already been selected 
 * earlier in this file.  Theoretically you could change the 50 but it has not been tested.
 */
#define USEC_PER_TICK 50  // microseconds per clock interrupt tick

#if defined(IR_RECV_TIMER1)  // defines for timer1 (16 bits)
	#define IR_RECV_ENABLE_INTR    (TIMSK1 = _BV(OCIE1A))
	#define IR_RECV_DISABLE_INTR   (TIMSK1 = 0)
	#define IR_RECV_INTR_NAME      ISR(TIMER1_COMPA_vect,ISR_NOBLOCK)
	#define IR_RECV_CONFIG_TICKS() ({ \
		TCCR1A = 0;   TCCR1B = _BV(WGM12) | _BV(CS10); \
		OCR1A = SYSCLOCK * USEC_PER_TICK / 1000000;   TCNT1 = 0; })

#elif defined(IR_RECV_TIMER2)  // defines for timer2 (8 bits)
	#define IR_RECV_ENABLE_INTR    (TIMSK2 = _BV(OCIE2A))
	#define IR_RECV_DISABLE_INTR   (TIMSK2 = 0)
	#define IR_RECV_INTR_NAME      ISR(TIMER2_COMPA_vect,ISR_NOBLOCK)
	#define IR_RECV_COUNT_TOP      (SYSCLOCK * USEC_PER_TICK / 1000000)
	#if (IR_RECV_COUNT_TOP < 256)
		#define IR_RECV_CONFIG_TICKS() ({ \
			TCCR2A = _BV(WGM21);  TCCR2B = _BV(CS20); \
			OCR2A = IR_RECV_COUNT_TOP;   TCNT2 = 0; })
	#else
		#define IR_RECV_CONFIG_TICKS() ({ \
			TCCR2A = _BV(WGM21);   TCCR2B = _BV(CS21); \
			OCR2A = IR_RECV_COUNT_TOP / 8;   TCNT2 = 0; })
	#endif

#elif defined(IR_RECV_TIMER3)  // defines for timer3 (16 bits)
	#define IR_RECV_ENABLE_INTR    (TIMSK3 = _BV(OCIE3A))
	#define IR_RECV_DISABLE_INTR   (TIMSK3 = 0)
	#define IR_RECV_INTR_NAME      ISR(TIMER3_COMPA_vect,ISR_NOBLOCK)
	#define IR_RECV_CONFIG_TICKS() ({ \
		TCCR3A = 0;   TCCR3B = _BV(WGM32) | _BV(CS30); \
		OCR3A = SYSCLOCK * USEC_PER_TICK / 1000000;   TCNT3 = 0; })

#elif defined(IR_RECV_TIMER4_HS)  // defines for timer4 (10 bits, high speed option)
	#define IR_RECV_ENABLE_INTR    (TIMSK4 = _BV(TOIE4))
	#define IR_RECV_DISABLE_INTR   (TIMSK4 = 0)
	#define IR_RECV_INTR_NAME      ISR(TIMER4_OVF_vect,ISR_NOBLOCK)
	#define IR_RECV_CONFIG_TICKS() ({ \
		TCCR4A = 0;   TCCR4B = _BV(CS40); \
		TCCR4C = 0;   TCCR4D = 0; TCCR4E = 0; \
		TC4H = (SYSCLOCK * USEC_PER_TICK / 1000000) >> 8; \
		OCR4C = (SYSCLOCK * USEC_PER_TICK / 1000000) & 255; \
		TC4H = 0;   TCNT4 = 0; })

#elif defined(IR_RECV_TIMER4) // defines for timer4 (16 bits)
	#define IR_RECV_ENABLE_INTR    (TIMSK4 = _BV(OCIE4A))
	#define IR_RECV_DISABLE_INTR   (TIMSK4 = 0)
	#define IR_RECV_INTR_NAME      ISR(TIMER4_COMPA_vect,ISR_NOBLOCK)
	#define IR_RECV_CONFIG_TICKS() ({ \
		TCCR4A = 0;   TCCR4B = _BV(WGM42) | _BV(CS40); \
		OCR4A = SYSCLOCK * USEC_PER_TICK / 1000000;   TCNT4 = 0; })

#elif defined(IR_RECV_TIMER5)  // defines for timer5 (16 bits)
	#define IR_RECV_ENABLE_INTR    (TIMSK5 = _BV(OCIE5A))
	#define IR_RECV_DISABLE_INTR   (TIMSK5 = 0)
	#define IR_RECV_INTR_NAME      ISR(TIMER5_COMPA_vect,ISR_NOBLOCK)
	#define IR_RECV_CONFIG_TICKS() ({ \
		TCCR5A = 0;   TCCR5B = _BV(WGM52) | _BV(CS50); \
		OCR5A = SYSCLOCK * USEC_PER_TICK / 1000000;   TCNT5 = 0; })
#elif defined(IRLibSAMD21_h)  //for SAMD 21
/* All of these definitions have been moved to IRLibSAMD21.h
	#define IR_RECV_ENABLE_INTR 
  #define IR_RECV_DISABLE_INTR
	#define IR_RECV_INTR_NAME
	#define IR_RECV_CONFIG_TICKS()
 */
#else // unknown timer
	#error "Internal code configuration error, no known IR_RECV_TIMER# defined\n"
#endif

//Cannot use blinking LED on 13 if that's the output pin.
#if (IR_SEND_PWM_PIN==13)
  #define BLINKLED      -1
  #define BLINKLED_ON() 
  #define BLINKLED_OFF()
#endif
// defines for blinking the LED
#ifndef BLINKLED
  #if defined(CORE_LED0_PIN)
    #define BLINKLED       CORE_LED0_PIN
    #define BLINKLED_ON()  (digitalWrite(CORE_LED0_PIN, HIGH))
    #define BLINKLED_OFF() (digitalWrite(CORE_LED0_PIN, LOW))
  #elif defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
    #define BLINKLED       13
    #define BLINKLED_ON()  (PORTB |= B10000000)
    #define BLINKLED_OFF() (PORTB &= B01111111)
  #elif defined(__AVR_ATmega644P__) || defined(__AVR_ATmega644__)
    #define BLINKLED       0
    #define BLINKLED_ON()  (PORTD |= B00000001)
    #define BLINKLED_OFF() (PORTD &= B11111110)
  #elif defined(__AVR_ATmega32u4__) || defined(__AVR_ATmega328__)
    #define BLINKLED       13
    #define BLINKLED_ON()  (PORTB |= B00100000)
    #define BLINKLED_OFF() (PORTB &= B11011111)
  #else
    #define BLINKLED       13
    #define BLINKLED_ON()  (digitalWrite(13, HIGH))
    #define BLINKLED_OFF() (digitalWrite(13, LOW))  
  #endif
#endif

extern uint8_t IRLib_didIROut;//See the explanation in IRLibHardware.cpp
#endif //IRLibHardware_h
