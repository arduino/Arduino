/* ============================================================================ */
/* Copyright (c) 2014, Texas Instruments Incorporated                           */
/*  All rights reserved.                                                        */
/*                                                                              */
/*  Redistribution and use in source and binary forms, with or without          */
/*  modification, are permitted provided that the following conditions          */
/*  are met:                                                                    */
/*                                                                              */
/*  *  Redistributions of source code must retain the above copyright           */
/*     notice, this list of conditions and the following disclaimer.            */
/*                                                                              */
/*  *  Redistributions in binary form must reproduce the above copyright        */
/*     notice, this list of conditions and the following disclaimer in the      */
/*     documentation and/or other materials provided with the distribution.     */
/*                                                                              */
/*  *  Neither the name of Texas Instruments Incorporated nor the names of      */
/*     its contributors may be used to endorse or promote products derived      */
/*     from this software without specific prior written permission.            */
/*                                                                              */
/*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" */
/*  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,       */
/*  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR      */
/*  PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR            */
/*  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,       */
/*  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,         */
/*  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; */
/*  OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,    */
/*  WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR     */
/*  OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,              */
/*  EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.                          */
/* ============================================================================ */

/********************************************************************
*
* Standard register and bit definitions for the Texas Instruments
* MSP430 microcontroller.
*
* This file supports assembler and C development for
* MSP430FR5969 devices.
*
* Texas Instruments, Version 1.4
*
* Rev. 1.0, Setup
* Rev. 1.1  updated PxSELC register address to offset 0x16 (instead of 0x10)
*           replaced Comperator B with Comperator E
* Rev. 1.2  fixed typo in SYSRSTIV_MPUSEG defintions
*           replaced COMP_B with COMP_E
* Rev. 1.3  removed not available PxDS Register definitions
* Rev. 1.4  replaced NACCESSx with NWAITSx
*
********************************************************************/

#ifndef __MSP430FR5969
#define __MSP430FR5969

#define __MSP430_HEADER_VERSION__ 1121

#define __MSP430_TI_HEADERS__

#ifdef __cplusplus
extern "C" {
#endif

#include <iomacros.h>

/************************************************************
* STANDARD BITS
************************************************************/

#define BIT0                (0x0001)
#define BIT1                (0x0002)
#define BIT2                (0x0004)
#define BIT3                (0x0008)
#define BIT4                (0x0010)
#define BIT5                (0x0020)
#define BIT6                (0x0040)
#define BIT7                (0x0080)
#define BIT8                (0x0100)
#define BIT9                (0x0200)
#define BITA                (0x0400)
#define BITB                (0x0800)
#define BITC                (0x1000)
#define BITD                (0x2000)
#define BITE                (0x4000)
#define BITF                (0x8000)

/************************************************************
* STATUS REGISTER BITS
************************************************************/

#define C                   (0x0001)
#define Z                   (0x0002)
#define N                   (0x0004)
#define V                   (0x0100)
#define GIE                 (0x0008)
#define CPUOFF              (0x0010)
#define OSCOFF              (0x0020)
#define SCG0                (0x0040)
#define SCG1                (0x0080)

/* Low Power Modes coded with Bits 4-7 in SR */

#ifndef __STDC__ /* Begin #defines for assembler */
#define LPM0                (CPUOFF)
#define LPM1                (SCG0+CPUOFF)
#define LPM2                (SCG1+CPUOFF)
#define LPM3                (SCG1+SCG0+CPUOFF)
#define LPM4                (SCG1+SCG0+OSCOFF+CPUOFF)
/* End #defines for assembler */

#else /* Begin #defines for C */
#define LPM0_bits           (CPUOFF)
#define LPM1_bits           (SCG0+CPUOFF)
#define LPM2_bits           (SCG1+CPUOFF)
#define LPM3_bits           (SCG1+SCG0+CPUOFF)
#define LPM4_bits           (SCG1+SCG0+OSCOFF+CPUOFF)

#include "in430.h"

#define LPM0      __bis_SR_register(LPM0_bits)         /* Enter Low Power Mode 0 */
#define LPM0_EXIT __bic_SR_register_on_exit(LPM0_bits) /* Exit Low Power Mode 0 */
#define LPM1      __bis_SR_register(LPM1_bits)         /* Enter Low Power Mode 1 */
#define LPM1_EXIT __bic_SR_register_on_exit(LPM1_bits) /* Exit Low Power Mode 1 */
#define LPM2      __bis_SR_register(LPM2_bits)         /* Enter Low Power Mode 2 */
#define LPM2_EXIT __bic_SR_register_on_exit(LPM2_bits) /* Exit Low Power Mode 2 */
#define LPM3      __bis_SR_register(LPM3_bits)         /* Enter Low Power Mode 3 */
#define LPM3_EXIT __bic_SR_register_on_exit(LPM3_bits) /* Exit Low Power Mode 3 */
#define LPM4      __bis_SR_register(LPM4_bits)         /* Enter Low Power Mode 4 */
#define LPM4_EXIT __bic_SR_register_on_exit(LPM4_bits) /* Exit Low Power Mode 4 */
#endif /* End #defines for C */

/************************************************************
* CPU
************************************************************/
#define __MSP430_HAS_MSP430XV2_CPU__  /* Definition to show that it has MSP430XV2 CPU */
#define __MSP430FR5XX_6XX_FAMILY__

/************************************************************
* PERIPHERAL FILE MAP
************************************************************/


/************************************************************
* ADC12_B
************************************************************/
#define __MSP430_HAS_ADC12_B__         /* Definition to show that Module is available */
#define __MSP430_BASEADDRESS_ADC12_B__ 0x0800
#define ADC12_B_BASE __MSP430_BASEADDRESS_ADC12_B__

#define ADC12CTL0_            0x0800    /* ADC12 B Control 0 */
sfrb(ADC12CTL0_L , ADC12CTL0_);
sfrb(ADC12CTL0_H , ADC12CTL0_+1);
sfrw(ADC12CTL0, ADC12CTL0_);
#define ADC12CTL1_            0x0802    /* ADC12 B Control 1 */
sfrb(ADC12CTL1_L , ADC12CTL1_);
sfrb(ADC12CTL1_H , ADC12CTL1_+1);
sfrw(ADC12CTL1, ADC12CTL1_);
#define ADC12CTL2_            0x0804    /* ADC12 B Control 2 */
sfrb(ADC12CTL2_L , ADC12CTL2_);
sfrb(ADC12CTL2_H , ADC12CTL2_+1);
sfrw(ADC12CTL2, ADC12CTL2_);
#define ADC12CTL3_            0x0806    /* ADC12 B Control 3 */
sfrb(ADC12CTL3_L , ADC12CTL3_);
sfrb(ADC12CTL3_H , ADC12CTL3_+1);
sfrw(ADC12CTL3, ADC12CTL3_);
#define ADC12LO_              0x0808    /* ADC12 B Window Comparator High Threshold */
sfrb(ADC12LO_L , ADC12LO_);
sfrb(ADC12LO_H , ADC12LO_+1);
sfrw(ADC12LO, ADC12LO_);
#define ADC12HI_              0x080A    /* ADC12 B Window Comparator High Threshold */
sfrb(ADC12HI_L , ADC12HI_);
sfrb(ADC12HI_H , ADC12HI_+1);
sfrw(ADC12HI, ADC12HI_);
#define ADC12IFGR0_           0x080C    /* ADC12 B Interrupt Flag 0 */
sfrb(ADC12IFGR0_L , ADC12IFGR0_);
sfrb(ADC12IFGR0_H , ADC12IFGR0_+1);
sfrw(ADC12IFGR0, ADC12IFGR0_);
#define ADC12IFGR1_           0x080E    /* ADC12 B Interrupt Flag 1 */
sfrb(ADC12IFGR1_L , ADC12IFGR1_);
sfrb(ADC12IFGR1_H , ADC12IFGR1_+1);
sfrw(ADC12IFGR1, ADC12IFGR1_);
#define ADC12IFGR2_           0x0810    /* ADC12 B Interrupt Flag 2 */
sfrb(ADC12IFGR2_L , ADC12IFGR2_);
sfrb(ADC12IFGR2_H , ADC12IFGR2_+1);
sfrw(ADC12IFGR2, ADC12IFGR2_);
#define ADC12IER0_            0x0812    /* ADC12 B Interrupt Enable 0 */
sfrb(ADC12IER0_L , ADC12IER0_);
sfrb(ADC12IER0_H , ADC12IER0_+1);
sfrw(ADC12IER0, ADC12IER0_);
#define ADC12IER1_            0x0814    /* ADC12 B Interrupt Enable 1 */
sfrb(ADC12IER1_L , ADC12IER1_);
sfrb(ADC12IER1_H , ADC12IER1_+1);
sfrw(ADC12IER1, ADC12IER1_);
#define ADC12IER2_            0x0816    /* ADC12 B Interrupt Enable 2 */
sfrb(ADC12IER2_L , ADC12IER2_);
sfrb(ADC12IER2_H , ADC12IER2_+1);
sfrw(ADC12IER2, ADC12IER2_);
#define ADC12IV_              0x0818    /* ADC12 B Interrupt Vector Word */
sfrb(ADC12IV_L , ADC12IV_);
sfrb(ADC12IV_H , ADC12IV_+1);
sfrw(ADC12IV, ADC12IV_);

#define ADC12MCTL0_           0x0820    /* ADC12 Memory Control 0 */
sfrb(ADC12MCTL0_L , ADC12MCTL0_);
sfrb(ADC12MCTL0_H , ADC12MCTL0_+1);
sfrw(ADC12MCTL0, ADC12MCTL0_);
#define ADC12MCTL1_           0x0822    /* ADC12 Memory Control 1 */
sfrb(ADC12MCTL1_L , ADC12MCTL1_);
sfrb(ADC12MCTL1_H , ADC12MCTL1_+1);
sfrw(ADC12MCTL1, ADC12MCTL1_);
#define ADC12MCTL2_           0x0824    /* ADC12 Memory Control 2 */
sfrb(ADC12MCTL2_L , ADC12MCTL2_);
sfrb(ADC12MCTL2_H , ADC12MCTL2_+1);
sfrw(ADC12MCTL2, ADC12MCTL2_);
#define ADC12MCTL3_           0x0826    /* ADC12 Memory Control 3 */
sfrb(ADC12MCTL3_L , ADC12MCTL3_);
sfrb(ADC12MCTL3_H , ADC12MCTL3_+1);
sfrw(ADC12MCTL3, ADC12MCTL3_);
#define ADC12MCTL4_           0x0828    /* ADC12 Memory Control 4 */
sfrb(ADC12MCTL4_L , ADC12MCTL4_);
sfrb(ADC12MCTL4_H , ADC12MCTL4_+1);
sfrw(ADC12MCTL4, ADC12MCTL4_);
#define ADC12MCTL5_           0x082A    /* ADC12 Memory Control 5 */
sfrb(ADC12MCTL5_L , ADC12MCTL5_);
sfrb(ADC12MCTL5_H , ADC12MCTL5_+1);
sfrw(ADC12MCTL5, ADC12MCTL5_);
#define ADC12MCTL6_           0x082C    /* ADC12 Memory Control 6 */
sfrb(ADC12MCTL6_L , ADC12MCTL6_);
sfrb(ADC12MCTL6_H , ADC12MCTL6_+1);
sfrw(ADC12MCTL6, ADC12MCTL6_);
#define ADC12MCTL7_           0x082E    /* ADC12 Memory Control 7 */
sfrb(ADC12MCTL7_L , ADC12MCTL7_);
sfrb(ADC12MCTL7_H , ADC12MCTL7_+1);
sfrw(ADC12MCTL7, ADC12MCTL7_);
#define ADC12MCTL8_           0x0830    /* ADC12 Memory Control 8 */
sfrb(ADC12MCTL8_L , ADC12MCTL8_);
sfrb(ADC12MCTL8_H , ADC12MCTL8_+1);
sfrw(ADC12MCTL8, ADC12MCTL8_);
#define ADC12MCTL9_           0x0832    /* ADC12 Memory Control 9 */
sfrb(ADC12MCTL9_L , ADC12MCTL9_);
sfrb(ADC12MCTL9_H , ADC12MCTL9_+1);
sfrw(ADC12MCTL9, ADC12MCTL9_);
#define ADC12MCTL10_          0x0834    /* ADC12 Memory Control 10 */
sfrb(ADC12MCTL10_L , ADC12MCTL10_);
sfrb(ADC12MCTL10_H , ADC12MCTL10_+1);
sfrw(ADC12MCTL10, ADC12MCTL10_);
#define ADC12MCTL11_          0x0836    /* ADC12 Memory Control 11 */
sfrb(ADC12MCTL11_L , ADC12MCTL11_);
sfrb(ADC12MCTL11_H , ADC12MCTL11_+1);
sfrw(ADC12MCTL11, ADC12MCTL11_);
#define ADC12MCTL12_          0x0838    /* ADC12 Memory Control 12 */
sfrb(ADC12MCTL12_L , ADC12MCTL12_);
sfrb(ADC12MCTL12_H , ADC12MCTL12_+1);
sfrw(ADC12MCTL12, ADC12MCTL12_);
#define ADC12MCTL13_          0x083A    /* ADC12 Memory Control 13 */
sfrb(ADC12MCTL13_L , ADC12MCTL13_);
sfrb(ADC12MCTL13_H , ADC12MCTL13_+1);
sfrw(ADC12MCTL13, ADC12MCTL13_);
#define ADC12MCTL14_          0x083C    /* ADC12 Memory Control 14 */
sfrb(ADC12MCTL14_L , ADC12MCTL14_);
sfrb(ADC12MCTL14_H , ADC12MCTL14_+1);
sfrw(ADC12MCTL14, ADC12MCTL14_);
#define ADC12MCTL15_          0x083E    /* ADC12 Memory Control 15 */
sfrb(ADC12MCTL15_L , ADC12MCTL15_);
sfrb(ADC12MCTL15_H , ADC12MCTL15_+1);
sfrw(ADC12MCTL15, ADC12MCTL15_);
#define ADC12MCTL16_          0x0840    /* ADC12 Memory Control 16 */
sfrb(ADC12MCTL16_L , ADC12MCTL16_);
sfrb(ADC12MCTL16_H , ADC12MCTL16_+1);
sfrw(ADC12MCTL16, ADC12MCTL16_);
#define ADC12MCTL17_          0x0842    /* ADC12 Memory Control 17 */
sfrb(ADC12MCTL17_L , ADC12MCTL17_);
sfrb(ADC12MCTL17_H , ADC12MCTL17_+1);
sfrw(ADC12MCTL17, ADC12MCTL17_);
#define ADC12MCTL18_          0x0844    /* ADC12 Memory Control 18 */
sfrb(ADC12MCTL18_L , ADC12MCTL18_);
sfrb(ADC12MCTL18_H , ADC12MCTL18_+1);
sfrw(ADC12MCTL18, ADC12MCTL18_);
#define ADC12MCTL19_          0x0846    /* ADC12 Memory Control 19 */
sfrb(ADC12MCTL19_L , ADC12MCTL19_);
sfrb(ADC12MCTL19_H , ADC12MCTL19_+1);
sfrw(ADC12MCTL19, ADC12MCTL19_);
#define ADC12MCTL20_          0x0848    /* ADC12 Memory Control 20 */
sfrb(ADC12MCTL20_L , ADC12MCTL20_);
sfrb(ADC12MCTL20_H , ADC12MCTL20_+1);
sfrw(ADC12MCTL20, ADC12MCTL20_);
#define ADC12MCTL21_          0x084A    /* ADC12 Memory Control 21 */
sfrb(ADC12MCTL21_L , ADC12MCTL21_);
sfrb(ADC12MCTL21_H , ADC12MCTL21_+1);
sfrw(ADC12MCTL21, ADC12MCTL21_);
#define ADC12MCTL22_          0x084C    /* ADC12 Memory Control 22 */
sfrb(ADC12MCTL22_L , ADC12MCTL22_);
sfrb(ADC12MCTL22_H , ADC12MCTL22_+1);
sfrw(ADC12MCTL22, ADC12MCTL22_);
#define ADC12MCTL23_          0x084E    /* ADC12 Memory Control 23 */
sfrb(ADC12MCTL23_L , ADC12MCTL23_);
sfrb(ADC12MCTL23_H , ADC12MCTL23_+1);
sfrw(ADC12MCTL23, ADC12MCTL23_);
#define ADC12MCTL24_          0x0850    /* ADC12 Memory Control 24 */
sfrb(ADC12MCTL24_L , ADC12MCTL24_);
sfrb(ADC12MCTL24_H , ADC12MCTL24_+1);
sfrw(ADC12MCTL24, ADC12MCTL24_);
#define ADC12MCTL25_          0x0852    /* ADC12 Memory Control 25 */
sfrb(ADC12MCTL25_L , ADC12MCTL25_);
sfrb(ADC12MCTL25_H , ADC12MCTL25_+1);
sfrw(ADC12MCTL25, ADC12MCTL25_);
#define ADC12MCTL26_          0x0854    /* ADC12 Memory Control 26 */
sfrb(ADC12MCTL26_L , ADC12MCTL26_);
sfrb(ADC12MCTL26_H , ADC12MCTL26_+1);
sfrw(ADC12MCTL26, ADC12MCTL26_);
#define ADC12MCTL27_          0x0856    /* ADC12 Memory Control 27 */
sfrb(ADC12MCTL27_L , ADC12MCTL27_);
sfrb(ADC12MCTL27_H , ADC12MCTL27_+1);
sfrw(ADC12MCTL27, ADC12MCTL27_);
#define ADC12MCTL28_          0x0858    /* ADC12 Memory Control 28 */
sfrb(ADC12MCTL28_L , ADC12MCTL28_);
sfrb(ADC12MCTL28_H , ADC12MCTL28_+1);
sfrw(ADC12MCTL28, ADC12MCTL28_);
#define ADC12MCTL29_          0x085A    /* ADC12 Memory Control 29 */
sfrb(ADC12MCTL29_L , ADC12MCTL29_);
sfrb(ADC12MCTL29_H , ADC12MCTL29_+1);
sfrw(ADC12MCTL29, ADC12MCTL29_);
#define ADC12MCTL30_          0x085C    /* ADC12 Memory Control 30 */
sfrb(ADC12MCTL30_L , ADC12MCTL30_);
sfrb(ADC12MCTL30_H , ADC12MCTL30_+1);
sfrw(ADC12MCTL30, ADC12MCTL30_);
#define ADC12MCTL31_          0x085E    /* ADC12 Memory Control 31 */
sfrb(ADC12MCTL31_L , ADC12MCTL31_);
sfrb(ADC12MCTL31_H , ADC12MCTL31_+1);
sfrw(ADC12MCTL31, ADC12MCTL31_);
#define ADC12MCTL_          ADC12MCTL /* ADC12 Memory Control */
#ifndef __STDC__
#define ADC12MCTL           ADC12MCTL0 /* ADC12 Memory Control (for assembler) */
#else
#define ADC12MCTL           ((volatile char*) &ADC12MCTL0) /* ADC12 Memory Control (for C) */
#endif


#define ADC12MEM0_            0x0860    /* ADC12 Conversion Memory 0 */
sfrb(ADC12MEM0_L , ADC12MEM0_);
sfrb(ADC12MEM0_H , ADC12MEM0_+1);
sfrw(ADC12MEM0, ADC12MEM0_);
#define ADC12MEM1_            0x0862    /* ADC12 Conversion Memory 1 */
sfrb(ADC12MEM1_L , ADC12MEM1_);
sfrb(ADC12MEM1_H , ADC12MEM1_+1);
sfrw(ADC12MEM1, ADC12MEM1_);
#define ADC12MEM2_            0x0864    /* ADC12 Conversion Memory 2 */
sfrb(ADC12MEM2_L , ADC12MEM2_);
sfrb(ADC12MEM2_H , ADC12MEM2_+1);
sfrw(ADC12MEM2, ADC12MEM2_);
#define ADC12MEM3_            0x0866    /* ADC12 Conversion Memory 3 */
sfrb(ADC12MEM3_L , ADC12MEM3_);
sfrb(ADC12MEM3_H , ADC12MEM3_+1);
sfrw(ADC12MEM3, ADC12MEM3_);
#define ADC12MEM4_            0x0868    /* ADC12 Conversion Memory 4 */
sfrb(ADC12MEM4_L , ADC12MEM4_);
sfrb(ADC12MEM4_H , ADC12MEM4_+1);
sfrw(ADC12MEM4, ADC12MEM4_);
#define ADC12MEM5_            0x086A    /* ADC12 Conversion Memory 5 */
sfrb(ADC12MEM5_L , ADC12MEM5_);
sfrb(ADC12MEM5_H , ADC12MEM5_+1);
sfrw(ADC12MEM5, ADC12MEM5_);
#define ADC12MEM6_            0x086C    /* ADC12 Conversion Memory 6 */
sfrb(ADC12MEM6_L , ADC12MEM6_);
sfrb(ADC12MEM6_H , ADC12MEM6_+1);
sfrw(ADC12MEM6, ADC12MEM6_);
#define ADC12MEM7_            0x086E    /* ADC12 Conversion Memory 7 */
sfrb(ADC12MEM7_L , ADC12MEM7_);
sfrb(ADC12MEM7_H , ADC12MEM7_+1);
sfrw(ADC12MEM7, ADC12MEM7_);
#define ADC12MEM8_            0x0870    /* ADC12 Conversion Memory 8 */
sfrb(ADC12MEM8_L , ADC12MEM8_);
sfrb(ADC12MEM8_H , ADC12MEM8_+1);
sfrw(ADC12MEM8, ADC12MEM8_);
#define ADC12MEM9_            0x0872    /* ADC12 Conversion Memory 9 */
sfrb(ADC12MEM9_L , ADC12MEM9_);
sfrb(ADC12MEM9_H , ADC12MEM9_+1);
sfrw(ADC12MEM9, ADC12MEM9_);
#define ADC12MEM10_           0x0874    /* ADC12 Conversion Memory 10 */
sfrb(ADC12MEM10_L , ADC12MEM10_);
sfrb(ADC12MEM10_H , ADC12MEM10_+1);
sfrw(ADC12MEM10, ADC12MEM10_);
#define ADC12MEM11_           0x0876    /* ADC12 Conversion Memory 11 */
sfrb(ADC12MEM11_L , ADC12MEM11_);
sfrb(ADC12MEM11_H , ADC12MEM11_+1);
sfrw(ADC12MEM11, ADC12MEM11_);
#define ADC12MEM12_           0x0878    /* ADC12 Conversion Memory 12 */
sfrb(ADC12MEM12_L , ADC12MEM12_);
sfrb(ADC12MEM12_H , ADC12MEM12_+1);
sfrw(ADC12MEM12, ADC12MEM12_);
#define ADC12MEM13_           0x087A    /* ADC12 Conversion Memory 13 */
sfrb(ADC12MEM13_L , ADC12MEM13_);
sfrb(ADC12MEM13_H , ADC12MEM13_+1);
sfrw(ADC12MEM13, ADC12MEM13_);
#define ADC12MEM14_           0x087C    /* ADC12 Conversion Memory 14 */
sfrb(ADC12MEM14_L , ADC12MEM14_);
sfrb(ADC12MEM14_H , ADC12MEM14_+1);
sfrw(ADC12MEM14, ADC12MEM14_);
#define ADC12MEM15_           0x087E    /* ADC12 Conversion Memory 15 */
sfrb(ADC12MEM15_L , ADC12MEM15_);
sfrb(ADC12MEM15_H , ADC12MEM15_+1);
sfrw(ADC12MEM15, ADC12MEM15_);
#define ADC12MEM16_           0x0880    /* ADC12 Conversion Memory 16 */
sfrb(ADC12MEM16_L , ADC12MEM16_);
sfrb(ADC12MEM16_H , ADC12MEM16_+1);
sfrw(ADC12MEM16, ADC12MEM16_);
#define ADC12MEM17_           0x0882    /* ADC12 Conversion Memory 17 */
sfrb(ADC12MEM17_L , ADC12MEM17_);
sfrb(ADC12MEM17_H , ADC12MEM17_+1);
sfrw(ADC12MEM17, ADC12MEM17_);
#define ADC12MEM18_           0x0884    /* ADC12 Conversion Memory 18 */
sfrb(ADC12MEM18_L , ADC12MEM18_);
sfrb(ADC12MEM18_H , ADC12MEM18_+1);
sfrw(ADC12MEM18, ADC12MEM18_);
#define ADC12MEM19_           0x0886    /* ADC12 Conversion Memory 19 */
sfrb(ADC12MEM19_L , ADC12MEM19_);
sfrb(ADC12MEM19_H , ADC12MEM19_+1);
sfrw(ADC12MEM19, ADC12MEM19_);
#define ADC12MEM20_           0x0888    /* ADC12 Conversion Memory 20 */
sfrb(ADC12MEM20_L , ADC12MEM20_);
sfrb(ADC12MEM20_H , ADC12MEM20_+1);
sfrw(ADC12MEM20, ADC12MEM20_);
#define ADC12MEM21_           0x088A    /* ADC12 Conversion Memory 21 */
sfrb(ADC12MEM21_L , ADC12MEM21_);
sfrb(ADC12MEM21_H , ADC12MEM21_+1);
sfrw(ADC12MEM21, ADC12MEM21_);
#define ADC12MEM22_           0x088C    /* ADC12 Conversion Memory 22 */
sfrb(ADC12MEM22_L , ADC12MEM22_);
sfrb(ADC12MEM22_H , ADC12MEM22_+1);
sfrw(ADC12MEM22, ADC12MEM22_);
#define ADC12MEM23_           0x088E    /* ADC12 Conversion Memory 23 */
sfrb(ADC12MEM23_L , ADC12MEM23_);
sfrb(ADC12MEM23_H , ADC12MEM23_+1);
sfrw(ADC12MEM23, ADC12MEM23_);
#define ADC12MEM24_           0x0890    /* ADC12 Conversion Memory 24 */
sfrb(ADC12MEM24_L , ADC12MEM24_);
sfrb(ADC12MEM24_H , ADC12MEM24_+1);
sfrw(ADC12MEM24, ADC12MEM24_);
#define ADC12MEM25_           0x0892    /* ADC12 Conversion Memory 25 */
sfrb(ADC12MEM25_L , ADC12MEM25_);
sfrb(ADC12MEM25_H , ADC12MEM25_+1);
sfrw(ADC12MEM25, ADC12MEM25_);
#define ADC12MEM26_           0x0894    /* ADC12 Conversion Memory 26 */
sfrb(ADC12MEM26_L , ADC12MEM26_);
sfrb(ADC12MEM26_H , ADC12MEM26_+1);
sfrw(ADC12MEM26, ADC12MEM26_);
#define ADC12MEM27_           0x0896    /* ADC12 Conversion Memory 27 */
sfrb(ADC12MEM27_L , ADC12MEM27_);
sfrb(ADC12MEM27_H , ADC12MEM27_+1);
sfrw(ADC12MEM27, ADC12MEM27_);
#define ADC12MEM28_           0x0898    /* ADC12 Conversion Memory 28 */
sfrb(ADC12MEM28_L , ADC12MEM28_);
sfrb(ADC12MEM28_H , ADC12MEM28_+1);
sfrw(ADC12MEM28, ADC12MEM28_);
#define ADC12MEM29_           0x089A    /* ADC12 Conversion Memory 29 */
sfrb(ADC12MEM29_L , ADC12MEM29_);
sfrb(ADC12MEM29_H , ADC12MEM29_+1);
sfrw(ADC12MEM29, ADC12MEM29_);
#define ADC12MEM30_           0x089C    /* ADC12 Conversion Memory 30 */
sfrb(ADC12MEM30_L , ADC12MEM30_);
sfrb(ADC12MEM30_H , ADC12MEM30_+1);
sfrw(ADC12MEM30, ADC12MEM30_);
#define ADC12MEM31_           0x089E    /* ADC12 Conversion Memory 31 */
sfrb(ADC12MEM31_L , ADC12MEM31_);
sfrb(ADC12MEM31_H , ADC12MEM31_+1);
sfrw(ADC12MEM31, ADC12MEM31_);
#define ADC12MEM_           ADC12MEM  /* ADC12 Conversion Memory */
#ifndef __STDC__
#define ADC12MEM            ADC12MEM0 /* ADC12 Conversion Memory (for assembler) */
#else
#define ADC12MEM            ((volatile int*) &ADC12MEM0) /* ADC12 Conversion Memory (for C) */
#endif


/* ADC12CTL0 Control Bits */
#define ADC12SC             (0x0001)  /* ADC12 Start Conversion */
#define ADC12ENC            (0x0002)  /* ADC12 Enable Conversion */
#define ADC12ON             (0x0010)  /* ADC12 On/enable */
#define ADC12MSC            (0x0080)  /* ADC12 Multiple SampleConversion */
#define ADC12SHT00          (0x0100)  /* ADC12 Sample Hold 0 Select Bit: 0 */
#define ADC12SHT01          (0x0200)  /* ADC12 Sample Hold 0 Select Bit: 1 */
#define ADC12SHT02          (0x0400)  /* ADC12 Sample Hold 0 Select Bit: 2 */
#define ADC12SHT03          (0x0800)  /* ADC12 Sample Hold 0 Select Bit: 3 */
#define ADC12SHT10          (0x1000)  /* ADC12 Sample Hold 1 Select Bit: 0 */
#define ADC12SHT11          (0x2000)  /* ADC12 Sample Hold 1 Select Bit: 1 */
#define ADC12SHT12          (0x4000)  /* ADC12 Sample Hold 1 Select Bit: 2 */
#define ADC12SHT13          (0x8000)  /* ADC12 Sample Hold 1 Select Bit: 3 */

/* ADC12CTL0 Control Bits */
#define ADC12SC_L           (0x0001)  /* ADC12 Start Conversion */
#define ADC12ENC_L          (0x0002)  /* ADC12 Enable Conversion */
#define ADC12ON_L           (0x0010)  /* ADC12 On/enable */
#define ADC12MSC_L          (0x0080)  /* ADC12 Multiple SampleConversion */

/* ADC12CTL0 Control Bits */
#define ADC12SHT00_H        (0x0001)  /* ADC12 Sample Hold 0 Select Bit: 0 */
#define ADC12SHT01_H        (0x0002)  /* ADC12 Sample Hold 0 Select Bit: 1 */
#define ADC12SHT02_H        (0x0004)  /* ADC12 Sample Hold 0 Select Bit: 2 */
#define ADC12SHT03_H        (0x0008)  /* ADC12 Sample Hold 0 Select Bit: 3 */
#define ADC12SHT10_H        (0x0010)  /* ADC12 Sample Hold 1 Select Bit: 0 */
#define ADC12SHT11_H        (0x0020)  /* ADC12 Sample Hold 1 Select Bit: 1 */
#define ADC12SHT12_H        (0x0040)  /* ADC12 Sample Hold 1 Select Bit: 2 */
#define ADC12SHT13_H        (0x0080)  /* ADC12 Sample Hold 1 Select Bit: 3 */

#define ADC12SHT0_0         (0x0000)  /* ADC12 Sample Hold 0 Select Bit: 0 */
#define ADC12SHT0_1         (0x0100)  /* ADC12 Sample Hold 0 Select Bit: 1 */
#define ADC12SHT0_2         (0x0200)  /* ADC12 Sample Hold 0 Select Bit: 2 */
#define ADC12SHT0_3         (0x0300)  /* ADC12 Sample Hold 0 Select Bit: 3 */
#define ADC12SHT0_4         (0x0400)  /* ADC12 Sample Hold 0 Select Bit: 4 */
#define ADC12SHT0_5         (0x0500)  /* ADC12 Sample Hold 0 Select Bit: 5 */
#define ADC12SHT0_6         (0x0600)  /* ADC12 Sample Hold 0 Select Bit: 6 */
#define ADC12SHT0_7         (0x0700)  /* ADC12 Sample Hold 0 Select Bit: 7 */
#define ADC12SHT0_8         (0x0800)  /* ADC12 Sample Hold 0 Select Bit: 8 */
#define ADC12SHT0_9         (0x0900)  /* ADC12 Sample Hold 0 Select Bit: 9 */
#define ADC12SHT0_10        (0x0A00) /* ADC12 Sample Hold 0 Select Bit: 10 */
#define ADC12SHT0_11        (0x0B00) /* ADC12 Sample Hold 0 Select Bit: 11 */
#define ADC12SHT0_12        (0x0C00) /* ADC12 Sample Hold 0 Select Bit: 12 */
#define ADC12SHT0_13        (0x0D00) /* ADC12 Sample Hold 0 Select Bit: 13 */
#define ADC12SHT0_14        (0x0E00) /* ADC12 Sample Hold 0 Select Bit: 14 */
#define ADC12SHT0_15        (0x0F00) /* ADC12 Sample Hold 0 Select Bit: 15 */

#define ADC12SHT1_0         (0x0000)  /* ADC12 Sample Hold 1 Select Bit: 0 */
#define ADC12SHT1_1         (0x1000)  /* ADC12 Sample Hold 1 Select Bit: 1 */
#define ADC12SHT1_2         (0x2000)  /* ADC12 Sample Hold 1 Select Bit: 2 */
#define ADC12SHT1_3         (0x3000)  /* ADC12 Sample Hold 1 Select Bit: 3 */
#define ADC12SHT1_4         (0x4000)  /* ADC12 Sample Hold 1 Select Bit: 4 */
#define ADC12SHT1_5         (0x5000)  /* ADC12 Sample Hold 1 Select Bit: 5 */
#define ADC12SHT1_6         (0x6000)  /* ADC12 Sample Hold 1 Select Bit: 6 */
#define ADC12SHT1_7         (0x7000)  /* ADC12 Sample Hold 1 Select Bit: 7 */
#define ADC12SHT1_8         (0x8000)  /* ADC12 Sample Hold 1 Select Bit: 8 */
#define ADC12SHT1_9         (0x9000)  /* ADC12 Sample Hold 1 Select Bit: 9 */
#define ADC12SHT1_10        (0xA000) /* ADC12 Sample Hold 1 Select Bit: 10 */
#define ADC12SHT1_11        (0xB000) /* ADC12 Sample Hold 1 Select Bit: 11 */
#define ADC12SHT1_12        (0xC000) /* ADC12 Sample Hold 1 Select Bit: 12 */
#define ADC12SHT1_13        (0xD000) /* ADC12 Sample Hold 1 Select Bit: 13 */
#define ADC12SHT1_14        (0xE000) /* ADC12 Sample Hold 1 Select Bit: 14 */
#define ADC12SHT1_15        (0xF000) /* ADC12 Sample Hold 1 Select Bit: 15 */

/* ADC12CTL1 Control Bits */
#define ADC12BUSY           (0x0001)    /* ADC12 Busy */
#define ADC12CONSEQ0        (0x0002)    /* ADC12 Conversion Sequence Select Bit: 0 */
#define ADC12CONSEQ1        (0x0004)    /* ADC12 Conversion Sequence Select Bit: 1 */
#define ADC12SSEL0          (0x0008)    /* ADC12 Clock Source Select Bit: 0 */
#define ADC12SSEL1          (0x0010)    /* ADC12 Clock Source Select Bit: 1 */
#define ADC12DIV0           (0x0020)    /* ADC12 Clock Divider Select Bit: 0 */
#define ADC12DIV1           (0x0040)    /* ADC12 Clock Divider Select Bit: 1 */
#define ADC12DIV2           (0x0080)    /* ADC12 Clock Divider Select Bit: 2 */
#define ADC12ISSH           (0x0100)    /* ADC12 Invert Sample Hold Signal */
#define ADC12SHP            (0x0200)    /* ADC12 Sample/Hold Pulse Mode */
#define ADC12SHS0           (0x0400)    /* ADC12 Sample/Hold Source Bit: 0 */
#define ADC12SHS1           (0x0800)    /* ADC12 Sample/Hold Source Bit: 1 */
#define ADC12SHS2           (0x1000)    /* ADC12 Sample/Hold Source Bit: 2 */
#define ADC12PDIV0          (0x2000)    /* ADC12 Predivider Bit: 0 */
#define ADC12PDIV1          (0x4000)    /* ADC12 Predivider Bit: 1 */

/* ADC12CTL1 Control Bits */
#define ADC12BUSY_L         (0x0001)    /* ADC12 Busy */
#define ADC12CONSEQ0_L      (0x0002)    /* ADC12 Conversion Sequence Select Bit: 0 */
#define ADC12CONSEQ1_L      (0x0004)    /* ADC12 Conversion Sequence Select Bit: 1 */
#define ADC12SSEL0_L        (0x0008)    /* ADC12 Clock Source Select Bit: 0 */
#define ADC12SSEL1_L        (0x0010)    /* ADC12 Clock Source Select Bit: 1 */
#define ADC12DIV0_L         (0x0020)    /* ADC12 Clock Divider Select Bit: 0 */
#define ADC12DIV1_L         (0x0040)    /* ADC12 Clock Divider Select Bit: 1 */
#define ADC12DIV2_L         (0x0080)    /* ADC12 Clock Divider Select Bit: 2 */

/* ADC12CTL1 Control Bits */
#define ADC12ISSH_H         (0x0001)    /* ADC12 Invert Sample Hold Signal */
#define ADC12SHP_H          (0x0002)    /* ADC12 Sample/Hold Pulse Mode */
#define ADC12SHS0_H         (0x0004)    /* ADC12 Sample/Hold Source Bit: 0 */
#define ADC12SHS1_H         (0x0008)    /* ADC12 Sample/Hold Source Bit: 1 */
#define ADC12SHS2_H         (0x0010)    /* ADC12 Sample/Hold Source Bit: 2 */
#define ADC12PDIV0_H        (0x0020)    /* ADC12 Predivider Bit: 0 */
#define ADC12PDIV1_H        (0x0040)    /* ADC12 Predivider Bit: 1 */

#define ADC12CONSEQ_0        (0x0000) /* ADC12 Conversion Sequence Select: 0 */
#define ADC12CONSEQ_1        (0x0002) /* ADC12 Conversion Sequence Select: 1 */
#define ADC12CONSEQ_2        (0x0004) /* ADC12 Conversion Sequence Select: 2 */
#define ADC12CONSEQ_3        (0x0006) /* ADC12 Conversion Sequence Select: 3 */

#define ADC12SSEL_0          (0x0000) /* ADC12 Clock Source Select: 0 */
#define ADC12SSEL_1          (0x0008) /* ADC12 Clock Source Select: 1 */
#define ADC12SSEL_2          (0x0010) /* ADC12 Clock Source Select: 2 */
#define ADC12SSEL_3          (0x0018) /* ADC12 Clock Source Select: 3 */

#define ADC12DIV_0           (0x0000) /* ADC12 Clock Divider Select: 0 */
#define ADC12DIV_1           (0x0020) /* ADC12 Clock Divider Select: 1 */
#define ADC12DIV_2           (0x0040) /* ADC12 Clock Divider Select: 2 */
#define ADC12DIV_3           (0x0060) /* ADC12 Clock Divider Select: 3 */
#define ADC12DIV_4           (0x0080) /* ADC12 Clock Divider Select: 4 */
#define ADC12DIV_5           (0x00A0) /* ADC12 Clock Divider Select: 5 */
#define ADC12DIV_6           (0x00C0) /* ADC12 Clock Divider Select: 6 */
#define ADC12DIV_7           (0x00E0) /* ADC12 Clock Divider Select: 7 */

#define ADC12SHS_0           (0x0000) /* ADC12 Sample/Hold Source: 0 */
#define ADC12SHS_1           (0x0400) /* ADC12 Sample/Hold Source: 1 */
#define ADC12SHS_2           (0x0800) /* ADC12 Sample/Hold Source: 2 */
#define ADC12SHS_3           (0x0C00) /* ADC12 Sample/Hold Source: 3 */
#define ADC12SHS_4           (0x1000) /* ADC12 Sample/Hold Source: 4 */
#define ADC12SHS_5           (0x1400) /* ADC12 Sample/Hold Source: 5 */
#define ADC12SHS_6           (0x1800) /* ADC12 Sample/Hold Source: 6 */
#define ADC12SHS_7           (0x1C00) /* ADC12 Sample/Hold Source: 7 */

#define ADC12PDIV_0          (0x0000) /* ADC12 Clock predivider Select 0 */
#define ADC12PDIV_1          (0x2000) /* ADC12 Clock predivider Select 1 */
#define ADC12PDIV_2          (0x4000) /* ADC12 Clock predivider Select 2 */
#define ADC12PDIV_3          (0x6000) /* ADC12 Clock predivider Select 3 */
#define ADC12PDIV__1         (0x0000) /* ADC12 Clock predivider Select: /1 */
#define ADC12PDIV__4         (0x2000) /* ADC12 Clock predivider Select: /4 */
#define ADC12PDIV__32        (0x4000) /* ADC12 Clock predivider Select: /32 */
#define ADC12PDIV__64        (0x6000) /* ADC12 Clock predivider Select: /64 */

/* ADC12CTL2 Control Bits */
#define ADC12PWRMD          (0x0001)    /* ADC12 Power Mode */
#define ADC12DF             (0x0008)    /* ADC12 Data Format */
#define ADC12RES0           (0x0010)    /* ADC12 Resolution Bit: 0 */
#define ADC12RES1           (0x0020)    /* ADC12 Resolution Bit: 1 */

/* ADC12CTL2 Control Bits */
#define ADC12PWRMD_L        (0x0001)    /* ADC12 Power Mode */
#define ADC12DF_L           (0x0008)    /* ADC12 Data Format */
#define ADC12RES0_L         (0x0010)    /* ADC12 Resolution Bit: 0 */
#define ADC12RES1_L         (0x0020)    /* ADC12 Resolution Bit: 1 */


#define ADC12RES_0          (0x0000)    /* ADC12+ Resolution : 8 Bit */
#define ADC12RES_1          (0x0010)    /* ADC12+ Resolution : 10 Bit */
#define ADC12RES_2          (0x0020)    /* ADC12+ Resolution : 12 Bit */
#define ADC12RES_3          (0x0030)    /* ADC12+ Resolution : reserved */

#define ADC12RES__8BIT      (0x0000)    /* ADC12+ Resolution : 8 Bit */
#define ADC12RES__10BIT     (0x0010)    /* ADC12+ Resolution : 10 Bit */
#define ADC12RES__12BIT     (0x0020)    /* ADC12+ Resolution : 12 Bit */

/* ADC12CTL3 Control Bits */
#define ADC12CSTARTADD0     (0x0001)    /* ADC12 Conversion Start Address Bit: 0 */
#define ADC12CSTARTADD1     (0x0002)    /* ADC12 Conversion Start Address Bit: 1 */
#define ADC12CSTARTADD2     (0x0004)    /* ADC12 Conversion Start Address Bit: 2 */
#define ADC12CSTARTADD3     (0x0008)    /* ADC12 Conversion Start Address Bit: 3 */
#define ADC12CSTARTADD4     (0x0010)    /* ADC12 Conversion Start Address Bit: 4 */
#define ADC12BATMAP         (0x0040)    /* ADC12 Internal AVCC/2 select */
#define ADC12TCMAP          (0x0080)    /* ADC12 Internal TempSensor select */
#define ADC12ICH0MAP        (0x0100)    /* ADC12 Internal Channel 0 select */
#define ADC12ICH1MAP        (0x0200)    /* ADC12 Internal Channel 1 select */
#define ADC12ICH2MAP        (0x0400)    /* ADC12 Internal Channel 2 select */
#define ADC12ICH3MAP        (0x0800)    /* ADC12 Internal Channel 3 select */

/* ADC12CTL3 Control Bits */
#define ADC12CSTARTADD0_L   (0x0001)    /* ADC12 Conversion Start Address Bit: 0 */
#define ADC12CSTARTADD1_L   (0x0002)    /* ADC12 Conversion Start Address Bit: 1 */
#define ADC12CSTARTADD2_L   (0x0004)    /* ADC12 Conversion Start Address Bit: 2 */
#define ADC12CSTARTADD3_L   (0x0008)    /* ADC12 Conversion Start Address Bit: 3 */
#define ADC12CSTARTADD4_L   (0x0010)    /* ADC12 Conversion Start Address Bit: 4 */
#define ADC12BATMAP_L       (0x0040)    /* ADC12 Internal AVCC/2 select */
#define ADC12TCMAP_L        (0x0080)    /* ADC12 Internal TempSensor select */

/* ADC12CTL3 Control Bits */
#define ADC12ICH0MAP_H      (0x0001)    /* ADC12 Internal Channel 0 select */
#define ADC12ICH1MAP_H      (0x0002)    /* ADC12 Internal Channel 1 select */
#define ADC12ICH2MAP_H      (0x0004)    /* ADC12 Internal Channel 2 select */
#define ADC12ICH3MAP_H      (0x0008)    /* ADC12 Internal Channel 3 select */

#define ADC12CSTARTADD_0     ( 0*0x0001) /* ADC12 Conversion Start Address: 0 */
#define ADC12CSTARTADD_1     ( 1*0x0001) /* ADC12 Conversion Start Address: 1 */
#define ADC12CSTARTADD_2     ( 2*0x0001) /* ADC12 Conversion Start Address: 2 */
#define ADC12CSTARTADD_3     ( 3*0x0001) /* ADC12 Conversion Start Address: 3 */
#define ADC12CSTARTADD_4     ( 4*0x0001) /* ADC12 Conversion Start Address: 4 */
#define ADC12CSTARTADD_5     ( 5*0x0001) /* ADC12 Conversion Start Address: 5 */
#define ADC12CSTARTADD_6     ( 6*0x0001) /* ADC12 Conversion Start Address: 6 */
#define ADC12CSTARTADD_7     ( 7*0x0001) /* ADC12 Conversion Start Address: 7 */
#define ADC12CSTARTADD_8     ( 8*0x0001) /* ADC12 Conversion Start Address: 8 */
#define ADC12CSTARTADD_9     ( 9*0x0001) /* ADC12 Conversion Start Address: 9 */
#define ADC12CSTARTADD_10    (0x000A) /* ADC12 Conversion Start Address: 10 */
#define ADC12CSTARTADD_11    (0x000B) /* ADC12 Conversion Start Address: 11 */
#define ADC12CSTARTADD_12    (0x000C) /* ADC12 Conversion Start Address: 12 */
#define ADC12CSTARTADD_13    (0x000D) /* ADC12 Conversion Start Address: 13 */
#define ADC12CSTARTADD_14    (0x000E) /* ADC12 Conversion Start Address: 14 */
#define ADC12CSTARTADD_15    (0x000F) /* ADC12 Conversion Start Address: 15 */
#define ADC12CSTARTADD_16    (0x0010) /* ADC12 Conversion Start Address: 16 */
#define ADC12CSTARTADD_17    (0x0011) /* ADC12 Conversion Start Address: 17 */
#define ADC12CSTARTADD_18    (0x0012) /* ADC12 Conversion Start Address: 18 */
#define ADC12CSTARTADD_19    (0x0013) /* ADC12 Conversion Start Address: 19 */
#define ADC12CSTARTADD_20    (0x0014) /* ADC12 Conversion Start Address: 20 */
#define ADC12CSTARTADD_21    (0x0015) /* ADC12 Conversion Start Address: 21 */
#define ADC12CSTARTADD_22    (0x0016) /* ADC12 Conversion Start Address: 22 */
#define ADC12CSTARTADD_23    (0x0017) /* ADC12 Conversion Start Address: 23 */
#define ADC12CSTARTADD_24    (0x0018) /* ADC12 Conversion Start Address: 24 */
#define ADC12CSTARTADD_25    (0x0019) /* ADC12 Conversion Start Address: 25 */
#define ADC12CSTARTADD_26    (0x001A) /* ADC12 Conversion Start Address: 26 */
#define ADC12CSTARTADD_27    (0x001B) /* ADC12 Conversion Start Address: 27 */
#define ADC12CSTARTADD_28    (0x001C) /* ADC12 Conversion Start Address: 28 */
#define ADC12CSTARTADD_29    (0x001D) /* ADC12 Conversion Start Address: 29 */
#define ADC12CSTARTADD_30    (0x001E) /* ADC12 Conversion Start Address: 30 */
#define ADC12CSTARTADD_31    (0x001F) /* ADC12 Conversion Start Address: 31 */

/* ADC12MCTLx Control Bits */
#define ADC12INCH0          (0x0001)    /* ADC12 Input Channel Select Bit 0 */
#define ADC12INCH1          (0x0002)    /* ADC12 Input Channel Select Bit 1 */
#define ADC12INCH2          (0x0004)    /* ADC12 Input Channel Select Bit 2 */
#define ADC12INCH3          (0x0008)    /* ADC12 Input Channel Select Bit 3 */
#define ADC12INCH4          (0x0010)    /* ADC12 Input Channel Select Bit 4 */
#define ADC12EOS            (0x0080)    /* ADC12 End of Sequence */
#define ADC12VRSEL0         (0x0100)    /* ADC12 VR Select Bit 0 */
#define ADC12VRSEL1         (0x0200)    /* ADC12 VR Select Bit 1 */
#define ADC12VRSEL2         (0x0400)    /* ADC12 VR Select Bit 2 */
#define ADC12VRSEL3         (0x0800)    /* ADC12 VR Select Bit 3 */
#define ADC12DIF            (0x2000)    /* ADC12 Differential mode (only for even Registers) */
#define ADC12WINC           (0x4000)    /* ADC12 Comparator window enable */

/* ADC12MCTLx Control Bits */
#define ADC12INCH0_L        (0x0001)    /* ADC12 Input Channel Select Bit 0 */
#define ADC12INCH1_L        (0x0002)    /* ADC12 Input Channel Select Bit 1 */
#define ADC12INCH2_L        (0x0004)    /* ADC12 Input Channel Select Bit 2 */
#define ADC12INCH3_L        (0x0008)    /* ADC12 Input Channel Select Bit 3 */
#define ADC12INCH4_L        (0x0010)    /* ADC12 Input Channel Select Bit 4 */
#define ADC12EOS_L          (0x0080)    /* ADC12 End of Sequence */

/* ADC12MCTLx Control Bits */
#define ADC12VRSEL0_H       (0x0001)    /* ADC12 VR Select Bit 0 */
#define ADC12VRSEL1_H       (0x0002)    /* ADC12 VR Select Bit 1 */
#define ADC12VRSEL2_H       (0x0004)    /* ADC12 VR Select Bit 2 */
#define ADC12VRSEL3_H       (0x0008)    /* ADC12 VR Select Bit 3 */
#define ADC12DIF_H          (0x0020)    /* ADC12 Differential mode (only for even Registers) */
#define ADC12WINC_H         (0x0040)    /* ADC12 Comparator window enable */




#define ADC12INCH_0         (0x0000)    /* ADC12 Input Channel 0 */
#define ADC12INCH_1         (0x0001)    /* ADC12 Input Channel 1 */
#define ADC12INCH_2         (0x0002)    /* ADC12 Input Channel 2 */
#define ADC12INCH_3         (0x0003)    /* ADC12 Input Channel 3 */
#define ADC12INCH_4         (0x0004)    /* ADC12 Input Channel 4 */
#define ADC12INCH_5         (0x0005)    /* ADC12 Input Channel 5 */
#define ADC12INCH_6         (0x0006)    /* ADC12 Input Channel 6 */
#define ADC12INCH_7         (0x0007)    /* ADC12 Input Channel 7 */
#define ADC12INCH_8         (0x0008)    /* ADC12 Input Channel 8 */
#define ADC12INCH_9         (0x0009)    /* ADC12 Input Channel 9 */
#define ADC12INCH_10        (0x000A)    /* ADC12 Input Channel 10 */
#define ADC12INCH_11        (0x000B)    /* ADC12 Input Channel 11 */
#define ADC12INCH_12        (0x000C)    /* ADC12 Input Channel 12 */
#define ADC12INCH_13        (0x000D)    /* ADC12 Input Channel 13 */
#define ADC12INCH_14        (0x000E)    /* ADC12 Input Channel 14 */
#define ADC12INCH_15        (0x000F)    /* ADC12 Input Channel 15 */
#define ADC12INCH_16        (0x0010)    /* ADC12 Input Channel 16 */
#define ADC12INCH_17        (0x0011)    /* ADC12 Input Channel 17 */
#define ADC12INCH_18        (0x0012)    /* ADC12 Input Channel 18 */
#define ADC12INCH_19        (0x0013)    /* ADC12 Input Channel 19 */
#define ADC12INCH_20        (0x0014)    /* ADC12 Input Channel 20 */
#define ADC12INCH_21        (0x0015)    /* ADC12 Input Channel 21 */
#define ADC12INCH_22        (0x0016)    /* ADC12 Input Channel 22 */
#define ADC12INCH_23        (0x0017)    /* ADC12 Input Channel 23 */
#define ADC12INCH_24        (0x0018)    /* ADC12 Input Channel 24 */
#define ADC12INCH_25        (0x0019)    /* ADC12 Input Channel 25 */
#define ADC12INCH_26        (0x001A)    /* ADC12 Input Channel 26 */
#define ADC12INCH_27        (0x001B)    /* ADC12 Input Channel 27 */
#define ADC12INCH_28        (0x001C)    /* ADC12 Input Channel 28 */
#define ADC12INCH_29        (0x001D)    /* ADC12 Input Channel 29 */
#define ADC12INCH_30        (0x001E)    /* ADC12 Input Channel 30 */
#define ADC12INCH_31        (0x001F)    /* ADC12 Input Channel 31 */

#define ADC12VRSEL_0        (0x0000)    /* ADC12 Select Reference 0 */
#define ADC12VRSEL_1        (0x0100)    /* ADC12 Select Reference 1 */
#define ADC12VRSEL_2        (0x0200)    /* ADC12 Select Reference 2 */
#define ADC12VRSEL_3        (0x0300)    /* ADC12 Select Reference 3 */
#define ADC12VRSEL_4        (0x0400)    /* ADC12 Select Reference 4 */
#define ADC12VRSEL_5        (0x0500)    /* ADC12 Select Reference 5 */
#define ADC12VRSEL_6        (0x0600)    /* ADC12 Select Reference 6 */
#define ADC12VRSEL_7        (0x0700)    /* ADC12 Select Reference 7 */
#define ADC12VRSEL_8        (0x0800)    /* ADC12 Select Reference 8  */
#define ADC12VRSEL_9        (0x0900)    /* ADC12 Select Reference 9  */
#define ADC12VRSEL_10       (0x0A00)   /* ADC12 Select Reference 10 */
#define ADC12VRSEL_11       (0x0B00)   /* ADC12 Select Reference 11 */
#define ADC12VRSEL_12       (0x0C00)   /* ADC12 Select Reference 12 */
#define ADC12VRSEL_13       (0x0D00)   /* ADC12 Select Reference 13 */
#define ADC12VRSEL_14       (0x0E00)   /* ADC12 Select Reference 14 */
#define ADC12VRSEL_15       (0x0F00)   /* ADC12 Select Reference 15 */

/* ADC12HI Control Bits */


/* ADC12LO Control Bits */



/* ADC12IER0 Control Bits */
#define ADC12IE0          (0x0001)  /* ADC12 Memory 0 Interrupt Enable */
#define ADC12IE1          (0x0002)  /* ADC12 Memory 1 Interrupt Enable */
#define ADC12IE2          (0x0004)  /* ADC12 Memory 2 Interrupt Enable */
#define ADC12IE3          (0x0008)  /* ADC12 Memory 3 Interrupt Enable */
#define ADC12IE4          (0x0010)  /* ADC12 Memory 4 Interrupt Enable */
#define ADC12IE5          (0x0020)  /* ADC12 Memory 5 Interrupt Enable */
#define ADC12IE6          (0x0040)  /* ADC12 Memory 6 Interrupt Enable */
#define ADC12IE7          (0x0080)  /* ADC12 Memory 7 Interrupt Enable */
#define ADC12IE8          (0x0100)  /* ADC12 Memory 8 Interrupt Enable */
#define ADC12IE9          (0x0200)  /* ADC12 Memory 9 Interrupt Enable */
#define ADC12IE10          (0x0400)  /* ADC12 Memory 10 Interrupt Enable */
#define ADC12IE11          (0x0800)  /* ADC12 Memory 11 Interrupt Enable */
#define ADC12IE12          (0x1000)  /* ADC12 Memory 12 Interrupt Enable */
#define ADC12IE13          (0x2000)  /* ADC12 Memory 13 Interrupt Enable */
#define ADC12IE14          (0x4000)  /* ADC12 Memory 14 Interrupt Enable */
#define ADC12IE15          (0x8000)  /* ADC12 Memory 15 Interrupt Enable */

/* ADC12IER0 Control Bits */
#define ADC12IE0_L          (0x0001)  /* ADC12 Memory 0 Interrupt Enable */
#define ADC12IE1_L          (0x0002)  /* ADC12 Memory 1 Interrupt Enable */
#define ADC12IE2_L          (0x0004)  /* ADC12 Memory 2 Interrupt Enable */
#define ADC12IE3_L          (0x0008)  /* ADC12 Memory 3 Interrupt Enable */
#define ADC12IE4_L          (0x0010)  /* ADC12 Memory 4 Interrupt Enable */
#define ADC12IE5_L          (0x0020)  /* ADC12 Memory 5 Interrupt Enable */
#define ADC12IE6_L          (0x0040)  /* ADC12 Memory 6 Interrupt Enable */
#define ADC12IE7_L          (0x0080)  /* ADC12 Memory 7 Interrupt Enable */

/* ADC12IER0 Control Bits */
#define ADC12IE8_H          (0x0001)  /* ADC12 Memory 8 Interrupt Enable */
#define ADC12IE9_H          (0x0002)  /* ADC12 Memory 9 Interrupt Enable */
#define ADC12IE10_H         (0x0004)  /* ADC12 Memory 10 Interrupt Enable */
#define ADC12IE11_H         (0x0008)  /* ADC12 Memory 11 Interrupt Enable */
#define ADC12IE12_H         (0x0010)  /* ADC12 Memory 12 Interrupt Enable */
#define ADC12IE13_H         (0x0020)  /* ADC12 Memory 13 Interrupt Enable */
#define ADC12IE14_H         (0x0040)  /* ADC12 Memory 14 Interrupt Enable */
#define ADC12IE15_H         (0x0080)  /* ADC12 Memory 15 Interrupt Enable */

/* ADC12IER1 Control Bits */
#define ADC12IE16          (0x0001)  /* ADC12 Memory 16 Interrupt Enable */
#define ADC12IE17          (0x0002)  /* ADC12 Memory 17 Interrupt Enable */
#define ADC12IE18          (0x0004)  /* ADC12 Memory 18 Interrupt Enable */
#define ADC12IE19          (0x0008)  /* ADC12 Memory 19 Interrupt Enable */
#define ADC12IE20          (0x0010)  /* ADC12 Memory 20 Interrupt Enable */
#define ADC12IE21          (0x0020)  /* ADC12 Memory 21 Interrupt Enable */
#define ADC12IE22          (0x0040)  /* ADC12 Memory 22 Interrupt Enable */
#define ADC12IE23          (0x0080)  /* ADC12 Memory 23 Interrupt Enable */
#define ADC12IE24          (0x0100)  /* ADC12 Memory 24 Interrupt Enable */
#define ADC12IE25          (0x0200)  /* ADC12 Memory 25 Interrupt Enable */
#define ADC12IE26          (0x0400)  /* ADC12 Memory 26 Interrupt Enable */
#define ADC12IE27          (0x0800)  /* ADC12 Memory 27 Interrupt Enable */
#define ADC12IE28          (0x1000)  /* ADC12 Memory 28 Interrupt Enable */
#define ADC12IE29          (0x2000)  /* ADC12 Memory 29 Interrupt Enable */
#define ADC12IE30          (0x4000)  /* ADC12 Memory 30 Interrupt Enable */
#define ADC12IE31          (0x8000)  /* ADC12 Memory 31 Interrupt Enable */

/* ADC12IER1 Control Bits */
#define ADC12IE16_L         (0x0001)  /* ADC12 Memory 16 Interrupt Enable */
#define ADC12IE17_L         (0x0002)  /* ADC12 Memory 17 Interrupt Enable */
#define ADC12IE18_L         (0x0004)  /* ADC12 Memory 18 Interrupt Enable */
#define ADC12IE19_L         (0x0008)  /* ADC12 Memory 19 Interrupt Enable */
#define ADC12IE20_L         (0x0010)  /* ADC12 Memory 20 Interrupt Enable */
#define ADC12IE21_L         (0x0020)  /* ADC12 Memory 21 Interrupt Enable */
#define ADC12IE22_L         (0x0040)  /* ADC12 Memory 22 Interrupt Enable */
#define ADC12IE23_L         (0x0080)  /* ADC12 Memory 23 Interrupt Enable */

/* ADC12IER1 Control Bits */
#define ADC12IE24_H         (0x0001)  /* ADC12 Memory 24 Interrupt Enable */
#define ADC12IE25_H         (0x0002)  /* ADC12 Memory 25 Interrupt Enable */
#define ADC12IE26_H         (0x0004)  /* ADC12 Memory 26 Interrupt Enable */
#define ADC12IE27_H         (0x0008)  /* ADC12 Memory 27 Interrupt Enable */
#define ADC12IE28_H         (0x0010)  /* ADC12 Memory 28 Interrupt Enable */
#define ADC12IE29_H         (0x0020)  /* ADC12 Memory 29 Interrupt Enable */
#define ADC12IE30_H         (0x0040)  /* ADC12 Memory 30 Interrupt Enable */
#define ADC12IE31_H         (0x0080)  /* ADC12 Memory 31 Interrupt Enable */

/* ADC12IER2 Control Bits */
#define ADC12INIE           (0x0002)    /* ADC12 Interrupt enable for the inside of window of the Window comparator */
#define ADC12LOIE           (0x0004)    /* ADC12 Interrupt enable for lower threshold of the Window comparator */
#define ADC12HIIE           (0x0008)    /* ADC12 Interrupt enable for upper threshold of the Window comparator */
#define ADC12OVIE           (0x0010)    /* ADC12 ADC12MEMx Overflow interrupt enable */
#define ADC12TOVIE          (0x0020)    /* ADC12 Timer Overflow interrupt enable */
#define ADC12RDYIE          (0x0040)    /* ADC12 local buffered reference ready interrupt enable */

/* ADC12IER2 Control Bits */
#define ADC12INIE_L         (0x0002)    /* ADC12 Interrupt enable for the inside of window of the Window comparator */
#define ADC12LOIE_L         (0x0004)    /* ADC12 Interrupt enable for lower threshold of the Window comparator */
#define ADC12HIIE_L         (0x0008)    /* ADC12 Interrupt enable for upper threshold of the Window comparator */
#define ADC12OVIE_L         (0x0010)    /* ADC12 ADC12MEMx Overflow interrupt enable */
#define ADC12TOVIE_L        (0x0020)    /* ADC12 Timer Overflow interrupt enable */
#define ADC12RDYIE_L        (0x0040)    /* ADC12 local buffered reference ready interrupt enable */


/* ADC12IFGR0 Control Bits */
#define ADC12IFG0          (0x0001)  /* ADC12 Memory 0 Interrupt Flag */
#define ADC12IFG1          (0x0002)  /* ADC12 Memory 1 Interrupt Flag */
#define ADC12IFG2          (0x0004)  /* ADC12 Memory 2 Interrupt Flag */
#define ADC12IFG3          (0x0008)  /* ADC12 Memory 3 Interrupt Flag */
#define ADC12IFG4          (0x0010)  /* ADC12 Memory 4 Interrupt Flag */
#define ADC12IFG5          (0x0020)  /* ADC12 Memory 5 Interrupt Flag */
#define ADC12IFG6          (0x0040)  /* ADC12 Memory 6 Interrupt Flag */
#define ADC12IFG7          (0x0080)  /* ADC12 Memory 7 Interrupt Flag */
#define ADC12IFG8          (0x0100)  /* ADC12 Memory 8 Interrupt Flag */
#define ADC12IFG9          (0x0200)  /* ADC12 Memory 9 Interrupt Flag */
#define ADC12IFG10          (0x0400)  /* ADC12 Memory 10 Interrupt Flag */
#define ADC12IFG11          (0x0800)  /* ADC12 Memory 11 Interrupt Flag */
#define ADC12IFG12          (0x1000)  /* ADC12 Memory 12 Interrupt Flag */
#define ADC12IFG13          (0x2000)  /* ADC12 Memory 13 Interrupt Flag */
#define ADC12IFG14          (0x4000)  /* ADC12 Memory 14 Interrupt Flag */
#define ADC12IFG15          (0x8000)  /* ADC12 Memory 15 Interrupt Flag */

/* ADC12IFGR0 Control Bits */
#define ADC12IFG0_L         (0x0001)  /* ADC12 Memory 0 Interrupt Flag */
#define ADC12IFG1_L         (0x0002)  /* ADC12 Memory 1 Interrupt Flag */
#define ADC12IFG2_L         (0x0004)  /* ADC12 Memory 2 Interrupt Flag */
#define ADC12IFG3_L         (0x0008)  /* ADC12 Memory 3 Interrupt Flag */
#define ADC12IFG4_L         (0x0010)  /* ADC12 Memory 4 Interrupt Flag */
#define ADC12IFG5_L         (0x0020)  /* ADC12 Memory 5 Interrupt Flag */
#define ADC12IFG6_L         (0x0040)  /* ADC12 Memory 6 Interrupt Flag */
#define ADC12IFG7_L         (0x0080)  /* ADC12 Memory 7 Interrupt Flag */

/* ADC12IFGR0 Control Bits */
#define ADC12IFG8_H         (0x0001)  /* ADC12 Memory 8 Interrupt Flag */
#define ADC12IFG9_H         (0x0002)  /* ADC12 Memory 9 Interrupt Flag */
#define ADC12IFG10_H        (0x0004)  /* ADC12 Memory 10 Interrupt Flag */
#define ADC12IFG11_H        (0x0008)  /* ADC12 Memory 11 Interrupt Flag */
#define ADC12IFG12_H        (0x0010)  /* ADC12 Memory 12 Interrupt Flag */
#define ADC12IFG13_H        (0x0020)  /* ADC12 Memory 13 Interrupt Flag */
#define ADC12IFG14_H        (0x0040)  /* ADC12 Memory 14 Interrupt Flag */
#define ADC12IFG15_H        (0x0080)  /* ADC12 Memory 15 Interrupt Flag */

/* ADC12IFGR1 Control Bits */
#define ADC12IFG16          (0x0001)  /* ADC12 Memory 16 Interrupt Flag */
#define ADC12IFG17          (0x0002)  /* ADC12 Memory 17 Interrupt Flag */
#define ADC12IFG18          (0x0004)  /* ADC12 Memory 18 Interrupt Flag */
#define ADC12IFG19          (0x0008)  /* ADC12 Memory 19 Interrupt Flag */
#define ADC12IFG20          (0x0010)  /* ADC12 Memory 20 Interrupt Flag */
#define ADC12IFG21          (0x0020)  /* ADC12 Memory 21 Interrupt Flag */
#define ADC12IFG22          (0x0040)  /* ADC12 Memory 22 Interrupt Flag */
#define ADC12IFG23          (0x0080)  /* ADC12 Memory 23 Interrupt Flag */
#define ADC12IFG24          (0x0100)  /* ADC12 Memory 24 Interrupt Flag */
#define ADC12IFG25          (0x0200)  /* ADC12 Memory 25 Interrupt Flag */
#define ADC12IFG26          (0x0400)  /* ADC12 Memory 26 Interrupt Flag */
#define ADC12IFG27          (0x0800)  /* ADC12 Memory 27 Interrupt Flag */
#define ADC12IFG28          (0x1000)  /* ADC12 Memory 28 Interrupt Flag */
#define ADC12IFG29          (0x2000)  /* ADC12 Memory 29 Interrupt Flag */
#define ADC12IFG30          (0x4000)  /* ADC12 Memory 30 Interrupt Flag */
#define ADC12IFG31          (0x8000)  /* ADC12 Memory 31 Interrupt Flag */

/* ADC12IFGR1 Control Bits */
#define ADC12IFG16_L        (0x0001)  /* ADC12 Memory 16 Interrupt Flag */
#define ADC12IFG17_L        (0x0002)  /* ADC12 Memory 17 Interrupt Flag */
#define ADC12IFG18_L        (0x0004)  /* ADC12 Memory 18 Interrupt Flag */
#define ADC12IFG19_L        (0x0008)  /* ADC12 Memory 19 Interrupt Flag */
#define ADC12IFG20_L        (0x0010)  /* ADC12 Memory 20 Interrupt Flag */
#define ADC12IFG21_L        (0x0020)  /* ADC12 Memory 21 Interrupt Flag */
#define ADC12IFG22_L        (0x0040)  /* ADC12 Memory 22 Interrupt Flag */
#define ADC12IFG23_L        (0x0080)  /* ADC12 Memory 23 Interrupt Flag */

/* ADC12IFGR1 Control Bits */
#define ADC12IFG24_H        (0x0001)  /* ADC12 Memory 24 Interrupt Flag */
#define ADC12IFG25_H        (0x0002)  /* ADC12 Memory 25 Interrupt Flag */
#define ADC12IFG26_H        (0x0004)  /* ADC12 Memory 26 Interrupt Flag */
#define ADC12IFG27_H        (0x0008)  /* ADC12 Memory 27 Interrupt Flag */
#define ADC12IFG28_H        (0x0010)  /* ADC12 Memory 28 Interrupt Flag */
#define ADC12IFG29_H        (0x0020)  /* ADC12 Memory 29 Interrupt Flag */
#define ADC12IFG30_H        (0x0040)  /* ADC12 Memory 30 Interrupt Flag */
#define ADC12IFG31_H        (0x0080)  /* ADC12 Memory 31 Interrupt Flag */

/* ADC12IFGR2 Control Bits */
#define ADC12INIFG          (0x0002)    /* ADC12 Interrupt Flag for the inside of window of the Window comparator */
#define ADC12LOIFG          (0x0004)    /* ADC12 Interrupt Flag for lower threshold of the Window comparator */
#define ADC12HIIFG          (0x0008)    /* ADC12 Interrupt Flag for upper threshold of the Window comparator */
#define ADC12OVIFG          (0x0010)    /* ADC12 ADC12MEMx Overflow interrupt Flag */
#define ADC12TOVIFG         (0x0020)    /* ADC12 Timer Overflow interrupt Flag */
#define ADC12RDYIFG         (0x0040)    /* ADC12 local buffered reference ready interrupt Flag */

/* ADC12IFGR2 Control Bits */
#define ADC12INIFG_L        (0x0002)    /* ADC12 Interrupt Flag for the inside of window of the Window comparator */
#define ADC12LOIFG_L        (0x0004)    /* ADC12 Interrupt Flag for lower threshold of the Window comparator */
#define ADC12HIIFG_L        (0x0008)    /* ADC12 Interrupt Flag for upper threshold of the Window comparator */
#define ADC12OVIFG_L        (0x0010)    /* ADC12 ADC12MEMx Overflow interrupt Flag */
#define ADC12TOVIFG_L       (0x0020)    /* ADC12 Timer Overflow interrupt Flag */
#define ADC12RDYIFG_L       (0x0040)    /* ADC12 local buffered reference ready interrupt Flag */


/* ADC12IV Definitions */
#define ADC12IV_NONE        (0x0000)    /* No Interrupt pending */
#define ADC12IV_ADC12OVIFG  (0x0002)    /* ADC12OVIFG */
#define ADC12IV_ADC12TOVIFG (0x0004)    /* ADC12TOVIFG */
#define ADC12IV_ADC12HIIFG  (0x0006)    /* ADC12HIIFG */
#define ADC12IV_ADC12LOIFG  (0x0008)    /* ADC12LOIFG */
#define ADC12IV_ADC12INIFG  (0x000A)    /* ADC12INIFG */
#define ADC12IV_ADC12IFG0   (0x000C)    /* ADC12IFG0 */
#define ADC12IV_ADC12IFG1   (0x000E)    /* ADC12IFG1 */
#define ADC12IV_ADC12IFG2   (0x0010)    /* ADC12IFG2 */
#define ADC12IV_ADC12IFG3   (0x0012)    /* ADC12IFG3 */
#define ADC12IV_ADC12IFG4   (0x0014)    /* ADC12IFG4 */
#define ADC12IV_ADC12IFG5   (0x0016)    /* ADC12IFG5 */
#define ADC12IV_ADC12IFG6   (0x0018)    /* ADC12IFG6 */
#define ADC12IV_ADC12IFG7   (0x001A)    /* ADC12IFG7 */
#define ADC12IV_ADC12IFG8   (0x001C)    /* ADC12IFG8 */
#define ADC12IV_ADC12IFG9   (0x001E)    /* ADC12IFG9 */
#define ADC12IV_ADC12IFG10  (0x0020)    /* ADC12IFG10 */
#define ADC12IV_ADC12IFG11  (0x0022)    /* ADC12IFG11 */
#define ADC12IV_ADC12IFG12  (0x0024)    /* ADC12IFG12 */
#define ADC12IV_ADC12IFG13  (0x0026)    /* ADC12IFG13 */
#define ADC12IV_ADC12IFG14  (0x0028)    /* ADC12IFG14 */
#define ADC12IV_ADC12IFG15  (0x002A)    /* ADC12IFG15 */
#define ADC12IV_ADC12IFG16  (0x002C)    /* ADC12IFG16 */
#define ADC12IV_ADC12IFG17  (0x002E)    /* ADC12IFG17 */
#define ADC12IV_ADC12IFG18  (0x0030)    /* ADC12IFG18 */
#define ADC12IV_ADC12IFG19  (0x0032)    /* ADC12IFG19 */
#define ADC12IV_ADC12IFG20  (0x0034)    /* ADC12IFG20 */
#define ADC12IV_ADC12IFG21  (0x0036)    /* ADC12IFG21 */
#define ADC12IV_ADC12IFG22  (0x0038)    /* ADC12IFG22 */
#define ADC12IV_ADC12IFG23  (0x003A)    /* ADC12IFG23 */
#define ADC12IV_ADC12IFG24  (0x003C)    /* ADC12IFG24 */
#define ADC12IV_ADC12IFG25  (0x003E)    /* ADC12IFG25 */
#define ADC12IV_ADC12IFG26  (0x0040)    /* ADC12IFG26 */
#define ADC12IV_ADC12IFG27  (0x0042)    /* ADC12IFG27 */
#define ADC12IV_ADC12IFG28  (0x0044)    /* ADC12IFG28 */
#define ADC12IV_ADC12IFG29  (0x0046)    /* ADC12IFG29 */
#define ADC12IV_ADC12IFG30  (0x0048)    /* ADC12IFG30 */
#define ADC12IV_ADC12IFG31  (0x004A)    /* ADC12IFG31 */
#define ADC12IV_ADC12RDYIFG (0x004C)    /* ADC12RDYIFG */


/************************************************************
* AES256 Accelerator
************************************************************/
#define __MSP430_HAS_AES256__          /* Definition to show that Module is available */
#define __MSP430_BASEADDRESS_AES256__ 0x09C0
#define AES256_BASE __MSP430_BASEADDRESS_AES256__

#define AESACTL0_             0x09C0    /* AES accelerator control register 0 */
sfrb(AESACTL0_L , AESACTL0_);
sfrb(AESACTL0_H , AESACTL0_+1);
sfrw(AESACTL0, AESACTL0_);
#define AESACTL1_             0x09C2    /* AES accelerator control register 1 */
sfrb(AESACTL1_L , AESACTL1_);
sfrb(AESACTL1_H , AESACTL1_+1);
sfrw(AESACTL1, AESACTL1_);
#define AESASTAT_             0x09C4    /* AES accelerator status register */
sfrb(AESASTAT_L , AESASTAT_);
sfrb(AESASTAT_H , AESASTAT_+1);
sfrw(AESASTAT, AESASTAT_);
#define AESAKEY_              0x09C6    /* AES accelerator key register */
sfrb(AESAKEY_L , AESAKEY_);
sfrb(AESAKEY_H , AESAKEY_+1);
sfrw(AESAKEY, AESAKEY_);
#define AESADIN_              0x09C8    /* AES accelerator data in register */
sfrb(AESADIN_L , AESADIN_);
sfrb(AESADIN_H , AESADIN_+1);
sfrw(AESADIN, AESADIN_);
#define AESADOUT_             0x09CA    /* AES accelerator data out register  */
sfrb(AESADOUT_L , AESADOUT_);
sfrb(AESADOUT_H , AESADOUT_+1);
sfrw(AESADOUT, AESADOUT_);
#define AESAXDIN_             0x09CC    /* AES accelerator XORed data in register */
sfrb(AESAXDIN_L , AESAXDIN_);
sfrb(AESAXDIN_H , AESAXDIN_+1);
sfrw(AESAXDIN, AESAXDIN_);
#define AESAXIN_              0x09CE    /* AES accelerator XORed data in register (no trigger)  */
sfrb(AESAXIN_L , AESAXIN_);
sfrb(AESAXIN_H , AESAXIN_+1);
sfrw(AESAXIN, AESAXIN_);


/* AESACTL0 Control Bits */
#define AESOP0              (0x0001)  /* AES Operation Bit: 0 */
#define AESOP1              (0x0002)  /* AES Operation Bit: 1 */
#define AESKL0              (0x0004)  /* AES Key length Bit: 0 */
#define AESKL1              (0x0008)  /* AES Key length Bit: 1 */
#define AESTRIG             (0x0010)  /* AES Trigger Select */
#define AESCM0              (0x0020)  /* AES Cipher mode select Bit: 0 */
#define AESCM1              (0x0040)  /* AES Cipher mode select Bit: 1 */
#define AESSWRST            (0x0080)  /* AES Software Reset */
#define AESRDYIFG           (0x0100)  /* AES ready interrupt flag */
#define AESERRFG            (0x0800)  /* AES Error Flag */
#define AESRDYIE            (0x1000)  /* AES ready interrupt enable*/
#define AESCMEN             (0x8000)  /* AES DMA cipher mode enable*/

/* AESACTL0 Control Bits */
#define AESOP0_L            (0x0001)  /* AES Operation Bit: 0 */
#define AESOP1_L            (0x0002)  /* AES Operation Bit: 1 */
#define AESKL0_L            (0x0004)  /* AES Key length Bit: 0 */
#define AESKL1_L            (0x0008)  /* AES Key length Bit: 1 */
#define AESTRIG_L           (0x0010)  /* AES Trigger Select */
#define AESCM0_L            (0x0020)  /* AES Cipher mode select Bit: 0 */
#define AESCM1_L            (0x0040)  /* AES Cipher mode select Bit: 1 */
#define AESSWRST_L          (0x0080)  /* AES Software Reset */

/* AESACTL0 Control Bits */
#define AESRDYIFG_H         (0x0001)  /* AES ready interrupt flag */
#define AESERRFG_H          (0x0008)  /* AES Error Flag */
#define AESRDYIE_H          (0x0010)  /* AES ready interrupt enable*/
#define AESCMEN_H           (0x0080)  /* AES DMA cipher mode enable*/

#define AESOP_0             (0x0000)  /* AES Operation: Encrypt */
#define AESOP_1             (0x0001)  /* AES Operation: Decrypt (same Key) */
#define AESOP_2             (0x0002)  /* AES Operation: Decrypt (frist round Key) */
#define AESOP_3             (0x0003)  /* AES Operation: Generate first round Key */

#define AESKL_0             (0x0000)  /* AES Key length: AES128 */
#define AESKL_1             (0x0004)  /* AES Key length: AES192 */
#define AESKL_2             (0x0008)  /* AES Key length: AES256 */
#define AESKL__128          (0x0000)  /* AES Key length: AES128 */
#define AESKL__192          (0x0004)  /* AES Key length: AES192 */
#define AESKL__256          (0x0008)  /* AES Key length: AES256 */

#define AESCM_0             (0x0000)  /* AES Cipher mode select: ECB */
#define AESCM_1             (0x0020)  /* AES Cipher mode select: CBC */
#define AESCM_2             (0x0040)  /* AES Cipher mode select: OFB */
#define AESCM_3             (0x0060)  /* AES Cipher mode select: CFB */
#define AESCM__ECB          (0x0000)  /* AES Cipher mode select: ECB */
#define AESCM__CBC          (0x0020)  /* AES Cipher mode select: CBC */
#define AESCM__OFB          (0x0040)  /* AES Cipher mode select: OFB */
#define AESCM__CFB          (0x0060)  /* AES Cipher mode select: CFB */


/* AESACTL1 Control Bits */
#define AESBLKCNT0          (0x0001)  /* AES Cipher Block Counter Bit: 0 */
#define AESBLKCNT1          (0x0002)  /* AES Cipher Block Counter Bit: 1 */
#define AESBLKCNT2          (0x0004)  /* AES Cipher Block Counter Bit: 2 */
#define AESBLKCNT3          (0x0008)  /* AES Cipher Block Counter Bit: 3 */
#define AESBLKCNT4          (0x0010)  /* AES Cipher Block Counter Bit: 4 */
#define AESBLKCNT5          (0x0020)  /* AES Cipher Block Counter Bit: 5 */
#define AESBLKCNT6          (0x0040)  /* AES Cipher Block Counter Bit: 6 */
#define AESBLKCNT7          (0x0080)  /* AES Cipher Block Counter Bit: 7 */

/* AESACTL1 Control Bits */
#define AESBLKCNT0_L        (0x0001)  /* AES Cipher Block Counter Bit: 0 */
#define AESBLKCNT1_L        (0x0002)  /* AES Cipher Block Counter Bit: 1 */
#define AESBLKCNT2_L        (0x0004)  /* AES Cipher Block Counter Bit: 2 */
#define AESBLKCNT3_L        (0x0008)  /* AES Cipher Block Counter Bit: 3 */
#define AESBLKCNT4_L        (0x0010)  /* AES Cipher Block Counter Bit: 4 */
#define AESBLKCNT5_L        (0x0020)  /* AES Cipher Block Counter Bit: 5 */
#define AESBLKCNT6_L        (0x0040)  /* AES Cipher Block Counter Bit: 6 */
#define AESBLKCNT7_L        (0x0080)  /* AES Cipher Block Counter Bit: 7 */


/* AESASTAT Control Bits */
#define AESBUSY             (0x0001)  /* AES Busy */
#define AESKEYWR            (0x0002)  /* AES All 16 bytes written to AESAKEY */
#define AESDINWR            (0x0004)  /* AES All 16 bytes written to AESADIN */
#define AESDOUTRD           (0x0008)  /* AES All 16 bytes read from AESADOUT */
#define AESKEYCNT0          (0x0010)  /* AES Bytes written via AESAKEY Bit: 0 */
#define AESKEYCNT1          (0x0020)  /* AES Bytes written via AESAKEY Bit: 1 */
#define AESKEYCNT2          (0x0040)  /* AES Bytes written via AESAKEY Bit: 2 */
#define AESKEYCNT3          (0x0080)  /* AES Bytes written via AESAKEY Bit: 3 */
#define AESDINCNT0          (0x0100)  /* AES Bytes written via AESADIN Bit: 0 */
#define AESDINCNT1          (0x0200)  /* AES Bytes written via AESADIN Bit: 1 */
#define AESDINCNT2          (0x0400)  /* AES Bytes written via AESADIN Bit: 2 */
#define AESDINCNT3          (0x0800)  /* AES Bytes written via AESADIN Bit: 3 */
#define AESDOUTCNT0         (0x1000)  /* AES Bytes read via AESADOUT Bit: 0 */
#define AESDOUTCNT1         (0x2000)  /* AES Bytes read via AESADOUT Bit: 1 */
#define AESDOUTCNT2         (0x4000)  /* AES Bytes read via AESADOUT Bit: 2 */
#define AESDOUTCNT3         (0x8000)  /* AES Bytes read via AESADOUT Bit: 3 */

/* AESASTAT Control Bits */
#define AESBUSY_L           (0x0001)  /* AES Busy */
#define AESKEYWR_L          (0x0002)  /* AES All 16 bytes written to AESAKEY */
#define AESDINWR_L          (0x0004)  /* AES All 16 bytes written to AESADIN */
#define AESDOUTRD_L         (0x0008)  /* AES All 16 bytes read from AESADOUT */
#define AESKEYCNT0_L        (0x0010)  /* AES Bytes written via AESAKEY Bit: 0 */
#define AESKEYCNT1_L        (0x0020)  /* AES Bytes written via AESAKEY Bit: 1 */
#define AESKEYCNT2_L        (0x0040)  /* AES Bytes written via AESAKEY Bit: 2 */
#define AESKEYCNT3_L        (0x0080)  /* AES Bytes written via AESAKEY Bit: 3 */

/* AESASTAT Control Bits */
#define AESDINCNT0_H        (0x0001)  /* AES Bytes written via AESADIN Bit: 0 */
#define AESDINCNT1_H        (0x0002)  /* AES Bytes written via AESADIN Bit: 1 */
#define AESDINCNT2_H        (0x0004)  /* AES Bytes written via AESADIN Bit: 2 */
#define AESDINCNT3_H        (0x0008)  /* AES Bytes written via AESADIN Bit: 3 */
#define AESDOUTCNT0_H       (0x0010)  /* AES Bytes read via AESADOUT Bit: 0 */
#define AESDOUTCNT1_H       (0x0020)  /* AES Bytes read via AESADOUT Bit: 1 */
#define AESDOUTCNT2_H       (0x0040)  /* AES Bytes read via AESADOUT Bit: 2 */
#define AESDOUTCNT3_H       (0x0080)  /* AES Bytes read via AESADOUT Bit: 3 */

/************************************************************
* Capacitive_Touch_IO 0
************************************************************/
#define __MSP430_HAS_CAP_TOUCH_IO_0__ /* Definition to show that Module is available */
#define __MSP430_BASEADDRESS_CAP_TOUCH_IO_0__ 0x0430
#define CAP_TOUCH_0_BASE __MSP430_BASEADDRESS_CAP_TOUCH_IO_0__

#define CAPTIO0CTL_           0x043E    /* Capacitive_Touch_IO 0 control register */
sfrb(CAPTIO0CTL_L , CAPTIO0CTL_);
sfrb(CAPTIO0CTL_H , CAPTIO0CTL_+1);
sfrw(CAPTIO0CTL, CAPTIO0CTL_);

#define  CAPSIO0CTL         CAPTIO0CTL  /* legacy define */

/************************************************************
* Capacitive_Touch_IO 1
************************************************************/
#define __MSP430_HAS_CAP_TOUCH_IO_1__ /* Definition to show that Module is available */
#define __MSP430_BASEADDRESS_CAP_TOUCH_IO_1__ 0x0470
#define CAP_TOUCH_1_BASE __MSP430_BASEADDRESS_CAP_TOUCH_IO_1__

#define CAPTIO1CTL_           0x047E    /* Capacitive_Touch_IO 1 control register */
sfrb(CAPTIO1CTL_L , CAPTIO1CTL_);
sfrb(CAPTIO1CTL_H , CAPTIO1CTL_+1);
sfrw(CAPTIO1CTL, CAPTIO1CTL_);

#define  CAPSIO1CTL         CAPTIO1CTL  /* legacy define */

/* CAPTIOxCTL Control Bits */
#define CAPTIOPISEL0         (0x0002)    /* CapTouchIO Pin Select Bit: 0 */
#define CAPTIOPISEL1         (0x0004)    /* CapTouchIO Pin Select Bit: 1 */
#define CAPTIOPISEL2         (0x0008)    /* CapTouchIO Pin Select Bit: 2 */
#define CAPTIOPOSEL0         (0x0010)    /* CapTouchIO Port Select Bit: 0 */
#define CAPTIOPOSEL1         (0x0020)    /* CapTouchIO Port Select Bit: 1 */
#define CAPTIOPOSEL2         (0x0040)    /* CapTouchIO Port Select Bit: 2 */
#define CAPTIOPOSEL3         (0x0080)    /* CapTouchIO Port Select Bit: 3 */
#define CAPTIOEN             (0x0100)    /* CapTouchIO Enable */
#define CAPTIO               (0x0200)    /* CapTouchIO state */

/* CAPTIOxCTL Control Bits */
#define CAPTIOPISEL0_L      (0x0002)    /* CapTouchIO Pin Select Bit: 0 */
#define CAPTIOPISEL1_L      (0x0004)    /* CapTouchIO Pin Select Bit: 1 */
#define CAPTIOPISEL2_L      (0x0008)    /* CapTouchIO Pin Select Bit: 2 */
#define CAPTIOPOSEL0_L      (0x0010)    /* CapTouchIO Port Select Bit: 0 */
#define CAPTIOPOSEL1_L      (0x0020)    /* CapTouchIO Port Select Bit: 1 */
#define CAPTIOPOSEL2_L      (0x0040)    /* CapTouchIO Port Select Bit: 2 */
#define CAPTIOPOSEL3_L      (0x0080)    /* CapTouchIO Port Select Bit: 3 */

/* CAPTIOxCTL Control Bits */
#define CAPTIOEN_H          (0x0001)    /* CapTouchIO Enable */
#define CAPTIO_H            (0x0002)    /* CapTouchIO state */

/* Legacy defines */
#define CAPSIOPISEL0         (0x0002)    /* CapTouchIO Pin Select Bit: 0 */
#define CAPSIOPISEL1         (0x0004)    /* CapTouchIO Pin Select Bit: 1 */
#define CAPSIOPISEL2         (0x0008)    /* CapTouchIO Pin Select Bit: 2 */
#define CAPSIOPOSEL0         (0x0010)    /* CapTouchIO Port Select Bit: 0 */
#define CAPSIOPOSEL1         (0x0020)    /* CapTouchIO Port Select Bit: 1 */
#define CAPSIOPOSEL2         (0x0040)    /* CapTouchIO Port Select Bit: 2 */
#define CAPSIOPOSEL3         (0x0080)    /* CapTouchIO Port Select Bit: 3 */
#define CAPSIOEN             (0x0100)    /* CapTouchIO Enable */
#define CAPSIO               (0x0200)    /* CapTouchIO state */

/************************************************************
* Comparator E
************************************************************/
#define __MSP430_HAS_COMP_E__          /* Definition to show that Module is available */
#define __MSP430_BASEADDRESS_COMP_E__ 0x08C0
#define COMP_E_BASE __MSP430_BASEADDRESS_COMP_E__

#define CECTL0_               0x08C0    /* Comparator E Control Register 0 */
sfrb(CECTL0_L , CECTL0_);
sfrb(CECTL0_H , CECTL0_+1);
sfrw(CECTL0, CECTL0_);
#define CECTL1_               0x08C2    /* Comparator E Control Register 1 */
sfrb(CECTL1_L , CECTL1_);
sfrb(CECTL1_H , CECTL1_+1);
sfrw(CECTL1, CECTL1_);
#define CECTL2_               0x08C4    /* Comparator E Control Register 2 */
sfrb(CECTL2_L , CECTL2_);
sfrb(CECTL2_H , CECTL2_+1);
sfrw(CECTL2, CECTL2_);
#define CECTL3_               0x08C6    /* Comparator E Control Register 3 */
sfrb(CECTL3_L , CECTL3_);
sfrb(CECTL3_H , CECTL3_+1);
sfrw(CECTL3, CECTL3_);
#define CEINT_                0x08CC    /* Comparator E Interrupt Register */
sfrb(CEINT_L , CEINT_);
sfrb(CEINT_H , CEINT_+1);
sfrw(CEINT, CEINT_);
#define CEIV_                 0x08CE    /* Comparator E Interrupt Vector Word */
const_sfrb(CEIV_L , CEIV_);
const_sfrb(CEIV_H , CEIV_+1);
const_sfrw(CEIV, CEIV_);


/* CECTL0 Control Bits */
#define CEIPSEL0            (0x0001)  /* Comp. E Pos. Channel Input Select 0 */
#define CEIPSEL1            (0x0002)  /* Comp. E Pos. Channel Input Select 1 */
#define CEIPSEL2            (0x0004)  /* Comp. E Pos. Channel Input Select 2 */
#define CEIPSEL3            (0x0008)  /* Comp. E Pos. Channel Input Select 3 */
//#define RESERVED            (0x0010)  /* Comp. E */
//#define RESERVED            (0x0020)  /* Comp. E */
//#define RESERVED            (0x0040)  /* Comp. E */
#define CEIPEN              (0x0080)  /* Comp. E Pos. Channel Input Enable */
#define CEIMSEL0            (0x0100)  /* Comp. E Neg. Channel Input Select 0 */
#define CEIMSEL1            (0x0200)  /* Comp. E Neg. Channel Input Select 1 */
#define CEIMSEL2            (0x0400)  /* Comp. E Neg. Channel Input Select 2 */
#define CEIMSEL3            (0x0800)  /* Comp. E Neg. Channel Input Select 3 */
//#define RESERVED            (0x1000)  /* Comp. E */
//#define RESERVED            (0x2000)  /* Comp. E */
//#define RESERVED            (0x4000)  /* Comp. E */
#define CEIMEN              (0x8000)  /* Comp. E Neg. Channel Input Enable */

/* CECTL0 Control Bits */
#define CEIPSEL0_L          (0x0001)  /* Comp. E Pos. Channel Input Select 0 */
#define CEIPSEL1_L          (0x0002)  /* Comp. E Pos. Channel Input Select 1 */
#define CEIPSEL2_L          (0x0004)  /* Comp. E Pos. Channel Input Select 2 */
#define CEIPSEL3_L          (0x0008)  /* Comp. E Pos. Channel Input Select 3 */
//#define RESERVED            (0x0010)  /* Comp. E */
//#define RESERVED            (0x0020)  /* Comp. E */
//#define RESERVED            (0x0040)  /* Comp. E */
#define CEIPEN_L            (0x0080)  /* Comp. E Pos. Channel Input Enable */
//#define RESERVED            (0x1000)  /* Comp. E */
//#define RESERVED            (0x2000)  /* Comp. E */
//#define RESERVED            (0x4000)  /* Comp. E */

/* CECTL0 Control Bits */
//#define RESERVED            (0x0010)  /* Comp. E */
//#define RESERVED            (0x0020)  /* Comp. E */
//#define RESERVED            (0x0040)  /* Comp. E */
#define CEIMSEL0_H          (0x0001)  /* Comp. E Neg. Channel Input Select 0 */
#define CEIMSEL1_H          (0x0002)  /* Comp. E Neg. Channel Input Select 1 */
#define CEIMSEL2_H          (0x0004)  /* Comp. E Neg. Channel Input Select 2 */
#define CEIMSEL3_H          (0x0008)  /* Comp. E Neg. Channel Input Select 3 */
//#define RESERVED            (0x1000)  /* Comp. E */
//#define RESERVED            (0x2000)  /* Comp. E */
//#define RESERVED            (0x4000)  /* Comp. E */
#define CEIMEN_H            (0x0080)  /* Comp. E Neg. Channel Input Enable */

#define CEIPSEL_0           (0x0000)  /* Comp. E V+ terminal Input Select: Channel 0 */
#define CEIPSEL_1           (0x0001)  /* Comp. E V+ terminal Input Select: Channel 1 */
#define CEIPSEL_2           (0x0002)  /* Comp. E V+ terminal Input Select: Channel 2 */
#define CEIPSEL_3           (0x0003)  /* Comp. E V+ terminal Input Select: Channel 3 */
#define CEIPSEL_4           (0x0004)  /* Comp. E V+ terminal Input Select: Channel 4 */
#define CEIPSEL_5           (0x0005)  /* Comp. E V+ terminal Input Select: Channel 5 */
#define CEIPSEL_6           (0x0006)  /* Comp. E V+ terminal Input Select: Channel 6 */
#define CEIPSEL_7           (0x0007)  /* Comp. E V+ terminal Input Select: Channel 7 */
#define CEIPSEL_8           (0x0008)  /* Comp. E V+ terminal Input Select: Channel 8 */
#define CEIPSEL_9           (0x0009)  /* Comp. E V+ terminal Input Select: Channel 9 */
#define CEIPSEL_10          (0x000A)  /* Comp. E V+ terminal Input Select: Channel 10 */
#define CEIPSEL_11          (0x000B)  /* Comp. E V+ terminal Input Select: Channel 11 */
#define CEIPSEL_12          (0x000C)  /* Comp. E V+ terminal Input Select: Channel 12 */
#define CEIPSEL_13          (0x000D)  /* Comp. E V+ terminal Input Select: Channel 13 */
#define CEIPSEL_14          (0x000E)  /* Comp. E V+ terminal Input Select: Channel 14 */
#define CEIPSEL_15          (0x000F)  /* Comp. E V+ terminal Input Select: Channel 15 */

#define CEIMSEL_0           (0x0000)  /* Comp. E V- Terminal Input Select: Channel 0 */
#define CEIMSEL_1           (0x0100)  /* Comp. E V- Terminal Input Select: Channel 1 */
#define CEIMSEL_2           (0x0200)  /* Comp. E V- Terminal Input Select: Channel 2 */
#define CEIMSEL_3           (0x0300)  /* Comp. E V- Terminal Input Select: Channel 3 */
#define CEIMSEL_4           (0x0400)  /* Comp. E V- Terminal Input Select: Channel 4 */
#define CEIMSEL_5           (0x0500)  /* Comp. E V- Terminal Input Select: Channel 5 */
#define CEIMSEL_6           (0x0600)  /* Comp. E V- Terminal Input Select: Channel 6 */
#define CEIMSEL_7           (0x0700)  /* Comp. E V- Terminal Input Select: Channel 7 */
#define CEIMSEL_8           (0x0800)  /* Comp. E V- terminal Input Select: Channel 8 */
#define CEIMSEL_9           (0x0900)  /* Comp. E V- terminal Input Select: Channel 9 */
#define CEIMSEL_10          (0x0A00)  /* Comp. E V- terminal Input Select: Channel 10 */
#define CEIMSEL_11          (0x0B00)  /* Comp. E V- terminal Input Select: Channel 11 */
#define CEIMSEL_12          (0x0C00)  /* Comp. E V- terminal Input Select: Channel 12 */
#define CEIMSEL_13          (0x0D00)  /* Comp. E V- terminal Input Select: Channel 13 */
#define CEIMSEL_14          (0x0E00)  /* Comp. E V- terminal Input Select: Channel 14 */
#define CEIMSEL_15          (0x0F00)  /* Comp. E V- terminal Input Select: Channel 15 */

/* CECTL1 Control Bits */
#define CEOUT               (0x0001)  /* Comp. E Output */
#define CEOUTPOL            (0x0002)  /* Comp. E Output Polarity */
#define CEF                 (0x0004)  /* Comp. E Enable Output Filter */
#define CEIES               (0x0008)  /* Comp. E Interrupt Edge Select */
#define CESHORT             (0x0010)  /* Comp. E Input Short */
#define CEEX                (0x0020)  /* Comp. E Exchange Inputs */
#define CEFDLY0             (0x0040)  /* Comp. E Filter delay Bit 0 */
#define CEFDLY1             (0x0080)  /* Comp. E Filter delay Bit 1 */
#define CEPWRMD0            (0x0100)  /* Comp. E Power mode Bit 0 */
#define CEPWRMD1            (0x0200)  /* Comp. E Power mode Bit 1 */
#define CEON                (0x0400)  /* Comp. E enable */
#define CEMRVL              (0x0800)  /* Comp. E CEMRV Level */
#define CEMRVS              (0x1000)  /* Comp. E Output selects between VREF0 or VREF1*/
//#define RESERVED            (0x2000)  /* Comp. E */
//#define RESERVED            (0x4000)  /* Comp. E */
//#define RESERVED            (0x8000)  /* Comp. E */

/* CECTL1 Control Bits */
#define CEOUT_L             (0x0001)  /* Comp. E Output */
#define CEOUTPOL_L          (0x0002)  /* Comp. E Output Polarity */
#define CEF_L               (0x0004)  /* Comp. E Enable Output Filter */
#define CEIES_L             (0x0008)  /* Comp. E Interrupt Edge Select */
#define CESHORT_L           (0x0010)  /* Comp. E Input Short */
#define CEEX_L              (0x0020)  /* Comp. E Exchange Inputs */
#define CEFDLY0_L           (0x0040)  /* Comp. E Filter delay Bit 0 */
#define CEFDLY1_L           (0x0080)  /* Comp. E Filter delay Bit 1 */
//#define RESERVED            (0x2000)  /* Comp. E */
//#define RESERVED            (0x4000)  /* Comp. E */
//#define RESERVED            (0x8000)  /* Comp. E */

/* CECTL1 Control Bits */
#define CEPWRMD0_H          (0x0001)  /* Comp. E Power mode Bit 0 */
#define CEPWRMD1_H          (0x0002)  /* Comp. E Power mode Bit 1 */
#define CEON_H              (0x0004)  /* Comp. E enable */
#define CEMRVL_H            (0x0008)  /* Comp. E CEMRV Level */
#define CEMRVS_H            (0x0010)  /* Comp. E Output selects between VREF0 or VREF1*/
//#define RESERVED            (0x2000)  /* Comp. E */
//#define RESERVED            (0x4000)  /* Comp. E */
//#define RESERVED            (0x8000)  /* Comp. E */

#define CEPWRMD_0          (0x0000)  /* Comp. E Power mode 0 */
#define CEPWRMD_1          (0x0100)  /* Comp. E Power mode 1 */
#define CEPWRMD_2          (0x0200)  /* Comp. E Power mode 2 */
#define CEPWRMD_3          (0x0300)  /* Comp. E Power mode 3*/

#define CEFDLY_0           (0x0000)  /* Comp. E Filter delay 0 : 450ns */
#define CEFDLY_1           (0x0040)  /* Comp. E Filter delay 1 : 900ns */
#define CEFDLY_2           (0x0080)  /* Comp. E Filter delay 2 : 1800ns */
#define CEFDLY_3           (0x00C0)  /* Comp. E Filter delay 3 : 3600ns */


/* CECTL2 Control Bits */
#define CEREF00             (0x0001)  /* Comp. E Reference 0 Resistor Select Bit : 0 */
#define CEREF01             (0x0002)  /* Comp. E Reference 0 Resistor Select Bit : 1 */
#define CEREF02             (0x0004)  /* Comp. E Reference 0 Resistor Select Bit : 2 */
#define CEREF03             (0x0008)  /* Comp. E Reference 0 Resistor Select Bit : 3 */
#define CEREF04             (0x0010)  /* Comp. E Reference 0 Resistor Select Bit : 4 */
#define CERSEL              (0x0020)  /* Comp. E Reference select */
#define CERS0               (0x0040)  /* Comp. E Reference Source Bit : 0 */
#define CERS1               (0x0080)  /* Comp. E Reference Source Bit : 1 */
#define CEREF10             (0x0100)  /* Comp. E Reference 1 Resistor Select Bit : 0 */
#define CEREF11             (0x0200)  /* Comp. E Reference 1 Resistor Select Bit : 1 */
#define CEREF12             (0x0400)  /* Comp. E Reference 1 Resistor Select Bit : 2 */
#define CEREF13             (0x0800)  /* Comp. E Reference 1 Resistor Select Bit : 3 */
#define CEREF14             (0x1000)  /* Comp. E Reference 1 Resistor Select Bit : 4 */
#define CEREFL0             (0x2000)  /* Comp. E Reference voltage level Bit : 0 */
#define CEREFL1             (0x4000)  /* Comp. E Reference voltage level Bit : 1 */
#define CEREFACC            (0x8000)  /* Comp. E Reference Accuracy */

/* CECTL2 Control Bits */
#define CEREF00_L           (0x0001)  /* Comp. E Reference 0 Resistor Select Bit : 0 */
#define CEREF01_L           (0x0002)  /* Comp. E Reference 0 Resistor Select Bit : 1 */
#define CEREF02_L           (0x0004)  /* Comp. E Reference 0 Resistor Select Bit : 2 */
#define CEREF03_L           (0x0008)  /* Comp. E Reference 0 Resistor Select Bit : 3 */
#define CEREF04_L           (0x0010)  /* Comp. E Reference 0 Resistor Select Bit : 4 */
#define CERSEL_L            (0x0020)  /* Comp. E Reference select */
#define CERS0_L             (0x0040)  /* Comp. E Reference Source Bit : 0 */
#define CERS1_L             (0x0080)  /* Comp. E Reference Source Bit : 1 */

/* CECTL2 Control Bits */
#define CEREF10_H           (0x0001)  /* Comp. E Reference 1 Resistor Select Bit : 0 */
#define CEREF11_H           (0x0002)  /* Comp. E Reference 1 Resistor Select Bit : 1 */
#define CEREF12_H           (0x0004)  /* Comp. E Reference 1 Resistor Select Bit : 2 */
#define CEREF13_H           (0x0008)  /* Comp. E Reference 1 Resistor Select Bit : 3 */
#define CEREF14_H           (0x0010)  /* Comp. E Reference 1 Resistor Select Bit : 4 */
#define CEREFL0_H           (0x0020)  /* Comp. E Reference voltage level Bit : 0 */
#define CEREFL1_H           (0x0040)  /* Comp. E Reference voltage level Bit : 1 */
#define CEREFACC_H          (0x0080)  /* Comp. E Reference Accuracy */

#define CEREF0_0            (0x0000)  /* Comp. E Int. Ref.0 Select 0 : 1/32 */
#define CEREF0_1            (0x0001)  /* Comp. E Int. Ref.0 Select 1 : 2/32 */
#define CEREF0_2            (0x0002)  /* Comp. E Int. Ref.0 Select 2 : 3/32 */
#define CEREF0_3            (0x0003)  /* Comp. E Int. Ref.0 Select 3 : 4/32 */
#define CEREF0_4            (0x0004)  /* Comp. E Int. Ref.0 Select 4 : 5/32 */
#define CEREF0_5            (0x0005)  /* Comp. E Int. Ref.0 Select 5 : 6/32 */
#define CEREF0_6            (0x0006)  /* Comp. E Int. Ref.0 Select 6 : 7/32 */
#define CEREF0_7            (0x0007)  /* Comp. E Int. Ref.0 Select 7 : 8/32 */
#define CEREF0_8            (0x0008)  /* Comp. E Int. Ref.0 Select 0 : 9/32 */
#define CEREF0_9            (0x0009)  /* Comp. E Int. Ref.0 Select 1 : 10/32 */
#define CEREF0_10           (0x000A)  /* Comp. E Int. Ref.0 Select 2 : 11/32 */
#define CEREF0_11           (0x000B)  /* Comp. E Int. Ref.0 Select 3 : 12/32 */
#define CEREF0_12           (0x000C)  /* Comp. E Int. Ref.0 Select 4 : 13/32 */
#define CEREF0_13           (0x000D)  /* Comp. E Int. Ref.0 Select 5 : 14/32 */
#define CEREF0_14           (0x000E)  /* Comp. E Int. Ref.0 Select 6 : 15/32 */
#define CEREF0_15           (0x000F)  /* Comp. E Int. Ref.0 Select 7 : 16/32 */
#define CEREF0_16           (0x0010)  /* Comp. E Int. Ref.0 Select 0 : 17/32 */
#define CEREF0_17           (0x0011)  /* Comp. E Int. Ref.0 Select 1 : 18/32 */
#define CEREF0_18           (0x0012)  /* Comp. E Int. Ref.0 Select 2 : 19/32 */
#define CEREF0_19           (0x0013)  /* Comp. E Int. Ref.0 Select 3 : 20/32 */
#define CEREF0_20           (0x0014)  /* Comp. E Int. Ref.0 Select 4 : 21/32 */
#define CEREF0_21           (0x0015)  /* Comp. E Int. Ref.0 Select 5 : 22/32 */
#define CEREF0_22           (0x0016)  /* Comp. E Int. Ref.0 Select 6 : 23/32 */
#define CEREF0_23           (0x0017)  /* Comp. E Int. Ref.0 Select 7 : 24/32 */
#define CEREF0_24           (0x0018)  /* Comp. E Int. Ref.0 Select 0 : 25/32 */
#define CEREF0_25           (0x0019)  /* Comp. E Int. Ref.0 Select 1 : 26/32 */
#define CEREF0_26           (0x001A)  /* Comp. E Int. Ref.0 Select 2 : 27/32 */
#define CEREF0_27           (0x001B)  /* Comp. E Int. Ref.0 Select 3 : 28/32 */
#define CEREF0_28           (0x001C)  /* Comp. E Int. Ref.0 Select 4 : 29/32 */
#define CEREF0_29           (0x001D)  /* Comp. E Int. Ref.0 Select 5 : 30/32 */
#define CEREF0_30           (0x001E)  /* Comp. E Int. Ref.0 Select 6 : 31/32 */
#define CEREF0_31           (0x001F)  /* Comp. E Int. Ref.0 Select 7 : 32/32 */

#define CERS_0              (0x0000)  /* Comp. E Reference Source 0 : Off */
#define CERS_1              (0x0040)  /* Comp. E Reference Source 1 : Vcc */
#define CERS_2              (0x0080)  /* Comp. E Reference Source 2 : Shared Ref. */
#define CERS_3              (0x00C0)  /* Comp. E Reference Source 3 : Shared Ref. / Off */

#define CEREF1_0            (0x0000)  /* Comp. E Int. Ref.1 Select 0 : 1/32 */
#define CEREF1_1            (0x0100)  /* Comp. E Int. Ref.1 Select 1 : 2/32 */
#define CEREF1_2            (0x0200)  /* Comp. E Int. Ref.1 Select 2 : 3/32 */
#define CEREF1_3            (0x0300)  /* Comp. E Int. Ref.1 Select 3 : 4/32 */
#define CEREF1_4            (0x0400)  /* Comp. E Int. Ref.1 Select 4 : 5/32 */
#define CEREF1_5            (0x0500)  /* Comp. E Int. Ref.1 Select 5 : 6/32 */
#define CEREF1_6            (0x0600)  /* Comp. E Int. Ref.1 Select 6 : 7/32 */
#define CEREF1_7            (0x0700)  /* Comp. E Int. Ref.1 Select 7 : 8/32 */
#define CEREF1_8            (0x0800)  /* Comp. E Int. Ref.1 Select 0 : 9/32 */
#define CEREF1_9            (0x0900)  /* Comp. E Int. Ref.1 Select 1 : 10/32 */
#define CEREF1_10           (0x0A00)  /* Comp. E Int. Ref.1 Select 2 : 11/32 */
#define CEREF1_11           (0x0B00)  /* Comp. E Int. Ref.1 Select 3 : 12/32 */
#define CEREF1_12           (0x0C00)  /* Comp. E Int. Ref.1 Select 4 : 13/32 */
#define CEREF1_13           (0x0D00)  /* Comp. E Int. Ref.1 Select 5 : 14/32 */
#define CEREF1_14           (0x0E00)  /* Comp. E Int. Ref.1 Select 6 : 15/32 */
#define CEREF1_15           (0x0F00)  /* Comp. E Int. Ref.1 Select 7 : 16/32 */
#define CEREF1_16           (0x1000)  /* Comp. E Int. Ref.1 Select 0 : 17/32 */
#define CEREF1_17           (0x1100)  /* Comp. E Int. Ref.1 Select 1 : 18/32 */
#define CEREF1_18           (0x1200)  /* Comp. E Int. Ref.1 Select 2 : 19/32 */
#define CEREF1_19           (0x1300)  /* Comp. E Int. Ref.1 Select 3 : 20/32 */
#define CEREF1_20           (0x1400)  /* Comp. E Int. Ref.1 Select 4 : 21/32 */
#define CEREF1_21           (0x1500)  /* Comp. E Int. Ref.1 Select 5 : 22/32 */
#define CEREF1_22           (0x1600)  /* Comp. E Int. Ref.1 Select 6 : 23/32 */
#define CEREF1_23           (0x1700)  /* Comp. E Int. Ref.1 Select 7 : 24/32 */
#define CEREF1_24           (0x1800)  /* Comp. E Int. Ref.1 Select 0 : 25/32 */
#define CEREF1_25           (0x1900)  /* Comp. E Int. Ref.1 Select 1 : 26/32 */
#define CEREF1_26           (0x1A00)  /* Comp. E Int. Ref.1 Select 2 : 27/32 */
#define CEREF1_27           (0x1B00)  /* Comp. E Int. Ref.1 Select 3 : 28/32 */
#define CEREF1_28           (0x1C00)  /* Comp. E Int. Ref.1 Select 4 : 29/32 */
#define CEREF1_29           (0x1D00)  /* Comp. E Int. Ref.1 Select 5 : 30/32 */
#define CEREF1_30           (0x1E00)  /* Comp. E Int. Ref.1 Select 6 : 31/32 */
#define CEREF1_31           (0x1F00)  /* Comp. E Int. Ref.1 Select 7 : 32/32 */

#define CEREFL_0            (0x0000)  /* Comp. E Reference voltage level 0 : None */
#define CEREFL_1            (0x2000)  /* Comp. E Reference voltage level 1 : 1.2V */
#define CEREFL_2            (0x4000)  /* Comp. E Reference voltage level 2 : 2.0V  */
#define CEREFL_3            (0x6000)  /* Comp. E Reference voltage level 3 : 2.5V  */


#define CEPD0               (0x0001)  /* Comp. E Disable Input Buffer of Port Register .0 */
#define CEPD1               (0x0002)  /* Comp. E Disable Input Buffer of Port Register .1 */
#define CEPD2               (0x0004)  /* Comp. E Disable Input Buffer of Port Register .2 */
#define CEPD3               (0x0008)  /* Comp. E Disable Input Buffer of Port Register .3 */
#define CEPD4               (0x0010)  /* Comp. E Disable Input Buffer of Port Register .4 */
#define CEPD5               (0x0020)  /* Comp. E Disable Input Buffer of Port Register .5 */
#define CEPD6               (0x0040)  /* Comp. E Disable Input Buffer of Port Register .6 */
#define CEPD7               (0x0080)  /* Comp. E Disable Input Buffer of Port Register .7 */
#define CEPD8               (0x0100)  /* Comp. E Disable Input Buffer of Port Register .8 */
#define CEPD9               (0x0200)  /* Comp. E Disable Input Buffer of Port Register .9 */
#define CEPD10              (0x0400)  /* Comp. E Disable Input Buffer of Port Register .10 */
#define CEPD11              (0x0800)  /* Comp. E Disable Input Buffer of Port Register .11 */
#define CEPD12              (0x1000)  /* Comp. E Disable Input Buffer of Port Register .12 */
#define CEPD13              (0x2000)  /* Comp. E Disable Input Buffer of Port Register .13 */
#define CEPD14              (0x4000)  /* Comp. E Disable Input Buffer of Port Register .14 */
#define CEPD15              (0x8000)  /* Comp. E Disable Input Buffer of Port Register .15 */

#define CEPD0_L             (0x0001)  /* Comp. E Disable Input Buffer of Port Register .0 */
#define CEPD1_L             (0x0002)  /* Comp. E Disable Input Buffer of Port Register .1 */
#define CEPD2_L             (0x0004)  /* Comp. E Disable Input Buffer of Port Register .2 */
#define CEPD3_L             (0x0008)  /* Comp. E Disable Input Buffer of Port Register .3 */
#define CEPD4_L             (0x0010)  /* Comp. E Disable Input Buffer of Port Register .4 */
#define CEPD5_L             (0x0020)  /* Comp. E Disable Input Buffer of Port Register .5 */
#define CEPD6_L             (0x0040)  /* Comp. E Disable Input Buffer of Port Register .6 */
#define CEPD7_L             (0x0080)  /* Comp. E Disable Input Buffer of Port Register .7 */

#define CEPD8_H             (0x0001)  /* Comp. E Disable Input Buffer of Port Register .8 */
#define CEPD9_H             (0x0002)  /* Comp. E Disable Input Buffer of Port Register .9 */
#define CEPD10_H            (0x0004)  /* Comp. E Disable Input Buffer of Port Register .10 */
#define CEPD11_H            (0x0008)  /* Comp. E Disable Input Buffer of Port Register .11 */
#define CEPD12_H            (0x0010)  /* Comp. E Disable Input Buffer of Port Register .12 */
#define CEPD13_H            (0x0020)  /* Comp. E Disable Input Buffer of Port Register .13 */
#define CEPD14_H            (0x0040)  /* Comp. E Disable Input Buffer of Port Register .14 */
#define CEPD15_H            (0x0080)  /* Comp. E Disable Input Buffer of Port Register .15 */


/* CEINT Control Bits */
#define CEIFG                (0x0001)  /* Comp. E Interrupt Flag */
#define CEIIFG               (0x0002)  /* Comp. E Interrupt Flag Inverted Polarity */
//#define RESERVED             (0x0004)  /* Comp. E */
//#define RESERVED             (0x0008)  /* Comp. E */
#define CERDYIFG             (0x0010)  /* Comp. E Comparator_E ready interrupt flag */
//#define RESERVED             (0x0020)  /* Comp. E */
//#define RESERVED             (0x0040)  /* Comp. E */
//#define RESERVED             (0x0080)  /* Comp. E */
#define CEIE                 (0x0100)  /* Comp. E Interrupt Enable */
#define CEIIE                (0x0200)  /* Comp. E Interrupt Enable Inverted Polarity */
//#define RESERVED             (0x0400)  /* Comp. E */
//#define RESERVED             (0x0800)  /* Comp. E */
#define CERDYIE              (0x1000)  /* Comp. E Comparator_E ready interrupt enable */
//#define RESERVED             (0x2000)  /* Comp. E */
//#define RESERVED             (0x4000)  /* Comp. E */
//#define RESERVED             (0x8000)  /* Comp. E */

/* CEINT Control Bits */
#define CEIFG_L             (0x0001)  /* Comp. E Interrupt Flag */
#define CEIIFG_L            (0x0002)  /* Comp. E Interrupt Flag Inverted Polarity */
//#define RESERVED             (0x0004)  /* Comp. E */
//#define RESERVED             (0x0008)  /* Comp. E */
#define CERDYIFG_L          (0x0010)  /* Comp. E Comparator_E ready interrupt flag */
//#define RESERVED             (0x0020)  /* Comp. E */
//#define RESERVED             (0x0040)  /* Comp. E */
//#define RESERVED             (0x0080)  /* Comp. E */
//#define RESERVED             (0x0400)  /* Comp. E */
//#define RESERVED             (0x0800)  /* Comp. E */
//#define RESERVED             (0x2000)  /* Comp. E */
//#define RESERVED             (0x4000)  /* Comp. E */
//#define RESERVED             (0x8000)  /* Comp. E */

/* CEINT Control Bits */
//#define RESERVED             (0x0004)  /* Comp. E */
//#define RESERVED             (0x0008)  /* Comp. E */
//#define RESERVED             (0x0020)  /* Comp. E */
//#define RESERVED             (0x0040)  /* Comp. E */
//#define RESERVED             (0x0080)  /* Comp. E */
#define CEIE_H              (0x0001)  /* Comp. E Interrupt Enable */
#define CEIIE_H             (0x0002)  /* Comp. E Interrupt Enable Inverted Polarity */
//#define RESERVED             (0x0400)  /* Comp. E */
//#define RESERVED             (0x0800)  /* Comp. E */
#define CERDYIE_H           (0x0010)  /* Comp. E Comparator_E ready interrupt enable */
//#define RESERVED             (0x2000)  /* Comp. E */
//#define RESERVED             (0x4000)  /* Comp. E */
//#define RESERVED             (0x8000)  /* Comp. E */

/* CEIV Definitions */
#define CEIV_NONE           (0x0000)    /* No Interrupt pending */
#define CEIV_CEIFG          (0x0002)    /* CEIFG */
#define CEIV_CEIIFG         (0x0004)    /* CEIIFG */
#define CEIV_CERDYIFG       (0x000A)    /* CERDYIFG */

/*************************************************************
* CRC Module
*************************************************************/
#define __MSP430_HAS_CRC__            /* Definition to show that Module is available */
#define __MSP430_BASEADDRESS_CRC__ 0x0150
#define CRC_BASE __MSP430_BASEADDRESS_CRC__

#define CRCDI_                0x0150    /* CRC Data In Register */
sfrb(CRCDI_L , CRCDI_);
sfrb(CRCDI_H , CRCDI_+1);
sfrw(CRCDI, CRCDI_);
#define CRCDIRB_              0x0152    /* CRC data in reverse byte Register */
sfrb(CRCDIRB_L , CRCDIRB_);
sfrb(CRCDIRB_H , CRCDIRB_+1);
sfrw(CRCDIRB, CRCDIRB_);
#define CRCINIRES_            0x0154    /* CRC Initialisation Register and Result Register */
sfrb(CRCINIRES_L , CRCINIRES_);
sfrb(CRCINIRES_H , CRCINIRES_+1);
sfrw(CRCINIRES, CRCINIRES_);
#define CRCRESR_              0x0156    /* CRC reverse result Register */
sfrb(CRCRESR_L , CRCRESR_);
sfrb(CRCRESR_H , CRCRESR_+1);
sfrw(CRCRESR, CRCRESR_);

/************************************************************
* CLOCK SYSTEM
************************************************************/
#define __MSP430_HAS_CS__              /* Definition to show that Module is available */
#define __MSP430_BASEADDRESS_CS__ 0x0160
#define CS_BASE __MSP430_BASEADDRESS_CS__

#define CSCTL0_               0x0160    /* CS Control Register 0 */
sfrb(CSCTL0_L , CSCTL0_);
sfrb(CSCTL0_H , CSCTL0_+1);
sfrw(CSCTL0, CSCTL0_);
#define CSCTL1_               0x0162    /* CS Control Register 1 */
sfrb(CSCTL1_L , CSCTL1_);
sfrb(CSCTL1_H , CSCTL1_+1);
sfrw(CSCTL1, CSCTL1_);
#define CSCTL2_               0x0164    /* CS Control Register 2 */
sfrb(CSCTL2_L , CSCTL2_);
sfrb(CSCTL2_H , CSCTL2_+1);
sfrw(CSCTL2, CSCTL2_);
#define CSCTL3_               0x0166    /* CS Control Register 3 */
sfrb(CSCTL3_L , CSCTL3_);
sfrb(CSCTL3_H , CSCTL3_+1);
sfrw(CSCTL3, CSCTL3_);
#define CSCTL4_               0x0168    /* CS Control Register 4 */
sfrb(CSCTL4_L , CSCTL4_);
sfrb(CSCTL4_H , CSCTL4_+1);
sfrw(CSCTL4, CSCTL4_);
#define CSCTL5_               0x016A    /* CS Control Register 5 */
sfrb(CSCTL5_L , CSCTL5_);
sfrb(CSCTL5_H , CSCTL5_+1);
sfrw(CSCTL5, CSCTL5_);
#define CSCTL6_               0x016C    /* CS Control Register 6 */
sfrb(CSCTL6_L , CSCTL6_);
sfrb(CSCTL6_H , CSCTL6_+1);
sfrw(CSCTL6, CSCTL6_);

/* CSCTL0 Control Bits */

#define CSKEY                (0xA500)    /* CS Password */
#define CSKEY_H              (0xA5)      /* CS Password for high byte access */

/* CSCTL1 Control Bits */
#define DCOFSEL0            (0x0002)    /* DCO frequency select Bit: 0 */
#define DCOFSEL1            (0x0004)    /* DCO frequency select Bit: 1 */
#define DCOFSEL2            (0x0008)    /* DCO frequency select Bit: 2 */
#define DCORSEL             (0x0040)    /* DCO range select. */

/* CSCTL1 Control Bits */
#define DCOFSEL0_L          (0x0002)    /* DCO frequency select Bit: 0 */
#define DCOFSEL1_L          (0x0004)    /* DCO frequency select Bit: 1 */
#define DCOFSEL2_L          (0x0008)    /* DCO frequency select Bit: 2 */
#define DCORSEL_L           (0x0040)    /* DCO range select. */


#define DCOFSEL_0           (0x0000)    /* DCO frequency select: 0 */
#define DCOFSEL_1           (0x0002)    /* DCO frequency select: 1 */
#define DCOFSEL_2           (0x0004)    /* DCO frequency select: 2 */
#define DCOFSEL_3           (0x0006)    /* DCO frequency select: 3 */
#define DCOFSEL_4           (0x0008)    /* DCO frequency select: 4 */
#define DCOFSEL_5           (0x000A)    /* DCO frequency select: 5 */
#define DCOFSEL_6           (0x000C)    /* DCO frequency select: 6 */
#define DCOFSEL_7           (0x000E)    /* DCO frequency select: 7 */


/* CSCTL2 Control Bits */
#define SELM0               (0x0001)   /* MCLK Source Select Bit: 0 */
#define SELM1               (0x0002)   /* MCLK Source Select Bit: 1 */
#define SELM2               (0x0004)   /* MCLK Source Select Bit: 2 */
//#define RESERVED            (0x0004)    /* RESERVED */
//#define RESERVED            (0x0008)    /* RESERVED */
#define SELS0               (0x0010)   /* SMCLK Source Select Bit: 0 */
#define SELS1               (0x0020)   /* SMCLK Source Select Bit: 1 */
#define SELS2               (0x0040)   /* SMCLK Source Select Bit: 2 */
//#define RESERVED            (0x0040)    /* RESERVED */
//#define RESERVED            (0x0080)    /* RESERVED */
#define SELA0               (0x0100)   /* ACLK Source Select Bit: 0 */
#define SELA1               (0x0200)   /* ACLK Source Select Bit: 1 */
#define SELA2               (0x0400)   /* ACLK Source Select Bit: 2 */
//#define RESERVED            (0x0400)    /* RESERVED */
//#define RESERVED            (0x0800)    /* RESERVED */
//#define RESERVED            (0x1000)    /* RESERVED */
//#define RESERVED            (0x2000)    /* RESERVED */
//#define RESERVED            (0x4000)    /* RESERVED */
//#define RESERVED            (0x8000)    /* RESERVED */

/* CSCTL2 Control Bits */
#define SELM0_L             (0x0001)   /* MCLK Source Select Bit: 0 */
#define SELM1_L             (0x0002)   /* MCLK Source Select Bit: 1 */
#define SELM2_L             (0x0004)   /* MCLK Source Select Bit: 2 */
//#define RESERVED            (0x0004)    /* RESERVED */
//#define RESERVED            (0x0008)    /* RESERVED */
#define SELS0_L             (0x0010)   /* SMCLK Source Select Bit: 0 */
#define SELS1_L             (0x0020)   /* SMCLK Source Select Bit: 1 */
#define SELS2_L             (0x0040)   /* SMCLK Source Select Bit: 2 */
//#define RESERVED            (0x0040)    /* RESERVED */
//#define RESERVED            (0x0080)    /* RESERVED */
//#define RESERVED            (0x0400)    /* RESERVED */
//#define RESERVED            (0x0800)    /* RESERVED */
//#define RESERVED            (0x1000)    /* RESERVED */
//#define RESERVED            (0x2000)    /* RESERVED */
//#define RESERVED            (0x4000)    /* RESERVED */
//#define RESERVED            (0x8000)    /* RESERVED */

/* CSCTL2 Control Bits */
//#define RESERVED            (0x0004)    /* RESERVED */
//#define RESERVED            (0x0008)    /* RESERVED */
//#define RESERVED            (0x0040)    /* RESERVED */
//#define RESERVED            (0x0080)    /* RESERVED */
#define SELA0_H             (0x0001)   /* ACLK Source Select Bit: 0 */
#define SELA1_H             (0x0002)   /* ACLK Source Select Bit: 1 */
#define SELA2_H             (0x0004)   /* ACLK Source Select Bit: 2 */
//#define RESERVED            (0x0400)    /* RESERVED */
//#define RESERVED            (0x0800)    /* RESERVED */
//#define RESERVED            (0x1000)    /* RESERVED */
//#define RESERVED            (0x2000)    /* RESERVED */
//#define RESERVED            (0x4000)    /* RESERVED */
//#define RESERVED            (0x8000)    /* RESERVED */

#define SELM_0              (0x0000)   /* MCLK Source Select 0 */
#define SELM_1              (0x0001)   /* MCLK Source Select 1 */
#define SELM_2              (0x0002)   /* MCLK Source Select 2 */
#define SELM_3              (0x0003)   /* MCLK Source Select 3 */
#define SELM_4              (0x0004)   /* MCLK Source Select 4 */
#define SELM_5              (0x0005)   /* MCLK Source Select 5 */
#define SELM_6              (0x0006)   /* MCLK Source Select 6 */
#define SELM_7              (0x0007)   /* MCLK Source Select 7 */
#define SELM__LFXTCLK       (0x0000)   /* MCLK Source Select LFXTCLK */
#define SELM__VLOCLK        (0x0001)   /* MCLK Source Select VLOCLK */
#define SELM__LFMODOSC      (0x0002)   /* MCLK Source Select LFMODOSC */
#define SELM__DCOCLK        (0x0003)   /* MCLK Source Select DCOCLK */
#define SELM__MODOSC        (0x0004)   /* MCLK Source Select MODOSC */
#define SELM__HFXTCLK       (0x0005)   /* MCLK Source Select HFXTCLK */

#define SELS_0              (0x0000)   /* SMCLK Source Select 0 */
#define SELS_1              (0x0010)   /* SMCLK Source Select 1 */
#define SELS_2              (0x0020)   /* SMCLK Source Select 2 */
#define SELS_3              (0x0030)   /* SMCLK Source Select 3 */
#define SELS_4              (0x0040)   /* SMCLK Source Select 4 */
#define SELS_5              (0x0050)   /* SMCLK Source Select 5 */
#define SELS_6              (0x0060)   /* SMCLK Source Select 6 */
#define SELS_7              (0x0070)   /* SMCLK Source Select 7 */
#define SELS__LFXTCLK       (0x0000)   /* SMCLK Source Select LFXTCLK */
#define SELS__VLOCLK        (0x0010)   /* SMCLK Source Select VLOCLK */
#define SELS__LFMODOSC      (0x0020)   /* SMCLK Source Select LFMODOSC */
#define SELS__DCOCLK        (0x0030)   /* SMCLK Source Select DCOCLK */
#define SELS__MODOSC        (0x0040)   /* SMCLK Source Select MODOSC */
#define SELS__HFXTCLK       (0x0050)   /* SMCLK Source Select HFXTCLK */

#define SELA_0              (0x0000)   /* ACLK Source Select 0 */
#define SELA_1              (0x0100)   /* ACLK Source Select 1 */
#define SELA_2              (0x0200)   /* ACLK Source Select 2 */
#define SELA_3              (0x0300)   /* ACLK Source Select 3 */
#define SELA_4              (0x0400)   /* ACLK Source Select 4 */
#define SELA_5              (0x0500)   /* ACLK Source Select 5 */
#define SELA_6              (0x0600)   /* ACLK Source Select 6 */
#define SELA_7              (0x0700)   /* ACLK Source Select 7 */
#define SELA__LFXTCLK       (0x0000)   /* ACLK Source Select LFXTCLK */
#define SELA__VLOCLK        (0x0100)   /* ACLK Source Select VLOCLK */
#define SELA__LFMODOSC      (0x0200)   /* ACLK Source Select LFMODOSC */

/* CSCTL3 Control Bits */
#define DIVM0               (0x0001)   /* MCLK Divider Bit: 0 */
#define DIVM1               (0x0002)   /* MCLK Divider Bit: 1 */
#define DIVM2               (0x0004)   /* MCLK Divider Bit: 2 */
//#define RESERVED            (0x0004)    /* RESERVED */
//#define RESERVED            (0x0008)    /* RESERVED */
#define DIVS0               (0x0010)   /* SMCLK Divider Bit: 0 */
#define DIVS1               (0x0020)   /* SMCLK Divider Bit: 1 */
#define DIVS2               (0x0040)   /* SMCLK Divider Bit: 2 */
//#define RESERVED            (0x0040)    /* RESERVED */
//#define RESERVED            (0x0080)    /* RESERVED */
#define DIVA0               (0x0100)   /* ACLK Divider Bit: 0 */
#define DIVA1               (0x0200)   /* ACLK Divider Bit: 1 */
#define DIVA2               (0x0400)   /* ACLK Divider Bit: 2 */
//#define RESERVED            (0x0400)    /* RESERVED */
//#define RESERVED            (0x0800)    /* RESERVED */
//#define RESERVED            (0x1000)    /* RESERVED */
//#define RESERVED            (0x2000)    /* RESERVED */
//#define RESERVED            (0x4000)    /* RESERVED */
//#define RESERVED            (0x8000)    /* RESERVED */

/* CSCTL3 Control Bits */
#define DIVM0_L             (0x0001)   /* MCLK Divider Bit: 0 */
#define DIVM1_L             (0x0002)   /* MCLK Divider Bit: 1 */
#define DIVM2_L             (0x0004)   /* MCLK Divider Bit: 2 */
//#define RESERVED            (0x0004)    /* RESERVED */
//#define RESERVED            (0x0008)    /* RESERVED */
#define DIVS0_L             (0x0010)   /* SMCLK Divider Bit: 0 */
#define DIVS1_L             (0x0020)   /* SMCLK Divider Bit: 1 */
#define DIVS2_L             (0x0040)   /* SMCLK Divider Bit: 2 */
//#define RESERVED            (0x0040)    /* RESERVED */
//#define RESERVED            (0x0080)    /* RESERVED */
//#define RESERVED            (0x0400)    /* RESERVED */
//#define RESERVED            (0x0800)    /* RESERVED */
//#define RESERVED            (0x1000)    /* RESERVED */
//#define RESERVED            (0x2000)    /* RESERVED */
//#define RESERVED            (0x4000)    /* RESERVED */
//#define RESERVED            (0x8000)    /* RESERVED */

/* CSCTL3 Control Bits */
//#define RESERVED            (0x0004)    /* RESERVED */
//#define RESERVED            (0x0008)    /* RESERVED */
//#define RESERVED            (0x0040)    /* RESERVED */
//#define RESERVED            (0x0080)    /* RESERVED */
#define DIVA0_H             (0x0001)   /* ACLK Divider Bit: 0 */
#define DIVA1_H             (0x0002)   /* ACLK Divider Bit: 1 */
#define DIVA2_H             (0x0004)   /* ACLK Divider Bit: 2 */
//#define RESERVED            (0x0400)    /* RESERVED */
//#define RESERVED            (0x0800)    /* RESERVED */
//#define RESERVED            (0x1000)    /* RESERVED */
//#define RESERVED            (0x2000)    /* RESERVED */
//#define RESERVED            (0x4000)    /* RESERVED */
//#define RESERVED            (0x8000)    /* RESERVED */

#define DIVM_0              (0x0000)    /* MCLK Source Divider 0 */
#define DIVM_1              (0x0001)    /* MCLK Source Divider 1 */
#define DIVM_2              (0x0002)    /* MCLK Source Divider 2 */
#define DIVM_3              (0x0003)    /* MCLK Source Divider 3 */
#define DIVM_4              (0x0004)    /* MCLK Source Divider 4 */
#define DIVM_5              (0x0005)    /* MCLK Source Divider 5 */
#define DIVM__1             (0x0000)    /* MCLK Source Divider f(MCLK)/1 */
#define DIVM__2             (0x0001)    /* MCLK Source Divider f(MCLK)/2 */
#define DIVM__4             (0x0002)    /* MCLK Source Divider f(MCLK)/4 */
#define DIVM__8             (0x0003)    /* MCLK Source Divider f(MCLK)/8 */
#define DIVM__16            (0x0004)    /* MCLK Source Divider f(MCLK)/16 */
#define DIVM__32            (0x0005)    /* MCLK Source Divider f(MCLK)/32 */

#define DIVS_0              (0x0000)    /* SMCLK Source Divider 0 */
#define DIVS_1              (0x0010)    /* SMCLK Source Divider 1 */
#define DIVS_2              (0x0020)    /* SMCLK Source Divider 2 */
#define DIVS_3              (0x0030)    /* SMCLK Source Divider 3 */
#define DIVS_4              (0x0040)    /* SMCLK Source Divider 4 */
#define DIVS_5              (0x0050)    /* SMCLK Source Divider 5 */
#define DIVS__1             (0x0000)    /* SMCLK Source Divider f(SMCLK)/1 */
#define DIVS__2             (0x0010)    /* SMCLK Source Divider f(SMCLK)/2 */
#define DIVS__4             (0x0020)    /* SMCLK Source Divider f(SMCLK)/4 */
#define DIVS__8             (0x0030)    /* SMCLK Source Divider f(SMCLK)/8 */
#define DIVS__16            (0x0040)    /* SMCLK Source Divider f(SMCLK)/16 */
#define DIVS__32            (0x0050)    /* SMCLK Source Divider f(SMCLK)/32 */

#define DIVA_0              (0x0000)    /* ACLK Source Divider 0 */
#define DIVA_1              (0x0100)    /* ACLK Source Divider 1 */
#define DIVA_2              (0x0200)    /* ACLK Source Divider 2 */
#define DIVA_3              (0x0300)    /* ACLK Source Divider 3 */
#define DIVA_4              (0x0400)    /* ACLK Source Divider 4 */
#define DIVA_5              (0x0500)    /* ACLK Source Divider 5 */
#define DIVA__1             (0x0000)    /* ACLK Source Divider f(ACLK)/1 */
#define DIVA__2             (0x0100)    /* ACLK Source Divider f(ACLK)/2 */
#define DIVA__4             (0x0200)    /* ACLK Source Divider f(ACLK)/4 */
#define DIVA__8             (0x0300)    /* ACLK Source Divider f(ACLK)/8 */
#define DIVA__16            (0x0400)    /* ACLK Source Divider f(ACLK)/16 */
#define DIVA__32            (0x0500)    /* ACLK Source Divider f(ACLK)/32 */


/* CSCTL4 Control Bits */
#define LFXTOFF             (0x0001)    /* High Frequency Oscillator 1 (XT1) disable */
#define SMCLKOFF            (0x0002)    /* SMCLK Off */
#define VLOOFF              (0x0008)    /* VLO Off */
#define LFXTBYPASS          (0x0010)    /* LFXT bypass mode : 0: internal 1:sourced from external pin */
#define LFXTAGCOFF          (0x0020)    /* LFXT automatic gain control off */
#define LFXTDRIVE0          (0x0040)    /* LFXT Drive Level mode Bit 0 */
#define LFXTDRIVE1          (0x0080)    /* LFXT Drive Level mode Bit 1 */
#define HFXTOFF             (0x0100)    /* High Frequency Oscillator disable */
#define HFFREQ0             (0x0400)    /* HFXT frequency selection Bit 1 */
#define HFFREQ1             (0x0800)    /* HFXT frequency selection Bit 0 */
#define HFXTBYPASS          (0x1000)    /* HFXT bypass mode : 0: internal 1:sourced from external pin */
#define HFXTDRIVE0          (0x4000)    /* HFXT Drive Level mode Bit 0 */
#define HFXTDRIVE1          (0x8000)    /* HFXT Drive Level mode Bit 1 */

/* CSCTL4 Control Bits */
#define LFXTOFF_L           (0x0001)    /* High Frequency Oscillator 1 (XT1) disable */
#define SMCLKOFF_L          (0x0002)    /* SMCLK Off */
#define VLOOFF_L            (0x0008)    /* VLO Off */
#define LFXTBYPASS_L        (0x0010)    /* LFXT bypass mode : 0: internal 1:sourced from external pin */
#define LFXTAGCOFF_L        (0x0020)    /* LFXT automatic gain control off */
#define LFXTDRIVE0_L        (0x0040)    /* LFXT Drive Level mode Bit 0 */
#define LFXTDRIVE1_L        (0x0080)    /* LFXT Drive Level mode Bit 1 */

/* CSCTL4 Control Bits */
#define HFXTOFF_H           (0x0001)    /* High Frequency Oscillator disable */
#define HFFREQ0_H           (0x0004)    /* HFXT frequency selection Bit 1 */
#define HFFREQ1_H           (0x0008)    /* HFXT frequency selection Bit 0 */
#define HFXTBYPASS_H        (0x0010)    /* HFXT bypass mode : 0: internal 1:sourced from external pin */
#define HFXTDRIVE0_H        (0x0040)    /* HFXT Drive Level mode Bit 0 */
#define HFXTDRIVE1_H        (0x0080)    /* HFXT Drive Level mode Bit 1 */

#define LFXTDRIVE_0         (0x0000)    /* LFXT Drive Level mode: 0 */
#define LFXTDRIVE_1         (0x0040)    /* LFXT Drive Level mode: 1 */
#define LFXTDRIVE_2         (0x0080)    /* LFXT Drive Level mode: 2 */
#define LFXTDRIVE_3         (0x00C0)    /* LFXT Drive Level mode: 3 */

#define HFFREQ_0            (0x0000)    /* HFXT frequency selection: 0 */
#define HFFREQ_1            (0x0400)    /* HFXT frequency selection: 1 */
#define HFFREQ_2            (0x0800)    /* HFXT frequency selection: 2 */
#define HFFREQ_3            (0x0C00)    /* HFXT frequency selection: 3 */

#define HFXTDRIVE_0         (0x0000)    /* HFXT Drive Level mode: 0 */
#define HFXTDRIVE_1         (0x4000)    /* HFXT Drive Level mode: 1 */
#define HFXTDRIVE_2         (0x8000)    /* HFXT Drive Level mode: 2 */
#define HFXTDRIVE_3         (0xC000)    /* HFXT Drive Level mode: 3 */

/* CSCTL5 Control Bits */
#define LFXTOFFG            (0x0001)    /* LFXT Low Frequency Oscillator Fault Flag */
#define HFXTOFFG            (0x0002)    /* HFXT High Frequency Oscillator Fault Flag */
#define ENSTFCNT1           (0x0040)    /* Enable start counter for XT1 */
#define ENSTFCNT2           (0x0080)    /* Enable start counter for XT2 */

/* CSCTL5 Control Bits */
#define LFXTOFFG_L          (0x0001)    /* LFXT Low Frequency Oscillator Fault Flag */
#define HFXTOFFG_L          (0x0002)    /* HFXT High Frequency Oscillator Fault Flag */
#define ENSTFCNT1_L         (0x0040)    /* Enable start counter for XT1 */
#define ENSTFCNT2_L         (0x0080)    /* Enable start counter for XT2 */


/* CSCTL6 Control Bits */
#define ACLKREQEN           (0x0001)    /* ACLK Clock Request Enable */
#define MCLKREQEN           (0x0002)    /* MCLK Clock Request Enable */
#define SMCLKREQEN          (0x0004)    /* SMCLK Clock Request Enable */
#define MODCLKREQEN         (0x0008)    /* MODOSC Clock Request Enable */

/* CSCTL6 Control Bits */
#define ACLKREQEN_L         (0x0001)    /* ACLK Clock Request Enable */
#define MCLKREQEN_L         (0x0002)    /* MCLK Clock Request Enable */
#define SMCLKREQEN_L        (0x0004)    /* SMCLK Clock Request Enable */
#define MODCLKREQEN_L       (0x0008)    /* MODOSC Clock Request Enable */


/************************************************************
* DMA_X
************************************************************/
#define __MSP430_HAS_DMAX_3__           /* Definition to show that Module is available */
#define __MSP430_BASEADDRESS_DMAX_3__ 0x0500
#define DMA_BASE __MSP430_BASEADDRESS_DMAX_3__

#define DMACTL0_              0x0500    /* DMA Module Control 0 */
sfrb(DMACTL0_L , DMACTL0_);
sfrb(DMACTL0_H , DMACTL0_+1);
sfrw(DMACTL0, DMACTL0_);
#define DMACTL1_              0x0502    /* DMA Module Control 1 */
sfrb(DMACTL1_L , DMACTL1_);
sfrb(DMACTL1_H , DMACTL1_+1);
sfrw(DMACTL1, DMACTL1_);
#define DMACTL2_              0x0504    /* DMA Module Control 2 */
sfrb(DMACTL2_L , DMACTL2_);
sfrb(DMACTL2_H , DMACTL2_+1);
sfrw(DMACTL2, DMACTL2_);
#define DMACTL3_              0x0506    /* DMA Module Control 3 */
sfrb(DMACTL3_L , DMACTL3_);
sfrb(DMACTL3_H , DMACTL3_+1);
sfrw(DMACTL3, DMACTL3_);
#define DMACTL4_              0x0508    /* DMA Module Control 4 */
sfrb(DMACTL4_L , DMACTL4_);
sfrb(DMACTL4_H , DMACTL4_+1);
sfrw(DMACTL4, DMACTL4_);
#define DMAIV_                0x050E    /* DMA Interrupt Vector Word */
sfrb(DMAIV_L , DMAIV_);
sfrb(DMAIV_H , DMAIV_+1);
sfrw(DMAIV, DMAIV_);

#define DMA0CTL_              0x0510    /* DMA Channel 0 Control */
sfrb(DMA0CTL_L , DMA0CTL_);
sfrb(DMA0CTL_H , DMA0CTL_+1);
sfrw(DMA0CTL, DMA0CTL_);
#define DMA0SA_               0x0512    /* DMA Channel 0 Source Address */
sfra(DMA0SA, DMA0SA_);
#define DMA0DA_               0x0516    /* DMA Channel 0 Destination Address */
sfra(DMA0DA, DMA0DA_);
#define DMA0SZ_               0x051A    /* DMA Channel 0 Transfer Size */
sfrw(DMA0SZ, DMA0SZ_);

#define DMA1CTL_              0x0520    /* DMA Channel 1 Control */
sfrb(DMA1CTL_L , DMA1CTL_);
sfrb(DMA1CTL_H , DMA1CTL_+1);
sfrw(DMA1CTL, DMA1CTL_);
#define DMA1SA_               0x0522    /* DMA Channel 1 Source Address */
sfra(DMA1SA, DMA1SA_);
#define DMA1DA_               0x0526    /* DMA Channel 1 Destination Address */
sfra(DMA1DA, DMA1DA_);
#define DMA1SZ_               0x052A    /* DMA Channel 1 Transfer Size */
sfrw(DMA1SZ, DMA1SZ_);

#define DMA2CTL_              0x0530    /* DMA Channel 2 Control */
sfrb(DMA2CTL_L , DMA2CTL_);
sfrb(DMA2CTL_H , DMA2CTL_+1);
sfrw(DMA2CTL, DMA2CTL_);
#define DMA2SA_               0x0532    /* DMA Channel 2 Source Address */
sfra(DMA2SA, DMA2SA_);
#define DMA2DA_               0x0536    /* DMA Channel 2 Destination Address */
sfra(DMA2DA, DMA2DA_);
#define DMA2SZ_               0x053A    /* DMA Channel 2 Transfer Size */
sfrw(DMA2SZ, DMA2SZ_);

/* DMACTL0 Control Bits */
#define DMA0TSEL0           (0x0001)    /* DMA channel 0 transfer select bit 0 */
#define DMA0TSEL1           (0x0002)    /* DMA channel 0 transfer select bit 1 */
#define DMA0TSEL2           (0x0004)    /* DMA channel 0 transfer select bit 2 */
#define DMA0TSEL3           (0x0008)    /* DMA channel 0 transfer select bit 3 */
#define DMA0TSEL4           (0x0010)    /* DMA channel 0 transfer select bit 4 */
#define DMA1TSEL0           (0x0100)    /* DMA channel 1 transfer select bit 0 */
#define DMA1TSEL1           (0x0200)    /* DMA channel 1 transfer select bit 1 */
#define DMA1TSEL2           (0x0400)    /* DMA channel 1 transfer select bit 2 */
#define DMA1TSEL3           (0x0800)    /* DMA channel 1 transfer select bit 3 */
#define DMA1TSEL4           (0x1000)    /* DMA channel 1 transfer select bit 4 */

/* DMACTL0 Control Bits */
#define DMA0TSEL0_L         (0x0001)    /* DMA channel 0 transfer select bit 0 */
#define DMA0TSEL1_L         (0x0002)    /* DMA channel 0 transfer select bit 1 */
#define DMA0TSEL2_L         (0x0004)    /* DMA channel 0 transfer select bit 2 */
#define DMA0TSEL3_L         (0x0008)    /* DMA channel 0 transfer select bit 3 */
#define DMA0TSEL4_L         (0x0010)    /* DMA channel 0 transfer select bit 4 */

/* DMACTL0 Control Bits */
#define DMA1TSEL0_H         (0x0001)    /* DMA channel 1 transfer select bit 0 */
#define DMA1TSEL1_H         (0x0002)    /* DMA channel 1 transfer select bit 1 */
#define DMA1TSEL2_H         (0x0004)    /* DMA channel 1 transfer select bit 2 */
#define DMA1TSEL3_H         (0x0008)    /* DMA channel 1 transfer select bit 3 */
#define DMA1TSEL4_H         (0x0010)    /* DMA channel 1 transfer select bit 4 */

/* DMACTL01 Control Bits */
#define DMA2TSEL0           (0x0001)    /* DMA channel 2 transfer select bit 0 */
#define DMA2TSEL1           (0x0002)    /* DMA channel 2 transfer select bit 1 */
#define DMA2TSEL2           (0x0004)    /* DMA channel 2 transfer select bit 2 */
#define DMA2TSEL3           (0x0008)    /* DMA channel 2 transfer select bit 3 */
#define DMA2TSEL4           (0x0010)    /* DMA channel 2 transfer select bit 4 */

/* DMACTL01 Control Bits */
#define DMA2TSEL0_L         (0x0001)    /* DMA channel 2 transfer select bit 0 */
#define DMA2TSEL1_L         (0x0002)    /* DMA channel 2 transfer select bit 1 */
#define DMA2TSEL2_L         (0x0004)    /* DMA channel 2 transfer select bit 2 */
#define DMA2TSEL3_L         (0x0008)    /* DMA channel 2 transfer select bit 3 */
#define DMA2TSEL4_L         (0x0010)    /* DMA channel 2 transfer select bit 4 */


/* DMACTL4 Control Bits */
#define ENNMI               (0x0001)    /* Enable NMI interruption of DMA */
#define ROUNDROBIN          (0x0002)    /* Round-Robin DMA channel priorities */
#define DMARMWDIS           (0x0004)    /* Inhibited DMA transfers during read-modify-write CPU operations */

/* DMACTL4 Control Bits */
#define ENNMI_L             (0x0001)    /* Enable NMI interruption of DMA */
#define ROUNDROBIN_L        (0x0002)    /* Round-Robin DMA channel priorities */
#define DMARMWDIS_L         (0x0004)    /* Inhibited DMA transfers during read-modify-write CPU operations */



/* DMAxCTL Control Bits */
#define DMAREQ              (0x0001)    /* Initiate DMA transfer with DMATSEL */
#define DMAABORT            (0x0002)    /* DMA transfer aborted by NMI */
#define DMAIE               (0x0004)    /* DMA interrupt enable */
#define DMAIFG              (0x0008)    /* DMA interrupt flag */
#define DMAEN               (0x0010)    /* DMA enable */
#define DMALEVEL            (0x0020)    /* DMA level sensitive trigger select */
#define DMASRCBYTE          (0x0040)    /* DMA source byte */
#define DMADSTBYTE          (0x0080)    /* DMA destination byte */
#define DMASRCINCR0         (0x0100)    /* DMA source increment bit 0 */
#define DMASRCINCR1         (0x0200)    /* DMA source increment bit 1 */
#define DMADSTINCR0         (0x0400)    /* DMA destination increment bit 0 */
#define DMADSTINCR1         (0x0800)    /* DMA destination increment bit 1 */
#define DMADT0              (0x1000)    /* DMA transfer mode bit 0 */
#define DMADT1              (0x2000)    /* DMA transfer mode bit 1 */
#define DMADT2              (0x4000)    /* DMA transfer mode bit 2 */

/* DMAxCTL Control Bits */
#define DMAREQ_L            (0x0001)    /* Initiate DMA transfer with DMATSEL */
#define DMAABORT_L          (0x0002)    /* DMA transfer aborted by NMI */
#define DMAIE_L             (0x0004)    /* DMA interrupt enable */
#define DMAIFG_L            (0x0008)    /* DMA interrupt flag */
#define DMAEN_L             (0x0010)    /* DMA enable */
#define DMALEVEL_L          (0x0020)    /* DMA level sensitive trigger select */
#define DMASRCBYTE_L        (0x0040)    /* DMA source byte */
#define DMADSTBYTE_L        (0x0080)    /* DMA destination byte */

/* DMAxCTL Control Bits */
#define DMASRCINCR0_H       (0x0001)    /* DMA source increment bit 0 */
#define DMASRCINCR1_H       (0x0002)    /* DMA source increment bit 1 */
#define DMADSTINCR0_H       (0x0004)    /* DMA destination increment bit 0 */
#define DMADSTINCR1_H       (0x0008)    /* DMA destination increment bit 1 */
#define DMADT0_H            (0x0010)    /* DMA transfer mode bit 0 */
#define DMADT1_H            (0x0020)    /* DMA transfer mode bit 1 */
#define DMADT2_H            (0x0040)    /* DMA transfer mode bit 2 */

#define DMASWDW             (0x0000)  /* DMA transfer: source word to destination word */
#define DMASBDW             (0x0040)  /* DMA transfer: source byte to destination word */
#define DMASWDB             (0x0080)  /* DMA transfer: source word to destination byte */
#define DMASBDB             (0x00C0)  /* DMA transfer: source byte to destination byte */

#define DMASRCINCR_0        (0x0000)  /* DMA source increment 0: source address unchanged */
#define DMASRCINCR_1        (0x0100)  /* DMA source increment 1: source address unchanged */
#define DMASRCINCR_2        (0x0200)  /* DMA source increment 2: source address decremented */
#define DMASRCINCR_3        (0x0300)  /* DMA source increment 3: source address incremented */

#define DMADSTINCR_0        (0x0000)  /* DMA destination increment 0: destination address unchanged */
#define DMADSTINCR_1        (0x0400)  /* DMA destination increment 1: destination address unchanged */
#define DMADSTINCR_2        (0x0800)  /* DMA destination increment 2: destination address decremented */
#define DMADSTINCR_3        (0x0C00)  /* DMA destination increment 3: destination address incremented */

#define DMADT_0             (0x0000)  /* DMA transfer mode 0: Single transfer */
#define DMADT_1             (0x1000)  /* DMA transfer mode 1: Block transfer */
#define DMADT_2             (0x2000)  /* DMA transfer mode 2: Burst-Block transfer */
#define DMADT_3             (0x3000)  /* DMA transfer mode 3: Burst-Block transfer */
#define DMADT_4             (0x4000)  /* DMA transfer mode 4: Repeated Single transfer */
#define DMADT_5             (0x5000)  /* DMA transfer mode 5: Repeated Block transfer */
#define DMADT_6             (0x6000)  /* DMA transfer mode 6: Repeated Burst-Block transfer */
#define DMADT_7             (0x7000)  /* DMA transfer mode 7: Repeated Burst-Block transfer */

/* DMAIV Definitions */
#define DMAIV_NONE           (0x0000)    /* No Interrupt pending */
#define DMAIV_DMA0IFG        (0x0002)    /* DMA0IFG*/
#define DMAIV_DMA1IFG        (0x0004)    /* DMA1IFG*/
#define DMAIV_DMA2IFG        (0x0006)    /* DMA2IFG*/

#define DMA0TSEL_0          (0x0000)  /* DMA channel 0 transfer select 0:  DMA_REQ (sw) */
#define DMA0TSEL_1          (0x0001)  /* DMA channel 0 transfer select 1:  */
#define DMA0TSEL_2          (0x0002)  /* DMA channel 0 transfer select 2:  */
#define DMA0TSEL_3          (0x0003)  /* DMA channel 0 transfer select 3:  */
#define DMA0TSEL_4          (0x0004)  /* DMA channel 0 transfer select 4:  */
#define DMA0TSEL_5          (0x0005)  /* DMA channel 0 transfer select 5:  */
#define DMA0TSEL_6          (0x0006)  /* DMA channel 0 transfer select 6:  */
#define DMA0TSEL_7          (0x0007)  /* DMA channel 0 transfer select 7:  */
#define DMA0TSEL_8          (0x0008)  /* DMA channel 0 transfer select 8:  */
#define DMA0TSEL_9          (0x0009)  /* DMA channel 0 transfer select 9:  */
#define DMA0TSEL_10         (0x000A) /* DMA channel 0 transfer select 10: */
#define DMA0TSEL_11         (0x000B) /* DMA channel 0 transfer select 11: */
#define DMA0TSEL_12         (0x000C) /* DMA channel 0 transfer select 12: */
#define DMA0TSEL_13         (0x000D) /* DMA channel 0 transfer select 13: */
#define DMA0TSEL_14         (0x000E) /* DMA channel 0 transfer select 14: */
#define DMA0TSEL_15         (0x000F) /* DMA channel 0 transfer select 15: */
#define DMA0TSEL_16         (0x0010) /* DMA channel 0 transfer select 16: */
#define DMA0TSEL_17         (0x0011) /* DMA channel 0 transfer select 17: */
#define DMA0TSEL_18         (0x0012) /* DMA channel 0 transfer select 18: */
#define DMA0TSEL_19         (0x0013) /* DMA channel 0 transfer select 19: */
#define DMA0TSEL_20         (0x0014) /* DMA channel 0 transfer select 20: */
#define DMA0TSEL_21         (0x0015) /* DMA channel 0 transfer select 21: */
#define DMA0TSEL_22         (0x0016) /* DMA channel 0 transfer select 22: */
#define DMA0TSEL_23         (0x0017) /* DMA channel 0 transfer select 23: */
#define DMA0TSEL_24         (0x0018) /* DMA channel 0 transfer select 24: */
#define DMA0TSEL_25         (0x0019) /* DMA channel 0 transfer select 25: */
#define DMA0TSEL_26         (0x001A) /* DMA channel 0 transfer select 26: */
#define DMA0TSEL_27         (0x001B) /* DMA channel 0 transfer select 27: */
#define DMA0TSEL_28         (0x001C) /* DMA channel 0 transfer select 28: */
#define DMA0TSEL_29         (0x001D) /* DMA channel 0 transfer select 29: */
#define DMA0TSEL_30         (0x001E) /* DMA channel 0 transfer select 30: previous DMA channel DMA2IFG */
#define DMA0TSEL_31         (0x001F) /* DMA channel 0 transfer select 31: ext. Trigger (DMAE0) */

#define DMA1TSEL_0          (0x0000)  /* DMA channel 1 transfer select 0:  DMA_REQ (sw) */
#define DMA1TSEL_1          (0x0100)  /* DMA channel 1 transfer select 1:  */
#define DMA1TSEL_2          (0x0200)  /* DMA channel 1 transfer select 2:  */
#define DMA1TSEL_3          (0x0300)  /* DMA channel 1 transfer select 3:  */
#define DMA1TSEL_4          (0x0400)  /* DMA channel 1 transfer select 4:  */
#define DMA1TSEL_5          (0x0500)  /* DMA channel 1 transfer select 5:  */
#define DMA1TSEL_6          (0x0600)  /* DMA channel 1 transfer select 6:  */
#define DMA1TSEL_7          (0x0700)  /* DMA channel 1 transfer select 7:  */
#define DMA1TSEL_8          (0x0800)  /* DMA channel 1 transfer select 8:  */
#define DMA1TSEL_9          (0x0900)  /* DMA channel 1 transfer select 9:  */
#define DMA1TSEL_10         (0x0A00) /* DMA channel 1 transfer select 10: */
#define DMA1TSEL_11         (0x0B00) /* DMA channel 1 transfer select 11: */
#define DMA1TSEL_12         (0x0C00) /* DMA channel 1 transfer select 12: */
#define DMA1TSEL_13         (0x0D00) /* DMA channel 1 transfer select 13: */
#define DMA1TSEL_14         (0x0E00) /* DMA channel 1 transfer select 14: */
#define DMA1TSEL_15         (0x0F00) /* DMA channel 1 transfer select 15: */
#define DMA1TSEL_16         (0x1000) /* DMA channel 1 transfer select 16: */
#define DMA1TSEL_17         (0x1100) /* DMA channel 1 transfer select 17: */
#define DMA1TSEL_18         (0x1200) /* DMA channel 1 transfer select 18: */
#define DMA1TSEL_19         (0x1300) /* DMA channel 1 transfer select 19: */
#define DMA1TSEL_20         (0x1400) /* DMA channel 1 transfer select 20: */
#define DMA1TSEL_21         (0x1500) /* DMA channel 1 transfer select 21: */
#define DMA1TSEL_22         (0x1600) /* DMA channel 1 transfer select 22: */
#define DMA1TSEL_23         (0x1700) /* DMA channel 1 transfer select 23: */
#define DMA1TSEL_24         (0x1800) /* DMA channel 1 transfer select 24: */
#define DMA1TSEL_25         (0x1900) /* DMA channel 1 transfer select 25: */
#define DMA1TSEL_26         (0x1A00) /* DMA channel 1 transfer select 26: */
#define DMA1TSEL_27         (0x1B00) /* DMA channel 1 transfer select 27: */
#define DMA1TSEL_28         (0x1C00) /* DMA channel 1 transfer select 28: */
#define DMA1TSEL_29         (0x1D00) /* DMA channel 1 transfer select 29: */
#define DMA1TSEL_30         (0x1E00) /* DMA channel 1 transfer select 30: previous DMA channel DMA0IFG */
#define DMA1TSEL_31         (0x1F00) /* DMA channel 1 transfer select 31: ext. Trigger (DMAE0) */

#define DMA2TSEL_0          (0x0000)  /* DMA channel 2 transfer select 0:  DMA_REQ (sw) */
#define DMA2TSEL_1          (0x0001)  /* DMA channel 2 transfer select 1:  */
#define DMA2TSEL_2          (0x0002)  /* DMA channel 2 transfer select 2:  */
#define DMA2TSEL_3          (0x0003)  /* DMA channel 2 transfer select 3:  */
#define DMA2TSEL_4          (0x0004)  /* DMA channel 2 transfer select 4:  */
#define DMA2TSEL_5          (0x0005)  /* DMA channel 2 transfer select 5:  */
#define DMA2TSEL_6          (0x0006)  /* DMA channel 2 transfer select 6:  */
#define DMA2TSEL_7          (0x0007)  /* DMA channel 2 transfer select 7:  */
#define DMA2TSEL_8          (0x0008)  /* DMA channel 2 transfer select 8:  */
#define DMA2TSEL_9          (0x0009)  /* DMA channel 2 transfer select 9:  */
#define DMA2TSEL_10         (0x000A) /* DMA channel 2 transfer select 10: */
#define DMA2TSEL_11         (0x000B) /* DMA channel 2 transfer select 11: */
#define DMA2TSEL_12         (0x000C) /* DMA channel 2 transfer select 12: */
#define DMA2TSEL_13         (0x000D) /* DMA channel 2 transfer select 13: */
#define DMA2TSEL_14         (0x000E) /* DMA channel 2 transfer select 14: */
#define DMA2TSEL_15         (0x000F) /* DMA channel 2 transfer select 15: */
#define DMA2TSEL_16         (0x0010) /* DMA channel 2 transfer select 16: */
#define DMA2TSEL_17         (0x0011) /* DMA channel 2 transfer select 17: */
#define DMA2TSEL_18         (0x0012) /* DMA channel 2 transfer select 18: */
#define DMA2TSEL_19         (0x0013) /* DMA channel 2 transfer select 19: */
#define DMA2TSEL_20         (0x0014) /* DMA channel 2 transfer select 20: */
#define DMA2TSEL_21         (0x0015) /* DMA channel 2 transfer select 21: */
#define DMA2TSEL_22         (0x0016) /* DMA channel 2 transfer select 22: */
#define DMA2TSEL_23         (0x0017) /* DMA channel 2 transfer select 23: */
#define DMA2TSEL_24         (0x0018) /* DMA channel 2 transfer select 24: */
#define DMA2TSEL_25         (0x0019) /* DMA channel 2 transfer select 25: */
#define DMA2TSEL_26         (0x001A) /* DMA channel 2 transfer select 26: */
#define DMA2TSEL_27         (0x001B) /* DMA channel 2 transfer select 27: */
#define DMA2TSEL_28         (0x001C) /* DMA channel 2 transfer select 28: */
#define DMA2TSEL_29         (0x001D) /* DMA channel 2 transfer select 29: */
#define DMA2TSEL_30         (0x001E) /* DMA channel 2 transfer select 30: previous DMA channel DMA1IFG */
#define DMA2TSEL_31         (0x001F) /* DMA channel 2 transfer select 31: ext. Trigger (DMAE0) */

#define DMA0TSEL__DMAREQ     (0x0000)  /* DMA channel 0 transfer select 0:  DMA_REQ (sw) */
#define DMA0TSEL__TA0CCR0    (0x0001)  /* DMA channel 0 transfer select 1:  TA0CCR0 */
#define DMA0TSEL__TA0CCR2    (0x0002)  /* DMA channel 0 transfer select 2:  TA0CCR2 */
#define DMA0TSEL__TA1CCR0    (0x0003)  /* DMA channel 0 transfer select 3:  TA1CCR0 */
#define DMA0TSEL__TA1CCR2    (0x0004)  /* DMA channel 0 transfer select 4:  TA1CCR2 */
#define DMA0TSEL__TA2CCR0    (0x0005)  /* DMA channel 0 transfer select 3:  TA2CCR0 */
#define DMA0TSEL__TA3CCR0    (0x0006)  /* DMA channel 0 transfer select 4:  TA3CCR0 */
#define DMA0TSEL__TB0CCR0    (0x0007)  /* DMA channel 0 transfer select 7:  TB0CCR0 */
#define DMA0TSEL__TB0CCR2    (0x0008)  /* DMA channel 0 transfer select 8:  TB0CCR2 */
#define DMA0TSEL__RES9       (0x0009)  /* DMA channel 0 transfer select 9:  RES9 */
#define DMA0TSEL__RES10      (0x000A) /* DMA channel 0 transfer select 10: RES10 */
#define DMA0TSEL__RES11      (0x000B) /* DMA channel 0 transfer select 11: RES11 */
#define DMA0TSEL__RES12      (0x000C) /* DMA channel 0 transfer select 12: RES12 */
#define DMA0TSEL__RES13      (0x000D) /* DMA channel 0 transfer select 13: RES13 */
#define DMA0TSEL__UCA0RXIFG  (0x000E) /* DMA channel 0 transfer select 14: UCA0RXIFG */
#define DMA0TSEL__UCA0TXIFG  (0x000F) /* DMA channel 0 transfer select 15: UCA0TXIFG */
#define DMA0TSEL__UCA1RXIFG  (0x0010) /* DMA channel 0 transfer select 16: UCA1RXIFG */
#define DMA0TSEL__UCA1TXIFG  (0x0011) /* DMA channel 0 transfer select 17: UCA1TXIFG */
#define DMA0TSEL__UCB0RXIFG0 (0x0012) /* DMA channel 0 transfer select 18: UCB0RXIFG0 */
#define DMA0TSEL__UCB0TXIFG0 (0x0013) /* DMA channel 0 transfer select 19: UCB0TXIFG0 */
#define DMA0TSEL__UCB0RXIFG1 (0x0014) /* DMA channel 0 transfer select 20: UCB0RXIFG1 */
#define DMA0TSEL__UCB0TXIFG1 (0x0015) /* DMA channel 0 transfer select 21: UCB0TXIFG1 */
#define DMA0TSEL__UCB0RXIFG2 (0x0016) /* DMA channel 0 transfer select 22: UCB0RXIFG2 */
#define DMA0TSEL__UCB0TXIFG2 (0x0017) /* DMA channel 0 transfer select 23: UCB0TXIFG2 */
#define DMA0TSEL__UCB0RXIFG3 (0x0018) /* DMA channel 0 transfer select 24: UCB0RXIFG3 */
#define DMA0TSEL__UCB0TXIFG3 (0x0019) /* DMA channel 0 transfer select 25: UCB0TXIFG3 */
#define DMA0TSEL__ADC12IFG   (0x001A) /* DMA channel 0 transfer select 26: ADC12IFG */
#define DMA0TSEL__RES27      (0x001B) /* DMA channel 0 transfer select 27: RES27 */
#define DMA0TSEL__RES28      (0x001C) /* DMA channel 0 transfer select 28: RES28 */
#define DMA0TSEL__MPY        (0x001D) /* DMA channel 0 transfer select 29: MPY */
#define DMA0TSEL__DMA2IFG    (0x001E) /* DMA channel 0 transfer select 30: previous DMA channel DMA2IFG */
#define DMA0TSEL__DMAE0      (0x001F) /* DMA channel 0 transfer select 31: ext. Trigger (DMAE0) */

#define DMA1TSEL__DMAREQ     (0x0000)  /* DMA channel 1 transfer select 0:  DMA_REQ (sw) */
#define DMA1TSEL__TA0CCR0    (0x0100)  /* DMA channel 1 transfer select 1:  TA0CCR0 */
#define DMA1TSEL__TA0CCR2    (0x0200)  /* DMA channel 1 transfer select 2:  TA0CCR2 */
#define DMA1TSEL__TA1CCR0    (0x0300)  /* DMA channel 1 transfer select 3:  TA1CCR0 */
#define DMA1TSEL__TA1CCR2    (0x0400)  /* DMA channel 1 transfer select 4:  TA1CCR2 */
#define DMA1TSEL__TA2CCR0    (0x0500)  /* DMA channel 1 transfer select 5:  TA2CCR0 */
#define DMA1TSEL__TA3CCR0    (0x0600)  /* DMA channel 1 transfer select 6:  TA3CCR0 */
#define DMA1TSEL__TB0CCR0    (0x0700)  /* DMA channel 1 transfer select 7:  TB0CCR0 */
#define DMA1TSEL__TB0CCR2    (0x0800)  /* DMA channel 1 transfer select 8:  TB0CCR2 */
#define DMA1TSEL__RES9       (0x0900)  /* DMA channel 1 transfer select 9:  RES9 */
#define DMA1TSEL__RES10      (0x0A00) /* DMA channel 1 transfer select 10: RES10 */
#define DMA1TSEL__RES11      (0x0B00) /* DMA channel 1 transfer select 11: RES11 */
#define DMA1TSEL__RES12      (0x0C00) /* DMA channel 1 transfer select 12: RES12 */
#define DMA1TSEL__RES13      (0x0D00) /* DMA channel 1 transfer select 13: RES13 */
#define DMA1TSEL__UCA0RXIFG  (0x0E00) /* DMA channel 1 transfer select 14: UCA0RXIFG */
#define DMA1TSEL__UCA0TXIFG  (0x0F00) /* DMA channel 1 transfer select 15: UCA0TXIFG */
#define DMA1TSEL__UCA1RXIFG  (0x1000) /* DMA channel 1 transfer select 16: UCA1RXIFG */
#define DMA1TSEL__UCA1TXIFG  (0x1100) /* DMA channel 1 transfer select 17: UCA1TXIFG */
#define DMA1TSEL__UCB0RXIFG0 (0x1200) /* DMA channel 1 transfer select 18: UCB0RXIFG0 */
#define DMA1TSEL__UCB0TXIFG0 (0x1300) /* DMA channel 1 transfer select 19: UCB0TXIFG0 */
#define DMA1TSEL__UCB0RXIFG1 (0x1400) /* DMA channel 1 transfer select 20: UCB0RXIFG1 */
#define DMA1TSEL__UCB0TXIFG1 (0x1500) /* DMA channel 1 transfer select 21: UCB0TXIFG1 */
#define DMA1TSEL__UCB0RXIFG2 (0x1600) /* DMA channel 1 transfer select 22: UCB0RXIFG2 */
#define DMA1TSEL__UCB0TXIFG2 (0x1700) /* DMA channel 1 transfer select 23: UCB0TXIFG2 */
#define DMA1TSEL__UCB0RXIFG3 (0x1800) /* DMA channel 1 transfer select 24: UCB0RXIFG3 */
#define DMA1TSEL__UCB0TXIFG3 (0x1900) /* DMA channel 1 transfer select 25: UCB0TXIFG3 */
#define DMA1TSEL__ADC12IFG   (0x1A00) /* DMA channel 1 transfer select 26: ADC12IFG */
#define DMA1TSEL__RES27      (0x1B00) /* DMA channel 1 transfer select 27: RES27 */
#define DMA1TSEL__RES28      (0x1C00) /* DMA channel 1 transfer select 28: RES28 */
#define DMA1TSEL__MPY        (0x1D00) /* DMA channel 1 transfer select 29: MPY */
#define DMA1TSEL__DMA2IFG    (0x1E00) /* DMA channel 1 transfer select 30: previous DMA channel DMA2IFG */
#define DMA1TSEL__DMAE0      (0x1F00) /* DMA channel 1 transfer select 31: ext. Trigger (DMAE0) */

#define DMA2TSEL__DMAREQ     (0x0000)  /* DMA channel 2 transfer select 0:  DMA_REQ (sw) */
#define DMA2TSEL__TA0CCR0    (0x0001)  /* DMA channel 2 transfer select 1:  TA0CCR0 */
#define DMA2TSEL__TA0CCR2    (0x0002)  /* DMA channel 2 transfer select 2:  TA0CCR2 */
#define DMA2TSEL__TA1CCR0    (0x0003)  /* DMA channel 2 transfer select 3:  TA1CCR0 */
#define DMA2TSEL__TA1CCR2    (0x0004)  /* DMA channel 2 transfer select 4:  TA1CCR2 */
#define DMA2TSEL__TA2CCR0    (0x0005)  /* DMA channel 2 transfer select 5:  TA2CCR0 */
#define DMA2TSEL__TA3CCR0    (0x0006)  /* DMA channel 2 transfer select 6:  TA3CCR0 */
#define DMA2TSEL__TB0CCR0    (0x0007)  /* DMA channel 2 transfer select 7:  TB0CCR0 */
#define DMA2TSEL__TB0CCR2    (0x0008)  /* DMA channel 2 transfer select 8:  TB0CCR2 */
#define DMA2TSEL__RES9       (0x0009)  /* DMA channel 2 transfer select 9:  RES9 */
#define DMA2TSEL__RES10      (0x000A) /* DMA channel 2 transfer select 10: RES10 */
#define DMA2TSEL__RES11      (0x000B) /* DMA channel 2 transfer select 11: RES11 */
#define DMA2TSEL__RES12      (0x000C) /* DMA channel 2 transfer select 12: RES12 */
#define DMA2TSEL__RES13      (0x000D) /* DMA channel 2 transfer select 13: RES13 */
#define DMA2TSEL__UCA0RXIFG  (0x000E) /* DMA channel 2 transfer select 14: UCA0RXIFG */
#define DMA2TSEL__UCA0TXIFG  (0x000F) /* DMA channel 2 transfer select 15: UCA0TXIFG */
#define DMA2TSEL__UCA1RXIFG  (0x0010) /* DMA channel 2 transfer select 16: UCA1RXIFG */
#define DMA2TSEL__UCA1TXIFG  (0x0011) /* DMA channel 2 transfer select 17: UCA1TXIFG */
#define DMA2TSEL__UCB0RXIFG0 (0x0012) /* DMA channel 2 transfer select 18: UCB0RXIFG0 */
#define DMA2TSEL__UCB0TXIFG0 (0x0013) /* DMA channel 2 transfer select 19: UCB0TXIFG0 */
#define DMA2TSEL__UCB0RXIFG1 (0x0014) /* DMA channel 2 transfer select 20: UCB0RXIFG1 */
#define DMA2TSEL__UCB0TXIFG1 (0x0015) /* DMA channel 2 transfer select 21: UCB0TXIFG1 */
#define DMA2TSEL__UCB0RXIFG2 (0x0016) /* DMA channel 2 transfer select 22: UCB0RXIFG2 */
#define DMA2TSEL__UCB0TXIFG2 (0x0017) /* DMA channel 2 transfer select 23: UCB0TXIFG2 */
#define DMA2TSEL__UCB0RXIFG3 (0x0018) /* DMA channel 2 transfer select 24: UCB0RXIFG3 */
#define DMA2TSEL__UCB0TXIFG3 (0x0019) /* DMA channel 2 transfer select 25: UCB0TXIFG3 */
#define DMA2TSEL__ADC12IFG   (0x001A) /* DMA channel 2 transfer select 26: ADC12IFG */
#define DMA2TSEL__RES27      (0x001B) /* DMA channel 2 transfer select 27: RES27 */
#define DMA2TSEL__RES28      (0x001C) /* DMA channel 2 transfer select 28: RES28 */
#define DMA2TSEL__MPY        (0x001D) /* DMA channel 2 transfer select 29: MPY */
#define DMA2TSEL__DMA2IFG    (0x001E) /* DMA channel 2 transfer select 30: previous DMA channel DMA2IFG */
#define DMA2TSEL__DMAE0      (0x001F) /* DMA channel 2 transfer select 31: ext. Trigger (DMAE0) */

/*************************************************************
* FRAM Memory
*************************************************************/
#define __MSP430_HAS_FRAM__           /* Definition to show that Module is available */
#define __MSP430_BASEADDRESS_FRAM__ 0x0140
#define FRAM_BASE __MSP430_BASEADDRESS_FRAM__

#define FRCTL0_               0x0140    /* FRAM Controller Control 0 */
sfrb(FRCTL0_L , FRCTL0_);
sfrb(FRCTL0_H , FRCTL0_+1);
sfrw(FRCTL0, FRCTL0_);
#define GCCTL0_               0x0144    /* General Control 0 */
sfrb(GCCTL0_L , GCCTL0_);
sfrb(GCCTL0_H , GCCTL0_+1);
sfrw(GCCTL0, GCCTL0_);
#define GCCTL1_               0x0146    /* General Control 1 */
sfrb(GCCTL1_L , GCCTL1_);
sfrb(GCCTL1_H , GCCTL1_+1);
sfrw(GCCTL1, GCCTL1_);

#define FRCTLPW             (0xA500)  /* FRAM password for write */
#define FRPW                (0x9600)  /* FRAM password returned by read */
#define FWPW                (0xA500)  /* FRAM password for write */
#define FXPW                (0x3300)  /* for use with XOR instruction */

/* FRCTL0 Control Bits */
//#define RESERVED            (0x0001)  /* RESERVED */
//#define RESERVED            (0x0002)  /* RESERVED */
//#define RESERVED            (0x0004)  /* RESERVED */
#define NWAITS0             (0x0010)  /* FRAM Wait state control Bit: 0 */
#define NWAITS1             (0x0020)  /* FRAM Wait state control Bit: 1 */
#define NWAITS2             (0x0040)  /* FRAM Wait state control Bit: 2 */
//#define RESERVED            (0x0080)  /* RESERVED */

/* FRCTL0 Control Bits */
//#define RESERVED            (0x0001)  /* RESERVED */
//#define RESERVED            (0x0002)  /* RESERVED */
//#define RESERVED            (0x0004)  /* RESERVED */
#define NWAITS0_L           (0x0010)  /* FRAM Wait state control Bit: 0 */
#define NWAITS1_L           (0x0020)  /* FRAM Wait state control Bit: 1 */
#define NWAITS2_L           (0x0040)  /* FRAM Wait state control Bit: 2 */
//#define RESERVED            (0x0080)  /* RESERVED */


#define NWAITS_0            (0x0000)  /* FRAM Wait state control: 0 */
#define NWAITS_1            (0x0010)  /* FRAM Wait state control: 1 */
#define NWAITS_2            (0x0020)  /* FRAM Wait state control: 2 */
#define NWAITS_3            (0x0030)  /* FRAM Wait state control: 3 */
#define NWAITS_4            (0x0040)  /* FRAM Wait state control: 4 */
#define NWAITS_5            (0x0050)  /* FRAM Wait state control: 5 */
#define NWAITS_6            (0x0060)  /* FRAM Wait state control: 6 */
#define NWAITS_7            (0x0070)  /* FRAM Wait state control: 7 */


/* Legacy Defines */
#define NAUTO               (0x0008)  /* FRAM Disables the wait state generator (obsolete on Rev.E and later)*/
#define NACCESS0            (0x0010)  /* FRAM Wait state Generator Access Time control Bit: 0 */
#define NACCESS1            (0x0020)  /* FRAM Wait state Generator Access Time control Bit: 1 */
#define NACCESS2            (0x0040)  /* FRAM Wait state Generator Access Time control Bit: 2 */
#define NACCESS_0           (0x0000)  /* FRAM Wait state Generator Access Time control: 0 */
#define NACCESS_1           (0x0010)  /* FRAM Wait state Generator Access Time control: 1 */
#define NACCESS_2           (0x0020)  /* FRAM Wait state Generator Access Time control: 2 */
#define NACCESS_3           (0x0030)  /* FRAM Wait state Generator Access Time control: 3 */
#define NACCESS_4           (0x0040)  /* FRAM Wait state Generator Access Time control: 4 */
#define NACCESS_5           (0x0050)  /* FRAM Wait state Generator Access Time control: 5 */
#define NACCESS_6           (0x0060)  /* FRAM Wait state Generator Access Time control: 6 */
#define NACCESS_7           (0x0070)  /* FRAM Wait state Generator Access Time control: 7 */


/* GCCTL0 Control Bits */
//#define RESERVED            (0x0001)  /* RESERVED */
#define FRLPMPWR            (0x0002)  /* FRAM Enable FRAM auto power up after LPM */
#define FRPWR               (0x0004)  /* FRAM Power Control */
#define ACCTEIE             (0x0008)  /* Enable NMI event if Access time error occurs */
//#define RESERVED            (0x0010)  /* RESERVED */
#define CBDIE               (0x0020)  /* Enable NMI event if correctable bit error detected */
#define UBDIE               (0x0040)  /* Enable NMI event if uncorrectable bit error detected */
#define UBDRSTEN            (0x0080)  /* Enable Power Up Clear (PUC) reset if FRAM uncorrectable bit error detected */

/* GCCTL0 Control Bits */
//#define RESERVED            (0x0001)  /* RESERVED */
#define FRLPMPWR_L          (0x0002)  /* FRAM Enable FRAM auto power up after LPM */
#define FRPWR_L             (0x0004)  /* FRAM Power Control */
#define ACCTEIE_L           (0x0008)  /* Enable NMI event if Access time error occurs */
//#define RESERVED            (0x0010)  /* RESERVED */
#define CBDIE_L             (0x0020)  /* Enable NMI event if correctable bit error detected */
#define UBDIE_L             (0x0040)  /* Enable NMI event if uncorrectable bit error detected */
#define UBDRSTEN_L          (0x0080)  /* Enable Power Up Clear (PUC) reset if FRAM uncorrectable bit error detected */


/* GCCTL1 Control Bits */
//#define RESERVED            (0x0001)  /* RESERVED */
#define CBDIFG              (0x0002)  /* FRAM correctable bit error flag */
#define UBDIFG              (0x0004)  /* FRAM uncorrectable bit error flag */
#define ACCTEIFG            (0x0008)  /* Access time error flag */

/* GCCTL1 Control Bits */
//#define RESERVED            (0x0001)  /* RESERVED */
#define CBDIFG_L            (0x0002)  /* FRAM correctable bit error flag */
#define UBDIFG_L            (0x0004)  /* FRAM uncorrectable bit error flag */
#define ACCTEIFG_L          (0x0008)  /* Access time error flag */


/************************************************************
* Memory Protection Unit
************************************************************/
#define __MSP430_HAS_MPU__             /* Definition to show that Module is available */
#define __MSP430_BASEADDRESS_MPU__ 0x05A0
#define MPU_BASE __MSP430_BASEADDRESS_MPU__

#define MPUCTL0_              0x05A0    /* MPU Control Register 0 */
sfrb(MPUCTL0_L , MPUCTL0_);
sfrb(MPUCTL0_H , MPUCTL0_+1);
sfrw(MPUCTL0, MPUCTL0_);
#define MPUCTL1_              0x05A2    /* MPU Control Register 1 */
sfrb(MPUCTL1_L , MPUCTL1_);
sfrb(MPUCTL1_H , MPUCTL1_+1);
sfrw(MPUCTL1, MPUCTL1_);
#define MPUSEGB2_             0x05A4    /* MPU Segmentation Border 2 Register */
sfrb(MPUSEGB2_L , MPUSEGB2_);
sfrb(MPUSEGB2_H , MPUSEGB2_+1);
sfrw(MPUSEGB2, MPUSEGB2_);
#define MPUSEGB1_             0x05A6    /* MPU Segmentation Border 1 Register */
sfrb(MPUSEGB1_L , MPUSEGB1_);
sfrb(MPUSEGB1_H , MPUSEGB1_+1);
sfrw(MPUSEGB1, MPUSEGB1_);
#define MPUSAM_               0x05A8    /* MPU Access Management Register */
sfrb(MPUSAM_L , MPUSAM_);
sfrb(MPUSAM_H , MPUSAM_+1);
sfrw(MPUSAM, MPUSAM_);
#define MPUIPC0_              0x05AA    /* MPU IP Control 0 Register */
sfrb(MPUIPC0_L , MPUIPC0_);
sfrb(MPUIPC0_H , MPUIPC0_+1);
sfrw(MPUIPC0, MPUIPC0_);
#define MPUIPSEGB2_           0x05AC    /* MPU IP Segment Border 2 Register */
sfrb(MPUIPSEGB2_L , MPUIPSEGB2_);
sfrb(MPUIPSEGB2_H , MPUIPSEGB2_+1);
sfrw(MPUIPSEGB2, MPUIPSEGB2_);
#define MPUIPSEGB1_           0x05AE    /* MPU IP Segment Border 1 Register */
sfrb(MPUIPSEGB1_L , MPUIPSEGB1_);
sfrb(MPUIPSEGB1_H , MPUIPSEGB1_+1);
sfrw(MPUIPSEGB1, MPUIPSEGB1_);


/* MPUCTL0 Control Bits */
#define MPUENA               (0x0001)  /* MPU Enable */
#define MPULOCK              (0x0002)  /* MPU Lock */
#define MPUSEGIE             (0x0010)  /* MPU Enable NMI on Segment violation */

/* MPUCTL0 Control Bits */
#define MPUENA_L            (0x0001)  /* MPU Enable */
#define MPULOCK_L           (0x0002)  /* MPU Lock */
#define MPUSEGIE_L          (0x0010)  /* MPU Enable NMI on Segment violation */

#define MPUPW                (0xA500)  /* MPU Access Password */
#define MPUPW_H              (0xA5)    /* MPU Access Password */

/* MPUCTL1 Control Bits */
#define MPUSEG1IFG           (0x0001)  /* MPU Main Memory Segment 1 violation interupt flag */
#define MPUSEG2IFG           (0x0002)  /* MPU Main Memory Segment 2 violation interupt flag */
#define MPUSEG3IFG           (0x0004)  /* MPU Main Memory Segment 3 violation interupt flag */
#define MPUSEGIIFG           (0x0008)  /* MPU Info Memory Segment violation interupt flag */
#define MPUSEGIPIFG          (0x0010)  /* MPU IP Memory Segment violation interupt flag */

/* MPUCTL1 Control Bits */
#define MPUSEG1IFG_L        (0x0001)  /* MPU Main Memory Segment 1 violation interupt flag */
#define MPUSEG2IFG_L        (0x0002)  /* MPU Main Memory Segment 2 violation interupt flag */
#define MPUSEG3IFG_L        (0x0004)  /* MPU Main Memory Segment 3 violation interupt flag */
#define MPUSEGIIFG_L        (0x0008)  /* MPU Info Memory Segment violation interupt flag */
#define MPUSEGIPIFG_L       (0x0010)  /* MPU IP Memory Segment violation interupt flag */


/* MPUSEGB2 Control Bits */

/* MPUSEGB2 Control Bits */

/* MPUSEGB2 Control Bits */

/* MPUSEGB1 Control Bits */

/* MPUSEGB1 Control Bits */

/* MPUSEGB1 Control Bits */

/* MPUSAM Control Bits */
#define MPUSEG1RE            (0x0001)  /* MPU Main memory Segment 1 Read enable */
#define MPUSEG1WE            (0x0002)  /* MPU Main memory Segment 1 Write enable */
#define MPUSEG1XE            (0x0004)  /* MPU Main memory Segment 1 Execute enable */
#define MPUSEG1VS            (0x0008)  /* MPU Main memory Segment 1 Violation select */
#define MPUSEG2RE            (0x0010)  /* MPU Main memory Segment 2 Read enable */
#define MPUSEG2WE            (0x0020)  /* MPU Main memory Segment 2 Write enable */
#define MPUSEG2XE            (0x0040)  /* MPU Main memory Segment 2 Execute enable */
#define MPUSEG2VS            (0x0080)  /* MPU Main memory Segment 2 Violation select */
#define MPUSEG3RE            (0x0100)  /* MPU Main memory Segment 3 Read enable */
#define MPUSEG3WE            (0x0200)  /* MPU Main memory Segment 3 Write enable */
#define MPUSEG3XE            (0x0400)  /* MPU Main memory Segment 3 Execute enable */
#define MPUSEG3VS            (0x0800)  /* MPU Main memory Segment 3 Violation select */
#define MPUSEGIRE            (0x1000)  /* MPU Info memory Segment Read enable */
#define MPUSEGIWE            (0x2000)  /* MPU Info memory Segment Write enable */
#define MPUSEGIXE            (0x4000)  /* MPU Info memory Segment Execute enable */
#define MPUSEGIVS            (0x8000)  /* MPU Info memory Segment Violation select */

/* MPUSAM Control Bits */
#define MPUSEG1RE_L         (0x0001)  /* MPU Main memory Segment 1 Read enable */
#define MPUSEG1WE_L         (0x0002)  /* MPU Main memory Segment 1 Write enable */
#define MPUSEG1XE_L         (0x0004)  /* MPU Main memory Segment 1 Execute enable */
#define MPUSEG1VS_L         (0x0008)  /* MPU Main memory Segment 1 Violation select */
#define MPUSEG2RE_L         (0x0010)  /* MPU Main memory Segment 2 Read enable */
#define MPUSEG2WE_L         (0x0020)  /* MPU Main memory Segment 2 Write enable */
#define MPUSEG2XE_L         (0x0040)  /* MPU Main memory Segment 2 Execute enable */
#define MPUSEG2VS_L         (0x0080)  /* MPU Main memory Segment 2 Violation select */

/* MPUSAM Control Bits */
#define MPUSEG3RE_H         (0x0001)  /* MPU Main memory Segment 3 Read enable */
#define MPUSEG3WE_H         (0x0002)  /* MPU Main memory Segment 3 Write enable */
#define MPUSEG3XE_H         (0x0004)  /* MPU Main memory Segment 3 Execute enable */
#define MPUSEG3VS_H         (0x0008)  /* MPU Main memory Segment 3 Violation select */
#define MPUSEGIRE_H         (0x0010)  /* MPU Info memory Segment Read enable */
#define MPUSEGIWE_H         (0x0020)  /* MPU Info memory Segment Write enable */
#define MPUSEGIXE_H         (0x0040)  /* MPU Info memory Segment Execute enable */
#define MPUSEGIVS_H         (0x0080)  /* MPU Info memory Segment Violation select */

/* MPUIPC0 Control Bits */
#define MPUIPVS              (0x0020)  /* MPU MPU IP protection segment Violation Select */
#define MPUIPENA             (0x0040)  /* MPU MPU IP Protection Enable */
#define MPUIPLOCK            (0x0080)  /* MPU IP Protection Lock */

/* MPUIPC0 Control Bits */
#define MPUIPVS_L           (0x0020)  /* MPU MPU IP protection segment Violation Select */
#define MPUIPENA_L          (0x0040)  /* MPU MPU IP Protection Enable */
#define MPUIPLOCK_L         (0x0080)  /* MPU IP Protection Lock */


/* MPUIPSEGB2 Control Bits */

/* MPUIPSEGB2 Control Bits */

/* MPUIPSEGB2 Control Bits */

/* MPUIPSEGB1 Control Bits */

/* MPUIPSEGB1 Control Bits */

/* MPUIPSEGB1 Control Bits */

/************************************************************
* HARDWARE MULTIPLIER 32Bit
************************************************************/
#define __MSP430_HAS_MPY32__          /* Definition to show that Module is available */
#define __MSP430_BASEADDRESS_MPY32__ 0x04C0
#define MPY32_BASE __MSP430_BASEADDRESS_MPY32__

#define MPY_                  0x04C0    /* Multiply Unsigned/Operand 1 */
sfrb(MPY_L , MPY_);
sfrb(MPY_H , MPY_+1);
sfrw(MPY, MPY_);
#define MPYS_                 0x04C2    /* Multiply Signed/Operand 1 */
sfrb(MPYS_L , MPYS_);
sfrb(MPYS_H , MPYS_+1);
sfrw(MPYS, MPYS_);
#define MAC_                  0x04C4    /* Multiply Unsigned and Accumulate/Operand 1 */
sfrb(MAC_L , MAC_);
sfrb(MAC_H , MAC_+1);
sfrw(MAC, MAC_);
#define MACS_                 0x04C6    /* Multiply Signed and Accumulate/Operand 1 */
sfrb(MACS_L , MACS_);
sfrb(MACS_H , MACS_+1);
sfrw(MACS, MACS_);
#define OP2_                  0x04C8    /* Operand 2 */
sfrb(OP2_L , OP2_);
sfrb(OP2_H , OP2_+1);
sfrw(OP2, OP2_);
#define RESLO_                0x04CA    /* Result Low Word */
sfrb(RESLO_L , RESLO_);
sfrb(RESLO_H , RESLO_+1);
sfrw(RESLO, RESLO_);
#define RESHI_                0x04CC    /* Result High Word */
sfrb(RESHI_L , RESHI_);
sfrb(RESHI_H , RESHI_+1);
sfrw(RESHI, RESHI_);
#define SUMEXT_               0x04CE    /* Sum Extend */
const_sfrb(SUMEXT_L , SUMEXT_);
const_sfrb(SUMEXT_H , SUMEXT_+1);
const_sfrw(SUMEXT, SUMEXT_);

#define MPY32L_               0x04D0    /* 32-bit operand 1 - multiply - low word */
sfrb(MPY32L_L , MPY32L_);
sfrb(MPY32L_H , MPY32L_+1);
sfrw(MPY32L, MPY32L_);
#define MPY32H_               0x04D2    /* 32-bit operand 1 - multiply - high word */
sfrb(MPY32H_L , MPY32H_);
sfrb(MPY32H_H , MPY32H_+1);
sfrw(MPY32H, MPY32H_);
#define MPYS32L_              0x04D4    /* 32-bit operand 1 - signed multiply - low word */
sfrb(MPYS32L_L , MPYS32L_);
sfrb(MPYS32L_H , MPYS32L_+1);
sfrw(MPYS32L, MPYS32L_);
#define MPYS32H_              0x04D6    /* 32-bit operand 1 - signed multiply - high word */
sfrb(MPYS32H_L , MPYS32H_);
sfrb(MPYS32H_H , MPYS32H_+1);
sfrw(MPYS32H, MPYS32H_);
#define MAC32L_               0x04D8    /* 32-bit operand 1 - multiply accumulate - low word */
sfrb(MAC32L_L , MAC32L_);
sfrb(MAC32L_H , MAC32L_+1);
sfrw(MAC32L, MAC32L_);
#define MAC32H_               0x04DA    /* 32-bit operand 1 - multiply accumulate - high word */
sfrb(MAC32H_L , MAC32H_);
sfrb(MAC32H_H , MAC32H_+1);
sfrw(MAC32H, MAC32H_);
#define MACS32L_              0x04DC    /* 32-bit operand 1 - signed multiply accumulate - low word */
sfrb(MACS32L_L , MACS32L_);
sfrb(MACS32L_H , MACS32L_+1);
sfrw(MACS32L, MACS32L_);
#define MACS32H_              0x04DE    /* 32-bit operand 1 - signed multiply accumulate - high word */
sfrb(MACS32H_L , MACS32H_);
sfrb(MACS32H_H , MACS32H_+1);
sfrw(MACS32H, MACS32H_);
#define OP2L_                 0x04E0    /* 32-bit operand 2 - low word */
sfrb(OP2L_L , OP2L_);
sfrb(OP2L_H , OP2L_+1);
sfrw(OP2L, OP2L_);
#define OP2H_                 0x04E2    /* 32-bit operand 2 - high word */
sfrb(OP2H_L , OP2H_);
sfrb(OP2H_H , OP2H_+1);
sfrw(OP2H, OP2H_);
#define RES0_                 0x04E4    /* 32x32-bit result 0 - least significant word */
sfrb(RES0_L , RES0_);
sfrb(RES0_H , RES0_+1);
sfrw(RES0, RES0_);
#define RES1_                 0x04E6    /* 32x32-bit result 1 */
sfrb(RES1_L , RES1_);
sfrb(RES1_H , RES1_+1);
sfrw(RES1, RES1_);
#define RES2_                 0x04E8    /* 32x32-bit result 2 */
sfrb(RES2_L , RES2_);
sfrb(RES2_H , RES2_+1);
sfrw(RES2, RES2_);
#define RES3_                 0x04EA    /* 32x32-bit result 3 - most significant word */
sfrb(RES3_L , RES3_);
sfrb(RES3_H , RES3_+1);
sfrw(RES3, RES3_);
#define MPY32CTL0_            0x04EC    /* MPY32 Control Register 0 */
sfrb(MPY32CTL0_L , MPY32CTL0_);
sfrb(MPY32CTL0_H , MPY32CTL0_+1);
sfrw(MPY32CTL0, MPY32CTL0_);

#define MPY_B               MPY_L      /* Multiply Unsigned/Operand 1 (Byte Access) */
#define MPYS_B              MPYS_L     /* Multiply Signed/Operand 1 (Byte Access) */
#define MAC_B               MAC_L      /* Multiply Unsigned and Accumulate/Operand 1 (Byte Access) */
#define MACS_B              MACS_L     /* Multiply Signed and Accumulate/Operand 1 (Byte Access) */
#define OP2_B               OP2_L      /* Operand 2 (Byte Access) */
#define MPY32L_B            MPY32L_L   /* 32-bit operand 1 - multiply - low word (Byte Access) */
#define MPY32H_B            MPY32H_L   /* 32-bit operand 1 - multiply - high word (Byte Access) */
#define MPYS32L_B           MPYS32L_L  /* 32-bit operand 1 - signed multiply - low word (Byte Access) */
#define MPYS32H_B           MPYS32H_L  /* 32-bit operand 1 - signed multiply - high word (Byte Access) */
#define MAC32L_B            MAC32L_L   /* 32-bit operand 1 - multiply accumulate - low word (Byte Access) */
#define MAC32H_B            MAC32H_L   /* 32-bit operand 1 - multiply accumulate - high word (Byte Access) */
#define MACS32L_B           MACS32L_L  /* 32-bit operand 1 - signed multiply accumulate - low word (Byte Access) */
#define MACS32H_B           MACS32H_L  /* 32-bit operand 1 - signed multiply accumulate - high word (Byte Access) */
#define OP2L_B              OP2L_L     /* 32-bit operand 2 - low word (Byte Access) */
#define OP2H_B              OP2H_L     /* 32-bit operand 2 - high word (Byte Access) */


/* MPY32CTL0 Control Bits */
#define MPYC                (0x0001)  /* Carry of the multiplier */
//#define RESERVED            (0x0002)  /* Reserved */
#define MPYFRAC             (0x0004)  /* Fractional mode */
#define MPYSAT              (0x0008)  /* Saturation mode */
#define MPYM0               (0x0010)  /* Multiplier mode Bit:0 */
#define MPYM1               (0x0020)  /* Multiplier mode Bit:1 */
#define OP1_32              (0x0040)  /* Bit-width of operand 1 0:16Bit / 1:32Bit */
#define OP2_32              (0x0080)  /* Bit-width of operand 2 0:16Bit / 1:32Bit */
#define MPYDLYWRTEN         (0x0100)  /* Delayed write enable */
#define MPYDLY32            (0x0200)  /* Delayed write mode */

/* MPY32CTL0 Control Bits */
#define MPYC_L              (0x0001)  /* Carry of the multiplier */
//#define RESERVED            (0x0002)  /* Reserved */
#define MPYFRAC_L           (0x0004)  /* Fractional mode */
#define MPYSAT_L            (0x0008)  /* Saturation mode */
#define MPYM0_L             (0x0010)  /* Multiplier mode Bit:0 */
#define MPYM1_L             (0x0020)  /* Multiplier mode Bit:1 */
#define OP1_32_L            (0x0040)  /* Bit-width of operand 1 0:16Bit / 1:32Bit */
#define OP2_32_L            (0x0080)  /* Bit-width of operand 2 0:16Bit / 1:32Bit */

/* MPY32CTL0 Control Bits */
//#define RESERVED            (0x0002)  /* Reserved */
#define MPYDLYWRTEN_H       (0x0001)  /* Delayed write enable */
#define MPYDLY32_H          (0x0002)  /* Delayed write mode */

#define MPYM_0              (0x0000)  /* Multiplier mode: MPY */
#define MPYM_1              (0x0010)  /* Multiplier mode: MPYS */
#define MPYM_2              (0x0020)  /* Multiplier mode: MAC */
#define MPYM_3              (0x0030)  /* Multiplier mode: MACS */
#define MPYM__MPY           (0x0000)  /* Multiplier mode: MPY */
#define MPYM__MPYS          (0x0010)  /* Multiplier mode: MPYS */
#define MPYM__MAC           (0x0020)  /* Multiplier mode: MAC */
#define MPYM__MACS          (0x0030)  /* Multiplier mode: MACS */

/************************************************************
* PMM - Power Management System for FRAM
************************************************************/
#define __MSP430_HAS_PMM_FRAM__       /* Definition to show that Module is available */
#define __MSP430_BASEADDRESS_PMM_FRAM__ 0x0120
#define PMM_BASE __MSP430_BASEADDRESS_PMM_FRAM__

#define PMMCTL0_              0x0120    /* PMM Control 0 */
sfrb(PMMCTL0_L , PMMCTL0_);
sfrb(PMMCTL0_H , PMMCTL0_+1);
sfrw(PMMCTL0, PMMCTL0_);
#define PMMCTL1_              0x0122    /* PMM Control 1 */
sfrw(PMMCTL1, PMMCTL1_);
#define PMMIFG_               0x012A    /* PMM Interrupt Flag */
sfrb(PMMIFG_L , PMMIFG_);
sfrb(PMMIFG_H , PMMIFG_+1);
sfrw(PMMIFG, PMMIFG_);
#define PM5CTL0_              0x0130    /* PMM Power Mode 5 Control Register 0 */
sfrb(PM5CTL0_L , PM5CTL0_);
sfrb(PM5CTL0_H , PM5CTL0_+1);
sfrw(PM5CTL0, PM5CTL0_);

#define PMMPW               (0xA500)  /* PMM Register Write Password */
#define PMMPW_H             (0xA5)    /* PMM Register Write Password for high word access */

/* PMMCTL0 Control Bits */
#define PMMSWBOR            (0x0004)  /* PMM Software BOR */
#define PMMSWPOR            (0x0008)  /* PMM Software POR */
#define PMMREGOFF           (0x0010)  /* PMM Turn Regulator off */
#define SVSHE               (0x0040)  /* SVS high side enable */
#define PMMLPRST            (0x0080)  /* PMM Low-Power Reset Enable */

/* PMMCTL0 Control Bits */
#define PMMSWBOR_L          (0x0004)  /* PMM Software BOR */
#define PMMSWPOR_L          (0x0008)  /* PMM Software POR */
#define PMMREGOFF_L         (0x0010)  /* PMM Turn Regulator off */
#define SVSHE_L             (0x0040)  /* SVS high side enable */
#define PMMLPRST_L          (0x0080)  /* PMM Low-Power Reset Enable */


/* PMMCTL1 Control Bits */
#define PMMLPSVEN           (0x0002)  /* PMM Low-Power Supervision Enable */
#define PMMLPRNG0           (0x0004)  /* PMM Load Range Control overwrite for LPM2, LPM3 and LPM4 Bit: 0 */
#define PMMLPRNG1           (0x0008)  /* PMM Load Range Control overwrite for LPM2, LPM3 and LPM4 Bit: 1 */
#define PMMAMRNG0           (0x0010)  /* Load Range Control overwrite for AM, LPM0 and LPM1 Bit: 0 */
#define PMMAMRNG1           (0x0020)  /* Load Range Control overwrite for AM, LPM0 and LPM1 Bit: 1 */
#define PMMAMRNG2           (0x0040)  /* Load Range Control overwrite for AM, LPM0 and LPM1 Bit: 2 */
#define PMMAMRNG3           (0x0080)  /* Load Range Control overwrite for AM, LPM0 and LPM1 Bit: 3 */
#define PMMCTL1KEY          (0xCC00)  /* PMM PMMCTL1 Register Write Password */


/* PMMIFG Control Bits */
#define PMMBORIFG           (0x0100)  /* PMM Software BOR interrupt flag */
#define PMMRSTIFG           (0x0200)  /* PMM RESET pin interrupt flag */
#define PMMPORIFG           (0x0400)  /* PMM Software POR interrupt flag */
#define SVSHIFG             (0x2000)  /* SVS low side interrupt flag */
#define PMMLPM5IFG          (0x8000)  /* LPM5 indication Flag */

/* PMMIFG Control Bits */
#define PMMBORIFG_H         (0x0001)  /* PMM Software BOR interrupt flag */
#define PMMRSTIFG_H         (0x0002)  /* PMM RESET pin interrupt flag */
#define PMMPORIFG_H         (0x0004)  /* PMM Software POR interrupt flag */
#define SVSHIFG_H           (0x0020)  /* SVS low side interrupt flag */
#define PMMLPM5IFG_H        (0x0080)  /* LPM5 indication Flag */


/* PM5CTL0 Power Mode 5 Control Bits */
#define LOCKLPM5            (0x0001)  /* Lock I/O pin configuration upon entry/exit to/from LPM5 */

/* PM5CTL0 Power Mode 5 Control Bits */
#define LOCKLPM5_L          (0x0001)  /* Lock I/O pin configuration upon entry/exit to/from LPM5 */



/************************************************************
* DIGITAL I/O Port1/2 Pull up / Pull down Resistors
************************************************************/
#define __MSP430_HAS_PORT1_R__        /* Definition to show that Module is available */
#define __MSP430_BASEADDRESS_PORT1_R__ 0x0200
#define P1_BASE __MSP430_BASEADDRESS_PORT1_R__
#define __MSP430_HAS_PORT2_R__        /* Definition to show that Module is available */
#define __MSP430_BASEADDRESS_PORT2_R__ 0x0200
#define P2_BASE __MSP430_BASEADDRESS_PORT2_R__
#define __MSP430_HAS_PORTA_R__        /* Definition to show that Module is available */
#define __MSP430_BASEADDRESS_PORTA_R__ 0x0200
#define PA_BASE __MSP430_BASEADDRESS_PORTA_R__
#define __MSP430_HAS_P1SEL0__         /* Define for DriverLib */
#define __MSP430_HAS_P2SEL0__         /* Define for DriverLib */
#define __MSP430_HAS_PASEL0__         /* Define for DriverLib */
#define __MSP430_HAS_P1SEL1__         /* Define for DriverLib */
#define __MSP430_HAS_P2SEL1__         /* Define for DriverLib */
#define __MSP430_HAS_PASEL1__         /* Define for DriverLib */

#define PAIN_                 0x0200    /* Port A Input */
const_sfrb(PAIN_L , PAIN_);
const_sfrb(PAIN_H , PAIN_+1);
const_sfrw(PAIN, PAIN_);
#define PAOUT_                0x0202    /* Port A Output */
sfrb(PAOUT_L , PAOUT_);
sfrb(PAOUT_H , PAOUT_+1);
sfrw(PAOUT, PAOUT_);
#define PADIR_                0x0204    /* Port A Direction */
sfrb(PADIR_L , PADIR_);
sfrb(PADIR_H , PADIR_+1);
sfrw(PADIR, PADIR_);
#define PAREN_                0x0206    /* Port A Resistor Enable */
sfrb(PAREN_L , PAREN_);
sfrb(PAREN_H , PAREN_+1);
sfrw(PAREN, PAREN_);
#define PASEL0_               0x020A    /* Port A Selection 0 */
sfrb(PASEL0_L , PASEL0_);
sfrb(PASEL0_H , PASEL0_+1);
sfrw(PASEL0, PASEL0_);
#define PASEL1_               0x020C    /* Port A Selection 1 */
sfrb(PASEL1_L , PASEL1_);
sfrb(PASEL1_H , PASEL1_+1);
sfrw(PASEL1, PASEL1_);
#define PASELC_               0x0216    /* Port A Complement Selection */
sfrb(PASELC_L , PASELC_);
sfrb(PASELC_H , PASELC_+1);
sfrw(PASELC, PASELC_);
#define PAIES_                0x0218    /* Port A Interrupt Edge Select */
sfrb(PAIES_L , PAIES_);
sfrb(PAIES_H , PAIES_+1);
sfrw(PAIES, PAIES_);
#define PAIE_                 0x021A    /* Port A Interrupt Enable */
sfrb(PAIE_L , PAIE_);
sfrb(PAIE_H , PAIE_+1);
sfrw(PAIE, PAIE_);
#define PAIFG_                0x021C    /* Port A Interrupt Flag */
sfrb(PAIFG_L , PAIFG_);
sfrb(PAIFG_H , PAIFG_+1);
sfrw(PAIFG, PAIFG_);























#define P1IV_                 0x020E    /* Port 1 Interrupt Vector Word */
sfrw(P1IV, P1IV_);
#define P2IV_                 0x021E    /* Port 2 Interrupt Vector Word */
sfrw(P2IV, P2IV_);
#define P1IN                (PAIN_L)  /* Port 1 Input */
#define P1OUT               (PAOUT_L) /* Port 1 Output */
#define P1DIR               (PADIR_L) /* Port 1 Direction */
#define P1REN               (PAREN_L) /* Port 1 Resistor Enable */
#define P1SEL0              (PASEL0_L) /* Port 1 Selection 0 */
#define P1SEL1              (PASEL1_L) /* Port 1 Selection 1 */
#define P1SELC              (PASELC_L) /* Port 1 Complement Selection */
#define P1IES               (PAIES_L) /* Port 1 Interrupt Edge Select */
#define P1IE                (PAIE_L)  /* Port 1 Interrupt Enable */
#define P1IFG               (PAIFG_L) /* Port 1 Interrupt Flag */

//Definitions for P1IV
#define P1IV_NONE            (0x0000)    /* No Interrupt pending */
#define P1IV_P1IFG0          (0x0002)    /* P1IV P1IFG.0 */
#define P1IV_P1IFG1          (0x0004)    /* P1IV P1IFG.1 */
#define P1IV_P1IFG2          (0x0006)    /* P1IV P1IFG.2 */
#define P1IV_P1IFG3          (0x0008)    /* P1IV P1IFG.3 */
#define P1IV_P1IFG4          (0x000A)    /* P1IV P1IFG.4 */
#define P1IV_P1IFG5          (0x000C)    /* P1IV P1IFG.5 */
#define P1IV_P1IFG6          (0x000E)    /* P1IV P1IFG.6 */
#define P1IV_P1IFG7          (0x0010)    /* P1IV P1IFG.7 */


#define P2IN                (PAIN_H)  /* Port 2 Input */
#define P2OUT               (PAOUT_H) /* Port 2 Output */
#define P2DIR               (PADIR_H) /* Port 2 Direction */
#define P2REN               (PAREN_H) /* Port 2 Resistor Enable */
#define P2SEL0              (PASEL0_H) /* Port 2 Selection 0 */
#define P2SEL1              (PASEL1_H) /* Port 2 Selection 1 */
#define P2SELC              (PASELC_H) /* Port 2 Complement Selection */
#define P2IES               (PAIES_H) /* Port 2 Interrupt Edge Select */
#define P2IE                (PAIE_H)  /* Port 2 Interrupt Enable */
#define P2IFG               (PAIFG_H) /* Port 2 Interrupt Flag */

//Definitions for P2IV
#define P2IV_NONE            (0x0000)    /* No Interrupt pending */
#define P2IV_P2IFG0          (0x0002)    /* P2IV P2IFG.0 */
#define P2IV_P2IFG1          (0x0004)    /* P2IV P2IFG.1 */
#define P2IV_P2IFG2          (0x0006)    /* P2IV P2IFG.2 */
#define P2IV_P2IFG3          (0x0008)    /* P2IV P2IFG.3 */
#define P2IV_P2IFG4          (0x000A)    /* P2IV P2IFG.4 */
#define P2IV_P2IFG5          (0x000C)    /* P2IV P2IFG.5 */
#define P2IV_P2IFG6          (0x000E)    /* P2IV P2IFG.6 */
#define P2IV_P2IFG7          (0x0010)    /* P2IV P2IFG.7 */



/************************************************************
* DIGITAL I/O Port3/4 Pull up / Pull down Resistors
************************************************************/
#define __MSP430_HAS_PORT3_R__        /* Definition to show that Module is available */
#define __MSP430_BASEADDRESS_PORT3_R__ 0x0220
#define P3_BASE __MSP430_BASEADDRESS_PORT3_R__
#define __MSP430_HAS_PORT4_R__        /* Definition to show that Module is available */
#define __MSP430_BASEADDRESS_PORT4_R__ 0x0220
#define P4_BASE __MSP430_BASEADDRESS_PORT4_R__
#define __MSP430_HAS_PORTB_R__        /* Definition to show that Module is available */
#define __MSP430_BASEADDRESS_PORTB_R__ 0x0220
#define PB_BASE __MSP430_BASEADDRESS_PORTB_R__
#define __MSP430_HAS_P3SEL0__         /* Define for DriverLib */
#define __MSP430_HAS_P4SEL0__         /* Define for DriverLib */
#define __MSP430_HAS_PBSEL0__         /* Define for DriverLib */
#define __MSP430_HAS_P3SEL1__         /* Define for DriverLib */
#define __MSP430_HAS_P4SEL1__         /* Define for DriverLib */
#define __MSP430_HAS_PBSEL1__         /* Define for DriverLib */

#define PBIN_                 0x0220    /* Port B Input */
const_sfrb(PBIN_L , PBIN_);
const_sfrb(PBIN_H , PBIN_+1);
const_sfrw(PBIN, PBIN_);
#define PBOUT_                0x0222    /* Port B Output */
sfrb(PBOUT_L , PBOUT_);
sfrb(PBOUT_H , PBOUT_+1);
sfrw(PBOUT, PBOUT_);
#define PBDIR_                0x0224    /* Port B Direction */
sfrb(PBDIR_L , PBDIR_);
sfrb(PBDIR_H , PBDIR_+1);
sfrw(PBDIR, PBDIR_);
#define PBREN_                0x0226    /* Port B Resistor Enable */
sfrb(PBREN_L , PBREN_);
sfrb(PBREN_H , PBREN_+1);
sfrw(PBREN, PBREN_);
#define PBSEL0_               0x022A    /* Port B Selection 0 */
sfrb(PBSEL0_L , PBSEL0_);
sfrb(PBSEL0_H , PBSEL0_+1);
sfrw(PBSEL0, PBSEL0_);
#define PBSEL1_               0x022C    /* Port B Selection 1 */
sfrb(PBSEL1_L , PBSEL1_);
sfrb(PBSEL1_H , PBSEL1_+1);
sfrw(PBSEL1, PBSEL1_);
#define PBSELC_               0x0236    /* Port B Complement Selection */
sfrb(PBSELC_L , PBSELC_);
sfrb(PBSELC_H , PBSELC_+1);
sfrw(PBSELC, PBSELC_);
#define PBIES_                0x0238    /* Port B Interrupt Edge Select */
sfrb(PBIES_L , PBIES_);
sfrb(PBIES_H , PBIES_+1);
sfrw(PBIES, PBIES_);
#define PBIE_                 0x023A    /* Port B Interrupt Enable */
sfrb(PBIE_L , PBIE_);
sfrb(PBIE_H , PBIE_+1);
sfrw(PBIE, PBIE_);
#define PBIFG_                0x023C    /* Port B Interrupt Flag */
sfrb(PBIFG_L , PBIFG_);
sfrb(PBIFG_H , PBIFG_+1);
sfrw(PBIFG, PBIFG_);























#define P3IV_                 0x022E    /* Port 3 Interrupt Vector Word */
sfrw(P3IV, P3IV_);
#define P4IV_                 0x023E    /* Port 4 Interrupt Vector Word */
sfrw(P4IV, P4IV_);
#define P3IN                (PBIN_L)  /* Port 3 Input */
#define P3OUT               (PBOUT_L) /* Port 3 Output */
#define P3DIR               (PBDIR_L) /* Port 3 Direction */
#define P3REN               (PBREN_L) /* Port 3 Resistor Enable */
#define P3SEL0              (PBSEL0_L) /* Port 3 Selection 0 */
#define P3SEL1              (PBSEL1_L) /* Port 3 Selection 1 */
#define P3SELC              (PBSELC_L) /* Port 3 Complement Selection */
#define P3IES               (PBIES_L) /* Port 3 Interrupt Edge Select */
#define P3IE                (PBIE_L)  /* Port 3 Interrupt Enable */
#define P3IFG               (PBIFG_L) /* Port 3 Interrupt Flag */

//Definitions for P3IV
#define P3IV_NONE            (0x0000)    /* No Interrupt pending */
#define P3IV_P3IFG0          (0x0002)    /* P3IV P3IFG.0 */
#define P3IV_P3IFG1          (0x0004)    /* P3IV P3IFG.1 */
#define P3IV_P3IFG2          (0x0006)    /* P3IV P3IFG.2 */
#define P3IV_P3IFG3          (0x0008)    /* P3IV P3IFG.3 */
#define P3IV_P3IFG4          (0x000A)    /* P3IV P3IFG.4 */
#define P3IV_P3IFG5          (0x000C)    /* P3IV P3IFG.5 */
#define P3IV_P3IFG6          (0x000E)    /* P3IV P3IFG.6 */
#define P3IV_P3IFG7          (0x0010)    /* P3IV P3IFG.7 */


#define P4IN                (PBIN_H)  /* Port 4 Input */
#define P4OUT               (PBOUT_H) /* Port 4 Output */
#define P4DIR               (PBDIR_H) /* Port 4 Direction */
#define P4REN               (PBREN_H) /* Port 4 Resistor Enable */
#define P4SEL0              (PBSEL0_H) /* Port 4 Selection 0 */
#define P4SEL1              (PBSEL1_H) /* Port 4 Selection 1 */
#define P4SELC              (PBSELC_H) /* Port 4 Complement Selection */
#define P4IES               (PBIES_H) /* Port 4 Interrupt Edge Select */
#define P4IE                (PBIE_H)  /* Port 4 Interrupt Enable */
#define P4IFG               (PBIFG_H) /* Port 4 Interrupt Flag */

//Definitions for P4IV
#define P4IV_NONE            (0x0000)    /* No Interrupt pending */
#define P4IV_P4IFG0          (0x0002)    /* P4IV P4IFG.0 */
#define P4IV_P4IFG1          (0x0004)    /* P4IV P4IFG.1 */
#define P4IV_P4IFG2          (0x0006)    /* P4IV P4IFG.2 */
#define P4IV_P4IFG3          (0x0008)    /* P4IV P4IFG.3 */
#define P4IV_P4IFG4          (0x000A)    /* P4IV P4IFG.4 */
#define P4IV_P4IFG5          (0x000C)    /* P4IV P4IFG.5 */
#define P4IV_P4IFG6          (0x000E)    /* P4IV P4IFG.6 */
#define P4IV_P4IFG7          (0x0010)    /* P4IV P4IFG.7 */



/************************************************************
* DIGITAL I/O PortJ Pull up / Pull down Resistors
************************************************************/
#define __MSP430_HAS_PORTJ_R__        /* Definition to show that Module is available */
#define __MSP430_BASEADDRESS_PORTJ_R__ 0x0320
#define PJ_BASE __MSP430_BASEADDRESS_PORTJ_R__
#define __MSP430_HAS_PJSEL0__          /* Define for DriverLib */
#define __MSP430_HAS_PJSEL1__          /* Define for DriverLib */

#define PJIN_                 0x0320    /* Port J Input */
const_sfrb(PJIN_L , PJIN_);
const_sfrb(PJIN_H , PJIN_+1);
const_sfrw(PJIN, PJIN_);
#define PJOUT_                0x0322    /* Port J Output */
sfrb(PJOUT_L , PJOUT_);
sfrb(PJOUT_H , PJOUT_+1);
sfrw(PJOUT, PJOUT_);
#define PJDIR_                0x0324    /* Port J Direction */
sfrb(PJDIR_L , PJDIR_);
sfrb(PJDIR_H , PJDIR_+1);
sfrw(PJDIR, PJDIR_);
#define PJREN_                0x0326    /* Port J Resistor Enable */
sfrb(PJREN_L , PJREN_);
sfrb(PJREN_H , PJREN_+1);
sfrw(PJREN, PJREN_);
#define PJSEL0_               0x032A    /* Port J Selection 0 */
sfrb(PJSEL0_L , PJSEL0_);
sfrb(PJSEL0_H , PJSEL0_+1);
sfrw(PJSEL0, PJSEL0_);
#define PJSEL1_               0x032C    /* Port J Selection 1 */
sfrb(PJSEL1_L , PJSEL1_);
sfrb(PJSEL1_H , PJSEL1_+1);
sfrw(PJSEL1, PJSEL1_);
#define PJSELC_               0x0336    /* Port J Complement Selection */
sfrb(PJSELC_L , PJSELC_);
sfrb(PJSELC_H , PJSELC_+1);
sfrw(PJSELC, PJSELC_);













/************************************************************
* Shared Reference
************************************************************/
#define __MSP430_HAS_REF_A__           /* Definition to show that Module is available */
#define __MSP430_BASEADDRESS_REF_A__ 0x01B0
#define REF_A_BASE __MSP430_BASEADDRESS_REF_A__

#define REFCTL0_              0x01B0    /* REF Shared Reference control register 0 */
sfrb(REFCTL0_L , REFCTL0_);
sfrb(REFCTL0_H , REFCTL0_+1);
sfrw(REFCTL0, REFCTL0_);

/* REFCTL0 Control Bits */
#define REFON               (0x0001)  /* REF Reference On */
#define REFOUT              (0x0002)  /* REF Reference output Buffer On */
//#define RESERVED            (0x0004)  /* Reserved */
#define REFTCOFF            (0x0008)  /* REF Temp.Sensor off */
#define REFVSEL0            (0x0010)  /* REF Reference Voltage Level Select Bit:0 */
#define REFVSEL1            (0x0020)  /* REF Reference Voltage Level Select Bit:1 */
#define REFGENOT            (0x0040)  /* REF Reference generator one-time trigger */
#define REFBGOT             (0x0080)  /* REF Bandgap and bandgap buffer one-time trigger */
#define REFGENACT           (0x0100)  /* REF Reference generator active */
#define REFBGACT            (0x0200)  /* REF Reference bandgap active */
#define REFGENBUSY          (0x0400)  /* REF Reference generator busy */
#define BGMODE              (0x0800)  /* REF Bandgap mode */
#define REFGENRDY           (0x1000)  /* REF Reference generator ready */
#define REFBGRDY            (0x2000)  /* REF Reference bandgap ready */
//#define RESERVED            (0x4000)  /* Reserved */
//#define RESERVED            (0x8000)  /* Reserved */

/* REFCTL0 Control Bits */
#define REFON_L             (0x0001)  /* REF Reference On */
#define REFOUT_L            (0x0002)  /* REF Reference output Buffer On */
//#define RESERVED            (0x0004)  /* Reserved */
#define REFTCOFF_L          (0x0008)  /* REF Temp.Sensor off */
#define REFVSEL0_L          (0x0010)  /* REF Reference Voltage Level Select Bit:0 */
#define REFVSEL1_L          (0x0020)  /* REF Reference Voltage Level Select Bit:1 */
#define REFGENOT_L          (0x0040)  /* REF Reference generator one-time trigger */
#define REFBGOT_L           (0x0080)  /* REF Bandgap and bandgap buffer one-time trigger */
//#define RESERVED            (0x4000)  /* Reserved */
//#define RESERVED            (0x8000)  /* Reserved */

/* REFCTL0 Control Bits */
//#define RESERVED            (0x0004)  /* Reserved */
#define REFGENACT_H         (0x0001)  /* REF Reference generator active */
#define REFBGACT_H          (0x0002)  /* REF Reference bandgap active */
#define REFGENBUSY_H        (0x0004)  /* REF Reference generator busy */
#define BGMODE_H            (0x0008)  /* REF Bandgap mode */
#define REFGENRDY_H         (0x0010)  /* REF Reference generator ready */
#define REFBGRDY_H          (0x0020)  /* REF Reference bandgap ready */
//#define RESERVED            (0x4000)  /* Reserved */
//#define RESERVED            (0x8000)  /* Reserved */

#define REFVSEL_0           (0x0000)  /* REF Reference Voltage Level Select 1.2V */
#define REFVSEL_1           (0x0010)  /* REF Reference Voltage Level Select 2.0V */
#define REFVSEL_2           (0x0020)  /* REF Reference Voltage Level Select 2.5V */
#define REFVSEL_3           (0x0030)  /* REF Reference Voltage Level Select 2.5V */

/************************************************************
* Real Time Clock
************************************************************/
#define __MSP430_HAS_RTC_B__          /* Definition to show that Module is available */
#define __MSP430_BASEADDRESS_RTC_B__ 0x04A0
#define RTC_B_BASE __MSP430_BASEADDRESS_RTC_B__

#define RTCCTL01_             0x04A0    /* Real Timer Control 0/1 */
sfrb(RTCCTL01_L , RTCCTL01_);
sfrb(RTCCTL01_H , RTCCTL01_+1);
sfrw(RTCCTL01, RTCCTL01_);
#define RTCCTL23_             0x04A2    /* Real Timer Control 2/3 */
sfrb(RTCCTL23_L , RTCCTL23_);
sfrb(RTCCTL23_H , RTCCTL23_+1);
sfrw(RTCCTL23, RTCCTL23_);
#define RTCPS0CTL_            0x04A8    /* Real Timer Prescale Timer 0 Control */
sfrb(RTCPS0CTL_L , RTCPS0CTL_);
sfrb(RTCPS0CTL_H , RTCPS0CTL_+1);
sfrw(RTCPS0CTL, RTCPS0CTL_);
#define RTCPS1CTL_            0x04AA    /* Real Timer Prescale Timer 1 Control */
sfrb(RTCPS1CTL_L , RTCPS1CTL_);
sfrb(RTCPS1CTL_H , RTCPS1CTL_+1);
sfrw(RTCPS1CTL, RTCPS1CTL_);
#define RTCPS_                0x04AC    /* Real Timer Prescale Timer Control */
sfrb(RTCPS_L , RTCPS_);
sfrb(RTCPS_H , RTCPS_+1);
sfrw(RTCPS, RTCPS_);
#define RTCIV_                0x04AE    /* Real Time Clock Interrupt Vector */
sfrw(RTCIV, RTCIV_);
#define RTCTIM0_              0x04B0    /* Real Time Clock Time 0 */
sfrb(RTCTIM0_L , RTCTIM0_);
sfrb(RTCTIM0_H , RTCTIM0_+1);
sfrw(RTCTIM0, RTCTIM0_);
#define RTCTIM1_              0x04B2    /* Real Time Clock Time 1 */
sfrb(RTCTIM1_L , RTCTIM1_);
sfrb(RTCTIM1_H , RTCTIM1_+1);
sfrw(RTCTIM1, RTCTIM1_);
#define RTCDATE_              0x04B4    /* Real Time Clock Date */
sfrb(RTCDATE_L , RTCDATE_);
sfrb(RTCDATE_H , RTCDATE_+1);
sfrw(RTCDATE, RTCDATE_);
#define RTCYEAR_              0x04B6    /* Real Time Clock Year */
sfrb(RTCYEAR_L , RTCYEAR_);
sfrb(RTCYEAR_H , RTCYEAR_+1);
sfrw(RTCYEAR, RTCYEAR_);
#define RTCAMINHR_            0x04B8    /* Real Time Clock Alarm Min/Hour */
sfrb(RTCAMINHR_L , RTCAMINHR_);
sfrb(RTCAMINHR_H , RTCAMINHR_+1);
sfrw(RTCAMINHR, RTCAMINHR_);
#define RTCADOWDAY_           0x04BA    /* Real Time Clock Alarm day of week/day */
sfrb(RTCADOWDAY_L , RTCADOWDAY_);
sfrb(RTCADOWDAY_H , RTCADOWDAY_+1);
sfrw(RTCADOWDAY, RTCADOWDAY_);
#define BIN2BCD_              0x04BC    /* Real Time Binary-to-BCD conversion register */
sfrw(BIN2BCD, BIN2BCD_);
#define BCD2BIN_              0x04BE    /* Real Time BCD-to-binary conversion register */
sfrw(BCD2BIN, BCD2BIN_);

#define RTCCTL0             RTCCTL01_L  /* Real Time Clock Control 0 */
#define RTCCTL1             RTCCTL01_H  /* Real Time Clock Control 1 */
#define RTCCTL2             RTCCTL23_L  /* Real Time Clock Control 2 */
#define RTCCTL3             RTCCTL23_H  /* Real Time Clock Control 3 */
#define RTCNT12             RTCTIM0
#define RTCNT34             RTCTIM1
#define RTCNT1              RTCTIM0_L
#define RTCNT2              RTCTIM0_H
#define RTCNT3              RTCTIM1_L
#define RTCNT4              RTCTIM1_H
#define RTCSEC              RTCTIM0_L
#define RTCMIN              RTCTIM0_H
#define RTCHOUR             RTCTIM1_L
#define RTCDOW              RTCTIM1_H
#define RTCDAY              RTCDATE_L
#define RTCMON              RTCDATE_H
#define RTCYEARL            RTCYEAR_L
#define RTCYEARH            RTCYEAR_H
#define RT0PS               RTCPS_L
#define RT1PS               RTCPS_H
#define RTCAMIN             RTCAMINHR_L  /* Real Time Clock Alarm Min */
#define RTCAHOUR            RTCAMINHR_H  /* Real Time Clock Alarm Hour */
#define RTCADOW             RTCADOWDAY_L /* Real Time Clock Alarm day of week */
#define RTCADAY             RTCADOWDAY_H /* Real Time Clock Alarm day */

/* RTCCTL01 Control Bits */
#define RTCBCD              (0x8000)     /* RTC BCD  0:Binary / 1:BCD */
#define RTCHOLD             (0x4000)     /* RTC Hold */
//#define RESERVED            (0x2000)     /* RESERVED */
#define RTCRDY              (0x1000)     /* RTC Ready */
//#define RESERVED            (0x0800)     /* RESERVED */
//#define RESERVED            (0x0400)     /* RESERVED */
#define RTCTEV1             (0x0200)     /* RTC Time Event 1 */
#define RTCTEV0             (0x0100)     /* RTC Time Event 0 */
#define RTCOFIE             (0x0080)     /* RTC 32kHz cyrstal oscillator fault interrupt enable */
#define RTCTEVIE            (0x0040)     /* RTC Time Event Interrupt Enable Flag */
#define RTCAIE              (0x0020)     /* RTC Alarm Interrupt Enable Flag */
#define RTCRDYIE            (0x0010)     /* RTC Ready Interrupt Enable Flag */
#define RTCOFIFG            (0x0008)     /* RTC 32kHz cyrstal oscillator fault interrupt flag */
#define RTCTEVIFG           (0x0004)     /* RTC Time Event Interrupt Flag */
#define RTCAIFG             (0x0002)     /* RTC Alarm Interrupt Flag */
#define RTCRDYIFG           (0x0001)     /* RTC Ready Interrupt Flag */

/* RTCCTL01 Control Bits */
//#define RESERVED            (0x2000)     /* RESERVED */
//#define RESERVED            (0x0800)     /* RESERVED */
//#define RESERVED            (0x0400)     /* RESERVED */
#define RTCOFIE_L           (0x0080)     /* RTC 32kHz cyrstal oscillator fault interrupt enable */
#define RTCTEVIE_L          (0x0040)     /* RTC Time Event Interrupt Enable Flag */
#define RTCAIE_L            (0x0020)     /* RTC Alarm Interrupt Enable Flag */
#define RTCRDYIE_L          (0x0010)     /* RTC Ready Interrupt Enable Flag */
#define RTCOFIFG_L          (0x0008)     /* RTC 32kHz cyrstal oscillator fault interrupt flag */
#define RTCTEVIFG_L         (0x0004)     /* RTC Time Event Interrupt Flag */
#define RTCAIFG_L           (0x0002)     /* RTC Alarm Interrupt Flag */
#define RTCRDYIFG_L         (0x0001)     /* RTC Ready Interrupt Flag */

/* RTCCTL01 Control Bits */
#define RTCBCD_H            (0x0080)     /* RTC BCD  0:Binary / 1:BCD */
#define RTCHOLD_H           (0x0040)     /* RTC Hold */
//#define RESERVED            (0x2000)     /* RESERVED */
#define RTCRDY_H            (0x0010)     /* RTC Ready */
//#define RESERVED            (0x0800)     /* RESERVED */
//#define RESERVED            (0x0400)     /* RESERVED */
#define RTCTEV1_H           (0x0002)     /* RTC Time Event 1 */
#define RTCTEV0_H           (0x0001)     /* RTC Time Event 0 */

#define RTCTEV_0            (0x0000)     /* RTC Time Event: 0 (Min. changed) */
#define RTCTEV_1            (0x0100)     /* RTC Time Event: 1 (Hour changed) */
#define RTCTEV_2            (0x0200)     /* RTC Time Event: 2 (12:00 changed) */
#define RTCTEV_3            (0x0300)     /* RTC Time Event: 3 (00:00 changed) */
#define RTCTEV__MIN         (0x0000)     /* RTC Time Event: 0 (Min. changed) */
#define RTCTEV__HOUR        (0x0100)     /* RTC Time Event: 1 (Hour changed) */
#define RTCTEV__0000        (0x0200)     /* RTC Time Event: 2 (00:00 changed) */
#define RTCTEV__1200        (0x0300)     /* RTC Time Event: 3 (12:00 changed) */

/* RTCCTL23 Control Bits */
#define RTCCALF1            (0x0200)     /* RTC Calibration Frequency Bit 1 */
#define RTCCALF0            (0x0100)     /* RTC Calibration Frequency Bit 0 */
#define RTCCALS             (0x0080)     /* RTC Calibration Sign */
//#define Reserved          (0x0040)
#define RTCCAL5             (0x0020)     /* RTC Calibration Bit 5 */
#define RTCCAL4             (0x0010)     /* RTC Calibration Bit 4 */
#define RTCCAL3             (0x0008)     /* RTC Calibration Bit 3 */
#define RTCCAL2             (0x0004)     /* RTC Calibration Bit 2 */
#define RTCCAL1             (0x0002)     /* RTC Calibration Bit 1 */
#define RTCCAL0             (0x0001)     /* RTC Calibration Bit 0 */

/* RTCCTL23 Control Bits */
#define RTCCALS_L           (0x0080)     /* RTC Calibration Sign */
//#define Reserved          (0x0040)
#define RTCCAL5_L           (0x0020)     /* RTC Calibration Bit 5 */
#define RTCCAL4_L           (0x0010)     /* RTC Calibration Bit 4 */
#define RTCCAL3_L           (0x0008)     /* RTC Calibration Bit 3 */
#define RTCCAL2_L           (0x0004)     /* RTC Calibration Bit 2 */
#define RTCCAL1_L           (0x0002)     /* RTC Calibration Bit 1 */
#define RTCCAL0_L           (0x0001)     /* RTC Calibration Bit 0 */

/* RTCCTL23 Control Bits */
#define RTCCALF1_H          (0x0002)     /* RTC Calibration Frequency Bit 1 */
#define RTCCALF0_H          (0x0001)     /* RTC Calibration Frequency Bit 0 */
//#define Reserved          (0x0040)

#define RTCCALF_0           (0x0000)     /* RTC Calibration Frequency: No Output */
#define RTCCALF_1           (0x0100)     /* RTC Calibration Frequency: 512 Hz */
#define RTCCALF_2           (0x0200)     /* RTC Calibration Frequency: 256 Hz */
#define RTCCALF_3           (0x0300)     /* RTC Calibration Frequency: 1 Hz */


#define RTCAE               (0x80)     /* Real Time Clock Alarm enable */




/* RTCPS0CTL Control Bits */
//#define Reserved          (0x0080)
//#define Reserved          (0x0040)
//#define Reserved          (0x0020)
#define RT0IP2              (0x0010)     /* RTC Prescale Timer 0 Interrupt Interval Bit: 2 */
#define RT0IP1              (0x0008)     /* RTC Prescale Timer 0 Interrupt Interval Bit: 1 */
#define RT0IP0              (0x0004)     /* RTC Prescale Timer 0 Interrupt Interval Bit: 0 */
#define RT0PSIE             (0x0002)     /* RTC Prescale Timer 0 Interrupt Enable Flag */
#define RT0PSIFG            (0x0001)     /* RTC Prescale Timer 0 Interrupt Flag */

/* RTCPS0CTL Control Bits */
//#define Reserved          (0x0080)
//#define Reserved          (0x0040)
//#define Reserved          (0x0020)
#define RT0IP2_L            (0x0010)     /* RTC Prescale Timer 0 Interrupt Interval Bit: 2 */
#define RT0IP1_L            (0x0008)     /* RTC Prescale Timer 0 Interrupt Interval Bit: 1 */
#define RT0IP0_L            (0x0004)     /* RTC Prescale Timer 0 Interrupt Interval Bit: 0 */
#define RT0PSIE_L           (0x0002)     /* RTC Prescale Timer 0 Interrupt Enable Flag */
#define RT0PSIFG_L          (0x0001)     /* RTC Prescale Timer 0 Interrupt Flag */


#define RT0IP_0             (0x0000)     /* RTC Prescale Timer 0 Interrupt Interval /2 */
#define RT0IP_1             (0x0004)     /* RTC Prescale Timer 0 Interrupt Interval /4 */
#define RT0IP_2             (0x0008)     /* RTC Prescale Timer 0 Interrupt Interval /8 */
#define RT0IP_3             (0x000C)     /* RTC Prescale Timer 0 Interrupt Interval /16 */
#define RT0IP_4             (0x0010)     /* RTC Prescale Timer 0 Interrupt Interval /32 */
#define RT0IP_5             (0x0014)     /* RTC Prescale Timer 0 Interrupt Interval /64 */
#define RT0IP_6             (0x0018)     /* RTC Prescale Timer 0 Interrupt Interval /128 */
#define RT0IP_7             (0x001C)     /* RTC Prescale Timer 0 Interrupt Interval /256 */

#define RT0IP__2            (0x0000)     /* RTC Prescale Timer 0 Interrupt Interval /2 */
#define RT0IP__4            (0x0004)     /* RTC Prescale Timer 0 Interrupt Interval /4 */
#define RT0IP__8            (0x0008)     /* RTC Prescale Timer 0 Interrupt Interval /8 */
#define RT0IP__16           (0x000C)     /* RTC Prescale Timer 0 Interrupt Interval /16 */
#define RT0IP__32           (0x0010)     /* RTC Prescale Timer 0 Interrupt Interval /32 */
#define RT0IP__64           (0x0014)     /* RTC Prescale Timer 0 Interrupt Interval /64 */
#define RT0IP__128          (0x0018)     /* RTC Prescale Timer 0 Interrupt Interval /128 */
#define RT0IP__256          (0x001C)     /* RTC Prescale Timer 0 Interrupt Interval /256 */


/* RTCPS1CTL Control Bits */
//#define Reserved          (0x0080)
//#define Reserved          (0x0040)
//#define Reserved          (0x0020)
#define RT1IP2              (0x0010)     /* RTC Prescale Timer 1 Interrupt Interval Bit: 2 */
#define RT1IP1              (0x0008)     /* RTC Prescale Timer 1 Interrupt Interval Bit: 1 */
#define RT1IP0              (0x0004)     /* RTC Prescale Timer 1 Interrupt Interval Bit: 0 */
#define RT1PSIE             (0x0002)     /* RTC Prescale Timer 1 Interrupt Enable Flag */
#define RT1PSIFG            (0x0001)     /* RTC Prescale Timer 1 Interrupt Flag */

/* RTCPS1CTL Control Bits */
//#define Reserved          (0x0080)
//#define Reserved          (0x0040)
//#define Reserved          (0x0020)
#define RT1IP2_L            (0x0010)     /* RTC Prescale Timer 1 Interrupt Interval Bit: 2 */
#define RT1IP1_L            (0x0008)     /* RTC Prescale Timer 1 Interrupt Interval Bit: 1 */
#define RT1IP0_L            (0x0004)     /* RTC Prescale Timer 1 Interrupt Interval Bit: 0 */
#define RT1PSIE_L           (0x0002)     /* RTC Prescale Timer 1 Interrupt Enable Flag */
#define RT1PSIFG_L          (0x0001)     /* RTC Prescale Timer 1 Interrupt Flag */


#define RT1IP_0             (0x0000)     /* RTC Prescale Timer 1 Interrupt Interval /2 */
#define RT1IP_1             (0x0004)     /* RTC Prescale Timer 1 Interrupt Interval /4 */
#define RT1IP_2             (0x0008)     /* RTC Prescale Timer 1 Interrupt Interval /8 */
#define RT1IP_3             (0x000C)     /* RTC Prescale Timer 1 Interrupt Interval /16 */
#define RT1IP_4             (0x0010)     /* RTC Prescale Timer 1 Interrupt Interval /32 */
#define RT1IP_5             (0x0014)     /* RTC Prescale Timer 1 Interrupt Interval /64 */
#define RT1IP_6             (0x0018)     /* RTC Prescale Timer 1 Interrupt Interval /128 */
#define RT1IP_7             (0x001C)     /* RTC Prescale Timer 1 Interrupt Interval /256 */

#define RT1IP__2            (0x0000)     /* RTC Prescale Timer 1 Interrupt Interval /2 */
#define RT1IP__4            (0x0004)     /* RTC Prescale Timer 1 Interrupt Interval /4 */
#define RT1IP__8            (0x0008)     /* RTC Prescale Timer 1 Interrupt Interval /8 */
#define RT1IP__16           (0x000C)     /* RTC Prescale Timer 1 Interrupt Interval /16 */
#define RT1IP__32           (0x0010)     /* RTC Prescale Timer 1 Interrupt Interval /32 */
#define RT1IP__64           (0x0014)     /* RTC Prescale Timer 1 Interrupt Interval /64 */
#define RT1IP__128          (0x0018)     /* RTC Prescale Timer 1 Interrupt Interval /128 */
#define RT1IP__256          (0x001C)     /* RTC Prescale Timer 1 Interrupt Interval /256 */


/* RTC Definitions */
#define RTCIV_NONE           (0x0000)    /* No Interrupt pending */
#define RTCIV_RTCRDYIFG      (0x0002)    /* RTC ready: RTCRDYIFG */
#define RTCIV_RTCTEVIFG      (0x0004)    /* RTC interval timer: RTCTEVIFG */
#define RTCIV_RTCAIFG        (0x0006)    /* RTC user alarm: RTCAIFG */
#define RTCIV_RT0PSIFG       (0x0008)    /* RTC prescaler 0: RT0PSIFG */
#define RTCIV_RT1PSIFG       (0x000A)    /* RTC prescaler 1: RT1PSIFG */
#define RTCIV_RTCOFIFG       (0x000C)    /* RTC Oscillator fault */

/* Legacy Definitions */
#define RTC_NONE           (0x0000)      /* No Interrupt pending */
#define RTC_RTCRDYIFG      (0x0002)      /* RTC ready: RTCRDYIFG */
#define RTC_RTCTEVIFG      (0x0004)      /* RTC interval timer: RTCTEVIFG */
#define RTC_RTCAIFG        (0x0006)      /* RTC user alarm: RTCAIFG */
#define RTC_RT0PSIFG       (0x0008)      /* RTC prescaler 0: RT0PSIFG */
#define RTC_RT1PSIFG       (0x000A)      /* RTC prescaler 1: RT1PSIFG */
#define RTC_RTCOFIFG       (0x000C)      /* RTC Oscillator fault */

/************************************************************
* SFR - Special Function Register Module
************************************************************/
#define __MSP430_HAS_SFR__            /* Definition to show that Module is available */
#define __MSP430_BASEADDRESS_SFR__ 0x0100
#define SFR_BASE __MSP430_BASEADDRESS_SFR__

#define SFRIE1_               0x0100    /* Interrupt Enable 1 */
sfrb(SFRIE1_L , SFRIE1_);
sfrb(SFRIE1_H , SFRIE1_+1);
sfrw(SFRIE1, SFRIE1_);

/* SFRIE1 Control Bits */
#define WDTIE               (0x0001)  /* WDT Interrupt Enable */
#define OFIE                (0x0002)  /* Osc Fault Enable */
//#define Reserved          (0x0004)
#define VMAIE               (0x0008)  /* Vacant Memory Interrupt Enable */
#define NMIIE               (0x0010)  /* NMI Interrupt Enable */
#define JMBINIE             (0x0040)  /* JTAG Mail Box input Interrupt Enable */
#define JMBOUTIE            (0x0080)  /* JTAG Mail Box output Interrupt Enable */

#define WDTIE_L             (0x0001)  /* WDT Interrupt Enable */
#define OFIE_L              (0x0002)  /* Osc Fault Enable */
//#define Reserved          (0x0004)
#define VMAIE_L             (0x0008)  /* Vacant Memory Interrupt Enable */
#define NMIIE_L             (0x0010)  /* NMI Interrupt Enable */
#define JMBINIE_L           (0x0040)  /* JTAG Mail Box input Interrupt Enable */
#define JMBOUTIE_L          (0x0080)  /* JTAG Mail Box output Interrupt Enable */


#define SFRIFG1_              0x0102    /* Interrupt Flag 1 */
sfrb(SFRIFG1_L , SFRIFG1_);
sfrb(SFRIFG1_H , SFRIFG1_+1);
sfrw(SFRIFG1, SFRIFG1_);
/* SFRIFG1 Control Bits */
#define WDTIFG              (0x0001)  /* WDT Interrupt Flag */
#define OFIFG               (0x0002)  /* Osc Fault Flag */
//#define Reserved          (0x0004)
#define VMAIFG              (0x0008)  /* Vacant Memory Interrupt Flag */
#define NMIIFG              (0x0010)  /* NMI Interrupt Flag */
//#define Reserved          (0x0020)
#define JMBINIFG            (0x0040)  /* JTAG Mail Box input Interrupt Flag */
#define JMBOUTIFG           (0x0080)  /* JTAG Mail Box output Interrupt Flag */

#define WDTIFG_L            (0x0001)  /* WDT Interrupt Flag */
#define OFIFG_L             (0x0002)  /* Osc Fault Flag */
//#define Reserved          (0x0004)
#define VMAIFG_L            (0x0008)  /* Vacant Memory Interrupt Flag */
#define NMIIFG_L            (0x0010)  /* NMI Interrupt Flag */
//#define Reserved          (0x0020)
#define JMBINIFG_L          (0x0040)  /* JTAG Mail Box input Interrupt Flag */
#define JMBOUTIFG_L         (0x0080)  /* JTAG Mail Box output Interrupt Flag */


#define SFRRPCR_              0x0104    /* RESET Pin Control Register */
sfrb(SFRRPCR_L , SFRRPCR_);
sfrb(SFRRPCR_H , SFRRPCR_+1);
sfrw(SFRRPCR, SFRRPCR_);
/* SFRRPCR Control Bits */
#define SYSNMI              (0x0001)  /* NMI select */
#define SYSNMIIES           (0x0002)  /* NMI edge select */
#define SYSRSTUP            (0x0004)  /* RESET Pin pull down/up select */
#define SYSRSTRE            (0x0008)  /* RESET Pin Resistor enable */

#define SYSNMI_L            (0x0001)  /* NMI select */
#define SYSNMIIES_L         (0x0002)  /* NMI edge select */
#define SYSRSTUP_L          (0x0004)  /* RESET Pin pull down/up select */
#define SYSRSTRE_L          (0x0008)  /* RESET Pin Resistor enable */


/************************************************************
* SYS - System Module
************************************************************/
#define __MSP430_HAS_SYS__            /* Definition to show that Module is available */
#define __MSP430_BASEADDRESS_SYS__ 0x0180
#define SYS_BASE __MSP430_BASEADDRESS_SYS__

#define SYSCTL_               0x0180    /* System control */
sfrb(SYSCTL_L , SYSCTL_);
sfrb(SYSCTL_H , SYSCTL_+1);
sfrw(SYSCTL, SYSCTL_);
#define SYSBSLC_              0x0182    /* Boot strap configuration area */
sfrb(SYSBSLC_L , SYSBSLC_);
sfrb(SYSBSLC_H , SYSBSLC_+1);
sfrw(SYSBSLC, SYSBSLC_);
#define SYSJMBC_              0x0186    /* JTAG mailbox control */
sfrb(SYSJMBC_L , SYSJMBC_);
sfrb(SYSJMBC_H , SYSJMBC_+1);
sfrw(SYSJMBC, SYSJMBC_);
#define SYSJMBI0_             0x0188    /* JTAG mailbox input 0 */
sfrb(SYSJMBI0_L , SYSJMBI0_);
sfrb(SYSJMBI0_H , SYSJMBI0_+1);
sfrw(SYSJMBI0, SYSJMBI0_);
#define SYSJMBI1_             0x018A    /* JTAG mailbox input 1 */
sfrb(SYSJMBI1_L , SYSJMBI1_);
sfrb(SYSJMBI1_H , SYSJMBI1_+1);
sfrw(SYSJMBI1, SYSJMBI1_);
#define SYSJMBO0_             0x018C    /* JTAG mailbox output 0 */
sfrb(SYSJMBO0_L , SYSJMBO0_);
sfrb(SYSJMBO0_H , SYSJMBO0_+1);
sfrw(SYSJMBO0, SYSJMBO0_);
#define SYSJMBO1_             0x018E    /* JTAG mailbox output 1 */
sfrb(SYSJMBO1_L , SYSJMBO1_);
sfrb(SYSJMBO1_H , SYSJMBO1_+1);
sfrw(SYSJMBO1, SYSJMBO1_);

#define SYSBERRIV_            0x0198    /* Bus Error vector generator */
sfrb(SYSBERRIV_L , SYSBERRIV_);
sfrb(SYSBERRIV_H , SYSBERRIV_+1);
sfrw(SYSBERRIV, SYSBERRIV_);
#define SYSUNIV_              0x019A    /* User NMI vector generator */
sfrb(SYSUNIV_L , SYSUNIV_);
sfrb(SYSUNIV_H , SYSUNIV_+1);
sfrw(SYSUNIV, SYSUNIV_);
#define SYSSNIV_              0x019C    /* System NMI vector generator */
sfrb(SYSSNIV_L , SYSSNIV_);
sfrb(SYSSNIV_H , SYSSNIV_+1);
sfrw(SYSSNIV, SYSSNIV_);
#define SYSRSTIV_             0x019E    /* Reset vector generator */
sfrb(SYSRSTIV_L , SYSRSTIV_);
sfrb(SYSRSTIV_H , SYSRSTIV_+1);
sfrw(SYSRSTIV, SYSRSTIV_);

/* SYSCTL Control Bits */
#define SYSRIVECT           (0x0001)  /* SYS - RAM based interrupt vectors */
//#define RESERVED            (0x0002)  /* SYS - Reserved */
#define SYSPMMPE            (0x0004)  /* SYS - PMM access protect */
//#define RESERVED            (0x0008)  /* SYS - Reserved */
#define SYSBSLIND           (0x0010)  /* SYS - TCK/RST indication detected */
#define SYSJTAGPIN          (0x0020)  /* SYS - Dedicated JTAG pins enabled */
//#define RESERVED            (0x0040)  /* SYS - Reserved */
//#define RESERVED            (0x0080)  /* SYS - Reserved */
//#define RESERVED            (0x0100)  /* SYS - Reserved */
//#define RESERVED            (0x0200)  /* SYS - Reserved */
//#define RESERVED            (0x0400)  /* SYS - Reserved */
//#define RESERVED            (0x0800)  /* SYS - Reserved */
//#define RESERVED            (0x1000)  /* SYS - Reserved */
//#define RESERVED            (0x2000)  /* SYS - Reserved */
//#define RESERVED            (0x4000)  /* SYS - Reserved */
//#define RESERVED            (0x8000)  /* SYS - Reserved */

/* SYSCTL Control Bits */
#define SYSRIVECT_L         (0x0001)  /* SYS - RAM based interrupt vectors */
//#define RESERVED            (0x0002)  /* SYS - Reserved */
#define SYSPMMPE_L          (0x0004)  /* SYS - PMM access protect */
//#define RESERVED            (0x0008)  /* SYS - Reserved */
#define SYSBSLIND_L         (0x0010)  /* SYS - TCK/RST indication detected */
#define SYSJTAGPIN_L        (0x0020)  /* SYS - Dedicated JTAG pins enabled */
//#define RESERVED            (0x0040)  /* SYS - Reserved */
//#define RESERVED            (0x0080)  /* SYS - Reserved */
//#define RESERVED            (0x0100)  /* SYS - Reserved */
//#define RESERVED            (0x0200)  /* SYS - Reserved */
//#define RESERVED            (0x0400)  /* SYS - Reserved */
//#define RESERVED            (0x0800)  /* SYS - Reserved */
//#define RESERVED            (0x1000)  /* SYS - Reserved */
//#define RESERVED            (0x2000)  /* SYS - Reserved */
//#define RESERVED            (0x4000)  /* SYS - Reserved */
//#define RESERVED            (0x8000)  /* SYS - Reserved */


/* SYSBSLC Control Bits */
#define SYSBSLSIZE0         (0x0001)  /* SYS - BSL Protection Size 0 */
#define SYSBSLSIZE1         (0x0002)  /* SYS - BSL Protection Size 1 */
#define SYSBSLR             (0x0004)  /* SYS - RAM assigned to BSL */
//#define RESERVED            (0x0008)  /* SYS - Reserved */
//#define RESERVED            (0x0010)  /* SYS - Reserved */
//#define RESERVED            (0x0020)  /* SYS - Reserved */
//#define RESERVED            (0x0040)  /* SYS - Reserved */
//#define RESERVED            (0x0080)  /* SYS - Reserved */
//#define RESERVED            (0x0100)  /* SYS - Reserved */
//#define RESERVED            (0x0200)  /* SYS - Reserved */
//#define RESERVED            (0x0400)  /* SYS - Reserved */
//#define RESERVED            (0x0800)  /* SYS - Reserved */
//#define RESERVED            (0x1000)  /* SYS - Reserved */
//#define RESERVED            (0x2000)  /* SYS - Reserved */
#define SYSBSLOFF           (0x4000)  /* SYS - BSL Memory disabled */
#define SYSBSLPE            (0x8000)  /* SYS - BSL Memory protection enabled */

/* SYSBSLC Control Bits */
#define SYSBSLSIZE0_L       (0x0001)  /* SYS - BSL Protection Size 0 */
#define SYSBSLSIZE1_L       (0x0002)  /* SYS - BSL Protection Size 1 */
#define SYSBSLR_L           (0x0004)  /* SYS - RAM assigned to BSL */
//#define RESERVED            (0x0008)  /* SYS - Reserved */
//#define RESERVED            (0x0010)  /* SYS - Reserved */
//#define RESERVED            (0x0020)  /* SYS - Reserved */
//#define RESERVED            (0x0040)  /* SYS - Reserved */
//#define RESERVED            (0x0080)  /* SYS - Reserved */
//#define RESERVED            (0x0100)  /* SYS - Reserved */
//#define RESERVED            (0x0200)  /* SYS - Reserved */
//#define RESERVED            (0x0400)  /* SYS - Reserved */
//#define RESERVED            (0x0800)  /* SYS - Reserved */
//#define RESERVED            (0x1000)  /* SYS - Reserved */
//#define RESERVED            (0x2000)  /* SYS - Reserved */

/* SYSBSLC Control Bits */
//#define RESERVED            (0x0008)  /* SYS - Reserved */
//#define RESERVED            (0x0010)  /* SYS - Reserved */
//#define RESERVED            (0x0020)  /* SYS - Reserved */
//#define RESERVED            (0x0040)  /* SYS - Reserved */
//#define RESERVED            (0x0080)  /* SYS - Reserved */
//#define RESERVED            (0x0100)  /* SYS - Reserved */
//#define RESERVED            (0x0200)  /* SYS - Reserved */
//#define RESERVED            (0x0400)  /* SYS - Reserved */
//#define RESERVED            (0x0800)  /* SYS - Reserved */
//#define RESERVED            (0x1000)  /* SYS - Reserved */
//#define RESERVED            (0x2000)  /* SYS - Reserved */
#define SYSBSLOFF_H         (0x0040)  /* SYS - BSL Memory disabled */
#define SYSBSLPE_H          (0x0080)  /* SYS - BSL Memory protection enabled */

/* SYSJMBC Control Bits */
#define JMBIN0FG            (0x0001)  /* SYS - Incoming JTAG Mailbox 0 Flag */
#define JMBIN1FG            (0x0002)  /* SYS - Incoming JTAG Mailbox 1 Flag */
#define JMBOUT0FG           (0x0004)  /* SYS - Outgoing JTAG Mailbox 0 Flag */
#define JMBOUT1FG           (0x0008)  /* SYS - Outgoing JTAG Mailbox 1 Flag */
#define JMBMODE             (0x0010)  /* SYS - JMB 16/32 Bit Mode */
//#define RESERVED            (0x0020)  /* SYS - Reserved */
#define JMBCLR0OFF          (0x0040)  /* SYS - Incoming JTAG Mailbox 0 Flag auto-clear disalbe */
#define JMBCLR1OFF          (0x0080)  /* SYS - Incoming JTAG Mailbox 1 Flag auto-clear disalbe */
//#define RESERVED            (0x0100)  /* SYS - Reserved */
//#define RESERVED            (0x0200)  /* SYS - Reserved */
//#define RESERVED            (0x0400)  /* SYS - Reserved */
//#define RESERVED            (0x0800)  /* SYS - Reserved */
//#define RESERVED            (0x1000)  /* SYS - Reserved */
//#define RESERVED            (0x2000)  /* SYS - Reserved */
//#define RESERVED            (0x4000)  /* SYS - Reserved */
//#define RESERVED            (0x8000)  /* SYS - Reserved */

/* SYSJMBC Control Bits */
#define JMBIN0FG_L          (0x0001)  /* SYS - Incoming JTAG Mailbox 0 Flag */
#define JMBIN1FG_L          (0x0002)  /* SYS - Incoming JTAG Mailbox 1 Flag */
#define JMBOUT0FG_L         (0x0004)  /* SYS - Outgoing JTAG Mailbox 0 Flag */
#define JMBOUT1FG_L         (0x0008)  /* SYS - Outgoing JTAG Mailbox 1 Flag */
#define JMBMODE_L           (0x0010)  /* SYS - JMB 16/32 Bit Mode */
//#define RESERVED            (0x0020)  /* SYS - Reserved */
#define JMBCLR0OFF_L        (0x0040)  /* SYS - Incoming JTAG Mailbox 0 Flag auto-clear disalbe */
#define JMBCLR1OFF_L        (0x0080)  /* SYS - Incoming JTAG Mailbox 1 Flag auto-clear disalbe */
//#define RESERVED            (0x0100)  /* SYS - Reserved */
//#define RESERVED            (0x0200)  /* SYS - Reserved */
//#define RESERVED            (0x0400)  /* SYS - Reserved */
//#define RESERVED            (0x0800)  /* SYS - Reserved */
//#define RESERVED            (0x1000)  /* SYS - Reserved */
//#define RESERVED            (0x2000)  /* SYS - Reserved */
//#define RESERVED            (0x4000)  /* SYS - Reserved */
//#define RESERVED            (0x8000)  /* SYS - Reserved */








/* SYSUNIV Definitions */
#define SYSUNIV_NONE       (0x0000)    /* No Interrupt pending */
#define SYSUNIV_NMIIFG     (0x0002)    /* SYSUNIV : NMIIFG */
#define SYSUNIV_OFIFG      (0x0004)    /* SYSUNIV : Osc. Fail - OFIFG */

/* SYSSNIV Definitions */
#define SYSSNIV_NONE       (0x0000)    /* No Interrupt pending */
#define SYSSNIV_SVS        (0x0002)    /* SYSSNIV : SVS low_power reset */
#define SYSSNIV_UBDIFG     (0x0004)    /* SYSSNIV : FRAM Uncorrectable bit Error */
#define SYSSNIV_ACCTEIFG   (0x0006)    /* SYSSNIV : Access time error */
#define SYSSNIV_MPUSEGPIFG (0x0008)    /* SYSSNIV : MPUSEGPIFG violation */
#define SYSSNIV_MPUSEGIIFG (0x000A)    /* SYSSNIV : MPUSEGIIFG violation */
#define SYSSNIV_MPUSEG1IFG (0x000C)    /* SYSSNIV : MPUSEG1IFG violation */
#define SYSSNIV_MPUSEG2IFG (0x000E)    /* SYSSNIV : MPUSEG2IFG violation */
#define SYSSNIV_MPUSEG3IFG (0x0010)    /* SYSSNIV : MPUSEG3IFG violation */
#define SYSSNIV_VMAIFG     (0x0012)    /* SYSSNIV : VMAIFG */
#define SYSSNIV_JMBINIFG   (0x0014)    /* SYSSNIV : JMBINIFG */
#define SYSSNIV_JMBOUTIFG  (0x0016)    /* SYSSNIV : JMBOUTIFG */
#define SYSSNIV_CBDIFG     (0x0018)    /* SYSSNIV : FRAM Correctable Bit error */

/* SYSRSTIV Definitions */
#define SYSRSTIV_NONE      (0x0000)    /* No Interrupt pending */
#define SYSRSTIV_BOR       (0x0002)    /* SYSRSTIV : BOR */
#define SYSRSTIV_RSTNMI    (0x0004)    /* SYSRSTIV : RST/NMI */
#define SYSRSTIV_DOBOR     (0x0006)    /* SYSRSTIV : Do BOR */
#define SYSRSTIV_LPM5WU    (0x0008)    /* SYSRSTIV : Port LPM5 Wake Up */
#define SYSRSTIV_SECYV     (0x000A)    /* SYSRSTIV : Security violation */
#define SYSRSTIV_RES0C     (0x000C)    /* SYSRSTIV : Reserved */
#define SYSRSTIV_SVSHIFG   (0x000E)    /* SYSRSTIV : SVSHIFG */
#define SYSRSTIV_RES10     (0x0010)    /* SYSRSTIV : Reserved */
#define SYSRSTIV_RES12     (0x0012)    /* SYSRSTIV : Reserved */
#define SYSRSTIV_DOPOR     (0x0014)    /* SYSRSTIV : Do POR */
#define SYSRSTIV_WDTTO     (0x0016)    /* SYSRSTIV : WDT Time out */
#define SYSRSTIV_WDTKEY    (0x0018)    /* SYSRSTIV : WDTKEY violation */
#define SYSRSTIV_FRCTLPW   (0x001A)    /* SYSRSTIV : FRAM Key violation */
#define SYSRSTIV_UBDIFG    (0x001C)    /* SYSRSTIV : FRAM Uncorrectable bit Error */
#define SYSRSTIV_PERF      (0x001E)    /* SYSRSTIV : peripheral/config area fetch */
#define SYSRSTIV_PMMPW     (0x0020)    /* SYSRSTIV : PMM Password violation */
#define SYSRSTIV_MPUPW     (0x0022)    /* SYSRSTIV : MPU Password violation */
#define SYSRSTIV_CSPW      (0x0024)    /* SYSRSTIV : CS Password violation */
#define SYSRSTIV_MPUSEGPIFG (0x0026)   /* SYSRSTIV : MPUSEGPIFG violation */
#define SYSRSTIV_MPUSEGIIFG (0x0028)   /* SYSRSTIV : MPUSEGIIFG violation */
#define SYSRSTIV_MPUSEG1IFG (0x002A)   /* SYSRSTIV : MPUSEG1IFG violation */
#define SYSRSTIV_MPUSEG2IFG (0x002C)   /* SYSRSTIV : MPUSEG2IFG violation */
#define SYSRSTIV_MPUSEG3IFG (0x002E)   /* SYSRSTIV : MPUSEG3IFG violation */

/************************************************************
* Timer0_A3
************************************************************/
#define __MSP430_HAS_T0A3__           /* Definition to show that Module is available */
#define __MSP430_BASEADDRESS_T0A3__ 0x0340
#define TIMER_A0_BASE __MSP430_BASEADDRESS_T0A3__

#define TA0CTL_               0x0340    /* Timer0_A3 Control */
sfrw(TA0CTL, TA0CTL_);
#define TA0CCTL0_             0x0342    /* Timer0_A3 Capture/Compare Control 0 */
sfrw(TA0CCTL0, TA0CCTL0_);
#define TA0CCTL1_             0x0344    /* Timer0_A3 Capture/Compare Control 1 */
sfrw(TA0CCTL1, TA0CCTL1_);
#define TA0CCTL2_             0x0346    /* Timer0_A3 Capture/Compare Control 2 */
sfrw(TA0CCTL2, TA0CCTL2_);
#define TA0R_                 0x0350    /* Timer0_A3 */
sfrw(TA0R, TA0R_);
#define TA0CCR0_              0x0352    /* Timer0_A3 Capture/Compare 0 */
sfrw(TA0CCR0, TA0CCR0_);
#define TA0CCR1_              0x0354    /* Timer0_A3 Capture/Compare 1 */
sfrw(TA0CCR1, TA0CCR1_);
#define TA0CCR2_              0x0356    /* Timer0_A3 Capture/Compare 2 */
sfrw(TA0CCR2, TA0CCR2_);
#define TA0IV_                0x036E    /* Timer0_A3 Interrupt Vector Word */
sfrw(TA0IV, TA0IV_);
#define TA0EX0_               0x0360    /* Timer0_A3 Expansion Register 0 */
sfrw(TA0EX0, TA0EX0_);

/* TAxCTL Control Bits */
#define TASSEL1             (0x0200)  /* Timer A clock source select 1 */
#define TASSEL0             (0x0100)  /* Timer A clock source select 0 */
#define ID1                 (0x0080)  /* Timer A clock input divider 1 */
#define ID0                 (0x0040)  /* Timer A clock input divider 0 */
#define MC1                 (0x0020)  /* Timer A mode control 1 */
#define MC0                 (0x0010)  /* Timer A mode control 0 */
#define TACLR               (0x0004)  /* Timer A counter clear */
#define TAIE                (0x0002)  /* Timer A counter interrupt enable */
#define TAIFG               (0x0001)  /* Timer A counter interrupt flag */

#define MC_0                (0x0000)  /* Timer A mode control: 0 - Stop */
#define MC_1                (0x0010)  /* Timer A mode control: 1 - Up to CCR0 */
#define MC_2                (0x0020)  /* Timer A mode control: 2 - Continuous up */
#define MC_3                (0x0030)  /* Timer A mode control: 3 - Up/Down */
#define ID_0                (0x0000)  /* Timer A input divider: 0 - /1 */
#define ID_1                (0x0040)  /* Timer A input divider: 1 - /2 */
#define ID_2                (0x0080)  /* Timer A input divider: 2 - /4 */
#define ID_3                (0x00C0)  /* Timer A input divider: 3 - /8 */
#define TASSEL_0            (0x0000) /* Timer A clock source select: 0 - TACLK */
#define TASSEL_1            (0x0100) /* Timer A clock source select: 1 - ACLK  */
#define TASSEL_2            (0x0200) /* Timer A clock source select: 2 - SMCLK */
#define TASSEL_3            (0x0300) /* Timer A clock source select: 3 - INCLK */
#define MC__STOP            (0x0000)  /* Timer A mode control: 0 - Stop */
#define MC__UP              (0x0010)  /* Timer A mode control: 1 - Up to CCR0 */
#define MC__CONTINUOUS      (0x0020)  /* Timer A mode control: 2 - Continuous up */
#define MC__CONTINOUS       (0x0020)  /* Legacy define */
#define MC__UPDOWN          (0x0030)  /* Timer A mode control: 3 - Up/Down */
#define ID__1               (0x0000)  /* Timer A input divider: 0 - /1 */
#define ID__2               (0x0040)  /* Timer A input divider: 1 - /2 */
#define ID__4               (0x0080)  /* Timer A input divider: 2 - /4 */
#define ID__8               (0x00C0)  /* Timer A input divider: 3 - /8 */
#define TASSEL__TACLK       (0x0000) /* Timer A clock source select: 0 - TACLK */
#define TASSEL__ACLK        (0x0100) /* Timer A clock source select: 1 - ACLK  */
#define TASSEL__SMCLK       (0x0200) /* Timer A clock source select: 2 - SMCLK */
#define TASSEL__INCLK       (0x0300) /* Timer A clock source select: 3 - INCLK */

/* TAxCCTLx Control Bits */
#define CM1                 (0x8000)  /* Capture mode 1 */
#define CM0                 (0x4000)  /* Capture mode 0 */
#define CCIS1               (0x2000)  /* Capture input select 1 */
#define CCIS0               (0x1000)  /* Capture input select 0 */
#define SCS                 (0x0800)  /* Capture sychronize */
#define SCCI                (0x0400)  /* Latched capture signal (read) */
#define CAP                 (0x0100)  /* Capture mode: 1 /Compare mode : 0 */
#define OUTMOD2             (0x0080)  /* Output mode 2 */
#define OUTMOD1             (0x0040)  /* Output mode 1 */
#define OUTMOD0             (0x0020)  /* Output mode 0 */
#define CCIE                (0x0010)  /* Capture/compare interrupt enable */
#define CCI                 (0x0008)  /* Capture input signal (read) */
#define OUT                 (0x0004)  /* PWM Output signal if output mode 0 */
#define COV                 (0x0002)  /* Capture/compare overflow flag */
#define CCIFG               (0x0001)  /* Capture/compare interrupt flag */

#define OUTMOD_0            (0x0000)  /* PWM output mode: 0 - output only */
#define OUTMOD_1            (0x0020)  /* PWM output mode: 1 - set */
#define OUTMOD_2            (0x0040)  /* PWM output mode: 2 - PWM toggle/reset */
#define OUTMOD_3            (0x0060)  /* PWM output mode: 3 - PWM set/reset */
#define OUTMOD_4            (0x0080)  /* PWM output mode: 4 - toggle */
#define OUTMOD_5            (0x00A0)  /* PWM output mode: 5 - Reset */
#define OUTMOD_6            (0x00C0)  /* PWM output mode: 6 - PWM toggle/set */
#define OUTMOD_7            (0x00E0)  /* PWM output mode: 7 - PWM reset/set */
#define CCIS_0              (0x0000) /* Capture input select: 0 - CCIxA */
#define CCIS_1              (0x1000) /* Capture input select: 1 - CCIxB */
#define CCIS_2              (0x2000) /* Capture input select: 2 - GND */
#define CCIS_3              (0x3000) /* Capture input select: 3 - Vcc */
#define CM_0                (0x0000) /* Capture mode: 0 - disabled */
#define CM_1                (0x4000) /* Capture mode: 1 - pos. edge */
#define CM_2                (0x8000) /* Capture mode: 1 - neg. edge */
#define CM_3                (0xC000) /* Capture mode: 1 - both edges */


/* TAxEX0 Control Bits */
#define TAIDEX0             (0x0001)  /* Timer A Input divider expansion Bit: 0 */
#define TAIDEX1             (0x0002)  /* Timer A Input divider expansion Bit: 1 */
#define TAIDEX2             (0x0004)  /* Timer A Input divider expansion Bit: 2 */

#define TAIDEX_0            (0x0000) /* Timer A Input divider expansion : /1 */
#define TAIDEX_1            (0x0001) /* Timer A Input divider expansion : /2 */
#define TAIDEX_2            (0x0002) /* Timer A Input divider expansion : /3 */
#define TAIDEX_3            (0x0003) /* Timer A Input divider expansion : /4 */
#define TAIDEX_4            (0x0004) /* Timer A Input divider expansion : /5 */
#define TAIDEX_5            (0x0005) /* Timer A Input divider expansion : /6 */
#define TAIDEX_6            (0x0006) /* Timer A Input divider expansion : /7 */
#define TAIDEX_7            (0x0007) /* Timer A Input divider expansion : /8 */

/* T0A3IV Definitions */
#define TA0IV_NONE          (0x0000)    /* No Interrupt pending */
#define TA0IV_TACCR1        (0x0002)    /* TA0CCR1_CCIFG */
#define TA0IV_TACCR2        (0x0004)    /* TA0CCR2_CCIFG */
#define TA0IV_3             (0x0006)    /* Reserved */
#define TA0IV_4             (0x0008)    /* Reserved */
#define TA0IV_5             (0x000A)    /* Reserved */
#define TA0IV_6             (0x000C)    /* Reserved */
#define TA0IV_TAIFG         (0x000E)    /* TA0IFG */

/* Legacy Defines */
#define TA0IV_TA0CCR1       (0x0002)    /* TA0CCR1_CCIFG */
#define TA0IV_TA0CCR2       (0x0004)    /* TA0CCR2_CCIFG */
#define TA0IV_TA0IFG        (0x000E)    /* TA0IFG */

/************************************************************
* Timer1_A3
************************************************************/
#define __MSP430_HAS_T1A3__            /* Definition to show that Module is available */
#define __MSP430_BASEADDRESS_T1A3__ 0x0380
#define TIMER_A1_BASE __MSP430_BASEADDRESS_T1A3__

#define TA1CTL_               0x0380    /* Timer1_A3 Control */
sfrw(TA1CTL, TA1CTL_);
#define TA1CCTL0_             0x0382    /* Timer1_A3 Capture/Compare Control 0 */
sfrw(TA1CCTL0, TA1CCTL0_);
#define TA1CCTL1_             0x0384    /* Timer1_A3 Capture/Compare Control 1 */
sfrw(TA1CCTL1, TA1CCTL1_);
#define TA1CCTL2_             0x0386    /* Timer1_A3 Capture/Compare Control 2 */
sfrw(TA1CCTL2, TA1CCTL2_);
#define TA1R_                 0x0390    /* Timer1_A3 */
sfrw(TA1R, TA1R_);
#define TA1CCR0_              0x0392    /* Timer1_A3 Capture/Compare 0 */
sfrw(TA1CCR0, TA1CCR0_);
#define TA1CCR1_              0x0394    /* Timer1_A3 Capture/Compare 1 */
sfrw(TA1CCR1, TA1CCR1_);
#define TA1CCR2_              0x0396    /* Timer1_A3 Capture/Compare 2 */
sfrw(TA1CCR2, TA1CCR2_);
#define TA1IV_                0x03AE    /* Timer1_A3 Interrupt Vector Word */
sfrw(TA1IV, TA1IV_);
#define TA1EX0_               0x03A0    /* Timer1_A3 Expansion Register 0 */
sfrw(TA1EX0, TA1EX0_);

/* Bits are already defined within the Timer0_Ax */

/* TA1IV Definitions */
#define TA1IV_NONE          (0x0000)    /* No Interrupt pending */
#define TA1IV_TACCR1        (0x0002)    /* TA1CCR1_CCIFG */
#define TA1IV_TACCR2        (0x0004)    /* TA1CCR2_CCIFG */
#define TA1IV_3             (0x0006)    /* Reserved */
#define TA1IV_4             (0x0008)    /* Reserved */
#define TA1IV_5             (0x000A)    /* Reserved */
#define TA1IV_6             (0x000C)    /* Reserved */
#define TA1IV_TAIFG         (0x000E)    /* TA1IFG */

/* Legacy Defines */
#define TA1IV_TA1CCR1      (0x0002)    /* TA1CCR1_CCIFG */
#define TA1IV_TA1CCR2      (0x0004)    /* TA1CCR2_CCIFG */
#define TA1IV_TA1IFG       (0x000E)    /* TA1IFG */

/************************************************************
* Timer2_A2
************************************************************/
#define __MSP430_HAS_T2A2__            /* Definition to show that Module is available */
#define __MSP430_BASEADDRESS_T2A2__ 0x0400
#define TIMER_A2_BASE __MSP430_BASEADDRESS_T2A2__

#define TA2CTL_               0x0400    /* Timer2_A2 Control */
sfrw(TA2CTL, TA2CTL_);
#define TA2CCTL0_             0x0402    /* Timer2_A2 Capture/Compare Control 0 */
sfrw(TA2CCTL0, TA2CCTL0_);
#define TA2CCTL1_             0x0404    /* Timer2_A2 Capture/Compare Control 1 */
sfrw(TA2CCTL1, TA2CCTL1_);
#define TA2R_                 0x0410    /* Timer2_A2 */
sfrw(TA2R, TA2R_);
#define TA2CCR0_              0x0412    /* Timer2_A2 Capture/Compare 0 */
sfrw(TA2CCR0, TA2CCR0_);
#define TA2CCR1_              0x0414    /* Timer2_A2 Capture/Compare 1 */
sfrw(TA2CCR1, TA2CCR1_);
#define TA2IV_                0x042E    /* Timer2_A2 Interrupt Vector Word */
sfrw(TA2IV, TA2IV_);
#define TA2EX0_               0x0420    /* Timer2_A2 Expansion Register 0 */
sfrw(TA2EX0, TA2EX0_);

/* Bits are already defined within the Timer0_Ax */

/* TA2IV Definitions */
#define TA2IV_NONE          (0x0000)    /* No Interrupt pending */
#define TA2IV_TACCR1        (0x0002)    /* TA2CCR1_CCIFG */
#define TA2IV_3             (0x0006)    /* Reserved */
#define TA2IV_4             (0x0008)    /* Reserved */
#define TA2IV_5             (0x000A)    /* Reserved */
#define TA2IV_6             (0x000C)    /* Reserved */
#define TA2IV_TAIFG         (0x000E)    /* TA2IFG */

/* Legacy Defines */
#define TA2IV_TA2CCR1      (0x0002)    /* TA2CCR1_CCIFG */
#define TA2IV_TA2IFG       (0x000E)    /* TA2IFG */

/************************************************************
* Timer3_A2
************************************************************/
#define __MSP430_HAS_T3A2__            /* Definition to show that Module is available */
#define __MSP430_BASEADDRESS_T3A2__ 0x0440
#define TIMER_A3_BASE __MSP430_BASEADDRESS_T3A2__

#define TA3CTL_               0x0440    /* Timer3_A2 Control */
sfrw(TA3CTL, TA3CTL_);
#define TA3CCTL0_             0x0442    /* Timer3_A2 Capture/Compare Control 0 */
sfrw(TA3CCTL0, TA3CCTL0_);
#define TA3CCTL1_             0x0444    /* Timer3_A2 Capture/Compare Control 1 */
sfrw(TA3CCTL1, TA3CCTL1_);
#define TA3R_                 0x0450    /* Timer3_A2 */
sfrw(TA3R, TA3R_);
#define TA3CCR0_              0x0452    /* Timer3_A2 Capture/Compare 0 */
sfrw(TA3CCR0, TA3CCR0_);
#define TA3CCR1_              0x0454    /* Timer3_A2 Capture/Compare 1 */
sfrw(TA3CCR1, TA3CCR1_);
#define TA3IV_                0x046E    /* Timer3_A2 Interrupt Vector Word */
sfrw(TA3IV, TA3IV_);
#define TA3EX0_               0x0460    /* Timer3_A2 Expansion Register 0 */
sfrw(TA3EX0, TA3EX0_);

/* Bits are already defined within the Timer0_Ax */

/* TA3IV Definitions */
#define TA3IV_NONE          (0x0000)    /* No Interrupt pending */
#define TA3IV_TACCR1        (0x0002)    /* TA3CCR1_CCIFG */
#define TA3IV_3             (0x0006)    /* Reserved */
#define TA3IV_4             (0x0008)    /* Reserved */
#define TA3IV_5             (0x000A)    /* Reserved */
#define TA3IV_6             (0x000C)    /* Reserved */
#define TA3IV_TAIFG         (0x000E)    /* TA3IFG */

/* Legacy Defines */
#define TA3IV_TA3CCR1      (0x0002)    /* TA3CCR1_CCIFG */
#define TA3IV_TA3IFG       (0x000E)    /* TA3IFG */

/************************************************************
* Timer0_B7
************************************************************/
#define __MSP430_HAS_T0B7__            /* Definition to show that Module is available */
#define __MSP430_BASEADDRESS_T0B7__ 0x03C0
#define TIMER_B0_BASE __MSP430_BASEADDRESS_T0B7__

#define TB0CTL_               0x03C0    /* Timer0_B7 Control */
sfrw(TB0CTL, TB0CTL_);
#define TB0CCTL0_             0x03C2    /* Timer0_B7 Capture/Compare Control 0 */
sfrw(TB0CCTL0, TB0CCTL0_);
#define TB0CCTL1_             0x03C4    /* Timer0_B7 Capture/Compare Control 1 */
sfrw(TB0CCTL1, TB0CCTL1_);
#define TB0CCTL2_             0x03C6    /* Timer0_B7 Capture/Compare Control 2 */
sfrw(TB0CCTL2, TB0CCTL2_);
#define TB0CCTL3_             0x03C8    /* Timer0_B7 Capture/Compare Control 3 */
sfrw(TB0CCTL3, TB0CCTL3_);
#define TB0CCTL4_             0x03CA    /* Timer0_B7 Capture/Compare Control 4 */
sfrw(TB0CCTL4, TB0CCTL4_);
#define TB0CCTL5_             0x03CC    /* Timer0_B7 Capture/Compare Control 5 */
sfrw(TB0CCTL5, TB0CCTL5_);
#define TB0CCTL6_             0x03CE    /* Timer0_B7 Capture/Compare Control 6 */
sfrw(TB0CCTL6, TB0CCTL6_);
#define TB0R_                 0x03D0    /* Timer0_B7 */
sfrw(TB0R, TB0R_);
#define TB0CCR0_              0x03D2    /* Timer0_B7 Capture/Compare 0 */
sfrw(TB0CCR0, TB0CCR0_);
#define TB0CCR1_              0x03D4    /* Timer0_B7 Capture/Compare 1 */
sfrw(TB0CCR1, TB0CCR1_);
#define TB0CCR2_              0x03D6    /* Timer0_B7 Capture/Compare 2 */
sfrw(TB0CCR2, TB0CCR2_);
#define TB0CCR3_              0x03D8    /* Timer0_B7 Capture/Compare 3 */
sfrw(TB0CCR3, TB0CCR3_);
#define TB0CCR4_              0x03DA    /* Timer0_B7 Capture/Compare 4 */
sfrw(TB0CCR4, TB0CCR4_);
#define TB0CCR5_              0x03DC    /* Timer0_B7 Capture/Compare 5 */
sfrw(TB0CCR5, TB0CCR5_);
#define TB0CCR6_              0x03DE    /* Timer0_B7 Capture/Compare 6 */
sfrw(TB0CCR6, TB0CCR6_);
#define TB0EX0_               0x03E0    /* Timer0_B7 Expansion Register 0 */
sfrw(TB0EX0, TB0EX0_);
#define TB0IV_                0x03EE    /* Timer0_B7 Interrupt Vector Word */
sfrw(TB0IV, TB0IV_);

/* Legacy Type Definitions for TimerB */
#define TBCTL                TB0CTL    /* Timer0_B7 Control */
#define TBCCTL0              TB0CCTL0  /* Timer0_B7 Capture/Compare Control 0 */
#define TBCCTL1              TB0CCTL1  /* Timer0_B7 Capture/Compare Control 1 */
#define TBCCTL2              TB0CCTL2  /* Timer0_B7 Capture/Compare Control 2 */
#define TBCCTL3              TB0CCTL3  /* Timer0_B7 Capture/Compare Control 3 */
#define TBCCTL4              TB0CCTL4  /* Timer0_B7 Capture/Compare Control 4 */
#define TBCCTL5              TB0CCTL5  /* Timer0_B7 Capture/Compare Control 5 */
#define TBCCTL6              TB0CCTL6  /* Timer0_B7 Capture/Compare Control 6 */
#define TBR                  TB0R      /* Timer0_B7 */
#define TBCCR0               TB0CCR0   /* Timer0_B7 Capture/Compare 0 */
#define TBCCR1               TB0CCR1   /* Timer0_B7 Capture/Compare 1 */
#define TBCCR2               TB0CCR2   /* Timer0_B7 Capture/Compare 2 */
#define TBCCR3               TB0CCR3   /* Timer0_B7 Capture/Compare 3 */
#define TBCCR4               TB0CCR4   /* Timer0_B7 Capture/Compare 4 */
#define TBCCR5               TB0CCR5   /* Timer0_B7 Capture/Compare 5 */
#define TBCCR6               TB0CCR6   /* Timer0_B7 Capture/Compare 6 */
#define TBEX0                TB0EX0    /* Timer0_B7 Expansion Register 0 */
#define TBIV                 TB0IV     /* Timer0_B7 Interrupt Vector Word */
#define TIMERB1_VECTOR       TIMER0_B1_VECTOR /* Timer0_B7 CC1-6, TB */
#define TIMERB0_VECTOR       TIMER0_B0_VECTOR /* Timer0_B7 CC0 */


/* TBxCTL Control Bits */
#define TBCLGRP1            (0x4000)  /* Timer0_B7 Compare latch load group 1 */
#define TBCLGRP0            (0x2000)  /* Timer0_B7 Compare latch load group 0 */
#define CNTL1               (0x1000)  /* Counter lenght 1 */
#define CNTL0               (0x0800)  /* Counter lenght 0 */
#define TBSSEL1             (0x0200)  /* Clock source 1 */
#define TBSSEL0             (0x0100)  /* Clock source 0 */
#define TBCLR               (0x0004)  /* Timer0_B7 counter clear */
#define TBIE                (0x0002)  /* Timer0_B7 interrupt enable */
#define TBIFG               (0x0001)  /* Timer0_B7 interrupt flag */

#define SHR1                (0x4000)  /* Timer0_B7 Compare latch load group 1 */
#define SHR0                (0x2000)  /* Timer0_B7 Compare latch load group 0 */

#define TBSSEL_0            (0x0000)  /* Clock Source: TBCLK */
#define TBSSEL_1            (0x0100)  /* Clock Source: ACLK  */
#define TBSSEL_2            (0x0200)  /* Clock Source: SMCLK */
#define TBSSEL_3            (0x0300)  /* Clock Source: INCLK */
#define CNTL_0              (0x0000)  /* Counter lenght: 16 bit */
#define CNTL_1              (0x0800)  /* Counter lenght: 12 bit */
#define CNTL_2              (0x1000)  /* Counter lenght: 10 bit */
#define CNTL_3              (0x1800)  /* Counter lenght:  8 bit */
#define SHR_0               (0x0000)  /* Timer0_B7 Group: 0 - individually */
#define SHR_1               (0x2000)  /* Timer0_B7 Group: 1 - 3 groups (1-2, 3-4, 5-6) */
#define SHR_2               (0x4000)  /* Timer0_B7 Group: 2 - 2 groups (1-3, 4-6)*/
#define SHR_3               (0x6000)  /* Timer0_B7 Group: 3 - 1 group (all) */
#define TBCLGRP_0           (0x0000)  /* Timer0_B7 Group: 0 - individually */
#define TBCLGRP_1           (0x2000)  /* Timer0_B7 Group: 1 - 3 groups (1-2, 3-4, 5-6) */
#define TBCLGRP_2           (0x4000)  /* Timer0_B7 Group: 2 - 2 groups (1-3, 4-6)*/
#define TBCLGRP_3           (0x6000)  /* Timer0_B7 Group: 3 - 1 group (all) */
#define TBSSEL__TBCLK       (0x0000) /* Timer0_B7 clock source select: 0 - TBCLK */
#define TBSSEL__TACLK       (0x0000) /* Timer0_B7 clock source select: 0 - TBCLK (legacy) */
#define TBSSEL__ACLK        (0x0100) /* Timer0_B7 clock source select: 1 - ACLK  */
#define TBSSEL__SMCLK       (0x0200) /* Timer0_B7 clock source select: 2 - SMCLK */
#define TBSSEL__INCLK       (0x0300) /* Timer0_B7 clock source select: 3 - INCLK */
#define CNTL__16            (0x0000)  /* Counter lenght: 16 bit */
#define CNTL__12            (0x0800)  /* Counter lenght: 12 bit */
#define CNTL__10            (0x1000)  /* Counter lenght: 10 bit */
#define CNTL__8             (0x1800)  /* Counter lenght:  8 bit */

/* Additional Timer B Control Register bits are defined in Timer A */
/* TBxCCTLx Control Bits */
#define CLLD1               (0x0400)  /* Compare latch load source 1 */
#define CLLD0               (0x0200)  /* Compare latch load source 0 */

#define SLSHR1              (0x0400)  /* Compare latch load source 1 */
#define SLSHR0              (0x0200)  /* Compare latch load source 0 */

#define SLSHR_0             (0x0000) /* Compare latch load sourec : 0 - immediate */
#define SLSHR_1             (0x0200) /* Compare latch load sourec : 1 - TBR counts to 0 */
#define SLSHR_2             (0x0400) /* Compare latch load sourec : 2 - up/down */
#define SLSHR_3             (0x0600) /* Compare latch load sourec : 3 - TBR counts to TBCTL0 */

#define CLLD_0              (0x0000) /* Compare latch load sourec : 0 - immediate */
#define CLLD_1              (0x0200) /* Compare latch load sourec : 1 - TBR counts to 0 */
#define CLLD_2              (0x0400) /* Compare latch load sourec : 2 - up/down */
#define CLLD_3              (0x0600) /* Compare latch load sourec : 3 - TBR counts to TBCTL0 */

/* TBxEX0 Control Bits */
#define TBIDEX0             (0x0001)   /* Timer0_B7 Input divider expansion Bit: 0 */
#define TBIDEX1             (0x0002)   /* Timer0_B7 Input divider expansion Bit: 1 */
#define TBIDEX2             (0x0004)   /* Timer0_B7 Input divider expansion Bit: 2 */

#define TBIDEX_0            (0x0000) /* Timer0_B7 Input divider expansion : /1 */
#define TBIDEX_1            (0x0001) /* Timer0_B7 Input divider expansion : /2 */
#define TBIDEX_2            (0x0002) /* Timer0_B7 Input divider expansion : /3 */
#define TBIDEX_3            (0x0003) /* Timer0_B7 Input divider expansion : /4 */
#define TBIDEX_4            (0x0004) /* Timer0_B7 Input divider expansion : /5 */
#define TBIDEX_5            (0x0005) /* Timer0_B7 Input divider expansion : /6 */
#define TBIDEX_6            (0x0006) /* Timer0_B7 Input divider expansion : /7 */
#define TBIDEX_7            (0x0007) /* Timer0_B7 Input divider expansion : /8 */
#define TBIDEX__1           (0x0000) /* Timer0_B7 Input divider expansion : /1 */
#define TBIDEX__2           (0x0001) /* Timer0_B7 Input divider expansion : /2 */
#define TBIDEX__3           (0x0002) /* Timer0_B7 Input divider expansion : /3 */
#define TBIDEX__4           (0x0003) /* Timer0_B7 Input divider expansion : /4 */
#define TBIDEX__5           (0x0004) /* Timer0_B7 Input divider expansion : /5 */
#define TBIDEX__6           (0x0005) /* Timer0_B7 Input divider expansion : /6 */
#define TBIDEX__7           (0x0006) /* Timer0_B7 Input divider expansion : /7 */
#define TBIDEX__8           (0x0007) /* Timer0_B7 Input divider expansion : /8 */

/* TB0IV Definitions */
#define TB0IV_NONE          (0x0000)    /* No Interrupt pending */
#define TB0IV_TBCCR1        (0x0002)    /* TB0CCR1_CCIFG */
#define TB0IV_TBCCR2        (0x0004)    /* TB0CCR2_CCIFG */
#define TB0IV_3             (0x0006)    /* Reserved */
#define TB0IV_4             (0x0008)    /* Reserved */
#define TB0IV_5             (0x000A)    /* Reserved */
#define TB0IV_6             (0x000C)    /* Reserved */
#define TB0IV_TBIFG         (0x000E)    /* TB0IFG */

/* Legacy Defines */
#define TB0IV_TB0CCR1       (0x0002)    /* TB0CCR1_CCIFG */
#define TB0IV_TB0CCR2       (0x0004)    /* TB0CCR2_CCIFG */
#define TB0IV_TB0IFG        (0x000E)    /* TB0IFG */


/************************************************************
* USCI A0
************************************************************/
#define __MSP430_HAS_EUSCI_A0__      /* Definition to show that Module is available */
#define __MSP430_BASEADDRESS_EUSCI_A0__ 0x05C0
#define EUSCI_A0_BASE __MSP430_BASEADDRESS_EUSCI_A0__

#define UCA0CTLW0_            0x05C0    /* USCI A0 Control Word Register 0 */
sfrb(UCA0CTLW0_L , UCA0CTLW0_);
sfrb(UCA0CTLW0_H , UCA0CTLW0_+1);
sfrw(UCA0CTLW0, UCA0CTLW0_);
#define UCA0CTL1            UCA0CTLW0_L  /* USCI A0 Control Register 1 */
#define UCA0CTL0            UCA0CTLW0_H  /* USCI A0 Control Register 0 */
#define UCA0CTLW1_            0x05C2    /* USCI A0 Control Word Register 1 */
sfrb(UCA0CTLW1_L , UCA0CTLW1_);
sfrb(UCA0CTLW1_H , UCA0CTLW1_+1);
sfrw(UCA0CTLW1, UCA0CTLW1_);
#define UCA0BRW_              0x05C6    /* USCI A0 Baud Word Rate 0 */
sfrb(UCA0BRW_L , UCA0BRW_);
sfrb(UCA0BRW_H , UCA0BRW_+1);
sfrw(UCA0BRW, UCA0BRW_);
#define UCA0BR0             UCA0BRW_L /* USCI A0 Baud Rate 0 */
#define UCA0BR1             UCA0BRW_H /* USCI A0 Baud Rate 1 */
#define UCA0MCTLW_            0x05C8    /* USCI A0 Modulation Control */
sfrb(UCA0MCTLW_L , UCA0MCTLW_);
sfrb(UCA0MCTLW_H , UCA0MCTLW_+1);
sfrw(UCA0MCTLW, UCA0MCTLW_);
#define UCA0STATW_            0x05CA    /* USCI A0 Status Register */
sfrb(UCA0STATW, UCA0STATW_);
#define UCA0RXBUF_            0x05CC    /* USCI A0 Receive Buffer */
const_sfrb(UCA0RXBUF_L , UCA0RXBUF_);
const_sfrb(UCA0RXBUF_H , UCA0RXBUF_+1);
const_sfrw(UCA0RXBUF, UCA0RXBUF_);
#define UCA0TXBUF_            0x05CE    /* USCI A0 Transmit Buffer */
sfrb(UCA0TXBUF_L , UCA0TXBUF_);
sfrb(UCA0TXBUF_H , UCA0TXBUF_+1);
sfrw(UCA0TXBUF, UCA0TXBUF_);
#define UCA0ABCTL_            0x05D0    /* USCI A0 LIN Control */
sfrb(UCA0ABCTL, UCA0ABCTL_);
#define UCA0IRCTL_            0x05D2    /* USCI A0 IrDA Transmit Control */
sfrb(UCA0IRCTL_L , UCA0IRCTL_);
sfrb(UCA0IRCTL_H , UCA0IRCTL_+1);
sfrw(UCA0IRCTL, UCA0IRCTL_);
#define UCA0IRTCTL          UCA0IRCTL_L  /* USCI A0 IrDA Transmit Control */
#define UCA0IRRCTL          UCA0IRCTL_H  /* USCI A0 IrDA Receive Control */
#define UCA0IE_               0x05DA    /* USCI A0 Interrupt Enable Register */
sfrb(UCA0IE_L , UCA0IE_);
sfrb(UCA0IE_H , UCA0IE_+1);
sfrw(UCA0IE, UCA0IE_);
#define UCA0IFG_              0x05DC    /* USCI A0 Interrupt Flags Register */
sfrb(UCA0IFG_L , UCA0IFG_);
sfrb(UCA0IFG_H , UCA0IFG_+1);
sfrw(UCA0IFG, UCA0IFG_);
#define UCA0IV_               0x05DE    /* USCI A0 Interrupt Vector Register */
sfrw(UCA0IV, UCA0IV_);


/************************************************************
* USCI A1
************************************************************/
#define __MSP430_HAS_EUSCI_A1__      /* Definition to show that Module is available */
#define __MSP430_BASEADDRESS_EUSCI_A1__ 0x05E0
#define EUSCI_A1_BASE __MSP430_BASEADDRESS_EUSCI_A1__

#define UCA1CTLW0_            0x05E0    /* USCI A1 Control Word Register 0 */
sfrb(UCA1CTLW0_L , UCA1CTLW0_);
sfrb(UCA1CTLW0_H , UCA1CTLW0_+1);
sfrw(UCA1CTLW0, UCA1CTLW0_);
#define UCA1CTL1            UCA1CTLW0_L  /* USCI A1 Control Register 1 */
#define UCA1CTL0            UCA1CTLW0_H  /* USCI A1 Control Register 0 */
#define UCA1CTLW1_            0x05E2    /* USCI A1 Control Word Register 1 */
sfrb(UCA1CTLW1_L , UCA1CTLW1_);
sfrb(UCA1CTLW1_H , UCA1CTLW1_+1);
sfrw(UCA1CTLW1, UCA1CTLW1_);
#define UCA1BRW_              0x05E6    /* USCI A1 Baud Word Rate 0 */
sfrb(UCA1BRW_L , UCA1BRW_);
sfrb(UCA1BRW_H , UCA1BRW_+1);
sfrw(UCA1BRW, UCA1BRW_);
#define UCA1BR0             UCA1BRW_L /* USCI A1 Baud Rate 0 */
#define UCA1BR1             UCA1BRW_H /* USCI A1 Baud Rate 1 */
#define UCA1MCTLW_            0x05E8    /* USCI A1 Modulation Control */
sfrb(UCA1MCTLW_L , UCA1MCTLW_);
sfrb(UCA1MCTLW_H , UCA1MCTLW_+1);
sfrw(UCA1MCTLW, UCA1MCTLW_);
#define UCA1STATW_            0x05EA    /* USCI A1 Status Register */
sfrb(UCA1STATW, UCA1STATW_);
#define UCA1RXBUF_            0x05EC    /* USCI A1 Receive Buffer */
const_sfrb(UCA1RXBUF_L , UCA1RXBUF_);
const_sfrb(UCA1RXBUF_H , UCA1RXBUF_+1);
const_sfrw(UCA1RXBUF, UCA1RXBUF_);
#define UCA1TXBUF_            0x05EE    /* USCI A1 Transmit Buffer */
sfrb(UCA1TXBUF_L , UCA1TXBUF_);
sfrb(UCA1TXBUF_H , UCA1TXBUF_+1);
sfrw(UCA1TXBUF, UCA1TXBUF_);
#define UCA1ABCTL_            0x05F0    /* USCI A1 LIN Control */
sfrb(UCA1ABCTL, UCA1ABCTL_);
#define UCA1IRCTL_            0x05F2    /* USCI A1 IrDA Transmit Control */
sfrb(UCA1IRCTL_L , UCA1IRCTL_);
sfrb(UCA1IRCTL_H , UCA1IRCTL_+1);
sfrw(UCA1IRCTL, UCA1IRCTL_);
#define UCA1IRTCTL          UCA1IRCTL_L  /* USCI A1 IrDA Transmit Control */
#define UCA1IRRCTL          UCA1IRCTL_H  /* USCI A1 IrDA Receive Control */
#define UCA1IE_               0x05FA    /* USCI A1 Interrupt Enable Register */
sfrb(UCA1IE_L , UCA1IE_);
sfrb(UCA1IE_H , UCA1IE_+1);
sfrw(UCA1IE, UCA1IE_);
#define UCA1IFG_              0x05FC    /* USCI A1 Interrupt Flags Register */
sfrb(UCA1IFG_L , UCA1IFG_);
sfrb(UCA1IFG_H , UCA1IFG_+1);
sfrw(UCA1IFG, UCA1IFG_);
#define UCA1IV_               0x05FE    /* USCI A1 Interrupt Vector Register */
sfrw(UCA1IV, UCA1IV_);


/************************************************************
* USCI B0
************************************************************/
#define __MSP430_HAS_EUSCI_B0__       /* Definition to show that Module is available */
#define __MSP430_BASEADDRESS_EUSCI_B0__ 0x0640
#define EUSCI_B0_BASE __MSP430_BASEADDRESS_EUSCI_B0__


#define UCB0CTLW0_            0x0640    /* USCI B0 Control Word Register 0 */
sfrb(UCB0CTLW0_L , UCB0CTLW0_);
sfrb(UCB0CTLW0_H , UCB0CTLW0_+1);
sfrw(UCB0CTLW0, UCB0CTLW0_);
#define UCB0CTL1            UCB0CTLW0_L  /* USCI B0 Control Register 1 */
#define UCB0CTL0            UCB0CTLW0_H  /* USCI B0 Control Register 0 */
#define UCB0CTLW1_            0x0642    /* USCI B0 Control Word Register 1 */
sfrb(UCB0CTLW1_L , UCB0CTLW1_);
sfrb(UCB0CTLW1_H , UCB0CTLW1_+1);
sfrw(UCB0CTLW1, UCB0CTLW1_);
#define UCB0BRW_              0x0646    /* USCI B0 Baud Word Rate 0 */
sfrb(UCB0BRW_L , UCB0BRW_);
sfrb(UCB0BRW_H , UCB0BRW_+1);
sfrw(UCB0BRW, UCB0BRW_);
#define UCB0BR0             UCB0BRW_L /* USCI B0 Baud Rate 0 */
#define UCB0BR1             UCB0BRW_H /* USCI B0 Baud Rate 1 */
#define UCB0STATW_            0x0648    /* USCI B0 Status Word Register */
sfrb(UCB0STATW_L , UCB0STATW_);
sfrb(UCB0STATW_H , UCB0STATW_+1);
sfrw(UCB0STATW, UCB0STATW_);
#define UCB0STAT            UCB0STATW_L /* USCI B0 Status Register */
#define UCB0BCNT            UCB0STATW_H /* USCI B0 Byte Counter Register */
#define UCB0TBCNT_            0x064A    /* USCI B0 Byte Counter Threshold Register */
sfrb(UCB0TBCNT_L , UCB0TBCNT_);
sfrb(UCB0TBCNT_H , UCB0TBCNT_+1);
sfrw(UCB0TBCNT, UCB0TBCNT_);
#define UCB0RXBUF_            0x064C    /* USCI B0 Receive Buffer */
const_sfrb(UCB0RXBUF_L , UCB0RXBUF_);
const_sfrb(UCB0RXBUF_H , UCB0RXBUF_+1);
const_sfrw(UCB0RXBUF, UCB0RXBUF_);
#define UCB0TXBUF_            0x064E    /* USCI B0 Transmit Buffer */
sfrb(UCB0TXBUF_L , UCB0TXBUF_);
sfrb(UCB0TXBUF_H , UCB0TXBUF_+1);
sfrw(UCB0TXBUF, UCB0TXBUF_);
#define UCB0I2COA0_           0x0654    /* USCI B0 I2C Own Address 0 */
sfrb(UCB0I2COA0_L , UCB0I2COA0_);
sfrb(UCB0I2COA0_H , UCB0I2COA0_+1);
sfrw(UCB0I2COA0, UCB0I2COA0_);
#define UCB0I2COA1_           0x0656    /* USCI B0 I2C Own Address 1 */
sfrb(UCB0I2COA1_L , UCB0I2COA1_);
sfrb(UCB0I2COA1_H , UCB0I2COA1_+1);
sfrw(UCB0I2COA1, UCB0I2COA1_);
#define UCB0I2COA2_           0x0658    /* USCI B0 I2C Own Address 2 */
sfrb(UCB0I2COA2_L , UCB0I2COA2_);
sfrb(UCB0I2COA2_H , UCB0I2COA2_+1);
sfrw(UCB0I2COA2, UCB0I2COA2_);
#define UCB0I2COA3_           0x065A    /* USCI B0 I2C Own Address 3 */
sfrb(UCB0I2COA3_L , UCB0I2COA3_);
sfrb(UCB0I2COA3_H , UCB0I2COA3_+1);
sfrw(UCB0I2COA3, UCB0I2COA3_);
#define UCB0ADDRX_            0x065C    /* USCI B0 Received Address Register */
sfrb(UCB0ADDRX_L , UCB0ADDRX_);
sfrb(UCB0ADDRX_H , UCB0ADDRX_+1);
sfrw(UCB0ADDRX, UCB0ADDRX_);
#define UCB0ADDMASK_          0x065E    /* USCI B0 Address Mask Register */
sfrb(UCB0ADDMASK_L , UCB0ADDMASK_);
sfrb(UCB0ADDMASK_H , UCB0ADDMASK_+1);
sfrw(UCB0ADDMASK, UCB0ADDMASK_);
#define UCB0I2CSA_            0x0660    /* USCI B0 I2C Slave Address */
sfrb(UCB0I2CSA_L , UCB0I2CSA_);
sfrb(UCB0I2CSA_H , UCB0I2CSA_+1);
sfrw(UCB0I2CSA, UCB0I2CSA_);
#define UCB0IE_               0x066A    /* USCI B0 Interrupt Enable Register */
sfrb(UCB0IE_L , UCB0IE_);
sfrb(UCB0IE_H , UCB0IE_+1);
sfrw(UCB0IE, UCB0IE_);
#define UCB0IFG_              0x066C    /* USCI B0 Interrupt Flags Register */
sfrb(UCB0IFG_L , UCB0IFG_);
sfrb(UCB0IFG_H , UCB0IFG_+1);
sfrw(UCB0IFG, UCB0IFG_);
#define UCB0IV_               0x066E    /* USCI B0 Interrupt Vector Register */
sfrw(UCB0IV, UCB0IV_);


// UCAxCTLW0 UART-Mode Control Bits
#define UCPEN               (0x8000)    /* Async. Mode: Parity enable */
#define UCPAR               (0x4000)    /* Async. Mode: Parity     0:odd / 1:even */
#define UCMSB               (0x2000)    /* Async. Mode: MSB first  0:LSB / 1:MSB */
#define UC7BIT              (0x1000)    /* Async. Mode: Data Bits  0:8-bits / 1:7-bits */
#define UCSPB               (0x0800)    /* Async. Mode: Stop Bits  0:one / 1: two */
#define UCMODE1             (0x0400)    /* Async. Mode: USCI Mode 1 */
#define UCMODE0             (0x0200)    /* Async. Mode: USCI Mode 0 */
#define UCSYNC              (0x0100)    /* Sync-Mode  0:UART-Mode / 1:SPI-Mode */
#define UCSSEL1             (0x0080)    /* USCI 0 Clock Source Select 1 */
#define UCSSEL0             (0x0040)    /* USCI 0 Clock Source Select 0 */
#define UCRXEIE             (0x0020)    /* RX Error interrupt enable */
#define UCBRKIE             (0x0010)    /* Break interrupt enable */
#define UCDORM              (0x0008)    /* Dormant (Sleep) Mode */
#define UCTXADDR            (0x0004)    /* Send next Data as Address */
#define UCTXBRK             (0x0002)    /* Send next Data as Break */
#define UCSWRST             (0x0001)    /* USCI Software Reset */

// UCAxCTLW0 UART-Mode Control Bits
#define UCSSEL1_L           (0x0080)    /* USCI 0 Clock Source Select 1 */
#define UCSSEL0_L           (0x0040)    /* USCI 0 Clock Source Select 0 */
#define UCRXEIE_L           (0x0020)    /* RX Error interrupt enable */
#define UCBRKIE_L           (0x0010)    /* Break interrupt enable */
#define UCDORM_L            (0x0008)    /* Dormant (Sleep) Mode */
#define UCTXADDR_L          (0x0004)    /* Send next Data as Address */
#define UCTXBRK_L           (0x0002)    /* Send next Data as Break */
#define UCSWRST_L           (0x0001)    /* USCI Software Reset */

// UCAxCTLW0 UART-Mode Control Bits
#define UCPEN_H             (0x0080)    /* Async. Mode: Parity enable */
#define UCPAR_H             (0x0040)    /* Async. Mode: Parity     0:odd / 1:even */
#define UCMSB_H             (0x0020)    /* Async. Mode: MSB first  0:LSB / 1:MSB */
#define UC7BIT_H            (0x0010)    /* Async. Mode: Data Bits  0:8-bits / 1:7-bits */
#define UCSPB_H             (0x0008)    /* Async. Mode: Stop Bits  0:one / 1: two */
#define UCMODE1_H           (0x0004)    /* Async. Mode: USCI Mode 1 */
#define UCMODE0_H           (0x0002)    /* Async. Mode: USCI Mode 0 */
#define UCSYNC_H            (0x0001)    /* Sync-Mode  0:UART-Mode / 1:SPI-Mode */

// UCxxCTLW0 SPI-Mode Control Bits
#define UCCKPH              (0x8000)    /* Sync. Mode: Clock Phase */
#define UCCKPL              (0x4000)    /* Sync. Mode: Clock Polarity */
#define UCMST               (0x0800)    /* Sync. Mode: Master Select */
//#define res               (0x0020)    /* reserved */
//#define res               (0x0010)    /* reserved */
//#define res               (0x0008)    /* reserved */
//#define res               (0x0004)    /* reserved */
#define UCSTEM             (0x0002)    /* USCI STE Mode */

// UCBxCTLW0 I2C-Mode Control Bits
#define UCA10               (0x8000)    /* 10-bit Address Mode */
#define UCSLA10             (0x4000)    /* 10-bit Slave Address Mode */
#define UCMM                (0x2000)    /* Multi-Master Environment */
//#define res               (0x1000)    /* reserved */
//#define res               (0x0100)    /* reserved */
#define UCTXACK             (0x0020)    /* Transmit ACK */
#define UCTR                (0x0010)    /* Transmit/Receive Select/Flag */
#define UCTXNACK            (0x0008)    /* Transmit NACK */
#define UCTXSTP             (0x0004)    /* Transmit STOP */
#define UCTXSTT             (0x0002)    /* Transmit START */

// UCBxCTLW0 I2C-Mode Control Bits
//#define res               (0x1000)    /* reserved */
//#define res               (0x0100)    /* reserved */
#define UCTXACK_L           (0x0020)    /* Transmit ACK */
#define UCTR_L              (0x0010)    /* Transmit/Receive Select/Flag */
#define UCTXNACK_L          (0x0008)    /* Transmit NACK */
#define UCTXSTP_L           (0x0004)    /* Transmit STOP */
#define UCTXSTT_L           (0x0002)    /* Transmit START */

// UCBxCTLW0 I2C-Mode Control Bits
#define UCA10_H             (0x0080)    /* 10-bit Address Mode */
#define UCSLA10_H           (0x0040)    /* 10-bit Slave Address Mode */
#define UCMM_H              (0x0020)    /* Multi-Master Environment */
//#define res               (0x1000)    /* reserved */
//#define res               (0x0100)    /* reserved */

#define UCMODE_0            (0x0000)    /* Sync. Mode: USCI Mode: 0 */
#define UCMODE_1            (0x0200)    /* Sync. Mode: USCI Mode: 1 */
#define UCMODE_2            (0x0400)    /* Sync. Mode: USCI Mode: 2 */
#define UCMODE_3            (0x0600)    /* Sync. Mode: USCI Mode: 3 */

#define UCSSEL_0            (0x0000)    /* USCI 0 Clock Source: 0 */
#define UCSSEL_1            (0x0040)    /* USCI 0 Clock Source: 1 */
#define UCSSEL_2            (0x0080)    /* USCI 0 Clock Source: 2 */
#define UCSSEL_3            (0x00C0)    /* USCI 0 Clock Source: 3 */
#define UCSSEL__UCLK        (0x0000)    /* USCI 0 Clock Source: UCLK */
#define UCSSEL__ACLK        (0x0040)    /* USCI 0 Clock Source: ACLK */
#define UCSSEL__SMCLK       (0x0080)    /* USCI 0 Clock Source: SMCLK */


// UCAxCTLW1 UART-Mode Control Bits
#define UCGLIT1             (0x0002)    /* USCI Deglitch Time Bit 1 */
#define UCGLIT0             (0x0001)    /* USCI Deglitch Time Bit 0 */

// UCAxCTLW1 UART-Mode Control Bits
#define UCGLIT1_L           (0x0002)    /* USCI Deglitch Time Bit 1 */
#define UCGLIT0_L           (0x0001)    /* USCI Deglitch Time Bit 0 */


// UCBxCTLW1 I2C-Mode Control Bits
#define UCETXINT            (0x0100)    /* USCI Early UCTXIFG0 */
#define UCCLTO1             (0x0080)    /* USCI Clock low timeout Bit: 1 */
#define UCCLTO0             (0x0040)    /* USCI Clock low timeout Bit: 0 */
#define UCSTPNACK           (0x0020)    /* USCI Acknowledge Stop last byte */
#define UCSWACK             (0x0010)    /* USCI Software controlled ACK */
#define UCASTP1             (0x0008)    /* USCI Automatic Stop condition generation Bit: 1 */
#define UCASTP0             (0x0004)    /* USCI Automatic Stop condition generation Bit: 0 */
#define UCGLIT1             (0x0002)    /* USCI Deglitch time Bit: 1 */
#define UCGLIT0             (0x0001)    /* USCI Deglitch time Bit: 0 */

// UCBxCTLW1 I2C-Mode Control Bits
#define UCCLTO1_L           (0x0080)    /* USCI Clock low timeout Bit: 1 */
#define UCCLTO0_L           (0x0040)    /* USCI Clock low timeout Bit: 0 */
#define UCSTPNACK_L         (0x0020)    /* USCI Acknowledge Stop last byte */
#define UCSWACK_L           (0x0010)    /* USCI Software controlled ACK */
#define UCASTP1_L           (0x0008)    /* USCI Automatic Stop condition generation Bit: 1 */
#define UCASTP0_L           (0x0004)    /* USCI Automatic Stop condition generation Bit: 0 */
#define UCGLIT1_L           (0x0002)    /* USCI Deglitch time Bit: 1 */
#define UCGLIT0_L           (0x0001)    /* USCI Deglitch time Bit: 0 */

// UCBxCTLW1 I2C-Mode Control Bits
#define UCETXINT_H          (0x0001)    /* USCI Early UCTXIFG0 */

#define UCGLIT_0            (0x0000)    /* USCI Deglitch time: 0 */
#define UCGLIT_1            (0x0001)    /* USCI Deglitch time: 1 */
#define UCGLIT_2            (0x0002)    /* USCI Deglitch time: 2 */
#define UCGLIT_3            (0x0003)    /* USCI Deglitch time: 3 */

#define UCASTP_0            (0x0000)    /* USCI Automatic Stop condition generation: 0 */
#define UCASTP_1            (0x0004)    /* USCI Automatic Stop condition generation: 1 */
#define UCASTP_2            (0x0008)    /* USCI Automatic Stop condition generation: 2 */
#define UCASTP_3            (0x000C)    /* USCI Automatic Stop condition generation: 3 */

#define UCCLTO_0            (0x0000)    /* USCI Clock low timeout: 0 */
#define UCCLTO_1            (0x0040)    /* USCI Clock low timeout: 1 */
#define UCCLTO_2            (0x0080)    /* USCI Clock low timeout: 2 */
#define UCCLTO_3            (0x00C0)    /* USCI Clock low timeout: 3 */


/* UCAxMCTLW Control Bits */
#define UCBRS7              (0x8000)    /* USCI Second Stage Modulation Select 7 */
#define UCBRS6              (0x4000)    /* USCI Second Stage Modulation Select 6 */
#define UCBRS5              (0x2000)    /* USCI Second Stage Modulation Select 5 */
#define UCBRS4              (0x1000)    /* USCI Second Stage Modulation Select 4 */
#define UCBRS3              (0x0800)    /* USCI Second Stage Modulation Select 3 */
#define UCBRS2              (0x0400)    /* USCI Second Stage Modulation Select 2 */
#define UCBRS1              (0x0200)    /* USCI Second Stage Modulation Select 1 */
#define UCBRS0              (0x0100)    /* USCI Second Stage Modulation Select 0 */
#define UCBRF3              (0x0080)    /* USCI First Stage Modulation Select 3 */
#define UCBRF2              (0x0040)    /* USCI First Stage Modulation Select 2 */
#define UCBRF1              (0x0020)    /* USCI First Stage Modulation Select 1 */
#define UCBRF0              (0x0010)    /* USCI First Stage Modulation Select 0 */
#define UCOS16              (0x0001)    /* USCI 16-times Oversampling enable */

/* UCAxMCTLW Control Bits */
#define UCBRF3_L            (0x0080)    /* USCI First Stage Modulation Select 3 */
#define UCBRF2_L            (0x0040)    /* USCI First Stage Modulation Select 2 */
#define UCBRF1_L            (0x0020)    /* USCI First Stage Modulation Select 1 */
#define UCBRF0_L            (0x0010)    /* USCI First Stage Modulation Select 0 */
#define UCOS16_L            (0x0001)    /* USCI 16-times Oversampling enable */

/* UCAxMCTLW Control Bits */
#define UCBRS7_H            (0x0080)    /* USCI Second Stage Modulation Select 7 */
#define UCBRS6_H            (0x0040)    /* USCI Second Stage Modulation Select 6 */
#define UCBRS5_H            (0x0020)    /* USCI Second Stage Modulation Select 5 */
#define UCBRS4_H            (0x0010)    /* USCI Second Stage Modulation Select 4 */
#define UCBRS3_H            (0x0008)    /* USCI Second Stage Modulation Select 3 */
#define UCBRS2_H            (0x0004)    /* USCI Second Stage Modulation Select 2 */
#define UCBRS1_H            (0x0002)    /* USCI Second Stage Modulation Select 1 */
#define UCBRS0_H            (0x0001)    /* USCI Second Stage Modulation Select 0 */

#define UCBRF_0             (0x00)    /* USCI First Stage Modulation: 0 */
#define UCBRF_1             (0x10)    /* USCI First Stage Modulation: 1 */
#define UCBRF_2             (0x20)    /* USCI First Stage Modulation: 2 */
#define UCBRF_3             (0x30)    /* USCI First Stage Modulation: 3 */
#define UCBRF_4             (0x40)    /* USCI First Stage Modulation: 4 */
#define UCBRF_5             (0x50)    /* USCI First Stage Modulation: 5 */
#define UCBRF_6             (0x60)    /* USCI First Stage Modulation: 6 */
#define UCBRF_7             (0x70)    /* USCI First Stage Modulation: 7 */
#define UCBRF_8             (0x80)    /* USCI First Stage Modulation: 8 */
#define UCBRF_9             (0x90)    /* USCI First Stage Modulation: 9 */
#define UCBRF_10            (0xA0)    /* USCI First Stage Modulation: A */
#define UCBRF_11            (0xB0)    /* USCI First Stage Modulation: B */
#define UCBRF_12            (0xC0)    /* USCI First Stage Modulation: C */
#define UCBRF_13            (0xD0)    /* USCI First Stage Modulation: D */
#define UCBRF_14            (0xE0)    /* USCI First Stage Modulation: E */
#define UCBRF_15            (0xF0)    /* USCI First Stage Modulation: F */


/* UCAxSTATW Control Bits */
#define UCLISTEN            (0x0080)  /* USCI Listen mode */
#define UCFE                (0x0040)  /* USCI Frame Error Flag */
#define UCOE                (0x0020)  /* USCI Overrun Error Flag */
#define UCPE                (0x0010)  /* USCI Parity Error Flag */
#define UCBRK               (0x0008)  /* USCI Break received */
#define UCRXERR             (0x0004)  /* USCI RX Error Flag */
#define UCADDR              (0x0002)  /* USCI Address received Flag */
#define UCBUSY              (0x0001)  /* USCI Busy Flag */
#define UCIDLE              (0x0002)  /* USCI Idle line detected Flag */


/* UCBxSTATW I2C Control Bits */
#define UCBCNT7             (0x8000)  /* USCI Byte Counter Bit 7 */
#define UCBCNT6             (0x4000)  /* USCI Byte Counter Bit 6 */
#define UCBCNT5             (0x2000)  /* USCI Byte Counter Bit 5 */
#define UCBCNT4             (0x1000)  /* USCI Byte Counter Bit 4 */
#define UCBCNT3             (0x0800)  /* USCI Byte Counter Bit 3 */
#define UCBCNT2             (0x0400)  /* USCI Byte Counter Bit 2 */
#define UCBCNT1             (0x0200)  /* USCI Byte Counter Bit 1 */
#define UCBCNT0             (0x0100)  /* USCI Byte Counter Bit 0 */
#define UCSCLLOW            (0x0040)  /* SCL low */
#define UCGC                (0x0020)  /* General Call address received Flag */
#define UCBBUSY             (0x0010)  /* Bus Busy Flag */

/* UCBxTBCNT I2C Control Bits */
#define UCTBCNT7            (0x0080)  /* USCI Byte Counter Bit 7 */
#define UCTBCNT6            (0x0040)  /* USCI Byte Counter Bit 6 */
#define UCTBCNT5            (0x0020)  /* USCI Byte Counter Bit 5 */
#define UCTBCNT4            (0x0010)  /* USCI Byte Counter Bit 4 */
#define UCTBCNT3            (0x0008)  /* USCI Byte Counter Bit 3 */
#define UCTBCNT2            (0x0004)  /* USCI Byte Counter Bit 2 */
#define UCTBCNT1            (0x0002)  /* USCI Byte Counter Bit 1 */
#define UCTBCNT0            (0x0001)  /* USCI Byte Counter Bit 0 */

/* UCAxIRCTL Control Bits */
#define UCIRRXFL5           (0x8000)  /* IRDA Receive Filter Length 5 */
#define UCIRRXFL4           (0x4000)  /* IRDA Receive Filter Length 4 */
#define UCIRRXFL3           (0x2000)  /* IRDA Receive Filter Length 3 */
#define UCIRRXFL2           (0x1000)  /* IRDA Receive Filter Length 2 */
#define UCIRRXFL1           (0x0800)  /* IRDA Receive Filter Length 1 */
#define UCIRRXFL0           (0x0400)  /* IRDA Receive Filter Length 0 */
#define UCIRRXPL            (0x0200)  /* IRDA Receive Input Polarity */
#define UCIRRXFE            (0x0100)  /* IRDA Receive Filter enable */
#define UCIRTXPL5           (0x0080)  /* IRDA Transmit Pulse Length 5 */
#define UCIRTXPL4           (0x0040)  /* IRDA Transmit Pulse Length 4 */
#define UCIRTXPL3           (0x0020)  /* IRDA Transmit Pulse Length 3 */
#define UCIRTXPL2           (0x0010)  /* IRDA Transmit Pulse Length 2 */
#define UCIRTXPL1           (0x0008)  /* IRDA Transmit Pulse Length 1 */
#define UCIRTXPL0           (0x0004)  /* IRDA Transmit Pulse Length 0 */
#define UCIRTXCLK           (0x0002)  /* IRDA Transmit Pulse Clock Select */
#define UCIREN              (0x0001)  /* IRDA Encoder/Decoder enable */

/* UCAxIRCTL Control Bits */
#define UCIRTXPL5_L         (0x0080)  /* IRDA Transmit Pulse Length 5 */
#define UCIRTXPL4_L         (0x0040)  /* IRDA Transmit Pulse Length 4 */
#define UCIRTXPL3_L         (0x0020)  /* IRDA Transmit Pulse Length 3 */
#define UCIRTXPL2_L         (0x0010)  /* IRDA Transmit Pulse Length 2 */
#define UCIRTXPL1_L         (0x0008)  /* IRDA Transmit Pulse Length 1 */
#define UCIRTXPL0_L         (0x0004)  /* IRDA Transmit Pulse Length 0 */
#define UCIRTXCLK_L         (0x0002)  /* IRDA Transmit Pulse Clock Select */
#define UCIREN_L            (0x0001)  /* IRDA Encoder/Decoder enable */

/* UCAxIRCTL Control Bits */
#define UCIRRXFL5_H         (0x0080)  /* IRDA Receive Filter Length 5 */
#define UCIRRXFL4_H         (0x0040)  /* IRDA Receive Filter Length 4 */
#define UCIRRXFL3_H         (0x0020)  /* IRDA Receive Filter Length 3 */
#define UCIRRXFL2_H         (0x0010)  /* IRDA Receive Filter Length 2 */
#define UCIRRXFL1_H         (0x0008)  /* IRDA Receive Filter Length 1 */
#define UCIRRXFL0_H         (0x0004)  /* IRDA Receive Filter Length 0 */
#define UCIRRXPL_H          (0x0002)  /* IRDA Receive Input Polarity */
#define UCIRRXFE_H          (0x0001)  /* IRDA Receive Filter enable */


/* UCAxABCTL Control Bits */
//#define res               (0x80)    /* reserved */
//#define res               (0x40)    /* reserved */
#define UCDELIM1            (0x20)    /* Break Sync Delimiter 1 */
#define UCDELIM0            (0x10)    /* Break Sync Delimiter 0 */
#define UCSTOE              (0x08)    /* Sync-Field Timeout error */
#define UCBTOE              (0x04)    /* Break Timeout error */
//#define res               (0x02)    /* reserved */
#define UCABDEN             (0x01)    /* Auto Baud Rate detect enable */

/* UCBxI2COA0 Control Bits */
#define UCGCEN              (0x8000)  /* I2C General Call enable */
#define UCOAEN              (0x0400)  /* I2C Own Address enable */
#define UCOA9               (0x0200)  /* I2C Own Address Bit 9 */
#define UCOA8               (0x0100)  /* I2C Own Address Bit 8 */
#define UCOA7               (0x0080)  /* I2C Own Address Bit 7 */
#define UCOA6               (0x0040)  /* I2C Own Address Bit 6 */
#define UCOA5               (0x0020)  /* I2C Own Address Bit 5 */
#define UCOA4               (0x0010)  /* I2C Own Address Bit 4 */
#define UCOA3               (0x0008)  /* I2C Own Address Bit 3 */
#define UCOA2               (0x0004)  /* I2C Own Address Bit 2 */
#define UCOA1               (0x0002)  /* I2C Own Address Bit 1 */
#define UCOA0               (0x0001)  /* I2C Own Address Bit 0 */

/* UCBxI2COA0 Control Bits */
#define UCOA7_L             (0x0080)  /* I2C Own Address Bit 7 */
#define UCOA6_L             (0x0040)  /* I2C Own Address Bit 6 */
#define UCOA5_L             (0x0020)  /* I2C Own Address Bit 5 */
#define UCOA4_L             (0x0010)  /* I2C Own Address Bit 4 */
#define UCOA3_L             (0x0008)  /* I2C Own Address Bit 3 */
#define UCOA2_L             (0x0004)  /* I2C Own Address Bit 2 */
#define UCOA1_L             (0x0002)  /* I2C Own Address Bit 1 */
#define UCOA0_L             (0x0001)  /* I2C Own Address Bit 0 */

/* UCBxI2COA0 Control Bits */
#define UCGCEN_H            (0x0080)  /* I2C General Call enable */
#define UCOAEN_H            (0x0004)  /* I2C Own Address enable */
#define UCOA9_H             (0x0002)  /* I2C Own Address Bit 9 */
#define UCOA8_H             (0x0001)  /* I2C Own Address Bit 8 */

/* UCBxI2COAx Control Bits */
#define UCOAEN              (0x0400)  /* I2C Own Address enable */
#define UCOA9               (0x0200)  /* I2C Own Address Bit 9 */
#define UCOA8               (0x0100)  /* I2C Own Address Bit 8 */
#define UCOA7               (0x0080)  /* I2C Own Address Bit 7 */
#define UCOA6               (0x0040)  /* I2C Own Address Bit 6 */
#define UCOA5               (0x0020)  /* I2C Own Address Bit 5 */
#define UCOA4               (0x0010)  /* I2C Own Address Bit 4 */
#define UCOA3               (0x0008)  /* I2C Own Address Bit 3 */
#define UCOA2               (0x0004)  /* I2C Own Address Bit 2 */
#define UCOA1               (0x0002)  /* I2C Own Address Bit 1 */
#define UCOA0               (0x0001)  /* I2C Own Address Bit 0 */

/* UCBxI2COAx Control Bits */
#define UCOA7_L             (0x0080)  /* I2C Own Address Bit 7 */
#define UCOA6_L             (0x0040)  /* I2C Own Address Bit 6 */
#define UCOA5_L             (0x0020)  /* I2C Own Address Bit 5 */
#define UCOA4_L             (0x0010)  /* I2C Own Address Bit 4 */
#define UCOA3_L             (0x0008)  /* I2C Own Address Bit 3 */
#define UCOA2_L             (0x0004)  /* I2C Own Address Bit 2 */
#define UCOA1_L             (0x0002)  /* I2C Own Address Bit 1 */
#define UCOA0_L             (0x0001)  /* I2C Own Address Bit 0 */

/* UCBxI2COAx Control Bits */
#define UCOAEN_H            (0x0004)  /* I2C Own Address enable */
#define UCOA9_H             (0x0002)  /* I2C Own Address Bit 9 */
#define UCOA8_H             (0x0001)  /* I2C Own Address Bit 8 */

/* UCBxADDRX Control Bits */
#define UCADDRX9            (0x0200)  /* I2C Receive Address Bit 9 */
#define UCADDRX8            (0x0100)  /* I2C Receive Address Bit 8 */
#define UCADDRX7            (0x0080)  /* I2C Receive Address Bit 7 */
#define UCADDRX6            (0x0040)  /* I2C Receive Address Bit 6 */
#define UCADDRX5            (0x0020)  /* I2C Receive Address Bit 5 */
#define UCADDRX4            (0x0010)  /* I2C Receive Address Bit 4 */
#define UCADDRX3            (0x0008)  /* I2C Receive Address Bit 3 */
#define UCADDRX2            (0x0004)  /* I2C Receive Address Bit 2 */
#define UCADDRX1            (0x0002)  /* I2C Receive Address Bit 1 */
#define UCADDRX0            (0x0001)  /* I2C Receive Address Bit 0 */

/* UCBxADDRX Control Bits */
#define UCADDRX7_L          (0x0080)  /* I2C Receive Address Bit 7 */
#define UCADDRX6_L          (0x0040)  /* I2C Receive Address Bit 6 */
#define UCADDRX5_L          (0x0020)  /* I2C Receive Address Bit 5 */
#define UCADDRX4_L          (0x0010)  /* I2C Receive Address Bit 4 */
#define UCADDRX3_L          (0x0008)  /* I2C Receive Address Bit 3 */
#define UCADDRX2_L          (0x0004)  /* I2C Receive Address Bit 2 */
#define UCADDRX1_L          (0x0002)  /* I2C Receive Address Bit 1 */
#define UCADDRX0_L          (0x0001)  /* I2C Receive Address Bit 0 */

/* UCBxADDRX Control Bits */
#define UCADDRX9_H          (0x0002)  /* I2C Receive Address Bit 9 */
#define UCADDRX8_H          (0x0001)  /* I2C Receive Address Bit 8 */

/* UCBxADDMASK Control Bits */
#define UCADDMASK9            (0x0200)  /* I2C Address Mask Bit 9 */
#define UCADDMASK8            (0x0100)  /* I2C Address Mask Bit 8 */
#define UCADDMASK7            (0x0080)  /* I2C Address Mask Bit 7 */
#define UCADDMASK6            (0x0040)  /* I2C Address Mask Bit 6 */
#define UCADDMASK5            (0x0020)  /* I2C Address Mask Bit 5 */
#define UCADDMASK4            (0x0010)  /* I2C Address Mask Bit 4 */
#define UCADDMASK3            (0x0008)  /* I2C Address Mask Bit 3 */
#define UCADDMASK2            (0x0004)  /* I2C Address Mask Bit 2 */
#define UCADDMASK1            (0x0002)  /* I2C Address Mask Bit 1 */
#define UCADDMASK0            (0x0001)  /* I2C Address Mask Bit 0 */

/* UCBxADDMASK Control Bits */
#define UCADDMASK7_L        (0x0080)  /* I2C Address Mask Bit 7 */
#define UCADDMASK6_L        (0x0040)  /* I2C Address Mask Bit 6 */
#define UCADDMASK5_L        (0x0020)  /* I2C Address Mask Bit 5 */
#define UCADDMASK4_L        (0x0010)  /* I2C Address Mask Bit 4 */
#define UCADDMASK3_L        (0x0008)  /* I2C Address Mask Bit 3 */
#define UCADDMASK2_L        (0x0004)  /* I2C Address Mask Bit 2 */
#define UCADDMASK1_L        (0x0002)  /* I2C Address Mask Bit 1 */
#define UCADDMASK0_L        (0x0001)  /* I2C Address Mask Bit 0 */

/* UCBxADDMASK Control Bits */
#define UCADDMASK9_H        (0x0002)  /* I2C Address Mask Bit 9 */
#define UCADDMASK8_H        (0x0001)  /* I2C Address Mask Bit 8 */

/* UCBxI2CSA Control Bits */
#define UCSA9               (0x0200)  /* I2C Slave Address Bit 9 */
#define UCSA8               (0x0100)  /* I2C Slave Address Bit 8 */
#define UCSA7               (0x0080)  /* I2C Slave Address Bit 7 */
#define UCSA6               (0x0040)  /* I2C Slave Address Bit 6 */
#define UCSA5               (0x0020)  /* I2C Slave Address Bit 5 */
#define UCSA4               (0x0010)  /* I2C Slave Address Bit 4 */
#define UCSA3               (0x0008)  /* I2C Slave Address Bit 3 */
#define UCSA2               (0x0004)  /* I2C Slave Address Bit 2 */
#define UCSA1               (0x0002)  /* I2C Slave Address Bit 1 */
#define UCSA0               (0x0001)  /* I2C Slave Address Bit 0 */

/* UCBxI2CSA Control Bits */
#define UCSA7_L             (0x0080)  /* I2C Slave Address Bit 7 */
#define UCSA6_L             (0x0040)  /* I2C Slave Address Bit 6 */
#define UCSA5_L             (0x0020)  /* I2C Slave Address Bit 5 */
#define UCSA4_L             (0x0010)  /* I2C Slave Address Bit 4 */
#define UCSA3_L             (0x0008)  /* I2C Slave Address Bit 3 */
#define UCSA2_L             (0x0004)  /* I2C Slave Address Bit 2 */
#define UCSA1_L             (0x0002)  /* I2C Slave Address Bit 1 */
#define UCSA0_L             (0x0001)  /* I2C Slave Address Bit 0 */

/* UCBxI2CSA Control Bits */
#define UCSA9_H             (0x0002)  /* I2C Slave Address Bit 9 */
#define UCSA8_H             (0x0001)  /* I2C Slave Address Bit 8 */

/* UCAxIE UART Control Bits */
#define UCTXCPTIE           (0x0008)  /* UART Transmit Complete Interrupt Enable */
#define UCSTTIE             (0x0004)  /* UART Start Bit Interrupt Enalble */
#define UCTXIE              (0x0002)  /* UART Transmit Interrupt Enable */
#define UCRXIE              (0x0001)  /* UART Receive Interrupt Enable */

/* UCAxIE/UCBxIE SPI Control Bits */

/* UCBxIE I2C Control Bits */
#define UCBIT9IE            (0x4000)  /* I2C Bit 9 Position Interrupt Enable 3 */
#define UCTXIE3             (0x2000)  /* I2C Transmit Interrupt Enable 3 */
#define UCRXIE3             (0x1000)  /* I2C Receive Interrupt Enable 3 */
#define UCTXIE2             (0x0800)  /* I2C Transmit Interrupt Enable 2 */
#define UCRXIE2             (0x0400)  /* I2C Receive Interrupt Enable 2 */
#define UCTXIE1             (0x0200)  /* I2C Transmit Interrupt Enable 1 */
#define UCRXIE1             (0x0100)  /* I2C Receive Interrupt Enable 1 */
#define UCCLTOIE            (0x0080)  /* I2C Clock Low Timeout interrupt enable */
#define UCBCNTIE            (0x0040)  /* I2C Automatic stop assertion interrupt enable */
#define UCNACKIE            (0x0020)  /* I2C NACK Condition interrupt enable */
#define UCALIE              (0x0010)  /* I2C Arbitration Lost interrupt enable */
#define UCSTPIE             (0x0008)  /* I2C STOP Condition interrupt enable */
#define UCSTTIE             (0x0004)  /* I2C START Condition interrupt enable */
#define UCTXIE0             (0x0002)  /* I2C Transmit Interrupt Enable 0 */
#define UCRXIE0             (0x0001)  /* I2C Receive Interrupt Enable 0 */

/* UCAxIFG UART Control Bits */
#define UCTXCPTIFG          (0x0008)  /* UART Transmit Complete Interrupt Flag */
#define UCSTTIFG            (0x0004)  /* UART Start Bit Interrupt Flag */
#define UCTXIFG             (0x0002)  /* UART Transmit Interrupt Flag */
#define UCRXIFG             (0x0001)  /* UART Receive Interrupt Flag */

/* UCAxIFG/UCBxIFG SPI Control Bits */
#define UCTXIFG             (0x0002)  /* SPI Transmit Interrupt Flag */
#define UCRXIFG             (0x0001)  /* SPI Receive Interrupt Flag */

/* UCBxIFG Control Bits */
#define UCBIT9IFG           (0x4000)  /* I2C Bit 9 Possition Interrupt Flag 3 */
#define UCTXIFG3            (0x2000)  /* I2C Transmit Interrupt Flag 3 */
#define UCRXIFG3            (0x1000)  /* I2C Receive Interrupt Flag 3 */
#define UCTXIFG2            (0x0800)  /* I2C Transmit Interrupt Flag 2 */
#define UCRXIFG2            (0x0400)  /* I2C Receive Interrupt Flag 2 */
#define UCTXIFG1            (0x0200)  /* I2C Transmit Interrupt Flag 1 */
#define UCRXIFG1            (0x0100)  /* I2C Receive Interrupt Flag 1 */
#define UCCLTOIFG           (0x0080)  /* I2C Clock low Timeout interrupt Flag */
#define UCBCNTIFG           (0x0040)  /* I2C Byte counter interrupt flag */
#define UCNACKIFG           (0x0020)  /* I2C NACK Condition interrupt Flag */
#define UCALIFG             (0x0010)  /* I2C Arbitration Lost interrupt Flag */
#define UCSTPIFG            (0x0008)  /* I2C STOP Condition interrupt Flag */
#define UCSTTIFG            (0x0004)  /* I2C START Condition interrupt Flag */
#define UCTXIFG0            (0x0002)  /* I2C Transmit Interrupt Flag 0 */
#define UCRXIFG0            (0x0001)  /* I2C Receive Interrupt Flag 0 */

/* USCI UART Definitions */
#define USCI_NONE            (0x0000)   /* No Interrupt pending */
#define USCI_UART_UCRXIFG    (0x0002)   /* USCI UCRXIFG */
#define USCI_UART_UCTXIFG    (0x0004)   /* USCI UCTXIFG */
#define USCI_UART_UCSTTIFG   (0x0006)   /* USCI UCSTTIFG */
#define USCI_UART_UCTXCPTIFG (0x0008)   /* USCI UCTXCPTIFG */

/* USCI SPI Definitions */
#define USCI_SPI_UCRXIFG    (0x0002)    /* USCI UCRXIFG */
#define USCI_SPI_UCTXIFG    (0x0004)    /* USCI UCTXIFG */

/* USCI I2C Definitions */
#define USCI_I2C_UCALIFG    (0x0002)    /* USCI I2C Mode: UCALIFG */
#define USCI_I2C_UCNACKIFG  (0x0004)    /* USCI I2C Mode: UCNACKIFG */
#define USCI_I2C_UCSTTIFG   (0x0006)    /* USCI I2C Mode: UCSTTIFG*/
#define USCI_I2C_UCSTPIFG   (0x0008)    /* USCI I2C Mode: UCSTPIFG*/
#define USCI_I2C_UCRXIFG3   (0x000A)    /* USCI I2C Mode: UCRXIFG3 */
#define USCI_I2C_UCTXIFG3   (0x000C)    /* USCI I2C Mode: UCTXIFG3 */
#define USCI_I2C_UCRXIFG2   (0x000E)    /* USCI I2C Mode: UCRXIFG2 */
#define USCI_I2C_UCTXIFG2   (0x0010)    /* USCI I2C Mode: UCTXIFG2 */
#define USCI_I2C_UCRXIFG1   (0x0012)    /* USCI I2C Mode: UCRXIFG1 */
#define USCI_I2C_UCTXIFG1   (0x0014)    /* USCI I2C Mode: UCTXIFG1 */
#define USCI_I2C_UCRXIFG0   (0x0016)    /* USCI I2C Mode: UCRXIFG0 */
#define USCI_I2C_UCTXIFG0   (0x0018)    /* USCI I2C Mode: UCTXIFG0 */
#define USCI_I2C_UCBCNTIFG  (0x001A)    /* USCI I2C Mode: UCBCNTIFG */
#define USCI_I2C_UCCLTOIFG  (0x001C)    /* USCI I2C Mode: UCCLTOIFG */
#define USCI_I2C_UCBIT9IFG  (0x001E)    /* USCI I2C Mode: UCBIT9IFG */















/************************************************************
* WATCHDOG TIMER A
************************************************************/
#define __MSP430_HAS_WDT_A__          /* Definition to show that Module is available */
#define __MSP430_BASEADDRESS_WDT_A__ 0x0150
#define WDT_A_BASE __MSP430_BASEADDRESS_WDT_A__

#define WDTCTL_               0x015C    /* Watchdog Timer Control */
sfrb(WDTCTL_L , WDTCTL_);
sfrb(WDTCTL_H , WDTCTL_+1);
sfrw(WDTCTL, WDTCTL_);
/* The bit names have been prefixed with "WDT" */
/* WDTCTL Control Bits */
#define WDTIS0              (0x0001)  /* WDT - Timer Interval Select 0 */
#define WDTIS1              (0x0002)  /* WDT - Timer Interval Select 1 */
#define WDTIS2              (0x0004)  /* WDT - Timer Interval Select 2 */
#define WDTCNTCL            (0x0008)  /* WDT - Timer Clear */
#define WDTTMSEL            (0x0010)  /* WDT - Timer Mode Select */
#define WDTSSEL0            (0x0020)  /* WDT - Timer Clock Source Select 0 */
#define WDTSSEL1            (0x0040)  /* WDT - Timer Clock Source Select 1 */
#define WDTHOLD             (0x0080)  /* WDT - Timer hold */

/* WDTCTL Control Bits */
#define WDTIS0_L            (0x0001)  /* WDT - Timer Interval Select 0 */
#define WDTIS1_L            (0x0002)  /* WDT - Timer Interval Select 1 */
#define WDTIS2_L            (0x0004)  /* WDT - Timer Interval Select 2 */
#define WDTCNTCL_L          (0x0008)  /* WDT - Timer Clear */
#define WDTTMSEL_L          (0x0010)  /* WDT - Timer Mode Select */
#define WDTSSEL0_L          (0x0020)  /* WDT - Timer Clock Source Select 0 */
#define WDTSSEL1_L          (0x0040)  /* WDT - Timer Clock Source Select 1 */
#define WDTHOLD_L           (0x0080)  /* WDT - Timer hold */


#define WDTPW               (0x5A00)

#define WDTIS_0           (0x0000)  /* WDT - Timer Interval Select: /2G */
#define WDTIS_1           (0x0001)  /* WDT - Timer Interval Select: /128M */
#define WDTIS_2           (0x0002)  /* WDT - Timer Interval Select: /8192k */
#define WDTIS_3           (0x0003)  /* WDT - Timer Interval Select: /512k */
#define WDTIS_4           (0x0004)  /* WDT - Timer Interval Select: /32k */
#define WDTIS_5           (0x0005)  /* WDT - Timer Interval Select: /8192 */
#define WDTIS_6           (0x0006)  /* WDT - Timer Interval Select: /512 */
#define WDTIS_7           (0x0007)  /* WDT - Timer Interval Select: /64 */
#define WDTIS__2G         (0x0000)  /* WDT - Timer Interval Select: /2G */
#define WDTIS__128M       (0x0001)  /* WDT - Timer Interval Select: /128M */
#define WDTIS__8192K      (0x0002)  /* WDT - Timer Interval Select: /8192k */
#define WDTIS__512K       (0x0003)  /* WDT - Timer Interval Select: /512k */
#define WDTIS__32K        (0x0004)  /* WDT - Timer Interval Select: /32k */
#define WDTIS__8192       (0x0005)  /* WDT - Timer Interval Select: /8192 */
#define WDTIS__512        (0x0006)  /* WDT - Timer Interval Select: /512 */
#define WDTIS__64         (0x0007)  /* WDT - Timer Interval Select: /64 */

#define WDTSSEL_0         (0x0000)  /* WDT - Timer Clock Source Select: SMCLK */
#define WDTSSEL_1         (0x0020)  /* WDT - Timer Clock Source Select: ACLK */
#define WDTSSEL_2         (0x0040)  /* WDT - Timer Clock Source Select: VLO_CLK */
#define WDTSSEL_3         (0x0060)  /* WDT - Timer Clock Source Select: reserved */
#define WDTSSEL__SMCLK    (0x0000)  /* WDT - Timer Clock Source Select: SMCLK */
#define WDTSSEL__ACLK     (0x0020)  /* WDT - Timer Clock Source Select: ACLK */
#define WDTSSEL__VLO      (0x0040)  /* WDT - Timer Clock Source Select: VLO_CLK */


/* WDT-interval times [1ms] coded with Bits 0-2 */
/* WDT is clocked by fSMCLK (assumed 1MHz) */
#define WDT_MDLY_32         (WDTPW+WDTTMSEL+WDTCNTCL+WDTIS2)                         /* 32ms interval (default) */
#define WDT_MDLY_8          (WDTPW+WDTTMSEL+WDTCNTCL+WDTIS2+WDTIS0)                  /* 8ms     " */
#define WDT_MDLY_0_5        (WDTPW+WDTTMSEL+WDTCNTCL+WDTIS2+WDTIS1)                  /* 0.5ms   " */
#define WDT_MDLY_0_064      (WDTPW+WDTTMSEL+WDTCNTCL+WDTIS2+WDTIS1+WDTIS0)           /* 0.064ms " */
/* WDT is clocked by fACLK (assumed 32KHz) */
#define WDT_ADLY_1000       (WDTPW+WDTTMSEL+WDTCNTCL+WDTIS2+WDTSSEL0)                /* 1000ms  " */
#define WDT_ADLY_250        (WDTPW+WDTTMSEL+WDTCNTCL+WDTIS2+WDTSSEL0+WDTIS0)         /* 250ms   " */
#define WDT_ADLY_16         (WDTPW+WDTTMSEL+WDTCNTCL+WDTIS2+WDTSSEL0+WDTIS1)         /* 16ms    " */
#define WDT_ADLY_1_9        (WDTPW+WDTTMSEL+WDTCNTCL+WDTIS2+WDTSSEL0+WDTIS1+WDTIS0)  /* 1.9ms   " */
/* Watchdog mode -> reset after expired time */
/* WDT is clocked by fSMCLK (assumed 1MHz) */
#define WDT_MRST_32         (WDTPW+WDTCNTCL+WDTIS2)                                  /* 32ms interval (default) */
#define WDT_MRST_8          (WDTPW+WDTCNTCL+WDTIS2+WDTIS0)                           /* 8ms     " */
#define WDT_MRST_0_5        (WDTPW+WDTCNTCL+WDTIS2+WDTIS1)                           /* 0.5ms   " */
#define WDT_MRST_0_064      (WDTPW+WDTCNTCL+WDTIS2+WDTIS1+WDTIS0)                    /* 0.064ms " */
/* WDT is clocked by fACLK (assumed 32KHz) */
#define WDT_ARST_1000       (WDTPW+WDTCNTCL+WDTSSEL0+WDTIS2)                         /* 1000ms  " */
#define WDT_ARST_250        (WDTPW+WDTCNTCL+WDTSSEL0+WDTIS2+WDTIS0)                  /* 250ms   " */
#define WDT_ARST_16         (WDTPW+WDTCNTCL+WDTSSEL0+WDTIS2+WDTIS1)                  /* 16ms    " */
#define WDT_ARST_1_9        (WDTPW+WDTCNTCL+WDTSSEL0+WDTIS2+WDTIS1+WDTIS0)           /* 1.9ms   " */


/************************************************************
* End of Modules
************************************************************/
#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* #ifndef __MSP430FR5969 */

