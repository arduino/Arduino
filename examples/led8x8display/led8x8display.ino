/*
 * Energia test program for Olimex MSP430-LED boosterpack
 * http://www.olimex.com/dev/msp-led8x8.html
 *
 * Copyright (c) 2012, Peter Brier (pbrier.nl - gmail.com)
 * All rights reserved.
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met: 
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer. 
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution. 
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * README
 * ~~~~~~
 *
 * The 8x8 led array is connected via two shift registers
 * 16 bits need to be shifted out, and latched.
 * Bit 7..0 (the first bits shifted out) control the high side of the array (columns)
 * Bit 15..8 (the last bits shifted out) control the low side of the array (row data)
 *
 * To display an image you need to constantly update the display: scanning the rows 
 * and update the colum data accordingly
 *
 * This program uses "bit banging" to shift out the data. Some uC have a nice SPI peripheral
 * to do this without burning CPU cycles. We're not using that (at the moment). 
 *
 * TODO
 * ~~~~
 * - Do somthing with the buzzer and mic
 * - Make some defines to desichain more displays  
 */
#include "font.h"
 
// MIC and Buzzer
#define AIN 2
#define BUZ1 3
#define BUZ2 4

// The 8x8 led matrix
#define LATCH 6
#define CLOCK 7
#define DATA 14
#define DELAYTIME 1 // microseconds to wait after setting pin

// default launchpad pins (note: they overlap with the default connection of the booster pack!)
#define SWITCH 4
#define LED1 2
#define LED2 14

// The string to display:
const char *str = "}} Hello  World... }}";




/**
*** setup()
*** Enable the output pins
**/
void setup()
{
  pinMode(BUZ1, OUTPUT);
  pinMode(BUZ2, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(DATA, OUTPUT);
  pinMode(LATCH, OUTPUT);
}

// send 16 bits to LED tile (bits 0..7 are column, 8..15 are row) 
void sendData(unsigned short data)
{
  for(unsigned short i=0; i<16; i++)
  {
   if ( data & ((unsigned short)1<<i)  )
     digitalWrite(DATA, 1);
   else
    digitalWrite(DATA, 0);
   delayMicroseconds(DELAYTIME);
   digitalWrite(CLOCK,1);
   delayMicroseconds(DELAYTIME);
   digitalWrite(CLOCK,0);
  } 
   delayMicroseconds(DELAYTIME);
  digitalWrite(LATCH,1);
   delayMicroseconds(DELAYTIME);
  digitalWrite(LATCH,0);
}

// scan an image on the LED tile
// 8x8 bitmap img is the input
void sendImage(unsigned char *img)
{
  unsigned short data;
  for(int i=0;i<8;i++)
  {
     data = (1<<8)<<i;
     data |= *img++;
     sendData(data);
  }
}


// Image buffer, you can modify the bits and they will be displayed on the 8x8 matrix
unsigned char image[8] = {  0xFF, 0xFF, 0xFF, 0xFF,  0xFF, 0xFF, 0xFF, 0xFF };


// Shift alls bytes in the image right and add a byte in the display buffer
void shiftRight(unsigned char c)
{
  image[7] = image[6];
  image[6] = image[5];
  image[5] = image[4];
  image[4] = image[3];
  image[3] = image[2];
  image[2] = image[1];
  image[1] = image[0];
  image[0] = c;
}

// Shift all bytes in the image buffer left and add byte in the display buffer
void shiftLeft(unsigned char c)
{
  image[0] = image[1];
  image[1] = image[2];
  image[2] = image[3];
  image[3] = image[4];
  image[4] = image[5];
  image[5] = image[6];
  image[6] = image[7];
  image[7] = c;
}


/**
*** main loop, keep refreshing the image
**/
void loop()
{
  int a =0, i=0, j=0;
  while(1)
  {
    sendImage(image);
    if ( a++ > 50 ) // shift in new line
    {  
      a=0;
      if ( j < 5 ) // copy character
        shiftLeft( *(fontPtr(str[i]) + (unsigned int)j) );
      else
        shiftLeft(0); // blank line
      if ( ++j > 5 ) // next character
      {
        j = 0;
        if ( ++i >= strlen(str) ) 
          i = 0; 
      }
    }
  } 
}
