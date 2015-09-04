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
//  Edited 2015-07-11 by ReiVilo
//  Added setOrientation(), setReverse() and flushReverse()
//

// Include application, user and local libraries
#include "SPI.h"
#include "OneMsTaskTimer.h"
#include "LCD_SharpBoosterPack_SPI.h"

// Variables
LCD_SharpBoosterPack_SPI myScreen;
uint8_t myOrientation = 0;
uint16_t myCount = 0;


// Add setup code
void setup() {
    Serial.begin(9600);

    myScreen.begin();
    myScreen.clearBuffer();
    
    myScreen.setFont(1);
    myScreen.text(10, 10, "Hello!");
    myScreen.flush();
    
    for (uint8_t i=0; i<20; i++) delay(100);
    myScreen.reverseFlush();
    for (uint8_t i=0; i<20; i++) delay(100);
    
    myScreen.clear();
    
    for (uint8_t i=0; i<4; i++)
    {
        myScreen.setOrientation(i);
        myScreen.text(10, 10, String(i));
        myScreen.flush();
    }
    for (uint8_t i=0; i<20; i++) delay(100);
    
    Serial.print("myCount = ");
}

// Add loop code
void loop()
{
    myCount++;
    Serial.print(-myCount, DEC);
    if (myCount > 16)
    {
        myOrientation++;
 //       if (myOrientation > 4) myOrientation = 0;
        myOrientation %= 4;
        myScreen.setOrientation(myOrientation);
        myCount = 0;
        Serial.println();
        Serial.print("** myOrientation = ");
        Serial.println(myOrientation, DEC);
        Serial.print("myCount = ");
    }
    myScreen.clearBuffer();
    myScreen.setFont(0);
    
    myScreen.text(myCount, 10, "ABCDE", LCDWrapNone);
    for (uint8_t i=10; i<LCD_HORIZONTAL_MAX-10; i++) {
        myScreen.setXY(i,20,1);
    }
    
    myScreen.text(10,30,String(myCount,10));
    
    for (uint8_t i=0; i<=20; i++) {
        myScreen.setXY(50+i,30,1);
        //    }
        //    for (uint8_t i=0; i<=20; i++) {
        myScreen.setXY(50,30+i,1);
        //    }
        //    for (uint8_t i=0; i<=20; i++) {
        myScreen.setXY(50+i,50,1);
        //    }
        //    for (uint8_t i=0; i<=20; i++) {
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
    
    for (uint8_t i=0; i<2; i++) delay(100);
}
