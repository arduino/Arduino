/* IRLibRecvPCI.h 
 * Part of IRLib Library for Arduino receiving, decoding, and sending
 * infrared signals. See COPYRIGHT.txt and LICENSE.txt for more information.
 *
 * You should include this header in your sketch if you're using the IRLibRecvPCI
 * receiver class which uses pin change interrupts to poll the input pin.
 * This version gives more accurate results than the 50us timer based IRrecv but it has
 * other limitations. It uses the Arduino "attachInterrupt()" function which can conflict
 * with other libraries. Also unless you use an external buffer and enable auto resume
 * this receiver occasionally fails to receive the second of 2 quickly sent frames.
 * If you do not have sufficient RAM for a second buffer you should consider using the
 * other two available receiver classes.
 * Applications that do sending only SHOULD NOT include this header.  
 *
 * This receiver is based in part on Arduino firmware for use with AnalysIR IR signal analysis
 * software for Windows PCs. Many thanks to the people at http://analysir.com for their 
 * assistance in developing this section of code.
 */

#ifndef IRLibRecvPCI_h
#define IRLibRecvPCI_h
#include "IRLibRecvBase.h"

class IRrecvPCI: public IRrecvBase {
public:
  IRrecvPCI(void){};  //Use only when receiver object is part of larger object. 
                      // Still must initialize using constructor below.
  IRrecvPCI(uint8_t pin);
  void enableIRIn(void); //call to initialize or resume receiving
  bool getResults(void); //returns true if new frame of data has been received
  void disableIRIn(void); //ISR runs continuously once started. Use this if you want to stop.
private:
  uint8_t intrNum;
};
#endif //IRLibRecvPCI_h
