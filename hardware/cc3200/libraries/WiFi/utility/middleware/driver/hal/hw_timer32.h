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
 *  hw_timer32.h - API and other data constructs to operate GPIO HAL.
 *******************************************************************************
 */

#ifndef _HW_TIMER32_H_
#define _HW_TIMER32_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "hw_timer.h"

/* 
   Activate HW Timer32 to operate in specified 'mode' and set it to time-out at
   a value specified by 'expires'.
   
   Returns 0 on success otherwise -1
*/
i32 cc_hwt32_start(cc_hndl hndl, u32 expires, enum cc_hw_timer_mode mode);

/* 
   Update HW Timer32 to time-out at a new value specified by 'expires'.

   Returns 0 on success otherwise -1
*/
i32 cc_hwt32_update(cc_hndl hndl, u32 expires);

/* 
   De-activate HW Timer32, if it is already running.
   
   Returns 0 on success otherwise -1
*/
i32 cc_hwt32_stop(cc_hndl hndl);

/* 
   Returns status of HW Timer32.
*/
bool cc_hwt32_is_running(cc_hndl hndl);

/* 
   If timer is active, then get counts remaining to reach time-out value 
   of expires.
   
   Returns 0 on success otherwise -1
 */
i32  cc_hwt32_get_remaining(cc_hndl hndl, u32 *remaining);

/* 
   If timer is active, then get instantaneous value of couner.

   Returns 0 on success otherwise -1
*/
i32  cc_hwt32_get_current(cc_hndl hndl, u32 *current);

/* 
   For an running timer, returns number of rollovers or wrap-arounds of counter
   since last 'start'.

   If timer is not active or running, then a value of 0 is returned.
*/
u32  cc_hwt32_get_rollovers(cc_hndl hndl);

/* 
   Returns effective frequency in HZ at which counter is running.
   
*/ 
u32  cc_hwt32_get_frequency(cc_hndl hndl);

/* 
   Installs call-back information of user, if not already done in 'init' 
   function.
*/
i32  cc_hwt32_register_cb(cc_hndl hndl, cc_cb_fn user_cb, cc_hndl cb_param);

#define MAX_HW_TIMER32 1

/* 
   Initiliazes HW Timer32 as per provide configuration.

   Returns a valid on success otherwise NULL.
*/
cc_hndl cc_hwt32_init(struct hw_timer_cfg *cfg);

/* 
   Interrupt service routine.

   Should be invoked by platform whenever, a new value for timer is set or there
   is a pending HW interrupt 
*/
void cc_hwt32_isr(cc_hndl hndl);
#endif

