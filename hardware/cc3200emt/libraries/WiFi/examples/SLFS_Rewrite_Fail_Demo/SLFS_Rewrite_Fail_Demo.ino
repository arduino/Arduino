/* Energia SLFS example: SLFS Rewrite Fail Demo
 *
 * This example illustrates how with the SimpleLink Flash FS, "rewriting" specific contents of a file
 * is not possible.  The only way to re-write files is to first delete them, then re-create them with
 * new contents.
 *
 * Here we only demonstrate that opening a previously-written file for "write" mode just doesn't work.
 *
 * Complexity: medium
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
  
  Serial.println("Creating a binary file with 32-bit integers binary packed:");
  // Create a file /binfile/myfile.bin
  int32_t retval = SerFlash.open("/binfile/myfile.bin",
    FS_MODE_OPEN_CREATE(128, _FS_FILE_OPEN_FLAG_COMMIT));
  if (retval != SL_FS_OK) {
    Serial.print("Error creating file /binfile/myfile.bin, error code: ");
    Serial.println(SerFlash.lastErrorString());
    Serial.flush();  // flush pending serial output before entering suspend()
    while(1) ;  // halting (suspend() isn't support by Energia MT at the moment FYI)
  }
  
  uint32_t my_array[8];
  for (int i=0; i < 8; i++) {
    my_array[i] = 200 + i;
  }
  SerFlash.write(my_array, sizeof(my_array));  // Write all 8 32-bit integers into the file in
                                               // native 32-bit binary format.
  SerFlash.close();
}

void loop()
{
  // put your main code here, to run repeatedly:
  int i;
  uint32_t array[8];
  static uint32_t my_int = 0;

  Serial.println("Opening /binfile/myfile.bin and examining contents (8 32-bit integers):");
  SerFlash.open("/binfile/myfile.bin", FS_MODE_OPEN_READ);
  size_t read_len = SerFlash.readBytes(array, sizeof(array));
  if (read_len != sizeof(array)) {
    Serial.print("Error: Unable to read ");
    Serial.print(sizeof(array));
    Serial.println(" bytes from our file as expected...");
  } else {
    for (i=0; i < 8; i++) {
      Serial.print("Integer at index#");
      Serial.print(i);
      Serial.print(": ");
      Serial.println(array[i]);
    }
  }
  
  // Compute a new value for "my_int"
  my_int += 500;
  Serial.print("Modifying integer at index# 0 to a new value: ");
  Serial.println(my_int);
  
  SerFlash.open("/binfile/myfile.bin", FS_MODE_OPEN_WRITE);
  // Upon open()'ing a file, the file pointer implicitly starts at position 0, which should represent the
  // contents of our 32-bit integer array at index == 0.
  SerFlash.write(&my_int, sizeof(my_int));  // Rewrite index#0 with my_int
  SerFlash.close();
  Serial.println("In a couple seconds, we will re-read the file's contents and update index#0 again...");
  delay(3000);
  // Loop around to re-read the file contents - As you will see, the contents don't update!
}
