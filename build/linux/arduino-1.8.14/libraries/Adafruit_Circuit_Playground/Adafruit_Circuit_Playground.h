/*!
 * @file Adafruit_Circuit_Playground.h
 *
 * This is part of Adafruit's CircuitPlayground driver for the Arduino platform.  It is
 * designed specifically to work with the Adafruit CircuitPlayground boards.
 *
 * Adafruit invests time and resources providing this open source code,
 * please support Adafruit and open-source hardware by purchasing
 * products from Adafruit!
 *
 * Written by Ladyada and others for Adafruit Industries.
 *
 * BSD license, all text here must be included in any redistribution.
 *
 */

#ifndef _ADAFRUIT_CIRCUITPLAYGROUND_H_
#define _ADAFRUIT_CIRCUITPLAYGROUND_H_

#include <Arduino.h>
#include "utility/Adafruit_CPlay_NeoPixel.h"
#include "utility/Adafruit_CPlay_LIS3DH.h"
#include "utility/Adafruit_CPlay_Mic.h"
#include "utility/Adafruit_CPlay_Speaker.h"
#include "utility/CP_Firmata.h"

#if defined(__AVR__) || defined(ARDUINO_NRF52840_CIRCUITPLAY) // Circuit Playground 'classic'
  #include "utility/CPlay_CapacitiveSensor.h"
#else
  #include "utility/Adafruit_CPlay_FreeTouch.h"
  #include "utility/IRLibCPE.h"
#endif

#ifndef NOT_AN_INTERRUPT // Not defined in Arduino 1.0.5
  #define NOT_AN_INTERRUPT -1 ///< Pin is not on an interrupt
#endif

#ifdef __AVR__ // Circuit Playground 'classic'
 #define CPLAY_CAPSENSE_SHARED   30  ///< capacitive sense pin
 #define CPLAY_REDLED           13 ///< red LED pin
 #define CPLAY_NEOPIXELPIN      17 ///< neopixel pin
 #define CPLAY_SLIDESWITCHPIN   21 ///< slide switch pin
 #define CPLAY_LEFTBUTTON        4 ///< left button pin
 #define CPLAY_RIGHTBUTTON      19 ///< right button pin
 #define CPLAY_LIGHTSENSOR      A5 ///< light sensor pin
 #define CPLAY_THERMISTORPIN    A0 ///< thermistor pin
 #define CPLAY_SOUNDSENSOR      A4 ///< sound sensor pin
 #define CPLAY_BUZZER            5 ///< buzzer pin
 #define CPLAY_LIS3DH_CS         8 ///< LIS3DH chip select pin
 #define CPLAY_LIS3DH_INTERRUPT  7 ///< LIS3DH interrupt pin
 #define CPLAY_LIS3DH_ADDRESS    0x18 ///< LIS3DH I2C address
#elif defined(ARDUINO_NRF52840_CIRCUITPLAY)
 #include <math.h>
 #define CPLAY_CAPSENSE_SHARED  255 ///< we use ground instead of capacitive sense pin
 #define CPLAY_LEFTBUTTON        4 ///< left button pin
 #define CPLAY_RIGHTBUTTON       5 ///< right button pin
 #define CPLAY_SLIDESWITCHPIN    7 ///< slide switch pin
 #define CPLAY_NEOPIXELPIN       8 ///< neopixel pin
 #define CPLAY_REDLED           13 ///< red led pin
 #define CPLAY_BUZZER           A0 ///< buzzer pin
 #define CPLAY_LIGHTSENSOR      A8 ///< light sensor pin
 #define CPLAY_THERMISTORPIN    A9 ///< thermistor pin
 #define CPLAY_LIS3DH_CS        -1 ///< LIS3DH chip select pin
 #define CPLAY_LIS3DH_INTERRUPT 27 ///< LIS3DH interrupt pin
 #define CPLAY_LIS3DH_ADDRESS   0x19 ///< LIS3DH I2C address
#else // Circuit Playground Express
 #define CPLAY_LEFTBUTTON        4  ///< left button pin
 #define CPLAY_RIGHTBUTTON       5 ///< right button pin
 #define CPLAY_SLIDESWITCHPIN    7 ///< slide switch pin
 #define CPLAY_NEOPIXELPIN       8 ///< neopixel pin
 #define CPLAY_REDLED           13 ///< red led pin
 #define CPLAY_IR_EMITTER       25 ///< IR emmitter pin
 #define CPLAY_IR_RECEIVER      26 ///< IR receiver pin
 #define CPLAY_BUZZER           A0 ///< buzzer pin
 #define CPLAY_LIGHTSENSOR      A8 ///< light sensor pin
 #define CPLAY_THERMISTORPIN    A9 ///< thermistor pin
 #define CPLAY_SOUNDSENSOR      A4 ///< TBD I2S
 #define CPLAY_LIS3DH_CS        -1 ///< LIS3DH chip select pin
 #define CPLAY_LIS3DH_INTERRUPT 27 ///< LIS3DH interrupt pin
 #define CPLAY_LIS3DH_ADDRESS   0x19 ///< LIS3DH I2C address
#endif

#define SERIESRESISTOR 10000 ///< series resistor for thermistor
#define THERMISTORNOMINAL 10000 ///< resistance of thermistor at 25 degrees C
#define TEMPERATURENOMINAL 25 ///< temp. for nominal resistance (almost always 25 C)

#define BCOEFFICIENT 3380 ///< The beta coefficient of the thermistor (usually 3000-4000)

/*! 
  @brief Configuration to tune the color sensing logic:
   Amount of time (in milliseconds) to wait between 
   changing the pixel color and reading the light
    sensor.
*/
#define LIGHT_SETTLE_MS 100  

/**************************************************************************/
/*! 
    @brief  Class that stores state and functions for interacting with CircuitPlayground hardware
*/
/**************************************************************************/
class Adafruit_CircuitPlayground {
 public:
  bool begin(uint8_t brightness=20);

  Adafruit_CPlay_NeoPixel strip; ///< the neopixel strip object
  Adafruit_CPlay_LIS3DH lis; ///< the accelerometer object
  Adafruit_CPlay_Mic mic; ///< the microphone object
  Adafruit_CPlay_Speaker speaker; ///< the speaker object

#if defined (__AVR__) || defined(ARDUINO_NRF52840_CIRCUITPLAY) // Circuit Playground 'classic' or bluefruit
  CPlay_CapacitiveSensor cap[8]; ///< the array of capacitive touch sensors
#else
  Adafruit_CPlay_FreeTouch     cap[7]; ///< the array of capacitive touch sensors
  IRrecvPCI              irReceiver; ///< the IR receiver object
  IRdecode               irDecoder; ///< the IR decoder object
  IRsend                 irSend; ///< the IR send object
#endif

  bool slideSwitch(void);
  void redLED(bool v);
  void playTone(uint16_t freq, uint16_t time, bool wait=true);
  bool leftButton(void);
  bool rightButton(void);
  uint16_t lightSensor(void);
  int16_t soundSensor(void);
  float temperature(void);
  float temperatureF(void);

  uint16_t readCap(uint8_t p, uint8_t samples=10);

  // Accelerometer
  float motionX(void);
  float motionY(void);
  float motionZ(void);

/**************************************************************************/
/*! 
  @brief set the range of the MEMS accelerometer.
  @param range the range to set the accelerometer to. LIS3DH_RANGE_2_G
        is the smallest (+-2G) but will give the greatest precision, while LIS3DH_RANGE_8_G
        is the largest (+-8G) but with the lease precision. LIS3DH_RANGE_4_G is in the middle.
*/
/**************************************************************************/
  void setAccelRange(lis3dh_range_t range) { lis.setRange(range); }
/**************************************************************************/
/*! 
  @brief turn on tap detection. Tap detection can detect single taps or 'double taps' 
  (like a double-click).
  @param c If c is 1 you will only detect single taps, one at a time. 
            If c is 2, you will be able to detect both single taps and double taps.
  @param clickthresh the threshold over which to register a tap
*/
/**************************************************************************/
  void setAccelTap(uint8_t c, uint8_t clickthresh) 
    { lis.setClick(c, clickthresh, 10, 20, 255); }

/**************************************************************************/
/*! 
  @brief test whether or not a tap has been detected
  @return 0 if no tap is detected, 1 if a single tap is detected, and 2 or 3 if double tap is detected. 
*/
/**************************************************************************/
  uint8_t getAccelTap(void) { return (lis.getClick() >> 8) & 0x3; }


/**************************************************************************/
/*! 
  @brief turn off all neopixels on the board
*/
/**************************************************************************/
  void clearPixels(void) { strip.clear(); strip.show(); }

/**************************************************************************/
/*! 
  @brief set the color of a neopixel on the board
  @param p the pixel to set. Pixel 0 is above the pad labeled 'GND' right next to the
      USB connector, while pixel 9 is above the pad labeled '3.3V' on the other side of
      the USB connector.
  @param c a 24bit color value to set the pixel to
*/
/**************************************************************************/
  void setPixelColor(uint8_t p, uint32_t c) {strip.setPixelColor(p, c); strip.show();}

/**************************************************************************/
/*! 
  @brief set the color of a neopixel on the board
  @param p the pixel to set. Pixel 0 is above the pad labeled 'GND' right next to the
      USB connector, while pixel 9 is above the pad labeled '3.3V' on the other side of
      the USB connector.
  @param r a 0 to 255 value corresponding to the red component of the desired color.  
  @param g a 0 to 255 value corresponding to the green component of the desired color.
  @param b a 0 to 255 value corresponding to the blue component of the desired color.  
*/
/**************************************************************************/
  void setPixelColor(uint8_t p, uint8_t r, uint8_t g, uint8_t b) {strip.setPixelColor(p, r, g, b); strip.show();}
  
/*!  @brief set the global brightness of all neopixels.
     @param b a 0 to 255 value corresponding to the desired brightness. The default brightness
     of all neopixels is 30. */
  void setBrightness(uint16_t b){strip.setBrightness(b);}

/*!  @brief Get a sinusoidal value from a sine table
     @param x a 0 to 255 value corresponding to an index to the sine table
     @returns An 8-bit sinusoidal value back */
  uint8_t sine8(uint8_t x) { return strip.sine8(x); }

/*!  @brief Get a gamma-corrected value from a gamma table
     @param x a 0 to 255 value corresponding to an index to the gamma table
     @returns An 8-bit gamma-corrected value back */
  uint8_t gamma8(uint8_t x) { return strip.gamma8(x); }

  uint32_t colorWheel(uint8_t x);

  // Basic RGB color sensing with the light sensor and nearby neopixel.
  // Both functions do the same thing and just differ in how they return the
  // result, either as explicit RGB bytes or a 24-bit RGB color value.
  void senseColor(uint8_t& red, uint8_t& green, uint8_t& blue);

/**************************************************************************/
/*! 
  @brief detect a color using the onboard light sensor
  @return a 24 bit color. The most significant byte is red, followed by green, and
          the least significant byte is blue.
*/
/**************************************************************************/
  uint32_t senseColor() {
    // Use the individual color component color sense function and then recombine
    // tbe components into a 24-bit color value.
    uint8_t red, green, blue;
    senseColor(red, green, blue);
    return ((uint32_t)red << 16) | ((uint32_t)green << 8) | blue;
  }

  bool isExpress(void);

 private:


};


extern Adafruit_CircuitPlayground CircuitPlayground; ///< instantiated by default

#endif
