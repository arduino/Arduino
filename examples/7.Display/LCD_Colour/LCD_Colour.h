///
/// @mainpage	LCD_Colour Library
///
/// @details 	Library for LCD_Colour with Nokia 7110 display
/// @n		Based on Color LCD graphics library by RobG for Color LCD Booster Pack by RobG
/// @n		Uses GLCD fonts
/// @n @a	Developed with [embedXcode](http://embedXcode.weebly.com)
///
/// @author	Rei VILO
/// @author	embedXcode.weebly.com
/// @date	Dec 15, 2012
/// @version	103
///
/// @copyright	© Rei VILO, 2012
/// @copyright	CC = BY NC SA
///
/// @see
/// *		(Universal) Color LCD graphics library by RobG 22 March 2012 - 03:09 AM
/// @n		http://forum.43oh.com/topic/1956-universal-color-lcd-graphics-library/
/// *		Color LCD Booster Pack by RobG 02 February 2012 - 10:01 PM
///	@n		http://forum.43oh.com/topic/1758-color-lcd-booster-pack/
/// *		Serial_LCD Library Suite
/// @n		http://embeddedcomputing.weebly.com/serial-lcd.html
/// * 		Fonts generated with MikroElektronika GLCD Font Creator 1.2.0.0
// Core library
#if defined(ENERGIA) // LaunchPad specific
#include "Energia.h"
#else
#error Board not supported
#endif
#ifndef LCD_Colour_h
#define LCD_Colour_h
#include "Terminal6.h"
#include "Terminal12.h"
// Colours                        Red  Green Blue
//                               4321054321043210
const uint16_t blackColour   = 0b0000000000000000;
const uint16_t whiteColour   = 0b1111111111111111;
const uint16_t redColour     = 0b1111100000000000;
const uint16_t greenColour   = 0b0000011111100000;
const uint16_t blueColour    = 0b0000000000011111;
const uint16_t yellowColour  = 0b1111111111100000;
const uint16_t cyanColour    = 0b0000011111111111;
const uint16_t orangeColour  = 0b1111101111100000;
const uint16_t magentaColour = 0b1111100000001111;
const uint16_t violetColour  = 0b1111100000011111;
const uint16_t grayColour    = 0b0111101111101111;
class LCD_Colour {
public:
    LCD_Colour(uint8_t version=1);
    LCD_Colour(uint8_t pinChipSelect, uint8_t pinSerialClock, uint8_t pinSerialData, uint8_t pinDataCommand, uint8_t pinPushButton);
    void begin();
    String WhoAmI();
    void clear();
    void setFont(uint8_t font=0);
    void setColour(uint16_t colour);
    uint16_t calculateColour(uint8_t red, uint8_t green, uint8_t blue);
    uint8_t fontX();
    uint8_t fontY();
    void text(uint8_t x, uint8_t y, String s);
    void setPenSolid(boolean flag=true);
    void point(uint8_t x1, uint8_t y1);
    void line(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2);
    void rectangle(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2);
    void circle(uint8_t x1, uint8_t y1, uint8_t radius);
    void setBacklight(boolean flag=true);
    boolean getButton();
private:
    void setXY(uint8_t x, uint8_t y);
    void setArea(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2);
    void write(uint8_t dataCommand, uint8_t c);
    uint8_t _font;
    uint8_t _colourLowByte, _colourHighByte;
    uint8_t _penSolid;
};
#endif
