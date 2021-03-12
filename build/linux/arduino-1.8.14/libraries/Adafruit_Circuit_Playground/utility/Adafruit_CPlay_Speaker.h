// Adafruit Circuit Playground speaker library
// by Phil Burgess / Paint Your Dragon.

#ifndef ADAFRUIT_CPLAY_SPEAKER_H
#define ADAFRUIT_CPLAY_SPEAKER_H

#include <Arduino.h>

#if !defined(__AVR__) // circuit playground express has nicer amp w/shutdown
  #define CPLAY_SPEAKER_SHUTDOWN 11 ///< shutdown pin (Express boards only)
#endif

/**************************************************************************/
/*! 
    @brief  Class that stores state and functions for the speaker on CircuitPlayground boards
*/
/**************************************************************************/
class Adafruit_CPlay_Speaker {
 public:
  Adafruit_CPlay_Speaker(void) { started = false; };
  void begin(void),
       end(void),
       set(uint8_t value),
       playSound(const uint8_t *data, uint32_t length, uint16_t sampleRate,
         bool tenBit=false),
       say(const uint8_t *addr);

  void enable(bool e);

  /**************************************************************************/
  /*! 
      @brief  disable the speaker.
      @note this function only has an effect on 'Express' boards
  */
  /**************************************************************************/
  void off(void) { enable(false); };

  /**************************************************************************/
  /*! 
      @brief  enable the speaker.
      @note this function only has an effect on 'Express' boards
  */
  /**************************************************************************/
  void on(void) { enable(true); };

 private:
  bool started;
};

#endif // ADAFRUIT_CPLAY_SPEAKER_H
