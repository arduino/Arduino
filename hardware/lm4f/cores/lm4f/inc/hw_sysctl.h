//*****************************************************************************
//
// hw_sysctl.h - Macros used when accessing the system control hardware.
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
// This is part of revision 2.0.1.11577 of the Tiva Firmware Development Package.
//
//*****************************************************************************

#ifndef __HW_SYSCTL_H__
#define __HW_SYSCTL_H__

//*****************************************************************************
//
// The following are defines for the System Control register addresses.
//
//*****************************************************************************
#define SYSCTL_DID0             0x400FE000  // Device Identification 0
#define SYSCTL_DID1             0x400FE004  // Device Identification 1
#define SYSCTL_DC0              0x400FE008  // Device Capabilities 0
#define SYSCTL_DC1              0x400FE010  // Device Capabilities 1
#define SYSCTL_DC2              0x400FE014  // Device Capabilities 2
#define SYSCTL_DC3              0x400FE018  // Device Capabilities 3
#define SYSCTL_DC4              0x400FE01C  // Device Capabilities 4
#define SYSCTL_DC5              0x400FE020  // Device Capabilities 5
#define SYSCTL_DC6              0x400FE024  // Device Capabilities 6
#define SYSCTL_DC7              0x400FE028  // Device Capabilities 7
#define SYSCTL_DC8              0x400FE02C  // Device Capabilities 8 ADC
                                            // Channels
#define SYSCTL_PBORCTL          0x400FE030  // Brown-Out Reset Control
#define SYSCTL_PTBOCTL          0x400FE038  // Power-Temp Brown Out Control
#define SYSCTL_SRCR0            0x400FE040  // Software Reset Control 0
#define SYSCTL_SRCR1            0x400FE044  // Software Reset Control 1
#define SYSCTL_SRCR2            0x400FE048  // Software Reset Control 2
#define SYSCTL_RIS              0x400FE050  // Raw Interrupt Status
#define SYSCTL_IMC              0x400FE054  // Interrupt Mask Control
#define SYSCTL_MISC             0x400FE058  // Masked Interrupt Status and
                                            // Clear
#define SYSCTL_RESC             0x400FE05C  // Reset Cause
#define SYSCTL_PWRTC            0x400FE060  // Power-Temperature Cause
#define SYSCTL_RCC              0x400FE060  // Run-Mode Clock Configuration
#define SYSCTL_NMIC             0x400FE064  // NMI Cause Register
#define SYSCTL_GPIOHBCTL        0x400FE06C  // GPIO High-Performance Bus
                                            // Control
#define SYSCTL_RCC2             0x400FE070  // Run-Mode Clock Configuration 2
#define SYSCTL_MOSCCTL          0x400FE07C  // Main Oscillator Control
#define SYSCTL_RSCLKCFG         0x400FE0B0  // Run and Sleep Mode Configuration
                                            // Register
#define SYSCTL_MEMTIM0          0x400FE0C0  // Memory Timing Parameter Register
                                            // 0 for Main Flash and EEPROM
#define SYSCTL_DSMEMTIM0        0x400FE0C8  // Deep Sleep Mode Memory Timing
                                            // Register 0 for Main Flash and
                                            // EEPROM
#define SYSCTL_RCGC0            0x400FE100  // Run Mode Clock Gating Control
                                            // Register 0
#define SYSCTL_RCGC1            0x400FE104  // Run Mode Clock Gating Control
                                            // Register 1
#define SYSCTL_RCGC2            0x400FE108  // Run Mode Clock Gating Control
                                            // Register 2
#define SYSCTL_SCGC0            0x400FE110  // Sleep Mode Clock Gating Control
                                            // Register 0
#define SYSCTL_SCGC1            0x400FE114  // Sleep Mode Clock Gating Control
                                            // Register 1
#define SYSCTL_SCGC2            0x400FE118  // Sleep Mode Clock Gating Control
                                            // Register 2
#define SYSCTL_DCGC0            0x400FE120  // Deep Sleep Mode Clock Gating
                                            // Control Register 0
#define SYSCTL_DCGC1            0x400FE124  // Deep-Sleep Mode Clock Gating
                                            // Control Register 1
#define SYSCTL_DCGC2            0x400FE128  // Deep Sleep Mode Clock Gating
                                            // Control Register 2
#define SYSCTL_ALTCLKCFG        0x400FE138  // Alternate Clock Configuration
#define SYSCTL_DSLPCLKCFG       0x400FE144  // Deep Sleep Clock Configuration
#define SYSCTL_DSCLKCFG         0x400FE144  // Deep Sleep Clock Configuration
                                            // Register
#define SYSCTL_DIVSCLK          0x400FE148  // Divisor and Source Clock
                                            // Configuration
#define SYSCTL_SYSPROP          0x400FE14C  // System Properties
#define SYSCTL_PIOSCCAL         0x400FE150  // Precision Internal Oscillator
                                            // Calibration
#define SYSCTL_PIOSCSTAT        0x400FE154  // Precision Internal Oscillator
                                            // Statistics
#define SYSCTL_PLLFREQ0         0x400FE160  // PLL Frequency 0
#define SYSCTL_PLLFREQ1         0x400FE164  // PLL Frequency 1
#define SYSCTL_PLLSTAT          0x400FE168  // PLL Status
#define SYSCTL_SLPPWRCFG        0x400FE188  // Sleep Power Configuration
#define SYSCTL_DSLPPWRCFG       0x400FE18C  // Deep-Sleep Power Configuration
#define SYSCTL_DC9              0x400FE190  // Device Capabilities 9 ADC
                                            // Digital Comparators
#define SYSCTL_NVMSTAT          0x400FE1A0  // Non-Volatile Memory Information
#define SYSCTL_LDOSPCTL         0x400FE1B4  // LDO Sleep Power Control
#define SYSCTL_LDODPCTL         0x400FE1BC  // LDO Deep-Sleep Power Control
#define SYSCTL_RESBEHAVCTL      0x400FE1D8  // Reset Behavior Control Register
#define SYSCTL_HSSR             0x400FE1F4  // Hardware System Service Request
#define SYSCTL_USBPDS           0x400FE280  // USB Power Domain Status
#define SYSCTL_USBMPC           0x400FE284  // USB Memory Power Control
#define SYSCTL_EMACPDS          0x400FE288  // Ethernet MAC Power Domain Status
#define SYSCTL_EMACMPC          0x400FE28C  // Ethernet MAC Memory Power
                                            // Control
#define SYSCTL_LCDMPC           0x400FE294  // LCD Memory Power Control
#define SYSCTL_PPWD             0x400FE300  // Watchdog Timer Peripheral
                                            // Present
#define SYSCTL_PPTIMER          0x400FE304  // Timer Peripheral Present
#define SYSCTL_PPGPIO           0x400FE308  // General-Purpose Input/Output
                                            // Peripheral Present
#define SYSCTL_PPDMA            0x400FE30C  // Micro Direct Memory Access
                                            // Peripheral Present
#define SYSCTL_PPEPI            0x400FE310  // EPI Peripheral Present -SCPL
#define SYSCTL_PPHIB            0x400FE314  // Hibernation Peripheral Present
#define SYSCTL_PPUART           0x400FE318  // Universal Asynchronous
                                            // Receiver/Transmitter Peripheral
                                            // Present
#define SYSCTL_PPSSI            0x400FE31C  // Synchronous Serial Interface
                                            // Peripheral Present
#define SYSCTL_PPI2C            0x400FE320  // Inter-Integrated Circuit
                                            // Peripheral Present
#define SYSCTL_PPUSB            0x400FE328  // Universal Serial Bus Peripheral
                                            // Present
#define SYSCTL_PPEPHY           0x400FE330  // Ethernet PHY Peripheral Present
#define SYSCTL_PPCAN            0x400FE334  // Controller Area Network
                                            // Peripheral Present
#define SYSCTL_PPADC            0x400FE338  // Analog-to-Digital Converter
                                            // Peripheral Present
#define SYSCTL_PPACMP           0x400FE33C  // Analog Comparator Peripheral
                                            // Present
#define SYSCTL_PPPWM            0x400FE340  // Pulse Width Modulator Peripheral
                                            // Present
#define SYSCTL_PPQEI            0x400FE344  // Quadrature Encoder Interface
                                            // Peripheral Present
#define SYSCTL_PPLPC            0x400FE348  // Low Pin Count Interface
                                            // Peripheral Present
#define SYSCTL_PPPECI           0x400FE350  // Platform Environment Control
                                            // Interface Peripheral Present
#define SYSCTL_PPFAN            0x400FE354  // Fan Control Peripheral Present
#define SYSCTL_PPEEPROM         0x400FE358  // EEPROM Peripheral Present
#define SYSCTL_PPWTIMER         0x400FE35C  // Wide Timer Peripheral Present
#define SYSCTL_PPRTS            0x400FE370  // Remote Temperature Sensor
                                            // Peripheral Present -SCPL
#define SYSCTL_PPCCM            0x400FE374  // CRC and Cryptographic Modules
                                            // Peripheral Present
#define SYSCTL_PPLCD            0x400FE390  // LCD Peripheral Present - INIT
                                            // ROM
#define SYSCTL_PPOWIRE          0x400FE398  // One-Wire Peripheral Present
                                            // -SCPL
#define SYSCTL_PPEMAC           0x400FE39C  // Ethernet MAC Peripheral Present
#define SYSCTL_PPHIM            0x400FE3A4  // Human Interface Master
                                            // Peripheral Present -SCPL
#define SYSCTL_SRWD             0x400FE500  // Watchdog Timer Software Reset
#define SYSCTL_SRTIMER          0x400FE504  // Timer Software Reset
#define SYSCTL_SRGPIO           0x400FE508  // General-Purpose Input/Output
                                            // Software Reset
#define SYSCTL_SRDMA            0x400FE50C  // Micro Direct Memory Access
                                            // Software Reset
#define SYSCTL_SREPI            0x400FE510  // EPI Software Reset
#define SYSCTL_SRHIB            0x400FE514  // Hibernation Software Reset
#define SYSCTL_SRUART           0x400FE518  // Universal Asynchronous
                                            // Receiver/Transmitter Software
                                            // Reset
#define SYSCTL_SRSSI            0x400FE51C  // Synchronous Serial Interface
                                            // Software Reset
#define SYSCTL_SRI2C            0x400FE520  // Inter-Integrated Circuit
                                            // Software Reset
#define SYSCTL_SRUSB            0x400FE528  // Universal Serial Bus Software
                                            // Reset
#define SYSCTL_SREPHY           0x400FE530  // Ethernet PHY Software Reset
#define SYSCTL_SRCAN            0x400FE534  // Controller Area Network Software
                                            // Reset
#define SYSCTL_SRADC            0x400FE538  // Analog-to-Digital Converter
                                            // Software Reset
#define SYSCTL_SRACMP           0x400FE53C  // Analog Comparator Software Reset
#define SYSCTL_SRPWM            0x400FE540  // Pulse Width Modulator Software
                                            // Reset
#define SYSCTL_SRQEI            0x400FE544  // Quadrature Encoder Interface
                                            // Software Reset
#define SYSCTL_SREEPROM         0x400FE558  // EEPROM Software Reset
#define SYSCTL_SRWTIMER         0x400FE55C  // Wide Timer Software Reset
#define SYSCTL_SRCCM            0x400FE574  // CRC and Cryptographic Modules
                                            // Software Reset
#define SYSCTL_SRLCD            0x400FE590  // LCD Controller Software Reset
#define SYSCTL_SROWIRE          0x400FE598  // One-Wire Software Reset
#define SYSCTL_SREMAC           0x400FE59C  // Ethernet MAC Software Reset
#define SYSCTL_RCGCWD           0x400FE600  // Watchdog Timer Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCTIMER        0x400FE604  // Timer Run Mode Clock Gating
                                            // Control
#define SYSCTL_RCGCGPIO         0x400FE608  // General-Purpose Input/Output Run
                                            // Mode Clock Gating Control
#define SYSCTL_RCGCDMA          0x400FE60C  // Micro Direct Memory Access Run
                                            // Mode Clock Gating Control
#define SYSCTL_RCGCEPI          0x400FE610  // EPI Run Mode Clock Gating
                                            // Control
#define SYSCTL_RCGCHIB          0x400FE614  // Hibernation Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCUART         0x400FE618  // Universal Asynchronous
                                            // Receiver/Transmitter Run Mode
                                            // Clock Gating Control
#define SYSCTL_RCGCSSI          0x400FE61C  // Synchronous Serial Interface Run
                                            // Mode Clock Gating Control
#define SYSCTL_RCGCI2C          0x400FE620  // Inter-Integrated Circuit Run
                                            // Mode Clock Gating Control
#define SYSCTL_RCGCUSB          0x400FE628  // Universal Serial Bus Run Mode
                                            // Clock Gating Control
#define SYSCTL_RCGCEPHY         0x400FE630  // Ethernet PHY Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCCAN          0x400FE634  // Controller Area Network Run Mode
                                            // Clock Gating Control
#define SYSCTL_RCGCADC          0x400FE638  // Analog-to-Digital Converter Run
                                            // Mode Clock Gating Control
#define SYSCTL_RCGCACMP         0x400FE63C  // Analog Comparator Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCPWM          0x400FE640  // Pulse Width Modulator Run Mode
                                            // Clock Gating Control
#define SYSCTL_RCGCQEI          0x400FE644  // Quadrature Encoder Interface Run
                                            // Mode Clock Gating Control
#define SYSCTL_RCGCEEPROM       0x400FE658  // EEPROM Run Mode Clock Gating
                                            // Control
#define SYSCTL_RCGCWTIMER       0x400FE65C  // Wide Timer Run Mode Clock Gating
                                            // Control
#define SYSCTL_RCGCCCM          0x400FE674  // CRC and Cryptographic Modules
                                            // Run Mode Clock Gating Control
#define SYSCTL_RCGCLCD          0x400FE690  // LCD Controller Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCOWIRE        0x400FE698  // One-Wire Run Mode Clock Gating
                                            // Control
#define SYSCTL_RCGCEMAC         0x400FE69C  // Ethernet MAC Run Mode Clock
                                            // Gating Control
#define SYSCTL_SCGCWD           0x400FE700  // Watchdog Timer Sleep Mode Clock
                                            // Gating Control
#define SYSCTL_SCGCTIMER        0x400FE704  // Timer Sleep Mode Clock Gating
                                            // Control
#define SYSCTL_SCGCGPIO         0x400FE708  // General-Purpose Input/Output
                                            // Sleep Mode Clock Gating Control
#define SYSCTL_SCGCDMA          0x400FE70C  // Micro Direct Memory Access Sleep
                                            // Mode Clock Gating Control
#define SYSCTL_SCGCEPI          0x400FE710  // EPI Sleep Mode Clock Gating
                                            // Control
#define SYSCTL_SCGCHIB          0x400FE714  // Hibernation Sleep Mode Clock
                                            // Gating Control
#define SYSCTL_SCGCUART         0x400FE718  // Universal Asynchronous
                                            // Receiver/Transmitter Sleep Mode
                                            // Clock Gating Control
#define SYSCTL_SCGCSSI          0x400FE71C  // Synchronous Serial Interface
                                            // Sleep Mode Clock Gating Control
#define SYSCTL_SCGCI2C          0x400FE720  // Inter-Integrated Circuit Sleep
                                            // Mode Clock Gating Control
#define SYSCTL_SCGCUSB          0x400FE728  // Universal Serial Bus Sleep Mode
                                            // Clock Gating Control
#define SYSCTL_SCGCEPHY         0x400FE730  // Ethernet PHY Sleep Mode Clock
                                            // Gating Control
#define SYSCTL_SCGCCAN          0x400FE734  // Controller Area Network Sleep
                                            // Mode Clock Gating Control
#define SYSCTL_SCGCADC          0x400FE738  // Analog-to-Digital Converter
                                            // Sleep Mode Clock Gating Control
#define SYSCTL_SCGCACMP         0x400FE73C  // Analog Comparator Sleep Mode
                                            // Clock Gating Control
#define SYSCTL_SCGCPWM          0x400FE740  // Pulse Width Modulator Sleep Mode
                                            // Clock Gating Control
#define SYSCTL_SCGCQEI          0x400FE744  // Quadrature Encoder Interface
                                            // Sleep Mode Clock Gating Control
#define SYSCTL_SCGCEEPROM       0x400FE758  // EEPROM Sleep Mode Clock Gating
                                            // Control
#define SYSCTL_SCGCWTIMER       0x400FE75C  // Wide Timer Sleep Mode Clock
                                            // Gating Control
#define SYSCTL_SCGCCCM          0x400FE774  // CRC and Cryptographic Modules
                                            // Sleep Mode Clock Gating Control
#define SYSCTL_SCGCLCD          0x400FE790  // LCD Controller Sleep Mode Clock
                                            // Gating Control
#define SYSCTL_SCGCOWIRE        0x400FE798  // One-Wire Sleep Mode Clock Gating
                                            // Control
#define SYSCTL_SCGCEMAC         0x400FE79C  // Ethernet MAC Sleep Mode Clock
                                            // Gating Control
#define SYSCTL_DCGCWD           0x400FE800  // Watchdog Timer Deep-Sleep Mode
                                            // Clock Gating Control
#define SYSCTL_DCGCTIMER        0x400FE804  // Timer Deep-Sleep Mode Clock
                                            // Gating Control
#define SYSCTL_DCGCGPIO         0x400FE808  // General-Purpose Input/Output
                                            // Deep-Sleep Mode Clock Gating
                                            // Control
#define SYSCTL_DCGCDMA          0x400FE80C  // Micro Direct Memory Access
                                            // Deep-Sleep Mode Clock Gating
                                            // Control
#define SYSCTL_DCGCEPI          0x400FE810  // EPI Deep-Sleep Mode Clock Gating
                                            // Control
#define SYSCTL_DCGCHIB          0x400FE814  // Hibernation Deep-Sleep Mode
                                            // Clock Gating Control
#define SYSCTL_DCGCUART         0x400FE818  // Universal Asynchronous
                                            // Receiver/Transmitter Deep-Sleep
                                            // Mode Clock Gating Control
#define SYSCTL_DCGCSSI          0x400FE81C  // Synchronous Serial Interface
                                            // Deep-Sleep Mode Clock Gating
                                            // Control
#define SYSCTL_DCGCI2C          0x400FE820  // Inter-Integrated Circuit
                                            // Deep-Sleep Mode Clock Gating
                                            // Control
#define SYSCTL_DCGCUSB          0x400FE828  // Universal Serial Bus Deep-Sleep
                                            // Mode Clock Gating Control
#define SYSCTL_DCGCEPHY         0x400FE830  // Ethernet PHY Deep-Sleep Mode
                                            // Clock Gating Control
#define SYSCTL_DCGCCAN          0x400FE834  // Controller Area Network
                                            // Deep-Sleep Mode Clock Gating
                                            // Control
#define SYSCTL_DCGCADC          0x400FE838  // Analog-to-Digital Converter
                                            // Deep-Sleep Mode Clock Gating
                                            // Control
#define SYSCTL_DCGCACMP         0x400FE83C  // Analog Comparator Deep-Sleep
                                            // Mode Clock Gating Control
#define SYSCTL_DCGCPWM          0x400FE840  // Pulse Width Modulator Deep-Sleep
                                            // Mode Clock Gating Control
#define SYSCTL_DCGCQEI          0x400FE844  // Quadrature Encoder Interface
                                            // Deep-Sleep Mode Clock Gating
                                            // Control
#define SYSCTL_DCGCEEPROM       0x400FE858  // EEPROM Deep-Sleep Mode Clock
                                            // Gating Control
#define SYSCTL_DCGCWTIMER       0x400FE85C  // Wide Timer Deep-Sleep Mode Clock
                                            // Gating Control
#define SYSCTL_DCGCCCM          0x400FE874  // CRC and Cryptographic Modules
                                            // Deep-Sleep Mode Clock Gating
                                            // Control
#define SYSCTL_DCGCLCD          0x400FE890  // LCD Controller Deep-Sleep Mode
                                            // Clock Gating Control
#define SYSCTL_DCGCOWIRE        0x400FE898  // One-Wire Deep-Sleep Mode Clock
                                            // Gating Control
#define SYSCTL_DCGCEMAC         0x400FE89C  // Ethernet MAC Deep-Sleep Mode
                                            // Clock Gating Control
#define SYSCTL_PCWD             0x400FE900  // Watchdog Timer Power Control
#define SYSCTL_PCTIMER          0x400FE904  // 16/32-Bit General-Purpose Timer
                                            // Power Control
#define SYSCTL_PCGPIO           0x400FE908  // General-Purpose Input/Output
                                            // Power Control
#define SYSCTL_PCDMA            0x400FE90C  // Micro Direct Memory Access Power
                                            // Control
#define SYSCTL_PCEPI            0x400FE910  // External Peripheral Interface
                                            // Power Control
#define SYSCTL_PCHIB            0x400FE914  // Hibernation Power Control
#define SYSCTL_PCUART           0x400FE918  // Universal Asynchronous
                                            // Receiver/Transmitter Power
                                            // Control
#define SYSCTL_PCSSI            0x400FE91C  // Synchronous Serial Interface
                                            // Power Control
#define SYSCTL_PCI2C            0x400FE920  // Inter-Integrated Circuit Power
                                            // Control
#define SYSCTL_PCUSB            0x400FE928  // Universal Serial Bus Power
                                            // Control
#define SYSCTL_PCEPHY           0x400FE930  // Ethernet PHY Power Control
#define SYSCTL_PCCAN            0x400FE934  // Controller Area Network Power
                                            // Control
#define SYSCTL_PCADC            0x400FE938  // Analog-to-Digital Converter
                                            // Power Control
#define SYSCTL_PCACMP           0x400FE93C  // Analog Comparator Power Control
#define SYSCTL_PCPWM            0x400FE940  // Pulse Width Modulator Power
                                            // Control
#define SYSCTL_PCQEI            0x400FE944  // Quadrature Encoder Interface
                                            // Power Control
#define SYSCTL_PCEEPROM         0x400FE958  // EEPROM Power Control
#define SYSCTL_PCCCM            0x400FE974  // CRC and Cryptographic Modules
                                            // Power Control
#define SYSCTL_PCLCD            0x400FE990  // LCD Controller Power Control
#define SYSCTL_PCOWIRE          0x400FE998  // 1-Wire Power Control
#define SYSCTL_PCEMAC           0x400FE99C  // Ethernet MAC Power Control
#define SYSCTL_PRWD             0x400FEA00  // Watchdog Timer Peripheral Ready
#define SYSCTL_PRTIMER          0x400FEA04  // Timer Peripheral Ready
#define SYSCTL_PRGPIO           0x400FEA08  // General-Purpose Input/Output
                                            // Peripheral Ready
#define SYSCTL_PRDMA            0x400FEA0C  // Micro Direct Memory Access
                                            // Peripheral Ready
#define SYSCTL_PREPI            0x400FEA10  // EPI Peripheral Ready
#define SYSCTL_PRHIB            0x400FEA14  // Hibernation Peripheral Ready
#define SYSCTL_PRUART           0x400FEA18  // Universal Asynchronous
                                            // Receiver/Transmitter Peripheral
                                            // Ready
#define SYSCTL_PRSSI            0x400FEA1C  // Synchronous Serial Interface
                                            // Peripheral Ready
#define SYSCTL_PRI2C            0x400FEA20  // Inter-Integrated Circuit
                                            // Peripheral Ready
#define SYSCTL_PRUSB            0x400FEA28  // Universal Serial Bus Peripheral
                                            // Ready
#define SYSCTL_PREPHY           0x400FEA30  // Ethernet PHY Peripheral Ready
#define SYSCTL_PRCAN            0x400FEA34  // Controller Area Network
                                            // Peripheral Ready
#define SYSCTL_PRADC            0x400FEA38  // Analog-to-Digital Converter
                                            // Peripheral Ready
#define SYSCTL_PRACMP           0x400FEA3C  // Analog Comparator Peripheral
                                            // Ready
#define SYSCTL_PRPWM            0x400FEA40  // Pulse Width Modulator Peripheral
                                            // Ready
#define SYSCTL_PRQEI            0x400FEA44  // Quadrature Encoder Interface
                                            // Peripheral Ready
#define SYSCTL_PREEPROM         0x400FEA58  // EEPROM Peripheral Ready
#define SYSCTL_PRWTIMER         0x400FEA5C  // Wide Timer Peripheral Ready
#define SYSCTL_PRCCM            0x400FEA74  // CRC and Cryptographic Modules
                                            // Peripheral Ready
#define SYSCTL_PRLCD            0x400FEA90  // LCD Controller Peripheral Ready
#define SYSCTL_PROWIRE          0x400FEA98  // One-Wire Peripheral Ready
#define SYSCTL_PREMAC           0x400FEA9C  // Ethernet MAC Peripheral Ready
#define SYSCTL_CCMCGREQ         0x44030204  // Cryptographic Modules Clock
                                            // Gating Request

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_DID0 register.
//
//*****************************************************************************
#define SYSCTL_DID0_VER_M       0x70000000  // DID0 Version
#define SYSCTL_DID0_VER_1       0x10000000  // Second version of the DID0
                                            // register format
#define SYSCTL_DID0_CLASS_M     0x00FF0000  // Device Class
#define SYSCTL_DID0_CLASS_BLIZZARD                                            \
                                0x00050000  // Tiva(TM) C Series Blizzard-class
                                            // microcontrollers
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
#define SYSCTL_DID1_PRTNO_TM4C1230C3PM                                        \
                                0x00220000  // TM4C1230C3PM
#define SYSCTL_DID1_PRTNO_TM4C1230D5PM                                        \
                                0x00230000  // TM4C1230D5PM
#define SYSCTL_DID1_PRTNO_TM4C1230E6PM                                        \
                                0x00200000  // TM4C1230E6PM
#define SYSCTL_DID1_PRTNO_TM4C1230H6PM                                        \
                                0x00210000  // TM4C1230H6PM
#define SYSCTL_DID1_PRTNO_TM4C1231C3PM                                        \
                                0x00180000  // TM4C1231C3PM
#define SYSCTL_DID1_PRTNO_TM4C1231D5PM                                        \
                                0x00190000  // TM4C1231D5PM
#define SYSCTL_DID1_PRTNO_TM4C1231D5PZ                                        \
                                0x00360000  // TM4C1231D5PZ
#define SYSCTL_DID1_PRTNO_TM4C1231E6PM                                        \
                                0x00100000  // TM4C1231E6PM
#define SYSCTL_DID1_PRTNO_TM4C1231E6PZ                                        \
                                0x00300000  // TM4C1231E6PZ
#define SYSCTL_DID1_PRTNO_TM4C1231H6PGE                                       \
                                0x00350000  // TM4C1231H6PGE
#define SYSCTL_DID1_PRTNO_TM4C1231H6PM                                        \
                                0x00110000  // TM4C1231H6PM
#define SYSCTL_DID1_PRTNO_TM4C1231H6PZ                                        \
                                0x00310000  // TM4C1231H6PZ
#define SYSCTL_DID1_PRTNO_TM4C1232C3PM                                        \
                                0x00080000  // TM4C1232C3PM
#define SYSCTL_DID1_PRTNO_TM4C1232D5PM                                        \
                                0x00090000  // TM4C1232D5PM
#define SYSCTL_DID1_PRTNO_TM4C1232E6PM                                        \
                                0x000A0000  // TM4C1232E6PM
#define SYSCTL_DID1_PRTNO_TM4C1232H6PM                                        \
                                0x000B0000  // TM4C1232H6PM
#define SYSCTL_DID1_PRTNO_TM4C1233C3PM                                        \
                                0x00010000  // TM4C1233C3PM
#define SYSCTL_DID1_PRTNO_TM4C1233D5PM                                        \
                                0x00020000  // TM4C1233D5PM
#define SYSCTL_DID1_PRTNO_TM4C1233D5PZ                                        \
                                0x00D00000  // TM4C1233D5PZ
#define SYSCTL_DID1_PRTNO_TM4C1233E6PM                                        \
                                0x00030000  // TM4C1233E6PM
#define SYSCTL_DID1_PRTNO_TM4C1233E6PZ                                        \
                                0x00D10000  // TM4C1233E6PZ
#define SYSCTL_DID1_PRTNO_TM4C1233H6PGE                                       \
                                0x00D60000  // TM4C1233H6PGE
#define SYSCTL_DID1_PRTNO_TM4C1233H6PM                                        \
                                0x00040000  // TM4C1233H6PM
#define SYSCTL_DID1_PRTNO_TM4C1233H6PZ                                        \
                                0x00D20000  // TM4C1233H6PZ
#define SYSCTL_DID1_PRTNO_TM4C1236D5PM                                        \
                                0x00520000  // TM4C1236D5PM
#define SYSCTL_DID1_PRTNO_TM4C1236E6PM                                        \
                                0x00500000  // TM4C1236E6PM
#define SYSCTL_DID1_PRTNO_TM4C1236H6PM                                        \
                                0x00510000  // TM4C1236H6PM
#define SYSCTL_DID1_PRTNO_TM4C1237D5PM                                        \
                                0x00480000  // TM4C1237D5PM
#define SYSCTL_DID1_PRTNO_TM4C1237D5PZ                                        \
                                0x00660000  // TM4C1237D5PZ
#define SYSCTL_DID1_PRTNO_TM4C1237E6PM                                        \
                                0x00400000  // TM4C1237E6PM
#define SYSCTL_DID1_PRTNO_TM4C1237E6PZ                                        \
                                0x00600000  // TM4C1237E6PZ
#define SYSCTL_DID1_PRTNO_TM4C1237H6PGE                                       \
                                0x00650000  // TM4C1237H6PGE
#define SYSCTL_DID1_PRTNO_TM4C1237H6PM                                        \
                                0x00410000  // TM4C1237H6PM
#define SYSCTL_DID1_PRTNO_TM4C1237H6PZ                                        \
                                0x00610000  // TM4C1237H6PZ
#define SYSCTL_DID1_PRTNO_TM4C123AE6PM                                        \
                                0x00800000  // TM4C123AE6PM
#define SYSCTL_DID1_PRTNO_TM4C123AH6PM                                        \
                                0x00830000  // TM4C123AH6PM
#define SYSCTL_DID1_PRTNO_TM4C123BE6PM                                        \
                                0x00700000  // TM4C123BE6PM
#define SYSCTL_DID1_PRTNO_TM4C123BE6PZ                                        \
                                0x00C30000  // TM4C123BE6PZ
#define SYSCTL_DID1_PRTNO_TM4C123BH6PGE                                       \
                                0x00C60000  // TM4C123BH6PGE
#define SYSCTL_DID1_PRTNO_TM4C123BH6PM                                        \
                                0x00730000  // TM4C123BH6PM
#define SYSCTL_DID1_PRTNO_TM4C123BH6PZ                                        \
                                0x00C40000  // TM4C123BH6PZ
#define SYSCTL_DID1_PRTNO_TM4C123BH6ZRB                                       \
                                0x00E90000  // TM4C123BH6ZRB
#define SYSCTL_DID1_PRTNO_TM4C123FE6PM                                        \
                                0x00B00000  // TM4C123FE6PM
#define SYSCTL_DID1_PRTNO_TM4C123FH6PM                                        \
                                0x00B10000  // TM4C123FH6PM
#define SYSCTL_DID1_PRTNO_TM4C123GE6PM                                        \
                                0x00A00000  // TM4C123GE6PM
#define SYSCTL_DID1_PRTNO_TM4C123GE6PZ                                        \
                                0x00C00000  // TM4C123GE6PZ
#define SYSCTL_DID1_PRTNO_TM4C123GH6PGE                                       \
                                0x00C50000  // TM4C123GH6PGE
#define SYSCTL_DID1_PRTNO_TM4C123GH6PM                                        \
                                0x00A10000  // TM4C123GH6PM
#define SYSCTL_DID1_PRTNO_TM4C123GH6PZ                                        \
                                0x00C10000  // TM4C123GH6PZ
#define SYSCTL_DID1_PRTNO_TM4C123GH6ZRB                                       \
                                0x00E30000  // TM4C123GH6ZRB
#define SYSCTL_DID1_PRTNO_TM4C1290NCPDT                                       \
                                0x00190000  // TM4C1290NCPDT
#define SYSCTL_DID1_PRTNO_TM4C1290NCZAD                                       \
                                0x001B0000  // TM4C1290NCZAD
#define SYSCTL_DID1_PRTNO_TM4C1292NCPDT                                       \
                                0x001C0000  // TM4C1292NCPDT
#define SYSCTL_DID1_PRTNO_TM4C1292NCZAD                                       \
                                0x001E0000  // TM4C1292NCZAD
#define SYSCTL_DID1_PRTNO_TM4C1294NCPDT                                       \
                                0x001F0000  // TM4C1294NCPDT
#define SYSCTL_DID1_PRTNO_TM4C1294NCZAD                                       \
                                0x00210000  // TM4C1294NCZAD
#define SYSCTL_DID1_PRTNO_TM4C129CNCPDT                                       \
                                0x00240000  // TM4C129CNCPDT
#define SYSCTL_DID1_PRTNO_TM4C129CNCZAD                                       \
                                0x00260000  // TM4C129CNCZAD
#define SYSCTL_DID1_PRTNO_TM4C129DNCPDT                                       \
                                0x00270000  // TM4C129DNCPDT
#define SYSCTL_DID1_PRTNO_TM4C129DNCZAD                                       \
                                0x00290000  // TM4C129DNCZAD
#define SYSCTL_DID1_PRTNO_TM4C129ENCPDT                                       \
                                0x002D0000  // TM4C129ENCPDT
#define SYSCTL_DID1_PRTNO_TM4C129ENCZAD                                       \
                                0x002F0000  // TM4C129ENCZAD
#define SYSCTL_DID1_PRTNO_TM4C129XNCZAD                                       \
                                0x00320000  // TM4C129XNCZAD
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
#define SYSCTL_DID1_TEMP_IE     0x00000060  // Available in both industrial
                                            // temperature range (-40C to 85C)
                                            // and extended temperature range
                                            // (-40C to 105C) devices. See
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
// The following are defines for the bit fields in the SYSCTL_DC0 register.
//
//*****************************************************************************
#define SYSCTL_DC0_SRAMSZ_M     0xFFFF0000  // SRAM Size
#define SYSCTL_DC0_SRAMSZ_2KB   0x00070000  // 2 KB of SRAM
#define SYSCTL_DC0_SRAMSZ_4KB   0x000F0000  // 4 KB of SRAM
#define SYSCTL_DC0_SRAMSZ_6KB   0x00170000  // 6 KB of SRAM
#define SYSCTL_DC0_SRAMSZ_8KB   0x001F0000  // 8 KB of SRAM
#define SYSCTL_DC0_SRAMSZ_12KB  0x002F0000  // 12 KB of SRAM
#define SYSCTL_DC0_SRAMSZ_16KB  0x003F0000  // 16 KB of SRAM
#define SYSCTL_DC0_SRAMSZ_20KB  0x004F0000  // 20 KB of SRAM
#define SYSCTL_DC0_SRAMSZ_24KB  0x005F0000  // 24 KB of SRAM
#define SYSCTL_DC0_SRAMSZ_32KB  0x007F0000  // 32 KB of SRAM
#define SYSCTL_DC0_FLASHSZ_M    0x0000FFFF  // Flash Size
#define SYSCTL_DC0_FLASHSZ_8KB  0x00000003  // 8 KB of Flash
#define SYSCTL_DC0_FLASHSZ_16KB 0x00000007  // 16 KB of Flash
#define SYSCTL_DC0_FLASHSZ_32KB 0x0000000F  // 32 KB of Flash
#define SYSCTL_DC0_FLASHSZ_64KB 0x0000001F  // 64 KB of Flash
#define SYSCTL_DC0_FLASHSZ_96KB 0x0000002F  // 96 KB of Flash
#define SYSCTL_DC0_FLASHSZ_128K 0x0000003F  // 128 KB of Flash
#define SYSCTL_DC0_FLASHSZ_192K 0x0000005F  // 192 KB of Flash
#define SYSCTL_DC0_FLASHSZ_256K 0x0000007F  // 256 KB of Flash

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_DC1 register.
//
//*****************************************************************************
#define SYSCTL_DC1_WDT1         0x10000000  // Watchdog Timer1 Present
#define SYSCTL_DC1_CAN1         0x02000000  // CAN Module 1 Present
#define SYSCTL_DC1_CAN0         0x01000000  // CAN Module 0 Present
#define SYSCTL_DC1_PWM1         0x00200000  // PWM Module 1 Present
#define SYSCTL_DC1_PWM0         0x00100000  // PWM Module 0 Present
#define SYSCTL_DC1_ADC1         0x00020000  // ADC Module 1 Present
#define SYSCTL_DC1_ADC0         0x00010000  // ADC Module 0 Present
#define SYSCTL_DC1_MINSYSDIV_M  0x0000F000  // System Clock Divider
#define SYSCTL_DC1_MINSYSDIV_100                                              \
                                0x00001000  // Divide VCO (400MHZ) by 5 minimum
#define SYSCTL_DC1_MINSYSDIV_66 0x00002000  // Divide VCO (400MHZ) by 2*2 + 2 =
                                            // 6 minimum
#define SYSCTL_DC1_MINSYSDIV_50 0x00003000  // Specifies a 50-MHz CPU clock
                                            // with a PLL divider of 4
#define SYSCTL_DC1_MINSYSDIV_40 0x00004000  // Specifies a 40-MHz CPU clock
                                            // with a PLL divider of 5
#define SYSCTL_DC1_MINSYSDIV_25 0x00007000  // Specifies a 25-MHz clock with a
                                            // PLL divider of 8
#define SYSCTL_DC1_MINSYSDIV_20 0x00009000  // Specifies a 20-MHz clock with a
                                            // PLL divider of 10
#define SYSCTL_DC1_ADC1SPD_M    0x00000C00  // Max ADC1 Speed
#define SYSCTL_DC1_ADC1SPD_125K 0x00000000  // 125K samples/second
#define SYSCTL_DC1_ADC1SPD_250K 0x00000400  // 250K samples/second
#define SYSCTL_DC1_ADC1SPD_500K 0x00000800  // 500K samples/second
#define SYSCTL_DC1_ADC1SPD_1M   0x00000C00  // 1M samples/second
#define SYSCTL_DC1_ADC0SPD_M    0x00000300  // Max ADC0 Speed
#define SYSCTL_DC1_ADC0SPD_125K 0x00000000  // 125K samples/second
#define SYSCTL_DC1_ADC0SPD_250K 0x00000100  // 250K samples/second
#define SYSCTL_DC1_ADC0SPD_500K 0x00000200  // 500K samples/second
#define SYSCTL_DC1_ADC0SPD_1M   0x00000300  // 1M samples/second
#define SYSCTL_DC1_MPU          0x00000080  // MPU Present
#define SYSCTL_DC1_HIB          0x00000040  // Hibernation Module Present
#define SYSCTL_DC1_TEMP         0x00000020  // Temp Sensor Present
#define SYSCTL_DC1_PLL          0x00000010  // PLL Present
#define SYSCTL_DC1_WDT0         0x00000008  // Watchdog Timer 0 Present
#define SYSCTL_DC1_SWO          0x00000004  // SWO Trace Port Present
#define SYSCTL_DC1_SWD          0x00000002  // SWD Present
#define SYSCTL_DC1_JTAG         0x00000001  // JTAG Present

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_DC2 register.
//
//*****************************************************************************
#define SYSCTL_DC2_EPI0         0x40000000  // EPI Module 0 Present
#define SYSCTL_DC2_I2S0         0x10000000  // I2S Module 0 Present
#define SYSCTL_DC2_COMP2        0x04000000  // Analog Comparator 2 Present
#define SYSCTL_DC2_COMP1        0x02000000  // Analog Comparator 1 Present
#define SYSCTL_DC2_COMP0        0x01000000  // Analog Comparator 0 Present
#define SYSCTL_DC2_TIMER3       0x00080000  // Timer Module 3 Present
#define SYSCTL_DC2_TIMER2       0x00040000  // Timer Module 2 Present
#define SYSCTL_DC2_TIMER1       0x00020000  // Timer Module 1 Present
#define SYSCTL_DC2_TIMER0       0x00010000  // Timer Module 0 Present
#define SYSCTL_DC2_I2C1HS       0x00008000  // I2C Module 1 Speed
#define SYSCTL_DC2_I2C1         0x00004000  // I2C Module 1 Present
#define SYSCTL_DC2_I2C0HS       0x00002000  // I2C Module 0 Speed
#define SYSCTL_DC2_I2C0         0x00001000  // I2C Module 0 Present
#define SYSCTL_DC2_QEI1         0x00000200  // QEI Module 1 Present
#define SYSCTL_DC2_QEI0         0x00000100  // QEI Module 0 Present
#define SYSCTL_DC2_SSI1         0x00000020  // SSI Module 1 Present
#define SYSCTL_DC2_SSI0         0x00000010  // SSI Module 0 Present
#define SYSCTL_DC2_UART2        0x00000004  // UART Module 2 Present
#define SYSCTL_DC2_UART1        0x00000002  // UART Module 1 Present
#define SYSCTL_DC2_UART0        0x00000001  // UART Module 0 Present

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_DC3 register.
//
//*****************************************************************************
#define SYSCTL_DC3_32KHZ        0x80000000  // 32KHz Input Clock Available
#define SYSCTL_DC3_CCP5         0x20000000  // CCP5 Pin Present
#define SYSCTL_DC3_CCP4         0x10000000  // CCP4 Pin Present
#define SYSCTL_DC3_CCP3         0x08000000  // CCP3 Pin Present
#define SYSCTL_DC3_CCP2         0x04000000  // CCP2 Pin Present
#define SYSCTL_DC3_CCP1         0x02000000  // CCP1 Pin Present
#define SYSCTL_DC3_CCP0         0x01000000  // CCP0 Pin Present
#define SYSCTL_DC3_ADC0AIN7     0x00800000  // ADC Module 0 AIN7 Pin Present
#define SYSCTL_DC3_ADC0AIN6     0x00400000  // ADC Module 0 AIN6 Pin Present
#define SYSCTL_DC3_ADC0AIN5     0x00200000  // ADC Module 0 AIN5 Pin Present
#define SYSCTL_DC3_ADC0AIN4     0x00100000  // ADC Module 0 AIN4 Pin Present
#define SYSCTL_DC3_ADC0AIN3     0x00080000  // ADC Module 0 AIN3 Pin Present
#define SYSCTL_DC3_ADC0AIN2     0x00040000  // ADC Module 0 AIN2 Pin Present
#define SYSCTL_DC3_ADC0AIN1     0x00020000  // ADC Module 0 AIN1 Pin Present
#define SYSCTL_DC3_ADC0AIN0     0x00010000  // ADC Module 0 AIN0 Pin Present
#define SYSCTL_DC3_PWMFAULT     0x00008000  // PWM Fault Pin Present
#define SYSCTL_DC3_C2O          0x00004000  // C2o Pin Present
#define SYSCTL_DC3_C2PLUS       0x00002000  // C2+ Pin Present
#define SYSCTL_DC3_C2MINUS      0x00001000  // C2- Pin Present
#define SYSCTL_DC3_C1O          0x00000800  // C1o Pin Present
#define SYSCTL_DC3_C1PLUS       0x00000400  // C1+ Pin Present
#define SYSCTL_DC3_C1MINUS      0x00000200  // C1- Pin Present
#define SYSCTL_DC3_C0O          0x00000100  // C0o Pin Present
#define SYSCTL_DC3_C0PLUS       0x00000080  // C0+ Pin Present
#define SYSCTL_DC3_C0MINUS      0x00000040  // C0- Pin Present
#define SYSCTL_DC3_PWM5         0x00000020  // PWM5 Pin Present
#define SYSCTL_DC3_PWM4         0x00000010  // PWM4 Pin Present
#define SYSCTL_DC3_PWM3         0x00000008  // PWM3 Pin Present
#define SYSCTL_DC3_PWM2         0x00000004  // PWM2 Pin Present
#define SYSCTL_DC3_PWM1         0x00000002  // PWM1 Pin Present
#define SYSCTL_DC3_PWM0         0x00000001  // PWM0 Pin Present

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_DC4 register.
//
//*****************************************************************************
#define SYSCTL_DC4_EPHY0        0x40000000  // Ethernet PHY Layer 0 Present
#define SYSCTL_DC4_EMAC0        0x10000000  // Ethernet MAC Layer 0 Present
#define SYSCTL_DC4_E1588        0x01000000  // 1588 Capable
#define SYSCTL_DC4_PICAL        0x00040000  // PIOSC Calibrate
#define SYSCTL_DC4_CCP7         0x00008000  // CCP7 Pin Present
#define SYSCTL_DC4_CCP6         0x00004000  // CCP6 Pin Present
#define SYSCTL_DC4_UDMA         0x00002000  // Micro-DMA Module Present
#define SYSCTL_DC4_ROM          0x00001000  // Internal Code ROM Present
#define SYSCTL_DC4_GPIOJ        0x00000100  // GPIO Port J Present
#define SYSCTL_DC4_GPIOH        0x00000080  // GPIO Port H Present
#define SYSCTL_DC4_GPIOG        0x00000040  // GPIO Port G Present
#define SYSCTL_DC4_GPIOF        0x00000020  // GPIO Port F Present
#define SYSCTL_DC4_GPIOE        0x00000010  // GPIO Port E Present
#define SYSCTL_DC4_GPIOD        0x00000008  // GPIO Port D Present
#define SYSCTL_DC4_GPIOC        0x00000004  // GPIO Port C Present
#define SYSCTL_DC4_GPIOB        0x00000002  // GPIO Port B Present
#define SYSCTL_DC4_GPIOA        0x00000001  // GPIO Port A Present

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_DC5 register.
//
//*****************************************************************************
#define SYSCTL_DC5_PWMFAULT3    0x08000000  // PWM Fault 3 Pin Present
#define SYSCTL_DC5_PWMFAULT2    0x04000000  // PWM Fault 2 Pin Present
#define SYSCTL_DC5_PWMFAULT1    0x02000000  // PWM Fault 1 Pin Present
#define SYSCTL_DC5_PWMFAULT0    0x01000000  // PWM Fault 0 Pin Present
#define SYSCTL_DC5_PWMEFLT      0x00200000  // PWM Extended Fault Active
#define SYSCTL_DC5_PWMESYNC     0x00100000  // PWM Extended SYNC Active
#define SYSCTL_DC5_PWM7         0x00000080  // PWM7 Pin Present
#define SYSCTL_DC5_PWM6         0x00000040  // PWM6 Pin Present
#define SYSCTL_DC5_PWM5         0x00000020  // PWM5 Pin Present
#define SYSCTL_DC5_PWM4         0x00000010  // PWM4 Pin Present
#define SYSCTL_DC5_PWM3         0x00000008  // PWM3 Pin Present
#define SYSCTL_DC5_PWM2         0x00000004  // PWM2 Pin Present
#define SYSCTL_DC5_PWM1         0x00000002  // PWM1 Pin Present
#define SYSCTL_DC5_PWM0         0x00000001  // PWM0 Pin Present

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_DC6 register.
//
//*****************************************************************************
#define SYSCTL_DC6_USB0PHY      0x00000010  // USB Module 0 PHY Present
#define SYSCTL_DC6_USB0_M       0x00000003  // USB Module 0 Present
#define SYSCTL_DC6_USB0_DEV     0x00000001  // USB0 is Device Only
#define SYSCTL_DC6_USB0_HOSTDEV 0x00000002  // USB is Device or Host
#define SYSCTL_DC6_USB0_OTG     0x00000003  // USB0 is OTG

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_DC7 register.
//
//*****************************************************************************
#define SYSCTL_DC7_DMACH30      0x40000000  // SW
#define SYSCTL_DC7_DMACH29      0x20000000  // I2S0_TX / CAN1_TX
#define SYSCTL_DC7_DMACH28      0x10000000  // I2S0_RX / CAN1_RX
#define SYSCTL_DC7_DMACH27      0x08000000  // CAN1_TX / ADC1_SS3
#define SYSCTL_DC7_DMACH26      0x04000000  // CAN1_RX / ADC1_SS2
#define SYSCTL_DC7_DMACH25      0x02000000  // SSI1_TX / ADC1_SS1
#define SYSCTL_DC7_DMACH24      0x01000000  // SSI1_RX / ADC1_SS0
#define SYSCTL_DC7_DMACH23      0x00800000  // UART1_TX / CAN2_TX
#define SYSCTL_DC7_DMACH22      0x00400000  // UART1_RX / CAN2_RX
#define SYSCTL_DC7_DMACH21      0x00200000  // Timer1B / EPI0_WFIFO
#define SYSCTL_DC7_DMACH20      0x00100000  // Timer1A / EPI0_NBRFIFO
#define SYSCTL_DC7_DMACH19      0x00080000  // Timer0B / Timer1B
#define SYSCTL_DC7_DMACH18      0x00040000  // Timer0A / Timer1A
#define SYSCTL_DC7_DMACH17      0x00020000  // ADC0_SS3
#define SYSCTL_DC7_DMACH16      0x00010000  // ADC0_SS2
#define SYSCTL_DC7_DMACH15      0x00008000  // ADC0_SS1 / Timer2B
#define SYSCTL_DC7_DMACH14      0x00004000  // ADC0_SS0 / Timer2A
#define SYSCTL_DC7_DMACH13      0x00002000  // CAN0_TX / UART2_TX
#define SYSCTL_DC7_DMACH12      0x00001000  // CAN0_RX / UART2_RX
#define SYSCTL_DC7_DMACH11      0x00000800  // SSI0_TX / SSI1_TX
#define SYSCTL_DC7_DMACH10      0x00000400  // SSI0_RX / SSI1_RX
#define SYSCTL_DC7_DMACH9       0x00000200  // UART0_TX / UART1_TX
#define SYSCTL_DC7_DMACH8       0x00000100  // UART0_RX / UART1_RX
#define SYSCTL_DC7_DMACH7       0x00000080  // ETH_TX / Timer2B
#define SYSCTL_DC7_DMACH6       0x00000040  // ETH_RX / Timer2A
#define SYSCTL_DC7_DMACH5       0x00000020  // USB_EP3_TX / Timer2B
#define SYSCTL_DC7_DMACH4       0x00000010  // USB_EP3_RX / Timer2A
#define SYSCTL_DC7_DMACH3       0x00000008  // USB_EP2_TX / Timer3B
#define SYSCTL_DC7_DMACH2       0x00000004  // USB_EP2_RX / Timer3A
#define SYSCTL_DC7_DMACH1       0x00000002  // USB_EP1_TX / UART2_TX
#define SYSCTL_DC7_DMACH0       0x00000001  // USB_EP1_RX / UART2_RX

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_DC8 register.
//
//*****************************************************************************
#define SYSCTL_DC8_ADC1AIN15    0x80000000  // ADC Module 1 AIN15 Pin Present
#define SYSCTL_DC8_ADC1AIN14    0x40000000  // ADC Module 1 AIN14 Pin Present
#define SYSCTL_DC8_ADC1AIN13    0x20000000  // ADC Module 1 AIN13 Pin Present
#define SYSCTL_DC8_ADC1AIN12    0x10000000  // ADC Module 1 AIN12 Pin Present
#define SYSCTL_DC8_ADC1AIN11    0x08000000  // ADC Module 1 AIN11 Pin Present
#define SYSCTL_DC8_ADC1AIN10    0x04000000  // ADC Module 1 AIN10 Pin Present
#define SYSCTL_DC8_ADC1AIN9     0x02000000  // ADC Module 1 AIN9 Pin Present
#define SYSCTL_DC8_ADC1AIN8     0x01000000  // ADC Module 1 AIN8 Pin Present
#define SYSCTL_DC8_ADC1AIN7     0x00800000  // ADC Module 1 AIN7 Pin Present
#define SYSCTL_DC8_ADC1AIN6     0x00400000  // ADC Module 1 AIN6 Pin Present
#define SYSCTL_DC8_ADC1AIN5     0x00200000  // ADC Module 1 AIN5 Pin Present
#define SYSCTL_DC8_ADC1AIN4     0x00100000  // ADC Module 1 AIN4 Pin Present
#define SYSCTL_DC8_ADC1AIN3     0x00080000  // ADC Module 1 AIN3 Pin Present
#define SYSCTL_DC8_ADC1AIN2     0x00040000  // ADC Module 1 AIN2 Pin Present
#define SYSCTL_DC8_ADC1AIN1     0x00020000  // ADC Module 1 AIN1 Pin Present
#define SYSCTL_DC8_ADC1AIN0     0x00010000  // ADC Module 1 AIN0 Pin Present
#define SYSCTL_DC8_ADC0AIN15    0x00008000  // ADC Module 0 AIN15 Pin Present
#define SYSCTL_DC8_ADC0AIN14    0x00004000  // ADC Module 0 AIN14 Pin Present
#define SYSCTL_DC8_ADC0AIN13    0x00002000  // ADC Module 0 AIN13 Pin Present
#define SYSCTL_DC8_ADC0AIN12    0x00001000  // ADC Module 0 AIN12 Pin Present
#define SYSCTL_DC8_ADC0AIN11    0x00000800  // ADC Module 0 AIN11 Pin Present
#define SYSCTL_DC8_ADC0AIN10    0x00000400  // ADC Module 0 AIN10 Pin Present
#define SYSCTL_DC8_ADC0AIN9     0x00000200  // ADC Module 0 AIN9 Pin Present
#define SYSCTL_DC8_ADC0AIN8     0x00000100  // ADC Module 0 AIN8 Pin Present
#define SYSCTL_DC8_ADC0AIN7     0x00000080  // ADC Module 0 AIN7 Pin Present
#define SYSCTL_DC8_ADC0AIN6     0x00000040  // ADC Module 0 AIN6 Pin Present
#define SYSCTL_DC8_ADC0AIN5     0x00000020  // ADC Module 0 AIN5 Pin Present
#define SYSCTL_DC8_ADC0AIN4     0x00000010  // ADC Module 0 AIN4 Pin Present
#define SYSCTL_DC8_ADC0AIN3     0x00000008  // ADC Module 0 AIN3 Pin Present
#define SYSCTL_DC8_ADC0AIN2     0x00000004  // ADC Module 0 AIN2 Pin Present
#define SYSCTL_DC8_ADC0AIN1     0x00000002  // ADC Module 0 AIN1 Pin Present
#define SYSCTL_DC8_ADC0AIN0     0x00000001  // ADC Module 0 AIN0 Pin Present

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PBORCTL register.
//
//*****************************************************************************
#define SYSCTL_PBORCTL_BOR0     0x00000004  // VDD under BOR0 Event Action
#define SYSCTL_PBORCTL_BOR1     0x00000002  // VDD under BOR1 Event Action

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
// The following are defines for the bit fields in the SYSCTL_SRCR0 register.
//
//*****************************************************************************
#define SYSCTL_SRCR0_WDT1       0x10000000  // WDT1 Reset Control
#define SYSCTL_SRCR0_CAN1       0x02000000  // CAN1 Reset Control
#define SYSCTL_SRCR0_CAN0       0x01000000  // CAN0 Reset Control
#define SYSCTL_SRCR0_PWM0       0x00100000  // PWM Reset Control
#define SYSCTL_SRCR0_ADC1       0x00020000  // ADC1 Reset Control
#define SYSCTL_SRCR0_ADC0       0x00010000  // ADC0 Reset Control
#define SYSCTL_SRCR0_HIB        0x00000040  // HIB Reset Control
#define SYSCTL_SRCR0_WDT0       0x00000008  // WDT0 Reset Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_SRCR1 register.
//
//*****************************************************************************
#define SYSCTL_SRCR1_COMP2      0x04000000  // Analog Comp 2 Reset Control
#define SYSCTL_SRCR1_COMP1      0x02000000  // Analog Comp 1 Reset Control
#define SYSCTL_SRCR1_COMP0      0x01000000  // Analog Comp 0 Reset Control
#define SYSCTL_SRCR1_TIMER3     0x00080000  // Timer 3 Reset Control
#define SYSCTL_SRCR1_TIMER2     0x00040000  // Timer 2 Reset Control
#define SYSCTL_SRCR1_TIMER1     0x00020000  // Timer 1 Reset Control
#define SYSCTL_SRCR1_TIMER0     0x00010000  // Timer 0 Reset Control
#define SYSCTL_SRCR1_I2C1       0x00004000  // I2C1 Reset Control
#define SYSCTL_SRCR1_I2C0       0x00001000  // I2C0 Reset Control
#define SYSCTL_SRCR1_QEI1       0x00000200  // QEI1 Reset Control
#define SYSCTL_SRCR1_QEI0       0x00000100  // QEI0 Reset Control
#define SYSCTL_SRCR1_SSI1       0x00000020  // SSI1 Reset Control
#define SYSCTL_SRCR1_SSI0       0x00000010  // SSI0 Reset Control
#define SYSCTL_SRCR1_UART2      0x00000004  // UART2 Reset Control
#define SYSCTL_SRCR1_UART1      0x00000002  // UART1 Reset Control
#define SYSCTL_SRCR1_UART0      0x00000001  // UART0 Reset Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_SRCR2 register.
//
//*****************************************************************************
#define SYSCTL_SRCR2_USB0       0x00010000  // USB0 Reset Control
#define SYSCTL_SRCR2_UDMA       0x00002000  // Micro-DMA Reset Control
#define SYSCTL_SRCR2_GPIOJ      0x00000100  // Port J Reset Control
#define SYSCTL_SRCR2_GPIOH      0x00000080  // Port H Reset Control
#define SYSCTL_SRCR2_GPIOG      0x00000040  // Port G Reset Control
#define SYSCTL_SRCR2_GPIOF      0x00000020  // Port F Reset Control
#define SYSCTL_SRCR2_GPIOE      0x00000010  // Port E Reset Control
#define SYSCTL_SRCR2_GPIOD      0x00000008  // Port D Reset Control
#define SYSCTL_SRCR2_GPIOC      0x00000004  // Port C Reset Control
#define SYSCTL_SRCR2_GPIOB      0x00000002  // Port B Reset Control
#define SYSCTL_SRCR2_GPIOA      0x00000001  // Port A Reset Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_RIS register.
//
//*****************************************************************************
#define SYSCTL_RIS_VDDARIS      0x00000400  // VDDA Power OK Event Raw
                                            // Interrupt Status
#define SYSCTL_RIS_MOSCPUPRIS   0x00000100  // MOSC Power Up Raw Interrupt
                                            // Status
#define SYSCTL_RIS_USBPLLLRIS   0x00000080  // USB PLL Lock Raw Interrupt
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
#define SYSCTL_IMC_VDDAIM       0x00000400  // VDDA Power OK Interrupt Mask
#define SYSCTL_IMC_MOSCPUPIM    0x00000100  // MOSC Power Up Interrupt Mask
#define SYSCTL_IMC_USBPLLLIM    0x00000080  // USB PLL Lock Interrupt Mask
#define SYSCTL_IMC_PLLLIM       0x00000040  // PLL Lock Interrupt Mask
#define SYSCTL_IMC_MOFIM        0x00000008  // Main Oscillator Fault Interrupt
                                            // Mask
#define SYSCTL_IMC_BORIM        0x00000002  // Brown-Out Reset Interrupt Mask

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_MISC register.
//
//*****************************************************************************
#define SYSCTL_MISC_VDDAMIS     0x00000400  // VDDA Power OK Masked Interrupt
                                            // Status
#define SYSCTL_MISC_MOSCPUPMIS  0x00000100  // MOSC Power Up Masked Interrupt
                                            // Status
#define SYSCTL_MISC_USBPLLLMIS  0x00000080  // USB PLL Lock Masked Interrupt
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
// The following are defines for the bit fields in the SYSCTL_RCC register.
//
//*****************************************************************************
#define SYSCTL_RCC_ACG          0x08000000  // Auto Clock Gating
#define SYSCTL_RCC_SYSDIV_M     0x07800000  // System Clock Divisor
#define SYSCTL_RCC_USESYSDIV    0x00400000  // Enable System Clock Divider
#define SYSCTL_RCC_USEPWMDIV    0x00100000  // Enable PWM Clock Divisor
#define SYSCTL_RCC_PWMDIV_M     0x000E0000  // PWM Unit Clock Divisor
#define SYSCTL_RCC_PWMDIV_2     0x00000000  // PWM clock /2
#define SYSCTL_RCC_PWMDIV_4     0x00020000  // PWM clock /4
#define SYSCTL_RCC_PWMDIV_8     0x00040000  // PWM clock /8
#define SYSCTL_RCC_PWMDIV_16    0x00060000  // PWM clock /16
#define SYSCTL_RCC_PWMDIV_32    0x00080000  // PWM clock /32
#define SYSCTL_RCC_PWMDIV_64    0x000A0000  // PWM clock /64
#define SYSCTL_RCC_PWRDN        0x00002000  // PLL Power Down
#define SYSCTL_RCC_BYPASS       0x00000800  // PLL Bypass
#define SYSCTL_RCC_XTAL_M       0x000007C0  // Crystal Value
#define SYSCTL_RCC_XTAL_4MHZ    0x00000180  // 4 MHz
#define SYSCTL_RCC_XTAL_4_09MHZ 0x000001C0  // 4.096 MHz
#define SYSCTL_RCC_XTAL_4_91MHZ 0x00000200  // 4.9152 MHz
#define SYSCTL_RCC_XTAL_5MHZ    0x00000240  // 5 MHz
#define SYSCTL_RCC_XTAL_5_12MHZ 0x00000280  // 5.12 MHz
#define SYSCTL_RCC_XTAL_6MHZ    0x000002C0  // 6 MHz
#define SYSCTL_RCC_XTAL_6_14MHZ 0x00000300  // 6.144 MHz
#define SYSCTL_RCC_XTAL_7_37MHZ 0x00000340  // 7.3728 MHz
#define SYSCTL_RCC_XTAL_8MHZ    0x00000380  // 8 MHz
#define SYSCTL_RCC_XTAL_8_19MHZ 0x000003C0  // 8.192 MHz
#define SYSCTL_RCC_XTAL_10MHZ   0x00000400  // 10 MHz
#define SYSCTL_RCC_XTAL_12MHZ   0x00000440  // 12 MHz
#define SYSCTL_RCC_XTAL_12_2MHZ 0x00000480  // 12.288 MHz
#define SYSCTL_RCC_XTAL_13_5MHZ 0x000004C0  // 13.56 MHz
#define SYSCTL_RCC_XTAL_14_3MHZ 0x00000500  // 14.31818 MHz
#define SYSCTL_RCC_XTAL_16MHZ   0x00000540  // 16 MHz
#define SYSCTL_RCC_XTAL_16_3MHZ 0x00000580  // 16.384 MHz
#define SYSCTL_RCC_XTAL_18MHZ   0x000005C0  // 18.0 MHz
#define SYSCTL_RCC_XTAL_20MHZ   0x00000600  // 20.0 MHz
#define SYSCTL_RCC_XTAL_24MHZ   0x00000640  // 24.0 MHz
#define SYSCTL_RCC_XTAL_25MHZ   0x00000680  // 25.0 MHz
#define SYSCTL_RCC_OSCSRC_M     0x00000030  // Oscillator Source
#define SYSCTL_RCC_OSCSRC_MAIN  0x00000000  // MOSC
#define SYSCTL_RCC_OSCSRC_INT   0x00000010  // IOSC
#define SYSCTL_RCC_OSCSRC_INT4  0x00000020  // IOSC/4
#define SYSCTL_RCC_OSCSRC_30    0x00000030  // 30 kHz
#define SYSCTL_RCC_MOSCDIS      0x00000001  // Main Oscillator Disable
#define SYSCTL_RCC_SYSDIV_S     23
#define SYSCTL_RCC_XTAL_S       6           // Shift to the XTAL field

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
// The following are defines for the bit fields in the SYSCTL_GPIOHBCTL
// register.
//
//*****************************************************************************
#define SYSCTL_GPIOHBCTL_PORTJ  0x00000100  // Port J Advanced High-Performance
                                            // Bus
#define SYSCTL_GPIOHBCTL_PORTH  0x00000080  // Port H Advanced High-Performance
                                            // Bus
#define SYSCTL_GPIOHBCTL_PORTG  0x00000040  // Port G Advanced High-Performance
                                            // Bus
#define SYSCTL_GPIOHBCTL_PORTF  0x00000020  // Port F Advanced High-Performance
                                            // Bus
#define SYSCTL_GPIOHBCTL_PORTE  0x00000010  // Port E Advanced High-Performance
                                            // Bus
#define SYSCTL_GPIOHBCTL_PORTD  0x00000008  // Port D Advanced High-Performance
                                            // Bus
#define SYSCTL_GPIOHBCTL_PORTC  0x00000004  // Port C Advanced High-Performance
                                            // Bus
#define SYSCTL_GPIOHBCTL_PORTB  0x00000002  // Port B Advanced High-Performance
                                            // Bus
#define SYSCTL_GPIOHBCTL_PORTA  0x00000001  // Port A Advanced High-Performance
                                            // Bus

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_RCC2 register.
//
//*****************************************************************************
#define SYSCTL_RCC2_USERCC2     0x80000000  // Use RCC2
#define SYSCTL_RCC2_DIV400      0x40000000  // Divide PLL as 400 MHz vs. 200
                                            // MHz
#define SYSCTL_RCC2_SYSDIV2_M   0x1F800000  // System Clock Divisor 2
#define SYSCTL_RCC2_SYSDIV2LSB  0x00400000  // Additional LSB for SYSDIV2
#define SYSCTL_RCC2_USBPWRDN    0x00004000  // Power-Down USB PLL
#define SYSCTL_RCC2_PWRDN2      0x00002000  // Power-Down PLL 2
#define SYSCTL_RCC2_BYPASS2     0x00000800  // PLL Bypass 2
#define SYSCTL_RCC2_OSCSRC2_M   0x00000070  // Oscillator Source 2
#define SYSCTL_RCC2_OSCSRC2_MO  0x00000000  // MOSC
#define SYSCTL_RCC2_OSCSRC2_IO  0x00000010  // PIOSC
#define SYSCTL_RCC2_OSCSRC2_IO4 0x00000020  // PIOSC/4
#define SYSCTL_RCC2_OSCSRC2_30  0x00000030  // 30 kHz
#define SYSCTL_RCC2_OSCSRC2_32  0x00000070  // 32.768 kHz
#define SYSCTL_RCC2_SYSDIV2_S   23

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
#define SYSCTL_MEMTIM0_MB1      0x00100010  // Must be one
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
// The following are defines for the bit fields in the SYSCTL_RCGC0 register.
//
//*****************************************************************************
#define SYSCTL_RCGC0_WDT1       0x10000000  // WDT1 Clock Gating Control
#define SYSCTL_RCGC0_CAN1       0x02000000  // CAN1 Clock Gating Control
#define SYSCTL_RCGC0_CAN0       0x01000000  // CAN0 Clock Gating Control
#define SYSCTL_RCGC0_PWM0       0x00100000  // PWM Clock Gating Control
#define SYSCTL_RCGC0_ADC1       0x00020000  // ADC1 Clock Gating Control
#define SYSCTL_RCGC0_ADC0       0x00010000  // ADC0 Clock Gating Control
#define SYSCTL_RCGC0_ADC1SPD_M  0x00000C00  // ADC1 Sample Speed
#define SYSCTL_RCGC0_ADC1SPD_125K                                             \
                                0x00000000  // 125K samples/second
#define SYSCTL_RCGC0_ADC1SPD_250K                                             \
                                0x00000400  // 250K samples/second
#define SYSCTL_RCGC0_ADC1SPD_500K                                             \
                                0x00000800  // 500K samples/second
#define SYSCTL_RCGC0_ADC1SPD_1M 0x00000C00  // 1M samples/second
#define SYSCTL_RCGC0_ADC0SPD_M  0x00000300  // ADC0 Sample Speed
#define SYSCTL_RCGC0_ADC0SPD_125K                                             \
                                0x00000000  // 125K samples/second
#define SYSCTL_RCGC0_ADC0SPD_250K                                             \
                                0x00000100  // 250K samples/second
#define SYSCTL_RCGC0_ADC0SPD_500K                                             \
                                0x00000200  // 500K samples/second
#define SYSCTL_RCGC0_ADC0SPD_1M 0x00000300  // 1M samples/second
#define SYSCTL_RCGC0_HIB        0x00000040  // HIB Clock Gating Control
#define SYSCTL_RCGC0_WDT0       0x00000008  // WDT0 Clock Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_RCGC1 register.
//
//*****************************************************************************
#define SYSCTL_RCGC1_COMP2      0x04000000  // Analog Comparator 2 Clock Gating
#define SYSCTL_RCGC1_COMP1      0x02000000  // Analog Comparator 1 Clock Gating
#define SYSCTL_RCGC1_COMP0      0x01000000  // Analog Comparator 0 Clock Gating
#define SYSCTL_RCGC1_TIMER3     0x00080000  // Timer 3 Clock Gating Control
#define SYSCTL_RCGC1_TIMER2     0x00040000  // Timer 2 Clock Gating Control
#define SYSCTL_RCGC1_TIMER1     0x00020000  // Timer 1 Clock Gating Control
#define SYSCTL_RCGC1_TIMER0     0x00010000  // Timer 0 Clock Gating Control
#define SYSCTL_RCGC1_I2C1       0x00004000  // I2C1 Clock Gating Control
#define SYSCTL_RCGC1_I2C0       0x00001000  // I2C0 Clock Gating Control
#define SYSCTL_RCGC1_QEI1       0x00000200  // QEI1 Clock Gating Control
#define SYSCTL_RCGC1_QEI0       0x00000100  // QEI0 Clock Gating Control
#define SYSCTL_RCGC1_SSI1       0x00000020  // SSI1 Clock Gating Control
#define SYSCTL_RCGC1_SSI0       0x00000010  // SSI0 Clock Gating Control
#define SYSCTL_RCGC1_UART2      0x00000004  // UART2 Clock Gating Control
#define SYSCTL_RCGC1_UART1      0x00000002  // UART1 Clock Gating Control
#define SYSCTL_RCGC1_UART0      0x00000001  // UART0 Clock Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_RCGC2 register.
//
//*****************************************************************************
#define SYSCTL_RCGC2_USB0       0x00010000  // USB0 Clock Gating Control
#define SYSCTL_RCGC2_UDMA       0x00002000  // Micro-DMA Clock Gating Control
#define SYSCTL_RCGC2_GPIOJ      0x00000100  // Port J Clock Gating Control
#define SYSCTL_RCGC2_GPIOH      0x00000080  // Port H Clock Gating Control
#define SYSCTL_RCGC2_GPIOG      0x00000040  // Port G Clock Gating Control
#define SYSCTL_RCGC2_GPIOF      0x00000020  // Port F Clock Gating Control
#define SYSCTL_RCGC2_GPIOE      0x00000010  // Port E Clock Gating Control
#define SYSCTL_RCGC2_GPIOD      0x00000008  // Port D Clock Gating Control
#define SYSCTL_RCGC2_GPIOC      0x00000004  // Port C Clock Gating Control
#define SYSCTL_RCGC2_GPIOB      0x00000002  // Port B Clock Gating Control
#define SYSCTL_RCGC2_GPIOA      0x00000001  // Port A Clock Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_SCGC0 register.
//
//*****************************************************************************
#define SYSCTL_SCGC0_WDT1       0x10000000  // WDT1 Clock Gating Control
#define SYSCTL_SCGC0_CAN1       0x02000000  // CAN1 Clock Gating Control
#define SYSCTL_SCGC0_CAN0       0x01000000  // CAN0 Clock Gating Control
#define SYSCTL_SCGC0_PWM0       0x00100000  // PWM Clock Gating Control
#define SYSCTL_SCGC0_ADC1       0x00020000  // ADC1 Clock Gating Control
#define SYSCTL_SCGC0_ADC0       0x00010000  // ADC0 Clock Gating Control
#define SYSCTL_SCGC0_ADCSPD_M   0x00000F00  // ADC Sample Speed
#define SYSCTL_SCGC0_HIB        0x00000040  // HIB Clock Gating Control
#define SYSCTL_SCGC0_WDT0       0x00000008  // WDT0 Clock Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_SCGC1 register.
//
//*****************************************************************************
#define SYSCTL_SCGC1_COMP2      0x04000000  // Analog Comparator 2 Clock Gating
#define SYSCTL_SCGC1_COMP1      0x02000000  // Analog Comparator 1 Clock Gating
#define SYSCTL_SCGC1_COMP0      0x01000000  // Analog Comparator 0 Clock Gating
#define SYSCTL_SCGC1_TIMER3     0x00080000  // Timer 3 Clock Gating Control
#define SYSCTL_SCGC1_TIMER2     0x00040000  // Timer 2 Clock Gating Control
#define SYSCTL_SCGC1_TIMER1     0x00020000  // Timer 1 Clock Gating Control
#define SYSCTL_SCGC1_TIMER0     0x00010000  // Timer 0 Clock Gating Control
#define SYSCTL_SCGC1_I2C1       0x00004000  // I2C1 Clock Gating Control
#define SYSCTL_SCGC1_I2C0       0x00001000  // I2C0 Clock Gating Control
#define SYSCTL_SCGC1_QEI1       0x00000200  // QEI1 Clock Gating Control
#define SYSCTL_SCGC1_QEI0       0x00000100  // QEI0 Clock Gating Control
#define SYSCTL_SCGC1_SSI1       0x00000020  // SSI1 Clock Gating Control
#define SYSCTL_SCGC1_SSI0       0x00000010  // SSI0 Clock Gating Control
#define SYSCTL_SCGC1_UART2      0x00000004  // UART2 Clock Gating Control
#define SYSCTL_SCGC1_UART1      0x00000002  // UART1 Clock Gating Control
#define SYSCTL_SCGC1_UART0      0x00000001  // UART0 Clock Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_SCGC2 register.
//
//*****************************************************************************
#define SYSCTL_SCGC2_USB0       0x00010000  // USB0 Clock Gating Control
#define SYSCTL_SCGC2_UDMA       0x00002000  // Micro-DMA Clock Gating Control
#define SYSCTL_SCGC2_GPIOJ      0x00000100  // Port J Clock Gating Control
#define SYSCTL_SCGC2_GPIOH      0x00000080  // Port H Clock Gating Control
#define SYSCTL_SCGC2_GPIOG      0x00000040  // Port G Clock Gating Control
#define SYSCTL_SCGC2_GPIOF      0x00000020  // Port F Clock Gating Control
#define SYSCTL_SCGC2_GPIOE      0x00000010  // Port E Clock Gating Control
#define SYSCTL_SCGC2_GPIOD      0x00000008  // Port D Clock Gating Control
#define SYSCTL_SCGC2_GPIOC      0x00000004  // Port C Clock Gating Control
#define SYSCTL_SCGC2_GPIOB      0x00000002  // Port B Clock Gating Control
#define SYSCTL_SCGC2_GPIOA      0x00000001  // Port A Clock Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_DCGC0 register.
//
//*****************************************************************************
#define SYSCTL_DCGC0_WDT1       0x10000000  // WDT1 Clock Gating Control
#define SYSCTL_DCGC0_CAN1       0x02000000  // CAN1 Clock Gating Control
#define SYSCTL_DCGC0_CAN0       0x01000000  // CAN0 Clock Gating Control
#define SYSCTL_DCGC0_PWM0       0x00100000  // PWM Clock Gating Control
#define SYSCTL_DCGC0_ADC1       0x00020000  // ADC1 Clock Gating Control
#define SYSCTL_DCGC0_ADC0       0x00010000  // ADC0 Clock Gating Control
#define SYSCTL_DCGC0_HIB        0x00000040  // HIB Clock Gating Control
#define SYSCTL_DCGC0_WDT0       0x00000008  // WDT0 Clock Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_DCGC1 register.
//
//*****************************************************************************
#define SYSCTL_DCGC1_COMP2      0x04000000  // Analog Comparator 2 Clock Gating
#define SYSCTL_DCGC1_COMP1      0x02000000  // Analog Comparator 1 Clock Gating
#define SYSCTL_DCGC1_COMP0      0x01000000  // Analog Comparator 0 Clock Gating
#define SYSCTL_DCGC1_TIMER3     0x00080000  // Timer 3 Clock Gating Control
#define SYSCTL_DCGC1_TIMER2     0x00040000  // Timer 2 Clock Gating Control
#define SYSCTL_DCGC1_TIMER1     0x00020000  // Timer 1 Clock Gating Control
#define SYSCTL_DCGC1_TIMER0     0x00010000  // Timer 0 Clock Gating Control
#define SYSCTL_DCGC1_I2C1       0x00004000  // I2C1 Clock Gating Control
#define SYSCTL_DCGC1_I2C0       0x00001000  // I2C0 Clock Gating Control
#define SYSCTL_DCGC1_QEI1       0x00000200  // QEI1 Clock Gating Control
#define SYSCTL_DCGC1_QEI0       0x00000100  // QEI0 Clock Gating Control
#define SYSCTL_DCGC1_SSI1       0x00000020  // SSI1 Clock Gating Control
#define SYSCTL_DCGC1_SSI0       0x00000010  // SSI0 Clock Gating Control
#define SYSCTL_DCGC1_UART2      0x00000004  // UART2 Clock Gating Control
#define SYSCTL_DCGC1_UART1      0x00000002  // UART1 Clock Gating Control
#define SYSCTL_DCGC1_UART0      0x00000001  // UART0 Clock Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_DCGC2 register.
//
//*****************************************************************************
#define SYSCTL_DCGC2_USB0       0x00010000  // USB0 Clock Gating Control
#define SYSCTL_DCGC2_UDMA       0x00002000  // Micro-DMA Clock Gating Control
#define SYSCTL_DCGC2_GPIOJ      0x00000100  // Port J Clock Gating Control
#define SYSCTL_DCGC2_GPIOH      0x00000080  // Port H Clock Gating Control
#define SYSCTL_DCGC2_GPIOG      0x00000040  // Port G Clock Gating Control
#define SYSCTL_DCGC2_GPIOF      0x00000020  // Port F Clock Gating Control
#define SYSCTL_DCGC2_GPIOE      0x00000010  // Port E Clock Gating Control
#define SYSCTL_DCGC2_GPIOD      0x00000008  // Port D Clock Gating Control
#define SYSCTL_DCGC2_GPIOC      0x00000004  // Port C Clock Gating Control
#define SYSCTL_DCGC2_GPIOB      0x00000002  // Port B Clock Gating Control
#define SYSCTL_DCGC2_GPIOA      0x00000001  // Port A Clock Gating Control

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
// The following are defines for the bit fields in the SYSCTL_DSLPCLKCFG
// register.
//
//*****************************************************************************
#define SYSCTL_DSLPCLKCFG_D_M   0x1F800000  // Divider Field Override
#define SYSCTL_DSLPCLKCFG_O_M   0x00000070  // Clock Source
#define SYSCTL_DSLPCLKCFG_O_IGN 0x00000000  // MOSC
#define SYSCTL_DSLPCLKCFG_O_IO  0x00000010  // PIOSC
#define SYSCTL_DSLPCLKCFG_O_30  0x00000030  // 30 kHz
#define SYSCTL_DSLPCLKCFG_O_32  0x00000070  // 32.768 kHz
#define SYSCTL_DSLPCLKCFG_PIOSCPD                                             \
                                0x00000002  // PIOSC Power Down Request
#define SYSCTL_DSLPCLKCFG_D_S   23

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
// The following are defines for the bit fields in the SYSCTL_DC9 register.
//
//*****************************************************************************
#define SYSCTL_DC9_ADC1DC7      0x00800000  // ADC1 DC7 Present
#define SYSCTL_DC9_ADC1DC6      0x00400000  // ADC1 DC6 Present
#define SYSCTL_DC9_ADC1DC5      0x00200000  // ADC1 DC5 Present
#define SYSCTL_DC9_ADC1DC4      0x00100000  // ADC1 DC4 Present
#define SYSCTL_DC9_ADC1DC3      0x00080000  // ADC1 DC3 Present
#define SYSCTL_DC9_ADC1DC2      0x00040000  // ADC1 DC2 Present
#define SYSCTL_DC9_ADC1DC1      0x00020000  // ADC1 DC1 Present
#define SYSCTL_DC9_ADC1DC0      0x00010000  // ADC1 DC0 Present
#define SYSCTL_DC9_ADC0DC7      0x00000080  // ADC0 DC7 Present
#define SYSCTL_DC9_ADC0DC6      0x00000040  // ADC0 DC6 Present
#define SYSCTL_DC9_ADC0DC5      0x00000020  // ADC0 DC5 Present
#define SYSCTL_DC9_ADC0DC4      0x00000010  // ADC0 DC4 Present
#define SYSCTL_DC9_ADC0DC3      0x00000008  // ADC0 DC3 Present
#define SYSCTL_DC9_ADC0DC2      0x00000004  // ADC0 DC2 Present
#define SYSCTL_DC9_ADC0DC1      0x00000002  // ADC0 DC1 Present
#define SYSCTL_DC9_ADC0DC0      0x00000001  // ADC0 DC0 Present

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_NVMSTAT register.
//
//*****************************************************************************
#define SYSCTL_NVMSTAT_FWB      0x00000001  // 32 Word Flash Write Buffer
                                            // Active

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_LDOSPCTL
// register.
//
//*****************************************************************************
#define SYSCTL_LDOSPCTL_VADJEN  0x80000000  // Voltage Adjust Enable
#define SYSCTL_LDOSPCTL_VLDO_M  0x000000FF  // LDO Output Voltage
#define SYSCTL_LDOSPCTL_VLDO_0_90V                                            \
                                0x00000012  // 0.90 V
#define SYSCTL_LDOSPCTL_VLDO_0_95V                                            \
                                0x00000013  // 0.95 V
#define SYSCTL_LDOSPCTL_VLDO_1_00V                                            \
                                0x00000014  // 1.00 V
#define SYSCTL_LDOSPCTL_VLDO_1_05V                                            \
                                0x00000015  // 1.05 V
#define SYSCTL_LDOSPCTL_VLDO_1_10V                                            \
                                0x00000016  // 1.10 V
#define SYSCTL_LDOSPCTL_VLDO_1_15V                                            \
                                0x00000017  // 1.15 V
#define SYSCTL_LDOSPCTL_VLDO_1_20V                                            \
                                0x00000018  // 1.20 V

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
// The following are defines for the bit fields in the SYSCTL_LCDMPC register.
//
//*****************************************************************************
#define SYSCTL_LCDMPC_PWRCTL_M  0x00000003  // Memory Array Power Control
#define SYSCTL_LCDMPC_PWRCTL_OFF                                              \
                                0x00000000  // Array OFF
#define SYSCTL_LCDMPC_PWRCTL_ON 0x00000003  // Array On

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
#define SYSCTL_PPGPIO_P17       0x00020000  // GPIO Port T Present
#define SYSCTL_PPGPIO_P16       0x00010000  // GPIO Port S Present
#define SYSCTL_PPGPIO_P15       0x00008000  // GPIO Port R Present
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
#define SYSCTL_PPPWM_P1         0x00000002  // PWM Module 1 Present
#define SYSCTL_PPPWM_P0         0x00000001  // PWM Module 0 Present

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PPQEI register.
//
//*****************************************************************************
#define SYSCTL_PPQEI_P1         0x00000002  // QEI Module 1 Present
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
#define SYSCTL_PPWTIMER_P5      0x00000020  // Wide Timer 5 Present
#define SYSCTL_PPWTIMER_P4      0x00000010  // Wide Timer 4 Present
#define SYSCTL_PPWTIMER_P3      0x00000008  // Wide Timer 3 Present
#define SYSCTL_PPWTIMER_P2      0x00000004  // Wide Timer 2 Present
#define SYSCTL_PPWTIMER_P1      0x00000002  // Wide Timer 1 Present
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
#define SYSCTL_SRGPIO_R17       0x00020000  // GPIO Port T Software Reset
#define SYSCTL_SRGPIO_R16       0x00010000  // GPIO Port S Software Reset
#define SYSCTL_SRGPIO_R15       0x00008000  // GPIO Port R Software Reset
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
#define SYSCTL_SRPWM_R1         0x00000002  // PWM Module 1 Software Reset
#define SYSCTL_SRPWM_R0         0x00000001  // PWM Module 0 Software Reset

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_SRQEI register.
//
//*****************************************************************************
#define SYSCTL_SRQEI_R1         0x00000002  // QEI Module 1 Software Reset
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
// The following are defines for the bit fields in the SYSCTL_SRWTIMER
// register.
//
//*****************************************************************************
#define SYSCTL_SRWTIMER_R5      0x00000020  // Wide Timer 5 Software Reset
#define SYSCTL_SRWTIMER_R4      0x00000010  // Wide Timer 4 Software Reset
#define SYSCTL_SRWTIMER_R3      0x00000008  // Wide Timer 3 Software Reset
#define SYSCTL_SRWTIMER_R2      0x00000004  // Wide Timer 2 Software Reset
#define SYSCTL_SRWTIMER_R1      0x00000002  // Wide Timer 1 Software Reset
#define SYSCTL_SRWTIMER_R0      0x00000001  // Wide Timer 0 Software Reset

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_SRCCM register.
//
//*****************************************************************************
#define SYSCTL_SRCCM_R0         0x00000001  // CRC and Cryptographic Modules
                                            // Software Reset

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_SRLCD register.
//
//*****************************************************************************
#define SYSCTL_SRLCD_R0         0x00000001  // LCD Module 0 Software Reset

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_SROWIRE register.
//
//*****************************************************************************
#define SYSCTL_SROWIRE_R0       0x00000001  // HIM Module 0 Software Reset

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
#define SYSCTL_RCGCGPIO_R17     0x00020000  // GPIO Port T Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCGPIO_R16     0x00010000  // GPIO Port S Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCGPIO_R15     0x00008000  // GPIO Port R Run Mode Clock
                                            // Gating Control
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
#define SYSCTL_RCGCPWM_R1       0x00000002  // PWM Module 1 Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCPWM_R0       0x00000001  // PWM Module 0 Run Mode Clock
                                            // Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_RCGCQEI register.
//
//*****************************************************************************
#define SYSCTL_RCGCQEI_R1       0x00000002  // QEI Module 1 Run Mode Clock
                                            // Gating Control
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
// The following are defines for the bit fields in the SYSCTL_RCGCWTIMER
// register.
//
//*****************************************************************************
#define SYSCTL_RCGCWTIMER_R5    0x00000020  // Wide Timer 5 Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCWTIMER_R4    0x00000010  // Wide Timer 4 Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCWTIMER_R3    0x00000008  // Wide Timer 3 Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCWTIMER_R2    0x00000004  // Wide Timer 2 Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCWTIMER_R1    0x00000002  // Wide Timer 1 Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCWTIMER_R0    0x00000001  // Wide Timer 0 Run Mode Clock
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
// The following are defines for the bit fields in the SYSCTL_RCGCLCD register.
//
//*****************************************************************************
#define SYSCTL_RCGCLCD_R0       0x00000001  // LCD Controller Module 0 Run Mode
                                            // Clock Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_RCGCOWIRE
// register.
//
//*****************************************************************************
#define SYSCTL_RCGCOWIRE_R0     0x00000001  // One-Wire Module 0 Run Mode Clock
                                            // Gating Control

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
#define SYSCTL_SCGCGPIO_S17     0x00020000  // GPIO Port T Sleep Mode Clock
                                            // Gating Control
#define SYSCTL_SCGCGPIO_S16     0x00010000  // GPIO Port S Sleep Mode Clock
                                            // Gating Control
#define SYSCTL_SCGCGPIO_S15     0x00008000  // GPIO Port R Sleep Mode Clock
                                            // Gating Control
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
// The following are defines for the bit fields in the SYSCTL_SCGCDMA register.
//
//*****************************************************************************
#define SYSCTL_SCGCDMA_S0       0x00000001  // uDMA Module Sleep Mode Clock
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
#define SYSCTL_SCGCPWM_S1       0x00000002  // PWM Module 1 Sleep Mode Clock
                                            // Gating Control
#define SYSCTL_SCGCPWM_S0       0x00000001  // PWM Module 0 Sleep Mode Clock
                                            // Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_SCGCQEI register.
//
//*****************************************************************************
#define SYSCTL_SCGCQEI_S1       0x00000002  // QEI Module 1 Sleep Mode Clock
                                            // Gating Control
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
// The following are defines for the bit fields in the SYSCTL_SCGCWTIMER
// register.
//
//*****************************************************************************
#define SYSCTL_SCGCWTIMER_S5    0x00000020  // Wide Timer 5 Sleep Mode Clock
                                            // Gating Control
#define SYSCTL_SCGCWTIMER_S4    0x00000010  // Wide Timer 4 Sleep Mode Clock
                                            // Gating Control
#define SYSCTL_SCGCWTIMER_S3    0x00000008  // Wide Timer 3 Sleep Mode Clock
                                            // Gating Control
#define SYSCTL_SCGCWTIMER_S2    0x00000004  // Wide Timer 2 Sleep Mode Clock
                                            // Gating Control
#define SYSCTL_SCGCWTIMER_S1    0x00000002  // Wide Timer 1 Sleep Mode Clock
                                            // Gating Control
#define SYSCTL_SCGCWTIMER_S0    0x00000001  // Wide Timer 0 Sleep Mode Clock
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
// The following are defines for the bit fields in the SYSCTL_SCGCLCD register.
//
//*****************************************************************************
#define SYSCTL_SCGCLCD_S0       0x00000001  // LCD Controller Module 0 Sleep
                                            // Mode Clock Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_SCGCOWIRE
// register.
//
//*****************************************************************************
#define SYSCTL_SCGCOWIRE_S0     0x00000001  // One-Wire Module 0 Sleep Mode
                                            // Clock Gating Control

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
#define SYSCTL_DCGCGPIO_D17     0x00020000  // GPIO Port T Deep-Sleep Mode
                                            // Clock Gating Control
#define SYSCTL_DCGCGPIO_D16     0x00010000  // GPIO Port S Deep-Sleep Mode
                                            // Clock Gating Control
#define SYSCTL_DCGCGPIO_D15     0x00008000  // GPIO Port R Deep-Sleep Mode
                                            // Clock Gating Control
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
// The following are defines for the bit fields in the SYSCTL_DCGCDMA register.
//
//*****************************************************************************
#define SYSCTL_DCGCDMA_D0       0x00000001  // uDMA Module Deep-Sleep Mode
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
#define SYSCTL_DCGCPWM_D1       0x00000002  // PWM Module 1 Deep-Sleep Mode
                                            // Clock Gating Control
#define SYSCTL_DCGCPWM_D0       0x00000001  // PWM Module 0 Deep-Sleep Mode
                                            // Clock Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_DCGCQEI register.
//
//*****************************************************************************
#define SYSCTL_DCGCQEI_D1       0x00000002  // QEI Module 1 Deep-Sleep Mode
                                            // Clock Gating Control
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
// The following are defines for the bit fields in the SYSCTL_DCGCWTIMER
// register.
//
//*****************************************************************************
#define SYSCTL_DCGCWTIMER_D5    0x00000020  // Wide Timer 5 Deep-Sleep Mode
                                            // Clock Gating Control
#define SYSCTL_DCGCWTIMER_D4    0x00000010  // Wide Timer 4 Deep-Sleep Mode
                                            // Clock Gating Control
#define SYSCTL_DCGCWTIMER_D3    0x00000008  // Wide Timer 3 Deep-Sleep Mode
                                            // Clock Gating Control
#define SYSCTL_DCGCWTIMER_D2    0x00000004  // Wide Timer 2 Deep-Sleep Mode
                                            // Clock Gating Control
#define SYSCTL_DCGCWTIMER_D1    0x00000002  // Wide Timer 1 Deep-Sleep Mode
                                            // Clock Gating Control
#define SYSCTL_DCGCWTIMER_D0    0x00000001  // Wide Timer 0 Deep-Sleep Mode
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
// The following are defines for the bit fields in the SYSCTL_DCGCLCD register.
//
//*****************************************************************************
#define SYSCTL_DCGCLCD_D0       0x00000001  // LCD Controller Module 0
                                            // Deep-Sleep Mode Clock Gating
                                            // Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_DCGCOWIRE
// register.
//
//*****************************************************************************
#define SYSCTL_DCGCOWIRE_D0     0x00000001  // One-Wire Module 0 Deep-Sleep
                                            // Mode Clock Gating Control

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
#define SYSCTL_PCGPIO_P17       0x00020000  // GPIO Port T Power Control
#define SYSCTL_PCGPIO_P16       0x00010000  // GPIO Port S Power Control
#define SYSCTL_PCGPIO_P15       0x00008000  // GPIO Port R Power Control
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
// The following are defines for the bit fields in the SYSCTL_PCLCD register.
//
//*****************************************************************************
#define SYSCTL_PCLCD_P0         0x00000001  // LCD Controller Module 0 Power
                                            // Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PCOWIRE register.
//
//*****************************************************************************
#define SYSCTL_PCOWIRE_P0       0x00000001  // 1-Wire Module 0 Power Control

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
#define SYSCTL_PRGPIO_R17       0x00020000  // GPIO Port T Peripheral Ready
#define SYSCTL_PRGPIO_R16       0x00010000  // GPIO Port S Peripheral Ready
#define SYSCTL_PRGPIO_R15       0x00008000  // GPIO Port R Peripheral Ready
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
#define SYSCTL_PRPWM_R1         0x00000002  // PWM Module 1 Peripheral Ready
#define SYSCTL_PRPWM_R0         0x00000001  // PWM Module 0 Peripheral Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PRQEI register.
//
//*****************************************************************************
#define SYSCTL_PRQEI_R1         0x00000002  // QEI Module 1 Peripheral Ready
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
// The following are defines for the bit fields in the SYSCTL_PRWTIMER
// register.
//
//*****************************************************************************
#define SYSCTL_PRWTIMER_R5      0x00000020  // Wide Timer 5 Peripheral Ready
#define SYSCTL_PRWTIMER_R4      0x00000010  // Wide Timer 4 Peripheral Ready
#define SYSCTL_PRWTIMER_R3      0x00000008  // Wide Timer 3 Peripheral Ready
#define SYSCTL_PRWTIMER_R2      0x00000004  // Wide Timer 2 Peripheral Ready
#define SYSCTL_PRWTIMER_R1      0x00000002  // Wide Timer 1 Peripheral Ready
#define SYSCTL_PRWTIMER_R0      0x00000001  // Wide Timer 0 Peripheral Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PRCCM register.
//
//*****************************************************************************
#define SYSCTL_PRCCM_R0         0x00000001  // CRC and Cryptographic Modules
                                            // Peripheral Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PRLCD register.
//
//*****************************************************************************
#define SYSCTL_PRLCD_R0         0x00000001  // LCD Controller Module 0
                                            // Peripheral Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PROWIRE register.
//
//*****************************************************************************
#define SYSCTL_PROWIRE_R0       0x00000001  // One-Wire Module 0 Peripheral
                                            // Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PREMAC register.
//
//*****************************************************************************
#define SYSCTL_PREMAC_R0        0x00000001  // Ethernet MAC Module 0 Peripheral
                                            // Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_CCMCGREQ
// register.
//
//*****************************************************************************
#define SYSCTL_CCMCGREQ_DESCFG  0x00000004  // DES Clock Gating Request
#define SYSCTL_CCMCGREQ_AESCFG  0x00000002  // AES Clock Gating Request
#define SYSCTL_CCMCGREQ_SHACFG  0x00000001  // SHA/MD5 Clock Gating Request

#endif // __HW_SYSCTL_H__
