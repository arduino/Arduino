///
/// @mainpage	FRAM_8_LEDs
/// @details	FraunchPad playing K2000!
/// @n
/// @n
/// @n @a	Developed with [embedXcode](http://embedXcode.weebly.com)
///
/// @author	Rei VILO
/// @author	http://embedxcode.weebly.com
/// @date	01/11/12 15:56
/// @version	101
///
/// @copyright	© Rei VILO, 2012
/// @copyright	CC = BY NC SA
///
/// @see	ReadMe.txt for references
///


///
/// @file	FRAM_8_LEDs.ino
/// @brief	Main sketch
/// @details	FraunchPad playing K2000!
/// @n @a	Developed with [embedXcode](http://embedXcode.weebly.com)
///
/// @author	Rei VILO
/// @author	http://embedxcode.weebly.com
/// @date	01/11/12 15:56
/// @version	101
///
/// @copyright	© Rei VILO, 2012
/// @copyright	CC = BY NC SA
///
/// @see	ReadMe.txt for references
/// @n
///


// Core library - MCU-based
#if defined(__MSP430FR5739__) // FraunchPad specific
#include "Energia.h"
#else
#error Platform not supported
#endif


// Include application, user and local libraries

// Define variables and constants
///
/// @brief	Table of the LEDs
///
uint8_t myLED[8];
uint8_t i;
const uint16_t PAUSE = 20; // ms
const uint16_t STAY  = 80; // ms

///
/// @brief	Setup
/// @details	Define the pins of the LEDs
///
void setup() {
  myLED[0] = LED1;
  myLED[1] = LED2;
  myLED[2] = LED3;
  myLED[3] = LED4;
  myLED[4] = LED5;
  myLED[5] = LED6;
  myLED[6] = LED7;
  myLED[7] = LED8;
  
  for (i=0; i<8; i++) {
    pinMode(myLED[i], OUTPUT);
    digitalWrite(myLED[i], LOW);
  }
}

///
/// @brief	Loop
///
void loop() {
  digitalWrite(myLED[0], HIGH);
  delay(PAUSE);
  
  for (i=1; i<8; i++) {
    digitalWrite(myLED[i], HIGH);
    delay(PAUSE);
    digitalWrite(myLED[i-1], LOW);
    delay(STAY);
  }
  
  digitalWrite(myLED[7], HIGH);
  delay(PAUSE);
  
  for (i=1; i<8; i++) {
    digitalWrite(myLED[7-i], HIGH);
    delay(PAUSE);
    digitalWrite(myLED[7-i+1], LOW);
    delay(STAY);
  }
  
}
