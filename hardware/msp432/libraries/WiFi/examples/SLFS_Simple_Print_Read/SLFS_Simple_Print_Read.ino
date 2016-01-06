/* Energia SLFS example: SLFS Simple Print Read
 *
 * This example illustrates how to initialize the SerFlash object (representing a handle
 * into the SimpleLink Serial Flash Filesystem) and use it to write contents to a file, then
 * read it back.  This file will stick across multiple resets, power-cycles and even re-flashing
 * of sketches or code.  The only way to delete the file is using the SerFlash.del() function
 * call or using a CCS Uniflash utility to reformat or modify the SimpleLink Flash Filesystem.
 *
 * Complexity: low
 */
 
#include <SPI.h>
#include <WiFi.h>
#include <SLFS.h>


void setup()
{
  // put your setup code here, to run once:
  
  Serial.begin(115200);
  delay(1000);
  Serial.println("CC3200/CC3100 SLFS Serial Flash demo.");
  
  SerFlash.begin();  // This calls WiFi.init() in case the user hasn't already run WiFi.begin()
  
  Serial.println("Writing some text to /storage/mine.txt-");
  // Create a file "/storage/mine.txt"  
  int32_t retval = SerFlash.open("/storage/mine.txt",
    FS_MODE_OPEN_CREATE(512, _FS_FILE_OPEN_FLAG_COMMIT));
  if (retval == SL_FS_OK) {
    SerFlash.println("Hi there, this is my file!");
    SerFlash.close();
  } else {
    Serial.print("Error opening /storage/mine.txt, error code: ");
    Serial.println(SerFlash.lastErrorString());
    Serial.flush();  // flush pending serial output before entering suspend()
    while(1) ;  // halting (suspend() isn't support by Energia MT at the moment FYI)
  }
}

void loop()
{
  // Open "/storage/mine.txt" and read its contents, print to serial monitor-
  SerFlash.open("/storage/mine.txt", FS_MODE_OPEN_READ);
  char buf[1024];
  
  buf[0] = '\0';  // Init buf in case readBytes doesn't actually do anything (and returns 0)
  size_t read_length = SerFlash.readBytes(buf, 1023);
  Serial.print("Read ");
  Serial.print(read_length);
  Serial.println(" bytes from /storage/mine.txt - contents:");
  Serial.println(buf);
  SerFlash.close();
  
  delay(10000);  // Pause 10 seconds
  // ... then do it again :-)
}
