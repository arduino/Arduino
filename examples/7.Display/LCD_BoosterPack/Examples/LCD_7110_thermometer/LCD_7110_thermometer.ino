///
/// @mainpage	LCD7110_LM4F
/// @details	<#details#>
/// @n
/// @n
/// @n @a	Developed with [embedXcode](http://embedXcode.weebly.com)
///
/// @author	Rei VILO
/// @author	Rei VILO
/// @date	12/12/12 14:27
/// @version	<#version#>
///
/// @copyright	© Rei VILO, 2012
/// @copyright	CC = BY NC SA
///
/// @see	ReadMe.txt for references
///


///
/// @file	LCD7110_LM4F.ino
/// @brief	Main sketch
/// @details	<#details#>
/// @n @a	Developed with [embedXcode](http://embedXcode.weebly.com)
///
/// @author	Rei VILO
/// @author	Rei VILO
/// @date	12/12/12 14:27
/// @version	<#version#>
///
/// @copyright	© Rei VILO, 2012
/// @copyright	CC = BY NC SA
///
/// @see	ReadMe.txt for references
/// @n
///

//
//  LCD_BoosterPack_main.pde
//  Sketch
//  ----------------------------------
//  Developed with embedXcode
//
//  Project LCD BoosterPack
//  Created by Rei VILO on 28/05/12
//  Copyright (c) 2012 http://embeddedcomputing.weebly.com
//  Licence CC = BY SA NC
//

// Core library
#if defined(__MSP430G2553__) // LaunchPad __MSP430G2553__ specific
#include "Energia.h"
#else
#error Board not supported
#endif

// Include application, user and local libraries
#include "LCD_7110.h"
#include "Thermometer_430.h"

// Variables
LCD_7110 myScreen;
Thermometer_430 myThermometer;
boolean	backlight = false;


// Add setup code
void setup() {
  Serial.begin(9600);

  Serial.print("myThermometer.begin... ");
  myThermometer.begin();
  Serial.println("done");

  Serial.print("myScreen.begin... ");
  myScreen.begin();
  Serial.println("done");

  myScreen.setBacklight(backlight);
  myScreen.text(0, 0, "Hello!");
  Serial.println("done 1");

  myScreen.setFont(1);
  myScreen.text(0, 2, " MSP430");
  myScreen.setFont(0);
  myScreen.text(0, 5, "1234567890abcdef");
  Serial.println("done 2");

  delay(1000);
  Serial.println("done 3");

  myScreen.clear();
  myScreen.text(2, 0, "Thermometer");
  myScreen.text(0, 7, "Light off");
  Serial.println("done 4");

}

// Display mask
char c[8] = {
  ' ', ' ', ' ', '.', ' ', 0x7f, 'C', 0x00};


// Add loop code
void loop() {
  if (myScreen.getButton()) {
    backlight = (backlight==0);
    myScreen.setFont(0);
    myScreen.text(0, 7, backlight ? "Light on " : "Light off");
    myScreen.setBacklight(backlight);
    Serial.print("setBacklight... ");
    Serial.println(backlight, DEC);
  }
  delay(500);
  Serial.println("done 5");


  myThermometer.get();

  // Temperature display
  int32_t number = myThermometer.temperatureX10();

  boolean flag = (number<0);
  if (flag) number = -number;

  c[4] = 0x30 + (number%10);
  number /= 10;
  c[2] = 0x30 + (number%10);
  number /= 10;
  if (number>0) {
    c[1] = 0x30 + (number%10);
  } 
  else if (flag) {
    c[1] = '-';
    flag = false;
  } 
  else {
    c[1] = ' ';
  }
  number /= 10;
  if (number>0) c[0] = 0x30 + (number%10);
  else if (flag) c[0] = '-';
  else c[0] = ' ';

  myScreen.setFont(1);
  myScreen.text(0, 3, c);

  delay(1000);
}



