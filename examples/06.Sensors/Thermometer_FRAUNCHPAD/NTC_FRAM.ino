/// 
/// @mainpage	FraunchPad NTC Thermometer
/// @details	Simple sketch for the built-in FraunchPad NTC
/// @n 
/// @n 
/// @n @a	Developed with [embedXcode](http://embedXcode.weebly.com)
/// 
/// @author	Rei Vilo
/// @author	http://embedxcode.weebly.com
/// @date	Oct 08, 2012
/// @version	101
/// 
/// @copyright	© Rei Vilo, 2012
/// @copyright	CC = BY NC SA
///
/// @see
///
/// *		Table algorithm by larsie — Tue Apr 03, 2012 1:18 pm
/// @n		http://www.43oh.com/forum/viewtopic.php?f=10&p=18608#p18608
///
/// *		NTC table generated with TDK / Epcos NTC R/T Calculation 5.0
/// @n		http://www.epcos.com/designtools/ntc/index.html
/// @n		Select B57560G1104 for NTC 100 k = 25 oC
/// @n		with temperature scaling = 5 oC, lower limit = -25 oC and upper limit = + 75 oC
///


///
/// @file	NTC_FRAM.ino 
/// @brief	Main sketch
///
/// @n @a	Developed with [embedXcode](http://embedXcode.weebly.com)
/// 
/// @author	Rei Vilo
/// @author	http://embedxcode.weebly.com
/// @date	Oct 08, 2012
/// @version	101
/// 
/// @copyright	© Rei Vilo, 2012
/// @copyright	CC = BY NC SA
///
/// @see	ReadMe.txt for references
/// @n
///


// Core library - MCU-based
#if defined(__MSP430FR5739__) // FraunchPad only
#include "Energia.h"
#else // error
#error Platform not supported. FraunchPad only.
#endif

// Include application, user and local libraries
#include "FraunchPad_NTC.h"

// Define variables and constants
///
///
/// @brief	temperature X10
///
int32_t temperature;


///
/// @brief	NTC
///
NTC_FR myNTC;

///
/// @brief	Print for value X10
/// @param	i value X10
///
void printX10(int32_t i) {
  
  if (i<0) {
    Serial.print("-");
    i = -i;
  }
  Serial.print(i/10, DEC);
  Serial.print(".");
  Serial.print(i%10, DEC);
}

///
/// @brief	Setup
///
// Add setup code 
void setup() {
  pinMode(PUSH1, INPUT_PULLUP);
  pinMode(PUSH2, INPUT_PULLUP);
  
  myNTC.begin(); 
  
  Serial.begin(9600);
  Serial.println(myNTC.WhoAmI());
  Serial.println("press PUSH2 to exit serial");
  delay(500);
  
}

///
/// @brief	Loop
///
// Add loop code 
void loop() {
  myNTC.get();

  myNTC.celsiusX10(temperature);
  printX10(temperature);
  Serial.print(" oC\t");
  
  myNTC.fahrenheitX10(temperature);
  printX10(temperature);
  Serial.println(" oF");
  delay(500);
  
  if (digitalRead(PUSH2)==LOW) {
    Serial.print("exit... ");
    Serial.end();
    Serial.println("end");
    while(true); // endless loop
  }
}
