// Circuit Playground Birthday Candles
//
// All the NeoPixels will flicker like candles and the speaker will
// play the tune to Happy Birthday continuously.  Blow on the board
// to slowly blow out all the candles and hear a victory song!
// Controls:
//  - Slide switch: Move this to +/on to hear music or -/off to disable sound.
//  - Left button: Hold this down and press reset to use a rainbow flicker color.
//  - Right button: Hold this down and press reset to use a simple solid color (no flicker).
//  - If neither left or right button are pressed at startup then a flame-like
//    flickering animation will be used.
// After all the candles are blown out press reset to reset and start over!
//
// Author: Tony DiCola
// License: MIT (https://opensource.org/licenses/MIT)
#include <Adafruit_CircuitPlayground.h>

// General configuration defines:
#define BREATH_THRESHOLD  92    // Peak to peak sound pressure level that
                                // determines if someone is blowing on the board.
                                // You can open the serial console to see the sound
                                // levels and adjust as necessary!

#define FLAME_LIFE_MS     200   // Amount of time (in milliseconds) that each
                                // candle flame takes to blow out.  Increase this
                                // to make it harder/slower to blow them all out
                                // and decrease it to make it easier/faster.

#define FLAME_HUE         35    // Primary hue of the flame.  This is a value in
                                // degrees from 0.0 to 360.0, see HSV color space
                                // for different hue values:
                                //   https://en.wikipedia.org/wiki/HSL_and_HSV#/media/File:Hsl-hsv_models.svg
                                // The value 35 degrees is a nice orange in the
                                // middle of red and yellow hues that will look like
                                // a flame flickering as the hues animate.
                                // For the flicker effect the pixels will cycle 
                                // around hues that are +/-10 degrees of this value.
                                // For the solid effect the pixels will be set
                                // to this hue (at full saturation and value).
                                // Rainbow effect ignores this hue config and
                                // cycles through all of them.

#define LIT_CANDLES       10    // The number of candles to start with lit.  By
                                // default all 10 candles/pixels will be lit but
                                // adjust down to light less for a young kid's
                                // birthday.

// A few music note frequencies as defined in this tone example:
//   https://www.arduino.cc/en/Tutorial/toneMelody
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988

// Define note durations.  You only need to adjust the whole note
// time and other notes will be subdivided from it directly.
#define WHOLE         2200       // Length of time in milliseconds of a whole note (i.e. a full bar).
#define HALF          WHOLE/2
#define QUARTER       HALF/2
#define EIGHTH        QUARTER/2
#define EIGHTH_TRIPLE QUARTER/3
#define SIXTEENTH     EIGHTH/2

// Color gamma correction table, this makes the hues of the NeoPixels
// a little more accurate by accounting for our eye's non-linear color
// sensitivity.  See this great guide for more details:
//   https://learn.adafruit.com/led-tricks-gamma-correction/the-issue
const uint8_t PROGMEM gamma8[] = {
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  2,  2,  2,  2,  2,  2,  2,
    2,  3,  3,  3,  3,  3,  3,  3,  4,  4,  4,  4,  4,  5,  5,  5,
    5,  6,  6,  6,  6,  7,  7,  7,  7,  8,  8,  8,  9,  9,  9, 10,
   10, 10, 11, 11, 11, 12, 12, 13, 13, 13, 14, 14, 15, 15, 16, 16,
   17, 17, 18, 18, 19, 19, 20, 20, 21, 21, 22, 22, 23, 24, 24, 25,
   25, 26, 27, 27, 28, 29, 29, 30, 31, 32, 32, 33, 34, 35, 35, 36,
   37, 38, 39, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 50,
   51, 52, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 66, 67, 68,
   69, 70, 72, 73, 74, 75, 77, 78, 79, 81, 82, 83, 85, 86, 87, 89,
   90, 92, 93, 95, 96, 98, 99,101,102,104,105,107,109,110,112,114,
  115,117,119,120,122,124,126,127,129,131,133,135,137,138,140,142,
  144,146,148,150,152,154,156,158,160,162,164,167,169,171,173,175,
  177,180,182,184,186,189,191,193,196,198,200,203,205,208,210,213,
  215,218,220,223,225,228,231,233,236,239,241,244,247,249,252,255 };


// Global program state.
int lit = LIT_CANDLES;           // How many candles are still lit.  Once all are extinguished this falls to -1.
float frequencies[10] = {0};     // Random frequencies and phases will be generated for each pixel to
float phases[10] = {0};          // define an organic but random looking flicker effect.
enum AnimationType { SOLID, FLICKER, RAINBOW };  // Which type of animation is currently running.
AnimationType animation = FLICKER;


// Play a note of the specified frequency and for the specified duration.
// Hold is an optional bool that specifies if this note should be held a
// little longer, i.e. for eigth notes that are tied together.
// While waiting for a note to play the waitBreath delay function is used
// so breath detection and pixel animation continues to run.  No tones
// will play if the slide switch is in the -/off position or all the
// candles have been blown out.
void playNote(int frequency, int duration, bool hold=false, bool measure=true) {
  // Check if the slide switch is off or the candles have been blown out
  // and stop immediately without playing anything.
  if (!CircuitPlayground.slideSwitch() || lit < 0) {
    return;
  }
  if (hold) {
    // For a note that's held play it a little longer than the specified duration
    // so it blends into the next tone (but there's still a small delay to 
    // hear the next note).
    CircuitPlayground.playTone(frequency, duration + duration/32, false);
  }
  else {
    // For a note that isn't held just play it for the specified duration.
    CircuitPlayground.playTone(frequency, duration, false);
  }
  // Use waitBreath instead of Arduino's delay because breath detection and
  // pixel animation needs to occur while music plays.  However skip this logic
  // if not asked for (measure = false, only needed when playing celebration
  // song so as to not continue waiting for breaths).
  if (measure) {
    waitBreath(duration + duration/16);
  }
  else {
    delay(duration + duration/16);
  }
}

// Delay for the specified number of milliseconds while at the same time
// listening for a continuous loud sound on from the microphone, i.e. someone
// blowing directly on it, and animating the NeoPixels.  When a breath is detected
// the number of lit candles will gradually decrease.  Once the number of lit
// candles hits zero then a celebration tune is played and everything stops.
void waitBreath(uint32_t milliseconds) {
  float peakToPeak = measurePeak(milliseconds);
  // Serial.println(peakToPeak);
  while (peakToPeak >= BREATH_THRESHOLD) {
    // Decrement the number of lit candles and keep it from going below
    // the value -1 (a sentinel that indicates all the candles are blown out
    // and no music playback, etc. should occur anymore).
    lit = max(lit-1, -1);
    // For the simple solid color animation (i.e. no flickering) only update
    // the pixels when the lit pixel count changes.  This allows the tone
    // playback to sound better because the pixels don't need to be updated
    // during delays and music note playback (the pixel writing messes with
    // interrupts that drive tone playback and cause scratchier sounding tones).
    if (animation == SOLID) {
      showLitSolid();
    }
    // Check if we just hit 0 candles lit up, i.e. they're all blown out.
    // Turn off the pixels and play a little celebration tune when it 
    // happens, then indicate the candles are blown out with the -1 sentinel value.
    if (lit == 0) {
      CircuitPlayground.clearPixels();
      celebrateSong();
      lit = -1;
    }
    // Keep measuring the peak to peak sound value for a period of time
    // that it takes to blow out another candle.
    peakToPeak = measurePeak(FLAME_LIFE_MS);
  }
}

// Song to play when the candles are blown out.
void celebrateSong() {
  // Play a little charge melody, from:
  //  https://en.wikipedia.org/wiki/Charge_(fanfare)
  // Note the explicit boolean parameters in particular the measure=false
  // at the end.  This means the notes will play without any breath measurement
  // logic.  Without this false value playNote will try to keep waiting for candles
  // to blow out during the celebration song!
  playNote(NOTE_G4, EIGHTH_TRIPLE, true, false);
  playNote(NOTE_C5, EIGHTH_TRIPLE, true, false);
  playNote(NOTE_E5, EIGHTH_TRIPLE, false, false);
  playNote(NOTE_G5, EIGHTH, true, false);
  playNote(NOTE_E5, SIXTEENTH, false);
  playNote(NOTE_G5, HALF, false);
}

// Measure the peak to peak sound pressure level from the microphone
// for a specified number of milliseconds.
// While measuring the current NeoPixel animation will be updated too.
float measurePeak(uint32_t milliseconds) {
  float soundMax = 0;
  // Loop until the specified number of milliseconds have ellapsed.
  uint32_t start = millis();
  uint32_t current = start;
  while ((current - start) < milliseconds) {
    // Inside the loop check the sound pressure level 10ms at a time
    float sample = CircuitPlayground.mic.soundPressureLevel(10);
    Serial.println(sample);
    soundMax = max(sample, soundMax);
    // Be sure to drive the NeoPixel animation too.
    animatePixels(current);
    current = millis();
  }
  return soundMax;
}

// Perform a frame of animation on the NeoPixels.
// Current is the current monotonically increasing time in milliseconds.
void animatePixels(uint32_t current) {
  switch (animation) {
    case FLICKER:
      showLitFlicker(current);
      break;
    case RAINBOW:
      showLitRainbow(current);
      break;
    // Ignore the SOLID case as it has no animation.
    // This makes the audio smoother since it doesn't get interrupted by
    // NeoPixel writing like the other animations.  The pixels are instead
    // changed only once when the number of lit candles changes (see the
    // waitBreath function's loop).
  }
}

// Helper to change the color of a NeoPixel on the Circuit Playground board.
// Will automatically convert from HSV color space to RGB and apply gamma
// correction.
float setPixelHSV(int i, float h, float s, float v) {
  // Convert HSV to RGB
  float r, g, b = 0.0;
  HSVtoRGB(&r, &g, &b, h, s, v);
  // Lookup gamma correct RGB colors (also convert from 0...1.0 RGB range to 0...255 byte range).
  uint8_t r1 = pgm_read_byte(&gamma8[int(r*255.0)]);
  uint8_t g1 = pgm_read_byte(&gamma8[int(g*255.0)]);
  uint8_t b1 = pgm_read_byte(&gamma8[int(b*255.0)]);
  // Set the color of the pixel.
  CircuitPlayground.strip.setPixelColor(i, r1, g1, b1);
}

// Rainbow candle flicker animation.
// Uses a sine wave with random frequency and phase (computed ahead of time in setup)
// to smoothly modulate the hue of each NeoPixel candle flame over time.
void showLitRainbow(uint32_t current) {
  // Convert time from milliseconds to seconds.
  float t = current/1000.0;
  // Loop through each pixel and compute its color.
  for (int i=0; i<10; ++i) {
    if (i < lit) {
      // This pixel should be lit, so compute its hue from the sine wave
      // equation and set the color accordingly.  Notice the frequency
      // is scaled down by 10 to 'slow down' the rainbow flicker animation.
      // This lets the same random frequencies be shared between fast candle
      // flame effects and this slower rainbow flicker effect.
      float x  = sin(2.0*PI*frequencies[i]/10.0*t + phases[i]);
      // Interpolate the sine wave between all 360 degree hue values.
      float h = lerp(x, -1.0, 1.0, 0.0, 360.0);
      setPixelHSV(i, h, 1.0, 1.0);
    }
    else {
      // This pixel has been blown out, just turn it off.
      setPixelHSV(i, 0, 0, 0);
    }
  }
  CircuitPlayground.strip.show();
}

// Flickering candle animation effect.
// Uses a noisey sine wave to modulate the hue of each pixel within a range
// of flame colors.  The sine wave has some low and high frequency components
// which give it an organice and seemingly random appearance.
void showLitFlicker(uint32_t current) {
  // First determine the low and high bounds of the flicker hues.
  // These are +/- 10 degrees of the specified target hue and will
  // wrap around to the start/end as appropriate.
  float lowHue = fmod(FLAME_HUE - 10.0, 360.0);
  float highHue = fmod(FLAME_HUE + 10.0, 360.0);
  // Convert time from milliseconds to seconds.
  float t = current/1000.0;
  // Loop through each pixel and compute its color.
  for (int i=0; i<10; ++i) {
    if (i < lit) {
      // This pixel should be lit, so compute its hue by composing
      // a low frequency / slowly changing sine wave with a high
      // frequency / fast changing cosine wave.  This means the candle will
      // pulse and jump around in an organice but random looking way.
      // The frequencies and phases of the waves are randomly generated at
      // startup in the setup function.
      // Low frequency wave is a sine wave with random freuqency between 1 and 4,
      // and offset by a random phase to keep pixels from all starting at the same
      // color:
      float lowFreq  = sin(2.0*PI*frequencies[i]*t + phases[i]);
      // High frequency is a faster changing cosine wave that uses a different
      // pixel's random frequency.
      float highFreq = cos(3.0*PI*frequencies[(i+5)%10]*t);
      // Add the low and high frequency waves together, then interpolate their value
      // to a hue that's +/-20% of the configured target hue.
      float h = lerp(lowFreq+highFreq, -2.0, 2.0, lowHue, highHue);
      setPixelHSV(i, h, 1.0, 1.0);
    }
    else {
      // This pixel has been blown out, just turn it off.
      setPixelHSV(i, 0, 0, 0);
    }
  }
  CircuitPlayground.strip.show();
}

// Simple solid lit candle effect.
// No animation, each pixel is lit with the specified flame hue until they're all blown out.
void showLitSolid() {
  for (int i=0; i<10; ++i) {
    if (i < lit) {
      // This pixel should be lit.
      setPixelHSV(i, FLAME_HUE, 1.0, 1.0);
    }
    else {
      // This pixel has been blown out, just turn it off.
      setPixelHSV(i, 0, 0, 0);
    }
  }
  CircuitPlayground.strip.show();
}

// HSV to RGB color space conversion function taken directly from:
//  https://www.cs.rit.edu/~ncs/color/t_convert.html
void HSVtoRGB( float *r, float *g, float *b, float h, float s, float v )
{
  int i;
  float f, p, q, t;
  if( s == 0 ) {
    // achromatic (grey)
    *r = *g = *b = v;
    return;
  }
  h /= 60;      // sector 0 to 5
  i = floor( h );
  f = h - i;      // factorial part of h
  p = v * ( 1 - s );
  q = v * ( 1 - s * f );
  t = v * ( 1 - s * ( 1 - f ) );
  switch( i ) {
    case 0:
      *r = v;
      *g = t;
      *b = p;
      break;
    case 1:
      *r = q;
      *g = v;
      *b = p;
      break;
    case 2:
      *r = p;
      *g = v;
      *b = t;
      break;
    case 3:
      *r = p;
      *g = q;
      *b = v;
      break;
    case 4:
      *r = t;
      *g = p;
      *b = v;
      break;
    default:    // case 5:
      *r = v;
      *g = p;
      *b = q;
      break;
  }
}

// Linear interpolation of value y within y0...y1 given x and x0...x1.
float lerp(float x, float x0, float x1, float y0, float y1) {
  return y0 + (x-x0)*((y1-y0)/(x1-x0));
}

void setup() {
  // Initialize serial output and Circuit Playground library.
  Serial.begin(115200);
  CircuitPlayground.begin();
  // Check if a button is being pressed at startup and change the
  // animation mode accordingly.
  if (CircuitPlayground.leftButton()) {
    // Rainbow animation on left button press at startup.
    animation = RAINBOW;
  }
  else if (CircuitPlayground.rightButton()) {
    // Solid color animation on right button press at startup.
    animation = SOLID;
    // Since the solid animation doesn't update every frame, bootstrap it by
    // turning all the pixels on at the start.  As candles are blown out the
    // pixels will be updated (see the waitBreath function's loop).
    showLitSolid();
  }
  else {
    // Otherwise default to flicker animation.
    animation = FLICKER;
  }
  // Read the sound sensor and use it to initialize the random number generator.
  randomSeed(CircuitPlayground.soundSensor());
  // Precompute random frequency and phase values for each pixel.
  // This gives the flicker an organic but random looking appearance.
  for (int i=0; i<10; ++i) {
    // Generate random floating point frequency values between 1.0 and 4.0.
    frequencies[i] = random(1000, 4000)/1000.0;
    // Generate random floating point phase values between 0 and 2*PI.
    phases[i] = random(1000)/1000.0 * 2.0 * PI;
  }
}

void loop() {
  // Play happy birthday tune, from:
  //  http://www.irish-folk-songs.com/happy-birthday-tin-whistle-sheet-music.html#.WXFJMtPytBw
  // Inside each playNote call it will play a note and drive the NeoPixel animation
  // and check for a breath against the sound sensor.  Once all the candles are blown out
  // the playNote calls will stop playing music.
  playNote(NOTE_D4, EIGHTH, true);
  playNote(NOTE_D4, EIGHTH);
  playNote(NOTE_E4, QUARTER);       // Bar 1
  playNote(NOTE_D4, QUARTER);
  playNote(NOTE_G4, QUARTER);
  playNote(NOTE_FS4, HALF);         // Bar 2
  playNote(NOTE_D4, EIGHTH, true);
  playNote(NOTE_D4, EIGHTH);
  playNote(NOTE_E4, QUARTER);       // Bar 3
  playNote(NOTE_D4, QUARTER);
  playNote(NOTE_A4, QUARTER);
  playNote(NOTE_G4, HALF);          // Bar 4
  playNote(NOTE_D4, EIGHTH, true);
  playNote(NOTE_D4, EIGHTH);
  playNote(NOTE_D5, QUARTER);       // Bar 5
  playNote(NOTE_B4, QUARTER);
  playNote(NOTE_G4, QUARTER);
  playNote(NOTE_FS4, QUARTER);      // Bar 6
  playNote(NOTE_E4, QUARTER);
  playNote(NOTE_C5, EIGHTH, true);
  playNote(NOTE_C5, EIGHTH);
  playNote(NOTE_B4, QUARTER);       // Bar 7
  playNote(NOTE_G4, QUARTER);
  playNote(NOTE_A4, QUARTER);
  playNote(NOTE_G4, HALF);          // Bar 8
  // One second pause before repeating the loop and playing
  // the tune again.  Use waitBreath instead of delay so the
  // pixel animation and breath check continues to happen.
  waitBreath(1000);
}

