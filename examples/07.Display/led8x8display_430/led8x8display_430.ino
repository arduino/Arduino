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
 * This demo also uses the MIC and Buzzer (some kind of scope)
 *
 * TODO
 * ~~~~
 * - Use hardware SPI and interrupts instead of bit-banging  
 */
#include "font.h"
 
// MIC and Buzzer
#define AIN 0 // Note: AIN0 == pin2
#define BUZ1 3
#define BUZ2 4

// The 8x8 led matrix
#define LATCH 6
#define CLOCK 7
#define DATA 14
#define DELAYTIME 1 // microseconds to wait after setting pin

#define TILES 6 // number of tiles
#define SPEED 4 // smaller number is faster 


// The string to display:
const char *str = "}} Hello  World... good morning! }}";


// Image buffer, you can modify the bits and they will be displayed on the 8x8 matrix with the sendImage() function
unsigned char image[8*TILES];


/**
*** setup()
*** Enable the output pins
**/
void setup()
{
  memset(image,0xFF,sizeof(image));
  pinMode(BUZ1, OUTPUT);
  pinMode(BUZ2, OUTPUT); // note: also switch
  pinMode(CLOCK, OUTPUT);
  pinMode(DATA, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(PUSH2, INPUT_PULLUP);
  analogReference(INTERNAL1V5);
}

// Read switch status
boolean button()
{
  return digitalRead(PUSH2) == 0;
}

// send bits to tiles, each 8x8 tile receives 16 bits to LED tile (bits 0..7 are column, 8..15 are row) 
void sendData(unsigned short data)
{
  for(unsigned short i=0; i<16; i++)
  {
    if ( data & ((unsigned short)1<<i)  )
      digitalWrite(DATA, 1);
    else
      digitalWrite(DATA, 0);
    nop();
    digitalWrite(CLOCK,1);
    nop();
    digitalWrite(CLOCK,0);
  }
}

// scan an image on the LED tile
// 8x8 bitmap img is the input
void sendImage(unsigned char *img)
{
  unsigned short data;
  for(unsigned int i=0;i<8;i++)
  {
    for(unsigned int n=0;n<TILES;n++)
    {
      data = (1<<8)<<i;
      data |= *(img+i+(8*n));
      sendData(data);
    }
     // Latch data 
  nop();
  digitalWrite(LATCH,1);
  nop(); 
  digitalWrite(LATCH,0);
  }

 
}

// Shift alls bytes in the image right and add a byte in the display buffer
void shiftRight(unsigned char c)
{
  for(unsigned short i=((8*TILES)-1); i>1; i--)
    image[i] = image[i-1];
  image[0] = c;
}

// Shift all bytes in the image buffer left and add byte in the display buffer
void shiftLeft(unsigned char c)
{
  for(unsigned short i=0; i<((8*TILES)-1); i++)
    image[i] = image[i+1];
  image[(8*TILES)-1] = c;
}

#define ABS(a) ( (a<0 ? -a : a) )

// tone: activate buzzer with frequency
void tone(int t)
{
  for(int i=0;i<20000/t;i++)
  {
    digitalWrite(BUZ1, 1);
    for(int j=0;j<t;j++) nop();
    digitalWrite(BUZ1, 0);
    for(int j=0;j<t;j++) nop();
  }
}

/**
*** main loop, keep refreshing the image
**/
void loop()
{
  int a =0, i=0, j=0, now=0, avg=0, prev=0, val=0;
  sineWave();
  for(i=0;i<20;i++)
   tone(500*i);
  showText(str);
  
  while(1)
  {
    sendImage(image);
    if ( a++ > SPEED ) // shift in new line
    {  
      a=0;      
      now = analogRead(AIN)/2;
      if ( now < 0 ) now = -now;
      avg = (15 * avg + now) / 16;
      val = ABS(avg-prev);
      shiftLeft(  128>>val );
      if ( button() )
        avg = 0;
      tone(100*val);    
      prev = avg;
    }
  } 
}

// Sinewave example
void sineWave()
{
  static const unsigned char wave[] = {4,5,6,6,7,7,7,6,6,5,4,3,2,1,1,0,0,0,1,1,2,3,4};
  unsigned char j = 0, q;
  for(int i=0; i<60;i++)
  {
    j = i % sizeof(wave);
    tone(600+200*wave[j]); 
    shiftLeft(1 << wave[j]);
    for(q=0; q<2; q++) sendImage(image);
  }
}


// display a text on the 8x8 display
void showText(const char *txt)
{
  int a =0, i=0, j=0;
  while(1)
  {
    sendImage(image);
    if ( a++ > SPEED ) // shift in new line
    {  
      a=0;
      if ( j < 5 ) // copy character
        shiftLeft( *(fontPtr(txt[i]) + (unsigned int)j) );
      else
      {
        shiftLeft(0); // blank line
        sendImage(image);
      // tone(500);
      }
      if ( ++j > 5 ) // next character
      {
        j = 0;
        if ( ++i >= strlen(txt) ) 
          return; 
      } 
    }
  } 
}
