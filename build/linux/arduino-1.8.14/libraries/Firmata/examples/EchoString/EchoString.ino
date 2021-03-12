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

/* This sketch accepts strings and raw sysex messages and echos them back.
 *
 * This example code is in the public domain.
 */
#include <Firmata.h>

void stringCallback(char *myString)
{
  Firmata.sendString(myString);
}


void sysexCallback(byte command, byte argc, byte *argv)
{
  Firmata.sendSysex(command, argc, argv);
}

void setup()
{
  Firmata.setFirmwareVersion(FIRMATA_FIRMWARE_MAJOR_VERSION, FIRMATA_FIRMWARE_MINOR_VERSION);
  Firmata.attach(STRING_DATA, stringCallback);
  Firmata.attach(START_SYSEX, sysexCallback);
  Firmata.begin(57600);
}

void loop()
{
  while (Firmata.available()) {
    Firmata.processInput();
  }
}


