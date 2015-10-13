//###########################################################################
//
// FILE:    F2837xS_cla.h
//
// TITLE:   F2837xS Device CLA Register Definitions.
//
//###########################################################################
// $TI Release: F2837xS Support Library v170 $
// $Release Date: Mon Sep 21 16:56:07 CDT 2015 $
// $Copyright: Copyright (C) 2014-2015 Texas Instruments Incorporated -
//             http://www.ti.com/ ALL RIGHTS RESERVED $
//###########################################################################

#ifndef __F2837xS_CLA_H__
#define __F2837xS_CLA_H__

#ifdef __cplusplus 
extern "C" {
#endif 


//---------------------------------------------------------------------------
// CLA Individual Register Bit Definitions:

struct MCTL_BITS {                      // bits description
    Uint16 HARDRESET:1;                 // 0 Hard Reset
    Uint16 SOFTRESET:1;                 // 1 Soft Reset
    Uint16 IACKE:1;                     // 2 IACK enable
    Uint16 rsvd1:13;                    // 15:3 Reserved
};

union MCTL_REG {
    Uint16  all;
    struct  MCTL_BITS  bit;
};

struct MIFR_BITS {                      // bits description
    Uint16 INT1:1;                      // 0 Task 1 Interrupt Flag
    Uint16 INT2:1;                      // 1 Task 2 Interrupt Flag
    Uint16 INT3:1;                      // 2 Task 3 Interrupt Flag
    Uint16 INT4:1;                      // 3 Task 4 Interrupt Flag
    Uint16 INT5:1;                      // 4 Task 5 Interrupt Flag
    Uint16 INT6:1;                      // 5 Task 6 Interrupt Flag
    Uint16 INT7:1;                      // 6 Task 7 Interrupt Flag
    Uint16 INT8:1;                      // 7 Task 8 Interrupt Flag
    Uint16 rsvd1:8;                     // 15:8 Reserved
};

union MIFR_REG {
    Uint16  all;
    struct  MIFR_BITS  bit;
};

struct MIOVF_BITS {                     // bits description
    Uint16 INT1:1;                      // 0 Task 1 Interrupt Overflow Flag
    Uint16 INT2:1;                      // 1 Task 2 Interrupt Overflow Flag
    Uint16 INT3:1;                      // 2 Task 3 Interrupt Overflow Flag
    Uint16 INT4:1;                      // 3 Task 4 Interrupt Overflow Flag
    Uint16 INT5:1;                      // 4 Task 5 Interrupt Overflow Flag
    Uint16 INT6:1;                      // 5 Task 6 Interrupt Overflow Flag
    Uint16 INT7:1;                      // 6 Task 7 Interrupt Overflow Flag
    Uint16 INT8:1;                      // 7 Task 8 Interrupt Overflow Flag
    Uint16 rsvd1:8;                     // 15:8 Reserved
};

union MIOVF_REG {
    Uint16  all;
    struct  MIOVF_BITS  bit;
};

struct MIFRC_BITS {                     // bits description
    Uint16 INT1:1;                      // 0 Task 1 Interrupt Force
    Uint16 INT2:1;                      // 1 Task 2 Interrupt Force
    Uint16 INT3:1;                      // 2 Task 3 Interrupt Force
    Uint16 INT4:1;                      // 3 Task 4 Interrupt Force
    Uint16 INT5:1;                      // 4 Task 5 Interrupt Force
    Uint16 INT6:1;                      // 5 Task 6 Interrupt Force
    Uint16 INT7:1;                      // 6 Task 7 Interrupt Force
    Uint16 INT8:1;                      // 7 Task 8 Interrupt Force
    Uint16 rsvd1:8;                     // 15:8 Reserved
};

union MIFRC_REG {
    Uint16  all;
    struct  MIFRC_BITS  bit;
};

struct MICLR_BITS {                     // bits description
    Uint16 INT1:1;                      // 0 Task 1 Interrupt Flag Clear
    Uint16 INT2:1;                      // 1 Task 2 Interrupt Flag Clear
    Uint16 INT3:1;                      // 2 Task 3 Interrupt Flag Clear
    Uint16 INT4:1;                      // 3 Task 4 Interrupt Flag Clear
    Uint16 INT5:1;                      // 4 Task 5 Interrupt Flag Clear
    Uint16 INT6:1;                      // 5 Task 6 Interrupt Flag Clear
    Uint16 INT7:1;                      // 6 Task 7 Interrupt Flag Clear
    Uint16 INT8:1;                      // 7 Task 8 Interrupt Flag Clear
    Uint16 rsvd1:8;                     // 15:8 Reserved
};

union MICLR_REG {
    Uint16  all;
    struct  MICLR_BITS  bit;
};

struct MICLROVF_BITS {                  // bits description
    Uint16 INT1:1;                      // 0 Task 1 Interrupt Overflow Flag Clear
    Uint16 INT2:1;                      // 1 Task 2 Interrupt Overflow Flag Clear
    Uint16 INT3:1;                      // 2 Task 3 Interrupt Overflow Flag Clear
    Uint16 INT4:1;                      // 3 Task 4 Interrupt Overflow Flag Clear
    Uint16 INT5:1;                      // 4 Task 5 Interrupt Overflow Flag Clear
    Uint16 INT6:1;                      // 5 Task 6 Interrupt Overflow Flag Clear
    Uint16 INT7:1;                      // 6 Task 7 Interrupt Overflow Flag Clear
    Uint16 INT8:1;                      // 7 Task 8 Interrupt Overflow Flag Clear
    Uint16 rsvd1:8;                     // 15:8 Reserved
};

union MICLROVF_REG {
    Uint16  all;
    struct  MICLROVF_BITS  bit;
};

struct MIER_BITS {                      // bits description
    Uint16 INT1:1;                      // 0 Task 1 Interrupt Enable
    Uint16 INT2:1;                      // 1 Task 2 Interrupt Enable
    Uint16 INT3:1;                      // 2 Task 3 Interrupt Enable
    Uint16 INT4:1;                      // 3 Task 4 Interrupt Enable
    Uint16 INT5:1;                      // 4 Task 5 Interrupt Enable
    Uint16 INT6:1;                      // 5 Task 6 Interrupt Enable
    Uint16 INT7:1;                      // 6 Task 7 Interrupt Enable
    Uint16 INT8:1;                      // 7 Task 8 Interrupt Enable
    Uint16 rsvd1:8;                     // 15:8 Reserved
};

union MIER_REG {
    Uint16  all;
    struct  MIER_BITS  bit;
};

struct MIRUN_BITS {                     // bits description
    Uint16 INT1:1;                      // 0 Task 1 Run Status
    Uint16 INT2:1;                      // 1 Task 2 Run Status
    Uint16 INT3:1;                      // 2 Task 3 Run Status
    Uint16 INT4:1;                      // 3 Task 4 Run Status
    Uint16 INT5:1;                      // 4 Task 5 Run Status
    Uint16 INT6:1;                      // 5 Task 6 Run Status
    Uint16 INT7:1;                      // 6 Task 7 Run Status
    Uint16 INT8:1;                      // 7 Task 8 Run Status
    Uint16 rsvd1:8;                     // 15:8 Reserved
};

union MIRUN_REG {
    Uint16  all;
    struct  MIRUN_BITS  bit;
};

struct _MSTF_BITS {                     // bits description
    Uint16 LVF:1;                       // 0 Latched Overflow Flag 
    Uint16 LUF:1;                       // 1 Latched Underflow Flag 
    Uint16 NF:1;                        // 2 Negative Float Flag 
    Uint16 ZF:1;                        // 3 Zero Float Flag
    Uint16 rsvd1:2;                     // 5:4 Reserved
    Uint16 TF:1;                        // 6 Test Flag 
    Uint16 rsvd2:2;                     // 8:7 Reserved
    Uint16 RNDF32:1;                    // 9 Round 32-bit Floating-Point Mode
    Uint16 rsvd3:1;                     // 10 Reserved
    Uint16 MEALLOW:1;                   // 11 MEALLOW Status
    Uint32 _RPC:16;                     // 27:12 Return PC
    Uint16 rsvd4:4;                     // 31:28 Reserved
};

union _MSTF_REG {
    Uint32  all;
    struct  _MSTF_BITS  bit;
};

union MR_REG {
    Uint32              i32;
    float               f32;
};

struct CLA_REGS {
    Uint16                                   MVECT1;                       // Task Interrupt Vector
    Uint16                                   MVECT2;                       // Task Interrupt Vector
    Uint16                                   MVECT3;                       // Task Interrupt Vector
    Uint16                                   MVECT4;                       // Task Interrupt Vector
    Uint16                                   MVECT5;                       // Task Interrupt Vector
    Uint16                                   MVECT6;                       // Task Interrupt Vector
    Uint16                                   MVECT7;                       // Task Interrupt Vector
    Uint16                                   MVECT8;                       // Task Interrupt Vector
    Uint16                                   rsvd1[8];                     // Reserved
    union   MCTL_REG                         MCTL;                         // Control Register
    Uint16                                   rsvd2[15];                    // Reserved
    union   MIFR_REG                         MIFR;                         // Interrupt Flag Register
    union   MIOVF_REG                        MIOVF;                        // Interrupt Overflow Flag Register
    union   MIFRC_REG                        MIFRC;                        // Interrupt Force Register
    union   MICLR_REG                        MICLR;                        // Interrupt Flag Clear Register
    union   MICLROVF_REG                     MICLROVF;                     // Interrupt Overflow Flag Clear Register
    union   MIER_REG                         MIER;                         // Interrupt Enable Register
    union   MIRUN_REG                        MIRUN;                        // Interrupt Run Status Register
    Uint16                                   rsvd3;                        // Reserved
    Uint16                                   _MPC;                         // CLA Program Counter
    Uint16                                   rsvd4;                        // Reserved
    Uint16                                   _MAR0;                        // CLA Auxiliary Register 0
    Uint16                                   _MAR1;                        // CLA Auxiliary Register 1
    Uint16                                   rsvd5[2];                     // Reserved
    union   _MSTF_REG                        _MSTF;                        // CLA Floating-Point Status Register
    union   MR_REG                           _MR0;                         // CLA Floating-Point Result Register 0
    Uint16                                   rsvd6[2];                     // Reserved
    union   MR_REG                           _MR1;                         // CLA Floating-Point Result Register 1
    Uint16                                   rsvd7[2];                     // Reserved
    union   MR_REG                           _MR2;                         // CLA Floating-Point Result Register 2
    Uint16                                   rsvd8[2];                     // Reserved
    union   MR_REG                           _MR3;                         // CLA Floating-Point Result Register 3
};

struct SOFTINTEN_BITS {                 // bits description
    Uint16 TASK1:1;                     // 0 Task 1 Software Interrupt Enable
    Uint16 TASK2:1;                     // 1 Task 2 Software Interrupt Enable
    Uint16 TASK3:1;                     // 2 Task 3 Software Interrupt Enable
    Uint16 TASK4:1;                     // 3 Task 4 Software Interrupt Enable
    Uint16 TASK5:1;                     // 4 Task 5 Software Interrupt Enable
    Uint16 TASK6:1;                     // 5 Task 6 Software Interrupt Enable
    Uint16 TASK7:1;                     // 6 Task 7 Software Interrupt Enable
    Uint16 TASK8:1;                     // 7 Task 8 Software Interrupt Enable
    Uint16 rsvd1:8;                     // 15:8 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union SOFTINTEN_REG {
    Uint32  all;
    struct  SOFTINTEN_BITS  bit;
};

struct SOFTINTFRC_BITS {                // bits description
    Uint16 TASK1:1;                     // 0 Task 1 Software Interrupt Force
    Uint16 TASK2:1;                     // 1 Task 2 Software Interrupt Force
    Uint16 TASK3:1;                     // 2 Task 3 Software Interrupt Force
    Uint16 TASK4:1;                     // 3 Task 4 Software Interrupt Force
    Uint16 TASK5:1;                     // 4 Task 5 Software Interrupt Force
    Uint16 TASK6:1;                     // 5 Task 6 Software Interrupt Force
    Uint16 TASK7:1;                     // 6 Task 7 Software Interrupt Force
    Uint16 TASK8:1;                     // 7 Task 8 Software Interrupt Force
    Uint16 rsvd1:8;                     // 15:8 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union SOFTINTFRC_REG {
    Uint32  all;
    struct  SOFTINTFRC_BITS  bit;
};

struct CLA_SOFTINT_REGS {
    union   SOFTINTEN_REG                    SOFTINTEN;                    // Task Software Interrupt Enable
    union   SOFTINTFRC_REG                   SOFTINTFRC;                   // Task Software Interrupt Force
};

//---------------------------------------------------------------------------
// CLA External References & Function Declarations:
//
extern volatile struct CLA_SOFTINT_REGS Cla1SoftIntRegs;
extern volatile struct CLA_REGS Cla1Regs;
#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================
