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
 *  cc_pm.h - API and other data constructs to operate power mnagement frmwk.
 *******************************************************************************
 */
#ifndef __CC_PM_H__
#define __CC_PM_H__

#include <stdio.h>
#include <stdbool.h>
#include "cc_types.h"
/*******************************************************************************
 * Power Management Framework
 *
 * Note: Framework has been intentionally kept generic so that, if needed, it 
 * can be used on other SoC(s) as well.
 ******************************************************************************/

/* SoC or System power states */
enum soc_pm {
        
        e_pm_S0, // CPU & HW modules are functioning at optimal & intended freq
        e_pm_S1, // CPU is halted, high freq PLL CLK is available to HW modules
        e_pm_S2, // CPUSS is clk gated, Mid freq CLK is availalbe to HW modules 
        e_pm_S3, // SoC almost pwr off, slow CLK is present & OCRAM is retained
        e_pm_S4  // SOC almost pwr off, slow CLK is present & few regs retained

};

/* HW Module power states */
enum mod_pm {
        
        e_pm_M0, // HW module is active & operational at intended & optimal freq
        e_pm_M1, // Unused parts of HW module is clk gated, some context is lost
        e_pm_M2, // HW module while supporting remote WKUP is mostly clock gated 
        e_pm_M3, // No clock whatsover is availalbe to HW modules, still powered
        e_pm_M4  // Powered Down
};

/* 
   Description 
   -----------

   1. Sx value refers to sleep states of SoC. S0 is highest power consuming state

   2. Mx value refers to power state of a HW 'Module' in SoC. M0 is highest power 
   consuming state of a module.

   3. In theory, following relationship or mapping exists between Sx and Mx

   S0 -> M0, M1, M2, M3, M4 i.e. each of modules can exist in any Mx state
   S1 -> M0, M1, M2, M3, M4 i.e. each of modules can exist in any Mx state
   S2 -> M0, M1, M2, M3, M4 i.e. each of modules can exist in any Mx state
   S3 -> M4                 i.e  every module must be powered down 
   S4 -> M4                 i.e  every module must be powered down 
   
   Specifically, M1, M2 and M3 states are managed by intelligent module drivers.

   4. For extreme power management, HW modules that have been provisioned for use
   but are idle, at present, and are not expected to receive any asynchronous HW
   event, should be kept in M3 state by their correspondig software drivers. 

   Examples of such modules include UART Master, I2C Master, DMA Master, ....

   For many of modules, states M1 & M2 may not be applicable and can be optional

   5. Of course, each module will have M0 (opertational) and M4 (powered off) 
   states and in likelihood shall have M3 state. If M3 state is not applicable, 
   then it shall be considered as optional. 

   6. Power management framework provides an infrastructure to restore system 
   context, whenever, woken up from low power states of S1, S2 and S3.
   
*/


/*
  cc_idle_task_pm(void)

  Sole entry point to framework to exercise power management of platform. When
  invoked from IDLE task of system, this routine attemtps to push system to a
  lowest possible and configured power state (i.e. one of S1 to S4).

  The sequence of states for power management is S4 -> S3 -> S2 -> S1.

*/

void cc_idle_task_pm(void);

/*
  struct platform_pm_ops
  
  Holds platform specific routines for power management. Provisioned by platform
  and invoked by framework.
  
  By providing adequate operations to platform implementation, framework ensures
  that there are ample opportunities to incorporate deployment compelled quirks
  and fix-ups on platform side.

  Platform software must inform PM framework about supported low power Sx states 
  by providing corresponding enter_Sx operations. If a particular enter_Sx entry
  is not provided by implementation, then it implies that particular low power
  is not supported on platform.
  
  Note: 

  1. Unless stated otherwise, all functions return 0 for success & -1 for errors.

  2. Unless stated otherwise, framework invokes functions in an atomic manner.

  3. Need to ascertain whether some of function returns can be changed to 'void'
  
*/

struct platform_pm_ops {
        
        /* Sets up wake-up sources for indicated power mode */
        i32  (*set_up_wkup_srcs)(enum soc_pm target);
        
        /* Process events that have woken up system. 

        Note: This API is called in the context of Boot ROM. Therefore, platform
        implementation should, at the earliest, enable a switch to RTOS context.
        A typical way enabling context switch out of Boot ROM is to read wake-up
        events and then post SW IRQ or IRQ events to NVIC. Generation of IRQ by 
        NVIC should transfer CPU control irreversably to RTOS implementation.
        
        */
        i32  (*handle_S3_wakeup)(void);

        /* Are there interrupts pending in system?   TRUE -> yes else no */
        bool (*are_irqs_pending)(void);

        /* Coarsely, can system go to a Lower Power? TRUE -> yes else no */
        bool (*can_try_pm_state)(enum soc_pm target);

        /* Must push system to low power state of S4 */
        i32  (*enter_S4)(void);

        /* Must push system to low power state of S3 */
        i32  (*enter_S3)(void(*resume_fn)(void), u32 stack_ptr);

        /* Must push system to low power state of S2 */
        i32  (*enter_S2)(void);

        /* Must push system to low power state of S1 */
        i32  (*enter_S1)(void);

        /* S3: Back-up & restore system regs &  data */
        void (*back_up_soc_data)(void);
        void (*restore_soc_data)(void);

        /* Disable & enable system / global interrupt */
        u32 (*dsbl_sys_irq)(void); /* ref counted for use by nested calls */
        void (*enbl_sys_irq)(u32 mask);
};

/*
  struct module_info
  
  Abstraction to provide information about a HW module to framework. A module is
  identified by an unique ID. Modules are provisioned by platform implemetation
  and used by framework.
*/

enum mod_freq {
        
        e_freq_mhz40,
        e_freq_mhz80
};

struct module_drv;

struct soc_module {
        
        const u8      module_id;

        const u32       base_addr;
        const u32       irqvec_id;
        
        /* Can frequency be made simple 32 bit unsigned interger? */
        const enum mod_freq      oper_freq;       /* Maximum operating freq  */
        volatile u32   *pm_clkreg;
        const enum soc_pm        min_op_Sx;       /* Minimal oper SoC state  */

        void                    *hw_detail;       /* Module specific detail  */

        struct module_drv       *my_driver;       /* Refer to HAL SW driver  */

        struct soc_module       *next;
        
        /* Enable  clock for module */
        i32  (*clk_enable)(struct soc_module  *hw_module, enum soc_pm Sx);

        /* Disable clock for module */
        i32  (*clk_disable)(struct soc_module *hw_module, enum soc_pm Sx);

        /* Load SW driver for module */
        i32  (*rtos_drv_ld)(struct soc_module *hw_module);
};

enum mod_clk_state {
        
        e_clk_cut_off,
        e_clk_working
};

enum api_signature {
        
        e_sync_call,
        e_async_call
};

/* 
   struct module_drv
   
   This construct defines and describes boundary between module specific driver
   and a platform supported generic framework or infrastructure.
   
*/

struct module_drv {
        
        /* Following data must be populated & managed by system framework */
             
        struct soc_module       *hw_module;       /* HW MOD description  */
        enum mod_clk_state       clk_state;       /* Runtime clock state */
        
        /* Following data must be provided by drivers to system framework */
        enum mod_pm              pm_state;

        void                    *rtos_drv;
        
        /* Runtime PM mode - invoked by platform framework  */ 
        i32  (*goto2pm_mode)(struct module_drv *mod_drv, const enum mod_pm);
};

/*
  Initialize Platform.

  Returns 0 on success otherwise -1 on error
*/
i32 cc_pm_framework_init(void);

/* 
   Used by init code of platform to support implementation specific nuances.

   Returns 0 on success otherwise -1 on error.
*/
i32 cc_pm_platform_ops_register(struct platform_pm_ops *ops); 

/* 
   Used by central init sequence of platform. May be considered as optional
   if RTOS has its intrinsic infrastructure to load module drivers.

   Input "modules" must be an array with "num_mod" elements and is stored 
   on a persistent memory.

   This API loads driver for each of module specified in array.

   Returns 0 on success otherwise -1 on error.
*/
i32 cc_modules_load(struct soc_module *modules, i32 num_mod);

/* 
   Binds specified driver and module, then register that binding with frame
   -work.
   
   "hw_module" and "mod_drv" must be pointers to persistent memories. PM or
   platform framework maintains a list of used modules. There is one-to-one
   binding between module and driver. In other words, a module is managed
   by only driver.

   Invoked by module drivers a.k.a device drivers irrespective of fact that
   (optional) cc_modules_load( ) is used or not. 

   Returns 0 on success otherwise -1 on error.
*/
i32  cc_module_drv_register(struct soc_module *hw_module,
                                struct module_drv *mod_drv);

/* 
   Un-register correspondig module from list of used modules (maintained by
   framework) and follow-it up by removing binding as well. 

   It is expected binding of module & driver would have been registered with
   platform framework.

   Invoked by module drivers a.k.a device drivers.
*/
void cc_module_drv_unregister(struct module_drv *mod_drv);

/*
  Control HW clock for modules.

  Returns 0 on success otherwise -1/
*/
i32 cc_module_clk_enable(struct module_drv *mod_drv);
i32 cc_module_clk_disable(struct module_drv *mod_drv);

/* Applications can defer SoC PM indefinitely - typically, SoC remains in S0 */
void cc_app_putoff_pm(void); /* Ref  counted */
void cc_app_resume_pm(void); /* Resume PM, after it has been deferred */

/* 
 *   Data constructs for implementation in assembly.
 */
struct arm_CM4_core_regs {
        u32     msp;
        u32     psp;
        u32     psr;
        u32     primask;
        u32     faultmask;
        u32     basepri;
        u32     control; 
};

#endif //__CC_PM_H__

