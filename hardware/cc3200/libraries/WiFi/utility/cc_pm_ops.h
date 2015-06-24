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
 *  cc_pm_ops.h - API and other data constructs of CC3200 platform operations.
 *******************************************************************************
 */
#ifndef __CC_PM_OPS_H__
#define __CC_PM_OPS_H__

/*******************************************************************************
 * Power Management Platform operations APIs
 ******************************************************************************/

#define WAKEUP_TIME_LPDS        230             /* 7 ms */
#define WAKEUP_TIME_HIB         3277            /* 100 ms */
#define LPDS_WDOG_TIME			32768			/* 1 sec */
#define RAM_RETAIN_NONE         0
#define RAM_RETAIN_64KB         (PRCM_SRAM_COL_1)
#define RAM_RETAIN_128KB        (RAM_RETAIN_64KB | PRCM_SRAM_COL_2)
#define RAM_RETAIN_192KB        (RAM_RETAIN_128KB | PRCM_SRAM_COL_3)
#define RAM_RETAIN_256KB        (RAM_RETAIN_256KB | PRCM_SRAM_COL_4)

enum power_modes {
        POWER_POLICY_SLEEP,
        POWER_POLICY_STANDBY,
        POWER_POLICY_HIBERNATE
};

#define NVIC_PEND0_MASK         0x01FFC16F
#define NVIC_PEND1_MASK         0x00C81800
#define NVIC_PEND2_MASK         0x00000000
#define NVIC_PEND3_MASK         0x00000000
#define NVIC_PEND4_MASK         0x02900000
#define NVIC_PEND5_MASK         0x00039902

/* Sets up wake-up sources for indicated power mode */
i32 cc_set_up_wkup_srcs(enum soc_pm target);

/* Process events that have woken up system */
i32 cc_handle_S3_wakeup();

/* Are there interrupts pending in system?   TRUE -> yes else no */
bool cc_are_irqs_pending(void);

/* Coarsely, can system go to a Lower Power? TRUE -> yes else no.
   This decision is based on the user input
   */
bool cc_can_try_pm_state(enum soc_pm target);

/* Must push system to low power state of S4 (Hibernate) */
i32 cc_enter_S4(void);

/* Must push system to low power state of S3 (LPDS) */
i32 cc_enter_S3(void(*resume_fn)(void), u32 stack_ptr);

/* Must push system to low power state of S2 (Deepsleep) */
i32 cc_enter_S2(void);

/* Must push system to low power state of S1 */
i32  cc_enter_S1(void);

/* S3 (LPDS): Back-up system regs & data */
void cc_back_up_soc_data(u32 ram_retention);

/* S3 (LPDS): Restore system regs & data */
void cc_restore_soc_data(void);

/* Disable system / global interrupt. ref counted for use by nested calls */
void cc_dsbl_sys_irq(void);

/* Enable system / global interrupt. */
void cc_enbl_sys_irq(void);

/* User applications invoke this API to communicate the preferred choice 
 * of low power mode */
i32 cc_setup_power_policy(enum power_modes lowest_power_mode);

/* Get the platform specific operations */
i32 cc_get_pm_ops(struct platform_pm_ops *cc_pm_ops);

/*interrupt handler to handle LPDS wake up event*/
void wake_interrupt_handler(void);

#endif // __CC_PM_OPS_H__

