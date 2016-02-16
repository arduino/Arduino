/*************************************************** 
  This is an example for the TMP007 Barometric Pressure & Temp Sensor

  Designed specifically to work with the Adafruit TMP007 Breakout 
  ----> https://www.adafruit.com/products/2023
  
  These displays use I2C to communicate, 2 pins are required to  
  interface
  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#include <Wire.h>
#include "Adafruit_TMP007.h"

// Connect VCC to +3V (its a quieter supply than the 5V supply on an Arduino
// Gnd -> Gnd
// SCL connects to the I2C clock pin. On newer boards this is labeled with SCL
// otherwise, on the Uno, this is A5 on the Mega it is 21 and on the Leonardo/Micro digital 3
// SDA connects to the I2C data pin. On newer boards this is labeled with SDA
// otherwise, on the Uno, this is A4 on the Mega it is 20 and on the Leonardo/Micro digital 2

Adafruit_TMP007 tmp007;
//Adafruit_TMP007 tmp007(0x41);  // start with a diferent i2c address!

void setup() { 
  Serial.begin(9600);
  Serial.println("Adafruit TMP007 example");

  // you can also use tmp007.begin(TMP007_CFG_1SAMPLE) or 2SAMPLE/4SAMPLE/8SAMPLE to have
  // lower precision, higher rate sampling. default is TMP007_CFG_16SAMPLE which takes
  // 4 seconds per reading (16 samples)
  if (! tmp007.begin()) {
    Serial.println("No sensor found");
    while (1);
  }
}

void loop() {
   float objt = tmp007.readObjTempC();
   Serial.print("Object Temperature: "); Serial.print(objt); Serial.println("*C");
   float diet = tmp007.readDieTempC();
   Serial.print("Die Temperature: "); Serial.print(diet); Serial.println("*C");
   
   delay(4000); // 4 seconds per reading for 16 samples per reading
}