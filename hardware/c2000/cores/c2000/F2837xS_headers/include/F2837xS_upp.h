//###########################################################################
//
// FILE:    F2837xS_upp.h
//
// TITLE:   F2837xS Device UPP Register Definitions.
//
//###########################################################################
// $TI Release: F2837xS Support Library v170 $
// $Release Date: Mon Sep 21 16:56:07 CDT 2015 $
// $Copyright: Copyright (C) 2014-2015 Texas Instruments Incorporated -
//             http://www.ti.com/ ALL RIGHTS RESERVED $
//###########################################################################

#ifndef __F2837xS_UPP_H__
#define __F2837xS_UPP_H__

#ifdef __cplusplus 
extern "C" {
#endif 


//---------------------------------------------------------------------------
// UPP Individual Register Bit Definitions:

struct PERCTL_BITS {                    // bits description
    Uint16 FREE:1;                      // 0 Emulation control.
    Uint16 SOFT:1;                      // 1 Emulation control.
    Uint16 RTEMU:1;                     // 2 Realtime emulation control.
    Uint16 PEREN:1;                     // 3 Peripheral Enable
    Uint16 SOFTRST:1;                   // 4 Software Reset
    Uint16 rsvd1:2;                     // 6:5 Reserved
    Uint16 DMAST:1;                     // 7 DMA Burst transaction status
    Uint16 rsvd2:8;                     // 15:8 Reserved
    Uint16 rsvd3:16;                    // 31:16 Reserved
};

union PERCTL_REG {
    Uint32  all;
    struct  PERCTL_BITS  bit;
};

struct CHCTL_BITS {                     // bits description
    Uint16 MODE:2;                      // 1:0 Operating mode
    Uint16 rsvd1:1;                     // 2 Reserved
    Uint16 SDRTXILA:1;                  // 3 SDR TX Interleve mode
    Uint16 DEMUXA:1;                    // 4 DDR de-multiplexing mode
    Uint16 rsvd2:11;                    // 15:5 Reserved
    Uint16 DRA:1;                       // 16 Data rate
    Uint16 rsvd3:14;                    // 30:17 Reserved
    Uint16 rsvd4:1;                     // 31 Reserved
};

union CHCTL_REG {
    Uint32  all;
    struct  CHCTL_BITS  bit;
};

struct IFCFG_BITS {                     // bits description
    Uint16 STARTPOLA:1;                 // 0 Polarity of START(SELECT) signal
    Uint16 ENAPOLA:1;                   // 1 Polarity of ENABLE(WRITE) signal
    Uint16 WAITPOLA:1;                  // 2 Polarity of WAIT signal.
    Uint16 STARTA:1;                    // 3 Enable Usage of START (SELECT) signal
    Uint16 ENAA:1;                      // 4 Enable Usage of ENABLE (WRITE) signal
    Uint16 WAITA:1;                     // 5 Enable Usage of WAIT signal
    Uint16 rsvd1:2;                     // 7:6 Reserved
    Uint16 CLKDIVA:4;                   // 11:8 Clock divider for tx mode
    Uint16 CLKINVA:1;                   // 12 Clock inversion
    Uint16 TRISENA:1;                   // 13 Pin Tri-state Control
    Uint16 rsvd2:2;                     // 15:14 Reserved
    Uint16 rsvd3:6;                     // 21:16 Reserved
    Uint16 rsvd4:2;                     // 23:22 Reserved
    Uint16 rsvd5:6;                     // 29:24 Reserved
    Uint16 rsvd6:2;                     // 31:30 Reserved
};

union IFCFG_REG {
    Uint32  all;
    struct  IFCFG_BITS  bit;
};

struct IFIVAL_BITS {                    // bits description
    Uint16 VALA:9;                      // 8:0 Idle Value
    Uint16 rsvd1:7;                     // 15:9 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union IFIVAL_REG {
    Uint32  all;
    struct  IFIVAL_BITS  bit;
};

struct THCFG_BITS {                     // bits description
    Uint16 RDSIZEI:2;                   // 1:0 DMA Read Threshold for DMA Channel I
    Uint16 rsvd1:6;                     // 7:2 Reserved
    Uint16 RDSIZEQ:2;                   // 9:8 DMA Read Threshold for DMA Channel Q
    Uint16 rsvd2:6;                     // 15:10 Reserved
    Uint16 TXSIZEA:2;                   // 17:16 I/O Transmit Threshold Value
    Uint16 rsvd3:6;                     // 23:18 Reserved
    Uint16 rsvd4:2;                     // 25:24 Reserved
    Uint16 rsvd5:6;                     // 31:26 Reserved
};

union THCFG_REG {
    Uint32  all;
    struct  THCFG_BITS  bit;
};

struct RAWINTST_BITS {                  // bits description
    Uint16 DPEI:1;                      // 0 Interrupt raw status for DMA programming error
    Uint16 UOEI:1;                      // 1 Interrupt raw status for DMA under-run or over-run
    Uint16 rsvd1:1;                     // 2 Reserved
    Uint16 EOWI:1;                      // 3 Interrupt raw status for end-of window condition
    Uint16 EOLI:1;                      // 4 Interrupt raw status for end-of-line condition
    Uint16 rsvd2:3;                     // 7:5 Reserved
    Uint16 DPEQ:1;                      // 8 Interrupt raw status for DMA programming error
    Uint16 UOEQ:1;                      // 9 Interrupt raw status for DMA under-run or over-run
    Uint16 rsvd3:1;                     // 10 Reserved
    Uint16 EOWQ:1;                      // 11 Interrupt raw status for end-of window condition
    Uint16 EOLQ:1;                      // 12 Interrupt raw status for end-of-line condition
    Uint16 rsvd4:3;                     // 15:13 Reserved
    Uint16 rsvd5:16;                    // 31:16 Reserved
};

union RAWINTST_REG {
    Uint32  all;
    struct  RAWINTST_BITS  bit;
};

struct ENINTST_BITS {                   // bits description
    Uint16 DPEI:1;                      // 0 Interrupt enable status for DMA programming error
    Uint16 UOEI:1;                      // 1 Interrupt enable status for DMA under-run or over-run
    Uint16 rsvd1:1;                     // 2 Reserved
    Uint16 EOWI:1;                      // 3 Interrupt enable status for end-of window condition
    Uint16 EOLI:1;                      // 4 Interrupt enable status for end-of-line condition
    Uint16 rsvd2:3;                     // 7:5 Reserved
    Uint16 DPEQ:1;                      // 8 Interrupt enable status for DMA programming error
    Uint16 UOEQ:1;                      // 9 Interrupt enable status for DMA under-run or over-run
    Uint16 rsvd3:1;                     // 10 Reserved
    Uint16 EOWQ:1;                      // 11 Interrupt enable status for end-of window condition
    Uint16 EOLQ:1;                      // 12 Interrupt enable status for end-of-line condition
    Uint16 rsvd4:3;                     // 15:13 Reserved
    Uint16 rsvd5:16;                    // 31:16 Reserved
};

union ENINTST_REG {
    Uint32  all;
    struct  ENINTST_BITS  bit;
};

struct INTENSET_BITS {                  // bits description
    Uint16 DPEI:1;                      // 0 Interrupt enable for DMA programming error
    Uint16 UOEI:1;                      // 1 Interrupt enable for DMA under-run or over-run
    Uint16 rsvd1:1;                     // 2 Reserved
    Uint16 EOWI:1;                      // 3 Interrupt enable for end-of window condition
    Uint16 EOLI:1;                      // 4 Interrupt enable for end-of-line condition
    Uint16 rsvd2:3;                     // 7:5 Reserved
    Uint16 DPEQ:1;                      // 8 Interrupt enable for DMA programming error
    Uint16 UOEQ:1;                      // 9 Interrupt enable for DMA under-run or over-run
    Uint16 rsvd3:1;                     // 10 Reserved
    Uint16 EOWQ:1;                      // 11 Interrupt enable for end-of window condition
    Uint16 EOLQ:1;                      // 12 Interrupt enable for end-of-line condition
    Uint16 rsvd4:3;                     // 15:13 Reserved
    Uint16 rsvd5:16;                    // 31:16 Reserved
};

union INTENSET_REG {
    Uint32  all;
    struct  INTENSET_BITS  bit;
};

struct INTENCLR_BITS {                  // bits description
    Uint16 DPEI:1;                      // 0 Interrupt clear for DMA programming error
    Uint16 UOEI:1;                      // 1 Interrupt clear for DMA under-run or over-run
    Uint16 rsvd1:1;                     // 2 Reserved
    Uint16 EOWI:1;                      // 3 Interrupt clear for end-of window condition
    Uint16 EOLI:1;                      // 4 Interrupt clear for end-of-line condition
    Uint16 rsvd2:3;                     // 7:5 Reserved
    Uint16 DPEQ:1;                      // 8 Interrupt clear for DMA programming error
    Uint16 UOEQ:1;                      // 9 Interrupt clear for DMA under-run or over-run
    Uint16 rsvd3:1;                     // 10 Reserved
    Uint16 EOWQ:1;                      // 11 Interrupt clear for end-of window condition
    Uint16 EOLQ:1;                      // 12 Interrupt clear for end-of-line condition
    Uint16 rsvd4:3;                     // 15:13 Reserved
    Uint16 rsvd5:16;                    // 31:16 Reserved
};

union INTENCLR_REG {
    Uint32  all;
    struct  INTENCLR_BITS  bit;
};

struct CHIDESC1_BITS {                  // bits description
    Uint16 BCNT:16;                     // 15:0 Number of bytes in a line for DMA Channel I transfer.
    Uint16 LCNT:16;                     // 31:16 Number of lines in a window for DMA Channel I transfer.
};

union CHIDESC1_REG {
    Uint32  all;
    struct  CHIDESC1_BITS  bit;
};

struct CHIDESC2_BITS {                  // bits description
    Uint16 LOFFSET:16;                  // 15:0 Current start address to next start address offset.
    Uint16 rsvd1:16;                    // 31:16 Reserved
};

union CHIDESC2_REG {
    Uint32  all;
    struct  CHIDESC2_BITS  bit;
};

struct CHIST1_BITS {                    // bits description
    Uint16 BCNT:16;                     // 15:0 Current byte number.
    Uint16 LCNT:16;                     // 31:16 Current line number.
};

union CHIST1_REG {
    Uint32  all;
    struct  CHIST1_BITS  bit;
};

struct CHIST2_BITS {                    // bits description
    Uint16 ACT:1;                       // 0 Status of DMA descriptor.
    Uint16 PEND:1;                      // 1 Status of DMA.
    Uint16 rsvd1:2;                     // 3:2 Reserved
    Uint16 WM:4;                        // 7:4 Watermark for FIFO block count for DMA Channel I tranfer.
    Uint16 rsvd2:8;                     // 15:8 Reserved
    Uint16 rsvd3:16;                    // 31:16 Reserved
};

union CHIST2_REG {
    Uint32  all;
    struct  CHIST2_BITS  bit;
};

struct CHQDESC1_BITS {                  // bits description
    Uint16 BCNT:16;                     // 15:0 Number of bytes in a line for DMA Channel Q transfer.
    Uint16 LCNT:16;                     // 31:16 Number of lines in a window for DMA Channel Q transfer.
};

union CHQDESC1_REG {
    Uint32  all;
    struct  CHQDESC1_BITS  bit;
};

struct CHQDESC2_BITS {                  // bits description
    Uint16 LOFFSET:16;                  // 15:0 Current start address to next start address offset.
    Uint16 rsvd1:16;                    // 31:16 Reserved
};

union CHQDESC2_REG {
    Uint32  all;
    struct  CHQDESC2_BITS  bit;
};

struct CHQST1_BITS {                    // bits description
    Uint16 BCNT:16;                     // 15:0 Current byte number.
    Uint16 LCNT:16;                     // 31:16 Current line number.
};

union CHQST1_REG {
    Uint32  all;
    struct  CHQST1_BITS  bit;
};

struct CHQST2_BITS {                    // bits description
    Uint16 ACT:1;                       // 0 Status of DMA descriptor.
    Uint16 PEND:1;                      // 1 Status of DMA.
    Uint16 rsvd1:2;                     // 3:2 Reserved
    Uint16 WM:4;                        // 7:4 Watermark for FIFO block count for DMA Channel Q tranfer.
    Uint16 rsvd2:8;                     // 15:8 Reserved
    Uint16 rsvd3:16;                    // 31:16 Reserved
};

union CHQST2_REG {
    Uint32  all;
    struct  CHQST2_BITS  bit;
};

struct GINTEN_BITS {                    // bits description
    Uint16 GINTEN:1;                    // 0 Global Interrupt Enable
    Uint16 rsvd1:15;                    // 15:1 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union GINTEN_REG {
    Uint32  all;
    struct  GINTEN_BITS  bit;
};

struct GINTFLG_BITS {                   // bits description
    Uint16 GINTFLG:1;                   // 0 Global Interrupt Flag
    Uint16 rsvd1:15;                    // 15:1 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union GINTFLG_REG {
    Uint32  all;
    struct  GINTFLG_BITS  bit;
};

struct GINTCLR_BITS {                   // bits description
    Uint16 GINTCLR:1;                   // 0 Global Interrupt Clear
    Uint16 rsvd1:15;                    // 15:1 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union GINTCLR_REG {
    Uint32  all;
    struct  GINTCLR_BITS  bit;
};

struct DLYCTL_BITS {                    // bits description
    Uint16 DLYDIS:1;                    // 0 IO dealy control disable.
    Uint16 DLYCTL:2;                    // 2:1 IO delay control.
    Uint16 rsvd1:13;                    // 15:3 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union DLYCTL_REG {
    Uint32  all;
    struct  DLYCTL_BITS  bit;
};

struct UPP_REGS {
    Uint32                                   PID;                          // Peripheral ID Register
    union   PERCTL_REG                       PERCTL;                       // Peripheral Control Register
    Uint16                                   rsvd1[4];                     // Reserved
    union   CHCTL_REG                        CHCTL;                        // General Control Register
    union   IFCFG_REG                        IFCFG;                        // Interface Configuration Register
    union   IFIVAL_REG                       IFIVAL;                       // Interface Idle Value Register
    union   THCFG_REG                        THCFG;                        // Threshold Configuration Register
    union   RAWINTST_REG                     RAWINTST;                     // Raw Interrupt Status Register
    union   ENINTST_REG                      ENINTST;                      // Enable Interrupt Status Register
    union   INTENSET_REG                     INTENSET;                     // Interrupt Enable Set Register
    union   INTENCLR_REG                     INTENCLR;                     // Interrupt Enable Clear Register
    Uint16                                   rsvd2[8];                     // Reserved
    Uint32                                   CHIDESC0;                     // DMA Channel I Descriptor 0 Register
    union   CHIDESC1_REG                     CHIDESC1;                     // DMA Channel I Descriptor 1 Register
    union   CHIDESC2_REG                     CHIDESC2;                     // DMA Channel I Descriptor 2 Register
    Uint16                                   rsvd3[2];                     // Reserved
    Uint32                                   CHIST0;                       // DMA Channel I Status 0 Register
    union   CHIST1_REG                       CHIST1;                       // DMA Channel I Status 1 Register
    union   CHIST2_REG                       CHIST2;                       // DMA Channel I Status 2 Register
    Uint16                                   rsvd4[2];                     // Reserved
    Uint32                                   CHQDESC0;                     // DMA Channel Q Descriptor 0 Register
    union   CHQDESC1_REG                     CHQDESC1;                     // DMA Channel Q Descriptor 1 Register
    union   CHQDESC2_REG                     CHQDESC2;                     // DMA Channel Q Descriptor 2 Register
    Uint16                                   rsvd5[2];                     // Reserved
    Uint32                                   CHQST0;                       // DMA Channel Q Status 0 Register
    union   CHQST1_REG                       CHQST1;                       // DMA Channel Q Status 1 Register
    union   CHQST2_REG                       CHQST2;                       // DMA Channel Q Status 2 Register
    Uint16                                   rsvd6[2];                     // Reserved
    union   GINTEN_REG                       GINTEN;                       // Global Peripheral Interrupt Enable Register
    union   GINTFLG_REG                      GINTFLG;                      // Global Peripheral Interrupt Flag Register
    union   GINTCLR_REG                      GINTCLR;                      // Global Peripheral Interrupt Clear Register
    union   DLYCTL_REG                       DLYCTL;                       // IO clock data skew control Register
};

//---------------------------------------------------------------------------
// UPP External References & Function Declarations:
//
extern volatile struct UPP_REGS UppRegs;
#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================
