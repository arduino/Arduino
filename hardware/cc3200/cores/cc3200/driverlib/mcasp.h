//*****************************************************************************
//
// mcasp.h - Defines and Macros for the McASP.
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

#ifndef __MCASP_H__
#define __MCASP_H__

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
#define MCASP_BASE		MCASPA0_BASE

//*****************************************************************************
// Macros for McASPFSyncConfig()
//*****************************************************************************

#define MCASP_FS_MODE_BURST  	0x00000000
#define MCASP_FS_MODE_I2S	0x00000100
#define MCASP_FS_MODE_TDM_2  	0x00000100
#define MCASP_FS_MODE_TDM_3   	0x00000180
#define MCASP_FS_MODE_TDM_4   	0x00000200
#define MCASP_FS_MODE_TDM_5   	0x00000280
#define MCASP_FS_MODE_TDM_6   	0x00000300
#define MCASP_FS_MODE_TDM_7   	0x00000380
#define MCASP_FS_MODE_TDM_8   	0x00000400
#define MCASP_FS_MODE_TDM_9   	0x00000480
#define MCASP_FS_MODE_TDM_10 	0x00000500
#define MCASP_FS_MODE_TDM_11 	0x00000580
#define MCASP_FS_MODE_TDM_12 	0x00000600
#define MCASP_FS_MODE_TDM_13 	0x00000680
#define MCASP_FS_MODE_TDM_14 	0x00000700
#define MCASP_FS_MODE_TDM_15 	0x00000780
#define MCASP_FS_MODE_TDM_16 	0x00000800
#define MCASP_FS_MODE_TDM_17 	0x00000880
#define MCASP_FS_MODE_TDM_18 	0x00000900
#define MCASP_FS_MODE_TDM_19 	0x00000980
#define MCASP_FS_MODE_TDM_20 	0x00000A00
#define MCASP_FS_MODE_TDM_21 	0x00000A80
#define MCASP_FS_MODE_TDM_22 	0x00000B00
#define MCASP_FS_MODE_TDM_23 	0x00000B80
#define MCASP_FS_MODE_TDM_24 	0x00000C00
#define MCASP_FS_MODE_TDM_25 	0x00000C80
#define MCASP_FS_MODE_TDM_26 	0x00000D00
#define MCASP_FS_MODE_TDM_27 	0x00000D80
#define MCASP_FS_MODE_TDM_28 	0x00000E00
#define MCASP_FS_MODE_TDM_29 	0x00000E80
#define MCASP_FS_MODE_TDM_30 	0x00000F00
#define MCASP_FS_MODE_TDM_31 	0x00000F80
#define MCASP_FS_MODE_TDM_32 	0x00001000

#define MCASP_FS_WIDTH_BIT    	0x00000000
#define MCASP_FS_WIDTH_WORD   	0x00000010
#define MCASP_FS_POL_RISE    	0x00000000
#define MCASP_FS_POL_FALL    	0x00000001


//*****************************************************************************
// Values that can be passed to McASPTxFMTConfig() and McASPRxFMTConfig()
//*****************************************************************************

// 
// FSync delay
//
#define MCASP_FMT_FSDLY_NONE	0x00000000
#define MCASP_FMT_FSDLY_1	0x00010000
#define MCASP_FMT_FSDLY_2	0x00020000

//
// Bit order
//
#define MCASP_FMT_FST_LSB	0x00000000
#define MCASP_FMT_FST_MSB	0x00008000

//
// Padding
//
#define MCASP_FMT_PAD_0		0x00000000
#define MCASP_FMT_PAD_1		0x00002000
#define MCASP_FMT_DBIT_0	0x00004000
#define MCASP_FMT_DBIT_1	0x00004100
#define MCASP_FMT_DBIT_2	0x00004200
#define MCASP_FMT_DBIT_3	0x00004300
#define MCASP_FMT_DBIT_4	0x00004400
#define MCASP_FMT_DBIT_5	0x00004500
#define MCASP_FMT_DBIT_6	0x00004600
#define MCASP_FMT_DBIT_7	0x00004700
#define MCASP_FMT_DBIT_8	0x00004800
#define MCASP_FMT_DBIT_9	0x00004900
#define MCASP_FMT_DBIT_10	0x00004A00
#define MCASP_FMT_DBIT_11	0x00004B00
#define MCASP_FMT_DBIT_12	0x00004C00
#define MCASP_FMT_DBIT_13	0x00004D00
#define MCASP_FMT_DBIT_14	0x00004E00
#define MCASP_FMT_DBIT_15	0x00004F00
#define MCASP_FMT_DBIT_16	0x00005000
#define MCASP_FMT_DBIT_17	0x00005100
#define MCASP_FMT_DBIT_18	0x00005200
#define MCASP_FMT_DBIT_19	0x00005300
#define MCASP_FMT_DBIT_20	0x00005400
#define MCASP_FMT_DBIT_21	0x00005500
#define MCASP_FMT_DBIT_22	0x00005600
#define MCASP_FMT_DBIT_23	0x00005700
#define MCASP_FMT_DBIT_24	0x00005800
#define MCASP_FMT_DBIT_25	0x00005900
#define MCASP_FMT_DBIT_26	0x00005A00
#define MCASP_FMT_DBIT_27	0x00005B00
#define MCASP_FMT_DBIT_28	0x00005C00
#define MCASP_FMT_DBIT_29	0x00005D00
#define MCASP_FMT_DBIT_30	0x00005E00
#define MCASP_FMT_DBIT_31	0x00005F00

//
// Slot size
//
#define MCASP_FMT_SSZ_8		0x00000030
#define MCASP_FMT_SSZ_12	0x00000050
#define MCASP_FMT_SSZ_16	0x00000070
#define MCASP_FMT_SSZ_20	0x00000090
#define MCASP_FMT_SSZ_24	0x000000B0
#define MCASP_FMT_SSZ_28	0x000000D0
#define MCASP_FMT_SSZ_32	0x000000F0

//
// Words size
//
#define MCASP_FMT_WSZ_4		0x00000001
#define MCASP_FMT_WSZ_8		0x00000002
#define MCASP_FMT_WSZ_12	0x00000003
#define MCASP_FMT_WSZ_16	0x00000004
#define MCASP_FMT_WSZ_20	0x00000005
#define MCASP_FMT_WSZ_24	0x00000006
#define MCASP_FMT_WSZ_28	0x00000007
#define MCASP_FMT_WSZ_32	0x00000008

//
// Data Port
//
#define MCASP_PORT_DMA		0x00000000
#define MCASP_PORT_CPU		0x00000008

//
// Data representation
//
#define MCASP_FMT_Q31           0x00000000
#define MCASP_FMT_INT           0x00000001

//
// Alignment
//
#define MCASP_FMT_ALIGN_LFT     0x00000000
#define MCASP_FMT_ALIGN_RHT     0x00000001
	
//*****************************************************************************
// Values that can be passed to McASPClkConfig()
//*****************************************************************************
#define MCASP_CLK_POL_RISE      0x00000080
#define MCASP_CLK_POL_FALL      0x00000080

//*****************************************************************************
//Value that can be passed to McASPSerialConfig()
//*****************************************************************************

#define MCASP_SER_MODE_TX	0x00000001
#define MCASP_SER_MODE_RX	0x00000002
#define MCASP_INACT_TRI 	0x00000000
#define MCASP_INACT_0	        0x00000008
#define MCASP_INACT_1   	0x0000000C


//*****************************************************************************
// Vlaues that can be passed to McASPIntEnable and McASPIntDiasble().
//*****************************************************************************

#define MCASP_INT_XUNDRN	0x00000001
#define MCASP_INT_XSYNCERR	0x00000002
#define MCASP_INT_XCKFAIL	0x00000004
#define MCASP_INT_XDMAERR	0x00000008
#define MCASP_INT_XLAST		0x00000010
#define MCASP_INT_XDATA		0x00000020
#define MCASP_INT_XSTAFRM	0x00000080
#define MCASP_INT_XDMA		0x00000100

#define MCASP_INT_ROVRN		0x00010000
#define MCASP_INT_RSYNCERR	0x00020000
#define MCASP_INT_RCKFAIL	0x00040000
#define MCASP_INT_RDMAERR	0x00080000
#define MCASP_INT_RLAST		0x00100000
#define MCASP_INT_RDATA		0x00200000
#define MCASP_INT_RSTAFRM	0x00800000
#define MCASP_INT_RDMA		0x01000000


//*****************************************************************************
// Macros for McASPIntStatus() and McASPIntClear().
//****************************************************************************
#define MCASP_STAT_XERR		0x00000100
#define MCASP_STAT_XDMAERR	0x00000080
#define MCASP_STAT_XSTAFRM	0x00000040
#define MCASP_STAT_XDATA	0x00000020
#define MCASP_STAT_XLAST	0x00000010	
#define MCASP_STAT_XTDMSLOT	0x00000008
#define MCASP_STAT_XCKFAIL	0x00000004
#define MCASP_STAT_XSYNCERR	0x00000002
#define MCASP_STAT_XUNDRN	0x00000001

#define MCASP_STAT_RERR		0x01000000
#define MCASP_STAT_RDMAERR	0x00800000
#define MCASP_STAT_RSTAFRM	0x00400000
#define MCASP_STAT_RDATA	0x00200000
#define MCASP_STAT_RLAST	0x00100000
#define MCASP_STAT_RTDMSLOT	0x00080000
#define MCASP_STAT_RCKFAIL	0x00040000
#define MCASP_STAT_RSYNCERR	0x00020000
#define MCASP_STAT_ROVERN	0x00010000

//*****************************************************************************
// Values that can be passed to McASPDMAStatus() and McASPDMAClear().
//*****************************************************************************

#define MCASP_XDMA_DONE		0x00000800
#define MCASP_RDMA_DONE		0x00000400


//*****************************************************************************
//Values that can be passed to McASPGBLEnable() and McASPGBLDisable()
//*****************************************************************************

#define MCASP_GBL_RCLK		0x00000001
#define MCASP_GBL_RHCLK		0x00000002
#define MCASP_GBL_RSER		0x00000004
#define MCASP_GBL_RSM		0x00000008
#define MCASP_GBL_RFSYNC	0x00000010
#define MCASP_GBL_XCLK		0x00000100
#define MCASP_GBL_XHCLK		0x00000200
#define MCASP_GBL_XSER		0x00000400
#define MCASP_GBL_XSM		0x00000800
#define MCASP_GBL_XFSYNC	0x00001000

//*****************************************************************************
//Values that can be passed to McASPPinDirSet()
//*****************************************************************************
#define MCASP_PIN_OUT	        0x00000001
#define MCASP_PIN_IN    	0x00000000
#define MCASP_PIN_DATA_0        0x00000000
#define MCASP_PIN_DATA_1        0x00000001
#define MCASP_PIN_AFSX          0x0000001C
#define MCASP_PIN_ACLKX         0x0000001A

//*****************************************************************************
//Values that can be passed to McASPPinModeSet()
//*****************************************************************************
#define MCASP_MODE_0		0x00000000
#define MCASP_MODE_1		0x00000001
#define MCASP_MODE_2		0x00000002
#define MCASP_MODE_3		0x00000003

//*****************************************************************************
// Values that can be passed to McASPDMAEnable() and McASPDMADisable()
//*****************************************************************************
#define MCASP_DMA_TX            0x00000001
#define MCASP_DMA_RX            0x00000002
#define MCASP_DMA_BOTH          0x00000003

//*****************************************************************************
// DMA Port Address
//*****************************************************************************
#define MCASP_DMA_TX_PORT 	0x4401E200
#define MCASP_DMA_RX_PORT 	0x4401E280

	
//*****************************************************************************
// API function prototypes
//*****************************************************************************
extern void McASPReset(unsigned long ulBase);
extern void McASPPinDirSet(unsigned long ulBase, unsigned long ulPin,unsigned long ulPinDir);

extern void McASPGBLEnable(unsigned long ulBase, unsigned long ulFlag);
extern void McASPGBLDisable(unsigned long ulBase, unsigned long ulFlag);

extern void McASPTxValidBitSet(unsigned long ulBase, unsigned long ulValidMask);
extern void McASPRxValidBitSet(unsigned long ulBase, unsigned long ulValidMask);
extern unsigned long McASPTxValidBitGet(unsigned long ulBase);
extern unsigned long McASPRxValidBitGet(unsigned long ulBase);

extern void McASPClkConfig(unsigned long ulBase, unsigned long ulMcASPClk,
                                unsigned long ulBitClk, unsigned ulClkPol);

extern void McASPFSyncConfig(unsigned long ulBase, unsigned long ulFSyncMode,unsigned long ulWidth,
                        unsigned long ulPol,tBoolean bExtrn);

extern void McASPSerEnable(unsigned long ulBase, unsigned long ulDataPin, unsigned long ulSerMode, 
                       unsigned long ulInactLvl);

extern void McASPSerDisable(unsigned long ulBase, unsigned long ulDataPin);

extern long McASPSendNonBlocking(unsigned long ulBase, unsigned long ulDataPin,unsigned long ulData);
extern void McASPSend(unsigned long ulBase, unsigned long ulDataPin,unsigned long ulData);
extern long McASPRecvNonBlocking(unsigned long ulBase, unsigned long ulDataPin,unsigned long *ulData);
extern void McASPRecv(unsigned long ulBase, unsigned long ulDataPin,unsigned long *ulData);



extern void McASPTxActiveSlotSet(unsigned long ulBase, unsigned long ulMask);
extern void McASPRxActiveSlotSet(unsigned long ulBase, unsigned long ulMask);
extern unsigned long McASPTxActiveSlotGet(unsigned long ulBase);
extern unsigned long McASPRxActiveSlotGet(unsigned long ulBase);
extern unsigned long McASPTxCurSlotGet(unsigned long ulBase);
extern unsigned long McASPRxCurSlotGet(unsigned long ulBase);

extern void McASPIntRegister(unsigned long ulBase, void (*pfnHandler)(void));
extern void McASPIntUnregister(unsigned long ulBase);
extern void McASPIntEnable(unsigned long ulBase, unsigned long ulFlag);
extern void McASPIntDisable(unsigned long ulBase, unsigned long ulFlag);
extern unsigned long McASPIntStatus(unsigned long ulBase);
extern void McASPIntClear(unsigned long ulBase, unsigned long ulFlag);

extern void McASPTxPortSet(unsigned long ulBase, unsigned long ulFlag);
extern unsigned long McASPTxPortGet(unsigned long ulBase);
extern void McASPRxPortSet(unsigned long ulBase, unsigned long ulFlag);
extern unsigned long McASPRxPortGet(unsigned long ulBase);

extern void McASPTxEnable(unsigned long ulBase);
extern void McASPRxEnable(unsigned long ulBase);
extern void McASPTxDisable(unsigned long ulBase);
extern void McASPRxDisable(unsigned long ulBase);

extern void McASPXferModeSet(unsigned long ulBase, unsigned long ulMode);

extern void McASPTxClkChkConfig(unsigned long ulBase, unsigned long ulPrescale,unsigned long ulMin,unsigned long ulMax);
extern unsigned long McASPTxClkChkCount(unsigned long ulBase);
extern void McASPRxClkChkConfig(unsigned long ulBase, unsigned long ulPrescale,unsigned long ulMin,unsigned long ulMax);
extern unsigned long McASPRxClkChkCount(unsigned long ulBase);
extern unsigned long McASPPinDirGet(unsigned long ulBase, unsigned long ulPin);
extern void McASPTxFMTConfig(unsigned long ulBase, unsigned long ulFdelay,unsigned long ulPad,
                       unsigned long ulSlot, unsigned long ulWord,
		       unsigned long ulAlign, unsigned long ulOrder,
		       unsigned long ulDspRep);
extern void McASPRxFMTConfig(unsigned long ulBase, unsigned long ulFdelay,unsigned long ulPad,
                       unsigned long ulSlot, unsigned long ulWord,
		       unsigned long ulAlign, unsigned long ulOrder,
		       unsigned long ulDspRep);

extern unsigned long McASPDMAStatus(unsigned long ulBase, tBoolean bMasked);
extern void McASPDMAClear(unsigned long ulBase, unsigned long ulDmaFlag);
extern void McASPDMAEnable(unsigned long ulBase, unsigned long ulDmaFlag);
extern void McASPDMADisable(unsigned long ulBase, unsigned long ulDmaFlag);
extern void McASPTxFIFOEnable(unsigned long ulBase, unsigned long ulLevel, unsigned long ulWordspertransfer);
extern void McASPRxFIFOEnable(unsigned long ulBase, unsigned long ulLevel, unsigned long ulWordspertransfer);
extern void McASPTxFIFODisable(unsigned long ulBase);
extern void McASPRxFIFODisable(unsigned long ulBase);




//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************

#ifdef __cplusplus
}
#endif

#endif //  __MCASP_H__
