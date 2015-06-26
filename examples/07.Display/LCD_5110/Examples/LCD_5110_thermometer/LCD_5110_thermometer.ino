//
//  LCD_5110_main.pde
//  Sketch 
//  ----------------------------------
//  Developed with embedXcode
//
//  Project LCD 5110
//  Created by Rei VILO on 28/05/12
//  Copyright (c) 2012 http://embeddedcomputing.weebly.com
//  Licence CC = BY SA NC
//

// Core library
#if defined(__MSP430G2553__) // LaunchPad MSP430G2553 specific
#include "Energia.h"
#else
#error Board not supported
#endif

// Include application, user and local libraries
#include "LCD_5110.h"
#include "Thermometer_430.h"

// Variables
// Option 1: parameters with suggested pins
//LCD_5110 myScreen(P2_4, P2_3, P2_2, P2_1, P2_0, P2_5, PUSH2);

//#define _pinChipSelect  P2_4
//#define _pinSerialClock P2_3
//#define _pinSerialData  P2_2
//#define _pinDataCommand P2_1
//#define _pinReset       P2_0
//#define _pinBacklight   P2_5
//#define _pinPushButton  PUSH2

// Option 2: no parameters, pins compatible with LCD BoosterPack / Nokia 7110
LCD_5110 myScreen;

//LCD_5110(P2_2,    // Chip Select *
//         P2_4,    // Serial Clock *
//         P2_0,    // Serial Data *
//         P2_3,    // Data/Command *
//         P1_0,    // Reset *
//         P2_1,    // Backlight
//         PUSH2);  // Push Button 0


Thermometer_430 myThermometer;
boolean	backlight = false;


// Add setup code 
void setup() {   
    myScreen.begin();
    
    myScreen.setFont(0);
    myScreen.text(0, 0, "Hello");
    myScreen.setFont(1);
    myScreen.text(1, 2, "MSP430");
    
    delay(1000);
    myThermometer.begin();
    
    myScreen.clear();
    myScreen.setFont(0);
    myScreen.text(0, 0, "Thermometer");
    myScreen.text(0, 5, "Light off");
    
}

// Display mask
char display[8] = {' ', ' ', ' ', '.', ' ', 0x7f, 'C', 0x00};


// Add loop code 
void loop() {
    if (myScreen.getButton()) {
        backlight = ~backlight;
        myScreen.setFont(0);
        myScreen.text(0, 5, backlight ? "Light on " : "Light off");
        myScreen.setBacklight(backlight);
    }
    
    myThermometer.get();
    
    // Temperature display 
    int32_t number = myThermometer.temperatureX10();
    
	boolean flag = (number<0);
    if (flag) number = -number;
    
    display[4] = 0x30 + (number%10);
    number /= 10;
    display[2] = 0x30 + (number%10);
    number /= 10;
	if (number>0) {
        display[1] = 0x30 + (number%10);  
    } else if (flag) { 
        display[1] = '-';
        flag = false;
    } else {
        display[1] = ' ';   
    }
    number /= 10;
	if (number>0) display[0] = 0x30 + (number%10);
    else if (flag) display[0] = '-';
    else display[0] = ' ';
    
    myScreen.setFont(1);
    myScreen.text(0, 2, display);
    
    delay(500);
}


