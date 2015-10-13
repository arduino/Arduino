//###########################################################################
//
// FILE:    F2837xS_flash.h
//
// TITLE:   F2837xS Device FLASH Register Definitions.
//
//###########################################################################
// $TI Release: F2837xS Support Library v170 $
// $Release Date: Mon Sep 21 16:56:07 CDT 2015 $
// $Copyright: Copyright (C) 2014-2015 Texas Instruments Incorporated -
//             http://www.ti.com/ ALL RIGHTS RESERVED $
//###########################################################################

#ifndef __F2837xS_FLASH_H__
#define __F2837xS_FLASH_H__

#ifdef __cplusplus 
extern "C" {
#endif 


//---------------------------------------------------------------------------
// FLASH Individual Register Bit Definitions:

struct FRDCNTL_BITS {                   // bits description
    Uint16 rsvd1:8;                     // 7:0 Reserved
    Uint16 RWAIT:4;                     // 11:8 Random Read Waitstate
    Uint16 rsvd2:4;                     // 15:12 Reserved
    Uint16 rsvd3:16;                    // 31:16 Reserved
};

union FRDCNTL_REG {
    Uint32  all;
    struct  FRDCNTL_BITS  bit;
};

struct FBAC_BITS {                      // bits description
    Uint16 VREADST:8;                   // 7:0 VREAD Setup Time Count
    Uint16 BAGP:8;                      // 15:8 Bank Active Grace Period
    Uint16 rsvd1:16;                    // 31:16 Reserved
};

union FBAC_REG {
    Uint32  all;
    struct  FBAC_BITS  bit;
};

struct FBFALLBACK_BITS {                // bits description
    Uint16 BNKPWR0:2;                   // 1:0 Bank Power Mode
    Uint16 rsvd1:14;                    // 15:2 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union FBFALLBACK_REG {
    Uint32  all;
    struct  FBFALLBACK_BITS  bit;
};

struct FBPRDY_BITS {                    // bits description
    Uint16 BANKRDY:1;                   // 0 Flash Bank Active Power State
    Uint16 rsvd1:14;                    // 14:1 Reserved
    Uint16 PUMPRDY:1;                   // 15 Flash Pump Active Power Mode
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union FBPRDY_REG {
    Uint32  all;
    struct  FBPRDY_BITS  bit;
};

struct FPAC1_BITS {                     // bits description
    Uint16 PMPPWR:1;                    // 0 Charge Pump Fallback Power Mode
    Uint16 rsvd1:15;                    // 15:1 Reserved
    Uint16 PSLEEP:12;                   // 27:16 Pump Sleep Down Count
    Uint16 rsvd2:4;                     // 31:28 Reserved
};

union FPAC1_REG {
    Uint32  all;
    struct  FPAC1_BITS  bit;
};

struct FPAC2_BITS {                     // bits description
    Uint16 PAGP:16;                     // 15:0 Pump Active Grace Period
    Uint16 rsvd1:16;                    // 31:16 Reserved
};

union FPAC2_REG {
    Uint32  all;
    struct  FPAC2_BITS  bit;
};

struct FMAC_BITS {                      // bits description
    Uint16 BANK:3;                      // 2:0 Flash Bank for FSM and Software Interface Operations
    Uint16 rsvd1:13;                    // 15:3 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union FMAC_REG {
    Uint32  all;
    struct  FMAC_BITS  bit;
};

struct FMSTAT_BITS {                    // bits description
    Uint16 rsvd1:1;                     // 0 Reserved
    Uint16 rsvd2:1;                     // 1 Reserved
    Uint16 rsvd3:1;                     // 2 Reserved
    Uint16 VOLTSTAT:1;                  // 3 Flash Pump Power Status
    Uint16 CSTAT:1;                     // 4 Command Fail Status
    Uint16 INVDAT:1;                    // 5 Invalid Data
    Uint16 PGM:1;                       // 6 Program Operation Status
    Uint16 ERS:1;                       // 7 Erase Operation Status
    Uint16 BUSY:1;                      // 8 Busy Bit
    Uint16 rsvd4:1;                     // 9 Reserved
    Uint16 EV:1;                        // 10 Erase Verify Status
    Uint16 rsvd5:1;                     // 11 Reserved
    Uint16 PGV:1;                       // 12 Programming Verify Status
    Uint16 rsvd6:1;                     // 13 Reserved
    Uint16 ILA:1;                       // 14 Illegal Address Detected
    Uint16 rsvd7:1;                     // 15 Reserved
    Uint16 rsvd8:1;                     // 16 Reserved
    Uint16 rsvd9:1;                     // 17 Reserved
    Uint16 rsvd10:14;                   // 31:18 Reserved
};

union FMSTAT_REG {
    Uint32  all;
    struct  FMSTAT_BITS  bit;
};

struct FRD_INTF_CTRL_BITS {             // bits description
    Uint16 PREFETCH_EN:1;               // 0 Prefetch Enable
    Uint16 DATA_CACHE_EN:1;             // 1 Data Cache Enable
    Uint16 rsvd1:14;                    // 15:2 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union FRD_INTF_CTRL_REG {
    Uint32  all;
    struct  FRD_INTF_CTRL_BITS  bit;
};

struct FLASH_CTRL_REGS {
    union   FRDCNTL_REG                      FRDCNTL;                      // Flash Read Control Register
    Uint16                                   rsvd1[28];                    // Reserved
    union   FBAC_REG                         FBAC;                         // Flash Bank Access Control Register
    union   FBFALLBACK_REG                   FBFALLBACK;                   // Flash Bank Fallback Power Register
    union   FBPRDY_REG                       FBPRDY;                       // Flash Bank Pump Ready Register
    union   FPAC1_REG                        FPAC1;                        // Flash Pump Access Control Register 1
    union   FPAC2_REG                        FPAC2;                        // Flash Pump Access Control Register 2
    union   FMAC_REG                         FMAC;                         // Flash Module Access Control Register
    union   FMSTAT_REG                       FMSTAT;                       // Flash Module Status Register
    Uint16                                   rsvd2[340];                   // Reserved
    union   FRD_INTF_CTRL_REG                FRD_INTF_CTRL;                // Flash Read Interface Control Register
};

struct ECC_ENABLE_BITS {                // bits description
    Uint16 ENABLE:4;                    // 3:0 Enable ECC
    Uint16 rsvd1:12;                    // 15:4 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union ECC_ENABLE_REG {
    Uint32  all;
    struct  ECC_ENABLE_BITS  bit;
};

struct ERR_STATUS_BITS {                // bits description
    Uint16 FAIL_0_L:1;                  // 0 Lower 64bits Single Bit Error Corrected Value 0
    Uint16 FAIL_1_L:1;                  // 1 Lower 64bits Single Bit Error Corrected Value 1
    Uint16 UNC_ERR_L:1;                 // 2 Lower 64 bits Uncorrectable error occurred
    Uint16 rsvd1:13;                    // 15:3 Reserved
    Uint16 FAIL_0_H:1;                  // 16 Upper 64bits Single Bit Error Corrected Value 0
    Uint16 FAIL_1_H:1;                  // 17 Upper 64bits Single Bit Error Corrected Value 1
    Uint16 UNC_ERR_H:1;                 // 18 Upper 64 bits Uncorrectable error occurred
    Uint16 rsvd2:13;                    // 31:19 Reserved
};

union ERR_STATUS_REG {
    Uint32  all;
    struct  ERR_STATUS_BITS  bit;
};

struct ERR_POS_BITS {                   // bits description
    Uint16 ERR_POS_L:6;                 // 5:0 Bit Position of Single bit Error in lower 64 bits
    Uint16 rsvd1:2;                     // 7:6 Reserved
    Uint16 ERR_TYPE_L:1;                // 8 Error Type in lower 64 bits
    Uint16 rsvd2:7;                     // 15:9 Reserved
    Uint16 ERR_POS_H:6;                 // 21:16 Bit Position of Single bit Error in upper 64 bits
    Uint16 rsvd3:2;                     // 23:22 Reserved
    Uint16 ERR_TYPE_H:1;                // 24 Error Type in upper 64 bits
    Uint16 rsvd4:7;                     // 31:25 Reserved
};

union ERR_POS_REG {
    Uint32  all;
    struct  ERR_POS_BITS  bit;
};

struct ERR_STATUS_CLR_BITS {            // bits description
    Uint16 FAIL_0_L_CLR:1;              // 0 Lower 64bits Single Bit Error Corrected Value 0 Clear
    Uint16 FAIL_1_L_CLR:1;              // 1 Lower 64bits Single Bit Error Corrected Value 1 Clear
    Uint16 UNC_ERR_L_CLR:1;             // 2 Lower 64 bits Uncorrectable error occurred Clear
    Uint16 rsvd1:13;                    // 15:3 Reserved
    Uint16 FAIL_0_H_CLR:1;              // 16 Upper 64bits Single Bit Error Corrected Value 0 Clear
    Uint16 FAIL_1_H_CLR:1;              // 17 Upper 64bits Single Bit Error Corrected Value 1 Clear
    Uint16 UNC_ERR_H_CLR:1;             // 18 Upper 64 bits Uncorrectable error occurred Clear
    Uint16 rsvd2:13;                    // 31:19 Reserved
};

union ERR_STATUS_CLR_REG {
    Uint32  all;
    struct  ERR_STATUS_CLR_BITS  bit;
};

struct ERR_CNT_BITS {                   // bits description
    Uint16 ERR_CNT:16;                  // 15:0 Error counter
    Uint16 rsvd1:16;                    // 31:16 Reserved
};

union ERR_CNT_REG {
    Uint32  all;
    struct  ERR_CNT_BITS  bit;
};

struct ERR_THRESHOLD_BITS {             // bits description
    Uint16 ERR_THRESHOLD:16;            // 15:0 Error Threshold
    Uint16 rsvd1:16;                    // 31:16 Reserved
};

union ERR_THRESHOLD_REG {
    Uint32  all;
    struct  ERR_THRESHOLD_BITS  bit;
};

struct ERR_INTFLG_BITS {                // bits description
    Uint16 SINGLE_ERR_INTFLG:1;         // 0 Single Error Interrupt Flag
    Uint16 UNC_ERR_INTFLG:1;            // 1 Uncorrectable Interrupt Flag
    Uint16 rsvd1:14;                    // 15:2 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union ERR_INTFLG_REG {
    Uint32  all;
    struct  ERR_INTFLG_BITS  bit;
};

struct ERR_INTCLR_BITS {                // bits description
    Uint16 SINGLE_ERR_INTCLR:1;         // 0 Single Error Interrupt Flag Clear
    Uint16 UNC_ERR_INTCLR:1;            // 1 Uncorrectable Interrupt Flag Clear
    Uint16 rsvd1:14;                    // 15:2 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union ERR_INTCLR_REG {
    Uint32  all;
    struct  ERR_INTCLR_BITS  bit;
};

struct FADDR_TEST_BITS {                // bits description
    Uint16 rsvd1:3;                     // 2:0 Reserved
    Uint16 ADDRL:13;                    // 15:3 ECC Address Low
    Uint16 ADDRH:6;                     // 21:16 ECC Address High
    Uint16 rsvd2:10;                    // 31:22 Reserved
};

union FADDR_TEST_REG {
    Uint32  all;
    struct  FADDR_TEST_BITS  bit;
};

struct FECC_TEST_BITS {                 // bits description
    Uint16 ECC:8;                       // 7:0 ECC Control Bits
    Uint16 rsvd1:8;                     // 15:8 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union FECC_TEST_REG {
    Uint32  all;
    struct  FECC_TEST_BITS  bit;
};

struct FECC_CTRL_BITS {                 // bits description
    Uint16 ECC_TEST_EN:1;               // 0 Enable ECC Test Logic
    Uint16 ECC_SELECT:1;                // 1 ECC Bit Select
    Uint16 DO_ECC_CALC:1;               // 2 Enable ECC Calculation
    Uint16 rsvd1:13;                    // 15:3 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union FECC_CTRL_REG {
    Uint32  all;
    struct  FECC_CTRL_BITS  bit;
};

struct FECC_STATUS_BITS {               // bits description
    Uint16 SINGLE_ERR:1;                // 0 Test Result is Single Bit Error
    Uint16 UNC_ERR:1;                   // 1 Test Result is Uncorrectable Error
    Uint16 DATA_ERR_POS:6;              // 7:2 Holds Bit Position of Error
    Uint16 ERR_TYPE:1;                  // 8 Holds Bit Position of 8 Check Bits of Error
    Uint16 rsvd1:7;                     // 15:9 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union FECC_STATUS_REG {
    Uint32  all;
    struct  FECC_STATUS_BITS  bit;
};

struct FLASH_ECC_REGS {
    union   ECC_ENABLE_REG                   ECC_ENABLE;                   // ECC Enable
    Uint32                                   SINGLE_ERR_ADDR_LOW;          // Single Error Address Low
    Uint32                                   SINGLE_ERR_ADDR_HIGH;         // Single Error Address High
    Uint32                                   UNC_ERR_ADDR_LOW;             // Uncorrectable Error Address Low
    Uint32                                   UNC_ERR_ADDR_HIGH;            // Uncorrectable Error Address High
    union   ERR_STATUS_REG                   ERR_STATUS;                   // Error Status
    union   ERR_POS_REG                      ERR_POS;                      // Error Position
    union   ERR_STATUS_CLR_REG               ERR_STATUS_CLR;               // Error Status Clear
    union   ERR_CNT_REG                      ERR_CNT;                      // Error Control
    union   ERR_THRESHOLD_REG                ERR_THRESHOLD;                // Error Threshold
    union   ERR_INTFLG_REG                   ERR_INTFLG;                   // Error Interrupt Flag
    union   ERR_INTCLR_REG                   ERR_INTCLR;                   // Error Interrupt Flag Clear
    Uint32                                   FDATAH_TEST;                  // Data High Test
    Uint32                                   FDATAL_TEST;                  // Data Low Test
    union   FADDR_TEST_REG                   FADDR_TEST;                   // ECC Test Address
    union   FECC_TEST_REG                    FECC_TEST;                    // ECC Test Address
    union   FECC_CTRL_REG                    FECC_CTRL;                    // ECC Control
    Uint32                                   FOUTH_TEST;                   // Test Data Out High
    Uint32                                   FOUTL_TEST;                   // Test Data Out Low
    union   FECC_STATUS_REG                  FECC_STATUS;                  // ECC Status
};

struct PUMPREQUEST_BITS {               // bits description
    Uint16 PUMP_OWNERSHIP:2;            // 1:0 Flash Pump Request Semaphore between CPU1 and CPU2
    Uint16 rsvd1:14;                    // 15:2 Reserved
    Uint16 KEY:16;                      // 31:16 Key Qualifier for writes to this register
};

union PUMPREQUEST_REG {
    Uint32  all;
    struct  PUMPREQUEST_BITS  bit;
};

struct FLASH_PUMP_SEMAPHORE_REGS {
    union   PUMPREQUEST_REG                  PUMPREQUEST;                  // Flash programming semaphore PUMP request register
};

//---------------------------------------------------------------------------
// FLASH External References & Function Declarations:
//
extern volatile struct FLASH_PUMP_SEMAPHORE_REGS FlashPumpSemaphoreRegs;
extern volatile struct FLASH_CTRL_REGS Flash0CtrlRegs;
extern volatile struct FLASH_ECC_REGS Flash0EccRegs;
extern volatile struct FLASH_CTRL_REGS Flash1CtrlRegs;
extern volatile struct FLASH_ECC_REGS Flash1EccRegs;
#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================
