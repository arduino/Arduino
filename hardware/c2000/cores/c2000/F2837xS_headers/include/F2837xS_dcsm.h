//###########################################################################
//
// FILE:    F2837xS_dcsm.h
//
// TITLE:   F2837xS Device DCSM Register Definitions.
//
//###########################################################################
// $TI Release: F2837xS Support Library v170 $
// $Release Date: Mon Sep 21 16:56:07 CDT 2015 $
// $Copyright: Copyright (C) 2014-2015 Texas Instruments Incorporated -
//             http://www.ti.com/ ALL RIGHTS RESERVED $
//###########################################################################

#ifndef __F2837xS_DCSM_H__
#define __F2837xS_DCSM_H__

#ifdef __cplusplus 
extern "C" {
#endif 


//---------------------------------------------------------------------------
// DCSM Individual Register Bit Definitions:

struct DCSM_Z1_OTP {
    Uint32                                   Z1OTP_LINKPOINTER1;           // Zone 1 Link Pointer1 in Z1 OTP
    Uint16                                   rsvd1[2];                     // Reserved
    Uint32                                   Z1OTP_LINKPOINTER2;           // Zone 1 Link Pointer2 in Z1 OTP
    Uint16                                   rsvd2[2];                     // Reserved
    Uint32                                   Z1OTP_LINKPOINTER3;           // Zone 1 Link Pointer3 in Z1 OTP
    Uint16                                   rsvd3[6];                     // Reserved
    Uint32                                   Z1OTP_PSWDLOCK;               // Secure Password Lock in Z1 OTP
    Uint16                                   rsvd4[2];                     // Reserved
    Uint32                                   Z1OTP_CRCLOCK;                // Secure CRC Lock in Z1 OTP
    Uint16                                   rsvd5[8];                     // Reserved
    Uint32                                   Z1OTP_BOOTCTRL;               // Boot Mode in Z1 OTP
};

struct DCSM_Z2_OTP {
    Uint32                                   Z2OTP_LINKPOINTER1;           // Zone 2 Link Pointer1 in Z2 OTP
    Uint16                                   rsvd1[2];                     // Reserved
    Uint32                                   Z2OTP_LINKPOINTER2;           // Zone 2 Link Pointer2 in Z2 OTP
    Uint16                                   rsvd2[2];                     // Reserved
    Uint32                                   Z2OTP_LINKPOINTER3;           // Zone 2 Link Pointer3 in Z2 OTP
    Uint16                                   rsvd3[6];                     // Reserved
    Uint32                                   Z2OTP_PSWDLOCK;               // Secure Password Lock in Z2 OTP
    Uint16                                   rsvd4[2];                     // Reserved
    Uint32                                   Z2OTP_CRCLOCK;                // Secure CRC Lock in Z2 OTP
    Uint16                                   rsvd5[8];                     // Reserved
    Uint32                                   Z2OTP_BOOTCTRL;               // Boot Mode in Z2 OTP
};

struct Z1_LINKPOINTER_BITS {            // bits description
    Uint32 LINKPOINTER:29;              // 28:0 Zone1 LINK Pointer.
    Uint16 rsvd1:3;                     // 31:29 Reserved
};

union Z1_LINKPOINTER_REG {
    Uint32  all;
    struct  Z1_LINKPOINTER_BITS  bit;
};

struct Z1_OTPSECLOCK_BITS {             // bits description
    Uint16 rsvd1:4;                     // 3:0 Reserved
    Uint16 PSWDLOCK:4;                  // 7:4 Zone1 Password Lock.
    Uint16 CRCLOCK:4;                   // 11:8 Zone1 CRC Lock.
    Uint16 rsvd2:4;                     // 15:12 Reserved
    Uint16 rsvd3:16;                    // 31:16 Reserved
};

union Z1_OTPSECLOCK_REG {
    Uint32  all;
    struct  Z1_OTPSECLOCK_BITS  bit;
};

struct Z1_BOOTCTRL_BITS {               // bits description
    Uint16 KEY:8;                       // 7:0 OTP Boot Key
    Uint16 BMODE:8;                     // 15:8 OTP Boot Mode
    Uint16 BOOTPIN0:8;                  // 23:16 OTP Boot Pin 0 Mapping
    Uint16 BOOTPIN1:8;                  // 31:24 OTP Boot Pin 1 Mapping
};

union Z1_BOOTCTRL_REG {
    Uint32  all;
    struct  Z1_BOOTCTRL_BITS  bit;
};

struct Z1_CR_BITS {                     // bits description
    Uint16 rsvd1:3;                     // 2:0 Reserved
    Uint16 ALLZERO:1;                   // 3 CSMPSWD All Zeros
    Uint16 ALLONE:1;                    // 4 CSMPSWD All Ones
    Uint16 UNSECURE:1;                  // 5 CSMPSWD Match CSMKEY
    Uint16 ARMED:1;                     // 6 CSM Armed
    Uint16 rsvd2:1;                     // 7 Reserved
    Uint16 rsvd3:7;                     // 14:8 Reserved
    Uint16 FORCESEC:1;                  // 15 Force Secure
};

union Z1_CR_REG {
    Uint16  all;
    struct  Z1_CR_BITS  bit;
};

struct Z1_GRABSECTR_BITS {              // bits description
    Uint16 GRAB_SECTA:2;                // 1:0 Grab Flash Sector A
    Uint16 GRAB_SECTB:2;                // 3:2 Grab Flash Sector B
    Uint16 GRAB_SECTC:2;                // 5:4 Grab Flash Sector C
    Uint16 GRAB_SECTD:2;                // 7:6 Grab Flash Sector D
    Uint16 GRAB_SECTE:2;                // 9:8 Grab Flash Sector E
    Uint16 GRAB_SECTF:2;                // 11:10 Grab Flash Sector F
    Uint16 GRAB_SECTG:2;                // 13:12 Grab Flash Sector G
    Uint16 GRAB_SECTH:2;                // 15:14 Grab Flash Sector H
    Uint16 GRAB_SECTI:2;                // 17:16 Grab Flash Sector I
    Uint16 GRAB_SECTJ:2;                // 19:18 Grab Flash Sector J
    Uint16 GRAB_SECTK:2;                // 21:20 Grab Flash Sector K
    Uint16 GRAB_SECTL:2;                // 23:22 Grab Flash Sector L
    Uint16 GRAB_SECTM:2;                // 25:24 Grab Flash Sector M
    Uint16 GRAB_SECTN:2;                // 27:26 Grab Flash Sector N
    Uint16 GRAB_BANK1:2;                // 29:28 Grab BANK1 (all sectors of bank 1)
    Uint16 rsvd1:2;                     // 31:30 Reserved
};

union Z1_GRABSECTR_REG {
    Uint32  all;
    struct  Z1_GRABSECTR_BITS  bit;
};

struct Z1_GRABRAMR_BITS {               // bits description
    Uint16 GRAB_RAM0:2;                 // 1:0 Grab RAM LS0
    Uint16 GRAB_RAM1:2;                 // 3:2 Grab RAM LS1
    Uint16 GRAB_RAM2:2;                 // 5:4 Grab RAM LS2
    Uint16 GRAB_RAM3:2;                 // 7:6 Grab RAM LS3
    Uint16 GRAB_RAM4:2;                 // 9:8 Grab RAM LS4
    Uint16 GRAB_RAM5:2;                 // 11:10 Grab RAM LS5
    Uint16 GRAB_RAM6:2;                 // 13:12 Grab RAM D0
    Uint16 GRAB_RAM7:2;                 // 15:14 Grab RAM D1
    Uint16 rsvd1:12;                    // 27:16 Reserved
    Uint16 GRAB_CLA1:2;                 // 29:28 Grab CLA1
    Uint16 rsvd2:2;                     // 31:30 Reserved
};

union Z1_GRABRAMR_REG {
    Uint32  all;
    struct  Z1_GRABRAMR_BITS  bit;
};

struct Z1_EXEONLYSECTR_BITS {           // bits description
    Uint16 EXEONLY_SECTA:1;             // 0 Execute-Only Flash Sector A
    Uint16 EXEONLY_SECTB:1;             // 1 Execute-Only Flash Sector B
    Uint16 EXEONLY_SECTC:1;             // 2 Execute-Only Flash Sector C
    Uint16 EXEONLY_SECTD:1;             // 3 Execute-Only Flash Sector D 
    Uint16 EXEONLY_SECTE:1;             // 4 Execute-Only Flash Sector E
    Uint16 EXEONLY_SECTF:1;             // 5 Execute-Only Flash Sector F 
    Uint16 EXEONLY_SECTG:1;             // 6 Execute-Only Flash Sector G 
    Uint16 EXEONLY_SECTH:1;             // 7 Execute-Only Flash Sector H
    Uint16 EXEONLY_SECTI:1;             // 8 Execute-Only Flash Sector I
    Uint16 EXEONLY_SECTJ:1;             // 9 Execute-Only Flash Sector J
    Uint16 EXEONLY_SECTK:1;             // 10 Execute-Only Flash Sector K
    Uint16 EXEONLY_SECTL:1;             // 11 Execute-Only Flash Sector L
    Uint16 EXEONLY_SECTM:1;             // 12 Execute-Only Flash Sector M
    Uint16 EXEONLY_SECTN:1;             // 13 Execute-Only Flash Sector N
    Uint16 EXEONLY_BANK1:1;             // 14 Execute-Only Flash BANK1
    Uint16 rsvd1:1;                     // 15 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union Z1_EXEONLYSECTR_REG {
    Uint32  all;
    struct  Z1_EXEONLYSECTR_BITS  bit;
};

struct Z1_EXEONLYRAMR_BITS {            // bits description
    Uint16 EXEONLY_RAM0:1;              // 0 Execute-Only RAM LS0
    Uint16 EXEONLY_RAM1:1;              // 1 Execute-Only RAM LS1
    Uint16 EXEONLY_RAM2:1;              // 2 Execute-Only RAM LS2
    Uint16 EXEONLY_RAM3:1;              // 3 Execute-Only RAM LS3
    Uint16 EXEONLY_RAM4:1;              // 4 Execute-Only RAM LS4
    Uint16 EXEONLY_RAM5:1;              // 5 Execute-Only RAM LS5
    Uint16 EXEONLY_RAM6:1;              // 6 Execute-Only RAM D0
    Uint16 EXEONLY_RAM7:1;              // 7 Execute-Only RAM D1
    Uint16 rsvd1:8;                     // 15:8 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union Z1_EXEONLYRAMR_REG {
    Uint32  all;
    struct  Z1_EXEONLYRAMR_BITS  bit;
};

struct DCSM_Z1_REGS {
    union   Z1_LINKPOINTER_REG               Z1_LINKPOINTER;               // Zone 1 Link Pointer
    union   Z1_OTPSECLOCK_REG                Z1_OTPSECLOCK;                // Zone 1 OTP Secure JTAG lock
    union   Z1_BOOTCTRL_REG                  Z1_BOOTCTRL;                  // Boot Mode
    Uint32                                   Z1_LINKPOINTERERR;            // Link Pointer Error
    Uint16                                   rsvd1[8];                     // Reserved
    Uint32                                   Z1_CSMKEY0;                   // Zone 1 CSM Key 0
    Uint32                                   Z1_CSMKEY1;                   // Zone 1 CSM Key 1
    Uint32                                   Z1_CSMKEY2;                   // Zone 1 CSM Key 2
    Uint32                                   Z1_CSMKEY3;                   // Zone 1 CSM Key 3
    Uint16                                   rsvd2;                        // Reserved
    union   Z1_CR_REG                        Z1_CR;                        // Zone 1 CSM Control Register
    union   Z1_GRABSECTR_REG                 Z1_GRABSECTR;                 // Zone 1 Grab Flash Sectors Register
    union   Z1_GRABRAMR_REG                  Z1_GRABRAMR;                  // Zone 1 Grab RAM Blocks Register
    union   Z1_EXEONLYSECTR_REG              Z1_EXEONLYSECTR;              // Zone 1 Flash Execute_Only Sector Register
    union   Z1_EXEONLYRAMR_REG               Z1_EXEONLYRAMR;               // Zone 1 RAM Execute_Only Block Register
    Uint16                                   rsvd3;                        // Reserved
};

struct Z2_LINKPOINTER_BITS {            // bits description
    Uint32 LINKPOINTER:29;              // 28:0 Zone2 LINK Pointer.
    Uint16 rsvd1:3;                     // 31:29 Reserved
};

union Z2_LINKPOINTER_REG {
    Uint32  all;
    struct  Z2_LINKPOINTER_BITS  bit;
};

struct Z2_OTPSECLOCK_BITS {             // bits description
    Uint16 rsvd1:4;                     // 3:0 Reserved
    Uint16 PSWDLOCK:4;                  // 7:4 Zone2 Password Lock.
    Uint16 CRCLOCK:4;                   // 11:8 Zone2 CRC Lock.
    Uint16 rsvd2:4;                     // 15:12 Reserved
    Uint16 rsvd3:16;                    // 31:16 Reserved
};

union Z2_OTPSECLOCK_REG {
    Uint32  all;
    struct  Z2_OTPSECLOCK_BITS  bit;
};

struct Z2_BOOTCTRL_BITS {               // bits description
    Uint16 KEY:8;                       // 7:0 OTP Boot Key
    Uint16 BMODE:8;                     // 15:8 OTP Boot Mode
    Uint16 BOOTPIN0:8;                  // 23:16 OTP Boot Pin 0 Mapping
    Uint16 BOOTPIN1:8;                  // 31:24 OTP Boot Pin 1 Mapping
};

union Z2_BOOTCTRL_REG {
    Uint32  all;
    struct  Z2_BOOTCTRL_BITS  bit;
};

struct Z2_CR_BITS {                     // bits description
    Uint16 rsvd1:3;                     // 2:0 Reserved
    Uint16 ALLZERO:1;                   // 3 CSMPSWD All Zeros
    Uint16 ALLONE:1;                    // 4 CSMPSWD All Ones
    Uint16 UNSECURE:1;                  // 5 CSMPSWD Match CSMKEY
    Uint16 ARMED:1;                     // 6 CSM Armed
    Uint16 rsvd2:1;                     // 7 Reserved
    Uint16 rsvd3:7;                     // 14:8 Reserved
    Uint16 FORCESEC:1;                  // 15 Force Secure
};

union Z2_CR_REG {
    Uint16  all;
    struct  Z2_CR_BITS  bit;
};

struct Z2_GRABSECTR_BITS {              // bits description
    Uint16 GRAB_SECTA:2;                // 1:0 Grab Flash Sector A
    Uint16 GRAB_SECTB:2;                // 3:2 Grab Flash Sector B
    Uint16 GRAB_SECTC:2;                // 5:4 Grab Flash Sector C
    Uint16 GRAB_SECTD:2;                // 7:6 Grab Flash Sector D
    Uint16 GRAB_SECTE:2;                // 9:8 Grab Flash Sector E
    Uint16 GRAB_SECTF:2;                // 11:10 Grab Flash Sector F
    Uint16 GRAB_SECTG:2;                // 13:12 Grab Flash Sector G
    Uint16 GRAB_SECTH:2;                // 15:14 Grab Flash Sector H
    Uint16 GRAB_SECTI:2;                // 17:16 Grab Flash Sector I
    Uint16 GRAB_SECTJ:2;                // 19:18 Grab Flash Sector J
    Uint16 GRAB_SECTK:2;                // 21:20 Grab Flash Sector K
    Uint16 GRAB_SECTL:2;                // 23:22 Grab Flash Sector L
    Uint16 GRAB_SECTM:2;                // 25:24 Grab Flash Sector M
    Uint16 GRAB_SECTN:2;                // 27:26 Grab Flash Sector N
    Uint16 GRAB_BANK1:2;                // 29:28 Grab BANK1 (all sectors of bank 1)
    Uint16 rsvd1:2;                     // 31:30 Reserved
};

union Z2_GRABSECTR_REG {
    Uint32  all;
    struct  Z2_GRABSECTR_BITS  bit;
};

struct Z2_GRABRAMR_BITS {               // bits description
    Uint16 GRAB_RAM0:2;                 // 1:0 Grab RAM LS0
    Uint16 GRAB_RAM1:2;                 // 3:2 Grab RAM LS1
    Uint16 GRAB_RAM2:2;                 // 5:4 Grab RAM LS2
    Uint16 GRAB_RAM3:2;                 // 7:6 Grab RAM LS3
    Uint16 GRAB_RAM4:2;                 // 9:8 Grab RAM LS4
    Uint16 GRAB_RAM5:2;                 // 11:10 Grab RAM LS5
    Uint16 GRAB_RAM6:2;                 // 13:12 Grab RAM D0
    Uint16 GRAB_RAM7:2;                 // 15:14 Grab RAM D1
    Uint16 rsvd1:12;                    // 27:16 Reserved
    Uint16 GRAB_CLA1:2;                 // 29:28 Grab CLA1
    Uint16 rsvd2:2;                     // 31:30 Reserved
};

union Z2_GRABRAMR_REG {
    Uint32  all;
    struct  Z2_GRABRAMR_BITS  bit;
};

struct Z2_EXEONLYSECTR_BITS {           // bits description
    Uint16 EXEONLY_SECTA:1;             // 0 Execute-Only Flash Sector A
    Uint16 EXEONLY_SECTB:1;             // 1 Execute-Only Flash Sector B
    Uint16 EXEONLY_SECTC:1;             // 2 Execute-Only Flash Sector C
    Uint16 EXEONLY_SECTD:1;             // 3 Execute-Only Flash Sector D 
    Uint16 EXEONLY_SECTE:1;             // 4 Execute-Only Flash Sector E
    Uint16 EXEONLY_SECTF:1;             // 5 Execute-Only Flash Sector F 
    Uint16 EXEONLY_SECTG:1;             // 6 Execute-Only Flash Sector G 
    Uint16 EXEONLY_SECTH:1;             // 7 Execute-Only Flash Sector H
    Uint16 EXEONLY_SECTI:1;             // 8 Execute-Only Flash Sector I
    Uint16 EXEONLY_SECTJ:1;             // 9 Execute-Only Flash Sector J
    Uint16 EXEONLY_SECTK:1;             // 10 Execute-Only Flash Sector K
    Uint16 EXEONLY_SECTL:1;             // 11 Execute-Only Flash Sector L
    Uint16 EXEONLY_SECTM:1;             // 12 Execute-Only Flash Sector M
    Uint16 EXEONLY_SECTN:1;             // 13 Execute-Only Flash Sector N
    Uint16 EXEONLY_BANK1:1;             // 14 Execute-Only Flash BANK1
    Uint16 rsvd1:1;                     // 15 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union Z2_EXEONLYSECTR_REG {
    Uint32  all;
    struct  Z2_EXEONLYSECTR_BITS  bit;
};

struct Z2_EXEONLYRAMR_BITS {            // bits description
    Uint16 EXEONLY_RAM0:1;              // 0 Execute-Only RAM LS0
    Uint16 EXEONLY_RAM1:1;              // 1 Execute-Only RAM LS1
    Uint16 EXEONLY_RAM2:1;              // 2 Execute-Only RAM LS2
    Uint16 EXEONLY_RAM3:1;              // 3 Execute-Only RAM LS3
    Uint16 EXEONLY_RAM4:1;              // 4 Execute-Only RAM LS4
    Uint16 EXEONLY_RAM5:1;              // 5 Execute-Only RAM LS5
    Uint16 EXEONLY_RAM6:1;              // 6 Execute-Only RAM D0
    Uint16 EXEONLY_RAM7:1;              // 7 Execute-Only RAM D1
    Uint16 rsvd1:8;                     // 15:8 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union Z2_EXEONLYRAMR_REG {
    Uint32  all;
    struct  Z2_EXEONLYRAMR_BITS  bit;
};

struct DCSM_Z2_REGS {
    union   Z2_LINKPOINTER_REG               Z2_LINKPOINTER;               // Zone 2 Link Pointer
    union   Z2_OTPSECLOCK_REG                Z2_OTPSECLOCK;                // Zone 2 OTP Secure JTAG lock
    union   Z2_BOOTCTRL_REG                  Z2_BOOTCTRL;                  // Boot Mode
    Uint32                                   Z2_LINKPOINTERERR;            // Link Pointer Error
    Uint16                                   rsvd1[8];                     // Reserved
    Uint32                                   Z2_CSMKEY0;                   // Zone 2 CSM Key 0
    Uint32                                   Z2_CSMKEY1;                   // Zone 2 CSM Key 1
    Uint32                                   Z2_CSMKEY2;                   // Zone 2 CSM Key 2
    Uint32                                   Z2_CSMKEY3;                   // Zone 2 CSM Key 3
    Uint16                                   rsvd2;                        // Reserved
    union   Z2_CR_REG                        Z2_CR;                        // Zone 2 CSM Control Register
    union   Z2_GRABSECTR_REG                 Z2_GRABSECTR;                 // Zone 2 Grab Flash Sectors Register
    union   Z2_GRABRAMR_REG                  Z2_GRABRAMR;                  // Zone 2 Grab RAM Blocks Register
    union   Z2_EXEONLYSECTR_REG              Z2_EXEONLYSECTR;              // Zone 2 Flash Execute_Only Sector Register
    union   Z2_EXEONLYRAMR_REG               Z2_EXEONLYRAMR;               // Zone 2 RAM Execute_Only Block Register
    Uint16                                   rsvd3;                        // Reserved
};

struct FLSEM_BITS {                     // bits description
    Uint16 SEM:2;                       // 1:0 Flash Semaphore Bit
    Uint16 rsvd1:6;                     // 7:2 Reserved
    Uint16 KEY:8;                       // 15:8 Semaphore Key
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union FLSEM_REG {
    Uint32  all;
    struct  FLSEM_BITS  bit;
};

struct SECTSTAT_BITS {                  // bits description
    Uint16 STATUS_SECTA:2;              // 1:0 Zone Status Flash Sector A
    Uint16 STATUS_SECTB:2;              // 3:2 Zone Status Flash Sector B
    Uint16 STATUS_SECTC:2;              // 5:4 Zone Status Flash Sector C
    Uint16 STATUS_SECTD:2;              // 7:6 Zone Status Flash Sector D 
    Uint16 STATUS_SECTE:2;              // 9:8 Zone Status Flash Sector E
    Uint16 STATUS_SECTF:2;              // 11:10 Zone Status Flash Sector F 
    Uint16 STATUS_SECTG:2;              // 13:12 Zone Status Flash Sector G 
    Uint16 STATUS_SECTH:2;              // 15:14 Zone Status Flash Sector H
    Uint16 STATUS_SECTI:2;              // 17:16 Zone Status Flash Sector I
    Uint16 STATUS_SECTJ:2;              // 19:18 Zone Status Flash Sector J
    Uint16 STATUS_SECTK:2;              // 21:20 Zone Status Flash Sector K
    Uint16 STATUS_SECTL:2;              // 23:22 Zone Status Flash Sector L
    Uint16 STATUS_SECTM:2;              // 25:24 Zone Status Flash Sector M
    Uint16 STATUS_SECTN:2;              // 27:26 Zone Status Flash Sector N
    Uint16 STATUS_BANK1:2;              // 29:28 Zone Status Flash BANK1
    Uint16 rsvd1:2;                     // 31:30 Reserved
};

union SECTSTAT_REG {
    Uint32  all;
    struct  SECTSTAT_BITS  bit;
};

struct RAMSTAT_BITS {                   // bits description
    Uint16 STATUS_RAM0:2;               // 1:0 Zone Status RAM LS0
    Uint16 STATUS_RAM1:2;               // 3:2 Zone Status RAM LS1
    Uint16 STATUS_RAM2:2;               // 5:4 Zone Status RAM LS2
    Uint16 STATUS_RAM3:2;               // 7:6 Zone Status RAM LS3
    Uint16 STATUS_RAM4:2;               // 9:8 Zone Status RAM LS4
    Uint16 STATUS_RAM5:2;               // 11:10 Zone Status RAM LS5
    Uint16 STATUS_RAM6:2;               // 13:12 Zone Status RAM D0
    Uint16 STATUS_RAM7:2;               // 15:14 Zone Status RAM D1
    Uint16 rsvd1:12;                    // 27:16 Reserved
    Uint16 STATUS_CLA1:2;               // 29:28 Zone Status CLA1
    Uint16 rsvd2:2;                     // 31:30 Reserved
};

union RAMSTAT_REG {
    Uint32  all;
    struct  RAMSTAT_BITS  bit;
};

struct DCSM_COMMON_REGS {
    union   FLSEM_REG                        FLSEM;                        // Flash Wrapper Semaphore Register
    union   SECTSTAT_REG                     SECTSTAT;                     // Sectors Status Register
    union   RAMSTAT_REG                      RAMSTAT;                      // RAM Status Register
    Uint16                                   rsvd1[2];                     // Reserved
};

//---------------------------------------------------------------------------
// DCSM External References & Function Declarations:
//
extern volatile struct DCSM_Z1_REGS DcsmZ1Regs;
extern volatile struct DCSM_Z2_REGS DcsmZ2Regs;
extern volatile struct DCSM_COMMON_REGS DcsmCommonRegs;
#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================
