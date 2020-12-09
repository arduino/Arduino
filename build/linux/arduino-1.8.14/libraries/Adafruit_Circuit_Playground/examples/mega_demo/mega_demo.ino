// Circuit Playground MEGA Demo
//
// Showcases interesting demos of all the components on Circuit Playground.
// This is a somewhat advanced sketch that's broken across multiple files (see
// the tabs above for all the files).  When run on Circuit Playground you can
// press the left button to cycle through each demo, and the right button to
// cycle through each mode inside a demo.  When the slide switch is in the -/right
// position the board will 'turn off' and go into deep sleep (pullin around 5mA
// of current), and when moved into the +/left position it will turn on and run
// the demos.  Make sure the switch is on the +/left side after you upload or else
// the board won't do anything!
//
// NOTE: This example requires the Adafruit SleepyDog sleep & watchdog library
// be installed.  Use the library manager to install, or grab it from its home:
//   - https://github.com/adafruit/Adafruit_SleepyDog
//   - https://github.com/adafruit/Adafruit_ASFcore (for Express)
//
// The following demos are available (in order):
// - NeoPixel color rainbow cycle
//   This animates all 10 neopixels with a rainbow cycle.  Changing the mode
//   changes the speed of animation.
// - Volume level meter
//   This uses the microphone to display a volume level meter.  The louder the
//   volume the more lights light up (and a peak level dot animates back down).
//   Changing mode changes the sensitivity from medium to very high to very low
//   and back to medium again (3 levels).
// - Capacitive touch instrument
//   This uses the capacitive touch pads (0, 1, 2, 3, 6, 9, 10, 12) and lights up
//   a nearby pixel when a pad is touched.  Pressing the mode toggles between
//   playing a different tone for each pad too (8 notes total covering the basic
//   C4 scale).
// - Accelerometer tilt demo
//   This lights up all the pixels to a color between blue and red depending on
//   the value of the accelerometer.  Try tilting the board around axes to see
//   how it behaves.  Pressing mode toggles between the X, Y, Z axis as the one
//   under measurements (starts with X axis).
// - Temperature & light sensor demo
//   The left half of the pixels light up blue proportional to the temperature
//   of the thermistor, and the right half of the pixels light up red proportional
//   to the light sensor.  Pressing mode toggles between small, medium, and big
//   ranges of measurements for each sensor.
//
// Author: Tony DiCola
// License: MIT License (https://opensource.org/licenses/MIT)
#include <Adafruit_CircuitPlayground.h>
#include <Wire.h>
#include <SPI.h>
#include "Adafruit_SleepyDog.h"

// Include all the demos, note that each demo is defined in a separate class to keep the sketch
// code below clean and simple.
#include "Demo.h"
#include "RainbowCycleDemo.h"
#include "VUMeterDemo.h"
#include "CapTouchDemo.h"
#include "TiltDemo.h"
#include "SensorDemo.h"

// Create an instance of each demo class.
RainbowCycleDemo rainbowCycleDemo;
VUMeterDemo vuMeterDemo;
CapTouchDemo capTouchDemo;
TiltDemo tiltDemo;
SensorDemo sensorDemo;

// Make a list of all demo class instances and keep track of the currently selected one.
int currentDemo = 0;
Demo* demos[] = {
  &rainbowCycleDemo,
  &vuMeterDemo,
  &capTouchDemo,
  &tiltDemo,
  &sensorDemo
};

void setup() {
  // Initialize serial port and circuit playground library.
  Serial.begin(115200);
  Serial.println("Circuit Playground MEGA Demo!");
  CircuitPlayground.begin();
}

void loop() {
  // Check if slide switch is on the left (false) and go to sleep.
  while (!CircuitPlayground.slideSwitch()) {
    // Turn off the pixels, then go into deep sleep for a second.
    CircuitPlayground.clearPixels();
    Watchdog.sleep(1000);
  }

  // Check for any button presses by checking their state twice with
  // a delay inbetween.  If the first press state is different from the
  // second press state then something was pressed/released!
  bool leftFirst = CircuitPlayground.leftButton();
  bool rightFirst = CircuitPlayground.rightButton();
  delay(10);

  // Run current demo's main loop.
  demos[currentDemo]->loop();

  // Now check for buttons that were released.
  bool leftSecond = CircuitPlayground.leftButton();
  bool rightSecond = CircuitPlayground.rightButton();

  // Left button will change the current demo.
  if (leftFirst && !leftSecond) {
    // Turn off all the pixels when entering new mode.
    CircuitPlayground.clearPixels();
    // Increment the current demo (looping back to zero if at end).
    currentDemo += 1;
    if (currentDemo >= (sizeof(demos)/sizeof(Demo*))) {
      currentDemo = 0;
    }
    Serial.print("Changed to demo: "); Serial.println(currentDemo, DEC);
  }

  // Right button will change the mode of the current demo.
  if (rightFirst && !rightSecond) {
    demos[currentDemo]->modePress();
  }
}
