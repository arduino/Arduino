//###########################################################################
//
// FILE:   F2806x_Dma_defines.h
//
// TITLE:  #defines used in DMA examples
//
//###########################################################################
// $TI Release: 2806x C/C++ Header Files V1.10 $
// $Release Date: April 7, 2011 $
//###########################################################################

#ifndef F2806x_DMA_DEFINES_H
#define F2806x_DMA_DEFINES_H


#ifdef __cplusplus
extern "C" {
#endif

// MODE
//==========================
// PERINTSEL bits
#define DMA_SEQ1INT 	1
#define DMA_SEQ2INT 	2
#define DMA_XINT1   	3
#define DMA_XINT2   	4
#define DMA_XINT3   	5
#define DMA_USB0EP1RX	7
#define DMA_USB0EP1TX	8
#define DMA_USB0EP2RX	9
#define DMA_USB0EP2TX	10
#define DMA_TINT0   	11
#define DMA_TINT1   	12
#define DMA_TINT2   	13
#define DMA_MXEVTA  	14
#define DMA_MREVTA  	15
#define DMA_EPWM1A  	18
#define DMA_EPWM1B  	19
#define DMA_EPWM2A  	20
#define DMA_EPWM2B  	21
#define DMA_EPWM3A  	22
#define DMA_EPWM3B  	23
#define DMA_EPWM4A  	24
#define DMA_EPWM4B  	25
#define DMA_EPWM5A  	26
#define DMA_EPWM5B  	27
#define DMA_EPWM6A  	28
#define DMA_EPWM6B  	29
#define DMA_USB0EP3RX	30
#define DMA_USB0EP3TX	31
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

#endif   // - end of F2806x_DMA_DEFINES_H

//===========================================================================
// End of file.
//===========================================================================
