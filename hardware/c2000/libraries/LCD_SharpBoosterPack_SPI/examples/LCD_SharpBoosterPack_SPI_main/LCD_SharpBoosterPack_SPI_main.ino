//
//  Sharp BoosterPackLCD SPI
//  Example for library for Sharp BoosterPack LCD with hardware SPI
//
//
//  Author :  Stefan Schauer
//  Date   :  Jan 29, 2014
//  Version:  1.00
//  File   :  LCD_SharpBoosterPack_SPI_main.ino
//
//  Version:  1.01 : added support for CC3200
//
//  Based on the LCD5110 Library
//  Created by Rei VILO on 28/05/12
//  Copyright (c) 2012 http://embeddedcomputing.weebly.com
//  Licence CC = BY SA NC
//

// Include application, user and local libraries
#include "SPI.h"
#include "OneMsTaskTimer.h"
#include "LCD_SharpBoosterPack_SPI.h"

// Variables
LCD_SharpBoosterPack_SPI myScreen;
uint8_t k = 0;
uint16_t count = 0;


// Add setup code
void setup() {
    myScreen.begin();
    
    myScreen.setFont(1);
    myScreen.text(10, 10, "Hello!");
    myScreen.flush();  
    
    delay(1000);
    myScreen.clear();
}

// Add loop code
void loop() {
    k++;
    myScreen.clearBuffer();
    myScreen.setFont(0);
    myScreen.text(k, 10, "ABCDE", LCDWrapNone);
    for (uint8_t i=10; i<LCD_HORIZONTAL_MAX-10; i++) {
      myScreen.setXY(i,20,1);
    }

    myScreen.text(10,30,String(count++,10));
    
    for (uint8_t i=0; i<=20; i++) {
      myScreen.setXY(50+i,30,1);
    }
    for (uint8_t i=0; i<=20; i++) {
      myScreen.setXY(50,30+i,1);
    }
    for (uint8_t i=0; i<=20; i++) {
      myScreen.setXY(50+i,50,1);
    }
    for (uint8_t i=0; i<=20; i++) {
      myScreen.setXY(70,30+i,1);
    }
    
    myScreen.setFont(1);
    myScreen.setCharXY(10, 40);
    myScreen.print("ABC");
    myScreen.setFont(0);
    myScreen.setCharXY(60, 60);
    myScreen.print(0x7F, HEX);
    myScreen.print(0x81, HEX);
    myScreen.setCharXY(10, 60);
    myScreen.println("Break!");
    myScreen.print("ABC\nabc");
    myScreen.flush();  
    delay(200);
}