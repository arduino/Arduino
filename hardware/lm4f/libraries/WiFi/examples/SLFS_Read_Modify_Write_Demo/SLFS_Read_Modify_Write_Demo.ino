/* Energia SLFS example: SLFS Read Modify Write Demo
 *
 * This example successfully writes an array of 32-bit integers, then successfully modifies
 * the first entry over and over in a loop, demonstrating how to perform an in-memory
 * Read-Modify-Write using malloc() and free() to manage an in-RAM buffer sized appropriately
 * to store the entire contents of the file.
 *
 * This is risky business especially with large files, so keep that in mind.  Another method
 * for modifying a file would be to read-modify-write to a second file using a small RAM buffer,
 * then read-write the second file back to the first file.  That's cumbersome, and if you have
 * enough RAM to hold the file's contents, doing an in-memory Read-Modify-Write is simpler.
 *
 * Complexity: high
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
  int i=0;
  int32_t retval;
  uint32_t a, *dary;
  static uint32_t my_int = 0;

  Serial.println("Opening /binfile/myfile.bin and examining contents-");
  retval = SerFlash.open("/binfile/myfile.bin", FS_MODE_OPEN_READ);
  if (retval != SL_FS_OK) {
    Serial.print("Error opening /binfile/myfile.bin for reading, error code: ");
    Serial.println(SerFlash.lastErrorString());
    Serial.flush();  // flush pending serial output before entering suspend()
    while(1) ;  // halting (suspend() isn't support by Energia MT at the moment FYI)
  }
  
  size_t read_len = SerFlash.size();
  Serial.print("File size: ");
  Serial.println(read_len);
  
  while ( (retval = SerFlash.readBytes(&a, sizeof(uint32_t))) > 0 ) {
    Serial.print("Index#");
    Serial.print(i++);
    Serial.print(" - ");
    Serial.println(a);
  }
  SerFlash.close();

  // Compute a new value for "my_int"
  my_int += 500;
  Serial.print("Modifying integer at index# 0 to a new value, performing a read-modify-write in the process: ");
  Serial.println(my_int);

  retval = SerFlash.open("/binfile/myfile.bin", FS_MODE_OPEN_READ);
  if (retval != SL_FS_OK) {
    Serial.print("Error opening /binfile/myfile.bin for reading, error code: ");
    Serial.println(SerFlash.lastErrorString());
    Serial.flush();  // flush pending serial output before entering suspend()
    while(1) ;  // halting (suspend() isn't support by Energia MT at the moment FYI)
  }
  
  read_len = SerFlash.size();

  // Use malloc() to create a RAM buffer appropriately sized to hold the present contents of this file.
  dary = (uint32_t *) malloc(read_len);  // cast to (uint32_t *) since dary is a pointer to an array of type uint32_t.

  // Read contents of the file into dary[]:
  for (i=0; i < (read_len / sizeof(uint32_t)); i++) {
    retval = SerFlash.readBytes(&dary[i], sizeof(uint32_t));
    if (retval <= 0) {
      Serial.print("Error reading from /binfile/myfile.bin, error code: ");
      Serial.println(SerFlash.lastErrorString());
      Serial.flush();  // flush pending serial output before entering suspend()
      while(1) ;  // halting (suspend() isn't support by Energia MT at the moment FYI)
    }
  }
  SerFlash.close();
  
  // Contents now stored in dary[].  Modify the contents of array index#0 to reflect the value of "my_int".
  dary[0] = my_int;
  
  // Great!  Now store the contents into the same file, re-creating it (thus overwriting).
  retval = SerFlash.open("/binfile/myfile.bin", FS_MODE_OPEN_CREATE(128, _FS_FILE_OPEN_FLAG_COMMIT));
  if (retval != SL_FS_OK) {
    Serial.print("Error creating file /binfile/myfile.bin, error code: ");
    Serial.println(SerFlash.lastErrorString());
    Serial.flush();  // flush pending serial output before entering suspend()
    while(1) ;  // halting (suspend() isn't support by Energia MT at the moment FYI)
  }

  // File created; write contents.
  for (i=0; i < (read_len / sizeof(uint32_t)); i++) {
    SerFlash.write(&dary[i], sizeof(uint32_t));
  }

  SerFlash.close();

  // All done!  Free the malloc'd buffer pointed to by dary[] so we don't end up with a memory leak.
  free(dary);
  
  Serial.println("File successfully re-written.  Looping in 3 seconds to read the contents...");
  delay(3000);
}
