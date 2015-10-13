//###########################################################################
//
// FILE:    F2837xS_dac.h
//
// TITLE:   F2837xS Device DAC Register Definitions.
//
//###########################################################################
// $TI Release: F2837xS Support Library v170 $
// $Release Date: Mon Sep 21 16:56:07 CDT 2015 $
// $Copyright: Copyright (C) 2014-2015 Texas Instruments Incorporated -
//             http://www.ti.com/ ALL RIGHTS RESERVED $
//###########################################################################

#ifndef __F2837xS_DAC_H__
#define __F2837xS_DAC_H__

#ifdef __cplusplus 
extern "C" {
#endif 


//---------------------------------------------------------------------------
// DAC Individual Register Bit Definitions:

struct DACREV_BITS {                    // bits description
    Uint16 REV:8;                       // 7:0 DAC Revision Register
    Uint16 rsvd1:8;                     // 15:8 Reserved
};

union DACREV_REG {
    Uint16  all;
    struct  DACREV_BITS  bit;
};

struct DACCTL_BITS {                    // bits description
    Uint16 DACREFSEL:1;                 // 0 DAC Reference Select
    Uint16 rsvd1:1;                     // 1 Reserved
    Uint16 LOADMODE:1;                  // 2 DACVALA Load Mode
    Uint16 rsvd2:1;                     // 3 Reserved
    Uint16 SYNCSEL:4;                   // 7:4 DAC PWMSYNC Select
    Uint16 rsvd3:8;                     // 15:8 Reserved
};

union DACCTL_REG {
    Uint16  all;
    struct  DACCTL_BITS  bit;
};

struct DACVALA_BITS {                   // bits description
    Uint16 DACVALA:12;                  // 11:0 DAC Active Output Code
    Uint16 rsvd1:4;                     // 15:12 Reserved
};

union DACVALA_REG {
    Uint16  all;
    struct  DACVALA_BITS  bit;
};

struct DACVALS_BITS {                   // bits description
    Uint16 DACVALS:12;                  // 11:0 DAC Shadow Output Code
    Uint16 rsvd1:4;                     // 15:12 Reserved
};

union DACVALS_REG {
    Uint16  all;
    struct  DACVALS_BITS  bit;
};

struct DACOUTEN_BITS {                  // bits description
    Uint16 DACOUTEN:1;                  // 0 DAC Output Code
    Uint16 rsvd1:15;                    // 15:1 Reserved
};

union DACOUTEN_REG {
    Uint16  all;
    struct  DACOUTEN_BITS  bit;
};

struct DACLOCK_BITS {                   // bits description
    Uint16 DACCTL:1;                    // 0 DAC Control Register Lock
    Uint16 DACVAL:1;                    // 1 DAC Value Register Lock
    Uint16 DACOUTEN:1;                  // 2 DAC Output Enable Register Lock
    Uint16 rsvd1:13;                    // 15:3 Reserved
};

union DACLOCK_REG {
    Uint16  all;
    struct  DACLOCK_BITS  bit;
};

struct DACTRIM_BITS {                   // bits description
    Uint16 OFFSET_TRIM:8;               // 7:0 DAC Offset Trim
    Uint16 rsvd1:4;                     // 11:8 Reserved
    Uint16 rsvd2:4;                     // 15:12 Reserved
};

union DACTRIM_REG {
    Uint16  all;
    struct  DACTRIM_BITS  bit;
};

struct DAC_REGS {
    union   DACREV_REG                       DACREV;                       // DAC Revision Register
    union   DACCTL_REG                       DACCTL;                       // DAC Control Register
    union   DACVALA_REG                      DACVALA;                      // DAC Value Register - Active
    union   DACVALS_REG                      DACVALS;                      // DAC Value Register - Shadow
    union   DACOUTEN_REG                     DACOUTEN;                     // DAC Output Enable Register
    union   DACLOCK_REG                      DACLOCK;                      // DAC Lock Register
    union   DACTRIM_REG                      DACTRIM;                      // DAC Trim Register
    Uint16                                   rsvd1;                        // Reserved
};

//---------------------------------------------------------------------------
// DAC External References & Function Declarations:
//
extern volatile struct DAC_REGS DacaRegs;
extern volatile struct DAC_REGS DacbRegs;
extern volatile struct DAC_REGS DaccRegs;
#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================
