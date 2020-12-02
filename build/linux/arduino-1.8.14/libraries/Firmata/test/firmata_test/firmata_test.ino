/*
 * To run this test suite, you must first install the ArduinoUnit library
 * to your Arduino/libraries/ directory.
 * You can get ArduinoUnit here: https://github.com/mmurdoch/arduinounit
 * Download version 2.0 or greater or install it via the Arduino library manager.
 */

#include <ArduinoUnit.h>
#include <Firmata.h>

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Test::run();
}

test(beginPrintsVersion)
{
  FakeStream stream;

  Firmata.begin(stream);

  char expected[] = {
    REPORT_VERSION,
    FIRMATA_PROTOCOL_MAJOR_VERSION,
    FIRMATA_PROTOCOL_MINOR_VERSION,
    0
  };
  assertEqual(expected, stream.bytesWritten());
}

void processMessage(const byte *message, size_t length)
{
  FakeStream stream;
  Firmata.begin(stream);

  for (size_t i = 0; i < length; i++) {
    stream.nextByte(message[i]);
    Firmata.processInput();
  }
}

byte _digitalPort;
int _digitalPortValue;
void writeToDigitalPort(byte port, int value)
{
  _digitalPort = port;
  _digitalPortValue = value;
}

void setupDigitalPort()
{
  _digitalPort = 0;
  _digitalPortValue = 0;
}

char * _receivedString;
void handleStringCallback(char *str)
{
  _receivedString = str;
}

test(processWriteDigital_0)
{
  setupDigitalPort();
  Firmata.attach(DIGITAL_MESSAGE, writeToDigitalPort);

  byte message[] = { DIGITAL_MESSAGE, 0, 0 };
  processMessage(message, 3);

  assertEqual(0, _digitalPortValue);
}

test(processWriteDigital_127)
{
  setupDigitalPort();
  Firmata.attach(DIGITAL_MESSAGE, writeToDigitalPort);

  byte message[] = { DIGITAL_MESSAGE, 127, 0 };
  processMessage(message, 3);

  assertEqual(127, _digitalPortValue);
}

test(processWriteDigital_128)
{
  setupDigitalPort();
  Firmata.attach(DIGITAL_MESSAGE, writeToDigitalPort);

  byte message[] = { DIGITAL_MESSAGE, 0, 1 };
  processMessage(message, 3);

  assertEqual(128, _digitalPortValue);
}

test(processWriteLargestDigitalValue)
{
  setupDigitalPort();
  Firmata.attach(DIGITAL_MESSAGE, writeToDigitalPort);

  byte message[] = { DIGITAL_MESSAGE, 0x7F, 0x7F };
  processMessage(message, 3);

  // Maximum of 14 bits can be set (B0011111111111111)
  assertEqual(0x3FFF, _digitalPortValue);
}

test(defaultDigitalWritePortIsZero)
{
  setupDigitalPort();
  Firmata.attach(DIGITAL_MESSAGE, writeToDigitalPort);

  byte message[] = { DIGITAL_MESSAGE, 0, 0 };
  processMessage(message, 3);

  assertEqual(0, _digitalPort);
}

test(specifiedDigitalWritePort)
{
  setupDigitalPort();
  Firmata.attach(DIGITAL_MESSAGE, writeToDigitalPort);

  byte message[] = { DIGITAL_MESSAGE + 1, 0, 0 };
  processMessage(message, 3);

  assertEqual(1, _digitalPort);
}

test(setFirmwareVersionDoesNotLeakMemory)
{
  Firmata.setFirmwareVersion(1, 0);
  int initialMemory = freeMemory();

  Firmata.setFirmwareVersion(1, 0);

  assertEqual(0, initialMemory - freeMemory());
}

test(sendStringShouldEncode2BytesPerChar)
{
  FakeStream stream;
  Firmata.begin(stream);
  // reset the buffer because the firmware name string will be sent on Firmata.begin
  stream.reset();

  char testString[] = "hi!";
  Firmata.sendString(testString);

  byte expected[] = { START_SYSEX, STRING_DATA, 'h', 0, 'i', 0, '!', 0, END_SYSEX };

  int len = stream.bytesWritten().length();
  assertEqual(sizeof(expected), len);
  for (byte i = 0; i < len; i++) {
    assertEqual(expected[i], (byte)stream.bytesWritten().charAt(i));
  }
}

test(receivedStringShouldDecodeFrom2BytesPerChar)
{
  Firmata.attach(STRING_DATA, handleStringCallback);

  byte message[] = { START_SYSEX, STRING_DATA, 'b', 0, 'y', 0, 'e', 0, '!', 0, END_SYSEX };
  processMessage(message, 11);

  assertEqual("bye!", _receivedString);
}

