//###########################################################################
//
// FILE:   F2802x_NmiIntrupt.h
//
// TITLE:  F2802x Device NMI Interrupt Register Definitions
//
//###########################################################################
// $TI Release: 2802x C/C++ Header Files and Peripheral Examples V1.29 $
// $Release Date: January 11, 2011 $
//###########################################################################

#ifndef F2802x_NMIINTRUPT_H
#define F2802x_NMIINTRUPT_H

#ifdef __cplusplus
extern "C" {
#endif

//===========================================================================
//  NMI Interrupt Register Bit Definitions
//

struct NMICFG_BITS {             // bits      description
    uint16_t   rsvd1:1;            // 0         reserved
    uint16_t   CLOCKFAIL:1;        // 1         Fail Interrupt Enable Bits
    uint16_t   rsvd2:14;           // 15:02     reserved
};

union NMICFG_REG  {
    uint16_t                         all;
    struct NMICFG_BITS             bit;
};

struct NMIFLG_BITS {             // bits      description
    uint16_t   NMIINT:1;           // 0         NMI Interrupt Flag
    uint16_t   CLOCKFAIL:1;        // 1         Clock Fail Interrupt Flags
    uint16_t   rsvd1:14;           // 15:02     reserved
};

union NMIFLG_REG  {
    uint16_t                         all;
    struct NMIFLG_BITS             bit;
};

struct NMIFLGCLR_BITS {          // bits      description
    uint16_t   NMIINT:1;           // 0         NMIINT Flag Clear Bit
    uint16_t   CLOCKFAIL:1;        // 1         CLOCKFAIL Flag Clear Bit
    uint16_t   rsvd1:14;           // 15:02     reserved
};

union NMIFLGCLR_REG  {
    uint16_t                         all;
    struct NMIFLGCLR_BITS          bit;
};

struct NMIFLGFRC_BITS {          // bits      description
    uint16_t   rsvd1:1;            // 0         reserved
    uint16_t   CLOCKFAIL:1;        // 1         CLOCKFAIL Flag Force Bit
    uint16_t   rsvd2:14;           // 15:02     reserved
};

union NMIFLGFRC_REG  {
    uint16_t                         all;
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
    uint16_t                     NMIWDCNT;
    uint16_t                     NMIWDPRD;
    uint16_t                     rsvd1[10];
};

//===========================================================================
//  NMI Interrupt External References and Function Declarations
//

extern volatile struct NMIINTRUPT_REGS NmiIntruptRegs;

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of F2802x_NMIINTRUPT_H definition

//===========================================================================
// End of file
//===========================================================================
