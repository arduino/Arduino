/* Energia SLFS example: SLFS Append Fail
 *
 * This example demonstrates another thing that "fails" in the SimpleLink Filesystem-
 * Appending to a file.  Technically you can write to a file that was already created,
 * and extend its size up to the max size specified during file creation, however every
 * time the file is opened for WRITE, the previous contents are erased!!
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
  SerFlash.del("/binfile/myfile.bin");
  
  Serial.println("Creating a binary file with 32-bit integers binary packed:");
  // Create a file /binfile/myfile.bin
  int32_t retval = SerFlash.open("/binfile/myfile.bin",
    FS_MODE_OPEN_CREATE(3072, _FS_FILE_OPEN_FLAG_COMMIT));
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
  int32_t retval;
  uint32_t a;
  static uint32_t my_int = 0;

  Serial.println("Opening /binfile/myfile.bin and listing all integers-");
  retval = SerFlash.open("/binfile/myfile.bin", FS_MODE_OPEN_READ);
  if (retval != SL_FS_OK) {
    Serial.print("Error opening /binfile/myfile.bin for reading; error code: ");
    Serial.println(SerFlash.lastErrorString());
    Serial.flush();  // flush pending serial output before entering suspend()
    while(1) ;  // halting (suspend() isn't support by Energia MT at the moment FYI)
  }
  Serial.print("File size: ");
  Serial.println(SerFlash.size());

  i = 0;
  do {
    retval = SerFlash.readBytes(&a, sizeof(a));
    Serial.print("Index#");
    Serial.print(i++);
    Serial.print(" - ");
    Serial.println(a);
  } while (retval == sizeof(a));

  SerFlash.close();  // Close read-mode

  // Compute a new value for "my_int"
  my_int += 500;
  Serial.print("Appending integer value ");
  Serial.print(my_int);
  Serial.println(" to file /binfile/myfile.bin-");
  
  // Try writing it to the end of /binfile/myfile.bin...
  retval = SerFlash.open("/binfile/myfile.bin", FS_MODE_OPEN_WRITE);
  if (retval != SL_FS_OK) {
    Serial.print("SerFlash.open: ");
    Serial.println(SerFlash.lastErrorString());
  }

  // Upon open()'ing a file, the file pointer implicitly starts at position 0, we want to append to the end.
  SerFlash.seek(i * sizeof(uint32_t));
  retval = SerFlash.write(&my_int, sizeof(my_int));  // Rewrite index#0 with my_int
  if (retval == 0) {  // SerFlash.write and SerFlash.read, SerFlash.readBytes all return > 0 for normal conditions,
                      // and 0 if there is either an error or the length argument provided is 0.
    Serial.print("SerFlash.write: ");
    Serial.println(SerFlash.lastError());
  }
  retval = SerFlash.close();
  if (retval != SL_FS_OK) {
    Serial.print("SerFlash.close: ");
    Serial.println(SerFlash.lastErrorString());
  }

  Serial.println("In a couple seconds, we will re-read the file's contents...");
  delay(2000);
}
