///
/// @file	FastDigitalWrite_main.ino
/// @brief	Example for measures
///
///
/// @n @a	Developed with [embedXcode](http://embedXcode.weebly.com)
///
/// @author	Rei VILO
/// @author	http://embedXcode.weebly.com
/// @date	Jul 08, 2013
/// @version	101
///
/// @copyright	© Rei VILO, 2013
/// @copyright	CC = BY NC SA
///
/// @see	ReadMe.txt for references
/// @n
///


// Core library for code-sense
#include "Energia.h"
#include "FastDigitalWrite.h"


void testFastPin(uint8_t pin)
{
  fastDigitalOutputPin myPin;
  uint32_t chrono;
  pinMode(pin, OUTPUT);
  Serial.println("1000 cycles, time in microseconds");
  Serial.println("1 second = 10^9 microseconds");
  Serial.println();
  Serial.print("digitalWrite()\t");
  chrono = micros();
  for (uint16_t i=0; i<1000; i++) {
    digitalWrite(pin, HIGH);
    digitalWrite(pin, LOW);
  }
  Serial.println(micros() - chrono, DEC);

  myPin.begin(pin);

  Serial.print("fast setHIGH() setLOW()\t");
  chrono = micros();
  for (uint16_t i=0; i<1000; i++) {
    myPin.setHIGH();
    myPin.setLOW();
  }
  Serial.println(micros() - chrono, DEC);

  Serial.print("fast set()\t");
  chrono = micros();
  for (uint16_t i=0; i<1000; i++) {
    myPin.set(HIGH);
    myPin.set(LOW);
  }
  Serial.println(micros() - chrono, DEC);
}

void testLogicAnalyser(uint8_t pin)
{
  fastDigitalOutputPin myPin;

  pinMode(pin, OUTPUT);
  Serial.println("digitalWrite(HIGH)");
  Serial.println("digitalWrite(LOW)");
  digitalWrite(pin, HIGH);
  digitalWrite(pin, LOW);
  delay(10);

  myPin.begin(pin);

  Serial.println("setHIGH()");
  Serial.println("setLOW()");
  myPin.setHIGH();
  myPin.setLOW();
  delay(10);
  Serial.println("pulseHIGH()");
  myPin.pulseHIGH();
  delay(10);
  Serial.println("setHIGH()");
  myPin.setHIGH();
  delay(10);
  Serial.println("pulseLOW()");
  myPin.pulseLOW();
  delay(10);
  Serial.println("pulseLOW() x2");
  myPin.pulseLOW();
  myPin.pulseLOW();
  Serial.println("setLOW()");
  myPin.setLOW();
  delay(1000);
}

void setup(void) {
  Serial.begin(9600);
  delay(100);

  Serial.println("Fast Digital Write");
  Serial.println("---");

  // Test for logical analyser
  //    testLogicAnalyser(RED_LED);

  testFastPin(RED_LED);
  Serial.println("---");
  Serial.println();

}

void loop() {

}




