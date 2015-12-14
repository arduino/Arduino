/* --COPYRIGHT--,BSD
 * Copyright (c) 2015, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * --/COPYRIGHT--*/
/*******************************************************************************
 *
 * LCD_Launchpad.cpp
 *
 * Hardware abstraction layer for the FH-1138P Segmented LCD
 * on MSP-EXP430FR6989 and MSP-EXP430FR4133
 *
 * February 2015
 * E. Chen
 *
 * June 2015 StefanSch: Adopted for Energia
 *
 * Dec 12, 2015 Rei Vilo
 * 0b00000101 mask for LCDMEM[position+1] to avoid interferences with symbols
 * Tested on MSP430 FR4133 and FR6989
 *
 ******************************************************************************/

#include "LCD_Launchpad.h"
#include "string.h"


//***** Defines ***************************************************************

// Define word access definitions to LCD memories
#ifndef LCDMEMW
#define LCDMEMW    ((int*) LCDMEM) /* LCD Memory (for C) */
#endif

// Number of character positions in the display
#define LCD_NUM_CHAR                6                                             

#if defined(__MSP430_HAS_LCD_C__)
//Change based on LCD Memory locations
#define pos1 9   /* Digit A1 begins at S18 */
#define pos2 5   /* Digit A2 begins at S10 */
#define pos3 3   /* Digit A3 begins at S6  */
#define pos4 18  /* Digit A4 begins at S36 */
#define pos5 14  /* Digit A5 begins at S28 */
#define pos6 7   /* Digit A6 begins at S14 */


// Memory locations for LCD characters
const uint8_t digit_loc[ LCD_NUM_CHAR ] =
{
       pos1,                                                                    // Position 1 = Digit A1
       pos2,                                                                    // Position 2 = Digit A2
       pos3,                                                                    // Position 3 = Digit A3
       pos4,                                                                    // Position 4 = Digit A4
       pos5,                                                                    // Position 5 = Digit A5
       pos6                                                                     // Position 6 = Digit A6
};


const uint8_t symbol_loc[] [2] =
{
    {   2,   0x01},   //  LCD_SEG_MARK,
    {   2,   0x02},   //  LCD_SEG_R,
    {   2,   0x04},   //  LCD_SEG_HEART,
    {   2,   0x08},   //  LCD_SEG_CLOCK,
    {   4,   0x01},   //  LCD_SEG_DOT3,
    {   4,   0x04},   //  LCD_SEG_RADIO,
    {   6,   0x01},   //  LCD_SEG_DOT2,
    {   6,   0x04},   //  LCD_SEG_COLON2,
    {   8,   0x01},   //  LCD_SEG_RX,
    {   8,   0x04},   //  LCD_SEG_TX,
    {  10,   0x01},   //  LCD_SEG_DOT1,
    {  10,   0x04},   //  LCD_SEG_MINUS1,
    {  13,   0x10},   //  LCD_SEG_BAT_POL,
    {  13,   0x20},   //  LCD_SEG_BAT1,
    {  13,   0x40},   //  LCD_SEG_BAT3,
    {  13,   0x80},   //  LCD_SEG_BAT5,
    {  15,   0x01},   //  LCD_SEG_DOT5,
    {  15,   0x04},   //  LCD_SEG_DEG5,
    {  17,   0x10},   //  LCD_SEG_BAT_ENDS,
    {  17,   0x20},   //  LCD_SEG_BAT0,
    {  17,   0x40},   //  LCD_SEG_BAT2,
    {  17,   0x80},   //  LCD_SEG_BAT4,
    {  19,   0x01},   //  LCD_SEG_DOT4,
    {  19,   0x04},   //  LCD_SEG_COLON4,
};

// LCD memory map for numeric digits
const char digit[10][2] =
{
    {0xFC, 0x28},  /* "0" LCD segments a+b+c+d+e+f+k+q */
    {0x60, 0x20},  /* "1" */
    {0xDB, 0x00},  /* "2" */
    {0xF3, 0x00},  /* "3" */
    {0x67, 0x00},  /* "4" */
    {0xB7, 0x00},  /* "5" */
    {0xBF, 0x00},  /* "6" */
    {0xE4, 0x00},  /* "7" */
    {0xFF, 0x00},  /* "8" */
    {0xF7, 0x00}   /* "9" */
};

// LCD memory map for uppercase letters
const char alphabetBig[26][2] =
{
    {0xEF, 0x00},  /* "A" LCD segments a+b+c+e+f+g+m */
    {0xF1, 0x50},  /* "B" */
    {0x9C, 0x00},  /* "C" */
    {0xF0, 0x50},  /* "D" */
    {0x9F, 0x00},  /* "E" */
    {0x8F, 0x00},  /* "F" */
    {0xBD, 0x00},  /* "G" */
    {0x6F, 0x00},  /* "H" */
    {0x90, 0x50},  /* "I" */
    {0x78, 0x00},  /* "J" */
    {0x0E, 0x22},  /* "K" */
    {0x1C, 0x00},  /* "L" */
    {0x6C, 0xA0},  /* "M" */
    {0x6C, 0x82},  /* "N" */
    {0xFC, 0x00},  /* "O" */
    {0xCF, 0x00},  /* "P" */
    {0xFC, 0x02},  /* "Q" */
    {0xCF, 0x02},  /* "R" */
    {0xB7, 0x00},  /* "S" */
    {0x80, 0x50},  /* "T" */
    {0x7C, 0x00},  /* "U" */
    {0x0C, 0x28},  /* "V" */
    {0x6C, 0x0A},  /* "W" */
    {0x00, 0xAA},  /* "X" */
    {0x00, 0xB0},  /* "Y" */
    {0x90, 0x28}   /* "Z" */
};

LCD_LAUNCHPAD::LCD_LAUNCHPAD(void) {
}

void LCD_LAUNCHPAD::init()
{
    LCDCCTL0 &= ~LCDON;
    LCDCCTL0 = (LCDMX0 | LCDMX1
                   | LCDLP | LCDSON | LCDDIV_0 | LCDPRE_4);

	// pin assignment for FR6989 - if more Launchpads gets LCDs added this may should go to the energia_pins.h file
	LCDCPCTL0 = 0xFFD0;
	LCDCPCTL1 = 0xF83F;
	LCDCPCTL2 = 0x00F8;

    LCDCCTL0 &= ~LCDON;
    LCDCVCTL &= ~(VLCDEXT | LCDREXT | LCDEXTBIAS |R03EXT);


    // Set VLCD voltage to 3.20v
    LCDCVCTL &= ~VLCD_15;

    LCDCVCTL |= VLCD3;

    // Enable charge pump and select internal reference for it
    LCDCVCTL |= LCDCPEN;
    LCDCVCTL &= ~VLCDREF_3;

    LCDCVCTL |= VLCDREF_0;

    LCDCCPCTL &= ~(LCDCPCLKSYNC);
    LCDCCPCTL &= ~(LCDCPDIS7 | LCDCPDIS6 | LCDCPDIS5
                    | LCDCPDIS4 | LCDCPDIS3 |
                    LCDCPDIS2 | LCDCPDIS1 |
                    LCDCPDIS0);

    LCDCCPCTL |= LCDCPCLKSYNC | 0;

    // Clear LCD memory
    LCDCMEMCTL |= LCDCLRM;

    //Turn LCD on
    LCDCCTL0 |= LCDON;
}
#endif /* defined(__MSP430_HAS_LCD_C__) */

#if defined(__MSP430_HAS_LCD_E__)
//Change based on LCD Memory locations
#define pos1 4   /* Digit A1 begins at S8 */
#define pos2 6   /* Digit A2 begins at S12 */
#define pos3 8   /* Digit A3 begins at S16  */
#define pos4 10  /* Digit A4 begins at S20 */
#define pos5 2   /* Digit A5 begins at S4 */
#define pos6 18  /* Digit A6 begins at S36 */



// Memory locations for LCD characters
const uint8_t digit_loc[ LCD_NUM_CHAR ] =
{
       pos1,                                                                    // Position 1 = Digit A1
       pos2,                                                                    // Position 2 = Digit A2
       pos3,                                                                    // Position 3 = Digit A3
       pos4,                                                                    // Position 4 = Digit A4
       pos5,                                                                    // Position 5 = Digit A5
       pos6                                                                     // Position 6 = Digit A6
};


const uint8_t symbol_loc[] [2] =
{
    {  12,   0x01},   //  LCD_SEG_MARK,
    {  12,   0x02},   //  LCD_SEG_R,
    {  12,   0x04},   //  LCD_SEG_HEART,
    {  12,   0x08},   //  LCD_SEG_CLOCK,
    {   9,   0x01},   //  LCD_SEG_DOT3,
    {   9,   0x04},   //  LCD_SEG_RADIO,
    {   7,   0x01},   //  LCD_SEG_DOT2,
    {   7,   0x04},   //  LCD_SEG_COLON2,
    {  19,   0x01},   //  LCD_SEG_RX,
    {  19,   0x04},   //  LCD_SEG_TX,
    {   5,   0x01},   //  LCD_SEG_DOT1,
    {   5,   0x04},   //  LCD_SEG_MINUS1,
    {  12,   0x10},   //  LCD_SEG_BAT_POL,
    {  12,   0x20},   //  LCD_SEG_BAT1,
    {  12,   0x40},   //  LCD_SEG_BAT3,
    {  12,   0x80},   //  LCD_SEG_BAT5,
    {   3,   0x01},   //  LCD_SEG_DOT5,
    {   3,   0x04},   //  LCD_SEG_DEG5,
    {  13,   0x01},   //  LCD_SEG_BAT_ENDS,
    {  13,   0x02},   //  LCD_SEG_BAT0,
    {  13,   0x04},   //  LCD_SEG_BAT2,
    {  13,   0x08},   //  LCD_SEG_BAT4,
    {  11,   0x01},   //  LCD_SEG_DOT4,
    {  11,   0x04},   //  LCD_SEG_COLON4,
};

// LCD memory map for numeric digits
const char digit[10][2] =
{
    {0xFC, 0x28},  /* "0" LCD segments a+b+c+d+e+f+k+q */
    {0x60, 0x20},  /* "1" */
    {0xDB, 0x00},  /* "2" */
    {0xF3, 0x00},  /* "3" */
    {0x67, 0x00},  /* "4" */
    {0xB7, 0x00},  /* "5" */
    {0xBF, 0x00},  /* "6" */
    {0xE4, 0x00},  /* "7" */
    {0xFF, 0x00},  /* "8" */
    {0xF7, 0x00}   /* "9" */
};

// LCD memory map for uppercase letters
const char alphabetBig[26][2] =
{
    {0xEF, 0x00},  /* "A" LCD segments a+b+c+e+f+g+m */
    {0xF1, 0x50},  /* "B" */
    {0x9C, 0x00},  /* "C" */
    {0xF0, 0x50},  /* "D" */
    {0x9F, 0x00},  /* "E" */
    {0x8F, 0x00},  /* "F" */
    {0xBD, 0x00},  /* "G" */
    {0x6F, 0x00},  /* "H" */
    {0x90, 0x50},  /* "I" */
    {0x78, 0x00},  /* "J" */
    {0x0E, 0x22},  /* "K" */
    {0x1C, 0x00},  /* "L" */
    {0x6C, 0xA0},  /* "M" */
    {0x6C, 0x82},  /* "N" */
    {0xFC, 0x00},  /* "O" */
    {0xCF, 0x00},  /* "P" */
    {0xFC, 0x02},  /* "Q" */
    {0xCF, 0x02},  /* "R" */
    {0xB7, 0x00},  /* "S" */
    {0x80, 0x50},  /* "T" */
    {0x7C, 0x00},  /* "U" */
    {0x0C, 0x28},  /* "V" */
    {0x6C, 0x0A},  /* "W" */
    {0x00, 0xAA},  /* "X" */
    {0x00, 0xB0},  /* "Y" */
    {0x90, 0x28}   /* "Z" */
};

LCD_LAUNCHPAD::LCD_LAUNCHPAD(void) {
}

void LCD_LAUNCHPAD::init()
{
    LCDCTL0 &= ~LCDON;
	// pin assignment for FR4133 - if more Launchpads gets LCDs added this may should go to the energia_pins.h file
	LCDPCTL0 |= 0xFFFF;
	LCDPCTL1 |= 0x07FF;
	LCDPCTL2 |= 0x00F0;

	LCDCSSEL0 = 0x000F;
	
    LCDCTL0 = (LCDMX0 | LCDMX1 | LCDSSEL_0
                   | LCDLP | LCDSON | LCDDIV_2);

    // LCD Operation - Mode 3, internal 3.02v, charge pump 256Hz
    LCDVCTL = (LCDREFEN| LCDCPEN | VLCD_6 | 
	           LCDCPFSEL3 | LCDCPFSEL2 | LCDCPFSEL1 | LCDCPFSEL0);

    // Clear LCD memory
    LCDMEMCTL |= LCDCLRM | LCDCLRBM;

    // Configure COMs and SEGs
    // L0 = COM0, L1 = COM1, L2 = COM2, L3 = COM3
    //LCD_E_setPinAsCOM( LCD_E_BASE, LCD_E_SEGMENT_LINE_0, 	 );
    //LCD_E_setPinAsCOM( LCD_E_BASE, LCD_E_SEGMENT_LINE_1, LCD_E_MEMORY_COM1 );
    //LCD_E_setPinAsCOM( LCD_E_BASE, LCD_E_SEGMENT_LINE_2, LCD_E_MEMORY_COM2 );
    //LCD_E_setPinAsCOM( LCD_E_BASE, LCD_E_SEGMENT_LINE_3, LCD_E_MEMORY_COM3 );
    LCDM0W = 0x8421;
    LCDBM0W = 0x8421;

    // Select to display main LCD memory
    LCDMEMCTL &= ~LCDDISP;
    //LCDMEMCTL |= 0;

    // Turn blinking features off
    LCDBLKCTL &= ~(LCDBLKPRE2 | LCDBLKPRE1 | LCDBLKPRE0 | LCDBLKMOD_3);
    LCDBLKCTL |= (LCDBLKPRE2 | LCDBLKMOD_0);

    //Turn LCD on
    LCDCTL0 |= LCDON;
}
#endif /* defined(__MSP430_HAS_LCD_E__) */

/*
 * Display input string across LCD screen
 */
void LCD_LAUNCHPAD::displayText(String s)
{
	LCD_LAUNCHPAD::displayText(s, 0);
}

void LCD_LAUNCHPAD::displayText(String s, char pos)
{
    int length = s.length();
    int i;
    for (i=0; i<pos; i++)
    {
        showChar(' ', i);
	}
    for (i=pos; i<length; i++)
    {
        showChar(s.charAt(i-pos), i);
    }


}

void LCD_LAUNCHPAD::displayText(char *s, char pos)
{
    int length = strlen(s);
    int i;
    for (i=0; i<pos; i++)
    {
        showChar(' ', i);
	}
    for (i=pos; i<length; i++)
    {
        showChar(s[i-pos], i);
    }
}


/*
 * Scrolls input string across LCD screen from left to right
 */
void LCD_LAUNCHPAD::displayScrollText(char *s, unsigned int wait)
{
    int length = strlen(s);
    int i;
    int x = 5;
    char buffer[] = "      ";
    for (i=0; i<length+7; i++)
    {
        int t;
        for (t=0; t<6; t++)
            buffer[t] = ' ';
        int j;
        for (j=0; j<length; j++)
        {
            if (((x+j) >= 0) && ((x+j) < 6))
                buffer[x+j] = s[j];
        }
        x--;

        showChar(buffer[0], 0);
        showChar(buffer[1], 1);
        showChar(buffer[2], 2);
        showChar(buffer[3], 3);
        showChar(buffer[4], 4);
        showChar(buffer[5], 5);

        delay(wait);
    }
}


size_t LCD_LAUNCHPAD::write(uint8_t c) {
	static char position = 0;
	if (c == '\n') {position = 0; return (c);}
	if (c == '\r') {position = 0; return (c);}
	if (position >= LCD_NUM_CHAR) position = 0;
    LCD_LAUNCHPAD::showChar(c, position++);
    return (c);
}

/*
 * Displays input character at given LCD digit/position
 * Only spaces, numeric digits, and uppercase letters are accepted characters
 */
void LCD_LAUNCHPAD::showChar(char c, int position)
{
    position = digit_loc[position];
	
	if (c >= 0 && c <= 9) c+= '0';
	if (c >= 'a' && c <= 'z') c-= ('a' - 'A');	
    if (c == ' ')
    {
        // Display space
        LCDMEM[position] = 0;
        LCDMEM[position+1] = 0 | (LCDMEM[position+1] & 0b00000101);
    }
    else if (c >= '0' && c <= '9')
    {
        // Display digit
        LCDMEM[position] = digit[c-48][0];
        LCDMEM[position+1] = digit[c-48][1] | (LCDMEM[position+1] & 0b00000101);
    }
    else if (c >= 'A' && c <= 'Z')
    {
        // Display alphabet
        LCDMEM[position] = alphabetBig[c-65][0];
        LCDMEM[position+1] = alphabetBig[c-65][1] | (LCDMEM[position+1] & 0b00000101);
    }
    else
    {
        // Turn all segments on if character is not a space, digit, or uppercase letter
        LCDMEM[position] = 0xFF;
        LCDMEM[position+1] = (0xFF & ~0b00000101) | (LCDMEM[position+1] & 0b00000101);
    }
}

/*
 * Displays the given Symbol
 */
void LCD_LAUNCHPAD::showSymbol(char symbol, int status)
{
	if (status)
		LCDMEM[symbol_loc[symbol][0]] |= symbol_loc[symbol][1]; // switch on
	else
		LCDMEM[symbol_loc[symbol][0]] &= ~symbol_loc[symbol][1]; // switch off
}
/*
 * Clears memories to all 6 digits on the LCD
 */
void LCD_LAUNCHPAD::clear()
{
#if defined(__MSP430_HAS_LCD_C__)
    LCDCMEMCTL |= (LCDCLRM|LCDCLRBM);
#endif /* defined(__MSP430_HAS_LCD_C__) */
#if defined(__MSP430_HAS_LCD_E__)
    LCDMEMCTL |= (LCDCLRM|LCDCLRBM);
    LCDM0W = 0x8421;
    LCDBM0W = 0x8421;
#endif /* defined(__MSP430_HAS_LCD_E__) */
}
