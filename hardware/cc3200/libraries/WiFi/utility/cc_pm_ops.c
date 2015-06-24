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
 * Power Management Platform operations
 *
 * Note: The implementation is for the CC3xxx platform.
 ******************************************************************************/
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/rom.h"
#include "driverlib/rom_map.h"
#include "driverlib/prcm.h"
#include "driverlib/gpio.h"
#include "driverlib/cpu.h"
#include "driverlib/udma.h"
#include "driverlib/gpio_hal.h"
#include "driverlib/interrupt.h"
#include "inc/hw_ints.h"
#include "inc/hw_nvic.h"
#include "inc/hw_common_reg.h"
#include "cc_types.h"
#include "cc_pm.h"
#include "cc_pm_ops.h"
#include "driverlib/rtc_hal.h"
#include "driverlib/dma_hal.h"

#define DBG_PRINT               Report
#define NUM_NVIC_PEND_REG       6
#define ERR_TIMER_TO_WAKE       (-2)
#define MAX_GPIO_WAKESOURCE     6

struct cc_pm_ops_ctrl {
        enum power_modes user_sel_power_mode;
        u8 intr_ref_cnt;
        u32 spl_gpio_wakefrom_lpds;
};

struct {
        u32 vector_table;   // Vector Table Offset
        u32 aux_ctrl;       // Auxiliary control register
        u32 int_ctrl_state; // Interrupt Control and State
        u32 app_int;        // Application Interrupt Reset control
        u32 sys_ctrl;       // System control
        u32 config_ctrl;    // Configuration control
        u32 sys_pri_1;      // System Handler Priority 1
        u32 sys_pri_2;      // System Handler Priority 2
        u32 sys_pri_3;      // System Handler Priority 3
        u32 sys_hcrs;       // System Handler control and state register
        u32 systick_ctrl;   // SysTick Control Status
        u32 systick_reload; // SysTick Reload
        u32 systick_calib;  // SysTick Calibration
        u32 int_en[6];      // Interrupt set enable
        u32 int_priority[49]; // Interrupt priority
} nvic_reg_store;

struct cc_pm_ops_ctrl cc_pm_ctrl = {POWER_POLICY_SLEEP, 0, 13};

u8 gpio_wake_src[] = {2, 4, 13, 17, 11, 24};
u8 gpio_lpds_inttype[] = {1, 1, 2, 0xFF, 3, 0xFF, 0};
u8 gpio_hib_inttype[] = {2, 2, 0, 0xFF, 3, 0xFF, 1};

u32 nvic_int_mask[] = {NVIC_PEND0_MASK, NVIC_PEND1_MASK, NVIC_PEND2_MASK,
                                NVIC_PEND3_MASK, NVIC_PEND4_MASK, NVIC_PEND5_MASK};

volatile i32 debug = 0;


/* Network (Host IRQ) based wakeup from S3(LPDS) */
static i32 setup_S3_wakeup_from_nw()
{
#define IS_NWPIC_INTR_SET() (HWREG(NVIC_EN5) & (1 << ((INT_NWPIC - 16) & 31)))

        /* Check if the NWP->APPs interrupt is enabled */
        if(IS_NWPIC_INTR_SET()) {
                /* Set LPDS Wakeup source as NWP request */
                MAP_PRCMLPDSWakeupSourceEnable(PRCM_LPDS_HOST_IRQ);
                return 0;
        } else {
                return -1;
        }
}



/* GPIO based wakeup from S3(LPDS) */
static i32 check_n_setup_S3_wakeup_from_gpio()
{
        i32 retval, indx;
        u8 gpio_num[MAX_GPIO_WAKESOURCE];
        u8 int_type[MAX_GPIO_WAKESOURCE];

        /* Check for any special purpose GPIO usage */
        retval = cc_gpio_get_spl_purpose(&gpio_num[0],
                                &int_type[0],
                                MAX_GPIO_WAKESOURCE);

        if(retval > 0) {
                for(indx = 0; indx < sizeof(gpio_wake_src); indx++) {
                        if(gpio_wake_src[indx] == gpio_num[0]) {
                                /* Setup the GPIO to be the wake source */
                                MAP_PRCMLPDSWakeUpGPIOSelect(
                                      indx, gpio_lpds_inttype[int_type[0]]);
                                MAP_PRCMLPDSWakeupSourceEnable(PRCM_LPDS_GPIO);
                                /* Save the GPIO number wake from LPDS */
                                cc_pm_ctrl.spl_gpio_wakefrom_lpds = gpio_num[0];
                                break;
                        }
                }
        } else {
                return -1;
        }

        return 0;
}

/* Timer based wakeup from S3 (LPDS) */
static i32 check_n_setup_S3_wakeup_from_timer()
{
        u64 scc_match, scc_curr, scc_remaining;

        /* Check if there is an alarm set */
        if(cc_rtc_has_alarm()) {
                /* Get the time remaining for the RTC timer to expire */
                scc_match = MAP_PRCMSlowClkCtrMatchGet();
                scc_curr = MAP_PRCMSlowClkCtrGet();
                
                if(scc_match > scc_curr) {
                        /* Get the time remaining in terms of slow clocks */
                        scc_remaining = (scc_match - scc_curr);
                        if(scc_remaining > WAKEUP_TIME_LPDS) {
                                /* Subtract the time it takes for wakeup 
                                   from S3 (LPDS) */
                                scc_remaining -= WAKEUP_TIME_LPDS;
                                scc_remaining = (scc_remaining > 0xFFFFFFFF)?
                                        0xFFFFFFFF: scc_remaining;
                                /* Setup the LPDS wake time */
                                MAP_PRCMLPDSIntervalSet(
                                        (u32)scc_remaining);
                                /* Enable the wake source to be timer */
                                MAP_PRCMLPDSWakeupSourceEnable(
                                        PRCM_LPDS_TIMER);
                        } else {
                                /* Cannot enter LPDS */
                                return ERR_TIMER_TO_WAKE;
                        }
                } else {
                       return ERR_TIMER_TO_WAKE;
                }
        } else {
                /* Disable timer as the wake source  */
                MAP_PRCMLPDSWakeupSourceDisable(PRCM_LPDS_TIMER);
                return -1;
        }

        return 0;
}

/* Setup the HIBernate wakr source as apecified GPIO */
static void setup_hib_gpio_wake(u32 gpio_num,
                           u32 gpio_wake_type)
{
        MAP_PRCMHibernateWakeUpGPIOSelect(gpio_num, gpio_wake_type);
        MAP_PRCMHibernateWakeupSourceEnable(gpio_num);

        return;
}

/* GPIO based wakeup from S4 (HIB) */
static i32 check_n_setup_S4_wakeup_from_gpio()
{
        i32 retval, indx;
        u8 gpio_num[MAX_GPIO_WAKESOURCE];
        u8 int_type[MAX_GPIO_WAKESOURCE];

        /* Check for any special purpose GPIO usage */
        retval = cc_gpio_get_spl_purpose(&gpio_num[0], 
                                        &int_type[0], 
                                        MAX_GPIO_WAKESOURCE);

        if(retval > 0) {
                for(indx = 0; indx < retval; indx++) {
                        switch(gpio_num[indx]) {
                                case 2:
                                        setup_hib_gpio_wake(PRCM_HIB_GPIO2,
                                                gpio_hib_inttype[int_type[indx]]);
                                        break;
                                case 4:
                                        setup_hib_gpio_wake(PRCM_HIB_GPIO4,
                                                gpio_hib_inttype[int_type[indx]]);
                                        break;
                                case 13:
                                        setup_hib_gpio_wake(PRCM_HIB_GPIO13,
                                                gpio_hib_inttype[int_type[indx]]);
                                        break;
                                case 17:
                                        setup_hib_gpio_wake(PRCM_HIB_GPIO17,
                                                gpio_hib_inttype[int_type[indx]]);
                                        
                                        break;
                                case 11:
                                        setup_hib_gpio_wake(PRCM_HIB_GPIO11,
                                                gpio_hib_inttype[int_type[indx]]);
                                        break;
                                case 24:
                                        setup_hib_gpio_wake(PRCM_HIB_GPIO24,
                                                gpio_hib_inttype[int_type[indx]]);
                                        break;
                                default:
                                        break;
                        }
                }
        } else {
            return -1;
        }
    
        return 0;
}

/* Timer based wakeup from S4 (HIB) */
static i32 check_n_setup_S4_wakeup_from_timer()
{
        u64 scc_match, scc_curr, scc_remaining;

        /* Check if there is an alarm set */
        if(cc_rtc_has_alarm()) {
                /* Get the time remaining for the RTC timer to expire */
                scc_match = MAP_PRCMSlowClkCtrMatchGet();
                scc_curr = MAP_PRCMSlowClkCtrGet();
                
                if(scc_match > scc_curr) {
                        /* Get the time remaining in terms of slow clocks */
                        scc_remaining = (scc_match - scc_curr);
                        if(scc_remaining > WAKEUP_TIME_HIB) {
                                /* Subtract the time it takes for wakeup 
                                   from S4 (HIB) */
                                scc_remaining -= WAKEUP_TIME_HIB;
                                /* Setup the HIB wake time */
                                MAP_PRCMHibernateIntervalSet(scc_remaining);
                                /* Enable the wake source to be RTC */
                                MAP_PRCMHibernateWakeupSourceEnable(
                                        PRCM_HIB_SLOW_CLK_CTR);
                        } else {
                                /* Cannot enter HIB */
                                return ERR_TIMER_TO_WAKE;
                        }
                } else {
                        return -1;
                }
        } else {
                /* Disable Timer as wake source */
                MAP_PRCMHibernateWakeupSourceDisable(PRCM_HIB_SLOW_CLK_CTR);
                return -1;
        }

        return 0;
}

/* Sets up wake-up sources for indicated power mode */
i32 cc_set_up_wkup_srcs(enum soc_pm target)
{
        i32 nw_ret = -1, gpio_ret = -1, timer_ret = -1;
        switch(target) {
                case e_pm_S0:
                case e_pm_S1:
                case e_pm_S2:
                        /* These handle the cases of run, sleep, deepsleep.
                           Wake source is configured outside this scope in 
                           individual peripherals */
                        break;
                case e_pm_S3:
                        /* Low power deep sleep condition */
                        /* Network (Host IRQ) based wakeup is always enabled */
                        nw_ret = setup_S3_wakeup_from_nw(); 
                        /* Check and enable GPIO based wakeup */
                        gpio_ret = check_n_setup_S3_wakeup_from_gpio();
                        /* Check and enable LRT based wakeup */
                        timer_ret = check_n_setup_S3_wakeup_from_timer();
                        break;
                case e_pm_S4:
                        /* Hibernate condition */
                        /* Check and enable GPIO based wakeup */
                        gpio_ret = check_n_setup_S4_wakeup_from_gpio();
                        /* Check and enable LRT based wakeup */
                        timer_ret = check_n_setup_S4_wakeup_from_timer();
                        break;
                default:
                        break;
        }

        if(ERR_TIMER_TO_WAKE == timer_ret) {
                return -1;
        }
        if((nw_ret < 0) && (gpio_ret < 0) && (timer_ret < 0)) {
                return -1;
        }
        else if((gpio_ret < 0) && (timer_ret < 0)) {
				/* Setup the LPDS wake time */
				MAP_PRCMLPDSIntervalSet(LPDS_WDOG_TIME);
				/* Enable the wake source to be timer */
				MAP_PRCMLPDSWakeupSourceEnable(
						PRCM_LPDS_TIMER);
        }
        return 0;
}

/* LPDS wake SW interrupt handler */
void wake_interrupt_handler()
{
        i32 wake_source;

        /* Identify the wakeup source */
        wake_source = MAP_PRCMLPDSWakeupCauseGet();
        
        switch(wake_source) {
        case PRCM_LPDS_HOST_IRQ:
                        break;
        case PRCM_LPDS_GPIO:
                /* Invoke the callback with the last GPIO num 
                   used to enter LPDS (S3) */
                gpio_wake_interrupt_handler(
                        &cc_pm_ctrl.spl_gpio_wakefrom_lpds);
                        break;
        case PRCM_LPDS_TIMER:
                        break;
        }

        return;
}

/* Process events that have woken up system from S3 (LPDS) */
i32 cc_handle_S3_wakeup()
{
        /* Trigger the SW interrupt */
        MAP_IntPendSet(INT_PRCM);
        return 0;
}

/* Are there interrupts pending in system?   TRUE -> yes else no */
bool cc_are_irqs_pending(void)
{
        i32 indx = 0;
        u32 *base_reg_addr;

        /* Check if there are any interrupts pending */
        base_reg_addr = (u32 *)NVIC_PEND0;
        for(indx = 0; indx < NUM_NVIC_PEND_REG; indx++) {
                if(base_reg_addr[indx] & nvic_int_mask[indx]) {
                        return true;
                }
        }

        return false;
}

/* Must push system to low power state of S4 (Hibernate) */
i32 cc_enter_S4(void)
{
        /* Invoke the driverlib API to enter HIBernate */
        MAP_PRCMHibernateEnter();

        return 0;
}

/* Must push system to low power state of S3 (LPDS) */
i32 cc_enter_S3(void(*resume_fn)(void), u32 stack_ptr)
{
		MAP_PRCMLPDSRestoreInfoSet(stack_ptr, (u32)resume_fn);

        /* Enter LPDS */
        MAP_PRCMLPDSEnter();
        return 0;
}

/* Must push system to low power state of S2 (Deepsleep) */
i32 cc_enter_S2(void)
{
        /* Enter deepsleep */
        //MAP_PRCMDeepSleepEnter();

        return 0;
}

/* Must push system to low power state of S1 */
i32  cc_enter_S1(void)
{
        MAP_PRCMSleepEnter();
        return 0;
}

/* Save the NVIC registers */
void back_up_nvic_regs()
{
        i32 indx = 0;
        u32 *base_reg_addr;
        /* Save the NVIC control registers */
        nvic_reg_store.vector_table = HWREG(NVIC_VTABLE);
        nvic_reg_store.aux_ctrl = HWREG(NVIC_ACTLR);
        nvic_reg_store.int_ctrl_state = HWREG(NVIC_INT_CTRL);
        nvic_reg_store.app_int = HWREG(NVIC_APINT);
        nvic_reg_store.sys_ctrl = HWREG(NVIC_SYS_CTRL);
        nvic_reg_store.config_ctrl = HWREG(NVIC_CFG_CTRL);
        nvic_reg_store.sys_pri_1 = HWREG(NVIC_SYS_PRI1);
        nvic_reg_store.sys_pri_2 = HWREG(NVIC_SYS_PRI2);
        nvic_reg_store.sys_pri_3 = HWREG(NVIC_SYS_PRI3);
        nvic_reg_store.sys_hcrs = HWREG(NVIC_SYS_HND_CTRL);

        /* Systick registers */
        nvic_reg_store.systick_ctrl = HWREG(NVIC_ST_CTRL);
        nvic_reg_store.systick_reload = HWREG(NVIC_ST_RELOAD);
        nvic_reg_store.systick_calib = HWREG(NVIC_ST_CAL);
        
        /* Save the interrupt enable registers */
        base_reg_addr = (u32 *)NVIC_EN0;
        for(indx = 0; indx < (sizeof(nvic_reg_store.int_en) / 4); indx++) {
                nvic_reg_store.int_en[indx] = base_reg_addr[indx];
        }

        /* Save the interrupt priority registers */
        base_reg_addr = (u32 *)NVIC_PRI0;
        for(indx = 0; indx < (sizeof(nvic_reg_store.int_priority) / 4); indx++) {
                nvic_reg_store.int_priority[indx] = base_reg_addr[indx];
        }

        return;
}

/* Reestore the NVIC registers */
void restore_nvic_regs()
{
        i32 indx = 0;
        u32 *base_reg_addr;

        /* Restore the NVIC control registers */
        HWREG(NVIC_VTABLE) = nvic_reg_store.vector_table;
        HWREG(NVIC_ACTLR) = nvic_reg_store.aux_ctrl;
        HWREG(NVIC_APINT) = nvic_reg_store.app_int;
        HWREG(NVIC_SYS_CTRL) = nvic_reg_store.sys_ctrl;
        HWREG(NVIC_CFG_CTRL) = nvic_reg_store.config_ctrl;
        HWREG(NVIC_SYS_PRI1) = nvic_reg_store.sys_pri_1;
        HWREG(NVIC_SYS_PRI2) = nvic_reg_store.sys_pri_2;
        HWREG(NVIC_SYS_PRI3) = nvic_reg_store.sys_pri_3;
        HWREG(NVIC_SYS_HND_CTRL) = nvic_reg_store.sys_hcrs;

        /* Systick registers */
        HWREG(NVIC_ST_CTRL) = nvic_reg_store.systick_ctrl;
        HWREG(NVIC_ST_RELOAD) = nvic_reg_store.systick_reload;
        HWREG(NVIC_ST_CAL) = nvic_reg_store.systick_calib;

        /* Restore the interrupt priority registers */
        base_reg_addr = (u32 *)NVIC_PRI0;
        for(indx = 0; indx < (sizeof(nvic_reg_store.int_priority) / 4); indx++) {
                base_reg_addr[indx] = nvic_reg_store.int_priority[indx];
        }
        
        /* Restore the interrupt enable registers */
        base_reg_addr = (u32 *)NVIC_EN0;
        for(indx = 0; indx < (sizeof(nvic_reg_store.int_en) / 4); indx++) {
                base_reg_addr[indx] = nvic_reg_store.int_en[indx];
        }

        INTRODUCE_SYNC_BARRIER(); /* Data and instruction sync barriers */

        return;
}

/* S3 (LPDS): Back-up system regs & data */
void cc_back_up_soc_data(u32 ram_retention)
{
        /* Enable the RAM retention */
        MAP_PRCMSRAMRetentionEnable(ram_retention, PRCM_SRAM_LPDS_RET);
        /* Store the NVIC registers */
        back_up_nvic_regs();

        return;
}

/* S3 (LPDS): Restore system regs & data */
void cc_restore_soc_data(void)
{
        u32 reg_val;
        /* Check if any of the registers/data need to be restored */
        /* Take I2C semaphore */
        reg_val = HWREG(COMMON_REG_BASE + 
                COMMON_REG_O_I2C_Properties_Register);
        reg_val = (reg_val & ~0x3) | 0x1;
        HWREG(COMMON_REG_BASE + 
                COMMON_REG_O_I2C_Properties_Register) = reg_val;

        /* Take GPIO semaphore */
        reg_val = HWREG(COMMON_REG_BASE + 
                COMMON_REG_O_GPIO_properties_register);
        reg_val = (reg_val & ~0x3FF) | 0x155;
        HWREG(COMMON_REG_BASE + 
                COMMON_REG_O_GPIO_properties_register) = reg_val;

        /* Restore the NVIC registers */
        restore_nvic_regs();
        
        return;
}

/* Disable system / global interrupt. ref counted for use by nested calls */
void cc_dsbl_sys_irq(void)
{
        u32 primask;
        /* Disable the interrupts */
        primask = CPUcpsid();
        cc_pm_ctrl.intr_ref_cnt++;

        UNUSED(primask);
        return;
}

/* Enable system / global interrupt. */
void cc_enbl_sys_irq(void)
{
        u32 primask;

        if(cc_pm_ctrl.intr_ref_cnt && (--cc_pm_ctrl.intr_ref_cnt == 0)) {
                /* Enable the interrupts */
                primask = CPUcpsie();
        }

        UNUSED(primask);

        return;
}

