#include "IRremote.h"
#include "IRremoteTools.h"
#include <Arduino.h>

#ifdef AVR_ROBOT_CONTROL || AVR_ROBOT_MOTOR
int RECV_PIN = TKD2; // the pin the IR receiver is connected to
IRrecv irrecv(RECV_PIN); // an instance of the IR receiver object
decode_results results; // container for received IR codes

void beginIRremote(){
	irrecv.enableIRIn(); // Start the receiver
}

bool IRrecived(){
	return irrecv.decode(&results);
}

void resumeIRremote(){
    irrecv.resume(); // resume receiver
}

unsigned long getIRresult(){
	return results.value;
}
#endif