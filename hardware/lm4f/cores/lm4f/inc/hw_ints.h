//*****************************************************************************
//
// hw_ints.h - Macros that define the interrupt assignment on Stellaris.
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

#ifndef __HW_INTS_H__
#define __HW_INTS_H__

//*****************************************************************************
//
// The following are defines for the fault assignments.
//
//*****************************************************************************
#define FAULT_NMI               2           // NMI fault
#define FAULT_HARD              3           // Hard fault
#define FAULT_MPU               4           // MPU fault
#define FAULT_BUS               5           // Bus fault
#define FAULT_USAGE             6           // Usage fault
#define FAULT_SVCALL            11          // SVCall
#define FAULT_DEBUG             12          // Debug monitor
#define FAULT_PENDSV            14          // PendSV
#define FAULT_SYSTICK           15          // System Tick

//*****************************************************************************
//
// The following are defines for the interrupt assignments.
//
//*****************************************************************************
#define INT_GPIOA               16          // GPIO Port A
#define INT_GPIOB               17          // GPIO Port B
#define INT_GPIOC               18          // GPIO Port C
#define INT_GPIOD               19          // GPIO Port D
#define INT_GPIOE               20          // GPIO Port E
#define INT_UART0               21          // UART0 Rx and Tx
#define INT_UART1               22          // UART1 Rx and Tx
#define INT_SSI0                23          // SSI0 Rx and Tx
#define INT_I2C0                24          // I2C0 Master and Slave
#define INT_PWM0_FAULT          25          // PWM0 Fault
#define INT_PWM0_0              26          // PWM0 Generator 0
#define INT_PWM0_1              27          // PWM0 Generator 1
#define INT_PWM0_2              28          // PWM0 Generator 2
#define INT_QEI0                29          // Quadrature Encoder 0
#define INT_ADC0SS0             30          // ADC0 Sequence 0
#define INT_ADC0SS1             31          // ADC0 Sequence 1
#define INT_ADC0SS2             32          // ADC0 Sequence 2
#define INT_ADC0SS3             33          // ADC0 Sequence 3
#define INT_WATCHDOG            34          // Watchdog timer
#define INT_TIMER0A             35          // Timer 0 subtimer A
#define INT_TIMER0B             36          // Timer 0 subtimer B
#define INT_TIMER1A             37          // Timer 1 subtimer A
#define INT_TIMER1B             38          // Timer 1 subtimer B
#define INT_TIMER2A             39          // Timer 2 subtimer A
#define INT_TIMER2B             40          // Timer 2 subtimer B
#define INT_COMP0               41          // Analog Comparator 0
#define INT_COMP1               42          // Analog Comparator 1
#define INT_COMP2               43          // Analog Comparator 2
#define INT_SYSCTL              44          // System Control (PLL, OSC, BO)
#define INT_FLASH               45          // FLASH Control
#define INT_GPIOF               46          // GPIO Port F
#define INT_GPIOG               47          // GPIO Port G
#define INT_GPIOH               48          // GPIO Port H
#define INT_UART2               49          // UART2 Rx and Tx
#define INT_SSI1                50          // SSI1 Rx and Tx
#define INT_TIMER3A             51          // Timer 3 subtimer A
#define INT_TIMER3B             52          // Timer 3 subtimer B
#define INT_I2C1                53          // I2C1 Master and Slave
#define INT_QEI1                54          // Quadrature Encoder 1
#define INT_CAN0                55          // CAN0
#define INT_CAN1                56          // CAN1
#define INT_CAN2                57          // CAN2
#define INT_ETH                 58          // Ethernet
#define INT_HIBERNATE           59          // Hibernation module
#define INT_USB0                60          // USB 0 Controller
#define INT_PWM0_3              61          // PWM0 Generator 3
#define INT_UDMA                62          // uDMA controller
#define INT_UDMAERR             63          // uDMA Error
#define INT_ADC1SS0             64          // ADC1 Sequence 0
#define INT_ADC1SS1             65          // ADC1 Sequence 1
#define INT_ADC1SS2             66          // ADC1 Sequence 2
#define INT_ADC1SS3             67          // ADC1 Sequence 3
#define INT_I2S0                68          // I2S0
#define INT_EPI0                69          // EPI0
#define INT_GPIOJ               70          // GPIO Port J
#define INT_GPIOK               71          // GPIO Port K
#define INT_GPIOL               72          // GPIO Port L
#define INT_SSI2                73          // SSI2
#define INT_SSI3                74          // SSI3
#define INT_UART3               75          // UART3
#define INT_UART4               76          // UART4
#define INT_UART5               77          // UART5
#define INT_UART6               78          // UART6
#define INT_UART7               79          // UART7
#define INT_I2C2                84          // I2C2
#define INT_I2C3                85          // I2C3
#define INT_TIMER4A             86          // Timer 4A
#define INT_TIMER4B             87          // Timer 4B
#define INT_TIMER5A             108         // Timer 5A
#define INT_TIMER5B             109         // Timer 5B
#define INT_WTIMER0A            110         // Wide Timer 0A
#define INT_WTIMER0B            111         // Wide Timer 0B
#define INT_WTIMER1A            112         // Wide Timer 1A
#define INT_WTIMER1B            113         // Wide Timer 1B
#define INT_WTIMER2A            114         // Wide Timer 2A
#define INT_WTIMER2B            115         // Wide Timer 2B
#define INT_WTIMER3A            116         // Wide Timer 3A
#define INT_WTIMER3B            117         // Wide Timer 3B
#define INT_WTIMER4A            118         // Wide Timer 4A
#define INT_WTIMER4B            119         // Wide Timer 4B
#define INT_WTIMER5A            120         // Wide Timer 5A
#define INT_WTIMER5B            121         // Wide Timer 5B
#define INT_SYSEXC              122         // System Exception (imprecise)
#define INT_PECI0               123         // PECI 0
#define INT_LPC0                124         // LPC 0
#define INT_I2C4                125         // I2C4
#define INT_I2C5                126         // I2C5
#define INT_GPIOM               127         // GPIO Port M
#define INT_GPION               128         // GPIO Port N
#define INT_FAN0                130         // FAN 0
#define INT_GPIOP0              132         // GPIO Port P (Summary or P0)
#define INT_GPIOP1              133         // GPIO Port P1
#define INT_GPIOP2              134         // GPIO Port P2
#define INT_GPIOP3              135         // GPIO Port P3
#define INT_GPIOP4              136         // GPIO Port P4
#define INT_GPIOP5              137         // GPIO Port P5
#define INT_GPIOP6              138         // GPIO Port P6
#define INT_GPIOP7              139         // GPIO Port P7
#define INT_GPIOQ0              140         // GPIO Port Q (Summary or Q0)
#define INT_GPIOQ1              141         // GPIO Port Q1
#define INT_GPIOQ2              142         // GPIO Port Q2
#define INT_GPIOQ3              143         // GPIO Port Q3
#define INT_GPIOQ4              144         // GPIO Port Q4
#define INT_GPIOQ5              145         // GPIO Port Q5
#define INT_GPIOQ6              146         // GPIO Port Q6
#define INT_GPIOQ7              147         // GPIO Port Q7
#define INT_PWM1_0              150         // PWM1 Generator 0
#define INT_PWM1_1              151         // PWM1 Generator 1
#define INT_PWM1_2              152         // PWM1 Generator 2
#define INT_PWM1_3              153         // PWM1 Generator 3
#define INT_PWM1_FAULT          154         // PWM1 Fault

//*****************************************************************************
//
// The following are defines for the total number of interrupts.
//
//*****************************************************************************
#define NUM_INTERRUPTS          155

//*****************************************************************************
//
// The following are defines for the total number of priority levels.
//
//*****************************************************************************
#define NUM_PRIORITY            8
#define NUM_PRIORITY_BITS       3

//*****************************************************************************
//
// The following definitions are deprecated.
//
//*****************************************************************************
#ifndef DEPRECATED

//*****************************************************************************
//
// The following are deprecated defines for the interrupt assignments.
//
//*****************************************************************************
#define INT_SSI                 23          // SSI Rx and Tx
#define INT_I2C                 24          // I2C Master and Slave
#define INT_PWM_FAULT           25          // PWM Fault
#define INT_PWM0                26          // PWM Generator 0
#define INT_PWM1                27          // PWM Generator 1
#define INT_PWM2                28          // PWM Generator 2
#define INT_QEI                 29          // Quadrature Encoder
#define INT_ADC0                30          // ADC Sequence 0
#define INT_ADC1                31          // ADC Sequence 1
#define INT_ADC2                32          // ADC Sequence 2
#define INT_ADC3                33          // ADC Sequence 3
#define INT_PWM3                61          // PWM Generator 3

#endif

#endif // __HW_INTS_H__
