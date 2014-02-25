/**
 * File: usi_spi.c - msp430 USI SPI implementation
 *
 * Copyright (c) 2012 by Rick Kimball <rick@kimballsoftware.com>
 * spi abstraction api for msp430
 *
 * This file is free software; you can redistribute it and/or modify
 * it under the terms of either the GNU General Public License version 2
 * or the GNU Lesser General Public License version 2.1, both as
 * published by the Free Software Foundation.
 *
 * 07-14-2012 - rick@kimballsoftware.com 
 *    Fixed MODE2/MODE3 phase problems. Added logic to deal with USI5 errata.
 */

//#include <stdint.h>
//#include <stdbool.h>
typedef unsigned char _Bool;
#include "F2802x_Device.h"     // Device Headerfile and Examples Include File

//#include "spi_430.h"



/**
 * spi_initialize() - Configure USI for SPI mode
 *
 * P2.0 - CS (active low)
 * P1.5 - SCLK
 * P1.6 - MOSI aka SIMO
 * P1.7 - MISO aka SOMI
 */

void spi_initialize(void)
{
    EALLOW;
    SysCtrlRegs.PCLKCR0.bit.SPIAENCLK = 1;      // SPI-A
    GpioCtrlRegs.GPAMUX2.bit.GPIO16 = 1;
    GpioCtrlRegs.GPAMUX2.bit.GPIO17 = 1;
    GpioCtrlRegs.GPAMUX2.bit.GPIO18 = 1;

   	SpiaRegs.SPICCR.all =0x0007;	             // Reset on, rising edge, 16-bit char bits
	SpiaRegs.SPICTL.all =0x0006;    		     // Enable master mode, normal phase,
                                                 // enable talk, and SPI int disabled.
	SpiaRegs.SPIBRR =0x00E;
    SpiaRegs.SPICCR.all =0x0087;		         // Relinquish SPI from Reset
    SpiaRegs.SPIPRI.bit.FREE = 1;                // Set so breakpoints don't disturb xmission
}

void spi_disable(void) {
//    USICTL0 |= USISWRST;        // put USI in reset mode

    SpiaRegs.SPICCR.bit.SPISWRESET = 0;
}

/**
 * spi_send() - send a byte and recv response
 */
uint8_t spi_send(const uint8_t data)
{
   while(SpiaRegs.SPISTS.bit.BUFFULL_FLAG == 1)
   {
   }
   SpiaRegs.SPITXBUF = data << 8;
   while(SpiaRegs.SPISTS.bit.INT_FLAG != 1)
   {
   }
   return(SpiaRegs.SPIRXBUF & 0xFF);

}

/**
 * spi_set_divisor() - set new clock divider for USI
 *
 * There are a fixed set of valid values for clock divisors
 * see the slau144 for details. DIV by 2/4/8 .. 128
 */

void spi_set_divisor(const uint16_t clkdiv)
{
 //   USICTL0 |= USISWRST;        // put USI in reset mode
   // USICKCTL = (USICKCTL & ~SPI_DIV_MASK) | clkdiv;
    //USICTL0 &= ~USISWRST;        // release for operation
	
    SpiaRegs.SPICCR.bit.SPISWRESET = 0;
	SpiaRegs.SPIBRR = clkdiv-1;
    SpiaRegs.SPICCR.bit.SPISWRESET = 1;
	
}

/**
 * spi_set_bitorder (enum LSBFIRST=0|MSBFIRST=1)
 *
 * Note: this should use the LSBFIRST/MSBFIRST defines however
 * it doesn't to allow this code to compile without Energia.
 *
 */
void spi_set_bitorder(const uint8_t order)
{
//    USICTL0 |= USISWRST;        // put USI in reset mode
//    USICTL0 = (USICTL0 & ~SPI_LSBMSB_MASK) | ((order == 1 /*MSBFIRST*/) ? 0 : USILSB); /* MSBFIRST = 1 */
//    USICTL0 &= ~USISWRST;       // release for operation
}

/**
 * spi_set_datamode() - Motorola SPI Mode 0 ... 3
 *
 * mode is really an enum SPI_MODE0 ... SPI_MODE3 as defined in
 * the Energia header file.
 */
void spi_set_datamode(const uint8_t mode)
{
    //USICTL0 |= USISWRST;        // put USI in reset mode while we make changes
	EALLOW;
    SpiaRegs.SPICCR.bit.SPISWRESET = 0;
    switch(mode) {
    case 0:                   /* SPI_MODE0 */
       // USICKCTL &= ~USICKPL; /* CPOL=0 */
        //USICTL1  |= USICKPH;  /* CPHA=0 */
		
		SpiaRegs.SPICCR.bit.CLKPOLARITY = 0;
		SpiaRegs.SPICTL.bit.CLK_PHASE = 0;
        break;

    case 1:                   /* SPI_MODE1 */
       // USICKCTL &= ~USICKPL; /* CPOL=0 */
        //USICTL1  &= ~USICKPH; /* CPHA=1 */
		
		SpiaRegs.SPICCR.bit.CLKPOLARITY = 0;
		SpiaRegs.SPICTL.bit.CLK_PHASE = 1;
        break;

    case 2:                   /* SPI_MODE2 */
        //USICKCTL |= USICKPL;  /* CPOL=1 */
        //USICTL1  |= USICKPH;  /* CPHA=0 */
		
		SpiaRegs.SPICCR.bit.CLKPOLARITY = 1;
		SpiaRegs.SPICTL.bit.CLK_PHASE = 0;
        break;

    case 4:                   /* SPI_MODE3 */
        //USICKCTL |= USICKPL;  /* CPOL=1 */
        //USICTL1  &= ~USICKPH; /* CPHA=1 */
		
		SpiaRegs.SPICCR.bit.CLKPOLARITY = 1;
		SpiaRegs.SPICTL.bit.CLK_PHASE = 1;
        break;

    default:
        break;
    }
    //USICTL0 &= ~USISWRST;       // release for operation
	SpiaRegs.SPICCR.bit.SPISWRESET = 1;
    EDIS;


}

