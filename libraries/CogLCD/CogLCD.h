/*
 * This is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * DogLcd is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with DogLcd.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Copyright 2014 Robert Wessels <make@energia.nu>
 *
 * Based on Arduino library for Dog character LCD's
 * http://code.google.com/p/doglcd/
 * Copyright: 2010 Eberhard Fahle e.fahle@wayoda.org
 * License: GNU Lesser GPL
 *
 * Based on the Educational BoosterPack Library
 * http://embedXcode.weebly.com
 * Copyright: 2013 Rei Vilo
 * License: CC = BY NC SA
 */

#include <Energia.h>
#include <Print.h>
#define LCD_CLEARDISPLAY 0x01
#define LCD_RETURNHOME 0x02
#define LCD_ENTRYMODESET 0x04
#define LCD_DISPLAYCONTROL 0x08
#define LCD_CURSORSHIFT 0x10
#define LCD_FUNCTIONSET 0x20
#define LCD_SETCGRAMADDR 0x40
#define LCD_SETDDRAMADDR 0x80

// flags for display entry mode
#define LCD_ENTRYRIGHT 0x00
#define LCD_ENTRYLEFT 0x02
#define LCD_ENTRYSHIFTINCREMENT 0x01
#define LCD_ENTRYSHIFTDECREMENT 0x00

// flags for display on/off control
#define LCD_DISPLAYON 0x04
#define LCD_DISPLAYOFF 0x00
#define LCD_CURSORON 0x02
#define LCD_CURSOROFF 0x00
#define LCD_BLINKON 0x01
#define LCD_BLINKOFF 0x00

// flags for display/cursor shift
#define LCD_DISPLAYMOVE 0x08
#define LCD_CURSORMOVE 0x00
#define LCD_MOVERIGHT 0x04
#define LCD_MOVELEFT 0x00

// flags for function set
#define LCD_8BITMODE 0x10
#define LCD_4BITMODE 0x00
#define LCD_2LINE 0x08
#define LCD_1LINE 0x00
#define LCD_5x10DOTS 0x04
#define LCD_5x8DOTS 0x00

class CogLCD : public Print {
public:
	CogLCD(uint8_t SI, uint8_t SCL, uint8_t RS, uint8_t CSB, uint8_t RST);
	void begin(uint8_t lines = 16, uint8_t rows = 2, uint8_t dotsize = LCD_5x8DOTS);
	void send(uint8_t mode, uint8_t data);

	void clear();
	void home();
	void noDisplay();
	void display();
	void noBlink();
	void blink();
	void noCursor();
	void cursor();
	void scrollDisplayLeft();
	void scrollDisplayRight();
	void leftToRight();
	void rightToLeft();
	void autoscroll();
	void noAutoscroll();
	void createChar(uint8_t, uint8_t[]);
	void setCursor(uint8_t, uint8_t); 
	virtual size_t write(uint8_t);

	void command(uint8_t);

	using Print::write;
private:
	uint8_t SI;
	uint8_t SCL;
	uint8_t RS;
	uint8_t CSB;
	uint8_t RST;
	uint8_t _displayfunction;
	uint8_t _displaycontrol;
	uint8_t _displaymode;
	uint8_t _numlines,_currline;
};
