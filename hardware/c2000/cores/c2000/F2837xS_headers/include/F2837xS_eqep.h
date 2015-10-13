//###########################################################################
//
// FILE:    F2837xS_eqep.h
//
// TITLE:   F2837xS Device EQEP Register Definitions.
//
//###########################################################################
// $TI Release: F2837xS Support Library v170 $
// $Release Date: Mon Sep 21 16:56:07 CDT 2015 $
// $Copyright: Copyright (C) 2014-2015 Texas Instruments Incorporated -
//             http://www.ti.com/ ALL RIGHTS RESERVED $
//###########################################################################

#ifndef __F2837xS_EQEP_H__
#define __F2837xS_EQEP_H__

#ifdef __cplusplus 
extern "C" {
#endif 


//---------------------------------------------------------------------------
// EQEP Individual Register Bit Definitions:

struct QDECCTL_BITS {                   // bits description
    Uint16 rsvd1:5;                     // 4:0 Reserved
    Uint16 QSP:1;                       // 5 QEPS input polarity
    Uint16 QIP:1;                       // 6 QEPI input polarity
    Uint16 QBP:1;                       // 7 QEPB input polarity
    Uint16 QAP:1;                       // 8 QEPA input polarity
    Uint16 IGATE:1;                     // 9 Index pulse gating option
    Uint16 SWAP:1;                      // 10 CLK/DIR Signal Source for Position Counter 
    Uint16 XCR:1;                       // 11 External Clock Rate
    Uint16 SPSEL:1;                     // 12 Sync output pin selection
    Uint16 SOEN:1;                      // 13 Sync output-enable
    Uint16 QSRC:2;                      // 15:14 Position-counter source selection
};

union QDECCTL_REG {
    Uint16  all;
    struct  QDECCTL_BITS  bit;
};

struct QEPCTL_BITS {                    // bits description
    Uint16 WDE:1;                       // 0 QEP watchdog enable 
    Uint16 UTE:1;                       // 1 QEP unit timer enable
    Uint16 QCLM:1;                      // 2 QEP capture latch mode 
    Uint16 QPEN:1;                      // 3 Quadrature postotion counter enable 
    Uint16 IEL:2;                       // 5:4 Index event latch 
    Uint16 SEL:1;                       // 6 Strobe event latch 
    Uint16 SWI:1;                       // 7 Software init position counter
    Uint16 IEI:2;                       // 9:8 Index event init of position count 
    Uint16 SEI:2;                       // 11:10 Strobe event init 
    Uint16 PCRM:2;                      // 13:12 Postion counter reset 
    Uint16 FREE_SOFT:2;                 // 15:14 Emulation mode 
};

union QEPCTL_REG {
    Uint16  all;
    struct  QEPCTL_BITS  bit;
};

struct QCAPCTL_BITS {                   // bits description
    Uint16 UPPS:4;                      // 3:0 Unit position event prescaler
    Uint16 CCPS:3;                      // 6:4 eQEP capture timer clock prescaler
    Uint16 rsvd1:8;                     // 14:7 Reserved
    Uint16 CEN:1;                       // 15 Enable eQEP capture
};

union QCAPCTL_REG {
    Uint16  all;
    struct  QCAPCTL_BITS  bit;
};

struct QPOSCTL_BITS {                   // bits description
    Uint16 PCSPW:12;                    // 11:0 Position compare sync pulse width 
    Uint16 PCE:1;                       // 12 Position compare enable/disable 
    Uint16 PCPOL:1;                     // 13 Polarity of sync output 
    Uint16 PCLOAD:1;                    // 14 Position compare of shadow load 
    Uint16 PCSHDW:1;                    // 15 Position compare of shadow enable
};

union QPOSCTL_REG {
    Uint16  all;
    struct  QPOSCTL_BITS  bit;
};

struct QEINT_BITS {                     // bits description
    Uint16 rsvd1:1;                     // 0 Reserved
    Uint16 PCE:1;                       // 1 Position counter error interrupt enable
    Uint16 QPE:1;                       // 2 Quadrature phase error interrupt enable
    Uint16 QDC:1;                       // 3 Quadrature direction change interrupt enable
    Uint16 WTO:1;                       // 4 Watchdog time out interrupt enable
    Uint16 PCU:1;                       // 5 Position counter underflow interrupt enable
    Uint16 PCO:1;                       // 6 Position counter overflow interrupt enable
    Uint16 PCR:1;                       // 7 Position-compare ready interrupt enable
    Uint16 PCM:1;                       // 8 Position-compare match interrupt enable
    Uint16 SEL:1;                       // 9 Strobe event latch interrupt enable
    Uint16 IEL:1;                       // 10 Index event latch interrupt enable
    Uint16 UTO:1;                       // 11 Unit time out interrupt enable
    Uint16 rsvd2:4;                     // 15:12 Reserved
};

union QEINT_REG {
    Uint16  all;
    struct  QEINT_BITS  bit;
};

struct QFLG_BITS {                      // bits description
    Uint16 INT:1;                       // 0 Global interrupt status flag
    Uint16 PCE:1;                       // 1 Position counter error interrupt flag
    Uint16 PHE:1;                       // 2 Quadrature phase error interrupt flag
    Uint16 QDC:1;                       // 3 Quadrature direction change interrupt flag
    Uint16 WTO:1;                       // 4 Watchdog timeout interrupt flag
    Uint16 PCU:1;                       // 5 Position counter underflow interrupt flag
    Uint16 PCO:1;                       // 6 Position counter overflow interrupt flag
    Uint16 PCR:1;                       // 7 Position-compare ready interrupt flag
    Uint16 PCM:1;                       // 8 eQEP compare match event interrupt flag
    Uint16 SEL:1;                       // 9 Strobe event latch interrupt flag
    Uint16 IEL:1;                       // 10 Index event latch interrupt flag
    Uint16 UTO:1;                       // 11 Unit time out interrupt flag
    Uint16 rsvd1:4;                     // 15:12 Reserved
};

union QFLG_REG {
    Uint16  all;
    struct  QFLG_BITS  bit;
};

struct QCLR_BITS {                      // bits description
    Uint16 INT:1;                       // 0 Global interrupt clear flag
    Uint16 PCE:1;                       // 1 Clear position counter error interrupt flag
    Uint16 PHE:1;                       // 2 Clear quadrature phase error interrupt flag
    Uint16 QDC:1;                       // 3 Clear quadrature direction change interrupt flag
    Uint16 WTO:1;                       // 4 Clear watchdog timeout interrupt flag
    Uint16 PCU:1;                       // 5 Clear position counter underflow interrupt flag
    Uint16 PCO:1;                       // 6 Clear position counter overflow interrupt flag
    Uint16 PCR:1;                       // 7 Clear position-compare ready interrupt flag
    Uint16 PCM:1;                       // 8 Clear eQEP compare match event interrupt flag
    Uint16 SEL:1;                       // 9 Clear strobe event latch interrupt flag
    Uint16 IEL:1;                       // 10 Clear index event latch interrupt flag
    Uint16 UTO:1;                       // 11 Clear unit time out interrupt flag
    Uint16 rsvd1:4;                     // 15:12 Reserved
};

union QCLR_REG {
    Uint16  all;
    struct  QCLR_BITS  bit;
};

struct QFRC_BITS {                      // bits description
    Uint16 rsvd1:1;                     // 0 Reserved
    Uint16 PCE:1;                       // 1 Force position counter error interrupt
    Uint16 PHE:1;                       // 2 Force quadrature phase error interrupt
    Uint16 QDC:1;                       // 3 Force quadrature direction change interrupt
    Uint16 WTO:1;                       // 4 Force watchdog time out interrupt
    Uint16 PCU:1;                       // 5 Force position counter underflow interrupt
    Uint16 PCO:1;                       // 6 Force position counter overflow interrupt
    Uint16 PCR:1;                       // 7 Force position-compare ready interrupt
    Uint16 PCM:1;                       // 8 Force position-compare match interrupt
    Uint16 SEL:1;                       // 9 Force strobe event latch interrupt
    Uint16 IEL:1;                       // 10 Force index event latch interrupt
    Uint16 UTO:1;                       // 11 Force unit time out interrupt
    Uint16 rsvd2:4;                     // 15:12 Reserved
};

union QFRC_REG {
    Uint16  all;
    struct  QFRC_BITS  bit;
};

struct QEPSTS_BITS {                    // bits description
    Uint16 PCEF:1;                      // 0 Position counter error flag.
    Uint16 FIMF:1;                      // 1 First index marker flag
    Uint16 CDEF:1;                      // 2 Capture direction error flag
    Uint16 COEF:1;                      // 3 Capture overflow error flag
    Uint16 QDLF:1;                      // 4 eQEP direction latch flag
    Uint16 QDF:1;                       // 5 Quadrature direction flag
    Uint16 FIDF:1;                      // 6 The first index marker
    Uint16 UPEVNT:1;                    // 7 Unit position event flag
    Uint16 rsvd1:8;                     // 15:8 Reserved
};

union QEPSTS_REG {
    Uint16  all;
    struct  QEPSTS_BITS  bit;
};

struct EQEP_REGS {
    Uint32                                   QPOSCNT;                      // Position Counter 
    Uint32                                   QPOSINIT;                     // Position Counter Init 
    Uint32                                   QPOSMAX;                      // Maximum Position Count 
    Uint32                                   QPOSCMP;                      // Position Compare 
    Uint32                                   QPOSILAT;                     // Index Position Latch 
    Uint32                                   QPOSSLAT;                     // Strobe Position Latch
    Uint32                                   QPOSLAT;                      // Position Latch 
    Uint32                                   QUTMR;                        // QEP Unit Timer 
    Uint32                                   QUPRD;                        // QEP Unit Period 
    Uint16                                   QWDTMR;                       // QEP Watchdog Timer 
    Uint16                                   QWDPRD;                       // QEP Watchdog Period 
    union   QDECCTL_REG                      QDECCTL;                      // Quadrature Decoder Control 
    union   QEPCTL_REG                       QEPCTL;                       // QEP Control 
    union   QCAPCTL_REG                      QCAPCTL;                      // Qaudrature Capture Control 
    union   QPOSCTL_REG                      QPOSCTL;                      // Position Compare Control 
    union   QEINT_REG                        QEINT;                        // QEP Interrupt Control 
    union   QFLG_REG                         QFLG;                         // QEP Interrupt Flag 
    union   QCLR_REG                         QCLR;                         // QEP Interrupt Clear 
    union   QFRC_REG                         QFRC;                         // QEP Interrupt Force 
    union   QEPSTS_REG                       QEPSTS;                       // QEP Status 
    Uint16                                   QCTMR;                        // QEP Capture Timer 
    Uint16                                   QCPRD;                        // QEP Capture Period 
    Uint16                                   QCTMRLAT;                     // QEP Capture Latch 
    Uint16                                   QCPRDLAT;                     // QEP Capture Period Latch 
    Uint16                                   rsvd1;                        // Reserved
};

//---------------------------------------------------------------------------
// EQEP External References & Function Declarations:
//
extern volatile struct EQEP_REGS EQep1Regs;
extern volatile struct EQEP_REGS EQep2Regs;
extern volatile struct EQEP_REGS EQep3Regs;
#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================
