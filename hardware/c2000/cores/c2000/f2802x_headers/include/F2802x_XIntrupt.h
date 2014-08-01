//###########################################################################
//
// FILE:  F2802x_XIntrupt.h
//
// TITLE: F2802x Device External Interrupt Register Definitions.
//
//###########################################################################
// $TI Release: 2802x C/C++ Header Files and Peripheral Examples V1.29 $
// $Release Date: January 11, 2011 $
//###########################################################################

#ifndef F2802x_XINTRUPT_H
#define F2802x_XINTRUPT_H

#ifdef __cplusplus
extern "C" {
#endif

//---------------------------------------------------------------------------

struct XINTCR_BITS {
    uint16_t   ENABLE:1;    // 0      enable/disable
    uint16_t   rsvd1:1;     // 1      reserved
    uint16_t   POLARITY:2;  // 3:2    pos/neg, both triggered
    uint16_t   rsvd2:12;    //15:4    reserved
};

union XINTCR_REG {
    uint16_t               all;
    struct XINTCR_BITS   bit;
};

//---------------------------------------------------------------------------
// External Interrupt Register File:
//
struct XINTRUPT_REGS {
    union XINTCR_REG XINT1CR;
    union XINTCR_REG XINT2CR;
    union XINTCR_REG XINT3CR;
    uint16_t           rsvd1[5];
    uint16_t           XINT1CTR;
    uint16_t           XINT2CTR;
    uint16_t           XINT3CTR;
    uint16_t           rsvd[5];
};

//---------------------------------------------------------------------------
// External Interrupt References & Function Declarations:
//
extern volatile struct XINTRUPT_REGS XIntruptRegs;

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of F2802x_XINTF_H definition

//===========================================================================
// End of file.
//===========================================================================

