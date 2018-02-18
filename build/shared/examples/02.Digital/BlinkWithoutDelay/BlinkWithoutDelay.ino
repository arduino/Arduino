/*
  Blink without Delay

  Turns on and off a light emitting diode (LED) connected to a digital pin,
  without using the delay() function. This means that other code can run at the
  same time without being interrupted by the LED code.

  The circuit:
  - Use the onboard LED.
  - Note: Most Arduinos have an on-board LED you can control. On the UNO, MEGA
    and ZERO it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN
    is set to the correct LED pin independent of which board is used.
    If you want to know what pin the on-board LED is connected to on your
    Arduino model, check the Technical Specs of your board at:
    https://www.arduino.cc/en/Main/Products

  created 2005
  by David A. Mellis
  modified 8 Feb 2010
  by Paul Stoffregen
  modified 11 Nov 2013
  by Scott Fitzgerald
  modified 9 Jan 2017
  by Arturo Guadalupi
  modified 18 Feb 2018
  by Alex Scott

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/BlinkWithoutDelay
*/

// Unchangeable constant to hold our blink interval in milliseconds:
const long interval = 1000;

// Setup a variable to hold our LED state
int ledState = LOW;

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time LED was updated

void setup() {
  // Set the digital pin as output:
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // This is where you'd put code that needs to be running all the time.

  // Check to see if it's time to blink the LED; that is, if the difference
  // between the current time and last time you blinked the LED is greater than
  // the interval at which you want to blink the LED.
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // Save the last time you blinked the LED
    previousMillis = currentMillis;

    // Inverse the state of our LED pin:
    ledState = !ledState;

    // Set the LED with the updated LED state:
    digitalWrite(LED_BUILTIN, ledState);
  }
}