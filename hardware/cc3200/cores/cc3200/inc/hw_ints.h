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

//*****************************************************************************
//
// hw_ints.h - Macros that define the interrupt assignment on CC3101.
//
//*****************************************************************************

#ifndef __HW_INTS_H__
#define __HW_INTS_H__

//*****************************************************************************
//
// The following are defines for the fault assignments.
//
//*****************************************************************************
#define FAULT_NMI               2           // NMI fault
#define FAULT_HARD              3           // Hard fault
#define FAULT_MPU               4           // MPU fault
#define FAULT_BUS               5           // Bus fault
#define FAULT_USAGE             6           // Usage fault
#define FAULT_SVCALL            11          // SVCall
#define FAULT_DEBUG             12          // Debug monitor
#define FAULT_PENDSV            14          // PendSV
#define FAULT_SYSTICK           15          // System Tick

//*****************************************************************************
//
// The following are defines for the interrupt assignments.
//
//*****************************************************************************
#define INT_GPIOA0              16          // GPIO Port S0
#define INT_GPIOA1              17          // GPIO Port S1
#define INT_GPIOA2              18          // GPIO Port S2
#define INT_GPIOA3              19          // GPIO Port S3
#define INT_UARTA0              21          // UART0 Rx and Tx
#define INT_UARTA1              22          // UART1 Rx and Tx
#define INT_I2CA0               24          // I2C controller
#define INT_ADCCH0              30          // ADC Sequence 0
#define INT_ADCCH1              31          // ADC Sequence 1
#define INT_ADCCH2              32          // ADC Sequence 2
#define INT_ADCCH3              33          // ADC Sequence 3
#define INT_WDT                 34          // Watchdog Timer0
#define INT_TIMERA0A            35          // Timer 0 subtimer A
#define INT_TIMERA0B            36          // Timer 0 subtimer B
#define INT_TIMERA1A            37          // Timer 1 subtimer A
#define INT_TIMERA1B            38          // Timer 1 subtimer B
#define INT_TIMERA2A            39          // Timer 2 subtimer A
#define INT_TIMERA2B            40          // Timer 2 subtimer B
#define INT_FLASH               45          // FLASH Control
#define INT_TIMERA3A            51          // Timer 3 subtimer A
#define INT_TIMERA3B            52          // Timer 3 subtimer B
#define INT_UDMA                62          // uDMA controller
#define INT_UDMAERR             63          // uDMA Error
#define INT_SHA                 164         // SHA
#define INT_AES                 167         // AES
#define INT_DES                 169         // DES
#define INT_MMCHS               175         // SDIO
#define INT_MCASP               177         // McAPS
#define INT_CAMERA              179         // Camera
#define INT_NWPIC               187         // Interprocessor communication
#define INT_PRCM                188         // Power, Reset and Clock Module
#define INT_SSPI                191         // Shared SPI
#define INT_GSPI                192         // Generic SPI
#define INT_LSPI                193         // Link SPI

//*****************************************************************************
//
// The following are defines for the total number of interrupts.
//
//*****************************************************************************
#define NUM_INTERRUPTS          195 //The above number plus 2?


//*****************************************************************************
//
// The following are defines for the total number of priority levels.
//
//*****************************************************************************
#define NUM_PRIORITY            8
#define NUM_PRIORITY_BITS       3


#endif // __HW_INTS_H__
