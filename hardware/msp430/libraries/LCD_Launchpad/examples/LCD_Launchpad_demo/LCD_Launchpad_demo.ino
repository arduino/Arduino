//
//  Launchpad LCD
//  Example for library for Lauchpad LCD
//
//
//  Author :  Stefan Schauer
//  Date   :  June 23, 2014
//  Version:  1.00
//  File   :  LCD_Launchpad_demo.ino
//
//

// Include application, user and local libraries
 #include "LCD_Launchpad.h"

// Variables
LCD_LAUNCHPAD myLCD;

// Add setup code
void setup() {
    myLCD.init();
    
    myLCD.displayText("Hello");
    
    delay(1000);
    myLCD.clear();

    myLCD.showSymbol(LCD_SEG_RADIO, 1);
    delay(400);
    myLCD.showSymbol(LCD_SEG_TX, 1);
    delay(400);
    myLCD.showSymbol(LCD_SEG_RX, 1);
    delay(400);
	
    myLCD.showSymbol(LCD_SEG_HEART, 1);
    delay(400);
    myLCD.showSymbol(LCD_SEG_MARK, 1);
    delay(400);
    myLCD.showSymbol(LCD_SEG_CLOCK, 1);
    delay(400);
    myLCD.showSymbol(LCD_SEG_R, 1);
    delay(400);

    myLCD.showSymbol(LCD_SEG_BAT_ENDS, 1);
    delay(400);
    myLCD.showSymbol(LCD_SEG_BAT_POL, 1);
    delay(1000);
    myLCD.showSymbol(LCD_SEG_BAT0, 1);
    delay(200);
    myLCD.showSymbol(LCD_SEG_BAT1, 1);
    delay(200);
    myLCD.showSymbol(LCD_SEG_BAT2, 1);
    delay(200);
    myLCD.showSymbol(LCD_SEG_BAT3, 1);
    delay(200);
    myLCD.showSymbol(LCD_SEG_BAT4, 1);
    delay(200);
    myLCD.showSymbol(LCD_SEG_BAT5, 1);
    delay(200);
    myLCD.showSymbol(LCD_SEG_BAT_POL, 1);
    delay(1000);
    myLCD.showSymbol(LCD_SEG_BAT0, 0);
    delay(200);
    myLCD.showSymbol(LCD_SEG_BAT1, 0);
    delay(200);
    myLCD.showSymbol(LCD_SEG_BAT2, 0);
    delay(200);
    myLCD.showSymbol(LCD_SEG_BAT3, 0);
    delay(200);
    myLCD.showSymbol(LCD_SEG_BAT4, 0);
    delay(200);
    myLCD.showSymbol(LCD_SEG_BAT5, 0);
    delay(200);

    myLCD.showSymbol(LCD_SEG_MINUS1, 1);
    delay(400);
    myLCD.showSymbol(LCD_SEG_DOT1, 1);
    delay(400);
    myLCD.showSymbol(LCD_SEG_COLON2, 1);
    delay(400);
    myLCD.showSymbol(LCD_SEG_DOT2, 1);
    delay(400);
    myLCD.showSymbol(LCD_SEG_DOT3, 1);
    delay(400);
    myLCD.showSymbol(LCD_SEG_COLON4, 1);
    delay(400);
    myLCD.showSymbol(LCD_SEG_DOT4, 1);
    delay(400);
    myLCD.showSymbol(LCD_SEG_DOT5, 1);
    delay(400);
    myLCD.showSymbol(LCD_SEG_DEG5, 1);
    delay(1000);

	
	
}

// Add loop code
void loop() {
	uint16_t count = 0;
	
    myLCD.clear();
    myLCD.displayText("ABCDE");
    delay(1000);

    myLCD.clear();
    count = 0;
    while (count <= 150){
      myLCD.println(count++);
      delay(50);
    }
    delay(1000);
    
    myLCD.clear();
    myLCD.showChar('1', 1);
    myLCD.showChar('3', 3);
    myLCD.showChar('5', 5);
    delay(1000);
    myLCD.clear();
    myLCD.print("543");
    delay(1000);
    myLCD.println("21");
    delay(1000);
    myLCD.print("XYZ\nxyz");
    delay(1000);
    myLCD.println("");
    myLCD.clear();
}
