//*****************************************************************************
//
// comp.h - Prototypes for the analog comparator driver.
//
// Copyright (c) 2005-2013 Texas Instruments Incorporated.  All rights reserved.
// Software License Agreement
// 
//   Redistribution and use in source and binary forms, with or without
//   modification, are permitted provided that the following conditions
//   are met:
// 
//   Redistributions of source code must retain the above copyright
//   notice, this list of conditions and the following disclaimer.
// 
//   Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the
//   documentation and/or other materials provided with the  
//   distribution.
// 
//   Neither the name of Texas Instruments Incorporated nor the names of
//   its contributors may be used to endorse or promote products derived
//   from this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// 
// This is part of revision 2.0.1.11577 of the Tiva Peripheral Driver Library.
//
//*****************************************************************************

#ifndef __DRIVERLIB_COMP_H__
#define __DRIVERLIB_COMP_H__

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

//*****************************************************************************
//
// Values that can be passed to ComparatorConfigure() as the ui32Config
// parameter.  For each group (in other words, COMP_TRIG_xxx, COMP_INT_xxx, and
// so on), one of the values may be selected and combined together with values
// from the other groups via a logical OR.
//
//*****************************************************************************
#define COMP_TRIG_NONE          0x00000000  // No ADC trigger
#define COMP_TRIG_HIGH          0x00000880  // Trigger when high
#define COMP_TRIG_LOW           0x00000800  // Trigger when low
#define COMP_TRIG_FALL          0x00000820  // Trigger on falling edge
#define COMP_TRIG_RISE          0x00000840  // Trigger on rising edge
#define COMP_TRIG_BOTH          0x00000860  // Trigger on both edges
#define COMP_INT_HIGH           0x00000010  // Interrupt when high
#define COMP_INT_LOW            0x00000000  // Interrupt when low
#define COMP_INT_FALL           0x00000004  // Interrupt on falling edge
#define COMP_INT_RISE           0x00000008  // Interrupt on rising edge
#define COMP_INT_BOTH           0x0000000C  // Interrupt on both edges
#define COMP_ASRCP_PIN          0x00000000  // Dedicated Comp+ pin
#define COMP_ASRCP_PIN0         0x00000200  // Comp0+ pin
#define COMP_ASRCP_REF          0x00000400  // Internal voltage reference
#define COMP_OUTPUT_NORMAL      0x00000000  // Comparator output normal
#define COMP_OUTPUT_INVERT      0x00000002  // Comparator output inverted

//*****************************************************************************
//
// Values that can be passed to ComparatorSetRef() as the ui32Ref parameter.
//
//*****************************************************************************
#define COMP_REF_OFF            0x00000000  // Turn off the internal reference
#define COMP_REF_0V             0x00000300  // Internal reference of 0V
#define COMP_REF_0_1375V        0x00000301  // Internal reference of 0.1375V
#define COMP_REF_0_275V         0x00000302  // Internal reference of 0.275V
#define COMP_REF_0_4125V        0x00000303  // Internal reference of 0.4125V
#define COMP_REF_0_55V          0x00000304  // Internal reference of 0.55V
#define COMP_REF_0_6875V        0x00000305  // Internal reference of 0.6875V
#define COMP_REF_0_825V         0x00000306  // Internal reference of 0.825V
#define COMP_REF_0_928125V      0x00000201  // Internal reference of 0.928125V
#define COMP_REF_0_9625V        0x00000307  // Internal reference of 0.9625V
#define COMP_REF_1_03125V       0x00000202  // Internal reference of 1.03125V
#define COMP_REF_1_134375V      0x00000203  // Internal reference of 1.134375V
#define COMP_REF_1_1V           0x00000308  // Internal reference of 1.1V
#define COMP_REF_1_2375V        0x00000309  // Internal reference of 1.2375V
#define COMP_REF_1_340625V      0x00000205  // Internal reference of 1.340625V
#define COMP_REF_1_375V         0x0000030A  // Internal reference of 1.375V
#define COMP_REF_1_44375V       0x00000206  // Internal reference of 1.44375V
#define COMP_REF_1_5125V        0x0000030B  // Internal reference of 1.5125V
#define COMP_REF_1_546875V      0x00000207  // Internal reference of 1.546875V
#define COMP_REF_1_65V          0x0000030C  // Internal reference of 1.65V
#define COMP_REF_1_753125V      0x00000209  // Internal reference of 1.753125V
#define COMP_REF_1_7875V        0x0000030D  // Internal reference of 1.7875V
#define COMP_REF_1_85625V       0x0000020A  // Internal reference of 1.85625V
#define COMP_REF_1_925V         0x0000030E  // Internal reference of 1.925V
#define COMP_REF_1_959375V      0x0000020B  // Internal reference of 1.959375V
#define COMP_REF_2_0625V        0x0000030F  // Internal reference of 2.0625V
#define COMP_REF_2_165625V      0x0000020D  // Internal reference of 2.165625V
#define COMP_REF_2_26875V       0x0000020E  // Internal reference of 2.26875V
#define COMP_REF_2_371875V      0x0000020F  // Internal reference of 2.371875V

//*****************************************************************************
//
// Prototypes for the APIs.
//
//*****************************************************************************
extern void ComparatorConfigure(uint32_t ui32Base, uint32_t ui32Comp,
                                uint32_t ui32Config);
extern void ComparatorRefSet(uint32_t ui32Base, uint32_t ui32Ref);
extern bool ComparatorValueGet(uint32_t ui32Base, uint32_t ui32Comp);
extern void ComparatorIntRegister(uint32_t ui32Base, uint32_t ui32Comp,
                                  void (*pfnHandler)(void));
extern void ComparatorIntUnregister(uint32_t ui32Base, uint32_t ui32Comp);
extern void ComparatorIntEnable(uint32_t ui32Base, uint32_t ui32Comp);
extern void ComparatorIntDisable(uint32_t ui32Base, uint32_t ui32Comp);
extern bool ComparatorIntStatus(uint32_t ui32Base, uint32_t ui32Comp,
                                bool bMasked);
extern void ComparatorIntClear(uint32_t ui32Base, uint32_t ui32Comp);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif // __DRIVERLIB_COMP_H__
