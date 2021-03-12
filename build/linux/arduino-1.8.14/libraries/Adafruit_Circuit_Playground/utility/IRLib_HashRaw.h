/* IRLib_P00_HashRaw.h
 * Part of IRLib Library for Arduino receiving, decoding, and sending
 * infrared signals. See COPYRIGHT.txt and LICENSE.txt for more information.
 */
/*
 * If you have a protocol which is unsupported by this library, you can still receive
 * and transmit the data. You can store the raw data values in a buffer and retransmit the 
 * data exactly as you received it. Of course it takes a lot of memory to store such data
 * so it is inefficient but it is better than nothing.
 * If all you need to do is detect a unique value for an unsupported protocol and you do
 * not need to resend the data, you can use the hash code decoder. It looks at the
 * array of raw timing values and create a 32 bit value based on the data. It is
 * highly likely to be unique however you cannot reverse engineer the process.
 * You cannot re-create the original data stream for 32 bit hash code. 
 * This module also implements the raw send method. You have to have the original
 * timing values.
 */

#ifndef IRLIB_HASHRAW_H
#define IRLIB_HASHRAW_H
#define IR_SEND_RAW		case 0: IRsendRaw::send((uint16_t*)data,data2,khz); break;
#define IR_DECODE_HASH	if(IRdecodeHash::decode()) return true;
#ifdef IRLIB_HAVE_COMBO
	#define PV_IR_DECODE_HASH ,public virtual IRdecodeHash
	#define PV_IR_SEND_RAW   ,public virtual IRsendRaw
#else
	#define PV_IR_DECODE_HASH  public virtual IRdecodeHash
	#define PV_IR_SEND_RAW    public virtual IRsendRaw
#endif

#ifdef IRLIBSENDBASE_H
/* The first parameter to the "IRendRaw" method is a pointer to the first element of an
 * array of uint16_t values. These values are the raw timing values in microseconds. Note
 * it is possible to simply pass "(uint16_t*) &My_Decoder.decodeBuffer[1]" if you have just
 * received a code and wish to echo it. You have to point to the index "1" because index "0"
 * of that buffer contains the gap between successive frames data and it should be ignored.
 * If the frequency to be used in transmission is not specified, it defaults to 38kHz.
 */
class IRsendRaw: public virtual IRsendBase {
  public:
    void send(uint16_t *buf, uint8_t len, uint8_t khz) {
      enableIROut(khz);
      for (uint8_t i = 0; i < len; i++) {
        if (i & 1) {
          space(buf[i]);
        } 
        else {
          mark(buf[i]);
        }
      }
      space(0); // Just to be sure
    }
};
#endif  //IRLIBSENDBASE_H

#ifdef IRLIBDECODEBASE_H
/* This Hash decoder is based on IRhashcode Copyright 2010 Ken Shirriff
 * For details see http://www.righto.com/2010/01/using-arbitrary-remotes-with-arduino.html
 * Use FNV hash algorithm: http://isthe.com/chongo/tech/comp/fnv/#FNV-param
 * Converts the raw code values into a 32-bit hash code.
 * Hopefully this code is unique for each button.
 */
#define FNV_PRIME_32 16777619
#define FNV_BASIS_32 2166136261
// Compare two tick values, return 0 if v1 is lower, 1 if equal, and 2 if v2 is higher
#define TICKS_COMPARE(v1,v2) ( (v2< v1*0.8)?0:( (v1< v2*0.8)?2:1) )
class IRdecodeHash: public virtual IRdecodeBase {
  public:
    bool decode(void) {
      value = FNV_BASIS_32;
      for (int i = 1; i+2 < recvGlobal.decodeLength; i++) {
        value = (value * FNV_PRIME_32) ^ TICKS_COMPARE(recvGlobal.decodeBuffer[i], recvGlobal.decodeBuffer[i+2]);
      }
      protocolNum = UNKNOWN;
      bits= (recvGlobal.decodeLength-3)/2;//Estimated number of bits of unknown protocol
      //Note that value is always 32 bit hash code.
      return true;
    }
};
#endif //IRLIBDECODEBASE_H

#define IRLIB_HAVE_COMBO

#endif //IRLIB_HASHRAW_H
