// TI File $Revision: /main/1 $
// Checkin $Date: August 14, 2008   16:55:40 $
//###########################################################################
//
// FILE:   F2802x_ECap.h
//
// TITLE:  F2802x Enhanced Capture Module Register Bit Definitions.
//
//###########################################################################
// $TI Release: 2802x C/C++ Header Files and Peripheral Examples V1.29 $
// $Release Date: January 11, 2011 $
//###########################################################################

#ifndef F2802x_ECAP_H
#define F2802x_ECAP_H

#ifdef __cplusplus
extern "C" {
#endif

//----------------------------------------------------
// Capture control register 1 bit definitions */
struct ECCTL1_BITS {          // bits   description
   uint16_t CAP1POL:1;          // 0      Capture Event 1 Polarity select
   uint16_t CTRRST1:1;          // 1      Counter Reset on Capture Event 1
   uint16_t CAP2POL:1;          // 2      Capture Event 2 Polarity select
   uint16_t CTRRST2:1;          // 3      Counter Reset on Capture Event 2
   uint16_t CAP3POL:1;          // 4      Capture Event 3 Polarity select
   uint16_t CTRRST3:1;          // 5      Counter Reset on Capture Event 3
   uint16_t CAP4POL:1;          // 6      Capture Event 4 Polarity select
   uint16_t CTRRST4:1;          // 7      Counter Reset on Capture Event 4
   uint16_t CAPLDEN:1;          // 8      Enable Loading CAP1-4 regs on a Cap Event
   uint16_t PRESCALE:5;         // 13:9   Event Filter prescale select
   uint16_t FREE_SOFT:2;        // 15:14  Emulation mode
};

union ECCTL1_REG {
   uint16_t              all;
   struct ECCTL1_BITS  bit;
};

// In V1.1 the STOPVALUE bit field was changed to
// STOP_WRAP.  This correlated to a silicon change from
// F2802x Rev 0 to Rev A.
//----------------------------------------------------
// Capture control register 2 bit definitions */
struct ECCTL2_BITS {          // bits   description
   uint16_t CONT_ONESHT:1;      // 0      Continuous or one-shot
   uint16_t STOP_WRAP:2;        // 2:1    Stop value for one-shot, Wrap for continuous
   uint16_t REARM:1;            // 3      One-shot re-arm
   uint16_t TSCTRSTOP:1;        // 4      TSCNT counter stop
   uint16_t SYNCI_EN:1;         // 5      Counter sync-in select
   uint16_t SYNCO_SEL:2;        // 7:6    Sync-out mode
   uint16_t SWSYNC:1;           // 8      SW forced counter sync
   uint16_t CAP_APWM:1;         // 9      CAP/APWM operating mode select
   uint16_t APWMPOL:1;          // 10     APWM output polarity select
   uint16_t rsvd1:5;            // 15:11
};

union ECCTL2_REG {
   uint16_t              all;
   struct ECCTL2_BITS  bit;
};

//----------------------------------------------------
// ECAP interrupt enable register bit definitions */
struct ECEINT_BITS {          // bits   description
   uint16_t rsvd1:1;            // 0      reserved
   uint16_t CEVT1:1;            // 1      Capture Event 1 Interrupt Enable
   uint16_t CEVT2:1;            // 2      Capture Event 2 Interrupt Enable
   uint16_t CEVT3:1;            // 3      Capture Event 3 Interrupt Enable
   uint16_t CEVT4:1;            // 4      Capture Event 4 Interrupt Enable
   uint16_t CTROVF:1;           // 5      Counter Overflow Interrupt Enable
   uint16_t CTR_EQ_PRD:1;       // 6      Period Equal Interrupt Enable
   uint16_t CTR_EQ_CMP:1;       // 7      Compare Equal Interrupt Enable
   uint16_t rsvd2:8;            // 15:8   reserved
};

union ECEINT_REG {
   uint16_t              all;
   struct ECEINT_BITS  bit;
};

//----------------------------------------------------
// ECAP interrupt flag register bit definitions */
struct ECFLG_BITS {           // bits   description
   uint16_t INT:1;              // 0      Global Flag
   uint16_t CEVT1:1;            // 1      Capture Event 1 Interrupt Flag
   uint16_t CEVT2:1;            // 2      Capture Event 2 Interrupt Flag
   uint16_t CEVT3:1;            // 3      Capture Event 3 Interrupt Flag
   uint16_t CEVT4:1;            // 4      Capture Event 4 Interrupt Flag
   uint16_t CTROVF:1;           // 5      Counter Overflow Interrupt Flag
   uint16_t CTR_EQ_PRD:1;       // 6      Period Equal Interrupt Flag
   uint16_t CTR_EQ_CMP:1;       // 7      Compare Equal Interrupt Flag
   uint16_t rsvd2:8;            // 15:8   reserved
};

union ECFLG_REG {
   uint16_t              all;
   struct ECFLG_BITS   bit;
};

//----------------------------------------------------

struct ECAP_REGS {
   uint32_t              TSCTR;    // Time stamp counter
   uint32_t              CTRPHS;   // Counter phase
   uint32_t              CAP1;     // Capture 1
   uint32_t              CAP2;     // Capture 2
   uint32_t              CAP3;     // Capture 3
   uint32_t              CAP4;     // Capture 4
   uint16_t              rsvd1[8]; // reserved
   union   ECCTL1_REG  ECCTL1;   // Capture Control Reg 1
   union   ECCTL2_REG  ECCTL2;   // Capture Control Reg 2
   union   ECEINT_REG  ECEINT;   // ECAP interrupt enable
   union   ECFLG_REG   ECFLG;    // ECAP interrupt flags
   union   ECFLG_REG   ECCLR;    // ECAP interrupt clear
   union   ECEINT_REG  ECFRC;    // ECAP interrupt force
   uint16_t              rsvd2[6]; // reserved
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
