/*
  ************************************************************************
  *	twi.c
  *
  *	Arduino core files for MSP430
  *		Copyright (c) 2012 Robert Wessels. All right reserved.
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

#include "pins_arduino.h"
#include "twi.h"

static volatile uint8_t twi_state;
static uint8_t twi_slarw;
static uint8_t twi_my_addr;

static void (*twi_onSlaveTransmit)(void);
static void (*twi_onSlaveReceive)(uint8_t*, int);

static uint8_t twi_masterBuffer[TWI_BUFFER_LENGTH];
static volatile uint8_t twi_masterBufferIndex;
static uint8_t twi_masterBufferLength;

static uint8_t twi_txBuffer[TWI_BUFFER_LENGTH];
static volatile uint8_t twi_txBufferIndex;
static volatile uint8_t twi_txBufferLength;

//static uint8_t twi_rxBuffer[TWI_BUFFER_LENGTH];
static volatile uint8_t twi_rxBufferIndex;

static volatile uint8_t twi_error;

/*
 * Function twi_init
 * Desc     readys twi pins and sets twi bitrate
 * Input    none
 * Output   none
 */
void twi_init(void)
{

	__bic_SR_register(GIE);
	P1OUT = 0xC0;                             // P1.6 & P1.7 Pullups, others to 0
	P1REN |= 0xC0;                            // P1.6 & P1.7 Pullups

	USICTL0 = USIPE6+USIPE7+USIMST+USISWRST;  // SDA/SCL
	USICTL1 = USII2C+USIIE;                   // Enable I2C mode & USI interrupt
	USICKCTL = USIDIV_7+USISSEL_2+USICKPL;    // USI clk: SCL = SMCLK/128
	USICNT |= USIIFGCC;                       // Disable automatic clear control
	USICTL0 &= ~USISWRST;                     // Enable USI
	USICTL1 &= ~USIIFG;                       // Clear pending flag
	__bis_SR_register(GIE);
}

/*
 * Function twi_setAddress
 * Desc     sets slave address and enables interrupt
 * Input    none
 * Output   none
 */
void twi_setAddress(uint8_t address)
{
	twi_my_addr = address << 1;
	//TODO: enable start detect interrupt to kick off the state machine
}

/*
 * Function twi_readFrom
 * Desc     attempts to become twi bus master and read a
 *          series of bytes from a device on the bus
 * Input    address: 7bit i2c device address
 *          data: pointer to byte array
 *          length: number of bytes to read into array
 * Output   number of bytes read
 */
uint8_t twi_readFrom(uint8_t address, uint8_t* data, uint8_t length)
{
	uint8_t i;

	USICTL0 |= USIMST; // USI master mode
	// ensure data will fit into buffer
	if(TWI_BUFFER_LENGTH < length){
		return 0;
	}

	// initialize buffer iteration vars
	twi_masterBufferIndex = 0;
	twi_masterBufferLength = length-1;  // This is not intuitive, read on...
	// On receive, the previously configured ACK/NACK setting is transmitted in
	// response to the received byte before the interrupt is signalled.
	// Therefor we must actually set NACK when the _next_ to last byte is
	// received, causing that NACK to be sent in response to receiving the last
	// expected byte of data.

	// build sla+w, slave device address + w bit
	twi_slarw = 1;
	twi_slarw |= address << 1;

	// send start condition
	twi_state = TWI_SND_START;
	// this will trigger an interrupt kicking off the state machine in the isr
	USICTL1 |= USIIFG;

	// wait for read operation to complete
	while(twi_state != TWI_IDLE){
		continue;
	}

	if (twi_masterBufferIndex < length)
		length = twi_masterBufferIndex;

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
 * Output   0 .. success
 *          1 .. length to long for buffer
 *          2 .. address send, NACK received
 *          3 .. data send, NACK received
 *          4 .. other twi error (lost bus arbitration, bus error, ..)
 */
uint8_t twi_writeTo(uint8_t address, uint8_t* data, uint8_t length, uint8_t wait)
{
	uint8_t i;
	twi_error = TWI_ERRROR_NO_ERROR;
	USICTL0 |= USIMST; // USI master mode
	if(length == 0) {
		return 0;
	}

	// ensure data will fit into buffer
	if(length > TWI_BUFFER_LENGTH){
		return TWI_ERROR_BUF_TO_LONG;
	}


	// initialize buffer iteration vars
	twi_masterBufferIndex = 0;
	twi_masterBufferLength = length;

	// copy data to twi buffer
	for(i = 0; i < length; ++i){
		twi_masterBuffer[i] = data[i];
	}

	// build sla+w, slave device address + w bit
	twi_slarw = 0;
	twi_slarw |= address << 1;
	twi_state = TWI_SND_START;
	// this will trigger an interrupt kicking off the state machine in the isr
	USICTL1 |= USIIFG;

	while(twi_state != TWI_IDLE)
	{
		continue;
	}

	return twi_error;
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
 * Function twi_start
 * Desc     sends start condition
 * Input    tx: 1 indicated tx, 0 indicated rx
 * Output   none
 */
void twi_start()
{
}

void twi_send() {
	USISRL = 0xaa;          // Load data byte
	USICNT |=  0x08;              // Bit counter = 8, start TX
}
/*
 * Function twi_stop
 * Desc     relinquishes bus master status
 * Input    none
 * Output   none
 */
void twi_stop(void)
{
	USICTL0 |= USIOE;
	USISRL = 0x00;
	USICNT |=  0x01;
}

/*
 * Function twi_releaseBus
 * Desc     releases bus control
 * Input    none
 * Output   none
 */
void twi_releaseBus(void)
{

}

#if 0
//__attribute__((interrupt(USI_VECTOR)))
void USI_ISR(void)
{
	switch(twi_state){
	// All Master
	case TWI_SND_START:// sent start condition
		USISRL = 0x00;                // Generate Start Condition...
		USICTL0 |= USIGE+USIOE;
		USICTL0 &= ~USIGE;
		USISRL = twi_slarw;
		USICNT = (USICNT & 0xE0) + 0x08;
		twi_state = TWI_RECV_SLA_ACK;

		break;
	case TWI_RECV_SLA_ACK: // reveive (N)ACK

		USICTL0 &= ~USIOE; // SDA = input
		USICNT |= 0x01; // Bit counter=1
		twi_state = TWI_PROC_SLA_ACK;
		break;
	case TWI_PROC_SLA_ACK:
		if ((USISRL & 0x01) || (twi_masterBufferIndex == twi_masterBufferLength)){
			if(twi_masterBufferIndex == 0) {
				//we haven't advance so must be an address NACK
				twi_error = TWI_ERROR_ADDR_NACK;
			} else if (twi_masterBufferIndex < twi_masterBufferLength){
				twi_error = TWI_ERROR_DATA_NACK;
			}
			twi_stop();
			twi_state = TWI_EXIT;
		} else { // ACK received
			USICTL0 |= USIOE;
			USISRL = twi_masterBuffer[twi_masterBufferIndex++];
			USICNT |=  0x08;
			twi_state = TWI_RECV_SLA_ACK;
		}
		// if receive data set counter to 8 and SDA to in
		// then go to receive data processing stage

		break;
	//case TWI_PROC_SLA_DATA:
	//	if not the last byte,
	case TWI_EXIT:
		USISRL = 0x0FF; // USISRL = 1 to drive SDA high
		USICTL0 |= USIGE; // Transparent latch enabled
		USICTL0 &= ~(USIGE+USIOE); // Latch/SDA output disabled
		twi_state = TWI_IDLE; //Idle
		break;
	}

	USICTL1 &= ~USIIFG; // !!!Clear pending flag!!!

}
#endif

void send_start()
{
	USISRL = 0x00;                // Generate Start Condition...
	USICTL0 |= USIGE+USIOE;
	USICTL0 &= ~USIGE;
	USISRL = twi_slarw;
	USICNT = (USICNT & 0xE0) + 0x08;
}

__attribute__((interrupt(USI_VECTOR)))
void foo(void)
{
	switch(twi_state){

	// Master transmit / receive
	case TWI_SND_START:
		send_start();
		twi_state = TWI_PREP_SLA_ADDR_ACK;
		break;
	case TWI_PREP_SLA_ADDR_ACK: // reveive (N)ACK
		USICTL0 &= ~USIOE; // SDA = input
		USICNT |= 0x01; // Bit counter=1
		twi_state = TWI_MT_PROC_ADDR_ACK;
		break;
	case TWI_MT_PROC_ADDR_ACK:
		if (USISRL & 0x01) {
			twi_error = TWI_ERROR_ADDR_NACK;
			twi_stop();
			twi_state = TWI_EXIT;
			break;
		}
		if(twi_slarw & 1)
			goto mtre;
		else
			goto mtpd;
		// else fall through and process data ACK;
	case TWI_MT_PREP_DATA_ACK: // reveive (N)ACK
		USICTL0 &= ~USIOE; // SDA = input
		USICNT |= 0x01; // Bit counter=1
		twi_state = TWI_MT_PROC_DATA_ACK;
		break;
	case TWI_MT_PROC_DATA_ACK:
mtpd:
		if (USISRL & 0x01) {
			twi_error = TWI_ERROR_DATA_NACK;
			twi_stop();
			twi_state = TWI_EXIT;
			break;
		}

		if(twi_masterBufferIndex == twi_masterBufferLength) {
			twi_stop();
			twi_state = TWI_EXIT;
			break;
		}

		USICTL0 |= USIOE;
		USISRL = twi_masterBuffer[twi_masterBufferIndex++];
		USICNT |=  0x08;
		twi_state = TWI_MT_PREP_DATA_ACK;
		break;
	// Master receiver
mtre:
	case TWI_MR_PREP_DATA_RECV:
		USICTL0 &= ~USIOE; // SDA input
		USICNT |=  0x08; // Bit counter = 8, RX data
		twi_state = TWI_MR_PROC_DATA_RECV;
		break;
	case TWI_MR_PROC_DATA_RECV:
		USICTL0 |= USIOE; // SDA output
		twi_masterBuffer[twi_masterBufferIndex++] = USISRL;
		if(twi_masterBufferIndex > twi_masterBufferLength ) {
			USISRL = 0xFF; // that was the last byte send NACK
			twi_state = TWI_MR_PREP_STOP;
		} else {
			USISRL = 0x00; // keep on receiving and send ACK
			twi_state = TWI_MR_PREP_DATA_RECV;
		}
		USICNT |= 0x01;
		break;
	case TWI_MR_PREP_STOP:
		twi_stop();
		twi_state = TWI_EXIT;
		break;
	// Slave receiver
	// Slave transmitter
	// All
	case TWI_EXIT:
		USISRL = 0x0FF; // USISRL = 1 to drive SDA high
		USICTL0 |= USIGE; // Transparent latch enabled
		USICTL0 &= ~(USIGE+USIOE); // Latch/SDA output disabled
		twi_state = TWI_IDLE; //Idle
		break;

	default:
		break;//should not happen handle error
	}

	USICTL1 &= ~USIIFG; // !!!Clear pending flag!!!

}
