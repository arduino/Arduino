/* IRLib_P05_Panasonic_Old.h
 * Part of IRLib Library for Arduino receiving, decoding, and sending
 * infrared signals. See COPYRIGHT.txt and LICENSE.txt for more information.
 */
/*
 * This protocol #5 named "Panasonic_Old" is a 57 kHz protocol with 22 bits
 * of data. The second 11 bits are the bitwise logical complement of the first 11 bits.
 * The protocol is used by many cable boxes and DVR's made by  Scientific Atlantic and
 * Cisco. They are common for Bright House and Time Warner cable systems.
 */

#ifndef IRLIB_PROTOCOL_05_H
#define IRLIB_PROTOCOL_05_H
#define IR_SEND_PROTOCOL_05		case 5: IRsendPanasonic_Old::send(data); break;
#define IR_DECODE_PROTOCOL_05	if(IRdecodePanasonic_Old::decode()) return true;
#ifdef IRLIB_HAVE_COMBO
	#define PV_IR_DECODE_PROTOCOL_05 ,public virtual IRdecodePanasonic_Old
	#define PV_IR_SEND_PROTOCOL_05   ,public virtual IRsendPanasonic_Old
#else
	#define PV_IR_DECODE_PROTOCOL_05  public virtual IRdecodePanasonic_Old
	#define PV_IR_SEND_PROTOCOL_05    public virtual IRsendPanasonic_Old
#endif

#ifdef IRLIBSENDBASE_H
class IRsendPanasonic_Old: public virtual IRsendBase {
public:
  void send(uint32_t data) {
    sendGeneric(data,22, 833*4, 833*4, 833, 833, 833*3, 833,57, true);
  };
};
#endif  //IRLIBSENDBASE_H

#ifdef IRLIBDECODEBASE_H
class IRdecodePanasonic_Old: public virtual IRdecodeBase {
public:
  virtual bool decode(void) {
    IRLIB_ATTEMPT_MESSAGE(F("Panasonic_Old"));
    if(!decodeGeneric(48,833*4,833*4,833,833*3,833)) return false;
    // The protocol spec says that the first 11 bits described the device and function.
    // The next 11 bits are the same thing only it is the logical Bitwise complement.
    // Many protocols have such check features in their definition but our code typically
    // doesn't perform these checks. For example NEC's least significant 8 bits are the
    // complement of the next more significant 8 bits. While it's probably not necessary
    // to error check this, you can un-comment the next 4 lines of code to do this extra
    // checking.
    //  long S1= (value & 0x0007ff);  // 00 0000 0000 0111 1111 1111 
    //  long S2= (value & 0x3ff800)>> 11;  // 11 1111 1111 1000 0000 0000 
    //  S2= (~S2) & 0x0007ff;
    //  if (S1!=S2) return IRLIB_REJECTION_MESSAGE(F("inverted bit redundancy"));
    protocolNum = PANASONIC_OLD;
    return true;
  };
};
#endif //IRLIBDECODEBASE_H

#define IRLIB_HAVE_COMBO

#endif //IRLIB_PROTOCOL_05_H
