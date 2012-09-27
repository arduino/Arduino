//*****************************************************************************
//
// hw_memmap.h - Macros defining the memory map of Stellaris.
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

#ifndef __HW_MEMMAP_H__
#define __HW_MEMMAP_H__

//*****************************************************************************
//
// The following are defines for the base address of the memories and
// peripherals.
//
//*****************************************************************************
#define FLASH_BASE              0x00000000  // FLASH memory
#define SRAM_BASE               0x20000000  // SRAM memory
#define WATCHDOG0_BASE          0x40000000  // Watchdog0
#define WATCHDOG1_BASE          0x40001000  // Watchdog1
#define GPIO_PORTA_BASE         0x40004000  // GPIO Port A
#define GPIO_PORTB_BASE         0x40005000  // GPIO Port B
#define GPIO_PORTC_BASE         0x40006000  // GPIO Port C
#define GPIO_PORTD_BASE         0x40007000  // GPIO Port D
#define SSI0_BASE               0x40008000  // SSI0
#define SSI1_BASE               0x40009000  // SSI1
#define SSI2_BASE               0x4000A000  // SSI2
#define SSI3_BASE               0x4000B000  // SSI3
#define UART0_BASE              0x4000C000  // UART0
#define UART1_BASE              0x4000D000  // UART1
#define UART2_BASE              0x4000E000  // UART2
#define UART3_BASE              0x4000F000  // UART3
#define UART4_BASE              0x40010000  // UART4
#define UART5_BASE              0x40011000  // UART5
#define UART6_BASE              0x40012000  // UART6
#define UART7_BASE              0x40013000  // UART7
#define I2C0_MASTER_BASE        0x40020000  // I2C0 Master
#define I2C0_SLAVE_BASE         0x40020800  // I2C0 Slave
#define I2C1_MASTER_BASE        0x40021000  // I2C1 Master
#define I2C1_SLAVE_BASE         0x40021800  // I2C1 Slave
#define I2C2_MASTER_BASE        0x40022000  // I2C2 Master
#define I2C2_SLAVE_BASE         0x40022800  // I2C2 Slave
#define I2C3_MASTER_BASE        0x40023000  // I2C3 Master
#define I2C3_SLAVE_BASE         0x40023800  // I2C3 Slave
#define GPIO_PORTE_BASE         0x40024000  // GPIO Port E
#define GPIO_PORTF_BASE         0x40025000  // GPIO Port F
#define GPIO_PORTG_BASE         0x40026000  // GPIO Port G
#define GPIO_PORTH_BASE         0x40027000  // GPIO Port H
#define PWM0_BASE               0x40028000  // Pulse Width Modulator (PWM)
#define PWM1_BASE               0x40029000  // Pulse Width Modulator (PWM)
#define QEI0_BASE               0x4002C000  // QEI0
#define QEI1_BASE               0x4002D000  // QEI1
#define TIMER0_BASE             0x40030000  // Timer0
#define TIMER1_BASE             0x40031000  // Timer1
#define TIMER2_BASE             0x40032000  // Timer2
#define TIMER3_BASE             0x40033000  // Timer3
#define TIMER4_BASE             0x40034000  // Timer4
#define TIMER5_BASE             0x40035000  // Timer5
#define WTIMER0_BASE            0x40036000  // Wide Timer0
#define WTIMER1_BASE            0x40037000  // Wide Timer1
#define ADC0_BASE               0x40038000  // ADC0
#define ADC1_BASE               0x40039000  // ADC1
#define COMP_BASE               0x4003C000  // Analog comparators
#define GPIO_PORTJ_BASE         0x4003D000  // GPIO Port J
#define CAN0_BASE               0x40040000  // CAN0
#define CAN1_BASE               0x40041000  // CAN1
#define CAN2_BASE               0x40042000  // CAN2
#define ETH_BASE                0x40048000  // Ethernet
#define MAC_BASE                0x40048000  // Ethernet
#define WTIMER2_BASE            0x4004C000  // Wide Timer2
#define WTIMER3_BASE            0x4004D000  // Wide Timer3
#define WTIMER4_BASE            0x4004E000  // Wide Timer4
#define WTIMER5_BASE            0x4004F000  // Wide Timer5
#define USB0_BASE               0x40050000  // USB 0 Controller
#define I2S0_BASE               0x40054000  // I2S0
#define GPIO_PORTA_AHB_BASE     0x40058000  // GPIO Port A (high speed)
#define GPIO_PORTB_AHB_BASE     0x40059000  // GPIO Port B (high speed)
#define GPIO_PORTC_AHB_BASE     0x4005A000  // GPIO Port C (high speed)
#define GPIO_PORTD_AHB_BASE     0x4005B000  // GPIO Port D (high speed)
#define GPIO_PORTE_AHB_BASE     0x4005C000  // GPIO Port E (high speed)
#define GPIO_PORTF_AHB_BASE     0x4005D000  // GPIO Port F (high speed)
#define GPIO_PORTG_AHB_BASE     0x4005E000  // GPIO Port G (high speed)
#define GPIO_PORTH_AHB_BASE     0x4005F000  // GPIO Port H (high speed)
#define GPIO_PORTJ_AHB_BASE     0x40060000  // GPIO Port J (high speed)
#define GPIO_PORTK_BASE         0x40061000  // GPIO Port K
#define GPIO_PORTL_BASE         0x40062000  // GPIO Port L
#define GPIO_PORTM_BASE         0x40063000  // GPIO Port M
#define GPIO_PORTN_BASE         0x40064000  // GPIO Port N
#define GPIO_PORTP_BASE         0x40065000  // GPIO Port P
#define GPIO_PORTQ_BASE         0x40066000  // GPIO Port Q
#define LPC0_BASE               0x40080000  // Low Pin Count Interface (LPC)
#define FAN0_BASE               0x40084000  // Fan Control (FAN)
#define EEPROM_BASE             0x400AF000  // EEPROM memory
#define PECI0_BASE              0x400B0000  // Platform Environment Control
                                            // Interface (PECI)
#define I2C4_MASTER_BASE        0x400C0000  // I2C4 Master
#define I2C4_SLAVE_BASE         0x400C0800  // I2C4 Slave
#define I2C5_MASTER_BASE        0x400C1000  // I2C5 Master
#define I2C5_SLAVE_BASE         0x400C1800  // I2C5 Slave
#define EPI0_BASE               0x400D0000  // EPI0
#define SYSEXC_BASE             0x400F9000  // System Exception Module
#define HIB_BASE                0x400FC000  // Hibernation Module
#define FLASH_CTRL_BASE         0x400FD000  // FLASH Controller
#define SYSCTL_BASE             0x400FE000  // System Control
#define UDMA_BASE               0x400FF000  // uDMA Controller
#define ITM_BASE                0xE0000000  // Instrumentation Trace Macrocell
#define DWT_BASE                0xE0001000  // Data Watchpoint and Trace
#define FPB_BASE                0xE0002000  // FLASH Patch and Breakpoint
#define NVIC_BASE               0xE000E000  // Nested Vectored Interrupt Ctrl
#define TPIU_BASE               0xE0040000  // Trace Port Interface Unit

//*****************************************************************************
//
// The following definitions are deprecated.
//
//*****************************************************************************
#ifndef DEPRECATED

//*****************************************************************************
//
// The following are deprecated defines for the base address of the memories
// and peripherals.
//
//*****************************************************************************
#define WATCHDOG_BASE           0x40000000  // Watchdog
#define SSI_BASE                0x40008000  // SSI
#define I2C_MASTER_BASE         0x40020000  // I2C Master
#define I2C_SLAVE_BASE          0x40020800  // I2C Slave
#define PWM_BASE                0x40028000  // PWM
#define QEI_BASE                0x4002C000  // QEI
#define ADC_BASE                0x40038000  // ADC

#endif

#endif // __HW_MEMMAP_H__
