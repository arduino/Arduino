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
//****************************************************************************

/*******************************************************************************
 *  rtc_hal.h - API and other data constructs to operate RTC HAL.
 *******************************************************************************
 */

#ifndef _RTC_HAL_H_
#define _RTC_HAL_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "hw_timer.h"

/* 
   Set Wall-Clock Alarm (using absolute time)

   Returns 0 on success otherwise -1
*/
i32 cc_rtc_set_alarm(struct u64_time *alarm);

/* 
   Clear a previously configured alarm

   Returns 0 on success otherwise -1
*/
i32 cc_rtc_clr_alarm(void);

/* 
   Returns to indicate whether an alarm is active or not
*/
bool cc_rtc_has_alarm(void);

/*  
    Get wall-clock time remaining to expiry of configured alarm.

    Returns 0 on success otherwise -1
*/
i32 cc_rtc_time_to_alarm(struct u64_time *tta);

/*  
    Get wall-clock time at this instance.

    Returns 0 on success otherwise -1
*/
i32 cc_rtc_get(struct u64_time *rtc_val);

/*  
    Set wall-clock time at this instance.

    Returns 0 on success otherwise -1
*/
i32 cc_rtc_set(struct u64_time *rtc_val);

/* 
   Interrupt service routine.

   Should be invoked by platform whenever, a new value for RTC is set or there
   is a pending HW interrupt 
*/
void cc_rtc_isr();

i32 cc_rtc_fast_read_config(bool enable);

i32 cc_rtc_init(const struct hw_timer_cfg *cfg);

#endif

