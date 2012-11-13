/*
 * Copyright (c) 2010 by Cristian Maglie <c.maglie@bug.st>
 * SPI Master library for arduino.
 *
 * This file is free software; you can redistribute it and/or modify
 * it under the terms of either the GNU General Public License version 2
 * or the GNU Lesser General Public License version 2.1, both as
 * published by the Free Software Foundation.
 */

#include "wiring_private.h"
#include "inc/hw_memmap.h"
#include "inc/hw_ssi.h"
#include "inc/hw_types.h"
#include "driverlib/ssi.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "SPI.h"

SPIClass SPI;

uint8_t SPIClass::slaveSelect = PA_5;

void SPIClass::begin(uint8_t ssPin) {

	  SysCtlPeripheralEnable(SYSCTL_PERIPH_SSI2);
	  GPIOPinConfigure(GPIO_PB4_SSI2CLK);
	  GPIOPinConfigure(GPIO_PB5_SSI2FSS);
	  GPIOPinConfigure(GPIO_PB6_SSI2RX);
	  GPIOPinConfigure(GPIO_PB7_SSI2TX);
	  GPIOPinTypeSSI(GPIO_PORTB_BASE, GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 |
	                 GPIO_PIN_7);
	  /*
	    Polarity Phase        Mode
	  	  0 	   0   SSI_FRF_MOTO_MODE_0
	      0        1   SSI_FRF_MOTO_MODE_1
	      1        0   SSI_FRF_MOTO_MODE_2
	      1        1   SSI_FRF_MOTO_MODE_3
	  */

	  HWREG(SSI2_BASE + SSI_O_CR1) &= ~SSI_CR1_MS; //Master mode
	  SSIEnable(SSI2_BASE);
	  slaveSelect = ssPin;
	  pinMode(slaveSelect, INPUT);

}

void SPIClass::begin() {

	//default to MSP430 launchpad ssPin
	begin(PA_5);

}

void SPIClass::end(uint8_t ssPin) {

	SSIDisable(SSI2_BASE);

}

void SPIClass::end() {

	end(slaveSelect);

}

void SPIClass::setBitOrder(uint8_t ssPin, uint8_t bitOrder)
{
}
void SPIClass::setBitOrder(uint8_t bitOrder)
{
}

void SPIClass::setDataMode(uint8_t mode) {

	HWREG(SSI2_BASE + SSI_O_CR0) &=
			~(SSI_CR0_SPO | SSI_CR0_SPH);
	HWREG(SSI2_BASE + SSI_O_CR0) |= mode;

}

void SPIClass::setClockDivider(uint8_t divider){

	//value must be even
  HWREG(SSI2_BASE + SSI_O_CPSR) = divider;

}
uint8_t SPIClass::transfer(uint8_t ssPin, uint8_t data, uint8_t transferMode) {

	digitalWrite(ssPin, LOW);

	SSIDataPutNonBlocking(SSI2_BASE, data);

	while(SSIBusy(SSI2_BASE));

	SSIDataGetNonBlocking(SSI2_BASE, (unsigned long *) &data);

	if(transferMode == SPI_LAST)
		digitalWrite(ssPin, HIGH);
	else
		digitalWrite(ssPin, LOW);

	return data;

}

uint8_t SPIClass::transfer(uint8_t ssPin, uint8_t data) {

  return transfer(ssPin, data, SPI_LAST);

}

uint8_t SPIClass::transfer(uint8_t data) {

  return transfer(slaveSelect, data, SPI_LAST);

}
