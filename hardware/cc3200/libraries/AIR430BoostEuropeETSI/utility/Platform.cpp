/**
 *  ----------------------------------------------------------------------------
 *  Platform.cpp - AIR430Boost A110x2500 radio platform port implementation.
 *  Copyright (C) 2012-2013 Anaren Microwave, Inc.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 * 
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 * 
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 *
 *  This example demonstrates usage of the AIR430BoostETSI library which uses
 *  the 430Boost-CC110L AIR Module BoosterPack created by Anaren Microwave, Inc.
 *  and available through the TI eStore, for the European Union.
 *  ----------------------------------------------------------------------------
 *
 *  Note: This file is part of AIR430Boost.
 */
#include "Platform.h"

void A110x2500SpiInit()
{
  // Setup CSn line.
  pinMode (RF_SPI_CSN, OUTPUT);
  
  #if defined(PART_TM4C1233H6PM) || defined (PART_LM4F120H5QR) || defined (PART_TM4C129XNCZAD) || defined (PART_TM4C1294NCPDT)
  // Select the correct SPI port to interface with AIR Booster Pack.
  SPI.setModule(2);
  #endif
  
  /**
   *  Setup the SPI peripheral and SCLK, MISO, and MOSI lines. This is assumed
   *  to be taken care of by the Energia SPI driver.
   *  
   *  Note: It is assumed that the peripheral clock is running at 16MHz. The
   *  radio SPI bus cannot exceed 10MHz.
   */
   #if (F_CPU == 1000000)
   SPI.setClockDivider(SPI_CLOCK_DIV1); //1 MHz SPI Clock  
   #elif (F_CPU == 16000000)
   SPI.setClockDivider(SPI_CLOCK_DIV2); //8 MHz SPI Clock
   #elif (F_CPU == 24000000)   
   SPI.setClockDivider(SPI_CLOCK_DIV4); //6 MHz SPI Clock
   #elif (F_CPU == 80000000)
   SPI.setClockDivider(SPI_CLOCK_DIV16); //5 MHz SPI Clock
   #elif (F_CPU == 120000000)
   SPI.setClockDivider(SPI_CLOCK_DIV16); //7.5 MHz SPI Clock
   #else
   #error "Radio SPI clock unable to be set < 10MHz"      
   #endif

  SPI.setDataMode(SPI_MODE0);

  /**
   *  Note: The MSP430 Launchpad's green LED is on the same pin as the MISO SPI
   *  signal. To allow for use of the green LED, on the MSP430 Launchpad, each
   *  SPI transfer (read/write) will call SPI.begin() and SPI.end() 
   *  respectively. This allows the application to use the green LED when the
   *  pin is not being used for SPI operations. No need to call SPI.begin()
   *  during initialization.
   *
   *  Note: It is assumed that if the SPI bus is to be shared, it is always
   *  fixed to a value specified in this initialization routine. THE RADIO
   *  REQUIRES A SPI CLOCK SPEED < 10MHZ.
   */
}  

void A110x2500SpiRead(unsigned char address,
                      unsigned char *buffer,
                      unsigned char count)
{
  // Change MISO pin to SPI.
  SPI.begin();
  
  digitalWrite(RF_SPI_CSN,LOW);
  // Look for CHIP_RDYn from radio.
  while (digitalRead(RF_SPI_MISO));
  
  // Write the address/command byte.
  SPI.transfer(address);
  
  // Write dummy byte(s) and read response(s).
  for (unsigned char i = 0; i < count; i++)
  {
    buffer[i] = SPI.transfer(0x00);
  }

  // Note: It is assumed that the Energia SPI driver waits until the USCIB0
  // peripheral is done being busy before returning to the caller.

  digitalWrite(RF_SPI_CSN,HIGH);
  
  // Change MISO pin to general purpose output (LED use if available).
  SPI.end();
}

void A110x2500SpiWrite(unsigned char address,
                       const unsigned char *buffer,
                       unsigned char count)
{
  // Change MISO pin to SPI.
  SPI.begin();
  
  digitalWrite(RF_SPI_CSN,LOW);
  // Look for CHIP_RDYn from radio.
  while (digitalRead(RF_SPI_MISO));
  
  // Write the address/command byte.
  SPI.transfer(address);
  
  // Write dummy byte(s) and read response(s).
  for (unsigned char i = 0; i < count; i++)
  {
    SPI.transfer(buffer[i]);
  }

  // Note: It is assumed that the Energia SPI driver waits until the USCIB0
  // peripheral is done being busy before returning to the caller.

  digitalWrite(RF_SPI_CSN,HIGH);
  
  // Change MISO pin to general purpose output (LED use if available).
  SPI.end();
}

void A110x2500Gdo0Init()
{
  pinMode (RF_GDO0, INPUT);
}

