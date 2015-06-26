
/*
 Infrared temp sensor TMP006 example for Educational BoosterPack MK II
 http://boosterpackdepot.info/wiki/index.php?title=Educational_BoosterPack_MK_II
 

Modified 03 Dec 2013
by Dung Dang

This example code is in the public domain.
*/
#include <Wire.h>
#include "Adafruit_TMP006.h"
#define USE_USCI_B1 

Adafruit_TMP006 tmp006;
void printFloat(float value, int places) ;

void setup()
{
  Serial.begin(115200);

  // Initalizes the TMP006 for operation and for I2C communication
  if (! tmp006.begin(TMP006_CFG_8SAMPLE)) {
    Serial.println("No sensor found");
    while (1);
  }
}

void loop()
{
  float objt = tmp006.readObjTempC();
  Serial.print("Object Temperature: "); Serial.print(objt); Serial.println("*C");
  float diet = tmp006.readDieTempC();
  Serial.print("Die Temperature: "); Serial.print(diet); Serial.println("*C");
   
  delay(1000); // 4 seconds per reading for 16 samples per reading
}
