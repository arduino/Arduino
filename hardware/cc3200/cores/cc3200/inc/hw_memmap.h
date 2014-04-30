//*****************************************************************************
//
//  Copyright (C) 2013 Texas Instruments Incorporated
//
//  All rights reserved. Property of Texas Instruments Incorporated.
//  Restricted rights to use, duplicate or disclose this code are
//  granted through contract.
//
//  The program may not be used without the written permission of
//  Texas Instruments Incorporated or against the terms and conditions
//  stipulated in the agreement under which this program has been supplied,
//  and under no circumstances can it be used with non-TI connectivity device.
//
//*****************************************************************************

#ifndef __HW_MEMMAP_H__
#define __HW_MEMMAP_H__

//*****************************************************************************
//
// The following are defines for the base address of the memories and
// peripherals on the slave_1 interface.
//
//*****************************************************************************
#define FLASH_BASE              0x01000000  
#define SRAM_BASE               0x20000000
#define WDT_BASE                0x40000000
#define GPIOA0_BASE             0x40004000
#define GPIOA1_BASE             0x40005000 
#define GPIOA2_BASE             0x40006000 
#define GPIOA3_BASE             0x40007000 
#define UARTA0_BASE             0x4000C000 
#define UARTA1_BASE             0x4000D000 
#define I2CA0_BASE              0x40020000 
#define TIMERA0_BASE            0x40030000 
#define TIMERA1_BASE            0x40031000 
#define TIMERA2_BASE            0x40032000 
#define TIMERA3_BASE            0x40033000   
#define STACKDIE_CTRL_BASE      0x400F5000 
#define COMMON_REG_BASE         0x400F7000 
#define FLASH_CONTROL_BASE      0x400FD000 
#define SYSTEM_CONTROL_BASE     0x400FE000 
#define UDMA_BASE               0x400FF000   
#define SDHOST_BASE             0x44010000 
#define CAMERA_BASE             0x44018000  
#define MCASPA0_BASE            0x4401C000  
#define SSPI_BASE               0x44020000  
#define GSPI_BASE               0x44021000  
#define LSPI_BASE               0x44022000  
#define ARCM_BASE               0x44025000  
#define APPS_CONFIG_BASE        0x44026000  
#define GPRCM_BASE              0x4402D000  
#define OCP_SHARED_BASE         0x4402E000  
#define ADC_BASE                0x4402E800   
#define HIB1P2_BASE             0x4402F000  
#define HIB3P3_BASE             0x4402F800  
#define DTHE_BASE               0x44030000  
#define SHAMD5_BASE             0x44035000  
#define AES_BASE                0x44037000
#define DES_BASE                0x44039000


#endif // __HW_MEMMAP_H__
