//###########################################################################
//
// FILE:   F2837xS_sdfm_strut.h
//
// TITLE:  contains structures used for the SDFM driver.
//
//###########################################################################
// $TI Release: F2837xS Support Library v170 $
// $Release Date: Mon Sep 21 16:56:07 CDT 2015 $
// $Copyright: Copyright (C) 2014-2015 Texas Instruments Incorporated -
//             http://www.ti.com/ ALL RIGHTS RESERVED $
//###########################################################################

#ifndef F2837xS_SDFM_STRUCT_H
#define F2837xS_SDFM_STRUCT_H

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_CPUTIMER 4
#define MAX_ECAP 7
#define MAX_EPWM 13
#define MAX_EQEP 4
#define MAX_I2C 2
#define MAX_MCBSP 2
#define MAX_SCI 2
#define MAX_SPI 4
#define MAX_ADC	5
#define MAX_SDFM 3
#define MAX_TRIPSEL 15

extern volatile Uint16 *TRIP_SEL[MAX_TRIPSEL];
extern volatile struct ADC_REGS *ADC[MAX_ADC];
extern volatile struct CPUTIMER_REGS *CPUTIMER[MAX_CPUTIMER];
extern volatile struct ECAP_REGS *ECAP[MAX_ECAP];
extern volatile struct EPWM_REGS *EPWM[MAX_EPWM];
extern volatile struct EQEP_REGS *EQEP[MAX_EQEP];
extern volatile struct I2C_REGS *I2C[MAX_I2C];
extern volatile struct McBSP_REGS *MCBSP[MAX_MCBSP];
extern volatile struct SCI_REGS *SCI[MAX_SCI];
extern volatile struct SPI_REGS *SPI[MAX_SPI];
extern volatile struct SDFM_REGS *SDFM[MAX_SDFM];

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif   // - end of F2837xS_SDFM_STRUCT_H
