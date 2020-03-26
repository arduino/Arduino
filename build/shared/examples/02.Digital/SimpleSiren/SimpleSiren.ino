/*
  SimpleSiren

  Description:
  Haven't we all used horns / sirens. Just a touch on switch and siren blows.
  Just a tap back and its stops honking. This library provides just this.
  A bare minimum framework simulating a siren functioning.

  A buzzer which is connected to digital pin 13 is blown,
  when pressing a pushbutton attached to pin 2.

  The circuit:
  - Buzzer attached from pin 13 to ground
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground

  - Note: on most Arduinos do NOT come with a Buzzer on the board
    hence has to be attached to pin 13.

  created March 2020,
  by Manthan Admane

*/

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int buzzerPin =  13;      // the number of the Buzzer pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the Buzzer pin as an output:
  pinMode(buzzerPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn Buzzer on:
    digitalWrite(buzzerPin, HIGH);
  } else {
    // turn Buzzer off:
    digitalWrite(buzzerPin, LOW);
  }
}
