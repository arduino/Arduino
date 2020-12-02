/* IRLibGlobals.h
 * Part of IRLib Library for Arduino receiving, decoding, and sending
 * infrared signals. See COPYRIGHT.txt and LICENSE.txt for more information.
 *
 * This file replaces the previous IRLibRData.h file. It contains definition of global
 * items which are used by both the receiver and decoding classes. They have to be
 * declared global in scope because they are accessed by the ISR and you cannot pass
 * parameters nor objects to an ISR routine.
 *
 * In general, applications would not include this file. Unless you are creating your own
 * customized receiver class apart from the provided IRrcev, IRrcevPCI, or IRrcevLoop
 * classes, you can ignore the contents of this file.
 * The RECV_BUF_LENGTH is the only item you would ever modify unless you are completely
 * rewriting how the system works in general.
 */
#ifndef IRLibGlobals_h
#define IRLibGlobals_h
#include <Arduino.h>

/* Timing data is stored in a buffer by the receiver object. It is an array of
 * uint16_t that should be at least 100 entries as defined by this default below.
 * However some IR sequences will require longer buffers especially those used for
 * air conditioner controls. In general we recommend you keep this value below 255
 * so that the index into the array can remain 8 bits. This library can handle larger 
 * arrays however it will make your code longer in addition to taking more RAM.
 */
#define RECV_BUF_LENGTH 100
#if (RECV_BUF_LENGTH > 255)
	typedef uint16_t bufIndex_t;
#else
	typedef uint8_t bufIndex_t;
#endif

// Receiver states. This previously was enum but changed it to uint8_t
// to guarantee it was a single atomic 8-bit value.
#define  STATE_UNKNOWN 0
#define  STATE_READY_TO_BEGIN 1
#define  STATE_TIMING_MARK 2
#define  STATE_TIMING_SPACE 3
#define  STATE_FINISHED 4
#define  STATE_RUNNING 5
typedef uint8_t  currentState_t;
/* The structure contains information used by the ISR routines. Because we cannot
 * pass parameters to an ISR, it must be global. Values which can be changed by
 * the ISR but are accessed outside the ISR must be volatile. 
 */
typedef struct {
//These next 4 fields are initialized by the receiver class and unlikely to change once
//they have been initialized. Only change them on the fly at your own peril.
  uint8_t recvPin;    // pin number or interrupt number for receiver
  bool enableAutoResume;	//ISR can copy data to decodeBuffer and restart by itself
  uint16_t frameTimeout; //Maximum length of a SPACE before we decide the frame has ended
//Used by IRrecv only
  uint16_t frameTimeoutTicks;// = frameTimeout/USEC_PER_TICKS
  bool enableBlinkLED;
  
//These fields are both read and written inside and outside ISRs. Must be volatile.
  volatile bool decoderWantsData;	//tells ISR previous decode is finished. Buffer available.
  volatile bool newDataAvailable; //ISR flag informs getResults that data is available.
  volatile bool didAutoResume;    //ISR tells getResults we already copied, just do math.
//The buffers are filled with timing values by the ISRs. The recvLength is the number of
//entries when the frame is complete. See the note at the end of this file about buffers.
  volatile uint16_t recvBuffer[RECV_BUF_LENGTH];
//  volatile uint16_t* recvBuffer;
  volatile bufIndex_t recvLength;
//These next two fields are how the receiver communicates with the decoder. Previously
//this was accomplished by passing to the receiver a pointer to the decoder in getResults.
//However with auto resume we now may need to communicate before getResults is called.
//The decoderBuffer pointer is maintained by the decoder. It points to where the
//decoder wants the data put by the receiver. It will point to either recvGlobal.recvBuffer
//or an external buffer provided by the user via useExtnBuf. The decodeLength
//is set by the receiver telling the decoder the data length. 
  volatile uint16_t* decodeBuffer;
  volatile bufIndex_t decodeLength;
//This field accumulates the elapsed time of a MARK or SPACE. IRrecv uses it only inside
//the ISR however IRrecvPCI accesses it outside the ISR. Therefore it is volatile
//and because it is multi-byte it will need atomic guards when accessed outside the ISR.
  volatile uint32_t timer;     // state timer, counts 50uS ticks.(and other uses)
//Used by both IRrecv and IRrecvPCI.
  volatile currentState_t currentState;   // state machine  Legal values defined above.
} 
recvGlobal_t;
extern  recvGlobal_t recvGlobal; //declared in IRLibRecvBase.cpp

/****  NOTE CONCERNING BUFFER NAMES AND VOLATILITY
 * In versions of IRLib prior to 2.0 we had the capability to declare an external
 * buffer so that the receiver could resume receiving while the decoding was taking place.
 * However it was up to the decoder to notice that the data had been received via a call to
 * getResults() and it had to tell the receiver to resume. Starting with version 2.0
 * it is now possible that the receiver can automatically copy the data to the external
 * buffer and auto resume. Rather than using names like rawbuf1 and rawbuf2 we have come
 * up with a new naming system. Also irparams wasn't the most descriptive name
 * ever conceived. Here is our new naming system which we hope is slightly less confusing.
 *
 * First irparams was a structure that contained global variables used by the receiver ISR.
 * They should not be part of the receiver class because you can't pass parameters
 * to an ISR. We think recvGlobal is a better name.
 *
 * Previously the ISR did not need access to any external buffer so it only needed one
 * buffer and one length variable. If there was an external buffer, only the decoder
 * needed to access it. Now the receiver and ISR needs access to that external buffer
 * in order to implement auto resume. Therefore the extra buffer needs to be linked
 * to recvGlobal as well. The receiver puts the data in recvGlobal.recvBuffer and it's 
 * length is in recvGlobal.recvLength. It is for the receiver's internal use.
 * Additionally we have "decodeBuffer" and "decodeLength" which
 * are defined as where the decoder wants the receiver to put its data. The decoder
 * decides where decodeBuffer points. The receiver puts the data at that address
 * and has no idea where it points. The receiver puts the length in decodeLength.
 * It is the receiver's responsibility to copy the data from recvBuffer to decodeBuffer.
 * The math is always done in getResults however deciding when to do the copying is
 * a bit more complicated. If we are doing auto resume, we do a bufcpy to copy as
 * quickly as possible and defer the math until the actual poll to getResults.
 * The getResults needs to know whether it should copy or just do the math in place.
 * If you determine that by the flag didAutoResume.
 *
 * Now we tackle the volatile issue of "volatile". Aptly named because it starts flame wars.
 * In general the rule is, if data is to be accessed inside and outside an ISR you need to
 * add the volatile qualifier to its definition. This ensures that the compiler does not
 * optimize the code in such a way that a bad copy of a variable might be used. It forces
 * the compiler to fetch the data every time he uses it and not to store it in a register.
 * We are going to presume that our ISRs never interrupt themselves. I believe the volatile
 * qualifier may not be necessary because the decoder is only accessing the data once the
 * receiver is finished working with it. The only items that really need to be volatile
 * are some of the flags. However making the buffer volatile does not seem to measurably
 * slowdown the decoding process (I ran some tests). So as part of "good programming
 * practices we are marking the buffers and lengths as volatile just in case. We need not
 * use atomic blocks to access the buffer except in very rare cases.
 */ 
#define DEBUG_VALUE(l, v) Serial.print(l); Serial.print(":"); Serial.println(v,DEC);
#endif
