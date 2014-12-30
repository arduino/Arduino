#include "LiquidCrystal.h"

#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include "Arduino.h"

// define WS0010 if you are to use WINSTAR OLED
#undef WS0010
//#define WS0010

// When the display powers up, it is configured as follows:
//
// 1. Display clear
// 2. Function set: 
//    DL = 1; 8-bit interface data 
//    N = 0; 1-line display 
//    F = 0; 5x8 dot character font 
// 3. Display on/off control: 
//    D = 0; Display off 
//    C = 0; Cursor off 
//    B = 0; Blinking off 
// 4. Entry mode set: 
//    I/D = 1; Increment by 1 
//    S = 0; No shift 
// #ifdef WS0010
// 5. Cursor/Display shift/Mode / Pwr
//    G/C = 0: Character mode
//    Pwr = 1: Internal DCDC power on
// #endif
//
// Note, however, that resetting the Arduino doesn't reset the LCD, so we
// can't assume that its in that state when a sketch starts (and the
// LiquidCrystal constructor is called).

#ifndef WS0010
#define LCD_FONT 0x00
#else
//#define LCD_FONT 0x00 // Japanese font
//#define LCD_FONT 0x01 // European I font
#define LCD_FONT 0x02 // Russian font
//#define LCD_FONT 0x03 // European II font
#endif

LiquidCrystal::LiquidCrystal(uint8_t rs, uint8_t rw, uint8_t enable,
			     uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
			     uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7)
{
  init(0, rs, rw, enable, d0, d1, d2, d3, d4, d5, d6, d7);
}

LiquidCrystal::LiquidCrystal(uint8_t rs, uint8_t enable,
			     uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
			     uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7)
{
  init(0, rs, 255, enable, d0, d1, d2, d3, d4, d5, d6, d7);
}

LiquidCrystal::LiquidCrystal(uint8_t rs, uint8_t rw, uint8_t enable,
			     uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3)
{
  init(1, rs, rw, enable, d0, d1, d2, d3, 0, 0, 0, 0);
}

LiquidCrystal::LiquidCrystal(uint8_t rs,  uint8_t enable,
			     uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3)
{
  init(1, rs, 255, enable, d0, d1, d2, d3, 0, 0, 0, 0);
}

void LiquidCrystal::init(uint8_t fourbitmode, uint8_t rs, uint8_t rw, uint8_t enable,
			 uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
			 uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7)
{
  _rs_pin = rs;
  _rw_pin = rw;
  _enable_pin = enable;
  
  _data_pins[0] = d0;
  _data_pins[1] = d1;
  _data_pins[2] = d2;
  _data_pins[3] = d3; 
  _data_pins[4] = d4;
  _data_pins[5] = d5;
  _data_pins[6] = d6;
  _data_pins[7] = d7; 
  
  
  if (fourbitmode)
    _displayfunction = LCD_4BITMODE | LCD_1LINE | LCD_5x8DOTS | LCD_FONT;
  else 
    _displayfunction = LCD_8BITMODE | LCD_1LINE | LCD_5x8DOTS | LCD_FONT;

}

void LiquidCrystal::begin(uint8_t cols, uint8_t lines, uint8_t dotsize) {
  // Deferred initialization from init()
  // as Edison (or standard C++) fail to call these within the constructor
  digitalWrite(_rs_pin, LOW);
  pinMode(_rs_pin, OUTPUT);
  // we can save 1 pin by not using RW. Indicate by passing 255 instead of pin#
  if (_rw_pin != 255) {
    digitalWrite(_rw_pin, LOW);
    pinMode(_rw_pin, OUTPUT);
  }
  digitalWrite(_enable_pin, LOW);
  pinMode(_enable_pin, OUTPUT);

  if (lines > 1) {
    _displayfunction |= LCD_2LINE;
  }
  _numlines = lines;
  _currline = 0;

  // for some 1 line displays you can select a 10 pixel high font
  if ((dotsize != 0) && (lines == 1)) {
    _displayfunction |= LCD_5x10DOTS;
  }

  // SEE PAGE 45/46 FOR INITIALIZATION SPECIFICATION!
  // according to datasheet, we need at least 40ms after power rises above 2.7V
  // before sending commands. Arduino can turn on way before 4.5V so we'll wait 50
  // Edit: WS0010 needs > 500ms besides HD44780 needs > 40ms @3V, >15ms @5V
  // we'd better wait 500
  delay(500);

  //put the LCD into 4 bit or 8 bit mode
  if (! (_displayfunction & LCD_8BITMODE)) {
#ifndef WS0010
    // this is according to the hitachi HD44780 datasheet
    // figure 24, pg 46

    // we start in 8bit mode, try to set 4 bit mode
    write4bits(0x03);
    delayMicroseconds(4100); // wait min 4.1ms

    // second try
    write4bits(0x03);
    delayMicroseconds(100); // wait min 100us
    
    // third go!
    write4bits(0x03); 
    delayMicroseconds(37); // wait min 37us
#else
    // the above initialize sequence doesn't work for WS0010.
    // because LCD_FUNCTIONSET command [0:0:1:DL:N:F:FT1:FT0] has extra FT1 and FT0
    // bits that HD44780 doesn't care. the lower 4-bits are floating during 
    // the initialization and WS0010 doesn't like to be reset the font ROM so frequently.
    // but don't worry WS0010 has special sequence consists of five 0's for soft-resetting!
    // cf.
    //    http://blog.digit-parts.com/pdf/wsoled_app.pdf
    //    http://www.winstar.com.tw/UserFiles/downloads/13370715900854524584.pdf (p.43)
    for (int i = 0; i < 5; i++) {
      write4bits(0);
    }
#endif
    // the interface is confirmed to be 8-bit
    // switch 8-bit to 4-bit
    write4bits(0x02); 
    delayMicroseconds(37); // wait min 37us

    // finally, set # lines, font size, etc.
    write4bits((LCD_FUNCTIONSET | _displayfunction)>>4);  
    write4bits(LCD_FUNCTIONSET | _displayfunction);  
  } else {
    // this is according to the hitachi HD44780 datasheet
    // page 45 figure 23

    // Send function set command sequence
    write8bits(LCD_FUNCTIONSET | _displayfunction);
    delayMicroseconds(4100); // wait min 4.1ms

    // second try
    write8bits(LCD_FUNCTIONSET | _displayfunction);
    delayMicroseconds(100); // wait min 100us

    // third go
    write8bits(LCD_FUNCTIONSET | _displayfunction);
    delayMicroseconds(37); // wait min 37us

    // finally, set # lines, font size, etc.
    write8bits(LCD_FUNCTIONSET | _displayfunction);  
  }
  if (_rw_pin == 255)
    delayMicroseconds(37); // wait min 37us

  // turn the display on with no cursor or blinking default
  _displaycontrol = LCD_DISPLAYON | LCD_CURSOROFF | LCD_BLINKOFF;  
  // Initialize to default text direction (for romance languages)
  _displaymode = LCD_ENTRYLEFT | LCD_ENTRYSHIFTDECREMENT;

#ifdef WS0010
  // display off
  noDisplay();
  // character mode and internal power on
  command(LCD_CURSORSHIFT | 0x07); // [G/C:PWR:1:1] = [0:1:1:1]
  // clear display
  clear();
  // return home
  home();
  // entry mode set
  command(LCD_ENTRYMODESET | _displaymode);
  // display on
  display();
#else
  display();

  // clear it off
  clear();

  command(LCD_ENTRYMODESET | _displaymode);
#endif
}

/********** high level commands, for the user! */
void LiquidCrystal::clear()
{
  command(LCD_CLEARDISPLAY);  // clear display, set cursor position to zero
  if (_rw_pin == 255)
    delayMicroseconds(6200);  // for WS0010 min 6.2ms @ fosc=250kHz
}

void LiquidCrystal::home()
{
  command(LCD_RETURNHOME);  // set cursor position to zero
  if (_rw_pin == 255)
    delayMicroseconds(1520);  // min 1.52ms @ fosc=270kHz
}

void LiquidCrystal::setCursor(uint8_t col, uint8_t row)
{
  int row_offsets[] = { 0x00, 0x40, 0x14, 0x54 };
  if ( row >= _numlines ) {
    row = _numlines-1;    // we count rows starting w/0
  }
  
  command(LCD_SETDDRAMADDR | (col + row_offsets[row]));
}

// Turn the display on/off (quickly)
void LiquidCrystal::noDisplay() {
  _displaycontrol &= ~LCD_DISPLAYON;
  command(LCD_DISPLAYCONTROL | _displaycontrol);
}
void LiquidCrystal::display() {
  _displaycontrol |= LCD_DISPLAYON;
  command(LCD_DISPLAYCONTROL | _displaycontrol);
}

// Turns the underline cursor on/off
void LiquidCrystal::noCursor() {
  _displaycontrol &= ~LCD_CURSORON;
  command(LCD_DISPLAYCONTROL | _displaycontrol);
}
void LiquidCrystal::cursor() {
  _displaycontrol |= LCD_CURSORON;
  command(LCD_DISPLAYCONTROL | _displaycontrol);
}

// Turn on and off the blinking cursor
void LiquidCrystal::noBlink() {
  _displaycontrol &= ~LCD_BLINKON;
  command(LCD_DISPLAYCONTROL | _displaycontrol);
}
void LiquidCrystal::blink() {
  _displaycontrol |= LCD_BLINKON;
  command(LCD_DISPLAYCONTROL | _displaycontrol);
}

// These commands scroll the display without changing the RAM
void LiquidCrystal::scrollDisplayLeft(void) {
  command(LCD_CURSORSHIFT | LCD_DISPLAYMOVE | LCD_MOVELEFT);
}
void LiquidCrystal::scrollDisplayRight(void) {
  command(LCD_CURSORSHIFT | LCD_DISPLAYMOVE | LCD_MOVERIGHT);
}

// This is for text that flows Left to Right
void LiquidCrystal::leftToRight(void) {
  _displaymode |= LCD_ENTRYLEFT;
  command(LCD_ENTRYMODESET | _displaymode);
}

// This is for text that flows Right to Left
void LiquidCrystal::rightToLeft(void) {
  _displaymode &= ~LCD_ENTRYLEFT;
  command(LCD_ENTRYMODESET | _displaymode);
}

// This will 'right justify' text from the cursor
void LiquidCrystal::autoscroll(void) {
  _displaymode |= LCD_ENTRYSHIFTINCREMENT;
  command(LCD_ENTRYMODESET | _displaymode);
}

// This will 'left justify' text from the cursor
void LiquidCrystal::noAutoscroll(void) {
  _displaymode &= ~LCD_ENTRYSHIFTINCREMENT;
  command(LCD_ENTRYMODESET | _displaymode);
}

// Allows us to fill the first 8 CGRAM locations
// with custom characters
void LiquidCrystal::createChar(uint8_t location, uint8_t charmap[]) {
  location &= 0x7; // we only have 8 locations 0-7
  command(LCD_SETCGRAMADDR | (location << 3));
  for (int i=0; i<8; i++) {
    write(charmap[i]);
  }
}

/*********** mid level commands, for sending data/cmds */

inline void LiquidCrystal::command(uint8_t value) {
  send(value, LOW);
}

inline size_t LiquidCrystal::write(uint8_t value) {
  send(value, HIGH);
  return 1; // assume sucess
}

/************ low level data pushing commands **********/

// write either command or data, with automatic 4/8-bit selection
void LiquidCrystal::send(uint8_t value, uint8_t mode) {
  unsigned char bitnum = (_displayfunction & LCD_8BITMODE) ? 8 : 4;
  // if there is a RW pin indicated, set it low to Write
  if (_rw_pin != 255) {
    unsigned char busy;
    for (int i = 0; i < bitnum; i++)
      pinMode(_data_pins[i], INPUT);
    digitalWrite(_rs_pin, LOW);
    digitalWrite(_rw_pin, HIGH);
    do {
#ifndef __ARDUINO_X86__
      delayMicroseconds(1);
#endif
      digitalWrite(_enable_pin, HIGH);
#ifndef __ARDUINO_X86__
      delayMicroseconds(1);
#endif
      busy = digitalRead(_data_pins[bitnum-1]);
      digitalWrite(_enable_pin, LOW);
      if (bitnum == 4) {
        pulseEnable();
      }
    } while (busy);
    digitalWrite(_rw_pin, LOW);
  }
  digitalWrite(_rs_pin, mode);
  if (bitnum == 8) {
    write8bits(value);
  } else {
    write4bits(value>>4);
    write4bits(value);
  }
  if (_rw_pin == 255)
    delayMicroseconds(37);   // commands need > 37us to settle
}

void LiquidCrystal::pulseEnable(void) {
#ifndef __ARDUINO_X86__
  delayMicroseconds(1);    
#endif  
  digitalWrite(_enable_pin, HIGH);
#ifndef __ARDUINO_X86__  
  delayMicroseconds(1);    // enable pulse must be >450ns
#endif  
  digitalWrite(_enable_pin, LOW);
}

void LiquidCrystal::write4bits(uint8_t value) {
  for (int i = 0; i < 4; i++) {
    pinMode(_data_pins[i], OUTPUT);
    digitalWrite(_data_pins[i], (value >> i) & 0x01);
  }

  pulseEnable();
}

void LiquidCrystal::write8bits(uint8_t value) {
  for (int i = 0; i < 8; i++) {
    pinMode(_data_pins[i], OUTPUT);
    digitalWrite(_data_pins[i], (value >> i) & 0x01);
  }
  
  pulseEnable();
}
