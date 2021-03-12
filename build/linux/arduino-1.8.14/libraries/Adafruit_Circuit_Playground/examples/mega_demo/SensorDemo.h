#ifndef SENSORDEMO_H
#define SENSORDEMO_H

#include "Demo.h"

// Define small, medium, large range of light sensor values.
static int minLight[] = {  0,   0,    0};
static int maxLight[] = { 50, 255, 1023};

// Define small, medium, large range of temp sensor values (in Fahrenheit).
static float minTempF[] = {  80.0,  70.0,  -32.0};
static float maxTempF[] = {  85.0,  90.0, 212.0};

// Define color for light sensor pixels.
#define LIGHT_RED   0xFF
#define LIGHT_GREEN 0x00
#define LIGHT_BLUE  0x00

// Define color for temp sensor pixels.
#define TEMP_RED    0x00
#define TEMP_GREEN  0x00
#define TEMP_BLUE   0xFF

class SensorDemo: public Demo {
public:
  SensorDemo() { mode = 0; }
  ~SensorDemo() {}

  virtual void loop() {
    // Reset all lights to off.
    for (int i=0; i<10; ++i) {
      CircuitPlayground.strip.setPixelColor(i, 0);
    }
    
    // Measure the light level and use it to light up its LEDs (right half).
    uint16_t light = CircuitPlayground.lightSensor();
    int level = (int)lerp(light, minLight[mode], maxLight[mode], 0.0, 5.0);
    for (int i=9; i>9-level; --i) {
      CircuitPlayground.strip.setPixelColor(i, LIGHT_RED, LIGHT_GREEN, LIGHT_BLUE);
    }

    // Measure the temperatue and use it to light up its LEDs (left half).
    float tempF = CircuitPlayground.temperatureF();
    level = (int)lerp(tempF, minTempF[mode], maxTempF[mode], 0.0, 5.0);
    for (int i=0; i<level; ++i) {
      CircuitPlayground.strip.setPixelColor(i, TEMP_RED, TEMP_GREEN, TEMP_BLUE);
    }

    // Light up the pixels!
    CircuitPlayground.strip.show();
  }

  virtual void modePress() {
    // Switch to one of three modes for small, medium, big ranges of measurements.
    mode += 1;
    if (mode > 2) {
      mode = 0;
    }
  }

private:
  int mode;
};

#endif
