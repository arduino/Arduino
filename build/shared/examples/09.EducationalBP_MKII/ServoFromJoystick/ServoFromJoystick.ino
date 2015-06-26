/*
 Servo Sweep example for Educational BoosterPack MK II
 http://boosterpackdepot.info/wiki/index.php?title=Educational_BoosterPack_MK_II

 The sketch demonstrates controlling a servo using an analog input from the joystick
 
 based on Knob example by Michal Rinott <http://people.interaction-ivrea.it/m.rinott> 
 
The example uses a LaunchPad with 12-bit ADC yielding analog reading in the [0,4096] 
range. Adjust the scale according when using a 10-bit/8-bit ADC.

The circuit:
* servo connected to pin 19
* analog channel from Joystick X axis connected to pin 23

Modified 03 Dec 2013
by Dung Dang

This example code is in the public domain.
*/

#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
 
int potpin = 2;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin 
 
void setup() 
{ 
  myservo.attach(19);  // attaches the servo on pin 9 to the servo object 
} 
 
void loop() 
{ 
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023) 
  val = map(val, 0, 4096, 0, 179);     // scale it to use it with the servo (value between 0 and 180) 
  myservo.write(val);                  // sets the servo position according to the scaled value 
  delay(15);                           // waits for the servo to get there 
} 
