/* IRLib_P99_Additional.h
 * Part of IRLib Library for Arduino receiving, decoding, and sending
 * infrared signals. See COPYRIGHT.txt and LICENSE.txt for more information.
 */
/*
 * This is dummy code that you can copy and rename and modify when implementing new protocols.
 */

#ifndef IRLIB_PROTOCOL_99_H
#define IRLIB_PROTOCOL_99_H
#define IR_SEND_PROTOCOL_99		case 99: IRsendAdditional::send(data); break;
#define IR_DECODE_PROTOCOL_99	if(IRdecodeAdditional::decode()) return true;
#ifdef IRLIB_HAVE_COMBO
	#define PV_IR_DECODE_PROTOCOL_99 ,public virtual IRdecodeAdditional
	#define PV_IR_SEND_PROTOCOL_99   ,public virtual IRsendAdditional
#else
	#define PV_IR_DECODE_PROTOCOL_99  public virtual IRdecodeAdditional
	#define PV_IR_SEND_PROTOCOL_99    public virtual IRsendAdditional
#endif

#ifdef IRLIBSENDBASE_H
class IRsendAdditional: public virtual IRsendBase {
  public:
    void IRsendAdditional::send(uint32_t data) {
    //void IRsendAdditional::send(uint32_t data, uint32_t data2)//optional form
      /*********
       *  Insert your code here.
       *********/
    };
};
#endif  //IRLIBSENDBASE_H

#ifdef IRLIBDECODEBASE_H
class IRdecodeAdditional: public virtual IRdecodeBase {
  public:
    bool IRdecodeAdditional::decode(void) {
      IRLIB_ATTEMPT_MESSAGE(F("Additional"));
      /*********
       *  Insert your code here. Return false if it fails. 
       *  Don't forget to include the following lines or 
       *  equivalent somewhere in the code.
       *  
       *  bits = 32;	//Substitute proper value here
       *  value = data;	//return data in "value"
       *  protocolNum = ADDITIONAL;	//set the protocol number here.
       */
      return true;
    }
};

#endif //IRLIBDECODEBASE_H

#define IRLIB_HAVE_COMBO

#endif //IRLIB_PROTOCOL_99_H
