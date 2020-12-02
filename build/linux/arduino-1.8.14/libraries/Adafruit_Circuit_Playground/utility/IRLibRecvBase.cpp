/* IRrecvBase.cpp
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

#if !defined(ARDUINO_NRF52840_CIRCUITPLAY)

#include "IRLibRecvBase.h"
#include "IRLibHardware.h"

/* This structure contains all of the global variables used by the ISRs to communicate
 * with the receiver and decoder objects. You cannot pass parameters to an ISR so
 * these values must be global. The fields are defined in IRLibRecvBase.h
 */
recvGlobal_t recvGlobal;

// The base constructor receives the pin number
IRrecvBase::IRrecvBase(uint8_t recvPin) {
  recvGlobal.recvPin = recvPin;
  init();
}

// Initialization common to all three receiver classes
void IRrecvBase::init(void) {
//These first two lines would normally be done by the decoder
//however in rare circumstances there is no decoder.
  recvGlobal.decoderWantsData=false; //turned on by enableIRIn.
  recvGlobal.decodeBuffer=recvGlobal.recvBuffer;//default buffer
	recvGlobal.enableAutoResume=false;
  recvGlobal.frameTimeout=DEFAULT_FRAME_TIMEOUT;
  recvGlobal.frameTimeoutTicks=recvGlobal.frameTimeout/USEC_PER_TICK;
  markExcess=DEFAULT_MARK_EXCESS;
  recvGlobal.newDataAvailable=false;
  recvGlobal.enableBlinkLED=false;
  recvGlobal.currentState=STATE_FINISHED;//i.e. Not running.
}

// Turn on or off a blinking LED which indicates signal received. Usually pin 13.
void blink13(bool enableBlinkLED){
#if (BLINKLED>0)
  pinMode(BLINKLED,OUTPUT);
  recvGlobal.enableBlinkLED=enableBlinkLED;
#endif
}

/* Any receiver class must implement a getResults method that will return true when 
 * a complete frame of data has been received. When your getResults determines that 
 * the frame is complete, it must guarantee that there will be no further changes to
 * the data in the buffer or the length value. It can do that by either disabling 
 * interrupts or putting the ISR in a state that ensures it will not
 * change those values. Then it must then call IRrecvBase::getResults. This base method 
 * will then will perform some math on the values and copy them to the decodeBuffer.
 * Some receivers provide results in recvBuffer measured in ticks of some number of
 * microseconds while others return results in actual microseconds. If you use ticks then
 * you should pass a multiplier value in timePerTicks.
 * NOTE: Only call the base method if newDataAvailable is true.
 */
bool IRrecvBase::getResults(const uint16_t timePerTick) {
//Conceptually the loop below copies data from the receiver buffer to the decode buffer
//while performing some math. In some instances, the source and destination are the same.
//The decoder has already set up decodeBuffer to point to the proper destination.
//Here we need to figure out the source. If didAutoResume is true then the ISR has already
//copied the data to decodeBuffer so it is both source and destination. In all
//other circumstances the source is always recvGlobal.recvBuffer.
  recvGlobal.newDataAvailable=false;
  volatile uint16_t *Source;
  //DEBUG_VALUE("recvGlobal.didAutoResume",recvGlobal.didAutoResume);
  if(recvGlobal.didAutoResume) {
    Source=recvGlobal.decodeBuffer;
    recvGlobal.didAutoResume=false;
  } else {
    Source=recvGlobal.recvBuffer;
    recvGlobal.decodeLength=recvGlobal.recvLength;//if auto resumed, was already copied
  }
//If the receiver counts time intervals rather than actual microseconds we will multiply
//the data by timePerTick. It also adjusts the data by adding or subtracting the
//markExcess value. See the documentation on markExcess for details.
  for(uint8_t i=0; i<recvGlobal.decodeLength; i++) {
    recvGlobal.decodeBuffer[i]=Source[i]*timePerTick + ( (i % 2)? -markExcess:markExcess);
  }
  //Now that the decoder has its data it doesn't want any more until it tells you.
  //It will do so by calling enableIRIn.
  recvGlobal.decoderWantsData=false;
  return true;
}

/* The user calls enableIRIn each time it is ready to receive data. Previously
 * this was only used to initialize the receiver once and subsequent calls were made
 * to a method called "resume". However it was confusing because you had to call
 * enableIRIn after a send because any sending would disable IRIn. It's simpler just to
 * always use enableIRIn even though parts of it are slightly redundant.
 * The interrupt driven receivers call this before enabling interrupts.
 * See the comments on IRrecv::enableIRIn() in IRLibRecv.cpp regarding auto resume.
 */
void IRrecvBase::enableIRIn(void) { 
//some IR receiver datesheets recommend pull-up resistors
  pinMode(recvGlobal.recvPin, INPUT_PULLUP);
  recvGlobal.recvLength = 0;
  recvGlobal.currentState = STATE_READY_TO_BEGIN;
  IRLib_didIROut=false;//We reinitialized so reset until somebody does more output.
}

/* Even when not receiving data or waiting to receive data, the ISR may remain active
 * but remains in a do-nothing state. If the user wants to truly shut down the ISR
 * they can call this method. The derived method should disable the ISR and then call 
 * this base method to the turn everything off.
 */
void IRrecvBase::disableIRIn(void) {
  recvGlobal.decoderWantsData=false;
  recvGlobal.didAutoResume=false;
  recvGlobal.currentState=STATE_FINISHED;//i.e. Not running.
}

/*
 * Normally recvGlobal.decodeBuffer points to recvGlobal.recvBuffer and therefore
 * decoding uses the same buffer as receiving. However you may want to resume 
 * receiving while still decoding. To do so must specify a separate buffer for decoding.
 * You will declare the buffer as "uint16_t myBuffer[RECV_BUF_LENGHT];" in your sketch
 * then pass its address using the method below. Then IRrecvBase::getResults() will copy 
 * timing values from its buffer to yours. The receiver will then automatically resume.
 * The receiver will not overwrite your buffer unless you have called enableIRIn()
 * to tell it that you have finished your decoding. In other words auto resume will only
 * occur once until you again call enableIRIn().
 */
void IRrecvBase::enableAutoResume(uint16_t *P){
  recvGlobal.decodeBuffer=(volatile uint16_t*)P;
  recvGlobal.enableAutoResume=true;
};

// This had to be a method so that IRrecv::setFrameTimeout can compute 
// frameTimeoutTicks.
void IRrecvBase::setFrameTimeout(uint16_t frameTimeout) {
  recvGlobal.frameTimeout=frameTimeout;
}

/*********************
 *
 * The remaining functions below are not part of any class or object. They are global
 * so they can be called by the ISRs or for other reasons are not really tied to any
 * class or object.
 *
 *********************/

/*
 * This function is called by both the 50us and PCI ISR in one of two circumstances:
 * 1) The SPACE was long enough that we are sure the frame is over and ready to process.
 * 2) The buffer overflowed we have to quit. The parameter is for debugging purposes only.
 */
void IRLib_IRrecvComplete(uint8_t Reason) {
  // Here we are finished. Let the world know there is new data available.
  recvGlobal.newDataAvailable=true;
  recvGlobal.currentState=STATE_FINISHED;//this essentially pauses the receiver ISR
  //Now we need to see if we want to auto resume. We can only do that if it is enabled and
  //if the user is finished using the buffer from the previous capture and wants more data.
  //DEBUG_VALUE ("Reason completed", Reason)
  if (recvGlobal.enableAutoResume && recvGlobal.decoderWantsData) {
		//Here we do the actual auto resume. We will copy the data using memcpy because it
    //should be very quick. Any calculations will be handled by the getResults method but
    //not here.
    memcpy((void *)recvGlobal.decodeBuffer, (const void*)recvGlobal.recvBuffer,recvGlobal.recvLength*sizeof(uint16_t));
		recvGlobal.decodeLength=recvGlobal.recvLength;
		// We have just copied the data to the decoder so it's not going to want more until
		// it tells us that it is ready for more.
		recvGlobal.decoderWantsData=false;
    // Tell getResults that we auto resumed therefore the data has been copied but
    // still needs the math done.
    recvGlobal.didAutoResume=true;
		// Now we need to reset the index to the beginning and restart the state machine.
		recvGlobal.recvLength=0;
    //While we were doing the copy, the 50 us interrupt continued but the state machine
    //was paused in the STATE_FINISHED. Now we actually turn it back on till you get to
    //actually receive data.
    recvGlobal.currentState= STATE_READY_TO_BEGIN;
  }
}

/* If your hardware is set up to do both output and input but your particular sketch
 * doesn't do any output, this method will ensure that your output pin is low
 * and doesn't turn on your IR LED or any output circuit.
 */
void IRLib_NoOutput (void) {
#if defined(IR_SEND_PWM_PIN)
 pinMode(IR_SEND_PWM_PIN, OUTPUT);  
 digitalWrite(IR_SEND_PWM_PIN, LOW); // When not sending PWM, we want it low    
#endif
}
	
/* Do the actual blinking off and on of the indicator LED. Called by the various
 * receiver ISRs
 */
void IRLib_doBlink(void) {
  if (recvGlobal.enableBlinkLED) {
    if(recvGlobal.recvLength & 1) {
      BLINKLED_ON();  // turn pin 13 LED on
    } 
    else {
      BLINKLED_OFF();  // turn pin 13 LED off
    }
  }
}


#endif //!defined(__NRF52__) 
