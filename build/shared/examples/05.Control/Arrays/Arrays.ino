/*
  Arrays
 
  Demonstrates the use of  an array to hold pin numbers
  in order to iterate over the pins in a sequence. 
  Lights multiple LEDs in sequence, then in reverse.
 
  Unlike the For Loop tutorial, where the pins have to be
  contiguous, here the pins can be in any random order.
 
  The circuit:
  * LEDs from pins 2 through 10 to ground
 
  created 2006
  by David A. Mellis
  modified 16 Apr 2013
  by Adrian Fernandez 
  
  Hardware Required:
  * MSP-EXP430G2 LaunchPad
  * (9) 220 ohm resistors
  * (9) LEDs
  * hook-up wire
  * breadboard

  This example code is in the public domain.
  
  2015-11-09 Rei Vilo
  * timer changed for timer_ms to avoid conflict with timer()
 
*/

int timer_ms = 100;           // The higher the number, the slower the timing.
int ledPins[] = { 
  4, 10, 2, 6, 5, 3, 7, 9, 8};       // an array of pin numbers to which LEDs are attached
int pinCount = 9;           // the number of pins (i.e. the length of the array)

void setup() {
  // the array elements are numbered from 0 to (pinCount - 1).
  // use a for loop to initialize each pin as an output:
  for (int thisPin = 0; thisPin < pinCount; thisPin++)  {
    pinMode(ledPins[thisPin], OUTPUT);      
  }
}

void loop() {
  // loop from the lowest pin to the highest:
  for (int thisPin = 0; thisPin < pinCount; thisPin++) { 
    // turn the pin on:
    digitalWrite(ledPins[thisPin], HIGH);   
    delay(timer_ms);                  
    // turn the pin off:
    digitalWrite(ledPins[thisPin], LOW);    

  }

  // loop from the highest pin to the lowest:
  for (int thisPin = pinCount - 1; thisPin >= 0; thisPin--) { 
    // turn the pin on:
    digitalWrite(ledPins[thisPin], HIGH);
    delay(timer_ms);
    // turn the pin off:
    digitalWrite(ledPins[thisPin], LOW);
  }
}
