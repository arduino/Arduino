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

// Clock Settings for I2C module

#define SYSCLKOUT F_CPU // Frequency of I2C i/p clk
#define MODCLK    10*10^6 // Frequency of module clk must be between 7-10Mhz, selecting 10Mhz
#define CLKL      100      // Clock high
#define CLKH      100       // clock low

static volatile uint8_t twi_state;
static volatile uint8_t twi_slarw;
static volatile uint8_t twi_sendStop;           // should the transaction end with a stop
static volatile uint8_t twi_inRepStart;         // in the middle of a repeated start

static void (*twi_onSlaveTransmit)(void);
static void (*twi_onSlaveReceive)(uint8_t*, int);

static uint8_t twi_masterBuffer[TWI_BUFFER_LENGTH];
static volatile uint8_t twi_masterBufferIndex;
static volatile uint8_t twi_masterBufferLength;

static uint8_t twi_txBuffer[TWI_BUFFER_LENGTH];
static volatile uint8_t twi_txBufferIndex;
static volatile uint8_t twi_txBufferLength;

static uint8_t twi_rxBuffer[TWI_BUFFER_LENGTH];
static volatile uint8_t twi_rxBufferIndex;

static volatile uint8_t twi_error;

__interrupt void twiISR(void);
__interrupt void twiFIFOISR(void);

/*
 * Function twi_init
 * Desc     readys twi pins and sets twi bitrate
 * Input    none
 * Output   none
 */
void twi_init(void)
{
  // initialize state
  twi_state = TWI_READY;
  twi_sendStop = true;		// default value
  twi_inRepStart = false;

  twi_masterBufferIndex = 0;
  twi_masterBufferLength = 0;
  twi_txBufferIndex = 0;
  twi_txBufferLength = 0;
  twi_rxBufferIndex = 0;


  EALLOW;

  SysCtrlRegs.PCLKCR0.bit.I2CAENCLK = 1;

  //Register I2C Interrupt Handlers
  PieVectTable.I2CINT1A = twiISR;
  PieVectTable.I2CINT2A = twiFIFOISR;
  PieCtrlRegs.PIEIER8.bit.INTx1 = 1;
  PieCtrlRegs.PIEIER8.bit.INTx2 = 1;
  IER |= 0x0080;

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
  I2caRegs.I2CIER.all = 0x24;      // Enable SCD & ARDY interrupts
  I2caRegs.I2CMDR.bit.IRS = 1;                     // Set I2C module  
  I2caRegs.I2CMDR.bit.FREE = 1;

   I2caRegs.I2CFFTX.all = 0x6043;   // Enable TXFIFO, clear TXFFINT, Disable TXFFINT
   I2caRegs.I2CFFRX.all = 0x2061;   // Enable RXFIFO, clear RXFFINT, Enable RXFFINT


}

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

	uint16_t i;

	// ensure data will fit into buffer
	if(TWI_BUFFER_LENGTH < length){
		return 0;
	}

  // wait until twi is ready, become master reciever
  while(TWI_READY != twi_state){
	continue;
	}

    while(I2caRegs.I2CMDR.bit.STP == 1); // Wait until the I2C bus is not busy

  twi_state = TWI_MRX;
  twi_sendStop = sendStop;
  // reset error state (0xFF.. no error occured)
  twi_error = 0xFF;
	// initialize buffer iteration vars
	twi_masterBufferIndex = 0;
	twi_masterBufferLength = length;

  // build sla+w, slave device address + w bit
  twi_setAddress(address);
  twi_setCount(length);

  if (true == twi_inRepStart) {
    // if we're in the repeated start state, then we've already sent the start,
    // (@@@ we hope), and the TWI statemachine is just waiting for the address byte.
    // We need to remove ourselves from the repeated start state before we enable interrupts,
    // since the ISR is ASYNC, and we could get confused if we hit the ISR before cleaning
    // up. Also, don't enable the START interrupt. There may be one pending from the 
    // repeated start that we sent outselves, and that would really confuse things.
    twi_inRepStart = false;			// remember, we're dealing with an ASYNC ISR
//    TWDR = twi_slarw;
//    TWCR = _BV(TWINT) | _BV(TWEA) | _BV(TWEN) | _BV(TWIE);	// enable INTs, but not START
    //I2caRegs.I2CIER.bit.RRDY = 1;
    I2caRegs.I2CMDR.all = 0x6C20;         // Send restart as master receiver
//    while(twi_masterBufferIndex < twi_masterBufferLength){
//    	while(I2caRegs.I2CSTR.bit.RRDY == 0);
//    	twi_masterBuffer[twi_masterBufferIndex++] = I2caRegs.I2CDRR;
//    }

  }
  else{
    // send start condition
//    TWCR = _BV(TWEN) | _BV(TWIE) | _BV(TWEA) | _BV(TWINT) | _BV(TWSTA);
	  //I2caRegs.I2CIER.bit.RRDY = 1;
      I2caRegs.I2CMDR.all = 0x6C20;         // Send restart as master receiver
//      while(twi_masterBufferIndex < twi_masterBufferLength){
//      	while(I2caRegs.I2CSTR.bit.RRDY == 0);
//      	twi_masterBuffer[twi_masterBufferIndex++] = I2caRegs.I2CDRR;
//      }
  }

//  twi_state = TWI_READY;
//  // wait for read operation to complete
  while((TWI_MRX == twi_state) &&  (twi_masterBufferIndex < length)){
    continue;
  }

  if (twi_masterBufferIndex < length){
    length = twi_masterBufferIndex;
  }

  twi_state = TWI_READY;

  // copy twi buffer to data
	for(i = 0; i < length; ++i){
		data[i] = twi_masterBuffer[i];
	}

	return length;
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
	uint8_t i;

  // ensure data will fit into buffer
  if(TWI_BUFFER_LENGTH < length){
    return 1;
	}

  // wait until twi is ready, become master transmitter
  while(TWI_READY != twi_state){
    continue;
	}
  twi_state = TWI_MTX;
  twi_sendStop = sendStop;
  // reset error state (0xFF.. no error occured)
  twi_error = 0xFF;

  // initialize buffer iteration vars
	twi_masterBufferIndex = 0;
	twi_masterBufferLength = length;

  // copy data to twi buffer
	for(i = 0; i < length; ++i){
		twi_masterBuffer[i] = data[i];
	}

  //Set the slave address
  twi_setAddress(address);

  //Set the number of bytes to transmit
  twi_setCount(length);

  //Enable interrupt to begin copying data into the FIFO
  I2caRegs.I2CFFTX.bit.TXFFIENA = 1;
  I2caRegs.I2CFFTX.bit.TXFFINTCLR = 1;


  delay(10);
//  while(1);
//
//  //Load up first byte
//  if(twi_masterBufferIndex < twi_masterBufferLength){
//    // copy data to output register
//    I2caRegs.I2CDXR = twi_masterBuffer[twi_masterBufferIndex++];
//  }

  // if we're in a repeated start, then we've already sent the START
  // in the ISR. Don't do it again.
  //
  if (true == twi_inRepStart) {
    // if we're in the repeated start state, then we've already sent the start,
    // (@@@ we hope), and the TWI statemachine is just waiting for the address byte.
    // We need to remove ourselves from the repeated start state before we enable interrupts,
    // since the ISR is ASYNC, and we could get confused if we hit the ISR before cleaning
    // up. Also, don't enable the START interrupt. There may be one pending from the 
    // repeated start that we sent outselves, and that would really confuse things.
    twi_inRepStart = false;			// remember, we're dealing with an ASYNC ISR
    //TWDR = twi_slarw;				
//    TWCR = _BV(TWINT) | _BV(TWEA) | _BV(TWEN) | _BV(TWIE);	// enable INTs, but not START
    //I2caRegs.I2CIER.bit.XRDY = 1; //Enable transmit interrupt
    if(sendStop)
	  I2caRegs.I2CMDR.all = 0x6E20; //send start and stop
    else
      I2caRegs.I2CMDR.all = 0x6620; //send start no stop

//    while(twi_masterBufferIndex < twi_masterBufferLength){
//        //wait for transmit register to be ready
//        while(I2caRegs.I2CSTR.bit.XRDY == 0);
//        // copy data to output register a
//        I2caRegs.I2CDXR = twi_masterBuffer[twi_masterBufferIndex++];
//    }
  }
  else{
	// send start condition
//    TWCR = _BV(TWINT) | _BV(TWEA) | _BV(TWEN) | _BV(TWIE) | _BV(TWSTA);	// enable INTs
	  //I2caRegs.I2CIER.bit.XRDY = 1; //Enable transmit interrupt
      if(sendStop)
	    I2caRegs.I2CMDR.all = 0x6E20; //send start and stop
      else
        I2caRegs.I2CMDR.all = 0x6620; //send start no stop
//      while(twi_masterBufferIndex < twi_masterBufferLength){
//        //wait for transmit register to be ready
//        while(I2caRegs.I2CSTR.bit.XRDY == 0);
//        // copy data to output register a
//        I2caRegs.I2CDXR = twi_masterBuffer[twi_masterBufferIndex++];
//    }
  }


  // wait for write operation to complete
  while(wait && (TWI_MTX == twi_state)){
    continue;
  }



  //Check if an error occured
  if(I2caRegs.I2CSTR.all & 0x0003)
      return 1;
  else{
      twi_state = TWI_READY;
      return 0;
  }

//  if (twi_error == 0xFF)
//    return 0;	// success
//  else if (twi_error == I2C_ARB_LOST_ERROR)
//    return 2;	// error: address send, nack received
//  else if (twi_error == I2C_NACK_ERROR)
//    return 3;	// error: data send, nack received
//  else
//    return 4;	// other twi error
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
  if(TWI_BUFFER_LENGTH < length){
    return 1;
  }

  // ensure we are currently a slave transmitter
  if(TWI_STX != twi_state){
    return 2;
  }

  // set length and copy data into tx buffer
  twi_txBufferLength = length;
  for(i = 0; i < length; ++i){
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
 * Function twi_reply
 * Desc     sends byte or readys receive line
 * Input    ack: byte indicating to ack or to nack
 * Output   none
 */
void twi_reply(uint8_t ack)
{
  // transmit master read ready signal, with or without ack
  if(ack){
//    TWCR = _BV(TWEN) | _BV(TWIE) | _BV(TWINT) | _BV(TWEA);
  }else{
//	  TWCR = _BV(TWEN) | _BV(TWIE) | _BV(TWINT);
  }
  }

/* 
 * Function twi_stop
 * Desc     relinquishes bus master status
 * Input    none
 * Output   none
 */
void twi_stop(void)
{
  // send stop condition
//  TWCR = _BV(TWEN) | _BV(TWIE) | _BV(TWEA) | _BV(TWINT) | _BV(TWSTO);
	I2caRegs.I2CMDR.bit.STP = 1;


    I2caRegs.I2CIER.bit.XRDY = 0; //Disable transmit interrupt

  // wait for stop condition to be exectued on bus
  // TWINT is not set after a stop condition!
//  while(TWCR & _BV(TWSTO)){
//    continue;
//  }
	while(I2caRegs.I2CMDR.bit.STP == 1){
		continue;
	}

  // update twi state
  twi_state = TWI_READY;
}

/* 
 * Function twi_releaseBus
 * Desc     releases bus control
 * Input    none
 * Output   none
 */
void twi_releaseBus(void)
{
  // release bus
//  TWCR = _BV(TWEN) | _BV(TWIE) | _BV(TWEA) | _BV(TWINT);

  // update twi state
  twi_state = TWI_READY;
}

__interrupt void twiISR(void)
{
    uint16_t status;

    status = I2caRegs.I2CISRC.all;


	  switch(status){
	  	  case I2C_NO_ISRC:
	  		  break;
	  	  case I2C_ARB_ISRC:
	  		  //Arbitration lost
			  twi_error = 5;
			  twi_releaseBus();
	  		  break;
	  	  case I2C_NACK_ISRC:
	  		  // Nack Recieved
			  twi_error = 6;
			  twi_stop();
	  		  break;
	  	  case I2C_ARDY_ISRC:
	  		  // Registers ready for access
	  		  break;
	  	  case I2C_RX_ISRC:
	  		  //Receive data ready
	  		  // put byte into buffer
	  		  twi_masterBuffer[twi_masterBufferIndex++] = I2caRegs.I2CDRR;
			  // ack if more bytes are expected, otherwise nack
			  if(twi_masterBufferIndex < twi_masterBufferLength){
				twi_reply(1);
			  }else{
				twi_reply(0);
			  }
	  		  break;
	  	  case I2C_TX_ISRC:
	  		  //Transmit data ready
	  		  // if there is data to send, send it, otherwise stop
	  		  if(twi_masterBufferIndex < twi_masterBufferLength){
	  			  // copy data to output register and ack
	  			I2caRegs.I2CDXR = twi_masterBuffer[twi_masterBufferIndex++];
	  			  twi_reply(1);
	  		  }
	  		  if(twi_masterBufferIndex == twi_masterBufferLength){
	  			  if (twi_sendStop)
	  				  twi_stop();
	  			  else {
	  				  twi_inRepStart = true;	// we're gonna send the START
	  				  // don't enable the interrupt. We'll generate the start, but we
	  				  // avoid handling the interrupt until we're in the next transaction,
	  				  // at the point where we would normally issue the start.
//	  				  TWCR = _BV(TWINT) | _BV(TWSTA)| _BV(TWEN) ;
 				      I2caRegs.I2CIER.bit.XRDY = 0; //Disable transmit interrupt
	  				  twi_state = TWI_READY;
	  			  }
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

__interrupt void twiFIFOISR(void)
{


    if(I2caRegs.I2CFFTX.bit.TXFFINT && I2caRegs.I2CFFTX.bit.TXFFIENA){
        //transmit fifo has room for more data
        
        //check to see if there is more data to be sent
        if(twi_masterBufferLength - twi_masterBufferIndex){


            //Copy a byte to the transmit register
            I2caRegs.I2CDXR = twi_masterBuffer[twi_masterBufferIndex++];
            //Clear TXFIFO interrupt
            I2caRegs.I2CFFTX.bit.TXFFINTCLR = 1;

        }else{
            //if not disable the interrupt within the module
            I2caRegs.I2CFFTX.bit.TXFFIENA = 0;
            //Clear TXFIFO interrupt
            I2caRegs.I2CFFTX.bit.TXFFINTCLR = 1;

            twi_state = TWI_READY;

        }


    }

    if(I2caRegs.I2CFFRX.bit.RXFFINT && I2caRegs.I2CFFRX.bit.RXFFIENA){
        //recieve fifo has data for us to read
        //read out however much data we have and copy it to the recieve buffer
        twi_masterBuffer[twi_masterBufferIndex++] = I2caRegs.I2CDRR;

         //Clear TXFIFO interrupt
        I2caRegs.I2CFFRX.bit.RXFFINTCLR = 1;

    }

    PieCtrlRegs.PIEACK.all  = 0x80;

}

