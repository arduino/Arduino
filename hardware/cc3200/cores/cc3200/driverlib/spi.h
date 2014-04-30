//*****************************************************************************
//
// spi.h - Defines and Macros for the SPI.
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

#ifndef __SPI_H__
#define __SPI_H__

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
// Values that can be passed to SPIConfigSetExpClk() as ulMode parameter
//*****************************************************************************
#define SPI_MODE_MASTER    0x00000000
#define SPI_MODE_SLAVE     0x00000004
  
//*****************************************************************************
// Values that can be passed to SPIConfigSetExpClk() as ulSubMode parameter
//*****************************************************************************
#define SPI_SUB_MODE_0     0x00000000
#define SPI_SUB_MODE_1     0x00000001
#define SPI_SUB_MODE_2     0x00000002
#define SPI_SUB_MODE_3     0x00000003


//*****************************************************************************
// Values that can be passed to SPIConfigSetExpClk() as ulConfigFlags parameter
//*****************************************************************************
#define SPI_SW_CTRL_CS      0x01000000
#define SPI_HW_CTRL_CS      0x00000000
#define SPI_3PIN_MODE       0x02000000
#define SPI_4PIN_MODE       0x00000000
#define SPI_TURBO_ON        0x00080000
#define SPI_TURBO_OFF       0x00000000
#define SPI_CS_ACTIVEHIGH   0x00000000
#define SPI_CS_ACTIVELOW    0x00000040
#define SPI_WL_8            0x00000380
#define SPI_WL_16           0x00000780
#define SPI_WL_32           0x00000F80

//*****************************************************************************
// Values that can be passed to SPIFIFOEnable() and SPIFIFODisable()
//*****************************************************************************  
#define SPI_TX_FIFO        0x08000000
#define SPI_RX_FIFO        0x10000000

//*****************************************************************************
// Values that can be passed to SPIDMAEnable() and SPIDMADisable()
//*****************************************************************************    
#define SPI_RX_DMA         0x00008000
#define SPI_TX_DMA         0x00004000

//*****************************************************************************
// Values that can be passed to SPIIntEnable(), SPIIntDiasble(), 
// SPIIntClear() or returned from SPIStatus()
//*****************************************************************************
#define SPI_INT_DMATX         0x20000000
#define SPI_INT_DMARX         0x10000000
#define SPI_INT_EOW           0x00020000
#define SPI_INT_WKS           0x00010000
#define SPI_INT_RX_OVRFLOW    0x00000008
#define SPI_INT_RX_FULL       0x00000004
#define SPI_INT_TX_UDRFLOW    0x00000002
#define SPI_INT_TX_EMPTY      0x00000001
 
//*****************************************************************************
// Values that can be passed to SPITransfer()
//*****************************************************************************
#define SPI_CS_ENABLE  0x00000001
#define SPI_CS_DISABLE 0x00000002
  
//*****************************************************************************
//
// API Function prototypes
//
//***************************************************************************** 
extern void SPIEnable(unsigned long ulBase);
extern void SPIDisable(unsigned long ulBase);
extern void SPIReset(unsigned long ulBase);
extern void SPIConfigSetExpClk(unsigned long ulBase,unsigned long ulSPIClk, 
            unsigned long ulBitRate, unsigned long ulMode, 
            unsigned long ulSubMode, unsigned long ulConfig);
extern long SPIDataGetNonBlocking(unsigned long ulBase, 
                                        unsigned long * pulData);
extern void SPIDataGet(unsigned long ulBase, unsigned long *pulData);
extern long SPIDataPutNonBlocking(unsigned long ulBase, 
                                        unsigned long ulData);
extern void SPIDataPut(unsigned long ulBase, unsigned long ulData);
extern void SPIFIFOEnable(unsigned long ulBase, unsigned long ulFlags);
extern void SPIFIFODisable(unsigned long ulBase, unsigned long ulFlags);
extern void SPIFIFOLevelSet(unsigned long ulBase, unsigned long ulTxLevel, 
                   unsigned long ulRxLevel);
extern void SPIFIFOLevelGet(unsigned long ulBase, unsigned long *pulTxLevel,
                 unsigned long *pulRxLevel);
extern void SPIWordCountSet(unsigned long ulBase, unsigned long ulWordCount);
extern void SPIIntRegister(unsigned long ulBase, void(*pfnHandler)(void));
extern void SPIIntUnregister(unsigned long ulBase);
extern void SPIIntEnable(unsigned long ulBase, unsigned long ulIntFlags);
extern void SPIIntDisable(unsigned long ulBase, unsigned long ulIntFlags);
extern unsigned long SPIIntStatus(unsigned long ulBase, tBoolean bMasked);
extern void SPIIntClear(unsigned long ulBase, unsigned long ulIntFlags);
extern void SPIDmaEnable(unsigned long ulBase, unsigned long ulFlags);
extern void SPIDmaDisable(unsigned long ulBase, unsigned long ulFlags);
extern void SPICSEnable(unsigned long ulBase);
extern void SPICSDisable(unsigned long ulBase);
extern long SPITransfer(unsigned long ulBase, unsigned char *ucDout,
                   unsigned char *ucDin, unsigned long ulSize,
                   unsigned long ulFlags);

  
//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif //  __SPI_H__
