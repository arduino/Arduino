/* IRLibCombo.h
 * Part of IRLib Library for Arduino receiving, decoding, and sending
 * infrared signals. See COPYRIGHT.txt and LICENSE.txt for more information.
 */
/* 
 * This file is for creating a customer decode or send class which contains only 
 * the protocols that you will actually use. At the top of your sketch you should
 * include the Send and/or Decode base modules followed by at least one or more
 * protocol module. Then conclude with this module.
 * WARNING: The lowest numbered protocol which you are using MUST be included first. 
 *		The remaining protocol modules technically could be in any order however we 
 *		recommend that you maintain numerical order because you might at some point 
 *		comment out the top one and then the lowest would not be first causing an error.
 *   
 * Here is an example...
 *
 * #include <IRLibSendBase.h>	//Only include if you are sending
 * #include <IRLibDecodeBase.h>	//Only include if you are decoding
 * #include <IRLib_Pxx_protocol_name.h>	//Include at least one protocol
 * #include <IRLib_Pxx_another_name.h>	//Include as many as you want
 * #include <IRLibCombo.h>		//Include this file
 * IRdecode My_Decoder;	//declare an instance of the decoder if needed
 * IRsend My_Sender;	//declarative sense of the sending routine if needed
 * //The rest of your code goes here
 */
 
#ifndef IRLIB_COMBO_H
#define IRLIB_COMBO_H

#ifndef IRLIB_HASHRAW_H
	#define IR_SEND_RAW
	#define IR_DECODE_HASH
	#define PV_IR_DECODE_HASH
	#define PV_IR_SEND_RAW
#endif
#ifndef IRLIB_PROTOCOL_01_H
	#define IR_SEND_PROTOCOL_01
	#define IR_DECODE_PROTOCOL_01
	#define PV_IR_DECODE_PROTOCOL_01
	#define PV_IR_SEND_PROTOCOL_01
#endif
#ifndef IRLIB_PROTOCOL_02_H
	#define IR_SEND_PROTOCOL_02
	#define IR_DECODE_PROTOCOL_02
	#define PV_IR_DECODE_PROTOCOL_02
	#define PV_IR_SEND_PROTOCOL_02
#endif
#ifndef IRLIB_PROTOCOL_03_H
	#define IR_SEND_PROTOCOL_03
	#define IR_DECODE_PROTOCOL_03
	#define PV_IR_DECODE_PROTOCOL_03
	#define PV_IR_SEND_PROTOCOL_03
#endif
#ifndef IRLIB_PROTOCOL_04_H
	#define IR_SEND_PROTOCOL_04
	#define IR_DECODE_PROTOCOL_04
	#define PV_IR_DECODE_PROTOCOL_04
	#define PV_IR_SEND_PROTOCOL_04
#endif
#ifndef IRLIB_PROTOCOL_05_H
	#define IR_SEND_PROTOCOL_05
	#define IR_DECODE_PROTOCOL_05
	#define PV_IR_DECODE_PROTOCOL_05
	#define PV_IR_SEND_PROTOCOL_05
#endif
#ifndef IRLIB_PROTOCOL_06_H
	#define IR_SEND_PROTOCOL_06
	#define IR_DECODE_PROTOCOL_06
	#define PV_IR_DECODE_PROTOCOL_06
	#define PV_IR_SEND_PROTOCOL_06
#endif
#ifndef IRLIB_PROTOCOL_07_H
	#define IR_SEND_PROTOCOL_07
	#define IR_DECODE_PROTOCOL_07
	#define PV_IR_DECODE_PROTOCOL_07
	#define PV_IR_SEND_PROTOCOL_07
#endif
#ifndef IRLIB_PROTOCOL_08_H
	#define IR_SEND_PROTOCOL_08
	#define IR_DECODE_PROTOCOL_08
	#define PV_IR_DECODE_PROTOCOL_08
	#define PV_IR_SEND_PROTOCOL_08
#endif
#ifndef IRLIB_PROTOCOL_09_H
	#define IR_SEND_PROTOCOL_09
	#define IR_DECODE_PROTOCOL_09
	#define PV_IR_DECODE_PROTOCOL_09
	#define PV_IR_SEND_PROTOCOL_09
#endif
#ifndef IRLIB_PROTOCOL_10_H
	#define IR_SEND_PROTOCOL_10
	#define IR_DECODE_PROTOCOL_10
	#define PV_IR_DECODE_PROTOCOL_10
	#define PV_IR_SEND_PROTOCOL_10
#endif
#ifndef IRLIB_PROTOCOL_11_H
	#define IR_SEND_PROTOCOL_11
	#define IR_DECODE_PROTOCOL_11
	#define PV_IR_DECODE_PROTOCOL_11
	#define PV_IR_SEND_PROTOCOL_11
#endif
#ifndef IRLIB_PROTOCOL_12_H
	#define IR_SEND_PROTOCOL_12
	#define IR_DECODE_PROTOCOL_12
	#define PV_IR_DECODE_PROTOCOL_12
	#define PV_IR_SEND_PROTOCOL_12
#endif
#ifndef IRLIB_PROTOCOL_13_H
	#define IR_SEND_PROTOCOL_13
	#define IR_DECODE_PROTOCOL_13
	#define PV_IR_DECODE_PROTOCOL_13
	#define PV_IR_SEND_PROTOCOL_13
#endif
#ifndef IRLIB_PROTOCOL_14_H
	#define IR_SEND_PROTOCOL_14
	#define IR_DECODE_PROTOCOL_14
	#define PV_IR_DECODE_PROTOCOL_14
	#define PV_IR_SEND_PROTOCOL_14
#endif
//Add additional protocols 15, 16, etc. above.

//Note protocol 90- 99 for sample code that will be unsupported in the final version.
//See IRLibProtocols/unsupported/IRLib_P90_Unsupported.h for details
#ifndef IRLIB_PROTOCOL_90_H
	#define IR_SEND_PROTOCOL_90
	#define IR_DECODE_PROTOCOL_90
	#define PV_IR_DECODE_PROTOCOL_90
	#define PV_IR_SEND_PROTOCOL_90
#endif
#ifndef IRLIB_PROTOCOL_91_H
	#define IR_SEND_PROTOCOL_91
	#define IR_DECODE_PROTOCOL_91
	#define PV_IR_DECODE_PROTOCOL_91
	#define PV_IR_SEND_PROTOCOL_91
#endif
#ifndef IRLIB_PROTOCOL_92_H
	#define IR_SEND_PROTOCOL_92
	#define IR_DECODE_PROTOCOL_92
	#define PV_IR_DECODE_PROTOCOL_92
	#define PV_IR_SEND_PROTOCOL_92
#endif
/*
 * You may add additional protocols by copying and modifying the previous six lines.
 * You must also add appropriate macros in each segment below. Be sure to maintain 
 * numerical order. Also the final entry in each list MUST BE the Hash_Raw version.
 */
#ifdef IRLIBDECODEBASE_H
class IRdecode: 
	PV_IR_DECODE_PROTOCOL_01
	PV_IR_DECODE_PROTOCOL_02
	PV_IR_DECODE_PROTOCOL_03
	PV_IR_DECODE_PROTOCOL_04
	PV_IR_DECODE_PROTOCOL_05
	PV_IR_DECODE_PROTOCOL_06
	PV_IR_DECODE_PROTOCOL_07
	PV_IR_DECODE_PROTOCOL_08
	PV_IR_DECODE_PROTOCOL_09
	PV_IR_DECODE_PROTOCOL_10
	PV_IR_DECODE_PROTOCOL_11
	PV_IR_DECODE_PROTOCOL_12
	PV_IR_DECODE_PROTOCOL_13
	PV_IR_DECODE_PROTOCOL_14
	PV_IR_DECODE_PROTOCOL_90 //Add additional 15, 16 etc. above this
	PV_IR_DECODE_PROTOCOL_91
	PV_IR_DECODE_PROTOCOL_92
	PV_IR_DECODE_HASH	//Must be last one. 
{
public:
	bool decode(void) {
		IR_DECODE_PROTOCOL_01
		IR_DECODE_PROTOCOL_02
		IR_DECODE_PROTOCOL_03
		IR_DECODE_PROTOCOL_04
		IR_DECODE_PROTOCOL_05
		IR_DECODE_PROTOCOL_06
		IR_DECODE_PROTOCOL_07
		IR_DECODE_PROTOCOL_08
		IR_DECODE_PROTOCOL_09
		IR_DECODE_PROTOCOL_10
		IR_DECODE_PROTOCOL_11
		IR_DECODE_PROTOCOL_12
		IR_DECODE_PROTOCOL_13
		IR_DECODE_PROTOCOL_14
    IR_DECODE_PROTOCOL_90 //Add additional 15, 16 etc. above this
		IR_DECODE_PROTOCOL_91
		IR_DECODE_PROTOCOL_92
	  IR_DECODE_HASH	//Must be last one. 
		return false;
	};
#ifdef IRLIB_PROTOCOL_12_H
  void dumpResults(bool verbose=true) {
    if(protocolNum==12) {
      IRdecodeCYKM::dumpResults();
      if(verbose)IRdecodeBase::dumpResults(true);
    } else {
      IRdecodeBase::dumpResults(verbose);
    }
  }
#endif
};
#endif //IRLIBDECODEBASE_H

#ifdef IRLIBSENDBASE_H
class IRsend: 
	PV_IR_SEND_PROTOCOL_01
	PV_IR_SEND_PROTOCOL_02
	PV_IR_SEND_PROTOCOL_03
	PV_IR_SEND_PROTOCOL_04
	PV_IR_SEND_PROTOCOL_05
	PV_IR_SEND_PROTOCOL_06
	PV_IR_SEND_PROTOCOL_07
	PV_IR_SEND_PROTOCOL_08
	PV_IR_SEND_PROTOCOL_09
	PV_IR_SEND_PROTOCOL_10
	PV_IR_SEND_PROTOCOL_11
	PV_IR_SEND_PROTOCOL_12
	PV_IR_SEND_PROTOCOL_13
	PV_IR_SEND_PROTOCOL_14
  PV_IR_SEND_PROTOCOL_90 //Add additional 15, 16 etc. above this
	PV_IR_SEND_PROTOCOL_91
	PV_IR_SEND_PROTOCOL_92
	PV_IR_SEND_RAW	//Must be last one.
{
public:
	void send(uint8_t protocolNum, uint32_t data, uint16_t data2=0, uint8_t khz=38) {
    if(khz==0)khz=38;
		switch(protocolNum) {
			IR_SEND_PROTOCOL_01
			IR_SEND_PROTOCOL_02
			IR_SEND_PROTOCOL_03
			IR_SEND_PROTOCOL_04
			IR_SEND_PROTOCOL_05
			IR_SEND_PROTOCOL_06
			IR_SEND_PROTOCOL_07
			IR_SEND_PROTOCOL_08
			IR_SEND_PROTOCOL_09
			IR_SEND_PROTOCOL_10
			IR_SEND_PROTOCOL_11
			IR_SEND_PROTOCOL_12
			IR_SEND_PROTOCOL_13
			IR_SEND_PROTOCOL_14
			IR_SEND_PROTOCOL_90 //Add additional 15, 16 etc. above this 
			IR_SEND_PROTOCOL_91
			IR_SEND_PROTOCOL_92
			IR_SEND_RAW	//Must be last one.
		}
	}
};
#endif  //IRLIBSENDBASE_H

#endif //IRLIB_COMBO_H
