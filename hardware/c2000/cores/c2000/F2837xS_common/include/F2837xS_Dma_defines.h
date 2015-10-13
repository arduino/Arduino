//###########################################################################
//
// FILE:   F2837xS_Dma_defines.h
//
// TITLE:  #defines used in DMA examples
//
//###########################################################################
// $TI Release: F2837xS Support Library v170 $
// $Release Date: Mon Sep 21 16:56:07 CDT 2015 $
// $Copyright: Copyright (C) 2014-2015 Texas Instruments Incorporated -
//             http://www.ti.com/ ALL RIGHTS RESERVED $
//###########################################################################

#ifndef F2837xS_DMA_DEFINES_H
#define F2837xS_DMA_DEFINES_H


#ifdef __cplusplus
extern "C" {
#endif

// MODE
//==========================
// PERINTSEL bits
#define DMA_ADCAINT1    1
#define DMA_ADCAINT2    2
#define DMA_ADCAINT3    3
#define DMA_ADCAINT4    4
#define DMA_ADCAEVT     5
#define DMA_ADCBINT1    6
#define DMA_ADCBINT2    7
#define DMA_ADCBINT3    8
#define DMA_ADCBINT4    9
#define DMA_ADCBEVT     10
#define DMA_ADCCINT1    11
#define DMA_ADCCINT2    12
#define DMA_ADCCINT3    13
#define DMA_ADCCINT4    14
#define DMA_ADCCEVT     15
#define DMA_ADCDINT1    16
#define DMA_ADCDINT2    17
#define DMA_ADCDINT3    18
#define DMA_ADCDINT4    19
#define DMA_ADCDEVT     20

#define DMA_XINT1   	29
#define DMA_XINT2   	30
#define DMA_XINT3   	31
#define DMA_XINT4   	32
#define DMA_XINT5   	33

#define DMA_EPWM1A  	36
#define DMA_EPWM1B  	37
#define DMA_EPWM2A  	38
#define DMA_EPWM2B  	39
#define DMA_EPWM3A  	40
#define DMA_EPWM3B  	41
#define DMA_EPWM4A  	42
#define DMA_EPWM4B  	43
#define DMA_EPWM5A  	44
#define DMA_EPWM5B  	45
#define DMA_EPWM6A  	46
#define DMA_EPWM6B  	47
#define DMA_EPWM7A  	48
#define DMA_EPWM7B  	49
#define DMA_EPWM8A  	50
#define DMA_EPWM8B  	51
#define DMA_EPWM9A  	52
#define DMA_EPWM9B  	53
#define DMA_EPWM10A  	54
#define DMA_EPWM10B  	55
#define DMA_EPWM11A  	56
#define DMA_EPWM11B  	57
#define DMA_EPWM12A  	58
#define DMA_EPWM12B  	59
#define DMA_EPWM13A  	60
#define DMA_EPWM13B  	61
#define DMA_EPWM14A  	62
#define DMA_EPWM14B  	63
#define DMA_EPWM15A  	64
#define DMA_EPWM15B  	65
#define DMA_EPWM16A  	66
#define DMA_EPWM16B  	67

#define DMA_TINT0   	68
#define DMA_TINT1   	69
#define DMA_TINT2   	70

#define DMA_MXEVTA  	71
#define DMA_MREVTA  	72
#define DMA_MXEVTB  	73
#define DMA_MREVTB  	74

#define DMA_SD1FLT1     95
#define DMA_SD1FLT2     96
#define DMA_SD1FLT3     97
#define DMA_SD1FLT4     98

#define DMA_SD2FLT1     99
#define DMA_SD2FLT2     100
#define DMA_SD2FLT3     101
#define DMA_SD2FLT4     102

#define DMA_SPIATX		109
#define DMA_SPIARX		110
#define DMA_SPIBTX		111
#define DMA_SPIBRX 		112
#define DMA_SPICTX   	113
#define DMA_SPICRX   	114

#define DMA_USBRX1  	131
#define DMA_USBTX1 	 	132
#define DMA_USBRX2 	 	133
#define DMA_USBTX2  	134
#define DMA_USBRX3  	135
#define DMA_USBTX3  	136


// OVERINTE bit
#define OVRFLOW_DISABLE 0x0
#define OVEFLOW_ENABLE  0x1
// PERINTE bit
#define PERINT_DISABLE  0x0
#define PERINT_ENABLE   0x1
// CHINTMODE bits
#define CHINT_BEGIN     0x0
#define CHINT_END       0x1
// ONESHOT bits
#define ONESHOT_DISABLE 0x0
#define ONESHOT_ENABLE  0x1
// CONTINOUS bit
#define CONT_DISABLE    0x0
#define CONT_ENABLE     0x1
// SYNCE bit
#define SYNC_DISABLE    0x0
#define SYNC_ENABLE     0x1
// SYNCSEL bit
#define SYNC_SRC        0x0
#define SYNC_DST        0x1
// DATASIZE bit
#define SIXTEEN_BIT     0x0
#define THIRTYTWO_BIT   0x1
// CHINTE bit
#define CHINT_DISABLE   0x0
#define CHINT_ENABLE    0x1


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif   // - end of F2837xS_DMA_DEFINES_H

//===========================================================================
// End of file.
//===========================================================================
