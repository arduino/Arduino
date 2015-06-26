///
/// @mainpage	FraunchPad Accelerometer
/// @details	Simple sketch for the built-in FraunchPad accelerometer
///
/// @n @a	Developed with [embedXcode](http://embedXcode.weebly.com)
///
/// @author	Rei Vilo
/// @author	http://embedxcode.weebly.com
/// @date	20/09/12 21:48
/// @version	103
///
/// @copyright	© Rei Vilo, 2012
/// @copyright	CC = BY NC SA
///
/// @see	ReadMe.txt for references
///


///
/// @file	FRAM_ACC.pde
/// @brief	Main sketch
///
/// @n @a	Developed with [embedXcode](http://embedXcode.weebly.com)
///
/// @author	Rei Vilo
/// @author	http://embedxcode.weebly.com
/// @date	20/09/12 21:48
/// @version	103
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
#error Platform not defined
#endif

// Include application, user and local libraries
#include "FraunchPad_Accelerometer.h"

// Define variables and constants
///
int32_t x, ///< x axis variable
  y, ///< y axis variable
  z; ///< z axis variable

///
/// @brief	Object
///
accelerometer_FR myAccelerometer;

///
/// @brief	Print for value X100
/// @param	i value X100
///
void printX100(int32_t i) {

  if (i<0) {
    Serial.print("-");
    i = -i;
  }
  Serial.print(i/100, DEC);
  Serial.print(".");
  Serial.print(i%100/10, DEC);
  Serial.print(i%10, DEC);
  Serial.print("\t");
}

///
/// @brief	Setup
///
// Add setup code
void setup() {
  pinMode(PUSH1, INPUT_PULLUP);
  pinMode(PUSH2, INPUT_PULLUP);
  
  myAccelerometer.begin();
  
  Serial.begin(9600);
  Serial.println(myAccelerometer.WhoAmI());
  Serial.println("press PUSH1 to calibrate");
  Serial.println("press PUSH2 to exit serial");
  delay(500);
  
  Serial.println("g:\tx\ty\tz\tdeg:\tx\ty\tz");
}

///
/// @brief	Loop
///
// Add loop code
void loop() {
  myAccelerometer.get();
  myAccelerometer.gravityX100(x, y, z);
  
  Serial.print("g:\t");
  printX100(x);
  printX100(y);
  printX100(z);
  
  myAccelerometer.degreeX100(x, y, z);
  
  Serial.print("deg:\t");
  printX100(x);
  printX100(y);
  printX100(z);
  Serial.println();
  
  delay(500);
  
  if (digitalRead(PUSH1)==LOW) {
    Serial.print("calibrate... ");
    myAccelerometer.calibrate();
    Serial.println("done");
  }
  
  if (digitalRead(PUSH2)==LOW) {
    Serial.print("exit... ");
    Serial.end();
    Serial.println("end");
    while(true); // endless loop
  }
  
}
