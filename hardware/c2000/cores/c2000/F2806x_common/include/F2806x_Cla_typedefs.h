//###########################################################################
//
// FILE:   F2806x_Cla_typedefs.h
//
// TITLE:  Variable type definitions
//
//###########################################################################
// $TI Release: $
// $Release Date:  $
//###########################################################################


#ifndef F2806X_CLA_TYPEDEFS_H_
#define F2806X_CLA_TYPEDEFS_H_

//---------------------------------------------------------------------------
// For Portability, User Is Recommended To Use Following Data Type Size
// Definitions For 16-bit and 32-Bit Signed/Unsigned Integers:
//
// CLA does not support 64-bit types
// This definition is only to allow inclusion of the standard header files
// which do use 64-bit types
//
#ifndef DSP28_DATA_TYPES
#define DSP28_DATA_TYPES
typedef short           int16;
typedef long            int32;
typedef unsigned char   Uint8;
typedef unsigned short  Uint16;
typedef unsigned long   Uint32;
typedef float           float32;
typedef long double     float64;
#endif

#ifndef _TI_STD_TYPES
#define _TI_STD_TYPES
/*
 * These types are also defined in DSP/BIOS 5.x's <std.h> and the
 * SYS/BIOS 6.x's <xdc/std.h> files.  We need to protect their
 * definition with the #ifndef/#define guard to avoid the duplicate
 * definition warning.
 *
 * SYS/BIOS requires that the <xdc/std.h> file be included before
 * any other .h files.
 */
#endif

// Suppress warnings casting CLA pointers
#pragma diag_suppress 70,770,232

// Macros to manipulate pre-processor to generate a header file name
// at compile time that is based on the test name and can be used as
// an argument to #include

#define XSTRINGIZE(s) STRINGIZE(s)
#define STRINGIZE(s) #s
#define XCONCAT(x,y) CONCAT(x,y)
#define CONCAT(x,y) x##y

#ifdef __TMS320C28XX_CLA0__
struct MSTF_SHADOW_BITS {     // bits description
    Uint16  LVF:1;          // 0    Latched Overflow Flag
    Uint16  LUF:1;          // 1    Latched Underflow Flag
    Uint16  NF:1;           // 2    Negative Float Flag
    Uint16  ZF:1;           // 3    Zero Float Flag
    Uint16  rsvd1:2;        // 5:4  Reserved
    Uint16  TF:1;           // 6    Test Flag
    Uint16  rsvd2:2;        // 8:7  Reserved
    Uint16  RNDF32:1;       // 9    Rounding Mode
    Uint16  rsvd3:1;        // 10   Reserved
    Uint16  MEALLOW:1;      // 11   MEALLOW Status
    Uint16  RPCL:4;         // 15:12    Return PC: Low Portion
    Uint16  RPCH:8;         // 23:16    Return PC: High Portion
    Uint16  rsvd4:8;        // 31:24    Reserved
};
extern __cregister volatile unsigned int MSTF;
#endif //__TMS320C28XX_CLA0__

#ifdef __TMS320C28XX_CLA0__
typedef struct { Uint32 low32; Uint32 high32; } Uint64;
#else
typedef unsigned long long Uint64;
#endif


#ifndef  __TMS320C28XX__
#define __cregister
#endif  //__TMS320C28xx__

#endif /*F2806X_CLA_TYPEDEFS_H_*/
