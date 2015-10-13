//###########################################################################
//
// FILE:    F2837xS_nmiintrupt.h
//
// TITLE:   F2837xS Device NMIINTRUPT Register Definitions.
//
//###########################################################################
// $TI Release: F2837xS Support Library v170 $
// $Release Date: Mon Sep 21 16:56:07 CDT 2015 $
// $Copyright: Copyright (C) 2014-2015 Texas Instruments Incorporated -
//             http://www.ti.com/ ALL RIGHTS RESERVED $
//###########################################################################

#ifndef __F2837xS_NMIINTRUPT_H__
#define __F2837xS_NMIINTRUPT_H__

#ifdef __cplusplus 
extern "C" {
#endif 


//---------------------------------------------------------------------------
// NMIINTRUPT Individual Register Bit Definitions:

struct NMICFG_BITS {                    // bits description
    Uint16 NMIE:1;                      // 0 Global NMI Enable
    Uint16 rsvd1:15;                    // 15:1 Reserved
};

union NMICFG_REG {
    Uint16  all;
    struct  NMICFG_BITS  bit;
};

struct NMIFLG_BITS {                    // bits description
    Uint16 NMIINT:1;                    // 0 NMI Interrupt Flag
    Uint16 CLOCKFAIL:1;                 // 1 Clock Fail Interrupt Flag
    Uint16 RAMUNCERR:1;                 // 2 RAM Uncorrectable Error NMI Flag
    Uint16 FLUNCERR:1;                  // 3 Flash Uncorrectable Error NMI Flag
    Uint16 CPU1HWBISTERR:1;             // 4 HW BIST Error NMI Flag
    Uint16 rsvd1:1;                     // 5 Reserved
    Uint16 rsvd2:1;                     // 6 Reserved
    Uint16 rsvd3:1;                     // 7 Reserved
    Uint16 rsvd4:1;                     // 8 Reserved
    Uint16 rsvd5:1;                     // 9 Reserved
    Uint16 rsvd6:1;                     // 10 Reserved
    Uint16 rsvd7:1;                     // 11 Reserved
    Uint16 rsvd8:4;                     // 15:12 Reserved
};

union NMIFLG_REG {
    Uint16  all;
    struct  NMIFLG_BITS  bit;
};

struct NMIFLGCLR_BITS {                 // bits description
    Uint16 NMIINT:1;                    // 0 NMIINT Flag Clear
    Uint16 CLOCKFAIL:1;                 // 1 CLOCKFAIL Flag Clear
    Uint16 RAMUNCERR:1;                 // 2 RAMUNCERR Flag Clear
    Uint16 FLUNCERR:1;                  // 3 FLUNCERR Flag Clear
    Uint16 CPU1HWBISTERR:1;             // 4 CPU1HWBISTERR Flag Clear
    Uint16 rsvd1:1;                     // 5 Reserved
    Uint16 rsvd2:1;                     // 6 Reserved
    Uint16 rsvd3:1;                     // 7 Reserved
    Uint16 rsvd4:1;                     // 8 Reserved
    Uint16 rsvd5:1;                     // 9 Reserved
    Uint16 rsvd6:1;                     // 10 Reserved
    Uint16 OVF:1;                       // 11 OVF Flag Clear
    Uint16 rsvd7:4;                     // 15:12 Reserved
};

union NMIFLGCLR_REG {
    Uint16  all;
    struct  NMIFLGCLR_BITS  bit;
};

struct NMIFLGFRC_BITS {                 // bits description
    Uint16 rsvd1:1;                     // 0 Reserved
    Uint16 CLOCKFAIL:1;                 // 1 CLOCKFAIL Flag Force
    Uint16 RAMUNCERR:1;                 // 2 RAMUNCERR Flag Force
    Uint16 FLUNCERR:1;                  // 3 FLUNCERR Flag Force
    Uint16 CPU1HWBISTERR:1;             // 4 CPU1HWBISTERR Flag Force
    Uint16 rsvd2:1;                     // 5 Reserved
    Uint16 rsvd3:1;                     // 6 Reserved
    Uint16 rsvd4:1;                     // 7 Reserved
    Uint16 rsvd5:1;                     // 8 Reserved
    Uint16 rsvd6:1;                     // 9 Reserved
    Uint16 rsvd7:1;                     // 10 Reserved
    Uint16 OVF:1;                       // 11 OVF Flag Force
    Uint16 rsvd8:4;                     // 15:12 Reserved
};

union NMIFLGFRC_REG {
    Uint16  all;
    struct  NMIFLGFRC_BITS  bit;
};

struct NMISHDFLG_BITS {                 // bits description
    Uint16 rsvd1:1;                     // 0 Reserved
    Uint16 CLOCKFAIL:1;                 // 1 Shadow CLOCKFAIL Flag
    Uint16 RAMUNCERR:1;                 // 2 Shadow RAMUNCERR Flag
    Uint16 FLUNCERR:1;                  // 3 Shadow FLUNCERR Flag
    Uint16 CPU1HWBISTERR:1;             // 4 Shadow CPU1HWBISTERR Flag
    Uint16 rsvd2:1;                     // 5 Reserved
    Uint16 rsvd3:1;                     // 6 Reserved
    Uint16 rsvd4:1;                     // 7 Reserved
    Uint16 rsvd5:1;                     // 8 Reserved
    Uint16 rsvd6:1;                     // 9 Reserved
    Uint16 rsvd7:1;                     // 10 Reserved
    Uint16 OVF:1;                       // 11 Shadow OVF Flag
    Uint16 rsvd8:4;                     // 15:12 Reserved
};

union NMISHDFLG_REG {
    Uint16  all;
    struct  NMISHDFLG_BITS  bit;
};

struct NMI_INTRUPT_REGS {
    union   NMICFG_REG                       NMICFG;                       // NMI Configuration Register
    union   NMIFLG_REG                       NMIFLG;                       // NMI Flag Register (XRSn Clear)
    union   NMIFLGCLR_REG                    NMIFLGCLR;                    // NMI Flag Clear Register
    union   NMIFLGFRC_REG                    NMIFLGFRC;                    // NMI Flag Force Register
    Uint16                                   NMIWDCNT;                     // NMI Watchdog Counter Register
    Uint16                                   NMIWDPRD;                     // NMI Watchdog Period Register
    union   NMISHDFLG_REG                    NMISHDFLG;                    // NMI Shadow Flag Register
};

//---------------------------------------------------------------------------
// NMIINTRUPT External References & Function Declarations:
//
extern volatile struct NMI_INTRUPT_REGS NmiIntruptRegs;
#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================
