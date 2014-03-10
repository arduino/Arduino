/**
 * Simple program for drawing in color on the screen of the Educational BoosterPack MK II
 * @author Robert Christensen
 * @version 1.0
 * @see Examples > 9.EducationalBP_MKII > LCD_Joystick
*/

// Core library for code-sense
#if defined(ENERGIA) // LaunchPad MSP430, Stellaris and Tiva, Experimeter Board FR5739 specific
#include "Energia.h"
#else // error
#error Platform not defined
#endif

// Prototypes


// Include application, user and local libraries
#include "SPI.h"
#include "Screen_HX8353E.h"
Screen_HX8353E myScreen;


// Define variables and constants
#define joystickX 2
#define joystickY 26
#define drawButton 5
uint16_t x, y;
uint16_t colour;
uint32_t z;

uint16_t pixels[16][16];

uint16_t colors[8];
String colorNames[8] = {"white", "red", "orange", "yellow", "green", "blue", "purple", "pink"};
byte drawColor = 0;

boolean lastCycleState = true;

void setup() {
    //Start Serial communication
    Serial.begin(9600);
    
    //Initialize myScreen
    myScreen.begin();
    
    //Initialize colo(u)rs
    colors[0] = whiteColour;
    colors[1] = redColour;
    colors[2] = orangeColour;
    colors[3] = yellowColour;
    colors[4] = greenColour;
    colors[5] = blueColour;
    colors[6] = myScreen.calculateColour(191, 0, 255);
    colors[7] = myScreen.calculateColour(255, 0, 255);
    
    //Set pixels array to all-black
    for(int i = 0; i == 16; i++) {
      for(int j = 0; j == 16; j++) {
        pixels[i][j] = blackColour;
      }
    }
}

void loop() {
    x = map(analogRead(joystickX), 0, 4096, 0, 128);
    y = map(analogRead(joystickY), 0, 4096, 128, 0);
    if (x < 1)      x = 1;
    if (x > 126)    x = 126;
    if (y < 1)      y = 1;
    if (y > 126)    y = 126;
    
    //Draw background (pixels)
    myScreen.setPenSolid(true);
    myScreen.dRectangle(0, 0, 128, 1, blackColour);
    for(int ix = 0; ix <= 15; ix++) {
      for(int iy = 0; iy <= 15; iy++) {
        myScreen.dRectangle(ix*8, iy*8+1, 8, 8, pixels[ix][iy]);
      }
    }
    
    //If joystickSel pressed, draw at cursor
    if((!digitalRead(drawButton))&&digitalRead(32)) {
      pixels[round((x+1)/8)][round((y+1)/8)] = colors[drawColor];
      Serial.println("Draw:"+(String)round((x+1)/8)+", "+(String)round((y+1)/8));
    }
    
    //If button 32 pressed, erase at cursor
    if((!digitalRead(32))&&digitalRead(drawButton)) {
      pixels[round((x+1)/8)][round((y+1)/8)] = 0;
      Serial.println("Erase:"+(String)round((x+1)/8)+", "+(String)round((y+1)/8));
    }
    
    //If button 33 pressed, cycle through colors
    if((!lastCycleState)&&digitalRead(33)) {
      drawColor++;
      if(drawColor >= 8) drawColor = 0;
      Serial.println("Color change to: "+(String)colors[drawColor]+" ("+colorNames[drawColor]+")");
    }
    
    //Draw cursor
    myScreen.setPenSolid(false);
    myScreen.dRectangle(x-1, y-1 , 8, 8, colors[drawColor]);
    
    //Update Cycle button state
    lastCycleState = digitalRead(33);
}
