/*
  ************************************************************************
  *	twi.c
  *
  *	Arduino core files for C2000
  *		Copyright (c) 2012 Trey German. All right reserved.
  *
  *
  ***********************************************************************
  Derived from:
  twi.c - TWI/I2C library for Wiring & Arduino
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
*/

#include <math.h>
#include <stdlib.h>
#include "Energia.h" // for digitalWrite
 
#ifndef cbi
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#endif

#ifndef sbi
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
#endif

#include "wiring_private.h"
#include "pins_energia.h"
#include "twi.h"
#include "sci_isr_handler.h"

// Clock Settings for I2C module

#define SYSCLKOUT 60*10^6 // Frequency of I2C i/p clk
#define MODCLK    10*10^6 // Frequency of module clk must be between 7-10Mhz, selecting 10Mhz
#define CLKL      10      // Clock high
#define CLKH      5       // clock low

static volatile uint8_t twi_state;
static volatile uint8_t twi_sendStop;           // should the transaction end with a stop
static volatile uint8_t twi_inRepStart;         // in the middle of a repeated start

static void (*twi_onSlaveTransmit)(void);
static void (*twi_onSlaveReceive)(uint8_t*, int);

static uint8_t twi_masterBuffer[TWI_BUFFER_LENGTH];
static volatile uint8_t twi_masterBufferIndex;
static uint8_t twi_masterBufferLength;

static uint8_t twi_txBuffer[TWI_BUFFER_LENGTH];
static volatile uint8_t twi_txBufferIndex;
static volatile uint8_t twi_txBufferLength;
#if (defined(__MSP430_HAS_USCI__) || defined(__MSP430_HAS_EUSCI_B0__))
static uint8_t twi_rxBuffer[TWI_BUFFER_LENGTH];
static volatile uint8_t twi_rxBufferIndex;
#endif

static volatile uint8_t twi_error;

static uint8_t twi_slarw;
//static uint8_t twi_my_addr;

/*
 * Function twi_init
 * Desc     readys twi pins and sets twi bitrate
 * Input    none
 * Output   none
 */

int i = 0;
void twi_init(void)
{

EALLOW;

SysCtrlRegs.PCLKCR0.bit.I2CAENCLK = 1;

/* Enable internal pull-up for the selected pins */
// Pull-ups can be enabled or disabled disabled by the user.
// This will enable the pullups for the specified pins.
// Comment out other unwanted lines.

   // GpioCtrlRegs.GPAPUD.bit.GPIO28 = 0;    // Enable pull-up for GPIO28 (SDAA)
   // GpioCtrlRegs.GPAPUD.bit.GPIO29 = 0;       // Enable pull-up for GPIO29 (SCLA)

    GpioCtrlRegs.GPBPUD.bit.GPIO32 = 0;    // Enable pull-up for GPIO32 (SDAA)
    GpioCtrlRegs.GPBPUD.bit.GPIO33 = 0;       // Enable pull-up for GPIO33 (SCLA)

/* Set qualification for selected pins to asynch only */
// This will select asynch (no qualification) for the selected pins.
// Comment out other unwanted lines.

    //GpioCtrlRegs.GPAQSEL2.bit.GPIO28 = 3;  // Asynch input GPIO28 (SDAA)
    //GpioCtrlRegs.GPAQSEL2.bit.GPIO29 = 3;  // Asynch input GPIO29 (SCLA)

    GpioCtrlRegs.GPBQSEL1.bit.GPIO32 = 3;  // Asynch input GPIO32 (SDAA)
    GpioCtrlRegs.GPBQSEL1.bit.GPIO33 = 3;  // Asynch input GPIO33 (SCLA)

/* Configure I2C pins using GPIO regs*/
// This specifies which of the possible GPIO pins will be I2C functional pins.
// Comment out other unwanted lines.

   // GpioCtrlRegs.GPAMUX2.bit.GPIO28 = 2;   // Configure GPIO28 for SDAA operation
   // GpioCtrlRegs.GPAMUX2.bit.GPIO29 = 2;   // Configure GPIO29 for SCLA operation

    GpioCtrlRegs.GPBMUX1.bit.GPIO32 = 1;   // Configure GPIO32 for SDAA operation
    GpioCtrlRegs.GPBMUX1.bit.GPIO33 = 1;   // Configure GPIO33 for SCLA operation

    EDIS;


I2caRegs.I2CMDR.bit.IRS = 0;                     // Reset I2C module 
I2caRegs.I2CPSC.all = (SYSCLKOUT / MODCLK )- 1;  // Setting the prescalar value
I2caRegs.I2CCLKL = CLKL;                         // CLOCK LOW
I2caRegs.I2CCLKH = CLKH;                         // CLOCK HIGH
I2caRegs.I2CMDR.bit.IRS = 1;                     // Set I2C module

}

//*************************************************************************************************************

/*
 * Function twi_setAddress
 * Desc     sets slave address and enables interrupt
 * Input    none
 * Output   none
 */

void twi_setAddress(uint8_t address)
{
I2caRegs.I2CSAR = address; 
}

//**************************************************************************************************************


/*
 * Function twi_readFrom
 * Desc     attempts to become twi bus master and read a
 *          series of bytes from a device on the bus
 * Input    address: 7bit i2c device address
 *          data: pointer to byte array
 *          length: number of bytes to read into array
 * Output   number of bytes read
 */
uint8_t twi_readFrom(uint8_t address, uint8_t* data, uint8_t length, uint8_t sendStop)
{


	// ensure data will fit into buffer
	if(TWI_BUFFER_LENGTH < length){
		return 0;
	}

	// initialize buffer iteration vars
	twi_masterBufferIndex = 0;
	twi_masterBufferLength = length-1;

	// Configuring the Master in Master-Transmitter mode initially
	while(I2caRegs.I2CSTR.bit.NACK == 1)
	{

	while(I2caRegs.I2CSTR.bit.BB == 1); // Wait until the I2C bus is not busy
	I2caRegs.I2CSAR = address;          // Slave address
	I2caRegs.I2CCNT = length;           // count of number of bytes to be read from slave

	// is the address copied from I2CSAR TO I2CDXR AND THEN TO I2CXTR ?? or should we directly copy the address to I2CDXR ??

	twi_slarw = 0;                        // bit to indicate read
	twi_slarw |= address << 1;
	twi_state = TWI_SND_START;            // send start condition
	I2caRegs.I2CMDR.all = 0x0620;         // issue a START command (no stop) [ configure as Master transmitter to transmit slave address]

	// should the control word be 0X0620 or 0x2620 ??

	while(I2caRegs.I2CSTR.bit.XRDY == 0); // Wait until the transmit register is ready

	I2caRegs.I2CDXR = twi_slarw; // Put the control byte [ address + r/w bit] into transmit register

	while(I2caRegs.I2CSTR.bit.ARDY)
	{ // wait for the transmission to finish
		if(I2caRegs.I2CSTR.bit.NACK == 1)
		{ 	// if we get a NACK from slave during this transmission
			I2caRegs.I2CMDR.bit.STP = 1; // issue a STOP
			break;
		}
	}

	}

	// Configuring the Master in Master-reciever  mode to start recieving data from slave
	twi_state =  TWI_MRX;   // Master reciever state

	I2caRegs.I2CMDR.bit.STP = 1; // Set a  stop bit. Because we need to change to non repeat mode.
	I2caRegs.I2CMDR.bit.TRX = 0; // set master as reciever
	I2caRegs.I2CMDR.bit.FDF = 1; // support free data format


	while ( i < length)
	{
		while(I2caRegs.I2CSTR.bit.RRDY != 1);
		twi_masterBuffer[twi_masterBufferIndex++] = I2caRegs.I2CDRR;
		i++;
	}

	if (i== length){
		I2caRegs.I2CMDR.bit.NACKMOD = 1; // sending a NACK after last byte has been recieved.
	}

	for(i = 0; i < length; ++i){
		data[i] = twi_masterBuffer[i];
	}

	return length;
}

//**********************************************************************************************************************************************

/*
 * Function twi_writeTo
 * Desc     attempts to become twi bus master and write a
 *          series of bytes to a device on the bus
 * Input    address: 7bit i2c device address
 *          data: pointer to byte array
 *          length: number of bytes in array
 *          wait: boolean indicating to wait for write or not
 * Output   0 .. success
 *          1 .. length to long for buffer
 *          2 .. address send, NACK received
 *          3 .. data send, NACK received
 *          4 .. other twi error (lost bus arbitration, bus error, ..)
 */
uint8_t twi_writeTo(uint8_t address, uint8_t* data, uint8_t length, uint8_t wait, uint8_t sendStop)
{
	uint8_t i;
	twi_error = TWI_ERRROR_NO_ERROR;
	twi_sendStop = sendStop;

//************** Getting the buffer ready ********************************************

if(length == 0) {
		return 0;
	}

	/* Ensure data will fit into buffer */
	if(length > TWI_BUFFER_LENGTH){
		return TWI_ERROR_BUF_TO_LONG;
	}


	/* initialize buffer iteration vars */
	twi_masterBufferIndex = 0;
	twi_masterBufferLength = length;

	for(i = 0; i < length; ++i){
		twi_masterBuffer[i] = data[i];
	}



// ***************** Configuring the Master in Master-Transmitter mode initially to send control information ****************
//do
//{
while(I2caRegs.I2CSTR.bit.BB == 1); // Wait until the I2C bus is not busy
I2caRegs.I2CSAR = address;          // Slave address
I2caRegs.I2CCNT = length;           // count of number of bytes to be written to slave

// is the address copied from I2CSAR TO I2CDXR AND THEN TO I2CXTR ?? or should we directly copy the address to I2CDXR ??

twi_slarw = 1;                        // bit to indicate write
twi_slarw |= address << 1;
twi_state = TWI_SND_START;            // send start condition
I2caRegs.I2CMDR.all = 0x0E20;         // issue a START command (no stop) [ configure as Master transmitter to transmit slave address]

// should the control word be 0X0620 or 0x2620 ?? 

while(I2caRegs.I2CSTR.bit.XRDY == 0); // Wait until the transmit register is ready

I2caRegs.I2CDXR = twi_slarw; // Put the control byte [ address + r/w bit] into transmit register

while(I2caRegs.I2CSTR.bit.ARDY) 
  { // wait for the transmission to finish
    if(I2caRegs.I2CSTR.bit.NACK == 1) 
     { // if we get a NACK from slave during this transmission
       I2caRegs.I2CMDR.bit.STP = 1; // issue a STOP
       twi_error= TWI_ERROR_ADDR_NACK;
       //return twi_error;
       break;
     }
  }

if(twi_error==TWI_ERROR_ADDR_NACK )
    return twi_error;

 
//return twi_error;
 
//} while(I2caRegs.I2CSTR.bit.NACK == 1);

//********************* Configuring the master in master-transmitter mode *************************************************

I2caRegs.I2CMDR.bit.FDF = 1; // support free data format

while ( i < length)
{
while(I2caRegs.I2CSTR.bit.XRDY != 1);
I2caRegs.I2CDXR= twi_masterBuffer[i];
while(I2caRegs.I2CSTR.bit.ARDY==0);
   // wait for the transmission to finish
    if(I2caRegs.I2CSTR.bit.NACK == 1) 
     { // if we get a NACK from slave during this transmission
       I2caRegs.I2CMDR.bit.STP = 1; // issue a STOP
       twi_error= TWI_ERROR_DATA_NACK;
       break;
     }
  i++;
}

// automaticall STOP condition issued when i=length because STP= 1

return twi_error;
}

//******************************************************************************************************************************

/*
 * Function twi_attachSlaveRxEvent
 * Desc     sets function called before a slave read operation
 * Input    function: callback function to use
 * Output   none
 */
void twi_attachSlaveRxEvent( void (*function)(uint8_t*, int) )
{
  twi_onSlaveReceive = function;
}

/*
 * Function twi_attachSlaveTxEvent
 * Desc     sets function called before a slave write operation
 * Input    function: callback function to use
 * Output   none
 */
void twi_attachSlaveTxEvent( void (*function)(void) )
{
  twi_onSlaveTransmit = function;
}

//************************************************************************************************************************************


/*
 * Function twi_transmit
 * Desc     fills slave tx buffer with data
 *          must be called in slave tx event callback
 * Input    data: pointer to byte array
 *          length: number of bytes in array
 * Output   1 length too long for buffer
 *          2 not slave transmitter
 *          0 ok
 */
uint8_t twi_transmit(const uint8_t* data, uint8_t length)
{
  uint8_t i;

  twi_state =  TWI_STX;                     // Slave transmit mode
  
  // ensure data will fit into buffer
  if(TWI_BUFFER_LENGTH < length){
    return 1;
  }
  // set length and copy data into tx buffer
  twi_txBufferLength = length;
  for(i = 0; i < length; ++i){
    twi_txBuffer[i] = data[i];
  }

  return 0;
}










