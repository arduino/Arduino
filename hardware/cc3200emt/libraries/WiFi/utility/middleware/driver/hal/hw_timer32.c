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

#include <stdbool.h>
#include <stdint.h>
#include "rom.h"
#include "rom_map.h"
#include "hw_timer32.h"
#include "hw_ints.h"
#include "hw_types.h"
#include "timer.h"


static sys_irq_enbl enbl_irqc;
static sys_irq_dsbl dsbl_irqc;
static u32 sys_flags = 0;

/* All the "time-out" configurations made in the hardware is in terms
   of operational "ticks" and not in absolute time. The caller must
   convert the absolute time into the hardware ticks prior to calling
   these API(s). Tick = Freq x Time.
*/
struct hw_timer32 {
        
        u32                    base_addr;
        u32                    freq_hz;
        
        u32                    irq_mask;

        /* Assert to indicate that SW has used an
           additional rollover count ahead of the
           actual occurence in hardware. This is
           done to avoid SW / HW race-conditions.
           Applicable only in MONOTONE mode. */
        bool                   sw_early_ro;
        u32                    n_rollovers; 
        struct u64_val         mtone_expy;

        cc_cb_fn               timeout_cb;
        cc_hndl                cb_param;

        enum cc_hw_timer_mode  op_mode;
        
        struct hw_timer32      *next;
};

#define HWT32_ACCESS_CYCLES 5000 /* Gauges SW processing times */

static inline void hwt32_set_op_mode(struct hw_timer32     *hwt,
                                     enum cc_hw_timer_mode mode)
{
        hwt->op_mode = mode;
}

static inline bool hwt32_is_running(struct hw_timer32 *hwt)
{
        return HW_TIMER_NOT_USED == hwt->op_mode? false : true;
}

bool cc_hwt32_is_running(cc_hndl hndl)
{
        struct hw_timer32 *hwt = (struct hw_timer32*) hndl;
        bool rv = false;
        
        if(NULL == hwt)
                goto cc_hwt32_is_running_exit;
        
        dsbl_irqc(&sys_flags);
        rv = hwt32_is_running(hwt);
        enbl_irqc(sys_flags);

 cc_hwt32_is_running_exit:
        return rv;
}

static i32 hwt32_config_one_shot(struct hw_timer32 *hwt, u32 expires)
{
        /* Count downwards from value of 'expires' to zero */
        MAP_TimerConfigure(hwt->base_addr, TIMER_CFG_A_ONE_SHOT);
        MAP_TimerLoadSet(hwt->base_addr, TIMER_A, expires); /* Countdown value */
        
        hwt->irq_mask = TIMER_TIMA_TIMEOUT; /* IRQ: when down counter reaches 0*/

        return 0;
}

static i32 hwt32_config_periodic(struct hw_timer32 *hwt, u32 expires)
{        
        /* Count downwards from value of 'expires' to zero */
        MAP_TimerConfigure(hwt->base_addr, TIMER_CFG_PERIODIC);
        MAP_TimerLoadSet(hwt->base_addr, TIMER_A, expires); /* Countdown value */

        hwt->irq_mask = TIMER_TIMA_TIMEOUT; /* IRQ: when down counter reaches 0*/
        
        return 0;
}

static i32 hwt32_config_monotone(struct hw_timer32 *hwt, u32 expires)
{        
        /* Count upwards until counter value matches 'expires' */
        MAP_TimerConfigure(hwt->base_addr, TIMER_CFG_PERIODIC_UP);
        MAP_TimerLoadSet(hwt->base_addr, TIMER_A, 0xFFFFFFFF); /* Rollover Val */
        MAP_TimerMatchSet(hwt->base_addr, TIMER_A, expires); /* User match Val */

        /* IRQ(s) when up counter rollsover and counter reaches 'expires' */
        hwt->irq_mask = TIMER_TIMA_TIMEOUT | TIMER_TIMA_MATCH;
        
        return 0;
}

static i32 hwt32_configure(struct hw_timer32 *hwt, u32 expires,
                           enum cc_hw_timer_mode mode)
{
        i32 rv = 0;

        switch(mode) {

        case HW_TIMER_ONE_SHOT:
                rv = hwt32_config_one_shot(hwt, expires);
                break;

        case HW_TIMER_PERIODIC:
                rv = hwt32_config_periodic(hwt, expires);
                break;

        case HW_TIMER_MONOTONE:
                rv = hwt32_config_monotone(hwt, expires);
                break;

        default:
                rv = -1;
                break;
        }

        return rv;
}

static i32 hwt32_start(struct hw_timer32 *hwt, u32 expires, 
                       enum cc_hw_timer_mode mode)
{
        if(hwt32_configure(hwt, expires, mode))
                return -1;

        hwt32_set_op_mode(hwt, mode);
        
        MAP_TimerIntEnable(hwt->base_addr, hwt->irq_mask);
        MAP_TimerEnable(hwt->base_addr, TIMER_A);

        return 0;
}

i32 cc_hwt32_start(cc_hndl hndl, u32 expires, enum cc_hw_timer_mode mode)
{
        struct hw_timer32 *hwt = (struct hw_timer32*) hndl;
        i32 rv = -1;
        
        dsbl_irqc(&sys_flags);

        if(hwt && (false == hwt32_is_running(hwt)) && expires) {
                rv = hwt32_start(hwt, expires, mode);
        }

        enbl_irqc(sys_flags);

        return rv;
}


static i32 hwt32_process_monotone_current(struct hw_timer32 *hwt,
                                          struct u64_val *current64)
{
        u32 count = MAP_TimerValueGet(hwt->base_addr, TIMER_A);
        
        util_u32_data_add(count, HWT32_ACCESS_CYCLES, current64);
        if((current64->hi_32 != 0) && (false == hwt->sw_early_ro)) {
                hwt->sw_early_ro = true;
                hwt->n_rollovers++;
        }

        current64->hi_32 = hwt->n_rollovers;

        return 0;
}

/* Utility function: v1 <-- offset--> v2, move to utils */
static u32 v1_to_v2_offset32(u32 v1, u32 v2)
{
        return (v2 > v1)? v2 - v1 : v1 + ~v2 + 1;
}

static i32 hwt32_update_monotone(struct hw_timer32 *hwt, u32 expires)
{
        struct u64_val value64 = {0, 0};
        u32 current = 0;

        hwt32_process_monotone_current(hwt, &value64);
        current = value64.lo_32;
        value64.hi_32 = 0;
        
        /* If 'expires' is too close to be missed, then push
           out the 'expires' to ensure that IRQ is triggered */
        if((v1_to_v2_offset32(current, expires) <
            HWT32_ACCESS_CYCLES)                   ||
           (v1_to_v2_offset32(expires, current) <
            HWT32_ACCESS_CYCLES)) {
                util_u32_data_add(HWT32_ACCESS_CYCLES, current,
                                  &value64);
                expires = value64.lo_32;
        }

        MAP_TimerMatchSet(hwt->base_addr, TIMER_A, expires);
        hwt->mtone_expy.hi_32 = value64.hi_32 + hwt->n_rollovers;
        hwt->mtone_expy.lo_32 = expires;

        return 0;        
}

static i32 hwt32_update(struct hw_timer32 *hwt, u32 expires)
{
        i32 rv = -1;

        switch(hwt->op_mode) {

        case HW_TIMER_MONOTONE: {
                if(hwt32_is_running(hwt))
                        rv = hwt32_update_monotone(hwt, expires);
        }
                break;

        case HW_TIMER_ONE_SHOT: /* No updates: stop, program and then start */
        case HW_TIMER_PERIODIC: /* No updates: stop, program and then start */
        default:
                break;
        }

        return rv;
}

i32 cc_hwt32_update(cc_hndl hndl, u32 expires)
{
        struct hw_timer32 *hwt = (struct hw_timer32*) hndl;
        i32 rv = -1;

        dsbl_irqc(&sys_flags);

        if(hwt && expires)
                rv = hwt32_update(hwt, expires);

        enbl_irqc(sys_flags);

        return rv;
}

static i32 hwt32_stop(struct hw_timer32* hwt)
{
        u32 status = 0;

        MAP_TimerDisable(hwt->base_addr, TIMER_A);
        MAP_TimerIntDisable(hwt->base_addr, hwt->irq_mask);

        status = MAP_TimerIntStatus(hwt->base_addr, true);
        MAP_TimerIntClear(hwt->base_addr, status);

        TimerValueSet(hwt->base_addr,TIMER_A,0x0);

        hwt32_set_op_mode(hwt, HW_TIMER_NOT_USED);

        hwt->irq_mask    = 0;
        hwt->n_rollovers = 0;
        hwt->sw_early_ro = false;

        hwt->mtone_expy.hi_32 = 0;
        hwt->mtone_expy.lo_32 = 0;

        return 0;
}

i32 cc_hwt32_stop(cc_hndl hndl)
{
        struct hw_timer32 *hwt = (struct hw_timer32*) hndl;
        i32 rv = -1;

        dsbl_irqc(&sys_flags);

        if(hwt && (true == hwt32_is_running(hwt))) {
                rv = hwt32_stop(hwt);
        }

        enbl_irqc(sys_flags);

        return rv;
}

static i32 hwt32_get_remaining(struct hw_timer32 *hwt, u32 *remaining)
{
        u32 count = 0;
        i32 rv = 0;

        switch(hwt->op_mode) {
                
        case HW_TIMER_ONE_SHOT:
        case HW_TIMER_PERIODIC:
                /* Counting downwards to zero from the 'load' value.  */
                count = MAP_TimerValueGet(hwt->base_addr, TIMER_A);
                break;

        case HW_TIMER_MONOTONE: {
                /* Monotonic: Counter keeps ticking even after match w/
                   'alarm' is done, so need some additional checks */
                u32 match = MAP_TimerMatchGet(hwt->base_addr, TIMER_A);
                u32 value = MAP_TimerValueGet(hwt->base_addr, TIMER_A);

                if(MAP_TimerIntStatus(hwt->base_addr, true) && 
                   TIMER_TIMA_MATCH)
                        rv = -1; /* HW: Match value has been attained */
                else
                        count = v1_to_v2_offset32(value, match);
        }
                break;

        default:
                rv = -1;
                break;
        }        

        if(0 == rv) {
                *remaining = 
                        count > HWT32_ACCESS_CYCLES ? 
                        count - HWT32_ACCESS_CYCLES :/* Adjusted time */
                        0;
        }

        return rv;
}

i32 cc_hwt32_get_remaining(cc_hndl hndl, u32 *remaining)
{
        i32 rv = 0;

        struct hw_timer32 *hwt = (struct hw_timer32*) hndl;

        dsbl_irqc(&sys_flags);
        
        if(hwt && (true == hwt32_is_running(hwt))) {
                rv = hwt32_get_remaining(hwt, remaining);
        }

        enbl_irqc(sys_flags);

        return rv;
}

static i32 hwt32_get_current(struct hw_timer32 *hwt, u32 *current)
{
        u32 count = 0;
        i32 rv = 0;

        switch(hwt->op_mode) {

        case HW_TIMER_ONE_SHOT:
        case HW_TIMER_PERIODIC: {
                /* Counting downwards to zero from the 'load' value.  */
                u32 loaded = MAP_TimerLoadGet(hwt->base_addr, TIMER_A);
                u32 value = MAP_TimerValueGet(hwt->base_addr, TIMER_A);
                count = (value < HWT32_ACCESS_CYCLES)?
                        loaded : loaded - value - HWT32_ACCESS_CYCLES;
        }
                break;

        case HW_TIMER_MONOTONE: {
                struct u64_val adjusted = {0, 0};

                hwt32_process_monotone_current(hwt, &adjusted);
                count = adjusted.lo_32;
        }
                break;

        default:
                rv = -1;
                break;
        }

        if(0 == rv)
                *current = count;
        
        return rv;
}

i32 cc_hwt32_get_current(cc_hndl hndl, u32 *current)
{
        struct hw_timer32 *hwt = (struct hw_timer32*) hndl;
        i32 rv = -1;

        dsbl_irqc(&sys_flags);

        if(hwt && (true == hwt32_is_running(hwt))) {
                rv = hwt32_get_current(hwt, current);
        }

        enbl_irqc(sys_flags);

        return rv;
}

u32 cc_hwt32_get_rollovers(cc_hndl hndl)
{
        struct hw_timer32 *hwt = (struct hw_timer32*) hndl;
        u32 rv = 0;

        dsbl_irqc(&sys_flags);

        if(hwt && (true == hwt32_is_running(hwt)))
                rv = hwt->n_rollovers;

        enbl_irqc(sys_flags);
        
        return rv;
}

u32 cc_hwt32_get_frequency(cc_hndl hndl)
{
        return hndl? ((struct hw_timer32*) hndl)->freq_hz : 0;
}

i32 cc_hwt32_register_cb(cc_hndl hndl, cc_cb_fn user_cb, cc_hndl cb_param)
{
        struct hw_timer32 *hwt = (struct hw_timer32*) hndl;

        if((NULL == hwt) || (NULL != hwt->timeout_cb))
                return -1;  /* Callback was aleady configured */

        hwt->timeout_cb = user_cb;
        hwt->cb_param   = cb_param;

        return 0;
}

static struct hw_timer32 timers32[MAX_HW_TIMER32];
static struct hw_timer32 *hwt_list = NULL;
static bool   init_flag = false;

static void hwt32_setup(void)
{
        i32 i = 0;
        for(i = 0; i < MAX_HW_TIMER32; i++) {
                struct hw_timer32 *hwt = timers32 + i;
                hwt->next = hwt_list;
                hwt_list  = hwt;
        }

        return;
}

DEF_HWT32_OPS(cc_hwt32_start,         cc_hwt32_update,        cc_hwt32_stop, 
              cc_hwt32_is_running,    cc_hwt32_get_remaining, 
              cc_hwt32_get_current,   cc_hwt32_get_rollovers, 
              cc_hwt32_get_frequency, cc_hwt32_register_cb)

cc_hndl cc_hwt32_init(struct hw_timer_cfg *cfg)
{
        struct hw_timer32 *hwt = NULL;

        if(false == init_flag) {
                memset(timers32, 0, sizeof(timers32));
                hwt32_setup();
                init_flag = true;
        }

        hwt = hwt_list;
        if((!hwt) || (!cfg) || (!cfg->user_tfw && !cfg->cb.timeout_cb))
                return NULL;

        if(cfg->user_tfw){
                if(cfg->cb.tfw_register_hwt_ops(cfg->source,
                                                (cc_hndl)hwt, &hwt_ops) != 0) {
                        return NULL;
                }
        } else {
                hwt->timeout_cb = cfg->cb.timeout_cb;
                hwt->cb_param   = cfg->cb_param;
        }
        
        hwt_list  = hwt->next;
        hwt->next = NULL;

        hwt->base_addr  = cfg->base_addr;
        hwt->freq_hz    = cfg->freq_hz;

        hwt->sw_early_ro= false;
        enbl_irqc       = cfg->enbl_irqc;
        dsbl_irqc       = cfg->dsbl_irqc;

        hwt32_set_op_mode(hwt, HW_TIMER_NOT_USED);

        return (cc_hndl) hwt;
}

/* 
   Called in interrupt context.

   For MONOTONIC timer::             it is possible to upload a new value
   for expiry in a running timer. The control can reach here under a race
   condition, when new expiry is loaded into timer, whilst the system IRQ
   was disabled for atomicity. Servicing of such "now stale" expiry needs
   to be ignored.
*/
static void hwt32_handle_monotone_timeout(struct hw_timer32 *hwt, u32 status)
{
        struct u64_val current64 = {0, 0};

        dsbl_irqc(sys_flags);
        if(status & TIMER_TIMA_TIMEOUT) {
                if(false == hwt->sw_early_ro)
                        hwt->n_rollovers++;
                else
                        hwt->sw_early_ro = false;
        }

        hwt32_process_monotone_current(hwt, &current64);
        enbl_irqc(sys_flags);
        
        if((status & TIMER_TIMA_MATCH) &&
           (util_u64_data_cmp(&hwt->mtone_expy, &current64) <= 0))
                /* Expiry is in past, so handle it */
                hwt->timeout_cb(hwt->cb_param);

        return;
}

static void hwt32_handle_timeout(struct hw_timer32 *hwt, u32 status)
{
        switch(hwt->op_mode) {

        case HW_TIMER_ONE_SHOT:
                hwt->timeout_cb(hwt->cb_param);
                hwt32_stop(hwt);
                break;

        case HW_TIMER_PERIODIC:
                hwt->timeout_cb(hwt->cb_param);
                break;

        case HW_TIMER_MONOTONE: 
                hwt32_handle_monotone_timeout(hwt, status);
                break;

        default:
                break;
        }
        
        return;
}

void cc_hwt32_isr(cc_hndl hndl)
{
        u32 status;

        struct hw_timer32 *hwt = (struct hw_timer32*) hndl;

        if(NULL == hwt)
                return;

        status = MAP_TimerIntStatus(hwt->base_addr, true);

        if((false == hwt32_is_running(hwt)) ||
           (status & ~hwt->irq_mask))  
                goto hwt32_isr_exit;
        
                
        hwt32_handle_timeout(hwt, status);
        
 hwt32_isr_exit:
        MAP_TimerIntClear(hwt->base_addr, status);
        
        return;
}
