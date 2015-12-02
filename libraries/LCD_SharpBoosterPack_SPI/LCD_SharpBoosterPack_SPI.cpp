//
//  Sharp BoosterPackLCD SPI
//  Example for library for Sharp BoosterPack LCD with hardware SPI
//
//
//  Author :  Stefan Schauer
//  Date   :  Mar 05, 2015
//  Version:  1.02
//  File   :  LCD_SharpBoosterPack_SPI_main.c
//
//  Version:  1.01 : added support for CC3200
//  Version:  1.02 : added print class
//
//  Based on the LCD5110 Library
//  Created by Rei VILO on 28/05/12
//  Copyright (c) 2012 http://embeddedcomputing.weebly.com
//  Licence CC = BY SA NC
//
//  Edited 2015-07-11 by ReiVilo
//  Added setOrientation(), setReverse() and flushReverse()
//  Unchanged #include <OneMsTaskTimer.h>
//

#include <Energia.h>
#include "LCD_SharpBoosterPack_SPI.h"
#include "SPI.h"

uint8_t _pinReset;
uint8_t _pinSerialData;
uint8_t _pinDISP;
uint8_t _pinVCC;
uint8_t _pinChipSelect;
uint8_t _pinSerialClock;
bool    _autoVCOM;

// Booster Pack Pins
    //  7 - P2.2 for SPI_CLK mode
    // 15 - P1.6 for SPI_SIMO mode
    //  6 - P2.4 output pin for SPI_CS
    //  2 - P4.2 as output to supply the LCD
    //  5 - P4.3 as output for DISP
    // Set display's VCC and DISP pins to high


static const uint8_t P_CS   = 6;
static const uint8_t P_VCC  = 2;
static const uint8_t P_DISP = 5;

#define SHARP_LCD_TRAILER_BYTE              0x00

#define SHARP_LCD_CMD_CHANGE_VCOM           0x00
#define SHARP_LCD_CMD_CLEAR_SCREEN          0x20
#define SHARP_LCD_CMD_WRITE_LINE            0x80

unsigned char DisplayBuffer[LCD_VERTICAL_MAX][LCD_HORIZONTAL_MAX/8];

unsigned char VCOMbit = 0x40;
#define SHARP_VCOM_TOGGLE_BIT               0x40

unsigned char flagSendToggleVCOMCommand = 0;
#define SHARP_SEND_COMMAND_RUNNING          0x01
#define SHARP_REQUEST_TOGGLE_VCOM           0x02


static void SendToggleVCOMCommand(void);

uint8_t textx = 0; 
uint8_t texty = 0;
uint8_t textstartx =0; 
uint8_t textstarty =0;
uint8_t lineSpacing[NUM_OF_FONTS] = {9,16};

	
LCD_SharpBoosterPack_SPI::LCD_SharpBoosterPack_SPI() {
    LCD_SharpBoosterPack_SPI(
                 P_CS,    // Chip Select
                 P_DISP,   // DISP
                 P_VCC,   // Vcc display
                 true     // Auto VCOM
    );
}

LCD_SharpBoosterPack_SPI::LCD_SharpBoosterPack_SPI(uint8_t pinChipSelect, uint8_t pinDISP, uint8_t pinVCC, bool autoVCOM) {
    _pinChipSelect  = pinChipSelect;
    _pinDISP = pinDISP;
    _pinVCC  = pinVCC;
    _autoVCOM = autoVCOM;
}

LCD_SharpBoosterPack_SPI::LCD_SharpBoosterPack_SPI(uint8_t pinChipSelect, uint8_t pinDISP, uint8_t pinVCC) {
    LCD_SharpBoosterPack_SPI(pinChipSelect, pinDISP, pinVCC, true);
}

void LCD_SharpBoosterPack_SPI::setOrientation(uint8_t orientation)
{
    _orientation = orientation % 4;
}

void LCD_SharpBoosterPack_SPI::setReverse(bool reverse)
{
    _reverse = reverse;
}

void LCD_SharpBoosterPack_SPI::reverseFlush()
{
    for (uint8_t i=0; i< LCD_VERTICAL_MAX; i++)
    {
        for (uint8_t j=0; j< (LCD_HORIZONTAL_MAX>>3); j++)
        {
            DisplayBuffer[i][j] = 0xff ^ DisplayBuffer[i][j];
        }
    }
    flush();
}

void LCD_SharpBoosterPack_SPI::setXY(uint8_t x, uint8_t y, uint8_t  ulValue)
{
    uint8_t x0;
    uint8_t y0;

    switch (_orientation)
    {
        case 1:
            x0 = LCD_HORIZONTAL_MAX - y;
            y0 = x;
            break;

        case 2:
            x0 = LCD_HORIZONTAL_MAX - x;
            y0 = LCD_VERTICAL_MAX   - y;
            break;
            
        case 3:
            x0 = y;
            y0 = LCD_VERTICAL_MAX   - x;
            break;
            
        default:
            x0 = x;
            y0 = y;
            break;
    }

    if (_reverse) ulValue = (ulValue == 0);
    
    if (ulValue != 0)   DisplayBuffer[y0][x0>>3] &= ~(0x80 >> (x0 & 0x7));
    else                DisplayBuffer[y0][x0>>3] |=  (0x80 >> (x0 & 0x7));
}

void LCD_SharpBoosterPack_SPI::begin() {
    SPI.begin();
    //SPI.setClockDivider(SPI_CLOCK_DIV2);
    SPI.setBitOrder(MSBFIRST);
    SPI.setDataMode(SPI_MODE0);

    pinMode(_pinChipSelect, OUTPUT);
    pinMode(_pinDISP, OUTPUT);
    pinMode(_pinVCC, OUTPUT);

    digitalWrite(_pinChipSelect, LOW);
    digitalWrite(_pinVCC, HIGH);
    digitalWrite(_pinDISP, HIGH);

    if (_autoVCOM) {
        TA0_enableVCOMToggle();
    }

    clear();
    _font = 0;
    _orientation = 0;
    _reverse = false;
}

String LCD_SharpBoosterPack_SPI::WhoAmI() {
    return "Sharp LCD BoosterPack";
}

void LCD_SharpBoosterPack_SPI::clear() {
  
  unsigned char command = SHARP_LCD_CMD_CLEAR_SCREEN;
  
  // set flag to indicate command transmit is running
  flagSendToggleVCOMCommand |= SHARP_SEND_COMMAND_RUNNING;
  
  command |= VCOMbit;                    //COM inversion bit

  // Set P2.4 High for CS
  digitalWrite(_pinChipSelect, HIGH);

  SPI.transfer(command);
  SPI.transfer(SHARP_LCD_TRAILER_BYTE);

  // Wait for last byte to be sent, then drop SCS
  delayMicroseconds(10);

  // Set P2.4 High for CS
  digitalWrite(_pinChipSelect, LOW);
  
  // clear flag to indicate command transmit is free
  flagSendToggleVCOMCommand &= ~SHARP_SEND_COMMAND_RUNNING;  
  SendToggleVCOMCommand(); // send toggle if required

  clearBuffer();
  
}

void LCD_SharpBoosterPack_SPI::clearBuffer() {
    for (uint8_t i = 0; i< LCD_VERTICAL_MAX; i++)
        for (uint8_t j = 0; j< (LCD_HORIZONTAL_MAX>>3); j++)
            DisplayBuffer[i][j] = _reverse ? 0x00 : 0xff;
}

void LCD_SharpBoosterPack_SPI::setFont(tNumOfFontsType font) {
    _font = font;
}

void LCD_SharpBoosterPack_SPI::setLineSpacing(uint8_t pixel) {
    lineSpacing[_font] = pixel;
}

void LCD_SharpBoosterPack_SPI::text(uint8_t x, uint8_t y, String s) {
	text(x, y, s, LCDWrapNextLine);
}

void LCD_SharpBoosterPack_SPI::text(uint8_t x, uint8_t y, String s, tLCDWrapType wrap) {
    uint8_t i;
    uint8_t j;
    int8_t k;
    int8_t deltax = 5;
    int8_t deltay = lineSpacing[_font];
	uint8_t c;
	
	setCharXY(x, y);
    if (_font==1) {
		deltax = 11;
	}
    
	for (j=0; j<s.length(); j++) {
		c = s.charAt(j);
		if  ((wrap == LCDWrapLine)     && (textx+deltax > LCD_HORIZONTAL_MAX)) {textx = textstartx;}
		if  ((wrap == LCDWrapNextLine) && (textx+deltax > LCD_HORIZONTAL_MAX)) {textx = textstartx; texty += deltay;}
		if  (c == '\n') {textx = textstartx; texty += deltay;}
		else if  (c >= ' ') {
			if (_font==0) {
				for (i=0; i<deltax; i++){ 
					for (k=7; k>=0; k--) setXY(textx, texty+k, Terminal6x8[c-' '][i]&(1<<k));
					textx += 1;
				}
			}
			if (_font==1) {
				for (i=0; i<deltax; i++){
					for (k=7; k>=0; k--){ 
						setXY(textx, texty+k,   Terminal11x16[c-' '][2*i]&(1<<k));
						setXY(textx, texty+k+8, Terminal11x16[c-' '][2*i+1]&(1<<k));
					}
					textx += 1;
				}
			}
			textx += 1;  // spacing
		}
	}
}


void LCD_SharpBoosterPack_SPI::text(uint8_t x, uint8_t y, uint8_t c) {
	setCharXY(x, y);
	write(c);
}

size_t LCD_SharpBoosterPack_SPI::write(uint8_t c) {
    uint8_t i;
    int8_t k;
	const tLCDWrapType wrap = LCDWrapNextLine;
    int8_t deltax = 5;
    int8_t deltay = 9;
	
    if (_font==1) {
		deltax = 11;
		deltay = 16;
	}
	
	if  ((wrap == LCDWrapLine)     && (textx+deltax > LCD_HORIZONTAL_MAX)) {textx = textstartx;}
	if  ((wrap == LCDWrapNextLine) && (textx+deltax > LCD_HORIZONTAL_MAX)) {textx = textstartx; texty += deltay;}
	if  (c == '\n') {textx = textstartx; texty += deltay;}
	else if  (c >= ' ') {
		if (_font==0) {
			for (i=0; i<deltax; i++){ 
				for (k=7; k>=0; k--) setXY(textx, texty+k, Terminal6x8[c-' '][i]&(1<<k));
				textx += 1;
			}
		}
		if (_font==1) {
			for (i=0; i<deltax; i++){
				for (k=7; k>=0; k--){ 
					setXY(textx, texty+k,   Terminal11x16[c-' '][2*i]&(1<<k));
					setXY(textx, texty+k+8, Terminal11x16[c-' '][2*i+1]&(1<<k));
				}
				textx += 1;
			}
		}
		textx += 1;  // spacing
	}
}

void LCD_SharpBoosterPack_SPI::setCharXY(uint8_t x, uint8_t y) {
	textx =x; 
	texty =y;
	textstartx =x; 
	textstarty =y;
}

//*****************************************************************************
// drawImage
// Draw an Image on the display
// Image can be generated with ImageDog (check for ImageDog on GitHub)
// Header : width in pixel
//          hight in pixel/8
//
//*****************************************************************************
void LCD_SharpBoosterPack_SPI::drawImage(const uint8_t * image, uint8_t x,uint8_t y)
{
    // height in rows (row = 8 pixels), width in columns
    uint8_t height, width;

    width = *image++;
    height = (*image++)*8;

    for (uint8_t a = 0; a < height; a+=8)
    {
      uint8_t data;
      for (uint8_t i=0; i<width; i++) {
        data  = *image++;
        for (uint8_t j=0; j<8; j++) {
          data & 0x80 ? setXY(x+i,y+a+j,1) : setXY(x+i,y+a+j,0); 
          data <<= 1;
        }  
      }
    }
}

const uint8_t referse_data[] = {0x0, 0x8, 0x4, 0xC, 0x2, 0xA, 0x6, 0xE, 0x1, 0x9, 0x5, 0xD, 0x3, 0xB, 0x7, 0xF};
uint8_t reverse(uint8_t x)
{
  uint8_t b = 0;
  
  b  = referse_data[x & 0xF]<<4;
  b |= referse_data[(x & 0xF0)>>4];
  return b;
}


void LCD_SharpBoosterPack_SPI::flush (void)
{
    unsigned char *pucData = &DisplayBuffer[0][0];
    long xi =0;
    long xj = 0;
    //image update mode(1X000000b)
    unsigned char command = SHARP_LCD_CMD_WRITE_LINE;

    // set flag to indicate command transmit is running
    flagSendToggleVCOMCommand |= SHARP_SEND_COMMAND_RUNNING;
    //COM inversion bit
    command |= VCOMbit;
    // Set P2.4 High for CS
    digitalWrite(_pinChipSelect, HIGH);

    SPI.transfer((char)command);
    for(xj=0; xj<LCD_VERTICAL_MAX; xj++)
    {
        SPI.transfer((char)reverse(xj + 1));

        for(xi=0; xi<(LCD_HORIZONTAL_MAX>>3); xi++)
        {
            SPI.transfer((char)*(pucData++));
        }
        SPI.transfer(SHARP_LCD_TRAILER_BYTE);
    }

    SPI.transfer((char)SHARP_LCD_TRAILER_BYTE);
	delayMicroseconds(10);

    // Set P2.4 Low for CS
    digitalWrite(_pinChipSelect, LOW);
    // clear flag to indicate command transmit is free
    flagSendToggleVCOMCommand &= ~SHARP_SEND_COMMAND_RUNNING;  
    SendToggleVCOMCommand(); // send toggle if required
}

static void SendToggleVCOMCommand(void)
{
    if(!(flagSendToggleVCOMCommand & SHARP_REQUEST_TOGGLE_VCOM)){ // no request pending ?
        VCOMbit ^= SHARP_VCOM_TOGGLE_BIT;                 // Toggle VCOM Bit
    }

    if(flagSendToggleVCOMCommand & SHARP_SEND_COMMAND_RUNNING){
        // set request flag
        flagSendToggleVCOMCommand |= SHARP_REQUEST_TOGGLE_VCOM;
    }else{  // if no communication to LCD -> send toggle sequence now
        unsigned char command = SHARP_LCD_CMD_CHANGE_VCOM;
        command |= VCOMbit;                    //COM inversion bit

        // Set P2.4 High for CS
        digitalWrite(_pinChipSelect, HIGH);

        SPI.transfer((char)command);
        SPI.transfer((char)SHARP_LCD_TRAILER_BYTE);

        // Wait for last byte to be sent, then drop SCS
		delayMicroseconds(10);
        // Set P2.4 High for CS
        digitalWrite(_pinChipSelect, LOW);
        // clear request flag
        flagSendToggleVCOMCommand &= ~SHARP_REQUEST_TOGGLE_VCOM;
    }
}

struct OneMsTaskTimer_t timer_task = {1000, SendToggleVCOMCommand, 0, 0};

void LCD_SharpBoosterPack_SPI::TA0_enableVCOMToggle()
{
    // generate Int. each 4096*8*32768Hz = 1 sec
    //
    // Base address for first timer
    //
    OneMsTaskTimer::add(&timer_task);
	OneMsTaskTimer::start();
}


void LCD_SharpBoosterPack_SPI::TA0_turnOff()
{
  OneMsTaskTimer::stop();
}



