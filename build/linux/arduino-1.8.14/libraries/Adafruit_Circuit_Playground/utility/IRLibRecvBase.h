/* IRLibRecvBase.h 
 * Part of IRLib Library for Arduino receiving, decoding, and sending
 * infrared signals. See COPYRIGHT.txt and LICENSE.txt for more information.
 *
 * This module contains the base class classes for receiving IR signals. You will not create
 * instances of this class, rather it is used as a base class for the 3 different
 * receiver classes. These are the original IRrecv which uses a 50us timer interrupt.
 * The IRrecvPCI version that uses pin change interrupts and IRrecvLoop which uses no timers
 * or interrupts. Each of these has its own .h and .cpp file.
 *
 * The IRrecvLoop files are in this folder.  However the other two receivers in their own 
 * separate libraries. That is because their interrupt service routines can conflict
 * with other ISRs. The ISRs conflict would occur even if you did not create an instance
 * of their receiver classes. Similarly the frequency detection receiver which also uses
 * interrupts is also in a separate folder IRLibFreq.
 */

#ifndef IRLibRecvBase_h
#define IRLibRecvBase_h
#include "IRLibGlobals.h"

/* Below are default values for initializing various receiver parameters.
 * Each of these can be set using methods or variables in the base class
 * however these are the defaults if you do not specifically set them.
 */
#define DEFAULT_BLINK_PIN LED_BUILTIN  //NOTE: LED_BUILTIN is an Arduino constant
#define DEFAULT_BLINK_ENABLED false
#define DEFAULT_MARK_EXCESS 50
#define DEFAULT_FRAME_TIMEOUT 7800 //maximum length of SPACE Sbefore we assume frame ended
//DEFAULT_TIMEOUT should be 1.25*the_largest_space_any_valid_IR_protocol_might_have. 
//In IRremote library ir_Dish.cpp space they use DISH_RPT_SPACE 6200 while referenced says
//about 6000. If we take 6200*1.25= 7750 rounded up we will use 7800. Previous IRLib
//value was 10000 was probably too large. Thanks to Gabriel Staples for this note.


/* Base receiver class. Do not create instance. Only used as base for other
 * receiver classes. See documentation for description of each method or variable.
 */
class IRrecvBase {
public:
  IRrecvBase(void) {};
  IRrecvBase(uint8_t recvPin);
  bool getResults(const uint16_t timePerTicks=1);
  virtual void enableIRIn(void);
  virtual void disableIRIn(void);
  void enableAutoResume(uint16_t *P); 
  void setFrameTimeout(uint16_t frameTimeout);
  void blink13(bool enableBlinkLED);
	uint16_t markExcess;
protected:
  void init(void);
};

/* The global functions below are not methods of any class because they either
 * do not directly relate to the classes or they must be global functions
 * so that they can appear inside and ISR. You cannot pass variables to ISR's
 * or you could not pass any object or methods to it. These functions have been
 * renamed to emphasize the fact that they are part of this library.
 */
 
/* This function does the actual blinking of an indicator LED. Must be global
 * so it can be used by ISRs
 */
void IRLib_doBlink(void);

/* Some users create custom boards for input and output of IR signals and those boards are 
 * connected to their Arduino even in the case when the sketch only does input. It is 
 * theoretically possible that when running an “input only” sketch that the output pin 
 * could initialize high and your output LED would be on all the time. LED driver circuits 
 * are sometimes designed to overdrive the LED because it is used only intermittently. If 
 * it were to be accidentally left on continuously, it could burn out your circuit. If you
 * want to ensure that this does not happen you can call the function below.
 * NOTE: This used to be a method of the base receiver class but it really doesn't have 
 *  anything to do with receiving so we renamed it and made it a standalone function.
 */
void IRLib_NoOutput(void);

/* This function is called by both the 50us and PCI ISR in one of two circumstances:
 * 1) The SPACE was long enough that we are sure the frame is over and ready to process.
 * 2) The buffer overflowed we have to quit. The parameter is for debugging purposes only.
 */
void IRLib_IRrecvComplete(uint8_t Reason);

#endif //IRLibRecvBase_h