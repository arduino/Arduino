/*OPT3001_Demo Example
In this example, we will read the various registers available in the OPT3001.
The LUX readings from the OPT3001 are also shown in the Energia serial monitor.


Created by Adrian Fernandez & Dung Dang, Dec 2013
Released to public domain.
*/

#include <Wire.h>			// Needed by Energia for Tiva C LaunchPad 
#include "OPT3001.h"
#define USE_USCI_B1 

opt3001 opt3001;

void setup()
{
  unsigned int readings = 0;
  
  Serial.begin(115200);
  delay(1000);
  
  opt3001.begin(); 
  
  Serial.println("OPT3001 Initialized----------------------------------");
  
  // get manufacturer ID from OPT3001. Default = 0101010001001001
  readings = opt3001.readManufacturerId();  
  Serial.print("Manufacturer ID: "); 
  Serial.println(readings, BIN);

  // get device ID from OPT3001. Default = 0011000000000001
  readings = opt3001.readDeviceId();  
  Serial.print("Device ID: "); 
  Serial.println(readings, BIN);
  
  // read config register from OPT3001. Default = 1100110000010000
  readings = opt3001.readConfigReg();  
  Serial.print("Configuration Register: "); 
  Serial.println(readings, BIN);

  // read Low Limit register from OPT3001. Default = 0000000000000000
  readings = opt3001.readLowLimitReg();  
  Serial.print("Low Limit Register: "); 
  Serial.println(readings, BIN);
  
  // read High Limit register from OPT3001. Default = 1011111111111111
  readings = opt3001.readHighLimitReg();  
  Serial.print("High Limit Register: "); 
  Serial.println(readings, BIN);    
  
  Serial.println("\nOPT3001 READINGS-------------------------------------");
}

void loop()
{
  // Variables
  uint32_t readings;
     
  // Read OPT3001
  readings = opt3001.readResult();  
  
  Serial.print("LUX Readings = ");
  Serial.println(readings, DEC);
 
  delay(800);
}

