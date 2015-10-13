//###########################################################################
//
// FILE:    F2837xS_ecap.h
//
// TITLE:   F2837xS Device ECAP Register Definitions.
//
//###########################################################################
// $TI Release: F2837xS Support Library v170 $
// $Release Date: Mon Sep 21 16:56:07 CDT 2015 $
// $Copyright: Copyright (C) 2014-2015 Texas Instruments Incorporated -
//             http://www.ti.com/ ALL RIGHTS RESERVED $
//###########################################################################

#ifndef __F2837xS_ECAP_H__
#define __F2837xS_ECAP_H__

#ifdef __cplusplus 
extern "C" {
#endif 


//---------------------------------------------------------------------------
// ECAP Individual Register Bit Definitions:

struct ECCTL1_BITS {                    // bits description
    Uint16 CAP1POL:1;                   // 0 Capture Event 1 Polarity select
    Uint16 CTRRST1:1;                   // 1 Counter Reset on Capture Event 1 
    Uint16 CAP2POL:1;                   // 2 Capture Event 2 Polarity select 
    Uint16 CTRRST2:1;                   // 3 Counter Reset on Capture Event 2 
    Uint16 CAP3POL:1;                   // 4 Capture Event 3 Polarity select 
    Uint16 CTRRST3:1;                   // 5 Counter Reset on Capture Event 3 
    Uint16 CAP4POL:1;                   // 6 Capture Event 4 Polarity select 
    Uint16 CTRRST4:1;                   // 7 Counter Reset on Capture Event 4 
    Uint16 CAPLDEN:1;                   // 8 Enable Loading CAP1-4 regs on a Cap Event 
    Uint16 PRESCALE:5;                  // 13:9 Event Filter prescale select 
    Uint16 FREE_SOFT:2;                 // 15:14 Emulation mode 
};

union ECCTL1_REG {
    Uint16  all;
    struct  ECCTL1_BITS  bit;
};

struct ECCTL2_BITS {                    // bits description
    Uint16 CONT_ONESHT:1;               // 0 Continuous or one-shot 
    Uint16 STOP_WRAP:2;                 // 2:1 Stop value for one-shot, Wrap for continuous
    Uint16 REARM:1;                     // 3 One-shot re-arm 
    Uint16 TSCTRSTOP:1;                 // 4 TSCNT counter stop 
    Uint16 SYNCI_EN:1;                  // 5 Counter sync-in select
    Uint16 SYNCO_SEL:2;                 // 7:6 Sync-out mode 
    Uint16 SWSYNC:1;                    // 8 SW forced counter sync 
    Uint16 CAP_APWM:1;                  // 9 CAP/APWM operating mode select 
    Uint16 APWMPOL:1;                   // 10  APWM output polarity select 
    Uint16 rsvd1:5;                     // 15:11 Reserved
};

union ECCTL2_REG {
    Uint16  all;
    struct  ECCTL2_BITS  bit;
};

struct ECEINT_BITS {                    // bits description
    Uint16 rsvd1:1;                     // 0 Reserved
    Uint16 CEVT1:1;                     // 1 Capture Event 1 Interrupt Enable 
    Uint16 CEVT2:1;                     // 2 Capture Event 2 Interrupt Enable 
    Uint16 CEVT3:1;                     // 3 Capture Event 3 Interrupt Enable 
    Uint16 CEVT4:1;                     // 4 Capture Event 4 Interrupt Enable 
    Uint16 CTROVF:1;                    // 5 Counter Overflow Interrupt Enable 
    Uint16 CTR_EQ_PRD:1;                // 6 Period Equal Interrupt Enable
    Uint16 CTR_EQ_CMP:1;                // 7 Compare Equal Interrupt Enable 
    Uint16 rsvd2:8;                     // 15:8 Reserved
};

union ECEINT_REG {
    Uint16  all;
    struct  ECEINT_BITS  bit;
};

struct ECFLG_BITS {                     // bits description
    Uint16 INT:1;                       // 0 Global Flag 
    Uint16 CEVT1:1;                     // 1 Capture Event 1 Interrupt Flag 
    Uint16 CEVT2:1;                     // 2 Capture Event 2 Interrupt Flag 
    Uint16 CEVT3:1;                     // 3 Capture Event 3 Interrupt Flag 
    Uint16 CEVT4:1;                     // 4 Capture Event 4 Interrupt Flag 
    Uint16 CTROVF:1;                    // 5 Counter Overflow Interrupt Flag 
    Uint16 CTR_PRD:1;                   // 6 Period Equal Interrupt Flag 
    Uint16 CTR_CMP:1;                   // 7 Compare Equal Interrupt Flag
    Uint16 rsvd1:8;                     // 15:8 Reserved
};

union ECFLG_REG {
    Uint16  all;
    struct  ECFLG_BITS  bit;
};

struct ECCLR_BITS {                     // bits description
    Uint16 INT:1;                       // 0 Global Flag 
    Uint16 CEVT1:1;                     // 1 Capture Event 1 Interrupt Flag 
    Uint16 CEVT2:1;                     // 2 Capture Event 2 Interrupt Flag 
    Uint16 CEVT3:1;                     // 3 Capture Event 3 Interrupt Flag 
    Uint16 CEVT4:1;                     // 4 Capture Event 4 Interrupt Flag 
    Uint16 CTROVF:1;                    // 5 Counter Overflow Interrupt Flag 
    Uint16 CTR_PRD:1;                   // 6 Period Equal Interrupt Flag 
    Uint16 CTR_CMP:1;                   // 7 Compare Equal Interrupt Flag
    Uint16 rsvd1:8;                     // 15:8 Reserved
};

union ECCLR_REG {
    Uint16  all;
    struct  ECCLR_BITS  bit;
};

struct ECFRC_BITS {                     // bits description
    Uint16 rsvd1:1;                     // 0 Reserved
    Uint16 CEVT1:1;                     // 1 Capture Event 1 Interrupt Enable 
    Uint16 CEVT2:1;                     // 2 Capture Event 2 Interrupt Enable 
    Uint16 CEVT3:1;                     // 3 Capture Event 3 Interrupt Enable 
    Uint16 CEVT4:1;                     // 4 Capture Event 4 Interrupt Enable 
    Uint16 CTROVF:1;                    // 5 Counter Overflow Interrupt Enable 
    Uint16 CTR_PRD:1;                   // 6 Period Equal Interrupt Enable
    Uint16 CTR_CMP:1;                   // 7 Compare Equal Interrupt Enable 
    Uint16 rsvd2:8;                     // 15:8 Reserved
};

union ECFRC_REG {
    Uint16  all;
    struct  ECFRC_BITS  bit;
};

struct ECAP_REGS {
    Uint32                                   TSCTR;                        // Time-Stamp Counter
    Uint32                                   CTRPHS;                       // Counter Phase Offset Value Register
    Uint32                                   CAP1;                         // Capture 1 Register
    Uint32                                   CAP2;                         // Capture 2 Register
    Uint32                                   CAP3;                         // Capture 3Register
    Uint32                                   CAP4;                         // Capture 4 Register
    Uint16                                   rsvd1[8];                     // Reserved
    union   ECCTL1_REG                       ECCTL1;                       // Capture Control Register 1
    union   ECCTL2_REG                       ECCTL2;                       // Capture Control Register 2
    union   ECEINT_REG                       ECEINT;                       // Capture Interrupt Enable Register
    union   ECFLG_REG                        ECFLG;                        // Capture Interrupt Flag Register
    union   ECCLR_REG                        ECCLR;                        // Capture Interrupt Flag Register
    union   ECFRC_REG                        ECFRC;                        // Capture Interrupt Force Register
    Uint16                                   rsvd2[6];                     // Reserved
};

//---------------------------------------------------------------------------
// ECAP External References & Function Declarations:
//
extern volatile struct ECAP_REGS ECap1Regs;
extern volatile struct ECAP_REGS ECap2Regs;
extern volatile struct ECAP_REGS ECap3Regs;
extern volatile struct ECAP_REGS ECap4Regs;
extern volatile struct ECAP_REGS ECap5Regs;
extern volatile struct ECAP_REGS ECap6Regs;
#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================
