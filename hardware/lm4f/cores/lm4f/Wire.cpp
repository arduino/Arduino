/*
 ************************************************************************
 *	TwoWire.cpp
 *
 *	Arduino core files for MSP430
 *		Copyright (c) 2012 Robert Wessels. All right reserved.
 *
 *
 ***********************************************************************
  Derived from:
  TwoWire.cpp - Hardware serial library for Wiring
  Copyright (c) 2006 Nicholas Zambetti.  All right reserved.

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

  Modified 23 November 2006 by David A. Mellis
  Modified 28 September 2010 by Mark Sproul
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include "wiring_private.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_ints.h"
#include "inc/hw_i2c.h"
#include "driverlib/gpio.h"
#include "driverlib/debug.h"
#include "driverlib/interrupt.h"
#include "driverlib/rom.h"
#include "driverlib/rom_map.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/i2c.h"
#include "Wire.h"

#define TX_BUFFER_EMPTY    (txReadIndex == txWriteIndex)
#define TX_BUFFER_FULL     (((txWriteIndex + 1) % SERIAL_BUFFER_SIZE) == txReadIndex)

#define RX_BUFFER_EMPTY    (rxReadIndex == rxWriteIndex)
#define RX_BUFFER_FULL     (((rxWriteIndex + 1) % SERIAL_BUFFER_SIZE) == rxReadIndex)


#define MASTER_CS HWREG(MASTER_BASE + I2C_O_MCS)
#define SLAVE_CS HWREG(SLAVE_BASE + I2C_O_MCS)

static const unsigned long g_uli2cMasterBase[4] =
{
    I2C0_MASTER_BASE, I2C1_MASTER_BASE, 
	I2C2_MASTER_BASE, I2C3_MASTER_BASE
};
static const unsigned long g_uli2cSlaveBase[4] =
{
    I2C0_SLAVE_BASE, I2C1_SLAVE_BASE, 
	I2C2_SLAVE_BASE, I2C3_SLAVE_BASE
};
//*****************************************************************************
//
// The list of possible interrupts for the console i2c.
//
//*****************************************************************************
static const unsigned long g_uli2cInt[4] =
{
    INT_I2C0, INT_I2C1, INT_I2C2, INT_I2C3
};

//*****************************************************************************
//
// The list of i2c peripherals.
//
//*****************************************************************************
static const unsigned long g_uli2cPeriph[4] =
{
    SYSCTL_PERIPH_I2C0, SYSCTL_PERIPH_I2C1, 
    SYSCTL_PERIPH_I2C2, SYSCTL_PERIPH_I2C3
};

//*****************************************************************************
//
// The list of i2c gpio configurations.
//
//*****************************************************************************
static const unsigned long g_uli2cConfig[4][2] =
{
    {GPIO_PB2_I2C0SCL, GPIO_PB3_I2C0SDA},
    {GPIO_PA6_I2C1SCL, GPIO_PA7_I2C1SDA},
    {GPIO_PE4_I2C2SCL, GPIO_PE5_I2C2SDA},
    {GPIO_PD0_I2C3SCL, GPIO_PD1_I2C3SDA}
};

//*****************************************************************************
//
// The list of i2c gpio configurations.
//
//*****************************************************************************
static const unsigned long g_uli2cBase[4] =
{
    GPIO_PORTB_BASE, GPIO_PORTA_BASE, GPIO_PORTE_BASE, GPIO_PORTD_BASE
};

//*****************************************************************************
//
// The list of i2c gpio configurations.
//
//*****************************************************************************
static const unsigned long g_uli2cPins[4] =
{
    GPIO_PIN_2 | GPIO_PIN_3, 
    GPIO_PIN_6 | GPIO_PIN_7, 
    GPIO_PIN_4 | GPIO_PIN_5, 
    GPIO_PIN_0 | GPIO_PIN_1
};

#define MASTER_BASE g_uli2cMasterBase[i2cModule]
#define SLAVE_BASE g_uli2cSlaveBase[i2cModule]

// Initialize Class Variables //////////////////////////////////////////////////

uint8_t TwoWire::rxBuffer[BUFFER_LENGTH];
uint8_t TwoWire::rxBufferIndex = 0;
uint8_t TwoWire::rxBufferLength = 0;
uint8_t TwoWire::txAddress = 0;

uint8_t TwoWire::txBuffer[BUFFER_LENGTH];
uint8_t TwoWire::txBufferIndex = 0;
uint8_t TwoWire::txBufferLength = 0;

uint8_t TwoWire::transmitting = 0;
void (*TwoWire::user_onRequest)(void);
void (*TwoWire::user_onReceive)(int);

// Constructors ////////////////////////////////////////////////////////////////

TwoWire::TwoWire()
{
    i2cModule = 0;
}


// Private Methods //////////////////////////////////////////////////////////////


// Public Methods //////////////////////////////////////////////////////////////

void TwoWire::begin(void)
{
  rxBufferIndex = 0;
  rxBufferLength = 0;

  txBufferIndex = 0;
  txBufferLength = 0;
  
  SysCtlPeripheralEnable(g_uli2cPeriph[i2cModule]);

  //Configure GPIO pins for I2C operation
  GPIOPinConfigure(g_uli2cConfig[i2cModule][0]);
  GPIOPinConfigure(g_uli2cConfig[i2cModule][1]);
  GPIOPinTypeI2C(g_uli2cBase[i2cModule], g_uli2cPins[i2cModule]);

  //Enable and initialize the I2Cx master module
  //false indicates that we're not using fast-speed transfers
  I2CMasterInitExpClk(MASTER_BASE, SysCtlClockGet(), false);   
}

void TwoWire::begin(uint8_t address)
{

  begin();

  //Enable slave interrupts
  IntEnable(g_uli2cInt[i2cModule]);
  I2CSlaveIntEnableEx(SLAVE_BASE, I2C_SLAVE_INT_DATA);
  
  //Setup as a slave device
  I2CMasterDisable(MASTER_BASE);
  I2CSlaveEnable(SLAVE_BASE);
  I2CSlaveInit(SLAVE_BASE, address); 
  
  IntMasterEnable();
  
}

void TwoWire::selectModule(unsigned long _i2cModule)
{
    i2cModule = _i2cModule;
}

uint8_t TwoWire::requestFrom(uint8_t address, uint8_t quantity, uint8_t sendStop)
{
  // clamp to buffer length
  if(quantity > BUFFER_LENGTH){
    quantity = BUFFER_LENGTH;
  }
  
  //Select which slave we are requesting data from
  //true indicates we are reading from the slave
  I2CMasterSlaveAddrSet(MASTER_BASE, address, true);
  
  //Wait for bus to open up in the case of multiple masters present
  while(I2CMasterBusBusy(MASTER_BASE)){};
  
  //Initiate burst receives
  I2CMasterControl(MASTER_BASE, I2C_MASTER_CMD_BURST_RECEIVE_START);
  
  uint8_t i;
  for(i = 0; i < quantity; i++) {
  
	while(I2CMasterBusy(MASTER_BASE)){};
	I2CMasterControl(MASTER_BASE, I2C_MASTER_CMD_BURST_RECEIVE_CONT);
	
	//Stop for any error
	if (I2CMasterErr(MASTER_BASE) != I2C_MASTER_ERR_NONE) {
	  I2CMasterControl(MASTER_BASE, I2C_MASTER_CMD_BURST_RECEIVE_ERROR_STOP);
	  break;
	}
	
	//Place data into rxBuffer
	else {
	  rxBuffer[rxBufferIndex] = I2CMasterDataGet(MASTER_BASE);
	  rxBufferIndex = (rxBufferIndex + 1) % BUFFER_LENGTH;
	  rxBufferLength++;
	}
	
  }  

  //release the bus if needed
  if(sendStop) {
	I2CMasterControl(MASTER_BASE, I2C_MASTER_CMD_BURST_RECEIVE_FINISH);
  }

  return rxBufferLength;
}

uint8_t TwoWire::requestFrom(uint8_t address, uint8_t quantity)
{
  return requestFrom((uint8_t)address, (uint8_t)quantity, (uint8_t)true);
}
uint8_t TwoWire::requestFrom(int address, int quantity)
{
  return requestFrom((uint8_t)address, (uint8_t)quantity, (uint8_t)true);
}
uint8_t TwoWire::requestFrom(int address, int quantity, int sendStop)
{
  return requestFrom((uint8_t)address, (uint8_t)quantity, (uint8_t)sendStop);
}

void TwoWire::beginTransmission(uint8_t address)
{
  // indicate that we are transmitting
  transmitting = 1;
  // set address of targeted slave
  txAddress = address;
  // reset tx buffer iterator vars
  txBufferIndex = 0;
  txBufferLength = 0;
}

void TwoWire::beginTransmission(int address)
{
  beginTransmission((uint8_t)address);
}

uint8_t TwoWire::endTransmission(uint8_t sendStop)
{
  uint8_t error = I2C_MASTER_ERR_NONE;
  //Select which slave we are requesting data from
  //false indicates we are writing to the slave
  I2CMasterSlaveAddrSet(MASTER_BASE, txAddress, false);
  
  //Wait for bus to open up in the case of multiple masters present
  while(I2CMasterBusBusy(MASTER_BASE));
  
  //Initiate burst transmissions
  I2CMasterControl(MASTER_BASE, I2C_MASTER_CMD_BURST_SEND_START);
  
  uint8_t i;
  for(i = 0; i < txBufferLength; i++) {
  
	while(I2CMasterBusy(MASTER_BASE));
	
    I2CMasterDataPut(MASTER_BASE, txBuffer[txBufferIndex]);
	I2CMasterControl(MASTER_BASE, I2C_MASTER_CMD_BURST_SEND_CONT);
	
	//Stop for any error
	error = I2CMasterErr(MASTER_BASE);
	if (error != I2C_MASTER_ERR_NONE) {
	  I2CMasterControl(MASTER_BASE, I2C_MASTER_CMD_BURST_SEND_ERROR_STOP);
	  switch(error){
	    //Normally this would return a 1 for data being too long for buffer
		//but that is not a valid error condition for Stellaris
		case(I2C_MASTER_ERR_ADDR_ACK):
		  error = 2;
		  break;
	    case(I2C_MASTER_ERR_DATA_ACK):
		  error = 3;
		  break;
		default:
		  error = 4;
	  }
	  break;
	}
	else {
		txBufferIndex = (txBufferIndex + 1) % BUFFER_LENGTH;
		txBufferLength = (txBufferLength + 1) % BUFFER_LENGTH;
	}
  }
  //release the bus if needed
  if(sendStop) {
    I2CMasterControl(MASTER_BASE, I2C_MASTER_CMD_BURST_SEND_FINISH);
  }

  // reset tx buffer iterator vars
  txBufferIndex = 0;
  txBufferLength = 0;
  // indicate that we are done transmitting
  transmitting = 0;
  return error;
}

//	This provides backwards compatibility with the original
//	definition, and expected behaviour, of endTransmission
//
uint8_t TwoWire::endTransmission(void)
{
  return endTransmission(true);
}

// must be called in:
// slave tx event callback
// or after beginTransmission(address)
size_t TwoWire::write(uint8_t data)
{
  if(transmitting){
  // in master transmitter mode
    // don't bother if buffer is full
    if(txBufferLength >= BUFFER_LENGTH){
      setWriteError();
      return 0;
    }
    // put byte in tx buffer
    txBuffer[txBufferIndex] = data;
    ++txBufferIndex;
    // update amount in buffer   
    txBufferLength = txBufferIndex;
  }else{
  // in slave send mode
    // reply to master
	I2CSlaveDataPut(SLAVE_BASE, data);
  }
  return 1;
}

// must be called in:
// slave tx event callback
// or after beginTransmission(address)
size_t TwoWire::write(const uint8_t *data, size_t quantity)
{
  for(size_t i = 0; i < quantity; i++){
      write(data[i]);
  }
  return quantity;
}

// must be called in:
// slave rx event callback
// or after requestFrom(address, numBytes)
int TwoWire::available(void)
{
  return rxBufferLength - rxBufferIndex;
}

// must be called in:
// slave rx event callback
// or after requestFrom(address, numBytes)
int TwoWire::read(void)
{
  int value = -1;
  
  // get each successive byte on each call
  if(rxBufferIndex < rxBufferLength){
    value = rxBuffer[rxBufferIndex];
    ++rxBufferIndex;
  }

  return value;
}

// must be called in:
// slave rx event callback
// or after requestFrom(address, numBytes)
int TwoWire::peek(void)
{
  int value = -1;
  
  if(rxBufferIndex < rxBufferLength){
    value = rxBuffer[rxBufferIndex];
  }

  return value;
}
void TwoWire::flush(void)
{
	txBufferIndex = 0;
}

// sets function called on slave write
void TwoWire::onReceive( void (*function)(int) )
{
  user_onReceive = function;
}

// sets function called on slave read
void TwoWire::onRequest( void (*function)(void) )
{
  user_onRequest = function;
}

void TwoWire::I2CIntHandler(void) {

    I2CSlaveIntClear(SLAVE_BASE);
	switch(I2CSlaveStatus(SLAVE_BASE)) {
		case(I2C_SLAVE_ACT_RREQ)://data received
		    user_onReceive(rxBufferIndex);
			break;
		case(I2C_SLAVE_ACT_TREQ)://data requested 
		    user_onRequest();
			break;
		default:
			break;
	}
}
void
I2CIntHandler(void)
{
    Wire.I2CIntHandler();
}

//Preinstantiate Object
TwoWire Wire;
