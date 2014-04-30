//*****************************************************************************
//
// camera.h - Prototypes and macros for the camera controller module.
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

#ifndef __CAMERA_H__
#define __CAMERA_H__

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
// Macro defining Camera buffer address
//*****************************************************************************  
#define CAM_BUFFER_ADDR 0x44018100
  
  
//*****************************************************************************
// Value that can be passed to CameraXClkSet().
//*****************************************************************************
#define CAM_XCLK_STABLE_LO          0x00
#define CAM_XCLK_STABLE_HI          0x01
#define CAM_XCLK_DIV_BYPASS         0x02
  
  
//*****************************************************************************
// Value that can be passed to CameraIntEnable(), CameraIntDisable, 
// CameraIntClear() or returned from CameraIntStatus().
//*****************************************************************************
#define CAM_INT_DMA           0x80000000
#define CAM_INT_FE            0x00010000
#define CAM_INT_FSC_ERR       0x00000200 
#define CAM_INT_FIFO_NOEMPTY  0x00000010
#define CAM_INT_FIFO_FULL     0x00000008
#define CAM_INT_FIFO_THR      0x00000004
#define CAM_INT_FIFO_OF       0x00000002
#define CAN_INT_FIFO_UR       0x00000001
  
  
//*****************************************************************************
// Value that can be passed to CameraXClkConfig().
//*****************************************************************************
#define CAM_HS_POL_HI       0x00000000
#define CAM_HS_POL_LO       0000000200
#define CAM_VS_POL_HI       0x00000000
#define CAM_VS_POL_LO       0x00000100

#define CAM_PCLK_RISE_EDGE  0x00000000
#define CAM_PCLK_FALL_EDGE  0000000400

#define CAM_ORDERCAM_SWAP   0x00000800
#define CAM_BT_CORRECT_EN   0x00001000
#define CAM_NOBT_SYNCHRO    0x00002000
#define CAM_IF_SYNCHRO      0x00080000
  

//*****************************************************************************
//
// API Function prototypes
//
//***************************************************************************** 
extern void CameraReset(unsigned long ulBase);
extern void CameraParamsConfig(unsigned long ulBase, unsigned long ulHSPol,
                               unsigned long ulVSPol, unsigned long ulFlags);
extern void CameraXClkConfig(unsigned long ulBase, unsigned long ulCamClkIn,
                             unsigned long ulXClk);
extern void CameraXClkSet(unsigned long ulBase, unsigned char bXClkFlags);
extern void CameraDMAEnable(unsigned long ulBase);
extern void CameraDMADisable(unsigned long ulBase);
extern void CameraThresholdSet(unsigned long ulBase, unsigned long ulThreshold);
extern void CameraIntRegister(unsigned long ulBase, void (*pfnHandler)(void));
extern void CameraIntUnregister(unsigned long ulBase);
extern void CameraIntEnable(unsigned long ulBase, unsigned long ulIntFlags);
extern void CameraIntDisable(unsigned long ulBase, unsigned long ulIntFlags);
extern unsigned long CameraIntStatus(unsigned long ulBase);
extern void CameraIntClear(unsigned long ulBase, unsigned long ulIntFlags);
extern void CameraCaptureStop(unsigned long ulBase, tBoolean bImmediate);
extern void CameraCaptureStart(unsigned long ulBase);
extern void CameraBufferRead(unsigned long ulBase,unsigned long *pBuffer, 
                          unsigned char ucSize);
  
//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif //__CAMERA_H__
