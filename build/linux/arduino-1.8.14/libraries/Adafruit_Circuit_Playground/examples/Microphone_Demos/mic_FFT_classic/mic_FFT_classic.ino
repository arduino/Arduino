// FFT-based audio visualizer for Adafruit Circuit Playground: uses the
// built-in mic on A4, 10x NeoPixels for display.  Built on the ELM-Chan
// FFT library for AVR microcontrollers.

// The fast Fourier transform (FFT) algorithm converts a signal from the
// time domain to the frequency domain -- e.g. turning a sampled audio
// signal into a visualization of frequencies and magnitudes -- an EQ meter.

// The FFT algorithm itself is handled in the Circuit Playground library;
// the code here is mostly for converting that function's output into
// animation.  In most AV gear it's usually done with bargraph displays;
// with a 1D output (the 10 NeoPixels) we need to get creative with color
// and brightness...it won't look great in every situation (seems to work
// best with LOUD music), but it's colorful and fun to look at.  So this
// code is mostly a bunch of tables and weird fixed-point (integer) math
// that probably doesn't make much sense even with all these comments.

#include <Adafruit_CircuitPlayground.h>
#include <Wire.h>
#include <SPI.h>

// GLOBAL STUFF ------------------------------------------------------------

// Displaying EQ meter output straight from the FFT may be 'correct,' but
// isn't always visually interesting (most bins spend most time near zero).
// Dynamic level adjustment narrows in on a range of values so there's
// always something going on.  The upper and lower range are based on recent
// audio history, and on a per-bin basis (some may be more active than
// others, so this keeps one or two "loud" bins from spoiling the rest.

#define BINS   10          // FFT output is filtered down to this many bins
#define FRAMES 4           // This many FFT cycles are averaged for leveling
uint8_t lvl[FRAMES][BINS], // Bin levels for the prior #FRAMES frames
        avgLo[BINS],       // Pseudo rolling averages for bins -- lower and
        avgHi[BINS],       // upper limits -- for dynamic level adjustment.
        frameIdx = 0;      // Counter for lvl storage

// CALIBRATION CONSTANTS ---------------------------------------------------

const uint8_t PROGMEM
  // Low-level noise initially subtracted from each of 32 FFT bins
  noise[]    = { 0x04,0x03,0x03,0x03, 0x02,0x02,0x02,0x02,
                 0x02,0x02,0x02,0x02, 0x01,0x01,0x01,0x01,
                 0x01,0x01,0x01,0x01, 0x01,0x01,0x01,0x01,
                 0x01,0x01,0x01,0x01, 0x01,0x01,0x01,0x01 },
  // FFT bins (32) are then filtered down to 10 output bins (to match the
  // number of NeoPixels on Circuit Playground).  10 arrays here, one per
  // output bin.  First element of each is the number of input bins to
  // merge, second element is index of first merged bin, remaining values
  // are scaling weights as each input bin is merged into output.  The
  // merging also "de-linearizes" the FFT output, so it's closer to a
  // logarithmic scale with octaves evenly-ish spaced, music looks better.
  bin0data[] = { 1, 2, 147 },
  bin1data[] = { 2, 2, 89, 14 },
  bin2data[] = { 2, 3, 89, 14 },
  bin3data[] = { 4, 3, 15, 181, 58, 3 },
  bin4data[] = { 4, 4, 15, 181, 58, 3 },
  bin5data[] = { 6, 5, 6, 89, 185, 85, 14, 2 },
  bin6data[] = { 7, 7, 5, 60, 173, 147, 49, 9, 1 },
  bin7data[] = { 10, 8, 3, 23, 89, 170, 176, 109, 45, 14, 4, 1 },
  bin8data[] = { 13, 11, 2, 12, 45, 106, 167, 184, 147, 89, 43, 18, 6, 2, 1 },
  bin9data[] = { 18, 14, 2, 6, 19, 46, 89, 138, 175, 185, 165, 127, 85, 51, 27, 14, 7, 3, 2, 1 },
  // Pointers to 10 bin arrays, because PROGMEM arrays-of-arrays are weird:
  * const binData[] = { bin0data, bin1data, bin2data, bin3data, bin4data,
                        bin5data, bin6data, bin7data, bin8data, bin9data },
  // R,G,B values for color wheel covering 10 NeoPixels:
  reds[]   = { 0xAD, 0x9A, 0x84, 0x65, 0x00, 0x00, 0x00, 0x00, 0x65, 0x84 },
  greens[] = { 0x00, 0x66, 0x87, 0x9E, 0xB1, 0x87, 0x66, 0x00, 0x00, 0x00 },
  blues[]  = { 0x00, 0x00, 0x00, 0x00, 0x00, 0xC3, 0xE4, 0xFF, 0xE4, 0xC3 },
  gamma8[] = { // Gamma correction improves the appearance of midrange colors
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x03, 0x03, 0x03, 0x03,
    0x03, 0x03, 0x04, 0x04, 0x04, 0x04, 0x05, 0x05, 0x05, 0x05, 0x05, 0x06,
    0x06, 0x06, 0x06, 0x07, 0x07, 0x07, 0x08, 0x08, 0x08, 0x09, 0x09, 0x09,
    0x0A, 0x0A, 0x0A, 0x0B, 0x0B, 0x0B, 0x0C, 0x0C, 0x0D, 0x0D, 0x0D, 0x0E,
    0x0E, 0x0F, 0x0F, 0x10, 0x10, 0x11, 0x11, 0x12, 0x12, 0x13, 0x13, 0x14,
    0x14, 0x15, 0x15, 0x16, 0x16, 0x17, 0x18, 0x18, 0x19, 0x19, 0x1A, 0x1B,
    0x1B, 0x1C, 0x1D, 0x1D, 0x1E, 0x1F, 0x1F, 0x20, 0x21, 0x22, 0x22, 0x23,
    0x24, 0x25, 0x26, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x2A, 0x2B, 0x2C, 0x2D,
    0x2E, 0x2F, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39,
    0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F, 0x40, 0x41, 0x42, 0x44, 0x45, 0x46,
    0x47, 0x48, 0x49, 0x4B, 0x4C, 0x4D, 0x4E, 0x50, 0x51, 0x52, 0x54, 0x55,
    0x56, 0x58, 0x59, 0x5A, 0x5C, 0x5D, 0x5E, 0x60, 0x61, 0x63, 0x64, 0x66,
    0x67, 0x69, 0x6A, 0x6C, 0x6D, 0x6F, 0x70, 0x72, 0x73, 0x75, 0x77, 0x78,
    0x7A, 0x7C, 0x7D, 0x7F, 0x81, 0x82, 0x84, 0x86, 0x88, 0x89, 0x8B, 0x8D,
    0x8F, 0x91, 0x92, 0x94, 0x96, 0x98, 0x9A, 0x9C, 0x9E, 0xA0, 0xA2, 0xA4,
    0xA6, 0xA8, 0xAA, 0xAC, 0xAE, 0xB0, 0xB2, 0xB4, 0xB6, 0xB8, 0xBA, 0xBC,
    0xBF, 0xC1, 0xC3, 0xC5, 0xC7, 0xCA, 0xCC, 0xCE, 0xD1, 0xD3, 0xD5, 0xD7,
    0xDA, 0xDC, 0xDF, 0xE1, 0xE3, 0xE6, 0xE8, 0xEB, 0xED, 0xF0, 0xF2, 0xF5,
    0xF7, 0xFA, 0xFC, 0xFF };
const uint16_t PROGMEM
  // Scaling values applied to each FFT bin (32) after noise subtraction
  // but prior to merging/filtering.  When multiplied by these values,
  // then divided by 256, these tend to produce outputs in the 0-255
  // range (VERY VERY "ISH") at normal listening levels.  These were
  // determined empirically by throwing lots of sample audio at it.
  binMul[] = { 405, 508, 486, 544, 533, 487, 519, 410,
               481, 413, 419, 410, 397, 424, 412, 411,
               511, 591, 588, 577, 554, 529, 524, 570,
               546, 559, 511, 552, 439, 488, 483, 547, },
  // Sums of bin weights for bin-merging tables above.
  binDiv[]   = { 147, 103, 103, 257, 257, 381, 444, 634, 822, 1142 };

// SETUP FUNCTION - runs once ----------------------------------------------

void setup() {
  CircuitPlayground.begin();
  CircuitPlayground.setBrightness(255);
  CircuitPlayground.clearPixels();

  // Initialize rolling average ranges
  uint8_t i;
  for(i=0; i<BINS; i++) {
    avgLo[i] = 0;
    avgHi[i] = 255;
  }
  for(i=0; i<FRAMES; i++) {
    memset(&lvl[i], 127, sizeof(lvl[i]));
  }
}

// LOOP FUNCTION - runs over and over - does animation ---------------------

void loop() {
  uint16_t spectrum[32]; // FFT spectrum output buffer

  CircuitPlayground.mic.fft(spectrum);

  // spectrum[] is now raw FFT output, 32 bins.

  // Remove noise and apply EQ levels
  uint8_t  i, N;
  uint16_t S;
  for(i=0; i<32; i++) {
    N = pgm_read_byte(&noise[i]);
    if(spectrum[i] > N) { // Above noise threshold: scale & clip
      S           = ((spectrum[i] - N) *
                     (uint32_t)pgm_read_word(&binMul[i])) >> 8;
      spectrum[i] = (S < 255) ? S : 255;
    } else { // Below noise threshold: clip
      spectrum[i] = 0;
    }
  }
  // spectrum[] is now noise-filtered, scaled & clipped
  // FFT output, in range 0-255, still 32 bins.

  // Filter spectrum[] from 32 elements down to 10,
  // make pretty colors out of it:

  uint16_t sum, level;
  uint8_t  j, minLvl, maxLvl, nBins, binNum, *data;

  for(i=0; i<BINS; i++) { // For each output bin (and each pixel)...
    data   = (uint8_t *)pgm_read_word(&binData[i]);
    nBins  = pgm_read_byte(&data[0]); // Number of input bins to merge
    binNum = pgm_read_byte(&data[1]); // Index of first input bin
    data  += 2;
    for(sum=0, j=0; j<nBins; j++) {
      sum += spectrum[binNum++] * pgm_read_byte(&data[j]); // Total
    }
    sum /= pgm_read_word(&binDiv[i]);                      // Average
    lvl[frameIdx][i] = sum;      // Save for rolling averages
    minLvl = maxLvl = lvl[0][i]; // Get min and max range for bin
    for(j=1; j<FRAMES; j++) {    // from prior stored frames
      if(lvl[j][i] < minLvl)      minLvl = lvl[j][i];
      else if(lvl[j][i] > maxLvl) maxLvl = lvl[j][i];
    }

    // minLvl and maxLvl indicate the extents of the FFT output for this
    // bin over the past few frames, used for vertically scaling the output
    // graph (so it looks interesting regardless of volume level).  If too
    // close together though (e.g. at very low volume levels) the graph
    // becomes super coarse and 'jumpy'...so keep some minimum distance
    // between them (also lets the graph go to zero when no sound playing):
    if((maxLvl - minLvl) < 23) {
      maxLvl = (minLvl < (255-23)) ? minLvl + 23 : 255;
    }
    avgLo[i] = (avgLo[i] * 7 + minLvl) / 8; // Dampen min/max levels
    avgHi[i] = (maxLvl >= avgHi[i]) ?       // (fake rolling averages)
      (avgHi[i] *  3 + maxLvl) /  4 :       // Fast rise
      (avgHi[i] * 31 + maxLvl) / 32;        // Slow decay

    // Second fixed-point scale then 'stretches' each bin based on
    // dynamic min/max levels to 0-256 range:
    level = 1 + ((sum <= avgLo[i]) ? 0 :
                 256L * (sum - avgLo[i]) / (long)(avgHi[i] - avgLo[i]));
    // Clip output and convert to color:
    if(level <= 255) {
      uint8_t r = (pgm_read_byte(&reds[i])   * level) >> 8,
              g = (pgm_read_byte(&greens[i]) * level) >> 8,
              b = (pgm_read_byte(&blues[i])  * level) >> 8;
      CircuitPlayground.strip.setPixelColor(i,
        pgm_read_byte(&gamma8[r]),
        pgm_read_byte(&gamma8[g]),
        pgm_read_byte(&gamma8[b]));
    } else { // level = 256, show white pixel OONTZ OONTZ
      CircuitPlayground.strip.setPixelColor(i, 0x56587F);
    }
  }
  CircuitPlayground.strip.show();

  if(++frameIdx >= FRAMES) frameIdx = 0;
}
