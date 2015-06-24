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

/*******************************************************************************
 *  cc_io_park.h - API and other data constructs to operate io parking.
 *******************************************************************************
 */
#ifndef __CC_IO_PARK_H__
#define __CC_IO_PARK_H__

#include <driverlib/pin.h>
#include "utility/cc_types.h"

enum io_park_state {
        DONT_CARE,
        NO_PULL_HIZ,
        WEAK_PULL_UP_STD = PIN_TYPE_STD_PU,
        WEAK_PULL_DOWN_STD = PIN_TYPE_STD_PD,
        WEAK_PULL_UP_OD = PIN_TYPE_OD_PU,
        WEAK_PULL_DOWN_OD = PIN_TYPE_OD_PD
};

struct soc_io_park {
        u8 pin_num;
        i8 *pin_description;
        enum io_park_state park_val;
};


i32 cc_io_park_safe(struct soc_io_park *io_park_choice,
                     u8 num_pins);


i32 cc_set_default(struct soc_io_park *io_park_choice,
                     u8 num_pins);

#endif // __CC_IO_PARK_H__
