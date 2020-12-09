/* IRLib_P09_GICable.h
 * Part of IRLib Library for Arduino receiving, decoding, and sending
 * infrared signals. See COPYRIGHT.txt and LICENSE.txt for more information.
 */

/* The G.I. Cable protocol is is used by many Motorola brand cable boxes manufactured by
 * General Instruments. The IRP notation for this protocol is 
 * "{38.7k,490}<1,-4.5|1,-9>(18,-9,F:8,D:4,C:4,1,-84,(18,-4.5,1,-178)*) {C = -(D + F:4 + F:4:4)}"
 * It is a 16-bit code which uses an unusual "ditto" repeat sequence similar to NEC.
 * In fact it is so similar that IRLib generally not distinguish between the two.
 * The header timing for G.I. Cable ditto is 8820,1960 and for NEC is 9024,2256
 * If you are using both protocols and you receive an NEC ditto immediately after 
 * receiving a G.I.Cable then you should presume it is a G.I.Cable and vice versa. 
 */
#ifndef IRLIB_PROTOCOL_09_H
#define IRLIB_PROTOCOL_09_H
#define IR_SEND_PROTOCOL_09		case 9: IRsendGICable::send(data); break;
#define IR_DECODE_PROTOCOL_09	if(IRdecodeGICable::decode()) return true;
#ifdef IRLIB_HAVE_COMBO
	#define PV_IR_DECODE_PROTOCOL_09 ,public virtual IRdecodeGICable
	#define PV_IR_SEND_PROTOCOL_09   ,public virtual IRsendGICable
#else
	#define PV_IR_DECODE_PROTOCOL_09  public virtual IRdecodeGICable
	#define PV_IR_SEND_PROTOCOL_09    public virtual IRsendGICable
#endif

#ifdef IRLIBSENDBASE_H
class IRsendGICable: public virtual IRsendBase {
  public:
    void send(uint32_t data) {
      if(data==REPEAT_CODE) {
        enableIROut(39);
        mark (490*18); space(2205);//actually "490*4.5"
        mark (490); space(220);delay(87);//actually 490*178 or "space(87220);"
      } else {
        sendGeneric(data,16, 490*18, 490*9, 490, 490, 490*9, 2205/*(4.5*490)*/, 39, true);
        space(37*490);
      }
    }
};
#endif  //IRLIBSENDBASE_H

#ifdef IRLIBDECODEBASE_H
class IRdecodeGICable: public virtual IRdecodeBase {
  public:
    bool decode(void) {
      IRLIB_ATTEMPT_MESSAGE(F("G.I.cable"));
      // Check for repeat
      if (recvGlobal.decodeLength == 4 && MATCH(recvGlobal.decodeBuffer[1], 490*18) && MATCH(recvGlobal.decodeBuffer[2],2205)
              && MATCH(recvGlobal.decodeBuffer[3],490)) {
        bits = 0;
        value = REPEAT_CODE;
        protocolNum=GICABLE;
        return true;
      }
      if(!decodeGeneric(36, 18*490, 9*490, 490, 9*490, 2205/*(4.5*490)*/)) return false;
      protocolNum=GICABLE;
      return true;
    }
};
#endif //IRLIBDECODEBASE_H

#define IRLIB_HAVE_COMBO

#endif //IRLIB_PROTOCOL_09_H
