/* IRLib_P11_RCMM.h
 * Part of IRLib Library for Arduino receiving, decoding, and sending
 * infrared signals. See COPYRIGHT.txt and LICENSE.txt for more information.
 */
/* This module implements the Phillips RC-MM also known as Nokia Protocol. Is used by 
 * AT&T U-Verse cable boxes. There are three different varieties that are 12, 24, or 32 bits.
 * According to http://www.hifi-remote.com/johnsfine/DecodeIR.html#Nokia
 * The IRP notation for these protocols are:
 * Nokia 12 bit: {36k,msb}<164,-276|164,-445|164,-614|164,-783>(412,-276,D:4,F:8,164,-???)+ 
 * Nokia 24-bit: {36k,msb}<164,-276|164,-445|164,-614|164,-783>(412,-276,D:8,S:8,F:8,164,-???)+ 
 * Nokia 32 bit: {36k,msb}<164,-276|164,-445|164,-614|164,-783>(412,-276,D:8,S:8,T:1X:7,F:8,164,^100m)+ 
 * Slightly different timing values are documented at 
 * http://www.sbprojects.com/knowledge/ir/rcmm.php
 * We will use the timing from the latter reference.
 * Unlike most protocols which defined sequences for a logical "0" and "1", this protocol
 * encodes 2 bits per pulse. Therefore it encodes a logical "2" and "3" as well.
 * The length of the mark is constant but the length of the space denotes the bit values.
 * Note the 32-bit version uses a toggle bit of 0x8000 and as usual it is up to the end-user
 * to implement it outside the library routines.
 */
#define RCMM_HEAD_MARK 417
#define RCMM_DATA_MARK 167
#define RCMM_ZERO      278
#define RCMM_ONE       444
#define RCMM_TWO       611
#define RCMM_THREE     778

#ifndef IRLIB_PROTOCOL_11_H
#define IRLIB_PROTOCOL_11_H
#define IR_SEND_PROTOCOL_11		case 11: IRsendRCMM::send(data,data2); break;//data2 is the number of bits
#define IR_DECODE_PROTOCOL_11	if(IRdecodeRCMM::decode()) return true;
#ifdef IRLIB_HAVE_COMBO
	#define PV_IR_DECODE_PROTOCOL_11 ,public virtual IRdecodeRCMM
	#define PV_IR_SEND_PROTOCOL_11   ,public virtual IRsendRCMM
#else
	#define PV_IR_DECODE_PROTOCOL_11  public virtual IRdecodeRCMM
	#define PV_IR_SEND_PROTOCOL_11    public virtual IRsendRCMM
#endif

#ifdef IRLIBSENDBASE_H
class IRsendRCMM: public virtual IRsendBase {
  public:
    void send(uint32_t data, uint8_t nBits= 12) {
      if (nBits==0) nBits=12;
      extent=0;
      data <<= (32 - nBits);
      nBits=nBits/2;
      enableIROut(36);
      mark(RCMM_HEAD_MARK); space(RCMM_ZERO);//Send header
      for (uint8_t i = 0; i < nBits; i++) {
        mark(RCMM_DATA_MARK);
        switch (data & 0xC0000000UL) {//use the leftmost two bits
          case 0x00000000UL: space(RCMM_ZERO); break;
          case 0x40000000UL: space(RCMM_ONE); break;
          case 0x80000000UL: space(RCMM_TWO); break;
          case 0xC0000000UL: space(RCMM_THREE); break;
        }
        data <<= 2;
      };
      mark(RCMM_DATA_MARK);  
      space(27778-extent);
    };
};
#endif  //IRLIBSENDBASE_H

#ifdef IRLIBDECODEBASE_H
/*
 * Normally IRLib uses a plus or minus percentage to determine if an interval matches the
 * desired value. However this protocol uses extremely long intervals of similar length.
 * For example using the default 25% tolerance the RCMM_TWO value 611 would be accepted for 
 * anything between 458 and 763. The low end is actually closer to RCMM_ONE value of 444
 * and the upper range is closer to RCM_THREE value of 778. To implement this protocol
 * we created a new match routine ABS_MATCH which allows you to specify an absolute
 * number of microseconds of tolerance for comparison.
 */ 
#define RCMM_TOLERANCE 80
class IRdecodeRCMM: public virtual IRdecodeBase {
  public:
    bool decode(void) {
      resetDecoder();//This used to be in the receiver getResults.
      IRLIB_ATTEMPT_MESSAGE(F("RCMM"));
      if ( (recvGlobal.decodeLength!=(12+4)) && (recvGlobal.decodeLength!=(24+4)) && (recvGlobal.decodeLength!=(32+4)) ) return RAW_COUNT_ERROR;
      if (!ignoreHeader) if (!MATCH(recvGlobal.decodeBuffer[1],RCMM_HEAD_MARK)) return HEADER_MARK_ERROR(RCMM_HEAD_MARK);
      if (!MATCH(recvGlobal.decodeBuffer[2],RCMM_ZERO)) return HEADER_SPACE_ERROR(RCMM_ZERO);
      offset=3; uint32_t data=0;
      while (offset < (recvGlobal.decodeLength-1)) {
        if (!ABS_MATCH(recvGlobal.decodeBuffer[offset],RCMM_DATA_MARK,RCMM_TOLERANCE)) return DATA_MARK_ERROR(RCMM_DATA_MARK);
        offset++;
        if (ABS_MATCH(recvGlobal.decodeBuffer[offset],RCMM_ZERO, RCMM_TOLERANCE) ) { //Logical "0"
          data <<= 2;
        } 
        else if (ABS_MATCH(recvGlobal.decodeBuffer[offset],RCMM_ONE, RCMM_TOLERANCE) ) { //Logical "1"
          data = (data<<2) + 1;
        } 
        else if (ABS_MATCH(recvGlobal.decodeBuffer[offset],RCMM_TWO, RCMM_TOLERANCE) ) { //Logical "2"
          data = (data<<2) + 2;
        } 
        else if (ABS_MATCH(recvGlobal.decodeBuffer[offset],RCMM_THREE, RCMM_TOLERANCE) ) { //Logical "3"
          data = (data<<2) + 3;
        } 
        else return DATA_SPACE_ERROR(RCMM_ZERO);
        offset++;
      }
      if (!MATCH(recvGlobal.decodeBuffer[offset],RCMM_DATA_MARK))  return DATA_MARK_ERROR(RCMM_DATA_MARK);
      bits = recvGlobal.decodeLength-4;//set bit length
      value = data;//put remaining bits in value
      protocolNum=RCMM;
      return true;
    }
};
#endif //IRLIBDECODEBASE_H

#define IRLIB_HAVE_COMBO

#endif //IRLIB_PROTOCOL_11_H
