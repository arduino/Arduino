#ifndef TILTDEMO_H
#define TILTDEMO_H

#include "Demo.h"

// Define range of possible acceleration values.
#define MIN_ACCEL -10.0
#define MAX_ACCEL 10.0

// Define range of colors (min color and max color) using their red, green, blue components.
// First the min color:
#define MIN_COLOR_RED   0xFF
#define MIN_COLOR_GREEN 0x00
#define MIN_COLOR_BLUE  0x00

// Then the max color:
#define MAX_COLOR_RED   0x00
#define MAX_COLOR_GREEN 0x00
#define MAX_COLOR_BLUE  0xFF


class TiltDemo: public Demo {
public:
  TiltDemo() { mode = 0; }
  ~TiltDemo() {}

  virtual void loop() {
    // Grab the acceleration for the current mode's axis.
    float accel = 0;
    switch (mode) {
      case 0:
        accel = CircuitPlayground.motionX();
        break;
      case 1:
        accel = CircuitPlayground.motionY();
        break;
      case 2:
        accel = CircuitPlayground.motionZ();
        break;
    }

    // Now interpolate the acceleration into a color for the pixels.
    uint8_t red = (uint8_t)lerp(accel, MIN_ACCEL, MAX_ACCEL, MIN_COLOR_RED, MAX_COLOR_RED);
    uint8_t green = (uint8_t)lerp(accel, MIN_ACCEL, MAX_ACCEL, MIN_COLOR_GREEN, MAX_COLOR_GREEN);
    uint8_t blue = (uint8_t)lerp(accel, MIN_ACCEL, MAX_ACCEL, MIN_COLOR_BLUE, MAX_COLOR_BLUE);

    // Gamma correction makes LED brightness appear more linear
    red   = CircuitPlayground.gamma8(red);
    green = CircuitPlayground.gamma8(green);
    blue  = CircuitPlayground.gamma8(blue);

    // Light up all the pixels the interpolated color.
    for (int i=0; i<10; ++i) {
      CircuitPlayground.strip.setPixelColor(i, red, green, blue);
    }
    CircuitPlayground.strip.show();
  }

  virtual void modePress() {
    // Change the mode (axis being displayed) to a value inside 0-2 for X, Y, Z.
    mode += 1;
    if (mode > 2) {
      mode = 0;
    }
  }

private:
  int mode;
};

#endif
