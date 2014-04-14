//*****************************************************************************
//
// crc.h - Defines and Macros for CRC module.
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

#ifndef __DRIVERLIB_CRC_H__
#define __DRIVERLIB_CRC_H__

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
// The following defines are used in the ui32Config argument of the
// ECConfig function.
//
//*****************************************************************************
#define CRC_CFG_INIT_SEED       0x00000000  // Initialize with seed
#define CRC_CFG_INIT_0          0x00004000  // Initialize to all '0s'
#define CRC_CFG_INIT_1          0x00006000  // Initialize to all '1s'
#define CRC_CFG_SIZE_8BIT       0x00001000  // Input Data Size
#define CRC_CFG_SIZE_32BIT      0x00000000  // Input Data Size
#define CRC_CFG_RESINV          0x00000200  // Result Inverse Enable
#define CRC_CFG_OBR             0x00000100  // Output Reverse Enable
#define CRC_CFG_IBR             0x00000080  // Bit reverse enable
#define CRC_CFG_ENDIAN_SBHW     0x00000000  // Swap byte in half-word
#define CRC_CFG_ENDIAN_SHW      0x00000010  // Swap half-word
#define CRC_CFG_TYPE_P8005      0x00000000  // Polynomial 0x8005
#define CRC_CFG_TYPE_P1021      0x00000001  // Polynomial 0x1021
#define CRC_CFG_TYPE_P4C11DB7   0x00000002  // Polynomial 0x4C11DB7
#define CRC_CFG_TYPE_P1EDC6F41  0x00000003  // Polynomial 0x1EDC6F41
#define CRC_CFG_TYPE_TCPCHKSUM  0x00000008  // TCP checksum

//*****************************************************************************
//
// Function prototypes.
//
//*****************************************************************************
extern void CRCConfigSet(uint32_t ui32Base, uint32_t ui32CRCConfig);
extern uint32_t CRCDataProcess(uint32_t ui32Base, uint32_t *pui32DataIn,
                               uint32_t ui32DataLength, bool bPPResult);
extern void CRCDataWrite(uint32_t ui32Base, uint32_t ui32Data);
extern uint32_t CRCResultRead(uint32_t ui32Base, bool bPPResult);
extern void CRCSeedSet(uint32_t ui32Base, uint32_t ui32Seed);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif // __DRIVERLIB_CRC_H__
