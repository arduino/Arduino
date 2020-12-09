// Speaker demo for Circuit Playground -- when tapped, plays a very short
// digitized sound sample, very quietly (because teeny tiny speaker).

#include <Adafruit_CircuitPlayground.h>
#include <Wire.h>
#include <SPI.h>

// Enable ONE of these lines to pick a sound to play back when tapped:
#include "coin.h" // Super Mario coin sound
//#include "trek.h" // Star Trek TNG communicator noise

volatile boolean play = false;

// This function will be called automatically when a tap is detected by the
// accelerometer.  This just sets the global flag 'play' to true, which is
// then detected in loop() (where the sound is then played)...doing heavy
// processing within an interrupt function is sometimes considered poor form.
void myFunction() {
  play = true; // Hey loop(), play the sound!
}

void setup() {
  CircuitPlayground.begin();

  // Configure accelerometer for +-4G range, use the tap interrupt
  // feature to call myFunction() automatically when tapped.
  CircuitPlayground.setAccelRange(LIS3DH_RANGE_4_G);
  CircuitPlayground.setAccelTap(1, 127);
  attachInterrupt(digitalPinToInterrupt(CPLAY_LIS3DH_INTERRUPT), myFunction, RISING);
}

void loop() {
  while(!play); // Wait for tap interrupt

  // Play sound data in the audio[] array (declared in one of the .h files).
  // This function "blocks" -- that is, program flow stops until sound is
  // done playing -- it does not play in the background.
  CircuitPlayground.speaker.playSound(audio, sizeof(audio), SAMPLE_RATE);

  // Calling speaker.end() after playing a sound is optional -- this will
  // turn off the pin 13 LED (it's connected to a microcontroller pin that's
  // also related to the speaker), but there's a small audible click when it
  // turns off.  Tradeoffs!
  CircuitPlayground.speaker.end();

  play = false; // Clear flag, wait for interrupt
}
