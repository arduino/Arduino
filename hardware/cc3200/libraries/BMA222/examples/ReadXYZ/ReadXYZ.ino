#include <Wire.h>
#include <BMA222.h>

BMA222 mySensor;

void setup()
{
  Serial.begin(115200);
  
  mySensor.begin();
  uint8_t chipID = mySensor.chipID();
  Serial.print("chipID: ");
  Serial.println(chipID);
}

void loop()
{
  int8_t data = mySensor.readXData();
  Serial.print("X: ");
  Serial.print(data);

  data = mySensor.readYData();
  Serial.print(" Y: ");
  Serial.print(data);

  data = mySensor.readZData();
  Serial.print(" Z: ");
  Serial.println(data);

  delay(10);
}
