// Circuit Playground Digital Fidget Spinner
// -----------------------------------------
// Uses the Circuit Playground accelerometer to detect when the board
// is flicked from one side or the other and animates the pixels spinning
// around accordingly (with decay in speed to simulate friction).
// Press one button to cycle through different color combinations,
// and another button to cycle through 4 different types of animations
// (single dot, dual dot, single sine wave, dual sine wave).
// See the FidgetSpinner.h and PeakDetector.h files as tabs at the top
// for more of the sketch code!
// Author: Tony DiCola
// License: MIT License (https://opensource.org/licenses/MIT)
#include <Adafruit_CircuitPlayground.h>
#include "FidgetSpinner.h"
#include "PeakDetector.h"


// Configure which accelerometer axis to check:
// This should be one of the following values (uncomment only ONE):
//#define AXIS              CircuitPlayground.motionX()    // X axis, good for Circuit Playground express (SAMD21).
#define AXIS                CircuitPlayground.motionY()    // Y axis, good for Circuit Playground classic (32u4).
//#define AXIS              CircuitPlayground.motionZ()    // Z axis, wacky--try it!

// Configure how the axis direction compares to pixel movement direction:
#define INVERT_AXIS         true  // Set to true or 1 to invert the axis direction vs.
                                  // pixel movement direction, or false/0 to disable.
                                  // If the pixels spin in the opposite direction of your
                                  // flick all the time then try changing this value.

// Configure pixel brightness.
// Set this to a value from 0 to 255 (minimum to maximum brightness).
#define BRIGHTNESS          255

// Configure peak detector behavior:
#define LAG                 30     // Lag, how large is the buffer of filtered samples.
                                   // Must be an integer value!
#define THRESHOLD           20.0   // Number of standard deviations above average a
                                   // value needs to be to be considered a peak.
#define INFLUENCE            0.1   // Scale down peak values to this percent influence
                                   // when storing them back in the filtered values.
                                   // Should be a value from 0 to 1.0 where smaller
                                   // values mean peaks have less influence.

// Configure spinner decay, i.e. how much it slows down.  This should
// be a value from 0 to 1 where smaller values cause the spinner to
// slow down faster.
#define DECAY                0.66

// Debounce times for peak detection and button presses.
// You probably don't need to change these.
#define PEAK_DEBOUNCE_MS     500
#define BUTTON_DEBOUNCE_MS   20

// Define combinations of colors.  Each combo has a primary and secondary color
// that are defined as 24-bit RGB values (like HTML colors, set them using hex
// values).  First define a struct to specify the types colors.  Then define
// the list of color combos.  If you want to change color combos (like add or
// remove them, skip down to the colors[] array below and change it.
typedef struct {
  uint32_t primary;
  uint32_t secondary;
} colorCombo;
// Add or remove color combos here:
colorCombo colors[] = {
  // Each color combo has the following form:
  // { .primary = 24-bit RGB color (use hex), .secondary = 24-bit RGB color },
  // Make sure each combo ends in a comma EXCEPT for the last one!
  { .primary = 0xFF0000, .secondary = 0x000000 },  // Red to black
  { .primary = 0x00FF00, .secondary = 0x000000 },  // Green to black
  { .primary = 0x0000FF, .secondary = 0x000000 },  // Blue to black
  { .primary = 0xFF0000, .secondary = 0x00FF00 },  // Red to green
  { .primary = 0xFF0000, .secondary = 0x0000FF },  // Red to blue
  { .primary = 0x00FF00, .secondary = 0x0000FF }   // Green to blue
};

// Uncomment this to output a stream of debug information
// from the accelerometer and peak detector.  Use the serial
// plotter to view the graph of these 4 values:
//  - Accelerometer y axis value (in m/s^2)
//  - Peak detector filtered y axis average
//  - Peak detector filtered y axis standard deviation
//  - Peak detector result, 0=no peak 1=positive peak, -1=negative peak
#define DEBUG


// Global state used by the sketch (you don't need to change this):
PeakDetector peakDetector(LAG, THRESHOLD, INFLUENCE);
FidgetSpinner fidgetSpinner(DECAY);
uint32_t lastMS = millis();
uint32_t peakDebounce = 0;
uint32_t buttonDebounce = 0;
bool lastButton1;
bool lastButton2;
int currentAnimation = 0;
int currentColor = 0;


void setup() {
  // Initialize serial output for debugging and plotting.
  Serial.begin(115200);
  // Initialize Circuit Playground library and set accelerometer
  // to its widest +/-16G range.
  CircuitPlayground.begin(BRIGHTNESS);
  CircuitPlayground.setAccelRange(LIS3DH_RANGE_16_G);
  // Initialize starting button state.
  lastButton1 = CircuitPlayground.leftButton();
  lastButton2 = CircuitPlayground.rightButton();
}

void loop() {
  // Update time since last loop call.
  uint32_t currentMS = millis();
  uint32_t deltaMS = currentMS - lastMS;  // Time in milliseconds.
  float deltaS = deltaMS / 1000.0;        // Time in seconds.
  lastMS = currentMS;

  // Grab the current accelerometer axis value and look for a sudden peak.
  float accel = AXIS;
  int result = peakDetector.detect(accel);

  // If in debug mode, print out the current acceleration and peak detector
  // state (average, standard deviation, and peak result).  Use the serial
  // plotter to view this over time.
  #ifdef DEBUG
    Serial.print(accel);
    Serial.print(",");
    Serial.print(peakDetector.getAvg());
    Serial.print(",");
    Serial.print(peakDetector.getStd());
    Serial.print(",");
    Serial.println(result);
  #endif

  // If there was a peak and enough time has elapsed since the last peak
  // (i.e. to 'debounce' the noisey peak signal a bit) then start the spinner
  // moving at a velocity proportional to the accelerometer value.
  if ((result != 0) && (currentMS >= peakDebounce)) {
    peakDebounce = currentMS + PEAK_DEBOUNCE_MS;
    // Invert accel because accelerometer axis positive/negative is flipped
    // with respect to pixel positive/negative movement.
    if (INVERT_AXIS) {
      fidgetSpinner.spin(-accel);
    }
    else {
      fidgetSpinner.spin(accel);
    }
  }

  // Check if enough time has passed to test for button releases.
  if (currentMS >= buttonDebounce) {
    buttonDebounce = currentMS + BUTTON_DEBOUNCE_MS;
    // Check if any button was released.  I.e. the last known button
    // state was pressed (true) and the current state is released (false).
    bool button1 = CircuitPlayground.leftButton();
    bool button2 = CircuitPlayground.rightButton();
    if (!button1 && lastButton1) {
      // Button 1 released!
      // Change to the next animation (looping back to start after 3 since
      // there are 4 total animations).
      currentAnimation = (currentAnimation + 1) % 4;
    }
    if (!button2 && lastButton2) {
      // Button 2 released!
      // Change to the next color index.
      currentColor = (currentColor + 1) % (sizeof(colors)/sizeof(colorCombo));
    }
    lastButton1 = button1;
    lastButton2 = button2;
  }

  // Update the spinner position and draw the current animation frame.
  float pos = fidgetSpinner.getPosition(deltaS);
  switch (currentAnimation) {
    case 0:
      // Single dot.
      animateDots(pos, 1);
      break;
    case 1:
      // Two opposite dots.
      animateDots(pos, 2);
      break;
    case 2:
      // Sine wave with one peak.
      animateSine(pos, 1.0);
      break;
    case 3:
      // Sine wave with two peaks.
      animateSine(pos, 2.0);
      break;
  }
}


// Helper functions:
void fillPixels(const uint32_t color) {
  // Set all the pixels on CircuitPlayground to the specified color.
  for (int i=0; i<CircuitPlayground.strip.numPixels();++i) {
    CircuitPlayground.strip.setPixelColor(i, color);
  }
}

float constrainPosition(const float pos) {
  // Take a continuous positive or negative value and map it to its relative positon
  // within the range 0...<10 (so it's valid as an index to CircuitPlayground pixel
  // position).
  float result = fmod(pos, CircuitPlayground.strip.numPixels());
  if (result < 0.0) {
    result += CircuitPlayground.strip.numPixels();
  }
  return result;
}

float lerp(const float x, const float x0, const float x1, const float y0, const float y1) {
  // Linear interpolation of value y within y0...y1 given x and range x0...x1.
  return y0 + (x-x0)*((y1-y0)/(x1-x0));
}

uint32_t primaryColor() {
  return colors[currentColor].primary;
}

uint32_t secondaryColor() {
  return colors[currentColor].secondary;
}

uint32_t colorLerp(const float x, const float x0, const float x1, const uint32_t c0, const uint32_t c1) {
  // Perform linear interpolation of 24-bit RGB color values.
  // Will return a color within the range of c0...c1 proportional to the value x within x0...x1.
  uint8_t r0 = (c0 >> 16) & 0xFF;
  uint8_t g0 = (c0 >> 8) & 0xFF;
  uint8_t b0 = c0 & 0xFF;
  uint8_t r1 = (c1 >> 16) & 0xFF;
  uint8_t g1 = (c1 >> 8) & 0xFF;
  uint8_t b1 = c1 & 0xFF;
  uint32_t r = int(lerp(x, x0, x1, r0, r1));
  uint32_t g = int(lerp(x, x0, x1, g0, g1));
  uint32_t b = int(lerp(x, x0, x1, b0, b1));
  return (r << 16) | (g << 8) | b;
}

// Animation functions:
void animateDots(float pos, int count) {
  // Simple discrete dot animation.  Spins dots around the board based on the specified
  // spinner position.  Count specifies how many dots to display, each one equally spaced
  // around the pixels (in practice any count that 10 isn't evenly divisible by will look odd).
  // Count should be from 1 to 10 (inclusive)!
  fillPixels(secondaryColor());
  // Compute each dot's position and turn on the appropriate pixel.
  for (int i=0; i<count; ++i) {
    float dotPos = constrainPosition(pos + i*(float(CircuitPlayground.strip.numPixels())/float(count)));
    CircuitPlayground.strip.setPixelColor(int(dotPos), primaryColor());
  }
  CircuitPlayground.strip.show();
}

void animateSine(float pos, float frequency) {
  // Smooth sine wave animation.  Sweeps a sine wave of primary to secondary color around
  // the board pixels based on the specified spinner position.
  // Compute phase based on spinner position.  As the spinner position changes the phase will
  // move the sine wave around the pixels.
  float phase = 2.0*PI*(constrainPosition(pos)/10.0);
  for (int i=0; i<CircuitPlayground.strip.numPixels();++i) {
    // Use a sine wave to compute the value of each pixel based on its position for time
    // (and offset by the global phase that depends on fidget spinner position).
    float x = sin(2.0*PI*frequency*(i/10.0)+phase);
    CircuitPlayground.strip.setPixelColor(i, colorLerp(x, -1.0, 1.0, primaryColor(), secondaryColor()));
  }
  CircuitPlayground.strip.show();
}
