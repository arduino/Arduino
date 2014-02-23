
/*
 Infrared temp sensor TMP006 example for Educational BoosterPack MK II
 http://boosterpackdepot.info/wiki/index.php?title=Educational_BoosterPack_MK_II
 

Modified 03 Dec 2013
by Dung Dang

This example code is in the public domain.
*/

// Code is currently using printFloat() to print temperature result in Float
// Once fixed point library is polished, example can be updated.

#include <Wire.h>
#include "tmp006.h"
#define USE_USCI_B1 

tmp006 tmp006;
void printFloat(float value, int places) ;

void setup()
{ // Initializes the TMP006 for operation and for I2C communication
  tmp006.begin(EIGHT_SAMPLES);  // Takes 8 averaged samples for measurement
  Serial.begin(115200);
}
float temp;
void loop()
{
  temp = tmp006.getTemp();

  Serial.print("Temp in C = ");
  Serial.print(temp);
  Serial.println(" deg. C");
  delay(1000);
}




