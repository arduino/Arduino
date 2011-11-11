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
  * This code is for the master device. Instructions are in comments for the slave device code.
  *  
  */

#include <Wire.h>

//button to send a general call message (connect button between pin10 and ground)
#define GENERAL_CALL_ADDR_BUTTON 10
//button to send a normal i2c message (connect button between pin 9 and ground)
#define SLAVE_ADDR_BUTTON 9

#define SLAVE_ADDRESS 0x9
#define GENERAL_CALL_ADDR 0x0

//store state of slave message button 
boolean slave_btn_state = HIGH;
//store state of general call message button
boolean general_call_btn_state = HIGH;

void setup() {
  Serial.begin(9600);
  
  //setup general call button as input with internal pullup
  pinMode(GENERAL_CALL_ADDR_BUTTON, INPUT);
  digitalWrite(GENERAL_CALL_ADDR_BUTTON, HIGH);
  
  //setup normal i2c send button as input with internal pullup
  pinMode(SLAVE_ADDR_BUTTON, INPUT);
  digitalWrite(SLAVE_ADDR_BUTTON, HIGH);
  
  //setup TWI as master
  Wire.begin();
  
}

void loop() {
  //if general call button state changes, send new state over message to general call address
  if (digitalRead(GENERAL_CALL_ADDR_BUTTON) != general_call_btn_state){
    general_call_btn_state = !general_call_btn_state;
    Wire.beginTransmission(GENERAL_CALL_ADDR);
    Wire.write(general_call_btn_state);
    Wire.endTransmission();
    delay(100);
  }
  
  //if slave address send button changes state, send new state over message to slave address
  if (digitalRead(SLAVE_ADDR_BUTTON) != slave_btn_state){
    slave_btn_state = !slave_btn_state;
    Wire.beginTransmission(SLAVE_ADDRESS);
    Wire.write(slave_btn_state);
    Wire.endTransmission();
    //we need a small delay or we'll crash the Wire library - TODO - fix it
    delay(100);
  }
  
}
