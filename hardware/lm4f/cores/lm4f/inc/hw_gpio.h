//*****************************************************************************
//
// hw_gpio.h - Defines and Macros for GPIO hardware.
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

#ifndef __HW_GPIO_H__
#define __HW_GPIO_H__

//*****************************************************************************
//
// The following are defines for the GPIO register offsets.
//
//*****************************************************************************
#define GPIO_O_DATA             0x00000000  // GPIO Data
#define GPIO_O_DIR              0x00000400  // GPIO Direction
#define GPIO_O_IS               0x00000404  // GPIO Interrupt Sense
#define GPIO_O_IBE              0x00000408  // GPIO Interrupt Both Edges
#define GPIO_O_IEV              0x0000040C  // GPIO Interrupt Event
#define GPIO_O_IM               0x00000410  // GPIO Interrupt Mask
#define GPIO_O_RIS              0x00000414  // GPIO Raw Interrupt Status
#define GPIO_O_MIS              0x00000418  // GPIO Masked Interrupt Status
#define GPIO_O_ICR              0x0000041C  // GPIO Interrupt Clear
#define GPIO_O_AFSEL            0x00000420  // GPIO Alternate Function Select
#define GPIO_O_DR2R             0x00000500  // GPIO 2-mA Drive Select
#define GPIO_O_DR4R             0x00000504  // GPIO 4-mA Drive Select
#define GPIO_O_DR8R             0x00000508  // GPIO 8-mA Drive Select
#define GPIO_O_ODR              0x0000050C  // GPIO Open Drain Select
#define GPIO_O_PUR              0x00000510  // GPIO Pull-Up Select
#define GPIO_O_PDR              0x00000514  // GPIO Pull-Down Select
#define GPIO_O_SLR              0x00000518  // GPIO Slew Rate Control Select
#define GPIO_O_DEN              0x0000051C  // GPIO Digital Enable
#define GPIO_O_LOCK             0x00000520  // GPIO Lock
#define GPIO_O_CR               0x00000524  // GPIO Commit
#define GPIO_O_AMSEL            0x00000528  // GPIO Analog Mode Select
#define GPIO_O_PCTL             0x0000052C  // GPIO Port Control
#define GPIO_O_ADCCTL           0x00000530  // GPIO ADC Control
#define GPIO_O_DMACTL           0x00000534  // GPIO DMA Control
#define GPIO_O_SI               0x00000538  // GPIO Select Interrupt

//*****************************************************************************
//
// The following are defines for the bit fields in the GPIO_O_IM register.
//
//*****************************************************************************
#define GPIO_IM_GPIO_M          0x000000FF  // GPIO Interrupt Mask Enable
#define GPIO_IM_GPIO_S          0

//*****************************************************************************
//
// The following are defines for the bit fields in the GPIO_O_RIS register.
//
//*****************************************************************************
#define GPIO_RIS_GPIO_M         0x000000FF  // GPIO Interrupt Raw Status
#define GPIO_RIS_GPIO_S         0

//*****************************************************************************
//
// The following are defines for the bit fields in the GPIO_O_MIS register.
//
//*****************************************************************************
#define GPIO_MIS_GPIO_M         0x000000FF  // GPIO Masked Interrupt Status
#define GPIO_MIS_GPIO_S         0

//*****************************************************************************
//
// The following are defines for the bit fields in the GPIO_O_ICR register.
//
//*****************************************************************************
#define GPIO_ICR_GPIO_M         0x000000FF  // GPIO Interrupt Clear
#define GPIO_ICR_GPIO_S         0

//*****************************************************************************
//
// The following are defines for the bit fields in the GPIO_O_LOCK register.
//
//*****************************************************************************
#define GPIO_LOCK_M             0xFFFFFFFF  // GPIO Lock
#define GPIO_LOCK_UNLOCKED      0x00000000  // The GPIOCR register is unlocked
                                            // and may be modified
#define GPIO_LOCK_LOCKED        0x00000001  // The GPIOCR register is locked
                                            // and may not be modified
#define GPIO_LOCK_KEY           0x1ACCE551  // Unlocks the GPIO_CR register
#define GPIO_LOCK_KEY_DD        0x4C4F434B  // Unlocks the GPIO_CR register on
                                            // DustDevil-class devices and
                                            // later

//*****************************************************************************
//
// The following are defines for the bit fields in the GPIO_O_SI register.
//
//*****************************************************************************
#define GPIO_SI_SUM             0x00000001  // Summary Interrupt

//*****************************************************************************
//
// The following definitions are deprecated.
//
//*****************************************************************************
#ifndef DEPRECATED

//*****************************************************************************
//
// The following are deprecated defines for the GPIO register offsets.
//
//*****************************************************************************
#define GPIO_O_PeriphID4        0x00000FD0
#define GPIO_O_PeriphID5        0x00000FD4
#define GPIO_O_PeriphID6        0x00000FD8
#define GPIO_O_PeriphID7        0x00000FDC
#define GPIO_O_PeriphID0        0x00000FE0
#define GPIO_O_PeriphID1        0x00000FE4
#define GPIO_O_PeriphID2        0x00000FE8
#define GPIO_O_PeriphID3        0x00000FEC
#define GPIO_O_PCellID0         0x00000FF0
#define GPIO_O_PCellID1         0x00000FF4
#define GPIO_O_PCellID2         0x00000FF8
#define GPIO_O_PCellID3         0x00000FFC

//*****************************************************************************
//
// The following are deprecated defines for the GPIO Register reset values.
//
//*****************************************************************************
#define GPIO_RV_DEN             0x000000FF  // Digital input enable reg RV
#define GPIO_RV_PUR             0x000000FF  // Pull up select reg RV
#define GPIO_RV_DR2R            0x000000FF  // 2ma drive select reg RV
#define GPIO_RV_PCellID1        0x000000F0
#define GPIO_RV_PCellID3        0x000000B1
#define GPIO_RV_PeriphID0       0x00000061
#define GPIO_RV_PeriphID1       0x00000010
#define GPIO_RV_PCellID0        0x0000000D
#define GPIO_RV_PCellID2        0x00000005
#define GPIO_RV_PeriphID2       0x00000004
#define GPIO_RV_LOCK            0x00000001  // Lock register RV
#define GPIO_RV_PeriphID7       0x00000000
#define GPIO_RV_PDR             0x00000000  // Pull down select reg RV
#define GPIO_RV_IC              0x00000000  // Interrupt clear reg RV
#define GPIO_RV_SLR             0x00000000  // Slew rate control enable reg RV
#define GPIO_RV_ODR             0x00000000  // Open drain select reg RV
#define GPIO_RV_IBE             0x00000000  // Interrupt both edges reg RV
#define GPIO_RV_AFSEL           0x00000000  // Mode control select reg RV
#define GPIO_RV_IS              0x00000000  // Interrupt sense reg RV
#define GPIO_RV_IM              0x00000000  // Interrupt mask reg RV
#define GPIO_RV_PeriphID4       0x00000000
#define GPIO_RV_PeriphID5       0x00000000
#define GPIO_RV_DR8R            0x00000000  // 8ma drive select reg RV
#define GPIO_RV_RIS             0x00000000  // Raw interrupt status reg RV
#define GPIO_RV_DR4R            0x00000000  // 4ma drive select reg RV
#define GPIO_RV_IEV             0x00000000  // Intterupt event reg RV
#define GPIO_RV_DIR             0x00000000  // Data direction reg RV
#define GPIO_RV_PeriphID6       0x00000000
#define GPIO_RV_PeriphID3       0x00000000
#define GPIO_RV_DATA            0x00000000  // Data register reset value
#define GPIO_RV_MIS             0x00000000  // Masked interrupt status reg RV

#endif

#endif // __HW_GPIO_H__
