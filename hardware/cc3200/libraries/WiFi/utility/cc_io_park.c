//*****************************************************************************
//
// Copyright (C) 2014 Texas Instruments Incorporated - http://www.ti.com/ 
// 
// 
//  Redistribution and use in source and binary forms, with or without 
//  modification, are permitted provided that the following conditions 
//  are met:
//
//    Redistributions of source code must retain the above copyright 
//    notice, this list of conditions and the following disclaimer.
//
//    Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the 
//    documentation and/or other materials provided with the   
//    distribution.
//
//    Neither the name of Texas Instruments Incorporated nor the names of
//    its contributors may be used to endorse or promote products derived
//    from this software without specific prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
//  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
//  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
//  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
//  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
//  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
//  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
//  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
//  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
//  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
//  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//*****************************************************************************

#include <stdio.h>
#include "inc/hw_types.h"
#include "driverlib/rom.h"
#include "driverlib/rom_map.h"
#include "utility/cc_io_park.h"

static void apply_io_park(u8 pin_num, 
                          enum io_park_state park_value)
{
        u32 pin_strength, pin_type;

        if(DONT_CARE != park_value) {
                /* Change the pin mode to GPIO to be safe */
                //MAP_PinModeSet(pin_num, PIN_MODE_0);
            
                /* First apply PullUp/PullDn (or no pull) according 
                to the default levels specified in the user supplied
                parking table */
                MAP_PinConfigGet(pin_num, &pin_strength, &pin_type);

                if(NO_PULL_HIZ != park_value) {
                        MAP_PinConfigSet(pin_num, pin_strength, park_value);
                } else {
                        MAP_PinConfigSet(pin_num, pin_strength, PIN_TYPE_STD);
                }

                /* One by one HiZ all the IOs, 
                  by writing the register that drives IOEN_N control 
                  pin of the IOs. This register and the signal path is 
                  always-on and hence not get lost during True-LPDS */
                MAP_PinDirModeSet(pin_num, PIN_DIR_MODE_IN);

                /* Once all the digital IOs has been made HiZ, 
                  the desired default PAD levels would be held by 
                  the weak-pulls. Input buffers would be alive 
                  (such as auto-SPI or wake-GPIOs) and would not 
                  have Iddq issue since pulls are present. */
        }
        return;
}

i32 cc_io_park_safe(struct soc_io_park *io_park_choice,
                     u8 num_pins)
{
        i32 loopcnt;

        if(NULL == io_park_choice) {
                return -1;
        }

        /* Park the IOs safely as specified by the application */
        for(loopcnt = 0; loopcnt < num_pins; loopcnt++) {
                switch(io_park_choice[loopcnt].pin_num) {
                        /* Shared SPI pins for SFLASH */
                        case PIN_11:
                        case PIN_12:
                        case PIN_13:
                        case PIN_14:
#ifdef DEBUG_MODE
                        /* JTAG pins */
                        case PIN_16:
                        case PIN_17:
                        case PIN_19:
                        case PIN_20:
#endif
                                /* Do not park these pins as they may 
                                   have external dependencies */
                                break;
                        default:
                                /* Apply the specified IO parking scheme */
                                apply_io_park(io_park_choice[loopcnt].pin_num,
                                        io_park_choice[loopcnt].park_val);

                }

        }

        /* parking the SFLASH IOs */
        HWREG(0x4402E0E8) &= ~(0x3 << 8);
        HWREG(0x4402E0E8) |= (0x2 << 8);
        HWREG(0x4402E0EC) &= ~(0x3 << 8);
        HWREG(0x4402E0EC) |= (0x2 << 8);
        HWREG(0x4402E0F0) &= ~(0x3 << 8);
        HWREG(0x4402E0F0) |= (0x2 << 8);
        HWREG(0x4402E0F4) &= ~(0x3 << 8);
        HWREG(0x4402E0F4) |= (0x1 << 8);

        return 0;

}


i32 cc_set_default(struct soc_io_park *io_park_choice,
                     u8 num_pins)
{
        i32 loopcnt;

        if(NULL == io_park_choice) {
                return -1;
        }

        /* Park the IOs safely as specified by the application */
        for(loopcnt = 0; loopcnt < num_pins; loopcnt++) {
                /* Change the pin mode to default MODE 1 */
                MAP_PinModeSet(io_park_choice[loopcnt].pin_num, 
                                PIN_MODE_1);
                /* Change the drive strength and pin type to default */
                MAP_PinConfigSet(io_park_choice[loopcnt].pin_num,
                                (PIN_STRENGTH_2MA | PIN_STRENGTH_4MA),
                                PIN_TYPE_STD);
                /* Set the PINs as input */
                MAP_PinDirModeSet(io_park_choice[loopcnt].pin_num, 
                                PIN_DIR_MODE_IN);
        }

        return 0;
}

