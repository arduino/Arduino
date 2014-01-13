/* ConsumerAndSystemControl.ino

	Turns the computer's volume up, then turns it down. 
 
	For ATmega32U4 based boards (like the Leonardo and Micro)

	* This code is an API demo for the USB HID ConsumerControl and 
	  SystemControl APIS.
	  It does not require any circut external to your Arduino

	Created 12 Jan 2014
	by Jesse Vincent <jesse@keyboard.io>

	This sample code is in the public domain.
*/


void setup() {
	Keyboard.begin();

	// It can take a moment for the USB interface to be ready
	// after setup. Delay for a second so we don't lose the first
	// keypress.
	delay(1000); 
}

void loop() {

	Keyboard.consumerControl(CONSUMER_CONTROL_VOLUME_UP);
	delay(1000);
	Keyboard.consumerControl(CONSUMER_CONTROL_VOLUME_DOWN);
	delay(1000);


	// Some other things the consumer control API can do:

	// Keyboard.consumerControl(CONSUMER_CONTROL_VOLUME_MUTE);
	// Keyboard.consumerControl(CONSUMER_CONTROL_PLAY_PAUSE);
	// Keyboard.consumerControl(CONSUMER_CONTROL_STOP);
	// Keyboard.consumerControl(CONSUMER_CONTROL_PREV_TRACK);
	// Keyboard.consumerControl(CONSUMER_CONTROL_NEXT_TRACK);


	// If you uncomment this code, the Arduino will try to put your
	// computer to sleep after waiting for 30 seconds.
	// delay(30000); Keyboard.systemControl(SYSTEM_CONTROL_SLEEP);

	// For a complete list, of the currently supported ConsumerControl 
	// and SystemControl usages, look in cores/arduino/USBAPI.h

}



