/* IRLib_P01_NEC.h 
 * Part of IRLib Library for Arduino receiving, decoding, and sending
 * infrared signals. See COPYRIGHT.txt and LICENSE.txt for more information.
 */
/*
 * NEC is an extremely common protocol. There are two variations NEC1 and NEC2.
 * They differ only in the way in which they handle repeat codes.  If you hold a button
 * using NEC1 it does not repeat the same sequence. Rather it sends a special sequence
 * consisting of the usual header mark, a half-size header space, a normal mark.
 * When IRLib receives one of these special repeat sequences, it returns the 
 * value REPEAT_CODE which is defined in IRLibProtocols.h as the value 0xffffffff. If you
 * send REPEAT_CODE, the send routine will create a special sequence for you.
 * NOTE that the timing for this special did sequence is nearly identical to a ditto
 * used by the G.I.Cable protocol and IRLib generally not distinguish between the two.
 * The header timing for G.I. Cable ditto is 8820,1960 and for NEC is 9024,2256
 * If you are using both protocols and you receive an NEC ditto immediately after 
 * receiving a G.I.Cable then you should presume it is a G.I.Cable and vice versa. 
 * Whether it is a normal code or a repeat code the entire frame has a 108ms extent.
 * The IRP notation for these protocols are:
 * NEC1: {38k,564}<1,-1|1,-3>(16,-8,D:8,S:8,F:8,~F:8,1,^108,(16,-4,1,^108)*)
 * NEC2: {38k,564}<1,-1|1,-3>(16,-8,D:8,S:8,F:8,~F:8,1,^108)+
 * Other protocols use the same timing and 32 bits of data but they interpret the data fields
 * differently. These include Apple and TiVo. Also Pioneer protocol is identical to NEC2
 * however uses 40k rather than 38k modulation. Pioneer sometimes requires a 2 frame
 * sequence of different data for a single pushbutton function. The optional 2nd
 * parameter to the "send" method allows you to change the frequency from the default 38.
 */

#ifndef IRLIB_PROTOCOL_01_H
#define IRLIB_PROTOCOL_01_H
#define IR_SEND_PROTOCOL_01		case 1: if(data2==0)data2=38;IRsendNEC::send(data,data2); break;
#define IR_DECODE_PROTOCOL_01	if(IRdecodeNEC::decode()) return true;
#ifdef IRLIB_HAVE_COMBO
	#define PV_IR_DECODE_PROTOCOL_01 ,public virtual IRdecodeNEC
	#define PV_IR_SEND_PROTOCOL_01   ,public virtual IRsendNEC
#else
	#define PV_IR_DECODE_PROTOCOL_01  public virtual IRdecodeNEC
	#define PV_IR_SEND_PROTOCOL_01    public virtual IRsendNEC
#endif
#ifdef IRLIBSENDBASE_H

class IRsendNEC: public virtual IRsendBase {
  public:
    void send(uint32_t data, uint8_t kHz=38) {
      if (data==REPEAT_CODE) {
        enableIROut(kHz);
        mark (564* 16); space(564*4); mark(564);space(572);delay(97);//actually 97572us
      } else {
        sendGeneric(data,32, 564*16, 564*8, 564, 564, 564*3, 564, kHz, true,108000);
      }
    };
};
#endif  //IRLIBSENDBASE_H

#ifdef IRLIBDECODEBASE_H
class IRdecodeNEC: public virtual IRdecodeBase {
  public:
    bool decode(void) {
      resetDecoder();//This used to be in the receiver getResults.
      IRLIB_ATTEMPT_MESSAGE(F("NEC repeat"));
      // Check for repeat
      if (recvGlobal.decodeLength == 4 && MATCH(recvGlobal.decodeBuffer[1],564*16) && MATCH(recvGlobal.decodeBuffer[2],564*4) 
          && MATCH(recvGlobal.decodeBuffer[3],564)) {
        bits = 0;
        value = REPEAT_CODE;
        protocolNum = NEC;
        return true;
      }
      IRLIB_ATTEMPT_MESSAGE(F("NEC"));
      if(!decodeGeneric(68, 564*16, 564*8, 564, 564*3, 564)) return false;
      protocolNum = NEC;
      return true;
    }
};

#endif //IRLIBDECODEBASE_H

#define IRLIB_HAVE_COMBO

#endif //IRLIB_PROTOCOL_01_H
