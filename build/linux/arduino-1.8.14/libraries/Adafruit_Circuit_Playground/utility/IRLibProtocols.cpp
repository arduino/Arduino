/* IRLibProtocols.cpp 
 * Part of IRLib Library for Arduino receiving, decoding, and sending
 * infrared signals. See COPYRIGHT.txt and LICENSE.txt for more information.
 */
/*
 * This module enumerates the various supported protocols and defines a program memory
 * string used by the dump routines or your sketches to display the name of a protocol.
 * It is used by both Send and Decode sections of the code but not Receive.
 */

#if !defined(ARDUINO_NRF52840_CIRCUITPLAY)

#include "IRLibProtocols.h"

/*
 * Returns a pointer to a flash stored string that is the name of the protocol received. 
 */
const __FlashStringHelper *Pnames(uint8_t type) {
  if(type>89) return F("Unsup");
  if(type>LAST_PROTOCOL) type=UNKNOWN;
  // You can add additional strings before the entry for hash code.
  const __FlashStringHelper *Names[LAST_PROTOCOL+1]={
	F("Unknown"),F("NEC"),F("Sony"),F("RC5"),F("RC6"),F("Panasonic Old"),F("JVC"),
	F("NECx"),F("Samsung36"),F("G.I.Cable"),F("DirecTV"),F("rcmm"),F("CYKM")
  //,F("Additional_13")//expand or edit these
  };
  return Names[type];
};

#endif
