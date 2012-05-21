//
//  I2C_TMP102_Thermometer_430
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
//  Binary sketch size = 3004 bytes out of 8192 bytes
//

#include "Wire.h"
#include "TimerSerial.h"

// PUSH2 alreadey defined
#define _address 0x4b // strap ADDR0 - SCL

TimerSerial mySerial;

void setup() {
  mySerial.begin();
  mySerial.print("\n\n\n*** Thermometer \n"); 
  mySerial.print("Press PUSH2 to end\n"); 
  pinMode(PUSH2, INPUT);     

  Wire.begin();
}

int16_t t;

void loop() {
  Wire.beginTransmission(_address); 
  Wire.write(0b00000000);      
  Wire.endTransmission(); 

  Wire.beginTransmission(_address);
  Wire.requestFrom(_address, 2);   
  t=(Wire.read() << 8 | Wire.read()) >> 4;

  Wire.endTransmission(); 
  if (t>0b100000000000) t -= 4096;

  //  Float adds 6 kB
  //  mySerial.print(t*0.0625, DEC);
  //  mySerial.print("\n");

  // Integer
  t *= 10;  // one decimal place
  t += 8;   // rounding
  mySerial.print(t/160, DEC);
  mySerial.print(".");
  mySerial.print((t%160)/16, DEC);
  mySerial.print("\n");

  delay(500);

  // PUSH2 required to avoid USB freeze for next upload
  if (digitalRead(PUSH2)==LOW) {
    mySerial.print("\n*** End\n"); 
    mySerial.end();
    while(true); // endless loop
  }
}






