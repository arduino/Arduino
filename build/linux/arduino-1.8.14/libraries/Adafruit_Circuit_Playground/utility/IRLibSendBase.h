/* IRLibSendBase.h
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
#ifndef IRLIBSENDBASE_H
#define IRLIBSENDBASE_H

#include "IRLibProtocols.h"

class IRsendBase {
public:
  IRsendBase();
  void sendGeneric(uint32_t data,  uint8_t numBits, uint16_t headMark, uint16_t headSpace, 
                   uint16_t markOne, uint16_t markZero, uint16_t spaceOne, uint16_t spaceZero, 
				   uint8_t kHz, bool stopBits, uint32_t maxExtent=0);
protected:
  void enableIROut(uint8_t khz);
  void mark(uint16_t usec);
  void space(uint16_t usec);
  uint32_t extent;
  uint8_t onTime,offTime,iLength;//used by bit-bang output.
};

#endif	//IRLIBSENDBASE_H
 