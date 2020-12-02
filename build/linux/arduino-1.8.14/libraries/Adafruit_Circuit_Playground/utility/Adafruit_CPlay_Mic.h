// Adafruit Circuit Playground microphone library
// by Phil Burgess / Paint Your Dragon.
// Fast Fourier transform section is derived from
// ELM-ChaN FFT library (see comments in ffft.S).

#ifndef ADAFRUIT_CPLAY_MIC_H
#define ADAFRUIT_CPLAY_MIC_H

#ifdef __GNUC__
  #define DEPRECATED(func) func __attribute__ ((deprecated))
#elif defined(_MSC_VER)
  #define DEPRECATED(func) __declspec(deprecated) func
#else
  #pragma message("WARNING: You need to implement DEPRECATED for this compiler")
  #define DEPRECATED(func) func
#endif

#include "Adafruit_ZeroPDM.h"


/**************************************************************************/
/*! 
    @brief  Class that stores state and functions for the microphone on CircuitPlayground boards
*/
/**************************************************************************/
class Adafruit_CPlay_Mic {
 public:
  Adafruit_CPlay_Mic(void) {}; // Empty constructor
  int  peak(uint16_t ms)  __attribute__ ((deprecated));
  void capture(int16_t *buf, uint16_t nSamples),
       fft(uint16_t *spectrum);

  float soundPressureLevel(uint16_t ms);

private:
#if defined(ARDUINO_ARCH_SAMD)
  static Adafruit_ZeroPDM pdm;
#endif
};

#endif // ADAFRUIT_CPLAY_MIC_H
