#ifndef RAINBOWCYCLEDEMO_H
#define RAINBOWCYCLEDEMO_H

#include "Demo.h"

// Animation speeds to loop through with mode presses.  The current milliseconds 
// are divided by this value so the smaller the value the faster the animation.
static int speeds[] = { 5, 10, 50, 100 };

class RainbowCycleDemo: public Demo {
public:
  RainbowCycleDemo() { currentSpeed = 0; }
  ~RainbowCycleDemo() {}

  virtual void loop() {
    // Make an offset based on the current millisecond count scaled by the current speed.
    uint32_t offset = millis() / speeds[currentSpeed];
    // Loop through each pixel and set it to an incremental color wheel value.
    for(int i=0; i<10; ++i) {
      CircuitPlayground.strip.setPixelColor(i, CircuitPlayground.colorWheel(((i * 256 / 10) + offset) & 255));
    }
    // Show all the pixels.
    CircuitPlayground.strip.show();
  }

  virtual void modePress() {
    // Increment through the available speeds.
    currentSpeed += 1;
    if (currentSpeed >= sizeof(speeds)/sizeof(int)) {
      currentSpeed = 0;
    }
  }

private:
  int currentSpeed;
  
};


#endif
