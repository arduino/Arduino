/*
  EEPROM.cpp - EEPROM library
  Copyright (c) 2006 David A. Mellis.  All right reserved.

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

/******************************************************************************
 * Includes
 ******************************************************************************/

#include "Energia.h"
#include "driverlib/eeprom.h"
#include "EEPROM.h"

/******************************************************************************
 * Definitions
 ******************************************************************************/

/******************************************************************************
 * Constructors
 ******************************************************************************/

/******************************************************************************
 * User API
 ******************************************************************************/
#define BYTES_PER_WORD 	4
#define WORDS_PER_BLOCK 16
#define NUM_BLOCKS		32

uint8_t EEPROMClass::read(int address)
{
	uint32_t byteAddr = address - (address % BYTES_PER_WORD);
	//int block = address / (BYTES_PER_WORD * WORDS_PER_BLOCK);
	//int word = (address / BYTES_PER_WORD) % WORDS_PER_BLOCK;
	uint32_t wordVal = 0;

	ROM_EEPROMRead(&wordVal, byteAddr, 4);
	wordVal = wordVal >> (8*(address % BYTES_PER_WORD));

	return (uint8_t) wordVal;
}

void EEPROMClass::write(int address, uint8_t value)
{
	uint32_t byteAddr = address - (address % BYTES_PER_WORD);

	uint32_t wordVal = 0;
	ROM_EEPROMRead(&wordVal, byteAddr, 4);
	wordVal &= ~(0xFF << (8*(address % BYTES_PER_WORD)));
	wordVal += value << (8*(address % BYTES_PER_WORD));

	ROM_EEPROMProgram(&wordVal, byteAddr, 4);
}

void EEPROMClass::update(int address, uint8_t value)
{
  	uint8_t old_value = read(address);
  
	if(value != old_value)
		write(address, value);
}

EEPROMClass EEPROM;
