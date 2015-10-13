//###########################################################################
//
// FILE:   F2837xS_Cla_defines.h
//
// TITLE:  #defines used in CLA examples
//
//###########################################################################
// $TI Release: F2837xS Support Library v170 $
// $Release Date: Mon Sep 21 16:56:07 CDT 2015 $
// $Copyright: Copyright (C) 2014-2015 Texas Instruments Incorporated -
//             http://www.ti.com/ ALL RIGHTS RESERVED $
//###########################################################################

#ifndef F2837xS_CLA_DEFINES_H
#define F2837xS_CLA_DEFINES_H

#ifdef __cplusplus
extern "C" {
#endif

// MCTL Register
//==========================
#define CLA_FORCE_RESET           0x1
#define CLA_IACK_ENABLE           0x1
#define CLA_IACK_DISABLE          0x0

// MMEMCFG Register
//==========================
#define CLA_CLA_SPACE             0x1
#define CLA_CPU_SPACE             0x0

// MIER Interrupt Enable Register
//==========================
#define CLA_INT_ENABLE            0x1
#define CLA_INT_DISABLE           0x0

// Peripheral Interrupt Source Select define for DMAnCLASourceSelect Register
//===========================================================================
#define CLA_TRIG_NOPERPH	 0
#define CLA_TRIG_ADCAINT1    1
#define CLA_TRIG_ADCAINT2    2
#define CLA_TRIG_ADCAINT3    3
#define CLA_TRIG_ADCAINT4    4
#define CLA_TRIG_ADCAEVT     5
#define CLA_TRIG_ADCBINT1    6
#define CLA_TRIG_ADCBINT2    7
#define CLA_TRIG_ADCBINT3    8
#define CLA_TRIG_ADCBINT4    9
#define CLA_TRIG_ADCBEVT     10
#define CLA_TRIG_ADCCINT1    11
#define CLA_TRIG_ADCCINT2    12
#define CLA_TRIG_ADCCINT3    13
#define CLA_TRIG_ADCCINT4    14
#define CLA_TRIG_ADCCEVT     15
#define CLA_TRIG_ADCDINT1    16
#define CLA_TRIG_ADCDINT2    17
#define CLA_TRIG_ADCDINT3    18
#define CLA_TRIG_ADCDINT4    19
#define CLA_TRIG_ADCDEVT     20

#define CLA_TRIG_XINT1   	29
#define CLA_TRIG_XINT2   	30
#define CLA_TRIG_XINT3   	31
#define CLA_TRIG_XINT4   	32
#define CLA_TRIG_XINT5   	33

#define CLA_TRIG_EPWM1INT  	36
#define CLA_TRIG_EPWM2INT  	37
#define CLA_TRIG_EPWM3INT  	38
#define CLA_TRIG_EPWM4INT  	39
#define CLA_TRIG_EPWM5INT  	40
#define CLA_TRIG_EPWM6INT  	41
#define CLA_TRIG_EPWM7INT  	42
#define CLA_TRIG_EPWM8INT  	43
#define CLA_TRIG_EPWM9INT  	44
#define CLA_TRIG_EPWM10INT  45
#define CLA_TRIG_EPWM11INT  46
#define CLA_TRIG_EPWM12INT  47

#define CLA_TRIG_TINT0   	68
#define CLA_TRIG_TINT1   	69
#define CLA_TRIG_TINT2   	70

#define CLA_TRIG_MXEVTA  	71
#define CLA_TRIG_MREVTA  	72
#define CLA_TRIG_MXEVTB  	73
#define CLA_TRIG_MREVTB  	74

#define CLA_TRIG_ECAP1INT   75
#define CLA_TRIG_ECAP2INT   76
#define CLA_TRIG_ECAP3INT   77
#define CLA_TRIG_ECAP4INT   78
#define CLA_TRIG_ECAP5INT   79
#define CLA_TRIG_ECAP6INT   80

#define CLA_TRIG_EQEP1INT 	83
#define CLA_TRIG_EQEP2INT   84
#define CLA_TRIG_EQEP3INT   85

#define CLA_TRIG_HRCAP1INT  87
#define CLA_TRIG_HRCAP2INT  88

#define CLA_TRIG_SD1INT		95
#define CLA_TRIG_SD2INT     96

#define CLA_TRIG_UPP1_INT   107

#define CLA_TRIG_SPITXINTA  109
#define CLA_TRIG_SPIRXINTA	110
#define CLA_TRIG_SPITXINTB	111
#define CLA_TRIG_SPIRXINTB	112
#define CLA_TRIG_SPITXINTC	113
#define CLA_TRIG_SPIRXINTC	114
// TODO



//---------------------------------------------------------------------------
// Useful CLA Operation Macros:
//================================

#define Cla1ForceTask1andWait()asm("  IACK  #0x0001");             \
                               asm("  RPT #3 || NOP");             \
                                while(Cla1Regs.MIRUN.bit.INT1 == 1);


#define Cla1ForceTask2andWait()asm("  IACK  #0x0002");             \
                               asm("  RPT #3 || NOP");             \
                                while(Cla1Regs.MIRUN.bit.INT2 == 1);

#define Cla1ForceTask3andWait()asm("  IACK  #0x0004");             \
                               asm("  RPT #3 || NOP");             \
                                while(Cla1Regs.MIRUN.bit.INT3 == 1);

#define Cla1ForceTask4andWait()asm("  IACK  #0x0008");             \
                               asm("  RPT #3 || NOP");             \
                                while(Cla1Regs.MIRUN.bit.INT4 == 1);

#define Cla1ForceTask5andWait()asm("  IACK  #0x0010");             \
                               asm("  RPT #3 || NOP");             \
                                while(Cla1Regs.MIRUN.bit.INT5 == 1);

#define Cla1ForceTask6andWait()asm("  IACK  #0x0020");             \
                               asm("  RPT #3 || NOP");             \
                                while(Cla1Regs.MIRUN.bit.INT6 == 1);

#define Cla1ForceTask7andWait()asm("  IACK  #0x0040");             \
                               asm("  RPT #3 || NOP");             \
                                while(Cla1Regs.MIRUN.bit.INT7 == 1);

#define Cla1ForceTask8andWait()asm("  IACK  #0x0080");             \
                               asm("  RPT #3 || NOP");             \
                                while(Cla1Regs.MIRUN.bit.INT8 == 1);


#define Cla1ForceTask1()       asm("  IACK  #0x0001")
#define Cla1ForceTask2()       asm("  IACK  #0x0002")
#define Cla1ForceTask3()       asm("  IACK  #0x0004")
#define Cla1ForceTask4()       asm("  IACK  #0x0008")
#define Cla1ForceTask5()       asm("  IACK  #0x0010")
#define Cla1ForceTask6()       asm("  IACK  #0x0020")
#define Cla1ForceTask7()       asm("  IACK  #0x0040")
#define Cla1ForceTask8()       asm("  IACK  #0x0080")

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif   // - end of F2837xS_CLA_DEFINES_H

//===========================================================================
// End of file.
//===========================================================================
