/* IRLib_P04_RC6.h
 * Part of IRLib Library for Arduino receiving, decoding, and sending
 * infrared signals. See COPYRIGHT.txt and LICENSE.txt for more information.
 */
/*
 * The RC6 protocol was invented by Phillips but is used by wide variety of manufacturers.
 * Like the Phillips RC5 protocol it uses phased coding however the phase is backwards
 * from RC5. With RC6 a space/mark pair indicates "0" and a mark/space indicates a "1".
 * in the data. The protocol uses 36 kHz modulation however 38 kHz receivers can typically 
 * receive the codes okay.
 * The protocol consists of a header followed by a "1" bit which is always on and we do not 
 * encode. This is followed by a 3 bit OEM code that is usually 0 or 6. This is followed by
 * special trailer bit whose time is twice that of normal. It all but the 32-bit version,
 * the trailer bit also serves as a toggle bit. The toggle bit changes if the button was 
 * pressed and released however remains the same if the button was held. You must toggle 
 * this bit yourself when sending data and account for it when interpreting decoded values. 
 * Next are the actual data bits.  Varieties include 16, 20, 24, and 32 bit versions. 
 * Because we encode the 3 OEM bits and the toggle bit, our actual bit lengths are 20, 24, 
 * and 28 for the first three varieties. The 32-bit variety is different because it uses 
 * OEM bits of 011 followed by a 0 in what is traditionally the toggle bit.
 * Because the 32-bit version is invariant in these first 4 bits, we do not encode them
 * and presume they are always "0110". The 32-bit version uses the highest order of the
 * data bits as a toggle bit.  At this time the 16-bit version always uses OEM = 0 and 
 * other known varieties always use OEM = 6 but we will only make that presumption for the
 * 32-bit version.  Encoding the OEM bits allows for other OEM values to be used without 
 * modifying the library. If we ever encounter a 32-bit version with an OEM other than 6 
 * it will require a special modified encoder and decoder.
 * Here is a description of known varieties:
 * RC6-0-16: Original version by Phillips.      16 bits, we encode 20, toggle is 0x00010000
 * RC6-6-20: Used by some Sky and Sky+ remotes. 20 bits, we encode 24, toggle is 0x00100000
 * RC6-6-24: Also known as "Replay" protocol.   24 bits, we encode 28, toggle is 0x01000000
 * RC6-6-32: Also known as "MCE" protocol.      32 bits, we encode 32, toggle is 0x00008000
 */
#ifndef IRLIB_PROTOCOL_04_H
#define IRLIB_PROTOCOL_04_H
#define IR_SEND_PROTOCOL_04		case 04: IRsendRC6::send(data,data2); break;
#define IR_DECODE_PROTOCOL_04	if(IRdecodeRC6::decode()) return true;
#ifdef IRLIB_HAVE_COMBO
	#define PV_IR_DECODE_PROTOCOL_04 ,public virtual IRdecodeRC6
	#define PV_IR_SEND_PROTOCOL_04   ,public virtual IRsendRC6
#else
	#define PV_IR_DECODE_PROTOCOL_04  public virtual IRdecodeRC6
	#define PV_IR_SEND_PROTOCOL_04    public virtual IRsendRC6
#endif
#define RC6_HDR_MARK	2666
#define RC6_HDR_SPACE	889
#define RC6_T1		444

#ifdef IRLIBSENDBASE_H
class IRsendRC6: public virtual IRsendBase {
  public:
    void send(uint32_t data, uint8_t nBits=16) {
      if (nBits==0) nBits=16;
      enableIROut(36);
      uint64_t bigData = data;
      if (nBits==32) {
        bigData+=0xc00000000ull;//add OEM value
        nBits=36;
      };
      bigData=bigData << (64 - nBits);
      extent=0;
      mark(RC6_HDR_MARK); space(RC6_HDR_SPACE);
      mark(RC6_T1);  space(RC6_T1);// start bit "1"
      uint16_t t;
      for (uint8_t i = 0; i < nBits; i++) {
        if (i == 3) {
          t = 2 * RC6_T1;       // double-wide trailer bit
        } else {
          t = RC6_T1;
        }
        if (bigData & 0x8000000000000000ull) {
          mark(t); space(t);//"1" is a Mark/space
        } else {
          space(t); mark(t);//"0" is a space/Mark
        }
        bigData <<= 1;
      }
      space(107000-extent); // Turn off at end
    }
};
#endif  //IRLIBSENDBASE_H

#ifdef IRLIBDECODEBASE_H

/* Note this decoder is a derived class from the IRdecodeRC base 
 * class rather than IRdecodeBase. The base class defines the 
 * method "getRClevel" which is common to both RC5 and RC6 protocols. 
 * It facilitates the decoding of phase encoded data. 
 */
class IRdecodeRC6: public virtual IRdecodeRC {
  public:
    virtual bool decode(void)  {
      IRLIB_ATTEMPT_MESSAGE(F("RC6"));
      resetDecoder();//This used to be in the receiver getResults.
      //Legal lengths range from 24 through 76 we went one bigger just in case.
      if( (recvGlobal.decodeLength < 23) ||  (recvGlobal.decodeLength > 77) )return RAW_COUNT_ERROR;
      // Initial mark
      if (!ignoreHeader) {
        if (!MATCH(recvGlobal.decodeBuffer[1], RC6_HDR_MARK)) return HEADER_MARK_ERROR(RC6_HDR_MARK);
      }
      if (!MATCH(recvGlobal.decodeBuffer[2], RC6_HDR_SPACE)) return HEADER_SPACE_ERROR(RC6_HDR_SPACE);
      offset=3;//Skip gap and header
      data = 0;
      used = 0;
      // Get start bit (1)
      if (getRClevel(&used, RC6_T1) != MARK) return DATA_MARK_ERROR(RC6_T1);
      if (getRClevel(&used, RC6_T1) != SPACE) return DATA_SPACE_ERROR(RC6_T1);
      for (nBits = 0; offset < recvGlobal.decodeLength; nBits++) {
        RCLevel levelA, levelB; // Next two levels
        levelA = getRClevel(&used, RC6_T1); 
        if (nBits == 3) {
          // T bit is double wide; make sure second half matches
          if (levelA != getRClevel(&used, RC6_T1)) return TRAILER_BIT_ERROR(RC6_T1);
        } 
        levelB = getRClevel(&used, RC6_T1);
        if (nBits == 3) {
          // T bit is double wide; make sure second half matches
          if (levelB != getRClevel(&used, RC6_T1)) return TRAILER_BIT_ERROR(RC6_T1);
        } 
        if (levelA == MARK && levelB == SPACE) { // reversed compared to RC5
          data = (data << 1) | 1;   // 1 bit
        } else if (levelA == SPACE && levelB == MARK) {
          data <<= 1; // zero bit
        } else {
          return DATA_MARK_ERROR(RC6_T1); 
        } 
      }
      // Success
      if (nBits==36) {
        nBits=32;//OEM & trailer bits are discarded on 32-bit version
      } else {
        //if ( (nBits!=20) || (nBits!=24) || (nBits!=28) ) return BIT_COUNT_ERROR;
      }
      bits = nBits;
      value = data;      
      protocolNum = RC6;
      return true;
    }
};
#endif //IRLIBDECODEBASE_H

#define IRLIB_HAVE_COMBO

#endif //IRLIB_PROTOCOL_04_H
