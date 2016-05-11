///
/// @file		LCD_protocol100.ino
/// @brief		Main sketch
///
/// @details	Measure the speed of the screen
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
///
/// @author		Rei VILO
/// @author		http://embeddedcomputing.weebly.com
/// @date		Oct 05, 2013
/// @version	104
///
/// @copyright	(c) Rei VILO, 2013-2016 — Special edition for Energia
/// @copyright	CC = BY SA NC
///
/// @see		ReadMe.txt for references
/// @n
///


// Core library for code-sense
#if defined(WIRING) // Wiring specific
#include "Wiring.h"
#elif defined(MAPLE_IDE) // Maple specific
#include "WProgram.h"
#elif defined(MPIDE) // chipKIT specific
#include "WProgram.h"
#elif defined(DIGISPARK) // Digispark specific
#include "Arduino.h"
#elif defined(ENERGIA) // LaunchPad MSP430, Stellaris and Tiva, Experimeter Board FR5739 specific
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

// Screen selection
#define HX8353E // HX8353E K35_SPI

#if defined(K35_SPI)
#include "Screen_K35_SPI.h"
Screen_K35_SPI myScreen;

#elif defined(HX8353E)
#include "Screen_HX8353E.h"
Screen_HX8353E myScreen;

#else
#error Unknown screen
#endif

// Define variables and constants
//uint32_t chrono;



///
/// @brief      protocolSquare
/// @details    measure time to draw a square with side=pixels
/// @param      pixels number of pixels of one side
///
void protocolSquare(uint16_t pixels)
{
    if ((pixels < myScreen.screenSizeX()) && (pixels < myScreen.screenSizeY()) && (pixels > 48)) {
        
        myScreen.setOrientation(0);
        myScreen.setPenSolid(false);
        
        uint16_t x100 = (myScreen.screenSizeX()-pixels)/2;
        uint16_t y100 = (myScreen.screenSizeY()-pixels)/2;
        
        myScreen.dRectangle(x100-1, y100-1, pixels+2, pixels+2, whiteColour);
        myScreen.setPenSolid(true);
        uint32_t chrono = millis();
        myScreen.dRectangle(x100, y100, pixels, pixels, grayColour);
        chrono = millis() - chrono;
        
        myScreen.setFontSize(myScreen.fontMax());
        myScreen.gText(x100 +2, y100 +2, "(" + i32toa(pixels) + ")");
        myScreen.gText(x100 +2, y100 +pixels -myScreen.fontSizeY() -2, i32toa(chrono) + " ms");
        
        Serial.print("Square(");
        Serial.print(pixels, DEC);
        Serial.print(")\t");
        Serial.println(chrono, DEC);
    }
}


///
/// @brief      protocolCopyPaste
/// @details    measure time to copy-paste a 64x64 area
/// @param      orientation default=1
///
void protocolCopyPaste(uint8_t orientation = 1)
{
    uint32_t chrono;
    myScreen.clear();
    myScreen.setOrientation(orientation);
    
    // Image
    chrono = millis();
    for (uint8_t i=0; i<64; i++) {
        for (uint8_t j=0; j<64; j++) {
            myScreen.point(i, j, myScreen.calculateColour(4*i, 4*j, 254-2*i-2*j));
        }
    }
    
    myScreen.setPenSolid(false);
    myScreen.rectangle(1, 1, 62, 62, blackColour);
    myScreen.line(0,   0, 63, 63, whiteColour);
    myScreen.line(32,  0, 63, 63, whiteColour);
    myScreen.line(0,  32, 63, 63, whiteColour);
    myScreen.dRectangle(0, 0, 64, 64, whiteColour);
    chrono = millis() - chrono;
    
    myScreen.setFontSize(0);
    myScreen.gText(0, 66, "0: Original");
    myScreen.setFontSize(1);
    myScreen.gText(0, 76, i32toa(chrono) + " ms");
    
    Serial.print("Original(=");
    Serial.print(orientation, DEC);
    Serial.print(")\t");
    Serial.println(chrono, DEC);
    
    // Method 1
    chrono = millis();
    for (uint16_t i=0; i<64; i++) {
        for (uint16_t j=0; j<64; j++) {
            myScreen.point(myScreen.screenSizeX()/2+i, j, myScreen.readPixel(i, j));
        }
    }
    chrono = millis() - chrono;
    myScreen.setFontSize(0);
    myScreen.gText(myScreen.screenSizeX()/2, 66, "1. point readPixel");
    myScreen.setFontSize(1);
    myScreen.gText(myScreen.screenSizeX()/2, 76, i32toa(chrono) + " ms");
    
    Serial.print("point(readPixel())\t");
    Serial.println(chrono, DEC);
    
    // Method 2
    chrono = millis();
    myScreen.copyPaste(0, 0, 0, myScreen.screenSizeY()/2, 64, 64);
    chrono = millis() - chrono;
    
    myScreen.setFontSize(0);
    myScreen.gText(0, myScreen.screenSizeY()/2 +66, "2. copyPaste");
    myScreen.setFontSize(1);
    myScreen.gText(0, myScreen.screenSizeY()/2 +76, i32toa(chrono) + " ms");
    
    Serial.print("copyPaste()\t");
    Serial.println(chrono, DEC);
    
    // Method 3
    if (myScreen.isStorage()) {
        uint32_t address;
        
        chrono = millis();
        address = 100;
        myScreen.copyArea(0, 0, 64, 64, address);
        address = 100;
        myScreen.pasteArea(myScreen.screenSizeX()/2, myScreen.screenSizeY()/2, 64, 64, address);
        chrono = millis() - chrono;
        
        myScreen.setFontSize(0);
        myScreen.gText(myScreen.screenSizeX()/2, myScreen.screenSizeY()/2 +66, "3. copy-paste SRAM");
        myScreen.setFontSize(1);
        myScreen.gText(myScreen.screenSizeX()/2, myScreen.screenSizeY()/2 +76, i32toa(chrono) + " ms");
        
        Serial.print("copyArea()+pasteArea() SRAM\t");
        Serial.println(chrono, DEC);
    }
}


///
/// @brief      protocolText
/// @details    measure time to draw text in 3 fonts, 4 orientations, 10x
///
void protocolText()
{
    uint32_t chrono1, chrono2;
    uint16_t colour;
    uint8_t k = 0;

    // Serial.print("fast gText... ");
    myScreen.clear(grayColour);
    myScreen.setFontSolid(true);
    chrono1 = millis();
    for (uint8_t j=0; j<10; j++) {
        for (uint8_t i=0; i<4; i++) {
            if (k==1) colour = redColour;
            else if (k==2) colour = yellowColour;
            else if (k==3) colour = greenColour;
            else if (k==4) colour = cyanColour;
            else if (k==5) colour = blueColour;
            else  colour = violetColour;
            k++;
            k %= 7;
            
            myScreen.setPenSolid(false);
            myScreen.dRectangle(0, 0, myScreen.screenSizeX(), myScreen.screenSizeY(), colour);
            
            myScreen.setOrientation(i);
            myScreen.setFontSize(0);
            myScreen.gText(4, 4, "font 0 on " + String(i), colour);
            myScreen.setFontSize(1);
            myScreen.gText(4, 14, "font 1 on " + String(i), colour);
            myScreen.setFontSize(2);
            myScreen.gText(4, 34, "font 2 on " + String(i), colour);
        }
    }
    chrono1 = millis()-chrono1;
    Serial.print("10xFontSolid(true)\t");
    Serial.println(chrono1, DEC);
    
    // Serial.print("slow gText... ");
    myScreen.clear(grayColour);
    myScreen.setFontSolid(false);
    chrono2 = millis();
    
    for (uint8_t j=0; j<10; j++) {
        for (uint8_t i=0; i<4; i++) {
            if (k==1) colour = redColour;
            else if (k==2) colour = yellowColour;
            else if (k==3) colour = greenColour;
            else if (k==4) colour = cyanColour;
            else if (k==5) colour = blueColour;
            else  colour = violetColour;
            k++;
            k %= 7;
            
            myScreen.setPenSolid(false);
            myScreen.dRectangle(0, 0, myScreen.screenSizeX(), myScreen.screenSizeY(), colour);
            
            myScreen.setOrientation(i);
            myScreen.setFontSize(0);
            myScreen.gText(4, 4, "font 0 on " + String(i), colour);
            myScreen.setFontSize(1);
            myScreen.gText(4, 14, "font 1 on " + String(i), colour);
            myScreen.setFontSize(2);
            myScreen.gText(4, 34, "font 2 on " + String(i), colour);
        }
    }
    
    chrono2 = millis()-chrono2;
    Serial.print("10xFontSolid(false)\t");
    Serial.println(chrono2, DEC);
    
    Serial.print("Ratio%\t");
    Serial.println((uint32_t)((uint64_t)(chrono1*100)/chrono2), DEC);
    
}


// Add setup code
void setup()
{
    Serial.begin(9600);
    delay(100);
    Serial.println("*** LCD_protocol");
    Serial.println("(All times in ms)");
    
    myScreen.begin();
    Serial.println(myScreen.WhoAmI());
    Serial.print(myScreen.screenSizeX(), DEC);
    Serial.print("x");
    Serial.println(myScreen.screenSizeY(), DEC);
    
    myScreen.setFontSize(myScreen.fontMax());
    myScreen.clear(darkGrayColour);
    
    protocolSquare(300);
    protocolSquare(200);
    protocolSquare(100);
    protocolSquare(50);
    delay(2000);
    
    protocolText();
    delay(2000);
    
    if (myScreen.isReadable()) {
        protocolCopyPaste(1);
        delay(2000);
    }
    
    myScreen.clear();
    Serial.println("---");
    Serial.println();
}

// Add loop code
void loop()
{
    
}
