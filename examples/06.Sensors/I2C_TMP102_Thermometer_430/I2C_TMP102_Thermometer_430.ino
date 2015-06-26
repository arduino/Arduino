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
// Revision
//   Rei VILO, May 21, 2012 - Updated with GREEN_LED, RED_LED and PUSH2
//   Rei VILO, Sep 09, 2012 - TimerSerial.h no longer required
//   Rei VILO, Sep 24, 2012 - FraunchPad excluded
#if defined(__MSP430G2452__) || defined(__MSP430G2553__) || defined(__MSP430G2231__) 
#else
#error Board not supported
#endif


#include "Wire.h"

// PUSH2 alreadey defined
#define _address 0x4b // strap ADDR0 - SCL

void setup() {
  Serial.begin(9600);
  Serial.print("\n\n\n*** Thermometer \n"); 
  Serial.print("Press PUSH2 to end\n"); 
  pinMode(PUSH2, INPUT_PULLUP);     

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
  //  Serial.print(t*0.0625, DEC);
  //  Serial.print("\n");

  // Integer
  t *= 10;  // one decimal place
  t += 8;   // rounding
  Serial.print(t/160, DEC);
  Serial.print(".");
  Serial.print((t%160)/16, DEC);
  Serial.print("\n");

  delay(500);

  // PUSH2 required to avoid USB freeze for next upload
  if (digitalRead(PUSH2)==LOW) {
    Serial.print("\n*** End\n"); 
    Serial.end();
    while(true); // endless loop
  }
}






