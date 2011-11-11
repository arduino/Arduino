/*
  * Author: Ed Baafi 
  * Date: 11/11/11 
  *
  * This example demonstrates the TWI (I2C) "General Call" capabilities.
  *
  * General call is like a broadcast that can be received by many listeners at the same same. This
  * is useful when you don't know the address of the device you want to talk to or it can be used as
  * a sort of interrupt over the TWI (I2C). For more info on General Call, please see the I2C specs.
  *
  * The Wire library now supports General Call by adding a second receive callback to Wire.onReceive()
  * This second callback will be called whenever a message is received over the general call address.  
  *
  * 1) This code is for the slave device.  Connect the slave device (through usb) to your PC and open  
  *  up the serial monitor (set it to 9600 bps).  You can optionally connect two LEDs to pins 12 and 11
  *
  * 2) On the master device, connect a button between pin10 and ground and another between pin9 
  *  and ground.  The pin10 button will send its state to the general call address (can be picked up by 
  *  any attached slave device) and the pin9 button will sent through to a specific slave address. 
  * 
  * 3) Connect the SCL and SDA lines from the slave to the master.  For UNO boards SDA is on analog pin
  *  4 and SCL is on analog pin 5.
  *
  * 4) Pressing one button will send a message to general call and the other will send a message through 
  *  the slave's address.  Want to go further, add a second slave device and/or use the LEDs to see which
  *  address is being sent to.
  */
  
#include <Wire.h>

//led to tie to the master's general call i2c button
#define GENERAL_CALL_RECV_LED 12
//led to tie to the master's normal i2c button
#define RECV_LED 11

#define MY_ADDRESS 0x9

void setup() {
  Serial.begin(9600);
 
  //set general call led pin as output and set low (turn off)
  pinMode(GENERAL_CALL_RECV_LED, OUTPUT);
  digitalWrite(GENERAL_CALL_RECV_LED, LOW);
  
  //set slave receive led pin as output and set low (turn off)
  pinMode(RECV_LED, OUTPUT);
  digitalWrite(RECV_LED, LOW);
  
  //setup TWI as slave and set address
  Wire.begin(MY_ADDRESS);
  
  //setup first callback to fire when data is received on MY_ADDRESS
  //and the second when a data is received on the general call address (0x0)
  //if you omit the second callback, general call wil not be enabled in the Wire library
  Wire.onReceive(receiveCallback,generalCallreceiveCallback);
  
}

void loop() {
   //do nothing - wait for callbacks to fire
}

void receiveCallback(int howMany){
     //print data sent to MY_ADDRESS to the serial monitor
     Serial.print("\nRECIEIVED BYTE FROM SLAVE ADDRESS: ");
     while (Wire.available() > 0 && howMany > 0){
        boolean b = Wire.read();
        Serial.print(b, DEC);
        digitalWrite(RECV_LED, !b);
        howMany--;
     }
}

void generalCallreceiveCallback(int howMany){
      //print data sent to the general call address to the serial monitor
      Serial.print("\nRECEIVED BYTE FROM GENERAL CALL ADDRESS: "); 
      while (Wire.available() > 0 && howMany > 0){
        boolean b = Wire.read();
        Serial.print(b, DEC);
        digitalWrite(GENERAL_CALL_RECV_LED, !b);
        howMany--;
      } 
}

