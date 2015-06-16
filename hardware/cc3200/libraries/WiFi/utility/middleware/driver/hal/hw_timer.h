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
 *  hw_timer.h - API and other data constructs to operate HW timer.
 *******************************************************************************
 */
#ifndef _HW_TIMER_H_
#define _HW_TIMER_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "util64.h"

/* Candidates for system level common header file */

typedef void (*cc_cb_fn)(cc_hndl);

enum cc_hw_timer_mode {
        
        HW_TIMER_NOT_USED = 1, /* Need to be removed from here */
        HW_TIMER_ONE_SHOT,
        HW_TIMER_PERIODIC,
        HW_TIMER_MONOTONE
};

/* Operations supported by hardware timer (HWT) on system. A HWT can be either
   be 64bits or 32bits capable but not both. Therefore, the HWT  driver should 
   provide either all 64bits or 32bits routines in conjunction with all common
   functions.

   Unless otherwise stated, operations returns 0 on success and -1 on errors.
*/
struct hw_timer_ops {
        
        /* Activate HW Timer in specified mode for indicated absolute expiry */
        i32  (*start32)(cc_hndl hndl, u32 expires, enum cc_hw_timer_mode mode);
        i32  (*start64)(cc_hndl hndl, struct u64_val *expires, 
                        enum cc_hw_timer_mode mode);

        /* Update a running HW Timer with a new absolute expiry value */
        i32  (*update_exp32)(cc_hndl hndl, u32 expires);
        i32  (*update_exp64)(cc_hndl hndl, struct u64_val *expires);

        /* De-activate a running HE Timer */
        i32  (*stop)(cc_hndl hndl);

        bool (*is_running)(cc_hndl hndl);

        /* Get time in terms of HW ticks remaining prior to HW Timer expiry */
        i32  (*get_remaining32)(cc_hndl hndl, u32 *remaining);
        i32  (*get_remaining64)(cc_hndl hndl, struct u64_val *remaining);

        /* Get time in terms of HW ticks at the instant of API invocation */
        i32  (*get_current32)(cc_hndl hndl, u32 *current);
        i32  (*get_current64)(cc_hndl hndl, struct u64_val *current);

        /* Returns number of rollovers since, HW Timer was activated */
        u32  (*get_rollovers)(cc_hndl hndl);

        /* Returns operating frequency in HZ of HW Timer */ 
        u32  (*get_frequency)(cc_hndl hndl);

        /* Install callback information, if not done as part of module init */
        i32  (*register_cb)(cc_hndl hwt, cc_cb_fn user_cb, cc_hndl cb_param);
};

#define DEF_HWT32_OPS(start32,   update_exp32, stop, is_running,        \
                      get_rem32, get_cur32, get_rolls, get_freq,        \
                      reg_cb)                                           \
        static struct hw_timer_ops hwt_ops = {                          \
                start32, NULL, update_exp32, NULL, stop, is_running,    \
                get_rem32, NULL, get_cur32, NULL, get_rolls,            \
                get_freq, reg_cb                                        \
        };

#define DEF_HWT64_OPS(start64,   update_exp64, stop, is_running,        \
                      get_rem64, get_cur64, get_rolls, get_freq,        \
                      reg_cb)                                           \
        static struct hw_timer_ops hwt_ops = {                          \
                NULL, start64, NULL, update_exp64, stop, is_running,    \
                NULL, get_rem64, NULL, get_cur64, get_rolls,            \
                get_freq, reg_cb                                        \
        };


/* Source ID */
#define HW_REALTIME_CLK   1  /* Hardware RTC ticks - typical 32768 Hz  */
#define HW_MONOTONE_CTR   0  /* Hardware (high-res) Monotonic counter  */

struct hw_timer_cfg {

        u32            base_addr;
        u32            freq_hz;
        u32            source;     /* Clock Source */
        
        bool           user_tfw; /* Timer Framework (tfw) is using hwt32 */
        union {
                /* Must be provided if 'user_tfw' is asserted. HW Timer 
                   implementation must invoke this routine to bind system
                   specific Timer Framework
                */
                i32 (*tfw_register_hwt_ops)(u32 source,  cc_hndl hwt_hndl,
                                            struct hw_timer_ops *hwt_ops);

                /* Must be provided if 'user_tfw' is not set  */
                cc_cb_fn       timeout_cb;
        } cb;

        cc_hndl        cb_param; /* Used in conjunction with 'timeout_cb */

        /* 
           Platform should force set IRQ bit correspoding to timer in interupt
           controller. This is to ensure that an alarm that might have expired
           is always handled when a new RTC value is set. 
        */
        void          (*set_irq)(void); 

        sys_irq_enbl   enbl_irqc;
        sys_irq_dsbl   dsbl_irqc;
};


#endif

