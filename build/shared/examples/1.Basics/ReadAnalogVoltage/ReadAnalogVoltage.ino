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
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin A3:
  int sensorValue = analogRead(A3);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 3V):
  float voltage = sensorValue * (3.0 / 1023.0);
  // print out the value you read:
  Serial.println(voltage);
}