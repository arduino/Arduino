/* IRLibDecodeBase.h 
 * Part of IRLib Library for Arduino receiving, decoding, and sending
 * infrared signals. See COPYRIGHT.txt and LICENSE.txt for more information.
 */
/*
 * This module contains the base classes for decoding. You will not create instances
 * of these classes, rather you will use them as base classes in creating derived
 * protocol specific decoders.
 */
#ifndef IRLIBDECODEBASE_H
#define IRLIBDECODEBASE_H
#include "IRLibGlobals.h"
#include "IRLibProtocols.h"

// Base class for decoding raw results
class IRdecodeBase {
public:
  IRdecodeBase(void);
  uint8_t protocolNum;              // NEC, SONY, RC5, UNKNOWN etc.
  uint32_t value;                   // Decoded value
  uint16_t address;                 // Additional data for protocols using more than 32 bits
  uint8_t bits;                     // Number of bits in decoded value
  bool ignoreHeader;                // Relaxed header detection allows AGC to settle
  bool decodeGeneric(uint8_t expectedLength, uint16_t headMark, uint16_t headSpace,
                     uint16_t markData, uint16_t spaceOne, uint16_t spaceZero);
  void dumpResults(bool verbose=true);//full dump of all timing values
  bool MATCH(int16_t val,int16_t expected);
  bool ABS_MATCH(int16_t val,int16_t expected,int16_t tolerance);
protected:
  virtual void resetDecoder(void);   // Initializes the decoder
  bufIndex_t offset;                 // Index into decodeBuffer used various places
};

// Base class used by RC5 and RC6 protocols
class IRdecodeRC: public virtual IRdecodeBase {
public:
  enum RCLevel {MARK, SPACE, ERROR};//used by decoders for RC5/RC6
  RCLevel getRClevel(uint8_t *used, const uint16_t t1);
protected:
  uint8_t nBits;
  uint8_t used;
  uint32_t data;
};

/* The remainder of this file a variety of default values and macros which are 
 * used internally. They used to be in a separate file IRLibMatch.h but it's easier
 * to include them here.  You need not worry about them unless you are creating 
 * your own decoding routines. See the documentation how to implement new protocols
 * for a more detailed explanation of these definitions and routines.
 */

/*
 * Originally all timing comparisons for decoding were based on a percent of the
 * target value. However when target values are relatively large, the percent tolerance
 * is too much.  In some instances an absolute tolerance is needed. In order to maintain
 * backward compatibility, the default will be to continue to use percent. If you wish 
 * to default to an absolute tolerance, you should comment out the line below.
 */
#define IRLIB_USE_PERCENT

/*
 * These are some miscellaneous definitions that are needed by the decoding routines. 
 * You need not include this file unless you are creating custom decode routines 
 * which will require these macros and definitions. Even if you include it, you probably
 * don't need to be intimately familiar with the internal details.
 */

#define TOPBIT 0x80000000
#define PERCENT_TOLERANCE 25  // percent tolerance in measurements
#define DEFAULT_ABS_TOLERANCE 75 //absolute tolerance in microseconds
/* If you insert #define IRLIB_TRACE in your sketch before including this file,
 * various debugging routines will be enabled in the dumpResults() method.
 */
#ifdef IRLIB_TRACE
void IRLIB_ATTEMPT_MESSAGE(const __FlashStringHelper * s) {Serial.print(F("Attempting ")); Serial.print(s); Serial.println(F(" decode:"));};
void IRLIB_TRACE_MESSAGE(const __FlashStringHelper * s) {Serial.print(F("Executing ")); Serial.println(s);};
uint8_t IRLIB_REJECTION_MESSAGE(const __FlashStringHelper * s) { Serial.print(F(" Protocol failed because ")); Serial.print(s); Serial.println(F(" wrong.")); return false;};
uint8_t IRLIB_DATA_ERROR_MESSAGE(const __FlashStringHelper * s, uint8_t index, uint16_t value, uint16_t expected) {  
 IRLIB_REJECTION_MESSAGE(s); Serial.print(F("Error occurred with decodeBuffer[")); Serial.print(index,DEC); Serial.print(F("]=")); Serial.print(value,DEC);
 Serial.print(F(" expected:")); Serial.println(expected,DEC); return false;
};
#define RAW_COUNT_ERROR IRLIB_REJECTION_MESSAGE(F("number of raw samples"));
#define HEADER_MARK_ERROR(expected) IRLIB_DATA_ERROR_MESSAGE(F("header mark"),1,recvGlobal.decodeBuffer[1],expected);
#define HEADER_SPACE_ERROR(expected) IRLIB_DATA_ERROR_MESSAGE(F("header space"),2,recvGlobal.decodeBuffer[2],expected);
#define DATA_MARK_ERROR(expected) IRLIB_DATA_ERROR_MESSAGE(F("data mark"),offset,recvGlobal.decodeBuffer[offset],expected);
#define DATA_SPACE_ERROR(expected) IRLIB_DATA_ERROR_MESSAGE(F("data space"),offset,recvGlobal.decodeBuffer[offset],expected);
#define TRAILER_BIT_ERROR(expected) IRLIB_DATA_ERROR_MESSAGE(F("RC6 trailer bit length"),offset,recvGlobal.decodeBuffer[offset],expected);
#define BIT_COUNT_ERROR IRLIB_REJECTION_MESSAGE(F("invalid number of bits"));
#else 
#define IRLIB_ATTEMPT_MESSAGE(s)
#define IRLIB_TRACE_MESSAGE(s)
#define IRLIB_REJECTION_MESSAGE(s) false
#define IRLIB_DATA_ERROR_MESSAGE(s,i,v,e) false
#define RAW_COUNT_ERROR false
#define HEADER_MARK_ERROR(expected) false
#define HEADER_SPACE_ERROR(expected) false
#define DATA_MARK_ERROR(expected) false
#define DATA_SPACE_ERROR(expected) false
#define TRAILER_BIT_ERROR(expected) false
#define BIT_COUNT_ERROR false
#endif

#endif	//IRLIBDECODEBASE_H
 