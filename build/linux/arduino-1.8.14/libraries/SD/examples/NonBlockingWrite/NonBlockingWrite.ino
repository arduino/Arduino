/*
  Non-blocking Write

  This example demonstrates how to perform non-blocking writes
  to a file on a SD card. The file will contain the current millis()
  value every 10ms. If the SD card is busy, the data will be buffered
  in order to not block the sketch.

  NOTE: myFile.availableForWrite() will automatically sync the
        file contents as needed. You may lose some unsynced data
        still if myFile.sync() or myFile.close() is not called.

  The circuit:
  - Arduino MKR Zero board
  - micro SD card attached

  This example code is in the public domain.
*/

#include <SD.h>

// file name to use for writing
const char filename[] = "demo.txt";

// File object to represent file
File txtFile;

// string to buffer output
String buffer;

unsigned long lastMillis = 0;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  // reserve 1kB for String used as a buffer
  buffer.reserve(1024);

  // set LED pin to output, used to blink when writing
  pinMode(LED_BUILTIN, OUTPUT);

  // init the SD card
  if (!SD.begin()) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    while (1);
  }

  // If you want to start from an empty file,
  // uncomment the next line:
  // SD.remove(filename);

  // try to open the file for writing
  txtFile = SD.open(filename, FILE_WRITE);
  if (!txtFile) {
    Serial.print("error opening ");
    Serial.println(filename);
    while (1);
  }

  // add some new lines to start
  txtFile.println();
  txtFile.println("Hello World!");
}

void loop() {
  // check if it's been over 10 ms since the last line added
  unsigned long now = millis();
  if ((now - lastMillis) >= 10) {
    // add a new line to the buffer
    buffer += "Hello ";
    buffer += now;
    buffer += "\r\n";

    lastMillis = now;
  }

  // check if the SD card is available to write data without blocking
  // and if the buffered data is enough for the full chunk size
  unsigned int chunkSize = txtFile.availableForWrite();
  if (chunkSize && buffer.length() >= chunkSize) {
    // write to file and blink LED
    digitalWrite(LED_BUILTIN, HIGH);
    txtFile.write(buffer.c_str(), chunkSize);
    digitalWrite(LED_BUILTIN, LOW);

    // remove written data from buffer
    buffer.remove(0, chunkSize);
  }
}
