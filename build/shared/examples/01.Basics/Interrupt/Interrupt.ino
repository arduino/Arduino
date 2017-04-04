/*
  Interrupt
  Use a pushbutton to control an LED; powered by interrupts.

  This sample uses an interrupt service routine (ISR) named `blink` to toggle
  a global state variable and then uses the built-in LED to display the value
  of the cached state to the user. The work of updating the cached state happens
  asychronously in the interrupt service routine.

  This sample can easily be modified from behaving as a button into behaving as
  a switch, by changing the interrupt mode from CHANGE to LOW. Futhermore, this
  example can be modified to update the built-in LED from inside in the ISR,
  which would allow the loop function to be empty yet still allow actions and
  reactions to occur.

  This example code is in the public domain (adapted from
  https://www.arduino.cc/en/Reference/attachInterrupt).

  adapted 1 APR 2017
  by Zachary J. Fields
*/

const byte interruptPin = 2;
volatile byte state = LOW;

void blink () {
  state = !state;  // toggle the cached state
}

// the setup function runs once when you press reset or power the board
void setup () {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  // initialize digital pin as input with pull-up resistor (i.e. always HIGH, unless deliberately pulled LOW)
  pinMode(interruptPin, INPUT_PULLUP);
  // attach an interrupt service routine to be executed when pin state changes
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink, CHANGE);
}

// the loop function runs over and over again forever
void loop () {
  // update the LED to reflect the cached state updated with interrupts
  digitalWrite(LED_BUILTIN, state);
}

