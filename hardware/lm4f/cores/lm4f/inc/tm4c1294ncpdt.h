//*****************************************************************************
//
// tm4c1294ncpdt.h - TM4C1294NCPDT Register Definitions
//
// Copyright (c) 2013 Texas Instruments Incorporated.  All rights reserved.
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
// This is part of revision 2.0.1.11577 of the Tiva Firmware Development Package.
//
//*****************************************************************************

#ifndef __TM4C1294NCPDT_H__
#define __TM4C1294NCPDT_H__

//*****************************************************************************
//
// Interrupt assignments
//
//*****************************************************************************
#define INT_GPIOA               16          // GPIO Port A
#define INT_GPIOB               17          // GPIO Port B
#define INT_GPIOC               18          // GPIO Port C
#define INT_GPIOD               19          // GPIO Port D
#define INT_GPIOE               20          // GPIO Port E
#define INT_UART0               21          // UART0
#define INT_UART1               22          // UART1
#define INT_SSI0                23          // SSI0
#define INT_I2C0                24          // I2C0
#define INT_PWM0_FAULT          25          // PWM Fault
#define INT_PWM0_0              26          // PWM Generator 0
#define INT_PWM0_1              27          // PWM Generator 1
#define INT_PWM0_2              28          // PWM Generator 2
#define INT_QEI0                29          // QEI0
#define INT_ADC0SS0             30          // ADC0 Sequence 0
#define INT_ADC0SS1             31          // ADC0 Sequence 1
#define INT_ADC0SS2             32          // ADC0 Sequence 2
#define INT_ADC0SS3             33          // ADC0 Sequence 3
#define INT_WATCHDOG            34          // Watchdog Timers 0 and 1
#define INT_TIMER0A             35          // 16/32-Bit Timer 0A
#define INT_TIMER0B             36          // 16/32-Bit Timer 0B
#define INT_TIMER1A             37          // 16/32-Bit Timer 1A
#define INT_TIMER1B             38          // 16/32-Bit Timer 1B
#define INT_TIMER2A             39          // 16/32-Bit Timer 2A
#define INT_TIMER2B             40          // 16/32-Bit Timer 2B
#define INT_COMP0               41          // Analog Comparator 0
#define INT_COMP1               42          // Analog Comparator 1
#define INT_COMP2               43          // Analog Comparator 2
#define INT_SYSCTL              44          // System Control
#define INT_FLASH               45          // Flash Memory Control
#define INT_GPIOF               46          // GPIO Port F
#define INT_GPIOG               47          // GPIO Port G
#define INT_GPIOH               48          // GPIO Port H
#define INT_UART2               49          // UART2
#define INT_SSI1                50          // SSI1
#define INT_TIMER3A             51          // 16/32-Bit Timer 3A
#define INT_TIMER3B             52          // 16/32-Bit Timer 3B
#define INT_I2C1                53          // I2C1
#define INT_CAN0                54          // CAN 0
#define INT_CAN1                55          // CAN1
#define INT_EMAC0               56          // Ethernet MAC
#define INT_HIBERNATE           57          // HIB (Power Island)
#define INT_USB0                58          // USB MAC
#define INT_PWM0_3              59          // PWM Generator 3
#define INT_UDMA                60          // uDMA 0 Software
#define INT_UDMAERR             61          // uDMA 0 Error
#define INT_ADC1SS0             62          // ADC1 Sequence 0
#define INT_ADC1SS1             63          // ADC1 Sequence 1
#define INT_ADC1SS2             64          // ADC1 Sequence 2
#define INT_ADC1SS3             65          // ADC1 Sequence 3
#define INT_EPI0                66          // EPI 0
#define INT_GPIOJ               67          // GPIO Port J
#define INT_GPIOK               68          // GPIO Port K
#define INT_GPIOL               69          // GPIO Port L
#define INT_SSI2                70          // SSI 2
#define INT_SSI3                71          // SSI 3
#define INT_UART3               72          // UART 3
#define INT_UART4               73          // UART 4
#define INT_UART5               74          // UART 5
#define INT_UART6               75          // UART 6
#define INT_UART7               76          // UART 7
#define INT_I2C2                77          // I2C 2
#define INT_I2C3                78          // I2C 3
#define INT_TIMER4A             79          // Timer 4A
#define INT_TIMER4B             80          // Timer 4B
#define INT_TIMER5A             81          // Timer 5A
#define INT_TIMER5B             82          // Timer 5B
#define INT_SYSEXC              83          // Floating-Point Exception
                                            // (imprecise)
#define INT_I2C4                86          // I2C 4
#define INT_I2C5                87          // I2C 5
#define INT_GPIOM               88          // GPIO Port M
#define INT_GPION               89          // GPIO Port N
#define INT_TAMPER0             91          // Tamper
#define INT_GPIOP0              92          // GPIO Port P (Summary or P0)
#define INT_GPIOP1              93          // GPIO Port P1
#define INT_GPIOP2              94          // GPIO Port P2
#define INT_GPIOP3              95          // GPIO Port P3
#define INT_GPIOP4              96          // GPIO Port P4
#define INT_GPIOP5              97          // GPIO Port P5
#define INT_GPIOP6              98          // GPIO Port P6
#define INT_GPIOP7              99          // GPIO Port P7
#define INT_GPIOQ0              100         // GPIO Port Q (Summary or Q0)
#define INT_GPIOQ1              101         // GPIO Port Q1
#define INT_GPIOQ2              102         // GPIO Port Q2
#define INT_GPIOQ3              103         // GPIO Port Q3
#define INT_GPIOQ4              104         // GPIO Port Q4
#define INT_GPIOQ5              105         // GPIO Port Q5
#define INT_GPIOQ6              106         // GPIO Port Q6
#define INT_GPIOQ7              107         // GPIO Port Q7
#define INT_TIMER6A             114         // 16/32-Bit Timer 6A
#define INT_TIMER6B             115         // 16/32-Bit Timer 6B
#define INT_TIMER7A             116         // 16/32-Bit Timer 7A
#define INT_TIMER7B             117         // 16/32-Bit Timer 7B
#define INT_I2C6                118         // I2C 6
#define INT_I2C7                119         // I2C 7
#define INT_I2C8                125         // I2C 8
#define INT_I2C9                126         // I2C 9

//*****************************************************************************
//
// Watchdog Timer registers (WATCHDOG0)
//
//*****************************************************************************
#define WATCHDOG0_LOAD_R        (*((volatile uint32_t *)0x40000000))
#define WATCHDOG0_VALUE_R       (*((volatile uint32_t *)0x40000004))
#define WATCHDOG0_CTL_R         (*((volatile uint32_t *)0x40000008))
#define WATCHDOG0_ICR_R         (*((volatile uint32_t *)0x4000000C))
#define WATCHDOG0_RIS_R         (*((volatile uint32_t *)0x40000010))
#define WATCHDOG0_MIS_R         (*((volatile uint32_t *)0x40000014))
#define WATCHDOG0_TEST_R        (*((volatile uint32_t *)0x40000418))
#define WATCHDOG0_LOCK_R        (*((volatile uint32_t *)0x40000C00))

//*****************************************************************************
//
// Watchdog Timer registers (WATCHDOG1)
//
//*****************************************************************************
#define WATCHDOG1_LOAD_R        (*((volatile uint32_t *)0x40001000))
#define WATCHDOG1_VALUE_R       (*((volatile uint32_t *)0x40001004))
#define WATCHDOG1_CTL_R         (*((volatile uint32_t *)0x40001008))
#define WATCHDOG1_ICR_R         (*((volatile uint32_t *)0x4000100C))
#define WATCHDOG1_RIS_R         (*((volatile uint32_t *)0x40001010))
#define WATCHDOG1_MIS_R         (*((volatile uint32_t *)0x40001014))
#define WATCHDOG1_TEST_R        (*((volatile uint32_t *)0x40001418))
#define WATCHDOG1_LOCK_R        (*((volatile uint32_t *)0x40001C00))

//*****************************************************************************
//
// SSI registers (SSI0)
//
//*****************************************************************************
#define SSI0_CR0_R              (*((volatile uint32_t *)0x40008000))
#define SSI0_CR1_R              (*((volatile uint32_t *)0x40008004))
#define SSI0_DR_R               (*((volatile uint32_t *)0x40008008))
#define SSI0_SR_R               (*((volatile uint32_t *)0x4000800C))
#define SSI0_CPSR_R             (*((volatile uint32_t *)0x40008010))
#define SSI0_IM_R               (*((volatile uint32_t *)0x40008014))
#define SSI0_RIS_R              (*((volatile uint32_t *)0x40008018))
#define SSI0_MIS_R              (*((volatile uint32_t *)0x4000801C))
#define SSI0_ICR_R              (*((volatile uint32_t *)0x40008020))
#define SSI0_DMACTL_R           (*((volatile uint32_t *)0x40008024))
#define SSI0_PP_R               (*((volatile uint32_t *)0x40008FC0))
#define SSI0_CC_R               (*((volatile uint32_t *)0x40008FC8))

//*****************************************************************************
//
// SSI registers (SSI1)
//
//*****************************************************************************
#define SSI1_CR0_R              (*((volatile uint32_t *)0x40009000))
#define SSI1_CR1_R              (*((volatile uint32_t *)0x40009004))
#define SSI1_DR_R               (*((volatile uint32_t *)0x40009008))
#define SSI1_SR_R               (*((volatile uint32_t *)0x4000900C))
#define SSI1_CPSR_R             (*((volatile uint32_t *)0x40009010))
#define SSI1_IM_R               (*((volatile uint32_t *)0x40009014))
#define SSI1_RIS_R              (*((volatile uint32_t *)0x40009018))
#define SSI1_MIS_R              (*((volatile uint32_t *)0x4000901C))
#define SSI1_ICR_R              (*((volatile uint32_t *)0x40009020))
#define SSI1_DMACTL_R           (*((volatile uint32_t *)0x40009024))
#define SSI1_PP_R               (*((volatile uint32_t *)0x40009FC0))
#define SSI1_CC_R               (*((volatile uint32_t *)0x40009FC8))

//*****************************************************************************
//
// SSI registers (SSI2)
//
//*****************************************************************************
#define SSI2_CR0_R              (*((volatile uint32_t *)0x4000A000))
#define SSI2_CR1_R              (*((volatile uint32_t *)0x4000A004))
#define SSI2_DR_R               (*((volatile uint32_t *)0x4000A008))
#define SSI2_SR_R               (*((volatile uint32_t *)0x4000A00C))
#define SSI2_CPSR_R             (*((volatile uint32_t *)0x4000A010))
#define SSI2_IM_R               (*((volatile uint32_t *)0x4000A014))
#define SSI2_RIS_R              (*((volatile uint32_t *)0x4000A018))
#define SSI2_MIS_R              (*((volatile uint32_t *)0x4000A01C))
#define SSI2_ICR_R              (*((volatile uint32_t *)0x4000A020))
#define SSI2_DMACTL_R           (*((volatile uint32_t *)0x4000A024))
#define SSI2_PP_R               (*((volatile uint32_t *)0x4000AFC0))
#define SSI2_CC_R               (*((volatile uint32_t *)0x4000AFC8))

//*****************************************************************************
//
// SSI registers (SSI3)
//
//*****************************************************************************
#define SSI3_CR0_R              (*((volatile uint32_t *)0x4000B000))
#define SSI3_CR1_R              (*((volatile uint32_t *)0x4000B004))
#define SSI3_DR_R               (*((volatile uint32_t *)0x4000B008))
#define SSI3_SR_R               (*((volatile uint32_t *)0x4000B00C))
#define SSI3_CPSR_R             (*((volatile uint32_t *)0x4000B010))
#define SSI3_IM_R               (*((volatile uint32_t *)0x4000B014))
#define SSI3_RIS_R              (*((volatile uint32_t *)0x4000B018))
#define SSI3_MIS_R              (*((volatile uint32_t *)0x4000B01C))
#define SSI3_ICR_R              (*((volatile uint32_t *)0x4000B020))
#define SSI3_DMACTL_R           (*((volatile uint32_t *)0x4000B024))
#define SSI3_PP_R               (*((volatile uint32_t *)0x4000BFC0))
#define SSI3_CC_R               (*((volatile uint32_t *)0x4000BFC8))

//*****************************************************************************
//
// UART registers (UART0)
//
//*****************************************************************************
#define UART0_DR_R              (*((volatile uint32_t *)0x4000C000))
#define UART0_RSR_R             (*((volatile uint32_t *)0x4000C004))
#define UART0_ECR_R             (*((volatile uint32_t *)0x4000C004))
#define UART0_FR_R              (*((volatile uint32_t *)0x4000C018))
#define UART0_ILPR_R            (*((volatile uint32_t *)0x4000C020))
#define UART0_IBRD_R            (*((volatile uint32_t *)0x4000C024))
#define UART0_FBRD_R            (*((volatile uint32_t *)0x4000C028))
#define UART0_LCRH_R            (*((volatile uint32_t *)0x4000C02C))
#define UART0_CTL_R             (*((volatile uint32_t *)0x4000C030))
#define UART0_IFLS_R            (*((volatile uint32_t *)0x4000C034))
#define UART0_IM_R              (*((volatile uint32_t *)0x4000C038))
#define UART0_RIS_R             (*((volatile uint32_t *)0x4000C03C))
#define UART0_MIS_R             (*((volatile uint32_t *)0x4000C040))
#define UART0_ICR_R             (*((volatile uint32_t *)0x4000C044))
#define UART0_DMACTL_R          (*((volatile uint32_t *)0x4000C048))
#define UART0_9BITADDR_R        (*((volatile uint32_t *)0x4000C0A4))
#define UART0_9BITAMASK_R       (*((volatile uint32_t *)0x4000C0A8))
#define UART0_PP_R              (*((volatile uint32_t *)0x4000CFC0))
#define UART0_CC_R              (*((volatile uint32_t *)0x4000CFC8))

//*****************************************************************************
//
// UART registers (UART1)
//
//*****************************************************************************
#define UART1_DR_R              (*((volatile uint32_t *)0x4000D000))
#define UART1_RSR_R             (*((volatile uint32_t *)0x4000D004))
#define UART1_ECR_R             (*((volatile uint32_t *)0x4000D004))
#define UART1_FR_R              (*((volatile uint32_t *)0x4000D018))
#define UART1_ILPR_R            (*((volatile uint32_t *)0x4000D020))
#define UART1_IBRD_R            (*((volatile uint32_t *)0x4000D024))
#define UART1_FBRD_R            (*((volatile uint32_t *)0x4000D028))
#define UART1_LCRH_R            (*((volatile uint32_t *)0x4000D02C))
#define UART1_CTL_R             (*((volatile uint32_t *)0x4000D030))
#define UART1_IFLS_R            (*((volatile uint32_t *)0x4000D034))
#define UART1_IM_R              (*((volatile uint32_t *)0x4000D038))
#define UART1_RIS_R             (*((volatile uint32_t *)0x4000D03C))
#define UART1_MIS_R             (*((volatile uint32_t *)0x4000D040))
#define UART1_ICR_R             (*((volatile uint32_t *)0x4000D044))
#define UART1_DMACTL_R          (*((volatile uint32_t *)0x4000D048))
#define UART1_9BITADDR_R        (*((volatile uint32_t *)0x4000D0A4))
#define UART1_9BITAMASK_R       (*((volatile uint32_t *)0x4000D0A8))
#define UART1_PP_R              (*((volatile uint32_t *)0x4000DFC0))
#define UART1_CC_R              (*((volatile uint32_t *)0x4000DFC8))

//*****************************************************************************
//
// UART registers (UART2)
//
//*****************************************************************************
#define UART2_DR_R              (*((volatile uint32_t *)0x4000E000))
#define UART2_RSR_R             (*((volatile uint32_t *)0x4000E004))
#define UART2_ECR_R             (*((volatile uint32_t *)0x4000E004))
#define UART2_FR_R              (*((volatile uint32_t *)0x4000E018))
#define UART2_ILPR_R            (*((volatile uint32_t *)0x4000E020))
#define UART2_IBRD_R            (*((volatile uint32_t *)0x4000E024))
#define UART2_FBRD_R            (*((volatile uint32_t *)0x4000E028))
#define UART2_LCRH_R            (*((volatile uint32_t *)0x4000E02C))
#define UART2_CTL_R             (*((volatile uint32_t *)0x4000E030))
#define UART2_IFLS_R            (*((volatile uint32_t *)0x4000E034))
#define UART2_IM_R              (*((volatile uint32_t *)0x4000E038))
#define UART2_RIS_R             (*((volatile uint32_t *)0x4000E03C))
#define UART2_MIS_R             (*((volatile uint32_t *)0x4000E040))
#define UART2_ICR_R             (*((volatile uint32_t *)0x4000E044))
#define UART2_DMACTL_R          (*((volatile uint32_t *)0x4000E048))
#define UART2_9BITADDR_R        (*((volatile uint32_t *)0x4000E0A4))
#define UART2_9BITAMASK_R       (*((volatile uint32_t *)0x4000E0A8))
#define UART2_PP_R              (*((volatile uint32_t *)0x4000EFC0))
#define UART2_CC_R              (*((volatile uint32_t *)0x4000EFC8))

//*****************************************************************************
//
// UART registers (UART3)
//
//*****************************************************************************
#define UART3_DR_R              (*((volatile uint32_t *)0x4000F000))
#define UART3_RSR_R             (*((volatile uint32_t *)0x4000F004))
#define UART3_ECR_R             (*((volatile uint32_t *)0x4000F004))
#define UART3_FR_R              (*((volatile uint32_t *)0x4000F018))
#define UART3_ILPR_R            (*((volatile uint32_t *)0x4000F020))
#define UART3_IBRD_R            (*((volatile uint32_t *)0x4000F024))
#define UART3_FBRD_R            (*((volatile uint32_t *)0x4000F028))
#define UART3_LCRH_R            (*((volatile uint32_t *)0x4000F02C))
#define UART3_CTL_R             (*((volatile uint32_t *)0x4000F030))
#define UART3_IFLS_R            (*((volatile uint32_t *)0x4000F034))
#define UART3_IM_R              (*((volatile uint32_t *)0x4000F038))
#define UART3_RIS_R             (*((volatile uint32_t *)0x4000F03C))
#define UART3_MIS_R             (*((volatile uint32_t *)0x4000F040))
#define UART3_ICR_R             (*((volatile uint32_t *)0x4000F044))
#define UART3_DMACTL_R          (*((volatile uint32_t *)0x4000F048))
#define UART3_9BITADDR_R        (*((volatile uint32_t *)0x4000F0A4))
#define UART3_9BITAMASK_R       (*((volatile uint32_t *)0x4000F0A8))
#define UART3_PP_R              (*((volatile uint32_t *)0x4000FFC0))
#define UART3_CC_R              (*((volatile uint32_t *)0x4000FFC8))

//*****************************************************************************
//
// UART registers (UART4)
//
//*****************************************************************************
#define UART4_DR_R              (*((volatile uint32_t *)0x40010000))
#define UART4_RSR_R             (*((volatile uint32_t *)0x40010004))
#define UART4_ECR_R             (*((volatile uint32_t *)0x40010004))
#define UART4_FR_R              (*((volatile uint32_t *)0x40010018))
#define UART4_ILPR_R            (*((volatile uint32_t *)0x40010020))
#define UART4_IBRD_R            (*((volatile uint32_t *)0x40010024))
#define UART4_FBRD_R            (*((volatile uint32_t *)0x40010028))
#define UART4_LCRH_R            (*((volatile uint32_t *)0x4001002C))
#define UART4_CTL_R             (*((volatile uint32_t *)0x40010030))
#define UART4_IFLS_R            (*((volatile uint32_t *)0x40010034))
#define UART4_IM_R              (*((volatile uint32_t *)0x40010038))
#define UART4_RIS_R             (*((volatile uint32_t *)0x4001003C))
#define UART4_MIS_R             (*((volatile uint32_t *)0x40010040))
#define UART4_ICR_R             (*((volatile uint32_t *)0x40010044))
#define UART4_DMACTL_R          (*((volatile uint32_t *)0x40010048))
#define UART4_9BITADDR_R        (*((volatile uint32_t *)0x400100A4))
#define UART4_9BITAMASK_R       (*((volatile uint32_t *)0x400100A8))
#define UART4_PP_R              (*((volatile uint32_t *)0x40010FC0))
#define UART4_CC_R              (*((volatile uint32_t *)0x40010FC8))

//*****************************************************************************
//
// UART registers (UART5)
//
//*****************************************************************************
#define UART5_DR_R              (*((volatile uint32_t *)0x40011000))
#define UART5_RSR_R             (*((volatile uint32_t *)0x40011004))
#define UART5_ECR_R             (*((volatile uint32_t *)0x40011004))
#define UART5_FR_R              (*((volatile uint32_t *)0x40011018))
#define UART5_ILPR_R            (*((volatile uint32_t *)0x40011020))
#define UART5_IBRD_R            (*((volatile uint32_t *)0x40011024))
#define UART5_FBRD_R            (*((volatile uint32_t *)0x40011028))
#define UART5_LCRH_R            (*((volatile uint32_t *)0x4001102C))
#define UART5_CTL_R             (*((volatile uint32_t *)0x40011030))
#define UART5_IFLS_R            (*((volatile uint32_t *)0x40011034))
#define UART5_IM_R              (*((volatile uint32_t *)0x40011038))
#define UART5_RIS_R             (*((volatile uint32_t *)0x4001103C))
#define UART5_MIS_R             (*((volatile uint32_t *)0x40011040))
#define UART5_ICR_R             (*((volatile uint32_t *)0x40011044))
#define UART5_DMACTL_R          (*((volatile uint32_t *)0x40011048))
#define UART5_9BITADDR_R        (*((volatile uint32_t *)0x400110A4))
#define UART5_9BITAMASK_R       (*((volatile uint32_t *)0x400110A8))
#define UART5_PP_R              (*((volatile uint32_t *)0x40011FC0))
#define UART5_CC_R              (*((volatile uint32_t *)0x40011FC8))

//*****************************************************************************
//
// UART registers (UART6)
//
//*****************************************************************************
#define UART6_DR_R              (*((volatile uint32_t *)0x40012000))
#define UART6_RSR_R             (*((volatile uint32_t *)0x40012004))
#define UART6_ECR_R             (*((volatile uint32_t *)0x40012004))
#define UART6_FR_R              (*((volatile uint32_t *)0x40012018))
#define UART6_ILPR_R            (*((volatile uint32_t *)0x40012020))
#define UART6_IBRD_R            (*((volatile uint32_t *)0x40012024))
#define UART6_FBRD_R            (*((volatile uint32_t *)0x40012028))
#define UART6_LCRH_R            (*((volatile uint32_t *)0x4001202C))
#define UART6_CTL_R             (*((volatile uint32_t *)0x40012030))
#define UART6_IFLS_R            (*((volatile uint32_t *)0x40012034))
#define UART6_IM_R              (*((volatile uint32_t *)0x40012038))
#define UART6_RIS_R             (*((volatile uint32_t *)0x4001203C))
#define UART6_MIS_R             (*((volatile uint32_t *)0x40012040))
#define UART6_ICR_R             (*((volatile uint32_t *)0x40012044))
#define UART6_DMACTL_R          (*((volatile uint32_t *)0x40012048))
#define UART6_9BITADDR_R        (*((volatile uint32_t *)0x400120A4))
#define UART6_9BITAMASK_R       (*((volatile uint32_t *)0x400120A8))
#define UART6_PP_R              (*((volatile uint32_t *)0x40012FC0))
#define UART6_CC_R              (*((volatile uint32_t *)0x40012FC8))

//*****************************************************************************
//
// UART registers (UART7)
//
//*****************************************************************************
#define UART7_DR_R              (*((volatile uint32_t *)0x40013000))
#define UART7_RSR_R             (*((volatile uint32_t *)0x40013004))
#define UART7_ECR_R             (*((volatile uint32_t *)0x40013004))
#define UART7_FR_R              (*((volatile uint32_t *)0x40013018))
#define UART7_ILPR_R            (*((volatile uint32_t *)0x40013020))
#define UART7_IBRD_R            (*((volatile uint32_t *)0x40013024))
#define UART7_FBRD_R            (*((volatile uint32_t *)0x40013028))
#define UART7_LCRH_R            (*((volatile uint32_t *)0x4001302C))
#define UART7_CTL_R             (*((volatile uint32_t *)0x40013030))
#define UART7_IFLS_R            (*((volatile uint32_t *)0x40013034))
#define UART7_IM_R              (*((volatile uint32_t *)0x40013038))
#define UART7_RIS_R             (*((volatile uint32_t *)0x4001303C))
#define UART7_MIS_R             (*((volatile uint32_t *)0x40013040))
#define UART7_ICR_R             (*((volatile uint32_t *)0x40013044))
#define UART7_DMACTL_R          (*((volatile uint32_t *)0x40013048))
#define UART7_9BITADDR_R        (*((volatile uint32_t *)0x400130A4))
#define UART7_9BITAMASK_R       (*((volatile uint32_t *)0x400130A8))
#define UART7_PP_R              (*((volatile uint32_t *)0x40013FC0))
#define UART7_CC_R              (*((volatile uint32_t *)0x40013FC8))

//*****************************************************************************
//
// I2C registers (I2C0)
//
//*****************************************************************************
#define I2C0_MSA_R              (*((volatile uint32_t *)0x40020000))
#define I2C0_MCS_R              (*((volatile uint32_t *)0x40020004))
#define I2C0_MDR_R              (*((volatile uint32_t *)0x40020008))
#define I2C0_MTPR_R             (*((volatile uint32_t *)0x4002000C))
#define I2C0_MIMR_R             (*((volatile uint32_t *)0x40020010))
#define I2C0_MRIS_R             (*((volatile uint32_t *)0x40020014))
#define I2C0_MMIS_R             (*((volatile uint32_t *)0x40020018))
#define I2C0_MICR_R             (*((volatile uint32_t *)0x4002001C))
#define I2C0_MCR_R              (*((volatile uint32_t *)0x40020020))
#define I2C0_MCLKOCNT_R         (*((volatile uint32_t *)0x40020024))
#define I2C0_MBMON_R            (*((volatile uint32_t *)0x4002002C))
#define I2C0_MBLEN_R            (*((volatile uint32_t *)0x40020030))
#define I2C0_MBCNT_R            (*((volatile uint32_t *)0x40020034))
#define I2C0_SOAR_R             (*((volatile uint32_t *)0x40020800))
#define I2C0_SCSR_R             (*((volatile uint32_t *)0x40020804))
#define I2C0_SDR_R              (*((volatile uint32_t *)0x40020808))
#define I2C0_SIMR_R             (*((volatile uint32_t *)0x4002080C))
#define I2C0_SRIS_R             (*((volatile uint32_t *)0x40020810))
#define I2C0_SMIS_R             (*((volatile uint32_t *)0x40020814))
#define I2C0_SICR_R             (*((volatile uint32_t *)0x40020818))
#define I2C0_SOAR2_R            (*((volatile uint32_t *)0x4002081C))
#define I2C0_SACKCTL_R          (*((volatile uint32_t *)0x40020820))
#define I2C0_FIFODATA_R         (*((volatile uint32_t *)0x40020F00))
#define I2C0_FIFOCTL_R          (*((volatile uint32_t *)0x40020F04))
#define I2C0_FIFOSTATUS_R       (*((volatile uint32_t *)0x40020F08))
#define I2C0_PP_R               (*((volatile uint32_t *)0x40020FC0))
#define I2C0_PC_R               (*((volatile uint32_t *)0x40020FC4))

//*****************************************************************************
//
// I2C registers (I2C1)
//
//*****************************************************************************
#define I2C1_MSA_R              (*((volatile uint32_t *)0x40021000))
#define I2C1_MCS_R              (*((volatile uint32_t *)0x40021004))
#define I2C1_MDR_R              (*((volatile uint32_t *)0x40021008))
#define I2C1_MTPR_R             (*((volatile uint32_t *)0x4002100C))
#define I2C1_MIMR_R             (*((volatile uint32_t *)0x40021010))
#define I2C1_MRIS_R             (*((volatile uint32_t *)0x40021014))
#define I2C1_MMIS_R             (*((volatile uint32_t *)0x40021018))
#define I2C1_MICR_R             (*((volatile uint32_t *)0x4002101C))
#define I2C1_MCR_R              (*((volatile uint32_t *)0x40021020))
#define I2C1_MCLKOCNT_R         (*((volatile uint32_t *)0x40021024))
#define I2C1_MBMON_R            (*((volatile uint32_t *)0x4002102C))
#define I2C1_MBLEN_R            (*((volatile uint32_t *)0x40021030))
#define I2C1_MBCNT_R            (*((volatile uint32_t *)0x40021034))
#define I2C1_SOAR_R             (*((volatile uint32_t *)0x40021800))
#define I2C1_SCSR_R             (*((volatile uint32_t *)0x40021804))
#define I2C1_SDR_R              (*((volatile uint32_t *)0x40021808))
#define I2C1_SIMR_R             (*((volatile uint32_t *)0x4002180C))
#define I2C1_SRIS_R             (*((volatile uint32_t *)0x40021810))
#define I2C1_SMIS_R             (*((volatile uint32_t *)0x40021814))
#define I2C1_SICR_R             (*((volatile uint32_t *)0x40021818))
#define I2C1_SOAR2_R            (*((volatile uint32_t *)0x4002181C))
#define I2C1_SACKCTL_R          (*((volatile uint32_t *)0x40021820))
#define I2C1_FIFODATA_R         (*((volatile uint32_t *)0x40021F00))
#define I2C1_FIFOCTL_R          (*((volatile uint32_t *)0x40021F04))
#define I2C1_FIFOSTATUS_R       (*((volatile uint32_t *)0x40021F08))
#define I2C1_PP_R               (*((volatile uint32_t *)0x40021FC0))
#define I2C1_PC_R               (*((volatile uint32_t *)0x40021FC4))

//*****************************************************************************
//
// I2C registers (I2C2)
//
//*****************************************************************************
#define I2C2_MSA_R              (*((volatile uint32_t *)0x40022000))
#define I2C2_MCS_R              (*((volatile uint32_t *)0x40022004))
#define I2C2_MDR_R              (*((volatile uint32_t *)0x40022008))
#define I2C2_MTPR_R             (*((volatile uint32_t *)0x4002200C))
#define I2C2_MIMR_R             (*((volatile uint32_t *)0x40022010))
#define I2C2_MRIS_R             (*((volatile uint32_t *)0x40022014))
#define I2C2_MMIS_R             (*((volatile uint32_t *)0x40022018))
#define I2C2_MICR_R             (*((volatile uint32_t *)0x4002201C))
#define I2C2_MCR_R              (*((volatile uint32_t *)0x40022020))
#define I2C2_MCLKOCNT_R         (*((volatile uint32_t *)0x40022024))
#define I2C2_MBMON_R            (*((volatile uint32_t *)0x4002202C))
#define I2C2_MBLEN_R            (*((volatile uint32_t *)0x40022030))
#define I2C2_MBCNT_R            (*((volatile uint32_t *)0x40022034))
#define I2C2_SOAR_R             (*((volatile uint32_t *)0x40022800))
#define I2C2_SCSR_R             (*((volatile uint32_t *)0x40022804))
#define I2C2_SDR_R              (*((volatile uint32_t *)0x40022808))
#define I2C2_SIMR_R             (*((volatile uint32_t *)0x4002280C))
#define I2C2_SRIS_R             (*((volatile uint32_t *)0x40022810))
#define I2C2_SMIS_R             (*((volatile uint32_t *)0x40022814))
#define I2C2_SICR_R             (*((volatile uint32_t *)0x40022818))
#define I2C2_SOAR2_R            (*((volatile uint32_t *)0x4002281C))
#define I2C2_SACKCTL_R          (*((volatile uint32_t *)0x40022820))
#define I2C2_FIFODATA_R         (*((volatile uint32_t *)0x40022F00))
#define I2C2_FIFOCTL_R          (*((volatile uint32_t *)0x40022F04))
#define I2C2_FIFOSTATUS_R       (*((volatile uint32_t *)0x40022F08))
#define I2C2_PP_R               (*((volatile uint32_t *)0x40022FC0))
#define I2C2_PC_R               (*((volatile uint32_t *)0x40022FC4))

//*****************************************************************************
//
// I2C registers (I2C3)
//
//*****************************************************************************
#define I2C3_MSA_R              (*((volatile uint32_t *)0x40023000))
#define I2C3_MCS_R              (*((volatile uint32_t *)0x40023004))
#define I2C3_MDR_R              (*((volatile uint32_t *)0x40023008))
#define I2C3_MTPR_R             (*((volatile uint32_t *)0x4002300C))
#define I2C3_MIMR_R             (*((volatile uint32_t *)0x40023010))
#define I2C3_MRIS_R             (*((volatile uint32_t *)0x40023014))
#define I2C3_MMIS_R             (*((volatile uint32_t *)0x40023018))
#define I2C3_MICR_R             (*((volatile uint32_t *)0x4002301C))
#define I2C3_MCR_R              (*((volatile uint32_t *)0x40023020))
#define I2C3_MCLKOCNT_R         (*((volatile uint32_t *)0x40023024))
#define I2C3_MBMON_R            (*((volatile uint32_t *)0x4002302C))
#define I2C3_MBLEN_R            (*((volatile uint32_t *)0x40023030))
#define I2C3_MBCNT_R            (*((volatile uint32_t *)0x40023034))
#define I2C3_SOAR_R             (*((volatile uint32_t *)0x40023800))
#define I2C3_SCSR_R             (*((volatile uint32_t *)0x40023804))
#define I2C3_SDR_R              (*((volatile uint32_t *)0x40023808))
#define I2C3_SIMR_R             (*((volatile uint32_t *)0x4002380C))
#define I2C3_SRIS_R             (*((volatile uint32_t *)0x40023810))
#define I2C3_SMIS_R             (*((volatile uint32_t *)0x40023814))
#define I2C3_SICR_R             (*((volatile uint32_t *)0x40023818))
#define I2C3_SOAR2_R            (*((volatile uint32_t *)0x4002381C))
#define I2C3_SACKCTL_R          (*((volatile uint32_t *)0x40023820))
#define I2C3_FIFODATA_R         (*((volatile uint32_t *)0x40023F00))
#define I2C3_FIFOCTL_R          (*((volatile uint32_t *)0x40023F04))
#define I2C3_FIFOSTATUS_R       (*((volatile uint32_t *)0x40023F08))
#define I2C3_PP_R               (*((volatile uint32_t *)0x40023FC0))
#define I2C3_PC_R               (*((volatile uint32_t *)0x40023FC4))

//*****************************************************************************
//
// PWM registers (PWM0)
//
//*****************************************************************************
#define PWM0_CTL_R              (*((volatile uint32_t *)0x40028000))
#define PWM0_SYNC_R             (*((volatile uint32_t *)0x40028004))
#define PWM0_ENABLE_R           (*((volatile uint32_t *)0x40028008))
#define PWM0_INVERT_R           (*((volatile uint32_t *)0x4002800C))
#define PWM0_FAULT_R            (*((volatile uint32_t *)0x40028010))
#define PWM0_INTEN_R            (*((volatile uint32_t *)0x40028014))
#define PWM0_RIS_R              (*((volatile uint32_t *)0x40028018))
#define PWM0_ISC_R              (*((volatile uint32_t *)0x4002801C))
#define PWM0_STATUS_R           (*((volatile uint32_t *)0x40028020))
#define PWM0_FAULTVAL_R         (*((volatile uint32_t *)0x40028024))
#define PWM0_ENUPD_R            (*((volatile uint32_t *)0x40028028))
#define PWM0_0_CTL_R            (*((volatile uint32_t *)0x40028040))
#define PWM0_0_INTEN_R          (*((volatile uint32_t *)0x40028044))
#define PWM0_0_RIS_R            (*((volatile uint32_t *)0x40028048))
#define PWM0_0_ISC_R            (*((volatile uint32_t *)0x4002804C))
#define PWM0_0_LOAD_R           (*((volatile uint32_t *)0x40028050))
#define PWM0_0_COUNT_R          (*((volatile uint32_t *)0x40028054))
#define PWM0_0_CMPA_R           (*((volatile uint32_t *)0x40028058))
#define PWM0_0_CMPB_R           (*((volatile uint32_t *)0x4002805C))
#define PWM0_0_GENA_R           (*((volatile uint32_t *)0x40028060))
#define PWM0_0_GENB_R           (*((volatile uint32_t *)0x40028064))
#define PWM0_0_DBCTL_R          (*((volatile uint32_t *)0x40028068))
#define PWM0_0_DBRISE_R         (*((volatile uint32_t *)0x4002806C))
#define PWM0_0_DBFALL_R         (*((volatile uint32_t *)0x40028070))
#define PWM0_0_FLTSRC0_R        (*((volatile uint32_t *)0x40028074))
#define PWM0_0_FLTSRC1_R        (*((volatile uint32_t *)0x40028078))
#define PWM0_0_MINFLTPER_R      (*((volatile uint32_t *)0x4002807C))
#define PWM0_1_CTL_R            (*((volatile uint32_t *)0x40028080))
#define PWM0_1_INTEN_R          (*((volatile uint32_t *)0x40028084))
#define PWM0_1_RIS_R            (*((volatile uint32_t *)0x40028088))
#define PWM0_1_ISC_R            (*((volatile uint32_t *)0x4002808C))
#define PWM0_1_LOAD_R           (*((volatile uint32_t *)0x40028090))
#define PWM0_1_COUNT_R          (*((volatile uint32_t *)0x40028094))
#define PWM0_1_CMPA_R           (*((volatile uint32_t *)0x40028098))
#define PWM0_1_CMPB_R           (*((volatile uint32_t *)0x4002809C))
#define PWM0_1_GENA_R           (*((volatile uint32_t *)0x400280A0))
#define PWM0_1_GENB_R           (*((volatile uint32_t *)0x400280A4))
#define PWM0_1_DBCTL_R          (*((volatile uint32_t *)0x400280A8))
#define PWM0_1_DBRISE_R         (*((volatile uint32_t *)0x400280AC))
#define PWM0_1_DBFALL_R         (*((volatile uint32_t *)0x400280B0))
#define PWM0_1_FLTSRC0_R        (*((volatile uint32_t *)0x400280B4))
#define PWM0_1_FLTSRC1_R        (*((volatile uint32_t *)0x400280B8))
#define PWM0_1_MINFLTPER_R      (*((volatile uint32_t *)0x400280BC))
#define PWM0_2_CTL_R            (*((volatile uint32_t *)0x400280C0))
#define PWM0_2_INTEN_R          (*((volatile uint32_t *)0x400280C4))
#define PWM0_2_RIS_R            (*((volatile uint32_t *)0x400280C8))
#define PWM0_2_ISC_R            (*((volatile uint32_t *)0x400280CC))
#define PWM0_2_LOAD_R           (*((volatile uint32_t *)0x400280D0))
#define PWM0_2_COUNT_R          (*((volatile uint32_t *)0x400280D4))
#define PWM0_2_CMPA_R           (*((volatile uint32_t *)0x400280D8))
#define PWM0_2_CMPB_R           (*((volatile uint32_t *)0x400280DC))
#define PWM0_2_GENA_R           (*((volatile uint32_t *)0x400280E0))
#define PWM0_2_GENB_R           (*((volatile uint32_t *)0x400280E4))
#define PWM0_2_DBCTL_R          (*((volatile uint32_t *)0x400280E8))
#define PWM0_2_DBRISE_R         (*((volatile uint32_t *)0x400280EC))
#define PWM0_2_DBFALL_R         (*((volatile uint32_t *)0x400280F0))
#define PWM0_2_FLTSRC0_R        (*((volatile uint32_t *)0x400280F4))
#define PWM0_2_FLTSRC1_R        (*((volatile uint32_t *)0x400280F8))
#define PWM0_2_MINFLTPER_R      (*((volatile uint32_t *)0x400280FC))
#define PWM0_3_CTL_R            (*((volatile uint32_t *)0x40028100))
#define PWM0_3_INTEN_R          (*((volatile uint32_t *)0x40028104))
#define PWM0_3_RIS_R            (*((volatile uint32_t *)0x40028108))
#define PWM0_3_ISC_R            (*((volatile uint32_t *)0x4002810C))
#define PWM0_3_LOAD_R           (*((volatile uint32_t *)0x40028110))
#define PWM0_3_COUNT_R          (*((volatile uint32_t *)0x40028114))
#define PWM0_3_CMPA_R           (*((volatile uint32_t *)0x40028118))
#define PWM0_3_CMPB_R           (*((volatile uint32_t *)0x4002811C))
#define PWM0_3_GENA_R           (*((volatile uint32_t *)0x40028120))
#define PWM0_3_GENB_R           (*((volatile uint32_t *)0x40028124))
#define PWM0_3_DBCTL_R          (*((volatile uint32_t *)0x40028128))
#define PWM0_3_DBRISE_R         (*((volatile uint32_t *)0x4002812C))
#define PWM0_3_DBFALL_R         (*((volatile uint32_t *)0x40028130))
#define PWM0_3_FLTSRC0_R        (*((volatile uint32_t *)0x40028134))
#define PWM0_3_FLTSRC1_R        (*((volatile uint32_t *)0x40028138))
#define PWM0_3_MINFLTPER_R      (*((volatile uint32_t *)0x4002813C))
#define PWM0_0_FLTSEN_R         (*((volatile uint32_t *)0x40028800))
#define PWM0_0_FLTSTAT0_R       (*((volatile uint32_t *)0x40028804))
#define PWM0_0_FLTSTAT1_R       (*((volatile uint32_t *)0x40028808))
#define PWM0_1_FLTSEN_R         (*((volatile uint32_t *)0x40028880))
#define PWM0_1_FLTSTAT0_R       (*((volatile uint32_t *)0x40028884))
#define PWM0_1_FLTSTAT1_R       (*((volatile uint32_t *)0x40028888))
#define PWM0_2_FLTSEN_R         (*((volatile uint32_t *)0x40028900))
#define PWM0_2_FLTSTAT0_R       (*((volatile uint32_t *)0x40028904))
#define PWM0_2_FLTSTAT1_R       (*((volatile uint32_t *)0x40028908))
#define PWM0_3_FLTSEN_R         (*((volatile uint32_t *)0x40028980))
#define PWM0_3_FLTSTAT0_R       (*((volatile uint32_t *)0x40028984))
#define PWM0_3_FLTSTAT1_R       (*((volatile uint32_t *)0x40028988))
#define PWM0_PP_R               (*((volatile uint32_t *)0x40028FC0))
#define PWM0_CC_R               (*((volatile uint32_t *)0x40028FC8))

//*****************************************************************************
//
// QEI registers (QEI0)
//
//*****************************************************************************
#define QEI0_CTL_R              (*((volatile uint32_t *)0x4002C000))
#define QEI0_STAT_R             (*((volatile uint32_t *)0x4002C004))
#define QEI0_POS_R              (*((volatile uint32_t *)0x4002C008))
#define QEI0_MAXPOS_R           (*((volatile uint32_t *)0x4002C00C))
#define QEI0_LOAD_R             (*((volatile uint32_t *)0x4002C010))
#define QEI0_TIME_R             (*((volatile uint32_t *)0x4002C014))
#define QEI0_COUNT_R            (*((volatile uint32_t *)0x4002C018))
#define QEI0_SPEED_R            (*((volatile uint32_t *)0x4002C01C))
#define QEI0_INTEN_R            (*((volatile uint32_t *)0x4002C020))
#define QEI0_RIS_R              (*((volatile uint32_t *)0x4002C024))
#define QEI0_ISC_R              (*((volatile uint32_t *)0x4002C028))

//*****************************************************************************
//
// Timer registers (TIMER0)
//
//*****************************************************************************
#define TIMER0_CFG_R            (*((volatile uint32_t *)0x40030000))
#define TIMER0_TAMR_R           (*((volatile uint32_t *)0x40030004))
#define TIMER0_TBMR_R           (*((volatile uint32_t *)0x40030008))
#define TIMER0_CTL_R            (*((volatile uint32_t *)0x4003000C))
#define TIMER0_SYNC_R           (*((volatile uint32_t *)0x40030010))
#define TIMER0_IMR_R            (*((volatile uint32_t *)0x40030018))
#define TIMER0_RIS_R            (*((volatile uint32_t *)0x4003001C))
#define TIMER0_MIS_R            (*((volatile uint32_t *)0x40030020))
#define TIMER0_ICR_R            (*((volatile uint32_t *)0x40030024))
#define TIMER0_TAILR_R          (*((volatile uint32_t *)0x40030028))
#define TIMER0_TBILR_R          (*((volatile uint32_t *)0x4003002C))
#define TIMER0_TAMATCHR_R       (*((volatile uint32_t *)0x40030030))
#define TIMER0_TBMATCHR_R       (*((volatile uint32_t *)0x40030034))
#define TIMER0_TAPR_R           (*((volatile uint32_t *)0x40030038))
#define TIMER0_TBPR_R           (*((volatile uint32_t *)0x4003003C))
#define TIMER0_TAPMR_R          (*((volatile uint32_t *)0x40030040))
#define TIMER0_TBPMR_R          (*((volatile uint32_t *)0x40030044))
#define TIMER0_TAR_R            (*((volatile uint32_t *)0x40030048))
#define TIMER0_TBR_R            (*((volatile uint32_t *)0x4003004C))
#define TIMER0_TAV_R            (*((volatile uint32_t *)0x40030050))
#define TIMER0_TBV_R            (*((volatile uint32_t *)0x40030054))
#define TIMER0_RTCPD_R          (*((volatile uint32_t *)0x40030058))
#define TIMER0_TAPS_R           (*((volatile uint32_t *)0x4003005C))
#define TIMER0_TBPS_R           (*((volatile uint32_t *)0x40030060))
#define TIMER0_DMAEV_R          (*((volatile uint32_t *)0x4003006C))
#define TIMER0_ADCEV_R          (*((volatile uint32_t *)0x40030070))
#define TIMER0_PP_R             (*((volatile uint32_t *)0x40030FC0))
#define TIMER0_CC_R             (*((volatile uint32_t *)0x40030FC8))

//*****************************************************************************
//
// Timer registers (TIMER1)
//
//*****************************************************************************
#define TIMER1_CFG_R            (*((volatile uint32_t *)0x40031000))
#define TIMER1_TAMR_R           (*((volatile uint32_t *)0x40031004))
#define TIMER1_TBMR_R           (*((volatile uint32_t *)0x40031008))
#define TIMER1_CTL_R            (*((volatile uint32_t *)0x4003100C))
#define TIMER1_SYNC_R           (*((volatile uint32_t *)0x40031010))
#define TIMER1_IMR_R            (*((volatile uint32_t *)0x40031018))
#define TIMER1_RIS_R            (*((volatile uint32_t *)0x4003101C))
#define TIMER1_MIS_R            (*((volatile uint32_t *)0x40031020))
#define TIMER1_ICR_R            (*((volatile uint32_t *)0x40031024))
#define TIMER1_TAILR_R          (*((volatile uint32_t *)0x40031028))
#define TIMER1_TBILR_R          (*((volatile uint32_t *)0x4003102C))
#define TIMER1_TAMATCHR_R       (*((volatile uint32_t *)0x40031030))
#define TIMER1_TBMATCHR_R       (*((volatile uint32_t *)0x40031034))
#define TIMER1_TAPR_R           (*((volatile uint32_t *)0x40031038))
#define TIMER1_TBPR_R           (*((volatile uint32_t *)0x4003103C))
#define TIMER1_TAPMR_R          (*((volatile uint32_t *)0x40031040))
#define TIMER1_TBPMR_R          (*((volatile uint32_t *)0x40031044))
#define TIMER1_TAR_R            (*((volatile uint32_t *)0x40031048))
#define TIMER1_TBR_R            (*((volatile uint32_t *)0x4003104C))
#define TIMER1_TAV_R            (*((volatile uint32_t *)0x40031050))
#define TIMER1_TBV_R            (*((volatile uint32_t *)0x40031054))
#define TIMER1_RTCPD_R          (*((volatile uint32_t *)0x40031058))
#define TIMER1_TAPS_R           (*((volatile uint32_t *)0x4003105C))
#define TIMER1_TBPS_R           (*((volatile uint32_t *)0x40031060))
#define TIMER1_DMAEV_R          (*((volatile uint32_t *)0x4003106C))
#define TIMER1_ADCEV_R          (*((volatile uint32_t *)0x40031070))
#define TIMER1_PP_R             (*((volatile uint32_t *)0x40031FC0))
#define TIMER1_CC_R             (*((volatile uint32_t *)0x40031FC8))

//*****************************************************************************
//
// Timer registers (TIMER2)
//
//*****************************************************************************
#define TIMER2_CFG_R            (*((volatile uint32_t *)0x40032000))
#define TIMER2_TAMR_R           (*((volatile uint32_t *)0x40032004))
#define TIMER2_TBMR_R           (*((volatile uint32_t *)0x40032008))
#define TIMER2_CTL_R            (*((volatile uint32_t *)0x4003200C))
#define TIMER2_SYNC_R           (*((volatile uint32_t *)0x40032010))
#define TIMER2_IMR_R            (*((volatile uint32_t *)0x40032018))
#define TIMER2_RIS_R            (*((volatile uint32_t *)0x4003201C))
#define TIMER2_MIS_R            (*((volatile uint32_t *)0x40032020))
#define TIMER2_ICR_R            (*((volatile uint32_t *)0x40032024))
#define TIMER2_TAILR_R          (*((volatile uint32_t *)0x40032028))
#define TIMER2_TBILR_R          (*((volatile uint32_t *)0x4003202C))
#define TIMER2_TAMATCHR_R       (*((volatile uint32_t *)0x40032030))
#define TIMER2_TBMATCHR_R       (*((volatile uint32_t *)0x40032034))
#define TIMER2_TAPR_R           (*((volatile uint32_t *)0x40032038))
#define TIMER2_TBPR_R           (*((volatile uint32_t *)0x4003203C))
#define TIMER2_TAPMR_R          (*((volatile uint32_t *)0x40032040))
#define TIMER2_TBPMR_R          (*((volatile uint32_t *)0x40032044))
#define TIMER2_TAR_R            (*((volatile uint32_t *)0x40032048))
#define TIMER2_TBR_R            (*((volatile uint32_t *)0x4003204C))
#define TIMER2_TAV_R            (*((volatile uint32_t *)0x40032050))
#define TIMER2_TBV_R            (*((volatile uint32_t *)0x40032054))
#define TIMER2_RTCPD_R          (*((volatile uint32_t *)0x40032058))
#define TIMER2_TAPS_R           (*((volatile uint32_t *)0x4003205C))
#define TIMER2_TBPS_R           (*((volatile uint32_t *)0x40032060))
#define TIMER2_DMAEV_R          (*((volatile uint32_t *)0x4003206C))
#define TIMER2_ADCEV_R          (*((volatile uint32_t *)0x40032070))
#define TIMER2_PP_R             (*((volatile uint32_t *)0x40032FC0))
#define TIMER2_CC_R             (*((volatile uint32_t *)0x40032FC8))

//*****************************************************************************
//
// Timer registers (TIMER3)
//
//*****************************************************************************
#define TIMER3_CFG_R            (*((volatile uint32_t *)0x40033000))
#define TIMER3_TAMR_R           (*((volatile uint32_t *)0x40033004))
#define TIMER3_TBMR_R           (*((volatile uint32_t *)0x40033008))
#define TIMER3_CTL_R            (*((volatile uint32_t *)0x4003300C))
#define TIMER3_SYNC_R           (*((volatile uint32_t *)0x40033010))
#define TIMER3_IMR_R            (*((volatile uint32_t *)0x40033018))
#define TIMER3_RIS_R            (*((volatile uint32_t *)0x4003301C))
#define TIMER3_MIS_R            (*((volatile uint32_t *)0x40033020))
#define TIMER3_ICR_R            (*((volatile uint32_t *)0x40033024))
#define TIMER3_TAILR_R          (*((volatile uint32_t *)0x40033028))
#define TIMER3_TBILR_R          (*((volatile uint32_t *)0x4003302C))
#define TIMER3_TAMATCHR_R       (*((volatile uint32_t *)0x40033030))
#define TIMER3_TBMATCHR_R       (*((volatile uint32_t *)0x40033034))
#define TIMER3_TAPR_R           (*((volatile uint32_t *)0x40033038))
#define TIMER3_TBPR_R           (*((volatile uint32_t *)0x4003303C))
#define TIMER3_TAPMR_R          (*((volatile uint32_t *)0x40033040))
#define TIMER3_TBPMR_R          (*((volatile uint32_t *)0x40033044))
#define TIMER3_TAR_R            (*((volatile uint32_t *)0x40033048))
#define TIMER3_TBR_R            (*((volatile uint32_t *)0x4003304C))
#define TIMER3_TAV_R            (*((volatile uint32_t *)0x40033050))
#define TIMER3_TBV_R            (*((volatile uint32_t *)0x40033054))
#define TIMER3_RTCPD_R          (*((volatile uint32_t *)0x40033058))
#define TIMER3_TAPS_R           (*((volatile uint32_t *)0x4003305C))
#define TIMER3_TBPS_R           (*((volatile uint32_t *)0x40033060))
#define TIMER3_DMAEV_R          (*((volatile uint32_t *)0x4003306C))
#define TIMER3_ADCEV_R          (*((volatile uint32_t *)0x40033070))
#define TIMER3_PP_R             (*((volatile uint32_t *)0x40033FC0))
#define TIMER3_CC_R             (*((volatile uint32_t *)0x40033FC8))

//*****************************************************************************
//
// Timer registers (TIMER4)
//
//*****************************************************************************
#define TIMER4_CFG_R            (*((volatile uint32_t *)0x40034000))
#define TIMER4_TAMR_R           (*((volatile uint32_t *)0x40034004))
#define TIMER4_TBMR_R           (*((volatile uint32_t *)0x40034008))
#define TIMER4_CTL_R            (*((volatile uint32_t *)0x4003400C))
#define TIMER4_SYNC_R           (*((volatile uint32_t *)0x40034010))
#define TIMER4_IMR_R            (*((volatile uint32_t *)0x40034018))
#define TIMER4_RIS_R            (*((volatile uint32_t *)0x4003401C))
#define TIMER4_MIS_R            (*((volatile uint32_t *)0x40034020))
#define TIMER4_ICR_R            (*((volatile uint32_t *)0x40034024))
#define TIMER4_TAILR_R          (*((volatile uint32_t *)0x40034028))
#define TIMER4_TBILR_R          (*((volatile uint32_t *)0x4003402C))
#define TIMER4_TAMATCHR_R       (*((volatile uint32_t *)0x40034030))
#define TIMER4_TBMATCHR_R       (*((volatile uint32_t *)0x40034034))
#define TIMER4_TAPR_R           (*((volatile uint32_t *)0x40034038))
#define TIMER4_TBPR_R           (*((volatile uint32_t *)0x4003403C))
#define TIMER4_TAPMR_R          (*((volatile uint32_t *)0x40034040))
#define TIMER4_TBPMR_R          (*((volatile uint32_t *)0x40034044))
#define TIMER4_TAR_R            (*((volatile uint32_t *)0x40034048))
#define TIMER4_TBR_R            (*((volatile uint32_t *)0x4003404C))
#define TIMER4_TAV_R            (*((volatile uint32_t *)0x40034050))
#define TIMER4_TBV_R            (*((volatile uint32_t *)0x40034054))
#define TIMER4_RTCPD_R          (*((volatile uint32_t *)0x40034058))
#define TIMER4_TAPS_R           (*((volatile uint32_t *)0x4003405C))
#define TIMER4_TBPS_R           (*((volatile uint32_t *)0x40034060))
#define TIMER4_DMAEV_R          (*((volatile uint32_t *)0x4003406C))
#define TIMER4_ADCEV_R          (*((volatile uint32_t *)0x40034070))
#define TIMER4_PP_R             (*((volatile uint32_t *)0x40034FC0))
#define TIMER4_CC_R             (*((volatile uint32_t *)0x40034FC8))

//*****************************************************************************
//
// Timer registers (TIMER5)
//
//*****************************************************************************
#define TIMER5_CFG_R            (*((volatile uint32_t *)0x40035000))
#define TIMER5_TAMR_R           (*((volatile uint32_t *)0x40035004))
#define TIMER5_TBMR_R           (*((volatile uint32_t *)0x40035008))
#define TIMER5_CTL_R            (*((volatile uint32_t *)0x4003500C))
#define TIMER5_SYNC_R           (*((volatile uint32_t *)0x40035010))
#define TIMER5_IMR_R            (*((volatile uint32_t *)0x40035018))
#define TIMER5_RIS_R            (*((volatile uint32_t *)0x4003501C))
#define TIMER5_MIS_R            (*((volatile uint32_t *)0x40035020))
#define TIMER5_ICR_R            (*((volatile uint32_t *)0x40035024))
#define TIMER5_TAILR_R          (*((volatile uint32_t *)0x40035028))
#define TIMER5_TBILR_R          (*((volatile uint32_t *)0x4003502C))
#define TIMER5_TAMATCHR_R       (*((volatile uint32_t *)0x40035030))
#define TIMER5_TBMATCHR_R       (*((volatile uint32_t *)0x40035034))
#define TIMER5_TAPR_R           (*((volatile uint32_t *)0x40035038))
#define TIMER5_TBPR_R           (*((volatile uint32_t *)0x4003503C))
#define TIMER5_TAPMR_R          (*((volatile uint32_t *)0x40035040))
#define TIMER5_TBPMR_R          (*((volatile uint32_t *)0x40035044))
#define TIMER5_TAR_R            (*((volatile uint32_t *)0x40035048))
#define TIMER5_TBR_R            (*((volatile uint32_t *)0x4003504C))
#define TIMER5_TAV_R            (*((volatile uint32_t *)0x40035050))
#define TIMER5_TBV_R            (*((volatile uint32_t *)0x40035054))
#define TIMER5_RTCPD_R          (*((volatile uint32_t *)0x40035058))
#define TIMER5_TAPS_R           (*((volatile uint32_t *)0x4003505C))
#define TIMER5_TBPS_R           (*((volatile uint32_t *)0x40035060))
#define TIMER5_DMAEV_R          (*((volatile uint32_t *)0x4003506C))
#define TIMER5_ADCEV_R          (*((volatile uint32_t *)0x40035070))
#define TIMER5_PP_R             (*((volatile uint32_t *)0x40035FC0))
#define TIMER5_CC_R             (*((volatile uint32_t *)0x40035FC8))

//*****************************************************************************
//
// ADC registers (ADC0)
//
//*****************************************************************************
#define ADC0_ACTSS_R            (*((volatile uint32_t *)0x40038000))
#define ADC0_RIS_R              (*((volatile uint32_t *)0x40038004))
#define ADC0_IM_R               (*((volatile uint32_t *)0x40038008))
#define ADC0_ISC_R              (*((volatile uint32_t *)0x4003800C))
#define ADC0_OSTAT_R            (*((volatile uint32_t *)0x40038010))
#define ADC0_EMUX_R             (*((volatile uint32_t *)0x40038014))
#define ADC0_USTAT_R            (*((volatile uint32_t *)0x40038018))
#define ADC0_TSSEL_R            (*((volatile uint32_t *)0x4003801C))
#define ADC0_SSPRI_R            (*((volatile uint32_t *)0x40038020))
#define ADC0_SPC_R              (*((volatile uint32_t *)0x40038024))
#define ADC0_PSSI_R             (*((volatile uint32_t *)0x40038028))
#define ADC0_SAC_R              (*((volatile uint32_t *)0x40038030))
#define ADC0_DCISC_R            (*((volatile uint32_t *)0x40038034))
#define ADC0_CTL_R              (*((volatile uint32_t *)0x40038038))
#define ADC0_SSMUX0_R           (*((volatile uint32_t *)0x40038040))
#define ADC0_SSCTL0_R           (*((volatile uint32_t *)0x40038044))
#define ADC0_SSFIFO0_R          (*((volatile uint32_t *)0x40038048))
#define ADC0_SSFSTAT0_R         (*((volatile uint32_t *)0x4003804C))
#define ADC0_SSOP0_R            (*((volatile uint32_t *)0x40038050))
#define ADC0_SSDC0_R            (*((volatile uint32_t *)0x40038054))
#define ADC0_SSEMUX0_R          (*((volatile uint32_t *)0x40038058))
#define ADC0_SSTSH0_R           (*((volatile uint32_t *)0x4003805C))
#define ADC0_SSMUX1_R           (*((volatile uint32_t *)0x40038060))
#define ADC0_SSCTL1_R           (*((volatile uint32_t *)0x40038064))
#define ADC0_SSFIFO1_R          (*((volatile uint32_t *)0x40038068))
#define ADC0_SSFSTAT1_R         (*((volatile uint32_t *)0x4003806C))
#define ADC0_SSOP1_R            (*((volatile uint32_t *)0x40038070))
#define ADC0_SSDC1_R            (*((volatile uint32_t *)0x40038074))
#define ADC0_SSEMUX1_R          (*((volatile uint32_t *)0x40038078))
#define ADC0_SSTSH1_R           (*((volatile uint32_t *)0x4003807C))
#define ADC0_SSMUX2_R           (*((volatile uint32_t *)0x40038080))
#define ADC0_SSCTL2_R           (*((volatile uint32_t *)0x40038084))
#define ADC0_SSFIFO2_R          (*((volatile uint32_t *)0x40038088))
#define ADC0_SSFSTAT2_R         (*((volatile uint32_t *)0x4003808C))
#define ADC0_SSOP2_R            (*((volatile uint32_t *)0x40038090))
#define ADC0_SSDC2_R            (*((volatile uint32_t *)0x40038094))
#define ADC0_SSEMUX2_R          (*((volatile uint32_t *)0x40038098))
#define ADC0_SSTSH2_R           (*((volatile uint32_t *)0x4003809C))
#define ADC0_SSMUX3_R           (*((volatile uint32_t *)0x400380A0))
#define ADC0_SSCTL3_R           (*((volatile uint32_t *)0x400380A4))
#define ADC0_SSFIFO3_R          (*((volatile uint32_t *)0x400380A8))
#define ADC0_SSFSTAT3_R         (*((volatile uint32_t *)0x400380AC))
#define ADC0_SSOP3_R            (*((volatile uint32_t *)0x400380B0))
#define ADC0_SSDC3_R            (*((volatile uint32_t *)0x400380B4))
#define ADC0_SSEMUX3_R          (*((volatile uint32_t *)0x400380B8))
#define ADC0_SSTSH3_R           (*((volatile uint32_t *)0x400380BC))
#define ADC0_DCRIC_R            (*((volatile uint32_t *)0x40038D00))
#define ADC0_DCCTL0_R           (*((volatile uint32_t *)0x40038E00))
#define ADC0_DCCTL1_R           (*((volatile uint32_t *)0x40038E04))
#define ADC0_DCCTL2_R           (*((volatile uint32_t *)0x40038E08))
#define ADC0_DCCTL3_R           (*((volatile uint32_t *)0x40038E0C))
#define ADC0_DCCTL4_R           (*((volatile uint32_t *)0x40038E10))
#define ADC0_DCCTL5_R           (*((volatile uint32_t *)0x40038E14))
#define ADC0_DCCTL6_R           (*((volatile uint32_t *)0x40038E18))
#define ADC0_DCCTL7_R           (*((volatile uint32_t *)0x40038E1C))
#define ADC0_DCCMP0_R           (*((volatile uint32_t *)0x40038E40))
#define ADC0_DCCMP1_R           (*((volatile uint32_t *)0x40038E44))
#define ADC0_DCCMP2_R           (*((volatile uint32_t *)0x40038E48))
#define ADC0_DCCMP3_R           (*((volatile uint32_t *)0x40038E4C))
#define ADC0_DCCMP4_R           (*((volatile uint32_t *)0x40038E50))
#define ADC0_DCCMP5_R           (*((volatile uint32_t *)0x40038E54))
#define ADC0_DCCMP6_R           (*((volatile uint32_t *)0x40038E58))
#define ADC0_DCCMP7_R           (*((volatile uint32_t *)0x40038E5C))
#define ADC0_PP_R               (*((volatile uint32_t *)0x40038FC0))
#define ADC0_PC_R               (*((volatile uint32_t *)0x40038FC4))
#define ADC0_CC_R               (*((volatile uint32_t *)0x40038FC8))

//*****************************************************************************
//
// ADC registers (ADC1)
//
//*****************************************************************************
#define ADC1_ACTSS_R            (*((volatile uint32_t *)0x40039000))
#define ADC1_RIS_R              (*((volatile uint32_t *)0x40039004))
#define ADC1_IM_R               (*((volatile uint32_t *)0x40039008))
#define ADC1_ISC_R              (*((volatile uint32_t *)0x4003900C))
#define ADC1_OSTAT_R            (*((volatile uint32_t *)0x40039010))
#define ADC1_EMUX_R             (*((volatile uint32_t *)0x40039014))
#define ADC1_USTAT_R            (*((volatile uint32_t *)0x40039018))
#define ADC1_TSSEL_R            (*((volatile uint32_t *)0x4003901C))
#define ADC1_SSPRI_R            (*((volatile uint32_t *)0x40039020))
#define ADC1_SPC_R              (*((volatile uint32_t *)0x40039024))
#define ADC1_PSSI_R             (*((volatile uint32_t *)0x40039028))
#define ADC1_SAC_R              (*((volatile uint32_t *)0x40039030))
#define ADC1_DCISC_R            (*((volatile uint32_t *)0x40039034))
#define ADC1_CTL_R              (*((volatile uint32_t *)0x40039038))
#define ADC1_SSMUX0_R           (*((volatile uint32_t *)0x40039040))
#define ADC1_SSCTL0_R           (*((volatile uint32_t *)0x40039044))
#define ADC1_SSFIFO0_R          (*((volatile uint32_t *)0x40039048))
#define ADC1_SSFSTAT0_R         (*((volatile uint32_t *)0x4003904C))
#define ADC1_SSOP0_R            (*((volatile uint32_t *)0x40039050))
#define ADC1_SSDC0_R            (*((volatile uint32_t *)0x40039054))
#define ADC1_SSEMUX0_R          (*((volatile uint32_t *)0x40039058))
#define ADC1_SSTSH0_R           (*((volatile uint32_t *)0x4003905C))
#define ADC1_SSMUX1_R           (*((volatile uint32_t *)0x40039060))
#define ADC1_SSCTL1_R           (*((volatile uint32_t *)0x40039064))
#define ADC1_SSFIFO1_R          (*((volatile uint32_t *)0x40039068))
#define ADC1_SSFSTAT1_R         (*((volatile uint32_t *)0x4003906C))
#define ADC1_SSOP1_R            (*((volatile uint32_t *)0x40039070))
#define ADC1_SSDC1_R            (*((volatile uint32_t *)0x40039074))
#define ADC1_SSEMUX1_R          (*((volatile uint32_t *)0x40039078))
#define ADC1_SSTSH1_R           (*((volatile uint32_t *)0x4003907C))
#define ADC1_SSMUX2_R           (*((volatile uint32_t *)0x40039080))
#define ADC1_SSCTL2_R           (*((volatile uint32_t *)0x40039084))
#define ADC1_SSFIFO2_R          (*((volatile uint32_t *)0x40039088))
#define ADC1_SSFSTAT2_R         (*((volatile uint32_t *)0x4003908C))
#define ADC1_SSOP2_R            (*((volatile uint32_t *)0x40039090))
#define ADC1_SSDC2_R            (*((volatile uint32_t *)0x40039094))
#define ADC1_SSEMUX2_R          (*((volatile uint32_t *)0x40039098))
#define ADC1_SSTSH2_R           (*((volatile uint32_t *)0x4003909C))
#define ADC1_SSMUX3_R           (*((volatile uint32_t *)0x400390A0))
#define ADC1_SSCTL3_R           (*((volatile uint32_t *)0x400390A4))
#define ADC1_SSFIFO3_R          (*((volatile uint32_t *)0x400390A8))
#define ADC1_SSFSTAT3_R         (*((volatile uint32_t *)0x400390AC))
#define ADC1_SSOP3_R            (*((volatile uint32_t *)0x400390B0))
#define ADC1_SSDC3_R            (*((volatile uint32_t *)0x400390B4))
#define ADC1_SSEMUX3_R          (*((volatile uint32_t *)0x400390B8))
#define ADC1_SSTSH3_R           (*((volatile uint32_t *)0x400390BC))
#define ADC1_DCRIC_R            (*((volatile uint32_t *)0x40039D00))
#define ADC1_DCCTL0_R           (*((volatile uint32_t *)0x40039E00))
#define ADC1_DCCTL1_R           (*((volatile uint32_t *)0x40039E04))
#define ADC1_DCCTL2_R           (*((volatile uint32_t *)0x40039E08))
#define ADC1_DCCTL3_R           (*((volatile uint32_t *)0x40039E0C))
#define ADC1_DCCTL4_R           (*((volatile uint32_t *)0x40039E10))
#define ADC1_DCCTL5_R           (*((volatile uint32_t *)0x40039E14))
#define ADC1_DCCTL6_R           (*((volatile uint32_t *)0x40039E18))
#define ADC1_DCCTL7_R           (*((volatile uint32_t *)0x40039E1C))
#define ADC1_DCCMP0_R           (*((volatile uint32_t *)0x40039E40))
#define ADC1_DCCMP1_R           (*((volatile uint32_t *)0x40039E44))
#define ADC1_DCCMP2_R           (*((volatile uint32_t *)0x40039E48))
#define ADC1_DCCMP3_R           (*((volatile uint32_t *)0x40039E4C))
#define ADC1_DCCMP4_R           (*((volatile uint32_t *)0x40039E50))
#define ADC1_DCCMP5_R           (*((volatile uint32_t *)0x40039E54))
#define ADC1_DCCMP6_R           (*((volatile uint32_t *)0x40039E58))
#define ADC1_DCCMP7_R           (*((volatile uint32_t *)0x40039E5C))
#define ADC1_PP_R               (*((volatile uint32_t *)0x40039FC0))
#define ADC1_PC_R               (*((volatile uint32_t *)0x40039FC4))
#define ADC1_CC_R               (*((volatile uint32_t *)0x40039FC8))

//*****************************************************************************
//
// Comparator registers (COMP)
//
//*****************************************************************************
#define COMP_ACMIS_R            (*((volatile uint32_t *)0x4003C000))
#define COMP_ACRIS_R            (*((volatile uint32_t *)0x4003C004))
#define COMP_ACINTEN_R          (*((volatile uint32_t *)0x4003C008))
#define COMP_ACREFCTL_R         (*((volatile uint32_t *)0x4003C010))
#define COMP_ACSTAT0_R          (*((volatile uint32_t *)0x4003C020))
#define COMP_ACCTL0_R           (*((volatile uint32_t *)0x4003C024))
#define COMP_ACSTAT1_R          (*((volatile uint32_t *)0x4003C040))
#define COMP_ACCTL1_R           (*((volatile uint32_t *)0x4003C044))
#define COMP_ACSTAT2_R          (*((volatile uint32_t *)0x4003C060))
#define COMP_ACCTL2_R           (*((volatile uint32_t *)0x4003C064))
#define COMP_PP_R               (*((volatile uint32_t *)0x4003CFC0))

//*****************************************************************************
//
// CAN registers (CAN0)
//
//*****************************************************************************
#define CAN0_CTL_R              (*((volatile uint32_t *)0x40040000))
#define CAN0_STS_R              (*((volatile uint32_t *)0x40040004))
#define CAN0_ERR_R              (*((volatile uint32_t *)0x40040008))
#define CAN0_BIT_R              (*((volatile uint32_t *)0x4004000C))
#define CAN0_INT_R              (*((volatile uint32_t *)0x40040010))
#define CAN0_TST_R              (*((volatile uint32_t *)0x40040014))
#define CAN0_BRPE_R             (*((volatile uint32_t *)0x40040018))
#define CAN0_IF1CRQ_R           (*((volatile uint32_t *)0x40040020))
#define CAN0_IF1CMSK_R          (*((volatile uint32_t *)0x40040024))
#define CAN0_IF1MSK1_R          (*((volatile uint32_t *)0x40040028))
#define CAN0_IF1MSK2_R          (*((volatile uint32_t *)0x4004002C))
#define CAN0_IF1ARB1_R          (*((volatile uint32_t *)0x40040030))
#define CAN0_IF1ARB2_R          (*((volatile uint32_t *)0x40040034))
#define CAN0_IF1MCTL_R          (*((volatile uint32_t *)0x40040038))
#define CAN0_IF1DA1_R           (*((volatile uint32_t *)0x4004003C))
#define CAN0_IF1DA2_R           (*((volatile uint32_t *)0x40040040))
#define CAN0_IF1DB1_R           (*((volatile uint32_t *)0x40040044))
#define CAN0_IF1DB2_R           (*((volatile uint32_t *)0x40040048))
#define CAN0_IF2CRQ_R           (*((volatile uint32_t *)0x40040080))
#define CAN0_IF2CMSK_R          (*((volatile uint32_t *)0x40040084))
#define CAN0_IF2MSK1_R          (*((volatile uint32_t *)0x40040088))
#define CAN0_IF2MSK2_R          (*((volatile uint32_t *)0x4004008C))
#define CAN0_IF2ARB1_R          (*((volatile uint32_t *)0x40040090))
#define CAN0_IF2ARB2_R          (*((volatile uint32_t *)0x40040094))
#define CAN0_IF2MCTL_R          (*((volatile uint32_t *)0x40040098))
#define CAN0_IF2DA1_R           (*((volatile uint32_t *)0x4004009C))
#define CAN0_IF2DA2_R           (*((volatile uint32_t *)0x400400A0))
#define CAN0_IF2DB1_R           (*((volatile uint32_t *)0x400400A4))
#define CAN0_IF2DB2_R           (*((volatile uint32_t *)0x400400A8))
#define CAN0_TXRQ1_R            (*((volatile uint32_t *)0x40040100))
#define CAN0_TXRQ2_R            (*((volatile uint32_t *)0x40040104))
#define CAN0_NWDA1_R            (*((volatile uint32_t *)0x40040120))
#define CAN0_NWDA2_R            (*((volatile uint32_t *)0x40040124))
#define CAN0_MSG1INT_R          (*((volatile uint32_t *)0x40040140))
#define CAN0_MSG2INT_R          (*((volatile uint32_t *)0x40040144))
#define CAN0_MSG1VAL_R          (*((volatile uint32_t *)0x40040160))
#define CAN0_MSG2VAL_R          (*((volatile uint32_t *)0x40040164))

//*****************************************************************************
//
// CAN registers (CAN1)
//
//*****************************************************************************
#define CAN1_CTL_R              (*((volatile uint32_t *)0x40041000))
#define CAN1_STS_R              (*((volatile uint32_t *)0x40041004))
#define CAN1_ERR_R              (*((volatile uint32_t *)0x40041008))
#define CAN1_BIT_R              (*((volatile uint32_t *)0x4004100C))
#define CAN1_INT_R              (*((volatile uint32_t *)0x40041010))
#define CAN1_TST_R              (*((volatile uint32_t *)0x40041014))
#define CAN1_BRPE_R             (*((volatile uint32_t *)0x40041018))
#define CAN1_IF1CRQ_R           (*((volatile uint32_t *)0x40041020))
#define CAN1_IF1CMSK_R          (*((volatile uint32_t *)0x40041024))
#define CAN1_IF1MSK1_R          (*((volatile uint32_t *)0x40041028))
#define CAN1_IF1MSK2_R          (*((volatile uint32_t *)0x4004102C))
#define CAN1_IF1ARB1_R          (*((volatile uint32_t *)0x40041030))
#define CAN1_IF1ARB2_R          (*((volatile uint32_t *)0x40041034))
#define CAN1_IF1MCTL_R          (*((volatile uint32_t *)0x40041038))
#define CAN1_IF1DA1_R           (*((volatile uint32_t *)0x4004103C))
#define CAN1_IF1DA2_R           (*((volatile uint32_t *)0x40041040))
#define CAN1_IF1DB1_R           (*((volatile uint32_t *)0x40041044))
#define CAN1_IF1DB2_R           (*((volatile uint32_t *)0x40041048))
#define CAN1_IF2CRQ_R           (*((volatile uint32_t *)0x40041080))
#define CAN1_IF2CMSK_R          (*((volatile uint32_t *)0x40041084))
#define CAN1_IF2MSK1_R          (*((volatile uint32_t *)0x40041088))
#define CAN1_IF2MSK2_R          (*((volatile uint32_t *)0x4004108C))
#define CAN1_IF2ARB1_R          (*((volatile uint32_t *)0x40041090))
#define CAN1_IF2ARB2_R          (*((volatile uint32_t *)0x40041094))
#define CAN1_IF2MCTL_R          (*((volatile uint32_t *)0x40041098))
#define CAN1_IF2DA1_R           (*((volatile uint32_t *)0x4004109C))
#define CAN1_IF2DA2_R           (*((volatile uint32_t *)0x400410A0))
#define CAN1_IF2DB1_R           (*((volatile uint32_t *)0x400410A4))
#define CAN1_IF2DB2_R           (*((volatile uint32_t *)0x400410A8))
#define CAN1_TXRQ1_R            (*((volatile uint32_t *)0x40041100))
#define CAN1_TXRQ2_R            (*((volatile uint32_t *)0x40041104))
#define CAN1_NWDA1_R            (*((volatile uint32_t *)0x40041120))
#define CAN1_NWDA2_R            (*((volatile uint32_t *)0x40041124))
#define CAN1_MSG1INT_R          (*((volatile uint32_t *)0x40041140))
#define CAN1_MSG2INT_R          (*((volatile uint32_t *)0x40041144))
#define CAN1_MSG1VAL_R          (*((volatile uint32_t *)0x40041160))
#define CAN1_MSG2VAL_R          (*((volatile uint32_t *)0x40041164))

//*****************************************************************************
//
// Univeral Serial Bus registers (USB0)
//
//*****************************************************************************
#define USB0_FADDR_R            (*((volatile uint8_t *)0x40050000))
#define USB0_POWER_R            (*((volatile uint8_t *)0x40050001))
#define USB0_TXIS_R             (*((volatile uint16_t *)0x40050002))
#define USB0_RXIS_R             (*((volatile uint16_t *)0x40050004))
#define USB0_TXIE_R             (*((volatile uint16_t *)0x40050006))
#define USB0_RXIE_R             (*((volatile uint16_t *)0x40050008))
#define USB0_IS_R               (*((volatile uint8_t *)0x4005000A))
#define USB0_IE_R               (*((volatile uint8_t *)0x4005000B))
#define USB0_FRAME_R            (*((volatile uint16_t *)0x4005000C))
#define USB0_EPIDX_R            (*((volatile uint8_t *)0x4005000E))
#define USB0_TEST_R             (*((volatile uint8_t *)0x4005000F))
#define USB0_FIFO0_R            (*((volatile uint32_t *)0x40050020))
#define USB0_FIFO1_R            (*((volatile uint32_t *)0x40050024))
#define USB0_FIFO2_R            (*((volatile uint32_t *)0x40050028))
#define USB0_FIFO3_R            (*((volatile uint32_t *)0x4005002C))
#define USB0_FIFO4_R            (*((volatile uint32_t *)0x40050030))
#define USB0_FIFO5_R            (*((volatile uint32_t *)0x40050034))
#define USB0_FIFO6_R            (*((volatile uint32_t *)0x40050038))
#define USB0_FIFO7_R            (*((volatile uint32_t *)0x4005003C))
#define USB0_DEVCTL_R           (*((volatile uint8_t *)0x40050060))
#define USB0_CCONF_R            (*((volatile uint8_t *)0x40050061))
#define USB0_TXFIFOSZ_R         (*((volatile uint8_t *)0x40050062))
#define USB0_RXFIFOSZ_R         (*((volatile uint8_t *)0x40050063))
#define USB0_TXFIFOADD_R        (*((volatile uint16_t *)0x40050064))
#define USB0_RXFIFOADD_R        (*((volatile uint16_t *)0x40050066))
#define USB0_ULPIVBUSCTL_R      (*((volatile uint8_t *)0x40050070))
#define USB0_ULPIREGDATA_R      (*((volatile uint8_t *)0x40050074))
#define USB0_ULPIREGADDR_R      (*((volatile uint8_t *)0x40050075))
#define USB0_ULPIREGCTL_R       (*((volatile uint8_t *)0x40050076))
#define USB0_ULPIRAWDATA_R      (*((volatile uint8_t *)0x40050077))
#define USB0_EPINFO_R           (*((volatile uint8_t *)0x40050078))
#define USB0_RAMINFO_R          (*((volatile uint8_t *)0x40050079))
#define USB0_CONTIM_R           (*((volatile uint8_t *)0x4005007A))
#define USB0_VPLEN_R            (*((volatile uint8_t *)0x4005007B))
#define USB0_HSEOF_R            (*((volatile uint8_t *)0x4005007C))
#define USB0_FSEOF_R            (*((volatile uint8_t *)0x4005007D))
#define USB0_LSEOF_R            (*((volatile uint8_t *)0x4005007E))
#define USB0_TXFUNCADDR0_R      (*((volatile uint8_t *)0x40050080))
#define USB0_TXHUBADDR0_R       (*((volatile uint8_t *)0x40050082))
#define USB0_TXHUBPORT0_R       (*((volatile uint8_t *)0x40050083))
#define USB0_TXFUNCADDR1_R      (*((volatile uint8_t *)0x40050088))
#define USB0_TXHUBADDR1_R       (*((volatile uint8_t *)0x4005008A))
#define USB0_TXHUBPORT1_R       (*((volatile uint8_t *)0x4005008B))
#define USB0_RXFUNCADDR1_R      (*((volatile uint8_t *)0x4005008C))
#define USB0_RXHUBADDR1_R       (*((volatile uint8_t *)0x4005008E))
#define USB0_RXHUBPORT1_R       (*((volatile uint8_t *)0x4005008F))
#define USB0_TXFUNCADDR2_R      (*((volatile uint8_t *)0x40050090))
#define USB0_TXHUBADDR2_R       (*((volatile uint8_t *)0x40050092))
#define USB0_TXHUBPORT2_R       (*((volatile uint8_t *)0x40050093))
#define USB0_RXFUNCADDR2_R      (*((volatile uint8_t *)0x40050094))
#define USB0_RXHUBADDR2_R       (*((volatile uint8_t *)0x40050096))
#define USB0_RXHUBPORT2_R       (*((volatile uint8_t *)0x40050097))
#define USB0_TXFUNCADDR3_R      (*((volatile uint8_t *)0x40050098))
#define USB0_TXHUBADDR3_R       (*((volatile uint8_t *)0x4005009A))
#define USB0_TXHUBPORT3_R       (*((volatile uint8_t *)0x4005009B))
#define USB0_RXFUNCADDR3_R      (*((volatile uint8_t *)0x4005009C))
#define USB0_RXHUBADDR3_R       (*((volatile uint8_t *)0x4005009E))
#define USB0_RXHUBPORT3_R       (*((volatile uint8_t *)0x4005009F))
#define USB0_TXFUNCADDR4_R      (*((volatile uint8_t *)0x400500A0))
#define USB0_TXHUBADDR4_R       (*((volatile uint8_t *)0x400500A2))
#define USB0_TXHUBPORT4_R       (*((volatile uint8_t *)0x400500A3))
#define USB0_RXFUNCADDR4_R      (*((volatile uint8_t *)0x400500A4))
#define USB0_RXHUBADDR4_R       (*((volatile uint8_t *)0x400500A6))
#define USB0_RXHUBPORT4_R       (*((volatile uint8_t *)0x400500A7))
#define USB0_TXFUNCADDR5_R      (*((volatile uint8_t *)0x400500A8))
#define USB0_TXHUBADDR5_R       (*((volatile uint8_t *)0x400500AA))
#define USB0_TXHUBPORT5_R       (*((volatile uint8_t *)0x400500AB))
#define USB0_RXFUNCADDR5_R      (*((volatile uint8_t *)0x400500AC))
#define USB0_RXHUBADDR5_R       (*((volatile uint8_t *)0x400500AE))
#define USB0_RXHUBPORT5_R       (*((volatile uint8_t *)0x400500AF))
#define USB0_TXFUNCADDR6_R      (*((volatile uint8_t *)0x400500B0))
#define USB0_TXHUBADDR6_R       (*((volatile uint8_t *)0x400500B2))
#define USB0_TXHUBPORT6_R       (*((volatile uint8_t *)0x400500B3))
#define USB0_RXFUNCADDR6_R      (*((volatile uint8_t *)0x400500B4))
#define USB0_RXHUBADDR6_R       (*((volatile uint8_t *)0x400500B6))
#define USB0_RXHUBPORT6_R       (*((volatile uint8_t *)0x400500B7))
#define USB0_TXFUNCADDR7_R      (*((volatile uint8_t *)0x400500B8))
#define USB0_TXHUBADDR7_R       (*((volatile uint8_t *)0x400500BA))
#define USB0_TXHUBPORT7_R       (*((volatile uint8_t *)0x400500BB))
#define USB0_RXFUNCADDR7_R      (*((volatile uint8_t *)0x400500BC))
#define USB0_RXHUBADDR7_R       (*((volatile uint8_t *)0x400500BE))
#define USB0_RXHUBPORT7_R       (*((volatile uint8_t *)0x400500BF))
#define USB0_CSRL0_R            (*((volatile uint8_t *)0x40050102))
#define USB0_CSRH0_R            (*((volatile uint8_t *)0x40050103))
#define USB0_COUNT0_R           (*((volatile uint8_t *)0x40050108))
#define USB0_TYPE0_R            (*((volatile uint8_t *)0x4005010A))
#define USB0_NAKLMT_R           (*((volatile uint8_t *)0x4005010B))
#define USB0_TXMAXP1_R          (*((volatile uint16_t *)0x40050110))
#define USB0_TXCSRL1_R          (*((volatile uint8_t *)0x40050112))
#define USB0_TXCSRH1_R          (*((volatile uint8_t *)0x40050113))
#define USB0_RXMAXP1_R          (*((volatile uint16_t *)0x40050114))
#define USB0_RXCSRL1_R          (*((volatile uint8_t *)0x40050116))
#define USB0_RXCSRH1_R          (*((volatile uint8_t *)0x40050117))
#define USB0_RXCOUNT1_R         (*((volatile uint16_t *)0x40050118))
#define USB0_TXTYPE1_R          (*((volatile uint8_t *)0x4005011A))
#define USB0_TXINTERVAL1_R      (*((volatile uint8_t *)0x4005011B))
#define USB0_RXTYPE1_R          (*((volatile uint8_t *)0x4005011C))
#define USB0_RXINTERVAL1_R      (*((volatile uint8_t *)0x4005011D))
#define USB0_TXMAXP2_R          (*((volatile uint16_t *)0x40050120))
#define USB0_TXCSRL2_R          (*((volatile uint8_t *)0x40050122))
#define USB0_TXCSRH2_R          (*((volatile uint8_t *)0x40050123))
#define USB0_RXMAXP2_R          (*((volatile uint16_t *)0x40050124))
#define USB0_RXCSRL2_R          (*((volatile uint8_t *)0x40050126))
#define USB0_RXCSRH2_R          (*((volatile uint8_t *)0x40050127))
#define USB0_RXCOUNT2_R         (*((volatile uint16_t *)0x40050128))
#define USB0_TXTYPE2_R          (*((volatile uint8_t *)0x4005012A))
#define USB0_TXINTERVAL2_R      (*((volatile uint8_t *)0x4005012B))
#define USB0_RXTYPE2_R          (*((volatile uint8_t *)0x4005012C))
#define USB0_RXINTERVAL2_R      (*((volatile uint8_t *)0x4005012D))
#define USB0_TXMAXP3_R          (*((volatile uint16_t *)0x40050130))
#define USB0_TXCSRL3_R          (*((volatile uint8_t *)0x40050132))
#define USB0_TXCSRH3_R          (*((volatile uint8_t *)0x40050133))
#define USB0_RXMAXP3_R          (*((volatile uint16_t *)0x40050134))
#define USB0_RXCSRL3_R          (*((volatile uint8_t *)0x40050136))
#define USB0_RXCSRH3_R          (*((volatile uint8_t *)0x40050137))
#define USB0_RXCOUNT3_R         (*((volatile uint16_t *)0x40050138))
#define USB0_TXTYPE3_R          (*((volatile uint8_t *)0x4005013A))
#define USB0_TXINTERVAL3_R      (*((volatile uint8_t *)0x4005013B))
#define USB0_RXTYPE3_R          (*((volatile uint8_t *)0x4005013C))
#define USB0_RXINTERVAL3_R      (*((volatile uint8_t *)0x4005013D))
#define USB0_TXMAXP4_R          (*((volatile uint16_t *)0x40050140))
#define USB0_TXCSRL4_R          (*((volatile uint8_t *)0x40050142))
#define USB0_TXCSRH4_R          (*((volatile uint8_t *)0x40050143))
#define USB0_RXMAXP4_R          (*((volatile uint16_t *)0x40050144))
#define USB0_RXCSRL4_R          (*((volatile uint8_t *)0x40050146))
#define USB0_RXCSRH4_R          (*((volatile uint8_t *)0x40050147))
#define USB0_RXCOUNT4_R         (*((volatile uint16_t *)0x40050148))
#define USB0_TXTYPE4_R          (*((volatile uint8_t *)0x4005014A))
#define USB0_TXINTERVAL4_R      (*((volatile uint8_t *)0x4005014B))
#define USB0_RXTYPE4_R          (*((volatile uint8_t *)0x4005014C))
#define USB0_RXINTERVAL4_R      (*((volatile uint8_t *)0x4005014D))
#define USB0_TXMAXP5_R          (*((volatile uint16_t *)0x40050150))
#define USB0_TXCSRL5_R          (*((volatile uint8_t *)0x40050152))
#define USB0_TXCSRH5_R          (*((volatile uint8_t *)0x40050153))
#define USB0_RXMAXP5_R          (*((volatile uint16_t *)0x40050154))
#define USB0_RXCSRL5_R          (*((volatile uint8_t *)0x40050156))
#define USB0_RXCSRH5_R          (*((volatile uint8_t *)0x40050157))
#define USB0_RXCOUNT5_R         (*((volatile uint16_t *)0x40050158))
#define USB0_TXTYPE5_R          (*((volatile uint8_t *)0x4005015A))
#define USB0_TXINTERVAL5_R      (*((volatile uint8_t *)0x4005015B))
#define USB0_RXTYPE5_R          (*((volatile uint8_t *)0x4005015C))
#define USB0_RXINTERVAL5_R      (*((volatile uint8_t *)0x4005015D))
#define USB0_TXMAXP6_R          (*((volatile uint16_t *)0x40050160))
#define USB0_TXCSRL6_R          (*((volatile uint8_t *)0x40050162))
#define USB0_TXCSRH6_R          (*((volatile uint8_t *)0x40050163))
#define USB0_RXMAXP6_R          (*((volatile uint16_t *)0x40050164))
#define USB0_RXCSRL6_R          (*((volatile uint8_t *)0x40050166))
#define USB0_RXCSRH6_R          (*((volatile uint8_t *)0x40050167))
#define USB0_RXCOUNT6_R         (*((volatile uint16_t *)0x40050168))
#define USB0_TXTYPE6_R          (*((volatile uint8_t *)0x4005016A))
#define USB0_TXINTERVAL6_R      (*((volatile uint8_t *)0x4005016B))
#define USB0_RXTYPE6_R          (*((volatile uint8_t *)0x4005016C))
#define USB0_RXINTERVAL6_R      (*((volatile uint8_t *)0x4005016D))
#define USB0_TXMAXP7_R          (*((volatile uint16_t *)0x40050170))
#define USB0_TXCSRL7_R          (*((volatile uint8_t *)0x40050172))
#define USB0_TXCSRH7_R          (*((volatile uint8_t *)0x40050173))
#define USB0_RXMAXP7_R          (*((volatile uint16_t *)0x40050174))
#define USB0_RXCSRL7_R          (*((volatile uint8_t *)0x40050176))
#define USB0_RXCSRH7_R          (*((volatile uint8_t *)0x40050177))
#define USB0_RXCOUNT7_R         (*((volatile uint16_t *)0x40050178))
#define USB0_TXTYPE7_R          (*((volatile uint8_t *)0x4005017A))
#define USB0_TXINTERVAL7_R      (*((volatile uint8_t *)0x4005017B))
#define USB0_RXTYPE7_R          (*((volatile uint8_t *)0x4005017C))
#define USB0_RXINTERVAL7_R      (*((volatile uint8_t *)0x4005017D))
#define USB0_DMAINTR_R          (*((volatile uint8_t *)0x40050200))
#define USB0_DMACTL0_R          (*((volatile uint16_t *)0x40050204))
#define USB0_DMAADDR0_R         (*((volatile uint32_t *)0x40050208))
#define USB0_DMACOUNT0_R        (*((volatile uint32_t *)0x4005020C))
#define USB0_DMACTL1_R          (*((volatile uint16_t *)0x40050214))
#define USB0_DMAADDR1_R         (*((volatile uint32_t *)0x40050218))
#define USB0_DMACOUNT1_R        (*((volatile uint32_t *)0x4005021C))
#define USB0_DMACTL2_R          (*((volatile uint16_t *)0x40050224))
#define USB0_DMAADDR2_R         (*((volatile uint32_t *)0x40050228))
#define USB0_DMACOUNT2_R        (*((volatile uint32_t *)0x4005022C))
#define USB0_DMACTL3_R          (*((volatile uint16_t *)0x40050234))
#define USB0_DMAADDR3_R         (*((volatile uint32_t *)0x40050238))
#define USB0_DMACOUNT3_R        (*((volatile uint32_t *)0x4005023C))
#define USB0_DMACTL4_R          (*((volatile uint16_t *)0x40050244))
#define USB0_DMAADDR4_R         (*((volatile uint32_t *)0x40050248))
#define USB0_DMACOUNT4_R        (*((volatile uint32_t *)0x4005024C))
#define USB0_DMACTL5_R          (*((volatile uint16_t *)0x40050254))
#define USB0_DMAADDR5_R         (*((volatile uint32_t *)0x40050258))
#define USB0_DMACOUNT5_R        (*((volatile uint32_t *)0x4005025C))
#define USB0_DMACTL6_R          (*((volatile uint16_t *)0x40050264))
#define USB0_DMAADDR6_R         (*((volatile uint32_t *)0x40050268))
#define USB0_DMACOUNT6_R        (*((volatile uint32_t *)0x4005026C))
#define USB0_DMACTL7_R          (*((volatile uint16_t *)0x40050274))
#define USB0_DMAADDR7_R         (*((volatile uint32_t *)0x40050278))
#define USB0_DMACOUNT7_R        (*((volatile uint32_t *)0x4005027C))
#define USB0_RQPKTCOUNT1_R      (*((volatile uint16_t *)0x40050304))
#define USB0_RQPKTCOUNT2_R      (*((volatile uint16_t *)0x40050308))
#define USB0_RQPKTCOUNT3_R      (*((volatile uint16_t *)0x4005030C))
#define USB0_RQPKTCOUNT4_R      (*((volatile uint16_t *)0x40050310))
#define USB0_RQPKTCOUNT5_R      (*((volatile uint16_t *)0x40050314))
#define USB0_RQPKTCOUNT6_R      (*((volatile uint16_t *)0x40050318))
#define USB0_RQPKTCOUNT7_R      (*((volatile uint16_t *)0x4005031C))
#define USB0_RXDPKTBUFDIS_R     (*((volatile uint16_t *)0x40050340))
#define USB0_TXDPKTBUFDIS_R     (*((volatile uint16_t *)0x40050342))
#define USB0_CTO_R              (*((volatile uint16_t *)0x40050344))
#define USB0_HHSRTN_R           (*((volatile uint16_t *)0x40050346))
#define USB0_HSBT_R             (*((volatile uint16_t *)0x40050348))
#define USB0_LPMATTR_R          (*((volatile uint16_t *)0x40050360))
#define USB0_LPMCNTRL_R         (*((volatile uint8_t *)0x40050362))
#define USB0_LPMIM_R            (*((volatile uint8_t *)0x40050363))
#define USB0_LPMRIS_R           (*((volatile uint8_t *)0x40050364))
#define USB0_LPMFADDR_R         (*((volatile uint8_t *)0x40050365))
#define USB0_EPC_R              (*((volatile uint32_t *)0x40050400))
#define USB0_EPCRIS_R           (*((volatile uint32_t *)0x40050404))
#define USB0_EPCIM_R            (*((volatile uint32_t *)0x40050408))
#define USB0_EPCISC_R           (*((volatile uint32_t *)0x4005040C))
#define USB0_DRRIS_R            (*((volatile uint32_t *)0x40050410))
#define USB0_DRIM_R             (*((volatile uint32_t *)0x40050414))
#define USB0_DRISC_R            (*((volatile uint32_t *)0x40050418))
#define USB0_GPCS_R             (*((volatile uint32_t *)0x4005041C))
#define USB0_VDC_R              (*((volatile uint32_t *)0x40050430))
#define USB0_VDCRIS_R           (*((volatile uint32_t *)0x40050434))
#define USB0_VDCIM_R            (*((volatile uint32_t *)0x40050438))
#define USB0_VDCISC_R           (*((volatile uint32_t *)0x4005043C))
#define USB0_PP_R               (*((volatile uint32_t *)0x40050FC0))
#define USB0_PC_R               (*((volatile uint32_t *)0x40050FC4))
#define USB0_CC_R               (*((volatile uint32_t *)0x40050FC8))

//*****************************************************************************
//
// GPIO registers (PORTA AHB)
//
//*****************************************************************************
#define GPIO_PORTA_AHB_DATA_BITS_R                                            \
                                ((volatile uint32_t *)0x40058000)
#define GPIO_PORTA_AHB_DATA_R   (*((volatile uint32_t *)0x400583FC))
#define GPIO_PORTA_AHB_DIR_R    (*((volatile uint32_t *)0x40058400))
#define GPIO_PORTA_AHB_IS_R     (*((volatile uint32_t *)0x40058404))
#define GPIO_PORTA_AHB_IBE_R    (*((volatile uint32_t *)0x40058408))
#define GPIO_PORTA_AHB_IEV_R    (*((volatile uint32_t *)0x4005840C))
#define GPIO_PORTA_AHB_IM_R     (*((volatile uint32_t *)0x40058410))
#define GPIO_PORTA_AHB_RIS_R    (*((volatile uint32_t *)0x40058414))
#define GPIO_PORTA_AHB_MIS_R    (*((volatile uint32_t *)0x40058418))
#define GPIO_PORTA_AHB_ICR_R    (*((volatile uint32_t *)0x4005841C))
#define GPIO_PORTA_AHB_AFSEL_R  (*((volatile uint32_t *)0x40058420))
#define GPIO_PORTA_AHB_DR2R_R   (*((volatile uint32_t *)0x40058500))
#define GPIO_PORTA_AHB_DR4R_R   (*((volatile uint32_t *)0x40058504))
#define GPIO_PORTA_AHB_DR8R_R   (*((volatile uint32_t *)0x40058508))
#define GPIO_PORTA_AHB_ODR_R    (*((volatile uint32_t *)0x4005850C))
#define GPIO_PORTA_AHB_PUR_R    (*((volatile uint32_t *)0x40058510))
#define GPIO_PORTA_AHB_PDR_R    (*((volatile uint32_t *)0x40058514))
#define GPIO_PORTA_AHB_SLR_R    (*((volatile uint32_t *)0x40058518))
#define GPIO_PORTA_AHB_DEN_R    (*((volatile uint32_t *)0x4005851C))
#define GPIO_PORTA_AHB_LOCK_R   (*((volatile uint32_t *)0x40058520))
#define GPIO_PORTA_AHB_CR_R     (*((volatile uint32_t *)0x40058524))
#define GPIO_PORTA_AHB_AMSEL_R  (*((volatile uint32_t *)0x40058528))
#define GPIO_PORTA_AHB_PCTL_R   (*((volatile uint32_t *)0x4005852C))
#define GPIO_PORTA_AHB_ADCCTL_R (*((volatile uint32_t *)0x40058530))
#define GPIO_PORTA_AHB_DMACTL_R (*((volatile uint32_t *)0x40058534))
#define GPIO_PORTA_AHB_SI_R     (*((volatile uint32_t *)0x40058538))
#define GPIO_PORTA_AHB_DR12R_R  (*((volatile uint32_t *)0x4005853C))
#define GPIO_PORTA_AHB_WAKEPEN_R                                              \
                                (*((volatile uint32_t *)0x40058540))
#define GPIO_PORTA_AHB_WAKELVL_R                                              \
                                (*((volatile uint32_t *)0x40058544))
#define GPIO_PORTA_AHB_WAKESTAT_R                                             \
                                (*((volatile uint32_t *)0x40058548))
#define GPIO_PORTA_AHB_PP_R     (*((volatile uint32_t *)0x40058FC0))
#define GPIO_PORTA_AHB_PC_R     (*((volatile uint32_t *)0x40058FC4))

//*****************************************************************************
//
// GPIO registers (PORTB AHB)
//
//*****************************************************************************
#define GPIO_PORTB_AHB_DATA_BITS_R                                            \
                                ((volatile uint32_t *)0x40059000)
#define GPIO_PORTB_AHB_DATA_R   (*((volatile uint32_t *)0x400593FC))
#define GPIO_PORTB_AHB_DIR_R    (*((volatile uint32_t *)0x40059400))
#define GPIO_PORTB_AHB_IS_R     (*((volatile uint32_t *)0x40059404))
#define GPIO_PORTB_AHB_IBE_R    (*((volatile uint32_t *)0x40059408))
#define GPIO_PORTB_AHB_IEV_R    (*((volatile uint32_t *)0x4005940C))
#define GPIO_PORTB_AHB_IM_R     (*((volatile uint32_t *)0x40059410))
#define GPIO_PORTB_AHB_RIS_R    (*((volatile uint32_t *)0x40059414))
#define GPIO_PORTB_AHB_MIS_R    (*((volatile uint32_t *)0x40059418))
#define GPIO_PORTB_AHB_ICR_R    (*((volatile uint32_t *)0x4005941C))
#define GPIO_PORTB_AHB_AFSEL_R  (*((volatile uint32_t *)0x40059420))
#define GPIO_PORTB_AHB_DR2R_R   (*((volatile uint32_t *)0x40059500))
#define GPIO_PORTB_AHB_DR4R_R   (*((volatile uint32_t *)0x40059504))
#define GPIO_PORTB_AHB_DR8R_R   (*((volatile uint32_t *)0x40059508))
#define GPIO_PORTB_AHB_ODR_R    (*((volatile uint32_t *)0x4005950C))
#define GPIO_PORTB_AHB_PUR_R    (*((volatile uint32_t *)0x40059510))
#define GPIO_PORTB_AHB_PDR_R    (*((volatile uint32_t *)0x40059514))
#define GPIO_PORTB_AHB_SLR_R    (*((volatile uint32_t *)0x40059518))
#define GPIO_PORTB_AHB_DEN_R    (*((volatile uint32_t *)0x4005951C))
#define GPIO_PORTB_AHB_LOCK_R   (*((volatile uint32_t *)0x40059520))
#define GPIO_PORTB_AHB_CR_R     (*((volatile uint32_t *)0x40059524))
#define GPIO_PORTB_AHB_AMSEL_R  (*((volatile uint32_t *)0x40059528))
#define GPIO_PORTB_AHB_PCTL_R   (*((volatile uint32_t *)0x4005952C))
#define GPIO_PORTB_AHB_ADCCTL_R (*((volatile uint32_t *)0x40059530))
#define GPIO_PORTB_AHB_DMACTL_R (*((volatile uint32_t *)0x40059534))
#define GPIO_PORTB_AHB_SI_R     (*((volatile uint32_t *)0x40059538))
#define GPIO_PORTB_AHB_DR12R_R  (*((volatile uint32_t *)0x4005953C))
#define GPIO_PORTB_AHB_WAKEPEN_R                                              \
                                (*((volatile uint32_t *)0x40059540))
#define GPIO_PORTB_AHB_WAKELVL_R                                              \
                                (*((volatile uint32_t *)0x40059544))
#define GPIO_PORTB_AHB_WAKESTAT_R                                             \
                                (*((volatile uint32_t *)0x40059548))
#define GPIO_PORTB_AHB_PP_R     (*((volatile uint32_t *)0x40059FC0))
#define GPIO_PORTB_AHB_PC_R     (*((volatile uint32_t *)0x40059FC4))

//*****************************************************************************
//
// GPIO registers (PORTC AHB)
//
//*****************************************************************************
#define GPIO_PORTC_AHB_DATA_BITS_R                                            \
                                ((volatile uint32_t *)0x4005A000)
#define GPIO_PORTC_AHB_DATA_R   (*((volatile uint32_t *)0x4005A3FC))
#define GPIO_PORTC_AHB_DIR_R    (*((volatile uint32_t *)0x4005A400))
#define GPIO_PORTC_AHB_IS_R     (*((volatile uint32_t *)0x4005A404))
#define GPIO_PORTC_AHB_IBE_R    (*((volatile uint32_t *)0x4005A408))
#define GPIO_PORTC_AHB_IEV_R    (*((volatile uint32_t *)0x4005A40C))
#define GPIO_PORTC_AHB_IM_R     (*((volatile uint32_t *)0x4005A410))
#define GPIO_PORTC_AHB_RIS_R    (*((volatile uint32_t *)0x4005A414))
#define GPIO_PORTC_AHB_MIS_R    (*((volatile uint32_t *)0x4005A418))
#define GPIO_PORTC_AHB_ICR_R    (*((volatile uint32_t *)0x4005A41C))
#define GPIO_PORTC_AHB_AFSEL_R  (*((volatile uint32_t *)0x4005A420))
#define GPIO_PORTC_AHB_DR2R_R   (*((volatile uint32_t *)0x4005A500))
#define GPIO_PORTC_AHB_DR4R_R   (*((volatile uint32_t *)0x4005A504))
#define GPIO_PORTC_AHB_DR8R_R   (*((volatile uint32_t *)0x4005A508))
#define GPIO_PORTC_AHB_ODR_R    (*((volatile uint32_t *)0x4005A50C))
#define GPIO_PORTC_AHB_PUR_R    (*((volatile uint32_t *)0x4005A510))
#define GPIO_PORTC_AHB_PDR_R    (*((volatile uint32_t *)0x4005A514))
#define GPIO_PORTC_AHB_SLR_R    (*((volatile uint32_t *)0x4005A518))
#define GPIO_PORTC_AHB_DEN_R    (*((volatile uint32_t *)0x4005A51C))
#define GPIO_PORTC_AHB_LOCK_R   (*((volatile uint32_t *)0x4005A520))
#define GPIO_PORTC_AHB_CR_R     (*((volatile uint32_t *)0x4005A524))
#define GPIO_PORTC_AHB_AMSEL_R  (*((volatile uint32_t *)0x4005A528))
#define GPIO_PORTC_AHB_PCTL_R   (*((volatile uint32_t *)0x4005A52C))
#define GPIO_PORTC_AHB_ADCCTL_R (*((volatile uint32_t *)0x4005A530))
#define GPIO_PORTC_AHB_DMACTL_R (*((volatile uint32_t *)0x4005A534))
#define GPIO_PORTC_AHB_SI_R     (*((volatile uint32_t *)0x4005A538))
#define GPIO_PORTC_AHB_DR12R_R  (*((volatile uint32_t *)0x4005A53C))
#define GPIO_PORTC_AHB_WAKEPEN_R                                              \
                                (*((volatile uint32_t *)0x4005A540))
#define GPIO_PORTC_AHB_WAKELVL_R                                              \
                                (*((volatile uint32_t *)0x4005A544))
#define GPIO_PORTC_AHB_WAKESTAT_R                                             \
                                (*((volatile uint32_t *)0x4005A548))
#define GPIO_PORTC_AHB_PP_R     (*((volatile uint32_t *)0x4005AFC0))
#define GPIO_PORTC_AHB_PC_R     (*((volatile uint32_t *)0x4005AFC4))

//*****************************************************************************
//
// GPIO registers (PORTD AHB)
//
//*****************************************************************************
#define GPIO_PORTD_AHB_DATA_BITS_R                                            \
                                ((volatile uint32_t *)0x4005B000)
#define GPIO_PORTD_AHB_DATA_R   (*((volatile uint32_t *)0x4005B3FC))
#define GPIO_PORTD_AHB_DIR_R    (*((volatile uint32_t *)0x4005B400))
#define GPIO_PORTD_AHB_IS_R     (*((volatile uint32_t *)0x4005B404))
#define GPIO_PORTD_AHB_IBE_R    (*((volatile uint32_t *)0x4005B408))
#define GPIO_PORTD_AHB_IEV_R    (*((volatile uint32_t *)0x4005B40C))
#define GPIO_PORTD_AHB_IM_R     (*((volatile uint32_t *)0x4005B410))
#define GPIO_PORTD_AHB_RIS_R    (*((volatile uint32_t *)0x4005B414))
#define GPIO_PORTD_AHB_MIS_R    (*((volatile uint32_t *)0x4005B418))
#define GPIO_PORTD_AHB_ICR_R    (*((volatile uint32_t *)0x4005B41C))
#define GPIO_PORTD_AHB_AFSEL_R  (*((volatile uint32_t *)0x4005B420))
#define GPIO_PORTD_AHB_DR2R_R   (*((volatile uint32_t *)0x4005B500))
#define GPIO_PORTD_AHB_DR4R_R   (*((volatile uint32_t *)0x4005B504))
#define GPIO_PORTD_AHB_DR8R_R   (*((volatile uint32_t *)0x4005B508))
#define GPIO_PORTD_AHB_ODR_R    (*((volatile uint32_t *)0x4005B50C))
#define GPIO_PORTD_AHB_PUR_R    (*((volatile uint32_t *)0x4005B510))
#define GPIO_PORTD_AHB_PDR_R    (*((volatile uint32_t *)0x4005B514))
#define GPIO_PORTD_AHB_SLR_R    (*((volatile uint32_t *)0x4005B518))
#define GPIO_PORTD_AHB_DEN_R    (*((volatile uint32_t *)0x4005B51C))
#define GPIO_PORTD_AHB_LOCK_R   (*((volatile uint32_t *)0x4005B520))
#define GPIO_PORTD_AHB_CR_R     (*((volatile uint32_t *)0x4005B524))
#define GPIO_PORTD_AHB_AMSEL_R  (*((volatile uint32_t *)0x4005B528))
#define GPIO_PORTD_AHB_PCTL_R   (*((volatile uint32_t *)0x4005B52C))
#define GPIO_PORTD_AHB_ADCCTL_R (*((volatile uint32_t *)0x4005B530))
#define GPIO_PORTD_AHB_DMACTL_R (*((volatile uint32_t *)0x4005B534))
#define GPIO_PORTD_AHB_SI_R     (*((volatile uint32_t *)0x4005B538))
#define GPIO_PORTD_AHB_DR12R_R  (*((volatile uint32_t *)0x4005B53C))
#define GPIO_PORTD_AHB_WAKEPEN_R                                              \
                                (*((volatile uint32_t *)0x4005B540))
#define GPIO_PORTD_AHB_WAKELVL_R                                              \
                                (*((volatile uint32_t *)0x4005B544))
#define GPIO_PORTD_AHB_WAKESTAT_R                                             \
                                (*((volatile uint32_t *)0x4005B548))
#define GPIO_PORTD_AHB_PP_R     (*((volatile uint32_t *)0x4005BFC0))
#define GPIO_PORTD_AHB_PC_R     (*((volatile uint32_t *)0x4005BFC4))

//*****************************************************************************
//
// GPIO registers (PORTE AHB)
//
//*****************************************************************************
#define GPIO_PORTE_AHB_DATA_BITS_R                                            \
                                ((volatile uint32_t *)0x4005C000)
#define GPIO_PORTE_AHB_DATA_R   (*((volatile uint32_t *)0x4005C3FC))
#define GPIO_PORTE_AHB_DIR_R    (*((volatile uint32_t *)0x4005C400))
#define GPIO_PORTE_AHB_IS_R     (*((volatile uint32_t *)0x4005C404))
#define GPIO_PORTE_AHB_IBE_R    (*((volatile uint32_t *)0x4005C408))
#define GPIO_PORTE_AHB_IEV_R    (*((volatile uint32_t *)0x4005C40C))
#define GPIO_PORTE_AHB_IM_R     (*((volatile uint32_t *)0x4005C410))
#define GPIO_PORTE_AHB_RIS_R    (*((volatile uint32_t *)0x4005C414))
#define GPIO_PORTE_AHB_MIS_R    (*((volatile uint32_t *)0x4005C418))
#define GPIO_PORTE_AHB_ICR_R    (*((volatile uint32_t *)0x4005C41C))
#define GPIO_PORTE_AHB_AFSEL_R  (*((volatile uint32_t *)0x4005C420))
#define GPIO_PORTE_AHB_DR2R_R   (*((volatile uint32_t *)0x4005C500))
#define GPIO_PORTE_AHB_DR4R_R   (*((volatile uint32_t *)0x4005C504))
#define GPIO_PORTE_AHB_DR8R_R   (*((volatile uint32_t *)0x4005C508))
#define GPIO_PORTE_AHB_ODR_R    (*((volatile uint32_t *)0x4005C50C))
#define GPIO_PORTE_AHB_PUR_R    (*((volatile uint32_t *)0x4005C510))
#define GPIO_PORTE_AHB_PDR_R    (*((volatile uint32_t *)0x4005C514))
#define GPIO_PORTE_AHB_SLR_R    (*((volatile uint32_t *)0x4005C518))
#define GPIO_PORTE_AHB_DEN_R    (*((volatile uint32_t *)0x4005C51C))
#define GPIO_PORTE_AHB_LOCK_R   (*((volatile uint32_t *)0x4005C520))
#define GPIO_PORTE_AHB_CR_R     (*((volatile uint32_t *)0x4005C524))
#define GPIO_PORTE_AHB_AMSEL_R  (*((volatile uint32_t *)0x4005C528))
#define GPIO_PORTE_AHB_PCTL_R   (*((volatile uint32_t *)0x4005C52C))
#define GPIO_PORTE_AHB_ADCCTL_R (*((volatile uint32_t *)0x4005C530))
#define GPIO_PORTE_AHB_DMACTL_R (*((volatile uint32_t *)0x4005C534))
#define GPIO_PORTE_AHB_SI_R     (*((volatile uint32_t *)0x4005C538))
#define GPIO_PORTE_AHB_DR12R_R  (*((volatile uint32_t *)0x4005C53C))
#define GPIO_PORTE_AHB_WAKEPEN_R                                              \
                                (*((volatile uint32_t *)0x4005C540))
#define GPIO_PORTE_AHB_WAKELVL_R                                              \
                                (*((volatile uint32_t *)0x4005C544))
#define GPIO_PORTE_AHB_WAKESTAT_R                                             \
                                (*((volatile uint32_t *)0x4005C548))
#define GPIO_PORTE_AHB_PP_R     (*((volatile uint32_t *)0x4005CFC0))
#define GPIO_PORTE_AHB_PC_R     (*((volatile uint32_t *)0x4005CFC4))

//*****************************************************************************
//
// GPIO registers (PORTF AHB)
//
//*****************************************************************************
#define GPIO_PORTF_AHB_DATA_BITS_R                                            \
                                ((volatile uint32_t *)0x4005D000)
#define GPIO_PORTF_AHB_DATA_R   (*((volatile uint32_t *)0x4005D3FC))
#define GPIO_PORTF_AHB_DIR_R    (*((volatile uint32_t *)0x4005D400))
#define GPIO_PORTF_AHB_IS_R     (*((volatile uint32_t *)0x4005D404))
#define GPIO_PORTF_AHB_IBE_R    (*((volatile uint32_t *)0x4005D408))
#define GPIO_PORTF_AHB_IEV_R    (*((volatile uint32_t *)0x4005D40C))
#define GPIO_PORTF_AHB_IM_R     (*((volatile uint32_t *)0x4005D410))
#define GPIO_PORTF_AHB_RIS_R    (*((volatile uint32_t *)0x4005D414))
#define GPIO_PORTF_AHB_MIS_R    (*((volatile uint32_t *)0x4005D418))
#define GPIO_PORTF_AHB_ICR_R    (*((volatile uint32_t *)0x4005D41C))
#define GPIO_PORTF_AHB_AFSEL_R  (*((volatile uint32_t *)0x4005D420))
#define GPIO_PORTF_AHB_DR2R_R   (*((volatile uint32_t *)0x4005D500))
#define GPIO_PORTF_AHB_DR4R_R   (*((volatile uint32_t *)0x4005D504))
#define GPIO_PORTF_AHB_DR8R_R   (*((volatile uint32_t *)0x4005D508))
#define GPIO_PORTF_AHB_ODR_R    (*((volatile uint32_t *)0x4005D50C))
#define GPIO_PORTF_AHB_PUR_R    (*((volatile uint32_t *)0x4005D510))
#define GPIO_PORTF_AHB_PDR_R    (*((volatile uint32_t *)0x4005D514))
#define GPIO_PORTF_AHB_SLR_R    (*((volatile uint32_t *)0x4005D518))
#define GPIO_PORTF_AHB_DEN_R    (*((volatile uint32_t *)0x4005D51C))
#define GPIO_PORTF_AHB_LOCK_R   (*((volatile uint32_t *)0x4005D520))
#define GPIO_PORTF_AHB_CR_R     (*((volatile uint32_t *)0x4005D524))
#define GPIO_PORTF_AHB_AMSEL_R  (*((volatile uint32_t *)0x4005D528))
#define GPIO_PORTF_AHB_PCTL_R   (*((volatile uint32_t *)0x4005D52C))
#define GPIO_PORTF_AHB_ADCCTL_R (*((volatile uint32_t *)0x4005D530))
#define GPIO_PORTF_AHB_DMACTL_R (*((volatile uint32_t *)0x4005D534))
#define GPIO_PORTF_AHB_SI_R     (*((volatile uint32_t *)0x4005D538))
#define GPIO_PORTF_AHB_DR12R_R  (*((volatile uint32_t *)0x4005D53C))
#define GPIO_PORTF_AHB_WAKEPEN_R                                              \
                                (*((volatile uint32_t *)0x4005D540))
#define GPIO_PORTF_AHB_WAKELVL_R                                              \
                                (*((volatile uint32_t *)0x4005D544))
#define GPIO_PORTF_AHB_WAKESTAT_R                                             \
                                (*((volatile uint32_t *)0x4005D548))
#define GPIO_PORTF_AHB_PP_R     (*((volatile uint32_t *)0x4005DFC0))
#define GPIO_PORTF_AHB_PC_R     (*((volatile uint32_t *)0x4005DFC4))

//*****************************************************************************
//
// GPIO registers (PORTG AHB)
//
//*****************************************************************************
#define GPIO_PORTG_AHB_DATA_BITS_R                                            \
                                ((volatile uint32_t *)0x4005E000)
#define GPIO_PORTG_AHB_DATA_R   (*((volatile uint32_t *)0x4005E3FC))
#define GPIO_PORTG_AHB_DIR_R    (*((volatile uint32_t *)0x4005E400))
#define GPIO_PORTG_AHB_IS_R     (*((volatile uint32_t *)0x4005E404))
#define GPIO_PORTG_AHB_IBE_R    (*((volatile uint32_t *)0x4005E408))
#define GPIO_PORTG_AHB_IEV_R    (*((volatile uint32_t *)0x4005E40C))
#define GPIO_PORTG_AHB_IM_R     (*((volatile uint32_t *)0x4005E410))
#define GPIO_PORTG_AHB_RIS_R    (*((volatile uint32_t *)0x4005E414))
#define GPIO_PORTG_AHB_MIS_R    (*((volatile uint32_t *)0x4005E418))
#define GPIO_PORTG_AHB_ICR_R    (*((volatile uint32_t *)0x4005E41C))
#define GPIO_PORTG_AHB_AFSEL_R  (*((volatile uint32_t *)0x4005E420))
#define GPIO_PORTG_AHB_DR2R_R   (*((volatile uint32_t *)0x4005E500))
#define GPIO_PORTG_AHB_DR4R_R   (*((volatile uint32_t *)0x4005E504))
#define GPIO_PORTG_AHB_DR8R_R   (*((volatile uint32_t *)0x4005E508))
#define GPIO_PORTG_AHB_ODR_R    (*((volatile uint32_t *)0x4005E50C))
#define GPIO_PORTG_AHB_PUR_R    (*((volatile uint32_t *)0x4005E510))
#define GPIO_PORTG_AHB_PDR_R    (*((volatile uint32_t *)0x4005E514))
#define GPIO_PORTG_AHB_SLR_R    (*((volatile uint32_t *)0x4005E518))
#define GPIO_PORTG_AHB_DEN_R    (*((volatile uint32_t *)0x4005E51C))
#define GPIO_PORTG_AHB_LOCK_R   (*((volatile uint32_t *)0x4005E520))
#define GPIO_PORTG_AHB_CR_R     (*((volatile uint32_t *)0x4005E524))
#define GPIO_PORTG_AHB_AMSEL_R  (*((volatile uint32_t *)0x4005E528))
#define GPIO_PORTG_AHB_PCTL_R   (*((volatile uint32_t *)0x4005E52C))
#define GPIO_PORTG_AHB_ADCCTL_R (*((volatile uint32_t *)0x4005E530))
#define GPIO_PORTG_AHB_DMACTL_R (*((volatile uint32_t *)0x4005E534))
#define GPIO_PORTG_AHB_SI_R     (*((volatile uint32_t *)0x4005E538))
#define GPIO_PORTG_AHB_DR12R_R  (*((volatile uint32_t *)0x4005E53C))
#define GPIO_PORTG_AHB_WAKEPEN_R                                              \
                                (*((volatile uint32_t *)0x4005E540))
#define GPIO_PORTG_AHB_WAKELVL_R                                              \
                                (*((volatile uint32_t *)0x4005E544))
#define GPIO_PORTG_AHB_WAKESTAT_R                                             \
                                (*((volatile uint32_t *)0x4005E548))
#define GPIO_PORTG_AHB_PP_R     (*((volatile uint32_t *)0x4005EFC0))
#define GPIO_PORTG_AHB_PC_R     (*((volatile uint32_t *)0x4005EFC4))

//*****************************************************************************
//
// GPIO registers (PORTH AHB)
//
//*****************************************************************************
#define GPIO_PORTH_AHB_DATA_BITS_R                                            \
                                ((volatile uint32_t *)0x4005F000)
#define GPIO_PORTH_AHB_DATA_R   (*((volatile uint32_t *)0x4005F3FC))
#define GPIO_PORTH_AHB_DIR_R    (*((volatile uint32_t *)0x4005F400))
#define GPIO_PORTH_AHB_IS_R     (*((volatile uint32_t *)0x4005F404))
#define GPIO_PORTH_AHB_IBE_R    (*((volatile uint32_t *)0x4005F408))
#define GPIO_PORTH_AHB_IEV_R    (*((volatile uint32_t *)0x4005F40C))
#define GPIO_PORTH_AHB_IM_R     (*((volatile uint32_t *)0x4005F410))
#define GPIO_PORTH_AHB_RIS_R    (*((volatile uint32_t *)0x4005F414))
#define GPIO_PORTH_AHB_MIS_R    (*((volatile uint32_t *)0x4005F418))
#define GPIO_PORTH_AHB_ICR_R    (*((volatile uint32_t *)0x4005F41C))
#define GPIO_PORTH_AHB_AFSEL_R  (*((volatile uint32_t *)0x4005F420))
#define GPIO_PORTH_AHB_DR2R_R   (*((volatile uint32_t *)0x4005F500))
#define GPIO_PORTH_AHB_DR4R_R   (*((volatile uint32_t *)0x4005F504))
#define GPIO_PORTH_AHB_DR8R_R   (*((volatile uint32_t *)0x4005F508))
#define GPIO_PORTH_AHB_ODR_R    (*((volatile uint32_t *)0x4005F50C))
#define GPIO_PORTH_AHB_PUR_R    (*((volatile uint32_t *)0x4005F510))
#define GPIO_PORTH_AHB_PDR_R    (*((volatile uint32_t *)0x4005F514))
#define GPIO_PORTH_AHB_SLR_R    (*((volatile uint32_t *)0x4005F518))
#define GPIO_PORTH_AHB_DEN_R    (*((volatile uint32_t *)0x4005F51C))
#define GPIO_PORTH_AHB_LOCK_R   (*((volatile uint32_t *)0x4005F520))
#define GPIO_PORTH_AHB_CR_R     (*((volatile uint32_t *)0x4005F524))
#define GPIO_PORTH_AHB_AMSEL_R  (*((volatile uint32_t *)0x4005F528))
#define GPIO_PORTH_AHB_PCTL_R   (*((volatile uint32_t *)0x4005F52C))
#define GPIO_PORTH_AHB_ADCCTL_R (*((volatile uint32_t *)0x4005F530))
#define GPIO_PORTH_AHB_DMACTL_R (*((volatile uint32_t *)0x4005F534))
#define GPIO_PORTH_AHB_SI_R     (*((volatile uint32_t *)0x4005F538))
#define GPIO_PORTH_AHB_DR12R_R  (*((volatile uint32_t *)0x4005F53C))
#define GPIO_PORTH_AHB_WAKEPEN_R                                              \
                                (*((volatile uint32_t *)0x4005F540))
#define GPIO_PORTH_AHB_WAKELVL_R                                              \
                                (*((volatile uint32_t *)0x4005F544))
#define GPIO_PORTH_AHB_WAKESTAT_R                                             \
                                (*((volatile uint32_t *)0x4005F548))
#define GPIO_PORTH_AHB_PP_R     (*((volatile uint32_t *)0x4005FFC0))
#define GPIO_PORTH_AHB_PC_R     (*((volatile uint32_t *)0x4005FFC4))

//*****************************************************************************
//
// GPIO registers (PORTJ AHB)
//
//*****************************************************************************
#define GPIO_PORTJ_AHB_DATA_BITS_R                                            \
                                ((volatile uint32_t *)0x40060000)
#define GPIO_PORTJ_AHB_DATA_R   (*((volatile uint32_t *)0x400603FC))
#define GPIO_PORTJ_AHB_DIR_R    (*((volatile uint32_t *)0x40060400))
#define GPIO_PORTJ_AHB_IS_R     (*((volatile uint32_t *)0x40060404))
#define GPIO_PORTJ_AHB_IBE_R    (*((volatile uint32_t *)0x40060408))
#define GPIO_PORTJ_AHB_IEV_R    (*((volatile uint32_t *)0x4006040C))
#define GPIO_PORTJ_AHB_IM_R     (*((volatile uint32_t *)0x40060410))
#define GPIO_PORTJ_AHB_RIS_R    (*((volatile uint32_t *)0x40060414))
#define GPIO_PORTJ_AHB_MIS_R    (*((volatile uint32_t *)0x40060418))
#define GPIO_PORTJ_AHB_ICR_R    (*((volatile uint32_t *)0x4006041C))
#define GPIO_PORTJ_AHB_AFSEL_R  (*((volatile uint32_t *)0x40060420))
#define GPIO_PORTJ_AHB_DR2R_R   (*((volatile uint32_t *)0x40060500))
#define GPIO_PORTJ_AHB_DR4R_R   (*((volatile uint32_t *)0x40060504))
#define GPIO_PORTJ_AHB_DR8R_R   (*((volatile uint32_t *)0x40060508))
#define GPIO_PORTJ_AHB_ODR_R    (*((volatile uint32_t *)0x4006050C))
#define GPIO_PORTJ_AHB_PUR_R    (*((volatile uint32_t *)0x40060510))
#define GPIO_PORTJ_AHB_PDR_R    (*((volatile uint32_t *)0x40060514))
#define GPIO_PORTJ_AHB_SLR_R    (*((volatile uint32_t *)0x40060518))
#define GPIO_PORTJ_AHB_DEN_R    (*((volatile uint32_t *)0x4006051C))
#define GPIO_PORTJ_AHB_LOCK_R   (*((volatile uint32_t *)0x40060520))
#define GPIO_PORTJ_AHB_CR_R     (*((volatile uint32_t *)0x40060524))
#define GPIO_PORTJ_AHB_AMSEL_R  (*((volatile uint32_t *)0x40060528))
#define GPIO_PORTJ_AHB_PCTL_R   (*((volatile uint32_t *)0x4006052C))
#define GPIO_PORTJ_AHB_ADCCTL_R (*((volatile uint32_t *)0x40060530))
#define GPIO_PORTJ_AHB_DMACTL_R (*((volatile uint32_t *)0x40060534))
#define GPIO_PORTJ_AHB_SI_R     (*((volatile uint32_t *)0x40060538))
#define GPIO_PORTJ_AHB_DR12R_R  (*((volatile uint32_t *)0x4006053C))
#define GPIO_PORTJ_AHB_WAKEPEN_R                                              \
                                (*((volatile uint32_t *)0x40060540))
#define GPIO_PORTJ_AHB_WAKELVL_R                                              \
                                (*((volatile uint32_t *)0x40060544))
#define GPIO_PORTJ_AHB_WAKESTAT_R                                             \
                                (*((volatile uint32_t *)0x40060548))
#define GPIO_PORTJ_AHB_PP_R     (*((volatile uint32_t *)0x40060FC0))
#define GPIO_PORTJ_AHB_PC_R     (*((volatile uint32_t *)0x40060FC4))

//*****************************************************************************
//
// GPIO registers (PORTK)
//
//*****************************************************************************
#define GPIO_PORTK_DATA_BITS_R  ((volatile uint32_t *)0x40061000)
#define GPIO_PORTK_DATA_R       (*((volatile uint32_t *)0x400613FC))
#define GPIO_PORTK_DIR_R        (*((volatile uint32_t *)0x40061400))
#define GPIO_PORTK_IS_R         (*((volatile uint32_t *)0x40061404))
#define GPIO_PORTK_IBE_R        (*((volatile uint32_t *)0x40061408))
#define GPIO_PORTK_IEV_R        (*((volatile uint32_t *)0x4006140C))
#define GPIO_PORTK_IM_R         (*((volatile uint32_t *)0x40061410))
#define GPIO_PORTK_RIS_R        (*((volatile uint32_t *)0x40061414))
#define GPIO_PORTK_MIS_R        (*((volatile uint32_t *)0x40061418))
#define GPIO_PORTK_ICR_R        (*((volatile uint32_t *)0x4006141C))
#define GPIO_PORTK_AFSEL_R      (*((volatile uint32_t *)0x40061420))
#define GPIO_PORTK_DR2R_R       (*((volatile uint32_t *)0x40061500))
#define GPIO_PORTK_DR4R_R       (*((volatile uint32_t *)0x40061504))
#define GPIO_PORTK_DR8R_R       (*((volatile uint32_t *)0x40061508))
#define GPIO_PORTK_ODR_R        (*((volatile uint32_t *)0x4006150C))
#define GPIO_PORTK_PUR_R        (*((volatile uint32_t *)0x40061510))
#define GPIO_PORTK_PDR_R        (*((volatile uint32_t *)0x40061514))
#define GPIO_PORTK_SLR_R        (*((volatile uint32_t *)0x40061518))
#define GPIO_PORTK_DEN_R        (*((volatile uint32_t *)0x4006151C))
#define GPIO_PORTK_LOCK_R       (*((volatile uint32_t *)0x40061520))
#define GPIO_PORTK_CR_R         (*((volatile uint32_t *)0x40061524))
#define GPIO_PORTK_AMSEL_R      (*((volatile uint32_t *)0x40061528))
#define GPIO_PORTK_PCTL_R       (*((volatile uint32_t *)0x4006152C))
#define GPIO_PORTK_ADCCTL_R     (*((volatile uint32_t *)0x40061530))
#define GPIO_PORTK_DMACTL_R     (*((volatile uint32_t *)0x40061534))
#define GPIO_PORTK_SI_R         (*((volatile uint32_t *)0x40061538))
#define GPIO_PORTK_DR12R_R      (*((volatile uint32_t *)0x4006153C))
#define GPIO_PORTK_WAKEPEN_R    (*((volatile uint32_t *)0x40061540))
#define GPIO_PORTK_WAKELVL_R    (*((volatile uint32_t *)0x40061544))
#define GPIO_PORTK_WAKESTAT_R   (*((volatile uint32_t *)0x40061548))
#define GPIO_PORTK_PP_R         (*((volatile uint32_t *)0x40061FC0))
#define GPIO_PORTK_PC_R         (*((volatile uint32_t *)0x40061FC4))

//*****************************************************************************
//
// GPIO registers (PORTL)
//
//*****************************************************************************
#define GPIO_PORTL_DATA_BITS_R  ((volatile uint32_t *)0x40062000)
#define GPIO_PORTL_DATA_R       (*((volatile uint32_t *)0x400623FC))
#define GPIO_PORTL_DIR_R        (*((volatile uint32_t *)0x40062400))
#define GPIO_PORTL_IS_R         (*((volatile uint32_t *)0x40062404))
#define GPIO_PORTL_IBE_R        (*((volatile uint32_t *)0x40062408))
#define GPIO_PORTL_IEV_R        (*((volatile uint32_t *)0x4006240C))
#define GPIO_PORTL_IM_R         (*((volatile uint32_t *)0x40062410))
#define GPIO_PORTL_RIS_R        (*((volatile uint32_t *)0x40062414))
#define GPIO_PORTL_MIS_R        (*((volatile uint32_t *)0x40062418))
#define GPIO_PORTL_ICR_R        (*((volatile uint32_t *)0x4006241C))
#define GPIO_PORTL_AFSEL_R      (*((volatile uint32_t *)0x40062420))
#define GPIO_PORTL_DR2R_R       (*((volatile uint32_t *)0x40062500))
#define GPIO_PORTL_DR4R_R       (*((volatile uint32_t *)0x40062504))
#define GPIO_PORTL_DR8R_R       (*((volatile uint32_t *)0x40062508))
#define GPIO_PORTL_ODR_R        (*((volatile uint32_t *)0x4006250C))
#define GPIO_PORTL_PUR_R        (*((volatile uint32_t *)0x40062510))
#define GPIO_PORTL_PDR_R        (*((volatile uint32_t *)0x40062514))
#define GPIO_PORTL_SLR_R        (*((volatile uint32_t *)0x40062518))
#define GPIO_PORTL_DEN_R        (*((volatile uint32_t *)0x4006251C))
#define GPIO_PORTL_LOCK_R       (*((volatile uint32_t *)0x40062520))
#define GPIO_PORTL_CR_R         (*((volatile uint32_t *)0x40062524))
#define GPIO_PORTL_AMSEL_R      (*((volatile uint32_t *)0x40062528))
#define GPIO_PORTL_PCTL_R       (*((volatile uint32_t *)0x4006252C))
#define GPIO_PORTL_ADCCTL_R     (*((volatile uint32_t *)0x40062530))
#define GPIO_PORTL_DMACTL_R     (*((volatile uint32_t *)0x40062534))
#define GPIO_PORTL_SI_R         (*((volatile uint32_t *)0x40062538))
#define GPIO_PORTL_DR12R_R      (*((volatile uint32_t *)0x4006253C))
#define GPIO_PORTL_WAKEPEN_R    (*((volatile uint32_t *)0x40062540))
#define GPIO_PORTL_WAKELVL_R    (*((volatile uint32_t *)0x40062544))
#define GPIO_PORTL_WAKESTAT_R   (*((volatile uint32_t *)0x40062548))
#define GPIO_PORTL_PP_R         (*((volatile uint32_t *)0x40062FC0))
#define GPIO_PORTL_PC_R         (*((volatile uint32_t *)0x40062FC4))

//*****************************************************************************
//
// GPIO registers (PORTM)
//
//*****************************************************************************
#define GPIO_PORTM_DATA_BITS_R  ((volatile uint32_t *)0x40063000)
#define GPIO_PORTM_DATA_R       (*((volatile uint32_t *)0x400633FC))
#define GPIO_PORTM_DIR_R        (*((volatile uint32_t *)0x40063400))
#define GPIO_PORTM_IS_R         (*((volatile uint32_t *)0x40063404))
#define GPIO_PORTM_IBE_R        (*((volatile uint32_t *)0x40063408))
#define GPIO_PORTM_IEV_R        (*((volatile uint32_t *)0x4006340C))
#define GPIO_PORTM_IM_R         (*((volatile uint32_t *)0x40063410))
#define GPIO_PORTM_RIS_R        (*((volatile uint32_t *)0x40063414))
#define GPIO_PORTM_MIS_R        (*((volatile uint32_t *)0x40063418))
#define GPIO_PORTM_ICR_R        (*((volatile uint32_t *)0x4006341C))
#define GPIO_PORTM_AFSEL_R      (*((volatile uint32_t *)0x40063420))
#define GPIO_PORTM_DR2R_R       (*((volatile uint32_t *)0x40063500))
#define GPIO_PORTM_DR4R_R       (*((volatile uint32_t *)0x40063504))
#define GPIO_PORTM_DR8R_R       (*((volatile uint32_t *)0x40063508))
#define GPIO_PORTM_ODR_R        (*((volatile uint32_t *)0x4006350C))
#define GPIO_PORTM_PUR_R        (*((volatile uint32_t *)0x40063510))
#define GPIO_PORTM_PDR_R        (*((volatile uint32_t *)0x40063514))
#define GPIO_PORTM_SLR_R        (*((volatile uint32_t *)0x40063518))
#define GPIO_PORTM_DEN_R        (*((volatile uint32_t *)0x4006351C))
#define GPIO_PORTM_LOCK_R       (*((volatile uint32_t *)0x40063520))
#define GPIO_PORTM_CR_R         (*((volatile uint32_t *)0x40063524))
#define GPIO_PORTM_AMSEL_R      (*((volatile uint32_t *)0x40063528))
#define GPIO_PORTM_PCTL_R       (*((volatile uint32_t *)0x4006352C))
#define GPIO_PORTM_ADCCTL_R     (*((volatile uint32_t *)0x40063530))
#define GPIO_PORTM_DMACTL_R     (*((volatile uint32_t *)0x40063534))
#define GPIO_PORTM_SI_R         (*((volatile uint32_t *)0x40063538))
#define GPIO_PORTM_DR12R_R      (*((volatile uint32_t *)0x4006353C))
#define GPIO_PORTM_WAKEPEN_R    (*((volatile uint32_t *)0x40063540))
#define GPIO_PORTM_WAKELVL_R    (*((volatile uint32_t *)0x40063544))
#define GPIO_PORTM_WAKESTAT_R   (*((volatile uint32_t *)0x40063548))
#define GPIO_PORTM_PP_R         (*((volatile uint32_t *)0x40063FC0))
#define GPIO_PORTM_PC_R         (*((volatile uint32_t *)0x40063FC4))

//*****************************************************************************
//
// GPIO registers (PORTN)
//
//*****************************************************************************
#define GPIO_PORTN_DATA_BITS_R  ((volatile uint32_t *)0x40064000)
#define GPIO_PORTN_DATA_R       (*((volatile uint32_t *)0x400643FC))
#define GPIO_PORTN_DIR_R        (*((volatile uint32_t *)0x40064400))
#define GPIO_PORTN_IS_R         (*((volatile uint32_t *)0x40064404))
#define GPIO_PORTN_IBE_R        (*((volatile uint32_t *)0x40064408))
#define GPIO_PORTN_IEV_R        (*((volatile uint32_t *)0x4006440C))
#define GPIO_PORTN_IM_R         (*((volatile uint32_t *)0x40064410))
#define GPIO_PORTN_RIS_R        (*((volatile uint32_t *)0x40064414))
#define GPIO_PORTN_MIS_R        (*((volatile uint32_t *)0x40064418))
#define GPIO_PORTN_ICR_R        (*((volatile uint32_t *)0x4006441C))
#define GPIO_PORTN_AFSEL_R      (*((volatile uint32_t *)0x40064420))
#define GPIO_PORTN_DR2R_R       (*((volatile uint32_t *)0x40064500))
#define GPIO_PORTN_DR4R_R       (*((volatile uint32_t *)0x40064504))
#define GPIO_PORTN_DR8R_R       (*((volatile uint32_t *)0x40064508))
#define GPIO_PORTN_ODR_R        (*((volatile uint32_t *)0x4006450C))
#define GPIO_PORTN_PUR_R        (*((volatile uint32_t *)0x40064510))
#define GPIO_PORTN_PDR_R        (*((volatile uint32_t *)0x40064514))
#define GPIO_PORTN_SLR_R        (*((volatile uint32_t *)0x40064518))
#define GPIO_PORTN_DEN_R        (*((volatile uint32_t *)0x4006451C))
#define GPIO_PORTN_LOCK_R       (*((volatile uint32_t *)0x40064520))
#define GPIO_PORTN_CR_R         (*((volatile uint32_t *)0x40064524))
#define GPIO_PORTN_AMSEL_R      (*((volatile uint32_t *)0x40064528))
#define GPIO_PORTN_PCTL_R       (*((volatile uint32_t *)0x4006452C))
#define GPIO_PORTN_ADCCTL_R     (*((volatile uint32_t *)0x40064530))
#define GPIO_PORTN_DMACTL_R     (*((volatile uint32_t *)0x40064534))
#define GPIO_PORTN_SI_R         (*((volatile uint32_t *)0x40064538))
#define GPIO_PORTN_DR12R_R      (*((volatile uint32_t *)0x4006453C))
#define GPIO_PORTN_WAKEPEN_R    (*((volatile uint32_t *)0x40064540))
#define GPIO_PORTN_WAKELVL_R    (*((volatile uint32_t *)0x40064544))
#define GPIO_PORTN_WAKESTAT_R   (*((volatile uint32_t *)0x40064548))
#define GPIO_PORTN_PP_R         (*((volatile uint32_t *)0x40064FC0))
#define GPIO_PORTN_PC_R         (*((volatile uint32_t *)0x40064FC4))

//*****************************************************************************
//
// GPIO registers (PORTP)
//
//*****************************************************************************
#define GPIO_PORTP_DATA_BITS_R  ((volatile uint32_t *)0x40065000)
#define GPIO_PORTP_DATA_R       (*((volatile uint32_t *)0x400653FC))
#define GPIO_PORTP_DIR_R        (*((volatile uint32_t *)0x40065400))
#define GPIO_PORTP_IS_R         (*((volatile uint32_t *)0x40065404))
#define GPIO_PORTP_IBE_R        (*((volatile uint32_t *)0x40065408))
#define GPIO_PORTP_IEV_R        (*((volatile uint32_t *)0x4006540C))
#define GPIO_PORTP_IM_R         (*((volatile uint32_t *)0x40065410))
#define GPIO_PORTP_RIS_R        (*((volatile uint32_t *)0x40065414))
#define GPIO_PORTP_MIS_R        (*((volatile uint32_t *)0x40065418))
#define GPIO_PORTP_ICR_R        (*((volatile uint32_t *)0x4006541C))
#define GPIO_PORTP_AFSEL_R      (*((volatile uint32_t *)0x40065420))
#define GPIO_PORTP_DR2R_R       (*((volatile uint32_t *)0x40065500))
#define GPIO_PORTP_DR4R_R       (*((volatile uint32_t *)0x40065504))
#define GPIO_PORTP_DR8R_R       (*((volatile uint32_t *)0x40065508))
#define GPIO_PORTP_ODR_R        (*((volatile uint32_t *)0x4006550C))
#define GPIO_PORTP_PUR_R        (*((volatile uint32_t *)0x40065510))
#define GPIO_PORTP_PDR_R        (*((volatile uint32_t *)0x40065514))
#define GPIO_PORTP_SLR_R        (*((volatile uint32_t *)0x40065518))
#define GPIO_PORTP_DEN_R        (*((volatile uint32_t *)0x4006551C))
#define GPIO_PORTP_LOCK_R       (*((volatile uint32_t *)0x40065520))
#define GPIO_PORTP_CR_R         (*((volatile uint32_t *)0x40065524))
#define GPIO_PORTP_AMSEL_R      (*((volatile uint32_t *)0x40065528))
#define GPIO_PORTP_PCTL_R       (*((volatile uint32_t *)0x4006552C))
#define GPIO_PORTP_ADCCTL_R     (*((volatile uint32_t *)0x40065530))
#define GPIO_PORTP_DMACTL_R     (*((volatile uint32_t *)0x40065534))
#define GPIO_PORTP_SI_R         (*((volatile uint32_t *)0x40065538))
#define GPIO_PORTP_DR12R_R      (*((volatile uint32_t *)0x4006553C))
#define GPIO_PORTP_WAKEPEN_R    (*((volatile uint32_t *)0x40065540))
#define GPIO_PORTP_WAKELVL_R    (*((volatile uint32_t *)0x40065544))
#define GPIO_PORTP_WAKESTAT_R   (*((volatile uint32_t *)0x40065548))
#define GPIO_PORTP_PP_R         (*((volatile uint32_t *)0x40065FC0))
#define GPIO_PORTP_PC_R         (*((volatile uint32_t *)0x40065FC4))

//*****************************************************************************
//
// GPIO registers (PORTQ)
//
//*****************************************************************************
#define GPIO_PORTQ_DATA_BITS_R  ((volatile uint32_t *)0x40066000)
#define GPIO_PORTQ_DATA_R       (*((volatile uint32_t *)0x400663FC))
#define GPIO_PORTQ_DIR_R        (*((volatile uint32_t *)0x40066400))
#define GPIO_PORTQ_IS_R         (*((volatile uint32_t *)0x40066404))
#define GPIO_PORTQ_IBE_R        (*((volatile uint32_t *)0x40066408))
#define GPIO_PORTQ_IEV_R        (*((volatile uint32_t *)0x4006640C))
#define GPIO_PORTQ_IM_R         (*((volatile uint32_t *)0x40066410))
#define GPIO_PORTQ_RIS_R        (*((volatile uint32_t *)0x40066414))
#define GPIO_PORTQ_MIS_R        (*((volatile uint32_t *)0x40066418))
#define GPIO_PORTQ_ICR_R        (*((volatile uint32_t *)0x4006641C))
#define GPIO_PORTQ_AFSEL_R      (*((volatile uint32_t *)0x40066420))
#define GPIO_PORTQ_DR2R_R       (*((volatile uint32_t *)0x40066500))
#define GPIO_PORTQ_DR4R_R       (*((volatile uint32_t *)0x40066504))
#define GPIO_PORTQ_DR8R_R       (*((volatile uint32_t *)0x40066508))
#define GPIO_PORTQ_ODR_R        (*((volatile uint32_t *)0x4006650C))
#define GPIO_PORTQ_PUR_R        (*((volatile uint32_t *)0x40066510))
#define GPIO_PORTQ_PDR_R        (*((volatile uint32_t *)0x40066514))
#define GPIO_PORTQ_SLR_R        (*((volatile uint32_t *)0x40066518))
#define GPIO_PORTQ_DEN_R        (*((volatile uint32_t *)0x4006651C))
#define GPIO_PORTQ_LOCK_R       (*((volatile uint32_t *)0x40066520))
#define GPIO_PORTQ_CR_R         (*((volatile uint32_t *)0x40066524))
#define GPIO_PORTQ_AMSEL_R      (*((volatile uint32_t *)0x40066528))
#define GPIO_PORTQ_PCTL_R       (*((volatile uint32_t *)0x4006652C))
#define GPIO_PORTQ_ADCCTL_R     (*((volatile uint32_t *)0x40066530))
#define GPIO_PORTQ_DMACTL_R     (*((volatile uint32_t *)0x40066534))
#define GPIO_PORTQ_SI_R         (*((volatile uint32_t *)0x40066538))
#define GPIO_PORTQ_DR12R_R      (*((volatile uint32_t *)0x4006653C))
#define GPIO_PORTQ_WAKEPEN_R    (*((volatile uint32_t *)0x40066540))
#define GPIO_PORTQ_WAKELVL_R    (*((volatile uint32_t *)0x40066544))
#define GPIO_PORTQ_WAKESTAT_R   (*((volatile uint32_t *)0x40066548))
#define GPIO_PORTQ_PP_R         (*((volatile uint32_t *)0x40066FC0))
#define GPIO_PORTQ_PC_R         (*((volatile uint32_t *)0x40066FC4))

//*****************************************************************************
//
// EEPROM registers (EEPROM)
//
//*****************************************************************************
#define EEPROM_EESIZE_R         (*((volatile uint32_t *)0x400AF000))
#define EEPROM_EEBLOCK_R        (*((volatile uint32_t *)0x400AF004))
#define EEPROM_EEOFFSET_R       (*((volatile uint32_t *)0x400AF008))
#define EEPROM_EERDWR_R         (*((volatile uint32_t *)0x400AF010))
#define EEPROM_EERDWRINC_R      (*((volatile uint32_t *)0x400AF014))
#define EEPROM_EEDONE_R         (*((volatile uint32_t *)0x400AF018))
#define EEPROM_EESUPP_R         (*((volatile uint32_t *)0x400AF01C))
#define EEPROM_EEUNLOCK_R       (*((volatile uint32_t *)0x400AF020))
#define EEPROM_EEPROT_R         (*((volatile uint32_t *)0x400AF030))
#define EEPROM_EEPASS0_R        (*((volatile uint32_t *)0x400AF034))
#define EEPROM_EEPASS1_R        (*((volatile uint32_t *)0x400AF038))
#define EEPROM_EEPASS2_R        (*((volatile uint32_t *)0x400AF03C))
#define EEPROM_EEINT_R          (*((volatile uint32_t *)0x400AF040))
#define EEPROM_EEHIDE0_R        (*((volatile uint32_t *)0x400AF050))
#define EEPROM_EEHIDE1_R        (*((volatile uint32_t *)0x400AF054))
#define EEPROM_EEHIDE2_R        (*((volatile uint32_t *)0x400AF058))
#define EEPROM_EEDBGME_R        (*((volatile uint32_t *)0x400AF080))
#define EEPROM_PP_R             (*((volatile uint32_t *)0x400AFFC0))

//*****************************************************************************
//
// I2C registers (I2C8)
//
//*****************************************************************************
#define I2C8_MSA_R              (*((volatile uint32_t *)0x400B8000))
#define I2C8_MCS_R              (*((volatile uint32_t *)0x400B8004))
#define I2C8_MDR_R              (*((volatile uint32_t *)0x400B8008))
#define I2C8_MTPR_R             (*((volatile uint32_t *)0x400B800C))
#define I2C8_MIMR_R             (*((volatile uint32_t *)0x400B8010))
#define I2C8_MRIS_R             (*((volatile uint32_t *)0x400B8014))
#define I2C8_MMIS_R             (*((volatile uint32_t *)0x400B8018))
#define I2C8_MICR_R             (*((volatile uint32_t *)0x400B801C))
#define I2C8_MCR_R              (*((volatile uint32_t *)0x400B8020))
#define I2C8_MCLKOCNT_R         (*((volatile uint32_t *)0x400B8024))
#define I2C8_MBMON_R            (*((volatile uint32_t *)0x400B802C))
#define I2C8_MBLEN_R            (*((volatile uint32_t *)0x400B8030))
#define I2C8_MBCNT_R            (*((volatile uint32_t *)0x400B8034))
#define I2C8_SOAR_R             (*((volatile uint32_t *)0x400B8800))
#define I2C8_SCSR_R             (*((volatile uint32_t *)0x400B8804))
#define I2C8_SDR_R              (*((volatile uint32_t *)0x400B8808))
#define I2C8_SIMR_R             (*((volatile uint32_t *)0x400B880C))
#define I2C8_SRIS_R             (*((volatile uint32_t *)0x400B8810))
#define I2C8_SMIS_R             (*((volatile uint32_t *)0x400B8814))
#define I2C8_SICR_R             (*((volatile uint32_t *)0x400B8818))
#define I2C8_SOAR2_R            (*((volatile uint32_t *)0x400B881C))
#define I2C8_SACKCTL_R          (*((volatile uint32_t *)0x400B8820))
#define I2C8_FIFODATA_R         (*((volatile uint32_t *)0x400B8F00))
#define I2C8_FIFOCTL_R          (*((volatile uint32_t *)0x400B8F04))
#define I2C8_FIFOSTATUS_R       (*((volatile uint32_t *)0x400B8F08))
#define I2C8_PP_R               (*((volatile uint32_t *)0x400B8FC0))
#define I2C8_PC_R               (*((volatile uint32_t *)0x400B8FC4))

//*****************************************************************************
//
// I2C registers (I2C9)
//
//*****************************************************************************
#define I2C9_MSA_R              (*((volatile uint32_t *)0x400B9000))
#define I2C9_MCS_R              (*((volatile uint32_t *)0x400B9004))
#define I2C9_MDR_R              (*((volatile uint32_t *)0x400B9008))
#define I2C9_MTPR_R             (*((volatile uint32_t *)0x400B900C))
#define I2C9_MIMR_R             (*((volatile uint32_t *)0x400B9010))
#define I2C9_MRIS_R             (*((volatile uint32_t *)0x400B9014))
#define I2C9_MMIS_R             (*((volatile uint32_t *)0x400B9018))
#define I2C9_MICR_R             (*((volatile uint32_t *)0x400B901C))
#define I2C9_MCR_R              (*((volatile uint32_t *)0x400B9020))
#define I2C9_MCLKOCNT_R         (*((volatile uint32_t *)0x400B9024))
#define I2C9_MBMON_R            (*((volatile uint32_t *)0x400B902C))
#define I2C9_MBLEN_R            (*((volatile uint32_t *)0x400B9030))
#define I2C9_MBCNT_R            (*((volatile uint32_t *)0x400B9034))
#define I2C9_SOAR_R             (*((volatile uint32_t *)0x400B9800))
#define I2C9_SCSR_R             (*((volatile uint32_t *)0x400B9804))
#define I2C9_SDR_R              (*((volatile uint32_t *)0x400B9808))
#define I2C9_SIMR_R             (*((volatile uint32_t *)0x400B980C))
#define I2C9_SRIS_R             (*((volatile uint32_t *)0x400B9810))
#define I2C9_SMIS_R             (*((volatile uint32_t *)0x400B9814))
#define I2C9_SICR_R             (*((volatile uint32_t *)0x400B9818))
#define I2C9_SOAR2_R            (*((volatile uint32_t *)0x400B981C))
#define I2C9_SACKCTL_R          (*((volatile uint32_t *)0x400B9820))
#define I2C9_FIFODATA_R         (*((volatile uint32_t *)0x400B9F00))
#define I2C9_FIFOCTL_R          (*((volatile uint32_t *)0x400B9F04))
#define I2C9_FIFOSTATUS_R       (*((volatile uint32_t *)0x400B9F08))
#define I2C9_PP_R               (*((volatile uint32_t *)0x400B9FC0))
#define I2C9_PC_R               (*((volatile uint32_t *)0x400B9FC4))

//*****************************************************************************
//
// I2C registers (I2C4)
//
//*****************************************************************************
#define I2C4_MSA_R              (*((volatile uint32_t *)0x400C0000))
#define I2C4_MCS_R              (*((volatile uint32_t *)0x400C0004))
#define I2C4_MDR_R              (*((volatile uint32_t *)0x400C0008))
#define I2C4_MTPR_R             (*((volatile uint32_t *)0x400C000C))
#define I2C4_MIMR_R             (*((volatile uint32_t *)0x400C0010))
#define I2C4_MRIS_R             (*((volatile uint32_t *)0x400C0014))
#define I2C4_MMIS_R             (*((volatile uint32_t *)0x400C0018))
#define I2C4_MICR_R             (*((volatile uint32_t *)0x400C001C))
#define I2C4_MCR_R              (*((volatile uint32_t *)0x400C0020))
#define I2C4_MCLKOCNT_R         (*((volatile uint32_t *)0x400C0024))
#define I2C4_MBMON_R            (*((volatile uint32_t *)0x400C002C))
#define I2C4_MBLEN_R            (*((volatile uint32_t *)0x400C0030))
#define I2C4_MBCNT_R            (*((volatile uint32_t *)0x400C0034))
#define I2C4_SOAR_R             (*((volatile uint32_t *)0x400C0800))
#define I2C4_SCSR_R             (*((volatile uint32_t *)0x400C0804))
#define I2C4_SDR_R              (*((volatile uint32_t *)0x400C0808))
#define I2C4_SIMR_R             (*((volatile uint32_t *)0x400C080C))
#define I2C4_SRIS_R             (*((volatile uint32_t *)0x400C0810))
#define I2C4_SMIS_R             (*((volatile uint32_t *)0x400C0814))
#define I2C4_SICR_R             (*((volatile uint32_t *)0x400C0818))
#define I2C4_SOAR2_R            (*((volatile uint32_t *)0x400C081C))
#define I2C4_SACKCTL_R          (*((volatile uint32_t *)0x400C0820))
#define I2C4_FIFODATA_R         (*((volatile uint32_t *)0x400C0F00))
#define I2C4_FIFOCTL_R          (*((volatile uint32_t *)0x400C0F04))
#define I2C4_FIFOSTATUS_R       (*((volatile uint32_t *)0x400C0F08))
#define I2C4_PP_R               (*((volatile uint32_t *)0x400C0FC0))
#define I2C4_PC_R               (*((volatile uint32_t *)0x400C0FC4))

//*****************************************************************************
//
// I2C registers (I2C5)
//
//*****************************************************************************
#define I2C5_MSA_R              (*((volatile uint32_t *)0x400C1000))
#define I2C5_MCS_R              (*((volatile uint32_t *)0x400C1004))
#define I2C5_MDR_R              (*((volatile uint32_t *)0x400C1008))
#define I2C5_MTPR_R             (*((volatile uint32_t *)0x400C100C))
#define I2C5_MIMR_R             (*((volatile uint32_t *)0x400C1010))
#define I2C5_MRIS_R             (*((volatile uint32_t *)0x400C1014))
#define I2C5_MMIS_R             (*((volatile uint32_t *)0x400C1018))
#define I2C5_MICR_R             (*((volatile uint32_t *)0x400C101C))
#define I2C5_MCR_R              (*((volatile uint32_t *)0x400C1020))
#define I2C5_MCLKOCNT_R         (*((volatile uint32_t *)0x400C1024))
#define I2C5_MBMON_R            (*((volatile uint32_t *)0x400C102C))
#define I2C5_MBLEN_R            (*((volatile uint32_t *)0x400C1030))
#define I2C5_MBCNT_R            (*((volatile uint32_t *)0x400C1034))
#define I2C5_SOAR_R             (*((volatile uint32_t *)0x400C1800))
#define I2C5_SCSR_R             (*((volatile uint32_t *)0x400C1804))
#define I2C5_SDR_R              (*((volatile uint32_t *)0x400C1808))
#define I2C5_SIMR_R             (*((volatile uint32_t *)0x400C180C))
#define I2C5_SRIS_R             (*((volatile uint32_t *)0x400C1810))
#define I2C5_SMIS_R             (*((volatile uint32_t *)0x400C1814))
#define I2C5_SICR_R             (*((volatile uint32_t *)0x400C1818))
#define I2C5_SOAR2_R            (*((volatile uint32_t *)0x400C181C))
#define I2C5_SACKCTL_R          (*((volatile uint32_t *)0x400C1820))
#define I2C5_FIFODATA_R         (*((volatile uint32_t *)0x400C1F00))
#define I2C5_FIFOCTL_R          (*((volatile uint32_t *)0x400C1F04))
#define I2C5_FIFOSTATUS_R       (*((volatile uint32_t *)0x400C1F08))
#define I2C5_PP_R               (*((volatile uint32_t *)0x400C1FC0))
#define I2C5_PC_R               (*((volatile uint32_t *)0x400C1FC4))

//*****************************************************************************
//
// I2C registers (I2C6)
//
//*****************************************************************************
#define I2C6_MSA_R              (*((volatile uint32_t *)0x400C2000))
#define I2C6_MCS_R              (*((volatile uint32_t *)0x400C2004))
#define I2C6_MDR_R              (*((volatile uint32_t *)0x400C2008))
#define I2C6_MTPR_R             (*((volatile uint32_t *)0x400C200C))
#define I2C6_MIMR_R             (*((volatile uint32_t *)0x400C2010))
#define I2C6_MRIS_R             (*((volatile uint32_t *)0x400C2014))
#define I2C6_MMIS_R             (*((volatile uint32_t *)0x400C2018))
#define I2C6_MICR_R             (*((volatile uint32_t *)0x400C201C))
#define I2C6_MCR_R              (*((volatile uint32_t *)0x400C2020))
#define I2C6_MCLKOCNT_R         (*((volatile uint32_t *)0x400C2024))
#define I2C6_MBMON_R            (*((volatile uint32_t *)0x400C202C))
#define I2C6_MBLEN_R            (*((volatile uint32_t *)0x400C2030))
#define I2C6_MBCNT_R            (*((volatile uint32_t *)0x400C2034))
#define I2C6_SOAR_R             (*((volatile uint32_t *)0x400C2800))
#define I2C6_SCSR_R             (*((volatile uint32_t *)0x400C2804))
#define I2C6_SDR_R              (*((volatile uint32_t *)0x400C2808))
#define I2C6_SIMR_R             (*((volatile uint32_t *)0x400C280C))
#define I2C6_SRIS_R             (*((volatile uint32_t *)0x400C2810))
#define I2C6_SMIS_R             (*((volatile uint32_t *)0x400C2814))
#define I2C6_SICR_R             (*((volatile uint32_t *)0x400C2818))
#define I2C6_SOAR2_R            (*((volatile uint32_t *)0x400C281C))
#define I2C6_SACKCTL_R          (*((volatile uint32_t *)0x400C2820))
#define I2C6_FIFODATA_R         (*((volatile uint32_t *)0x400C2F00))
#define I2C6_FIFOCTL_R          (*((volatile uint32_t *)0x400C2F04))
#define I2C6_FIFOSTATUS_R       (*((volatile uint32_t *)0x400C2F08))
#define I2C6_PP_R               (*((volatile uint32_t *)0x400C2FC0))
#define I2C6_PC_R               (*((volatile uint32_t *)0x400C2FC4))

//*****************************************************************************
//
// I2C registers (I2C7)
//
//*****************************************************************************
#define I2C7_MSA_R              (*((volatile uint32_t *)0x400C3000))
#define I2C7_MCS_R              (*((volatile uint32_t *)0x400C3004))
#define I2C7_MDR_R              (*((volatile uint32_t *)0x400C3008))
#define I2C7_MTPR_R             (*((volatile uint32_t *)0x400C300C))
#define I2C7_MIMR_R             (*((volatile uint32_t *)0x400C3010))
#define I2C7_MRIS_R             (*((volatile uint32_t *)0x400C3014))
#define I2C7_MMIS_R             (*((volatile uint32_t *)0x400C3018))
#define I2C7_MICR_R             (*((volatile uint32_t *)0x400C301C))
#define I2C7_MCR_R              (*((volatile uint32_t *)0x400C3020))
#define I2C7_MCLKOCNT_R         (*((volatile uint32_t *)0x400C3024))
#define I2C7_MBMON_R            (*((volatile uint32_t *)0x400C302C))
#define I2C7_MBLEN_R            (*((volatile uint32_t *)0x400C3030))
#define I2C7_MBCNT_R            (*((volatile uint32_t *)0x400C3034))
#define I2C7_SOAR_R             (*((volatile uint32_t *)0x400C3800))
#define I2C7_SCSR_R             (*((volatile uint32_t *)0x400C3804))
#define I2C7_SDR_R              (*((volatile uint32_t *)0x400C3808))
#define I2C7_SIMR_R             (*((volatile uint32_t *)0x400C380C))
#define I2C7_SRIS_R             (*((volatile uint32_t *)0x400C3810))
#define I2C7_SMIS_R             (*((volatile uint32_t *)0x400C3814))
#define I2C7_SICR_R             (*((volatile uint32_t *)0x400C3818))
#define I2C7_SOAR2_R            (*((volatile uint32_t *)0x400C381C))
#define I2C7_SACKCTL_R          (*((volatile uint32_t *)0x400C3820))
#define I2C7_FIFODATA_R         (*((volatile uint32_t *)0x400C3F00))
#define I2C7_FIFOCTL_R          (*((volatile uint32_t *)0x400C3F04))
#define I2C7_FIFOSTATUS_R       (*((volatile uint32_t *)0x400C3F08))
#define I2C7_PP_R               (*((volatile uint32_t *)0x400C3FC0))
#define I2C7_PC_R               (*((volatile uint32_t *)0x400C3FC4))

//*****************************************************************************
//
// External Peripheral Interface registers (EPI0)
//
//*****************************************************************************
#define EPI0_CFG_R              (*((volatile uint32_t *)0x400D0000))
#define EPI0_BAUD_R             (*((volatile uint32_t *)0x400D0004))
#define EPI0_BAUD2_R            (*((volatile uint32_t *)0x400D0008))
#define EPI0_HB16CFG_R          (*((volatile uint32_t *)0x400D0010))
#define EPI0_GPCFG_R            (*((volatile uint32_t *)0x400D0010))
#define EPI0_SDRAMCFG_R         (*((volatile uint32_t *)0x400D0010))
#define EPI0_HB8CFG_R           (*((volatile uint32_t *)0x400D0010))
#define EPI0_HB8CFG2_R          (*((volatile uint32_t *)0x400D0014))
#define EPI0_HB16CFG2_R         (*((volatile uint32_t *)0x400D0014))
#define EPI0_ADDRMAP_R          (*((volatile uint32_t *)0x400D001C))
#define EPI0_RSIZE0_R           (*((volatile uint32_t *)0x400D0020))
#define EPI0_RADDR0_R           (*((volatile uint32_t *)0x400D0024))
#define EPI0_RPSTD0_R           (*((volatile uint32_t *)0x400D0028))
#define EPI0_RSIZE1_R           (*((volatile uint32_t *)0x400D0030))
#define EPI0_RADDR1_R           (*((volatile uint32_t *)0x400D0034))
#define EPI0_RPSTD1_R           (*((volatile uint32_t *)0x400D0038))
#define EPI0_STAT_R             (*((volatile uint32_t *)0x400D0060))
#define EPI0_RFIFOCNT_R         (*((volatile uint32_t *)0x400D006C))
#define EPI0_READFIFO0_R        (*((volatile uint32_t *)0x400D0070))
#define EPI0_READFIFO1_R        (*((volatile uint32_t *)0x400D0074))
#define EPI0_READFIFO2_R        (*((volatile uint32_t *)0x400D0078))
#define EPI0_READFIFO3_R        (*((volatile uint32_t *)0x400D007C))
#define EPI0_READFIFO4_R        (*((volatile uint32_t *)0x400D0080))
#define EPI0_READFIFO5_R        (*((volatile uint32_t *)0x400D0084))
#define EPI0_READFIFO6_R        (*((volatile uint32_t *)0x400D0088))
#define EPI0_READFIFO7_R        (*((volatile uint32_t *)0x400D008C))
#define EPI0_FIFOLVL_R          (*((volatile uint32_t *)0x400D0200))
#define EPI0_WFIFOCNT_R         (*((volatile uint32_t *)0x400D0204))
#define EPI0_DMATXCNT_R         (*((volatile uint32_t *)0x400D0208))
#define EPI0_IM_R               (*((volatile uint32_t *)0x400D0210))
#define EPI0_RIS_R              (*((volatile uint32_t *)0x400D0214))
#define EPI0_MIS_R              (*((volatile uint32_t *)0x400D0218))
#define EPI0_EISC_R             (*((volatile uint32_t *)0x400D021C))
#define EPI0_HB8CFG3_R          (*((volatile uint32_t *)0x400D0308))
#define EPI0_HB16CFG3_R         (*((volatile uint32_t *)0x400D0308))
#define EPI0_HB16CFG4_R         (*((volatile uint32_t *)0x400D030C))
#define EPI0_HB8CFG4_R          (*((volatile uint32_t *)0x400D030C))
#define EPI0_HB8TIME_R          (*((volatile uint32_t *)0x400D0310))
#define EPI0_HB16TIME_R         (*((volatile uint32_t *)0x400D0310))
#define EPI0_HB8TIME2_R         (*((volatile uint32_t *)0x400D0314))
#define EPI0_HB16TIME2_R        (*((volatile uint32_t *)0x400D0314))
#define EPI0_HB16TIME3_R        (*((volatile uint32_t *)0x400D0318))
#define EPI0_HB8TIME3_R         (*((volatile uint32_t *)0x400D0318))
#define EPI0_HB8TIME4_R         (*((volatile uint32_t *)0x400D031C))
#define EPI0_HB16TIME4_R        (*((volatile uint32_t *)0x400D031C))
#define EPI0_HBPSRAM_R          (*((volatile uint32_t *)0x400D0360))

//*****************************************************************************
//
// Timer registers (TIMER6)
//
//*****************************************************************************
#define TIMER6_CFG_R            (*((volatile uint32_t *)0x400E0000))
#define TIMER6_TAMR_R           (*((volatile uint32_t *)0x400E0004))
#define TIMER6_TBMR_R           (*((volatile uint32_t *)0x400E0008))
#define TIMER6_CTL_R            (*((volatile uint32_t *)0x400E000C))
#define TIMER6_SYNC_R           (*((volatile uint32_t *)0x400E0010))
#define TIMER6_IMR_R            (*((volatile uint32_t *)0x400E0018))
#define TIMER6_RIS_R            (*((volatile uint32_t *)0x400E001C))
#define TIMER6_MIS_R            (*((volatile uint32_t *)0x400E0020))
#define TIMER6_ICR_R            (*((volatile uint32_t *)0x400E0024))
#define TIMER6_TAILR_R          (*((volatile uint32_t *)0x400E0028))
#define TIMER6_TBILR_R          (*((volatile uint32_t *)0x400E002C))
#define TIMER6_TAMATCHR_R       (*((volatile uint32_t *)0x400E0030))
#define TIMER6_TBMATCHR_R       (*((volatile uint32_t *)0x400E0034))
#define TIMER6_TAPR_R           (*((volatile uint32_t *)0x400E0038))
#define TIMER6_TBPR_R           (*((volatile uint32_t *)0x400E003C))
#define TIMER6_TAPMR_R          (*((volatile uint32_t *)0x400E0040))
#define TIMER6_TBPMR_R          (*((volatile uint32_t *)0x400E0044))
#define TIMER6_TAR_R            (*((volatile uint32_t *)0x400E0048))
#define TIMER6_TBR_R            (*((volatile uint32_t *)0x400E004C))
#define TIMER6_TAV_R            (*((volatile uint32_t *)0x400E0050))
#define TIMER6_TBV_R            (*((volatile uint32_t *)0x400E0054))
#define TIMER6_RTCPD_R          (*((volatile uint32_t *)0x400E0058))
#define TIMER6_TAPS_R           (*((volatile uint32_t *)0x400E005C))
#define TIMER6_TBPS_R           (*((volatile uint32_t *)0x400E0060))
#define TIMER6_DMAEV_R          (*((volatile uint32_t *)0x400E006C))
#define TIMER6_ADCEV_R          (*((volatile uint32_t *)0x400E0070))
#define TIMER6_PP_R             (*((volatile uint32_t *)0x400E0FC0))
#define TIMER6_CC_R             (*((volatile uint32_t *)0x400E0FC8))

//*****************************************************************************
//
// Timer registers (TIMER7)
//
//*****************************************************************************
#define TIMER7_CFG_R            (*((volatile uint32_t *)0x400E1000))
#define TIMER7_TAMR_R           (*((volatile uint32_t *)0x400E1004))
#define TIMER7_TBMR_R           (*((volatile uint32_t *)0x400E1008))
#define TIMER7_CTL_R            (*((volatile uint32_t *)0x400E100C))
#define TIMER7_SYNC_R           (*((volatile uint32_t *)0x400E1010))
#define TIMER7_IMR_R            (*((volatile uint32_t *)0x400E1018))
#define TIMER7_RIS_R            (*((volatile uint32_t *)0x400E101C))
#define TIMER7_MIS_R            (*((volatile uint32_t *)0x400E1020))
#define TIMER7_ICR_R            (*((volatile uint32_t *)0x400E1024))
#define TIMER7_TAILR_R          (*((volatile uint32_t *)0x400E1028))
#define TIMER7_TBILR_R          (*((volatile uint32_t *)0x400E102C))
#define TIMER7_TAMATCHR_R       (*((volatile uint32_t *)0x400E1030))
#define TIMER7_TBMATCHR_R       (*((volatile uint32_t *)0x400E1034))
#define TIMER7_TAPR_R           (*((volatile uint32_t *)0x400E1038))
#define TIMER7_TBPR_R           (*((volatile uint32_t *)0x400E103C))
#define TIMER7_TAPMR_R          (*((volatile uint32_t *)0x400E1040))
#define TIMER7_TBPMR_R          (*((volatile uint32_t *)0x400E1044))
#define TIMER7_TAR_R            (*((volatile uint32_t *)0x400E1048))
#define TIMER7_TBR_R            (*((volatile uint32_t *)0x400E104C))
#define TIMER7_TAV_R            (*((volatile uint32_t *)0x400E1050))
#define TIMER7_TBV_R            (*((volatile uint32_t *)0x400E1054))
#define TIMER7_RTCPD_R          (*((volatile uint32_t *)0x400E1058))
#define TIMER7_TAPS_R           (*((volatile uint32_t *)0x400E105C))
#define TIMER7_TBPS_R           (*((volatile uint32_t *)0x400E1060))
#define TIMER7_DMAEV_R          (*((volatile uint32_t *)0x400E106C))
#define TIMER7_ADCEV_R          (*((volatile uint32_t *)0x400E1070))
#define TIMER7_PP_R             (*((volatile uint32_t *)0x400E1FC0))
#define TIMER7_CC_R             (*((volatile uint32_t *)0x400E1FC8))

//*****************************************************************************
//
// EMAC registers (EMAC0)
//
//*****************************************************************************
#define EMAC0_CFG_R             (*((volatile uint32_t *)0x400EC000))
#define EMAC0_FRAMEFLTR_R       (*((volatile uint32_t *)0x400EC004))
#define EMAC0_HASHTBLH_R        (*((volatile uint32_t *)0x400EC008))
#define EMAC0_HASHTBLL_R        (*((volatile uint32_t *)0x400EC00C))
#define EMAC0_MIIADDR_R         (*((volatile uint32_t *)0x400EC010))
#define EMAC0_MIIDATA_R         (*((volatile uint32_t *)0x400EC014))
#define EMAC0_FLOWCTL_R         (*((volatile uint32_t *)0x400EC018))
#define EMAC0_VLANTG_R          (*((volatile uint32_t *)0x400EC01C))
#define EMAC0_STATUS_R          (*((volatile uint32_t *)0x400EC024))
#define EMAC0_RWUFF_R           (*((volatile uint32_t *)0x400EC028))
#define EMAC0_PMTCTLSTAT_R      (*((volatile uint32_t *)0x400EC02C))
#define EMAC0_RIS_R             (*((volatile uint32_t *)0x400EC038))
#define EMAC0_IM_R              (*((volatile uint32_t *)0x400EC03C))
#define EMAC0_ADDR0H_R          (*((volatile uint32_t *)0x400EC040))
#define EMAC0_ADDR0L_R          (*((volatile uint32_t *)0x400EC044))
#define EMAC0_ADDR1H_R          (*((volatile uint32_t *)0x400EC048))
#define EMAC0_ADDR1L_R          (*((volatile uint32_t *)0x400EC04C))
#define EMAC0_ADDR2H_R          (*((volatile uint32_t *)0x400EC050))
#define EMAC0_ADDR2L_R          (*((volatile uint32_t *)0x400EC054))
#define EMAC0_ADDR3H_R          (*((volatile uint32_t *)0x400EC058))
#define EMAC0_ADDR3L_R          (*((volatile uint32_t *)0x400EC05C))
#define EMAC0_WDOGTO_R          (*((volatile uint32_t *)0x400EC0DC))
#define EMAC0_MMCCTRL_R         (*((volatile uint32_t *)0x400EC100))
#define EMAC0_MMCRXRIS_R        (*((volatile uint32_t *)0x400EC104))
#define EMAC0_MMCTXRIS_R        (*((volatile uint32_t *)0x400EC108))
#define EMAC0_MMCRXIM_R         (*((volatile uint32_t *)0x400EC10C))
#define EMAC0_MMCTXIM_R         (*((volatile uint32_t *)0x400EC110))
#define EMAC0_TXCNTGB_R         (*((volatile uint32_t *)0x400EC118))
#define EMAC0_TXCNTSCOL_R       (*((volatile uint32_t *)0x400EC14C))
#define EMAC0_TXCNTMCOL_R       (*((volatile uint32_t *)0x400EC150))
#define EMAC0_TXOCTCNTG_R       (*((volatile uint32_t *)0x400EC164))
#define EMAC0_RXCNTGB_R         (*((volatile uint32_t *)0x400EC180))
#define EMAC0_RXCNTCRCERR_R     (*((volatile uint32_t *)0x400EC194))
#define EMAC0_RXCNTALGNERR_R    (*((volatile uint32_t *)0x400EC198))
#define EMAC0_RXCNTGUNI_R       (*((volatile uint32_t *)0x400EC1C4))
#define EMAC0_VLNINCREP_R       (*((volatile uint32_t *)0x400EC584))
#define EMAC0_VLANHASH_R        (*((volatile uint32_t *)0x400EC588))
#define EMAC0_TIMSTCTRL_R       (*((volatile uint32_t *)0x400EC700))
#define EMAC0_SUBSECINC_R       (*((volatile uint32_t *)0x400EC704))
#define EMAC0_TIMSEC_R          (*((volatile uint32_t *)0x400EC708))
#define EMAC0_TIMNANO_R         (*((volatile uint32_t *)0x400EC70C))
#define EMAC0_TIMSECU_R         (*((volatile uint32_t *)0x400EC710))
#define EMAC0_TIMNANOU_R        (*((volatile uint32_t *)0x400EC714))
#define EMAC0_TIMADD_R          (*((volatile uint32_t *)0x400EC718))
#define EMAC0_TARGSEC_R         (*((volatile uint32_t *)0x400EC71C))
#define EMAC0_TARGNANO_R        (*((volatile uint32_t *)0x400EC720))
#define EMAC0_HWORDSEC_R        (*((volatile uint32_t *)0x400EC724))
#define EMAC0_TIMSTAT_R         (*((volatile uint32_t *)0x400EC728))
#define EMAC0_PPSCTRL_R         (*((volatile uint32_t *)0x400EC72C))
#define EMAC0_PPS0INTVL_R       (*((volatile uint32_t *)0x400EC760))
#define EMAC0_PPS0WIDTH_R       (*((volatile uint32_t *)0x400EC764))
#define EMAC0_DMABUSMOD_R       (*((volatile uint32_t *)0x400ECC00))
#define EMAC0_TXPOLLD_R         (*((volatile uint32_t *)0x400ECC04))
#define EMAC0_RXPOLLD_R         (*((volatile uint32_t *)0x400ECC08))
#define EMAC0_RXDLADDR_R        (*((volatile uint32_t *)0x400ECC0C))
#define EMAC0_TXDLADDR_R        (*((volatile uint32_t *)0x400ECC10))
#define EMAC0_DMARIS_R          (*((volatile uint32_t *)0x400ECC14))
#define EMAC0_DMAOPMODE_R       (*((volatile uint32_t *)0x400ECC18))
#define EMAC0_DMAIM_R           (*((volatile uint32_t *)0x400ECC1C))
#define EMAC0_MFBOC_R           (*((volatile uint32_t *)0x400ECC20))
#define EMAC0_RXINTWDT_R        (*((volatile uint32_t *)0x400ECC24))
#define EMAC0_HOSTXDESC_R       (*((volatile uint32_t *)0x400ECC48))
#define EMAC0_HOSRXDESC_R       (*((volatile uint32_t *)0x400ECC4C))
#define EMAC0_HOSTXBA_R         (*((volatile uint32_t *)0x400ECC50))
#define EMAC0_HOSRXBA_R         (*((volatile uint32_t *)0x400ECC54))
#define EMAC0_PP_R              (*((volatile uint32_t *)0x400ECFC0))
#define EMAC0_PC_R              (*((volatile uint32_t *)0x400ECFC4))
#define EMAC0_CC_R              (*((volatile uint32_t *)0x400ECFC8))
#define EMAC0_EPHYRIS_R         (*((volatile uint32_t *)0x400ECFD0))
#define EMAC0_EPHYIM_R          (*((volatile uint32_t *)0x400ECFD4))
#define EMAC0_EPHYMISC_R        (*((volatile uint32_t *)0x400ECFD8))

//*****************************************************************************
//
// EPHY registers (EMAC0)
//
//*****************************************************************************
#define EPHY_BMCR               0x00000000  // Ethernet PHY Basic Mode Control
#define EPHY_BMSR               0x00000001  // Ethernet PHY Basic Mode Status
#define EPHY_ID1                0x00000002  // Ethernet PHY Identifier Register
                                            // 1
#define EPHY_ID2                0x00000003  // Ethernet PHY Identifier Register
                                            // 2
#define EPHY_ANA                0x00000004  // Ethernet PHY Auto-Negotiation
                                            // Advertisement
#define EPHY_ANLPA              0x00000005  // Ethernet PHY Auto-Negotiation
                                            // Link Partner Ability
#define EPHY_ANER               0x00000006  // Ethernet PHY Auto-Negotiation
                                            // Expansion
#define EPHY_ANNPTR             0x00000007  // Ethernet PHY Auto-Negotiation
                                            // Next Page TX
#define EPHY_ANLNPTR            0x00000008  // Ethernet PHY Auto-Negotiation
                                            // Link Partner Ability Next Page
#define EPHY_CFG1               0x00000009  // Ethernet PHY Configuration 1
#define EPHY_CFG2               0x0000000A  // Ethernet PHY Configuration 2
#define EPHY_CFG3               0x0000000B  // Ethernet PHY Configuration 3
#define EPHY_REGCTL             0x0000000D  // Ethernet PHY Register Control
#define EPHY_ADDAR              0x0000000E  // Ethernet PHY Address or Data
#define EPHY_STS                0x00000010  // Ethernet PHY Status
#define EPHY_SCR                0x00000011  // Ethernet PHY Specific Control
#define EPHY_MISR1              0x00000012  // Ethernet PHY MII Interrupt
                                            // Status 1
#define EPHY_MISR2              0x00000013  // Ethernet PHY MII Interrupt
                                            // Status 2
#define EPHY_FCSCR              0x00000014  // Ethernet PHY False Carrier Sense
                                            // Counter
#define EPHY_RXERCNT            0x00000015  // Ethernet PHY Receive Error Count
#define EPHY_BISTCR             0x00000016  // Ethernet PHY BIST Control
#define EPHY_LEDCR              0x00000018  // Ethernet PHY LED Control
#define EPHY_CTL                0x00000019  // Ethernet PHY Control
#define EPHY_10BTSC             0x0000001A  // Ethernet PHY 10Base-T
                                            // Status/Control
#define EPHY_BICSR1             0x0000001B  // Ethernet PHY BIST Control and
                                            // Status 1
#define EPHY_BICSR2             0x0000001C  // Ethernet PHY BIST Control and
                                            // Status 2
#define EPHY_CDCR               0x0000001E  // Ethernet PHY Cable Diagnostic
                                            // Control
#define EPHY_RCR                0x0000001F  // Ethernet PHY Reset Control
#define EPHY_LEDCFG             0x00000025  // Ethernet PHY LED Configuration
#define EPHY_ALCDCR             0x00000155  // Ethernet PHY ALCD Control and
                                            // Results
#define EPHY_CDSCR              0x00000170  // Ethernet PHY Cable Diagnostic
                                            // Control
#define EPHY_CDLR1              0x00000180  // Ethernet PHY Cable Diagnostic
                                            // Location Result 1
#define EPHY_CDLR2              0x00000181  // Ethernet PHY Cable Diagnostic
                                            // Location Result 2
#define EPHY_CDLR3              0x00000182  // Ethernet PHY Cable Diagnostic
                                            // Location Result 3
#define EPHY_CDLR4              0x00000183  // Ethernet PHY Cable Diagnostic
                                            // Location Result 4
#define EPHY_CDLR5              0x00000184  // Ethernet PHY Cable Diagnostic
                                            // Location Result 5
#define EPHY_CDLAR1             0x00000185  // Ethernet PHY Cable Diagnostic
                                            // Amplitude Result 1
#define EPHY_CDLAR2             0x00000186  // Ethernet PHY Cable Diagnostic
                                            // Amplitude Result 2
#define EPHY_CDLAR3             0x00000187  // Ethernet PHY Cable Diagnostic
                                            // Amplitude Result 3
#define EPHY_CDLAR4             0x00000188  // Ethernet PHY Cable Diagnostic
                                            // Amplitude Result 4
#define EPHY_CDLAR5             0x00000189  // Ethernet PHY Cable Diagnostic
                                            // Amplitude Result 5
#define EPHY_CDGRR              0x0000018A  // Ethernet PHY Cable Diagnostic
                                            // General Result
#define EPHY_ALCDR2             0x00000215  // Ethernet PHY ALCD Results 2

//*****************************************************************************
//
// System Exception Module registers (SYSEXC)
//
//*****************************************************************************
#define SYSEXC_RIS_R            (*((volatile uint32_t *)0x400F9000))
#define SYSEXC_IM_R             (*((volatile uint32_t *)0x400F9004))
#define SYSEXC_MIS_R            (*((volatile uint32_t *)0x400F9008))
#define SYSEXC_IC_R             (*((volatile uint32_t *)0x400F900C))

//*****************************************************************************
//
// Hibernation module registers (HIB)
//
//*****************************************************************************
#define HIB_RTCC_R              (*((volatile uint32_t *)0x400FC000))
#define HIB_RTCM0_R             (*((volatile uint32_t *)0x400FC004))
#define HIB_RTCLD_R             (*((volatile uint32_t *)0x400FC00C))
#define HIB_CTL_R               (*((volatile uint32_t *)0x400FC010))
#define HIB_IM_R                (*((volatile uint32_t *)0x400FC014))
#define HIB_RIS_R               (*((volatile uint32_t *)0x400FC018))
#define HIB_MIS_R               (*((volatile uint32_t *)0x400FC01C))
#define HIB_IC_R                (*((volatile uint32_t *)0x400FC020))
#define HIB_RTCT_R              (*((volatile uint32_t *)0x400FC024))
#define HIB_RTCSS_R             (*((volatile uint32_t *)0x400FC028))
#define HIB_IO_R                (*((volatile uint32_t *)0x400FC02C))
#define HIB_DATA_R              (*((volatile uint32_t *)0x400FC030))
#define HIB_CALCTL_R            (*((volatile uint32_t *)0x400FC300))
#define HIB_CAL0_R              (*((volatile uint32_t *)0x400FC310))
#define HIB_CAL1_R              (*((volatile uint32_t *)0x400FC314))
#define HIB_CALLD0_R            (*((volatile uint32_t *)0x400FC320))
#define HIB_CALLD1_R            (*((volatile uint32_t *)0x400FC324))
#define HIB_CALM0_R             (*((volatile uint32_t *)0x400FC330))
#define HIB_CALM1_R             (*((volatile uint32_t *)0x400FC334))
#define HIB_LOCK_R              (*((volatile uint32_t *)0x400FC360))
#define HIB_TPCTL_R             (*((volatile uint32_t *)0x400FC400))
#define HIB_TPSTAT_R            (*((volatile uint32_t *)0x400FC404))
#define HIB_TPIO_R              (*((volatile uint32_t *)0x400FC410))
#define HIB_TPLOG0_R            (*((volatile uint32_t *)0x400FC4E0))
#define HIB_TPLOG1_R            (*((volatile uint32_t *)0x400FC4E4))
#define HIB_TPLOG2_R            (*((volatile uint32_t *)0x400FC4E8))
#define HIB_TPLOG3_R            (*((volatile uint32_t *)0x400FC4EC))
#define HIB_TPLOG4_R            (*((volatile uint32_t *)0x400FC4F0))
#define HIB_TPLOG5_R            (*((volatile uint32_t *)0x400FC4F4))
#define HIB_TPLOG6_R            (*((volatile uint32_t *)0x400FC4F8))
#define HIB_TPLOG7_R            (*((volatile uint32_t *)0x400FC4FC))
#define HIB_PP_R                (*((volatile uint32_t *)0x400FCFC0))
#define HIB_CC_R                (*((volatile uint32_t *)0x400FCFC8))

//*****************************************************************************
//
// FLASH registers (FLASH CTRL)
//
//*****************************************************************************
#define FLASH_FMA_R             (*((volatile uint32_t *)0x400FD000))
#define FLASH_FMD_R             (*((volatile uint32_t *)0x400FD004))
#define FLASH_FMC_R             (*((volatile uint32_t *)0x400FD008))
#define FLASH_FCRIS_R           (*((volatile uint32_t *)0x400FD00C))
#define FLASH_FCIM_R            (*((volatile uint32_t *)0x400FD010))
#define FLASH_FCMISC_R          (*((volatile uint32_t *)0x400FD014))
#define FLASH_FMC2_R            (*((volatile uint32_t *)0x400FD020))
#define FLASH_FWBVAL_R          (*((volatile uint32_t *)0x400FD030))
#define FLASH_FLPEKEY_R         (*((volatile uint32_t *)0x400FD03C))
#define FLASH_FWBN_R            (*((volatile uint32_t *)0x400FD100))
#define FLASH_PP_R              (*((volatile uint32_t *)0x400FDFC0))
#define FLASH_SSIZE_R           (*((volatile uint32_t *)0x400FDFC4))
#define FLASH_CONF_R            (*((volatile uint32_t *)0x400FDFC8))
#define FLASH_ROMSWMAP_R        (*((volatile uint32_t *)0x400FDFCC))
#define FLASH_DMASZ_R           (*((volatile uint32_t *)0x400FDFD0))
#define FLASH_DMAST_R           (*((volatile uint32_t *)0x400FDFD4))
#define FLASH_RVP_R             (*((volatile uint32_t *)0x400FE0D4))
#define FLASH_BOOTCFG_R         (*((volatile uint32_t *)0x400FE1D0))
#define FLASH_USRPWRUP_R        (*((volatile uint32_t *)0x400FE1DC))
#define FLASH_USERREG0_R        (*((volatile uint32_t *)0x400FE1E0))
#define FLASH_USERREG1_R        (*((volatile uint32_t *)0x400FE1E4))
#define FLASH_USERREG2_R        (*((volatile uint32_t *)0x400FE1E8))
#define FLASH_USERREG3_R        (*((volatile uint32_t *)0x400FE1EC))
#define FLASH_FMPRE0_R          (*((volatile uint32_t *)0x400FE200))
#define FLASH_FMPRE1_R          (*((volatile uint32_t *)0x400FE204))
#define FLASH_FMPRE2_R          (*((volatile uint32_t *)0x400FE208))
#define FLASH_FMPRE3_R          (*((volatile uint32_t *)0x400FE20C))
#define FLASH_FMPRE4_R          (*((volatile uint32_t *)0x400FE210))
#define FLASH_FMPRE5_R          (*((volatile uint32_t *)0x400FE214))
#define FLASH_FMPRE6_R          (*((volatile uint32_t *)0x400FE218))
#define FLASH_FMPRE7_R          (*((volatile uint32_t *)0x400FE21C))
#define FLASH_FMPRE8_R          (*((volatile uint32_t *)0x400FE220))
#define FLASH_FMPRE9_R          (*((volatile uint32_t *)0x400FE224))
#define FLASH_FMPRE10_R         (*((volatile uint32_t *)0x400FE228))
#define FLASH_FMPRE11_R         (*((volatile uint32_t *)0x400FE22C))
#define FLASH_FMPRE12_R         (*((volatile uint32_t *)0x400FE230))
#define FLASH_FMPRE13_R         (*((volatile uint32_t *)0x400FE234))
#define FLASH_FMPRE14_R         (*((volatile uint32_t *)0x400FE238))
#define FLASH_FMPRE15_R         (*((volatile uint32_t *)0x400FE23C))
#define FLASH_FMPPE0_R          (*((volatile uint32_t *)0x400FE400))
#define FLASH_FMPPE1_R          (*((volatile uint32_t *)0x400FE404))
#define FLASH_FMPPE2_R          (*((volatile uint32_t *)0x400FE408))
#define FLASH_FMPPE3_R          (*((volatile uint32_t *)0x400FE40C))
#define FLASH_FMPPE4_R          (*((volatile uint32_t *)0x400FE410))
#define FLASH_FMPPE5_R          (*((volatile uint32_t *)0x400FE414))
#define FLASH_FMPPE6_R          (*((volatile uint32_t *)0x400FE418))
#define FLASH_FMPPE7_R          (*((volatile uint32_t *)0x400FE41C))
#define FLASH_FMPPE8_R          (*((volatile uint32_t *)0x400FE420))
#define FLASH_FMPPE9_R          (*((volatile uint32_t *)0x400FE424))
#define FLASH_FMPPE10_R         (*((volatile uint32_t *)0x400FE428))
#define FLASH_FMPPE11_R         (*((volatile uint32_t *)0x400FE42C))
#define FLASH_FMPPE12_R         (*((volatile uint32_t *)0x400FE430))
#define FLASH_FMPPE13_R         (*((volatile uint32_t *)0x400FE434))
#define FLASH_FMPPE14_R         (*((volatile uint32_t *)0x400FE438))
#define FLASH_FMPPE15_R         (*((volatile uint32_t *)0x400FE43C))

//*****************************************************************************
//
// System Control registers (SYSCTL)
//
//*****************************************************************************
#define SYSCTL_DID0_R           (*((volatile uint32_t *)0x400FE000))
#define SYSCTL_DID1_R           (*((volatile uint32_t *)0x400FE004))
#define SYSCTL_PTBOCTL_R        (*((volatile uint32_t *)0x400FE038))
#define SYSCTL_RIS_R            (*((volatile uint32_t *)0x400FE050))
#define SYSCTL_IMC_R            (*((volatile uint32_t *)0x400FE054))
#define SYSCTL_MISC_R           (*((volatile uint32_t *)0x400FE058))
#define SYSCTL_RESC_R           (*((volatile uint32_t *)0x400FE05C))
#define SYSCTL_PWRTC_R          (*((volatile uint32_t *)0x400FE060))
#define SYSCTL_NMIC_R           (*((volatile uint32_t *)0x400FE064))
#define SYSCTL_MOSCCTL_R        (*((volatile uint32_t *)0x400FE07C))
#define SYSCTL_RSCLKCFG_R       (*((volatile uint32_t *)0x400FE0B0))
#define SYSCTL_MEMTIM0_R        (*((volatile uint32_t *)0x400FE0C0))
#define SYSCTL_DSMEMTIM0_R      (*((volatile uint32_t *)0x400FE0C8))
#define SYSCTL_ALTCLKCFG_R      (*((volatile uint32_t *)0x400FE138))
#define SYSCTL_DSCLKCFG_R       (*((volatile uint32_t *)0x400FE144))
#define SYSCTL_DIVSCLK_R        (*((volatile uint32_t *)0x400FE148))
#define SYSCTL_SYSPROP_R        (*((volatile uint32_t *)0x400FE14C))
#define SYSCTL_PIOSCCAL_R       (*((volatile uint32_t *)0x400FE150))
#define SYSCTL_PIOSCSTAT_R      (*((volatile uint32_t *)0x400FE154))
#define SYSCTL_PLLFREQ0_R       (*((volatile uint32_t *)0x400FE160))
#define SYSCTL_PLLFREQ1_R       (*((volatile uint32_t *)0x400FE164))
#define SYSCTL_PLLSTAT_R        (*((volatile uint32_t *)0x400FE168))
#define SYSCTL_SLPPWRCFG_R      (*((volatile uint32_t *)0x400FE188))
#define SYSCTL_DSLPPWRCFG_R     (*((volatile uint32_t *)0x400FE18C))
#define SYSCTL_NVMSTAT_R        (*((volatile uint32_t *)0x400FE1A0))
#define SYSCTL_LDODPCTL_R       (*((volatile uint32_t *)0x400FE1BC))
#define SYSCTL_RESBEHAVCTL_R    (*((volatile uint32_t *)0x400FE1D8))
#define SYSCTL_HSSR_R           (*((volatile uint32_t *)0x400FE1F4))
#define SYSCTL_USBPDS_R         (*((volatile uint32_t *)0x400FE280))
#define SYSCTL_USBMPC_R         (*((volatile uint32_t *)0x400FE284))
#define SYSCTL_EMACPDS_R        (*((volatile uint32_t *)0x400FE288))
#define SYSCTL_EMACMPC_R        (*((volatile uint32_t *)0x400FE28C))
#define SYSCTL_PPWD_R           (*((volatile uint32_t *)0x400FE300))
#define SYSCTL_PPTIMER_R        (*((volatile uint32_t *)0x400FE304))
#define SYSCTL_PPGPIO_R         (*((volatile uint32_t *)0x400FE308))
#define SYSCTL_PPDMA_R          (*((volatile uint32_t *)0x400FE30C))
#define SYSCTL_PPEPI_R          (*((volatile uint32_t *)0x400FE310))
#define SYSCTL_PPHIB_R          (*((volatile uint32_t *)0x400FE314))
#define SYSCTL_PPUART_R         (*((volatile uint32_t *)0x400FE318))
#define SYSCTL_PPSSI_R          (*((volatile uint32_t *)0x400FE31C))
#define SYSCTL_PPI2C_R          (*((volatile uint32_t *)0x400FE320))
#define SYSCTL_PPUSB_R          (*((volatile uint32_t *)0x400FE328))
#define SYSCTL_PPEPHY_R         (*((volatile uint32_t *)0x400FE330))
#define SYSCTL_PPCAN_R          (*((volatile uint32_t *)0x400FE334))
#define SYSCTL_PPADC_R          (*((volatile uint32_t *)0x400FE338))
#define SYSCTL_PPACMP_R         (*((volatile uint32_t *)0x400FE33C))
#define SYSCTL_PPPWM_R          (*((volatile uint32_t *)0x400FE340))
#define SYSCTL_PPQEI_R          (*((volatile uint32_t *)0x400FE344))
#define SYSCTL_PPLPC_R          (*((volatile uint32_t *)0x400FE348))
#define SYSCTL_PPPECI_R         (*((volatile uint32_t *)0x400FE350))
#define SYSCTL_PPFAN_R          (*((volatile uint32_t *)0x400FE354))
#define SYSCTL_PPEEPROM_R       (*((volatile uint32_t *)0x400FE358))
#define SYSCTL_PPWTIMER_R       (*((volatile uint32_t *)0x400FE35C))
#define SYSCTL_PPRTS_R          (*((volatile uint32_t *)0x400FE370))
#define SYSCTL_PPCCM_R          (*((volatile uint32_t *)0x400FE374))
#define SYSCTL_PPLCD_R          (*((volatile uint32_t *)0x400FE390))
#define SYSCTL_PPOWIRE_R        (*((volatile uint32_t *)0x400FE398))
#define SYSCTL_PPEMAC_R         (*((volatile uint32_t *)0x400FE39C))
#define SYSCTL_PPHIM_R          (*((volatile uint32_t *)0x400FE3A4))
#define SYSCTL_SRWD_R           (*((volatile uint32_t *)0x400FE500))
#define SYSCTL_SRTIMER_R        (*((volatile uint32_t *)0x400FE504))
#define SYSCTL_SRGPIO_R         (*((volatile uint32_t *)0x400FE508))
#define SYSCTL_SRDMA_R          (*((volatile uint32_t *)0x400FE50C))
#define SYSCTL_SREPI_R          (*((volatile uint32_t *)0x400FE510))
#define SYSCTL_SRHIB_R          (*((volatile uint32_t *)0x400FE514))
#define SYSCTL_SRUART_R         (*((volatile uint32_t *)0x400FE518))
#define SYSCTL_SRSSI_R          (*((volatile uint32_t *)0x400FE51C))
#define SYSCTL_SRI2C_R          (*((volatile uint32_t *)0x400FE520))
#define SYSCTL_SRUSB_R          (*((volatile uint32_t *)0x400FE528))
#define SYSCTL_SREPHY_R         (*((volatile uint32_t *)0x400FE530))
#define SYSCTL_SRCAN_R          (*((volatile uint32_t *)0x400FE534))
#define SYSCTL_SRADC_R          (*((volatile uint32_t *)0x400FE538))
#define SYSCTL_SRACMP_R         (*((volatile uint32_t *)0x400FE53C))
#define SYSCTL_SRPWM_R          (*((volatile uint32_t *)0x400FE540))
#define SYSCTL_SRQEI_R          (*((volatile uint32_t *)0x400FE544))
#define SYSCTL_SREEPROM_R       (*((volatile uint32_t *)0x400FE558))
#define SYSCTL_SRCCM_R          (*((volatile uint32_t *)0x400FE574))
#define SYSCTL_SREMAC_R         (*((volatile uint32_t *)0x400FE59C))
#define SYSCTL_RCGCWD_R         (*((volatile uint32_t *)0x400FE600))
#define SYSCTL_RCGCTIMER_R      (*((volatile uint32_t *)0x400FE604))
#define SYSCTL_RCGCGPIO_R       (*((volatile uint32_t *)0x400FE608))
#define SYSCTL_RCGCDMA_R        (*((volatile uint32_t *)0x400FE60C))
#define SYSCTL_RCGCEPI_R        (*((volatile uint32_t *)0x400FE610))
#define SYSCTL_RCGCHIB_R        (*((volatile uint32_t *)0x400FE614))
#define SYSCTL_RCGCUART_R       (*((volatile uint32_t *)0x400FE618))
#define SYSCTL_RCGCSSI_R        (*((volatile uint32_t *)0x400FE61C))
#define SYSCTL_RCGCI2C_R        (*((volatile uint32_t *)0x400FE620))
#define SYSCTL_RCGCUSB_R        (*((volatile uint32_t *)0x400FE628))
#define SYSCTL_RCGCEPHY_R       (*((volatile uint32_t *)0x400FE630))
#define SYSCTL_RCGCCAN_R        (*((volatile uint32_t *)0x400FE634))
#define SYSCTL_RCGCADC_R        (*((volatile uint32_t *)0x400FE638))
#define SYSCTL_RCGCACMP_R       (*((volatile uint32_t *)0x400FE63C))
#define SYSCTL_RCGCPWM_R        (*((volatile uint32_t *)0x400FE640))
#define SYSCTL_RCGCQEI_R        (*((volatile uint32_t *)0x400FE644))
#define SYSCTL_RCGCEEPROM_R     (*((volatile uint32_t *)0x400FE658))
#define SYSCTL_RCGCCCM_R        (*((volatile uint32_t *)0x400FE674))
#define SYSCTL_RCGCEMAC_R       (*((volatile uint32_t *)0x400FE69C))
#define SYSCTL_SCGCWD_R         (*((volatile uint32_t *)0x400FE700))
#define SYSCTL_SCGCTIMER_R      (*((volatile uint32_t *)0x400FE704))
#define SYSCTL_SCGCGPIO_R       (*((volatile uint32_t *)0x400FE708))
#define SYSCTL_SCGCEPI_R        (*((volatile uint32_t *)0x400FE710))
#define SYSCTL_SCGCHIB_R        (*((volatile uint32_t *)0x400FE714))
#define SYSCTL_SCGCUART_R       (*((volatile uint32_t *)0x400FE718))
#define SYSCTL_SCGCSSI_R        (*((volatile uint32_t *)0x400FE71C))
#define SYSCTL_SCGCI2C_R        (*((volatile uint32_t *)0x400FE720))
#define SYSCTL_SCGCUSB_R        (*((volatile uint32_t *)0x400FE728))
#define SYSCTL_SCGCEPHY_R       (*((volatile uint32_t *)0x400FE730))
#define SYSCTL_SCGCCAN_R        (*((volatile uint32_t *)0x400FE734))
#define SYSCTL_SCGCADC_R        (*((volatile uint32_t *)0x400FE738))
#define SYSCTL_SCGCACMP_R       (*((volatile uint32_t *)0x400FE73C))
#define SYSCTL_SCGCPWM_R        (*((volatile uint32_t *)0x400FE740))
#define SYSCTL_SCGCQEI_R        (*((volatile uint32_t *)0x400FE744))
#define SYSCTL_SCGCEEPROM_R     (*((volatile uint32_t *)0x400FE758))
#define SYSCTL_SCGCCCM_R        (*((volatile uint32_t *)0x400FE774))
#define SYSCTL_SCGCEMAC_R       (*((volatile uint32_t *)0x400FE79C))
#define SYSCTL_DCGCWD_R         (*((volatile uint32_t *)0x400FE800))
#define SYSCTL_DCGCTIMER_R      (*((volatile uint32_t *)0x400FE804))
#define SYSCTL_DCGCGPIO_R       (*((volatile uint32_t *)0x400FE808))
#define SYSCTL_DCGCEPI_R        (*((volatile uint32_t *)0x400FE810))
#define SYSCTL_DCGCHIB_R        (*((volatile uint32_t *)0x400FE814))
#define SYSCTL_DCGCUART_R       (*((volatile uint32_t *)0x400FE818))
#define SYSCTL_DCGCSSI_R        (*((volatile uint32_t *)0x400FE81C))
#define SYSCTL_DCGCI2C_R        (*((volatile uint32_t *)0x400FE820))
#define SYSCTL_DCGCUSB_R        (*((volatile uint32_t *)0x400FE828))
#define SYSCTL_DCGCEPHY_R       (*((volatile uint32_t *)0x400FE830))
#define SYSCTL_DCGCCAN_R        (*((volatile uint32_t *)0x400FE834))
#define SYSCTL_DCGCADC_R        (*((volatile uint32_t *)0x400FE838))
#define SYSCTL_DCGCACMP_R       (*((volatile uint32_t *)0x400FE83C))
#define SYSCTL_DCGCPWM_R        (*((volatile uint32_t *)0x400FE840))
#define SYSCTL_DCGCQEI_R        (*((volatile uint32_t *)0x400FE844))
#define SYSCTL_DCGCEEPROM_R     (*((volatile uint32_t *)0x400FE858))
#define SYSCTL_DCGCCCM_R        (*((volatile uint32_t *)0x400FE874))
#define SYSCTL_DCGCEMAC_R       (*((volatile uint32_t *)0x400FE89C))
#define SYSCTL_PCWD_R           (*((volatile uint32_t *)0x400FE900))
#define SYSCTL_PCTIMER_R        (*((volatile uint32_t *)0x400FE904))
#define SYSCTL_PCGPIO_R         (*((volatile uint32_t *)0x400FE908))
#define SYSCTL_PCDMA_R          (*((volatile uint32_t *)0x400FE90C))
#define SYSCTL_PCEPI_R          (*((volatile uint32_t *)0x400FE910))
#define SYSCTL_PCHIB_R          (*((volatile uint32_t *)0x400FE914))
#define SYSCTL_PCUART_R         (*((volatile uint32_t *)0x400FE918))
#define SYSCTL_PCSSI_R          (*((volatile uint32_t *)0x400FE91C))
#define SYSCTL_PCI2C_R          (*((volatile uint32_t *)0x400FE920))
#define SYSCTL_PCUSB_R          (*((volatile uint32_t *)0x400FE928))
#define SYSCTL_PCEPHY_R         (*((volatile uint32_t *)0x400FE930))
#define SYSCTL_PCCAN_R          (*((volatile uint32_t *)0x400FE934))
#define SYSCTL_PCADC_R          (*((volatile uint32_t *)0x400FE938))
#define SYSCTL_PCACMP_R         (*((volatile uint32_t *)0x400FE93C))
#define SYSCTL_PCPWM_R          (*((volatile uint32_t *)0x400FE940))
#define SYSCTL_PCQEI_R          (*((volatile uint32_t *)0x400FE944))
#define SYSCTL_PCEEPROM_R       (*((volatile uint32_t *)0x400FE958))
#define SYSCTL_PCCCM_R          (*((volatile uint32_t *)0x400FE974))
#define SYSCTL_PCEMAC_R         (*((volatile uint32_t *)0x400FE99C))
#define SYSCTL_PRWD_R           (*((volatile uint32_t *)0x400FEA00))
#define SYSCTL_PRTIMER_R        (*((volatile uint32_t *)0x400FEA04))
#define SYSCTL_PRGPIO_R         (*((volatile uint32_t *)0x400FEA08))
#define SYSCTL_PRDMA_R          (*((volatile uint32_t *)0x400FEA0C))
#define SYSCTL_PREPI_R          (*((volatile uint32_t *)0x400FEA10))
#define SYSCTL_PRHIB_R          (*((volatile uint32_t *)0x400FEA14))
#define SYSCTL_PRUART_R         (*((volatile uint32_t *)0x400FEA18))
#define SYSCTL_PRSSI_R          (*((volatile uint32_t *)0x400FEA1C))
#define SYSCTL_PRI2C_R          (*((volatile uint32_t *)0x400FEA20))
#define SYSCTL_PRUSB_R          (*((volatile uint32_t *)0x400FEA28))
#define SYSCTL_PREPHY_R         (*((volatile uint32_t *)0x400FEA30))
#define SYSCTL_PRCAN_R          (*((volatile uint32_t *)0x400FEA34))
#define SYSCTL_PRADC_R          (*((volatile uint32_t *)0x400FEA38))
#define SYSCTL_PRACMP_R         (*((volatile uint32_t *)0x400FEA3C))
#define SYSCTL_PRPWM_R          (*((volatile uint32_t *)0x400FEA40))
#define SYSCTL_PRQEI_R          (*((volatile uint32_t *)0x400FEA44))
#define SYSCTL_PREEPROM_R       (*((volatile uint32_t *)0x400FEA58))
#define SYSCTL_PRCCM_R          (*((volatile uint32_t *)0x400FEA74))
#define SYSCTL_PREMAC_R         (*((volatile uint32_t *)0x400FEA9C))

//*****************************************************************************
//
// Micro Direct Memory Access registers (UDMA)
//
//*****************************************************************************
#define UDMA_STAT_R             (*((volatile uint32_t *)0x400FF000))
#define UDMA_CFG_R              (*((volatile uint32_t *)0x400FF004))
#define UDMA_CTLBASE_R          (*((volatile uint32_t *)0x400FF008))
#define UDMA_ALTBASE_R          (*((volatile uint32_t *)0x400FF00C))
#define UDMA_WAITSTAT_R         (*((volatile uint32_t *)0x400FF010))
#define UDMA_SWREQ_R            (*((volatile uint32_t *)0x400FF014))
#define UDMA_USEBURSTSET_R      (*((volatile uint32_t *)0x400FF018))
#define UDMA_USEBURSTCLR_R      (*((volatile uint32_t *)0x400FF01C))
#define UDMA_REQMASKSET_R       (*((volatile uint32_t *)0x400FF020))
#define UDMA_REQMASKCLR_R       (*((volatile uint32_t *)0x400FF024))
#define UDMA_ENASET_R           (*((volatile uint32_t *)0x400FF028))
#define UDMA_ENACLR_R           (*((volatile uint32_t *)0x400FF02C))
#define UDMA_ALTSET_R           (*((volatile uint32_t *)0x400FF030))
#define UDMA_ALTCLR_R           (*((volatile uint32_t *)0x400FF034))
#define UDMA_PRIOSET_R          (*((volatile uint32_t *)0x400FF038))
#define UDMA_PRIOCLR_R          (*((volatile uint32_t *)0x400FF03C))
#define UDMA_ERRCLR_R           (*((volatile uint32_t *)0x400FF04C))
#define UDMA_CHASGN_R           (*((volatile uint32_t *)0x400FF500))
#define UDMA_CHMAP0_R           (*((volatile uint32_t *)0x400FF510))
#define UDMA_CHMAP1_R           (*((volatile uint32_t *)0x400FF514))
#define UDMA_CHMAP2_R           (*((volatile uint32_t *)0x400FF518))
#define UDMA_CHMAP3_R           (*((volatile uint32_t *)0x400FF51C))

//*****************************************************************************
//
// Micro Direct Memory Access (uDMA) offsets (UDMA)
//
//*****************************************************************************
#define UDMA_SRCENDP            0x00000000  // DMA Channel Source Address End
                                            // Pointer
#define UDMA_DSTENDP            0x00000004  // DMA Channel Destination Address
                                            // End Pointer
#define UDMA_CHCTL              0x00000008  // DMA Channel Control Word

//*****************************************************************************
//
// EC registers (CCM0)
//
//*****************************************************************************
#define CCM0_CRCCTRL_R          (*((volatile uint32_t *)0x44030400))
#define CCM0_CRCSEED_R          (*((volatile uint32_t *)0x44030410))
#define CCM0_CRCDIN_R           (*((volatile uint32_t *)0x44030414))
#define CCM0_CRCRSLTPP_R        (*((volatile uint32_t *)0x44030418))

//*****************************************************************************
//
// NVIC registers (NVIC)
//
//*****************************************************************************
#define NVIC_ACTLR_R            (*((volatile uint32_t *)0xE000E008))
#define NVIC_ST_CTRL_R          (*((volatile uint32_t *)0xE000E010))
#define NVIC_ST_RELOAD_R        (*((volatile uint32_t *)0xE000E014))
#define NVIC_ST_CURRENT_R       (*((volatile uint32_t *)0xE000E018))
#define NVIC_EN0_R              (*((volatile uint32_t *)0xE000E100))
#define NVIC_EN1_R              (*((volatile uint32_t *)0xE000E104))
#define NVIC_EN2_R              (*((volatile uint32_t *)0xE000E108))
#define NVIC_EN3_R              (*((volatile uint32_t *)0xE000E10C))
#define NVIC_DIS0_R             (*((volatile uint32_t *)0xE000E180))
#define NVIC_DIS1_R             (*((volatile uint32_t *)0xE000E184))
#define NVIC_DIS2_R             (*((volatile uint32_t *)0xE000E188))
#define NVIC_DIS3_R             (*((volatile uint32_t *)0xE000E18C))
#define NVIC_PEND0_R            (*((volatile uint32_t *)0xE000E200))
#define NVIC_PEND1_R            (*((volatile uint32_t *)0xE000E204))
#define NVIC_PEND2_R            (*((volatile uint32_t *)0xE000E208))
#define NVIC_PEND3_R            (*((volatile uint32_t *)0xE000E20C))
#define NVIC_UNPEND0_R          (*((volatile uint32_t *)0xE000E280))
#define NVIC_UNPEND1_R          (*((volatile uint32_t *)0xE000E284))
#define NVIC_UNPEND2_R          (*((volatile uint32_t *)0xE000E288))
#define NVIC_UNPEND3_R          (*((volatile uint32_t *)0xE000E28C))
#define NVIC_ACTIVE0_R          (*((volatile uint32_t *)0xE000E300))
#define NVIC_ACTIVE1_R          (*((volatile uint32_t *)0xE000E304))
#define NVIC_ACTIVE2_R          (*((volatile uint32_t *)0xE000E308))
#define NVIC_ACTIVE3_R          (*((volatile uint32_t *)0xE000E30C))
#define NVIC_PRI0_R             (*((volatile uint32_t *)0xE000E400))
#define NVIC_PRI1_R             (*((volatile uint32_t *)0xE000E404))
#define NVIC_PRI2_R             (*((volatile uint32_t *)0xE000E408))
#define NVIC_PRI3_R             (*((volatile uint32_t *)0xE000E40C))
#define NVIC_PRI4_R             (*((volatile uint32_t *)0xE000E410))
#define NVIC_PRI5_R             (*((volatile uint32_t *)0xE000E414))
#define NVIC_PRI6_R             (*((volatile uint32_t *)0xE000E418))
#define NVIC_PRI7_R             (*((volatile uint32_t *)0xE000E41C))
#define NVIC_PRI8_R             (*((volatile uint32_t *)0xE000E420))
#define NVIC_PRI9_R             (*((volatile uint32_t *)0xE000E424))
#define NVIC_PRI10_R            (*((volatile uint32_t *)0xE000E428))
#define NVIC_PRI11_R            (*((volatile uint32_t *)0xE000E42C))
#define NVIC_PRI12_R            (*((volatile uint32_t *)0xE000E430))
#define NVIC_PRI13_R            (*((volatile uint32_t *)0xE000E434))
#define NVIC_PRI14_R            (*((volatile uint32_t *)0xE000E438))
#define NVIC_PRI15_R            (*((volatile uint32_t *)0xE000E43C))
#define NVIC_PRI16_R            (*((volatile uint32_t *)0xE000E440))
#define NVIC_PRI17_R            (*((volatile uint32_t *)0xE000E444))
#define NVIC_PRI18_R            (*((volatile uint32_t *)0xE000E448))
#define NVIC_PRI19_R            (*((volatile uint32_t *)0xE000E44C))
#define NVIC_PRI20_R            (*((volatile uint32_t *)0xE000E450))
#define NVIC_PRI21_R            (*((volatile uint32_t *)0xE000E454))
#define NVIC_PRI22_R            (*((volatile uint32_t *)0xE000E458))
#define NVIC_PRI23_R            (*((volatile uint32_t *)0xE000E45C))
#define NVIC_PRI24_R            (*((volatile uint32_t *)0xE000E460))
#define NVIC_PRI25_R            (*((volatile uint32_t *)0xE000E464))
#define NVIC_PRI26_R            (*((volatile uint32_t *)0xE000E468))
#define NVIC_PRI27_R            (*((volatile uint32_t *)0xE000E46C))
#define NVIC_PRI28_R            (*((volatile uint32_t *)0xE000E470))
#define NVIC_CPUID_R            (*((volatile uint32_t *)0xE000ED00))
#define NVIC_INT_CTRL_R         (*((volatile uint32_t *)0xE000ED04))
#define NVIC_VTABLE_R           (*((volatile uint32_t *)0xE000ED08))
#define NVIC_APINT_R            (*((volatile uint32_t *)0xE000ED0C))
#define NVIC_SYS_CTRL_R         (*((volatile uint32_t *)0xE000ED10))
#define NVIC_CFG_CTRL_R         (*((volatile uint32_t *)0xE000ED14))
#define NVIC_SYS_PRI1_R         (*((volatile uint32_t *)0xE000ED18))
#define NVIC_SYS_PRI2_R         (*((volatile uint32_t *)0xE000ED1C))
#define NVIC_SYS_PRI3_R         (*((volatile uint32_t *)0xE000ED20))
#define NVIC_SYS_HND_CTRL_R     (*((volatile uint32_t *)0xE000ED24))
#define NVIC_FAULT_STAT_R       (*((volatile uint32_t *)0xE000ED28))
#define NVIC_HFAULT_STAT_R      (*((volatile uint32_t *)0xE000ED2C))
#define NVIC_DEBUG_STAT_R       (*((volatile uint32_t *)0xE000ED30))
#define NVIC_MM_ADDR_R          (*((volatile uint32_t *)0xE000ED34))
#define NVIC_FAULT_ADDR_R       (*((volatile uint32_t *)0xE000ED38))
#define NVIC_CPAC_R             (*((volatile uint32_t *)0xE000ED88))
#define NVIC_MPU_TYPE_R         (*((volatile uint32_t *)0xE000ED90))
#define NVIC_MPU_CTRL_R         (*((volatile uint32_t *)0xE000ED94))
#define NVIC_MPU_NUMBER_R       (*((volatile uint32_t *)0xE000ED98))
#define NVIC_MPU_BASE_R         (*((volatile uint32_t *)0xE000ED9C))
#define NVIC_MPU_ATTR_R         (*((volatile uint32_t *)0xE000EDA0))
#define NVIC_MPU_BASE1_R        (*((volatile uint32_t *)0xE000EDA4))
#define NVIC_MPU_ATTR1_R        (*((volatile uint32_t *)0xE000EDA8))
#define NVIC_MPU_BASE2_R        (*((volatile uint32_t *)0xE000EDAC))
#define NVIC_MPU_ATTR2_R        (*((volatile uint32_t *)0xE000EDB0))
#define NVIC_MPU_BASE3_R        (*((volatile uint32_t *)0xE000EDB4))
#define NVIC_MPU_ATTR3_R        (*((volatile uint32_t *)0xE000EDB8))
#define NVIC_DBG_CTRL_R         (*((volatile uint32_t *)0xE000EDF0))
#define NVIC_DBG_XFER_R         (*((volatile uint32_t *)0xE000EDF4))
#define NVIC_DBG_DATA_R         (*((volatile uint32_t *)0xE000EDF8))
#define NVIC_DBG_INT_R          (*((volatile uint32_t *)0xE000EDFC))
#define NVIC_SW_TRIG_R          (*((volatile uint32_t *)0xE000EF00))
#define NVIC_FPCC_R             (*((volatile uint32_t *)0xE000EF34))
#define NVIC_FPCA_R             (*((volatile uint32_t *)0xE000EF38))
#define NVIC_FPDSC_R            (*((volatile uint32_t *)0xE000EF3C))

//*****************************************************************************
//
// The following are defines for the bit fields in the WDT_O_LOAD register.
//
//*****************************************************************************
#define WDT_LOAD_M              0xFFFFFFFF  // Watchdog Load Value
#define WDT_LOAD_S              0

//*****************************************************************************
//
// The following are defines for the bit fields in the WDT_O_VALUE register.
//
//*****************************************************************************
#define WDT_VALUE_M             0xFFFFFFFF  // Watchdog Value
#define WDT_VALUE_S             0

//*****************************************************************************
//
// The following are defines for the bit fields in the WDT_O_CTL register.
//
//*****************************************************************************
#define WDT_CTL_WRC             0x80000000  // Write Complete
#define WDT_CTL_INTTYPE         0x00000004  // Watchdog Interrupt Type
#define WDT_CTL_RESEN           0x00000002  // Watchdog Reset Enable
#define WDT_CTL_INTEN           0x00000001  // Watchdog Interrupt Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the WDT_O_ICR register.
//
//*****************************************************************************
#define WDT_ICR_M               0xFFFFFFFF  // Watchdog Interrupt Clear
#define WDT_ICR_S               0

//*****************************************************************************
//
// The following are defines for the bit fields in the WDT_O_RIS register.
//
//*****************************************************************************
#define WDT_RIS_WDTRIS          0x00000001  // Watchdog Raw Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the WDT_O_MIS register.
//
//*****************************************************************************
#define WDT_MIS_WDTMIS          0x00000001  // Watchdog Masked Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the WDT_O_TEST register.
//
//*****************************************************************************
#define WDT_TEST_STALL          0x00000100  // Watchdog Stall Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the WDT_O_LOCK register.
//
//*****************************************************************************
#define WDT_LOCK_M              0xFFFFFFFF  // Watchdog Lock
#define WDT_LOCK_UNLOCKED       0x00000000  // Unlocked
#define WDT_LOCK_LOCKED         0x00000001  // Locked
#define WDT_LOCK_UNLOCK         0x1ACCE551  // Unlocks the watchdog timer

//*****************************************************************************
//
// The following are defines for the bit fields in the SSI_O_CR0 register.
//
//*****************************************************************************
#define SSI_CR0_SCR_M           0x0000FF00  // SSI Serial Clock Rate
#define SSI_CR0_SPH             0x00000080  // SSI Serial Clock Phase
#define SSI_CR0_SPO             0x00000040  // SSI Serial Clock Polarity
#define SSI_CR0_FRF_M           0x00000030  // SSI Frame Format Select
#define SSI_CR0_FRF_MOTO        0x00000000  // Freescale SPI Frame Format
#define SSI_CR0_FRF_TI          0x00000010  // Texas Instruments Synchronous
                                            // Serial Frame Format
#define SSI_CR0_DSS_M           0x0000000F  // SSI Data Size Select
#define SSI_CR0_DSS_4           0x00000003  // 4-bit data
#define SSI_CR0_DSS_5           0x00000004  // 5-bit data
#define SSI_CR0_DSS_6           0x00000005  // 6-bit data
#define SSI_CR0_DSS_7           0x00000006  // 7-bit data
#define SSI_CR0_DSS_8           0x00000007  // 8-bit data
#define SSI_CR0_DSS_9           0x00000008  // 9-bit data
#define SSI_CR0_DSS_10          0x00000009  // 10-bit data
#define SSI_CR0_DSS_11          0x0000000A  // 11-bit data
#define SSI_CR0_DSS_12          0x0000000B  // 12-bit data
#define SSI_CR0_DSS_13          0x0000000C  // 13-bit data
#define SSI_CR0_DSS_14          0x0000000D  // 14-bit data
#define SSI_CR0_DSS_15          0x0000000E  // 15-bit data
#define SSI_CR0_DSS_16          0x0000000F  // 16-bit data
#define SSI_CR0_SCR_S           8

//*****************************************************************************
//
// The following are defines for the bit fields in the SSI_O_CR1 register.
//
//*****************************************************************************
#define SSI_CR1_EOM             0x00000800  // Stop Frame (End of Message)
#define SSI_CR1_FSSHLDFRM       0x00000400  // FSS Hold Frame
#define SSI_CR1_HSCLKEN         0x00000200  // High Speed Clock Enable
#define SSI_CR1_DIR             0x00000100  // SSI Direction of Operation
#define SSI_CR1_MODE_M          0x000000C0  // SSI Mode
#define SSI_CR1_MODE_LEGACY     0x00000000  // Legacy SSI mode
#define SSI_CR1_MODE_BI         0x00000040  // Bi-SSI mode
#define SSI_CR1_MODE_QUAD       0x00000080  // Quad-SSI Mode
#define SSI_CR1_MODE_ADVANCED   0x000000C0  // Advanced SSI Mode
#define SSI_CR1_EOT             0x00000010  // End of Transmission
#define SSI_CR1_SOD             0x00000008  // SSI Slave Mode Output Disable
#define SSI_CR1_MS              0x00000004  // SSI Master/Slave Select
#define SSI_CR1_SSE             0x00000002  // SSI Synchronous Serial Port
                                            // Enable
#define SSI_CR1_LBM             0x00000001  // SSI Loopback Mode

//*****************************************************************************
//
// The following are defines for the bit fields in the SSI_O_DR register.
//
//*****************************************************************************
#define SSI_DR_DATA_M           0x0000FFFF  // SSI Receive/Transmit Data
#define SSI_DR_DATA_S           0

//*****************************************************************************
//
// The following are defines for the bit fields in the SSI_O_SR register.
//
//*****************************************************************************
#define SSI_SR_BSY              0x00000010  // SSI Busy Bit
#define SSI_SR_RFF              0x00000008  // SSI Receive FIFO Full
#define SSI_SR_RNE              0x00000004  // SSI Receive FIFO Not Empty
#define SSI_SR_TNF              0x00000002  // SSI Transmit FIFO Not Full
#define SSI_SR_TFE              0x00000001  // SSI Transmit FIFO Empty

//*****************************************************************************
//
// The following are defines for the bit fields in the SSI_O_CPSR register.
//
//*****************************************************************************
#define SSI_CPSR_CPSDVSR_M      0x000000FF  // SSI Clock Prescale Divisor
#define SSI_CPSR_CPSDVSR_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the SSI_O_IM register.
//
//*****************************************************************************
#define SSI_IM_EOTIM            0x00000040  // End of Transmit Interrupt Mask
#define SSI_IM_DMATXIM          0x00000020  // SSI Transmit DMA Interrupt Mask
#define SSI_IM_DMARXIM          0x00000010  // SSI Receive DMA Interrupt Mask
#define SSI_IM_TXIM             0x00000008  // SSI Transmit FIFO Interrupt Mask
#define SSI_IM_RXIM             0x00000004  // SSI Receive FIFO Interrupt Mask
#define SSI_IM_RTIM             0x00000002  // SSI Receive Time-Out Interrupt
                                            // Mask
#define SSI_IM_RORIM            0x00000001  // SSI Receive Overrun Interrupt
                                            // Mask

//*****************************************************************************
//
// The following are defines for the bit fields in the SSI_O_RIS register.
//
//*****************************************************************************
#define SSI_RIS_EOTRIS          0x00000040  // End of Transmit Raw Interrupt
                                            // Status
#define SSI_RIS_DMATXRIS        0x00000020  // SSI Transmit DMA Raw Interrupt
                                            // Status
#define SSI_RIS_DMARXRIS        0x00000010  // SSI Receive DMA Raw Interrupt
                                            // Status
#define SSI_RIS_TXRIS           0x00000008  // SSI Transmit FIFO Raw Interrupt
                                            // Status
#define SSI_RIS_RXRIS           0x00000004  // SSI Receive FIFO Raw Interrupt
                                            // Status
#define SSI_RIS_RTRIS           0x00000002  // SSI Receive Time-Out Raw
                                            // Interrupt Status
#define SSI_RIS_RORRIS          0x00000001  // SSI Receive Overrun Raw
                                            // Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the SSI_O_MIS register.
//
//*****************************************************************************
#define SSI_MIS_EOTMIS          0x00000040  // End of Transmit Masked Interrupt
                                            // Status
#define SSI_MIS_DMATXMIS        0x00000020  // SSI Transmit DMA Masked
                                            // Interrupt Status
#define SSI_MIS_DMARXMIS        0x00000010  // SSI Receive DMA Masked Interrupt
                                            // Status
#define SSI_MIS_TXMIS           0x00000008  // SSI Transmit FIFO Masked
                                            // Interrupt Status
#define SSI_MIS_RXMIS           0x00000004  // SSI Receive FIFO Masked
                                            // Interrupt Status
#define SSI_MIS_RTMIS           0x00000002  // SSI Receive Time-Out Masked
                                            // Interrupt Status
#define SSI_MIS_RORMIS          0x00000001  // SSI Receive Overrun Masked
                                            // Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the SSI_O_ICR register.
//
//*****************************************************************************
#define SSI_ICR_EOTIC           0x00000040  // End of Transmit Interrupt Clear
#define SSI_ICR_DMATXIC         0x00000020  // SSI Transmit DMA Interrupt Clear
#define SSI_ICR_DMARXIC         0x00000010  // SSI Receive DMA Interrupt Clear
#define SSI_ICR_RTIC            0x00000002  // SSI Receive Time-Out Interrupt
                                            // Clear
#define SSI_ICR_RORIC           0x00000001  // SSI Receive Overrun Interrupt
                                            // Clear

//*****************************************************************************
//
// The following are defines for the bit fields in the SSI_O_DMACTL register.
//
//*****************************************************************************
#define SSI_DMACTL_TXDMAE       0x00000002  // Transmit DMA Enable
#define SSI_DMACTL_RXDMAE       0x00000001  // Receive DMA Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the SSI_O_PP register.
//
//*****************************************************************************
#define SSI_PP_FSSHLDFRM        0x00000008  // FSS Hold Frame Capability
#define SSI_PP_MODE_M           0x00000006  // Mode of Operation
#define SSI_PP_MODE_LEGACY      0x00000000  // Legacy SSI mode
#define SSI_PP_MODE_ADVBI       0x00000002  // Advanced SSI and Bi-SSI
#define SSI_PP_MODE_ADVBIQUAD   0x00000004  // Advanced, Bi- and Quad-SSI
#define SSI_PP_HSCLK            0x00000001  // High Speed Capability

//*****************************************************************************
//
// The following are defines for the bit fields in the SSI_O_CC register.
//
//*****************************************************************************
#define SSI_CC_CS_M             0x0000000F  // SSI Baud Clock Source
#define SSI_CC_CS_SYSPLL        0x00000000  // Either the system clock (if the
                                            // PLL bypass is in effect) or the
                                            // PLL output (default)
#define SSI_CC_CS_PIOSC         0x00000005  // PIOSC

//*****************************************************************************
//
// The following are defines for the bit fields in the UART_O_DR register.
//
//*****************************************************************************
#define UART_DR_OE              0x00000800  // UART Overrun Error
#define UART_DR_BE              0x00000400  // UART Break Error
#define UART_DR_PE              0x00000200  // UART Parity Error
#define UART_DR_FE              0x00000100  // UART Framing Error
#define UART_DR_DATA_M          0x000000FF  // Data Transmitted or Received
#define UART_DR_DATA_S          0

//*****************************************************************************
//
// The following are defines for the bit fields in the UART_O_RSR register.
//
//*****************************************************************************
#define UART_RSR_OE             0x00000008  // UART Overrun Error
#define UART_RSR_BE             0x00000004  // UART Break Error
#define UART_RSR_PE             0x00000002  // UART Parity Error
#define UART_RSR_FE             0x00000001  // UART Framing Error

//*****************************************************************************
//
// The following are defines for the bit fields in the UART_O_ECR register.
//
//*****************************************************************************
#define UART_ECR_DATA_M         0x000000FF  // Error Clear
#define UART_ECR_DATA_S         0

//*****************************************************************************
//
// The following are defines for the bit fields in the UART_O_FR register.
//
//*****************************************************************************
#define UART_FR_RI              0x00000100  // Ring Indicator
#define UART_FR_TXFE            0x00000080  // UART Transmit FIFO Empty
#define UART_FR_RXFF            0x00000040  // UART Receive FIFO Full
#define UART_FR_TXFF            0x00000020  // UART Transmit FIFO Full
#define UART_FR_RXFE            0x00000010  // UART Receive FIFO Empty
#define UART_FR_BUSY            0x00000008  // UART Busy
#define UART_FR_DCD             0x00000004  // Data Carrier Detect
#define UART_FR_DSR             0x00000002  // Data Set Ready
#define UART_FR_CTS             0x00000001  // Clear To Send

//*****************************************************************************
//
// The following are defines for the bit fields in the UART_O_ILPR register.
//
//*****************************************************************************
#define UART_ILPR_ILPDVSR_M     0x000000FF  // IrDA Low-Power Divisor
#define UART_ILPR_ILPDVSR_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the UART_O_IBRD register.
//
//*****************************************************************************
#define UART_IBRD_DIVINT_M      0x0000FFFF  // Integer Baud-Rate Divisor
#define UART_IBRD_DIVINT_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the UART_O_FBRD register.
//
//*****************************************************************************
#define UART_FBRD_DIVFRAC_M     0x0000003F  // Fractional Baud-Rate Divisor
#define UART_FBRD_DIVFRAC_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the UART_O_LCRH register.
//
//*****************************************************************************
#define UART_LCRH_SPS           0x00000080  // UART Stick Parity Select
#define UART_LCRH_WLEN_M        0x00000060  // UART Word Length
#define UART_LCRH_WLEN_5        0x00000000  // 5 bits (default)
#define UART_LCRH_WLEN_6        0x00000020  // 6 bits
#define UART_LCRH_WLEN_7        0x00000040  // 7 bits
#define UART_LCRH_WLEN_8        0x00000060  // 8 bits
#define UART_LCRH_FEN           0x00000010  // UART Enable FIFOs
#define UART_LCRH_STP2          0x00000008  // UART Two Stop Bits Select
#define UART_LCRH_EPS           0x00000004  // UART Even Parity Select
#define UART_LCRH_PEN           0x00000002  // UART Parity Enable
#define UART_LCRH_BRK           0x00000001  // UART Send Break

//*****************************************************************************
//
// The following are defines for the bit fields in the UART_O_CTL register.
//
//*****************************************************************************
#define UART_CTL_CTSEN          0x00008000  // Enable Clear To Send
#define UART_CTL_RTSEN          0x00004000  // Enable Request to Send
#define UART_CTL_RTS            0x00000800  // Request to Send
#define UART_CTL_DTR            0x00000400  // Data Terminal Ready
#define UART_CTL_RXE            0x00000200  // UART Receive Enable
#define UART_CTL_TXE            0x00000100  // UART Transmit Enable
#define UART_CTL_LBE            0x00000080  // UART Loop Back Enable
#define UART_CTL_HSE            0x00000020  // High-Speed Enable
#define UART_CTL_EOT            0x00000010  // End of Transmission
#define UART_CTL_SMART          0x00000008  // ISO 7816 Smart Card Support
#define UART_CTL_SIRLP          0x00000004  // UART SIR Low-Power Mode
#define UART_CTL_SIREN          0x00000002  // UART SIR Enable
#define UART_CTL_UARTEN         0x00000001  // UART Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the UART_O_IFLS register.
//
//*****************************************************************************
#define UART_IFLS_RX_M          0x00000038  // UART Receive Interrupt FIFO
                                            // Level Select
#define UART_IFLS_RX1_8         0x00000000  // RX FIFO >= 1/8 full
#define UART_IFLS_RX2_8         0x00000008  // RX FIFO >= 1/4 full
#define UART_IFLS_RX4_8         0x00000010  // RX FIFO >= 1/2 full (default)
#define UART_IFLS_RX6_8         0x00000018  // RX FIFO >= 3/4 full
#define UART_IFLS_RX7_8         0x00000020  // RX FIFO >= 7/8 full
#define UART_IFLS_TX_M          0x00000007  // UART Transmit Interrupt FIFO
                                            // Level Select
#define UART_IFLS_TX1_8         0x00000000  // TX FIFO <= 1/8 full
#define UART_IFLS_TX2_8         0x00000001  // TX FIFO <= 1/4 full
#define UART_IFLS_TX4_8         0x00000002  // TX FIFO <= 1/2 full (default)
#define UART_IFLS_TX6_8         0x00000003  // TX FIFO <= 3/4 full
#define UART_IFLS_TX7_8         0x00000004  // TX FIFO <= 7/8 full

//*****************************************************************************
//
// The following are defines for the bit fields in the UART_O_IM register.
//
//*****************************************************************************
#define UART_IM_DMATXIM         0x00020000  // Transmit DMA Interrupt Mask
#define UART_IM_DMARXIM         0x00010000  // Receive DMA Interrupt Mask
#define UART_IM_9BITIM          0x00001000  // 9-Bit Mode Interrupt Mask
#define UART_IM_EOTIM           0x00000800  // End of Transmission Interrupt
                                            // Mask
#define UART_IM_OEIM            0x00000400  // UART Overrun Error Interrupt
                                            // Mask
#define UART_IM_BEIM            0x00000200  // UART Break Error Interrupt Mask
#define UART_IM_PEIM            0x00000100  // UART Parity Error Interrupt Mask
#define UART_IM_FEIM            0x00000080  // UART Framing Error Interrupt
                                            // Mask
#define UART_IM_RTIM            0x00000040  // UART Receive Time-Out Interrupt
                                            // Mask
#define UART_IM_TXIM            0x00000020  // UART Transmit Interrupt Mask
#define UART_IM_RXIM            0x00000010  // UART Receive Interrupt Mask
#define UART_IM_DSRMIM          0x00000008  // UART Data Set Ready Modem
                                            // Interrupt Mask
#define UART_IM_DCDMIM          0x00000004  // UART Data Carrier Detect Modem
                                            // Interrupt Mask
#define UART_IM_CTSMIM          0x00000002  // UART Clear to Send Modem
                                            // Interrupt Mask
#define UART_IM_RIMIM           0x00000001  // UART Ring Indicator Modem
                                            // Interrupt Mask

//*****************************************************************************
//
// The following are defines for the bit fields in the UART_O_RIS register.
//
//*****************************************************************************
#define UART_RIS_DMATXRIS       0x00020000  // Transmit DMA Raw Interrupt
                                            // Status
#define UART_RIS_DMARXRIS       0x00010000  // Receive DMA Raw Interrupt Status
#define UART_RIS_9BITRIS        0x00001000  // 9-Bit Mode Raw Interrupt Status
#define UART_RIS_EOTRIS         0x00000800  // End of Transmission Raw
                                            // Interrupt Status
#define UART_RIS_OERIS          0x00000400  // UART Overrun Error Raw Interrupt
                                            // Status
#define UART_RIS_BERIS          0x00000200  // UART Break Error Raw Interrupt
                                            // Status
#define UART_RIS_PERIS          0x00000100  // UART Parity Error Raw Interrupt
                                            // Status
#define UART_RIS_FERIS          0x00000080  // UART Framing Error Raw Interrupt
                                            // Status
#define UART_RIS_RTRIS          0x00000040  // UART Receive Time-Out Raw
                                            // Interrupt Status
#define UART_RIS_TXRIS          0x00000020  // UART Transmit Raw Interrupt
                                            // Status
#define UART_RIS_RXRIS          0x00000010  // UART Receive Raw Interrupt
                                            // Status
#define UART_RIS_DSRRIS         0x00000008  // UART Data Set Ready Modem Raw
                                            // Interrupt Status
#define UART_RIS_DCDRIS         0x00000004  // UART Data Carrier Detect Modem
                                            // Raw Interrupt Status
#define UART_RIS_CTSRIS         0x00000002  // UART Clear to Send Modem Raw
                                            // Interrupt Status
#define UART_RIS_RIRIS          0x00000001  // UART Ring Indicator Modem Raw
                                            // Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the UART_O_MIS register.
//
//*****************************************************************************
#define UART_MIS_DMATXMIS       0x00020000  // Transmit DMA Masked Interrupt
                                            // Status
#define UART_MIS_DMARXMIS       0x00010000  // Receive DMA Masked Interrupt
                                            // Status
#define UART_MIS_9BITMIS        0x00001000  // 9-Bit Mode Masked Interrupt
                                            // Status
#define UART_MIS_EOTMIS         0x00000800  // End of Transmission Masked
                                            // Interrupt Status
#define UART_MIS_OEMIS          0x00000400  // UART Overrun Error Masked
                                            // Interrupt Status
#define UART_MIS_BEMIS          0x00000200  // UART Break Error Masked
                                            // Interrupt Status
#define UART_MIS_PEMIS          0x00000100  // UART Parity Error Masked
                                            // Interrupt Status
#define UART_MIS_FEMIS          0x00000080  // UART Framing Error Masked
                                            // Interrupt Status
#define UART_MIS_RTMIS          0x00000040  // UART Receive Time-Out Masked
                                            // Interrupt Status
#define UART_MIS_TXMIS          0x00000020  // UART Transmit Masked Interrupt
                                            // Status
#define UART_MIS_RXMIS          0x00000010  // UART Receive Masked Interrupt
                                            // Status
#define UART_MIS_DSRMIS         0x00000008  // UART Data Set Ready Modem Masked
                                            // Interrupt Status
#define UART_MIS_DCDMIS         0x00000004  // UART Data Carrier Detect Modem
                                            // Masked Interrupt Status
#define UART_MIS_CTSMIS         0x00000002  // UART Clear to Send Modem Masked
                                            // Interrupt Status
#define UART_MIS_RIMIS          0x00000001  // UART Ring Indicator Modem Masked
                                            // Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the UART_O_ICR register.
//
//*****************************************************************************
#define UART_ICR_DMATXIC        0x00020000  // Transmit DMA Interrupt Clear
#define UART_ICR_DMARXIC        0x00010000  // Receive DMA Interrupt Clear
#define UART_ICR_9BITIC         0x00001000  // 9-Bit Mode Interrupt Clear
#define UART_ICR_EOTIC          0x00000800  // End of Transmission Interrupt
                                            // Clear
#define UART_ICR_OEIC           0x00000400  // Overrun Error Interrupt Clear
#define UART_ICR_BEIC           0x00000200  // Break Error Interrupt Clear
#define UART_ICR_PEIC           0x00000100  // Parity Error Interrupt Clear
#define UART_ICR_FEIC           0x00000080  // Framing Error Interrupt Clear
#define UART_ICR_RTIC           0x00000040  // Receive Time-Out Interrupt Clear
#define UART_ICR_TXIC           0x00000020  // Transmit Interrupt Clear
#define UART_ICR_RXIC           0x00000010  // Receive Interrupt Clear
#define UART_ICR_DSRMIC         0x00000008  // UART Data Set Ready Modem
                                            // Interrupt Clear
#define UART_ICR_DCDMIC         0x00000004  // UART Data Carrier Detect Modem
                                            // Interrupt Clear
#define UART_ICR_CTSMIC         0x00000002  // UART Clear to Send Modem
                                            // Interrupt Clear
#define UART_ICR_RIMIC          0x00000001  // UART Ring Indicator Modem
                                            // Interrupt Clear

//*****************************************************************************
//
// The following are defines for the bit fields in the UART_O_DMACTL register.
//
//*****************************************************************************
#define UART_DMACTL_DMAERR      0x00000004  // DMA on Error
#define UART_DMACTL_TXDMAE      0x00000002  // Transmit DMA Enable
#define UART_DMACTL_RXDMAE      0x00000001  // Receive DMA Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the UART_O_9BITADDR
// register.
//
//*****************************************************************************
#define UART_9BITADDR_9BITEN    0x00008000  // Enable 9-Bit Mode
#define UART_9BITADDR_ADDR_M    0x000000FF  // Self Address for 9-Bit Mode
#define UART_9BITADDR_ADDR_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the UART_O_9BITAMASK
// register.
//
//*****************************************************************************
#define UART_9BITAMASK_MASK_M   0x000000FF  // Self Address Mask for 9-Bit Mode
#define UART_9BITAMASK_MASK_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the UART_O_PP register.
//
//*****************************************************************************
#define UART_PP_MSE             0x00000008  // Modem Support Extended
#define UART_PP_MS              0x00000004  // Modem Support
#define UART_PP_NB              0x00000002  // 9-Bit Support
#define UART_PP_SC              0x00000001  // Smart Card Support

//*****************************************************************************
//
// The following are defines for the bit fields in the UART_O_CC register.
//
//*****************************************************************************
#define UART_CC_CS_M            0x0000000F  // UART Baud Clock Source
#define UART_CC_CS_SYSCLK       0x00000000  // The system clock (default)
#define UART_CC_CS_PIOSC        0x00000005  // PIOSC

//*****************************************************************************
//
// The following are defines for the bit fields in the I2C_O_MSA register.
//
//*****************************************************************************
#define I2C_MSA_SA_M            0x000000FE  // I2C Slave Address
#define I2C_MSA_RS              0x00000001  // Receive not send
#define I2C_MSA_SA_S            1

//*****************************************************************************
//
// The following are defines for the bit fields in the I2C_O_MCS register.
//
//*****************************************************************************
#define I2C_MCS_ACTDMARX        0x80000000  // DMA RX Active Status
#define I2C_MCS_ACTDMATX        0x40000000  // DMA TX Active Status
#define I2C_MCS_CLKTO           0x00000080  // Clock Timeout Error
#define I2C_MCS_BURST           0x00000040  // Burst Enable
#define I2C_MCS_BUSBSY          0x00000040  // Bus Busy
#define I2C_MCS_IDLE            0x00000020  // I2C Idle
#define I2C_MCS_QCMD            0x00000020  // Quick Command
#define I2C_MCS_ARBLST          0x00000010  // Arbitration Lost
#define I2C_MCS_HS              0x00000010  // High-Speed Enable
#define I2C_MCS_ACK             0x00000008  // Data Acknowledge Enable
#define I2C_MCS_DATACK          0x00000008  // Acknowledge Data
#define I2C_MCS_ADRACK          0x00000004  // Acknowledge Address
#define I2C_MCS_STOP            0x00000004  // Generate STOP
#define I2C_MCS_ERROR           0x00000002  // Error
#define I2C_MCS_START           0x00000002  // Generate START
#define I2C_MCS_RUN             0x00000001  // I2C Master Enable
#define I2C_MCS_BUSY            0x00000001  // I2C Busy

//*****************************************************************************
//
// The following are defines for the bit fields in the I2C_O_MDR register.
//
//*****************************************************************************
#define I2C_MDR_DATA_M          0x000000FF  // Data Transferred
#define I2C_MDR_DATA_S          0

//*****************************************************************************
//
// The following are defines for the bit fields in the I2C_O_MTPR register.
//
//*****************************************************************************
#define I2C_MTPR_PULSEL_M       0x00070000  // Glitch Suppression Pulse Width
#define I2C_MTPR_PULSEL_BYPASS  0x00000000  // Bypass
#define I2C_MTPR_PULSEL_1       0x00010000  // 1 clock
#define I2C_MTPR_PULSEL_2       0x00020000  // 2 clocks
#define I2C_MTPR_PULSEL_3       0x00030000  // 3 clocks
#define I2C_MTPR_PULSEL_4       0x00040000  // 4 clocks
#define I2C_MTPR_PULSEL_8       0x00050000  // 8 clocks
#define I2C_MTPR_PULSEL_16      0x00060000  // 16 clocks
#define I2C_MTPR_PULSEL_32      0x00070000  // 32 clocks
#define I2C_MTPR_HS             0x00000080  // High-Speed Enable
#define I2C_MTPR_TPR_M          0x0000007F  // Timer Period
#define I2C_MTPR_TPR_S          0

//*****************************************************************************
//
// The following are defines for the bit fields in the I2C_O_MIMR register.
//
//*****************************************************************************
#define I2C_MIMR_RXFFIM         0x00000800  // Receive FIFO Full Interrupt Mask
#define I2C_MIMR_TXFEIM         0x00000400  // Transmit FIFO Empty Interrupt
                                            // Mask
#define I2C_MIMR_RXIM           0x00000200  // Receive FIFO Request Interrupt
                                            // Mask
#define I2C_MIMR_TXIM           0x00000100  // Transmit FIFO Request Interrupt
                                            // Mask
#define I2C_MIMR_ARBLOSTIM      0x00000080  // Arbitration Lost Interrupt Mask
#define I2C_MIMR_STOPIM         0x00000040  // STOP Detection Interrupt Mask
#define I2C_MIMR_STARTIM        0x00000020  // START Detection Interrupt Mask
#define I2C_MIMR_NACKIM         0x00000010  // Address/Data NACK Interrupt Mask
#define I2C_MIMR_DMATXIM        0x00000008  // Transmit DMA Interrupt Mask
#define I2C_MIMR_DMARXIM        0x00000004  // Receive DMA Interrupt Mask
#define I2C_MIMR_CLKIM          0x00000002  // Clock Timeout Interrupt Mask
#define I2C_MIMR_IM             0x00000001  // Master Interrupt Mask

//*****************************************************************************
//
// The following are defines for the bit fields in the I2C_O_MRIS register.
//
//*****************************************************************************
#define I2C_MRIS_RXFFRIS        0x00000800  // Receive FIFO Full Raw Interrupt
                                            // Status
#define I2C_MRIS_TXFERIS        0x00000400  // Transmit FIFO Empty Raw
                                            // Interrupt Status
#define I2C_MRIS_RXRIS          0x00000200  // Receive FIFO Request Raw
                                            // Interrupt Status
#define I2C_MRIS_TXRIS          0x00000100  // Transmit Request Raw Interrupt
                                            // Status
#define I2C_MRIS_ARBLOSTRIS     0x00000080  // Arbitration Lost Raw Interrupt
                                            // Status
#define I2C_MRIS_STOPRIS        0x00000040  // STOP Detection Raw Interrupt
                                            // Status
#define I2C_MRIS_STARTRIS       0x00000020  // START Detection Raw Interrupt
                                            // Status
#define I2C_MRIS_NACKRIS        0x00000010  // Address/Data NACK Raw Interrupt
                                            // Status
#define I2C_MRIS_DMATXRIS       0x00000008  // Transmit DMA Raw Interrupt
                                            // Status
#define I2C_MRIS_DMARXRIS       0x00000004  // Receive DMA Raw Interrupt Status
#define I2C_MRIS_CLKRIS         0x00000002  // Clock Timeout Raw Interrupt
                                            // Status
#define I2C_MRIS_RIS            0x00000001  // Master Raw Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the I2C_O_MMIS register.
//
//*****************************************************************************
#define I2C_MMIS_RXFFMIS        0x00000800  // Receive FIFO Full Interrupt Mask
#define I2C_MMIS_TXFEMIS        0x00000400  // Transmit FIFO Empty Interrupt
                                            // Mask
#define I2C_MMIS_RXMIS          0x00000200  // Receive FIFO Request Interrupt
                                            // Mask
#define I2C_MMIS_TXMIS          0x00000100  // Transmit Request Interrupt Mask
#define I2C_MMIS_ARBLOSTMIS     0x00000080  // Arbitration Lost Interrupt Mask
#define I2C_MMIS_STOPMIS        0x00000040  // STOP Detection Interrupt Mask
#define I2C_MMIS_STARTMIS       0x00000020  // START Detection Interrupt Mask
#define I2C_MMIS_NACKMIS        0x00000010  // Address/Data NACK Interrupt Mask
#define I2C_MMIS_DMATXMIS       0x00000008  // Transmit DMA Interrupt Status
#define I2C_MMIS_DMARXMIS       0x00000004  // Receive DMA Interrupt Status
#define I2C_MMIS_CLKMIS         0x00000002  // Clock Timeout Masked Interrupt
                                            // Status
#define I2C_MMIS_MIS            0x00000001  // Masked Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the I2C_O_MICR register.
//
//*****************************************************************************
#define I2C_MICR_RXFFIC         0x00000800  // Receive FIFO Full Interrupt
                                            // Clear
#define I2C_MICR_TXFEIC         0x00000400  // Transmit FIFO Empty Interrupt
                                            // Clear
#define I2C_MICR_RXIC           0x00000200  // Receive FIFO Request Interrupt
                                            // Clear
#define I2C_MICR_TXIC           0x00000100  // Transmit FIFO Request Interrupt
                                            // Clear
#define I2C_MICR_ARBLOSTIC      0x00000080  // Arbitration Lost Interrupt Clear
#define I2C_MICR_STOPIC         0x00000040  // STOP Detection Interrupt Clear
#define I2C_MICR_STARTIC        0x00000020  // START Detection Interrupt Clear
#define I2C_MICR_NACKIC         0x00000010  // Address/Data NACK Interrupt
                                            // Clear
#define I2C_MICR_DMATXIC        0x00000008  // Transmit DMA Interrupt Clear
#define I2C_MICR_DMARXIC        0x00000004  // Receive DMA Interrupt Clear
#define I2C_MICR_CLKIC          0x00000002  // Clock Timeout Interrupt Clear
#define I2C_MICR_IC             0x00000001  // Master Interrupt Clear

//*****************************************************************************
//
// The following are defines for the bit fields in the I2C_O_MCR register.
//
//*****************************************************************************
#define I2C_MCR_SFE             0x00000020  // I2C Slave Function Enable
#define I2C_MCR_MFE             0x00000010  // I2C Master Function Enable
#define I2C_MCR_LPBK            0x00000001  // I2C Loopback

//*****************************************************************************
//
// The following are defines for the bit fields in the I2C_O_MCLKOCNT register.
//
//*****************************************************************************
#define I2C_MCLKOCNT_CNTL_M     0x000000FF  // I2C Master Count
#define I2C_MCLKOCNT_CNTL_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the I2C_O_MBMON register.
//
//*****************************************************************************
#define I2C_MBMON_SDA           0x00000002  // I2C SDA Status
#define I2C_MBMON_SCL           0x00000001  // I2C SCL Status

//*****************************************************************************
//
// The following are defines for the bit fields in the I2C_O_MBLEN register.
//
//*****************************************************************************
#define I2C_MBLEN_CNTL_M        0x000000FF  // I2C Burst Length
#define I2C_MBLEN_CNTL_S        0

//*****************************************************************************
//
// The following are defines for the bit fields in the I2C_O_MBCNT register.
//
//*****************************************************************************
#define I2C_MBCNT_CNTL_M        0x000000FF  // I2C Master Burst Count
#define I2C_MBCNT_CNTL_S        0

//*****************************************************************************
//
// The following are defines for the bit fields in the I2C_O_SOAR register.
//
//*****************************************************************************
#define I2C_SOAR_OAR_M          0x0000007F  // I2C Slave Own Address
#define I2C_SOAR_OAR_S          0

//*****************************************************************************
//
// The following are defines for the bit fields in the I2C_O_SCSR register.
//
//*****************************************************************************
#define I2C_SCSR_ACTDMARX       0x80000000  // DMA RX Active Status
#define I2C_SCSR_ACTDMATX       0x40000000  // DMA TX Active Status
#define I2C_SCSR_QCMDRW         0x00000020  // Quick Command Read / Write
#define I2C_SCSR_QCMDST         0x00000010  // Quick Command Status
#define I2C_SCSR_OAR2SEL        0x00000008  // OAR2 Address Matched
#define I2C_SCSR_FBR            0x00000004  // First Byte Received
#define I2C_SCSR_RXFIFO         0x00000004  // RX FIFO Enable
#define I2C_SCSR_TXFIFO         0x00000002  // TX FIFO Enable
#define I2C_SCSR_TREQ           0x00000002  // Transmit Request
#define I2C_SCSR_DA             0x00000001  // Device Active
#define I2C_SCSR_RREQ           0x00000001  // Receive Request

//*****************************************************************************
//
// The following are defines for the bit fields in the I2C_O_SDR register.
//
//*****************************************************************************
#define I2C_SDR_DATA_M          0x000000FF  // Data for Transfer
#define I2C_SDR_DATA_S          0

//*****************************************************************************
//
// The following are defines for the bit fields in the I2C_O_SIMR register.
//
//*****************************************************************************
#define I2C_SIMR_RXFFIM         0x00000100  // Receive FIFO Full Interrupt Mask
#define I2C_SIMR_TXFEIM         0x00000080  // Transmit FIFO Empty Interrupt
                                            // Mask
#define I2C_SIMR_RXIM           0x00000040  // Receive FIFO Request Interrupt
                                            // Mask
#define I2C_SIMR_TXIM           0x00000020  // Transmit FIFO Request Interrupt
                                            // Mask
#define I2C_SIMR_DMATXIM        0x00000010  // Transmit DMA Interrupt Mask
#define I2C_SIMR_DMARXIM        0x00000008  // Receive DMA Interrupt Mask
#define I2C_SIMR_STOPIM         0x00000004  // Stop Condition Interrupt Mask
#define I2C_SIMR_STARTIM        0x00000002  // Start Condition Interrupt Mask
#define I2C_SIMR_DATAIM         0x00000001  // Data Interrupt Mask

//*****************************************************************************
//
// The following are defines for the bit fields in the I2C_O_SRIS register.
//
//*****************************************************************************
#define I2C_SRIS_RXFFRIS        0x00000100  // Receive FIFO Full Raw Interrupt
                                            // Status
#define I2C_SRIS_TXFERIS        0x00000080  // Transmit FIFO Empty Raw
                                            // Interrupt Status
#define I2C_SRIS_RXRIS          0x00000040  // Receive FIFO Request Raw
                                            // Interrupt Status
#define I2C_SRIS_TXRIS          0x00000020  // Transmit Request Raw Interrupt
                                            // Status
#define I2C_SRIS_DMATXRIS       0x00000010  // Transmit DMA Raw Interrupt
                                            // Status
#define I2C_SRIS_DMARXRIS       0x00000008  // Receive DMA Raw Interrupt Status
#define I2C_SRIS_STOPRIS        0x00000004  // Stop Condition Raw Interrupt
                                            // Status
#define I2C_SRIS_STARTRIS       0x00000002  // Start Condition Raw Interrupt
                                            // Status
#define I2C_SRIS_DATARIS        0x00000001  // Data Raw Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the I2C_O_SMIS register.
//
//*****************************************************************************
#define I2C_SMIS_RXFFMIS        0x00000100  // Receive FIFO Full Interrupt Mask
#define I2C_SMIS_TXFEMIS        0x00000080  // Transmit FIFO Empty Interrupt
                                            // Mask
#define I2C_SMIS_RXMIS          0x00000040  // Receive FIFO Request Interrupt
                                            // Mask
#define I2C_SMIS_TXMIS          0x00000020  // Transmit FIFO Request Interrupt
                                            // Mask
#define I2C_SMIS_DMATXMIS       0x00000010  // Transmit DMA Masked Interrupt
                                            // Status
#define I2C_SMIS_DMARXMIS       0x00000008  // Receive DMA Masked Interrupt
                                            // Status
#define I2C_SMIS_STOPMIS        0x00000004  // Stop Condition Masked Interrupt
                                            // Status
#define I2C_SMIS_STARTMIS       0x00000002  // Start Condition Masked Interrupt
                                            // Status
#define I2C_SMIS_DATAMIS        0x00000001  // Data Masked Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the I2C_O_SICR register.
//
//*****************************************************************************
#define I2C_SICR_RXFFIC         0x00000100  // Receive FIFO Full Interrupt Mask
#define I2C_SICR_TXFEIC         0x00000080  // Transmit FIFO Empty Interrupt
                                            // Mask
#define I2C_SICR_RXIC           0x00000040  // Receive Request Interrupt Mask
#define I2C_SICR_TXIC           0x00000020  // Transmit Request Interrupt Mask
#define I2C_SICR_DMATXIC        0x00000010  // Transmit DMA Interrupt Clear
#define I2C_SICR_DMARXIC        0x00000008  // Receive DMA Interrupt Clear
#define I2C_SICR_STOPIC         0x00000004  // Stop Condition Interrupt Clear
#define I2C_SICR_STARTIC        0x00000002  // Start Condition Interrupt Clear
#define I2C_SICR_DATAIC         0x00000001  // Data Interrupt Clear

//*****************************************************************************
//
// The following are defines for the bit fields in the I2C_O_SOAR2 register.
//
//*****************************************************************************
#define I2C_SOAR2_OAR2EN        0x00000080  // I2C Slave Own Address 2 Enable
#define I2C_SOAR2_OAR2_M        0x0000007F  // I2C Slave Own Address 2
#define I2C_SOAR2_OAR2_S        0

//*****************************************************************************
//
// The following are defines for the bit fields in the I2C_O_SACKCTL register.
//
//*****************************************************************************
#define I2C_SACKCTL_ACKOVAL     0x00000002  // I2C Slave ACK Override Value
#define I2C_SACKCTL_ACKOEN      0x00000001  // I2C Slave ACK Override Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the I2C_O_FIFODATA register.
//
//*****************************************************************************
#define I2C_FIFODATA_DATA_M     0x000000FF  // I2C FIFO Data Byte
#define I2C_FIFODATA_DATA_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the I2C_O_FIFOCTL register.
//
//*****************************************************************************
#define I2C_FIFOCTL_RXASGNMT    0x80000000  // RX Control Assignment
#define I2C_FIFOCTL_RXFLUSH     0x40000000  // RX FIFO Flush
#define I2C_FIFOCTL_DMARXENA    0x20000000  // DMA RX Channel Enable
#define I2C_FIFOCTL_RXTRIG_M    0x00070000  // RX FIFO Trigger
#define I2C_FIFOCTL_TXASGNMT    0x00008000  // TX Control Assignment
#define I2C_FIFOCTL_TXFLUSH     0x00004000  // TX FIFO Flush
#define I2C_FIFOCTL_DMATXENA    0x00002000  // DMA TX Channel Enable
#define I2C_FIFOCTL_TXTRIG_M    0x00000007  // TX FIFO Trigger
#define I2C_FIFOCTL_RXTRIG_S    16
#define I2C_FIFOCTL_TXTRIG_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the I2C_O_FIFOSTATUS
// register.
//
//*****************************************************************************
#define I2C_FIFOSTATUS_RXABVTRIG                                              \
                                0x00040000  // RX FIFO Above Trigger Level
#define I2C_FIFOSTATUS_RXFF     0x00020000  // RX FIFO Full
#define I2C_FIFOSTATUS_RXFE     0x00010000  // RX FIFO Empty
#define I2C_FIFOSTATUS_TXBLWTRIG                                              \
                                0x00000004  // TX FIFO Below Trigger Level
#define I2C_FIFOSTATUS_TXFF     0x00000002  // TX FIFO Full
#define I2C_FIFOSTATUS_TXFE     0x00000001  // TX FIFO Empty

//*****************************************************************************
//
// The following are defines for the bit fields in the I2C_O_PP register.
//
//*****************************************************************************
#define I2C_PP_HS               0x00000001  // High-Speed Capable

//*****************************************************************************
//
// The following are defines for the bit fields in the I2C_O_PC register.
//
//*****************************************************************************
#define I2C_PC_HS               0x00000001  // High-Speed Capable

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_CTL register.
//
//*****************************************************************************
#define PWM_CTL_GLOBALSYNC3     0x00000008  // Update PWM Generator 3
#define PWM_CTL_GLOBALSYNC2     0x00000004  // Update PWM Generator 2
#define PWM_CTL_GLOBALSYNC1     0x00000002  // Update PWM Generator 1
#define PWM_CTL_GLOBALSYNC0     0x00000001  // Update PWM Generator 0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_SYNC register.
//
//*****************************************************************************
#define PWM_SYNC_SYNC3          0x00000008  // Reset Generator 3 Counter
#define PWM_SYNC_SYNC2          0x00000004  // Reset Generator 2 Counter
#define PWM_SYNC_SYNC1          0x00000002  // Reset Generator 1 Counter
#define PWM_SYNC_SYNC0          0x00000001  // Reset Generator 0 Counter

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_ENABLE register.
//
//*****************************************************************************
#define PWM_ENABLE_PWM7EN       0x00000080  // PWM7 Output Enable
#define PWM_ENABLE_PWM6EN       0x00000040  // PWM6 Output Enable
#define PWM_ENABLE_PWM5EN       0x00000020  // PWM5 Output Enable
#define PWM_ENABLE_PWM4EN       0x00000010  // PWM4 Output Enable
#define PWM_ENABLE_PWM3EN       0x00000008  // PWM3 Output Enable
#define PWM_ENABLE_PWM2EN       0x00000004  // PWM2 Output Enable
#define PWM_ENABLE_PWM1EN       0x00000002  // PWM1 Output Enable
#define PWM_ENABLE_PWM0EN       0x00000001  // PWM0 Output Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_INVERT register.
//
//*****************************************************************************
#define PWM_INVERT_PWM7INV      0x00000080  // Invert PWM7 Signal
#define PWM_INVERT_PWM6INV      0x00000040  // Invert PWM6 Signal
#define PWM_INVERT_PWM5INV      0x00000020  // Invert PWM5 Signal
#define PWM_INVERT_PWM4INV      0x00000010  // Invert PWM4 Signal
#define PWM_INVERT_PWM3INV      0x00000008  // Invert PWM3 Signal
#define PWM_INVERT_PWM2INV      0x00000004  // Invert PWM2 Signal
#define PWM_INVERT_PWM1INV      0x00000002  // Invert PWM1 Signal
#define PWM_INVERT_PWM0INV      0x00000001  // Invert PWM0 Signal

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_FAULT register.
//
//*****************************************************************************
#define PWM_FAULT_FAULT7        0x00000080  // PWM7 Fault
#define PWM_FAULT_FAULT6        0x00000040  // PWM6 Fault
#define PWM_FAULT_FAULT5        0x00000020  // PWM5 Fault
#define PWM_FAULT_FAULT4        0x00000010  // PWM4 Fault
#define PWM_FAULT_FAULT3        0x00000008  // PWM3 Fault
#define PWM_FAULT_FAULT2        0x00000004  // PWM2 Fault
#define PWM_FAULT_FAULT1        0x00000002  // PWM1 Fault
#define PWM_FAULT_FAULT0        0x00000001  // PWM0 Fault

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_INTEN register.
//
//*****************************************************************************
#define PWM_INTEN_INTFAULT3     0x00080000  // Interrupt Fault 3
#define PWM_INTEN_INTFAULT2     0x00040000  // Interrupt Fault 2
#define PWM_INTEN_INTFAULT1     0x00020000  // Interrupt Fault 1
#define PWM_INTEN_INTFAULT0     0x00010000  // Interrupt Fault 0
#define PWM_INTEN_INTPWM3       0x00000008  // PWM3 Interrupt Enable
#define PWM_INTEN_INTPWM2       0x00000004  // PWM2 Interrupt Enable
#define PWM_INTEN_INTPWM1       0x00000002  // PWM1 Interrupt Enable
#define PWM_INTEN_INTPWM0       0x00000001  // PWM0 Interrupt Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_RIS register.
//
//*****************************************************************************
#define PWM_RIS_INTFAULT3       0x00080000  // Interrupt Fault PWM 3
#define PWM_RIS_INTFAULT2       0x00040000  // Interrupt Fault PWM 2
#define PWM_RIS_INTFAULT1       0x00020000  // Interrupt Fault PWM 1
#define PWM_RIS_INTFAULT0       0x00010000  // Interrupt Fault PWM 0
#define PWM_RIS_INTPWM3         0x00000008  // PWM3 Interrupt Asserted
#define PWM_RIS_INTPWM2         0x00000004  // PWM2 Interrupt Asserted
#define PWM_RIS_INTPWM1         0x00000002  // PWM1 Interrupt Asserted
#define PWM_RIS_INTPWM0         0x00000001  // PWM0 Interrupt Asserted

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_ISC register.
//
//*****************************************************************************
#define PWM_ISC_INTFAULT3       0x00080000  // FAULT3 Interrupt Asserted
#define PWM_ISC_INTFAULT2       0x00040000  // FAULT2 Interrupt Asserted
#define PWM_ISC_INTFAULT1       0x00020000  // FAULT1 Interrupt Asserted
#define PWM_ISC_INTFAULT0       0x00010000  // FAULT0 Interrupt Asserted
#define PWM_ISC_INTPWM3         0x00000008  // PWM3 Interrupt Status
#define PWM_ISC_INTPWM2         0x00000004  // PWM2 Interrupt Status
#define PWM_ISC_INTPWM1         0x00000002  // PWM1 Interrupt Status
#define PWM_ISC_INTPWM0         0x00000001  // PWM0 Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_STATUS register.
//
//*****************************************************************************
#define PWM_STATUS_FAULT3       0x00000008  // Generator 3 Fault Status
#define PWM_STATUS_FAULT2       0x00000004  // Generator 2 Fault Status
#define PWM_STATUS_FAULT1       0x00000002  // Generator 1 Fault Status
#define PWM_STATUS_FAULT0       0x00000001  // Generator 0 Fault Status

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_FAULTVAL register.
//
//*****************************************************************************
#define PWM_FAULTVAL_PWM7       0x00000080  // PWM7 Fault Value
#define PWM_FAULTVAL_PWM6       0x00000040  // PWM6 Fault Value
#define PWM_FAULTVAL_PWM5       0x00000020  // PWM5 Fault Value
#define PWM_FAULTVAL_PWM4       0x00000010  // PWM4 Fault Value
#define PWM_FAULTVAL_PWM3       0x00000008  // PWM3 Fault Value
#define PWM_FAULTVAL_PWM2       0x00000004  // PWM2 Fault Value
#define PWM_FAULTVAL_PWM1       0x00000002  // PWM1 Fault Value
#define PWM_FAULTVAL_PWM0       0x00000001  // PWM0 Fault Value

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_ENUPD register.
//
//*****************************************************************************
#define PWM_ENUPD_ENUPD7_M      0x0000C000  // PWM7 Enable Update Mode
#define PWM_ENUPD_ENUPD7_IMM    0x00000000  // Immediate
#define PWM_ENUPD_ENUPD7_LSYNC  0x00008000  // Locally Synchronized
#define PWM_ENUPD_ENUPD7_GSYNC  0x0000C000  // Globally Synchronized
#define PWM_ENUPD_ENUPD6_M      0x00003000  // PWM6 Enable Update Mode
#define PWM_ENUPD_ENUPD6_IMM    0x00000000  // Immediate
#define PWM_ENUPD_ENUPD6_LSYNC  0x00002000  // Locally Synchronized
#define PWM_ENUPD_ENUPD6_GSYNC  0x00003000  // Globally Synchronized
#define PWM_ENUPD_ENUPD5_M      0x00000C00  // PWM5 Enable Update Mode
#define PWM_ENUPD_ENUPD5_IMM    0x00000000  // Immediate
#define PWM_ENUPD_ENUPD5_LSYNC  0x00000800  // Locally Synchronized
#define PWM_ENUPD_ENUPD5_GSYNC  0x00000C00  // Globally Synchronized
#define PWM_ENUPD_ENUPD4_M      0x00000300  // PWM4 Enable Update Mode
#define PWM_ENUPD_ENUPD4_IMM    0x00000000  // Immediate
#define PWM_ENUPD_ENUPD4_LSYNC  0x00000200  // Locally Synchronized
#define PWM_ENUPD_ENUPD4_GSYNC  0x00000300  // Globally Synchronized
#define PWM_ENUPD_ENUPD3_M      0x000000C0  // PWM3 Enable Update Mode
#define PWM_ENUPD_ENUPD3_IMM    0x00000000  // Immediate
#define PWM_ENUPD_ENUPD3_LSYNC  0x00000080  // Locally Synchronized
#define PWM_ENUPD_ENUPD3_GSYNC  0x000000C0  // Globally Synchronized
#define PWM_ENUPD_ENUPD2_M      0x00000030  // PWM2 Enable Update Mode
#define PWM_ENUPD_ENUPD2_IMM    0x00000000  // Immediate
#define PWM_ENUPD_ENUPD2_LSYNC  0x00000020  // Locally Synchronized
#define PWM_ENUPD_ENUPD2_GSYNC  0x00000030  // Globally Synchronized
#define PWM_ENUPD_ENUPD1_M      0x0000000C  // PWM1 Enable Update Mode
#define PWM_ENUPD_ENUPD1_IMM    0x00000000  // Immediate
#define PWM_ENUPD_ENUPD1_LSYNC  0x00000008  // Locally Synchronized
#define PWM_ENUPD_ENUPD1_GSYNC  0x0000000C  // Globally Synchronized
#define PWM_ENUPD_ENUPD0_M      0x00000003  // PWM0 Enable Update Mode
#define PWM_ENUPD_ENUPD0_IMM    0x00000000  // Immediate
#define PWM_ENUPD_ENUPD0_LSYNC  0x00000002  // Locally Synchronized
#define PWM_ENUPD_ENUPD0_GSYNC  0x00000003  // Globally Synchronized

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_0_CTL register.
//
//*****************************************************************************
#define PWM_0_CTL_LATCH         0x00040000  // Latch Fault Input
#define PWM_0_CTL_MINFLTPER     0x00020000  // Minimum Fault Period
#define PWM_0_CTL_FLTSRC        0x00010000  // Fault Condition Source
#define PWM_0_CTL_DBFALLUPD_M   0x0000C000  // Specifies the update mode for
                                            // the PWMnDBFALL register
#define PWM_0_CTL_DBFALLUPD_I   0x00000000  // Immediate
#define PWM_0_CTL_DBFALLUPD_LS  0x00008000  // Locally Synchronized
#define PWM_0_CTL_DBFALLUPD_GS  0x0000C000  // Globally Synchronized
#define PWM_0_CTL_DBRISEUPD_M   0x00003000  // PWMnDBRISE Update Mode
#define PWM_0_CTL_DBRISEUPD_I   0x00000000  // Immediate
#define PWM_0_CTL_DBRISEUPD_LS  0x00002000  // Locally Synchronized
#define PWM_0_CTL_DBRISEUPD_GS  0x00003000  // Globally Synchronized
#define PWM_0_CTL_DBCTLUPD_M    0x00000C00  // PWMnDBCTL Update Mode
#define PWM_0_CTL_DBCTLUPD_I    0x00000000  // Immediate
#define PWM_0_CTL_DBCTLUPD_LS   0x00000800  // Locally Synchronized
#define PWM_0_CTL_DBCTLUPD_GS   0x00000C00  // Globally Synchronized
#define PWM_0_CTL_GENBUPD_M     0x00000300  // PWMnGENB Update Mode
#define PWM_0_CTL_GENBUPD_I     0x00000000  // Immediate
#define PWM_0_CTL_GENBUPD_LS    0x00000200  // Locally Synchronized
#define PWM_0_CTL_GENBUPD_GS    0x00000300  // Globally Synchronized
#define PWM_0_CTL_GENAUPD_M     0x000000C0  // PWMnGENA Update Mode
#define PWM_0_CTL_GENAUPD_I     0x00000000  // Immediate
#define PWM_0_CTL_GENAUPD_LS    0x00000080  // Locally Synchronized
#define PWM_0_CTL_GENAUPD_GS    0x000000C0  // Globally Synchronized
#define PWM_0_CTL_CMPBUPD       0x00000020  // Comparator B Update Mode
#define PWM_0_CTL_CMPAUPD       0x00000010  // Comparator A Update Mode
#define PWM_0_CTL_LOADUPD       0x00000008  // Load Register Update Mode
#define PWM_0_CTL_DEBUG         0x00000004  // Debug Mode
#define PWM_0_CTL_MODE          0x00000002  // Counter Mode
#define PWM_0_CTL_ENABLE        0x00000001  // PWM Block Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_0_INTEN register.
//
//*****************************************************************************
#define PWM_0_INTEN_TRCMPBD     0x00002000  // Trigger for Counter=Comparator B
                                            // Down
#define PWM_0_INTEN_TRCMPBU     0x00001000  // Trigger for Counter=Comparator B
                                            // Up
#define PWM_0_INTEN_TRCMPAD     0x00000800  // Trigger for Counter=Comparator A
                                            // Down
#define PWM_0_INTEN_TRCMPAU     0x00000400  // Trigger for Counter=Comparator A
                                            // Up
#define PWM_0_INTEN_TRCNTLOAD   0x00000200  // Trigger for Counter=Load
#define PWM_0_INTEN_TRCNTZERO   0x00000100  // Trigger for Counter=0
#define PWM_0_INTEN_INTCMPBD    0x00000020  // Interrupt for Counter=Comparator
                                            // B Down
#define PWM_0_INTEN_INTCMPBU    0x00000010  // Interrupt for Counter=Comparator
                                            // B Up
#define PWM_0_INTEN_INTCMPAD    0x00000008  // Interrupt for Counter=Comparator
                                            // A Down
#define PWM_0_INTEN_INTCMPAU    0x00000004  // Interrupt for Counter=Comparator
                                            // A Up
#define PWM_0_INTEN_INTCNTLOAD  0x00000002  // Interrupt for Counter=Load
#define PWM_0_INTEN_INTCNTZERO  0x00000001  // Interrupt for Counter=0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_0_RIS register.
//
//*****************************************************************************
#define PWM_0_RIS_INTCMPBD      0x00000020  // Comparator B Down Interrupt
                                            // Status
#define PWM_0_RIS_INTCMPBU      0x00000010  // Comparator B Up Interrupt Status
#define PWM_0_RIS_INTCMPAD      0x00000008  // Comparator A Down Interrupt
                                            // Status
#define PWM_0_RIS_INTCMPAU      0x00000004  // Comparator A Up Interrupt Status
#define PWM_0_RIS_INTCNTLOAD    0x00000002  // Counter=Load Interrupt Status
#define PWM_0_RIS_INTCNTZERO    0x00000001  // Counter=0 Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_0_ISC register.
//
//*****************************************************************************
#define PWM_0_ISC_INTCMPBD      0x00000020  // Comparator B Down Interrupt
#define PWM_0_ISC_INTCMPBU      0x00000010  // Comparator B Up Interrupt
#define PWM_0_ISC_INTCMPAD      0x00000008  // Comparator A Down Interrupt
#define PWM_0_ISC_INTCMPAU      0x00000004  // Comparator A Up Interrupt
#define PWM_0_ISC_INTCNTLOAD    0x00000002  // Counter=Load Interrupt
#define PWM_0_ISC_INTCNTZERO    0x00000001  // Counter=0 Interrupt

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_0_LOAD register.
//
//*****************************************************************************
#define PWM_0_LOAD_M            0x0000FFFF  // Counter Load Value
#define PWM_0_LOAD_S            0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_0_COUNT register.
//
//*****************************************************************************
#define PWM_0_COUNT_M           0x0000FFFF  // Counter Value
#define PWM_0_COUNT_S           0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_0_CMPA register.
//
//*****************************************************************************
#define PWM_0_CMPA_M            0x0000FFFF  // Comparator A Value
#define PWM_0_CMPA_S            0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_0_CMPB register.
//
//*****************************************************************************
#define PWM_0_CMPB_M            0x0000FFFF  // Comparator B Value
#define PWM_0_CMPB_S            0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_0_GENA register.
//
//*****************************************************************************
#define PWM_0_GENA_ACTCMPBD_M   0x00000C00  // Action for Comparator B Down
#define PWM_0_GENA_ACTCMPBD_NONE                                              \
                                0x00000000  // Do nothing
#define PWM_0_GENA_ACTCMPBD_INV 0x00000400  // Invert the output signal
#define PWM_0_GENA_ACTCMPBD_ZERO                                              \
                                0x00000800  // Set the output signal to 0
#define PWM_0_GENA_ACTCMPBD_ONE 0x00000C00  // Set the output signal to 1
#define PWM_0_GENA_ACTCMPBU_M   0x00000300  // Action for Comparator B Up
#define PWM_0_GENA_ACTCMPBU_NONE                                              \
                                0x00000000  // Do nothing
#define PWM_0_GENA_ACTCMPBU_INV 0x00000100  // Invert the output signal
#define PWM_0_GENA_ACTCMPBU_ZERO                                              \
                                0x00000200  // Set the output signal to 0
#define PWM_0_GENA_ACTCMPBU_ONE 0x00000300  // Set the output signal to 1
#define PWM_0_GENA_ACTCMPAD_M   0x000000C0  // Action for Comparator A Down
#define PWM_0_GENA_ACTCMPAD_NONE                                              \
                                0x00000000  // Do nothing
#define PWM_0_GENA_ACTCMPAD_INV 0x00000040  // Invert the output signal
#define PWM_0_GENA_ACTCMPAD_ZERO                                              \
                                0x00000080  // Set the output signal to 0
#define PWM_0_GENA_ACTCMPAD_ONE 0x000000C0  // Set the output signal to 1
#define PWM_0_GENA_ACTCMPAU_M   0x00000030  // Action for Comparator A Up
#define PWM_0_GENA_ACTCMPAU_NONE                                              \
                                0x00000000  // Do nothing
#define PWM_0_GENA_ACTCMPAU_INV 0x00000010  // Invert the output signal
#define PWM_0_GENA_ACTCMPAU_ZERO                                              \
                                0x00000020  // Set the output signal to 0
#define PWM_0_GENA_ACTCMPAU_ONE 0x00000030  // Set the output signal to 1
#define PWM_0_GENA_ACTLOAD_M    0x0000000C  // Action for Counter=Load
#define PWM_0_GENA_ACTLOAD_NONE 0x00000000  // Do nothing
#define PWM_0_GENA_ACTLOAD_INV  0x00000004  // Invert the output signal
#define PWM_0_GENA_ACTLOAD_ZERO 0x00000008  // Set the output signal to 0
#define PWM_0_GENA_ACTLOAD_ONE  0x0000000C  // Set the output signal to 1
#define PWM_0_GENA_ACTZERO_M    0x00000003  // Action for Counter=0
#define PWM_0_GENA_ACTZERO_NONE 0x00000000  // Do nothing
#define PWM_0_GENA_ACTZERO_INV  0x00000001  // Invert the output signal
#define PWM_0_GENA_ACTZERO_ZERO 0x00000002  // Set the output signal to 0
#define PWM_0_GENA_ACTZERO_ONE  0x00000003  // Set the output signal to 1

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_0_GENB register.
//
//*****************************************************************************
#define PWM_0_GENB_ACTCMPBD_M   0x00000C00  // Action for Comparator B Down
#define PWM_0_GENB_ACTCMPBD_NONE                                              \
                                0x00000000  // Do nothing
#define PWM_0_GENB_ACTCMPBD_INV 0x00000400  // Invert the output signal
#define PWM_0_GENB_ACTCMPBD_ZERO                                              \
                                0x00000800  // Set the output signal to 0
#define PWM_0_GENB_ACTCMPBD_ONE 0x00000C00  // Set the output signal to 1
#define PWM_0_GENB_ACTCMPBU_M   0x00000300  // Action for Comparator B Up
#define PWM_0_GENB_ACTCMPBU_NONE                                              \
                                0x00000000  // Do nothing
#define PWM_0_GENB_ACTCMPBU_INV 0x00000100  // Invert the output signal
#define PWM_0_GENB_ACTCMPBU_ZERO                                              \
                                0x00000200  // Set the output signal to 0
#define PWM_0_GENB_ACTCMPBU_ONE 0x00000300  // Set the output signal to 1
#define PWM_0_GENB_ACTCMPAD_M   0x000000C0  // Action for Comparator A Down
#define PWM_0_GENB_ACTCMPAD_NONE                                              \
                                0x00000000  // Do nothing
#define PWM_0_GENB_ACTCMPAD_INV 0x00000040  // Invert the output signal
#define PWM_0_GENB_ACTCMPAD_ZERO                                              \
                                0x00000080  // Set the output signal to 0
#define PWM_0_GENB_ACTCMPAD_ONE 0x000000C0  // Set the output signal to 1
#define PWM_0_GENB_ACTCMPAU_M   0x00000030  // Action for Comparator A Up
#define PWM_0_GENB_ACTCMPAU_NONE                                              \
                                0x00000000  // Do nothing
#define PWM_0_GENB_ACTCMPAU_INV 0x00000010  // Invert the output signal
#define PWM_0_GENB_ACTCMPAU_ZERO                                              \
                                0x00000020  // Set the output signal to 0
#define PWM_0_GENB_ACTCMPAU_ONE 0x00000030  // Set the output signal to 1
#define PWM_0_GENB_ACTLOAD_M    0x0000000C  // Action for Counter=Load
#define PWM_0_GENB_ACTLOAD_NONE 0x00000000  // Do nothing
#define PWM_0_GENB_ACTLOAD_INV  0x00000004  // Invert the output signal
#define PWM_0_GENB_ACTLOAD_ZERO 0x00000008  // Set the output signal to 0
#define PWM_0_GENB_ACTLOAD_ONE  0x0000000C  // Set the output signal to 1
#define PWM_0_GENB_ACTZERO_M    0x00000003  // Action for Counter=0
#define PWM_0_GENB_ACTZERO_NONE 0x00000000  // Do nothing
#define PWM_0_GENB_ACTZERO_INV  0x00000001  // Invert the output signal
#define PWM_0_GENB_ACTZERO_ZERO 0x00000002  // Set the output signal to 0
#define PWM_0_GENB_ACTZERO_ONE  0x00000003  // Set the output signal to 1

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_0_DBCTL register.
//
//*****************************************************************************
#define PWM_0_DBCTL_ENABLE      0x00000001  // Dead-Band Generator Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_0_DBRISE register.
//
//*****************************************************************************
#define PWM_0_DBRISE_DELAY_M    0x00000FFF  // Dead-Band Rise Delay
#define PWM_0_DBRISE_DELAY_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_0_DBFALL register.
//
//*****************************************************************************
#define PWM_0_DBFALL_DELAY_M    0x00000FFF  // Dead-Band Fall Delay
#define PWM_0_DBFALL_DELAY_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_0_FLTSRC0
// register.
//
//*****************************************************************************
#define PWM_0_FLTSRC0_FAULT3    0x00000008  // Fault3 Input
#define PWM_0_FLTSRC0_FAULT2    0x00000004  // Fault2 Input
#define PWM_0_FLTSRC0_FAULT1    0x00000002  // Fault1 Input
#define PWM_0_FLTSRC0_FAULT0    0x00000001  // Fault0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_0_FLTSRC1
// register.
//
//*****************************************************************************
#define PWM_0_FLTSRC1_DCMP7     0x00000080  // Digital Comparator 7
#define PWM_0_FLTSRC1_DCMP6     0x00000040  // Digital Comparator 6
#define PWM_0_FLTSRC1_DCMP5     0x00000020  // Digital Comparator 5
#define PWM_0_FLTSRC1_DCMP4     0x00000010  // Digital Comparator 4
#define PWM_0_FLTSRC1_DCMP3     0x00000008  // Digital Comparator 3
#define PWM_0_FLTSRC1_DCMP2     0x00000004  // Digital Comparator 2
#define PWM_0_FLTSRC1_DCMP1     0x00000002  // Digital Comparator 1
#define PWM_0_FLTSRC1_DCMP0     0x00000001  // Digital Comparator 0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_0_MINFLTPER
// register.
//
//*****************************************************************************
#define PWM_0_MINFLTPER_M       0x0000FFFF  // Minimum Fault Period
#define PWM_0_MINFLTPER_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_1_CTL register.
//
//*****************************************************************************
#define PWM_1_CTL_LATCH         0x00040000  // Latch Fault Input
#define PWM_1_CTL_MINFLTPER     0x00020000  // Minimum Fault Period
#define PWM_1_CTL_FLTSRC        0x00010000  // Fault Condition Source
#define PWM_1_CTL_DBFALLUPD_M   0x0000C000  // Specifies the update mode for
                                            // the PWMnDBFALL register
#define PWM_1_CTL_DBFALLUPD_I   0x00000000  // Immediate
#define PWM_1_CTL_DBFALLUPD_LS  0x00008000  // Locally Synchronized
#define PWM_1_CTL_DBFALLUPD_GS  0x0000C000  // Globally Synchronized
#define PWM_1_CTL_DBRISEUPD_M   0x00003000  // PWMnDBRISE Update Mode
#define PWM_1_CTL_DBRISEUPD_I   0x00000000  // Immediate
#define PWM_1_CTL_DBRISEUPD_LS  0x00002000  // Locally Synchronized
#define PWM_1_CTL_DBRISEUPD_GS  0x00003000  // Globally Synchronized
#define PWM_1_CTL_DBCTLUPD_M    0x00000C00  // PWMnDBCTL Update Mode
#define PWM_1_CTL_DBCTLUPD_I    0x00000000  // Immediate
#define PWM_1_CTL_DBCTLUPD_LS   0x00000800  // Locally Synchronized
#define PWM_1_CTL_DBCTLUPD_GS   0x00000C00  // Globally Synchronized
#define PWM_1_CTL_GENBUPD_M     0x00000300  // PWMnGENB Update Mode
#define PWM_1_CTL_GENBUPD_I     0x00000000  // Immediate
#define PWM_1_CTL_GENBUPD_LS    0x00000200  // Locally Synchronized
#define PWM_1_CTL_GENBUPD_GS    0x00000300  // Globally Synchronized
#define PWM_1_CTL_GENAUPD_M     0x000000C0  // PWMnGENA Update Mode
#define PWM_1_CTL_GENAUPD_I     0x00000000  // Immediate
#define PWM_1_CTL_GENAUPD_LS    0x00000080  // Locally Synchronized
#define PWM_1_CTL_GENAUPD_GS    0x000000C0  // Globally Synchronized
#define PWM_1_CTL_CMPBUPD       0x00000020  // Comparator B Update Mode
#define PWM_1_CTL_CMPAUPD       0x00000010  // Comparator A Update Mode
#define PWM_1_CTL_LOADUPD       0x00000008  // Load Register Update Mode
#define PWM_1_CTL_DEBUG         0x00000004  // Debug Mode
#define PWM_1_CTL_MODE          0x00000002  // Counter Mode
#define PWM_1_CTL_ENABLE        0x00000001  // PWM Block Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_1_INTEN register.
//
//*****************************************************************************
#define PWM_1_INTEN_TRCMPBD     0x00002000  // Trigger for Counter=Comparator B
                                            // Down
#define PWM_1_INTEN_TRCMPBU     0x00001000  // Trigger for Counter=Comparator B
                                            // Up
#define PWM_1_INTEN_TRCMPAD     0x00000800  // Trigger for Counter=Comparator A
                                            // Down
#define PWM_1_INTEN_TRCMPAU     0x00000400  // Trigger for Counter=Comparator A
                                            // Up
#define PWM_1_INTEN_TRCNTLOAD   0x00000200  // Trigger for Counter=Load
#define PWM_1_INTEN_TRCNTZERO   0x00000100  // Trigger for Counter=0
#define PWM_1_INTEN_INTCMPBD    0x00000020  // Interrupt for Counter=Comparator
                                            // B Down
#define PWM_1_INTEN_INTCMPBU    0x00000010  // Interrupt for Counter=Comparator
                                            // B Up
#define PWM_1_INTEN_INTCMPAD    0x00000008  // Interrupt for Counter=Comparator
                                            // A Down
#define PWM_1_INTEN_INTCMPAU    0x00000004  // Interrupt for Counter=Comparator
                                            // A Up
#define PWM_1_INTEN_INTCNTLOAD  0x00000002  // Interrupt for Counter=Load
#define PWM_1_INTEN_INTCNTZERO  0x00000001  // Interrupt for Counter=0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_1_RIS register.
//
//*****************************************************************************
#define PWM_1_RIS_INTCMPBD      0x00000020  // Comparator B Down Interrupt
                                            // Status
#define PWM_1_RIS_INTCMPBU      0x00000010  // Comparator B Up Interrupt Status
#define PWM_1_RIS_INTCMPAD      0x00000008  // Comparator A Down Interrupt
                                            // Status
#define PWM_1_RIS_INTCMPAU      0x00000004  // Comparator A Up Interrupt Status
#define PWM_1_RIS_INTCNTLOAD    0x00000002  // Counter=Load Interrupt Status
#define PWM_1_RIS_INTCNTZERO    0x00000001  // Counter=0 Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_1_ISC register.
//
//*****************************************************************************
#define PWM_1_ISC_INTCMPBD      0x00000020  // Comparator B Down Interrupt
#define PWM_1_ISC_INTCMPBU      0x00000010  // Comparator B Up Interrupt
#define PWM_1_ISC_INTCMPAD      0x00000008  // Comparator A Down Interrupt
#define PWM_1_ISC_INTCMPAU      0x00000004  // Comparator A Up Interrupt
#define PWM_1_ISC_INTCNTLOAD    0x00000002  // Counter=Load Interrupt
#define PWM_1_ISC_INTCNTZERO    0x00000001  // Counter=0 Interrupt

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_1_LOAD register.
//
//*****************************************************************************
#define PWM_1_LOAD_LOAD_M       0x0000FFFF  // Counter Load Value
#define PWM_1_LOAD_LOAD_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_1_COUNT register.
//
//*****************************************************************************
#define PWM_1_COUNT_COUNT_M     0x0000FFFF  // Counter Value
#define PWM_1_COUNT_COUNT_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_1_CMPA register.
//
//*****************************************************************************
#define PWM_1_CMPA_COMPA_M      0x0000FFFF  // Comparator A Value
#define PWM_1_CMPA_COMPA_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_1_CMPB register.
//
//*****************************************************************************
#define PWM_1_CMPB_COMPB_M      0x0000FFFF  // Comparator B Value
#define PWM_1_CMPB_COMPB_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_1_GENA register.
//
//*****************************************************************************
#define PWM_1_GENA_ACTCMPBD_M   0x00000C00  // Action for Comparator B Down
#define PWM_1_GENA_ACTCMPBD_NONE                                              \
                                0x00000000  // Do nothing
#define PWM_1_GENA_ACTCMPBD_INV 0x00000400  // Invert the output signal
#define PWM_1_GENA_ACTCMPBD_ZERO                                              \
                                0x00000800  // Set the output signal to 0
#define PWM_1_GENA_ACTCMPBD_ONE 0x00000C00  // Set the output signal to 1
#define PWM_1_GENA_ACTCMPBU_M   0x00000300  // Action for Comparator B Up
#define PWM_1_GENA_ACTCMPBU_NONE                                              \
                                0x00000000  // Do nothing
#define PWM_1_GENA_ACTCMPBU_INV 0x00000100  // Invert the output signal
#define PWM_1_GENA_ACTCMPBU_ZERO                                              \
                                0x00000200  // Set the output signal to 0
#define PWM_1_GENA_ACTCMPBU_ONE 0x00000300  // Set the output signal to 1
#define PWM_1_GENA_ACTCMPAD_M   0x000000C0  // Action for Comparator A Down
#define PWM_1_GENA_ACTCMPAD_NONE                                              \
                                0x00000000  // Do nothing
#define PWM_1_GENA_ACTCMPAD_INV 0x00000040  // Invert the output signal
#define PWM_1_GENA_ACTCMPAD_ZERO                                              \
                                0x00000080  // Set the output signal to 0
#define PWM_1_GENA_ACTCMPAD_ONE 0x000000C0  // Set the output signal to 1
#define PWM_1_GENA_ACTCMPAU_M   0x00000030  // Action for Comparator A Up
#define PWM_1_GENA_ACTCMPAU_NONE                                              \
                                0x00000000  // Do nothing
#define PWM_1_GENA_ACTCMPAU_INV 0x00000010  // Invert the output signal
#define PWM_1_GENA_ACTCMPAU_ZERO                                              \
                                0x00000020  // Set the output signal to 0
#define PWM_1_GENA_ACTCMPAU_ONE 0x00000030  // Set the output signal to 1
#define PWM_1_GENA_ACTLOAD_M    0x0000000C  // Action for Counter=Load
#define PWM_1_GENA_ACTLOAD_NONE 0x00000000  // Do nothing
#define PWM_1_GENA_ACTLOAD_INV  0x00000004  // Invert the output signal
#define PWM_1_GENA_ACTLOAD_ZERO 0x00000008  // Set the output signal to 0
#define PWM_1_GENA_ACTLOAD_ONE  0x0000000C  // Set the output signal to 1
#define PWM_1_GENA_ACTZERO_M    0x00000003  // Action for Counter=0
#define PWM_1_GENA_ACTZERO_NONE 0x00000000  // Do nothing
#define PWM_1_GENA_ACTZERO_INV  0x00000001  // Invert the output signal
#define PWM_1_GENA_ACTZERO_ZERO 0x00000002  // Set the output signal to 0
#define PWM_1_GENA_ACTZERO_ONE  0x00000003  // Set the output signal to 1

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_1_GENB register.
//
//*****************************************************************************
#define PWM_1_GENB_ACTCMPBD_M   0x00000C00  // Action for Comparator B Down
#define PWM_1_GENB_ACTCMPBD_NONE                                              \
                                0x00000000  // Do nothing
#define PWM_1_GENB_ACTCMPBD_INV 0x00000400  // Invert the output signal
#define PWM_1_GENB_ACTCMPBD_ZERO                                              \
                                0x00000800  // Set the output signal to 0
#define PWM_1_GENB_ACTCMPBD_ONE 0x00000C00  // Set the output signal to 1
#define PWM_1_GENB_ACTCMPBU_M   0x00000300  // Action for Comparator B Up
#define PWM_1_GENB_ACTCMPBU_NONE                                              \
                                0x00000000  // Do nothing
#define PWM_1_GENB_ACTCMPBU_INV 0x00000100  // Invert the output signal
#define PWM_1_GENB_ACTCMPBU_ZERO                                              \
                                0x00000200  // Set the output signal to 0
#define PWM_1_GENB_ACTCMPBU_ONE 0x00000300  // Set the output signal to 1
#define PWM_1_GENB_ACTCMPAD_M   0x000000C0  // Action for Comparator A Down
#define PWM_1_GENB_ACTCMPAD_NONE                                              \
                                0x00000000  // Do nothing
#define PWM_1_GENB_ACTCMPAD_INV 0x00000040  // Invert the output signal
#define PWM_1_GENB_ACTCMPAD_ZERO                                              \
                                0x00000080  // Set the output signal to 0
#define PWM_1_GENB_ACTCMPAD_ONE 0x000000C0  // Set the output signal to 1
#define PWM_1_GENB_ACTCMPAU_M   0x00000030  // Action for Comparator A Up
#define PWM_1_GENB_ACTCMPAU_NONE                                              \
                                0x00000000  // Do nothing
#define PWM_1_GENB_ACTCMPAU_INV 0x00000010  // Invert the output signal
#define PWM_1_GENB_ACTCMPAU_ZERO                                              \
                                0x00000020  // Set the output signal to 0
#define PWM_1_GENB_ACTCMPAU_ONE 0x00000030  // Set the output signal to 1
#define PWM_1_GENB_ACTLOAD_M    0x0000000C  // Action for Counter=Load
#define PWM_1_GENB_ACTLOAD_NONE 0x00000000  // Do nothing
#define PWM_1_GENB_ACTLOAD_INV  0x00000004  // Invert the output signal
#define PWM_1_GENB_ACTLOAD_ZERO 0x00000008  // Set the output signal to 0
#define PWM_1_GENB_ACTLOAD_ONE  0x0000000C  // Set the output signal to 1
#define PWM_1_GENB_ACTZERO_M    0x00000003  // Action for Counter=0
#define PWM_1_GENB_ACTZERO_NONE 0x00000000  // Do nothing
#define PWM_1_GENB_ACTZERO_INV  0x00000001  // Invert the output signal
#define PWM_1_GENB_ACTZERO_ZERO 0x00000002  // Set the output signal to 0
#define PWM_1_GENB_ACTZERO_ONE  0x00000003  // Set the output signal to 1

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_1_DBCTL register.
//
//*****************************************************************************
#define PWM_1_DBCTL_ENABLE      0x00000001  // Dead-Band Generator Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_1_DBRISE register.
//
//*****************************************************************************
#define PWM_1_DBRISE_RISEDELAY_M                                              \
                                0x00000FFF  // Dead-Band Rise Delay
#define PWM_1_DBRISE_RISEDELAY_S                                              \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_1_DBFALL register.
//
//*****************************************************************************
#define PWM_1_DBFALL_FALLDELAY_M                                              \
                                0x00000FFF  // Dead-Band Fall Delay
#define PWM_1_DBFALL_FALLDELAY_S                                              \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_1_FLTSRC0
// register.
//
//*****************************************************************************
#define PWM_1_FLTSRC0_FAULT3    0x00000008  // Fault3 Input
#define PWM_1_FLTSRC0_FAULT2    0x00000004  // Fault2 Input
#define PWM_1_FLTSRC0_FAULT1    0x00000002  // Fault1 Input
#define PWM_1_FLTSRC0_FAULT0    0x00000001  // Fault0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_1_FLTSRC1
// register.
//
//*****************************************************************************
#define PWM_1_FLTSRC1_DCMP7     0x00000080  // Digital Comparator 7
#define PWM_1_FLTSRC1_DCMP6     0x00000040  // Digital Comparator 6
#define PWM_1_FLTSRC1_DCMP5     0x00000020  // Digital Comparator 5
#define PWM_1_FLTSRC1_DCMP4     0x00000010  // Digital Comparator 4
#define PWM_1_FLTSRC1_DCMP3     0x00000008  // Digital Comparator 3
#define PWM_1_FLTSRC1_DCMP2     0x00000004  // Digital Comparator 2
#define PWM_1_FLTSRC1_DCMP1     0x00000002  // Digital Comparator 1
#define PWM_1_FLTSRC1_DCMP0     0x00000001  // Digital Comparator 0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_1_MINFLTPER
// register.
//
//*****************************************************************************
#define PWM_1_MINFLTPER_MFP_M   0x0000FFFF  // Minimum Fault Period
#define PWM_1_MINFLTPER_MFP_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_2_CTL register.
//
//*****************************************************************************
#define PWM_2_CTL_LATCH         0x00040000  // Latch Fault Input
#define PWM_2_CTL_MINFLTPER     0x00020000  // Minimum Fault Period
#define PWM_2_CTL_FLTSRC        0x00010000  // Fault Condition Source
#define PWM_2_CTL_DBFALLUPD_M   0x0000C000  // Specifies the update mode for
                                            // the PWMnDBFALL register
#define PWM_2_CTL_DBFALLUPD_I   0x00000000  // Immediate
#define PWM_2_CTL_DBFALLUPD_LS  0x00008000  // Locally Synchronized
#define PWM_2_CTL_DBFALLUPD_GS  0x0000C000  // Globally Synchronized
#define PWM_2_CTL_DBRISEUPD_M   0x00003000  // PWMnDBRISE Update Mode
#define PWM_2_CTL_DBRISEUPD_I   0x00000000  // Immediate
#define PWM_2_CTL_DBRISEUPD_LS  0x00002000  // Locally Synchronized
#define PWM_2_CTL_DBRISEUPD_GS  0x00003000  // Globally Synchronized
#define PWM_2_CTL_DBCTLUPD_M    0x00000C00  // PWMnDBCTL Update Mode
#define PWM_2_CTL_DBCTLUPD_I    0x00000000  // Immediate
#define PWM_2_CTL_DBCTLUPD_LS   0x00000800  // Locally Synchronized
#define PWM_2_CTL_DBCTLUPD_GS   0x00000C00  // Globally Synchronized
#define PWM_2_CTL_GENBUPD_M     0x00000300  // PWMnGENB Update Mode
#define PWM_2_CTL_GENBUPD_I     0x00000000  // Immediate
#define PWM_2_CTL_GENBUPD_LS    0x00000200  // Locally Synchronized
#define PWM_2_CTL_GENBUPD_GS    0x00000300  // Globally Synchronized
#define PWM_2_CTL_GENAUPD_M     0x000000C0  // PWMnGENA Update Mode
#define PWM_2_CTL_GENAUPD_I     0x00000000  // Immediate
#define PWM_2_CTL_GENAUPD_LS    0x00000080  // Locally Synchronized
#define PWM_2_CTL_GENAUPD_GS    0x000000C0  // Globally Synchronized
#define PWM_2_CTL_CMPBUPD       0x00000020  // Comparator B Update Mode
#define PWM_2_CTL_CMPAUPD       0x00000010  // Comparator A Update Mode
#define PWM_2_CTL_LOADUPD       0x00000008  // Load Register Update Mode
#define PWM_2_CTL_DEBUG         0x00000004  // Debug Mode
#define PWM_2_CTL_MODE          0x00000002  // Counter Mode
#define PWM_2_CTL_ENABLE        0x00000001  // PWM Block Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_2_INTEN register.
//
//*****************************************************************************
#define PWM_2_INTEN_TRCMPBD     0x00002000  // Trigger for Counter=Comparator B
                                            // Down
#define PWM_2_INTEN_TRCMPBU     0x00001000  // Trigger for Counter=Comparator B
                                            // Up
#define PWM_2_INTEN_TRCMPAD     0x00000800  // Trigger for Counter=Comparator A
                                            // Down
#define PWM_2_INTEN_TRCMPAU     0x00000400  // Trigger for Counter=Comparator A
                                            // Up
#define PWM_2_INTEN_TRCNTLOAD   0x00000200  // Trigger for Counter=Load
#define PWM_2_INTEN_TRCNTZERO   0x00000100  // Trigger for Counter=0
#define PWM_2_INTEN_INTCMPBD    0x00000020  // Interrupt for Counter=Comparator
                                            // B Down
#define PWM_2_INTEN_INTCMPBU    0x00000010  // Interrupt for Counter=Comparator
                                            // B Up
#define PWM_2_INTEN_INTCMPAD    0x00000008  // Interrupt for Counter=Comparator
                                            // A Down
#define PWM_2_INTEN_INTCMPAU    0x00000004  // Interrupt for Counter=Comparator
                                            // A Up
#define PWM_2_INTEN_INTCNTLOAD  0x00000002  // Interrupt for Counter=Load
#define PWM_2_INTEN_INTCNTZERO  0x00000001  // Interrupt for Counter=0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_2_RIS register.
//
//*****************************************************************************
#define PWM_2_RIS_INTCMPBD      0x00000020  // Comparator B Down Interrupt
                                            // Status
#define PWM_2_RIS_INTCMPBU      0x00000010  // Comparator B Up Interrupt Status
#define PWM_2_RIS_INTCMPAD      0x00000008  // Comparator A Down Interrupt
                                            // Status
#define PWM_2_RIS_INTCMPAU      0x00000004  // Comparator A Up Interrupt Status
#define PWM_2_RIS_INTCNTLOAD    0x00000002  // Counter=Load Interrupt Status
#define PWM_2_RIS_INTCNTZERO    0x00000001  // Counter=0 Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_2_ISC register.
//
//*****************************************************************************
#define PWM_2_ISC_INTCMPBD      0x00000020  // Comparator B Down Interrupt
#define PWM_2_ISC_INTCMPBU      0x00000010  // Comparator B Up Interrupt
#define PWM_2_ISC_INTCMPAD      0x00000008  // Comparator A Down Interrupt
#define PWM_2_ISC_INTCMPAU      0x00000004  // Comparator A Up Interrupt
#define PWM_2_ISC_INTCNTLOAD    0x00000002  // Counter=Load Interrupt
#define PWM_2_ISC_INTCNTZERO    0x00000001  // Counter=0 Interrupt

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_2_LOAD register.
//
//*****************************************************************************
#define PWM_2_LOAD_LOAD_M       0x0000FFFF  // Counter Load Value
#define PWM_2_LOAD_LOAD_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_2_COUNT register.
//
//*****************************************************************************
#define PWM_2_COUNT_COUNT_M     0x0000FFFF  // Counter Value
#define PWM_2_COUNT_COUNT_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_2_CMPA register.
//
//*****************************************************************************
#define PWM_2_CMPA_COMPA_M      0x0000FFFF  // Comparator A Value
#define PWM_2_CMPA_COMPA_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_2_CMPB register.
//
//*****************************************************************************
#define PWM_2_CMPB_COMPB_M      0x0000FFFF  // Comparator B Value
#define PWM_2_CMPB_COMPB_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_2_GENA register.
//
//*****************************************************************************
#define PWM_2_GENA_ACTCMPBD_M   0x00000C00  // Action for Comparator B Down
#define PWM_2_GENA_ACTCMPBD_NONE                                              \
                                0x00000000  // Do nothing
#define PWM_2_GENA_ACTCMPBD_INV 0x00000400  // Invert the output signal
#define PWM_2_GENA_ACTCMPBD_ZERO                                              \
                                0x00000800  // Set the output signal to 0
#define PWM_2_GENA_ACTCMPBD_ONE 0x00000C00  // Set the output signal to 1
#define PWM_2_GENA_ACTCMPBU_M   0x00000300  // Action for Comparator B Up
#define PWM_2_GENA_ACTCMPBU_NONE                                              \
                                0x00000000  // Do nothing
#define PWM_2_GENA_ACTCMPBU_INV 0x00000100  // Invert the output signal
#define PWM_2_GENA_ACTCMPBU_ZERO                                              \
                                0x00000200  // Set the output signal to 0
#define PWM_2_GENA_ACTCMPBU_ONE 0x00000300  // Set the output signal to 1
#define PWM_2_GENA_ACTCMPAD_M   0x000000C0  // Action for Comparator A Down
#define PWM_2_GENA_ACTCMPAD_NONE                                              \
                                0x00000000  // Do nothing
#define PWM_2_GENA_ACTCMPAD_INV 0x00000040  // Invert the output signal
#define PWM_2_GENA_ACTCMPAD_ZERO                                              \
                                0x00000080  // Set the output signal to 0
#define PWM_2_GENA_ACTCMPAD_ONE 0x000000C0  // Set the output signal to 1
#define PWM_2_GENA_ACTCMPAU_M   0x00000030  // Action for Comparator A Up
#define PWM_2_GENA_ACTCMPAU_NONE                                              \
                                0x00000000  // Do nothing
#define PWM_2_GENA_ACTCMPAU_INV 0x00000010  // Invert the output signal
#define PWM_2_GENA_ACTCMPAU_ZERO                                              \
                                0x00000020  // Set the output signal to 0
#define PWM_2_GENA_ACTCMPAU_ONE 0x00000030  // Set the output signal to 1
#define PWM_2_GENA_ACTLOAD_M    0x0000000C  // Action for Counter=Load
#define PWM_2_GENA_ACTLOAD_NONE 0x00000000  // Do nothing
#define PWM_2_GENA_ACTLOAD_INV  0x00000004  // Invert the output signal
#define PWM_2_GENA_ACTLOAD_ZERO 0x00000008  // Set the output signal to 0
#define PWM_2_GENA_ACTLOAD_ONE  0x0000000C  // Set the output signal to 1
#define PWM_2_GENA_ACTZERO_M    0x00000003  // Action for Counter=0
#define PWM_2_GENA_ACTZERO_NONE 0x00000000  // Do nothing
#define PWM_2_GENA_ACTZERO_INV  0x00000001  // Invert the output signal
#define PWM_2_GENA_ACTZERO_ZERO 0x00000002  // Set the output signal to 0
#define PWM_2_GENA_ACTZERO_ONE  0x00000003  // Set the output signal to 1

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_2_GENB register.
//
//*****************************************************************************
#define PWM_2_GENB_ACTCMPBD_M   0x00000C00  // Action for Comparator B Down
#define PWM_2_GENB_ACTCMPBD_NONE                                              \
                                0x00000000  // Do nothing
#define PWM_2_GENB_ACTCMPBD_INV 0x00000400  // Invert the output signal
#define PWM_2_GENB_ACTCMPBD_ZERO                                              \
                                0x00000800  // Set the output signal to 0
#define PWM_2_GENB_ACTCMPBD_ONE 0x00000C00  // Set the output signal to 1
#define PWM_2_GENB_ACTCMPBU_M   0x00000300  // Action for Comparator B Up
#define PWM_2_GENB_ACTCMPBU_NONE                                              \
                                0x00000000  // Do nothing
#define PWM_2_GENB_ACTCMPBU_INV 0x00000100  // Invert the output signal
#define PWM_2_GENB_ACTCMPBU_ZERO                                              \
                                0x00000200  // Set the output signal to 0
#define PWM_2_GENB_ACTCMPBU_ONE 0x00000300  // Set the output signal to 1
#define PWM_2_GENB_ACTCMPAD_M   0x000000C0  // Action for Comparator A Down
#define PWM_2_GENB_ACTCMPAD_NONE                                              \
                                0x00000000  // Do nothing
#define PWM_2_GENB_ACTCMPAD_INV 0x00000040  // Invert the output signal
#define PWM_2_GENB_ACTCMPAD_ZERO                                              \
                                0x00000080  // Set the output signal to 0
#define PWM_2_GENB_ACTCMPAD_ONE 0x000000C0  // Set the output signal to 1
#define PWM_2_GENB_ACTCMPAU_M   0x00000030  // Action for Comparator A Up
#define PWM_2_GENB_ACTCMPAU_NONE                                              \
                                0x00000000  // Do nothing
#define PWM_2_GENB_ACTCMPAU_INV 0x00000010  // Invert the output signal
#define PWM_2_GENB_ACTCMPAU_ZERO                                              \
                                0x00000020  // Set the output signal to 0
#define PWM_2_GENB_ACTCMPAU_ONE 0x00000030  // Set the output signal to 1
#define PWM_2_GENB_ACTLOAD_M    0x0000000C  // Action for Counter=Load
#define PWM_2_GENB_ACTLOAD_NONE 0x00000000  // Do nothing
#define PWM_2_GENB_ACTLOAD_INV  0x00000004  // Invert the output signal
#define PWM_2_GENB_ACTLOAD_ZERO 0x00000008  // Set the output signal to 0
#define PWM_2_GENB_ACTLOAD_ONE  0x0000000C  // Set the output signal to 1
#define PWM_2_GENB_ACTZERO_M    0x00000003  // Action for Counter=0
#define PWM_2_GENB_ACTZERO_NONE 0x00000000  // Do nothing
#define PWM_2_GENB_ACTZERO_INV  0x00000001  // Invert the output signal
#define PWM_2_GENB_ACTZERO_ZERO 0x00000002  // Set the output signal to 0
#define PWM_2_GENB_ACTZERO_ONE  0x00000003  // Set the output signal to 1

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_2_DBCTL register.
//
//*****************************************************************************
#define PWM_2_DBCTL_ENABLE      0x00000001  // Dead-Band Generator Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_2_DBRISE register.
//
//*****************************************************************************
#define PWM_2_DBRISE_RISEDELAY_M                                              \
                                0x00000FFF  // Dead-Band Rise Delay
#define PWM_2_DBRISE_RISEDELAY_S                                              \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_2_DBFALL register.
//
//*****************************************************************************
#define PWM_2_DBFALL_FALLDELAY_M                                              \
                                0x00000FFF  // Dead-Band Fall Delay
#define PWM_2_DBFALL_FALLDELAY_S                                              \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_2_FLTSRC0
// register.
//
//*****************************************************************************
#define PWM_2_FLTSRC0_FAULT3    0x00000008  // Fault3 Input
#define PWM_2_FLTSRC0_FAULT2    0x00000004  // Fault2 Input
#define PWM_2_FLTSRC0_FAULT1    0x00000002  // Fault1 Input
#define PWM_2_FLTSRC0_FAULT0    0x00000001  // Fault0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_2_FLTSRC1
// register.
//
//*****************************************************************************
#define PWM_2_FLTSRC1_DCMP7     0x00000080  // Digital Comparator 7
#define PWM_2_FLTSRC1_DCMP6     0x00000040  // Digital Comparator 6
#define PWM_2_FLTSRC1_DCMP5     0x00000020  // Digital Comparator 5
#define PWM_2_FLTSRC1_DCMP4     0x00000010  // Digital Comparator 4
#define PWM_2_FLTSRC1_DCMP3     0x00000008  // Digital Comparator 3
#define PWM_2_FLTSRC1_DCMP2     0x00000004  // Digital Comparator 2
#define PWM_2_FLTSRC1_DCMP1     0x00000002  // Digital Comparator 1
#define PWM_2_FLTSRC1_DCMP0     0x00000001  // Digital Comparator 0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_2_MINFLTPER
// register.
//
//*****************************************************************************
#define PWM_2_MINFLTPER_MFP_M   0x0000FFFF  // Minimum Fault Period
#define PWM_2_MINFLTPER_MFP_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_3_CTL register.
//
//*****************************************************************************
#define PWM_3_CTL_LATCH         0x00040000  // Latch Fault Input
#define PWM_3_CTL_MINFLTPER     0x00020000  // Minimum Fault Period
#define PWM_3_CTL_FLTSRC        0x00010000  // Fault Condition Source
#define PWM_3_CTL_DBFALLUPD_M   0x0000C000  // Specifies the update mode for
                                            // the PWMnDBFALL register
#define PWM_3_CTL_DBFALLUPD_I   0x00000000  // Immediate
#define PWM_3_CTL_DBFALLUPD_LS  0x00008000  // Locally Synchronized
#define PWM_3_CTL_DBFALLUPD_GS  0x0000C000  // Globally Synchronized
#define PWM_3_CTL_DBRISEUPD_M   0x00003000  // PWMnDBRISE Update Mode
#define PWM_3_CTL_DBRISEUPD_I   0x00000000  // Immediate
#define PWM_3_CTL_DBRISEUPD_LS  0x00002000  // Locally Synchronized
#define PWM_3_CTL_DBRISEUPD_GS  0x00003000  // Globally Synchronized
#define PWM_3_CTL_DBCTLUPD_M    0x00000C00  // PWMnDBCTL Update Mode
#define PWM_3_CTL_DBCTLUPD_I    0x00000000  // Immediate
#define PWM_3_CTL_DBCTLUPD_LS   0x00000800  // Locally Synchronized
#define PWM_3_CTL_DBCTLUPD_GS   0x00000C00  // Globally Synchronized
#define PWM_3_CTL_GENBUPD_M     0x00000300  // PWMnGENB Update Mode
#define PWM_3_CTL_GENBUPD_I     0x00000000  // Immediate
#define PWM_3_CTL_GENBUPD_LS    0x00000200  // Locally Synchronized
#define PWM_3_CTL_GENBUPD_GS    0x00000300  // Globally Synchronized
#define PWM_3_CTL_GENAUPD_M     0x000000C0  // PWMnGENA Update Mode
#define PWM_3_CTL_GENAUPD_I     0x00000000  // Immediate
#define PWM_3_CTL_GENAUPD_LS    0x00000080  // Locally Synchronized
#define PWM_3_CTL_GENAUPD_GS    0x000000C0  // Globally Synchronized
#define PWM_3_CTL_CMPBUPD       0x00000020  // Comparator B Update Mode
#define PWM_3_CTL_CMPAUPD       0x00000010  // Comparator A Update Mode
#define PWM_3_CTL_LOADUPD       0x00000008  // Load Register Update Mode
#define PWM_3_CTL_DEBUG         0x00000004  // Debug Mode
#define PWM_3_CTL_MODE          0x00000002  // Counter Mode
#define PWM_3_CTL_ENABLE        0x00000001  // PWM Block Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_3_INTEN register.
//
//*****************************************************************************
#define PWM_3_INTEN_TRCMPBD     0x00002000  // Trigger for Counter=Comparator B
                                            // Down
#define PWM_3_INTEN_TRCMPBU     0x00001000  // Trigger for Counter=Comparator B
                                            // Up
#define PWM_3_INTEN_TRCMPAD     0x00000800  // Trigger for Counter=Comparator A
                                            // Down
#define PWM_3_INTEN_TRCMPAU     0x00000400  // Trigger for Counter=Comparator A
                                            // Up
#define PWM_3_INTEN_TRCNTLOAD   0x00000200  // Trigger for Counter=Load
#define PWM_3_INTEN_TRCNTZERO   0x00000100  // Trigger for Counter=0
#define PWM_3_INTEN_INTCMPBD    0x00000020  // Interrupt for Counter=Comparator
                                            // B Down
#define PWM_3_INTEN_INTCMPBU    0x00000010  // Interrupt for Counter=Comparator
                                            // B Up
#define PWM_3_INTEN_INTCMPAD    0x00000008  // Interrupt for Counter=Comparator
                                            // A Down
#define PWM_3_INTEN_INTCMPAU    0x00000004  // Interrupt for Counter=Comparator
                                            // A Up
#define PWM_3_INTEN_INTCNTLOAD  0x00000002  // Interrupt for Counter=Load
#define PWM_3_INTEN_INTCNTZERO  0x00000001  // Interrupt for Counter=0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_3_RIS register.
//
//*****************************************************************************
#define PWM_3_RIS_INTCMPBD      0x00000020  // Comparator B Down Interrupt
                                            // Status
#define PWM_3_RIS_INTCMPBU      0x00000010  // Comparator B Up Interrupt Status
#define PWM_3_RIS_INTCMPAD      0x00000008  // Comparator A Down Interrupt
                                            // Status
#define PWM_3_RIS_INTCMPAU      0x00000004  // Comparator A Up Interrupt Status
#define PWM_3_RIS_INTCNTLOAD    0x00000002  // Counter=Load Interrupt Status
#define PWM_3_RIS_INTCNTZERO    0x00000001  // Counter=0 Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_3_ISC register.
//
//*****************************************************************************
#define PWM_3_ISC_INTCMPBD      0x00000020  // Comparator B Down Interrupt
#define PWM_3_ISC_INTCMPBU      0x00000010  // Comparator B Up Interrupt
#define PWM_3_ISC_INTCMPAD      0x00000008  // Comparator A Down Interrupt
#define PWM_3_ISC_INTCMPAU      0x00000004  // Comparator A Up Interrupt
#define PWM_3_ISC_INTCNTLOAD    0x00000002  // Counter=Load Interrupt
#define PWM_3_ISC_INTCNTZERO    0x00000001  // Counter=0 Interrupt

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_3_LOAD register.
//
//*****************************************************************************
#define PWM_3_LOAD_LOAD_M       0x0000FFFF  // Counter Load Value
#define PWM_3_LOAD_LOAD_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_3_COUNT register.
//
//*****************************************************************************
#define PWM_3_COUNT_COUNT_M     0x0000FFFF  // Counter Value
#define PWM_3_COUNT_COUNT_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_3_CMPA register.
//
//*****************************************************************************
#define PWM_3_CMPA_COMPA_M      0x0000FFFF  // Comparator A Value
#define PWM_3_CMPA_COMPA_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_3_CMPB register.
//
//*****************************************************************************
#define PWM_3_CMPB_COMPB_M      0x0000FFFF  // Comparator B Value
#define PWM_3_CMPB_COMPB_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_3_GENA register.
//
//*****************************************************************************
#define PWM_3_GENA_ACTCMPBD_M   0x00000C00  // Action for Comparator B Down
#define PWM_3_GENA_ACTCMPBD_NONE                                              \
                                0x00000000  // Do nothing
#define PWM_3_GENA_ACTCMPBD_INV 0x00000400  // Invert the output signal
#define PWM_3_GENA_ACTCMPBD_ZERO                                              \
                                0x00000800  // Set the output signal to 0
#define PWM_3_GENA_ACTCMPBD_ONE 0x00000C00  // Set the output signal to 1
#define PWM_3_GENA_ACTCMPBU_M   0x00000300  // Action for Comparator B Up
#define PWM_3_GENA_ACTCMPBU_NONE                                              \
                                0x00000000  // Do nothing
#define PWM_3_GENA_ACTCMPBU_INV 0x00000100  // Invert the output signal
#define PWM_3_GENA_ACTCMPBU_ZERO                                              \
                                0x00000200  // Set the output signal to 0
#define PWM_3_GENA_ACTCMPBU_ONE 0x00000300  // Set the output signal to 1
#define PWM_3_GENA_ACTCMPAD_M   0x000000C0  // Action for Comparator A Down
#define PWM_3_GENA_ACTCMPAD_NONE                                              \
                                0x00000000  // Do nothing
#define PWM_3_GENA_ACTCMPAD_INV 0x00000040  // Invert the output signal
#define PWM_3_GENA_ACTCMPAD_ZERO                                              \
                                0x00000080  // Set the output signal to 0
#define PWM_3_GENA_ACTCMPAD_ONE 0x000000C0  // Set the output signal to 1
#define PWM_3_GENA_ACTCMPAU_M   0x00000030  // Action for Comparator A Up
#define PWM_3_GENA_ACTCMPAU_NONE                                              \
                                0x00000000  // Do nothing
#define PWM_3_GENA_ACTCMPAU_INV 0x00000010  // Invert the output signal
#define PWM_3_GENA_ACTCMPAU_ZERO                                              \
                                0x00000020  // Set the output signal to 0
#define PWM_3_GENA_ACTCMPAU_ONE 0x00000030  // Set the output signal to 1
#define PWM_3_GENA_ACTLOAD_M    0x0000000C  // Action for Counter=Load
#define PWM_3_GENA_ACTLOAD_NONE 0x00000000  // Do nothing
#define PWM_3_GENA_ACTLOAD_INV  0x00000004  // Invert the output signal
#define PWM_3_GENA_ACTLOAD_ZERO 0x00000008  // Set the output signal to 0
#define PWM_3_GENA_ACTLOAD_ONE  0x0000000C  // Set the output signal to 1
#define PWM_3_GENA_ACTZERO_M    0x00000003  // Action for Counter=0
#define PWM_3_GENA_ACTZERO_NONE 0x00000000  // Do nothing
#define PWM_3_GENA_ACTZERO_INV  0x00000001  // Invert the output signal
#define PWM_3_GENA_ACTZERO_ZERO 0x00000002  // Set the output signal to 0
#define PWM_3_GENA_ACTZERO_ONE  0x00000003  // Set the output signal to 1

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_3_GENB register.
//
//*****************************************************************************
#define PWM_3_GENB_ACTCMPBD_M   0x00000C00  // Action for Comparator B Down
#define PWM_3_GENB_ACTCMPBD_NONE                                              \
                                0x00000000  // Do nothing
#define PWM_3_GENB_ACTCMPBD_INV 0x00000400  // Invert the output signal
#define PWM_3_GENB_ACTCMPBD_ZERO                                              \
                                0x00000800  // Set the output signal to 0
#define PWM_3_GENB_ACTCMPBD_ONE 0x00000C00  // Set the output signal to 1
#define PWM_3_GENB_ACTCMPBU_M   0x00000300  // Action for Comparator B Up
#define PWM_3_GENB_ACTCMPBU_NONE                                              \
                                0x00000000  // Do nothing
#define PWM_3_GENB_ACTCMPBU_INV 0x00000100  // Invert the output signal
#define PWM_3_GENB_ACTCMPBU_ZERO                                              \
                                0x00000200  // Set the output signal to 0
#define PWM_3_GENB_ACTCMPBU_ONE 0x00000300  // Set the output signal to 1
#define PWM_3_GENB_ACTCMPAD_M   0x000000C0  // Action for Comparator A Down
#define PWM_3_GENB_ACTCMPAD_NONE                                              \
                                0x00000000  // Do nothing
#define PWM_3_GENB_ACTCMPAD_INV 0x00000040  // Invert the output signal
#define PWM_3_GENB_ACTCMPAD_ZERO                                              \
                                0x00000080  // Set the output signal to 0
#define PWM_3_GENB_ACTCMPAD_ONE 0x000000C0  // Set the output signal to 1
#define PWM_3_GENB_ACTCMPAU_M   0x00000030  // Action for Comparator A Up
#define PWM_3_GENB_ACTCMPAU_NONE                                              \
                                0x00000000  // Do nothing
#define PWM_3_GENB_ACTCMPAU_INV 0x00000010  // Invert the output signal
#define PWM_3_GENB_ACTCMPAU_ZERO                                              \
                                0x00000020  // Set the output signal to 0
#define PWM_3_GENB_ACTCMPAU_ONE 0x00000030  // Set the output signal to 1
#define PWM_3_GENB_ACTLOAD_M    0x0000000C  // Action for Counter=Load
#define PWM_3_GENB_ACTLOAD_NONE 0x00000000  // Do nothing
#define PWM_3_GENB_ACTLOAD_INV  0x00000004  // Invert the output signal
#define PWM_3_GENB_ACTLOAD_ZERO 0x00000008  // Set the output signal to 0
#define PWM_3_GENB_ACTLOAD_ONE  0x0000000C  // Set the output signal to 1
#define PWM_3_GENB_ACTZERO_M    0x00000003  // Action for Counter=0
#define PWM_3_GENB_ACTZERO_NONE 0x00000000  // Do nothing
#define PWM_3_GENB_ACTZERO_INV  0x00000001  // Invert the output signal
#define PWM_3_GENB_ACTZERO_ZERO 0x00000002  // Set the output signal to 0
#define PWM_3_GENB_ACTZERO_ONE  0x00000003  // Set the output signal to 1

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_3_DBCTL register.
//
//*****************************************************************************
#define PWM_3_DBCTL_ENABLE      0x00000001  // Dead-Band Generator Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_3_DBRISE register.
//
//*****************************************************************************
#define PWM_3_DBRISE_RISEDELAY_M                                              \
                                0x00000FFF  // Dead-Band Rise Delay
#define PWM_3_DBRISE_RISEDELAY_S                                              \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_3_DBFALL register.
//
//*****************************************************************************
#define PWM_3_DBFALL_FALLDELAY_M                                              \
                                0x00000FFF  // Dead-Band Fall Delay
#define PWM_3_DBFALL_FALLDELAY_S                                              \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_3_FLTSRC0
// register.
//
//*****************************************************************************
#define PWM_3_FLTSRC0_FAULT3    0x00000008  // Fault3 Input
#define PWM_3_FLTSRC0_FAULT2    0x00000004  // Fault2
#define PWM_3_FLTSRC0_FAULT1    0x00000002  // Fault1
#define PWM_3_FLTSRC0_FAULT0    0x00000001  // Fault0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_3_FLTSRC1
// register.
//
//*****************************************************************************
#define PWM_3_FLTSRC1_DCMP7     0x00000080  // Digital Comparator 7
#define PWM_3_FLTSRC1_DCMP6     0x00000040  // Digital Comparator 6
#define PWM_3_FLTSRC1_DCMP5     0x00000020  // Digital Comparator 5
#define PWM_3_FLTSRC1_DCMP4     0x00000010  // Digital Comparator 4
#define PWM_3_FLTSRC1_DCMP3     0x00000008  // Digital Comparator 3
#define PWM_3_FLTSRC1_DCMP2     0x00000004  // Digital Comparator 2
#define PWM_3_FLTSRC1_DCMP1     0x00000002  // Digital Comparator 1
#define PWM_3_FLTSRC1_DCMP0     0x00000001  // Digital Comparator 0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_3_MINFLTPER
// register.
//
//*****************************************************************************
#define PWM_3_MINFLTPER_MFP_M   0x0000FFFF  // Minimum Fault Period
#define PWM_3_MINFLTPER_MFP_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_0_FLTSEN register.
//
//*****************************************************************************
#define PWM_0_FLTSEN_FAULT3     0x00000008  // Fault3 Sense
#define PWM_0_FLTSEN_FAULT2     0x00000004  // Fault2 Sense
#define PWM_0_FLTSEN_FAULT1     0x00000002  // Fault1 Sense
#define PWM_0_FLTSEN_FAULT0     0x00000001  // Fault0 Sense

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_0_FLTSTAT0
// register.
//
//*****************************************************************************
#define PWM_0_FLTSTAT0_FAULT3   0x00000008  // Fault Input 3
#define PWM_0_FLTSTAT0_FAULT2   0x00000004  // Fault Input 2
#define PWM_0_FLTSTAT0_FAULT1   0x00000002  // Fault Input 1
#define PWM_0_FLTSTAT0_FAULT0   0x00000001  // Fault Input 0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_0_FLTSTAT1
// register.
//
//*****************************************************************************
#define PWM_0_FLTSTAT1_DCMP7    0x00000080  // Digital Comparator 7 Trigger
#define PWM_0_FLTSTAT1_DCMP6    0x00000040  // Digital Comparator 6 Trigger
#define PWM_0_FLTSTAT1_DCMP5    0x00000020  // Digital Comparator 5 Trigger
#define PWM_0_FLTSTAT1_DCMP4    0x00000010  // Digital Comparator 4 Trigger
#define PWM_0_FLTSTAT1_DCMP3    0x00000008  // Digital Comparator 3 Trigger
#define PWM_0_FLTSTAT1_DCMP2    0x00000004  // Digital Comparator 2 Trigger
#define PWM_0_FLTSTAT1_DCMP1    0x00000002  // Digital Comparator 1 Trigger
#define PWM_0_FLTSTAT1_DCMP0    0x00000001  // Digital Comparator 0 Trigger

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_1_FLTSEN register.
//
//*****************************************************************************
#define PWM_1_FLTSEN_FAULT3     0x00000008  // Fault3 Sense
#define PWM_1_FLTSEN_FAULT2     0x00000004  // Fault2 Sense
#define PWM_1_FLTSEN_FAULT1     0x00000002  // Fault1 Sense
#define PWM_1_FLTSEN_FAULT0     0x00000001  // Fault0 Sense

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_1_FLTSTAT0
// register.
//
//*****************************************************************************
#define PWM_1_FLTSTAT0_FAULT3   0x00000008  // Fault Input 3
#define PWM_1_FLTSTAT0_FAULT2   0x00000004  // Fault Input 2
#define PWM_1_FLTSTAT0_FAULT1   0x00000002  // Fault Input 1
#define PWM_1_FLTSTAT0_FAULT0   0x00000001  // Fault Input 0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_1_FLTSTAT1
// register.
//
//*****************************************************************************
#define PWM_1_FLTSTAT1_DCMP7    0x00000080  // Digital Comparator 7 Trigger
#define PWM_1_FLTSTAT1_DCMP6    0x00000040  // Digital Comparator 6 Trigger
#define PWM_1_FLTSTAT1_DCMP5    0x00000020  // Digital Comparator 5 Trigger
#define PWM_1_FLTSTAT1_DCMP4    0x00000010  // Digital Comparator 4 Trigger
#define PWM_1_FLTSTAT1_DCMP3    0x00000008  // Digital Comparator 3 Trigger
#define PWM_1_FLTSTAT1_DCMP2    0x00000004  // Digital Comparator 2 Trigger
#define PWM_1_FLTSTAT1_DCMP1    0x00000002  // Digital Comparator 1 Trigger
#define PWM_1_FLTSTAT1_DCMP0    0x00000001  // Digital Comparator 0 Trigger

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_2_FLTSEN register.
//
//*****************************************************************************
#define PWM_2_FLTSEN_FAULT3     0x00000008  // Fault3 Sense
#define PWM_2_FLTSEN_FAULT2     0x00000004  // Fault2 Sense
#define PWM_2_FLTSEN_FAULT1     0x00000002  // Fault1 Sense
#define PWM_2_FLTSEN_FAULT0     0x00000001  // Fault0 Sense

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_2_FLTSTAT0
// register.
//
//*****************************************************************************
#define PWM_2_FLTSTAT0_FAULT3   0x00000008  // Fault Input 3
#define PWM_2_FLTSTAT0_FAULT2   0x00000004  // Fault Input 2
#define PWM_2_FLTSTAT0_FAULT1   0x00000002  // Fault Input 1
#define PWM_2_FLTSTAT0_FAULT0   0x00000001  // Fault Input 0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_2_FLTSTAT1
// register.
//
//*****************************************************************************
#define PWM_2_FLTSTAT1_DCMP7    0x00000080  // Digital Comparator 7 Trigger
#define PWM_2_FLTSTAT1_DCMP6    0x00000040  // Digital Comparator 6 Trigger
#define PWM_2_FLTSTAT1_DCMP5    0x00000020  // Digital Comparator 5 Trigger
#define PWM_2_FLTSTAT1_DCMP4    0x00000010  // Digital Comparator 4 Trigger
#define PWM_2_FLTSTAT1_DCMP3    0x00000008  // Digital Comparator 3 Trigger
#define PWM_2_FLTSTAT1_DCMP2    0x00000004  // Digital Comparator 2 Trigger
#define PWM_2_FLTSTAT1_DCMP1    0x00000002  // Digital Comparator 1 Trigger
#define PWM_2_FLTSTAT1_DCMP0    0x00000001  // Digital Comparator 0 Trigger

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_3_FLTSEN register.
//
//*****************************************************************************
#define PWM_3_FLTSEN_FAULT3     0x00000008  // Fault3 Sense
#define PWM_3_FLTSEN_FAULT2     0x00000004  // Fault2 Sense
#define PWM_3_FLTSEN_FAULT1     0x00000002  // Fault1 Sense
#define PWM_3_FLTSEN_FAULT0     0x00000001  // Fault0 Sense

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_3_FLTSTAT0
// register.
//
//*****************************************************************************
#define PWM_3_FLTSTAT0_FAULT3   0x00000008  // Fault Input 3
#define PWM_3_FLTSTAT0_FAULT2   0x00000004  // Fault Input 2
#define PWM_3_FLTSTAT0_FAULT1   0x00000002  // Fault Input 1
#define PWM_3_FLTSTAT0_FAULT0   0x00000001  // Fault Input 0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_3_FLTSTAT1
// register.
//
//*****************************************************************************
#define PWM_3_FLTSTAT1_DCMP7    0x00000080  // Digital Comparator 7 Trigger
#define PWM_3_FLTSTAT1_DCMP6    0x00000040  // Digital Comparator 6 Trigger
#define PWM_3_FLTSTAT1_DCMP5    0x00000020  // Digital Comparator 5 Trigger
#define PWM_3_FLTSTAT1_DCMP4    0x00000010  // Digital Comparator 4 Trigger
#define PWM_3_FLTSTAT1_DCMP3    0x00000008  // Digital Comparator 3 Trigger
#define PWM_3_FLTSTAT1_DCMP2    0x00000004  // Digital Comparator 2 Trigger
#define PWM_3_FLTSTAT1_DCMP1    0x00000002  // Digital Comparator 1 Trigger
#define PWM_3_FLTSTAT1_DCMP0    0x00000001  // Digital Comparator 0 Trigger

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_PP register.
//
//*****************************************************************************
#define PWM_PP_ONE              0x00000400  // One-Shot Mode
#define PWM_PP_EFAULT           0x00000200  // Extended Fault
#define PWM_PP_ESYNC            0x00000100  // Extended Synchronization
#define PWM_PP_FCNT_M           0x000000F0  // Fault Inputs
#define PWM_PP_GCNT_M           0x0000000F  // Generators
#define PWM_PP_FCNT_S           4
#define PWM_PP_GCNT_S           0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_CC register.
//
//*****************************************************************************
#define PWM_CC_USEPWM           0x00000100  // Use PWM Clock Divisor
#define PWM_CC_PWMDIV_M         0x00000007  // PWM Clock Divider
#define PWM_CC_PWMDIV_2         0x00000000  // /2
#define PWM_CC_PWMDIV_4         0x00000001  // /4
#define PWM_CC_PWMDIV_8         0x00000002  // /8
#define PWM_CC_PWMDIV_16        0x00000003  // /16
#define PWM_CC_PWMDIV_32        0x00000004  // /32
#define PWM_CC_PWMDIV_64        0x00000005  // /64

//*****************************************************************************
//
// The following are defines for the bit fields in the QEI_O_CTL register.
//
//*****************************************************************************
#define QEI_CTL_FILTCNT_M       0x000F0000  // Input Filter Prescale Count
#define QEI_CTL_FILTEN          0x00002000  // Enable Input Filter
#define QEI_CTL_STALLEN         0x00001000  // Stall QEI
#define QEI_CTL_INVI            0x00000800  // Invert Index Pulse
#define QEI_CTL_INVB            0x00000400  // Invert PhB
#define QEI_CTL_INVA            0x00000200  // Invert PhA
#define QEI_CTL_VELDIV_M        0x000001C0  // Predivide Velocity
#define QEI_CTL_VELDIV_1        0x00000000  // QEI clock /1
#define QEI_CTL_VELDIV_2        0x00000040  // QEI clock /2
#define QEI_CTL_VELDIV_4        0x00000080  // QEI clock /4
#define QEI_CTL_VELDIV_8        0x000000C0  // QEI clock /8
#define QEI_CTL_VELDIV_16       0x00000100  // QEI clock /16
#define QEI_CTL_VELDIV_32       0x00000140  // QEI clock /32
#define QEI_CTL_VELDIV_64       0x00000180  // QEI clock /64
#define QEI_CTL_VELDIV_128      0x000001C0  // QEI clock /128
#define QEI_CTL_VELEN           0x00000020  // Capture Velocity
#define QEI_CTL_RESMODE         0x00000010  // Reset Mode
#define QEI_CTL_CAPMODE         0x00000008  // Capture Mode
#define QEI_CTL_SIGMODE         0x00000004  // Signal Mode
#define QEI_CTL_SWAP            0x00000002  // Swap Signals
#define QEI_CTL_ENABLE          0x00000001  // Enable QEI
#define QEI_CTL_FILTCNT_S       16

//*****************************************************************************
//
// The following are defines for the bit fields in the QEI_O_STAT register.
//
//*****************************************************************************
#define QEI_STAT_DIRECTION      0x00000002  // Direction of Rotation
#define QEI_STAT_ERROR          0x00000001  // Error Detected

//*****************************************************************************
//
// The following are defines for the bit fields in the QEI_O_POS register.
//
//*****************************************************************************
#define QEI_POS_M               0xFFFFFFFF  // Current Position Integrator
                                            // Value
#define QEI_POS_S               0

//*****************************************************************************
//
// The following are defines for the bit fields in the QEI_O_MAXPOS register.
//
//*****************************************************************************
#define QEI_MAXPOS_M            0xFFFFFFFF  // Maximum Position Integrator
                                            // Value
#define QEI_MAXPOS_S            0

//*****************************************************************************
//
// The following are defines for the bit fields in the QEI_O_LOAD register.
//
//*****************************************************************************
#define QEI_LOAD_M              0xFFFFFFFF  // Velocity Timer Load Value
#define QEI_LOAD_S              0

//*****************************************************************************
//
// The following are defines for the bit fields in the QEI_O_TIME register.
//
//*****************************************************************************
#define QEI_TIME_M              0xFFFFFFFF  // Velocity Timer Current Value
#define QEI_TIME_S              0

//*****************************************************************************
//
// The following are defines for the bit fields in the QEI_O_COUNT register.
//
//*****************************************************************************
#define QEI_COUNT_M             0xFFFFFFFF  // Velocity Pulse Count
#define QEI_COUNT_S             0

//*****************************************************************************
//
// The following are defines for the bit fields in the QEI_O_SPEED register.
//
//*****************************************************************************
#define QEI_SPEED_M             0xFFFFFFFF  // Velocity
#define QEI_SPEED_S             0

//*****************************************************************************
//
// The following are defines for the bit fields in the QEI_O_INTEN register.
//
//*****************************************************************************
#define QEI_INTEN_ERROR         0x00000008  // Phase Error Interrupt Enable
#define QEI_INTEN_DIR           0x00000004  // Direction Change Interrupt
                                            // Enable
#define QEI_INTEN_TIMER         0x00000002  // Timer Expires Interrupt Enable
#define QEI_INTEN_INDEX         0x00000001  // Index Pulse Detected Interrupt
                                            // Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the QEI_O_RIS register.
//
//*****************************************************************************
#define QEI_RIS_ERROR           0x00000008  // Phase Error Detected
#define QEI_RIS_DIR             0x00000004  // Direction Change Detected
#define QEI_RIS_TIMER           0x00000002  // Velocity Timer Expired
#define QEI_RIS_INDEX           0x00000001  // Index Pulse Asserted

//*****************************************************************************
//
// The following are defines for the bit fields in the QEI_O_ISC register.
//
//*****************************************************************************
#define QEI_ISC_ERROR           0x00000008  // Phase Error Interrupt
#define QEI_ISC_DIR             0x00000004  // Direction Change Interrupt
#define QEI_ISC_TIMER           0x00000002  // Velocity Timer Expired Interrupt
#define QEI_ISC_INDEX           0x00000001  // Index Pulse Interrupt

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_CFG register.
//
//*****************************************************************************
#define TIMER_CFG_M             0x00000007  // GPTM Configuration
#define TIMER_CFG_32_BIT_TIMER  0x00000000  // 32-bit timer configuration
#define TIMER_CFG_32_BIT_RTC    0x00000001  // 32-bit real-time clock (RTC)
                                            // counter configuration
#define TIMER_CFG_16_BIT        0x00000004  // 16-bit timer configuration. The
                                            // function is controlled by bits
                                            // 1:0 of GPTMTAMR and GPTMTBMR

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_TAMR register.
//
//*****************************************************************************
#define TIMER_TAMR_TCACT_M      0x0000E000  // Timer Compare Action Select
#define TIMER_TAMR_TCACT_NONE   0x00000000  // Disable compare operations
#define TIMER_TAMR_TCACT_TOGGLE 0x00002000  // Toggle State on Time-Out
#define TIMER_TAMR_TCACT_CLRTO  0x00004000  // Clear CCP on Time-Out
#define TIMER_TAMR_TCACT_SETTO  0x00006000  // Set CCP on Time-Out
#define TIMER_TAMR_TCACT_SETTOGTO                                             \
                                0x00008000  // Set CCP immediately and toggle
                                            // on Time-Out
#define TIMER_TAMR_TCACT_CLRTOGTO                                             \
                                0x0000A000  // Clear CCP immediately and toggle
                                            // on Time-Out
#define TIMER_TAMR_TCACT_SETCLRTO                                             \
                                0x0000C000  // Set CCP immediately and clear on
                                            // Time-Out
#define TIMER_TAMR_TCACT_CLRSETTO                                             \
                                0x0000E000  // Clear CCP immediately and set on
                                            // Time-Out
#define TIMER_TAMR_TACINTD      0x00001000  // One-shot/Periodic Interrupt Mode
#define TIMER_TAMR_TAPLO        0x00000800  // GPTM Timer A PWM Legacy
                                            // Operation
#define TIMER_TAMR_TAMRSU       0x00000400  // GPTM Timer A Match Register
                                            // Update
#define TIMER_TAMR_TAPWMIE      0x00000200  // GPTM Timer A PWM Interrupt
                                            // Enable
#define TIMER_TAMR_TAILD        0x00000100  // GPTM Timer A Interval Load Write
#define TIMER_TAMR_TASNAPS      0x00000080  // GPTM Timer A Snap-Shot Mode
#define TIMER_TAMR_TAWOT        0x00000040  // GPTM Timer A Wait-on-Trigger
#define TIMER_TAMR_TAMIE        0x00000020  // GPTM Timer A Match Interrupt
                                            // Enable
#define TIMER_TAMR_TACDIR       0x00000010  // GPTM Timer A Count Direction
#define TIMER_TAMR_TAAMS        0x00000008  // GPTM Timer A Alternate Mode
                                            // Select
#define TIMER_TAMR_TACMR        0x00000004  // GPTM Timer A Capture Mode
#define TIMER_TAMR_TAMR_M       0x00000003  // GPTM Timer A Mode
#define TIMER_TAMR_TAMR_1_SHOT  0x00000001  // One-Shot Timer mode
#define TIMER_TAMR_TAMR_PERIOD  0x00000002  // Periodic Timer mode
#define TIMER_TAMR_TAMR_CAP     0x00000003  // Capture mode

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_TBMR register.
//
//*****************************************************************************
#define TIMER_TBMR_TCACT_M      0x0000E000  // Timer Compare Action Select
#define TIMER_TBMR_TCACT_NONE   0x00000000  // Disable compare operations
#define TIMER_TBMR_TCACT_TOGGLE 0x00002000  // Toggle State on Time-Out
#define TIMER_TBMR_TCACT_CLRTO  0x00004000  // Clear CCP on Time-Out
#define TIMER_TBMR_TCACT_SETTO  0x00006000  // Set CCP on Time-Out
#define TIMER_TBMR_TCACT_SETTOGTO                                             \
                                0x00008000  // Set CCP immediately and toggle
                                            // on Time-Out
#define TIMER_TBMR_TCACT_CLRTOGTO                                             \
                                0x0000A000  // Clear CCP immediately and toggle
                                            // on Time-Out
#define TIMER_TBMR_TCACT_SETCLRTO                                             \
                                0x0000C000  // Set CCP immediately and clear on
                                            // Time-Out
#define TIMER_TBMR_TCACT_CLRSETTO                                             \
                                0x0000E000  // Clear CCP immediately and set on
                                            // Time-Out
#define TIMER_TBMR_TBCINTD      0x00001000  // One-Shot/Periodic Interrupt Mode
#define TIMER_TBMR_TBPLO        0x00000800  // GPTM Timer B PWM Legacy
                                            // Operation
#define TIMER_TBMR_TBMRSU       0x00000400  // GPTM Timer B Match Register
                                            // Update
#define TIMER_TBMR_TBPWMIE      0x00000200  // GPTM Timer B PWM Interrupt
                                            // Enable
#define TIMER_TBMR_TBILD        0x00000100  // GPTM Timer B Interval Load Write
#define TIMER_TBMR_TBSNAPS      0x00000080  // GPTM Timer B Snap-Shot Mode
#define TIMER_TBMR_TBWOT        0x00000040  // GPTM Timer B Wait-on-Trigger
#define TIMER_TBMR_TBMIE        0x00000020  // GPTM Timer B Match Interrupt
                                            // Enable
#define TIMER_TBMR_TBCDIR       0x00000010  // GPTM Timer B Count Direction
#define TIMER_TBMR_TBAMS        0x00000008  // GPTM Timer B Alternate Mode
                                            // Select
#define TIMER_TBMR_TBCMR        0x00000004  // GPTM Timer B Capture Mode
#define TIMER_TBMR_TBMR_M       0x00000003  // GPTM Timer B Mode
#define TIMER_TBMR_TBMR_1_SHOT  0x00000001  // One-Shot Timer mode
#define TIMER_TBMR_TBMR_PERIOD  0x00000002  // Periodic Timer mode
#define TIMER_TBMR_TBMR_CAP     0x00000003  // Capture mode

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_CTL register.
//
//*****************************************************************************
#define TIMER_CTL_TBPWML        0x00004000  // GPTM Timer B PWM Output Level
#define TIMER_CTL_TBOTE         0x00002000  // GPTM Timer B Output Trigger
                                            // Enable
#define TIMER_CTL_TBEVENT_M     0x00000C00  // GPTM Timer B Event Mode
#define TIMER_CTL_TBEVENT_POS   0x00000000  // Positive edge
#define TIMER_CTL_TBEVENT_NEG   0x00000400  // Negative edge
#define TIMER_CTL_TBEVENT_BOTH  0x00000C00  // Both edges
#define TIMER_CTL_TBSTALL       0x00000200  // GPTM Timer B Stall Enable
#define TIMER_CTL_TBEN          0x00000100  // GPTM Timer B Enable
#define TIMER_CTL_TAPWML        0x00000040  // GPTM Timer A PWM Output Level
#define TIMER_CTL_TAOTE         0x00000020  // GPTM Timer A Output Trigger
                                            // Enable
#define TIMER_CTL_RTCEN         0x00000010  // GPTM RTC Stall Enable
#define TIMER_CTL_TAEVENT_M     0x0000000C  // GPTM Timer A Event Mode
#define TIMER_CTL_TAEVENT_POS   0x00000000  // Positive edge
#define TIMER_CTL_TAEVENT_NEG   0x00000004  // Negative edge
#define TIMER_CTL_TAEVENT_BOTH  0x0000000C  // Both edges
#define TIMER_CTL_TASTALL       0x00000002  // GPTM Timer A Stall Enable
#define TIMER_CTL_TAEN          0x00000001  // GPTM Timer A Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_SYNC register.
//
//*****************************************************************************
#define TIMER_SYNC_SYNCT7_M     0x0000C000  // Synchronize GPTM Timer 7
#define TIMER_SYNC_SYNCT7_NONE  0x00000000  // GPT7 is not affected
#define TIMER_SYNC_SYNCT7_TA    0x00004000  // A timeout event for Timer A of
                                            // GPTM7 is triggered
#define TIMER_SYNC_SYNCT7_TB    0x00008000  // A timeout event for Timer B of
                                            // GPTM7 is triggered
#define TIMER_SYNC_SYNCT7_TATB  0x0000C000  // A timeout event for both Timer A
                                            // and Timer B of GPTM7 is
                                            // triggered
#define TIMER_SYNC_SYNCT6_M     0x00003000  // Synchronize GPTM Timer 6
#define TIMER_SYNC_SYNCT6_NONE  0x00000000  // GPTM6 is not affected
#define TIMER_SYNC_SYNCT6_TA    0x00001000  // A timeout event for Timer A of
                                            // GPTM6 is triggered
#define TIMER_SYNC_SYNCT6_TB    0x00002000  // A timeout event for Timer B of
                                            // GPTM6 is triggered
#define TIMER_SYNC_SYNCT6_TATB  0x00003000  // A timeout event for both Timer A
                                            // and Timer B of GPTM6 is
                                            // triggered
#define TIMER_SYNC_SYNCT5_M     0x00000C00  // Synchronize GPTM 16/32-Bit Timer
                                            // 5
#define TIMER_SYNC_SYNCT5_NONE  0x00000000  // GPTM 16/32-Bit Timer 5 is not
                                            // affected
#define TIMER_SYNC_SYNCT5_TA    0x00000400  // A timeout event for Timer A of
                                            // GPTM 16/32-Bit Timer 5 is
                                            // triggered
#define TIMER_SYNC_SYNCT5_TB    0x00000800  // A timeout event for Timer B of
                                            // GPTM 16/32-Bit Timer 5 is
                                            // triggered
#define TIMER_SYNC_SYNCT5_TATB  0x00000C00  // A timeout event for both Timer A
                                            // and Timer B of GPTM 16/32-Bit
                                            // Timer 5 is triggered
#define TIMER_SYNC_SYNCT4_M     0x00000300  // Synchronize GPTM 16/32-Bit Timer
                                            // 4
#define TIMER_SYNC_SYNCT4_NONE  0x00000000  // GPTM 16/32-Bit Timer 4 is not
                                            // affected
#define TIMER_SYNC_SYNCT4_TA    0x00000100  // A timeout event for Timer A of
                                            // GPTM 16/32-Bit Timer 4 is
                                            // triggered
#define TIMER_SYNC_SYNCT4_TB    0x00000200  // A timeout event for Timer B of
                                            // GPTM 16/32-Bit Timer 4 is
                                            // triggered
#define TIMER_SYNC_SYNCT4_TATB  0x00000300  // A timeout event for both Timer A
                                            // and Timer B of GPTM 16/32-Bit
                                            // Timer 4 is triggered
#define TIMER_SYNC_SYNCT3_M     0x000000C0  // Synchronize GPTM 16/32-Bit Timer
                                            // 3
#define TIMER_SYNC_SYNCT3_NONE  0x00000000  // GPTM 16/32-Bit Timer 3 is not
                                            // affected
#define TIMER_SYNC_SYNCT3_TA    0x00000040  // A timeout event for Timer A of
                                            // GPTM 16/32-Bit Timer 3 is
                                            // triggered
#define TIMER_SYNC_SYNCT3_TB    0x00000080  // A timeout event for Timer B of
                                            // GPTM 16/32-Bit Timer 3 is
                                            // triggered
#define TIMER_SYNC_SYNCT3_TATB  0x000000C0  // A timeout event for both Timer A
                                            // and Timer B of GPTM 16/32-Bit
                                            // Timer 3 is triggered
#define TIMER_SYNC_SYNCT2_M     0x00000030  // Synchronize GPTM 16/32-Bit Timer
                                            // 2
#define TIMER_SYNC_SYNCT2_NONE  0x00000000  // GPTM 16/32-Bit Timer 2 is not
                                            // affected
#define TIMER_SYNC_SYNCT2_TA    0x00000010  // A timeout event for Timer A of
                                            // GPTM 16/32-Bit Timer 2 is
                                            // triggered
#define TIMER_SYNC_SYNCT2_TB    0x00000020  // A timeout event for Timer B of
                                            // GPTM 16/32-Bit Timer 2 is
                                            // triggered
#define TIMER_SYNC_SYNCT2_TATB  0x00000030  // A timeout event for both Timer A
                                            // and Timer B of GPTM 16/32-Bit
                                            // Timer 2 is triggered
#define TIMER_SYNC_SYNCT1_M     0x0000000C  // Synchronize GPTM 16/32-Bit Timer
                                            // 1
#define TIMER_SYNC_SYNCT1_NONE  0x00000000  // GPTM 16/32-Bit Timer 1 is not
                                            // affected
#define TIMER_SYNC_SYNCT1_TA    0x00000004  // A timeout event for Timer A of
                                            // GPTM 16/32-Bit Timer 1 is
                                            // triggered
#define TIMER_SYNC_SYNCT1_TB    0x00000008  // A timeout event for Timer B of
                                            // GPTM 16/32-Bit Timer 1 is
                                            // triggered
#define TIMER_SYNC_SYNCT1_TATB  0x0000000C  // A timeout event for both Timer A
                                            // and Timer B of GPTM 16/32-Bit
                                            // Timer 1 is triggered
#define TIMER_SYNC_SYNCT0_M     0x00000003  // Synchronize GPTM 16/32-Bit Timer
                                            // 0
#define TIMER_SYNC_SYNCT0_NONE  0x00000000  // GPTM 16/32-Bit Timer 0 is not
                                            // affected
#define TIMER_SYNC_SYNCT0_TA    0x00000001  // A timeout event for Timer A of
                                            // GPTM 16/32-Bit Timer 0 is
                                            // triggered
#define TIMER_SYNC_SYNCT0_TB    0x00000002  // A timeout event for Timer B of
                                            // GPTM 16/32-Bit Timer 0 is
                                            // triggered
#define TIMER_SYNC_SYNCT0_TATB  0x00000003  // A timeout event for both Timer A
                                            // and Timer B of GPTM 16/32-Bit
                                            // Timer 0 is triggered

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_IMR register.
//
//*****************************************************************************
#define TIMER_IMR_DMABIM        0x00002000  // GPTM Timer B DMA Done Interrupt
                                            // Mask
#define TIMER_IMR_TBMIM         0x00000800  // GPTM Timer B Match Interrupt
                                            // Mask
#define TIMER_IMR_CBEIM         0x00000400  // GPTM Timer B Capture Mode Event
                                            // Interrupt Mask
#define TIMER_IMR_CBMIM         0x00000200  // GPTM Timer B Capture Mode Match
                                            // Interrupt Mask
#define TIMER_IMR_TBTOIM        0x00000100  // GPTM Timer B Time-Out Interrupt
                                            // Mask
#define TIMER_IMR_DMAAIM        0x00000020  // GPTM Timer A DMA Done Interrupt
                                            // Mask
#define TIMER_IMR_TAMIM         0x00000010  // GPTM Timer A Match Interrupt
                                            // Mask
#define TIMER_IMR_RTCIM         0x00000008  // GPTM RTC Interrupt Mask
#define TIMER_IMR_CAEIM         0x00000004  // GPTM Timer A Capture Mode Event
                                            // Interrupt Mask
#define TIMER_IMR_CAMIM         0x00000002  // GPTM Timer A Capture Mode Match
                                            // Interrupt Mask
#define TIMER_IMR_TATOIM        0x00000001  // GPTM Timer A Time-Out Interrupt
                                            // Mask

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_RIS register.
//
//*****************************************************************************
#define TIMER_RIS_DMABRIS       0x00002000  // GPTM Timer B DMA Done Raw
                                            // Interrupt Status
#define TIMER_RIS_TBMRIS        0x00000800  // GPTM Timer B Match Raw Interrupt
#define TIMER_RIS_CBERIS        0x00000400  // GPTM Timer B Capture Mode Event
                                            // Raw Interrupt
#define TIMER_RIS_CBMRIS        0x00000200  // GPTM Timer B Capture Mode Match
                                            // Raw Interrupt
#define TIMER_RIS_TBTORIS       0x00000100  // GPTM Timer B Time-Out Raw
                                            // Interrupt
#define TIMER_RIS_DMAARIS       0x00000020  // GPTM Timer A DMA Done Raw
                                            // Interrupt Status
#define TIMER_RIS_TAMRIS        0x00000010  // GPTM Timer A Match Raw Interrupt
#define TIMER_RIS_RTCRIS        0x00000008  // GPTM RTC Raw Interrupt
#define TIMER_RIS_CAERIS        0x00000004  // GPTM Timer A Capture Mode Event
                                            // Raw Interrupt
#define TIMER_RIS_CAMRIS        0x00000002  // GPTM Timer A Capture Mode Match
                                            // Raw Interrupt
#define TIMER_RIS_TATORIS       0x00000001  // GPTM Timer A Time-Out Raw
                                            // Interrupt

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_MIS register.
//
//*****************************************************************************
#define TIMER_MIS_DMABMIS       0x00002000  // GPTM Timer B DMA Done Masked
                                            // Interrupt
#define TIMER_MIS_TBMMIS        0x00000800  // GPTM Timer B Match Masked
                                            // Interrupt
#define TIMER_MIS_CBEMIS        0x00000400  // GPTM Timer B Capture Mode Event
                                            // Masked Interrupt
#define TIMER_MIS_CBMMIS        0x00000200  // GPTM Timer B Capture Mode Match
                                            // Masked Interrupt
#define TIMER_MIS_TBTOMIS       0x00000100  // GPTM Timer B Time-Out Masked
                                            // Interrupt
#define TIMER_MIS_DMAAMIS       0x00000020  // GPTM Timer A DMA Done Masked
                                            // Interrupt
#define TIMER_MIS_TAMMIS        0x00000010  // GPTM Timer A Match Masked
                                            // Interrupt
#define TIMER_MIS_RTCMIS        0x00000008  // GPTM RTC Masked Interrupt
#define TIMER_MIS_CAEMIS        0x00000004  // GPTM Timer A Capture Mode Event
                                            // Masked Interrupt
#define TIMER_MIS_CAMMIS        0x00000002  // GPTM Timer A Capture Mode Match
                                            // Masked Interrupt
#define TIMER_MIS_TATOMIS       0x00000001  // GPTM Timer A Time-Out Masked
                                            // Interrupt

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_ICR register.
//
//*****************************************************************************
#define TIMER_ICR_DMABINT       0x00002000  // GPTM Timer B DMA Done Interrupt
                                            // Clear
#define TIMER_ICR_TBMCINT       0x00000800  // GPTM Timer B Match Interrupt
                                            // Clear
#define TIMER_ICR_CBECINT       0x00000400  // GPTM Timer B Capture Mode Event
                                            // Interrupt Clear
#define TIMER_ICR_CBMCINT       0x00000200  // GPTM Timer B Capture Mode Match
                                            // Interrupt Clear
#define TIMER_ICR_TBTOCINT      0x00000100  // GPTM Timer B Time-Out Interrupt
                                            // Clear
#define TIMER_ICR_DMAAINT       0x00000020  // GPTM Timer A DMA Done Interrupt
                                            // Clear
#define TIMER_ICR_TAMCINT       0x00000010  // GPTM Timer A Match Interrupt
                                            // Clear
#define TIMER_ICR_RTCCINT       0x00000008  // GPTM RTC Interrupt Clear
#define TIMER_ICR_CAECINT       0x00000004  // GPTM Timer A Capture Mode Event
                                            // Interrupt Clear
#define TIMER_ICR_CAMCINT       0x00000002  // GPTM Timer A Capture Mode Match
                                            // Interrupt Clear
#define TIMER_ICR_TATOCINT      0x00000001  // GPTM Timer A Time-Out Raw
                                            // Interrupt

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_TAILR register.
//
//*****************************************************************************
#define TIMER_TAILR_M           0xFFFFFFFF  // GPTM Timer A Interval Load
                                            // Register
#define TIMER_TAILR_S           0

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_TBILR register.
//
//*****************************************************************************
#define TIMER_TBILR_M           0xFFFFFFFF  // GPTM Timer B Interval Load
                                            // Register
#define TIMER_TBILR_S           0

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_TAMATCHR
// register.
//
//*****************************************************************************
#define TIMER_TAMATCHR_TAMR_M   0xFFFFFFFF  // GPTM Timer A Match Register
#define TIMER_TAMATCHR_TAMR_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_TBMATCHR
// register.
//
//*****************************************************************************
#define TIMER_TBMATCHR_TBMR_M   0xFFFFFFFF  // GPTM Timer B Match Register
#define TIMER_TBMATCHR_TBMR_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_TAPR register.
//
//*****************************************************************************
#define TIMER_TAPR_TAPSR_M      0x000000FF  // GPTM Timer A Prescale
#define TIMER_TAPR_TAPSR_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_TBPR register.
//
//*****************************************************************************
#define TIMER_TBPR_TBPSR_M      0x000000FF  // GPTM Timer B Prescale
#define TIMER_TBPR_TBPSR_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_TAPMR register.
//
//*****************************************************************************
#define TIMER_TAPMR_TAPSMR_M    0x000000FF  // GPTM TimerA Prescale Match
#define TIMER_TAPMR_TAPSMR_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_TBPMR register.
//
//*****************************************************************************
#define TIMER_TBPMR_TBPSMR_M    0x000000FF  // GPTM TimerB Prescale Match
#define TIMER_TBPMR_TBPSMR_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_TAR register.
//
//*****************************************************************************
#define TIMER_TAR_M             0xFFFFFFFF  // GPTM Timer A Register
#define TIMER_TAR_S             0

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_TBR register.
//
//*****************************************************************************
#define TIMER_TBR_M             0xFFFFFFFF  // GPTM Timer B Register
#define TIMER_TBR_S             0

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_TAV register.
//
//*****************************************************************************
#define TIMER_TAV_M             0xFFFFFFFF  // GPTM Timer A Value
#define TIMER_TAV_S             0

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_TBV register.
//
//*****************************************************************************
#define TIMER_TBV_M             0xFFFFFFFF  // GPTM Timer B Value
#define TIMER_TBV_S             0

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_RTCPD register.
//
//*****************************************************************************
#define TIMER_RTCPD_RTCPD_M     0x0000FFFF  // RTC Predivide Counter Value
#define TIMER_RTCPD_RTCPD_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_TAPS register.
//
//*****************************************************************************
#define TIMER_TAPS_PSS_M        0x0000FFFF  // GPTM Timer A Prescaler Snapshot
#define TIMER_TAPS_PSS_S        0

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_TBPS register.
//
//*****************************************************************************
#define TIMER_TBPS_PSS_M        0x0000FFFF  // GPTM Timer A Prescaler Value
#define TIMER_TBPS_PSS_S        0

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_DMAEV register.
//
//*****************************************************************************
#define TIMER_DMAEV_TBMDMAEN    0x00000800  // GPTM Timer B Mode Match DMA
                                            // Trigger Enable
#define TIMER_DMAEV_CBEDMAEN    0x00000400  // GPTM Capture B Event DMA Trigger
                                            // Enable
#define TIMER_DMAEV_CBMDMAEN    0x00000200  // GPTM Capture B Match DMA Trigger
                                            // Enable
#define TIMER_DMAEV_TBTODMAEN   0x00000100  // GPTM Timer B Time-Out DMA
                                            // Trigger Enable
#define TIMER_DMAEV_TAMDMAEN    0x00000010  // GPTM Timer A Mode Match DMA
                                            // Trigger Enable
#define TIMER_DMAEV_RTCDMAEN    0x00000008  // GPTM RTC DMA Trigger Enable
#define TIMER_DMAEV_CAEDMAEN    0x00000004  // GPTM Capture A Event DMA Trigger
                                            // Enable
#define TIMER_DMAEV_CAMDMAEN    0x00000002  // GPTM Capture A Match DMA Trigger
                                            // Enable
#define TIMER_DMAEV_TATODMAEN   0x00000001  // GPTM Timer A Time-Out DMA
                                            // Trigger Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_ADCEV register.
//
//*****************************************************************************
#define TIMER_ADCEV_TBMADCEN    0x00000800  // GPTM Timer B Mode Match ADC
                                            // Trigger Enable
#define TIMER_ADCEV_CBEADCEN    0x00000400  // GPTM Capture B Event ADC Trigger
                                            // Enable
#define TIMER_ADCEV_CBMADCEN    0x00000200  // GPTM Capture B Match ADC Trigger
                                            // Enable
#define TIMER_ADCEV_TBTOADCEN   0x00000100  // GPTM Timer B Time-Out ADC
                                            // Trigger Enable
#define TIMER_ADCEV_TAMADCEN    0x00000010  // GPTM Timer A Mode Match ADC
                                            // Trigger Enable
#define TIMER_ADCEV_RTCADCEN    0x00000008  // GPTM RTC ADC Trigger Enable
#define TIMER_ADCEV_CAEADCEN    0x00000004  // GPTM Capture A Event ADC Trigger
                                            // Enable
#define TIMER_ADCEV_CAMADCEN    0x00000002  // GPTM Capture A Match ADC Trigger
                                            // Enable
#define TIMER_ADCEV_TATOADCEN   0x00000001  // GPTM Timer A Time-Out ADC
                                            // Trigger Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_PP register.
//
//*****************************************************************************
#define TIMER_PP_ALTCLK         0x00000040  // Alternate Clock Source
#define TIMER_PP_SYNCCNT        0x00000020  // Synchronize Start
#define TIMER_PP_CHAIN          0x00000010  // Chain with Other Timers
#define TIMER_PP_SIZE_M         0x0000000F  // Count Size
#define TIMER_PP_SIZE_16        0x00000000  // Timer A and Timer B counters are
                                            // 16 bits each with an 8-bit
                                            // prescale counter
#define TIMER_PP_SIZE_32        0x00000001  // Timer A and Timer B counters are
                                            // 32 bits each with a 16-bit
                                            // prescale counter

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_CC register.
//
//*****************************************************************************
#define TIMER_CC_ALTCLK         0x00000001  // Alternate Clock Source

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_ACTSS register.
//
//*****************************************************************************
#define ADC_ACTSS_BUSY          0x00010000  // ADC Busy
#define ADC_ACTSS_ADEN3         0x00000800  // ADC SS3 DMA Enable
#define ADC_ACTSS_ADEN2         0x00000400  // ADC SS2 DMA Enable
#define ADC_ACTSS_ADEN1         0x00000200  // ADC SS1 DMA Enable
#define ADC_ACTSS_ADEN0         0x00000100  // ADC SS1 DMA Enable
#define ADC_ACTSS_ASEN3         0x00000008  // ADC SS3 Enable
#define ADC_ACTSS_ASEN2         0x00000004  // ADC SS2 Enable
#define ADC_ACTSS_ASEN1         0x00000002  // ADC SS1 Enable
#define ADC_ACTSS_ASEN0         0x00000001  // ADC SS0 Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_RIS register.
//
//*****************************************************************************
#define ADC_RIS_INRDC           0x00010000  // Digital Comparator Raw Interrupt
                                            // Status
#define ADC_RIS_DMAINR3         0x00000800  // SS3 DMA Raw Interrupt Status
#define ADC_RIS_DMAINR2         0x00000400  // SS2 DMA Raw Interrupt Status
#define ADC_RIS_DMAINR1         0x00000200  // SS1 DMA Raw Interrupt Status
#define ADC_RIS_DMAINR0         0x00000100  // SS0 DMA Raw Interrupt Status
#define ADC_RIS_INR3            0x00000008  // SS3 Raw Interrupt Status
#define ADC_RIS_INR2            0x00000004  // SS2 Raw Interrupt Status
#define ADC_RIS_INR1            0x00000002  // SS1 Raw Interrupt Status
#define ADC_RIS_INR0            0x00000001  // SS0 Raw Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_IM register.
//
//*****************************************************************************
#define ADC_IM_DCONSS3          0x00080000  // Digital Comparator Interrupt on
                                            // SS3
#define ADC_IM_DCONSS2          0x00040000  // Digital Comparator Interrupt on
                                            // SS2
#define ADC_IM_DCONSS1          0x00020000  // Digital Comparator Interrupt on
                                            // SS1
#define ADC_IM_DCONSS0          0x00010000  // Digital Comparator Interrupt on
                                            // SS0
#define ADC_IM_DMAMASK3         0x00000800  // SS3 DMA Interrupt Mask
#define ADC_IM_DMAMASK2         0x00000400  // SS2 DMA Interrupt Mask
#define ADC_IM_DMAMASK1         0x00000200  // SS1 DMA Interrupt Mask
#define ADC_IM_DMAMASK0         0x00000100  // SS0 DMA Interrupt Mask
#define ADC_IM_MASK3            0x00000008  // SS3 Interrupt Mask
#define ADC_IM_MASK2            0x00000004  // SS2 Interrupt Mask
#define ADC_IM_MASK1            0x00000002  // SS1 Interrupt Mask
#define ADC_IM_MASK0            0x00000001  // SS0 Interrupt Mask

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_ISC register.
//
//*****************************************************************************
#define ADC_ISC_DCINSS3         0x00080000  // Digital Comparator Interrupt
                                            // Status on SS3
#define ADC_ISC_DCINSS2         0x00040000  // Digital Comparator Interrupt
                                            // Status on SS2
#define ADC_ISC_DCINSS1         0x00020000  // Digital Comparator Interrupt
                                            // Status on SS1
#define ADC_ISC_DCINSS0         0x00010000  // Digital Comparator Interrupt
                                            // Status on SS0
#define ADC_ISC_DMAIN3          0x00000800  // SS3 DMA Interrupt Status and
                                            // Clear
#define ADC_ISC_DMAIN2          0x00000400  // SS2 DMA Interrupt Status and
                                            // Clear
#define ADC_ISC_DMAIN1          0x00000200  // SS1 DMA Interrupt Status and
                                            // Clear
#define ADC_ISC_DMAIN0          0x00000100  // SS0 DMA Interrupt Status and
                                            // Clear
#define ADC_ISC_IN3             0x00000008  // SS3 Interrupt Status and Clear
#define ADC_ISC_IN2             0x00000004  // SS2 Interrupt Status and Clear
#define ADC_ISC_IN1             0x00000002  // SS1 Interrupt Status and Clear
#define ADC_ISC_IN0             0x00000001  // SS0 Interrupt Status and Clear

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_OSTAT register.
//
//*****************************************************************************
#define ADC_OSTAT_OV3           0x00000008  // SS3 FIFO Overflow
#define ADC_OSTAT_OV2           0x00000004  // SS2 FIFO Overflow
#define ADC_OSTAT_OV1           0x00000002  // SS1 FIFO Overflow
#define ADC_OSTAT_OV0           0x00000001  // SS0 FIFO Overflow

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_EMUX register.
//
//*****************************************************************************
#define ADC_EMUX_EM3_M          0x0000F000  // SS3 Trigger Select
#define ADC_EMUX_EM3_PROCESSOR  0x00000000  // Processor (default)
#define ADC_EMUX_EM3_COMP0      0x00001000  // Analog Comparator 0
#define ADC_EMUX_EM3_COMP1      0x00002000  // Analog Comparator 1
#define ADC_EMUX_EM3_COMP2      0x00003000  // Analog Comparator 2
#define ADC_EMUX_EM3_EXTERNAL   0x00004000  // External (GPIO PB4)
#define ADC_EMUX_EM3_TIMER      0x00005000  // Timer
#define ADC_EMUX_EM3_PWM0       0x00006000  // PWM0
#define ADC_EMUX_EM3_PWM1       0x00007000  // PWM1
#define ADC_EMUX_EM3_PWM2       0x00008000  // PWM2
#define ADC_EMUX_EM3_PWM3       0x00009000  // PWM3
#define ADC_EMUX_EM3_NEVER      0x0000E000  // Never Trigger
#define ADC_EMUX_EM3_ALWAYS     0x0000F000  // Always (continuously sample)
#define ADC_EMUX_EM2_M          0x00000F00  // SS2 Trigger Select
#define ADC_EMUX_EM2_PROCESSOR  0x00000000  // Processor (default)
#define ADC_EMUX_EM2_COMP0      0x00000100  // Analog Comparator 0
#define ADC_EMUX_EM2_COMP1      0x00000200  // Analog Comparator 1
#define ADC_EMUX_EM2_COMP2      0x00000300  // Analog Comparator 2
#define ADC_EMUX_EM2_EXTERNAL   0x00000400  // External (GPIO PB4)
#define ADC_EMUX_EM2_TIMER      0x00000500  // Timer
#define ADC_EMUX_EM2_PWM0       0x00000600  // PWM0
#define ADC_EMUX_EM2_PWM1       0x00000700  // PWM1
#define ADC_EMUX_EM2_PWM2       0x00000800  // PWM2
#define ADC_EMUX_EM2_PWM3       0x00000900  // PWM3
#define ADC_EMUX_EM2_NEVER      0x00000E00  // Never Trigger
#define ADC_EMUX_EM2_ALWAYS     0x00000F00  // Always (continuously sample)
#define ADC_EMUX_EM1_M          0x000000F0  // SS1 Trigger Select
#define ADC_EMUX_EM1_PROCESSOR  0x00000000  // Processor (default)
#define ADC_EMUX_EM1_COMP0      0x00000010  // Analog Comparator 0
#define ADC_EMUX_EM1_COMP1      0x00000020  // Analog Comparator 1
#define ADC_EMUX_EM1_COMP2      0x00000030  // Analog Comparator 2
#define ADC_EMUX_EM1_EXTERNAL   0x00000040  // External (GPIO PB4)
#define ADC_EMUX_EM1_TIMER      0x00000050  // Timer
#define ADC_EMUX_EM1_PWM0       0x00000060  // PWM0
#define ADC_EMUX_EM1_PWM1       0x00000070  // PWM1
#define ADC_EMUX_EM1_PWM2       0x00000080  // PWM2
#define ADC_EMUX_EM1_PWM3       0x00000090  // PWM3
#define ADC_EMUX_EM1_NEVER      0x000000E0  // Never Trigger
#define ADC_EMUX_EM1_ALWAYS     0x000000F0  // Always (continuously sample)
#define ADC_EMUX_EM0_M          0x0000000F  // SS0 Trigger Select
#define ADC_EMUX_EM0_PROCESSOR  0x00000000  // Processor (default)
#define ADC_EMUX_EM0_COMP0      0x00000001  // Analog Comparator 0
#define ADC_EMUX_EM0_COMP1      0x00000002  // Analog Comparator 1
#define ADC_EMUX_EM0_COMP2      0x00000003  // Analog Comparator 2
#define ADC_EMUX_EM0_EXTERNAL   0x00000004  // External (GPIO PB4)
#define ADC_EMUX_EM0_TIMER      0x00000005  // Timer
#define ADC_EMUX_EM0_PWM0       0x00000006  // PWM0
#define ADC_EMUX_EM0_PWM1       0x00000007  // PWM1
#define ADC_EMUX_EM0_PWM2       0x00000008  // PWM2
#define ADC_EMUX_EM0_PWM3       0x00000009  // PWM3
#define ADC_EMUX_EM0_NEVER      0x0000000E  // Never Trigger
#define ADC_EMUX_EM0_ALWAYS     0x0000000F  // Always (continuously sample)

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_USTAT register.
//
//*****************************************************************************
#define ADC_USTAT_UV3           0x00000008  // SS3 FIFO Underflow
#define ADC_USTAT_UV2           0x00000004  // SS2 FIFO Underflow
#define ADC_USTAT_UV1           0x00000002  // SS1 FIFO Underflow
#define ADC_USTAT_UV0           0x00000001  // SS0 FIFO Underflow

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_TSSEL register.
//
//*****************************************************************************
#define ADC_TSSEL_PS3_M         0x30000000  // PWM Unit Select
#define ADC_TSSEL_PS3_0         0x00000000  // PWM Unit 0
#define ADC_TSSEL_PS2_M         0x00300000  // PWM Unit Select
#define ADC_TSSEL_PS2_0         0x00000000  // PWM Unit 0
#define ADC_TSSEL_PS1_M         0x00003000  // PWM Unit Select
#define ADC_TSSEL_PS1_0         0x00000000  // PWM Unit 0
#define ADC_TSSEL_PS0_M         0x00000030  // PWM Unit Select
#define ADC_TSSEL_PS0_0         0x00000000  // PWM Unit 0

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_SSPRI register.
//
//*****************************************************************************
#define ADC_SSPRI_SS3_M         0x00003000  // SS3 Priority
#define ADC_SSPRI_SS2_M         0x00000300  // SS2 Priority
#define ADC_SSPRI_SS1_M         0x00000030  // SS1 Priority
#define ADC_SSPRI_SS0_M         0x00000003  // SS0 Priority

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_SPC register.
//
//*****************************************************************************
#define ADC_SPC_PHASE_M         0x0000000F  // Phase Difference
#define ADC_SPC_PHASE_0         0x00000000  // ADC sample lags by 0.0
#define ADC_SPC_PHASE_22_5      0x00000001  // ADC sample lags by 22.5
#define ADC_SPC_PHASE_45        0x00000002  // ADC sample lags by 45.0
#define ADC_SPC_PHASE_67_5      0x00000003  // ADC sample lags by 67.5
#define ADC_SPC_PHASE_90        0x00000004  // ADC sample lags by 90.0
#define ADC_SPC_PHASE_112_5     0x00000005  // ADC sample lags by 112.5
#define ADC_SPC_PHASE_135       0x00000006  // ADC sample lags by 135.0
#define ADC_SPC_PHASE_157_5     0x00000007  // ADC sample lags by 157.5
#define ADC_SPC_PHASE_180       0x00000008  // ADC sample lags by 180.0
#define ADC_SPC_PHASE_202_5     0x00000009  // ADC sample lags by 202.5
#define ADC_SPC_PHASE_225       0x0000000A  // ADC sample lags by 225.0
#define ADC_SPC_PHASE_247_5     0x0000000B  // ADC sample lags by 247.5
#define ADC_SPC_PHASE_270       0x0000000C  // ADC sample lags by 270.0
#define ADC_SPC_PHASE_292_5     0x0000000D  // ADC sample lags by 292.5
#define ADC_SPC_PHASE_315       0x0000000E  // ADC sample lags by 315.0
#define ADC_SPC_PHASE_337_5     0x0000000F  // ADC sample lags by 337.5

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_PSSI register.
//
//*****************************************************************************
#define ADC_PSSI_GSYNC          0x80000000  // Global Synchronize
#define ADC_PSSI_SYNCWAIT       0x08000000  // Synchronize Wait
#define ADC_PSSI_SS3            0x00000008  // SS3 Initiate
#define ADC_PSSI_SS2            0x00000004  // SS2 Initiate
#define ADC_PSSI_SS1            0x00000002  // SS1 Initiate
#define ADC_PSSI_SS0            0x00000001  // SS0 Initiate

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_SAC register.
//
//*****************************************************************************
#define ADC_SAC_AVG_M           0x00000007  // Hardware Averaging Control
#define ADC_SAC_AVG_OFF         0x00000000  // No hardware oversampling
#define ADC_SAC_AVG_2X          0x00000001  // 2x hardware oversampling
#define ADC_SAC_AVG_4X          0x00000002  // 4x hardware oversampling
#define ADC_SAC_AVG_8X          0x00000003  // 8x hardware oversampling
#define ADC_SAC_AVG_16X         0x00000004  // 16x hardware oversampling
#define ADC_SAC_AVG_32X         0x00000005  // 32x hardware oversampling
#define ADC_SAC_AVG_64X         0x00000006  // 64x hardware oversampling

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_DCISC register.
//
//*****************************************************************************
#define ADC_DCISC_DCINT7        0x00000080  // Digital Comparator 7 Interrupt
                                            // Status and Clear
#define ADC_DCISC_DCINT6        0x00000040  // Digital Comparator 6 Interrupt
                                            // Status and Clear
#define ADC_DCISC_DCINT5        0x00000020  // Digital Comparator 5 Interrupt
                                            // Status and Clear
#define ADC_DCISC_DCINT4        0x00000010  // Digital Comparator 4 Interrupt
                                            // Status and Clear
#define ADC_DCISC_DCINT3        0x00000008  // Digital Comparator 3 Interrupt
                                            // Status and Clear
#define ADC_DCISC_DCINT2        0x00000004  // Digital Comparator 2 Interrupt
                                            // Status and Clear
#define ADC_DCISC_DCINT1        0x00000002  // Digital Comparator 1 Interrupt
                                            // Status and Clear
#define ADC_DCISC_DCINT0        0x00000001  // Digital Comparator 0 Interrupt
                                            // Status and Clear

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_CTL register.
//
//*****************************************************************************
#define ADC_CTL_DITHER          0x00000040  // Dither Mode Enable
#define ADC_CTL_VREF_M          0x00000003  // Voltage Reference Select
#define ADC_CTL_VREF_INTERNAL   0x00000000  // The internal reference as the
                                            // voltage reference
#define ADC_CTL_VREF_EXT_3V     0x00000001  // A 3.0 V external VREFA input is
                                            // the voltage reference. The ADC
                                            // conversion range is 0.0 V to the
                                            // external reference value

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_SSMUX0 register.
//
//*****************************************************************************
#define ADC_SSMUX0_MUX7_M       0xF0000000  // 8th Sample Input Select
#define ADC_SSMUX0_MUX6_M       0x0F000000  // 7th Sample Input Select
#define ADC_SSMUX0_MUX5_M       0x00F00000  // 6th Sample Input Select
#define ADC_SSMUX0_MUX4_M       0x000F0000  // 5th Sample Input Select
#define ADC_SSMUX0_MUX3_M       0x0000F000  // 4th Sample Input Select
#define ADC_SSMUX0_MUX2_M       0x00000F00  // 3rd Sample Input Select
#define ADC_SSMUX0_MUX1_M       0x000000F0  // 2nd Sample Input Select
#define ADC_SSMUX0_MUX0_M       0x0000000F  // 1st Sample Input Select
#define ADC_SSMUX0_MUX7_S       28
#define ADC_SSMUX0_MUX6_S       24
#define ADC_SSMUX0_MUX5_S       20
#define ADC_SSMUX0_MUX4_S       16
#define ADC_SSMUX0_MUX3_S       12
#define ADC_SSMUX0_MUX2_S       8
#define ADC_SSMUX0_MUX1_S       4
#define ADC_SSMUX0_MUX0_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_SSCTL0 register.
//
//*****************************************************************************
#define ADC_SSCTL0_TS7          0x80000000  // 8th Sample Temp Sensor Select
#define ADC_SSCTL0_IE7          0x40000000  // 8th Sample Interrupt Enable
#define ADC_SSCTL0_END7         0x20000000  // 8th Sample is End of Sequence
#define ADC_SSCTL0_D7           0x10000000  // 8th Sample Diff Input Select
#define ADC_SSCTL0_TS6          0x08000000  // 7th Sample Temp Sensor Select
#define ADC_SSCTL0_IE6          0x04000000  // 7th Sample Interrupt Enable
#define ADC_SSCTL0_END6         0x02000000  // 7th Sample is End of Sequence
#define ADC_SSCTL0_D6           0x01000000  // 7th Sample Diff Input Select
#define ADC_SSCTL0_TS5          0x00800000  // 6th Sample Temp Sensor Select
#define ADC_SSCTL0_IE5          0x00400000  // 6th Sample Interrupt Enable
#define ADC_SSCTL0_END5         0x00200000  // 6th Sample is End of Sequence
#define ADC_SSCTL0_D5           0x00100000  // 6th Sample Diff Input Select
#define ADC_SSCTL0_TS4          0x00080000  // 5th Sample Temp Sensor Select
#define ADC_SSCTL0_IE4          0x00040000  // 5th Sample Interrupt Enable
#define ADC_SSCTL0_END4         0x00020000  // 5th Sample is End of Sequence
#define ADC_SSCTL0_D4           0x00010000  // 5th Sample Diff Input Select
#define ADC_SSCTL0_TS3          0x00008000  // 4th Sample Temp Sensor Select
#define ADC_SSCTL0_IE3          0x00004000  // 4th Sample Interrupt Enable
#define ADC_SSCTL0_END3         0x00002000  // 4th Sample is End of Sequence
#define ADC_SSCTL0_D3           0x00001000  // 4th Sample Diff Input Select
#define ADC_SSCTL0_TS2          0x00000800  // 3rd Sample Temp Sensor Select
#define ADC_SSCTL0_IE2          0x00000400  // 3rd Sample Interrupt Enable
#define ADC_SSCTL0_END2         0x00000200  // 3rd Sample is End of Sequence
#define ADC_SSCTL0_D2           0x00000100  // 3rd Sample Diff Input Select
#define ADC_SSCTL0_TS1          0x00000080  // 2nd Sample Temp Sensor Select
#define ADC_SSCTL0_IE1          0x00000040  // 2nd Sample Interrupt Enable
#define ADC_SSCTL0_END1         0x00000020  // 2nd Sample is End of Sequence
#define ADC_SSCTL0_D1           0x00000010  // 2nd Sample Diff Input Select
#define ADC_SSCTL0_TS0          0x00000008  // 1st Sample Temp Sensor Select
#define ADC_SSCTL0_IE0          0x00000004  // 1st Sample Interrupt Enable
#define ADC_SSCTL0_END0         0x00000002  // 1st Sample is End of Sequence
#define ADC_SSCTL0_D0           0x00000001  // 1st Sample Diff Input Select

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_SSFIFO0 register.
//
//*****************************************************************************
#define ADC_SSFIFO0_DATA_M      0x00000FFF  // Conversion Result Data
#define ADC_SSFIFO0_DATA_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_SSFSTAT0 register.
//
//*****************************************************************************
#define ADC_SSFSTAT0_FULL       0x00001000  // FIFO Full
#define ADC_SSFSTAT0_EMPTY      0x00000100  // FIFO Empty
#define ADC_SSFSTAT0_HPTR_M     0x000000F0  // FIFO Head Pointer
#define ADC_SSFSTAT0_TPTR_M     0x0000000F  // FIFO Tail Pointer
#define ADC_SSFSTAT0_HPTR_S     4
#define ADC_SSFSTAT0_TPTR_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_SSOP0 register.
//
//*****************************************************************************
#define ADC_SSOP0_S7DCOP        0x10000000  // Sample 7 Digital Comparator
                                            // Operation
#define ADC_SSOP0_S6DCOP        0x01000000  // Sample 6 Digital Comparator
                                            // Operation
#define ADC_SSOP0_S5DCOP        0x00100000  // Sample 5 Digital Comparator
                                            // Operation
#define ADC_SSOP0_S4DCOP        0x00010000  // Sample 4 Digital Comparator
                                            // Operation
#define ADC_SSOP0_S3DCOP        0x00001000  // Sample 3 Digital Comparator
                                            // Operation
#define ADC_SSOP0_S2DCOP        0x00000100  // Sample 2 Digital Comparator
                                            // Operation
#define ADC_SSOP0_S1DCOP        0x00000010  // Sample 1 Digital Comparator
                                            // Operation
#define ADC_SSOP0_S0DCOP        0x00000001  // Sample 0 Digital Comparator
                                            // Operation

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_SSDC0 register.
//
//*****************************************************************************
#define ADC_SSDC0_S7DCSEL_M     0xF0000000  // Sample 7 Digital Comparator
                                            // Select
#define ADC_SSDC0_S6DCSEL_M     0x0F000000  // Sample 6 Digital Comparator
                                            // Select
#define ADC_SSDC0_S5DCSEL_M     0x00F00000  // Sample 5 Digital Comparator
                                            // Select
#define ADC_SSDC0_S4DCSEL_M     0x000F0000  // Sample 4 Digital Comparator
                                            // Select
#define ADC_SSDC0_S3DCSEL_M     0x0000F000  // Sample 3 Digital Comparator
                                            // Select
#define ADC_SSDC0_S2DCSEL_M     0x00000F00  // Sample 2 Digital Comparator
                                            // Select
#define ADC_SSDC0_S1DCSEL_M     0x000000F0  // Sample 1 Digital Comparator
                                            // Select
#define ADC_SSDC0_S0DCSEL_M     0x0000000F  // Sample 0 Digital Comparator
                                            // Select
#define ADC_SSDC0_S6DCSEL_S     24
#define ADC_SSDC0_S5DCSEL_S     20
#define ADC_SSDC0_S4DCSEL_S     16
#define ADC_SSDC0_S3DCSEL_S     12
#define ADC_SSDC0_S2DCSEL_S     8
#define ADC_SSDC0_S1DCSEL_S     4
#define ADC_SSDC0_S0DCSEL_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_SSEMUX0 register.
//
//*****************************************************************************
#define ADC_SSEMUX0_EMUX7       0x10000000  // 8th Sample Input Select (Upper
                                            // Bit)
#define ADC_SSEMUX0_EMUX6       0x01000000  // 7th Sample Input Select (Upper
                                            // Bit)
#define ADC_SSEMUX0_EMUX5       0x00100000  // 6th Sample Input Select (Upper
                                            // Bit)
#define ADC_SSEMUX0_EMUX4       0x00010000  // 5th Sample Input Select (Upper
                                            // Bit)
#define ADC_SSEMUX0_EMUX3       0x00001000  // 4th Sample Input Select (Upper
                                            // Bit)
#define ADC_SSEMUX0_EMUX2       0x00000100  // 3rd Sample Input Select (Upper
                                            // Bit)
#define ADC_SSEMUX0_EMUX1       0x00000010  // 2th Sample Input Select (Upper
                                            // Bit)
#define ADC_SSEMUX0_EMUX0       0x00000001  // 1st Sample Input Select (Upper
                                            // Bit)

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_SSTSH0 register.
//
//*****************************************************************************
#define ADC_SSTSH0_TSH7_M       0xF0000000  // 8th Sample and Hold Period
                                            // Select
#define ADC_SSTSH0_TSH6_M       0x0F000000  // 7th Sample and Hold Period
                                            // Select
#define ADC_SSTSH0_TSH5_M       0x00F00000  // 6th Sample and Hold Period
                                            // Select
#define ADC_SSTSH0_TSH4_M       0x000F0000  // 5th Sample and Hold Period
                                            // Select
#define ADC_SSTSH0_TSH3_M       0x0000F000  // 4th Sample and Hold Period
                                            // Select
#define ADC_SSTSH0_TSH2_M       0x00000F00  // 3rd Sample and Hold Period
                                            // Select
#define ADC_SSTSH0_TSH1_M       0x000000F0  // 2nd Sample and Hold Period
                                            // Select
#define ADC_SSTSH0_TSH0_M       0x0000000F  // 1st Sample and Hold Period
                                            // Select
#define ADC_SSTSH0_TSH7_S       28
#define ADC_SSTSH0_TSH6_S       24
#define ADC_SSTSH0_TSH5_S       20
#define ADC_SSTSH0_TSH4_S       16
#define ADC_SSTSH0_TSH3_S       12
#define ADC_SSTSH0_TSH2_S       8
#define ADC_SSTSH0_TSH1_S       4
#define ADC_SSTSH0_TSH0_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_SSMUX1 register.
//
//*****************************************************************************
#define ADC_SSMUX1_MUX3_M       0x0000F000  // 4th Sample Input Select
#define ADC_SSMUX1_MUX2_M       0x00000F00  // 3rd Sample Input Select
#define ADC_SSMUX1_MUX1_M       0x000000F0  // 2nd Sample Input Select
#define ADC_SSMUX1_MUX0_M       0x0000000F  // 1st Sample Input Select
#define ADC_SSMUX1_MUX3_S       12
#define ADC_SSMUX1_MUX2_S       8
#define ADC_SSMUX1_MUX1_S       4
#define ADC_SSMUX1_MUX0_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_SSCTL1 register.
//
//*****************************************************************************
#define ADC_SSCTL1_TS3          0x00008000  // 4th Sample Temp Sensor Select
#define ADC_SSCTL1_IE3          0x00004000  // 4th Sample Interrupt Enable
#define ADC_SSCTL1_END3         0x00002000  // 4th Sample is End of Sequence
#define ADC_SSCTL1_D3           0x00001000  // 4th Sample Diff Input Select
#define ADC_SSCTL1_TS2          0x00000800  // 3rd Sample Temp Sensor Select
#define ADC_SSCTL1_IE2          0x00000400  // 3rd Sample Interrupt Enable
#define ADC_SSCTL1_END2         0x00000200  // 3rd Sample is End of Sequence
#define ADC_SSCTL1_D2           0x00000100  // 3rd Sample Diff Input Select
#define ADC_SSCTL1_TS1          0x00000080  // 2nd Sample Temp Sensor Select
#define ADC_SSCTL1_IE1          0x00000040  // 2nd Sample Interrupt Enable
#define ADC_SSCTL1_END1         0x00000020  // 2nd Sample is End of Sequence
#define ADC_SSCTL1_D1           0x00000010  // 2nd Sample Diff Input Select
#define ADC_SSCTL1_TS0          0x00000008  // 1st Sample Temp Sensor Select
#define ADC_SSCTL1_IE0          0x00000004  // 1st Sample Interrupt Enable
#define ADC_SSCTL1_END0         0x00000002  // 1st Sample is End of Sequence
#define ADC_SSCTL1_D0           0x00000001  // 1st Sample Diff Input Select

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_SSFIFO1 register.
//
//*****************************************************************************
#define ADC_SSFIFO1_DATA_M      0x00000FFF  // Conversion Result Data
#define ADC_SSFIFO1_DATA_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_SSFSTAT1 register.
//
//*****************************************************************************
#define ADC_SSFSTAT1_FULL       0x00001000  // FIFO Full
#define ADC_SSFSTAT1_EMPTY      0x00000100  // FIFO Empty
#define ADC_SSFSTAT1_HPTR_M     0x000000F0  // FIFO Head Pointer
#define ADC_SSFSTAT1_TPTR_M     0x0000000F  // FIFO Tail Pointer
#define ADC_SSFSTAT1_HPTR_S     4
#define ADC_SSFSTAT1_TPTR_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_SSOP1 register.
//
//*****************************************************************************
#define ADC_SSOP1_S3DCOP        0x00001000  // Sample 3 Digital Comparator
                                            // Operation
#define ADC_SSOP1_S2DCOP        0x00000100  // Sample 2 Digital Comparator
                                            // Operation
#define ADC_SSOP1_S1DCOP        0x00000010  // Sample 1 Digital Comparator
                                            // Operation
#define ADC_SSOP1_S0DCOP        0x00000001  // Sample 0 Digital Comparator
                                            // Operation

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_SSDC1 register.
//
//*****************************************************************************
#define ADC_SSDC1_S3DCSEL_M     0x0000F000  // Sample 3 Digital Comparator
                                            // Select
#define ADC_SSDC1_S2DCSEL_M     0x00000F00  // Sample 2 Digital Comparator
                                            // Select
#define ADC_SSDC1_S1DCSEL_M     0x000000F0  // Sample 1 Digital Comparator
                                            // Select
#define ADC_SSDC1_S0DCSEL_M     0x0000000F  // Sample 0 Digital Comparator
                                            // Select
#define ADC_SSDC1_S2DCSEL_S     8
#define ADC_SSDC1_S1DCSEL_S     4
#define ADC_SSDC1_S0DCSEL_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_SSEMUX1 register.
//
//*****************************************************************************
#define ADC_SSEMUX1_EMUX3       0x00001000  // 4th Sample Input Select (Upper
                                            // Bit)
#define ADC_SSEMUX1_EMUX2       0x00000100  // 3rd Sample Input Select (Upper
                                            // Bit)
#define ADC_SSEMUX1_EMUX1       0x00000010  // 2th Sample Input Select (Upper
                                            // Bit)
#define ADC_SSEMUX1_EMUX0       0x00000001  // 1st Sample Input Select (Upper
                                            // Bit)

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_SSTSH1 register.
//
//*****************************************************************************
#define ADC_SSTSH1_TSH3_M       0x0000F000  // 4th Sample and Hold Period
                                            // Select
#define ADC_SSTSH1_TSH2_M       0x00000F00  // 3rd Sample and Hold Period
                                            // Select
#define ADC_SSTSH1_TSH1_M       0x000000F0  // 2nd Sample and Hold Period
                                            // Select
#define ADC_SSTSH1_TSH0_M       0x0000000F  // 1st Sample and Hold Period
                                            // Select
#define ADC_SSTSH1_TSH3_S       12
#define ADC_SSTSH1_TSH2_S       8
#define ADC_SSTSH1_TSH1_S       4
#define ADC_SSTSH1_TSH0_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_SSMUX2 register.
//
//*****************************************************************************
#define ADC_SSMUX2_MUX3_M       0x0000F000  // 4th Sample Input Select
#define ADC_SSMUX2_MUX2_M       0x00000F00  // 3rd Sample Input Select
#define ADC_SSMUX2_MUX1_M       0x000000F0  // 2nd Sample Input Select
#define ADC_SSMUX2_MUX0_M       0x0000000F  // 1st Sample Input Select
#define ADC_SSMUX2_MUX3_S       12
#define ADC_SSMUX2_MUX2_S       8
#define ADC_SSMUX2_MUX1_S       4
#define ADC_SSMUX2_MUX0_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_SSCTL2 register.
//
//*****************************************************************************
#define ADC_SSCTL2_TS3          0x00008000  // 4th Sample Temp Sensor Select
#define ADC_SSCTL2_IE3          0x00004000  // 4th Sample Interrupt Enable
#define ADC_SSCTL2_END3         0x00002000  // 4th Sample is End of Sequence
#define ADC_SSCTL2_D3           0x00001000  // 4th Sample Diff Input Select
#define ADC_SSCTL2_TS2          0x00000800  // 3rd Sample Temp Sensor Select
#define ADC_SSCTL2_IE2          0x00000400  // 3rd Sample Interrupt Enable
#define ADC_SSCTL2_END2         0x00000200  // 3rd Sample is End of Sequence
#define ADC_SSCTL2_D2           0x00000100  // 3rd Sample Diff Input Select
#define ADC_SSCTL2_TS1          0x00000080  // 2nd Sample Temp Sensor Select
#define ADC_SSCTL2_IE1          0x00000040  // 2nd Sample Interrupt Enable
#define ADC_SSCTL2_END1         0x00000020  // 2nd Sample is End of Sequence
#define ADC_SSCTL2_D1           0x00000010  // 2nd Sample Diff Input Select
#define ADC_SSCTL2_TS0          0x00000008  // 1st Sample Temp Sensor Select
#define ADC_SSCTL2_IE0          0x00000004  // 1st Sample Interrupt Enable
#define ADC_SSCTL2_END0         0x00000002  // 1st Sample is End of Sequence
#define ADC_SSCTL2_D0           0x00000001  // 1st Sample Diff Input Select

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_SSFIFO2 register.
//
//*****************************************************************************
#define ADC_SSFIFO2_DATA_M      0x00000FFF  // Conversion Result Data
#define ADC_SSFIFO2_DATA_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_SSFSTAT2 register.
//
//*****************************************************************************
#define ADC_SSFSTAT2_FULL       0x00001000  // FIFO Full
#define ADC_SSFSTAT2_EMPTY      0x00000100  // FIFO Empty
#define ADC_SSFSTAT2_HPTR_M     0x000000F0  // FIFO Head Pointer
#define ADC_SSFSTAT2_TPTR_M     0x0000000F  // FIFO Tail Pointer
#define ADC_SSFSTAT2_HPTR_S     4
#define ADC_SSFSTAT2_TPTR_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_SSOP2 register.
//
//*****************************************************************************
#define ADC_SSOP2_S3DCOP        0x00001000  // Sample 3 Digital Comparator
                                            // Operation
#define ADC_SSOP2_S2DCOP        0x00000100  // Sample 2 Digital Comparator
                                            // Operation
#define ADC_SSOP2_S1DCOP        0x00000010  // Sample 1 Digital Comparator
                                            // Operation
#define ADC_SSOP2_S0DCOP        0x00000001  // Sample 0 Digital Comparator
                                            // Operation

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_SSDC2 register.
//
//*****************************************************************************
#define ADC_SSDC2_S3DCSEL_M     0x0000F000  // Sample 3 Digital Comparator
                                            // Select
#define ADC_SSDC2_S2DCSEL_M     0x00000F00  // Sample 2 Digital Comparator
                                            // Select
#define ADC_SSDC2_S1DCSEL_M     0x000000F0  // Sample 1 Digital Comparator
                                            // Select
#define ADC_SSDC2_S0DCSEL_M     0x0000000F  // Sample 0 Digital Comparator
                                            // Select
#define ADC_SSDC2_S2DCSEL_S     8
#define ADC_SSDC2_S1DCSEL_S     4
#define ADC_SSDC2_S0DCSEL_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_SSEMUX2 register.
//
//*****************************************************************************
#define ADC_SSEMUX2_EMUX3       0x00001000  // 4th Sample Input Select (Upper
                                            // Bit)
#define ADC_SSEMUX2_EMUX2       0x00000100  // 3rd Sample Input Select (Upper
                                            // Bit)
#define ADC_SSEMUX2_EMUX1       0x00000010  // 2th Sample Input Select (Upper
                                            // Bit)
#define ADC_SSEMUX2_EMUX0       0x00000001  // 1st Sample Input Select (Upper
                                            // Bit)

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_SSTSH2 register.
//
//*****************************************************************************
#define ADC_SSTSH2_TSH3_M       0x0000F000  // 4th Sample and Hold Period
                                            // Select
#define ADC_SSTSH2_TSH2_M       0x00000F00  // 3rd Sample and Hold Period
                                            // Select
#define ADC_SSTSH2_TSH1_M       0x000000F0  // 2nd Sample and Hold Period
                                            // Select
#define ADC_SSTSH2_TSH0_M       0x0000000F  // 1st Sample and Hold Period
                                            // Select
#define ADC_SSTSH2_TSH3_S       12
#define ADC_SSTSH2_TSH2_S       8
#define ADC_SSTSH2_TSH1_S       4
#define ADC_SSTSH2_TSH0_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_SSMUX3 register.
//
//*****************************************************************************
#define ADC_SSMUX3_MUX0_M       0x0000000F  // 1st Sample Input Select
#define ADC_SSMUX3_MUX0_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_SSCTL3 register.
//
//*****************************************************************************
#define ADC_SSCTL3_TS0          0x00000008  // 1st Sample Temp Sensor Select
#define ADC_SSCTL3_IE0          0x00000004  // 1st Sample Interrupt Enable
#define ADC_SSCTL3_END0         0x00000002  // 1st Sample is End of Sequence
#define ADC_SSCTL3_D0           0x00000001  // 1st Sample Diff Input Select

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_SSFIFO3 register.
//
//*****************************************************************************
#define ADC_SSFIFO3_DATA_M      0x00000FFF  // Conversion Result Data
#define ADC_SSFIFO3_DATA_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_SSFSTAT3 register.
//
//*****************************************************************************
#define ADC_SSFSTAT3_FULL       0x00001000  // FIFO Full
#define ADC_SSFSTAT3_EMPTY      0x00000100  // FIFO Empty
#define ADC_SSFSTAT3_HPTR_M     0x000000F0  // FIFO Head Pointer
#define ADC_SSFSTAT3_TPTR_M     0x0000000F  // FIFO Tail Pointer
#define ADC_SSFSTAT3_HPTR_S     4
#define ADC_SSFSTAT3_TPTR_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_SSOP3 register.
//
//*****************************************************************************
#define ADC_SSOP3_S0DCOP        0x00000001  // Sample 0 Digital Comparator
                                            // Operation

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_SSDC3 register.
//
//*****************************************************************************
#define ADC_SSDC3_S0DCSEL_M     0x0000000F  // Sample 0 Digital Comparator
                                            // Select

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_SSEMUX3 register.
//
//*****************************************************************************
#define ADC_SSEMUX3_EMUX0       0x00000001  // 1st Sample Input Select (Upper
                                            // Bit)

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_SSTSH3 register.
//
//*****************************************************************************
#define ADC_SSTSH3_TSH0_M       0x0000000F  // 1st Sample and Hold Period
                                            // Select
#define ADC_SSTSH3_TSH0_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_DCRIC register.
//
//*****************************************************************************
#define ADC_DCRIC_DCTRIG7       0x00800000  // Digital Comparator Trigger 7
#define ADC_DCRIC_DCTRIG6       0x00400000  // Digital Comparator Trigger 6
#define ADC_DCRIC_DCTRIG5       0x00200000  // Digital Comparator Trigger 5
#define ADC_DCRIC_DCTRIG4       0x00100000  // Digital Comparator Trigger 4
#define ADC_DCRIC_DCTRIG3       0x00080000  // Digital Comparator Trigger 3
#define ADC_DCRIC_DCTRIG2       0x00040000  // Digital Comparator Trigger 2
#define ADC_DCRIC_DCTRIG1       0x00020000  // Digital Comparator Trigger 1
#define ADC_DCRIC_DCTRIG0       0x00010000  // Digital Comparator Trigger 0
#define ADC_DCRIC_DCINT7        0x00000080  // Digital Comparator Interrupt 7
#define ADC_DCRIC_DCINT6        0x00000040  // Digital Comparator Interrupt 6
#define ADC_DCRIC_DCINT5        0x00000020  // Digital Comparator Interrupt 5
#define ADC_DCRIC_DCINT4        0x00000010  // Digital Comparator Interrupt 4
#define ADC_DCRIC_DCINT3        0x00000008  // Digital Comparator Interrupt 3
#define ADC_DCRIC_DCINT2        0x00000004  // Digital Comparator Interrupt 2
#define ADC_DCRIC_DCINT1        0x00000002  // Digital Comparator Interrupt 1
#define ADC_DCRIC_DCINT0        0x00000001  // Digital Comparator Interrupt 0

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_DCCTL0 register.
//
//*****************************************************************************
#define ADC_DCCTL0_CTE          0x00001000  // Comparison Trigger Enable
#define ADC_DCCTL0_CTC_M        0x00000C00  // Comparison Trigger Condition
#define ADC_DCCTL0_CTC_LOW      0x00000000  // Low Band
#define ADC_DCCTL0_CTC_MID      0x00000400  // Mid Band
#define ADC_DCCTL0_CTC_HIGH     0x00000C00  // High Band
#define ADC_DCCTL0_CTM_M        0x00000300  // Comparison Trigger Mode
#define ADC_DCCTL0_CTM_ALWAYS   0x00000000  // Always
#define ADC_DCCTL0_CTM_ONCE     0x00000100  // Once
#define ADC_DCCTL0_CTM_HALWAYS  0x00000200  // Hysteresis Always
#define ADC_DCCTL0_CTM_HONCE    0x00000300  // Hysteresis Once
#define ADC_DCCTL0_CIE          0x00000010  // Comparison Interrupt Enable
#define ADC_DCCTL0_CIC_M        0x0000000C  // Comparison Interrupt Condition
#define ADC_DCCTL0_CIC_LOW      0x00000000  // Low Band
#define ADC_DCCTL0_CIC_MID      0x00000004  // Mid Band
#define ADC_DCCTL0_CIC_HIGH     0x0000000C  // High Band
#define ADC_DCCTL0_CIM_M        0x00000003  // Comparison Interrupt Mode
#define ADC_DCCTL0_CIM_ALWAYS   0x00000000  // Always
#define ADC_DCCTL0_CIM_ONCE     0x00000001  // Once
#define ADC_DCCTL0_CIM_HALWAYS  0x00000002  // Hysteresis Always
#define ADC_DCCTL0_CIM_HONCE    0x00000003  // Hysteresis Once

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_DCCTL1 register.
//
//*****************************************************************************
#define ADC_DCCTL1_CTE          0x00001000  // Comparison Trigger Enable
#define ADC_DCCTL1_CTC_M        0x00000C00  // Comparison Trigger Condition
#define ADC_DCCTL1_CTC_LOW      0x00000000  // Low Band
#define ADC_DCCTL1_CTC_MID      0x00000400  // Mid Band
#define ADC_DCCTL1_CTC_HIGH     0x00000C00  // High Band
#define ADC_DCCTL1_CTM_M        0x00000300  // Comparison Trigger Mode
#define ADC_DCCTL1_CTM_ALWAYS   0x00000000  // Always
#define ADC_DCCTL1_CTM_ONCE     0x00000100  // Once
#define ADC_DCCTL1_CTM_HALWAYS  0x00000200  // Hysteresis Always
#define ADC_DCCTL1_CTM_HONCE    0x00000300  // Hysteresis Once
#define ADC_DCCTL1_CIE          0x00000010  // Comparison Interrupt Enable
#define ADC_DCCTL1_CIC_M        0x0000000C  // Comparison Interrupt Condition
#define ADC_DCCTL1_CIC_LOW      0x00000000  // Low Band
#define ADC_DCCTL1_CIC_MID      0x00000004  // Mid Band
#define ADC_DCCTL1_CIC_HIGH     0x0000000C  // High Band
#define ADC_DCCTL1_CIM_M        0x00000003  // Comparison Interrupt Mode
#define ADC_DCCTL1_CIM_ALWAYS   0x00000000  // Always
#define ADC_DCCTL1_CIM_ONCE     0x00000001  // Once
#define ADC_DCCTL1_CIM_HALWAYS  0x00000002  // Hysteresis Always
#define ADC_DCCTL1_CIM_HONCE    0x00000003  // Hysteresis Once

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_DCCTL2 register.
//
//*****************************************************************************
#define ADC_DCCTL2_CTE          0x00001000  // Comparison Trigger Enable
#define ADC_DCCTL2_CTC_M        0x00000C00  // Comparison Trigger Condition
#define ADC_DCCTL2_CTC_LOW      0x00000000  // Low Band
#define ADC_DCCTL2_CTC_MID      0x00000400  // Mid Band
#define ADC_DCCTL2_CTC_HIGH     0x00000C00  // High Band
#define ADC_DCCTL2_CTM_M        0x00000300  // Comparison Trigger Mode
#define ADC_DCCTL2_CTM_ALWAYS   0x00000000  // Always
#define ADC_DCCTL2_CTM_ONCE     0x00000100  // Once
#define ADC_DCCTL2_CTM_HALWAYS  0x00000200  // Hysteresis Always
#define ADC_DCCTL2_CTM_HONCE    0x00000300  // Hysteresis Once
#define ADC_DCCTL2_CIE          0x00000010  // Comparison Interrupt Enable
#define ADC_DCCTL2_CIC_M        0x0000000C  // Comparison Interrupt Condition
#define ADC_DCCTL2_CIC_LOW      0x00000000  // Low Band
#define ADC_DCCTL2_CIC_MID      0x00000004  // Mid Band
#define ADC_DCCTL2_CIC_HIGH     0x0000000C  // High Band
#define ADC_DCCTL2_CIM_M        0x00000003  // Comparison Interrupt Mode
#define ADC_DCCTL2_CIM_ALWAYS   0x00000000  // Always
#define ADC_DCCTL2_CIM_ONCE     0x00000001  // Once
#define ADC_DCCTL2_CIM_HALWAYS  0x00000002  // Hysteresis Always
#define ADC_DCCTL2_CIM_HONCE    0x00000003  // Hysteresis Once

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_DCCTL3 register.
//
//*****************************************************************************
#define ADC_DCCTL3_CTE          0x00001000  // Comparison Trigger Enable
#define ADC_DCCTL3_CTC_M        0x00000C00  // Comparison Trigger Condition
#define ADC_DCCTL3_CTC_LOW      0x00000000  // Low Band
#define ADC_DCCTL3_CTC_MID      0x00000400  // Mid Band
#define ADC_DCCTL3_CTC_HIGH     0x00000C00  // High Band
#define ADC_DCCTL3_CTM_M        0x00000300  // Comparison Trigger Mode
#define ADC_DCCTL3_CTM_ALWAYS   0x00000000  // Always
#define ADC_DCCTL3_CTM_ONCE     0x00000100  // Once
#define ADC_DCCTL3_CTM_HALWAYS  0x00000200  // Hysteresis Always
#define ADC_DCCTL3_CTM_HONCE    0x00000300  // Hysteresis Once
#define ADC_DCCTL3_CIE          0x00000010  // Comparison Interrupt Enable
#define ADC_DCCTL3_CIC_M        0x0000000C  // Comparison Interrupt Condition
#define ADC_DCCTL3_CIC_LOW      0x00000000  // Low Band
#define ADC_DCCTL3_CIC_MID      0x00000004  // Mid Band
#define ADC_DCCTL3_CIC_HIGH     0x0000000C  // High Band
#define ADC_DCCTL3_CIM_M        0x00000003  // Comparison Interrupt Mode
#define ADC_DCCTL3_CIM_ALWAYS   0x00000000  // Always
#define ADC_DCCTL3_CIM_ONCE     0x00000001  // Once
#define ADC_DCCTL3_CIM_HALWAYS  0x00000002  // Hysteresis Always
#define ADC_DCCTL3_CIM_HONCE    0x00000003  // Hysteresis Once

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_DCCTL4 register.
//
//*****************************************************************************
#define ADC_DCCTL4_CTE          0x00001000  // Comparison Trigger Enable
#define ADC_DCCTL4_CTC_M        0x00000C00  // Comparison Trigger Condition
#define ADC_DCCTL4_CTC_LOW      0x00000000  // Low Band
#define ADC_DCCTL4_CTC_MID      0x00000400  // Mid Band
#define ADC_DCCTL4_CTC_HIGH     0x00000C00  // High Band
#define ADC_DCCTL4_CTM_M        0x00000300  // Comparison Trigger Mode
#define ADC_DCCTL4_CTM_ALWAYS   0x00000000  // Always
#define ADC_DCCTL4_CTM_ONCE     0x00000100  // Once
#define ADC_DCCTL4_CTM_HALWAYS  0x00000200  // Hysteresis Always
#define ADC_DCCTL4_CTM_HONCE    0x00000300  // Hysteresis Once
#define ADC_DCCTL4_CIE          0x00000010  // Comparison Interrupt Enable
#define ADC_DCCTL4_CIC_M        0x0000000C  // Comparison Interrupt Condition
#define ADC_DCCTL4_CIC_LOW      0x00000000  // Low Band
#define ADC_DCCTL4_CIC_MID      0x00000004  // Mid Band
#define ADC_DCCTL4_CIC_HIGH     0x0000000C  // High Band
#define ADC_DCCTL4_CIM_M        0x00000003  // Comparison Interrupt Mode
#define ADC_DCCTL4_CIM_ALWAYS   0x00000000  // Always
#define ADC_DCCTL4_CIM_ONCE     0x00000001  // Once
#define ADC_DCCTL4_CIM_HALWAYS  0x00000002  // Hysteresis Always
#define ADC_DCCTL4_CIM_HONCE    0x00000003  // Hysteresis Once

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_DCCTL5 register.
//
//*****************************************************************************
#define ADC_DCCTL5_CTE          0x00001000  // Comparison Trigger Enable
#define ADC_DCCTL5_CTC_M        0x00000C00  // Comparison Trigger Condition
#define ADC_DCCTL5_CTC_LOW      0x00000000  // Low Band
#define ADC_DCCTL5_CTC_MID      0x00000400  // Mid Band
#define ADC_DCCTL5_CTC_HIGH     0x00000C00  // High Band
#define ADC_DCCTL5_CTM_M        0x00000300  // Comparison Trigger Mode
#define ADC_DCCTL5_CTM_ALWAYS   0x00000000  // Always
#define ADC_DCCTL5_CTM_ONCE     0x00000100  // Once
#define ADC_DCCTL5_CTM_HALWAYS  0x00000200  // Hysteresis Always
#define ADC_DCCTL5_CTM_HONCE    0x00000300  // Hysteresis Once
#define ADC_DCCTL5_CIE          0x00000010  // Comparison Interrupt Enable
#define ADC_DCCTL5_CIC_M        0x0000000C  // Comparison Interrupt Condition
#define ADC_DCCTL5_CIC_LOW      0x00000000  // Low Band
#define ADC_DCCTL5_CIC_MID      0x00000004  // Mid Band
#define ADC_DCCTL5_CIC_HIGH     0x0000000C  // High Band
#define ADC_DCCTL5_CIM_M        0x00000003  // Comparison Interrupt Mode
#define ADC_DCCTL5_CIM_ALWAYS   0x00000000  // Always
#define ADC_DCCTL5_CIM_ONCE     0x00000001  // Once
#define ADC_DCCTL5_CIM_HALWAYS  0x00000002  // Hysteresis Always
#define ADC_DCCTL5_CIM_HONCE    0x00000003  // Hysteresis Once

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_DCCTL6 register.
//
//*****************************************************************************
#define ADC_DCCTL6_CTE          0x00001000  // Comparison Trigger Enable
#define ADC_DCCTL6_CTC_M        0x00000C00  // Comparison Trigger Condition
#define ADC_DCCTL6_CTC_LOW      0x00000000  // Low Band
#define ADC_DCCTL6_CTC_MID      0x00000400  // Mid Band
#define ADC_DCCTL6_CTC_HIGH     0x00000C00  // High Band
#define ADC_DCCTL6_CTM_M        0x00000300  // Comparison Trigger Mode
#define ADC_DCCTL6_CTM_ALWAYS   0x00000000  // Always
#define ADC_DCCTL6_CTM_ONCE     0x00000100  // Once
#define ADC_DCCTL6_CTM_HALWAYS  0x00000200  // Hysteresis Always
#define ADC_DCCTL6_CTM_HONCE    0x00000300  // Hysteresis Once
#define ADC_DCCTL6_CIE          0x00000010  // Comparison Interrupt Enable
#define ADC_DCCTL6_CIC_M        0x0000000C  // Comparison Interrupt Condition
#define ADC_DCCTL6_CIC_LOW      0x00000000  // Low Band
#define ADC_DCCTL6_CIC_MID      0x00000004  // Mid Band
#define ADC_DCCTL6_CIC_HIGH     0x0000000C  // High Band
#define ADC_DCCTL6_CIM_M        0x00000003  // Comparison Interrupt Mode
#define ADC_DCCTL6_CIM_ALWAYS   0x00000000  // Always
#define ADC_DCCTL6_CIM_ONCE     0x00000001  // Once
#define ADC_DCCTL6_CIM_HALWAYS  0x00000002  // Hysteresis Always
#define ADC_DCCTL6_CIM_HONCE    0x00000003  // Hysteresis Once

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_DCCTL7 register.
//
//*****************************************************************************
#define ADC_DCCTL7_CTE          0x00001000  // Comparison Trigger Enable
#define ADC_DCCTL7_CTC_M        0x00000C00  // Comparison Trigger Condition
#define ADC_DCCTL7_CTC_LOW      0x00000000  // Low Band
#define ADC_DCCTL7_CTC_MID      0x00000400  // Mid Band
#define ADC_DCCTL7_CTC_HIGH     0x00000C00  // High Band
#define ADC_DCCTL7_CTM_M        0x00000300  // Comparison Trigger Mode
#define ADC_DCCTL7_CTM_ALWAYS   0x00000000  // Always
#define ADC_DCCTL7_CTM_ONCE     0x00000100  // Once
#define ADC_DCCTL7_CTM_HALWAYS  0x00000200  // Hysteresis Always
#define ADC_DCCTL7_CTM_HONCE    0x00000300  // Hysteresis Once
#define ADC_DCCTL7_CIE          0x00000010  // Comparison Interrupt Enable
#define ADC_DCCTL7_CIC_M        0x0000000C  // Comparison Interrupt Condition
#define ADC_DCCTL7_CIC_LOW      0x00000000  // Low Band
#define ADC_DCCTL7_CIC_MID      0x00000004  // Mid Band
#define ADC_DCCTL7_CIC_HIGH     0x0000000C  // High Band
#define ADC_DCCTL7_CIM_M        0x00000003  // Comparison Interrupt Mode
#define ADC_DCCTL7_CIM_ALWAYS   0x00000000  // Always
#define ADC_DCCTL7_CIM_ONCE     0x00000001  // Once
#define ADC_DCCTL7_CIM_HALWAYS  0x00000002  // Hysteresis Always
#define ADC_DCCTL7_CIM_HONCE    0x00000003  // Hysteresis Once

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_DCCMP0 register.
//
//*****************************************************************************
#define ADC_DCCMP0_COMP1_M      0x0FFF0000  // Compare 1
#define ADC_DCCMP0_COMP0_M      0x00000FFF  // Compare 0
#define ADC_DCCMP0_COMP1_S      16
#define ADC_DCCMP0_COMP0_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_DCCMP1 register.
//
//*****************************************************************************
#define ADC_DCCMP1_COMP1_M      0x0FFF0000  // Compare 1
#define ADC_DCCMP1_COMP0_M      0x00000FFF  // Compare 0
#define ADC_DCCMP1_COMP1_S      16
#define ADC_DCCMP1_COMP0_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_DCCMP2 register.
//
//*****************************************************************************
#define ADC_DCCMP2_COMP1_M      0x0FFF0000  // Compare 1
#define ADC_DCCMP2_COMP0_M      0x00000FFF  // Compare 0
#define ADC_DCCMP2_COMP1_S      16
#define ADC_DCCMP2_COMP0_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_DCCMP3 register.
//
//*****************************************************************************
#define ADC_DCCMP3_COMP1_M      0x0FFF0000  // Compare 1
#define ADC_DCCMP3_COMP0_M      0x00000FFF  // Compare 0
#define ADC_DCCMP3_COMP1_S      16
#define ADC_DCCMP3_COMP0_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_DCCMP4 register.
//
//*****************************************************************************
#define ADC_DCCMP4_COMP1_M      0x0FFF0000  // Compare 1
#define ADC_DCCMP4_COMP0_M      0x00000FFF  // Compare 0
#define ADC_DCCMP4_COMP1_S      16
#define ADC_DCCMP4_COMP0_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_DCCMP5 register.
//
//*****************************************************************************
#define ADC_DCCMP5_COMP1_M      0x0FFF0000  // Compare 1
#define ADC_DCCMP5_COMP0_M      0x00000FFF  // Compare 0
#define ADC_DCCMP5_COMP1_S      16
#define ADC_DCCMP5_COMP0_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_DCCMP6 register.
//
//*****************************************************************************
#define ADC_DCCMP6_COMP1_M      0x0FFF0000  // Compare 1
#define ADC_DCCMP6_COMP0_M      0x00000FFF  // Compare 0
#define ADC_DCCMP6_COMP1_S      16
#define ADC_DCCMP6_COMP0_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_DCCMP7 register.
//
//*****************************************************************************
#define ADC_DCCMP7_COMP1_M      0x0FFF0000  // Compare 1
#define ADC_DCCMP7_COMP0_M      0x00000FFF  // Compare 0
#define ADC_DCCMP7_COMP1_S      16
#define ADC_DCCMP7_COMP0_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_PP register.
//
//*****************************************************************************
#define ADC_PP_APSHT            0x01000000  // Application-Programmable
                                            // Sample-and-Hold Time
#define ADC_PP_TS               0x00800000  // Temperature Sensor
#define ADC_PP_RSL_M            0x007C0000  // Resolution
#define ADC_PP_TYPE_M           0x00030000  // ADC Architecture
#define ADC_PP_TYPE_SAR         0x00000000  // SAR
#define ADC_PP_DC_M             0x0000FC00  // Digital Comparator Count
#define ADC_PP_CH_M             0x000003F0  // ADC Channel Count
#define ADC_PP_MCR_M            0x0000000F  // Maximum Conversion Rate
#define ADC_PP_MCR_FULL         0x00000007  // Full conversion rate (FCONV) as
                                            // defined by TADC and NSH
#define ADC_PP_RSL_S            18
#define ADC_PP_DC_S             10
#define ADC_PP_CH_S             4

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_PC register.
//
//*****************************************************************************
#define ADC_PC_MCR_M            0x0000000F  // Conversion Rate
#define ADC_PC_MCR_1_8          0x00000001  // Eighth conversion rate. After a
                                            // conversion completes, the logic
                                            // pauses for 112 TADC periods
                                            // before starting the next
                                            // conversion
#define ADC_PC_MCR_1_4          0x00000003  // Quarter conversion rate. After a
                                            // conversion completes, the logic
                                            // pauses for 48 TADC periods
                                            // before starting the next
                                            // conversion
#define ADC_PC_MCR_1_2          0x00000005  // Half conversion rate. After a
                                            // conversion completes, the logic
                                            // pauses for 16 TADC periods
                                            // before starting the next
                                            // conversion
#define ADC_PC_MCR_FULL         0x00000007  // Full conversion rate (FCONV) as
                                            // defined by TADC and NSH

//*****************************************************************************
//
// The following are defines for the bit fields in the ADC_O_CC register.
//
//*****************************************************************************
#define ADC_CC_CLKDIV_M         0x000003F0  // PLL VCO Clock Divisor
#define ADC_CC_CS_M             0x0000000F  // ADC Clock Source
#define ADC_CC_CS_SYSPLL        0x00000000  // Either the system clock (if the
                                            // PLL bypass is in effect) or the
                                            // 16 MHz clock derived from PLL /
                                            // 25 (default)
#define ADC_CC_CS_PIOSC         0x00000001  // PIOSC
#define ADC_CC_CS_MOSC          0x00000002  // MOSC
#define ADC_CC_CLKDIV_S         4

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
// The following are defines for the bit fields in the CAN_O_CTL register.
//
//*****************************************************************************
#define CAN_CTL_TEST            0x00000080  // Test Mode Enable
#define CAN_CTL_CCE             0x00000040  // Configuration Change Enable
#define CAN_CTL_DAR             0x00000020  // Disable Automatic-Retransmission
#define CAN_CTL_EIE             0x00000008  // Error Interrupt Enable
#define CAN_CTL_SIE             0x00000004  // Status Interrupt Enable
#define CAN_CTL_IE              0x00000002  // CAN Interrupt Enable
#define CAN_CTL_INIT            0x00000001  // Initialization

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_STS register.
//
//*****************************************************************************
#define CAN_STS_BOFF            0x00000080  // Bus-Off Status
#define CAN_STS_EWARN           0x00000040  // Warning Status
#define CAN_STS_EPASS           0x00000020  // Error Passive
#define CAN_STS_RXOK            0x00000010  // Received a Message Successfully
#define CAN_STS_TXOK            0x00000008  // Transmitted a Message
                                            // Successfully
#define CAN_STS_LEC_M           0x00000007  // Last Error Code
#define CAN_STS_LEC_NONE        0x00000000  // No Error
#define CAN_STS_LEC_STUFF       0x00000001  // Stuff Error
#define CAN_STS_LEC_FORM        0x00000002  // Format Error
#define CAN_STS_LEC_ACK         0x00000003  // ACK Error
#define CAN_STS_LEC_BIT1        0x00000004  // Bit 1 Error
#define CAN_STS_LEC_BIT0        0x00000005  // Bit 0 Error
#define CAN_STS_LEC_CRC         0x00000006  // CRC Error
#define CAN_STS_LEC_NOEVENT     0x00000007  // No Event

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_ERR register.
//
//*****************************************************************************
#define CAN_ERR_RP              0x00008000  // Received Error Passive
#define CAN_ERR_REC_M           0x00007F00  // Receive Error Counter
#define CAN_ERR_TEC_M           0x000000FF  // Transmit Error Counter
#define CAN_ERR_REC_S           8
#define CAN_ERR_TEC_S           0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_BIT register.
//
//*****************************************************************************
#define CAN_BIT_TSEG2_M         0x00007000  // Time Segment after Sample Point
#define CAN_BIT_TSEG1_M         0x00000F00  // Time Segment Before Sample Point
#define CAN_BIT_SJW_M           0x000000C0  // (Re)Synchronization Jump Width
#define CAN_BIT_BRP_M           0x0000003F  // Baud Rate Prescaler
#define CAN_BIT_TSEG2_S         12
#define CAN_BIT_TSEG1_S         8
#define CAN_BIT_SJW_S           6
#define CAN_BIT_BRP_S           0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_INT register.
//
//*****************************************************************************
#define CAN_INT_INTID_M         0x0000FFFF  // Interrupt Identifier
#define CAN_INT_INTID_NONE      0x00000000  // No interrupt pending
#define CAN_INT_INTID_STATUS    0x00008000  // Status Interrupt

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_TST register.
//
//*****************************************************************************
#define CAN_TST_RX              0x00000080  // Receive Observation
#define CAN_TST_TX_M            0x00000060  // Transmit Control
#define CAN_TST_TX_CANCTL       0x00000000  // CAN Module Control
#define CAN_TST_TX_SAMPLE       0x00000020  // Sample Point
#define CAN_TST_TX_DOMINANT     0x00000040  // Driven Low
#define CAN_TST_TX_RECESSIVE    0x00000060  // Driven High
#define CAN_TST_LBACK           0x00000010  // Loopback Mode
#define CAN_TST_SILENT          0x00000008  // Silent Mode
#define CAN_TST_BASIC           0x00000004  // Basic Mode

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_BRPE register.
//
//*****************************************************************************
#define CAN_BRPE_BRPE_M         0x0000000F  // Baud Rate Prescaler Extension
#define CAN_BRPE_BRPE_S         0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_IF1CRQ register.
//
//*****************************************************************************
#define CAN_IF1CRQ_BUSY         0x00008000  // Busy Flag
#define CAN_IF1CRQ_MNUM_M       0x0000003F  // Message Number
#define CAN_IF1CRQ_MNUM_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_IF1CMSK register.
//
//*****************************************************************************
#define CAN_IF1CMSK_WRNRD       0x00000080  // Write, Not Read
#define CAN_IF1CMSK_MASK        0x00000040  // Access Mask Bits
#define CAN_IF1CMSK_ARB         0x00000020  // Access Arbitration Bits
#define CAN_IF1CMSK_CONTROL     0x00000010  // Access Control Bits
#define CAN_IF1CMSK_CLRINTPND   0x00000008  // Clear Interrupt Pending Bit
#define CAN_IF1CMSK_NEWDAT      0x00000004  // Access New Data
#define CAN_IF1CMSK_TXRQST      0x00000004  // Access Transmission Request
#define CAN_IF1CMSK_DATAA       0x00000002  // Access Data Byte 0 to 3
#define CAN_IF1CMSK_DATAB       0x00000001  // Access Data Byte 4 to 7

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_IF1MSK1 register.
//
//*****************************************************************************
#define CAN_IF1MSK1_IDMSK_M     0x0000FFFF  // Identifier Mask
#define CAN_IF1MSK1_IDMSK_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_IF1MSK2 register.
//
//*****************************************************************************
#define CAN_IF1MSK2_MXTD        0x00008000  // Mask Extended Identifier
#define CAN_IF1MSK2_MDIR        0x00004000  // Mask Message Direction
#define CAN_IF1MSK2_IDMSK_M     0x00001FFF  // Identifier Mask
#define CAN_IF1MSK2_IDMSK_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_IF1ARB1 register.
//
//*****************************************************************************
#define CAN_IF1ARB1_ID_M        0x0000FFFF  // Message Identifier
#define CAN_IF1ARB1_ID_S        0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_IF1ARB2 register.
//
//*****************************************************************************
#define CAN_IF1ARB2_MSGVAL      0x00008000  // Message Valid
#define CAN_IF1ARB2_XTD         0x00004000  // Extended Identifier
#define CAN_IF1ARB2_DIR         0x00002000  // Message Direction
#define CAN_IF1ARB2_ID_M        0x00001FFF  // Message Identifier
#define CAN_IF1ARB2_ID_S        0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_IF1MCTL register.
//
//*****************************************************************************
#define CAN_IF1MCTL_NEWDAT      0x00008000  // New Data
#define CAN_IF1MCTL_MSGLST      0x00004000  // Message Lost
#define CAN_IF1MCTL_INTPND      0x00002000  // Interrupt Pending
#define CAN_IF1MCTL_UMASK       0x00001000  // Use Acceptance Mask
#define CAN_IF1MCTL_TXIE        0x00000800  // Transmit Interrupt Enable
#define CAN_IF1MCTL_RXIE        0x00000400  // Receive Interrupt Enable
#define CAN_IF1MCTL_RMTEN       0x00000200  // Remote Enable
#define CAN_IF1MCTL_TXRQST      0x00000100  // Transmit Request
#define CAN_IF1MCTL_EOB         0x00000080  // End of Buffer
#define CAN_IF1MCTL_DLC_M       0x0000000F  // Data Length Code
#define CAN_IF1MCTL_DLC_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_IF1DA1 register.
//
//*****************************************************************************
#define CAN_IF1DA1_DATA_M       0x0000FFFF  // Data
#define CAN_IF1DA1_DATA_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_IF1DA2 register.
//
//*****************************************************************************
#define CAN_IF1DA2_DATA_M       0x0000FFFF  // Data
#define CAN_IF1DA2_DATA_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_IF1DB1 register.
//
//*****************************************************************************
#define CAN_IF1DB1_DATA_M       0x0000FFFF  // Data
#define CAN_IF1DB1_DATA_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_IF1DB2 register.
//
//*****************************************************************************
#define CAN_IF1DB2_DATA_M       0x0000FFFF  // Data
#define CAN_IF1DB2_DATA_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_IF2CRQ register.
//
//*****************************************************************************
#define CAN_IF2CRQ_BUSY         0x00008000  // Busy Flag
#define CAN_IF2CRQ_MNUM_M       0x0000003F  // Message Number
#define CAN_IF2CRQ_MNUM_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_IF2CMSK register.
//
//*****************************************************************************
#define CAN_IF2CMSK_WRNRD       0x00000080  // Write, Not Read
#define CAN_IF2CMSK_MASK        0x00000040  // Access Mask Bits
#define CAN_IF2CMSK_ARB         0x00000020  // Access Arbitration Bits
#define CAN_IF2CMSK_CONTROL     0x00000010  // Access Control Bits
#define CAN_IF2CMSK_CLRINTPND   0x00000008  // Clear Interrupt Pending Bit
#define CAN_IF2CMSK_NEWDAT      0x00000004  // Access New Data
#define CAN_IF2CMSK_TXRQST      0x00000004  // Access Transmission Request
#define CAN_IF2CMSK_DATAA       0x00000002  // Access Data Byte 0 to 3
#define CAN_IF2CMSK_DATAB       0x00000001  // Access Data Byte 4 to 7

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_IF2MSK1 register.
//
//*****************************************************************************
#define CAN_IF2MSK1_IDMSK_M     0x0000FFFF  // Identifier Mask
#define CAN_IF2MSK1_IDMSK_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_IF2MSK2 register.
//
//*****************************************************************************
#define CAN_IF2MSK2_MXTD        0x00008000  // Mask Extended Identifier
#define CAN_IF2MSK2_MDIR        0x00004000  // Mask Message Direction
#define CAN_IF2MSK2_IDMSK_M     0x00001FFF  // Identifier Mask
#define CAN_IF2MSK2_IDMSK_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_IF2ARB1 register.
//
//*****************************************************************************
#define CAN_IF2ARB1_ID_M        0x0000FFFF  // Message Identifier
#define CAN_IF2ARB1_ID_S        0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_IF2ARB2 register.
//
//*****************************************************************************
#define CAN_IF2ARB2_MSGVAL      0x00008000  // Message Valid
#define CAN_IF2ARB2_XTD         0x00004000  // Extended Identifier
#define CAN_IF2ARB2_DIR         0x00002000  // Message Direction
#define CAN_IF2ARB2_ID_M        0x00001FFF  // Message Identifier
#define CAN_IF2ARB2_ID_S        0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_IF2MCTL register.
//
//*****************************************************************************
#define CAN_IF2MCTL_NEWDAT      0x00008000  // New Data
#define CAN_IF2MCTL_MSGLST      0x00004000  // Message Lost
#define CAN_IF2MCTL_INTPND      0x00002000  // Interrupt Pending
#define CAN_IF2MCTL_UMASK       0x00001000  // Use Acceptance Mask
#define CAN_IF2MCTL_TXIE        0x00000800  // Transmit Interrupt Enable
#define CAN_IF2MCTL_RXIE        0x00000400  // Receive Interrupt Enable
#define CAN_IF2MCTL_RMTEN       0x00000200  // Remote Enable
#define CAN_IF2MCTL_TXRQST      0x00000100  // Transmit Request
#define CAN_IF2MCTL_EOB         0x00000080  // End of Buffer
#define CAN_IF2MCTL_DLC_M       0x0000000F  // Data Length Code
#define CAN_IF2MCTL_DLC_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_IF2DA1 register.
//
//*****************************************************************************
#define CAN_IF2DA1_DATA_M       0x0000FFFF  // Data
#define CAN_IF2DA1_DATA_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_IF2DA2 register.
//
//*****************************************************************************
#define CAN_IF2DA2_DATA_M       0x0000FFFF  // Data
#define CAN_IF2DA2_DATA_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_IF2DB1 register.
//
//*****************************************************************************
#define CAN_IF2DB1_DATA_M       0x0000FFFF  // Data
#define CAN_IF2DB1_DATA_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_IF2DB2 register.
//
//*****************************************************************************
#define CAN_IF2DB2_DATA_M       0x0000FFFF  // Data
#define CAN_IF2DB2_DATA_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_TXRQ1 register.
//
//*****************************************************************************
#define CAN_TXRQ1_TXRQST_M      0x0000FFFF  // Transmission Request Bits
#define CAN_TXRQ1_TXRQST_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_TXRQ2 register.
//
//*****************************************************************************
#define CAN_TXRQ2_TXRQST_M      0x0000FFFF  // Transmission Request Bits
#define CAN_TXRQ2_TXRQST_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_NWDA1 register.
//
//*****************************************************************************
#define CAN_NWDA1_NEWDAT_M      0x0000FFFF  // New Data Bits
#define CAN_NWDA1_NEWDAT_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_NWDA2 register.
//
//*****************************************************************************
#define CAN_NWDA2_NEWDAT_M      0x0000FFFF  // New Data Bits
#define CAN_NWDA2_NEWDAT_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_MSG1INT register.
//
//*****************************************************************************
#define CAN_MSG1INT_INTPND_M    0x0000FFFF  // Interrupt Pending Bits
#define CAN_MSG1INT_INTPND_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_MSG2INT register.
//
//*****************************************************************************
#define CAN_MSG2INT_INTPND_M    0x0000FFFF  // Interrupt Pending Bits
#define CAN_MSG2INT_INTPND_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_MSG1VAL register.
//
//*****************************************************************************
#define CAN_MSG1VAL_MSGVAL_M    0x0000FFFF  // Message Valid Bits
#define CAN_MSG1VAL_MSGVAL_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_MSG2VAL register.
//
//*****************************************************************************
#define CAN_MSG2VAL_MSGVAL_M    0x0000FFFF  // Message Valid Bits
#define CAN_MSG2VAL_MSGVAL_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_FADDR register.
//
//*****************************************************************************
#define USB_FADDR_M             0x0000007F  // Function Address
#define USB_FADDR_S             0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_POWER register.
//
//*****************************************************************************
#define USB_POWER_ISOUP         0x00000080  // Isochronous Update
#define USB_POWER_SOFTCONN      0x00000040  // Soft Connect/Disconnect
#define USB_POWER_HSENAB        0x00000020  // High Speed Enable
#define USB_POWER_HSMODE        0x00000010  // High Speed Enable
#define USB_POWER_RESET         0x00000008  // RESET Signaling
#define USB_POWER_RESUME        0x00000004  // RESUME Signaling
#define USB_POWER_SUSPEND       0x00000002  // SUSPEND Mode
#define USB_POWER_PWRDNPHY      0x00000001  // Power Down PHY

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXIS register.
//
//*****************************************************************************
#define USB_TXIS_EP7            0x00000080  // TX Endpoint 7 Interrupt
#define USB_TXIS_EP6            0x00000040  // TX Endpoint 6 Interrupt
#define USB_TXIS_EP5            0x00000020  // TX Endpoint 5 Interrupt
#define USB_TXIS_EP4            0x00000010  // TX Endpoint 4 Interrupt
#define USB_TXIS_EP3            0x00000008  // TX Endpoint 3 Interrupt
#define USB_TXIS_EP2            0x00000004  // TX Endpoint 2 Interrupt
#define USB_TXIS_EP1            0x00000002  // TX Endpoint 1 Interrupt
#define USB_TXIS_EP0            0x00000001  // TX and RX Endpoint 0 Interrupt

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXIS register.
//
//*****************************************************************************
#define USB_RXIS_EP7            0x00000080  // RX Endpoint 7 Interrupt
#define USB_RXIS_EP6            0x00000040  // RX Endpoint 6 Interrupt
#define USB_RXIS_EP5            0x00000020  // RX Endpoint 5 Interrupt
#define USB_RXIS_EP4            0x00000010  // RX Endpoint 4 Interrupt
#define USB_RXIS_EP3            0x00000008  // RX Endpoint 3 Interrupt
#define USB_RXIS_EP2            0x00000004  // RX Endpoint 2 Interrupt
#define USB_RXIS_EP1            0x00000002  // RX Endpoint 1 Interrupt

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXIE register.
//
//*****************************************************************************
#define USB_TXIE_EP7            0x00000080  // TX Endpoint 7 Interrupt Enable
#define USB_TXIE_EP6            0x00000040  // TX Endpoint 6 Interrupt Enable
#define USB_TXIE_EP5            0x00000020  // TX Endpoint 5 Interrupt Enable
#define USB_TXIE_EP4            0x00000010  // TX Endpoint 4 Interrupt Enable
#define USB_TXIE_EP3            0x00000008  // TX Endpoint 3 Interrupt Enable
#define USB_TXIE_EP2            0x00000004  // TX Endpoint 2 Interrupt Enable
#define USB_TXIE_EP1            0x00000002  // TX Endpoint 1 Interrupt Enable
#define USB_TXIE_EP0            0x00000001  // TX and RX Endpoint 0 Interrupt
                                            // Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXIE register.
//
//*****************************************************************************
#define USB_RXIE_EP7            0x00000080  // RX Endpoint 7 Interrupt Enable
#define USB_RXIE_EP6            0x00000040  // RX Endpoint 6 Interrupt Enable
#define USB_RXIE_EP5            0x00000020  // RX Endpoint 5 Interrupt Enable
#define USB_RXIE_EP4            0x00000010  // RX Endpoint 4 Interrupt Enable
#define USB_RXIE_EP3            0x00000008  // RX Endpoint 3 Interrupt Enable
#define USB_RXIE_EP2            0x00000004  // RX Endpoint 2 Interrupt Enable
#define USB_RXIE_EP1            0x00000002  // RX Endpoint 1 Interrupt Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_IS register.
//
//*****************************************************************************
#define USB_IS_VBUSERR          0x00000080  // VBUS Error
#define USB_IS_SESREQ           0x00000040  // SESSION REQUEST
#define USB_IS_DISCON           0x00000020  // Session Disconnect
#define USB_IS_CONN             0x00000010  // Session Connect
#define USB_IS_SOF              0x00000008  // Start of Frame
#define USB_IS_BABBLE           0x00000004  // Babble Detected
#define USB_IS_RESET            0x00000004  // RESET Signaling Detected
#define USB_IS_RESUME           0x00000002  // RESUME Signaling Detected
#define USB_IS_SUSPEND          0x00000001  // SUSPEND Signaling Detected

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_IE register.
//
//*****************************************************************************
#define USB_IE_VBUSERR          0x00000080  // Enable VBUS Error Interrupt
#define USB_IE_SESREQ           0x00000040  // Enable Session Request
#define USB_IE_DISCON           0x00000020  // Enable Disconnect Interrupt
#define USB_IE_CONN             0x00000010  // Enable Connect Interrupt
#define USB_IE_SOF              0x00000008  // Enable Start-of-Frame Interrupt
#define USB_IE_BABBLE           0x00000004  // Enable Babble Interrupt
#define USB_IE_RESET            0x00000004  // Enable RESET Interrupt
#define USB_IE_RESUME           0x00000002  // Enable RESUME Interrupt
#define USB_IE_SUSPND           0x00000001  // Enable SUSPEND Interrupt

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_FRAME register.
//
//*****************************************************************************
#define USB_FRAME_M             0x000007FF  // Frame Number
#define USB_FRAME_S             0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_EPIDX register.
//
//*****************************************************************************
#define USB_EPIDX_EPIDX_M       0x0000000F  // Endpoint Index
#define USB_EPIDX_EPIDX_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TEST register.
//
//*****************************************************************************
#define USB_TEST_FORCEH         0x00000080  // Force Host Mode
#define USB_TEST_FIFOACC        0x00000040  // FIFO Access
#define USB_TEST_FORCEFS        0x00000020  // Force Full-Speed Mode
#define USB_TEST_FORCEHS        0x00000010  // Force High-Speed Mode
#define USB_TEST_TESTPKT        0x00000008  // Test Packet Mode Enable
#define USB_TEST_TESTK          0x00000004  // Test_K Mode Enable
#define USB_TEST_TESTJ          0x00000002  // Test_J Mode Enable
#define USB_TEST_TESTSE0NAK     0x00000001  // Test_SE0_NAK Test Mode Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_FIFO0 register.
//
//*****************************************************************************
#define USB_FIFO0_EPDATA_M      0xFFFFFFFF  // Endpoint Data
#define USB_FIFO0_EPDATA_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_FIFO1 register.
//
//*****************************************************************************
#define USB_FIFO1_EPDATA_M      0xFFFFFFFF  // Endpoint Data
#define USB_FIFO1_EPDATA_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_FIFO2 register.
//
//*****************************************************************************
#define USB_FIFO2_EPDATA_M      0xFFFFFFFF  // Endpoint Data
#define USB_FIFO2_EPDATA_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_FIFO3 register.
//
//*****************************************************************************
#define USB_FIFO3_EPDATA_M      0xFFFFFFFF  // Endpoint Data
#define USB_FIFO3_EPDATA_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_FIFO4 register.
//
//*****************************************************************************
#define USB_FIFO4_EPDATA_M      0xFFFFFFFF  // Endpoint Data
#define USB_FIFO4_EPDATA_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_FIFO5 register.
//
//*****************************************************************************
#define USB_FIFO5_EPDATA_M      0xFFFFFFFF  // Endpoint Data
#define USB_FIFO5_EPDATA_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_FIFO6 register.
//
//*****************************************************************************
#define USB_FIFO6_EPDATA_M      0xFFFFFFFF  // Endpoint Data
#define USB_FIFO6_EPDATA_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_FIFO7 register.
//
//*****************************************************************************
#define USB_FIFO7_EPDATA_M      0xFFFFFFFF  // Endpoint Data
#define USB_FIFO7_EPDATA_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_DEVCTL register.
//
//*****************************************************************************
#define USB_DEVCTL_DEV          0x00000080  // Device Mode
#define USB_DEVCTL_FSDEV        0x00000040  // Full-Speed Device Detected
#define USB_DEVCTL_LSDEV        0x00000020  // Low-Speed Device Detected
#define USB_DEVCTL_VBUS_M       0x00000018  // VBUS Level
#define USB_DEVCTL_VBUS_NONE    0x00000000  // Below SessionEnd
#define USB_DEVCTL_VBUS_SEND    0x00000008  // Above SessionEnd, below AValid
#define USB_DEVCTL_VBUS_AVALID  0x00000010  // Above AValid, below VBUSValid
#define USB_DEVCTL_VBUS_VALID   0x00000018  // Above VBUSValid
#define USB_DEVCTL_HOST         0x00000004  // Host Mode
#define USB_DEVCTL_HOSTREQ      0x00000002  // Host Request
#define USB_DEVCTL_SESSION      0x00000001  // Session Start/End

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_CCONF register.
//
//*****************************************************************************
#define USB_CCONF_TXEDMA        0x00000002  // TX Early DMA Enable
#define USB_CCONF_RXEDMA        0x00000001  // TX Early DMA Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXFIFOSZ register.
//
//*****************************************************************************
#define USB_TXFIFOSZ_DPB        0x00000010  // Double Packet Buffer Support
#define USB_TXFIFOSZ_SIZE_M     0x0000000F  // Max Packet Size
#define USB_TXFIFOSZ_SIZE_8     0x00000000  // 8
#define USB_TXFIFOSZ_SIZE_16    0x00000001  // 16
#define USB_TXFIFOSZ_SIZE_32    0x00000002  // 32
#define USB_TXFIFOSZ_SIZE_64    0x00000003  // 64
#define USB_TXFIFOSZ_SIZE_128   0x00000004  // 128
#define USB_TXFIFOSZ_SIZE_256   0x00000005  // 256
#define USB_TXFIFOSZ_SIZE_512   0x00000006  // 512
#define USB_TXFIFOSZ_SIZE_1024  0x00000007  // 1024
#define USB_TXFIFOSZ_SIZE_2048  0x00000008  // 2048

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXFIFOSZ register.
//
//*****************************************************************************
#define USB_RXFIFOSZ_DPB        0x00000010  // Double Packet Buffer Support
#define USB_RXFIFOSZ_SIZE_M     0x0000000F  // Max Packet Size
#define USB_RXFIFOSZ_SIZE_8     0x00000000  // 8
#define USB_RXFIFOSZ_SIZE_16    0x00000001  // 16
#define USB_RXFIFOSZ_SIZE_32    0x00000002  // 32
#define USB_RXFIFOSZ_SIZE_64    0x00000003  // 64
#define USB_RXFIFOSZ_SIZE_128   0x00000004  // 128
#define USB_RXFIFOSZ_SIZE_256   0x00000005  // 256
#define USB_RXFIFOSZ_SIZE_512   0x00000006  // 512
#define USB_RXFIFOSZ_SIZE_1024  0x00000007  // 1024
#define USB_RXFIFOSZ_SIZE_2048  0x00000008  // 2048

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXFIFOADD
// register.
//
//*****************************************************************************
#define USB_TXFIFOADD_ADDR_M    0x000001FF  // Transmit/Receive Start Address
#define USB_TXFIFOADD_ADDR_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXFIFOADD
// register.
//
//*****************************************************************************
#define USB_RXFIFOADD_ADDR_M    0x000001FF  // Transmit/Receive Start Address
#define USB_RXFIFOADD_ADDR_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_ULPIVBUSCTL
// register.
//
//*****************************************************************************
#define USB_ULPIVBUSCTL_USEEXTVBUSIND                                         \
                                0x00000002  // Use External VBUS Indicator
#define USB_ULPIVBUSCTL_USEEXTVBUS                                            \
                                0x00000001  // Use External VBUS

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_ULPIREGDATA
// register.
//
//*****************************************************************************
#define USB_ULPIREGDATA_REGDATA_M                                             \
                                0x000000FF  // Register Data
#define USB_ULPIREGDATA_REGDATA_S                                             \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_ULPIREGADDR
// register.
//
//*****************************************************************************
#define USB_ULPIREGADDR_ADDR_M  0x000000FF  // Register Address
#define USB_ULPIREGADDR_ADDR_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_ULPIREGCTL
// register.
//
//*****************************************************************************
#define USB_ULPIREGCTL_RDWR     0x00000004  // Read/Write Control
#define USB_ULPIREGCTL_REGCMPLT 0x00000002  // Register Access Complete
#define USB_ULPIREGCTL_REGACC   0x00000001  // Initiate Register Access

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_ULPIRAWDATA
// register.
//
//*****************************************************************************
#define USB_ULPIRAWDATA_WTCON_M 0x000000F0  // Connect Wait
#define USB_ULPIRAWDATA_WTID_M  0x0000000F  // Wait ID
#define USB_ULPIRAWDATA_WTCON_S 4
#define USB_ULPIRAWDATA_WTID_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_EPINFO register.
//
//*****************************************************************************
#define USB_EPINFO_RXEP_M       0x000000F0  // RX Endpoints
#define USB_EPINFO_TXEP_M       0x0000000F  // TX Endpoints
#define USB_EPINFO_RXEP_S       4
#define USB_EPINFO_TXEP_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RAMINFO register.
//
//*****************************************************************************
#define USB_RAMINFO_DMACHAN_M   0x000000F0  // DMA Channels
#define USB_RAMINFO_RAMBITS_M   0x0000000F  // RAM Address Bus Width
#define USB_RAMINFO_DMACHAN_S   4
#define USB_RAMINFO_RAMBITS_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_CONTIM register.
//
//*****************************************************************************
#define USB_CONTIM_WTCON_M      0x000000F0  // Connect Wait
#define USB_CONTIM_WTID_M       0x0000000F  // Wait ID
#define USB_CONTIM_WTCON_S      4
#define USB_CONTIM_WTID_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_VPLEN register.
//
//*****************************************************************************
#define USB_VPLEN_VPLEN_M       0x000000FF  // VBUS Pulse Length
#define USB_VPLEN_VPLEN_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_HSEOF register.
//
//*****************************************************************************
#define USB_HSEOF_HSEOFG_M      0x000000FF  // HIgh-Speed End-of-Frame Gap
#define USB_HSEOF_HSEOFG_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_FSEOF register.
//
//*****************************************************************************
#define USB_FSEOF_FSEOFG_M      0x000000FF  // Full-Speed End-of-Frame Gap
#define USB_FSEOF_FSEOFG_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_LSEOF register.
//
//*****************************************************************************
#define USB_LSEOF_LSEOFG_M      0x000000FF  // Low-Speed End-of-Frame Gap
#define USB_LSEOF_LSEOFG_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXFUNCADDR0
// register.
//
//*****************************************************************************
#define USB_TXFUNCADDR0_ADDR_M  0x0000007F  // Device Address
#define USB_TXFUNCADDR0_ADDR_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXHUBADDR0
// register.
//
//*****************************************************************************
#define USB_TXHUBADDR0_ADDR_M   0x0000007F  // Hub Address
#define USB_TXHUBADDR0_ADDR_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXHUBPORT0
// register.
//
//*****************************************************************************
#define USB_TXHUBPORT0_PORT_M   0x0000007F  // Hub Port
#define USB_TXHUBPORT0_PORT_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXFUNCADDR1
// register.
//
//*****************************************************************************
#define USB_TXFUNCADDR1_ADDR_M  0x0000007F  // Device Address
#define USB_TXFUNCADDR1_ADDR_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXHUBADDR1
// register.
//
//*****************************************************************************
#define USB_TXHUBADDR1_ADDR_M   0x0000007F  // Hub Address
#define USB_TXHUBADDR1_ADDR_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXHUBPORT1
// register.
//
//*****************************************************************************
#define USB_TXHUBPORT1_PORT_M   0x0000007F  // Hub Port
#define USB_TXHUBPORT1_PORT_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXFUNCADDR1
// register.
//
//*****************************************************************************
#define USB_RXFUNCADDR1_ADDR_M  0x0000007F  // Device Address
#define USB_RXFUNCADDR1_ADDR_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXHUBADDR1
// register.
//
//*****************************************************************************
#define USB_RXHUBADDR1_ADDR_M   0x0000007F  // Hub Address
#define USB_RXHUBADDR1_ADDR_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXHUBPORT1
// register.
//
//*****************************************************************************
#define USB_RXHUBPORT1_PORT_M   0x0000007F  // Hub Port
#define USB_RXHUBPORT1_PORT_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXFUNCADDR2
// register.
//
//*****************************************************************************
#define USB_TXFUNCADDR2_ADDR_M  0x0000007F  // Device Address
#define USB_TXFUNCADDR2_ADDR_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXHUBADDR2
// register.
//
//*****************************************************************************
#define USB_TXHUBADDR2_ADDR_M   0x0000007F  // Hub Address
#define USB_TXHUBADDR2_ADDR_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXHUBPORT2
// register.
//
//*****************************************************************************
#define USB_TXHUBPORT2_PORT_M   0x0000007F  // Hub Port
#define USB_TXHUBPORT2_PORT_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXFUNCADDR2
// register.
//
//*****************************************************************************
#define USB_RXFUNCADDR2_ADDR_M  0x0000007F  // Device Address
#define USB_RXFUNCADDR2_ADDR_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXHUBADDR2
// register.
//
//*****************************************************************************
#define USB_RXHUBADDR2_ADDR_M   0x0000007F  // Hub Address
#define USB_RXHUBADDR2_ADDR_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXHUBPORT2
// register.
//
//*****************************************************************************
#define USB_RXHUBPORT2_PORT_M   0x0000007F  // Hub Port
#define USB_RXHUBPORT2_PORT_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXFUNCADDR3
// register.
//
//*****************************************************************************
#define USB_TXFUNCADDR3_ADDR_M  0x0000007F  // Device Address
#define USB_TXFUNCADDR3_ADDR_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXHUBADDR3
// register.
//
//*****************************************************************************
#define USB_TXHUBADDR3_ADDR_M   0x0000007F  // Hub Address
#define USB_TXHUBADDR3_ADDR_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXHUBPORT3
// register.
//
//*****************************************************************************
#define USB_TXHUBPORT3_PORT_M   0x0000007F  // Hub Port
#define USB_TXHUBPORT3_PORT_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXFUNCADDR3
// register.
//
//*****************************************************************************
#define USB_RXFUNCADDR3_ADDR_M  0x0000007F  // Device Address
#define USB_RXFUNCADDR3_ADDR_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXHUBADDR3
// register.
//
//*****************************************************************************
#define USB_RXHUBADDR3_ADDR_M   0x0000007F  // Hub Address
#define USB_RXHUBADDR3_ADDR_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXHUBPORT3
// register.
//
//*****************************************************************************
#define USB_RXHUBPORT3_PORT_M   0x0000007F  // Hub Port
#define USB_RXHUBPORT3_PORT_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXFUNCADDR4
// register.
//
//*****************************************************************************
#define USB_TXFUNCADDR4_ADDR_M  0x0000007F  // Device Address
#define USB_TXFUNCADDR4_ADDR_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXHUBADDR4
// register.
//
//*****************************************************************************
#define USB_TXHUBADDR4_ADDR_M   0x0000007F  // Hub Address
#define USB_TXHUBADDR4_ADDR_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXHUBPORT4
// register.
//
//*****************************************************************************
#define USB_TXHUBPORT4_PORT_M   0x0000007F  // Hub Port
#define USB_TXHUBPORT4_PORT_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXFUNCADDR4
// register.
//
//*****************************************************************************
#define USB_RXFUNCADDR4_ADDR_M  0x0000007F  // Device Address
#define USB_RXFUNCADDR4_ADDR_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXHUBADDR4
// register.
//
//*****************************************************************************
#define USB_RXHUBADDR4_ADDR_M   0x0000007F  // Hub Address
#define USB_RXHUBADDR4_ADDR_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXHUBPORT4
// register.
//
//*****************************************************************************
#define USB_RXHUBPORT4_PORT_M   0x0000007F  // Hub Port
#define USB_RXHUBPORT4_PORT_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXFUNCADDR5
// register.
//
//*****************************************************************************
#define USB_TXFUNCADDR5_ADDR_M  0x0000007F  // Device Address
#define USB_TXFUNCADDR5_ADDR_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXHUBADDR5
// register.
//
//*****************************************************************************
#define USB_TXHUBADDR5_ADDR_M   0x0000007F  // Hub Address
#define USB_TXHUBADDR5_ADDR_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXHUBPORT5
// register.
//
//*****************************************************************************
#define USB_TXHUBPORT5_PORT_M   0x0000007F  // Hub Port
#define USB_TXHUBPORT5_PORT_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXFUNCADDR5
// register.
//
//*****************************************************************************
#define USB_RXFUNCADDR5_ADDR_M  0x0000007F  // Device Address
#define USB_RXFUNCADDR5_ADDR_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXHUBADDR5
// register.
//
//*****************************************************************************
#define USB_RXHUBADDR5_ADDR_M   0x0000007F  // Hub Address
#define USB_RXHUBADDR5_ADDR_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXHUBPORT5
// register.
//
//*****************************************************************************
#define USB_RXHUBPORT5_PORT_M   0x0000007F  // Hub Port
#define USB_RXHUBPORT5_PORT_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXFUNCADDR6
// register.
//
//*****************************************************************************
#define USB_TXFUNCADDR6_ADDR_M  0x0000007F  // Device Address
#define USB_TXFUNCADDR6_ADDR_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXHUBADDR6
// register.
//
//*****************************************************************************
#define USB_TXHUBADDR6_ADDR_M   0x0000007F  // Hub Address
#define USB_TXHUBADDR6_ADDR_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXHUBPORT6
// register.
//
//*****************************************************************************
#define USB_TXHUBPORT6_PORT_M   0x0000007F  // Hub Port
#define USB_TXHUBPORT6_PORT_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXFUNCADDR6
// register.
//
//*****************************************************************************
#define USB_RXFUNCADDR6_ADDR_M  0x0000007F  // Device Address
#define USB_RXFUNCADDR6_ADDR_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXHUBADDR6
// register.
//
//*****************************************************************************
#define USB_RXHUBADDR6_ADDR_M   0x0000007F  // Hub Address
#define USB_RXHUBADDR6_ADDR_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXHUBPORT6
// register.
//
//*****************************************************************************
#define USB_RXHUBPORT6_PORT_M   0x0000007F  // Hub Port
#define USB_RXHUBPORT6_PORT_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXFUNCADDR7
// register.
//
//*****************************************************************************
#define USB_TXFUNCADDR7_ADDR_M  0x0000007F  // Device Address
#define USB_TXFUNCADDR7_ADDR_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXHUBADDR7
// register.
//
//*****************************************************************************
#define USB_TXHUBADDR7_ADDR_M   0x0000007F  // Hub Address
#define USB_TXHUBADDR7_ADDR_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXHUBPORT7
// register.
//
//*****************************************************************************
#define USB_TXHUBPORT7_PORT_M   0x0000007F  // Hub Port
#define USB_TXHUBPORT7_PORT_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXFUNCADDR7
// register.
//
//*****************************************************************************
#define USB_RXFUNCADDR7_ADDR_M  0x0000007F  // Device Address
#define USB_RXFUNCADDR7_ADDR_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXHUBADDR7
// register.
//
//*****************************************************************************
#define USB_RXHUBADDR7_ADDR_M   0x0000007F  // Hub Address
#define USB_RXHUBADDR7_ADDR_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXHUBPORT7
// register.
//
//*****************************************************************************
#define USB_RXHUBPORT7_PORT_M   0x0000007F  // Hub Port
#define USB_RXHUBPORT7_PORT_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_CSRL0 register.
//
//*****************************************************************************
#define USB_CSRL0_NAKTO         0x00000080  // NAK Timeout
#define USB_CSRL0_SETENDC       0x00000080  // Setup End Clear
#define USB_CSRL0_STATUS        0x00000040  // STATUS Packet
#define USB_CSRL0_RXRDYC        0x00000040  // RXRDY Clear
#define USB_CSRL0_REQPKT        0x00000020  // Request Packet
#define USB_CSRL0_STALL         0x00000020  // Send Stall
#define USB_CSRL0_SETEND        0x00000010  // Setup End
#define USB_CSRL0_ERROR         0x00000010  // Error
#define USB_CSRL0_DATAEND       0x00000008  // Data End
#define USB_CSRL0_SETUP         0x00000008  // Setup Packet
#define USB_CSRL0_STALLED       0x00000004  // Endpoint Stalled
#define USB_CSRL0_TXRDY         0x00000002  // Transmit Packet Ready
#define USB_CSRL0_RXRDY         0x00000001  // Receive Packet Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_CSRH0 register.
//
//*****************************************************************************
#define USB_CSRH0_DISPING       0x00000008  // PING Disable
#define USB_CSRH0_DTWE          0x00000004  // Data Toggle Write Enable
#define USB_CSRH0_DT            0x00000002  // Data Toggle
#define USB_CSRH0_FLUSH         0x00000001  // Flush FIFO

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_COUNT0 register.
//
//*****************************************************************************
#define USB_COUNT0_COUNT_M      0x0000007F  // FIFO Count
#define USB_COUNT0_COUNT_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TYPE0 register.
//
//*****************************************************************************
#define USB_TYPE0_SPEED_M       0x000000C0  // Operating Speed
#define USB_TYPE0_SPEED_HIGH    0x00000040  // High
#define USB_TYPE0_SPEED_FULL    0x00000080  // Full
#define USB_TYPE0_SPEED_LOW     0x000000C0  // Low

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_NAKLMT register.
//
//*****************************************************************************
#define USB_NAKLMT_NAKLMT_M     0x0000001F  // EP0 NAK Limit
#define USB_NAKLMT_NAKLMT_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXMAXP1 register.
//
//*****************************************************************************
#define USB_TXMAXP1_MAXLOAD_M   0x000007FF  // Maximum Payload
#define USB_TXMAXP1_MAXLOAD_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXCSRL1 register.
//
//*****************************************************************************
#define USB_TXCSRL1_NAKTO       0x00000080  // NAK Timeout
#define USB_TXCSRL1_CLRDT       0x00000040  // Clear Data Toggle
#define USB_TXCSRL1_STALLED     0x00000020  // Endpoint Stalled
#define USB_TXCSRL1_STALL       0x00000010  // Send STALL
#define USB_TXCSRL1_SETUP       0x00000010  // Setup Packet
#define USB_TXCSRL1_FLUSH       0x00000008  // Flush FIFO
#define USB_TXCSRL1_ERROR       0x00000004  // Error
#define USB_TXCSRL1_UNDRN       0x00000004  // Underrun
#define USB_TXCSRL1_FIFONE      0x00000002  // FIFO Not Empty
#define USB_TXCSRL1_TXRDY       0x00000001  // Transmit Packet Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXCSRH1 register.
//
//*****************************************************************************
#define USB_TXCSRH1_AUTOSET     0x00000080  // Auto Set
#define USB_TXCSRH1_ISO         0x00000040  // Isochronous Transfers
#define USB_TXCSRH1_MODE        0x00000020  // Mode
#define USB_TXCSRH1_DMAEN       0x00000010  // DMA Request Enable
#define USB_TXCSRH1_FDT         0x00000008  // Force Data Toggle
#define USB_TXCSRH1_DMAMOD      0x00000004  // DMA Request Mode
#define USB_TXCSRH1_DTWE        0x00000002  // Data Toggle Write Enable
#define USB_TXCSRH1_DT          0x00000001  // Data Toggle

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXMAXP1 register.
//
//*****************************************************************************
#define USB_RXMAXP1_MAXLOAD_M   0x000007FF  // Maximum Payload
#define USB_RXMAXP1_MAXLOAD_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXCSRL1 register.
//
//*****************************************************************************
#define USB_RXCSRL1_CLRDT       0x00000080  // Clear Data Toggle
#define USB_RXCSRL1_STALLED     0x00000040  // Endpoint Stalled
#define USB_RXCSRL1_STALL       0x00000020  // Send STALL
#define USB_RXCSRL1_REQPKT      0x00000020  // Request Packet
#define USB_RXCSRL1_FLUSH       0x00000010  // Flush FIFO
#define USB_RXCSRL1_DATAERR     0x00000008  // Data Error
#define USB_RXCSRL1_NAKTO       0x00000008  // NAK Timeout
#define USB_RXCSRL1_OVER        0x00000004  // Overrun
#define USB_RXCSRL1_ERROR       0x00000004  // Error
#define USB_RXCSRL1_FULL        0x00000002  // FIFO Full
#define USB_RXCSRL1_RXRDY       0x00000001  // Receive Packet Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXCSRH1 register.
//
//*****************************************************************************
#define USB_RXCSRH1_AUTOCL      0x00000080  // Auto Clear
#define USB_RXCSRH1_AUTORQ      0x00000040  // Auto Request
#define USB_RXCSRH1_ISO         0x00000040  // Isochronous Transfers
#define USB_RXCSRH1_DMAEN       0x00000020  // DMA Request Enable
#define USB_RXCSRH1_DISNYET     0x00000010  // Disable NYET
#define USB_RXCSRH1_PIDERR      0x00000010  // PID Error
#define USB_RXCSRH1_DMAMOD      0x00000008  // DMA Request Mode
#define USB_RXCSRH1_DTWE        0x00000004  // Data Toggle Write Enable
#define USB_RXCSRH1_DT          0x00000002  // Data Toggle
#define USB_RXCSRH1_INCOMPRX    0x00000001  // Incomplete RX Transmission
                                            // Status

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXCOUNT1 register.
//
//*****************************************************************************
#define USB_RXCOUNT1_COUNT_M    0x00001FFF  // Receive Packet Count
#define USB_RXCOUNT1_COUNT_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXTYPE1 register.
//
//*****************************************************************************
#define USB_TXTYPE1_SPEED_M     0x000000C0  // Operating Speed
#define USB_TXTYPE1_SPEED_DFLT  0x00000000  // Default
#define USB_TXTYPE1_SPEED_HIGH  0x00000040  // High
#define USB_TXTYPE1_SPEED_FULL  0x00000080  // Full
#define USB_TXTYPE1_SPEED_LOW   0x000000C0  // Low
#define USB_TXTYPE1_PROTO_M     0x00000030  // Protocol
#define USB_TXTYPE1_PROTO_CTRL  0x00000000  // Control
#define USB_TXTYPE1_PROTO_ISOC  0x00000010  // Isochronous
#define USB_TXTYPE1_PROTO_BULK  0x00000020  // Bulk
#define USB_TXTYPE1_PROTO_INT   0x00000030  // Interrupt
#define USB_TXTYPE1_TEP_M       0x0000000F  // Target Endpoint Number
#define USB_TXTYPE1_TEP_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXINTERVAL1
// register.
//
//*****************************************************************************
#define USB_TXINTERVAL1_NAKLMT_M                                              \
                                0x000000FF  // NAK Limit
#define USB_TXINTERVAL1_TXPOLL_M                                              \
                                0x000000FF  // TX Polling
#define USB_TXINTERVAL1_TXPOLL_S                                              \
                                0
#define USB_TXINTERVAL1_NAKLMT_S                                              \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXTYPE1 register.
//
//*****************************************************************************
#define USB_RXTYPE1_SPEED_M     0x000000C0  // Operating Speed
#define USB_RXTYPE1_SPEED_DFLT  0x00000000  // Default
#define USB_RXTYPE1_SPEED_HIGH  0x00000040  // High
#define USB_RXTYPE1_SPEED_FULL  0x00000080  // Full
#define USB_RXTYPE1_SPEED_LOW   0x000000C0  // Low
#define USB_RXTYPE1_PROTO_M     0x00000030  // Protocol
#define USB_RXTYPE1_PROTO_CTRL  0x00000000  // Control
#define USB_RXTYPE1_PROTO_ISOC  0x00000010  // Isochronous
#define USB_RXTYPE1_PROTO_BULK  0x00000020  // Bulk
#define USB_RXTYPE1_PROTO_INT   0x00000030  // Interrupt
#define USB_RXTYPE1_TEP_M       0x0000000F  // Target Endpoint Number
#define USB_RXTYPE1_TEP_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXINTERVAL1
// register.
//
//*****************************************************************************
#define USB_RXINTERVAL1_TXPOLL_M                                              \
                                0x000000FF  // RX Polling
#define USB_RXINTERVAL1_NAKLMT_M                                              \
                                0x000000FF  // NAK Limit
#define USB_RXINTERVAL1_TXPOLL_S                                              \
                                0
#define USB_RXINTERVAL1_NAKLMT_S                                              \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXMAXP2 register.
//
//*****************************************************************************
#define USB_TXMAXP2_MAXLOAD_M   0x000007FF  // Maximum Payload
#define USB_TXMAXP2_MAXLOAD_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXCSRL2 register.
//
//*****************************************************************************
#define USB_TXCSRL2_NAKTO       0x00000080  // NAK Timeout
#define USB_TXCSRL2_CLRDT       0x00000040  // Clear Data Toggle
#define USB_TXCSRL2_STALLED     0x00000020  // Endpoint Stalled
#define USB_TXCSRL2_SETUP       0x00000010  // Setup Packet
#define USB_TXCSRL2_STALL       0x00000010  // Send STALL
#define USB_TXCSRL2_FLUSH       0x00000008  // Flush FIFO
#define USB_TXCSRL2_ERROR       0x00000004  // Error
#define USB_TXCSRL2_UNDRN       0x00000004  // Underrun
#define USB_TXCSRL2_FIFONE      0x00000002  // FIFO Not Empty
#define USB_TXCSRL2_TXRDY       0x00000001  // Transmit Packet Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXCSRH2 register.
//
//*****************************************************************************
#define USB_TXCSRH2_AUTOSET     0x00000080  // Auto Set
#define USB_TXCSRH2_ISO         0x00000040  // Isochronous Transfers
#define USB_TXCSRH2_MODE        0x00000020  // Mode
#define USB_TXCSRH2_DMAEN       0x00000010  // DMA Request Enable
#define USB_TXCSRH2_FDT         0x00000008  // Force Data Toggle
#define USB_TXCSRH2_DMAMOD      0x00000004  // DMA Request Mode
#define USB_TXCSRH2_DTWE        0x00000002  // Data Toggle Write Enable
#define USB_TXCSRH2_DT          0x00000001  // Data Toggle

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXMAXP2 register.
//
//*****************************************************************************
#define USB_RXMAXP2_MAXLOAD_M   0x000007FF  // Maximum Payload
#define USB_RXMAXP2_MAXLOAD_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXCSRL2 register.
//
//*****************************************************************************
#define USB_RXCSRL2_CLRDT       0x00000080  // Clear Data Toggle
#define USB_RXCSRL2_STALLED     0x00000040  // Endpoint Stalled
#define USB_RXCSRL2_REQPKT      0x00000020  // Request Packet
#define USB_RXCSRL2_STALL       0x00000020  // Send STALL
#define USB_RXCSRL2_FLUSH       0x00000010  // Flush FIFO
#define USB_RXCSRL2_DATAERR     0x00000008  // Data Error
#define USB_RXCSRL2_NAKTO       0x00000008  // NAK Timeout
#define USB_RXCSRL2_ERROR       0x00000004  // Error
#define USB_RXCSRL2_OVER        0x00000004  // Overrun
#define USB_RXCSRL2_FULL        0x00000002  // FIFO Full
#define USB_RXCSRL2_RXRDY       0x00000001  // Receive Packet Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXCSRH2 register.
//
//*****************************************************************************
#define USB_RXCSRH2_AUTOCL      0x00000080  // Auto Clear
#define USB_RXCSRH2_AUTORQ      0x00000040  // Auto Request
#define USB_RXCSRH2_ISO         0x00000040  // Isochronous Transfers
#define USB_RXCSRH2_DMAEN       0x00000020  // DMA Request Enable
#define USB_RXCSRH2_DISNYET     0x00000010  // Disable NYET
#define USB_RXCSRH2_PIDERR      0x00000010  // PID Error
#define USB_RXCSRH2_DMAMOD      0x00000008  // DMA Request Mode
#define USB_RXCSRH2_DTWE        0x00000004  // Data Toggle Write Enable
#define USB_RXCSRH2_DT          0x00000002  // Data Toggle
#define USB_RXCSRH2_INCOMPRX    0x00000001  // Incomplete RX Transmission
                                            // Status

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXCOUNT2 register.
//
//*****************************************************************************
#define USB_RXCOUNT2_COUNT_M    0x00001FFF  // Receive Packet Count
#define USB_RXCOUNT2_COUNT_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXTYPE2 register.
//
//*****************************************************************************
#define USB_TXTYPE2_SPEED_M     0x000000C0  // Operating Speed
#define USB_TXTYPE2_SPEED_DFLT  0x00000000  // Default
#define USB_TXTYPE2_SPEED_HIGH  0x00000040  // High
#define USB_TXTYPE2_SPEED_FULL  0x00000080  // Full
#define USB_TXTYPE2_SPEED_LOW   0x000000C0  // Low
#define USB_TXTYPE2_PROTO_M     0x00000030  // Protocol
#define USB_TXTYPE2_PROTO_CTRL  0x00000000  // Control
#define USB_TXTYPE2_PROTO_ISOC  0x00000010  // Isochronous
#define USB_TXTYPE2_PROTO_BULK  0x00000020  // Bulk
#define USB_TXTYPE2_PROTO_INT   0x00000030  // Interrupt
#define USB_TXTYPE2_TEP_M       0x0000000F  // Target Endpoint Number
#define USB_TXTYPE2_TEP_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXINTERVAL2
// register.
//
//*****************************************************************************
#define USB_TXINTERVAL2_TXPOLL_M                                              \
                                0x000000FF  // TX Polling
#define USB_TXINTERVAL2_NAKLMT_M                                              \
                                0x000000FF  // NAK Limit
#define USB_TXINTERVAL2_NAKLMT_S                                              \
                                0
#define USB_TXINTERVAL2_TXPOLL_S                                              \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXTYPE2 register.
//
//*****************************************************************************
#define USB_RXTYPE2_SPEED_M     0x000000C0  // Operating Speed
#define USB_RXTYPE2_SPEED_DFLT  0x00000000  // Default
#define USB_RXTYPE2_SPEED_HIGH  0x00000040  // High
#define USB_RXTYPE2_SPEED_FULL  0x00000080  // Full
#define USB_RXTYPE2_SPEED_LOW   0x000000C0  // Low
#define USB_RXTYPE2_PROTO_M     0x00000030  // Protocol
#define USB_RXTYPE2_PROTO_CTRL  0x00000000  // Control
#define USB_RXTYPE2_PROTO_ISOC  0x00000010  // Isochronous
#define USB_RXTYPE2_PROTO_BULK  0x00000020  // Bulk
#define USB_RXTYPE2_PROTO_INT   0x00000030  // Interrupt
#define USB_RXTYPE2_TEP_M       0x0000000F  // Target Endpoint Number
#define USB_RXTYPE2_TEP_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXINTERVAL2
// register.
//
//*****************************************************************************
#define USB_RXINTERVAL2_TXPOLL_M                                              \
                                0x000000FF  // RX Polling
#define USB_RXINTERVAL2_NAKLMT_M                                              \
                                0x000000FF  // NAK Limit
#define USB_RXINTERVAL2_TXPOLL_S                                              \
                                0
#define USB_RXINTERVAL2_NAKLMT_S                                              \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXMAXP3 register.
//
//*****************************************************************************
#define USB_TXMAXP3_MAXLOAD_M   0x000007FF  // Maximum Payload
#define USB_TXMAXP3_MAXLOAD_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXCSRL3 register.
//
//*****************************************************************************
#define USB_TXCSRL3_NAKTO       0x00000080  // NAK Timeout
#define USB_TXCSRL3_CLRDT       0x00000040  // Clear Data Toggle
#define USB_TXCSRL3_STALLED     0x00000020  // Endpoint Stalled
#define USB_TXCSRL3_SETUP       0x00000010  // Setup Packet
#define USB_TXCSRL3_STALL       0x00000010  // Send STALL
#define USB_TXCSRL3_FLUSH       0x00000008  // Flush FIFO
#define USB_TXCSRL3_ERROR       0x00000004  // Error
#define USB_TXCSRL3_UNDRN       0x00000004  // Underrun
#define USB_TXCSRL3_FIFONE      0x00000002  // FIFO Not Empty
#define USB_TXCSRL3_TXRDY       0x00000001  // Transmit Packet Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXCSRH3 register.
//
//*****************************************************************************
#define USB_TXCSRH3_AUTOSET     0x00000080  // Auto Set
#define USB_TXCSRH3_ISO         0x00000040  // Isochronous Transfers
#define USB_TXCSRH3_MODE        0x00000020  // Mode
#define USB_TXCSRH3_DMAEN       0x00000010  // DMA Request Enable
#define USB_TXCSRH3_FDT         0x00000008  // Force Data Toggle
#define USB_TXCSRH3_DMAMOD      0x00000004  // DMA Request Mode
#define USB_TXCSRH3_DTWE        0x00000002  // Data Toggle Write Enable
#define USB_TXCSRH3_DT          0x00000001  // Data Toggle

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXMAXP3 register.
//
//*****************************************************************************
#define USB_RXMAXP3_MAXLOAD_M   0x000007FF  // Maximum Payload
#define USB_RXMAXP3_MAXLOAD_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXCSRL3 register.
//
//*****************************************************************************
#define USB_RXCSRL3_CLRDT       0x00000080  // Clear Data Toggle
#define USB_RXCSRL3_STALLED     0x00000040  // Endpoint Stalled
#define USB_RXCSRL3_STALL       0x00000020  // Send STALL
#define USB_RXCSRL3_REQPKT      0x00000020  // Request Packet
#define USB_RXCSRL3_FLUSH       0x00000010  // Flush FIFO
#define USB_RXCSRL3_DATAERR     0x00000008  // Data Error
#define USB_RXCSRL3_NAKTO       0x00000008  // NAK Timeout
#define USB_RXCSRL3_ERROR       0x00000004  // Error
#define USB_RXCSRL3_OVER        0x00000004  // Overrun
#define USB_RXCSRL3_FULL        0x00000002  // FIFO Full
#define USB_RXCSRL3_RXRDY       0x00000001  // Receive Packet Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXCSRH3 register.
//
//*****************************************************************************
#define USB_RXCSRH3_AUTOCL      0x00000080  // Auto Clear
#define USB_RXCSRH3_AUTORQ      0x00000040  // Auto Request
#define USB_RXCSRH3_ISO         0x00000040  // Isochronous Transfers
#define USB_RXCSRH3_DMAEN       0x00000020  // DMA Request Enable
#define USB_RXCSRH3_DISNYET     0x00000010  // Disable NYET
#define USB_RXCSRH3_PIDERR      0x00000010  // PID Error
#define USB_RXCSRH3_DMAMOD      0x00000008  // DMA Request Mode
#define USB_RXCSRH3_DTWE        0x00000004  // Data Toggle Write Enable
#define USB_RXCSRH3_DT          0x00000002  // Data Toggle
#define USB_RXCSRH3_INCOMPRX    0x00000001  // Incomplete RX Transmission
                                            // Status

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXCOUNT3 register.
//
//*****************************************************************************
#define USB_RXCOUNT3_COUNT_M    0x00001FFF  // Receive Packet Count
#define USB_RXCOUNT3_COUNT_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXTYPE3 register.
//
//*****************************************************************************
#define USB_TXTYPE3_SPEED_M     0x000000C0  // Operating Speed
#define USB_TXTYPE3_SPEED_DFLT  0x00000000  // Default
#define USB_TXTYPE3_SPEED_HIGH  0x00000040  // High
#define USB_TXTYPE3_SPEED_FULL  0x00000080  // Full
#define USB_TXTYPE3_SPEED_LOW   0x000000C0  // Low
#define USB_TXTYPE3_PROTO_M     0x00000030  // Protocol
#define USB_TXTYPE3_PROTO_CTRL  0x00000000  // Control
#define USB_TXTYPE3_PROTO_ISOC  0x00000010  // Isochronous
#define USB_TXTYPE3_PROTO_BULK  0x00000020  // Bulk
#define USB_TXTYPE3_PROTO_INT   0x00000030  // Interrupt
#define USB_TXTYPE3_TEP_M       0x0000000F  // Target Endpoint Number
#define USB_TXTYPE3_TEP_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXINTERVAL3
// register.
//
//*****************************************************************************
#define USB_TXINTERVAL3_TXPOLL_M                                              \
                                0x000000FF  // TX Polling
#define USB_TXINTERVAL3_NAKLMT_M                                              \
                                0x000000FF  // NAK Limit
#define USB_TXINTERVAL3_TXPOLL_S                                              \
                                0
#define USB_TXINTERVAL3_NAKLMT_S                                              \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXTYPE3 register.
//
//*****************************************************************************
#define USB_RXTYPE3_SPEED_M     0x000000C0  // Operating Speed
#define USB_RXTYPE3_SPEED_DFLT  0x00000000  // Default
#define USB_RXTYPE3_SPEED_HIGH  0x00000040  // High
#define USB_RXTYPE3_SPEED_FULL  0x00000080  // Full
#define USB_RXTYPE3_SPEED_LOW   0x000000C0  // Low
#define USB_RXTYPE3_PROTO_M     0x00000030  // Protocol
#define USB_RXTYPE3_PROTO_CTRL  0x00000000  // Control
#define USB_RXTYPE3_PROTO_ISOC  0x00000010  // Isochronous
#define USB_RXTYPE3_PROTO_BULK  0x00000020  // Bulk
#define USB_RXTYPE3_PROTO_INT   0x00000030  // Interrupt
#define USB_RXTYPE3_TEP_M       0x0000000F  // Target Endpoint Number
#define USB_RXTYPE3_TEP_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXINTERVAL3
// register.
//
//*****************************************************************************
#define USB_RXINTERVAL3_TXPOLL_M                                              \
                                0x000000FF  // RX Polling
#define USB_RXINTERVAL3_NAKLMT_M                                              \
                                0x000000FF  // NAK Limit
#define USB_RXINTERVAL3_TXPOLL_S                                              \
                                0
#define USB_RXINTERVAL3_NAKLMT_S                                              \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXMAXP4 register.
//
//*****************************************************************************
#define USB_TXMAXP4_MAXLOAD_M   0x000007FF  // Maximum Payload
#define USB_TXMAXP4_MAXLOAD_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXCSRL4 register.
//
//*****************************************************************************
#define USB_TXCSRL4_NAKTO       0x00000080  // NAK Timeout
#define USB_TXCSRL4_CLRDT       0x00000040  // Clear Data Toggle
#define USB_TXCSRL4_STALLED     0x00000020  // Endpoint Stalled
#define USB_TXCSRL4_SETUP       0x00000010  // Setup Packet
#define USB_TXCSRL4_STALL       0x00000010  // Send STALL
#define USB_TXCSRL4_FLUSH       0x00000008  // Flush FIFO
#define USB_TXCSRL4_ERROR       0x00000004  // Error
#define USB_TXCSRL4_UNDRN       0x00000004  // Underrun
#define USB_TXCSRL4_FIFONE      0x00000002  // FIFO Not Empty
#define USB_TXCSRL4_TXRDY       0x00000001  // Transmit Packet Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXCSRH4 register.
//
//*****************************************************************************
#define USB_TXCSRH4_AUTOSET     0x00000080  // Auto Set
#define USB_TXCSRH4_ISO         0x00000040  // Isochronous Transfers
#define USB_TXCSRH4_MODE        0x00000020  // Mode
#define USB_TXCSRH4_DMAEN       0x00000010  // DMA Request Enable
#define USB_TXCSRH4_FDT         0x00000008  // Force Data Toggle
#define USB_TXCSRH4_DMAMOD      0x00000004  // DMA Request Mode
#define USB_TXCSRH4_DTWE        0x00000002  // Data Toggle Write Enable
#define USB_TXCSRH4_DT          0x00000001  // Data Toggle

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXMAXP4 register.
//
//*****************************************************************************
#define USB_RXMAXP4_MAXLOAD_M   0x000007FF  // Maximum Payload
#define USB_RXMAXP4_MAXLOAD_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXCSRL4 register.
//
//*****************************************************************************
#define USB_RXCSRL4_CLRDT       0x00000080  // Clear Data Toggle
#define USB_RXCSRL4_STALLED     0x00000040  // Endpoint Stalled
#define USB_RXCSRL4_STALL       0x00000020  // Send STALL
#define USB_RXCSRL4_REQPKT      0x00000020  // Request Packet
#define USB_RXCSRL4_FLUSH       0x00000010  // Flush FIFO
#define USB_RXCSRL4_NAKTO       0x00000008  // NAK Timeout
#define USB_RXCSRL4_DATAERR     0x00000008  // Data Error
#define USB_RXCSRL4_OVER        0x00000004  // Overrun
#define USB_RXCSRL4_ERROR       0x00000004  // Error
#define USB_RXCSRL4_FULL        0x00000002  // FIFO Full
#define USB_RXCSRL4_RXRDY       0x00000001  // Receive Packet Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXCSRH4 register.
//
//*****************************************************************************
#define USB_RXCSRH4_AUTOCL      0x00000080  // Auto Clear
#define USB_RXCSRH4_AUTORQ      0x00000040  // Auto Request
#define USB_RXCSRH4_ISO         0x00000040  // Isochronous Transfers
#define USB_RXCSRH4_DMAEN       0x00000020  // DMA Request Enable
#define USB_RXCSRH4_DISNYET     0x00000010  // Disable NYET
#define USB_RXCSRH4_PIDERR      0x00000010  // PID Error
#define USB_RXCSRH4_DMAMOD      0x00000008  // DMA Request Mode
#define USB_RXCSRH4_DTWE        0x00000004  // Data Toggle Write Enable
#define USB_RXCSRH4_DT          0x00000002  // Data Toggle
#define USB_RXCSRH4_INCOMPRX    0x00000001  // Incomplete RX Transmission
                                            // Status

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXCOUNT4 register.
//
//*****************************************************************************
#define USB_RXCOUNT4_COUNT_M    0x00001FFF  // Receive Packet Count
#define USB_RXCOUNT4_COUNT_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXTYPE4 register.
//
//*****************************************************************************
#define USB_TXTYPE4_SPEED_M     0x000000C0  // Operating Speed
#define USB_TXTYPE4_SPEED_DFLT  0x00000000  // Default
#define USB_TXTYPE4_SPEED_HIGH  0x00000040  // High
#define USB_TXTYPE4_SPEED_FULL  0x00000080  // Full
#define USB_TXTYPE4_SPEED_LOW   0x000000C0  // Low
#define USB_TXTYPE4_PROTO_M     0x00000030  // Protocol
#define USB_TXTYPE4_PROTO_CTRL  0x00000000  // Control
#define USB_TXTYPE4_PROTO_ISOC  0x00000010  // Isochronous
#define USB_TXTYPE4_PROTO_BULK  0x00000020  // Bulk
#define USB_TXTYPE4_PROTO_INT   0x00000030  // Interrupt
#define USB_TXTYPE4_TEP_M       0x0000000F  // Target Endpoint Number
#define USB_TXTYPE4_TEP_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXINTERVAL4
// register.
//
//*****************************************************************************
#define USB_TXINTERVAL4_TXPOLL_M                                              \
                                0x000000FF  // TX Polling
#define USB_TXINTERVAL4_NAKLMT_M                                              \
                                0x000000FF  // NAK Limit
#define USB_TXINTERVAL4_NAKLMT_S                                              \
                                0
#define USB_TXINTERVAL4_TXPOLL_S                                              \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXTYPE4 register.
//
//*****************************************************************************
#define USB_RXTYPE4_SPEED_M     0x000000C0  // Operating Speed
#define USB_RXTYPE4_SPEED_DFLT  0x00000000  // Default
#define USB_RXTYPE4_SPEED_HIGH  0x00000040  // High
#define USB_RXTYPE4_SPEED_FULL  0x00000080  // Full
#define USB_RXTYPE4_SPEED_LOW   0x000000C0  // Low
#define USB_RXTYPE4_PROTO_M     0x00000030  // Protocol
#define USB_RXTYPE4_PROTO_CTRL  0x00000000  // Control
#define USB_RXTYPE4_PROTO_ISOC  0x00000010  // Isochronous
#define USB_RXTYPE4_PROTO_BULK  0x00000020  // Bulk
#define USB_RXTYPE4_PROTO_INT   0x00000030  // Interrupt
#define USB_RXTYPE4_TEP_M       0x0000000F  // Target Endpoint Number
#define USB_RXTYPE4_TEP_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXINTERVAL4
// register.
//
//*****************************************************************************
#define USB_RXINTERVAL4_TXPOLL_M                                              \
                                0x000000FF  // RX Polling
#define USB_RXINTERVAL4_NAKLMT_M                                              \
                                0x000000FF  // NAK Limit
#define USB_RXINTERVAL4_NAKLMT_S                                              \
                                0
#define USB_RXINTERVAL4_TXPOLL_S                                              \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXMAXP5 register.
//
//*****************************************************************************
#define USB_TXMAXP5_MAXLOAD_M   0x000007FF  // Maximum Payload
#define USB_TXMAXP5_MAXLOAD_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXCSRL5 register.
//
//*****************************************************************************
#define USB_TXCSRL5_NAKTO       0x00000080  // NAK Timeout
#define USB_TXCSRL5_CLRDT       0x00000040  // Clear Data Toggle
#define USB_TXCSRL5_STALLED     0x00000020  // Endpoint Stalled
#define USB_TXCSRL5_SETUP       0x00000010  // Setup Packet
#define USB_TXCSRL5_STALL       0x00000010  // Send STALL
#define USB_TXCSRL5_FLUSH       0x00000008  // Flush FIFO
#define USB_TXCSRL5_ERROR       0x00000004  // Error
#define USB_TXCSRL5_UNDRN       0x00000004  // Underrun
#define USB_TXCSRL5_FIFONE      0x00000002  // FIFO Not Empty
#define USB_TXCSRL5_TXRDY       0x00000001  // Transmit Packet Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXCSRH5 register.
//
//*****************************************************************************
#define USB_TXCSRH5_AUTOSET     0x00000080  // Auto Set
#define USB_TXCSRH5_ISO         0x00000040  // Isochronous Transfers
#define USB_TXCSRH5_MODE        0x00000020  // Mode
#define USB_TXCSRH5_DMAEN       0x00000010  // DMA Request Enable
#define USB_TXCSRH5_FDT         0x00000008  // Force Data Toggle
#define USB_TXCSRH5_DMAMOD      0x00000004  // DMA Request Mode
#define USB_TXCSRH5_DTWE        0x00000002  // Data Toggle Write Enable
#define USB_TXCSRH5_DT          0x00000001  // Data Toggle

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXMAXP5 register.
//
//*****************************************************************************
#define USB_RXMAXP5_MAXLOAD_M   0x000007FF  // Maximum Payload
#define USB_RXMAXP5_MAXLOAD_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXCSRL5 register.
//
//*****************************************************************************
#define USB_RXCSRL5_CLRDT       0x00000080  // Clear Data Toggle
#define USB_RXCSRL5_STALLED     0x00000040  // Endpoint Stalled
#define USB_RXCSRL5_STALL       0x00000020  // Send STALL
#define USB_RXCSRL5_REQPKT      0x00000020  // Request Packet
#define USB_RXCSRL5_FLUSH       0x00000010  // Flush FIFO
#define USB_RXCSRL5_NAKTO       0x00000008  // NAK Timeout
#define USB_RXCSRL5_DATAERR     0x00000008  // Data Error
#define USB_RXCSRL5_ERROR       0x00000004  // Error
#define USB_RXCSRL5_OVER        0x00000004  // Overrun
#define USB_RXCSRL5_FULL        0x00000002  // FIFO Full
#define USB_RXCSRL5_RXRDY       0x00000001  // Receive Packet Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXCSRH5 register.
//
//*****************************************************************************
#define USB_RXCSRH5_AUTOCL      0x00000080  // Auto Clear
#define USB_RXCSRH5_AUTORQ      0x00000040  // Auto Request
#define USB_RXCSRH5_ISO         0x00000040  // Isochronous Transfers
#define USB_RXCSRH5_DMAEN       0x00000020  // DMA Request Enable
#define USB_RXCSRH5_DISNYET     0x00000010  // Disable NYET
#define USB_RXCSRH5_PIDERR      0x00000010  // PID Error
#define USB_RXCSRH5_DMAMOD      0x00000008  // DMA Request Mode
#define USB_RXCSRH5_DTWE        0x00000004  // Data Toggle Write Enable
#define USB_RXCSRH5_DT          0x00000002  // Data Toggle
#define USB_RXCSRH5_INCOMPRX    0x00000001  // Incomplete RX Transmission
                                            // Status

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXCOUNT5 register.
//
//*****************************************************************************
#define USB_RXCOUNT5_COUNT_M    0x00001FFF  // Receive Packet Count
#define USB_RXCOUNT5_COUNT_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXTYPE5 register.
//
//*****************************************************************************
#define USB_TXTYPE5_SPEED_M     0x000000C0  // Operating Speed
#define USB_TXTYPE5_SPEED_DFLT  0x00000000  // Default
#define USB_TXTYPE5_SPEED_HIGH  0x00000040  // High
#define USB_TXTYPE5_SPEED_FULL  0x00000080  // Full
#define USB_TXTYPE5_SPEED_LOW   0x000000C0  // Low
#define USB_TXTYPE5_PROTO_M     0x00000030  // Protocol
#define USB_TXTYPE5_PROTO_CTRL  0x00000000  // Control
#define USB_TXTYPE5_PROTO_ISOC  0x00000010  // Isochronous
#define USB_TXTYPE5_PROTO_BULK  0x00000020  // Bulk
#define USB_TXTYPE5_PROTO_INT   0x00000030  // Interrupt
#define USB_TXTYPE5_TEP_M       0x0000000F  // Target Endpoint Number
#define USB_TXTYPE5_TEP_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXINTERVAL5
// register.
//
//*****************************************************************************
#define USB_TXINTERVAL5_TXPOLL_M                                              \
                                0x000000FF  // TX Polling
#define USB_TXINTERVAL5_NAKLMT_M                                              \
                                0x000000FF  // NAK Limit
#define USB_TXINTERVAL5_NAKLMT_S                                              \
                                0
#define USB_TXINTERVAL5_TXPOLL_S                                              \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXTYPE5 register.
//
//*****************************************************************************
#define USB_RXTYPE5_SPEED_M     0x000000C0  // Operating Speed
#define USB_RXTYPE5_SPEED_DFLT  0x00000000  // Default
#define USB_RXTYPE5_SPEED_HIGH  0x00000040  // High
#define USB_RXTYPE5_SPEED_FULL  0x00000080  // Full
#define USB_RXTYPE5_SPEED_LOW   0x000000C0  // Low
#define USB_RXTYPE5_PROTO_M     0x00000030  // Protocol
#define USB_RXTYPE5_PROTO_CTRL  0x00000000  // Control
#define USB_RXTYPE5_PROTO_ISOC  0x00000010  // Isochronous
#define USB_RXTYPE5_PROTO_BULK  0x00000020  // Bulk
#define USB_RXTYPE5_PROTO_INT   0x00000030  // Interrupt
#define USB_RXTYPE5_TEP_M       0x0000000F  // Target Endpoint Number
#define USB_RXTYPE5_TEP_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXINTERVAL5
// register.
//
//*****************************************************************************
#define USB_RXINTERVAL5_TXPOLL_M                                              \
                                0x000000FF  // RX Polling
#define USB_RXINTERVAL5_NAKLMT_M                                              \
                                0x000000FF  // NAK Limit
#define USB_RXINTERVAL5_TXPOLL_S                                              \
                                0
#define USB_RXINTERVAL5_NAKLMT_S                                              \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXMAXP6 register.
//
//*****************************************************************************
#define USB_TXMAXP6_MAXLOAD_M   0x000007FF  // Maximum Payload
#define USB_TXMAXP6_MAXLOAD_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXCSRL6 register.
//
//*****************************************************************************
#define USB_TXCSRL6_NAKTO       0x00000080  // NAK Timeout
#define USB_TXCSRL6_CLRDT       0x00000040  // Clear Data Toggle
#define USB_TXCSRL6_STALLED     0x00000020  // Endpoint Stalled
#define USB_TXCSRL6_STALL       0x00000010  // Send STALL
#define USB_TXCSRL6_SETUP       0x00000010  // Setup Packet
#define USB_TXCSRL6_FLUSH       0x00000008  // Flush FIFO
#define USB_TXCSRL6_ERROR       0x00000004  // Error
#define USB_TXCSRL6_UNDRN       0x00000004  // Underrun
#define USB_TXCSRL6_FIFONE      0x00000002  // FIFO Not Empty
#define USB_TXCSRL6_TXRDY       0x00000001  // Transmit Packet Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXCSRH6 register.
//
//*****************************************************************************
#define USB_TXCSRH6_AUTOSET     0x00000080  // Auto Set
#define USB_TXCSRH6_ISO         0x00000040  // Isochronous Transfers
#define USB_TXCSRH6_MODE        0x00000020  // Mode
#define USB_TXCSRH6_DMAEN       0x00000010  // DMA Request Enable
#define USB_TXCSRH6_FDT         0x00000008  // Force Data Toggle
#define USB_TXCSRH6_DMAMOD      0x00000004  // DMA Request Mode
#define USB_TXCSRH6_DTWE        0x00000002  // Data Toggle Write Enable
#define USB_TXCSRH6_DT          0x00000001  // Data Toggle

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXMAXP6 register.
//
//*****************************************************************************
#define USB_RXMAXP6_MAXLOAD_M   0x000007FF  // Maximum Payload
#define USB_RXMAXP6_MAXLOAD_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXCSRL6 register.
//
//*****************************************************************************
#define USB_RXCSRL6_CLRDT       0x00000080  // Clear Data Toggle
#define USB_RXCSRL6_STALLED     0x00000040  // Endpoint Stalled
#define USB_RXCSRL6_REQPKT      0x00000020  // Request Packet
#define USB_RXCSRL6_STALL       0x00000020  // Send STALL
#define USB_RXCSRL6_FLUSH       0x00000010  // Flush FIFO
#define USB_RXCSRL6_NAKTO       0x00000008  // NAK Timeout
#define USB_RXCSRL6_DATAERR     0x00000008  // Data Error
#define USB_RXCSRL6_ERROR       0x00000004  // Error
#define USB_RXCSRL6_OVER        0x00000004  // Overrun
#define USB_RXCSRL6_FULL        0x00000002  // FIFO Full
#define USB_RXCSRL6_RXRDY       0x00000001  // Receive Packet Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXCSRH6 register.
//
//*****************************************************************************
#define USB_RXCSRH6_AUTOCL      0x00000080  // Auto Clear
#define USB_RXCSRH6_AUTORQ      0x00000040  // Auto Request
#define USB_RXCSRH6_ISO         0x00000040  // Isochronous Transfers
#define USB_RXCSRH6_DMAEN       0x00000020  // DMA Request Enable
#define USB_RXCSRH6_DISNYET     0x00000010  // Disable NYET
#define USB_RXCSRH6_PIDERR      0x00000010  // PID Error
#define USB_RXCSRH6_DMAMOD      0x00000008  // DMA Request Mode
#define USB_RXCSRH6_DTWE        0x00000004  // Data Toggle Write Enable
#define USB_RXCSRH6_DT          0x00000002  // Data Toggle
#define USB_RXCSRH6_INCOMPRX    0x00000001  // Incomplete RX Transmission
                                            // Status

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXCOUNT6 register.
//
//*****************************************************************************
#define USB_RXCOUNT6_COUNT_M    0x00001FFF  // Receive Packet Count
#define USB_RXCOUNT6_COUNT_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXTYPE6 register.
//
//*****************************************************************************
#define USB_TXTYPE6_SPEED_M     0x000000C0  // Operating Speed
#define USB_TXTYPE6_SPEED_DFLT  0x00000000  // Default
#define USB_TXTYPE6_SPEED_HIGH  0x00000040  // High
#define USB_TXTYPE6_SPEED_FULL  0x00000080  // Full
#define USB_TXTYPE6_SPEED_LOW   0x000000C0  // Low
#define USB_TXTYPE6_PROTO_M     0x00000030  // Protocol
#define USB_TXTYPE6_PROTO_CTRL  0x00000000  // Control
#define USB_TXTYPE6_PROTO_ISOC  0x00000010  // Isochronous
#define USB_TXTYPE6_PROTO_BULK  0x00000020  // Bulk
#define USB_TXTYPE6_PROTO_INT   0x00000030  // Interrupt
#define USB_TXTYPE6_TEP_M       0x0000000F  // Target Endpoint Number
#define USB_TXTYPE6_TEP_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXINTERVAL6
// register.
//
//*****************************************************************************
#define USB_TXINTERVAL6_TXPOLL_M                                              \
                                0x000000FF  // TX Polling
#define USB_TXINTERVAL6_NAKLMT_M                                              \
                                0x000000FF  // NAK Limit
#define USB_TXINTERVAL6_TXPOLL_S                                              \
                                0
#define USB_TXINTERVAL6_NAKLMT_S                                              \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXTYPE6 register.
//
//*****************************************************************************
#define USB_RXTYPE6_SPEED_M     0x000000C0  // Operating Speed
#define USB_RXTYPE6_SPEED_DFLT  0x00000000  // Default
#define USB_RXTYPE6_SPEED_HIGH  0x00000040  // High
#define USB_RXTYPE6_SPEED_FULL  0x00000080  // Full
#define USB_RXTYPE6_SPEED_LOW   0x000000C0  // Low
#define USB_RXTYPE6_PROTO_M     0x00000030  // Protocol
#define USB_RXTYPE6_PROTO_CTRL  0x00000000  // Control
#define USB_RXTYPE6_PROTO_ISOC  0x00000010  // Isochronous
#define USB_RXTYPE6_PROTO_BULK  0x00000020  // Bulk
#define USB_RXTYPE6_PROTO_INT   0x00000030  // Interrupt
#define USB_RXTYPE6_TEP_M       0x0000000F  // Target Endpoint Number
#define USB_RXTYPE6_TEP_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXINTERVAL6
// register.
//
//*****************************************************************************
#define USB_RXINTERVAL6_TXPOLL_M                                              \
                                0x000000FF  // RX Polling
#define USB_RXINTERVAL6_NAKLMT_M                                              \
                                0x000000FF  // NAK Limit
#define USB_RXINTERVAL6_NAKLMT_S                                              \
                                0
#define USB_RXINTERVAL6_TXPOLL_S                                              \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXMAXP7 register.
//
//*****************************************************************************
#define USB_TXMAXP7_MAXLOAD_M   0x000007FF  // Maximum Payload
#define USB_TXMAXP7_MAXLOAD_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXCSRL7 register.
//
//*****************************************************************************
#define USB_TXCSRL7_NAKTO       0x00000080  // NAK Timeout
#define USB_TXCSRL7_CLRDT       0x00000040  // Clear Data Toggle
#define USB_TXCSRL7_STALLED     0x00000020  // Endpoint Stalled
#define USB_TXCSRL7_STALL       0x00000010  // Send STALL
#define USB_TXCSRL7_SETUP       0x00000010  // Setup Packet
#define USB_TXCSRL7_FLUSH       0x00000008  // Flush FIFO
#define USB_TXCSRL7_ERROR       0x00000004  // Error
#define USB_TXCSRL7_UNDRN       0x00000004  // Underrun
#define USB_TXCSRL7_FIFONE      0x00000002  // FIFO Not Empty
#define USB_TXCSRL7_TXRDY       0x00000001  // Transmit Packet Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXCSRH7 register.
//
//*****************************************************************************
#define USB_TXCSRH7_AUTOSET     0x00000080  // Auto Set
#define USB_TXCSRH7_ISO         0x00000040  // Isochronous Transfers
#define USB_TXCSRH7_MODE        0x00000020  // Mode
#define USB_TXCSRH7_DMAEN       0x00000010  // DMA Request Enable
#define USB_TXCSRH7_FDT         0x00000008  // Force Data Toggle
#define USB_TXCSRH7_DMAMOD      0x00000004  // DMA Request Mode
#define USB_TXCSRH7_DTWE        0x00000002  // Data Toggle Write Enable
#define USB_TXCSRH7_DT          0x00000001  // Data Toggle

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXMAXP7 register.
//
//*****************************************************************************
#define USB_RXMAXP7_MAXLOAD_M   0x000007FF  // Maximum Payload
#define USB_RXMAXP7_MAXLOAD_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXCSRL7 register.
//
//*****************************************************************************
#define USB_RXCSRL7_CLRDT       0x00000080  // Clear Data Toggle
#define USB_RXCSRL7_STALLED     0x00000040  // Endpoint Stalled
#define USB_RXCSRL7_REQPKT      0x00000020  // Request Packet
#define USB_RXCSRL7_STALL       0x00000020  // Send STALL
#define USB_RXCSRL7_FLUSH       0x00000010  // Flush FIFO
#define USB_RXCSRL7_DATAERR     0x00000008  // Data Error
#define USB_RXCSRL7_NAKTO       0x00000008  // NAK Timeout
#define USB_RXCSRL7_ERROR       0x00000004  // Error
#define USB_RXCSRL7_OVER        0x00000004  // Overrun
#define USB_RXCSRL7_FULL        0x00000002  // FIFO Full
#define USB_RXCSRL7_RXRDY       0x00000001  // Receive Packet Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXCSRH7 register.
//
//*****************************************************************************
#define USB_RXCSRH7_AUTOCL      0x00000080  // Auto Clear
#define USB_RXCSRH7_ISO         0x00000040  // Isochronous Transfers
#define USB_RXCSRH7_AUTORQ      0x00000040  // Auto Request
#define USB_RXCSRH7_DMAEN       0x00000020  // DMA Request Enable
#define USB_RXCSRH7_PIDERR      0x00000010  // PID Error
#define USB_RXCSRH7_DISNYET     0x00000010  // Disable NYET
#define USB_RXCSRH7_DMAMOD      0x00000008  // DMA Request Mode
#define USB_RXCSRH7_DTWE        0x00000004  // Data Toggle Write Enable
#define USB_RXCSRH7_DT          0x00000002  // Data Toggle
#define USB_RXCSRH7_INCOMPRX    0x00000001  // Incomplete RX Transmission
                                            // Status

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXCOUNT7 register.
//
//*****************************************************************************
#define USB_RXCOUNT7_COUNT_M    0x00001FFF  // Receive Packet Count
#define USB_RXCOUNT7_COUNT_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXTYPE7 register.
//
//*****************************************************************************
#define USB_TXTYPE7_SPEED_M     0x000000C0  // Operating Speed
#define USB_TXTYPE7_SPEED_DFLT  0x00000000  // Default
#define USB_TXTYPE7_SPEED_HIGH  0x00000040  // High
#define USB_TXTYPE7_SPEED_FULL  0x00000080  // Full
#define USB_TXTYPE7_SPEED_LOW   0x000000C0  // Low
#define USB_TXTYPE7_PROTO_M     0x00000030  // Protocol
#define USB_TXTYPE7_PROTO_CTRL  0x00000000  // Control
#define USB_TXTYPE7_PROTO_ISOC  0x00000010  // Isochronous
#define USB_TXTYPE7_PROTO_BULK  0x00000020  // Bulk
#define USB_TXTYPE7_PROTO_INT   0x00000030  // Interrupt
#define USB_TXTYPE7_TEP_M       0x0000000F  // Target Endpoint Number
#define USB_TXTYPE7_TEP_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXINTERVAL7
// register.
//
//*****************************************************************************
#define USB_TXINTERVAL7_TXPOLL_M                                              \
                                0x000000FF  // TX Polling
#define USB_TXINTERVAL7_NAKLMT_M                                              \
                                0x000000FF  // NAK Limit
#define USB_TXINTERVAL7_NAKLMT_S                                              \
                                0
#define USB_TXINTERVAL7_TXPOLL_S                                              \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXTYPE7 register.
//
//*****************************************************************************
#define USB_RXTYPE7_SPEED_M     0x000000C0  // Operating Speed
#define USB_RXTYPE7_SPEED_DFLT  0x00000000  // Default
#define USB_RXTYPE7_SPEED_HIGH  0x00000040  // High
#define USB_RXTYPE7_SPEED_FULL  0x00000080  // Full
#define USB_RXTYPE7_SPEED_LOW   0x000000C0  // Low
#define USB_RXTYPE7_PROTO_M     0x00000030  // Protocol
#define USB_RXTYPE7_PROTO_CTRL  0x00000000  // Control
#define USB_RXTYPE7_PROTO_ISOC  0x00000010  // Isochronous
#define USB_RXTYPE7_PROTO_BULK  0x00000020  // Bulk
#define USB_RXTYPE7_PROTO_INT   0x00000030  // Interrupt
#define USB_RXTYPE7_TEP_M       0x0000000F  // Target Endpoint Number
#define USB_RXTYPE7_TEP_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXINTERVAL7
// register.
//
//*****************************************************************************
#define USB_RXINTERVAL7_TXPOLL_M                                              \
                                0x000000FF  // RX Polling
#define USB_RXINTERVAL7_NAKLMT_M                                              \
                                0x000000FF  // NAK Limit
#define USB_RXINTERVAL7_NAKLMT_S                                              \
                                0
#define USB_RXINTERVAL7_TXPOLL_S                                              \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_DMAINTR register.
//
//*****************************************************************************
#define USB_DMAINTR_CH7         0x00000080  // Channel 8 DMA Interrupt
#define USB_DMAINTR_CH6         0x00000040  // Channel 7 DMA Interrupt
#define USB_DMAINTR_CH5         0x00000020  // Channel 6 DMA Interrupt
#define USB_DMAINTR_CH4         0x00000010  // Channel 5 DMA Interrupt
#define USB_DMAINTR_CH3         0x00000008  // Channel 4 DMA Interrupt
#define USB_DMAINTR_CH2         0x00000004  // Channel 3 DMA Interrupt
#define USB_DMAINTR_CH1         0x00000002  // Channel 2 DMA Interrupt
#define USB_DMAINTR_CH0         0x00000001  // Channel 1 DMA Interrupt

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_DMACTL0 register.
//
//*****************************************************************************
#define USB_DMACTL0_BRSTM_M     0x00000600  // Burst Mode
#define USB_DMACTL0_BRSTM_ANY   0x00000000  // Bursts of unspecified length
#define USB_DMACTL0_BRSTM_INC4  0x00000200  // INCR4 or unspecified length
#define USB_DMACTL0_BRSTM_INC8  0x00000400  // INCR8, INCR4 or unspecified
                                            // length
#define USB_DMACTL0_BRSTM_INC16 0x00000600  // INCR16, INCR8, INCR4 or
                                            // unspecified length
#define USB_DMACTL0_ERR         0x00000100  // Bus Error Bit
#define USB_DMACTL0_EP_M        0x000000F0  // Endpoint number
#define USB_DMACTL0_IE          0x00000008  // DMA Interrupt Enable
#define USB_DMACTL0_MODE        0x00000004  // DMA Transfer Mode
#define USB_DMACTL0_DIR         0x00000002  // DMA Direction
#define USB_DMACTL0_ENABLE      0x00000001  // DMA Transfer Enable
#define USB_DMACTL0_EP_S        4

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_DMAADDR0 register.
//
//*****************************************************************************
#define USB_DMAADDR0_ADDR_M     0xFFFFFFFC  // DMA Address
#define USB_DMAADDR0_ADDR_S     2

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_DMACOUNT0
// register.
//
//*****************************************************************************
#define USB_DMACOUNT0_COUNT_M   0xFFFFFFFC  // DMA Count
#define USB_DMACOUNT0_COUNT_S   2

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_DMACTL1 register.
//
//*****************************************************************************
#define USB_DMACTL1_BRSTM_M     0x00000600  // Burst Mode
#define USB_DMACTL1_BRSTM_ANY   0x00000000  // Bursts of unspecified length
#define USB_DMACTL1_BRSTM_INC4  0x00000200  // INCR4 or unspecified length
#define USB_DMACTL1_BRSTM_INC8  0x00000400  // INCR8, INCR4 or unspecified
                                            // length
#define USB_DMACTL1_BRSTM_INC16 0x00000600  // INCR16, INCR8, INCR4 or
                                            // unspecified length
#define USB_DMACTL1_ERR         0x00000100  // Bus Error Bit
#define USB_DMACTL1_EP_M        0x000000F0  // Endpoint number
#define USB_DMACTL1_IE          0x00000008  // DMA Interrupt Enable
#define USB_DMACTL1_MODE        0x00000004  // DMA Transfer Mode
#define USB_DMACTL1_DIR         0x00000002  // DMA Direction
#define USB_DMACTL1_ENABLE      0x00000001  // DMA Transfer Enable
#define USB_DMACTL1_EP_S        4

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_DMAADDR1 register.
//
//*****************************************************************************
#define USB_DMAADDR1_ADDR_M     0xFFFFFFFC  // DMA Address
#define USB_DMAADDR1_ADDR_S     2

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_DMACOUNT1
// register.
//
//*****************************************************************************
#define USB_DMACOUNT1_COUNT_M   0xFFFFFFFC  // DMA Count
#define USB_DMACOUNT1_COUNT_S   2

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_DMACTL2 register.
//
//*****************************************************************************
#define USB_DMACTL2_BRSTM_M     0x00000600  // Burst Mode
#define USB_DMACTL2_BRSTM_ANY   0x00000000  // Bursts of unspecified length
#define USB_DMACTL2_BRSTM_INC4  0x00000200  // INCR4 or unspecified length
#define USB_DMACTL2_BRSTM_INC8  0x00000400  // INCR8, INCR4 or unspecified
                                            // length
#define USB_DMACTL2_BRSTM_INC16 0x00000600  // INCR16, INCR8, INCR4 or
                                            // unspecified length
#define USB_DMACTL2_ERR         0x00000100  // Bus Error Bit
#define USB_DMACTL2_EP_M        0x000000F0  // Endpoint number
#define USB_DMACTL2_IE          0x00000008  // DMA Interrupt Enable
#define USB_DMACTL2_MODE        0x00000004  // DMA Transfer Mode
#define USB_DMACTL2_DIR         0x00000002  // DMA Direction
#define USB_DMACTL2_ENABLE      0x00000001  // DMA Transfer Enable
#define USB_DMACTL2_EP_S        4

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_DMAADDR2 register.
//
//*****************************************************************************
#define USB_DMAADDR2_ADDR_M     0xFFFFFFFC  // DMA Address
#define USB_DMAADDR2_ADDR_S     2

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_DMACOUNT2
// register.
//
//*****************************************************************************
#define USB_DMACOUNT2_COUNT_M   0xFFFFFFFC  // DMA Count
#define USB_DMACOUNT2_COUNT_S   2

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_DMACTL3 register.
//
//*****************************************************************************
#define USB_DMACTL3_BRSTM_M     0x00000600  // Burst Mode
#define USB_DMACTL3_BRSTM_ANY   0x00000000  // Bursts of unspecified length
#define USB_DMACTL3_BRSTM_INC4  0x00000200  // INCR4 or unspecified length
#define USB_DMACTL3_BRSTM_INC8  0x00000400  // INCR8, INCR4 or unspecified
                                            // length
#define USB_DMACTL3_BRSTM_INC16 0x00000600  // INCR16, INCR8, INCR4 or
                                            // unspecified length
#define USB_DMACTL3_ERR         0x00000100  // Bus Error Bit
#define USB_DMACTL3_EP_M        0x000000F0  // Endpoint number
#define USB_DMACTL3_IE          0x00000008  // DMA Interrupt Enable
#define USB_DMACTL3_MODE        0x00000004  // DMA Transfer Mode
#define USB_DMACTL3_DIR         0x00000002  // DMA Direction
#define USB_DMACTL3_ENABLE      0x00000001  // DMA Transfer Enable
#define USB_DMACTL3_EP_S        4

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_DMAADDR3 register.
//
//*****************************************************************************
#define USB_DMAADDR3_ADDR_M     0xFFFFFFFC  // DMA Address
#define USB_DMAADDR3_ADDR_S     2

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_DMACOUNT3
// register.
//
//*****************************************************************************
#define USB_DMACOUNT3_COUNT_M   0xFFFFFFFC  // DMA Count
#define USB_DMACOUNT3_COUNT_S   2

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_DMACTL4 register.
//
//*****************************************************************************
#define USB_DMACTL4_BRSTM_M     0x00000600  // Burst Mode
#define USB_DMACTL4_BRSTM_ANY   0x00000000  // Bursts of unspecified length
#define USB_DMACTL4_BRSTM_INC4  0x00000200  // INCR4 or unspecified length
#define USB_DMACTL4_BRSTM_INC8  0x00000400  // INCR8, INCR4 or unspecified
                                            // length
#define USB_DMACTL4_BRSTM_INC16 0x00000600  // INCR16, INCR8, INCR4 or
                                            // unspecified length
#define USB_DMACTL4_ERR         0x00000100  // Bus Error Bit
#define USB_DMACTL4_EP_M        0x000000F0  // Endpoint number
#define USB_DMACTL4_IE          0x00000008  // DMA Interrupt Enable
#define USB_DMACTL4_MODE        0x00000004  // DMA Transfer Mode
#define USB_DMACTL4_DIR         0x00000002  // DMA Direction
#define USB_DMACTL4_ENABLE      0x00000001  // DMA Transfer Enable
#define USB_DMACTL4_EP_S        4

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_DMAADDR4 register.
//
//*****************************************************************************
#define USB_DMAADDR4_ADDR_M     0xFFFFFFFC  // DMA Address
#define USB_DMAADDR4_ADDR_S     2

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_DMACOUNT4
// register.
//
//*****************************************************************************
#define USB_DMACOUNT4_COUNT_M   0xFFFFFFFC  // DMA Count
#define USB_DMACOUNT4_COUNT_S   2

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_DMACTL5 register.
//
//*****************************************************************************
#define USB_DMACTL5_BRSTM_M     0x00000600  // Burst Mode
#define USB_DMACTL5_BRSTM_ANY   0x00000000  // Bursts of unspecified length
#define USB_DMACTL5_BRSTM_INC4  0x00000200  // INCR4 or unspecified length
#define USB_DMACTL5_BRSTM_INC8  0x00000400  // INCR8, INCR4 or unspecified
                                            // length
#define USB_DMACTL5_BRSTM_INC16 0x00000600  // INCR16, INCR8, INCR4 or
                                            // unspecified length
#define USB_DMACTL5_ERR         0x00000100  // Bus Error Bit
#define USB_DMACTL5_EP_M        0x000000F0  // Endpoint number
#define USB_DMACTL5_IE          0x00000008  // DMA Interrupt Enable
#define USB_DMACTL5_MODE        0x00000004  // DMA Transfer Mode
#define USB_DMACTL5_DIR         0x00000002  // DMA Direction
#define USB_DMACTL5_ENABLE      0x00000001  // DMA Transfer Enable
#define USB_DMACTL5_EP_S        4

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_DMAADDR5 register.
//
//*****************************************************************************
#define USB_DMAADDR5_ADDR_M     0xFFFFFFFC  // DMA Address
#define USB_DMAADDR5_ADDR_S     2

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_DMACOUNT5
// register.
//
//*****************************************************************************
#define USB_DMACOUNT5_COUNT_M   0xFFFFFFFC  // DMA Count
#define USB_DMACOUNT5_COUNT_S   2

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_DMACTL6 register.
//
//*****************************************************************************
#define USB_DMACTL6_BRSTM_M     0x00000600  // Burst Mode
#define USB_DMACTL6_BRSTM_ANY   0x00000000  // Bursts of unspecified length
#define USB_DMACTL6_BRSTM_INC4  0x00000200  // INCR4 or unspecified length
#define USB_DMACTL6_BRSTM_INC8  0x00000400  // INCR8, INCR4 or unspecified
                                            // length
#define USB_DMACTL6_BRSTM_INC16 0x00000600  // INCR16, INCR8, INCR4 or
                                            // unspecified length
#define USB_DMACTL6_ERR         0x00000100  // Bus Error Bit
#define USB_DMACTL6_EP_M        0x000000F0  // Endpoint number
#define USB_DMACTL6_IE          0x00000008  // DMA Interrupt Enable
#define USB_DMACTL6_MODE        0x00000004  // DMA Transfer Mode
#define USB_DMACTL6_DIR         0x00000002  // DMA Direction
#define USB_DMACTL6_ENABLE      0x00000001  // DMA Transfer Enable
#define USB_DMACTL6_EP_S        4

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_DMAADDR6 register.
//
//*****************************************************************************
#define USB_DMAADDR6_ADDR_M     0xFFFFFFFC  // DMA Address
#define USB_DMAADDR6_ADDR_S     2

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_DMACOUNT6
// register.
//
//*****************************************************************************
#define USB_DMACOUNT6_COUNT_M   0xFFFFFFFC  // DMA Count
#define USB_DMACOUNT6_COUNT_S   2

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_DMACTL7 register.
//
//*****************************************************************************
#define USB_DMACTL7_BRSTM_M     0x00000600  // Burst Mode
#define USB_DMACTL7_BRSTM_ANY   0x00000000  // Bursts of unspecified length
#define USB_DMACTL7_BRSTM_INC4  0x00000200  // INCR4 or unspecified length
#define USB_DMACTL7_BRSTM_INC8  0x00000400  // INCR8, INCR4 or unspecified
                                            // length
#define USB_DMACTL7_BRSTM_INC16 0x00000600  // INCR16, INCR8, INCR4 or
                                            // unspecified length
#define USB_DMACTL7_ERR         0x00000100  // Bus Error Bit
#define USB_DMACTL7_EP_M        0x000000F0  // Endpoint number
#define USB_DMACTL7_IE          0x00000008  // DMA Interrupt Enable
#define USB_DMACTL7_MODE        0x00000004  // DMA Transfer Mode
#define USB_DMACTL7_DIR         0x00000002  // DMA Direction
#define USB_DMACTL7_ENABLE      0x00000001  // DMA Transfer Enable
#define USB_DMACTL7_EP_S        4

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_DMAADDR7 register.
//
//*****************************************************************************
#define USB_DMAADDR7_ADDR_M     0xFFFFFFFC  // DMA Address
#define USB_DMAADDR7_ADDR_S     2

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_DMACOUNT7
// register.
//
//*****************************************************************************
#define USB_DMACOUNT7_COUNT_M   0xFFFFFFFC  // DMA Count
#define USB_DMACOUNT7_COUNT_S   2

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RQPKTCOUNT1
// register.
//
//*****************************************************************************
#define USB_RQPKTCOUNT1_M       0x0000FFFF  // Block Transfer Packet Count
#define USB_RQPKTCOUNT1_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RQPKTCOUNT2
// register.
//
//*****************************************************************************
#define USB_RQPKTCOUNT2_M       0x0000FFFF  // Block Transfer Packet Count
#define USB_RQPKTCOUNT2_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RQPKTCOUNT3
// register.
//
//*****************************************************************************
#define USB_RQPKTCOUNT3_M       0x0000FFFF  // Block Transfer Packet Count
#define USB_RQPKTCOUNT3_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RQPKTCOUNT4
// register.
//
//*****************************************************************************
#define USB_RQPKTCOUNT4_COUNT_M 0x0000FFFF  // Block Transfer Packet Count
#define USB_RQPKTCOUNT4_COUNT_S 0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RQPKTCOUNT5
// register.
//
//*****************************************************************************
#define USB_RQPKTCOUNT5_COUNT_M 0x0000FFFF  // Block Transfer Packet Count
#define USB_RQPKTCOUNT5_COUNT_S 0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RQPKTCOUNT6
// register.
//
//*****************************************************************************
#define USB_RQPKTCOUNT6_COUNT_M 0x0000FFFF  // Block Transfer Packet Count
#define USB_RQPKTCOUNT6_COUNT_S 0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RQPKTCOUNT7
// register.
//
//*****************************************************************************
#define USB_RQPKTCOUNT7_COUNT_M 0x0000FFFF  // Block Transfer Packet Count
#define USB_RQPKTCOUNT7_COUNT_S 0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_RXDPKTBUFDIS
// register.
//
//*****************************************************************************
#define USB_RXDPKTBUFDIS_EP7    0x00000080  // EP7 RX Double-Packet Buffer
                                            // Disable
#define USB_RXDPKTBUFDIS_EP6    0x00000040  // EP6 RX Double-Packet Buffer
                                            // Disable
#define USB_RXDPKTBUFDIS_EP5    0x00000020  // EP5 RX Double-Packet Buffer
                                            // Disable
#define USB_RXDPKTBUFDIS_EP4    0x00000010  // EP4 RX Double-Packet Buffer
                                            // Disable
#define USB_RXDPKTBUFDIS_EP3    0x00000008  // EP3 RX Double-Packet Buffer
                                            // Disable
#define USB_RXDPKTBUFDIS_EP2    0x00000004  // EP2 RX Double-Packet Buffer
                                            // Disable
#define USB_RXDPKTBUFDIS_EP1    0x00000002  // EP1 RX Double-Packet Buffer
                                            // Disable

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_TXDPKTBUFDIS
// register.
//
//*****************************************************************************
#define USB_TXDPKTBUFDIS_EP7    0x00000080  // EP7 TX Double-Packet Buffer
                                            // Disable
#define USB_TXDPKTBUFDIS_EP6    0x00000040  // EP6 TX Double-Packet Buffer
                                            // Disable
#define USB_TXDPKTBUFDIS_EP5    0x00000020  // EP5 TX Double-Packet Buffer
                                            // Disable
#define USB_TXDPKTBUFDIS_EP4    0x00000010  // EP4 TX Double-Packet Buffer
                                            // Disable
#define USB_TXDPKTBUFDIS_EP3    0x00000008  // EP3 TX Double-Packet Buffer
                                            // Disable
#define USB_TXDPKTBUFDIS_EP2    0x00000004  // EP2 TX Double-Packet Buffer
                                            // Disable
#define USB_TXDPKTBUFDIS_EP1    0x00000002  // EP1 TX Double-Packet Buffer
                                            // Disable

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_CTO register.
//
//*****************************************************************************
#define USB_CTO_CCTV_M          0x0000FFFF  // Configurable Chirp Timeout Value
#define USB_CTO_CCTV_S          0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_HHSRTN register.
//
//*****************************************************************************
#define USB_HHSRTN_HHSRTN_M     0x0000FFFF  // High Speed to UTM Operating
                                            // Delay
#define USB_HHSRTN_HHSRTN_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_HSBT register.
//
//*****************************************************************************
#define USB_HSBT_HSBT_M         0x0000000F  // High Speed Timeout Adder
#define USB_HSBT_HSBT_S         0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_LPMATTR register.
//
//*****************************************************************************
#define USB_LPMATTR_ENDPT_M     0x0000F000  // Endpoint
#define USB_LPMATTR_RMTWAK      0x00000100  // Remote Wake
#define USB_LPMATTR_HIRD_M      0x000000F0  // Host Initiated Resume Duration
#define USB_LPMATTR_LS_M        0x0000000F  // Link State
#define USB_LPMATTR_LS_L1       0x00000001  // Sleep State (L1)
#define USB_LPMATTR_ENDPT_S     12
#define USB_LPMATTR_HIRD_S      4

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_LPMCNTRL register.
//
//*****************************************************************************
#define USB_LPMCNTRL_NAK        0x00000010  // LPM NAK
#define USB_LPMCNTRL_EN_M       0x0000000C  // LPM Enable
#define USB_LPMCNTRL_EN_NONE    0x00000000  // LPM and Extended transactions
                                            // are not supported. In this case,
                                            // the USB does not respond to LPM
                                            // transactions and LPM
                                            // transactions cause a timeout
#define USB_LPMCNTRL_EN_EXT     0x00000004  // LPM is not supported but
                                            // extended transactions are
                                            // supported. In this case, the USB
                                            // does respond to an LPM
                                            // transaction with a STALL
#define USB_LPMCNTRL_EN_LPMEXT  0x0000000C  // The USB supports LPM extended
                                            // transactions. In this case, the
                                            // USB responds with a NYET or an
                                            // ACK as determined by the value
                                            // of TXLPM and other conditions
#define USB_LPMCNTRL_RES        0x00000002  // LPM Resume
#define USB_LPMCNTRL_TXLPM      0x00000001  // Transmit LPM Transaction Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_LPMIM register.
//
//*****************************************************************************
#define USB_LPMIM_ERR           0x00000020  // LPM Error Interrupt Mask
#define USB_LPMIM_RES           0x00000010  // LPM Resume Interrupt Mask
#define USB_LPMIM_NC            0x00000008  // LPM NC Interrupt Mask
#define USB_LPMIM_ACK           0x00000004  // LPM ACK Interrupt Mask
#define USB_LPMIM_NY            0x00000002  // LPM NY Interrupt Mask
#define USB_LPMIM_STALL         0x00000001  // LPM STALL Interrupt Mask

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_LPMRIS register.
//
//*****************************************************************************
#define USB_LPMRIS_ERR          0x00000020  // LPM Error Interrupt Status
#define USB_LPMRIS_RES          0x00000010  // LPM Resume Interrupt Status
#define USB_LPMRIS_NC           0x00000008  // LPM No Completion Interrupt
                                            // Status
#define USB_LPMRIS_ACK          0x00000004  // LPM ACK Interrupt Status
#define USB_LPMRIS_NY           0x00000002  // LPM NY Interrupt Status
#define USB_LPMRIS_LPMST        0x00000001  // LPM STALL Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_LPMFADDR register.
//
//*****************************************************************************
#define USB_LPMFADDR_ADDR_M     0x0000007F  // LPM Function Address
#define USB_LPMFADDR_ADDR_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_EPC register.
//
//*****************************************************************************
#define USB_EPC_PFLTACT_M       0x00000300  // Power Fault Action
#define USB_EPC_PFLTACT_UNCHG   0x00000000  // Unchanged
#define USB_EPC_PFLTACT_TRIS    0x00000100  // Tristate
#define USB_EPC_PFLTACT_LOW     0x00000200  // Low
#define USB_EPC_PFLTACT_HIGH    0x00000300  // High
#define USB_EPC_PFLTAEN         0x00000040  // Power Fault Action Enable
#define USB_EPC_PFLTSEN_HIGH    0x00000020  // Power Fault Sense
#define USB_EPC_PFLTEN          0x00000010  // Power Fault Input Enable
#define USB_EPC_EPENDE          0x00000004  // EPEN Drive Enable
#define USB_EPC_EPEN_M          0x00000003  // External Power Supply Enable
                                            // Configuration
#define USB_EPC_EPEN_LOW        0x00000000  // Power Enable Active Low
#define USB_EPC_EPEN_HIGH       0x00000001  // Power Enable Active High
#define USB_EPC_EPEN_VBLOW      0x00000002  // Power Enable High if VBUS Low
#define USB_EPC_EPEN_VBHIGH     0x00000003  // Power Enable High if VBUS High

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_EPCRIS register.
//
//*****************************************************************************
#define USB_EPCRIS_PF           0x00000001  // USB Power Fault Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_EPCIM register.
//
//*****************************************************************************
#define USB_EPCIM_PF            0x00000001  // USB Power Fault Interrupt Mask

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_EPCISC register.
//
//*****************************************************************************
#define USB_EPCISC_PF           0x00000001  // USB Power Fault Interrupt Status
                                            // and Clear

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_DRRIS register.
//
//*****************************************************************************
#define USB_DRRIS_RESUME        0x00000001  // RESUME Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_DRIM register.
//
//*****************************************************************************
#define USB_DRIM_RESUME         0x00000001  // RESUME Interrupt Mask

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_DRISC register.
//
//*****************************************************************************
#define USB_DRISC_RESUME        0x00000001  // RESUME Interrupt Status and
                                            // Clear

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_GPCS register.
//
//*****************************************************************************
#define USB_GPCS_DEVMOD_M       0x00000007  // Device Mode
#define USB_GPCS_DEVMOD_OTG     0x00000000  // Use USB0VBUS and USB0ID pin
#define USB_GPCS_DEVMOD_HOST    0x00000002  // Force USB0VBUS and USB0ID low
#define USB_GPCS_DEVMOD_DEV     0x00000003  // Force USB0VBUS and USB0ID high
#define USB_GPCS_DEVMOD_HOSTVBUS                                              \
                                0x00000004  // Use USB0VBUS and force USB0ID
                                            // low
#define USB_GPCS_DEVMOD_DEVVBUS 0x00000005  // Use USB0VBUS and force USB0ID
                                            // high

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_VDC register.
//
//*****************************************************************************
#define USB_VDC_VBDEN           0x00000001  // VBUS Droop Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_VDCRIS register.
//
//*****************************************************************************
#define USB_VDCRIS_VD           0x00000001  // VBUS Droop Raw Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_VDCIM register.
//
//*****************************************************************************
#define USB_VDCIM_VD            0x00000001  // VBUS Droop Interrupt Mask

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_VDCISC register.
//
//*****************************************************************************
#define USB_VDCISC_VD           0x00000001  // VBUS Droop Interrupt Status and
                                            // Clear

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_PP register.
//
//*****************************************************************************
#define USB_PP_ECNT_M           0x0000FF00  // Endpoint Count
#define USB_PP_USB_M            0x000000C0  // USB Capability
#define USB_PP_USB_DEVICE       0x00000040  // DEVICE
#define USB_PP_USB_HOSTDEVICE   0x00000080  // HOST
#define USB_PP_USB_OTG          0x000000C0  // OTG
#define USB_PP_ULPI             0x00000020  // ULPI Present
#define USB_PP_PHY              0x00000010  // PHY Present
#define USB_PP_TYPE_M           0x0000000F  // Controller Type
#define USB_PP_TYPE_0           0x00000000  // The first-generation USB
                                            // controller
#define USB_PP_TYPE_1           0x00000001  // Second-generation USB
                                            // controller.The controller
                                            // implemented in post Icestorm
                                            // devices that use the 3.0 version
                                            // of the Mentor controller
#define USB_PP_ECNT_S           8

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_PC register.
//
//*****************************************************************************
#define USB_PC_ULPIEN           0x00010000  // ULPI Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the USB_O_CC register.
//
//*****************************************************************************
#define USB_CC_CLKEN            0x00000200  // USB Clock Enable
#define USB_CC_CSD              0x00000100  // Clock Source/Direction
#define USB_CC_CLKDIV_M         0x0000000F  // PLL Clock Divisor
#define USB_CC_CLKDIV_S         0

//*****************************************************************************
//
// The following are defines for the bit fields in the EEPROM_EESIZE register.
//
//*****************************************************************************
#define EEPROM_EESIZE_BLKCNT_M  0x07FF0000  // Number of 16-Word Blocks
#define EEPROM_EESIZE_WORDCNT_M 0x0000FFFF  // Number of 32-Bit Words
#define EEPROM_EESIZE_BLKCNT_S  16
#define EEPROM_EESIZE_WORDCNT_S 0

//*****************************************************************************
//
// The following are defines for the bit fields in the EEPROM_EEBLOCK register.
//
//*****************************************************************************
#define EEPROM_EEBLOCK_BLOCK_M  0x0000FFFF  // Current Block
#define EEPROM_EEBLOCK_BLOCK_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the EEPROM_EEOFFSET
// register.
//
//*****************************************************************************
#define EEPROM_EEOFFSET_OFFSET_M                                              \
                                0x0000000F  // Current Address Offset
#define EEPROM_EEOFFSET_OFFSET_S                                              \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the EEPROM_EERDWR register.
//
//*****************************************************************************
#define EEPROM_EERDWR_VALUE_M   0xFFFFFFFF  // EEPROM Read or Write Data
#define EEPROM_EERDWR_VALUE_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the EEPROM_EERDWRINC
// register.
//
//*****************************************************************************
#define EEPROM_EERDWRINC_VALUE_M                                              \
                                0xFFFFFFFF  // EEPROM Read or Write Data with
                                            // Increment
#define EEPROM_EERDWRINC_VALUE_S                                              \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the EEPROM_EEDONE register.
//
//*****************************************************************************
#define EEPROM_EEDONE_INVPL     0x00000100  // Invalid Program Voltage Level
#define EEPROM_EEDONE_WRBUSY    0x00000020  // Write Busy
#define EEPROM_EEDONE_NOPERM    0x00000010  // Write Without Permission
#define EEPROM_EEDONE_WKCOPY    0x00000008  // Working on a Copy
#define EEPROM_EEDONE_WKERASE   0x00000004  // Working on an Erase
#define EEPROM_EEDONE_WORKING   0x00000001  // EEPROM Working

//*****************************************************************************
//
// The following are defines for the bit fields in the EEPROM_EESUPP register.
//
//*****************************************************************************
#define EEPROM_EESUPP_PRETRY    0x00000008  // Programming Must Be Retried
#define EEPROM_EESUPP_ERETRY    0x00000004  // Erase Must Be Retried
#define EEPROM_EESUPP_EREQ      0x00000002  // Erase Required
#define EEPROM_EESUPP_START     0x00000001  // Start Erase

//*****************************************************************************
//
// The following are defines for the bit fields in the EEPROM_EEUNLOCK
// register.
//
//*****************************************************************************
#define EEPROM_EEUNLOCK_UNLOCK_M                                              \
                                0xFFFFFFFF  // EEPROM Unlock

//*****************************************************************************
//
// The following are defines for the bit fields in the EEPROM_EEPROT register.
//
//*****************************************************************************
#define EEPROM_EEPROT_ACC       0x00000008  // Access Control
#define EEPROM_EEPROT_PROT_M    0x00000007  // Protection Control
#define EEPROM_EEPROT_PROT_RWNPW                                              \
                                0x00000000  // This setting is the default. If
                                            // there is no password, the block
                                            // is not protected and is readable
                                            // and writable
#define EEPROM_EEPROT_PROT_RWPW 0x00000001  // If there is a password, the
                                            // block is readable or writable
                                            // only when unlocked
#define EEPROM_EEPROT_PROT_RONPW                                              \
                                0x00000002  // If there is no password, the
                                            // block is readable, not writable

//*****************************************************************************
//
// The following are defines for the bit fields in the EEPROM_EEPASS0 register.
//
//*****************************************************************************
#define EEPROM_EEPASS0_PASS_M   0xFFFFFFFF  // Password
#define EEPROM_EEPASS0_PASS_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the EEPROM_EEPASS1 register.
//
//*****************************************************************************
#define EEPROM_EEPASS1_PASS_M   0xFFFFFFFF  // Password
#define EEPROM_EEPASS1_PASS_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the EEPROM_EEPASS2 register.
//
//*****************************************************************************
#define EEPROM_EEPASS2_PASS_M   0xFFFFFFFF  // Password
#define EEPROM_EEPASS2_PASS_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the EEPROM_EEINT register.
//
//*****************************************************************************
#define EEPROM_EEINT_INT        0x00000001  // Interrupt Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the EEPROM_EEHIDE0 register.
//
//*****************************************************************************
#define EEPROM_EEHIDE0_HN_M     0xFFFFFFFE  // Hide Block

//*****************************************************************************
//
// The following are defines for the bit fields in the EEPROM_EEHIDE1 register.
//
//*****************************************************************************
#define EEPROM_EEHIDE1_HN_M     0xFFFFFFFF  // Hide Block

//*****************************************************************************
//
// The following are defines for the bit fields in the EEPROM_EEHIDE2 register.
//
//*****************************************************************************
#define EEPROM_EEHIDE2_HN_M     0xFFFFFFFF  // Hide Block

//*****************************************************************************
//
// The following are defines for the bit fields in the EEPROM_EEDBGME register.
//
//*****************************************************************************
#define EEPROM_EEDBGME_KEY_M    0xFFFF0000  // Erase Key
#define EEPROM_EEDBGME_ME       0x00000001  // Mass Erase
#define EEPROM_EEDBGME_KEY_S    16

//*****************************************************************************
//
// The following are defines for the bit fields in the EEPROM_PP register.
//
//*****************************************************************************
#define EEPROM_PP_SIZE_M        0x0000FFFF  // EEPROM Size
#define EEPROM_PP_SIZE_64       0x00000000  // 64 bytes of EEPROM
#define EEPROM_PP_SIZE_128      0x00000001  // 128 bytes of EEPROM
#define EEPROM_PP_SIZE_256      0x00000003  // 256 bytes of EEPROM
#define EEPROM_PP_SIZE_512      0x00000007  // 512 bytes of EEPROM
#define EEPROM_PP_SIZE_1K       0x0000000F  // 1 KB of EEPROM
#define EEPROM_PP_SIZE_2K       0x0000001F  // 2 KB of EEPROM
#define EEPROM_PP_SIZE_3K       0x0000003F  // 3 KB of EEPROM
#define EEPROM_PP_SIZE_4K       0x0000007F  // 4 KB of EEPROM
#define EEPROM_PP_SIZE_5K       0x000000FF  // 5 KB of EEPROM
#define EEPROM_PP_SIZE_6K       0x000001FF  // 6 KB of EEPROM

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_CFG register.
//
//*****************************************************************************
#define EPI_CFG_INTDIV          0x00000100  // Integer Clock Divider Enable
#define EPI_CFG_BLKEN           0x00000010  // Block Enable
#define EPI_CFG_MODE_M          0x0000000F  // Mode Select
#define EPI_CFG_MODE_NONE       0x00000000  // General Purpose
#define EPI_CFG_MODE_SDRAM      0x00000001  // SDRAM
#define EPI_CFG_MODE_HB8        0x00000002  // 8-Bit Host-Bus (HB8)
#define EPI_CFG_MODE_HB16       0x00000003  // 16-Bit Host-Bus (HB16)

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_BAUD register.
//
//*****************************************************************************
#define EPI_BAUD_COUNT1_M       0xFFFF0000  // Baud Rate Counter 1
#define EPI_BAUD_COUNT0_M       0x0000FFFF  // Baud Rate Counter 0
#define EPI_BAUD_COUNT1_S       16
#define EPI_BAUD_COUNT0_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_BAUD2 register.
//
//*****************************************************************************
#define EPI_BAUD2_COUNT1_M      0xFFFF0000  // CS3n Baud Rate Counter 1
#define EPI_BAUD2_COUNT0_M      0x0000FFFF  // CS2n Baud Rate Counter 0
#define EPI_BAUD2_COUNT1_S      16
#define EPI_BAUD2_COUNT0_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_HB16CFG register.
//
//*****************************************************************************
#define EPI_HB16CFG_CLKGATE     0x80000000  // Clock Gated
#define EPI_HB16CFG_CLKGATEI    0x40000000  // Clock Gated Idle
#define EPI_HB16CFG_CLKINV      0x20000000  // Invert Output Clock Enable
#define EPI_HB16CFG_RDYEN       0x10000000  // Input Ready Enable
#define EPI_HB16CFG_IRDYINV     0x08000000  // Input Ready Invert
#define EPI_HB16CFG_XFFEN       0x00800000  // External FIFO FULL Enable
#define EPI_HB16CFG_XFEEN       0x00400000  // External FIFO EMPTY Enable
#define EPI_HB16CFG_WRHIGH      0x00200000  // WRITE Strobe Polarity
#define EPI_HB16CFG_RDHIGH      0x00100000  // READ Strobe Polarity
#define EPI_HB16CFG_ALEHIGH     0x00080000  // ALE Strobe Polarity
#define EPI_HB16CFG_WRCRE       0x00040000  // PSRAM Configuration Register
                                            // Write
#define EPI_HB16CFG_RDCRE       0x00020000  // PSRAM Configuration Register
                                            // Read
#define EPI_HB16CFG_BURST       0x00010000  // Burst Mode
#define EPI_HB16CFG_MAXWAIT_M   0x0000FF00  // Maximum Wait
#define EPI_HB16CFG_WRWS_M      0x000000C0  // Write Wait States
#define EPI_HB16CFG_WRWS_0      0x00000000  // No wait states
#define EPI_HB16CFG_WRWS_1      0x00000040  // 1 wait state
#define EPI_HB16CFG_WRWS_2      0x00000080  // 2 wait states
#define EPI_HB16CFG_WRWS_3      0x000000C0  // 3 wait states
#define EPI_HB16CFG_RDWS_M      0x00000030  // Read Wait States
#define EPI_HB16CFG_RDWS_0      0x00000000  // No wait states
#define EPI_HB16CFG_RDWS_1      0x00000010  // 1 wait state
#define EPI_HB16CFG_RDWS_2      0x00000020  // 2 wait states
#define EPI_HB16CFG_RDWS_3      0x00000030  // 3 wait states
#define EPI_HB16CFG_BSEL        0x00000004  // Byte Select Configuration
#define EPI_HB16CFG_MODE_M      0x00000003  // Host Bus Sub-Mode
#define EPI_HB16CFG_MODE_ADMUX  0x00000000  // ADMUX - AD[15:0]
#define EPI_HB16CFG_MODE_ADNMUX 0x00000001  // ADNONMUX - D[15:0]
#define EPI_HB16CFG_MODE_SRAM   0x00000002  // Continuous Read - D[15:0]
#define EPI_HB16CFG_MODE_XFIFO  0x00000003  // XFIFO - D[15:0]
#define EPI_HB16CFG_MAXWAIT_S   8

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_GPCFG register.
//
//*****************************************************************************
#define EPI_GPCFG_CLKPIN        0x80000000  // Clock Pin
#define EPI_GPCFG_CLKGATE       0x40000000  // Clock Gated
#define EPI_GPCFG_RDYEN         0x10000000  // Ready Enable
#define EPI_GPCFG_FRM50         0x04000000  // 50/50 Frame
#define EPI_GPCFG_FRMCNT_M      0x03C00000  // Frame Count
#define EPI_GPCFG_WR2CYC        0x00080000  // 2-Cycle Writes
#define EPI_GPCFG_MAXWAIT_M     0x0000FF00  // Maximum Wait
#define EPI_GPCFG_ASIZE_M       0x00000030  // Address Bus Size
#define EPI_GPCFG_ASIZE_NONE    0x00000000  // No address
#define EPI_GPCFG_ASIZE_4BIT    0x00000010  // Up to 4 bits wide
#define EPI_GPCFG_ASIZE_12BIT   0x00000020  // Up to 12 bits wide. This size
                                            // cannot be used with 24-bit data
#define EPI_GPCFG_ASIZE_20BIT   0x00000030  // Up to 20 bits wide. This size
                                            // cannot be used with data sizes
                                            // other than 8
#define EPI_GPCFG_DSIZE_M       0x00000003  // Size of Data Bus
#define EPI_GPCFG_DSIZE_4BIT    0x00000000  // 8 Bits Wide (EPI0S0 to EPI0S7)
#define EPI_GPCFG_DSIZE_16BIT   0x00000001  // 16 Bits Wide (EPI0S0 to EPI0S15)
#define EPI_GPCFG_DSIZE_24BIT   0x00000002  // 24 Bits Wide (EPI0S0 to EPI0S23)
#define EPI_GPCFG_DSIZE_32BIT   0x00000003  // 32 Bits Wide (EPI0S0 to EPI0S31)
#define EPI_GPCFG_FRMCNT_S      22
#define EPI_GPCFG_MAXWAIT_S     8

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_SDRAMCFG register.
//
//*****************************************************************************
#define EPI_SDRAMCFG_FREQ_M     0xC0000000  // EPI Frequency Range
#define EPI_SDRAMCFG_FREQ_NONE  0x00000000  // 0 - 15 MHz
#define EPI_SDRAMCFG_FREQ_15MHZ 0x40000000  // 15 - 30 MHz
#define EPI_SDRAMCFG_FREQ_30MHZ 0x80000000  // 30 - 50 MHz
#define EPI_SDRAMCFG_RFSH_M     0x07FF0000  // Refresh Counter
#define EPI_SDRAMCFG_SLEEP      0x00000200  // Sleep Mode
#define EPI_SDRAMCFG_SIZE_M     0x00000003  // Size of SDRAM
#define EPI_SDRAMCFG_SIZE_8MB   0x00000000  // 64 megabits (8MB)
#define EPI_SDRAMCFG_SIZE_16MB  0x00000001  // 128 megabits (16MB)
#define EPI_SDRAMCFG_SIZE_32MB  0x00000002  // 256 megabits (32MB)
#define EPI_SDRAMCFG_SIZE_64MB  0x00000003  // 512 megabits (64MB)
#define EPI_SDRAMCFG_RFSH_S     16

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_HB8CFG register.
//
//*****************************************************************************
#define EPI_HB8CFG_CLKGATE      0x80000000  // Clock Gated
#define EPI_HB8CFG_CLKGATEI     0x40000000  // Clock Gated when Idle
#define EPI_HB8CFG_CLKINV       0x20000000  // Invert Output Clock Enable
#define EPI_HB8CFG_RDYEN        0x10000000  // Input Ready Enable
#define EPI_HB8CFG_IRDYINV      0x08000000  // Input Ready Invert
#define EPI_HB8CFG_XFFEN        0x00800000  // External FIFO FULL Enable
#define EPI_HB8CFG_XFEEN        0x00400000  // External FIFO EMPTY Enable
#define EPI_HB8CFG_WRHIGH       0x00200000  // WRITE Strobe Polarity
#define EPI_HB8CFG_RDHIGH       0x00100000  // READ Strobe Polarity
#define EPI_HB8CFG_ALEHIGH      0x00080000  // ALE Strobe Polarity
#define EPI_HB8CFG_MAXWAIT_M    0x0000FF00  // Maximum Wait
#define EPI_HB8CFG_WRWS_M       0x000000C0  // Write Wait States
#define EPI_HB8CFG_WRWS_0       0x00000000  // No wait states
#define EPI_HB8CFG_WRWS_1       0x00000040  // 1 wait state
#define EPI_HB8CFG_WRWS_2       0x00000080  // 2 wait states
#define EPI_HB8CFG_WRWS_3       0x000000C0  // 3 wait states
#define EPI_HB8CFG_RDWS_M       0x00000030  // Read Wait States
#define EPI_HB8CFG_RDWS_0       0x00000000  // No wait states
#define EPI_HB8CFG_RDWS_1       0x00000010  // 1 wait state
#define EPI_HB8CFG_RDWS_2       0x00000020  // 2 wait states
#define EPI_HB8CFG_RDWS_3       0x00000030  // 3 wait states
#define EPI_HB8CFG_MODE_M       0x00000003  // Host Bus Sub-Mode
#define EPI_HB8CFG_MODE_MUX     0x00000000  // ADMUX - AD[7:0]
#define EPI_HB8CFG_MODE_NMUX    0x00000001  // ADNONMUX - D[7:0]
#define EPI_HB8CFG_MODE_SRAM    0x00000002  // Continuous Read - D[7:0]
#define EPI_HB8CFG_MODE_FIFO    0x00000003  // XFIFO - D[7:0]
#define EPI_HB8CFG_MAXWAIT_S    8

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_HB8CFG2 register.
//
//*****************************************************************************
#define EPI_HB8CFG2_CSCFGEXT    0x08000000  // Chip Select Extended
                                            // Configuration
#define EPI_HB8CFG2_CSBAUD      0x04000000  // Chip Select Baud Rate
#define EPI_HB8CFG2_CSCFG_M     0x03000000  // Chip Select Configuration
#define EPI_HB8CFG2_CSCFG_ALE   0x00000000  // ALE Configuration
#define EPI_HB8CFG2_CSCFG_CS    0x01000000  // CSn Configuration
#define EPI_HB8CFG2_CSCFG_DCS   0x02000000  // Dual CSn Configuration
#define EPI_HB8CFG2_CSCFG_ADCS  0x03000000  // ALE with Dual CSn Configuration
#define EPI_HB8CFG2_WRHIGH      0x00200000  // CS1n WRITE Strobe Polarity
#define EPI_HB8CFG2_RDHIGH      0x00100000  // CS1n READ Strobe Polarity
#define EPI_HB8CFG2_ALEHIGH     0x00080000  // CS1n ALE Strobe Polarity
#define EPI_HB8CFG2_WRWS_M      0x000000C0  // CS1n Write Wait States
#define EPI_HB8CFG2_WRWS_0      0x00000000  // No wait states
#define EPI_HB8CFG2_WRWS_1      0x00000040  // 1 wait state
#define EPI_HB8CFG2_WRWS_2      0x00000080  // 2 wait states
#define EPI_HB8CFG2_WRWS_3      0x000000C0  // 3 wait states
#define EPI_HB8CFG2_RDWS_M      0x00000030  // CS1n Read Wait States
#define EPI_HB8CFG2_RDWS_0      0x00000000  // No wait states
#define EPI_HB8CFG2_RDWS_1      0x00000010  // 1 wait state
#define EPI_HB8CFG2_RDWS_2      0x00000020  // 2 wait states
#define EPI_HB8CFG2_RDWS_3      0x00000030  // 3 wait states
#define EPI_HB8CFG2_MODE_M      0x00000003  // CS1n Host Bus Sub-Mode
#define EPI_HB8CFG2_MODE_ADMUX  0x00000000  // ADMUX - AD[7:0]
#define EPI_HB8CFG2_MODE_AD     0x00000001  // ADNONMUX - D[7:0]

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_HB16CFG2 register.
//
//*****************************************************************************
#define EPI_HB16CFG2_CSCFGEXT   0x08000000  // Chip Select Extended
                                            // Configuration
#define EPI_HB16CFG2_CSBAUD     0x04000000  // Chip Select Baud Rate
#define EPI_HB16CFG2_CSCFG_M    0x03000000  // Chip Select Configuration
#define EPI_HB16CFG2_CSCFG_ALE  0x00000000  // ALE Configuration
#define EPI_HB16CFG2_CSCFG_CS   0x01000000  // CSn Configuration
#define EPI_HB16CFG2_CSCFG_DCS  0x02000000  // Dual CSn Configuration
#define EPI_HB16CFG2_CSCFG_ADCS 0x03000000  // ALE with Dual CSn Configuration
#define EPI_HB16CFG2_WRHIGH     0x00200000  // CS1n WRITE Strobe Polarity
#define EPI_HB16CFG2_RDHIGH     0x00100000  // CS1n READ Strobe Polarity
#define EPI_HB16CFG2_ALEHIGH    0x00080000  // CS1n ALE Strobe Polarity
#define EPI_HB16CFG2_WRCRE      0x00040000  // CS1n PSRAM Configuration
                                            // Register Write
#define EPI_HB16CFG2_RDCRE      0x00020000  // CS1n PSRAM Configuration
                                            // Register Read
#define EPI_HB16CFG2_BURST      0x00010000  // CS1n Burst Mode
#define EPI_HB16CFG2_WRWS_M     0x000000C0  // CS1n Write Wait States
#define EPI_HB16CFG2_WRWS_0     0x00000000  // No wait states
#define EPI_HB16CFG2_WRWS_1     0x00000040  // 1 wait state
#define EPI_HB16CFG2_WRWS_2     0x00000080  // 2 wait states
#define EPI_HB16CFG2_WRWS_3     0x000000C0  // 3 wait states
#define EPI_HB16CFG2_RDWS_M     0x00000030  // CS1n Read Wait States
#define EPI_HB16CFG2_RDWS_0     0x00000000  // No wait states
#define EPI_HB16CFG2_RDWS_1     0x00000010  // 1 wait state
#define EPI_HB16CFG2_RDWS_2     0x00000020  // 2 wait states
#define EPI_HB16CFG2_RDWS_3     0x00000030  // 3 wait states
#define EPI_HB16CFG2_MODE_M     0x00000003  // CS1n Host Bus Sub-Mode
#define EPI_HB16CFG2_MODE_ADMUX 0x00000000  // ADMUX - AD[15:0]
#define EPI_HB16CFG2_MODE_AD    0x00000001  // ADNONMUX - D[15:0]
#define EPI_HB16CFG2_MODE_CR    0x00000002  // Continuous Read - D[15:0]

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_ADDRMAP register.
//
//*****************************************************************************
#define EPI_ADDRMAP_ECSZ_M      0x00000C00  // External Code Size
#define EPI_ADDRMAP_ECSZ_256B   0x00000000  // 256 bytes; lower address range:
                                            // 0x00 to 0xFF
#define EPI_ADDRMAP_ECSZ_64KB   0x00000400  // 64 KB; lower address range:
                                            // 0x0000 to 0xFFFF
#define EPI_ADDRMAP_ECSZ_16MB   0x00000800  // 16 MB; lower address range:
                                            // 0x00.0000 to 0xFF.FFFF
#define EPI_ADDRMAP_ECSZ_256MB  0x00000C00  // 256MB; lower address range:
                                            // 0x000.0000 to 0x0FFF.FFFF
#define EPI_ADDRMAP_ECADR_M     0x00000300  // External Code Address
#define EPI_ADDRMAP_ECADR_NONE  0x00000000  // Not mapped
#define EPI_ADDRMAP_ECADR_1000  0x00000100  // At 0x1000.0000
#define EPI_ADDRMAP_EPSZ_M      0x000000C0  // External Peripheral Size
#define EPI_ADDRMAP_EPSZ_256B   0x00000000  // 256 bytes; lower address range:
                                            // 0x00 to 0xFF
#define EPI_ADDRMAP_EPSZ_64KB   0x00000040  // 64 KB; lower address range:
                                            // 0x0000 to 0xFFFF
#define EPI_ADDRMAP_EPSZ_16MB   0x00000080  // 16 MB; lower address range:
                                            // 0x00.0000 to 0xFF.FFFF
#define EPI_ADDRMAP_EPSZ_256MB  0x000000C0  // 256 MB; lower address range:
                                            // 0x000.0000 to 0xFFF.FFFF
#define EPI_ADDRMAP_EPADR_M     0x00000030  // External Peripheral Address
#define EPI_ADDRMAP_EPADR_NONE  0x00000000  // Not mapped
#define EPI_ADDRMAP_EPADR_A000  0x00000010  // At 0xA000.0000
#define EPI_ADDRMAP_EPADR_C000  0x00000020  // At 0xC000.0000
#define EPI_ADDRMAP_EPADR_HBQS  0x00000030  // Only to be used with Host Bus
                                            // quad chip select. In quad chip
                                            // select mode, CS2n maps to
                                            // 0xA000.0000 and CS3n maps to
                                            // 0xC000.0000
#define EPI_ADDRMAP_ERSZ_M      0x0000000C  // External RAM Size
#define EPI_ADDRMAP_ERSZ_256B   0x00000000  // 256 bytes; lower address range:
                                            // 0x00 to 0xFF
#define EPI_ADDRMAP_ERSZ_64KB   0x00000004  // 64 KB; lower address range:
                                            // 0x0000 to 0xFFFF
#define EPI_ADDRMAP_ERSZ_16MB   0x00000008  // 16 MB; lower address range:
                                            // 0x00.0000 to 0xFF.FFFF
#define EPI_ADDRMAP_ERSZ_256MB  0x0000000C  // 256 MB; lower address range:
                                            // 0x000.0000 to 0xFFF.FFFF
#define EPI_ADDRMAP_ERADR_M     0x00000003  // External RAM Address
#define EPI_ADDRMAP_ERADR_NONE  0x00000000  // Not mapped
#define EPI_ADDRMAP_ERADR_6000  0x00000001  // At 0x6000.0000
#define EPI_ADDRMAP_ERADR_8000  0x00000002  // At 0x8000.0000
#define EPI_ADDRMAP_ERADR_HBQS  0x00000003  // Only to be used with Host Bus
                                            // quad chip select. In quad chip
                                            // select mode, CS0n maps to
                                            // 0x6000.0000 and CS1n maps to
                                            // 0x8000.0000

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_RSIZE0 register.
//
//*****************************************************************************
#define EPI_RSIZE0_SIZE_M       0x00000003  // Current Size
#define EPI_RSIZE0_SIZE_8BIT    0x00000001  // Byte (8 bits)
#define EPI_RSIZE0_SIZE_16BIT   0x00000002  // Half-word (16 bits)
#define EPI_RSIZE0_SIZE_32BIT   0x00000003  // Word (32 bits)

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_RADDR0 register.
//
//*****************************************************************************
#define EPI_RADDR0_ADDR_M       0xFFFFFFFF  // Current Address
#define EPI_RADDR0_ADDR_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_RPSTD0 register.
//
//*****************************************************************************
#define EPI_RPSTD0_POSTCNT_M    0x00001FFF  // Post Count
#define EPI_RPSTD0_POSTCNT_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_RSIZE1 register.
//
//*****************************************************************************
#define EPI_RSIZE1_SIZE_M       0x00000003  // Current Size
#define EPI_RSIZE1_SIZE_8BIT    0x00000001  // Byte (8 bits)
#define EPI_RSIZE1_SIZE_16BIT   0x00000002  // Half-word (16 bits)
#define EPI_RSIZE1_SIZE_32BIT   0x00000003  // Word (32 bits)

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_RADDR1 register.
//
//*****************************************************************************
#define EPI_RADDR1_ADDR_M       0xFFFFFFFF  // Current Address
#define EPI_RADDR1_ADDR_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_RPSTD1 register.
//
//*****************************************************************************
#define EPI_RPSTD1_POSTCNT_M    0x00001FFF  // Post Count
#define EPI_RPSTD1_POSTCNT_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_STAT register.
//
//*****************************************************************************
#define EPI_STAT_CELOW          0x00000200  // Clock Enable Low
#define EPI_STAT_XFFULL         0x00000100  // External FIFO Full
#define EPI_STAT_XFEMPTY        0x00000080  // External FIFO Empty
#define EPI_STAT_INITSEQ        0x00000040  // Initialization Sequence
#define EPI_STAT_WBUSY          0x00000020  // Write Busy
#define EPI_STAT_NBRBUSY        0x00000010  // Non-Blocking Read Busy
#define EPI_STAT_ACTIVE         0x00000001  // Register Active

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_RFIFOCNT register.
//
//*****************************************************************************
#define EPI_RFIFOCNT_COUNT_M    0x0000000F  // FIFO Count
#define EPI_RFIFOCNT_COUNT_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_READFIFO0
// register.
//
//*****************************************************************************
#define EPI_READFIFO0_DATA_M    0xFFFFFFFF  // Reads Data
#define EPI_READFIFO0_DATA_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_READFIFO1
// register.
//
//*****************************************************************************
#define EPI_READFIFO1_DATA_M    0xFFFFFFFF  // Reads Data
#define EPI_READFIFO1_DATA_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_READFIFO2
// register.
//
//*****************************************************************************
#define EPI_READFIFO2_DATA_M    0xFFFFFFFF  // Reads Data
#define EPI_READFIFO2_DATA_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_READFIFO3
// register.
//
//*****************************************************************************
#define EPI_READFIFO3_DATA_M    0xFFFFFFFF  // Reads Data
#define EPI_READFIFO3_DATA_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_READFIFO4
// register.
//
//*****************************************************************************
#define EPI_READFIFO4_DATA_M    0xFFFFFFFF  // Reads Data
#define EPI_READFIFO4_DATA_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_READFIFO5
// register.
//
//*****************************************************************************
#define EPI_READFIFO5_DATA_M    0xFFFFFFFF  // Reads Data
#define EPI_READFIFO5_DATA_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_READFIFO6
// register.
//
//*****************************************************************************
#define EPI_READFIFO6_DATA_M    0xFFFFFFFF  // Reads Data
#define EPI_READFIFO6_DATA_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_READFIFO7
// register.
//
//*****************************************************************************
#define EPI_READFIFO7_DATA_M    0xFFFFFFFF  // Reads Data
#define EPI_READFIFO7_DATA_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_FIFOLVL register.
//
//*****************************************************************************
#define EPI_FIFOLVL_WFERR       0x00020000  // Write Full Error
#define EPI_FIFOLVL_RSERR       0x00010000  // Read Stall Error
#define EPI_FIFOLVL_WRFIFO_M    0x00000070  // Write FIFO
#define EPI_FIFOLVL_WRFIFO_EMPT 0x00000000  // Trigger when there are any
                                            // spaces available in the WFIFO
#define EPI_FIFOLVL_WRFIFO_1_4  0x00000020  // Trigger when there are up to 3
                                            // spaces available in the WFIFO
#define EPI_FIFOLVL_WRFIFO_1_2  0x00000030  // Trigger when there are up to 2
                                            // spaces available in the WFIFO
#define EPI_FIFOLVL_WRFIFO_3_4  0x00000040  // Trigger when there is 1 space
                                            // available in the WFIFO
#define EPI_FIFOLVL_RDFIFO_M    0x00000007  // Read FIFO
#define EPI_FIFOLVL_RDFIFO_1_8  0x00000001  // Trigger when there are 1 or more
                                            // entries in the NBRFIFO
#define EPI_FIFOLVL_RDFIFO_1_4  0x00000002  // Trigger when there are 2 or more
                                            // entries in the NBRFIFO
#define EPI_FIFOLVL_RDFIFO_1_2  0x00000003  // Trigger when there are 4 or more
                                            // entries in the NBRFIFO
#define EPI_FIFOLVL_RDFIFO_3_4  0x00000004  // Trigger when there are 6 or more
                                            // entries in the NBRFIFO
#define EPI_FIFOLVL_RDFIFO_7_8  0x00000005  // Trigger when there are 7 or more
                                            // entries in the NBRFIFO
#define EPI_FIFOLVL_RDFIFO_FULL 0x00000006  // Trigger when there are 8 entries
                                            // in the NBRFIFO

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_WFIFOCNT register.
//
//*****************************************************************************
#define EPI_WFIFOCNT_WTAV_M     0x00000007  // Available Write Transactions
#define EPI_WFIFOCNT_WTAV_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_DMATXCNT register.
//
//*****************************************************************************
#define EPI_DMATXCNT_TXCNT_M    0x0000FFFF  // DMA Count
#define EPI_DMATXCNT_TXCNT_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_IM register.
//
//*****************************************************************************
#define EPI_IM_DMAWRIM          0x00000010  // Write uDMA Interrupt Mask
#define EPI_IM_DMARDIM          0x00000008  // Read uDMA Interrupt Mask
#define EPI_IM_WRIM             0x00000004  // Write FIFO Empty Interrupt Mask
#define EPI_IM_RDIM             0x00000002  // Read FIFO Full Interrupt Mask
#define EPI_IM_ERRIM            0x00000001  // Error Interrupt Mask

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_RIS register.
//
//*****************************************************************************
#define EPI_RIS_DMAWRRIS        0x00000010  // Write uDMA Raw Interrupt Status
#define EPI_RIS_DMARDRIS        0x00000008  // Read uDMA Raw Interrupt Status
#define EPI_RIS_WRRIS           0x00000004  // Write Raw Interrupt Status
#define EPI_RIS_RDRIS           0x00000002  // Read Raw Interrupt Status
#define EPI_RIS_ERRRIS          0x00000001  // Error Raw Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_MIS register.
//
//*****************************************************************************
#define EPI_MIS_DMAWRMIS        0x00000010  // Write uDMA Masked Interrupt
                                            // Status
#define EPI_MIS_DMARDMIS        0x00000008  // Read uDMA Masked Interrupt
                                            // Status
#define EPI_MIS_WRMIS           0x00000004  // Write Masked Interrupt Status
#define EPI_MIS_RDMIS           0x00000002  // Read Masked Interrupt Status
#define EPI_MIS_ERRMIS          0x00000001  // Error Masked Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_EISC register.
//
//*****************************************************************************
#define EPI_EISC_DMAWRIC        0x00000010  // Write uDMA Interrupt Clear
#define EPI_EISC_DMARDIC        0x00000008  // Read uDMA Interrupt Clear
#define EPI_EISC_WTFULL         0x00000004  // Write FIFO Full Error
#define EPI_EISC_RSTALL         0x00000002  // Read Stalled Error
#define EPI_EISC_TOUT           0x00000001  // Timeout Error

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_HB8CFG3 register.
//
//*****************************************************************************
#define EPI_HB8CFG3_WRHIGH      0x00200000  // CS2n WRITE Strobe Polarity
#define EPI_HB8CFG3_RDHIGH      0x00100000  // CS2n READ Strobe Polarity
#define EPI_HB8CFG3_ALEHIGH     0x00080000  // CS2n ALE Strobe Polarity
#define EPI_HB8CFG3_WRWS_M      0x000000C0  // CS2n Write Wait States
#define EPI_HB8CFG3_WRWS_2      0x00000000  // Active WRn is 2 EPI clocks
#define EPI_HB8CFG3_WRWS_4      0x00000040  // Active WRn is 4 EPI clocks
#define EPI_HB8CFG3_WRWS_6      0x00000080  // Active WRn is 6 EPI clocks
#define EPI_HB8CFG3_WRWS_8      0x000000C0  // Active WRn is 8 EPI clocks
#define EPI_HB8CFG3_RDWS_M      0x00000030  // CS2n Read Wait States
#define EPI_HB8CFG3_RDWS_2      0x00000000  // Active RDn is 2 EPI clocks
#define EPI_HB8CFG3_RDWS_4      0x00000010  // Active RDn is 4 EPI clocks
#define EPI_HB8CFG3_RDWS_6      0x00000020  // Active RDn is 6 EPI clocks
#define EPI_HB8CFG3_RDWS_8      0x00000030  // Active RDn is 8 EPI clocks
#define EPI_HB8CFG3_MODE_M      0x00000003  // CS2n Host Bus Sub-Mode
#define EPI_HB8CFG3_MODE_ADMUX  0x00000000  // ADMUX - AD[7:0]
#define EPI_HB8CFG3_MODE_AD     0x00000001  // ADNONMUX - D[7:0]
#define EPI_HB8CFG3_MODE_CR     0x00000002  // Continuous Read - D[7:0]

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_HB16CFG3 register.
//
//*****************************************************************************
#define EPI_HB16CFG3_WRHIGH     0x00200000  // CS2n WRITE Strobe Polarity
#define EPI_HB16CFG3_RDHIGH     0x00100000  // CS2n READ Strobe Polarity
#define EPI_HB16CFG3_ALEHIGH    0x00080000  // CS2n ALE Strobe Polarity
#define EPI_HB16CFG3_WRCRE      0x00040000  // CS2n PSRAM Configuration
                                            // Register Write
#define EPI_HB16CFG3_RDCRE      0x00020000  // CS2n PSRAM Configuration
                                            // Register Read
#define EPI_HB16CFG3_BURST      0x00010000  // CS2n Burst Mode
#define EPI_HB16CFG3_WRWS_M     0x000000C0  // CS2n Write Wait States
#define EPI_HB16CFG3_WRWS_2     0x00000000  // Active WRn is 2 EPI clocks
#define EPI_HB16CFG3_WRWS_4     0x00000040  // Active WRn is 4 EPI clocks
#define EPI_HB16CFG3_WRWS_6     0x00000080  // Active WRn is 6 EPI clocks
#define EPI_HB16CFG3_WRWS_8     0x000000C0  // Active WRn is 8 EPI clocks
#define EPI_HB16CFG3_RDWS_M     0x00000030  // CS2n Read Wait States
#define EPI_HB16CFG3_RDWS_2     0x00000000  // Active RDn is 2 EPI clocks
#define EPI_HB16CFG3_RDWS_4     0x00000010  // Active RDn is 4 EPI clocks
#define EPI_HB16CFG3_RDWS_6     0x00000020  // Active RDn is 6 EPI clocks
#define EPI_HB16CFG3_RDWS_8     0x00000030  // Active RDn is 8 EPI clocks
#define EPI_HB16CFG3_MODE_M     0x00000003  // CS2n Host Bus Sub-Mode
#define EPI_HB16CFG3_MODE_ADMUX 0x00000000  // ADMUX - AD[15:0]
#define EPI_HB16CFG3_MODE_AD    0x00000001  // ADNONMUX - D[15:0]
#define EPI_HB16CFG3_MODE_CR    0x00000002  // Continuous Read - D[15:0]

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_HB16CFG4 register.
//
//*****************************************************************************
#define EPI_HB16CFG4_WRHIGH     0x00200000  // CS3n WRITE Strobe Polarity
#define EPI_HB16CFG4_RDHIGH     0x00100000  // CS3n READ Strobe Polarity
#define EPI_HB16CFG4_ALEHIGH    0x00080000  // CS3n ALE Strobe Polarity
#define EPI_HB16CFG4_WRCRE      0x00040000  // CS3n PSRAM Configuration
                                            // Register Write
#define EPI_HB16CFG4_RDCRE      0x00020000  // CS3n PSRAM Configuration
                                            // Register Read
#define EPI_HB16CFG4_BURST      0x00010000  // CS3n Burst Mode
#define EPI_HB16CFG4_WRWS_M     0x000000C0  // CS3n Write Wait States
#define EPI_HB16CFG4_WRWS_2     0x00000000  // Active WRn is 2 EPI clocks
#define EPI_HB16CFG4_WRWS_4     0x00000040  // Active WRn is 4 EPI clocks
#define EPI_HB16CFG4_WRWS_6     0x00000080  // Active WRn is 6 EPI clocks
#define EPI_HB16CFG4_WRWS_8     0x000000C0  // Active WRn is 8 EPI clocks
#define EPI_HB16CFG4_RDWS_M     0x00000030  // CS3n Read Wait States
#define EPI_HB16CFG4_RDWS_2     0x00000000  // Active RDn is 2 EPI clocks
#define EPI_HB16CFG4_RDWS_4     0x00000010  // Active RDn is 4 EPI clocks
#define EPI_HB16CFG4_RDWS_6     0x00000020  // Active RDn is 6 EPI clocks
#define EPI_HB16CFG4_RDWS_8     0x00000030  // Active RDn is 8 EPI clocks
#define EPI_HB16CFG4_MODE_M     0x00000003  // CS3n Host Bus Sub-Mode
#define EPI_HB16CFG4_MODE_ADMUX 0x00000000  // ADMUX - AD[15:0]
#define EPI_HB16CFG4_MODE_AD    0x00000001  // ADNONMUX - D[15:0]
#define EPI_HB16CFG4_MODE_CR    0x00000002  // Continuous Read - D[15:0]

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_HB8CFG4 register.
//
//*****************************************************************************
#define EPI_HB8CFG4_WRHIGH      0x00200000  // CS3n WRITE Strobe Polarity
#define EPI_HB8CFG4_RDHIGH      0x00100000  // CS2n READ Strobe Polarity
#define EPI_HB8CFG4_ALEHIGH     0x00080000  // CS3n ALE Strobe Polarity
#define EPI_HB8CFG4_WRWS_M      0x000000C0  // CS3n Write Wait States
#define EPI_HB8CFG4_WRWS_2      0x00000000  // Active WRn is 2 EPI clocks
#define EPI_HB8CFG4_WRWS_4      0x00000040  // Active WRn is 4 EPI clocks
#define EPI_HB8CFG4_WRWS_6      0x00000080  // Active WRn is 6 EPI clocks
#define EPI_HB8CFG4_WRWS_8      0x000000C0  // Active WRn is 8 EPI clocks
#define EPI_HB8CFG4_RDWS_M      0x00000030  // CS3n Read Wait States
#define EPI_HB8CFG4_RDWS_2      0x00000000  // Active RDn is 2 EPI clocks
#define EPI_HB8CFG4_RDWS_4      0x00000010  // Active RDn is 4 EPI clocks
#define EPI_HB8CFG4_RDWS_6      0x00000020  // Active RDn is 6 EPI clocks
#define EPI_HB8CFG4_RDWS_8      0x00000030  // Active RDn is 8 EPI clocks
#define EPI_HB8CFG4_MODE_M      0x00000003  // CS3n Host Bus Sub-Mode
#define EPI_HB8CFG4_MODE_ADMUX  0x00000000  // ADMUX - AD[7:0]
#define EPI_HB8CFG4_MODE_AD     0x00000001  // ADNONMUX - D[7:0]
#define EPI_HB8CFG4_MODE_CR     0x00000002  // Continuous Read - D[7:0]

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_HB8TIME register.
//
//*****************************************************************************
#define EPI_HB8TIME_IRDYDLY_M   0x03000000  // CS0n Input Ready Delay
#define EPI_HB8TIME_CAPWIDTH_M  0x00003000  // CS0n Inter-transfer Capture
                                            // Width
#define EPI_HB8TIME_WRWSM       0x00000010  // Write Wait State Minus One
#define EPI_HB8TIME_RDWSM       0x00000001  // Read Wait State Minus One
#define EPI_HB8TIME_IRDYDLY_S   24
#define EPI_HB8TIME_CAPWIDTH_S  12

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_HB16TIME register.
//
//*****************************************************************************
#define EPI_HB16TIME_IRDYDLY_M  0x03000000  // CS0n Input Ready Delay
#define EPI_HB16TIME_PSRAMSZ_M  0x00070000  // PSRAM Row Size
#define EPI_HB16TIME_PSRAMSZ_0  0x00000000  // No PSRAM
#define EPI_HB16TIME_PSRAMSZ_128B                                             \
                                0x00010000  // 128 B
#define EPI_HB16TIME_PSRAMSZ_256B                                             \
                                0x00020000  // 256 B
#define EPI_HB16TIME_PSRAMSZ_512B                                             \
                                0x00030000  // 512 B
#define EPI_HB16TIME_PSRAMSZ_1KB                                              \
                                0x00040000  // 1024 B
#define EPI_HB16TIME_PSRAMSZ_2KB                                              \
                                0x00050000  // 2048 B
#define EPI_HB16TIME_PSRAMSZ_4KB                                              \
                                0x00060000  // 4096 B
#define EPI_HB16TIME_PSRAMSZ_8KB                                              \
                                0x00070000  // 8192 B
#define EPI_HB16TIME_CAPWIDTH_M 0x00003000  // CS0n Inter-transfer Capture
                                            // Width
#define EPI_HB16TIME_WRWSM      0x00000010  // Write Wait State Minus One
#define EPI_HB16TIME_RDWSM      0x00000001  // Read Wait State Minus One
#define EPI_HB16TIME_IRDYDLY_S  24
#define EPI_HB16TIME_CAPWIDTH_S 12

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_HB8TIME2 register.
//
//*****************************************************************************
#define EPI_HB8TIME2_IRDYDLY_M  0x03000000  // CS1n Input Ready Delay
#define EPI_HB8TIME2_CAPWIDTH_M 0x00003000  // CS1n Inter-transfer Capture
                                            // Width
#define EPI_HB8TIME2_WRWSM      0x00000010  // CS1n Write Wait State Minus One
#define EPI_HB8TIME2_RDWSM      0x00000001  // CS1n Read Wait State Minus One
#define EPI_HB8TIME2_IRDYDLY_S  24
#define EPI_HB8TIME2_CAPWIDTH_S 12

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_HB16TIME2
// register.
//
//*****************************************************************************
#define EPI_HB16TIME2_IRDYDLY_M 0x03000000  // CS1n Input Ready Delay
#define EPI_HB16TIME2_PSRAMSZ_M 0x00070000  // PSRAM Row Size
#define EPI_HB16TIME2_PSRAMSZ_0 0x00000000  // No PSRAM
#define EPI_HB16TIME2_PSRAMSZ_128B                                            \
                                0x00010000  // 128 B
#define EPI_HB16TIME2_PSRAMSZ_256B                                            \
                                0x00020000  // 256 B
#define EPI_HB16TIME2_PSRAMSZ_512B                                            \
                                0x00030000  // 512 B
#define EPI_HB16TIME2_PSRAMSZ_1KB                                             \
                                0x00040000  // 1024 B
#define EPI_HB16TIME2_PSRAMSZ_2KB                                             \
                                0x00050000  // 2048 B
#define EPI_HB16TIME2_PSRAMSZ_4KB                                             \
                                0x00060000  // 4096 B
#define EPI_HB16TIME2_PSRAMSZ_8KB                                             \
                                0x00070000  // 8192 B
#define EPI_HB16TIME2_CAPWIDTH_M                                              \
                                0x00003000  // CS1n Inter-transfer Capture
                                            // Width
#define EPI_HB16TIME2_WRWSM     0x00000010  // CS1n Write Wait State Minus One
#define EPI_HB16TIME2_RDWSM     0x00000001  // CS1n Read Wait State Minus One
#define EPI_HB16TIME2_IRDYDLY_S 24
#define EPI_HB16TIME2_CAPWIDTH_S                                              \
                                12

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_HB16TIME3
// register.
//
//*****************************************************************************
#define EPI_HB16TIME3_IRDYDLY_M 0x03000000  // CS2n Input Ready Delay
#define EPI_HB16TIME3_PSRAMSZ_M 0x00070000  // PSRAM Row Size
#define EPI_HB16TIME3_PSRAMSZ_0 0x00000000  // No PSRAM
#define EPI_HB16TIME3_PSRAMSZ_128B                                            \
                                0x00010000  // 128 B
#define EPI_HB16TIME3_PSRAMSZ_256B                                            \
                                0x00020000  // 256 B
#define EPI_HB16TIME3_PSRAMSZ_512B                                            \
                                0x00030000  // 512 B
#define EPI_HB16TIME3_PSRAMSZ_1KB                                             \
                                0x00040000  // 1024 B
#define EPI_HB16TIME3_PSRAMSZ_2KB                                             \
                                0x00050000  // 2048 B
#define EPI_HB16TIME3_PSRAMSZ_4KB                                             \
                                0x00060000  // 4096 B
#define EPI_HB16TIME3_PSRAMSZ_8KB                                             \
                                0x00070000  // 8192 B
#define EPI_HB16TIME3_CAPWIDTH_M                                              \
                                0x00003000  // CS2n Inter-transfer Capture
                                            // Width
#define EPI_HB16TIME3_WRWSM     0x00000010  // CS2n Write Wait State Minus One
#define EPI_HB16TIME3_RDWSM     0x00000001  // CS2n Read Wait State Minus One
#define EPI_HB16TIME3_IRDYDLY_S 24
#define EPI_HB16TIME3_CAPWIDTH_S                                              \
                                12

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_HB8TIME3 register.
//
//*****************************************************************************
#define EPI_HB8TIME3_IRDYDLY_M  0x03000000  // CS2n Input Ready Delay
#define EPI_HB8TIME3_CAPWIDTH_M 0x00003000  // CS2n Inter-transfer Capture
                                            // Width
#define EPI_HB8TIME3_WRWSM      0x00000010  // CS2n Write Wait State Minus One
#define EPI_HB8TIME3_RDWSM      0x00000001  // CS2n Read Wait State Minus One
#define EPI_HB8TIME3_IRDYDLY_S  24
#define EPI_HB8TIME3_CAPWIDTH_S 12

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_HB8TIME4 register.
//
//*****************************************************************************
#define EPI_HB8TIME4_IRDYDLY_M  0x03000000  // CS3n Input Ready Delay
#define EPI_HB8TIME4_CAPWIDTH_M 0x00003000  // CS3n Inter-transfer Capture
                                            // Width
#define EPI_HB8TIME4_WRWSM      0x00000010  // CS3n Write Wait State Minus One
#define EPI_HB8TIME4_RDWSM      0x00000001  // CS3n Read Wait State Minus One
#define EPI_HB8TIME4_IRDYDLY_S  24
#define EPI_HB8TIME4_CAPWIDTH_S 12

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_HB16TIME4
// register.
//
//*****************************************************************************
#define EPI_HB16TIME4_IRDYDLY_M 0x03000000  // CS3n Input Ready Delay
#define EPI_HB16TIME4_PSRAMSZ_M 0x00070000  // PSRAM Row Size
#define EPI_HB16TIME4_PSRAMSZ_0 0x00000000  // No PSRAM
#define EPI_HB16TIME4_PSRAMSZ_128B                                            \
                                0x00010000  // 128 B
#define EPI_HB16TIME4_PSRAMSZ_256B                                            \
                                0x00020000  // 256 B
#define EPI_HB16TIME4_PSRAMSZ_512B                                            \
                                0x00030000  // 512 B
#define EPI_HB16TIME4_PSRAMSZ_1KB                                             \
                                0x00040000  // 1024 B
#define EPI_HB16TIME4_PSRAMSZ_2KB                                             \
                                0x00050000  // 2048 B
#define EPI_HB16TIME4_PSRAMSZ_4KB                                             \
                                0x00060000  // 4096 B
#define EPI_HB16TIME4_PSRAMSZ_8KB                                             \
                                0x00070000  // 8192 B
#define EPI_HB16TIME4_CAPWIDTH_M                                              \
                                0x00003000  // CS3n Inter-transfer Capture
                                            // Width
#define EPI_HB16TIME4_WRWSM     0x00000010  // CS3n Write Wait State Minus One
#define EPI_HB16TIME4_RDWSM     0x00000001  // CS3n Read Wait State Minus One
#define EPI_HB16TIME4_IRDYDLY_S 24
#define EPI_HB16TIME4_CAPWIDTH_S                                              \
                                12

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_HBPSRAM register.
//
//*****************************************************************************
#define EPI_HBPSRAM_CR_M        0x001FFFFF  // PSRAM Config Register
#define EPI_HBPSRAM_CR_S        0

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSEXC_RIS register.
//
//*****************************************************************************
#define SYSEXC_RIS_FPIXCRIS     0x00000020  // Floating-Point Inexact Exception
                                            // Raw Interrupt Status
#define SYSEXC_RIS_FPOFCRIS     0x00000010  // Floating-Point Overflow
                                            // Exception Raw Interrupt Status
#define SYSEXC_RIS_FPUFCRIS     0x00000008  // Floating-Point Underflow
                                            // Exception Raw Interrupt Status
#define SYSEXC_RIS_FPIOCRIS     0x00000004  // Floating-Point Invalid Operation
                                            // Raw Interrupt Status
#define SYSEXC_RIS_FPDZCRIS     0x00000002  // Floating-Point Divide By 0
                                            // Exception Raw Interrupt Status
#define SYSEXC_RIS_FPIDCRIS     0x00000001  // Floating-Point Input Denormal
                                            // Exception Raw Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSEXC_IM register.
//
//*****************************************************************************
#define SYSEXC_IM_FPIXCIM       0x00000020  // Floating-Point Inexact Exception
                                            // Interrupt Mask
#define SYSEXC_IM_FPOFCIM       0x00000010  // Floating-Point Overflow
                                            // Exception Interrupt Mask
#define SYSEXC_IM_FPUFCIM       0x00000008  // Floating-Point Underflow
                                            // Exception Interrupt Mask
#define SYSEXC_IM_FPIOCIM       0x00000004  // Floating-Point Invalid Operation
                                            // Interrupt Mask
#define SYSEXC_IM_FPDZCIM       0x00000002  // Floating-Point Divide By 0
                                            // Exception Interrupt Mask
#define SYSEXC_IM_FPIDCIM       0x00000001  // Floating-Point Input Denormal
                                            // Exception Interrupt Mask

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSEXC_MIS register.
//
//*****************************************************************************
#define SYSEXC_MIS_FPIXCMIS     0x00000020  // Floating-Point Inexact Exception
                                            // Masked Interrupt Status
#define SYSEXC_MIS_FPOFCMIS     0x00000010  // Floating-Point Overflow
                                            // Exception Masked Interrupt
                                            // Status
#define SYSEXC_MIS_FPUFCMIS     0x00000008  // Floating-Point Underflow
                                            // Exception Masked Interrupt
                                            // Status
#define SYSEXC_MIS_FPIOCMIS     0x00000004  // Floating-Point Invalid Operation
                                            // Masked Interrupt Status
#define SYSEXC_MIS_FPDZCMIS     0x00000002  // Floating-Point Divide By 0
                                            // Exception Masked Interrupt
                                            // Status
#define SYSEXC_MIS_FPIDCMIS     0x00000001  // Floating-Point Input Denormal
                                            // Exception Masked Interrupt
                                            // Status

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSEXC_IC register.
//
//*****************************************************************************
#define SYSEXC_IC_FPIXCIC       0x00000020  // Floating-Point Inexact Exception
                                            // Interrupt Clear
#define SYSEXC_IC_FPOFCIC       0x00000010  // Floating-Point Overflow
                                            // Exception Interrupt Clear
#define SYSEXC_IC_FPUFCIC       0x00000008  // Floating-Point Underflow
                                            // Exception Interrupt Clear
#define SYSEXC_IC_FPIOCIC       0x00000004  // Floating-Point Invalid Operation
                                            // Interrupt Clear
#define SYSEXC_IC_FPDZCIC       0x00000002  // Floating-Point Divide By 0
                                            // Exception Interrupt Clear
#define SYSEXC_IC_FPIDCIC       0x00000001  // Floating-Point Input Denormal
                                            // Exception Interrupt Clear

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_RTCC register.
//
//*****************************************************************************
#define HIB_RTCC_M              0xFFFFFFFF  // RTC Counter
#define HIB_RTCC_S              0

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_RTCM0 register.
//
//*****************************************************************************
#define HIB_RTCM0_M             0xFFFFFFFF  // RTC Match 0
#define HIB_RTCM0_S             0

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_RTCLD register.
//
//*****************************************************************************
#define HIB_RTCLD_M             0xFFFFFFFF  // RTC Load
#define HIB_RTCLD_S             0

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_CTL register.
//
//*****************************************************************************
#define HIB_CTL_WRC             0x80000000  // Write Complete/Capable
#define HIB_CTL_RETCLR          0x40000000  // GPIO Retention/Clear
#define HIB_CTL_OSCSEL          0x00080000  // Oscillator Select
#define HIB_CTL_OSCDRV          0x00020000  // Oscillator Drive Capability
#define HIB_CTL_OSCBYP          0x00010000  // Oscillator Bypass
#define HIB_CTL_VBATSEL_M       0x00006000  // Select for Low-Battery
                                            // Comparator
#define HIB_CTL_VBATSEL_1_9V    0x00000000  // 1.9 Volts
#define HIB_CTL_VBATSEL_2_1V    0x00002000  // 2.1 Volts (default)
#define HIB_CTL_VBATSEL_2_3V    0x00004000  // 2.3 Volts
#define HIB_CTL_VBATSEL_2_5V    0x00006000  // 2.5 Volts
#define HIB_CTL_BATCHK          0x00000400  // Check Battery Status
#define HIB_CTL_BATWKEN         0x00000200  // Wake on Low Battery
#define HIB_CTL_VDD3ON          0x00000100  // VDD Powered
#define HIB_CTL_VABORT          0x00000080  // Power Cut Abort Enable
#define HIB_CTL_CLK32EN         0x00000040  // Clocking Enable
#define HIB_CTL_PINWEN          0x00000010  // External WAKE Pin Enable
#define HIB_CTL_RTCWEN          0x00000008  // RTC Wake-up Enable
#define HIB_CTL_HIBREQ          0x00000002  // Hibernation Request
#define HIB_CTL_RTCEN           0x00000001  // RTC Timer Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_IM register.
//
//*****************************************************************************
#define HIB_IM_VDDFAIL          0x00000080  // VDD Fail Interrupt Mask
#define HIB_IM_RSTWK            0x00000040  // Reset Pad I/O Wake-Up Interrupt
                                            // Mask
#define HIB_IM_PADIOWK          0x00000020  // Pad I/O Wake-Up Interrupt Mask
#define HIB_IM_WC               0x00000010  // External Write Complete/Capable
                                            // Interrupt Mask
#define HIB_IM_EXTW             0x00000008  // External Wake-Up Interrupt Mask
#define HIB_IM_LOWBAT           0x00000004  // Low Battery Voltage Interrupt
                                            // Mask
#define HIB_IM_RTCALT0          0x00000001  // RTC Alert 0 Interrupt Mask

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_RIS register.
//
//*****************************************************************************
#define HIB_RIS_VDDFAIL         0x00000080  // VDD Fail Raw Interrupt Status
#define HIB_RIS_RSTWK           0x00000040  // Reset Pad I/O Wake-Up Interrupt
                                            // Mask
#define HIB_RIS_PADIOWK         0x00000020  // Pad I/O Wake-Up Interrupt Mask
#define HIB_RIS_WC              0x00000010  // Write Complete/Capable Raw
                                            // Interrupt Status
#define HIB_RIS_EXTW            0x00000008  // External Wake-Up Raw Interrupt
                                            // Status
#define HIB_RIS_LOWBAT          0x00000004  // Low Battery Voltage Raw
                                            // Interrupt Status
#define HIB_RIS_RTCALT0         0x00000001  // RTC Alert 0 Raw Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_MIS register.
//
//*****************************************************************************
#define HIB_MIS_VDDFAIL         0x00000080  // VDD Fail Interrupt Mask
#define HIB_MIS_RSTWK           0x00000040  // Reset Pad I/O Wake-Up Interrupt
                                            // Mask
#define HIB_MIS_PADIOWK         0x00000020  // Pad I/O Wake-Up Interrupt Mask
#define HIB_MIS_WC              0x00000010  // Write Complete/Capable Masked
                                            // Interrupt Status
#define HIB_MIS_EXTW            0x00000008  // External Wake-Up Masked
                                            // Interrupt Status
#define HIB_MIS_LOWBAT          0x00000004  // Low Battery Voltage Masked
                                            // Interrupt Status
#define HIB_MIS_RTCALT0         0x00000001  // RTC Alert 0 Masked Interrupt
                                            // Status

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_IC register.
//
//*****************************************************************************
#define HIB_IC_VDDFAIL          0x00000080  // VDD Fail Interrupt Clear
#define HIB_IC_RSTWK            0x00000040  // Reset Pad I/O Wake-Up Interrupt
                                            // Mask
#define HIB_IC_PADIOWK          0x00000020  // Pad I/O Wake-Up Interrupt Mask
#define HIB_IC_WC               0x00000010  // Write Complete/Capable Masked
                                            // Interrupt Clear
#define HIB_IC_EXTW             0x00000008  // External Wake-Up Masked
                                            // Interrupt Clear
#define HIB_IC_LOWBAT           0x00000004  // Low Battery Voltage Masked
                                            // Interrupt Clear
#define HIB_IC_RTCALT0          0x00000001  // RTC Alert0 Masked Interrupt
                                            // Clear

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_RTCT register.
//
//*****************************************************************************
#define HIB_RTCT_TRIM_M         0x0000FFFF  // RTC Trim Value
#define HIB_RTCT_TRIM_S         0

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_RTCSS register.
//
//*****************************************************************************
#define HIB_RTCSS_RTCSSM_M      0x7FFF0000  // RTC Sub Seconds Match
#define HIB_RTCSS_RTCSSC_M      0x00007FFF  // RTC Sub Seconds Count
#define HIB_RTCSS_RTCSSM_S      16
#define HIB_RTCSS_RTCSSC_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_IO register.
//
//*****************************************************************************
#define HIB_IO_IOWRC            0x80000000  // I/O Write Complete
#define HIB_IO_WURSTEN          0x00000010  // Reset Wake Source Enable
#define HIB_IO_WUUNLK           0x00000001  // I/O Wake Pad Configuration
                                            // Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_DATA register.
//
//*****************************************************************************
#define HIB_DATA_RTD_M          0xFFFFFFFF  // Hibernation Module NV Data
#define HIB_DATA_RTD_S          0

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_CALCTL register.
//
//*****************************************************************************
#define HIB_CALCTL_CAL24        0x00000004  // Calendar Mode
#define HIB_CALCTL_CALEN        0x00000001  // RTC Calendar/Counter Mode Select

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_CAL0 register.
//
//*****************************************************************************
#define HIB_CAL0_VALID          0x80000000  // Valid Calendar Load
#define HIB_CAL0_AMPM           0x00400000  // AM/PM Designation
#define HIB_CAL0_HR_M           0x001F0000  // Hours
#define HIB_CAL0_MIN_M          0x00003F00  // Minutes
#define HIB_CAL0_SEC_M          0x0000003F  // Seconds
#define HIB_CAL0_HR_S           16
#define HIB_CAL0_MIN_S          8
#define HIB_CAL0_SEC_S          0

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_CAL1 register.
//
//*****************************************************************************
#define HIB_CAL1_VALID          0x80000000  // Valid Calendar Load
#define HIB_CAL1_DOW_M          0x07000000  // Day of Week
#define HIB_CAL1_YEAR_M         0x007F0000  // Year Value
#define HIB_CAL1_MON_M          0x00000F00  // Month
#define HIB_CAL1_DOM_M          0x0000001F  // Day of Month
#define HIB_CAL1_DOW_S          24
#define HIB_CAL1_YEAR_S         16
#define HIB_CAL1_MON_S          8
#define HIB_CAL1_DOM_S          0

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_CALLD0 register.
//
//*****************************************************************************
#define HIB_CALLD0_AMPM         0x00400000  // AM/PM Designation
#define HIB_CALLD0_HR_M         0x001F0000  // Hours
#define HIB_CALLD0_MIN_M        0x00003F00  // Minutes
#define HIB_CALLD0_SEC_M        0x0000003F  // Seconds
#define HIB_CALLD0_HR_S         16
#define HIB_CALLD0_MIN_S        8
#define HIB_CALLD0_SEC_S        0

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_CALLD1 register.
//
//*****************************************************************************
#define HIB_CALLD1_DOW_M        0x07000000  // Day of Week
#define HIB_CALLD1_YEAR_M       0x007F0000  // Year Value
#define HIB_CALLD1_MON_M        0x00000F00  // Month
#define HIB_CALLD1_DOM_M        0x0000001F  // Day of Month
#define HIB_CALLD1_DOW_S        24
#define HIB_CALLD1_YEAR_S       16
#define HIB_CALLD1_MON_S        8
#define HIB_CALLD1_DOM_S        0

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_CALM0 register.
//
//*****************************************************************************
#define HIB_CALM0_AMPM          0x00400000  // AM/PM Designation
#define HIB_CALM0_HR_M          0x001F0000  // Hours
#define HIB_CALM0_MIN_M         0x00003F00  // Minutes
#define HIB_CALM0_SEC_M         0x0000003F  // Seconds
#define HIB_CALM0_HR_S          16
#define HIB_CALM0_MIN_S         8
#define HIB_CALM0_SEC_S         0

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_CALM1 register.
//
//*****************************************************************************
#define HIB_CALM1_DOM_M         0x0000001F  // Day of Month
#define HIB_CALM1_DOM_S         0

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_LOCK register.
//
//*****************************************************************************
#define HIB_LOCK_HIBLOCK_M      0xFFFFFFFF  // Hibernate Lock
#define HIB_LOCK_HIBLOCK_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_TPCTL register.
//
//*****************************************************************************
#define HIB_TPCTL_WAKE          0x00000800  // Wake from Hibernate on a Tamper
                                            // Event
#define HIB_TPCTL_MEMCLR_M      0x00000300  // HIB Memory Clear on Tamper Event
#define HIB_TPCTL_MEMCLR_NONE   0x00000000  // Do not Clear HIB memory on
                                            // tamper event
#define HIB_TPCTL_MEMCLR_LOW32  0x00000100  // Clear Lower 32 Bytes of HIB
                                            // memory on tamper event
#define HIB_TPCTL_MEMCLR_HIGH32 0x00000200  // Clear upper 32 Bytes of HIB
                                            // memory on tamper event
#define HIB_TPCTL_MEMCLR_ALL    0x00000300  // Clear all HIB memory on tamper
                                            // event
#define HIB_TPCTL_TPCLR         0x00000010  // Tamper Event Clear
#define HIB_TPCTL_TPEN          0x00000001  // Tamper Module Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_TPSTAT register.
//
//*****************************************************************************
#define HIB_TPSTAT_STATE_M      0x0000000C  // Tamper Module Status
#define HIB_TPSTAT_STATE_DISABLED                                             \
                                0x00000000  // Tamper disabled
#define HIB_TPSTAT_STATE_CONFIGED                                             \
                                0x00000004  // Tamper configured
#define HIB_TPSTAT_STATE_ERROR  0x00000008  // Tamper event occurred
#define HIB_TPSTAT_XOSCST       0x00000002  // External Oscillator Status
#define HIB_TPSTAT_XOSCFAIL     0x00000001  // External Oscillator Failure

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_TPIO register.
//
//*****************************************************************************
#define HIB_TPIO_GFLTR3         0x08000000  // TPIO3 Glitch Filtering
#define HIB_TPIO_PUEN3          0x04000000  // TPIO3 Internal Weak Pull-up
                                            // Enable
#define HIB_TPIO_LEV3           0x02000000  // TPIO3 Trigger Level
#define HIB_TPIO_EN3            0x01000000  // TPIO3 Enable
#define HIB_TPIO_GFLTR2         0x00080000  // TPIO2 Glitch Filtering
#define HIB_TPIO_PUEN2          0x00040000  // TPIO2 Internal Weak Pull-up
                                            // Enable
#define HIB_TPIO_LEV2           0x00020000  // TPIO2 Trigger Level
#define HIB_TPIO_EN2            0x00010000  // TPIO2 Enable
#define HIB_TPIO_GFLTR1         0x00000800  // TPIO1 Glitch Filtering
#define HIB_TPIO_PUEN1          0x00000400  // TPIO1 Internal Weak Pull-up
                                            // Enable
#define HIB_TPIO_LEV1           0x00000200  // TPIO1 Trigger Level
#define HIB_TPIO_EN1            0x00000100  // TPIO1Enable
#define HIB_TPIO_GFLTR0         0x00000008  // TPIO0 Glitch Filtering
#define HIB_TPIO_PUEN0          0x00000004  // TPIO0 Internal Weak Pull-up
                                            // Enable
#define HIB_TPIO_LEV0           0x00000002  // TPIO0 Trigger Level
#define HIB_TPIO_EN0            0x00000001  // TPIO0 Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_TPLOG0 register.
//
//*****************************************************************************
#define HIB_TPLOG0_TIME_M       0xFFFFFFFF  // Tamper Log Calendar Information
#define HIB_TPLOG0_TIME_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_TPLOG1 register.
//
//*****************************************************************************
#define HIB_TPLOG1_XOSC         0x00010000  // Status of external 32
#define HIB_TPLOG1_TRIG3        0x00000008  // Status of TPIO[3] Trigger
#define HIB_TPLOG1_TRIG2        0x00000004  // Status of TPIO[2] Trigger
#define HIB_TPLOG1_TRIG1        0x00000002  // Status of TPIO[1] Trigger
#define HIB_TPLOG1_TRIG0        0x00000001  // Status of TPIO[0] Trigger

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_TPLOG2 register.
//
//*****************************************************************************
#define HIB_TPLOG2_TIME_M       0xFFFFFFFF  // Tamper Log Calendar Information
#define HIB_TPLOG2_TIME_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_TPLOG3 register.
//
//*****************************************************************************
#define HIB_TPLOG3_XOSC         0x00010000  // Status of external 32
#define HIB_TPLOG3_TRIG3        0x00000008  // Status of TPIO[3] Trigger
#define HIB_TPLOG3_TRIG2        0x00000004  // Status of TPIO[2] Trigger
#define HIB_TPLOG3_TRIG1        0x00000002  // Status of TPIO[1] Trigger
#define HIB_TPLOG3_TRIG0        0x00000001  // Status of TPIO[0] Trigger

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_TPLOG4 register.
//
//*****************************************************************************
#define HIB_TPLOG4_TIME_M       0xFFFFFFFF  // Tamper Log Calendar Information
#define HIB_TPLOG4_TIME_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_TPLOG5 register.
//
//*****************************************************************************
#define HIB_TPLOG5_XOSC         0x00010000  // Status of external 32
#define HIB_TPLOG5_TRIG3        0x00000008  // Status of TPIO[3] Trigger
#define HIB_TPLOG5_TRIG2        0x00000004  // Status of TPIO[2] Trigger
#define HIB_TPLOG5_TRIG1        0x00000002  // Status of TPIO[1] Trigger
#define HIB_TPLOG5_TRIG0        0x00000001  // Status of TPIO[0] Trigger

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_TPLOG6 register.
//
//*****************************************************************************
#define HIB_TPLOG6_TIME_M       0xFFFFFFFF  // Tamper Log Calendar Information
#define HIB_TPLOG6_TIME_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_TPLOG7 register.
//
//*****************************************************************************
#define HIB_TPLOG7_XOSC         0x00010000  // Status of external 32
#define HIB_TPLOG7_TRIG3        0x00000008  // Status of TPIO[3] Trigger
#define HIB_TPLOG7_TRIG2        0x00000004  // Status of TPIO[2] Trigger
#define HIB_TPLOG7_TRIG1        0x00000002  // Status of TPIO[1] Trigger
#define HIB_TPLOG7_TRIG0        0x00000001  // Status of TPIO[0] Trigger

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_PP register.
//
//*****************************************************************************
#define HIB_PP_TAMPER           0x00000002  // Tamper Pin Presence
#define HIB_PP_WAKENC           0x00000001  // Wake Pin Presence

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_CC register.
//
//*****************************************************************************
#define HIB_CC_SYSCLKEN         0x00000001  // System Clock Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_FMA register.
//
//*****************************************************************************
#define FLASH_FMA_OFFSET_M      0x000FFFFF  // Address Offset
#define FLASH_FMA_OFFSET_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_FMD register.
//
//*****************************************************************************
#define FLASH_FMD_DATA_M        0xFFFFFFFF  // Data Value
#define FLASH_FMD_DATA_S        0

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_FMC register.
//
//*****************************************************************************
#define FLASH_FMC_WRKEY         0xA4420000  // FLASH write key
#define FLASH_FMC_COMT          0x00000008  // Commit Register Value
#define FLASH_FMC_MERASE        0x00000004  // Mass Erase Flash Memory
#define FLASH_FMC_ERASE         0x00000002  // Erase a Page of Flash Memory
#define FLASH_FMC_WRITE         0x00000001  // Write a Word into Flash Memory

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_FCRIS register.
//
//*****************************************************************************
#define FLASH_FCRIS_PROGRIS     0x00002000  // PROGVER Raw Interrupt Status
#define FLASH_FCRIS_ERRIS       0x00000800  // ERVER Raw Interrupt Status
#define FLASH_FCRIS_INVDRIS     0x00000400  // Invalid Data Raw Interrupt
                                            // Status
#define FLASH_FCRIS_VOLTRIS     0x00000200  // VOLTSTAT Raw Interrupt Status
#define FLASH_FCRIS_ERIS        0x00000004  // EEPROM Raw Interrupt Status
#define FLASH_FCRIS_PRIS        0x00000002  // Programming Raw Interrupt Status
#define FLASH_FCRIS_ARIS        0x00000001  // Access Raw Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_FCIM register.
//
//*****************************************************************************
#define FLASH_FCIM_PROGMASK     0x00002000  // PROGVER Interrupt Mask
#define FLASH_FCIM_ERMASK       0x00000800  // ERVER Interrupt Mask
#define FLASH_FCIM_INVDMASK     0x00000400  // Invalid Data Interrupt Mask
#define FLASH_FCIM_VOLTMASK     0x00000200  // VOLT Interrupt Mask
#define FLASH_FCIM_EMASK        0x00000004  // EEPROM Interrupt Mask
#define FLASH_FCIM_PMASK        0x00000002  // Programming Interrupt Mask
#define FLASH_FCIM_AMASK        0x00000001  // Access Interrupt Mask

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_FCMISC register.
//
//*****************************************************************************
#define FLASH_FCMISC_PROGMISC   0x00002000  // PROGVER Masked Interrupt Status
                                            // and Clear
#define FLASH_FCMISC_ERMISC     0x00000800  // ERVER Masked Interrupt Status
                                            // and Clear
#define FLASH_FCMISC_INVDMISC   0x00000400  // Invalid Data Masked Interrupt
                                            // Status and Clear
#define FLASH_FCMISC_VOLTMISC   0x00000200  // VOLT Masked Interrupt Status and
                                            // Clear
#define FLASH_FCMISC_EMISC      0x00000004  // EEPROM Masked Interrupt Status
                                            // and Clear
#define FLASH_FCMISC_PMISC      0x00000002  // Programming Masked Interrupt
                                            // Status and Clear
#define FLASH_FCMISC_AMISC      0x00000001  // Access Masked Interrupt Status
                                            // and Clear

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_FMC2 register.
//
//*****************************************************************************
#define FLASH_FMC2_WRBUF        0x00000001  // Buffered Flash Memory Write

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_FWBVAL register.
//
//*****************************************************************************
#define FLASH_FWBVAL_FWB_M      0xFFFFFFFF  // Flash Memory Write Buffer

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_FLPEKEY register.
//
//*****************************************************************************
#define FLASH_FLPEKEY_PEKEY_M   0x0000FFFF  // Key Value
#define FLASH_FLPEKEY_PEKEY_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_FWBN register.
//
//*****************************************************************************
#define FLASH_FWBN_DATA_M       0xFFFFFFFF  // Data

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_PP register.
//
//*****************************************************************************
#define FLASH_PP_PFC            0x40000000  // Prefetch Cache Mode
#define FLASH_PP_FMM            0x20000000  // Flash Mirror Mode
#define FLASH_PP_DFA            0x10000000  // DMA Code SRAM Access
#define FLASH_PP_EESS_M         0x00780000  // EEPROM Sector Size of the
                                            // physical bank
#define FLASH_PP_EESS_1KB       0x00000000  // 1 KB
#define FLASH_PP_EESS_2KB       0x00080000  // 2 KB
#define FLASH_PP_EESS_4KB       0x00100000  // 4 KB
#define FLASH_PP_EESS_8KB       0x00180000  // 8 KB
#define FLASH_PP_MAINSS_M       0x00070000  // Flash Sector Size of the
                                            // physical bank
#define FLASH_PP_MAINSS_1KB     0x00000000  // 1 KB
#define FLASH_PP_MAINSS_2KB     0x00010000  // 2 KB
#define FLASH_PP_MAINSS_4KB     0x00020000  // 4 KB
#define FLASH_PP_MAINSS_8KB     0x00030000  // 8 KB
#define FLASH_PP_MAINSS_16KB    0x00040000  // 16 KB
#define FLASH_PP_SIZE_M         0x0000FFFF  // Code SRAM Size
#define FLASH_PP_SIZE_16KB      0x00000007  // 16 KB of Code SRAM
#define FLASH_PP_SIZE_32KB      0x0000000F  // 32 KB of Code SRAM
#define FLASH_PP_SIZE_64KB      0x0000001F  // 64 KB of Code SRAM
#define FLASH_PP_SIZE_96KB      0x0000002F  // 96 KB of Code SRAM
#define FLASH_PP_SIZE_128KB     0x0000003F  // 128 KB of Code SRAM
#define FLASH_PP_SIZE_192KB     0x0000005F  // 192 KB of Flash
#define FLASH_PP_SIZE_256KB     0x0000007F  // 256 KB of Flash
#define FLASH_PP_SIZE_384KB     0x000000BF  // 384 K of Flash
#define FLASH_PP_SIZE_512KB     0x000000FF  // 512 KB of Flash
#define FLASH_PP_SIZE_1MB       0x000001FF  // 1024 KB of Flash

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_SSIZE register.
//
//*****************************************************************************
#define FLASH_SSIZE_SIZE_M      0x0000FFFF  // SRAM Size
#define FLASH_SSIZE_SIZE_256KB  0x000003FF  // 256 KB of SRAM

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_CONF register.
//
//*****************************************************************************
#define FLASH_CONF_FMME         0x40000000  // Flash Mirror Mode Enable
#define FLASH_CONF_SPFE         0x20000000  // Single Prefetch Mode Enable
#define FLASH_CONF_CLRTV        0x00100000  // Clear Tag Valid Bits
#define FLASH_CONF_FPFON        0x00020000  // Force Prefetch On
#define FLASH_CONF_FPFOFF       0x00010000  // Force Prefetch Off

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_ROMSWMAP register.
//
//*****************************************************************************
#define FLASH_ROMSWMAP_SW7EN_M  0x0000C000  // ROM SW Region 7 Availability
#define FLASH_ROMSWMAP_SW7EN_NOTVIS                                           \
                                0x00000000  // Not Visible outside of secure
                                            // INITIALIZATION
#define FLASH_ROMSWMAP_SW7EN_CORE                                             \
                                0x00004000  // Visible to core
#define FLASH_ROMSWMAP_SW6EN_M  0x00003000  // ROM SW Region 6 Availability
#define FLASH_ROMSWMAP_SW6EN_NOTVIS                                           \
                                0x00000000  // Not Visible outside of secure
                                            // INITIALIZATION
#define FLASH_ROMSWMAP_SW6EN_CORE                                             \
                                0x00001000  // Visible to core
#define FLASH_ROMSWMAP_SW5EN_M  0x00000C00  // ROM SW Region 5 Availability
#define FLASH_ROMSWMAP_SW5EN_NOTVIS                                           \
                                0x00000000  // Not Visible outside of secure
                                            // INITIALIZATION
#define FLASH_ROMSWMAP_SW5EN_CORE                                             \
                                0x00000400  // Visible to core
#define FLASH_ROMSWMAP_SW4EN_M  0x00000300  // ROM SW Region 4 Availability
#define FLASH_ROMSWMAP_SW4EN_NOTVIS                                           \
                                0x00000000  // Not Visible outside of secure
                                            // INITIALIZATION
#define FLASH_ROMSWMAP_SW4EN_CORE                                             \
                                0x00000100  // Visible to core
#define FLASH_ROMSWMAP_SW3EN_M  0x000000C0  // ROM SW Region 3 Availability
#define FLASH_ROMSWMAP_SW3EN_NOTVIS                                           \
                                0x00000000  // Not Visible outside of secure
                                            // INITIALIZATION
#define FLASH_ROMSWMAP_SW3EN_CORE                                             \
                                0x00000040  // Visible to core
#define FLASH_ROMSWMAP_SW2EN_M  0x00000030  // ROM SW Region 2 Availability
#define FLASH_ROMSWMAP_SW2EN_NOTVIS                                           \
                                0x00000000  // Not Visible outside of secure
                                            // INITIALIZATION
#define FLASH_ROMSWMAP_SW2EN_CORE                                             \
                                0x00000010  // Visible to core
#define FLASH_ROMSWMAP_SW1EN_M  0x0000000C  // ROM SW Region 1 Availability
#define FLASH_ROMSWMAP_SW1EN_NOTVIS                                           \
                                0x00000000  // Not Visible outside of secure
                                            // INITIALIZATION
#define FLASH_ROMSWMAP_SW1EN_CORE                                             \
                                0x00000004  // Visible to core
#define FLASH_ROMSWMAP_SW0EN_M  0x00000003  // ROM SW Region 0 Availability
#define FLASH_ROMSWMAP_SW0EN_NOTVIS                                           \
                                0x00000000  // Not Visible outside of secure
                                            // INITIALIZATION
#define FLASH_ROMSWMAP_SW0EN_CORE                                             \
                                0x00000001  // Visible to core

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_DMASZ register.
//
//*****************************************************************************
#define FLASH_DMASZ_SIZE_M      0x0003FFFF  // KBs of uDMA-accessible Address
                                            // Space in powers of 2
#define FLASH_DMASZ_SIZE_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_DMAST register.
//
//*****************************************************************************
#define FLASH_DMAST_ADDR_M      0x1FFFF800  // Contains the starting address of
                                            // the Code SRAM region accessible
                                            // by uDMA if the FLASHPP register
                                            // DFA bit is set
#define FLASH_DMAST_ADDR_S      11

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_RVP register.
//
//*****************************************************************************
#define FLASH_RVP_RV_M          0xFFFFFFFF  // Reset Vector Pointer Address
#define FLASH_RVP_RV_S          0

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_BOOTCFG register.
//
//*****************************************************************************
#define FLASH_BOOTCFG_NW        0x80000000  // Not Written
#define FLASH_BOOTCFG_PORT_M    0x0000E000  // Boot GPIO Port
#define FLASH_BOOTCFG_PORT_A    0x00000000  // Port A
#define FLASH_BOOTCFG_PORT_B    0x00002000  // Port B
#define FLASH_BOOTCFG_PORT_C    0x00004000  // Port C
#define FLASH_BOOTCFG_PORT_D    0x00006000  // Port D
#define FLASH_BOOTCFG_PORT_E    0x00008000  // Port E
#define FLASH_BOOTCFG_PORT_F    0x0000A000  // Port F
#define FLASH_BOOTCFG_PORT_G    0x0000C000  // Port G
#define FLASH_BOOTCFG_PORT_H    0x0000E000  // Port H
#define FLASH_BOOTCFG_PIN_M     0x00001C00  // Boot GPIO Pin
#define FLASH_BOOTCFG_PIN_0     0x00000000  // Pin 0
#define FLASH_BOOTCFG_PIN_1     0x00000400  // Pin 1
#define FLASH_BOOTCFG_PIN_2     0x00000800  // Pin 2
#define FLASH_BOOTCFG_PIN_3     0x00000C00  // Pin 3
#define FLASH_BOOTCFG_PIN_4     0x00001000  // Pin 4
#define FLASH_BOOTCFG_PIN_5     0x00001400  // Pin 5
#define FLASH_BOOTCFG_PIN_6     0x00001800  // Pin 6
#define FLASH_BOOTCFG_PIN_7     0x00001C00  // Pin 7
#define FLASH_BOOTCFG_POL       0x00000200  // Boot GPIO Polarity
#define FLASH_BOOTCFG_EN        0x00000100  // Boot GPIO Enable
#define FLASH_BOOTCFG_KEY       0x00000010  // KEY Select
#define FLASH_BOOTCFG_DBG1      0x00000002  // Debug Control 1
#define FLASH_BOOTCFG_DBG0      0x00000001  // Debug Control 0

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_USRPWRUP register.
//
//*****************************************************************************
#define FLASH_USRPWRUP_LDODISABL_M                                            \
                                0x000000FF  // LDO Disable
#define FLASH_USRPWRUP_LDODISABL_S                                            \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_USERREG0 register.
//
//*****************************************************************************
#define FLASH_USERREG0_DATA_M   0xFFFFFFFF  // User Data
#define FLASH_USERREG0_DATA_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_USERREG1 register.
//
//*****************************************************************************
#define FLASH_USERREG1_DATA_M   0xFFFFFFFF  // User Data
#define FLASH_USERREG1_DATA_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_USERREG2 register.
//
//*****************************************************************************
#define FLASH_USERREG2_DATA_M   0xFFFFFFFF  // User Data
#define FLASH_USERREG2_DATA_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_USERREG3 register.
//
//*****************************************************************************
#define FLASH_USERREG3_DATA_M   0xFFFFFFFF  // User Data
#define FLASH_USERREG3_DATA_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_FMPRE8 register.
//
//*****************************************************************************
#define FLASH_FMPRE8_READ_ENABLE_M                                            \
                                0xFFFFFFFF  // Flash Read Enable
#define FLASH_FMPRE8_READ_ENABLE_S                                            \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_FMPRE9 register.
//
//*****************************************************************************
#define FLASH_FMPRE9_READ_ENABLE_M                                            \
                                0xFFFFFFFF  // Flash Read Enable
#define FLASH_FMPRE9_READ_ENABLE_S                                            \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_FMPRE10 register.
//
//*****************************************************************************
#define FLASH_FMPRE10_READ_ENABLE_M                                           \
                                0xFFFFFFFF  // Flash Read Enable
#define FLASH_FMPRE10_READ_ENABLE_S                                           \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_FMPRE11 register.
//
//*****************************************************************************
#define FLASH_FMPRE11_READ_ENABLE_M                                           \
                                0xFFFFFFFF  // Flash Read Enable
#define FLASH_FMPRE11_READ_ENABLE_S                                           \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_FMPRE12 register.
//
//*****************************************************************************
#define FLASH_FMPRE12_READ_ENABLE_M                                           \
                                0xFFFFFFFF  // Flash Read Enable
#define FLASH_FMPRE12_READ_ENABLE_S                                           \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_FMPRE13 register.
//
//*****************************************************************************
#define FLASH_FMPRE13_READ_ENABLE_M                                           \
                                0xFFFFFFFF  // Flash Read Enable
#define FLASH_FMPRE13_READ_ENABLE_S                                           \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_FMPRE14 register.
//
//*****************************************************************************
#define FLASH_FMPRE14_READ_ENABLE_M                                           \
                                0xFFFFFFFF  // Flash Read Enable
#define FLASH_FMPRE14_READ_ENABLE_S                                           \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_FMPRE15 register.
//
//*****************************************************************************
#define FLASH_FMPRE15_READ_ENABLE_M                                           \
                                0xFFFFFFFF  // Flash Read Enable
#define FLASH_FMPRE15_READ_ENABLE_S                                           \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_FMPPE8 register.
//
//*****************************************************************************
#define FLASH_FMPPE8_PROG_ENABLE_M                                            \
                                0xFFFFFFFF  // Flash Programming Enable
#define FLASH_FMPPE8_PROG_ENABLE_S                                            \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_FMPPE9 register.
//
//*****************************************************************************
#define FLASH_FMPPE9_PROG_ENABLE_M                                            \
                                0xFFFFFFFF  // Flash Programming Enable
#define FLASH_FMPPE9_PROG_ENABLE_S                                            \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_FMPPE10 register.
//
//*****************************************************************************
#define FLASH_FMPPE10_PROG_ENABLE_M                                           \
                                0xFFFFFFFF  // Flash Programming Enable
#define FLASH_FMPPE10_PROG_ENABLE_S                                           \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_FMPPE11 register.
//
//*****************************************************************************
#define FLASH_FMPPE11_PROG_ENABLE_M                                           \
                                0xFFFFFFFF  // Flash Programming Enable
#define FLASH_FMPPE11_PROG_ENABLE_S                                           \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_FMPPE12 register.
//
//*****************************************************************************
#define FLASH_FMPPE12_PROG_ENABLE_M                                           \
                                0xFFFFFFFF  // Flash Programming Enable
#define FLASH_FMPPE12_PROG_ENABLE_S                                           \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_FMPPE13 register.
//
//*****************************************************************************
#define FLASH_FMPPE13_PROG_ENABLE_M                                           \
                                0xFFFFFFFF  // Flash Programming Enable
#define FLASH_FMPPE13_PROG_ENABLE_S                                           \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_FMPPE14 register.
//
//*****************************************************************************
#define FLASH_FMPPE14_PROG_ENABLE_M                                           \
                                0xFFFFFFFF  // Flash Programming Enable
#define FLASH_FMPPE14_PROG_ENABLE_S                                           \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_FMPPE15 register.
//
//*****************************************************************************
#define FLASH_FMPPE15_PROG_ENABLE_M                                           \
                                0xFFFFFFFF  // Flash Programming Enable
#define FLASH_FMPPE15_PROG_ENABLE_S                                           \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_DID0 register.
//
//*****************************************************************************
#define SYSCTL_DID0_VER_M       0x70000000  // DID0 Version
#define SYSCTL_DID0_VER_1       0x10000000  // Second version of the DID0
                                            // register format
#define SYSCTL_DID0_CLASS_M     0x00FF0000  // Device Class
#define SYSCTL_DID0_CLASS_SNOWFLAKE                                           \
                                0x000A0000  // Tiva(TM) C Series
                                            // Snowflake-class microcontrollers
#define SYSCTL_DID0_MAJ_M       0x0000FF00  // Major Revision
#define SYSCTL_DID0_MAJ_REVA    0x00000000  // Revision A (initial device)
#define SYSCTL_DID0_MAJ_REVB    0x00000100  // Revision B (first base layer
                                            // revision)
#define SYSCTL_DID0_MAJ_REVC    0x00000200  // Revision C (second base layer
                                            // revision)
#define SYSCTL_DID0_MIN_M       0x000000FF  // Minor Revision
#define SYSCTL_DID0_MIN_0       0x00000000  // Initial device, or a major
                                            // revision update
#define SYSCTL_DID0_MIN_1       0x00000001  // First metal layer change
#define SYSCTL_DID0_MIN_2       0x00000002  // Second metal layer change

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_DID1 register.
//
//*****************************************************************************
#define SYSCTL_DID1_VER_M       0xF0000000  // DID1 Version
#define SYSCTL_DID1_VER_1       0x10000000  // Second version of the DID1
                                            // register format
#define SYSCTL_DID1_FAM_M       0x0F000000  // Family
#define SYSCTL_DID1_FAM_TIVA    0x00000000  // Tiva family of microcontollers
#define SYSCTL_DID1_PRTNO_M     0x00FF0000  // Part Number
#define SYSCTL_DID1_PRTNO_TM4C1294NCPDT                                       \
                                0x001F0000  // TM4C1294NCPDT
#define SYSCTL_DID1_PINCNT_M    0x0000E000  // Package Pin Count
#define SYSCTL_DID1_PINCNT_100  0x00004000  // 100-pin package
#define SYSCTL_DID1_PINCNT_64   0x00006000  // 64-pin package
#define SYSCTL_DID1_PINCNT_144  0x00008000  // 144-pin package
#define SYSCTL_DID1_PINCNT_157  0x0000A000  // 157-pin package
#define SYSCTL_DID1_PINCNT_128  0x0000C000  // 128-pin package
#define SYSCTL_DID1_TEMP_M      0x000000E0  // Temperature Range
#define SYSCTL_DID1_TEMP_C      0x00000000  // Commercial temperature range (0C
                                            // to 70C)
#define SYSCTL_DID1_TEMP_I      0x00000020  // Industrial temperature range
                                            // (-40C to 85C)
#define SYSCTL_DID1_TEMP_E      0x00000040  // Extended temperature range (-40C
                                            // to 105C)
#define SYSCTL_DID1_PKG_M       0x00000018  // Package Type
#define SYSCTL_DID1_PKG_SOIC    0x00000000  // SOIC package
#define SYSCTL_DID1_PKG_QFP     0x00000008  // LQFP package
#define SYSCTL_DID1_PKG_BGA     0x00000010  // BGA package
#define SYSCTL_DID1_ROHS        0x00000004  // RoHS-Compliance
#define SYSCTL_DID1_QUAL_M      0x00000003  // Qualification Status
#define SYSCTL_DID1_QUAL_ES     0x00000000  // Engineering Sample (unqualified)
#define SYSCTL_DID1_QUAL_PP     0x00000001  // Pilot Production (unqualified)
#define SYSCTL_DID1_QUAL_FQ     0x00000002  // Fully Qualified

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PTBOCTL register.
//
//*****************************************************************************
#define SYSCTL_PTBOCTL_VDDA_UBOR_M                                            \
                                0x00000300  // VDDA under BOR Event Action
#define SYSCTL_PTBOCTL_VDDA_UBOR_NONE                                         \
                                0x00000000  // No Action
#define SYSCTL_PTBOCTL_VDDA_UBOR_SYSINT                                       \
                                0x00000100  // System control interrupt
#define SYSCTL_PTBOCTL_VDDA_UBOR_NMI                                          \
                                0x00000200  // NMI
#define SYSCTL_PTBOCTL_VDDA_UBOR_RST                                          \
                                0x00000300  // Reset
#define SYSCTL_PTBOCTL_VDD_UBOR_M                                             \
                                0x00000003  // VDD under BOR Event Action
#define SYSCTL_PTBOCTL_VDD_UBOR_NONE                                          \
                                0x00000000  // No Action
#define SYSCTL_PTBOCTL_VDD_UBOR_SYSINT                                        \
                                0x00000001  // System control interrupt
#define SYSCTL_PTBOCTL_VDD_UBOR_NMI                                           \
                                0x00000002  // NMI
#define SYSCTL_PTBOCTL_VDD_UBOR_RST                                           \
                                0x00000003  // Reset

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_RIS register.
//
//*****************************************************************************
#define SYSCTL_RIS_MOSCPUPRIS   0x00000100  // MOSC Power Up Raw Interrupt
                                            // Status
#define SYSCTL_RIS_PLLLRIS      0x00000040  // PLL Lock Raw Interrupt Status
#define SYSCTL_RIS_MOFRIS       0x00000008  // Main Oscillator Fault Raw
                                            // Interrupt Status
#define SYSCTL_RIS_BORRIS       0x00000002  // Brown-Out Reset Raw Interrupt
                                            // Status

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_IMC register.
//
//*****************************************************************************
#define SYSCTL_IMC_MOSCPUPIM    0x00000100  // MOSC Power Up Interrupt Mask
#define SYSCTL_IMC_PLLLIM       0x00000040  // PLL Lock Interrupt Mask
#define SYSCTL_IMC_MOFIM        0x00000008  // Main Oscillator Fault Interrupt
                                            // Mask
#define SYSCTL_IMC_BORIM        0x00000002  // Brown-Out Reset Interrupt Mask

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_MISC register.
//
//*****************************************************************************
#define SYSCTL_MISC_MOSCPUPMIS  0x00000100  // MOSC Power Up Masked Interrupt
                                            // Status
#define SYSCTL_MISC_PLLLMIS     0x00000040  // PLL Lock Masked Interrupt Status
#define SYSCTL_MISC_MOFMIS      0x00000008  // Main Oscillator Fault Masked
                                            // Interrupt Status
#define SYSCTL_MISC_BORMIS      0x00000002  // BOR Masked Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_RESC register.
//
//*****************************************************************************
#define SYSCTL_RESC_MOSCFAIL    0x00010000  // MOSC Failure Reset
#define SYSCTL_RESC_KAPER       0x00008000  // Key Added Period Exceeded Reset
#define SYSCTL_RESC_HSSR        0x00001000  // HSSR Reset
#define SYSCTL_RESC_HIB         0x00000040  // HIB Reset
#define SYSCTL_RESC_WDT1        0x00000020  // Watchdog Timer 1 Reset
#define SYSCTL_RESC_SW          0x00000010  // Software Reset
#define SYSCTL_RESC_WDT0        0x00000008  // Watchdog Timer 0 Reset
#define SYSCTL_RESC_BOR         0x00000004  // Brown-Out Reset
#define SYSCTL_RESC_POR         0x00000002  // Power-On Reset
#define SYSCTL_RESC_EXT         0x00000001  // External Reset

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PWRTC register.
//
//*****************************************************************************
#define SYSCTL_PWRTC_VDDA_UBOR0 0x00000010  // VDDAUnder BOR0 Status
#define SYSCTL_PWRTC_VDD_UBOR0  0x00000001  // VDDUnder BOR0 Status

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_NMIC register.
//
//*****************************************************************************
#define SYSCTL_NMIC_MOSCFAIL    0x00010000  // MOSC Failure NMI
#define SYSCTL_NMIC_TAMPER      0x00000200  // Tamper Event NMI
#define SYSCTL_NMIC_WDT1        0x00000020  // Watch Dog Timer (WDT) 1 NMI
#define SYSCTL_NMIC_WDT0        0x00000008  // Watch Dog Timer (WDT) 0 NMI
#define SYSCTL_NMIC_POWER       0x00000004  // Power/Brown Out Event NMI
#define SYSCTL_NMIC_EXTERNAL    0x00000001  // External Pin NMI

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_MOSCCTL register.
//
//*****************************************************************************
#define SYSCTL_MOSCCTL_SESRC    0x00000020  // Single-Ended Source
#define SYSCTL_MOSCCTL_OSCRNG   0x00000010  // Oscillator Range
#define SYSCTL_MOSCCTL_PWRDN    0x00000008  // Power Down
#define SYSCTL_MOSCCTL_NOXTAL   0x00000004  // No Crystal Connected
#define SYSCTL_MOSCCTL_MOSCIM   0x00000002  // MOSC Failure Action
#define SYSCTL_MOSCCTL_CVAL     0x00000001  // Clock Validation for MOSC

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_RSCLKCFG
// register.
//
//*****************************************************************************
#define SYSCTL_RSCLKCFG_MEMTIMU 0x80000000  // Memory Timing Register Update
#define SYSCTL_RSCLKCFG_NEWFREQ 0x40000000  // New PLLFREQ Accept
#define SYSCTL_RSCLKCFG_ACG     0x20000000  // Auto Clock Gating Enable
#define SYSCTL_RSCLKCFG_USEPLL  0x10000000  // Use PLL
#define SYSCTL_RSCLKCFG_PLLSRC_M                                              \
                                0x0F000000  // PLL Source
#define SYSCTL_RSCLKCFG_PLLSRC_PIOSC                                          \
                                0x00000000  // PIOSC is PLL input clock source
#define SYSCTL_RSCLKCFG_PLLSRC_MOSC                                           \
                                0x03000000  // MOSC is PLL input clock source
#define SYSCTL_RSCLKCFG_OSCSRC_M                                              \
                                0x00F00000  // Oscillator Source
#define SYSCTL_RSCLKCFG_OSCSRC_PIOSC                                          \
                                0x00000000  // PIOSC is oscillator source
#define SYSCTL_RSCLKCFG_OSCSRC_LFIOSC                                         \
                                0x00200000  // LFIOSC is oscillator source
#define SYSCTL_RSCLKCFG_OSCSRC_MOSC                                           \
                                0x00300000  // MOSC is oscillator source
#define SYSCTL_RSCLKCFG_OSCSRC_RTC                                            \
                                0x00400000  // RTC is oscillator source
#define SYSCTL_RSCLKCFG_OSYSDIV_M                                             \
                                0x000FFC00  // Oscillator System Clock Divisor
#define SYSCTL_RSCLKCFG_PSYSDIV_M                                             \
                                0x000003FF  // PLL System Clock Divisor
#define SYSCTL_RSCLKCFG_OSYSDIV_S                                             \
                                10
#define SYSCTL_RSCLKCFG_PSYSDIV_S                                             \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_MEMTIM0 register.
//
//*****************************************************************************
#define SYSCTL_MEMTIM0_EBCHT_M  0x03C00000  // EEPROM Clock High Time
#define SYSCTL_MEMTIM0_EBCHT_0_5                                              \
                                0x00000000  // System clock high
#define SYSCTL_MEMTIM0_EBCHT_1  0x00400000  // 1 system clock period
#define SYSCTL_MEMTIM0_EBCHT_1_5                                              \
                                0x00800000  // 1.5 system clock periods
#define SYSCTL_MEMTIM0_EBCHT_2  0x00C00000  // 2 system clock periods
#define SYSCTL_MEMTIM0_EBCHT_2_5                                              \
                                0x01000000  // 2.5 system clock periods
#define SYSCTL_MEMTIM0_EBCHT_3  0x01400000  // 3 system clock periods
#define SYSCTL_MEMTIM0_EBCHT_3_5                                              \
                                0x01800000  // 3.5 system clock periods
#define SYSCTL_MEMTIM0_EBCHT_4  0x01C00000  // 4 system clock periods
#define SYSCTL_MEMTIM0_EBCHT_4_5                                              \
                                0x02000000  // 4.5 system clock periods
#define SYSCTL_MEMTIM0_EBCE     0x00200000  // EEPROM Bank Clock Edge
#define SYSCTL_MEMTIM0_EWS_M    0x000F0000  // EEPROM Wait State
#define SYSCTL_MEMTIM0_FBCHT_M  0x000003C0  // Flash Bank Clock High Time
#define SYSCTL_MEMTIM0_FBCHT_0_5                                              \
                                0x00000000  // System clock high
#define SYSCTL_MEMTIM0_FBCHT_1  0x00000040  // 1 system clock period
#define SYSCTL_MEMTIM0_FBCHT_1_5                                              \
                                0x00000080  // 1.5 system clock periods
#define SYSCTL_MEMTIM0_FBCHT_2  0x000000C0  // 2 system clock periods
#define SYSCTL_MEMTIM0_FBCHT_2_5                                              \
                                0x00000100  // 2.5 system clock periods
#define SYSCTL_MEMTIM0_FBCHT_3  0x00000140  // 3 system clock periods
#define SYSCTL_MEMTIM0_FBCHT_3_5                                              \
                                0x00000180  // 3.5 system clock periods
#define SYSCTL_MEMTIM0_FBCHT_4  0x000001C0  // 4 system clock periods
#define SYSCTL_MEMTIM0_FBCHT_4_5                                              \
                                0x00000200  // 4.5 system clock periods
#define SYSCTL_MEMTIM0_FBCE     0x00000020  // Flash Bank Clock Edge
#define SYSCTL_MEMTIM0_FWS_M    0x0000000F  // Flash Wait State
#define SYSCTL_MEMTIM0_EWS_S    16
#define SYSCTL_MEMTIM0_FWS_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_DSMEMTIM0
// register.
//
//*****************************************************************************
#define SYSCTL_DSMEMTIM0_DSEBCHT_M                                            \
                                0x03C00000  // Deep Sleep EEPROM Clock High
                                            // Time
#define SYSCTL_DSMEMTIM0_DSEBCHT_0_5                                          \
                                0x00000000  // System clock high
#define SYSCTL_DSMEMTIM0_DSEBCHT_1                                            \
                                0x00400000  // 1 system clock period
#define SYSCTL_DSMEMTIM0_DSEBCHT_1_5                                          \
                                0x00800000  // 1.5 system clock periods
#define SYSCTL_DSMEMTIM0_DSEBCHT_2                                            \
                                0x00C00000  // 2 system clock periods
#define SYSCTL_DSMEMTIM0_DSEBCHT_2_5                                          \
                                0x01000000  // 2.5 system clock periods
#define SYSCTL_DSMEMTIM0_DSEBCHT_3                                            \
                                0x01400000  // 3 system clock periods
#define SYSCTL_DSMEMTIM0_DSEBCHT_3_5                                          \
                                0x01800000  // 3.5 system clock periods
#define SYSCTL_DSMEMTIM0_DSEBCHT_4                                            \
                                0x01C00000  // 4 system clock periods
#define SYSCTL_DSMEMTIM0_DSEBCHT_4_5                                          \
                                0x02000000  // 4.5 system clock periods
#define SYSCTL_DSMEMTIM0_DSEBCE 0x00200000  // Deep Sleep EEPROM Bank Clock
                                            // Edge
#define SYSCTL_DSMEMTIM0_EBO    0x00100000  // Deep Sleep EEPROM Bank Output
#define SYSCTL_DSMEMTIM0_EWS_M  0x000F0000  // Deep Sleep EEPROM Wait State
#define SYSCTL_DSMEMTIM0_DSFBCHT_M                                            \
                                0x000003C0  // Deep Sleep Flash Bank Clock High
                                            // Time
#define SYSCTL_DSMEMTIM0_DSFBCHT_0_5                                          \
                                0x00000000  // System clock high
#define SYSCTL_DSMEMTIM0_DSFBCHT_1                                            \
                                0x00000040  // 1 system clock period
#define SYSCTL_DSMEMTIM0_DSFBCHT_1_5                                          \
                                0x00000080  // 1.5 system clock periods
#define SYSCTL_DSMEMTIM0_DSFBCHT_2                                            \
                                0x000000C0  // 2 system clock periods
#define SYSCTL_DSMEMTIM0_DSFBCHT_2_5                                          \
                                0x00000100  // 2.5 system clock periods
#define SYSCTL_DSMEMTIM0_DSFBCHT_3                                            \
                                0x00000140  // 3 system clock periods
#define SYSCTL_DSMEMTIM0_DSFBCHT_3_5                                          \
                                0x00000180  // 3.5 system clock periods
#define SYSCTL_DSMEMTIM0_DSFBCHT_4                                            \
                                0x000001C0  // 4 system clock periods
#define SYSCTL_DSMEMTIM0_DSFBCHT_4_5                                          \
                                0x00000200  // 4.5 system clock periods
#define SYSCTL_DSMEMTIM0_DSFBCE 0x00000020  // Deep Sleep Flash Bank Clock Edge
#define SYSCTL_DSMEMTIM0_DSFBO  0x00000010  // Deep Sleep Flash Bank Output
#define SYSCTL_DSMEMTIM0_DSFWS_M                                              \
                                0x0000000F  // Deep Sleep Flash Wait State
#define SYSCTL_DSMEMTIM0_EWS_S  16
#define SYSCTL_DSMEMTIM0_DSFWS_S                                              \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_ALTCLKCFG
// register.
//
//*****************************************************************************
#define SYSCTL_ALTCLKCFG_ALTCLK_M                                             \
                                0x0000000F  // Alternate Clock Source
#define SYSCTL_ALTCLKCFG_ALTCLK_PIOSC                                         \
                                0x00000000  // PIOSC
#define SYSCTL_ALTCLKCFG_ALTCLK_PIOSC48                                       \
                                0x00000001  // PIOSC48
#define SYSCTL_ALTCLKCFG_ALTCLK_LFIOSC                                        \
                                0x00000002  // LFIOSC
#define SYSCTL_ALTCLKCFG_ALTCLK_RTCOSC                                        \
                                0x00000003  // Hibernation Module Real-time
                                            // clock output (RTCOSC)
#define SYSCTL_ALTCLKCFG_ALTCLK_HIBRTC                                        \
                                0x00000004  // Hibernation Module RTCOSC

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_DSCLKCFG
// register.
//
//*****************************************************************************
#define SYSCTL_DSCLKCFG_PIOSCPD 0x80000000  // PIOSC Power Down
#define SYSCTL_DSCLKCFG_MOSCDPD 0x40000000  // MOSC Disable Power Down
#define SYSCTL_DSCLKCFG_DSOSCSRC_M                                            \
                                0x00F00000  // Deep Sleep
#define SYSCTL_DSCLKCFG_DSOSCSRC_PIOSC                                        \
                                0x00000000  // PIOSC
#define SYSCTL_DSCLKCFG_DSOSCSRC_LFIOSC                                       \
                                0x00200000  // LFIOSC
#define SYSCTL_DSCLKCFG_DSOSCSRC_MOSC                                         \
                                0x00300000  // MOSC
#define SYSCTL_DSCLKCFG_DSOSCSRC_RTC                                          \
                                0x00400000  // RTC
#define SYSCTL_DSCLKCFG_DSSYSDIV_M                                            \
                                0x000003FF  // Deep Sleep Clock Divisor
#define SYSCTL_DSCLKCFG_DSSYSDIV_S                                            \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_DIVSCLK register.
//
//*****************************************************************************
#define SYSCTL_DIVSCLK_EN       0x80000000  // Enable
#define SYSCTL_DIVSCLK_SRC_M    0x00030000  // Clock Source
#define SYSCTL_DIVSCLK_SRC_SYSCLK                                             \
                                0x00000000  // System Clock
#define SYSCTL_DIVSCLK_SRC_PIOSC                                              \
                                0x00010000  // PIOSC
#define SYSCTL_DIVSCLK_SRC_MOSC 0x00020000  // MOSC
#define SYSCTL_DIVSCLK_DIV_M    0x000000FF  // Divisor Value
#define SYSCTL_DIVSCLK_DIV_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_SYSPROP register.
//
//*****************************************************************************
#define SYSCTL_SYSPROP_FPU      0x00000001  // FPU Present

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PIOSCCAL
// register.
//
//*****************************************************************************
#define SYSCTL_PIOSCCAL_UTEN    0x80000000  // Use User Trim Value
#define SYSCTL_PIOSCCAL_CAL     0x00000200  // Start Calibration
#define SYSCTL_PIOSCCAL_UPDATE  0x00000100  // Update Trim
#define SYSCTL_PIOSCCAL_UT_M    0x0000007F  // User Trim Value
#define SYSCTL_PIOSCCAL_UT_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PIOSCSTAT
// register.
//
//*****************************************************************************
#define SYSCTL_PIOSCSTAT_DT_M   0x007F0000  // Default Trim Value
#define SYSCTL_PIOSCSTAT_CR_M   0x00000300  // Calibration Result
#define SYSCTL_PIOSCSTAT_CRNONE 0x00000000  // Calibration has not been
                                            // attempted
#define SYSCTL_PIOSCSTAT_CRPASS 0x00000100  // The last calibration operation
                                            // completed to meet 1% accuracy
#define SYSCTL_PIOSCSTAT_CRFAIL 0x00000200  // The last calibration operation
                                            // failed to meet 1% accuracy
#define SYSCTL_PIOSCSTAT_CT_M   0x0000007F  // Calibration Trim Value
#define SYSCTL_PIOSCSTAT_DT_S   16
#define SYSCTL_PIOSCSTAT_CT_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PLLFREQ0
// register.
//
//*****************************************************************************
#define SYSCTL_PLLFREQ0_PLLPWR  0x00800000  // PLL Power
#define SYSCTL_PLLFREQ0_MFRAC_M 0x000FFC00  // PLL M Fractional Value
#define SYSCTL_PLLFREQ0_MINT_M  0x000003FF  // PLL M Integer Value
#define SYSCTL_PLLFREQ0_MFRAC_S 10
#define SYSCTL_PLLFREQ0_MINT_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PLLFREQ1
// register.
//
//*****************************************************************************
#define SYSCTL_PLLFREQ1_Q_M     0x00001F00  // PLL Q Value
#define SYSCTL_PLLFREQ1_N_M     0x0000001F  // PLL N Value
#define SYSCTL_PLLFREQ1_Q_S     8
#define SYSCTL_PLLFREQ1_N_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PLLSTAT register.
//
//*****************************************************************************
#define SYSCTL_PLLSTAT_LOCK     0x00000001  // PLL Lock

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_SLPPWRCFG
// register.
//
//*****************************************************************************
#define SYSCTL_SLPPWRCFG_FLASHPM_M                                            \
                                0x00000030  // Flash Power Modes
#define SYSCTL_SLPPWRCFG_FLASHPM_NRM                                          \
                                0x00000000  // Active Mode
#define SYSCTL_SLPPWRCFG_FLASHPM_SLP                                          \
                                0x00000020  // Low Power Mode
#define SYSCTL_SLPPWRCFG_SRAMPM_M                                             \
                                0x00000003  // SRAM Power Modes
#define SYSCTL_SLPPWRCFG_SRAMPM_NRM                                           \
                                0x00000000  // Active Mode
#define SYSCTL_SLPPWRCFG_SRAMPM_SBY                                           \
                                0x00000001  // Standby Mode
#define SYSCTL_SLPPWRCFG_SRAMPM_LP                                            \
                                0x00000003  // Low Power Mode

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_DSLPPWRCFG
// register.
//
//*****************************************************************************
#define SYSCTL_DSLPPWRCFG_LDOSM 0x00000200  // LDO Sleep Mode
#define SYSCTL_DSLPPWRCFG_TSPD  0x00000100  // Temperature Sense Power Down
#define SYSCTL_DSLPPWRCFG_FLASHPM_M                                           \
                                0x00000030  // Flash Power Modes
#define SYSCTL_DSLPPWRCFG_FLASHPM_NRM                                         \
                                0x00000000  // Active Mode
#define SYSCTL_DSLPPWRCFG_FLASHPM_SLP                                         \
                                0x00000020  // Low Power Mode
#define SYSCTL_DSLPPWRCFG_SRAMPM_M                                            \
                                0x00000003  // SRAM Power Modes
#define SYSCTL_DSLPPWRCFG_SRAMPM_NRM                                          \
                                0x00000000  // Active Mode
#define SYSCTL_DSLPPWRCFG_SRAMPM_SBY                                          \
                                0x00000001  // Standby Mode
#define SYSCTL_DSLPPWRCFG_SRAMPM_LP                                           \
                                0x00000003  // Low Power Mode

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_NVMSTAT register.
//
//*****************************************************************************
#define SYSCTL_NVMSTAT_FWB      0x00000001  // 32 Word Flash Write Buffer
                                            // Active

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_LDODPCTL
// register.
//
//*****************************************************************************
#define SYSCTL_LDODPCTL_VADJEN  0x80000000  // Voltage Adjust Enable
#define SYSCTL_LDODPCTL_VLDO_M  0x000000FF  // LDO Output Voltage
#define SYSCTL_LDODPCTL_VLDO_0_90V                                            \
                                0x00000012  // 0.90 V
#define SYSCTL_LDODPCTL_VLDO_0_95V                                            \
                                0x00000013  // 0.95 V
#define SYSCTL_LDODPCTL_VLDO_1_00V                                            \
                                0x00000014  // 1.00 V
#define SYSCTL_LDODPCTL_VLDO_1_05V                                            \
                                0x00000015  // 1.05 V
#define SYSCTL_LDODPCTL_VLDO_1_10V                                            \
                                0x00000016  // 1.10 V
#define SYSCTL_LDODPCTL_VLDO_1_15V                                            \
                                0x00000017  // 1.15 V
#define SYSCTL_LDODPCTL_VLDO_1_20V                                            \
                                0x00000018  // 1.20 V
#define SYSCTL_LDODPCTL_VLDO_1_25V                                            \
                                0x00000019  // 1.25 V
#define SYSCTL_LDODPCTL_VLDO_1_30V                                            \
                                0x0000001A  // 1.30 V
#define SYSCTL_LDODPCTL_VLDO_1_35V                                            \
                                0x0000001B  // 1.35 V

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_RESBEHAVCTL
// register.
//
//*****************************************************************************
#define SYSCTL_RESBEHAVCTL_WDOG1_M                                            \
                                0x000000C0  // Defines operation of Watchdog 1
                                            // Reset
#define SYSCTL_RESBEHAVCTL_WDOG1_SYSRST                                       \
                                0x00000080  // Watchdog 1 issues system reset.
                                            // Application starts within 10usec
#define SYSCTL_RESBEHAVCTL_WDOG1_POR                                          \
                                0x000000C0  // Watchdog 1 issues full POR
                                            // sequence. Application starts <
                                            // 500us after deassertion
                                            // (Default)
#define SYSCTL_RESBEHAVCTL_WDOG0_M                                            \
                                0x00000030  // Defines operation of Watchdog 0
                                            // Reset
#define SYSCTL_RESBEHAVCTL_WDOG0_SYSRST                                       \
                                0x00000020  // Watchdog 0 issues system reset.
                                            // Application starts within 10usec
#define SYSCTL_RESBEHAVCTL_WDOG0_POR                                          \
                                0x00000030  // Watchdog 0 issues full POR
                                            // sequence. Application starts <
                                            // 500us after deassertion
                                            // (Default)
#define SYSCTL_RESBEHAVCTL_BOR_M                                              \
                                0x0000000C  // Defines operation of BOR when
                                            // USER has defined the BOR
                                            // operation to be a reset
#define SYSCTL_RESBEHAVCTL_BOR_SYSRST                                         \
                                0x00000008  // Brown Out Reset issues system
                                            // reset. Application starts within
                                            // 10usec
#define SYSCTL_RESBEHAVCTL_BOR_POR                                            \
                                0x0000000C  // Brown Out Reset issues full POR
                                            // sequence. Application starts <
                                            // 500us after deassertion
                                            // (Default)
#define SYSCTL_RESBEHAVCTL_EXTRES_M                                           \
                                0x00000003  // External Resetn Pin Operation
#define SYSCTL_RESBEHAVCTL_EXTRES_SYSRST                                      \
                                0x00000002  // External Resetn issues system
                                            // reset. Application starts within
                                            // 10usec
#define SYSCTL_RESBEHAVCTL_EXTRES_POR                                         \
                                0x00000003  // External Resetn issues full POR
                                            // sequence. Application starts <
                                            // 500us after deassertion
                                            // (Default) Application starts <
                                            // 500us after deassertion
                                            // (Default)

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_HSSR register.
//
//*****************************************************************************
#define SYSCTL_HSSR_KEY_M       0xFF000000  // Write Key
#define SYSCTL_HSSR_CDOFF_M     0x00FFFFFF  // Command Descriptor Pointer
#define SYSCTL_HSSR_KEY_S       24
#define SYSCTL_HSSR_CDOFF_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_USBPDS register.
//
//*****************************************************************************
#define SYSCTL_USBPDS_MEMSTAT_M 0x0000000C  // Memory Array Power Status
#define SYSCTL_USBPDS_MEMSTAT_OFF                                             \
                                0x00000000  // Array OFF
#define SYSCTL_USBPDS_MEMSTAT_RETAIN                                          \
                                0x00000004  // SRAM Retention
#define SYSCTL_USBPDS_MEMSTAT_ON                                              \
                                0x0000000C  // Array On
#define SYSCTL_USBPDS_PWRSTAT_M 0x00000003  // Power Domain Status
#define SYSCTL_USBPDS_PWRSTAT_OFF                                             \
                                0x00000000  // OFF
#define SYSCTL_USBPDS_PWRSTAT_ON                                              \
                                0x00000003  // ON

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_USBMPC register.
//
//*****************************************************************************
#define SYSCTL_USBMPC_PWRCTL_M  0x00000003  // Memory Array Power Control
#define SYSCTL_USBMPC_PWRCTL_OFF                                              \
                                0x00000000  // Array OFF
#define SYSCTL_USBMPC_PWRCTL_RETAIN                                           \
                                0x00000001  // SRAM Retention
#define SYSCTL_USBMPC_PWRCTL_ON 0x00000003  // Array On

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_EMACPDS register.
//
//*****************************************************************************
#define SYSCTL_EMACPDS_MEMSTAT_M                                              \
                                0x0000000C  // Memory Array Power Status
#define SYSCTL_EMACPDS_MEMSTAT_OFF                                            \
                                0x00000000  // Array OFF
#define SYSCTL_EMACPDS_MEMSTAT_ON                                             \
                                0x0000000C  // Array On
#define SYSCTL_EMACPDS_PWRSTAT_M                                              \
                                0x00000003  // Power Domain Status
#define SYSCTL_EMACPDS_PWRSTAT_OFF                                            \
                                0x00000000  // OFF
#define SYSCTL_EMACPDS_PWRSTAT_ON                                             \
                                0x00000003  // ON

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_EMACMPC register.
//
//*****************************************************************************
#define SYSCTL_EMACMPC_PWRCTL_M 0x00000003  // Memory Array Power Control
#define SYSCTL_EMACMPC_PWRCTL_OFF                                             \
                                0x00000000  // Array OFF
#define SYSCTL_EMACMPC_PWRCTL_ON                                              \
                                0x00000003  // Array On

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PPWD register.
//
//*****************************************************************************
#define SYSCTL_PPWD_P1          0x00000002  // Watchdog Timer 1 Present
#define SYSCTL_PPWD_P0          0x00000001  // Watchdog Timer 0 Present

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PPTIMER register.
//
//*****************************************************************************
#define SYSCTL_PPTIMER_P7       0x00000080  // 16/32-Bit General-Purpose Timer
                                            // 7 Present
#define SYSCTL_PPTIMER_P6       0x00000040  // 16/32-Bit General-Purpose Timer
                                            // 6 Present
#define SYSCTL_PPTIMER_P5       0x00000020  // Timer 5 Present
#define SYSCTL_PPTIMER_P4       0x00000010  // Timer 4 Present
#define SYSCTL_PPTIMER_P3       0x00000008  // Timer 3 Present
#define SYSCTL_PPTIMER_P2       0x00000004  // Timer 2 Present
#define SYSCTL_PPTIMER_P1       0x00000002  // Timer 1 Present
#define SYSCTL_PPTIMER_P0       0x00000001  // Timer 0 Present

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PPGPIO register.
//
//*****************************************************************************
#define SYSCTL_PPGPIO_P14       0x00004000  // GPIO Port Q Present
#define SYSCTL_PPGPIO_P13       0x00002000  // GPIO Port P Present
#define SYSCTL_PPGPIO_P12       0x00001000  // GPIO Port N Present
#define SYSCTL_PPGPIO_P11       0x00000800  // GPIO Port M Present
#define SYSCTL_PPGPIO_P10       0x00000400  // GPIO Port L Present
#define SYSCTL_PPGPIO_P9        0x00000200  // GPIO Port K Present
#define SYSCTL_PPGPIO_P8        0x00000100  // GPIO Port J Present
#define SYSCTL_PPGPIO_P7        0x00000080  // GPIO Port H Present
#define SYSCTL_PPGPIO_P6        0x00000040  // GPIO Port G Present
#define SYSCTL_PPGPIO_P5        0x00000020  // GPIO Port F Present
#define SYSCTL_PPGPIO_P4        0x00000010  // GPIO Port E Present
#define SYSCTL_PPGPIO_P3        0x00000008  // GPIO Port D Present
#define SYSCTL_PPGPIO_P2        0x00000004  // GPIO Port C Present
#define SYSCTL_PPGPIO_P1        0x00000002  // GPIO Port B Present
#define SYSCTL_PPGPIO_P0        0x00000001  // GPIO Port A Present

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PPDMA register.
//
//*****************************************************************************
#define SYSCTL_PPDMA_P0         0x00000001  // uDMA Module Present

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PPEPI register.
//
//*****************************************************************************
#define SYSCTL_PPEPI_P0         0x00000001  // EPI Module Present

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PPHIB register.
//
//*****************************************************************************
#define SYSCTL_PPHIB_P0         0x00000001  // Hibernation Module Present

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PPUART register.
//
//*****************************************************************************
#define SYSCTL_PPUART_P7        0x00000080  // UART Module 7 Present
#define SYSCTL_PPUART_P6        0x00000040  // UART Module 6 Present
#define SYSCTL_PPUART_P5        0x00000020  // UART Module 5 Present
#define SYSCTL_PPUART_P4        0x00000010  // UART Module 4 Present
#define SYSCTL_PPUART_P3        0x00000008  // UART Module 3 Present
#define SYSCTL_PPUART_P2        0x00000004  // UART Module 2 Present
#define SYSCTL_PPUART_P1        0x00000002  // UART Module 1 Present
#define SYSCTL_PPUART_P0        0x00000001  // UART Module 0 Present

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PPSSI register.
//
//*****************************************************************************
#define SYSCTL_PPSSI_P3         0x00000008  // SSI Module 3 Present
#define SYSCTL_PPSSI_P2         0x00000004  // SSI Module 2 Present
#define SYSCTL_PPSSI_P1         0x00000002  // SSI Module 1 Present
#define SYSCTL_PPSSI_P0         0x00000001  // SSI Module 0 Present

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PPI2C register.
//
//*****************************************************************************
#define SYSCTL_PPI2C_P9         0x00000200  // I2C Module 9 Present
#define SYSCTL_PPI2C_P8         0x00000100  // I2C Module 8 Present
#define SYSCTL_PPI2C_P7         0x00000080  // I2C Module 7 Present
#define SYSCTL_PPI2C_P6         0x00000040  // I2C Module 6 Present
#define SYSCTL_PPI2C_P5         0x00000020  // I2C Module 5 Present
#define SYSCTL_PPI2C_P4         0x00000010  // I2C Module 4 Present
#define SYSCTL_PPI2C_P3         0x00000008  // I2C Module 3 Present
#define SYSCTL_PPI2C_P2         0x00000004  // I2C Module 2 Present
#define SYSCTL_PPI2C_P1         0x00000002  // I2C Module 1 Present
#define SYSCTL_PPI2C_P0         0x00000001  // I2C Module 0 Present

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PPUSB register.
//
//*****************************************************************************
#define SYSCTL_PPUSB_P0         0x00000001  // USB Module Present

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PPEPHY register.
//
//*****************************************************************************
#define SYSCTL_PPEPHY_P0        0x00000001  // Ethernet PHY Module Present

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PPCAN register.
//
//*****************************************************************************
#define SYSCTL_PPCAN_P1         0x00000002  // CAN Module 1 Present
#define SYSCTL_PPCAN_P0         0x00000001  // CAN Module 0 Present

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PPADC register.
//
//*****************************************************************************
#define SYSCTL_PPADC_P1         0x00000002  // ADC Module 1 Present
#define SYSCTL_PPADC_P0         0x00000001  // ADC Module 0 Present

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PPACMP register.
//
//*****************************************************************************
#define SYSCTL_PPACMP_P0        0x00000001  // Analog Comparator Module Present

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PPPWM register.
//
//*****************************************************************************
#define SYSCTL_PPPWM_P0         0x00000001  // PWM Module 0 Present

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PPQEI register.
//
//*****************************************************************************
#define SYSCTL_PPQEI_P0         0x00000001  // QEI Module 0 Present

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PPLPC register.
//
//*****************************************************************************
#define SYSCTL_PPLPC_P0         0x00000001  // LPC Module Present

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PPPECI register.
//
//*****************************************************************************
#define SYSCTL_PPPECI_P0        0x00000001  // PECI Module Present

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PPFAN register.
//
//*****************************************************************************
#define SYSCTL_PPFAN_P0         0x00000001  // FAN Module Present

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PPEEPROM
// register.
//
//*****************************************************************************
#define SYSCTL_PPEEPROM_P0      0x00000001  // EEPROM Module Present

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PPWTIMER
// register.
//
//*****************************************************************************
#define SYSCTL_PPWTIMER_P0      0x00000001  // Wide Timer 0 Present

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PPRTS register.
//
//*****************************************************************************
#define SYSCTL_PPRTS_P0         0x00000001  // RTS Module Present

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PPCCM register.
//
//*****************************************************************************
#define SYSCTL_PPCCM_P0         0x00000001  // CRC and Cryptographic Modules
                                            // Present

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PPLCD register.
//
//*****************************************************************************
#define SYSCTL_PPLCD_P0         0x00000001  // LCD Module Present

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PPOWIRE register.
//
//*****************************************************************************
#define SYSCTL_PPOWIRE_P0       0x00000001  // One-Wire Module Present

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PPEMAC register.
//
//*****************************************************************************
#define SYSCTL_PPEMAC_P0        0x00000001  // Ethernet Controller Module
                                            // Present

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PPHIM register.
//
//*****************************************************************************
#define SYSCTL_PPHIM_P0         0x00000001  // HIM Module Present

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_SRWD register.
//
//*****************************************************************************
#define SYSCTL_SRWD_R1          0x00000002  // Watchdog Timer 1 Software Reset
#define SYSCTL_SRWD_R0          0x00000001  // Watchdog Timer 0 Software Reset

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_SRTIMER register.
//
//*****************************************************************************
#define SYSCTL_SRTIMER_R7       0x00000080  // 16/32-Bit General-Purpose Timer
                                            // 7 Software Reset
#define SYSCTL_SRTIMER_R6       0x00000040  // 16/32-Bit General-Purpose Timer
                                            // 6 Software Reset
#define SYSCTL_SRTIMER_R5       0x00000020  // Timer 5 Software Reset
#define SYSCTL_SRTIMER_R4       0x00000010  // Timer 4 Software Reset
#define SYSCTL_SRTIMER_R3       0x00000008  // Timer 3 Software Reset
#define SYSCTL_SRTIMER_R2       0x00000004  // Timer 2 Software Reset
#define SYSCTL_SRTIMER_R1       0x00000002  // Timer 1 Software Reset
#define SYSCTL_SRTIMER_R0       0x00000001  // Timer 0 Software Reset

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_SRGPIO register.
//
//*****************************************************************************
#define SYSCTL_SRGPIO_R14       0x00004000  // GPIO Port Q Software Reset
#define SYSCTL_SRGPIO_R13       0x00002000  // GPIO Port P Software Reset
#define SYSCTL_SRGPIO_R12       0x00001000  // GPIO Port N Software Reset
#define SYSCTL_SRGPIO_R11       0x00000800  // GPIO Port M Software Reset
#define SYSCTL_SRGPIO_R10       0x00000400  // GPIO Port L Software Reset
#define SYSCTL_SRGPIO_R9        0x00000200  // GPIO Port K Software Reset
#define SYSCTL_SRGPIO_R8        0x00000100  // GPIO Port J Software Reset
#define SYSCTL_SRGPIO_R7        0x00000080  // GPIO Port H Software Reset
#define SYSCTL_SRGPIO_R6        0x00000040  // GPIO Port G Software Reset
#define SYSCTL_SRGPIO_R5        0x00000020  // GPIO Port F Software Reset
#define SYSCTL_SRGPIO_R4        0x00000010  // GPIO Port E Software Reset
#define SYSCTL_SRGPIO_R3        0x00000008  // GPIO Port D Software Reset
#define SYSCTL_SRGPIO_R2        0x00000004  // GPIO Port C Software Reset
#define SYSCTL_SRGPIO_R1        0x00000002  // GPIO Port B Software Reset
#define SYSCTL_SRGPIO_R0        0x00000001  // GPIO Port A Software Reset

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_SRDMA register.
//
//*****************************************************************************
#define SYSCTL_SRDMA_R0         0x00000001  // uDMA Module Software Reset

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_SREPI register.
//
//*****************************************************************************
#define SYSCTL_SREPI_R0         0x00000001  // EPI Module Software Reset

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_SRHIB register.
//
//*****************************************************************************
#define SYSCTL_SRHIB_R0         0x00000001  // Hibernation Module Software
                                            // Reset

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_SRUART register.
//
//*****************************************************************************
#define SYSCTL_SRUART_R7        0x00000080  // UART Module 7 Software Reset
#define SYSCTL_SRUART_R6        0x00000040  // UART Module 6 Software Reset
#define SYSCTL_SRUART_R5        0x00000020  // UART Module 5 Software Reset
#define SYSCTL_SRUART_R4        0x00000010  // UART Module 4 Software Reset
#define SYSCTL_SRUART_R3        0x00000008  // UART Module 3 Software Reset
#define SYSCTL_SRUART_R2        0x00000004  // UART Module 2 Software Reset
#define SYSCTL_SRUART_R1        0x00000002  // UART Module 1 Software Reset
#define SYSCTL_SRUART_R0        0x00000001  // UART Module 0 Software Reset

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_SRSSI register.
//
//*****************************************************************************
#define SYSCTL_SRSSI_R3         0x00000008  // SSI Module 3 Software Reset
#define SYSCTL_SRSSI_R2         0x00000004  // SSI Module 2 Software Reset
#define SYSCTL_SRSSI_R1         0x00000002  // SSI Module 1 Software Reset
#define SYSCTL_SRSSI_R0         0x00000001  // SSI Module 0 Software Reset

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_SRI2C register.
//
//*****************************************************************************
#define SYSCTL_SRI2C_R9         0x00000200  // I2C Module 9 Software Reset
#define SYSCTL_SRI2C_R8         0x00000100  // I2C Module 8 Software Reset
#define SYSCTL_SRI2C_R7         0x00000080  // I2C Module 7 Software Reset
#define SYSCTL_SRI2C_R6         0x00000040  // I2C Module 6 Software Reset
#define SYSCTL_SRI2C_R5         0x00000020  // I2C Module 5 Software Reset
#define SYSCTL_SRI2C_R4         0x00000010  // I2C Module 4 Software Reset
#define SYSCTL_SRI2C_R3         0x00000008  // I2C Module 3 Software Reset
#define SYSCTL_SRI2C_R2         0x00000004  // I2C Module 2 Software Reset
#define SYSCTL_SRI2C_R1         0x00000002  // I2C Module 1 Software Reset
#define SYSCTL_SRI2C_R0         0x00000001  // I2C Module 0 Software Reset

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_SRUSB register.
//
//*****************************************************************************
#define SYSCTL_SRUSB_R0         0x00000001  // USB Module Software Reset

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_SREPHY register.
//
//*****************************************************************************
#define SYSCTL_SREPHY_R0        0x00000001  // Ethernet PHY Module Software
                                            // Reset

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_SRCAN register.
//
//*****************************************************************************
#define SYSCTL_SRCAN_R1         0x00000002  // CAN Module 1 Software Reset
#define SYSCTL_SRCAN_R0         0x00000001  // CAN Module 0 Software Reset

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_SRADC register.
//
//*****************************************************************************
#define SYSCTL_SRADC_R1         0x00000002  // ADC Module 1 Software Reset
#define SYSCTL_SRADC_R0         0x00000001  // ADC Module 0 Software Reset

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_SRACMP register.
//
//*****************************************************************************
#define SYSCTL_SRACMP_R0        0x00000001  // Analog Comparator Module 0
                                            // Software Reset

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_SRPWM register.
//
//*****************************************************************************
#define SYSCTL_SRPWM_R0         0x00000001  // PWM Module 0 Software Reset

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_SRQEI register.
//
//*****************************************************************************
#define SYSCTL_SRQEI_R0         0x00000001  // QEI Module 0 Software Reset

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_SREEPROM
// register.
//
//*****************************************************************************
#define SYSCTL_SREEPROM_R0      0x00000001  // EEPROM Module Software Reset

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_SRCCM register.
//
//*****************************************************************************
#define SYSCTL_SRCCM_R0         0x00000001  // CRC and Cryptographic Modules
                                            // Software Reset

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_SREMAC register.
//
//*****************************************************************************
#define SYSCTL_SREMAC_R0        0x00000001  // Ethernet Controller MAC Module 0
                                            // Software Reset

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_RCGCWD register.
//
//*****************************************************************************
#define SYSCTL_RCGCWD_R1        0x00000002  // Watchdog Timer 1 Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCWD_R0        0x00000001  // Watchdog Timer 0 Run Mode Clock
                                            // Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_RCGCTIMER
// register.
//
//*****************************************************************************
#define SYSCTL_RCGCTIMER_R7     0x00000080  // 16/32-Bit General-Purpose Timer
                                            // 7 Run Mode Clock Gating Control
#define SYSCTL_RCGCTIMER_R6     0x00000040  // 16/32-Bit General-Purpose Timer
                                            // 6 Run Mode Clock Gating Control
#define SYSCTL_RCGCTIMER_R5     0x00000020  // Timer 5 Run Mode Clock Gating
                                            // Control
#define SYSCTL_RCGCTIMER_R4     0x00000010  // Timer 4 Run Mode Clock Gating
                                            // Control
#define SYSCTL_RCGCTIMER_R3     0x00000008  // Timer 3 Run Mode Clock Gating
                                            // Control
#define SYSCTL_RCGCTIMER_R2     0x00000004  // Timer 2 Run Mode Clock Gating
                                            // Control
#define SYSCTL_RCGCTIMER_R1     0x00000002  // Timer 1 Run Mode Clock Gating
                                            // Control
#define SYSCTL_RCGCTIMER_R0     0x00000001  // Timer 0 Run Mode Clock Gating
                                            // Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_RCGCGPIO
// register.
//
//*****************************************************************************
#define SYSCTL_RCGCGPIO_R14     0x00004000  // GPIO Port Q Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCGPIO_R13     0x00002000  // GPIO Port P Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCGPIO_R12     0x00001000  // GPIO Port N Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCGPIO_R11     0x00000800  // GPIO Port M Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCGPIO_R10     0x00000400  // GPIO Port L Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCGPIO_R9      0x00000200  // GPIO Port K Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCGPIO_R8      0x00000100  // GPIO Port J Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCGPIO_R7      0x00000080  // GPIO Port H Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCGPIO_R6      0x00000040  // GPIO Port G Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCGPIO_R5      0x00000020  // GPIO Port F Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCGPIO_R4      0x00000010  // GPIO Port E Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCGPIO_R3      0x00000008  // GPIO Port D Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCGPIO_R2      0x00000004  // GPIO Port C Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCGPIO_R1      0x00000002  // GPIO Port B Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCGPIO_R0      0x00000001  // GPIO Port A Run Mode Clock
                                            // Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_RCGCDMA register.
//
//*****************************************************************************
#define SYSCTL_RCGCDMA_R0       0x00000001  // uDMA Module Run Mode Clock
                                            // Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_RCGCEPI register.
//
//*****************************************************************************
#define SYSCTL_RCGCEPI_R0       0x00000001  // EPI Module Run Mode Clock Gating
                                            // Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_RCGCHIB register.
//
//*****************************************************************************
#define SYSCTL_RCGCHIB_R0       0x00000001  // Hibernation Module Run Mode
                                            // Clock Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_RCGCUART
// register.
//
//*****************************************************************************
#define SYSCTL_RCGCUART_R7      0x00000080  // UART Module 7 Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCUART_R6      0x00000040  // UART Module 6 Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCUART_R5      0x00000020  // UART Module 5 Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCUART_R4      0x00000010  // UART Module 4 Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCUART_R3      0x00000008  // UART Module 3 Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCUART_R2      0x00000004  // UART Module 2 Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCUART_R1      0x00000002  // UART Module 1 Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCUART_R0      0x00000001  // UART Module 0 Run Mode Clock
                                            // Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_RCGCSSI register.
//
//*****************************************************************************
#define SYSCTL_RCGCSSI_R3       0x00000008  // SSI Module 3 Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCSSI_R2       0x00000004  // SSI Module 2 Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCSSI_R1       0x00000002  // SSI Module 1 Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCSSI_R0       0x00000001  // SSI Module 0 Run Mode Clock
                                            // Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_RCGCI2C register.
//
//*****************************************************************************
#define SYSCTL_RCGCI2C_R9       0x00000200  // I2C Module 9 Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCI2C_R8       0x00000100  // I2C Module 8 Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCI2C_R7       0x00000080  // I2C Module 7 Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCI2C_R6       0x00000040  // I2C Module 6 Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCI2C_R5       0x00000020  // I2C Module 5 Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCI2C_R4       0x00000010  // I2C Module 4 Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCI2C_R3       0x00000008  // I2C Module 3 Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCI2C_R2       0x00000004  // I2C Module 2 Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCI2C_R1       0x00000002  // I2C Module 1 Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCI2C_R0       0x00000001  // I2C Module 0 Run Mode Clock
                                            // Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_RCGCUSB register.
//
//*****************************************************************************
#define SYSCTL_RCGCUSB_R0       0x00000001  // USB Module Run Mode Clock Gating
                                            // Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_RCGCEPHY
// register.
//
//*****************************************************************************
#define SYSCTL_RCGCEPHY_R0      0x00000001  // Ethernet PHY Module Run Mode
                                            // Clock Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_RCGCCAN register.
//
//*****************************************************************************
#define SYSCTL_RCGCCAN_R1       0x00000002  // CAN Module 1 Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCCAN_R0       0x00000001  // CAN Module 0 Run Mode Clock
                                            // Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_RCGCADC register.
//
//*****************************************************************************
#define SYSCTL_RCGCADC_R1       0x00000002  // ADC Module 1 Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCADC_R0       0x00000001  // ADC Module 0 Run Mode Clock
                                            // Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_RCGCACMP
// register.
//
//*****************************************************************************
#define SYSCTL_RCGCACMP_R0      0x00000001  // Analog Comparator Module 0 Run
                                            // Mode Clock Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_RCGCPWM register.
//
//*****************************************************************************
#define SYSCTL_RCGCPWM_R0       0x00000001  // PWM Module 0 Run Mode Clock
                                            // Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_RCGCQEI register.
//
//*****************************************************************************
#define SYSCTL_RCGCQEI_R0       0x00000001  // QEI Module 0 Run Mode Clock
                                            // Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_RCGCEEPROM
// register.
//
//*****************************************************************************
#define SYSCTL_RCGCEEPROM_R0    0x00000001  // EEPROM Module Run Mode Clock
                                            // Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_RCGCCCM register.
//
//*****************************************************************************
#define SYSCTL_RCGCCCM_R0       0x00000001  // CRC and Cryptographic Modules
                                            // Run Mode Clock Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_RCGCEMAC
// register.
//
//*****************************************************************************
#define SYSCTL_RCGCEMAC_R0      0x00000001  // Ethernet MAC Module 0 Run Mode
                                            // Clock Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_SCGCWD register.
//
//*****************************************************************************
#define SYSCTL_SCGCWD_S1        0x00000002  // Watchdog Timer 1 Sleep Mode
                                            // Clock Gating Control
#define SYSCTL_SCGCWD_S0        0x00000001  // Watchdog Timer 0 Sleep Mode
                                            // Clock Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_SCGCTIMER
// register.
//
//*****************************************************************************
#define SYSCTL_SCGCTIMER_S7     0x00000080  // 16/32-Bit General-Purpose Timer
                                            // 7 Sleep Mode Clock Gating
                                            // Control
#define SYSCTL_SCGCTIMER_S6     0x00000040  // 16/32-Bit General-Purpose Timer
                                            // 6 Sleep Mode Clock Gating
                                            // Control
#define SYSCTL_SCGCTIMER_S5     0x00000020  // Timer 5 Sleep Mode Clock Gating
                                            // Control
#define SYSCTL_SCGCTIMER_S4     0x00000010  // Timer 4 Sleep Mode Clock Gating
                                            // Control
#define SYSCTL_SCGCTIMER_S3     0x00000008  // Timer 3 Sleep Mode Clock Gating
                                            // Control
#define SYSCTL_SCGCTIMER_S2     0x00000004  // Timer 2 Sleep Mode Clock Gating
                                            // Control
#define SYSCTL_SCGCTIMER_S1     0x00000002  // Timer 1 Sleep Mode Clock Gating
                                            // Control
#define SYSCTL_SCGCTIMER_S0     0x00000001  // Timer 0 Sleep Mode Clock Gating
                                            // Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_SCGCGPIO
// register.
//
//*****************************************************************************
#define SYSCTL_SCGCGPIO_S14     0x00004000  // GPIO Port Q Sleep Mode Clock
                                            // Gating Control
#define SYSCTL_SCGCGPIO_S13     0x00002000  // GPIO Port P Sleep Mode Clock
                                            // Gating Control
#define SYSCTL_SCGCGPIO_S12     0x00001000  // GPIO Port N Sleep Mode Clock
                                            // Gating Control
#define SYSCTL_SCGCGPIO_S11     0x00000800  // GPIO Port M Sleep Mode Clock
                                            // Gating Control
#define SYSCTL_SCGCGPIO_S10     0x00000400  // GPIO Port L Sleep Mode Clock
                                            // Gating Control
#define SYSCTL_SCGCGPIO_S9      0x00000200  // GPIO Port K Sleep Mode Clock
                                            // Gating Control
#define SYSCTL_SCGCGPIO_S8      0x00000100  // GPIO Port J Sleep Mode Clock
                                            // Gating Control
#define SYSCTL_SCGCGPIO_S7      0x00000080  // GPIO Port H Sleep Mode Clock
                                            // Gating Control
#define SYSCTL_SCGCGPIO_S6      0x00000040  // GPIO Port G Sleep Mode Clock
                                            // Gating Control
#define SYSCTL_SCGCGPIO_S5      0x00000020  // GPIO Port F Sleep Mode Clock
                                            // Gating Control
#define SYSCTL_SCGCGPIO_S4      0x00000010  // GPIO Port E Sleep Mode Clock
                                            // Gating Control
#define SYSCTL_SCGCGPIO_S3      0x00000008  // GPIO Port D Sleep Mode Clock
                                            // Gating Control
#define SYSCTL_SCGCGPIO_S2      0x00000004  // GPIO Port C Sleep Mode Clock
                                            // Gating Control
#define SYSCTL_SCGCGPIO_S1      0x00000002  // GPIO Port B Sleep Mode Clock
                                            // Gating Control
#define SYSCTL_SCGCGPIO_S0      0x00000001  // GPIO Port A Sleep Mode Clock
                                            // Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_SCGCEPI register.
//
//*****************************************************************************
#define SYSCTL_SCGCEPI_S0       0x00000001  // EPI Module Sleep Mode Clock
                                            // Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_SCGCHIB register.
//
//*****************************************************************************
#define SYSCTL_SCGCHIB_S0       0x00000001  // Hibernation Module Sleep Mode
                                            // Clock Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_SCGCUART
// register.
//
//*****************************************************************************
#define SYSCTL_SCGCUART_S7      0x00000080  // UART Module 7 Sleep Mode Clock
                                            // Gating Control
#define SYSCTL_SCGCUART_S6      0x00000040  // UART Module 6 Sleep Mode Clock
                                            // Gating Control
#define SYSCTL_SCGCUART_S5      0x00000020  // UART Module 5 Sleep Mode Clock
                                            // Gating Control
#define SYSCTL_SCGCUART_S4      0x00000010  // UART Module 4 Sleep Mode Clock
                                            // Gating Control
#define SYSCTL_SCGCUART_S3      0x00000008  // UART Module 3 Sleep Mode Clock
                                            // Gating Control
#define SYSCTL_SCGCUART_S2      0x00000004  // UART Module 2 Sleep Mode Clock
                                            // Gating Control
#define SYSCTL_SCGCUART_S1      0x00000002  // UART Module 1 Sleep Mode Clock
                                            // Gating Control
#define SYSCTL_SCGCUART_S0      0x00000001  // UART Module 0 Sleep Mode Clock
                                            // Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_SCGCSSI register.
//
//*****************************************************************************
#define SYSCTL_SCGCSSI_S3       0x00000008  // SSI Module 3 Sleep Mode Clock
                                            // Gating Control
#define SYSCTL_SCGCSSI_S2       0x00000004  // SSI Module 2 Sleep Mode Clock
                                            // Gating Control
#define SYSCTL_SCGCSSI_S1       0x00000002  // SSI Module 1 Sleep Mode Clock
                                            // Gating Control
#define SYSCTL_SCGCSSI_S0       0x00000001  // SSI Module 0 Sleep Mode Clock
                                            // Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_SCGCI2C register.
//
//*****************************************************************************
#define SYSCTL_SCGCI2C_S9       0x00000200  // I2C Module 9 Sleep Mode Clock
                                            // Gating Control
#define SYSCTL_SCGCI2C_S8       0x00000100  // I2C Module 8 Sleep Mode Clock
                                            // Gating Control
#define SYSCTL_SCGCI2C_S7       0x00000080  // I2C Module 7 Sleep Mode Clock
                                            // Gating Control
#define SYSCTL_SCGCI2C_S6       0x00000040  // I2C Module 6 Sleep Mode Clock
                                            // Gating Control
#define SYSCTL_SCGCI2C_S5       0x00000020  // I2C Module 5 Sleep Mode Clock
                                            // Gating Control
#define SYSCTL_SCGCI2C_S4       0x00000010  // I2C Module 4 Sleep Mode Clock
                                            // Gating Control
#define SYSCTL_SCGCI2C_S3       0x00000008  // I2C Module 3 Sleep Mode Clock
                                            // Gating Control
#define SYSCTL_SCGCI2C_S2       0x00000004  // I2C Module 2 Sleep Mode Clock
                                            // Gating Control
#define SYSCTL_SCGCI2C_S1       0x00000002  // I2C Module 1 Sleep Mode Clock
                                            // Gating Control
#define SYSCTL_SCGCI2C_S0       0x00000001  // I2C Module 0 Sleep Mode Clock
                                            // Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_SCGCUSB register.
//
//*****************************************************************************
#define SYSCTL_SCGCUSB_S0       0x00000001  // USB Module Sleep Mode Clock
                                            // Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_SCGCEPHY
// register.
//
//*****************************************************************************
#define SYSCTL_SCGCEPHY_S0      0x00000001  // PHY Module Sleep Mode Clock
                                            // Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_SCGCCAN register.
//
//*****************************************************************************
#define SYSCTL_SCGCCAN_S1       0x00000002  // CAN Module 1 Sleep Mode Clock
                                            // Gating Control
#define SYSCTL_SCGCCAN_S0       0x00000001  // CAN Module 0 Sleep Mode Clock
                                            // Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_SCGCADC register.
//
//*****************************************************************************
#define SYSCTL_SCGCADC_S1       0x00000002  // ADC Module 1 Sleep Mode Clock
                                            // Gating Control
#define SYSCTL_SCGCADC_S0       0x00000001  // ADC Module 0 Sleep Mode Clock
                                            // Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_SCGCACMP
// register.
//
//*****************************************************************************
#define SYSCTL_SCGCACMP_S0      0x00000001  // Analog Comparator Module 0 Sleep
                                            // Mode Clock Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_SCGCPWM register.
//
//*****************************************************************************
#define SYSCTL_SCGCPWM_S0       0x00000001  // PWM Module 0 Sleep Mode Clock
                                            // Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_SCGCQEI register.
//
//*****************************************************************************
#define SYSCTL_SCGCQEI_S0       0x00000001  // QEI Module 0 Sleep Mode Clock
                                            // Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_SCGCEEPROM
// register.
//
//*****************************************************************************
#define SYSCTL_SCGCEEPROM_S0    0x00000001  // EEPROM Module Sleep Mode Clock
                                            // Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_SCGCCCM register.
//
//*****************************************************************************
#define SYSCTL_SCGCCCM_S0       0x00000001  // CRC and Cryptographic Modules
                                            // Sleep Mode Clock Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_SCGCEMAC
// register.
//
//*****************************************************************************
#define SYSCTL_SCGCEMAC_S0      0x00000001  // Ethernet MAC Module 0 Sleep Mode
                                            // Clock Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_DCGCWD register.
//
//*****************************************************************************
#define SYSCTL_DCGCWD_D1        0x00000002  // Watchdog Timer 1 Deep-Sleep Mode
                                            // Clock Gating Control
#define SYSCTL_DCGCWD_D0        0x00000001  // Watchdog Timer 0 Deep-Sleep Mode
                                            // Clock Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_DCGCTIMER
// register.
//
//*****************************************************************************
#define SYSCTL_DCGCTIMER_D7     0x00000080  // 16/32-Bit General-Purpose Timer
                                            // 7 Deep-Sleep Mode Clock Gating
                                            // Control
#define SYSCTL_DCGCTIMER_D6     0x00000040  // 16/32-Bit General-Purpose Timer
                                            // 6 Deep-Sleep Mode Clock Gating
                                            // Control
#define SYSCTL_DCGCTIMER_D5     0x00000020  // Timer 5 Deep-Sleep Mode Clock
                                            // Gating Control
#define SYSCTL_DCGCTIMER_D4     0x00000010  // Timer 4 Deep-Sleep Mode Clock
                                            // Gating Control
#define SYSCTL_DCGCTIMER_D3     0x00000008  // Timer 3 Deep-Sleep Mode Clock
                                            // Gating Control
#define SYSCTL_DCGCTIMER_D2     0x00000004  // Timer 2 Deep-Sleep Mode Clock
                                            // Gating Control
#define SYSCTL_DCGCTIMER_D1     0x00000002  // Timer 1 Deep-Sleep Mode Clock
                                            // Gating Control
#define SYSCTL_DCGCTIMER_D0     0x00000001  // Timer 0 Deep-Sleep Mode Clock
                                            // Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_DCGCGPIO
// register.
//
//*****************************************************************************
#define SYSCTL_DCGCGPIO_D14     0x00004000  // GPIO Port Q Deep-Sleep Mode
                                            // Clock Gating Control
#define SYSCTL_DCGCGPIO_D13     0x00002000  // GPIO Port P Deep-Sleep Mode
                                            // Clock Gating Control
#define SYSCTL_DCGCGPIO_D12     0x00001000  // GPIO Port N Deep-Sleep Mode
                                            // Clock Gating Control
#define SYSCTL_DCGCGPIO_D11     0x00000800  // GPIO Port M Deep-Sleep Mode
                                            // Clock Gating Control
#define SYSCTL_DCGCGPIO_D10     0x00000400  // GPIO Port L Deep-Sleep Mode
                                            // Clock Gating Control
#define SYSCTL_DCGCGPIO_D9      0x00000200  // GPIO Port K Deep-Sleep Mode
                                            // Clock Gating Control
#define SYSCTL_DCGCGPIO_D8      0x00000100  // GPIO Port J Deep-Sleep Mode
                                            // Clock Gating Control
#define SYSCTL_DCGCGPIO_D7      0x00000080  // GPIO Port H Deep-Sleep Mode
                                            // Clock Gating Control
#define SYSCTL_DCGCGPIO_D6      0x00000040  // GPIO Port G Deep-Sleep Mode
                                            // Clock Gating Control
#define SYSCTL_DCGCGPIO_D5      0x00000020  // GPIO Port F Deep-Sleep Mode
                                            // Clock Gating Control
#define SYSCTL_DCGCGPIO_D4      0x00000010  // GPIO Port E Deep-Sleep Mode
                                            // Clock Gating Control
#define SYSCTL_DCGCGPIO_D3      0x00000008  // GPIO Port D Deep-Sleep Mode
                                            // Clock Gating Control
#define SYSCTL_DCGCGPIO_D2      0x00000004  // GPIO Port C Deep-Sleep Mode
                                            // Clock Gating Control
#define SYSCTL_DCGCGPIO_D1      0x00000002  // GPIO Port B Deep-Sleep Mode
                                            // Clock Gating Control
#define SYSCTL_DCGCGPIO_D0      0x00000001  // GPIO Port A Deep-Sleep Mode
                                            // Clock Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_DCGCEPI register.
//
//*****************************************************************************
#define SYSCTL_DCGCEPI_D0       0x00000001  // EPI Module Deep-Sleep Mode Clock
                                            // Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_DCGCHIB register.
//
//*****************************************************************************
#define SYSCTL_DCGCHIB_D0       0x00000001  // Hibernation Module Deep-Sleep
                                            // Mode Clock Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_DCGCUART
// register.
//
//*****************************************************************************
#define SYSCTL_DCGCUART_D7      0x00000080  // UART Module 7 Deep-Sleep Mode
                                            // Clock Gating Control
#define SYSCTL_DCGCUART_D6      0x00000040  // UART Module 6 Deep-Sleep Mode
                                            // Clock Gating Control
#define SYSCTL_DCGCUART_D5      0x00000020  // UART Module 5 Deep-Sleep Mode
                                            // Clock Gating Control
#define SYSCTL_DCGCUART_D4      0x00000010  // UART Module 4 Deep-Sleep Mode
                                            // Clock Gating Control
#define SYSCTL_DCGCUART_D3      0x00000008  // UART Module 3 Deep-Sleep Mode
                                            // Clock Gating Control
#define SYSCTL_DCGCUART_D2      0x00000004  // UART Module 2 Deep-Sleep Mode
                                            // Clock Gating Control
#define SYSCTL_DCGCUART_D1      0x00000002  // UART Module 1 Deep-Sleep Mode
                                            // Clock Gating Control
#define SYSCTL_DCGCUART_D0      0x00000001  // UART Module 0 Deep-Sleep Mode
                                            // Clock Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_DCGCSSI register.
//
//*****************************************************************************
#define SYSCTL_DCGCSSI_D3       0x00000008  // SSI Module 3 Deep-Sleep Mode
                                            // Clock Gating Control
#define SYSCTL_DCGCSSI_D2       0x00000004  // SSI Module 2 Deep-Sleep Mode
                                            // Clock Gating Control
#define SYSCTL_DCGCSSI_D1       0x00000002  // SSI Module 1 Deep-Sleep Mode
                                            // Clock Gating Control
#define SYSCTL_DCGCSSI_D0       0x00000001  // SSI Module 0 Deep-Sleep Mode
                                            // Clock Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_DCGCI2C register.
//
//*****************************************************************************
#define SYSCTL_DCGCI2C_D9       0x00000200  // I2C Module 9 Deep-Sleep Mode
                                            // Clock Gating Control
#define SYSCTL_DCGCI2C_D8       0x00000100  // I2C Module 8 Deep-Sleep Mode
                                            // Clock Gating Control
#define SYSCTL_DCGCI2C_D7       0x00000080  // I2C Module 7 Deep-Sleep Mode
                                            // Clock Gating Control
#define SYSCTL_DCGCI2C_D6       0x00000040  // I2C Module 6 Deep-Sleep Mode
                                            // Clock Gating Control
#define SYSCTL_DCGCI2C_D5       0x00000020  // I2C Module 5 Deep-Sleep Mode
                                            // Clock Gating Control
#define SYSCTL_DCGCI2C_D4       0x00000010  // I2C Module 4 Deep-Sleep Mode
                                            // Clock Gating Control
#define SYSCTL_DCGCI2C_D3       0x00000008  // I2C Module 3 Deep-Sleep Mode
                                            // Clock Gating Control
#define SYSCTL_DCGCI2C_D2       0x00000004  // I2C Module 2 Deep-Sleep Mode
                                            // Clock Gating Control
#define SYSCTL_DCGCI2C_D1       0x00000002  // I2C Module 1 Deep-Sleep Mode
                                            // Clock Gating Control
#define SYSCTL_DCGCI2C_D0       0x00000001  // I2C Module 0 Deep-Sleep Mode
                                            // Clock Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_DCGCUSB register.
//
//*****************************************************************************
#define SYSCTL_DCGCUSB_D0       0x00000001  // USB Module Deep-Sleep Mode Clock
                                            // Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_DCGCEPHY
// register.
//
//*****************************************************************************
#define SYSCTL_DCGCEPHY_D0      0x00000001  // PHY Module Deep-Sleep Mode Clock
                                            // Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_DCGCCAN register.
//
//*****************************************************************************
#define SYSCTL_DCGCCAN_D1       0x00000002  // CAN Module 1 Deep-Sleep Mode
                                            // Clock Gating Control
#define SYSCTL_DCGCCAN_D0       0x00000001  // CAN Module 0 Deep-Sleep Mode
                                            // Clock Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_DCGCADC register.
//
//*****************************************************************************
#define SYSCTL_DCGCADC_D1       0x00000002  // ADC Module 1 Deep-Sleep Mode
                                            // Clock Gating Control
#define SYSCTL_DCGCADC_D0       0x00000001  // ADC Module 0 Deep-Sleep Mode
                                            // Clock Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_DCGCACMP
// register.
//
//*****************************************************************************
#define SYSCTL_DCGCACMP_D0      0x00000001  // Analog Comparator Module 0
                                            // Deep-Sleep Mode Clock Gating
                                            // Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_DCGCPWM register.
//
//*****************************************************************************
#define SYSCTL_DCGCPWM_D0       0x00000001  // PWM Module 0 Deep-Sleep Mode
                                            // Clock Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_DCGCQEI register.
//
//*****************************************************************************
#define SYSCTL_DCGCQEI_D0       0x00000001  // QEI Module 0 Deep-Sleep Mode
                                            // Clock Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_DCGCEEPROM
// register.
//
//*****************************************************************************
#define SYSCTL_DCGCEEPROM_D0    0x00000001  // EEPROM Module Deep-Sleep Mode
                                            // Clock Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_DCGCCCM register.
//
//*****************************************************************************
#define SYSCTL_DCGCCCM_D0       0x00000001  // CRC and Cryptographic Modules
                                            // Deep-Sleep Mode Clock Gating
                                            // Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_DCGCEMAC
// register.
//
//*****************************************************************************
#define SYSCTL_DCGCEMAC_D0      0x00000001  // Ethernet MAC Module 0 Deep-Sleep
                                            // Mode Clock Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PCWD register.
//
//*****************************************************************************
#define SYSCTL_PCWD_P1          0x00000002  // Watchdog Timer 1 Power Control
#define SYSCTL_PCWD_P0          0x00000001  // Watchdog Timer 0 Power Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PCTIMER register.
//
//*****************************************************************************
#define SYSCTL_PCTIMER_P7       0x00000080  // General-Purpose Timer 7 Power
                                            // Control
#define SYSCTL_PCTIMER_P6       0x00000040  // General-Purpose Timer 6 Power
                                            // Control
#define SYSCTL_PCTIMER_P5       0x00000020  // 16/32-Bit General-Purpose Timer
                                            // 5 Power Control
#define SYSCTL_PCTIMER_P4       0x00000010  // 16/32-Bit General-Purpose Timer
                                            // 4 Power Control
#define SYSCTL_PCTIMER_P3       0x00000008  // 16/32-Bit General-Purpose Timer
                                            // 3 Power Control
#define SYSCTL_PCTIMER_P2       0x00000004  // 16/32-Bit General-Purpose Timer
                                            // 2 Power Control
#define SYSCTL_PCTIMER_P1       0x00000002  // 16/32-Bit General-Purpose Timer
                                            // 1 Power Control
#define SYSCTL_PCTIMER_P0       0x00000001  // 16/32-Bit General-Purpose Timer
                                            // 0 Power Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PCGPIO register.
//
//*****************************************************************************
#define SYSCTL_PCGPIO_P14       0x00004000  // GPIO Port Q Power Control
#define SYSCTL_PCGPIO_P13       0x00002000  // GPIO Port P Power Control
#define SYSCTL_PCGPIO_P12       0x00001000  // GPIO Port N Power Control
#define SYSCTL_PCGPIO_P11       0x00000800  // GPIO Port M Power Control
#define SYSCTL_PCGPIO_P10       0x00000400  // GPIO Port L Power Control
#define SYSCTL_PCGPIO_P9        0x00000200  // GPIO Port K Power Control
#define SYSCTL_PCGPIO_P8        0x00000100  // GPIO Port J Power Control
#define SYSCTL_PCGPIO_P7        0x00000080  // GPIO Port H Power Control
#define SYSCTL_PCGPIO_P6        0x00000040  // GPIO Port G Power Control
#define SYSCTL_PCGPIO_P5        0x00000020  // GPIO Port F Power Control
#define SYSCTL_PCGPIO_P4        0x00000010  // GPIO Port E Power Control
#define SYSCTL_PCGPIO_P3        0x00000008  // GPIO Port D Power Control
#define SYSCTL_PCGPIO_P2        0x00000004  // GPIO Port C Power Control
#define SYSCTL_PCGPIO_P1        0x00000002  // GPIO Port B Power Control
#define SYSCTL_PCGPIO_P0        0x00000001  // GPIO Port A Power Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PCDMA register.
//
//*****************************************************************************
#define SYSCTL_PCDMA_P0         0x00000001  // uDMA Module Power Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PCEPI register.
//
//*****************************************************************************
#define SYSCTL_PCEPI_P0         0x00000001  // EPI Module Power Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PCHIB register.
//
//*****************************************************************************
#define SYSCTL_PCHIB_P0         0x00000001  // Hibernation Module Power Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PCUART register.
//
//*****************************************************************************
#define SYSCTL_PCUART_P7        0x00000080  // UART Module 7 Power Control
#define SYSCTL_PCUART_P6        0x00000040  // UART Module 6 Power Control
#define SYSCTL_PCUART_P5        0x00000020  // UART Module 5 Power Control
#define SYSCTL_PCUART_P4        0x00000010  // UART Module 4 Power Control
#define SYSCTL_PCUART_P3        0x00000008  // UART Module 3 Power Control
#define SYSCTL_PCUART_P2        0x00000004  // UART Module 2 Power Control
#define SYSCTL_PCUART_P1        0x00000002  // UART Module 1 Power Control
#define SYSCTL_PCUART_P0        0x00000001  // UART Module 0 Power Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PCSSI register.
//
//*****************************************************************************
#define SYSCTL_PCSSI_P3         0x00000008  // SSI Module 3 Power Control
#define SYSCTL_PCSSI_P2         0x00000004  // SSI Module 2 Power Control
#define SYSCTL_PCSSI_P1         0x00000002  // SSI Module 1 Power Control
#define SYSCTL_PCSSI_P0         0x00000001  // SSI Module 0 Power Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PCI2C register.
//
//*****************************************************************************
#define SYSCTL_PCI2C_P9         0x00000200  // I2C Module 9 Power Control
#define SYSCTL_PCI2C_P8         0x00000100  // I2C Module 8 Power Control
#define SYSCTL_PCI2C_P7         0x00000080  // I2C Module 7 Power Control
#define SYSCTL_PCI2C_P6         0x00000040  // I2C Module 6 Power Control
#define SYSCTL_PCI2C_P5         0x00000020  // I2C Module 5 Power Control
#define SYSCTL_PCI2C_P4         0x00000010  // I2C Module 4 Power Control
#define SYSCTL_PCI2C_P3         0x00000008  // I2C Module 3 Power Control
#define SYSCTL_PCI2C_P2         0x00000004  // I2C Module 2 Power Control
#define SYSCTL_PCI2C_P1         0x00000002  // I2C Module 1 Power Control
#define SYSCTL_PCI2C_P0         0x00000001  // I2C Module 0 Power Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PCUSB register.
//
//*****************************************************************************
#define SYSCTL_PCUSB_P0         0x00000001  // USB Module Power Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PCEPHY register.
//
//*****************************************************************************
#define SYSCTL_PCEPHY_P0        0x00000001  // Ethernet PHY Module Power
                                            // Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PCCAN register.
//
//*****************************************************************************
#define SYSCTL_PCCAN_P1         0x00000002  // CAN Module 1 Power Control
#define SYSCTL_PCCAN_P0         0x00000001  // CAN Module 0 Power Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PCADC register.
//
//*****************************************************************************
#define SYSCTL_PCADC_P1         0x00000002  // ADC Module 1 Power Control
#define SYSCTL_PCADC_P0         0x00000001  // ADC Module 0 Power Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PCACMP register.
//
//*****************************************************************************
#define SYSCTL_PCACMP_P0        0x00000001  // Analog Comparator Module 0 Power
                                            // Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PCPWM register.
//
//*****************************************************************************
#define SYSCTL_PCPWM_P0         0x00000001  // PWM Module 0 Power Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PCQEI register.
//
//*****************************************************************************
#define SYSCTL_PCQEI_P0         0x00000001  // QEI Module 0 Power Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PCEEPROM
// register.
//
//*****************************************************************************
#define SYSCTL_PCEEPROM_P0      0x00000001  // EEPROM Module 0 Power Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PCCCM register.
//
//*****************************************************************************
#define SYSCTL_PCCCM_P0         0x00000001  // CRC and Cryptographic Modules
                                            // Power Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PCEMAC register.
//
//*****************************************************************************
#define SYSCTL_PCEMAC_P0        0x00000001  // Ethernet MAC Module 0 Power
                                            // Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PRWD register.
//
//*****************************************************************************
#define SYSCTL_PRWD_R1          0x00000002  // Watchdog Timer 1 Peripheral
                                            // Ready
#define SYSCTL_PRWD_R0          0x00000001  // Watchdog Timer 0 Peripheral
                                            // Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PRTIMER register.
//
//*****************************************************************************
#define SYSCTL_PRTIMER_R7       0x00000080  // 16/32-Bit General-Purpose Timer
                                            // 7 Peripheral Ready
#define SYSCTL_PRTIMER_R6       0x00000040  // 16/32-Bit General-Purpose Timer
                                            // 6 Peripheral Ready
#define SYSCTL_PRTIMER_R5       0x00000020  // Timer 5 Peripheral Ready
#define SYSCTL_PRTIMER_R4       0x00000010  // Timer 4 Peripheral Ready
#define SYSCTL_PRTIMER_R3       0x00000008  // Timer 3 Peripheral Ready
#define SYSCTL_PRTIMER_R2       0x00000004  // Timer 2 Peripheral Ready
#define SYSCTL_PRTIMER_R1       0x00000002  // Timer 1 Peripheral Ready
#define SYSCTL_PRTIMER_R0       0x00000001  // Timer 0 Peripheral Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PRGPIO register.
//
//*****************************************************************************
#define SYSCTL_PRGPIO_R14       0x00004000  // GPIO Port Q Peripheral Ready
#define SYSCTL_PRGPIO_R13       0x00002000  // GPIO Port P Peripheral Ready
#define SYSCTL_PRGPIO_R12       0x00001000  // GPIO Port N Peripheral Ready
#define SYSCTL_PRGPIO_R11       0x00000800  // GPIO Port M Peripheral Ready
#define SYSCTL_PRGPIO_R10       0x00000400  // GPIO Port L Peripheral Ready
#define SYSCTL_PRGPIO_R9        0x00000200  // GPIO Port K Peripheral Ready
#define SYSCTL_PRGPIO_R8        0x00000100  // GPIO Port J Peripheral Ready
#define SYSCTL_PRGPIO_R7        0x00000080  // GPIO Port H Peripheral Ready
#define SYSCTL_PRGPIO_R6        0x00000040  // GPIO Port G Peripheral Ready
#define SYSCTL_PRGPIO_R5        0x00000020  // GPIO Port F Peripheral Ready
#define SYSCTL_PRGPIO_R4        0x00000010  // GPIO Port E Peripheral Ready
#define SYSCTL_PRGPIO_R3        0x00000008  // GPIO Port D Peripheral Ready
#define SYSCTL_PRGPIO_R2        0x00000004  // GPIO Port C Peripheral Ready
#define SYSCTL_PRGPIO_R1        0x00000002  // GPIO Port B Peripheral Ready
#define SYSCTL_PRGPIO_R0        0x00000001  // GPIO Port A Peripheral Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PRDMA register.
//
//*****************************************************************************
#define SYSCTL_PRDMA_R0         0x00000001  // uDMA Module Peripheral Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PREPI register.
//
//*****************************************************************************
#define SYSCTL_PREPI_R0         0x00000001  // EPI Module Peripheral Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PRHIB register.
//
//*****************************************************************************
#define SYSCTL_PRHIB_R0         0x00000001  // Hibernation Module Peripheral
                                            // Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PRUART register.
//
//*****************************************************************************
#define SYSCTL_PRUART_R7        0x00000080  // UART Module 7 Peripheral Ready
#define SYSCTL_PRUART_R6        0x00000040  // UART Module 6 Peripheral Ready
#define SYSCTL_PRUART_R5        0x00000020  // UART Module 5 Peripheral Ready
#define SYSCTL_PRUART_R4        0x00000010  // UART Module 4 Peripheral Ready
#define SYSCTL_PRUART_R3        0x00000008  // UART Module 3 Peripheral Ready
#define SYSCTL_PRUART_R2        0x00000004  // UART Module 2 Peripheral Ready
#define SYSCTL_PRUART_R1        0x00000002  // UART Module 1 Peripheral Ready
#define SYSCTL_PRUART_R0        0x00000001  // UART Module 0 Peripheral Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PRSSI register.
//
//*****************************************************************************
#define SYSCTL_PRSSI_R3         0x00000008  // SSI Module 3 Peripheral Ready
#define SYSCTL_PRSSI_R2         0x00000004  // SSI Module 2 Peripheral Ready
#define SYSCTL_PRSSI_R1         0x00000002  // SSI Module 1 Peripheral Ready
#define SYSCTL_PRSSI_R0         0x00000001  // SSI Module 0 Peripheral Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PRI2C register.
//
//*****************************************************************************
#define SYSCTL_PRI2C_R9         0x00000200  // I2C Module 9 Peripheral Ready
#define SYSCTL_PRI2C_R8         0x00000100  // I2C Module 8 Peripheral Ready
#define SYSCTL_PRI2C_R7         0x00000080  // I2C Module 7 Peripheral Ready
#define SYSCTL_PRI2C_R6         0x00000040  // I2C Module 6 Peripheral Ready
#define SYSCTL_PRI2C_R5         0x00000020  // I2C Module 5 Peripheral Ready
#define SYSCTL_PRI2C_R4         0x00000010  // I2C Module 4 Peripheral Ready
#define SYSCTL_PRI2C_R3         0x00000008  // I2C Module 3 Peripheral Ready
#define SYSCTL_PRI2C_R2         0x00000004  // I2C Module 2 Peripheral Ready
#define SYSCTL_PRI2C_R1         0x00000002  // I2C Module 1 Peripheral Ready
#define SYSCTL_PRI2C_R0         0x00000001  // I2C Module 0 Peripheral Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PRUSB register.
//
//*****************************************************************************
#define SYSCTL_PRUSB_R0         0x00000001  // USB Module Peripheral Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PREPHY register.
//
//*****************************************************************************
#define SYSCTL_PREPHY_R0        0x00000001  // Ethernet PHY Module Peripheral
                                            // Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PRCAN register.
//
//*****************************************************************************
#define SYSCTL_PRCAN_R1         0x00000002  // CAN Module 1 Peripheral Ready
#define SYSCTL_PRCAN_R0         0x00000001  // CAN Module 0 Peripheral Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PRADC register.
//
//*****************************************************************************
#define SYSCTL_PRADC_R1         0x00000002  // ADC Module 1 Peripheral Ready
#define SYSCTL_PRADC_R0         0x00000001  // ADC Module 0 Peripheral Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PRACMP register.
//
//*****************************************************************************
#define SYSCTL_PRACMP_R0        0x00000001  // Analog Comparator Module 0
                                            // Peripheral Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PRPWM register.
//
//*****************************************************************************
#define SYSCTL_PRPWM_R0         0x00000001  // PWM Module 0 Peripheral Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PRQEI register.
//
//*****************************************************************************
#define SYSCTL_PRQEI_R0         0x00000001  // QEI Module 0 Peripheral Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PREEPROM
// register.
//
//*****************************************************************************
#define SYSCTL_PREEPROM_R0      0x00000001  // EEPROM Module Peripheral Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PRCCM register.
//
//*****************************************************************************
#define SYSCTL_PRCCM_R0         0x00000001  // CRC and Cryptographic Modules
                                            // Peripheral Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PREMAC register.
//
//*****************************************************************************
#define SYSCTL_PREMAC_R0        0x00000001  // Ethernet MAC Module 0 Peripheral
                                            // Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_STAT register.
//
//*****************************************************************************
#define UDMA_STAT_DMACHANS_M    0x001F0000  // Available uDMA Channels Minus 1
#define UDMA_STAT_STATE_M       0x000000F0  // Control State Machine Status
#define UDMA_STAT_STATE_IDLE    0x00000000  // Idle
#define UDMA_STAT_STATE_RD_CTRL 0x00000010  // Reading channel controller data
#define UDMA_STAT_STATE_RD_SRCENDP                                            \
                                0x00000020  // Reading source end pointer
#define UDMA_STAT_STATE_RD_DSTENDP                                            \
                                0x00000030  // Reading destination end pointer
#define UDMA_STAT_STATE_RD_SRCDAT                                             \
                                0x00000040  // Reading source data
#define UDMA_STAT_STATE_WR_DSTDAT                                             \
                                0x00000050  // Writing destination data
#define UDMA_STAT_STATE_WAIT    0x00000060  // Waiting for uDMA request to
                                            // clear
#define UDMA_STAT_STATE_WR_CTRL 0x00000070  // Writing channel controller data
#define UDMA_STAT_STATE_STALL   0x00000080  // Stalled
#define UDMA_STAT_STATE_DONE    0x00000090  // Done
#define UDMA_STAT_STATE_UNDEF   0x000000A0  // Undefined
#define UDMA_STAT_MASTEN        0x00000001  // Master Enable Status
#define UDMA_STAT_DMACHANS_S    16

//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_CFG register.
//
//*****************************************************************************
#define UDMA_CFG_MASTEN         0x00000001  // Controller Master Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_CTLBASE register.
//
//*****************************************************************************
#define UDMA_CTLBASE_ADDR_M     0xFFFFFC00  // Channel Control Base Address
#define UDMA_CTLBASE_ADDR_S     10

//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_ALTBASE register.
//
//*****************************************************************************
#define UDMA_ALTBASE_ADDR_M     0xFFFFFFFF  // Alternate Channel Address
                                            // Pointer
#define UDMA_ALTBASE_ADDR_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_WAITSTAT register.
//
//*****************************************************************************
#define UDMA_WAITSTAT_WAITREQ_M 0xFFFFFFFF  // Channel [n] Wait Status

//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_SWREQ register.
//
//*****************************************************************************
#define UDMA_SWREQ_M            0xFFFFFFFF  // Channel [n] Software Request

//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_USEBURSTSET
// register.
//
//*****************************************************************************
#define UDMA_USEBURSTSET_SET_M  0xFFFFFFFF  // Channel [n] Useburst Set

//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_USEBURSTCLR
// register.
//
//*****************************************************************************
#define UDMA_USEBURSTCLR_CLR_M  0xFFFFFFFF  // Channel [n] Useburst Clear

//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_REQMASKSET
// register.
//
//*****************************************************************************
#define UDMA_REQMASKSET_SET_M   0xFFFFFFFF  // Channel [n] Request Mask Set

//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_REQMASKCLR
// register.
//
//*****************************************************************************
#define UDMA_REQMASKCLR_CLR_M   0xFFFFFFFF  // Channel [n] Request Mask Clear

//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_ENASET register.
//
//*****************************************************************************
#define UDMA_ENASET_SET_M       0xFFFFFFFF  // Channel [n] Enable Set

//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_ENACLR register.
//
//*****************************************************************************
#define UDMA_ENACLR_CLR_M       0xFFFFFFFF  // Clear Channel [n] Enable Clear

//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_ALTSET register.
//
//*****************************************************************************
#define UDMA_ALTSET_SET_M       0xFFFFFFFF  // Channel [n] Alternate Set

//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_ALTCLR register.
//
//*****************************************************************************
#define UDMA_ALTCLR_CLR_M       0xFFFFFFFF  // Channel [n] Alternate Clear

//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_PRIOSET register.
//
//*****************************************************************************
#define UDMA_PRIOSET_SET_M      0xFFFFFFFF  // Channel [n] Priority Set

//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_PRIOCLR register.
//
//*****************************************************************************
#define UDMA_PRIOCLR_CLR_M      0xFFFFFFFF  // Channel [n] Priority Clear

//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_ERRCLR register.
//
//*****************************************************************************
#define UDMA_ERRCLR_ERRCLR      0x00000001  // uDMA Bus Error Status

//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_CHASGN register.
//
//*****************************************************************************
#define UDMA_CHASGN_M           0xFFFFFFFF  // Channel [n] Assignment Select
#define UDMA_CHASGN_PRIMARY     0x00000000  // Use the primary channel
                                            // assignment
#define UDMA_CHASGN_SECONDARY   0x00000001  // Use the secondary channel
                                            // assignment

//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_CHMAP0 register.
//
//*****************************************************************************
#define UDMA_CHMAP0_CH7SEL_M    0xF0000000  // uDMA Channel 7 Source Select
#define UDMA_CHMAP0_CH6SEL_M    0x0F000000  // uDMA Channel 6 Source Select
#define UDMA_CHMAP0_CH5SEL_M    0x00F00000  // uDMA Channel 5 Source Select
#define UDMA_CHMAP0_CH4SEL_M    0x000F0000  // uDMA Channel 4 Source Select
#define UDMA_CHMAP0_CH3SEL_M    0x0000F000  // uDMA Channel 3 Source Select
#define UDMA_CHMAP0_CH2SEL_M    0x00000F00  // uDMA Channel 2 Source Select
#define UDMA_CHMAP0_CH1SEL_M    0x000000F0  // uDMA Channel 1 Source Select
#define UDMA_CHMAP0_CH0SEL_M    0x0000000F  // uDMA Channel 0 Source Select
#define UDMA_CHMAP0_CH7SEL_S    28
#define UDMA_CHMAP0_CH6SEL_S    24
#define UDMA_CHMAP0_CH5SEL_S    20
#define UDMA_CHMAP0_CH4SEL_S    16
#define UDMA_CHMAP0_CH3SEL_S    12
#define UDMA_CHMAP0_CH2SEL_S    8
#define UDMA_CHMAP0_CH1SEL_S    4
#define UDMA_CHMAP0_CH0SEL_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_CHMAP1 register.
//
//*****************************************************************************
#define UDMA_CHMAP1_CH15SEL_M   0xF0000000  // uDMA Channel 15 Source Select
#define UDMA_CHMAP1_CH14SEL_M   0x0F000000  // uDMA Channel 14 Source Select
#define UDMA_CHMAP1_CH13SEL_M   0x00F00000  // uDMA Channel 13 Source Select
#define UDMA_CHMAP1_CH12SEL_M   0x000F0000  // uDMA Channel 12 Source Select
#define UDMA_CHMAP1_CH11SEL_M   0x0000F000  // uDMA Channel 11 Source Select
#define UDMA_CHMAP1_CH10SEL_M   0x00000F00  // uDMA Channel 10 Source Select
#define UDMA_CHMAP1_CH9SEL_M    0x000000F0  // uDMA Channel 9 Source Select
#define UDMA_CHMAP1_CH8SEL_M    0x0000000F  // uDMA Channel 8 Source Select
#define UDMA_CHMAP1_CH15SEL_S   28
#define UDMA_CHMAP1_CH14SEL_S   24
#define UDMA_CHMAP1_CH13SEL_S   20
#define UDMA_CHMAP1_CH12SEL_S   16
#define UDMA_CHMAP1_CH11SEL_S   12
#define UDMA_CHMAP1_CH10SEL_S   8
#define UDMA_CHMAP1_CH9SEL_S    4
#define UDMA_CHMAP1_CH8SEL_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_CHMAP2 register.
//
//*****************************************************************************
#define UDMA_CHMAP2_CH23SEL_M   0xF0000000  // uDMA Channel 23 Source Select
#define UDMA_CHMAP2_CH22SEL_M   0x0F000000  // uDMA Channel 22 Source Select
#define UDMA_CHMAP2_CH21SEL_M   0x00F00000  // uDMA Channel 21 Source Select
#define UDMA_CHMAP2_CH20SEL_M   0x000F0000  // uDMA Channel 20 Source Select
#define UDMA_CHMAP2_CH19SEL_M   0x0000F000  // uDMA Channel 19 Source Select
#define UDMA_CHMAP2_CH18SEL_M   0x00000F00  // uDMA Channel 18 Source Select
#define UDMA_CHMAP2_CH17SEL_M   0x000000F0  // uDMA Channel 17 Source Select
#define UDMA_CHMAP2_CH16SEL_M   0x0000000F  // uDMA Channel 16 Source Select
#define UDMA_CHMAP2_CH23SEL_S   28
#define UDMA_CHMAP2_CH22SEL_S   24
#define UDMA_CHMAP2_CH21SEL_S   20
#define UDMA_CHMAP2_CH20SEL_S   16
#define UDMA_CHMAP2_CH19SEL_S   12
#define UDMA_CHMAP2_CH18SEL_S   8
#define UDMA_CHMAP2_CH17SEL_S   4
#define UDMA_CHMAP2_CH16SEL_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_CHMAP3 register.
//
//*****************************************************************************
#define UDMA_CHMAP3_CH31SEL_M   0xF0000000  // uDMA Channel 31 Source Select
#define UDMA_CHMAP3_CH30SEL_M   0x0F000000  // uDMA Channel 30 Source Select
#define UDMA_CHMAP3_CH29SEL_M   0x00F00000  // uDMA Channel 29 Source Select
#define UDMA_CHMAP3_CH28SEL_M   0x000F0000  // uDMA Channel 28 Source Select
#define UDMA_CHMAP3_CH27SEL_M   0x0000F000  // uDMA Channel 27 Source Select
#define UDMA_CHMAP3_CH26SEL_M   0x00000F00  // uDMA Channel 26 Source Select
#define UDMA_CHMAP3_CH25SEL_M   0x000000F0  // uDMA Channel 25 Source Select
#define UDMA_CHMAP3_CH24SEL_M   0x0000000F  // uDMA Channel 24 Source Select
#define UDMA_CHMAP3_CH31SEL_S   28
#define UDMA_CHMAP3_CH30SEL_S   24
#define UDMA_CHMAP3_CH29SEL_S   20
#define UDMA_CHMAP3_CH28SEL_S   16
#define UDMA_CHMAP3_CH27SEL_S   12
#define UDMA_CHMAP3_CH26SEL_S   8
#define UDMA_CHMAP3_CH25SEL_S   4
#define UDMA_CHMAP3_CH24SEL_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_O_SRCENDP register.
//
//*****************************************************************************
#define UDMA_SRCENDP_ADDR_M     0xFFFFFFFF  // Source Address End Pointer
#define UDMA_SRCENDP_ADDR_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_O_DSTENDP register.
//
//*****************************************************************************
#define UDMA_DSTENDP_ADDR_M     0xFFFFFFFF  // Destination Address End Pointer
#define UDMA_DSTENDP_ADDR_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_O_CHCTL register.
//
//*****************************************************************************
#define UDMA_CHCTL_DSTINC_M     0xC0000000  // Destination Address Increment
#define UDMA_CHCTL_DSTINC_8     0x00000000  // Byte
#define UDMA_CHCTL_DSTINC_16    0x40000000  // Half-word
#define UDMA_CHCTL_DSTINC_32    0x80000000  // Word
#define UDMA_CHCTL_DSTINC_NONE  0xC0000000  // No increment
#define UDMA_CHCTL_DSTSIZE_M    0x30000000  // Destination Data Size
#define UDMA_CHCTL_DSTSIZE_8    0x00000000  // Byte
#define UDMA_CHCTL_DSTSIZE_16   0x10000000  // Half-word
#define UDMA_CHCTL_DSTSIZE_32   0x20000000  // Word
#define UDMA_CHCTL_SRCINC_M     0x0C000000  // Source Address Increment
#define UDMA_CHCTL_SRCINC_8     0x00000000  // Byte
#define UDMA_CHCTL_SRCINC_16    0x04000000  // Half-word
#define UDMA_CHCTL_SRCINC_32    0x08000000  // Word
#define UDMA_CHCTL_SRCINC_NONE  0x0C000000  // No increment
#define UDMA_CHCTL_SRCSIZE_M    0x03000000  // Source Data Size
#define UDMA_CHCTL_SRCSIZE_8    0x00000000  // Byte
#define UDMA_CHCTL_SRCSIZE_16   0x01000000  // Half-word
#define UDMA_CHCTL_SRCSIZE_32   0x02000000  // Word
#define UDMA_CHCTL_DSTPROT0     0x00200000  // Destination Privilege Access
#define UDMA_CHCTL_SRCPROT0     0x00040000  // Source Privilege Access
#define UDMA_CHCTL_ARBSIZE_M    0x0003C000  // Arbitration Size
#define UDMA_CHCTL_ARBSIZE_1    0x00000000  // 1 Transfer
#define UDMA_CHCTL_ARBSIZE_2    0x00004000  // 2 Transfers
#define UDMA_CHCTL_ARBSIZE_4    0x00008000  // 4 Transfers
#define UDMA_CHCTL_ARBSIZE_8    0x0000C000  // 8 Transfers
#define UDMA_CHCTL_ARBSIZE_16   0x00010000  // 16 Transfers
#define UDMA_CHCTL_ARBSIZE_32   0x00014000  // 32 Transfers
#define UDMA_CHCTL_ARBSIZE_64   0x00018000  // 64 Transfers
#define UDMA_CHCTL_ARBSIZE_128  0x0001C000  // 128 Transfers
#define UDMA_CHCTL_ARBSIZE_256  0x00020000  // 256 Transfers
#define UDMA_CHCTL_ARBSIZE_512  0x00024000  // 512 Transfers
#define UDMA_CHCTL_ARBSIZE_1024 0x00028000  // 1024 Transfers
#define UDMA_CHCTL_XFERSIZE_M   0x00003FF0  // Transfer Size (minus 1)
#define UDMA_CHCTL_NXTUSEBURST  0x00000008  // Next Useburst
#define UDMA_CHCTL_XFERMODE_M   0x00000007  // uDMA Transfer Mode
#define UDMA_CHCTL_XFERMODE_STOP                                              \
                                0x00000000  // Stop
#define UDMA_CHCTL_XFERMODE_BASIC                                             \
                                0x00000001  // Basic
#define UDMA_CHCTL_XFERMODE_AUTO                                              \
                                0x00000002  // Auto-Request
#define UDMA_CHCTL_XFERMODE_PINGPONG                                          \
                                0x00000003  // Ping-Pong
#define UDMA_CHCTL_XFERMODE_MEM_SG                                            \
                                0x00000004  // Memory Scatter-Gather
#define UDMA_CHCTL_XFERMODE_MEM_SGA                                           \
                                0x00000005  // Alternate Memory Scatter-Gather
#define UDMA_CHCTL_XFERMODE_PER_SG                                            \
                                0x00000006  // Peripheral Scatter-Gather
#define UDMA_CHCTL_XFERMODE_PER_SGA                                           \
                                0x00000007  // Alternate Peripheral
                                            // Scatter-Gather
#define UDMA_CHCTL_XFERSIZE_S   4

//*****************************************************************************
//
// The following are defines for the bit fields in the CCM_O_CRCCTRL register.
//
//*****************************************************************************
#define CCM_CRCCTRL_INIT_M      0x00006000  // CRC Initialization
#define CCM_CRCCTRL_INIT_SEED   0x00000000  // Use the EC_S_CRC_SEED register
                                            // context as the starting value
#define CCM_CRCCTRL_INIT_0      0x00004000  // Initialize to all '0s'
#define CCM_CRCCTRL_INIT_1      0x00006000  // Initialize to all '1s'
#define CCM_CRCCTRL_SIZE        0x00001000  // Input Data Size
#define CCM_CRCCTRL_RESINV      0x00000200  // Result Inverse Enable
#define CCM_CRCCTRL_OBR         0x00000100  // Output Reverse Enable
#define CCM_CRCCTRL_BR          0x00000080  // Bit reverse enable
#define CCM_CRCCTRL_ENDIAN_M    0x00000030  // Endian Control
#define CCM_CRCCTRL_ENDIAN_SBHW 0x00000000  // Configuration unchanged. (B3,
                                            // B2, B1, B0)
#define CCM_CRCCTRL_ENDIAN_SHW  0x00000010  // Bytes are swapped in half-words
                                            // but half-words are not swapped
                                            // (B2, B3, B0, B1)
#define CCM_CRCCTRL_ENDIAN_SHWNB                                              \
                                0x00000020  // Half-words are swapped but bytes
                                            // are not swapped in half-word.
                                            // (B1, B0, B3, B2)
#define CCM_CRCCTRL_ENDIAN_SBSW 0x00000030  // Bytes are swapped in half-words
                                            // and half-words are swapped. (B0,
                                            // B1, B2, B3)
#define CCM_CRCCTRL_TYPE_M      0x0000000F  // Operation Type
#define CCM_CRCCTRL_TYPE_P8055  0x00000000  // Polynomial 0x8005
#define CCM_CRCCTRL_TYPE_P1021  0x00000001  // Polynomial 0x1021
#define CCM_CRCCTRL_TYPE_P4C11DB7                                             \
                                0x00000002  // Polynomial 0x4C11DB7
#define CCM_CRCCTRL_TYPE_P1EDC6F41                                            \
                                0x00000003  // Polynomial 0x1EDC6F41
#define CCM_CRCCTRL_TYPE_TCPCHKSUM                                            \
                                0x00000008  // TCP checksum

//*****************************************************************************
//
// The following are defines for the bit fields in the CCM_O_CRCSEED register.
//
//*****************************************************************************
#define CCM_CRCSEED_SEED_M      0xFFFFFFFF  // SEED/Context Value
#define CCM_CRCSEED_SEED_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the CCM_O_CRCDIN register.
//
//*****************************************************************************
#define CCM_CRCDIN_DATAIN_M     0xFFFFFFFF  // Data Input
#define CCM_CRCDIN_DATAIN_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the CCM_O_CRCRSLTPP
// register.
//
//*****************************************************************************
#define CCM_CRCRSLTPP_RSLTPP_M  0xFFFFFFFF  // Post Processing Result
#define CCM_CRCRSLTPP_RSLTPP_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_ACTLR register.
//
//*****************************************************************************
#define NVIC_ACTLR_DISOOFP      0x00000200  // Disable Out-Of-Order Floating
                                            // Point
#define NVIC_ACTLR_DISFPCA      0x00000100  // Disable CONTROL
#define NVIC_ACTLR_DISFOLD      0x00000004  // Disable IT Folding
#define NVIC_ACTLR_DISWBUF      0x00000002  // Disable Write Buffer
#define NVIC_ACTLR_DISMCYC      0x00000001  // Disable Interrupts of Multiple
                                            // Cycle Instructions

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_ST_CTRL register.
//
//*****************************************************************************
#define NVIC_ST_CTRL_COUNT      0x00010000  // Count Flag
#define NVIC_ST_CTRL_CLK_SRC    0x00000004  // Clock Source
#define NVIC_ST_CTRL_INTEN      0x00000002  // Interrupt Enable
#define NVIC_ST_CTRL_ENABLE     0x00000001  // Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_ST_RELOAD register.
//
//*****************************************************************************
#define NVIC_ST_RELOAD_M        0x00FFFFFF  // Reload Value
#define NVIC_ST_RELOAD_S        0

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_ST_CURRENT
// register.
//
//*****************************************************************************
#define NVIC_ST_CURRENT_M       0x00FFFFFF  // Current Value
#define NVIC_ST_CURRENT_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_EN0 register.
//
//*****************************************************************************
#define NVIC_EN0_INT_M          0xFFFFFFFF  // Interrupt Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_EN1 register.
//
//*****************************************************************************
#define NVIC_EN1_INT_M          0xFFFFFFFF  // Interrupt Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_EN2 register.
//
//*****************************************************************************
#define NVIC_EN2_INT_M          0xFFFFFFFF  // Interrupt Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_EN3 register.
//
//*****************************************************************************
#define NVIC_EN3_INT_M          0xFFFFFFFF  // Interrupt Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_DIS0 register.
//
//*****************************************************************************
#define NVIC_DIS0_INT_M         0xFFFFFFFF  // Interrupt Disable

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_DIS1 register.
//
//*****************************************************************************
#define NVIC_DIS1_INT_M         0xFFFFFFFF  // Interrupt Disable

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_DIS2 register.
//
//*****************************************************************************
#define NVIC_DIS2_INT_M         0xFFFFFFFF  // Interrupt Disable

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_DIS3 register.
//
//*****************************************************************************
#define NVIC_DIS3_INT_M         0xFFFFFFFF  // Interrupt Disable

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PEND0 register.
//
//*****************************************************************************
#define NVIC_PEND0_INT_M        0xFFFFFFFF  // Interrupt Set Pending

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PEND1 register.
//
//*****************************************************************************
#define NVIC_PEND1_INT_M        0xFFFFFFFF  // Interrupt Set Pending

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PEND2 register.
//
//*****************************************************************************
#define NVIC_PEND2_INT_M        0xFFFFFFFF  // Interrupt Set Pending

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PEND3 register.
//
//*****************************************************************************
#define NVIC_PEND3_INT_M        0xFFFFFFFF  // Interrupt Set Pending

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_UNPEND0 register.
//
//*****************************************************************************
#define NVIC_UNPEND0_INT_M      0xFFFFFFFF  // Interrupt Clear Pending

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_UNPEND1 register.
//
//*****************************************************************************
#define NVIC_UNPEND1_INT_M      0xFFFFFFFF  // Interrupt Clear Pending

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_UNPEND2 register.
//
//*****************************************************************************
#define NVIC_UNPEND2_INT_M      0xFFFFFFFF  // Interrupt Clear Pending

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_UNPEND3 register.
//
//*****************************************************************************
#define NVIC_UNPEND3_INT_M      0xFFFFFFFF  // Interrupt Clear Pending

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_ACTIVE0 register.
//
//*****************************************************************************
#define NVIC_ACTIVE0_INT_M      0xFFFFFFFF  // Interrupt Active

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_ACTIVE1 register.
//
//*****************************************************************************
#define NVIC_ACTIVE1_INT_M      0xFFFFFFFF  // Interrupt Active

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_ACTIVE2 register.
//
//*****************************************************************************
#define NVIC_ACTIVE2_INT_M      0xFFFFFFFF  // Interrupt Active

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_ACTIVE3 register.
//
//*****************************************************************************
#define NVIC_ACTIVE3_INT_M      0xFFFFFFFF  // Interrupt Active

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI0 register.
//
//*****************************************************************************
#define NVIC_PRI0_INT3_M        0xE0000000  // Interrupt 3 Priority Mask
#define NVIC_PRI0_INT2_M        0x00E00000  // Interrupt 2 Priority Mask
#define NVIC_PRI0_INT1_M        0x0000E000  // Interrupt 1 Priority Mask
#define NVIC_PRI0_INT0_M        0x000000E0  // Interrupt 0 Priority Mask
#define NVIC_PRI0_INT3_S        29
#define NVIC_PRI0_INT2_S        21
#define NVIC_PRI0_INT1_S        13
#define NVIC_PRI0_INT0_S        5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI1 register.
//
//*****************************************************************************
#define NVIC_PRI1_INT7_M        0xE0000000  // Interrupt 7 Priority Mask
#define NVIC_PRI1_INT6_M        0x00E00000  // Interrupt 6 Priority Mask
#define NVIC_PRI1_INT5_M        0x0000E000  // Interrupt 5 Priority Mask
#define NVIC_PRI1_INT4_M        0x000000E0  // Interrupt 4 Priority Mask
#define NVIC_PRI1_INT7_S        29
#define NVIC_PRI1_INT6_S        21
#define NVIC_PRI1_INT5_S        13
#define NVIC_PRI1_INT4_S        5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI2 register.
//
//*****************************************************************************
#define NVIC_PRI2_INT11_M       0xE0000000  // Interrupt 11 Priority Mask
#define NVIC_PRI2_INT10_M       0x00E00000  // Interrupt 10 Priority Mask
#define NVIC_PRI2_INT9_M        0x0000E000  // Interrupt 9 Priority Mask
#define NVIC_PRI2_INT8_M        0x000000E0  // Interrupt 8 Priority Mask
#define NVIC_PRI2_INT11_S       29
#define NVIC_PRI2_INT10_S       21
#define NVIC_PRI2_INT9_S        13
#define NVIC_PRI2_INT8_S        5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI3 register.
//
//*****************************************************************************
#define NVIC_PRI3_INT15_M       0xE0000000  // Interrupt 15 Priority Mask
#define NVIC_PRI3_INT14_M       0x00E00000  // Interrupt 14 Priority Mask
#define NVIC_PRI3_INT13_M       0x0000E000  // Interrupt 13 Priority Mask
#define NVIC_PRI3_INT12_M       0x000000E0  // Interrupt 12 Priority Mask
#define NVIC_PRI3_INT15_S       29
#define NVIC_PRI3_INT14_S       21
#define NVIC_PRI3_INT13_S       13
#define NVIC_PRI3_INT12_S       5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI4 register.
//
//*****************************************************************************
#define NVIC_PRI4_INT19_M       0xE0000000  // Interrupt 19 Priority Mask
#define NVIC_PRI4_INT18_M       0x00E00000  // Interrupt 18 Priority Mask
#define NVIC_PRI4_INT17_M       0x0000E000  // Interrupt 17 Priority Mask
#define NVIC_PRI4_INT16_M       0x000000E0  // Interrupt 16 Priority Mask
#define NVIC_PRI4_INT19_S       29
#define NVIC_PRI4_INT18_S       21
#define NVIC_PRI4_INT17_S       13
#define NVIC_PRI4_INT16_S       5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI5 register.
//
//*****************************************************************************
#define NVIC_PRI5_INT23_M       0xE0000000  // Interrupt 23 Priority Mask
#define NVIC_PRI5_INT22_M       0x00E00000  // Interrupt 22 Priority Mask
#define NVIC_PRI5_INT21_M       0x0000E000  // Interrupt 21 Priority Mask
#define NVIC_PRI5_INT20_M       0x000000E0  // Interrupt 20 Priority Mask
#define NVIC_PRI5_INT23_S       29
#define NVIC_PRI5_INT22_S       21
#define NVIC_PRI5_INT21_S       13
#define NVIC_PRI5_INT20_S       5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI6 register.
//
//*****************************************************************************
#define NVIC_PRI6_INT27_M       0xE0000000  // Interrupt 27 Priority Mask
#define NVIC_PRI6_INT26_M       0x00E00000  // Interrupt 26 Priority Mask
#define NVIC_PRI6_INT25_M       0x0000E000  // Interrupt 25 Priority Mask
#define NVIC_PRI6_INT24_M       0x000000E0  // Interrupt 24 Priority Mask
#define NVIC_PRI6_INT27_S       29
#define NVIC_PRI6_INT26_S       21
#define NVIC_PRI6_INT25_S       13
#define NVIC_PRI6_INT24_S       5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI7 register.
//
//*****************************************************************************
#define NVIC_PRI7_INT31_M       0xE0000000  // Interrupt 31 Priority Mask
#define NVIC_PRI7_INT30_M       0x00E00000  // Interrupt 30 Priority Mask
#define NVIC_PRI7_INT29_M       0x0000E000  // Interrupt 29 Priority Mask
#define NVIC_PRI7_INT28_M       0x000000E0  // Interrupt 28 Priority Mask
#define NVIC_PRI7_INT31_S       29
#define NVIC_PRI7_INT30_S       21
#define NVIC_PRI7_INT29_S       13
#define NVIC_PRI7_INT28_S       5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI8 register.
//
//*****************************************************************************
#define NVIC_PRI8_INT35_M       0xE0000000  // Interrupt 35 Priority Mask
#define NVIC_PRI8_INT34_M       0x00E00000  // Interrupt 34 Priority Mask
#define NVIC_PRI8_INT33_M       0x0000E000  // Interrupt 33 Priority Mask
#define NVIC_PRI8_INT32_M       0x000000E0  // Interrupt 32 Priority Mask
#define NVIC_PRI8_INT35_S       29
#define NVIC_PRI8_INT34_S       21
#define NVIC_PRI8_INT33_S       13
#define NVIC_PRI8_INT32_S       5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI9 register.
//
//*****************************************************************************
#define NVIC_PRI9_INT39_M       0xE0000000  // Interrupt 39 Priority Mask
#define NVIC_PRI9_INT38_M       0x00E00000  // Interrupt 38 Priority Mask
#define NVIC_PRI9_INT37_M       0x0000E000  // Interrupt 37 Priority Mask
#define NVIC_PRI9_INT36_M       0x000000E0  // Interrupt 36 Priority Mask
#define NVIC_PRI9_INT39_S       29
#define NVIC_PRI9_INT38_S       21
#define NVIC_PRI9_INT37_S       13
#define NVIC_PRI9_INT36_S       5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI10 register.
//
//*****************************************************************************
#define NVIC_PRI10_INT43_M      0xE0000000  // Interrupt 43 Priority Mask
#define NVIC_PRI10_INT42_M      0x00E00000  // Interrupt 42 Priority Mask
#define NVIC_PRI10_INT41_M      0x0000E000  // Interrupt 41 Priority Mask
#define NVIC_PRI10_INT40_M      0x000000E0  // Interrupt 40 Priority Mask
#define NVIC_PRI10_INT43_S      29
#define NVIC_PRI10_INT42_S      21
#define NVIC_PRI10_INT41_S      13
#define NVIC_PRI10_INT40_S      5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI11 register.
//
//*****************************************************************************
#define NVIC_PRI11_INT47_M      0xE0000000  // Interrupt 47 Priority Mask
#define NVIC_PRI11_INT46_M      0x00E00000  // Interrupt 46 Priority Mask
#define NVIC_PRI11_INT45_M      0x0000E000  // Interrupt 45 Priority Mask
#define NVIC_PRI11_INT44_M      0x000000E0  // Interrupt 44 Priority Mask
#define NVIC_PRI11_INT47_S      29
#define NVIC_PRI11_INT46_S      21
#define NVIC_PRI11_INT45_S      13
#define NVIC_PRI11_INT44_S      5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI12 register.
//
//*****************************************************************************
#define NVIC_PRI12_INT51_M      0xE0000000  // Interrupt 51 Priority Mask
#define NVIC_PRI12_INT50_M      0x00E00000  // Interrupt 50 Priority Mask
#define NVIC_PRI12_INT49_M      0x0000E000  // Interrupt 49 Priority Mask
#define NVIC_PRI12_INT48_M      0x000000E0  // Interrupt 48 Priority Mask
#define NVIC_PRI12_INT51_S      29
#define NVIC_PRI12_INT50_S      21
#define NVIC_PRI12_INT49_S      13
#define NVIC_PRI12_INT48_S      5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI13 register.
//
//*****************************************************************************
#define NVIC_PRI13_INT55_M      0xE0000000  // Interrupt 55 Priority Mask
#define NVIC_PRI13_INT54_M      0x00E00000  // Interrupt 54 Priority Mask
#define NVIC_PRI13_INT53_M      0x0000E000  // Interrupt 53 Priority Mask
#define NVIC_PRI13_INT52_M      0x000000E0  // Interrupt 52 Priority Mask
#define NVIC_PRI13_INT55_S      29
#define NVIC_PRI13_INT54_S      21
#define NVIC_PRI13_INT53_S      13
#define NVIC_PRI13_INT52_S      5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI14 register.
//
//*****************************************************************************
#define NVIC_PRI14_INTD_M       0xE0000000  // Interrupt 59 Priority Mask
#define NVIC_PRI14_INTC_M       0x00E00000  // Interrupt 58 Priority Mask
#define NVIC_PRI14_INTB_M       0x0000E000  // Interrupt 57 Priority Mask
#define NVIC_PRI14_INTA_M       0x000000E0  // Interrupt 56 Priority Mask
#define NVIC_PRI14_INTD_S       29
#define NVIC_PRI14_INTC_S       21
#define NVIC_PRI14_INTB_S       13
#define NVIC_PRI14_INTA_S       5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI15 register.
//
//*****************************************************************************
#define NVIC_PRI15_INTD_M       0xE0000000  // Interrupt 63 Priority Mask
#define NVIC_PRI15_INTC_M       0x00E00000  // Interrupt 62 Priority Mask
#define NVIC_PRI15_INTB_M       0x0000E000  // Interrupt 61 Priority Mask
#define NVIC_PRI15_INTA_M       0x000000E0  // Interrupt 60 Priority Mask
#define NVIC_PRI15_INTD_S       29
#define NVIC_PRI15_INTC_S       21
#define NVIC_PRI15_INTB_S       13
#define NVIC_PRI15_INTA_S       5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI16 register.
//
//*****************************************************************************
#define NVIC_PRI16_INTD_M       0xE0000000  // Interrupt 67 Priority Mask
#define NVIC_PRI16_INTC_M       0x00E00000  // Interrupt 66 Priority Mask
#define NVIC_PRI16_INTB_M       0x0000E000  // Interrupt 65 Priority Mask
#define NVIC_PRI16_INTA_M       0x000000E0  // Interrupt 64 Priority Mask
#define NVIC_PRI16_INTD_S       29
#define NVIC_PRI16_INTC_S       21
#define NVIC_PRI16_INTB_S       13
#define NVIC_PRI16_INTA_S       5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI17 register.
//
//*****************************************************************************
#define NVIC_PRI17_INTD_M       0xE0000000  // Interrupt 71 Priority Mask
#define NVIC_PRI17_INTC_M       0x00E00000  // Interrupt 70 Priority Mask
#define NVIC_PRI17_INTB_M       0x0000E000  // Interrupt 69 Priority Mask
#define NVIC_PRI17_INTA_M       0x000000E0  // Interrupt 68 Priority Mask
#define NVIC_PRI17_INTD_S       29
#define NVIC_PRI17_INTC_S       21
#define NVIC_PRI17_INTB_S       13
#define NVIC_PRI17_INTA_S       5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI18 register.
//
//*****************************************************************************
#define NVIC_PRI18_INTD_M       0xE0000000  // Interrupt 75 Priority Mask
#define NVIC_PRI18_INTC_M       0x00E00000  // Interrupt 74 Priority Mask
#define NVIC_PRI18_INTB_M       0x0000E000  // Interrupt 73 Priority Mask
#define NVIC_PRI18_INTA_M       0x000000E0  // Interrupt 72 Priority Mask
#define NVIC_PRI18_INTD_S       29
#define NVIC_PRI18_INTC_S       21
#define NVIC_PRI18_INTB_S       13
#define NVIC_PRI18_INTA_S       5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI19 register.
//
//*****************************************************************************
#define NVIC_PRI19_INTD_M       0xE0000000  // Interrupt 79 Priority Mask
#define NVIC_PRI19_INTC_M       0x00E00000  // Interrupt 78 Priority Mask
#define NVIC_PRI19_INTB_M       0x0000E000  // Interrupt 77 Priority Mask
#define NVIC_PRI19_INTA_M       0x000000E0  // Interrupt 76 Priority Mask
#define NVIC_PRI19_INTD_S       29
#define NVIC_PRI19_INTC_S       21
#define NVIC_PRI19_INTB_S       13
#define NVIC_PRI19_INTA_S       5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI20 register.
//
//*****************************************************************************
#define NVIC_PRI20_INTD_M       0xE0000000  // Interrupt 83 Priority Mask
#define NVIC_PRI20_INTC_M       0x00E00000  // Interrupt 82 Priority Mask
#define NVIC_PRI20_INTB_M       0x0000E000  // Interrupt 81 Priority Mask
#define NVIC_PRI20_INTA_M       0x000000E0  // Interrupt 80 Priority Mask
#define NVIC_PRI20_INTD_S       29
#define NVIC_PRI20_INTC_S       21
#define NVIC_PRI20_INTB_S       13
#define NVIC_PRI20_INTA_S       5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI21 register.
//
//*****************************************************************************
#define NVIC_PRI21_INTD_M       0xE0000000  // Interrupt 87 Priority Mask
#define NVIC_PRI21_INTC_M       0x00E00000  // Interrupt 86 Priority Mask
#define NVIC_PRI21_INTB_M       0x0000E000  // Interrupt 85 Priority Mask
#define NVIC_PRI21_INTA_M       0x000000E0  // Interrupt 84 Priority Mask
#define NVIC_PRI21_INTD_S       29
#define NVIC_PRI21_INTC_S       21
#define NVIC_PRI21_INTB_S       13
#define NVIC_PRI21_INTA_S       5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI22 register.
//
//*****************************************************************************
#define NVIC_PRI22_INTD_M       0xE0000000  // Interrupt 91 Priority Mask
#define NVIC_PRI22_INTC_M       0x00E00000  // Interrupt 90 Priority Mask
#define NVIC_PRI22_INTB_M       0x0000E000  // Interrupt 89 Priority Mask
#define NVIC_PRI22_INTA_M       0x000000E0  // Interrupt 88 Priority Mask
#define NVIC_PRI22_INTD_S       29
#define NVIC_PRI22_INTC_S       21
#define NVIC_PRI22_INTB_S       13
#define NVIC_PRI22_INTA_S       5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI23 register.
//
//*****************************************************************************
#define NVIC_PRI23_INTD_M       0xE0000000  // Interrupt 95 Priority Mask
#define NVIC_PRI23_INTC_M       0x00E00000  // Interrupt 94 Priority Mask
#define NVIC_PRI23_INTB_M       0x0000E000  // Interrupt 93 Priority Mask
#define NVIC_PRI23_INTA_M       0x000000E0  // Interrupt 92 Priority Mask
#define NVIC_PRI23_INTD_S       29
#define NVIC_PRI23_INTC_S       21
#define NVIC_PRI23_INTB_S       13
#define NVIC_PRI23_INTA_S       5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI24 register.
//
//*****************************************************************************
#define NVIC_PRI24_INTD_M       0xE0000000  // Interrupt 99 Priority Mask
#define NVIC_PRI24_INTC_M       0x00E00000  // Interrupt 98 Priority Mask
#define NVIC_PRI24_INTB_M       0x0000E000  // Interrupt 97 Priority Mask
#define NVIC_PRI24_INTA_M       0x000000E0  // Interrupt 96 Priority Mask
#define NVIC_PRI24_INTD_S       29
#define NVIC_PRI24_INTC_S       21
#define NVIC_PRI24_INTB_S       13
#define NVIC_PRI24_INTA_S       5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI25 register.
//
//*****************************************************************************
#define NVIC_PRI25_INTD_M       0xE0000000  // Interrupt 103 Priority Mask
#define NVIC_PRI25_INTC_M       0x00E00000  // Interrupt 102 Priority Mask
#define NVIC_PRI25_INTB_M       0x0000E000  // Interrupt 101 Priority Mask
#define NVIC_PRI25_INTA_M       0x000000E0  // Interrupt 100 Priority Mask
#define NVIC_PRI25_INTD_S       29
#define NVIC_PRI25_INTC_S       21
#define NVIC_PRI25_INTB_S       13
#define NVIC_PRI25_INTA_S       5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI26 register.
//
//*****************************************************************************
#define NVIC_PRI26_INTD_M       0xE0000000  // Interrupt 107 Priority Mask
#define NVIC_PRI26_INTC_M       0x00E00000  // Interrupt 106 Priority Mask
#define NVIC_PRI26_INTB_M       0x0000E000  // Interrupt 105 Priority Mask
#define NVIC_PRI26_INTA_M       0x000000E0  // Interrupt 104 Priority Mask
#define NVIC_PRI26_INTD_S       29
#define NVIC_PRI26_INTC_S       21
#define NVIC_PRI26_INTB_S       13
#define NVIC_PRI26_INTA_S       5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI27 register.
//
//*****************************************************************************
#define NVIC_PRI27_INTD_M       0xE0000000  // Interrupt 111 Priority Mask
#define NVIC_PRI27_INTC_M       0x00E00000  // Interrupt 110 Priority Mask
#define NVIC_PRI27_INTB_M       0x0000E000  // Interrupt 109 Priority Mask
#define NVIC_PRI27_INTA_M       0x000000E0  // Interrupt 108 Priority Mask
#define NVIC_PRI27_INTD_S       29
#define NVIC_PRI27_INTC_S       21
#define NVIC_PRI27_INTB_S       13
#define NVIC_PRI27_INTA_S       5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI28 register.
//
//*****************************************************************************
#define NVIC_PRI28_INTD_M       0xE0000000  // Interrupt 115 Priority Mask
#define NVIC_PRI28_INTC_M       0x00E00000  // Interrupt 114 Priority Mask
#define NVIC_PRI28_INTB_M       0x0000E000  // Interrupt 113 Priority Mask
#define NVIC_PRI28_INTA_M       0x000000E0  // Interrupt 112 Priority Mask
#define NVIC_PRI28_INTD_S       29
#define NVIC_PRI28_INTC_S       21
#define NVIC_PRI28_INTB_S       13
#define NVIC_PRI28_INTA_S       5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_CPUID register.
//
//*****************************************************************************
#define NVIC_CPUID_IMP_M        0xFF000000  // Implementer Code
#define NVIC_CPUID_IMP_ARM      0x41000000  // ARM
#define NVIC_CPUID_VAR_M        0x00F00000  // Variant Number
#define NVIC_CPUID_CON_M        0x000F0000  // Constant
#define NVIC_CPUID_PARTNO_M     0x0000FFF0  // Part Number
#define NVIC_CPUID_PARTNO_CM4   0x0000C240  // Cortex-M4 processor
#define NVIC_CPUID_REV_M        0x0000000F  // Revision Number

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_INT_CTRL register.
//
//*****************************************************************************
#define NVIC_INT_CTRL_NMI_SET   0x80000000  // NMI Set Pending
#define NVIC_INT_CTRL_PEND_SV   0x10000000  // PendSV Set Pending
#define NVIC_INT_CTRL_UNPEND_SV 0x08000000  // PendSV Clear Pending
#define NVIC_INT_CTRL_PENDSTSET 0x04000000  // SysTick Set Pending
#define NVIC_INT_CTRL_PENDSTCLR 0x02000000  // SysTick Clear Pending
#define NVIC_INT_CTRL_ISR_PRE   0x00800000  // Debug Interrupt Handling
#define NVIC_INT_CTRL_ISR_PEND  0x00400000  // Interrupt Pending
#define NVIC_INT_CTRL_VEC_PEN_M 0x000FF000  // Interrupt Pending Vector Number
#define NVIC_INT_CTRL_VEC_PEN_NMI                                             \
                                0x00002000  // NMI
#define NVIC_INT_CTRL_VEC_PEN_HARD                                            \
                                0x00003000  // Hard fault
#define NVIC_INT_CTRL_VEC_PEN_MEM                                             \
                                0x00004000  // Memory management fault
#define NVIC_INT_CTRL_VEC_PEN_BUS                                             \
                                0x00005000  // Bus fault
#define NVIC_INT_CTRL_VEC_PEN_USG                                             \
                                0x00006000  // Usage fault
#define NVIC_INT_CTRL_VEC_PEN_SVC                                             \
                                0x0000B000  // SVCall
#define NVIC_INT_CTRL_VEC_PEN_PNDSV                                           \
                                0x0000E000  // PendSV
#define NVIC_INT_CTRL_VEC_PEN_TICK                                            \
                                0x0000F000  // SysTick
#define NVIC_INT_CTRL_RET_BASE  0x00000800  // Return to Base
#define NVIC_INT_CTRL_VEC_ACT_M 0x000000FF  // Interrupt Pending Vector Number
#define NVIC_INT_CTRL_VEC_ACT_S 0

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_VTABLE register.
//
//*****************************************************************************
#define NVIC_VTABLE_OFFSET_M    0xFFFFFC00  // Vector Table Offset
#define NVIC_VTABLE_OFFSET_S    10

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_APINT register.
//
//*****************************************************************************
#define NVIC_APINT_VECTKEY_M    0xFFFF0000  // Register Key
#define NVIC_APINT_VECTKEY      0x05FA0000  // Vector key
#define NVIC_APINT_ENDIANESS    0x00008000  // Data Endianess
#define NVIC_APINT_PRIGROUP_M   0x00000700  // Interrupt Priority Grouping
#define NVIC_APINT_PRIGROUP_7_1 0x00000000  // Priority group 7.1 split
#define NVIC_APINT_PRIGROUP_6_2 0x00000100  // Priority group 6.2 split
#define NVIC_APINT_PRIGROUP_5_3 0x00000200  // Priority group 5.3 split
#define NVIC_APINT_PRIGROUP_4_4 0x00000300  // Priority group 4.4 split
#define NVIC_APINT_PRIGROUP_3_5 0x00000400  // Priority group 3.5 split
#define NVIC_APINT_PRIGROUP_2_6 0x00000500  // Priority group 2.6 split
#define NVIC_APINT_PRIGROUP_1_7 0x00000600  // Priority group 1.7 split
#define NVIC_APINT_PRIGROUP_0_8 0x00000700  // Priority group 0.8 split
#define NVIC_APINT_SYSRESETREQ  0x00000004  // System Reset Request
#define NVIC_APINT_VECT_CLR_ACT 0x00000002  // Clear Active NMI / Fault
#define NVIC_APINT_VECT_RESET   0x00000001  // System Reset

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_SYS_CTRL register.
//
//*****************************************************************************
#define NVIC_SYS_CTRL_SEVONPEND 0x00000010  // Wake Up on Pending
#define NVIC_SYS_CTRL_SLEEPDEEP 0x00000004  // Deep Sleep Enable
#define NVIC_SYS_CTRL_SLEEPEXIT 0x00000002  // Sleep on ISR Exit

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_CFG_CTRL register.
//
//*****************************************************************************
#define NVIC_CFG_CTRL_STKALIGN  0x00000200  // Stack Alignment on Exception
                                            // Entry
#define NVIC_CFG_CTRL_BFHFNMIGN 0x00000100  // Ignore Bus Fault in NMI and
                                            // Fault
#define NVIC_CFG_CTRL_DIV0      0x00000010  // Trap on Divide by 0
#define NVIC_CFG_CTRL_UNALIGNED 0x00000008  // Trap on Unaligned Access
#define NVIC_CFG_CTRL_MAIN_PEND 0x00000002  // Allow Main Interrupt Trigger
#define NVIC_CFG_CTRL_BASE_THR  0x00000001  // Thread State Control

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_SYS_PRI1 register.
//
//*****************************************************************************
#define NVIC_SYS_PRI1_USAGE_M   0x00E00000  // Usage Fault Priority
#define NVIC_SYS_PRI1_BUS_M     0x0000E000  // Bus Fault Priority
#define NVIC_SYS_PRI1_MEM_M     0x000000E0  // Memory Management Fault Priority
#define NVIC_SYS_PRI1_USAGE_S   21
#define NVIC_SYS_PRI1_BUS_S     13
#define NVIC_SYS_PRI1_MEM_S     5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_SYS_PRI2 register.
//
//*****************************************************************************
#define NVIC_SYS_PRI2_SVC_M     0xE0000000  // SVCall Priority
#define NVIC_SYS_PRI2_SVC_S     29

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_SYS_PRI3 register.
//
//*****************************************************************************
#define NVIC_SYS_PRI3_TICK_M    0xE0000000  // SysTick Exception Priority
#define NVIC_SYS_PRI3_PENDSV_M  0x00E00000  // PendSV Priority
#define NVIC_SYS_PRI3_DEBUG_M   0x000000E0  // Debug Priority
#define NVIC_SYS_PRI3_TICK_S    29
#define NVIC_SYS_PRI3_PENDSV_S  21
#define NVIC_SYS_PRI3_DEBUG_S   5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_SYS_HND_CTRL
// register.
//
//*****************************************************************************
#define NVIC_SYS_HND_CTRL_USAGE 0x00040000  // Usage Fault Enable
#define NVIC_SYS_HND_CTRL_BUS   0x00020000  // Bus Fault Enable
#define NVIC_SYS_HND_CTRL_MEM   0x00010000  // Memory Management Fault Enable
#define NVIC_SYS_HND_CTRL_SVC   0x00008000  // SVC Call Pending
#define NVIC_SYS_HND_CTRL_BUSP  0x00004000  // Bus Fault Pending
#define NVIC_SYS_HND_CTRL_MEMP  0x00002000  // Memory Management Fault Pending
#define NVIC_SYS_HND_CTRL_USAGEP                                              \
                                0x00001000  // Usage Fault Pending
#define NVIC_SYS_HND_CTRL_TICK  0x00000800  // SysTick Exception Active
#define NVIC_SYS_HND_CTRL_PNDSV 0x00000400  // PendSV Exception Active
#define NVIC_SYS_HND_CTRL_MON   0x00000100  // Debug Monitor Active
#define NVIC_SYS_HND_CTRL_SVCA  0x00000080  // SVC Call Active
#define NVIC_SYS_HND_CTRL_USGA  0x00000008  // Usage Fault Active
#define NVIC_SYS_HND_CTRL_BUSA  0x00000002  // Bus Fault Active
#define NVIC_SYS_HND_CTRL_MEMA  0x00000001  // Memory Management Fault Active

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_FAULT_STAT
// register.
//
//*****************************************************************************
#define NVIC_FAULT_STAT_DIV0    0x02000000  // Divide-by-Zero Usage Fault
#define NVIC_FAULT_STAT_UNALIGN 0x01000000  // Unaligned Access Usage Fault
#define NVIC_FAULT_STAT_NOCP    0x00080000  // No Coprocessor Usage Fault
#define NVIC_FAULT_STAT_INVPC   0x00040000  // Invalid PC Load Usage Fault
#define NVIC_FAULT_STAT_INVSTAT 0x00020000  // Invalid State Usage Fault
#define NVIC_FAULT_STAT_UNDEF   0x00010000  // Undefined Instruction Usage
                                            // Fault
#define NVIC_FAULT_STAT_BFARV   0x00008000  // Bus Fault Address Register Valid
#define NVIC_FAULT_STAT_BLSPERR 0x00002000  // Bus Fault on Floating-Point Lazy
                                            // State Preservation
#define NVIC_FAULT_STAT_BSTKE   0x00001000  // Stack Bus Fault
#define NVIC_FAULT_STAT_BUSTKE  0x00000800  // Unstack Bus Fault
#define NVIC_FAULT_STAT_IMPRE   0x00000400  // Imprecise Data Bus Error
#define NVIC_FAULT_STAT_PRECISE 0x00000200  // Precise Data Bus Error
#define NVIC_FAULT_STAT_IBUS    0x00000100  // Instruction Bus Error
#define NVIC_FAULT_STAT_MMARV   0x00000080  // Memory Management Fault Address
                                            // Register Valid
#define NVIC_FAULT_STAT_MLSPERR 0x00000020  // Memory Management Fault on
                                            // Floating-Point Lazy State
                                            // Preservation
#define NVIC_FAULT_STAT_MSTKE   0x00000010  // Stack Access Violation
#define NVIC_FAULT_STAT_MUSTKE  0x00000008  // Unstack Access Violation
#define NVIC_FAULT_STAT_DERR    0x00000002  // Data Access Violation
#define NVIC_FAULT_STAT_IERR    0x00000001  // Instruction Access Violation

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_HFAULT_STAT
// register.
//
//*****************************************************************************
#define NVIC_HFAULT_STAT_DBG    0x80000000  // Debug Event
#define NVIC_HFAULT_STAT_FORCED 0x40000000  // Forced Hard Fault
#define NVIC_HFAULT_STAT_VECT   0x00000002  // Vector Table Read Fault

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_DEBUG_STAT
// register.
//
//*****************************************************************************
#define NVIC_DEBUG_STAT_EXTRNL  0x00000010  // EDBGRQ asserted
#define NVIC_DEBUG_STAT_VCATCH  0x00000008  // Vector catch
#define NVIC_DEBUG_STAT_DWTTRAP 0x00000004  // DWT match
#define NVIC_DEBUG_STAT_BKPT    0x00000002  // Breakpoint instruction
#define NVIC_DEBUG_STAT_HALTED  0x00000001  // Halt request

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_MM_ADDR register.
//
//*****************************************************************************
#define NVIC_MM_ADDR_M          0xFFFFFFFF  // Fault Address
#define NVIC_MM_ADDR_S          0

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_FAULT_ADDR
// register.
//
//*****************************************************************************
#define NVIC_FAULT_ADDR_M       0xFFFFFFFF  // Fault Address
#define NVIC_FAULT_ADDR_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_CPAC register.
//
//*****************************************************************************
#define NVIC_CPAC_CP11_M        0x00C00000  // CP11 Coprocessor Access
                                            // Privilege
#define NVIC_CPAC_CP11_DIS      0x00000000  // Access Denied
#define NVIC_CPAC_CP11_PRIV     0x00400000  // Privileged Access Only
#define NVIC_CPAC_CP11_FULL     0x00C00000  // Full Access
#define NVIC_CPAC_CP10_M        0x00300000  // CP10 Coprocessor Access
                                            // Privilege
#define NVIC_CPAC_CP10_DIS      0x00000000  // Access Denied
#define NVIC_CPAC_CP10_PRIV     0x00100000  // Privileged Access Only
#define NVIC_CPAC_CP10_FULL     0x00300000  // Full Access

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_MPU_TYPE register.
//
//*****************************************************************************
#define NVIC_MPU_TYPE_IREGION_M 0x00FF0000  // Number of I Regions
#define NVIC_MPU_TYPE_DREGION_M 0x0000FF00  // Number of D Regions
#define NVIC_MPU_TYPE_SEPARATE  0x00000001  // Separate or Unified MPU
#define NVIC_MPU_TYPE_IREGION_S 16
#define NVIC_MPU_TYPE_DREGION_S 8

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_MPU_CTRL register.
//
//*****************************************************************************
#define NVIC_MPU_CTRL_PRIVDEFEN 0x00000004  // MPU Default Region
#define NVIC_MPU_CTRL_HFNMIENA  0x00000002  // MPU Enabled During Faults
#define NVIC_MPU_CTRL_ENABLE    0x00000001  // MPU Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_MPU_NUMBER
// register.
//
//*****************************************************************************
#define NVIC_MPU_NUMBER_M       0x00000007  // MPU Region to Access
#define NVIC_MPU_NUMBER_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_MPU_BASE register.
//
//*****************************************************************************
#define NVIC_MPU_BASE_ADDR_M    0xFFFFFFE0  // Base Address Mask
#define NVIC_MPU_BASE_VALID     0x00000010  // Region Number Valid
#define NVIC_MPU_BASE_REGION_M  0x00000007  // Region Number
#define NVIC_MPU_BASE_ADDR_S    5
#define NVIC_MPU_BASE_REGION_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_MPU_ATTR register.
//
//*****************************************************************************
#define NVIC_MPU_ATTR_XN        0x10000000  // Instruction Access Disable
#define NVIC_MPU_ATTR_AP_M      0x07000000  // Access Privilege
#define NVIC_MPU_ATTR_TEX_M     0x00380000  // Type Extension Mask
#define NVIC_MPU_ATTR_SHAREABLE 0x00040000  // Shareable
#define NVIC_MPU_ATTR_CACHEABLE 0x00020000  // Cacheable
#define NVIC_MPU_ATTR_BUFFRABLE 0x00010000  // Bufferable
#define NVIC_MPU_ATTR_SRD_M     0x0000FF00  // Subregion Disable Bits
#define NVIC_MPU_ATTR_SIZE_M    0x0000003E  // Region Size Mask
#define NVIC_MPU_ATTR_ENABLE    0x00000001  // Region Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_MPU_BASE1 register.
//
//*****************************************************************************
#define NVIC_MPU_BASE1_ADDR_M   0xFFFFFFE0  // Base Address Mask
#define NVIC_MPU_BASE1_VALID    0x00000010  // Region Number Valid
#define NVIC_MPU_BASE1_REGION_M 0x00000007  // Region Number
#define NVIC_MPU_BASE1_ADDR_S   5
#define NVIC_MPU_BASE1_REGION_S 0

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_MPU_ATTR1 register.
//
//*****************************************************************************
#define NVIC_MPU_ATTR1_XN       0x10000000  // Instruction Access Disable
#define NVIC_MPU_ATTR1_AP_M     0x07000000  // Access Privilege
#define NVIC_MPU_ATTR1_TEX_M    0x00380000  // Type Extension Mask
#define NVIC_MPU_ATTR1_SHAREABLE                                              \
                                0x00040000  // Shareable
#define NVIC_MPU_ATTR1_CACHEABLE                                              \
                                0x00020000  // Cacheable
#define NVIC_MPU_ATTR1_BUFFRABLE                                              \
                                0x00010000  // Bufferable
#define NVIC_MPU_ATTR1_SRD_M    0x0000FF00  // Subregion Disable Bits
#define NVIC_MPU_ATTR1_SIZE_M   0x0000003E  // Region Size Mask
#define NVIC_MPU_ATTR1_ENABLE   0x00000001  // Region Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_MPU_BASE2 register.
//
//*****************************************************************************
#define NVIC_MPU_BASE2_ADDR_M   0xFFFFFFE0  // Base Address Mask
#define NVIC_MPU_BASE2_VALID    0x00000010  // Region Number Valid
#define NVIC_MPU_BASE2_REGION_M 0x00000007  // Region Number
#define NVIC_MPU_BASE2_ADDR_S   5
#define NVIC_MPU_BASE2_REGION_S 0

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_MPU_ATTR2 register.
//
//*****************************************************************************
#define NVIC_MPU_ATTR2_XN       0x10000000  // Instruction Access Disable
#define NVIC_MPU_ATTR2_AP_M     0x07000000  // Access Privilege
#define NVIC_MPU_ATTR2_TEX_M    0x00380000  // Type Extension Mask
#define NVIC_MPU_ATTR2_SHAREABLE                                              \
                                0x00040000  // Shareable
#define NVIC_MPU_ATTR2_CACHEABLE                                              \
                                0x00020000  // Cacheable
#define NVIC_MPU_ATTR2_BUFFRABLE                                              \
                                0x00010000  // Bufferable
#define NVIC_MPU_ATTR2_SRD_M    0x0000FF00  // Subregion Disable Bits
#define NVIC_MPU_ATTR2_SIZE_M   0x0000003E  // Region Size Mask
#define NVIC_MPU_ATTR2_ENABLE   0x00000001  // Region Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_MPU_BASE3 register.
//
//*****************************************************************************
#define NVIC_MPU_BASE3_ADDR_M   0xFFFFFFE0  // Base Address Mask
#define NVIC_MPU_BASE3_VALID    0x00000010  // Region Number Valid
#define NVIC_MPU_BASE3_REGION_M 0x00000007  // Region Number
#define NVIC_MPU_BASE3_ADDR_S   5
#define NVIC_MPU_BASE3_REGION_S 0

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_MPU_ATTR3 register.
//
//*****************************************************************************
#define NVIC_MPU_ATTR3_XN       0x10000000  // Instruction Access Disable
#define NVIC_MPU_ATTR3_AP_M     0x07000000  // Access Privilege
#define NVIC_MPU_ATTR3_TEX_M    0x00380000  // Type Extension Mask
#define NVIC_MPU_ATTR3_SHAREABLE                                              \
                                0x00040000  // Shareable
#define NVIC_MPU_ATTR3_CACHEABLE                                              \
                                0x00020000  // Cacheable
#define NVIC_MPU_ATTR3_BUFFRABLE                                              \
                                0x00010000  // Bufferable
#define NVIC_MPU_ATTR3_SRD_M    0x0000FF00  // Subregion Disable Bits
#define NVIC_MPU_ATTR3_SIZE_M   0x0000003E  // Region Size Mask
#define NVIC_MPU_ATTR3_ENABLE   0x00000001  // Region Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_DBG_CTRL register.
//
//*****************************************************************************
#define NVIC_DBG_CTRL_DBGKEY_M  0xFFFF0000  // Debug key mask
#define NVIC_DBG_CTRL_DBGKEY    0xA05F0000  // Debug key
#define NVIC_DBG_CTRL_S_RESET_ST                                              \
                                0x02000000  // Core has reset since last read
#define NVIC_DBG_CTRL_S_RETIRE_ST                                             \
                                0x01000000  // Core has executed insruction
                                            // since last read
#define NVIC_DBG_CTRL_S_LOCKUP  0x00080000  // Core is locked up
#define NVIC_DBG_CTRL_S_SLEEP   0x00040000  // Core is sleeping
#define NVIC_DBG_CTRL_S_HALT    0x00020000  // Core status on halt
#define NVIC_DBG_CTRL_S_REGRDY  0x00010000  // Register read/write available
#define NVIC_DBG_CTRL_C_SNAPSTALL                                             \
                                0x00000020  // Breaks a stalled load/store
#define NVIC_DBG_CTRL_C_MASKINT 0x00000008  // Mask interrupts when stepping
#define NVIC_DBG_CTRL_C_STEP    0x00000004  // Step the core
#define NVIC_DBG_CTRL_C_HALT    0x00000002  // Halt the core
#define NVIC_DBG_CTRL_C_DEBUGEN 0x00000001  // Enable debug

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_DBG_XFER register.
//
//*****************************************************************************
#define NVIC_DBG_XFER_REG_WNR   0x00010000  // Write or not read
#define NVIC_DBG_XFER_REG_SEL_M 0x0000001F  // Register
#define NVIC_DBG_XFER_REG_R0    0x00000000  // Register R0
#define NVIC_DBG_XFER_REG_R1    0x00000001  // Register R1
#define NVIC_DBG_XFER_REG_R2    0x00000002  // Register R2
#define NVIC_DBG_XFER_REG_R3    0x00000003  // Register R3
#define NVIC_DBG_XFER_REG_R4    0x00000004  // Register R4
#define NVIC_DBG_XFER_REG_R5    0x00000005  // Register R5
#define NVIC_DBG_XFER_REG_R6    0x00000006  // Register R6
#define NVIC_DBG_XFER_REG_R7    0x00000007  // Register R7
#define NVIC_DBG_XFER_REG_R8    0x00000008  // Register R8
#define NVIC_DBG_XFER_REG_R9    0x00000009  // Register R9
#define NVIC_DBG_XFER_REG_R10   0x0000000A  // Register R10
#define NVIC_DBG_XFER_REG_R11   0x0000000B  // Register R11
#define NVIC_DBG_XFER_REG_R12   0x0000000C  // Register R12
#define NVIC_DBG_XFER_REG_R13   0x0000000D  // Register R13
#define NVIC_DBG_XFER_REG_R14   0x0000000E  // Register R14
#define NVIC_DBG_XFER_REG_R15   0x0000000F  // Register R15
#define NVIC_DBG_XFER_REG_FLAGS 0x00000010  // xPSR/Flags register
#define NVIC_DBG_XFER_REG_MSP   0x00000011  // Main SP
#define NVIC_DBG_XFER_REG_PSP   0x00000012  // Process SP
#define NVIC_DBG_XFER_REG_DSP   0x00000013  // Deep SP
#define NVIC_DBG_XFER_REG_CFBP  0x00000014  // Control/Fault/BasePri/PriMask

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_DBG_DATA register.
//
//*****************************************************************************
#define NVIC_DBG_DATA_M         0xFFFFFFFF  // Data temporary cache
#define NVIC_DBG_DATA_S         0

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_DBG_INT register.
//
//*****************************************************************************
#define NVIC_DBG_INT_HARDERR    0x00000400  // Debug trap on hard fault
#define NVIC_DBG_INT_INTERR     0x00000200  // Debug trap on interrupt errors
#define NVIC_DBG_INT_BUSERR     0x00000100  // Debug trap on bus error
#define NVIC_DBG_INT_STATERR    0x00000080  // Debug trap on usage fault state
#define NVIC_DBG_INT_CHKERR     0x00000040  // Debug trap on usage fault check
#define NVIC_DBG_INT_NOCPERR    0x00000020  // Debug trap on coprocessor error
#define NVIC_DBG_INT_MMERR      0x00000010  // Debug trap on mem manage fault
#define NVIC_DBG_INT_RESET      0x00000008  // Core reset status
#define NVIC_DBG_INT_RSTPENDCLR 0x00000004  // Clear pending core reset
#define NVIC_DBG_INT_RSTPENDING 0x00000002  // Core reset is pending
#define NVIC_DBG_INT_RSTVCATCH  0x00000001  // Reset vector catch

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_SW_TRIG register.
//
//*****************************************************************************
#define NVIC_SW_TRIG_INTID_M    0x000000FF  // Interrupt ID
#define NVIC_SW_TRIG_INTID_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_FPCC register.
//
//*****************************************************************************
#define NVIC_FPCC_ASPEN         0x80000000  // Automatic State Preservation
                                            // Enable
#define NVIC_FPCC_LSPEN         0x40000000  // Lazy State Preservation Enable
#define NVIC_FPCC_MONRDY        0x00000100  // Monitor Ready
#define NVIC_FPCC_BFRDY         0x00000040  // Bus Fault Ready
#define NVIC_FPCC_MMRDY         0x00000020  // Memory Management Fault Ready
#define NVIC_FPCC_HFRDY         0x00000010  // Hard Fault Ready
#define NVIC_FPCC_THREAD        0x00000008  // Thread Mode
#define NVIC_FPCC_USER          0x00000002  // User Privilege Level
#define NVIC_FPCC_LSPACT        0x00000001  // Lazy State Preservation Active

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_FPCA register.
//
//*****************************************************************************
#define NVIC_FPCA_ADDRESS_M     0xFFFFFFF8  // Address
#define NVIC_FPCA_ADDRESS_S     3

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_FPDSC register.
//
//*****************************************************************************
#define NVIC_FPDSC_AHP          0x04000000  // AHP Bit Default
#define NVIC_FPDSC_DN           0x02000000  // DN Bit Default
#define NVIC_FPDSC_FZ           0x01000000  // FZ Bit Default
#define NVIC_FPDSC_RMODE_M      0x00C00000  // RMODE Bit Default
#define NVIC_FPDSC_RMODE_RN     0x00000000  // Round to Nearest (RN) mode
#define NVIC_FPDSC_RMODE_RP     0x00400000  // Round towards Plus Infinity (RP)
                                            // mode
#define NVIC_FPDSC_RMODE_RM     0x00800000  // Round towards Minus Infinity
                                            // (RM) mode
#define NVIC_FPDSC_RMODE_RZ     0x00C00000  // Round towards Zero (RZ) mode

#endif // __TM4C1294NCPDT_H__
