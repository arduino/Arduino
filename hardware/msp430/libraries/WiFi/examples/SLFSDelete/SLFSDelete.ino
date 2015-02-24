/* SLFSDelete.ino
 *
 * Simple demo showcasing the SLFS library which provides a "SerFlash" Stream interface
 * for reading, writing & deleting files on the Serial Flash filesystem housed within the CC3200 MCU
 * and CC3100 Network Wireless Processor's boards.
 *
 * This demo deletes the file created by the "SLFSTextFile" example.
 * It then tries to read back the file, proving that it was deleted.
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
  Serial.println("CC3200/CC3100 SLFS Serial Flash DELETE demo.");
  Serial.println("This demo expects that you've run the \"SLFSTextFile\" example once already.");

  SerFlash.begin();  // This actually calls WiFi.init() btw

  Serial.print("Deleting /storage/mine.txt- ");
  int retval = SerFlash.del("/storage/mine.txt");
  if (retval == false) {
    Serial.println("There was an ERROR deleting /storage/mine.txt");
  } else {
    Serial.println("Successfully deleted.");
  }
}

void loop()
{
  // Open "/storage/mine.txt" and read its contents to the serial monitor.
  if (SerFlash.open("/storage/mine.txt", FS_MODE_OPEN_READ) == false) {
    // Some sort of error occurred!
    Serial.println("ERROR opening /storage/mine.txt! (Either it didn't exist, or it was successfully deleted!)");
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
    Serial.println("There was an error reading from the /storage/mine.txt file!");
  }

  // Halt program.
  while(1) delay(1000);
}
