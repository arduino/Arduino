/*
  String Case changes
  Examples of how to change the case of a string
 
  created 27 July 2010
  modified 2 Apr 2012
  by Tom Igoe
 
  Hardware Required:
  * MSP-EXP430G2 LaunchPad
 
 This example code is in the public domain.
*/

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);

  // send an intro:
  Serial.println("\n\nString  case changes:");
  Serial.println();
}

void loop() {
  // toUpperCase() changes all letters to upper case:
  String stringOne = "";
  Serial.println(stringOne);
  stringOne.toUpperCase();
  Serial.println(stringOne);

  // toLowerCase() changes all letters to lower case:  
  String stringTwo = "";
  Serial.println(stringTwo);
  stringTwo.toLowerCase();
  Serial.println(stringTwo);


  // do nothing while true:
  while(true);
}
