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

// TODO: No support to I2C repeat mode yet.

#include <math.h>
#include <stdlib.h>

#include "wiring_private.h"
#include "twi.h"

// TODO: Don't forget to set this. FIFO mode uses interrupts. Non-FIFO mode uses polling.
#define I2C_FIFO_MODE true

// Clock Settings for I2C module

#define SYSCLKOUT F_CPU // Frequency of I2C i/p clk
#define MODCLK    10*10^6 // Frequency of module clk must be between 7-10Mhz, selecting 10Mhz
#define CLKL      100      // Clock high
#define CLKH      100       // clock low

static void (*twi_onSlaveTransmit)(void);
static void (*twi_onSlaveReceive)(uint8_t*, int);

static uint8_t twi_rxBuffer[TWI_BUFFER_LENGTH];
static volatile uint8_t twi_rxBufferIndex;
static volatile uint8_t twi_rxBufferLength;

static uint8_t twi_txBuffer[TWI_BUFFER_LENGTH];
static volatile uint8_t twi_txBufferIndex;
static volatile uint8_t twi_txBufferLength;

__interrupt void twiISR(void);
#if I2C_FIFO_MODE
__interrupt void twiFIFOISR(void);
#endif

/*
 * Function twi_init
 * Desc     readys twi pins and sets twi bitrate
 * Input    none
 * Output   none
 */
void twi_init(void)
{
  twi_txBufferIndex = 0;
  twi_txBufferLength = 0;
  twi_rxBufferIndex = 0;
    twi_rxBufferLength = 0;

  EALLOW;

#ifdef TMS320F28377S
    CpuSysRegs.PCLKCR9.bit.I2C_A = 1;
#else
  SysCtrlRegs.PCLKCR0.bit.I2CAENCLK = 1;
#endif

  //Register I2C Interrupt Handlers
#ifdef TMS320F28377S
    PieVectTable.I2CA_INT = &twiISR;
#if I2C_FIFO_MODE
    PieVectTable.I2CA_FIFO_INT = &twiFIFOISR;
#endif //I2C_FIFO_MODE
#else
    PieVectTable.I2CINT1A = &twiISR;
#if I2C_FIFO_MODE
    PieVectTable.I2CINT2A = &twiFIFOISR;
#endif //I2C_FIFO_MODE
#endif //TMS320F28377S
  PieCtrlRegs.PIEIER8.bit.INTx1 = 1;
#if I2C_FIFO_MODE
  PieCtrlRegs.PIEIER8.bit.INTx2 = 1;
#endif
  IER |= 0x0080;

#ifdef TMS320F28377S
/* Enable internal pull-up for the selected pins */
// Pull-ups can be enabled or disabled disabled by the user.
// This will enable the pullups for the specified pins.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPBPUD.bit.GPIO42 = 0;        // Enable pull-up for GPIO42 (SDAA)
    GpioCtrlRegs.GPBPUD.bit.GPIO43 = 0;        // Enable pull-up for GPIO43 (SCLA)

/* Set qualification for selected pins to asynch only */
// This will select asynch (no qualification) for the selected pins.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPBQSEL1.bit.GPIO42 = 3;    // Asynch input GPIO42 (SDAA)
    GpioCtrlRegs.GPBQSEL1.bit.GPIO43 = 3;    // Asynch input GPIO43 (SCLA)

/* Configure I2C pins using GPIO regs*/
// This specifies which of the possible GPIO pins will be I2C functional pins.
// Comment out other unwanted lines.

    // Configure GPIO42 for SDAA operation
    // Configure GPIO43 for SCLA operation
    GpioCtrlRegs.GPBGMUX1.bit.GPIO42 = 1;
    GpioCtrlRegs.GPBGMUX1.bit.GPIO43 = 1;
    GpioCtrlRegs.GPBMUX1.bit.GPIO42 = 2;
    GpioCtrlRegs.GPBMUX1.bit.GPIO43 = 2;
#else
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
#endif

    EDIS;

    // Commence I2C register set-up
    I2caRegs.I2CMDR.bit.IRS = 0;                     // Reset & disable I2C module
  I2caRegs.I2CPSC.all = (SYSCLKOUT / MODCLK )- 1;  // Setting the prescalar value
  I2caRegs.I2CCLKL = CLKL;                         // CLOCK LOW
  I2caRegs.I2CCLKH = CLKH;                         // CLOCK HIGH
//    I2caRegs.I2CIER.bit.SCD = 1;                    // Stop condition detected interrupt enable
#if !I2C_FIFO_MODE
//    I2caRegs.I2CIER.bit.XRDY = 1;                   // Transmit-data-ready interrupt enable, do NOT use with FIFO
//    I2caRegs.I2CIER.bit.RRDY = 1;                   // Receive-data-ready interrupt enable, do NOT use with FIFO
#endif
    I2caRegs.I2CMDR.bit.FREE = 1;                    // I2C module continues to run at a breakpoint

#if I2C_FIFO_MODE
    I2caRegs.I2CFFTX.bit.I2CFFEN = 1;                // I2C FIFO mode enable bit
    I2caRegs.I2CFFTX.bit.TXFFRST = 1;                // enable transmit FIFO operation
    I2caRegs.I2CFFTX.bit.TXFFIL = 1;                 // transmit FIFO interrupt level
    // we do not set TXFFIENA here yet because it will over-trigger the FIFO ISR (TXFFIENA & TXFFINT == 1 triggers ISR)

    I2caRegs.I2CFFRX.bit.RXFFIENA = 1;               // enable receive FIFO interrupt operation
    I2caRegs.I2CFFRX.bit.RXFFIL = 1;                 // receive FIFO interrupt level
    I2caRegs.I2CFFRX.bit.RXFFRST = 1;                // enable receive FIFO operation
    // RXFFRST must be set after RXFFIL or else RXINT flag is set too early (check TRM)
#endif
    I2caRegs.I2CMDR.bit.IRS = 1;                     // Enable I2C module
}

/*
 * Function twi_setAddress
 * Desc     sets slave address and enables interrupt
 * Input    none
 * Output   none
 */

void twi_setAddress(uint8_t address)
{
#ifdef TMS320F28377S
    I2caRegs.I2CSAR.bit.SAR = address;
#else
    I2caRegs.I2CSAR = address; 
#endif
}

void twi_setCount(uint8_t count)
{
	I2caRegs.I2CCNT = count;
}

/*
 * Function twi_readFrom
 * Desc     attempts to become twi bus master and read a
 *          series of bytes from a device on the bus
 * Input    address: 7bit i2c device address
 *          data: pointer to byte array
 *          length: number of bytes to read into array
 *          sendStop: Boolean indicating whether to send a stop at the end
 * Output   number of bytes read
 */
uint8_t twi_readFrom(uint8_t address, uint8_t* data, uint8_t length, uint8_t sendStop)
{
	// ensure data will fit into buffer
    if(TWI_BUFFER_LENGTH < length)
    {
		return 0;
	}

    // wait until twi is ready
    while(I2caRegs.I2CSTR.bit.BB == 1);
    while(I2caRegs.I2CMDR.bit.STP == 1); // Wait until the I2C bus is not busy

	// initialize buffer iteration vars
    twi_rxBufferIndex = 0;
    twi_rxBufferLength = length;

  // build sla+w, slave device address + w bit
  twi_setAddress(address);
  twi_setCount(length);

    if(sendStop)
    {
    	I2caRegs.I2CMDR.bit.STP = 1;                  // generate STOP condition when internal data counter -> 0
    }
    I2caRegs.I2CMDR.bit.MST = 1;                  // Master mode
    I2caRegs.I2CMDR.bit.TRX = 0;                  // not transmitter
    I2caRegs.I2CMDR.bit.STT = 1;                  // generate START condition on I2C bus
    I2caRegs.I2CMDR.bit.IRS = 1;                  // I2C module enabled
    // after STT, address in I2CSAR is automatically sent

#if !I2C_FIFO_MODE
    uint16_t i;

    while(twi_rxBufferIndex < twi_rxBufferLength)
    {
    	// wait until receive register ready
        while(I2caRegs.I2CSTR.bit.RRDY == 0);
        // put receive register data into receive buffer
        twi_rxBuffer[twi_rxBufferIndex++] = I2caRegs.I2CDRR.all;
  }

    if (twi_rxBufferIndex < length)
    {
        length = twi_rxBufferIndex;
  }

  // copy twi buffer to data
    for(i = 0; i < length; ++i)
    {
        data[i] = twi_rxBuffer[i];
	}

	return length;
#else
    return 0; // in FIFO INT mode, we will update TwoWire::rxBufferLength another way
#endif
}

/*
 * Function twi_writeTo
 * Desc     attempts to become twi bus master and write a
 *          series of bytes to a device on the bus
 * Input    address: 7bit i2c device address
 *          data: pointer to byte array
 *          length: number of bytes in array
 *          wait: boolean indicating to wait for write or not
 *          sendStop: boolean indicating whether or not to send a stop at the end
 * Output   0 .. success
 *          1 .. length to long for buffer
 *          2 .. address send, NACK received
 *          3 .. data send, NACK received
 *          4 .. other twi error (lost bus arbitration, bus error, ..)
 */
uint8_t twi_writeTo(uint8_t address, uint8_t* data, uint8_t length, uint8_t wait, uint8_t sendStop)
{
  // ensure data will fit into buffer
    if(TWI_BUFFER_LENGTH < length)
    {
    return 1;
	}

    // wait until twi is ready
    while(I2caRegs.I2CSTR.bit.BB == 1);
    while(I2caRegs.I2CMDR.bit.STP == 1); // Wait until the I2C bus is not busy

  // initialize buffer iteration vars
    twi_txBufferIndex = 0;
    twi_txBufferLength = length;

  //Set the slave address
  twi_setAddress(address);

  //Set the number of bytes to transmit
  twi_setCount(length);

	I2caRegs.I2CMDR.bit.MST = 1;    //Master mode
	I2caRegs.I2CMDR.bit.TRX = 1;    //I2C module is a transmitter
	I2caRegs.I2CMDR.bit.STT = 1;    //generate START condition on I2C bus
	I2caRegs.I2CMDR.bit.IRS = 1;    //I2C module enabled
    if(sendStop)
	{
	    I2caRegs.I2CMDR.bit.STP = 1;
	}
    // after STT, address in I2CSAR is automatically sent

#if I2C_FIFO_MODE
    // neccessary to trigger a TXFFINT flag the first time
	I2caRegs.I2CFFTX.bit.TXFFIENA = 1;               // enable transmit FIFO interrupt operation
    I2caRegs.I2CFFTX.bit.TXFFINTCLR = 1;
#endif

#if !I2C_FIFO_MODE
    uint8_t i;

    // copy data to twi buffer
    for(i = 0; i < length; ++i)
    {
        twi_txBuffer[i] = data[i];
  }

    while(twi_txBufferIndex < twi_txBufferLength)
    {
        //wait for transmit register to be ready
        while(I2caRegs.I2CSTR.bit.XRDY == 0);
        // copy data to output register
        I2caRegs.I2CDXR.all = twi_txBuffer[twi_txBufferIndex++];
  }
#endif
    return length;
}

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

  // ensure data will fit into buffer
    if(TWI_BUFFER_LENGTH < length)
    {
    return 1;
  }

  // ensure we are currently a slave transmitter
    if(I2caRegs.I2CMDR.bit.TRX == 1 && I2caRegs.I2CMDR.bit.MST == 0)
    {
    return 2;
  }

  // set length and copy data into tx buffer
  twi_txBufferLength = length;
    for(i = 0; i < length; ++i)
    {
    twi_txBuffer[i] = data[i];
}

  return 0;
}

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

/*
 * Function twi_stop
 * Desc     relinquishes bus master status
 * Input    none
 * Output   none
 */
void twi_stop(void)
{
	I2caRegs.I2CMDR.bit.STP = 1;

//    I2caRegs.I2CIER.bit.XRDY = 0; //Disable transmit interrupt
//    while(I2caRegs.I2CMDR.bit.STP == 1)
//    {
//    continue;
//  }
}

__interrupt void twiISR(void)
{
    uint16_t status;

    status = I2caRegs.I2CISRC.all;

    switch(status)
    {
	  	  case I2C_NO_ISRC:
	  		  break;
	  	  case I2C_ARB_ISRC:
	  		  //Arbitration lost
	  		  break;
	  	  case I2C_NACK_ISRC:
	  		  // Nack Recieved
	  		  break;
	  	  case I2C_ARDY_ISRC:
	  		  // Registers ready for access
	  		  break;
	  	  case I2C_RX_ISRC:
	  		  //Receive data ready
	  		  // put byte into buffer
#ifdef TMS320F28377S
              twi_rxBuffer[twi_rxBufferIndex++] = I2caRegs.I2CDRR.bit.DATA;
#else
              twi_rxBuffer[twi_rxBufferIndex++] = I2caRegs.I2CDRR;
#endif
	  		  break;
	  	  case I2C_TX_ISRC:
	  		  //Transmit data ready
	  		  // if there is data to send, send it, otherwise stop
              if(twi_txBufferIndex < twi_txBufferLength)
              {
	  			  // copy data to output register and ack
#ifdef TMS320F28377S
                   I2caRegs.I2CDXR.bit.DATA = twi_txBuffer[twi_txBufferIndex++];
#else
                   I2caRegs.I2CDXR = twi_txBuffer[twi_txBufferIndex++];
#endif
	  		  }
	  		  break;
	  	  case I2C_SCD_ISRC:
	  		  //Stop condition detected
	  		  break;
	  	  case I2C_AAS_ISRC:
	  		  //addressed as slave
	  		  break;
	  }


	PieCtrlRegs.PIEACK.all  = 0x80;

}      

#if I2C_FIFO_MODE
__interrupt void twiFIFOISR(void)
{
    if(I2caRegs.I2CFFTX.bit.TXFFINT && I2caRegs.I2CFFTX.bit.TXFFIENA)
    {
		accesstxBuffer(twi_txBuffer, twi_txBufferIndex);
        //transmit fifo has room for more data
        //check to see if there is more data to be sent
            //Copy a byte to the transmit register
    	if(twi_txBufferIndex < twi_txBufferLength)
    	{
#ifdef TMS320F28377S
			I2caRegs.I2CDXR.bit.DATA = twi_txBuffer[twi_txBufferIndex++];
#else
			I2caRegs.I2CDXR = twi_txBuffer[twi_txBufferIndex++];
#endif
    	}
    	else
    	{
    		// disable interrupt or else it keeps triggering
            I2caRegs.I2CFFTX.bit.TXFFIENA = 0;
    	}
            //Clear TXFIFO interrupt
            I2caRegs.I2CFFTX.bit.TXFFINTCLR = 1;
        }

    if(I2caRegs.I2CFFRX.bit.RXFFINT && I2caRegs.I2CFFRX.bit.RXFFIENA)
    {
        //recieve fifo has data for us to read
        //read out however much data we have and copy it to the recieve buffer
    	if(twi_rxBufferIndex < twi_rxBufferLength)
    	{
#ifdef TMS320F28377S
    		twi_rxBuffer[twi_rxBufferIndex++] = I2caRegs.I2CDRR.bit.DATA;
#else
    		twi_rxBuffer[twi_rxBufferIndex++] = I2caRegs.I2CDRR;
#endif
    	}
    	updaterxBuffer(twi_rxBuffer, twi_rxBufferIndex);
        //Clear RXFIFO interrupt
        I2caRegs.I2CFFRX.bit.RXFFINTCLR = 1;

    }

    PieCtrlRegs.PIEACK.all  = 0x80;

}
#endif
