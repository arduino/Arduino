// TI File $Revision: /main/9 $
// Checkin $Date: October 6, 2010   14:43:25 $
//###########################################################################
//
// FILE:   F2802x_Device.h
//
// TITLE:  F2802x Device Definitions.
//
//###########################################################################
// $TI Release: f2802x Support Library v210 $
// $Release Date: Mon Sep 17 09:13:31 CDT 2012 $
//###########################################################################

#ifndef F2802x_DEVICE_H
#define F2802x_DEVICE_H

#define DSP2802x_DEVICE_H 1

#ifdef __cplusplus
extern "C" {
#endif

#define   TARGET   1
//---------------------------------------------------------------------------
// User To Select Target Device:

#define   DSP28_280200PT  0
#define   DSP28_280200DA  0

#define   DSP28_28020PT   0
#define   DSP28_28020DA   0

#define   DSP28_28021PT   0
#define   DSP28_28021DA   0

#define   DSP28_28022PT   0
#define   DSP28_28022DA   0

#define   DSP28_28023PT   0
#define   DSP28_28023DA   0

#define   DSP28_28026PT   0
#define   DSP28_28026DA   0

#define   DSP28_28027PT   TARGET
#define   DSP28_28027DA   0


//---------------------------------------------------------------------------
// Common CPU Definitions:
//

extern cregister volatile unsigned int IFR;
extern cregister volatile unsigned int IER;

#define  EINT   asm(" clrc INTM")
#define  DINT   asm(" setc INTM")
#define  ERTM   asm(" clrc DBGM")
#define  DRTM   asm(" setc DBGM")
#define  EALLOW asm(" EALLOW")
#define  EDIS   asm(" EDIS")
#define  ESTOP0 asm(" ESTOP0")

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

#define BIT0    0x0001
#define BIT1    0x0002
#define BIT2    0x0004
#define BIT3    0x0008
#define BIT4    0x0010
#define BIT5    0x0020
#define BIT6    0x0040
#define BIT7    0x0080
#define BIT8    0x0100
#define BIT9    0x0200
#define BIT10   0x0400
#define BIT11   0x0800
#define BIT12   0x1000
#define BIT13   0x2000
#define BIT14   0x4000
#define BIT15   0x8000

//---------------------------------------------------------------------------
// For Portability, User Is Recommended To Use the C99 Standard integer types
//

#include <assert.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// C99 defines boolean type to be _Bool, but this doesn't match the format of
// the other standard integer types.  bool_t has been defined to fill this gap.
typedef _Bool bool_t;

// Work around for code that might accidently use uint8_t
typedef unsigned char uint8_t;
typedef char int8_t;

//---------------------------------------------------------------------------
// The following data types are included for compatability with legacy code,
// they are not recommended for use in new software.  Please use the C99
// types included above
//


#ifndef DSP28_DATA_TYPES
#define DSP28_DATA_TYPES
typedef int             int16;
typedef long            int32;
typedef unsigned int    Uint16;
typedef unsigned long   Uint32;
typedef float           float32;
typedef long double     float64;
#endif

//---------------------------------------------------------------------------
// Include All Peripheral Header Files:
//

#include "f2802x_headers/include/F2802x_Adc.h"                // ADC Registers
#include "f2802x_headers/include/F2802x_BootVars.h"           // Boot ROM Variables
#include "f2802x_headers/include/F2802x_DevEmu.h"             // Device Emulation Registers
#include "f2802x_headers/include/F2802x_Comp.h"               // Comparator Registers
#include "f2802x_headers/include/F2802x_CpuTimers.h"          // 32-bit CPU Timers
#include "f2802x_headers/include/F2802x_ECap.h"               // Enhanced Capture
#include "f2802x_headers/include/F2802x_EPwm.h"               // Enhanced PWM
#include "f2802x_headers/include/F2802x_Gpio.h"               // General Purpose I/O Registers
#include "f2802x_headers/include/F2802x_I2c.h"                // I2C Registers
#include "f2802x_headers/include/F2802x_NmiIntrupt.h"         // NMI Interrupt Registers
#include "f2802x_headers/include/F2802x_PieCtrl.h"            // PIE Control Registers
#include "f2802x_headers/include/F2802x_PieVect.h"            // PIE Vector Table
#include "f2802x_headers/include/F2802x_Spi.h"                // SPI Registers
#include "f2802x_headers/include/F2802x_Sci.h"                // SCI Registers
#include "f2802x_headers/include/F2802x_SysCtrl.h"            // System Control/Power Modes
#include "f2802x_headers/include/F2802x_XIntrupt.h"           // External Interrupts

#if (DSP28_28020PT||DSP28_28021PT||DSP28_28022PT||DSP28_28023PT||DSP28_28026PT||DSP28_28027PT)
#define DSP28_COMP1    1
#define DSP28_COMP2    1
#define DSP28_EPWM1    1
#define DSP28_EPWM2    1
#define DSP28_EPWM3    1
#define DSP28_EPWM4    1
#define DSP28_ECAP1    1
#define DSP28_SPIA     1
#define DSP28_SCIA     1
#define DSP28_I2CA     1
#endif  // end 2802x PT package

#if (DSP28_28020DA||DSP28_28021DA||DSP28_28022DA||DSP28_28023DA||DSP28_28026DA||DSP28_28027DA)
#define DSP28_COMP1    1
#define DSP28_COMP2    0
#define DSP28_EPWM1    1
#define DSP28_EPWM2    1
#define DSP28_EPWM3    1
#define DSP28_EPWM4    1
#define DSP28_ECAP1    1
#define DSP28_SPIA     1
#define DSP28_SCIA     1
#define DSP28_I2CA     1
#endif  // end 2802x DA package

#if (DSP28_280200PT)
#define DSP28_COMP1    1
#define DSP28_COMP2    1
#define DSP28_EPWM1    1
#define DSP28_EPWM2    1
#define DSP28_EPWM3    1
#define DSP28_EPWM4    1
#define DSP28_ECAP1    0
#define DSP28_SPIA     1
#define DSP28_SCIA     1
#define DSP28_I2CA     1
#endif  // end 280200 PT package

#if (DSP28_280200DA)
#define DSP28_COMP1    1
#define DSP28_COMP2    0
#define DSP28_EPWM1    1
#define DSP28_EPWM2    1
#define DSP28_EPWM3    1
#define DSP28_EPWM4    1
#define DSP28_ECAP1    0
#define DSP28_SPIA     1
#define DSP28_SCIA     1
#define DSP28_I2CA     1
#endif  // end 280200 DA package



// Timer definitions based on System Clock
// 60 MHz devices (28027/28026)
#if (DSP28_28026PT||DSP28_28026DA||DSP28_28027PT||DSP28_28027DA) 
    #define      mSec0_5          30000           // 0.5 mS
    #define      mSec0_75         45000           // 0.75 mS
    #define      mSec1            60000           // 1.0 mS
    #define      mSec2            120000          // 2.0 mS
    #define      mSec5            300000          // 5.0 mS
    #define      mSec7_5          450000          // 7.5 mS
    #define      mSec10           600000          // 10 mS
    #define      mSec20           1200000         // 20 mS
    #define      mSec50           3000000         // 50 mS
    #define      mSec75           4500000         // 75 mS
    #define      mSec100          6000000         // 100 mS
    #define      mSec200          12000000        // 200 mS
    #define      mSec500          30000000        // 500 mS
    #define      mSec750          45000000        // 750 mS
    #define      mSec1000         60000000        // 1000 mS
    #define      mSec2000         120000000       // 2000 mS
    #define      mSec5000         300000000       // 5000 mS
#endif

// 50 MHz devices (28023/28022)
#if (DSP28_28022PT||DSP28_28022DA||DSP28_28023PT||DSP28_28023DA)
    #define      mSec0_5          25000           // 0.5 mS
    #define      mSec0_75         37500           // 0.75 mS
    #define      mSec1            50000           // 1.0 mS
    #define      mSec2            100000          // 2.0 mS
    #define      mSec5            250000          // 5.0 mS
    #define      mSec7_5          375000          // 7.5 mS
    #define      mSec10           500000          // 10 mS
    #define      mSec20           1000000         // 20 mS
    #define      mSec50           2500000         // 50 mS
    #define      mSec75           3750000         // 75 mS
    #define      mSec100          5000000         // 100 mS
    #define      mSec200          10000000        // 200 mS
    #define      mSec500          25000000        // 500 mS
    #define      mSec750          37500000        // 750 mS
    #define      mSec1000         50000000        // 1000 mS
    #define      mSec2000         100000000       // 2000 mS
    #define      mSec5000         250000000       // 5000 mS
#endif

//40 MHz devices (28021/28020/280200)
#if (DSP28_280200PT||DSP28_280200DA||DSP28_28020PT||DSP28_28020DA||DSP28_28021PT ||DSP28_28021DA)
    #define      mSec0_5          20000           // 0.5 mS
    #define      mSec0_75         30000           // 0.75 mS
    #define      mSec1            40000           // 1.0 mS
    #define      mSec2            80000           // 2.0 mS
    #define      mSec5            200000          // 5.0 mS
    #define      mSec7_5          300000          // 7.5 mS
    #define      mSec10           400000          // 10 mS
    #define      mSec20           800000          // 20 mS
    #define      mSec50           2000000         // 50 mS
    #define      mSec75           3000000         // 75 mS
    #define      mSec100          4000000         // 100 mS
    #define      mSec200          8000000         // 200 mS
    #define      mSec500          20000000        // 500 mS
    #define      mSec750          30000000        // 750 mS
    #define      mSec1000         40000000        // 1000 mS
    #define      mSec2000         80000000        // 2000 mS
    #define      mSec5000         200000000       // 5000 mS
#endif

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of DSP2802x_DEVICE_H definition

//===========================================================================
// End of file.
//===========================================================================
