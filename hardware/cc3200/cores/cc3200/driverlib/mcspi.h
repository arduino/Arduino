//*****************************************************************************
//
// mcspi.h - Defines and Macros for the McSPI.
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

#ifndef __MCSPI_H__
#define __MCSPI_H__

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
        

//#define MCSPI_MAX_CHANNELS								4

//*****************************************************************************
// Values that can be passed to McSPIConfig()
//*****************************************************************************
#define MCSPI_MASTER_MODE 0
#define MCSPI_SLAVE_MODE  1
  
#define MCSPI_CS_ACTIVELOW  1
#define MCSPI_CS_ACTIVEHIGH 0

#define MCSPI_CLK_ACTIVELOW  1
#define MCSPI_CLK_ACTIVEHIGH 0

#define MCSPI_PHA_ODD_EDGES  0x0
#define MCSPI_PHA_EVEN_EDGES 0x1

//*****************************************************************************
// Values that can be passed to McSPIStartBitEnable()
//*****************************************************************************
#define MCSPI_SBE_ENABLE  1
#define MCSPI_SBE_DISABLE 0

#define MCSPI_TRM_TXONLY  2
#define MCSPI_TRM_RXONLY  1
#define MCSPI_TRM_TXRX    0

//*****************************************************************************
// Values taht can be passed to McSPIIntEnable(), McSPIIntDiasble(), 
// McSPIIntClear() or returned from McSPIStatus()
//*****************************************************************************
#define MCSPI_INT_DMATX         0x20000000
#define MCSPI_INT_DMARX         0x10000000
#define MCSPI_INT_EOW           0x00020000
#define MCSPI_INT_RX_OVRFLOW    0x00000008
#define MCSPI_INT_RX_FULL       0x00000004
#define MCSPI_INT_TX_UDRFLOW    0x00000002
#define MCSPI_INT_TX_EMPTY      0x00000001
 
//*****************************************************************************
// Values taht can be passed to McSPITransfer()
//*****************************************************************************
#define MCSPI_CS_ENABLE  0x00000001
#define MCSPI_CS_DISABLE 0x00000002

//*****************************************************************************
// Values taht can be passed to McSPIFIFOEnable() and McSPIFIFODisable()
//*****************************************************************************
#define MCSPI_TX_FIFO 0x08000000
#define MCSPI_RX_FIFO 0x10000000
  
 
//*****************************************************************************
// Values taht can be passed to McSPIDMAEnable() and McSPIDmaDisable
//*****************************************************************************
#define MCSPI_RX_DMA 0x00008000
#define MCSPI_TX_DMA 0x00004000

//*****************************************************************************
// Values taht can be passed to McSPIInitDelaySet() or 
// returned for McSPIInitDelayGet
//*****************************************************************************  
#define MCSPI_INITDLY_0     0x00000000
#define MCSPI_INITDLY_4     0x00000010
#define MCSPI_INITDLY_8     0x00000020
#define MCSPI_INITDLY_16    0x00000030
#define MCSPI_INITDLY_32    0x00000040
  
//*****************************************************************************
//
// API Function prototypes
//
//***************************************************************************** 
extern void McSPIReset(unsigned long ulBase);
extern void McSPIConfig(unsigned long ulBase, unsigned char ucMSMode,
            unsigned long ulMcSPIClk, unsigned long ulBaud,
            unsigned char ucWordLen, unsigned char ucCSPolarity,
            unsigned char ucClkPhase, unsigned char ucClkPolarity);
extern unsigned char McSPIMSModeGet(unsigned long ulBase);
extern unsigned long McSPIWordLenGet(unsigned long ulBase);
extern void McSPISPITRModeSet(unsigned long ulBase, unsigned long ulSPIMode);
extern unsigned char McSPISPITRModeGet(unsigned long ulBase);
extern void McSPIDataLineConfigSet(unsigned long ulBase, 
                                   unsigned char ucDataLineConf);
extern unsigned long McSPIDataLineConfigGet(unsigned long ulBase);
extern void McSPIChannelEnable(unsigned long ulBase);
extern void McSPIChannelDisable(unsigned long ulBase);
extern tBoolean McSPIDataNonBlockingGet(unsigned long ulBase, 
                                        unsigned long * pulData);
extern unsigned long McSPIDataGet(unsigned long ulBase);
extern tBoolean McSPIDataNonBlockingPut(unsigned long ulBase, 
                                        unsigned long ulData);
extern void McSPIDataPut(unsigned long ulBase, unsigned long ulData);
extern void McSPICSEnable(unsigned long ulBase);
extern void McSPICSDisable(unsigned long ulBase);
extern void McSPITransfer(unsigned long ulBase, unsigned char *ucDout,
                   unsigned char *ucDin, unsigned long ulSize,
                   unsigned long ulFlags);
extern void McSPIFIFOEnable(unsigned long ulBase, unsigned long ulFlags);
extern void McSPIFIFODisable(unsigned long ulBase, unsigned long ulFlags);
extern void McSPIConfigureAFL(unsigned long ulBase, unsigned char ucAFLData);
extern void McSPIConfigureAEL(unsigned long ulBase, unsigned char ucAELData);
extern void McSPIConfigureWCNT(unsigned long ulBase, unsigned short ucWCNT);
extern void McSPIDmaEnable(unsigned long ulBase, unsigned long ulFlags);
extern void McSPIDmaDisable(unsigned long ulBase, unsigned ulFlags);
extern void McSPIIntRegister(unsigned long ulBase, void(*pfnHandler)(void));
extern void McSPIIntUnregister(unsigned long ulBase);
extern void McSPIIntEnable(unsigned long ulBase, unsigned long ulIntFlags);
extern void McSPIIntDisable(unsigned long ulBase, unsigned long ulIntFlags);
extern unsigned long McSPIIntStatus(unsigned long ulBase, tBoolean bMasked);
extern void McSPIIntClear(unsigned long ulBase, unsigned long ulIntFlags);
extern void McSPIInitDelaySet(unsigned long ulBase, unsigned char ucInitDelay);
extern unsigned long McSPIInitDelayGet(unsigned long ulBase);
extern void McSPIStartBitEnable(unsigned long ulBase, tBoolean bSBPolHigh);
extern void McSPIStartBitDisable(unsigned long ulBase);
extern void McSPITurboModeEnable(unsigned long ulBase);
extern void McSPITurboModeDisable(unsigned long ulBase);
extern void McSPI3PinModeEnable(unsigned long ulBase);
extern void McSPI3PinModeDisable(unsigned long ulBase);
  
//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif //  __MCSPI_H__
