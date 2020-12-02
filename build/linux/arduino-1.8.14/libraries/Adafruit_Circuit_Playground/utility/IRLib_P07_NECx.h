/* IRLib_P07_NECx.h
 * Part of IRLib Library for Arduino receiving, decoding, and sending
 * infrared signals. See COPYRIGHT.txt and LICENSE.txt for more information.
 */
/*
 * NECx is a variation of NEC protocol. The only difference is in the timing of the
 * header.  There are two variations NECx1 and NECx2. They differ only in the way in 
 * which they handle repeat codes.  If you hold a button using NECx1 it does not repeat 
 * the same sequence. Rather it sends a special sequence consisting of the usual header
 * followed by a normal mark, a "1" bit, and then a long space with a 108ms extent. Note
 * this so-called "ditto" repeat code is slightly different than the one for regular NEC.
 * When IRLib receives one of these special repeat sequences, it returns the 
 * value REPEAT_CODE which is defined in IRLibProtocols.h as the value 0xffffffff. If you
 * send REPEAT_CODE, the send routine will create a special sequence for you.
 * Whether it is a normal code or a repeat code the entire frame has a 108ms extent.
 * The IRP notation for these protocols are:
 * NECx1: {38k,564}<1,-1|1,-3>(8,-8,D:8,S:8,F:8,~F:8,1,^108,(8,-8,D:1,1,^108m)*)
 * NECx2: {38k,564}<1,-1|1,-3>(8,-8,D:8,S:8,F:8,~F:8,1,^108)+
 */

#ifndef IRLIB_PROTOCOL_07_H
#define IRLIB_PROTOCOL_07_H
#define IR_SEND_PROTOCOL_07		case 07: IRsendNECx::send(data); break;
#define IR_DECODE_PROTOCOL_07	if(IRdecodeNECx::decode()) return true;
#ifdef IRLIB_HAVE_COMBO
	#define PV_IR_DECODE_PROTOCOL_07 ,public virtual IRdecodeNECx
	#define PV_IR_SEND_PROTOCOL_07   ,public virtual IRsendNECx
#else
	#define PV_IR_DECODE_PROTOCOL_07  public virtual IRdecodeNECx
	#define PV_IR_SEND_PROTOCOL_07    public virtual IRsendNECx
#endif

#ifdef IRLIBSENDBASE_H
class IRsendNECx: public virtual IRsendBase {
  public:
    void send(uint32_t data) {
      if (data==REPEAT_CODE) {
        enableIROut(38);
        mark(564*8); space(564*8); mark(564);space(564);
        mark(564);  space(412);delay(98);//actually 98412us
      }
      else {
        sendGeneric(data,32, 564*8, 564*8, 564, 564, 564*3, 564, 38, true);
      }
    };
};
#endif  //IRLIBSENDBASE_H

#ifdef IRLIBDECODEBASE_H
class IRdecodeNECx: public virtual IRdecodeBase {
  public:
    virtual bool decode(void) {
      IRLIB_ATTEMPT_MESSAGE(F("NECx"));
      resetDecoder();//This used to be in the receiver getResults.
      // Check for repeat
      if (recvGlobal.decodeLength == 6 && MATCH(recvGlobal.decodeBuffer[1], 564*8)  && MATCH(recvGlobal.decodeBuffer[2],564*8)
        && MATCH(recvGlobal.decodeBuffer[3],564) && MATCH(recvGlobal.decodeBuffer[5],564)
        ) {
        bits = 0;
        value = REPEAT_CODE;
        protocolNum = NECX;
        return true;
      }
      if(!decodeGeneric(68, 564*8, 564*8, 564, 564*3, 564)) return false;
      protocolNum = NECX;
      return true;
    }
};
#endif //IRLIBDECODEBASE_H

#define IRLIB_HAVE_COMBO

#endif //IRLIB_PROTOCOL_07_H
