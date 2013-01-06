///
/// @mainpage	SRAM
///
/// @details	Library for 23K640 SPI SRAM
/// @n		Microchip 23K640 is a SPI 64Kb = 8KB SRAM
/// @n
/// @n @a	Developed with [embedXcode](http://embedXcode.weebly.com)
///
/// @author	Rei VILO
/// @author	embedXcode.weebly.com
/// @date	Jan 06, 2013
/// @version	102
///
/// @copyright	© Rei VILO, 2012
/// @copyright	CC = BY NC SA
///
/// @see	ReadMe.txt for references
/// *		23A640/23K640 64K SPI Bus Low-Power Serial SRAM Data Sheet
/// @n		http://ww1.microchip.com/downloads/en/DeviceDoc/22126E.pdf
/// *		Recommended Usage of Microchip 23X256/23X640 SPI Serial SRAM Devices
/// @n		http://ww1.microchip.com/downloads/en/AppNotes/01245C.pdf

///
/// @file	SRAM_main.ino
/// @brief	Main sketch
/// @n		This example
/// *	prints 130 columns, saves them into the SRAM,
/// *	then reads them back from SRAM and prints them again.
///
/// @details	101
/// @n @a	Developed with [embedXcode](http://embedXcode.weebly.com)
///
/// @author	Rei VILO
/// @author	embedXcode.weebly.com
/// @date	Jan 06, 2013
/// @version	102
///
/// @copyright	© Rei VILO, 2012
/// @copyright	CC = BY NC SA
///
/// @see	ReadMe.txt for references
/// @n
///


#include "Energia.h"


// Core library for code-sense
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
#error Platform not defined
#endif

// Include application, user and local libraries
#include "SPI.h"
#include "SRAM.h"

// Define variables and constants

// Core library for code-sense
#include "Energia.h"

// Define variables and constants
#if defined(__MSP430G2553__)
SRAM mySRAM(P1_4); // chip select on pin P1_4
#elif defined(__LM4F120H5QR__)
SRAM mySRAM(PE_5); // chip select on pin PE_5
#else
#error Board not supported
#endif

const uint16_t MAX = 130;
uint8_t modulo = 26;
char buffer[MAX];
uint8_t i = 'A';

void setup (void)
{
#if defined(__MSP430G2553__)
    SPI.begin();
    SPI.setClockDivider(SPI_CLOCK_DIV2); // for MSP430G2553
#elif defined(__LM4F120H5QR__)
    SPI.begin(2);
    SPI.setClockDivider(SPI_CLOCK_DIV2); // for LM4F120H5QR
#endif
    
    mySRAM.begin();
    
    // For the example
    Serial.begin (9600);
    Serial.println("*** start");
    Serial.println("*** PUSH2 to close serial");
    Serial.println();
    
    if (MAX < modulo) modulo = MAX;
    pinMode(PUSH2, INPUT_PULLUP);
    
    Serial.print("      :");
    for (uint8_t j=0; j<MAX; j++) {
        if ( ((j+1) % 10==0) && ((j+1)/100>0) ) Serial.print((j+1)/100, DEC);
        else Serial.print(" ");
    }
    Serial.println();
    
    Serial.print("      :");
    for (uint8_t j=0; j<MAX; j++) {
        if ((j+1) % 10==0) Serial.print(((j+1)/10) %10, DEC);
        else Serial.print(" ");
    }
    Serial.println();
    
    Serial.print("      :");
    for (uint8_t j=0; j<MAX; j++) {
        if ((j+1) % 10==0) Serial.print("0");
        else Serial.print(" ");
    }
    Serial.println();
}


void loop (void)
{
    Serial.print("write >");
    for (uint8_t j=0; j<MAX; j++) {
        buffer[j]='.';
        if ((j % modulo)+ 'A' == i) buffer[j]=i;
        Serial.print((char)buffer[j]);
    }
    
    i++;
    if (i>modulo+'A') i = 'A';
    Serial.print(" (");
    Serial.print(i - 'A', DEC);
    Serial.print(")");
    Serial.println();
    
    mySRAM.write(300, (uint8_t *) buffer, sizeof buffer);
    
    for (uint8_t j=0; j<MAX; j++) buffer[j]='-';
    
    Serial.print("read  <");
    
    mySRAM.read(300, (uint8_t *) buffer, MAX);
    
    for (uint8_t j=0; j<MAX; j++) {
        Serial.print((char)buffer[j]);
    }
    Serial.println();
    delay(1000);
    
    if (!digitalRead(PUSH2)) {
        Serial.print("*** ");
        while (!digitalRead(PUSH2));
        Serial.println("end");
        Serial.end();
        while (true) delay(100);
        
    }
}




