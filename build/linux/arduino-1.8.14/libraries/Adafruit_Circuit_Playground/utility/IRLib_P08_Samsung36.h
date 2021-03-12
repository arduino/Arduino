/* IRLib_P08_Samsung36.h
 * Part of IRLib Library for Arduino receiving, decoding, and sending
 * infrared signals. See COPYRIGHT.txt and LICENSE.txt for more information.
 */

/*
 * This 36 bit protocol is used by some Samsung devices such as Blu-ray players.
 * It consists of a 16 bit address and 20 bits of data with strange timing in between.
 */
/* The IRP notation for this protocol is:
 * {38k,500}<1,-1|1,-3>(9,-9,D:8,S:8,1,-9,E:4,F:8,-68u,~F:8,1,-118)+ 
 * This means it uses 38k frequency. Base timing is multiples of 500.
 * A "0" is mark(500) space(500). A "1" is mark (500) space(500*3)
 * The header is mark(500*9) space(500*9).
 * The header is followed by 16 bit address (8 device, 8 sub device)
 * This is followed by a mark(500) space(500*9).
 * This is followed by 12 more bits (4+8)
 * This is followed by 68us of space. Actually this means that the space
 *  of the last bit of that segment is simply 68us longer than normal.
 * This is followed by 8 more bits and a final stop bit.
*/
#ifndef IRLIB_PROTOCOL_08_H
#define IRLIB_PROTOCOL_08_H
#define IR_SEND_PROTOCOL_08		case 8: IRsendSamsung36::send(data,data2); break;
#define IR_DECODE_PROTOCOL_08	if(IRdecodeSamsung36::decode()) return true;
#ifdef IRLIB_HAVE_COMBO
	#define PV_IR_DECODE_PROTOCOL_08 ,public virtual IRdecodeSamsung36
	#define PV_IR_SEND_PROTOCOL_08   ,public virtual IRsendSamsung36
#else
	#define PV_IR_DECODE_PROTOCOL_08  public virtual IRdecodeSamsung36
	#define PV_IR_SEND_PROTOCOL_08    public virtual IRsendSamsung36
#endif

#ifdef IRLIBSENDBASE_H
class IRsendSamsung36: public virtual IRsendBase {
  public:
    void send(uint32_t data, uint32_t address) {
      data <<= 32-20;
      address <<= 32-16;
      enableIROut(38);
      mark(500*9); space(500*9);	//Send header
      putBits (address, 16);		  //Send address 16 bits
      mark (500); space (500*9);	//Send break
      putBits (data, 12);			    //Send 12 bits
      space(68);                  //Send tiny break
      data <<= 12;
      putBits (data, 8);mark(500); //Final eight bits and one stop bit
      space(118*500);				//Lead out is 118 times the base time 500
    };
  private:
    /* Because not all of the data bits are contiguous in the stream,
    * we created this little routine to be called multiple times to send a 
    * segment of the data. 
    */
    void putBits (uint32_t data, uint8_t nbits) {
      for (uint8_t i = 0; i < nbits; i++) {
        if (data & TOPBIT) {
          mark(500);  space(500*3);
        } else {
          mark(500);  space(500);
        };
        data <<= 1;
      }
    }
};

#endif  //IRLIBSENDBASE_H

#ifdef IRLIBDECODEBASE_H
class IRdecodeSamsung36: public virtual IRdecodeBase {
  public:
    bool decode(void) {
      IRLIB_ATTEMPT_MESSAGE(F("Samsung36"));
      if (recvGlobal.decodeLength != 78) return RAW_COUNT_ERROR;
      if (!MATCH(recvGlobal.decodeBuffer[1],500*9))  return HEADER_MARK_ERROR(500*9);
      if (!MATCH(recvGlobal.decodeBuffer[2],500*9)) return HEADER_SPACE_ERROR(500*9);
      offset=3; data=0;
      //Get first 16 bits
      if(!getBits(16*2+2))return false;
      //Skip middle header
      if (!MATCH(recvGlobal.decodeBuffer[offset],500))  return DATA_MARK_ERROR(500);
      offset++;
      if (!MATCH(recvGlobal.decodeBuffer[offset],500*9)) return DATA_SPACE_ERROR(4400);
      //save first 16 bits in "address" and reset data
      offset++; address=data; data=0;
      //12 bits into this second segment, the space is extended by 68us.
      //  so we adjust the value to its normal length without the extra 68us.
      recvGlobal.decodeBuffer[62]-=68;
      //Now get the remaining 20 bits
      if(!getBits(77))return false;
      bits =36;		//set bit length
      value = data;	//put remaining 20 bits in value
      protocolNum= SAMSUNG36;
      return true;
    };
  private:
    /* Because not all of the data bits are contiguous in the stream
     * we created this little routine to be called multiple times
     * to decode a segment of the data. Parameter "last_offset" is when we
     * stop decoding the segment.
     */
    bool getBits(uint8_t last_offset) {
      while (offset < last_offset) {
        if (!MATCH(recvGlobal.decodeBuffer[offset],500)) return DATA_MARK_ERROR(500);
        offset++;
        if (MATCH(recvGlobal.decodeBuffer[offset],500*3)) 
          data = (data << 1) | 1;
        else if (MATCH(recvGlobal.decodeBuffer[offset],500)) 
          data <<= 1;
        else return DATA_SPACE_ERROR(500*3);
        offset++;
      };
      return true;
    };
    uint8_t offset;
    uint32_t data;
};
#endif //IRLIBDECODEBASE_H

#define IRLIB_HAVE_COMBO

#endif //IRLIB_PROTOCOL_08_H
