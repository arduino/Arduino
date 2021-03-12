/* IRLibProtocols.h
 * Part of IRLib Library for Arduino receiving, decoding, and sending
 * infrared signals. See COPYRIGHT.txt and LICENSE.txt for more information.
 */
/*
 * This module enumerates the various supported protocols and defines a program memory
 * string used by the dump routines or your sketches to display the name of a protocol.
 * It is used by both Send and Decode sections of the code but not Receive.
 */
#ifndef IRLIBPROTOCOLS_H
#define IRLIBPROTOCOLS_H
#include <Arduino.h>

#define UNKNOWN 0
#define NEC 1
#define SONY 2
#define RC5 3
#define RC6 4
#define PANASONIC_OLD 5
#define JVC 6
#define NECX 7
#define SAMSUNG36 8
#define GICABLE 9 
#define DIRECTV 10
#define RCMM 11
#define CYKM 12
//#define ADDITIONAL_13 13	//add additional protocols here
//#define ADDITIONAL_14 14
#define LAST_PROTOCOL 12 //Be sure to update this when adding protocols

/*
 * Returns a pointer to a flash stored string that is the name of the protocol received. 
 */
const __FlashStringHelper *Pnames(uint8_t Type); 

/*
 * Miscellaneous values used by both Send and Decode modules
 */
#define TOPBIT 0x80000000

// Decoded value for NEC and others when a repeat code is received or to be sent
#define REPEAT_CODE 0xffffffff

#endif	//IRLIBPROTOCOLS_H
