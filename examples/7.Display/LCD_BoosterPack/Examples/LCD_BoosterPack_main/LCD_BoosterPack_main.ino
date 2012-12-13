//
//  LCD_BoosterPack_main.ino
//  Sketch
//  ----------------------------------
//  Developed with embedXcode
//
//  Project LCD BoosterPack for MSP430G2553 and StallarPad LM4F
//  Created by Rei VILO on 28/05/12
//  Copyright (c) 2012 http://embeddedcomputing.weebly.com
//  Licence CC = BY SA NC
//

// Core library
#if defined(ENERGIA) // Energia specific
#include "Energia.h"
#else
#error Board not supported
#endif

// Include application, user and local libraries
#include "LCD_7110.h"

// Variables
LCD_7110 myScreen;
boolean	backlight = false;
uint8_t k = 0;


// Add setup code
void setup() {
    myScreen.begin();
    
    myScreen.setBacklight(backlight);
    myScreen.text(0, 0, "Hello!");
    
    myScreen.setFont(0);
    myScreen.text(0, 5, "1234567890abcdef");
    
    delay(1000);
    //  myScreen.clear();
    myScreen.text(0, 7, "Light off");
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
    }
    
    myScreen.setFont(1);
    if (k==0)   myScreen.text(0, 2, " MSP430");
    else if (k==8)   myScreen.text(0, 2, "  LM4F  ");
    
    myScreen.setFont(0);
    for (uint8_t i=0; i<16; i++) myScreen.text(i, 6, (i==k) ? "*" : " ");
    k++;
    k %= 16;
    
    delay(333);
}




