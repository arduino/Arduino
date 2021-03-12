/* IRLib_P10_DirecTV.h
 * Part of IRLib Library for Arduino receiving, decoding, and sending
 * infrared signals. See COPYRIGHT.txt and LICENSE.txt for more information.
 */
/*
 * This module implements the protocol used by DirecTV. It comes in six different 
 * varieties. It uses three different frequencies 38, 40, or 57 kHz. It also 
 * uses two different varieties lead out times either 9000us or 30000us. The 
 * default is 38 kHz and 30000us. Because the decoder does not usually detect 
 * frequency and does not record the lead out time, you may have difficulty
 * determining which variety your device uses.
 *
 * According to http://www.hifi-remote.com/johnsfine/DecodeIR.html#DirecTV
 * The IRP notation for this protocol is:
 *  {38k,600,msb}<1,-1|1,-2|2,-1|2,-2>(5,(5,-2,D:4,F:8,C:4,1,-50)+) 
 *   {C=7*(F:2:6)+5*(F:2:4)+3*(F:2:2)+(F:2)} 
 * Unlike most protocols which use a fixed length mark and a variable length or
 * a variable length mark a fixed length space, this protocol varies both the 
 * mark and the space. The stream is still a series of marks and spaces but the
 * length of either of those denotes a one or zero. A length of 1200us=logical 1 
 * and length 600us=logical 0. So whereas the normal protocol requires both a mark
 * and a space to encode a single bit, this protocol encodes one bit in each mark
 * and space.  It also makes changes to the length of the header mark to devote 
 * repeat codes. The first header mark should be 6000us but repeat codes should 
 * only be 3000us. The decode routine sets "address=true" if it is a first
 * and "address=false" otherwise.
 */

#ifndef IRLIB_PROTOCOL_10_H
#define IRLIB_PROTOCOL_10_H
/* When used with IRLibCombo.h the data2 value is a flag for repeat frame.
 * You can also optionally change the frequency. To change the lead out
 * time after you have created the instance of your sending object such as
 *    IRsend My_Send;
 * you can change the leadout with 
 *    My_Send.longLeadOut= false;
 * The default value is true.
 */
#define IR_SEND_PROTOCOL_10		case 10: IRsendDirecTV::send(data,data2,khz); break;
#define IR_DECODE_PROTOCOL_10	if(IRdecodeDirecTV::decode()) return true;
#ifdef IRLIB_HAVE_COMBO
	#define PV_IR_DECODE_PROTOCOL_10 ,public virtual IRdecodeDirecTV
	#define PV_IR_SEND_PROTOCOL_10   ,public virtual IRsendDirecTV
#else
	#define PV_IR_DECODE_PROTOCOL_10  public virtual IRdecodeDirecTV
	#define PV_IR_SEND_PROTOCOL_10    public virtual IRsendDirecTV
#endif

#ifdef IRLIBSENDBASE_H
class IRsendDirecTV: public virtual IRsendBase {
  public:
    IRsendDirecTV(void):longLeadOut(true){};
    void send(uint32_t data, bool first=true, uint8_t khz=38) {
      enableIROut(khz);
      if(first) mark(6000); else mark(3000); 
      space(1200);//Send header
      for (uint8_t i = 0; i < 8; i++) {
        if (data & 0x8000) mark(1200); else mark(600);  
        data <<= 1;
        if (data & 0x8000) space(1200); else space(600);
        data <<= 1;
      };
      mark(600);  
      space(longLeadOut?50*600:15*600);
    };
    bool longLeadOut;
};
#endif  //IRLIBSENDBASE_H

#ifdef IRLIBDECODEBASE_H
class IRdecodeDirecTV: public virtual IRdecodeBase {
  public:
    bool decode(void) {
      resetDecoder();//This used to be in the receiver getResults.
      IRLIB_ATTEMPT_MESSAGE(F("DirecTV"));
      if (recvGlobal.decodeLength != 20) return RAW_COUNT_ERROR;
      //We use the "address" value as a repeat flag
      if(!ignoreHeader) {
        if (MATCH(recvGlobal.decodeBuffer[1],3000)) {
          address=false;
        } else {
          if (!MATCH(recvGlobal.decodeBuffer[1],6000)) {
            return HEADER_MARK_ERROR(6000);
          } else {
            address=true;
          }
        }
      }
      if (!MATCH(recvGlobal.decodeBuffer[2],1200)) return HEADER_SPACE_ERROR(1200);
      uint32_t data=0; offset=3; 
      while (offset < 18) {
        if (MATCH(recvGlobal.decodeBuffer[offset],1200)) {
          data = (data << 1) | 1;
        } else {
          if (MATCH(recvGlobal.decodeBuffer[offset],600)) {
            data <<= 1;
          } else {
            return DATA_MARK_ERROR(1200);
          }
        }
        offset++;
        if (MATCH(recvGlobal.decodeBuffer[offset],1200)) {
          data = (data << 1) | 1;
        } else {
          if (MATCH (recvGlobal.decodeBuffer[offset],600)) {
            data <<= 1;
          } else {
            return DATA_SPACE_ERROR(1200);
          }
        }
        offset++;
      }
      bits = 16;
      value = data;
      protocolNum=DIRECTV;
      return true;
    }
};
#endif //IRLIBDECODEBASE_H

#define IRLIB_HAVE_COMBO

#endif //IRLIB_PROTOCOL_10_H
