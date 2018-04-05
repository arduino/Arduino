/*
  Adding Strings together

  Examples of how to add Strings together
  You can also add several different data types to String, as shown here:

  created 27 Jul 2010
  modified 2 Apr 2012
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/StringAdditionOperator
*/

// declare three Strings:
String stringOne, stringTwo, stringThree;

void setup() {
  // initialize serial and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  stringOne = String("You added ");
  stringTwo = String("this string");
  stringThree = String();
  // send an intro:
  Serial.println("\n\nAdding Strings together (concatenation):");
  Serial.println();
}

void loop() {
  // adding a constant integer to a String:
  stringThree =  stringOne + 123;
  Serial.println(stringThree);    // prints "You added 123"

  // adding a constant long integer to a String:
  stringThree = stringOne + 123456789;
  Serial.println(stringThree);    // prints "You added 123456789"

  // adding a constant character to a String:
  stringThree =  stringOne + 'A';
  Serial.println(stringThree);    // prints "You added A"

  // adding a constant string to a String:
  stringThree =  stringOne +  "abc";
  Serial.println(stringThree);    // prints "You added abc"

  stringThree = stringOne + stringTwo;
  Serial.println(stringThree);    // prints "You added this string"

  // adding a variable integer to a String:
  int sensorValue = analogRead(A0);
  stringOne = "Sensor value: ";
  stringThree = stringOne  + sensorValue;
  Serial.println(stringThree);    // prints "Sensor Value: 401" or whatever value analogRead(A0) has

  // adding a variable long integer to a String:
  stringOne = "millis() value: ";
  stringThree = stringOne + millis();
  Serial.println(stringThree);    // prints "The millis: 345345" or whatever value millis() has

  // do nothing while true:
  while (true);
}
