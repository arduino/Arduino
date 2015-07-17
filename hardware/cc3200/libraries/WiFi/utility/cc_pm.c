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
 * Power Management Framework
 *
 * Note: Framework has been intentionally kept generic such that, if needed,
 * it can be used on other SoC(s) as well.
 ******************************************************************************/
#include <string.h>
#include "cc_pm.h"
#include "inc/hw_types.h"

/* Storage memory for Cortex M4 registers. To make implementation independent of
   CPU, register specific constructs must be made part of platform services.
*/

struct arm_CM4_core_regs vault_arm_registers;

/* Following functions should be implemented in assembly */
/*extern void back_up_arm_registers(void);
extern void restore_arm_registers(void);*/

struct platform_desc {

        i32                      num_hw_module;
        struct soc_module       *hw_module_vec;

        i32                      used_list_len;
        struct soc_module       *used_mod_list;

        struct platform_pm_ops  reg_pm_ops;
        struct platform_pm_ops  *pm_ops;

        u32             num_app_no_pm;

};

static struct platform_desc  pform_info = {0, NULL, 0, NULL, {0}, NULL, 0};
static struct platform_desc *pform      =  NULL;

static i32 push_modules_to_M4_no_irq(void)
{
        struct soc_module *hw_module = pform->used_mod_list;
        i32 n_mod_in_M4 = 0;

        while(hw_module) {
                struct module_drv *mod_drv = hw_module->my_driver;
                if((NULL != mod_drv)                               && 
                   (NULL != mod_drv->goto2pm_mode)                 &&
                   (0 != mod_drv->goto2pm_mode(mod_drv, e_pm_M4)))
                        break;  /* Module not ready to go M4 state */
                
                n_mod_in_M4++;
                hw_module = hw_module->next;
        }

        return n_mod_in_M4;
}

static i32 make_modules_to_M0_no_irq(i32 n_mod)
{
        struct soc_module *hw_module = pform->used_mod_list;
        
        while(hw_module && (n_mod > 0)) {
                struct module_drv *mod_drv = hw_module->my_driver;
                if(NULL != mod_drv) {
                        if((NULL != hw_module->clk_enable)) {
                                hw_module->clk_enable(hw_module, e_pm_S0);
                        }
                        if((NULL != mod_drv->goto2pm_mode)) {
                                mod_drv->goto2pm_mode(mod_drv, e_pm_M0);
                        }
                }
                
                n_mod--;
                hw_module = hw_module->next;
        }
        
        return n_mod;
}

static i32 do_try_S4_no_irq()
{
        i32 retval;

        /* Attempt to push HW modules into M4 state */
        i32 n_M4_drv = push_modules_to_M4_no_irq();
        if(pform->used_list_len != n_M4_drv) {
                /* Failed to move all drivers to M4 state to enable system to 
                   get to S4; now restore peripherals to their active state.
                */
                make_modules_to_M0_no_irq(pform->used_list_len);
                
                return -1;
        }

        retval = pform->pm_ops->set_up_wkup_srcs(e_pm_S4);
        if(retval < 0) {
                /* Setup of wake sources failed */
                make_modules_to_M0_no_irq(pform->used_list_len);

                return -1;
        }

        pform->pm_ops->back_up_soc_data();

        /* Final checks to see, if any interrupts have shown-up in interim  */ 
        if(pform->pm_ops->are_irqs_pending()) {       /* Yes, they have ... */
                make_modules_to_M0_no_irq(pform->used_list_len);/* Wake all */
                return 0;
        }
        
        pform->pm_ops->enter_S4();

        return 0;      /* Control should never reach here */
}


i32 try_S4_no_irq(void)
{
#define PFORM_CAN_TRY_S4() ((NULL != pform->pm_ops->enter_S4)        && \
                            pform->pm_ops->can_try_pm_state(e_pm_S4))
        
        return PFORM_CAN_TRY_S4()? do_try_S4_no_irq() : -1;
}


#ifdef ewarm
#define BACK_UP_ARM_REGISTERS() {             \
        __asm(" push {r0-r12,LR} \n" \
          " mov32 r1, vault_arm_registers \n" \
          " mrs  r0,msp \n" \
          " str  r0,[r1] \n" \
          " mrs  r0,psp \n" \
          " str  r0,[r1, #4] \n" \
          " mrs  r0,primask \n" \
          " str  r0,[r1, #12] \n" \
          " mrs  r0,faultmask \n" \
          " str  r0,[r1, #16] \n" \
          " mrs  r0,basepri \n" \
          " str  r0,[r1, #20] \n" \
          " mrs  r0,control \n" \
          " str  r0,[r1, #24] \n"); \
          }
#endif

#ifdef ccs
#define BACK_UP_ARM_REGISTERS() {     \
        __asm(" push {r0-r12,LR} \n" \
          " movw r1, vault_arm_registers \n" \
          " movt r1, vault_arm_registers \n" \
          " mrs  r0,msp \n" \
          " str  r0,[r1] \n" \
          " mrs  r0,psp \n" \
          " str  r0,[r1, #4] \n" \
          " mrs  r0,primask \n" \
          " str  r0,[r1, #12] \n" \
          " mrs  r0,faultmask \n" \
          " str  r0,[r1, #16] \n" \
          " mrs  r0,basepri \n" \
          " str  r0,[r1, #20] \n" \
          " mrs  r0,control \n" \
          " str  r0,[r1, #24] \n"); \
          }
#endif

#ifdef __GNUC__
#define BACK_UP_ARM_REGISTERS() {     \
        __asm(" push {r0-r12,LR} \n" \
          " movw  r1, #:lower16:vault_arm_registers \n" \
          " movt  r1, #:upper16:vault_arm_registers \n" \
          " mrs  r0,msp \n" \
          " str  r0,[r1] \n" \
          " mrs  r0,psp \n" \
          " str  r0,[r1, #4] \n" \
          " mrs  r0,primask \n" \
          " str  r0,[r1, #12] \n" \
          " mrs  r0,faultmask \n" \
          " str  r0,[r1, #16] \n" \
          " mrs  r0,basepri \n" \
          " str  r0,[r1, #20] \n" \
          " mrs  r0,control \n" \
          " str  r0,[r1, #24] \n"); \
          }
#endif

//static inline void restore_arm_registers()

#ifdef ewarm
#define RESTORE_ARM_REGISTERS() {          \
    __asm(" mov32 r1, vault_arm_registers \n" \
          " ldr  r0,[r1, #24] \n" \
          " msr  control,r0 \n" \
          " ldr  r0,[r1] \n" \
          " msr  msp,r0 \n" \
          " ldr  r0,[r1,#4] \n" \
          " msr  psp,r0 \n" \
          " ldr  r0,[r1, #12] \n" \
          " msr  primask,r0 \n" \
          " ldr  r0,[r1, #16] \n" \
          " msr  faultmask,r0 \n" \
          " ldr  r0,[r1, #20] \n" \
          " msr  basepri,r0 \n" \
          " pop  {r0-r12,LR} \n"); \
         }
#endif


#ifdef ccs
#define RESTORE_ARM_REGISTERS() {        \
    __asm(" movw r1, vault_arm_registers \n" \
          " movt r1, vault_arm_registers \n" \
          " ldr  r0,[r1, #24] \n" \
          " msr  control,r0 \n" \
          " ldr  r0,[r1] \n" \
          " msr  msp,r0 \n" \
          " ldr  r0,[r1,#4] \n" \
          " msr  psp,r0 \n" \
          " ldr  r0,[r1, #12] \n" \
          " msr  primask,r0 \n" \
          " ldr  r0,[r1, #16] \n" \
          " msr  faultmask,r0 \n" \
          " ldr  r0,[r1, #20] \n" \
          " msr  basepri,r0 \n" \
          " pop  {r0-r12,LR} \n"); \
         }
#endif

#ifdef __GNUC__
#define RESTORE_ARM_REGISTERS() {          \
    __asm(" movw  r1, #:lower16:vault_arm_registers \n" \
          " movt  r1, #:upper16:vault_arm_registers \n" \
          " ldr  r0,[r1, #24] \n" \
          " msr  control,r0 \n" \
          " ldr  r0,[r1] \n" \
          " msr  msp,r0 \n" \
          " ldr  r0,[r1,#4] \n" \
          " msr  psp,r0 \n" \
          " ldr  r0,[r1, #12] \n" \
          " msr  primask,r0 \n" \
          " ldr  r0,[r1, #16] \n" \
          " msr  faultmask,r0 \n" \
          " ldr  r0,[r1, #20] \n" \
          " msr  basepri,r0 \n" \
          " pop  {r0-r12,LR} \n"); \
         }
#endif

/* Called directly by boot ROM after waking from S3 state */
void resume_from_S3(void)
{
        /* Jump from ROM context hence introduce the sync barriers */
        INTRODUCE_SYNC_BARRIER(); /* Data and instruction sync barriers */


        RESTORE_ARM_REGISTERS(); /* Core registers and code is in assembly */

        INTRODUCE_SYNC_BARRIER(); /* Data and instruction sync barriers */

        pform->pm_ops->restore_soc_data();
        make_modules_to_M0_no_irq(pform->used_list_len); /* Wake up all  */
        pform->pm_ops->handle_S3_wakeup();   /* Should be last statement */
        return;
}

static void enter_into_S3(void)
{

        pform->pm_ops->back_up_soc_data();

        INTRODUCE_SYNC_BARRIER(); /* Data and instruction sync barriers */
        
        BACK_UP_ARM_REGISTERS(); /* Core registers and code is in assembly */         

        /* In OS mode psp has to be saved*/
        /* In NON-OS mode msp has to be saved */
        if(vault_arm_registers.control == 0){
        	pform->pm_ops->enter_S3(resume_from_S3,
        							vault_arm_registers.msp);
        }else{
        	pform->pm_ops->enter_S3(resume_from_S3,
        	        				vault_arm_registers.psp);
        }

        /* Introducing delays to facilitate CPU to fade away ........ */
        asm(" NOP"); asm(" NOP"); asm(" NOP"); asm(" NOP"); asm(" NOP"); 
        asm(" NOP"); asm(" NOP"); asm(" NOP"); asm(" NOP"); asm(" NOP");
        asm(" NOP"); asm(" NOP"); asm(" NOP"); asm(" NOP"); asm(" NOP");
}

static i32 do_try_S3_no_irq()
{
        /* Attempt to push HW modules into M3 state */
        i32 n_M4_drv = push_modules_to_M4_no_irq();
        i32 retval;
       
        if(pform->used_list_len != n_M4_drv) {
                /* Failed to move all drivers to M4 state to enable system to 
                   get to S3; now restore peripherals to their active state.
                */
                make_modules_to_M0_no_irq(pform->used_list_len);
                
                return -1;
        }

        retval = pform->pm_ops->set_up_wkup_srcs(e_pm_S3);
        if(retval < 0) {
                /* Setup of wake sources failed */
                make_modules_to_M0_no_irq(pform->used_list_len);

                return -1;
        }
        /* Final checks to see, if any interrupts have shown-up in interim   */ 
        if(pform->pm_ops->are_irqs_pending()) {       /* Yes, they have ...  */
                make_modules_to_M0_no_irq(pform->used_list_len);/* Wake all  */
                return 0;
        }

        /* Enter LPDS here ... */
        enter_into_S3();

        return 0;
}

i32 try_S3_no_irq(void)
{
#define PFORM_CAN_TRY_S3() ((NULL != pform->pm_ops->enter_S3)        && \
                            pform->pm_ops->can_try_pm_state(e_pm_S3))
        
        return PFORM_CAN_TRY_S3() ? do_try_S3_no_irq() : -1;
}

i32 try_S2_no_irq(void)
{
        if((NULL == pform->pm_ops->enter_S2)         || 
           !pform->pm_ops->can_try_pm_state(e_pm_S2))
                return -1; /*S2: either not enabled or system is not ready */

        if(!pform->pm_ops->are_irqs_pending()) {  /* No interim interrupts */
                pform->pm_ops->enter_S2();        /* System now goes to S2 */
        }
           
        return 0;
}

i32 try_S1_no_irq(void)
{
        if(NULL == pform->pm_ops->enter_S1)
                return -1;                        /* S1 not used in system */

        if(!pform->pm_ops->are_irqs_pending()) {  /* No interim interrupts */
                pform->pm_ops->enter_S1();        /* System now goes to S1 */
        }
        return 0;
}

i32 idle_trace = 0;

void cc_idle_task_pm(void)
{
        /* 
           1. Interrupts are disabled to ensure atomic operations in system for
           checking status and perform follow-up configurations. In other words, 
           this arrangement avoids race conditions & supports synchronized flow
           for system commands such as WFI (from ARM) and custom ones (from TI).
           Of course, interrupts are enabled before function returns.
           
           2. Follows a orderly approach of trying to push system, first, into 
           most least power state and if not possible, then to the next higher 
           power state. Specifically, sequence is S4 -> S3 -> S2 -> S1.

           3. Importantly, this function will return, no sooner, SOC is woken-up
           from a low power state. This modus operandi ensures that a renewed or
           fresh assessment is made to push system to least possible power state,
           after 
        */
		u32 intr_mask;
        intr_mask = pform->pm_ops->dsbl_sys_irq(); /* Disable interrupts */

        if(0 != pform->num_app_no_pm) {
                /* Atleast, one app doesn't want PM to kick-in, so exit */
                goto cc_idle_task_pm_exit1;
        }

        if(0 != try_S4_no_irq()) {                        /* S4 entry failed */
                if(0 != try_S3_no_irq()) {                /* S3 entry failed */
                        if(0 != try_S2_no_irq()) {        /* S2 entry failed */
                        		pform->pm_ops->enbl_sys_irq(intr_mask);
                                if(0 != try_S1_no_irq()) {/* S1 entry failed */
                                        
                                }
                                intr_mask = pform->pm_ops->dsbl_sys_irq();
                           }
                   }
        }
        
 cc_idle_task_pm_exit1:
        pform->pm_ops->enbl_sys_irq(intr_mask); /* Enable  interrupts */
}

i32 cc_pm_platform_ops_register(struct platform_pm_ops *pm_ops)
{
        if(NULL  == pm_ops)
                return -1;

        if((NULL == pm_ops->enter_S4)   &&
           (NULL == pm_ops->enter_S3)   &&
           (NULL == pm_ops->enter_S2)   &&
           (NULL == pm_ops->enter_S1)) {
                return -1; /* No low power state, then don't use framework */
        }

        /* Atleast, one low power state is supported on platform, ensure 
           that all required operations have been provided */
        if((NULL == pm_ops->set_up_wkup_srcs)           ||
           (NULL == pm_ops->handle_S3_wakeup)           ||
           (NULL == pm_ops->are_irqs_pending)           ||
           (NULL == pm_ops->can_try_pm_state)           ||
           (NULL == pm_ops->back_up_soc_data)           ||
           (NULL == pm_ops->restore_soc_data)           ||
           (NULL == pm_ops->dsbl_sys_irq)               ||
           (NULL == pm_ops->enbl_sys_irq))
                return -1;  /* Mandatory operations not provided */
        
        memcpy(&pform->reg_pm_ops, pm_ops, sizeof(struct platform_pm_ops));
        
        pform->pm_ops = &pform->reg_pm_ops;

        return 0;
}


i32 cc_pm_framework_init(void)
{
        if(NULL == pform) {
                pform = &pform_info;
                return 0;
        }

        return -1;
}

i32 cc_modules_load(struct soc_module *modules, i32 num_mod)
{
        if((NULL != modules) && (0 != num_mod)) {
                i32 i = 0;
                for(i = 0; i < num_mod; i++) {
                        struct soc_module *hw_module = modules + i;
                        
                        if(-1 == hw_module->clk_enable(hw_module, e_pm_S0))
                                goto modules_load_error;                       
                        
                        if(-1 == hw_module->rtos_drv_ld(hw_module))
                                goto modules_load_error;
                }

                return 0;
        }

 modules_load_error:
        return -1;
}

static void add2tail_used_mod_list(struct soc_module *hw_module)
{
        struct soc_module *soc_mod = pform->used_mod_list;
        
        while(soc_mod  && soc_mod->next) {
                soc_mod = soc_mod->next;
        }

        if(NULL == soc_mod)
                pform->used_mod_list = hw_module;
        else
                soc_mod->next        = hw_module;

        pform->used_list_len++;

        return;
}

i32 cc_module_drv_register(struct soc_module *hw_module, 
                               struct module_drv *mod_drv)
{
        if((NULL != hw_module) && (NULL != mod_drv) && 
           (NULL == hw_module->my_driver) &&
           (NULL == mod_drv->hw_module)) {

                mod_drv->hw_module    = hw_module;
                hw_module->my_driver  = mod_drv;

                hw_module->next       = NULL;

                /* Drivers are listed in same order of loading */
                add2tail_used_mod_list(hw_module);

                return 0;
        }

        return -1;
}

void cc_module_drv_unregister(struct module_drv *mod_drv)
{
        struct soc_module *hw_module = pform->used_mod_list;
        struct soc_module *prev_hmod = NULL;
        
        while(hw_module) {

                if(hw_module->my_driver != mod_drv) {
                        prev_hmod = hw_module;
                        hw_module = hw_module->next;
                        continue;
                }
                
                if(NULL != prev_hmod) {
                        prev_hmod->next      = hw_module->next;
                } else {
                        pform->used_mod_list = hw_module->next;
                }

                hw_module->my_driver = NULL;
                mod_drv->hw_module   = NULL;
                
                break;
        }

        return;
}

void cc_app_putoff_pm(void)
{
		u32 intr_mask;
		intr_mask = pform->pm_ops->dsbl_sys_irq();
        pform->num_app_no_pm++;
        pform->pm_ops->enbl_sys_irq(intr_mask);

        return;
}

void cc_app_resume_pm(void)
{
		u32 intr_mask;
		intr_mask = pform->pm_ops->dsbl_sys_irq();
        if(0 != pform->num_app_no_pm) pform->num_app_no_pm--;
        pform->pm_ops->enbl_sys_irq(intr_mask);
}
