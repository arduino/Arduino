  /*
  CogLCD Library - Autoscroll
  Derived from:
  LiquidCrystal Library - TextDirection
 
 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the 
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.
 
 This sketch demonstrates how to use leftToRight() and rightToLeft()
 to move the cursor.
 
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
 
 http://arduino.cc/en/Tutorial/LiquidCrystalTextDirection
 
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

int thisChar = 'a';

void setup() {
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // turn on the cursor:
  lcd.cursor();
}

void loop() {
  // reverse directions at 'm':
  if (thisChar == 'm') {
    // go right for the next letter
    lcd.rightToLeft(); 
  }
  // reverse again at 's':
  if (thisChar == 's') {
    // go left for the next letter
    lcd.leftToRight(); 
  }
  // reset at 'z':
  if (thisChar > 'z') {
    // go to (0,0):
    lcd.home(); 
    // start again at 0
    thisChar = 'a';
  }
  // print the character
  lcd.write(thisChar);
  // wait a second:
  delay(1000);
  // increment the letter:
  thisChar++;
}








