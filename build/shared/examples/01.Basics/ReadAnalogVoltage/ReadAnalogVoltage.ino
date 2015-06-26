/*
  ReadAnalogVoltage
  Reads an analog input on pin A3, converts it to voltage, and prints the result to the serial monitor.
  Attach the center pin of a potentiometer to pin A3, and the outside pins to +3V and ground.
  
  Hardware Required:
  * MSP-EXP430G2 LaunchPad
  * Potentiometer
 
  This example code is in the public domain.
*/

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600); // msp430g2231 must use 4800
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin A3:
  int sensorValue = analogRead(A3);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 3V):
  // Can either use type int or float to store voltage, int takes up less memory and is recommend
  // Memory is a huge concern when programming microcontollers, be careful what datatypes are used 
  // in order to make the most of the available memory
  int voltage = sensorValue * (3.0 / 1023.0);  
  // You can compare the size of the code by running the program using int and then running with float
  // You will see ~4k bytes for int vs ~6k bytes for float just by changing the datatype, quite astonishing. 
  //float voltage = sensorValue * (3.0 / 1023.0);  
  
  // print out the value you read:
  Serial.println(voltage);
}