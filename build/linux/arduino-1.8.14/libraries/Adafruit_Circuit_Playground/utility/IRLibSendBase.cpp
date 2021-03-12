/* IRLibSendBase.cpp
 * Part of IRLib Library for Arduino receiving, decoding, and sending
 * infrared signals. See COPYRIGHT.txt and LICENSE.txt for more information.
 */
/*
 * This module contains the base classes for sending. You will not create instances
 * of these classes, rather you will use them as base classes in creating derived
 * protocol specific decoders.  Each protocol specific send class begins 
 * by calling enableIROut(uint8_t kHz) to set the carrier frequency.
 * It then calls mark(int usec) and space(inc usec) to transmit marks and
 * spaces of varying length of microseconds in the manner which the protocol defines.
 */

#if !defined(ARDUINO_NRF52840_CIRCUITPLAY) 

#include "IRLibSendBase.h"
#include "IRLibHardware.h"

/*
 * Most of the protocols have a header consisting of a mark/space of a particular length followed by 
 * a series of variable length mark/space signals.  Depending on the protocol they very the lengths of the 
 * mark or the space to indicate a data bit of "0" or "1". Most also end with a stop bit of "1".
 * The basic structure of the sending and decoding these protocols led to lots of redundant code. 
 * Therefore I have implemented generic sending and decoding routines. You just need to pass a bunch of customized 
 * parameters and it does the work. This reduces compiled code size with only minor speed degradation. 
 * You may be able to implement new protocols by simply passing the proper values to these generic routines.
 * The decoding routines do not encode stop bits. So you have to tell this routine whether or not to send one.
 * Some protocols have a fixed amount of space between frames while others require that the entire frame
 * be a particularly length despite the fact that the data transmission time may be veritable. Pass this
 * frame length of time the parameter maxExtent. It's default value is zero.
 */
void IRsendBase::sendGeneric(uint32_t data, uint8_t numBits, uint16_t headMark, uint16_t headSpace, 
                             uint16_t markOne, uint16_t markZero, uint16_t spaceOne, uint16_t spaceZero, 
							 uint8_t kHz, bool useStop, uint32_t maxExtent) {
  extent=0;
  data = data << (32 - numBits);
  enableIROut(kHz);
//Some protocols do not send a header when sending repeat codes. So we pass a zero value to indicate skipping this.
  if(headMark) mark(headMark); 
  if(headSpace) space(headSpace);
  for (uint8_t i = 0; i <numBits; i++) {
    if (data & TOPBIT) {
      mark(markOne);  space(spaceOne);
    } 
    else {
      mark(markZero);  space(spaceZero);
    }
    data <<= 1;
  }
  if(useStop) mark(markOne);   //stop bit of "1"
  if(maxExtent) {
#ifdef IRLIB_TRACE
    Serial.print("maxExtent="); Serial.println(maxExtent);
	Serial.print("extent="); Serial.println(extent);
	Serial.print("Difference="); Serial.println(maxExtent-extent);
#endif
	space(maxExtent-extent); 
	}
	else space(spaceOne);
};



void IRsendBase::enableIROut(uint8_t khz) {
//NOTE: the comments on this routine accompanied the original early version of IRremote library
//which only used TIMER2. The parameters defined in IRLibTimer.h may or may not work this way.
  // Enables IR output.  The khz value controls the modulation frequency in kilohertz.
  // The IR output will be on pin 3 (OC2B).
  // This routine is designed for 36-40KHz; if you use it for other values, it's up to you
  // to make sure it gives reasonable results.  (Watch out for overflow / underflow / rounding.)
  // TIMER2 is used in phase-correct PWM mode, with OCR2A controlling the frequency and OCR2B
  // controlling the duty cycle.
  // There is no prescaling, so the output frequency is 16MHz / (2 * OCR2A)
  // To turn the output on and off, we leave the PWM running, but connect and disconnect the output pin.
  // A few hours staring at the ATmega documentation and this will all make sense.
  // See my Secrets of Arduino PWM at http://www.righto.com/2009/07/secrets-of-arduino-pwm.html for details.
  
  // Disable the Timer2 Interrupt (which is used for receiving IR)
 IRLib_didIROut=true; //Tell the receiver we probably trashed his timer settings
 IR_RECV_DISABLE_INTR; //Timer2 Overflow Interrupt    
 pinMode(IR_SEND_PWM_PIN, OUTPUT);  
 digitalWrite(IR_SEND_PWM_PIN, LOW); // When not sending PWM, we want it low    
 IR_SEND_CONFIG_KHZ(khz);
 }

IRsendBase::IRsendBase () {
 pinMode(IR_SEND_PWM_PIN, OUTPUT);  
 digitalWrite(IR_SEND_PWM_PIN, LOW); // When not sending PWM, we want it low    
}

//The Arduino built in function delayMicroseconds has limits we wish to exceed
//Therefore we have created this alternative
void  IRLibDelayUSecs(uint16_t time) {
  if(time){if(time>16000) {delayMicroseconds(time % 1000); delay(time/1000); } else delayMicroseconds(time);};
}

void IRsendBase::mark(uint16_t time) {
 IR_SEND_PWM_START;
 IR_SEND_MARK_TIME(time);
 extent+=time;
}

void IRsendBase::space(uint16_t time) {
 IR_SEND_PWM_STOP;
 IRLibDelayUSecs(time);
 extent+=time;
}


#endif //!defined(__NRF52__) 
