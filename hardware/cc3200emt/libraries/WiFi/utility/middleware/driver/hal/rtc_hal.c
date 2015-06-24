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

static sys_irq_enbl enbl_irqc;              /* Construct to enable  system IRQ */
static sys_irq_dsbl dsbl_irqc;              /* Construct to disable system IRQ */

struct hw_rtc64 {

        u32                    base_addr;
        u32                    freq_hz;     /* Operating frequency of RTC HW   */

        cc_cb_fn               timeout_cb;
        cc_hndl                cb_param;

        void                   (*set_irq)(void);

        /* RTC is in a slow domain and access time to RTC hardware from software
           (in fast domain) is considerable. Therefore, to reduce overall delays,
           an alternative mechanism of calculating RTC value without reading the
           slow domain has been provided. Assert the flag "do not read hardware"
           - 'dont_rdhw = true' to use this alternative mechanism.

           However, in this 'SW' mechanism, the slow domain hardware is still
           accessed to "write" the RTC and the alarm values.
        */ 
        bool                   dont_rdhw;   /* True: use SW mechanism for RTC */
        struct u64_time        ref_value;   /* SW: not actual RTC but the ref */
        struct u64_time        alarm_val;   /* SW: user's actual alarm value  */

        bool                   has_alarm;   /* An alarm has been configured.  */
};

static struct hw_rtc64 rtc64, *rtc = NULL;

#define U32NS_U16MS(nsec)  (nsec / 1000000)
#define U16MS_U32NS(msec)  (msec * 1000000)

#define U16MS_CYCLES(msec)	((msec *1024)/1000)
#define CYCLES_U16MS(cycles)	((cycles *1000)/ 1024)

/* Read RTC counter in the fast domain through some system specific mechanisms */
static void rtc_fast_domain_counter_rd(struct u64_time *counter)
{
        u64 eval_count = 0;
        u64 rtc_count1,rtc_count2,rtc_count3 = 0;
        u32 itr = 0;

#define BRK_IF_RTC_CTRS_ALIGN(c2, c1)           \
        if(c2 - c1 <= 1) {                      \
                itr++;                          \
                break;                          \
        }

        do {
                rtc_count1 = PRCMSlowClkCtrFastGet();
                rtc_count2 = PRCMSlowClkCtrFastGet();
                rtc_count3 = PRCMSlowClkCtrFastGet();
                itr = 0;
                
                BRK_IF_RTC_CTRS_ALIGN(rtc_count2, rtc_count1);
                BRK_IF_RTC_CTRS_ALIGN(rtc_count3, rtc_count2);
                BRK_IF_RTC_CTRS_ALIGN(rtc_count3, rtc_count1);

                /* Consistent values in two consecutive reads implies a correct
                   value of the counter. Do note, the counter does not give the
                   calendar time but a hardware that ticks upwards continuously.
                   The 48-bit counter operates at 32,768 HZ. */
        } while(1);

        eval_count = (1 == itr)? rtc_count2 : rtc_count3;

        /* Counter resolution is 32768 Hz: need to get secs, nsec */
        eval_count  >>= 5; /* Div by 32 for resolution of 1024 Hz */ 
        counter->secs = eval_count >> 10; /* sec: Divide by 1024  */
        counter->nsec = eval_count & 0x3FF;
        if(counter->nsec != 0){
            /* accounting for the 1ms of lost precision during conversion */
            counter->nsec += 1;
        }
        counter->nsec = U16MS_U32NS(CYCLES_U16MS(counter->nsec));
        

        return;
}

static void rtc_alarm_wr(const struct u64_time *alarm)
{
        MAP_PRCMRTCMatchSet(alarm->secs,
                            U16MS_CYCLES(U32NS_U16MS(alarm->nsec)));

        /* Keep a copy to avoid costly HW read accesses */
        if(rtc->dont_rdhw) {
                rtc->alarm_val.secs = alarm->secs;
                rtc->alarm_val.nsec = alarm->nsec;
        }
        
        return;
}

static void rtc_alarm_rd(struct u64_time *alarm)
{
        u16 msec_cycles = 0;

        if(rtc->dont_rdhw) {
                alarm->secs = rtc->alarm_val.secs;
                alarm->nsec = rtc->alarm_val.nsec;
        } else {
                MAP_PRCMRTCMatchGet(&alarm->secs, &msec_cycles);
                if(msec_cycles != 0){
                		/* accounting for the 1ms of lost precision during conversion */
                         msec_cycles += 1;
                }
                alarm->nsec = U16MS_U32NS(CYCLES_U16MS(msec_cycles));
        }
}

static void rtc_ref_value_wr(const struct u64_time *value)
{
        struct u64_time counter, *clk_ctr;
        clk_ctr = &counter;

        rtc_fast_domain_counter_rd(clk_ctr);
        util_u32_nsec_sub(value->nsec, clk_ctr->nsec, &rtc->ref_value);
        rtc->ref_value.secs += value->secs - clk_ctr->secs;

        return;
}

#define RTC_ACCESS_TIME_NSEC    5000000  /* Time to access slow domain RTC HW */

/* Access to hardware (RTC) is slow. So, try a better estimate of RTC counter */
static void hw_access_time_addup(struct u64_time *value)
{
        struct u64_time input_value;
        struct u64_time access_time;

        input_value.secs = value->secs;
        input_value.nsec = value->nsec;

        access_time.secs = 0;
        access_time.nsec = RTC_ACCESS_TIME_NSEC;

        util_u64_time_add(&input_value, &access_time, value);

        return;
}

static void rtc_value_wr(const struct u64_time *value)
{
        MAP_PRCMRTCSet(value->secs, U16MS_CYCLES(U32NS_U16MS(value->nsec)));

        /* Now, maintain a reference to the RTC Value outside hardware */
        if(rtc->dont_rdhw) {
                struct u64_time provided_val;
                struct u64_time *adjusted_val = &provided_val;

                provided_val.secs = value->secs;
                provided_val.nsec = value->nsec;

                hw_access_time_addup(adjusted_val);

                rtc_ref_value_wr(adjusted_val);
        }

        return;
}

static void rtc_value_rd(struct u64_time *value)
{
        if(rtc->dont_rdhw) {
                /* Use the reference maintained outside hardware for RTC Val */
                struct u64_time counter, *clk_ctr;
                clk_ctr = &counter;
                rtc_fast_domain_counter_rd(clk_ctr);
                util_u64_time_add(&rtc->ref_value, clk_ctr, value);
        } else {
                u16 msec_cycles = 0;

                MAP_PRCMRTCGet(&value->secs, &msec_cycles);
                if(msec_cycles != 0){
                		/* accounting for the 1ms of lost precision during conversion */
                		msec_cycles += 1;
                }
                value->nsec = U16MS_U32NS(CYCLES_U16MS(msec_cycles));

                /* Try to provide a value adjusted for hardware access time.*/
                hw_access_time_addup(value); 
        }

        return;
}

/* 
   This routine validates given alarm configuration against RTC value. 
   Additionally, indicates if nsec part of alarm is smaller than that
   of RTC value.

   Return true for valid alarm.
*/
static bool is_alarm_cfg_valid(const struct u64_time *alarm, 
                               const struct u64_time *clock,
                               u32 *borrow_nsec)
{
        u32 borrow = 0;

        if(alarm->nsec <= clock->nsec)
                borrow = 1;
        
        if(alarm->secs < clock->secs + borrow)
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
        if(NULL == alarm)
                return -1;

        rtc_value_rd(&value);         /* An estimated RTC value at the moment */
        hw_access_time_addup(&value); /* Min alarm value to trigger next IRQ  */

        if(true == is_alarm_cfg_valid(alarm, &value, NULL))
                rtc_alarm_wr(alarm);  /* User alarm is greater than Min Value */
        else
                rtc_alarm_wr(&value); /* User alarm in past, fall-back on Min */

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
{	
        u32 intr_mask;
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
        MAP_PRCMIntStatus();

        rtc->has_alarm  = false;
        rtc->alarm_val.secs = 0;
        rtc->alarm_val.nsec = 0;

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

        if(false == is_alarm_cfg_valid(&alarm, &value, &borrow))
                return -1; /* Invalid means Expired */

        tta->nsec = borrow? alarm.nsec + ~value.nsec + 1 :
                            alarm.nsec - value.nsec;
        
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
        /* Not expecting 48bit RTC to rollover any time soon */
        return ((struct hw_rtc64*) hndl == rtc)? 0 : 0xFFFFFFFF;
}

static u32 hwt64_get_frequency(cc_hndl hndl)
{
        return ((struct hw_rtc64*) hndl == rtc)? rtc->freq_hz : 0;
}

i32 cc_rtc_set(struct u64_time *rtc_val)
{
        if(rtc) {
                rtc_value_wr(rtc_val);
                rtc->set_irq();
                return 0;
        }

        return -1;
}

i32 cc_rtc_fast_read_config(bool enable)
{
        if(NULL == rtc)
                return -1;

        if(enable) {
                struct u64_time rtc_val;
                rtc_value_rd(&rtc_val);
                rtc_ref_value_wr(&rtc_val);
                rtc->dont_rdhw = true;
        } else {
                rtc->dont_rdhw = false;
        }

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
        rtc->dont_rdhw  = false;
        rtc->alarm_val.secs  = 0;
        rtc->alarm_val.nsec  = 0;
        rtc->ref_value.secs  = 0;
        rtc->ref_value.nsec  = 0;

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

        status = dsbl_irqc();
        
        rtc_alarm_rd(&alarm);
        rtc_value_rd(&value);
        enbl_irqc(status);

        if(true == is_alarm_cfg_valid(&alarm, &value, NULL)){
                return; /* Race condition: ISR for old / stale alarm, ignore */
        }
        rtc->has_alarm = false; /* Valid ISR: alarm is about to be processed */

        /* This ISR is for the active alarm, therefore, handle it */
        rtc->timeout_cb(rtc->cb_param);
        
        return;
}
