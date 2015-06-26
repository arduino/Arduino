///
/// @mainpage	LifeGame
///
/// @details	Description of the project
/// @n 		    Based on Life_Game_Colour.pde Jul 12, 2012 © Rei VILO, 2010-2012
/// @n
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
///
/// @author		Rei Vilo
/// @author		Rei Vilo
/// @date		Dec 11, 2013 18:54
/// @version	release 136
///
/// @copyright	(c) Rei Vilo, 2013
/// @copyright	CC = BY SA NC
///
/// @see
/// * Life_Game_Colour.pde Jul 12, 2012 (c) Rei VILO, 2010-2012
/// @n http://embeddedcomputing.weebly.com/life-game.html
/// * http://nathandumont.com/node/245 (c) Nathan, 11/04/2011 - 20:46
///


///
/// @file		LifeGame.ino
/// @brief		Main sketch
///
/// @details	Description of the project
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
///
/// @author		Rei Vilo
/// @author		Rei Vilo
/// @date		Dec 11, 2013 18:54
/// @version	136
///
/// @copyright	(c) Rei Vilo, 2013
/// @copyright	CC = BY SA NC
///
/// @see		ReadMe.txt for references
/// @n
///


// Core library for code-sense
#if defined(ENERGIA) // LaunchPad MSP430, Stellaris and Tiva, Experimeter Board FR5739 specific
#include "Energia.h"
#else // error
#error Platform not defined
#endif

// Prototypes


// Include application, user and local libraries
#include <SPI.h>

// Screen selection
#define HX8353E

#include <LCD_screen.h>
#include <LCD_screen_font.h>
#include <LCD_utilities.h>
#include <Screen_HX8353E.h>
#include <Terminal12e.h>
#include <Terminal6e.h>
#include <Terminal8e.h>
Screen_HX8353E myScreen;


// Beware of RAM limitations
#if defined(HX8353E)                                                            // Educational BoosterPack MKII

#if defined(__MSP430F5529__)
#define ROWS 32 // max 80
#define COLS 32 // max 60
#elif defined(__LM4F120H5QR__) || defined(__TM4C123GH6PM__) 
#define ROWS 64 // max 80
#define COLS 64 // max 60
#elif defined(__TM4C1294NCPDT__) || defined(__TM4C1294XNCZAD__)
#define ROWS 128 // max 128
#define COLS 128 // max 128
#else
#error Board not supported
#endif

#else                                                                           // general case

#define ROWS 80 // max 80
#define COLS 60 // max 60

#endif

#define PERCENT 70 // % dead

// bits 7 . 6 . 5 . 4 . 3 . 2 . 1 . 0
// [3] = dead 0, alive 1
// [2..0] = age 0-7

#define ALIVE   0x08
#define DEAD    0x00

#define NMASK   0x08
#define AGEMASK 0x07

#define StopButton 33
#define NewGameButton 32

// Define variables and constants
uint8_t _screen[2][ROWS][COLS];
uint32_t chrono;
uint8_t page;
uint16_t colours[16];
uint16_t generation;
uint8_t rowSize, colSize;
uint8_t i, j;

void new_game() {
    page = 0;
    for (i=0; i < ROWS; i++) {
        for (j=0; j < COLS; j++) {
            if (random(100) > PERCENT)  _screen[page^1][i][j] = ALIVE;
            else                        _screen[page^1][i][j] = DEAD;
            myScreen.dRectangle(i*rowSize, j*colSize, rowSize, colSize, colours[_screen[page^1][i][j]]);
        }
    }
    
    page ^= 1;
    generation = 0;
    chrono = millis();
}


void setup() {
    // No need for INPUT_PULLUP
    pinMode(StopButton, INPUT);
    pinMode(NewGameButton, INPUT);
    
    myScreen.begin();
    
    rowSize = myScreen.screenSizeX() / ROWS;
    colSize = myScreen.screenSizeY() / COLS;
    
    delay(10);
    myScreen.setPenSolid(true);
    
    // 0-7 dying: cold colours
    // from green to blue to black
    colours[ 0] = myScreen.calculateColour(  0, 255,   0);
    colours[ 1] = myScreen.calculateColour(  0, 204,  51);
    colours[ 2] = myScreen.calculateColour(  0, 153, 102);
    colours[ 3] = myScreen.calculateColour(  0, 102, 153);
    colours[ 4] = myScreen.calculateColour(  0,  51, 204);
    colours[ 5] = myScreen.calculateColour(  0,   0, 255);
    colours[ 6] = myScreen.calculateColour(  0,   0, 127);
    colours[ 7] = myScreen.calculateColour(  0,   0,   0);
    
    
    // 8-15 living: hot colours
    // from red to orange to yellow
    colours[ 8] = myScreen.calculateColour(255,   0,   0);
    colours[ 9] = myScreen.calculateColour(255,  43,   0);
    colours[10] = myScreen.calculateColour(255,  85,   0);
    colours[11] = myScreen.calculateColour(255, 127,   0);
    colours[12] = myScreen.calculateColour(255, 171,   0);
    colours[13] = myScreen.calculateColour(255, 213,   0);
    colours[14] = myScreen.calculateColour(255, 255,   0);
    colours[15] = myScreen.calculateColour(255, 255, 255);
    
    myScreen.setFontSolid(false);
    myScreen.setFontSize(1);
    myScreen.gText((myScreen.screenSizeX()-9*myScreen.fontSizeX())/2, 20, "Life Game");
    
    j = myScreen.screenSizeX() / 16;
    
    myScreen.setFontSize(0);
    myScreen.gText(0, 60, "Death");
    for (i=0; i<8; i++)
        myScreen.dRectangle(j*(8-i), 40, j, j, colours[i]);
    
    myScreen.gText(myScreen.screenSizeX()-4*myScreen.fontSizeX(), 60, "Life");
    for (i=8; i<16; i++)
        myScreen.dRectangle(j*i, 40, j, j, colours[i]);
    
    myScreen.gText((myScreen.screenSizeX()-14*myScreen.fontSizeX())/2, 90, "Button 1: stop");
    myScreen.gText((myScreen.screenSizeX()-14*myScreen.fontSizeX())/2, 100, "Button 2: new");
    delay(4000);
    
    myScreen.clear();
    
    randomSeed(analogRead(0));
    new_game();
}


void update_pixel(uint8_t i, uint8_t j, uint8_t neighbours) {
    if (bitRead(_screen[page][i][j], 3)) {
        // alive
        if ((neighbours < 2) || (neighbours > 3)) {
            _screen[page^1][i][j] = DEAD;   // zero age dead pixel      // 0 pass
        } else {
            _screen[page^1][i][j] = _screen[page][i][j] + 1;             // 8-15 living
            if (_screen[page^1][i][j] > 0x0f) {
                _screen[page^1][i][j] = 0x0f;
            }
        }
    } else {
        // dead
        if (neighbours == 3) {
            _screen[page^1][i][j] = ALIVE; // zero age alive pixel     // 8 born
        } else {
            _screen[page^1][i][j] = _screen[page][i][j] + 1;             // 0-7 dying
            if (_screen[page^1][i][j] > 0x07) _screen[page^1][i][j] = 0x07;
        }
    }
    
    if (_screen[page][i][j]!=_screen[page^1][i][j])
        myScreen.dRectangle(i*rowSize, j*colSize, rowSize, colSize, colours[_screen[page^1][i][j]]);
}

void loop() {
    uint8_t neighbours;
    
    generation++;
    
    for (i=1; i < ROWS-1; i++) {
        for (j=1; j<COLS-1; j++) {
            neighbours  = bitRead(_screen[page][i-1][j-1], 3);
            neighbours += bitRead(_screen[page][i-1][j  ], 3);
            neighbours += bitRead(_screen[page][i-1][j+1], 3);
            neighbours += bitRead(_screen[page][i  ][j-1], 3);
            neighbours += bitRead(_screen[page][i  ][j+1], 3);
            neighbours += bitRead(_screen[page][i+1][j-1], 3);
            neighbours += bitRead(_screen[page][i+1][j  ], 3);
            neighbours += bitRead(_screen[page][i+1][j+1], 3);
            update_pixel(i,j, neighbours);
        }
    }
    for (i=1; i < COLS-1; i++) {
        neighbours  = bitRead(_screen[page][0     ][i-1], 3);
        neighbours += bitRead(_screen[page][0     ][i+1], 3);
        neighbours += bitRead(_screen[page][1     ][i-1], 3);
        neighbours += bitRead(_screen[page][1     ][i  ], 3);
        neighbours += bitRead(_screen[page][1     ][i+1], 3);
        neighbours += bitRead(_screen[page][ROWS-1][i-1], 3);
        neighbours += bitRead(_screen[page][ROWS-1][i  ], 3);
        neighbours += bitRead(_screen[page][ROWS-1][i+1], 3);
        update_pixel(0, i, neighbours);
        
        neighbours  = bitRead(_screen[page][ROWS-2][i-1], 3);
        neighbours += bitRead(_screen[page][ROWS-2][i  ], 3);
        neighbours += bitRead(_screen[page][ROWS-2][i+1], 3);
        neighbours += bitRead(_screen[page][ROWS-1][i-1], 3);
        neighbours += bitRead(_screen[page][ROWS-1][i+1], 3);
        neighbours += bitRead(_screen[page][0     ][i-1], 3);
        neighbours += bitRead(_screen[page][0     ][i  ], 3);
        neighbours += bitRead(_screen[page][0     ][i+1], 3);
        update_pixel(ROWS-1,i, neighbours);
    }
    for (i=1; i < ROWS-1; i++) {
        neighbours  = bitRead(_screen[page][i-1][0     ], 3);
        neighbours += bitRead(_screen[page][i+1][0     ], 3);
        neighbours += bitRead(_screen[page][i-1][1     ], 3);
        neighbours += bitRead(_screen[page][i  ][1     ], 3);
        neighbours += bitRead(_screen[page][i+1][1     ], 3);
        neighbours += bitRead(_screen[page][i-1][COLS-1], 3);
        neighbours += bitRead(_screen[page][i  ][COLS-1], 3);
        neighbours += bitRead(_screen[page][i+1][COLS-1], 3);
        update_pixel(i, 0, neighbours);
        
        neighbours  = bitRead(_screen[page][i-1][COLS-1], 3);
        neighbours += bitRead(_screen[page][i+1][COLS-1], 3);
        neighbours += bitRead(_screen[page][i-1][COLS-2], 3);
        neighbours += bitRead(_screen[page][i  ][COLS-2], 3);
        neighbours += bitRead(_screen[page][i+1][COLS-2], 3);
        neighbours += bitRead(_screen[page][i-1][0     ], 3);
        neighbours += bitRead(_screen[page][i  ][0     ], 3);
        neighbours += bitRead(_screen[page][i+1][0     ], 3);
        update_pixel(i,COLS-1, neighbours);
    }
    
    neighbours  = bitRead(_screen[page][1     ][0     ], 3);
    neighbours += bitRead(_screen[page][1     ][1     ], 3);
    neighbours += bitRead(_screen[page][0     ][1     ], 3);
    neighbours += bitRead(_screen[page][ROWS-1][0     ], 3);
    neighbours += bitRead(_screen[page][ROWS-1][1     ], 3);
    neighbours += bitRead(_screen[page][ROWS-1][COLS-1], 3);
    neighbours += bitRead(_screen[page][0     ][COLS-1], 3);
    neighbours += bitRead(_screen[page][1     ][COLS-1], 3);
    update_pixel(0,0, neighbours);
    
    neighbours  = bitRead(_screen[page][1     ][0     ], 3);
    neighbours += bitRead(_screen[page][0     ][0     ], 3);
    neighbours += bitRead(_screen[page][0     ][COLS-2], 3);
    neighbours += bitRead(_screen[page][1     ][COLS-2], 3);
    neighbours += bitRead(_screen[page][1     ][COLS-1], 3);
    neighbours += bitRead(_screen[page][ROWS-1][COLS-1], 3);
    neighbours += bitRead(_screen[page][ROWS-1][COLS-2], 3);
    neighbours += bitRead(_screen[page][ROWS-1][0     ], 3);
    update_pixel(0,COLS-1, neighbours);
    
    neighbours  = bitRead(_screen[page][ROWS-1][1     ], 3);
    neighbours += bitRead(_screen[page][ROWS-2][0     ], 3);
    neighbours += bitRead(_screen[page][ROWS-2][1     ], 3);
    neighbours += bitRead(_screen[page][ROWS-1][COLS-1], 3);
    neighbours += bitRead(_screen[page][ROWS-2][COLS-1], 3);
    neighbours += bitRead(_screen[page][0     ][COLS-1], 3);
    neighbours += bitRead(_screen[page][0     ][0     ], 3);
    neighbours += bitRead(_screen[page][0     ][1     ], 3);
    update_pixel(ROWS-1,0, neighbours);
    
    neighbours  = bitRead(_screen[page][ROWS-1][COLS-2], 3);
    neighbours += bitRead(_screen[page][ROWS-2][COLS-2], 3);
    neighbours += bitRead(_screen[page][ROWS-2][COLS-1], 3);
    neighbours += bitRead(_screen[page][ROWS-1][0     ], 3);
    neighbours += bitRead(_screen[page][ROWS-2][0     ], 3);
    neighbours += bitRead(_screen[page][0     ][0     ], 3);
    neighbours += bitRead(_screen[page][0     ][COLS-1], 3);
    neighbours += bitRead(_screen[page][1     ][COLS-2], 3);
    update_pixel(ROWS-1,COLS-1, neighbours);
    
    page ^= 1;
    
    // generation
    myScreen.setFontSolid(true);
    
    myScreen.setFontSize(1);
    myScreen.gText(0,
                   myScreen.screenSizeY()-myScreen.fontSizeY(),
                   i32toa(generation, 1, 0, 0));
    
    // calculation time in seconds
    myScreen.setFontSize(0);
    myScreen.gText(myScreen.screenSizeX()-8*myScreen.fontSizeX(),
                   myScreen.screenSizeY()-myScreen.fontSizeY(),
                   ttoa((millis()-chrono), 8));
    chrono = millis();
    
    //    // touch to stop
    if (digitalRead(StopButton) == 0) {
        myScreen.clear();
        while (1);
    }
    
    if (digitalRead(NewGameButton) == 0) {
        delay(333);
        myScreen.clear();
        delay(333);
        new_game();
        delay(333);
    }
}













