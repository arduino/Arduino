// TI File $Revision: /main/1 $
// Checkin $Date: August 14, 2008   16:55:40 $
//###########################################################################
//
// FILE:   DSP2802x_ECap.h
//
// TITLE:  DSP2802x Enhanced Capture Module Register Bit Definitions.
//
//###########################################################################
// $TI Release: f2802x Support Library v210 $
// $Release Date: Mon Sep 17 09:13:31 CDT 2012 $
//###########################################################################

#ifndef DSP2802x_ECAP_H
#define DSP2802x_ECAP_H

#ifdef __cplusplus
extern "C" {
#endif

//----------------------------------------------------
// Capture control register 1 bit definitions */
struct ECCTL1_BITS {          // bits   description
   Uint16 CAP1POL:1;          // 0      Capture Event 1 Polarity select
   Uint16 CTRRST1:1;          // 1      Counter Reset on Capture Event 1
   Uint16 CAP2POL:1;          // 2      Capture Event 2 Polarity select
   Uint16 CTRRST2:1;          // 3      Counter Reset on Capture Event 2
   Uint16 CAP3POL:1;          // 4      Capture Event 3 Polarity select
   Uint16 CTRRST3:1;          // 5      Counter Reset on Capture Event 3
   Uint16 CAP4POL:1;          // 6      Capture Event 4 Polarity select
   Uint16 CTRRST4:1;          // 7      Counter Reset on Capture Event 4
   Uint16 CAPLDEN:1;          // 8      Enable Loading CAP1-4 regs on a Cap Event
   Uint16 PRESCALE:5;         // 13:9   Event Filter prescale select
   Uint16 FREE_SOFT:2;        // 15:14  Emulation mode
};

union ECCTL1_REG {
   Uint16              all;
   struct ECCTL1_BITS  bit;
};

// In V1.1 the STOPVALUE bit field was changed to
// STOP_WRAP.  This correlated to a silicon change from
// F2802x Rev 0 to Rev A.
//----------------------------------------------------
// Capture control register 2 bit definitions */
struct ECCTL2_BITS {          // bits   description
   Uint16 CONT_ONESHT:1;      // 0      Continuous or one-shot
   Uint16 STOP_WRAP:2;        // 2:1    Stop value for one-shot, Wrap for continuous
   Uint16 REARM:1;            // 3      One-shot re-arm
   Uint16 TSCTRSTOP:1;        // 4      TSCNT counter stop
   Uint16 SYNCI_EN:1;         // 5      Counter sync-in select
   Uint16 SYNCO_SEL:2;        // 7:6    Sync-out mode
   Uint16 SWSYNC:1;           // 8      SW forced counter sync
   Uint16 CAP_APWM:1;         // 9      CAP/APWM operating mode select
   Uint16 APWMPOL:1;          // 10     APWM output polarity select
   Uint16 rsvd1:5;            // 15:11
};

union ECCTL2_REG {
   Uint16              all;
   struct ECCTL2_BITS  bit;
};

//----------------------------------------------------
// ECAP interrupt enable register bit definitions */
struct ECEINT_BITS {          // bits   description
   Uint16 rsvd1:1;            // 0      reserved
   Uint16 CEVT1:1;            // 1      Capture Event 1 Interrupt Enable
   Uint16 CEVT2:1;            // 2      Capture Event 2 Interrupt Enable
   Uint16 CEVT3:1;            // 3      Capture Event 3 Interrupt Enable
   Uint16 CEVT4:1;            // 4      Capture Event 4 Interrupt Enable
   Uint16 CTROVF:1;           // 5      Counter Overflow Interrupt Enable
   Uint16 CTR_EQ_PRD:1;       // 6      Period Equal Interrupt Enable
   Uint16 CTR_EQ_CMP:1;       // 7      Compare Equal Interrupt Enable
   Uint16 rsvd2:8;            // 15:8   reserved
};

union ECEINT_REG {
   Uint16              all;
   struct ECEINT_BITS  bit;
};

//----------------------------------------------------
// ECAP interrupt flag register bit definitions */
struct ECFLG_BITS {           // bits   description
   Uint16 INT:1;              // 0      Global Flag
   Uint16 CEVT1:1;            // 1      Capture Event 1 Interrupt Flag
   Uint16 CEVT2:1;            // 2      Capture Event 2 Interrupt Flag
   Uint16 CEVT3:1;            // 3      Capture Event 3 Interrupt Flag
   Uint16 CEVT4:1;            // 4      Capture Event 4 Interrupt Flag
   Uint16 CTROVF:1;           // 5      Counter Overflow Interrupt Flag
   Uint16 CTR_EQ_PRD:1;       // 6      Period Equal Interrupt Flag
   Uint16 CTR_EQ_CMP:1;       // 7      Compare Equal Interrupt Flag
   Uint16 rsvd2:8;            // 15:8   reserved
};

union ECFLG_REG {
   Uint16              all;
   struct ECFLG_BITS   bit;
};

//----------------------------------------------------

struct ECAP_REGS {
   Uint32              TSCTR;    // Time stamp counter
   Uint32              CTRPHS;   // Counter phase
   Uint32              CAP1;     // Capture 1
   Uint32              CAP2;     // Capture 2
   Uint32              CAP3;     // Capture 3
   Uint32              CAP4;     // Capture 4
   Uint16              rsvd1[8]; // reserved
   union   ECCTL1_REG  ECCTL1;   // Capture Control Reg 1
   union   ECCTL2_REG  ECCTL2;   // Capture Control Reg 2
   union   ECEINT_REG  ECEINT;   // ECAP interrupt enable
   union   ECFLG_REG   ECFLG;    // ECAP interrupt flags
   union   ECFLG_REG   ECCLR;    // ECAP interrupt clear
   union   ECEINT_REG  ECFRC;    // ECAP interrupt force
   Uint16              rsvd2[6]; // reserved
};

//---------------------------------------------------------------------------
// GPI/O External References & Function Declarations:
//
extern volatile struct ECAP_REGS ECap1Regs;

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of DSP2802x_ECAP_H definition

//===========================================================================
// End of file.
//===========================================================================
