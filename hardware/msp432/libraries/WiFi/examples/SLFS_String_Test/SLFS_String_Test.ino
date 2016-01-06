/* Energia SLFS example: SLFS String Test
 *
 * This example illustrates how to initialize the SerFlash object (representing a handle
 * into the SimpleLink Serial Flash Filesystem) and use it to write contents to a file using
 * the "String" datatype, then read it back as another String.  Illustrated in the loop() is the
 * fact that when a user uses SerFlash.readBytes() to return a String, they can optionally "free"
 * the library's internal String buffer to reduce memory usage.  Strictly speaking, no memory
 * leaks will occur if the user frequently utilizes SerFlash.readBytes() without running
 * SerFlash.freeString() though.
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
    // Create our String object with our message
    String s("Hi there, this is a String object.");
    s += " ... with an appendage.";

    // Write our String object to the file!    
    SerFlash.write(s);
    SerFlash.close();
  } else {
    // retval did not return SL_FS_OK, there must be an error!
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
  
  String s = SerFlash.readBytes();
  Serial.print("Read ");
  Serial.print(s.length());
  Serial.println(" bytes from /storage/mine.txt - contents:");
  Serial.println(s);
  SerFlash.close();
  SerFlash.freeString();  // Free up memory used by the last "String" produced by SerFlash.readBytes()
  // ^ This is optional, if it's not used, the built-in buffer will stick around but if the user attempts
  // to run SerFlash.readBytes() again, the old buffer will be free'd automatically before a new buffer is
  // created.  So it's not strictly necessary but can help with tight memory footprints.
  
  delay(2000);  // Pause 2 seconds
  // ... then do it again :-)
}
