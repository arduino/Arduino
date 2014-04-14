//*****************************************************************************
//
// des.h - Defines and Macros for the DES module.
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

#ifndef __DRIVERLIB_DES_H__
#define __DRIVERLIB_DES_H__

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
//
// The following defines are used to specify the direction with the
// ui32Config argument in the DESConfig() function.  Only one is permitted.
//
//*****************************************************************************
#define DES_CFG_DIR_DECRYPT     0x00000000
#define DES_CFG_DIR_ENCRYPT     0x00000004

//*****************************************************************************
//
// The following defines are used to specify the operational with the
// ui32Config argument in the DESConfig() function.  Only one is permitted.
//
//*****************************************************************************
#define DES_CFG_MODE_ECB        0x00000000
#define DES_CFG_MODE_CBC        0x00000010
#define DES_CFG_MODE_CFB        0x00000020

//*****************************************************************************
//
// The following defines are used to select between single DES and triple DES
// with the ui32Config argument in the DESConfig() function.  Only one is
// permitted.
//
//*****************************************************************************
#define DES_CFG_SINGLE          0x00000000
#define DES_CFG_TRIPLE          0x00000008

//*****************************************************************************
//
// The following defines are used with the DESIntEnable(), DESIntDisable() and
// DESIntStatus() functions.
//
//*****************************************************************************
#define DES_INT_CONTEXT_IN      0x00000001
#define DES_INT_DATA_IN         0x00000002
#define DES_INT_DATA_OUT        0x00000004
#define DES_INT_DMA_CONTEXT_IN  0x00010000
#define DES_INT_DMA_DATA_IN     0x00020000
#define DES_INT_DMA_DATA_OUT    0x00040000

//*****************************************************************************
//
// The following defines are used with the DESEnableDMA() and DESDisableDMA()
// functions.
//
//*****************************************************************************
#define DES_DMA_CONTEXT_IN      0x00000080
#define DES_DMA_DATA_OUT        0x00000040
#define DES_DMA_DATA_IN         0x00000020

//*****************************************************************************
//
// API Function prototypes
//
//*****************************************************************************
extern void DESConfigSet(uint32_t ui32Base, uint32_t ui32Config);
extern void DESDataRead(uint32_t ui32Base, uint32_t *pui32Dest);
extern bool DESDataReadNonBlocking(uint32_t ui32Base, uint32_t *pui32Dest);
extern bool DESDataProcess(uint32_t ui32Base, uint32_t *pui32Src,
                           uint32_t *pui32Dest, uint32_t ui32Length);
extern void DESDataWrite(uint32_t ui32Base, uint32_t *pui32Src);
extern bool DESDataWriteNonBlocking(uint32_t ui32Base, uint32_t *pui32Src);
extern void DESDMADisable(uint32_t ui32Base, uint32_t ui32Flags);
extern void DESDMAEnable(uint32_t ui32Base, uint32_t ui32Flags);
extern void DESIntClear(uint32_t ui32Base, uint32_t ui32IntFlags);
extern void DESIntDisable(uint32_t ui32Base, uint32_t ui32IntFlags);
extern void DESIntEnable(uint32_t ui32Base, uint32_t ui32IntFlags);
extern void DESIntRegister(uint32_t ui32Base, void(*pfnHandler)(void));
extern uint32_t DESIntStatus(uint32_t ui32Base, bool bMasked);
extern void DESIntUnregister(uint32_t ui32Base);
extern bool DESIVSet(uint32_t ui32Base, uint32_t *pui32IVdata);
extern void DESKeySet(uint32_t ui32Base, uint32_t *pui32Key);
extern void DESLengthSet(uint32_t ui32Base, uint32_t ui32Length);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif //  __DRIVERLIB_DES_H__
