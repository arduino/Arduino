// Wire Master Reader
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Reads data from an I2C/TWI slave device
// Refer to the "Wire Slave Sender" example for use with this

// Created 29 March 2006
// Edited 7 december 2014 by Mauro Mombelli

// This example code is in the public domain.


#include <Wire.h>

const unsigned long default_timeout_us = 1000UL;

void setup()
{
  Wire.begin_timeout(default_timeout_us);        // join i2c bus (address optional for master)
  Serial.begin(9600);  // start serial for output
}

void loop()
{
  Wire.requestFrom_timeout(2, 6, true, default_timeout_us);    // request 6 bytes from slave device #2

  while(Wire.available())    // slave may send less than requested
  { 
    char c = Wire.read(); // receive a byte as character
    Serial.print(c);         // print the character
  }

  delay(500);
}
