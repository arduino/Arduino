///
/// @file	LCD_Colour.ino 
/// @brief	Main sketch
/// 
/// @n @a	Developed with [embedXcode](http://embedXcode.weebly.com)
/// 
/// @author	Rei VILO
/// @author	embedXcode.weebly.com
/// @date	déc. 15, 2012 13:34
/// @version	103
/// 
/// @copyright	© Rei VILO, 2012
/// @copyright	CC = BY NC SA
///
/// @see	ReadMe.txt for references
/// @n
///


#include "Energia.h"


// Core library
#if defined(ENERGIA) // LaunchPad specific
#include "Energia.h"
#else
#error Board not supported
#endif


// Include application, user and local libraries
#include "LCD_Colour.h"

// Variables
///
/// @brief	Screen
///
LCD_Colour myScreen;



///
/// @brief	Setup code
///
void setup() {

    myScreen.begin();
    
    myScreen.setColour(whiteColour);
    myScreen.setFont(0);
    myScreen.text(0, 0, "Hello!");

    myScreen.setColour(orangeColour);
    myScreen.point(100, 5);
    
    myScreen.setColour(yellowColour);
    myScreen.line(20, 20, 80, 60);
    
    myScreen.setPenSolid(true);
    myScreen.setColour(blueColour);
    myScreen.rectangle(50, 50, 58, 58);
    
    myScreen.setPenSolid(false);
    myScreen.setColour(greenColour);
    myScreen.rectangle(60, 60, 68, 68);
    
    myScreen.setPenSolid(true);
    myScreen.setColour(grayColour);
    myScreen.circle(20, 70, 9);
    
    myScreen.setPenSolid(false);
    myScreen.setColour(magentaColour);
    myScreen.circle(20, 92, 9);
    
    myScreen.setBacklight(false);
    delay(1000);
    myScreen.setBacklight(true);
    
    myScreen.setColour(redColour);
    myScreen.setFont(1);
    myScreen.text(40,  80, "MSP430");
    myScreen.text(40, 100, " LM4F ");
    
    myScreen.setColour(whiteColour);
    myScreen.setFont(0);
    myScreen.text(0, 130, "         1         2");
    myScreen.text(0, 140, "123456789012345678901");
    
    while(true);
}

///
/// @brief	Loop code
///
void loop() {

        
}


