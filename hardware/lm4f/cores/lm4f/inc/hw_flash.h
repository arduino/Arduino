//*****************************************************************************
//
// hw_flash.h - Macros used when accessing the flash controller.
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

#ifndef __HW_FLASH_H__
#define __HW_FLASH_H__

//*****************************************************************************
//
// The following are defines for the FLASH register offsets.
//
//*****************************************************************************
#define FLASH_FMA               0x400FD000  // Flash Memory Address
#define FLASH_FMD               0x400FD004  // Flash Memory Data
#define FLASH_FMC               0x400FD008  // Flash Memory Control
#define FLASH_FCRIS             0x400FD00C  // Flash Controller Raw Interrupt
                                            // Status
#define FLASH_FCIM              0x400FD010  // Flash Controller Interrupt Mask
#define FLASH_FCMISC            0x400FD014  // Flash Controller Masked
                                            // Interrupt Status and Clear
#define FLASH_FMC2              0x400FD020  // Flash Memory Control 2
#define FLASH_FWBVAL            0x400FD030  // Flash Write Buffer Valid
#define FLASH_FLPEKEY           0x400FD03C  // Flash Program/Erase Key
#define FLASH_FWBN              0x400FD100  // Flash Write Buffer n
#define FLASH_PP                0x400FDFC0  // Code SRAM Peripheral Properties
#define FLASH_FSIZE             0x400FDFC0  // Flash Size
#define FLASH_SSIZE             0x400FDFC4  // SRAM Size
#define FLASH_CONF              0x400FDFC8  // Flash Configuration Register
#define FLASH_ROMSWMAP          0x400FDFCC  // ROM Software Map
#define FLASH_DMASZ             0x400FDFD0  // Code SRAM DMA Address Size
#define FLASH_DMAST             0x400FDFD4  // Code SRAM DMA Starting Address
#define FLASH_RVP               0x400FE0D4  // Reset Vector Pointer
#define FLASH_RMCTL             0x400FE0F0  // ROM Control
#define FLASH_BOOTCFG           0x400FE1D0  // Boot Configuration
#define FLASH_USRPWRUP          0x400FE1DC  // USER Power-Up Control
#define FLASH_USERREG0          0x400FE1E0  // User Register 0
#define FLASH_USERREG1          0x400FE1E4  // User Register 1
#define FLASH_USERREG2          0x400FE1E8  // User Register 2
#define FLASH_USERREG3          0x400FE1EC  // User Register 3
#define FLASH_FMPRE0            0x400FE200  // Flash Memory Protection Read
                                            // Enable 0
#define FLASH_FMPRE1            0x400FE204  // Flash Memory Protection Read
                                            // Enable 1
#define FLASH_FMPRE2            0x400FE208  // Flash Memory Protection Read
                                            // Enable 2
#define FLASH_FMPRE3            0x400FE20C  // Flash Memory Protection Read
                                            // Enable 3
#define FLASH_FMPRE4            0x400FE210  // Flash Memory Protection Read
                                            // Enable 4
#define FLASH_FMPRE5            0x400FE214  // Flash Memory Protection Read
                                            // Enable 5
#define FLASH_FMPRE6            0x400FE218  // Flash Memory Protection Read
                                            // Enable 6
#define FLASH_FMPRE7            0x400FE21C  // Flash Memory Protection Read
                                            // Enable 7
#define FLASH_FMPRE8            0x400FE220  // Flash Memory Protection Read
                                            // Enable 8
#define FLASH_FMPRE9            0x400FE224  // Flash Memory Protection Read
                                            // Enable 9
#define FLASH_FMPRE10           0x400FE228  // Flash Memory Protection Read
                                            // Enable 10
#define FLASH_FMPRE11           0x400FE22C  // Flash Memory Protection Read
                                            // Enable 11
#define FLASH_FMPRE12           0x400FE230  // Flash Memory Protection Read
                                            // Enable 12
#define FLASH_FMPRE13           0x400FE234  // Flash Memory Protection Read
                                            // Enable 13
#define FLASH_FMPRE14           0x400FE238  // Flash Memory Protection Read
                                            // Enable 14
#define FLASH_FMPRE15           0x400FE23C  // Flash Memory Protection Read
                                            // Enable 15
#define FLASH_FMPPE0            0x400FE400  // Flash Memory Protection Program
                                            // Enable 0
#define FLASH_FMPPE1            0x400FE404  // Flash Memory Protection Program
                                            // Enable 1
#define FLASH_FMPPE2            0x400FE408  // Flash Memory Protection Program
                                            // Enable 2
#define FLASH_FMPPE3            0x400FE40C  // Flash Memory Protection Program
                                            // Enable 3
#define FLASH_FMPPE4            0x400FE410  // Flash Memory Protection Program
                                            // Enable 4
#define FLASH_FMPPE5            0x400FE414  // Flash Memory Protection Program
                                            // Enable 5
#define FLASH_FMPPE6            0x400FE418  // Flash Memory Protection Program
                                            // Enable 6
#define FLASH_FMPPE7            0x400FE41C  // Flash Memory Protection Program
                                            // Enable 7
#define FLASH_FMPPE8            0x400FE420  // Flash Memory Protection Program
                                            // Enable 8
#define FLASH_FMPPE9            0x400FE424  // Flash Memory Protection Program
                                            // Enable 9
#define FLASH_FMPPE10           0x400FE428  // Flash Memory Protection Program
                                            // Enable 10
#define FLASH_FMPPE11           0x400FE42C  // Flash Memory Protection Program
                                            // Enable 11
#define FLASH_FMPPE12           0x400FE430  // Flash Memory Protection Program
                                            // Enable 12
#define FLASH_FMPPE13           0x400FE434  // Flash Memory Protection Program
                                            // Enable 13
#define FLASH_FMPPE14           0x400FE438  // Flash Memory Protection Program
                                            // Enable 14
#define FLASH_FMPPE15           0x400FE43C  // Flash Memory Protection Program
                                            // Enable 15

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
#define FLASH_FMC2_WRKEY        0xA4420000  // FLASH write key
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
// The following are defines for the bit fields in the FLASH_FSIZE register.
//
//*****************************************************************************
#define FLASH_FSIZE_SIZE_M      0x0000FFFF  // Flash Size
#define FLASH_FSIZE_SIZE_32KB   0x0000000F  // 32 KB of Flash
#define FLASH_FSIZE_SIZE_64KB   0x0000001F  // 64 KB of Flash
#define FLASH_FSIZE_SIZE_128KB  0x0000003F  // 128 KB of Flash
#define FLASH_FSIZE_SIZE_256KB  0x0000007F  // 256 KB of Flash

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_SSIZE register.
//
//*****************************************************************************
#define FLASH_SSIZE_SIZE_M      0x0000FFFF  // SRAM Size
#define FLASH_SSIZE_SIZE_12KB   0x0000002F  // 12 KB of SRAM
#define FLASH_SSIZE_SIZE_24KB   0x0000005F  // 24 KB of SRAM
#define FLASH_SSIZE_SIZE_32KB   0x0000007F  // 32 KB of SRAM
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
#define FLASH_ROMSWMAP_SAFERTOS 0x00000001  // SafeRTOS Present
#define FLASH_ROMSWMAP_SW0EN_M  0x00000003  // ROM SW Region 0 Availability
#define FLASH_ROMSWMAP_SW0EN_NOTVIS                                           \
                                0x00000000  // Not Visible outside of secure
                                            // INITIALIZATION
#define FLASH_ROMSWMAP_SW0EN_CORE                                             \
                                0x00000001  // Visible to core
#define FLASH_ROMSWMAP_SW1EN_M  0x0000000C  // ROM SW Region 1 Availability
#define FLASH_ROMSWMAP_SW1EN_NOTVIS                                           \
                                0x00000000  // Not Visible outside of secure
                                            // INITIALIZATION
#define FLASH_ROMSWMAP_SW1EN_CORE                                             \
                                0x00000004  // Visible to core
#define FLASH_ROMSWMAP_SW2EN_M  0x00000030  // ROM SW Region 2 Availability
#define FLASH_ROMSWMAP_SW2EN_NOTVIS                                           \
                                0x00000000  // Not Visible outside of secure
                                            // INITIALIZATION
#define FLASH_ROMSWMAP_SW2EN_CORE                                             \
                                0x00000010  // Visible to core
#define FLASH_ROMSWMAP_SW3EN_M  0x000000C0  // ROM SW Region 3 Availability
#define FLASH_ROMSWMAP_SW3EN_NOTVIS                                           \
                                0x00000000  // Not Visible outside of secure
                                            // INITIALIZATION
#define FLASH_ROMSWMAP_SW3EN_CORE                                             \
                                0x00000040  // Visible to core
#define FLASH_ROMSWMAP_SW4EN_M  0x00000300  // ROM SW Region 4 Availability
#define FLASH_ROMSWMAP_SW4EN_NOTVIS                                           \
                                0x00000000  // Not Visible outside of secure
                                            // INITIALIZATION
#define FLASH_ROMSWMAP_SW4EN_CORE                                             \
                                0x00000100  // Visible to core
#define FLASH_ROMSWMAP_SW5EN_M  0x00000C00  // ROM SW Region 5 Availability
#define FLASH_ROMSWMAP_SW5EN_NOTVIS                                           \
                                0x00000000  // Not Visible outside of secure
                                            // INITIALIZATION
#define FLASH_ROMSWMAP_SW5EN_CORE                                             \
                                0x00000400  // Visible to core
#define FLASH_ROMSWMAP_SW6EN_M  0x00003000  // ROM SW Region 6 Availability
#define FLASH_ROMSWMAP_SW6EN_NOTVIS                                           \
                                0x00000000  // Not Visible outside of secure
                                            // INITIALIZATION
#define FLASH_ROMSWMAP_SW6EN_CORE                                             \
                                0x00001000  // Visible to core
#define FLASH_ROMSWMAP_SW7EN_M  0x0000C000  // ROM SW Region 7 Availability
#define FLASH_ROMSWMAP_SW7EN_NOTVIS                                           \
                                0x00000000  // Not Visible outside of secure
                                            // INITIALIZATION
#define FLASH_ROMSWMAP_SW7EN_CORE                                             \
                                0x00004000  // Visible to core

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
// The following are defines for the bit fields in the FLASH_RMCTL register.
//
//*****************************************************************************
#define FLASH_RMCTL_BA          0x00000001  // Boot Alias

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
// The following are defines for the erase size of the FLASH block that is
// erased by an erase operation, and the protect size is the size of the FLASH
// block that is protected by each protection register.
//
//*****************************************************************************
#define FLASH_PROTECT_SIZE      0x00000800
#define FLASH_ERASE_SIZE        0x00000400

#endif // __HW_FLASH_H__
