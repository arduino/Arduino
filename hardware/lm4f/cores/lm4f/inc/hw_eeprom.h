//*****************************************************************************
//
// hw_eeprom.h - Macros used when accessing the EEPROM controller.
//
// Copyright (c) 2011-2012 Texas Instruments Incorporated.  All rights reserved.
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

#ifndef __HW_EEPROM_H__
#define __HW_EEPROM_H__

//*****************************************************************************
//
// The following are defines for the EEPROM register offsets.
//
//*****************************************************************************
#define EEPROM_EESIZE           0x400AF000  // EEPROM Size Information
#define EEPROM_EEBLOCK          0x400AF004  // EEPROM Current Block
#define EEPROM_EEOFFSET         0x400AF008  // EEPROM Current Offset
#define EEPROM_EERDWR           0x400AF010  // EEPROM Read-Write
#define EEPROM_EERDWRINC        0x400AF014  // EEPROM Read-Write with Increment
#define EEPROM_EEDONE           0x400AF018  // EEPROM Done Status
#define EEPROM_EESUPP           0x400AF01C  // EEPROM Support Control and
                                            // Status
#define EEPROM_EEUNLOCK         0x400AF020  // EEPROM Unlock
#define EEPROM_EEPROT           0x400AF030  // EEPROM Protection
#define EEPROM_EEPASS0          0x400AF034  // EEPROM Password
#define EEPROM_EEPASS1          0x400AF038  // EEPROM Password
#define EEPROM_EEPASS2          0x400AF03C  // EEPROM Password
#define EEPROM_EEINT            0x400AF040  // EEPROM Interrupt
#define EEPROM_EEHIDE           0x400AF050  // EEPROM Block Hide
#define EEPROM_EEDBGME          0x400AF080  // EEPROM Debug Mass Erase
#define EEPROM_PP               0x400AFFC0  // EEPROM Peripheral Properties

//*****************************************************************************
//
// The following are defines for the bit fields in the EEPROM_EESIZE register.
//
//*****************************************************************************
#define EEPROM_EESIZE_WORDCNT_M 0x0000FFFF  // Number of 32-Bit Words
#define EEPROM_EESIZE_BLKCNT_M  0x07FF0000  // Number of 16-Word Blocks
#define EEPROM_EESIZE_WORDCNT_S 0
#define EEPROM_EESIZE_BLKCNT_S  16

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
#define EEPROM_EEOFFSET_OFFSET_M \
                                0x0000000F  // Current Address Offset
#define EEPROM_EEOFFSET_OFFSET_S \
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
#define EEPROM_EERDWRINC_VALUE_M \
                                0xFFFFFFFF  // EEPROM Read or Write Data with
                                            // Increment
#define EEPROM_EERDWRINC_VALUE_S \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the EEPROM_EEDONE register.
//
//*****************************************************************************
#define EEPROM_EEDONE_WORKING   0x00000001  // EEPROM Working
#define EEPROM_EEDONE_WKERASE   0x00000004  // Working on an Erase
#define EEPROM_EEDONE_WKCOPY    0x00000008  // Working on a Copy
#define EEPROM_EEDONE_NOPERM    0x00000010  // Write Without Permission
#define EEPROM_EEDONE_WRBUSY    0x00000020  // Write Busy
#define EEPROM_EEDONE_INVPL     0x00000100  // Invalid Program Voltage Level

//*****************************************************************************
//
// The following are defines for the bit fields in the EEPROM_EESUPP register.
//
//*****************************************************************************
#define EEPROM_EESUPP_START     0x00000001  // Start Erase
#define EEPROM_EESUPP_EREQ      0x00000002  // Erase Required
#define EEPROM_EESUPP_ERETRY    0x00000004  // Erase Must Be Retried
#define EEPROM_EESUPP_PRETRY    0x00000008  // Programming Must Be Retried

//*****************************************************************************
//
// The following are defines for the bit fields in the EEPROM_EEUNLOCK
// register.
//
//*****************************************************************************
#define EEPROM_EEUNLOCK_UNLOCK_M \
                                0xFFFFFFFF  // EEPROM Unlock

//*****************************************************************************
//
// The following are defines for the bit fields in the EEPROM_EEPROT register.
//
//*****************************************************************************
#define EEPROM_EEPROT_PROT_M    0x00000007  // Protection Control
#define EEPROM_EEPROT_PROT_RWNPW \
                                0x00000000  // This setting is the default. If
                                            // there is no password, the block
                                            // is not protected and is readable
                                            // and writable
#define EEPROM_EEPROT_PROT_RWPW 0x00000001  // If there is a password, the
                                            // block is readable or writable
                                            // only when unlocked
#define EEPROM_EEPROT_PROT_RONPW \
                                0x00000002  // If there is no password, the
                                            // block is readable, not writable
#define EEPROM_EEPROT_ACC       0x00000008  // Access Control

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
// The following are defines for the bit fields in the EEPROM_EEHIDE register.
//
//*****************************************************************************
#define EEPROM_EEHIDE_HN_M      0xFFFFFFFE  // Hide Block

//*****************************************************************************
//
// The following are defines for the bit fields in the EEPROM_EEDBGME register.
//
//*****************************************************************************
#define EEPROM_EEDBGME_ME       0x00000001  // Mass Erase
#define EEPROM_EEDBGME_KEY_M    0xFFFF0000  // Erase Key
#define EEPROM_EEDBGME_KEY_S    16

//*****************************************************************************
//
// The following are defines for the bit fields in the EEPROM_PP register.
//
//*****************************************************************************
#define EEPROM_PP_SIZE_M        0x0000001F  // EEPROM Size
#define EEPROM_PP_SIZE_S        0

//*****************************************************************************
//
// The following definitions are deprecated.
//
//*****************************************************************************
#ifndef DEPRECATED

//*****************************************************************************
//
// The following are deprecated defines for the EEPROM register offsets.
//
//*****************************************************************************
#define EEPROM_EEPROMPP         0x400AFFC0  // EEPROM

//*****************************************************************************
//
// The following are deprecated defines for the bit fields in the
// EEPROM_EEPROMPP register.
//
//*****************************************************************************
#define EEPROM_EEPROMPP_SIZE_M  0x0000001F  // EEPROM Size
#define EEPROM_EEPROMPP_SIZE_S  0

#endif

#endif // __HW_EEPROM_H__
