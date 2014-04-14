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
#define ROM_MEM_BASE            0x00000000  
#define WD_TIMER_BASE           0x40000000  
#define GPIOS0_BASE             0x40004000  
#define GPIOS1_BASE             0x40005000  
#define GPIOS2_BASE             0x40006000  
#define GPIOS3_BASE             0x40007000  
#define UARTA0_BASE             0x4000C000  
#define UARTA1_BASE             0x4000D000  
#define I2CS0_BASE              0x40020000  
#define GPIOS4_BASE             0x40024000  
#define GPTA0_BASE              0x40030000  
#define GPTA1_BASE              0x40031000  
#define GPTA2_BASE              0x40032000  
#define GPTA3_BASE              0x40033000  
#define TOPDIE_PBIST_BASE       0x400AD000  
#define TOPDIE_FLTEST_BASE      0x400AE000  
#define EEPROM_BASE             0x400AF000  
#define EPIS0_BASE              0x400D0000  
#define STACKDIE_CTRL_BASE      0x400F5000  
#define COMMON_REG_BASE         0x400F7000  
#define FLASH_CONTROL_BASE      0x400FD000  
#define SYSTEM_CONTROL_BASE     0x400FE000  
#define DMA_BASE                0x400FF000  
#define BITBAND_ALIAS_BASE      0x42000000  
#define MMCHS_BASE              0x44010000  
#define CAMERA_BASE             0x44018000  
#define MCASPA0_BASE            0x4401C000  
#define MCSPIS0_BASE            0x44020000  
#define MCSPIA1_BASE            0x44021000  
#define MCSPIA2_BASE            0x44022000  
#define APPS_RCM_BASE           0x44025000  
#define APPS_CONFIG_BASE        0x44026000  
#define OCP_GPRCM_BASE          0x4402D000  
#define OCP_SHARED_BASE         0x4402E000  
#define TOP_ADC_BASE            0x4402E800  
#define OCLA_BASE               0x4402EC00  
#define OCP_HIB1P2_BASE         0x4402F000  
#define OCP_HIB3P3_BASE         0x4402F800  
#define DTHE_BASE               0x44030000  
#define SHAMD5_BASE             0x44035000  
#define AES_BASE                0x44037000  
#define DES_BASE                0x44039000  
#define EPI_MEM_BASE            0x60000000  
#define FLASH_MEM_BASE          0x01000000  
#define OTP_BANK0_BASE          0x03000000  
#define OTP_BANK1_BASE          0x03002000  
#define OTP_BANK2_BASE          0x03004000  
#define OTP_BANK3_BASE          0x03006000  
#define OTP_BANK4_BASE          0x03008000  
#define TIOTP_BANK0_BASE        0x03020000  
#define TIOTP_BANK1_BASE        0x03022000  
#define TIOTP_BANK2_BASE        0x03024000  
#define TIOTP_BANK3_BASE        0x03026000  
#define TIOTP_BANK4_BASE        0x03028000  
#define EEPROM_ROM_BASE         0x03040000  
#define APP_SRAM_BASE           0x20000000  
#define SRAM_TOP_DIE_BASE       0x25000000  


#endif // __HW_MEMMAP_H__
