//*****************************************************************************
//
// adc.h - Defines and Macros for the ADC.
//
// Copyright (C) 2013 Texas Instruments Incorporated
//
// All rights reserved. Property of Texas Instruments Incorporated.
// Restricted rights to use, duplicate or disclose this code are
// granted through contract.
// The program may not be used without the written permission of
// Texas Instruments Incorporated or against the terms and conditions
// stipulated in the agreement under which this program has been supplied,
// and under no circumstances can it be used with non-TI connectivity device.
//
//*****************************************************************************

#ifndef __ADC_H__
#define __ADC_H__

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

//*****************************************************************************
// Values that can be passed to APIs as ulChannel parameter
//*****************************************************************************
#define ADC_CH_0   0x00000000
#define ADC_CH_1   0x00000008
#define ADC_CH_2   0x00000010
#define ADC_CH_3   0x00000018


//*****************************************************************************
//
// Values that can be passed to ADCIntEnable(), ADCIntDisable() 
// and ADCIntClear() as ulIntFlags, and returned from ADCIntStatus()
//
//*****************************************************************************
#define ADC_DMA_DONE        0x00000010
#define ADC_FIFO_OVERFLOW   0x00000008
#define ADC_FIFO_UNDERFLOW  0x00000004
#define ADC_FIFO_EMPTY      0x00000002
#define ADC_FIFO_FULL       0x00000001


//*****************************************************************************
//
// Values that can be passed to ADCChannelGainSet() as ucGain parameter, and
// returned from ADCChannelGainGet()
//
//*****************************************************************************
#define ADC_GAIN_1X  0x00
#define ADC_GAIN_2X  0x01
#define ADC_GAIN_3X  0x02
#define ADC_GAIN_4X  0x03


//*****************************************************************************
//
// API Function prototypes
//
//*****************************************************************************
extern void ADCEnable(unsigned long ulBase);
extern void ADCDisable(unsigned long ulBase);
extern void ADCChannelEnable(unsigned long ulBase,unsigned long ulChannel);
extern void ADCChannelDisable(unsigned long ulBase,unsigned long ulChannel);
extern void ADCIntRegister(unsigned long ulBase, unsigned long ulChannel, 
                    void (*pfnHandler)(void));
extern void ADCIntUnregister(unsigned long ulBase, unsigned long ulChannel);
extern void ADCIntEnable(unsigned long ulBase, unsigned long ulChannel, 
                  unsigned long ulIntFlags);
extern void ADCIntDisable(unsigned long ulBase, unsigned long ulChannel, 
                  unsigned long ulIntFlags);
extern unsigned long ADCIntStatus(unsigned long ulBase,unsigned long ulChannel);
extern void ADCIntClear(unsigned long ulBase, unsigned long ulChannel, 
                  unsigned long ulIntFlags);
extern void ADCDMAEnable(unsigned long ulBase, unsigned long ulChannel);
extern void ADCDMADisable(unsigned long ulBase, unsigned long ulChannel);
extern void ADCChannelGainSet(unsigned long ulBase, unsigned long ulChannel,
                       unsigned char ucGain);
extern unsigned char ADCChannleGainGet(unsigned long ulBase,
                                       unsigned long ulChannel);
extern void ADCTimerConfig(unsigned long ulBase, unsigned long ulValue);
extern void ADCTimerEnable(unsigned long ulBase);
extern void ADCTimerDisable(unsigned long ulBase);
extern void ADCTimerReset(unsigned long ulBase);
extern unsigned long ADCTimerValueGet(unsigned long ulBase);
extern unsigned char ADCFIFOLvlGet(unsigned long ulBase, 
                                   unsigned long ulChannel);
extern unsigned long ADCFIFORead(unsigned long ulBase,
                                   unsigned long ulChannel);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif // __ADC_H__

