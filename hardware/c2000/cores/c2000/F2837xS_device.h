//###########################################################################
//
// FILE:   F2837xS_device.h
//
// TITLE:  F2837xS Device Definitions.
//
//###########################################################################
// $TI Release: F2837xS Support Library v170 $
// $Release Date: Mon Sep 21 16:56:07 CDT 2015 $
// $Copyright: Copyright (C) 2014-2015 Texas Instruments Incorporated -
//             http://www.ti.com/ ALL RIGHTS RESERVED $
//###########################################################################

#ifndef F2837xS_DEVICE_H
#define F2837xS_DEVICE_H

#ifdef __cplusplus
extern "C" {
#endif

#define   TARGET   1

//---------------------------------------------------------------------------
// User To Select Target Device:
//
#define   F28_2837xS    TARGET

//---------------------------------------------------------------------------
// Common CPU Definitions:
//
extern __cregister volatile unsigned int IFR;
extern __cregister volatile unsigned int IER;

#define  EINT   __asm(" clrc INTM")
#define  DINT   __asm(" setc INTM")
#define  ERTM   __asm(" clrc DBGM")
#define  DRTM   __asm(" setc DBGM")
#define  EALLOW __asm(" EALLOW")
#define  EDIS   __asm(" EDIS")
#define  ESTOP0 __asm(" ESTOP0")

#define M_INT1  0x0001
#define M_INT2  0x0002
#define M_INT3  0x0004
#define M_INT4  0x0008
#define M_INT5  0x0010
#define M_INT6  0x0020
#define M_INT7  0x0040
#define M_INT8  0x0080
#define M_INT9  0x0100
#define M_INT10 0x0200
#define M_INT11 0x0400
#define M_INT12 0x0800
#define M_INT13 0x1000
#define M_INT14 0x2000
#define M_DLOG  0x4000
#define M_RTOS  0x8000

#define BIT0    0x00000001
#define BIT1    0x00000002
#define BIT2    0x00000004
#define BIT3    0x00000008
#define BIT4    0x00000010
#define BIT5    0x00000020
#define BIT6    0x00000040
#define BIT7    0x00000080
#define BIT8    0x00000100
#define BIT9    0x00000200
#define BIT10   0x00000400
#define BIT11   0x00000800
#define BIT12   0x00001000
#define BIT13   0x00002000
#define BIT14   0x00004000
#define BIT15   0x00008000
#define BIT16   0x00010000
#define BIT17   0x00020000
#define BIT18   0x00040000
#define BIT19   0x00080000
#define BIT20   0x00100000
#define BIT21   0x00200000
#define BIT22   0x00400000
#define BIT23   0x00800000
#define BIT24   0x01000000
#define BIT25   0x02000000
#define BIT26   0x04000000
#define BIT27   0x08000000
#define BIT28   0x10000000
#define BIT29   0x20000000
#define BIT30   0x40000000
#define BIT31   0x80000000

//---------------------------------------------------------------------------
// For Portability, User Is Recommended To Use the C99 Standard integer types
//
#if !defined(__TMS320C28XX_CLA__)
#include <assert.h>
#include <stdarg.h>
#endif //__TMS320C28XX_CLA__
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// C99 defines boolean type to be _Bool, but this doesn't match the format of
// the other standard integer types.  bool_t has been defined to fill this gap.
typedef _Bool bool_t;

// Work around for code that might accidently use uint8_t
typedef unsigned char uint8_t;
typedef char int8_t;

//used for a bool function return status
typedef _Bool status_t;

#ifndef SUCCESS
#define SUCCESS     true
#endif

#ifndef FAIL
#define FAIL        false
#endif

//---------------------------------------------------------------------------
// The following data types are included for compatibility with legacy code,
// they are not recommended for use in new software.  Please use the C99
// types included above
//
#ifndef DSP28_DATA_TYPES
#define DSP28_DATA_TYPES
typedef int             	int16;
typedef long            	int32;
typedef long long			int64;
typedef unsigned int    	Uint16;
typedef unsigned long   	Uint32;
typedef unsigned long long	Uint64;
typedef float           	float32;
typedef long double     	float64;
#endif


//---------------------------------------------------------------------------
// Include All Peripheral Header Files:
//
#include "F2837xS_headers/include/F2837xS_adc.h"
#include "F2837xS_headers/include/F2837xS_analogsubsys.h"
#include "F2837xS_headers/include/F2837xS_cla.h"
#include "F2837xS_headers/include/F2837xS_cmpss.h"
#include "F2837xS_headers/include/F2837xS_cputimer.h"
#include "F2837xS_headers/include/F2837xS_dac.h"
#include "F2837xS_headers/include/F2837xS_dcsm.h"
#include "F2837xS_headers/include/F2837xS_dma.h"
#include "F2837xS_headers/include/F2837xS_ecap.h"
#include "F2837xS_headers/include/F2837xS_emif.h"
#include "F2837xS_headers/include/F2837xS_epwm.h"                // Enhanced PWM
#include "F2837xS_headers/include/F2837xS_epwm_xbar.h"
#include "F2837xS_headers/include/F2837xS_eqep.h"
#include "F2837xS_headers/include/F2837xS_flash.h"
#include "F2837xS_headers/include/F2837xS_gpio.h"                // General Purpose I/O Registers
#include "F2837xS_headers/include/F2837xS_i2c.h"
#include "F2837xS_headers/include/F2837xS_input_xbar.h"
#include "F2837xS_headers/include/F2837xS_mcbsp.h"
#include "F2837xS_headers/include/F2837xS_memconfig.h"
#include "F2837xS_headers/include/F2837xS_nmiintrupt.h"          // NMI Interrupt Registers
#include "F2837xS_headers/include/F2837xS_output_xbar.h"
#include "F2837xS_headers/include/F2837xS_piectrl.h"             // PIE Control Registers
#include "F2837xS_headers/include/F2837xS_pievect.h"
#include "F2837xS_headers/include/F2837xS_sci.h"
#include "F2837xS_headers/include/F2837xS_sdfm.h"
#include "F2837xS_headers/include/F2837xS_spi.h"
#include "F2837xS_headers/include/F2837xS_sysctrl.h"             // System Control/Power Modes
#include "F2837xS_headers/include/F2837xS_upp.h"
#include "F2837xS_headers/include/F2837xS_xbar.h"
#include "F2837xS_headers/include/F2837xS_xint.h"                // External Interrupts

#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif                                  // end of F2837xS_DEVICE_H definition

//===========================================================================
// End of file.
//===========================================================================
