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
#ifndef _XPLSDRAM_H_
#define _XPLSDRAM_H_

#include "Arduino.h"
#include <stdint.h>
#include <avr/io.h>

/** 
 * A class that enables the on board 8MB SDRAM on a XPlain board. 
 */
class xplSDRAM {
 private:
    /** Constant for the address where the SDRAM starts */
    static const uint16_t RAM_BASE_ADDRESS;    
    
 public:
    /**
     * Creates an instance of a xplSDRAM. The constructor initializes 
     * the ports on the XPlain board where the SDRAM is connected. 
     */
    xplSDRAM();

    /**
     * Returns a value for a memory location in SDRAM that is reachable 
     * using a 16-bit index-pointer. This method can only address 
     * SDRAM memory from 0x000 to 0xC012 (49152 bytes).
     * It is slightly faster than readFar.
     * @param addr the address from which the data is to be read
     * @return the value at address.  
     */
    uint8_t read(uint16_t address);

    /**
     * Writes a value to a memory location in SDRAM that is reachable 
     * using a 16-bit index-pointer. This method can only address 
     * SDRAM memory from 0x000 to 0xC012 (49152 bytes).
     * It is slightly faster than writeFar.
     * @param addr the address where the data is to be stored
     * @param value the value to write to SDRAM 
     */
    void write(uint16_t address, uint8_t value);

    /**
     * Returns a value for a memory location in SDRAM that is reachable 
     * using a 32-bit index-pointer. This method can only address 
     * SDRAM memory from 0x000 to 0x7CF000. (~8MB)
     * @param addr the address from which the data is to be read
     * @return the value at address.  
     */
    uint8_t readFar(uint32_t address);

    /**
     * Writes a value for a memory location in SDRAM that is reachable 
     * using a 32-bit index-pointer. This method can address the 
     * SDRAM memory from 0x000 to 0x7CF000. (~8MB)
     * @param addr the address where the data is to be stored
     * @param value the value to write to SDRAM 
     */
    void writeFar(uint32_t address, uint8_t value);

};

extern xplSDRAM SDRAM;

#endif
