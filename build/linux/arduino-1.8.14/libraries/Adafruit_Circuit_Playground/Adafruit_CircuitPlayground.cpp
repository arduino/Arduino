/*!
 * @file Adafruit_CircuitPlayground.cpp
 *
 * @mainpage Adafruit CircuitPlayground Library
 *
 * @section intro_sec Introduction
 *
 * This is the documentation for Adafruit's CircuitPlayground driver for the
 * Arduino platform.  It is designed specifically to work with the
 * Adafruit CircuitPlayground boards:
 *  - https://www.adafruit.com/products/3000
 *  - https://www.adafruit.com/products/3333
 *
 *
 * Adafruit invests time and resources providing this open source code,
 * please support Adafruit and open-source hardware by purchasing
 * products from Adafruit!
 *
 *
 * @section author Author
 *
 * Written by Ladyada and others for Adafruit Industries.
 *
 * @section license License
 *
 * BSD license, all text here must be included in any redistribution.
 *
 */

#include <Adafruit_Circuit_Playground.h>

/**************************************************************************/
/*!
    @brief  Set up the CircuitPlayground hardware
    @param  brightness Optional brightness to set the neopixels to
    @returns True if device is set up, false on any failure
*/
/**************************************************************************/
bool Adafruit_CircuitPlayground::begin(uint8_t brightness) {
  pinMode(CPLAY_REDLED, OUTPUT);
  pinMode(CPLAY_BUZZER, OUTPUT);
#if defined(__AVR__)
  pinMode(CPLAY_CAPSENSE_SHARED, OUTPUT);
  pinMode(CPLAY_LEFTBUTTON, INPUT);
  pinMode(CPLAY_RIGHTBUTTON, INPUT);
  pinMode(CPLAY_SLIDESWITCHPIN, INPUT);
#elif defined(ARDUINO_NRF52840_CIRCUITPLAY) // bluefruit
  pinMode(CPLAY_LEFTBUTTON, INPUT_PULLDOWN);
  pinMode(CPLAY_RIGHTBUTTON, INPUT_PULLDOWN);
  pinMode(CPLAY_SLIDESWITCHPIN, INPUT_PULLUP);
  pinMode(CPLAY_SPEAKER_SHUTDOWN, OUTPUT);
  digitalWrite(CPLAY_SPEAKER_SHUTDOWN, HIGH);
#elif defined(__SAMD21G18A__) // Circuit Playground Express
  pinMode(CPLAY_LEFTBUTTON, INPUT_PULLDOWN);
  pinMode(CPLAY_RIGHTBUTTON, INPUT_PULLDOWN);
  pinMode(CPLAY_SLIDESWITCHPIN, INPUT_PULLUP);
  irReceiver=IRrecvPCI(CPLAY_IR_RECEIVER);
  irDecoder=IRdecode();
  // since we aren't calling speaker.begin() anymore, do this here
  pinMode(CPLAY_SPEAKER_SHUTDOWN, OUTPUT);
  digitalWrite(CPLAY_SPEAKER_SHUTDOWN, HIGH);
#endif


  strip = Adafruit_CPlay_NeoPixel();
  strip.updateType(NEO_GRB + NEO_KHZ800);
  strip.updateLength(10);
  strip.setPin(CPLAY_NEOPIXELPIN);

#ifdef __AVR__ // Circuit Playground 'classic'
  lis = Adafruit_CPlay_LIS3DH(CPLAY_LIS3DH_CS, &SPI); // SPI
#elif defined(ARDUINO_NRF52840_CIRCUITPLAY)
  lis = Adafruit_CPlay_LIS3DH(&Wire1); // i2c on wire1
#else // samd21
  lis = Adafruit_CPlay_LIS3DH(&Wire1); // i2c on wire1
#endif

  mic = Adafruit_CPlay_Mic();

  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  strip.setBrightness(brightness);

#if defined(__AVR__) || defined(ARDUINO_NRF52840_CIRCUITPLAY) // bluefruit
  cap[0] = CPlay_CapacitiveSensor(CPLAY_CAPSENSE_SHARED, 0);
  cap[1] = CPlay_CapacitiveSensor(CPLAY_CAPSENSE_SHARED, 1);
  cap[2] = CPlay_CapacitiveSensor(CPLAY_CAPSENSE_SHARED, 2);
  cap[3] = CPlay_CapacitiveSensor(CPLAY_CAPSENSE_SHARED, 3);
  cap[4] = CPlay_CapacitiveSensor(CPLAY_CAPSENSE_SHARED, 6);
  cap[5] = CPlay_CapacitiveSensor(CPLAY_CAPSENSE_SHARED, 9);
  cap[6] = CPlay_CapacitiveSensor(CPLAY_CAPSENSE_SHARED, 10);
  cap[7] = CPlay_CapacitiveSensor(CPLAY_CAPSENSE_SHARED, 12);
#elif defined(__SAMD21G18A__) // Circuit Playground Express
  for(int i=0; i<7; i++) {
    cap[i] = Adafruit_CPlay_FreeTouch(A1+i, OVERSAMPLE_4, RESISTOR_50K, FREQ_MODE_NONE);
    if (! cap[i].begin()) return false;
  }
#endif

  return lis.begin(CPLAY_LIS3DH_ADDRESS);
}

/**************************************************************************/
/*!
    @brief  read capacitive touch sensor
    @param  p the pin to read. Must be a captouch enabled pin.
    @param  samples Optional number of samples to take. Defaults to 10.
    @returns measured captouch value
*/
/**************************************************************************/
uint16_t Adafruit_CircuitPlayground::readCap(uint8_t p, uint8_t samples) {
#if defined(__AVR__) || defined(ARDUINO_NRF52840_CIRCUITPLAY) // Circuit Playground Classic or bluefruit
  switch (p) {
    case 0:    return cap[0].capacitiveSensor(samples);
    case 1:    return cap[1].capacitiveSensor(samples);
    case 2:    return cap[2].capacitiveSensor(samples);
    case 3:    return cap[3].capacitiveSensor(samples);
    case 6:    return cap[4].capacitiveSensor(samples);
    case 9:    return cap[5].capacitiveSensor(samples);
    case 10:   return cap[6].capacitiveSensor(samples);
    case 12:   return cap[7].capacitiveSensor(samples);
    default:   return 0;
  }
#elif defined(__SAMD21G18A__) // Circuit Playground Express
  // analog pins r ez!
  if ((p >= A1) && (p <= A7)) {
    return cap[p - A1].measure();
  }
  // oof digital pins
  switch (p) {
    case 0:    return cap[A6 - A1].measure();
    case 1:    return cap[A7 - A1].measure();
    case 2:    return cap[A5 - A1].measure();
    case 3:    return cap[A4 - A1].measure();
    case 6:    return cap[A1 - A1].measure();
    case 9:    return cap[A2 - A1].measure();
    case 10:   return cap[A3 - A1].measure();
    default:   return 0;
  }
#endif
}

/**************************************************************************/
/*!
    @brief turn on or off the red LED on pin #13
    @param  v pass true to turn LED on, false to turn LED off
*/
/**************************************************************************/
void Adafruit_CircuitPlayground::redLED(bool v) {
  digitalWrite(CPLAY_REDLED, v);
}

/**************************************************************************/
/*!
    @brief read the slide switch
    @returns true if slide switch in set, false if not
*/
/**************************************************************************/
bool Adafruit_CircuitPlayground::slideSwitch(void) {
  return digitalRead(CPLAY_SLIDESWITCHPIN);
}

/**************************************************************************/
/*!
    @brief read the left button
    @returns true if button is pressed, false if not
*/
/**************************************************************************/
bool Adafruit_CircuitPlayground::leftButton(void) {
  return digitalRead(CPLAY_LEFTBUTTON);
}

/**************************************************************************/
/*!
    @brief read the right button
    @returns true if button is pressed, false if not
*/
/**************************************************************************/
bool Adafruit_CircuitPlayground::rightButton(void) {
  return digitalRead(CPLAY_RIGHTBUTTON);
}

/**************************************************************************/
/*!
    @brief play a tone on the onboard buzzer
    @param  freq the frequency to play
    @param  time the duration of the tone in milliseconds
    @param  wait Optional flag to wait for time milliseconds after playing the tone. Defaults to true.
    @note The driver circuitry is an on/off transistor driver, so you will only be able to play square waves.
    It is also not the same loudness over all frequencies but is designed to be the loudest at around 4 KHz
*/
/**************************************************************************/
void Adafruit_CircuitPlayground::playTone(
  uint16_t freq, uint16_t time, bool wait) {
#ifdef __AVR__
#define F_PLL 48000000
  if(!freq) return;
  uint32_t ocr;
  uint16_t prescale  = 1;
  uint8_t  scalebits = 0;
  uint8_t  hi1, lo1, hi2, lo2;

  // Determine best prescaler setting for 10-bit timer
  do {
    scalebits++;
    ocr       = F_PLL / freq / prescale - 1;
    prescale *= 2;
    if(prescale >= 16384) {
      ocr       = 1023;
      scalebits = 0b1111;
    }
  } while(ocr > 1023);

  // Set up Timer4 for fast PWM on !OC4A
  PLLFRQ  = (PLLFRQ & 0xCF) | 0x30;   // Route PLL to async clk
  TCCR4A  = _BV(COM4A0) | _BV(PWM4A); // Clear on match, PWMA on
  TCCR4B  = _BV(PWM4X)  | scalebits;  // PWM invert
  TCCR4D  = 0;                        // Fast PWM mode
  TCCR4E  = 0;                        // Not enhanced mode
  DT4     = 0;                        // No dead time
  hi1     = ocr >> 8;
  lo1     = ocr & 0xFF;
  hi2     = ocr >> 9;
  lo2     = (ocr >> 1) & 0xFF;
  noInterrupts();                     // TC4H accesses MUST be atomic
  TC4H    = hi1;
  OCR4C   = lo1;                      // TOP
  TC4H    = hi2;
  OCR4A   = lo2;                      // 50% duty
  interrupts();
  pinMode(5, OUTPUT);                 // Enable output
  delay(time);
  pinMode(5, INPUT);                  // Disable output
  TCCR4A  = 0;                        // PWMA off
#else
  tone(CPLAY_BUZZER, freq, time);
  delay(time); // time argument to tone() isn't working, so...
#endif
  if(wait) delay(time);
}

/**************************************************************************/
/*!
    @brief read the onboard lightsensor
    @returns value between 0 and 1023 read from the light sensor
    @note 1000 Lux will roughly read as 2 Volts (or about 680 as a raw analog reading).
      A reading of about 300 is common for most indoor light levels.
      Note that outdoor daylight is 10,000 Lux or even higher, so this sensor is best
      suited for indoor light levels!
*/
/**************************************************************************/
uint16_t Adafruit_CircuitPlayground::lightSensor(void) {
  return analogRead(CPLAY_LIGHTSENSOR);
}

/**************************************************************************/
/*!
    @brief read the onboard sound sensor. A reading of ~0 is silent, and
    loud audio will result in a reading between -500 and 500 or so.
    @returns value of the sound sensor
*/
/**************************************************************************/
int16_t Adafruit_CircuitPlayground::soundSensor(void) {
  int16_t x;
  mic.capture(&x, 1);
  return x;
}

/**************************************************************************/
/*!
    @brief read the X parameter of the onboard accelerometer. Value returned is
     defined by setAccelRange().
    @returns X value of the accelerometer
*/
/**************************************************************************/
float Adafruit_CircuitPlayground::motionX(void) {
  sensors_event_t event;
  CircuitPlayground.lis.getEvent(&event);
  return event.acceleration.x;
}

/**************************************************************************/
/*!
    @brief read the Y parameter of the onboard accelerometer. Value returned is
     defined by setAccelRange().
    @returns Y value of the accelerometer
*/
/**************************************************************************/
float Adafruit_CircuitPlayground::motionY(void) {
  sensors_event_t event;
  CircuitPlayground.lis.getEvent(&event);
  return event.acceleration.y;
}

/**************************************************************************/
/*!
    @brief read the Z parameter of the onboard accelerometer. Value returned is
     defined by setAccelRange().
    @returns the Z value of the onboard accelerometer
*/
/**************************************************************************/
float Adafruit_CircuitPlayground::motionZ(void) {
  sensors_event_t event;
  CircuitPlayground.lis.getEvent(&event);
  return event.acceleration.z;
}

/**************************************************************************/
/*!
    @brief read the onboard thermistor.
    @returns temperature reading in Centigrade.
*/
/**************************************************************************/
float Adafruit_CircuitPlayground::temperature(void) {
   // Thermistor test
  double reading;
  reading = analogRead(CPLAY_THERMISTORPIN);

  //Serial.print("Thermistor reading: "); Serial.println(reading);

  // convert the value to resistance
  reading = ((1023.0 * SERIESRESISTOR) / reading);
  reading -= SERIESRESISTOR;

  //Serial.print("Thermistor resistance: "); Serial.println(reading);

  double steinhart;
  steinhart = reading / THERMISTORNOMINAL;     // (R/Ro)
  steinhart = log(steinhart);                  // ln(R/Ro)
  steinhart /= BCOEFFICIENT;                   // 1/B * ln(R/Ro)
  steinhart += 1.0 / (TEMPERATURENOMINAL + 273.15); // + (1/To)
  steinhart = 1.0 / steinhart;                 // Invert
  steinhart -= 273.15;                         // convert to C

  return steinhart;
}

/**************************************************************************/
/*!
    @brief read the onboard thermistor.
    @returns temperature reading in Farenheight.
*/
/**************************************************************************/
float Adafruit_CircuitPlayground::temperatureF(void) {
  float tempF = CircuitPlayground.temperature() * 1.8 + 32;
  return tempF;
}

/**************************************************************************/
/*!
    @brief get a color value from the color wheel.
    @param WheelPos a value 0 to 255
    @returns a color value. The colours are a transition r - g - b - back to r.
*/
/**************************************************************************/
uint32_t Adafruit_CircuitPlayground::colorWheel(uint8_t WheelPos) {
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if (WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

/**************************************************************************/
/*!
    @brief detect a color value from the light sensor
    @param red the pointer to where the red component should be stored.
    @param green the pointer to where the green component should be stored.
    @param blue the pointer to where the blue component should be stored.
*/
/**************************************************************************/
void Adafruit_CircuitPlayground::senseColor(uint8_t& red, uint8_t& green, uint8_t& blue) {
  // Save the current pixel brightness so it can later be restored.  Then bump
  // the brightness to max to make sure the LED is as bright as possible for
  // the color readings.
  uint8_t old_brightness = strip.getBrightness();
  strip.setBrightness(255);
  // Set pixel 1 (next to the light sensor) to full red, green, blue
  // color and grab a light sensor reading.  Make sure to wait a bit
  // after changing pixel colors to let the light sensor change
  // resistance!
  setPixelColor(1, 255, 0, 0);  // Red
  delay(LIGHT_SETTLE_MS);
  uint16_t raw_red = lightSensor();
  setPixelColor(1, 0, 255, 0);  // Green
  delay(LIGHT_SETTLE_MS);
  uint16_t raw_green = lightSensor();
  setPixelColor(1, 0, 0, 255);  // Blue
  delay(LIGHT_SETTLE_MS);
  uint16_t raw_blue = lightSensor();
  // Turn off the pixel and restore brightness, we're done with readings.
  setPixelColor(1, 0);
  strip.setBrightness(old_brightness);
  // Now scale down each of the raw readings to be within
  // 0 to 255.  Remember each sensor reading is from the ADC
  // which has 10 bits of resolution (0 to 1023), so dividing
  // by 4 will change the range from 0-1023 to 0-255.  Also
  // use the min function to clamp the value to 255 at most (just
  // to prevent overflow from 255.xx to 0).
  red = min(255, raw_red/4);
  green = min(255, raw_green/4);
  blue = min(255, raw_blue/4);
}

/**************************************************************************/
/*!
    @brief check whether or not this device is a CircuitPlayground Express.
    @returns True if the device is a CircuitPlayground Express, false if it is a 'classic'.
*/
/**************************************************************************/
bool Adafruit_CircuitPlayground::isExpress(void) {
#ifdef __AVR__
  return false;
#else
  return true;
#endif
}

// instantiate static
Adafruit_CircuitPlayground CircuitPlayground;
