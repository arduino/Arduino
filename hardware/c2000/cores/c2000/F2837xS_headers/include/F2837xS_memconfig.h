//###########################################################################
//
// FILE:    F2837xS_memconfig.h
//
// TITLE:   F2837xS Device MEMCONFIG Register Definitions.
//
//###########################################################################
// $TI Release: F2837xS Support Library v170 $
// $Release Date: Mon Sep 21 16:56:07 CDT 2015 $
// $Copyright: Copyright (C) 2014-2015 Texas Instruments Incorporated -
//             http://www.ti.com/ ALL RIGHTS RESERVED $
//###########################################################################

#ifndef __F2837xS_MEMCONFIG_H__
#define __F2837xS_MEMCONFIG_H__

#ifdef __cplusplus 
extern "C" {
#endif 


//---------------------------------------------------------------------------
// MEMCONFIG Individual Register Bit Definitions:

struct DxLOCK_BITS {                    // bits description
    Uint16 rsvd1:2;                     // 1:0 Reserved
    Uint16 LOCK_D0:1;                   // 2 D0 RAM access protection and master select fields lock bit
    Uint16 LOCK_D1:1;                   // 3 D1 RAM access protection and master select fields lock bit
    Uint16 rsvd2:12;                    // 15:4 Reserved
    Uint16 rsvd3:16;                    // 31:16 Reserved
};

union DxLOCK_REG {
    Uint32  all;
    struct  DxLOCK_BITS  bit;
};

struct DxCOMMIT_BITS {                  // bits description
    Uint16 rsvd1:2;                     // 1:0 Reserved
    Uint16 COMMIT_D0:1;                 // 2 D0 RAM access protection and master select permanent lock
    Uint16 COMMIT_D1:1;                 // 3 D1 RAM access protection and master select permanent lock
    Uint16 rsvd2:12;                    // 15:4 Reserved
    Uint16 rsvd3:16;                    // 31:16 Reserved
};

union DxCOMMIT_REG {
    Uint32  all;
    struct  DxCOMMIT_BITS  bit;
};

struct DxACCPROT0_BITS {                // bits description
    Uint16 rsvd1:16;                    // 15:0 Reserved
    Uint16 FETCHPROT_D0:1;              // 16 Fetch Protection For D0 RAM
    Uint16 CPUWRPROT_D0:1;              // 17 CPU WR Protection For D0 RAM
    Uint16 rsvd2:6;                     // 23:18 Reserved
    Uint16 FETCHPROT_D1:1;              // 24 Fetch Protection For D1 RAM
    Uint16 CPUWRPROT_D1:1;              // 25 CPU WR Protection For D1 RAM
    Uint16 rsvd3:6;                     // 31:26 Reserved
};

union DxACCPROT0_REG {
    Uint32  all;
    struct  DxACCPROT0_BITS  bit;
};

struct DxTEST_BITS {                    // bits description
    Uint16 TEST_M0:2;                   // 1:0 Selects the different modes for M0 RAM
    Uint16 TEST_M1:2;                   // 3:2 Selects the different modes for M1 RAM
    Uint16 TEST_D0:2;                   // 5:4 Selects the different modes for D0 RAM
    Uint16 TEST_D1:2;                   // 7:6 Selects the different modes for D1 RAM
    Uint16 rsvd1:8;                     // 15:8 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union DxTEST_REG {
    Uint32  all;
    struct  DxTEST_BITS  bit;
};

struct DxINIT_BITS {                    // bits description
    Uint16 INIT_M0:1;                   // 0 RAM Initialization control for M0 RAM.
    Uint16 INIT_M1:1;                   // 1 RAM Initialization control for M1 RAM.
    Uint16 INIT_D0:1;                   // 2 RAM Initialization control for D0 RAM.
    Uint16 INIT_D1:1;                   // 3 RAM Initialization control for D1 RAM.
    Uint16 rsvd1:12;                    // 15:4 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union DxINIT_REG {
    Uint32  all;
    struct  DxINIT_BITS  bit;
};

struct DxINITDONE_BITS {                // bits description
    Uint16 INITDONE_M0:1;               // 0 RAM Initialization status for M0 RAM.
    Uint16 INITDONE_M1:1;               // 1 RAM Initialization status for M1 RAM.
    Uint16 INITDONE_D0:1;               // 2 RAM Initialization status for D0 RAM.
    Uint16 INITDONE_D1:1;               // 3 RAM Initialization status for D1 RAM.
    Uint16 rsvd1:12;                    // 15:4 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union DxINITDONE_REG {
    Uint32  all;
    struct  DxINITDONE_BITS  bit;
};

struct LSxLOCK_BITS {                   // bits description
    Uint16 LOCK_LS0:1;                  // 0 LS0 RAM access protection and master select fields lock bit
    Uint16 LOCK_LS1:1;                  // 1 LS1 RAM access protection and master select fields lock bit
    Uint16 LOCK_LS2:1;                  // 2 LS2 RAM access protection and master select fields lock bit
    Uint16 LOCK_LS3:1;                  // 3 LS3 RAM access protection and master select fields lock bit
    Uint16 LOCK_LS4:1;                  // 4 LS4 RAM access protection and master select fields lock bit
    Uint16 LOCK_LS5:1;                  // 5 LS5 RAM access protection and master select fields lock bit
    Uint16 rsvd1:10;                    // 15:6 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union LSxLOCK_REG {
    Uint32  all;
    struct  LSxLOCK_BITS  bit;
};

struct LSxCOMMIT_BITS {                 // bits description
    Uint16 COMMIT_LS0:1;                // 0 LS0 RAM access protection and master select permanent lock
    Uint16 COMMIT_LS1:1;                // 1 LS1 RAM access protection and master select permanent lock
    Uint16 COMMIT_LS2:1;                // 2 LS2 RAM access protection and master select permanent lock
    Uint16 COMMIT_LS3:1;                // 3 LS3 RAM access protection and master select permanent lock
    Uint16 COMMIT_LS4:1;                // 4 LS4 RAM access protection and master select permanent lock
    Uint16 COMMIT_LS5:1;                // 5 LS5 RAM access protection and master select permanent lock
    Uint16 rsvd1:10;                    // 15:6 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union LSxCOMMIT_REG {
    Uint32  all;
    struct  LSxCOMMIT_BITS  bit;
};

struct LSxMSEL_BITS {                   // bits description
    Uint16 MSEL_LS0:2;                  // 1:0 Master Select for LS0 RAM
    Uint16 MSEL_LS1:2;                  // 3:2 Master Select for LS1 RAM
    Uint16 MSEL_LS2:2;                  // 5:4 Master Select for LS2 RAM
    Uint16 MSEL_LS3:2;                  // 7:6 Master Select for LS3 RAM
    Uint16 MSEL_LS4:2;                  // 9:8 Master Select for LS4 RAM
    Uint16 MSEL_LS5:2;                  // 11:10 Master Select for LS5 RAM
    Uint16 rsvd1:4;                     // 15:12 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union LSxMSEL_REG {
    Uint32  all;
    struct  LSxMSEL_BITS  bit;
};

struct LSxCLAPGM_BITS {                 // bits description
    Uint16 CLAPGM_LS0:1;                // 0 Selects LS0 RAM as program vs data memory for CLA
    Uint16 CLAPGM_LS1:1;                // 1 Selects LS1 RAM as program vs data memory for CLA
    Uint16 CLAPGM_LS2:1;                // 2 Selects LS2 RAM as program vs data memory for CLA
    Uint16 CLAPGM_LS3:1;                // 3 Selects LS3 RAM as program vs data memory for CLA
    Uint16 CLAPGM_LS4:1;                // 4 Selects LS4 RAM as program vs data memory for CLA
    Uint16 CLAPGM_LS5:1;                // 5 Selects LS5 RAM as program vs data memory for CLA
    Uint16 rsvd1:10;                    // 15:6 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union LSxCLAPGM_REG {
    Uint32  all;
    struct  LSxCLAPGM_BITS  bit;
};

struct LSxACCPROT0_BITS {               // bits description
    Uint16 FETCHPROT_LS0:1;             // 0 Fetch Protection For LS0 RAM
    Uint16 CPUWRPROT_LS0:1;             // 1 CPU WR Protection For LS0 RAM
    Uint16 rsvd1:6;                     // 7:2 Reserved
    Uint16 FETCHPROT_LS1:1;             // 8 Fetch Protection For LS1 RAM
    Uint16 CPUWRPROT_LS1:1;             // 9 CPU WR Protection For LS1 RAM
    Uint16 rsvd2:6;                     // 15:10 Reserved
    Uint16 FETCHPROT_LS2:1;             // 16 Fetch Protection For LS2 RAM
    Uint16 CPUWRPROT_LS2:1;             // 17 CPU WR Protection For LS2 RAM
    Uint16 rsvd3:6;                     // 23:18 Reserved
    Uint16 FETCHPROT_LS3:1;             // 24 Fetch Protection For LS3 RAM
    Uint16 CPUWRPROT_LS3:1;             // 25 CPU WR Protection For LS3 RAM
    Uint16 rsvd4:6;                     // 31:26 Reserved
};

union LSxACCPROT0_REG {
    Uint32  all;
    struct  LSxACCPROT0_BITS  bit;
};

struct LSxACCPROT1_BITS {               // bits description
    Uint16 FETCHPROT_LS4:1;             // 0 Fetch Protection For LS4 RAM
    Uint16 CPUWRPROT_LS4:1;             // 1 CPU WR Protection For LS4 RAM
    Uint16 rsvd1:6;                     // 7:2 Reserved
    Uint16 FETCHPROT_LS5:1;             // 8 Fetch Protection For LS5 RAM
    Uint16 CPUWRPROT_LS5:1;             // 9 CPU WR Protection For LS5 RAM
    Uint16 rsvd2:6;                     // 15:10 Reserved
    Uint16 rsvd3:16;                    // 31:16 Reserved
};

union LSxACCPROT1_REG {
    Uint32  all;
    struct  LSxACCPROT1_BITS  bit;
};

struct LSxTEST_BITS {                   // bits description
    Uint16 TEST_LS0:2;                  // 1:0 Selects the different modes for LS0 RAM
    Uint16 TEST_LS1:2;                  // 3:2 Selects the different modes for LS1 RAM
    Uint16 TEST_LS2:2;                  // 5:4 Selects the different modes for LS2 RAM
    Uint16 TEST_LS3:2;                  // 7:6 Selects the different modes for LS3 RAM
    Uint16 TEST_LS4:2;                  // 9:8 Selects the different modes for LS4 RAM
    Uint16 TEST_LS5:2;                  // 11:10 Selects the different modes for LS5 RAM
    Uint16 rsvd1:4;                     // 15:12 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union LSxTEST_REG {
    Uint32  all;
    struct  LSxTEST_BITS  bit;
};

struct LSxINIT_BITS {                   // bits description
    Uint16 INIT_LS0:1;                  // 0 RAM Initialization control for LS0 RAM.
    Uint16 INIT_LS1:1;                  // 1 RAM Initialization control for LS1 RAM.
    Uint16 INIT_LS2:1;                  // 2 RAM Initialization control for LS2 RAM.
    Uint16 INIT_LS3:1;                  // 3 RAM Initialization control for LS3 RAM.
    Uint16 INIT_LS4:1;                  // 4 RAM Initialization control for LS4 RAM.
    Uint16 INIT_LS5:1;                  // 5 RAM Initialization control for LS5 RAM.
    Uint16 rsvd1:10;                    // 15:6 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union LSxINIT_REG {
    Uint32  all;
    struct  LSxINIT_BITS  bit;
};

struct LSxINITDONE_BITS {               // bits description
    Uint16 INITDONE_LS0:1;              // 0 RAM Initialization status for LS0 RAM.
    Uint16 INITDONE_LS1:1;              // 1 RAM Initialization status for LS1 RAM.
    Uint16 INITDONE_LS2:1;              // 2 RAM Initialization status for LS2 RAM.
    Uint16 INITDONE_LS3:1;              // 3 RAM Initialization status for LS3 RAM.
    Uint16 INITDONE_LS4:1;              // 4 RAM Initialization status for LS4 RAM.
    Uint16 INITDONE_LS5:1;              // 5 RAM Initialization status for LS5 RAM.
    Uint16 rsvd1:10;                    // 15:6 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union LSxINITDONE_REG {
    Uint32  all;
    struct  LSxINITDONE_BITS  bit;
};

struct GSxLOCK_BITS {                   // bits description
    Uint16 LOCK_GS0:1;                  // 0 GS0 RAM access protection and master select fields lock bit
    Uint16 LOCK_GS1:1;                  // 1 GS1 RAM access protection and master select fields lock bit
    Uint16 LOCK_GS2:1;                  // 2 GS2 RAM access protection and master select fields lock bit
    Uint16 LOCK_GS3:1;                  // 3 GS3 RAM access protection and master select fields lock bit
    Uint16 LOCK_GS4:1;                  // 4 GS4 RAM access protection and master select fields lock bit
    Uint16 LOCK_GS5:1;                  // 5 GS5 RAM access protection and master select fields lock bit
    Uint16 LOCK_GS6:1;                  // 6 GS6 RAM access protection and master select fields lock bit
    Uint16 LOCK_GS7:1;                  // 7 GS7 RAM access protection and master select fields lock bit
    Uint16 LOCK_GS8:1;                  // 8 GS8 RAM access protection and master select fields lock bit
    Uint16 LOCK_GS9:1;                  // 9 GS9 RAM access protection and master select fields lock bit
    Uint16 LOCK_GS10:1;                 // 10 GS10 RAM access protection and master select fields lock bit
    Uint16 LOCK_GS11:1;                 // 11 GS11 RAM access protection and master select fields lock bit
    Uint16 LOCK_GS12:1;                 // 12 GS12 RAM access protection and master select fields lock bit
    Uint16 LOCK_GS13:1;                 // 13 GS13 RAM access protection and master select fields lock bit
    Uint16 LOCK_GS14:1;                 // 14 GS14 RAM access protection and master select fields lock bit
    Uint16 LOCK_GS15:1;                 // 15 GS15 RAM access protection and master select fields lock bit
    Uint16 rsvd1:16;                    // 31:16 Reserved
};

union GSxLOCK_REG {
    Uint32  all;
    struct  GSxLOCK_BITS  bit;
};

struct GSxCOMMIT_BITS {                 // bits description
    Uint16 COMMIT_GS0:1;                // 0 GS0 RAM access protection and master select permanent lock
    Uint16 COMMIT_GS1:1;                // 1 GS1 RAM access protection and master select permanent lock
    Uint16 COMMIT_GS2:1;                // 2 GS2 RAM access protection and master select permanent lock
    Uint16 COMMIT_GS3:1;                // 3 GS3 RAM access protection and master select permanent lock
    Uint16 COMMIT_GS4:1;                // 4 GS4 RAM access protection and master select permanent lock
    Uint16 COMMIT_GS5:1;                // 5 GS5 RAM access protection and master select permanent lock
    Uint16 COMMIT_GS6:1;                // 6 GS6 RAM access protection and master select permanent lock
    Uint16 COMMIT_GS7:1;                // 7 GS7 RAM access protection and master select permanent lock
    Uint16 COMMIT_GS8:1;                // 8 GS8 RAM access protection and master select permanent lock
    Uint16 COMMIT_GS9:1;                // 9 GS9 RAM access protection and master select permanent lock
    Uint16 COMMIT_GS10:1;               // 10 GS10 RAM access protection and master select permanent lock
    Uint16 COMMIT_GS11:1;               // 11 GS11 RAM access protection and master select permanent lock
    Uint16 COMMIT_GS12:1;               // 12 GS12 RAM access protection and master select permanent lock
    Uint16 COMMIT_GS13:1;               // 13 GS13 RAM access protection and master select permanent lock
    Uint16 COMMIT_GS14:1;               // 14 GS14 RAM access protection and master select permanent lock
    Uint16 COMMIT_GS15:1;               // 15 GS15 RAM access protection and master select permanent lock
    Uint16 rsvd1:16;                    // 31:16 Reserved
};

union GSxCOMMIT_REG {
    Uint32  all;
    struct  GSxCOMMIT_BITS  bit;
};

struct GSxACCPROT0_BITS {               // bits description
    Uint16 FETCHPROT_GS0:1;             // 0 Fetch Protection For GS0 RAM
    Uint16 CPUWRPROT_GS0:1;             // 1 CPU WR Protection For GS0 RAM
    Uint16 DMAWRPROT_GS0:1;             // 2 DMA WR Protection For GS0 RAM
    Uint16 rsvd1:5;                     // 7:3 Reserved
    Uint16 FETCHPROT_GS1:1;             // 8 Fetch Protection For GS1 RAM
    Uint16 CPUWRPROT_GS1:1;             // 9 CPU WR Protection For GS1 RAM
    Uint16 DMAWRPROT_GS1:1;             // 10 DMA WR Protection For GS1 RAM
    Uint16 rsvd2:5;                     // 15:11 Reserved
    Uint16 FETCHPROT_GS2:1;             // 16 Fetch Protection For GS2 RAM
    Uint16 CPUWRPROT_GS2:1;             // 17 CPU WR Protection For GS2 RAM
    Uint16 DMAWRPROT_GS2:1;             // 18 DMA WR Protection For GS2 RAM
    Uint16 rsvd3:5;                     // 23:19 Reserved
    Uint16 FETCHPROT_GS3:1;             // 24 Fetch Protection For GS3 RAM
    Uint16 CPUWRPROT_GS3:1;             // 25 CPU WR Protection For GS3 RAM
    Uint16 DMAWRPROT_GS3:1;             // 26 DMA WR Protection For GS3 RAM
    Uint16 rsvd4:5;                     // 31:27 Reserved
};

union GSxACCPROT0_REG {
    Uint32  all;
    struct  GSxACCPROT0_BITS  bit;
};

struct GSxACCPROT1_BITS {               // bits description
    Uint16 FETCHPROT_GS4:1;             // 0 Fetch Protection For GS4 RAM
    Uint16 CPUWRPROT_GS4:1;             // 1 CPU WR Protection For GS4 RAM
    Uint16 DMAWRPROT_GS4:1;             // 2 DMA WR Protection For GS4 RAM
    Uint16 rsvd1:5;                     // 7:3 Reserved
    Uint16 FETCHPROT_GS5:1;             // 8 Fetch Protection For GS5 RAM
    Uint16 CPUWRPROT_GS5:1;             // 9 CPU WR Protection For GS5 RAM
    Uint16 DMAWRPROT_GS5:1;             // 10 DMA WR Protection For GS5RAM
    Uint16 rsvd2:5;                     // 15:11 Reserved
    Uint16 FETCHPROT_GS6:1;             // 16 Fetch Protection For GS6 RAM
    Uint16 CPUWRPROT_GS6:1;             // 17 CPU WR Protection For GS6 RAM
    Uint16 DMAWRPROT_GS6:1;             // 18 DMA WR Protection For GS6RAM
    Uint16 rsvd3:5;                     // 23:19 Reserved
    Uint16 FETCHPROT_GS7:1;             // 24 Fetch Protection For GS7 RAM
    Uint16 CPUWRPROT_GS7:1;             // 25 CPU WR Protection For GS7 RAM
    Uint16 DMAWRPROT_GS7:1;             // 26 DMA WR Protection For GS7RAM
    Uint16 rsvd4:5;                     // 31:27 Reserved
};

union GSxACCPROT1_REG {
    Uint32  all;
    struct  GSxACCPROT1_BITS  bit;
};

struct GSxACCPROT2_BITS {               // bits description
    Uint16 FETCHPROT_GS8:1;             // 0 Fetch Protection For GS8 RAM
    Uint16 CPUWRPROT_GS8:1;             // 1 CPU WR Protection For GS8 RAM
    Uint16 DMAWRPROT_GS8:1;             // 2 DMA WR Protection For GS8 RAM
    Uint16 rsvd1:5;                     // 7:3 Reserved
    Uint16 FETCHPROT_GS9:1;             // 8 Fetch Protection For GS9 RAM
    Uint16 CPUWRPROT_GS9:1;             // 9 CPU WR Protection For GS9 RAM
    Uint16 DMAWRPROT_GS9:1;             // 10 DMA WR Protection For GS9RAM
    Uint16 rsvd2:5;                     // 15:11 Reserved
    Uint16 FETCHPROT_GS10:1;            // 16 Fetch Protection For GS10 RAM
    Uint16 CPUWRPROT_GS10:1;            // 17 CPU WR Protection For GS10 RAM
    Uint16 DMAWRPROT_GS10:1;            // 18 DMA WR Protection For GS10RAM
    Uint16 rsvd3:5;                     // 23:19 Reserved
    Uint16 FETCHPROT_GS11:1;            // 24 Fetch Protection For GS11 RAM
    Uint16 CPUWRPROT_GS11:1;            // 25 CPU WR Protection For GS11 RAM
    Uint16 DMAWRPROT_GS11:1;            // 26 DMA WR Protection For GS11RAM
    Uint16 rsvd4:5;                     // 31:27 Reserved
};

union GSxACCPROT2_REG {
    Uint32  all;
    struct  GSxACCPROT2_BITS  bit;
};

struct GSxACCPROT3_BITS {               // bits description
    Uint16 FETCHPROT_GS12:1;            // 0 Fetch Protection For GS12 RAM
    Uint16 CPUWRPROT_GS12:1;            // 1 CPU WR Protection For GS12 RAM
    Uint16 DMAWRPROT_GS12:1;            // 2 DMA WR Protection For GS12 RAM
    Uint16 rsvd1:5;                     // 7:3 Reserved
    Uint16 FETCHPROT_GS13:1;            // 8 Fetch Protection For GS13 RAM
    Uint16 CPUWRPROT_GS13:1;            // 9 CPU WR Protection For GS13 RAM
    Uint16 DMAWRPROT_GS13:1;            // 10 DMA WR Protection For GS13RAM
    Uint16 rsvd2:5;                     // 15:11 Reserved
    Uint16 FETCHPROT_GS14:1;            // 16 Fetch Protection For GS14 RAM
    Uint16 CPUWRPROT_GS14:1;            // 17 CPU WR Protection For GS14 RAM
    Uint16 DMAWRPROT_GS14:1;            // 18 DMA WR Protection For GS14RAM
    Uint16 rsvd3:5;                     // 23:19 Reserved
    Uint16 FETCHPROT_GS15:1;            // 24 Fetch Protection For GS15 RAM
    Uint16 CPUWRPROT_GS15:1;            // 25 CPU WR Protection For GS15 RAM
    Uint16 DMAWRPROT_GS15:1;            // 26 DMA WR Protection For GS15RAM
    Uint16 rsvd4:5;                     // 31:27 Reserved
};

union GSxACCPROT3_REG {
    Uint32  all;
    struct  GSxACCPROT3_BITS  bit;
};

struct GSxTEST_BITS {                   // bits description
    Uint16 TEST_GS0:2;                  // 1:0 Selects the different modes for GS0 RAM
    Uint16 TEST_GS1:2;                  // 3:2 Selects the different modes for GS1 RAM
    Uint16 TEST_GS2:2;                  // 5:4 Selects the different modes for GS2 RAM
    Uint16 TEST_GS3:2;                  // 7:6 Selects the different modes for GS3 RAM
    Uint16 TEST_GS4:2;                  // 9:8 Selects the different modes for GS4 RAM
    Uint16 TEST_GS5:2;                  // 11:10 Selects the different modes for GS5 RAM
    Uint16 TEST_GS6:2;                  // 13:12 Selects the different modes for GS6 RAM
    Uint16 TEST_GS7:2;                  // 15:14 Selects the different modes for GS7 RAM
    Uint16 TEST_GS8:2;                  // 17:16 Selects the different modes for GS8 RAM
    Uint16 TEST_GS9:2;                  // 19:18 Selects the different modes for GS9 RAM
    Uint16 TEST_GS10:2;                 // 21:20 Selects the different modes for GS10 RAM
    Uint16 TEST_GS11:2;                 // 23:22 Selects the different modes for GS11 RAM
    Uint16 TEST_GS12:2;                 // 25:24 Selects the different modes for GS12 RAM
    Uint16 TEST_GS13:2;                 // 27:26 Selects the different modes for GS13 RAM
    Uint16 TEST_GS14:2;                 // 29:28 Selects the different modes for GS14 RAM
    Uint16 TEST_GS15:2;                 // 31:30 Selects the different modes for GS15 RAM
};

union GSxTEST_REG {
    Uint32  all;
    struct  GSxTEST_BITS  bit;
};

struct GSxINIT_BITS {                   // bits description
    Uint16 INIT_GS0:1;                  // 0 RAM Initialization control for GS0 RAM.
    Uint16 INIT_GS1:1;                  // 1 RAM Initialization control for GS1 RAM.
    Uint16 INIT_GS2:1;                  // 2 RAM Initialization control for GS2 RAM.
    Uint16 INIT_GS3:1;                  // 3 RAM Initialization control for GS3 RAM.
    Uint16 INIT_GS4:1;                  // 4 RAM Initialization control for GS4 RAM.
    Uint16 INIT_GS5:1;                  // 5 RAM Initialization control for GS5 RAM.
    Uint16 INIT_GS6:1;                  // 6 RAM Initialization control for GS6 RAM.
    Uint16 INIT_GS7:1;                  // 7 RAM Initialization control for GS7 RAM.
    Uint16 INIT_GS8:1;                  // 8 RAM Initialization control for GS8 RAM.
    Uint16 INIT_GS9:1;                  // 9 RAM Initialization control for GS9 RAM.
    Uint16 INIT_GS10:1;                 // 10 RAM Initialization control for GS10 RAM.
    Uint16 INIT_GS11:1;                 // 11 RAM Initialization control for GS11 RAM.
    Uint16 INIT_GS12:1;                 // 12 RAM Initialization control for GS12 RAM.
    Uint16 INIT_GS13:1;                 // 13 RAM Initialization control for GS13 RAM.
    Uint16 INIT_GS14:1;                 // 14 RAM Initialization control for GS14 RAM.
    Uint16 INIT_GS15:1;                 // 15 RAM Initialization control for GS15 RAM.
    Uint16 rsvd1:16;                    // 31:16 Reserved
};

union GSxINIT_REG {
    Uint32  all;
    struct  GSxINIT_BITS  bit;
};

struct GSxINITDONE_BITS {               // bits description
    Uint16 INITDONE_GS0:1;              // 0 RAM Initialization status for GS0 RAM.
    Uint16 INITDONE_GS1:1;              // 1 RAM Initialization status for GS1 RAM.
    Uint16 INITDONE_GS2:1;              // 2 RAM Initialization status for GS2 RAM.
    Uint16 INITDONE_GS3:1;              // 3 RAM Initialization status for GS3 RAM.
    Uint16 INITDONE_GS4:1;              // 4 RAM Initialization status for GS4 RAM.
    Uint16 INITDONE_GS5:1;              // 5 RAM Initialization status for GS5 RAM.
    Uint16 INITDONE_GS6:1;              // 6 RAM Initialization status for GS6 RAM.
    Uint16 INITDONE_GS7:1;              // 7 RAM Initialization status for GS7 RAM.
    Uint16 INITDONE_GS8:1;              // 8 RAM Initialization status for GS8 RAM.
    Uint16 INITDONE_GS9:1;              // 9 RAM Initialization status for GS9 RAM.
    Uint16 INITDONE_GS10:1;             // 10 RAM Initialization status for GS10 RAM.
    Uint16 INITDONE_GS11:1;             // 11 RAM Initialization status for GS11 RAM.
    Uint16 INITDONE_GS12:1;             // 12 RAM Initialization status for GS12 RAM.
    Uint16 INITDONE_GS13:1;             // 13 RAM Initialization status for GS13 RAM.
    Uint16 INITDONE_GS14:1;             // 14 RAM Initialization status for GS14 RAM.
    Uint16 INITDONE_GS15:1;             // 15 RAM Initialization status for GS15 RAM.
    Uint16 rsvd1:16;                    // 31:16 Reserved
};

union GSxINITDONE_REG {
    Uint32  all;
    struct  GSxINITDONE_BITS  bit;
};

struct MSGxTEST_BITS {                  // bits description
    Uint16 TEST_CPUTOCPU:2;             // 1:0 CPU to CPU Mode Select
    Uint16 TEST_CPUTOCLA1:2;            // 3:2 CPU to CLA1 MSG RAM Mode Select
    Uint16 TEST_CLA1TOCPU:2;            // 5:4 CLA1 to CPU MSG RAM Mode Select
    Uint16 rsvd1:2;                     // 7:6 Reserved
    Uint16 rsvd2:2;                     // 9:8 Reserved
    Uint16 rsvd3:6;                     // 15:10 Reserved
    Uint16 rsvd4:16;                    // 31:16 Reserved
};

union MSGxTEST_REG {
    Uint32  all;
    struct  MSGxTEST_BITS  bit;
};

struct MSGxINIT_BITS {                  // bits description
    Uint16 INIT_CPUTOCPU:1;             // 0 Initialization control for CPU to CPU MSG RAM
    Uint16 INIT_CPUTOCLA1:1;            // 1 Initialization control for CPUTOCLA1 MSG RAM
    Uint16 INIT_CLA1TOCPU:1;            // 2 Initialization control for CLA1TOCPU MSG RAM
    Uint16 rsvd1:1;                     // 3 Reserved
    Uint16 rsvd2:1;                     // 4 Reserved
    Uint16 rsvd3:11;                    // 15:5 Reserved
    Uint16 rsvd4:16;                    // 31:16 Reserved
};

union MSGxINIT_REG {
    Uint32  all;
    struct  MSGxINIT_BITS  bit;
};

struct MSGxINITDONE_BITS {              // bits description
    Uint16 INITDONE_CPUTOCPU:1;         // 0 Initialization status for CPU to CPU MSG RAM
    Uint16 INITDONE_CPUTOCLA1:1;        // 1 Initialization status for CPU to CLA1 MSG RAM
    Uint16 INITDONE_CLA1TOCPU:1;        // 2 Initialization status for CLA1 to CPU MSG RAM
    Uint16 rsvd1:1;                     // 3 Reserved
    Uint16 rsvd2:1;                     // 4 Reserved
    Uint16 rsvd3:11;                    // 15:5 Reserved
    Uint16 rsvd4:16;                    // 31:16 Reserved
};

union MSGxINITDONE_REG {
    Uint32  all;
    struct  MSGxINITDONE_BITS  bit;
};

struct MEM_CFG_REGS {
    union   DxLOCK_REG                       DxLOCK;                       // Dedicated RAM Config Lock Register
    union   DxCOMMIT_REG                     DxCOMMIT;                     // Dedicated RAM Config Lock Commit Register
    Uint16                                   rsvd1[4];                     // Reserved
    union   DxACCPROT0_REG                   DxACCPROT0;                   // Dedicated RAM Config Register
    Uint16                                   rsvd2[6];                     // Reserved
    union   DxTEST_REG                       DxTEST;                       // Dedicated RAM TEST Register
    union   DxINIT_REG                       DxINIT;                       // Dedicated RAM Init Register
    union   DxINITDONE_REG                   DxINITDONE;                   // Dedicated RAM InitDone Status Register
    Uint16                                   rsvd3[10];                    // Reserved
    union   LSxLOCK_REG                      LSxLOCK;                      // Local Shared RAM Config Lock Register
    union   LSxCOMMIT_REG                    LSxCOMMIT;                    // Local Shared RAM Config Lock Commit Register
    union   LSxMSEL_REG                      LSxMSEL;                      // Local Shared RAM Master Sel Register
    union   LSxCLAPGM_REG                    LSxCLAPGM;                    // Local Shared RAM Prog/Exe control Register
    union   LSxACCPROT0_REG                  LSxACCPROT0;                  // Local Shared RAM Config Register 0
    union   LSxACCPROT1_REG                  LSxACCPROT1;                  // Local Shared RAM Config Register 1
    Uint16                                   rsvd4[4];                     // Reserved
    union   LSxTEST_REG                      LSxTEST;                      // Local Shared RAM TEST Register
    union   LSxINIT_REG                      LSxINIT;                      // Local Shared RAM Init Register
    union   LSxINITDONE_REG                  LSxINITDONE;                  // Local Shared RAM InitDone Status Register
    Uint16                                   rsvd5[10];                    // Reserved
    union   GSxLOCK_REG                      GSxLOCK;                      // Global Shared RAM Config Lock Register
    union   GSxCOMMIT_REG                    GSxCOMMIT;                    // Global Shared RAM Config Lock Commit Register
    Uint16                                   rsvd6[4];                     // Reserved
    union   GSxACCPROT0_REG                  GSxACCPROT0;                  // Global Shared RAM Config Register 0
    union   GSxACCPROT1_REG                  GSxACCPROT1;                  // Global Shared RAM Config Register 1
    union   GSxACCPROT2_REG                  GSxACCPROT2;                  // Global Shared RAM Config Register 2
    union   GSxACCPROT3_REG                  GSxACCPROT3;                  // Global Shared RAM Config Register 3
    union   GSxTEST_REG                      GSxTEST;                      // Global Shared RAM TEST Register
    union   GSxINIT_REG                      GSxINIT;                      // Global Shared RAM Init Register
    union   GSxINITDONE_REG                  GSxINITDONE;                  // Global Shared RAM InitDone Status Register
    Uint16                                   rsvd7[26];                    // Reserved
    union   MSGxTEST_REG                     MSGxTEST;                     // Message RAM TEST Register
    union   MSGxINIT_REG                     MSGxINIT;                     // Message RAM Init Register
    union   MSGxINITDONE_REG                 MSGxINITDONE;                 // Message RAM InitDone Status Register
    Uint16                                   rsvd8[10];                    // Reserved
};

struct EMIF1LOCK_BITS {                 // bits description
    Uint16 LOCK_EMIF1:1;                // 0 EMIF1 access protection and master select fields lock bit
    Uint16 rsvd1:15;                    // 15:1 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union EMIF1LOCK_REG {
    Uint32  all;
    struct  EMIF1LOCK_BITS  bit;
};

struct EMIF1COMMIT_BITS {               // bits description
    Uint16 COMMIT_EMIF1:1;              // 0 EMIF1 access protection and master select permanent lock
    Uint16 rsvd1:15;                    // 15:1 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union EMIF1COMMIT_REG {
    Uint32  all;
    struct  EMIF1COMMIT_BITS  bit;
};

struct EMIF1ACCPROT0_BITS {             // bits description
    Uint16 FETCHPROT_EMIF1:1;           // 0 Fetch Protection For EMIF1
    Uint16 CPUWRPROT_EMIF1:1;           // 1 CPU WR Protection For EMIF1
    Uint16 DMAWRPROT_EMIF1:1;           // 2 DMA WR Protection For EMIF1
    Uint16 rsvd1:13;                    // 15:3 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union EMIF1ACCPROT0_REG {
    Uint32  all;
    struct  EMIF1ACCPROT0_BITS  bit;
};

struct EMIF1_CONFIG_REGS {
    union   EMIF1LOCK_REG                    EMIF1LOCK;                    // EMIF1 Config Lock Register
    union   EMIF1COMMIT_REG                  EMIF1COMMIT;                  // EMIF1 Config Lock Commit Register
    Uint16                                   rsvd1[4];                     // Reserved
    union   EMIF1ACCPROT0_REG                EMIF1ACCPROT0;                // EMIF1 Config Register 0
    Uint16                                   rsvd2[22];                    // Reserved
};

struct EMIF2LOCK_BITS {                 // bits description
    Uint16 LOCK_EMIF2:1;                // 0 EMIF2 access protection and master select permanent lock
    Uint16 rsvd1:15;                    // 15:1 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union EMIF2LOCK_REG {
    Uint32  all;
    struct  EMIF2LOCK_BITS  bit;
};

struct EMIF2COMMIT_BITS {               // bits description
    Uint16 COMMIT_EMIF2:1;              // 0 EMIF2 access protection and master select permanent lock
    Uint16 rsvd1:15;                    // 15:1 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union EMIF2COMMIT_REG {
    Uint32  all;
    struct  EMIF2COMMIT_BITS  bit;
};

struct EMIF2ACCPROT0_BITS {             // bits description
    Uint16 FETCHPROT_EMIF1:1;           // 0 Fetch Protection For EMIF2
    Uint16 CPUWRPROT_EMIF1:1;           // 1 CPU WR Protection For EMIF2
    Uint16 rsvd1:14;                    // 15:2 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union EMIF2ACCPROT0_REG {
    Uint32  all;
    struct  EMIF2ACCPROT0_BITS  bit;
};

struct EMIF2_CONFIG_REGS {
    union   EMIF2LOCK_REG                    EMIF2LOCK;                    // EMIF2 Config Lock Register
    union   EMIF2COMMIT_REG                  EMIF2COMMIT;                  // EMIF2 Config Lock Commit Register
    Uint16                                   rsvd1[4];                     // Reserved
    union   EMIF2ACCPROT0_REG                EMIF2ACCPROT0;                // EMIF2 Config Register 0
    Uint16                                   rsvd2[22];                    // Reserved
};

struct NMAVFLG_BITS {                   // bits description
    Uint16 CPUREAD:1;                   // 0 Non Master CPU Read Access Violation Flag
    Uint16 CPUWRITE:1;                  // 1 Non Master CPU Write Access Violation Flag
    Uint16 CPUFETCH:1;                  // 2 Non Master CPU Fetch Access Violation Flag
    Uint16 DMAWRITE:1;                  // 3 Non Master DMA Write Access Violation Flag
    Uint16 CLA1READ:1;                  // 4 Non Master CLA1 Read Access Violation Flag
    Uint16 CLA1WRITE:1;                 // 5 Non Master CLA1 Write Access Violation Flag
    Uint16 CLA1FETCH:1;                 // 6 Non Master CLA1 Fetch Access Violation Flag
    Uint16 rsvd1:1;                     // 7 Reserved
    Uint16 rsvd2:1;                     // 8 Reserved
    Uint16 rsvd3:1;                     // 9 Reserved
    Uint16 rsvd4:6;                     // 15:10 Reserved
    Uint16 rsvd5:16;                    // 31:16 Reserved
};

union NMAVFLG_REG {
    Uint32  all;
    struct  NMAVFLG_BITS  bit;
};

struct NMAVSET_BITS {                   // bits description
    Uint16 CPUREAD:1;                   // 0 Non Master CPU Read Access Violation Flag Set
    Uint16 CPUWRITE:1;                  // 1 Non Master CPU Write Access Violation Flag Set
    Uint16 CPUFETCH:1;                  // 2 Non Master CPU Fetch Access Violation Flag Set
    Uint16 DMAWRITE:1;                  // 3 Non Master DMA Write Access Violation Flag Set
    Uint16 CLA1READ:1;                  // 4 Non Master CLA1 Read Access Violation Flag Set
    Uint16 CLA1WRITE:1;                 // 5 Non Master CLA1 Write Access Violation Flag Set
    Uint16 CLA1FETCH:1;                 // 6 Non Master CLA1 Fetch Access Violation Flag Set
    Uint16 rsvd1:1;                     // 7 Reserved
    Uint16 rsvd2:1;                     // 8 Reserved
    Uint16 rsvd3:1;                     // 9 Reserved
    Uint16 rsvd4:6;                     // 15:10 Reserved
    Uint16 rsvd5:16;                    // 31:16 Reserved
};

union NMAVSET_REG {
    Uint32  all;
    struct  NMAVSET_BITS  bit;
};

struct NMAVCLR_BITS {                   // bits description
    Uint16 CPUREAD:1;                   // 0 Non Master CPU Read Access Violation Flag Clear 
    Uint16 CPUWRITE:1;                  // 1 Non Master CPU Write Access Violation Flag Clear 
    Uint16 CPUFETCH:1;                  // 2 Non Master CPU Fetch Access Violation Flag Clear 
    Uint16 DMAWRITE:1;                  // 3 Non Master DMA Write Access Violation Flag Clear 
    Uint16 CLA1READ:1;                  // 4 Non Master CLA1 Read Access Violation Flag Clear 
    Uint16 CLA1WRITE:1;                 // 5 Non Master CLA1 Write Access Violation Flag Clear 
    Uint16 CLA1FETCH:1;                 // 6 Non Master CLA1 Fetch Access Violation Flag Clear 
    Uint16 rsvd1:1;                     // 7 Reserved
    Uint16 rsvd2:1;                     // 8 Reserved
    Uint16 rsvd3:1;                     // 9 Reserved
    Uint16 rsvd4:6;                     // 15:10 Reserved
    Uint16 rsvd5:16;                    // 31:16 Reserved
};

union NMAVCLR_REG {
    Uint32  all;
    struct  NMAVCLR_BITS  bit;
};

struct NMAVINTEN_BITS {                 // bits description
    Uint16 CPUREAD:1;                   // 0 Non Master CPU Read Access Violation Interrupt Enable 
    Uint16 CPUWRITE:1;                  // 1 Non Master CPU Write Access Violation Interrupt Enable 
    Uint16 CPUFETCH:1;                  // 2 Non Master CPU Fetch Access Violation Interrupt Enable 
    Uint16 DMAWRITE:1;                  // 3 Non Master DMA Write Access Violation Interrupt Enable 
    Uint16 CLA1READ:1;                  // 4 Non Master CLA1 Read Access Violation Interrupt Enable 
    Uint16 CLA1WRITE:1;                 // 5 Non Master CLA1 Write Access Violation Interrupt Enable 
    Uint16 CLA1FETCH:1;                 // 6 Non Master CLA1 Fetch Access Violation Interrupt Enable 
    Uint16 rsvd1:1;                     // 7 Reserved
    Uint16 rsvd2:1;                     // 8 Reserved
    Uint16 rsvd3:1;                     // 9 Reserved
    Uint16 rsvd4:6;                     // 15:10 Reserved
    Uint16 rsvd5:16;                    // 31:16 Reserved
};

union NMAVINTEN_REG {
    Uint32  all;
    struct  NMAVINTEN_BITS  bit;
};

struct MAVFLG_BITS {                    // bits description
    Uint16 CPUFETCH:1;                  // 0 Master CPU Fetch Access Violation Flag
    Uint16 CPUWRITE:1;                  // 1 Master CPU Write Access Violation Flag
    Uint16 DMAWRITE:1;                  // 2 Master DMA Write Access Violation Flag
    Uint16 rsvd1:13;                    // 15:3 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union MAVFLG_REG {
    Uint32  all;
    struct  MAVFLG_BITS  bit;
};

struct MAVSET_BITS {                    // bits description
    Uint16 CPUFETCH:1;                  // 0 Master CPU Fetch Access Violation Flag Set
    Uint16 CPUWRITE:1;                  // 1 Master CPU Write Access Violation Flag Set
    Uint16 DMAWRITE:1;                  // 2 Master DMA Write Access Violation Flag Set
    Uint16 rsvd1:13;                    // 15:3 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union MAVSET_REG {
    Uint32  all;
    struct  MAVSET_BITS  bit;
};

struct MAVCLR_BITS {                    // bits description
    Uint16 CPUFETCH:1;                  // 0 Master CPU Fetch Access Violation Flag Clear 
    Uint16 CPUWRITE:1;                  // 1 Master CPU Write Access Violation Flag Clear 
    Uint16 DMAWRITE:1;                  // 2 Master DMA Write Access Violation Flag Clear 
    Uint16 rsvd1:13;                    // 15:3 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union MAVCLR_REG {
    Uint32  all;
    struct  MAVCLR_BITS  bit;
};

struct MAVINTEN_BITS {                  // bits description
    Uint16 CPUFETCH:1;                  // 0 Master CPU Fetch Access Violation Interrupt Enable 
    Uint16 CPUWRITE:1;                  // 1 Master CPU Write Access Violation Interrupt Enable 
    Uint16 DMAWRITE:1;                  // 2 Master DMA Write Access Violation Interrupt Enable 
    Uint16 rsvd1:13;                    // 15:3 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union MAVINTEN_REG {
    Uint32  all;
    struct  MAVINTEN_BITS  bit;
};

struct ACCESS_PROTECTION_REGS {
    union   NMAVFLG_REG                      NMAVFLG;                      // Non-Master Access Violation Flag Register
    union   NMAVSET_REG                      NMAVSET;                      // Non-Master Access Violation Flag Set Register
    union   NMAVCLR_REG                      NMAVCLR;                      // Non-Master Access Violation Flag Clear Register
    union   NMAVINTEN_REG                    NMAVINTEN;                    // Non-Master Access Violation Interrupt Enable Register
    Uint32                                   NMCPURDAVADDR;                // Non-Master CPU Read Access Violation Address
    Uint32                                   NMCPUWRAVADDR;                // Non-Master CPU Write Access Violation Address
    Uint32                                   NMCPUFAVADDR;                 // Non-Master CPU Fetch Access Violation Address
    Uint32                                   NMDMAWRAVADDR;                // Non-Master DMA Write Access Violation Address
    Uint32                                   NMCLA1RDAVADDR;               // Non-Master CLA1 Read Access Violation Address
    Uint32                                   NMCLA1WRAVADDR;               // Non-Master CLA1 Write Access Violation Address
    Uint32                                   NMCLA1FAVADDR;                // Non-Master CLA1 Fetch Access Violation Address
    Uint16                                   rsvd1[10];                    // Reserved
    union   MAVFLG_REG                       MAVFLG;                       // Master Access Violation Flag Register
    union   MAVSET_REG                       MAVSET;                       // Master Access Violation Flag Set Register
    union   MAVCLR_REG                       MAVCLR;                       // Master Access Violation Flag Clear Register
    union   MAVINTEN_REG                     MAVINTEN;                     // Master Access Violation Interrupt Enable Register
    Uint32                                   MCPUFAVADDR;                  // Master CPU Fetch Access Violation Address
    Uint32                                   MCPUWRAVADDR;                 // Master CPU Write Access Violation Address
    Uint32                                   MDMAWRAVADDR;                 // Master  DMA Write Access Violation Address
    Uint16                                   rsvd2[18];                    // Reserved
};

struct UCERRFLG_BITS {                  // bits description
    Uint16 CPURDERR:1;                  // 0 CPU Uncorrectable Read Error Flag 
    Uint16 DMARDERR:1;                  // 1 DMA Uncorrectable Read Error Flag 
    Uint16 CLA1RDERR:1;                 // 2 CLA1 Uncorrectable Read Error Flag 
    Uint16 rsvd1:1;                     // 3 Reserved
    Uint16 rsvd2:12;                    // 15:4 Reserved
    Uint16 rsvd3:16;                    // 31:16 Reserved
};

union UCERRFLG_REG {
    Uint32  all;
    struct  UCERRFLG_BITS  bit;
};

struct UCERRSET_BITS {                  // bits description
    Uint16 CPURDERR:1;                  // 0 CPU Uncorrectable Read Error Flag Set
    Uint16 DMARDERR:1;                  // 1 DMA Uncorrectable Read Error Flag Set
    Uint16 CLA1RDERR:1;                 // 2 CLA1 Uncorrectable Read Error Flag Set
    Uint16 rsvd1:1;                     // 3 Reserved
    Uint16 rsvd2:12;                    // 15:4 Reserved
    Uint16 rsvd3:16;                    // 31:16 Reserved
};

union UCERRSET_REG {
    Uint32  all;
    struct  UCERRSET_BITS  bit;
};

struct UCERRCLR_BITS {                  // bits description
    Uint16 CPURDERR:1;                  // 0 CPU Uncorrectable Read Error Flag Clear
    Uint16 DMARDERR:1;                  // 1 DMA Uncorrectable Read Error Flag Clear
    Uint16 CLA1RDERR:1;                 // 2 CLA1 Uncorrectable Read Error Flag Clear
    Uint16 rsvd1:1;                     // 3 Reserved
    Uint16 rsvd2:12;                    // 15:4 Reserved
    Uint16 rsvd3:16;                    // 31:16 Reserved
};

union UCERRCLR_REG {
    Uint32  all;
    struct  UCERRCLR_BITS  bit;
};

struct CERRFLG_BITS {                   // bits description
    Uint16 CPURDERR:1;                  // 0 CPU Correctable Read Error Flag 
    Uint16 DMARDERR:1;                  // 1 DMA Correctable Read Error Flag 
    Uint16 CLA1RDERR:1;                 // 2 CLA1 Correctable Read Error Flag 
    Uint16 rsvd1:1;                     // 3 Reserved
    Uint16 rsvd2:12;                    // 15:4 Reserved
    Uint16 rsvd3:16;                    // 31:16 Reserved
};

union CERRFLG_REG {
    Uint32  all;
    struct  CERRFLG_BITS  bit;
};

struct CERRSET_BITS {                   // bits description
    Uint16 CPURDERR:1;                  // 0 CPU Correctable Read Error Flag Set
    Uint16 DMARDERR:1;                  // 1 DMA Correctable Read Error Flag Set
    Uint16 CLA1RDERR:1;                 // 2 CLA1 Correctable Read Error Flag Set
    Uint16 rsvd1:1;                     // 3 Reserved
    Uint16 rsvd2:12;                    // 15:4 Reserved
    Uint16 rsvd3:16;                    // 31:16 Reserved
};

union CERRSET_REG {
    Uint32  all;
    struct  CERRSET_BITS  bit;
};

struct CERRCLR_BITS {                   // bits description
    Uint16 CPURDERR:1;                  // 0 CPU Correctable Read Error Flag Clear
    Uint16 DMARDERR:1;                  // 1 DMA Correctable Read Error Flag Clear
    Uint16 CLA1RDERR:1;                 // 2 CLA1 Correctable Read Error Flag Clear
    Uint16 rsvd1:1;                     // 3 Reserved
    Uint16 rsvd2:12;                    // 15:4 Reserved
    Uint16 rsvd3:16;                    // 31:16 Reserved
};

union CERRCLR_REG {
    Uint32  all;
    struct  CERRCLR_BITS  bit;
};

struct CEINTFLG_BITS {                  // bits description
    Uint16 CEINTFLAG:1;                 // 0 Total corrected error count exceeded threshold flag.
    Uint16 rsvd1:15;                    // 15:1 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union CEINTFLG_REG {
    Uint32  all;
    struct  CEINTFLG_BITS  bit;
};

struct CEINTCLR_BITS {                  // bits description
    Uint16 CEINTCLR:1;                  // 0 CPU Corrected Error Threshold Exceeded Error Clear.
    Uint16 rsvd1:15;                    // 15:1 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union CEINTCLR_REG {
    Uint32  all;
    struct  CEINTCLR_BITS  bit;
};

struct CEINTSET_BITS {                  // bits description
    Uint16 CEINTSET:1;                  // 0 Total corrected error count exceeded flag set.
    Uint16 rsvd1:15;                    // 15:1 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union CEINTSET_REG {
    Uint32  all;
    struct  CEINTSET_BITS  bit;
};

struct CEINTEN_BITS {                   // bits description
    Uint16 CEINTEN:1;                   // 0 CPU/DMA Correctable Error Interrupt Enable.
    Uint16 rsvd1:15;                    // 15:1 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union CEINTEN_REG {
    Uint32  all;
    struct  CEINTEN_BITS  bit;
};

struct MEMORY_ERROR_REGS {
    union   UCERRFLG_REG                     UCERRFLG;                     // Uncorrectable Error Flag Register
    union   UCERRSET_REG                     UCERRSET;                     // Uncorrectable Error Flag Set Register
    union   UCERRCLR_REG                     UCERRCLR;                     // Uncorrectable Error Flag Clear Register
    Uint32                                   UCCPUREADDR;                  // Uncorrectable CPU Read Error Address
    Uint32                                   UCDMAREADDR;                  // Uncorrectable DMA Read Error Address
    Uint32                                   UCCLA1READDR;                 // Uncorrectable CLA1 Read Error Address
    Uint16                                   rsvd1[20];                    // Reserved
    union   CERRFLG_REG                      CERRFLG;                      // Correctable Error Flag Register
    union   CERRSET_REG                      CERRSET;                      // Correctable Error Flag Set Register
    union   CERRCLR_REG                      CERRCLR;                      // Correctable Error Flag Clear Register
    Uint32                                   CCPUREADDR;                   // Correctable CPU Read Error Address
    Uint16                                   rsvd2[6];                     // Reserved
    Uint32                                   CERRCNT;                      // Correctable Error Count Register
    Uint32                                   CERRTHRES;                    // Correctable Error Threshold Value Register
    union   CEINTFLG_REG                     CEINTFLG;                     // Correctable Error Interrupt Flag Status Register
    union   CEINTCLR_REG                     CEINTCLR;                     // Correctable Error Interrupt Flag Clear Register
    union   CEINTSET_REG                     CEINTSET;                     // Correctable Error Interrupt Flag Set Register
    union   CEINTEN_REG                      CEINTEN;                      // Correctable Error Interrupt Enable Register
    Uint16                                   rsvd3[6];                     // Reserved
};

struct ROMWAITSTATE_BITS {              // bits description
    Uint16 WSDISABLE:1;                 // 0 ROM Wait State Enable/Disable Control
    Uint16 rsvd1:15;                    // 15:1 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union ROMWAITSTATE_REG {
    Uint32  all;
    struct  ROMWAITSTATE_BITS  bit;
};

struct ROM_WAIT_STATE_REGS {
    union   ROMWAITSTATE_REG                 ROMWAITSTATE;                 // ROM Wait State Configuration Register
};

struct ROMPREFETCH_BITS {               // bits description
    Uint16 PFENABLE:1;                  // 0 ROM Prefetch Enable/Disable Control
    Uint16 rsvd1:15;                    // 15:1 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union ROMPREFETCH_REG {
    Uint32  all;
    struct  ROMPREFETCH_BITS  bit;
};

struct ROM_PREFETCH_REGS {
    union   ROMPREFETCH_REG                  ROMPREFETCH;                  // ROM Prefetch Configuration Register
};

//---------------------------------------------------------------------------
// MEMCONFIG External References & Function Declarations:
//
extern volatile struct ROM_PREFETCH_REGS RomPrefetchRegs;
extern volatile struct MEM_CFG_REGS MemCfgRegs;
extern volatile struct EMIF1_CONFIG_REGS Emif1ConfigRegs;
extern volatile struct EMIF2_CONFIG_REGS Emif2ConfigRegs;
extern volatile struct ACCESS_PROTECTION_REGS AccessProtectionRegs;
extern volatile struct MEMORY_ERROR_REGS MemoryErrorRegs;
extern volatile struct ROM_WAIT_STATE_REGS RomWaitStateRegs;
#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================
