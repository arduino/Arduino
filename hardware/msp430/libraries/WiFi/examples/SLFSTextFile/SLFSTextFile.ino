/* SLFSTextFile.ino
 *
 * Simple demo showcasing the SLFS library which provides a "SerFlash" Stream interface
 * for reading, writing & deleting files on the Serial Flash filesystem housed within the CC3200 MCU
 * and CC3100 Network Wireless Processor's boards.
 *
 * Please note this Serial Flash filesystem only supports up to 128 files (including system files
 * already present, such as CC3100 firmware and CC3200 MCU code).
 *
 * When you create a file in the Serial Flash, the maximum size must be declared with the
 * _FS_MODE_OPEN_CREATE() macro.  Whenever this file is opened for WRITE mode, its contents is
 * first ERASED in its entirety.  It's very important to recognize this - you cannot "APPEND" to
 * an SLFS file, only re-write it.
 */

#ifndef __CC3200R1M1RGC__
// Do not include SPI for CC3200 LaunchPad
#include <SPI.h>
#endif
#include <WiFi.h>
#include <SLFS.h>

void setup()
{
  Serial.begin(115200);
  delay(1000);
  Serial.println("CC3200/CC3100 SLFS Serial Flash demo.");

  SerFlash.begin();  // This actually calls WiFi.init() btw

  Serial.println("Creating /storage/mine.txt and writing some text-");

  // Create a file "/storage/mine.txt", max size 512 bytes.
  if (SerFlash.open("/storage/mine.txt",
      FS_MODE_OPEN_CREATE(512, _FS_FILE_OPEN_FLAG_COMMIT)) != SL_FS_OK) {
    Serial.print("ERROR creating /storage/mine.txt!  Error code: ");
    Serial.println(SerFlash.lastErrorString());  // Report meaning of last SLFS API failure

    Serial.println("Halting.");
    while(1) delay(1000);  // Infinite loop to stop the program
  }

  // Write text to the file-
  SerFlash.println("Hi there, this is my file!");
  // ^ This writes: Hi there, this is my file!\r\n
  // with the CR-LF at the end because we used "println" rather than "print".
  // When reading this back to the serial console, we will only need to
  // use Serial.print() on the buffer, not Serial.println().

  SerFlash.close();  // Close filehandle (in preparation for reading later)
}

void loop()
{
  // Open "/storage/mine.txt" and read its contents to the serial monitor.
  if (SerFlash.open("/storage/mine.txt", FS_MODE_OPEN_READ) != SL_FS_OK) {
    // Some sort of error occurred!
    Serial.print("ERROR opening /storage/mine.txt!  Error code: ");
    Serial.println(SerFlash.lastErrorString());
    Serial.println("Halting.");
    while (1) delay(1000);  // Infinite loop to stop the program
  }

  char buf[1024];  // our RAM buffer to house the file's contents

  size_t read_size = SerFlash.readBytes(buf, 1023);
  if (read_size >= 0) {
    buf[read_size] = '\0';  // NUL-terminate the buffer before treating it as a string!
    Serial.print("Read ");
      Serial.print(read_size);
      Serial.println(" bytes from /storage/mine.txt - displaying contents:");

      Serial.print(buf);

      SerFlash.close();
  } else {
    Serial.print("There was an error reading from the /storage/mine.txt file! Error code: ");
    Serial.println(SerFlash.lastErrorString());
  }

  delay(10000);  // Pause 10 seconds
  // ... then do it all again :-)
}
