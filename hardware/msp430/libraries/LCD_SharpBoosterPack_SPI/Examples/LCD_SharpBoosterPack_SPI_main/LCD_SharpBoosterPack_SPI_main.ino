//
// Sharp BoosterPackLCD SPI
// Example for library for Sharp BoosterPack LCD with hardware SPI
//
//
// author:  Stefan Schauer
// date:    Jan 29, 2014
// version:	1.00
//
// file:    LCD_SharpBoosterPack_SPI_main.ino
//
// see	ReadMe.txt for references
//

#include "Energia.h"

// Include application, user and local libraries
#include "SPI.h"
#include "LCD_SharpBoosterPack_SPI.h"

// Variables

LCD_SharpBoosterPack_SPI myScreen;
uint8_t k = 0;


// Add setup code
void setup() {
#if defined(__MSP430__)
    SPI.begin();
    SPI.setClockDivider(SPI_CLOCK_DIV2);
    SPI.setBitOrder(MSBFIRST);
    SPI.setDataMode(SPI_MODE0);
    
#elif defined(__LM4F120H5QR__)
    SPI.Select(2);
    SPI.begin();
    SPI.setClockDivider(SPI_CLOCK_DIV128); // for LM4F120H5QR DIV2 = 4 MHz !
#endif
    
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
    myScreen.text(k, 10, "ABCDE");
    for (uint8_t i=10; i<LCD_HORIZONTAL_MAX-10; i++) {
      myScreen.setXY(i,20,1);
    }
    
    for (uint8_t i=0; i<20; i++) {
      myScreen.setXY(50+i,30,1);
    }
    for (uint8_t i=0; i<20; i++) {
      myScreen.setXY(50,30+i,1);
    }
    for (uint8_t i=0; i<20; i++) {
      myScreen.setXY(50+i,50,1);
    }
    for (uint8_t i=0; i<20; i++) {
      myScreen.setXY(70,30+i,1);
    }
    
    myScreen.setFont(1);
    myScreen.text(10, 60, "ABC");
    myScreen.flush();  
    delay(200);
}