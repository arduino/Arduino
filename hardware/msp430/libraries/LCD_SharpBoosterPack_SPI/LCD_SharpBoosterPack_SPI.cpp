//
//  LCD_SharpBoosterPack_SPI.cpp
//  Library C++ code
//  ----------------------------------
//  Developed with embedXcode
//
//  Project LCD 5110
//  Created by Rei VILO on Jan 12, 2013
//  Copyright (c) 2012 http://embeddedcomputing.weebly.com
//  Licence CC = BY SA NC
//

#include <msp430.h>
#include "LCD_SharpBoosterPack_SPI.h"
#include "spi.h"

uint8_t _pinReset;
uint8_t _pinSerialData;
uint8_t _pinDISP;
uint8_t _pinVCC;
uint8_t _pinChipSelect;
uint8_t _pinSerialClock;

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


#define spi_transmit(x) SPI.transfer(x)

#define LCD_VERTICAL_MAX    96
#define LCD_HORIZONTAL_MAX  96

#define SHARP_SEND_TOGGLE_VCOM_COMMAND      0x01
#define SHARP_SKIP_TOGGLE_VCOM_COMMAND      0x00

#define SHARP_LCD_TRAILER_BYTE              0x00

#define SHARP_VCOM_TOGGLE_BIT               0x40

#define SHARP_LCD_CMD_CHANGE_VCOM           0x00
#define SHARP_LCD_CMD_CLEAR_SCREEN          0x20
#define SHARP_LCD_CMD_WRITE_LINE            0x80

unsigned char DisplayBuffer[LCD_VERTICAL_MAX][LCD_HORIZONTAL_MAX/8];
unsigned char VCOMbit= 0x40;
unsigned char flagSendToggleVCOMCommand = 0;

static void SendToggleVCOMCommand(void);
//static void spi_transmit(uint8_t c);	
#define spi_transmit(x) SPI.transfer(x)
static void write(uint8_t x, uint8_t y, uint8_t d);
	
LCD_SharpBoosterPack_SPI::LCD_SharpBoosterPack_SPI() {
    LCD_SharpBoosterPack_SPI(P_CS,    // Chip Select
                 P_VCC,   // Vcc display
                 P_DISP   // DISP
	);
}


LCD_SharpBoosterPack_SPI::LCD_SharpBoosterPack_SPI(uint8_t pinChipSelect, uint8_t pinDISP, uint8_t pinVCC) {
    _pinChipSelect  = pinChipSelect;
    _pinDISP = pinDISP;
    _pinVCC  = pinVCC;
}

// static void spi_transmit(uint8_t c) {
	   // /* Wait for previous tx to complete. */
   // while (!(UCB0IFG & UCTXIFG))
      // ;
   // /* Setting TXBUF clears the TXIFG flag. */
   // UCB0TXBUF = c;
// }

static void write(uint8_t x, uint8_t y, uint8_t d)
{
	DisplayBuffer[y][x] = ~d;
}

void LCD_SharpBoosterPack_SPI::setXY(uint8_t x, uint8_t y, uint8_t  ulValue) {
    if( ulValue != 0)
        DisplayBuffer[y][x>>3] &= ~(0x80 >> (x & 0x7));
    else
        DisplayBuffer[y][x>>3] |= (0x80 >> (x & 0x7));
}

#define SPI_CLOCK_DIV1   1
#define SPI_CLOCK_DIV2   2
#define SPI_CLOCK_DIV4   4
#define SPI_CLOCK_DIV8   8
#define SPI_CLOCK_DIV16  16
#define SPI_CLOCK_DIV32  32
#define SPI_CLOCK_DIV64  64
#define SPI_CLOCK_DIV128 128

void LCD_SharpBoosterPack_SPI::begin() {
    pinMode(_pinChipSelect, OUTPUT);
    pinMode(_pinDISP, OUTPUT);
    pinMode(_pinVCC, OUTPUT);

    digitalWrite(_pinChipSelect, LOW);
    digitalWrite(_pinVCC, HIGH);
    digitalWrite(_pinDISP, HIGH);

   /* Put USCI in reset mode, source USCI clock from SMCLK. */
//   UCB0CTLW0 = UCSWRST | UCSSEL_2;

   /* SPI in master MODE 0 - CPOL=0 SPHA=0. */
//   UCB0CTLW0 |= UCCKPH | UCMSB | UCSYNC | UCMST;

   /* P1.6 as SIMO and P1.7 as SOMI. */
//   P1SEL1 |= BIT6 | BIT7;

   /* P2.2 as SCK. */
//   P2SEL1 |= BIT2;

   /* Set initial speed to 4MHz. */
//   UCB0BR0 = SPI_CLOCK_DIV4 & 0xFF;
//   UCB0BR1 = (SPI_CLOCK_DIV4 >> 8 ) & 0xFF;

   /* Release USCI for operation. */
//   UCB0CTLW0 &= ~UCSWRST;
    
	TA0_enableVCOMToggle();
	
    clear();
    _font = 0;
}

String LCD_SharpBoosterPack_SPI::WhoAmI() {
    return "Sharp LCD BoosterPack";
}

void LCD_SharpBoosterPack_SPI::clear() {
	
  unsigned char command = SHARP_LCD_CMD_CLEAR_SCREEN;                            //clear screen mode(0X100000b)
  command = command^VCOMbit;                    //COM inversion bit

  // Set P2.4 High for CS
  digitalWrite(_pinChipSelect, HIGH);

  spi_transmit(command);
  flagSendToggleVCOMCommand = SHARP_SKIP_TOGGLE_VCOM_COMMAND;
  spi_transmit(SHARP_LCD_TRAILER_BYTE);

  // Wait for last byte to be sent, then drop SCS
  __delay_cycles(100);

  // Set P2.4 High for CS
  digitalWrite(_pinChipSelect, LOW);

  initializeDisplayBuffer();
  
}

void LCD_SharpBoosterPack_SPI::setFont(uint8_t font) {
    _font = font;
}

void LCD_SharpBoosterPack_SPI::text(uint8_t x, uint8_t y, String s) {
    uint8_t i;
    uint8_t j;
    uint8_t offset = 0;;
    
    if (_font==0) {
        for (j=0; j<s.length(); j++) {
            for (i=0; i<5; i++) write(x, y+offset++,Terminal6x8[s.charAt(j)-' '][i]);
			offset += 1;  // spacing
        }
    }
    else if (_font==1) {
        for (j=0; j<s.length(); j++) {
            for (i=0; i<11; i++) {
				write(x+1, y+offset,  Terminal11x16[s.charAt(j)-' '][2*i]);
				write(x,   y+offset++,Terminal11x16[s.charAt(j)-' '][2*i+1]);
			}
			offset += 1;  // spacing
        }
    }
}

void LCD_SharpBoosterPack_SPI::initializeDisplayBuffer()
{
    unsigned int i=0,j=0;
    for(i =0; i< LCD_VERTICAL_MAX; i++)
    for(j =0; j< (LCD_HORIZONTAL_MAX>>3); j++)
       DisplayBuffer[i][j] = 0xff;
}

uint8_t reverse(uint8_t x)
{
  const uint8_t a[] = {0x0, 0x8, 0x4, 0xC, 0x2, 0xA, 0x6, 0xE, 0x1, 0x9, 0x5, 0xD, 0x3, 0xB, 0x7, 0xF};
  uint8_t b = 0;
  
  b  = a[x & 0xF]<<4;
  b |= a[(x & 0xF0)>>4];
  return b;
}


void LCD_SharpBoosterPack_SPI::flush (void)
{
	unsigned char *pucData = &DisplayBuffer[0][0];
    long xi =0;
    long xj = 0;
    //image update mode(1X000000b)
    unsigned char command = SHARP_LCD_CMD_WRITE_LINE;

    command |= BIT7;
    //COM inversion bit
    command = command^VCOMbit;
    // Set P2.4 High for CS
    digitalWrite(_pinChipSelect, HIGH);

    spi_transmit((char)command);
    flagSendToggleVCOMCommand = SHARP_SKIP_TOGGLE_VCOM_COMMAND;
    for(xj=0; xj<LCD_VERTICAL_MAX; xj++)
    {
		spi_transmit((char)reverse(xj + 1));
///		spi_transmit(xj);

        for(xi=0; xi<(LCD_HORIZONTAL_MAX>>3); xi++)
        {
			spi_transmit((char)*(pucData++));
        }
        spi_transmit(SHARP_LCD_TRAILER_BYTE);
    }

    spi_transmit((char)SHARP_LCD_TRAILER_BYTE);

    __delay_cycles(100);

    // Set P2.4 Low for CS
    digitalWrite(_pinChipSelect, LOW);
}

static void SendToggleVCOMCommand(void)
{
    VCOMbit ^= SHARP_VCOM_TOGGLE_BIT;

    if(SHARP_SEND_TOGGLE_VCOM_COMMAND == flagSendToggleVCOMCommand)
    {
        unsigned char command = SHARP_LCD_CMD_CHANGE_VCOM;                            //clear screen mode(0X100000b)
        command = command^VCOMbit;                    //COM inversion bit

		// Set P2.4 High for CS
		digitalWrite(_pinChipSelect, HIGH);

        spi_transmit((char)command);
        spi_transmit((char)SHARP_LCD_TRAILER_BYTE);

        // Wait for last byte to be sent, then drop SCS
        __delay_cycles(100);
		// Set P2.4 High for CS
		digitalWrite(_pinChipSelect, LOW);
    }
	
    flagSendToggleVCOMCommand = SHARP_SEND_TOGGLE_VCOM_COMMAND;
}

void LCD_SharpBoosterPack_SPI::TA0_enableVCOMToggle()
{
	TA0CTL = TASSEL__ACLK | ID__8 | TACLR | MC__UP;
    TA0CCTL0 = CCIE;
	TA0CCR0 = 4096;
}


void LCD_SharpBoosterPack_SPI::TA0_turnOff()
{
	TA0CTL = 0;
    TA0CCTL0 = 0;
}

#pragma vector=TIMER0_A0_VECTOR
__interrupt void TA0_ISR(void)
{
    SendToggleVCOMCommand();
}