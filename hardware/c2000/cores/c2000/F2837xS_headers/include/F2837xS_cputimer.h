//###########################################################################
//
// FILE:    F2837xS_cputimer.h
//
// TITLE:   F2837xS Device CPUTIMER Register Definitions.
//
//###########################################################################
// $TI Release: F2837xS Support Library v170 $
// $Release Date: Mon Sep 21 16:56:07 CDT 2015 $
// $Copyright: Copyright (C) 2014-2015 Texas Instruments Incorporated -
//             http://www.ti.com/ ALL RIGHTS RESERVED $
//###########################################################################

#ifndef __F2837xS_CPUTIMER_H__
#define __F2837xS_CPUTIMER_H__

#ifdef __cplusplus 
extern "C" {
#endif 


//---------------------------------------------------------------------------
// CPUTIMER Individual Register Bit Definitions:

struct TIM_BITS {                       // bits description
    Uint16 LSW:16;                      // 15:0 CPU-Timer Counter Registers
    Uint16 MSW:16;                      // 31:16 CPU-Timer Counter Registers High
};

union TIM_REG {
    Uint32  all;
    struct  TIM_BITS  bit;
};

struct PRD_BITS {                       // bits description
    Uint16 LSW:16;                      // 15:0 CPU-Timer Period Registers
    Uint16 MSW:16;                      // 31:16 CPU-Timer Period Registers High
};

union PRD_REG {
    Uint32  all;
    struct  PRD_BITS  bit;
};

struct TCR_BITS {                       // bits description
    Uint16 rsvd1:4;                     // 3:0 Reserved
    Uint16 TSS:1;                       // 4 CPU-Timer stop status bit.
    Uint16 TRB:1;                       // 5 Timer reload 
    Uint16 rsvd2:4;                     // 9:6 Reserved
    Uint16 SOFT:1;                      // 10 Emulation modes 
    Uint16 FREE:1;                      // 11 Emulation modes 
    Uint16 rsvd3:2;                     // 13:12 Reserved
    Uint16 TIE:1;                       // 14 CPU-Timer Interrupt Enable.
    Uint16 TIF:1;                       // 15 CPU-Timer Interrupt Flag. 
};

union TCR_REG {
    Uint16  all;
    struct  TCR_BITS  bit;
};

struct TPR_BITS {                       // bits description
    Uint16 TDDR:8;                      // 7:0 CPU-Timer Divide-Down.
    Uint16 PSC:8;                       // 15:8 CPU-Timer Prescale Counter.
};

union TPR_REG {
    Uint16  all;
    struct  TPR_BITS  bit;
};

struct TPRH_BITS {                      // bits description
    Uint16 TDDRH:8;                     // 7:0 CPU-Timer Divide-Down.
    Uint16 PSCH:8;                      // 15:8 CPU-Timer Prescale Counter.
};

union TPRH_REG {
    Uint16  all;
    struct  TPRH_BITS  bit;
};

struct CPUTIMER_REGS {
    union   TIM_REG                          TIM;                          // CPU-Timer, Counter Register
    union   PRD_REG                          PRD;                          // CPU-Timer, Period Register
    union   TCR_REG                          TCR;                          // CPU-Timer, Control Register
    Uint16                                   rsvd1;                        // Reserved
    union   TPR_REG                          TPR;                          // CPU-Timer, Prescale Register
    union   TPRH_REG                         TPRH;                         // CPU-Timer, Prescale Register High
};

//---------------------------------------------------------------------------
// CPUTIMER External References & Function Declarations:
//
extern volatile struct CPUTIMER_REGS CpuTimer0Regs;
extern volatile struct CPUTIMER_REGS CpuTimer1Regs;
extern volatile struct CPUTIMER_REGS CpuTimer2Regs;
#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================
