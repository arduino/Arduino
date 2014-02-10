/* AbsoluteMouse.ino
 
    For ATmega32U4 based boards (like the Leonardo and Micro)

    * This code is an API demo for the USB HID Absolute Mouse positioning API.
      It does not require any circut external to your Arduino

    Created 12 Jan 2014
    by Jesse Vincent <jesse@keyboard.io>

    This sample code is in the public domain.
*/


void setup() {
    Mouse.begin();
}

void loop() {

    Mouse.moveAbsolute(16384,16384); // Jump to the center of the screen
    delay(2500);
    Mouse.moveAbsolute(0, 0); // X position, Y position
    delay(2500);
    Mouse.moveAbsolute(0, 32767); 
    delay(2500);
    Mouse.moveAbsolute(32767, 32767); 
    delay(2500);
    Mouse.moveAbsolute(32767,0); 
    delay(2500);
}



