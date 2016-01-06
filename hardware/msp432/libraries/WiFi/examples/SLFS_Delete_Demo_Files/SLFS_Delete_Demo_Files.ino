/* Energia SLFS demo: SLFS Delete Demo Files
 *
 * This demonstration illustrates the use of the SerFlash.del() API call for
 * deleting files.  In here, we delete all files that have been referenced by
 * the other demos that ship with this library, showing the return value and
 * error string.
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
  
  SerFlash.begin();
  
  int32_t retval = SerFlash.del("/binfile/myfile.bin");
  Serial.print("Deleting /binfile/myfile.bin return code: ");
  Serial.println(SerFlash.lastErrorString());
  
  retval = SerFlash.del("/storage/mine.txt");
  Serial.print("Deleting /storage/mine.txt return code: ");
  Serial.println(SerFlash.lastErrorString());
  
  Serial.println("Halting; reset the MCU if you want to run this again.");
  Serial.flush();  // flush pending serial output before going into suspend()
  while(1) ;  // halting (suspend() isn't support by Energia MT at the moment FYI)
}

void loop()
{
  // put your main code here, to run repeatedly:
}
