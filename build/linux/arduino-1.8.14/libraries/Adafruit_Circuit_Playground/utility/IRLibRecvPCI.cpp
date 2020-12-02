/* IRrecvPCI.cpp
 * Part of IRLib Library for Arduino receiving, decoding, and sending
 * infrared signals. See COPYRIGHT.txt and LICENSE.txt for more information.
 *
 * This module implements the IRrecvPCI receiver class which uses pin change interrupts to
 * poll the input pin. This class gives more accurate results than the 50us timer based
 * IRrecv but it has other limitations. It uses the Arduino "attachInterrupt()" function
 * which can conflict with other libraries. Also unless you use an external buffer and
 * enable auto resume this receiver occasionally fails to receive the second of 2 quickly
 * sent frames. If you do not have sufficient RAM for a second buffer you should consider
 * using the other two available receiver classes.
 *
 * This receiver is based in part on Arduino firmware for use with AnalysIR IR signal analysis
 * software for Windows PCs. Many thanks to the people at http://analysir.com for their 
 * assistance in developing this section of code.
 */

#include "IRLibRecvPCI.h"
#include "IRLibHardware.h" //needed for IRLib_didIROut

void IRrecvPCI_Handler();//prototype for interrupt handler

/* Note that the constructor is passed the interrupt number rather than the pin number.
 * WARNING: These interrupt numbers which are passed to “attachInterrupt()” are not
 * necessarily identical to the interrupt numbers in the datasheet of the processor chip 
 * you are using. Rather it is a numbering system to the “attachInterrupt()” Arduino
 * function. For more information on attachInterrupt see
 * http://arduino.cc/en/Reference/AttachInterrupt 
 */
IRrecvPCI::IRrecvPCI(uint8_t pin) {
  init();
  intrNum=digitalPinToInterrupt(pin);
  recvGlobal.recvPin=pin;
}

/* Initializes receiving and attaches the pin change interrupt handler. Call this to
 * initialize it again to resume receiving after completing the decoding. Previous versions
 * of IRLib had a "resume" method that you should use this in either initializing or resuming.
 */
void IRrecvPCI::enableIRIn(void) {
//See comments on IRrecv::enableIRIn in "IRLibRecv.cpp" for explanation of this logic
  if(recvGlobal.newDataAvailable) 
    return;
  recvGlobal.decoderWantsData=true;//otherwise he wouldn't have called
  if( (recvGlobal.currentState==STATE_FINISHED) || IRLib_didIROut ) {
    IRrecvBase::enableIRIn();
    recvGlobal.timer=micros();
    attachInterrupt(intrNum, IRrecvPCI_Handler, CHANGE);
  }
};

/* Even when not sampling inputs and recording pulse timing, the ISR remains active
 * continues to interrupt every 50us however it remains in a do-nothing state. If 
 * the user wants to truly shut down the ISR they can call this method.
 */
void IRrecvPCI::disableIRIn(void) {
  detachInterrupt(intrNum);
  IRrecvBase::disableIRIn();
}

/* Returns true if a frame of data is available in the buffer. Most of the
 * handling is done by the base method. Because the ISR only is active when the pin
 * is changing, it may not recognize the long gap at the end of the frame so we need to
 * test to see if we had a long gap. Because the ISR is active, we need to ensure
 * that it doesn't change any variables while we are in the middle of accessing them.
 * Unfortunately the ATOMIC_BLOCK macro that we used to use is not supported for 
 * SAMD 21 platforms so we have to use "noInterrupts();" and "interrupts();" 
 * This is only necessary for multibyte variables.
 */
bool IRrecvPCI::getResults(void) {
  if(recvGlobal.newDataAvailable) {
    IRrecvBase::getResults();
    return true;
  }
  //ISR hasn't detected end of frame so if running we will take a peek
  if(recvGlobal.currentState==STATE_RUNNING) {
    //Only check for timeout if it is a SPACE
    if(digitalRead(recvGlobal.recvPin)) {//pin high means SPACE
      uint32_t changeTime; //time of the last change
      noInterrupts ();  //Ensure atomic access of volatile variable
      changeTime=recvGlobal.timer;
      interrupts(); //restore interrupts
      if( (micros()-changeTime) > recvGlobal.frameTimeout) {
        IRLib_IRrecvComplete(3);
        IRrecvBase::getResults();
        return true;
      }
    }
  }
  return false;
};

/* This is the interrupt handler used by this class. It is called every time the input
 * pin changes from high to low or from low to high. The initial state of the state machine
 * is STATE_READY_TO_BEGIN. It waits until it sees a MARK before it switches to
 * STATE_RUNNING. Each subsequent interrupt it computes the time since the previous 
 * interrupt. If it notices a SPACE is especially long then it calls IRLib_IRrecvComplete
 * which sets the proper flags to say that we had received data and implements
 * auto resume if enabled. The state STATE_FINISHED means that interrupts are continuing
 * however the receiver isn't ready for more data.
 */
void IRrecvPCI_Handler(){ 
  uint32_t volatile changeTime=micros();
  uint32_t deltaTime=changeTime-recvGlobal.timer;
  switch(recvGlobal.currentState) {
    case STATE_FINISHED: return;
    case STATE_RUNNING:
      IRLib_doBlink();
      if( !(recvGlobal.recvLength & 1) ){
        if (deltaTime>recvGlobal.frameTimeout) {
          IRLib_IRrecvComplete(1);//all finished, reset and possibly do auto resume
          return;//don't record final space
        }
      }
      break;
    case STATE_READY_TO_BEGIN:
      if(digitalRead(recvGlobal.recvPin)) {//pin high means SPACE
        return;//don't start until we get a MARK
      } else {
        recvGlobal.currentState=STATE_RUNNING;
      }
      break;
  };
  recvGlobal.recvBuffer[recvGlobal.recvLength]=deltaTime;
  recvGlobal.timer=changeTime;
  if(++recvGlobal.recvLength>=RECV_BUF_LENGTH) {//buffer overflows so we quit
    IRLib_IRrecvComplete(2);
  }
}

