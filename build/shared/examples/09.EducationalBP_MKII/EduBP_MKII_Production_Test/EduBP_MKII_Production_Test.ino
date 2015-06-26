
#include "pitches.h"
#include <Wire.h>
#include <tmp006.h>
//#include "OPT3001.h"
#define USE_USCI_B1 
#define USING_MSP430F5529_LAUNCHPAD
//#define USING_TIVA_C_LAUNCHPAD




// Core library for code-sense
#if defined(WIRING) // Wiring specific
#include "Wiring.h"
#elif defined(MAPLE_IDE) // Maple specific
#include "WProgram.h"
#elif defined(MPIDE) // chipKIT specific
#include "WProgram.h"
#elif defined(DIGISPARK) // Digispark specific
#include "Arduino.h"
#elif defined(ENERGIA) // LaunchPad MSP430, Stellaris and Tiva, Experimeter Board FR5739 specific
#include "Energia.h"
#elif defined(CORE_TEENSY) // Teensy specific
#include "WProgram.h"
#elif defined(ARDUINO) && (ARDUINO >= 100) // Arduino 1.0 and 1.5 specific
#include "Arduino.h"
#elif defined(ARDUINO) && (ARDUINO < 100) // Arduino 23 specific
#include "WProgram.h"
#else // error
#error Platform not defined
#endif

// Include application, user and local libraries
#include "SPI.h"

// Screen selection
#define HX8353E // HX8353E K35 HI32 W32 ILI9225B HY28A ST7735 PicasoSPE PicasoSGC

#include "Screen_HX8353E.h"
Screen_HX8353E myScreen;


// Define variables and constants
//uint32_t chrono;


///
/// @brief      protocolSquare
/// @details    measure time to draw a square with side=pixels
/// @param      pixels number of pixels of one side
///
void protocolSquare(uint16_t pixels)
{
    if ((pixels < myScreen.screenSizeX()) && (pixels < myScreen.screenSizeY()) && (pixels > 48)) {
        
        myScreen.setOrientation(0);
        myScreen.setPenSolid(false);
        
        uint16_t x100 = (myScreen.screenSizeX()-pixels)/2;
        uint16_t y100 = (myScreen.screenSizeY()-pixels)/2;
        
        myScreen.dRectangle(x100-1, y100-1, pixels+2, pixels+2, whiteColour);
        myScreen.setPenSolid(true);
        uint32_t chrono = millis();
        myScreen.dRectangle(x100, y100, pixels, pixels, grayColour);
        chrono = millis() - chrono;
        
        myScreen.setFontSize(myScreen.fontMax());
        myScreen.gText(x100 +2, y100 +2, "(" + i32toa(pixels) + ")");
        myScreen.gText(x100 +2, y100 +pixels -myScreen.fontSizeY() -2, i32toa(chrono) + " ms");
        
        Serial.print("Square(");
        Serial.print(pixels, DEC);
        Serial.print(")\t");
        Serial.println(chrono, DEC);
    }
}

///
/// @brief      protocolCopyPaste
/// @details    measure time to copy-paste a 64x64 area
/// @param      orientation default=1
///
void protocolCopyPaste(uint8_t orientation = 1)
{
    uint32_t chrono;
    myScreen.clear();
    myScreen.setOrientation(orientation);
    
    // Image
    chrono = millis();
    for (uint8_t i=0; i<64; i++) {
        for (uint8_t j=0; j<64; j++) {
            myScreen.point(i, j, myScreen.calculateColour(4*i, 4*j, 254-2*i-2*j));
        }
    }
    
    myScreen.setPenSolid(false);
    myScreen.rectangle(1, 1, 62, 62, blackColour);
    myScreen.line(0,   0, 63, 63, whiteColour);
    myScreen.line(32,  0, 63, 63, whiteColour);
    myScreen.line(0,  32, 63, 63, whiteColour);
    myScreen.dRectangle(0, 0, 64, 64, whiteColour);
    chrono = millis() - chrono;
    
    myScreen.setFontSize(0);
    myScreen.gText(0, 66, "0: Original");
    myScreen.setFontSize(1);
    myScreen.gText(0, 76, i32toa(chrono) + " ms");
    
    Serial.print("Original(=");
    Serial.print(orientation, DEC);
    Serial.print(")\t");
    Serial.println(chrono, DEC);
    
    // Method 1
    chrono = millis();
    for (uint16_t i=0; i<64; i++) {
        for (uint16_t j=0; j<64; j++) {
            myScreen.point(myScreen.screenSizeX()/2+i, j, myScreen.readPixel(i, j));
        }
    }
    chrono = millis() - chrono;
    myScreen.setFontSize(0);
    myScreen.gText(myScreen.screenSizeX()/2, 66, "1. point readPixel");
    myScreen.setFontSize(1);
    myScreen.gText(myScreen.screenSizeX()/2, 76, i32toa(chrono) + " ms");
    
    Serial.print("point(readPixel())\t");
    Serial.println(chrono, DEC);
    
    // Method 2
    chrono = millis();
    myScreen.copyPaste(0, 0, 0, myScreen.screenSizeY()/2, 64, 64);
    chrono = millis() - chrono;
    
    myScreen.setFontSize(0);
    myScreen.gText(0, myScreen.screenSizeY()/2 +66, "2. copyPaste");
    myScreen.setFontSize(1);
    myScreen.gText(0, myScreen.screenSizeY()/2 +76, i32toa(chrono) + " ms");
    
    Serial.print("copyPaste()\t");
    Serial.println(chrono, DEC);
    
    // Method 3
    if (myScreen.isStorage()) {
        uint32_t address;
        
        chrono = millis();
        address = 100;
        myScreen.copyArea(0, 0, 64, 64, address);
        address = 100;
        myScreen.pasteArea(myScreen.screenSizeX()/2, myScreen.screenSizeY()/2, 64, 64, address);
        chrono = millis() - chrono;
        
        myScreen.setFontSize(0);
        myScreen.gText(myScreen.screenSizeX()/2, myScreen.screenSizeY()/2 +66, "3. copy-paste SRAM");
        myScreen.setFontSize(1);
        myScreen.gText(myScreen.screenSizeX()/2, myScreen.screenSizeY()/2 +76, i32toa(chrono) + " ms");
        
        Serial.print("copyArea()+pasteArea() SRAM\t");
        Serial.println(chrono, DEC);
    }
}


///
/// @brief      protocolText
/// @details    measure time to draw text in 3 fonts, 4 orientations, 10x
///
void protocolText()
{
    uint32_t chrono1, chrono2;
    uint16_t colour;
    uint8_t k = 0;

    // Serial.print("fast gText... ");
    myScreen.clear(grayColour);
    myScreen.setFontSolid(true);
    chrono1 = millis();
    for (uint8_t j=0; j<10; j++) {
        for (uint8_t i=0; i<4; i++) {
            if (k==1) colour = redColour;
            else if (k==2) colour = yellowColour;
            else if (k==3) colour = greenColour;
            else if (k==4) colour = cyanColour;
            else if (k==5) colour = blueColour;
            else  colour = violetColour;
            k++;
            k %= 7;
            
            myScreen.setPenSolid(false);
            myScreen.dRectangle(0, 0, myScreen.screenSizeX(), myScreen.screenSizeY(), colour);
            
            myScreen.setOrientation(i);
            myScreen.setFontSize(0);
            myScreen.gText(4, 4, "font 0 on " + String(i), colour);
            myScreen.setFontSize(1);
            myScreen.gText(4, 14, "font 1 on " + String(i), colour);
            myScreen.setFontSize(2);
            myScreen.gText(4, 34, "font 2 on " + String(i), colour);
        }
    }
    chrono1 = millis()-chrono1;
    Serial.print("10xFontSolid(true)\t");
    Serial.println(chrono1, DEC);
    
    // Serial.print("slow gText... ");
    myScreen.clear(grayColour);
    myScreen.setFontSolid(false);
    chrono2 = millis();
    
    for (uint8_t j=0; j<10; j++) {
        for (uint8_t i=0; i<4; i++) {
            if (k==1) colour = redColour;
            else if (k==2) colour = yellowColour;
            else if (k==3) colour = greenColour;
            else if (k==4) colour = cyanColour;
            else if (k==5) colour = blueColour;
            else  colour = violetColour;
            k++;
            k %= 7;
            
            myScreen.setPenSolid(false);
            myScreen.dRectangle(0, 0, myScreen.screenSizeX(), myScreen.screenSizeY(), colour);
            
            myScreen.setOrientation(i);
            myScreen.setFontSize(0);
            myScreen.gText(4, 4, "font 0 on " + String(i), colour);
            myScreen.setFontSize(1);
            myScreen.gText(4, 14, "font 1 on " + String(i), colour);
            myScreen.setFontSize(2);
            myScreen.gText(4, 34, "font 2 on " + String(i), colour);
        }
    }
    
    chrono2 = millis()-chrono2;
    Serial.print("10xFontSolid(false)\t");
    Serial.println(chrono2, DEC);
    
    Serial.print("Ratio%\t");
    Serial.println((uint32_t)((uint64_t)(chrono1*100)/chrono2), DEC);
    
}



const int JOY_X = 2;
const int JOY_Y = 26;
const int SEL = 5;

//MIC
const int MIC = 6;

//ACCELEROMETER
const int ACC_X = 23;
const int ACC_Y = 24;
const int ACC_Z = 25;


//SWITCHES
const int SW1 = 33;
const int SW2 = 32;

//BUZZER
const int BUZZ = 40;



//RGB LED
const int RGB_RED = 39;
const int RGB_GRN = 38;
const int RGB_BLU = 37;

//TMP006
float tempReading = 0;

// notes in the melody:
#define NOTE_C4_1 260

// OPT3001
//opt3001 opt3001;
tmp006 tmp006;
unsigned long readings = 0;

int melody[] = {
   NOTE_C4_1,NOTE_C4, NOTE_D4, NOTE_C4,NOTE_F4,NOTE_E4,
   NOTE_C4_1,NOTE_C4,NOTE_D4,NOTE_C4,NOTE_G4,NOTE_F4,
   NOTE_C4_1,NOTE_C4,NOTE_C5,NOTE_A4,NOTE_F4,NOTE_F4, NOTE_E4,NOTE_D4,
   NOTE_AS4,NOTE_AS4,NOTE_A4,NOTE_F4,NOTE_G4,NOTE_F4};
   
// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 4, 2, 2,2,1,
  4, 4, 2, 2,2,1,
  4, 4, 2, 2,4,4,2,1, 
  4, 4, 2, 2,2,1};


void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(300);
  pinMode(SEL, INPUT);
  pinMode(SW1, INPUT);
  pinMode(SW2, INPUT);
  pinMode(BUZZ, OUTPUT);
  Serial.println("Welcome to the Educational BoosterPack MKII Production Test:");

  tmp006.begin(EIGHT_SAMPLES);  // Takes 8 averaged samples for measurement
//  opt3001.begin(); 
}

char *ftoa(char *a, float f, int precision)
{
  long p[] = {0,10,100,1000,10000,100000,1000000,10000000,100000000};
  
  char *ret = a;
  long heiltal = (long)f;
  itoa(heiltal, a, 10);
  while (*a != '\0') a++;
  *a++ = '.';
  long desimal = abs((long)((f - heiltal) * p[precision]));
  itoa(desimal, a, 10);
  return ret;
}

void loop()
{
  int16_t i;
  uint16_t colour;
    Serial.println("*** LCD_screen test ****");
    Serial.println("(All times in ms)");
     

    myScreen.begin();
    Serial.println(myScreen.WhoAmI());
    Serial.print(myScreen.screenSizeX(), DEC);
    Serial.print("x");
    Serial.println(myScreen.screenSizeY(), DEC);
    
    myScreen.setFontSize(myScreen.fontMax());
    myScreen.clear(darkGrayColour);
    
    protocolSquare(300);
    protocolSquare(200);
    protocolSquare(100);
    protocolSquare(50);
    delay(2000);
    
    protocolText();
    delay(2000);
    
    if (myScreen.isReadable()) {
        protocolCopyPaste(1);
        delay(2000);
    }
    	
    myScreen.clear();
    Serial.println("-END OF SCREEN TEST--");
    Serial.println();

      
    myScreen.clear(grayColour);
    myScreen.setFontSolid(false);
    colour = redColour;
            
	myScreen.setOrientation(i);
	myScreen.setFontSize(2);
	
	
            
        
  //Test out the joystick
  myScreen.gText(0, 0, "  JoyStick Test", blueColour);
  myScreen.gText(0, 15, "Right", colour);
  while(analogRead(JOY_X)<4094);
  
  myScreen.gText(50,15, " > Passed!", colour);
  myScreen.gText(0, 30, "Left", colour);
  while(analogRead(JOY_X)>0);
  myScreen.gText(50,30, " > Passed!", colour);
  
  myScreen.gText(0, 45, "Up", colour);
  while(analogRead(JOY_Y)<4094);
  myScreen.gText(50,45, " > Passed!", colour);
  
  myScreen.gText(0, 60, "Down", colour);
  while(analogRead(JOY_Y)>0);
  myScreen.gText(50,60, " > Passed!", colour);
  
  myScreen.gText(0,75, "Center", colour);
  while(digitalRead(SEL) == 1);
  myScreen.gText(50,75, " > Passed!", colour);

  delay(400);
  
  //Test out the microphone
  myScreen.clear(grayColour);
  myScreen.gText(0,0, "   Tap  Mic", blueColour);
  
  while(analogRead(MIC) > 100);
  myScreen.gText(50,10, " Passed!", colour);

  myScreen.gText(0,20, "  Button Tests", blueColour);
  //Test out button 1
  
  myScreen.gText(0,40, "Press S1", colour);
  while(digitalRead(SW1) == 1);
  myScreen.gText(50,40, " > Passed!", colour);

  //Test out button 2
  myScreen.gText(0,55, "Press S2", colour);
  while(digitalRead(SW2) == 1);
  myScreen.gText(50,55, " > Passed!", colour);
  
  myScreen.gText(0,70, "  Buzzer Test", blueColour);
  //Test out buzzer
  
  for (int thisNote = 0; thisNote < 26; thisNote++) {
    // to calculate the note duration, take one second 
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000/noteDurations[thisNote];
    tone(BUZZ, melody[thisNote],noteDuration);
    int pauseBetweenNotes = noteDuration + 50;      //delay between pulse
    delay(pauseBetweenNotes>>2);
    noTone(BUZZ);                // stop the tone playing
  }
  myScreen.gText(0,85, "S1&S2 if sound", colour);
  while(digitalRead(SW2) == 1 || digitalRead(SW1) == 1);
  myScreen.gText(0,100, " PASSED!!", greenColour);
  delay(400);
  
  
  //Test out 3-axis analog accelerometer
  // 1200 ~ -1G / 2000 ~ 0G / 2800 ~ +1G
  myScreen.clear(grayColour);
  myScreen.gText(0,0, " Accelerometer", blueColour);
  
  myScreen.gText(0,15, "Flat", colour);
  
  while(analogRead(ACC_X) < 1900 || analogRead(ACC_X) > 2100 || analogRead(ACC_Y) > 2100 || analogRead(ACC_Y) < 1900 || analogRead(ACC_Z) < 2700);
  myScreen.gText(50,15, " > Passed!", colour);
  
  myScreen.gText(0,30, "Left", colour);
  while(analogRead(ACC_X) > 1350 || analogRead(ACC_Y) > 2100 || analogRead(ACC_Y) < 1900 || analogRead(ACC_Z) > 2100 || analogRead(ACC_Z) < 1900);
  myScreen.gText(50,30, " > Passed!", colour);

  myScreen.gText(0,45, "Right", colour);
  while(analogRead(ACC_X) < 2650 || analogRead(ACC_Y) > 2100 || analogRead(ACC_Y) < 1900 || analogRead(ACC_Z) > 2100 || analogRead(ACC_Z) < 1900);
  myScreen.gText(50,45, " > Passed!", colour);



  myScreen.gText(0,60, "Away", colour);
  while(analogRead(ACC_X) < 1900 || analogRead(ACC_X) > 2000 || analogRead(ACC_Y) < 2600 || analogRead(ACC_Z) < 1900 || analogRead(ACC_Z) > 2100);
  myScreen.gText(50,60, " > Passed!", colour);
  

  myScreen.gText(0,75, "To you", colour);
  while(analogRead(ACC_X) < 1900 || analogRead(ACC_X) > 2100 || analogRead(ACC_Y) > 1450 || analogRead(ACC_Z) < 1900 || analogRead(ACC_Z) > 2100);
  myScreen.gText(50,75, " > Passed!", colour);
  

  myScreen.gText(0,90, "Upside Down", colour);
  while(analogRead(ACC_X) < 1900 || analogRead(ACC_X) > 2100 || analogRead(ACC_Y) > 2100 || analogRead(ACC_Y) < 1900 || analogRead(ACC_Z) > 1300);
  myScreen.gText(0,105, "   PASSED!!", greenColour);
  delay(400);
  myScreen.clear(grayColour);
  //TEST TMP006 TEMP SENSOR
  float temp = tmp006.getTemp();
  char* tempText;
  char ii;
  tempText = (char*) malloc(10);
  for (ii=0;ii<10;ii++)
  tempText[ii] = 0;
  tempText =  ftoa(tempText, temp, 4);
  myScreen.gText(0,0, "   TMP006 Test", blueColour);
  myScreen.gText(0,20, (char*)tempText , colour);
  myScreen.gText(60,20, "*C", colour);
  
  myScreen.gText(0,40, "   RGB LED Test", blueColour);
  //TEST OPT3001 LIGHT SENSOR
  //To be enabled once OPT3001 is added to future Edu BP MK II Rev.
  // Serial.println("Cover the light sensor to test the OPT3001.");
  // while(opt3001.readResult() > 30);
  // Serial.println("Shine flashlight onto the light sensor ");
  // while(opt3001.readResult() < 1000);
  
  // Serial.println("OPT3001 testing successful!");
  
  //TEST RGB LED

  i = 0;
  int brightness = 0;
  int fadeAmount = 5;
  
  for(brightness = 0; brightness<255; brightness+=fadeAmount){
    analogWrite(RGB_RED, brightness);    
    // wait for 30 milliseconds to see the dimming effect    
    delay(10); 
  }
  for(brightness = 255; brightness>=0; brightness-=fadeAmount){
    analogWrite(RGB_RED, brightness);    
    // wait for 30 milliseconds to see the dimming effect    
    delay(10); 
  }  
  for(brightness = 0; brightness<255; brightness+=fadeAmount){
    analogWrite(RGB_GRN, brightness);    
    // wait for 30 milliseconds to see the dimming effect    
    delay(10); 
  }
  for(brightness = 255; brightness>=0; brightness-=fadeAmount){
    analogWrite(RGB_GRN, brightness);    
    // wait for 30 milliseconds to see the dimming effect    
    delay(10); 
  }  
  for(brightness = 0; brightness<255; brightness+=fadeAmount){
    analogWrite(RGB_BLU, brightness);    
    // wait for 30 milliseconds to see the dimming effect    
    delay(10); 
  }
  for(brightness = 255; brightness>=0; brightness-=fadeAmount){
    analogWrite(RGB_BLU, brightness);    
    // wait for 30 milliseconds to see the dimming effect    
    delay(10); 
  }
  myScreen.gText(0,70, "S1 to Finish", colour);
  while(digitalRead(SW1) == 1);
  myScreen.gText(0,90, "ALL TESTS PASSED", greenColour);
  
  while(1);
}
