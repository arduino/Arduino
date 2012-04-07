//
//  I2C_Thermometer
//
//  © Rei VILO 2012
// 
//  PUSH2 on pin 5
//
//  Uses I2C thermometer 
//  Texas Instrument TMP102 with strap ADDR0 - SCL
//
//  Press push 2 to end
//
//  Tested on msp430g2452
//  Binary sketch size = 6884 bytes out of 8192 bytes
//

#include "Wire.h"
#include "TimerSerial.h"

TimerSerial mySerial;
const uint8_t PUSH2 = 5;
int8_t _address=0x4b; // strap ADDR0 - SCL

void setup() {
  mySerial.begin();
  mySerial.print("\n\n\n*** Thermometer \n"); 
  mySerial.print("Press PUSH2 to end\n"); 
  pinMode(PUSH2, INPUT);     

  Wire.begin();
}


float getTemperature() {
  int16_t t;

  Wire.beginTransmission(_address); 
  Wire.write(0b00000000);      
  Wire.endTransmission(); 

  Wire.beginTransmission(_address);
  Wire.requestFrom(_address, 2);   
  t=(Wire.read() << 8 | Wire.read()) >> 4;

  Wire.endTransmission(); 
  if (t>0b100000000000) t -= 4096;
  return t*0.0625;
}


void loop() 
{
  mySerial.print(getTemperature(), 2);
  mySerial.print("\n");

  delay(500);

  // required to avoid USB freeze for next upload
  if (digitalRead(PUSH2)==LOW) {
    mySerial.print("\n\n*** End\n"); 
    mySerial.end();
    while(true); // endless loop
  }
}


