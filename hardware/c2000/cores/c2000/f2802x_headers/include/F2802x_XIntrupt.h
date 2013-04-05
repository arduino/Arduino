// TI File $Revision: /main/2 $
// Checkin $Date: September 25, 2008   14:57:54 $
//###########################################################################
//
// FILE:  DSP2802x_XIntrupt.h
//
// TITLE: DSP2802x Device External Interrupt Register Definitions.
//
//###########################################################################
// $TI Release: f2802x Support Library v210 $
// $Release Date: Mon Sep 17 09:13:31 CDT 2012 $
//###########################################################################

#ifndef DSP2802x_XINTRUPT_H
#define DSP2802x_XINTRUPT_H

#ifdef __cplusplus
extern "C" {
#endif

//---------------------------------------------------------------------------

struct XINTCR_BITS {
    Uint16   ENABLE:1;    // 0      enable/disable
    Uint16   rsvd1:1;     // 1      reserved
    Uint16   POLARITY:2;  // 3:2    pos/neg, both triggered
    Uint16   rsvd2:12;    //15:4    reserved
};

union XINTCR_REG {
   Uint16               all;
   struct XINTCR_BITS   bit;
};

//---------------------------------------------------------------------------
// External Interrupt Register File:
//
struct XINTRUPT_REGS {
   union XINTCR_REG XINT1CR;
   union XINTCR_REG XINT2CR;
   union XINTCR_REG XINT3CR;
   Uint16           rsvd1[5];
   Uint16           XINT1CTR;
   Uint16           XINT2CTR;
   Uint16           XINT3CTR;
   Uint16           rsvd[5];
};

//---------------------------------------------------------------------------
// External Interrupt References & Function Declarations:
//
extern volatile struct XINTRUPT_REGS XIntruptRegs;

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of DSP2802x_XINTF_H definition

//===========================================================================
// End of file.
//===========================================================================

