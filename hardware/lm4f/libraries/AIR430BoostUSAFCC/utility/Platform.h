#ifndef PLATFORM_H
#define PLATFORM_H
/**
 *  ----------------------------------------------------------------------------
 *  Platform.h - AIR430Boost A110x2500 radio platform port interface.
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
#include <Energia.h>
#include <SPI.h>

extern "C" { 
  #include "CC1101.h"
}

#if defined( __MSP430FR5739__ )
#error "TODO: MSP430FR5739 FRAM Launchpad currently not supported."
#else
#define RF_SPI_MISO   14
#define RF_SPI_CSN    18
#define RF_GDO0       19
#endif

extern "C" void A110x2500SpiInit();
extern "C" void A110x2500SpiRead(unsigned char address, unsigned char *buffer, unsigned char count);
extern "C" void A110x2500SpiWrite(unsigned char address, const unsigned char *buffer, unsigned char count);
extern "C" void A110x2500Gdo0Init();

#endif  /* PLATFORM_H */
