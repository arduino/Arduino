//###########################################################################
//
// FILE:    F2837xS_analogsubsys.h
//
// TITLE:   F2837xS Device ANALOGSUBSYS Register Definitions.
//
//###########################################################################
// $TI Release: F2837xS Support Library v170 $
// $Release Date: Mon Sep 21 16:56:07 CDT 2015 $
// $Copyright: Copyright (C) 2014-2015 Texas Instruments Incorporated -
//             http://www.ti.com/ ALL RIGHTS RESERVED $
//###########################################################################

#ifndef __F2837xS_ANALOGSUBSYS_H__
#define __F2837xS_ANALOGSUBSYS_H__

#ifdef __cplusplus 
extern "C" {
#endif 


//---------------------------------------------------------------------------
// ANALOGSUBSYS Individual Register Bit Definitions:

struct INTOSC1TRIM_BITS {               // bits description
    Uint16 VALFINETRIM:12;              // 11:0 Oscillator Value Fine Trim Bits
    Uint16 rsvd1:4;                     // 15:12 Reserved
    Uint16 rsvd2:8;                     // 23:16 Reserved
    Uint16 rsvd3:8;                     // 31:24 Reserved
};

union INTOSC1TRIM_REG {
    Uint32  all;
    struct  INTOSC1TRIM_BITS  bit;
};

struct INTOSC2TRIM_BITS {               // bits description
    Uint16 VALFINETRIM:12;              // 11:0 Oscillator Value Fine Trim Bits
    Uint16 rsvd1:4;                     // 15:12 Reserved
    Uint16 rsvd2:8;                     // 23:16 Reserved
    Uint16 rsvd3:8;                     // 31:24 Reserved
};

union INTOSC2TRIM_REG {
    Uint32  all;
    struct  INTOSC2TRIM_BITS  bit;
};

struct TSNSCTL_BITS {                   // bits description
    Uint16 ENABLE:1;                    // 0 Temperature Sensor Enable
    Uint16 rsvd1:15;                    // 15:1 Reserved
};

union TSNSCTL_REG {
    Uint16  all;
    struct  TSNSCTL_BITS  bit;
};

struct LOCK_BITS {                      // bits description
    Uint16 rsvd1:1;                     // 0 Reserved
    Uint16 rsvd2:1;                     // 1 Reserved
    Uint16 rsvd3:1;                     // 2 Reserved
    Uint16 TSNSCTL:1;                   // 3 Temperature Sensor Control Register Lock
    Uint16 rsvd4:1;                     // 4 Reserved
    Uint16 rsvd5:1;                     // 5 Reserved
    Uint16 rsvd6:1;                     // 6 Reserved
    Uint32 rsvd7:12;                    // 18:7 Reserved
    Uint16 rsvd8:1;                     // 19 Reserved
    Uint16 rsvd9:1;                     // 20 Reserved
    Uint16 rsvd10:1;                    // 21 Reserved
    Uint16 rsvd11:1;                    // 22 Reserved
    Uint16 rsvd12:1;                    // 23 Reserved
    Uint16 rsvd13:1;                    // 24 Reserved
    Uint16 rsvd14:1;                    // 25 Reserved
    Uint16 rsvd15:1;                    // 26 Reserved
    Uint16 rsvd16:1;                    // 27 Reserved
    Uint16 rsvd17:1;                    // 28 Reserved
    Uint16 rsvd18:1;                    // 29 Reserved
    Uint16 rsvd19:1;                    // 30 Reserved
    Uint16 rsvd20:1;                    // 31 Reserved
};

union LOCK_REG {
    Uint32  all;
    struct  LOCK_BITS  bit;
};

struct ANAREFTRIMA_BITS {               // bits description
    Uint16 BGVALTRIM:6;                 // 5:0 Bandgap Value Trim
    Uint16 BGSLOPETRIM:5;               // 10:6 Bandgap Slope Trim
    Uint16 IREFTRIM:5;                  // 15:11 Reference Current Trim
    Uint16 rsvd1:8;                     // 23:16 Reserved
    Uint16 rsvd2:8;                     // 31:24 Reserved
};

union ANAREFTRIMA_REG {
    Uint32  all;
    struct  ANAREFTRIMA_BITS  bit;
};

struct ANAREFTRIMB_BITS {               // bits description
    Uint16 BGVALTRIM:6;                 // 5:0 Bandgap Value Trim
    Uint16 BGSLOPETRIM:5;               // 10:6 Bandgap Slope Trim
    Uint16 IREFTRIM:5;                  // 15:11 Reference Current Trim
    Uint16 rsvd1:8;                     // 23:16 Reserved
    Uint16 rsvd2:8;                     // 31:24 Reserved
};

union ANAREFTRIMB_REG {
    Uint32  all;
    struct  ANAREFTRIMB_BITS  bit;
};

struct ANAREFTRIMC_BITS {               // bits description
    Uint16 BGVALTRIM:6;                 // 5:0 Bandgap Value Trim
    Uint16 BGSLOPETRIM:5;               // 10:6 Bandgap Slope Trim
    Uint16 IREFTRIM:5;                  // 15:11 Reference Current Trim
    Uint16 rsvd1:8;                     // 23:16 Reserved
    Uint16 rsvd2:8;                     // 31:24 Reserved
};

union ANAREFTRIMC_REG {
    Uint32  all;
    struct  ANAREFTRIMC_BITS  bit;
};

struct ANAREFTRIMD_BITS {               // bits description
    Uint16 BGVALTRIM:6;                 // 5:0 Bandgap Value Trim
    Uint16 BGSLOPETRIM:5;               // 10:6 Bandgap Slope Trim
    Uint16 IREFTRIM:5;                  // 15:11 Reference Current Trim
    Uint16 rsvd1:8;                     // 23:16 Reserved
    Uint16 rsvd2:8;                     // 31:24 Reserved
};

union ANAREFTRIMD_REG {
    Uint32  all;
    struct  ANAREFTRIMD_BITS  bit;
};

struct ANALOG_SUBSYS_REGS {
    Uint16                                   rsvd1[32];                    // Reserved
    union   INTOSC1TRIM_REG                  INTOSC1TRIM;                  // Internal Oscillator 1 Trim Register
    union   INTOSC2TRIM_REG                  INTOSC2TRIM;                  // Internal Oscillator 2 Trim Register
    Uint16                                   rsvd2[2];                     // Reserved
    union   TSNSCTL_REG                      TSNSCTL;                      // Temperature Sensor Control Register
    Uint16                                   rsvd3[7];                     // Reserved
    union   LOCK_REG                         LOCK;                         // Lock Register
    Uint16                                   rsvd4[6];                     // Reserved
    union   ANAREFTRIMA_REG                  ANAREFTRIMA;                  // Analog Reference Trim A Register
    union   ANAREFTRIMB_REG                  ANAREFTRIMB;                  // Analog Reference Trim B Register
    union   ANAREFTRIMC_REG                  ANAREFTRIMC;                  // Analog Reference Trim C Register
    union   ANAREFTRIMD_REG                  ANAREFTRIMD;                  // Analog Reference Trim D Register
    Uint16                                   rsvd5[10];                    // Reserved
};

//---------------------------------------------------------------------------
// ANALOGSUBSYS External References & Function Declarations:
//
extern volatile struct ANALOG_SUBSYS_REGS AnalogSubsysRegs;
#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================
