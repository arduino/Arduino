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
#include "Energia.h"  // for digitalWrite
 
#ifndef cbi
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#endif

#ifndef sbi
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
#endif

#include "wiring_private.h"
#include "pins_energia.h"
#include "twi.h"
#include "usci_isr_handler.h"
#if DEFAULT_I2C == -1 // SW I2C implementation on default port
#include "twi_sw.h"   // software I2C interface
#endif

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
#if defined(__MSP430_HAS_USCI__) || defined(__MSP430_HAS_USCI_B0__) \
 || defined(__MSP430_HAS_USCI_B1__) || defined(__MSP430_HAS_EUSCI_B0__)
static uint8_t twi_rxBuffer[TWI_BUFFER_LENGTH];
static volatile uint8_t twi_rxBufferIndex;
#endif

static volatile uint8_t twi_error;

#if defined(__MSP430_HAS_USI__)
static uint8_t twi_slarw;
static uint8_t twi_my_addr;
#endif




#if defined(UCB0CTLW0_) || defined(UCB1CTLW0_)

#if defined(__MSP430_HAS_USCI_B0__) || defined(__MSP430_HAS_EUSCI_B0__)
#define UCB0_BASE UCB0CTLW0_
#endif
#if defined(__MSP430_HAS_USCI_B1__) || defined(__MSP430_HAS_EUSCI_B1__)
#define UCB1_BASE UCB1CTLW0_
#endif
  
#define UCBxCTLW0     (*((volatile uint16_t *)((uint16_t)(I2C_baseAddress + UCB0CTLW0_  - UCB0_BASE))))
#define UCBxCTLW1     (*((volatile uint16_t *)((uint16_t)(I2C_baseAddress + UCB0CTLW1_  - UCB0_BASE))))
#define UCBxCTL0      (*((volatile uint8_t  *)((uint16_t)(I2C_baseAddress + UCB0CTLW0_+1- UCB0_BASE))))
#define UCBxCTL1      (*((volatile uint8_t  *)((uint16_t)(I2C_baseAddress + UCB0CTLW0_  - UCB0_BASE))))
#define UCBxBRW       (*((volatile uint16_t *)((uint16_t)(I2C_baseAddress + UCB0BRW_    - UCB0_BASE))))
#define UCBxBR0       (*((volatile uint8_t  *)((uint16_t)(I2C_baseAddress + UCB0BRW_    - UCB0_BASE))))
#define UCBxBR1       (*((volatile uint8_t  *)((uint16_t)(I2C_baseAddress + UCB0BRW_+1  - UCB0_BASE))))
#define UCBxMCTL      (*((volatile uint8_t  *)((uint16_t)(I2C_baseAddress + UCB0MCTL_   - UCB0_BASE))))
#define UCBxMCTLW     (*((volatile uint16_t *)((uint16_t)(I2C_baseAddress + UCB0MCTLW_  - UCB0_BASE))))
#define UCBxSTAT      (*((volatile uint8_t  *)((uint16_t)(I2C_baseAddress + UCB0STAT_   - UCB0_BASE))))
#define UCBxTBCNT     (*((volatile uint8_t  *)((uint16_t)(I2C_baseAddress + UCB0TBCNT_  - UCB0_BASE))))
#define UCBxRXBUF     (*((volatile uint8_t  *)((uint16_t)(I2C_baseAddress + UCB0RXBUF_  - UCB0_BASE))))
#define UCBxTXBUF     (*((volatile uint8_t  *)((uint16_t)(I2C_baseAddress + UCB0TXBUF_  - UCB0_BASE))))
#define UCBxABCTL     (*((volatile uint8_t  *)((uint16_t)(I2C_baseAddress + UCB0ABCTL_  - UCB0_BASE))))
#define UCBxIRCTL     (*((volatile uint8_t  *)((uint16_t)(I2C_baseAddress + UCB0IRCTL_  - UCB0_BASE))))
#define UCBxIRTCTL    (*((volatile uint8_t  *)((uint16_t)(I2C_baseAddress + UCB0IRTCTL_ - UCB0_BASE))))
#define UCBxIRRCTL    (*((volatile uint8_t  *)((uint16_t)(I2C_baseAddress + UCB0IRRCTL_ - UCB0_BASE))))
#define UCBxICTL      (*((volatile uint8_t  *)((uint16_t)(I2C_baseAddress + UCB0ICTL_   - UCB0_BASE))))
#define UCBxI2COA     (*((volatile uint8_t  *)((uint16_t)(I2C_baseAddress + UCB0I2COA_  - UCB0_BASE))))
#define UCBxI2COA0    (*((volatile uint8_t  *)((uint16_t)(I2C_baseAddress + UCB0I2COA0_ - UCB0_BASE))))
#define UCBxI2CSA     (*((volatile uint8_t  *)((uint16_t)(I2C_baseAddress + UCB0I2CSA_  - UCB0_BASE))))
#if defined(UCB0ICTL_)
#define UCBxIE        (*((volatile uint8_t  *)((uint16_t)(I2C_baseAddress + UCB0ICTL_   - UCB0_BASE))))
#define UCBxIFG       (*((volatile uint8_t  *)((uint16_t)(I2C_baseAddress + UCB0ICTL_+1 - UCB0_BASE))))
#else
#define UCBxIE        (*((volatile uint8_t  *)((uint16_t)(I2C_baseAddress + UCB0IE_     - UCB0_BASE))))
#define UCBxIFG       (*((volatile uint8_t  *)((uint16_t)(I2C_baseAddress + UCB0IFG_    - UCB0_BASE))))
#endif
#define UCBxI2CIE     (*((volatile uint8_t *)((uint16_t)(I2C_baseAddress + UCB0I2CIE_  - UCB0_BASE)))) 
#define UCBxIV        (*((volatile uint8_t *)((uint16_t)(I2C_baseAddress + UCB0IV_     - UCB0_BASE)))) 

#else // #if defined(UCB0CTLW0_)

#if defined(__MSP430_HAS_USCI__)
#define UCB0_BASE UCB0CTL0_
#define UCB1_BASE UCB1CTL0_

#define UCBxCTL0      (*((volatile uint8_t *)((uint16_t)(I2C_baseAddress + UCB0CTL0_   - UCB0_BASE)))) 
#define UCBxCTL1      (*((volatile uint8_t *)((uint16_t)(I2C_baseAddress + UCB0CTL1_   - UCB0_BASE)))) 
#define UCBxBR0       (*((volatile uint8_t *)((uint16_t)(I2C_baseAddress + UCB0BR0_    - UCB0_BASE)))) 
#define UCBxBR1       (*((volatile uint8_t *)((uint16_t)(I2C_baseAddress + UCB0BR1_    - UCB0_BASE)))) 
//#define UCBxMCTL      (*((volatile uint8_t *)((uint16_t)(I2C_baseAddress + UCB0MCTL_   - UCB0_BASE)))) 
#define UCBxSTAT      (*((volatile uint8_t *)((uint16_t)(I2C_baseAddress + UCB0STAT_   - UCB0_BASE)))) 
#define UCBxRXBUF     (*((volatile uint8_t *)((uint16_t)(I2C_baseAddress + UCB0RXBUF_  - UCB0_BASE)))) 
#define UCBxTXBUF     (*((volatile uint8_t *)((uint16_t)(I2C_baseAddress + UCB0TXBUF_  - UCB0_BASE)))) 
//#define UCBxICTL      (*((volatile uint8_t *)((uint16_t)(I2C_baseAddress + UCB0ICTL_   - UCB0_BASE)))) 
#define UCBxI2COA     (*((volatile uint8_t *)((uint16_t)(I2C_baseAddress + UCB0I2COA_  - UCB0_BASE)))) 
#define UCBxI2CSA     (*((volatile uint8_t *)((uint16_t)(I2C_baseAddress + UCB0I2CSA_  - UCB0_BASE)))) 

#define UCxIE         UC0IE
#define UCBxI2CIE     (*((volatile uint8_t *)((uint16_t)(I2C_baseAddress + UCB0I2CIE_  - UCB0_BASE)))) 
#define UCxIFG        UC0IFG
#if defined(UCB1RXIE)
#define UCBxRXIE      UCB0RXIE  ? (I2C_baseAddress == UCB0_BASE) : UCB1RXIE
#define UCBxRXIFG     UCB0RXIFG ? (I2C_baseAddress == UCB0_BASE) : UCB1RXIFG
#else
#define UCBxRXIE      UCB0RXIE
#define UCBxRXIFG     UCB0RXIFG
#endif
#if defined(UCB1TXIE)
#define UCBxTXIE      UCB0TXIE  ? (I2C_baseAddress == UCB0_BASE) : UCB1TXIE
#define UCBxTXIFG     UCB0TXIFG ? (I2C_baseAddress == UCB0_BASE) : UCB1TXIFG
#else
#define UCBxTXIE      UCB0TXIE
#define UCBxTXIFG     UCB0TXIFG
#endif

#endif //#if defined(__MSP430_HAS_USCI__)
#endif // #if defined(UCB0CTLW0_) || defined(UCB1CTLW0_)


#if DEFAULT_I2C == -1 // SW I2C implementation on default port
uint16_t I2C_baseAddress = -1;
#endif
#if DEFAULT_I2C == 0
uint16_t I2C_baseAddress = UCB0_BASE;
#endif
#if DEFAULT_I2C == 1
uint16_t I2C_baseAddress = UCB1_BASE;
#endif


/*
 * Function twi_setModule
 * Desc     Selects the I2C module to use
 * Input    Module instance
 * Output   none
 */
void twi_setModule(uint8_t _i2cModule)
{
#if DEFAULT_I2C == -1 // SW I2C implementation on default port
	if (_i2cModule == -1)
	{
		I2C_baseAddress = -1;
	}
#endif
	if (_i2cModule == 0)
	{
#if defined(__MSP430_HAS_USCI__) || defined(__MSP430_HAS_USCI_B0__) || defined(__MSP430_HAS_EUSCI_B0__)
		I2C_baseAddress = UCB0_BASE;
#endif
	}
	if (_i2cModule == 1)
	{
#if defined(__MSP430_HAS_USCI_B1__) || defined(__MSP430_HAS_EUSCI_B1__)
		I2C_baseAddress = UCB1_BASE;
#endif
	}
}

/*
 * Function twi_init_port
 * Desc     initialises the port pins
 * Input    none
 * Output   none
 */
static void twi_init_port(void)
{
#if DEFAULT_I2C == -1 // SW I2C implementation on default port
	if (I2C_baseAddress == -1)
	{
		//pinMode_int(TWISDA1, TWISDA1_SET_MODE);
		//pinMode_int(TWISCL1, TWISCL1_SET_MODE);
		i2c_sw_init();
		return;
	}
#endif
#if defined(__MSP430_HAS_USCI__)
	if (I2C_baseAddress == UCB0_BASE)
	{
		pinMode_int(TWISDA0, TWISDA0_SET_MODE);
		pinMode_int(TWISCL0, TWISCL0_SET_MODE);
		return;
	}
#endif
#if defined(__MSP430_HAS_USCI_B0__) || defined(__MSP430_HAS_EUSCI_B0__)
	if (I2C_baseAddress == UCB0_BASE)
	{
		/* Set pins to I2C mode */
		pinMode_int(TWISDA0, INPUT_PULLUP);
		if (digitalRead(TWISDA0) == 0){ // toggle SCL if SDA is low at startup
			pinMode_int(TWISCL0, INPUT_PULLUP);
			digitalWrite(TWISCL0, LOW);
			pinMode(TWISCL0, OUTPUT);
			pinMode_int(TWISCL0, INPUT_PULLUP);
		}
#if defined(__MSP430_HAS_USCI_B0__)
		if ((TWISDA0_SET_MODE & INPUT_PULLUP) == 0) {
			pinMode(TWISDA0, INPUT);          // some device do not allow the pull up to be enabled
			pinMode(TWISCL0, INPUT);
		}
#endif
		pinMode_int(TWISDA0, TWISDA0_SET_MODE);
		pinMode_int(TWISCL0, TWISCL0_SET_MODE);
	}
#endif
#if defined(__MSP430_HAS_USCI_B1__) || defined(__MSP430_HAS_EUSCI_B1__)
	if (I2C_baseAddress == UCB1_BASE)
	{
		/* Set pins to I2C mode */
		pinMode_int(TWISDA1, INPUT_PULLUP);
		if (digitalRead(TWISDA1) == 0){ // toggle SCL if SDA is low at startup
			pinMode_int(TWISCL1, INPUT_PULLUP);
			digitalWrite(TWISCL1, LOW);
			pinMode(TWISCL1, OUTPUT);
			pinMode_int(TWISCL1, INPUT_PULLUP);
		}
#if defined(__MSP430_HAS_USCI_B1__)
		if ((TWISDA1_SET_MODE & INPUT_PULLUP) == 0) {
			pinMode(TWISDA1, INPUT);          // some device do not allow the pull up to be enabled
			pinMode(TWISCL1, INPUT);
		}
#endif
		pinMode_int(TWISDA1, TWISDA1_SET_MODE);
		pinMode_int(TWISCL1, TWISCL1_SET_MODE);
	}
#endif
}

/*
 * Function twi_init
 * Desc     readys twi pins and sets twi bitrate
 * Input    none
 * Output   none
 */
void twi_init(void)
{
	// initialize state
	twi_state = TWI_IDLE;
	twi_sendStop = true;		// default value
	twi_inRepStart = false;

#if DEFAULT_I2C == -1 // SW I2C implementation on default port
	if (I2C_baseAddress == -1)
	{
		twi_init_port();
		return;
	}
#endif

#if defined(__MSP430_HAS_USI__)

	/* 100 KHz for all */
#if (F_CPU >= 16000000L) || (F_CPU >= 12000000L)
	USICKCTL = USIDIV_7;
#elif defined(CALBC1_8MHZ_) && (F_CPU >= 8000000L)
	USICKCTL = USIDIV_6;
#elif defined(CALBC1_1MHZ_) && (F_CPU >= 1000000L)
	USICKCTL = USIDIV_3;
#endif
	/* Enable USI I2C mode. */
	USICTL1 = USII2C;
	/* SDA/SCL port enable and hold in reset */
	USICTL0 = (USIPE6 | USIPE7 | USISWRST);
	/* SMCLK and SCL inactive state is high */
	USICKCTL |= (USISSEL_2 | USICKPL);
	/* Disable automatic clear control */
	USICNT |= USIIFGCC;
	/* Enable USI */
	USICTL0 &= ~USISWRST;
	/* Counter interrupt enable */
	USICTL1 |= USIIE;
#endif

#if defined(__MSP430_HAS_USCI__) \
 || defined(__MSP430_HAS_USCI_B0__) || defined(__MSP430_HAS_USCI_B1__)

    /* Calling this dummy function prevents the linker
     * from stripping the USCI interupt vectors.*/ 
    usci_isr_install();
	
	twi_init_port();

    //Disable the USCI module and clears the other bits of control register
    UCBxCTL1 = UCSWRST;

     /*
     * Configure as I2C Slave.
     * UCMODE_3 = I2C mode
     * UCSYNC = Synchronous mode
     * UCCLK = SMCLK
     */
    UCBxCTL0 = UCMODE_3 | UCSYNC;
    /*
     * Compute the clock divider that achieves less than or
     * equal to 100kHz.  The numerator is biased to favor a larger
     * clock divider so that the resulting clock is always less than or equal
     * to the desired clock, never greater.
     */
    UCBxBR0 = (unsigned char)((F_CPU / TWI_FREQ) & 0xFF);
    UCBxBR1 = (unsigned char)((F_CPU / TWI_FREQ) >> 8);

    UCBxCTL1 &= ~(UCSWRST);

#if defined(__MSP430_HAS_USCI__)
    /* Set I2C state change interrupt mask */
    UCBxI2CIE |= (UCALIE|UCNACKIE|UCSTTIE|UCSTPIE);
    /* Enable state change and TX/RX interrupts */
    UCxIE |= UCBxRXIE | UCBxTXIE;
#else
    /* Set I2C state change interrupt mask and TX/RX interrupts */
    UCBxIE |= (UCALIE|UCNACKIE|UCSTTIE|UCSTPIE|UCRXIE|UCTXIE);
#endif
#endif
#if defined(__MSP430_HAS_EUSCI_B0__) || defined(__MSP430_HAS_EUSCI_B1__)
	twi_init_port();
	
    //Disable the USCI module and clears the other bits of control register
    UCBxCTLW0 = UCSWRST;

    //Configure Automatic STOP condition generation
    UCBxCTLW1 &= ~UCASTP_3;

    /*
     * Configure as I2C master mode.
     * UCMODE_3 = I2C mode
     * UCSYNC = Synchronous mode (read/write 1 for eUSCI_B)
     * UCCLK = SMCLK
     */
    UCBxCTLW0 = UCMODE_3 | UCSSEL__SMCLK | UCSYNC | UCSWRST;

    /*
     * Compute the clock divider that achieves the fastest speed less than or
     * equal to the desired speed.  The numerator is biased to favor a larger
     * clock divider so that the resulting clock is always less than or equal
     * to the desired clock, never greater.
     */
    UCBxBRW = (unsigned short)(F_CPU / 400000);
    UCBxCTLW0 &= ~(UCSWRST);
    UCBxIE |= (UCRXIE0|UCTXIE0|UCSTTIE|UCSTPIE); // Enable I2C interrupts
#endif
}

/*
 * Function twi_setAddress
 * Desc     sets slave address and enables interrupt
 * Input    none
 * Output   none
 */
void twi_setAddress(uint8_t address)
{
#if defined(__MSP430_HAS_USI__)
	twi_my_addr = address << 1;
#endif
#if defined(__MSP430_HAS_USCI__) || defined(__MSP430_HAS_USCI_B0__) || defined(__MSP430_HAS_USCI_B1__)
	/* UCGCEN = respond to general Call */
	UCBxI2COA = (address | UCGCEN);
#endif
#if defined(__MSP430_HAS_EUSCI_B0__)
	/* UCGCEN = respond to general Call */
	UCBxI2COA0 = (address | UCOAEN | UCGCEN);
#endif
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
uint8_t twi_readFrom(uint8_t address, uint8_t* data, uint8_t length, uint8_t sendStop)
{
	uint8_t i;

#if (DEFAULT_I2C == -1)
	if (I2C_baseAddress == -1)
	{
		i2c_sw_read(address, length, data, sendStop);
		return length;
	}
#endif
#if defined(__MSP430_HAS_USI__)
	/* Disable START condition interrupt */
	USICTL1 &= ~USISTTIE;
	/* I2C master mode */
	USICTL0 |= USIMST;
#endif
#if defined(__MSP430_HAS_USCI__) || defined(__MSP430_HAS_USCI_B0__) || defined(__MSP430_HAS_USCI_B1__)
    UCBxCTL1 = UCSWRST;                      // Enable SW reset
    UCBxCTL1 |= (UCSSEL_2);                  // I2C Master, synchronous mode
    UCBxCTL0 |= (UCMST | UCMODE_3 | UCSYNC); // I2C Master, synchronous mode
    UCBxCTL1 &= ~(UCTR);                     // Configure in receive mode
    UCBxI2CSA = address;                     // Set Slave Address
    UCBxCTL1 &= ~UCSWRST;                    // Clear SW reset, resume operation
#if defined(__MSP430_HAS_USCI__)
    UCBxI2CIE |= (UCALIE|UCNACKIE|UCSTPIE);  // Enable I2C interrupts
    UCxIE |= (UCBxRXIE | UCBxTXIE);          // Enable I2C interrupts
#else
    UCBxIE |= (UCALIE|UCNACKIE|UCSTPIE|UCRXIE|UCTXIE);  // Enable I2C interrupts
#endif
#endif
#if defined(__MSP430_HAS_EUSCI_B0__) || defined(__MSP430_HAS_EUSCI_B1__)
    UCBxCTLW0 |= UCSWRST;                     // Enable SW reset
    UCBxCTLW0 |= (UCMST);                     // I2C Master, synchronous mode
    UCBxCTLW0 &= ~(UCTR);                     // Configure in receive mode
    UCBxI2CSA = address;                      // Set Slave Address
    UCBxCTLW0 &= ~UCSWRST;                    // Clear SW reset, resume operation
    UCBxIE |= (UCRXIE0|UCALIE|UCNACKIE|UCSTTIE|UCSTPIE); // Enable I2C interrupts
#endif
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

#if defined(__MSP430_HAS_USI__)
	/* build sla+w, slave device address + w bit */
	twi_slarw = 1;
	twi_slarw |= address << 1;

	// send start condition
	twi_state = TWI_SND_START;
	// this will trigger an interrupt kicking off the state machine in the isr
	USICTL1 |= USIIFG;
#endif
#if defined(__MSP430_HAS_USCI__) || defined(__MSP430_HAS_USCI_B0__) || defined(__MSP430_HAS_USCI_B1__)
    twi_state =  TWI_MRX;                     // Master receive mode
    UCBxCTL1 |= UCTXSTT;                      // I2C start condition

    if(length == 1) {                         // When only receiving 1 byte..
        while(UCBxCTL1 & UCTXSTT);            // Wait for start bit to be sent
        UCBxCTL1 |= UCTXSTP;                  // Send I2C stop condition after recv
    }
#endif
#if defined(__MSP430_HAS_EUSCI_B0__) || defined(__MSP430_HAS_EUSCI_B1__)
    twi_state =  TWI_MRX;                     // Master receive mode
    //while (UCBxCTLW0 & UCTXSTP);              // Ensure stop condition got sent
    UCBxCTLW0 |= UCTXSTT;                     // I2C start condition
#endif

	/* Wait in low power mode for read operation to complete */
	while(twi_state != TWI_IDLE){
		__bis_SR_register(LPM0_bits);
	}

	if (twi_masterBufferIndex < length)
		length = twi_masterBufferIndex;

	for(i = 0; i < length; ++i){
		data[i] = twi_masterBuffer[i];
	}

#if defined(__MSP430_HAS_USCI__) || defined(__MSP430_HAS_USCI_B0__) || defined(__MSP430_HAS_USCI_B1__)
	/* Ensure stop condition got sent before we exit. */
	while (UCBxCTL1 & UCTXSTP);
#endif
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
uint8_t twi_writeTo(uint8_t address, uint8_t* data, uint8_t length, uint8_t wait, uint8_t sendStop)
{
	uint8_t i;
	twi_error = TWI_ERRROR_NO_ERROR;
	twi_sendStop = sendStop;

#if (DEFAULT_I2C == -1)	
	if (I2C_baseAddress == -1)
	{
		if (i2c_sw_write(address, length, data, sendStop))
			return TWI_ERROR_OTHER;
		else
			return TWI_ERRROR_NO_ERROR;
	}
#endif
#if defined(__MSP430_HAS_USI__)
	/* Disable START condition interrupt */
	USICTL1 &= ~USISTTIE;
	/* I2C master mode */
	USICTL0 |= USIMST;
#endif
#if defined(__MSP430_HAS_USCI__) || defined(__MSP430_HAS_USCI_B0__) || defined(__MSP430_HAS_USCI_B1__)
    UCBxCTL1 = UCSWRST;                      // Enable SW reset
    UCBxCTL1 |= UCSSEL_2;                    // SMCLK
    UCBxCTL0 |= (UCMST | UCMODE_3 | UCSYNC); // I2C Master, synchronous mode
    UCBxCTL1 |= UCTR;                        // Configure in transmit mode
    UCBxI2CSA = address;                     // Set Slave Address
    UCBxCTL1 &= ~UCSWRST;                    // Clear SW reset, resume operation
#if defined(__MSP430_HAS_USCI__)
    UCBxI2CIE |= (UCALIE|UCNACKIE|UCSTPIE);  // Enable I2C interrupts
    UCxIE |= UCBxTXIE;                     // Enable I2C interrupts
#else
    UCBxIE |= (UCALIE|UCNACKIE|UCSTPIE|UCTXIE);  // Enable I2C interrupts
#endif
#endif
#if defined(__MSP430_HAS_EUSCI_B0__) || defined(__MSP430_HAS_EUSCI_B1__)
    UCBxCTLW0 |= UCSWRST;                     // Enable SW reset
    UCBxCTLW0 |= (UCMST | UCTR);              //  I2C Master, transmit mode
    UCBxI2CSA = address;                      // Set Slave Address
    UCBxTBCNT = length;                       // set number of bytes to transmit
    UCBxCTLW0 &= ~UCSWRST;                    // Clear SW reset, resume operation
	if(sendStop) {
		UCBxCTLW1 |= UCASTP_2;           // do generate Stop after llast Byte to send
	} else {
		UCBxCTLW1 &= ~UCASTP_2;            // do not generate Stop
	}
    UCBxIE |= (UCRXIE|UCTXIE0|UCALIE|UCNACKIE|UCSTPIE); // Enable I2C interrupts
#endif
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

#if defined(__MSP430_HAS_USI__)
	/* build sla+w, slave device address + w bit */
	twi_slarw = 0;
	twi_slarw |= address << 1;
	
	twi_state = TWI_SND_START;
	/* This will trigger an interrupt kicking off the state machine in the isr */
	USICTL1 |= USIIFG;
#endif
#if defined(__MSP430_HAS_USCI__) || defined(__MSP430_HAS_USCI_B0__) || defined(__MSP430_HAS_USCI_B1__)
    twi_state =  TWI_MTX;                     // Master Transmit mode
    UCBxCTL1 |= UCTXSTT;                      // I2C start condition
#endif
#if defined(__MSP430_HAS_EUSCI_B0__) || defined(__MSP430_HAS_EUSCI_B1__)
    twi_state =  TWI_MTX;                     // Master Transmit mode
    //while (UCBxCTLW0 & UCTXSTP);           // Ensure stop condition got sent
    UCBxCTLW0 |= UCTXSTT;                  // I2C start condition
#endif

	/* Wait for the transaction to complete */
	while(twi_state != TWI_IDLE) {
		__bis_SR_register(LPM0_bits);
	}

#if defined(__MSP430_HAS_USCI__) || defined(__MSP430_HAS_USCI_B0__) || defined(__MSP430_HAS_USCI_B1__)
	/* Ensure stop/start condition got sent before we exit. */
	if(sendStop)
	{
		while (UCBxCTL1 & UCTXSTP);	// end with stop condition
	} else {
		while (UCBxCTL1 & UCTXSTT);	// end with (re)start condition
	}
#endif

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

#if defined(__MSP430_HAS_USI__)
void send_start()
{
	USISRL = 0x00;
	USICTL0 |= USIGE+USIOE;
	USICTL0 &= ~USIGE;
	USISRL = twi_slarw;
	USICNT = (USICNT & 0xE0) + 0x08;
}
#endif

#if defined(__MSP430_HAS_USI__)
__attribute__((interrupt(USI_VECTOR)))
void USI_ISR(void)
{
	if (!(USICTL0 & USIMST) && (USICTL1 & USISTTIFG)) {
		twi_state = TWI_SL_START;
	}
	
	switch(twi_state){
	/* Master transmit / receive */
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
			USICTL0 |= USIOE;
			USISRL = 0x00;
			USICNT |=  0x01;
			twi_state = TWI_EXIT;
			break;
		}

		if(twi_slarw & 1)
			goto mtre;
		else
			goto mtpd;

		break;
	/* Prepare to receive data (N)ACK */
	case TWI_MT_PREP_DATA_ACK:
		/* SDA = input */
		USICTL0 &= ~USIOE;
		/* Bit counter = 1 */
		USICNT |= 0x01;
		twi_state = TWI_MT_PROC_DATA_ACK;
		break;
	case TWI_MT_PROC_DATA_ACK:
mtpd:
		if (USISRL & 0x01) {
			twi_error = TWI_ERROR_DATA_NACK;
			USICTL0 |= USIOE;
			USISRL = 0x00;
			USICNT |=  0x01;
			twi_state = TWI_EXIT;
			break;
		}

		if(twi_masterBufferIndex == twi_masterBufferLength) {
			USICTL0 |= USIOE;
			USISRL = 0x00;
			USICNT |=  0x01;
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
		/* SDA input */
		USICTL0 &= ~USIOE;
		/* bit counter = 8 */
		USICNT |=  0x08;
		twi_state = TWI_MR_PROC_DATA_RECV;
		break;
	case TWI_MR_PROC_DATA_RECV:
		/* SDA output */
		USICTL0 |= USIOE;

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
		USICTL0 |= USIOE;
		USISRL = 0x00;
		USICNT |=  0x01;
		twi_state = TWI_EXIT;
		break;
	/* All */
	case TWI_EXIT:
		/* Load FF into output shift register */
		USISRL = 0x0FF;
		/* Output latch transparant. MSB of USISR to the SDO pin. */
		USICTL0 |= USIGE;
		/* Latch disabled and make SDA input */
		USICTL0 &= ~(USIGE+USIOE);
		twi_state = TWI_IDLE;
		break;
	case TWI_IDLE:
                /* Nothing to do. Fall thru and clear interrupt flag. */
	default:
		break;
	}

	/* Clear counter interrupt */
	USICTL1 &= ~USIIFG;

}
#endif /* __MSP430_HAS_USI__ */

#if defined(__MSP430_HAS_USCI__) || defined(__MSP430_HAS_USCI_B0__) || defined(__MSP430_HAS_USCI_B1__)
uint16_t i2c_txrx_isr(void)  // RX/TX Service
{
	uint16_t stay_active = false;

	/* USCI I2C mode. USCI_B0 receive interrupt flag.
	 * UCBxRXIFG is set when UCBxRXBUF has received a complete character. */
#if defined(__MSP430_HAS_USCI__)
	if (UCxIFG & UCBxRXIFG){
#else
	if (UCBxIFG & UCRXIFG){
#endif
		/* Master receive mode. */
		if (twi_state ==  TWI_MRX) {
			twi_masterBuffer[twi_masterBufferIndex++] = UCBxRXBUF;
			if(twi_masterBufferIndex == twi_masterBufferLength )
				/* Only one byte left. Generate STOP condition.
				 * In master mode a STOP is preceded by a NACK */
				UCBxCTL1 |= UCTXSTP;
			if(twi_masterBufferIndex > twi_masterBufferLength ) {
				/* All bytes received. We are idle*/
				stay_active = true;
				twi_state = TWI_IDLE;
			}
		/* Slave receive mode. (twi_state = TWI_SRX) */
		} else {
			// if there is still room in the rx buffer
			if(twi_rxBufferIndex < TWI_BUFFER_LENGTH){
				// put byte in buffer and ack
				twi_rxBuffer[twi_rxBufferIndex++] = UCBxRXBUF;
			} else {
				// otherwise nack
				UCBxCTL1 |= UCTXNACK;   // Generate NACK condition
			}
		}
	}
	/* USCI I2C mode. USCI_Bx transmit interrupt flag.
	 * UCBxTXIFG is set when UCBxTXBUF is empty.*/
#if defined(__MSP430_HAS_USCI__)
	if (UCxIFG & UCBxTXIFG){
#else
	if (UCBxIFG & UCTXIFG){
#endif
		/* Master transmit mode */
		if (twi_state == TWI_MTX) {
			// if there is data to send, send it, otherwise stop 
			if(twi_masterBufferIndex < twi_masterBufferLength){
				// Copy data to output register and ack.
				UCBxTXBUF = twi_masterBuffer[twi_masterBufferIndex++];
			} else {
				if (twi_sendStop) {
					/* All done. Generate STOP condition and IDLE */
					UCBxCTL1 |= UCTXSTP;
				} else {
					twi_inRepStart = true;  // we're gonna send the START
					// don't enable the interrupt. We'll generate the start, but we 
					// avoid handling the interrupt until we're in the next transaction,
					// at the point where we would normally issue the start.
					UCBxCTL1 |= UCTXSTT;
				}
				twi_state = TWI_IDLE;
				stay_active = true;
			}
		/* Slave transmit mode (twi_state = TWI_STX) */
		} else {
			// copy data to output register
			UCBxTXBUF = twi_txBuffer[twi_txBufferIndex++];
			// if there is more to send, ack, otherwise nack
			if(twi_txBufferIndex < twi_txBufferLength){
			} else {
				UCBxCTL1 |= UCTXNACK;    // Generate NACK condition
			}
		}
	}
	return(stay_active);
}

uint16_t i2c_state_isr(void)  // I2C Service
{
	uint16_t stay_active = false;

	/* Arbitration lost interrupt flag */
#if defined(__MSP430_HAS_USCI__)
	if (UCBxSTAT & UCALIFG) {
		UCBxSTAT &= ~UCALIFG;
#else
	if (UCBxIFG & UCALIFG) {
		UCBxIFG &= ~UCALIFG;
#endif
		/* TODO: Handle bus arbitration lost */
	}
	/* Not-acknowledge received interrupt flag. 
	 * UCNACKIFG is automatically cleared when a START condition is received.*/
#if defined(__MSP430_HAS_USCI__)
	if (UCBxSTAT & UCNACKIFG) {
		UCBxSTAT &= ~UCNACKIFG;
#else
	if (UCBxIFG & UCNACKIFG) {
		UCBxIFG &= ~UCNACKIFG;
#endif
		UCBxCTL1 |= UCTXSTP;
		twi_state = TWI_IDLE;
		/* TODO: This can just as well be an address NACK.
		 * Figure out a way to distinguish between ANACK and DNACK */
		twi_error = TWI_ERROR_DATA_NACK;
		stay_active = true;
	}
	/* Start condition interrupt flag.
	 * UCSTTIFG is automatically cleared if a STOP condition is received. */
#if defined(__MSP430_HAS_USCI__)
	 if (UCBxSTAT & UCSTTIFG) {
		UCBxSTAT &= ~UCSTTIFG;
#else
	 if (UCBxIFG & UCSTTIFG) {
		UCBxIFG &= ~UCSTTIFG;
#endif
		/* UCTR is automagically set by the USCI module upon a START condition. */
		if (UCBxCTL1 &  UCTR) {
			/* Slave TX mode. */
			twi_state =  TWI_STX;
			/* Ready the tx buffer index for iteration. */
			twi_txBufferIndex = 0;
			/* Set tx buffer length to be zero, to verify if user changes it. */
			twi_txBufferLength = 0;
			/* Request for txBuffer to be filled and length to be set. */
			/* note: user must call twi_transmit(bytes, length) to do this */
			twi_onSlaveTransmit();
			/* If they didn't change buffer & length, initialize it 
			 * TODO: Is this right? Shouldn't we reply with a NACK if there is no data to send? */
			if (0 == twi_txBufferLength) {
				twi_txBufferLength = 1;
				twi_txBuffer[0] = 0x00;
			}
		} else {
			/* Slave receive mode. */
			twi_state =  TWI_SRX;
			/* Indicate that rx buffer can be overwritten and ACK */
			twi_rxBufferIndex = 0;
		}
	}
	/* Stop condition interrupt flag.
	 * UCSTPIFG is automatically cleared when a START condition is received. */
#if defined(__MSP430_HAS_USCI__)
	if (UCBxSTAT & UCSTPIFG) {
		UCBxSTAT &= ~UCSTPIFG;
#else
	if (UCBxIFG & UCSTPIFG) {
		UCBxIFG &= ~UCSTPIFG;
#endif
		if (twi_state ==  TWI_SRX) {
			/* Callback to user defined callback */
			twi_onSlaveReceive(twi_rxBuffer, twi_rxBufferIndex);
		}
		twi_state =  TWI_IDLE;
	}
	return(stay_active);
}
#endif

#if defined(__MSP430_HAS_EUSCI_B0__) || defined(__MSP430_HAS_EUSCI_B1__)
uint16_t eusci_isr_handler(void)
{
  uint16_t exit_lpm = 0;
//	switch(twi_state){
  switch(UCBxIV){
    case USCI_NONE:            // No Interrupt pending
      break;
    case USCI_I2C_UCALIFG:     // USCI I2C Mode: UCALIFG
      // enter slave transmitter mode
      twi_state = TWI_STX;
      // ready the tx buffer index for iteration
      twi_txBufferIndex = 0;
      // set tx buffer length to be zero, to verify if user changes it
      twi_txBufferLength = 0;
      // request for txBuffer to be filled and length to be set
      // note: user must call twi_transmit(bytes, length) to do this
      twi_onSlaveTransmit();
      // if they didn't change buffer & length, initialize it
      if(0 == twi_txBufferLength){
        twi_txBufferLength = 1;
        twi_txBuffer[0] = 0x00;
      }
      // transmit first byte from buffer, fall
      // copy data to output register
      UCBxTXBUF = twi_txBuffer[twi_txBufferIndex++];
      // if there is more to send, ack, otherwise nack
      if(twi_txBufferIndex < twi_txBufferLength){
        //twi_reply(1);
      } else {
		UCBxCTLW0 |= UCTXNACK;                // Generate NACK condition
      }
      // leave slave receiver state
      twi_state = TWI_IDLE;

      break;
    case USCI_I2C_UCNACKIFG:   // USCI I2C Mode: UCNACKIFG
        // leave slave receiver state
        twi_state = TWI_IDLE;
		twi_error = TWI_ERROR_DATA_NACK;
		exit_lpm = 1; //__bic_SR_register_on_exit(LPM4_bits); // Exit LPM
      break;
    case USCI_I2C_UCSTTIFG:    // USCI I2C Mode: UCSTTIFG
		UCBxIFG &= ~UCSTTIFG;
		if (twi_state ==  TWI_IDLE){
			if (UCBxCTLW0 &  UCTR){
				twi_state =  TWI_STX;      // Slave Transmit mode
				// ready the tx buffer index for iteration
				twi_txBufferIndex = 0;
				// set tx buffer length to be zero, to verify if user changes it
				twi_txBufferLength = 0;
				// request for txBuffer to be filled and length to be set
				// note: user must call twi_transmit(bytes, length) to do this
				twi_onSlaveTransmit();
				// if they didn't change buffer & length, initialize it
				if(0 == twi_txBufferLength){
					twi_txBufferLength = 1;
					twi_txBuffer[0] = 0x00;
				}
			} else {
				twi_state =  TWI_SRX;      // Slave receive mode
				// indicate that rx buffer can be overwritten and ack
				twi_rxBufferIndex = 0;
			}
		}
      break;
    case USCI_I2C_UCSTPIFG:    // USCI I2C Mode: UCSTPIFG
        //UCBxIFG &= ~UCSTPIFG;
		if (twi_state ==  TWI_SRX){
			// callback to user defined callback
			twi_onSlaveReceive(twi_rxBuffer, twi_rxBufferIndex);
		}
		twi_state =  TWI_IDLE; // IDLE mode
		/* Work around for:
		 * If the master does a read and then a write the START interrupt occurs
		 * but the RX interrupt never fires. Clearing bit 4 and 5 of UCBxCTLW0 solves this.
		 * bit 4 and 5 are however marked as reserved in the datasheet.
		 */
		UCBxCTLW0 &= ~0x18;

		exit_lpm = 1; //__bic_SR_register_on_exit(LPM4_bits); // Exit LPM
      break;
    case USCI_I2C_UCRXIFG3:    // USCI I2C Mode: UCRXIFG3
      break;
    case USCI_I2C_UCTXIFG3:    // USCI I2C Mode: UCTXIFG3
      break;
    case USCI_I2C_UCRXIFG2:    // USCI I2C Mode: UCRXIFG2
      break;
    case USCI_I2C_UCTXIFG2:    // USCI I2C Mode: UCTXIFG2
      break;
    case USCI_I2C_UCRXIFG1:    // USCI I2C Mode: UCRXIFG1
      break;
    case USCI_I2C_UCTXIFG1:    // USCI I2C Mode: UCTXIFG1
      break;
    case USCI_I2C_UCRXIFG0:    // USCI I2C Mode: UCRXIFG0
		//UCBxIFG &= ~UCRXIFG;                  // Clear USCI_B0 TX int flag
		if (twi_state ==  TWI_MRX) {      // Master receive mode
			twi_masterBuffer[twi_masterBufferIndex++] = UCBxRXBUF; // Get RX data
			if(twi_masterBufferIndex == twi_masterBufferLength )
				UCBxCTLW0 |= UCTXSTP;  // Generate I2C stop condition
			if(twi_masterBufferIndex > twi_masterBufferLength ) {
				twi_state = TWI_IDLE; //Idle
			} else {
			}
		} else {
			// if there is still room in the rx buffer
			if(twi_rxBufferIndex < TWI_BUFFER_LENGTH){
				// put byte in buffer and ack
				twi_rxBuffer[twi_rxBufferIndex++] = UCBxRXBUF;
			} else {
				// otherwise nack
				UCBxCTLW0 |= UCTXNACK;                // Generate NACK condition
			}
		}
      break;
    case USCI_I2C_UCTXIFG0:    // USCI I2C Mode: UCTXIFG0
		//UCBxIFG &= ~UCTXIFG;                  // Clear USCI_B0 TX int flag
		if (twi_state == TWI_MTX) {      // Master receive mode
			// if there is data to send, send it, otherwise stop
			if(twi_masterBufferIndex < twi_masterBufferLength){
				// copy data to output register and ack
				UCBxTXBUF = twi_masterBuffer[twi_masterBufferIndex++];                 // Transmit data at address PTxData
			}else{
			   if (twi_sendStop) {
				//UCBxCTLW0 |= UCTXSTP;                // Generate I2C stop condition
			   } else {
				 twi_inRepStart = true;   // we're gonna send the START
				 // don't enable the interrupt. We'll generate the start, but we
				 // avoid handling the interrupt until we're in the next transaction,
				 // at the point where we would normally issue the start.
				 UCBxCTLW0 |= UCTXSTT;
				 twi_state = TWI_IDLE;
				 exit_lpm = 1; //__bic_SR_register_on_exit(LPM4_bits); // Exit LPM
			   }
			}
		} else {
			// copy data to output register
			UCBxTXBUF = twi_txBuffer[twi_txBufferIndex++];
			// if there is more to send, ack, otherwise nack
			if(twi_txBufferIndex < twi_txBufferLength){
			} else {
				UCBxCTLW0 |= UCTXNACK;                // Generate NACK condition
			}
		}
      break;
    case USCI_I2C_UCBCNTIFG:   // USCI I2C Mode: UCBCNTIFG
      break;
    case USCI_I2C_UCCLTOIFG:   // USCI I2C Mode: UCCLTOIFG/
      break;
    case USCI_I2C_UCBIT9IFG:   // USCI I2C Mode: UCBIT9IFG
      break;
	}
	return (exit_lpm);
}

#if defined(__MSP430_HAS_EUSCI_B0__)
__attribute__((interrupt(USCI_B0_VECTOR)))
void USCI_B0_ISR(void)
{
	if (eusci_isr_handler()) 
		__bic_SR_register_on_exit(LPM4_bits); // Exit LPM
} 
#endif

#if defined(__MSP430_HAS_EUSCI_B1__)
__attribute__((interrupt(USCI_B1_VECTOR)))
void USCI_B1_ISR(void)
{
	if (eusci_isr_handler()) 
		__bic_SR_register_on_exit(LPM4_bits); // Exit LPM
}	
#endif

#endif // #if defined(__MSP430_HAS_EUSCI_B0__) || defined(__MSP430_HAS_EUSCI_B1__)

