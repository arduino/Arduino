//###########################################################################
//
// FILE:   F2806x_NmiIntrupt.h
//
// TITLE:  F2806x Device NMI Interrupt Register Definitions
//
//###########################################################################
// $TI Release: 2806x C/C++ Header Files V1.10 $
// $Release Date: April 7, 2011 $
//###########################################################################

#ifndef F2806x_NMIINTRUPT_H
#define F2806x_NMIINTRUPT_H

#ifdef __cplusplus
extern "C" {
#endif

//===========================================================================
//  NMI Interrupt Register Bit Definitions
//

struct NMICFG_BITS {             // bits      description
    Uint16   rsvd1:1;            // 0         Reserved
    Uint16   CLOCKFAIL:1;        // 1         Fail Interrupt Enable Bits
    Uint16   rsvd2:14;           // 15:2      Reserved
};

union NMICFG_REG  {
    Uint16                         all;
    struct NMICFG_BITS             bit;
};

struct NMIFLG_BITS {             // bits      description
    Uint16   NMIINT:1;           // 0         NMI Interrupt Flag
    Uint16   CLOCKFAIL:1;        // 1         Clock Fail Interrupt Flags
    Uint16   rsvd1:14;           // 15:2      Reserved
};

union NMIFLG_REG  {
    Uint16                         all;
    struct NMIFLG_BITS             bit;
};

struct NMIFLGCLR_BITS {          // bits      description
    Uint16   NMIINT:1;           // 0         NMIINT Flag Clear Bit
    Uint16   CLOCKFAIL:1;        // 1         Clock Fail Flag Clear Bit
    Uint16   rsvd1:14;           // 15:2      Reserved
};

union NMIFLGCLR_REG  {
    Uint16                         all;
    struct NMIFLGCLR_BITS          bit;
};

struct NMIFLGFRC_BITS {          // bits      description
    Uint16   rsvd1:1;            // 0         Reserved
    Uint16   CLOCKFAIL:1;        // 1         Clock Fail Flag Force Bit
    Uint16   rsvd2:14;           // 15:2      Reserved
};

union NMIFLGFRC_REG  {
    Uint16                         all;
    struct NMIFLGFRC_BITS          bit;
};

//===========================================================================
//  NMI Interrupt Register Definitions
//

struct NMIINTRUPT_REGS {
    union  NMICFG_REG          NMICFG;
    union  NMIFLG_REG          NMIFLG;
    union  NMIFLGCLR_REG       NMIFLGCLR;
    union  NMIFLGFRC_REG       NMIFLGFRC;
    Uint16                     NMIWDCNT;
    Uint16                     NMIWDPRD;
    Uint16                     rsvd1[10];
};

//===========================================================================
//  NMI Interrupt External References and Function Declarations
//

extern volatile struct NMIINTRUPT_REGS NmiIntruptRegs;

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of F2806x_NMIINTRUPT_H definition

//===========================================================================
// End of file
//===========================================================================
