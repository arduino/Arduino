/*
 * This file is part of xmlibraries.
 * xmlibraries is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * xmlibraries is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Copyright 2010 Eberhard Fahle <e.fahle@wayoda.org>
 */
#include "xplSDRAM.h"

const uint16_t xplSDRAM::RAM_BASE_ADDRESS=0x4000;

xplSDRAM::xplSDRAM() {
    /* 
      Init the ports on which the SDRAM is connected 
      adress lines need to be outputs
      data lines are inputs
    */
    PORTH.DIR = 0xFF;
    PORTK.DIR = 0xFF;
    /* Port J has the data-lines in the  four lower bits */
    PORTJ.DIR = 0xF0;

    /*
      Init the EBI-module  on the xmega 
    */
    EBI.CTRL=EBI_SDDATAW_4BIT_gc 
	| EBI_LPCMODE_ALE1_gc 
	| EBI_SRMODE_ALE12_gc
	| EBI_IFMODE_3PORT_gc;
    /*
      Init the SDRAM part of the EBI-module
      The XPlain board has 8MB SDRAM on board
    */
    EBI.SDRAMCTRLA=EBI_SDROW_bm | EBI_SDCOL_10BIT_gc;

    /* Set delay counts */
    EBI.SDRAMCTRLB=EBI_MRDLY_1CLK_gc | EBI_ROWCYCDLY_1CLK_gc | EBI_RPDLY_1CLK_gc;
    EBI.SDRAMCTRLC=EBI_WRDLY_1CLK_gc | EBI_ESRDLY_1CLK_gc | EBI_ROWCOLDLY_1CLK_gc;
    /* Set refresh period and initialization delay, truncate too large values. */
    EBI.REFRESH = 0x03FF;
    EBI.INITDLY = 0x2000 & 0x3FFF;

    /* Last part of configuration and then enable Chip Select module in SDRAM mode. */
    EBI_CS3_CTRLB=(EBI_CS3_CTRLB & ~(EBI_CS_SDSREN_bm | EBI_CS_SDMODE_gm)) 
	| EBI_CS_SDMODE_NORMAL_gc;

    /* Truncate the base address to an address space boundary. */
    EBI_CS3_BASEADDR=(((uint32_t) RAM_BASE_ADDRESS)>>8) & (0xFFFF<<(EBI_CS_ASPACE_8MB_gc>>2)); 
    
    EBI_CS3_CTRLA=(EBI.CS3.CTRLA & ~(EBI_CS_ASPACE_gm | EBI_CS_MODE_gm)) 
	| EBI_CS_ASPACE_8MB_gc | EBI_CS_MODE_SDRAM_gc;
    /* Wait for SDRAM to initialize. */
    while ((EBI_CS3_CTRLB & EBI_CS_SDINITDONE_bm) == 0) ;
}

void xplSDRAM::write(uint16_t address, uint8_t value) {
    ((uint8_t *)RAM_BASE_ADDRESS)[address]=value;
}

uint8_t xplSDRAM::read(uint16_t address) {
    return (int)(((uint8_t *)RAM_BASE_ADDRESS)[address]);
}

uint8_t xplSDRAM::readFar(uint32_t address) {
    uint8_t __result;                  
    cli();
    address+=(uint32_t)0x4000;
    __asm__ volatile ("in __tmp_reg__, %3"      "\n\t"	
		      "out %3, %2"            "\n\t"   
		      "ld %0, Z"               "\n\t"   
		      "out %3, __tmp_reg__"            
		      : "=r" (__result)               
		      : "z" ((uint16_t)(address)),         
			"r" ((uint8_t)(((uint32_t)(address)) >> 16)),   
			"I" (_SFR_IO_ADDR(RAMPZ))      
		      );                              
    sei();
    return __result;  
}

void xplSDRAM::writeFar(uint32_t address, uint8_t value) {
    address+=(uint32_t)0x4000;
    cli();
   __asm__ volatile ("in __tmp_reg__, %2"      "\n\t"  
		     "out %2, %1"            "\n\t"
		     "st Z, %3"               "\n\t"	
		     "out %2, __tmp_reg__"	
		     :
		     : "z" ((uint16_t)(address)),	     
		       "r" ((uint8_t)(((uint32_t)(address)) >> 16)),	
		       "I" (_SFR_IO_ADDR(RAMPZ)),	
		       "r" ((uint8_t)value)	
		     );               
   sei();
}

//create the single static instance of this class
xplSDRAM SDRAM;    
