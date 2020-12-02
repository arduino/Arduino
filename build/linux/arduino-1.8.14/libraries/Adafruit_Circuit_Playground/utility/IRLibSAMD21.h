/* IRLibSAMD21.h
 * Part of IRLib Library for Arduino receiving, decoding, and sending
 * infrared signals. See COPYRIGHT.txt and LICENSE.txt for more information.
 *
 * This type of content is normally stored in IRLibHardware.h but we have 
 * moved at her because the SAMD21 support is significantly different than the
 * AVR 8-bit hardware support. Separating it out into a separate file
 * will make it easier to include comments and to maintain the code.
 */

/* This file provides hardware support for the SAMD21G18A processor or as we 
 * will refer to it simply as SAMD 21. This processor is used in the Arduino Zero, 
 * Arduino M0, Arduino M0 Pro, and the Adafruit Feather M0 series boards as well as
 * the upcoming Adafruit Circuit Playground Express.
 * Most of the code has been adapted from messages on the Arduino.cc support forum 
 * and from the code at:
 *	https://github.com/manitou48/ZERO/tree/master/IRtest
 * Receiving is supported through all three receiver classes. As you would expect 
 * the IRrecvLoop class can be used with any available input pin. The IRrecvPCI and 
 * IRfrequency classes can be used on any pin that supports "attachInterrupt()". 
 * Specifically that means everything except pin 4 on the Arduino Zero. And everything 
 * except pin 2 on the boards from Arduino.org such as the Arduino M0, M0 Pro, and 
 * Zero Pro. For details on supported pins see these links:
 *	https://www.arduino.cc/en/Reference/AttachInterrupt
 *	http://www.arduino.org/learning/reference/AttachInterrupt
 * Note that although we support Arduino.org hardware, you should only use the 
 * Arduino.cc IDE for compiling your sketches.
 * Both sending and receiving use GCLK0 even though GCLK0-GCLK3 are generally reserved
 * the Arduino infrastructure. However we are using the default 48 MHz clock source
 * and a divisor of "1" so we aren't changing any of the GCLK0 set up. It's therefore
 * safe to use.
 * The IRrecv receiver class using a 50 microsecond timer interrupt is also supported. 
 * It defaults to using hardware timer TC3 however TC4 and TC5 can also be used in case 
 * of conflicts with other libraries. The IRrecv and IRrecvLoop classes should be able to use
 * any available input pin. Note that all of our example sketches used pin 2 for 
 * receiver and pin 3 for frequency measurement. However pin 2 is not available for PCI 
 * interrupts on the Arduino.org platforms and neither 2 nor 3 are available on the 
 * Adafruit Feather M0 platforms. We are recommending using 5 and 6 for receiving and
 * frequency measurement respectively.
 * For sending, you can use any pin that supports PWM on your particular 
 * platform. On Arduino Zero that means pins 3, 4, 5, 6, 8, 9, 10, 11, 12, or 13.
 * Additionally Arduino M0 Pro adds pins 2 and 7 to that list. In all cases the default
 * output pin is 9. The code automatically selects TCC0 or TCC1 based on pin number
 * as needed. It has been tested at frequencies of 36, 38, 39, 40 and 57 which
 * are the frequencies of our supported protocols.
 * As of this release the code has been tested on Arduino Zero, Arduino M0 Pro, and 
 * Adafruit Feather M0 BLE version.
 */
#ifndef IRLibSAMD21_h
#define IRLibSAMD21_h
/*
 * This section contains user changeable values. You can probably stick with the defaults
 * but if there are hardware conflicts with other libraries, you can change these values.
 */
//Choose PWM output pin number from among the following
//Un-comment only one of these. 
//#define IR_SEND_PWM_PIN 2
//#define IR_SEND_PWM_PIN 3
//#define IR_SEND_PWM_PIN 4
//#define IR_SEND_PWM_PIN 5
//#define IR_SEND_PWM_PIN 6
//#define IR_SEND_PWM_PIN 7
//#define IR_SEND_PWM_PIN 8
//#define IR_SEND_PWM_PIN 9
//#define IR_SEND_PWM_PIN 10
//#define IR_SEND_PWM_PIN 11
#define IR_SEND_PWM_PIN 12
//#define IR_SEND_PWM_PIN 13
//Override default for Adafruit Circuit Playground Express
#ifdef ARDUINO_SAMD_CIRCUITPLAYGROUND_EXPRESS
  #define IR_SEND_PWM_PIN 25
#endif
//Choose which timer counter to use for the 50 microsecond interrupt
//Un-comment only one of these.
#define IR_TCn 3
//#define IR_TCn 4
//#define IR_TCn 5

/*
 * Everything below this point should not be changed. It computes needed defines
 * based on the user set values above.
 */

// Saves us a lot of typing when synchronizing
#define syncTC   while (IR_TCx->COUNT16.STATUS.bit.SYNCBUSY)
#define syncGCLK while (GCLK->STATUS.bit.SYNCBUSY)

#if defined(ARDUINO_SAMD_FEATHER_M0)
  #if ( (IR_SEND_PWM_PIN<5) || (IR_SEND_PWM_PIN==7) || (IR_SEND_PWM_PIN==8) )
    #error "Pin unsupported on Adafruit Feather M0"
  #endif
#endif

//Pins 8 and 9 use TCC1 and all others use TCC0
#if ( (IR_SEND_PWM_PIN==8) || (IR_SEND_PWM_PIN==9) )
  #define IR_TCCx TCC1
#else
  #define IR_TCCx TCC0
#endif

//Although there are 8 WO there are only 4 CC
#define CC4 CC0
#define CC5 CC1
#define CC6 CC2
#define CC7 CC3

//Set other values based on pin number
#if (IR_SEND_PWM_PIN==2)
  //NOTE: Arduino M0 Pro only
  #if defined(ARDUINO_SAM_ZERO)
    //PA08 E:TCC0-WO[0] F:TCC1-WO[2]
    #define IR_MUX_EF PORT_PMUX_PMUXE_E
    #define IR_CCx CC0
    #define IR_CCn 0
  #else
    #error "Pin 2 only available on Arduino M0 Pro"
  #endif
#elif (IR_SEND_PWM_PIN==3)
  //PA09 E:TCC0-WO[1] F:TCC1-WO[3]
  #define IR_MUX_EF PORT_PMUX_PMUXO_E 
  #define IR_CCx CC1
  #define IR_CCn 1
#elif (IR_SEND_PWM_PIN==4)
  //Arduino M0 Pro swaps pins 2 and 4
  #if(ARDUINO_SAM_ZERO)
    //Arduino M0 Pro
    //PA09 E:TC3-WO[0] F:TCC0-WO[4]
    #define IR_MUX_EF PORT_PMUX_PMUXE_F 
    #define IR_CCx CC4
    #define IR_CCn 4
  #else
    //Arduino Zero
    //PA08 E:TCC0-WO[0] F:TCC1-WO[2]
    #define IR_MUX_EF PORT_PMUX_PMUXE_E
    #define IR_CCx CC0
    #define IR_CCn 0
  #endif
#elif (IR_SEND_PWM_PIN==5)
  //PA15 E:TC3-WO[1] F:TCC0-WO[5]
  #define IR_MUX_EF PORT_PMUX_PMUXO_F
  #define IR_CCx CC5
  #define IR_CCn 5
#elif (IR_SEND_PWM_PIN==6)
  //PA20 E:TC7-WO[0] F:TCC0-WO[6]
  #define IR_MUX_EF PORT_PMUX_PMUXE_F
  #define IR_CCx CC6
  #define IR_CCn 6
#elif (IR_SEND_PWM_PIN==7)
  //NOTE: Arduino M0 Pro only
  #if defined(ARDUINO_SAM_ZERO)
    //PA08 E:TC7-WO[1] F:TCC0-WO[7]
    #define IR_MUX_EF PORT_PMUX_PMUXO_F
    #define IR_CCx CC7
    #define IR_CCn 7
  #else
    #error "Pin 7 only available on Arduino M0 Pro"
  #endif
#elif (IR_SEND_PWM_PIN==8)
  //PA06 E:TCC1-WO[0] F:--
  #define IR_MUX_EF PORT_PMUX_PMUXE_E 
  #define IR_CCx CC0
  #define IR_CCn 0
#elif (IR_SEND_PWM_PIN==9)
  //PA07 E:TCC1-WO[1] F:--
  #define IR_MUX_EF PORT_PMUX_PMUXO_E 
  #define IR_CCx CC1
  #define IR_CCn 1
#elif (IR_SEND_PWM_PIN==10)
  //PA18 E:TC3-WO[0] F:TCC0-WO[2]
  #define IR_MUX_EF PORT_PMUX_PMUXE_F
  #define IR_CCx CC2
  #define IR_CCn 2
#elif (IR_SEND_PWM_PIN==11)
  //PA16 E:TCC2-WO[0] F:TCC0-WO[6]
  #define IR_MUX_EF PORT_PMUX_PMUXE_F 
  #define IR_CCx CC6
  #define IR_CCn 6
#elif (IR_SEND_PWM_PIN==12)
  //PA19 E:TC3-WO[1] F:TCC0-WO[3]
  #define IR_MUX_EF PORT_PMUX_PMUXO_F
  #define IR_CCx CC3
  #define IR_CCn 3
#elif (IR_SEND_PWM_PIN==13)
  //PA17 E:TCC2-WO[1] F:TCC0-WO[7]
  #define IR_MUX_EF PORT_PMUX_PMUXO_F 
  #define IR_CCx CC7
  #define IR_CCn 7
#elif (IR_SEND_PWM_PIN==25)//Adafruit Circuit Playground Express only
  //PA23 E:TC4-WO[1] F:TCC0-WO[5]
  #define IR_MUX_EF PORT_PMUX_PMUXO_F 
  #define IR_CCx CC5
  #define IR_CCn 5
#else 
  #error "Invalid SAMD21 PWM pin"
#endif

// Turns PWM on and off after already set up
#define IR_SEND_PWM_START {IR_TCCx->CTRLA.reg |= TCC_CTRLA_ENABLE;\
  while (IR_TCCx->SYNCBUSY.bit.ENABLE);}
#define IR_SEND_MARK_TIME(time)  IRLibDelayUSecs(time)
#define IR_SEND_PWM_STOP {IR_TCCx->CTRLA.reg &= ~TCC_CTRLA_ENABLE;\
  while (IR_TCCx->SYNCBUSY.bit.ENABLE);}
#define IR_SEND_CONFIG_KHZ(val) initializeSAMD21PWM(val);

/* These are the definitions for setting up the 50 microsecond
 * timer interrupt for the IRrecv class. 
 */
#if (IR_TCn==3)
  #define IR_TCx   TC3
  #define IR_GCM   GCM_TCC2_TC3
  #define IR_RECV_INTR_NAME void TC3_Handler()
  #define IR_IRQ   TC3_IRQn
#elif (IR_TCn==4)
  #define IR_TCx   TC4
  #define IR_GCM   GCM_TC4_TC5
  #define IR_RECV_INTR_NAME void TC4_Handler()
  #define IR_IRQ   TC4_IRQn
#elif (IR_TCn==5)
  #define IR_TCx   TC5
  #define IR_GCM   GCM_TC4_TC5
  #define IR_RECV_INTR_NAME void TC5_Handler()
  #define IR_IRQ   TC5_IRQn
#else
  #error "Invalid IR_TCn value"
#endif

#define IR_RECV_ENABLE_INTR ({NVIC_EnableIRQ(IR_IRQ);\
    IR_TCx->COUNT16.INTENSET.reg = TC_INTENSET_OVF;\
    IR_TCx->COUNT16.CTRLA.reg |= TC_CTRLA_ENABLE; syncTC;})
#define IR_RECV_DISABLE_INTR  IR_TCx->COUNT16.INTENCLR.reg = TC_INTENCLR_OVF;  
#define IR_RECV_CONFIG_TICKS() initializeSAMD21timerInterrupt()

//Clear interrupt
#define IR_CLEAR_INTERRUPT 	IR_TCx->COUNT16.INTFLAG.bit.MC0 = 1;

//prototypes
void initializeSAMD21PWM(uint16_t khz);
void initializeSAMD21timerInterrupt(void);

#endif //IRLibSAMD21_h
