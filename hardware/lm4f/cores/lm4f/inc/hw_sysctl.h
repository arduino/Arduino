//*****************************************************************************
//
// hw_sysctl.h - Macros used when accessing the system control hardware.
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
#define SYSCTL_LDOPCTL          0x400FE034  // LDO Power Control
#define SYSCTL_SRCR0            0x400FE040  // Software Reset Control 0
#define SYSCTL_SRCR1            0x400FE044  // Software Reset Control 1
#define SYSCTL_SRCR2            0x400FE048  // Software Reset Control 2
#define SYSCTL_RIS              0x400FE050  // Raw Interrupt Status
#define SYSCTL_IMC              0x400FE054  // Interrupt Mask Control
#define SYSCTL_MISC             0x400FE058  // Masked Interrupt Status and
                                            // Clear
#define SYSCTL_RESC             0x400FE05C  // Reset Cause
#define SYSCTL_RCC              0x400FE060  // Run-Mode Clock Configuration
#define SYSCTL_PLLCFG           0x400FE064  // XTAL to PLL Translation
#define SYSCTL_GPIOHBCTL        0x400FE06C  // GPIO High-Performance Bus
                                            // Control
#define SYSCTL_RCC2             0x400FE070  // Run-Mode Clock Configuration 2
#define SYSCTL_MOSCCTL          0x400FE07C  // Main Oscillator Control
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
#define SYSCTL_DSLPCLKCFG       0x400FE144  // Deep Sleep Clock Configuration
#define SYSCTL_SYSPROP          0x400FE14C  // System Properties
#define SYSCTL_PIOSCCAL         0x400FE150  // Precision Internal Oscillator
                                            // Calibration
#define SYSCTL_CLKVCLR          0x400FE150  // Clock Verification Clear
#define SYSCTL_PIOSCSTAT        0x400FE154  // Precision Internal Oscillator
                                            // Statistics
#define SYSCTL_LDOARST          0x400FE160  // Allow Unregulated LDO to Reset
                                            // the Part
#define SYSCTL_PLLFREQ0         0x400FE160  // PLL Frequency 0
#define SYSCTL_PLLFREQ1         0x400FE164  // PLL Frequency 1
#define SYSCTL_PLLSTAT          0x400FE168  // PLL Status
#define SYSCTL_I2SMCLKCFG       0x400FE170  // I2S MCLK Configuration
#define SYSCTL_DC9              0x400FE190  // Device Capabilities 9 ADC
                                            // Digital Comparators
#define SYSCTL_NVMSTAT          0x400FE1A0  // Non-Volatile Memory Information
#define SYSCTL_PPWD             0x400FE300  // Watchdog Timer Peripheral
                                            // Present
#define SYSCTL_PPTIMER          0x400FE304  // Timer Peripheral Present
#define SYSCTL_PPGPIO           0x400FE308  // General-Purpose Input/Output
                                            // Peripheral Present
#define SYSCTL_PPDMA            0x400FE30C  // Micro Direct Memory Access
                                            // Peripheral Present
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
#define SYSCTL_SRWD             0x400FE500  // Watchdog Timer Software Reset
#define SYSCTL_SRTIMER          0x400FE504  // Timer Software Reset
#define SYSCTL_SRGPIO           0x400FE508  // General-Purpose Input/Output
                                            // Software Reset
#define SYSCTL_SRDMA            0x400FE50C  // Micro Direct Memory Access
                                            // Software Reset
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
#define SYSCTL_SRCAN            0x400FE534  // Controller Area Network Software
                                            // Reset
#define SYSCTL_SRADC            0x400FE538  // Analog-to-Digital Converter
                                            // Software Reset
#define SYSCTL_SRACMP           0x400FE53C  // Analog Comparator Software Reset
#define SYSCTL_SRPWM            0x400FE540  // Pulse Width Modulator Software
                                            // Reset
#define SYSCTL_SRQEI            0x400FE544  // Quadrature Encoder Interface
                                            // Software Reset
#define SYSCTL_SRLPC            0x400FE548  // Low Pin Count Interface Software
                                            // Reset
#define SYSCTL_SRPECI           0x400FE550  // Platform Environment Control
                                            // Interface Software Reset
#define SYSCTL_SRFAN            0x400FE554  // Fan Software Reset
#define SYSCTL_SREEPROM         0x400FE558  // EEPROM Software Reset
#define SYSCTL_SRWTIMER         0x400FE55C  // Wide Timer Software Reset
#define SYSCTL_RCGCWD           0x400FE600  // Watchdog Timer Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCTIMER        0x400FE604  // Timer Run Mode Clock Gating
                                            // Control
#define SYSCTL_RCGCGPIO         0x400FE608  // General-Purpose Input/Output Run
                                            // Mode Clock Gating Control
#define SYSCTL_RCGCDMA          0x400FE60C  // Micro Direct Memory Access Run
                                            // Mode Clock Gating Control
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
#define SYSCTL_RCGCLPC          0x400FE648  // Low Pin Count Interface Run Mode
                                            // Clock Gating Control
#define SYSCTL_RCGCPECI         0x400FE650  // Platform Environment Control
                                            // Interface Run Mode Clock Gating
                                            // Control
#define SYSCTL_RCGCFAN          0x400FE654  // Fan Run Mode Clock Gating
                                            // Control
#define SYSCTL_RCGCEEPROM       0x400FE658  // EEPROM Run Mode Clock Gating
                                            // Control
#define SYSCTL_RCGCWTIMER       0x400FE65C  // Wide Timer Run Mode Clock Gating
                                            // Control
#define SYSCTL_SCGCWD           0x400FE700  // Watchdog Timer Sleep Mode Clock
                                            // Gating Control
#define SYSCTL_SCGCTIMER        0x400FE704  // Timer Sleep Mode Clock Gating
                                            // Control
#define SYSCTL_SCGCGPIO         0x400FE708  // General-Purpose Input/Output
                                            // Sleep Mode Clock Gating Control
#define SYSCTL_SCGCDMA          0x400FE70C  // Micro Direct Memory Access Sleep
                                            // Mode Clock Gating Control
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
#define SYSCTL_SCGCLPC          0x400FE748  // Low Pin Count Interface Sleep
                                            // Mode Clock Gating Control
#define SYSCTL_SCGCPECI         0x400FE750  // Platform Environment Control
                                            // Interface Sleep Mode Clock
                                            // Gating Control
#define SYSCTL_SCGCFAN          0x400FE754  // Fan Sleep Mode Clock Gating
                                            // Control
#define SYSCTL_SCGCEEPROM       0x400FE758  // EEPROM Sleep Mode Clock Gating
                                            // Control
#define SYSCTL_SCGCWTIMER       0x400FE75C  // Wide Timer Sleep Mode Clock
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
#define SYSCTL_DCGCLPC          0x400FE848  // Low Pin Count Interface
                                            // Deep-Sleep Mode Clock Gating
                                            // Control
#define SYSCTL_DCGCPECI         0x400FE850  // Platform Environment Control
                                            // Interface Deep-Sleep Mode Clock
                                            // Gating Control
#define SYSCTL_DCGCFAN          0x400FE854  // Fan Deep-Sleep Mode Clock Gating
                                            // Control
#define SYSCTL_DCGCEEPROM       0x400FE858  // EEPROM Deep-Sleep Mode Clock
                                            // Gating Control
#define SYSCTL_DCGCWTIMER       0x400FE85C  // Wide Timer Deep-Sleep Mode Clock
                                            // Gating Control
#define SYSCTL_PCWD             0x400FE900  // Watchdog Timer Power Control
#define SYSCTL_PCTIMER          0x400FE904  // Timer Power Control
#define SYSCTL_PCGPIO           0x400FE908  // General-Purpose Input/Output
                                            // Power Control
#define SYSCTL_PCDMA            0x400FE90C  // Micro Direct Memory Access Power
                                            // Control
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
#define SYSCTL_PCCAN            0x400FE934  // Controller Area Network Power
                                            // Control
#define SYSCTL_PCADC            0x400FE938  // Analog-to-Digital Converter
                                            // Power Control
#define SYSCTL_PCACMP           0x400FE93C  // Analog Comparator Power Control
#define SYSCTL_PCPWM            0x400FE940  // Pulse Width Modulator Power
                                            // Control
#define SYSCTL_PCQEI            0x400FE944  // Quadrature Encoder Interface
                                            // Power Control
#define SYSCTL_PCLPC            0x400FE948  // Low Pin Count Interface Power
                                            // Control
#define SYSCTL_PCPECI           0x400FE950  // Platform Environment Control
                                            // Interface Power Control
#define SYSCTL_PCFAN            0x400FE954  // Fan Power Control
#define SYSCTL_PCEEPROM         0x400FE958  // EEPROM Power Control
#define SYSCTL_PCWTIMER         0x400FE95C  // Wide Timer Power Control
#define SYSCTL_PRWD             0x400FEA00  // Watchdog Timer Peripheral Ready
#define SYSCTL_PRTIMER          0x400FEA04  // Timer Peripheral Ready
#define SYSCTL_PRGPIO           0x400FEA08  // General-Purpose Input/Output
                                            // Peripheral Ready
#define SYSCTL_PRDMA            0x400FEA0C  // Micro Direct Memory Access
                                            // Peripheral Ready
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
#define SYSCTL_PRLPC            0x400FEA48  // Low Pin Count Interface
                                            // Peripheral Ready
#define SYSCTL_PRPECI           0x400FEA50  // Platform Environment Control
                                            // Interface Peripheral Ready
#define SYSCTL_PRFAN            0x400FEA54  // Fan Peripheral Ready
#define SYSCTL_PREEPROM         0x400FEA58  // EEPROM Peripheral Ready
#define SYSCTL_PRWTIMER         0x400FEA5C  // Wide Timer Peripheral Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_DID0 register.
//
//*****************************************************************************
#define SYSCTL_DID0_VER_M       0x70000000  // DID0 Version
#define SYSCTL_DID0_VER_0       0x00000000  // Initial DID0 register format
                                            // definition for Stellaris(R)
                                            // Sandstorm-class devices
#define SYSCTL_DID0_VER_1       0x10000000  // Second version of the DID0
                                            // register format
#define SYSCTL_DID0_CLASS_M     0x00FF0000  // Device Class
#define SYSCTL_DID0_CLASS_SANDSTORM \
                                0x00000000  // Sandstorm-class Device
#define SYSCTL_DID0_CLASS_FURY  0x00010000  // Stellaris(R) Fury-class devices
#define SYSCTL_DID0_CLASS_DUSTDEVIL \
                                0x00030000  // Stellaris(R) DustDevil-class
                                            // devices
#define SYSCTL_DID0_CLASS_TEMPEST \
                                0x00040000  // Stellaris(R) Tempest-class
                                            // microcontrollers
#define SYSCTL_DID0_CLASS_BLIZZARD \
                                0x00050000  // Stellaris(R) Blizzard-class
                                            // microcontrollers
#define SYSCTL_DID0_CLASS_FIRESTORM \
                                0x00060000  // Stellaris(R) Firestorm-class
                                            // microcontrollers
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
#define SYSCTL_DID0_MIN_3       0x00000003  // Minor revision 3
#define SYSCTL_DID0_MIN_4       0x00000004  // Minor revision 4
#define SYSCTL_DID0_MIN_5       0x00000005  // Minor revision 5

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_DID1 register.
//
//*****************************************************************************
#define SYSCTL_DID1_VER_M       0xF0000000  // DID1 Version
#define SYSCTL_DID1_VER_0       0x00000000  // Initial DID1 register format
                                            // definition, indicating a
                                            // Stellaris LM3Snnn device
#define SYSCTL_DID1_VER_1       0x10000000  // Second version of the DID1
                                            // register format
#define SYSCTL_DID1_FAM_M       0x0F000000  // Family
#define SYSCTL_DID1_FAM_STELLARIS \
                                0x00000000  // Stellaris family of
                                            // microcontollers, that is, all
                                            // devices with external part
                                            // numbers starting with LM3S
#define SYSCTL_DID1_PRTNO_M     0x00FF0000  // Part Number
#define SYSCTL_DID1_PRTNO_101   0x00010000  // LM3S101
#define SYSCTL_DID1_PRTNO_102   0x00020000  // LM3S102
#define SYSCTL_DID1_PRTNO_300   0x00190000  // LM3S300
#define SYSCTL_DID1_PRTNO_301   0x00110000  // LM3S301
#define SYSCTL_DID1_PRTNO_308   0x001A0000  // LM3S308
#define SYSCTL_DID1_PRTNO_310   0x00120000  // LM3S310
#define SYSCTL_DID1_PRTNO_315   0x00130000  // LM3S315
#define SYSCTL_DID1_PRTNO_316   0x00140000  // LM3S316
#define SYSCTL_DID1_PRTNO_317   0x00170000  // LM3S317
#define SYSCTL_DID1_PRTNO_328   0x00150000  // LM3S328
#define SYSCTL_DID1_PRTNO_600   0x002A0000  // LM3S600
#define SYSCTL_DID1_PRTNO_601   0x00210000  // LM3S601
#define SYSCTL_DID1_PRTNO_608   0x002B0000  // LM3S608
#define SYSCTL_DID1_PRTNO_610   0x00220000  // LM3S610
#define SYSCTL_DID1_PRTNO_611   0x00230000  // LM3S611
#define SYSCTL_DID1_PRTNO_612   0x00240000  // LM3S612
#define SYSCTL_DID1_PRTNO_613   0x00250000  // LM3S613
#define SYSCTL_DID1_PRTNO_615   0x00260000  // LM3S615
#define SYSCTL_DID1_PRTNO_617   0x00280000  // LM3S617
#define SYSCTL_DID1_PRTNO_618   0x00290000  // LM3S618
#define SYSCTL_DID1_PRTNO_628   0x00270000  // LM3S628
#define SYSCTL_DID1_PRTNO_800   0x00380000  // LM3S800
#define SYSCTL_DID1_PRTNO_801   0x00310000  // LM3S801
#define SYSCTL_DID1_PRTNO_808   0x00390000  // LM3S808
#define SYSCTL_DID1_PRTNO_811   0x00320000  // LM3S811
#define SYSCTL_DID1_PRTNO_812   0x00330000  // LM3S812
#define SYSCTL_DID1_PRTNO_815   0x00340000  // LM3S815
#define SYSCTL_DID1_PRTNO_817   0x00360000  // LM3S817
#define SYSCTL_DID1_PRTNO_818   0x00370000  // LM3S818
#define SYSCTL_DID1_PRTNO_828   0x00350000  // LM3S828
#define SYSCTL_DID1_PRTNO_1110  0x00BF0000  // LM3S1110
#define SYSCTL_DID1_PRTNO_1133  0x00C30000  // LM3S1133
#define SYSCTL_DID1_PRTNO_1138  0x00C50000  // LM3S1138
#define SYSCTL_DID1_PRTNO_1150  0x00C10000  // LM3S1150
#define SYSCTL_DID1_PRTNO_1162  0x00C40000  // LM3S1162
#define SYSCTL_DID1_PRTNO_1165  0x00C20000  // LM3S1165
#define SYSCTL_DID1_PRTNO_1166  0x00EC0000  // LM3S1166
#define SYSCTL_DID1_PRTNO_1332  0x00C60000  // LM3S1332
#define SYSCTL_DID1_PRTNO_1435  0x00BC0000  // LM3S1435
#define SYSCTL_DID1_PRTNO_1439  0x00BA0000  // LM3S1439
#define SYSCTL_DID1_PRTNO_1512  0x00BB0000  // LM3S1512
#define SYSCTL_DID1_PRTNO_1538  0x00C70000  // LM3S1538
#define SYSCTL_DID1_PRTNO_1601  0x00DB0000  // LM3S1601
#define SYSCTL_DID1_PRTNO_1607  0x00060000  // LM3S1607
#define SYSCTL_DID1_PRTNO_1608  0x00DA0000  // LM3S1608
#define SYSCTL_DID1_PRTNO_1620  0x00C00000  // LM3S1620
#define SYSCTL_DID1_PRTNO_1621  0x00CD0000  // LM3S1621
#define SYSCTL_DID1_PRTNO_1625  0x00030000  // LM3S1625
#define SYSCTL_DID1_PRTNO_1626  0x00040000  // LM3S1626
#define SYSCTL_DID1_PRTNO_1627  0x00050000  // LM3S1627
#define SYSCTL_DID1_PRTNO_1635  0x00B30000  // LM3S1635
#define SYSCTL_DID1_PRTNO_1636  0x00EB0000  // LM3S1636
#define SYSCTL_DID1_PRTNO_1637  0x00BD0000  // LM3S1637
#define SYSCTL_DID1_PRTNO_1651  0x00B10000  // LM3S1651
#define SYSCTL_DID1_PRTNO_1751  0x00B90000  // LM3S1751
#define SYSCTL_DID1_PRTNO_1776  0x00100000  // LM3S1776
#define SYSCTL_DID1_PRTNO_1811  0x00160000  // LM3S1811
#define SYSCTL_DID1_PRTNO_1816  0x003D0000  // LM3S1816
#define SYSCTL_DID1_PRTNO_1850  0x00B40000  // LM3S1850
#define SYSCTL_DID1_PRTNO_1911  0x00DD0000  // LM3S1911
#define SYSCTL_DID1_PRTNO_1918  0x00DC0000  // LM3S1918
#define SYSCTL_DID1_PRTNO_1937  0x00B70000  // LM3S1937
#define SYSCTL_DID1_PRTNO_1958  0x00BE0000  // LM3S1958
#define SYSCTL_DID1_PRTNO_1960  0x00B50000  // LM3S1960
#define SYSCTL_DID1_PRTNO_1968  0x00B80000  // LM3S1968
#define SYSCTL_DID1_PRTNO_1969  0x00EA0000  // LM3S1969
#define SYSCTL_DID1_PRTNO_1B21  0x00CE0000  // LM3S1B21
#define SYSCTL_DID1_PRTNO_1C21  0x00CA0000  // LM3S1C21
#define SYSCTL_DID1_PRTNO_1C26  0x00CB0000  // LM3S1C26
#define SYSCTL_DID1_PRTNO_1C58  0x00980000  // LM3S1C58
#define SYSCTL_DID1_PRTNO_1D21  0x00B00000  // LM3S1D21
#define SYSCTL_DID1_PRTNO_1D26  0x00CC0000  // LM3S1D26
#define SYSCTL_DID1_PRTNO_1F11  0x001D0000  // LM3S1F11
#define SYSCTL_DID1_PRTNO_1F16  0x001B0000  // LM3S1F16
#define SYSCTL_DID1_PRTNO_1G21  0x00AF0000  // LM3S1G21
#define SYSCTL_DID1_PRTNO_1G58  0x00950000  // LM3S1G58
#define SYSCTL_DID1_PRTNO_1H11  0x001E0000  // LM3S1H11
#define SYSCTL_DID1_PRTNO_1H16  0x001C0000  // LM3S1H16
#define SYSCTL_DID1_PRTNO_1J11  0x000F0000  // LM3S1J11
#define SYSCTL_DID1_PRTNO_1J16  0x003C0000  // LM3S1J16
#define SYSCTL_DID1_PRTNO_1N11  0x000E0000  // LM3S1N11
#define SYSCTL_DID1_PRTNO_1N16  0x003B0000  // LM3S1N16
#define SYSCTL_DID1_PRTNO_1P51  0x00B20000  // LM3S1P51
#define SYSCTL_DID1_PRTNO_1R21  0x009E0000  // LM3S1R21
#define SYSCTL_DID1_PRTNO_1R26  0x00C90000  // LM3S1R26
#define SYSCTL_DID1_PRTNO_1W16  0x00300000  // LM3S1W16
#define SYSCTL_DID1_PRTNO_1Z16  0x002F0000  // LM3S1Z16
#define SYSCTL_DID1_PRTNO_2016  0x00D40000  // LM3S2016
#define SYSCTL_DID1_PRTNO_2110  0x00510000  // LM3S2110
#define SYSCTL_DID1_PRTNO_2139  0x00840000  // LM3S2139
#define SYSCTL_DID1_PRTNO_2276  0x00390000  // LM3S2276
#define SYSCTL_DID1_PRTNO_2410  0x00A20000  // LM3S2410
#define SYSCTL_DID1_PRTNO_2412  0x00590000  // LM3S2412
#define SYSCTL_DID1_PRTNO_2432  0x00560000  // LM3S2432
#define SYSCTL_DID1_PRTNO_2533  0x005A0000  // LM3S2533
#define SYSCTL_DID1_PRTNO_2601  0x00E10000  // LM3S2601
#define SYSCTL_DID1_PRTNO_2608  0x00E00000  // LM3S2608
#define SYSCTL_DID1_PRTNO_2616  0x00330000  // LM3S2616
#define SYSCTL_DID1_PRTNO_2620  0x00570000  // LM3S2620
#define SYSCTL_DID1_PRTNO_2637  0x00850000  // LM3S2637
#define SYSCTL_DID1_PRTNO_2651  0x00530000  // LM3S2651
#define SYSCTL_DID1_PRTNO_2671  0x00800000  // LM3S2671
#define SYSCTL_DID1_PRTNO_2678  0x00500000  // LM3S2678
#define SYSCTL_DID1_PRTNO_2730  0x00A40000  // LM3S2730
#define SYSCTL_DID1_PRTNO_2739  0x00520000  // LM3S2739
#define SYSCTL_DID1_PRTNO_2776  0x003A0000  // LM3S2776
#define SYSCTL_DID1_PRTNO_2793  0x006D0000  // LM3S2793
#define SYSCTL_DID1_PRTNO_2911  0x00E30000  // LM3S2911
#define SYSCTL_DID1_PRTNO_2918  0x00E20000  // LM3S2918
#define SYSCTL_DID1_PRTNO_2919  0x00ED0000  // LM3S2919
#define SYSCTL_DID1_PRTNO_2939  0x00540000  // LM3S2939
#define SYSCTL_DID1_PRTNO_2948  0x008F0000  // LM3S2948
#define SYSCTL_DID1_PRTNO_2950  0x00580000  // LM3S2950
#define SYSCTL_DID1_PRTNO_2965  0x00550000  // LM3S2965
#define SYSCTL_DID1_PRTNO_2B93  0x006C0000  // LM3S2B93
#define SYSCTL_DID1_PRTNO_2D93  0x00940000  // LM3S2D93
#define SYSCTL_DID1_PRTNO_2U93  0x00930000  // LM3S2U93
#define SYSCTL_DID1_PRTNO_3634  0x00080000  // LM3S3634
#define SYSCTL_DID1_PRTNO_3651  0x00430000  // LM3S3651
#define SYSCTL_DID1_PRTNO_3654  0x00C80000  // LM3S3654
#define SYSCTL_DID1_PRTNO_3739  0x00440000  // LM3S3739
#define SYSCTL_DID1_PRTNO_3748  0x00490000  // LM3S3748
#define SYSCTL_DID1_PRTNO_3749  0x00450000  // LM3S3749
#define SYSCTL_DID1_PRTNO_3826  0x00420000  // LM3S3826
#define SYSCTL_DID1_PRTNO_3J26  0x00410000  // LM3S3J26
#define SYSCTL_DID1_PRTNO_3N26  0x00400000  // LM3S3N26
#define SYSCTL_DID1_PRTNO_3W26  0x003F0000  // LM3S3W26
#define SYSCTL_DID1_PRTNO_3Z26  0x003E0000  // LM3S3Z26
#define SYSCTL_DID1_PRTNO_5632  0x00810000  // LM3S5632
#define SYSCTL_DID1_PRTNO_5651  0x000C0000  // LM3S5651
#define SYSCTL_DID1_PRTNO_5652  0x008A0000  // LM3S5652
#define SYSCTL_DID1_PRTNO_5656  0x004D0000  // LM3S5656
#define SYSCTL_DID1_PRTNO_5662  0x00910000  // LM3S5662
#define SYSCTL_DID1_PRTNO_5732  0x00960000  // LM3S5732
#define SYSCTL_DID1_PRTNO_5737  0x00970000  // LM3S5737
#define SYSCTL_DID1_PRTNO_5739  0x00A00000  // LM3S5739
#define SYSCTL_DID1_PRTNO_5747  0x00990000  // LM3S5747
#define SYSCTL_DID1_PRTNO_5749  0x00A70000  // LM3S5749
#define SYSCTL_DID1_PRTNO_5752  0x009A0000  // LM3S5752
#define SYSCTL_DID1_PRTNO_5762  0x009C0000  // LM3S5762
#define SYSCTL_DID1_PRTNO_5791  0x00690000  // LM3S5791
#define SYSCTL_DID1_PRTNO_5951  0x000B0000  // LM3S5951
#define SYSCTL_DID1_PRTNO_5956  0x004E0000  // LM3S5956
#define SYSCTL_DID1_PRTNO_5B91  0x00680000  // LM3S5B91
#define SYSCTL_DID1_PRTNO_5C31  0x002E0000  // LM3S5C31
#define SYSCTL_DID1_PRTNO_5C36  0x002C0000  // LM3S5C36
#define SYSCTL_DID1_PRTNO_5C51  0x005E0000  // LM3S5C51
#define SYSCTL_DID1_PRTNO_5C56  0x005B0000  // LM3S5C56
#define SYSCTL_DID1_PRTNO_5D51  0x005F0000  // LM3S5D51
#define SYSCTL_DID1_PRTNO_5D56  0x005C0000  // LM3S5D56
#define SYSCTL_DID1_PRTNO_5D91  0x00870000  // LM3S5D91
#define SYSCTL_DID1_PRTNO_5G31  0x002D0000  // LM3S5G31
#define SYSCTL_DID1_PRTNO_5G36  0x001F0000  // LM3S5G36
#define SYSCTL_DID1_PRTNO_5G51  0x005D0000  // LM3S5G51
#define SYSCTL_DID1_PRTNO_5G56  0x004F0000  // LM3S5G56
#define SYSCTL_DID1_PRTNO_5K31  0x00090000  // LM3S5K31
#define SYSCTL_DID1_PRTNO_5K36  0x004A0000  // LM3S5K36
#define SYSCTL_DID1_PRTNO_5P31  0x000A0000  // LM3S5P31
#define SYSCTL_DID1_PRTNO_5P36  0x00480000  // LM3S5P36
#define SYSCTL_DID1_PRTNO_5P3B  0x00B60000  // LM3S5P3B
#define SYSCTL_DID1_PRTNO_5P51  0x000D0000  // LM3S5P51
#define SYSCTL_DID1_PRTNO_5P56  0x004C0000  // LM3S5P56
#define SYSCTL_DID1_PRTNO_5R31  0x00070000  // LM3S5R31
#define SYSCTL_DID1_PRTNO_5R36  0x004B0000  // LM3S5R36
#define SYSCTL_DID1_PRTNO_5T36  0x00470000  // LM3S5T36
#define SYSCTL_DID1_PRTNO_5U91  0x007F0000  // LM3S5U91
#define SYSCTL_DID1_PRTNO_5Y36  0x00460000  // LM3S5Y36
#define SYSCTL_DID1_PRTNO_6100  0x00A10000  // LM3S6100
#define SYSCTL_DID1_PRTNO_6110  0x00740000  // LM3S6110
#define SYSCTL_DID1_PRTNO_6420  0x00A50000  // LM3S6420
#define SYSCTL_DID1_PRTNO_6422  0x00820000  // LM3S6422
#define SYSCTL_DID1_PRTNO_6432  0x00750000  // LM3S6432
#define SYSCTL_DID1_PRTNO_6537  0x00760000  // LM3S6537
#define SYSCTL_DID1_PRTNO_6610  0x00710000  // LM3S6610
#define SYSCTL_DID1_PRTNO_6611  0x00E70000  // LM3S6611
#define SYSCTL_DID1_PRTNO_6618  0x00E60000  // LM3S6618
#define SYSCTL_DID1_PRTNO_6633  0x00830000  // LM3S6633
#define SYSCTL_DID1_PRTNO_6637  0x008B0000  // LM3S6637
#define SYSCTL_DID1_PRTNO_6730  0x00A30000  // LM3S6730
#define SYSCTL_DID1_PRTNO_6753  0x00770000  // LM3S6753
#define SYSCTL_DID1_PRTNO_6816  0x00D10000  // LM3S6816
#define SYSCTL_DID1_PRTNO_6911  0x00E90000  // LM3S6911
#define SYSCTL_DID1_PRTNO_6916  0x00D30000  // LM3S6916
#define SYSCTL_DID1_PRTNO_6918  0x00E80000  // LM3S6918
#define SYSCTL_DID1_PRTNO_6938  0x00890000  // LM3S6938
#define SYSCTL_DID1_PRTNO_6950  0x00720000  // LM3S6950
#define SYSCTL_DID1_PRTNO_6952  0x00780000  // LM3S6952
#define SYSCTL_DID1_PRTNO_6965  0x00730000  // LM3S6965
#define SYSCTL_DID1_PRTNO_6C11  0x00AA0000  // LM3S6C11
#define SYSCTL_DID1_PRTNO_6C65  0x00AC0000  // LM3S6C65
#define SYSCTL_DID1_PRTNO_6G11  0x009F0000  // LM3S6G11
#define SYSCTL_DID1_PRTNO_6G65  0x00AB0000  // LM3S6G65
#define SYSCTL_DID1_PRTNO_8530  0x00640000  // LM3S8530
#define SYSCTL_DID1_PRTNO_8538  0x008E0000  // LM3S8538
#define SYSCTL_DID1_PRTNO_8630  0x00610000  // LM3S8630
#define SYSCTL_DID1_PRTNO_8730  0x00630000  // LM3S8730
#define SYSCTL_DID1_PRTNO_8733  0x008D0000  // LM3S8733
#define SYSCTL_DID1_PRTNO_8738  0x00860000  // LM3S8738
#define SYSCTL_DID1_PRTNO_8930  0x00650000  // LM3S8930
#define SYSCTL_DID1_PRTNO_8933  0x008C0000  // LM3S8933
#define SYSCTL_DID1_PRTNO_8938  0x00880000  // LM3S8938
#define SYSCTL_DID1_PRTNO_8962  0x00A60000  // LM3S8962
#define SYSCTL_DID1_PRTNO_8970  0x00620000  // LM3S8970
#define SYSCTL_DID1_PRTNO_8971  0x00D70000  // LM3S8971
#define SYSCTL_DID1_PRTNO_8C62  0x00AE0000  // LM3S8C62
#define SYSCTL_DID1_PRTNO_8G62  0x00AD0000  // LM3S8G62
#define SYSCTL_DID1_PRTNO_9781  0x00CF0000  // LM3S9781
#define SYSCTL_DID1_PRTNO_9790  0x00670000  // LM3S9790
#define SYSCTL_DID1_PRTNO_9792  0x006B0000  // LM3S9792
#define SYSCTL_DID1_PRTNO_9971  0x002D0000  // LM3S9971
#define SYSCTL_DID1_PRTNO_9997  0x00200000  // LM3S9997
#define SYSCTL_DID1_PRTNO_9B81  0x00D00000  // LM3S9B81
#define SYSCTL_DID1_PRTNO_9B90  0x00660000  // LM3S9B90
#define SYSCTL_DID1_PRTNO_9B92  0x006A0000  // LM3S9B92
#define SYSCTL_DID1_PRTNO_9B95  0x006E0000  // LM3S9B95
#define SYSCTL_DID1_PRTNO_9B96  0x006F0000  // LM3S9B96
#define SYSCTL_DID1_PRTNO_9BN2  0x001D0000  // LM3S9BN2
#define SYSCTL_DID1_PRTNO_9BN5  0x001E0000  // LM3S9BN5
#define SYSCTL_DID1_PRTNO_9BN6  0x001F0000  // LM3S9BN6
#define SYSCTL_DID1_PRTNO_9C97  0x00700000  // LM3S9C97
#define SYSCTL_DID1_PRTNO_9CN5  0x007A0000  // LM3S9CN5
#define SYSCTL_DID1_PRTNO_9D81  0x00A90000  // LM3S9D81
#define SYSCTL_DID1_PRTNO_9D90  0x007E0000  // LM3S9D90
#define SYSCTL_DID1_PRTNO_9D92  0x00920000  // LM3S9D92
#define SYSCTL_DID1_PRTNO_9D95  0x00C80000  // LM3S9D95
#define SYSCTL_DID1_PRTNO_9D96  0x009D0000  // LM3S9D96
#define SYSCTL_DID1_PRTNO_9DN5  0x007B0000  // LM3S9DN5
#define SYSCTL_DID1_PRTNO_9DN6  0x007C0000  // LM3S9DN6
#define SYSCTL_DID1_PRTNO_9G97  0x00600000  // LM3S9G97
#define SYSCTL_DID1_PRTNO_9GN5  0x00790000  // LM3S9GN5
#define SYSCTL_DID1_PRTNO_9L71  0x001B0000  // LM3S9L71
#define SYSCTL_DID1_PRTNO_9L97  0x00180000  // LM3S9L97
#define SYSCTL_DID1_PRTNO_9U81  0x00A80000  // LM3S9U81
#define SYSCTL_DID1_PRTNO_9U90  0x007D0000  // LM3S9U90
#define SYSCTL_DID1_PRTNO_9U92  0x00900000  // LM3S9U92
#define SYSCTL_DID1_PRTNO_9U95  0x00B70000  // LM3S9U95
#define SYSCTL_DID1_PRTNO_9U96  0x009B0000  // LM3S9U96
#define SYSCTL_DID1_PRTNO_LM4F110B2QR \
                                0x00180000  // LM4F110B2QR
#define SYSCTL_DID1_PRTNO_LM4F110C4QR \
                                0x00190000  // LM4F110C4QR
#define SYSCTL_DID1_PRTNO_LM4F110E5QR \
                                0x00100000  // LM4F110E5QR
#define SYSCTL_DID1_PRTNO_LM4F110H5QR \
                                0x00110000  // LM4F110H5QR
#define SYSCTL_DID1_PRTNO_LM4F111B2QR \
                                0x00220000  // LM4F111B2QR
#define SYSCTL_DID1_PRTNO_LM4F111C4QR \
                                0x00230000  // LM4F111C4QR
#define SYSCTL_DID1_PRTNO_LM4F111E5QR \
                                0x00200000  // LM4F111E5QR
#define SYSCTL_DID1_PRTNO_LM4F111H5QR \
                                0x00210000  // LM4F111H5QR
#define SYSCTL_DID1_PRTNO_LM4F112C4QC \
                                0x00360000  // LM4F112C4QC
#define SYSCTL_DID1_PRTNO_LM4F112E5QC \
                                0x00300000  // LM4F112E5QC
#define SYSCTL_DID1_PRTNO_LM4F112H5QC \
                                0x00310000  // LM4F112H5QC
#define SYSCTL_DID1_PRTNO_LM4F112H5QD \
                                0x00350000  // LM4F112H5QD
#define SYSCTL_DID1_PRTNO_LM4F120B2QR \
                                0x00010000  // LM4F120B2QR
#define SYSCTL_DID1_PRTNO_LM4F120C4QR \
                                0x00020000  // LM4F120C4QR
#define SYSCTL_DID1_PRTNO_LM4F120E5QR \
                                0x00030000  // LM4F120E5QR
#define SYSCTL_DID1_PRTNO_LM4F120H5QR \
                                0x00040000  // LM4F120H5QR
#define SYSCTL_DID1_PRTNO_LM4F121B2QR \
                                0x00080000  // LM4F121B2QR
#define SYSCTL_DID1_PRTNO_LM4F121C4QR \
                                0x00090000  // LM4F121C4QR
#define SYSCTL_DID1_PRTNO_LM4F121E5QR \
                                0x000A0000  // LM4F121E5QR
#define SYSCTL_DID1_PRTNO_LM4F121H5QR \
                                0x000B0000  // LM4F121H5QR
#define SYSCTL_DID1_PRTNO_LM4F122C4QC \
                                0x00D00000  // LM4F122C4QC
#define SYSCTL_DID1_PRTNO_LM4F122E5QC \
                                0x00D10000  // LM4F122E5QC
#define SYSCTL_DID1_PRTNO_LM4F122H5QC \
                                0x00D20000  // LM4F122H5QC
#define SYSCTL_DID1_PRTNO_LM4F122H5QD \
                                0x00D60000  // LM4F122H5QD
#define SYSCTL_DID1_PRTNO_LM4F130C4QR \
                                0x00480000  // LM4F130C4QR
#define SYSCTL_DID1_PRTNO_LM4F130E5QR \
                                0x00400000  // LM4F130E5QR
#define SYSCTL_DID1_PRTNO_LM4F130H5QR \
                                0x00410000  // LM4F130H5QR
#define SYSCTL_DID1_PRTNO_LM4F131C4QR \
                                0x00520000  // LM4F131C4QR
#define SYSCTL_DID1_PRTNO_LM4F131E5QR \
                                0x00500000  // LM4F131E5QR
#define SYSCTL_DID1_PRTNO_LM4F131H5QR \
                                0x00510000  // LM4F131H5QR
#define SYSCTL_DID1_PRTNO_LM4F132C4QC \
                                0x00660000  // LM4F132C4QC
#define SYSCTL_DID1_PRTNO_LM4F132E5QC \
                                0x00600000  // LM4F132E5QC
#define SYSCTL_DID1_PRTNO_LM4F132H5QC \
                                0x00610000  // LM4F132H5QC
#define SYSCTL_DID1_PRTNO_LM4F132H5QD \
                                0x00650000  // LM4F132H5QD
#define SYSCTL_DID1_PRTNO_LM4F210E5QR \
                                0x00700000  // LM4F210E5QR
#define SYSCTL_DID1_PRTNO_LM4F210H5QR \
                                0x00730000  // LM4F210H5QR
#define SYSCTL_DID1_PRTNO_LM4F211E5QR \
                                0x00800000  // LM4F211E5QR
#define SYSCTL_DID1_PRTNO_LM4F211H5QR \
                                0x00830000  // LM4F211H5QR
#define SYSCTL_DID1_PRTNO_LM4F212H5BB \
                                0x00E90000  // LM4F212H5BB
#define SYSCTL_DID1_PRTNO_LM4F212H5QC \
                                0x00C40000  // LM4F212H5QC
#define SYSCTL_DID1_PRTNO_LM4F212H5QD \
                                0x00C60000  // LM4F212H5QD
#define SYSCTL_DID1_PRTNO_LM4F230E5QR \
                                0x00A00000  // LM4F230E5QR
#define SYSCTL_DID1_PRTNO_LM4F230H5QR \
                                0x00A10000  // LM4F230H5QR
#define SYSCTL_DID1_PRTNO_LM4F231E5QR \
                                0x00B00000  // LM4F231E5QR
#define SYSCTL_DID1_PRTNO_LM4F231H5QR \
                                0x00B10000  // LM4F231H5QR
#define SYSCTL_DID1_PRTNO_LM4F232E5QC \
                                0x00C00000  // LM4F232E5QC
#define SYSCTL_DID1_PRTNO_LM4F232H5BB \
                                0x00E30000  // LM4F232H5BB
#define SYSCTL_DID1_PRTNO_LM4F232H5QC \
                                0x00C10000  // LM4F232H5QC
#define SYSCTL_DID1_PRTNO_LM4F232H5QD \
                                0x00C50000  // LM4F232H5QD
#define SYSCTL_DID1_PRTNO_LM4FS1AH5BB \
                                0x00E50000  // LM4FS1AH5BB
#define SYSCTL_DID1_PRTNO_LM4FS1GH5BB \
                                0x00EA0000  // LM4FS1GH5BB
#define SYSCTL_DID1_PRTNO_LM4FS99H5BB \
                                0x00E40000  // LM4FS99H5BB
#define SYSCTL_DID1_PRTNO_LM4FSXAH5BB \
                                0x00E00000  // LM4FSXAH5BB
#define SYSCTL_DID1_PRTNO_LM4FSXLH5BB \
                                0x00E10000  // LM4FSXLH5BB
#define SYSCTL_DID1_PINCNT_M    0x0000E000  // Package Pin Count
#define SYSCTL_DID1_PINCNT_28   0x00000000  // 28-pin package
#define SYSCTL_DID1_PINCNT_48   0x00002000  // 48-pin package
#define SYSCTL_DID1_PINCNT_100  0x00004000  // 100-pin package
#define SYSCTL_DID1_PINCNT_64   0x00006000  // 64-pin package
#define SYSCTL_DID1_PINCNT_144  0x00008000  // 144-pin package
#define SYSCTL_DID1_PINCNT_157  0x0000A000  // 157-pin package
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
#define SYSCTL_DID1_PKG_QFN     0x00000018  // QFN package
#define SYSCTL_DID1_ROHS        0x00000004  // RoHS-Compliance
#define SYSCTL_DID1_QUAL_M      0x00000003  // Qualification Status
#define SYSCTL_DID1_QUAL_ES     0x00000000  // Engineering Sample (unqualified)
#define SYSCTL_DID1_QUAL_PP     0x00000001  // Pilot Production (unqualified)
#define SYSCTL_DID1_QUAL_FQ     0x00000002  // Fully Qualified
#define SYSCTL_DID1_PRTNO_S     16          // Part number shift

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
#define SYSCTL_DC0_SRAMSZ_48KB  0x00BF0000  // 48 KB of SRAM
#define SYSCTL_DC0_SRAMSZ_64KB  0x00FF0000  // 64 KB of SRAM
#define SYSCTL_DC0_SRAMSZ_96KB  0x017F0000  // 96 KB of SRAM
#define SYSCTL_DC0_FLASHSZ_M    0x0000FFFF  // Flash Size
#define SYSCTL_DC0_FLASHSZ_8KB  0x00000003  // 8 KB of Flash
#define SYSCTL_DC0_FLASHSZ_16KB 0x00000007  // 16 KB of Flash
#define SYSCTL_DC0_FLASHSZ_32KB 0x0000000F  // 32 KB of Flash
#define SYSCTL_DC0_FLASHSZ_64KB 0x0000001F  // 64 KB of Flash
#define SYSCTL_DC0_FLASHSZ_96KB 0x0000002F  // 96 KB of Flash
#define SYSCTL_DC0_FLASHSZ_128K 0x0000003F  // 128 KB of Flash
#define SYSCTL_DC0_FLASHSZ_192K 0x0000005F  // 192 KB of Flash
#define SYSCTL_DC0_FLASHSZ_256K 0x0000007F  // 256 KB of Flash
#define SYSCTL_DC0_FLASHSZ_384K 0x000000BF  // 384 KB of Flash
#define SYSCTL_DC0_FLASHSZ_512K 0x000000FF  // 512 KB of Flash
#define SYSCTL_DC0_SRAMSZ_S     16          // SRAM size shift
#define SYSCTL_DC0_FLASHSZ_S    0           // Flash size shift

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_DC1 register.
//
//*****************************************************************************
#define SYSCTL_DC1_WDT1         0x10000000  // Watchdog Timer1 Present
#define SYSCTL_DC1_CAN2         0x04000000  // CAN Module 2 Present
#define SYSCTL_DC1_CAN1         0x02000000  // CAN Module 1 Present
#define SYSCTL_DC1_CAN0         0x01000000  // CAN Module 0 Present
#define SYSCTL_DC1_PWM1         0x00200000  // PWM Module 1 Present
#define SYSCTL_DC1_PWM0         0x00100000  // PWM Module 0 Present
#define SYSCTL_DC1_ADC1         0x00020000  // ADC Module 1 Present
#define SYSCTL_DC1_ADC0         0x00010000  // ADC Module 0 Present
#define SYSCTL_DC1_MINSYSDIV_M  0x0000F000  // System Clock Divider
#define SYSCTL_DC1_MINSYSDIV_100 \
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
#define SYSCTL_DC4_ETH          0x50000000  // Ethernet present
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
#define SYSCTL_DC7_SW           0x40000000  // Software transfer on uDMA Ch30
#define SYSCTL_DC7_DMACH30      0x40000000  // SW
#define SYSCTL_DC7_DMACH29      0x20000000  // I2S0_TX / CAN1_TX
#define SYSCTL_DC7_DMACH28      0x10000000  // I2S0_RX / CAN1_RX
#define SYSCTL_DC7_DMACH27      0x08000000  // CAN1_TX / ADC1_SS3
#define SYSCTL_DC7_DMACH26      0x04000000  // CAN1_RX / ADC1_SS2
#define SYSCTL_DC7_DMACH25      0x02000000  // SSI1_TX / ADC1_SS1
#define SYSCTL_DC7_SSI1_TX      0x02000000  // SSI1 TX on uDMA Ch25
#define SYSCTL_DC7_SSI1_RX      0x01000000  // SSI1 RX on uDMA Ch24
#define SYSCTL_DC7_DMACH24      0x01000000  // SSI1_RX / ADC1_SS0
#define SYSCTL_DC7_UART1_TX     0x00800000  // UART1 TX on uDMA Ch23
#define SYSCTL_DC7_DMACH23      0x00800000  // UART1_TX / CAN2_TX
#define SYSCTL_DC7_DMACH22      0x00400000  // UART1_RX / CAN2_RX
#define SYSCTL_DC7_UART1_RX     0x00400000  // UART1 RX on uDMA Ch22
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
#define SYSCTL_DC7_SSI0_TX      0x00000800  // SSI0 TX on uDMA Ch11
#define SYSCTL_DC7_DMACH11      0x00000800  // SSI0_TX / SSI1_TX
#define SYSCTL_DC7_SSI0_RX      0x00000400  // SSI0 RX on uDMA Ch10
#define SYSCTL_DC7_DMACH10      0x00000400  // SSI0_RX / SSI1_RX
#define SYSCTL_DC7_UART0_TX     0x00000200  // UART0 TX on uDMA Ch9
#define SYSCTL_DC7_DMACH9       0x00000200  // UART0_TX / UART1_TX
#define SYSCTL_DC7_DMACH8       0x00000100  // UART0_RX / UART1_RX
#define SYSCTL_DC7_UART0_RX     0x00000100  // UART0 RX on uDMA Ch8
#define SYSCTL_DC7_DMACH7       0x00000080  // ETH_TX / Timer2B
#define SYSCTL_DC7_DMACH6       0x00000040  // ETH_RX / Timer2A
#define SYSCTL_DC7_DMACH5       0x00000020  // USB_EP3_TX / Timer2B
#define SYSCTL_DC7_USB_EP3_TX   0x00000020  // USB EP3 TX on uDMA Ch5
#define SYSCTL_DC7_USB_EP3_RX   0x00000010  // USB EP3 RX on uDMA Ch4
#define SYSCTL_DC7_DMACH4       0x00000010  // USB_EP3_RX / Timer2A
#define SYSCTL_DC7_USB_EP2_TX   0x00000008  // USB EP2 TX on uDMA Ch3
#define SYSCTL_DC7_DMACH3       0x00000008  // USB_EP2_TX / Timer3B
#define SYSCTL_DC7_USB_EP2_RX   0x00000004  // USB EP2 RX on uDMA Ch2
#define SYSCTL_DC7_DMACH2       0x00000004  // USB_EP2_RX / Timer3A
#define SYSCTL_DC7_USB_EP1_TX   0x00000002  // USB EP1 TX on uDMA Ch1
#define SYSCTL_DC7_DMACH1       0x00000002  // USB_EP1_TX / UART2_TX
#define SYSCTL_DC7_DMACH0       0x00000001  // USB_EP1_RX / UART2_RX
#define SYSCTL_DC7_USB_EP1_RX   0x00000001  // USB EP1 RX on uDMA Ch0

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
#define SYSCTL_PBORCTL_BORTIM_M 0x0000FFFC  // BOR Time Delay
#define SYSCTL_PBORCTL_BORIOR   0x00000002  // BOR Interrupt or Reset
#define SYSCTL_PBORCTL_BORWT    0x00000001  // BOR Wait and Check for Noise
#define SYSCTL_PBORCTL_BORTIM_S 2

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_LDOPCTL register.
//
//*****************************************************************************
#define SYSCTL_LDOPCTL_M        0x0000003F  // LDO Output Voltage
#define SYSCTL_LDOPCTL_2_50V    0x00000000  // 2.50
#define SYSCTL_LDOPCTL_2_45V    0x00000001  // 2.45
#define SYSCTL_LDOPCTL_2_40V    0x00000002  // 2.40
#define SYSCTL_LDOPCTL_2_35V    0x00000003  // 2.35
#define SYSCTL_LDOPCTL_2_30V    0x00000004  // 2.30
#define SYSCTL_LDOPCTL_2_25V    0x00000005  // 2.25
#define SYSCTL_LDOPCTL_2_75V    0x0000001B  // 2.75
#define SYSCTL_LDOPCTL_2_70V    0x0000001C  // 2.70
#define SYSCTL_LDOPCTL_2_65V    0x0000001D  // 2.65
#define SYSCTL_LDOPCTL_2_60V    0x0000001E  // 2.60
#define SYSCTL_LDOPCTL_2_55V    0x0000001F  // 2.55

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_SRCR0 register.
//
//*****************************************************************************
#define SYSCTL_SRCR0_WDT1       0x10000000  // WDT1 Reset Control
#define SYSCTL_SRCR0_CAN2       0x04000000  // CAN2 Reset Control
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
#define SYSCTL_SRCR1_EPI0       0x40000000  // EPI0 Reset Control
#define SYSCTL_SRCR1_I2S0       0x10000000  // I2S0 Reset Control
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
#define SYSCTL_SRCR2_EPHY0      0x40000000  // PHY0 Reset Control
#define SYSCTL_SRCR2_EMAC0      0x10000000  // MAC0 Reset Control
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
#define SYSCTL_RIS_MOSCPUPRIS   0x00000100  // MOSC Power Up Raw Interrupt
                                            // Status
#define SYSCTL_RIS_USBPLLLRIS   0x00000080  // USB PLL Lock Raw Interrupt
                                            // Status
#define SYSCTL_RIS_PLLLRIS      0x00000040  // PLL Lock Raw Interrupt Status
#define SYSCTL_RIS_CLRIS        0x00000020  // Current Limit Raw Interrupt
                                            // Status
#define SYSCTL_RIS_IOFRIS       0x00000010  // Internal Oscillator Fault Raw
                                            // Interrupt Status
#define SYSCTL_RIS_MOFRIS       0x00000008  // Main Oscillator Fault Raw
                                            // Interrupt Status
#define SYSCTL_RIS_LDORIS       0x00000004  // LDO Power Unregulated Raw
                                            // Interrupt Status
#define SYSCTL_RIS_BORRIS       0x00000002  // Brown-Out Reset Raw Interrupt
                                            // Status
#define SYSCTL_RIS_PLLFRIS      0x00000001  // PLL Fault Raw Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_IMC register.
//
//*****************************************************************************
#define SYSCTL_IMC_MOSCPUPIM    0x00000100  // MOSC Power Up Interrupt Mask
#define SYSCTL_IMC_USBPLLLIM    0x00000080  // USB PLL Lock Interrupt Mask
#define SYSCTL_IMC_PLLLIM       0x00000040  // PLL Lock Interrupt Mask
#define SYSCTL_IMC_CLIM         0x00000020  // Current Limit Interrupt Mask
#define SYSCTL_IMC_IOFIM        0x00000010  // Internal Oscillator Fault
                                            // Interrupt Mask
#define SYSCTL_IMC_MOFIM        0x00000008  // Main Oscillator Fault Interrupt
                                            // Mask
#define SYSCTL_IMC_LDOIM        0x00000004  // LDO Power Unregulated Interrupt
                                            // Mask
#define SYSCTL_IMC_BORIM        0x00000002  // Brown-Out Reset Interrupt Mask
#define SYSCTL_IMC_PLLFIM       0x00000001  // PLL Fault Interrupt Mask

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_MISC register.
//
//*****************************************************************************
#define SYSCTL_MISC_MOSCPUPMIS  0x00000100  // MOSC Power Up Masked Interrupt
                                            // Status
#define SYSCTL_MISC_USBPLLLMIS  0x00000080  // USB PLL Lock Masked Interrupt
                                            // Status
#define SYSCTL_MISC_PLLLMIS     0x00000040  // PLL Lock Masked Interrupt Status
#define SYSCTL_MISC_CLMIS       0x00000020  // Current Limit Masked Interrupt
                                            // Status
#define SYSCTL_MISC_IOFMIS      0x00000010  // Internal Oscillator Fault Masked
                                            // Interrupt Status
#define SYSCTL_MISC_MOFMIS      0x00000008  // Main Oscillator Fault Masked
                                            // Interrupt Status
#define SYSCTL_MISC_LDOMIS      0x00000004  // LDO Power Unregulated Masked
                                            // Interrupt Status
#define SYSCTL_MISC_BORMIS      0x00000002  // BOR Masked Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_RESC register.
//
//*****************************************************************************
#define SYSCTL_RESC_MOSCFAIL    0x00010000  // MOSC Failure Reset
#define SYSCTL_RESC_LDO         0x00000020  // LDO Reset
#define SYSCTL_RESC_WDT1        0x00000020  // Watchdog Timer 1 Reset
#define SYSCTL_RESC_SW          0x00000010  // Software Reset
#define SYSCTL_RESC_WDT0        0x00000008  // Watchdog Timer 0 Reset
#define SYSCTL_RESC_BOR         0x00000004  // Brown-Out Reset
#define SYSCTL_RESC_POR         0x00000002  // Power-On Reset
#define SYSCTL_RESC_EXT         0x00000001  // External Reset

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_RCC register.
//
//*****************************************************************************
#define SYSCTL_RCC_ACG          0x08000000  // Auto Clock Gating
#define SYSCTL_RCC_SYSDIV_M     0x07800000  // System Clock Divisor
#define SYSCTL_RCC_SYSDIV_2     0x00800000  // System clock /2
#define SYSCTL_RCC_SYSDIV_3     0x01000000  // System clock /3
#define SYSCTL_RCC_SYSDIV_4     0x01800000  // System clock /4
#define SYSCTL_RCC_SYSDIV_5     0x02000000  // System clock /5
#define SYSCTL_RCC_SYSDIV_6     0x02800000  // System clock /6
#define SYSCTL_RCC_SYSDIV_7     0x03000000  // System clock /7
#define SYSCTL_RCC_SYSDIV_8     0x03800000  // System clock /8
#define SYSCTL_RCC_SYSDIV_9     0x04000000  // System clock /9
#define SYSCTL_RCC_SYSDIV_10    0x04800000  // System clock /10
#define SYSCTL_RCC_SYSDIV_11    0x05000000  // System clock /11
#define SYSCTL_RCC_SYSDIV_12    0x05800000  // System clock /12
#define SYSCTL_RCC_SYSDIV_13    0x06000000  // System clock /13
#define SYSCTL_RCC_SYSDIV_14    0x06800000  // System clock /14
#define SYSCTL_RCC_SYSDIV_15    0x07000000  // System clock /15
#define SYSCTL_RCC_SYSDIV_16    0x07800000  // System clock /16
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
#define SYSCTL_RCC_OEN          0x00001000  // PLL Output Enable
#define SYSCTL_RCC_BYPASS       0x00000800  // PLL Bypass
#define SYSCTL_RCC_XTAL_M       0x000007C0  // Crystal Value
#define SYSCTL_RCC_XTAL_1MHZ    0x00000000  // 1 MHz
#define SYSCTL_RCC_XTAL_1_84MHZ 0x00000040  // 1.8432 MHz
#define SYSCTL_RCC_XTAL_2MHZ    0x00000080  // 2 MHz
#define SYSCTL_RCC_XTAL_2_45MHZ 0x000000C0  // 2.4576 MHz
#define SYSCTL_RCC_XTAL_3_57MHZ 0x00000100  // 3.579545 MHz
#define SYSCTL_RCC_XTAL_3_68MHZ 0x00000140  // 3.6864 MHz
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
#define SYSCTL_RCC_PLLVER       0x00000400  // PLL Verification
#define SYSCTL_RCC_OSCSRC_M     0x00000030  // Oscillator Source
#define SYSCTL_RCC_OSCSRC_MAIN  0x00000000  // MOSC
#define SYSCTL_RCC_OSCSRC_INT   0x00000010  // IOSC
#define SYSCTL_RCC_OSCSRC_INT4  0x00000020  // IOSC/4
#define SYSCTL_RCC_OSCSRC_30    0x00000030  // 30 kHz
#define SYSCTL_RCC_IOSCVER      0x00000008  // Internal Oscillator Verification
                                            // Timer
#define SYSCTL_RCC_MOSCVER      0x00000004  // Main Oscillator Verification
                                            // Timer
#define SYSCTL_RCC_IOSCDIS      0x00000002  // Internal Oscillator Disable
#define SYSCTL_RCC_MOSCDIS      0x00000001  // Main Oscillator Disable
#define SYSCTL_RCC_SYSDIV_S     23
#define SYSCTL_RCC_PWMDIV_S     17          // Shift to the PWMDIV field
#define SYSCTL_RCC_XTAL_S       6           // Shift to the XTAL field
#define SYSCTL_RCC_OSCSRC_S     4           // Shift to the OSCSRC field

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PLLCFG register.
//
//*****************************************************************************
#define SYSCTL_PLLCFG_OD_M      0x0000C000  // PLL OD Value
#define SYSCTL_PLLCFG_OD_1      0x00000000  // Divide by 1
#define SYSCTL_PLLCFG_OD_2      0x00004000  // Divide by 2
#define SYSCTL_PLLCFG_OD_4      0x00008000  // Divide by 4
#define SYSCTL_PLLCFG_F_M       0x00003FE0  // PLL F Value
#define SYSCTL_PLLCFG_R_M       0x0000001F  // PLL R Value
#define SYSCTL_PLLCFG_F_S       5
#define SYSCTL_PLLCFG_R_S       0

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
#define SYSCTL_RCC2_SYSDIV2_2   0x00800000  // System clock /2
#define SYSCTL_RCC2_SYSDIV2_3   0x01000000  // System clock /3
#define SYSCTL_RCC2_SYSDIV2_4   0x01800000  // System clock /4
#define SYSCTL_RCC2_SYSDIV2_5   0x02000000  // System clock /5
#define SYSCTL_RCC2_SYSDIV2_6   0x02800000  // System clock /6
#define SYSCTL_RCC2_SYSDIV2_7   0x03000000  // System clock /7
#define SYSCTL_RCC2_SYSDIV2_8   0x03800000  // System clock /8
#define SYSCTL_RCC2_SYSDIV2_9   0x04000000  // System clock /9
#define SYSCTL_RCC2_SYSDIV2_10  0x04800000  // System clock /10
#define SYSCTL_RCC2_SYSDIV2_11  0x05000000  // System clock /11
#define SYSCTL_RCC2_SYSDIV2_12  0x05800000  // System clock /12
#define SYSCTL_RCC2_SYSDIV2_13  0x06000000  // System clock /13
#define SYSCTL_RCC2_SYSDIV2_14  0x06800000  // System clock /14
#define SYSCTL_RCC2_SYSDIV2_15  0x07000000  // System clock /15
#define SYSCTL_RCC2_SYSDIV2_16  0x07800000  // System clock /16
#define SYSCTL_RCC2_SYSDIV2_17  0x08000000  // System clock /17
#define SYSCTL_RCC2_SYSDIV2_18  0x08800000  // System clock /18
#define SYSCTL_RCC2_SYSDIV2_19  0x09000000  // System clock /19
#define SYSCTL_RCC2_SYSDIV2_20  0x09800000  // System clock /20
#define SYSCTL_RCC2_SYSDIV2_21  0x0A000000  // System clock /21
#define SYSCTL_RCC2_SYSDIV2_22  0x0A800000  // System clock /22
#define SYSCTL_RCC2_SYSDIV2_23  0x0B000000  // System clock /23
#define SYSCTL_RCC2_SYSDIV2_24  0x0B800000  // System clock /24
#define SYSCTL_RCC2_SYSDIV2_25  0x0C000000  // System clock /25
#define SYSCTL_RCC2_SYSDIV2_26  0x0C800000  // System clock /26
#define SYSCTL_RCC2_SYSDIV2_27  0x0D000000  // System clock /27
#define SYSCTL_RCC2_SYSDIV2_28  0x0D800000  // System clock /28
#define SYSCTL_RCC2_SYSDIV2_29  0x0E000000  // System clock /29
#define SYSCTL_RCC2_SYSDIV2_30  0x0E800000  // System clock /30
#define SYSCTL_RCC2_SYSDIV2_31  0x0F000000  // System clock /31
#define SYSCTL_RCC2_SYSDIV2_32  0x0F800000  // System clock /32
#define SYSCTL_RCC2_SYSDIV2_33  0x10000000  // System clock /33
#define SYSCTL_RCC2_SYSDIV2_34  0x10800000  // System clock /34
#define SYSCTL_RCC2_SYSDIV2_35  0x11000000  // System clock /35
#define SYSCTL_RCC2_SYSDIV2_36  0x11800000  // System clock /36
#define SYSCTL_RCC2_SYSDIV2_37  0x12000000  // System clock /37
#define SYSCTL_RCC2_SYSDIV2_38  0x12800000  // System clock /38
#define SYSCTL_RCC2_SYSDIV2_39  0x13000000  // System clock /39
#define SYSCTL_RCC2_SYSDIV2_40  0x13800000  // System clock /40
#define SYSCTL_RCC2_SYSDIV2_41  0x14000000  // System clock /41
#define SYSCTL_RCC2_SYSDIV2_42  0x14800000  // System clock /42
#define SYSCTL_RCC2_SYSDIV2_43  0x15000000  // System clock /43
#define SYSCTL_RCC2_SYSDIV2_44  0x15800000  // System clock /44
#define SYSCTL_RCC2_SYSDIV2_45  0x16000000  // System clock /45
#define SYSCTL_RCC2_SYSDIV2_46  0x16800000  // System clock /46
#define SYSCTL_RCC2_SYSDIV2_47  0x17000000  // System clock /47
#define SYSCTL_RCC2_SYSDIV2_48  0x17800000  // System clock /48
#define SYSCTL_RCC2_SYSDIV2_49  0x18000000  // System clock /49
#define SYSCTL_RCC2_SYSDIV2_50  0x18800000  // System clock /50
#define SYSCTL_RCC2_SYSDIV2_51  0x19000000  // System clock /51
#define SYSCTL_RCC2_SYSDIV2_52  0x19800000  // System clock /52
#define SYSCTL_RCC2_SYSDIV2_53  0x1A000000  // System clock /53
#define SYSCTL_RCC2_SYSDIV2_54  0x1A800000  // System clock /54
#define SYSCTL_RCC2_SYSDIV2_55  0x1B000000  // System clock /55
#define SYSCTL_RCC2_SYSDIV2_56  0x1B800000  // System clock /56
#define SYSCTL_RCC2_SYSDIV2_57  0x1C000000  // System clock /57
#define SYSCTL_RCC2_SYSDIV2_58  0x1C800000  // System clock /58
#define SYSCTL_RCC2_SYSDIV2_59  0x1D000000  // System clock /59
#define SYSCTL_RCC2_SYSDIV2_60  0x1D800000  // System clock /60
#define SYSCTL_RCC2_SYSDIV2_61  0x1E000000  // System clock /61
#define SYSCTL_RCC2_SYSDIV2_62  0x1E800000  // System clock /62
#define SYSCTL_RCC2_SYSDIV2_63  0x1F000000  // System clock /63
#define SYSCTL_RCC2_SYSDIV2_64  0x1F800000  // System clock /64
#define SYSCTL_RCC2_SYSDIV2LSB  0x00400000  // Additional LSB for SYSDIV2
#define SYSCTL_RCC2_USBPWRDN    0x00004000  // Power-Down USB PLL
#define SYSCTL_RCC2_PWRDN2      0x00002000  // Power-Down PLL 2
#define SYSCTL_RCC2_BYPASS2     0x00000800  // PLL Bypass 2
#define SYSCTL_RCC2_OSCSRC2_M   0x00000070  // Oscillator Source 2
#define SYSCTL_RCC2_OSCSRC2_MO  0x00000000  // MOSC
#define SYSCTL_RCC2_OSCSRC2_IO  0x00000010  // PIOSC
#define SYSCTL_RCC2_OSCSRC2_IO4 0x00000020  // PIOSC/4
#define SYSCTL_RCC2_OSCSRC2_30  0x00000030  // 30 kHz
#define SYSCTL_RCC2_OSCSRC2_419 0x00000060  // 4.194304 MHz
#define SYSCTL_RCC2_OSCSRC2_32  0x00000070  // 32.768 kHz
#define SYSCTL_RCC2_SYSDIV2_S   23

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_MOSCCTL register.
//
//*****************************************************************************
#define SYSCTL_MOSCCTL_NOXTAL   0x00000004  // No Crystal Connected
#define SYSCTL_MOSCCTL_MOSCIM   0x00000002  // MOSC Failure Action
#define SYSCTL_MOSCCTL_CVAL     0x00000001  // Clock Validation for MOSC

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_RCGC0 register.
//
//*****************************************************************************
#define SYSCTL_RCGC0_WDT1       0x10000000  // WDT1 Clock Gating Control
#define SYSCTL_RCGC0_CAN2       0x04000000  // CAN2 Clock Gating Control
#define SYSCTL_RCGC0_CAN1       0x02000000  // CAN1 Clock Gating Control
#define SYSCTL_RCGC0_CAN0       0x01000000  // CAN0 Clock Gating Control
#define SYSCTL_RCGC0_PWM0       0x00100000  // PWM Clock Gating Control
#define SYSCTL_RCGC0_ADC1       0x00020000  // ADC1 Clock Gating Control
#define SYSCTL_RCGC0_ADC0       0x00010000  // ADC0 Clock Gating Control
#define SYSCTL_RCGC0_ADCSPD_M   0x00000F00  // ADC Sample Speed
#define SYSCTL_RCGC0_ADCSPD125K 0x00000000  // 125K samples/second
#define SYSCTL_RCGC0_ADCSPD250K 0x00000100  // 250K samples/second
#define SYSCTL_RCGC0_ADCSPD500K 0x00000200  // 500K samples/second
#define SYSCTL_RCGC0_ADCSPD1M   0x00000300  // 1M samples/second
#define SYSCTL_RCGC0_ADC1SPD_M  0x00000C00  // ADC1 Sample Speed
#define SYSCTL_RCGC0_ADC1SPD_125K \
                                0x00000000  // 125K samples/second
#define SYSCTL_RCGC0_ADC1SPD_250K \
                                0x00000400  // 250K samples/second
#define SYSCTL_RCGC0_ADC1SPD_500K \
                                0x00000800  // 500K samples/second
#define SYSCTL_RCGC0_ADC1SPD_1M 0x00000C00  // 1M samples/second
#define SYSCTL_RCGC0_ADC0SPD_M  0x00000300  // ADC0 Sample Speed
#define SYSCTL_RCGC0_ADC0SPD_125K \
                                0x00000000  // 125K samples/second
#define SYSCTL_RCGC0_ADC0SPD_250K \
                                0x00000100  // 250K samples/second
#define SYSCTL_RCGC0_ADC0SPD_500K \
                                0x00000200  // 500K samples/second
#define SYSCTL_RCGC0_ADC0SPD_1M 0x00000300  // 1M samples/second
#define SYSCTL_RCGC0_HIB        0x00000040  // HIB Clock Gating Control
#define SYSCTL_RCGC0_WDT0       0x00000008  // WDT0 Clock Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_RCGC1 register.
//
//*****************************************************************************
#define SYSCTL_RCGC1_EPI0       0x40000000  // EPI0 Clock Gating
#define SYSCTL_RCGC1_I2S0       0x10000000  // I2S0 Clock Gating
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
#define SYSCTL_RCGC2_EPHY0      0x40000000  // PHY0 Clock Gating Control
#define SYSCTL_RCGC2_EMAC0      0x10000000  // MAC0 Clock Gating Control
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
#define SYSCTL_SCGC0_CAN2       0x04000000  // CAN2 Clock Gating Control
#define SYSCTL_SCGC0_CAN1       0x02000000  // CAN1 Clock Gating Control
#define SYSCTL_SCGC0_CAN0       0x01000000  // CAN0 Clock Gating Control
#define SYSCTL_SCGC0_PWM0       0x00100000  // PWM Clock Gating Control
#define SYSCTL_SCGC0_ADC1       0x00020000  // ADC1 Clock Gating Control
#define SYSCTL_SCGC0_ADC0       0x00010000  // ADC0 Clock Gating Control
#define SYSCTL_SCGC0_ADCSPD_M   0x00000F00  // ADC Sample Speed
#define SYSCTL_SCGC0_ADCSPD125K 0x00000000  // 125K samples/second
#define SYSCTL_SCGC0_ADCSPD250K 0x00000100  // 250K samples/second
#define SYSCTL_SCGC0_ADCSPD500K 0x00000200  // 500K samples/second
#define SYSCTL_SCGC0_ADCSPD1M   0x00000300  // 1M samples/second
#define SYSCTL_SCGC0_ADC1SPD_M  0x00000C00  // ADC1 Sample Speed
#define SYSCTL_SCGC0_ADC1SPD_125K \
                                0x00000000  // 125K samples/second
#define SYSCTL_SCGC0_ADC1SPD_250K \
                                0x00000400  // 250K samples/second
#define SYSCTL_SCGC0_ADC1SPD_500K \
                                0x00000800  // 500K samples/second
#define SYSCTL_SCGC0_ADC1SPD_1M 0x00000C00  // 1M samples/second
#define SYSCTL_SCGC0_ADC0SPD_M  0x00000300  // ADC0 Sample Speed
#define SYSCTL_SCGC0_ADC0SPD_125K \
                                0x00000000  // 125K samples/second
#define SYSCTL_SCGC0_ADC0SPD_250K \
                                0x00000100  // 250K samples/second
#define SYSCTL_SCGC0_ADC0SPD_500K \
                                0x00000200  // 500K samples/second
#define SYSCTL_SCGC0_ADC0SPD_1M 0x00000300  // 1M samples/second
#define SYSCTL_SCGC0_HIB        0x00000040  // HIB Clock Gating Control
#define SYSCTL_SCGC0_WDT0       0x00000008  // WDT0 Clock Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_SCGC1 register.
//
//*****************************************************************************
#define SYSCTL_SCGC1_EPI0       0x40000000  // EPI0 Clock Gating
#define SYSCTL_SCGC1_I2S0       0x10000000  // I2S0 Clock Gating
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
#define SYSCTL_SCGC2_EPHY0      0x40000000  // PHY0 Clock Gating Control
#define SYSCTL_SCGC2_EMAC0      0x10000000  // MAC0 Clock Gating Control
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
#define SYSCTL_DCGC0_CAN2       0x04000000  // CAN2 Clock Gating Control
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
#define SYSCTL_DCGC1_EPI0       0x40000000  // EPI0 Clock Gating
#define SYSCTL_DCGC1_I2S0       0x10000000  // I2S0 Clock Gating
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
#define SYSCTL_DCGC2_EPHY0      0x40000000  // PHY0 Clock Gating Control
#define SYSCTL_DCGC2_EMAC0      0x10000000  // MAC0 Clock Gating Control
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
// The following are defines for the bit fields in the SYSCTL_DSLPCLKCFG
// register.
//
//*****************************************************************************
#define SYSCTL_DSLPCLKCFG_D_M   0x1F800000  // Divider Field Override
#define SYSCTL_DSLPCLKCFG_D_1   0x00000000  // System clock /1
#define SYSCTL_DSLPCLKCFG_D_2   0x00800000  // System clock /2
#define SYSCTL_DSLPCLKCFG_D_3   0x01000000  // System clock /3
#define SYSCTL_DSLPCLKCFG_D_4   0x01800000  // System clock /4
#define SYSCTL_DSLPCLKCFG_D_5   0x02000000  // System clock /5
#define SYSCTL_DSLPCLKCFG_D_6   0x02800000  // System clock /6
#define SYSCTL_DSLPCLKCFG_D_7   0x03000000  // System clock /7
#define SYSCTL_DSLPCLKCFG_D_8   0x03800000  // System clock /8
#define SYSCTL_DSLPCLKCFG_D_9   0x04000000  // System clock /9
#define SYSCTL_DSLPCLKCFG_D_10  0x04800000  // System clock /10
#define SYSCTL_DSLPCLKCFG_D_11  0x05000000  // System clock /11
#define SYSCTL_DSLPCLKCFG_D_12  0x05800000  // System clock /12
#define SYSCTL_DSLPCLKCFG_D_13  0x06000000  // System clock /13
#define SYSCTL_DSLPCLKCFG_D_14  0x06800000  // System clock /14
#define SYSCTL_DSLPCLKCFG_D_15  0x07000000  // System clock /15
#define SYSCTL_DSLPCLKCFG_D_16  0x07800000  // System clock /16
#define SYSCTL_DSLPCLKCFG_D_17  0x08000000  // System clock /17
#define SYSCTL_DSLPCLKCFG_D_18  0x08800000  // System clock /18
#define SYSCTL_DSLPCLKCFG_D_19  0x09000000  // System clock /19
#define SYSCTL_DSLPCLKCFG_D_20  0x09800000  // System clock /20
#define SYSCTL_DSLPCLKCFG_D_21  0x0A000000  // System clock /21
#define SYSCTL_DSLPCLKCFG_D_22  0x0A800000  // System clock /22
#define SYSCTL_DSLPCLKCFG_D_23  0x0B000000  // System clock /23
#define SYSCTL_DSLPCLKCFG_D_24  0x0B800000  // System clock /24
#define SYSCTL_DSLPCLKCFG_D_25  0x0C000000  // System clock /25
#define SYSCTL_DSLPCLKCFG_D_26  0x0C800000  // System clock /26
#define SYSCTL_DSLPCLKCFG_D_27  0x0D000000  // System clock /27
#define SYSCTL_DSLPCLKCFG_D_28  0x0D800000  // System clock /28
#define SYSCTL_DSLPCLKCFG_D_29  0x0E000000  // System clock /29
#define SYSCTL_DSLPCLKCFG_D_30  0x0E800000  // System clock /30
#define SYSCTL_DSLPCLKCFG_D_31  0x0F000000  // System clock /31
#define SYSCTL_DSLPCLKCFG_D_32  0x0F800000  // System clock /32
#define SYSCTL_DSLPCLKCFG_D_33  0x10000000  // System clock /33
#define SYSCTL_DSLPCLKCFG_D_34  0x10800000  // System clock /34
#define SYSCTL_DSLPCLKCFG_D_35  0x11000000  // System clock /35
#define SYSCTL_DSLPCLKCFG_D_36  0x11800000  // System clock /36
#define SYSCTL_DSLPCLKCFG_D_37  0x12000000  // System clock /37
#define SYSCTL_DSLPCLKCFG_D_38  0x12800000  // System clock /38
#define SYSCTL_DSLPCLKCFG_D_39  0x13000000  // System clock /39
#define SYSCTL_DSLPCLKCFG_D_40  0x13800000  // System clock /40
#define SYSCTL_DSLPCLKCFG_D_41  0x14000000  // System clock /41
#define SYSCTL_DSLPCLKCFG_D_42  0x14800000  // System clock /42
#define SYSCTL_DSLPCLKCFG_D_43  0x15000000  // System clock /43
#define SYSCTL_DSLPCLKCFG_D_44  0x15800000  // System clock /44
#define SYSCTL_DSLPCLKCFG_D_45  0x16000000  // System clock /45
#define SYSCTL_DSLPCLKCFG_D_46  0x16800000  // System clock /46
#define SYSCTL_DSLPCLKCFG_D_47  0x17000000  // System clock /47
#define SYSCTL_DSLPCLKCFG_D_48  0x17800000  // System clock /48
#define SYSCTL_DSLPCLKCFG_D_49  0x18000000  // System clock /49
#define SYSCTL_DSLPCLKCFG_D_50  0x18800000  // System clock /50
#define SYSCTL_DSLPCLKCFG_D_51  0x19000000  // System clock /51
#define SYSCTL_DSLPCLKCFG_D_52  0x19800000  // System clock /52
#define SYSCTL_DSLPCLKCFG_D_53  0x1A000000  // System clock /53
#define SYSCTL_DSLPCLKCFG_D_54  0x1A800000  // System clock /54
#define SYSCTL_DSLPCLKCFG_D_55  0x1B000000  // System clock /55
#define SYSCTL_DSLPCLKCFG_D_56  0x1B800000  // System clock /56
#define SYSCTL_DSLPCLKCFG_D_57  0x1C000000  // System clock /57
#define SYSCTL_DSLPCLKCFG_D_58  0x1C800000  // System clock /58
#define SYSCTL_DSLPCLKCFG_D_59  0x1D000000  // System clock /59
#define SYSCTL_DSLPCLKCFG_D_60  0x1D800000  // System clock /60
#define SYSCTL_DSLPCLKCFG_D_61  0x1E000000  // System clock /61
#define SYSCTL_DSLPCLKCFG_D_62  0x1E800000  // System clock /62
#define SYSCTL_DSLPCLKCFG_D_63  0x1F000000  // System clock /63
#define SYSCTL_DSLPCLKCFG_D_64  0x1F800000  // System clock /64
#define SYSCTL_DSLPCLKCFG_O_M   0x00000070  // Clock Source
#define SYSCTL_DSLPCLKCFG_O_IGN 0x00000000  // MOSC
#define SYSCTL_DSLPCLKCFG_O_IO  0x00000010  // PIOSC
#define SYSCTL_DSLPCLKCFG_O_30  0x00000030  // 30 kHz
#define SYSCTL_DSLPCLKCFG_O_32  0x00000070  // 32.768 kHz
#define SYSCTL_DSLPCLKCFG_PIOSCPD \
                                0x00000002  // PIOSC Power Down Request
#define SYSCTL_DSLPCLKCFG_IOSC  0x00000001  // IOSC Clock Source
#define SYSCTL_DSLPCLKCFG_D_S   23

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
// The following are defines for the bit fields in the SYSCTL_CLKVCLR register.
//
//*****************************************************************************
#define SYSCTL_CLKVCLR_VERCLR   0x00000001  // Clock Verification Clear

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
// The following are defines for the bit fields in the SYSCTL_LDOARST register.
//
//*****************************************************************************
#define SYSCTL_LDOARST_LDOARST  0x00000001  // LDO Reset

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PLLFREQ0
// register.
//
//*****************************************************************************
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
// The following are defines for the bit fields in the SYSCTL_I2SMCLKCFG
// register.
//
//*****************************************************************************
#define SYSCTL_I2SMCLKCFG_RXEN  0x80000000  // RX Clock Enable
#define SYSCTL_I2SMCLKCFG_RXI_M 0x3FF00000  // RX Clock Integer Input
#define SYSCTL_I2SMCLKCFG_RXF_M 0x000F0000  // RX Clock Fractional Input
#define SYSCTL_I2SMCLKCFG_TXEN  0x00008000  // TX Clock Enable
#define SYSCTL_I2SMCLKCFG_TXI_M 0x00003FF0  // TX Clock Integer Input
#define SYSCTL_I2SMCLKCFG_TXF_M 0x0000000F  // TX Clock Fractional Input
#define SYSCTL_I2SMCLKCFG_RXI_S 20
#define SYSCTL_I2SMCLKCFG_RXF_S 16
#define SYSCTL_I2SMCLKCFG_TXI_S 4
#define SYSCTL_I2SMCLKCFG_TXF_S 0

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
#define SYSCTL_NVMSTAT_TPSW     0x00000010  // Third Party Software Present
#define SYSCTL_NVMSTAT_FWB      0x00000001  // 32 Word Flash Write Buffer
                                            // Active

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
// The following are defines for the bit fields in the SYSCTL_SRLPC register.
//
//*****************************************************************************
#define SYSCTL_SRLPC_R0         0x00000001  // LPC Module Software Reset

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_SRPECI register.
//
//*****************************************************************************
#define SYSCTL_SRPECI_R0        0x00000001  // PECI Module Software Reset

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_SRFAN register.
//
//*****************************************************************************
#define SYSCTL_SRFAN_R0         0x00000001  // FAN Module Software Reset

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
// The following are defines for the bit fields in the SYSCTL_RCGCLPC register.
//
//*****************************************************************************
#define SYSCTL_RCGCLPC_R0       0x00000001  // LPC Module Run Mode Clock Gating
                                            // Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_RCGCPECI
// register.
//
//*****************************************************************************
#define SYSCTL_RCGCPECI_R0      0x00000001  // PECI Module Run Mode Clock
                                            // Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_RCGCFAN register.
//
//*****************************************************************************
#define SYSCTL_RCGCFAN_R0       0x00000001  // FAN Module Run Mode Clock Gating
                                            // Control

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
// The following are defines for the bit fields in the SYSCTL_SCGCDMA register.
//
//*****************************************************************************
#define SYSCTL_SCGCDMA_S0       0x00000001  // uDMA Module Sleep Mode Clock
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
// The following are defines for the bit fields in the SYSCTL_SCGCLPC register.
//
//*****************************************************************************
#define SYSCTL_SCGCLPC_S0       0x00000001  // LPC Module Sleep Mode Clock
                                            // Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_SCGCPECI
// register.
//
//*****************************************************************************
#define SYSCTL_SCGCPECI_S0      0x00000001  // PECI Module Sleep Mode Clock
                                            // Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_SCGCFAN register.
//
//*****************************************************************************
#define SYSCTL_SCGCFAN_S0       0x00000001  // FAN Module Sleep Mode Clock
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
// The following are defines for the bit fields in the SYSCTL_DCGCDMA register.
//
//*****************************************************************************
#define SYSCTL_DCGCDMA_D0       0x00000001  // uDMA Module Deep-Sleep Mode
                                            // Clock Gating Control

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
// The following are defines for the bit fields in the SYSCTL_DCGCLPC register.
//
//*****************************************************************************
#define SYSCTL_DCGCLPC_D0       0x00000001  // LPC Module Deep-Sleep Mode Clock
                                            // Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_DCGCPECI
// register.
//
//*****************************************************************************
#define SYSCTL_DCGCPECI_D0      0x00000001  // PECI Module Deep-Sleep Mode
                                            // Clock Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_DCGCFAN register.
//
//*****************************************************************************
#define SYSCTL_DCGCFAN_D0       0x00000001  // FAN Module Deep-Sleep Mode Clock
                                            // Gating Control

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
#define SYSCTL_PCTIMER_P5       0x00000020  // Timer 5 Power Control
#define SYSCTL_PCTIMER_P4       0x00000010  // Timer 4 Power Control
#define SYSCTL_PCTIMER_P3       0x00000008  // Timer 3 Power Control
#define SYSCTL_PCTIMER_P2       0x00000004  // Timer 2 Power Control
#define SYSCTL_PCTIMER_P1       0x00000002  // Timer 1 Power Control
#define SYSCTL_PCTIMER_P0       0x00000001  // Timer 0 Power Control

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
#define SYSCTL_PCPWM_P1         0x00000002  // PWM Module 1 Power Control
#define SYSCTL_PCPWM_P0         0x00000001  // PWM Module 0 Power Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PCQEI register.
//
//*****************************************************************************
#define SYSCTL_PCQEI_P1         0x00000002  // QEI Module 1 Power Control
#define SYSCTL_PCQEI_P0         0x00000001  // QEI Module 0 Power Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PCLPC register.
//
//*****************************************************************************
#define SYSCTL_PCLPC_P0         0x00000001  // LPC Module Power Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PCPECI register.
//
//*****************************************************************************
#define SYSCTL_PCPECI_P0        0x00000001  // PECI Module Power Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PCFAN register.
//
//*****************************************************************************
#define SYSCTL_PCFAN_P0         0x00000001  // FAN Module Power Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PCEEPROM
// register.
//
//*****************************************************************************
#define SYSCTL_PCEEPROM_P0      0x00000001  // EEPROM Module Power Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PCWTIMER
// register.
//
//*****************************************************************************
#define SYSCTL_PCWTIMER_P5      0x00000020  // Wide Timer 5 Power Control
#define SYSCTL_PCWTIMER_P4      0x00000010  // Wide Timer 4 Power Control
#define SYSCTL_PCWTIMER_P3      0x00000008  // Wide Timer 3 Power Control
#define SYSCTL_PCWTIMER_P2      0x00000004  // Wide Timer 2 Power Control
#define SYSCTL_PCWTIMER_P1      0x00000002  // Wide Timer 1 Power Control
#define SYSCTL_PCWTIMER_P0      0x00000001  // Wide Timer 0 Power Control

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
// The following are defines for the bit fields in the SYSCTL_PRLPC register.
//
//*****************************************************************************
#define SYSCTL_PRLPC_R0         0x00000001  // LPC Module Peripheral Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PRPECI register.
//
//*****************************************************************************
#define SYSCTL_PRPECI_R0        0x00000001  // PECI Module Peripheral Ready

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_PRFAN register.
//
//*****************************************************************************
#define SYSCTL_PRFAN_R0         0x00000001  // FAN Module Peripheral Ready

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
// The following definitions are deprecated.
//
//*****************************************************************************
#ifndef DEPRECATED

//*****************************************************************************
//
// The following are deprecated defines for the System Control register
// addresses.
//
//*****************************************************************************
#define SYSCTL_GPIOHSCTL        0x400FE06C  // GPIO High-Speed Control
#define SYSCTL_USER0            0x400FE1E0  // NV User Register 0
#define SYSCTL_USER1            0x400FE1E4  // NV User Register 1

//*****************************************************************************
//
// The following are deprecated defines for the bit fields in the SYSCTL_DID0
// register.
//
//*****************************************************************************
#define SYSCTL_DID0_VER_MASK    0x70000000  // DID0 version mask
#define SYSCTL_DID0_CLASS_MASK  0x00FF0000  // Device Class
#define SYSCTL_DID0_MAJ_MASK    0x0000FF00  // Major revision mask
#define SYSCTL_DID0_MAJ_A       0x00000000  // Major revision A
#define SYSCTL_DID0_MAJ_B       0x00000100  // Major revision B
#define SYSCTL_DID0_MAJ_C       0x00000200  // Major revision C
#define SYSCTL_DID0_MIN_MASK    0x000000FF  // Minor revision mask

//*****************************************************************************
//
// The following are deprecated defines for the bit fields in the SYSCTL_DID1
// register.
//
//*****************************************************************************
#define SYSCTL_DID1_VER_MASK    0xF0000000  // Register version mask
#define SYSCTL_DID1_FAM_MASK    0x0F000000  // Family mask
#define SYSCTL_DID1_FAM_S       0x00000000  // Stellaris family
#define SYSCTL_DID1_PRTNO_MASK  0x00FF0000  // Part number mask
#define SYSCTL_DID1_PINCNT_MASK 0x0000E000  // Pin count
#define SYSCTL_DID1_TEMP_MASK   0x000000E0  // Temperature range mask
#define SYSCTL_DID1_PKG_MASK    0x00000018  // Package mask
#define SYSCTL_DID1_PKG_48QFP   0x00000008  // QFP package
#define SYSCTL_DID1_QUAL_MASK   0x00000003  // Qualification status mask
#define SYSCTL_DID1_PKG_28SOIC  0x00000000  // SOIC package
#define SYSCTL_DID1_PRTNO_SHIFT 16

//*****************************************************************************
//
// The following are deprecated defines for the bit fields in the SYSCTL_DC0
// register.
//
//*****************************************************************************
#define SYSCTL_DC0_SRAMSZ_MASK  0xFFFF0000  // SRAM size mask
#define SYSCTL_DC0_FLASHSZ_MASK 0x0000FFFF  // Flash size mask

//*****************************************************************************
//
// The following are deprecated defines for the bit fields in the SYSCTL_DC1
// register.
//
//*****************************************************************************
#define SYSCTL_DC1_PWM          0x00100000  // PWM Module Present
#define SYSCTL_DC1_ADC          0x00010000  // ADC Module Present
#define SYSCTL_DC1_SYSDIV_MASK  0x0000F000  // Minimum system divider mask
#define SYSCTL_DC1_ADCSPD_MASK  0x00000F00  // ADC speed mask
#define SYSCTL_DC1_ADCSPD_M     0x00000F00  // Max ADC Speed
#define SYSCTL_DC1_ADCSPD_125K  0x00000000  // 125Ksps ADC
#define SYSCTL_DC1_ADCSPD_250K  0x00000100  // 250K samples/second
#define SYSCTL_DC1_ADCSPD_500K  0x00000200  // 500K samples/second
#define SYSCTL_DC1_ADCSPD_1M    0x00000300  // 1M samples/second
#define SYSCTL_DC1_WDOG         0x00000008  // Watchdog present
#define SYSCTL_DC1_WDT          0x00000008  // Watchdog Timer Present

//*****************************************************************************
//
// The following are deprecated defines for the bit fields in the SYSCTL_DC2
// register.
//
//*****************************************************************************
#define SYSCTL_DC2_I2C          0x00001000  // I2C present
#define SYSCTL_DC2_QEI          0x00000100  // QEI present
#define SYSCTL_DC2_SSI          0x00000010  // SSI present

//*****************************************************************************
//
// The following are deprecated defines for the bit fields in the SYSCTL_DC3
// register.
//
//*****************************************************************************
#define SYSCTL_DC3_ADC7         0x00800000  // ADC7 Pin Present
#define SYSCTL_DC3_ADC6         0x00400000  // ADC6 Pin Present
#define SYSCTL_DC3_ADC5         0x00200000  // ADC5 Pin Present
#define SYSCTL_DC3_ADC4         0x00100000  // ADC4 Pin Present
#define SYSCTL_DC3_ADC3         0x00080000  // ADC3 Pin Present
#define SYSCTL_DC3_ADC2         0x00040000  // ADC2 Pin Present
#define SYSCTL_DC3_ADC1         0x00020000  // ADC1 Pin Present
#define SYSCTL_DC3_ADC0         0x00010000  // ADC0 Pin Present
#define SYSCTL_DC3_MC_FAULT0    0x00008000  // MC0 fault pin present

//*****************************************************************************
//
// The following are deprecated defines for the bit fields in the
// SYSCTL_PBORCTL register.
//
//*****************************************************************************
#define SYSCTL_PBORCTL_BOR_MASK 0x0000FFFC  // BOR wait timer
#define SYSCTL_PBORCTL_BOR_SH   2

//*****************************************************************************
//
// The following are deprecated defines for the bit fields in the
// SYSCTL_LDOPCTL register.
//
//*****************************************************************************
#define SYSCTL_LDOPCTL_MASK     0x0000003F  // Voltage adjust mask

//*****************************************************************************
//
// The following are deprecated defines for the bit fields in the SYSCTL_SRCR0
// register.
//
//*****************************************************************************
#define SYSCTL_SRCR0_PWM        0x00100000  // PWM Reset Control
#define SYSCTL_SRCR0_ADC        0x00010000  // ADC0 Reset Control
#define SYSCTL_SRCR0_WDT        0x00000008  // WDT Reset Control

//*****************************************************************************
//
// The following are deprecated defines for the bit fields in the SYSCTL_RESC
// register.
//
//*****************************************************************************
#define SYSCTL_RESC_WDOG        0x00000008  // Watchdog reset
#define SYSCTL_RESC_WDT         0x00000008  // Watchdog Timer Reset

//*****************************************************************************
//
// The following are deprecated defines for the bit fields in the SYSCTL_RCC
// register.
//
//*****************************************************************************
#define SYSCTL_RCC_SYSDIV_MASK  0x07800000  // System clock divider
#define SYSCTL_RCC_USE_SYSDIV   0x00400000  // Use sytem clock divider
#define SYSCTL_RCC_USE_PWMDIV   0x00100000  // Use PWM clock divider
#define SYSCTL_RCC_PWMDIV_MASK  0x000E0000  // PWM clock divider
#define SYSCTL_RCC_OE           0x00001000  // PLL output enable
#define SYSCTL_RCC_XTAL_3_68MHz 0x00000140  // Using a 3.6864 MHz crystal
#define SYSCTL_RCC_XTAL_4MHz    0x00000180  // Using a 4 MHz crystal
#define SYSCTL_RCC_XTAL_MASK    0x000003C0  // Crystal attached to main osc
#define SYSCTL_RCC_OSCSRC_MASK  0x00000030  // Oscillator input select
#define SYSCTL_RCC_SYSDIV_SHIFT 23          // Shift to the SYSDIV field
#define SYSCTL_RCC_PWMDIV_SHIFT 17          // Shift to the PWMDIV field
#define SYSCTL_RCC_XTAL_SHIFT   6           // Shift to the XTAL field
#define SYSCTL_RCC_OSCSRC_SHIFT 4           // Shift to the OSCSRC field

//*****************************************************************************
//
// The following are deprecated defines for the bit fields in the SYSCTL_PLLCFG
// register.
//
//*****************************************************************************
#define SYSCTL_PLLCFG_OD_MASK   0x0000C000  // Output divider
#define SYSCTL_PLLCFG_F_MASK    0x00003FE0  // PLL multiplier
#define SYSCTL_PLLCFG_R_MASK    0x0000001F  // Input predivider
#define SYSCTL_PLLCFG_F_SHIFT   5
#define SYSCTL_PLLCFG_R_SHIFT   0

//*****************************************************************************
//
// The following are deprecated defines for the bit fields in the
// SYSCTL_GPIOHSCTL register.
//
//*****************************************************************************
#define SYSCTL_GPIOHSCTL_PORTA  0x00000001  // Port A High-Speed
#define SYSCTL_GPIOHSCTL_PORTB  0x00000002  // Port B High-Speed
#define SYSCTL_GPIOHSCTL_PORTC  0x00000004  // Port C High-Speed
#define SYSCTL_GPIOHSCTL_PORTD  0x00000008  // Port D High-Speed
#define SYSCTL_GPIOHSCTL_PORTE  0x00000010  // Port E High-Speed
#define SYSCTL_GPIOHSCTL_PORTF  0x00000020  // Port F High-Speed
#define SYSCTL_GPIOHSCTL_PORTG  0x00000040  // Port G High-Speed
#define SYSCTL_GPIOHSCTL_PORTH  0x00000080  // Port H High-Speed

//*****************************************************************************
//
// The following are deprecated defines for the bit fields in the SYSCTL_RCC2
// register.
//
//*****************************************************************************
#define SYSCTL_RCC2_USEFRACT    0x40000000  // Use fractional divider
#define SYSCTL_RCC2_SYSDIV2_MSK 0x1F800000  // System clock divider
#define SYSCTL_RCC2_FRACT       0x00400000  // Fractional divide
#define SYSCTL_RCC2_OSCSRC2_MSK 0x00000070  // Oscillator input select

//*****************************************************************************
//
// The following are deprecated defines for the bit fields in the SYSCTL_RCGC0
// register.
//
//*****************************************************************************
#define SYSCTL_RCGC0_PWM        0x00100000  // PWM Clock Gating Control
#define SYSCTL_RCGC0_ADC        0x00010000  // ADC0 Clock Gating Control
#define SYSCTL_RCGC0_WDT        0x00000008  // WDT Clock Gating Control

//*****************************************************************************
//
// The following are deprecated defines for the bit fields in the SYSCTL_SCGC0
// register.
//
//*****************************************************************************
#define SYSCTL_SCGC0_PWM        0x00100000  // PWM Clock Gating Control
#define SYSCTL_SCGC0_ADC        0x00010000  // ADC0 Clock Gating Control
#define SYSCTL_SCGC0_WDT        0x00000008  // WDT Clock Gating Control

//*****************************************************************************
//
// The following are deprecated defines for the bit fields in the SYSCTL_DCGC0
// register.
//
//*****************************************************************************
#define SYSCTL_DCGC0_PWM        0x00100000  // PWM Clock Gating Control
#define SYSCTL_DCGC0_ADC        0x00010000  // ADC0 Clock Gating Control
#define SYSCTL_DCGC0_WDT        0x00000008  // WDT Clock Gating Control

//*****************************************************************************
//
// The following are deprecated defines for the bit fields in the
// SYSCTL_DSLPCLKCFG register.
//
//*****************************************************************************
#define SYSCTL_DSLPCLKCFG_D_MSK 0x1F800000  // Deep sleep system clock override
#define SYSCTL_DSLPCLKCFG_O_MSK 0x00000070  // Deep sleep oscillator override

//*****************************************************************************
//
// The following are deprecated defines for the bit fields in the
// SYSCTL_CLKVCLR register.
//
//*****************************************************************************
#define SYSCTL_CLKVCLR_CLR      0x00000001  // Clear clock verification fault

//*****************************************************************************
//
// The following are deprecated defines for the bit fields in the
// SYSCTL_LDOARST register.
//
//*****************************************************************************
#define SYSCTL_LDOARST_ARST     0x00000001  // Allow LDO to reset device

//*****************************************************************************
//
// The following are deprecated defines for the bit fields in the SYSCTL_SRCR0,
// SYSCTL_RCGC0, SYSCTL_SCGC0, and SYSCTL_DCGC0 registers.
//
//*****************************************************************************
#define SYSCTL_SET0_CAN2        0x04000000  // CAN 2 module
#define SYSCTL_SET0_CAN1        0x02000000  // CAN 1 module
#define SYSCTL_SET0_CAN0        0x01000000  // CAN 0 module
#define SYSCTL_SET0_PWM         0x00100000  // PWM module
#define SYSCTL_SET0_ADC         0x00010000  // ADC module
#define SYSCTL_SET0_ADCSPD_MASK 0x00000F00  // ADC speed mask
#define SYSCTL_SET0_ADCSPD_125K 0x00000000  // 125Ksps ADC
#define SYSCTL_SET0_ADCSPD_250K 0x00000100  // 250Ksps ADC
#define SYSCTL_SET0_ADCSPD_500K 0x00000200  // 500Ksps ADC
#define SYSCTL_SET0_ADCSPD_1M   0x00000300  // 1Msps ADC
#define SYSCTL_SET0_HIB         0x00000040  // Hibernation module
#define SYSCTL_SET0_WDOG        0x00000008  // Watchdog module

//*****************************************************************************
//
// The following are deprecated defines for the bit fields in the SYSCTL_SRCR1,
// SYSCTL_RCGC1, SYSCTL_SCGC1, and SYSCTL_DCGC1 registers.
//
//*****************************************************************************
#define SYSCTL_SET1_COMP2       0x04000000  // Analog comparator module 2
#define SYSCTL_SET1_COMP1       0x02000000  // Analog comparator module 1
#define SYSCTL_SET1_COMP0       0x01000000  // Analog comparator module 0
#define SYSCTL_SET1_TIMER3      0x00080000  // Timer module 3
#define SYSCTL_SET1_TIMER2      0x00040000  // Timer module 2
#define SYSCTL_SET1_TIMER1      0x00020000  // Timer module 1
#define SYSCTL_SET1_TIMER0      0x00010000  // Timer module 0
#define SYSCTL_SET1_I2C1        0x00002000  // I2C module 1
#define SYSCTL_SET1_I2C0        0x00001000  // I2C module 0
#define SYSCTL_SET1_I2C         0x00001000  // I2C module
#define SYSCTL_SET1_QEI1        0x00000200  // QEI module 1
#define SYSCTL_SET1_QEI         0x00000100  // QEI module
#define SYSCTL_SET1_QEI0        0x00000100  // QEI module 0
#define SYSCTL_SET1_SSI1        0x00000020  // SSI module 1
#define SYSCTL_SET1_SSI0        0x00000010  // SSI module 0
#define SYSCTL_SET1_SSI         0x00000010  // SSI module
#define SYSCTL_SET1_UART2       0x00000004  // UART module 2
#define SYSCTL_SET1_UART1       0x00000002  // UART module 1
#define SYSCTL_SET1_UART0       0x00000001  // UART module 0

//*****************************************************************************
//
// The following are deprecated defines for the bit fields in the SYSCTL_SRCR2,
// SYSCTL_RCGC2, SYSCTL_SCGC2, and SYSCTL_DCGC2 registers.
//
//*****************************************************************************
#define SYSCTL_SET2_ETH         0x50000000  // ETH module
#define SYSCTL_SET2_GPIOH       0x00000080  // GPIO H module
#define SYSCTL_SET2_GPIOG       0x00000040  // GPIO G module
#define SYSCTL_SET2_GPIOF       0x00000020  // GPIO F module
#define SYSCTL_SET2_GPIOE       0x00000010  // GPIO E module
#define SYSCTL_SET2_GPIOD       0x00000008  // GPIO D module
#define SYSCTL_SET2_GPIOC       0x00000004  // GPIO C module
#define SYSCTL_SET2_GPIOB       0x00000002  // GPIO B module
#define SYSCTL_SET2_GPIOA       0x00000001  // GIPO A module

//*****************************************************************************
//
// The following are deprecated defines for the bit fields in the SYSCTL_RIS,
// SYSCTL_IMC, and SYSCTL_IMS registers.
//
//*****************************************************************************
#define SYSCTL_INT_PLL_LOCK     0x00000040  // PLL lock interrupt
#define SYSCTL_INT_CUR_LIMIT    0x00000020  // Current limit interrupt
#define SYSCTL_INT_IOSC_FAIL    0x00000010  // Internal oscillator failure int
#define SYSCTL_INT_MOSC_FAIL    0x00000008  // Main oscillator failure int
#define SYSCTL_INT_POR          0x00000004  // Power on reset interrupt
#define SYSCTL_INT_BOR          0x00000002  // Brown out interrupt
#define SYSCTL_INT_PLL_FAIL     0x00000001  // PLL failure interrupt

#endif

#endif // __HW_SYSCTL_H__
