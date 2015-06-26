//
//  LCD_5110_main.ino
//  Sketch
//  ----------------------------------
//  Developed with embedXcode
//
//  Project LCD BoosterPack for MSP430G2553 and StallarPad LM4F
//  Created by Rei VILO on 28/05/12
//  Copyright (c) 2012 http://embeddedcomputing.weebly.com
//  Licence CC = BY SA NC
//
//  Ported to LM4F120 by Bryan Schremp (bajabug@gmail.com) 11/10/2012
//


// Core library - IDE-based
#if defined(WIRING) // Wiring specific
#include "Wiring.h"
#elif defined(MAPLE_IDE) // Maple specific
#include "WProgram.h"   
#elif defined(MPIDE) // chipKIT specific
#include "WProgram.h"
#elif defined(ENERGIA) // LaunchPad, FraunchPad and StellarPad specific
#include "Energia.h"
#elif defined(CORE_TEENSY) // Teensy specific
#include "WProgram.h"
#elif defined(ARDUINO) && (ARDUINO >= 100) // Arduino 1.0 and 1.5 specific
#include "Arduino.h"
#elif defined(ARDUINO) && (ARDUINO < 100) // Arduino 23 specific
#include "WProgram.h"
#else // error
#error Board not supported
#endif

// Include application, user and local libraries
#include "LCD_5110.h"

// Variables
LCD_5110 myScreen;
boolean	backlight = false;
uint8_t k = 0;


// Add setup code
void setup() {
    myScreen.begin();
    
    myScreen.setBacklight(backlight);
    myScreen.text(0, 0, "Hello!");
    
    delay(1000);
    //  myScreen.clear();
    myScreen.text(0, 5, "Light off");
}


// Add loop code
void loop() {
    if (myScreen.getButton()) {
        backlight = (backlight==0);
        myScreen.setFont(0);
        myScreen.text(0, 5, backlight ? "Light on " : "Light off");
        myScreen.setBacklight(backlight);
    }
    
    myScreen.setFont(1);
    if (k==0)   myScreen.text(0, 2, " MSP430");
    else if (k==8)   myScreen.text(0, 2, "  LM4F  ");
    
    myScreen.setFont(0);
    for (uint8_t i=0; i<14; i++) myScreen.text(i, 4, (i==k) ? "*" : " ");
    k++;
    k %= 14;
    
    delay(200);
}




