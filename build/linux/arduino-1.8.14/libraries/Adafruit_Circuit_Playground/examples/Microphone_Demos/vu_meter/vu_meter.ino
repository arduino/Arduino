/*
LED VU meter for Circuit Playground
This is a port of the Adafruit Amplitie project to Circuit Playground.
Based on code for the adjustable sensitivity version of amplitie from:
  https://learn.adafruit.com/led-ampli-tie/the-code
 
 Hardware requirements:
 - Circuit Playground
 
 Software requirements:
 - Adafruit Circuit Playground library
 
 Written by Adafruit Industries.  Distributed under the BSD license.
 This paragraph must be included in any redistribution.
 
 */
#include <Adafruit_CircuitPlayground.h>
#include <Wire.h>
#include <SPI.h>

#define SAMPLE_WINDOW   10  // Sample window for average level
#define PEAK_HANG       24  // Time of pause before peak dot falls
#define PEAK_FALL        4  // Rate of falling peak dot

#define INPUT_FLOOR     56  // Lower range of mic sensitivity in dB SPL
#define INPUT_CEILING  110  // Upper range of mic sensitivity in db SPL

byte peak = 16;        // Peak level of column; used for falling dots
unsigned int sample;
byte dotCount = 0;     //Frame counter for peak dot
byte dotHangCount = 0; //Frame counter for holding peak dot

float mapf(float x, float in_min, float in_max, float out_min, float out_max);

void setup() 
{
  CircuitPlayground.begin();
}

void loop() 
{
  int numPixels = CircuitPlayground.strip.numPixels();
  float peakToPeak = 0;   // peak-to-peak level
  unsigned int c, y;

  //get peak sound pressure level over the sample window
  peakToPeak = CircuitPlayground.mic.soundPressureLevel(SAMPLE_WINDOW);

  //limit to the floor value
  peakToPeak = max(INPUT_FLOOR, peakToPeak);
 
  // Serial.println(peakToPeak);

  //Fill the strip with rainbow gradient
  for (int i=0;i<=numPixels-1;i++){
    CircuitPlayground.strip.setPixelColor(i,Wheel(map(i,0,numPixels-1,30,150)));
  }

  c = mapf(peakToPeak, INPUT_FLOOR, INPUT_CEILING, numPixels, 0);

  // Turn off pixels that are below volume threshold.
  if(c < peak) {
    peak = c;        // Keep dot on top
    dotHangCount = 0;    // make the dot hang before falling
  }
  if (c <= numPixels) { // Fill partial column with off pixels
    drawLine(numPixels, numPixels-c, CircuitPlayground.strip.Color(0, 0, 0));
  }

  // Set the peak dot to match the rainbow gradient
  y = numPixels - peak;
  CircuitPlayground.strip.setPixelColor(y-1,Wheel(map(y,0,numPixels-1,30,150)));
  CircuitPlayground.strip.show();

  // Frame based peak dot animation
  if(dotHangCount > PEAK_HANG) { //Peak pause length
    if(++dotCount >= PEAK_FALL) { //Fall rate 
      peak++;
      dotCount = 0;
    }
  } 
  else {
    dotHangCount++; 
  }
}

//Used to draw a line between two points of a given color
void drawLine(uint8_t from, uint8_t to, uint32_t c) {
  uint8_t fromTemp;
  if (from > to) {
    fromTemp = from;
    from = to;
    to = fromTemp;
  }
  for(int i=from; i<=to; i++){
    CircuitPlayground.strip.setPixelColor(i, c);
  }
}

float mapf(float x, float in_min, float in_max, float out_min, float out_max)
{
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
    return CircuitPlayground.strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } 
  else if(WheelPos < 170) {
    WheelPos -= 85;
    return CircuitPlayground.strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } 
  else {
    WheelPos -= 170;
    return CircuitPlayground.strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}