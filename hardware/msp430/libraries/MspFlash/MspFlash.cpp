/*
  MspFlash.h - Read/Write flash memory library for MSP430 Energia 
  Copyright (c) 2012 Peter Brier.  All right reserved.

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
#include "MspFlash.h"
#include <msp430.h>
#include <Energia.h>

// The Flash clock must be between 200 and 400 kHz to operate correctly
// TODO: calculate correct devider (0..64) depending on clock frequenct (F_CPU)
// Now we set F_CPU/64 is 250khz at F_CPU = 16MHz

#define FLASHCLOCK FSSEL1+((F_CPU/400000L) & 63); // SCLK

// erase flash, make sure pointer is in the segment you wish to erase, otherwise you may erase you program or some data
void MspFlashClass::erase(unsigned char *flash)
{
  disableWatchDog();        // Disable WDT
#ifdef __MSP430_HAS_FLASH2__
  FCTL2 = FWKEY+FLASHCLOCK; // SMCLK/2
  FCTL3 = FWKEY;            // Clear LOCK
  FCTL1 = FWKEY+ERASE;      //Enable segment erase
  *flash = 0;               // Dummy write, erase Segment
  FCTL3 = FWKEY+LOCK;       // Done, set LOCK
#else
  while (FCTL3 & BUSY)      // Wait for till busy flag is 0
  {
    __no_operation();
  }

  FCTL3 = FWKEY;            // Clear Lock bit
  FCTL1 = FWKEY+ERASE;      // Set Erase bit
  *flash = 0;               // Dummy write, erase Segment

  while (FCTL3 & BUSY)      // Wait for till busy flag is 0
  {
    __no_operation();
  }

  FCTL3 = FWKEY+LOCK;       // Set LOCK bit
#endif
  enableWatchDog();         // Enable WDT
}

// load from memory, at segment boundary
void MspFlashClass::read(unsigned char *flash, unsigned char *dest, int len)
{
  while(len--)
   *(dest++) = *(flash++); 
}

// save in to flash (at segment boundary)
void MspFlashClass::write(unsigned char *flash, unsigned char *src, int len)
{
 disableWatchDog();        // Disable WDT
#ifdef __MSP430_HAS_FLASH2__
 FCTL2 = FWKEY+FLASHCLOCK; // SMCLK/2 
 FCTL3 = FWKEY;            // Clear LOCK
 FCTL1 = FWKEY+WRT;        // Enable write
 while(len--)              // Copy data
   *(flash++) = *(src++);
 FCTL1 = FWKEY;            //Done. Clear WRT
 FCTL3 = FWKEY+LOCK;       // Set LOCK
#else
 FCTL3 = FWKEY;            // Clear Lock bit
 FCTL1 = FWKEY+WRT;        // Set Erase bit
 while(len--)              // Copy data
   *(flash++) = *(src++);
 FCTL1 = FWKEY;            // Done. Clear WRT
 FCTL3 = FWKEY+LOCK;       // Set LOCK
#endif
 enableWatchDog();         // Enable WDT
}

MspFlashClass Flash;
