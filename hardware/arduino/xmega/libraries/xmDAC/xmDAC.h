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
#ifndef _XMDAC_H_
#define _XMDAC_H_

#include "Arduino.h"
#include <stdint.h>
#include <avr/io.h>

class xmDAC {
 public:
    /** 
     * Constant for the type of reference voltage used :
     * The DAC uses the bandgap voltage as reference

     */
    const static uint8_t VREF_BANDGAP; 
    /** 
     * Constant for the type of reference voltage used :
     * The DAC uses the supply voltage  as reference
     */
    const static uint8_t VREF_VCC; 
    /** 
     * Constant for the type of reference voltage used :
     * The DAC uses the voltage supplied on input Aref on port A
     */
    const static uint8_t VREF_AREF_PORT_A; 
    /** 
     * Constant for the type of reference voltage used :
     * The DAC uses the voltage supplied on input Aref on port B
     */
    const static uint8_t VREF_AREF_PORT_B; 
    /** 
     * Constant for a port on an atxmega that provides a DAC :
     * Value for the DAC on Port A
     */
    const static uint8_t DAC_PORT_A;
    /** 
     * Constant for a port on an atxmega that provides a DAC :
     * Value for the DAC on Port B
     */
    const static uint8_t DAC_PORT_B;
    /** 
     * Constant for selecting between the Single/Dual channel mode :
     * Value for selecting the single channel mode
     */
    const static uint8_t SINGLE_CHANNEL_MODE;
    /** 
     * Constant for selecting between the Single/Dual channel mode :
     * Value for selecting the dual channel mode
     */
    const static uint8_t DUAL_CHANNEL_MODE;
    
 private:
    /** The value written to channel 0 */
    int v0;
    /** The value written to channel 1 */
    int v1;
    /** The reference voltage used for the DAC */
    uint8_t vref;
    /** The port on which we output the signal */
    uint8_t port;
    /** the channel mode that is used */
    uint8_t mode;
    /** a pointer to the DAC registers of the port */
    DAC_t *dac;
    /** this is 1 if the dac is enabled */
    bool enabled;

 public:
    /**
     * Creates a new instance of a DAC
     * @param port the DAC-port to be used
     * This must be on of the values 
     * DAC_PORT_A or DAC_PORT_B 
     * because there are never more than 2 DAC's on an xmega
     */
    xmDAC(uint8_t port);
    
    /**
     * Initialze the DAC.
     * @param mode this must be one of the contants
     * SINGLE_CHANNEL_MODE or DUAL_CHANNEL_MODE
     * @param vref select the reference voltage for the DAC
     * this must be one of the constants 
     * VREF_BANDGAP, VREF_VCC, VREF_AREF_PORT_A
     * or VREF_AREF_PORT_B
     * @return 0 if the DAC is ready for writing out
     * a value. 
     * Returns -1 if there is not DAC connected to the port
     * argument given to the constructor.
     * Returns -2 if you supplied an invalid mode argument.
     * Returns -3 if you supplied an invalid vref source argument.
     */
    int begin(uint8_t mode, uint8_t vref);
    /**
     * Disables the DAC, so the pin can be used for
     * other tasks. 
     * To reenable a DAC you have to call begin() again
     */
    void end();
    
    /**
     * Write a new value to the DAC.
     * @param ch0 the value to be set on DAC channel 0.
     * If the DAC is in SINGLE_CHANNEL_MODE this value must be
     * in the range 0x000..0xFFE. Otherwise the function returns
     * an error.
     * If the DAC is in DUAL_CHANNEL_MODE this value must also be
     * in the range 0x000..0xFFE but a value of -1 is also allowed
     * in case you want to update only DAC channel 1. 
     * @param ch1 the value to be set on DAC channel 1.
     * If the DAC is in SINGLE_CHANNEL_MODE value1 is ignored.
     * If the DAC is in DUAL_CHANNEL_MODE this value must be
     * in the range 0x000..0xFFE, but a value of -1 is also allowed
     * in case you want to update only DAC channel 0. 
     * @return 0 if the output value was successfully updated.
     * Returns -1 if DAC is not enabled. DAC.begin() was never called
     * or the DAC was suspended by DAC.end().
     * Returns -2 if DAC is in SINGLE_CHANNEL_MODE and value0
     * is outside the valid range 0x000...0xFFE.
     * Returns -3 if DAC is in DUAL_CHANNEL_MODE and either value0
     * or value1 is greater the the upper limit of the valid range 0xFFE.
     */
    int write(int ch0, int ch1=-1);
    /**
     * Tests if the DAC is enabled.
     * @return true if the DAC is ready to output a value, false otherwise.
     */
    bool isEnabled();
};


#endif
