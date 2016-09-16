#ifndef LiquidCrystal_h
#define LiquidCrystal_h

#include <inttypes.h>
#include "Print.h"

// commands
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

class LiquidCrystal : public Print {
public:
  LiquidCrystal(const uint8_t rs, const uint8_t enable,
		const uint8_t d0, const uint8_t d1, const uint8_t d2, const uint8_t d3,
		const uint8_t d4, const uint8_t d5, const uint8_t d6, const uint8_t d7);
  LiquidCrystal(const uint8_t rs, const uint8_t rw, const uint8_t enable,
		const uint8_t d0, const uint8_t d1, const uint8_t d2, const uint8_t d3,
		const uint8_t d4, const uint8_t d5, const uint8_t d6, const uint8_t d7);
  LiquidCrystal(const uint8_t rs, const uint8_t rw, const uint8_t enable,
		const uint8_t d0, const uint8_t d1, const uint8_t d2, const uint8_t d3);
  LiquidCrystal(const uint8_t rs, const uint8_t enable,
		const uint8_t d0, const uint8_t d1, const uint8_t d2, const uint8_t d3);

  void init(const uint8_t fourbitmode, const uint8_t rs, const uint8_t rw, uint8_t enable,
		const uint8_t d0, const uint8_t d1, const uint8_t d2, const uint8_t d3,
		const uint8_t d4, const uint8_t d5, const uint8_t d6, const uint8_t d7);
    
  void begin(const uint8_t cols, const uint8_t rows, const uint8_t charsize = LCD_5x8DOTS);

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

  void setRowOffsets(const int row1, const int row2, const int row3, const int row4);
  void createChar(uint8_t, uint8_t[]);
  void setCursor(const uint8_t, const uint8_t);
  virtual size_t write(uint8_t);
  void command(const uint8_t);
  
  using Print::write;
private:
  void send(const uint8_t, const uint8_t);
  void write4bits(const uint8_t);
  void write8bits(const uint8_t);
  void pulseEnable();

  uint8_t _rs_pin; // LOW: command.  HIGH: character.
  uint8_t _rw_pin; // LOW: write to LCD.  HIGH: read from LCD.
  uint8_t _enable_pin; // activated by a HIGH pulse.
  uint8_t _data_pins[8];

  uint8_t _displayfunction;
  uint8_t _displaycontrol;
  uint8_t _displaymode;

  uint8_t _initialized;

  uint8_t _numlines;
  uint8_t _row_offsets[4];
};

#endif
