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
* MSP430FR57XXGENERIC device.
*
* Texas Instruments, Version 1.0
*
* Rev. 1.0, Setup
*
*
********************************************************************/

#ifndef __msp430FR57XXGENERIC
#define __msp430FR57XXGENERIC

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
* ADC10_B
************************************************************/
#ifdef  __MSP430_HAS_ADC10_B__        /* Definition to show that Module is available */

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
* Comparator D
************************************************************/
#ifdef  __MSP430_HAS_COMPD__          /* Definition to show that Module is available */

#define OFS_CDCTL0            (0x0000)  /* Comparator D Control Register 0 */
#define OFS_CDCTL0_L           OFS_CDCTL0
#define OFS_CDCTL0_H           OFS_CDCTL0+1
#define OFS_CDCTL1            (0x0002)  /* Comparator D Control Register 1 */
#define OFS_CDCTL1_L           OFS_CDCTL1
#define OFS_CDCTL1_H           OFS_CDCTL1+1
#define OFS_CDCTL2            (0x0004)  /* Comparator D Control Register 2 */
#define OFS_CDCTL2_L           OFS_CDCTL2
#define OFS_CDCTL2_H           OFS_CDCTL2+1
#define OFS_CDCTL3            (0x0006)  /* Comparator D Control Register 3 */
#define OFS_CDCTL3_L           OFS_CDCTL3
#define OFS_CDCTL3_H           OFS_CDCTL3+1
#define OFS_CDINT             (0x000C)  /* Comparator D Interrupt Register */
#define OFS_CDINT_L            OFS_CDINT
#define OFS_CDINT_H            OFS_CDINT+1
#define OFS_CDIV              (0x000E)  /* Comparator D Interrupt Vector Word */
#define OFS_CDIV_L             OFS_CDIV
#define OFS_CDIV_H             OFS_CDIV+1


/* CDCTL0 Control Bits */
#define CDIPSEL0            (0x0001)  /* Comp. D Pos. Channel Input Select 0 */
#define CDIPSEL1            (0x0002)  /* Comp. D Pos. Channel Input Select 1 */
#define CDIPSEL2            (0x0004)  /* Comp. D Pos. Channel Input Select 2 */
#define CDIPSEL3            (0x0008)  /* Comp. D Pos. Channel Input Select 3 */
//#define RESERVED            (0x0010)  /* Comp. D */
//#define RESERVED            (0x0020)  /* Comp. D */
//#define RESERVED            (0x0040)  /* Comp. D */
#define CDIPEN              (0x0080)  /* Comp. D Pos. Channel Input Enable */
#define CDIMSEL0            (0x0100)  /* Comp. D Neg. Channel Input Select 0 */
#define CDIMSEL1            (0x0200)  /* Comp. D Neg. Channel Input Select 1 */
#define CDIMSEL2            (0x0400)  /* Comp. D Neg. Channel Input Select 2 */
#define CDIMSEL3            (0x0800)  /* Comp. D Neg. Channel Input Select 3 */
//#define RESERVED            (0x1000)  /* Comp. D */
//#define RESERVED            (0x2000)  /* Comp. D */
//#define RESERVED            (0x4000)  /* Comp. D */
#define CDIMEN              (0x8000)  /* Comp. D Neg. Channel Input Enable */

/* CDCTL0 Control Bits */
#define CDIPSEL0_L          (0x0001)  /* Comp. D Pos. Channel Input Select 0 */
#define CDIPSEL1_L          (0x0002)  /* Comp. D Pos. Channel Input Select 1 */
#define CDIPSEL2_L          (0x0004)  /* Comp. D Pos. Channel Input Select 2 */
#define CDIPSEL3_L          (0x0008)  /* Comp. D Pos. Channel Input Select 3 */
//#define RESERVED            (0x0010)  /* Comp. D */
//#define RESERVED            (0x0020)  /* Comp. D */
//#define RESERVED            (0x0040)  /* Comp. D */
#define CDIPEN_L            (0x0080)  /* Comp. D Pos. Channel Input Enable */
//#define RESERVED            (0x1000)  /* Comp. D */
//#define RESERVED            (0x2000)  /* Comp. D */
//#define RESERVED            (0x4000)  /* Comp. D */

/* CDCTL0 Control Bits */
//#define RESERVED            (0x0010)  /* Comp. D */
//#define RESERVED            (0x0020)  /* Comp. D */
//#define RESERVED            (0x0040)  /* Comp. D */
#define CDIMSEL0_H          (0x0001)  /* Comp. D Neg. Channel Input Select 0 */
#define CDIMSEL1_H          (0x0002)  /* Comp. D Neg. Channel Input Select 1 */
#define CDIMSEL2_H          (0x0004)  /* Comp. D Neg. Channel Input Select 2 */
#define CDIMSEL3_H          (0x0008)  /* Comp. D Neg. Channel Input Select 3 */
//#define RESERVED            (0x1000)  /* Comp. D */
//#define RESERVED            (0x2000)  /* Comp. D */
//#define RESERVED            (0x4000)  /* Comp. D */
#define CDIMEN_H            (0x0080)  /* Comp. D Neg. Channel Input Enable */

#define CDIPSEL_0           (0x0000)  /* Comp. D V+ terminal Input Select: Channel 0 */
#define CDIPSEL_1           (0x0001)  /* Comp. D V+ terminal Input Select: Channel 1 */
#define CDIPSEL_2           (0x0002)  /* Comp. D V+ terminal Input Select: Channel 2 */
#define CDIPSEL_3           (0x0003)  /* Comp. D V+ terminal Input Select: Channel 3 */
#define CDIPSEL_4           (0x0004)  /* Comp. D V+ terminal Input Select: Channel 4 */
#define CDIPSEL_5           (0x0005)  /* Comp. D V+ terminal Input Select: Channel 5 */
#define CDIPSEL_6           (0x0006)  /* Comp. D V+ terminal Input Select: Channel 6 */
#define CDIPSEL_7           (0x0007)  /* Comp. D V+ terminal Input Select: Channel 7 */
#define CDIPSEL_8           (0x0008)  /* Comp. D V+ terminal Input Select: Channel 8 */
#define CDIPSEL_9           (0x0009)  /* Comp. D V+ terminal Input Select: Channel 9 */
#define CDIPSEL_10          (0x000A)  /* Comp. D V+ terminal Input Select: Channel 10 */
#define CDIPSEL_11          (0x000B)  /* Comp. D V+ terminal Input Select: Channel 11 */
#define CDIPSEL_12          (0x000C)  /* Comp. D V+ terminal Input Select: Channel 12 */
#define CDIPSEL_13          (0x000D)  /* Comp. D V+ terminal Input Select: Channel 13 */
#define CDIPSEL_14          (0x000E)  /* Comp. D V+ terminal Input Select: Channel 14 */
#define CDIPSEL_15          (0x000F)  /* Comp. D V+ terminal Input Select: Channel 15 */

#define CDIMSEL_0           (0x0000)  /* Comp. D V- Terminal Input Select: Channel 0 */
#define CDIMSEL_1           (0x0100)  /* Comp. D V- Terminal Input Select: Channel 1 */
#define CDIMSEL_2           (0x0200)  /* Comp. D V- Terminal Input Select: Channel 2 */
#define CDIMSEL_3           (0x0300)  /* Comp. D V- Terminal Input Select: Channel 3 */
#define CDIMSEL_4           (0x0400)  /* Comp. D V- Terminal Input Select: Channel 4 */
#define CDIMSEL_5           (0x0500)  /* Comp. D V- Terminal Input Select: Channel 5 */
#define CDIMSEL_6           (0x0600)  /* Comp. D V- Terminal Input Select: Channel 6 */
#define CDIMSEL_7           (0x0700)  /* Comp. D V- Terminal Input Select: Channel 7 */
#define CDIMSEL_8           (0x0800)  /* Comp. D V- terminal Input Select: Channel 8 */
#define CDIMSEL_9           (0x0900)  /* Comp. D V- terminal Input Select: Channel 9 */
#define CDIMSEL_10          (0x0A00)  /* Comp. D V- terminal Input Select: Channel 10 */
#define CDIMSEL_11          (0x0B00)  /* Comp. D V- terminal Input Select: Channel 11 */
#define CDIMSEL_12          (0x0C00)  /* Comp. D V- terminal Input Select: Channel 12 */
#define CDIMSEL_13          (0x0D00)  /* Comp. D V- terminal Input Select: Channel 13 */
#define CDIMSEL_14          (0x0E00)  /* Comp. D V- terminal Input Select: Channel 14 */
#define CDIMSEL_15          (0x0F00)  /* Comp. D V- terminal Input Select: Channel 15 */

/* CDCTL1 Control Bits */
#define CDOUT               (0x0001)  /* Comp. D Output */
#define CDOUTPOL            (0x0002)  /* Comp. D Output Polarity */
#define CDF                 (0x0004)  /* Comp. D Enable Output Filter */
#define CDIES               (0x0008)  /* Comp. D Interrupt Edge Select */
#define CDSHORT             (0x0010)  /* Comp. D Input Short */
#define CDEX                (0x0020)  /* Comp. D Exchange Inputs */
#define CDFDLY0             (0x0040)  /* Comp. D Filter delay Bit 0 */
#define CDFDLY1             (0x0080)  /* Comp. D Filter delay Bit 1 */
//#define RESERVED            (0x0100)  /* Comp. D */
//#define RESERVED            (0x0200)  /* Comp. D */
#define CDON                (0x0400)  /* Comp. D enable */
#define CDMRVL              (0x0800)  /* Comp. D CDMRV Level */
#define CDMRVS              (0x1000)  /* Comp. D Output selects between VREF0 or VREF1*/
//#define RESERVED            (0x2000)  /* Comp. D */
//#define RESERVED            (0x4000)  /* Comp. D */
//#define RESERVED            (0x8000)  /* Comp. D */

/* CDCTL1 Control Bits */
#define CDOUT_L             (0x0001)  /* Comp. D Output */
#define CDOUTPOL_L          (0x0002)  /* Comp. D Output Polarity */
#define CDF_L               (0x0004)  /* Comp. D Enable Output Filter */
#define CDIES_L             (0x0008)  /* Comp. D Interrupt Edge Select */
#define CDSHORT_L           (0x0010)  /* Comp. D Input Short */
#define CDEX_L              (0x0020)  /* Comp. D Exchange Inputs */
#define CDFDLY0_L           (0x0040)  /* Comp. D Filter delay Bit 0 */
#define CDFDLY1_L           (0x0080)  /* Comp. D Filter delay Bit 1 */
//#define RESERVED            (0x0100)  /* Comp. D */
//#define RESERVED            (0x0200)  /* Comp. D */
//#define RESERVED            (0x2000)  /* Comp. D */
//#define RESERVED            (0x4000)  /* Comp. D */
//#define RESERVED            (0x8000)  /* Comp. D */

/* CDCTL1 Control Bits */
//#define RESERVED            (0x0100)  /* Comp. D */
//#define RESERVED            (0x0200)  /* Comp. D */
#define CDON_H              (0x0004)  /* Comp. D enable */
#define CDMRVL_H            (0x0008)  /* Comp. D CDMRV Level */
#define CDMRVS_H            (0x0010)  /* Comp. D Output selects between VREF0 or VREF1*/
//#define RESERVED            (0x2000)  /* Comp. D */
//#define RESERVED            (0x4000)  /* Comp. D */
//#define RESERVED            (0x8000)  /* Comp. D */

#define CDFDLY_0           (0x0000)  /* Comp. D Filter delay 0 : 450ns */
#define CDFDLY_1           (0x0040)  /* Comp. D Filter delay 1 : 900ns */
#define CDFDLY_2           (0x0080)  /* Comp. D Filter delay 2 : 1800ns */
#define CDFDLY_3           (0x00C0)  /* Comp. D Filter delay 3 : 3600ns */


/* CDCTL2 Control Bits */
#define CDREF00             (0x0001)  /* Comp. D Reference 0 Resistor Select Bit : 0 */
#define CDREF01             (0x0002)  /* Comp. D Reference 0 Resistor Select Bit : 1 */
#define CDREF02             (0x0004)  /* Comp. D Reference 0 Resistor Select Bit : 2 */
#define CDREF03             (0x0008)  /* Comp. D Reference 0 Resistor Select Bit : 3 */
#define CDREF04             (0x0010)  /* Comp. D Reference 0 Resistor Select Bit : 4 */
#define CDRSEL              (0x0020)  /* Comp. D Reference select */
#define CDRS0               (0x0040)  /* Comp. D Reference Source Bit : 0 */
#define CDRS1               (0x0080)  /* Comp. D Reference Source Bit : 1 */
#define CDREF10             (0x0100)  /* Comp. D Reference 1 Resistor Select Bit : 0 */
#define CDREF11             (0x0200)  /* Comp. D Reference 1 Resistor Select Bit : 1 */
#define CDREF12             (0x0400)  /* Comp. D Reference 1 Resistor Select Bit : 2 */
#define CDREF13             (0x0800)  /* Comp. D Reference 1 Resistor Select Bit : 3 */
#define CDREF14             (0x1000)  /* Comp. D Reference 1 Resistor Select Bit : 4 */
#define CDREFL0             (0x2000)  /* Comp. D Reference voltage level Bit : 0 */
#define CDREFL1             (0x4000)  /* Comp. D Reference voltage level Bit : 1 */
#define CDREFACC            (0x8000)  /* Comp. D Reference Accuracy */

/* CDCTL2 Control Bits */
#define CDREF00_L           (0x0001)  /* Comp. D Reference 0 Resistor Select Bit : 0 */
#define CDREF01_L           (0x0002)  /* Comp. D Reference 0 Resistor Select Bit : 1 */
#define CDREF02_L           (0x0004)  /* Comp. D Reference 0 Resistor Select Bit : 2 */
#define CDREF03_L           (0x0008)  /* Comp. D Reference 0 Resistor Select Bit : 3 */
#define CDREF04_L           (0x0010)  /* Comp. D Reference 0 Resistor Select Bit : 4 */
#define CDRSEL_L            (0x0020)  /* Comp. D Reference select */
#define CDRS0_L             (0x0040)  /* Comp. D Reference Source Bit : 0 */
#define CDRS1_L             (0x0080)  /* Comp. D Reference Source Bit : 1 */

/* CDCTL2 Control Bits */
#define CDREF10_H           (0x0001)  /* Comp. D Reference 1 Resistor Select Bit : 0 */
#define CDREF11_H           (0x0002)  /* Comp. D Reference 1 Resistor Select Bit : 1 */
#define CDREF12_H           (0x0004)  /* Comp. D Reference 1 Resistor Select Bit : 2 */
#define CDREF13_H           (0x0008)  /* Comp. D Reference 1 Resistor Select Bit : 3 */
#define CDREF14_H           (0x0010)  /* Comp. D Reference 1 Resistor Select Bit : 4 */
#define CDREFL0_H           (0x0020)  /* Comp. D Reference voltage level Bit : 0 */
#define CDREFL1_H           (0x0040)  /* Comp. D Reference voltage level Bit : 1 */
#define CDREFACC_H          (0x0080)  /* Comp. D Reference Accuracy */

#define CDREF0_0            (0x0000)  /* Comp. D Int. Ref.0 Select 0 : 1/32 */
#define CDREF0_1            (0x0001)  /* Comp. D Int. Ref.0 Select 1 : 2/32 */
#define CDREF0_2            (0x0002)  /* Comp. D Int. Ref.0 Select 2 : 3/32 */
#define CDREF0_3            (0x0003)  /* Comp. D Int. Ref.0 Select 3 : 4/32 */
#define CDREF0_4            (0x0004)  /* Comp. D Int. Ref.0 Select 4 : 5/32 */
#define CDREF0_5            (0x0005)  /* Comp. D Int. Ref.0 Select 5 : 6/32 */
#define CDREF0_6            (0x0006)  /* Comp. D Int. Ref.0 Select 6 : 7/32 */
#define CDREF0_7            (0x0007)  /* Comp. D Int. Ref.0 Select 7 : 8/32 */
#define CDREF0_8            (0x0008)  /* Comp. D Int. Ref.0 Select 0 : 9/32 */
#define CDREF0_9            (0x0009)  /* Comp. D Int. Ref.0 Select 1 : 10/32 */
#define CDREF0_10           (0x000A)  /* Comp. D Int. Ref.0 Select 2 : 11/32 */
#define CDREF0_11           (0x000B)  /* Comp. D Int. Ref.0 Select 3 : 12/32 */
#define CDREF0_12           (0x000C)  /* Comp. D Int. Ref.0 Select 4 : 13/32 */
#define CDREF0_13           (0x000D)  /* Comp. D Int. Ref.0 Select 5 : 14/32 */
#define CDREF0_14           (0x000E)  /* Comp. D Int. Ref.0 Select 6 : 15/32 */
#define CDREF0_15           (0x000F)  /* Comp. D Int. Ref.0 Select 7 : 16/32 */
#define CDREF0_16           (0x0010)  /* Comp. D Int. Ref.0 Select 0 : 17/32 */
#define CDREF0_17           (0x0011)  /* Comp. D Int. Ref.0 Select 1 : 18/32 */
#define CDREF0_18           (0x0012)  /* Comp. D Int. Ref.0 Select 2 : 19/32 */
#define CDREF0_19           (0x0013)  /* Comp. D Int. Ref.0 Select 3 : 20/32 */
#define CDREF0_20           (0x0014)  /* Comp. D Int. Ref.0 Select 4 : 21/32 */
#define CDREF0_21           (0x0015)  /* Comp. D Int. Ref.0 Select 5 : 22/32 */
#define CDREF0_22           (0x0016)  /* Comp. D Int. Ref.0 Select 6 : 23/32 */
#define CDREF0_23           (0x0017)  /* Comp. D Int. Ref.0 Select 7 : 24/32 */
#define CDREF0_24           (0x0018)  /* Comp. D Int. Ref.0 Select 0 : 25/32 */
#define CDREF0_25           (0x0019)  /* Comp. D Int. Ref.0 Select 1 : 26/32 */
#define CDREF0_26           (0x001A)  /* Comp. D Int. Ref.0 Select 2 : 27/32 */
#define CDREF0_27           (0x001B)  /* Comp. D Int. Ref.0 Select 3 : 28/32 */
#define CDREF0_28           (0x001C)  /* Comp. D Int. Ref.0 Select 4 : 29/32 */
#define CDREF0_29           (0x001D)  /* Comp. D Int. Ref.0 Select 5 : 30/32 */
#define CDREF0_30           (0x001E)  /* Comp. D Int. Ref.0 Select 6 : 31/32 */
#define CDREF0_31           (0x001F)  /* Comp. D Int. Ref.0 Select 7 : 32/32 */

#define CDRS_0              (0x0000)  /* Comp. D Reference Source 0 : Off */
#define CDRS_1              (0x0040)  /* Comp. D Reference Source 1 : Vcc */
#define CDRS_2              (0x0080)  /* Comp. D Reference Source 2 : Shared Ref. */
#define CDRS_3              (0x00C0)  /* Comp. D Reference Source 3 : Shared Ref. / Off */

#define CDREF1_0            (0x0000)  /* Comp. D Int. Ref.1 Select 0 : 1/32 */
#define CDREF1_1            (0x0100)  /* Comp. D Int. Ref.1 Select 1 : 2/32 */
#define CDREF1_2            (0x0200)  /* Comp. D Int. Ref.1 Select 2 : 3/32 */
#define CDREF1_3            (0x0300)  /* Comp. D Int. Ref.1 Select 3 : 4/32 */
#define CDREF1_4            (0x0400)  /* Comp. D Int. Ref.1 Select 4 : 5/32 */
#define CDREF1_5            (0x0500)  /* Comp. D Int. Ref.1 Select 5 : 6/32 */
#define CDREF1_6            (0x0600)  /* Comp. D Int. Ref.1 Select 6 : 7/32 */
#define CDREF1_7            (0x0700)  /* Comp. D Int. Ref.1 Select 7 : 8/32 */
#define CDREF1_8            (0x0800)  /* Comp. D Int. Ref.1 Select 0 : 9/32 */
#define CDREF1_9            (0x0900)  /* Comp. D Int. Ref.1 Select 1 : 10/32 */
#define CDREF1_10           (0x0A00)  /* Comp. D Int. Ref.1 Select 2 : 11/32 */
#define CDREF1_11           (0x0B00)  /* Comp. D Int. Ref.1 Select 3 : 12/32 */
#define CDREF1_12           (0x0C00)  /* Comp. D Int. Ref.1 Select 4 : 13/32 */
#define CDREF1_13           (0x0D00)  /* Comp. D Int. Ref.1 Select 5 : 14/32 */
#define CDREF1_14           (0x0E00)  /* Comp. D Int. Ref.1 Select 6 : 15/32 */
#define CDREF1_15           (0x0F00)  /* Comp. D Int. Ref.1 Select 7 : 16/32 */
#define CDREF1_16           (0x1000)  /* Comp. D Int. Ref.1 Select 0 : 17/32 */
#define CDREF1_17           (0x1100)  /* Comp. D Int. Ref.1 Select 1 : 18/32 */
#define CDREF1_18           (0x1200)  /* Comp. D Int. Ref.1 Select 2 : 19/32 */
#define CDREF1_19           (0x1300)  /* Comp. D Int. Ref.1 Select 3 : 20/32 */
#define CDREF1_20           (0x1400)  /* Comp. D Int. Ref.1 Select 4 : 21/32 */
#define CDREF1_21           (0x1500)  /* Comp. D Int. Ref.1 Select 5 : 22/32 */
#define CDREF1_22           (0x1600)  /* Comp. D Int. Ref.1 Select 6 : 23/32 */
#define CDREF1_23           (0x1700)  /* Comp. D Int. Ref.1 Select 7 : 24/32 */
#define CDREF1_24           (0x1800)  /* Comp. D Int. Ref.1 Select 0 : 25/32 */
#define CDREF1_25           (0x1900)  /* Comp. D Int. Ref.1 Select 1 : 26/32 */
#define CDREF1_26           (0x1A00)  /* Comp. D Int. Ref.1 Select 2 : 27/32 */
#define CDREF1_27           (0x1B00)  /* Comp. D Int. Ref.1 Select 3 : 28/32 */
#define CDREF1_28           (0x1C00)  /* Comp. D Int. Ref.1 Select 4 : 29/32 */
#define CDREF1_29           (0x1D00)  /* Comp. D Int. Ref.1 Select 5 : 30/32 */
#define CDREF1_30           (0x1E00)  /* Comp. D Int. Ref.1 Select 6 : 31/32 */
#define CDREF1_31           (0x1F00)  /* Comp. D Int. Ref.1 Select 7 : 32/32 */

#define CDREFL_0            (0x0000)  /* Comp. D Reference voltage level 0 : None */
#define CDREFL_1            (0x2000)  /* Comp. D Reference voltage level 1 : 1.5V */
#define CDREFL_2            (0x4000)  /* Comp. D Reference voltage level 2 : 2.0V  */
#define CDREFL_3            (0x6000)  /* Comp. D Reference voltage level 3 : 2.5V  */


#define CDPD0               (0x0001)  /* Comp. D Disable Input Buffer of Port Register .0 */
#define CDPD1               (0x0002)  /* Comp. D Disable Input Buffer of Port Register .1 */
#define CDPD2               (0x0004)  /* Comp. D Disable Input Buffer of Port Register .2 */
#define CDPD3               (0x0008)  /* Comp. D Disable Input Buffer of Port Register .3 */
#define CDPD4               (0x0010)  /* Comp. D Disable Input Buffer of Port Register .4 */
#define CDPD5               (0x0020)  /* Comp. D Disable Input Buffer of Port Register .5 */
#define CDPD6               (0x0040)  /* Comp. D Disable Input Buffer of Port Register .6 */
#define CDPD7               (0x0080)  /* Comp. D Disable Input Buffer of Port Register .7 */
#define CDPD8               (0x0100)  /* Comp. D Disable Input Buffer of Port Register .8 */
#define CDPD9               (0x0200)  /* Comp. D Disable Input Buffer of Port Register .9 */
#define CDPD10              (0x0400)  /* Comp. D Disable Input Buffer of Port Register .10 */
#define CDPD11              (0x0800)  /* Comp. D Disable Input Buffer of Port Register .11 */
#define CDPD12              (0x1000)  /* Comp. D Disable Input Buffer of Port Register .12 */
#define CDPD13              (0x2000)  /* Comp. D Disable Input Buffer of Port Register .13 */
#define CDPD14              (0x4000)  /* Comp. D Disable Input Buffer of Port Register .14 */
#define CDPD15              (0x8000)  /* Comp. D Disable Input Buffer of Port Register .15 */

#define CDPD0_L             (0x0001)  /* Comp. D Disable Input Buffer of Port Register .0 */
#define CDPD1_L             (0x0002)  /* Comp. D Disable Input Buffer of Port Register .1 */
#define CDPD2_L             (0x0004)  /* Comp. D Disable Input Buffer of Port Register .2 */
#define CDPD3_L             (0x0008)  /* Comp. D Disable Input Buffer of Port Register .3 */
#define CDPD4_L             (0x0010)  /* Comp. D Disable Input Buffer of Port Register .4 */
#define CDPD5_L             (0x0020)  /* Comp. D Disable Input Buffer of Port Register .5 */
#define CDPD6_L             (0x0040)  /* Comp. D Disable Input Buffer of Port Register .6 */
#define CDPD7_L             (0x0080)  /* Comp. D Disable Input Buffer of Port Register .7 */

#define CDPD8_H             (0x0001)  /* Comp. D Disable Input Buffer of Port Register .8 */
#define CDPD9_H             (0x0002)  /* Comp. D Disable Input Buffer of Port Register .9 */
#define CDPD10_H            (0x0004)  /* Comp. D Disable Input Buffer of Port Register .10 */
#define CDPD11_H            (0x0008)  /* Comp. D Disable Input Buffer of Port Register .11 */
#define CDPD12_H            (0x0010)  /* Comp. D Disable Input Buffer of Port Register .12 */
#define CDPD13_H            (0x0020)  /* Comp. D Disable Input Buffer of Port Register .13 */
#define CDPD14_H            (0x0040)  /* Comp. D Disable Input Buffer of Port Register .14 */
#define CDPD15_H            (0x0080)  /* Comp. D Disable Input Buffer of Port Register .15 */


/* CDINT Control Bits */
#define CDIFG                (0x0001)  /* Comp. D Interrupt Flag */
#define CDIIFG               (0x0002)  /* Comp. D Interrupt Flag Inverted Polarity */
//#define RESERVED             (0x0004)  /* Comp. D */
//#define RESERVED             (0x0008)  /* Comp. D */
//#define RESERVED             (0x0010)  /* Comp. D */
//#define RESERVED             (0x0020)  /* Comp. D */
//#define RESERVED             (0x0040)  /* Comp. D */
//#define RESERVED             (0x0080)  /* Comp. D */
#define CDIE                 (0x0100)  /* Comp. D Interrupt Enable */
#define CDIIE                (0x0200)  /* Comp. D Interrupt Enable Inverted Polarity */
//#define RESERVED             (0x0400)  /* Comp. D */
//#define RESERVED             (0x0800)  /* Comp. D */
//#define RESERVED             (0x1000)  /* Comp. D */
//#define RESERVED             (0x2000)  /* Comp. D */
//#define RESERVED             (0x4000)  /* Comp. D */
//#define RESERVED             (0x8000)  /* Comp. D */

/* CDINT Control Bits */
#define CDIFG_L             (0x0001)  /* Comp. D Interrupt Flag */
#define CDIIFG_L            (0x0002)  /* Comp. D Interrupt Flag Inverted Polarity */
//#define RESERVED             (0x0004)  /* Comp. D */
//#define RESERVED             (0x0008)  /* Comp. D */
//#define RESERVED             (0x0010)  /* Comp. D */
//#define RESERVED             (0x0020)  /* Comp. D */
//#define RESERVED             (0x0040)  /* Comp. D */
//#define RESERVED             (0x0080)  /* Comp. D */
//#define RESERVED             (0x0400)  /* Comp. D */
//#define RESERVED             (0x0800)  /* Comp. D */
//#define RESERVED             (0x1000)  /* Comp. D */
//#define RESERVED             (0x2000)  /* Comp. D */
//#define RESERVED             (0x4000)  /* Comp. D */
//#define RESERVED             (0x8000)  /* Comp. D */

/* CDINT Control Bits */
//#define RESERVED             (0x0004)  /* Comp. D */
//#define RESERVED             (0x0008)  /* Comp. D */
//#define RESERVED             (0x0010)  /* Comp. D */
//#define RESERVED             (0x0020)  /* Comp. D */
//#define RESERVED             (0x0040)  /* Comp. D */
//#define RESERVED             (0x0080)  /* Comp. D */
#define CDIE_H              (0x0001)  /* Comp. D Interrupt Enable */
#define CDIIE_H             (0x0002)  /* Comp. D Interrupt Enable Inverted Polarity */
//#define RESERVED             (0x0400)  /* Comp. D */
//#define RESERVED             (0x0800)  /* Comp. D */
//#define RESERVED             (0x1000)  /* Comp. D */
//#define RESERVED             (0x2000)  /* Comp. D */
//#define RESERVED             (0x4000)  /* Comp. D */
//#define RESERVED             (0x8000)  /* Comp. D */

/* CDIV Definitions */
#define CDIV_NONE           (0x0000)    /* No Interrupt pending */
#define CDIV_CDIFG          (0x0002)    /* CDIFG */
#define CDIV_CDIIFG         (0x0004)    /* CDIIFG */

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
* CLOCK SYSTEM
************************************************************/
#ifdef  __MSP430_HAS_CS__              /* Definition to show that Module is available */

#define OFS_CSCTL0            (0x0000)  /* CS Control Register 0 */
#define OFS_CSCTL0_L           OFS_CSCTL0
#define OFS_CSCTL0_H           OFS_CSCTL0+1
#define OFS_CSCTL1            (0x0002)  /* CS Control Register 1 */
#define OFS_CSCTL1_L           OFS_CSCTL1
#define OFS_CSCTL1_H           OFS_CSCTL1+1
#define OFS_CSCTL2            (0x0004)  /* CS Control Register 2 */
#define OFS_CSCTL2_L           OFS_CSCTL2
#define OFS_CSCTL2_H           OFS_CSCTL2+1
#define OFS_CSCTL3            (0x0006)  /* CS Control Register 3 */
#define OFS_CSCTL3_L           OFS_CSCTL3
#define OFS_CSCTL3_H           OFS_CSCTL3+1
#define OFS_CSCTL4            (0x0008)  /* CS Control Register 4 */
#define OFS_CSCTL4_L           OFS_CSCTL4
#define OFS_CSCTL4_H           OFS_CSCTL4+1
#define OFS_CSCTL5            (0x000A)  /* CS Control Register 5 */
#define OFS_CSCTL5_L           OFS_CSCTL5
#define OFS_CSCTL5_H           OFS_CSCTL5+1
#define OFS_CSCTL6            (0x000C)  /* CS Control Register 6 */
#define OFS_CSCTL6_L           OFS_CSCTL6
#define OFS_CSCTL6_H           OFS_CSCTL6+1

/* CSCTL0 Control Bits */

#define CSKEY                (0xA500)    /* CS Password */
#define CSKEY_H              (0xA5)      /* CS Password for high byte access */

/* CSCTL1 Control Bits */
#define DCOFSEL0            (0x0002)    /* DCO frequency select Bit: 0 */
#define DCOFSEL1            (0x0004)    /* DCO frequency select Bit: 1 */
#define DCORSEL             (0x0080)    /* DCO range select. */

/* CSCTL1 Control Bits */
#define DCOFSEL0_L          (0x0002)    /* DCO frequency select Bit: 0 */
#define DCOFSEL1_L          (0x0004)    /* DCO frequency select Bit: 1 */
#define DCORSEL_L           (0x0080)    /* DCO range select. */


#define DCOFSEL_0           (0x0000)    /* DCO frequency select: 0 */
#define DCOFSEL_1           (0x0002)    /* DCO frequency select: 1 */
#define DCOFSEL_2           (0x0004)    /* DCO frequency select: 2 */
#define DCOFSEL_3           (0x0006)    /* DCO frequency select: 3 */


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
#define SELM__XT1CLK        (0x0000)   /* MCLK Source Select XT1CLK */
#define SELM__VLOCLK        (0x0001)   /* MCLK Source Select VLOCLK */
#define SELM__DCOCLK        (0x0003)   /* MCLK Source Select DCOCLK */
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
#define SELS__DCOCLK        (0x0030)   /* SMCLK Source Select DCOCLK */
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
#define SELA__DCOCLK        (0x0300)   /* ACLK Source Select DCOCLK */
#define SELA__XT2CLK        (0x0500)   /* ACLK Source Select XT2CLK */

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
#define XT1OFF              (0x0001)    /* High Frequency Oscillator 1 (XT1) disable */
#define SMCLKOFF            (0x0002)    /* SMCLK Off */
#define XT1BYPASS           (0x0010)    /* XT1 bypass mode : 0: internal 1:sourced from external pin */
#define XTS                 (0x0020)    /* 1: Selects high-freq. oscillator */
#define XT1DRIVE0           (0x0040)    /* XT1 Drive Level mode Bit 0 */
#define XT1DRIVE1           (0x0080)    /* XT1 Drive Level mode Bit 1 */
#define XT2OFF              (0x0100)    /* High Frequency Oscillator 2 (XT2) disable */
#define XT2BYPASS           (0x1000)    /* XT2 bypass mode : 0: internal 1:sourced from external pin */
#define XT2DRIVE0           (0x4000)    /* XT2 Drive Level mode Bit 0 */
#define XT2DRIVE1           (0x8000)    /* XT2 Drive Level mode Bit 1 */

/* CSCTL4 Control Bits */
#define XT1OFF_L            (0x0001)    /* High Frequency Oscillator 1 (XT1) disable */
#define SMCLKOFF_L          (0x0002)    /* SMCLK Off */
#define XT1BYPASS_L         (0x0010)    /* XT1 bypass mode : 0: internal 1:sourced from external pin */
#define XTS_L               (0x0020)    /* 1: Selects high-freq. oscillator */
#define XT1DRIVE0_L         (0x0040)    /* XT1 Drive Level mode Bit 0 */
#define XT1DRIVE1_L         (0x0080)    /* XT1 Drive Level mode Bit 1 */

/* CSCTL4 Control Bits */
#define XT2OFF_H            (0x0001)    /* High Frequency Oscillator 2 (XT2) disable */
#define XT2BYPASS_H         (0x0010)    /* XT2 bypass mode : 0: internal 1:sourced from external pin */
#define XT2DRIVE0_H         (0x0040)    /* XT2 Drive Level mode Bit 0 */
#define XT2DRIVE1_H         (0x0080)    /* XT2 Drive Level mode Bit 1 */

#define XT1DRIVE_0          (0x0000)    /* XT1 Drive Level mode: 0 */
#define XT1DRIVE_1          (0x0040)    /* XT1 Drive Level mode: 1 */
#define XT1DRIVE_2          (0x0080)    /* XT1 Drive Level mode: 2 */
#define XT1DRIVE_3          (0x00C0)    /* XT1 Drive Level mode: 3 */
#define XT2DRIVE_0          (0x0000)    /* XT2 Drive Level mode: 0 */
#define XT2DRIVE_1          (0x4000)    /* XT2 Drive Level mode: 1 */
#define XT2DRIVE_2          (0x8000)    /* XT2 Drive Level mode: 2 */
#define XT2DRIVE_3          (0xC000)    /* XT2 Drive Level mode: 3 */


/* CSCTL5 Control Bits */
#define XT1OFFG             (0x0001)    /* XT1 Low Frequency Oscillator Fault Flag */
#define XT2OFFG             (0x0002)    /* High Frequency Oscillator 2 Fault Flag */
#define ENSTFCNT1           (0x0040)    /* Enable start counter for XT1 */
#define ENSTFCNT2           (0x0080)    /* Enable start counter for XT2 */

/* CSCTL5 Control Bits */
#define XT1OFFG_L           (0x0001)    /* XT1 Low Frequency Oscillator Fault Flag */
#define XT2OFFG_L           (0x0002)    /* High Frequency Oscillator 2 Fault Flag */
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
/*************************************************************
* FRAM Memory
*************************************************************/
#ifdef  __MSP430_HAS_FRAM_FR5XX__     /* Definition to show that Module is available */

#define OFS_FRCTL0            (0x0000)  /* FRAM Controller Control 0 */
#define OFS_FRCTL0_L           OFS_FRCTL0
#define OFS_FRCTL0_H           OFS_FRCTL0+1
#define OFS_GCCTL0            (0x0004)  /* General Control 0 */
#define OFS_GCCTL0_L           OFS_GCCTL0
#define OFS_GCCTL0_H           OFS_GCCTL0+1
#define OFS_GCCTL1            (0x0006)  /* General Control 1 */
#define OFS_GCCTL1_L           OFS_GCCTL1
#define OFS_GCCTL1_H           OFS_GCCTL1+1

#define FRPW                (0x9600)  /* FRAM password returned by read */
#define FWPW                (0xA500)  /* FRAM password for write */
#define FXPW                (0x3300)  /* for use with XOR instruction */

/* FRCTL0 Control Bits */
#define NPRECHG0            (0x0001)  /* FRAM Wait state Generator Precharge Time control Bit: 0 */
#define NPRECHG1            (0x0002)  /* FRAM Wait state Generator Precharge Time control Bit: 1 */
#define NPRECHG2            (0x0004)  /* FRAM Wait state Generator Precharge Time control Bit: 2 */
#define NAUTO               (0x0008)  /* FRAM Disables the wait state generator */
#define NACCESS0            (0x0010)  /* FRAM Wait state Generator Access Time control Bit: 0 */
#define NACCESS1            (0x0020)  /* FRAM Wait state Generator Access Time control Bit: 1 */
#define NACCESS2            (0x0040)  /* FRAM Wait state Generator Access Time control Bit: 2 */
//#define RESERVED            (0x0080)  /* RESERVED */

/* FRCTL0 Control Bits */
#define NPRECHG0_L          (0x0001)  /* FRAM Wait state Generator Precharge Time control Bit: 0 */
#define NPRECHG1_L          (0x0002)  /* FRAM Wait state Generator Precharge Time control Bit: 1 */
#define NPRECHG2_L          (0x0004)  /* FRAM Wait state Generator Precharge Time control Bit: 2 */
#define NAUTO_L             (0x0008)  /* FRAM Disables the wait state generator */
#define NACCESS0_L          (0x0010)  /* FRAM Wait state Generator Access Time control Bit: 0 */
#define NACCESS1_L          (0x0020)  /* FRAM Wait state Generator Access Time control Bit: 1 */
#define NACCESS2_L          (0x0040)  /* FRAM Wait state Generator Access Time control Bit: 2 */
//#define RESERVED            (0x0080)  /* RESERVED */


#define NPRECHG_0           (0x0000)  /* FRAM Wait state Generator Precharge Time control: 0 */
#define NPRECHG_1           (0x0001)  /* FRAM Wait state Generator Precharge Time control: 1 */
#define NPRECHG_2           (0x0002)  /* FRAM Wait state Generator Precharge Time control: 2 */
#define NPRECHG_3           (0x0003)  /* FRAM Wait state Generator Precharge Time control: 3 */
#define NPRECHG_4           (0x0004)  /* FRAM Wait state Generator Precharge Time control: 4 */
#define NPRECHG_5           (0x0005)  /* FRAM Wait state Generator Precharge Time control: 5 */
#define NPRECHG_6           (0x0006)  /* FRAM Wait state Generator Precharge Time control: 6 */
#define NPRECHG_7           (0x0007)  /* FRAM Wait state Generator Precharge Time control: 7 */

#define NACCESS_0           (0x0000)  /* FRAM Wait state Generator Access Time control: 0 */
#define NACCESS_1           (0x0010)  /* FRAM Wait state Generator Access Time control: 1 */
#define NACCESS_2           (0x0020)  /* FRAM Wait state Generator Access Time control: 2 */
#define NACCESS_3           (0x0030)  /* FRAM Wait state Generator Access Time control: 3 */
#define NACCESS_4           (0x0040)  /* FRAM Wait state Generator Access Time control: 4 */
#define NACCESS_5           (0x0050)  /* FRAM Wait state Generator Access Time control: 5 */
#define NACCESS_6           (0x0060)  /* FRAM Wait state Generator Access Time control: 6 */
#define NACCESS_7           (0x0070)  /* FRAM Wait state Generator Access Time control: 7 */


/* GCCTL0 Control Bits */
#define BUSY                (0x0001)  /* FRAM is currently busy programming */
//#define RESERVED            (0x0002)  /* RESERVED */
//#define RESERVED            (0x0004)  /* RESERVED */
#define ACCTEIE             (0x0008)  /* Enable NMI event if Access time error occurs */
#define ACCVIE              (0x0010)  /* Enable NMI event if Access Violation occurs */
#define CBDIE               (0x0020)  /* Enable NMI event if correctable bit error detected */
#define UBDIE               (0x0040)  /* Enable NMI event if uncorrectable bit error detected */
#define UBDRSTEN            (0x0080)  /* Enable Power Up Clear on uncorrectable bit error */

/* GCCTL0 Control Bits */
#define BUSY_L              (0x0001)  /* FRAM is currently busy programming */
//#define RESERVED            (0x0002)  /* RESERVED */
//#define RESERVED            (0x0004)  /* RESERVED */
#define ACCTEIE_L           (0x0008)  /* Enable NMI event if Access time error occurs */
#define ACCVIE_L            (0x0010)  /* Enable NMI event if Access Violation occurs */
#define CBDIE_L             (0x0020)  /* Enable NMI event if correctable bit error detected */
#define UBDIE_L             (0x0040)  /* Enable NMI event if uncorrectable bit error detected */
#define UBDRSTEN_L          (0x0080)  /* Enable Power Up Clear on uncorrectable bit error */


/* GCCTL1 Control Bits */
#define ACCVIFG             (0x0001)  /* Access Violation Interrupt Flag */
#define CBDIFG              (0x0002)  /* FRAM correctable bit error flag */
#define UBDIFG              (0x0004)  /* FRAM uncorrectable bit error flag */
#define ACCTEIFG            (0x0008)  /* Access time error flag */

/* GCCTL1 Control Bits */
#define ACCVIFG_L           (0x0001)  /* Access Violation Interrupt Flag */
#define CBDIFG_L            (0x0002)  /* FRAM correctable bit error flag */
#define UBDIFG_L            (0x0004)  /* FRAM uncorrectable bit error flag */
#define ACCTEIFG_L          (0x0008)  /* Access time error flag */


/* Legacy Definitions */
#define SBDIEN              (0x0020)  /* Enable NMI event if single bit error detected */
#define DBDIEN              (0x0040)  /* Enable NMI event if double bit error detected */
#define DBDRSTEN            (0x0080)  /* Enable Power Up Clear on double bit error */
#define SBDIFG              (0x0002)  /* FRAM single bit error flag */
#define DBDIFG              (0x0004)  /* FRAM double bit error flag */

#endif
/************************************************************
* Memory Protection Unit
************************************************************/
#ifdef  __MSP430_HAS_MPU__             /* Definition to show that Module is available */

#define OFS_MPUCTL0           (0x0000)  /* MPU Control Register 0 */
#define OFS_MPUCTL0_L          OFS_MPUCTL0
#define OFS_MPUCTL0_H          OFS_MPUCTL0+1
#define OFS_MPUCTL1           (0x0002)  /* MPU Control Register 1 */
#define OFS_MPUCTL1_L          OFS_MPUCTL1
#define OFS_MPUCTL1_H          OFS_MPUCTL1+1
#define OFS_MPUSEG            (0x0004)  /* MPU Segmentation Register */
#define OFS_MPUSEG_L           OFS_MPUSEG
#define OFS_MPUSEG_H           OFS_MPUSEG+1
#define OFS_MPUSAM            (0x0006)  /* MPU Access Management Register */
#define OFS_MPUSAM_L           OFS_MPUSAM
#define OFS_MPUSAM_H           OFS_MPUSAM+1

/* MPUCTL0 Control Bits */
#define MPUENA               (0x0001)  /* MPU Enable */

/* MPUCTL0 Control Bits */
#define MPUENA_L            (0x0001)  /* MPU Enable */


#define MPUPW                (0xA500)  /* MPU Access Password */
#define MPUPW_H              (0xA5)    /* MPU Access Password */

/* MPUCTL1 Control Bits */
#define MPUSEG1IFG           (0x0001)  /* MPU Main Memory Segment 1 violation interupt flag */
#define MPUSEG2IFG           (0x0002)  /* MPU Main Memory Segment 2 violation interupt flag */
#define MPUSEG3IFG           (0x0004)  /* MPU Main Memory Segment 3 violation interupt flag */
#define MPUSEGIIFG           (0x0008)  /* MPU Info Memory Segment violation interupt flag */

/* MPUCTL1 Control Bits */
#define MPUSEG1IFG_L        (0x0001)  /* MPU Main Memory Segment 1 violation interupt flag */
#define MPUSEG2IFG_L        (0x0002)  /* MPU Main Memory Segment 2 violation interupt flag */
#define MPUSEG3IFG_L        (0x0004)  /* MPU Main Memory Segment 3 violation interupt flag */
#define MPUSEGIIFG_L        (0x0008)  /* MPU Info Memory Segment violation interupt flag */


/* MPUSEG Control Bits */
#define MPUSB10              (0x0001)  /* MPU Segment Border 1 Bit: 0 */
#define MPUSB11              (0x0002)  /* MPU Segment Border 1 Bit: 1 */
#define MPUSB12              (0x0004)  /* MPU Segment Border 1 Bit: 2 */
#define MPUSB13              (0x0008)  /* MPU Segment Border 1 Bit: 3 */
#define MPUSB14              (0x0010)  /* MPU Segment Border 1 Bit: 4 */
#define MPUSB20              (0x0100)  /* MPU Segment Border 2 Bit: 0 */
#define MPUSB21              (0x0200)  /* MPU Segment Border 2 Bit: 1 */
#define MPUSB22              (0x0400)  /* MPU Segment Border 2 Bit: 2 */
#define MPUSB23              (0x0800)  /* MPU Segment Border 2 Bit: 3 */
#define MPUSB24              (0x1000)  /* MPU Segment Border 2 Bit: 4 */

/* MPUSEG Control Bits */
#define MPUSB10_L           (0x0001)  /* MPU Segment Border 1 Bit: 0 */
#define MPUSB11_L           (0x0002)  /* MPU Segment Border 1 Bit: 1 */
#define MPUSB12_L           (0x0004)  /* MPU Segment Border 1 Bit: 2 */
#define MPUSB13_L           (0x0008)  /* MPU Segment Border 1 Bit: 3 */
#define MPUSB14_L           (0x0010)  /* MPU Segment Border 1 Bit: 4 */

/* MPUSEG Control Bits */
#define MPUSB20_H           (0x0001)  /* MPU Segment Border 2 Bit: 0 */
#define MPUSB21_H           (0x0002)  /* MPU Segment Border 2 Bit: 1 */
#define MPUSB22_H           (0x0004)  /* MPU Segment Border 2 Bit: 2 */
#define MPUSB23_H           (0x0008)  /* MPU Segment Border 2 Bit: 3 */
#define MPUSB24_H           (0x0010)  /* MPU Segment Border 2 Bit: 4 */

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
* PMM - Power Management System
************************************************************/
#ifdef  __MSP430_HAS_PMM_FR5xx__      /* Definition to show that Module is available */

#define OFS_PMMCTL0           (0x0000)  /* PMM Control 0 */
#define OFS_PMMCTL0_L          OFS_PMMCTL0
#define OFS_PMMCTL0_H          OFS_PMMCTL0+1
#define OFS_PMMIFG            (0x000A)  /* PMM Interrupt Flag */
#define OFS_PMMIFG_L           OFS_PMMIFG
#define OFS_PMMIFG_H           OFS_PMMIFG+1
#define OFS_PM5CTL0           (0x0010)  /* PMM Power Mode 5 Control Register 0 */
#define OFS_PM5CTL0_L          OFS_PM5CTL0
#define OFS_PM5CTL0_H          OFS_PM5CTL0+1

#define PMMPW               (0xA500)  /* PMM Register Write Password */
#define PMMPW_H             (0xA5)    /* PMM Register Write Password for high word access */

/* PMMCTL0 Control Bits */
#define PMMSWBOR            (0x0004)  /* PMM Software BOR */
#define PMMSWPOR            (0x0008)  /* PMM Software POR */
#define PMMREGOFF           (0x0010)  /* PMM Turn Regulator off */
#define SVSLE               (0x0020)  /* SVS low side enable */
#define SVSHE               (0x0040)  /* SVS high side enable */

/* PMMCTL0 Control Bits */
#define PMMSWBOR_L          (0x0004)  /* PMM Software BOR */
#define PMMSWPOR_L          (0x0008)  /* PMM Software POR */
#define PMMREGOFF_L         (0x0010)  /* PMM Turn Regulator off */
#define SVSLE_L             (0x0020)  /* SVS low side enable */
#define SVSHE_L             (0x0040)  /* SVS high side enable */


/* PMMIFG Control Bits */
#define PMMBORIFG           (0x0100)  /* PMM Software BOR interrupt flag */
#define PMMRSTIFG           (0x0200)  /* PMM RESET pin interrupt flag */
#define PMMPORIFG           (0x0400)  /* PMM Software POR interrupt flag */
#define SVSLIFG             (0x1000)  /* SVS high side interrupt flag */
#define SVSHIFG             (0x2000)  /* SVS low side interrupt flag */
#define PMMLPM5IFG          (0x8000)  /* LPM5 indication Flag */

/* PMMIFG Control Bits */
#define PMMBORIFG_H         (0x0001)  /* PMM Software BOR interrupt flag */
#define PMMRSTIFG_H         (0x0002)  /* PMM RESET pin interrupt flag */
#define PMMPORIFG_H         (0x0004)  /* PMM Software POR interrupt flag */
#define SVSLIFG_H           (0x0010)  /* SVS high side interrupt flag */
#define SVSHIFG_H           (0x0020)  /* SVS low side interrupt flag */
#define PMMLPM5IFG_H        (0x0080)  /* LPM5 indication Flag */


/* PM5CTL0 Power Mode 5 Control Bits */
#define LOCKLPM5            (0x0001)  /* Lock I/O pin configuration upon entry/exit to/from LPM5 */

/* PM5CTL0 Power Mode 5 Control Bits */
#define LOCKLPM5_L          (0x0001)  /* Lock I/O pin configuration upon entry/exit to/from LPM5 */


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
#define OFS_PASEL             (0x000A)  /* Port A Selection */
#define OFS_PASEL_L            OFS_PASEL
#define OFS_PASEL_H            OFS_PASEL+1
#define OFS_PASEL0            (0x000A)  /* Port A Selection 0 */
#define OFS_PASEL0_L           OFS_PASEL0
#define OFS_PASEL0_H           OFS_PASEL0+1
#define OFS_PASEL1            (0x000C)  /* Port A Selection 1 */
#define OFS_PASEL1_L           OFS_PASEL1
#define OFS_PASEL1_H           OFS_PASEL1+1
#define OFS_PASELC            (0x0016)  /* Port A Complement Selection */
#define OFS_PASELC_L           OFS_PASELC
#define OFS_PASELC_H           OFS_PASELC+1
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
#define OFS_P1SEL             (0x000A)
#define OFS_P1SEL0            (0x000A)
#define OFS_P1SEL1            (0x000C)
#define OFS_P1SELC            (0x0016)
#define OFS_P1IV              (0x000E)  /* Port 1 Interrupt Vector Word */
#define OFS_P1IES             (0x0018)
#define OFS_P1IE              (0x001A)
#define OFS_P1IFG             (0x001C)
#define OFS_P2IN              (0x0001)
#define OFS_P2OUT             (0x0003)
#define OFS_P2DIR             (0x0005)
#define OFS_P2REN             (0x0007)
#define OFS_P2SEL             (0x000B)
#define OFS_P2SEL0            (0x000B)
#define OFS_P2SEL1            (0x000D)
#define OFS_P2SELC            (0x0017)
#define OFS_P2IV              (0x001E)  /* Port 2 Interrupt Vector Word */
#define OFS_P2IES             (0x0019)
#define OFS_P2IE              (0x001B)
#define OFS_P2IFG             (0x001d)
#define P1IN                (PAIN_L)  /* Port 1 Input */
#define P1OUT               (PAOUT_L) /* Port 1 Output */
#define P1DIR               (PADIR_L) /* Port 1 Direction */
#define P1REN               (PAREN_L) /* Port 1 Resistor Enable */
#define P1SEL               (PASEL_L) /* Port 1 Selection */
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
#define P2SEL               (PASEL_H) /* Port 2 Selection */
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
#define OFS_PBSEL             (0x000A)  /* Port B Selection */
#define OFS_PBSEL_L            OFS_PBSEL
#define OFS_PBSEL_H            OFS_PBSEL+1
#define OFS_PBSEL0            (0x000A)  /* Port B Selection 0 */
#define OFS_PBSEL0_L           OFS_PBSEL0
#define OFS_PBSEL0_H           OFS_PBSEL0+1
#define OFS_PBSEL1            (0x000C)  /* Port B Selection 1 */
#define OFS_PBSEL1_L           OFS_PBSEL1
#define OFS_PBSEL1_H           OFS_PBSEL1+1
#define OFS_PBSELC            (0x0016)  /* Port B Complement Selection */
#define OFS_PBSELC_L           OFS_PBSELC
#define OFS_PBSELC_H           OFS_PBSELC+1
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
#define OFS_P3SEL             (0x000A)
#define OFS_P3SEL0            (0x000A)
#define OFS_P3SEL1            (0x000C)
#define OFS_P3SELC            (0x0016)
#define OFS_P3IV              (0x000E)  /* Port 3 Interrupt Vector Word */
#define OFS_P3IES             (0x0018)
#define OFS_P3IE              (0x001A)
#define OFS_P3IFG             (0x001C)
#define OFS_P4IN              (0x0001)
#define OFS_P4OUT             (0x0003)
#define OFS_P4DIR             (0x0005)
#define OFS_P4REN             (0x0007)
#define OFS_P4SEL             (0x000B)
#define OFS_P4SEL0            (0x000B)
#define OFS_P4SEL1            (0x000D)
#define OFS_P4SELC            (0x0017)
#define OFS_P4IV              (0x001E)  /* Port 4 Interrupt Vector Word */
#define OFS_P4IES             (0x0019)
#define OFS_P4IE              (0x001B)
#define OFS_P4IFG             (0x001d)
#define P3IN                (PBIN_L)  /* Port 3 Input */
#define P3OUT               (PBOUT_L) /* Port 3 Output */
#define P3DIR               (PBDIR_L) /* Port 3 Direction */
#define P3REN               (PBREN_L) /* Port 3 Resistor Enable */
#define P3SEL               (PBSEL_L) /* Port 3 Selection */
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
#define P4SEL               (PBSEL_H) /* Port 4 Selection */
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
#define OFS_PCSEL             (0x000A)  /* Port C Selection */
#define OFS_PCSEL_L            OFS_PCSEL
#define OFS_PCSEL_H            OFS_PCSEL+1
#define OFS_PCSEL0            (0x000A)  /* Port C Selection 0 */
#define OFS_PCSEL0_L           OFS_PCSEL0
#define OFS_PCSEL0_H           OFS_PCSEL0+1
#define OFS_PCSEL1            (0x000C)  /* Port C Selection 1 */
#define OFS_PCSEL1_L           OFS_PCSEL1
#define OFS_PCSEL1_H           OFS_PCSEL1+1
#define OFS_PCSELC            (0x0016)  /* Port C Complement Selection */
#define OFS_PCSELC_L           OFS_PCSELC
#define OFS_PCSELC_H           OFS_PCSELC+1
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
#define OFS_P5SEL             (0x000A)
#define OFS_P5SEL0            (0x000A)
#define OFS_P5SEL1            (0x000C)
#define OFS_P5SELC            (0x0016)
#define OFS_P5IV              (0x000E)  /* Port 5 Interrupt Vector Word */
#define OFS_P5IES             (0x0018)
#define OFS_P5IE              (0x001A)
#define OFS_P5IFG             (0x001C)
#define OFS_P6IN              (0x0001)
#define OFS_P6OUT             (0x0003)
#define OFS_P6DIR             (0x0005)
#define OFS_P6REN             (0x0007)
#define OFS_P6SEL             (0x000B)
#define OFS_P6SEL0            (0x000B)
#define OFS_P6SEL1            (0x000D)
#define OFS_P6SELC            (0x0017)
#define OFS_P6IV              (0x001E)  /* Port 6 Interrupt Vector Word */
#define OFS_P6IES             (0x0019)
#define OFS_P6IE              (0x001B)
#define OFS_P6IFG             (0x001d)
#define P5IN                (PCIN_L)  /* Port 5 Input */
#define P5OUT               (PCOUT_L) /* Port 5 Output */
#define P5DIR               (PCDIR_L) /* Port 5 Direction */
#define P5REN               (PCREN_L) /* Port 5 Resistor Enable */
#define P5SEL               (PCSEL_L) /* Port 5 Selection */
#define P5SEL0              (PCSEL0_L) /* Port 5 Selection 0 */
#define P5SEL1              (PCSEL1_L) /* Port 5 Selection 1 */
#define P5SELC              (PCSELC_L) /* Port 5 Complement Selection */
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
#define P6SEL               (PCSEL_H) /* Port 6 Selection */
#define P6SEL0              (PCSEL0_H) /* Port 6 Selection 0 */
#define P6SEL1              (PCSEL1_H) /* Port 6 Selection 1 */
#define P6SELC              (PCSELC_H) /* Port 6 Complement Selection */
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
#define OFS_PDSEL             (0x000A)  /* Port D Selection */
#define OFS_PDSEL_L            OFS_PDSEL
#define OFS_PDSEL_H            OFS_PDSEL+1
#define OFS_PDSEL0            (0x000A)  /* Port D Selection 0 */
#define OFS_PDSEL0_L           OFS_PDSEL0
#define OFS_PDSEL0_H           OFS_PDSEL0+1
#define OFS_PDSEL1            (0x000C)  /* Port D Selection 1 */
#define OFS_PDSEL1_L           OFS_PDSEL1
#define OFS_PDSEL1_H           OFS_PDSEL1+1
#define OFS_PDSELC            (0x0016)  /* Port D Complement Selection */
#define OFS_PDSELC_L           OFS_PDSELC
#define OFS_PDSELC_H           OFS_PDSELC+1
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
#define OFS_P7SEL             (0x000A)
#define OFS_P7SEL0            (0x000A)
#define OFS_P7SEL1            (0x000C)
#define OFS_P7SELC            (0x0016)
#define OFS_P7IV              (0x000E)  /* Port 7 Interrupt Vector Word */
#define OFS_P7IES             (0x0018)
#define OFS_P7IE              (0x001A)
#define OFS_P7IFG             (0x001C)
#define OFS_P8IN              (0x0001)
#define OFS_P8OUT             (0x0003)
#define OFS_P8DIR             (0x0005)
#define OFS_P8REN             (0x0007)
#define OFS_P8SEL             (0x000B)
#define OFS_P8SEL0            (0x000B)
#define OFS_P8SEL1            (0x000D)
#define OFS_P8SELC            (0x0017)
#define OFS_P8IV              (0x001E)  /* Port 8 Interrupt Vector Word */
#define OFS_P8IES             (0x0019)
#define OFS_P8IE              (0x001B)
#define OFS_P8IFG             (0x001d)
#define P7IN                (PDIN_L)  /* Port 7 Input */
#define P7OUT               (PDOUT_L) /* Port 7 Output */
#define P7DIR               (PDDIR_L) /* Port 7 Direction */
#define P7REN               (PDREN_L) /* Port 7 Resistor Enable */
#define P7SEL               (PDSEL_L) /* Port 7 Selection */
#define P7SEL0              (PDSEL0_L) /* Port 7 Selection 0 */
#define P7SEL1              (PDSEL1_L) /* Port 7 Selection 1 */
#define P7SELC              (PDSELC_L) /* Port 7 Complement Selection */
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
#define P8SEL               (PDSEL_H) /* Port 8 Selection */
#define P8SEL0              (PDSEL0_H) /* Port 8 Selection 0 */
#define P8SEL1              (PDSEL1_H) /* Port 8 Selection 1 */
#define P8SELC              (PDSELC_H) /* Port 8 Complement Selection */
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
#define OFS_PESEL             (0x000A)  /* Port E Selection */
#define OFS_PESEL_L            OFS_PESEL
#define OFS_PESEL_H            OFS_PESEL+1
#define OFS_PESEL0            (0x000A)  /* Port E Selection 0 */
#define OFS_PESEL0_L           OFS_PESEL0
#define OFS_PESEL0_H           OFS_PESEL0+1
#define OFS_PESEL1            (0x000C)  /* Port E Selection 1 */
#define OFS_PESEL1_L           OFS_PESEL1
#define OFS_PESEL1_H           OFS_PESEL1+1
#define OFS_PESELC            (0x0016)  /* Port E Complement Selection */
#define OFS_PESELC_L           OFS_PESELC
#define OFS_PESELC_H           OFS_PESELC+1
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
#define OFS_P9SEL             (0x000A)
#define OFS_P9SEL0            (0x000A)
#define OFS_P9SEL1            (0x000C)
#define OFS_P9SELC            (0x0016)
#define OFS_P9IV              (0x000E)  /* Port 9 Interrupt Vector Word */
#define OFS_P9IES             (0x0018)
#define OFS_P9IE              (0x001A)
#define OFS_P9IFG             (0x001C)
#define OFS_P10IN             (0x0001)
#define OFS_P10OUT            (0x0003)
#define OFS_P10DIR            (0x0005)
#define OFS_P10REN            (0x0007)
#define OFS_P10SEL            (0x000B)
#define OFS_P10SEL0           (0x000B)
#define OFS_P10SEL1           (0x000D)
#define OFS_P10SELC           (0x0017)
#define OFS_P10IV             (0x001E)  /* Port 10 Interrupt Vector Word */
#define OFS_P10IES            (0x0019)
#define OFS_P10IE             (0x001B)
#define OFS_P10IFG            (0x001d)
#define P9IN                (PEIN_L)  /* Port 9 Input */
#define P9OUT               (PEOUT_L) /* Port 9 Output */
#define P9DIR               (PEDIR_L) /* Port 9 Direction */
#define P9REN               (PEREN_L) /* Port 9 Resistor Enable */
#define P9SEL               (PESEL_L) /* Port 9 Selection */
#define P9SEL0              (PESEL0_L) /* Port 9 Selection 0 */
#define P9SEL1              (PESEL1_L) /* Port 9 Selection 1 */
#define P9SELC              (PESELC_L) /* Port 9 Complement Selection */
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
#define P10SEL               (PESEL_H) /* Port 10 Selection */
#define P10SEL0              (PESEL0_H) /* Port 10 Selection 0 */
#define P10SEL1              (PESEL1_H) /* Port 10 Selection 1 */
#define P10SELC              (PESELC_H) /* Port 10 Complement Selection */
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
#define OFS_PFSEL             (0x000A)  /* Port F Selection */
#define OFS_PFSEL_L            OFS_PFSEL
#define OFS_PFSEL_H            OFS_PFSEL+1
#define OFS_PFSEL0            (0x000A)  /* Port F Selection 0 */
#define OFS_PFSEL0_L           OFS_PFSEL0
#define OFS_PFSEL0_H           OFS_PFSEL0+1
#define OFS_PFSEL1            (0x000C)  /* Port F Selection 1 */
#define OFS_PFSEL1_L           OFS_PFSEL1
#define OFS_PFSEL1_H           OFS_PFSEL1+1
#define OFS_PFSELC            (0x0016)  /* Port F Complement Selection */
#define OFS_PFSELC_L           OFS_PFSELC
#define OFS_PFSELC_H           OFS_PFSELC+1
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
#define OFS_P11SEL            (0x000A)
#define OFS_P11SEL0           (0x000A)
#define OFS_P11SEL1           (0x000C)
#define OFS_P11SELC           (0x0016)
#define OFS_P11IV             (0x000E)  /* Port 11 Interrupt Vector Word */
#define OFS_P11IES            (0x0018)
#define OFS_P11IE             (0x001A)
#define OFS_P11IFG            (0x001C)
#define P11IN                (PFIN_L)  /* Port 11 Input */
#define P11OUT               (PFOUT_L) /* Port 11 Output */
#define P11DIR               (PFDIR_L) /* Port 11 Direction */
#define P11REN               (PFREN_L) /* Port 11 Resistor Enable */
#define P11SEL               (PFSEL_L) /* Port 11 Selection */
#define P11SEL0              (PFSEL0_L) /* Port 11 Selection0 */
#define P11SEL1              (PFSEL1_L) /* Port 11 Selection1 */
#define OFS_P11SELC           (0x0017)

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
#define OFS_PJSEL0            (0x000A)  /* Port J Selection 0 */
#define OFS_PJSEL0_L           OFS_PJSEL0
#define OFS_PJSEL0_H           OFS_PJSEL0+1
#define OFS_PJSEL1            (0x000C)  /* Port J Selection 1 */
#define OFS_PJSEL1_L           OFS_PJSEL1
#define OFS_PJSEL1_H           OFS_PJSEL1+1
#define OFS_PJSELC            (0x0016)  /* Port J Complement Selection */
#define OFS_PJSELC_L           OFS_PJSELC
#define OFS_PJSELC_H           OFS_PJSELC+1













#endif
/************************************************************
* PMM - Power Management System
************************************************************/
#ifdef  __MSP430_HAS_PMM_FR5xx__      /* Definition to show that Module is available */

#define OFS_PMMCTL0           (0x0000)  /* PMM Control 0 */
#define OFS_PMMCTL0_L          OFS_PMMCTL0
#define OFS_PMMCTL0_H          OFS_PMMCTL0+1
#define OFS_PMMIFG            (0x000A)  /* PMM Interrupt Flag */
#define OFS_PMMIFG_L           OFS_PMMIFG
#define OFS_PMMIFG_H           OFS_PMMIFG+1
#define OFS_PM5CTL0           (0x0010)  /* PMM Power Mode 5 Control Register 0 */
#define OFS_PM5CTL0_L          OFS_PM5CTL0
#define OFS_PM5CTL0_H          OFS_PM5CTL0+1

#define PMMPW               (0xA500)  /* PMM Register Write Password */
#define PMMPW_H             (0xA5)    /* PMM Register Write Password for high word access */

/* PMMCTL0 Control Bits */
#define PMMSWBOR            (0x0004)  /* PMM Software BOR */
#define PMMSWPOR            (0x0008)  /* PMM Software POR */
#define PMMREGOFF           (0x0010)  /* PMM Turn Regulator off */
#define SVSLE               (0x0020)  /* SVS low side enable */
#define SVSHE               (0x0040)  /* SVS high side enable */

/* PMMCTL0 Control Bits */
#define PMMSWBOR_L          (0x0004)  /* PMM Software BOR */
#define PMMSWPOR_L          (0x0008)  /* PMM Software POR */
#define PMMREGOFF_L         (0x0010)  /* PMM Turn Regulator off */
#define SVSLE_L             (0x0020)  /* SVS low side enable */
#define SVSHE_L             (0x0040)  /* SVS high side enable */


/* PMMIFG Control Bits */
#define PMMBORIFG           (0x0100)  /* PMM Software BOR interrupt flag */
#define PMMRSTIFG           (0x0200)  /* PMM RESET pin interrupt flag */
#define PMMPORIFG           (0x0400)  /* PMM Software POR interrupt flag */
#define SVSLIFG             (0x1000)  /* SVS high side interrupt flag */
#define SVSHIFG             (0x2000)  /* SVS low side interrupt flag */
#define PMMLPM5IFG          (0x8000)  /* LPM5 indication Flag */

/* PMMIFG Control Bits */
#define PMMBORIFG_H         (0x0001)  /* PMM Software BOR interrupt flag */
#define PMMRSTIFG_H         (0x0002)  /* PMM RESET pin interrupt flag */
#define PMMPORIFG_H         (0x0004)  /* PMM Software POR interrupt flag */
#define SVSLIFG_H           (0x0010)  /* SVS high side interrupt flag */
#define SVSHIFG_H           (0x0020)  /* SVS low side interrupt flag */
#define PMMLPM5IFG_H        (0x0080)  /* LPM5 indication Flag */


/* PM5CTL0 Power Mode 5 Control Bits */
#define LOCKLPM5            (0x0001)  /* Lock I/O pin configuration upon entry/exit to/from LPM5 */

/* PM5CTL0 Power Mode 5 Control Bits */
#define LOCKLPM5_L          (0x0001)  /* Lock I/O pin configuration upon entry/exit to/from LPM5 */


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
#define JMBINIE             (0x0040)  /* JTAG Mail Box input Interrupt Enable */
#define JMBOUTIE            (0x0080)  /* JTAG Mail Box output Interrupt Enable */

#define WDTIE_L             (0x0001)  /* WDT Interrupt Enable */
#define OFIE_L              (0x0002)  /* Osc Fault Enable */
//#define Reserved          (0x0004)
#define VMAIE_L             (0x0008)  /* Vacant Memory Interrupt Enable */
#define NMIIE_L             (0x0010)  /* NMI Interrupt Enable */
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

#endif /* #ifndef __msp430FR57XXGENERIC */

