/// 
/// @mainpage	LCD_Colour_main 
/// @details	<#details#>
/// @n 
/// @n 
/// @n @a	Developed with [embedXcode](http://embedXcode.weebly.com)
/// 
/// @author	Rei VILO
/// @author	http://embeddedcomputing.weebly.com
/// @date	09/07/12 20:26
/// @version	<#version#>
/// 
/// @copyright	© Rei VILO, 2012
/// @copyright	CC = BY NC SA
///
/// @see	ReadMe.txt for references
///


///
/// @file	LCD_Colour_main.pde 
/// @brief	Main sketch
/// @details	<#details#>
/// @n @a	Developed with [embedXcode](http://embedXcode.weebly.com)
/// 
/// @author	Rei VILO
/// @author	http://embeddedcomputing.weebly.com
/// @date	09/07/12 20:26
/// @version	<#version#>
/// 
/// @copyright	© Rei VILO, 2012
/// @copyright	CC = BY NC SA
///
/// @see	ReadMe.txt for references
/// @n
///


// Core library
#if defined(__MSP430G2452__) || defined(__MSP430G2553__) || defined(__MSP430G2231__) // LaunchPad specific
#include "Energia.h"
#else
#error Board not supported
#endif


// Include application, user and local libraries
#include "LCD_Colour.h"
#include "Thermometer_430.h"

// Variables
LCD_Colour myScreen;
Thermometer_430 myThermometer;
boolean	backlight = false;


// Add setup code 
void setup() {   
    myThermometer.begin();
    
    myScreen.begin();
    
//    myScreen.setBacklight(backlight);
    myScreen.text(0, 0, "Hello!");
    
    myScreen.setFont(1);
    myScreen.text(0, 2, " MSP430");
    myScreen.setFont(0);
    myScreen.text(0, 5, "1234567890abcdef");
    
    delay(1000);
    myScreen.clear();
    myScreen.text(2, 0, "Thermometer");
    myScreen.text(0, 7, "Light off");
    
}

// Display mask
char c[8] = {' ', ' ', ' ', '.', ' ', 0x7f, 'C', 0x00};


// Add loop code 
void loop() {
    if (myScreen.getButton()) {
        backlight = ~backlight;
        myScreen.setFont(0);
        myScreen.text(0, 7, backlight ? "Light on " : "Light off");
//        myScreen.setBacklight(backlight);
    }
	delay(500);
    
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
    } else if (flag) { 
        c[1] = '-';
        flag = false;
    } else {
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


