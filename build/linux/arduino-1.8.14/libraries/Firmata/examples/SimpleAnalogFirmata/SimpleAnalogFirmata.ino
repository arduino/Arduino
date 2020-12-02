/*
 * Firmata is a generic protocol for communicating with microcontrollers
 * from software on a host computer. It is intended to work with
 * any host computer software package.
 *
 * To download a host software package, please click on the following link
 * to open the list of Firmata client libraries in your default browser.
 *
 * https://github.com/firmata/arduino#firmata-client-libraries
 */

/* Supports as many analog inputs and analog PWM outputs as possible.
 *
 * This example code is in the public domain.
 */
#include <Firmata.h>

byte analogPin = 0;

void analogWriteCallback(byte pin, int value)
{
  if (IS_PIN_PWM(pin)) {
    pinMode(PIN_TO_DIGITAL(pin), OUTPUT);
    analogWrite(PIN_TO_PWM(pin), value);
  }
}

void setup()
{
  Firmata.setFirmwareVersion(FIRMATA_FIRMWARE_MAJOR_VERSION, FIRMATA_FIRMWARE_MINOR_VERSION);
  Firmata.attach(ANALOG_MESSAGE, analogWriteCallback);
  Firmata.begin(57600);
}

void loop()
{
  while (Firmata.available()) {
    Firmata.processInput();
  }
  // do one analogRead per loop, so if PC is sending a lot of
  // analog write messages, we will only delay 1 analogRead
  Firmata.sendAnalog(analogPin, analogRead(analogPin));
  analogPin = analogPin + 1;
  if (analogPin >= TOTAL_ANALOG_PINS) analogPin = 0;
}

