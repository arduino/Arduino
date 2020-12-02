/* IRLib_P06_JVC.h
 * Part of IRLib Library for Arduino receiving, decoding, and sending
 * infrared signals. See COPYRIGHT.txt and LICENSE.txt for more information.
 */
/*
 * JVC omits the mark/space header on repeat sending. Therefore we multiply 
 * it by 0 if it's a repeat. The only device I had to test this protocol was
 * an old JVC VCR. It would only work if at least 2 frames are sent separated 
 * by 45 time periods of "space". Therefore you should call this routine once 
 * with "first=true" and it will send a first frame followed by one repeat 
 * frame. If First==false, it will only send a single repeat frame.
 */

#ifndef IRLIB_PROTOCOL_06_H
#define IRLIB_PROTOCOL_06_H
#define IR_SEND_PROTOCOL_06		case 06: IRsendJVC::send(data,(bool)data2); break;
#define IR_DECODE_PROTOCOL_06	if(IRdecodeJVC::decode()) return true;
#ifdef IRLIB_HAVE_COMBO
	#define PV_IR_DECODE_PROTOCOL_06 ,public virtual IRdecodeJVC
	#define PV_IR_SEND_PROTOCOL_06   ,public virtual IRsendJVC
#else
	#define PV_IR_DECODE_PROTOCOL_06  public virtual IRdecodeJVC
	#define PV_IR_SEND_PROTOCOL_06    public virtual IRsendJVC
#endif

#ifdef IRLIBSENDBASE_H
class IRsendJVC: public virtual IRsendBase {
  public:
    void send(uint32_t data, bool first=true) {
      sendGeneric(data, 16,525*16*first, 525*8*first, 525, 525,525*3, 525, 38, true);
      space(525*45);
      if(first) {
        sendGeneric(data, 16,0,0, 525, 525,525*3, 525, 38, true);
        space(525*45);
      }
    }
};
#endif  //IRLIBSENDBASE_H

#ifdef IRLIBDECODEBASE_H
class IRdecodeJVC: public virtual IRdecodeBase {
  public:
    bool decode(void) {
      // JVC does not send any header if there is a repeat.
      // first try with the header. If that fails, try without.
      IRLIB_ATTEMPT_MESSAGE(F("JVC"));
      if(!decodeGeneric(36,525*16,525*8,525,525*3,525)) {
        IRLIB_ATTEMPT_MESSAGE(F("JVC Repeat"));
        if (recvGlobal.decodeLength==34) {
          if(!decodeGeneric(0,525,0,525,525*3,525)) {
            return IRLIB_REJECTION_MESSAGE(F("JVC repeat failed generic"));
          } else {
            //If this is a repeat code then IRdecodeBase::decodeGeneric fails to add the most significant bit
            if (MATCH(recvGlobal.decodeBuffer[2],(525*3))) {
              value |= 0x8000;
            } else {
              if (!MATCH(recvGlobal.decodeBuffer[2],525)) return DATA_SPACE_ERROR(525);
            }
          }
          bits++;
        }
        else return RAW_COUNT_ERROR;
      } 
      address=(recvGlobal.decodeLength==36);
      protocolNum =JVC;
      return true;
    }
};
#endif //IRLIBDECODEBASE_H

#define IRLIB_HAVE_COMBO

#endif //IRLIB_PROTOCOL_06_H
