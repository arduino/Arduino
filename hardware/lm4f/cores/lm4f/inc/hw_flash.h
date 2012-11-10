//*****************************************************************************
//
// hw_flash.h - Macros used when accessing the flash controller.
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
#define FLASH_FCTL              0x400FD0F8  // Flash Control
#define FLASH_FWBN              0x400FD100  // Flash Write Buffer n
#define FLASH_FSIZE             0x400FDFC0  // Flash Size
#define FLASH_SSIZE             0x400FDFC4  // SRAM Size
#define FLASH_ROMSWMAP          0x400FDFCC  // ROM Software Map
#define FLASH_RMCTL             0x400FE0F0  // ROM Control
#define FLASH_FMPRE             0x400FE130  // Flash Memory Protection Read
                                            // Enable
#define FLASH_FMPPE             0x400FE134  // Flash Memory Protection Program
                                            // Enable
#define FLASH_USECRL            0x400FE140  // USec Reload
#define FLASH_USERDBG           0x400FE1D0  // User Debug
#define FLASH_BOOTCFG           0x400FE1D0  // Boot Configuration
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

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_FMA register.
//
//*****************************************************************************
#define FLASH_FMA_OFFSET_M      0x0007FFFF  // Address Offset
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
// The following are defines for the bit fields in the FLASH_FCTL register.
//
//*****************************************************************************
#define FLASH_FCTL_USDACK       0x00000002  // User Shut Down Acknowledge
#define FLASH_FCTL_USDREQ       0x00000001  // User Shut Down Request

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_FWBN register.
//
//*****************************************************************************
#define FLASH_FWBN_DATA_M       0xFFFFFFFF  // Data

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_FSIZE register.
//
//*****************************************************************************
#define FLASH_FSIZE_SIZE_M      0x0000FFFF  // Flash Size
#define FLASH_FSIZE_SIZE_8KB    0x00000003  // 8 KB of Flash
#define FLASH_FSIZE_SIZE_16KB   0x00000007  // 16 KB of Flash
#define FLASH_FSIZE_SIZE_32KB   0x0000000F  // 32 KB of Flash
#define FLASH_FSIZE_SIZE_64KB   0x0000001F  // 64 KB of Flash
#define FLASH_FSIZE_SIZE_96KB   0x0000002F  // 96 KB of Flash
#define FLASH_FSIZE_SIZE_128KB  0x0000003F  // 128 KB of Flash
#define FLASH_FSIZE_SIZE_192KB  0x0000005F  // 192 KB of Flash
#define FLASH_FSIZE_SIZE_256KB  0x0000007F  // 256 KB of Flash

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_SSIZE register.
//
//*****************************************************************************
#define FLASH_SSIZE_SIZE_M      0x0000FFFF  // SRAM Size
#define FLASH_SSIZE_SIZE_2KB    0x00000007  // 2 KB of SRAM
#define FLASH_SSIZE_SIZE_4KB    0x0000000F  // 4 KB of SRAM
#define FLASH_SSIZE_SIZE_6KB    0x00000017  // 6 KB of SRAM
#define FLASH_SSIZE_SIZE_8KB    0x0000001F  // 8 KB of SRAM
#define FLASH_SSIZE_SIZE_12KB   0x0000002F  // 12 KB of SRAM
#define FLASH_SSIZE_SIZE_16KB   0x0000003F  // 16 KB of SRAM
#define FLASH_SSIZE_SIZE_20KB   0x0000004F  // 20 KB of SRAM
#define FLASH_SSIZE_SIZE_24KB   0x0000005F  // 24 KB of SRAM
#define FLASH_SSIZE_SIZE_32KB   0x0000007F  // 32 KB of SRAM

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_ROMSWMAP register.
//
//*****************************************************************************
#define FLASH_ROMSWMAP_SAFERTOS 0x00000001  // SafeRTOS Present

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_RMCTL register.
//
//*****************************************************************************
#define FLASH_RMCTL_BA          0x00000001  // Boot Alias

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_USECRL register.
//
//*****************************************************************************
#define FLASH_USECRL_M          0x000000FF  // Microsecond Reload Value
#define FLASH_USECRL_S          0

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_USERDBG register.
//
//*****************************************************************************
#define FLASH_USERDBG_NW        0x80000000  // User Debug Not Written
#define FLASH_USERDBG_DATA_M    0x7FFFFFFC  // User Data
#define FLASH_USERDBG_DBG1      0x00000002  // Debug Control 1
#define FLASH_USERDBG_DBG0      0x00000001  // Debug Control 0
#define FLASH_USERDBG_DATA_S    2

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
#define FLASH_BOOTCFG_DBG1      0x00000002  // Debug Control 1
#define FLASH_BOOTCFG_DBG0      0x00000001  // Debug Control 0

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_USERREG0 register.
//
//*****************************************************************************
#define FLASH_USERREG0_DATA_M   0xFFFFFFFF  // User Data
#define FLASH_USERREG0_NW       0x80000000  // Not Written
#define FLASH_USERREG0_DATA_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_USERREG1 register.
//
//*****************************************************************************
#define FLASH_USERREG1_DATA_M   0xFFFFFFFF  // User Data
#define FLASH_USERREG1_NW       0x80000000  // Not Written
#define FLASH_USERREG1_DATA_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_USERREG2 register.
//
//*****************************************************************************
#define FLASH_USERREG2_DATA_M   0xFFFFFFFF  // User Data
#define FLASH_USERREG2_NW       0x80000000  // Not Written
#define FLASH_USERREG2_DATA_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_USERREG3 register.
//
//*****************************************************************************
#define FLASH_USERREG3_DATA_M   0xFFFFFFFF  // User Data
#define FLASH_USERREG3_NW       0x80000000  // Not Written
#define FLASH_USERREG3_DATA_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the FLASH_FMPRE and
// FLASH_FMPPE registers.
//
//*****************************************************************************
#define FLASH_FMP_BLOCK_31      0x80000000  // Enable for block 31
#define FLASH_FMP_BLOCK_30      0x40000000  // Enable for block 30
#define FLASH_FMP_BLOCK_29      0x20000000  // Enable for block 29
#define FLASH_FMP_BLOCK_28      0x10000000  // Enable for block 28
#define FLASH_FMP_BLOCK_27      0x08000000  // Enable for block 27
#define FLASH_FMP_BLOCK_26      0x04000000  // Enable for block 26
#define FLASH_FMP_BLOCK_25      0x02000000  // Enable for block 25
#define FLASH_FMP_BLOCK_24      0x01000000  // Enable for block 24
#define FLASH_FMP_BLOCK_23      0x00800000  // Enable for block 23
#define FLASH_FMP_BLOCK_22      0x00400000  // Enable for block 22
#define FLASH_FMP_BLOCK_21      0x00200000  // Enable for block 21
#define FLASH_FMP_BLOCK_20      0x00100000  // Enable for block 20
#define FLASH_FMP_BLOCK_19      0x00080000  // Enable for block 19
#define FLASH_FMP_BLOCK_18      0x00040000  // Enable for block 18
#define FLASH_FMP_BLOCK_17      0x00020000  // Enable for block 17
#define FLASH_FMP_BLOCK_16      0x00010000  // Enable for block 16
#define FLASH_FMP_BLOCK_15      0x00008000  // Enable for block 15
#define FLASH_FMP_BLOCK_14      0x00004000  // Enable for block 14
#define FLASH_FMP_BLOCK_13      0x00002000  // Enable for block 13
#define FLASH_FMP_BLOCK_12      0x00001000  // Enable for block 12
#define FLASH_FMP_BLOCK_11      0x00000800  // Enable for block 11
#define FLASH_FMP_BLOCK_10      0x00000400  // Enable for block 10
#define FLASH_FMP_BLOCK_9       0x00000200  // Enable for block 9
#define FLASH_FMP_BLOCK_8       0x00000100  // Enable for block 8
#define FLASH_FMP_BLOCK_7       0x00000080  // Enable for block 7
#define FLASH_FMP_BLOCK_6       0x00000040  // Enable for block 6
#define FLASH_FMP_BLOCK_5       0x00000020  // Enable for block 5
#define FLASH_FMP_BLOCK_4       0x00000010  // Enable for block 4
#define FLASH_FMP_BLOCK_3       0x00000008  // Enable for block 3
#define FLASH_FMP_BLOCK_2       0x00000004  // Enable for block 2
#define FLASH_FMP_BLOCK_1       0x00000002  // Enable for block 1
#define FLASH_FMP_BLOCK_0       0x00000001  // Enable for block 0

//*****************************************************************************
//
// The following are defines for the erase size of the FLASH block that is
// erased by an erase operation, and the protect size is the size of the FLASH
// block that is protected by each protection register.
//
//*****************************************************************************
#define FLASH_PROTECT_SIZE      0x00000800
#define FLASH_ERASE_SIZE        0x00000400

//*****************************************************************************
//
// The following definitions are deprecated.
//
//*****************************************************************************
#ifndef DEPRECATED

//*****************************************************************************
//
// The following are deprecated defines for the FLASH register offsets.
//
//*****************************************************************************
#define FLASH_RMVER             0x400FE0F4  // ROM Version Register

//*****************************************************************************
//
// The following are deprecated defines for the bit fields in the FLASH_FMC
// register.
//
//*****************************************************************************
#define FLASH_FMC_WRKEY_M       0xFFFF0000  // Flash Memory Write Key
#define FLASH_FMC_WRKEY_MASK    0xFFFF0000  // FLASH write key mask
#define FLASH_FMC_WRKEY_S       16

//*****************************************************************************
//
// The following are deprecated defines for the bit fields in the FLASH_FCRIS
// register.
//
//*****************************************************************************
#define FLASH_FCRIS_PROGRAM     0x00000002  // Programming status
#define FLASH_FCRIS_ACCESS      0x00000001  // Invalid access status

//*****************************************************************************
//
// The following are deprecated defines for the bit fields in the FLASH_FCIM
// register.
//
//*****************************************************************************
#define FLASH_FCIM_PROGRAM      0x00000002  // Programming mask
#define FLASH_FCIM_ACCESS       0x00000001  // Invalid access mask

//*****************************************************************************
//
// The following are deprecated defines for the bit fields in the FLASH_FCMISC
// register.
//
//*****************************************************************************
#define FLASH_FCMISC_PROGRAM    0x00000002  // Programming status
#define FLASH_FCMISC_ACCESS     0x00000001  // Invalid access status

//*****************************************************************************
//
// The following are deprecated defines for the bit fields in the FLASH_RMVER
// register.
//
//*****************************************************************************
#define FLASH_RMVER_CONT_M      0xFF000000  // ROM Contents
#define FLASH_RMVER_CONT_LM     0x00000000  // Stellaris Boot Loader &
                                            // DriverLib
#define FLASH_RMVER_CONT_LM_AES 0x02000000  // Stellaris Boot Loader &
                                            // DriverLib with AES
#define FLASH_RMVER_CONT_LM_AES_SAFERTOS \
                                0x03000000  // Stellaris Boot Loader &
                                            // DriverLib with AES and SAFERTOS
#define FLASH_RMVER_CONT_LM_AES2 \
                                0x05000000  // Stellaris Boot Loader &
                                            // DriverLib with AES
#define FLASH_RMVER_VER_M       0x0000FF00  // ROM Version
#define FLASH_RMVER_REV_M       0x000000FF  // ROM Revision
#define FLASH_RMVER_VER_S       8
#define FLASH_RMVER_REV_S       0

//*****************************************************************************
//
// The following are deprecated defines for the bit fields in the FLASH_USECRL
// register.
//
//*****************************************************************************
#define FLASH_USECRL_MASK       0x000000FF  // Clock per uSec
#define FLASH_USECRL_SHIFT      0

#endif

#endif // __HW_FLASH_H__
