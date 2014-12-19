/*
  CogLCD Library - Autoscroll
  Derived from:
  LiquidCrystal Library - Autoscroll
 
 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the 
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.
 
 This sketch demonstrates the use of the autoscroll()
 and noAutoscroll() functions to make new text scroll or not.
 
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

 http://arduino.cc/en/Tutorial/LiquidCrystalAutoscroll

 */

// include the library code:
#include <SPI.h>
#include <CogLCD.h>

#define LCD_CSB 13
#define LCD_RS 12
#define LCD_RST 11
#define LCD_SI 15
#define LCD_SCL 7

// initialize the library with the numbers of the interface pins
CogLCD lcd(LCD_SI, LCD_SCL, LCD_RS, LCD_CSB, LCD_RST);

void setup() {
  // set up the LCD's number of columns and rows: 
  lcd.begin(16,2);
}

void loop() {
  // set the cursor to (0,0):
  lcd.setCursor(0, 0);
  // print from 0 to 9:
  for (int thisChar = 0; thisChar < 10; thisChar++) {
   lcd.print(thisChar);
   delay(500);
  }

  // set the cursor to (16,1):
  lcd.setCursor(16,1);
  // set the display to automatically scroll:
  lcd.autoscroll();
  // print from 0 to 9:
  for (int thisChar = 0; thisChar < 10; thisChar++) {
    lcd.print(thisChar);
    delay(500);
  }
  // turn off automatic scrolling
  lcd.noAutoscroll();
  
  // clear screen for the next loop:
  lcd.clear();
}

