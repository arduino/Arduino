//###########################################################################
//
// FILE:    F2837xS_input_xbar.h
//
// TITLE:   F2837xS Device INPUT_XBAR Register Definitions.
//
//###########################################################################
// $TI Release: F2837xS Support Library v170 $
// $Release Date: Mon Sep 21 16:56:07 CDT 2015 $
// $Copyright: Copyright (C) 2014-2015 Texas Instruments Incorporated -
//             http://www.ti.com/ ALL RIGHTS RESERVED $
//###########################################################################

#ifndef __F2837xS_INPUT_XBAR_H__
#define __F2837xS_INPUT_XBAR_H__

#ifdef __cplusplus 
extern "C" {
#endif 


//---------------------------------------------------------------------------
// INPUT_XBAR Individual Register Bit Definitions:

struct INPUTSELECTLOCK_BITS {           // bits description
    Uint16 INPUT1SELECT:1;              // 0 Lock bit for INPUT1SEL Register
    Uint16 INPUT2SELECT:1;              // 1 Lock bit for INPUT2SEL Register
    Uint16 INPUT3SELECT:1;              // 2 Lock bit for INPUT3SEL Register
    Uint16 INPUT4SELECT:1;              // 3 Lock bit for INPUT4SEL Register
    Uint16 INPUT5SELECT:1;              // 4 Lock bit for INPUT5SEL Register
    Uint16 INPUT6SELECT:1;              // 5 Lock bit for INPUT7SEL Register
    Uint16 INPUT7SELECT:1;              // 6 Lock bit for INPUT8SEL Register
    Uint16 INPUT8SELECT:1;              // 7 Lock bit for INPUT9SEL Register
    Uint16 INPUT9SELECT:1;              // 8 Lock bit for INPUT10SEL Register
    Uint16 INPUT10SELECT:1;             // 9 Lock bit for INPUT11SEL Register
    Uint16 INPUT11SELECT:1;             // 10 Lock bit for INPUT11SEL Register
    Uint16 INPUT12SELECT:1;             // 11 Lock bit for INPUT12SEL Register
    Uint16 INPUT13SELECT:1;             // 12 Lock bit for INPUT13SEL Register
    Uint16 INPUT14SELECT:1;             // 13 Lock bit for INPUT14SEL Register
    Uint16 INPUT15SELECT:1;             // 14 Lock bit for INPUT15SEL Register
    Uint16 INPUT16SELECT:1;             // 15 Lock bit for INPUT16SEL Register
    Uint16 rsvd1:16;                    // 31:16 Reserved
};

union INPUTSELECTLOCK_REG {
    Uint32  all;
    struct  INPUTSELECTLOCK_BITS  bit;
};

struct INPUT_XBAR_REGS {
    Uint16                                   INPUT1SELECT;                 // INPUT1 Input Select Register (GPIO0 to x)
    Uint16                                   INPUT2SELECT;                 // INPUT2 Input Select Register (GPIO0 to x)
    Uint16                                   INPUT3SELECT;                 // INPUT3 Input Select Register (GPIO0 to x)
    Uint16                                   INPUT4SELECT;                 // INPUT4 Input Select Register (GPIO0 to x)
    Uint16                                   INPUT5SELECT;                 // INPUT5 Input Select Register (GPIO0 to x)
    Uint16                                   INPUT6SELECT;                 // INPUT6 Input Select Register (GPIO0 to x)
    Uint16                                   INPUT7SELECT;                 // INPUT7 Input Select Register (GPIO0 to x)
    Uint16                                   INPUT8SELECT;                 // INPUT8 Input Select Register (GPIO0 to x)
    Uint16                                   INPUT9SELECT;                 // INPUT9 Input Select Register (GPIO0 to x)
    Uint16                                   INPUT10SELECT;                // INPUT10 Input Select Register (GPIO0 to x)
    Uint16                                   INPUT11SELECT;                // INPUT11 Input Select Register (GPIO0 to x)
    Uint16                                   INPUT12SELECT;                // INPUT12 Input Select Register (GPIO0 to x)
    Uint16                                   INPUT13SELECT;                // INPUT13 Input Select Register (GPIO0 to x)
    Uint16                                   INPUT14SELECT;                // INPUT14 Input Select Register (GPIO0 to x)
    Uint16                                   rsvd1[16];                    // Reserved
    union   INPUTSELECTLOCK_REG              INPUTSELECTLOCK;              // Input Select Lock Register
};

//---------------------------------------------------------------------------
// INPUT_XBAR External References & Function Declarations:
//
extern volatile struct INPUT_XBAR_REGS InputXbarRegs;
#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================
