//###########################################################################
//
// FILE:    F2837xS_mcbsp.h
//
// TITLE:   F2837xS Device MCBSP Register Definitions.
//
//###########################################################################
// $TI Release: F2837xS Support Library v170 $
// $Release Date: Mon Sep 21 16:56:07 CDT 2015 $
// $Copyright: Copyright (C) 2014-2015 Texas Instruments Incorporated -
//             http://www.ti.com/ ALL RIGHTS RESERVED $
//###########################################################################

#ifndef __F2837xS_MCBSP_H__
#define __F2837xS_MCBSP_H__

#ifdef __cplusplus 
extern "C" {
#endif 


//---------------------------------------------------------------------------
// MCBSP Individual Register Bit Definitions:

struct DRR2_BITS {                      // bits description
    Uint16 HWLB:8;                      // 7:0 High word low byte
    Uint16 HWHB:8;                      // 15:8 High word high byte
};

union DRR2_REG {
    Uint16  all;
    struct  DRR2_BITS  bit;
};

struct DRR1_BITS {                      // bits description
    Uint16 LWLB:8;                      // 7:0 Low word low byte
    Uint16 LWHB:8;                      // 15:8 Low word high byte
};

union DRR1_REG {
    Uint16  all;
    struct  DRR1_BITS  bit;
};

struct DXR2_BITS {                      // bits description
    Uint16 HWLB:8;                      // 7:0 High word low byte
    Uint16 HWHB:8;                      // 15:8 High word high byte
};

union DXR2_REG {
    Uint16  all;
    struct  DXR2_BITS  bit;
};

struct DXR1_BITS {                      // bits description
    Uint16 LWLB:8;                      // 7:0 Low word low byte
    Uint16 LWHB:8;                      // 15:8 Low word high byte
};

union DXR1_REG {
    Uint16  all;
    struct  DXR1_BITS  bit;
};

struct SPCR2_BITS {                     // bits description
    Uint16 XRST:1;                      // 0 Transmitter reset
    Uint16 XRDY:1;                      // 1 Transmitter ready
    Uint16 XEMPTY:1;                    // 2 Transmitter empty
    Uint16 XSYNCERR:1;                  // 3 Transmit sync error INT flag
    Uint16 XINTM:2;                     // 5:4 Transmit Interupt mode bits
    Uint16 GRST:1;                      // 6 Sample rate generator reset
    Uint16 FRST:1;                      // 7 Frame sync logic reset
    Uint16 SOFT:1;                      // 8 SOFT bit
    Uint16 FREE:1;                      // 9 FREE bit
    Uint16 rsvd1:6;                     // 15:10 Reserved
};

union SPCR2_REG {
    Uint16  all;
    struct  SPCR2_BITS  bit;
};

struct SPCR1_BITS {                     // bits description
    Uint16 RRST:1;                      // 0 Receiver reset
    Uint16 RRDY:1;                      // 1 Receiver ready
    Uint16 RFULL:1;                     // 2 Receiver full
    Uint16 RSYNCERR:1;                  // 3 Receive sync error INT flag
    Uint16 RINTM:2;                     // 5:4 Receive Interupt mode bits
    Uint16 rsvd1:1;                     // 6 Reserved
    Uint16 DXENA:1;                     // 7 DX delay enable
    Uint16 rsvd2:3;                     // 10:8 Reserved
    Uint16 CLKSTP:2;                    // 12:11 Clock stop mode
    Uint16 RJUST:2;                     // 14:13 Rx sign extension and justification mode
    Uint16 DLB:1;                       // 15 Digital loopback
};

union SPCR1_REG {
    Uint16  all;
    struct  SPCR1_BITS  bit;
};

struct RCR2_BITS {                      // bits description
    Uint16 RDATDLY:2;                   // 1:0 Receive data delay
    Uint16 RFIG:1;                      // 2 Receive frame sync ignore
    Uint16 RCOMPAND:2;                  // 4:3 Receive Companding Mode selects
    Uint16 RWDLEN2:3;                   // 7:5 Receive word length 2
    Uint16 RFRLEN2:7;                   // 14:8 Receive Frame length 2
    Uint16 RPHASE:1;                    // 15 Receive Phase
};

union RCR2_REG {
    Uint16  all;
    struct  RCR2_BITS  bit;
};

struct RCR1_BITS {                      // bits description
    Uint16 rsvd1:5;                     // 4:0 Reserved
    Uint16 RWDLEN1:3;                   // 7:5 Receive word length 1
    Uint16 RFRLEN1:7;                   // 14:8 Receive Frame length 1
    Uint16 rsvd2:1;                     // 15 Reserved
};

union RCR1_REG {
    Uint16  all;
    struct  RCR1_BITS  bit;
};

struct XCR2_BITS {                      // bits description
    Uint16 XDATDLY:2;                   // 1:0 Transmit data delay
    Uint16 XFIG:1;                      // 2 Transmit frame sync ignore
    Uint16 XCOMPAND:2;                  // 4:3 Transmit Companding Mode selects
    Uint16 XWDLEN2:3;                   // 7:5 Transmit word length 2
    Uint16 XFRLEN2:7;                   // 14:8 Transmit Frame length 2
    Uint16 XPHASE:1;                    // 15 Transmit Phase
};

union XCR2_REG {
    Uint16  all;
    struct  XCR2_BITS  bit;
};

struct XCR1_BITS {                      // bits description
    Uint16 rsvd1:5;                     // 4:0 Reserved
    Uint16 XWDLEN1:3;                   // 7:5 Transmit word length 1
    Uint16 XFRLEN1:7;                   // 14:8 Transmit Frame length 1
    Uint16 rsvd2:1;                     // 15 Reserved
};

union XCR1_REG {
    Uint16  all;
    struct  XCR1_BITS  bit;
};

struct SRGR2_BITS {                     // bits description
    Uint16 FPER:12;                     // 11:0 Frame-sync period
    Uint16 FSGM:1;                      // 12 Frame sync generator mode
    Uint16 CLKSM:1;                     // 13 Sample rate generator mode
    Uint16 rsvd1:1;                     // 14 Reserved
    Uint16 GSYNC:1;                     // 15 CLKG sync
};

union SRGR2_REG {
    Uint16  all;
    struct  SRGR2_BITS  bit;
};

struct SRGR1_BITS {                     // bits description
    Uint16 CLKGDV:8;                    // 7:0 CLKG divider
    Uint16 FWID:8;                      // 15:8 Frame width
};

union SRGR1_REG {
    Uint16  all;
    struct  SRGR1_BITS  bit;
};

struct MCR2_BITS {                      // bits description
    Uint16 XMCM:2;                      // 1:0 Transmit data delay
    Uint16 XCBLK:3;                     // 4:2 Transmit frame sync ignore
    Uint16 XPABLK:2;                    // 6:5 Transmit Companding Mode selects
    Uint16 XPBBLK:2;                    // 8:7 Transmit word length 2
    Uint16 XMCME:1;                     // 9 Transmit Frame length 2
    Uint16 rsvd1:6;                     // 15:10 Reserved
};

union MCR2_REG {
    Uint16  all;
    struct  MCR2_BITS  bit;
};

struct MCR1_BITS {                      // bits description
    Uint16 RMCM:1;                      // 0 Receive multichannel mode
    Uint16 rsvd1:1;                     // 1 Reserved
    Uint16 RCBLK:3;                     // 4:2 eceive current block
    Uint16 RPABLK:2;                    // 6:5 Receive partition A Block
    Uint16 RPBBLK:2;                    // 8:7 Receive partition B Block
    Uint16 RMCME:1;                     // 9 Receive multi-channel enhance mode
    Uint16 rsvd2:6;                     // 15:10 Reserved
};

union MCR1_REG {
    Uint16  all;
    struct  MCR1_BITS  bit;
};

struct PCR_BITS {                       // bits description
    Uint16 CLKRP:1;                     // 0 Receive Clock polarity
    Uint16 CLKXP:1;                     // 1 Transmit clock polarity
    Uint16 FSRP:1;                      // 2 Receive Frame synchronization polarity
    Uint16 FSXP:1;                      // 3 Transmit Frame synchronization polarity
    Uint16 rsvd1:1;                     // 4 Reserved
    Uint16 rsvd2:1;                     // 5 Reserved
    Uint16 rsvd3:1;                     // 6 Reserved
    Uint16 SCLKME:1;                    // 7 Sample clock mode selection
    Uint16 CLKRM:1;                     // 8 Receiver Clock Mode
    Uint16 CLKXM:1;                     // 9 Transmit Clock Mode.
    Uint16 FSRM:1;                      // 10 Receive Frame Synchronization Mode
    Uint16 FSXM:1;                      // 11 Transmit Frame Synchronization Mode
    Uint16 rsvd4:4;                     // 15:12 Reserved
};

union PCR_REG {
    Uint16  all;
    struct  PCR_BITS  bit;
};

struct MFFINT_BITS {                    // bits description
    Uint16 XINT:1;                      // 0 Enable for Receive Interrupt
    Uint16 rsvd1:1;                     // 1 Reserved
    Uint16 RINT:1;                      // 2 Enable for transmit Interrupt
    Uint16 rsvd2:13;                    // 15:3 Reserved
};

union MFFINT_REG {
    Uint16  all;
    struct  MFFINT_BITS  bit;
};

struct McBSP_REGS {
    union   DRR2_REG                         DRR2;                         // Data receive register bits 31-16
    union   DRR1_REG                         DRR1;                         // Data receive register bits 15-0
    union   DXR2_REG                         DXR2;                         // Data transmit register bits 31-16
    union   DXR1_REG                         DXR1;                         // Data transmit register bits 15-0
    union   SPCR2_REG                        SPCR2;                        // Control register 2
    union   SPCR1_REG                        SPCR1;                        // Control register 1
    union   RCR2_REG                         RCR2;                         // Receive Control register 2
    union   RCR1_REG                         RCR1;                         // Receive Control register 1
    union   XCR2_REG                         XCR2;                         // Transmit Control register 2
    union   XCR1_REG                         XCR1;                         // Transmit Control register 1
    union   SRGR2_REG                        SRGR2;                        // Sample rate generator register 2
    union   SRGR1_REG                        SRGR1;                        // Sample rate generator register 1
    union   MCR2_REG                         MCR2;                         // Multi-channel register 2
    union   MCR1_REG                         MCR1;                         // Multi-channel register 1
    Uint16                                   RCERA;                        // Receive channel enable partition A
    Uint16                                   RCERB;                        // Receive channel enable partition B
    Uint16                                   XCERA;                        // Transmit channel enable partition A
    Uint16                                   XCERB;                        // Transmit channel enable partition B
    union   PCR_REG                          PCR;                          // Pin Control register
    Uint16                                   RCERC;                        // Receive channel enable partition C
    Uint16                                   RCERD;                        // Receive channel enable partition D
    Uint16                                   XCERC;                        // Transmit channel enable partition C
    Uint16                                   XCERD;                        // Transmit channel enable partition D
    Uint16                                   RCERE;                        // Receive channel enable partition E
    Uint16                                   RCERF;                        // Receive channel enable partition F
    Uint16                                   XCERE;                        // Transmit channel enable partition E
    Uint16                                   XCERF;                        // Transmit channel enable partition F
    Uint16                                   RCERG;                        // Receive channel enable partition G
    Uint16                                   RCERH;                        // Receive channel enable partition H
    Uint16                                   XCERG;                        // Transmit channel enable partition G
    Uint16                                   XCERH;                        // Transmit channel enable partition H
    Uint16                                   rsvd1[4];                     // Reserved
    union   MFFINT_REG                       MFFINT;                       // Interrupt enable
};

//---------------------------------------------------------------------------
// MCBSP External References & Function Declarations:
//
extern volatile struct McBSP_REGS McbspaRegs;
extern volatile struct McBSP_REGS McbspbRegs;
#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================
