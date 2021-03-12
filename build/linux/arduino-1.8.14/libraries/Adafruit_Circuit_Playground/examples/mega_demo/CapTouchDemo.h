#ifndef CAPTOUCHDEMO_H
#define CAPTOUCHDEMO_H

#include "Demo.h"


#define CAP_SAMPLES      20   // Number of samples to take for a capacitive touch read.
#define TONE_DURATION_MS 100  // Duration in milliseconds to play a tone when touched.

class CapTouchDemo: public Demo {
public:
  uint16_t CAP_THRESHOLD = 200;  // Threshold for a capacitive touch (higher = less sensitive).

  CapTouchDemo() { 
    playSound = false; 
    if (CircuitPlayground.isExpress()) {
      CAP_THRESHOLD = 800;
    } else {
      CAP_THRESHOLD = 200;
    }
  }
  ~CapTouchDemo() {}

  
  virtual void loop() {
    // Clear all the neopixels.
    for (int i=0; i<10; ++i) {
      CircuitPlayground.strip.setPixelColor(i, 0);
    }
    
    // Check if any of the cap touch inputs are pressed and turn on those pixels.
    // Also play a tone if in tone playback mode.
    if (CircuitPlayground.readCap(0, CAP_SAMPLES) >= CAP_THRESHOLD) {
      CircuitPlayground.strip.setPixelColor(3, CircuitPlayground.colorWheel(256/10*3));
      if (playSound) {
        CircuitPlayground.playTone(330, TONE_DURATION_MS);  // 330hz = E4
      }
    }
    if (CircuitPlayground.readCap(1, CAP_SAMPLES) >= CAP_THRESHOLD) {
      CircuitPlayground.strip.setPixelColor(4, CircuitPlayground.colorWheel(256/10*4));
      if (playSound) {
        CircuitPlayground.playTone(349, TONE_DURATION_MS);  // 349hz = F4
      }
    }
    if (CircuitPlayground.readCap(2, CAP_SAMPLES) >= CAP_THRESHOLD) {
      CircuitPlayground.strip.setPixelColor(1, CircuitPlayground.colorWheel(256/10));
      if (playSound) {
        CircuitPlayground.playTone(294, TONE_DURATION_MS);  // 294hz = D4
      }
    }
    if (CircuitPlayground.readCap(3, CAP_SAMPLES) >= CAP_THRESHOLD) {
      CircuitPlayground.strip.setPixelColor(0, CircuitPlayground.colorWheel(0));
      if (playSound) {
        CircuitPlayground.playTone(262, TONE_DURATION_MS);  // 262hz = C4
      }
    }
    if (CircuitPlayground.readCap(6, CAP_SAMPLES) >= CAP_THRESHOLD) {
      CircuitPlayground.strip.setPixelColor(6, CircuitPlayground.colorWheel(256/10*6));
      if (playSound) {
        CircuitPlayground.playTone(440, TONE_DURATION_MS);  // 440hz = A4
      }
    }
    if (CircuitPlayground.readCap(9, CAP_SAMPLES) >= CAP_THRESHOLD) {
      CircuitPlayground.strip.setPixelColor(8, CircuitPlayground.colorWheel(256/10*8));
      if (playSound) {
        CircuitPlayground.playTone(494, TONE_DURATION_MS);  // 494hz = B4
      }
    }
    if (CircuitPlayground.readCap(10, CAP_SAMPLES) >= CAP_THRESHOLD) {
      CircuitPlayground.strip.setPixelColor(9, CircuitPlayground.colorWheel(256/10*9));
      if (playSound) {
        CircuitPlayground.playTone(523, TONE_DURATION_MS);  // 523hz = C5
      }
    }
    if (CircuitPlayground.readCap(12, CAP_SAMPLES) >= CAP_THRESHOLD) {
      CircuitPlayground.strip.setPixelColor(5, CircuitPlayground.colorWheel(256/10*5));
      if (playSound) {
        CircuitPlayground.playTone(392, TONE_DURATION_MS);  // 392hz = G4
      }
    }

    // Light up the pixels.
    CircuitPlayground.strip.show();
  }

  virtual void modePress() {
    // Turn sound on/off.
    playSound = !playSound;
  }

private:
  bool playSound;
};

#endif
