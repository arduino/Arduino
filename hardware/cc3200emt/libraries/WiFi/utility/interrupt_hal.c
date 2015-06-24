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

#include <stdio.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "inc/hw_ints.h"
#include "driverlib/rom.h"
#include "driverlib/rom_map.h"
#include "driverlib/interrupt.h"
#include "driverlib/prcm.h"
#include "osi.h"
#include "cc_types.h"

struct isr_handler {
        void (*reg_intr_handler)(void *);
        void *intr_param;
};

/* Can make this allocation dynamic to save memory */
struct isr_handler isr_handler_list[256];

#if defined(ewarm)
u32
CPUipsr(void)
{
    //
    // Read IPSR.
    //
    __asm("    mrs     r0, IPSR\n");

    //
    // "Warning[Pe940]: missing return statement at end of non-void function"
    // is suppressed here to avoid putting a "bx lr" in the inline assembly
    // above and a superfluous return statement here.
    //
#pragma diag_suppress=Pe940
}
#pragma diag_default=Pe940
#endif
#if defined(ccs)
u32
CPUipsr(void)
{
    //
    // Read IPSR.
    //
    __asm("    mrs     r0, IPSR\n"
          "    bx      lr\n");

    //
    // The following keeps the compiler happy, because it wants to see a
    // return value from this function.  It will generate code to return
    // a zero.  However, the real return is the "bx lr" above, so the
    // return(0) is never executed and the function returns with the value
    // you expect in R0.
    //
    return(0);
}
#endif


void global_intr_handler()
{
        u32 intr_num;
        
        /* Get the IPSR register value */
        intr_num = CPUipsr();
        /* Get the exception number */
        intr_num &= 0xFF;

        /* Invoke the registered interrupt handler with the associated param */
        isr_handler_list[intr_num].reg_intr_handler(
                isr_handler_list[intr_num].intr_param);
}

i32 register_isr(u8 irqvec_id, 
                        void (*intr_handler)(void *), 
                        void *param)
{
        /* Setup the ISR handler list to be used to invoke on interrupt 
           occurance. The new setting will override the older ones always */
        isr_handler_list[irqvec_id].reg_intr_handler = intr_handler;
        isr_handler_list[irqvec_id].intr_param = param;

        osi_InterruptRegister(irqvec_id, (P_OSI_INTR_ENTRY)global_intr_handler, (1 << 5));
        if(INT_PRCM == irqvec_id) {
                MAP_PRCMIntEnable(PRCM_INT_SLOW_CLK_CTR);
        }

        return 0;
}
