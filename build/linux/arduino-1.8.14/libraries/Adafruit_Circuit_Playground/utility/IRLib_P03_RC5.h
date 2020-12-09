/* IRLib_P03_RC5.h
 * Part of IRLib Library for Arduino receiving, decoding, and sending
 * infrared signals. See COPYRIGHT.txt and LICENSE.txt for more information.
 */
/*
 * The RC5 protocol was invented by Phillips but is used by wide variety of manufacturers.
 * It uses a phase encoding of data bits. A space/mark pair indicates "1"
 * and a mark/space indicates a "0". It begins with a single "1" bit which is not encoded
 * in the data. The second highest order data bit is a toggle bit that indicates individual
 * keypresses. You must toggle this bit yourself when sending data. The protocol uses 36 kHz
 * modulation however 38 kHz receivers can typically receive the codes okay.
 * There are three supported varieties as follows:
 * RC5          13 bits, 36 kHz (default, most common variety.
 * RC5-F7       14 bits, 36 kHz
 * RC5-F7-57    14 bits, 57 kHz
 * There's also a 19 bit variety called RC5x that is not supported here but may be a separate
 * module eventually.
 */

#ifndef IRLIB_PROTOCOL_03_H
#define IRLIB_PROTOCOL_03_H
#define IR_SEND_PROTOCOL_03		case 03: if(khz==38)khz=36; IRsendRC5::send(data,data2,khz); break;
#define IR_DECODE_PROTOCOL_03	if(IRdecodeRC5::decode()) return true;
#ifdef IRLIB_HAVE_COMBO
	#define PV_IR_DECODE_PROTOCOL_03 ,public virtual IRdecodeRC5
	#define PV_IR_SEND_PROTOCOL_03   ,public virtual IRsendRC5
#else
	#define PV_IR_DECODE_PROTOCOL_03  public virtual IRdecodeRC5
	#define PV_IR_SEND_PROTOCOL_03    public virtual IRsendRC5
#endif
#define RC5_T1		889

#ifdef IRLIBSENDBASE_H

class IRsendRC5: public virtual IRsendBase {
  public:
    void send(uint32_t data, uint8_t nBits=13, uint8_t kHz=36) {
      if(nBits==0)nBits=13;
      if(kHz==0)kHz=36;
      enableIROut(kHz);
      data = data << (32 - nBits);
      extent=0;
      mark(RC5_T1); // First start bit
//Note: Original IRremote library incorrectly assumed second bit was 
//always a "1". Bit patterns from this decoder are not backward compatible 
//with patterns produced by the original library. Uncomment the following two
//lines to maintain backward compatibility.
      //space(RC5_T1); // Second start bit
      //mark(RC5_T1); // Second start bit
      for (uint8_t i = 0; i < nBits; i++) {
        if (data & TOPBIT) {
          space(RC5_T1); mark(RC5_T1);// 1 is space, then mark
        } else {
          mark(RC5_T1);  space(RC5_T1);// 0 is mark, then space
        }
        data <<= 1;
      }
      space(114000-extent); // Turn off at end
    }
};
#endif  //IRLIBSENDBASE_H

#ifdef IRLIBDECODEBASE_H

/* Note this decoder is a derived class from the IRdecodeRC base class 
 * rather than IRdecodeBase. The base class defines the method "getRClevel" 
 * which is common to both RC5 and RC6 protocols. It facilitates the decoding 
 * of phase encoded data. 
 */

class IRdecodeRC5: public virtual IRdecodeRC {
  public:
    virtual bool decode(void) {
      IRLIB_ATTEMPT_MESSAGE(F("RC5"));
      resetDecoder();//This used to be in the receiver getResults.
      if (recvGlobal.decodeLength < 13) return RAW_COUNT_ERROR;
      offset = 1; // Skip gap space
      data = 0;
      used = 0;
      // Get start bits
      if (getRClevel(&used, RC5_T1) != MARK) return HEADER_MARK_ERROR(RC5_T1);
//Note: Original IRremote library incorrectly assumed second bit was always
// a "1". Bit patterns from this decoder are not backward compatible with 
// patterns produced by original library. Uncomment the following two lines
// to maintain backward compatibility.
      //if (getRClevel(&used, RC5_T1) != SPACE) return HEADER_SPACE_ERROR(RC5_T1);
      //if (getRClevel(&used, RC5_T1) != MARK) return HEADER_MARK_ERROR(RC5_T1);
      for (nBits = 0; offset < recvGlobal.decodeLength; nBits++) {
        RCLevel levelA = getRClevel(&used, RC5_T1); 
        RCLevel levelB = getRClevel(&used, RC5_T1);
        if (levelA == SPACE && levelB == MARK) {
          data = (data << 1) | 1;   // 1 bit
        } else if (levelA == MARK && levelB == SPACE) {
          data <<= 1;               // zero bit
        } else return DATA_MARK_ERROR(RC5_T1);
      }
      // Success
      bits = nBits;
      value = data;
      protocolNum = RC5;
      return true;
    }
};
#endif //IRLIBDECODEBASE_H

#define IRLIB_HAVE_COMBO

#endif //IRLIB_PROTOCOL_03_H
