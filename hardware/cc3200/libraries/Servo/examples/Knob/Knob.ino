// Controlling a servo position using a potentiometer (variable resistor) 
// by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>
// Modified for Energia/Stellaris Launchpad by Kevin Balke <fughilli@gmail.com>

#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
 
int potpin = PE_4;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin 
 
void setup() 
{ 
  myservo.attach(PF_1);  // attaches the servo on Port F, pin 1 (Red LED pin) to the servo object 
} 
 
void loop() 
{ 
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 4095) 
  val = map(val, 0, 4095, 0, 179);     // scale it to use it with the servo (value between 0 and 180) 
  myservo.write(val);                  // sets the servo position according to the scaled value 
  delay(15);                           // waits for the servo to get there 
} 