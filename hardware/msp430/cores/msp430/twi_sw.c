/*
  ************************************************************************
  *	twi_sw.c
  *
  *	twi software files for MSP430
  *		Copyright (c) 2015 StefanSch. All right reserved.
  *
  *
  ***********************************************************************

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "twi_sw.h"

#if DEFAULT_I2C == -1 /* indicates SW I2C on pseudo module 1 */


#define I2C_DELAY1() __delay_cycles(F_CPU / 1000000UL * 10)
#define I2C_DELAY2() __delay_cycles(F_CPU / 1000000UL * 20)

#define I2C_READ   BIT0
#define I2C_WRITE  0

uint8_t i2c_sw_start(uint8_t address, uint8_t rw);
uint8_t i2c_sw_txByte(uint8_t data);
void i2c_sw_ack(void);
uint8_t i2c_sw_rxByte(uint8_t lastChar);
void i2c_sw_stop(void);


void i2c_sw_init(void)
{
  digitalWrite(TWISDA1, LOW);
  digitalWrite(TWISCL1, LOW);
  pinMode(TWISDA1, INPUT);
  pinMode(TWISCL1, INPUT);
}

uint8_t i2c_sw_read(uint8_t slaveAddress,
                          uint16_t numBytes, uint8_t* data, uint8_t sendStop)
{
  uint16_t i;
  uint8_t ack_error;
  
  ack_error = i2c_sw_start(slaveAddress, I2C_READ);   // Send Start condition
                                          // [ADDR] + R/W bit = 1
  if (ack_error) return (ack_error);
  for (i = 0; i < numBytes-1; i++) {
    *data++ = i2c_sw_rxByte(0);           // Read data
  }
  *data++ = i2c_sw_rxByte(1);             // Read last data
  if (sendStop) i2c_sw_stop();            // Send Stop condition
  return (0);
}

uint8_t i2c_sw_write(uint8_t slaveAddress,
                           uint16_t numBytes, uint8_t* data, uint8_t sendStop)
{        
   uint16_t i;
   uint8_t ack_error;
   
   ack_error = i2c_sw_start(slaveAddress, I2C_WRITE);       // Send Start condition
                                                // [ADDR] + R/W bit = 0
   if (ack_error) return (ack_error);
   for (i = 0; i < numBytes; i++) {
	   ack_error |= i2c_sw_txByte(*data++);          // Send data and ack
   }
   if (sendStop) i2c_sw_stop();                 // Send Stop condition
   return (ack_error);
}

uint8_t i2c_sw_start(uint8_t address, uint8_t rw)               // Set up start condition for I2C
{
  pinMode(TWISDA1, OUTPUT);
  I2C_DELAY2();                        // delay
  pinMode(TWISCL1, OUTPUT);
  I2C_DELAY2();                        // delay
  return(i2c_sw_txByte((address << 1) | rw)); // [ADDR] + R/W bit
}

uint8_t i2c_sw_txByte(uint8_t data)
{
  uint8_t bits = 0x08;
  uint8_t ack_error;
  
  while (bits != 0x00)                      // Loop until all bits are shifted
  {
    if (data & BIT7)                        // Test data bit
      pinMode(TWISDA1, INPUT);
    else
      pinMode(TWISDA1, OUTPUT);
    I2C_DELAY2();
    pinMode(TWISCL1, INPUT);
    data <<= 1;                             // Shift bits 1 place to the left
    I2C_DELAY1();                           // Quick delay
    pinMode(TWISCL1, OUTPUT);
    bits--;                                 // Loop until 8 bits are sent
  }
  pinMode(TWISDA1, INPUT);
  // Get acknowledge
  I2C_DELAY2();
  pinMode(TWISCL1, INPUT);
  I2C_DELAY2();
  ack_error = digitalRead(TWISDA1);
  pinMode(TWISCL1, OUTPUT);
  return (ack_error);
}

void i2c_sw_ack(void)                       // Check for I2C acknowledge
{
   I2C_DELAY2();
   pinMode(TWISCL1, INPUT);
   I2C_DELAY2();
   pinMode(TWISCL1, OUTPUT);
}
            
uint8_t i2c_sw_rxByte(uint8_t lastChar)  // Read 8 bits of I2C data
{
   uint8_t bits = 0x08;
   uint8_t data = 0;

   pinMode(TWISDA1, INPUT);
   I2C_DELAY1();
   while (bits > 0)                         // Loop until all bits are read
   {
      pinMode(TWISCL1, INPUT);
      I2C_DELAY1();
      data <<= 1;                           // Shift bits 1 place to the left
      if (digitalRead(TWISDA1))             // Check digital input
        data |= 1;                          // If input is 'H' store a '1'
      pinMode(TWISCL1, OUTPUT);
      I2C_DELAY1();
      bits--;                               // Decrement I2C bit counter
   }
   if (lastChar == 0)
     pinMode(TWISDA1, OUTPUT); // Set acknowledge
   I2C_DELAY1();
   pinMode(TWISCL1, INPUT);
   I2C_DELAY1();
   pinMode(TWISCL1, OUTPUT);
   I2C_DELAY1();
   return (data);                           // Return 8-bit data byte
}   

void i2c_sw_stop(void)             // Send I2C stop command
{
  pinMode(TWISDA1, OUTPUT);
  I2C_DELAY2();
  pinMode(TWISCL1, INPUT);
  I2C_DELAY2();
  pinMode(TWISDA1, INPUT);
  I2C_DELAY2();
}

#endif // #if DEFAULT_I2C = -1 /* indicates SW I2C on pseudo module 1 */
