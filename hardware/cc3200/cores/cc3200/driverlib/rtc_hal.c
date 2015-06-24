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

#include "hw_types.h"
#include "rom.h"
#include "rom_map.h"
#include "prcm.h"
#include "rtc_hal.h"

static sys_irq_enbl enbl_irqc;
static sys_irq_dsbl dsbl_irqc;

struct hw_rtc64 {

        u32                    base_addr;
        u32                    freq_hz;

        cc_cb_fn               timeout_cb;
        cc_hndl                cb_param;

        void                   (*set_irq)(void);

        bool                   has_alarm;
};

static struct hw_rtc64 rtc64, *rtc = NULL;
#if 0
#define U32NS_U16MS(nsec)  (nsec >> 20)
#define U16MS_U32NS(msec)  (msec << 20)
#else
#define U32NS_U16MS(nsec)  (nsec / 1000000)
#define U16MS_U32NS(msec)  (msec * 1000000)
#endif

#if 1
#define U16MS_CYCLES(msec)	((msec *1024)/1000)
#define CYCLES_U16MS(cycles)	((cycles *1000)/ 1024)
//#define CYCLES_U16MS(cycles)	(cycles)
#else
#define U16MS_CYCLES(msec)	(msec)
#define CYCLES_U16MS(cycles)	(cycles)
#endif

static inline void rtc_alarm_wr(const struct u64_time *alarm)
{
        MAP_PRCMRTCMatchSet(alarm->secs,
        					U16MS_CYCLES(U32NS_U16MS(alarm->nsec)));
}

static void rtc_alarm_rd(struct u64_time *alarm)
{
        u16 msec_cycles = 0;
        
        MAP_PRCMRTCMatchGet(&alarm->secs, &msec_cycles);
        alarm->nsec = U16MS_U32NS(CYCLES_U16MS(msec_cycles));
}

static inline void rtc_value_wr(const struct u64_time *value)
{
        MAP_PRCMRTCSet(value->secs, U16MS_CYCLES(U32NS_U16MS(value->nsec)));
}

static void rtc_value_rd(struct u64_time *value)
{
        u16 msec_cycles = 0;
        
        MAP_PRCMRTCGet(&value->secs, &msec_cycles);
        value->nsec = U16MS_U32NS(CYCLES_U16MS(msec_cycles));
}

/* 
   This routine validates given alarm configuration against RTC value. 
   Additionally, indicates if nsec part of alarm is smaller than that
   of RTC value.

   Return true for valid alarm.
*/
static bool is_valid_alarm(const struct u64_time *alarm, 
                           const struct u64_time *value,
                           u32 *borrow_nsec)
{
        u32 borrow = 0;

        if(alarm->nsec <= value->nsec)
                borrow = 1;
        
        if(alarm->secs < value->secs + borrow)
                return false; /* Expired: Alarm-64 is less than Value-64 */
        
        if(borrow_nsec)
                *borrow_nsec = borrow;
               
        return true;
}

static bool hwt64_is_running(cc_hndl hndl)
{
        return (((struct hw_rtc64*) hndl == rtc) && 
                (rtc->has_alarm))? true : false;
}

static i32 set_alarm(struct u64_time *alarm)
{
        struct u64_time value;

        rtc_value_rd(&value);
        if(NULL == alarm){
                return -1;
        }
        if(false == is_valid_alarm(alarm, &value, NULL))
                return -1; /* Perhaps, alarm specified is in past */
        
        rtc_alarm_wr(alarm);        
        rtc->has_alarm = true;

        MAP_PRCMIntEnable(PRCM_INT_SLOW_CLK_CTR);

        return 0;
}

i32 cc_rtc_set_alarm(struct u64_time *alarm)
{
		u32 intr_mask;
        i32 rv = 0;

        intr_mask = dsbl_irqc();
        rv = set_alarm(alarm);
        enbl_irqc(intr_mask);

        return rv;
}

static i32 setup_alarm(struct hw_rtc64 *rtc, struct u64_val *expires)
{
        struct u64_time alarm;

        if(NULL == expires)
                return -1;

        alarm.secs = expires->hi_32;
        alarm.nsec = expires->lo_32;
        set_alarm(&alarm);

        return 0;
}

static i32 hwt64_update_alarm(cc_hndl hndl, struct u64_val *expires)
{
		u32 intr_mask;
        i32 rv = -1;
        struct hw_rtc64 *rtc = (struct hw_rtc64*) hndl;

        intr_mask = dsbl_irqc();
        
        if(rtc && (true == rtc->has_alarm)) {
                rv = setup_alarm(rtc, expires);
        }

        enbl_irqc(intr_mask);

        return rv;
}

static i32 hwt64_create_alarm(cc_hndl hndl, struct u64_val *expires,
                              enum cc_hw_timer_mode mode)
{		u32 intr_mask;
        i32 rv = -1;
        struct hw_rtc64 *rtc = (struct hw_rtc64*) hndl;

        intr_mask = dsbl_irqc();

        if(rtc && (false == rtc->has_alarm)) {
                rv = setup_alarm(rtc, expires);
        }

        enbl_irqc(intr_mask);

        return rv;
}                             

static i32 clr_alarm(void)
{
        MAP_PRCMIntDisable(PRCM_INT_SLOW_CLK_CTR);
        
        rtc->has_alarm = false;

        return 0;
}

static i32 hwt64_clear_alarm(cc_hndl hndl)
{
        struct hw_rtc64 *rtc = (struct hw_rtc64*) hndl;
         
        if((NULL == rtc) || (false == rtc->has_alarm))
                return -1;

        clr_alarm();
        rtc->has_alarm = false;

        return 0;
}

i32 cc_rtc_clr_alarm(void)
{
		u32 intr_mask;
        i32 rv = 0;

        intr_mask = dsbl_irqc();
        rv = clr_alarm();
        enbl_irqc(intr_mask);

        return rv;
}

bool cc_rtc_has_alarm(void)
{
		u32 intr_mask;
        bool rv = false;
        
        intr_mask = dsbl_irqc();
        rv = rtc->has_alarm;
        enbl_irqc(intr_mask);
        
        return rv;
}

static i32 time_to_alarm(struct u64_time *tta)
{
        struct u64_time alarm, value;
        u32 borrow = 0;

        if(false == rtc->has_alarm)
                return -1;

        rtc_alarm_rd(&alarm);
        rtc_value_rd(&value);

        if(false == is_valid_alarm(&alarm, &value, &borrow))
                return -1; /* Invalid means Expired */

        tta->nsec = 
                borrow? alarm.nsec + ~value.nsec + 1 : alarm.nsec - value.nsec;
        
        tta->nsec = alarm.secs - value.secs - borrow;
        
        return 0;
}

static i32 hwt64_get_remaining(cc_hndl hndl, struct u64_val *remaining)
{
        i32 rv = -1;
        struct hw_rtc64 *rtc = (struct hw_rtc64*) hndl;

        if(remaining && rtc) {
            struct u64_time tta = {0, 0};
                
                rv = time_to_alarm(&tta);
                if(0 == rv) {
                        remaining->hi_32 = tta.secs;
                        remaining->lo_32 = tta.nsec;
                }
        }

        return rv;
}

i32 cc_rtc_time_to_alarm(struct u64_time *tta)
{
		u32 intr_mask;
        i32 rv = 0;

        intr_mask = dsbl_irqc();
        rv = time_to_alarm(tta);
        enbl_irqc(intr_mask);
        
        return rv;
}

static i32 get_value(struct u64_time *time_u64)
{
        if(NULL != time_u64) {
                rtc_value_rd(time_u64);
                return 0;
        }

        return -1;
}

static i32 hwt64_get_current(cc_hndl hndl, struct u64_val *current)
{
        struct u64_time now_time;
        i32 rv = -1;
        
        if(NULL != current) {
                rv = get_value(&now_time);
                if(0 == rv) {
                        current->hi_32 = now_time.secs;
                        current->lo_32 = now_time.nsec;
                }
        }

        return rv;
}

i32 cc_rtc_get(struct u64_time *rtc_val)
{
        return get_value(rtc_val);
}

static u32 hwt64_get_rollovers(cc_hndl hndl)
{
        /* Not expecting 64bit RTC to rollover in life-time of product */
        return ((struct hw_rtc64*) hndl == rtc)? 0 : 0xFFFFFFFF;
}

static u32 hwt64_get_frequency(cc_hndl hndl)
{
        return ((struct hw_rtc64*) hndl == rtc)? rtc->freq_hz : 0;
}

i32 cc_rtc_set(struct u64_time *rtc_val)
{
        rtc_value_wr(rtc_val);
        rtc->set_irq();

        return 0;
}

static i32 hwt64_register_cb(cc_hndl hndl, cc_cb_fn user_cb, cc_hndl cb_param)
{
        struct hw_rtc64 *rtc = (struct hw_rtc64*) hndl;

        if((NULL == rtc) || (NULL != rtc->timeout_cb))
                return -1; /* Callback was aleady configured */

        rtc->timeout_cb = user_cb;
        rtc->cb_param   = cb_param;

        return 0;
}

DEF_HWT64_OPS(hwt64_create_alarm,  hwt64_update_alarm,  hwt64_clear_alarm, 
              hwt64_is_running,    hwt64_get_remaining, hwt64_get_current, 
              hwt64_get_rollovers, hwt64_get_frequency, hwt64_register_cb)

i32 cc_rtc_init(const struct hw_timer_cfg *cfg)
{
        if(!cfg || ((!cfg->user_tfw && !cfg->cb.timeout_cb) || !cfg->set_irq))
                return -1;

        if(NULL == rtc) {
                rtc = &rtc64;
                memset(rtc, 0, sizeof(rtc64));
        }

        if(cfg->user_tfw) {
          if(cfg->cb.tfw_register_hwt_ops(cfg->source, 
                                           (cc_hndl)rtc, &hwt_ops) != 0) {
                return -1;
          }
        } else {
                rtc->timeout_cb = cfg->cb.timeout_cb;
                rtc->cb_param   = cfg->cb_param;
        }
        
        rtc->base_addr  = cfg->base_addr;
        rtc->freq_hz    = cfg->freq_hz; 
        rtc->set_irq    = cfg->set_irq;
        rtc->has_alarm  = false;

        enbl_irqc       = cfg->enbl_irqc;
        dsbl_irqc       = cfg->dsbl_irqc;

        MAP_PRCMRTCInUseSet();

        return 0;
}

/* Invoked in interrupt context */
void cc_rtc_isr(void)
{
        struct u64_time alarm, value;
        u32 status;

        /* Read the interrupt status, also clears the status */
        status = MAP_PRCMIntStatus();
        UNUSED(status);
        if(rtc == NULL){
                return;
        }
        /* 
           Need to ascertain ISR has not been invoked for older or stale alarm.
           This can happen if alarm was either updated or cancelled by the user
           while holding up ISR through disable system interrupt
        */
        if(false == rtc->has_alarm)
                return; /* Race condition: alarm was cleared interim, ignore */
        
        rtc_alarm_rd(&alarm);
        rtc_value_rd(&value);

        if(true == is_valid_alarm(&alarm, &value, NULL))
                return; /* Race condition: ISR for old / stale alarm, ignore */

        rtc->has_alarm = false; /* Valid ISR: alarm is about to be processed */

        /* This ISR is for the active alarm, therefore, handle it */
        rtc->timeout_cb(rtc->cb_param);
        
        return;
}
