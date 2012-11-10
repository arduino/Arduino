//*****************************************************************************
//
// hw_comp.h - Macros used when accessing the comparator hardware.
//
// Copyright (c) 2005-2012 Texas Instruments Incorporated.  All rights reserved.
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
// This is part of revision 9453 of the Stellaris Firmware Development Package.
//
//*****************************************************************************

#ifndef __HW_COMP_H__
#define __HW_COMP_H__

//*****************************************************************************
//
// The following are defines for the Comparator register offsets.
//
//*****************************************************************************
#define COMP_O_ACMIS            0x00000000  // Analog Comparator Masked
                                            // Interrupt Status
#define COMP_O_ACRIS            0x00000004  // Analog Comparator Raw Interrupt
                                            // Status
#define COMP_O_ACINTEN          0x00000008  // Analog Comparator Interrupt
                                            // Enable
#define COMP_O_ACREFCTL         0x00000010  // Analog Comparator Reference
                                            // Voltage Control
#define COMP_O_ACSTAT0          0x00000020  // Analog Comparator Status 0
#define COMP_O_ACCTL0           0x00000024  // Analog Comparator Control 0
#define COMP_O_ACSTAT1          0x00000040  // Analog Comparator Status 1
#define COMP_O_ACCTL1           0x00000044  // Analog Comparator Control 1
#define COMP_O_ACSTAT2          0x00000060  // Analog Comparator Status 2
#define COMP_O_ACCTL2           0x00000064  // Analog Comparator Control 2
#define COMP_O_PP               0x00000FC0  // Analog Comparator Peripheral
                                            // Properties

//*****************************************************************************
//
// The following are defines for the bit fields in the COMP_O_ACMIS register.
//
//*****************************************************************************
#define COMP_ACMIS_IN2          0x00000004  // Comparator 2 Masked Interrupt
                                            // Status
#define COMP_ACMIS_IN1          0x00000002  // Comparator 1 Masked Interrupt
                                            // Status
#define COMP_ACMIS_IN0          0x00000001  // Comparator 0 Masked Interrupt
                                            // Status

//*****************************************************************************
//
// The following are defines for the bit fields in the COMP_O_ACRIS register.
//
//*****************************************************************************
#define COMP_ACRIS_IN2          0x00000004  // Comparator 2 Interrupt Status
#define COMP_ACRIS_IN1          0x00000002  // Comparator 1 Interrupt Status
#define COMP_ACRIS_IN0          0x00000001  // Comparator 0 Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the COMP_O_ACINTEN register.
//
//*****************************************************************************
#define COMP_ACINTEN_IN2        0x00000004  // Comparator 2 Interrupt Enable
#define COMP_ACINTEN_IN1        0x00000002  // Comparator 1 Interrupt Enable
#define COMP_ACINTEN_IN0        0x00000001  // Comparator 0 Interrupt Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the COMP_O_ACREFCTL
// register.
//
//*****************************************************************************
#define COMP_ACREFCTL_EN        0x00000200  // Resistor Ladder Enable
#define COMP_ACREFCTL_RNG       0x00000100  // Resistor Ladder Range
#define COMP_ACREFCTL_VREF_M    0x0000000F  // Resistor Ladder Voltage Ref
#define COMP_ACREFCTL_VREF_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the COMP_O_ACSTAT0 register.
//
//*****************************************************************************
#define COMP_ACSTAT0_OVAL       0x00000002  // Comparator Output Value

//*****************************************************************************
//
// The following are defines for the bit fields in the COMP_O_ACCTL0 register.
//
//*****************************************************************************
#define COMP_ACCTL0_TOEN        0x00000800  // Trigger Output Enable
#define COMP_ACCTL0_ASRCP_M     0x00000600  // Analog Source Positive
#define COMP_ACCTL0_ASRCP_PIN   0x00000000  // Pin value of Cn+
#define COMP_ACCTL0_ASRCP_PIN0  0x00000200  // Pin value of C0+
#define COMP_ACCTL0_ASRCP_REF   0x00000400  // Internal voltage reference
#define COMP_ACCTL0_TSLVAL      0x00000080  // Trigger Sense Level Value
#define COMP_ACCTL0_TSEN_M      0x00000060  // Trigger Sense
#define COMP_ACCTL0_TSEN_LEVEL  0x00000000  // Level sense, see TSLVAL
#define COMP_ACCTL0_TSEN_FALL   0x00000020  // Falling edge
#define COMP_ACCTL0_TSEN_RISE   0x00000040  // Rising edge
#define COMP_ACCTL0_TSEN_BOTH   0x00000060  // Either edge
#define COMP_ACCTL0_ISLVAL      0x00000010  // Interrupt Sense Level Value
#define COMP_ACCTL0_ISEN_M      0x0000000C  // Interrupt Sense
#define COMP_ACCTL0_ISEN_LEVEL  0x00000000  // Level sense, see ISLVAL
#define COMP_ACCTL0_ISEN_FALL   0x00000004  // Falling edge
#define COMP_ACCTL0_ISEN_RISE   0x00000008  // Rising edge
#define COMP_ACCTL0_ISEN_BOTH   0x0000000C  // Either edge
#define COMP_ACCTL0_CINV        0x00000002  // Comparator Output Invert

//*****************************************************************************
//
// The following are defines for the bit fields in the COMP_O_ACSTAT1 register.
//
//*****************************************************************************
#define COMP_ACSTAT1_OVAL       0x00000002  // Comparator Output Value

//*****************************************************************************
//
// The following are defines for the bit fields in the COMP_O_ACCTL1 register.
//
//*****************************************************************************
#define COMP_ACCTL1_TOEN        0x00000800  // Trigger Output Enable
#define COMP_ACCTL1_ASRCP_M     0x00000600  // Analog Source Positive
#define COMP_ACCTL1_ASRCP_PIN   0x00000000  // Pin value of Cn+
#define COMP_ACCTL1_ASRCP_PIN0  0x00000200  // Pin value of C0+
#define COMP_ACCTL1_ASRCP_REF   0x00000400  // Internal voltage reference
                                            // (VIREF)
#define COMP_ACCTL1_TSLVAL      0x00000080  // Trigger Sense Level Value
#define COMP_ACCTL1_TSEN_M      0x00000060  // Trigger Sense
#define COMP_ACCTL1_TSEN_LEVEL  0x00000000  // Level sense, see TSLVAL
#define COMP_ACCTL1_TSEN_FALL   0x00000020  // Falling edge
#define COMP_ACCTL1_TSEN_RISE   0x00000040  // Rising edge
#define COMP_ACCTL1_TSEN_BOTH   0x00000060  // Either edge
#define COMP_ACCTL1_ISLVAL      0x00000010  // Interrupt Sense Level Value
#define COMP_ACCTL1_ISEN_M      0x0000000C  // Interrupt Sense
#define COMP_ACCTL1_ISEN_LEVEL  0x00000000  // Level sense, see ISLVAL
#define COMP_ACCTL1_ISEN_FALL   0x00000004  // Falling edge
#define COMP_ACCTL1_ISEN_RISE   0x00000008  // Rising edge
#define COMP_ACCTL1_ISEN_BOTH   0x0000000C  // Either edge
#define COMP_ACCTL1_CINV        0x00000002  // Comparator Output Invert

//*****************************************************************************
//
// The following are defines for the bit fields in the COMP_O_ACSTAT2 register.
//
//*****************************************************************************
#define COMP_ACSTAT2_OVAL       0x00000002  // Comparator Output Value

//*****************************************************************************
//
// The following are defines for the bit fields in the COMP_O_ACCTL2 register.
//
//*****************************************************************************
#define COMP_ACCTL2_TOEN        0x00000800  // Trigger Output Enable
#define COMP_ACCTL2_ASRCP_M     0x00000600  // Analog Source Positive
#define COMP_ACCTL2_ASRCP_PIN   0x00000000  // Pin value of Cn+
#define COMP_ACCTL2_ASRCP_PIN0  0x00000200  // Pin value of C0+
#define COMP_ACCTL2_ASRCP_REF   0x00000400  // Internal voltage reference
                                            // (VIREF)
#define COMP_ACCTL2_TSLVAL      0x00000080  // Trigger Sense Level Value
#define COMP_ACCTL2_TSEN_M      0x00000060  // Trigger Sense
#define COMP_ACCTL2_TSEN_LEVEL  0x00000000  // Level sense, see TSLVAL
#define COMP_ACCTL2_TSEN_FALL   0x00000020  // Falling edge
#define COMP_ACCTL2_TSEN_RISE   0x00000040  // Rising edge
#define COMP_ACCTL2_TSEN_BOTH   0x00000060  // Either edge
#define COMP_ACCTL2_ISLVAL      0x00000010  // Interrupt Sense Level Value
#define COMP_ACCTL2_ISEN_M      0x0000000C  // Interrupt Sense
#define COMP_ACCTL2_ISEN_LEVEL  0x00000000  // Level sense, see ISLVAL
#define COMP_ACCTL2_ISEN_FALL   0x00000004  // Falling edge
#define COMP_ACCTL2_ISEN_RISE   0x00000008  // Rising edge
#define COMP_ACCTL2_ISEN_BOTH   0x0000000C  // Either edge
#define COMP_ACCTL2_CINV        0x00000002  // Comparator Output Invert

//*****************************************************************************
//
// The following are defines for the bit fields in the COMP_O_PP register.
//
//*****************************************************************************
#define COMP_PP_C2O             0x00040000  // Comparator Output 2 Present
#define COMP_PP_C1O             0x00020000  // Comparator Output 1 Present
#define COMP_PP_C0O             0x00010000  // Comparator Output 0 Present
#define COMP_PP_CMP2            0x00000004  // Comparator 2 Present
#define COMP_PP_CMP1            0x00000002  // Comparator 1 Present
#define COMP_PP_CMP0            0x00000001  // Comparator 0 Present

//*****************************************************************************
//
// The following definitions are deprecated.
//
//*****************************************************************************
#ifndef DEPRECATED

//*****************************************************************************
//
// The following are deprecated defines for the Comparator register offsets.
//
//*****************************************************************************
#define COMP_O_MIS              0x00000000  // Interrupt status register
#define COMP_O_RIS              0x00000004  // Raw interrupt status register
#define COMP_O_INTEN            0x00000008  // Interrupt enable register
#define COMP_O_REFCTL           0x00000010  // Reference voltage control reg

//*****************************************************************************
//
// The following are deprecated defines for the bit fields in the COMP_O_REFCTL
// register.
//
//*****************************************************************************
#define COMP_REFCTL_EN          0x00000200  // Reference voltage enable
#define COMP_REFCTL_RNG         0x00000100  // Reference voltage range
#define COMP_REFCTL_VREF_MASK   0x0000000F  // Reference voltage select mask
#define COMP_REFCTL_VREF_SHIFT  0

//*****************************************************************************
//
// The following are deprecated defines for the bit fields in the COMP_MIS,
// COMP_RIS, and COMP_INTEN registers.
//
//*****************************************************************************
#define COMP_INT_2              0x00000004  // Comp2 interrupt
#define COMP_INT_1              0x00000002  // Comp1 interrupt
#define COMP_INT_0              0x00000001  // Comp0 interrupt

//*****************************************************************************
//
// The following are deprecated defines for the bit fields in the COMP_ACSTAT0,
// COMP_ACSTAT1, and COMP_ACSTAT2 registers.
//
//*****************************************************************************
#define COMP_ACSTAT_OVAL        0x00000002  // Comparator output value

//*****************************************************************************
//
// The following are deprecated defines for the bit fields in the COMP_ACCTL0,
// COMP_ACCTL1, and COMP_ACCTL2 registers.
//
//*****************************************************************************
#define COMP_ACCTL_TMASK        0x00000800  // Trigger enable
#define COMP_ACCTL_ASRCP_MASK   0x00000600  // Vin+ source select mask
#define COMP_ACCTL_ASRCP_PIN    0x00000000  // Dedicated Comp+ pin
#define COMP_ACCTL_ASRCP_PIN0   0x00000200  // Comp0+ pin
#define COMP_ACCTL_ASRCP_REF    0x00000400  // Internal voltage reference
#define COMP_ACCTL_ASRCP_RES    0x00000600  // Reserved
#define COMP_ACCTL_OEN          0x00000100  // Comparator output enable
#define COMP_ACCTL_TSVAL        0x00000080  // Trigger polarity select
#define COMP_ACCTL_TSEN_MASK    0x00000060  // Trigger sense mask
#define COMP_ACCTL_TSEN_LEVEL   0x00000000  // Trigger is level sense
#define COMP_ACCTL_TSEN_FALL    0x00000020  // Trigger is falling edge
#define COMP_ACCTL_TSEN_RISE    0x00000040  // Trigger is rising edge
#define COMP_ACCTL_TSEN_BOTH    0x00000060  // Trigger is both edges
#define COMP_ACCTL_ISLVAL       0x00000010  // Interrupt polarity select
#define COMP_ACCTL_ISEN_MASK    0x0000000C  // Interrupt sense mask
#define COMP_ACCTL_ISEN_LEVEL   0x00000000  // Interrupt is level sense
#define COMP_ACCTL_ISEN_FALL    0x00000004  // Interrupt is falling edge
#define COMP_ACCTL_ISEN_RISE    0x00000008  // Interrupt is rising edge
#define COMP_ACCTL_ISEN_BOTH    0x0000000C  // Interrupt is both edges
#define COMP_ACCTL_CINV         0x00000002  // Comparator output invert

//*****************************************************************************
//
// The following are deprecated defines for the reset values for the comparator
// registers.
//
//*****************************************************************************
#define COMP_RV_ACCTL1          0x00000000  // Comp1 control register
#define COMP_RV_ACSTAT2         0x00000000  // Comp2 status register
#define COMP_RV_ACSTAT0         0x00000000  // Comp0 status register
#define COMP_RV_RIS             0x00000000  // Raw interrupt status register
#define COMP_RV_INTEN           0x00000000  // Interrupt enable register
#define COMP_RV_ACCTL2          0x00000000  // Comp2 control register
#define COMP_RV_MIS             0x00000000  // Interrupt status register
#define COMP_RV_ACCTL0          0x00000000  // Comp0 control register
#define COMP_RV_ACSTAT1         0x00000000  // Comp1 status register
#define COMP_RV_REFCTL          0x00000000  // Reference voltage control reg

#endif

#endif // __HW_COMP_H__
