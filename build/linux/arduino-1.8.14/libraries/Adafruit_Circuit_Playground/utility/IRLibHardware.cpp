/* IRLibHardware.cpp
 * Part of IRLib Library for Arduino receiving, decoding, and sending
 * infrared signals. See COPYRIGHT.txt and LICENSE.txt for more information.
 *
 * We need a way for the sending object to communicate with the receiving object.
 * Sending an IR signal can disable further receiving because the timer needed for the 50us
 * interrupts is used to modulate the frequency of the PWM output signal. We need a flag
 * for the send object to inform you receive object that this occurred.
 *
 * Some applications do sending only and would only require you to include IRLibSendBase.h 
 * while others only do receiving/decoding and would include IRLibRecvBase.h but not
 * IRLibSendBase.h. The only include file that is used by both sending and receiving is
 * the IRLibHardware.h which was formerly called IRLibTimer.h. Therefore we put the flag
 * in this newly created IRLibHardware.cpp module. That way a send only can put the flag
 * here whether or not there is a receiver. Similarly the receiver can check the flag
 * whether or not there is a sender.
 *
 * The below is a global flag IRLib_didIROut that gets set true with every call to enableIROut.
 * Then any call to IRrecv::enableIRIn checks this to see if it needs to restart the ISR. 
 * Regardless IRrecv::enableIRIn will always reset it it false for the next time.
 * Note as always if you try to send while in the middle of receiving, the partially received
 * data is lost. If the application wishes to create a system where the sending waits until
 * the receiver is idle, the programmer can implement such a system themselves and deal with
 * the consequences.
 *
 * The bottom line is the application no longer needs to figure out if it needs to
 * call enableIRIn or the "resume" method. There is no more "resume". You always do
 * enableIRIn after every decode and the system handles it.
 */

#if !defined(ARDUINO_NRF52840_CIRCUITPLAY)

#include "IRLibHardware.h"
uint8_t IRLib_didIROut=false;

#endif
