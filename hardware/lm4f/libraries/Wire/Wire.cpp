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
#define TX_BUFFER_FULL     (((txWriteIndex + 1) % BUFFER_LENGTH) == txReadIndex)

#define RX_BUFFER_EMPTY    (rxReadIndex == rxWriteIndex)
#define RX_BUFFER_FULL     (((rxWriteIndex + 1) % BUFFER_LENGTH) == rxReadIndex)

#define RUN_BIT 	0x1
#define START_BIT 	0x2
#define STOP_BIT	0x4
#define ACK_BIT 	0x8

#define NOT_ACTIVE  0xA

static const unsigned long g_uli2cMasterBase[4] =
{
#ifdef TARGET_IS_BLIZZARD_RB1
    I2C0_BASE, I2C1_BASE, 
	I2C2_BASE, I2C3_BASE
#else
#ifdef __TM4C129XNCZAD__
    I2C0_BASE, I2C1_BASE, 
	I2C2_BASE, I2C3_BASE
#endif
#ifdef __TM4C1294NCPDT__
    I2C0_BASE, I2C2_BASE, 
	I2C8_BASE, I2C7_BASE
#endif
#endif
};
static const unsigned long g_uli2cSlaveBase[4] =
{
#ifdef TARGET_IS_BLIZZARD_RB1
    I2C0_BASE, I2C1_BASE, 
	I2C2_BASE, I2C3_BASE
#else
#ifdef __TM4C129XNCZAD__
    I2C0_BASE, I2C1_BASE, 
	I2C2_BASE, I2C3_BASE
#endif
#ifdef __TM4C1294NCPDT__
    I2C0_BASE, I2C2_BASE, 
	I2C8_BASE, I2C7_BASE
#endif
#endif
};

//*****************************************************************************
//
// The list of possible interrupts for the console i2c.
//
//*****************************************************************************
static const unsigned long g_uli2cInt[4] =
{
#ifdef TARGET_IS_BLIZZARD_RB1
    INT_I2C0, INT_I2C1, INT_I2C2, INT_I2C3
#else
#ifdef __TM4C129XNCZAD__
    INT_I2C0, INT_I2C1, INT_I2C2, INT_I2C3
#endif
#ifdef __TM4C1294NCPDT__
    INT_I2C0, INT_I2C2, INT_I2C8, INT_I2C7
#endif
#endif

};

//*****************************************************************************
//
// The list of i2c peripherals.
//
//*****************************************************************************
static const unsigned long g_uli2cPeriph[4] =
{
#ifdef TARGET_IS_BLIZZARD_RB1
    SYSCTL_PERIPH_I2C0, SYSCTL_PERIPH_I2C1, 
    SYSCTL_PERIPH_I2C2, SYSCTL_PERIPH_I2C3
#else
#ifdef __TM4C129XNCZAD__
    SYSCTL_PERIPH_I2C0, SYSCTL_PERIPH_I2C1, 
    SYSCTL_PERIPH_I2C2, SYSCTL_PERIPH_I2C3
#endif
#ifdef __TM4C1294NCPDT__
    SYSCTL_PERIPH_I2C0, SYSCTL_PERIPH_I2C2, 
    SYSCTL_PERIPH_I2C8, SYSCTL_PERIPH_I2C7
#endif
#endif
};

//*****************************************************************************
//
// The list of i2c gpio configurations.
//
//*****************************************************************************
static const unsigned long g_uli2cConfig[4][2] =
{
#ifdef TARGET_IS_BLIZZARD_RB1
    {GPIO_PB2_I2C0SCL, GPIO_PB3_I2C0SDA},
    {GPIO_PA6_I2C1SCL, GPIO_PA7_I2C1SDA},
    {GPIO_PE4_I2C2SCL, GPIO_PE5_I2C2SDA},
    {GPIO_PD0_I2C3SCL, GPIO_PD1_I2C3SDA}
#else
#ifdef __TM4C129XNCZAD__
    {GPIO_PB2_I2C0SCL, GPIO_PB3_I2C0SDA},
    {GPIO_PG0_I2C1SCL, GPIO_PG1_I2C1SDA},
    {GPIO_PL1_I2C2SCL, GPIO_PL0_I2C2SDA},
    {GPIO_PG4_I2C3SCL, GPIO_PG5_I2C3SDA}
#endif
#ifdef __TM4C1294NCPDT__
    {GPIO_PB2_I2C0SCL, GPIO_PB3_I2C0SDA},
    {GPIO_PN5_I2C2SCL, GPIO_PN4_I2C2SDA},
    {GPIO_PA2_I2C8SCL, GPIO_PA3_I2C8SDA},
    {GPIO_PD0_I2C7SCL, GPIO_PD1_I2C7SDA}
#endif
#endif
};

//*****************************************************************************
//
// The list of i2c gpio configurations.
//
//*****************************************************************************
static const unsigned long g_uli2cBase[4] =
{
#ifdef TARGET_IS_BLIZZARD_RB1
    GPIO_PORTB_BASE, GPIO_PORTA_BASE, GPIO_PORTE_BASE, GPIO_PORTD_BASE
#else
#ifdef __TM4C129XNCZAD__
    GPIO_PORTB_BASE, GPIO_PORTG_BASE, GPIO_PORTL_BASE, GPIO_PORTG_BASE
#endif
#ifdef __TM4C1294NCPDT__
    GPIO_PORTB_BASE, GPIO_PORTN_BASE, GPIO_PORTA_BASE, GPIO_PORTD_BASE
#endif
#endif
};

//*****************************************************************************
//
// The list of i2c gpio configurations.
//
//*****************************************************************************
static const unsigned long g_uli2cSDAPins[4] =
{
#ifdef TARGET_IS_BLIZZARD_RB1
    GPIO_PIN_3, GPIO_PIN_7, GPIO_PIN_5, GPIO_PIN_1
#else
#ifdef __TM4C129XNCZAD__
    GPIO_PIN_3, GPIO_PIN_1, GPIO_PIN_0, GPIO_PIN_5
#endif
#ifdef __TM4C1294NCPDT__
    GPIO_PIN_3, GPIO_PIN_4, GPIO_PIN_3, GPIO_PIN_1
#endif
#endif
};
static const unsigned long g_uli2cSCLPins[4] =
{
#ifdef TARGET_IS_BLIZZARD_RB1
    GPIO_PIN_2, GPIO_PIN_6, GPIO_PIN_4, GPIO_PIN_0
#else
#ifdef __TM4C129XNCZAD__
    GPIO_PIN_2, GPIO_PIN_0, GPIO_PIN_1, GPIO_PIN_4
#endif
#ifdef __TM4C1294NCPDT__
    GPIO_PIN_2, GPIO_PIN_5, GPIO_PIN_2, GPIO_PIN_0
#endif
#endif
};

#define MASTER_BASE g_uli2cMasterBase[i2cModule]
#define SLAVE_BASE g_uli2cSlaveBase[i2cModule]

// Initialize Class Variables //////////////////////////////////////////////////

uint8_t TwoWire::rxBuffer[BUFFER_LENGTH];
uint8_t TwoWire::rxReadIndex = 0;
uint8_t TwoWire::rxWriteIndex = 0;
uint8_t TwoWire::txAddress = 0;

uint8_t TwoWire::txBuffer[BUFFER_LENGTH];
uint8_t TwoWire::txReadIndex = 0;
uint8_t TwoWire::txWriteIndex = 0;

uint8_t TwoWire::transmitting = 0;
uint8_t TwoWire::currentState = IDLE;

void (*TwoWire::user_onRequest)(void);
void (*TwoWire::user_onReceive)(int);

uint8_t TwoWire::i2cModule = NOT_ACTIVE;
uint8_t TwoWire::slaveAddress = 0;
// Constructors ////////////////////////////////////////////////////////////////

TwoWire::TwoWire()
{
}

TwoWire::TwoWire(unsigned long module)
{
	i2cModule = module;
}

// Private Methods //////////////////////////////////////////////////////////////

uint8_t getError(uint8_t thrownError) {
  if(thrownError == I2C_MASTER_ERR_ADDR_ACK) return(2);
  else if(thrownError == I2C_MASTER_ERR_DATA_ACK) return(3);
  else if(thrownError != 0) return (4);
  else return(0);
}

uint8_t TwoWire::getRxData(unsigned long cmd) {

	if (currentState == IDLE) while(ROM_I2CMasterBusBusy(MASTER_BASE));
	HWREG(MASTER_BASE + I2C_O_MCS) = cmd;
	while(ROM_I2CMasterBusy(MASTER_BASE));
	uint8_t error = ROM_I2CMasterErr(MASTER_BASE);
	if (error != I2C_MASTER_ERR_NONE) {
        ROM_I2CMasterControl(MASTER_BASE, I2C_MASTER_CMD_BURST_RECEIVE_ERROR_STOP);
	}
	else {
		delay(1);
		rxBuffer[rxWriteIndex] = ROM_I2CMasterDataGet(MASTER_BASE);
		rxWriteIndex = (rxWriteIndex + 1) % BUFFER_LENGTH;
	}
	return error;

}

uint8_t TwoWire::sendTxData(unsigned long cmd, uint8_t data) {
    delay(1);
    ROM_I2CMasterDataPut(MASTER_BASE, data);

    HWREG(MASTER_BASE + I2C_O_MCS) = cmd;
    while(ROM_I2CMasterBusy(MASTER_BASE));
    uint8_t error = ROM_I2CMasterErr(MASTER_BASE);
    if (error != I2C_MASTER_ERR_NONE)
		  ROM_I2CMasterControl(MASTER_BASE, I2C_MASTER_CMD_BURST_SEND_ERROR_STOP);
    return(getError(error));
}

void TwoWire::forceStop(void) {

	//force a stop to release the bus
	ROM_GPIOPinTypeGPIOOutput(g_uli2cBase[i2cModule],
		  g_uli2cSCLPins[i2cModule] | g_uli2cSDAPins[i2cModule]);
    ROM_GPIOPinWrite(g_uli2cBase[i2cModule], g_uli2cSDAPins[i2cModule], 0);
    ROM_GPIOPinWrite(g_uli2cBase[i2cModule],
  		  g_uli2cSCLPins[i2cModule], g_uli2cSCLPins[i2cModule]);
    ROM_GPIOPinWrite(g_uli2cBase[i2cModule],
    	  g_uli2cSDAPins[i2cModule], g_uli2cSDAPins[i2cModule]);

    ROM_GPIOPinTypeI2C(g_uli2cBase[i2cModule], g_uli2cSDAPins[i2cModule]);
    ROM_GPIOPinTypeI2CSCL(g_uli2cBase[i2cModule], g_uli2cSCLPins[i2cModule]);
    //reset I2C controller
    //without resetting the I2C controller, the I2C module will
    //bring the bus back to it's erroneous state
    ROM_SysCtlPeripheralReset(g_uli2cPeriph[i2cModule]);
    while(!ROM_SysCtlPeripheralReady(g_uli2cPeriph[i2cModule]));
    ROM_I2CMasterInitExpClk(MASTER_BASE, F_CPU, false);
}

// Public Methods //////////////////////////////////////////////////////////////

//Initialize as a master
void TwoWire::begin(void)
{

  if(i2cModule == NOT_ACTIVE) {
      i2cModule = BOOST_PACK_WIRE;
  }

  ROM_SysCtlPeripheralEnable(g_uli2cPeriph[i2cModule]);

  //Configure GPIO pins for I2C operation
  ROM_GPIOPinConfigure(g_uli2cConfig[i2cModule][0]);
  ROM_GPIOPinConfigure(g_uli2cConfig[i2cModule][1]);
  ROM_GPIOPinTypeI2C(g_uli2cBase[i2cModule], g_uli2cSDAPins[i2cModule]);
  ROM_GPIOPinTypeI2CSCL(g_uli2cBase[i2cModule], g_uli2cSCLPins[i2cModule]);
  ROM_I2CMasterInitExpClk(MASTER_BASE, F_CPU, false);//max bus speed=400kHz for gyroscope

  //force a stop condition
  if(!ROM_GPIOPinRead(g_uli2cBase[i2cModule], g_uli2cSCLPins[i2cModule]))
	  forceStop();

  //Handle any startup issues by pulsing SCL
  if(ROM_I2CMasterBusBusy(MASTER_BASE) || ROM_I2CMasterErr(MASTER_BASE) 
	|| !ROM_GPIOPinRead(g_uli2cBase[i2cModule], g_uli2cSCLPins[i2cModule])){
	  uint8_t doI = 0;
  	  ROM_GPIOPinTypeGPIOOutput(g_uli2cBase[i2cModule], g_uli2cSCLPins[i2cModule]);
  	  unsigned long mask = 0;
  	  do{
  		  for(unsigned long i = 0; i < 10 ; i++) {
  			  ROM_SysCtlDelay(F_CPU/100000/3);//100Hz=desired frequency, delay iteration=3 cycles
  			  mask = (i%2) ? g_uli2cSCLPins[i2cModule] : 0;
  			  ROM_GPIOPinWrite(g_uli2cBase[i2cModule], g_uli2cSCLPins[i2cModule], mask);
  		  }
  		  doI++;
  	  }while(ROM_I2CMasterBusBusy(MASTER_BASE) && doI < 100);

  	  ROM_GPIOPinTypeI2CSCL(g_uli2cBase[i2cModule], g_uli2cSCLPins[i2cModule]);
  	  if(!ROM_GPIOPinRead(g_uli2cBase[i2cModule], g_uli2cSCLPins[i2cModule]))
  		  forceStop();

  }

}

//Initialize as a slave
void TwoWire::begin(uint8_t address)
{

  if(i2cModule == NOT_ACTIVE) {
      i2cModule = BOOST_PACK_WIRE;
  }

  ROM_SysCtlPeripheralEnable(g_uli2cPeriph[i2cModule]);
  ROM_GPIOPinConfigure(g_uli2cConfig[i2cModule][0]);
  ROM_GPIOPinConfigure(g_uli2cConfig[i2cModule][1]);
  ROM_GPIOPinTypeI2C(g_uli2cBase[i2cModule], g_uli2cSDAPins[i2cModule]);
  ROM_GPIOPinTypeI2CSCL(g_uli2cBase[i2cModule], g_uli2cSCLPins[i2cModule]);
  slaveAddress = address;

  //Enable slave interrupts
  ROM_IntEnable(g_uli2cInt[i2cModule]);
  I2CSlaveIntEnableEx(SLAVE_BASE, I2C_SLAVE_INT_DATA | I2C_SLAVE_INT_STOP);
  HWREG(SLAVE_BASE + I2C_O_SICR) =
		  I2C_SICR_DATAIC | I2C_SICR_STARTIC | I2C_SICR_STOPIC;

  //Setup as a slave device
  ROM_I2CMasterDisable(MASTER_BASE);
  I2CSlaveEnable(SLAVE_BASE);
  I2CSlaveInit(SLAVE_BASE, address); 
  
  ROM_IntMasterEnable();

}

void TwoWire::begin(int address)
{
  begin((uint8_t)address);
}

uint8_t TwoWire::requestFrom(uint8_t address, uint8_t quantity, uint8_t sendStop)
{
  uint8_t error = 0;
  uint8_t oldWriteIndex = rxWriteIndex;
  uint8_t spaceAvailable = (rxWriteIndex >= rxReadIndex) ?
		 BUFFER_LENGTH - (rxWriteIndex - rxReadIndex) : (rxReadIndex - rxWriteIndex);

  if (quantity > spaceAvailable)
	  quantity = spaceAvailable;
  if (!quantity) return 0;

  //Select which slave we are requesting data from
  //true indicates we are reading from the slave
  ROM_I2CMasterSlaveAddrSet(MASTER_BASE, address, true);

  unsigned long cmd = 0;

  if((quantity > 1) || !sendStop)
	  cmd = RUN_BIT | START_BIT | ACK_BIT;
  else cmd = RUN_BIT | START_BIT | (sendStop << 2);

  error = getRxData(cmd);
  if(error) return 0;

  currentState = MASTER_RX;

  for (int i = 1; i < quantity; i++) {
	  //since NACK is being sent on last byte, a consecutive burst read will
	  //need to send a start condition
	  if(i == (quantity - 1))
		cmd = RUN_BIT;
	  else
		cmd = RUN_BIT | ACK_BIT;

	  error = getRxData(cmd);
	  if(error) return i;
  }

  if(sendStop) {
	  HWREG(MASTER_BASE + I2C_O_MCS) = STOP_BIT;
	  while(ROM_I2CMasterBusy(MASTER_BASE));
	  currentState = IDLE;
  }

  uint8_t bytesWritten = (rxWriteIndex >= oldWriteIndex) ?
		 BUFFER_LENGTH - (rxWriteIndex - oldWriteIndex) : (oldWriteIndex - rxWriteIndex);

  return(bytesWritten);

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
  transmitting = 1;
  // set address of targeted slave
  txAddress = address;
}

void TwoWire::beginTransmission(int address)
{
  beginTransmission((uint8_t)address);
}

uint8_t TwoWire::endTransmission(uint8_t sendStop)
{
  uint8_t error = I2C_MASTER_ERR_NONE;

  if(TX_BUFFER_EMPTY) return 0;
  //Wait for any previous transaction to complete
  while(ROM_I2CMasterBusBusy(MASTER_BASE));
  while(ROM_I2CMasterBusy(MASTER_BASE));

  //Select which slave we are requesting data from
  //false indicates we are writing to the slave
  ROM_I2CMasterSlaveAddrSet(MASTER_BASE, txAddress, false);

  while(ROM_I2CMasterBusy(MASTER_BASE));
  unsigned long cmd = RUN_BIT | START_BIT;

  error = sendTxData(cmd,txBuffer[txReadIndex]);
  txReadIndex = (txReadIndex + 1) % BUFFER_LENGTH;
  if(error) return error;
  while(!TX_BUFFER_EMPTY) {
	  error = sendTxData(RUN_BIT,txBuffer[txReadIndex]);
  	  txReadIndex = (txReadIndex + 1) % BUFFER_LENGTH;
	  if(error) return getError(error);
  }

  if(sendStop) {
	  while(ROM_I2CMasterBusy(MASTER_BASE));
	  HWREG(MASTER_BASE + I2C_O_MCS) = STOP_BIT;
	  while(ROM_I2CMasterBusy(MASTER_BASE));
	  currentState = IDLE;
  }
  else {
	  currentState = MASTER_TX;
  }

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
    if(TX_BUFFER_FULL){
      setWriteError();
      return 0;
    }
    // put byte in tx buffer
    txBuffer[txWriteIndex] = data;
    txWriteIndex = (txWriteIndex + 1) % BUFFER_LENGTH;

  }else{
  // in slave send mode
    // reply to master
	if(TX_BUFFER_FULL) {
		I2CSlaveDataPut(SLAVE_BASE, txBuffer[txReadIndex]);
		txReadIndex = (txReadIndex + 1) % BUFFER_LENGTH;
	}
	    txBuffer[txWriteIndex] = data;
	    txWriteIndex = (txWriteIndex + 1) % BUFFER_LENGTH;
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
    return((rxWriteIndex >= rxReadIndex) ?
		(rxWriteIndex - rxReadIndex) : BUFFER_LENGTH - (rxReadIndex - rxWriteIndex));
}

// must be called in:
// slave rx event callback
// or after requestFrom(address, numBytes)
int TwoWire::read(void)
{
  int value = -1;
  
  // get each successive byte on each call
  if(!RX_BUFFER_FULL){
    value = rxBuffer[rxReadIndex];
    rxReadIndex = (rxReadIndex + 1) % BUFFER_LENGTH;
  }

  return value;
}

// must be called in:
// slave rx event callback
// or after requestFrom(address, numBytes)
int TwoWire::peek(void)
{
  int value = -1;
  
  if(!RX_BUFFER_EMPTY){
    value = rxBuffer[rxReadIndex];
  }
  return value;
}
void TwoWire::flush(void)
{
	txWriteIndex = 0;
	rxReadIndex = rxWriteIndex;
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
	//clear data interrupt
	HWREG(SLAVE_BASE + I2C_O_SICR) = I2C_SICR_DATAIC;
	uint8_t startDetected = 0;
	uint8_t stopDetected = 0;

	if(HWREG(SLAVE_BASE + I2C_O_SRIS) & I2C_SLAVE_INT_START) {
		startDetected = 1;
	    //clear raw start interrupt
	    HWREG(SLAVE_BASE + I2C_O_SICR) = I2C_SICR_STARTIC;
	}
	else if(HWREG(SLAVE_BASE + I2C_O_SRIS) & I2C_SLAVE_INT_STOP) {
		stopDetected = 1;
	    HWREG(SLAVE_BASE + I2C_O_SICR) = I2C_SICR_STOPIC;
	}

	switch(I2CSlaveStatus(SLAVE_BASE) & (I2C_SCSR_TREQ | I2C_SCSR_RREQ)) {

		case(I2C_SLAVE_ACT_RREQ)://data received
			if(I2CSlaveStatus(SLAVE_BASE) & I2C_SCSR_FBR)
				currentState = SLAVE_RX;
			if(!RX_BUFFER_FULL) {
				rxBuffer[rxWriteIndex] = I2CSlaveDataGet(SLAVE_BASE);
				rxWriteIndex = (rxWriteIndex + 1) % BUFFER_LENGTH;
			}

			break;

		case(I2C_SLAVE_ACT_TREQ)://data requested 

		    if(startDetected) {
		        uint8_t oldWriteIndex = txWriteIndex;
		        user_onRequest();

		        //
		        // send data if onRequest() wrote data that has
		        // yet to be sent
		        //
		    	if(oldWriteIndex != txWriteIndex) {
			    	I2CSlaveDataPut(SLAVE_BASE, txBuffer[txReadIndex]);
			    	txReadIndex = (txReadIndex + 1) % BUFFER_LENGTH;
		        }

		    }

		    else if(!TX_BUFFER_EMPTY){
		    	I2CSlaveDataPut(SLAVE_BASE, txBuffer[txReadIndex]);
		    	txReadIndex = (txReadIndex + 1) % BUFFER_LENGTH;
		    }

		    else
		    	I2CSlaveDataPut(SLAVE_BASE, 0);

			break;

		default:
			break;
	}

	if(stopDetected && currentState == SLAVE_RX) {
		int avail = available();
		user_onReceive(avail);
		currentState = IDLE;
	}

}

void
I2CIntHandler(void)
{
    Wire.I2CIntHandler();
}

void TwoWire::setModule(unsigned long _i2cModule)
{
    i2cModule = _i2cModule;
    if(slaveAddress != 0) begin(slaveAddress);
    else begin();
}

//Preinstantiate Object
TwoWire Wire;
