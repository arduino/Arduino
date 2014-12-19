/*
  CogLCD Library - Autoscroll
  Derived from:
  LiquidCrystal Library - setCursor
 
 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the 
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.
 
 This sketch prints to all the positions of the LCD using the
 setCursor(0 method:
 
  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 13
 * LCD Reset pin to digital pin 11
 * LCD Data pin to digital pin 15
 * LCD Clock pin to digital pin 7
 
 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe 
 modified 22 Nov 2010
 by Tom Igoe
 modified 10 Nov 2014
 by Robert Wessels (http://energia.nu)
 
 This example code is in the public domain.
 
 http://arduino.cc/en/Tutorial/LiquidCrystalSetCursor

 */

#include <SPI.h>
#include <CogLCD.h>

#define LCD_CSB 13
#define LCD_RS 12
#define LCD_RST 11
#define LCD_SI 15
#define LCD_SCL 7

// initialize the library with the numbers of the interface pins
CogLCD lcd(LCD_SI, LCD_SCL, LCD_RS, LCD_CSB, LCD_RST);

// these constants won't change.  But you can change the size of
// your LCD using them:
const int numRows = 2;
const int numCols = 16;

void setup() {
  // set up the LCD's number of columns and rows: 
  lcd.begin(numCols,numRows);
}

void loop() {
  // loop from ASCII 'a' to ASCII 'z':
  for (int thisLetter = 'a'; thisLetter <= 'z'; thisLetter++) {
    // loop over the columns:
    for (int thisCol = 0; thisCol < numRows; thisCol++) {
      // loop over the rows:
      for (int thisRow = 0; thisRow < numCols; thisRow++) {
        // set the cursor position:
        lcd.setCursor(thisRow,thisCol);
        // print the letter:
        lcd.write(thisLetter);
        delay(200);
      }
    }
  }
}


