// This demo is based on the vumeter demo in the Adafruit Circuit Playground library.
#ifndef VUMETERDEMO_H
#define VUMETERDEMO_H

#include <math.h>
#include "Demo.h"

#define SAMPLE_WINDOW   10  // Sample window for average level
#define PEAK_HANG       24  // Time of pause before peak dot falls
#define PEAK_FALL        4  // Rate of falling peak dot
#define INPUT_FLOOR     56  // Lower range of mic sensitivity in dB SPL
#define INPUT_CEILING  110  // Upper range of mic sensitivity in db SPL

static byte peak = 16;        // Peak level of column; used for falling dots
static unsigned int sample;
static byte dotCount = 0;     //Frame counter for peak dot
static byte dotHangCount = 0; //Frame counter for holding peak dot

static float mapf(float x, float in_min, float in_max, float out_min, float out_max);
static void drawLine(uint8_t from, uint8_t to, uint32_t c);

class VUMeterDemo: public Demo {
public:
  VUMeterDemo() { currentCeiling = 0; }
  ~VUMeterDemo() {}

  virtual void loop() {
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
        CircuitPlayground.strip.setPixelColor(i, CircuitPlayground.colorWheel(map(i,0,numPixels-1,30,150)));
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
      CircuitPlayground.strip.setPixelColor(y-1,CircuitPlayground.colorWheel(map(y,0,numPixels-1,30,150)));
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

  virtual void modePress() {
  }

private:
  int currentCeiling;
};



static float mapf(float x, float in_min, float in_max, float out_min, float out_max)
{
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

//Used to draw a line between two points of a given color
static void drawLine(uint8_t from, uint8_t to, uint32_t c) {
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

#endif
