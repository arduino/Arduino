/*
  Educational BoosterPack MK II
  http://boosterpackdepot.info/wiki/index.php?title=Educational_BoosterPack_MK_II 
  
  Microphone input, LED output, serial output 
  based on Analog input, analog output, serial output
  
 Reads an analog input pin, maps the result to a range from 0 to 255
 and uses the result to set the pulsewidth modulation (PWM) of an output pin.
 Also prints the results to the serial monitor.
 
 The circuit:
 * Microphone (analog) attached to  pin 6.
   Neutral reading is at the center of the analog scale ~2048
   Higher sound input results in higher dynamic range at both
   ends of the analog scale [0,4096]
 * LED connected from pin 39 to ground
 
 created 29 Dec. 2008
 modified 30 Aug 2011
 by Tom Igoe
 modified 03 Dec 2013
 by Dung Dang for Educational BoosterPack MK II
 
 This example code is in the public domain.
 
 */

// These constants won't change.  They're used to give names
// to the pins used:
const int analogInPin = 6;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = 39; // Analog output pin that the LED is attached to

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600); 
}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);            
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 0, 4096, 0, 255);  
  // change the analog out value:
  analogWrite(analogOutPin, outputValue);           

  // print the results to the serial monitor:
  Serial.print("microphone = " );                       
  Serial.print(sensorValue);      
  Serial.print("\t output = ");      
  Serial.println(outputValue);   

  // wait 10 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(10);                     
}
