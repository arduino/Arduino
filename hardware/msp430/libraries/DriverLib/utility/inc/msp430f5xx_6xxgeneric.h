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
* MSP430F5XX_F6XXGENERIC device.
*
* Texas Instruments, Version 1.0
*
* Rev. 1.0, Setup
*
*
********************************************************************/

#ifndef __msp430F5XX_F6XXGENERIC
#define __msp430F5XX_F6XXGENERIC

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

#if defined(__MSP430_HAS_T0A2__) || defined(__MSP430_HAS_T1A2__) || defined(__MSP430_HAS_T2A2__) || defined(__MSP430_HAS_T3A2__) \
 || defined(__MSP430_HAS_T0A3__) || defined(__MSP430_HAS_T1A3__) || defined(__MSP430_HAS_T2A3__) || defined(__MSP430_HAS_T3A3__) \
 || defined(__MSP430_HAS_T0A5__) || defined(__MSP430_HAS_T1A5__) || defined(__MSP430_HAS_T2A5__) || defined(__MSP430_HAS_T3A5__) \
 || defined(__MSP430_HAS_T0A7__) || defined(__MSP430_HAS_T1A7__) || defined(__MSP430_HAS_T2A7__) || defined(__MSP430_HAS_T3A7__)
  #define __MSP430_HAS_TxA7__
#endif
#if defined(__MSP430_HAS_T0B3__) || defined(__MSP430_HAS_T0B5__) || defined(__MSP430_HAS_T0B7__) \
 || defined(__MSP430_HAS_T1B3__) || defined(__MSP430_HAS_T1B5__) || defined(__MSP430_HAS_T1B7__)
  #define __MSP430_HAS_TxB7__
#endif
#if defined(__MSP430_HAS_T0D3__) || defined(__MSP430_HAS_T0D5__) || defined(__MSP430_HAS_T0D7__) \
 || defined(__MSP430_HAS_T1D3__) || defined(__MSP430_HAS_T1D5__) || defined(__MSP430_HAS_T1D7__)
  #define __MSP430_HAS_TxD7__
#endif
#if defined(__MSP430_HAS_USCI_A0__) || defined(__MSP430_HAS_USCI_A1__) || defined(__MSP430_HAS_USCI_A2__) || defined(__MSP430_HAS_USCI_A3__)
  #define __MSP430_HAS_USCI_Ax__
#endif
#if defined(__MSP430_HAS_USCI_B0__) || defined(__MSP430_HAS_USCI_B1__) || defined(__MSP430_HAS_USCI_B2__) || defined(__MSP430_HAS_USCI_B3__)
  #define __MSP430_HAS_USCI_Bx__
#endif
#if defined(__MSP430_HAS_EUSCI_A0__) || defined(__MSP430_HAS_EUSCI_A1__) || defined(__MSP430_HAS_EUSCI_A2__) || defined(__MSP430_HAS_EUSCI_A3__)
  #define __MSP430_HAS_EUSCI_Ax__
#endif
#if defined(__MSP430_HAS_EUSCI_B0__) || defined(__MSP430_HAS_EUSCI_B1__) || defined(__MSP430_HAS_EUSCI_B2__) || defined(__MSP430_HAS_EUSCI_B3__)
  #define __MSP430_HAS_EUSCI_Bx__
#endif
#ifdef __MSP430_HAS_EUSCI_B0__
  #define __MSP430_HAS_EUSCI_Bx__
#endif

/************************************************************
* ADC10_A
************************************************************/
#ifdef  __MSP430_HAS_ADC10_A__        /* Definition to show that Module is available */

#define OFS_ADC10CTL0         (0x0000)  /* ADC10 Control 0 */
#define OFS_ADC10CTL0_L        OFS_ADC10CTL0
#define OFS_ADC10CTL0_H        OFS_ADC10CTL0+1
#define OFS_ADC10CTL1         (0x0002)  /* ADC10 Control 1 */
#define OFS_ADC10CTL1_L        OFS_ADC10CTL1
#define OFS_ADC10CTL1_H        OFS_ADC10CTL1+1
#define OFS_ADC10CTL2         (0x0004)  /* ADC10 Control 2 */
#define OFS_ADC10CTL2_L        OFS_ADC10CTL2
#define OFS_ADC10CTL2_H        OFS_ADC10CTL2+1
#define OFS_ADC10LO           (0x0006)  /* ADC10 Window Comparator High Threshold */
#define OFS_ADC10LO_L          OFS_ADC10LO
#define OFS_ADC10LO_H          OFS_ADC10LO+1
#define OFS_ADC10HI           (0x0008)  /* ADC10 Window Comparator High Threshold */
#define OFS_ADC10HI_L          OFS_ADC10HI
#define OFS_ADC10HI_H          OFS_ADC10HI+1
#define OFS_ADC10MCTL0        (0x000A)  /* ADC10 Memory Control 0 */
#define OFS_ADC10MCTL0_L       OFS_ADC10MCTL0
#define OFS_ADC10MCTL0_H       OFS_ADC10MCTL0+1
#define OFS_ADC10MEM0         (0x0012)  /* ADC10 Conversion Memory 0 */
#define OFS_ADC10MEM0_L        OFS_ADC10MEM0
#define OFS_ADC10MEM0_H        OFS_ADC10MEM0+1
#define OFS_ADC10IE           (0x001A)  /* ADC10 Interrupt Enable */
#define OFS_ADC10IE_L          OFS_ADC10IE
#define OFS_ADC10IE_H          OFS_ADC10IE+1
#define OFS_ADC10IFG          (0x001C)  /* ADC10 Interrupt Flag */
#define OFS_ADC10IFG_L         OFS_ADC10IFG
#define OFS_ADC10IFG_H         OFS_ADC10IFG+1
#define OFS_ADC10IV           (0x001E)  /* ADC10 Interrupt Vector Word */
#define OFS_ADC10IV_L          OFS_ADC10IV
#define OFS_ADC10IV_H          OFS_ADC10IV+1

/* ADC10CTL0 Control Bits */
#define ADC10SC             (0x0001)  /* ADC10 Start Conversion */
#define ADC10ENC            (0x0002)  /* ADC10 Enable Conversion */
#define ADC10ON             (0x0010)  /* ADC10 On/enable */
#define ADC10MSC            (0x0080)  /* ADC10 Multiple SampleConversion */
#define ADC10SHT0           (0x0100)  /* ADC10 Sample Hold Select Bit: 0 */
#define ADC10SHT1           (0x0200)  /* ADC10 Sample Hold Select Bit: 1 */
#define ADC10SHT2           (0x0400)  /* ADC10 Sample Hold Select Bit: 2 */
#define ADC10SHT3           (0x0800)  /* ADC10 Sample Hold Select Bit: 3 */

/* ADC10CTL0 Control Bits */
#define ADC10SC_L           (0x0001)  /* ADC10 Start Conversion */
#define ADC10ENC_L          (0x0002)  /* ADC10 Enable Conversion */
#define ADC10ON_L           (0x0010)  /* ADC10 On/enable */
#define ADC10MSC_L          (0x0080)  /* ADC10 Multiple SampleConversion */

/* ADC10CTL0 Control Bits */
#define ADC10SHT0_H         (0x0001)  /* ADC10 Sample Hold Select Bit: 0 */
#define ADC10SHT1_H         (0x0002)  /* ADC10 Sample Hold Select Bit: 1 */
#define ADC10SHT2_H         (0x0004)  /* ADC10 Sample Hold Select Bit: 2 */
#define ADC10SHT3_H         (0x0008)  /* ADC10 Sample Hold Select Bit: 3 */

#define ADC10SHT_0          (0x0000) /* ADC10 Sample Hold Select 0 */
#define ADC10SHT_1          (0x0100) /* ADC10 Sample Hold Select 1 */
#define ADC10SHT_2          (0x0200) /* ADC10 Sample Hold Select 2 */
#define ADC10SHT_3          (0x0300) /* ADC10 Sample Hold Select 3 */
#define ADC10SHT_4          (0x0400) /* ADC10 Sample Hold Select 4 */
#define ADC10SHT_5          (0x0500) /* ADC10 Sample Hold Select 5 */
#define ADC10SHT_6          (0x0600) /* ADC10 Sample Hold Select 6 */
#define ADC10SHT_7          (0x0700) /* ADC10 Sample Hold Select 7 */
#define ADC10SHT_8          (0x0800) /* ADC10 Sample Hold Select 8 */
#define ADC10SHT_9          (0x0900) /* ADC10 Sample Hold Select 9 */
#define ADC10SHT_10         (0x0A00) /* ADC10 Sample Hold Select 10 */
#define ADC10SHT_11         (0x0B00) /* ADC10 Sample Hold Select 11 */
#define ADC10SHT_12         (0x0C00) /* ADC10 Sample Hold Select 12 */
#define ADC10SHT_13         (0x0D00) /* ADC10 Sample Hold Select 13 */
#define ADC10SHT_14         (0x0E00) /* ADC10 Sample Hold Select 14 */
#define ADC10SHT_15         (0x0F00) /* ADC10 Sample Hold Select 15 */

/* ADC10CTL1 Control Bits */
#define ADC10BUSY           (0x0001)    /* ADC10 Busy */
#define ADC10CONSEQ0        (0x0002)    /* ADC10 Conversion Sequence Select 0 */
#define ADC10CONSEQ1        (0x0004)    /* ADC10 Conversion Sequence Select 1 */
#define ADC10SSEL0          (0x0008)    /* ADC10 Clock Source Select 0 */
#define ADC10SSEL1          (0x0010)    /* ADC10 Clock Source Select 1 */
#define ADC10DIV0           (0x0020)    /* ADC10 Clock Divider Select 0 */
#define ADC10DIV1           (0x0040)    /* ADC10 Clock Divider Select 1 */
#define ADC10DIV2           (0x0080)    /* ADC10 Clock Divider Select 2 */
#define ADC10ISSH           (0x0100)    /* ADC10 Invert Sample Hold Signal */
#define ADC10SHP            (0x0200)    /* ADC10 Sample/Hold Pulse Mode */
#define ADC10SHS0           (0x0400)    /* ADC10 Sample/Hold Source 0 */
#define ADC10SHS1           (0x0800)    /* ADC10 Sample/Hold Source 1 */

/* ADC10CTL1 Control Bits */
#define ADC10BUSY_L         (0x0001)    /* ADC10 Busy */
#define ADC10CONSEQ0_L      (0x0002)    /* ADC10 Conversion Sequence Select 0 */
#define ADC10CONSEQ1_L      (0x0004)    /* ADC10 Conversion Sequence Select 1 */
#define ADC10SSEL0_L        (0x0008)    /* ADC10 Clock Source Select 0 */
#define ADC10SSEL1_L        (0x0010)    /* ADC10 Clock Source Select 1 */
#define ADC10DIV0_L         (0x0020)    /* ADC10 Clock Divider Select 0 */
#define ADC10DIV1_L         (0x0040)    /* ADC10 Clock Divider Select 1 */
#define ADC10DIV2_L         (0x0080)    /* ADC10 Clock Divider Select 2 */

/* ADC10CTL1 Control Bits */
#define ADC10ISSH_H         (0x0001)    /* ADC10 Invert Sample Hold Signal */
#define ADC10SHP_H          (0x0002)    /* ADC10 Sample/Hold Pulse Mode */
#define ADC10SHS0_H         (0x0004)    /* ADC10 Sample/Hold Source 0 */
#define ADC10SHS1_H         (0x0008)    /* ADC10 Sample/Hold Source 1 */

#define ADC10CONSEQ_0        (0x0000)      /* ADC10 Conversion Sequence Select: 0 */
#define ADC10CONSEQ_1        (0x0002)      /* ADC10 Conversion Sequence Select: 1 */
#define ADC10CONSEQ_2        (0x0004)      /* ADC10 Conversion Sequence Select: 2 */
#define ADC10CONSEQ_3        (0x0006)      /* ADC10 Conversion Sequence Select: 3 */

#define ADC10SSEL_0          (0x0000)      /* ADC10 Clock Source Select: 0 */
#define ADC10SSEL_1          (0x0008)      /* ADC10 Clock Source Select: 1 */
#define ADC10SSEL_2          (0x0010)      /* ADC10 Clock Source Select: 2 */
#define ADC10SSEL_3          (0x0018)      /* ADC10 Clock Source Select: 3 */

#define ADC10DIV_0           (0x0000)   /* ADC10 Clock Divider Select: 0 */
#define ADC10DIV_1           (0x0020)   /* ADC10 Clock Divider Select: 1 */
#define ADC10DIV_2           (0x0040)   /* ADC10 Clock Divider Select: 2 */
#define ADC10DIV_3           (0x0060)   /* ADC10 Clock Divider Select: 3 */
#define ADC10DIV_4           (0x0080)   /* ADC10 Clock Divider Select: 4 */
#define ADC10DIV_5           (0x00A0)   /* ADC10 Clock Divider Select: 5 */
#define ADC10DIV_6           (0x00C0)   /* ADC10 Clock Divider Select: 6 */
#define ADC10DIV_7           (0x00E0)   /* ADC10 Clock Divider Select: 7 */

#define ADC10SHS_0           (0x0000)  /* ADC10 Sample/Hold Source: 0 */
#define ADC10SHS_1           (0x0400)  /* ADC10 Sample/Hold Source: 1 */
#define ADC10SHS_2           (0x0800)  /* ADC10 Sample/Hold Source: 2 */
#define ADC10SHS_3           (0x0C00)  /* ADC10 Sample/Hold Source: 3 */

/* ADC10CTL2 Control Bits */
#define ADC10REFBURST       (0x0001)    /* ADC10 Reference Burst */
#define ADC10SR             (0x0004)    /* ADC10 Sampling Rate */
#define ADC10DF             (0x0008)    /* ADC10 Data Format */
#define ADC10RES            (0x0010)    /* ADC10 Resolution Bit */
#define ADC10PDIV0          (0x0100)    /* ADC10 predivider Bit: 0 */
#define ADC10PDIV1          (0x0200)    /* ADC10 predivider Bit: 1 */

/* ADC10CTL2 Control Bits */
#define ADC10REFBURST_L     (0x0001)    /* ADC10 Reference Burst */
#define ADC10SR_L           (0x0004)    /* ADC10 Sampling Rate */
#define ADC10DF_L           (0x0008)    /* ADC10 Data Format */
#define ADC10RES_L          (0x0010)    /* ADC10 Resolution Bit */

/* ADC10CTL2 Control Bits */
#define ADC10PDIV0_H        (0x0001)    /* ADC10 predivider Bit: 0 */
#define ADC10PDIV1_H        (0x0002)    /* ADC10 predivider Bit: 1 */

#define ADC10PDIV_0         (0x0000)    /* ADC10 predivider /1 */
#define ADC10PDIV_1         (0x0100)    /* ADC10 predivider /2 */
#define ADC10PDIV_2         (0x0200)    /* ADC10 predivider /64 */
#define ADC10PDIV_3         (0x0300)    /* ADC10 predivider reserved */

#define ADC10PDIV__1        (0x0000)    /* ADC10 predivider /1 */
#define ADC10PDIV__4        (0x0100)    /* ADC10 predivider /2 */
#define ADC10PDIV__64       (0x0200)    /* ADC10 predivider /64 */

/* ADC10MCTL0 Control Bits */
#define ADC10INCH0          (0x0001)    /* ADC10 Input Channel Select Bit 0 */
#define ADC10INCH1          (0x0002)    /* ADC10 Input Channel Select Bit 1 */
#define ADC10INCH2          (0x0004)    /* ADC10 Input Channel Select Bit 2 */
#define ADC10INCH3          (0x0008)    /* ADC10 Input Channel Select Bit 3 */
#define ADC10SREF0          (0x0010)    /* ADC10 Select Reference Bit 0 */
#define ADC10SREF1          (0x0020)    /* ADC10 Select Reference Bit 1 */
#define ADC10SREF2          (0x0040)    /* ADC10 Select Reference Bit 2 */

/* ADC10MCTL0 Control Bits */
#define ADC10INCH0_L        (0x0001)    /* ADC10 Input Channel Select Bit 0 */
#define ADC10INCH1_L        (0x0002)    /* ADC10 Input Channel Select Bit 1 */
#define ADC10INCH2_L        (0x0004)    /* ADC10 Input Channel Select Bit 2 */
#define ADC10INCH3_L        (0x0008)    /* ADC10 Input Channel Select Bit 3 */
#define ADC10SREF0_L        (0x0010)    /* ADC10 Select Reference Bit 0 */
#define ADC10SREF1_L        (0x0020)    /* ADC10 Select Reference Bit 1 */
#define ADC10SREF2_L        (0x0040)    /* ADC10 Select Reference Bit 2 */


#define ADC10INCH_0         (0)         /* ADC10 Input Channel 0 */
#define ADC10INCH_1         (1)         /* ADC10 Input Channel 1 */
#define ADC10INCH_2         (2)         /* ADC10 Input Channel 2 */
#define ADC10INCH_3         (3)         /* ADC10 Input Channel 3 */
#define ADC10INCH_4         (4)         /* ADC10 Input Channel 4 */
#define ADC10INCH_5         (5)         /* ADC10 Input Channel 5 */
#define ADC10INCH_6         (6)         /* ADC10 Input Channel 6 */
#define ADC10INCH_7         (7)         /* ADC10 Input Channel 7 */
#define ADC10INCH_8         (8)         /* ADC10 Input Channel 8 */
#define ADC10INCH_9         (9)         /* ADC10 Input Channel 9 */
#define ADC10INCH_10        (10)        /* ADC10 Input Channel 10 */
#define ADC10INCH_11        (11)        /* ADC10 Input Channel 11 */
#define ADC10INCH_12        (12)        /* ADC10 Input Channel 12 */
#define ADC10INCH_13        (13)        /* ADC10 Input Channel 13 */
#define ADC10INCH_14        (14)        /* ADC10 Input Channel 14 */
#define ADC10INCH_15        (15)        /* ADC10 Input Channel 15 */

#define ADC10SREF_0         (0x0000)    /* ADC10 Select Reference 0 */
#define ADC10SREF_1         (0x0010)    /* ADC10 Select Reference 1 */
#define ADC10SREF_2         (0x0020)    /* ADC10 Select Reference 2 */
#define ADC10SREF_3         (0x0030)    /* ADC10 Select Reference 3 */
#define ADC10SREF_4         (0x0040)    /* ADC10 Select Reference 4 */
#define ADC10SREF_5         (0x0050)    /* ADC10 Select Reference 5 */
#define ADC10SREF_6         (0x0060)    /* ADC10 Select Reference 6 */
#define ADC10SREF_7         (0x0070)    /* ADC10 Select Reference 7 */

/* ADC10IE Interrupt Enable Bits */
#define ADC10IE0            (0x0001)    /* ADC10_A Interrupt enable */
#define ADC10INIE           (0x0002)    /* ADC10_A Interrupt enable for the inside of window of the Window comparator */
#define ADC10LOIE           (0x0004)    /* ADC10_A Interrupt enable for lower threshold of the Window comparator */
#define ADC10HIIE           (0x0008)    /* ADC10_A Interrupt enable for upper threshold of the Window comparator */
#define ADC10OVIE           (0x0010)    /* ADC10_A ADC10MEM overflow Interrupt enable */
#define ADC10TOVIE          (0x0020)    /* ADC10_A conversion-time-overflow Interrupt enable */

/* ADC10IE Interrupt Enable Bits */
#define ADC10IE0_L          (0x0001)    /* ADC10_A Interrupt enable */
#define ADC10INIE_L         (0x0002)    /* ADC10_A Interrupt enable for the inside of window of the Window comparator */
#define ADC10LOIE_L         (0x0004)    /* ADC10_A Interrupt enable for lower threshold of the Window comparator */
#define ADC10HIIE_L         (0x0008)    /* ADC10_A Interrupt enable for upper threshold of the Window comparator */
#define ADC10OVIE_L         (0x0010)    /* ADC10_A ADC10MEM overflow Interrupt enable */
#define ADC10TOVIE_L        (0x0020)    /* ADC10_A conversion-time-overflow Interrupt enable */


/* ADC10IFG Interrupt Flag Bits */
#define ADC10IFG0           (0x0001)    /* ADC10_A Interrupt Flag */
#define ADC10INIFG          (0x0002)    /* ADC10_A Interrupt Flag for the inside of window of the Window comparator */
#define ADC10LOIFG          (0x0004)    /* ADC10_A Interrupt Flag for lower threshold of the Window comparator */
#define ADC10HIIFG          (0x0008)    /* ADC10_A Interrupt Flag for upper threshold of the Window comparator */
#define ADC10OVIFG          (0x0010)    /* ADC10_A ADC10MEM overflow Interrupt Flag */
#define ADC10TOVIFG         (0x0020)    /* ADC10_A conversion-time-overflow Interrupt Flag */

/* ADC10IFG Interrupt Flag Bits */
#define ADC10IFG0_L         (0x0001)    /* ADC10_A Interrupt Flag */
#define ADC10INIFG_L        (0x0002)    /* ADC10_A Interrupt Flag for the inside of window of the Window comparator */
#define ADC10LOIFG_L        (0x0004)    /* ADC10_A Interrupt Flag for lower threshold of the Window comparator */
#define ADC10HIIFG_L        (0x0008)    /* ADC10_A Interrupt Flag for upper threshold of the Window comparator */
#define ADC10OVIFG_L        (0x0010)    /* ADC10_A ADC10MEM overflow Interrupt Flag */
#define ADC10TOVIFG_L       (0x0020)    /* ADC10_A conversion-time-overflow Interrupt Flag */


/* ADC10IV Definitions */
#define ADC10IV_NONE        (0x0000)    /* No Interrupt pending */
#define ADC10IV_ADC10OVIFG  (0x0002)    /* ADC10OVIFG */
#define ADC10IV_ADC10TOVIFG (0x0004)    /* ADC10TOVIFG */
#define ADC10IV_ADC10HIIFG  (0x0006)    /* ADC10HIIFG */
#define ADC10IV_ADC10LOIFG  (0x0008)    /* ADC10LOIFG */
#define ADC10IV_ADC10INIFG  (0x000A)    /* ADC10INIFG */
#define ADC10IV_ADC10IFG    (0x000C)    /* ADC10IFG */

#endif
/************************************************************
* ADC12 PLUS
************************************************************/
#ifdef  __MSP430_HAS_ADC12_PLUS__     /* Definition to show that Module is available */

#define OFS_ADC12CTL0         (0x0000)  /* ADC12+ Control 0 */
#define OFS_ADC12CTL0_L        OFS_ADC12CTL0
#define OFS_ADC12CTL0_H        OFS_ADC12CTL0+1
#define OFS_ADC12CTL1         (0x0002)  /* ADC12+ Control 1 */
#define OFS_ADC12CTL1_L        OFS_ADC12CTL1
#define OFS_ADC12CTL1_H        OFS_ADC12CTL1+1
#define OFS_ADC12CTL2         (0x0004)  /* ADC12+ Control 2 */
#define OFS_ADC12CTL2_L        OFS_ADC12CTL2
#define OFS_ADC12CTL2_H        OFS_ADC12CTL2+1
#define OFS_ADC12IFG          (0x000A)  /* ADC12+ Interrupt Flag */
#define OFS_ADC12IFG_L         OFS_ADC12IFG
#define OFS_ADC12IFG_H         OFS_ADC12IFG+1
#define OFS_ADC12IE           (0x000C)  /* ADC12+ Interrupt Enable */
#define OFS_ADC12IE_L          OFS_ADC12IE
#define OFS_ADC12IE_H          OFS_ADC12IE+1
#define OFS_ADC12IV           (0x000E)  /* ADC12+ Interrupt Vector Word */
#define OFS_ADC12IV_L          OFS_ADC12IV
#define OFS_ADC12IV_H          OFS_ADC12IV+1

#define OFS_ADC12MEM0         (0x0020)  /* ADC12 Conversion Memory 0 */
#define OFS_ADC12MEM0_L        OFS_ADC12MEM0
#define OFS_ADC12MEM0_H        OFS_ADC12MEM0+1
#define OFS_ADC12MEM1         (0x0022)  /* ADC12 Conversion Memory 1 */
#define OFS_ADC12MEM1_L        OFS_ADC12MEM1
#define OFS_ADC12MEM1_H        OFS_ADC12MEM1+1
#define OFS_ADC12MEM2         (0x0024)  /* ADC12 Conversion Memory 2 */
#define OFS_ADC12MEM2_L        OFS_ADC12MEM2
#define OFS_ADC12MEM2_H        OFS_ADC12MEM2+1
#define OFS_ADC12MEM3         (0x0026)  /* ADC12 Conversion Memory 3 */
#define OFS_ADC12MEM3_L        OFS_ADC12MEM3
#define OFS_ADC12MEM3_H        OFS_ADC12MEM3+1
#define OFS_ADC12MEM4         (0x0028)  /* ADC12 Conversion Memory 4 */
#define OFS_ADC12MEM4_L        OFS_ADC12MEM4
#define OFS_ADC12MEM4_H        OFS_ADC12MEM4+1
#define OFS_ADC12MEM5         (0x002A)  /* ADC12 Conversion Memory 5 */
#define OFS_ADC12MEM5_L        OFS_ADC12MEM5
#define OFS_ADC12MEM5_H        OFS_ADC12MEM5+1
#define OFS_ADC12MEM6         (0x002C)  /* ADC12 Conversion Memory 6 */
#define OFS_ADC12MEM6_L        OFS_ADC12MEM6
#define OFS_ADC12MEM6_H        OFS_ADC12MEM6+1
#define OFS_ADC12MEM7         (0x002E)  /* ADC12 Conversion Memory 7 */
#define OFS_ADC12MEM7_L        OFS_ADC12MEM7
#define OFS_ADC12MEM7_H        OFS_ADC12MEM7+1
#define OFS_ADC12MEM8         (0x0030)  /* ADC12 Conversion Memory 8 */
#define OFS_ADC12MEM8_L        OFS_ADC12MEM8
#define OFS_ADC12MEM8_H        OFS_ADC12MEM8+1
#define OFS_ADC12MEM9         (0x0032)  /* ADC12 Conversion Memory 9 */
#define OFS_ADC12MEM9_L        OFS_ADC12MEM9
#define OFS_ADC12MEM9_H        OFS_ADC12MEM9+1
#define OFS_ADC12MEM10        (0x0034)  /* ADC12 Conversion Memory 10 */
#define OFS_ADC12MEM10_L       OFS_ADC12MEM10
#define OFS_ADC12MEM10_H       OFS_ADC12MEM10+1
#define OFS_ADC12MEM11        (0x0036)  /* ADC12 Conversion Memory 11 */
#define OFS_ADC12MEM11_L       OFS_ADC12MEM11
#define OFS_ADC12MEM11_H       OFS_ADC12MEM11+1
#define OFS_ADC12MEM12        (0x0038)  /* ADC12 Conversion Memory 12 */
#define OFS_ADC12MEM12_L       OFS_ADC12MEM12
#define OFS_ADC12MEM12_H       OFS_ADC12MEM12+1
#define OFS_ADC12MEM13        (0x003A)  /* ADC12 Conversion Memory 13 */
#define OFS_ADC12MEM13_L       OFS_ADC12MEM13
#define OFS_ADC12MEM13_H       OFS_ADC12MEM13+1
#define OFS_ADC12MEM14        (0x003C)  /* ADC12 Conversion Memory 14 */
#define OFS_ADC12MEM14_L       OFS_ADC12MEM14
#define OFS_ADC12MEM14_H       OFS_ADC12MEM14+1
#define OFS_ADC12MEM15        (0x003E)  /* ADC12 Conversion Memory 15 */
#define OFS_ADC12MEM15_L       OFS_ADC12MEM15
#define OFS_ADC12MEM15_H       OFS_ADC12MEM15+1
#define ADC12MEM_           ADC12MEM  /* ADC12 Conversion Memory */
#ifndef __STDC__
#define ADC12MEM            ADC12MEM0 /* ADC12 Conversion Memory (for assembler) */
#else
#define ADC12MEM            ((volatile int*) &ADC12MEM0) /* ADC12 Conversion Memory (for C) */
#endif

#define OFS_ADC12MCTL0        (0x0010)  /* ADC12 Memory Control 0 */
#define OFS_ADC12MCTL1        (0x0011)  /* ADC12 Memory Control 1 */
#define OFS_ADC12MCTL2        (0x0012)  /* ADC12 Memory Control 2 */
#define OFS_ADC12MCTL3        (0x0013)  /* ADC12 Memory Control 3 */
#define OFS_ADC12MCTL4        (0x0014)  /* ADC12 Memory Control 4 */
#define OFS_ADC12MCTL5        (0x0015)  /* ADC12 Memory Control 5 */
#define OFS_ADC12MCTL6        (0x0016)  /* ADC12 Memory Control 6 */
#define OFS_ADC12MCTL7        (0x0017)  /* ADC12 Memory Control 7 */
#define OFS_ADC12MCTL8        (0x0018)  /* ADC12 Memory Control 8 */
#define OFS_ADC12MCTL9        (0x0019)  /* ADC12 Memory Control 9 */
#define OFS_ADC12MCTL10       (0x001A)  /* ADC12 Memory Control 10 */
#define OFS_ADC12MCTL11       (0x001B)  /* ADC12 Memory Control 11 */
#define OFS_ADC12MCTL12       (0x001C)  /* ADC12 Memory Control 12 */
#define OFS_ADC12MCTL13       (0x001D)  /* ADC12 Memory Control 13 */
#define OFS_ADC12MCTL14       (0x001E)  /* ADC12 Memory Control 14 */
#define OFS_ADC12MCTL15       (0x001F)  /* ADC12 Memory Control 15 */
#define ADC12MCTL_          ADC12MCTL /* ADC12 Memory Control */
#ifndef __STDC__
#define ADC12MCTL           ADC12MCTL0 /* ADC12 Memory Control (for assembler) */
#else
#define ADC12MCTL           ((volatile char*) &ADC12MCTL0) /* ADC12 Memory Control (for C) */
#endif

/* ADC12CTL0 Control Bits */
#define ADC12SC             (0x0001)  /* ADC12 Start Conversion */
#define ADC12ENC            (0x0002)  /* ADC12 Enable Conversion */
#define ADC12TOVIE          (0x0004)  /* ADC12 Timer Overflow interrupt enable */
#define ADC12OVIE           (0x0008)  /* ADC12 Overflow interrupt enable */
#define ADC12ON             (0x0010)  /* ADC12 On/enable */
#define ADC12REFON          (0x0020)  /* ADC12 Reference on */
#define ADC12REF2_5V        (0x0040)  /* ADC12 Ref 0:1.5V / 1:2.5V */
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
#define ADC12TOVIE_L        (0x0004)  /* ADC12 Timer Overflow interrupt enable */
#define ADC12OVIE_L         (0x0008)  /* ADC12 Overflow interrupt enable */
#define ADC12ON_L           (0x0010)  /* ADC12 On/enable */
#define ADC12REFON_L        (0x0020)  /* ADC12 Reference on */
#define ADC12REF2_5V_L      (0x0040)  /* ADC12 Ref 0:1.5V / 1:2.5V */
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
#define ADC12CSTARTADD0     (0x1000)    /* ADC12 Conversion Start Address Bit: 0 */
#define ADC12CSTARTADD1     (0x2000)    /* ADC12 Conversion Start Address Bit: 1 */
#define ADC12CSTARTADD2     (0x4000)    /* ADC12 Conversion Start Address Bit: 2 */
#define ADC12CSTARTADD3     (0x8000)    /* ADC12 Conversion Start Address Bit: 3 */

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
#define ADC12CSTARTADD0_H   (0x0010)    /* ADC12 Conversion Start Address Bit: 0 */
#define ADC12CSTARTADD1_H   (0x0020)    /* ADC12 Conversion Start Address Bit: 1 */
#define ADC12CSTARTADD2_H   (0x0040)    /* ADC12 Conversion Start Address Bit: 2 */
#define ADC12CSTARTADD3_H   (0x0080)    /* ADC12 Conversion Start Address Bit: 3 */

#define ADC12CONSEQ_0        (0x0000)      /* ADC12 Conversion Sequence Select: 0 */
#define ADC12CONSEQ_1        (0x0002)      /* ADC12 Conversion Sequence Select: 1 */
#define ADC12CONSEQ_2        (0x0004)      /* ADC12 Conversion Sequence Select: 2 */
#define ADC12CONSEQ_3        (0x0006)      /* ADC12 Conversion Sequence Select: 3 */

#define ADC12SSEL_0          (0x0000)      /* ADC12 Clock Source Select: 0 */
#define ADC12SSEL_1          (0x0008)      /* ADC12 Clock Source Select: 1 */
#define ADC12SSEL_2          (0x0010)      /* ADC12 Clock Source Select: 2 */
#define ADC12SSEL_3          (0x0018)      /* ADC12 Clock Source Select: 3 */

#define ADC12DIV_0           (0x0000)   /* ADC12 Clock Divider Select: 0 */
#define ADC12DIV_1           (0x0020)   /* ADC12 Clock Divider Select: 1 */
#define ADC12DIV_2           (0x0040)   /* ADC12 Clock Divider Select: 2 */
#define ADC12DIV_3           (0x0060)   /* ADC12 Clock Divider Select: 3 */
#define ADC12DIV_4           (0x0080)   /* ADC12 Clock Divider Select: 4 */
#define ADC12DIV_5           (0x00A0)   /* ADC12 Clock Divider Select: 5 */
#define ADC12DIV_6           (0x00C0)   /* ADC12 Clock Divider Select: 6 */
#define ADC12DIV_7           (0x00E0)   /* ADC12 Clock Divider Select: 7 */

#define ADC12SHS_0           (0x0000)  /* ADC12 Sample/Hold Source: 0 */
#define ADC12SHS_1           (0x0400)  /* ADC12 Sample/Hold Source: 1 */
#define ADC12SHS_2           (0x0800)  /* ADC12 Sample/Hold Source: 2 */
#define ADC12SHS_3           (0x0C00)  /* ADC12 Sample/Hold Source: 3 */

#define ADC12CSTARTADD_0     (0x0000) /* ADC12 Conversion Start Address: 0 */
#define ADC12CSTARTADD_1     (0x1000) /* ADC12 Conversion Start Address: 1 */
#define ADC12CSTARTADD_2     (0x2000) /* ADC12 Conversion Start Address: 2 */
#define ADC12CSTARTADD_3     (0x3000) /* ADC12 Conversion Start Address: 3 */
#define ADC12CSTARTADD_4     (0x4000) /* ADC12 Conversion Start Address: 4 */
#define ADC12CSTARTADD_5     (0x5000) /* ADC12 Conversion Start Address: 5 */
#define ADC12CSTARTADD_6     (0x6000) /* ADC12 Conversion Start Address: 6 */
#define ADC12CSTARTADD_7     (0x7000) /* ADC12 Conversion Start Address: 7 */
#define ADC12CSTARTADD_8     (0x8000) /* ADC12 Conversion Start Address: 8 */
#define ADC12CSTARTADD_9     (0x9000) /* ADC12 Conversion Start Address: 9 */
#define ADC12CSTARTADD_10    (0xA000) /* ADC12 Conversion Start Address: 10 */
#define ADC12CSTARTADD_11    (0xB000) /* ADC12 Conversion Start Address: 11 */
#define ADC12CSTARTADD_12    (0xC000) /* ADC12 Conversion Start Address: 12 */
#define ADC12CSTARTADD_13    (0xD000) /* ADC12 Conversion Start Address: 13 */
#define ADC12CSTARTADD_14    (0xE000) /* ADC12 Conversion Start Address: 14 */
#define ADC12CSTARTADD_15    (0xF000) /* ADC12 Conversion Start Address: 15 */

/* ADC12CTL2 Control Bits */
#define ADC12REFBURST       (0x0001)    /* ADC12+ Reference Burst */
#define ADC12REFOUT         (0x0002)    /* ADC12+ Reference Out */
#define ADC12SR             (0x0004)    /* ADC12+ Sampling Rate */
#define ADC12DF             (0x0008)    /* ADC12+ Data Format */
#define ADC12RES0           (0x0010)    /* ADC12+ Resolution Bit: 0 */
#define ADC12RES1           (0x0020)    /* ADC12+ Resolution Bit: 1 */
#define ADC12TCOFF          (0x0080)    /* ADC12+ Temperature Sensor Off */
#define ADC12PDIV           (0x0100)    /* ADC12+ predivider 0:/1   1:/4 */

/* ADC12CTL2 Control Bits */
#define ADC12REFBURST_L     (0x0001)    /* ADC12+ Reference Burst */
#define ADC12REFOUT_L       (0x0002)    /* ADC12+ Reference Out */
#define ADC12SR_L           (0x0004)    /* ADC12+ Sampling Rate */
#define ADC12DF_L           (0x0008)    /* ADC12+ Data Format */
#define ADC12RES0_L         (0x0010)    /* ADC12+ Resolution Bit: 0 */
#define ADC12RES1_L         (0x0020)    /* ADC12+ Resolution Bit: 1 */
#define ADC12TCOFF_L        (0x0080)    /* ADC12+ Temperature Sensor Off */

/* ADC12CTL2 Control Bits */
#define ADC12PDIV_H         (0x0001)    /* ADC12+ predivider 0:/1   1:/4 */

#define ADC12RES_0          (0x0000)    /* ADC12+ Resolution : 8 Bit */
#define ADC12RES_1          (0x0010)    /* ADC12+ Resolution : 10 Bit */
#define ADC12RES_2          (0x0020)    /* ADC12+ Resolution : 12 Bit */
#define ADC12RES_3          (0x0030)    /* ADC12+ Resolution : reserved */

/* ADC12MCTLx Control Bits */
#define ADC12INCH0          (0x0001)    /* ADC12 Input Channel Select Bit 0 */
#define ADC12INCH1          (0x0002)    /* ADC12 Input Channel Select Bit 1 */
#define ADC12INCH2          (0x0004)    /* ADC12 Input Channel Select Bit 2 */
#define ADC12INCH3          (0x0008)    /* ADC12 Input Channel Select Bit 3 */
#define ADC12SREF0          (0x0010)    /* ADC12 Select Reference Bit 0 */
#define ADC12SREF1          (0x0020)    /* ADC12 Select Reference Bit 1 */
#define ADC12SREF2          (0x0040)    /* ADC12 Select Reference Bit 2 */
#define ADC12EOS            (0x0080)    /* ADC12 End of Sequence */

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

#define ADC12SREF_0         (0x0000)    /* ADC12 Select Reference 0 */
#define ADC12SREF_1         (0x0010)    /* ADC12 Select Reference 1 */
#define ADC12SREF_2         (0x0020)    /* ADC12 Select Reference 2 */
#define ADC12SREF_3         (0x0030)    /* ADC12 Select Reference 3 */
#define ADC12SREF_4         (0x0040)    /* ADC12 Select Reference 4 */
#define ADC12SREF_5         (0x0050)    /* ADC12 Select Reference 5 */
#define ADC12SREF_6         (0x0060)    /* ADC12 Select Reference 6 */
#define ADC12SREF_7         (0x0070)    /* ADC12 Select Reference 7 */

#define ADC12IE0           (0x0001)  /* ADC12 Memory 0 Interrupt Enable */
#define ADC12IE1           (0x0002)  /* ADC12 Memory 1 Interrupt Enable */
#define ADC12IE2           (0x0004)  /* ADC12 Memory 2 Interrupt Enable */
#define ADC12IE3           (0x0008)  /* ADC12 Memory 3 Interrupt Enable */
#define ADC12IE4           (0x0010)  /* ADC12 Memory 4 Interrupt Enable */
#define ADC12IE5           (0x0020)  /* ADC12 Memory 5 Interrupt Enable */
#define ADC12IE6           (0x0040)  /* ADC12 Memory 6 Interrupt Enable */
#define ADC12IE7           (0x0080)  /* ADC12 Memory 7 Interrupt Enable */
#define ADC12IE8           (0x0100)  /* ADC12 Memory 8 Interrupt Enable */
#define ADC12IE9           (0x0200)  /* ADC12 Memory 9 Interrupt Enable */
#define ADC12IE10           (0x0400)  /* ADC12 Memory 10 Interrupt Enable */
#define ADC12IE11           (0x0800)  /* ADC12 Memory 11 Interrupt Enable */
#define ADC12IE12           (0x1000)  /* ADC12 Memory 12 Interrupt Enable */
#define ADC12IE13           (0x2000)  /* ADC12 Memory 13 Interrupt Enable */
#define ADC12IE14           (0x4000)  /* ADC12 Memory 14 Interrupt Enable */
#define ADC12IE15           (0x8000)  /* ADC12 Memory 15 Interrupt Enable */

#define ADC12IE0_L          (0x0001)  /* ADC12 Memory 0 Interrupt Enable */
#define ADC12IE1_L          (0x0002)  /* ADC12 Memory 1 Interrupt Enable */
#define ADC12IE2_L          (0x0004)  /* ADC12 Memory 2 Interrupt Enable */
#define ADC12IE3_L          (0x0008)  /* ADC12 Memory 3 Interrupt Enable */
#define ADC12IE4_L          (0x0010)  /* ADC12 Memory 4 Interrupt Enable */
#define ADC12IE5_L          (0x0020)  /* ADC12 Memory 5 Interrupt Enable */
#define ADC12IE6_L          (0x0040)  /* ADC12 Memory 6 Interrupt Enable */
#define ADC12IE7_L          (0x0080)  /* ADC12 Memory 7 Interrupt Enable */

#define ADC12IE8_H          (0x0001)  /* ADC12 Memory 8 Interrupt Enable */
#define ADC12IE9_H          (0x0002)  /* ADC12 Memory 9 Interrupt Enable */
#define ADC12IE10_H         (0x0004)  /* ADC12 Memory 10 Interrupt Enable */
#define ADC12IE11_H         (0x0008)  /* ADC12 Memory 11 Interrupt Enable */
#define ADC12IE12_H         (0x0010)  /* ADC12 Memory 12 Interrupt Enable */
#define ADC12IE13_H         (0x0020)  /* ADC12 Memory 13 Interrupt Enable */
#define ADC12IE14_H         (0x0040)  /* ADC12 Memory 14 Interrupt Enable */
#define ADC12IE15_H         (0x0080)  /* ADC12 Memory 15 Interrupt Enable */

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

#define ADC12IFG0_L         (0x0001)  /* ADC12 Memory 0 Interrupt Flag */
#define ADC12IFG1_L         (0x0002)  /* ADC12 Memory 1 Interrupt Flag */
#define ADC12IFG2_L         (0x0004)  /* ADC12 Memory 2 Interrupt Flag */
#define ADC12IFG3_L         (0x0008)  /* ADC12 Memory 3 Interrupt Flag */
#define ADC12IFG4_L         (0x0010)  /* ADC12 Memory 4 Interrupt Flag */
#define ADC12IFG5_L         (0x0020)  /* ADC12 Memory 5 Interrupt Flag */
#define ADC12IFG6_L         (0x0040)  /* ADC12 Memory 6 Interrupt Flag */
#define ADC12IFG7_L         (0x0080)  /* ADC12 Memory 7 Interrupt Flag */

#define ADC12IFG8_H         (0x0001)  /* ADC12 Memory 8 Interrupt Flag */
#define ADC12IFG9_H         (0x0002)  /* ADC12 Memory 9 Interrupt Flag */
#define ADC12IFG10_H        (0x0004)  /* ADC12 Memory 10 Interrupt Flag */
#define ADC12IFG11_H        (0x0008)  /* ADC12 Memory 11 Interrupt Flag */
#define ADC12IFG12_H        (0x0010)  /* ADC12 Memory 12 Interrupt Flag */
#define ADC12IFG13_H        (0x0020)  /* ADC12 Memory 13 Interrupt Flag */
#define ADC12IFG14_H        (0x0040)  /* ADC12 Memory 14 Interrupt Flag */
#define ADC12IFG15_H        (0x0080)  /* ADC12 Memory 15 Interrupt Flag */

/* ADC12IV Definitions */
#define ADC12IV_NONE        (0x0000)    /* No Interrupt pending */
#define ADC12IV_ADC12OVIFG  (0x0002)    /* ADC12OVIFG */
#define ADC12IV_ADC12TOVIFG (0x0004)    /* ADC12TOVIFG */
#define ADC12IV_ADC12IFG0   (0x0006)    /* ADC12IFG0 */
#define ADC12IV_ADC12IFG1   (0x0008)    /* ADC12IFG1 */
#define ADC12IV_ADC12IFG2   (0x000A)    /* ADC12IFG2 */
#define ADC12IV_ADC12IFG3   (0x000C)    /* ADC12IFG3 */
#define ADC12IV_ADC12IFG4   (0x000E)    /* ADC12IFG4 */
#define ADC12IV_ADC12IFG5   (0x0010)    /* ADC12IFG5 */
#define ADC12IV_ADC12IFG6   (0x0012)    /* ADC12IFG6 */
#define ADC12IV_ADC12IFG7   (0x0014)    /* ADC12IFG7 */
#define ADC12IV_ADC12IFG8   (0x0016)    /* ADC12IFG8 */
#define ADC12IV_ADC12IFG9   (0x0018)    /* ADC12IFG9 */
#define ADC12IV_ADC12IFG10  (0x001A)    /* ADC12IFG10 */
#define ADC12IV_ADC12IFG11  (0x001C)    /* ADC12IFG11 */
#define ADC12IV_ADC12IFG12  (0x001E)    /* ADC12IFG12 */
#define ADC12IV_ADC12IFG13  (0x0020)    /* ADC12IFG13 */
#define ADC12IV_ADC12IFG14  (0x0022)    /* ADC12IFG14 */
#define ADC12IV_ADC12IFG15  (0x0024)    /* ADC12IFG15 */

#endif
/************************************************************
* AES Accelerator
************************************************************/
#ifdef  __MSP430_HAS_AES__          /* Definition to show that Module is available */

#define OFS_AESACTL0          (0x0000)  /* AES accelerator control register 0 */
#define OFS_AESACTL0_L         OFS_AESACTL0
#define OFS_AESACTL0_H         OFS_AESACTL0+1
#define OFS_AESASTAT          (0x0004)  /* AES accelerator status register */
#define OFS_AESASTAT_L         OFS_AESASTAT
#define OFS_AESASTAT_H         OFS_AESASTAT+1
#define OFS_AESAKEY           (0x0006)  /* AES accelerator key register */
#define OFS_AESAKEY_L          OFS_AESAKEY
#define OFS_AESAKEY_H          OFS_AESAKEY+1
#define OFS_AESADIN           (0x0008)  /* AES accelerator data in register */
#define OFS_AESADIN_L          OFS_AESADIN
#define OFS_AESADIN_H          OFS_AESADIN+1
#define OFS_AESADOUT          (0x000A)  /* AES accelerator data out register  */
#define OFS_AESADOUT_L         OFS_AESADOUT
#define OFS_AESADOUT_H         OFS_AESADOUT+1


/* AESACTL0 Control Bits */
#define AESOP0              (0x0001)  /* AES Operation Bit: 0 */
#define AESOP1              (0x0002)  /* AES Operation Bit: 1 */
#define AESSWRST            (0x0080)  /* AES Software Reset */
#define AESRDYIFG           (0x0100)  /* AES ready interrupt flag */
#define AESERRFG            (0x0800)  /* AES Error Flag */
#define AESRDYIE            (0x1000)  /* AES ready interrupt enable*/

/* AESACTL0 Control Bits */
#define AESOP0_L            (0x0001)  /* AES Operation Bit: 0 */
#define AESOP1_L            (0x0002)  /* AES Operation Bit: 1 */
#define AESSWRST_L          (0x0080)  /* AES Software Reset */

/* AESACTL0 Control Bits */
#define AESRDYIFG_H         (0x0001)  /* AES ready interrupt flag */
#define AESERRFG_H          (0x0008)  /* AES Error Flag */
#define AESRDYIE_H          (0x0010)  /* AES ready interrupt enable*/

#define AESOP_0             (0x0000)  /* AES Operation: Encrypt */
#define AESOP_1             (0x0001)  /* AES Operation: Decrypt (same Key) */
#define AESOP_2             (0x0002)  /* AES Operation: Decrypt (frist round Key) */
#define AESOP_3             (0x0003)  /* AES Operation: Generate first round Key */


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

#endif
/*************************************************************
* Backup RAM Module
*************************************************************/
#ifdef  __MSP430_HAS_BACKUP_RAM__      /* Definition to show that Module is available */

#define OFS_BAKMEM0           (0x0000)  /* Battery Backup Memory 0 */
#define OFS_BAKMEM0_L          OFS_BAKMEM0
#define OFS_BAKMEM0_H          OFS_BAKMEM0+1
#define OFS_BAKMEM1           (0x0002)  /* Battery Backup Memory 1 */
#define OFS_BAKMEM1_L          OFS_BAKMEM1
#define OFS_BAKMEM1_H          OFS_BAKMEM1+1
#define OFS_BAKMEM2           (0x0004)  /* Battery Backup Memory 2 */
#define OFS_BAKMEM2_L          OFS_BAKMEM2
#define OFS_BAKMEM2_H          OFS_BAKMEM2+1
#define OFS_BAKMEM3           (0x0006)  /* Battery Backup Memory 3 */
#define OFS_BAKMEM3_L          OFS_BAKMEM3
#define OFS_BAKMEM3_H          OFS_BAKMEM3+1

#endif
/*************************************************************
* Battery Charger Module
*************************************************************/
#ifdef  __MSP430_HAS_BATTERY_CHARGER__   /* Definition to show that Module is available */

#define OFS_BAKCTL            (0x0000)  /* Battery Backup Control */
#define OFS_BAKCTL_L           OFS_BAKCTL
#define OFS_BAKCTL_H           OFS_BAKCTL+1
#define OFS_BAKCHCTL          (0x0002)  /* Battery Charger Control */
#define OFS_BAKCHCTL_L         OFS_BAKCHCTL
#define OFS_BAKCHCTL_H         OFS_BAKCHCTL+1

/* BAKCTL Control Bits */
#define LOCKBAK              (0x0001)    /* Lock backup sub-system */
#define BAKSW                (0x0002)    /* Manual switch to battery backup supply */
#define BAKADC               (0x0004)    /* Battery backup supply to ADC. */
#define BAKDIS               (0x0008)    /* Disable backup supply switching. */


/* BAKCTL Control Bits */
#define LOCKBAK_L           (0x0001)    /* Lock backup sub-system */
#define BAKSW_L             (0x0002)    /* Manual switch to battery backup supply */
#define BAKADC_L            (0x0004)    /* Battery backup supply to ADC. */
#define BAKDIS_L            (0x0008)    /* Disable backup supply switching. */



/* BAKCHCTL Control Bits */
#define CHEN                 (0x0001)    /* Charger enable */
#define CHC0                 (0x0002)    /* Charger charge current Bit 0 */
#define CHC1                 (0x0004)    /* Charger charge current Bit 1 */
#define CHV0                 (0x0010)    /* Charger end voltage Bit 0 */
#define CHV1                 (0x0020)    /* Charger end voltage Bit 1 */

/* BAKCHCTL Control Bits */
#define CHEN_L              (0x0001)    /* Charger enable */
#define CHC0_L              (0x0002)    /* Charger charge current Bit 0 */
#define CHC1_L              (0x0004)    /* Charger charge current Bit 1 */
#define CHV0_L              (0x0010)    /* Charger end voltage Bit 0 */
#define CHV1_L              (0x0020)    /* Charger end voltage Bit 1 */


#define CHPWD               (0x6900)     /* Charger write password. */

#endif
/************************************************************
* Comparator B
************************************************************/
#ifdef  __MSP430_HAS_COMPB__          /* Definition to show that Module is available */

#define OFS_CBCTL0            (0x0000)  /* Comparator B Control Register 0 */
#define OFS_CBCTL0_L           OFS_CBCTL0
#define OFS_CBCTL0_H           OFS_CBCTL0+1
#define OFS_CBCTL1            (0x0002)  /* Comparator B Control Register 1 */
#define OFS_CBCTL1_L           OFS_CBCTL1
#define OFS_CBCTL1_H           OFS_CBCTL1+1
#define OFS_CBCTL2            (0x0004)  /* Comparator B Control Register 2 */
#define OFS_CBCTL2_L           OFS_CBCTL2
#define OFS_CBCTL2_H           OFS_CBCTL2+1
#define OFS_CBCTL3            (0x0006)  /* Comparator B Control Register 3 */
#define OFS_CBCTL3_L           OFS_CBCTL3
#define OFS_CBCTL3_H           OFS_CBCTL3+1
#define OFS_CBINT             (0x000C)  /* Comparator B Interrupt Register */
#define OFS_CBINT_L            OFS_CBINT
#define OFS_CBINT_H            OFS_CBINT+1
#define OFS_CBIV              (0x000E)  /* Comparator B Interrupt Vector Word */


/* CBCTL0 Control Bits */
#define CBIPSEL0            (0x0001)  /* Comp. B Pos. Channel Input Select 0 */
#define CBIPSEL1            (0x0002)  /* Comp. B Pos. Channel Input Select 1 */
#define CBIPSEL2            (0x0004)  /* Comp. B Pos. Channel Input Select 2 */
#define CBIPSEL3            (0x0008)  /* Comp. B Pos. Channel Input Select 3 */
//#define RESERVED            (0x0010)  /* Comp. B */
//#define RESERVED            (0x0020)  /* Comp. B */
//#define RESERVED            (0x0040)  /* Comp. B */
#define CBIPEN              (0x0080)  /* Comp. B Pos. Channel Input Enable */
#define CBIMSEL0            (0x0100)  /* Comp. B Neg. Channel Input Select 0 */
#define CBIMSEL1            (0x0200)  /* Comp. B Neg. Channel Input Select 1 */
#define CBIMSEL2            (0x0400)  /* Comp. B Neg. Channel Input Select 2 */
#define CBIMSEL3            (0x0800)  /* Comp. B Neg. Channel Input Select 3 */
//#define RESERVED            (0x1000)  /* Comp. B */
//#define RESERVED            (0x2000)  /* Comp. B */
//#define RESERVED            (0x4000)  /* Comp. B */
#define CBIMEN              (0x8000)  /* Comp. B Neg. Channel Input Enable */

/* CBCTL0 Control Bits */
#define CBIPSEL0_L          (0x0001)  /* Comp. B Pos. Channel Input Select 0 */
#define CBIPSEL1_L          (0x0002)  /* Comp. B Pos. Channel Input Select 1 */
#define CBIPSEL2_L          (0x0004)  /* Comp. B Pos. Channel Input Select 2 */
#define CBIPSEL3_L          (0x0008)  /* Comp. B Pos. Channel Input Select 3 */
//#define RESERVED            (0x0010)  /* Comp. B */
//#define RESERVED            (0x0020)  /* Comp. B */
//#define RESERVED            (0x0040)  /* Comp. B */
#define CBIPEN_L            (0x0080)  /* Comp. B Pos. Channel Input Enable */
//#define RESERVED            (0x1000)  /* Comp. B */
//#define RESERVED            (0x2000)  /* Comp. B */
//#define RESERVED            (0x4000)  /* Comp. B */

/* CBCTL0 Control Bits */
//#define RESERVED            (0x0010)  /* Comp. B */
//#define RESERVED            (0x0020)  /* Comp. B */
//#define RESERVED            (0x0040)  /* Comp. B */
#define CBIMSEL0_H          (0x0001)  /* Comp. B Neg. Channel Input Select 0 */
#define CBIMSEL1_H          (0x0002)  /* Comp. B Neg. Channel Input Select 1 */
#define CBIMSEL2_H          (0x0004)  /* Comp. B Neg. Channel Input Select 2 */
#define CBIMSEL3_H          (0x0008)  /* Comp. B Neg. Channel Input Select 3 */
//#define RESERVED            (0x1000)  /* Comp. B */
//#define RESERVED            (0x2000)  /* Comp. B */
//#define RESERVED            (0x4000)  /* Comp. B */
#define CBIMEN_H            (0x0080)  /* Comp. B Neg. Channel Input Enable */

#define CBIPSEL_0           (0x0000)  /* Comp. B V+ terminal Input Select: Channel 0 */
#define CBIPSEL_1           (0x0001)  /* Comp. B V+ terminal Input Select: Channel 1 */
#define CBIPSEL_2           (0x0002)  /* Comp. B V+ terminal Input Select: Channel 2 */
#define CBIPSEL_3           (0x0003)  /* Comp. B V+ terminal Input Select: Channel 3 */
#define CBIPSEL_4           (0x0004)  /* Comp. B V+ terminal Input Select: Channel 4 */
#define CBIPSEL_5           (0x0005)  /* Comp. B V+ terminal Input Select: Channel 5 */
#define CBIPSEL_6           (0x0006)  /* Comp. B V+ terminal Input Select: Channel 6 */
#define CBIPSEL_7           (0x0007)  /* Comp. B V+ terminal Input Select: Channel 7 */
#define CBIPSEL_8           (0x0008)  /* Comp. B V+ terminal Input Select: Channel 8 */
#define CBIPSEL_9           (0x0009)  /* Comp. B V+ terminal Input Select: Channel 9 */
#define CBIPSEL_10          (0x000A)  /* Comp. B V+ terminal Input Select: Channel 10 */
#define CBIPSEL_11          (0x000B)  /* Comp. B V+ terminal Input Select: Channel 11 */
#define CBIPSEL_12          (0x000C)  /* Comp. B V+ terminal Input Select: Channel 12 */
#define CBIPSEL_13          (0x000D)  /* Comp. B V+ terminal Input Select: Channel 13 */
#define CBIPSEL_14          (0x000E)  /* Comp. B V+ terminal Input Select: Channel 14 */
#define CBIPSEL_15          (0x000F)  /* Comp. B V+ terminal Input Select: Channel 15 */

#define CBIMSEL_0           (0x0000)  /* Comp. B V- Terminal Input Select: Channel 0 */
#define CBIMSEL_1           (0x0100)  /* Comp. B V- Terminal Input Select: Channel 1 */
#define CBIMSEL_2           (0x0200)  /* Comp. B V- Terminal Input Select: Channel 2 */
#define CBIMSEL_3           (0x0300)  /* Comp. B V- Terminal Input Select: Channel 3 */
#define CBIMSEL_4           (0x0400)  /* Comp. B V- Terminal Input Select: Channel 4 */
#define CBIMSEL_5           (0x0500)  /* Comp. B V- Terminal Input Select: Channel 5 */
#define CBIMSEL_6           (0x0600)  /* Comp. B V- Terminal Input Select: Channel 6 */
#define CBIMSEL_7           (0x0700)  /* Comp. B V- Terminal Input Select: Channel 7 */
#define CBIMSEL_8           (0x0800)  /* Comp. B V- terminal Input Select: Channel 8 */
#define CBIMSEL_9           (0x0900)  /* Comp. B V- terminal Input Select: Channel 9 */
#define CBIMSEL_10          (0x0A00)  /* Comp. B V- terminal Input Select: Channel 10 */
#define CBIMSEL_11          (0x0B00)  /* Comp. B V- terminal Input Select: Channel 11 */
#define CBIMSEL_12          (0x0C00)  /* Comp. B V- terminal Input Select: Channel 12 */
#define CBIMSEL_13          (0x0D00)  /* Comp. B V- terminal Input Select: Channel 13 */
#define CBIMSEL_14          (0x0E00)  /* Comp. B V- terminal Input Select: Channel 14 */
#define CBIMSEL_15          (0x0F00)  /* Comp. B V- terminal Input Select: Channel 15 */

/* CBCTL1 Control Bits */
#define CBOUT               (0x0001)  /* Comp. B Output */
#define CBOUTPOL            (0x0002)  /* Comp. B Output Polarity */
#define CBF                 (0x0004)  /* Comp. B Enable Output Filter */
#define CBIES               (0x0008)  /* Comp. B Interrupt Edge Select */
#define CBSHORT             (0x0010)  /* Comp. B Input Short */
#define CBEX                (0x0020)  /* Comp. B Exchange Inputs */
#define CBFDLY0             (0x0040)  /* Comp. B Filter delay Bit 0 */
#define CBFDLY1             (0x0080)  /* Comp. B Filter delay Bit 1 */
#define CBPWRMD0            (0x0100)  /* Comp. B Power Mode Bit 0 */
#define CBPWRMD1            (0x0200)  /* Comp. B Power Mode Bit 1 */
#define CBON                (0x0400)  /* Comp. B enable */
#define CBMRVL              (0x0800)  /* Comp. B CBMRV Level */
#define CBMRVS              (0x1000)  /* Comp. B Output selects between VREF0 or VREF1*/
//#define RESERVED            (0x2000)  /* Comp. B */
//#define RESERVED            (0x4000)  /* Comp. B */
//#define RESERVED            (0x8000)  /* Comp. B */

/* CBCTL1 Control Bits */
#define CBOUT_L             (0x0001)  /* Comp. B Output */
#define CBOUTPOL_L          (0x0002)  /* Comp. B Output Polarity */
#define CBF_L               (0x0004)  /* Comp. B Enable Output Filter */
#define CBIES_L             (0x0008)  /* Comp. B Interrupt Edge Select */
#define CBSHORT_L           (0x0010)  /* Comp. B Input Short */
#define CBEX_L              (0x0020)  /* Comp. B Exchange Inputs */
#define CBFDLY0_L           (0x0040)  /* Comp. B Filter delay Bit 0 */
#define CBFDLY1_L           (0x0080)  /* Comp. B Filter delay Bit 1 */
//#define RESERVED            (0x2000)  /* Comp. B */
//#define RESERVED            (0x4000)  /* Comp. B */
//#define RESERVED            (0x8000)  /* Comp. B */

/* CBCTL1 Control Bits */
#define CBPWRMD0_H          (0x0001)  /* Comp. B Power Mode Bit 0 */
#define CBPWRMD1_H          (0x0002)  /* Comp. B Power Mode Bit 1 */
#define CBON_H              (0x0004)  /* Comp. B enable */
#define CBMRVL_H            (0x0008)  /* Comp. B CBMRV Level */
#define CBMRVS_H            (0x0010)  /* Comp. B Output selects between VREF0 or VREF1*/
//#define RESERVED            (0x2000)  /* Comp. B */
//#define RESERVED            (0x4000)  /* Comp. B */
//#define RESERVED            (0x8000)  /* Comp. B */

#define CBFDLY_0           (0x0000)  /* Comp. B Filter delay 0 : 450ns */
#define CBFDLY_1           (0x0040)  /* Comp. B Filter delay 1 : 900ns */
#define CBFDLY_2           (0x0080)  /* Comp. B Filter delay 2 : 1800ns */
#define CBFDLY_3           (0x00C0)  /* Comp. B Filter delay 3 : 3600ns */

#define CBPWRMD_0           (0x0000)  /* Comp. B Power Mode 0 : High speed */
#define CBPWRMD_1           (0x0100)  /* Comp. B Power Mode 1 : Normal */
#define CBPWRMD_2           (0x0200)  /* Comp. B Power Mode 2 : Ultra-Low*/
#define CBPWRMD_3           (0x0300)  /* Comp. B Power Mode 3 : Reserved */


/* CBCTL2 Control Bits */
#define CBREF00             (0x0001)  /* Comp. B Reference 0 Resistor Select Bit : 0 */
#define CBREF01             (0x0002)  /* Comp. B Reference 0 Resistor Select Bit : 1 */
#define CBREF02             (0x0004)  /* Comp. B Reference 0 Resistor Select Bit : 2 */
#define CBREF03             (0x0008)  /* Comp. B Reference 0 Resistor Select Bit : 3 */
#define CBREF04             (0x0010)  /* Comp. B Reference 0 Resistor Select Bit : 4 */
#define CBRSEL              (0x0020)  /* Comp. B Reference select */
#define CBRS0               (0x0040)  /* Comp. B Reference Source Bit : 0 */
#define CBRS1               (0x0080)  /* Comp. B Reference Source Bit : 1 */
#define CBREF10             (0x0100)  /* Comp. B Reference 1 Resistor Select Bit : 0 */
#define CBREF11             (0x0200)  /* Comp. B Reference 1 Resistor Select Bit : 1 */
#define CBREF12             (0x0400)  /* Comp. B Reference 1 Resistor Select Bit : 2 */
#define CBREF13             (0x0800)  /* Comp. B Reference 1 Resistor Select Bit : 3 */
#define CBREF14             (0x1000)  /* Comp. B Reference 1 Resistor Select Bit : 4 */
#define CBREFL0             (0x2000)  /* Comp. B Reference voltage level Bit : 0 */
#define CBREFL1             (0x4000)  /* Comp. B Reference voltage level Bit : 1 */
#define CBREFACC            (0x8000)  /* Comp. B Reference Accuracy */

/* CBCTL2 Control Bits */
#define CBREF00_L           (0x0001)  /* Comp. B Reference 0 Resistor Select Bit : 0 */
#define CBREF01_L           (0x0002)  /* Comp. B Reference 0 Resistor Select Bit : 1 */
#define CBREF02_L           (0x0004)  /* Comp. B Reference 0 Resistor Select Bit : 2 */
#define CBREF03_L           (0x0008)  /* Comp. B Reference 0 Resistor Select Bit : 3 */
#define CBREF04_L           (0x0010)  /* Comp. B Reference 0 Resistor Select Bit : 4 */
#define CBRSEL_L            (0x0020)  /* Comp. B Reference select */
#define CBRS0_L             (0x0040)  /* Comp. B Reference Source Bit : 0 */
#define CBRS1_L             (0x0080)  /* Comp. B Reference Source Bit : 1 */

/* CBCTL2 Control Bits */
#define CBREF10_H           (0x0001)  /* Comp. B Reference 1 Resistor Select Bit : 0 */
#define CBREF11_H           (0x0002)  /* Comp. B Reference 1 Resistor Select Bit : 1 */
#define CBREF12_H           (0x0004)  /* Comp. B Reference 1 Resistor Select Bit : 2 */
#define CBREF13_H           (0x0008)  /* Comp. B Reference 1 Resistor Select Bit : 3 */
#define CBREF14_H           (0x0010)  /* Comp. B Reference 1 Resistor Select Bit : 4 */
#define CBREFL0_H           (0x0020)  /* Comp. B Reference voltage level Bit : 0 */
#define CBREFL1_H           (0x0040)  /* Comp. B Reference voltage level Bit : 1 */
#define CBREFACC_H          (0x0080)  /* Comp. B Reference Accuracy */

#define CBREF0_0            (0x0000)  /* Comp. B Int. Ref.0 Select 0 : 1/32 */
#define CBREF0_1            (0x0001)  /* Comp. B Int. Ref.0 Select 1 : 2/32 */
#define CBREF0_2            (0x0002)  /* Comp. B Int. Ref.0 Select 2 : 3/32 */
#define CBREF0_3            (0x0003)  /* Comp. B Int. Ref.0 Select 3 : 4/32 */
#define CBREF0_4            (0x0004)  /* Comp. B Int. Ref.0 Select 4 : 5/32 */
#define CBREF0_5            (0x0005)  /* Comp. B Int. Ref.0 Select 5 : 6/32 */
#define CBREF0_6            (0x0006)  /* Comp. B Int. Ref.0 Select 6 : 7/32 */
#define CBREF0_7            (0x0007)  /* Comp. B Int. Ref.0 Select 7 : 8/32 */
#define CBREF0_8            (0x0008)  /* Comp. B Int. Ref.0 Select 0 : 9/32 */
#define CBREF0_9            (0x0009)  /* Comp. B Int. Ref.0 Select 1 : 10/32 */
#define CBREF0_10           (0x000A)  /* Comp. B Int. Ref.0 Select 2 : 11/32 */
#define CBREF0_11           (0x000B)  /* Comp. B Int. Ref.0 Select 3 : 12/32 */
#define CBREF0_12           (0x000C)  /* Comp. B Int. Ref.0 Select 4 : 13/32 */
#define CBREF0_13           (0x000D)  /* Comp. B Int. Ref.0 Select 5 : 14/32 */
#define CBREF0_14           (0x000E)  /* Comp. B Int. Ref.0 Select 6 : 15/32 */
#define CBREF0_15           (0x000F)  /* Comp. B Int. Ref.0 Select 7 : 16/32 */
#define CBREF0_16           (0x0010)  /* Comp. B Int. Ref.0 Select 0 : 17/32 */
#define CBREF0_17           (0x0011)  /* Comp. B Int. Ref.0 Select 1 : 18/32 */
#define CBREF0_18           (0x0012)  /* Comp. B Int. Ref.0 Select 2 : 19/32 */
#define CBREF0_19           (0x0013)  /* Comp. B Int. Ref.0 Select 3 : 20/32 */
#define CBREF0_20           (0x0014)  /* Comp. B Int. Ref.0 Select 4 : 21/32 */
#define CBREF0_21           (0x0015)  /* Comp. B Int. Ref.0 Select 5 : 22/32 */
#define CBREF0_22           (0x0016)  /* Comp. B Int. Ref.0 Select 6 : 23/32 */
#define CBREF0_23           (0x0017)  /* Comp. B Int. Ref.0 Select 7 : 24/32 */
#define CBREF0_24           (0x0018)  /* Comp. B Int. Ref.0 Select 0 : 25/32 */
#define CBREF0_25           (0x0019)  /* Comp. B Int. Ref.0 Select 1 : 26/32 */
#define CBREF0_26           (0x001A)  /* Comp. B Int. Ref.0 Select 2 : 27/32 */
#define CBREF0_27           (0x001B)  /* Comp. B Int. Ref.0 Select 3 : 28/32 */
#define CBREF0_28           (0x001C)  /* Comp. B Int. Ref.0 Select 4 : 29/32 */
#define CBREF0_29           (0x001D)  /* Comp. B Int. Ref.0 Select 5 : 30/32 */
#define CBREF0_30           (0x001E)  /* Comp. B Int. Ref.0 Select 6 : 31/32 */
#define CBREF0_31           (0x001F)  /* Comp. B Int. Ref.0 Select 7 : 32/32 */

#define CBRS_0              (0x0000)  /* Comp. B Reference Source 0 : Off */
#define CBRS_1              (0x0040)  /* Comp. B Reference Source 1 : Vcc */
#define CBRS_2              (0x0080)  /* Comp. B Reference Source 2 : Shared Ref. */
#define CBRS_3              (0x00C0)  /* Comp. B Reference Source 3 : Shared Ref. / Off */

#define CBREF1_0            (0x0000)  /* Comp. B Int. Ref.1 Select 0 : 1/32 */
#define CBREF1_1            (0x0100)  /* Comp. B Int. Ref.1 Select 1 : 2/32 */
#define CBREF1_2            (0x0200)  /* Comp. B Int. Ref.1 Select 2 : 3/32 */
#define CBREF1_3            (0x0300)  /* Comp. B Int. Ref.1 Select 3 : 4/32 */
#define CBREF1_4            (0x0400)  /* Comp. B Int. Ref.1 Select 4 : 5/32 */
#define CBREF1_5            (0x0500)  /* Comp. B Int. Ref.1 Select 5 : 6/32 */
#define CBREF1_6            (0x0600)  /* Comp. B Int. Ref.1 Select 6 : 7/32 */
#define CBREF1_7            (0x0700)  /* Comp. B Int. Ref.1 Select 7 : 8/32 */
#define CBREF1_8            (0x0800)  /* Comp. B Int. Ref.1 Select 0 : 9/32 */
#define CBREF1_9            (0x0900)  /* Comp. B Int. Ref.1 Select 1 : 10/32 */
#define CBREF1_10           (0x0A00)  /* Comp. B Int. Ref.1 Select 2 : 11/32 */
#define CBREF1_11           (0x0B00)  /* Comp. B Int. Ref.1 Select 3 : 12/32 */
#define CBREF1_12           (0x0C00)  /* Comp. B Int. Ref.1 Select 4 : 13/32 */
#define CBREF1_13           (0x0D00)  /* Comp. B Int. Ref.1 Select 5 : 14/32 */
#define CBREF1_14           (0x0E00)  /* Comp. B Int. Ref.1 Select 6 : 15/32 */
#define CBREF1_15           (0x0F00)  /* Comp. B Int. Ref.1 Select 7 : 16/32 */
#define CBREF1_16           (0x1000)  /* Comp. B Int. Ref.1 Select 0 : 17/32 */
#define CBREF1_17           (0x1100)  /* Comp. B Int. Ref.1 Select 1 : 18/32 */
#define CBREF1_18           (0x1200)  /* Comp. B Int. Ref.1 Select 2 : 19/32 */
#define CBREF1_19           (0x1300)  /* Comp. B Int. Ref.1 Select 3 : 20/32 */
#define CBREF1_20           (0x1400)  /* Comp. B Int. Ref.1 Select 4 : 21/32 */
#define CBREF1_21           (0x1500)  /* Comp. B Int. Ref.1 Select 5 : 22/32 */
#define CBREF1_22           (0x1600)  /* Comp. B Int. Ref.1 Select 6 : 23/32 */
#define CBREF1_23           (0x1700)  /* Comp. B Int. Ref.1 Select 7 : 24/32 */
#define CBREF1_24           (0x1800)  /* Comp. B Int. Ref.1 Select 0 : 25/32 */
#define CBREF1_25           (0x1900)  /* Comp. B Int. Ref.1 Select 1 : 26/32 */
#define CBREF1_26           (0x1A00)  /* Comp. B Int. Ref.1 Select 2 : 27/32 */
#define CBREF1_27           (0x1B00)  /* Comp. B Int. Ref.1 Select 3 : 28/32 */
#define CBREF1_28           (0x1C00)  /* Comp. B Int. Ref.1 Select 4 : 29/32 */
#define CBREF1_29           (0x1D00)  /* Comp. B Int. Ref.1 Select 5 : 30/32 */
#define CBREF1_30           (0x1E00)  /* Comp. B Int. Ref.1 Select 6 : 31/32 */
#define CBREF1_31           (0x1F00)  /* Comp. B Int. Ref.1 Select 7 : 32/32 */

#define CBREFL_0            (0x0000)  /* Comp. B Reference voltage level 0 : None */
#define CBREFL_1            (0x2000)  /* Comp. B Reference voltage level 1 : 1.5V */
#define CBREFL_2            (0x4000)  /* Comp. B Reference voltage level 2 : 2.0V  */
#define CBREFL_3            (0x6000)  /* Comp. B Reference voltage level 3 : 2.5V  */


#define CBPD0               (0x0001)  /* Comp. B Disable Input Buffer of Port Register .0 */
#define CBPD1               (0x0002)  /* Comp. B Disable Input Buffer of Port Register .1 */
#define CBPD2               (0x0004)  /* Comp. B Disable Input Buffer of Port Register .2 */
#define CBPD3               (0x0008)  /* Comp. B Disable Input Buffer of Port Register .3 */
#define CBPD4               (0x0010)  /* Comp. B Disable Input Buffer of Port Register .4 */
#define CBPD5               (0x0020)  /* Comp. B Disable Input Buffer of Port Register .5 */
#define CBPD6               (0x0040)  /* Comp. B Disable Input Buffer of Port Register .6 */
#define CBPD7               (0x0080)  /* Comp. B Disable Input Buffer of Port Register .7 */
#define CBPD8               (0x0100)  /* Comp. B Disable Input Buffer of Port Register .8 */
#define CBPD9               (0x0200)  /* Comp. B Disable Input Buffer of Port Register .9 */
#define CBPD10              (0x0400)  /* Comp. B Disable Input Buffer of Port Register .10 */
#define CBPD11              (0x0800)  /* Comp. B Disable Input Buffer of Port Register .11 */
#define CBPD12              (0x1000)  /* Comp. B Disable Input Buffer of Port Register .12 */
#define CBPD13              (0x2000)  /* Comp. B Disable Input Buffer of Port Register .13 */
#define CBPD14              (0x4000)  /* Comp. B Disable Input Buffer of Port Register .14 */
#define CBPD15              (0x8000)  /* Comp. B Disable Input Buffer of Port Register .15 */

#define CBPD0_L             (0x0001)  /* Comp. B Disable Input Buffer of Port Register .0 */
#define CBPD1_L             (0x0002)  /* Comp. B Disable Input Buffer of Port Register .1 */
#define CBPD2_L             (0x0004)  /* Comp. B Disable Input Buffer of Port Register .2 */
#define CBPD3_L             (0x0008)  /* Comp. B Disable Input Buffer of Port Register .3 */
#define CBPD4_L             (0x0010)  /* Comp. B Disable Input Buffer of Port Register .4 */
#define CBPD5_L             (0x0020)  /* Comp. B Disable Input Buffer of Port Register .5 */
#define CBPD6_L             (0x0040)  /* Comp. B Disable Input Buffer of Port Register .6 */
#define CBPD7_L             (0x0080)  /* Comp. B Disable Input Buffer of Port Register .7 */

#define CBPD8_H             (0x0001)  /* Comp. B Disable Input Buffer of Port Register .8 */
#define CBPD9_H             (0x0002)  /* Comp. B Disable Input Buffer of Port Register .9 */
#define CBPD10_H            (0x0004)  /* Comp. B Disable Input Buffer of Port Register .10 */
#define CBPD11_H            (0x0008)  /* Comp. B Disable Input Buffer of Port Register .11 */
#define CBPD12_H            (0x0010)  /* Comp. B Disable Input Buffer of Port Register .12 */
#define CBPD13_H            (0x0020)  /* Comp. B Disable Input Buffer of Port Register .13 */
#define CBPD14_H            (0x0040)  /* Comp. B Disable Input Buffer of Port Register .14 */
#define CBPD15_H            (0x0080)  /* Comp. B Disable Input Buffer of Port Register .15 */


/* CBINT Control Bits */
#define CBIFG                (0x0001)  /* Comp. B Interrupt Flag */
#define CBIIFG               (0x0002)  /* Comp. B Interrupt Flag Inverted Polarity */
//#define RESERVED             (0x0004)  /* Comp. B */
//#define RESERVED             (0x0008)  /* Comp. B */
//#define RESERVED             (0x0010)  /* Comp. B */
//#define RESERVED             (0x0020)  /* Comp. B */
//#define RESERVED             (0x0040)  /* Comp. B */
//#define RESERVED             (0x0080)  /* Comp. B */
#define CBIE                 (0x0100)  /* Comp. B Interrupt Enable */
#define CBIIE                (0x0200)  /* Comp. B Interrupt Enable Inverted Polarity */
//#define RESERVED             (0x0400)  /* Comp. B */
//#define RESERVED             (0x0800)  /* Comp. B */
//#define RESERVED             (0x1000)  /* Comp. B */
//#define RESERVED             (0x2000)  /* Comp. B */
//#define RESERVED             (0x4000)  /* Comp. B */
//#define RESERVED             (0x8000)  /* Comp. B */

/* CBINT Control Bits */
#define CBIFG_L             (0x0001)  /* Comp. B Interrupt Flag */
#define CBIIFG_L            (0x0002)  /* Comp. B Interrupt Flag Inverted Polarity */
//#define RESERVED             (0x0004)  /* Comp. B */
//#define RESERVED             (0x0008)  /* Comp. B */
//#define RESERVED             (0x0010)  /* Comp. B */
//#define RESERVED             (0x0020)  /* Comp. B */
//#define RESERVED             (0x0040)  /* Comp. B */
//#define RESERVED             (0x0080)  /* Comp. B */
//#define RESERVED             (0x0400)  /* Comp. B */
//#define RESERVED             (0x0800)  /* Comp. B */
//#define RESERVED             (0x1000)  /* Comp. B */
//#define RESERVED             (0x2000)  /* Comp. B */
//#define RESERVED             (0x4000)  /* Comp. B */
//#define RESERVED             (0x8000)  /* Comp. B */

/* CBINT Control Bits */
//#define RESERVED             (0x0004)  /* Comp. B */
//#define RESERVED             (0x0008)  /* Comp. B */
//#define RESERVED             (0x0010)  /* Comp. B */
//#define RESERVED             (0x0020)  /* Comp. B */
//#define RESERVED             (0x0040)  /* Comp. B */
//#define RESERVED             (0x0080)  /* Comp. B */
#define CBIE_H              (0x0001)  /* Comp. B Interrupt Enable */
#define CBIIE_H             (0x0002)  /* Comp. B Interrupt Enable Inverted Polarity */
//#define RESERVED             (0x0400)  /* Comp. B */
//#define RESERVED             (0x0800)  /* Comp. B */
//#define RESERVED             (0x1000)  /* Comp. B */
//#define RESERVED             (0x2000)  /* Comp. B */
//#define RESERVED             (0x4000)  /* Comp. B */
//#define RESERVED             (0x8000)  /* Comp. B */

/* CBIV Definitions */
#define CBIV_NONE           (0x0000)    /* No Interrupt pending */
#define CBIV_CBIFG          (0x0002)    /* CBIFG */
#define CBIV_CBIIFG         (0x0004)    /* CBIIFG */

#endif
/************************************************************
* CC1101 Radio Interface
************************************************************/
#ifdef  __MSP430_HAS_CC1101__          /* Definition to show that Module is available */

#define OFS_RF1AIFCTL0        (0x0000)  /* Radio interface control register 0 */
#define OFS_RF1AIFCTL0_L       OFS_RF1AIFCTL0
#define OFS_RF1AIFCTL0_H       OFS_RF1AIFCTL0+1
#define OFS_RF1AIFCTL1        (0x0002)  /* Radio interface control register 1 */
#define OFS_RF1AIFCTL1_L       OFS_RF1AIFCTL1
#define OFS_RF1AIFCTL1_H       OFS_RF1AIFCTL1+1
#define  RF1AIFIFG           RF1AIFCTL1_L  /* Radio interface interrupt flag register */
#define  RF1AIFIE            RF1AIFCTL1_H  /* Radio interface interrupt enable register */
#define OFS_RF1AIFCTL2        (0x0004)  /* (Radio interface control register 2) */
#define OFS_RF1AIFCTL2_L       OFS_RF1AIFCTL2
#define OFS_RF1AIFCTL2_H       OFS_RF1AIFCTL2+1
#define OFS_RF1AIFERR         (0x0006)  /* Radio interface error flag register */
#define OFS_RF1AIFERR_L        OFS_RF1AIFERR
#define OFS_RF1AIFERR_H        OFS_RF1AIFERR+1
#define OFS_RF1AIFERRV        (0x000C)  /* Radio interface error vector word register */
#define OFS_RF1AIFERRV_L       OFS_RF1AIFERRV
#define OFS_RF1AIFERRV_H       OFS_RF1AIFERRV+1
#define OFS_RF1AIFIV          (0x000E)  /* Radio interface interrupt vector word register */
#define OFS_RF1AIFIV_L         OFS_RF1AIFIV
#define OFS_RF1AIFIV_H         OFS_RF1AIFIV+1
#define OFS_RF1AINSTRW        (0x0010)  /* Radio instruction word register */
#define OFS_RF1AINSTRW_L       OFS_RF1AINSTRW
#define OFS_RF1AINSTRW_H       OFS_RF1AINSTRW+1
#define  RF1ADINB            RF1AINSTRW_L  /* Radio instruction byte register */
#define  RF1AINSTRB          RF1AINSTRW_H  /* Radio byte data in register */
#define OFS_RF1AINSTR1W       (0x0012)  /* Radio instruction 1-byte register with autoread */
#define OFS_RF1AINSTR1W_L      OFS_RF1AINSTR1W
#define OFS_RF1AINSTR1W_H      OFS_RF1AINSTR1W+1
#define  RF1AINSTR1B         RF1AINSTR1W_H /* Radio instruction 1-byte register with autoread */
#define OFS_RF1AINSTR2W       (0x0014)  /* Radio instruction 2-byte register with autoread */
#define OFS_RF1AINSTR2W_L      OFS_RF1AINSTR2W
#define OFS_RF1AINSTR2W_H      OFS_RF1AINSTR2W+1
#define  RF1AINSTR2B         RF1AINSTR1W_H /* Radio instruction 2-byte register with autoread */
#define OFS_RF1ADINW          (0x0016)  /* Radio word data in register */
#define OFS_RF1ADINW_L         OFS_RF1ADINW
#define OFS_RF1ADINW_H         OFS_RF1ADINW+1

#define OFS_RF1ASTAT0W        (0x0020)  /* Radio status word register without auto-read */
#define OFS_RF1ASTAT0W_L       OFS_RF1ASTAT0W
#define OFS_RF1ASTAT0W_H       OFS_RF1ASTAT0W+1
#define  RF1ADOUT0B          RF1ASTAT0W_L /* Radio byte data out register without auto-read */
#define  RF1ASTAT0B          RF1ASTAT0W_H /* Radio status byte register without auto-read */
#define  RF1ASTATW           RF1ASTAT0W   /* Radio status word register without auto-read */
#define  RF1ADOUTB           RF1ASTAT0W_L /* Radio byte data out register without auto-read */
#define  RF1ASTATB           RF1ASTAT0W_H /* Radio status byte register without auto-read */
#define OFS_RF1ASTAT1W        (0x0022)  /* Radio status word register with 1-byte auto-read */
#define OFS_RF1ASTAT1W_L       OFS_RF1ASTAT1W
#define OFS_RF1ASTAT1W_H       OFS_RF1ASTAT1W+1
#define  RF1ADOUT1B          RF1ASTAT1W_L /* Radio byte data out register with 1-byte auto-read */
#define  RF1ASTAT1B          RF1ASTAT1W_H /* Radio status byte register with 1-byte auto-read */
#define OFS_RF1ASTAT2W        (0x0024)  /* Radio status word register with 2-byte auto-read */
#define OFS_RF1ASTAT2W_L       OFS_RF1ASTAT2W
#define OFS_RF1ASTAT2W_H       OFS_RF1ASTAT2W+1
#define  RF1ADOUT2B          RF1ASTAT2W_L /* Radio byte data out register with 2-byte auto-read */
#define  RF1ASTAT2B          RF1ASTAT2W_H /* Radio status byte register with 2-byte auto-read */
#define OFS_RF1ADOUT0W        (0x0028)  /* Radio core word data out register without auto-read */
#define OFS_RF1ADOUT0W_L       OFS_RF1ADOUT0W
#define OFS_RF1ADOUT0W_H       OFS_RF1ADOUT0W+1
#define  RF1ADOUTW           RF1ADOUT0W   /* Radio core word data out register without auto-read */
#define  RF1ADOUTW_L         RF1ADOUT0W_L /* Radio core word data out register without auto-read */
#define  RF1ADOUTW_H         RF1ADOUT0W_H /* Radio core word data out register without auto-read */
#define OFS_RF1ADOUT1W        (0x002A)  /* Radio core word data out register with 1-byte auto-read */
#define OFS_RF1ADOUT1W_L       OFS_RF1ADOUT1W
#define OFS_RF1ADOUT1W_H       OFS_RF1ADOUT1W+1
#define OFS_RF1ADOUT2W        (0x002C)  /* Radio core word data out register with 2-byte auto-read */
#define OFS_RF1ADOUT2W_L       OFS_RF1ADOUT2W
#define OFS_RF1ADOUT2W_H       OFS_RF1ADOUT2W+1
#define OFS_RF1AIN            (0x0030)  /* Radio core signal input register */
#define OFS_RF1AIN_L           OFS_RF1AIN
#define OFS_RF1AIN_H           OFS_RF1AIN+1
#define OFS_RF1AIFG           (0x0032)  /* Radio core interrupt flag register */
#define OFS_RF1AIFG_L          OFS_RF1AIFG
#define OFS_RF1AIFG_H          OFS_RF1AIFG+1
#define OFS_RF1AIES           (0x0034)  /* Radio core interrupt edge select register */
#define OFS_RF1AIES_L          OFS_RF1AIES
#define OFS_RF1AIES_H          OFS_RF1AIES+1
#define OFS_RF1AIE            (0x0036)  /* Radio core interrupt enable register */
#define OFS_RF1AIE_L           OFS_RF1AIE
#define OFS_RF1AIE_H           OFS_RF1AIE+1
#define OFS_RF1AIV            (0x0038)  /* Radio core interrupt vector word register */
#define OFS_RF1AIV_L           OFS_RF1AIV
#define OFS_RF1AIV_H           OFS_RF1AIV+1
#define OFS_RF1ARXFIFO        (0x003C)  /* Direct receive FIFO access register */
#define OFS_RF1ARXFIFO_L       OFS_RF1ARXFIFO
#define OFS_RF1ARXFIFO_H       OFS_RF1ARXFIFO+1
#define OFS_RF1ATXFIFO        (0x003E)  /* Direct transmit FIFO access register */
#define OFS_RF1ATXFIFO_L       OFS_RF1ATXFIFO
#define OFS_RF1ATXFIFO_H       OFS_RF1ATXFIFO+1


/* RF1AIFCTL0 Control Bits */
#define RFFIFOEN            (0x0001)  /* CC1101 Direct FIFO access enable */
#define RFENDIAN            (0x0002)  /* CC1101 Disable endianness conversion */

/* RF1AIFCTL0 Control Bits */
#define RFFIFOEN_L          (0x0001)  /* CC1101 Direct FIFO access enable */
#define RFENDIAN_L          (0x0002)  /* CC1101 Disable endianness conversion */


/* RF1AIFCTL1 Control Bits */
#define RFRXIFG             (0x0001)  /* Radio interface direct FIFO access receive interrupt flag */
#define RFTXIFG             (0x0002)  /* Radio interface direct FIFO access transmit interrupt flag */
#define RFERRIFG            (0x0004)  /* Radio interface error interrupt flag */
#define RFINSTRIFG          (0x0010)  /* Radio interface instruction interrupt flag */
#define RFDINIFG            (0x0020)  /* Radio interface data in interrupt flag */
#define RFSTATIFG           (0x0040)  /* Radio interface status interrupt flag */
#define RFDOUTIFG           (0x0080)  /* Radio interface data out interrupt flag */
#define RFRXIE              (0x0100)  /* Radio interface direct FIFO access receive interrupt enable */
#define RFTXIE              (0x0200)  /* Radio interface direct FIFO access transmit interrupt enable */
#define RFERRIE             (0x0400)  /* Radio interface error interrupt enable */
#define RFINSTRIE           (0x1000)  /* Radio interface instruction interrupt enable */
#define RFDINIE             (0x2000)  /* Radio interface data in interrupt enable */
#define RFSTATIE            (0x4000)  /* Radio interface status interrupt enable */
#define RFDOUTIE            (0x8000)  /* Radio interface data out interrupt enable */

/* RF1AIFCTL1 Control Bits */
#define RFRXIFG_L           (0x0001)  /* Radio interface direct FIFO access receive interrupt flag */
#define RFTXIFG_L           (0x0002)  /* Radio interface direct FIFO access transmit interrupt flag */
#define RFERRIFG_L          (0x0004)  /* Radio interface error interrupt flag */
#define RFINSTRIFG_L        (0x0010)  /* Radio interface instruction interrupt flag */
#define RFDINIFG_L          (0x0020)  /* Radio interface data in interrupt flag */
#define RFSTATIFG_L         (0x0040)  /* Radio interface status interrupt flag */
#define RFDOUTIFG_L         (0x0080)  /* Radio interface data out interrupt flag */

/* RF1AIFCTL1 Control Bits */
#define RFRXIE_H            (0x0001)  /* Radio interface direct FIFO access receive interrupt enable */
#define RFTXIE_H            (0x0002)  /* Radio interface direct FIFO access transmit interrupt enable */
#define RFERRIE_H           (0x0004)  /* Radio interface error interrupt enable */
#define RFINSTRIE_H         (0x0010)  /* Radio interface instruction interrupt enable */
#define RFDINIE_H           (0x0020)  /* Radio interface data in interrupt enable */
#define RFSTATIE_H          (0x0040)  /* Radio interface status interrupt enable */
#define RFDOUTIE_H          (0x0080)  /* Radio interface data out interrupt enable */

/* RF1AIFERR Control Bits */
#define LVERR               (0x0001)  /* Low Core Voltage Error Flag */
#define OPERR               (0x0002)  /* Operand Error Flag */
#define OUTERR              (0x0004)  /* Output data not available Error Flag */
#define OPOVERR             (0x0008)  /* Operand Overwrite Error Flag */

/* RF1AIFERR Control Bits */
#define LVERR_L             (0x0001)  /* Low Core Voltage Error Flag */
#define OPERR_L             (0x0002)  /* Operand Error Flag */
#define OUTERR_L            (0x0004)  /* Output data not available Error Flag */
#define OPOVERR_L           (0x0008)  /* Operand Overwrite Error Flag */


/* RF1AIFERRV Definitions */
#define RF1AIFERRV_NONE     (0x0000)  /* No Error pending */
#define RF1AIFERRV_LVERR    (0x0002)  /* Low core voltage error */
#define RF1AIFERRV_OPERR    (0x0004)  /* Operand Error */
#define RF1AIFERRV_OUTERR   (0x0006)  /* Output data not available Error */
#define RF1AIFERRV_OPOVERR  (0x0008)  /* Operand Overwrite Error */

/* RF1AIFIV Definitions */
#define RF1AIFIV_NONE       (0x0000)  /* No Interrupt pending */
#define RF1AIFIV_RFERRIFG   (0x0002)  /* Radio interface error */
#define RF1AIFIV_RFDOUTIFG  (0x0004)  /* Radio i/f data out */
#define RF1AIFIV_RFSTATIFG  (0x0006)  /* Radio i/f status out */
#define RF1AIFIV_RFDINIFG   (0x0008)  /* Radio i/f data in */
#define RF1AIFIV_RFINSTRIFG (0x000A)  /* Radio i/f instruction in */

/* RF1AIV Definitions */
#define RF1AIV_NONE         (0x0000)  /* No Interrupt pending */
#define RF1AIV_RFIFG0       (0x0002)  /* RFIFG0 */
#define RF1AIV_RFIFG1       (0x0004)  /* RFIFG1 */
#define RF1AIV_RFIFG2       (0x0006)  /* RFIFG2 */
#define RF1AIV_RFIFG3       (0x0008)  /* RFIFG3 */
#define RF1AIV_RFIFG4       (0x000A)  /* RFIFG4 */
#define RF1AIV_RFIFG5       (0x000C)  /* RFIFG5 */
#define RF1AIV_RFIFG6       (0x000E)  /* RFIFG6 */
#define RF1AIV_RFIFG7       (0x0010)  /* RFIFG7 */
#define RF1AIV_RFIFG8       (0x0012)  /* RFIFG8 */
#define RF1AIV_RFIFG9       (0x0014)  /* RFIFG9 */
#define RF1AIV_RFIFG10      (0x0016)  /* RFIFG10 */
#define RF1AIV_RFIFG11      (0x0018)  /* RFIFG11 */
#define RF1AIV_RFIFG12      (0x001A)  /* RFIFG12 */
#define RF1AIV_RFIFG13      (0x001C)  /* RFIFG13 */
#define RF1AIV_RFIFG14      (0x001E)  /* RFIFG14 */
#define RF1AIV_RFIFG15      (0x0020)  /* RFIFG15 */


// Radio Core Registers
#define IOCFG2              0x00      /*  IOCFG2   - GDO2 output pin configuration  */
#define IOCFG1              0x01      /*  IOCFG1   - GDO1 output pin configuration  */
#define IOCFG0              0x02      /*  IOCFG1   - GDO0 output pin configuration  */
#define FIFOTHR             0x03      /*  FIFOTHR  - RX FIFO and TX FIFO thresholds */
#define SYNC1               0x04      /*  SYNC1    - Sync word, high byte */
#define SYNC0               0x05      /*  SYNC0    - Sync word, low byte */
#define PKTLEN              0x06      /*  PKTLEN   - Packet length */
#define PKTCTRL1            0x07      /*  PKTCTRL1 - Packet automation control */
#define PKTCTRL0            0x08      /*  PKTCTRL0 - Packet automation control */
#define ADDR                0x09      /*  ADDR     - Device address */
#define CHANNR              0x0A      /*  CHANNR   - Channel number */
#define FSCTRL1             0x0B      /*  FSCTRL1  - Frequency synthesizer control */
#define FSCTRL0             0x0C      /*  FSCTRL0  - Frequency synthesizer control */
#define FREQ2               0x0D      /*  FREQ2    - Frequency control word, high byte */
#define FREQ1               0x0E      /*  FREQ1    - Frequency control word, middle byte */
#define FREQ0               0x0F      /*  FREQ0    - Frequency control word, low byte */
#define MDMCFG4             0x10      /*  MDMCFG4  - Modem configuration */
#define MDMCFG3             0x11      /*  MDMCFG3  - Modem configuration */
#define MDMCFG2             0x12      /*  MDMCFG2  - Modem configuration */
#define MDMCFG1             0x13      /*  MDMCFG1  - Modem configuration */
#define MDMCFG0             0x14      /*  MDMCFG0  - Modem configuration */
#define DEVIATN             0x15      /*  DEVIATN  - Modem deviation setting */
#define MCSM2               0x16      /*  MCSM2    - Main Radio Control State Machine configuration */
#define MCSM1               0x17      /*  MCSM1    - Main Radio Control State Machine configuration */
#define MCSM0               0x18      /*  MCSM0    - Main Radio Control State Machine configuration */
#define FOCCFG              0x19      /*  FOCCFG   - Frequency Offset Compensation configuration */
#define BSCFG               0x1A      /*  BSCFG    - Bit Synchronization configuration */
#define AGCCTRL2            0x1B      /*  AGCCTRL2 - AGC control */
#define AGCCTRL1            0x1C      /*  AGCCTRL1 - AGC control */
#define AGCCTRL0            0x1D      /*  AGCCTRL0 - AGC control */
#define WOREVT1             0x1E      /*  WOREVT1  - High byte Event0 timeout */
#define WOREVT0             0x1F      /*  WOREVT0  - Low byte Event0 timeout */
#define WORCTRL             0x20      /*  WORCTRL  - Wake On Radio control */
#define FREND1              0x21      /*  FREND1   - Front end RX configuration */
#define FREND0              0x22      /*  FREDN0   - Front end TX configuration */
#define FSCAL3              0x23      /*  FSCAL3   - Frequency synthesizer calibration */
#define FSCAL2              0x24      /*  FSCAL2   - Frequency synthesizer calibration */
#define FSCAL1              0x25      /*  FSCAL1   - Frequency synthesizer calibration */
#define FSCAL0              0x26      /*  FSCAL0   - Frequency synthesizer calibration */
//#define RCCTRL1             0x27      /*  RCCTRL1  - RC oscillator configuration */
//#define RCCTRL0             0x28      /*  RCCTRL0  - RC oscillator configuration */
#define FSTEST              0x29      /*  FSTEST   - Frequency synthesizer calibration control */
#define PTEST               0x2A      /*  PTEST    - Production test */
#define AGCTEST             0x2B      /*  AGCTEST  - AGC test */
#define TEST2               0x2C      /*  TEST2    - Various test settings */
#define TEST1               0x2D      /*  TEST1    - Various test settings */
#define TEST0               0x2E      /*  TEST0    - Various test settings */

/* status registers */
#define PARTNUM             0x30      /*  PARTNUM    - Chip ID */
#define VERSION             0x31      /*  VERSION    - Chip ID */
#define FREQEST             0x32      /*  FREQEST    – Frequency Offset Estimate from demodulator */
#define LQI                 0x33      /*  LQI        – Demodulator estimate for Link Quality */
#define RSSI                0x34      /*  RSSI       – Received signal strength indication */
#define MARCSTATE           0x35      /*  MARCSTATE  – Main Radio Control State Machine state */
#define WORTIME1            0x36      /*  WORTIME1   – High byte of WOR time */
#define WORTIME0            0x37      /*  WORTIME0   – Low byte of WOR time */
#define PKTSTATUS           0x38      /*  PKTSTATUS  – Current GDOx status and packet status */
#define VCO_VC_DAC          0x39      /*  VCO_VC_DAC – Current setting from PLL calibration module */
#define TXBYTES             0x3A      /*  TXBYTES    – Underflow and number of bytes */
#define RXBYTES             0x3B      /*  RXBYTES    – Overflow and number of bytes */

/* burst write registers */
#define PATABLE             0x3E      /*  PATABLE - PA control settings table */
#define TXFIFO              0x3F      /*  TXFIFO  - Transmit FIFO */
#define RXFIFO              0x3F      /*  RXFIFO  - Receive FIFO */


/* Radio Core Instructions */
/* command strobes               */
#define RF_SRES             0x30      /*  SRES    - Reset chip. */
#define RF_SFSTXON          0x31      /*  SFSTXON - Enable and calibrate frequency synthesizer. */
#define RF_SXOFF            0x32      /*  SXOFF   - Turn off crystal oscillator. */
#define RF_SCAL             0x33      /*  SCAL    - Calibrate frequency synthesizer and turn it off. */
#define RF_SRX              0x34      /*  SRX     - Enable RX. Perform calibration if enabled. */
#define RF_STX              0x35      /*  STX     - Enable TX. If in RX state, only enable TX if CCA passes. */
#define RF_SIDLE            0x36      /*  SIDLE   - Exit RX / TX, turn off frequency synthesizer. */
//#define RF_SRSVD            0x37      /*  SRVSD   - Reserved.  Do not use. */
#define RF_SWOR             0x38      /*  SWOR    - Start automatic RX polling sequence (Wake-on-Radio) */
#define RF_SPWD             0x39      /*  SPWD    - Enter power down mode when CSn goes high. */
#define RF_SFRX             0x3A      /*  SFRX    - Flush the RX FIFO buffer. */
#define RF_SFTX             0x3B      /*  SFTX    - Flush the TX FIFO buffer. */
#define RF_SWORRST          0x3C      /*  SWORRST - Reset real time clock. */
#define RF_SNOP             0x3D      /*  SNOP    - No operation. Returns status byte. */

#define RF_RXSTAT           0x80      /* Used in combination with strobe commands delivers number of availabe bytes in RX FIFO with return status */
#define RF_TXSTAT           0x00      /* Used in combination with strobe commands delivers number of availabe bytes in TX FIFO with return status */


/* other radio instr */
#define RF_SNGLREGRD        0x80
#define RF_SNGLREGWR        0x00
#define RF_REGRD            0xC0
#define RF_REGWR            0x40
#define RF_STATREGRD        0xC0      /* Read single radio core status register */
#define RF_SNGLPATABRD      (RF_SNGLREGRD+PATABLE)
#define RF_SNGLPATABWR      (RF_SNGLREGWR+PATABLE)
#define RF_PATABRD          (RF_REGRD+PATABLE)
#define RF_PATABWR          (RF_REGWR+PATABLE)
#define RF_SNGLRXRD         (RF_SNGLREGRD+RXFIFO)
#define RF_SNGLTXWR         (RF_SNGLREGWR+TXFIFO)
#define RF_RXFIFORD         (RF_REGRD+RXFIFO)
#define RF_TXFIFOWR         (RF_REGWR+TXFIFO)

#endif
/*************************************************************
* CRC Module
*************************************************************/
#ifdef  __MSP430_HAS_CRC__            /* Definition to show that Module is available */

#define OFS_CRCDI             (0x0000)  /* CRC Data In Register */
#define OFS_CRCDI_L            OFS_CRCDI
#define OFS_CRCDI_H            OFS_CRCDI+1
#define OFS_CRCDIRB           (0x0002)  /* CRC data in reverse byte Register */
#define OFS_CRCDIRB_L          OFS_CRCDIRB
#define OFS_CRCDIRB_H          OFS_CRCDIRB+1
#define OFS_CRCINIRES         (0x0004)  /* CRC Initialisation Register and Result Register */
#define OFS_CRCINIRES_L        OFS_CRCINIRES
#define OFS_CRCINIRES_H        OFS_CRCINIRES+1
#define OFS_CRCRESR           (0x0006)  /* CRC reverse result Register */
#define OFS_CRCRESR_L          OFS_CRCRESR
#define OFS_CRCRESR_H          OFS_CRCRESR+1

#endif
/************************************************************
* DAC12
************************************************************/
#ifdef  __MSP430_HAS_DAC12_2__          /* Definition to show that Module is available */

#define OFS_DAC12_0CTL0       (0x0000)    /* DAC12_0 Control Register 0 */
#define OFS_DAC12_0CTL1       (0x0002)    /* DAC12_0 Control Register 1 */
#define OFS_DAC12_0DAT        (0x0004)    /* DAC12_0 Data */
#define OFS_DAC12_0CALCTL     (0x0006)    /* DAC12_0 Calibration Control Register */
#define OFS_DAC12_0CALDAT     (0x0008)    /* DAC12_0 Calibration Data Register */
#define OFS_DAC12_1CTL0       (0x0010)    /* DAC12_1 Control Register 0 */
#define OFS_DAC12_1CTL1       (0x0012)    /* DAC12_1 Control Register 1 */
#define OFS_DAC12_1DAT        (0x0014)    /* DAC12_1 Data */
#define OFS_DAC12_1CALCTL     (0x0016)    /* DAC12_1 Calibration Control Register */
#define OFS_DAC12_1CALDAT     (0x0018)    /* DAC12_1 Calibration Data Register */
#define OFS_DAC12_IV          (0x001E)    /* DAC12   Interrupt Vector Word */

/* DAC12_xCTL0 Control Bits */
#define DAC12GRP            (0x0001)    /* DAC12 group */
#define DAC12ENC            (0x0002)    /* DAC12 enable conversion */
#define DAC12IFG            (0x0004)    /* DAC12 interrupt flag */
#define DAC12IE             (0x0008)    /* DAC12 interrupt enable */
#define DAC12DF             (0x0010)    /* DAC12 data format */
#define DAC12AMP0           (0x0020)    /* DAC12 amplifier bit 0 */
#define DAC12AMP1           (0x0040)    /* DAC12 amplifier bit 1 */
#define DAC12AMP2           (0x0080)    /* DAC12 amplifier bit 2 */
#define DAC12IR             (0x0100)    /* DAC12 input reference and output range */
#define DAC12CALON          (0x0200)    /* DAC12 calibration */
#define DAC12LSEL0          (0x0400)    /* DAC12 load select bit 0 */
#define DAC12LSEL1          (0x0800)    /* DAC12 load select bit 1 */
#define DAC12RES            (0x1000)    /* DAC12 resolution */
#define DAC12SREF0          (0x2000)    /* DAC12 reference bit 0 */
#define DAC12SREF1          (0x4000)    /* DAC12 reference bit 1 */
#define DAC12OPS            (0x8000)    /* DAC12 Operation Amp. */

#define DAC12AMP_0          (0x0000)  /* DAC12 amplifier 0: off,    3-state */
#define DAC12AMP_1          (0x0020)  /* DAC12 amplifier 1: off,    off */
#define DAC12AMP_2          (0x0040)  /* DAC12 amplifier 2: low,    low */
#define DAC12AMP_3          (0x0060)  /* DAC12 amplifier 3: low,    medium */
#define DAC12AMP_4          (0x0080)  /* DAC12 amplifier 4: low,    high */
#define DAC12AMP_5          (0x00A0)  /* DAC12 amplifier 5: medium, medium */
#define DAC12AMP_6          (0x00C0)  /* DAC12 amplifier 6: medium, high */
#define DAC12AMP_7          (0x00E0)  /* DAC12 amplifier 7: high,   high */

#define DAC12LSEL_0         (0x0000)  /* DAC12 load select 0: direct */
#define DAC12LSEL_1         (0x0400)  /* DAC12 load select 1: latched with DAT */
#define DAC12LSEL_2         (0x0800)  /* DAC12 load select 2: latched with pos. Timer_A3.OUT1 */
#define DAC12LSEL_3         (0x0C00)  /* DAC12 load select 3: latched with pos. Timer_B7.OUT1 */

#define DAC12SREF_0         (0x0000)  /* DAC12 reference 0: Vref+ */
#define DAC12SREF_1         (0x2000)  /* DAC12 reference 1: Vref+ */
#define DAC12SREF_2         (0x4000)  /* DAC12 reference 2: Veref+ */
#define DAC12SREF_3         (0x6000)  /* DAC12 reference 3: Veref+ */


/* DAC12_xCTL1 Control Bits */
#define DAC12DFJ            (0x0001)    /* DAC12 Data Format Justification */
#define DAC12OG             (0x0002)    /* DAC12 output buffer gain: 0: 3x gain / 1: 2x gain */

/* DAC12_xCALCTL Control Bits */
#define DAC12LOCK           (0x0001)    /* DAC12 Calibration Lock */

#define DAC12PW             (0xA500)    /* DAC12 Calibration Register write Password */

/* DACIV Definitions */
#define DACIV_NONE          (0x0000)    /* No Interrupt pending */
#define DACIV_DAC12IFG_0    (0x0002)    /* DAC12IFG_0 */
#define DACIV_DAC12IFG_1    (0x0004)    /* DAC12IFG_1 */

#endif
/************************************************************
* DMA_X
************************************************************/
#ifdef  __MSP430_HAS_DMAX_3__           /* Definition to show that Module is available */

#define OFS_DMACTL0           (0x0000)    /* DMA Module Control 0 */
#define OFS_DMACTL0_L          OFS_DMACTL0
#define OFS_DMACTL0_H          OFS_DMACTL0+1
#define OFS_DMACTL1           (0x0002)    /* DMA Module Control 1 */
#define OFS_DMACTL1_L          OFS_DMACTL1
#define OFS_DMACTL1_H          OFS_DMACTL1+1
#define OFS_DMACTL2           (0x0004)    /* DMA Module Control 2 */
#define OFS_DMACTL2_L          OFS_DMACTL2
#define OFS_DMACTL2_H          OFS_DMACTL2+1
#define OFS_DMACTL3           (0x0006)    /* DMA Module Control 3 */
#define OFS_DMACTL3_L          OFS_DMACTL3
#define OFS_DMACTL3_H          OFS_DMACTL3+1
#define OFS_DMACTL4           (0x0008)    /* DMA Module Control 4 */
#define OFS_DMACTL4_L          OFS_DMACTL4
#define OFS_DMACTL4_H          OFS_DMACTL4+1
#define OFS_DMAIV             (0x000E)    /* DMA Interrupt Vector Word */
#define OFS_DMAIV_L            OFS_DMAIV
#define OFS_DMAIV_H            OFS_DMAIV+1

#define OFS_DMA0CTL           (0x0010)    /* DMA Channel 0 Control */
#define OFS_DMA0CTL_L          OFS_DMA0CTL
#define OFS_DMA0CTL_H          OFS_DMA0CTL+1
#define OFS_DMA0SA            (0x0012)    /* DMA Channel 0 Source Address */
#define OFS_DMA0DA            (0x0016)    /* DMA Channel 0 Destination Address */
#define OFS_DMA0SZ            (0x001A)    /* DMA Channel 0 Transfer Size */

#define OFS_DMA1CTL           (0x0020)    /* DMA Channel 1 Control */
#define OFS_DMA1CTL_L          OFS_DMA1CTL
#define OFS_DMA1CTL_H          OFS_DMA1CTL+1
#define OFS_DMA1SA            (0x0022)    /* DMA Channel 1 Source Address */
#define OFS_DMA1DA            (0x0026)    /* DMA Channel 1 Destination Address */
#define OFS_DMA1SZ            (0x002A)    /* DMA Channel 1 Transfer Size */

#define OFS_DMA2CTL           (0x0030)    /* DMA Channel 2 Control */
#define OFS_DMA2CTL_L          OFS_DMA2CTL
#define OFS_DMA2CTL_H          OFS_DMA2CTL+1
#define OFS_DMA2SA            (0x0032)    /* DMA Channel 2 Source Address */
#define OFS_DMA2DA            (0x0036)    /* DMA Channel 2 Destination Address */
#define OFS_DMA2SZ            (0x003A)    /* DMA Channel 2 Transfer Size */

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

#endif
/************************************************************
* DMA_X
************************************************************/
#ifdef  __MSP430_HAS_DMAX_6__           /* Definition to show that Module is available */

#define OFS_DMACTL0           (0x0000)    /* DMA Module Control 0 */
#define OFS_DMACTL0_L          OFS_DMACTL0
#define OFS_DMACTL0_H          OFS_DMACTL0+1
#define OFS_DMACTL1           (0x0002)    /* DMA Module Control 1 */
#define OFS_DMACTL1_L          OFS_DMACTL1
#define OFS_DMACTL1_H          OFS_DMACTL1+1
#define OFS_DMACTL2           (0x0004)    /* DMA Module Control 2 */
#define OFS_DMACTL2_L          OFS_DMACTL2
#define OFS_DMACTL2_H          OFS_DMACTL2+1
#define OFS_DMACTL3           (0x0006)    /* DMA Module Control 3 */
#define OFS_DMACTL3_L          OFS_DMACTL3
#define OFS_DMACTL3_H          OFS_DMACTL3+1
#define OFS_DMACTL4           (0x0008)    /* DMA Module Control 4 */
#define OFS_DMACTL4_L          OFS_DMACTL4
#define OFS_DMACTL4_H          OFS_DMACTL4+1
#define OFS_DMAIV             (0x000E)    /* DMA Interrupt Vector Word */
#define OFS_DMAIV_L            OFS_DMAIV
#define OFS_DMAIV_H            OFS_DMAIV+1

#define OFS_DMA0CTL           (0x0010)    /* DMA Channel 0 Control */
#define OFS_DMA0CTL_L          OFS_DMA0CTL
#define OFS_DMA0CTL_H          OFS_DMA0CTL+1
#define OFS_DMA0SA            (0x0012)    /* DMA Channel 0 Source Address */
#define OFS_DMA0DA            (0x0016)    /* DMA Channel 0 Destination Address */
#define OFS_DMA0SZ            (0x001A)    /* DMA Channel 0 Transfer Size */

#define OFS_DMA1CTL           (0x0020)    /* DMA Channel 1 Control */
#define OFS_DMA1CTL_L          OFS_DMA1CTL
#define OFS_DMA1CTL_H          OFS_DMA1CTL+1
#define OFS_DMA1SA            (0x0022)    /* DMA Channel 1 Source Address */
#define OFS_DMA1DA            (0x0026)    /* DMA Channel 1 Destination Address */
#define OFS_DMA1SZ            (0x002A)    /* DMA Channel 1 Transfer Size */

#define OFS_DMA2CTL           (0x0030)    /* DMA Channel 2 Control */
#define OFS_DMA2CTL_L          OFS_DMA2CTL
#define OFS_DMA2CTL_H          OFS_DMA2CTL+1
#define OFS_DMA2SA            (0x0032)    /* DMA Channel 2 Source Address */
#define OFS_DMA2DA            (0x0036)    /* DMA Channel 2 Destination Address */
#define OFS_DMA2SZ            (0x003A)    /* DMA Channel 2 Transfer Size */

#define OFS_DMA3CTL           (0x0040)    /* DMA Channel 3 Control */
#define OFS_DMA3CTL_L          OFS_DMA3CTL
#define OFS_DMA3CTL_H          OFS_DMA3CTL+1
#define OFS_DMA3SA            (0x0042)    /* DMA Channel 3 Source Address */
#define OFS_DMA3DA            (0x0046)    /* DMA Channel 3 Destination Address */
#define OFS_DMA3SZ            (0x004A)    /* DMA Channel 3 Transfer Size */

#define OFS_DMA4CTL           (0x0050)    /* DMA Channel 4 Control */
#define OFS_DMA4CTL_L          OFS_DMA4CTL
#define OFS_DMA4CTL_H          OFS_DMA4CTL+1
#define OFS_DMA4SA            (0x0052)    /* DMA Channel 4 Source Address */
#define OFS_DMA4DA            (0x0056)    /* DMA Channel 4 Destination Address */
#define OFS_DMA4SZ            (0x005A)    /* DMA Channel 4 Transfer Size */

#define OFS_DMA5CTL           (0x0060)    /* DMA Channel 5 Control */
#define OFS_DMA5CTL_L          OFS_DMA5CTL
#define OFS_DMA5CTL_H          OFS_DMA5CTL+1
#define OFS_DMA5SA            (0x0062)    /* DMA Channel 5 Source Address */
#define OFS_DMA5DA            (0x0066)    /* DMA Channel 5 Destination Address */
#define OFS_DMA5SZ            (0x006A)    /* DMA Channel 5 Transfer Size */

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
#define DMA3TSEL0           (0x0100)    /* DMA channel 3 transfer select bit 0 */
#define DMA3TSEL1           (0x0200)    /* DMA channel 3 transfer select bit 1 */
#define DMA3TSEL2           (0x0400)    /* DMA channel 3 transfer select bit 2 */
#define DMA3TSEL3           (0x0800)    /* DMA channel 3 transfer select bit 3 */
#define DMA3TSEL4           (0x1000)    /* DMA channel 3 transfer select bit 4 */

/* DMACTL01 Control Bits */
#define DMA2TSEL0_L         (0x0001)    /* DMA channel 2 transfer select bit 0 */
#define DMA2TSEL1_L         (0x0002)    /* DMA channel 2 transfer select bit 1 */
#define DMA2TSEL2_L         (0x0004)    /* DMA channel 2 transfer select bit 2 */
#define DMA2TSEL3_L         (0x0008)    /* DMA channel 2 transfer select bit 3 */
#define DMA2TSEL4_L         (0x0010)    /* DMA channel 2 transfer select bit 4 */

/* DMACTL01 Control Bits */
#define DMA3TSEL0_H         (0x0001)    /* DMA channel 3 transfer select bit 0 */
#define DMA3TSEL1_H         (0x0002)    /* DMA channel 3 transfer select bit 1 */
#define DMA3TSEL2_H         (0x0004)    /* DMA channel 3 transfer select bit 2 */
#define DMA3TSEL3_H         (0x0008)    /* DMA channel 3 transfer select bit 3 */
#define DMA3TSEL4_H         (0x0010)    /* DMA channel 3 transfer select bit 4 */

/* DMACTL0 Control Bits */
#define DMA4TSEL0           (0x0001)    /* DMA channel 4 transfer select bit 0 */
#define DMA4TSEL1           (0x0002)    /* DMA channel 4 transfer select bit 1 */
#define DMA4TSEL2           (0x0004)    /* DMA channel 4 transfer select bit 2 */
#define DMA4TSEL3           (0x0008)    /* DMA channel 4 transfer select bit 3 */
#define DMA4TSEL4           (0x0010)    /* DMA channel 4 transfer select bit 4 */
#define DMA5TSEL0           (0x0100)    /* DMA channel 5 transfer select bit 0 */
#define DMA5TSEL1           (0x0200)    /* DMA channel 5 transfer select bit 1 */
#define DMA5TSEL2           (0x0400)    /* DMA channel 5 transfer select bit 2 */
#define DMA5TSEL3           (0x0800)    /* DMA channel 5 transfer select bit 3 */
#define DMA5TSEL4           (0x1000)    /* DMA channel 5 transfer select bit 4 */

/* DMACTL0 Control Bits */
#define DMA4TSEL0_L         (0x0001)    /* DMA channel 4 transfer select bit 0 */
#define DMA4TSEL1_L         (0x0002)    /* DMA channel 4 transfer select bit 1 */
#define DMA4TSEL2_L         (0x0004)    /* DMA channel 4 transfer select bit 2 */
#define DMA4TSEL3_L         (0x0008)    /* DMA channel 4 transfer select bit 3 */
#define DMA4TSEL4_L         (0x0010)    /* DMA channel 4 transfer select bit 4 */

/* DMACTL0 Control Bits */
#define DMA5TSEL0_H         (0x0001)    /* DMA channel 5 transfer select bit 0 */
#define DMA5TSEL1_H         (0x0002)    /* DMA channel 5 transfer select bit 1 */
#define DMA5TSEL2_H         (0x0004)    /* DMA channel 5 transfer select bit 2 */
#define DMA5TSEL3_H         (0x0008)    /* DMA channel 5 transfer select bit 3 */
#define DMA5TSEL4_H         (0x0010)    /* DMA channel 5 transfer select bit 4 */

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
#define DMAIV_DMA3IFG        (0x0008)    /* DMA3IFG*/
#define DMAIV_DMA4IFG        (0x000A)    /* DMA4IFG*/
#define DMAIV_DMA5IFG        (0x000C)    /* DMA5IFG*/

#endif
/*************************************************************
* Flash Memory
*************************************************************/
#ifdef  __MSP430_HAS_FLASH__         /* Definition to show that Module is available */

#define OFS_FCTL1             (0x0000)  /* FLASH Control 1 */
#define OFS_FCTL1_L            OFS_FCTL1
#define OFS_FCTL1_H            OFS_FCTL1+1
//#define    FCTL2_O               (0x0002)  /* FLASH Control 2 */
#define OFS_FCTL3             (0x0004)  /* FLASH Control 3 */
#define OFS_FCTL3_L            OFS_FCTL3
#define OFS_FCTL3_H            OFS_FCTL3+1
#define OFS_FCTL4             (0x0006)  /* FLASH Control 4 */
#define OFS_FCTL4_L            OFS_FCTL4
#define OFS_FCTL4_H            OFS_FCTL4+1

#define FRPW                (0x9600)  /* Flash password returned by read */
#define FWPW                (0xA500)  /* Flash password for write */
#define FXPW                (0x3300)  /* for use with XOR instruction */
#define FRKEY               (0x9600)  /* (legacy definition) Flash key returned by read */
#define FWKEY               (0xA500)  /* (legacy definition) Flash key for write */
#define FXKEY               (0x3300)  /* (legacy definition) for use with XOR instruction */

/* FCTL1 Control Bits */
//#define RESERVED            (0x0001)  /* Reserved */
#define ERASE               (0x0002)  /* Enable bit for Flash segment erase */
#define MERAS               (0x0004)  /* Enable bit for Flash mass erase */
//#define RESERVED            (0x0008)  /* Reserved */
//#define RESERVED            (0x0010)  /* Reserved */
#define SWRT                (0x0020)  /* Smart Write enable */
#define WRT                 (0x0040)  /* Enable bit for Flash write */
#define BLKWRT              (0x0080)  /* Enable bit for Flash segment write */

/* FCTL1 Control Bits */
//#define RESERVED            (0x0001)  /* Reserved */
#define ERASE_L             (0x0002)  /* Enable bit for Flash segment erase */
#define MERAS_L             (0x0004)  /* Enable bit for Flash mass erase */
//#define RESERVED            (0x0008)  /* Reserved */
//#define RESERVED            (0x0010)  /* Reserved */
#define SWRT_L              (0x0020)  /* Smart Write enable */
#define WRT_L               (0x0040)  /* Enable bit for Flash write */
#define BLKWRT_L            (0x0080)  /* Enable bit for Flash segment write */


/* FCTL3 Control Bits */
#define BUSY                (0x0001)  /* Flash busy: 1 */
#define KEYV                (0x0002)  /* Flash Key violation flag */
#define ACCVIFG             (0x0004)  /* Flash Access violation flag */
#define WAIT                (0x0008)  /* Wait flag for segment write */
#define LOCK                (0x0010)  /* Lock bit: 1 - Flash is locked (read only) */
#define EMEX                (0x0020)  /* Flash Emergency Exit */
#define LOCKA               (0x0040)  /* Segment A Lock bit: read = 1 - Segment is locked (read only) */
//#define RESERVED            (0x0080)  /* Reserved */

/* FCTL3 Control Bits */
#define BUSY_L              (0x0001)  /* Flash busy: 1 */
#define KEYV_L              (0x0002)  /* Flash Key violation flag */
#define ACCVIFG_L           (0x0004)  /* Flash Access violation flag */
#define WAIT_L              (0x0008)  /* Wait flag for segment write */
#define LOCK_L              (0x0010)  /* Lock bit: 1 - Flash is locked (read only) */
#define EMEX_L              (0x0020)  /* Flash Emergency Exit */
#define LOCKA_L             (0x0040)  /* Segment A Lock bit: read = 1 - Segment is locked (read only) */
//#define RESERVED            (0x0080)  /* Reserved */


/* FCTL4 Control Bits */
#define VPE                 (0x0001)  /* Voltage Changed during Program Error Flag */
#define MGR0                (0x0010)  /* Marginal read 0 mode. */
#define MGR1                (0x0020)  /* Marginal read 1 mode. */
#define LOCKINFO            (0x0080)  /* Lock INFO Memory bit: read = 1 - Segment is locked (read only) */

/* FCTL4 Control Bits */
#define VPE_L               (0x0001)  /* Voltage Changed during Program Error Flag */
#define MGR0_L              (0x0010)  /* Marginal read 0 mode. */
#define MGR1_L              (0x0020)  /* Marginal read 1 mode. */
#define LOCKINFO_L          (0x0080)  /* Lock INFO Memory bit: read = 1 - Segment is locked (read only) */


#endif
/************************************************************
* LCD_B
************************************************************/
#ifdef  __MSP430_HAS_LCD_B__          /* Definition to show that Module is available */

#define OFS_LCDBCTL0          (0x0000)  /* LCD_B Control Register 0 */
#define OFS_LCDBCTL0_L         OFS_LCDBCTL0
#define OFS_LCDBCTL0_H         OFS_LCDBCTL0+1
#define OFS_LCDBCTL1          (0x0002)  /* LCD_B Control Register 1 */
#define OFS_LCDBCTL1_L         OFS_LCDBCTL1
#define OFS_LCDBCTL1_H         OFS_LCDBCTL1+1
#define OFS_LCDBBLKCTL        (0x0004)  /* LCD_B blinking control register */
#define OFS_LCDBBLKCTL_L       OFS_LCDBBLKCTL
#define OFS_LCDBBLKCTL_H       OFS_LCDBBLKCTL+1
#define OFS_LCDBMEMCTL        (0x0006)  /* LCD_B memory control register */
#define OFS_LCDBMEMCTL_L       OFS_LCDBMEMCTL
#define OFS_LCDBMEMCTL_H       OFS_LCDBMEMCTL+1
#define OFS_LCDBVCTL          (0x0008)  /* LCD_B Voltage Control Register */
#define OFS_LCDBVCTL_L         OFS_LCDBVCTL
#define OFS_LCDBVCTL_H         OFS_LCDBVCTL+1
#define OFS_LCDBPCTL0         (0x000A)  /* LCD_B Port Control Register 0 */
#define OFS_LCDBPCTL0_L        OFS_LCDBPCTL0
#define OFS_LCDBPCTL0_H        OFS_LCDBPCTL0+1
#define OFS_LCDBPCTL1         (0x000C)  /* LCD_B Port Control Register 1 */
#define OFS_LCDBPCTL1_L        OFS_LCDBPCTL1
#define OFS_LCDBPCTL1_H        OFS_LCDBPCTL1+1
#define OFS_LCDBPCTL2         (0x000E)  /* LCD_B Port Control Register 2 */
#define OFS_LCDBPCTL2_L        OFS_LCDBPCTL2
#define OFS_LCDBPCTL2_H        OFS_LCDBPCTL2+1
#define OFS_LCDBPCTL3         (0x0010)  /* LCD_B Port Control Register 3 */
#define OFS_LCDBPCTL3_L        OFS_LCDBPCTL3
#define OFS_LCDBPCTL3_H        OFS_LCDBPCTL3+1
#define OFS_LCDBCPCTL         (0x0012)  /* LCD_B Charge Pump Control Register 3 */
#define OFS_LCDBCPCTL_L        OFS_LCDBCPCTL
#define OFS_LCDBCPCTL_H        OFS_LCDBCPCTL+1
#define OFS_LCDBIV            (0x001E)  /* LCD_B Interrupt Vector Register */

// LCDBCTL0
#define LCDON               (0x0001)  /* LCD_B LCD On */
#define LCDSON              (0x0004)  /* LCD_B LCD Segments On */
#define LCDMX0              (0x0008)  /* LCD_B Mux Rate Bit: 0 */
#define LCDMX1              (0x0010)  /* LCD_B Mux Rate Bit: 1 */
//#define RESERVED            (0x0020)  /* LCD_B RESERVED */
//#define RESERVED            (0x0040)  /* LCD_B RESERVED */
#define LCDSSEL             (0x0080)  /* LCD_B Clock Select */
#define LCDPRE0             (0x0100)  /* LCD_B LCD frequency pre-scaler Bit: 0 */
#define LCDPRE1             (0x0200)  /* LCD_B LCD frequency pre-scaler Bit: 1 */
#define LCDPRE2             (0x0400)  /* LCD_B LCD frequency pre-scaler Bit: 2 */
#define LCDDIV0             (0x0800)  /* LCD_B LCD frequency divider Bit: 0 */
#define LCDDIV1             (0x1000)  /* LCD_B LCD frequency divider Bit: 1 */
#define LCDDIV2             (0x2000)  /* LCD_B LCD frequency divider Bit: 2 */
#define LCDDIV3             (0x4000)  /* LCD_B LCD frequency divider Bit: 3 */
#define LCDDIV4             (0x8000)  /* LCD_B LCD frequency divider Bit: 4 */

// LCDBCTL0
#define LCDON_L             (0x0001)  /* LCD_B LCD On */
#define LCDSON_L            (0x0004)  /* LCD_B LCD Segments On */
#define LCDMX0_L            (0x0008)  /* LCD_B Mux Rate Bit: 0 */
#define LCDMX1_L            (0x0010)  /* LCD_B Mux Rate Bit: 1 */
//#define RESERVED            (0x0020)  /* LCD_B RESERVED */
//#define RESERVED            (0x0040)  /* LCD_B RESERVED */
#define LCDSSEL_L           (0x0080)  /* LCD_B Clock Select */

// LCDBCTL0
//#define RESERVED            (0x0020)  /* LCD_B RESERVED */
//#define RESERVED            (0x0040)  /* LCD_B RESERVED */
#define LCDPRE0_H           (0x0001)  /* LCD_B LCD frequency pre-scaler Bit: 0 */
#define LCDPRE1_H           (0x0002)  /* LCD_B LCD frequency pre-scaler Bit: 1 */
#define LCDPRE2_H           (0x0004)  /* LCD_B LCD frequency pre-scaler Bit: 2 */
#define LCDDIV0_H           (0x0008)  /* LCD_B LCD frequency divider Bit: 0 */
#define LCDDIV1_H           (0x0010)  /* LCD_B LCD frequency divider Bit: 1 */
#define LCDDIV2_H           (0x0020)  /* LCD_B LCD frequency divider Bit: 2 */
#define LCDDIV3_H           (0x0040)  /* LCD_B LCD frequency divider Bit: 3 */
#define LCDDIV4_H           (0x0080)  /* LCD_B LCD frequency divider Bit: 4 */

#define LCDPRE_0            (0x0000)  /* LCD_B LCD frequency pre-scaler: /1 */
#define LCDPRE_1            (0x0100)  /* LCD_B LCD frequency pre-scaler: /2 */
#define LCDPRE_2            (0x0200)  /* LCD_B LCD frequency pre-scaler: /4 */
#define LCDPRE_3            (0x0300)  /* LCD_B LCD frequency pre-scaler: /8 */
#define LCDPRE_4            (0x0400)  /* LCD_B LCD frequency pre-scaler: /16 */
#define LCDPRE_5            (0x0500)  /* LCD_B LCD frequency pre-scaler: /32 */
#define LCDPRE__1           (0x0000)  /* LCD_B LCD frequency pre-scaler: /1 */
#define LCDPRE__2           (0x0100)  /* LCD_B LCD frequency pre-scaler: /2 */
#define LCDPRE__4           (0x0200)  /* LCD_B LCD frequency pre-scaler: /4 */
#define LCDPRE__8           (0x0300)  /* LCD_B LCD frequency pre-scaler: /8 */
#define LCDPRE__16          (0x0400)  /* LCD_B LCD frequency pre-scaler: /16 */
#define LCDPRE__32          (0x0500)  /* LCD_B LCD frequency pre-scaler: /32 */

#define LCDDIV_0            (0x0000)  /* LCD_B LCD frequency divider: /1 */
#define LCDDIV_1            (0x0800)  /* LCD_B LCD frequency divider: /2 */
#define LCDDIV_2            (0x1000)  /* LCD_B LCD frequency divider: /3 */
#define LCDDIV_3            (0x1800)  /* LCD_B LCD frequency divider: /4 */
#define LCDDIV_4            (0x2000)  /* LCD_B LCD frequency divider: /5 */
#define LCDDIV_5            (0x2800)  /* LCD_B LCD frequency divider: /6 */
#define LCDDIV_6            (0x3000)  /* LCD_B LCD frequency divider: /7 */
#define LCDDIV_7            (0x3800)  /* LCD_B LCD frequency divider: /8 */
#define LCDDIV_8            (0x4000)  /* LCD_B LCD frequency divider: /9 */
#define LCDDIV_9            (0x4800)  /* LCD_B LCD frequency divider: /10 */
#define LCDDIV_10           (0x5000)  /* LCD_B LCD frequency divider: /11 */
#define LCDDIV_11           (0x5800)  /* LCD_B LCD frequency divider: /12 */
#define LCDDIV_12           (0x6000)  /* LCD_B LCD frequency divider: /13 */
#define LCDDIV_13           (0x6800)  /* LCD_B LCD frequency divider: /14 */
#define LCDDIV_14           (0x7000)  /* LCD_B LCD frequency divider: /15 */
#define LCDDIV_15           (0x7800)  /* LCD_B LCD frequency divider: /16 */
#define LCDDIV_16           (0x8000)  /* LCD_B LCD frequency divider: /17 */
#define LCDDIV_17           (0x8800)  /* LCD_B LCD frequency divider: /18 */
#define LCDDIV_18           (0x9000)  /* LCD_B LCD frequency divider: /19 */
#define LCDDIV_19           (0x9800)  /* LCD_B LCD frequency divider: /20 */
#define LCDDIV_20           (0xA000)  /* LCD_B LCD frequency divider: /21 */
#define LCDDIV_21           (0xA800)  /* LCD_B LCD frequency divider: /22 */
#define LCDDIV_22           (0xB000)  /* LCD_B LCD frequency divider: /23 */
#define LCDDIV_23           (0xB800)  /* LCD_B LCD frequency divider: /24 */
#define LCDDIV_24           (0xC000)  /* LCD_B LCD frequency divider: /25 */
#define LCDDIV_25           (0xC800)  /* LCD_B LCD frequency divider: /26 */
#define LCDDIV_26           (0xD000)  /* LCD_B LCD frequency divider: /27 */
#define LCDDIV_27           (0xD800)  /* LCD_B LCD frequency divider: /28 */
#define LCDDIV_28           (0xE000)  /* LCD_B LCD frequency divider: /29 */
#define LCDDIV_29           (0xE800)  /* LCD_B LCD frequency divider: /30 */
#define LCDDIV_30           (0xF000)  /* LCD_B LCD frequency divider: /31 */
#define LCDDIV_31           (0xF800)  /* LCD_B LCD frequency divider: /32 */
#define LCDDIV__1           (0x0000)  /* LCD_B LCD frequency divider: /1 */
#define LCDDIV__2           (0x0800)  /* LCD_B LCD frequency divider: /2 */
#define LCDDIV__3           (0x1000)  /* LCD_B LCD frequency divider: /3 */
#define LCDDIV__4           (0x1800)  /* LCD_B LCD frequency divider: /4 */
#define LCDDIV__5           (0x2000)  /* LCD_B LCD frequency divider: /5 */
#define LCDDIV__6           (0x2800)  /* LCD_B LCD frequency divider: /6 */
#define LCDDIV__7           (0x3000)  /* LCD_B LCD frequency divider: /7 */
#define LCDDIV__8           (0x3800)  /* LCD_B LCD frequency divider: /8 */
#define LCDDIV__9           (0x4000)  /* LCD_B LCD frequency divider: /9 */
#define LCDDIV__10          (0x4800)  /* LCD_B LCD frequency divider: /10 */
#define LCDDIV__11          (0x5000)  /* LCD_B LCD frequency divider: /11 */
#define LCDDIV__12          (0x5800)  /* LCD_B LCD frequency divider: /12 */
#define LCDDIV__13          (0x6000)  /* LCD_B LCD frequency divider: /13 */
#define LCDDIV__14          (0x6800)  /* LCD_B LCD frequency divider: /14 */
#define LCDDIV__15          (0x7000)  /* LCD_B LCD frequency divider: /15 */
#define LCDDIV__16          (0x7800)  /* LCD_B LCD frequency divider: /16 */
#define LCDDIV__17          (0x8000)  /* LCD_B LCD frequency divider: /17 */
#define LCDDIV__18          (0x8800)  /* LCD_B LCD frequency divider: /18 */
#define LCDDIV__19          (0x9000)  /* LCD_B LCD frequency divider: /19 */
#define LCDDIV__20          (0x9800)  /* LCD_B LCD frequency divider: /20 */
#define LCDDIV__21          (0xA000)  /* LCD_B LCD frequency divider: /21 */
#define LCDDIV__22          (0xA800)  /* LCD_B LCD frequency divider: /22 */
#define LCDDIV__23          (0xB000)  /* LCD_B LCD frequency divider: /23 */
#define LCDDIV__24          (0xB800)  /* LCD_B LCD frequency divider: /24 */
#define LCDDIV__25          (0xC000)  /* LCD_B LCD frequency divider: /25 */
#define LCDDIV__26          (0xC800)  /* LCD_B LCD frequency divider: /26 */
#define LCDDIV__27          (0xD000)  /* LCD_B LCD frequency divider: /27 */
#define LCDDIV__28          (0xD800)  /* LCD_B LCD frequency divider: /28 */
#define LCDDIV__29          (0xE000)  /* LCD_B LCD frequency divider: /29 */
#define LCDDIV__30          (0xE800)  /* LCD_B LCD frequency divider: /30 */
#define LCDDIV__31          (0xF000)  /* LCD_B LCD frequency divider: /31 */
#define LCDDIV__32          (0xF800)  /* LCD_B LCD frequency divider: /32 */


/* Display modes coded with Bits 2-4 */
#define LCDSTATIC           (LCDSON)
#define LCD2MUX             (LCDMX0+LCDSON)
#define LCD3MUX             (LCDMX1+LCDSON)
#define LCD4MUX             (LCDMX1+LCDMX0+LCDSON)

// LCDBCTL1
#define LCDFRMIFG           (0x0001)  /* LCD_B LCD frame interrupt flag */
#define LCDBLKOFFIFG        (0x0002)  /* LCD_B LCD blinking off interrupt flag, */
#define LCDBLKONIFG         (0x0004)  /* LCD_B LCD blinking on interrupt flag, */
#define LCDNOCAPIFG         (0x0008)  /* LCD_B No cpacitance connected interrupt flag */
#define LCDFRMIE            (0x0100)  /* LCD_B LCD frame interrupt enable */
#define LCDBLKOFFIE         (0x0200)  /* LCD_B LCD blinking off interrupt flag, */
#define LCDBLKONIE          (0x0400)  /* LCD_B LCD blinking on interrupt flag, */
#define LCDNOCAPIE          (0x0800)  /* LCD_B No cpacitance connected interrupt enable */

// LCDBCTL1
#define LCDFRMIFG_L         (0x0001)  /* LCD_B LCD frame interrupt flag */
#define LCDBLKOFFIFG_L      (0x0002)  /* LCD_B LCD blinking off interrupt flag, */
#define LCDBLKONIFG_L       (0x0004)  /* LCD_B LCD blinking on interrupt flag, */
#define LCDNOCAPIFG_L       (0x0008)  /* LCD_B No cpacitance connected interrupt flag */

// LCDBCTL1
#define LCDFRMIE_H          (0x0001)  /* LCD_B LCD frame interrupt enable */
#define LCDBLKOFFIE_H       (0x0002)  /* LCD_B LCD blinking off interrupt flag, */
#define LCDBLKONIE_H        (0x0004)  /* LCD_B LCD blinking on interrupt flag, */
#define LCDNOCAPIE_H        (0x0008)  /* LCD_B No cpacitance connected interrupt enable */

// LCDBBLKCTL
#define LCDBLKMOD0          (0x0001)  /* LCD_B Blinking mode Bit: 0 */
#define LCDBLKMOD1          (0x0002)  /* LCD_B Blinking mode Bit: 1 */
#define LCDBLKPRE0          (0x0004)  /* LCD_B Clock pre-scaler for blinking frequency Bit: 0 */
#define LCDBLKPRE1          (0x0008)  /* LCD_B Clock pre-scaler for blinking frequency Bit: 1 */
#define LCDBLKPRE2          (0x0010)  /* LCD_B Clock pre-scaler for blinking frequency Bit: 2 */
#define LCDBLKDIV0          (0x0020)  /* LCD_B Clock divider for blinking frequency Bit: 0 */
#define LCDBLKDIV1          (0x0040)  /* LCD_B Clock divider for blinking frequency Bit: 1 */
#define LCDBLKDIV2          (0x0080)  /* LCD_B Clock divider for blinking frequency Bit: 2 */

// LCDBBLKCTL
#define LCDBLKMOD0_L        (0x0001)  /* LCD_B Blinking mode Bit: 0 */
#define LCDBLKMOD1_L        (0x0002)  /* LCD_B Blinking mode Bit: 1 */
#define LCDBLKPRE0_L        (0x0004)  /* LCD_B Clock pre-scaler for blinking frequency Bit: 0 */
#define LCDBLKPRE1_L        (0x0008)  /* LCD_B Clock pre-scaler for blinking frequency Bit: 1 */
#define LCDBLKPRE2_L        (0x0010)  /* LCD_B Clock pre-scaler for blinking frequency Bit: 2 */
#define LCDBLKDIV0_L        (0x0020)  /* LCD_B Clock divider for blinking frequency Bit: 0 */
#define LCDBLKDIV1_L        (0x0040)  /* LCD_B Clock divider for blinking frequency Bit: 1 */
#define LCDBLKDIV2_L        (0x0080)  /* LCD_B Clock divider for blinking frequency Bit: 2 */


#define LCDBLKMOD_0         (0x0000)  /* LCD_B Blinking mode: Off */
#define LCDBLKMOD_1         (0x0001)  /* LCD_B Blinking mode: Individual */
#define LCDBLKMOD_2         (0x0002)  /* LCD_B Blinking mode: All */
#define LCDBLKMOD_3         (0x0003)  /* LCD_B Blinking mode: Switching */

// LCDBMEMCTL
#define LCDDISP             (0x0001)  /* LCD_B LCD memory registers for display */
#define LCDCLRM             (0x0002)  /* LCD_B Clear LCD memory */
#define LCDCLRBM            (0x0004)  /* LCD_B Clear LCD blinking memory */

// LCDBMEMCTL
#define LCDDISP_L           (0x0001)  /* LCD_B LCD memory registers for display */
#define LCDCLRM_L           (0x0002)  /* LCD_B Clear LCD memory */
#define LCDCLRBM_L          (0x0004)  /* LCD_B Clear LCD blinking memory */


// LCDBVCTL
#define LCD2B               (0x0001)  /* Selects 1/2 bias. */
#define VLCDREF0            (0x0002)  /* Selects reference voltage for regulated charge pump: 0 */
#define VLCDREF1            (0x0004)  /* Selects reference voltage for regulated charge pump: 1 */
#define LCDCPEN             (0x0008)  /* LCD Voltage Charge Pump Enable. */
#define VLCDEXT             (0x0010)  /* Select external source for VLCD. */
#define LCDEXTBIAS          (0x0020)  /* V2 - V4 voltage select. */
#define R03EXT              (0x0040)  /* Selects external connections for LCD mid voltages. */
#define LCDREXT             (0x0080)  /* Selects external connection for lowest LCD voltage. */
#define VLCD0               (0x0200)  /* VLCD select: 0 */
#define VLCD1               (0x0400)  /* VLCD select: 1 */
#define VLCD2               (0x0800)  /* VLCD select: 2 */
#define VLCD3               (0x1000)  /* VLCD select: 3 */

// LCDBVCTL
#define LCD2B_L             (0x0001)  /* Selects 1/2 bias. */
#define VLCDREF0_L          (0x0002)  /* Selects reference voltage for regulated charge pump: 0 */
#define VLCDREF1_L          (0x0004)  /* Selects reference voltage for regulated charge pump: 1 */
#define LCDCPEN_L           (0x0008)  /* LCD Voltage Charge Pump Enable. */
#define VLCDEXT_L           (0x0010)  /* Select external source for VLCD. */
#define LCDEXTBIAS_L        (0x0020)  /* V2 - V4 voltage select. */
#define R03EXT_L            (0x0040)  /* Selects external connections for LCD mid voltages. */
#define LCDREXT_L           (0x0080)  /* Selects external connection for lowest LCD voltage. */

// LCDBVCTL
#define VLCD0_H             (0x0002)  /* VLCD select: 0 */
#define VLCD1_H             (0x0004)  /* VLCD select: 1 */
#define VLCD2_H             (0x0008)  /* VLCD select: 2 */
#define VLCD3_H             (0x0010)  /* VLCD select: 3 */

/* Reference voltage source select for the regulated charge pump */
#define VLCDREF_0           (0<<1)    /* Internal */
#define VLCDREF_1           (1<<1)    /* External */
#define VLCDREF_2           (2<<1)    /* Reserved */
#define VLCDREF_3           (3<<1)    /* Reserved */


/* Charge pump voltage selections */
#define VLCD_0              (0<<9)    /* Charge pump disabled */
#define VLCD_1              (1<<9)    /* VLCD = 2.60V */
#define VLCD_2              (2<<9)    /* VLCD = 2.66V */
#define VLCD_3              (3<<9)    /* VLCD = 2.72V */
#define VLCD_4              (4<<9)    /* VLCD = 2.78V */
#define VLCD_5              (5<<9)    /* VLCD = 2.84V */
#define VLCD_6              (6<<9)    /* VLCD = 2.90V */
#define VLCD_7              (7<<9)    /* VLCD = 2.96V */
#define VLCD_8              (8<<9)    /* VLCD = 3.02V */
#define VLCD_9              (9<<9)    /* VLCD = 3.08V */
#define VLCD_10             (10<<9)   /* VLCD = 3.14V */
#define VLCD_11             (11<<9)   /* VLCD = 3.20V */
#define VLCD_12             (12<<9)   /* VLCD = 3.26V */
#define VLCD_13             (13<<9)   /* VLCD = 3.32V */
#define VLCD_14             (14<<9)   /* VLCD = 3.38V */
#define VLCD_15             (15<<9)   /* VLCD = 3.44V */

#define VLCD_DISABLED       (0<<9)    /* Charge pump disabled */
#define VLCD_2_60           (1<<9)    /* VLCD = 2.60V */
#define VLCD_2_66           (2<<9)    /* VLCD = 2.66V */
#define VLCD_2_72           (3<<9)    /* VLCD = 2.72V */
#define VLCD_2_78           (4<<9)    /* VLCD = 2.78V */
#define VLCD_2_84           (5<<9)    /* VLCD = 2.84V */
#define VLCD_2_90           (6<<9)    /* VLCD = 2.90V */
#define VLCD_2_96           (7<<9)    /* VLCD = 2.96V */
#define VLCD_3_02           (8<<9)    /* VLCD = 3.02V */
#define VLCD_3_08           (9<<9)    /* VLCD = 3.08V */
#define VLCD_3_14           (10<<9)   /* VLCD = 3.14V */
#define VLCD_3_20           (11<<9)   /* VLCD = 3.20V */
#define VLCD_3_26           (12<<9)   /* VLCD = 3.26V */
#define VLCD_3_32           (13<<9)   /* VLCD = 3.32V */
#define VLCD_3_38           (14<<9)   /* VLCD = 3.38V */
#define VLCD_3_44           (15<<9)   /* VLCD = 3.44V */


// LCDBPCTL0
#define LCDS0               (0x0001)  /* LCD Segment  0 enable. */
#define LCDS1               (0x0002)  /* LCD Segment  1 enable. */
#define LCDS2               (0x0004)  /* LCD Segment  2 enable. */
#define LCDS3               (0x0008)  /* LCD Segment  3 enable. */
#define LCDS4               (0x0010)  /* LCD Segment  4 enable. */
#define LCDS5               (0x0020)  /* LCD Segment  5 enable. */
#define LCDS6               (0x0040)  /* LCD Segment  6 enable. */
#define LCDS7               (0x0080)  /* LCD Segment  7 enable. */
#define LCDS8               (0x0100)  /* LCD Segment  8 enable. */
#define LCDS9               (0x0200)  /* LCD Segment  9 enable. */
#define LCDS10              (0x0400)  /* LCD Segment 10 enable. */
#define LCDS11              (0x0800)  /* LCD Segment 11 enable. */
#define LCDS12              (0x1000)  /* LCD Segment 12 enable. */
#define LCDS13              (0x2000)  /* LCD Segment 13 enable. */
#define LCDS14              (0x4000)  /* LCD Segment 14 enable. */
#define LCDS15              (0x8000)  /* LCD Segment 15 enable. */

// LCDBPCTL0
#define LCDS0_L             (0x0001)  /* LCD Segment  0 enable. */
#define LCDS1_L             (0x0002)  /* LCD Segment  1 enable. */
#define LCDS2_L             (0x0004)  /* LCD Segment  2 enable. */
#define LCDS3_L             (0x0008)  /* LCD Segment  3 enable. */
#define LCDS4_L             (0x0010)  /* LCD Segment  4 enable. */
#define LCDS5_L             (0x0020)  /* LCD Segment  5 enable. */
#define LCDS6_L             (0x0040)  /* LCD Segment  6 enable. */
#define LCDS7_L             (0x0080)  /* LCD Segment  7 enable. */

// LCDBPCTL0
#define LCDS8_H             (0x0001)  /* LCD Segment  8 enable. */
#define LCDS9_H             (0x0002)  /* LCD Segment  9 enable. */
#define LCDS10_H            (0x0004)  /* LCD Segment 10 enable. */
#define LCDS11_H            (0x0008)  /* LCD Segment 11 enable. */
#define LCDS12_H            (0x0010)  /* LCD Segment 12 enable. */
#define LCDS13_H            (0x0020)  /* LCD Segment 13 enable. */
#define LCDS14_H            (0x0040)  /* LCD Segment 14 enable. */
#define LCDS15_H            (0x0080)  /* LCD Segment 15 enable. */

// LCDBPCTL1
#define LCDS16              (0x0001)  /* LCD Segment 16 enable. */
#define LCDS17              (0x0002)  /* LCD Segment 17 enable. */
#define LCDS18              (0x0004)  /* LCD Segment 18 enable. */
#define LCDS19              (0x0008)  /* LCD Segment 19 enable. */
#define LCDS20              (0x0010)  /* LCD Segment 20 enable. */
#define LCDS21              (0x0020)  /* LCD Segment 21 enable. */
#define LCDS22              (0x0040)  /* LCD Segment 22 enable. */
#define LCDS23              (0x0080)  /* LCD Segment 23 enable. */
#define LCDS24              (0x0100)  /* LCD Segment 24 enable. */
#define LCDS25              (0x0200)  /* LCD Segment 25 enable. */
#define LCDS26              (0x0400)  /* LCD Segment 26 enable. */
#define LCDS27              (0x0800)  /* LCD Segment 27 enable. */
#define LCDS28              (0x1000)  /* LCD Segment 28 enable. */
#define LCDS29              (0x2000)  /* LCD Segment 29 enable. */
#define LCDS30              (0x4000)  /* LCD Segment 30 enable. */
#define LCDS31              (0x8000)  /* LCD Segment 31 enable. */

// LCDBPCTL1
#define LCDS16_L            (0x0001)  /* LCD Segment 16 enable. */
#define LCDS17_L            (0x0002)  /* LCD Segment 17 enable. */
#define LCDS18_L            (0x0004)  /* LCD Segment 18 enable. */
#define LCDS19_L            (0x0008)  /* LCD Segment 19 enable. */
#define LCDS20_L            (0x0010)  /* LCD Segment 20 enable. */
#define LCDS21_L            (0x0020)  /* LCD Segment 21 enable. */
#define LCDS22_L            (0x0040)  /* LCD Segment 22 enable. */
#define LCDS23_L            (0x0080)  /* LCD Segment 23 enable. */

// LCDBPCTL1
#define LCDS24_H            (0x0001)  /* LCD Segment 24 enable. */
#define LCDS25_H            (0x0002)  /* LCD Segment 25 enable. */
#define LCDS26_H            (0x0004)  /* LCD Segment 26 enable. */
#define LCDS27_H            (0x0008)  /* LCD Segment 27 enable. */
#define LCDS28_H            (0x0010)  /* LCD Segment 28 enable. */
#define LCDS29_H            (0x0020)  /* LCD Segment 29 enable. */
#define LCDS30_H            (0x0040)  /* LCD Segment 30 enable. */
#define LCDS31_H            (0x0080)  /* LCD Segment 31 enable. */

// LCDBPCTL2
#define LCDS32              (0x0001)  /* LCD Segment 32 enable. */
#define LCDS33              (0x0002)  /* LCD Segment 33 enable. */
#define LCDS34              (0x0004)  /* LCD Segment 34 enable. */
#define LCDS35              (0x0008)  /* LCD Segment 35 enable. */
#define LCDS36              (0x0010)  /* LCD Segment 36 enable. */
#define LCDS37              (0x0020)  /* LCD Segment 37 enable. */
#define LCDS38              (0x0040)  /* LCD Segment 38 enable. */
#define LCDS39              (0x0080)  /* LCD Segment 39 enable. */
#define LCDS40              (0x0100)  /* LCD Segment 40 enable. */
#define LCDS41              (0x0200)  /* LCD Segment 41 enable. */
#define LCDS42              (0x0400)  /* LCD Segment 42 enable. */
#define LCDS43              (0x0800)  /* LCD Segment 43 enable. */
#define LCDS44              (0x1000)  /* LCD Segment 44 enable. */
#define LCDS45              (0x2000)  /* LCD Segment 45 enable. */
#define LCDS46              (0x4000)  /* LCD Segment 46 enable. */
#define LCDS47              (0x8000)  /* LCD Segment 47 enable. */

// LCDBPCTL2
#define LCDS32_L            (0x0001)  /* LCD Segment 32 enable. */
#define LCDS33_L            (0x0002)  /* LCD Segment 33 enable. */
#define LCDS34_L            (0x0004)  /* LCD Segment 34 enable. */
#define LCDS35_L            (0x0008)  /* LCD Segment 35 enable. */
#define LCDS36_L            (0x0010)  /* LCD Segment 36 enable. */
#define LCDS37_L            (0x0020)  /* LCD Segment 37 enable. */
#define LCDS38_L            (0x0040)  /* LCD Segment 38 enable. */
#define LCDS39_L            (0x0080)  /* LCD Segment 39 enable. */

// LCDBPCTL2
#define LCDS40_H            (0x0001)  /* LCD Segment 40 enable. */
#define LCDS41_H            (0x0002)  /* LCD Segment 41 enable. */
#define LCDS42_H            (0x0004)  /* LCD Segment 42 enable. */
#define LCDS43_H            (0x0008)  /* LCD Segment 43 enable. */
#define LCDS44_H            (0x0010)  /* LCD Segment 44 enable. */
#define LCDS45_H            (0x0020)  /* LCD Segment 45 enable. */
#define LCDS46_H            (0x0040)  /* LCD Segment 46 enable. */
#define LCDS47_H            (0x0080)  /* LCD Segment 47 enable. */

// LCDBPCTL3
#define LCDS48              (0x0001)  /* LCD Segment 48 enable. */
#define LCDS49              (0x0002)  /* LCD Segment 49 enable. */
#define LCDS50              (0x0004)  /* LCD Segment 50 enable. */

// LCDBPCTL3
#define LCDS48_L            (0x0001)  /* LCD Segment 48 enable. */
#define LCDS49_L            (0x0002)  /* LCD Segment 49 enable. */
#define LCDS50_L            (0x0004)  /* LCD Segment 50 enable. */


// LCDBCPCTL
#define LCDCPDIS0           (0x0001)  /* LCD charge pump disable */
#define LCDCPDIS1           (0x0002)  /* LCD charge pump disable */
#define LCDCPDIS2           (0x0004)  /* LCD charge pump disable */
#define LCDCPDIS3           (0x0008)  /* LCD charge pump disable */
#define LCDCPDIS4           (0x0010)  /* LCD charge pump disable */
#define LCDCPDIS5           (0x0020)  /* LCD charge pump disable */
#define LCDCPDIS6           (0x0040)  /* LCD charge pump disable */
#define LCDCPDIS7           (0x0080)  /* LCD charge pump disable */
#define LCDCPCLKSYNC        (0x8000)  /* LCD charge pump clock synchronization */

// LCDBCPCTL
#define LCDCPDIS0_L         (0x0001)  /* LCD charge pump disable */
#define LCDCPDIS1_L         (0x0002)  /* LCD charge pump disable */
#define LCDCPDIS2_L         (0x0004)  /* LCD charge pump disable */
#define LCDCPDIS3_L         (0x0008)  /* LCD charge pump disable */
#define LCDCPDIS4_L         (0x0010)  /* LCD charge pump disable */
#define LCDCPDIS5_L         (0x0020)  /* LCD charge pump disable */
#define LCDCPDIS6_L         (0x0040)  /* LCD charge pump disable */
#define LCDCPDIS7_L         (0x0080)  /* LCD charge pump disable */

// LCDBCPCTL
#define LCDCPCLKSYNC_H      (0x0080)  /* LCD charge pump clock synchronization */

#define OFS_LCDM1             (0x0020)  /* LCD Memory 1 */
#define LCDMEM_             LCDM1     /* LCD Memory */
#ifndef __STDC__
#define LCDMEM              LCDM1     /* LCD Memory (for assembler) */
#else
#define LCDMEM              ((volatile char*) &LCDM1) /* LCD Memory (for C) */
#endif
#define OFS_LCDM2             (0x0021)  /* LCD Memory 2 */
#define OFS_LCDM3             (0x0022)  /* LCD Memory 3 */
#define OFS_LCDM4             (0x0023)  /* LCD Memory 4 */
#define OFS_LCDM5             (0x0024)  /* LCD Memory 5 */
#define OFS_LCDM6             (0x0025)  /* LCD Memory 6 */
#define OFS_LCDM7             (0x0026)  /* LCD Memory 7 */
#define OFS_LCDM8             (0x0027)  /* LCD Memory 8 */
#define OFS_LCDM9             (0x0028)  /* LCD Memory 9 */
#define OFS_LCDM10            (0x0029)  /* LCD Memory 10 */
#define OFS_LCDM11            (0x002A)  /* LCD Memory 11 */
#define OFS_LCDM12            (0x002B)  /* LCD Memory 12 */
#define OFS_LCDM13            (0x002C)  /* LCD Memory 13 */
#define OFS_LCDM14            (0x002D)  /* LCD Memory 14 */
#define OFS_LCDM15            (0x002E)  /* LCD Memory 15 */
#define OFS_LCDM16            (0x002F)  /* LCD Memory 16 */
#define OFS_LCDM17            (0x0030)  /* LCD Memory 17 */
#define OFS_LCDM18            (0x0031)  /* LCD Memory 18 */
#define OFS_LCDM19            (0x0032)  /* LCD Memory 19 */
#define OFS_LCDM20            (0x0033)  /* LCD Memory 20 */
#define OFS_LCDM21            (0x0034)  /* LCD Memory 21 */
#define OFS_LCDM22            (0x0035)  /* LCD Memory 22 */
#define OFS_LCDM23            (0x0036)  /* LCD Memory 23 */
#define OFS_LCDM24            (0x0037)  /* LCD Memory 24 */

#define OFS_LCDBM1            (0x0040)  /* LCD Blinking Memory 1 */
#define LCDBMEM_            LCDBM1    /* LCD Blinking Memory */
#ifndef __STDC__
#define LCDBMEM             (LCDBM1)  /* LCD Blinking Memory (for assembler) */
#else
#define LCDBMEM             ((volatile char*) &LCDBM1) /* LCD Blinking Memory (for C) */
#endif
#define OFS_LCDBM2            (0x0041)  /* LCD Blinking Memory 2 */
#define OFS_LCDBM3            (0x0042)  /* LCD Blinking Memory 3 */
#define OFS_LCDBM4            (0x0043)  /* LCD Blinking Memory 4 */
#define OFS_LCDBM5            (0x0044)  /* LCD Blinking Memory 5 */
#define OFS_LCDBM6            (0x0045)  /* LCD Blinking Memory 6 */
#define OFS_LCDBM7            (0x0046)  /* LCD Blinking Memory 7 */
#define OFS_LCDBM8            (0x0047)  /* LCD Blinking Memory 8 */
#define OFS_LCDBM9            (0x0048)  /* LCD Blinking Memory 9 */
#define OFS_LCDBM10           (0x0049)  /* LCD Blinking Memory 10 */
#define OFS_LCDBM11           (0x004A)  /* LCD Blinking Memory 11 */
#define OFS_LCDBM12           (0x004B)  /* LCD Blinking Memory 12 */
#define OFS_LCDBM13           (0x004C)  /* LCD Blinking Memory 13 */
#define OFS_LCDBM14           (0x004D)  /* LCD Blinking Memory 14 */
#define OFS_LCDBM15           (0x004E)  /* LCD Blinking Memory 15 */
#define OFS_LCDBM16           (0x004F)  /* LCD Blinking Memory 16 */
#define OFS_LCDBM17           (0x0050)  /* LCD Blinking Memory 17 */
#define OFS_LCDBM18           (0x0051)  /* LCD Blinking Memory 18 */
#define OFS_LCDBM19           (0x0052)  /* LCD Blinking Memory 19 */
#define OFS_LCDBM20           (0x0053)  /* LCD Blinking Memory 20 */
#define OFS_LCDBM21           (0x0054)  /* LCD Blinking Memory 21 */
#define OFS_LCDBM22           (0x0055)  /* LCD Blinking Memory 22 */
#define OFS_LCDBM23           (0x0056)  /* LCD Blinking Memory 23 */
#define OFS_LCDBM24           (0x0057)  /* LCD Blinking Memory 24 */

/* LCDBIV Definitions */
#define LCDBIV_NONE         (0x0000)    /* No Interrupt pending */
#define LCDBIV_LCDNOCAPIFG  (0x0002)    /* No capacitor connected */
#define LCDBIV_LCDBLKOFFIFG (0x0004)    /* Blink, segments off */
#define LCDBIV_LCDBLKONIFG  (0x0006)    /* Blink, segments on */
#define LCDBIV_LCDFRMIFG    (0x0008)    /* Frame interrupt */

#endif
/************************************************************
* LCD_C
************************************************************/
#ifdef  __MSP430_HAS_LCD_C__          /* Definition to show that Module is available */

#define OFS_LCDCCTL0          (0x0000)  /* LCD_C Control Register 0 */
#define OFS_LCDCCTL0_L         OFS_LCDCCTL0
#define OFS_LCDCCTL0_H         OFS_LCDCCTL0+1
#define OFS_LCDCCTL1          (0x0002)  /* LCD_C Control Register 1 */
#define OFS_LCDCCTL1_L         OFS_LCDCCTL1
#define OFS_LCDCCTL1_H         OFS_LCDCCTL1+1
#define OFS_LCDCBLKCTL        (0x0004)  /* LCD_C blinking control register */
#define OFS_LCDCBLKCTL_L       OFS_LCDCBLKCTL
#define OFS_LCDCBLKCTL_H       OFS_LCDCBLKCTL+1
#define OFS_LCDCMEMCTL        (0x0006)  /* LCD_C memory control register */
#define OFS_LCDCMEMCTL_L       OFS_LCDCMEMCTL
#define OFS_LCDCMEMCTL_H       OFS_LCDCMEMCTL+1
#define OFS_LCDCVCTL          (0x0008)  /* LCD_C Voltage Control Register */
#define OFS_LCDCVCTL_L         OFS_LCDCVCTL
#define OFS_LCDCVCTL_H         OFS_LCDCVCTL+1
#define OFS_LCDCPCTL0         (0x000A)  /* LCD_C Port Control Register 0 */
#define OFS_LCDCPCTL0_L        OFS_LCDCPCTL0
#define OFS_LCDCPCTL0_H        OFS_LCDCPCTL0+1
#define OFS_LCDCPCTL1         (0x000C)  /* LCD_C Port Control Register 1 */
#define OFS_LCDCPCTL1_L        OFS_LCDCPCTL1
#define OFS_LCDCPCTL1_H        OFS_LCDCPCTL1+1
#define OFS_LCDCPCTL2         (0x000E)  /* LCD_C Port Control Register 2 */
#define OFS_LCDCPCTL2_L        OFS_LCDCPCTL2
#define OFS_LCDCPCTL2_H        OFS_LCDCPCTL2+1
#define OFS_LCDCCPCTL         (0x0012)  /* LCD_C Charge Pump Control Register 3 */
#define OFS_LCDCCPCTL_L        OFS_LCDCCPCTL
#define OFS_LCDCCPCTL_H        OFS_LCDCCPCTL+1
#define OFS_LCDCIV            (0x001E)  /* LCD_C Interrupt Vector Register */

// LCDCCTL0
#define LCDON               (0x0001)  /* LCD_C LCD On */
#define LCDLP               (0x0002)  /* LCD_C Low Power Waveform */
#define LCDSON              (0x0004)  /* LCD_C LCD Segments On */
#define LCDMX0              (0x0008)  /* LCD_C Mux Rate Bit: 0 */
#define LCDMX1              (0x0010)  /* LCD_C Mux Rate Bit: 1 */
#define LCDMX2              (0x0020)  /* LCD_C Mux Rate Bit: 2 */
//#define RESERVED            (0x0040)  /* LCD_C RESERVED */
#define LCDSSEL             (0x0080)  /* LCD_C Clock Select */
#define LCDPRE0             (0x0100)  /* LCD_C LCD frequency pre-scaler Bit: 0 */
#define LCDPRE1             (0x0200)  /* LCD_C LCD frequency pre-scaler Bit: 1 */
#define LCDPRE2             (0x0400)  /* LCD_C LCD frequency pre-scaler Bit: 2 */
#define LCDDIV0             (0x0800)  /* LCD_C LCD frequency divider Bit: 0 */
#define LCDDIV1             (0x1000)  /* LCD_C LCD frequency divider Bit: 1 */
#define LCDDIV2             (0x2000)  /* LCD_C LCD frequency divider Bit: 2 */
#define LCDDIV3             (0x4000)  /* LCD_C LCD frequency divider Bit: 3 */
#define LCDDIV4             (0x8000)  /* LCD_C LCD frequency divider Bit: 4 */

// LCDCCTL0
#define LCDON_L             (0x0001)  /* LCD_C LCD On */
#define LCDLP_L             (0x0002)  /* LCD_C Low Power Waveform */
#define LCDSON_L            (0x0004)  /* LCD_C LCD Segments On */
#define LCDMX0_L            (0x0008)  /* LCD_C Mux Rate Bit: 0 */
#define LCDMX1_L            (0x0010)  /* LCD_C Mux Rate Bit: 1 */
#define LCDMX2_L            (0x0020)  /* LCD_C Mux Rate Bit: 2 */
//#define RESERVED            (0x0040)  /* LCD_C RESERVED */
#define LCDSSEL_L           (0x0080)  /* LCD_C Clock Select */

// LCDCCTL0
//#define RESERVED            (0x0040)  /* LCD_C RESERVED */
#define LCDPRE0_H           (0x0001)  /* LCD_C LCD frequency pre-scaler Bit: 0 */
#define LCDPRE1_H           (0x0002)  /* LCD_C LCD frequency pre-scaler Bit: 1 */
#define LCDPRE2_H           (0x0004)  /* LCD_C LCD frequency pre-scaler Bit: 2 */
#define LCDDIV0_H           (0x0008)  /* LCD_C LCD frequency divider Bit: 0 */
#define LCDDIV1_H           (0x0010)  /* LCD_C LCD frequency divider Bit: 1 */
#define LCDDIV2_H           (0x0020)  /* LCD_C LCD frequency divider Bit: 2 */
#define LCDDIV3_H           (0x0040)  /* LCD_C LCD frequency divider Bit: 3 */
#define LCDDIV4_H           (0x0080)  /* LCD_C LCD frequency divider Bit: 4 */

#define LCDPRE_0            (0x0000)  /* LCD_C LCD frequency pre-scaler: /1 */
#define LCDPRE_1            (0x0100)  /* LCD_C LCD frequency pre-scaler: /2 */
#define LCDPRE_2            (0x0200)  /* LCD_C LCD frequency pre-scaler: /4 */
#define LCDPRE_3            (0x0300)  /* LCD_C LCD frequency pre-scaler: /8 */
#define LCDPRE_4            (0x0400)  /* LCD_C LCD frequency pre-scaler: /16 */
#define LCDPRE_5            (0x0500)  /* LCD_C LCD frequency pre-scaler: /32 */
#define LCDPRE__1           (0x0000)  /* LCD_C LCD frequency pre-scaler: /1 */
#define LCDPRE__2           (0x0100)  /* LCD_C LCD frequency pre-scaler: /2 */
#define LCDPRE__4           (0x0200)  /* LCD_C LCD frequency pre-scaler: /4 */
#define LCDPRE__8           (0x0300)  /* LCD_C LCD frequency pre-scaler: /8 */
#define LCDPRE__16          (0x0400)  /* LCD_C LCD frequency pre-scaler: /16 */
#define LCDPRE__32          (0x0500)  /* LCD_C LCD frequency pre-scaler: /32 */

#define LCDDIV_0            (0x0000)  /* LCD_C LCD frequency divider: /1 */
#define LCDDIV_1            (0x0800)  /* LCD_C LCD frequency divider: /2 */
#define LCDDIV_2            (0x1000)  /* LCD_C LCD frequency divider: /3 */
#define LCDDIV_3            (0x1800)  /* LCD_C LCD frequency divider: /4 */
#define LCDDIV_4            (0x2000)  /* LCD_C LCD frequency divider: /5 */
#define LCDDIV_5            (0x2800)  /* LCD_C LCD frequency divider: /6 */
#define LCDDIV_6            (0x3000)  /* LCD_C LCD frequency divider: /7 */
#define LCDDIV_7            (0x3800)  /* LCD_C LCD frequency divider: /8 */
#define LCDDIV_8            (0x4000)  /* LCD_C LCD frequency divider: /9 */
#define LCDDIV_9            (0x4800)  /* LCD_C LCD frequency divider: /10 */
#define LCDDIV_10           (0x5000)  /* LCD_C LCD frequency divider: /11 */
#define LCDDIV_11           (0x5800)  /* LCD_C LCD frequency divider: /12 */
#define LCDDIV_12           (0x6000)  /* LCD_C LCD frequency divider: /13 */
#define LCDDIV_13           (0x6800)  /* LCD_C LCD frequency divider: /14 */
#define LCDDIV_14           (0x7000)  /* LCD_C LCD frequency divider: /15 */
#define LCDDIV_15           (0x7800)  /* LCD_C LCD frequency divider: /16 */
#define LCDDIV_16           (0x8000)  /* LCD_C LCD frequency divider: /17 */
#define LCDDIV_17           (0x8800)  /* LCD_C LCD frequency divider: /18 */
#define LCDDIV_18           (0x9000)  /* LCD_C LCD frequency divider: /19 */
#define LCDDIV_19           (0x9800)  /* LCD_C LCD frequency divider: /20 */
#define LCDDIV_20           (0xA000)  /* LCD_C LCD frequency divider: /21 */
#define LCDDIV_21           (0xA800)  /* LCD_C LCD frequency divider: /22 */
#define LCDDIV_22           (0xB000)  /* LCD_C LCD frequency divider: /23 */
#define LCDDIV_23           (0xB800)  /* LCD_C LCD frequency divider: /24 */
#define LCDDIV_24           (0xC000)  /* LCD_C LCD frequency divider: /25 */
#define LCDDIV_25           (0xC800)  /* LCD_C LCD frequency divider: /26 */
#define LCDDIV_26           (0xD000)  /* LCD_C LCD frequency divider: /27 */
#define LCDDIV_27           (0xD800)  /* LCD_C LCD frequency divider: /28 */
#define LCDDIV_28           (0xE000)  /* LCD_C LCD frequency divider: /29 */
#define LCDDIV_29           (0xE800)  /* LCD_C LCD frequency divider: /30 */
#define LCDDIV_30           (0xF000)  /* LCD_C LCD frequency divider: /31 */
#define LCDDIV_31           (0xF800)  /* LCD_C LCD frequency divider: /32 */
#define LCDDIV__1           (0x0000)  /* LCD_C LCD frequency divider: /1 */
#define LCDDIV__2           (0x0800)  /* LCD_C LCD frequency divider: /2 */
#define LCDDIV__3           (0x1000)  /* LCD_C LCD frequency divider: /3 */
#define LCDDIV__4           (0x1800)  /* LCD_C LCD frequency divider: /4 */
#define LCDDIV__5           (0x2000)  /* LCD_C LCD frequency divider: /5 */
#define LCDDIV__6           (0x2800)  /* LCD_C LCD frequency divider: /6 */
#define LCDDIV__7           (0x3000)  /* LCD_C LCD frequency divider: /7 */
#define LCDDIV__8           (0x3800)  /* LCD_C LCD frequency divider: /8 */
#define LCDDIV__9           (0x4000)  /* LCD_C LCD frequency divider: /9 */
#define LCDDIV__10          (0x4800)  /* LCD_C LCD frequency divider: /10 */
#define LCDDIV__11          (0x5000)  /* LCD_C LCD frequency divider: /11 */
#define LCDDIV__12          (0x5800)  /* LCD_C LCD frequency divider: /12 */
#define LCDDIV__13          (0x6000)  /* LCD_C LCD frequency divider: /13 */
#define LCDDIV__14          (0x6800)  /* LCD_C LCD frequency divider: /14 */
#define LCDDIV__15          (0x7000)  /* LCD_C LCD frequency divider: /15 */
#define LCDDIV__16          (0x7800)  /* LCD_C LCD frequency divider: /16 */
#define LCDDIV__17          (0x8000)  /* LCD_C LCD frequency divider: /17 */
#define LCDDIV__18          (0x8800)  /* LCD_C LCD frequency divider: /18 */
#define LCDDIV__19          (0x9000)  /* LCD_C LCD frequency divider: /19 */
#define LCDDIV__20          (0x9800)  /* LCD_C LCD frequency divider: /20 */
#define LCDDIV__21          (0xA000)  /* LCD_C LCD frequency divider: /21 */
#define LCDDIV__22          (0xA800)  /* LCD_C LCD frequency divider: /22 */
#define LCDDIV__23          (0xB000)  /* LCD_C LCD frequency divider: /23 */
#define LCDDIV__24          (0xB800)  /* LCD_C LCD frequency divider: /24 */
#define LCDDIV__25          (0xC000)  /* LCD_C LCD frequency divider: /25 */
#define LCDDIV__26          (0xC800)  /* LCD_C LCD frequency divider: /26 */
#define LCDDIV__27          (0xD000)  /* LCD_C LCD frequency divider: /27 */
#define LCDDIV__28          (0xD800)  /* LCD_C LCD frequency divider: /28 */
#define LCDDIV__29          (0xE000)  /* LCD_C LCD frequency divider: /29 */
#define LCDDIV__30          (0xE800)  /* LCD_C LCD frequency divider: /30 */
#define LCDDIV__31          (0xF000)  /* LCD_C LCD frequency divider: /31 */
#define LCDDIV__32          (0xF800)  /* LCD_C LCD frequency divider: /32 */


/* Display modes coded with Bits 2-4 */
#define LCDSTATIC           (LCDSON)
#define LCD2MUX             (LCDMX0+LCDSON)
#define LCD3MUX             (LCDMX1+LCDSON)
#define LCD4MUX             (LCDMX1+LCDMX0+LCDSON)
#define LCD5MUX             (LCDMX2+LCDSON)
#define LCD6MUX             (LCDMX2+LCDMX0+LCDSON)
#define LCD7MUX             (LCDMX2+LCDMX1+LCDSON)
#define LCD8MUX             (LCDMX2+LCDMX1+LCDMX0+LCDSON)

// LCDCCTL1
#define LCDFRMIFG           (0x0001)  /* LCD_C LCD frame interrupt flag */
#define LCDBLKOFFIFG        (0x0002)  /* LCD_C LCD blinking off interrupt flag, */
#define LCDBLKONIFG         (0x0004)  /* LCD_C LCD blinking on interrupt flag, */
#define LCDNOCAPIFG         (0x0008)  /* LCD_C No cpacitance connected interrupt flag */
#define LCDFRMIE            (0x0100)  /* LCD_C LCD frame interrupt enable */
#define LCDBLKOFFIE         (0x0200)  /* LCD_C LCD blinking off interrupt flag, */
#define LCDBLKONIE          (0x0400)  /* LCD_C LCD blinking on interrupt flag, */
#define LCDNOCAPIE          (0x0800)  /* LCD_C No cpacitance connected interrupt enable */

// LCDCCTL1
#define LCDFRMIFG_L         (0x0001)  /* LCD_C LCD frame interrupt flag */
#define LCDBLKOFFIFG_L      (0x0002)  /* LCD_C LCD blinking off interrupt flag, */
#define LCDBLKONIFG_L       (0x0004)  /* LCD_C LCD blinking on interrupt flag, */
#define LCDNOCAPIFG_L       (0x0008)  /* LCD_C No cpacitance connected interrupt flag */

// LCDCCTL1
#define LCDFRMIE_H          (0x0001)  /* LCD_C LCD frame interrupt enable */
#define LCDBLKOFFIE_H       (0x0002)  /* LCD_C LCD blinking off interrupt flag, */
#define LCDBLKONIE_H        (0x0004)  /* LCD_C LCD blinking on interrupt flag, */
#define LCDNOCAPIE_H        (0x0008)  /* LCD_C No cpacitance connected interrupt enable */

// LCDCBLKCTL
#define LCDBLKMOD0          (0x0001)  /* LCD_C Blinking mode Bit: 0 */
#define LCDBLKMOD1          (0x0002)  /* LCD_C Blinking mode Bit: 1 */
#define LCDBLKPRE0          (0x0004)  /* LCD_C Clock pre-scaler for blinking frequency Bit: 0 */
#define LCDBLKPRE1          (0x0008)  /* LCD_C Clock pre-scaler for blinking frequency Bit: 1 */
#define LCDBLKPRE2          (0x0010)  /* LCD_C Clock pre-scaler for blinking frequency Bit: 2 */
#define LCDBLKDIV0          (0x0020)  /* LCD_C Clock divider for blinking frequency Bit: 0 */
#define LCDBLKDIV1          (0x0040)  /* LCD_C Clock divider for blinking frequency Bit: 1 */
#define LCDBLKDIV2          (0x0080)  /* LCD_C Clock divider for blinking frequency Bit: 2 */

// LCDCBLKCTL
#define LCDBLKMOD0_L        (0x0001)  /* LCD_C Blinking mode Bit: 0 */
#define LCDBLKMOD1_L        (0x0002)  /* LCD_C Blinking mode Bit: 1 */
#define LCDBLKPRE0_L        (0x0004)  /* LCD_C Clock pre-scaler for blinking frequency Bit: 0 */
#define LCDBLKPRE1_L        (0x0008)  /* LCD_C Clock pre-scaler for blinking frequency Bit: 1 */
#define LCDBLKPRE2_L        (0x0010)  /* LCD_C Clock pre-scaler for blinking frequency Bit: 2 */
#define LCDBLKDIV0_L        (0x0020)  /* LCD_C Clock divider for blinking frequency Bit: 0 */
#define LCDBLKDIV1_L        (0x0040)  /* LCD_C Clock divider for blinking frequency Bit: 1 */
#define LCDBLKDIV2_L        (0x0080)  /* LCD_C Clock divider for blinking frequency Bit: 2 */


#define LCDBLKMOD_0         (0x0000)  /* LCD_C Blinking mode: Off */
#define LCDBLKMOD_1         (0x0001)  /* LCD_C Blinking mode: Individual */
#define LCDBLKMOD_2         (0x0002)  /* LCD_C Blinking mode: All */
#define LCDBLKMOD_3         (0x0003)  /* LCD_C Blinking mode: Switching */

// LCDCMEMCTL
#define LCDDISP             (0x0001)  /* LCD_C LCD memory registers for display */
#define LCDCLRM             (0x0002)  /* LCD_C Clear LCD memory */
#define LCDCLRBM            (0x0004)  /* LCD_C Clear LCD blinking memory */

// LCDCMEMCTL
#define LCDDISP_L           (0x0001)  /* LCD_C LCD memory registers for display */
#define LCDCLRM_L           (0x0002)  /* LCD_C Clear LCD memory */
#define LCDCLRBM_L          (0x0004)  /* LCD_C Clear LCD blinking memory */


// LCDCVCTL
#define LCD2B               (0x0001)  /* Selects 1/2 bias. */
#define VLCDREF0            (0x0002)  /* Selects reference voltage for regulated charge pump: 0 */
#define VLCDREF1            (0x0004)  /* Selects reference voltage for regulated charge pump: 1 */
#define LCDCPEN             (0x0008)  /* LCD Voltage Charge Pump Enable. */
#define VLCDEXT             (0x0010)  /* Select external source for VLCD. */
#define LCDEXTBIAS          (0x0020)  /* V2 - V4 voltage select. */
#define R03EXT              (0x0040)  /* Selects external connections for LCD mid voltages. */
#define LCDREXT             (0x0080)  /* Selects external connection for lowest LCD voltage. */
#define VLCD0               (0x0200)  /* VLCD select: 0 */
#define VLCD1               (0x0400)  /* VLCD select: 1 */
#define VLCD2               (0x0800)  /* VLCD select: 2 */
#define VLCD3               (0x1000)  /* VLCD select: 3 */
#define VLCD4               (0x2000)  /* VLCD select: 4 */
#define VLCD5               (0x4000)  /* VLCD select: 5 */

// LCDCVCTL
#define LCD2B_L             (0x0001)  /* Selects 1/2 bias. */
#define VLCDREF0_L          (0x0002)  /* Selects reference voltage for regulated charge pump: 0 */
#define VLCDREF1_L          (0x0004)  /* Selects reference voltage for regulated charge pump: 1 */
#define LCDCPEN_L           (0x0008)  /* LCD Voltage Charge Pump Enable. */
#define VLCDEXT_L           (0x0010)  /* Select external source for VLCD. */
#define LCDEXTBIAS_L        (0x0020)  /* V2 - V4 voltage select. */
#define R03EXT_L            (0x0040)  /* Selects external connections for LCD mid voltages. */
#define LCDREXT_L           (0x0080)  /* Selects external connection for lowest LCD voltage. */

// LCDCVCTL
#define VLCD0_H             (0x0002)  /* VLCD select: 0 */
#define VLCD1_H             (0x0004)  /* VLCD select: 1 */
#define VLCD2_H             (0x0008)  /* VLCD select: 2 */
#define VLCD3_H             (0x0010)  /* VLCD select: 3 */
#define VLCD4_H             (0x0020)  /* VLCD select: 4 */
#define VLCD5_H             (0x0040)  /* VLCD select: 5 */

/* Reference voltage source select for the regulated charge pump */
#define VLCDREF_0              (0x0000)       /* Internal */
#define VLCDREF_1              (0x0002)       /* External */
#define VLCDREF_2              (0x0004)       /* Reserved */
#define VLCDREF_3              (0x0006)       /* Reserved */


/* Charge pump voltage selections */
#define VLCD_0                 (0x0000)       /* Charge pump disabled */
#define VLCD_1                 (0x0200)       /* VLCD = 2.60V */
#define VLCD_2                 (0x0400)       /* VLCD = 2.66V */
#define VLCD_3                 (0x0600)       /* VLCD = 2.72V */
#define VLCD_4                 (0x0800)       /* VLCD = 2.78V */
#define VLCD_5                 (0x0A00)       /* VLCD = 2.84V */
#define VLCD_6                 (0x0C00)       /* VLCD = 2.90V */
#define VLCD_7                 (0x0E00)       /* VLCD = 2.96V */
#define VLCD_8                 (0x1000)       /* VLCD = 3.02V */
#define VLCD_9                 (0x1200)       /* VLCD = 3.08V */
#define VLCD_10                (0x1400)       /* VLCD = 3.14V */
#define VLCD_11                (0x1600)       /* VLCD = 3.20V */
#define VLCD_12                (0x1800)       /* VLCD = 3.26V */
#define VLCD_13                (0x1A00)       /* VLCD = 3.32V */
#define VLCD_14                (0x1C00)       /* VLCD = 3.38V */
#define VLCD_15                (0x1E00)       /* VLCD = 3.44V */

#define VLCD_DISABLED          (0x0000)       /* Charge pump disabled */
#define VLCD_2_60              (0x0200)       /* VLCD = 2.60V */
#define VLCD_2_66              (0x0400)       /* VLCD = 2.66V */
#define VLCD_2_72              (0x0600)       /* VLCD = 2.72V */
#define VLCD_2_78              (0x0800)       /* VLCD = 2.78V */
#define VLCD_2_84              (0x0A00)       /* VLCD = 2.84V */
#define VLCD_2_90              (0x0C00)       /* VLCD = 2.90V */
#define VLCD_2_96              (0x0E00)       /* VLCD = 2.96V */
#define VLCD_3_02              (0x1000)       /* VLCD = 3.02V */
#define VLCD_3_08              (0x1200)       /* VLCD = 3.08V */
#define VLCD_3_14              (0x1400)       /* VLCD = 3.14V */
#define VLCD_3_20              (0x1600)       /* VLCD = 3.20V */
#define VLCD_3_26              (0x1800)       /* VLCD = 3.26V */
#define VLCD_3_32              (0x1A00)       /* VLCD = 3.32V */
#define VLCD_3_38              (0x1C00)       /* VLCD = 3.38V */
#define VLCD_3_44              (0x1E00)       /* VLCD = 3.44V */


// LCDCPCTL0
#define LCDS0               (0x0001)  /* LCD Segment  0 enable. */
#define LCDS1               (0x0002)  /* LCD Segment  1 enable. */
#define LCDS2               (0x0004)  /* LCD Segment  2 enable. */
#define LCDS3               (0x0008)  /* LCD Segment  3 enable. */
#define LCDS4               (0x0010)  /* LCD Segment  4 enable. */
#define LCDS5               (0x0020)  /* LCD Segment  5 enable. */
#define LCDS6               (0x0040)  /* LCD Segment  6 enable. */
#define LCDS7               (0x0080)  /* LCD Segment  7 enable. */
#define LCDS8               (0x0100)  /* LCD Segment  8 enable. */
#define LCDS9               (0x0200)  /* LCD Segment  9 enable. */
#define LCDS10              (0x0400)  /* LCD Segment 10 enable. */
#define LCDS11              (0x0800)  /* LCD Segment 11 enable. */
#define LCDS12              (0x1000)  /* LCD Segment 12 enable. */
#define LCDS13              (0x2000)  /* LCD Segment 13 enable. */
#define LCDS14              (0x4000)  /* LCD Segment 14 enable. */
#define LCDS15              (0x8000)  /* LCD Segment 15 enable. */

// LCDCPCTL0
#define LCDS0_L             (0x0001)  /* LCD Segment  0 enable. */
#define LCDS1_L             (0x0002)  /* LCD Segment  1 enable. */
#define LCDS2_L             (0x0004)  /* LCD Segment  2 enable. */
#define LCDS3_L             (0x0008)  /* LCD Segment  3 enable. */
#define LCDS4_L             (0x0010)  /* LCD Segment  4 enable. */
#define LCDS5_L             (0x0020)  /* LCD Segment  5 enable. */
#define LCDS6_L             (0x0040)  /* LCD Segment  6 enable. */
#define LCDS7_L             (0x0080)  /* LCD Segment  7 enable. */

// LCDCPCTL0
#define LCDS8_H             (0x0001)  /* LCD Segment  8 enable. */
#define LCDS9_H             (0x0002)  /* LCD Segment  9 enable. */
#define LCDS10_H            (0x0004)  /* LCD Segment 10 enable. */
#define LCDS11_H            (0x0008)  /* LCD Segment 11 enable. */
#define LCDS12_H            (0x0010)  /* LCD Segment 12 enable. */
#define LCDS13_H            (0x0020)  /* LCD Segment 13 enable. */
#define LCDS14_H            (0x0040)  /* LCD Segment 14 enable. */
#define LCDS15_H            (0x0080)  /* LCD Segment 15 enable. */

// LCDCPCTL1
#define LCDS16              (0x0001)  /* LCD Segment 16 enable. */
#define LCDS17              (0x0002)  /* LCD Segment 17 enable. */
#define LCDS18              (0x0004)  /* LCD Segment 18 enable. */
#define LCDS19              (0x0008)  /* LCD Segment 19 enable. */
#define LCDS20              (0x0010)  /* LCD Segment 20 enable. */
#define LCDS21              (0x0020)  /* LCD Segment 21 enable. */
#define LCDS22              (0x0040)  /* LCD Segment 22 enable. */
#define LCDS23              (0x0080)  /* LCD Segment 23 enable. */
#define LCDS24              (0x0100)  /* LCD Segment 24 enable. */
#define LCDS25              (0x0200)  /* LCD Segment 25 enable. */
#define LCDS26              (0x0400)  /* LCD Segment 26 enable. */
#define LCDS27              (0x0800)  /* LCD Segment 27 enable. */
#define LCDS28              (0x1000)  /* LCD Segment 28 enable. */
#define LCDS29              (0x2000)  /* LCD Segment 29 enable. */
#define LCDS30              (0x4000)  /* LCD Segment 30 enable. */
#define LCDS31              (0x8000)  /* LCD Segment 31 enable. */

// LCDCPCTL1
#define LCDS16_L            (0x0001)  /* LCD Segment 16 enable. */
#define LCDS17_L            (0x0002)  /* LCD Segment 17 enable. */
#define LCDS18_L            (0x0004)  /* LCD Segment 18 enable. */
#define LCDS19_L            (0x0008)  /* LCD Segment 19 enable. */
#define LCDS20_L            (0x0010)  /* LCD Segment 20 enable. */
#define LCDS21_L            (0x0020)  /* LCD Segment 21 enable. */
#define LCDS22_L            (0x0040)  /* LCD Segment 22 enable. */
#define LCDS23_L            (0x0080)  /* LCD Segment 23 enable. */

// LCDCPCTL1
#define LCDS24_H            (0x0001)  /* LCD Segment 24 enable. */
#define LCDS25_H            (0x0002)  /* LCD Segment 25 enable. */
#define LCDS26_H            (0x0004)  /* LCD Segment 26 enable. */
#define LCDS27_H            (0x0008)  /* LCD Segment 27 enable. */
#define LCDS28_H            (0x0010)  /* LCD Segment 28 enable. */
#define LCDS29_H            (0x0020)  /* LCD Segment 29 enable. */
#define LCDS30_H            (0x0040)  /* LCD Segment 30 enable. */
#define LCDS31_H            (0x0080)  /* LCD Segment 31 enable. */

// LCDCPCTL2
#define LCDS32              (0x0001)  /* LCD Segment 32 enable. */
#define LCDS33              (0x0002)  /* LCD Segment 33 enable. */
#define LCDS34              (0x0004)  /* LCD Segment 34 enable. */
#define LCDS35              (0x0008)  /* LCD Segment 35 enable. */
#define LCDS36              (0x0010)  /* LCD Segment 36 enable. */
#define LCDS37              (0x0020)  /* LCD Segment 37 enable. */
#define LCDS38              (0x0040)  /* LCD Segment 38 enable. */
#define LCDS39              (0x0080)  /* LCD Segment 39 enable. */
#define LCDS40              (0x0100)  /* LCD Segment 40 enable. */
#define LCDS41              (0x0200)  /* LCD Segment 41 enable. */
#define LCDS42              (0x0400)  /* LCD Segment 42 enable. */
#define LCDS43              (0x0800)  /* LCD Segment 43 enable. */
#define LCDS44              (0x1000)  /* LCD Segment 44 enable. */
#define LCDS45              (0x2000)  /* LCD Segment 45 enable. */
#define LCDS46              (0x4000)  /* LCD Segment 46 enable. */
#define LCDS47              (0x8000)  /* LCD Segment 47 enable. */

// LCDCPCTL2
#define LCDS32_L            (0x0001)  /* LCD Segment 32 enable. */
#define LCDS33_L            (0x0002)  /* LCD Segment 33 enable. */
#define LCDS34_L            (0x0004)  /* LCD Segment 34 enable. */
#define LCDS35_L            (0x0008)  /* LCD Segment 35 enable. */
#define LCDS36_L            (0x0010)  /* LCD Segment 36 enable. */
#define LCDS37_L            (0x0020)  /* LCD Segment 37 enable. */
#define LCDS38_L            (0x0040)  /* LCD Segment 38 enable. */
#define LCDS39_L            (0x0080)  /* LCD Segment 39 enable. */

// LCDCPCTL2
#define LCDS40_H            (0x0001)  /* LCD Segment 40 enable. */
#define LCDS41_H            (0x0002)  /* LCD Segment 41 enable. */
#define LCDS42_H            (0x0004)  /* LCD Segment 42 enable. */
#define LCDS43_H            (0x0008)  /* LCD Segment 43 enable. */
#define LCDS44_H            (0x0010)  /* LCD Segment 44 enable. */
#define LCDS45_H            (0x0020)  /* LCD Segment 45 enable. */
#define LCDS46_H            (0x0040)  /* LCD Segment 46 enable. */
#define LCDS47_H            (0x0080)  /* LCD Segment 47 enable. */


// LCDCCPCTL
#define LCDCPDIS0           (0x0001)  /* LCD charge pump disable */
#define LCDCPDIS1           (0x0002)  /* LCD charge pump disable */
#define LCDCPDIS2           (0x0004)  /* LCD charge pump disable */
#define LCDCPDIS3           (0x0008)  /* LCD charge pump disable */
#define LCDCPDIS4           (0x0010)  /* LCD charge pump disable */
#define LCDCPDIS5           (0x0020)  /* LCD charge pump disable */
#define LCDCPDIS6           (0x0040)  /* LCD charge pump disable */
#define LCDCPDIS7           (0x0080)  /* LCD charge pump disable */
#define LCDCPCLKSYNC        (0x8000)  /* LCD charge pump clock synchronization */

// LCDCCPCTL
#define LCDCPDIS0_L         (0x0001)  /* LCD charge pump disable */
#define LCDCPDIS1_L         (0x0002)  /* LCD charge pump disable */
#define LCDCPDIS2_L         (0x0004)  /* LCD charge pump disable */
#define LCDCPDIS3_L         (0x0008)  /* LCD charge pump disable */
#define LCDCPDIS4_L         (0x0010)  /* LCD charge pump disable */
#define LCDCPDIS5_L         (0x0020)  /* LCD charge pump disable */
#define LCDCPDIS6_L         (0x0040)  /* LCD charge pump disable */
#define LCDCPDIS7_L         (0x0080)  /* LCD charge pump disable */

// LCDCCPCTL
#define LCDCPCLKSYNC_H      (0x0080)  /* LCD charge pump clock synchronization */

#define OFS_LCDM1             (0x0020)  /* LCD Memory 1 */
#define LCDMEM_             LCDM1     /* LCD Memory */
#ifndef __STDC__
#define LCDMEM              LCDM1     /* LCD Memory (for assembler) */
#else
#define LCDMEM              ((volatile char*) &LCDM1) /* LCD Memory (for C) */
#endif
#define OFS_LCDM2             (0x0021)  /* LCD Memory 2 */
#define OFS_LCDM3             (0x0022)  /* LCD Memory 3 */
#define OFS_LCDM4             (0x0023)  /* LCD Memory 4 */
#define OFS_LCDM5             (0x0024)  /* LCD Memory 5 */
#define OFS_LCDM6             (0x0025)  /* LCD Memory 6 */
#define OFS_LCDM7             (0x0026)  /* LCD Memory 7 */
#define OFS_LCDM8             (0x0027)  /* LCD Memory 8 */
#define OFS_LCDM9             (0x0028)  /* LCD Memory 9 */
#define OFS_LCDM10            (0x0029)  /* LCD Memory 10 */
#define OFS_LCDM11            (0x002A)  /* LCD Memory 11 */
#define OFS_LCDM12            (0x002B)  /* LCD Memory 12 */
#define OFS_LCDM13            (0x002C)  /* LCD Memory 13 */
#define OFS_LCDM14            (0x002D)  /* LCD Memory 14 */
#define OFS_LCDM15            (0x002E)  /* LCD Memory 15 */
#define OFS_LCDM16            (0x002F)  /* LCD Memory 16 */
#define OFS_LCDM17            (0x0030)  /* LCD Memory 17 */
#define OFS_LCDM18            (0x0031)  /* LCD Memory 18 */
#define OFS_LCDM19            (0x0032)  /* LCD Memory 19 */
#define OFS_LCDM20            (0x0033)  /* LCD Memory 20 */
#define OFS_LCDM21            (0x0034)  /* LCD Memory 21 */
#define OFS_LCDM22            (0x0035)  /* LCD Memory 22 */
#define OFS_LCDM23            (0x0036)  /* LCD Memory 23 */
#define OFS_LCDM24            (0x0037)  /* LCD Memory 24 */
#define OFS_LCDM25            (0x0038)  /* LCD Memory 25 */
#define OFS_LCDM26            (0x0039)  /* LCD Memory 26 */
#define OFS_LCDM27            (0x003A)  /* LCD Memory 27 */
#define OFS_LCDM28            (0x003B)  /* LCD Memory 28 */
#define OFS_LCDM29            (0x003C)  /* LCD Memory 29 */
#define OFS_LCDM30            (0x003D)  /* LCD Memory 30 */
#define OFS_LCDM31            (0x003E)  /* LCD Memory 31 */
#define OFS_LCDM32            (0x003F)  /* LCD Memory 32 */
#define OFS_LCDM33            (0x0040)  /* LCD Memory 33 */
#define OFS_LCDM34            (0x0041)  /* LCD Memory 34 */
#define OFS_LCDM35            (0x0042)  /* LCD Memory 35 */
#define OFS_LCDM36            (0x0043)  /* LCD Memory 36 */
#define OFS_LCDM37            (0x0044)  /* LCD Memory 37 */
#define OFS_LCDM38            (0x0045)  /* LCD Memory 38 */
#define OFS_LCDM39            (0x0046)  /* LCD Memory 39 */
#define OFS_LCDM40            (0x0047)  /* LCD Memory 40 */

#define OFS_LCDBM1            (0x0040)  /* LCD Blinking Memory 1 */
#define LCDBMEM_            LCDBM1    /* LCD Blinking Memory */
#ifndef __STDC__
#define LCDBMEM             (LCDBM1)  /* LCD Blinking Memory (for assembler) */
#else
#define LCDBMEM             ((volatile char*) &LCDBM1) /* LCD Blinking Memory (for C) */
#endif
#define OFS_LCDBM2            (0x0041)  /* LCD Blinking Memory 2 */
#define OFS_LCDBM3            (0x0042)  /* LCD Blinking Memory 3 */
#define OFS_LCDBM4            (0x0043)  /* LCD Blinking Memory 4 */
#define OFS_LCDBM5            (0x0044)  /* LCD Blinking Memory 5 */
#define OFS_LCDBM6            (0x0045)  /* LCD Blinking Memory 6 */
#define OFS_LCDBM7            (0x0046)  /* LCD Blinking Memory 7 */
#define OFS_LCDBM8            (0x0047)  /* LCD Blinking Memory 8 */
#define OFS_LCDBM9            (0x0048)  /* LCD Blinking Memory 9 */
#define OFS_LCDBM10           (0x0049)  /* LCD Blinking Memory 10 */
#define OFS_LCDBM11           (0x004A)  /* LCD Blinking Memory 11 */
#define OFS_LCDBM12           (0x004B)  /* LCD Blinking Memory 12 */
#define OFS_LCDBM13           (0x004C)  /* LCD Blinking Memory 13 */
#define OFS_LCDBM14           (0x004D)  /* LCD Blinking Memory 14 */
#define OFS_LCDBM15           (0x004E)  /* LCD Blinking Memory 15 */
#define OFS_LCDBM16           (0x004F)  /* LCD Blinking Memory 16 */
#define OFS_LCDBM17           (0x0050)  /* LCD Blinking Memory 17 */
#define OFS_LCDBM18           (0x0051)  /* LCD Blinking Memory 18 */
#define OFS_LCDBM19           (0x0052)  /* LCD Blinking Memory 19 */
#define OFS_LCDBM20           (0x0053)  /* LCD Blinking Memory 20 */

/* LCDCIV Definitions */
#define LCDCIV_NONE         (0x0000)    /* No Interrupt pending */
#define LCDCIV_LCDNOCAPIFG  (0x0002)    /* No capacitor connected */
#define LCDCIV_LCDCLKOFFIFG (0x0004)    /* Blink, segments off */
#define LCDCIV_LCDCLKONIFG  (0x0006)    /* Blink, segments on */
#define LCDCIV_LCDFRMIFG    (0x0008)    /* Frame interrupt */

#endif
/************************************************************
* HARDWARE MULTIPLIER 32Bit
************************************************************/
#ifdef  __MSP430_HAS_MPY32__          /* Definition to show that Module is available */

#define OFS_MPY               (0x0000)  /* Multiply Unsigned/Operand 1 */
#define OFS_MPY_L              OFS_MPY
#define OFS_MPY_H              OFS_MPY+1
#define OFS_MPYS              (0x0002)  /* Multiply Signed/Operand 1 */
#define OFS_MPYS_L             OFS_MPYS
#define OFS_MPYS_H             OFS_MPYS+1
#define OFS_MAC               (0x0004)  /* Multiply Unsigned and Accumulate/Operand 1 */
#define OFS_MAC_L              OFS_MAC
#define OFS_MAC_H              OFS_MAC+1
#define OFS_MACS              (0x0006)  /* Multiply Signed and Accumulate/Operand 1 */
#define OFS_MACS_L             OFS_MACS
#define OFS_MACS_H             OFS_MACS+1
#define OFS_OP2               (0x0008)  /* Operand 2 */
#define OFS_OP2_L              OFS_OP2
#define OFS_OP2_H              OFS_OP2+1
#define OFS_RESLO             (0x000A)  /* Result Low Word */
#define OFS_RESLO_L            OFS_RESLO
#define OFS_RESLO_H            OFS_RESLO+1
#define OFS_RESHI             (0x000C)  /* Result High Word */
#define OFS_RESHI_L            OFS_RESHI
#define OFS_RESHI_H            OFS_RESHI+1
#define OFS_SUMEXT            (0x000E)  /* Sum Extend */
#define OFS_SUMEXT_L           OFS_SUMEXT
#define OFS_SUMEXT_H           OFS_SUMEXT+1
#define OFS_MPY32CTL0         (0x002C)
#define OFS_MPY32CTL0_L        OFS_MPY32CTL0
#define OFS_MPY32CTL0_H        OFS_MPY32CTL0+1

#define OFS_MPY32L            (0x0010)  /* 32-bit operand 1 - multiply - low word */
#define OFS_MPY32L_L           OFS_MPY32L
#define OFS_MPY32L_H           OFS_MPY32L+1
#define OFS_MPY32H            (0x0012)  /* 32-bit operand 1 - multiply - high word */
#define OFS_MPY32H_L           OFS_MPY32H
#define OFS_MPY32H_H           OFS_MPY32H+1
#define OFS_MPYS32L           (0x0014)  /* 32-bit operand 1 - signed multiply - low word */
#define OFS_MPYS32L_L          OFS_MPYS32L
#define OFS_MPYS32L_H          OFS_MPYS32L+1
#define OFS_MPYS32H           (0x0016)  /* 32-bit operand 1 - signed multiply - high word */
#define OFS_MPYS32H_L          OFS_MPYS32H
#define OFS_MPYS32H_H          OFS_MPYS32H+1
#define OFS_MAC32L            (0x0018)  /* 32-bit operand 1 - multiply accumulate - low word */
#define OFS_MAC32L_L           OFS_MAC32L
#define OFS_MAC32L_H           OFS_MAC32L+1
#define OFS_MAC32H            (0x001A)  /* 32-bit operand 1 - multiply accumulate - high word */
#define OFS_MAC32H_L           OFS_MAC32H
#define OFS_MAC32H_H           OFS_MAC32H+1
#define OFS_MACS32L           (0x001C)  /* 32-bit operand 1 - signed multiply accumulate - low word */
#define OFS_MACS32L_L          OFS_MACS32L
#define OFS_MACS32L_H          OFS_MACS32L+1
#define OFS_MACS32H           (0x001E)  /* 32-bit operand 1 - signed multiply accumulate - high word */
#define OFS_MACS32H_L          OFS_MACS32H
#define OFS_MACS32H_H          OFS_MACS32H+1
#define OFS_OP2L              (0x0020)  /* 32-bit operand 2 - low word */
#define OFS_OP2L_L             OFS_OP2L
#define OFS_OP2L_H             OFS_OP2L+1
#define OFS_OP2H              (0x0022)  /* 32-bit operand 2 - high word */
#define OFS_OP2H_L             OFS_OP2H
#define OFS_OP2H_H             OFS_OP2H+1
#define OFS_RES0              (0x0024)  /* 32x32-bit result 0 - least significant word */
#define OFS_RES0_L             OFS_RES0
#define OFS_RES0_H             OFS_RES0+1
#define OFS_RES1              (0x0026)  /* 32x32-bit result 1 */
#define OFS_RES1_L             OFS_RES1
#define OFS_RES1_H             OFS_RES1+1
#define OFS_RES2              (0x0028)  /* 32x32-bit result 2 */
#define OFS_RES2_L             OFS_RES2
#define OFS_RES2_H             OFS_RES2+1
#define OFS_RES3              (0x002A)  /* 32x32-bit result 3 - most significant word */
#define OFS_RES3_L             OFS_RES3
#define OFS_RES3_H             OFS_RES3+1
#define OFS_SUMEXT            (0x000E)
#define OFS_SUMEXT_L           OFS_SUMEXT
#define OFS_SUMEXT_H           OFS_SUMEXT+1
#define OFS_MPY32CTL0         (0x002C)  /* MPY32 Control Register 0 */
#define OFS_MPY32CTL0_L        OFS_MPY32CTL0
#define OFS_MPY32CTL0_H        OFS_MPY32CTL0+1

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

#endif
/************************************************************
* DIGITAL I/O Port1/2 Pull up / Pull down Resistors
************************************************************/
#ifdef  __MSP430_HAS_PORT1_R__        /* Definition to show that Module is available */
#ifdef  __MSP430_HAS_PORT2_R__        /* Definition to show that Module is available */
#ifdef  __MSP430_HAS_PORTA_R__        /* Definition to show that Module is available */

#define OFS_PAIN              (0x0000)  /* Port A Input */
#define OFS_PAIN_L             OFS_PAIN
#define OFS_PAIN_H             OFS_PAIN+1
#define OFS_PAOUT             (0x0002)  /* Port A Output */
#define OFS_PAOUT_L            OFS_PAOUT
#define OFS_PAOUT_H            OFS_PAOUT+1
#define OFS_PADIR             (0x0004)  /* Port A Direction */
#define OFS_PADIR_L            OFS_PADIR
#define OFS_PADIR_H            OFS_PADIR+1
#define OFS_PAREN             (0x0006)  /* Port A Resistor Enable */
#define OFS_PAREN_L            OFS_PAREN
#define OFS_PAREN_H            OFS_PAREN+1
#define OFS_PADS              (0x0008)  /* Port A Drive Strenght */
#define OFS_PADS_L             OFS_PADS
#define OFS_PADS_H             OFS_PADS+1
#define OFS_PASEL             (0x000A)  /* Port A Selection */
#define OFS_PASEL_L            OFS_PASEL
#define OFS_PASEL_H            OFS_PASEL+1
#define OFS_PAIES             (0x0018)  /* Port A Interrupt Edge Select */
#define OFS_PAIES_L            OFS_PAIES
#define OFS_PAIES_H            OFS_PAIES+1
#define OFS_PAIE              (0x001A)  /* Port A Interrupt Enable */
#define OFS_PAIE_L             OFS_PAIE
#define OFS_PAIE_H             OFS_PAIE+1
#define OFS_PAIFG             (0x001C)  /* Port A Interrupt Flag */
#define OFS_PAIFG_L            OFS_PAIFG
#define OFS_PAIFG_H            OFS_PAIFG+1





















#define OFS_P1IN              (0x0000)
#define OFS_P1OUT             (0x0002)
#define OFS_P1DIR             (0x0004)
#define OFS_P1REN             (0x0006)
#define OFS_P1DS              (0x0008)
#define OFS_P1SEL             (0x000A)
#define OFS_P1IV              (0x000E)  /* Port 1 Interrupt Vector Word */
#define OFS_P1IES             (0x0018)
#define OFS_P1IE              (0x001A)
#define OFS_P1IFG             (0x001C)
#define OFS_P2IN              (0x0001)
#define OFS_P2OUT             (0x0003)
#define OFS_P2DIR             (0x0005)
#define OFS_P2REN             (0x0007)
#define OFS_P2DS              (0x0009)
#define OFS_P2SEL             (0x000B)
#define OFS_P2IV              (0x001E)  /* Port 2 Interrupt Vector Word */
#define OFS_P2IES             (0x0019)
#define OFS_P2IE              (0x001B)
#define OFS_P2IFG             (0x001d)
#define P1IN                (PAIN_L)  /* Port 1 Input */
#define P1OUT               (PAOUT_L) /* Port 1 Output */
#define P1DIR               (PADIR_L) /* Port 1 Direction */
#define P1REN               (PAREN_L) /* Port 1 Resistor Enable */
#define P1DS                (PADS_L)  /* Port 1 Drive Strenght */
#define P1SEL               (PASEL_L) /* Port 1 Selection */
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
#define P2DS                (PADS_H)  /* Port 2 Drive Strenght */
#define P2SEL               (PASEL_H) /* Port 2 Selection */
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



#endif
#endif
#endif
/************************************************************
* DIGITAL I/O Port3/4 Pull up / Pull down Resistors
************************************************************/
#ifdef  __MSP430_HAS_PORT3_R__        /* Definition to show that Module is available */
#ifdef  __MSP430_HAS_PORT4_R__        /* Definition to show that Module is available */
#ifdef  __MSP430_HAS_PORTB_R__        /* Definition to show that Module is available */

#define OFS_PBIN              (0x0000)  /* Port B Input */
#define OFS_PBIN_L             OFS_PBIN
#define OFS_PBIN_H             OFS_PBIN+1
#define OFS_PBOUT             (0x0002)  /* Port B Output */
#define OFS_PBOUT_L            OFS_PBOUT
#define OFS_PBOUT_H            OFS_PBOUT+1
#define OFS_PBDIR             (0x0004)  /* Port B Direction */
#define OFS_PBDIR_L            OFS_PBDIR
#define OFS_PBDIR_H            OFS_PBDIR+1
#define OFS_PBREN             (0x0006)  /* Port B Resistor Enable */
#define OFS_PBREN_L            OFS_PBREN
#define OFS_PBREN_H            OFS_PBREN+1
#define OFS_PBDS              (0x0008)  /* Port B Drive Strenght */
#define OFS_PBDS_L             OFS_PBDS
#define OFS_PBDS_H             OFS_PBDS+1
#define OFS_PBSEL             (0x000A)  /* Port B Selection */
#define OFS_PBSEL_L            OFS_PBSEL
#define OFS_PBSEL_H            OFS_PBSEL+1
#define OFS_PBIES             (0x0018)  /* Port B Interrupt Edge Select */
#define OFS_PBIES_L            OFS_PBIES
#define OFS_PBIES_H            OFS_PBIES+1
#define OFS_PBIE              (0x001A)  /* Port B Interrupt Enable */
#define OFS_PBIE_L             OFS_PBIE
#define OFS_PBIE_H             OFS_PBIE+1
#define OFS_PBIFG             (0x001C)  /* Port B Interrupt Flag */
#define OFS_PBIFG_L            OFS_PBIFG
#define OFS_PBIFG_H            OFS_PBIFG+1





















#define OFS_P3IN              (0x0000)
#define OFS_P3OUT             (0x0002)
#define OFS_P3DIR             (0x0004)
#define OFS_P3REN             (0x0006)
#define OFS_P3DS              (0x0008)
#define OFS_P3SEL             (0x000A)
#define OFS_P3IV              (0x000E)  /* Port 3 Interrupt Vector Word */
#define OFS_P3IES             (0x0018)
#define OFS_P3IE              (0x001A)
#define OFS_P3IFG             (0x001C)
#define OFS_P4IN              (0x0001)
#define OFS_P4OUT             (0x0003)
#define OFS_P4DIR             (0x0005)
#define OFS_P4REN             (0x0007)
#define OFS_P4DS              (0x0009)
#define OFS_P4SEL             (0x000B)
#define OFS_P4IV              (0x001E)  /* Port 4 Interrupt Vector Word */
#define OFS_P4IES             (0x0019)
#define OFS_P4IE              (0x001B)
#define OFS_P4IFG             (0x001d)
#define P3IN                (PBIN_L)  /* Port 3 Input */
#define P3OUT               (PBOUT_L) /* Port 3 Output */
#define P3DIR               (PBDIR_L) /* Port 3 Direction */
#define P3REN               (PBREN_L) /* Port 3 Resistor Enable */
#define P3DS                (PBDS_L)  /* Port 3 Drive Strenght */
#define P3SEL               (PBSEL_L) /* Port 3 Selection */
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
#define P4DS                (PBDS_H)  /* Port 4 Drive Strenght */
#define P4SEL               (PBSEL_H) /* Port 4 Selection */
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



#endif
#endif
#endif
/************************************************************
* DIGITAL I/O Port5/6 Pull up / Pull down Resistors
************************************************************/
#ifdef  __MSP430_HAS_PORT5_R__        /* Definition to show that Module is available */
#ifdef  __MSP430_HAS_PORT6_R__        /* Definition to show that Module is available */
#ifdef  __MSP430_HAS_PORTC_R__        /* Definition to show that Module is available */

#define OFS_PCIN              (0x0000)  /* Port C Input */
#define OFS_PCIN_L             OFS_PCIN
#define OFS_PCIN_H             OFS_PCIN+1
#define OFS_PCOUT             (0x0002)  /* Port C Output */
#define OFS_PCOUT_L            OFS_PCOUT
#define OFS_PCOUT_H            OFS_PCOUT+1
#define OFS_PCDIR             (0x0004)  /* Port C Direction */
#define OFS_PCDIR_L            OFS_PCDIR
#define OFS_PCDIR_H            OFS_PCDIR+1
#define OFS_PCREN             (0x0006)  /* Port C Resistor Enable */
#define OFS_PCREN_L            OFS_PCREN
#define OFS_PCREN_H            OFS_PCREN+1
#define OFS_PCDS              (0x0008)  /* Port C Drive Strenght */
#define OFS_PCDS_L             OFS_PCDS
#define OFS_PCDS_H             OFS_PCDS+1
#define OFS_PCSEL             (0x000A)  /* Port C Selection */
#define OFS_PCSEL_L            OFS_PCSEL
#define OFS_PCSEL_H            OFS_PCSEL+1
#define OFS_PCIES             (0x0018)  /* Port C Interrupt Edge Select */
#define OFS_PCIES_L            OFS_PCIES
#define OFS_PCIES_H            OFS_PCIES+1
#define OFS_PCIE              (0x001A)  /* Port C Interrupt Enable */
#define OFS_PCIE_L             OFS_PCIE
#define OFS_PCIE_H             OFS_PCIE+1
#define OFS_PCIFG             (0x001C)  /* Port C Interrupt Flag */
#define OFS_PCIFG_L            OFS_PCIFG
#define OFS_PCIFG_H            OFS_PCIFG+1





















#define OFS_P5IN              (0x0000)
#define OFS_P5OUT             (0x0002)
#define OFS_P5DIR             (0x0004)
#define OFS_P5REN             (0x0006)
#define OFS_P5DS              (0x0008)
#define OFS_P5SEL             (0x000A)
#define OFS_P5IV              (0x000E)  /* Port 5 Interrupt Vector Word */
#define OFS_P5IES             (0x0018)
#define OFS_P5IE              (0x001A)
#define OFS_P5IFG             (0x001C)
#define OFS_P6IN              (0x0001)
#define OFS_P6OUT             (0x0003)
#define OFS_P6DIR             (0x0005)
#define OFS_P6REN             (0x0007)
#define OFS_P6DS              (0x0009)
#define OFS_P6SEL             (0x000B)
#define OFS_P6IV              (0x001E)  /* Port 6 Interrupt Vector Word */
#define OFS_P6IES             (0x0019)
#define OFS_P6IE              (0x001B)
#define OFS_P6IFG             (0x001d)
#define P5IN                (PCIN_L)  /* Port 5 Input */
#define P5OUT               (PCOUT_L) /* Port 5 Output */
#define P5DIR               (PCDIR_L) /* Port 5 Direction */
#define P5REN               (PCREN_L) /* Port 5 Resistor Enable */
#define P5DS                (PCDS_L)  /* Port 5 Drive Strenght */
#define P5SEL               (PCSEL_L) /* Port 5 Selection */
#define P5IES               (PCIES_L) /* Port 5 Interrupt Edge Select */
#define P5IE                (PCIE_L)  /* Port 5 Interrupt Enable */
#define P5IFG               (PCIFG_L) /* Port 5 Interrupt Flag */

//Definitions for P5IV
#define P5IV_NONE            (0x0000)    /* No Interrupt pending */
#define P5IV_P5IFG0          (0x0002)    /* P5IV P5IFG.0 */
#define P5IV_P5IFG1          (0x0004)    /* P5IV P5IFG.1 */
#define P5IV_P5IFG2          (0x0006)    /* P5IV P5IFG.2 */
#define P5IV_P5IFG3          (0x0008)    /* P5IV P5IFG.3 */
#define P5IV_P5IFG4          (0x000A)    /* P5IV P5IFG.4 */
#define P5IV_P5IFG5          (0x000C)    /* P5IV P5IFG.5 */
#define P5IV_P5IFG6          (0x000E)    /* P5IV P5IFG.6 */
#define P5IV_P5IFG7          (0x0010)    /* P5IV P5IFG.7 */


#define P6IN                (PCIN_H)  /* Port 6 Input */
#define P6OUT               (PCOUT_H) /* Port 6 Output */
#define P6DIR               (PCDIR_H) /* Port 6 Direction */
#define P6REN               (PCREN_H) /* Port 6 Resistor Enable */
#define P6DS                (PCDS_H)  /* Port 6 Drive Strenght */
#define P6SEL               (PCSEL_H) /* Port 6 Selection */
#define P6IES               (PCIES_H) /* Port 6 Interrupt Edge Select */
#define P6IE                (PCIE_H)  /* Port 6 Interrupt Enable */
#define P6IFG               (PCIFG_H) /* Port 6 Interrupt Flag */

//Definitions for P6IV
#define P6IV_NONE            (0x0000)    /* No Interrupt pending */
#define P6IV_P6IFG0          (0x0002)    /* P6IV P6IFG.0 */
#define P6IV_P6IFG1          (0x0004)    /* P6IV P6IFG.1 */
#define P6IV_P6IFG2          (0x0006)    /* P6IV P6IFG.2 */
#define P6IV_P6IFG3          (0x0008)    /* P6IV P6IFG.3 */
#define P6IV_P6IFG4          (0x000A)    /* P6IV P6IFG.4 */
#define P6IV_P6IFG5          (0x000C)    /* P6IV P6IFG.5 */
#define P6IV_P6IFG6          (0x000E)    /* P6IV P6IFG.6 */
#define P6IV_P6IFG7          (0x0010)    /* P6IV P6IFG.7 */



#endif
#endif
#endif
/************************************************************
* DIGITAL I/O Port7/8 Pull up / Pull down Resistors
************************************************************/
#ifdef  __MSP430_HAS_PORT7_R__        /* Definition to show that Module is available */
#ifdef  __MSP430_HAS_PORT8_R__        /* Definition to show that Module is available */
#ifdef  __MSP430_HAS_PORTD_R__        /* Definition to show that Module is available */

#define OFS_PDIN              (0x0000)  /* Port D Input */
#define OFS_PDIN_L             OFS_PDIN
#define OFS_PDIN_H             OFS_PDIN+1
#define OFS_PDOUT             (0x0002)  /* Port D Output */
#define OFS_PDOUT_L            OFS_PDOUT
#define OFS_PDOUT_H            OFS_PDOUT+1
#define OFS_PDDIR             (0x0004)  /* Port D Direction */
#define OFS_PDDIR_L            OFS_PDDIR
#define OFS_PDDIR_H            OFS_PDDIR+1
#define OFS_PDREN             (0x0006)  /* Port D Resistor Enable */
#define OFS_PDREN_L            OFS_PDREN
#define OFS_PDREN_H            OFS_PDREN+1
#define OFS_PDDS              (0x0008)  /* Port D Drive Strenght */
#define OFS_PDDS_L             OFS_PDDS
#define OFS_PDDS_H             OFS_PDDS+1
#define OFS_PDSEL             (0x000A)  /* Port D Selection */
#define OFS_PDSEL_L            OFS_PDSEL
#define OFS_PDSEL_H            OFS_PDSEL+1
#define OFS_PDIES             (0x0018)  /* Port D Interrupt Edge Select */
#define OFS_PDIES_L            OFS_PDIES
#define OFS_PDIES_H            OFS_PDIES+1
#define OFS_PDIE              (0x001A)  /* Port D Interrupt Enable */
#define OFS_PDIE_L             OFS_PDIE
#define OFS_PDIE_H             OFS_PDIE+1
#define OFS_PDIFG             (0x001C)  /* Port D Interrupt Flag */
#define OFS_PDIFG_L            OFS_PDIFG
#define OFS_PDIFG_H            OFS_PDIFG+1





















#define OFS_P7IN              (0x0000)
#define OFS_P7OUT             (0x0002)
#define OFS_P7DIR             (0x0004)
#define OFS_P7REN             (0x0006)
#define OFS_P7DS              (0x0008)
#define OFS_P7SEL             (0x000A)
#define OFS_P7IV              (0x000E)  /* Port 7 Interrupt Vector Word */
#define OFS_P7IES             (0x0018)
#define OFS_P7IE              (0x001A)
#define OFS_P7IFG             (0x001C)
#define OFS_P8IN              (0x0001)
#define OFS_P8OUT             (0x0003)
#define OFS_P8DIR             (0x0005)
#define OFS_P8REN             (0x0007)
#define OFS_P8DS              (0x0009)
#define OFS_P8SEL             (0x000B)
#define OFS_P8IV              (0x001E)  /* Port 8 Interrupt Vector Word */
#define OFS_P8IES             (0x0019)
#define OFS_P8IE              (0x001B)
#define OFS_P8IFG             (0x001d)
#define P7IN                (PDIN_L)  /* Port 7 Input */
#define P7OUT               (PDOUT_L) /* Port 7 Output */
#define P7DIR               (PDDIR_L) /* Port 7 Direction */
#define P7REN               (PDREN_L) /* Port 7 Resistor Enable */
#define P7DS                (PDDS_L)  /* Port 7 Drive Strenght */
#define P7SEL               (PDSEL_L) /* Port 7 Selection */
#define P7IES               (PDIES_L) /* Port 7 Interrupt Edge Select */
#define P7IE                (PDIE_L)  /* Port 7 Interrupt Enable */
#define P7IFG               (PDIFG_L) /* Port 7 Interrupt Flag */

//Definitions for P7IV
#define P7IV_NONE            (0x0000)    /* No Interrupt pending */
#define P7IV_P7IFG0          (0x0002)    /* P7IV P7IFG.0 */
#define P7IV_P7IFG1          (0x0004)    /* P7IV P7IFG.1 */
#define P7IV_P7IFG2          (0x0006)    /* P7IV P7IFG.2 */
#define P7IV_P7IFG3          (0x0008)    /* P7IV P7IFG.3 */
#define P7IV_P7IFG4          (0x000A)    /* P7IV P7IFG.4 */
#define P7IV_P7IFG5          (0x000C)    /* P7IV P7IFG.5 */
#define P7IV_P7IFG6          (0x000E)    /* P7IV P7IFG.6 */
#define P7IV_P7IFG7          (0x0010)    /* P7IV P7IFG.7 */


#define P8IN                (PDIN_H)  /* Port 8 Input */
#define P8OUT               (PDOUT_H) /* Port 8 Output */
#define P8DIR               (PDDIR_H) /* Port 8 Direction */
#define P8REN               (PDREN_H) /* Port 8 Resistor Enable */
#define P8DS                (PDDS_H)  /* Port 8 Drive Strenght */
#define P8SEL               (PDSEL_H) /* Port 8 Selection */
#define P8IES               (PDIES_H) /* Port 8 Interrupt Edge Select */
#define P8IE                (PDIE_H)  /* Port 8 Interrupt Enable */
#define P8IFG               (PDIFG_H) /* Port 8 Interrupt Flag */

//Definitions for P8IV
#define P8IV_NONE            (0x0000)    /* No Interrupt pending */
#define P8IV_P8IFG0          (0x0002)    /* P8IV P8IFG.0 */
#define P8IV_P8IFG1          (0x0004)    /* P8IV P8IFG.1 */
#define P8IV_P8IFG2          (0x0006)    /* P8IV P8IFG.2 */
#define P8IV_P8IFG3          (0x0008)    /* P8IV P8IFG.3 */
#define P8IV_P8IFG4          (0x000A)    /* P8IV P8IFG.4 */
#define P8IV_P8IFG5          (0x000C)    /* P8IV P8IFG.5 */
#define P8IV_P8IFG6          (0x000E)    /* P8IV P8IFG.6 */
#define P8IV_P8IFG7          (0x0010)    /* P8IV P8IFG.7 */



#endif
#endif
#endif
/************************************************************
* DIGITAL I/O Port9/10 Pull up / Pull down Resistors
************************************************************/
#ifdef  __MSP430_HAS_PORT9_R__        /* Definition to show that Module is available */
#ifdef  __MSP430_HAS_PORT10_R__        /* Definition to show that Module is available */
#ifdef  __MSP430_HAS_PORTE_R__        /* Definition to show that Module is available */

#define OFS_PEIN              (0x0000)  /* Port E Input */
#define OFS_PEIN_L             OFS_PEIN
#define OFS_PEIN_H             OFS_PEIN+1
#define OFS_PEOUT             (0x0002)  /* Port E Output */
#define OFS_PEOUT_L            OFS_PEOUT
#define OFS_PEOUT_H            OFS_PEOUT+1
#define OFS_PEDIR             (0x0004)  /* Port E Direction */
#define OFS_PEDIR_L            OFS_PEDIR
#define OFS_PEDIR_H            OFS_PEDIR+1
#define OFS_PEREN             (0x0006)  /* Port E Resistor Enable */
#define OFS_PEREN_L            OFS_PEREN
#define OFS_PEREN_H            OFS_PEREN+1
#define OFS_PEDS              (0x0008)  /* Port E Drive Strenght */
#define OFS_PEDS_L             OFS_PEDS
#define OFS_PEDS_H             OFS_PEDS+1
#define OFS_PESEL             (0x000A)  /* Port E Selection */
#define OFS_PESEL_L            OFS_PESEL
#define OFS_PESEL_H            OFS_PESEL+1
#define OFS_PEIES             (0x0018)  /* Port E Interrupt Edge Select */
#define OFS_PEIES_L            OFS_PEIES
#define OFS_PEIES_H            OFS_PEIES+1
#define OFS_PEIE              (0x001A)  /* Port E Interrupt Enable */
#define OFS_PEIE_L             OFS_PEIE
#define OFS_PEIE_H             OFS_PEIE+1
#define OFS_PEIFG             (0x001C)  /* Port E Interrupt Flag */
#define OFS_PEIFG_L            OFS_PEIFG
#define OFS_PEIFG_H            OFS_PEIFG+1





















#define OFS_P9IN              (0x0000)
#define OFS_P9OUT             (0x0002)
#define OFS_P9DIR             (0x0004)
#define OFS_P9REN             (0x0006)
#define OFS_P9DS              (0x0008)
#define OFS_P9SEL             (0x000A)
#define OFS_P9IV              (0x000E)  /* Port 9 Interrupt Vector Word */
#define OFS_P9IES             (0x0018)
#define OFS_P9IE              (0x001A)
#define OFS_P9IFG             (0x001C)
#define OFS_P10IN             (0x0001)
#define OFS_P10OUT            (0x0003)
#define OFS_P10DIR            (0x0005)
#define OFS_P10REN            (0x0007)
#define OFS_P10DS             (0x0009)
#define OFS_P10SEL            (0x000B)
#define OFS_P10IV             (0x001E)  /* Port 10 Interrupt Vector Word */
#define OFS_P10IES            (0x0019)
#define OFS_P10IE             (0x001B)
#define OFS_P10IFG            (0x001d)
#define P9IN                (PEIN_L)  /* Port 9 Input */
#define P9OUT               (PEOUT_L) /* Port 9 Output */
#define P9DIR               (PEDIR_L) /* Port 9 Direction */
#define P9REN               (PEREN_L) /* Port 9 Resistor Enable */
#define P9DS                (PEDS_L)  /* Port 9 Drive Strenght */
#define P9SEL               (PESEL_L) /* Port 9 Selection */
#define P9IES               (PEIES_L) /* Port 9 Interrupt Edge Select */
#define P9IE                (PEIE_L)  /* Port 9 Interrupt Enable */
#define P9IFG               (PEIFG_L) /* Port 9 Interrupt Flag */

//Definitions for P9IV
#define P9IV_NONE            (0x0000)    /* No Interrupt pending */
#define P9IV_P9IFG0          (0x0002)    /* P9IV P9IFG.0 */
#define P9IV_P9IFG1          (0x0004)    /* P9IV P9IFG.1 */
#define P9IV_P9IFG2          (0x0006)    /* P9IV P9IFG.2 */
#define P9IV_P9IFG3          (0x0008)    /* P9IV P9IFG.3 */
#define P9IV_P9IFG4          (0x000A)    /* P9IV P9IFG.4 */
#define P9IV_P9IFG5          (0x000C)    /* P9IV P9IFG.5 */
#define P9IV_P9IFG6          (0x000E)    /* P9IV P9IFG.6 */
#define P9IV_P9IFG7          (0x0010)    /* P9IV P9IFG.7 */


#define P10IN                (PEIN_H)  /* Port 10 Input */
#define P10OUT               (PEOUT_H) /* Port 10 Output */
#define P10DIR               (PEDIR_H) /* Port 10 Direction */
#define P10REN               (PEREN_H) /* Port 10 Resistor Enable */
#define P10DS                (PEDS_H)  /* Port 10 Drive Strenght */
#define P10SEL               (PESEL_H) /* Port 10 Selection */
#define P10IES               (PEIES_H) /* Port 10 Interrupt Edge Select */
#define P10IE                (PEIE_H)  /* Port 10 Interrupt Enable */
#define P10IFG               (PEIFG_H) /* Port 10 Interrupt Flag */

//Definitions for P10IV
#define P10IV_NONE            (0x0000)    /* No Interrupt pending */
#define P10IV_P10IFG0          (0x0002)    /* P10IV P10IFG.0 */
#define P10IV_P10IFG1          (0x0004)    /* P10IV P10IFG.1 */
#define P10IV_P10IFG2          (0x0006)    /* P10IV P10IFG.2 */
#define P10IV_P10IFG3          (0x0008)    /* P10IV P10IFG.3 */
#define P10IV_P10IFG4          (0x000A)    /* P10IV P10IFG.4 */
#define P10IV_P10IFG5          (0x000C)    /* P10IV P10IFG.5 */
#define P10IV_P10IFG6          (0x000E)    /* P10IV P10IFG.6 */
#define P10IV_P10IFG7          (0x0010)    /* P10IV P10IFG.7 */



#endif
#endif
#endif
/************************************************************
* DIGITAL I/O Port11 Pull up / Pull down Resistors
************************************************************/
#ifdef  __MSP430_HAS_PORT11_R__        /* Definition to show that Module is available */
#ifdef  __MSP430_HAS_PORTF_R__        /* Definition to show that Module is available */

#define OFS_PFIN              (0x0000)  /* Port F Input */
#define OFS_PFIN_L             OFS_PFIN
#define OFS_PFIN_H             OFS_PFIN+1
#define OFS_PFOUT             (0x0002)  /* Port F Output */
#define OFS_PFOUT_L            OFS_PFOUT
#define OFS_PFOUT_H            OFS_PFOUT+1
#define OFS_PFDIR             (0x0004)  /* Port F Direction */
#define OFS_PFDIR_L            OFS_PFDIR
#define OFS_PFDIR_H            OFS_PFDIR+1
#define OFS_PFREN             (0x0006)  /* Port F Resistor Enable */
#define OFS_PFREN_L            OFS_PFREN
#define OFS_PFREN_H            OFS_PFREN+1
#define OFS_PFDS              (0x0008)  /* Port F Drive Strenght */
#define OFS_PFDS_L             OFS_PFDS
#define OFS_PFDS_H             OFS_PFDS+1
#define OFS_PFSEL             (0x000A)  /* Port F Selection */
#define OFS_PFSEL_L            OFS_PFSEL
#define OFS_PFSEL_H            OFS_PFSEL+1
#define OFS_PFIES             (0x0018)  /* Port F Interrupt Edge Select */
#define OFS_PFIES_L            OFS_PFIES
#define OFS_PFIES_H            OFS_PFIES+1
#define OFS_PFIE              (0x001A)  /* Port F Interrupt Enable */
#define OFS_PFIE_L             OFS_PFIE
#define OFS_PFIE_H             OFS_PFIE+1
#define OFS_PFIFG             (0x001C)  /* Port F Interrupt Flag */
#define OFS_PFIFG_L            OFS_PFIFG
#define OFS_PFIFG_H            OFS_PFIFG+1




















#define OFS_P11IN             (0x0000)
#define OFS_P11OUT            (0x0002)
#define OFS_P11DIR            (0x0004)
#define OFS_P11REN            (0x0006)
#define OFS_P11DS             (0x0008)
#define OFS_P11SEL            (0x000A)
#define OFS_P11IV             (0x000E)  /* Port 11 Interrupt Vector Word */
#define OFS_P11IES            (0x0018)
#define OFS_P11IE             (0x001A)
#define OFS_P11IFG            (0x001C)
#define P11IN                (PFIN_L)  /* Port 11 Input */
#define P11OUT               (PFOUT_L) /* Port 11 Output */
#define P11DIR               (PFDIR_L) /* Port 11 Direction */
#define P11REN               (PFREN_L) /* Port 11 Resistor Enable */
#define P11DS                (PFDS_L)  /* Port 11 Drive Strenght */
#define P11SEL               (PFSEL_L) /* Port 11 Selection */

#define P11IES               (PFIES_L) /* Port 11 Interrupt Edge Select */
#define P11IE                (PFIE_L)  /* Port 11 Interrupt Enable */
#define P11IFG               (PFIFG_L) /* Port 11 Interrupt Flag */

//Definitions for P11IV
#define P11IV_NONE            (0x0000)    /* No Interrupt pending */
#define P11IV_P11IFG0          (0x0002)    /* P11IV P11IFG.0 */
#define P11IV_P11IFG1          (0x0004)    /* P11IV P11IFG.1 */
#define P11IV_P11IFG2          (0x0006)    /* P11IV P11IFG.2 */
#define P11IV_P11IFG3          (0x0008)    /* P11IV P11IFG.3 */
#define P11IV_P11IFG4          (0x000A)    /* P11IV P11IFG.4 */
#define P11IV_P11IFG5          (0x000C)    /* P11IV P11IFG.5 */
#define P11IV_P11IFG6          (0x000E)    /* P11IV P11IFG.6 */
#define P11IV_P11IFG7          (0x0010)    /* P11IV P11IFG.7 */




#endif
#endif
/************************************************************
* DIGITAL I/O PortJ Pull up / Pull down Resistors
************************************************************/
#ifdef  __MSP430_HAS_PORTJ_R__        /* Definition to show that Module is available */

#define OFS_PJIN              (0x0000)  /* Port J Input */
#define OFS_PJIN_L             OFS_PJIN
#define OFS_PJIN_H             OFS_PJIN+1
#define OFS_PJOUT             (0x0002)  /* Port J Output */
#define OFS_PJOUT_L            OFS_PJOUT
#define OFS_PJOUT_H            OFS_PJOUT+1
#define OFS_PJDIR             (0x0004)  /* Port J Direction */
#define OFS_PJDIR_L            OFS_PJDIR
#define OFS_PJDIR_H            OFS_PJDIR+1
#define OFS_PJREN             (0x0006)  /* Port J Resistor Enable */
#define OFS_PJREN_L            OFS_PJREN
#define OFS_PJREN_H            OFS_PJREN+1
#define OFS_PJDS              (0x0008)  /* Port J Drive Strenght */
#define OFS_PJDS_L             OFS_PJDS
#define OFS_PJDS_H             OFS_PJDS+1
#define OFS_PJSEL             (0x000A)  /* Port J Selection */
#define OFS_PJSEL_L            OFS_PJSEL
#define OFS_PJSEL_H            OFS_PJSEL+1













#endif
/************************************************************
* PORT MAPPING CONTROLLER
************************************************************/
#ifdef  __MSP430_HAS_PORT_MAPPING__   /* Definition to show that Module is available */

#define OFS_PMAPKEYID         (0x0000)  /* Port Mapping Key register */
#define OFS_PMAPKEYID_L        OFS_PMAPKEYID
#define OFS_PMAPKEYID_H        OFS_PMAPKEYID+1
#define OFS_PMAPCTL           (0x0002)  /* Port Mapping control register */
#define OFS_PMAPCTL_L          OFS_PMAPCTL
#define OFS_PMAPCTL_H          OFS_PMAPCTL+1

#define  PMAPKEY             (0x2D52)  /* Port Mapping Key */
#define  PMAPPWD             PMAPKEYID /* Legacy Definition: Mapping Key register */
#define  PMAPPW              (0x2D52)  /* Legacy Definition: Port Mapping Password */

/* PMAPCTL Control Bits */
#define PMAPLOCKED          (0x0001)  /* Port Mapping Lock bit. Read only */
#define PMAPRECFG           (0x0002)  /* Port Mapping re-configuration control bit */

/* PMAPCTL Control Bits */
#define PMAPLOCKED_L        (0x0001)  /* Port Mapping Lock bit. Read only */
#define PMAPRECFG_L         (0x0002)  /* Port Mapping re-configuration control bit */


#endif
/************************************************************
* PORT 2 MAPPING CONTROLLER
************************************************************/
#ifdef  __MSP430_HAS_PORT2_MAPPING__   /* Definition to show that Module is available */

#define OFS_P2MAP01           (0x0000)  /* Port P2.0/1 mapping register */
#define OFS_P2MAP01_L          OFS_P2MAP01
#define OFS_P2MAP01_H          OFS_P2MAP01+1
#define OFS_P2MAP23           (0x0002)  /* Port P2.2/3 mapping register */
#define OFS_P2MAP23_L          OFS_P2MAP23
#define OFS_P2MAP23_H          OFS_P2MAP23+1
#define OFS_P2MAP45           (0x0004)  /* Port P2.4/5 mapping register */
#define OFS_P2MAP45_L          OFS_P2MAP45
#define OFS_P2MAP45_H          OFS_P2MAP45+1
#define OFS_P2MAP67           (0x0006)  /* Port P2.6/7 mapping register */
#define OFS_P2MAP67_L          OFS_P2MAP67
#define OFS_P2MAP67_H          OFS_P2MAP67+1
#define OFS_P2MAP0            (0x0000)
#define OFS_P2MAP1            (0x0001)
#define OFS_P2MAP2            (0x0002)
#define OFS_P2MAP3            (0x0003)
#define OFS_P2MAP4            (0x0004)
#define OFS_P2MAP5            (0x0005)
#define OFS_P2MAP6            (0x0006)
#define OFS_P2MAP7            (0x0007)

#define  P2MAP0              P2MAP01_L /* Port P2.0 mapping register */
#define  P2MAP1              P2MAP01_H /* Port P2.1 mapping register */
#define  P2MAP2              P2MAP23_L /* Port P2.2 mapping register */
#define  P2MAP3              P2MAP23_H /* Port P2.3 mapping register */
#define  P2MAP4              P2MAP45_L /* Port P2.4 mapping register */
#define  P2MAP5              P2MAP45_H /* Port P2.5 mapping register */
#define  P2MAP6              P2MAP67_L /* Port P2.6 mapping register */
#define  P2MAP7              P2MAP67_H /* Port P2.7 mapping register */











#endif
/************************************************************
* PMM - Power Management System
************************************************************/
#ifdef  __MSP430_HAS_PMM__            /* Definition to show that Module is available */

#define OFS_PMMCTL0           (0x0000)  /* PMM Control 0 */
#define OFS_PMMCTL0_L          OFS_PMMCTL0
#define OFS_PMMCTL0_H          OFS_PMMCTL0+1
#define OFS_PMMCTL1           (0x0002)  /* PMM Control 1 */
#define OFS_PMMCTL1_L          OFS_PMMCTL1
#define OFS_PMMCTL1_H          OFS_PMMCTL1+1
#define OFS_SVSMHCTL          (0x0004)  /* SVS and SVM high side control register */
#define OFS_SVSMHCTL_L         OFS_SVSMHCTL
#define OFS_SVSMHCTL_H         OFS_SVSMHCTL+1
#define OFS_SVSMLCTL          (0x0006)  /* SVS and SVM low side control register */
#define OFS_SVSMLCTL_L         OFS_SVSMLCTL
#define OFS_SVSMLCTL_H         OFS_SVSMLCTL+1
#define OFS_SVSMIO            (0x0008)  /* SVSIN and SVSOUT control register */
#define OFS_SVSMIO_L           OFS_SVSMIO
#define OFS_SVSMIO_H           OFS_SVSMIO+1
#define OFS_PMMIFG            (0x000C)  /* PMM Interrupt Flag */
#define OFS_PMMIFG_L           OFS_PMMIFG
#define OFS_PMMIFG_H           OFS_PMMIFG+1
#define OFS_PMMRIE            (0x000E)  /* PMM and RESET Interrupt Enable */
#define OFS_PMMRIE_L           OFS_PMMRIE
#define OFS_PMMRIE_H           OFS_PMMRIE+1

#define PMMPW               (0xA500)  /* PMM Register Write Password */
#define PMMPW_H             (0xA5)    /* PMM Register Write Password for high word access */

/* PMMCTL0 Control Bits */
#define PMMCOREV0           (0x0001)  /* PMM Core Voltage Bit: 0 */
#define PMMCOREV1           (0x0002)  /* PMM Core Voltage Bit: 1 */
#define PMMSWBOR            (0x0004)  /* PMM Software BOR */
#define PMMSWPOR            (0x0008)  /* PMM Software POR */
#define PMMREGOFF           (0x0010)  /* PMM Turn Regulator off */
#define PMMHPMRE            (0x0080)  /* PMM Global High Power Module Request Enable */

/* PMMCTL0 Control Bits */
#define PMMCOREV0_L         (0x0001)  /* PMM Core Voltage Bit: 0 */
#define PMMCOREV1_L         (0x0002)  /* PMM Core Voltage Bit: 1 */
#define PMMSWBOR_L          (0x0004)  /* PMM Software BOR */
#define PMMSWPOR_L          (0x0008)  /* PMM Software POR */
#define PMMREGOFF_L         (0x0010)  /* PMM Turn Regulator off */
#define PMMHPMRE_L          (0x0080)  /* PMM Global High Power Module Request Enable */


#define PMMCOREV_0          (0x0000)  /* PMM Core Voltage 0 (1.35V) */
#define PMMCOREV_1          (0x0001)  /* PMM Core Voltage 1 (1.55V) */
#define PMMCOREV_2          (0x0002)  /* PMM Core Voltage 2 (1.75V) */
#define PMMCOREV_3          (0x0003)  /* PMM Core Voltage 3 (1.85V) */


/* PMMCTL1 Control Bits */
#define PMMREFMD            (0x0001)  /* PMM Reference Mode */
#define PMMCMD0             (0x0010)  /* PMM Voltage Regulator Current Mode Bit: 0 */
#define PMMCMD1             (0x0020)  /* PMM Voltage Regulator Current Mode Bit: 1 */

/* PMMCTL1 Control Bits */
#define PMMREFMD_L          (0x0001)  /* PMM Reference Mode */
#define PMMCMD0_L           (0x0010)  /* PMM Voltage Regulator Current Mode Bit: 0 */
#define PMMCMD1_L           (0x0020)  /* PMM Voltage Regulator Current Mode Bit: 1 */


/* SVSMHCTL Control Bits */
#define SVSMHRRL0           (0x0001)  /* SVS and SVM high side Reset Release Voltage Level Bit: 0 */
#define SVSMHRRL1           (0x0002)  /* SVS and SVM high side Reset Release Voltage Level Bit: 1 */
#define SVSMHRRL2           (0x0004)  /* SVS and SVM high side Reset Release Voltage Level Bit: 2 */
#define SVSMHDLYST          (0x0008)  /* SVS and SVM high side delay status */
#define SVSHMD              (0x0010)  /* SVS high side mode */
#define SVSMHEVM            (0x0040)  /* SVS and SVM high side event mask */
#define SVSMHACE            (0x0080)  /* SVS and SVM high side auto control enable */
#define SVSHRVL0            (0x0100)  /* SVS high side reset voltage level Bit: 0 */
#define SVSHRVL1            (0x0200)  /* SVS high side reset voltage level Bit: 1 */
#define SVSHE               (0x0400)  /* SVS high side enable */
#define SVSHFP              (0x0800)  /* SVS high side full performace mode */
#define SVMHOVPE            (0x1000)  /* SVM high side over-voltage enable */
#define SVMHE               (0x4000)  /* SVM high side enable */
#define SVMHFP              (0x8000)  /* SVM high side full performace mode */

/* SVSMHCTL Control Bits */
#define SVSMHRRL0_L         (0x0001)  /* SVS and SVM high side Reset Release Voltage Level Bit: 0 */
#define SVSMHRRL1_L         (0x0002)  /* SVS and SVM high side Reset Release Voltage Level Bit: 1 */
#define SVSMHRRL2_L         (0x0004)  /* SVS and SVM high side Reset Release Voltage Level Bit: 2 */
#define SVSMHDLYST_L        (0x0008)  /* SVS and SVM high side delay status */
#define SVSHMD_L            (0x0010)  /* SVS high side mode */
#define SVSMHEVM_L          (0x0040)  /* SVS and SVM high side event mask */
#define SVSMHACE_L          (0x0080)  /* SVS and SVM high side auto control enable */

/* SVSMHCTL Control Bits */
#define SVSHRVL0_H          (0x0001)  /* SVS high side reset voltage level Bit: 0 */
#define SVSHRVL1_H          (0x0002)  /* SVS high side reset voltage level Bit: 1 */
#define SVSHE_H             (0x0004)  /* SVS high side enable */
#define SVSHFP_H            (0x0008)  /* SVS high side full performace mode */
#define SVMHOVPE_H          (0x0010)  /* SVM high side over-voltage enable */
#define SVMHE_H             (0x0040)  /* SVM high side enable */
#define SVMHFP_H            (0x0080)  /* SVM high side full performace mode */

#define SVSMHRRL_0          (0x0000)  /* SVS and SVM high side Reset Release Voltage Level 0 */
#define SVSMHRRL_1          (0x0001)  /* SVS and SVM high side Reset Release Voltage Level 1 */
#define SVSMHRRL_2          (0x0002)  /* SVS and SVM high side Reset Release Voltage Level 2 */
#define SVSMHRRL_3          (0x0003)  /* SVS and SVM high side Reset Release Voltage Level 3 */
#define SVSMHRRL_4          (0x0004)  /* SVS and SVM high side Reset Release Voltage Level 4 */
#define SVSMHRRL_5          (0x0005)  /* SVS and SVM high side Reset Release Voltage Level 5 */
#define SVSMHRRL_6          (0x0006)  /* SVS and SVM high side Reset Release Voltage Level 6 */
#define SVSMHRRL_7          (0x0007)  /* SVS and SVM high side Reset Release Voltage Level 7 */

#define SVSHRVL_0           (0x0000)  /* SVS high side Reset Release Voltage Level 0 */
#define SVSHRVL_1           (0x0100)  /* SVS high side Reset Release Voltage Level 1 */
#define SVSHRVL_2           (0x0200)  /* SVS high side Reset Release Voltage Level 2 */
#define SVSHRVL_3           (0x0300)  /* SVS high side Reset Release Voltage Level 3 */


/* SVSMLCTL Control Bits */
#define SVSMLRRL0           (0x0001)  /* SVS and SVM low side Reset Release Voltage Level Bit: 0 */
#define SVSMLRRL1           (0x0002)  /* SVS and SVM low side Reset Release Voltage Level Bit: 1 */
#define SVSMLRRL2           (0x0004)  /* SVS and SVM low side Reset Release Voltage Level Bit: 2 */
#define SVSMLDLYST          (0x0008)  /* SVS and SVM low side delay status */
#define SVSLMD              (0x0010)  /* SVS low side mode */
#define SVSMLEVM            (0x0040)  /* SVS and SVM low side event mask */
#define SVSMLACE            (0x0080)  /* SVS and SVM low side auto control enable */
#define SVSLRVL0            (0x0100)  /* SVS low side reset voltage level Bit: 0 */
#define SVSLRVL1            (0x0200)  /* SVS low side reset voltage level Bit: 1 */
#define SVSLE               (0x0400)  /* SVS low side enable */
#define SVSLFP              (0x0800)  /* SVS low side full performace mode */
#define SVMLOVPE            (0x1000)  /* SVM low side over-voltage enable */
#define SVMLE               (0x4000)  /* SVM low side enable */
#define SVMLFP              (0x8000)  /* SVM low side full performace mode */

/* SVSMLCTL Control Bits */
#define SVSMLRRL0_L         (0x0001)  /* SVS and SVM low side Reset Release Voltage Level Bit: 0 */
#define SVSMLRRL1_L         (0x0002)  /* SVS and SVM low side Reset Release Voltage Level Bit: 1 */
#define SVSMLRRL2_L         (0x0004)  /* SVS and SVM low side Reset Release Voltage Level Bit: 2 */
#define SVSMLDLYST_L        (0x0008)  /* SVS and SVM low side delay status */
#define SVSLMD_L            (0x0010)  /* SVS low side mode */
#define SVSMLEVM_L          (0x0040)  /* SVS and SVM low side event mask */
#define SVSMLACE_L          (0x0080)  /* SVS and SVM low side auto control enable */

/* SVSMLCTL Control Bits */
#define SVSLRVL0_H          (0x0001)  /* SVS low side reset voltage level Bit: 0 */
#define SVSLRVL1_H          (0x0002)  /* SVS low side reset voltage level Bit: 1 */
#define SVSLE_H             (0x0004)  /* SVS low side enable */
#define SVSLFP_H            (0x0008)  /* SVS low side full performace mode */
#define SVMLOVPE_H          (0x0010)  /* SVM low side over-voltage enable */
#define SVMLE_H             (0x0040)  /* SVM low side enable */
#define SVMLFP_H            (0x0080)  /* SVM low side full performace mode */

#define SVSMLRRL_0          (0x0000)  /* SVS and SVM low side Reset Release Voltage Level 0 */
#define SVSMLRRL_1          (0x0001)  /* SVS and SVM low side Reset Release Voltage Level 1 */
#define SVSMLRRL_2          (0x0002)  /* SVS and SVM low side Reset Release Voltage Level 2 */
#define SVSMLRRL_3          (0x0003)  /* SVS and SVM low side Reset Release Voltage Level 3 */
#define SVSMLRRL_4          (0x0004)  /* SVS and SVM low side Reset Release Voltage Level 4 */
#define SVSMLRRL_5          (0x0005)  /* SVS and SVM low side Reset Release Voltage Level 5 */
#define SVSMLRRL_6          (0x0006)  /* SVS and SVM low side Reset Release Voltage Level 6 */
#define SVSMLRRL_7          (0x0007)  /* SVS and SVM low side Reset Release Voltage Level 7 */

#define SVSLRVL_0           (0x0000)  /* SVS low side Reset Release Voltage Level 0 */
#define SVSLRVL_1           (0x0100)  /* SVS low side Reset Release Voltage Level 1 */
#define SVSLRVL_2           (0x0200)  /* SVS low side Reset Release Voltage Level 2 */
#define SVSLRVL_3           (0x0300)  /* SVS low side Reset Release Voltage Level 3 */


/* SVSMIO Control Bits */
#define SVMLOE              (0x0008)  /* SVM low side output enable */
#define SVMLVLROE           (0x0010)  /* SVM low side voltage level reached output enable */
#define SVMOUTPOL           (0x0020)  /* SVMOUT pin polarity */
#define SVMHOE              (0x0800)  /* SVM high side output enable */
#define SVMHVLROE           (0x1000)  /* SVM high side voltage level reached output enable */

/* SVSMIO Control Bits */
#define SVMLOE_L            (0x0008)  /* SVM low side output enable */
#define SVMLVLROE_L         (0x0010)  /* SVM low side voltage level reached output enable */
#define SVMOUTPOL_L         (0x0020)  /* SVMOUT pin polarity */

/* SVSMIO Control Bits */
#define SVMHOE_H            (0x0008)  /* SVM high side output enable */
#define SVMHVLROE_H         (0x0010)  /* SVM high side voltage level reached output enable */


/* PMMIFG Control Bits */
#define SVSMLDLYIFG         (0x0001)  /* SVS and SVM low side Delay expired interrupt flag */
#define SVMLIFG             (0x0002)  /* SVM low side interrupt flag */
#define SVMLVLRIFG          (0x0004)  /* SVM low side Voltage Level Reached interrupt flag */
#define SVSMHDLYIFG         (0x0010)  /* SVS and SVM high side Delay expired interrupt flag */
#define SVMHIFG             (0x0020)  /* SVM high side interrupt flag */
#define SVMHVLRIFG          (0x0040)  /* SVM high side Voltage Level Reached interrupt flag */
#define PMMBORIFG           (0x0100)  /* PMM Software BOR interrupt flag */
#define PMMRSTIFG           (0x0200)  /* PMM RESET pin interrupt flag */
#define PMMPORIFG           (0x0400)  /* PMM Software POR interrupt flag */
#define SVSHIFG             (0x1000)  /* SVS low side interrupt flag */
#define SVSLIFG             (0x2000)  /* SVS high side interrupt flag */
#define PMMLPM5IFG          (0x8000)  /* LPM5 indication Flag */

/* PMMIFG Control Bits */
#define SVSMLDLYIFG_L       (0x0001)  /* SVS and SVM low side Delay expired interrupt flag */
#define SVMLIFG_L           (0x0002)  /* SVM low side interrupt flag */
#define SVMLVLRIFG_L        (0x0004)  /* SVM low side Voltage Level Reached interrupt flag */
#define SVSMHDLYIFG_L       (0x0010)  /* SVS and SVM high side Delay expired interrupt flag */
#define SVMHIFG_L           (0x0020)  /* SVM high side interrupt flag */
#define SVMHVLRIFG_L        (0x0040)  /* SVM high side Voltage Level Reached interrupt flag */

/* PMMIFG Control Bits */
#define PMMBORIFG_H         (0x0001)  /* PMM Software BOR interrupt flag */
#define PMMRSTIFG_H         (0x0002)  /* PMM RESET pin interrupt flag */
#define PMMPORIFG_H         (0x0004)  /* PMM Software POR interrupt flag */
#define SVSHIFG_H           (0x0010)  /* SVS low side interrupt flag */
#define SVSLIFG_H           (0x0020)  /* SVS high side interrupt flag */
#define PMMLPM5IFG_H        (0x0080)  /* LPM5 indication Flag */

#define PMMRSTLPM5IFG       PMMLPM5IFG /* LPM5 indication Flag */


/* PMMIE and RESET Control Bits */
#define SVSMLDLYIE          (0x0001)  /* SVS and SVM low side Delay expired interrupt enable */
#define SVMLIE              (0x0002)  /* SVM low side interrupt enable */
#define SVMLVLRIE           (0x0004)  /* SVM low side Voltage Level Reached interrupt enable */
#define SVSMHDLYIE          (0x0010)  /* SVS and SVM high side Delay expired interrupt enable */
#define SVMHIE              (0x0020)  /* SVM high side interrupt enable */
#define SVMHVLRIE           (0x0040)  /* SVM high side Voltage Level Reached interrupt enable */
#define SVSLPE              (0x0100)  /* SVS low side POR enable */
#define SVMLVLRPE           (0x0200)  /* SVM low side Voltage Level reached POR enable */
#define SVSHPE              (0x1000)  /* SVS high side POR enable */
#define SVMHVLRPE           (0x2000)  /* SVM high side Voltage Level reached POR enable */

/* PMMIE and RESET Control Bits */
#define SVSMLDLYIE_L        (0x0001)  /* SVS and SVM low side Delay expired interrupt enable */
#define SVMLIE_L            (0x0002)  /* SVM low side interrupt enable */
#define SVMLVLRIE_L         (0x0004)  /* SVM low side Voltage Level Reached interrupt enable */
#define SVSMHDLYIE_L        (0x0010)  /* SVS and SVM high side Delay expired interrupt enable */
#define SVMHIE_L            (0x0020)  /* SVM high side interrupt enable */
#define SVMHVLRIE_L         (0x0040)  /* SVM high side Voltage Level Reached interrupt enable */

/* PMMIE and RESET Control Bits */
#define SVSLPE_H            (0x0001)  /* SVS low side POR enable */
#define SVMLVLRPE_H         (0x0002)  /* SVM low side Voltage Level reached POR enable */
#define SVSHPE_H            (0x0010)  /* SVS high side POR enable */
#define SVMHVLRPE_H         (0x0020)  /* SVM high side Voltage Level reached POR enable */


#endif
/************************************************************
* Port U
************************************************************/
#ifdef  __MSP430_HAS_PU__             /* Definition to show that Module is available */

/* ========================================================================= */
/* Port U and LDO Control Registers */
/* ========================================================================= */
#define OFS_LDOKEYPID         (0x0000)       /* LDO Controller peripheral ID and key register */
#define OFS_LDOKEYPID_L        OFS_LDOKEYPID
#define OFS_LDOKEYPID_H        OFS_LDOKEYPID+1
#define OFS_PUCTL             (0x0004)       /* PU Control register */
#define OFS_PUCTL_L            OFS_PUCTL
#define OFS_PUCTL_H            OFS_PUCTL+1
#define OFS_LDOPWRCTL         (0x0008)       /* LDO Power control register */
#define OFS_LDOPWRCTL_L        OFS_LDOPWRCTL
#define OFS_LDOPWRCTL_H        OFS_LDOPWRCTL+1

#define LDOKEY         (0x9628)       /* LDO Control Register key */
#define LDOKEYID       LDOKEYPID      /* Legacy Definiton */

/* PUCTL Control Bits */
#define PUOUT0              (0x0001)  /* PU - PU Output Signal Bit 0 */
#define PUOUT1              (0x0002)  /* PU - PU Output Signal Bit 1 */
#define PUIN0               (0x0004)  /* PU - PU0/DP Input Data */
#define PUIN1               (0x0008)  /* PU - PU1/DM Input Data */
#define PUOPE               (0x0020)  /* PU - Port Output Enable */
#define PUIPE               (0x0100)  /* PU - PHY Single Ended Input enable */

/* PUCTL Control Bits */
#define PUOUT0_L            (0x0001)  /* PU - PU Output Signal Bit 0 */
#define PUOUT1_L            (0x0002)  /* PU - PU Output Signal Bit 1 */
#define PUIN0_L             (0x0004)  /* PU - PU0/DP Input Data */
#define PUIN1_L             (0x0008)  /* PU - PU1/DM Input Data */
#define PUOPE_L             (0x0020)  /* PU - Port Output Enable */

/* PUCTL Control Bits */
#define PUIPE_H             (0x0001)  /* PU - PHY Single Ended Input enable */

#define PUDIR               (0x0020)  /* Legacy Definiton */
#define PSEIEN              (0x0100)  /* Legacy Definiton */

/* LDOPWRCTL Control Bits */
#define LDOOVLIFG           (0x0001)  /* PU - LDOO Overload Interrupt Flag */
#define LDOONIFG            (0x0002)  /* PU - LDOI "Coming ON" Interrupt Flag */
#define LDOOFFIFG           (0x0004)  /* PU - LDOI "Going OFF" Interrupt Flag */
#define LDOBGVBV            (0x0008)  /* PU - LDO Bandgap and LDOI valid */
#define OVLAOFF             (0x0020)  /* PU - LDO overload auto off enable */
#define LDOOVLIE            (0x0100)  /* PU - Overload indication Interrupt Enable */
#define LDOONIE             (0x0200)  /* PU - LDOI "Coming ON" Interrupt Enable */
#define LDOOFFIE            (0x0400)  /* PU - LDOI "Going OFF" Interrupt Enable */
#define LDOEN               (0x0800)  /* PU - LDO Enable (3.3V) */

/* LDOPWRCTL Control Bits */
#define LDOOVLIFG_L         (0x0001)  /* PU - LDOO Overload Interrupt Flag */
#define LDOONIFG_L          (0x0002)  /* PU - LDOI "Coming ON" Interrupt Flag */
#define LDOOFFIFG_L         (0x0004)  /* PU - LDOI "Going OFF" Interrupt Flag */
#define LDOBGVBV_L          (0x0008)  /* PU - LDO Bandgap and LDOI valid */
#define OVLAOFF_L           (0x0020)  /* PU - LDO overload auto off enable */

/* LDOPWRCTL Control Bits */
#define LDOOVLIE_H          (0x0001)  /* PU - Overload indication Interrupt Enable */
#define LDOONIE_H           (0x0002)  /* PU - LDOI "Coming ON" Interrupt Enable */
#define LDOOFFIE_H          (0x0004)  /* PU - LDOI "Going OFF" Interrupt Enable */
#define LDOEN_H             (0x0008)  /* PU - LDO Enable (3.3V) */
#define LDOOEN               LDOEN    /* Deprecated support for LDO Enable (3.3V) */
#define LDOOEN_H             LDOEN_H  /* Deprecated support for LDO Enable (3.3V) */

#define VUOVLIFG            (0x0001)  /* PU - Legacy Definiton: LDOO Overload Interrupt Flag */
#define VBONIFG             (0x0002)  /* PU - Legacy Definiton: LDOI "Coming ON" Interrupt Flag */
#define VBOFFIFG            (0x0004)  /* PU - Legacy Definiton: LDOI "Going OFF" Interrupt Flag */
#define VUOVLIE             (0x0100)  /* PU - Legacy Definiton: Overload indication Interrupt Enable */
#define VBONIE              (0x0200)  /* PU - Legacy Definiton: LDOI "Coming ON" Interrupt Enable */
#define VBOFFIE             (0x0400)  /* PU - Legacy Definiton: LDOI "Going OFF" Interrupt Enable */


#endif
/*************************************************************
* RAM Control Module
*************************************************************/
#ifdef  __MSP430_HAS_RC__             /* Definition to show that Module is available */

#define OFS_RCCTL0            (0x0000)  /* Ram Controller Control Register */
#define OFS_RCCTL0_L           OFS_RCCTL0
#define OFS_RCCTL0_H           OFS_RCCTL0+1

/* RCCTL0 Control Bits */
#define RCRS0OFF            (0x0001)  /* RAM Controller RAM Sector 0 Off */
#define RCRS1OFF            (0x0002)  /* RAM Controller RAM Sector 1 Off */
#define RCRS2OFF            (0x0004)  /* RAM Controller RAM Sector 2 Off */
#define RCRS3OFF            (0x0008)  /* RAM Controller RAM Sector 3 Off */
#define RCRS4OFF            (0x0010)  /* RAM Controller RAM Sector 4 Off */
#define RCRS5OFF            (0x0020)  /* RAM Controller RAM Sector 5 Off */
#define RCRS6OFF            (0x0040)  /* RAM Controller RAM Sector 6 Off */
#define RCRS7OFF            (0x0080)  /* RAM Controller RAM Sector 7 (USB) Off */

/* RCCTL0 Control Bits */
#define RCRS0OFF_L          (0x0001)  /* RAM Controller RAM Sector 0 Off */
#define RCRS1OFF_L          (0x0002)  /* RAM Controller RAM Sector 1 Off */
#define RCRS2OFF_L          (0x0004)  /* RAM Controller RAM Sector 2 Off */
#define RCRS3OFF_L          (0x0008)  /* RAM Controller RAM Sector 3 Off */
#define RCRS4OFF_L          (0x0010)  /* RAM Controller RAM Sector 4 Off */
#define RCRS5OFF_L          (0x0020)  /* RAM Controller RAM Sector 5 Off */
#define RCRS6OFF_L          (0x0040)  /* RAM Controller RAM Sector 6 Off */
#define RCRS7OFF_L          (0x0080)  /* RAM Controller RAM Sector 7 (USB) Off */


#define RCKEY               (0x5A00)

#endif
/************************************************************
* Shared Reference
************************************************************/
#ifdef  __MSP430_HAS_REF__          /* Definition to show that Module is available */

#define OFS_REFCTL0           (0x0000)  /* REF Shared Reference control register 0 */
#define OFS_REFCTL0_L          OFS_REFCTL0
#define OFS_REFCTL0_H          OFS_REFCTL0+1

/* REFCTL0 Control Bits */
#define REFON               (0x0001)  /* REF Reference On */
#define REFOUT              (0x0002)  /* REF Reference output Buffer On */
//#define RESERVED            (0x0004)  /* Reserved */
#define REFTCOFF            (0x0008)  /* REF Temp.Sensor off */
#define REFVSEL0            (0x0010)  /* REF Reference Voltage Level Select Bit:0 */
#define REFVSEL1            (0x0020)  /* REF Reference Voltage Level Select Bit:1 */
//#define RESERVED            (0x0040)  /* Reserved */
#define REFMSTR             (0x0080)  /* REF Master Control */
#define REFGENACT           (0x0100)  /* REF Reference generator active */
#define REFBGACT            (0x0200)  /* REF Reference bandgap active */
#define REFGENBUSY          (0x0400)  /* REF Reference generator busy */
#define BGMODE              (0x0800)  /* REF Bandgap mode */
//#define RESERVED            (0x1000)  /* Reserved */
//#define RESERVED            (0x2000)  /* Reserved */
//#define RESERVED            (0x4000)  /* Reserved */
//#define RESERVED            (0x8000)  /* Reserved */

/* REFCTL0 Control Bits */
#define REFON_L             (0x0001)  /* REF Reference On */
#define REFOUT_L            (0x0002)  /* REF Reference output Buffer On */
//#define RESERVED            (0x0004)  /* Reserved */
#define REFTCOFF_L          (0x0008)  /* REF Temp.Sensor off */
#define REFVSEL0_L          (0x0010)  /* REF Reference Voltage Level Select Bit:0 */
#define REFVSEL1_L          (0x0020)  /* REF Reference Voltage Level Select Bit:1 */
//#define RESERVED            (0x0040)  /* Reserved */
#define REFMSTR_L           (0x0080)  /* REF Master Control */
//#define RESERVED            (0x1000)  /* Reserved */
//#define RESERVED            (0x2000)  /* Reserved */
//#define RESERVED            (0x4000)  /* Reserved */
//#define RESERVED            (0x8000)  /* Reserved */

/* REFCTL0 Control Bits */
//#define RESERVED            (0x0004)  /* Reserved */
//#define RESERVED            (0x0040)  /* Reserved */
#define REFGENACT_H         (0x0001)  /* REF Reference generator active */
#define REFBGACT_H          (0x0002)  /* REF Reference bandgap active */
#define REFGENBUSY_H        (0x0004)  /* REF Reference generator busy */
#define BGMODE_H            (0x0008)  /* REF Bandgap mode */
//#define RESERVED            (0x1000)  /* Reserved */
//#define RESERVED            (0x2000)  /* Reserved */
//#define RESERVED            (0x4000)  /* Reserved */
//#define RESERVED            (0x8000)  /* Reserved */

#define REFVSEL_0           (0x0000)  /* REF Reference Voltage Level Select 1.5V */
#define REFVSEL_1           (0x0010)  /* REF Reference Voltage Level Select 2.0V */
#define REFVSEL_2           (0x0020)  /* REF Reference Voltage Level Select 2.5V */
#define REFVSEL_3           (0x0030)  /* REF Reference Voltage Level Select 2.5V */

#endif
/************************************************************
* Shared Reference
************************************************************/
#ifdef  __MSP430_HAS_REF__          /* Definition to show that Module is available */

#define OFS_REFCTL0           (0x0000)  /* REF Shared Reference control register 0 */
#define OFS_REFCTL0_L          OFS_REFCTL0
#define OFS_REFCTL0_H          OFS_REFCTL0+1

/* REFCTL0 Control Bits */
#define REFON               (0x0001)  /* REF Reference On */
//#define RESERVED            (0x0002)  /* Reserved */
//#define RESERVED            (0x0004)  /* Reserved */
#define REFTCOFF            (0x0008)  /* REF Temp.Sensor off */
#define REFVSEL0            (0x0010)  /* REF Reference Voltage Level Select Bit:0 */
#define REFVSEL1            (0x0020)  /* REF Reference Voltage Level Select Bit:1 */
//#define RESERVED            (0x0040)  /* Reserved */
//#define RESERVED            (0x0080)  /* Reserved */
#define REFGENACT           (0x0100)  /* REF Reference generator active */
#define REFBGACT            (0x0200)  /* REF Reference bandgap active */
#define REFGENBUSY          (0x0400)  /* REF Reference generator busy */
#define BGMODE              (0x0800)  /* REF Bandgap mode */
//#define RESERVED            (0x1000)  /* Reserved */
//#define RESERVED            (0x2000)  /* Reserved */
//#define RESERVED            (0x4000)  /* Reserved */
//#define RESERVED            (0x8000)  /* Reserved */

/* REFCTL0 Control Bits */
#define REFON_L             (0x0001)  /* REF Reference On */
//#define RESERVED            (0x0002)  /* Reserved */
//#define RESERVED            (0x0004)  /* Reserved */
#define REFTCOFF_L          (0x0008)  /* REF Temp.Sensor off */
#define REFVSEL0_L          (0x0010)  /* REF Reference Voltage Level Select Bit:0 */
#define REFVSEL1_L          (0x0020)  /* REF Reference Voltage Level Select Bit:1 */
//#define RESERVED            (0x0040)  /* Reserved */
//#define RESERVED            (0x0080)  /* Reserved */
//#define RESERVED            (0x1000)  /* Reserved */
//#define RESERVED            (0x2000)  /* Reserved */
//#define RESERVED            (0x4000)  /* Reserved */
//#define RESERVED            (0x8000)  /* Reserved */

/* REFCTL0 Control Bits */
//#define RESERVED            (0x0002)  /* Reserved */
//#define RESERVED            (0x0004)  /* Reserved */
//#define RESERVED            (0x0040)  /* Reserved */
//#define RESERVED            (0x0080)  /* Reserved */
#define REFGENACT_H         (0x0001)  /* REF Reference generator active */
#define REFBGACT_H          (0x0002)  /* REF Reference bandgap active */
#define REFGENBUSY_H        (0x0004)  /* REF Reference generator busy */
#define BGMODE_H            (0x0008)  /* REF Bandgap mode */
//#define RESERVED            (0x1000)  /* Reserved */
//#define RESERVED            (0x2000)  /* Reserved */
//#define RESERVED            (0x4000)  /* Reserved */
//#define RESERVED            (0x8000)  /* Reserved */

#define REFVSEL_0           (0x0000)  /* REF Reference Voltage Level Select 1.5V */
#define REFVSEL_1           (0x0010)  /* REF Reference Voltage Level Select 2.0V */
#define REFVSEL_2           (0x0020)  /* REF Reference Voltage Level Select 2.5V */
#define REFVSEL_3           (0x0030)  /* REF Reference Voltage Level Select 2.5V */

#endif
/************************************************************
* Real Time Clock
************************************************************/
#ifdef  __MSP430_HAS_RTC__            /* Definition to show that Module is available */

#define OFS_RTCCTL01          (0x0000)  /* Real Timer Control 0/1 */
#define OFS_RTCCTL01_L         OFS_RTCCTL01
#define OFS_RTCCTL01_H         OFS_RTCCTL01+1
#define OFS_RTCCTL23          (0x0002)  /* Real Timer Control 2/3 */
#define OFS_RTCCTL23_L         OFS_RTCCTL23
#define OFS_RTCCTL23_H         OFS_RTCCTL23+1
#define OFS_RTCPS0CTL         (0x0008)  /* Real Timer Prescale Timer 0 Control */
#define OFS_RTCPS0CTL_L        OFS_RTCPS0CTL
#define OFS_RTCPS0CTL_H        OFS_RTCPS0CTL+1
#define OFS_RTCPS1CTL         (0x000A)  /* Real Timer Prescale Timer 1 Control */
#define OFS_RTCPS1CTL_L        OFS_RTCPS1CTL
#define OFS_RTCPS1CTL_H        OFS_RTCPS1CTL+1
#define OFS_RTCPS             (0x000C)  /* Real Timer Prescale Timer Control */
#define OFS_RTCPS_L            OFS_RTCPS
#define OFS_RTCPS_H            OFS_RTCPS+1
#define OFS_RTCIV             (0x000E)  /* Real Time Clock Interrupt Vector */
#define OFS_RTCTIM0           (0x0010)  /* Real Time Clock Time 0 */
#define OFS_RTCTIM0_L          OFS_RTCTIM0
#define OFS_RTCTIM0_H          OFS_RTCTIM0+1
#define OFS_RTCTIM1           (0x0012)  /* Real Time Clock Time 1 */
#define OFS_RTCTIM1_L          OFS_RTCTIM1
#define OFS_RTCTIM1_H          OFS_RTCTIM1+1
#define OFS_RTCDATE           (0x0014)  /* Real Time Clock Date */
#define OFS_RTCDATE_L          OFS_RTCDATE
#define OFS_RTCDATE_H          OFS_RTCDATE+1
#define OFS_RTCYEAR           (0x0016)  /* Real Time Clock Year */
#define OFS_RTCYEAR_L          OFS_RTCYEAR
#define OFS_RTCYEAR_H          OFS_RTCYEAR+1
#define OFS_RTCAMINHR         (0x0018)  /* Real Time Clock Alarm Min/Hour */
#define OFS_RTCAMINHR_L        OFS_RTCAMINHR
#define OFS_RTCAMINHR_H        OFS_RTCAMINHR+1
#define OFS_RTCADOWDAY        (0x001A)  /* Real Time Clock Alarm day of week/day */
#define OFS_RTCADOWDAY_L       OFS_RTCADOWDAY
#define OFS_RTCADOWDAY_H       OFS_RTCADOWDAY+1
#define OFS_RTCSEC            (0x0010)
#define OFS_RTCMIN            (0x0011)
#define OFS_RTCHOUR           (0x0012)
#define OFS_RTCDOW            (0x0013)
#define OFS_RTCDAY            (0x0014)
#define OFS_RTCMON            (0x0015)
#define OFS_RTCAMIN           (0x0018)
#define OFS_RTCAHOUR          (0x0019)
#define OFS_RTCADOW           (0x001A)
#define OFS_RTCADAY           (0x001B)

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
#define RTCMODE             (0x2000)     /* RTC Mode 0:Counter / 1: Calendar */
#define RTCRDY              (0x1000)     /* RTC Ready */
#define RTCSSEL1            (0x0800)     /* RTC Source Select 1 */
#define RTCSSEL0            (0x0400)     /* RTC Source Select 0 */
#define RTCTEV1             (0x0200)     /* RTC Time Event 1 */
#define RTCTEV0             (0x0100)     /* RTC Time Event 0 */
//#define Reserved          (0x0080)
#define RTCTEVIE            (0x0040)     /* RTC Time Event Interrupt Enable Flag */
#define RTCAIE              (0x0020)     /* RTC Alarm Interrupt Enable Flag */
#define RTCRDYIE            (0x0010)     /* RTC Ready Interrupt Enable Flag */
//#define Reserved          (0x0008)
#define RTCTEVIFG           (0x0004)     /* RTC Time Event Interrupt Flag */
#define RTCAIFG             (0x0002)     /* RTC Alarm Interrupt Flag */
#define RTCRDYIFG           (0x0001)     /* RTC Ready Interrupt Flag */

/* RTCCTL01 Control Bits */
//#define Reserved          (0x0080)
#define RTCTEVIE_L          (0x0040)     /* RTC Time Event Interrupt Enable Flag */
#define RTCAIE_L            (0x0020)     /* RTC Alarm Interrupt Enable Flag */
#define RTCRDYIE_L          (0x0010)     /* RTC Ready Interrupt Enable Flag */
//#define Reserved          (0x0008)
#define RTCTEVIFG_L         (0x0004)     /* RTC Time Event Interrupt Flag */
#define RTCAIFG_L           (0x0002)     /* RTC Alarm Interrupt Flag */
#define RTCRDYIFG_L         (0x0001)     /* RTC Ready Interrupt Flag */

/* RTCCTL01 Control Bits */
#define RTCBCD_H            (0x0080)     /* RTC BCD  0:Binary / 1:BCD */
#define RTCHOLD_H           (0x0040)     /* RTC Hold */
#define RTCMODE_H           (0x0020)     /* RTC Mode 0:Counter / 1: Calendar */
#define RTCRDY_H            (0x0010)     /* RTC Ready */
#define RTCSSEL1_H          (0x0008)     /* RTC Source Select 1 */
#define RTCSSEL0_H          (0x0004)     /* RTC Source Select 0 */
#define RTCTEV1_H           (0x0002)     /* RTC Time Event 1 */
#define RTCTEV0_H           (0x0001)     /* RTC Time Event 0 */
//#define Reserved          (0x0080)
//#define Reserved          (0x0008)

#define RTCSSEL_0           (0x0000)     /* RTC Source Select ACLK */
#define RTCSSEL_1           (0x0400)     /* RTC Source Select SMCLK */
#define RTCSSEL_2           (0x0800)     /* RTC Source Select RT1PS */
#define RTCSSEL_3           (0x0C00)     /* RTC Source Select RT1PS */
#define RTCSSEL__ACLK       (0x0000)     /* RTC Source Select ACLK */
#define RTCSSEL__SMCLK      (0x0400)     /* RTC Source Select SMCLK */
#define RTCSSEL__RT1PS      (0x0800)     /* RTC Source Select RT1PS */
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
//#define Reserved          (0x8000)
#define RT0SSEL             (0x4000)     /* RTC Prescale Timer 0 Source Select 0:ACLK / 1:SMCLK */
#define RT0PSDIV2           (0x2000)     /* RTC Prescale Timer 0 Clock Divide Bit: 2 */
#define RT0PSDIV1           (0x1000)     /* RTC Prescale Timer 0 Clock Divide Bit: 1 */
#define RT0PSDIV0           (0x0800)     /* RTC Prescale Timer 0 Clock Divide Bit: 0 */
//#define Reserved          (0x0400)
//#define Reserved          (0x0200)
#define RT0PSHOLD           (0x0100)     /* RTC Prescale Timer 0 Hold */
//#define Reserved          (0x0080)
//#define Reserved          (0x0040)
//#define Reserved          (0x0020)
#define RT0IP2              (0x0010)     /* RTC Prescale Timer 0 Interrupt Interval Bit: 2 */
#define RT0IP1              (0x0008)     /* RTC Prescale Timer 0 Interrupt Interval Bit: 1 */
#define RT0IP0              (0x0004)     /* RTC Prescale Timer 0 Interrupt Interval Bit: 0 */
#define RT0PSIE             (0x0002)     /* RTC Prescale Timer 0 Interrupt Enable Flag */
#define RT0PSIFG            (0x0001)     /* RTC Prescale Timer 0 Interrupt Flag */

/* RTCPS0CTL Control Bits */
//#define Reserved          (0x8000)
//#define Reserved          (0x0400)
//#define Reserved          (0x0200)
//#define Reserved          (0x0080)
//#define Reserved          (0x0040)
//#define Reserved          (0x0020)
#define RT0IP2_L            (0x0010)     /* RTC Prescale Timer 0 Interrupt Interval Bit: 2 */
#define RT0IP1_L            (0x0008)     /* RTC Prescale Timer 0 Interrupt Interval Bit: 1 */
#define RT0IP0_L            (0x0004)     /* RTC Prescale Timer 0 Interrupt Interval Bit: 0 */
#define RT0PSIE_L           (0x0002)     /* RTC Prescale Timer 0 Interrupt Enable Flag */
#define RT0PSIFG_L          (0x0001)     /* RTC Prescale Timer 0 Interrupt Flag */

/* RTCPS0CTL Control Bits */
//#define Reserved          (0x8000)
#define RT0SSEL_H           (0x0040)     /* RTC Prescale Timer 0 Source Select 0:ACLK / 1:SMCLK */
#define RT0PSDIV2_H         (0x0020)     /* RTC Prescale Timer 0 Clock Divide Bit: 2 */
#define RT0PSDIV1_H         (0x0010)     /* RTC Prescale Timer 0 Clock Divide Bit: 1 */
#define RT0PSDIV0_H         (0x0008)     /* RTC Prescale Timer 0 Clock Divide Bit: 0 */
//#define Reserved          (0x0400)
//#define Reserved          (0x0200)
#define RT0PSHOLD_H         (0x0001)     /* RTC Prescale Timer 0 Hold */
//#define Reserved          (0x0080)
//#define Reserved          (0x0040)
//#define Reserved          (0x0020)

#define RT0IP_0             (0x0000)     /* RTC Prescale Timer 0 Interrupt Interval /2 */
#define RT0IP_1             (0x0004)     /* RTC Prescale Timer 0 Interrupt Interval /4 */
#define RT0IP_2             (0x0008)     /* RTC Prescale Timer 0 Interrupt Interval /8 */
#define RT0IP_3             (0x000C)     /* RTC Prescale Timer 0 Interrupt Interval /16 */
#define RT0IP_4             (0x0010)     /* RTC Prescale Timer 0 Interrupt Interval /32 */
#define RT0IP_5             (0x0014)     /* RTC Prescale Timer 0 Interrupt Interval /64 */
#define RT0IP_6             (0x0018)     /* RTC Prescale Timer 0 Interrupt Interval /128 */
#define RT0IP_7             (0x001C)     /* RTC Prescale Timer 0 Interrupt Interval /256 */

#define RT0PSDIV_0          (0x0000)     /* RTC Prescale Timer 0 Clock Divide /2 */
#define RT0PSDIV_1          (0x0800)     /* RTC Prescale Timer 0 Clock Divide /4 */
#define RT0PSDIV_2          (0x1000)     /* RTC Prescale Timer 0 Clock Divide /8 */
#define RT0PSDIV_3          (0x1800)     /* RTC Prescale Timer 0 Clock Divide /16 */
#define RT0PSDIV_4          (0x2000)     /* RTC Prescale Timer 0 Clock Divide /32 */
#define RT0PSDIV_5          (0x2800)     /* RTC Prescale Timer 0 Clock Divide /64 */
#define RT0PSDIV_6          (0x3000)     /* RTC Prescale Timer 0 Clock Divide /128 */
#define RT0PSDIV_7          (0x3800)     /* RTC Prescale Timer 0 Clock Divide /256 */


/* RTCPS1CTL Control Bits */
#define RT1SSEL1            (0x8000)     /* RTC Prescale Timer 1 Source Select Bit 1 */
#define RT1SSEL0            (0x4000)     /* RTC Prescale Timer 1 Source Select Bit 0 */
#define RT1PSDIV2           (0x2000)     /* RTC Prescale Timer 1 Clock Divide Bit: 2 */
#define RT1PSDIV1           (0x1000)     /* RTC Prescale Timer 1 Clock Divide Bit: 1 */
#define RT1PSDIV0           (0x0800)     /* RTC Prescale Timer 1 Clock Divide Bit: 0 */
//#define Reserved          (0x0400)
//#define Reserved          (0x0200)
#define RT1PSHOLD           (0x0100)     /* RTC Prescale Timer 1 Hold */
//#define Reserved          (0x0080)
//#define Reserved          (0x0040)
//#define Reserved          (0x0020)
#define RT1IP2              (0x0010)     /* RTC Prescale Timer 1 Interrupt Interval Bit: 2 */
#define RT1IP1              (0x0008)     /* RTC Prescale Timer 1 Interrupt Interval Bit: 1 */
#define RT1IP0              (0x0004)     /* RTC Prescale Timer 1 Interrupt Interval Bit: 0 */
#define RT1PSIE             (0x0002)     /* RTC Prescale Timer 1 Interrupt Enable Flag */
#define RT1PSIFG            (0x0001)     /* RTC Prescale Timer 1 Interrupt Flag */

/* RTCPS1CTL Control Bits */
//#define Reserved          (0x0400)
//#define Reserved          (0x0200)
//#define Reserved          (0x0080)
//#define Reserved          (0x0040)
//#define Reserved          (0x0020)
#define RT1IP2_L            (0x0010)     /* RTC Prescale Timer 1 Interrupt Interval Bit: 2 */
#define RT1IP1_L            (0x0008)     /* RTC Prescale Timer 1 Interrupt Interval Bit: 1 */
#define RT1IP0_L            (0x0004)     /* RTC Prescale Timer 1 Interrupt Interval Bit: 0 */
#define RT1PSIE_L           (0x0002)     /* RTC Prescale Timer 1 Interrupt Enable Flag */
#define RT1PSIFG_L          (0x0001)     /* RTC Prescale Timer 1 Interrupt Flag */

/* RTCPS1CTL Control Bits */
#define RT1SSEL1_H          (0x0080)     /* RTC Prescale Timer 1 Source Select Bit 1 */
#define RT1SSEL0_H          (0x0040)     /* RTC Prescale Timer 1 Source Select Bit 0 */
#define RT1PSDIV2_H         (0x0020)     /* RTC Prescale Timer 1 Clock Divide Bit: 2 */
#define RT1PSDIV1_H         (0x0010)     /* RTC Prescale Timer 1 Clock Divide Bit: 1 */
#define RT1PSDIV0_H         (0x0008)     /* RTC Prescale Timer 1 Clock Divide Bit: 0 */
//#define Reserved          (0x0400)
//#define Reserved          (0x0200)
#define RT1PSHOLD_H         (0x0001)     /* RTC Prescale Timer 1 Hold */
//#define Reserved          (0x0080)
//#define Reserved          (0x0040)
//#define Reserved          (0x0020)

#define RT1IP_0             (0x0000)     /* RTC Prescale Timer 1 Interrupt Interval /2 */
#define RT1IP_1             (0x0004)     /* RTC Prescale Timer 1 Interrupt Interval /4 */
#define RT1IP_2             (0x0008)     /* RTC Prescale Timer 1 Interrupt Interval /8 */
#define RT1IP_3             (0x000C)     /* RTC Prescale Timer 1 Interrupt Interval /16 */
#define RT1IP_4             (0x0010)     /* RTC Prescale Timer 1 Interrupt Interval /32 */
#define RT1IP_5             (0x0014)     /* RTC Prescale Timer 1 Interrupt Interval /64 */
#define RT1IP_6             (0x0018)     /* RTC Prescale Timer 1 Interrupt Interval /128 */
#define RT1IP_7             (0x001C)     /* RTC Prescale Timer 1 Interrupt Interval /256 */

#define RT1PSDIV_0          (0x0000)     /* RTC Prescale Timer 1 Clock Divide /2 */
#define RT1PSDIV_1          (0x0800)     /* RTC Prescale Timer 1 Clock Divide /4 */
#define RT1PSDIV_2          (0x1000)     /* RTC Prescale Timer 1 Clock Divide /8 */
#define RT1PSDIV_3          (0x1800)     /* RTC Prescale Timer 1 Clock Divide /16 */
#define RT1PSDIV_4          (0x2000)     /* RTC Prescale Timer 1 Clock Divide /32 */
#define RT1PSDIV_5          (0x2800)     /* RTC Prescale Timer 1 Clock Divide /64 */
#define RT1PSDIV_6          (0x3000)     /* RTC Prescale Timer 1 Clock Divide /128 */
#define RT1PSDIV_7          (0x3800)     /* RTC Prescale Timer 1 Clock Divide /256 */

#define RT1SSEL_0           (0x0000)     /* RTC Prescale Timer Source Select ACLK */
#define RT1SSEL_1           (0x4000)     /* RTC Prescale Timer Source Select SMCLK */
#define RT1SSEL_2           (0x8000)     /* RTC Prescale Timer Source Select RT0PS */
#define RT1SSEL_3           (0xC000)     /* RTC Prescale Timer Source Select RT0PS */

/* RTC Definitions */
#define RTCIV_NONE          (0x0000)     /* No Interrupt pending */
#define RTCIV_RTCRDYIFG     (0x0002)     /* RTC ready: RTCRDYIFG */
#define RTCIV_RTCTEVIFG     (0x0004)     /* RTC interval timer: RTCTEVIFG */
#define RTCIV_RTCAIFG       (0x0006)     /* RTC user alarm: RTCAIFG */
#define RTCIV_RT0PSIFG      (0x0008)     /* RTC prescaler 0: RT0PSIFG */
#define RTCIV_RT1PSIFG      (0x000A)     /* RTC prescaler 1: RT1PSIFG */

/* Legacy Definitions */
#define RTC_NONE            (0x0000)     /* No Interrupt pending */
#define RTC_RTCRDYIFG       (0x0002)     /* RTC ready: RTCRDYIFG */
#define RTC_RTCTEVIFG       (0x0004)     /* RTC interval timer: RTCTEVIFG */
#define RTC_RTCAIFG         (0x0006)     /* RTC user alarm: RTCAIFG */
#define RTC_RT0PSIFG        (0x0008)     /* RTC prescaler 0: RT0PSIFG */
#define RTC_RT1PSIFG        (0x000A)     /* RTC prescaler 1: RT1PSIFG */

#endif
/************************************************************
* Real Time Clock
************************************************************/
#ifdef  __MSP430_HAS_RTC_B__          /* Definition to show that Module is available */

#define OFS_RTCCTL01          (0x0000)  /* Real Timer Control 0/1 */
#define OFS_RTCCTL01_L         OFS_RTCCTL01
#define OFS_RTCCTL01_H         OFS_RTCCTL01+1
#define OFS_RTCCTL23          (0x0002)  /* Real Timer Control 2/3 */
#define OFS_RTCCTL23_L         OFS_RTCCTL23
#define OFS_RTCCTL23_H         OFS_RTCCTL23+1
#define OFS_RTCPS0CTL         (0x0008)  /* Real Timer Prescale Timer 0 Control */
#define OFS_RTCPS0CTL_L        OFS_RTCPS0CTL
#define OFS_RTCPS0CTL_H        OFS_RTCPS0CTL+1
#define OFS_RTCPS1CTL         (0x000A)  /* Real Timer Prescale Timer 1 Control */
#define OFS_RTCPS1CTL_L        OFS_RTCPS1CTL
#define OFS_RTCPS1CTL_H        OFS_RTCPS1CTL+1
#define OFS_RTCPS             (0x000C)  /* Real Timer Prescale Timer Control */
#define OFS_RTCPS_L            OFS_RTCPS
#define OFS_RTCPS_H            OFS_RTCPS+1
#define OFS_RTCIV             (0x000E)  /* Real Time Clock Interrupt Vector */
#define OFS_RTCTIM0           (0x0010)  /* Real Time Clock Time 0 */
#define OFS_RTCTIM0_L          OFS_RTCTIM0
#define OFS_RTCTIM0_H          OFS_RTCTIM0+1
#define OFS_RTCTIM1           (0x0012)  /* Real Time Clock Time 1 */
#define OFS_RTCTIM1_L          OFS_RTCTIM1
#define OFS_RTCTIM1_H          OFS_RTCTIM1+1
#define OFS_RTCDATE           (0x0014)  /* Real Time Clock Date */
#define OFS_RTCDATE_L          OFS_RTCDATE
#define OFS_RTCDATE_H          OFS_RTCDATE+1
#define OFS_RTCYEAR           (0x0016)  /* Real Time Clock Year */
#define OFS_RTCYEAR_L          OFS_RTCYEAR
#define OFS_RTCYEAR_H          OFS_RTCYEAR+1
#define OFS_RTCAMINHR         (0x0018)  /* Real Time Clock Alarm Min/Hour */
#define OFS_RTCAMINHR_L        OFS_RTCAMINHR
#define OFS_RTCAMINHR_H        OFS_RTCAMINHR+1
#define OFS_RTCADOWDAY        (0x001A)  /* Real Time Clock Alarm day of week/day */
#define OFS_RTCADOWDAY_L       OFS_RTCADOWDAY
#define OFS_RTCADOWDAY_H       OFS_RTCADOWDAY+1
#define OFS_BIN2BCD           (0x001C)  /* Real Time Binary-to-BCD conversion register */
#define OFS_BCD2BIN           (0x001E)  /* Real Time BCD-to-binary conversion register */
#define OFS_RTCSEC            (0x0010)
#define OFS_RTCMIN            (0x0011)
#define OFS_RTCHOUR           (0x0012)
#define OFS_RTCDOW            (0x0013)
#define OFS_RTCDAY            (0x0014)
#define OFS_RTCMON            (0x0015)
#define OFS_RTCAMIN           (0x0018)
#define OFS_RTCAHOUR          (0x0019)
#define OFS_RTCADOW           (0x001A)
#define OFS_RTCADAY           (0x001B)

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

#endif
/************************************************************
* Real Time Clock
************************************************************/
#ifdef  __MSP430_HAS_RTC_C__          /* Definition to show that Module is available */

#define OFS_RTCCTL0           (0x0000)  /* Real Timer Clock Control 0/Key */
#define OFS_RTCCTL0_L          OFS_RTCCTL0
#define OFS_RTCCTL0_H          OFS_RTCCTL0+1
#define OFS_RTCCTL13          (0x0002)  /* Real Timer Clock Control 1/3 */
#define OFS_RTCCTL13_L         OFS_RTCCTL13
#define OFS_RTCCTL13_H         OFS_RTCCTL13+1
#define RTCCTL1             RTCCTL13_L
#define RTCCTL3             RTCCTL13_H
#define OFS_RTCOCAL           (0x0004)  /* Real Timer Clock Offset Calibartion */
#define OFS_RTCOCAL_L          OFS_RTCOCAL
#define OFS_RTCOCAL_H          OFS_RTCOCAL+1
#define OFS_RTCTCMP           (0x0006)  /* Real Timer Temperature Compensation */
#define OFS_RTCTCMP_L          OFS_RTCTCMP
#define OFS_RTCTCMP_H          OFS_RTCTCMP+1
#define OFS_RTCPS0CTL         (0x0008)  /* Real Timer Prescale Timer 0 Control */
#define OFS_RTCPS0CTL_L        OFS_RTCPS0CTL
#define OFS_RTCPS0CTL_H        OFS_RTCPS0CTL+1
#define OFS_RTCPS1CTL         (0x000A)  /* Real Timer Prescale Timer 1 Control */
#define OFS_RTCPS1CTL_L        OFS_RTCPS1CTL
#define OFS_RTCPS1CTL_H        OFS_RTCPS1CTL+1
#define OFS_RTCPS             (0x000C)  /* Real Timer Prescale Timer Control */
#define OFS_RTCPS_L            OFS_RTCPS
#define OFS_RTCPS_H            OFS_RTCPS+1
#define OFS_RTCIV             (0x000E)  /* Real Time Clock Interrupt Vector */
#define OFS_RTCTIM0           (0x0010)  /* Real Time Clock Time 0 */
#define OFS_RTCTIM0_L          OFS_RTCTIM0
#define OFS_RTCTIM0_H          OFS_RTCTIM0+1
#define OFS_RTCTIM1           (0x0012)  /* Real Time Clock Time 1 */
#define OFS_RTCTIM1_L          OFS_RTCTIM1
#define OFS_RTCTIM1_H          OFS_RTCTIM1+1
#define OFS_RTCDATE           (0x0014)  /* Real Time Clock Date */
#define OFS_RTCDATE_L          OFS_RTCDATE
#define OFS_RTCDATE_H          OFS_RTCDATE+1
#define OFS_RTCYEAR           (0x0016)  /* Real Time Clock Year */
#define OFS_RTCYEAR_L          OFS_RTCYEAR
#define OFS_RTCYEAR_H          OFS_RTCYEAR+1
#define OFS_RTCAMINHR         (0x0018)  /* Real Time Clock Alarm Min/Hour */
#define OFS_RTCAMINHR_L        OFS_RTCAMINHR
#define OFS_RTCAMINHR_H        OFS_RTCAMINHR+1
#define OFS_RTCADOWDAY        (0x001A)  /* Real Time Clock Alarm day of week/day */
#define OFS_RTCADOWDAY_L       OFS_RTCADOWDAY
#define OFS_RTCADOWDAY_H       OFS_RTCADOWDAY+1
#define OFS_BIN2BCD           (0x001C)  /* Real Time Binary-to-BCD conversion register */
#define OFS_BCD2BIN           (0x001E)  /* Real Time BCD-to-binary conversion register */
#define OFS_RTCSEC            (0x0010)
#define OFS_RTCMIN            (0x0011)
#define OFS_RTCHOUR           (0x0012)
#define OFS_RTCDOW            (0x0013)
#define OFS_RTCDAY            (0x0014)
#define OFS_RTCMON            (0x0015)
#define OFS_RTCAMIN           (0x0018)
#define OFS_RTCAHOUR          (0x0019)
#define OFS_RTCADOW           (0x001A)
#define OFS_RTCADAY           (0x001B)

#define RTCSEC              RTCTIM0_L
#define RTCMIN              RTCTIM0_H
#define RTCHOUR             RTCTIM1_L
#define RTCDOW              RTCTIM1_H
#define RTCDAY              RTCDATE_L
#define RTCMON              RTCDATE_H
#define RTCYEARL            RTCYEAR_L
#define RT0PS               RTCPS_L
#define RT1PS               RTCPS_H
#define RTCAMIN             RTCAMINHR_L    /* Real Time Clock Alarm Min */
#define RTCAHOUR            RTCAMINHR_H    /* Real Time Clock Alarm Hour */
#define RTCADOW             RTCADOWDAY_L   /* Real Time Clock Alarm day of week */
#define RTCADAY             RTCADOWDAY_H   /* Real Time Clock Alarm day */

/* RTCCTL0 Control Bits */
#define RTCOFIE             (0x0080)   /* RTC 32kHz cyrstal oscillator fault interrupt enable */
#define RTCTEVIE            (0x0040)   /* RTC Time Event Interrupt Enable Flag */
#define RTCAIE              (0x0020)   /* RTC Alarm Interrupt Enable Flag */
#define RTCRDYIE            (0x0010)   /* RTC Ready Interrupt Enable Flag */
#define RTCOFIFG            (0x0008)   /* RTC 32kHz cyrstal oscillator fault interrupt flag */
#define RTCTEVIFG           (0x0004)   /* RTC Time Event Interrupt Flag */
#define RTCAIFG             (0x0002)   /* RTC Alarm Interrupt Flag */
#define RTCRDYIFG           (0x0001)   /* RTC Ready Interrupt Flag */

/* RTCCTL0 Control Bits */
#define RTCOFIE_L           (0x0080)   /* RTC 32kHz cyrstal oscillator fault interrupt enable */
#define RTCTEVIE_L          (0x0040)   /* RTC Time Event Interrupt Enable Flag */
#define RTCAIE_L            (0x0020)   /* RTC Alarm Interrupt Enable Flag */
#define RTCRDYIE_L          (0x0010)   /* RTC Ready Interrupt Enable Flag */
#define RTCOFIFG_L          (0x0008)   /* RTC 32kHz cyrstal oscillator fault interrupt flag */
#define RTCTEVIFG_L         (0x0004)   /* RTC Time Event Interrupt Flag */
#define RTCAIFG_L           (0x0002)   /* RTC Alarm Interrupt Flag */
#define RTCRDYIFG_L         (0x0001)   /* RTC Ready Interrupt Flag */


#define RTCKEY              (0xA500)   /* RTC Key for RTC write access */
#define RTCKEY_H            (0xA5)     /* RTC Key for RTC write access (high word) */


/* RTCCTL13 Control Bits */
#define RTCCALF1            (0x0200)   /* RTC Calibration Frequency Bit 1 */
#define RTCCALF0            (0x0100)   /* RTC Calibration Frequency Bit 0 */
#define RTCBCD              (0x0080)   /* RTC BCD  0:Binary / 1:BCD */
#define RTCHOLD             (0x0040)   /* RTC Hold */
#define RTCMODE             (0x0020)   /* RTC Mode 0:Counter / 1: Calendar */
#define RTCRDY              (0x0010)   /* RTC Ready */
#define RTCSSEL1            (0x0008)   /* RTC Source Select 1 */
#define RTCSSEL0            (0x0004)   /* RTC Source Select 0 */
#define RTCTEV1             (0x0002)   /* RTC Time Event 1 */
#define RTCTEV0             (0x0001)   /* RTC Time Event 0 */

/* RTCCTL13 Control Bits */
#define RTCBCD_L            (0x0080)   /* RTC BCD  0:Binary / 1:BCD */
#define RTCHOLD_L           (0x0040)   /* RTC Hold */
#define RTCMODE_L           (0x0020)   /* RTC Mode 0:Counter / 1: Calendar */
#define RTCRDY_L            (0x0010)   /* RTC Ready */
#define RTCSSEL1_L          (0x0008)   /* RTC Source Select 1 */
#define RTCSSEL0_L          (0x0004)   /* RTC Source Select 0 */
#define RTCTEV1_L           (0x0002)   /* RTC Time Event 1 */
#define RTCTEV0_L           (0x0001)   /* RTC Time Event 0 */

/* RTCCTL13 Control Bits */
#define RTCCALF1_H          (0x0002)   /* RTC Calibration Frequency Bit 1 */
#define RTCCALF0_H          (0x0001)   /* RTC Calibration Frequency Bit 0 */

#define RTCSSEL_0           (0x0000)   /* RTC Source Select ACLK */
#define RTCSSEL_1           (0x0004)   /* RTC Source Select SMCLK */
#define RTCSSEL_2           (0x0008)   /* RTC Source Select RT1PS */
#define RTCSSEL_3           (0x000C)   /* RTC Source Select RT1PS */
#define RTCSSEL__ACLK       (0x0000)   /* RTC Source Select ACLK */
#define RTCSSEL__SMCLK      (0x0004)   /* RTC Source Select SMCLK */
#define RTCSSEL__RT1PS      (0x0008)   /* RTC Source Select RT1PS */

#define RTCTEV_0            (0x0000)   /* RTC Time Event: 0 (Min. changed) */
#define RTCTEV_1            (0x0001)   /* RTC Time Event: 1 (Hour changed) */
#define RTCTEV_2            (0x0002)   /* RTC Time Event: 2 (12:00 changed) */
#define RTCTEV_3            (0x0003)   /* RTC Time Event: 3 (00:00 changed) */
#define RTCTEV__MIN         (0x0000)   /* RTC Time Event: 0 (Min. changed) */
#define RTCTEV__HOUR        (0x0001)   /* RTC Time Event: 1 (Hour changed) */
#define RTCTEV__0000        (0x0002)   /* RTC Time Event: 2 (00:00 changed) */
#define RTCTEV__1200        (0x0003)   /* RTC Time Event: 3 (12:00 changed) */

#define RTCCALF_0           (0x0000)   /* RTC Calibration Frequency: No Output */
#define RTCCALF_1           (0x0100)   /* RTC Calibration Frequency: 512 Hz */
#define RTCCALF_2           (0x0200)   /* RTC Calibration Frequency: 256 Hz */
#define RTCCALF_3           (0x0300)   /* RTC Calibration Frequency: 1 Hz */


/* RTCOCAL Control Bits */
#define RTCOCALS            (0x8000)   /* RTC Offset Calibration Sign */
#define RTCOCAL7            (0x0080)   /* RTC Offset Calibration Bit 7 */
#define RTCOCAL6            (0x0040)   /* RTC Offset Calibration Bit 6 */
#define RTCOCAL5            (0x0020)   /* RTC Offset Calibration Bit 5 */
#define RTCOCAL4            (0x0010)   /* RTC Offset Calibration Bit 4 */
#define RTCOCAL3            (0x0008)   /* RTC Offset Calibration Bit 3 */
#define RTCOCAL2            (0x0004)   /* RTC Offset Calibration Bit 2 */
#define RTCOCAL1            (0x0002)   /* RTC Offset Calibration Bit 1 */
#define RTCOCAL0            (0x0001)   /* RTC Offset Calibration Bit 0 */

/* RTCOCAL Control Bits */
#define RTCOCAL7_L          (0x0080)   /* RTC Offset Calibration Bit 7 */
#define RTCOCAL6_L          (0x0040)   /* RTC Offset Calibration Bit 6 */
#define RTCOCAL5_L          (0x0020)   /* RTC Offset Calibration Bit 5 */
#define RTCOCAL4_L          (0x0010)   /* RTC Offset Calibration Bit 4 */
#define RTCOCAL3_L          (0x0008)   /* RTC Offset Calibration Bit 3 */
#define RTCOCAL2_L          (0x0004)   /* RTC Offset Calibration Bit 2 */
#define RTCOCAL1_L          (0x0002)   /* RTC Offset Calibration Bit 1 */
#define RTCOCAL0_L          (0x0001)   /* RTC Offset Calibration Bit 0 */

/* RTCOCAL Control Bits */
#define RTCOCALS_H          (0x0080)   /* RTC Offset Calibration Sign */

/* RTCTCMP Control Bits */
#define RTCTCMPS            (0x8000)   /* RTC Temperature Compensation Sign */
#define RTCTCRDY            (0x4000)   /* RTC Temperature compensation ready */
#define RTCTCOK             (0x2000)   /* RTC Temperature compensation write OK */
#define RTCTCMP7            (0x0080)   /* RTC Temperature Compensation Bit 7 */
#define RTCTCMP6            (0x0040)   /* RTC Temperature Compensation Bit 6 */
#define RTCTCMP5            (0x0020)   /* RTC Temperature Compensation Bit 5 */
#define RTCTCMP4            (0x0010)   /* RTC Temperature Compensation Bit 4 */
#define RTCTCMP3            (0x0008)   /* RTC Temperature Compensation Bit 3 */
#define RTCTCMP2            (0x0004)   /* RTC Temperature Compensation Bit 2 */
#define RTCTCMP1            (0x0002)   /* RTC Temperature Compensation Bit 1 */
#define RTCTCMP0            (0x0001)   /* RTC Temperature Compensation Bit 0 */

/* RTCTCMP Control Bits */
#define RTCTCMP7_L          (0x0080)   /* RTC Temperature Compensation Bit 7 */
#define RTCTCMP6_L          (0x0040)   /* RTC Temperature Compensation Bit 6 */
#define RTCTCMP5_L          (0x0020)   /* RTC Temperature Compensation Bit 5 */
#define RTCTCMP4_L          (0x0010)   /* RTC Temperature Compensation Bit 4 */
#define RTCTCMP3_L          (0x0008)   /* RTC Temperature Compensation Bit 3 */
#define RTCTCMP2_L          (0x0004)   /* RTC Temperature Compensation Bit 2 */
#define RTCTCMP1_L          (0x0002)   /* RTC Temperature Compensation Bit 1 */
#define RTCTCMP0_L          (0x0001)   /* RTC Temperature Compensation Bit 0 */

/* RTCTCMP Control Bits */
#define RTCTCMPS_H          (0x0080)   /* RTC Temperature Compensation Sign */
#define RTCTCRDY_H          (0x0040)   /* RTC Temperature compensation ready */
#define RTCTCOK_H           (0x0020)   /* RTC Temperature compensation write OK */


#define RTCAE               (0x80)     /* Real Time Clock Alarm enable */




/* RTCPS0CTL Control Bits */
//#define Reserved          (0x8000)
//#define Reserved          (0x4000)
#define RT0PSDIV2           (0x2000)   /* RTC Prescale Timer 0 Clock Divide Bit: 2 */
#define RT0PSDIV1           (0x1000)   /* RTC Prescale Timer 0 Clock Divide Bit: 1 */
#define RT0PSDIV0           (0x0800)   /* RTC Prescale Timer 0 Clock Divide Bit: 0 */
//#define Reserved          (0x0400)
//#define Reserved          (0x0200)
#define RT0PSHOLD           (0x0100)   /* RTC Prescale Timer 0 Hold */
//#define Reserved          (0x0080)
//#define Reserved          (0x0040)
//#define Reserved          (0x0020)
#define RT0IP2              (0x0010)   /* RTC Prescale Timer 0 Interrupt Interval Bit: 2 */
#define RT0IP1              (0x0008)   /* RTC Prescale Timer 0 Interrupt Interval Bit: 1 */
#define RT0IP0              (0x0004)   /* RTC Prescale Timer 0 Interrupt Interval Bit: 0 */
#define RT0PSIE             (0x0002)   /* RTC Prescale Timer 0 Interrupt Enable Flag */
#define RT0PSIFG            (0x0001)   /* RTC Prescale Timer 0 Interrupt Flag */

/* RTCPS0CTL Control Bits */
//#define Reserved          (0x8000)
//#define Reserved          (0x4000)
//#define Reserved          (0x0400)
//#define Reserved          (0x0200)
//#define Reserved          (0x0080)
//#define Reserved          (0x0040)
//#define Reserved          (0x0020)
#define RT0IP2_L            (0x0010)   /* RTC Prescale Timer 0 Interrupt Interval Bit: 2 */
#define RT0IP1_L            (0x0008)   /* RTC Prescale Timer 0 Interrupt Interval Bit: 1 */
#define RT0IP0_L            (0x0004)   /* RTC Prescale Timer 0 Interrupt Interval Bit: 0 */
#define RT0PSIE_L           (0x0002)   /* RTC Prescale Timer 0 Interrupt Enable Flag */
#define RT0PSIFG_L          (0x0001)   /* RTC Prescale Timer 0 Interrupt Flag */

/* RTCPS0CTL Control Bits */
//#define Reserved          (0x8000)
//#define Reserved          (0x4000)
#define RT0PSDIV2_H         (0x0020)   /* RTC Prescale Timer 0 Clock Divide Bit: 2 */
#define RT0PSDIV1_H         (0x0010)   /* RTC Prescale Timer 0 Clock Divide Bit: 1 */
#define RT0PSDIV0_H         (0x0008)   /* RTC Prescale Timer 0 Clock Divide Bit: 0 */
//#define Reserved          (0x0400)
//#define Reserved          (0x0200)
#define RT0PSHOLD_H         (0x0001)   /* RTC Prescale Timer 0 Hold */
//#define Reserved          (0x0080)
//#define Reserved          (0x0040)
//#define Reserved          (0x0020)

#define RT0IP_0             (0x0000)   /* RTC Prescale Timer 0 Interrupt Interval /2 */
#define RT0IP_1             (0x0004)   /* RTC Prescale Timer 0 Interrupt Interval /4 */
#define RT0IP_2             (0x0008)   /* RTC Prescale Timer 0 Interrupt Interval /8 */
#define RT0IP_3             (0x000C)   /* RTC Prescale Timer 0 Interrupt Interval /16 */
#define RT0IP_4             (0x0010)   /* RTC Prescale Timer 0 Interrupt Interval /32 */
#define RT0IP_5             (0x0014)   /* RTC Prescale Timer 0 Interrupt Interval /64 */
#define RT0IP_6             (0x0018)   /* RTC Prescale Timer 0 Interrupt Interval /128 */
#define RT0IP_7             (0x001C)   /* RTC Prescale Timer 0 Interrupt Interval /256 */


/* RTCPS1CTL Control Bits */
#define RT1SSEL1            (0x8000)   /* RTC Prescale Timer 1 Source Select Bit 1 */
#define RT1SSEL0            (0x4000)   /* RTC Prescale Timer 1 Source Select Bit 0 */
#define RT1PSDIV2           (0x2000)   /* RTC Prescale Timer 1 Clock Divide Bit: 2 */
#define RT1PSDIV1           (0x1000)   /* RTC Prescale Timer 1 Clock Divide Bit: 1 */
#define RT1PSDIV0           (0x0800)   /* RTC Prescale Timer 1 Clock Divide Bit: 0 */
//#define Reserved          (0x0400)
//#define Reserved          (0x0200)
#define RT1PSHOLD           (0x0100)   /* RTC Prescale Timer 1 Hold */
//#define Reserved          (0x0080)
//#define Reserved          (0x0040)
//#define Reserved          (0x0020)
#define RT1IP2              (0x0010)   /* RTC Prescale Timer 1 Interrupt Interval Bit: 2 */
#define RT1IP1              (0x0008)   /* RTC Prescale Timer 1 Interrupt Interval Bit: 1 */
#define RT1IP0              (0x0004)   /* RTC Prescale Timer 1 Interrupt Interval Bit: 0 */
#define RT1PSIE             (0x0002)   /* RTC Prescale Timer 1 Interrupt Enable Flag */
#define RT1PSIFG            (0x0001)   /* RTC Prescale Timer 1 Interrupt Flag */

/* RTCPS1CTL Control Bits */
//#define Reserved          (0x0400)
//#define Reserved          (0x0200)
//#define Reserved          (0x0080)
//#define Reserved          (0x0040)
//#define Reserved          (0x0020)
#define RT1IP2_L            (0x0010)   /* RTC Prescale Timer 1 Interrupt Interval Bit: 2 */
#define RT1IP1_L            (0x0008)   /* RTC Prescale Timer 1 Interrupt Interval Bit: 1 */
#define RT1IP0_L            (0x0004)   /* RTC Prescale Timer 1 Interrupt Interval Bit: 0 */
#define RT1PSIE_L           (0x0002)   /* RTC Prescale Timer 1 Interrupt Enable Flag */
#define RT1PSIFG_L          (0x0001)   /* RTC Prescale Timer 1 Interrupt Flag */

/* RTCPS1CTL Control Bits */
#define RT1SSEL1_H          (0x0080)   /* RTC Prescale Timer 1 Source Select Bit 1 */
#define RT1SSEL0_H          (0x0040)   /* RTC Prescale Timer 1 Source Select Bit 0 */
#define RT1PSDIV2_H         (0x0020)   /* RTC Prescale Timer 1 Clock Divide Bit: 2 */
#define RT1PSDIV1_H         (0x0010)   /* RTC Prescale Timer 1 Clock Divide Bit: 1 */
#define RT1PSDIV0_H         (0x0008)   /* RTC Prescale Timer 1 Clock Divide Bit: 0 */
//#define Reserved          (0x0400)
//#define Reserved          (0x0200)
#define RT1PSHOLD_H         (0x0001)   /* RTC Prescale Timer 1 Hold */
//#define Reserved          (0x0080)
//#define Reserved          (0x0040)
//#define Reserved          (0x0020)

#define RT1IP_0             (0x0000)   /* RTC Prescale Timer 1 Interrupt Interval /2 */
#define RT1IP_1             (0x0004)   /* RTC Prescale Timer 1 Interrupt Interval /4 */
#define RT1IP_2             (0x0008)   /* RTC Prescale Timer 1 Interrupt Interval /8 */
#define RT1IP_3             (0x000C)   /* RTC Prescale Timer 1 Interrupt Interval /16 */
#define RT1IP_4             (0x0010)   /* RTC Prescale Timer 1 Interrupt Interval /32 */
#define RT1IP_5             (0x0014)   /* RTC Prescale Timer 1 Interrupt Interval /64 */
#define RT1IP_6             (0x0018)   /* RTC Prescale Timer 1 Interrupt Interval /128 */
#define RT1IP_7             (0x001C)   /* RTC Prescale Timer 1 Interrupt Interval /256 */


/* RTC Definitions */
#define RTCIV_NONE         (0x0000)    /* No Interrupt pending */
#define RTCIV_RTCOFIFG     (0x0002)    /* RTC Osc fault: RTCOFIFG */
#define RTCIV_RTCRDYIFG    (0x0004)    /* RTC ready: RTCRDYIFG */
#define RTCIV_RTCTEVIFG    (0x0006)    /* RTC interval timer: RTCTEVIFG */
#define RTCIV_RTCAIFG      (0x0008)    /* RTC user alarm: RTCAIFG */
#define RTCIV_RT0PSIFG     (0x000A)    /* RTC prescaler 0: RT0PSIFG */
#define RTCIV_RT1PSIFG     (0x000C)    /* RTC prescaler 1: RT1PSIFG */

/* Legacy Definitions */
#define RTC_NONE           (0x0000)    /* No Interrupt pending */
#define RTC_RTCOFIFG       (0x0002)    /* RTC Osc fault: RTCOFIFG */
#define RTC_RTCRDYIFG      (0x0004)    /* RTC ready: RTCRDYIFG */
#define RTC_RTCTEVIFG      (0x0006)    /* RTC interval timer: RTCTEVIFG */
#define RTC_RTCAIFG        (0x0008)    /* RTC user alarm: RTCAIFG */
#define RTC_RT0PSIFG       (0x000A)    /* RTC prescaler 0: RT0PSIFG */
#define RTC_RT1PSIFG       (0x000C)    /* RTC prescaler 1: RT1PSIFG */

#endif
/************************************************************
* Real Time Clock
************************************************************/
#ifdef  __MSP430_HAS_RTC_CE__         /* Definition to show that Module is available */

#define OFS_RTCCTL0           (0x0000)  /* Real Timer Clock Control 0/Key */
#define OFS_RTCCTL0_L          OFS_RTCCTL0
#define OFS_RTCCTL0_H          OFS_RTCCTL0+1
#define OFS_RTCCTL13          (0x0002)  /* Real Timer Clock Control 1/3 */
#define OFS_RTCCTL13_L         OFS_RTCCTL13
#define OFS_RTCCTL13_H         OFS_RTCCTL13+1
#define RTCCTL1             RTCCTL13_L
#define RTCCTL3             RTCCTL13_H
#define OFS_RTCOCAL           (0x0004)  /* Real Timer Clock Offset Calibartion */
#define OFS_RTCOCAL_L          OFS_RTCOCAL
#define OFS_RTCOCAL_H          OFS_RTCOCAL+1
#define OFS_RTCTCMP           (0x0006)  /* Real Timer Temperature Compensation */
#define OFS_RTCTCMP_L          OFS_RTCTCMP
#define OFS_RTCTCMP_H          OFS_RTCTCMP+1
#define OFS_RTCPS0CTL         (0x0008)  /* Real Timer Prescale Timer 0 Control */
#define OFS_RTCPS0CTL_L        OFS_RTCPS0CTL
#define OFS_RTCPS0CTL_H        OFS_RTCPS0CTL+1
#define OFS_RTCPS1CTL         (0x000A)  /* Real Timer Prescale Timer 1 Control */
#define OFS_RTCPS1CTL_L        OFS_RTCPS1CTL
#define OFS_RTCPS1CTL_H        OFS_RTCPS1CTL+1
#define OFS_RTCPS             (0x000C)  /* Real Timer Prescale Timer Control */
#define OFS_RTCPS_L            OFS_RTCPS
#define OFS_RTCPS_H            OFS_RTCPS+1
#define OFS_RTCIV             (0x000E)  /* Real Time Clock Interrupt Vector */
#define OFS_RTCTIM0           (0x0010)  /* Real Time Clock Time 0 */
#define OFS_RTCTIM0_L          OFS_RTCTIM0
#define OFS_RTCTIM0_H          OFS_RTCTIM0+1
#define OFS_RTCTIM1           (0x0012)  /* Real Time Clock Time 1 */
#define OFS_RTCTIM1_L          OFS_RTCTIM1
#define OFS_RTCTIM1_H          OFS_RTCTIM1+1
#define OFS_RTCDATE           (0x0014)  /* Real Time Clock Date */
#define OFS_RTCDATE_L          OFS_RTCDATE
#define OFS_RTCDATE_H          OFS_RTCDATE+1
#define OFS_RTCYEAR           (0x0016)  /* Real Time Clock Year */
#define OFS_RTCYEAR_L          OFS_RTCYEAR
#define OFS_RTCYEAR_H          OFS_RTCYEAR+1
#define OFS_RTCAMINHR         (0x0018)  /* Real Time Clock Alarm Min/Hour */
#define OFS_RTCAMINHR_L        OFS_RTCAMINHR
#define OFS_RTCAMINHR_H        OFS_RTCAMINHR+1
#define OFS_RTCADOWDAY        (0x001A)  /* Real Time Clock Alarm day of week/day */
#define OFS_RTCADOWDAY_L       OFS_RTCADOWDAY
#define OFS_RTCADOWDAY_H       OFS_RTCADOWDAY+1
#define OFS_BIN2BCD           (0x001C)  /* Real Time Binary-to-BCD conversion register */
#define OFS_BCD2BIN           (0x001E)  /* Real Time BCD-to-binary conversion register */
#define OFS_RTCSEC            (0x0010)
#define OFS_RTCMIN            (0x0011)
#define OFS_RTCHOUR           (0x0012)
#define OFS_RTCDOW            (0x0013)
#define OFS_RTCDAY            (0x0014)
#define OFS_RTCMON            (0x0015)
#define OFS_RTCAMIN           (0x0018)
#define OFS_RTCAHOUR          (0x0019)
#define OFS_RTCADOW           (0x001A)
#define OFS_RTCADAY           (0x001B)

#define OFS_RTCTCCTL0         (0x0020)  /*  Real-Time Clock Time Capture Control Register 0   */
#define OFS_RTCTCCTL1         (0x0021)  /*  Real-Time Clock Time Capture Control Register 1   */
#define OFS_RTCCAP0CTL        (0x0022)  /*  Tamper Detect Pin 0 Control Register   */
#define OFS_RTCCAP1CTL        (0x0023)  /*  Tamper Detect Pin 1 Control Register   */
#define OFS_RTCSECBAK0        (0x0030)  /*  Real-Time Clock Seconds Backup Register 0   */
#define OFS_RTCMINBAK0        (0x0031)  /*  Real-Time Clock Minutes Backup Register 0   */
#define OFS_RTCHOURBAK0       (0x0032)  /*  Real-Time Clock Hours Backup Register 0   */
#define OFS_RTCDAYBAK0        (0x0033)  /*  Real-Time Clock Days Backup Register 0   */
#define OFS_RTCMONBAK0        (0x0034)  /*  Real-Time Clock Months Backup Register 0   */
#define OFS_RTCYEARBAK0       (0x0036)  /*  Real-Time Clock year Backup Register 0   */
#define OFS_RTCSECBAK1        (0x0038)  /*  Real-Time Clock Seconds Backup Register 1   */
#define OFS_RTCMINBAK1        (0x0039)  /*  Real-Time Clock Minutes Backup Register 1   */
#define OFS_RTCHOURBAK1       (0x003A)  /*  Real-Time Clock Hours Backup Register 1   */
#define OFS_RTCDAYBAK1        (0x003B)  /*  Real-Time Clock Days Backup Register 1   */
#define OFS_RTCMONBAK1        (0x003C)  /*  Real-Time Clock Months Backup Register 1   */
#define OFS_RTCYEARBAK1       (0x003E)  /*  Real-Time Clock Year Backup Register 1   */

#define RTCSEC              RTCTIM0_L
#define RTCMIN              RTCTIM0_H
#define RTCHOUR             RTCTIM1_L
#define RTCDOW              RTCTIM1_H
#define RTCDAY              RTCDATE_L
#define RTCMON              RTCDATE_H
#define RTCYEARL            RTCYEAR_L
#define RT0PS               RTCPS_L
#define RT1PS               RTCPS_H
#define RTCAMIN             RTCAMINHR_L    /* Real Time Clock Alarm Min */
#define RTCAHOUR            RTCAMINHR_H    /* Real Time Clock Alarm Hour */
#define RTCADOW             RTCADOWDAY_L   /* Real Time Clock Alarm day of week */
#define RTCADAY             RTCADOWDAY_H   /* Real Time Clock Alarm day */

/* RTCCTL0 Control Bits */
#define RTCOFIE             (0x0080)   /* RTC 32kHz cyrstal oscillator fault interrupt enable */
#define RTCTEVIE            (0x0040)   /* RTC Time Event Interrupt Enable Flag */
#define RTCAIE              (0x0020)   /* RTC Alarm Interrupt Enable Flag */
#define RTCRDYIE            (0x0010)   /* RTC Ready Interrupt Enable Flag */
#define RTCOFIFG            (0x0008)   /* RTC 32kHz cyrstal oscillator fault interrupt flag */
#define RTCTEVIFG           (0x0004)   /* RTC Time Event Interrupt Flag */
#define RTCAIFG             (0x0002)   /* RTC Alarm Interrupt Flag */
#define RTCRDYIFG           (0x0001)   /* RTC Ready Interrupt Flag */

/* RTCCTL0 Control Bits */
#define RTCOFIE_L           (0x0080)   /* RTC 32kHz cyrstal oscillator fault interrupt enable */
#define RTCTEVIE_L          (0x0040)   /* RTC Time Event Interrupt Enable Flag */
#define RTCAIE_L            (0x0020)   /* RTC Alarm Interrupt Enable Flag */
#define RTCRDYIE_L          (0x0010)   /* RTC Ready Interrupt Enable Flag */
#define RTCOFIFG_L          (0x0008)   /* RTC 32kHz cyrstal oscillator fault interrupt flag */
#define RTCTEVIFG_L         (0x0004)   /* RTC Time Event Interrupt Flag */
#define RTCAIFG_L           (0x0002)   /* RTC Alarm Interrupt Flag */
#define RTCRDYIFG_L         (0x0001)   /* RTC Ready Interrupt Flag */


#define RTCKEY              (0xA500)   /* RTC Key for RTC write access */
#define RTCKEY_H            (0xA5)     /* RTC Key for RTC write access (high word) */


/* RTCCTL13 Control Bits */
#define RTCCALF1            (0x0200)   /* RTC Calibration Frequency Bit 1 */
#define RTCCALF0            (0x0100)   /* RTC Calibration Frequency Bit 0 */
#define RTCBCD              (0x0080)   /* RTC BCD  0:Binary / 1:BCD */
#define RTCHOLD             (0x0040)   /* RTC Hold */
#define RTCMODE             (0x0020)   /* RTC Mode 0:Counter / 1: Calendar */
#define RTCRDY              (0x0010)   /* RTC Ready */
#define RTCSSEL1            (0x0008)   /* RTC Source Select 1 */
#define RTCSSEL0            (0x0004)   /* RTC Source Select 0 */
#define RTCTEV1             (0x0002)   /* RTC Time Event 1 */
#define RTCTEV0             (0x0001)   /* RTC Time Event 0 */

/* RTCCTL13 Control Bits */
#define RTCBCD_L            (0x0080)   /* RTC BCD  0:Binary / 1:BCD */
#define RTCHOLD_L           (0x0040)   /* RTC Hold */
#define RTCMODE_L           (0x0020)   /* RTC Mode 0:Counter / 1: Calendar */
#define RTCRDY_L            (0x0010)   /* RTC Ready */
#define RTCSSEL1_L          (0x0008)   /* RTC Source Select 1 */
#define RTCSSEL0_L          (0x0004)   /* RTC Source Select 0 */
#define RTCTEV1_L           (0x0002)   /* RTC Time Event 1 */
#define RTCTEV0_L           (0x0001)   /* RTC Time Event 0 */

/* RTCCTL13 Control Bits */
#define RTCCALF1_H          (0x0002)   /* RTC Calibration Frequency Bit 1 */
#define RTCCALF0_H          (0x0001)   /* RTC Calibration Frequency Bit 0 */

#define RTCSSEL_0           (0x0000)   /* RTC Source Select ACLK */
#define RTCSSEL_1           (0x0004)   /* RTC Source Select SMCLK */
#define RTCSSEL_2           (0x0008)   /* RTC Source Select RT1PS */
#define RTCSSEL_3           (0x000C)   /* RTC Source Select RT1PS */
#define RTCSSEL__ACLK       (0x0000)   /* RTC Source Select ACLK */
#define RTCSSEL__SMCLK      (0x0004)   /* RTC Source Select SMCLK */
#define RTCSSEL__RT1PS      (0x0008)   /* RTC Source Select RT1PS */

#define RTCTEV_0            (0x0000)   /* RTC Time Event: 0 (Min. changed) */
#define RTCTEV_1            (0x0001)   /* RTC Time Event: 1 (Hour changed) */
#define RTCTEV_2            (0x0002)   /* RTC Time Event: 2 (12:00 changed) */
#define RTCTEV_3            (0x0003)   /* RTC Time Event: 3 (00:00 changed) */
#define RTCTEV__MIN         (0x0000)   /* RTC Time Event: 0 (Min. changed) */
#define RTCTEV__HOUR        (0x0001)   /* RTC Time Event: 1 (Hour changed) */
#define RTCTEV__0000        (0x0002)   /* RTC Time Event: 2 (00:00 changed) */
#define RTCTEV__1200        (0x0003)   /* RTC Time Event: 3 (12:00 changed) */

#define RTCCALF_0           (0x0000)   /* RTC Calibration Frequency: No Output */
#define RTCCALF_1           (0x0100)   /* RTC Calibration Frequency: 512 Hz */
#define RTCCALF_2           (0x0200)   /* RTC Calibration Frequency: 256 Hz */
#define RTCCALF_3           (0x0300)   /* RTC Calibration Frequency: 1 Hz */


/* RTCOCAL Control Bits */
#define RTCOCALS            (0x8000)   /* RTC Offset Calibration Sign */
#define RTCOCAL7            (0x0080)   /* RTC Offset Calibration Bit 7 */
#define RTCOCAL6            (0x0040)   /* RTC Offset Calibration Bit 6 */
#define RTCOCAL5            (0x0020)   /* RTC Offset Calibration Bit 5 */
#define RTCOCAL4            (0x0010)   /* RTC Offset Calibration Bit 4 */
#define RTCOCAL3            (0x0008)   /* RTC Offset Calibration Bit 3 */
#define RTCOCAL2            (0x0004)   /* RTC Offset Calibration Bit 2 */
#define RTCOCAL1            (0x0002)   /* RTC Offset Calibration Bit 1 */
#define RTCOCAL0            (0x0001)   /* RTC Offset Calibration Bit 0 */

/* RTCOCAL Control Bits */
#define RTCOCAL7_L          (0x0080)   /* RTC Offset Calibration Bit 7 */
#define RTCOCAL6_L          (0x0040)   /* RTC Offset Calibration Bit 6 */
#define RTCOCAL5_L          (0x0020)   /* RTC Offset Calibration Bit 5 */
#define RTCOCAL4_L          (0x0010)   /* RTC Offset Calibration Bit 4 */
#define RTCOCAL3_L          (0x0008)   /* RTC Offset Calibration Bit 3 */
#define RTCOCAL2_L          (0x0004)   /* RTC Offset Calibration Bit 2 */
#define RTCOCAL1_L          (0x0002)   /* RTC Offset Calibration Bit 1 */
#define RTCOCAL0_L          (0x0001)   /* RTC Offset Calibration Bit 0 */

/* RTCOCAL Control Bits */
#define RTCOCALS_H          (0x0080)   /* RTC Offset Calibration Sign */

/* RTCTCMP Control Bits */
#define RTCTCMPS            (0x8000)   /* RTC Temperature Compensation Sign */
#define RTCTCRDY            (0x4000)   /* RTC Temperature compensation ready */
#define RTCTCOK             (0x2000)   /* RTC Temperature compensation write OK */
#define RTCTCMP7            (0x0080)   /* RTC Temperature Compensation Bit 7 */
#define RTCTCMP6            (0x0040)   /* RTC Temperature Compensation Bit 6 */
#define RTCTCMP5            (0x0020)   /* RTC Temperature Compensation Bit 5 */
#define RTCTCMP4            (0x0010)   /* RTC Temperature Compensation Bit 4 */
#define RTCTCMP3            (0x0008)   /* RTC Temperature Compensation Bit 3 */
#define RTCTCMP2            (0x0004)   /* RTC Temperature Compensation Bit 2 */
#define RTCTCMP1            (0x0002)   /* RTC Temperature Compensation Bit 1 */
#define RTCTCMP0            (0x0001)   /* RTC Temperature Compensation Bit 0 */

/* RTCTCMP Control Bits */
#define RTCTCMP7_L          (0x0080)   /* RTC Temperature Compensation Bit 7 */
#define RTCTCMP6_L          (0x0040)   /* RTC Temperature Compensation Bit 6 */
#define RTCTCMP5_L          (0x0020)   /* RTC Temperature Compensation Bit 5 */
#define RTCTCMP4_L          (0x0010)   /* RTC Temperature Compensation Bit 4 */
#define RTCTCMP3_L          (0x0008)   /* RTC Temperature Compensation Bit 3 */
#define RTCTCMP2_L          (0x0004)   /* RTC Temperature Compensation Bit 2 */
#define RTCTCMP1_L          (0x0002)   /* RTC Temperature Compensation Bit 1 */
#define RTCTCMP0_L          (0x0001)   /* RTC Temperature Compensation Bit 0 */

/* RTCTCMP Control Bits */
#define RTCTCMPS_H          (0x0080)   /* RTC Temperature Compensation Sign */
#define RTCTCRDY_H          (0x0040)   /* RTC Temperature compensation ready */
#define RTCTCOK_H           (0x0020)   /* RTC Temperature compensation write OK */


#define RTCAE               (0x80)     /* Real Time Clock Alarm enable */




/* RTCPS0CTL Control Bits */
//#define Reserved          (0x8000)
//#define Reserved          (0x4000)
#define RT0PSDIV2           (0x2000)   /* RTC Prescale Timer 0 Clock Divide Bit: 2 */
#define RT0PSDIV1           (0x1000)   /* RTC Prescale Timer 0 Clock Divide Bit: 1 */
#define RT0PSDIV0           (0x0800)   /* RTC Prescale Timer 0 Clock Divide Bit: 0 */
//#define Reserved          (0x0400)
//#define Reserved          (0x0200)
#define RT0PSHOLD           (0x0100)   /* RTC Prescale Timer 0 Hold */
//#define Reserved          (0x0080)
//#define Reserved          (0x0040)
//#define Reserved          (0x0020)
#define RT0IP2              (0x0010)   /* RTC Prescale Timer 0 Interrupt Interval Bit: 2 */
#define RT0IP1              (0x0008)   /* RTC Prescale Timer 0 Interrupt Interval Bit: 1 */
#define RT0IP0              (0x0004)   /* RTC Prescale Timer 0 Interrupt Interval Bit: 0 */
#define RT0PSIE             (0x0002)   /* RTC Prescale Timer 0 Interrupt Enable Flag */
#define RT0PSIFG            (0x0001)   /* RTC Prescale Timer 0 Interrupt Flag */

/* RTCPS0CTL Control Bits */
//#define Reserved          (0x8000)
//#define Reserved          (0x4000)
//#define Reserved          (0x0400)
//#define Reserved          (0x0200)
//#define Reserved          (0x0080)
//#define Reserved          (0x0040)
//#define Reserved          (0x0020)
#define RT0IP2_L            (0x0010)   /* RTC Prescale Timer 0 Interrupt Interval Bit: 2 */
#define RT0IP1_L            (0x0008)   /* RTC Prescale Timer 0 Interrupt Interval Bit: 1 */
#define RT0IP0_L            (0x0004)   /* RTC Prescale Timer 0 Interrupt Interval Bit: 0 */
#define RT0PSIE_L           (0x0002)   /* RTC Prescale Timer 0 Interrupt Enable Flag */
#define RT0PSIFG_L          (0x0001)   /* RTC Prescale Timer 0 Interrupt Flag */

/* RTCPS0CTL Control Bits */
//#define Reserved          (0x8000)
//#define Reserved          (0x4000)
#define RT0PSDIV2_H         (0x0020)   /* RTC Prescale Timer 0 Clock Divide Bit: 2 */
#define RT0PSDIV1_H         (0x0010)   /* RTC Prescale Timer 0 Clock Divide Bit: 1 */
#define RT0PSDIV0_H         (0x0008)   /* RTC Prescale Timer 0 Clock Divide Bit: 0 */
//#define Reserved          (0x0400)
//#define Reserved          (0x0200)
#define RT0PSHOLD_H         (0x0001)   /* RTC Prescale Timer 0 Hold */
//#define Reserved          (0x0080)
//#define Reserved          (0x0040)
//#define Reserved          (0x0020)

#define RT0IP_0             (0x0000)   /* RTC Prescale Timer 0 Interrupt Interval /2 */
#define RT0IP_1             (0x0004)   /* RTC Prescale Timer 0 Interrupt Interval /4 */
#define RT0IP_2             (0x0008)   /* RTC Prescale Timer 0 Interrupt Interval /8 */
#define RT0IP_3             (0x000C)   /* RTC Prescale Timer 0 Interrupt Interval /16 */
#define RT0IP_4             (0x0010)   /* RTC Prescale Timer 0 Interrupt Interval /32 */
#define RT0IP_5             (0x0014)   /* RTC Prescale Timer 0 Interrupt Interval /64 */
#define RT0IP_6             (0x0018)   /* RTC Prescale Timer 0 Interrupt Interval /128 */
#define RT0IP_7             (0x001C)   /* RTC Prescale Timer 0 Interrupt Interval /256 */


/* RTCPS1CTL Control Bits */
#define RT1SSEL1            (0x8000)   /* RTC Prescale Timer 1 Source Select Bit 1 */
#define RT1SSEL0            (0x4000)   /* RTC Prescale Timer 1 Source Select Bit 0 */
#define RT1PSDIV2           (0x2000)   /* RTC Prescale Timer 1 Clock Divide Bit: 2 */
#define RT1PSDIV1           (0x1000)   /* RTC Prescale Timer 1 Clock Divide Bit: 1 */
#define RT1PSDIV0           (0x0800)   /* RTC Prescale Timer 1 Clock Divide Bit: 0 */
//#define Reserved          (0x0400)
//#define Reserved          (0x0200)
#define RT1PSHOLD           (0x0100)   /* RTC Prescale Timer 1 Hold */
//#define Reserved          (0x0080)
//#define Reserved          (0x0040)
//#define Reserved          (0x0020)
#define RT1IP2              (0x0010)   /* RTC Prescale Timer 1 Interrupt Interval Bit: 2 */
#define RT1IP1              (0x0008)   /* RTC Prescale Timer 1 Interrupt Interval Bit: 1 */
#define RT1IP0              (0x0004)   /* RTC Prescale Timer 1 Interrupt Interval Bit: 0 */
#define RT1PSIE             (0x0002)   /* RTC Prescale Timer 1 Interrupt Enable Flag */
#define RT1PSIFG            (0x0001)   /* RTC Prescale Timer 1 Interrupt Flag */

/* RTCPS1CTL Control Bits */
//#define Reserved          (0x0400)
//#define Reserved          (0x0200)
//#define Reserved          (0x0080)
//#define Reserved          (0x0040)
//#define Reserved          (0x0020)
#define RT1IP2_L            (0x0010)   /* RTC Prescale Timer 1 Interrupt Interval Bit: 2 */
#define RT1IP1_L            (0x0008)   /* RTC Prescale Timer 1 Interrupt Interval Bit: 1 */
#define RT1IP0_L            (0x0004)   /* RTC Prescale Timer 1 Interrupt Interval Bit: 0 */
#define RT1PSIE_L           (0x0002)   /* RTC Prescale Timer 1 Interrupt Enable Flag */
#define RT1PSIFG_L          (0x0001)   /* RTC Prescale Timer 1 Interrupt Flag */

/* RTCPS1CTL Control Bits */
#define RT1SSEL1_H          (0x0080)   /* RTC Prescale Timer 1 Source Select Bit 1 */
#define RT1SSEL0_H          (0x0040)   /* RTC Prescale Timer 1 Source Select Bit 0 */
#define RT1PSDIV2_H         (0x0020)   /* RTC Prescale Timer 1 Clock Divide Bit: 2 */
#define RT1PSDIV1_H         (0x0010)   /* RTC Prescale Timer 1 Clock Divide Bit: 1 */
#define RT1PSDIV0_H         (0x0008)   /* RTC Prescale Timer 1 Clock Divide Bit: 0 */
//#define Reserved          (0x0400)
//#define Reserved          (0x0200)
#define RT1PSHOLD_H         (0x0001)   /* RTC Prescale Timer 1 Hold */
//#define Reserved          (0x0080)
//#define Reserved          (0x0040)
//#define Reserved          (0x0020)

#define RT1IP_0             (0x0000)   /* RTC Prescale Timer 1 Interrupt Interval /2 */
#define RT1IP_1             (0x0004)   /* RTC Prescale Timer 1 Interrupt Interval /4 */
#define RT1IP_2             (0x0008)   /* RTC Prescale Timer 1 Interrupt Interval /8 */
#define RT1IP_3             (0x000C)   /* RTC Prescale Timer 1 Interrupt Interval /16 */
#define RT1IP_4             (0x0010)   /* RTC Prescale Timer 1 Interrupt Interval /32 */
#define RT1IP_5             (0x0014)   /* RTC Prescale Timer 1 Interrupt Interval /64 */
#define RT1IP_6             (0x0018)   /* RTC Prescale Timer 1 Interrupt Interval /128 */
#define RT1IP_7             (0x001C)   /* RTC Prescale Timer 1 Interrupt Interval /256 */

/* RTCTCCTL0 Control Bits */
#define TCEN                (0x0001)   /* RTC Enable for RTC Tamper Detection with Time Stamp */
#define AUX3RST             (0x0002)   /* RTC Indication of power cycle on AUXVCC3 */

/* RTCTCCTL1 Control Bits */
#define RTCCAPIFG           (0x0001)   /* RTC  Tamper Event Interrupt Flag */
#define RTCCAPIE            (0x0002)   /* RTC Tamper Event Interrupt Enable */

/* RTCCAPxCTL Control Bits */
#define CAPEV               (0x0001)   /* RTC Tamper Event Flag */
#define CAPES               (0x0004)   /* RTC Event Edge Select */
#define RTCREN              (0x0008)   /* RTC RTCCAPx pin pullup/pulldown resistor enable */
#define RTCCAPIN            (0x0010)   /* RTC RTCCAPx input */
#define RTCCAPDIR           (0x0020)   /* RTC RTCCAPx Pin direction */
#define RTCCAPOUT           (0x0040)   /* RTC RTCCAPx Output */


/* RTCIV Definitions */
#define RTCIV_NONE         (0x0000)    /* No Interrupt pending */
#define RTCIV_RTCOFIFG     (0x0002)    /* RTC Osc fault: RTCOFIFG */
#define RTCIV_RTCCAPIFG    (0x0004)    /* RTC RTC Tamper Event: RTCCAPIFG */
#define RTCIV_RTCRDYIFG    (0x0006)    /* RTC ready: RTCRDYIFG */
#define RTCIV_RTCTEVIFG    (0x0008)    /* RTC interval timer: RTCTEVIFG */
#define RTCIV_RTCAIFG      (0x000A)    /* RTC user alarm: RTCAIFG */
#define RTCIV_RT0PSIFG     (0x000C)    /* RTC prescaler 0: RT0PSIFG */
#define RTCIV_RT1PSIFG     (0x000E)    /* RTC prescaler 1: RT1PSIFG */

/* Legacy RTCIV Definitions */
#define RTC_NONE           (0x0000)    /* No Interrupt pending */
#define RTC_RTCOFIFG       (0x0002)    /* RTC Osc fault: RTCOFIFG */
#define RTC_RTCRDYIFG      (0x0006)    /* RTC ready: RTCRDYIFG */
#define RTC_RTCTEVIFG      (0x0008)    /* RTC interval timer: RTCTEVIFG */
#define RTC_RTCAIFG        (0x000A)    /* RTC user alarm: RTCAIFG */
#define RTC_RT0PSIFG       (0x000C)    /* RTC prescaler 0: RT0PSIFG */
#define RTC_RT1PSIFG       (0x000E)    /* RTC prescaler 1: RT1PSIFG */

#endif
/************************************************************
* SD24_B - Sigma Delta 24 Bit
************************************************************/
#ifdef  __MSP430_HAS_SD24_B__         /* Definition to show that Module is available */

#define OFS_SD24BCTL0         (0x0000)  /* SD24B Control Register 0 */
#define OFS_SD24BCTL0_L        OFS_SD24BCTL0
#define OFS_SD24BCTL0_H        OFS_SD24BCTL0+1
#define OFS_SD24BCTL1         (0x0002)  /* SD24B Control Register 1 */
#define OFS_SD24BCTL1_L        OFS_SD24BCTL1
#define OFS_SD24BCTL1_H        OFS_SD24BCTL1+1
#define OFS_SD24BTRGCTL       (0x0004)  /* SD24B Trigger Control Register */
#define OFS_SD24BTRGCTL_L      OFS_SD24BTRGCTL
#define OFS_SD24BTRGCTL_H      OFS_SD24BTRGCTL+1
#define OFS_SD24BTRGOSR       (0x0006)  /* SD24B Trigger OSR Control Register */
#define OFS_SD24BTRGOSR_L      OFS_SD24BTRGOSR
#define OFS_SD24BTRGOSR_H      OFS_SD24BTRGOSR+1
#define OFS_SD24BTRGPRE       (0x0008)  /* SD24B Trigger Preload Register */
#define OFS_SD24BTRGPRE_L      OFS_SD24BTRGPRE
#define OFS_SD24BTRGPRE_H      OFS_SD24BTRGPRE+1
#define OFS_SD24BIFG          (0x000A)  /* SD24B Interrupt Flag Register */
#define OFS_SD24BIFG_L         OFS_SD24BIFG
#define OFS_SD24BIFG_H         OFS_SD24BIFG+1
#define OFS_SD24BIE           (0x000C)  /* SD24B Interrupt Enable Register */
#define OFS_SD24BIE_L          OFS_SD24BIE
#define OFS_SD24BIE_H          OFS_SD24BIE+1
#define OFS_SD24BIV           (0x000E)  /* SD24B Interrupt Vector Register */
#define OFS_SD24BIV_L          OFS_SD24BIV
#define OFS_SD24BIV_H          OFS_SD24BIV+1

#define OFS_SD24BCCTL0        (0x0010)  /* SD24B Channel 0 Control Register */
#define OFS_SD24BCCTL0_L       OFS_SD24BCCTL0
#define OFS_SD24BCCTL0_H       OFS_SD24BCCTL0+1
#define OFS_SD24BINCTL0       (0x0012)  /* SD24B Channel 0 Input Control Register */
#define OFS_SD24BINCTL0_L      OFS_SD24BINCTL0
#define OFS_SD24BINCTL0_H      OFS_SD24BINCTL0+1
#define OFS_SD24BOSR0         (0x0014)  /* SD24B Channel 0 OSR Control Register */
#define OFS_SD24BOSR0_L        OFS_SD24BOSR0
#define OFS_SD24BOSR0_H        OFS_SD24BOSR0+1
#define OFS_SD24BPRE0         (0x0016)  /* SD24B Channel 0 Preload Register */
#define OFS_SD24BPRE0_L        OFS_SD24BPRE0
#define OFS_SD24BPRE0_H        OFS_SD24BPRE0+1

#define OFS_SD24BMEML0        (0x0050)  /* SD24B Channel 0 Conversion Memory Low word */
#define OFS_SD24BMEML0_L       OFS_SD24BMEML0
#define OFS_SD24BMEML0_H       OFS_SD24BMEML0+1
#define OFS_SD24BMEMH0        (0x0052)  /* SD24B Channel 0 Conversion Memory High Word */
#define OFS_SD24BMEMH0_L       OFS_SD24BMEMH0
#define OFS_SD24BMEMH0_H       OFS_SD24BMEMH0+1


/* SD24BCTL0 */
#define SD24OV32            (0x0002)  /* SD24B Overflow Control */
#define SD24REFS            (0x0004)  /* SD24B Reference Select */
#define SD24SSEL0           (0x0010)  /* SD24B Clock Source Select 0 */
#define SD24SSEL1           (0x0020)  /* SD24B Clock Source Select 1 */
#define SD24M4              (0x0040)  /* SD24B Modulator clock to Manchester decoder clock ratio */
#define SD24CLKOS           (0x0080)  /* SD24B Clock Output Select */
#define SD24PDIV0           (0x0100)  /* SD24B Frequency pre-scaler Bit 0 */
#define SD24PDIV1           (0x0200)  /* SD24B Frequency pre-scaler Bit 1 */
#define SD24PDIV2           (0x0400)  /* SD24B Frequency pre-scaler Bit 2 */
#define SD24DIV0            (0x0800)  /* SD24B Frequency Divider Bit 0 */
#define SD24DIV1            (0x1000)  /* SD24B Frequency Divider Bit 1 */
#define SD24DIV2            (0x2000)  /* SD24B Frequency Divider Bit 2 */
#define SD24DIV3            (0x4000)  /* SD24B Frequency Divider Bit 3 */
#define SD24DIV4            (0x8000)  /* SD24B Frequency Divider Bit 4 */

#define SD24OV32_L          (0x0002)  /* SD24B Overflow Control */
#define SD24REFS_L          (0x0004)  /* SD24B Reference Select */
#define SD24SSEL0_L         (0x0010)  /* SD24B Clock Source Select 0 */
#define SD24SSEL1_L         (0x0020)  /* SD24B Clock Source Select 1 */
#define SD24M4_L            (0x0040)  /* SD24B Modulator clock to Manchester decoder clock ratio */
#define SD24CLKOS_L         (0x0080)  /* SD24B Clock Output Select */

#define SD24PDIV0_H         (0x0001)  /* SD24B Frequency pre-scaler Bit 0 */
#define SD24PDIV1_H         (0x0002)  /* SD24B Frequency pre-scaler Bit 1 */
#define SD24PDIV2_H         (0x0004)  /* SD24B Frequency pre-scaler Bit 2 */
#define SD24DIV0_H          (0x0008)  /* SD24B Frequency Divider Bit 0 */
#define SD24DIV1_H          (0x0010)  /* SD24B Frequency Divider Bit 1 */
#define SD24DIV2_H          (0x0020)  /* SD24B Frequency Divider Bit 2 */
#define SD24DIV3_H          (0x0040)  /* SD24B Frequency Divider Bit 3 */
#define SD24DIV4_H          (0x0080)  /* SD24B Frequency Divider Bit 4 */

#define SD24SSEL_0          (0x0000)  /* SD24B Clock Source Select MCLK  */
#define SD24SSEL_1          (0x0010)  /* SD24B Clock Source Select SMCLK */
#define SD24SSEL_2          (0x0020)  /* SD24B Clock Source Select ACLK  */
#define SD24SSEL_3          (0x0030)  /* SD24B Clock Source Select TACLK */
#define SD24SSEL__MCLK      (0x0000)  /* SD24B Clock Source Select MCLK  */
#define SD24SSEL__SMCLK     (0x0010)  /* SD24B Clock Source Select SMCLK */
#define SD24SSEL__ACLK      (0x0020)  /* SD24B Clock Source Select ACLK  */
#define SD24SSEL__SD24CLK   (0x0030)  /* SD24B Clock Source Select SD24CLK */

#define SD24PDIV_0          (0x0000)  /* SD24B Frequency pre-scaler  /1 */
#define SD24PDIV_1          (0x0100)  /* SD24B Frequency pre-scaler  /2 */
#define SD24PDIV_2          (0x0200)  /* SD24B Frequency pre-scaler  /4 */
#define SD24PDIV_3          (0x0300)  /* SD24B Frequency pre-scaler  /8 */
#define SD24PDIV_4          (0x0400)  /* SD24B Frequency pre-scaler  /16 */
#define SD24PDIV_5          (0x0500)  /* SD24B Frequency pre-scaler  /32 */
#define SD24PDIV_6          (0x0600)  /* SD24B Frequency pre-scaler  /64 */
#define SD24PDIV_7          (0x0700)  /* SD24B Frequency pre-scaler  /128 */

/* SD24BCTL1 */
#define SD24GRP0SC          (0x0001)  /* SD24B Group 0 Start Conversion */
#define SD24GRP1SC          (0x0002)  /* SD24B Group 1 Start Conversion */
#define SD24GRP2SC          (0x0004)  /* SD24B Group 2 Start Conversion */
#define SD24GRP3SC          (0x0008)  /* SD24B Group 3 Start Conversion */
#define SD24DMA0            (0x0100)  /* SD24B DMA Trigger Select Bit 0 */
#define SD24DMA1            (0x0200)  /* SD24B DMA Trigger Select Bit 1 */
#define SD24DMA2            (0x0400)  /* SD24B DMA Trigger Select Bit 2 */
#define SD24DMA3            (0x0800)  /* SD24B DMA Trigger Select Bit 3 */

#define SD24GRP0SC_L        (0x0001)  /* SD24B Group 0 Start Conversion */
#define SD24GRP1SC_L        (0x0002)  /* SD24B Group 1 Start Conversion */
#define SD24GRP2SC_L        (0x0004)  /* SD24B Group 2 Start Conversion */
#define SD24GRP3SC_L        (0x0008)  /* SD24B Group 3 Start Conversion */

#define SD24DMA0_H          (0x0001)  /* SD24B DMA Trigger Select Bit 0 */
#define SD24DMA1_H          (0x0002)  /* SD24B DMA Trigger Select Bit 1 */
#define SD24DMA2_H          (0x0004)  /* SD24B DMA Trigger Select Bit 2 */
#define SD24DMA3_H          (0x0008)  /* SD24B DMA Trigger Select Bit 3 */

#define SD24DMA_0           (0x0000)  /* SD24B DMA Trigger: 0 */
#define SD24DMA_1           (0x0100)  /* SD24B DMA Trigger: 1 */
#define SD24DMA_2           (0x0200)  /* SD24B DMA Trigger: 2 */
#define SD24DMA_3           (0x0300)  /* SD24B DMA Trigger: 3 */
#define SD24DMA_4           (0x0400)  /* SD24B DMA Trigger: 4 */
#define SD24DMA_5           (0x0500)  /* SD24B DMA Trigger: 5 */
#define SD24DMA_6           (0x0600)  /* SD24B DMA Trigger: 6 */
#define SD24DMA_7           (0x0700)  /* SD24B DMA Trigger: 7 */
#define SD24DMA_8           (0x0800)  /* SD24B DMA Trigger: 8 */

/* SD24BTRGCTL */
#define SD24SC              (0x0001)  /* SD24B Start Conversion */
#define SD24SCS0            (0x0002)  /* SD24B Start Conversion Select Bit 0 */
#define SD24SCS1            (0x0004)  /* SD24B Start Conversion Select Bit 1 */
#define SD24SCS2            (0x0008)  /* SD24B Start Conversion Select Bit 2 */
#define SD24SNGL            (0x0100)  /* SD24B Single Trigger Mode */
#define SD24TRGIFG          (0x0400)  /* SD24B Trigger Interrupt Flag */
#define SD24TRGIE           (0x0800)  /* SD24B Trigger Interrupt Enable */

#define SD24SC_L            (0x0001)  /* SD24B Start Conversion */
#define SD24SCS0_L          (0x0002)  /* SD24B Start Conversion Select Bit 0 */
#define SD24SCS1_L          (0x0004)  /* SD24B Start Conversion Select Bit 1 */
#define SD24SCS2_L          (0x0008)  /* SD24B Start Conversion Select Bit 2 */

#define SD24SNGL_H          (0x0001)  /* SD24B Single Trigger Mode */
#define SD24TRGIFG_H        (0x0004)  /* SD24B Trigger Interrupt Flag */
#define SD24TRGIE_H         (0x0008)  /* SD24B Trigger Interrupt Enable */

#define SD24SCS_0           (0x0000)  /* SD24B Start Conversion Select: 0 */
#define SD24SCS_1           (0x0002)  /* SD24B Start Conversion Select: 1 */
#define SD24SCS_2           (0x0004)  /* SD24B Start Conversion Select: 2 */
#define SD24SCS_3           (0x0006)  /* SD24B Start Conversion Select: 3 */
#define SD24SCS_4           (0x0008)  /* SD24B Start Conversion Select: 4 */
#define SD24SCS_5           (0x000A)  /* SD24B Start Conversion Select: 5 */
#define SD24SCS_6           (0x000C)  /* SD24B Start Conversion Select: 6 */
#define SD24SCS_7           (0x000E)  /* SD24B Start Conversion Select: 7 */
#define SD24SCS__SD24SC     (0x0000)  /* SD24B Start Conversion Select: SD24SC */
#define SD24SCS__EXT1       (0x0002)  /* SD24B Start Conversion Select: EXT1   */
#define SD24SCS__EXT2       (0x0004)  /* SD24B Start Conversion Select: EXT2   */
#define SD24SCS__EXT3       (0x0006)  /* SD24B Start Conversion Select: EXT3   */
#define SD24SCS__GROUP0     (0x0008)  /* SD24B Start Conversion Select: GROUP0 */
#define SD24SCS__GROUP1     (0x000A)  /* SD24B Start Conversion Select: GROUP1 */
#define SD24SCS__GROUP2     (0x000C)  /* SD24B Start Conversion Select: GROUP2 */
#define SD24SCS__GROUP3     (0x000E)  /* SD24B Start Conversion Select: GROUP3 */

/* SD24BIFG */
#define SD24IFG0            (0x0001)  /* SD24B Channel 0 Interrupt Flag */
#define SD24OVIFG0          (0x0100)  /* SD24B Channel 0 Overflow Interrupt Flag */

#define SD24IFG0_L          (0x0001)  /* SD24B Channel 0 Interrupt Flag */

#define SD24OVIFG0_H        (0x0001)  /* SD24B Channel 0 Overflow Interrupt Flag */

/* SD24BIE */
#define SD24IE0             (0x0001)  /* SD24B Channel 0 Interrupt Enable */
#define SD24OVIE0           (0x0100)  /* SD24B Channel 0 Overflow Interrupt Enable */

#define SD24IE0_L           (0x0001)  /* SD24B Channel 0 Interrupt Enable */

#define SD24OVIE0_H         (0x0001)  /* SD24B Channel 0 Overflow Interrupt Enable */

/* SD24BIV Definitions */
#define SD24BIV_NONE         (0x0000)    /* No Interrupt pending */
#define SD24BIV_SD24OVIFG    (0x0002)    /* SD24OVIFG */
#define SD24BIV_SD24TRGIFG   (0x0004)    /* SD24TRGIFG */
#define SD24BIV_SD24IFG0     (0x0006)    /* SD24IFG0 */

/* SD24BCCTLx */
#define SD24DF0              (0x0010)  /* SD24B Data Format Bit: 0 */
#define SD24DF1              (0x0020)  /* SD24B Data Format Bit: 1 */
#define SD24ALGN             (0x0040)  /* SD24B Data Alignment */
#define SD24CAL              (0x0200)  /* SD24B Calibration */
#define SD24DFS0             (0x0400)  /* SD24B Digital Filter Bit: 0 */
#define SD24DFS1             (0x0800)  /* SD24B Digital Filter Bit: 1 */
#define SD24DI               (0x1000)  /* SD24B Digital Bitstream Input */
#define SD24MC0              (0x2000)  /* SD24B Manchaster Encoding Bit: 0 */
#define SD24MC1              (0x4000)  /* SD24B Manchaster Encoding Bit: 1 */

#define SD24DF0_L           (0x0010)  /* SD24B Data Format Bit: 0 */
#define SD24DF1_L           (0x0020)  /* SD24B Data Format Bit: 1 */
#define SD24ALGN_L          (0x0040)  /* SD24B Data Alignment */

#define SD24CAL_H           (0x0002)  /* SD24B Calibration */
#define SD24DFS0_H          (0x0004)  /* SD24B Digital Filter Bit: 0 */
#define SD24DFS1_H          (0x0008)  /* SD24B Digital Filter Bit: 1 */
#define SD24DI_H            (0x0010)  /* SD24B Digital Bitstream Input */
#define SD24MC0_H           (0x0020)  /* SD24B Manchaster Encoding Bit: 0 */
#define SD24MC1_H           (0x0040)  /* SD24B Manchaster Encoding Bit: 1 */

#define SD24DF_0             (0x0000)  /* SD24B Data Format: Offset Binary  */
#define SD24DF_1             (0x0010)  /* SD24B Data Format: 2's complement */

#define SD24DFS_0            (0x0000)  /* SD24B Digital Filter 0 */
#define SD24DFS_1            (0x0400)  /* SD24B Digital Filter 1 */
#define SD24DFS_2            (0x0800)  /* SD24B Digital Filter 2 */
#define SD24DFS_3            (0x0C00)  /* SD24B Digital Filter 3 */

#define SD24MC_0             (0x0000)  /* SD24B Manchaster Encoding 0 */
#define SD24MC_1             (0x2000)  /* SD24B Manchaster Encoding 1 */
#define SD24MC_2             (0x4000)  /* SD24B Manchaster Encoding 2 */
#define SD24MC_3             (0x6000)  /* SD24B Manchaster Encoding 3 */

/* SD24BINCTLx */
#define SD24GAIN0           (0x0008)  /* SD24B Input Pre-Amplifier Gain Select 0 */
#define SD24GAIN1           (0x0010)  /* SD24B Input Pre-Amplifier Gain Select 1 */
#define SD24GAIN2           (0x0020)  /* SD24B Input Pre-Amplifier Gain Select 2 */
#define SD24INTDLY0         (0x0040)  /* SD24B Interrupt Delay after 1.Conversion 0 */
#define SD24INTDLY1         (0x0080)  /* SD24B Interrupt Delay after 1.Conversion 1 */

#define SD24GAIN0_L         (0x0008)  /* SD24B Input Pre-Amplifier Gain Select 0 */
#define SD24GAIN1_L         (0x0010)  /* SD24B Input Pre-Amplifier Gain Select 1 */
#define SD24GAIN2_L         (0x0020)  /* SD24B Input Pre-Amplifier Gain Select 2 */
#define SD24INTDLY0_L       (0x0040)  /* SD24B Interrupt Delay after 1.Conversion 0 */
#define SD24INTDLY1_L       (0x0080)  /* SD24B Interrupt Delay after 1.Conversion 1 */


#define SD24GAIN_1          (0x0000)  /* SD24B Input Pre-Amplifier Gain Select *1  */
#define SD24GAIN_2          (0x0008)  /* SD24B Input Pre-Amplifier Gain Select *2  */
#define SD24GAIN_4          (0x0010)  /* SD24B Input Pre-Amplifier Gain Select *4  */
#define SD24GAIN_8          (0x0018)  /* SD24B Input Pre-Amplifier Gain Select *8  */
#define SD24GAIN_16         (0x0020)  /* SD24B Input Pre-Amplifier Gain Select *16 */
#define SD24GAIN_32         (0x0028)  /* SD24B Input Pre-Amplifier Gain Select *32 */
#define SD24GAIN_64         (0x0030)  /* SD24B Input Pre-Amplifier Gain Select *64 */
#define SD24GAIN_128        (0x0038)  /* SD24B Input Pre-Amplifier Gain Select *128 */

#define SD24INTDLY_0        (0x0000)  /* SD24B Interrupt Delay: Int. after 4.Conversion  */
#define SD24INTDLY_1        (0x0040)  /* SD24B Interrupt Delay: Int. after 3.Conversion  */
#define SD24INTDLY_2        (0x0080)  /* SD24B Interrupt Delay: Int. after 2.Conversion  */
#define SD24INTDLY_3        (0x00C0)  /* SD24B Interrupt Delay: Int. after 1.Conversion  */

/* SD24BOSRx */
#define OSR0               (0x0001)  /* SD24B Oversampling Rate Bit: 0 */
#define OSR1               (0x0002)  /* SD24B Oversampling Rate Bit: 1 */
#define OSR2               (0x0004)  /* SD24B Oversampling Rate Bit: 2 */
#define OSR3               (0x0008)  /* SD24B Oversampling Rate Bit: 3 */
#define OSR4               (0x0010)  /* SD24B Oversampling Rate Bit: 4 */
#define OSR5               (0x0020)  /* SD24B Oversampling Rate Bit: 5 */
#define OSR6               (0x0040)  /* SD24B Oversampling Rate Bit: 6 */
#define OSR7               (0x0080)  /* SD24B Oversampling Rate Bit: 7 */
#define OSR8               (0x0100)  /* SD24B Oversampling Rate Bit: 8 */
#define OSR9               (0x0200)  /* SD24B Oversampling Rate Bit: 9 */
#define OSR10               (0x0400)  /* SD24B Oversampling Rate Bit: 10 */

#define OSR0_L              (0x0001)  /* SD24B Oversampling Rate Bit: 0 */
#define OSR1_L              (0x0002)  /* SD24B Oversampling Rate Bit: 1 */
#define OSR2_L              (0x0004)  /* SD24B Oversampling Rate Bit: 2 */
#define OSR3_L              (0x0008)  /* SD24B Oversampling Rate Bit: 3 */
#define OSR4_L              (0x0010)  /* SD24B Oversampling Rate Bit: 4 */
#define OSR5_L              (0x0020)  /* SD24B Oversampling Rate Bit: 5 */
#define OSR6_L              (0x0040)  /* SD24B Oversampling Rate Bit: 6 */
#define OSR7_L              (0x0080)  /* SD24B Oversampling Rate Bit: 7 */

#define OSR8_H              (0x0001)  /* SD24B Oversampling Rate Bit: 8 */
#define OSR9_H              (0x0002)  /* SD24B Oversampling Rate Bit: 9 */
#define OSR10_H             (0x0004)  /* SD24B Oversampling Rate Bit: 10 */

/* SD24BTRGOSR */



#define OSR__32             (32-1)    /* SD24B Oversampling Rate: 32 */
#define OSR__64             (64-1)    /* SD24B Oversampling Rate: 64 */
#define OSR__128            (128-1)   /* SD24B Oversampling Rate: 128 */
#define OSR__256            (256-1)   /* SD24B Oversampling Rate: 256 */
#define OSR__512            (512-1)   /* SD24B Oversampling Rate: 512 */
#define OSR__1024           (1024-1)  /* SD24B Oversampling Rate: 1024 */


#endif
/************************************************************
* SFR - Special Function Register Module
************************************************************/
#ifdef  __MSP430_HAS_SFR__            /* Definition to show that Module is available */

#define OFS_SFRIE1            (0x0000)  /* Interrupt Enable 1 */
#define OFS_SFRIE1_L           OFS_SFRIE1
#define OFS_SFRIE1_H           OFS_SFRIE1+1

/* SFRIE1 Control Bits */
#define WDTIE               (0x0001)  /* WDT Interrupt Enable */
#define OFIE                (0x0002)  /* Osc Fault Enable */
//#define Reserved          (0x0004)
#define VMAIE               (0x0008)  /* Vacant Memory Interrupt Enable */
#define NMIIE               (0x0010)  /* NMI Interrupt Enable */
#ifndef ACCVIE
#define ACCVIE              (0x0020)  /* Flash Access Violation Interrupt Enable */
#endif
#define JMBINIE             (0x0040)  /* JTAG Mail Box input Interrupt Enable */
#define JMBOUTIE            (0x0080)  /* JTAG Mail Box output Interrupt Enable */

#define WDTIE_L             (0x0001)  /* WDT Interrupt Enable */
#define OFIE_L              (0x0002)  /* Osc Fault Enable */
//#define Reserved          (0x0004)
#define VMAIE_L             (0x0008)  /* Vacant Memory Interrupt Enable */
#define NMIIE_L             (0x0010)  /* NMI Interrupt Enable */
#ifndef ACCVIE
#define ACCVIE_L            (0x0020)  /* Flash Access Violation Interrupt Enable */
#endif
#define JMBINIE_L           (0x0040)  /* JTAG Mail Box input Interrupt Enable */
#define JMBOUTIE_L          (0x0080)  /* JTAG Mail Box output Interrupt Enable */


#define OFS_SFRIFG1           (0x0002)  /* Interrupt Flag 1 */
#define OFS_SFRIFG1_L          OFS_SFRIFG1
#define OFS_SFRIFG1_H          OFS_SFRIFG1+1
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


#define OFS_SFRRPCR           (0x0004)  /* RESET Pin Control Register */
#define OFS_SFRRPCR_L          OFS_SFRRPCR
#define OFS_SFRRPCR_H          OFS_SFRRPCR+1
/* SFRRPCR Control Bits */
#define SYSNMI              (0x0001)  /* NMI select */
#define SYSNMIIES           (0x0002)  /* NMI edge select */
#define SYSRSTUP            (0x0004)  /* RESET Pin pull down/up select */
#define SYSRSTRE            (0x0008)  /* RESET Pin Resistor enable */

#define SYSNMI_L            (0x0001)  /* NMI select */
#define SYSNMIIES_L         (0x0002)  /* NMI edge select */
#define SYSRSTUP_L          (0x0004)  /* RESET Pin pull down/up select */
#define SYSRSTRE_L          (0x0008)  /* RESET Pin Resistor enable */


#endif
/************************************************************
* SYS - System Module
************************************************************/
#ifdef  __MSP430_HAS_SYS__            /* Definition to show that Module is available */

#define OFS_SYSCTL            (0x0000)  /* System control */
#define OFS_SYSCTL_L           OFS_SYSCTL
#define OFS_SYSCTL_H           OFS_SYSCTL+1
#define OFS_SYSBSLC           (0x0002)  /* Boot strap configuration area */
#define OFS_SYSBSLC_L          OFS_SYSBSLC
#define OFS_SYSBSLC_H          OFS_SYSBSLC+1
#define OFS_SYSJMBC           (0x0006)  /* JTAG mailbox control */
#define OFS_SYSJMBC_L          OFS_SYSJMBC
#define OFS_SYSJMBC_H          OFS_SYSJMBC+1
#define OFS_SYSJMBI0          (0x0008)  /* JTAG mailbox input 0 */
#define OFS_SYSJMBI0_L         OFS_SYSJMBI0
#define OFS_SYSJMBI0_H         OFS_SYSJMBI0+1
#define OFS_SYSJMBI1          (0x000A)  /* JTAG mailbox input 1 */
#define OFS_SYSJMBI1_L         OFS_SYSJMBI1
#define OFS_SYSJMBI1_H         OFS_SYSJMBI1+1
#define OFS_SYSJMBO0          (0x000C)  /* JTAG mailbox output 0 */
#define OFS_SYSJMBO0_L         OFS_SYSJMBO0
#define OFS_SYSJMBO0_H         OFS_SYSJMBO0+1
#define OFS_SYSJMBO1          (0x000E)  /* JTAG mailbox output 1 */
#define OFS_SYSJMBO1_L         OFS_SYSJMBO1
#define OFS_SYSJMBO1_H         OFS_SYSJMBO1+1

#define OFS_SYSBERRIV         (0x0018)  /* Bus Error vector generator */
#define OFS_SYSBERRIV_L        OFS_SYSBERRIV
#define OFS_SYSBERRIV_H        OFS_SYSBERRIV+1
#define OFS_SYSUNIV           (0x001A)  /* User NMI vector generator */
#define OFS_SYSUNIV_L          OFS_SYSUNIV
#define OFS_SYSUNIV_H          OFS_SYSUNIV+1
#define OFS_SYSSNIV           (0x001C)  /* System NMI vector generator */
#define OFS_SYSSNIV_L          OFS_SYSSNIV
#define OFS_SYSSNIV_H          OFS_SYSSNIV+1
#define OFS_SYSRSTIV          (0x001E)  /* Reset vector generator */
#define OFS_SYSRSTIV_L         OFS_SYSRSTIV
#define OFS_SYSRSTIV_H         OFS_SYSRSTIV+1

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







#endif
/************************************************************
* Timerx_A7
************************************************************/
#ifdef  __MSP430_HAS_TxA7__            /* Definition to show that Module is available */

#define OFS_TAxCTL            (0x0000)  /* Timerx_A7 Control */
#define OFS_TAxCCTL0          (0x0002)  /* Timerx_A7 Capture/Compare Control 0 */
#define OFS_TAxCCTL1          (0x0004)  /* Timerx_A7 Capture/Compare Control 1 */
#define OFS_TAxCCTL2          (0x0006)  /* Timerx_A7 Capture/Compare Control 2 */
#define OFS_TAxCCTL3          (0x0008)  /* Timerx_A7 Capture/Compare Control 3 */
#define OFS_TAxCCTL4          (0x000A)  /* Timerx_A7 Capture/Compare Control 4 */
#define OFS_TAxCCTL5          (0x000C)  /* Timerx_A7 Capture/Compare Control 5 */
#define OFS_TAxCCTL6          (0x000E)  /* Timerx_A7 Capture/Compare Control 6 */
#define OFS_TAxR              (0x0010)  /* Timerx_A7 */
#define OFS_TAxCCR0           (0x0012)  /* Timerx_A7 Capture/Compare 0 */
#define OFS_TAxCCR1           (0x0014)  /* Timerx_A7 Capture/Compare 1 */
#define OFS_TAxCCR2           (0x0016)  /* Timerx_A7 Capture/Compare 2 */
#define OFS_TAxCCR3           (0x0018)  /* Timerx_A7 Capture/Compare 3 */
#define OFS_TAxCCR4           (0x001A)  /* Timerx_A7 Capture/Compare 4 */
#define OFS_TAxCCR5           (0x001C)  /* Timerx_A7 Capture/Compare 5 */
#define OFS_TAxCCR6           (0x001E)  /* Timerx_A7 Capture/Compare 6 */
#define OFS_TAxIV             (0x002E)  /* Timerx_A7 Interrupt Vector Word */
#define OFS_TAxEX0            (0x0020)  /* Timerx_A7 Expansion Register 0 */

/* Bits are already defined within the Timer0_Ax */

/* TAxIV Definitions */
#define TAxIV_NONE          (0x0000)    /* No Interrupt pending */
#define TAxIV_TACCR1        (0x0002)    /* TAxCCR1_CCIFG */
#define TAxIV_TACCR2        (0x0004)    /* TAxCCR2_CCIFG */
#define TAxIV_TACCR3        (0x0006)    /* TAxCCR3_CCIFG */
#define TAxIV_TACCR4        (0x0008)    /* TAxCCR4_CCIFG */
#define TAxIV_TACCR5        (0x000A)    /* TAxCCR5_CCIFG */
#define TAxIV_TACCR6        (0x000C)    /* TAxCCR6_CCIFG */
#define TAxIV_TAIFG         (0x000E)    /* TAxIFG */

/* Legacy Defines */
#define TAxIV_TAxCCR1      (0x0002)    /* TAxCCR1_CCIFG */
#define TAxIV_TAxCCR2      (0x0004)    /* TAxCCR2_CCIFG */
#define TAxIV_TAxCCR3      (0x0006)    /* TAxCCR3_CCIFG */
#define TAxIV_TAxCCR4      (0x0008)    /* TAxCCR4_CCIFG */
#define TAxIV_TAxCCR5      (0x000A)    /* TAxCCR5_CCIFG */
#define TAxIV_TAxCCR6      (0x000C)    /* TAxCCR6_CCIFG */
#define TAxIV_TAxIFG       (0x000E)    /* TAxIFG */

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

#endif
/************************************************************
* Timerx_B7
************************************************************/
#ifdef  __MSP430_HAS_TxB7__            /* Definition to show that Module is available */

#define OFS_TBxCTL            (0x0000)  /* Timerx_B7 Control */
#define OFS_TBxCCTL0          (0x0002)  /* Timerx_B7 Capture/Compare Control 0 */
#define OFS_TBxCCTL1          (0x0004)  /* Timerx_B7 Capture/Compare Control 1 */
#define OFS_TBxCCTL2          (0x0006)  /* Timerx_B7 Capture/Compare Control 2 */
#define OFS_TBxCCTL3          (0x0008)  /* Timerx_B7 Capture/Compare Control 3 */
#define OFS_TBxCCTL4          (0x000A)  /* Timerx_B7 Capture/Compare Control 4 */
#define OFS_TBxCCTL5          (0x000C)  /* Timerx_B7 Capture/Compare Control 5 */
#define OFS_TBxCCTL6          (0x000E)  /* Timerx_B7 Capture/Compare Control 6 */
#define OFS_TBxR              (0x0010)  /* Timerx_B7 */
#define OFS_TBxCCR0           (0x0012)  /* Timerx_B7 Capture/Compare 0 */
#define OFS_TBxCCR1           (0x0014)  /* Timerx_B7 Capture/Compare 1 */
#define OFS_TBxCCR2           (0x0016)  /* Timerx_B7 Capture/Compare 2 */
#define OFS_TBxCCR3           (0x0018)  /* Timerx_B7 Capture/Compare 3 */
#define OFS_TBxCCR4           (0x001A)  /* Timerx_B7 Capture/Compare 4 */
#define OFS_TBxCCR5           (0x001C)  /* Timerx_B7 Capture/Compare 5 */
#define OFS_TBxCCR6           (0x001E)  /* Timerx_B7 Capture/Compare 6 */
#define OFS_TBxIV             (0x002E)  /* Timerx_B7 Interrupt Vector Word */
#define OFS_TBxEX0            (0x0020)  /* Timerx_B7 Expansion Register 0 */

/* Bits are already defined within the Timer0_Ax */

/* TBxIV Definitions */
#define TBxIV_NONE           (0x0000)    /* No Interrupt pending */
#define TBxIV_TBCCR1         (0x0002)    /* TBxCCR1_CCIFG */
#define TBxIV_TBCCR2         (0x0004)    /* TBxCCR2_CCIFG */
#define TBxIV_TBCCR3         (0x0006)    /* TBxCCR3_CCIFG */
#define TBxIV_TBCCR4         (0x0008)    /* TBxCCR4_CCIFG */
#define TBxIV_TBCCR5         (0x000A)    /* TBxCCR5_CCIFG */
#define TBxIV_TBCCR6         (0x000C)    /* TBxCCR6_CCIFG */
#define TBxIV_TBIFG          (0x000E)    /* TBxIFG */

/* Legacy Defines */
#define TBxIV_TBxCCR1       (0x0002)    /* TBxCCR1_CCIFG */
#define TBxIV_TBxCCR2       (0x0004)    /* TBxCCR2_CCIFG */
#define TBxIV_TBxCCR3       (0x0006)    /* TBxCCR3_CCIFG */
#define TBxIV_TBxCCR4       (0x0008)    /* TBxCCR4_CCIFG */
#define TBxIV_TBxCCR5       (0x000A)    /* TBxCCR5_CCIFG */
#define TBxIV_TBxCCR6       (0x000C)    /* TBxCCR6_CCIFG */
#define TBxIV_TBxIFG        (0x000E)    /* TBxIFG */

/* TBxCTL Control Bits */
#define TBCLGRP1            (0x4000)    /* Timer_B7 Compare latch load group 1 */
#define TBCLGRP0            (0x2000)    /* Timer_B7 Compare latch load group 0 */
#define CNTL1               (0x1000)    /* Counter lenght 1 */
#define CNTL0               (0x0800)    /* Counter lenght 0 */
#define TBSSEL1             (0x0200)    /* Clock source 1 */
#define TBSSEL0             (0x0100)    /* Clock source 0 */
#define TBCLR               (0x0004)    /* Timer_B7 counter clear */
#define TBIE                (0x0002)    /* Timer_B7 interrupt enable */
#define TBIFG               (0x0001)    /* Timer_B7 interrupt flag */

#define SHR1                (0x4000)    /* Timer_B7 Compare latch load group 1 */
#define SHR0                (0x2000)    /* Timer_B7 Compare latch load group 0 */

#define TBSSEL_0            (0x0000)  /* Clock Source: TBCLK */
#define TBSSEL_1            (0x0100)  /* Clock Source: ACLK  */
#define TBSSEL_2            (0x0200)  /* Clock Source: SMCLK */
#define TBSSEL_3            (0x0300)  /* Clock Source: INCLK */
#define CNTL_0              (0x0000)  /* Counter lenght: 16 bit */
#define CNTL_1              (0x0800)  /* Counter lenght: 12 bit */
#define CNTL_2              (0x1000)  /* Counter lenght: 10 bit */
#define CNTL_3              (0x1800)  /* Counter lenght:  8 bit */
#define SHR_0               (0x0000)  /* Timer_B7 Group: 0 - individually */
#define SHR_1               (0x2000)  /* Timer_B7 Group: 1 - 3 groups (1-2, 3-4, 5-6) */
#define SHR_2               (0x4000)  /* Timer_B7 Group: 2 - 2 groups (1-3, 4-6)*/
#define SHR_3               (0x6000)  /* Timer_B7 Group: 3 - 1 group (all) */
#define TBCLGRP_0           (0x0000)  /* Timer_B7 Group: 0 - individually */
#define TBCLGRP_1           (0x2000)  /* Timer_B7 Group: 1 - 3 groups (1-2, 3-4, 5-6) */
#define TBCLGRP_2           (0x4000)  /* Timer_B7 Group: 2 - 2 groups (1-3, 4-6)*/
#define TBCLGRP_3           (0x6000)  /* Timer_B7 Group: 3 - 1 group (all) */
#define TBSSEL__TBCLK       (0x0000) /* Timer0_B7 clock source select: 0 - TBCLK */
#define TBSSEL__TACLK       (0x0000) /* Timer0_B7 clock source select: 0 - TBCLK (legacy) */
#define TBSSEL__ACLK        (0x0100)  /* Timer_B7 clock source select: 1 - ACLK  */
#define TBSSEL__SMCLK       (0x0200)  /* Timer_B7 clock source select: 2 - SMCLK */
#define TBSSEL__INCLK       (0x0300)  /* Timer_B7 clock source select: 3 - INCLK */
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
#define TBIDEX0             (0x0001)   /* Timer_B7 Input divider expansion Bit: 0 */
#define TBIDEX1             (0x0002)   /* Timer_B7 Input divider expansion Bit: 1 */
#define TBIDEX2             (0x0004)   /* Timer_B7 Input divider expansion Bit: 2 */

#define TBIDEX_0            (0x0000) /* Timer_B7 Input divider expansion : /1 */
#define TBIDEX_1            (0x0001) /* Timer_B7 Input divider expansion : /2 */
#define TBIDEX_2            (0x0002) /* Timer_B7 Input divider expansion : /3 */
#define TBIDEX_3            (0x0003) /* Timer_B7 Input divider expansion : /4 */
#define TBIDEX_4            (0x0004) /* Timer_B7 Input divider expansion : /5 */
#define TBIDEX_5            (0x0005) /* Timer_B7 Input divider expansion : /6 */
#define TBIDEX_6            (0x0006) /* Timer_B7 Input divider expansion : /7 */
#define TBIDEX_7            (0x0007) /* Timer_B7 Input divider expansion : /8 */
#define TBIDEX__1           (0x0000) /* Timer_B7 Input divider expansion : /1 */
#define TBIDEX__2           (0x0001) /* Timer_B7 Input divider expansion : /2 */
#define TBIDEX__3           (0x0002) /* Timer_B7 Input divider expansion : /3 */
#define TBIDEX__4           (0x0003) /* Timer_B7 Input divider expansion : /4 */
#define TBIDEX__5           (0x0004) /* Timer_B7 Input divider expansion : /5 */
#define TBIDEX__6           (0x0005) /* Timer_B7 Input divider expansion : /6 */
#define TBIDEX__7           (0x0006) /* Timer_B7 Input divider expansion : /7 */
#define TBIDEX__8           (0x0007) /* Timer_B7 Input divider expansion : /8 */


#define ID1                    (0x0080)       /* Timer B clock input divider 1 */
#define ID0                    (0x0040)       /* Timer B clock input divider 0 */
#define MC1                    (0x0020)       /* Timer B mode control 1 */
#define MC0                    (0x0010)       /* Timer B mode control 0 */
#define MC__STOP               (0*0x10u)      /* Timer B mode control: 0 - Stop */
#define MC__UP                 (1*0x10u)      /* Timer B mode control: 1 - Up to CCR0 */
#define MC__CONTINUOUS         (2*0x10u)      /* Timer B mode control: 2 - Continuous up */
#define MC__CONTINOUS          (2*0x10u)      /* Legacy define */
#define MC__UPDOWN             (3*0x10u)      /* Timer B mode control: 3 - Up/Down */
#define CM1                    (0x8000)       /* Capture mode 1 */
#define CM0                    (0x4000)       /* Capture mode 0 */
#define MC_0                   (0*0x10u)      /* Timer B mode control: 0 - Stop */
#define MC_1                   (1*0x10u)      /* Timer B mode control: 1 - Up to CCR0 */
#define MC_2                   (2*0x10u)      /* Timer B mode control: 2 - Continuous up */
#define MC_3                   (3*0x10u)      /* Timer B mode control: 3 - Up/Down */
#define CAP                    (0x0100)       /* Capture mode: 1 /Compare mode : 0 */
#define CCIE                   (0x0010)       /* Capture/compare interrupt enable */
#define CCIFG                  (0x0001)       /* Capture/compare interrupt flag */
#define CCIS_0                 (0*0x1000u)
#define CCIS_1                 (1*0x1000u)
#define CCIS_2                 (2*0x1000u)
#define CCIS_3                 (3*0x1000u)
#define CM_0                   (0*0x4000u)    /* Capture mode: 0 - disabled */
#define CM_1                   (1*0x4000u)    /* Capture mode: 1 - pos. edge */
#define CM_2                   (2*0x4000u)    /* Capture mode: 1 - neg. edge */
#define CM_3                   (3*0x4000u)    /* Capture mode: 1 - both edges */
#define OUT                    (0x0004)       /* PWM Output signal if output mode 0 */
#define OUTMOD_0               (0*0x20u)      /* PWM output mode: 0 - output only */
#define OUTMOD_1               (1*0x20u)      /* PWM output mode: 1 - set */
#define OUTMOD_2               (2*0x20u)      /* PWM output mode: 2 - PWM toggle/reset */
#define OUTMOD_3               (3*0x20u)      /* PWM output mode: 3 - PWM set/reset */
#define OUTMOD_4               (4*0x20u)      /* PWM output mode: 4 - toggle */
#define OUTMOD_5               (5*0x20u)      /* PWM output mode: 5 - Reset */
#define OUTMOD_6               (6*0x20u)      /* PWM output mode: 6 - PWM toggle/set */
#define OUTMOD_7               (7*0x20u)      /* PWM output mode: 7 - PWM reset/set */
#define SCCI                   (0x0400)       /* Latched capture signal (read) */
#define SCS                    (0x0800)       /* Capture sychronize */
#define CCI                    (0x0008)       /* Capture input signal (read) */
#define ID__1                  (0*0x40u)      /* Timer B input divider: 0 - /1 */
#define ID__2                  (1*0x40u)      /* Timer B input divider: 1 - /2 */
#define ID__4                  (2*0x40u)      /* Timer B input divider: 2 - /4 */
#define ID__8                  (3*0x40u)      /* Timer B input divider: 3 - /8 */
#define ID_0                   (0*0x40u)      /* Timer B input divider: 0 - /1 */
#define ID_1                   (1*0x40u)      /* Timer B input divider: 1 - /2 */
#define ID_2                   (2*0x40u)      /* Timer B input divider: 2 - /4 */
#define ID_3                   (3*0x40u)      /* Timer B input divider: 3 - /8 */

#endif
/************************************************************
* Timerx_D7
************************************************************/
#ifdef  __MSP430_HAS_TxD7__            /* Definition to show that Module is available */

#define OFS_TDxCTL0           (0x0000)  /* Timerx_D7 Control 0 */
#define OFS_TDxCTL1           (0x0002)  /* Timerx_D7 Control 1 */
#define OFS_TDxCTL2           (0x0004)  /* Timerx_D7 Control 2 */
#define OFS_TDxR              (0x0006)  /* Timerx_D7 Counter */
#define OFS_TDxCCTL0          (0x0008)  /* Timerx_D7 Capture/Compare Control 0 */
#define OFS_TDxCCR0           (0x000A)  /* Timerx_D7 Capture/Compare 0 */
#define OFS_TDxCL0            (0x000C)  /* Timerx_D7 Capture/Compare Latch 0 */
#define OFS_TDxCCTL1          (0x000E)  /* Timerx_D7 Capture/Compare Control 1 */
#define OFS_TDxCCR1           (0x0010)  /* Timerx_D7 Capture/Compare 1 */
#define OFS_TDxCL1            (0x0012)  /* Timerx_D7 Capture/Compare Latch 1 */
#define OFS_TDxCCTL2          (0x0014)  /* Timerx_D7 Capture/Compare Control 2 */
#define OFS_TDxCCR2           (0x0016)  /* Timerx_D7 Capture/Compare 2 */
#define OFS_TDxCL2            (0x0018)  /* Timerx_D7 Capture/Compare Latch 2 */
#define OFS_TDxCCTL3          (0x001A)  /* Timerx_D7 Capture/Compare Control 3 */
#define OFS_TDxCCR3           (0x001C)  /* Timerx_D7 Capture/Compare 3 */
#define OFS_TDxCL3            (0x001E)  /* Timerx_D7 Capture/Compare Latch 3 */
#define OFS_TDxCCTL4          (0x0020)  /* Timerx_D7 Capture/Compare Control 4 */
#define OFS_TDxCCR4           (0x0022)  /* Timerx_D7 Capture/Compare 4 */
#define OFS_TDxCL4            (0x0024)  /* Timerx_D7 Capture/Compare Latch 4 */
#define OFS_TDxCCTL5          (0x0026)  /* Timerx_D7 Capture/Compare Control 5 */
#define OFS_TDxCCR5           (0x0028)  /* Timerx_D7 Capture/Compare 5 */
#define OFS_TDxCL5            (0x002A)  /* Timerx_D7 Capture/Compare Latch 5 */
#define OFS_TDxCCTL6          (0x002C)  /* Timerx_D7 Capture/Compare Control 6 */
#define OFS_TDxCCR6           (0x002E)  /* Timerx_D7 Capture/Compare 6 */
#define OFS_TDxCL6            (0x0030)  /* Timerx_D7 Capture/Compare Latch 6 */
#define OFS_TDxHCTL0          (0x0038)  /* Timerx_D7 High-resolution Control Register 0 */
#define OFS_TDxHCTL1          (0x003A)  /* Timerx_D7 High-resolution Control Register 1 */
#define OFS_TDxHINT           (0x003C)  /* Timerx_D7 High-resolution Interrupt Register */
#define OFS_TDxIV             (0x003E)  /* Timerx_D7 Interrupt Vector Word */

/* Bits are already defined within the Timer0_Dx */

/* TDxIV Definitions */
#define TDxIV_NONE           (0x0000)    /* No Interrupt pending */
#define TDxIV_TDCCR1         (0x0002)    /* TDxCCR1_CCIFG */
#define TDxIV_TDCCR2         (0x0004)    /* TDxCCR2_CCIFG */
#define TDxIV_TDCCR3         (0x0006)    /* TDxCCR3_CCIFG */
#define TDxIV_TDCCR4         (0x0008)    /* TDxCCR4_CCIFG */
#define TDxIV_TDCCR5         (0x000A)    /* TDxCCR5_CCIFG */
#define TDxIV_TDCCR6         (0x000C)    /* TDxCCR6_CCIFG */
#define TDxIV_RES_14         (0x000E)    /* Reserverd */
#define TDxIV_TDIFG          (0x0010)    /* TDxIFG */
#define TDxIV_TDHFLIFG       (0x0012)    /* TDHFLIFG Clock fail low */
#define TDxIV_TDHFHIFG       (0x0014)    /* TDHFLIFG Clock fail high */
#define TDxIV_TDHLKIFG       (0x0016)    /* TDHLKIE Clock lock*/
#define TDxIV_TDHUNLKIFG     (0x0018)    /* TDHUNLKIE Clock unlock */

/* Legacy Defines */
#define TDxIV_TDxCCR1       (0x0002)    /* TDxCCR1_CCIFG */
#define TDxIV_TDxCCR2       (0x0004)    /* TDxCCR2_CCIFG */
#define TDxIV_TDxCCR3       (0x0006)    /* TDxCCR3_CCIFG */
#define TDxIV_TDxCCR4       (0x0008)    /* TDxCCR4_CCIFG */
#define TDxIV_TDxCCR5       (0x000A)    /* TDxCCR5_CCIFG */
#define TDxIV_TDxCCR6       (0x000C)    /* TDxCCR6_CCIFG */
#define TDxIV_TDxIFG        (0x0010)    /* TDxIFG */

/* TDxCTL0 Control Bits */
#define TDCLGRP1            (0x4000)  /* Timer_D7 Compare latch load group 1 */
#define TDCLGRP0            (0x2000)  /* Timer_D7 Compare latch load group 0 */
#define CNTL1               (0x1000)  /* Counter lenght 1 */
#define CNTL0               (0x0800)  /* Counter lenght 0 */
#define TDSSEL1             (0x0200)  /* Clock source 1 */
#define TDSSEL0             (0x0100)  /* Clock source 0 */
#define TDCLR               (0x0004)  /* Timer_D7 counter clear */
#define TDIE                (0x0002)  /* Timer_D7 interrupt enable */
#define TDIFG               (0x0001)  /* Timer_D7 interrupt flag */

#define SHR1                (0x4000)  /* Timer_D7 Compare latch load group 1 */
#define SHR0                (0x2000)  /* Timer_D7 Compare latch load group 0 */

#define TDSSEL_0            (0x0000)  /* Clock Source: TDCLK */
#define TDSSEL_1            (0x0100)  /* Clock Source: ACLK  */
#define TDSSEL_2            (0x0200)  /* Clock Source: SMCLK */
#define TDSSEL_3            (0x0300)  /* Clock Source: INCLK */
#define CNTL_0              (0x0000)  /* Counter lenght: 16 bit */
#define CNTL_1              (0x0800)  /* Counter lenght: 12 bit */
#define CNTL_2              (0x1000)  /* Counter lenght: 10 bit */
#define CNTL_3              (0x1800)  /* Counter lenght:  8 bit */
#define SHR_0               (0x0000)  /* Timer_D7 Group: 0 - individually */
#define SHR_1               (0x2000)  /* Timer_D7 Group: 1 - 3 groups (1-2, 3-4, 5-6) */
#define SHR_2               (0x4000)  /* Timer_D7 Group: 2 - 2 groups (1-3, 4-6)*/
#define SHR_3               (0x6000)  /* Timer_D7 Group: 3 - 1 group (all) */
#define TDCLGRP_0           (0x0000)  /* Timer_D7 Group: 0 - individually */
#define TDCLGRP_1           (0x2000)  /* Timer_D7 Group: 1 - 3 groups (1-2, 3-4, 5-6) */
#define TDCLGRP_2           (0x4000)  /* Timer_D7 Group: 2 - 2 groups (1-3, 4-6)*/
#define TDCLGRP_3           (0x6000)  /* Timer_D7 Group: 3 - 1 group (all) */
#define TDSSEL__TACLK       (0x0000)  /* Timer_D7 clock source select: 0 - TACLK */
#define TDSSEL__ACLK        (0x0100)  /* Timer_D7 clock source select: 1 - ACLK  */
#define TDSSEL__SMCLK       (0x0200)  /* Timer_D7 clock source select: 2 - SMCLK */
#define TDSSEL__INCLK       (0x0300)  /* Timer_D7 clock source select: 3 - INCLK */
#define CNTL__16            (0x0000)  /* Counter lenght: 16 bit */
#define CNTL__12            (0x0800)  /* Counter lenght: 12 bit */
#define CNTL__10            (0x1000)  /* Counter lenght: 10 bit */
#define CNTL__8             (0x1800)  /* Counter lenght:  8 bit */

/* Additional Timer B Control Register bits are defined in Timer A */

/* TDxCTL1 Control Bits */
#define TDCLKM0             (0x0001)   /* Timer_D7 Clocking Mode Bit: 0 */
#define TDCLKM1             (0x0002)   /* Timer_D7 Clocking Mode Bit: 1 */
#define TD2CMB              (0x0010)   /* Timer_D7 TD0CCR Combination in TD2 */
#define TD4CMB              (0x0020)   /* Timer_D7 TD0CCR Combination in TD4 */
#define TD6CMB              (0x0040)   /* Timer_D7 TD0CCR Combination in TD6 */
#define TDIDEX0             (0x0100)   /* Timer_D7 Input divider expansion Bit: 0 */
#define TDIDEX1             (0x0200)   /* Timer_D7 Input divider expansion Bit: 1 */
#define TDIDEX2             (0x0400)   /* Timer_D7 Input divider expansion Bit: 2 */

#define TDCLKM_0            (0x0000)   /* Timer_D7 Clocking Mode: External */
#define TDCLKM_1            (0x0001)   /* Timer_D7 Clocking Mode: High-Res. local clock */
#define TDCLKM_2            (0x0002)   /* Timer_D7 Clocking Mode: Aux Clock */
#define TDCLKM__EXT         (0x0000)   /* Timer_D7 Clocking Mode: External */
#define TDCLKM__HIGHRES     (0x0001)   /* Timer_D7 Clocking Mode: High-Res. local clock */
#define TDCLKM__AUX         (0x0002)   /* Timer_D7 Clocking Mode: Aux Clock */

#define TDIDEX_0            (0x0000) /* Timer0_D3 Input divider expansion : /1 */
#define TDIDEX_1            (0x0100) /* Timer0_D3 Input divider expansion : /2 */
#define TDIDEX_2            (0x0200) /* Timer0_D3 Input divider expansion : /3 */
#define TDIDEX_3            (0x0300) /* Timer0_D3 Input divider expansion : /4 */
#define TDIDEX_4            (0x0400) /* Timer0_D3 Input divider expansion : /5 */
#define TDIDEX_5            (0x0500) /* Timer0_D3 Input divider expansion : /6 */
#define TDIDEX_6            (0x0600) /* Timer0_D3 Input divider expansion : /7 */
#define TDIDEX_7            (0x0700) /* Timer0_D3 Input divider expansion : /8 */
#define TDIDEX__1           (0x0000) /* Timer0_D3 Input divider expansion : /1 */
#define TDIDEX__2           (0x0100) /* Timer0_D3 Input divider expansion : /2 */
#define TDIDEX__3           (0x0200) /* Timer0_D3 Input divider expansion : /3 */
#define TDIDEX__4           (0x0300) /* Timer0_D3 Input divider expansion : /4 */
#define TDIDEX__5           (0x0400) /* Timer0_D3 Input divider expansion : /5 */
#define TDIDEX__6           (0x0500) /* Timer0_D3 Input divider expansion : /6 */
#define TDIDEX__7           (0x0600) /* Timer0_D3 Input divider expansion : /7 */
#define TDIDEX__8           (0x0700) /* Timer0_D3 Input divider expansion : /8 */

/* TDxCTL2 Control Bits */
#define TDCAPM0             (0x0001)   /* Timer_D7 Capture Mode of Channel 0 */
#define TDCAPM1             (0x0002)   /* Timer_D7 Capture Mode of Channel 1 */
#define TDCAPM2             (0x0004)   /* Timer_D7 Capture Mode of Channel 2 */
#define TDCAPM3             (0x0008)   /* Timer_D7 Capture Mode of Channel 3 */
#define TDCAPM4             (0x0010)   /* Timer_D7 Capture Mode of Channel 4 */
#define TDCAPM5             (0x0020)   /* Timer_D7 Capture Mode of Channel 5 */
#define TDCAPM6             (0x0040)   /* Timer_D7 Capture Mode of Channel 6 */

/* TDxCCTLx Control Bits */
#define CLLD1               (0x0400)  /* Compare latch load source 1 */
#define CLLD0               (0x0200)  /* Compare latch load source 0 */

#define SLSHR1              (0x0400)  /* Compare latch load source 1 */
#define SLSHR0              (0x0200)  /* Compare latch load source 0 */

#define SLSHR_0             (0x0000) /* Compare latch load sourec : 0 - immediate */
#define SLSHR_1             (0x0200) /* Compare latch load sourec : 1 - TDR counts to 0 */
#define SLSHR_2             (0x0400) /* Compare latch load sourec : 2 - up/down */
#define SLSHR_3             (0x0600) /* Compare latch load sourec : 3 - TDR counts to TDCTL0 */

#define CLLD_0              (0x0000) /* Compare latch load sourec : 0 - immediate */
#define CLLD_1              (0x0200) /* Compare latch load sourec : 1 - TDR counts to 0 */
#define CLLD_2              (0x0400) /* Compare latch load sourec : 2 - up/down */
#define CLLD_3              (0x0600) /* Compare latch load sourec : 3 - TDR counts to TDCTL0 */

/* TDxHCTL0 Control Bits */
#define TDHEN               (0x0001)   /* Timer_D7 High-Resolution Enable */
#define TDHREGEN            (0x0002)   /* Timer_D7 High-Resolution Regulatied Mode */
#define TDHEAEN             (0x0004)   /* Timer_D7 High-Resolution clock error accum. enable */
#define TDHRON              (0x0008)   /* Timer_D7 High-Resolution Generator forced on*/
#define TDHM0               (0x0010)   /* Timer_D7 High-Resoltuion Clock Mult. Bit: 0 */
#define TDHM1               (0x0020)   /* Timer_D7 High-Resoltuion Clock Mult. Bit: 1 */
#define TDHD0               (0x0040)   /* Timer_D7 High-Resolution clock divider Bit: 0 */
#define TDHD1               (0x0080)   /* Timer_D7 High-Resolution clock divider Bit: 1 */
#define TDHFW               (0x0100)   /* Timer_D7 High-resolution generator fast wakeup enable */

#define TDHCALEN            TDHREGEN   /* Timer_D7 Lagacy Definition */

#define TDHM_0              (0x0000)   /* Timer_D7 High-Resoltuion Clock Mult.: 8x TimerD clock */
#define TDHM_1              (0x0010)   /* Timer_D7 High-Resoltuion Clock Mult.: 16x TimerD clock */
#define TDHM__8             (0x0000)   /* Timer_D7 High-Resoltuion Clock Mult.: 8x TimerD clock */
#define TDHM__16            (0x0010)   /* Timer_D7 High-Resoltuion Clock Mult.: 16x TimerD clock */
#define TDHD_0              (0x0000)   /* Timer_D7 High-Resolution clock divider: /1 */
#define TDHD_1              (0x0040)   /* Timer_D7 High-Resolution clock divider: /2 */
#define TDHD_2              (0x0080)   /* Timer_D7 High-Resolution clock divider: /4 */
#define TDHD_3              (0x00C0)   /* Timer_D7 High-Resolution clock divider: /8 */
#define TDHD__1             (0x0000)   /* Timer_D7 High-Resolution clock divider: /1 */
#define TDHD__2             (0x0040)   /* Timer_D7 High-Resolution clock divider: /2 */
#define TDHD__4             (0x0080)   /* Timer_D7 High-Resolution clock divider: /4 */
#define TDHD__8             (0x00C0)   /* Timer_D7 High-Resolution clock divider: /8 */

/* TDxHCTL1 Control Bits */
#define TDHCLKTRIM0         (0x0002)   /* Timer_D7 High-Resolution Clock Trim Bit: 0 */
#define TDHCLKTRIM1         (0x0004)   /* Timer_D7 High-Resolution Clock Trim Bit: 1 */
#define TDHCLKTRIM2         (0x0008)   /* Timer_D7 High-Resolution Clock Trim Bit: 2 */
#define TDHCLKTRIM3         (0x0010)   /* Timer_D7 High-Resolution Clock Trim Bit: 3 */
#define TDHCLKTRIM4         (0x0020)   /* Timer_D7 High-Resolution Clock Trim Bit: 4 */
#define TDHCLKTRIM5         (0x0040)   /* Timer_D7 High-Resolution Clock Trim Bit: 5 */
#define TDHCLKTRIM6         (0x0080)   /* Timer_D7 High-Resolution Clock Trim Bit: 6 */
#define TDHCLKSR0           (0x0100)   /* Timer_D7 High-Resolution Clock Sub-Range Bit: 0 */
#define TDHCLKSR1           (0x0200)   /* Timer_D7 High-Resolution Clock Sub-Range Bit: 1 */
#define TDHCLKSR2           (0x0400)   /* Timer_D7 High-Resolution Clock Sub-Range Bit: 2 */
#define TDHCLKSR3           (0x0800)   /* Timer_D7 High-Resolution Clock Sub-Range Bit: 3 */
#define TDHCLKSR4           (0x1000)   /* Timer_D7 High-Resolution Clock Sub-Range Bit: 4 */
#define TDHCLKR0            (0x2000)   /* Timer_D7 High-Resolution Clock Range Bit: 0 */
#define TDHCLKR1            (0x4000)   /* Timer_D7 High-Resolution Clock Range Bit: 1 */
#define TDHCLKCR            (0x8000)   /* Timer_D7 High-Resolution Coarse Clock Range */

/* TDxHINT Control Bits */
#define TDHFLIFG            (0x0001)   /* Timer_D7 High-Res. fail low Interrupt Flag */
#define TDHFHIFG            (0x0002)   /* Timer_D7 High-Res. fail high Interrupt Flag */
#define TDHLKIFG            (0x0004)   /* Timer_D7 High-Res. frequency lock Interrupt Flag */
#define TDHUNLKIFG          (0x0008)   /* Timer_D7 High-Res. frequency unlock Interrupt Flag */
#define TDHFLIE             (0x0100)   /* Timer_D7 High-Res. fail low Interrupt Enable */
#define TDHFHIE             (0x0200)   /* Timer_D7 High-Res. fail high Interrupt Enable */
#define TDHLKIE             (0x0400)   /* Timer_D7 High-Res. frequency lock Interrupt Enable */
#define TDHUNLKIE           (0x0800)   /* Timer_D7 High-Res. frequency unlock Interrupt Enable */

#define ID1                    (0x0080)       /* Timer D clock input divider 1 */
#define ID0                    (0x0040)       /* Timer D clock input divider 0 */
#define MC1                    (0x0020)       /* Timer D mode control 1 */
#define MC0                    (0x0010)       /* Timer D mode control 0 */
#define MC__STOP               (0*0x10u)      /* Timer D mode control: 0 - Stop */
#define MC__UP                 (1*0x10u)      /* Timer D mode control: 1 - Up to CCR0 */
#define MC__CONTINUOUS         (2*0x10u)      /* Timer D mode control: 2 - Continuous up */
#define MC__CONTINOUS          (2*0x10u)      /* Legacy define */
#define MC__UPDOWN             (3*0x10u)      /* Timer D mode control: 3 - Up/Down */
#define CM1                    (0x8000)       /* Capture mode 1 */
#define CM0                    (0x4000)       /* Capture mode 0 */
#define MC_0                   (0*0x10u)      /* Timer D mode control: 0 - Stop */
#define MC_1                   (1*0x10u)      /* Timer D mode control: 1 - Up to CCR0 */
#define MC_2                   (2*0x10u)      /* Timer D mode control: 2 - Continuous up */
#define MC_3                   (3*0x10u)      /* Timer D mode control: 3 - Up/Down */
#define CAP                    (0x0100)       /* Capture mode: 1 /Compare mode : 0 */
#define CCIE                   (0x0010)       /* Capture/compare interrupt enable */
#define CCIFG                  (0x0001)       /* Capture/compare interrupt flag */
#define CCIS_0                 (0*0x1000u)
#define CCIS_1                 (1*0x1000u)
#define CCIS_2                 (2*0x1000u)
#define CCIS_3                 (3*0x1000u)
#define CM_0                   (0*0x4000u)    /* Capture mode: 0 - disabled */
#define CM_1                   (1*0x4000u)    /* Capture mode: 1 - pos. edge */
#define CM_2                   (2*0x4000u)    /* Capture mode: 1 - neg. edge */
#define CM_3                   (3*0x4000u)    /* Capture mode: 1 - both edges */
#define OUT                    (0x0004)       /* PWM Output signal if output mode 0 */
#define OUTMOD_0               (0*0x20u)      /* PWM output mode: 0 - output only */
#define OUTMOD_1               (1*0x20u)      /* PWM output mode: 1 - set */
#define OUTMOD_2               (2*0x20u)      /* PWM output mode: 2 - PWM toggle/reset */
#define OUTMOD_3               (3*0x20u)      /* PWM output mode: 3 - PWM set/reset */
#define OUTMOD_4               (4*0x20u)      /* PWM output mode: 4 - toggle */
#define OUTMOD_5               (5*0x20u)      /* PWM output mode: 5 - Reset */
#define OUTMOD_6               (6*0x20u)      /* PWM output mode: 6 - PWM toggle/set */
#define OUTMOD_7               (7*0x20u)      /* PWM output mode: 7 - PWM reset/set */
#define SCCI                   (0x0400)       /* Latched capture signal (read) */
#define SCS                    (0x0800)       /* Capture sychronize */
#define CCI                    (0x0008)       /* Capture input signal (read) */
#define ID__1                  (0*0x40u)      /* Timer D input divider: 0 - /1 */
#define ID__2                  (1*0x40u)      /* Timer D input divider: 1 - /2 */
#define ID__4                  (2*0x40u)      /* Timer D input divider: 2 - /4 */
#define ID__8                  (3*0x40u)      /* Timer D input divider: 3 - /8 */
#define ID_0                   (0*0x40u)      /* Timer D input divider: 0 - /1 */
#define ID_1                   (1*0x40u)      /* Timer D input divider: 1 - /2 */
#define ID_2                   (2*0x40u)      /* Timer D input divider: 2 - /4 */
#define ID_3                   (3*0x40u)      /* Timer D input divider: 3 - /8 */

#endif
/************************************************************
* Timer Event Control 0
************************************************************/
#ifdef  __MSP430_HAS_TEV0__             /* Definition to show that Module is available */

#define OFS_TEC0XCTL0         (0x0000)  /* Timer Event Control 0 External Control 0 */
#define OFS_TEC0XCTL0_L        OFS_TEC0XCTL0
#define OFS_TEC0XCTL0_H        OFS_TEC0XCTL0+1
#define OFS_TEC0XCTL1         (0x0002)  /* Timer Event Control 0 External Control 1 */
#define OFS_TEC0XCTL1_L        OFS_TEC0XCTL1
#define OFS_TEC0XCTL1_H        OFS_TEC0XCTL1+1
#define OFS_TEC0XCTL2         (0x0004)  /* Timer Event Control 0 External Control 2 */
#define OFS_TEC0XCTL2_L        OFS_TEC0XCTL2
#define OFS_TEC0XCTL2_H        OFS_TEC0XCTL2+1
#define OFS_TEC0STA           (0x0006)  /* Timer Event Control 0 Status */
#define OFS_TEC0STA_L          OFS_TEC0STA
#define OFS_TEC0STA_H          OFS_TEC0STA+1
#define OFS_TEC0XINT          (0x0008)  /* Timer Event Control 0 External Interrupt */
#define OFS_TEC0XINT_L         OFS_TEC0XINT
#define OFS_TEC0XINT_H         OFS_TEC0XINT+1
#define OFS_TEC0IV            (0x000A)  /* Timer Event Control 0 Interrupt Vector */
#define OFS_TEC0IV_L           OFS_TEC0IV
#define OFS_TEC0IV_H           OFS_TEC0IV+1


/* TECxXCTL0 Control Bits */
#define TECXFLTHLD0         (0x0001)  /* TEV Ext. fault signal hold for CE0 */
#define TECXFLTHLD1         (0x0002)  /* TEV Ext. fault signal hold for CE1 */
#define TECXFLTHLD2         (0x0004)  /* TEV Ext. fault signal hold for CE2 */
#define TECXFLTHLD3         (0x0008)  /* TEV Ext. fault signal hold for CE3 */
#define TECXFLTHLD4         (0x0010)  /* TEV Ext. fault signal hold for CE4 */
#define TECXFLTHLD5         (0x0020)  /* TEV Ext. fault signal hold for CE5 */
#define TECXFLTHLD6         (0x0040)  /* TEV Ext. fault signal hold for CE6 */
#define TECXFLTEN0          (0x0100)  /* TEV Ext. fault signal enable for CE0 */
#define TECXFLTEN1          (0x0200)  /* TEV Ext. fault signal enable for CE1 */
#define TECXFLTEN2          (0x0400)  /* TEV Ext. fault signal enable for CE2 */
#define TECXFLTEN3          (0x0800)  /* TEV Ext. fault signal enable for CE3 */
#define TECXFLTEN4          (0x1000)  /* TEV Ext. fault signal enable for CE4 */
#define TECXFLTEN5          (0x2000)  /* TEV Ext. fault signal enable for CE5 */
#define TECXFLTEN6          (0x4000)  /* TEV Ext. fault signal enable for CE6 */

/* TECxXCTL0 Control Bits */
#define TECXFLTHLD0_L       (0x0001)  /* TEV Ext. fault signal hold for CE0 */
#define TECXFLTHLD1_L       (0x0002)  /* TEV Ext. fault signal hold for CE1 */
#define TECXFLTHLD2_L       (0x0004)  /* TEV Ext. fault signal hold for CE2 */
#define TECXFLTHLD3_L       (0x0008)  /* TEV Ext. fault signal hold for CE3 */
#define TECXFLTHLD4_L       (0x0010)  /* TEV Ext. fault signal hold for CE4 */
#define TECXFLTHLD5_L       (0x0020)  /* TEV Ext. fault signal hold for CE5 */
#define TECXFLTHLD6_L       (0x0040)  /* TEV Ext. fault signal hold for CE6 */

/* TECxXCTL0 Control Bits */
#define TECXFLTEN0_H        (0x0001)  /* TEV Ext. fault signal enable for CE0 */
#define TECXFLTEN1_H        (0x0002)  /* TEV Ext. fault signal enable for CE1 */
#define TECXFLTEN2_H        (0x0004)  /* TEV Ext. fault signal enable for CE2 */
#define TECXFLTEN3_H        (0x0008)  /* TEV Ext. fault signal enable for CE3 */
#define TECXFLTEN4_H        (0x0010)  /* TEV Ext. fault signal enable for CE4 */
#define TECXFLTEN5_H        (0x0020)  /* TEV Ext. fault signal enable for CE5 */
#define TECXFLTEN6_H        (0x0040)  /* TEV Ext. fault signal enable for CE6 */

/* TECxXCTL1 Control Bits */
#define TECXFLTPOL0         (0x0001)  /* TEV Polarity Bit of ext. fault 0 */
#define TECXFLTPOL1         (0x0002)  /* TEV Polarity Bit of ext. fault 1 */
#define TECXFLTPOL2         (0x0004)  /* TEV Polarity Bit of ext. fault 2 */
#define TECXFLTPOL3         (0x0008)  /* TEV Polarity Bit of ext. fault 3 */
#define TECXFLTPOL4         (0x0010)  /* TEV Polarity Bit of ext. fault 4 */
#define TECXFLTPOL5         (0x0020)  /* TEV Polarity Bit of ext. fault 5 */
#define TECXFLTPOL6         (0x0040)  /* TEV Polarity Bit of ext. fault 6 */
#define TECXFLTLVS0         (0x0100)  /* TEV Signal Type of Ext. fault 0 */
#define TECXFLTLVS1         (0x0200)  /* TEV Signal Type of Ext. fault 1 */
#define TECXFLTLVS2         (0x0400)  /* TEV Signal Type of Ext. fault 2 */
#define TECXFLTLVS3         (0x0800)  /* TEV Signal Type of Ext. fault 3 */
#define TECXFLTLVS4         (0x1000)  /* TEV Signal Type of Ext. fault 4 */
#define TECXFLTLVS5         (0x2000)  /* TEV Signal Type of Ext. fault 5 */
#define TECXFLTLVS6         (0x4000)  /* TEV Signal Type of Ext. fault 6 */

/* TECxXCTL1 Control Bits */
#define TECXFLTPOL0_L       (0x0001)  /* TEV Polarity Bit of ext. fault 0 */
#define TECXFLTPOL1_L       (0x0002)  /* TEV Polarity Bit of ext. fault 1 */
#define TECXFLTPOL2_L       (0x0004)  /* TEV Polarity Bit of ext. fault 2 */
#define TECXFLTPOL3_L       (0x0008)  /* TEV Polarity Bit of ext. fault 3 */
#define TECXFLTPOL4_L       (0x0010)  /* TEV Polarity Bit of ext. fault 4 */
#define TECXFLTPOL5_L       (0x0020)  /* TEV Polarity Bit of ext. fault 5 */
#define TECXFLTPOL6_L       (0x0040)  /* TEV Polarity Bit of ext. fault 6 */

/* TECxXCTL1 Control Bits */
#define TECXFLTLVS0_H       (0x0001)  /* TEV Signal Type of Ext. fault 0 */
#define TECXFLTLVS1_H       (0x0002)  /* TEV Signal Type of Ext. fault 1 */
#define TECXFLTLVS2_H       (0x0004)  /* TEV Signal Type of Ext. fault 2 */
#define TECXFLTLVS3_H       (0x0008)  /* TEV Signal Type of Ext. fault 3 */
#define TECXFLTLVS4_H       (0x0010)  /* TEV Signal Type of Ext. fault 4 */
#define TECXFLTLVS5_H       (0x0020)  /* TEV Signal Type of Ext. fault 5 */
#define TECXFLTLVS6_H       (0x0040)  /* TEV Signal Type of Ext. fault 6 */

/* TECxXCTL2 Control Bits */
#define TECCLKSEL0          (0x0001)  /* TEV Aux. Clock Select Bit: 0 */
#define TECCLKSEL1          (0x0002)  /* TEV Aux. Clock Select Bit: 1 */
#define TECAXCLREN          (0x0004)  /* TEV Auxilary clear signal control */
#define TECEXCLREN          (0x0008)  /* TEV Ext. clear signal control */
#define TECEXCLRHLD         (0x0010)  /* TEV External clear signal hold bit */
#define TECEXCLRPOL         (0x0020)  /* TEV Polarity Bit of ext. clear */
#define TECEXCLRLVS         (0x0040)  /* TEV Signal Type of Ext. clear */

/* TECxXCTL2 Control Bits */
#define TECCLKSEL0_L        (0x0001)  /* TEV Aux. Clock Select Bit: 0 */
#define TECCLKSEL1_L        (0x0002)  /* TEV Aux. Clock Select Bit: 1 */
#define TECAXCLREN_L        (0x0004)  /* TEV Auxilary clear signal control */
#define TECEXCLREN_L        (0x0008)  /* TEV Ext. clear signal control */
#define TECEXCLRHLD_L       (0x0010)  /* TEV External clear signal hold bit */
#define TECEXCLRPOL_L       (0x0020)  /* TEV Polarity Bit of ext. clear */
#define TECEXCLRLVS_L       (0x0040)  /* TEV Signal Type of Ext. clear */


#define TECCLKSEL_0         (0x0000)  /* TEV Aux. Clock Select: CLK0 */
#define TECCLKSEL_1         (0x0001)  /* TEV Aux. Clock Select: CLK1 */
#define TECCLKSEL_2         (0x0002)  /* TEV Aux. Clock Select: CLK2 */
#define TECCLKSEL_3         (0x0003)  /* TEV Aux. Clock Select: CLK3 */

/* TECxSTA Control Bits */
#define TECXFLT0STA         (0x0001)  /* TEV External fault status flag for CE0 */
#define TECXFLT1STA         (0x0002)  /* TEV External fault status flag for CE1 */
#define TECXFLT2STA         (0x0004)  /* TEV External fault status flag for CE2 */
#define TECXFLT3STA         (0x0008)  /* TEV External fault status flag for CE3 */
#define TECXFLT4STA         (0x0010)  /* TEV External fault status flag for CE4 */
#define TECXFLT5STA         (0x0020)  /* TEV External fault status flag for CE5 */
#define TECXFLT6STA         (0x0040)  /* TEV External fault status flag for CE6 */
#define TECXCLRSTA          (0x0100)  /* TEC External clear status flag */

/* TECxSTA Control Bits */
#define TECXFLT0STA_L       (0x0001)  /* TEV External fault status flag for CE0 */
#define TECXFLT1STA_L       (0x0002)  /* TEV External fault status flag for CE1 */
#define TECXFLT2STA_L       (0x0004)  /* TEV External fault status flag for CE2 */
#define TECXFLT3STA_L       (0x0008)  /* TEV External fault status flag for CE3 */
#define TECXFLT4STA_L       (0x0010)  /* TEV External fault status flag for CE4 */
#define TECXFLT5STA_L       (0x0020)  /* TEV External fault status flag for CE5 */
#define TECXFLT6STA_L       (0x0040)  /* TEV External fault status flag for CE6 */

/* TECxSTA Control Bits */
#define TECXCLRSTA_H        (0x0001)  /* TEC External clear status flag */

/* TECxXINT Control Bits */
#define TECAXCLRIFG         (0x0001)   /* TEC Aux. Clear Interrupt Flag */
#define TECEXCLRIFG         (0x0002)   /* TEC External Clear Interrupt Flag */
#define TECXFLTIFG          (0x0004)   /* TEC External Fault Interrupt Flag */
#define TECAXCLRIE          (0x0100)   /* TEC Aux. Clear Interrupt Enable */
#define TECEXCLRIE          (0x0200)   /* TEC External Clear Interrupt Enable */
#define TECXFLTIE           (0x0400)   /* TEC External Fault Interrupt Enable */

/* TECxXINT Control Bits */
#define TECAXCLRIFG_L       (0x0001)   /* TEC Aux. Clear Interrupt Flag */
#define TECEXCLRIFG_L       (0x0002)   /* TEC External Clear Interrupt Flag */
#define TECXFLTIFG_L        (0x0004)   /* TEC External Fault Interrupt Flag */

/* TECxXINT Control Bits */
#define TECAXCLRIE_H        (0x0001)   /* TEC Aux. Clear Interrupt Enable */
#define TECEXCLRIE_H        (0x0002)   /* TEC External Clear Interrupt Enable */
#define TECXFLTIE_H         (0x0004)   /* TEC External Fault Interrupt Enable */

/* TEC0IV Definitions */
#define TEC0IV_NONE         (0x0000)    /* No Interrupt pending */
#define TEC0IV_TECXFLTIFG   (0x0002)    /* TEC0XFLTIFG */
#define TEC0IV_TECEXCLRIFG  (0x0004)    /* TEC0EXCLRIFG */
#define TEC0IV_TECAXCLRIFG  (0x0006)    /* TEC0AXCLRIFG */

#endif
/************************************************************
* Timer Event Control x
************************************************************/
#ifdef  __MSP430_HAS_TEVx__             /* Definition to show that Module is available */

#define OFS_TECxXCTL0         (0x0000)  /* Timer Event Control x External Control 0 */
#define OFS_TECxXCTL0_L        OFS_TECxXCTL0
#define OFS_TECxXCTL0_H        OFS_TECxXCTL0+1
#define OFS_TECxXCTL1         (0x0002)  /* Timer Event Control x External Control 1 */
#define OFS_TECxXCTL1_L        OFS_TECxXCTL1
#define OFS_TECxXCTL1_H        OFS_TECxXCTL1+1
#define OFS_TECxXCTL2         (0x0004)  /* Timer Event Control x External Control 2 */
#define OFS_TECxXCTL2_L        OFS_TECxXCTL2
#define OFS_TECxXCTL2_H        OFS_TECxXCTL2+1
#define OFS_TECxSTA           (0x0006)  /* Timer Event Control x Status */
#define OFS_TECxSTA_L          OFS_TECxSTA
#define OFS_TECxSTA_H          OFS_TECxSTA+1
#define OFS_TECxXINT          (0x0008)  /* Timer Event Control x External Interrupt */
#define OFS_TECxXINT_L         OFS_TECxXINT
#define OFS_TECxXINT_H         OFS_TECxXINT+1
#define OFS_TECxIV            (0x000A)  /* Timer Event Control x Interrupt Vector */
#define OFS_TECxIV_L           OFS_TECxIV
#define OFS_TECxIV_H           OFS_TECxIV+1


/* TECIV Definitions */
#define TECxIV_NONE         (0x0000)    /* No Interrupt pending */
#define TECxIV_TECXFLTIFG   (0x0002)    /* TECxXFLTIFG */
#define TECxIV_TECEXCLRIFG  (0x0004)    /* TECxEXCLRIFG */
#define TECxIV_TECAXCLRIFG  (0x0006)    /* TECxAXCLRIFG */


#endif

/************************************************************
* UNIFIED CLOCK SYSTEM
************************************************************/
#ifdef  __MSP430_HAS_UCS__            /* Definition to show that Module is available */

#define OFS_UCSCTL0           (0x0000)  /* UCS Control Register 0 */
#define OFS_UCSCTL0_L          OFS_UCSCTL0
#define OFS_UCSCTL0_H          OFS_UCSCTL0+1
#define OFS_UCSCTL1           (0x0002)  /* UCS Control Register 1 */
#define OFS_UCSCTL1_L          OFS_UCSCTL1
#define OFS_UCSCTL1_H          OFS_UCSCTL1+1
#define OFS_UCSCTL2           (0x0004)  /* UCS Control Register 2 */
#define OFS_UCSCTL2_L          OFS_UCSCTL2
#define OFS_UCSCTL2_H          OFS_UCSCTL2+1
#define OFS_UCSCTL3           (0x0006)  /* UCS Control Register 3 */
#define OFS_UCSCTL3_L          OFS_UCSCTL3
#define OFS_UCSCTL3_H          OFS_UCSCTL3+1
#define OFS_UCSCTL4           (0x0008)  /* UCS Control Register 4 */
#define OFS_UCSCTL4_L          OFS_UCSCTL4
#define OFS_UCSCTL4_H          OFS_UCSCTL4+1
#define OFS_UCSCTL5           (0x000A)  /* UCS Control Register 5 */
#define OFS_UCSCTL5_L          OFS_UCSCTL5
#define OFS_UCSCTL5_H          OFS_UCSCTL5+1
#define OFS_UCSCTL6           (0x000C)  /* UCS Control Register 6 */
#define OFS_UCSCTL6_L          OFS_UCSCTL6
#define OFS_UCSCTL6_H          OFS_UCSCTL6+1
#define OFS_UCSCTL7           (0x000E)  /* UCS Control Register 7 */
#define OFS_UCSCTL7_L          OFS_UCSCTL7
#define OFS_UCSCTL7_H          OFS_UCSCTL7+1
#define OFS_UCSCTL8           (0x0010)  /* UCS Control Register 8 */
#define OFS_UCSCTL8_L          OFS_UCSCTL8
#define OFS_UCSCTL8_H          OFS_UCSCTL8+1

/* UCSCTL0 Control Bits */
//#define RESERVED            (0x0001)    /* RESERVED */
//#define RESERVED            (0x0002)    /* RESERVED */
//#define RESERVED            (0x0004)    /* RESERVED */
#define MOD0                (0x0008)    /* Modulation Bit Counter Bit : 0 */
#define MOD1                (0x0010)    /* Modulation Bit Counter Bit : 1 */
#define MOD2                (0x0020)    /* Modulation Bit Counter Bit : 2 */
#define MOD3                (0x0040)    /* Modulation Bit Counter Bit : 3 */
#define MOD4                (0x0080)    /* Modulation Bit Counter Bit : 4 */
#define DCO0                (0x0100)    /* DCO TAP Bit : 0 */
#define DCO1                (0x0200)    /* DCO TAP Bit : 1 */
#define DCO2                (0x0400)    /* DCO TAP Bit : 2 */
#define DCO3                (0x0800)    /* DCO TAP Bit : 3 */
#define DCO4                (0x1000)    /* DCO TAP Bit : 4 */
//#define RESERVED            (0x2000)    /* RESERVED */
//#define RESERVED            (0x4000)    /* RESERVED */
//#define RESERVED            (0x8000)    /* RESERVED */

/* UCSCTL0 Control Bits */
//#define RESERVED            (0x0001)    /* RESERVED */
//#define RESERVED            (0x0002)    /* RESERVED */
//#define RESERVED            (0x0004)    /* RESERVED */
#define MOD0_L              (0x0008)    /* Modulation Bit Counter Bit : 0 */
#define MOD1_L              (0x0010)    /* Modulation Bit Counter Bit : 1 */
#define MOD2_L              (0x0020)    /* Modulation Bit Counter Bit : 2 */
#define MOD3_L              (0x0040)    /* Modulation Bit Counter Bit : 3 */
#define MOD4_L              (0x0080)    /* Modulation Bit Counter Bit : 4 */
//#define RESERVED            (0x2000)    /* RESERVED */
//#define RESERVED            (0x4000)    /* RESERVED */
//#define RESERVED            (0x8000)    /* RESERVED */

/* UCSCTL0 Control Bits */
//#define RESERVED            (0x0001)    /* RESERVED */
//#define RESERVED            (0x0002)    /* RESERVED */
//#define RESERVED            (0x0004)    /* RESERVED */
#define DCO0_H              (0x0001)    /* DCO TAP Bit : 0 */
#define DCO1_H              (0x0002)    /* DCO TAP Bit : 1 */
#define DCO2_H              (0x0004)    /* DCO TAP Bit : 2 */
#define DCO3_H              (0x0008)    /* DCO TAP Bit : 3 */
#define DCO4_H              (0x0010)    /* DCO TAP Bit : 4 */
//#define RESERVED            (0x2000)    /* RESERVED */
//#define RESERVED            (0x4000)    /* RESERVED */
//#define RESERVED            (0x8000)    /* RESERVED */

/* UCSCTL1 Control Bits */
#define DISMOD              (0x0001)    /* Disable Modulation */
//#define RESERVED            (0x0002)    /* RESERVED */
//#define RESERVED            (0x0004)    /* RESERVED */
//#define RESERVED            (0x0008)    /* RESERVED */
#define DCORSEL0            (0x0010)    /* DCO Freq. Range Select Bit : 0 */
#define DCORSEL1            (0x0020)    /* DCO Freq. Range Select Bit : 1 */
#define DCORSEL2            (0x0040)    /* DCO Freq. Range Select Bit : 2 */
//#define RESERVED            (0x0080)    /* RESERVED */
//#define RESERVED            (0x0100)    /* RESERVED */
//#define RESERVED            (0x0200)    /* RESERVED */
//#define RESERVED            (0x0400)    /* RESERVED */
//#define RESERVED            (0x0800)    /* RESERVED */
//#define RESERVED            (0x1000)    /* RESERVED */
//#define RESERVED            (0x2000)    /* RESERVED */
//#define RESERVED            (0x4000)    /* RESERVED */
//#define RESERVED            (0x8000)    /* RESERVED */

/* UCSCTL1 Control Bits */
#define DISMOD_L            (0x0001)    /* Disable Modulation */
//#define RESERVED            (0x0002)    /* RESERVED */
//#define RESERVED            (0x0004)    /* RESERVED */
//#define RESERVED            (0x0008)    /* RESERVED */
#define DCORSEL0_L          (0x0010)    /* DCO Freq. Range Select Bit : 0 */
#define DCORSEL1_L          (0x0020)    /* DCO Freq. Range Select Bit : 1 */
#define DCORSEL2_L          (0x0040)    /* DCO Freq. Range Select Bit : 2 */
//#define RESERVED            (0x0080)    /* RESERVED */
//#define RESERVED            (0x0100)    /* RESERVED */
//#define RESERVED            (0x0200)    /* RESERVED */
//#define RESERVED            (0x0400)    /* RESERVED */
//#define RESERVED            (0x0800)    /* RESERVED */
//#define RESERVED            (0x1000)    /* RESERVED */
//#define RESERVED            (0x2000)    /* RESERVED */
//#define RESERVED            (0x4000)    /* RESERVED */
//#define RESERVED            (0x8000)    /* RESERVED */


#define DCORSEL_0           (0x0000)    /* DCO RSEL 0 */
#define DCORSEL_1           (0x0010)    /* DCO RSEL 1 */
#define DCORSEL_2           (0x0020)    /* DCO RSEL 2 */
#define DCORSEL_3           (0x0030)    /* DCO RSEL 3 */
#define DCORSEL_4           (0x0040)    /* DCO RSEL 4 */
#define DCORSEL_5           (0x0050)    /* DCO RSEL 5 */
#define DCORSEL_6           (0x0060)    /* DCO RSEL 6 */
#define DCORSEL_7           (0x0070)    /* DCO RSEL 7 */


/* UCSCTL2 Control Bits */
#define FLLN0               (0x0001)    /* FLL Multipier Bit : 0 */
#define FLLN1               (0x0002)    /* FLL Multipier Bit : 1 */
#define FLLN2               (0x0004)    /* FLL Multipier Bit : 2 */
#define FLLN3               (0x0008)    /* FLL Multipier Bit : 3 */
#define FLLN4               (0x0010)    /* FLL Multipier Bit : 4 */
#define FLLN5               (0x0020)    /* FLL Multipier Bit : 5 */
#define FLLN6               (0x0040)    /* FLL Multipier Bit : 6 */
#define FLLN7               (0x0080)    /* FLL Multipier Bit : 7 */
#define FLLN8               (0x0100)    /* FLL Multipier Bit : 8 */
#define FLLN9               (0x0200)    /* FLL Multipier Bit : 9 */
//#define RESERVED            (0x0400)    /* RESERVED */
//#define RESERVED            (0x0800)    /* RESERVED */
#define FLLD0               (0x1000)    /* Loop Divider Bit : 0 */
#define FLLD1               (0x2000)    /* Loop Divider Bit : 1 */
#define FLLD2               (0x4000)    /* Loop Divider Bit : 1 */
//#define RESERVED            (0x8000)    /* RESERVED */

/* UCSCTL2 Control Bits */
#define FLLN0_L             (0x0001)    /* FLL Multipier Bit : 0 */
#define FLLN1_L             (0x0002)    /* FLL Multipier Bit : 1 */
#define FLLN2_L             (0x0004)    /* FLL Multipier Bit : 2 */
#define FLLN3_L             (0x0008)    /* FLL Multipier Bit : 3 */
#define FLLN4_L             (0x0010)    /* FLL Multipier Bit : 4 */
#define FLLN5_L             (0x0020)    /* FLL Multipier Bit : 5 */
#define FLLN6_L             (0x0040)    /* FLL Multipier Bit : 6 */
#define FLLN7_L             (0x0080)    /* FLL Multipier Bit : 7 */
//#define RESERVED            (0x0400)    /* RESERVED */
//#define RESERVED            (0x0800)    /* RESERVED */
//#define RESERVED            (0x8000)    /* RESERVED */

/* UCSCTL2 Control Bits */
#define FLLN8_H             (0x0001)    /* FLL Multipier Bit : 8 */
#define FLLN9_H             (0x0002)    /* FLL Multipier Bit : 9 */
//#define RESERVED            (0x0400)    /* RESERVED */
//#define RESERVED            (0x0800)    /* RESERVED */
#define FLLD0_H             (0x0010)    /* Loop Divider Bit : 0 */
#define FLLD1_H             (0x0020)    /* Loop Divider Bit : 1 */
#define FLLD2_H             (0x0040)    /* Loop Divider Bit : 1 */
//#define RESERVED            (0x8000)    /* RESERVED */

#define FLLD_0             (0x0000)    /* Multiply Selected Loop Freq. 1 */
#define FLLD_1             (0x1000)    /* Multiply Selected Loop Freq. 2 */
#define FLLD_2             (0x2000)    /* Multiply Selected Loop Freq. 4 */
#define FLLD_3             (0x3000)    /* Multiply Selected Loop Freq. 8 */
#define FLLD_4             (0x4000)    /* Multiply Selected Loop Freq. 16 */
#define FLLD_5             (0x5000)    /* Multiply Selected Loop Freq. 32 */
#define FLLD_6             (0x6000)    /* Multiply Selected Loop Freq. 32 */
#define FLLD_7             (0x7000)    /* Multiply Selected Loop Freq. 32 */
#define FLLD__1            (0x0000)    /* Multiply Selected Loop Freq. By 1 */
#define FLLD__2            (0x1000)    /* Multiply Selected Loop Freq. By 2 */
#define FLLD__4            (0x2000)    /* Multiply Selected Loop Freq. By 4 */
#define FLLD__8            (0x3000)    /* Multiply Selected Loop Freq. By 8 */
#define FLLD__16           (0x4000)    /* Multiply Selected Loop Freq. By 16 */
#define FLLD__32           (0x5000)    /* Multiply Selected Loop Freq. By 32 */


/* UCSCTL3 Control Bits */
#define FLLREFDIV0          (0x0001)    /* Reference Divider Bit : 0 */
#define FLLREFDIV1          (0x0002)    /* Reference Divider Bit : 1 */
#define FLLREFDIV2          (0x0004)    /* Reference Divider Bit : 2 */
//#define RESERVED            (0x0008)    /* RESERVED */
#define SELREF0             (0x0010)    /* FLL Reference Clock Select Bit : 0 */
#define SELREF1             (0x0020)    /* FLL Reference Clock Select Bit : 1 */
#define SELREF2             (0x0040)    /* FLL Reference Clock Select Bit : 2 */
//#define RESERVED            (0x0080)    /* RESERVED */
//#define RESERVED            (0x0100)    /* RESERVED */
//#define RESERVED            (0x0200)    /* RESERVED */
//#define RESERVED            (0x0400)    /* RESERVED */
//#define RESERVED            (0x0800)    /* RESERVED */
//#define RESERVED            (0x1000)    /* RESERVED */
//#define RESERVED            (0x2000)    /* RESERVED */
//#define RESERVED            (0x4000)    /* RESERVED */
//#define RESERVED            (0x8000)    /* RESERVED */

/* UCSCTL3 Control Bits */
#define FLLREFDIV0_L        (0x0001)    /* Reference Divider Bit : 0 */
#define FLLREFDIV1_L        (0x0002)    /* Reference Divider Bit : 1 */
#define FLLREFDIV2_L        (0x0004)    /* Reference Divider Bit : 2 */
//#define RESERVED            (0x0008)    /* RESERVED */
#define SELREF0_L           (0x0010)    /* FLL Reference Clock Select Bit : 0 */
#define SELREF1_L           (0x0020)    /* FLL Reference Clock Select Bit : 1 */
#define SELREF2_L           (0x0040)    /* FLL Reference Clock Select Bit : 2 */
//#define RESERVED            (0x0080)    /* RESERVED */
//#define RESERVED            (0x0100)    /* RESERVED */
//#define RESERVED            (0x0200)    /* RESERVED */
//#define RESERVED            (0x0400)    /* RESERVED */
//#define RESERVED            (0x0800)    /* RESERVED */
//#define RESERVED            (0x1000)    /* RESERVED */
//#define RESERVED            (0x2000)    /* RESERVED */
//#define RESERVED            (0x4000)    /* RESERVED */
//#define RESERVED            (0x8000)    /* RESERVED */


#define FLLREFDIV_0         (0x0000)    /* Reference Divider: f(LFCLK)/1 */
#define FLLREFDIV_1         (0x0001)    /* Reference Divider: f(LFCLK)/2 */
#define FLLREFDIV_2         (0x0002)    /* Reference Divider: f(LFCLK)/4 */
#define FLLREFDIV_3         (0x0003)    /* Reference Divider: f(LFCLK)/8 */
#define FLLREFDIV_4         (0x0004)    /* Reference Divider: f(LFCLK)/12 */
#define FLLREFDIV_5         (0x0005)    /* Reference Divider: f(LFCLK)/16 */
#define FLLREFDIV_6         (0x0006)    /* Reference Divider: f(LFCLK)/16 */
#define FLLREFDIV_7         (0x0007)    /* Reference Divider: f(LFCLK)/16 */
#define FLLREFDIV__1        (0x0000)    /* Reference Divider: f(LFCLK)/1 */
#define FLLREFDIV__2        (0x0001)    /* Reference Divider: f(LFCLK)/2 */
#define FLLREFDIV__4        (0x0002)    /* Reference Divider: f(LFCLK)/4 */
#define FLLREFDIV__8        (0x0003)    /* Reference Divider: f(LFCLK)/8 */
#define FLLREFDIV__12       (0x0004)    /* Reference Divider: f(LFCLK)/12 */
#define FLLREFDIV__16       (0x0005)    /* Reference Divider: f(LFCLK)/16 */
#define SELREF_0            (0x0000)    /* FLL Reference Clock Select 0 */
#define SELREF_1            (0x0010)    /* FLL Reference Clock Select 1 */
#define SELREF_2            (0x0020)    /* FLL Reference Clock Select 2 */
#define SELREF_3            (0x0030)    /* FLL Reference Clock Select 3 */
#define SELREF_4            (0x0040)    /* FLL Reference Clock Select 4 */
#define SELREF_5            (0x0050)    /* FLL Reference Clock Select 5 */
#define SELREF_6            (0x0060)    /* FLL Reference Clock Select 6 */
#define SELREF_7            (0x0070)    /* FLL Reference Clock Select 7 */
#define SELREF__XT1CLK      (0x0000)    /* Multiply Selected Loop Freq. By XT1CLK */
#define SELREF__REFOCLK     (0x0020)    /* Multiply Selected Loop Freq. By REFOCLK */
#define SELREF__XT2CLK      (0x0050)    /* Multiply Selected Loop Freq. By XT2CLK */

/* UCSCTL4 Control Bits */
#define SELM0               (0x0001)   /* MCLK Source Select Bit: 0 */
#define SELM1               (0x0002)   /* MCLK Source Select Bit: 1 */
#define SELM2               (0x0004)   /* MCLK Source Select Bit: 2 */
//#define RESERVED            (0x0008)    /* RESERVED */
#define SELS0               (0x0010)   /* SMCLK Source Select Bit: 0 */
#define SELS1               (0x0020)   /* SMCLK Source Select Bit: 1 */
#define SELS2               (0x0040)   /* SMCLK Source Select Bit: 2 */
//#define RESERVED            (0x0080)    /* RESERVED */
#define SELA0               (0x0100)   /* ACLK Source Select Bit: 0 */
#define SELA1               (0x0200)   /* ACLK Source Select Bit: 1 */
#define SELA2               (0x0400)   /* ACLK Source Select Bit: 2 */
//#define RESERVED            (0x0800)    /* RESERVED */
//#define RESERVED            (0x1000)    /* RESERVED */
//#define RESERVED            (0x2000)    /* RESERVED */
//#define RESERVED            (0x4000)    /* RESERVED */
//#define RESERVED            (0x8000)    /* RESERVED */

/* UCSCTL4 Control Bits */
#define SELM0_L             (0x0001)   /* MCLK Source Select Bit: 0 */
#define SELM1_L             (0x0002)   /* MCLK Source Select Bit: 1 */
#define SELM2_L             (0x0004)   /* MCLK Source Select Bit: 2 */
//#define RESERVED            (0x0008)    /* RESERVED */
#define SELS0_L             (0x0010)   /* SMCLK Source Select Bit: 0 */
#define SELS1_L             (0x0020)   /* SMCLK Source Select Bit: 1 */
#define SELS2_L             (0x0040)   /* SMCLK Source Select Bit: 2 */
//#define RESERVED            (0x0080)    /* RESERVED */
//#define RESERVED            (0x0800)    /* RESERVED */
//#define RESERVED            (0x1000)    /* RESERVED */
//#define RESERVED            (0x2000)    /* RESERVED */
//#define RESERVED            (0x4000)    /* RESERVED */
//#define RESERVED            (0x8000)    /* RESERVED */

/* UCSCTL4 Control Bits */
//#define RESERVED            (0x0008)    /* RESERVED */
//#define RESERVED            (0x0080)    /* RESERVED */
#define SELA0_H             (0x0001)   /* ACLK Source Select Bit: 0 */
#define SELA1_H             (0x0002)   /* ACLK Source Select Bit: 1 */
#define SELA2_H             (0x0004)   /* ACLK Source Select Bit: 2 */
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
#define SELM__XT1CLK        (0x0000)   /* MCLK Source Select XT1CLK */
#define SELM__VLOCLK        (0x0001)   /* MCLK Source Select VLOCLK */
#define SELM__REFOCLK       (0x0002)   /* MCLK Source Select REFOCLK */
#define SELM__DCOCLK        (0x0003)   /* MCLK Source Select DCOCLK */
#define SELM__DCOCLKDIV     (0x0004)   /* MCLK Source Select DCOCLKDIV */
#define SELM__XT2CLK        (0x0005)   /* MCLK Source Select XT2CLK */

#define SELS_0              (0x0000)   /* SMCLK Source Select 0 */
#define SELS_1              (0x0010)   /* SMCLK Source Select 1 */
#define SELS_2              (0x0020)   /* SMCLK Source Select 2 */
#define SELS_3              (0x0030)   /* SMCLK Source Select 3 */
#define SELS_4              (0x0040)   /* SMCLK Source Select 4 */
#define SELS_5              (0x0050)   /* SMCLK Source Select 5 */
#define SELS_6              (0x0060)   /* SMCLK Source Select 6 */
#define SELS_7              (0x0070)   /* SMCLK Source Select 7 */
#define SELS__XT1CLK        (0x0000)   /* SMCLK Source Select XT1CLK */
#define SELS__VLOCLK        (0x0010)   /* SMCLK Source Select VLOCLK */
#define SELS__REFOCLK       (0x0020)   /* SMCLK Source Select REFOCLK */
#define SELS__DCOCLK        (0x0030)   /* SMCLK Source Select DCOCLK */
#define SELS__DCOCLKDIV     (0x0040)   /* SMCLK Source Select DCOCLKDIV */
#define SELS__XT2CLK        (0x0050)   /* SMCLK Source Select XT2CLK */

#define SELA_0              (0x0000)   /* ACLK Source Select 0 */
#define SELA_1              (0x0100)   /* ACLK Source Select 1 */
#define SELA_2              (0x0200)   /* ACLK Source Select 2 */
#define SELA_3              (0x0300)   /* ACLK Source Select 3 */
#define SELA_4              (0x0400)   /* ACLK Source Select 4 */
#define SELA_5              (0x0500)   /* ACLK Source Select 5 */
#define SELA_6              (0x0600)   /* ACLK Source Select 6 */
#define SELA_7              (0x0700)   /* ACLK Source Select 7 */
#define SELA__XT1CLK        (0x0000)   /* ACLK Source Select XT1CLK */
#define SELA__VLOCLK        (0x0100)   /* ACLK Source Select VLOCLK */
#define SELA__REFOCLK       (0x0200)   /* ACLK Source Select REFOCLK */
#define SELA__DCOCLK        (0x0300)   /* ACLK Source Select DCOCLK */
#define SELA__DCOCLKDIV     (0x0400)   /* ACLK Source Select DCOCLKDIV */
#define SELA__XT2CLK        (0x0500)   /* ACLK Source Select XT2CLK */

/* UCSCTL5 Control Bits */
#define DIVM0               (0x0001)   /* MCLK Divider Bit: 0 */
#define DIVM1               (0x0002)   /* MCLK Divider Bit: 1 */
#define DIVM2               (0x0004)   /* MCLK Divider Bit: 2 */
//#define RESERVED            (0x0008)    /* RESERVED */
#define DIVS0               (0x0010)   /* SMCLK Divider Bit: 0 */
#define DIVS1               (0x0020)   /* SMCLK Divider Bit: 1 */
#define DIVS2               (0x0040)   /* SMCLK Divider Bit: 2 */
//#define RESERVED            (0x0080)    /* RESERVED */
#define DIVA0               (0x0100)   /* ACLK Divider Bit: 0 */
#define DIVA1               (0x0200)   /* ACLK Divider Bit: 1 */
#define DIVA2               (0x0400)   /* ACLK Divider Bit: 2 */
//#define RESERVED            (0x0800)    /* RESERVED */
#define DIVPA0              (0x1000)   /* ACLK from Pin Divider Bit: 0 */
#define DIVPA1              (0x2000)   /* ACLK from Pin Divider Bit: 1 */
#define DIVPA2              (0x4000)   /* ACLK from Pin Divider Bit: 2 */
//#define RESERVED            (0x8000)    /* RESERVED */

/* UCSCTL5 Control Bits */
#define DIVM0_L             (0x0001)   /* MCLK Divider Bit: 0 */
#define DIVM1_L             (0x0002)   /* MCLK Divider Bit: 1 */
#define DIVM2_L             (0x0004)   /* MCLK Divider Bit: 2 */
//#define RESERVED            (0x0008)    /* RESERVED */
#define DIVS0_L             (0x0010)   /* SMCLK Divider Bit: 0 */
#define DIVS1_L             (0x0020)   /* SMCLK Divider Bit: 1 */
#define DIVS2_L             (0x0040)   /* SMCLK Divider Bit: 2 */
//#define RESERVED            (0x0080)    /* RESERVED */
//#define RESERVED            (0x0800)    /* RESERVED */
//#define RESERVED            (0x8000)    /* RESERVED */

/* UCSCTL5 Control Bits */
//#define RESERVED            (0x0008)    /* RESERVED */
//#define RESERVED            (0x0080)    /* RESERVED */
#define DIVA0_H             (0x0001)   /* ACLK Divider Bit: 0 */
#define DIVA1_H             (0x0002)   /* ACLK Divider Bit: 1 */
#define DIVA2_H             (0x0004)   /* ACLK Divider Bit: 2 */
//#define RESERVED            (0x0800)    /* RESERVED */
#define DIVPA0_H            (0x0010)   /* ACLK from Pin Divider Bit: 0 */
#define DIVPA1_H            (0x0020)   /* ACLK from Pin Divider Bit: 1 */
#define DIVPA2_H            (0x0040)   /* ACLK from Pin Divider Bit: 2 */
//#define RESERVED            (0x8000)    /* RESERVED */

#define DIVM_0              (0x0000)    /* MCLK Source Divider 0 */
#define DIVM_1              (0x0001)    /* MCLK Source Divider 1 */
#define DIVM_2              (0x0002)    /* MCLK Source Divider 2 */
#define DIVM_3              (0x0003)    /* MCLK Source Divider 3 */
#define DIVM_4              (0x0004)    /* MCLK Source Divider 4 */
#define DIVM_5              (0x0005)    /* MCLK Source Divider 5 */
#define DIVM_6              (0x0006)    /* MCLK Source Divider 6 */
#define DIVM_7              (0x0007)    /* MCLK Source Divider 7 */
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
#define DIVS_6              (0x0060)    /* SMCLK Source Divider 6 */
#define DIVS_7              (0x0070)    /* SMCLK Source Divider 7 */
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
#define DIVA_6              (0x0600)    /* ACLK Source Divider 6 */
#define DIVA_7              (0x0700)    /* ACLK Source Divider 7 */
#define DIVA__1             (0x0000)    /* ACLK Source Divider f(ACLK)/1 */
#define DIVA__2             (0x0100)    /* ACLK Source Divider f(ACLK)/2 */
#define DIVA__4             (0x0200)    /* ACLK Source Divider f(ACLK)/4 */
#define DIVA__8             (0x0300)    /* ACLK Source Divider f(ACLK)/8 */
#define DIVA__16            (0x0400)    /* ACLK Source Divider f(ACLK)/16 */
#define DIVA__32            (0x0500)    /* ACLK Source Divider f(ACLK)/32 */

#define DIVPA_0             (0x0000)    /* ACLK from Pin Source Divider 0 */
#define DIVPA_1             (0x1000)    /* ACLK from Pin Source Divider 1 */
#define DIVPA_2             (0x2000)    /* ACLK from Pin Source Divider 2 */
#define DIVPA_3             (0x3000)    /* ACLK from Pin Source Divider 3 */
#define DIVPA_4             (0x4000)    /* ACLK from Pin Source Divider 4 */
#define DIVPA_5             (0x5000)    /* ACLK from Pin Source Divider 5 */
#define DIVPA_6             (0x6000)    /* ACLK from Pin Source Divider 6 */
#define DIVPA_7             (0x7000)    /* ACLK from Pin Source Divider 7 */
#define DIVPA__1            (0x0000)    /* ACLK from Pin Source Divider f(ACLK)/1 */
#define DIVPA__2            (0x1000)    /* ACLK from Pin Source Divider f(ACLK)/2 */
#define DIVPA__4            (0x2000)    /* ACLK from Pin Source Divider f(ACLK)/4 */
#define DIVPA__8            (0x3000)    /* ACLK from Pin Source Divider f(ACLK)/8 */
#define DIVPA__16           (0x4000)    /* ACLK from Pin Source Divider f(ACLK)/16 */
#define DIVPA__32           (0x5000)    /* ACLK from Pin Source Divider f(ACLK)/32 */


/* UCSCTL6 Control Bits */
#define XT1OFF              (0x0001)    /* High Frequency Oscillator 1 (XT1) disable */
#define SMCLKOFF            (0x0002)    /* SMCLK Off */
#define XCAP0               (0x0004)   /* XIN/XOUT Cap Bit: 0 */
#define XCAP1               (0x0008)   /* XIN/XOUT Cap Bit: 1 */
#define XT1BYPASS           (0x0010)    /* XT1 bypass mode : 0: internal 1:sourced from external pin */
#define XTS                 (0x0020)   /* 1: Selects high-freq. oscillator */
#define XT1DRIVE0           (0x0040)    /* XT1 Drive Level mode Bit 0 */
#define XT1DRIVE1           (0x0080)    /* XT1 Drive Level mode Bit 1 */
#define XT2OFF              (0x0100)    /* High Frequency Oscillator 2 (XT2) disable */
//#define RESERVED            (0x0200)    /* RESERVED */
//#define RESERVED            (0x0400)    /* RESERVED */
//#define RESERVED            (0x0800)    /* RESERVED */
#define XT2BYPASS           (0x1000)    /* XT2 bypass mode : 0: internal 1:sourced from external pin */
//#define RESERVED            (0x2000)    /* RESERVED */
#define XT2DRIVE0           (0x4000)    /* XT2 Drive Level mode Bit 0 */
#define XT2DRIVE1           (0x8000)    /* XT2 Drive Level mode Bit 1 */

/* UCSCTL6 Control Bits */
#define XT1OFF_L            (0x0001)    /* High Frequency Oscillator 1 (XT1) disable */
#define SMCLKOFF_L          (0x0002)    /* SMCLK Off */
#define XCAP0_L             (0x0004)   /* XIN/XOUT Cap Bit: 0 */
#define XCAP1_L             (0x0008)   /* XIN/XOUT Cap Bit: 1 */
#define XT1BYPASS_L         (0x0010)    /* XT1 bypass mode : 0: internal 1:sourced from external pin */
#define XTS_L               (0x0020)   /* 1: Selects high-freq. oscillator */
#define XT1DRIVE0_L         (0x0040)    /* XT1 Drive Level mode Bit 0 */
#define XT1DRIVE1_L         (0x0080)    /* XT1 Drive Level mode Bit 1 */
//#define RESERVED            (0x0200)    /* RESERVED */
//#define RESERVED            (0x0400)    /* RESERVED */
//#define RESERVED            (0x0800)    /* RESERVED */
//#define RESERVED            (0x2000)    /* RESERVED */

/* UCSCTL6 Control Bits */
#define XT2OFF_H            (0x0001)    /* High Frequency Oscillator 2 (XT2) disable */
//#define RESERVED            (0x0200)    /* RESERVED */
//#define RESERVED            (0x0400)    /* RESERVED */
//#define RESERVED            (0x0800)    /* RESERVED */
#define XT2BYPASS_H         (0x0010)    /* XT2 bypass mode : 0: internal 1:sourced from external pin */
//#define RESERVED            (0x2000)    /* RESERVED */
#define XT2DRIVE0_H         (0x0040)    /* XT2 Drive Level mode Bit 0 */
#define XT2DRIVE1_H         (0x0080)    /* XT2 Drive Level mode Bit 1 */

#define XCAP_0              (0x0000)    /* XIN/XOUT Cap 0 */
#define XCAP_1              (0x0004)    /* XIN/XOUT Cap 1 */
#define XCAP_2              (0x0008)    /* XIN/XOUT Cap 2 */
#define XCAP_3              (0x000C)    /* XIN/XOUT Cap 3 */
#define XT1DRIVE_0          (0x0000)    /* XT1 Drive Level mode: 0 */
#define XT1DRIVE_1          (0x0040)    /* XT1 Drive Level mode: 1 */
#define XT1DRIVE_2          (0x0080)    /* XT1 Drive Level mode: 2 */
#define XT1DRIVE_3          (0x00C0)    /* XT1 Drive Level mode: 3 */
#define XT2DRIVE_0          (0x0000)    /* XT2 Drive Level mode: 0 */
#define XT2DRIVE_1          (0x4000)    /* XT2 Drive Level mode: 1 */
#define XT2DRIVE_2          (0x8000)    /* XT2 Drive Level mode: 2 */
#define XT2DRIVE_3          (0xC000)    /* XT2 Drive Level mode: 3 */


/* UCSCTL7 Control Bits */
#define DCOFFG              (0x0001)    /* DCO Fault Flag */
#define XT1LFOFFG           (0x0002)    /* XT1 Low Frequency Oscillator Fault Flag */
#define XT1HFOFFG           (0x0004)    /* XT1 High Frequency Oscillator 1 Fault Flag */
#define XT2OFFG             (0x0008)    /* High Frequency Oscillator 2 Fault Flag */
//#define RESERVED            (0x0010)    /* RESERVED */
//#define RESERVED            (0x0020)    /* RESERVED */
//#define RESERVED            (0x0040)    /* RESERVED */
//#define RESERVED            (0x0080)    /* RESERVED */
//#define RESERVED            (0x0100)    /* RESERVED */
//#define RESERVED            (0x0200)    /* RESERVED */
//#define RESERVED            (0x0400)    /* RESERVED */
//#define RESERVED            (0x0800)    /* RESERVED */
//#define RESERVED            (0x1000)    /* RESERVED */
//#define RESERVED            (0x2000)    /* RESERVED */
//#define RESERVED            (0x4000)    /* RESERVED */
//#define RESERVED            (0x8000)    /* RESERVED */

/* UCSCTL7 Control Bits */
#define DCOFFG_L            (0x0001)    /* DCO Fault Flag */
#define XT1LFOFFG_L         (0x0002)    /* XT1 Low Frequency Oscillator Fault Flag */
#define XT1HFOFFG_L         (0x0004)    /* XT1 High Frequency Oscillator 1 Fault Flag */
#define XT2OFFG_L           (0x0008)    /* High Frequency Oscillator 2 Fault Flag */
//#define RESERVED            (0x0010)    /* RESERVED */
//#define RESERVED            (0x0020)    /* RESERVED */
//#define RESERVED            (0x0040)    /* RESERVED */
//#define RESERVED            (0x0080)    /* RESERVED */
//#define RESERVED            (0x0100)    /* RESERVED */
//#define RESERVED            (0x0200)    /* RESERVED */
//#define RESERVED            (0x0400)    /* RESERVED */
//#define RESERVED            (0x0800)    /* RESERVED */
//#define RESERVED            (0x1000)    /* RESERVED */
//#define RESERVED            (0x2000)    /* RESERVED */
//#define RESERVED            (0x4000)    /* RESERVED */
//#define RESERVED            (0x8000)    /* RESERVED */



/* UCSCTL8 Control Bits */
#define ACLKREQEN           (0x0001)    /* ACLK Clock Request Enable */
#define MCLKREQEN           (0x0002)    /* MCLK Clock Request Enable */
#define SMCLKREQEN          (0x0004)    /* SMCLK Clock Request Enable */
#define MODOSCREQEN         (0x0008)    /* MODOSC Clock Request Enable */
//#define RESERVED            (0x0010)    /* RESERVED */
//#define RESERVED            (0x0020)    /* RESERVED */
//#define RESERVED            (0x0040)    /* RESERVED */
//#define RESERVED            (0x0080)    /* RESERVED */
//#define RESERVED            (0x0100)    /* RESERVED */
//#define RESERVED            (0x0200)    /* RESERVED */
//#define RESERVED            (0x0400)    /* RESERVED */
//#define RESERVED            (0x0800)    /* RESERVED */
//#define RESERVED            (0x1000)    /* RESERVED */
//#define RESERVED            (0x2000)    /* RESERVED */
//#define RESERVED            (0x4000)    /* RESERVED */
//#define RESERVED            (0x8000)    /* RESERVED */

/* UCSCTL8 Control Bits */
#define ACLKREQEN_L         (0x0001)    /* ACLK Clock Request Enable */
#define MCLKREQEN_L         (0x0002)    /* MCLK Clock Request Enable */
#define SMCLKREQEN_L        (0x0004)    /* SMCLK Clock Request Enable */
#define MODOSCREQEN_L       (0x0008)    /* MODOSC Clock Request Enable */
//#define RESERVED            (0x0010)    /* RESERVED */
//#define RESERVED            (0x0020)    /* RESERVED */
//#define RESERVED            (0x0040)    /* RESERVED */
//#define RESERVED            (0x0080)    /* RESERVED */
//#define RESERVED            (0x0100)    /* RESERVED */
//#define RESERVED            (0x0200)    /* RESERVED */
//#define RESERVED            (0x0400)    /* RESERVED */
//#define RESERVED            (0x0800)    /* RESERVED */
//#define RESERVED            (0x1000)    /* RESERVED */
//#define RESERVED            (0x2000)    /* RESERVED */
//#define RESERVED            (0x4000)    /* RESERVED */
//#define RESERVED            (0x8000)    /* RESERVED */


#endif
/************************************************************
* UNIFIED CLOCK SYSTEM FOR Radio Devices
************************************************************/
#ifdef  __MSP430_HAS_UCS_RF__          /* Definition to show that Module is available */

#define OFS_UCSCTL0           (0x0000)  /* UCS Control Register 0 */
#define OFS_UCSCTL0_L          OFS_UCSCTL0
#define OFS_UCSCTL0_H          OFS_UCSCTL0+1
#define OFS_UCSCTL1           (0x0002)  /* UCS Control Register 1 */
#define OFS_UCSCTL1_L          OFS_UCSCTL1
#define OFS_UCSCTL1_H          OFS_UCSCTL1+1
#define OFS_UCSCTL2           (0x0004)  /* UCS Control Register 2 */
#define OFS_UCSCTL2_L          OFS_UCSCTL2
#define OFS_UCSCTL2_H          OFS_UCSCTL2+1
#define OFS_UCSCTL3           (0x0006)  /* UCS Control Register 3 */
#define OFS_UCSCTL3_L          OFS_UCSCTL3
#define OFS_UCSCTL3_H          OFS_UCSCTL3+1
#define OFS_UCSCTL4           (0x0008)  /* UCS Control Register 4 */
#define OFS_UCSCTL4_L          OFS_UCSCTL4
#define OFS_UCSCTL4_H          OFS_UCSCTL4+1
#define OFS_UCSCTL5           (0x000A)  /* UCS Control Register 5 */
#define OFS_UCSCTL5_L          OFS_UCSCTL5
#define OFS_UCSCTL5_H          OFS_UCSCTL5+1
#define OFS_UCSCTL6           (0x000C)  /* UCS Control Register 6 */
#define OFS_UCSCTL6_L          OFS_UCSCTL6
#define OFS_UCSCTL6_H          OFS_UCSCTL6+1
#define OFS_UCSCTL7           (0x000E)  /* UCS Control Register 7 */
#define OFS_UCSCTL7_L          OFS_UCSCTL7
#define OFS_UCSCTL7_H          OFS_UCSCTL7+1
#define OFS_UCSCTL8           (0x0010)  /* UCS Control Register 8 */
#define OFS_UCSCTL8_L          OFS_UCSCTL8
#define OFS_UCSCTL8_H          OFS_UCSCTL8+1

/* UCSCTL0 Control Bits */
//#define RESERVED            (0x0001)    /* RESERVED */
//#define RESERVED            (0x0002)    /* RESERVED */
//#define RESERVED            (0x0004)    /* RESERVED */
#define MOD0                (0x0008)    /* Modulation Bit Counter Bit : 0 */
#define MOD1                (0x0010)    /* Modulation Bit Counter Bit : 1 */
#define MOD2                (0x0020)    /* Modulation Bit Counter Bit : 2 */
#define MOD3                (0x0040)    /* Modulation Bit Counter Bit : 3 */
#define MOD4                (0x0080)    /* Modulation Bit Counter Bit : 4 */
#define DCO0                (0x0100)    /* DCO TAP Bit : 0 */
#define DCO1                (0x0200)    /* DCO TAP Bit : 1 */
#define DCO2                (0x0400)    /* DCO TAP Bit : 2 */
#define DCO3                (0x0800)    /* DCO TAP Bit : 3 */
#define DCO4                (0x1000)    /* DCO TAP Bit : 4 */
//#define RESERVED            (0x2000)    /* RESERVED */
//#define RESERVED            (0x4000)    /* RESERVED */
//#define RESERVED            (0x8000)    /* RESERVED */

/* UCSCTL0 Control Bits */
//#define RESERVED            (0x0001)    /* RESERVED */
//#define RESERVED            (0x0002)    /* RESERVED */
//#define RESERVED            (0x0004)    /* RESERVED */
#define MOD0_L              (0x0008)    /* Modulation Bit Counter Bit : 0 */
#define MOD1_L              (0x0010)    /* Modulation Bit Counter Bit : 1 */
#define MOD2_L              (0x0020)    /* Modulation Bit Counter Bit : 2 */
#define MOD3_L              (0x0040)    /* Modulation Bit Counter Bit : 3 */
#define MOD4_L              (0x0080)    /* Modulation Bit Counter Bit : 4 */
//#define RESERVED            (0x2000)    /* RESERVED */
//#define RESERVED            (0x4000)    /* RESERVED */
//#define RESERVED            (0x8000)    /* RESERVED */

/* UCSCTL0 Control Bits */
//#define RESERVED            (0x0001)    /* RESERVED */
//#define RESERVED            (0x0002)    /* RESERVED */
//#define RESERVED            (0x0004)    /* RESERVED */
#define DCO0_H              (0x0001)    /* DCO TAP Bit : 0 */
#define DCO1_H              (0x0002)    /* DCO TAP Bit : 1 */
#define DCO2_H              (0x0004)    /* DCO TAP Bit : 2 */
#define DCO3_H              (0x0008)    /* DCO TAP Bit : 3 */
#define DCO4_H              (0x0010)    /* DCO TAP Bit : 4 */
//#define RESERVED            (0x2000)    /* RESERVED */
//#define RESERVED            (0x4000)    /* RESERVED */
//#define RESERVED            (0x8000)    /* RESERVED */

/* UCSCTL1 Control Bits */
#define DISMOD              (0x0001)    /* Disable Modulation */
//#define RESERVED            (0x0002)    /* RESERVED */
//#define RESERVED            (0x0004)    /* RESERVED */
//#define RESERVED            (0x0008)    /* RESERVED */
#define DCORSEL0            (0x0010)    /* DCO Freq. Range Select Bit : 0 */
#define DCORSEL1            (0x0020)    /* DCO Freq. Range Select Bit : 1 */
#define DCORSEL2            (0x0040)    /* DCO Freq. Range Select Bit : 2 */
//#define RESERVED            (0x0080)    /* RESERVED */
//#define RESERVED            (0x0100)    /* RESERVED */
//#define RESERVED            (0x0200)    /* RESERVED */
//#define RESERVED            (0x0400)    /* RESERVED */
//#define RESERVED            (0x0800)    /* RESERVED */
//#define RESERVED            (0x1000)    /* RESERVED */
//#define RESERVED            (0x2000)    /* RESERVED */
//#define RESERVED            (0x4000)    /* RESERVED */
//#define RESERVED            (0x8000)    /* RESERVED */

/* UCSCTL1 Control Bits */
#define DISMOD_L            (0x0001)    /* Disable Modulation */
//#define RESERVED            (0x0002)    /* RESERVED */
//#define RESERVED            (0x0004)    /* RESERVED */
//#define RESERVED            (0x0008)    /* RESERVED */
#define DCORSEL0_L          (0x0010)    /* DCO Freq. Range Select Bit : 0 */
#define DCORSEL1_L          (0x0020)    /* DCO Freq. Range Select Bit : 1 */
#define DCORSEL2_L          (0x0040)    /* DCO Freq. Range Select Bit : 2 */
//#define RESERVED            (0x0080)    /* RESERVED */
//#define RESERVED            (0x0100)    /* RESERVED */
//#define RESERVED            (0x0200)    /* RESERVED */
//#define RESERVED            (0x0400)    /* RESERVED */
//#define RESERVED            (0x0800)    /* RESERVED */
//#define RESERVED            (0x1000)    /* RESERVED */
//#define RESERVED            (0x2000)    /* RESERVED */
//#define RESERVED            (0x4000)    /* RESERVED */
//#define RESERVED            (0x8000)    /* RESERVED */


#define DCORSEL_0           (0x0000)    /* DCO RSEL 0 */
#define DCORSEL_1           (0x0010)    /* DCO RSEL 1 */
#define DCORSEL_2           (0x0020)    /* DCO RSEL 2 */
#define DCORSEL_3           (0x0030)    /* DCO RSEL 3 */
#define DCORSEL_4           (0x0040)    /* DCO RSEL 4 */
#define DCORSEL_5           (0x0050)    /* DCO RSEL 5 */
#define DCORSEL_6           (0x0060)    /* DCO RSEL 6 */
#define DCORSEL_7           (0x0070)    /* DCO RSEL 7 */


/* UCSCTL2 Control Bits */
#define FLLN0               (0x0001)    /* FLL Multipier Bit : 0 */
#define FLLN1               (0x0002)    /* FLL Multipier Bit : 1 */
#define FLLN2               (0x0004)    /* FLL Multipier Bit : 2 */
#define FLLN3               (0x0008)    /* FLL Multipier Bit : 3 */
#define FLLN4               (0x0010)    /* FLL Multipier Bit : 4 */
#define FLLN5               (0x0020)    /* FLL Multipier Bit : 5 */
#define FLLN6               (0x0040)    /* FLL Multipier Bit : 6 */
#define FLLN7               (0x0080)    /* FLL Multipier Bit : 7 */
#define FLLN8               (0x0100)    /* FLL Multipier Bit : 8 */
#define FLLN9               (0x0200)    /* FLL Multipier Bit : 9 */
//#define RESERVED            (0x0400)    /* RESERVED */
//#define RESERVED            (0x0800)    /* RESERVED */
#define FLLD0               (0x1000)    /* Loop Divider Bit : 0 */
#define FLLD1               (0x2000)    /* Loop Divider Bit : 1 */
#define FLLD2               (0x4000)    /* Loop Divider Bit : 1 */
//#define RESERVED            (0x8000)    /* RESERVED */

/* UCSCTL2 Control Bits */
#define FLLN0_L             (0x0001)    /* FLL Multipier Bit : 0 */
#define FLLN1_L             (0x0002)    /* FLL Multipier Bit : 1 */
#define FLLN2_L             (0x0004)    /* FLL Multipier Bit : 2 */
#define FLLN3_L             (0x0008)    /* FLL Multipier Bit : 3 */
#define FLLN4_L             (0x0010)    /* FLL Multipier Bit : 4 */
#define FLLN5_L             (0x0020)    /* FLL Multipier Bit : 5 */
#define FLLN6_L             (0x0040)    /* FLL Multipier Bit : 6 */
#define FLLN7_L             (0x0080)    /* FLL Multipier Bit : 7 */
//#define RESERVED            (0x0400)    /* RESERVED */
//#define RESERVED            (0x0800)    /* RESERVED */
//#define RESERVED            (0x8000)    /* RESERVED */

/* UCSCTL2 Control Bits */
#define FLLN8_H             (0x0001)    /* FLL Multipier Bit : 8 */
#define FLLN9_H             (0x0002)    /* FLL Multipier Bit : 9 */
//#define RESERVED            (0x0400)    /* RESERVED */
//#define RESERVED            (0x0800)    /* RESERVED */
#define FLLD0_H             (0x0010)    /* Loop Divider Bit : 0 */
#define FLLD1_H             (0x0020)    /* Loop Divider Bit : 1 */
#define FLLD2_H             (0x0040)    /* Loop Divider Bit : 1 */
//#define RESERVED            (0x8000)    /* RESERVED */

#define FLLD_0             (0x0000)    /* Multiply Selected Loop Freq. 1 */
#define FLLD_1             (0x1000)    /* Multiply Selected Loop Freq. 2 */
#define FLLD_2             (0x2000)    /* Multiply Selected Loop Freq. 4 */
#define FLLD_3             (0x3000)    /* Multiply Selected Loop Freq. 8 */
#define FLLD_4             (0x4000)    /* Multiply Selected Loop Freq. 16 */
#define FLLD_5             (0x5000)    /* Multiply Selected Loop Freq. 32 */
#define FLLD_6             (0x6000)    /* Multiply Selected Loop Freq. 32 */
#define FLLD_7             (0x7000)    /* Multiply Selected Loop Freq. 32 */
#define FLLD__1            (0x0000)    /* Multiply Selected Loop Freq. By 1 */
#define FLLD__2            (0x1000)    /* Multiply Selected Loop Freq. By 2 */
#define FLLD__4            (0x2000)    /* Multiply Selected Loop Freq. By 4 */
#define FLLD__8            (0x3000)    /* Multiply Selected Loop Freq. By 8 */
#define FLLD__16           (0x4000)    /* Multiply Selected Loop Freq. By 16 */
#define FLLD__32           (0x5000)    /* Multiply Selected Loop Freq. By 32 */


/* UCSCTL3 Control Bits */
#define FLLREFDIV0          (0x0001)    /* Reference Divider Bit : 0 */
#define FLLREFDIV1          (0x0002)    /* Reference Divider Bit : 1 */
#define FLLREFDIV2          (0x0004)    /* Reference Divider Bit : 2 */
//#define RESERVED            (0x0008)    /* RESERVED */
#define SELREF0             (0x0010)    /* FLL Reference Clock Select Bit : 0 */
#define SELREF1             (0x0020)    /* FLL Reference Clock Select Bit : 1 */
#define SELREF2             (0x0040)    /* FLL Reference Clock Select Bit : 2 */
//#define RESERVED            (0x0080)    /* RESERVED */
//#define RESERVED            (0x0100)    /* RESERVED */
//#define RESERVED            (0x0200)    /* RESERVED */
//#define RESERVED            (0x0400)    /* RESERVED */
//#define RESERVED            (0x0800)    /* RESERVED */
//#define RESERVED            (0x1000)    /* RESERVED */
//#define RESERVED            (0x2000)    /* RESERVED */
//#define RESERVED            (0x4000)    /* RESERVED */
//#define RESERVED            (0x8000)    /* RESERVED */

/* UCSCTL3 Control Bits */
#define FLLREFDIV0_L        (0x0001)    /* Reference Divider Bit : 0 */
#define FLLREFDIV1_L        (0x0002)    /* Reference Divider Bit : 1 */
#define FLLREFDIV2_L        (0x0004)    /* Reference Divider Bit : 2 */
//#define RESERVED            (0x0008)    /* RESERVED */
#define SELREF0_L           (0x0010)    /* FLL Reference Clock Select Bit : 0 */
#define SELREF1_L           (0x0020)    /* FLL Reference Clock Select Bit : 1 */
#define SELREF2_L           (0x0040)    /* FLL Reference Clock Select Bit : 2 */
//#define RESERVED            (0x0080)    /* RESERVED */
//#define RESERVED            (0x0100)    /* RESERVED */
//#define RESERVED            (0x0200)    /* RESERVED */
//#define RESERVED            (0x0400)    /* RESERVED */
//#define RESERVED            (0x0800)    /* RESERVED */
//#define RESERVED            (0x1000)    /* RESERVED */
//#define RESERVED            (0x2000)    /* RESERVED */
//#define RESERVED            (0x4000)    /* RESERVED */
//#define RESERVED            (0x8000)    /* RESERVED */


#define FLLREFDIV_0         (0x0000)    /* Reference Divider: f(LFCLK)/1 */
#define FLLREFDIV_1         (0x0001)    /* Reference Divider: f(LFCLK)/2 */
#define FLLREFDIV_2         (0x0002)    /* Reference Divider: f(LFCLK)/4 */
#define FLLREFDIV_3         (0x0003)    /* Reference Divider: f(LFCLK)/8 */
#define FLLREFDIV_4         (0x0004)    /* Reference Divider: f(LFCLK)/12 */
#define FLLREFDIV_5         (0x0005)    /* Reference Divider: f(LFCLK)/16 */
#define FLLREFDIV_6         (0x0006)    /* Reference Divider: f(LFCLK)/16 */
#define FLLREFDIV_7         (0x0007)    /* Reference Divider: f(LFCLK)/16 */
#define FLLREFDIV__1        (0x0000)    /* Reference Divider: f(LFCLK)/1 */
#define FLLREFDIV__2        (0x0001)    /* Reference Divider: f(LFCLK)/2 */
#define FLLREFDIV__4        (0x0002)    /* Reference Divider: f(LFCLK)/4 */
#define FLLREFDIV__8        (0x0003)    /* Reference Divider: f(LFCLK)/8 */
#define FLLREFDIV__12       (0x0004)    /* Reference Divider: f(LFCLK)/12 */
#define FLLREFDIV__16       (0x0005)    /* Reference Divider: f(LFCLK)/16 */
#define SELREF_0            (0x0000)    /* FLL Reference Clock Select 0 */
#define SELREF_1            (0x0010)    /* FLL Reference Clock Select 1 */
#define SELREF_2            (0x0020)    /* FLL Reference Clock Select 2 */
#define SELREF_3            (0x0030)    /* FLL Reference Clock Select 3 */
#define SELREF_4            (0x0040)    /* FLL Reference Clock Select 4 */
#define SELREF_5            (0x0050)    /* FLL Reference Clock Select 5 */
#define SELREF_6            (0x0060)    /* FLL Reference Clock Select 6 */
#define SELREF_7            (0x0070)    /* FLL Reference Clock Select 7 */
#define SELREF__XT1CLK      (0x0000)    /* Multiply Selected Loop Freq. By XT1CLK */
#define SELREF__REFOCLK     (0x0020)    /* Multiply Selected Loop Freq. By REFOCLK */
#define SELREF__XT2CLK      (0x0050)    /* Multiply Selected Loop Freq. By XT2CLK */

/* UCSCTL4 Control Bits */
#define SELM0               (0x0001)   /* MCLK Source Select Bit: 0 */
#define SELM1               (0x0002)   /* MCLK Source Select Bit: 1 */
#define SELM2               (0x0004)   /* MCLK Source Select Bit: 2 */
//#define RESERVED            (0x0008)    /* RESERVED */
#define SELS0               (0x0010)   /* SMCLK Source Select Bit: 0 */
#define SELS1               (0x0020)   /* SMCLK Source Select Bit: 1 */
#define SELS2               (0x0040)   /* SMCLK Source Select Bit: 2 */
//#define RESERVED            (0x0080)    /* RESERVED */
#define SELA0               (0x0100)   /* ACLK Source Select Bit: 0 */
#define SELA1               (0x0200)   /* ACLK Source Select Bit: 1 */
#define SELA2               (0x0400)   /* ACLK Source Select Bit: 2 */
//#define RESERVED            (0x0800)    /* RESERVED */
//#define RESERVED            (0x1000)    /* RESERVED */
//#define RESERVED            (0x2000)    /* RESERVED */
//#define RESERVED            (0x4000)    /* RESERVED */
//#define RESERVED            (0x8000)    /* RESERVED */

/* UCSCTL4 Control Bits */
#define SELM0_L             (0x0001)   /* MCLK Source Select Bit: 0 */
#define SELM1_L             (0x0002)   /* MCLK Source Select Bit: 1 */
#define SELM2_L             (0x0004)   /* MCLK Source Select Bit: 2 */
//#define RESERVED            (0x0008)    /* RESERVED */
#define SELS0_L             (0x0010)   /* SMCLK Source Select Bit: 0 */
#define SELS1_L             (0x0020)   /* SMCLK Source Select Bit: 1 */
#define SELS2_L             (0x0040)   /* SMCLK Source Select Bit: 2 */
//#define RESERVED            (0x0080)    /* RESERVED */
//#define RESERVED            (0x0800)    /* RESERVED */
//#define RESERVED            (0x1000)    /* RESERVED */
//#define RESERVED            (0x2000)    /* RESERVED */
//#define RESERVED            (0x4000)    /* RESERVED */
//#define RESERVED            (0x8000)    /* RESERVED */

/* UCSCTL4 Control Bits */
//#define RESERVED            (0x0008)    /* RESERVED */
//#define RESERVED            (0x0080)    /* RESERVED */
#define SELA0_H             (0x0001)   /* ACLK Source Select Bit: 0 */
#define SELA1_H             (0x0002)   /* ACLK Source Select Bit: 1 */
#define SELA2_H             (0x0004)   /* ACLK Source Select Bit: 2 */
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
#define SELM__XT1CLK        (0x0000)   /* MCLK Source Select XT1CLK */
#define SELM__VLOCLK        (0x0001)   /* MCLK Source Select VLOCLK */
#define SELM__REFOCLK       (0x0002)   /* MCLK Source Select REFOCLK */
#define SELM__DCOCLK        (0x0003)   /* MCLK Source Select DCOCLK */
#define SELM__DCOCLKDIV     (0x0004)   /* MCLK Source Select DCOCLKDIV */
#define SELM__XT2CLK        (0x0005)   /* MCLK Source Select XT2CLK */

#define SELS_0              (0x0000)   /* SMCLK Source Select 0 */
#define SELS_1              (0x0010)   /* SMCLK Source Select 1 */
#define SELS_2              (0x0020)   /* SMCLK Source Select 2 */
#define SELS_3              (0x0030)   /* SMCLK Source Select 3 */
#define SELS_4              (0x0040)   /* SMCLK Source Select 4 */
#define SELS_5              (0x0050)   /* SMCLK Source Select 5 */
#define SELS_6              (0x0060)   /* SMCLK Source Select 6 */
#define SELS_7              (0x0070)   /* SMCLK Source Select 7 */
#define SELS__XT1CLK        (0x0000)   /* SMCLK Source Select XT1CLK */
#define SELS__VLOCLK        (0x0010)   /* SMCLK Source Select VLOCLK */
#define SELS__REFOCLK       (0x0020)   /* SMCLK Source Select REFOCLK */
#define SELS__DCOCLK        (0x0030)   /* SMCLK Source Select DCOCLK */
#define SELS__DCOCLKDIV     (0x0040)   /* SMCLK Source Select DCOCLKDIV */
#define SELS__XT2CLK        (0x0050)   /* SMCLK Source Select XT2CLK */

#define SELA_0              (0x0000)   /* ACLK Source Select 0 */
#define SELA_1              (0x0100)   /* ACLK Source Select 1 */
#define SELA_2              (0x0200)   /* ACLK Source Select 2 */
#define SELA_3              (0x0300)   /* ACLK Source Select 3 */
#define SELA_4              (0x0400)   /* ACLK Source Select 4 */
#define SELA_5              (0x0500)   /* ACLK Source Select 5 */
#define SELA_6              (0x0600)   /* ACLK Source Select 6 */
#define SELA_7              (0x0700)   /* ACLK Source Select 7 */
#define SELA__XT1CLK        (0x0000)   /* ACLK Source Select XT1CLK */
#define SELA__VLOCLK        (0x0100)   /* ACLK Source Select VLOCLK */
#define SELA__REFOCLK       (0x0200)   /* ACLK Source Select REFOCLK */
#define SELA__DCOCLK        (0x0300)   /* ACLK Source Select DCOCLK */
#define SELA__DCOCLKDIV     (0x0400)   /* ACLK Source Select DCOCLKDIV */
#define SELA__XT2CLK        (0x0500)   /* ACLK Source Select XT2CLK */

/* UCSCTL5 Control Bits */
#define DIVM0               (0x0001)   /* MCLK Divider Bit: 0 */
#define DIVM1               (0x0002)   /* MCLK Divider Bit: 1 */
#define DIVM2               (0x0004)   /* MCLK Divider Bit: 2 */
//#define RESERVED            (0x0008)    /* RESERVED */
#define DIVS0               (0x0010)   /* SMCLK Divider Bit: 0 */
#define DIVS1               (0x0020)   /* SMCLK Divider Bit: 1 */
#define DIVS2               (0x0040)   /* SMCLK Divider Bit: 2 */
//#define RESERVED            (0x0080)    /* RESERVED */
#define DIVA0               (0x0100)   /* ACLK Divider Bit: 0 */
#define DIVA1               (0x0200)   /* ACLK Divider Bit: 1 */
#define DIVA2               (0x0400)   /* ACLK Divider Bit: 2 */
//#define RESERVED            (0x0800)    /* RESERVED */
#define DIVPA0              (0x1000)   /* ACLK from Pin Divider Bit: 0 */
#define DIVPA1              (0x2000)   /* ACLK from Pin Divider Bit: 1 */
#define DIVPA2              (0x4000)   /* ACLK from Pin Divider Bit: 2 */
//#define RESERVED            (0x8000)    /* RESERVED */

/* UCSCTL5 Control Bits */
#define DIVM0_L             (0x0001)   /* MCLK Divider Bit: 0 */
#define DIVM1_L             (0x0002)   /* MCLK Divider Bit: 1 */
#define DIVM2_L             (0x0004)   /* MCLK Divider Bit: 2 */
//#define RESERVED            (0x0008)    /* RESERVED */
#define DIVS0_L             (0x0010)   /* SMCLK Divider Bit: 0 */
#define DIVS1_L             (0x0020)   /* SMCLK Divider Bit: 1 */
#define DIVS2_L             (0x0040)   /* SMCLK Divider Bit: 2 */
//#define RESERVED            (0x0080)    /* RESERVED */
//#define RESERVED            (0x0800)    /* RESERVED */
//#define RESERVED            (0x8000)    /* RESERVED */

/* UCSCTL5 Control Bits */
//#define RESERVED            (0x0008)    /* RESERVED */
//#define RESERVED            (0x0080)    /* RESERVED */
#define DIVA0_H             (0x0001)   /* ACLK Divider Bit: 0 */
#define DIVA1_H             (0x0002)   /* ACLK Divider Bit: 1 */
#define DIVA2_H             (0x0004)   /* ACLK Divider Bit: 2 */
//#define RESERVED            (0x0800)    /* RESERVED */
#define DIVPA0_H            (0x0010)   /* ACLK from Pin Divider Bit: 0 */
#define DIVPA1_H            (0x0020)   /* ACLK from Pin Divider Bit: 1 */
#define DIVPA2_H            (0x0040)   /* ACLK from Pin Divider Bit: 2 */
//#define RESERVED            (0x8000)    /* RESERVED */

#define DIVM_0              (0x0000)    /* MCLK Source Divider 0 */
#define DIVM_1              (0x0001)    /* MCLK Source Divider 1 */
#define DIVM_2              (0x0002)    /* MCLK Source Divider 2 */
#define DIVM_3              (0x0003)    /* MCLK Source Divider 3 */
#define DIVM_4              (0x0004)    /* MCLK Source Divider 4 */
#define DIVM_5              (0x0005)    /* MCLK Source Divider 5 */
#define DIVM_6              (0x0006)    /* MCLK Source Divider 6 */
#define DIVM_7              (0x0007)    /* MCLK Source Divider 7 */
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
#define DIVS_6              (0x0060)    /* SMCLK Source Divider 6 */
#define DIVS_7              (0x0070)    /* SMCLK Source Divider 7 */
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
#define DIVA_6              (0x0600)    /* ACLK Source Divider 6 */
#define DIVA_7              (0x0700)    /* ACLK Source Divider 7 */
#define DIVA__1             (0x0000)    /* ACLK Source Divider f(ACLK)/1 */
#define DIVA__2             (0x0100)    /* ACLK Source Divider f(ACLK)/2 */
#define DIVA__4             (0x0200)    /* ACLK Source Divider f(ACLK)/4 */
#define DIVA__8             (0x0300)    /* ACLK Source Divider f(ACLK)/8 */
#define DIVA__16            (0x0400)    /* ACLK Source Divider f(ACLK)/16 */
#define DIVA__32            (0x0500)    /* ACLK Source Divider f(ACLK)/32 */

#define DIVPA_0             (0x0000)    /* ACLK from Pin Source Divider 0 */
#define DIVPA_1             (0x1000)    /* ACLK from Pin Source Divider 1 */
#define DIVPA_2             (0x2000)    /* ACLK from Pin Source Divider 2 */
#define DIVPA_3             (0x3000)    /* ACLK from Pin Source Divider 3 */
#define DIVPA_4             (0x4000)    /* ACLK from Pin Source Divider 4 */
#define DIVPA_5             (0x5000)    /* ACLK from Pin Source Divider 5 */
#define DIVPA_6             (0x6000)    /* ACLK from Pin Source Divider 6 */
#define DIVPA_7             (0x7000)    /* ACLK from Pin Source Divider 7 */
#define DIVPA__1            (0x0000)    /* ACLK from Pin Source Divider f(ACLK)/1 */
#define DIVPA__2            (0x1000)    /* ACLK from Pin Source Divider f(ACLK)/2 */
#define DIVPA__4            (0x2000)    /* ACLK from Pin Source Divider f(ACLK)/4 */
#define DIVPA__8            (0x3000)    /* ACLK from Pin Source Divider f(ACLK)/8 */
#define DIVPA__16           (0x4000)    /* ACLK from Pin Source Divider f(ACLK)/16 */
#define DIVPA__32           (0x5000)    /* ACLK from Pin Source Divider f(ACLK)/32 */


/* UCSCTL6 Control Bits */
#define XT1OFF              (0x0001)    /* High Frequency Oscillator 1 (XT1) disable */
#define SMCLKOFF            (0x0002)    /* SMCLK Off */
#define XCAP0               (0x0004)    /* XIN/XOUT Cap Bit: 0 */
#define XCAP1               (0x0008)    /* XIN/XOUT Cap Bit: 1 */
#define XT1BYPASS           (0x0010)    /* XT1 bypass mode : 0: internal 1:sourced from external pin */
#define XTS                 (0x0020)    /* 1: Selects high-freq. oscillator */
#define XT1DRIVE0           (0x0040)    /* XT1 Drive Level mode Bit 0 */
#define XT1DRIVE1           (0x0080)    /* XT1 Drive Level mode Bit 1 */
#define XT2OFF              (0x0100)    /* High Frequency Oscillator 2 (XT2) disable */
//#define RESERVED            (0x0200)    /* RESERVED */
//#define RESERVED            (0x0400)    /* RESERVED */
//#define RESERVED            (0x0800)    /* RESERVED */
//#define RESERVED            (0x1000)    /* RESERVED */
//#define RESERVED            (0x2000)    /* RESERVED */
//#define RESERVED            (0x4000)    /* RESERVED */
//#define RESERVED            (0x8000)    /* RESERVED */

/* UCSCTL6 Control Bits */
#define XT1OFF_L            (0x0001)    /* High Frequency Oscillator 1 (XT1) disable */
#define SMCLKOFF_L          (0x0002)    /* SMCLK Off */
#define XCAP0_L             (0x0004)    /* XIN/XOUT Cap Bit: 0 */
#define XCAP1_L             (0x0008)    /* XIN/XOUT Cap Bit: 1 */
#define XT1BYPASS_L         (0x0010)    /* XT1 bypass mode : 0: internal 1:sourced from external pin */
#define XTS_L               (0x0020)    /* 1: Selects high-freq. oscillator */
#define XT1DRIVE0_L         (0x0040)    /* XT1 Drive Level mode Bit 0 */
#define XT1DRIVE1_L         (0x0080)    /* XT1 Drive Level mode Bit 1 */
//#define RESERVED            (0x0200)    /* RESERVED */
//#define RESERVED            (0x0400)    /* RESERVED */
//#define RESERVED            (0x0800)    /* RESERVED */
//#define RESERVED            (0x1000)    /* RESERVED */
//#define RESERVED            (0x2000)    /* RESERVED */
//#define RESERVED            (0x4000)    /* RESERVED */
//#define RESERVED            (0x8000)    /* RESERVED */

/* UCSCTL6 Control Bits */
#define XT2OFF_H            (0x0001)    /* High Frequency Oscillator 2 (XT2) disable */
//#define RESERVED            (0x0200)    /* RESERVED */
//#define RESERVED            (0x0400)    /* RESERVED */
//#define RESERVED            (0x0800)    /* RESERVED */
//#define RESERVED            (0x1000)    /* RESERVED */
//#define RESERVED            (0x2000)    /* RESERVED */
//#define RESERVED            (0x4000)    /* RESERVED */
//#define RESERVED            (0x8000)    /* RESERVED */

#define XCAP_0              (0x0000)    /* XIN/XOUT Cap 0 */
#define XCAP_1              (0x0004)    /* XIN/XOUT Cap 1 */
#define XCAP_2              (0x0008)    /* XIN/XOUT Cap 2 */
#define XCAP_3              (0x000C)    /* XIN/XOUT Cap 3 */
#define XT1DRIVE_0          (0x0000)    /* XT1 Drive Level mode: 0 */
#define XT1DRIVE_1          (0x0040)    /* XT1 Drive Level mode: 1 */
#define XT1DRIVE_2          (0x0080)    /* XT1 Drive Level mode: 2 */
#define XT1DRIVE_3          (0x00C0)    /* XT1 Drive Level mode: 3 */


/* UCSCTL7 Control Bits */
#define DCOFFG              (0x0001)    /* DCO Fault Flag */
#define XT1LFOFFG           (0x0002)    /* XT1 Low Frequency Oscillator Fault Flag */
#define XT1HFOFFG           (0x0004)    /* XT1 High Frequency Oscillator 1 Fault Flag */
#define XT2OFFG             (0x0008)    /* High Frequency Oscillator 2 Fault Flag */
//#define RESERVED            (0x0010)    /* RESERVED */
//#define RESERVED            (0x0020)    /* RESERVED */
//#define RESERVED            (0x0040)    /* RESERVED */
//#define RESERVED            (0x0080)    /* RESERVED */
//#define RESERVED            (0x0100)    /* RESERVED */
//#define RESERVED            (0x0200)    /* RESERVED */
//#define RESERVED            (0x0400)    /* RESERVED */
//#define RESERVED            (0x0800)    /* RESERVED */
//#define RESERVED            (0x1000)    /* RESERVED */
//#define RESERVED            (0x2000)    /* RESERVED */
//#define RESERVED            (0x4000)    /* RESERVED */
//#define RESERVED            (0x8000)    /* RESERVED */

/* UCSCTL7 Control Bits */
#define DCOFFG_L            (0x0001)    /* DCO Fault Flag */
#define XT1LFOFFG_L         (0x0002)    /* XT1 Low Frequency Oscillator Fault Flag */
#define XT1HFOFFG_L         (0x0004)    /* XT1 High Frequency Oscillator 1 Fault Flag */
#define XT2OFFG_L           (0x0008)    /* High Frequency Oscillator 2 Fault Flag */
//#define RESERVED            (0x0010)    /* RESERVED */
//#define RESERVED            (0x0020)    /* RESERVED */
//#define RESERVED            (0x0040)    /* RESERVED */
//#define RESERVED            (0x0080)    /* RESERVED */
//#define RESERVED            (0x0100)    /* RESERVED */
//#define RESERVED            (0x0200)    /* RESERVED */
//#define RESERVED            (0x0400)    /* RESERVED */
//#define RESERVED            (0x0800)    /* RESERVED */
//#define RESERVED            (0x1000)    /* RESERVED */
//#define RESERVED            (0x2000)    /* RESERVED */
//#define RESERVED            (0x4000)    /* RESERVED */
//#define RESERVED            (0x8000)    /* RESERVED */



/* UCSCTL8 Control Bits */
#define ACLKREQEN           (0x0001)    /* ACLK Clock Request Enable */
#define MCLKREQEN           (0x0002)    /* MCLK Clock Request Enable */
#define SMCLKREQEN          (0x0004)    /* SMCLK Clock Request Enable */
#define MODOSCREQEN         (0x0008)    /* MODOSC Clock Request Enable */
//#define RESERVED            (0x0010)    /* RESERVED */
//#define RESERVED            (0x0020)    /* RESERVED */
//#define RESERVED            (0x0040)    /* RESERVED */
//#define RESERVED            (0x0080)    /* RESERVED */
//#define RESERVED            (0x0100)    /* RESERVED */
//#define RESERVED            (0x0200)    /* RESERVED */
//#define RESERVED            (0x0400)    /* RESERVED */
//#define RESERVED            (0x0800)    /* RESERVED */
//#define RESERVED            (0x1000)    /* RESERVED */
//#define RESERVED            (0x2000)    /* RESERVED */
//#define RESERVED            (0x4000)    /* RESERVED */
//#define RESERVED            (0x8000)    /* RESERVED */

/* UCSCTL8 Control Bits */
#define ACLKREQEN_L         (0x0001)    /* ACLK Clock Request Enable */
#define MCLKREQEN_L         (0x0002)    /* MCLK Clock Request Enable */
#define SMCLKREQEN_L        (0x0004)    /* SMCLK Clock Request Enable */
#define MODOSCREQEN_L       (0x0008)    /* MODOSC Clock Request Enable */
//#define RESERVED            (0x0010)    /* RESERVED */
//#define RESERVED            (0x0020)    /* RESERVED */
//#define RESERVED            (0x0040)    /* RESERVED */
//#define RESERVED            (0x0080)    /* RESERVED */
//#define RESERVED            (0x0100)    /* RESERVED */
//#define RESERVED            (0x0200)    /* RESERVED */
//#define RESERVED            (0x0400)    /* RESERVED */
//#define RESERVED            (0x0800)    /* RESERVED */
//#define RESERVED            (0x1000)    /* RESERVED */
//#define RESERVED            (0x2000)    /* RESERVED */
//#define RESERVED            (0x4000)    /* RESERVED */
//#define RESERVED            (0x8000)    /* RESERVED */


#endif
/************************************************************
* USB
************************************************************/
#ifdef  __MSP430_HAS_USB__            /* Definition to show that Module is available */

/* ========================================================================= */
/* USB Configuration Registers */
/* ========================================================================= */
#define OFS_USBKEYID          (0x0000)    /* USB Controller key register */
#define OFS_USBKEYID_L         OFS_USBKEYID
#define OFS_USBKEYID_H         OFS_USBKEYID+1
#define OFS_USBCNF            (0x0002)    /* USB Module  configuration register */
#define OFS_USBCNF_L           OFS_USBCNF
#define OFS_USBCNF_H           OFS_USBCNF+1
#define OFS_USBPHYCTL         (0x0004)    /* USB PHY control register */
#define OFS_USBPHYCTL_L        OFS_USBPHYCTL
#define OFS_USBPHYCTL_H        OFS_USBPHYCTL+1
#define OFS_USBPWRCTL         (0x0008)    /* USB Power control register */
#define OFS_USBPWRCTL_L        OFS_USBPWRCTL
#define OFS_USBPWRCTL_H        OFS_USBPWRCTL+1
#define OFS_USBPLLCTL         (0x0010)    /* USB PLL control register */
#define OFS_USBPLLCTL_L        OFS_USBPLLCTL
#define OFS_USBPLLCTL_H        OFS_USBPLLCTL+1
#define OFS_USBPLLDIVB        (0x0012)    /* USB PLL Clock Divider Buffer control register */
#define OFS_USBPLLDIVB_L       OFS_USBPLLDIVB
#define OFS_USBPLLDIVB_H       OFS_USBPLLDIVB+1
#define OFS_USBPLLIR          (0x0014)    /* USB PLL Interrupt control register */
#define OFS_USBPLLIR_L         OFS_USBPLLIR
#define OFS_USBPLLIR_H         OFS_USBPLLIR+1

#define USBKEYPID      USBKEYID    /* Legacy Definition: USB Controller key register */
#define USBKEY         (0x9628)    /* USB Control Register key */

/* USBCNF Control Bits */
#define USB_EN              (0x0001)  /* USB - Module enable */
#define PUR_EN              (0x0002)  /* USB - PUR pin enable */
#define PUR_IN              (0x0004)  /* USB - PUR pin input value */
#define BLKRDY              (0x0008)  /* USB - Block ready signal for DMA */
#define FNTEN               (0x0010)  /* USB - Frame Number receive Trigger enable for DMA */
//#define RESERVED            (0x0020)  /* USB -  */
//#define RESERVED            (0x0040)  /* USB -  */
//#define RESERVED            (0x0080)  /* USB -  */
//#define RESERVED            (0x0100)  /* USB -  */
//#define RESERVED            (0x0200)  /* USB -  */
//#define RESERVED            (0x0400)  /* USB -  */
//#define RESERVED            (0x0800)  /* USB -  */
//#define RESERVED            (0x1000)  /* USB -  */
//#define RESERVED            (0x2000)  /* USB -  */
//#define RESERVED            (0x4000)  /* USB -  */
//#define RESERVED            (0x8000)  /* USB -  */

/* USBCNF Control Bits */
#define USB_EN_L            (0x0001)  /* USB - Module enable */
#define PUR_EN_L            (0x0002)  /* USB - PUR pin enable */
#define PUR_IN_L            (0x0004)  /* USB - PUR pin input value */
#define BLKRDY_L            (0x0008)  /* USB - Block ready signal for DMA */
#define FNTEN_L             (0x0010)  /* USB - Frame Number receive Trigger enable for DMA */
//#define RESERVED            (0x0020)  /* USB -  */
//#define RESERVED            (0x0040)  /* USB -  */
//#define RESERVED            (0x0080)  /* USB -  */
//#define RESERVED            (0x0100)  /* USB -  */
//#define RESERVED            (0x0200)  /* USB -  */
//#define RESERVED            (0x0400)  /* USB -  */
//#define RESERVED            (0x0800)  /* USB -  */
//#define RESERVED            (0x1000)  /* USB -  */
//#define RESERVED            (0x2000)  /* USB -  */
//#define RESERVED            (0x4000)  /* USB -  */
//#define RESERVED            (0x8000)  /* USB -  */


/* USBPHYCTL Control Bits */
#define PUOUT0              (0x0001)  /* USB - USB Port Output Signal Bit 0 */
#define PUOUT1              (0x0002)  /* USB - USB Port Output Signal Bit 1 */
#define PUIN0               (0x0004)  /* USB - PU0/DP Input Data */
#define PUIN1               (0x0008)  /* USB - PU1/DM Input Data */
//#define RESERVED            (0x0010)  /* USB -  */
#define PUOPE               (0x0020)  /* USB - USB Port Output Enable */
//#define RESERVED            (0x0040)  /* USB -  */
#define PUSEL               (0x0080)  /* USB - USB Port Function Select */
#define PUIPE               (0x0100)  /* USB - PHY Single Ended Input enable */
//#define RESERVED            (0x0200)  /* USB -  */
//#define RESERVED            (0x0100)  /* USB -  */
//#define RESERVED            (0x0200)  /* USB -  */
//#define RESERVED            (0x0400)  /* USB -  */
//#define RESERVED            (0x0800)  /* USB -  */
//#define RESERVED            (0x1000)  /* USB -  */
//#define RESERVED            (0x2000)  /* USB -  */
//#define RESERVED            (0x4000)  /* USB -  */
//#define RESERVED            (0x8000)  /* USB -  */

/* USBPHYCTL Control Bits */
#define PUOUT0_L            (0x0001)  /* USB - USB Port Output Signal Bit 0 */
#define PUOUT1_L            (0x0002)  /* USB - USB Port Output Signal Bit 1 */
#define PUIN0_L             (0x0004)  /* USB - PU0/DP Input Data */
#define PUIN1_L             (0x0008)  /* USB - PU1/DM Input Data */
//#define RESERVED            (0x0010)  /* USB -  */
#define PUOPE_L             (0x0020)  /* USB - USB Port Output Enable */
//#define RESERVED            (0x0040)  /* USB -  */
#define PUSEL_L             (0x0080)  /* USB - USB Port Function Select */
//#define RESERVED            (0x0200)  /* USB -  */
//#define RESERVED            (0x0100)  /* USB -  */
//#define RESERVED            (0x0200)  /* USB -  */
//#define RESERVED            (0x0400)  /* USB -  */
//#define RESERVED            (0x0800)  /* USB -  */
//#define RESERVED            (0x1000)  /* USB -  */
//#define RESERVED            (0x2000)  /* USB -  */
//#define RESERVED            (0x4000)  /* USB -  */
//#define RESERVED            (0x8000)  /* USB -  */

/* USBPHYCTL Control Bits */
//#define RESERVED            (0x0010)  /* USB -  */
//#define RESERVED            (0x0040)  /* USB -  */
#define PUIPE_H             (0x0001)  /* USB - PHY Single Ended Input enable */
//#define RESERVED            (0x0200)  /* USB -  */
//#define RESERVED            (0x0100)  /* USB -  */
//#define RESERVED            (0x0200)  /* USB -  */
//#define RESERVED            (0x0400)  /* USB -  */
//#define RESERVED            (0x0800)  /* USB -  */
//#define RESERVED            (0x1000)  /* USB -  */
//#define RESERVED            (0x2000)  /* USB -  */
//#define RESERVED            (0x4000)  /* USB -  */
//#define RESERVED            (0x8000)  /* USB -  */

#define PUDIR               (0x0020)  /* USB - Legacy Definition: USB Port Output Enable */
#define PSEIEN              (0x0100)  /* USB - Legacy Definition: PHY Single Ended Input enable */

/* USBPWRCTL Control Bits */
#define VUOVLIFG            (0x0001)  /* USB - VUSB Overload Interrupt Flag */
#define VBONIFG             (0x0002)  /* USB - VBUS "Coming ON" Interrupt Flag */
#define VBOFFIFG            (0x0004)  /* USB - VBUS "Going OFF" Interrupt Flag */
#define USBBGVBV            (0x0008)  /* USB - USB Bandgap and VBUS valid */
#define USBDETEN            (0x0010)  /* USB - VBUS on/off events enable */
#define OVLAOFF             (0x0020)  /* USB - LDO overload auto off enable */
#define SLDOAON             (0x0040)  /* USB - Secondary LDO auto on enable */
//#define RESERVED            (0x0080)  /* USB -  */
#define VUOVLIE             (0x0100)  /* USB - Overload indication Interrupt Enable */
#define VBONIE              (0x0200)  /* USB - VBUS "Coming ON" Interrupt Enable */
#define VBOFFIE             (0x0400)  /* USB - VBUS "Going OFF" Interrupt Enable */
#define VUSBEN              (0x0800)  /* USB - LDO Enable (3.3V) */
#define SLDOEN              (0x1000)  /* USB - Secondary LDO Enable (1.8V) */
//#define RESERVED            (0x2000)  /* USB -  */
//#define RESERVED            (0x4000)  /* USB -  */
//#define RESERVED            (0x8000)  /* USB -  */

/* USBPWRCTL Control Bits */
#define VUOVLIFG_L          (0x0001)  /* USB - VUSB Overload Interrupt Flag */
#define VBONIFG_L           (0x0002)  /* USB - VBUS "Coming ON" Interrupt Flag */
#define VBOFFIFG_L          (0x0004)  /* USB - VBUS "Going OFF" Interrupt Flag */
#define USBBGVBV_L          (0x0008)  /* USB - USB Bandgap and VBUS valid */
#define USBDETEN_L          (0x0010)  /* USB - VBUS on/off events enable */
#define OVLAOFF_L           (0x0020)  /* USB - LDO overload auto off enable */
#define SLDOAON_L           (0x0040)  /* USB - Secondary LDO auto on enable */
//#define RESERVED            (0x0080)  /* USB -  */
//#define RESERVED            (0x2000)  /* USB -  */
//#define RESERVED            (0x4000)  /* USB -  */
//#define RESERVED            (0x8000)  /* USB -  */

/* USBPWRCTL Control Bits */
//#define RESERVED            (0x0080)  /* USB -  */
#define VUOVLIE_H           (0x0001)  /* USB - Overload indication Interrupt Enable */
#define VBONIE_H            (0x0002)  /* USB - VBUS "Coming ON" Interrupt Enable */
#define VBOFFIE_H           (0x0004)  /* USB - VBUS "Going OFF" Interrupt Enable */
#define VUSBEN_H            (0x0008)  /* USB - LDO Enable (3.3V) */
#define SLDOEN_H            (0x0010)  /* USB - Secondary LDO Enable (1.8V) */
//#define RESERVED            (0x2000)  /* USB -  */
//#define RESERVED            (0x4000)  /* USB -  */
//#define RESERVED            (0x8000)  /* USB -  */


/* USBPLLCTL Control Bits */
//#define RESERVED            (0x0001)  /* USB -  */
//#define RESERVED            (0x0002)  /* USB -  */
//#define RESERVED            (0x0004)  /* USB -  */
//#define RESERVED            (0x0008)  /* USB -  */
//#define RESERVED            (0x0010)  /* USB -  */
//#define RESERVED            (0x0020)  /* USB -  */
#define UCLKSEL0            (0x0040)  /* USB - Module Clock Select Bit 0 */
#define UCLKSEL1            (0x0080)  /* USB - Module Clock Select Bit 1 */
#define UPLLEN              (0x0100)  /* USB - PLL enable */
#define UPFDEN              (0x0200)  /* USB - Phase Freq. Discriminator enable */
//#define RESERVED            (0x0400)  /* USB -  */
//#define RESERVED            (0x0800)  /* USB -  */
//#define RESERVED            (0x1000)  /* USB -  */
//#define RESERVED            (0x2000)  /* USB -  */
//#define RESERVED            (0x4000)  /* USB -  */
//#define RESERVED            (0x8000)  /* USB -  */

/* USBPLLCTL Control Bits */
//#define RESERVED            (0x0001)  /* USB -  */
//#define RESERVED            (0x0002)  /* USB -  */
//#define RESERVED            (0x0004)  /* USB -  */
//#define RESERVED            (0x0008)  /* USB -  */
//#define RESERVED            (0x0010)  /* USB -  */
//#define RESERVED            (0x0020)  /* USB -  */
#define UCLKSEL0_L          (0x0040)  /* USB - Module Clock Select Bit 0 */
#define UCLKSEL1_L          (0x0080)  /* USB - Module Clock Select Bit 1 */
//#define RESERVED            (0x0400)  /* USB -  */
//#define RESERVED            (0x0800)  /* USB -  */
//#define RESERVED            (0x1000)  /* USB -  */
//#define RESERVED            (0x2000)  /* USB -  */
//#define RESERVED            (0x4000)  /* USB -  */
//#define RESERVED            (0x8000)  /* USB -  */

/* USBPLLCTL Control Bits */
//#define RESERVED            (0x0001)  /* USB -  */
//#define RESERVED            (0x0002)  /* USB -  */
//#define RESERVED            (0x0004)  /* USB -  */
//#define RESERVED            (0x0008)  /* USB -  */
//#define RESERVED            (0x0010)  /* USB -  */
//#define RESERVED            (0x0020)  /* USB -  */
#define UPLLEN_H            (0x0001)  /* USB - PLL enable */
#define UPFDEN_H            (0x0002)  /* USB - Phase Freq. Discriminator enable */
//#define RESERVED            (0x0400)  /* USB -  */
//#define RESERVED            (0x0800)  /* USB -  */
//#define RESERVED            (0x1000)  /* USB -  */
//#define RESERVED            (0x2000)  /* USB -  */
//#define RESERVED            (0x4000)  /* USB -  */
//#define RESERVED            (0x8000)  /* USB -  */

#define UCLKSEL_0           (0x0000)  /* USB - Module Clock Select: 0 */
#define UCLKSEL_1           (0x0040)  /* USB - Module Clock Select: 1 */
#define UCLKSEL_2           (0x0080)  /* USB - Module Clock Select: 2 */
#define UCLKSEL_3           (0x00C0)  /* USB - Module Clock Select: 3 (Reserved) */

#define UCLKSEL__PLLCLK     (0x0000)  /* USB - Module Clock Select: PLLCLK */
#define UCLKSEL__XT1CLK     (0x0040)  /* USB - Module Clock Select: XT1CLK */
#define UCLKSEL__XT2CLK     (0x0080)  /* USB - Module Clock Select: XT2CLK */

/* USBPLLDIVB Control Bits */
#define UPMB0               (0x0001)  /* USB - PLL feedback divider buffer Bit 0 */
#define UPMB1               (0x0002)  /* USB - PLL feedback divider buffer Bit 1 */
#define UPMB2               (0x0004)  /* USB - PLL feedback divider buffer Bit 2 */
#define UPMB3               (0x0008)  /* USB - PLL feedback divider buffer Bit 3 */
#define UPMB4               (0x0010)  /* USB - PLL feedback divider buffer Bit 4 */
#define UPMB5               (0x0020)  /* USB - PLL feedback divider buffer Bit 5 */
//#define RESERVED            (0x0040)  /* USB -  */
//#define RESERVED            (0x0080)  /* USB -  */
#define UPQB0               (0x0100)  /* USB - PLL prescale divider buffer Bit 0 */
#define UPQB1               (0x0200)  /* USB - PLL prescale divider buffer Bit 1 */
#define UPQB2               (0x0400)  /* USB - PLL prescale divider buffer Bit 2 */
//#define RESERVED            (0x0800)  /* USB -  */
//#define RESERVED            (0x1000)  /* USB -  */
//#define RESERVED            (0x2000)  /* USB -  */
//#define RESERVED            (0x4000)  /* USB -  */
//#define RESERVED            (0x8000)  /* USB -  */

/* USBPLLDIVB Control Bits */
#define UPMB0_L             (0x0001)  /* USB - PLL feedback divider buffer Bit 0 */
#define UPMB1_L             (0x0002)  /* USB - PLL feedback divider buffer Bit 1 */
#define UPMB2_L             (0x0004)  /* USB - PLL feedback divider buffer Bit 2 */
#define UPMB3_L             (0x0008)  /* USB - PLL feedback divider buffer Bit 3 */
#define UPMB4_L             (0x0010)  /* USB - PLL feedback divider buffer Bit 4 */
#define UPMB5_L             (0x0020)  /* USB - PLL feedback divider buffer Bit 5 */
//#define RESERVED            (0x0040)  /* USB -  */
//#define RESERVED            (0x0080)  /* USB -  */
//#define RESERVED            (0x0800)  /* USB -  */
//#define RESERVED            (0x1000)  /* USB -  */
//#define RESERVED            (0x2000)  /* USB -  */
//#define RESERVED            (0x4000)  /* USB -  */
//#define RESERVED            (0x8000)  /* USB -  */

/* USBPLLDIVB Control Bits */
//#define RESERVED            (0x0040)  /* USB -  */
//#define RESERVED            (0x0080)  /* USB -  */
#define UPQB0_H             (0x0001)  /* USB - PLL prescale divider buffer Bit 0 */
#define UPQB1_H             (0x0002)  /* USB - PLL prescale divider buffer Bit 1 */
#define UPQB2_H             (0x0004)  /* USB - PLL prescale divider buffer Bit 2 */
//#define RESERVED            (0x0800)  /* USB -  */
//#define RESERVED            (0x1000)  /* USB -  */
//#define RESERVED            (0x2000)  /* USB -  */
//#define RESERVED            (0x4000)  /* USB -  */
//#define RESERVED            (0x8000)  /* USB -  */

#define USBPLL_SETCLK_1_5      (UPMB0*31 | UPQB0*0)  /* USB - PLL Set for 1.5 MHz input clock */
#define USBPLL_SETCLK_1_6      (UPMB0*29 | UPQB0*0)  /* USB - PLL Set for 1.6 MHz input clock */
#define USBPLL_SETCLK_1_7778   (UPMB0*26 | UPQB0*0)  /* USB - PLL Set for 1.7778 MHz input clock */
#define USBPLL_SETCLK_1_8432   (UPMB0*25 | UPQB0*0)  /* USB - PLL Set for 1.8432 MHz input clock */
#define USBPLL_SETCLK_1_8461   (UPMB0*25 | UPQB0*0)  /* USB - PLL Set for 1.8461 MHz input clock */
#define USBPLL_SETCLK_1_92     (UPMB0*24 | UPQB0*0)  /* USB - PLL Set for 1.92 MHz input clock */
#define USBPLL_SETCLK_2_0      (UPMB0*23 | UPQB0*0)  /* USB - PLL Set for 2.0 MHz input clock */
#define USBPLL_SETCLK_2_4      (UPMB0*19 | UPQB0*0)  /* USB - PLL Set for 2.4 MHz input clock */
#define USBPLL_SETCLK_2_6667   (UPMB0*17 | UPQB0*0)  /* USB - PLL Set for 2.6667 MHz input clock */
#define USBPLL_SETCLK_3_0      (UPMB0*15 | UPQB0*0)  /* USB - PLL Set for 3.0 MHz input clock */
#define USBPLL_SETCLK_3_2      (UPMB0*29 | UPQB0*1)  /* USB - PLL Set for 3.2 MHz input clock */
#define USBPLL_SETCLK_3_5556   (UPMB0*26 | UPQB0*1)  /* USB - PLL Set for 3.5556 MHz input clock */
#define USBPLL_SETCLK_3_579545 (UPMB0*26 | UPQB0*1)  /* USB - PLL Set for 3.579546 MHz input clock */
#define USBPLL_SETCLK_3_84     (UPMB0*24 | UPQB0*1)  /* USB - PLL Set for 3.84 MHz input clock */
#define USBPLL_SETCLK_4_0      (UPMB0*23 | UPQB0*1)  /* USB - PLL Set for 4.0 MHz input clock */
#define USBPLL_SETCLK_4_1739   (UPMB0*22 | UPQB0*1)  /* USB - PLL Set for 4.1739 MHz input clock */
#define USBPLL_SETCLK_4_1943   (UPMB0*22 | UPQB0*1)  /* USB - PLL Set for 4.1943 MHz input clock */
#define USBPLL_SETCLK_4_332    (UPMB0*21 | UPQB0*1)  /* USB - PLL Set for 4.332 MHz input clock */
#define USBPLL_SETCLK_4_3636   (UPMB0*21 | UPQB0*1)  /* USB - PLL Set for 4.3636 MHz input clock */
#define USBPLL_SETCLK_4_5      (UPMB0*31 | UPQB0*2)  /* USB - PLL Set for 4.5 MHz input clock */
#define USBPLL_SETCLK_4_8      (UPMB0*19 | UPQB0*1)  /* USB - PLL Set for 4.8 MHz input clock */
#define USBPLL_SETCLK_5_33     (UPMB0*17 | UPQB0*1)  /* USB - PLL Set for 5.33 MHz input clock */
#define USBPLL_SETCLK_5_76     (UPMB0*24 | UPQB0*2)  /* USB - PLL Set for 5.76 MHz input clock */
#define USBPLL_SETCLK_6_0      (UPMB0*23 | UPQB0*2)  /* USB - PLL Set for 6.0 MHz input clock */
#define USBPLL_SETCLK_6_4      (UPMB0*29 | UPQB0*3)  /* USB - PLL Set for 6.4 MHz input clock */
#define USBPLL_SETCLK_7_2      (UPMB0*19 | UPQB0*2)  /* USB - PLL Set for 7.2 MHz input clock */
#define USBPLL_SETCLK_7_68     (UPMB0*24 | UPQB0*3)  /* USB - PLL Set for 7.68 MHz input clock */
#define USBPLL_SETCLK_8_0      (UPMB0*17 | UPQB0*2)  /* USB - PLL Set for 8.0 MHz input clock */
#define USBPLL_SETCLK_9_0      (UPMB0*15 | UPQB0*2)  /* USB - PLL Set for 9.0 MHz input clock */
#define USBPLL_SETCLK_9_6      (UPMB0*19 | UPQB0*3)  /* USB - PLL Set for 9.6 MHz input clock */
#define USBPLL_SETCLK_10_66    (UPMB0*17 | UPQB0*3)  /* USB - PLL Set for 10.66 MHz input clock */
#define USBPLL_SETCLK_12_0     (UPMB0*15 | UPQB0*3)  /* USB - PLL Set for 12.0 MHz input clock */
#define USBPLL_SETCLK_12_8     (UPMB0*29 | UPQB0*5)  /* USB - PLL Set for 12.8 MHz input clock */
#define USBPLL_SETCLK_14_4     (UPMB0*19 | UPQB0*4)  /* USB - PLL Set for 14.4 MHz input clock */
#define USBPLL_SETCLK_16_0     (UPMB0*17 | UPQB0*4)  /* USB - PLL Set for 16.0 MHz input clock */
#define USBPLL_SETCLK_16_9344  (UPMB0*16 | UPQB0*4)  /* USB - PLL Set for 16.9344 MHz input clock */
#define USBPLL_SETCLK_16_94118 (UPMB0*16 | UPQB0*4)  /* USB - PLL Set for 16.94118 MHz input clock */
#define USBPLL_SETCLK_18_0     (UPMB0*15 | UPQB0*4)  /* USB - PLL Set for 18.0 MHz input clock */
#define USBPLL_SETCLK_19_2     (UPMB0*19 | UPQB0*5)  /* USB - PLL Set for 19.2 MHz input clock */
#define USBPLL_SETCLK_24_0     (UPMB0*15 | UPQB0*5)  /* USB - PLL Set for 24.0 MHz input clock */
#define USBPLL_SETCLK_25_6     (UPMB0*29 | UPQB0*7)  /* USB - PLL Set for 25.6 MHz input clock */
#define USBPLL_SETCLK_26_0     (UPMB0*23 | UPQB0*6)  /* USB - PLL Set for 26.0 MHz input clock */
#define USBPLL_SETCLK_32_0     (UPMB0*23 | UPQB0*7)  /* USB - PLL Set for 32.0 MHz input clock */


/* USBPLLIR Control Bits */
#define USBOOLIFG           (0x0001)  /* USB - PLL out of lock Interrupt Flag */
#define USBLOSIFG           (0x0002)  /* USB - PLL loss of signal Interrupt Flag */
#define USBOORIFG           (0x0004)  /* USB - PLL out of range Interrupt Flag */
//#define RESERVED            (0x0008)  /* USB -  */
//#define RESERVED            (0x0010)  /* USB -  */
//#define RESERVED            (0x0020)  /* USB -  */
//#define RESERVED            (0x0040)  /* USB -  */
//#define RESERVED            (0x0080)  /* USB -  */
#define USBOOLIE            (0x0100)  /* USB - PLL out of lock Interrupt enable */
#define USBLOSIE            (0x0200)  /* USB - PLL loss of signal Interrupt enable */
#define USBOORIE            (0x0400)  /* USB - PLL out of range Interrupt enable */
//#define RESERVED            (0x0800)  /* USB -  */
//#define RESERVED            (0x1000)  /* USB -  */
//#define RESERVED            (0x2000)  /* USB -  */
//#define RESERVED            (0x4000)  /* USB -  */
//#define RESERVED            (0x8000)  /* USB -  */

/* USBPLLIR Control Bits */
#define USBOOLIFG_L         (0x0001)  /* USB - PLL out of lock Interrupt Flag */
#define USBLOSIFG_L         (0x0002)  /* USB - PLL loss of signal Interrupt Flag */
#define USBOORIFG_L         (0x0004)  /* USB - PLL out of range Interrupt Flag */
//#define RESERVED            (0x0008)  /* USB -  */
//#define RESERVED            (0x0010)  /* USB -  */
//#define RESERVED            (0x0020)  /* USB -  */
//#define RESERVED            (0x0040)  /* USB -  */
//#define RESERVED            (0x0080)  /* USB -  */
//#define RESERVED            (0x0800)  /* USB -  */
//#define RESERVED            (0x1000)  /* USB -  */
//#define RESERVED            (0x2000)  /* USB -  */
//#define RESERVED            (0x4000)  /* USB -  */
//#define RESERVED            (0x8000)  /* USB -  */

/* USBPLLIR Control Bits */
//#define RESERVED            (0x0008)  /* USB -  */
//#define RESERVED            (0x0010)  /* USB -  */
//#define RESERVED            (0x0020)  /* USB -  */
//#define RESERVED            (0x0040)  /* USB -  */
//#define RESERVED            (0x0080)  /* USB -  */
#define USBOOLIE_H          (0x0001)  /* USB - PLL out of lock Interrupt enable */
#define USBLOSIE_H          (0x0002)  /* USB - PLL loss of signal Interrupt enable */
#define USBOORIE_H          (0x0004)  /* USB - PLL out of range Interrupt enable */
//#define RESERVED            (0x0800)  /* USB -  */
//#define RESERVED            (0x1000)  /* USB -  */
//#define RESERVED            (0x2000)  /* USB -  */
//#define RESERVED            (0x4000)  /* USB -  */
//#define RESERVED            (0x8000)  /* USB -  */



/* ========================================================================= */
/* USB Control Registers */
/* ========================================================================= */
#define OFS_USBIEPCNF_0       (0x0020)    /* USB Input endpoint_0: Configuration */
#define OFS_USBIEPCNT_0       (0x0021)    /* USB Input endpoint_0: Byte Count */
#define OFS_USBOEPCNF_0       (0x0022)    /* USB Output endpoint_0: Configuration */
#define OFS_USBOEPCNT_0       (0x0023)    /* USB Output endpoint_0: byte count */
#define OFS_USBIEPIE          (0x002E)    /* USB Input endpoint interrupt enable flags */
#define OFS_USBOEPIE          (0x002F)    /* USB Output endpoint interrupt enable flags */
#define OFS_USBIEPIFG         (0x0030)    /* USB Input endpoint interrupt flags */
#define OFS_USBOEPIFG         (0x0031)    /* USB Output endpoint interrupt flags */
#define OFS_USBVECINT         (0x0032)    /* USB Vector interrupt register */
#define OFS_USBVECINT_L        OFS_USBVECINT
#define OFS_USBVECINT_H        OFS_USBVECINT+1
#define OFS_USBMAINT          (0x0036)    /* USB maintenance register */
#define OFS_USBMAINT_L         OFS_USBMAINT
#define OFS_USBMAINT_H         OFS_USBMAINT+1
#define OFS_USBTSREG          (0x0038)    /* USB Time Stamp register */
#define OFS_USBTSREG_L         OFS_USBTSREG
#define OFS_USBTSREG_H         OFS_USBTSREG+1
#define OFS_USBFN             (0x003A)    /* USB Frame number */
#define OFS_USBFN_L            OFS_USBFN
#define OFS_USBFN_H            OFS_USBFN+1
#define OFS_USBCTL            (0x003C)    /* USB control register */
#define OFS_USBIE             (0x003D)    /* USB interrupt enable register */
#define OFS_USBIFG            (0x003E)    /* USB interrupt flag register */
#define OFS_USBFUNADR         (0x003F)    /* USB Function address register */

#define USBIV          USBVECINT   /* USB Vector interrupt register (alternate define) */

/* USBIEPCNF_0 Control Bits */
/* USBOEPCNF_0 Control Bits */
//#define RESERVED       (0x0001)  /* USB -  */
//#define RESERVED       (0x0001)  /* USB -  */
#define USBIIE         (0x0004)  /* USB - Transaction Interrupt indication enable */
#define STALL          (0x0008)  /* USB - Stall Condition */
//#define RESERVED       (0x0010)  /* USB -  */
#define TOGGLE         (0x0020)  /* USB - Toggle Bit */
//#define RESERVED       (0x0040)  /* USB -  */
#define UBME           (0x0080)  /* USB - UBM In-Endpoint Enable */

/* USBIEPBCNT_0 Control Bits */
/* USBOEPBCNT_0 Control Bits */
#define CNT0           (0x0001)  /* USB - Byte Count Bit 0 */
#define CNT1           (0x0001)  /* USB - Byte Count Bit 1 */
#define CNT2           (0x0004)  /* USB - Byte Count Bit 2 */
#define CNT3           (0x0008)  /* USB - Byte Count Bit 3 */
//#define RESERVED       (0x0010)  /* USB -  */
//#define RESERVED       (0x0020)  /* USB -  */
//#define RESERVED       (0x0040)  /* USB -  */
#define NAK            (0x0080)  /* USB - No Acknowledge Status Bit */


/* USBMAINT Control Bits */
#define UTIFG          (0x0001)  /* USB - Timer Interrupt Flag */
#define UTIE           (0x0002)  /* USB - Timer Interrupt Enable */
//#define RESERVED       (0x0004)  /* USB -  */
//#define RESERVED       (0x0008)  /* USB -  */
//#define RESERVED       (0x0010)  /* USB -  */
//#define RESERVED       (0x0020)  /* USB -  */
//#define RESERVED       (0x0040)  /* USB -  */
//#define RESERVED       (0x0080)  /* USB -  */
#define TSGEN          (0x0100)  /* USB - Time Stamp Generator Enable */
#define TSESEL0        (0x0200)  /* USB - Time Stamp Event Select Bit 0 */
#define TSESEL1        (0x0400)  /* USB - Time Stamp Event Select Bit 1 */
#define TSE3           (0x0800)  /* USB - Time Stamp Event #3 Bit */
//#define RESERVED       (0x1000)  /* USB -  */
#define UTSEL0         (0x2000)  /* USB - Timer Select Bit 0 */
#define UTSEL1         (0x4000)  /* USB - Timer Select Bit 1 */
#define UTSEL2         (0x8000)  /* USB - Timer Select Bit 2 */

/* USBMAINT Control Bits */
#define UTIFG_L             (0x0001)  /* USB - Timer Interrupt Flag */
#define UTIE_L              (0x0002)  /* USB - Timer Interrupt Enable */
//#define RESERVED       (0x0004)  /* USB -  */
//#define RESERVED       (0x0008)  /* USB -  */
//#define RESERVED       (0x0010)  /* USB -  */
//#define RESERVED       (0x0020)  /* USB -  */
//#define RESERVED       (0x0040)  /* USB -  */
//#define RESERVED       (0x0080)  /* USB -  */
//#define RESERVED       (0x1000)  /* USB -  */

/* USBMAINT Control Bits */
//#define RESERVED       (0x0004)  /* USB -  */
//#define RESERVED       (0x0008)  /* USB -  */
//#define RESERVED       (0x0010)  /* USB -  */
//#define RESERVED       (0x0020)  /* USB -  */
//#define RESERVED       (0x0040)  /* USB -  */
//#define RESERVED       (0x0080)  /* USB -  */
#define TSGEN_H             (0x0001)  /* USB - Time Stamp Generator Enable */
#define TSESEL0_H           (0x0002)  /* USB - Time Stamp Event Select Bit 0 */
#define TSESEL1_H           (0x0004)  /* USB - Time Stamp Event Select Bit 1 */
#define TSE3_H              (0x0008)  /* USB - Time Stamp Event #3 Bit */
//#define RESERVED       (0x1000)  /* USB -  */
#define UTSEL0_H            (0x0020)  /* USB - Timer Select Bit 0 */
#define UTSEL1_H            (0x0040)  /* USB - Timer Select Bit 1 */
#define UTSEL2_H            (0x0080)  /* USB - Timer Select Bit 2 */

#define TSESEL_0       (0x0000)  /* USB - Time Stamp Event Select: 0 */
#define TSESEL_1       (0x0200)  /* USB - Time Stamp Event Select: 1 */
#define TSESEL_2       (0x0400)  /* USB - Time Stamp Event Select: 2 */
#define TSESEL_3       (0x0600)  /* USB - Time Stamp Event Select: 3 */

#define UTSEL_0        (0x0000)  /* USB - Timer Select: 0 */
#define UTSEL_1        (0x2000)  /* USB - Timer Select: 1 */
#define UTSEL_2        (0x4000)  /* USB - Timer Select: 2 */
#define UTSEL_3        (0x6000)  /* USB - Timer Select: 3 */
#define UTSEL_4        (0x8000)  /* USB - Timer Select: 4 */
#define UTSEL_5        (0xA000)  /* USB - Timer Select: 5 */
#define UTSEL_6        (0xC000)  /* USB - Timer Select: 6 */
#define UTSEL_7        (0xE000)  /* USB - Timer Select: 7 */

/* USBCTL Control Bits */
#define DIR            (0x0001)  /* USB - Data Response Bit */
//#define RESERVED       (0x0002)  /* USB -  */
//#define RESERVED       (0x0004)  /* USB -  */
//#define RESERVED       (0x0008)  /* USB -  */
#define FRSTE          (0x0010)  /* USB - Function Reset Connection Enable */
#define RWUP           (0x0020)  /* USB - Device Remote Wakeup Request */
#define FEN            (0x0040)  /* USB - Function Enable Bit */
//#define RESERVED       (0x0080)  /* USB -  */

/* USBIE Control Bits */
#define STPOWIE        (0x0001)  /* USB - Setup Overwrite Interrupt Enable */
//#define RESERVED       (0x0002)  /* USB -  */
#define SETUPIE        (0x0004)  /* USB - Setup Interrupt Enable */
//#define RESERVED       (0x0008)  /* USB -  */
//#define RESERVED       (0x0010)  /* USB -  */
#define RESRIE         (0x0020)  /* USB - Function Resume Request Interrupt Enable */
#define SUSRIE         (0x0040)  /* USB - Function Suspend Request Interrupt Enable */
#define RSTRIE         (0x0080)  /* USB - Function Reset Request Interrupt Enable */

/* USBIFG Control Bits */
#define STPOWIFG       (0x0001)  /* USB - Setup Overwrite Interrupt Flag */
//#define RESERVED       (0x0002)  /* USB -  */
#define SETUPIFG       (0x0004)  /* USB - Setup Interrupt Flag */
//#define RESERVED       (0x0008)  /* USB -  */
//#define RESERVED       (0x0010)  /* USB -  */
#define RESRIFG        (0x0020)  /* USB - Function Resume Request Interrupt Flag */
#define SUSRIFG        (0x0040)  /* USB - Function Suspend Request Interrupt Flag */
#define RSTRIFG        (0x0080)  /* USB - Function Reset Request Interrupt Flag */

//values of USBVECINT when USB-interrupt occured
#define     USBVECINT_NONE                     0x00
#define     USBVECINT_PWR_DROP                 0x02
#define     USBVECINT_PLL_LOCK                 0x04
#define     USBVECINT_PLL_SIGNAL               0x06
#define     USBVECINT_PLL_RANGE                0x08
#define     USBVECINT_PWR_VBUSOn               0x0A
#define     USBVECINT_PWR_VBUSOff              0x0C
#define     USBVECINT_USB_TIMESTAMP            0x10
#define     USBVECINT_INPUT_ENDPOINT0          0x12
#define     USBVECINT_OUTPUT_ENDPOINT0         0x14
#define     USBVECINT_RSTR                     0x16
#define     USBVECINT_SUSR                     0x18
#define     USBVECINT_RESR                     0x1A
#define     USBVECINT_SETUP_PACKET_RECEIVED    0x20
#define     USBVECINT_STPOW_PACKET_RECEIVED    0x22
#define     USBVECINT_INPUT_ENDPOINT1          0x24
#define     USBVECINT_INPUT_ENDPOINT2          0x26
#define     USBVECINT_INPUT_ENDPOINT3          0x28
#define     USBVECINT_INPUT_ENDPOINT4          0x2A
#define     USBVECINT_INPUT_ENDPOINT5          0x2C
#define     USBVECINT_INPUT_ENDPOINT6          0x2E
#define     USBVECINT_INPUT_ENDPOINT7          0x30
#define     USBVECINT_OUTPUT_ENDPOINT1         0x32
#define     USBVECINT_OUTPUT_ENDPOINT2         0x34
#define     USBVECINT_OUTPUT_ENDPOINT3         0x36
#define     USBVECINT_OUTPUT_ENDPOINT4         0x38
#define     USBVECINT_OUTPUT_ENDPOINT5         0x3A
#define     USBVECINT_OUTPUT_ENDPOINT6         0x3C
#define     USBVECINT_OUTPUT_ENDPOINT7         0x3E


/* ========================================================================= */
/* USB Operation Registers */
/* ========================================================================= */

#define OFS_USBIEPSIZXY_7     (0x23FF)    /* Input Endpoint_7: X/Y-buffer size  */
#define OFS_USBIEPBCTY_7      (0x23FE)    /* Input Endpoint_7: Y-byte count  */
#define OFS_USBIEPBBAY_7      (0x23FD)    /* Input Endpoint_7: Y-buffer base addr.  */
//#define    Spare_O    (0x23FC)   /* Not used  */
//#define    Spare_O    (0x23FB)   /* Not used  */
#define OFS_USBIEPBCTX_7      (0x23FA)    /* Input Endpoint_7: X-byte count  */
#define OFS_USBIEPBBAX_7      (0x23F9)    /* Input Endpoint_7: X-buffer base addr. */
#define OFS_USBIEPCNF_7       (0x23F8)    /* Input Endpoint_7: Configuration  */
#define OFS_USBIEPSIZXY_6     (0x23F7)    /* Input Endpoint_6: X/Y-buffer size  */
#define OFS_USBIEPBCTY_6      (0x23F6)    /* Input Endpoint_6: Y-byte count */
#define OFS_USBIEPBBAY_6      (0x23F5)    /* Input Endpoint_6: Y-buffer base addr. */
//#define    Spare_O    (0x23F4)   /* Not used  */
//#define    Spare_O    (0x23F3)   /* Not used  */
#define OFS_USBIEPBCTX_6      (0x23F2)    /* Input Endpoint_6: X-byte count */
#define OFS_USBIEPBBAX_6      (0x23F1)    /* Input Endpoint_6: X-buffer base addr. */
#define OFS_USBIEPCNF_6       (0x23F0)    /* Input Endpoint_6: Configuration */
#define OFS_USBIEPSIZXY_5     (0x23EF)    /* Input Endpoint_5: X/Y-buffer size */
#define OFS_USBIEPBCTY_5      (0x23EE)    /* Input Endpoint_5: Y-byte count */
#define OFS_USBIEPBBAY_5      (0x23ED)    /* Input Endpoint_5: Y-buffer base addr. */
//#define    Spare_O    (0x23EC)   /* Not used */
//#define    Spare_O    (0x23EB)   /* Not used */
#define OFS_USBIEPBCTX_5      (0x23EA)    /* Input Endpoint_5: X-byte count */
#define OFS_USBIEPBBAX_5      (0x23E9)    /* Input Endpoint_5: X-buffer base addr. */
#define OFS_USBIEPCNF_5       (0x23E8)    /* Input Endpoint_5: Configuration */
#define OFS_USBIEPSIZXY_4     (0x23E7)    /* Input Endpoint_4: X/Y-buffer size */
#define OFS_USBIEPBCTY_4      (0x23E6)    /* Input Endpoint_4: Y-byte count */
#define OFS_USBIEPBBAY_4      (0x23E5)    /* Input Endpoint_4: Y-buffer base addr. */
//#define    Spare_O    (0x23E4)   /* Not used */
//#define    Spare_O    (0x23E3)   /* Not used */
#define OFS_USBIEPBCTX_4      (0x23E2)    /* Input Endpoint_4: X-byte count */
#define OFS_USBIEPBBAX_4      (0x23E1)    /* Input Endpoint_4: X-buffer base addr. */
#define OFS_USBIEPCNF_4       (0x23E0)    /* Input Endpoint_4: Configuration */
#define OFS_USBIEPSIZXY_3     (0x23DF)    /* Input Endpoint_3: X/Y-buffer size */
#define OFS_USBIEPBCTY_3      (0x23DE)    /* Input Endpoint_3: Y-byte count */
#define OFS_USBIEPBBAY_3      (0x23DD)    /* Input Endpoint_3: Y-buffer base addr. */
//#define    Spare_O    (0x23DC)   /* Not used */
//#define    Spare_O    (0x23DB)   /* Not used */
#define OFS_USBIEPBCTX_3      (0x23DA)    /* Input Endpoint_3: X-byte count */
#define OFS_USBIEPBBAX_3      (0x23D9)    /* Input Endpoint_3: X-buffer base addr. */
#define OFS_USBIEPCNF_3       (0x23D8)    /* Input Endpoint_3: Configuration */
#define OFS_USBIEPSIZXY_2     (0x23D7)    /* Input Endpoint_2: X/Y-buffer size */
#define OFS_USBIEPBCTY_2      (0x23D6)    /* Input Endpoint_2: Y-byte count */
#define OFS_USBIEPBBAY_2      (0x23D5)    /* Input Endpoint_2: Y-buffer base addr. */
//#define    Spare_O    (0x23D4)   /* Not used */
//#define    Spare_O    (0x23D3)   /* Not used */
#define OFS_USBIEPBCTX_2      (0x23D2)    /* Input Endpoint_2: X-byte count */
#define OFS_USBIEPBBAX_2      (0x23D1)    /* Input Endpoint_2: X-buffer base addr. */
#define OFS_USBIEPCNF_2       (0x23D0)    /* Input Endpoint_2: Configuration */
#define OFS_USBIEPSIZXY_1     (0x23CF)    /* Input Endpoint_1: X/Y-buffer size */
#define OFS_USBIEPBCTY_1      (0x23CE)    /* Input Endpoint_1: Y-byte count */
#define OFS_USBIEPBBAY_1      (0x23CD)    /* Input Endpoint_1: Y-buffer base addr. */
//#define    Spare_O    (0x23CC)   /* Not used */
//#define    Spare_O    (0x23CB)   /* Not used */
#define OFS_USBIEPBCTX_1      (0x23CA)    /* Input Endpoint_1: X-byte count */
#define OFS_USBIEPBBAX_1      (0x23C9)    /* Input Endpoint_1: X-buffer base addr. */
#define OFS_USBIEPCNF_1       (0x23C8)    /* Input Endpoint_1: Configuration */
//#define       (0x23C7)_O   /* */
//#define     RESERVED_O      (0x1C00)    /* */
//#define       (0x23C0)_O   /* */
#define OFS_USBOEPSIZXY_7     (0x23BF)    /* Output Endpoint_7: X/Y-buffer size */
#define OFS_USBOEPBCTY_7      (0x23BE)    /* Output Endpoint_7: Y-byte count */
#define OFS_USBOEPBBAY_7      (0x23BD)    /* Output Endpoint_7: Y-buffer base addr. */
//#define    Spare_O    (0x23BC)   /* Not used */
//#define    Spare_O    (0x23BB)   /* Not used */
#define OFS_USBOEPBCTX_7      (0x23BA)    /* Output Endpoint_7: X-byte count */
#define OFS_USBOEPBBAX_7      (0x23B9)    /* Output Endpoint_7: X-buffer base addr. */
#define OFS_USBOEPCNF_7       (0x23B8)   /* Output Endpoint_7: Configuration */
#define OFS_USBOEPSIZXY_6     (0x23B7)    /* Output Endpoint_6: X/Y-buffer size */
#define OFS_USBOEPBCTY_6      (0x23B6)    /* Output Endpoint_6: Y-byte count */
#define OFS_USBOEPBBAY_6      (0x23B5)    /* Output Endpoint_6: Y-buffer base addr. */
//#define    Spare_O    (0x23B4)   /* Not used */
//#define    Spare_O    (0x23B3)   /* Not used */
#define OFS_USBOEPBCTX_6      (0x23B2)    /* Output Endpoint_6: X-byte count */
#define OFS_USBOEPBBAX_6      (0x23B1)    /* Output Endpoint_6: X-buffer base addr. */
#define OFS_USBOEPCNF_6       (0x23B0)    /* Output Endpoint_6: Configuration */
#define OFS_USBOEPSIZXY_5     (0x23AF)    /* Output Endpoint_5: X/Y-buffer size */
#define OFS_USBOEPBCTY_5      (0x23AE)    /* Output Endpoint_5: Y-byte count */
#define OFS_USBOEPBBAY_5      (0x23AD)    /* Output Endpoint_5: Y-buffer base addr. */
//#define    Spare_O    (0x23AC)   /* Not used */
//#define    Spare_O    (0x23AB)   /* Not used */
#define OFS_USBOEPBCTX_5      (0x23AA)    /* Output Endpoint_5: X-byte count */
#define OFS_USBOEPBBAX_5      (0x23A9)    /* Output Endpoint_5: X-buffer base addr. */
#define OFS_USBOEPCNF_5       (0x23A8)    /* Output Endpoint_5: Configuration */
#define OFS_USBOEPSIZXY_4     (0x23A7)    /* Output Endpoint_4: X/Y-buffer size */
#define OFS_USBOEPBCTY_4      (0x23A6)    /* Output Endpoint_4: Y-byte count */
#define OFS_USBOEPBBAY_4      (0x23A5)    /* Output Endpoint_4: Y-buffer base addr. */
//#define    Spare_O    (0x23A4)   /* Not used */
//#define    Spare_O    (0x23A3)   /* Not used */
#define OFS_USBOEPBCTX_4      (0x23A2)    /* Output Endpoint_4: X-byte count */
#define OFS_USBOEPBBAX_4      (0x23A1)    /* Output Endpoint_4: X-buffer base addr. */
#define OFS_USBOEPCNF_4       (0x23A0)    /* Output Endpoint_4: Configuration */
#define OFS_USBOEPSIZXY_3     (0x239F)    /* Output Endpoint_3: X/Y-buffer size */
#define OFS_USBOEPBCTY_3      (0x239E)    /* Output Endpoint_3: Y-byte count */
#define OFS_USBOEPBBAY_3      (0x239D)    /* Output Endpoint_3: Y-buffer base addr. */
//#define    Spare_O    (0x239C)   /* Not used */
//#define    Spare_O    (0x239B)   /* Not used */
#define OFS_USBOEPBCTX_3      (0x239A)    /* Output Endpoint_3: X-byte count */
#define OFS_USBOEPBBAX_3      (0x2399)    /* Output Endpoint_3: X-buffer base addr. */
#define OFS_USBOEPCNF_3       (0x2398)    /* Output Endpoint_3: Configuration */
#define OFS_USBOEPSIZXY_2     (0x2397)    /* Output Endpoint_2: X/Y-buffer size */
#define OFS_USBOEPBCTY_2      (0x2396)    /* Output Endpoint_2: Y-byte count */
#define OFS_USBOEPBBAY_2      (0x2395)    /* Output Endpoint_2: Y-buffer base addr. */
//#define    Spare_O    (0x2394)   /* Not used */
//#define    Spare_O    (0x2393)   /* Not used */
#define OFS_USBOEPBCTX_2      (0x2392)    /* Output Endpoint_2: X-byte count */
#define OFS_USBOEPBBAX_2      (0x2391)    /* Output Endpoint_2: X-buffer base addr. */
#define OFS_USBOEPCNF_2       (0x2390)    /* Output Endpoint_2: Configuration */
#define OFS_USBOEPSIZXY_1     (0x238F)    /* Output Endpoint_1: X/Y-buffer size */
#define OFS_USBOEPBCTY_1      (0x238E)    /* Output Endpoint_1: Y-byte count */
#define OFS_USBOEPBBAY_1      (0x238D)    /* Output Endpoint_1: Y-buffer base addr. */
//#define    Spare_O    (0x238C)   /* Not used */
//#define    Spare_O    (0x238B)   /* Not used */
#define OFS_USBOEPBCTX_1      (0x238A)    /* Output Endpoint_1: X-byte count */
#define OFS_USBOEPBBAX_1      (0x2389)    /* Output Endpoint_1: X-buffer base addr. */
#define OFS_USBOEPCNF_1       (0x2388)    /* Output Endpoint_1: Configuration */
#define OFS_USBSUBLK          (0x2380)    /* Setup Packet Block */
#define OFS_USBIEP0BUF        (0x2378)    /* Input endpoint_0 buffer */
#define OFS_USBOEP0BUF        (0x2370)    /* Output endpoint_0 buffer */
#define OFS_USBTOPBUFF        (0x236F)    /* Top of buffer space */
//         (1904 Bytes)               /* Buffer space */
#define OFS_USBSTABUFF        (0x1C00)    /* Start of buffer space */

/* USBIEPCNF_n Control Bits */
/* USBOEPCNF_n Control Bits */
//#define RESERVED       (0x0001)  /* USB -  */
//#define RESERVED       (0x0001)  /* USB -  */
#define DBUF           (0x0010)  /* USB - Double Buffer Enable */
//#define RESERVED       (0x0040)  /* USB -  */

/* USBIEPBCNT_n Control Bits */
/* USBOEPBCNT_n Control Bits */
#define CNT4           (0x0010)  /* USB - Byte Count Bit 3 */
#define CNT5           (0x0020)  /* USB - Byte Count Bit 3 */
#define CNT6           (0x0040)  /* USB - Byte Count Bit 3 */
#endif
/************************************************************
* USCI Ax
************************************************************/
#ifdef  __MSP430_HAS_USCI_Ax__       /* Definition to show that Module is available */

#define OFS_UCAxCTLW0         (0x0000)  /* USCI Ax Control Word Register 0 */
#define OFS_UCAxCTLW0_L        OFS_UCAxCTLW0
#define OFS_UCAxCTLW0_H        OFS_UCAxCTLW0+1
#define OFS_UCAxCTL0          (0x0001)
#define OFS_UCAxCTL1          (0x0000)
#define UCAxCTL1            UCAxCTLW0_L  /* USCI Ax Control Register 1 */
#define UCAxCTL0            UCAxCTLW0_H  /* USCI Ax Control Register 0 */
#define OFS_UCAxBRW           (0x0006)  /* USCI Ax Baud Word Rate 0 */
#define OFS_UCAxBRW_L          OFS_UCAxBRW
#define OFS_UCAxBRW_H          OFS_UCAxBRW+1
#define OFS_UCAxBR0           (0x0006)
#define OFS_UCAxBR1           (0x0007)
#define UCAxBR0             UCAxBRW_L /* USCI Ax Baud Rate 0 */
#define UCAxBR1             UCAxBRW_H /* USCI Ax Baud Rate 1 */
#define OFS_UCAxMCTL          (0x0008)  /* USCI Ax Modulation Control */
#define OFS_UCAxSTAT          (0x000A)  /* USCI Ax Status Register */
#define OFS_UCAxRXBUF         (0x000C)  /* USCI Ax Receive Buffer */
#define OFS_UCAxTXBUF         (0x000E)  /* USCI Ax Transmit Buffer */
#define OFS_UCAxABCTL         (0x0010)  /* USCI Ax LIN Control */
#define OFS_UCAxIRCTL         (0x0012)  /* USCI Ax IrDA Transmit Control */
#define OFS_UCAxIRCTL_L        OFS_UCAxIRCTL
#define OFS_UCAxIRCTL_H        OFS_UCAxIRCTL+1
#define OFS_UCAxIRTCTL        (0x0012)
#define OFS_UCAxIRRCTL        (0x0013)
#define UCAxIRTCTL          UCAxIRCTL_L  /* USCI Ax IrDA Transmit Control */
#define UCAxIRRCTL          UCAxIRCTL_H  /* USCI Ax IrDA Receive Control */
#define OFS_UCAxICTL          (0x001C)  /* USCI Ax Interrupt Enable Register */
#define OFS_UCAxICTL_L         OFS_UCAxICTL
#define OFS_UCAxICTL_H         OFS_UCAxICTL+1
#define OFS_UCAxIE            (0x001C)
#define OFS_UCAxIFG           (0x001D)
#define UCAxIE              UCAxICTL_L  /* USCI Ax Interrupt Enable Register */
#define UCAxIFG             UCAxICTL_H  /* USCI Ax Interrupt Flags Register */
#define OFS_UCAxIV            (0x001E)  /* USCI Ax Interrupt Vector Register */

#define OFS_UCAxCTLW0__SPI    (0x0000)
#define OFS_UCAxCTLW0__SPI_L   OFS_UCAxCTLW0__SPI
#define OFS_UCAxCTLW0__SPI_H   OFS_UCAxCTLW0__SPI+1
#define OFS_UCAxCTL0__SPI     (0x0001)
#define OFS_UCAxCTL1__SPI     (0x0000)
#define OFS_UCAxBRW__SPI      (0x0006)
#define OFS_UCAxBRW__SPI_L     OFS_UCAxBRW__SPI
#define OFS_UCAxBRW__SPI_H     OFS_UCAxBRW__SPI+1
#define OFS_UCAxBR0__SPI      (0x0006)
#define OFS_UCAxBR1__SPI      (0x0007)
#define OFS_UCAxMCTL__SPI     (0x0008)
#define OFS_UCAxSTAT__SPI     (0x000A)
#define OFS_UCAxRXBUF__SPI    (0x000C)
#define OFS_UCAxTXBUF__SPI    (0x000E)
#define OFS_UCAxICTL__SPI     (0x001C)
#define OFS_UCAxICTL__SPI_L    OFS_UCAxICTL__SPI
#define OFS_UCAxICTL__SPI_H    OFS_UCAxICTL__SPI+1
#define OFS_UCAxIE__SPI       (0x001C)
#define OFS_UCAxIFG__SPI      (0x001D)
#define OFS_UCAxIV__SPI       (0x001E)

#endif
/************************************************************
* USCI Bx
************************************************************/
#ifdef  __MSP430_HAS_USCI_Bx__        /* Definition to show that Module is available */

#define OFS_UCBxCTLW0__SPI    (0x0000)
#define OFS_UCBxCTLW0__SPI_L   OFS_UCBxCTLW0__SPI
#define OFS_UCBxCTLW0__SPI_H   OFS_UCBxCTLW0__SPI+1
#define OFS_UCBxCTL0__SPI     (0x0001)
#define OFS_UCBxCTL1__SPI     (0x0000)
#define OFS_UCBxBRW__SPI      (0x0006)
#define OFS_UCBxBRW__SPI_L     OFS_UCBxBRW__SPI
#define OFS_UCBxBRW__SPI_H     OFS_UCBxBRW__SPI+1
#define OFS_UCBxBR0__SPI      (0x0006)
#define OFS_UCBxBR1__SPI      (0x0007)
#define OFS_UCBxSTAT__SPI     (0x000A)
#define OFS_UCBxRXBUF__SPI    (0x000C)
#define OFS_UCBxTXBUF__SPI    (0x000E)
#define OFS_UCBxICTL__SPI     (0x001C)
#define OFS_UCBxICTL__SPI_L    OFS_UCBxICTL__SPI
#define OFS_UCBxICTL__SPI_H    OFS_UCBxICTL__SPI+1
#define OFS_UCBxIE__SPI       (0x001C)
#define OFS_UCBxIFG__SPI      (0x001D)
#define OFS_UCBxIV__SPI       (0x001E)

#define OFS_UCBxCTLW0         (0x0000)  /* USCI Bx Control Word Register 0 */
#define OFS_UCBxCTLW0_L        OFS_UCBxCTLW0
#define OFS_UCBxCTLW0_H        OFS_UCBxCTLW0+1
#define OFS_UCBxCTL0          (0x0001)
#define OFS_UCBxCTL1          (0x0000)
#define UCBxCTL1            UCBxCTLW0_L  /* USCI Bx Control Register 1 */
#define UCBxCTL0            UCBxCTLW0_H  /* USCI Bx Control Register 0 */
#define OFS_UCBxBRW           (0x0006)  /* USCI Bx Baud Word Rate 0 */
#define OFS_UCBxBRW_L          OFS_UCBxBRW
#define OFS_UCBxBRW_H          OFS_UCBxBRW+1
#define OFS_UCBxBR0           (0x0006)
#define OFS_UCBxBR1           (0x0007)
#define UCBxBR0             UCBxBRW_L /* USCI Bx Baud Rate 0 */
#define UCBxBR1             UCBxBRW_H /* USCI Bx Baud Rate 1 */
#define OFS_UCBxSTAT          (0x000A)  /* USCI Bx Status Register */
#define OFS_UCBxRXBUF         (0x000C)  /* USCI Bx Receive Buffer */
#define OFS_UCBxTXBUF         (0x000E)  /* USCI Bx Transmit Buffer */
#define OFS_UCBxI2COA         (0x0010)  /* USCI Bx I2C Own Address */
#define OFS_UCBxI2COA_L        OFS_UCBxI2COA
#define OFS_UCBxI2COA_H        OFS_UCBxI2COA+1
#define OFS_UCBxI2CSA         (0x0012)  /* USCI Bx I2C Slave Address */
#define OFS_UCBxI2CSA_L        OFS_UCBxI2CSA
#define OFS_UCBxI2CSA_H        OFS_UCBxI2CSA+1
#define OFS_UCBxICTL          (0x001C)  /* USCI Bx Interrupt Enable Register */
#define OFS_UCBxICTL_L         OFS_UCBxICTL
#define OFS_UCBxICTL_H         OFS_UCBxICTL+1
#define OFS_UCBxIE            (0x001C)
#define OFS_UCBxIFG           (0x001D)
#define UCBxIE              UCBxICTL_L  /* USCI Bx Interrupt Enable Register */
#define UCBxIFG             UCBxICTL_H  /* USCI Bx Interrupt Flags Register */
#define OFS_UCBxIV            (0x001E)  /* USCI Bx Interrupt Vector Register */

#endif
#if (defined(__MSP430_HAS_USCI_Ax__) || defined(__MSP430_HAS_USCI_Bx__))

// UCAxCTL0 UART-Mode Control Bits
#define UCPEN               (0x80)    /* Async. Mode: Parity enable */
#define UCPAR               (0x40)    /* Async. Mode: Parity     0:odd / 1:even */
#define UCMSB               (0x20)    /* Async. Mode: MSB first  0:LSB / 1:MSB */
#define UC7BIT              (0x10)    /* Async. Mode: Data Bits  0:8-bits / 1:7-bits */
#define UCSPB               (0x08)    /* Async. Mode: Stop Bits  0:one / 1: two */
#define UCMODE1             (0x04)    /* Async. Mode: USCI Mode 1 */
#define UCMODE0             (0x02)    /* Async. Mode: USCI Mode 0 */
#define UCSYNC              (0x01)    /* Sync-Mode  0:UART-Mode / 1:SPI-Mode */

// UCxxCTL0 SPI-Mode Control Bits
#define UCCKPH              (0x80)    /* Sync. Mode: Clock Phase */
#define UCCKPL              (0x40)    /* Sync. Mode: Clock Polarity */
#define UCMST               (0x08)    /* Sync. Mode: Master Select */

// UCBxCTL0 I2C-Mode Control Bits
#define UCA10               (0x80)    /* 10-bit Address Mode */
#define UCSLA10             (0x40)    /* 10-bit Slave Address Mode */
#define UCMM                (0x20)    /* Multi-Master Environment */
//#define res               (0x10)    /* reserved */
#define UCMODE_0            (0x00)    /* Sync. Mode: USCI Mode: 0 */
#define UCMODE_1            (0x02)    /* Sync. Mode: USCI Mode: 1 */
#define UCMODE_2            (0x04)    /* Sync. Mode: USCI Mode: 2 */
#define UCMODE_3            (0x06)    /* Sync. Mode: USCI Mode: 3 */

// UCAxCTL1 UART-Mode Control Bits
#define UCSSEL1             (0x80)    /* USCI 0 Clock Source Select 1 */
#define UCSSEL0             (0x40)    /* USCI 0 Clock Source Select 0 */
#define UCRXEIE             (0x20)    /* RX Error interrupt enable */
#define UCBRKIE             (0x10)    /* Break interrupt enable */
#define UCDORM              (0x08)    /* Dormant (Sleep) Mode */
#define UCTXADDR            (0x04)    /* Send next Data as Address */
#define UCTXBRK             (0x02)    /* Send next Data as Break */
#define UCSWRST             (0x01)    /* USCI Software Reset */

// UCxxCTL1 SPI-Mode Control Bits
//#define res               (0x20)    /* reserved */
//#define res               (0x10)    /* reserved */
//#define res               (0x08)    /* reserved */
//#define res               (0x04)    /* reserved */
//#define res               (0x02)    /* reserved */

// UCBxCTL1 I2C-Mode Control Bits
//#define res               (0x20)    /* reserved */
#define UCTR                (0x10)    /* Transmit/Receive Select/Flag */
#define UCTXNACK            (0x08)    /* Transmit NACK */
#define UCTXSTP             (0x04)    /* Transmit STOP */
#define UCTXSTT             (0x02)    /* Transmit START */
#define UCSSEL_0            (0x00)    /* USCI 0 Clock Source: 0 */
#define UCSSEL_1            (0x40)    /* USCI 0 Clock Source: 1 */
#define UCSSEL_2            (0x80)    /* USCI 0 Clock Source: 2 */
#define UCSSEL_3            (0xC0)    /* USCI 0 Clock Source: 3 */
#define UCSSEL__UCLK        (0x00)    /* USCI 0 Clock Source: UCLK */
#define UCSSEL__ACLK        (0x40)    /* USCI 0 Clock Source: ACLK */
#define UCSSEL__SMCLK       (0x80)    /* USCI 0 Clock Source: SMCLK */

/* UCAxMCTL Control Bits */
#define UCBRF3              (0x80)    /* USCI First Stage Modulation Select 3 */
#define UCBRF2              (0x40)    /* USCI First Stage Modulation Select 2 */
#define UCBRF1              (0x20)    /* USCI First Stage Modulation Select 1 */
#define UCBRF0              (0x10)    /* USCI First Stage Modulation Select 0 */
#define UCBRS2              (0x08)    /* USCI Second Stage Modulation Select 2 */
#define UCBRS1              (0x04)    /* USCI Second Stage Modulation Select 1 */
#define UCBRS0              (0x02)    /* USCI Second Stage Modulation Select 0 */
#define UCOS16              (0x01)    /* USCI 16-times Oversampling enable */

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

#define UCBRS_0             (0x00)    /* USCI Second Stage Modulation: 0 */
#define UCBRS_1             (0x02)    /* USCI Second Stage Modulation: 1 */
#define UCBRS_2             (0x04)    /* USCI Second Stage Modulation: 2 */
#define UCBRS_3             (0x06)    /* USCI Second Stage Modulation: 3 */
#define UCBRS_4             (0x08)    /* USCI Second Stage Modulation: 4 */
#define UCBRS_5             (0x0A)    /* USCI Second Stage Modulation: 5 */
#define UCBRS_6             (0x0C)    /* USCI Second Stage Modulation: 6 */
#define UCBRS_7             (0x0E)    /* USCI Second Stage Modulation: 7 */

/* UCAxSTAT Control Bits */
#define UCLISTEN            (0x80)    /* USCI Listen mode */
#define UCFE                (0x40)    /* USCI Frame Error Flag */
#define UCOE                (0x20)    /* USCI Overrun Error Flag */
#define UCPE                (0x10)    /* USCI Parity Error Flag */
#define UCBRK               (0x08)    /* USCI Break received */
#define UCRXERR             (0x04)    /* USCI RX Error Flag */
#define UCADDR              (0x02)    /* USCI Address received Flag */
#define UCBUSY              (0x01)    /* USCI Busy Flag */
#define UCIDLE              (0x02)    /* USCI Idle line detected Flag */


/* UCBxSTAT Control Bits */
#define UCSCLLOW            (0x40)    /* SCL low */
#define UCGC                (0x20)    /* General Call address received Flag */
#define UCBBUSY             (0x10)    /* Bus Busy Flag */

/* UCAxIRTCTL Control Bits */
#define UCIRTXPL5           (0x80)    /* IRDA Transmit Pulse Length 5 */
#define UCIRTXPL4           (0x40)    /* IRDA Transmit Pulse Length 4 */
#define UCIRTXPL3           (0x20)    /* IRDA Transmit Pulse Length 3 */
#define UCIRTXPL2           (0x10)    /* IRDA Transmit Pulse Length 2 */
#define UCIRTXPL1           (0x08)    /* IRDA Transmit Pulse Length 1 */
#define UCIRTXPL0           (0x04)    /* IRDA Transmit Pulse Length 0 */
#define UCIRTXCLK           (0x02)    /* IRDA Transmit Pulse Clock Select */
#define UCIREN              (0x01)    /* IRDA Encoder/Decoder enable */

/* UCAxIRRCTL Control Bits */
#define UCIRRXFL5           (0x80)    /* IRDA Receive Filter Length 5 */
#define UCIRRXFL4           (0x40)    /* IRDA Receive Filter Length 4 */
#define UCIRRXFL3           (0x20)    /* IRDA Receive Filter Length 3 */
#define UCIRRXFL2           (0x10)    /* IRDA Receive Filter Length 2 */
#define UCIRRXFL1           (0x08)    /* IRDA Receive Filter Length 1 */
#define UCIRRXFL0           (0x04)    /* IRDA Receive Filter Length 0 */
#define UCIRRXPL            (0x02)    /* IRDA Receive Input Polarity */
#define UCIRRXFE            (0x01)    /* IRDA Receive Filter enable */

/* UCAxABCTL Control Bits */
//#define res               (0x80)    /* reserved */
//#define res               (0x40)    /* reserved */
#define UCDELIM1            (0x20)    /* Break Sync Delimiter 1 */
#define UCDELIM0            (0x10)    /* Break Sync Delimiter 0 */
#define UCSTOE              (0x08)    /* Sync-Field Timeout error */
#define UCBTOE              (0x04)    /* Break Timeout error */
//#define res               (0x02)    /* reserved */
#define UCABDEN             (0x01)    /* Auto Baud Rate detect enable */

/* UCBxI2COA Control Bits */
#define UCGCEN              (0x8000)  /* I2C General Call enable */
#define UCOA9               (0x0200)  /* I2C Own Address 9 */
#define UCOA8               (0x0100)  /* I2C Own Address 8 */
#define UCOA7               (0x0080)  /* I2C Own Address 7 */
#define UCOA6               (0x0040)  /* I2C Own Address 6 */
#define UCOA5               (0x0020)  /* I2C Own Address 5 */
#define UCOA4               (0x0010)  /* I2C Own Address 4 */
#define UCOA3               (0x0008)  /* I2C Own Address 3 */
#define UCOA2               (0x0004)  /* I2C Own Address 2 */
#define UCOA1               (0x0002)  /* I2C Own Address 1 */
#define UCOA0               (0x0001)  /* I2C Own Address 0 */

/* UCBxI2COA Control Bits */
#define UCOA7_L             (0x0080)  /* I2C Own Address 7 */
#define UCOA6_L             (0x0040)  /* I2C Own Address 6 */
#define UCOA5_L             (0x0020)  /* I2C Own Address 5 */
#define UCOA4_L             (0x0010)  /* I2C Own Address 4 */
#define UCOA3_L             (0x0008)  /* I2C Own Address 3 */
#define UCOA2_L             (0x0004)  /* I2C Own Address 2 */
#define UCOA1_L             (0x0002)  /* I2C Own Address 1 */
#define UCOA0_L             (0x0001)  /* I2C Own Address 0 */

/* UCBxI2COA Control Bits */
#define UCGCEN_H            (0x0080)  /* I2C General Call enable */
#define UCOA9_H             (0x0002)  /* I2C Own Address 9 */
#define UCOA8_H             (0x0001)  /* I2C Own Address 8 */

/* UCBxI2CSA Control Bits */
#define UCSA9               (0x0200)  /* I2C Slave Address 9 */
#define UCSA8               (0x0100)  /* I2C Slave Address 8 */
#define UCSA7               (0x0080)  /* I2C Slave Address 7 */
#define UCSA6               (0x0040)  /* I2C Slave Address 6 */
#define UCSA5               (0x0020)  /* I2C Slave Address 5 */
#define UCSA4               (0x0010)  /* I2C Slave Address 4 */
#define UCSA3               (0x0008)  /* I2C Slave Address 3 */
#define UCSA2               (0x0004)  /* I2C Slave Address 2 */
#define UCSA1               (0x0002)  /* I2C Slave Address 1 */
#define UCSA0               (0x0001)  /* I2C Slave Address 0 */

/* UCBxI2CSA Control Bits */
#define UCSA7_L             (0x0080)  /* I2C Slave Address 7 */
#define UCSA6_L             (0x0040)  /* I2C Slave Address 6 */
#define UCSA5_L             (0x0020)  /* I2C Slave Address 5 */
#define UCSA4_L             (0x0010)  /* I2C Slave Address 4 */
#define UCSA3_L             (0x0008)  /* I2C Slave Address 3 */
#define UCSA2_L             (0x0004)  /* I2C Slave Address 2 */
#define UCSA1_L             (0x0002)  /* I2C Slave Address 1 */
#define UCSA0_L             (0x0001)  /* I2C Slave Address 0 */

/* UCBxI2CSA Control Bits */
#define UCSA9_H             (0x0002)  /* I2C Slave Address 9 */
#define UCSA8_H             (0x0001)  /* I2C Slave Address 8 */

/* UCAxIE Control Bits */
#define UCTXIE              (0x0002)  /* USCI Transmit Interrupt Enable */
#define UCRXIE              (0x0001)  /* USCI Receive Interrupt Enable */

/* UCAxIE Control Bits */
#define UCTXIE_L            (0x0002)  /* USCI Transmit Interrupt Enable */
#define UCRXIE_L            (0x0001)  /* USCI Receive Interrupt Enable */


/* UCBxIE Control Bits */
#define UCNACKIE            (0x0020)  /* NACK Condition interrupt enable */
#define UCALIE              (0x0010)  /* Arbitration Lost interrupt enable */
#define UCSTPIE             (0x0008)  /* STOP Condition interrupt enable */
#define UCSTTIE             (0x0004)  /* START Condition interrupt enable */
#define UCTXIE              (0x0002)  /* USCI Transmit Interrupt Enable */
#define UCRXIE              (0x0001)  /* USCI Receive Interrupt Enable */

/* UCBxIE Control Bits */
#define UCNACKIE_L          (0x0020)  /* NACK Condition interrupt enable */
#define UCALIE_L            (0x0010)  /* Arbitration Lost interrupt enable */
#define UCSTPIE_L           (0x0008)  /* STOP Condition interrupt enable */
#define UCSTTIE_L           (0x0004)  /* START Condition interrupt enable */
#define UCTXIE_L            (0x0002)  /* USCI Transmit Interrupt Enable */
#define UCRXIE_L            (0x0001)  /* USCI Receive Interrupt Enable */


/* UCAxIFG Control Bits */
#define UCTXIFG             (0x0002)  /* USCI Transmit Interrupt Flag */
#define UCRXIFG             (0x0001)  /* USCI Receive Interrupt Flag */

/* UCAxIFG Control Bits */
#define UCTXIFG_L           (0x0002)  /* USCI Transmit Interrupt Flag */
#define UCRXIFG_L           (0x0001)  /* USCI Receive Interrupt Flag */


/* UCBxIFG Control Bits */
#define UCNACKIFG           (0x0020)  /* NAK Condition interrupt Flag */
#define UCALIFG             (0x0010)  /* Arbitration Lost interrupt Flag */
#define UCSTPIFG            (0x0008)  /* STOP Condition interrupt Flag */
#define UCSTTIFG            (0x0004)  /* START Condition interrupt Flag */
#define UCTXIFG             (0x0002)  /* USCI Transmit Interrupt Flag */
#define UCRXIFG             (0x0001)  /* USCI Receive Interrupt Flag */

/* UCBxIFG Control Bits */
#define UCNACKIFG_L         (0x0020)  /* NAK Condition interrupt Flag */
#define UCALIFG_L           (0x0010)  /* Arbitration Lost interrupt Flag */
#define UCSTPIFG_L          (0x0008)  /* STOP Condition interrupt Flag */
#define UCSTTIFG_L          (0x0004)  /* START Condition interrupt Flag */
#define UCTXIFG_L           (0x0002)  /* USCI Transmit Interrupt Flag */
#define UCRXIFG_L           (0x0001)  /* USCI Receive Interrupt Flag */


/* USCI Definitions */
#define USCI_NONE           (0x0000)    /* No Interrupt pending */
#define USCI_UCRXIFG        (0x0002)    /* USCI UCRXIFG */
#define USCI_UCTXIFG        (0x0004)    /* USCI UCTXIFG */
#define USCI_I2C_UCALIFG    (0x0002)    /* USCI I2C Mode: UCALIFG */
#define USCI_I2C_UCNACKIFG  (0x0004)    /* USCI I2C Mode: UCNACKIFG */
#define USCI_I2C_UCSTTIFG   (0x0006)    /* USCI I2C Mode: UCSTTIFG*/
#define USCI_I2C_UCSTPIFG   (0x0008)    /* USCI I2C Mode: UCSTPIFG*/
#define USCI_I2C_UCRXIFG    (0x000A)    /* USCI I2C Mode: UCRXIFG */
#define USCI_I2C_UCTXIFG    (0x000C)    /* USCI I2C Mode: UCTXIFG */

#endif
/************************************************************
* USCI Ax
************************************************************/
#ifdef  __MSP430_HAS_EUSCI_Ax__      /* Definition to show that Module is available */

#define OFS_UCAxCTLW0         (0x0000)  /* USCI Ax Control Word Register 0 */
#define OFS_UCAxCTLW0_L        OFS_UCAxCTLW0
#define OFS_UCAxCTLW0_H        OFS_UCAxCTLW0+1
#define OFS_UCAxCTL0          (0x0001)
#define OFS_UCAxCTL1          (0x0000)
#define UCAxCTL1            UCAxCTLW0_L  /* USCI Ax Control Register 1 */
#define UCAxCTL0            UCAxCTLW0_H  /* USCI Ax Control Register 0 */
#define OFS_UCAxCTLW1         (0x0002)  /* USCI Ax Control Word Register 1 */
#define OFS_UCAxCTLW1_L        OFS_UCAxCTLW1
#define OFS_UCAxCTLW1_H        OFS_UCAxCTLW1+1
#define OFS_UCAxBRW           (0x0006)  /* USCI Ax Baud Word Rate 0 */
#define OFS_UCAxBRW_L          OFS_UCAxBRW
#define OFS_UCAxBRW_H          OFS_UCAxBRW+1
#define OFS_UCAxBR0           (0x0006)
#define OFS_UCAxBR1           (0x0007)
#define UCAxBR0             UCAxBRW_L /* USCI Ax Baud Rate 0 */
#define UCAxBR1             UCAxBRW_H /* USCI Ax Baud Rate 1 */
#define OFS_UCAxMCTLW         (0x0008)  /* USCI Ax Modulation Control */
#define OFS_UCAxMCTLW_L        OFS_UCAxMCTLW
#define OFS_UCAxMCTLW_H        OFS_UCAxMCTLW+1
#define OFS_UCAxSTATW         (0x000A)  /* USCI Ax Status Register */
#define OFS_UCAxRXBUF         (0x000C)  /* USCI Ax Receive Buffer */
#define OFS_UCAxRXBUF_L        OFS_UCAxRXBUF
#define OFS_UCAxRXBUF_H        OFS_UCAxRXBUF+1
#define OFS_UCAxTXBUF         (0x000E)  /* USCI Ax Transmit Buffer */
#define OFS_UCAxTXBUF_L        OFS_UCAxTXBUF
#define OFS_UCAxTXBUF_H        OFS_UCAxTXBUF+1
#define OFS_UCAxABCTL         (0x0010)  /* USCI Ax LIN Control */
#define OFS_UCAxIRCTL         (0x0012)  /* USCI Ax IrDA Transmit Control */
#define OFS_UCAxIRCTL_L        OFS_UCAxIRCTL
#define OFS_UCAxIRCTL_H        OFS_UCAxIRCTL+1
#define OFS_UCAxIRTCTL        (0x0012)
#define OFS_UCAxIRRCTL        (0x0013)
#define UCAxIRTCTL          UCAxIRCTL_L  /* USCI Ax IrDA Transmit Control */
#define UCAxIRRCTL          UCAxIRCTL_H  /* USCI Ax IrDA Receive Control */
#define OFS_UCAxIE            (0x001A)  /* USCI Ax Interrupt Enable Register */
#define OFS_UCAxIE_L           OFS_UCAxIE
#define OFS_UCAxIE_H           OFS_UCAxIE+1
#define OFS_UCAxIFG           (0x001C)  /* USCI Ax Interrupt Flags Register */
#define OFS_UCAxIFG_L          OFS_UCAxIFG
#define OFS_UCAxIFG_H          OFS_UCAxIFG+1
#define OFS_UCAxIE__UART      (0x001A)
#define OFS_UCAxIE__UART_L     OFS_UCAxIE__UART
#define OFS_UCAxIE__UART_H     OFS_UCAxIE__UART+1
#define OFS_UCAxIFG__UART     (0x001C)
#define OFS_UCAxIFG__UART_L    OFS_UCAxIFG__UART
#define OFS_UCAxIFG__UART_H    OFS_UCAxIFG__UART+1
#define OFS_UCAxIV            (0x001E)  /* USCI Ax Interrupt Vector Register */

#define OFS_UCAxCTLW0__SPI    (0x0000)
#define OFS_UCAxCTLW0__SPI_L   OFS_UCAxCTLW0__SPI
#define OFS_UCAxCTLW0__SPI_H   OFS_UCAxCTLW0__SPI+1
#define OFS_UCAxCTL0__SPI     (0x0001)
#define OFS_UCAxCTL1__SPI     (0x0000)
#define OFS_UCAxBRW__SPI      (0x0006)
#define OFS_UCAxBRW__SPI_L     OFS_UCAxBRW__SPI
#define OFS_UCAxBRW__SPI_H     OFS_UCAxBRW__SPI+1
#define OFS_UCAxBR0__SPI      (0x0006)
#define OFS_UCAxBR1__SPI      (0x0007)
#define OFS_UCAxSTATW__SPI    (0x000A)
#define OFS_UCAxRXBUF__SPI    (0x000C)
#define OFS_UCAxRXBUF__SPI_L   OFS_UCAxRXBUF__SPI
#define OFS_UCAxRXBUF__SPI_H   OFS_UCAxRXBUF__SPI+1
#define OFS_UCAxTXBUF__SPI    (0x000E)
#define OFS_UCAxTXBUF__SPI_L   OFS_UCAxTXBUF__SPI
#define OFS_UCAxTXBUF__SPI_H   OFS_UCAxTXBUF__SPI+1
#define OFS_UCAxIE__SPI       (0x001A)
#define OFS_UCAxIFG__SPI      (0x001C)
#define OFS_UCAxIV__SPI       (0x001E)

#endif
/************************************************************
* USCI Bx
************************************************************/
#ifdef  __MSP430_HAS_EUSCI_Bx__       /* Definition to show that Module is available */

#define OFS_UCBxCTLW0__SPI    (0x0000)
#define OFS_UCBxCTLW0__SPI_L   OFS_UCBxCTLW0__SPI
#define OFS_UCBxCTLW0__SPI_H   OFS_UCBxCTLW0__SPI+1
#define OFS_UCBxCTL0__SPI     (0x0001)
#define OFS_UCBxCTL1__SPI     (0x0000)
#define OFS_UCBxBRW__SPI      (0x0006)
#define OFS_UCBxBRW__SPI_L     OFS_UCBxBRW__SPI
#define OFS_UCBxBRW__SPI_H     OFS_UCBxBRW__SPI+1
#define OFS_UCBxBR0__SPI      (0x0006)
#define OFS_UCBxBR1__SPI      (0x0007)
#define OFS_UCBxSTATW__SPI    (0x0008)
#define OFS_UCBxSTATW__SPI_L   OFS_UCBxSTATW__SPI
#define OFS_UCBxSTATW__SPI_H   OFS_UCBxSTATW__SPI+1
#define OFS_UCBxRXBUF__SPI    (0x000C)
#define OFS_UCBxRXBUF__SPI_L   OFS_UCBxRXBUF__SPI
#define OFS_UCBxRXBUF__SPI_H   OFS_UCBxRXBUF__SPI+1
#define OFS_UCBxTXBUF__SPI    (0x000E)
#define OFS_UCBxTXBUF__SPI_L   OFS_UCBxTXBUF__SPI
#define OFS_UCBxTXBUF__SPI_H   OFS_UCBxTXBUF__SPI+1
#define OFS_UCBxIE__SPI       (0x002A)
#define OFS_UCBxIE__SPI_L      OFS_UCBxIE__SPI
#define OFS_UCBxIE__SPI_H      OFS_UCBxIE__SPI+1
#define OFS_UCBxIFG__SPI      (0x002C)
#define OFS_UCBxIFG__SPI_L     OFS_UCBxIFG__SPI
#define OFS_UCBxIFG__SPI_H     OFS_UCBxIFG__SPI+1
#define OFS_UCBxIV__SPI       (0x002E)

#define OFS_UCBxCTLW0         (0x0000)  /* USCI Bx Control Word Register 0 */
#define OFS_UCBxCTLW0_L        OFS_UCBxCTLW0
#define OFS_UCBxCTLW0_H        OFS_UCBxCTLW0+1
#define OFS_UCBxCTL0          (0x0001)
#define OFS_UCBxCTL1          (0x0000)
#define UCBxCTL1            UCBxCTLW0_L  /* USCI Bx Control Register 1 */
#define UCBxCTL0            UCBxCTLW0_H  /* USCI Bx Control Register 0 */
#define OFS_UCBxCTLW1         (0x0002)  /* USCI Bx Control Word Register 1 */
#define OFS_UCBxCTLW1_L        OFS_UCBxCTLW1
#define OFS_UCBxCTLW1_H        OFS_UCBxCTLW1+1
#define OFS_UCBxBRW           (0x0006)  /* USCI Bx Baud Word Rate 0 */
#define OFS_UCBxBRW_L          OFS_UCBxBRW
#define OFS_UCBxBRW_H          OFS_UCBxBRW+1
#define OFS_UCBxBR0           (0x0006)
#define OFS_UCBxBR1           (0x0007)
#define UCBxBR0             UCBxBRW_L /* USCI Bx Baud Rate 0 */
#define UCBxBR1             UCBxBRW_H /* USCI Bx Baud Rate 1 */
#define OFS_UCBxSTATW         (0x0008)  /* USCI Bx Status Word Register */
#define OFS_UCBxSTATW_L        OFS_UCBxSTATW
#define OFS_UCBxSTATW_H        OFS_UCBxSTATW+1
#define OFS_UCBxSTATW__I2C    (0x0008)
#define OFS_UCBxSTAT__I2C     (0x0008)
#define OFS_UCBxBCNT__I2C     (0x0009)
#define UCBxSTAT            UCBxSTATW_L /* USCI Bx Status Register */
#define UCBxBCNT            UCBxSTATW_H /* USCI Bx Byte Counter Register */
#define OFS_UCBxTBCNT         (0x000A)  /* USCI Bx Byte Counter Threshold Register */
#define OFS_UCBxTBCNT_L        OFS_UCBxTBCNT
#define OFS_UCBxTBCNT_H        OFS_UCBxTBCNT+1
#define OFS_UCBxRXBUF         (0x000C)  /* USCI Bx Receive Buffer */
#define OFS_UCBxRXBUF_L        OFS_UCBxRXBUF
#define OFS_UCBxRXBUF_H        OFS_UCBxRXBUF+1
#define OFS_UCBxTXBUF         (0x000E)  /* USCI Bx Transmit Buffer */
#define OFS_UCBxTXBUF_L        OFS_UCBxTXBUF
#define OFS_UCBxTXBUF_H        OFS_UCBxTXBUF+1
#define OFS_UCBxI2COA0        (0x0014)  /* USCI Bx I2C Own Address 0 */
#define OFS_UCBxI2COA0_L       OFS_UCBxI2COA0
#define OFS_UCBxI2COA0_H       OFS_UCBxI2COA0+1
#define OFS_UCBxI2COA1        (0x0016)  /* USCI Bx I2C Own Address 1 */
#define OFS_UCBxI2COA1_L       OFS_UCBxI2COA1
#define OFS_UCBxI2COA1_H       OFS_UCBxI2COA1+1
#define OFS_UCBxI2COA2        (0x0018)  /* USCI Bx I2C Own Address 2 */
#define OFS_UCBxI2COA2_L       OFS_UCBxI2COA2
#define OFS_UCBxI2COA2_H       OFS_UCBxI2COA2+1
#define OFS_UCBxI2COA3        (0x001A)  /* USCI Bx I2C Own Address 3 */
#define OFS_UCBxI2COA3_L       OFS_UCBxI2COA3
#define OFS_UCBxI2COA3_H       OFS_UCBxI2COA3+1
#define OFS_UCBxADDRX         (0x001C)  /* USCI Bx Received Address Register */
#define OFS_UCBxADDRX_L        OFS_UCBxADDRX
#define OFS_UCBxADDRX_H        OFS_UCBxADDRX+1
#define OFS_UCBxADDMASK       (0x001E)  /* USCI Bx Address Mask Register */
#define OFS_UCBxADDMASK_L      OFS_UCBxADDMASK
#define OFS_UCBxADDMASK_H      OFS_UCBxADDMASK+1
#define OFS_UCBxI2CSA         (0x0020)  /* USCI Bx I2C Slave Address */
#define OFS_UCBxI2CSA_L        OFS_UCBxI2CSA
#define OFS_UCBxI2CSA_H        OFS_UCBxI2CSA+1
#define OFS_UCBxIE            (0x002A)  /* USCI Bx Interrupt Enable Register */
#define OFS_UCBxIE_L           OFS_UCBxIE
#define OFS_UCBxIE_H           OFS_UCBxIE+1
#define OFS_UCBxIFG           (0x002C)  /* USCI Bx Interrupt Flags Register */
#define OFS_UCBxIFG_L          OFS_UCBxIFG
#define OFS_UCBxIFG_H          OFS_UCBxIFG+1
#define OFS_UCBxIE__I2C       (0x002A)
#define OFS_UCBxIE__I2C_L      OFS_UCBxIE__I2C
#define OFS_UCBxIE__I2C_H      OFS_UCBxIE__I2C+1
#define OFS_UCBxIFG__I2C      (0x002C)
#define OFS_UCBxIFG__I2C_L     OFS_UCBxIFG__I2C
#define OFS_UCBxIFG__I2C_H     OFS_UCBxIFG__I2C+1
#define OFS_UCBxIV            (0x002E)  /* USCI Bx Interrupt Vector Register */

#endif
#if (defined(__MSP430_HAS_EUSCI_Ax__) || defined(__MSP430_HAS_EUSCI_Bx__))

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















#endif
/************************************************************
* WATCHDOG TIMER A
************************************************************/
#ifdef  __MSP430_HAS_WDT_A__          /* Definition to show that Module is available */

#define OFS_WDTCTL            (0x000C)  /* Watchdog Timer Control */
#define OFS_WDTCTL_L           OFS_WDTCTL
#define OFS_WDTCTL_H           OFS_WDTCTL+1
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

#endif

/************************************************************
* TLV Descriptors
************************************************************/
#define __MSP430_HAS_TLV__                /* Definition to show that Module is available */
#define TLV_BASE __MSP430_BASEADDRESS_TLV__

#define TLV_START             (0x1A08)    /* Start Address of the TLV structure */
#define TLV_END               (0x1AFF)    /* End Address of the TLV structure */

#define TLV_LDTAG             (0x01)      /*  Legacy descriptor (1xx, 2xx, 4xx families) */
#define TLV_PDTAG             (0x02)      /*  Peripheral discovery descriptor */
#define TLV_Reserved3         (0x03)      /*  Future usage */
#define TLV_Reserved4         (0x04)      /*  Future usage */
#define TLV_BLANK             (0x05)      /*  Blank descriptor */
#define TLV_Reserved6         (0x06)      /*  Future usage */
#define TLV_Reserved7         (0x07)      /*  Serial Number */
#define TLV_DIERECORD         (0x08)      /*  Die Record  */
#define TLV_ADCCAL            (0x11)      /*  ADC12 calibration */
#define TLV_ADC12CAL          (0x11)      /*  ADC12 calibration */
#define TLV_REFCAL            (0x12)      /*  REF calibration */
#define TLV_ADC10CAL          (0x13)      /*  ADC10 calibration */
#define TLV_TIMERDCAL         (0x15)      /*  TIMER_D calibration */
#define TLV_TAGEXT            (0xFE)      /*  Tag extender */
#define TLV_TAGEND            (0xFF)      /*  Tag End of Table */

/************************************************************
* Interrupt Vectors (offset from 0xFF80)
************************************************************/



/************************************************************
* End of Modules
************************************************************/
#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* #ifndef __msp430F5XX_F6XXGENERIC */

