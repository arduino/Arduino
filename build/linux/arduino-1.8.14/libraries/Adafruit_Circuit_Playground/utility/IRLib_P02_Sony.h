/* IRLib_P02_Sony.h
 * Part of IRLib Library for Arduino receiving, decoding, and sending
 * infrared signals. See COPYRIGHT.txt and LICENSE.txt for more information.
 */
/*
 * Sony is backwards from most protocols. It uses a variable length mark and a fixed length 
 * space rather than a fixed mark and a variable space. Our generic send will still work
 * however we need a custom decoding routine because it's difficult to get the generic
 * decoder to handle a variable length mark without cluttering up the code to much.
 * According to the protocol you must send Sony commands at least three times so we 
 * automatically do it here. Sony can be 8, 12, 15, or 20 bits in length.
 * The 8 bit version uses a shorter trailing space at the end. The signal is modulated 
 * at 40 kHz however most 38 kHz receivers are broad enough to receive it.
 */

#ifndef IRLIB_PROTOCOL_02_H
#define IRLIB_PROTOCOL_02_H
#define IR_SEND_PROTOCOL_02		case 2: IRsendSony::send(data,data2); break;
#define IR_DECODE_PROTOCOL_02	if(IRdecodeSony::decode()) return true;
#ifdef IRLIB_HAVE_COMBO
	#define PV_IR_DECODE_PROTOCOL_02 ,public virtual IRdecodeSony
	#define PV_IR_SEND_PROTOCOL_02   ,public virtual IRsendSony
#else
	#define PV_IR_DECODE_PROTOCOL_02  public virtual IRdecodeSony
	#define PV_IR_SEND_PROTOCOL_02    public virtual IRsendSony
#endif

#ifdef IRLIBSENDBASE_H
class IRsendSony: public virtual IRsendBase {
  public:
    void send(uint32_t data, uint8_t nbits) {
      for(uint8_t i=0; i<3;i++){
        sendGeneric(data,nbits, 600*4, 600, 600*2, 600, 600, 600, 40, false,45000); 
      }
    }
};
#endif  //IRLIBSENDBASE_H

#ifdef IRLIBDECODEBASE_H
class IRdecodeSony: public virtual IRdecodeBase {
  public:
    virtual bool decode(void) {
      IRLIB_ATTEMPT_MESSAGE(F("Sony"));
      resetDecoder();//This used to be in the receiver getResults.
      if(recvGlobal.decodeLength!=2*8+2 && recvGlobal.decodeLength!=2*12+2 && recvGlobal.decodeLength!=2*15+2 
        && recvGlobal.decodeLength!=2*20+2) return RAW_COUNT_ERROR;
      if(!ignoreHeader) {
        if (!MATCH(recvGlobal.decodeBuffer[1],600*4)) return HEADER_MARK_ERROR(600*4);
      }
      offset=2;//skip initial gap plus header Mark.
      while (offset < recvGlobal.decodeLength) {
        if (!MATCH(recvGlobal.decodeBuffer[offset],600)) return DATA_SPACE_ERROR(600);
        offset++;
        if (MATCH(recvGlobal.decodeBuffer[offset],600*2)) {
          value = (value << 1) | 1;
        } 
        else if (MATCH(recvGlobal.decodeBuffer[offset],600)) {
          value <<= 1;
        } 
        else return DATA_MARK_ERROR(600);
        offset++;
      }
      bits = (offset - 1) / 2;
      protocolNum = SONY;
      return true;
    }
};
#endif //IRLIBDECODEBASE_H

#define IRLIB_HAVE_COMBO

#endif //IRLIB_PROTOCOL_02_H
