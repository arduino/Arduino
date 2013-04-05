// TI File $Revision: /main/1 $
// Checkin $Date: August 14, 2008   17:02:22 $
//###########################################################################
//
// FILE:    IQmathLib.h
//
// TITLE:   IQ Math library functions definitions.
//
//###########################################################################
//
// Ver  | dd-mmm-yyyy |  Who  | Description of changes
// =====|=============|=======|==============================================
//  1.3 | 19 Nov 2001 | A. T. | Original Release.
// -----|-------------|-------|----------------------------------------------
//  1.4 | 17 May 2002 | A. T. | Added new functions and support for
//      |             |       | intrinsics IQmpy, IQxmpy, IQsat.
// -----|-------------|-------|----------------------------------------------
//  1.4a| 12 Jun 2002 | A. T. | Fixed problem with _IQ() operation on
//      |             |       | variables.
// -----|-------------|-------|----------------------------------------------
//  1.4b| 18 Jun 2002 | A. T. | Fixed bug with _IQtoIQN() and _IQNtoIQ()
//      |             |       | operations.
// -----|-------------|-------|----------------------------------------------
//  1.4d| 30 Mar 2003 | DA/SD | 1. Added macro parameters in parentheses
//      |             |       |    in number of places where it matters
//      |             |       | 2. Added macro definition to include header
//      |             |       |    file multiple times in the program.
// -----|-------------|-------|----------------------------------------------
//  1.4e| 17 Jun 2004 | AT/DA | Added IQexp function.
//      |             |       | Added IQasin & IQacos functions (thanks DA).
// -----|-------------|-------|----------------------------------------------
//  1.4f| 10 Mar 2005 | AT    | Fixed Bug In IQexp function.
// -----|-------------|-------|----------------------------------------------
//  1.5 | 30 Jan 2008 | LH    | 1. Changed the definion of the _IQatan2PU(A,B)
//      |             |       |    macro for FLOAT_MATH so that a call to
//      |             |       |    divide will not occur.
//      |             |       | 2. If MATH_TYPE == FLOAT_MATH, then include the
//      |             |       |    following standard headers: math.h
//      |             |       |    stdlib.h.
//      |             |       | 3. Added missing #defines for the non-global
//      |             |       |    _IQatanN() function
//      |             |       | 4. Adding missing definitions for absolute
//      |             |       |    value when MATH_TYPE == FLOAT_MATH
//      |             |       | 5. Included limits.h and changed the definition
//      |             |       |    of MAX_IQ_NEG to LONG_MIN and MAX_IQ_POS
//      |             |       |    to LONG_MAX
//###########################################################################
// $TI Release: f2802x Support Library v210 $
// $Release Date: Mon Sep 17 09:13:31 CDT 2012 $
//###########################################################################
//
// User needs to configure "MATH_TYPE" and "GLOBAL_Q" values:
//
//---------------------------------------------------------------------------
// Select math type, IQ_MATH or FLOAT_MATH:
//

#ifndef __IQMATHLIB_H_INCLUDED__
#define __IQMATHLIB_H_INCLUDED__


#define   FLOAT_MATH     1
#define   IQ_MATH        0

#ifndef   MATH_TYPE
#define   MATH_TYPE      IQ_MATH
#endif

//---------------------------------------------------------------------------
// Select global Q value and scaling. The Q value is limited to the
// following range for all functions:
//
//        30 <= GLOBAL_Q <=  1
//
#ifndef   GLOBAL_Q
#define   GLOBAL_Q       24
#endif

//---------------------------------------------------------------------------
// If using FLOAT_MATH, include standard headers to avoid conversion issues
//
#if MATH_TYPE == FLOAT_MATH
#include <math.h>
#include <stdlib.h>
#endif
#include <limits.h>

//---------------------------------------------------------------------------
// Various Usefull Constant Definitions:
//
#define   QG          GLOBAL_Q
#define   Q30         30
#define   Q29         29
#define   Q28         28
#define   Q27         27
#define   Q26         26
#define   Q25         25
#define   Q24         24
#define   Q23         23
#define   Q22         22
#define   Q21         21
#define   Q20         20
#define   Q19         19
#define   Q18         18
#define   Q17         17
#define   Q16         16
#define   Q15         15
#define   Q14         14
#define   Q13         13
#define   Q12         12
#define   Q11         11
#define   Q10         10
#define   Q9          9
#define   Q8          8
#define   Q7          7
#define   Q6          6
#define   Q5          5
#define   Q4          4
#define   Q3          3
#define   Q2          2
#define   Q1          1

#define   MAX_IQ_POS  LONG_MAX
#define   MAX_IQ_NEG  LONG_MIN
#define   MIN_IQ_POS  1
#define   MIN_IQ_NEG  -1

//###########################################################################
#if MATH_TYPE == IQ_MATH
//###########################################################################
// If IQ_MATH is used, the following IQmath library function definitions
// are used:
//===========================================================================
typedef   long    _iq;
typedef   long    _iq30;
typedef   long    _iq29;
typedef   long    _iq28;
typedef   long    _iq27;
typedef   long    _iq26;
typedef   long    _iq25;
typedef   long    _iq24;
typedef   long    _iq23;
typedef   long    _iq22;
typedef   long    _iq21;
typedef   long    _iq20;
typedef   long    _iq19;
typedef   long    _iq18;
typedef   long    _iq17;
typedef   long    _iq16;
typedef   long    _iq15;
typedef   long    _iq14;
typedef   long    _iq13;
typedef   long    _iq12;
typedef   long    _iq11;
typedef   long    _iq10;
typedef   long    _iq9;
typedef   long    _iq8;
typedef   long    _iq7;
typedef   long    _iq6;
typedef   long    _iq5;
typedef   long    _iq4;
typedef   long    _iq3;
typedef   long    _iq2;
typedef   long    _iq1;
//---------------------------------------------------------------------------
#define   _IQ30(A)      (long) ((A) * 1073741824.0L)
#define   _IQ29(A)      (long) ((A) * 536870912.0L)
#define   _IQ28(A)      (long) ((A) * 268435456.0L)
#define   _IQ27(A)      (long) ((A) * 134217728.0L)
#define   _IQ26(A)      (long) ((A) * 67108864.0L)
#define   _IQ25(A)      (long) ((A) * 33554432.0L)
#define   _IQ24(A)      (long) ((A) * 16777216.0L)
#define   _IQ23(A)      (long) ((A) * 8388608.0L)
#define   _IQ22(A)      (long) ((A) * 4194304.0L)
#define   _IQ21(A)      (long) ((A) * 2097152.0L)
#define   _IQ20(A)      (long) ((A) * 1048576.0L)
#define   _IQ19(A)      (long) ((A) * 524288.0L)
#define   _IQ18(A)      (long) ((A) * 262144.0L)
#define   _IQ17(A)      (long) ((A) * 131072.0L)
#define   _IQ16(A)      (long) ((A) * 65536.0L)
#define   _IQ15(A)      (long) ((A) * 32768.0L)
#define   _IQ14(A)      (long) ((A) * 16384.0L)
#define   _IQ13(A)      (long) ((A) * 8192.0L)
#define   _IQ12(A)      (long) ((A) * 4096.0L)
#define   _IQ11(A)      (long) ((A) * 2048.0L)
#define   _IQ10(A)      (long) ((A) * 1024.0L)
#define   _IQ9(A)       (long) ((A) * 512.0L)
#define   _IQ8(A)       (long) ((A) * 256.0L)
#define   _IQ7(A)       (long) ((A) * 128.0L)
#define   _IQ6(A)       (long) ((A) * 64.0L)
#define   _IQ5(A)       (long) ((A) * 32.0L)
#define   _IQ4(A)       (long) ((A) * 16.0L)
#define   _IQ3(A)       (long) ((A) * 8.0L)
#define   _IQ2(A)       (long) ((A) * 4.0L)
#define   _IQ1(A)       (long) ((A) * 2.0L)

#if GLOBAL_Q == 30
#define   _IQ(A)  _IQ30(A)
#endif
#if GLOBAL_Q == 29
#define   _IQ(A)  _IQ29(A)
#endif
#if GLOBAL_Q == 28
#define   _IQ(A)  _IQ28(A)
#endif
#if GLOBAL_Q == 27
#define   _IQ(A)  _IQ27(A)
#endif
#if GLOBAL_Q == 26
#define   _IQ(A)  _IQ26(A)
#endif
#if GLOBAL_Q == 25
#define   _IQ(A)  _IQ25(A)
#endif
#if GLOBAL_Q == 24
#define   _IQ(A)  _IQ24(A)
#endif
#if GLOBAL_Q == 23
#define   _IQ(A)  _IQ23(A)
#endif
#if GLOBAL_Q == 22
#define   _IQ(A)  _IQ22(A)
#endif
#if GLOBAL_Q == 21
#define   _IQ(A)  _IQ21(A)
#endif
#if GLOBAL_Q == 20
#define   _IQ(A)  _IQ20(A)
#endif
#if GLOBAL_Q == 19
#define   _IQ(A)  _IQ19(A)
#endif
#if GLOBAL_Q == 18
#define   _IQ(A)  _IQ18(A)
#endif
#if GLOBAL_Q == 17
#define   _IQ(A)  _IQ17(A)
#endif
#if GLOBAL_Q == 16
#define   _IQ(A)  _IQ16(A)
#endif
#if GLOBAL_Q == 15
#define   _IQ(A)  _IQ15(A)
#endif
#if GLOBAL_Q == 14
#define   _IQ(A)  _IQ14(A)
#endif
#if GLOBAL_Q == 13
#define   _IQ(A)  _IQ13(A)
#endif
#if GLOBAL_Q == 12
#define   _IQ(A)  _IQ12(A)
#endif
#if GLOBAL_Q == 11
#define   _IQ(A)  _IQ11(A)
#endif
#if GLOBAL_Q == 10
#define   _IQ(A)  _IQ10(A)
#endif
#if GLOBAL_Q == 9
#define   _IQ(A)  _IQ9(A)
#endif
#if GLOBAL_Q == 8
#define   _IQ(A)  _IQ8(A)
#endif
#if GLOBAL_Q == 7
#define   _IQ(A)  _IQ7(A)
#endif
#if GLOBAL_Q == 6
#define   _IQ(A)  _IQ6(A)
#endif
#if GLOBAL_Q == 5
#define   _IQ(A)  _IQ5(A)
#endif
#if GLOBAL_Q == 4
#define   _IQ(A)  _IQ4(A)
#endif
#if GLOBAL_Q == 3
#define   _IQ(A)  _IQ3(A)
#endif
#if GLOBAL_Q == 2
#define   _IQ(A)  _IQ2(A)
#endif
#if GLOBAL_Q == 1
#define   _IQ(A)  _IQ1(A)
#endif
//---------------------------------------------------------------------------
extern    float _IQ30toF(long A);
extern    float _IQ29toF(long A);
extern    float _IQ28toF(long A);
extern    float _IQ27toF(long A);
extern    float _IQ26toF(long A);
extern    float _IQ25toF(long A);
extern    float _IQ24toF(long A);
extern    float _IQ23toF(long A);
extern    float _IQ22toF(long A);
extern    float _IQ21toF(long A);
extern    float _IQ20toF(long A);
extern    float _IQ19toF(long A);
extern    float _IQ18toF(long A);
extern    float _IQ17toF(long A);
extern    float _IQ16toF(long A);
extern    float _IQ15toF(long A);
extern    float _IQ14toF(long A);
extern    float _IQ13toF(long A);
extern    float _IQ12toF(long A);
extern    float _IQ11toF(long A);
extern    float _IQ10toF(long A);
extern    float _IQ9toF(long A);
extern    float _IQ8toF(long A);
extern    float _IQ7toF(long A);
extern    float _IQ6toF(long A);
extern    float _IQ5toF(long A);
extern    float _IQ4toF(long A);
extern    float _IQ3toF(long A);
extern    float _IQ2toF(long A);
extern    float _IQ1toF(long A);

#if GLOBAL_Q == 30
#define   _IQtoF(A)  _IQ30toF(A)
#endif
#if GLOBAL_Q == 29
#define   _IQtoF(A)  _IQ29toF(A)
#endif
#if GLOBAL_Q == 28
#define   _IQtoF(A)  _IQ28toF(A)
#endif
#if GLOBAL_Q == 27
#define   _IQtoF(A)  _IQ27toF(A)
#endif
#if GLOBAL_Q == 26
#define   _IQtoF(A)  _IQ26toF(A)
#endif
#if GLOBAL_Q == 25
#define   _IQtoF(A)  _IQ25toF(A)
#endif
#if GLOBAL_Q == 24
#define   _IQtoF(A)  _IQ24toF(A)
#endif
#if GLOBAL_Q == 23
#define   _IQtoF(A)  _IQ23toF(A)
#endif
#if GLOBAL_Q == 22
#define   _IQtoF(A)  _IQ22toF(A)
#endif
#if GLOBAL_Q == 21
#define   _IQtoF(A)  _IQ21toF(A)
#endif
#if GLOBAL_Q == 20
#define   _IQtoF(A)  _IQ20toF(A)
#endif
#if GLOBAL_Q == 19
#define   _IQtoF(A)  _IQ19toF(A)
#endif
#if GLOBAL_Q == 18
#define   _IQtoF(A)  _IQ18toF(A)
#endif
#if GLOBAL_Q == 17
#define   _IQtoF(A)  _IQ17toF(A)
#endif
#if GLOBAL_Q == 16
#define   _IQtoF(A)  _IQ16toF(A)
#endif
#if GLOBAL_Q == 15
#define   _IQtoF(A)  _IQ15toF(A)
#endif
#if GLOBAL_Q == 14
#define   _IQtoF(A)  _IQ14toF(A)
#endif
#if GLOBAL_Q == 13
#define   _IQtoF(A)  _IQ13toF(A)
#endif
#if GLOBAL_Q == 12
#define   _IQtoF(A)  _IQ12toF(A)
#endif
#if GLOBAL_Q == 11
#define   _IQtoF(A)  _IQ11toF(A)
#endif
#if GLOBAL_Q == 10
#define   _IQtoF(A)  _IQ10toF(A)
#endif
#if GLOBAL_Q == 9
#define   _IQtoF(A)  _IQ9toF(A)
#endif
#if GLOBAL_Q == 8
#define   _IQtoF(A)  _IQ8toF(A)
#endif
#if GLOBAL_Q == 7
#define   _IQtoF(A)  _IQ7toF(A)
#endif
#if GLOBAL_Q == 6
#define   _IQtoF(A)  _IQ6toF(A)
#endif
#if GLOBAL_Q == 5
#define   _IQtoF(A)  _IQ5toF(A)
#endif
#if GLOBAL_Q == 4
#define   _IQtoF(A)  _IQ4toF(A)
#endif
#if GLOBAL_Q == 3
#define   _IQtoF(A)  _IQ3toF(A)
#endif
#if GLOBAL_Q == 2
#define   _IQtoF(A)  _IQ2toF(A)
#endif
#if GLOBAL_Q == 1
#define   _IQtoF(A)  _IQ1toF(A)
#endif
//---------------------------------------------------------------------------
#define   _IQsat(A, Pos, Neg)  __IQsat(A, Pos, Neg)
//---------------------------------------------------------------------------
#define   _IQtoIQ30(A)  ((long) (A) << (30 - GLOBAL_Q))
#define   _IQ30toIQ(A)  ((long) (A) >> (30 - GLOBAL_Q))

#if (GLOBAL_Q >= 29)
#define   _IQtoIQ29(A) ((long) (A) >> (GLOBAL_Q - 29))
#define   _IQ29toIQ(A) ((long) (A) << (GLOBAL_Q - 29))
#else
#define   _IQtoIQ29(A) ((long) (A) << (29 - GLOBAL_Q))
#define   _IQ29toIQ(A) ((long) (A) >> (29 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 28)
#define   _IQtoIQ28(A) ((long) (A) >> (GLOBAL_Q - 28))
#define   _IQ28toIQ(A) ((long) (A) << (GLOBAL_Q - 28))
#else
#define   _IQtoIQ28(A) ((long) (A) << (28 - GLOBAL_Q))
#define   _IQ28toIQ(A) ((long) (A) >> (28 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 27)
#define   _IQtoIQ27(A) ((long) (A) >> (GLOBAL_Q - 27))
#define   _IQ27toIQ(A) ((long) (A) << (GLOBAL_Q - 27))
#else
#define   _IQtoIQ27(A) ((long) (A) << (27 - GLOBAL_Q))
#define   _IQ27toIQ(A) ((long) (A) >> (27 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 26)
#define   _IQtoIQ26(A) ((long) (A) >> (GLOBAL_Q - 26))
#define   _IQ26toIQ(A) ((long) (A) << (GLOBAL_Q - 26))
#else
#define   _IQtoIQ26(A) ((long) (A) << (26 - GLOBAL_Q))
#define   _IQ26toIQ(A) ((long) (A) >> (26 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 25)
#define   _IQtoIQ25(A) ((long) (A) >> (GLOBAL_Q - 25))
#define   _IQ25toIQ(A) ((long) (A) << (GLOBAL_Q - 25))
#else
#define   _IQtoIQ25(A) ((long) (A) << (25 - GLOBAL_Q))
#define   _IQ25toIQ(A) ((long) (A) >> (25 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 24)
#define   _IQtoIQ24(A) ((long) (A) >> (GLOBAL_Q - 24))
#define   _IQ24toIQ(A) ((long) (A) << (GLOBAL_Q - 24))
#else
#define   _IQtoIQ24(A) ((long) (A) << (24 - GLOBAL_Q))
#define   _IQ24toIQ(A) ((long) (A) >> (24 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 23)
#define   _IQtoIQ23(A) ((long) (A) >> (GLOBAL_Q - 23))
#define   _IQ23toIQ(A) ((long) (A) << (GLOBAL_Q - 23))
#else
#define   _IQtoIQ23(A) ((long) (A) << (23 - GLOBAL_Q))
#define   _IQ23toIQ(A) ((long) (A) >> (23 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 22)
#define   _IQtoIQ22(A) ((long) (A) >> (GLOBAL_Q - 22))
#define   _IQ22toIQ(A) ((long) (A) << (GLOBAL_Q - 22))
#else
#define   _IQtoIQ22(A) ((long) (A) << (22 - GLOBAL_Q))
#define   _IQ22toIQ(A) ((long) (A) >> (22 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 21)
#define   _IQtoIQ21(A) ((long) (A) >> (GLOBAL_Q - 21))
#define   _IQ21toIQ(A) ((long) (A) << (GLOBAL_Q - 21))
#else
#define   _IQtoIQ21(A) ((long) (A) << (21 - GLOBAL_Q))
#define   _IQ21toIQ(A) ((long) (A) >> (21 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 20)
#define   _IQtoIQ20(A) ((long) (A) >> (GLOBAL_Q - 20))
#define   _IQ20toIQ(A) ((long) (A) << (GLOBAL_Q - 20))
#else
#define   _IQtoIQ20(A) ((long) (A) << (20 - GLOBAL_Q))
#define   _IQ20toIQ(A) ((long) (A) >> (20 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 19)
#define   _IQtoIQ19(A) ((long) (A) >> (GLOBAL_Q - 19))
#define   _IQ19toIQ(A) ((long) (A) << (GLOBAL_Q - 19))
#else
#define   _IQtoIQ19(A) ((long) (A) << (19 - GLOBAL_Q))
#define   _IQ19toIQ(A) ((long) (A) >> (19 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 18)
#define   _IQtoIQ18(A) ((long) (A) >> (GLOBAL_Q - 18))
#define   _IQ18toIQ(A) ((long) (A) << (GLOBAL_Q - 18))
#else
#define   _IQtoIQ18(A) ((long) (A) << (18 - GLOBAL_Q))
#define   _IQ18toIQ(A) ((long) (A) >> (18 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 17)
#define   _IQtoIQ17(A) ((long) (A) >> (GLOBAL_Q - 17))
#define   _IQ17toIQ(A) ((long) (A) << (GLOBAL_Q - 17))
#else
#define   _IQtoIQ17(A) ((long) (A) << (17 - GLOBAL_Q))
#define   _IQ17toIQ(A) ((long) (A) >> (17 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 16)
#define   _IQtoIQ16(A) ((long) (A) >> (GLOBAL_Q - 16))
#define   _IQ16toIQ(A) ((long) (A) << (GLOBAL_Q - 16))
#else
#define   _IQtoIQ16(A) ((long) (A) << (16 - GLOBAL_Q))
#define   _IQ16toIQ(A) ((long) (A) >> (16 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 15)
#define   _IQtoIQ15(A) ((long) (A) >> (GLOBAL_Q - 15))
#define   _IQ15toIQ(A) ((long) (A) << (GLOBAL_Q - 15))
#define   _IQtoQ15(A)  ((long) (A) >> (GLOBAL_Q - 15))
#define   _Q15toIQ(A)  ((long) (A) << (GLOBAL_Q - 15))
#else
#define   _IQtoIQ15(A) ((long) (A) << (15 - GLOBAL_Q))
#define   _IQ15toIQ(A) ((long) (A) >> (15 - GLOBAL_Q))
#define   _IQtoQ15(A)  ((long) (A) << (15 - GLOBAL_Q))
#define   _Q15toIQ(A)  ((long) (A) >> (15 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 14)
#define   _IQtoIQ14(A) ((long) (A) >> (GLOBAL_Q - 14))
#define   _IQ14toIQ(A) ((long) (A) << (GLOBAL_Q - 14))
#define   _IQtoQ14(A)  ((long) (A) >> (GLOBAL_Q - 14))
#define   _Q14toIQ(A)  ((long) (A) << (GLOBAL_Q - 14))
#else
#define   _IQtoIQ14(A) ((long) (A) << (14 - GLOBAL_Q))
#define   _IQ14toIQ(A) ((long) (A) >> (14 - GLOBAL_Q))
#define   _IQtoQ14(A)  ((long) (A) << (14 - GLOBAL_Q))
#define   _Q14toIQ(A)  ((long) (A) >> (14 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 13)
#define   _IQtoIQ13(A) ((long) (A) >> (GLOBAL_Q - 13))
#define   _IQ13toIQ(A) ((long) (A) << (GLOBAL_Q - 13))
#define   _IQtoQ13(A)  ((long) (A) >> (GLOBAL_Q - 13))
#define   _Q13toIQ(A)  ((long) (A) << (GLOBAL_Q - 13))
#else
#define   _IQtoIQ13(A) ((long) (A) << (13 - GLOBAL_Q))
#define   _IQ13toIQ(A) ((long) (A) >> (13 - GLOBAL_Q))
#define   _IQtoQ13(A)  ((long) (A) << (13 - GLOBAL_Q))
#define   _Q13toIQ(A)  ((long) (A) >> (13 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 12)
#define   _IQtoIQ12(A) ((long) (A) >> (GLOBAL_Q - 12))
#define   _IQ12toIQ(A) ((long) (A) << (GLOBAL_Q - 12))
#define   _IQtoQ12(A)  ((long) (A) >> (GLOBAL_Q - 12))
#define   _Q12toIQ(A)  ((long) (A) << (GLOBAL_Q - 12))
#else
#define   _IQtoIQ12(A) ((long) (A) << (12 - GLOBAL_Q))
#define   _IQ12toIQ(A) ((long) (A) >> (12 - GLOBAL_Q))
#define   _IQtoQ12(A)  ((long) (A) << (12 - GLOBAL_Q))
#define   _Q12toIQ(A)  ((long) (A) >> (12 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 11)
#define   _IQtoIQ11(A) ((long) (A) >> (GLOBAL_Q - 11))
#define   _IQ11toIQ(A) ((long) (A) << (GLOBAL_Q - 11))
#define   _IQtoQ11(A)  ((long) (A) >> (GLOBAL_Q - 11))
#define   _Q11toIQ(A)  ((long) (A) << (GLOBAL_Q - 11))
#else
#define   _IQtoIQ11(A) ((long) (A) << (11 - GLOBAL_Q))
#define   _IQ11toIQ(A) ((long) (A) >> (11 - GLOBAL_Q))
#define   _IQtoQ11(A)  ((long) (A) << (11 - GLOBAL_Q))
#define   _Q11toIQ(A)  ((long) (A) >> (11 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 10)
#define   _IQtoIQ10(A) ((long) (A) >> (GLOBAL_Q - 10))
#define   _IQ10toIQ(A) ((long) (A) << (GLOBAL_Q - 10))
#define   _IQtoQ10(A)  ((long) (A) >> (GLOBAL_Q - 10))
#define   _Q10toIQ(A)  ((long) (A) << (GLOBAL_Q - 10))
#else
#define   _IQtoIQ10(A) ((long) (A) << (10 - GLOBAL_Q))
#define   _IQ10toIQ(A) ((long) (A) >> (10 - GLOBAL_Q))
#define   _IQtoQ10(A)  ((long) (A) << (10 - GLOBAL_Q))
#define   _Q10toIQ(A)  ((long) (A) >> (10 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 9)
#define   _IQtoIQ9(A) ((long) (A) >> (GLOBAL_Q - 9))
#define   _IQ9toIQ(A) ((long) (A) << (GLOBAL_Q - 9))
#define   _IQtoQ9(A)  ((long) (A) >> (GLOBAL_Q - 9))
#define   _Q9toIQ(A)  ((long) (A) << (GLOBAL_Q - 9))
#else
#define   _IQtoIQ9(A) ((long) (A) << (9 - GLOBAL_Q))
#define   _IQ9toIQ(A) ((long) (A) >> (9 - GLOBAL_Q))
#define   _IQtoQ9(A)  ((long) (A) << (9 - GLOBAL_Q))
#define   _Q9toIQ(A)  ((long) (A) >> (9 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 8)
#define   _IQtoIQ8(A) ((long) (A) >> (GLOBAL_Q - 8))
#define   _IQ8toIQ(A) ((long) (A) << (GLOBAL_Q - 8))
#define   _IQtoQ8(A)  ((long) (A) >> (GLOBAL_Q - 8))
#define   _Q8toIQ(A)  ((long) (A) << (GLOBAL_Q - 8))
#else
#define   _IQtoIQ8(A) ((long) (A) << (8 - GLOBAL_Q))
#define   _IQ8toIQ(A) ((long) (A) >> (8 - GLOBAL_Q))
#define   _IQtoQ8(A)  ((long) (A) << (8 - GLOBAL_Q))
#define   _Q8toIQ(A)  ((long) (A) >> (8 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 7)
#define   _IQtoIQ7(A) ((long) (A) >> (GLOBAL_Q - 7))
#define   _IQ7toIQ(A) ((long) (A) << (GLOBAL_Q - 7))
#define   _IQtoQ7(A)  ((long) (A) >> (GLOBAL_Q - 7))
#define   _Q7toIQ(A)  ((long) (A) << (GLOBAL_Q - 7))
#else
#define   _IQtoIQ7(A) ((long) (A) << (7 - GLOBAL_Q))
#define   _IQ7toIQ(A) ((long) (A) >> (7 - GLOBAL_Q))
#define   _IQtoQ7(A)  ((long) (A) << (7 - GLOBAL_Q))
#define   _Q7toIQ(A)  ((long) (A) >> (7 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 6)
#define   _IQtoIQ6(A) ((long) (A) >> (GLOBAL_Q - 6))
#define   _IQ6toIQ(A) ((long) (A) << (GLOBAL_Q - 6))
#define   _IQtoQ6(A)  ((long) (A) >> (GLOBAL_Q - 6))
#define   _Q6toIQ(A)  ((long) (A) << (GLOBAL_Q - 6))
#else
#define   _IQtoIQ6(A) ((long) (A) << (6 - GLOBAL_Q))
#define   _IQ6toIQ(A) ((long) (A) >> (6 - GLOBAL_Q))
#define   _IQtoQ6(A)  ((long) (A) << (6 - GLOBAL_Q))
#define   _Q6toIQ(A)  ((long) (A) >> (6 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 5)
#define   _IQtoIQ5(A) ((long) (A) >> (GLOBAL_Q - 5))
#define   _IQ5toIQ(A) ((long) (A) << (GLOBAL_Q - 5))
#define   _IQtoQ5(A)  ((long) (A) >> (GLOBAL_Q - 5))
#define   _Q5toIQ(A)  ((long) (A) << (GLOBAL_Q - 5))
#else
#define   _IQtoIQ5(A) ((long) (A) << (5 - GLOBAL_Q))
#define   _IQ5toIQ(A) ((long) (A) >> (5 - GLOBAL_Q))
#define   _IQtoQ5(A)  ((long) (A) << (5 - GLOBAL_Q))
#define   _Q5toIQ(A)  ((long) (A) >> (5 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 4)
#define   _IQtoIQ4(A) ((long) (A) >> (GLOBAL_Q - 4))
#define   _IQ4toIQ(A) ((long) (A) << (GLOBAL_Q - 4))
#define   _IQtoQ4(A)  ((long) (A) >> (GLOBAL_Q - 4))
#define   _Q4toIQ(A)  ((long) (A) << (GLOBAL_Q - 4))
#else
#define   _IQtoIQ4(A) ((long) (A) << (4 - GLOBAL_Q))
#define   _IQ4toIQ(A) ((long) (A) >> (4 - GLOBAL_Q))
#define   _IQtoQ4(A)  ((long) (A) << (4 - GLOBAL_Q))
#define   _Q4toIQ(A)  ((long) (A) >> (4 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 3)
#define   _IQtoIQ3(A) ((long) (A) >> (GLOBAL_Q - 3))
#define   _IQ3toIQ(A) ((long) (A) << (GLOBAL_Q - 3))
#define   _IQtoQ3(A)  ((long) (A) >> (GLOBAL_Q - 3))
#define   _Q3toIQ(A)  ((long) (A) << (GLOBAL_Q - 3))
#else
#define   _IQtoIQ3(A) ((long) (A) << (3 - GLOBAL_Q))
#define   _IQ3toIQ(A) ((long) (A) >> (3 - GLOBAL_Q))
#define   _IQtoQ3(A)  ((long) (A) << (3 - GLOBAL_Q))
#define   _Q3toIQ(A)  ((long) (A) >> (3 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 2)
#define   _IQtoIQ2(A) ((long) (A) >> (GLOBAL_Q - 2))
#define   _IQ2toIQ(A) ((long) (A) << (GLOBAL_Q - 2))
#define   _IQtoQ2(A)  ((long) (A) >> (GLOBAL_Q - 2))
#define   _Q2toIQ(A)  ((long) (A) << (GLOBAL_Q - 2))
#else
#define   _IQtoIQ2(A) ((long) (A) << (2 - GLOBAL_Q))
#define   _IQ2toIQ(A) ((long) (A) >> (2 - GLOBAL_Q))
#define   _IQtoQ2(A)  ((long) (A) << (2 - GLOBAL_Q))
#define   _Q2toIQ(A)  ((long) (A) >> (2 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 1)
#define   _IQtoQ1(A)  ((long) (A) >> (GLOBAL_Q - 1))
#define   _Q1toIQ(A)  ((long) (A) << (GLOBAL_Q - 1))
#else
#define   _IQtoQ1(A)  ((long) (A) << (1 - GLOBAL_Q))
#define   _Q1toIQ(A)  ((long) (A) >> (1 - GLOBAL_Q))
#endif

#define   _IQtoIQ1(A)   ((long) (A) >> (GLOBAL_Q - 1))
#define   _IQ1toIQ(A)   ((long) (A) << (GLOBAL_Q - 1))
//---------------------------------------------------------------------------
#define   _IQmpy(A,B)    __IQmpy(A,B,GLOBAL_Q)
#define   _IQ30mpy(A,B)  __IQmpy(A,B,30)
#define   _IQ29mpy(A,B)  __IQmpy(A,B,29)
#define   _IQ28mpy(A,B)  __IQmpy(A,B,28)
#define   _IQ27mpy(A,B)  __IQmpy(A,B,27)
#define   _IQ26mpy(A,B)  __IQmpy(A,B,26)
#define   _IQ25mpy(A,B)  __IQmpy(A,B,25)
#define   _IQ24mpy(A,B)  __IQmpy(A,B,24)
#define   _IQ23mpy(A,B)  __IQmpy(A,B,23)
#define   _IQ22mpy(A,B)  __IQmpy(A,B,22)
#define   _IQ21mpy(A,B)  __IQmpy(A,B,21)
#define   _IQ20mpy(A,B)  __IQmpy(A,B,20)
#define   _IQ19mpy(A,B)  __IQmpy(A,B,19)
#define   _IQ18mpy(A,B)  __IQmpy(A,B,18)
#define   _IQ17mpy(A,B)  __IQmpy(A,B,17)
#define   _IQ16mpy(A,B)  __IQmpy(A,B,16)
#define   _IQ15mpy(A,B)  __IQmpy(A,B,15)
#define   _IQ14mpy(A,B)  __IQmpy(A,B,14)
#define   _IQ13mpy(A,B)  __IQmpy(A,B,13)
#define   _IQ12mpy(A,B)  __IQmpy(A,B,12)
#define   _IQ11mpy(A,B)  __IQmpy(A,B,11)
#define   _IQ10mpy(A,B)  __IQmpy(A,B,10)
#define   _IQ9mpy(A,B)   __IQmpy(A,B,9)
#define   _IQ8mpy(A,B)   __IQmpy(A,B,8)
#define   _IQ7mpy(A,B)   __IQmpy(A,B,7)
#define   _IQ6mpy(A,B)   __IQmpy(A,B,6)
#define   _IQ5mpy(A,B)   __IQmpy(A,B,5)
#define   _IQ4mpy(A,B)   __IQmpy(A,B,4)
#define   _IQ3mpy(A,B)   __IQmpy(A,B,3)
#define   _IQ2mpy(A,B)   __IQmpy(A,B,2)
#define   _IQ1mpy(A,B)   __IQmpy(A,B,1)
//---------------------------------------------------------------------------
extern    long _IQ30rmpy(long A, long B);
extern    long _IQ29rmpy(long A, long B);
extern    long _IQ28rmpy(long A, long B);
extern    long _IQ27rmpy(long A, long B);
extern    long _IQ26rmpy(long A, long B);
extern    long _IQ25rmpy(long A, long B);
extern    long _IQ24rmpy(long A, long B);
extern    long _IQ23rmpy(long A, long B);
extern    long _IQ22rmpy(long A, long B);
extern    long _IQ21rmpy(long A, long B);
extern    long _IQ20rmpy(long A, long B);
extern    long _IQ19rmpy(long A, long B);
extern    long _IQ18rmpy(long A, long B);
extern    long _IQ17rmpy(long A, long B);
extern    long _IQ16rmpy(long A, long B);
extern    long _IQ15rmpy(long A, long B);
extern    long _IQ14rmpy(long A, long B);
extern    long _IQ13rmpy(long A, long B);
extern    long _IQ12rmpy(long A, long B);
extern    long _IQ11rmpy(long A, long B);
extern    long _IQ10rmpy(long A, long B);
extern    long _IQ9rmpy(long A, long B);
extern    long _IQ8rmpy(long A, long B);
extern    long _IQ7rmpy(long A, long B);
extern    long _IQ6rmpy(long A, long B);
extern    long _IQ5rmpy(long A, long B);
extern    long _IQ4rmpy(long A, long B);
extern    long _IQ3rmpy(long A, long B);
extern    long _IQ2rmpy(long A, long B);
extern    long _IQ1rmpy(long A, long B);

#if GLOBAL_Q == 30
#define   _IQrmpy(A,B)  _IQ30rmpy(A,B)
#endif
#if GLOBAL_Q == 29
#define   _IQrmpy(A,B)  _IQ29rmpy(A,B)
#endif
#if GLOBAL_Q == 28
#define   _IQrmpy(A,B)  _IQ28rmpy(A,B)
#endif
#if GLOBAL_Q == 27
#define   _IQrmpy(A,B)  _IQ27rmpy(A,B)
#endif
#if GLOBAL_Q == 26
#define   _IQrmpy(A,B)  _IQ26rmpy(A,B)
#endif
#if GLOBAL_Q == 25
#define   _IQrmpy(A,B)  _IQ25rmpy(A,B)
#endif
#if GLOBAL_Q == 24
#define   _IQrmpy(A,B)  _IQ24rmpy(A,B)
#endif
#if GLOBAL_Q == 23
#define   _IQrmpy(A,B)  _IQ23rmpy(A,B)
#endif
#if GLOBAL_Q == 22
#define   _IQrmpy(A,B)  _IQ22rmpy(A,B)
#endif
#if GLOBAL_Q == 21
#define   _IQrmpy(A,B)  _IQ21rmpy(A,B)
#endif
#if GLOBAL_Q == 20
#define   _IQrmpy(A,B)  _IQ20rmpy(A,B)
#endif
#if GLOBAL_Q == 19
#define   _IQrmpy(A,B)  _IQ19rmpy(A,B)
#endif
#if GLOBAL_Q == 18
#define   _IQrmpy(A,B)  _IQ18rmpy(A,B)
#endif
#if GLOBAL_Q == 17
#define   _IQrmpy(A,B)  _IQ17rmpy(A,B)
#endif
#if GLOBAL_Q == 16
#define   _IQrmpy(A,B)  _IQ16rmpy(A,B)
#endif
#if GLOBAL_Q == 15
#define   _IQrmpy(A,B)  _IQ15rmpy(A,B)
#endif
#if GLOBAL_Q == 14
#define   _IQrmpy(A,B)  _IQ14rmpy(A,B)
#endif
#if GLOBAL_Q == 13
#define   _IQrmpy(A,B)  _IQ13rmpy(A,B)
#endif
#if GLOBAL_Q == 12
#define   _IQrmpy(A,B)  _IQ12rmpy(A,B)
#endif
#if GLOBAL_Q == 11
#define   _IQrmpy(A,B)  _IQ11rmpy(A,B)
#endif
#if GLOBAL_Q == 10
#define   _IQrmpy(A,B)  _IQ10rmpy(A,B)
#endif
#if GLOBAL_Q == 9
#define   _IQrmpy(A,B)  _IQ9rmpy(A,B)
#endif
#if GLOBAL_Q == 8
#define   _IQrmpy(A,B)  _IQ8rmpy(A,B)
#endif
#if GLOBAL_Q == 7
#define   _IQrmpy(A,B)  _IQ7rmpy(A,B)
#endif
#if GLOBAL_Q == 6
#define   _IQrmpy(A,B)  _IQ6rmpy(A,B)
#endif
#if GLOBAL_Q == 5
#define   _IQrmpy(A,B)  _IQ5rmpy(A,B)
#endif
#if GLOBAL_Q == 4
#define   _IQrmpy(A,B)  _IQ4rmpy(A,B)
#endif
#if GLOBAL_Q == 3
#define   _IQrmpy(A,B)  _IQ3rmpy(A,B)
#endif
#if GLOBAL_Q == 2
#define   _IQrmpy(A,B)  _IQ2rmpy(A,B)
#endif
#if GLOBAL_Q == 1
#define   _IQrmpy(A,B)  _IQ1rmpy(A,B)
#endif
//---------------------------------------------------------------------------
extern    long _IQ30rsmpy(long A, long B);
extern    long _IQ29rsmpy(long A, long B);
extern    long _IQ28rsmpy(long A, long B);
extern    long _IQ27rsmpy(long A, long B);
extern    long _IQ26rsmpy(long A, long B);
extern    long _IQ25rsmpy(long A, long B);
extern    long _IQ24rsmpy(long A, long B);
extern    long _IQ23rsmpy(long A, long B);
extern    long _IQ22rsmpy(long A, long B);
extern    long _IQ21rsmpy(long A, long B);
extern    long _IQ20rsmpy(long A, long B);
extern    long _IQ19rsmpy(long A, long B);
extern    long _IQ18rsmpy(long A, long B);
extern    long _IQ17rsmpy(long A, long B);
extern    long _IQ16rsmpy(long A, long B);
extern    long _IQ15rsmpy(long A, long B);
extern    long _IQ14rsmpy(long A, long B);
extern    long _IQ13rsmpy(long A, long B);
extern    long _IQ12rsmpy(long A, long B);
extern    long _IQ11rsmpy(long A, long B);
extern    long _IQ10rsmpy(long A, long B);
extern    long _IQ9rsmpy(long A, long B);
extern    long _IQ8rsmpy(long A, long B);
extern    long _IQ7rsmpy(long A, long B);
extern    long _IQ6rsmpy(long A, long B);
extern    long _IQ5rsmpy(long A, long B);
extern    long _IQ4rsmpy(long A, long B);
extern    long _IQ3rsmpy(long A, long B);
extern    long _IQ2rsmpy(long A, long B);
extern    long _IQ1rsmpy(long A, long B);

#if GLOBAL_Q == 30
#define   _IQrsmpy(A,B)  _IQ30rsmpy(A,B)
#endif
#if GLOBAL_Q == 29
#define   _IQrsmpy(A,B)  _IQ29rsmpy(A,B)
#endif
#if GLOBAL_Q == 28
#define   _IQrsmpy(A,B)  _IQ28rsmpy(A,B)
#endif
#if GLOBAL_Q == 27
#define   _IQrsmpy(A,B)  _IQ27rsmpy(A,B)
#endif
#if GLOBAL_Q == 26
#define   _IQrsmpy(A,B)  _IQ26rsmpy(A,B)
#endif
#if GLOBAL_Q == 25
#define   _IQrsmpy(A,B)  _IQ25rsmpy(A,B)
#endif
#if GLOBAL_Q == 24
#define   _IQrsmpy(A,B)  _IQ24rsmpy(A,B)
#endif
#if GLOBAL_Q == 23
#define   _IQrsmpy(A,B)  _IQ23rsmpy(A,B)
#endif
#if GLOBAL_Q == 22
#define   _IQrsmpy(A,B)  _IQ22rsmpy(A,B)
#endif
#if GLOBAL_Q == 21
#define   _IQrsmpy(A,B)  _IQ21rsmpy(A,B)
#endif
#if GLOBAL_Q == 20
#define   _IQrsmpy(A,B)  _IQ20rsmpy(A,B)
#endif
#if GLOBAL_Q == 19
#define   _IQrsmpy(A,B)  _IQ19rsmpy(A,B)
#endif
#if GLOBAL_Q == 18
#define   _IQrsmpy(A,B)  _IQ18rsmpy(A,B)
#endif
#if GLOBAL_Q == 17
#define   _IQrsmpy(A,B)  _IQ17rsmpy(A,B)
#endif
#if GLOBAL_Q == 16
#define   _IQrsmpy(A,B)  _IQ16rsmpy(A,B)
#endif
#if GLOBAL_Q == 15
#define   _IQrsmpy(A,B)  _IQ15rsmpy(A,B)
#endif
#if GLOBAL_Q == 14
#define   _IQrsmpy(A,B)  _IQ14rsmpy(A,B)
#endif
#if GLOBAL_Q == 13
#define   _IQrsmpy(A,B)  _IQ13rsmpy(A,B)
#endif
#if GLOBAL_Q == 12
#define   _IQrsmpy(A,B)  _IQ12rsmpy(A,B)
#endif
#if GLOBAL_Q == 11
#define   _IQrsmpy(A,B)  _IQ11rsmpy(A,B)
#endif
#if GLOBAL_Q == 10
#define   _IQrsmpy(A,B)  _IQ10rsmpy(A,B)
#endif
#if GLOBAL_Q == 9
#define   _IQrsmpy(A,B)  _IQ9rsmpy(A,B)
#endif
#if GLOBAL_Q == 8
#define   _IQrsmpy(A,B)  _IQ8rsmpy(A,B)
#endif
#if GLOBAL_Q == 7
#define   _IQrsmpy(A,B)  _IQ7rsmpy(A,B)
#endif
#if GLOBAL_Q == 6
#define   _IQrsmpy(A,B)  _IQ6rsmpy(A,B)
#endif
#if GLOBAL_Q == 5
#define   _IQrsmpy(A,B)  _IQ5rsmpy(A,B)
#endif
#if GLOBAL_Q == 4
#define   _IQrsmpy(A,B)  _IQ4rsmpy(A,B)
#endif
#if GLOBAL_Q == 3
#define   _IQrsmpy(A,B)  _IQ3rsmpy(A,B)
#endif
#if GLOBAL_Q == 2
#define   _IQrsmpy(A,B)  _IQ2rsmpy(A,B)
#endif
#if GLOBAL_Q == 1
#define   _IQrsmpy(A,B)  _IQ1rsmpy(A,B)
#endif
//---------------------------------------------------------------------------
extern    long _IQ30div(long A, long B);
extern    long _IQ29div(long A, long B);
extern    long _IQ28div(long A, long B);
extern    long _IQ27div(long A, long B);
extern    long _IQ26div(long A, long B);
extern    long _IQ25div(long A, long B);
extern    long _IQ24div(long A, long B);
extern    long _IQ23div(long A, long B);
extern    long _IQ22div(long A, long B);
extern    long _IQ21div(long A, long B);
extern    long _IQ20div(long A, long B);
extern    long _IQ19div(long A, long B);
extern    long _IQ18div(long A, long B);
extern    long _IQ17div(long A, long B);
extern    long _IQ16div(long A, long B);
extern    long _IQ15div(long A, long B);
extern    long _IQ14div(long A, long B);
extern    long _IQ13div(long A, long B);
extern    long _IQ12div(long A, long B);
extern    long _IQ11div(long A, long B);
extern    long _IQ10div(long A, long B);
extern    long _IQ9div(long A, long B);
extern    long _IQ8div(long A, long B);
extern    long _IQ7div(long A, long B);
extern    long _IQ6div(long A, long B);
extern    long _IQ5div(long A, long B);
extern    long _IQ4div(long A, long B);
extern    long _IQ3div(long A, long B);
extern    long _IQ2div(long A, long B);
extern    long _IQ1div(long A, long B);

#if GLOBAL_Q == 30
#define   _IQdiv(A,B)  _IQ30div(A,B)
#endif
#if GLOBAL_Q == 29
#define   _IQdiv(A,B)  _IQ29div(A,B)
#endif
#if GLOBAL_Q == 28
#define   _IQdiv(A,B)  _IQ28div(A,B)
#endif
#if GLOBAL_Q == 27
#define   _IQdiv(A,B)  _IQ27div(A,B)
#endif
#if GLOBAL_Q == 26
#define   _IQdiv(A,B)  _IQ26div(A,B)
#endif
#if GLOBAL_Q == 25
#define   _IQdiv(A,B)  _IQ25div(A,B)
#endif
#if GLOBAL_Q == 24
#define   _IQdiv(A,B)  _IQ24div(A,B)
#endif
#if GLOBAL_Q == 23
#define   _IQdiv(A,B)  _IQ23div(A,B)
#endif
#if GLOBAL_Q == 22
#define   _IQdiv(A,B)  _IQ22div(A,B)
#endif
#if GLOBAL_Q == 21
#define   _IQdiv(A,B)  _IQ21div(A,B)
#endif
#if GLOBAL_Q == 20
#define   _IQdiv(A,B)  _IQ20div(A,B)
#endif
#if GLOBAL_Q == 19
#define   _IQdiv(A,B)  _IQ19div(A,B)
#endif
#if GLOBAL_Q == 18
#define   _IQdiv(A,B)  _IQ18div(A,B)
#endif
#if GLOBAL_Q == 17
#define   _IQdiv(A,B)  _IQ17div(A,B)
#endif
#if GLOBAL_Q == 16
#define   _IQdiv(A,B)  _IQ16div(A,B)
#endif
#if GLOBAL_Q == 15
#define   _IQdiv(A,B)  _IQ15div(A,B)
#endif
#if GLOBAL_Q == 14
#define   _IQdiv(A,B)  _IQ14div(A,B)
#endif
#if GLOBAL_Q == 13
#define   _IQdiv(A,B)  _IQ13div(A,B)
#endif
#if GLOBAL_Q == 12
#define   _IQdiv(A,B)  _IQ12div(A,B)
#endif
#if GLOBAL_Q == 11
#define   _IQdiv(A,B)  _IQ11div(A,B)
#endif
#if GLOBAL_Q == 10
#define   _IQdiv(A,B)  _IQ10div(A,B)
#endif
#if GLOBAL_Q == 9
#define   _IQdiv(A,B)  _IQ9div(A,B)
#endif
#if GLOBAL_Q == 8
#define   _IQdiv(A,B)  _IQ8div(A,B)
#endif
#if GLOBAL_Q == 7
#define   _IQdiv(A,B)  _IQ7div(A,B)
#endif
#if GLOBAL_Q == 6
#define   _IQdiv(A,B)  _IQ6div(A,B)
#endif
#if GLOBAL_Q == 5
#define   _IQdiv(A,B)  _IQ5div(A,B)
#endif
#if GLOBAL_Q == 4
#define   _IQdiv(A,B)  _IQ4div(A,B)
#endif
#if GLOBAL_Q == 3
#define   _IQdiv(A,B)  _IQ3div(A,B)
#endif
#if GLOBAL_Q == 2
#define   _IQdiv(A,B)  _IQ2div(A,B)
#endif
#if GLOBAL_Q == 1
#define   _IQdiv(A,B)  _IQ1div(A,B)
#endif
//---------------------------------------------------------------------------
extern    long _IQ30sin(long A);
extern    long _IQ29sin(long A);
extern    long _IQ28sin(long A);
extern    long _IQ27sin(long A);
extern    long _IQ26sin(long A);
extern    long _IQ25sin(long A);
extern    long _IQ24sin(long A);
extern    long _IQ23sin(long A);
extern    long _IQ22sin(long A);
extern    long _IQ21sin(long A);
extern    long _IQ20sin(long A);
extern    long _IQ19sin(long A);
extern    long _IQ18sin(long A);
extern    long _IQ17sin(long A);
extern    long _IQ16sin(long A);
extern    long _IQ15sin(long A);
extern    long _IQ14sin(long A);
extern    long _IQ13sin(long A);
extern    long _IQ12sin(long A);
extern    long _IQ11sin(long A);
extern    long _IQ10sin(long A);
extern    long _IQ9sin(long A);
extern    long _IQ8sin(long A);
extern    long _IQ7sin(long A);
extern    long _IQ6sin(long A);
extern    long _IQ5sin(long A);
extern    long _IQ4sin(long A);
extern    long _IQ3sin(long A);
extern    long _IQ2sin(long A);
extern    long _IQ1sin(long A);

#if GLOBAL_Q == 30
#define   _IQsin(A)  _IQ30sin(A)
#endif
#if GLOBAL_Q == 29
#define   _IQsin(A)  _IQ29sin(A)
#endif
#if GLOBAL_Q == 28
#define   _IQsin(A)  _IQ28sin(A)
#endif
#if GLOBAL_Q == 27
#define   _IQsin(A)  _IQ27sin(A)
#endif
#if GLOBAL_Q == 26
#define   _IQsin(A)  _IQ26sin(A)
#endif
#if GLOBAL_Q == 25
#define   _IQsin(A)  _IQ25sin(A)
#endif
#if GLOBAL_Q == 24
#define   _IQsin(A)  _IQ24sin(A)
#endif
#if GLOBAL_Q == 23
#define   _IQsin(A)  _IQ23sin(A)
#endif
#if GLOBAL_Q == 22
#define   _IQsin(A)  _IQ22sin(A)
#endif
#if GLOBAL_Q == 21
#define   _IQsin(A)  _IQ21sin(A)
#endif
#if GLOBAL_Q == 20
#define   _IQsin(A)  _IQ20sin(A)
#endif
#if GLOBAL_Q == 19
#define   _IQsin(A)  _IQ19sin(A)
#endif
#if GLOBAL_Q == 18
#define   _IQsin(A)  _IQ18sin(A)
#endif
#if GLOBAL_Q == 17
#define   _IQsin(A)  _IQ17sin(A)
#endif
#if GLOBAL_Q == 16
#define   _IQsin(A)  _IQ16sin(A)
#endif
#if GLOBAL_Q == 15
#define   _IQsin(A)  _IQ15sin(A)
#endif
#if GLOBAL_Q == 14
#define   _IQsin(A)  _IQ14sin(A)
#endif
#if GLOBAL_Q == 13
#define   _IQsin(A)  _IQ13sin(A)
#endif
#if GLOBAL_Q == 12
#define   _IQsin(A)  _IQ12sin(A)
#endif
#if GLOBAL_Q == 11
#define   _IQsin(A)  _IQ11sin(A)
#endif
#if GLOBAL_Q == 10
#define   _IQsin(A)  _IQ10sin(A)
#endif
#if GLOBAL_Q == 9
#define   _IQsin(A)  _IQ9sin(A)
#endif
#if GLOBAL_Q == 8
#define   _IQsin(A)  _IQ8sin(A)
#endif
#if GLOBAL_Q == 7
#define   _IQsin(A)  _IQ7sin(A)
#endif
#if GLOBAL_Q == 6
#define   _IQsin(A)  _IQ6sin(A)
#endif
#if GLOBAL_Q == 5
#define   _IQsin(A)  _IQ5sin(A)
#endif
#if GLOBAL_Q == 4
#define   _IQsin(A)  _IQ4sin(A)
#endif
#if GLOBAL_Q == 3
#define   _IQsin(A)  _IQ3sin(A)
#endif
#if GLOBAL_Q == 2
#define   _IQsin(A)  _IQ2sin(A)
#endif
#if GLOBAL_Q == 1
#define   _IQsin(A)  _IQ1sin(A)
#endif
//---------------------------------------------------------------------------
extern    long _IQ30sinPU(long A);
extern    long _IQ29sinPU(long A);
extern    long _IQ28sinPU(long A);
extern    long _IQ27sinPU(long A);
extern    long _IQ26sinPU(long A);
extern    long _IQ25sinPU(long A);
extern    long _IQ24sinPU(long A);
extern    long _IQ23sinPU(long A);
extern    long _IQ22sinPU(long A);
extern    long _IQ21sinPU(long A);
extern    long _IQ20sinPU(long A);
extern    long _IQ19sinPU(long A);
extern    long _IQ18sinPU(long A);
extern    long _IQ17sinPU(long A);
extern    long _IQ16sinPU(long A);
extern    long _IQ15sinPU(long A);
extern    long _IQ14sinPU(long A);
extern    long _IQ13sinPU(long A);
extern    long _IQ12sinPU(long A);
extern    long _IQ11sinPU(long A);
extern    long _IQ10sinPU(long A);
extern    long _IQ9sinPU(long A);
extern    long _IQ8sinPU(long A);
extern    long _IQ7sinPU(long A);
extern    long _IQ6sinPU(long A);
extern    long _IQ5sinPU(long A);
extern    long _IQ4sinPU(long A);
extern    long _IQ3sinPU(long A);
extern    long _IQ2sinPU(long A);
extern    long _IQ1sinPU(long A);

#if GLOBAL_Q == 30
#define   _IQsinPU(A)  _IQ30sinPU(A)
#endif
#if GLOBAL_Q == 29
#define   _IQsinPU(A)  _IQ29sinPU(A)
#endif
#if GLOBAL_Q == 28
#define   _IQsinPU(A)  _IQ28sinPU(A)
#endif
#if GLOBAL_Q == 27
#define   _IQsinPU(A)  _IQ27sinPU(A)
#endif
#if GLOBAL_Q == 26
#define   _IQsinPU(A)  _IQ26sinPU(A)
#endif
#if GLOBAL_Q == 25
#define   _IQsinPU(A)  _IQ25sinPU(A)
#endif
#if GLOBAL_Q == 24
#define   _IQsinPU(A)  _IQ24sinPU(A)
#endif
#if GLOBAL_Q == 23
#define   _IQsinPU(A)  _IQ23sinPU(A)
#endif
#if GLOBAL_Q == 22
#define   _IQsinPU(A)  _IQ22sinPU(A)
#endif
#if GLOBAL_Q == 21
#define   _IQsinPU(A)  _IQ21sinPU(A)
#endif
#if GLOBAL_Q == 20
#define   _IQsinPU(A)  _IQ20sinPU(A)
#endif
#if GLOBAL_Q == 19
#define   _IQsinPU(A)  _IQ19sinPU(A)
#endif
#if GLOBAL_Q == 18
#define   _IQsinPU(A)  _IQ18sinPU(A)
#endif
#if GLOBAL_Q == 17
#define   _IQsinPU(A)  _IQ17sinPU(A)
#endif
#if GLOBAL_Q == 16
#define   _IQsinPU(A)  _IQ16sinPU(A)
#endif
#if GLOBAL_Q == 15
#define   _IQsinPU(A)  _IQ15sinPU(A)
#endif
#if GLOBAL_Q == 14
#define   _IQsinPU(A)  _IQ14sinPU(A)
#endif
#if GLOBAL_Q == 13
#define   _IQsinPU(A)  _IQ13sinPU(A)
#endif
#if GLOBAL_Q == 12
#define   _IQsinPU(A)  _IQ12sinPU(A)
#endif
#if GLOBAL_Q == 11
#define   _IQsinPU(A)  _IQ11sinPU(A)
#endif
#if GLOBAL_Q == 10
#define   _IQsinPU(A)  _IQ10sinPU(A)
#endif
#if GLOBAL_Q == 9
#define   _IQsinPU(A)  _IQ9sinPU(A)
#endif
#if GLOBAL_Q == 8
#define   _IQsinPU(A)  _IQ8sinPU(A)
#endif
#if GLOBAL_Q == 7
#define   _IQsinPU(A)  _IQ7sinPU(A)
#endif
#if GLOBAL_Q == 6
#define   _IQsinPU(A)  _IQ6sinPU(A)
#endif
#if GLOBAL_Q == 5
#define   _IQsinPU(A)  _IQ5sinPU(A)
#endif
#if GLOBAL_Q == 4
#define   _IQsinPU(A)  _IQ4sinPU(A)
#endif
#if GLOBAL_Q == 3
#define   _IQsinPU(A)  _IQ3sinPU(A)
#endif
#if GLOBAL_Q == 2
#define   _IQsinPU(A)  _IQ2sinPU(A)
#endif
#if GLOBAL_Q == 1
#define   _IQsinPU(A)  _IQ1sinPU(A)
#endif
//---------------------------------------------------------------------------
extern    long _IQ30asin(long A);
extern    long _IQ29asin(long A);
extern    long _IQ28asin(long A);
extern    long _IQ27asin(long A);
extern    long _IQ26asin(long A);
extern    long _IQ25asin(long A);
extern    long _IQ24asin(long A);
extern    long _IQ23asin(long A);
extern    long _IQ22asin(long A);
extern    long _IQ21asin(long A);
extern    long _IQ20asin(long A);
extern    long _IQ19asin(long A);
extern    long _IQ18asin(long A);
extern    long _IQ17asin(long A);
extern    long _IQ16asin(long A);
extern    long _IQ15asin(long A);
extern    long _IQ14asin(long A);
extern    long _IQ13asin(long A);
extern    long _IQ12asin(long A);
extern    long _IQ11asin(long A);
extern    long _IQ10asin(long A);
extern    long _IQ9asin(long A);
extern    long _IQ8asin(long A);
extern    long _IQ7asin(long A);
extern    long _IQ6asin(long A);
extern    long _IQ5asin(long A);
extern    long _IQ4asin(long A);
extern    long _IQ3asin(long A);
extern    long _IQ2asin(long A);
extern    long _IQ1asin(long A);

#if GLOBAL_Q == 30
#define   _IQasin(A)  _IQ30asin(A)
#endif
#if GLOBAL_Q == 29
#define   _IQasin(A)  _IQ29asin(A)
#endif
#if GLOBAL_Q == 28
#define   _IQasin(A)  _IQ28asin(A)
#endif
#if GLOBAL_Q == 27
#define   _IQasin(A)  _IQ27asin(A)
#endif
#if GLOBAL_Q == 26
#define   _IQasin(A)  _IQ26asin(A)
#endif
#if GLOBAL_Q == 25
#define   _IQasin(A)  _IQ25asin(A)
#endif
#if GLOBAL_Q == 24
#define   _IQasin(A)  _IQ24asin(A)
#endif
#if GLOBAL_Q == 23
#define   _IQasin(A)  _IQ23asin(A)
#endif
#if GLOBAL_Q == 22
#define   _IQasin(A)  _IQ22asin(A)
#endif
#if GLOBAL_Q == 21
#define   _IQasin(A)  _IQ21asin(A)
#endif
#if GLOBAL_Q == 20
#define   _IQasin(A)  _IQ20asin(A)
#endif
#if GLOBAL_Q == 19
#define   _IQasin(A)  _IQ19asin(A)
#endif
#if GLOBAL_Q == 18
#define   _IQasin(A)  _IQ18asin(A)
#endif
#if GLOBAL_Q == 17
#define   _IQasin(A)  _IQ17asin(A)
#endif
#if GLOBAL_Q == 16
#define   _IQasin(A)  _IQ16asin(A)
#endif
#if GLOBAL_Q == 15
#define   _IQasin(A)  _IQ15asin(A)
#endif
#if GLOBAL_Q == 14
#define   _IQasin(A)  _IQ14asin(A)
#endif
#if GLOBAL_Q == 13
#define   _IQasin(A)  _IQ13asin(A)
#endif
#if GLOBAL_Q == 12
#define   _IQasin(A)  _IQ12asin(A)
#endif
#if GLOBAL_Q == 11
#define   _IQasin(A)  _IQ11asin(A)
#endif
#if GLOBAL_Q == 10
#define   _IQasin(A)  _IQ10asin(A)
#endif
#if GLOBAL_Q == 9
#define   _IQasin(A)  _IQ9asin(A)
#endif
#if GLOBAL_Q == 8
#define   _IQasin(A)  _IQ8asin(A)
#endif
#if GLOBAL_Q == 7
#define   _IQasin(A)  _IQ7asin(A)
#endif
#if GLOBAL_Q == 6
#define   _IQasin(A)  _IQ6asin(A)
#endif
#if GLOBAL_Q == 5
#define   _IQasin(A)  _IQ5asin(A)
#endif
#if GLOBAL_Q == 4
#define   _IQasin(A)  _IQ4asin(A)
#endif
#if GLOBAL_Q == 3
#define   _IQasin(A)  _IQ3asin(A)
#endif
#if GLOBAL_Q == 2
#define   _IQasin(A)  _IQ2asin(A)
#endif
#if GLOBAL_Q == 1
#define   _IQasin(A)  _IQ1asin(A)
#endif
//---------------------------------------------------------------------------
extern    long _IQ30cos(long A);
extern    long _IQ29cos(long A);
extern    long _IQ28cos(long A);
extern    long _IQ27cos(long A);
extern    long _IQ26cos(long A);
extern    long _IQ25cos(long A);
extern    long _IQ24cos(long A);
extern    long _IQ23cos(long A);
extern    long _IQ22cos(long A);
extern    long _IQ21cos(long A);
extern    long _IQ20cos(long A);
extern    long _IQ19cos(long A);
extern    long _IQ18cos(long A);
extern    long _IQ17cos(long A);
extern    long _IQ16cos(long A);
extern    long _IQ15cos(long A);
extern    long _IQ14cos(long A);
extern    long _IQ13cos(long A);
extern    long _IQ12cos(long A);
extern    long _IQ11cos(long A);
extern    long _IQ10cos(long A);
extern    long _IQ9cos(long A);
extern    long _IQ8cos(long A);
extern    long _IQ7cos(long A);
extern    long _IQ6cos(long A);
extern    long _IQ5cos(long A);
extern    long _IQ4cos(long A);
extern    long _IQ3cos(long A);
extern    long _IQ2cos(long A);
extern    long _IQ1cos(long A);

#if GLOBAL_Q == 30
#define   _IQcos(A)  _IQ30cos(A)
#endif
#if GLOBAL_Q == 29
#define   _IQcos(A)  _IQ29cos(A)
#endif
#if GLOBAL_Q == 28
#define   _IQcos(A)  _IQ28cos(A)
#endif
#if GLOBAL_Q == 27
#define   _IQcos(A)  _IQ27cos(A)
#endif
#if GLOBAL_Q == 26
#define   _IQcos(A)  _IQ26cos(A)
#endif
#if GLOBAL_Q == 25
#define   _IQcos(A)  _IQ25cos(A)
#endif
#if GLOBAL_Q == 24
#define   _IQcos(A)  _IQ24cos(A)
#endif
#if GLOBAL_Q == 23
#define   _IQcos(A)  _IQ23cos(A)
#endif
#if GLOBAL_Q == 22
#define   _IQcos(A)  _IQ22cos(A)
#endif
#if GLOBAL_Q == 21
#define   _IQcos(A)  _IQ21cos(A)
#endif
#if GLOBAL_Q == 20
#define   _IQcos(A)  _IQ20cos(A)
#endif
#if GLOBAL_Q == 19
#define   _IQcos(A)  _IQ19cos(A)
#endif
#if GLOBAL_Q == 18
#define   _IQcos(A)  _IQ18cos(A)
#endif
#if GLOBAL_Q == 17
#define   _IQcos(A)  _IQ17cos(A)
#endif
#if GLOBAL_Q == 16
#define   _IQcos(A)  _IQ16cos(A)
#endif
#if GLOBAL_Q == 15
#define   _IQcos(A)  _IQ15cos(A)
#endif
#if GLOBAL_Q == 14
#define   _IQcos(A)  _IQ14cos(A)
#endif
#if GLOBAL_Q == 13
#define   _IQcos(A)  _IQ13cos(A)
#endif
#if GLOBAL_Q == 12
#define   _IQcos(A)  _IQ12cos(A)
#endif
#if GLOBAL_Q == 11
#define   _IQcos(A)  _IQ11cos(A)
#endif
#if GLOBAL_Q == 10
#define   _IQcos(A)  _IQ10cos(A)
#endif
#if GLOBAL_Q == 9
#define   _IQcos(A)  _IQ9cos(A)
#endif
#if GLOBAL_Q == 8
#define   _IQcos(A)  _IQ8cos(A)
#endif
#if GLOBAL_Q == 7
#define   _IQcos(A)  _IQ7cos(A)
#endif
#if GLOBAL_Q == 6
#define   _IQcos(A)  _IQ6cos(A)
#endif
#if GLOBAL_Q == 5
#define   _IQcos(A)  _IQ5cos(A)
#endif
#if GLOBAL_Q == 4
#define   _IQcos(A)  _IQ4cos(A)
#endif
#if GLOBAL_Q == 3
#define   _IQcos(A)  _IQ3cos(A)
#endif
#if GLOBAL_Q == 2
#define   _IQcos(A)  _IQ2cos(A)
#endif
#if GLOBAL_Q == 1
#define   _IQcos(A)  _IQ1cos(A)
#endif
//---------------------------------------------------------------------------
extern    long _IQ30cosPU(long A);
extern    long _IQ29cosPU(long A);
extern    long _IQ28cosPU(long A);
extern    long _IQ27cosPU(long A);
extern    long _IQ26cosPU(long A);
extern    long _IQ25cosPU(long A);
extern    long _IQ24cosPU(long A);
extern    long _IQ23cosPU(long A);
extern    long _IQ22cosPU(long A);
extern    long _IQ21cosPU(long A);
extern    long _IQ20cosPU(long A);
extern    long _IQ19cosPU(long A);
extern    long _IQ18cosPU(long A);
extern    long _IQ17cosPU(long A);
extern    long _IQ16cosPU(long A);
extern    long _IQ15cosPU(long A);
extern    long _IQ14cosPU(long A);
extern    long _IQ13cosPU(long A);
extern    long _IQ12cosPU(long A);
extern    long _IQ11cosPU(long A);
extern    long _IQ10cosPU(long A);
extern    long _IQ9cosPU(long A);
extern    long _IQ8cosPU(long A);
extern    long _IQ7cosPU(long A);
extern    long _IQ6cosPU(long A);
extern    long _IQ5cosPU(long A);
extern    long _IQ4cosPU(long A);
extern    long _IQ3cosPU(long A);
extern    long _IQ2cosPU(long A);
extern    long _IQ1cosPU(long A);

#if GLOBAL_Q == 30
#define   _IQcosPU(A)  _IQ30cosPU(A)
#endif
#if GLOBAL_Q == 29
#define   _IQcosPU(A)  _IQ29cosPU(A)
#endif
#if GLOBAL_Q == 28
#define   _IQcosPU(A)  _IQ28cosPU(A)
#endif
#if GLOBAL_Q == 27
#define   _IQcosPU(A)  _IQ27cosPU(A)
#endif
#if GLOBAL_Q == 26
#define   _IQcosPU(A)  _IQ26cosPU(A)
#endif
#if GLOBAL_Q == 25
#define   _IQcosPU(A)  _IQ25cosPU(A)
#endif
#if GLOBAL_Q == 24
#define   _IQcosPU(A)  _IQ24cosPU(A)
#endif
#if GLOBAL_Q == 23
#define   _IQcosPU(A)  _IQ23cosPU(A)
#endif
#if GLOBAL_Q == 22
#define   _IQcosPU(A)  _IQ22cosPU(A)
#endif
#if GLOBAL_Q == 21
#define   _IQcosPU(A)  _IQ21cosPU(A)
#endif
#if GLOBAL_Q == 20
#define   _IQcosPU(A)  _IQ20cosPU(A)
#endif
#if GLOBAL_Q == 19
#define   _IQcosPU(A)  _IQ19cosPU(A)
#endif
#if GLOBAL_Q == 18
#define   _IQcosPU(A)  _IQ18cosPU(A)
#endif
#if GLOBAL_Q == 17
#define   _IQcosPU(A)  _IQ17cosPU(A)
#endif
#if GLOBAL_Q == 16
#define   _IQcosPU(A)  _IQ16cosPU(A)
#endif
#if GLOBAL_Q == 15
#define   _IQcosPU(A)  _IQ15cosPU(A)
#endif
#if GLOBAL_Q == 14
#define   _IQcosPU(A)  _IQ14cosPU(A)
#endif
#if GLOBAL_Q == 13
#define   _IQcosPU(A)  _IQ13cosPU(A)
#endif
#if GLOBAL_Q == 12
#define   _IQcosPU(A)  _IQ12cosPU(A)
#endif
#if GLOBAL_Q == 11
#define   _IQcosPU(A)  _IQ11cosPU(A)
#endif
#if GLOBAL_Q == 10
#define   _IQcosPU(A)  _IQ10cosPU(A)
#endif
#if GLOBAL_Q == 9
#define   _IQcosPU(A)  _IQ9cosPU(A)
#endif
#if GLOBAL_Q == 8
#define   _IQcosPU(A)  _IQ8cosPU(A)
#endif
#if GLOBAL_Q == 7
#define   _IQcosPU(A)  _IQ7cosPU(A)
#endif
#if GLOBAL_Q == 6
#define   _IQcosPU(A)  _IQ6cosPU(A)
#endif
#if GLOBAL_Q == 5
#define   _IQcosPU(A)  _IQ5cosPU(A)
#endif
#if GLOBAL_Q == 4
#define   _IQcosPU(A)  _IQ4cosPU(A)
#endif
#if GLOBAL_Q == 3
#define   _IQcosPU(A)  _IQ3cosPU(A)
#endif
#if GLOBAL_Q == 2
#define   _IQcosPU(A)  _IQ2cosPU(A)
#endif
#if GLOBAL_Q == 1
#define   _IQcosPU(A)  _IQ1cosPU(A)
#endif
//---------------------------------------------------------------------------
extern    long _IQ30acos(long A);
extern    long _IQ29acos(long A);
extern    long _IQ28acos(long A);
extern    long _IQ27acos(long A);
extern    long _IQ26acos(long A);
extern    long _IQ25acos(long A);
extern    long _IQ24acos(long A);
extern    long _IQ23acos(long A);
extern    long _IQ22acos(long A);
extern    long _IQ21acos(long A);
extern    long _IQ20acos(long A);
extern    long _IQ19acos(long A);
extern    long _IQ18acos(long A);
extern    long _IQ17acos(long A);
extern    long _IQ16acos(long A);
extern    long _IQ15acos(long A);
extern    long _IQ14acos(long A);
extern    long _IQ13acos(long A);
extern    long _IQ12acos(long A);
extern    long _IQ11acos(long A);
extern    long _IQ10acos(long A);
extern    long _IQ9acos(long A);
extern    long _IQ8acos(long A);
extern    long _IQ7acos(long A);
extern    long _IQ6acos(long A);
extern    long _IQ5acos(long A);
extern    long _IQ4acos(long A);
extern    long _IQ3acos(long A);
extern    long _IQ2acos(long A);
extern    long _IQ1acos(long A);

#if GLOBAL_Q == 30
#define   _IQacos(A)  _IQ30acos(A)
#endif
#if GLOBAL_Q == 29
#define   _IQacos(A)  _IQ29acos(A)
#endif
#if GLOBAL_Q == 28
#define   _IQacos(A)  _IQ28acos(A)
#endif
#if GLOBAL_Q == 27
#define   _IQacos(A)  _IQ27acos(A)
#endif
#if GLOBAL_Q == 26
#define   _IQacos(A)  _IQ26acos(A)
#endif
#if GLOBAL_Q == 25
#define   _IQacos(A)  _IQ25acos(A)
#endif
#if GLOBAL_Q == 24
#define   _IQacos(A)  _IQ24acos(A)
#endif
#if GLOBAL_Q == 23
#define   _IQacos(A)  _IQ23acos(A)
#endif
#if GLOBAL_Q == 22
#define   _IQacos(A)  _IQ22acos(A)
#endif
#if GLOBAL_Q == 21
#define   _IQacos(A)  _IQ21acos(A)
#endif
#if GLOBAL_Q == 20
#define   _IQacos(A)  _IQ20acos(A)
#endif
#if GLOBAL_Q == 19
#define   _IQacos(A)  _IQ19acos(A)
#endif
#if GLOBAL_Q == 18
#define   _IQacos(A)  _IQ18acos(A)
#endif
#if GLOBAL_Q == 17
#define   _IQacos(A)  _IQ17acos(A)
#endif
#if GLOBAL_Q == 16
#define   _IQacos(A)  _IQ16acos(A)
#endif
#if GLOBAL_Q == 15
#define   _IQacos(A)  _IQ15acos(A)
#endif
#if GLOBAL_Q == 14
#define   _IQacos(A)  _IQ14acos(A)
#endif
#if GLOBAL_Q == 13
#define   _IQacos(A)  _IQ13acos(A)
#endif
#if GLOBAL_Q == 12
#define   _IQacos(A)  _IQ12acos(A)
#endif
#if GLOBAL_Q == 11
#define   _IQacos(A)  _IQ11acos(A)
#endif
#if GLOBAL_Q == 10
#define   _IQacos(A)  _IQ10acos(A)
#endif
#if GLOBAL_Q == 9
#define   _IQacos(A)  _IQ9acos(A)
#endif
#if GLOBAL_Q == 8
#define   _IQacos(A)  _IQ8acos(A)
#endif
#if GLOBAL_Q == 7
#define   _IQacos(A)  _IQ7acos(A)
#endif
#if GLOBAL_Q == 6
#define   _IQacos(A)  _IQ6acos(A)
#endif
#if GLOBAL_Q == 5
#define   _IQacos(A)  _IQ5acos(A)
#endif
#if GLOBAL_Q == 4
#define   _IQacos(A)  _IQ4acos(A)
#endif
#if GLOBAL_Q == 3
#define   _IQacos(A)  _IQ3acos(A)
#endif
#if GLOBAL_Q == 2
#define   _IQacos(A)  _IQ2acos(A)
#endif
#if GLOBAL_Q == 1
#define   _IQacos(A)  _IQ1acos(A)
#endif
//---------------------------------------------------------------------------
extern    long _IQ30atan2(long A, long B);
extern    long _IQ29atan2(long A, long B);
extern    long _IQ28atan2(long A, long B);
extern    long _IQ27atan2(long A, long B);
extern    long _IQ26atan2(long A, long B);
extern    long _IQ25atan2(long A, long B);
extern    long _IQ24atan2(long A, long B);
extern    long _IQ23atan2(long A, long B);
extern    long _IQ22atan2(long A, long B);
extern    long _IQ21atan2(long A, long B);
extern    long _IQ20atan2(long A, long B);
extern    long _IQ19atan2(long A, long B);
extern    long _IQ18atan2(long A, long B);
extern    long _IQ17atan2(long A, long B);
extern    long _IQ16atan2(long A, long B);
extern    long _IQ15atan2(long A, long B);
extern    long _IQ14atan2(long A, long B);
extern    long _IQ13atan2(long A, long B);
extern    long _IQ12atan2(long A, long B);
extern    long _IQ11atan2(long A, long B);
extern    long _IQ10atan2(long A, long B);
extern    long _IQ9atan2(long A, long B);
extern    long _IQ8atan2(long A, long B);
extern    long _IQ7atan2(long A, long B);
extern    long _IQ6atan2(long A, long B);
extern    long _IQ5atan2(long A, long B);
extern    long _IQ4atan2(long A, long B);
extern    long _IQ3atan2(long A, long B);
extern    long _IQ2atan2(long A, long B);
extern    long _IQ1atan2(long A, long B);

#if GLOBAL_Q == 30
#define   _IQatan2(A,B)  _IQ30atan2(A,B)
#endif
#if GLOBAL_Q == 29
#define   _IQatan2(A,B)  _IQ29atan2(A,B)
#endif
#if GLOBAL_Q == 28
#define   _IQatan2(A,B)  _IQ28atan2(A,B)
#endif
#if GLOBAL_Q == 27
#define   _IQatan2(A,B)  _IQ27atan2(A,B)
#endif
#if GLOBAL_Q == 26
#define   _IQatan2(A,B)  _IQ26atan2(A,B)
#endif
#if GLOBAL_Q == 25
#define   _IQatan2(A,B)  _IQ25atan2(A,B)
#endif
#if GLOBAL_Q == 24
#define   _IQatan2(A,B)  _IQ24atan2(A,B)
#endif
#if GLOBAL_Q == 23
#define   _IQatan2(A,B)  _IQ23atan2(A,B)
#endif
#if GLOBAL_Q == 22
#define   _IQatan2(A,B)  _IQ22atan2(A,B)
#endif
#if GLOBAL_Q == 21
#define   _IQatan2(A,B)  _IQ21atan2(A,B)
#endif
#if GLOBAL_Q == 20
#define   _IQatan2(A,B)  _IQ20atan2(A,B)
#endif
#if GLOBAL_Q == 19
#define   _IQatan2(A,B)  _IQ19atan2(A,B)
#endif
#if GLOBAL_Q == 18
#define   _IQatan2(A,B)  _IQ18atan2(A,B)
#endif
#if GLOBAL_Q == 17
#define   _IQatan2(A,B)  _IQ17atan2(A,B)
#endif
#if GLOBAL_Q == 16
#define   _IQatan2(A,B)  _IQ16atan2(A,B)
#endif
#if GLOBAL_Q == 15
#define   _IQatan2(A,B)  _IQ15atan2(A,B)
#endif
#if GLOBAL_Q == 14
#define   _IQatan2(A,B)  _IQ14atan2(A,B)
#endif
#if GLOBAL_Q == 13
#define   _IQatan2(A,B)  _IQ13atan2(A,B)
#endif
#if GLOBAL_Q == 12
#define   _IQatan2(A,B)  _IQ12atan2(A,B)
#endif
#if GLOBAL_Q == 11
#define   _IQatan2(A,B)  _IQ11atan2(A,B)
#endif
#if GLOBAL_Q == 10
#define   _IQatan2(A,B)  _IQ10atan2(A,B)
#endif
#if GLOBAL_Q == 9
#define   _IQatan2(A,B)  _IQ9atan2(A,B)
#endif
#if GLOBAL_Q == 8
#define   _IQatan2(A,B)  _IQ8atan2(A,B)
#endif
#if GLOBAL_Q == 7
#define   _IQatan2(A,B)  _IQ7atan2(A,B)
#endif
#if GLOBAL_Q == 6
#define   _IQatan2(A,B)  _IQ6atan2(A,B)
#endif
#if GLOBAL_Q == 5
#define   _IQatan2(A,B)  _IQ5atan2(A,B)
#endif
#if GLOBAL_Q == 4
#define   _IQatan2(A,B)  _IQ4atan2(A,B)
#endif
#if GLOBAL_Q == 3
#define   _IQatan2(A,B)  _IQ3atan2(A,B)
#endif
#if GLOBAL_Q == 2
#define   _IQatan2(A,B)  _IQ2atan2(A,B)
#endif
#if GLOBAL_Q == 1
#define   _IQatan2(A,B)  _IQ1atan2(A,B)
#endif
//---------------------------------------------------------------------------
extern    long _IQ30atan2PU(long A, long B);
extern    long _IQ29atan2PU(long A, long B);
extern    long _IQ28atan2PU(long A, long B);
extern    long _IQ27atan2PU(long A, long B);
extern    long _IQ26atan2PU(long A, long B);
extern    long _IQ25atan2PU(long A, long B);
extern    long _IQ24atan2PU(long A, long B);
extern    long _IQ23atan2PU(long A, long B);
extern    long _IQ22atan2PU(long A, long B);
extern    long _IQ21atan2PU(long A, long B);
extern    long _IQ20atan2PU(long A, long B);
extern    long _IQ19atan2PU(long A, long B);
extern    long _IQ18atan2PU(long A, long B);
extern    long _IQ17atan2PU(long A, long B);
extern    long _IQ16atan2PU(long A, long B);
extern    long _IQ15atan2PU(long A, long B);
extern    long _IQ14atan2PU(long A, long B);
extern    long _IQ13atan2PU(long A, long B);
extern    long _IQ12atan2PU(long A, long B);
extern    long _IQ11atan2PU(long A, long B);
extern    long _IQ10atan2PU(long A, long B);
extern    long _IQ9atan2PU(long A, long B);
extern    long _IQ8atan2PU(long A, long B);
extern    long _IQ7atan2PU(long A, long B);
extern    long _IQ6atan2PU(long A, long B);
extern    long _IQ5atan2PU(long A, long B);
extern    long _IQ4atan2PU(long A, long B);
extern    long _IQ3atan2PU(long A, long B);
extern    long _IQ2atan2PU(long A, long B);
extern    long _IQ1atan2PU(long A, long B);

#if GLOBAL_Q == 30
#define   _IQatan2PU(A,B)  _IQ30atan2PU(A,B)
#endif
#if GLOBAL_Q == 29
#define   _IQatan2PU(A,B)  _IQ29atan2PU(A,B)
#endif
#if GLOBAL_Q == 28
#define   _IQatan2PU(A,B)  _IQ28atan2PU(A,B)
#endif
#if GLOBAL_Q == 27
#define   _IQatan2PU(A,B)  _IQ27atan2PU(A,B)
#endif
#if GLOBAL_Q == 26
#define   _IQatan2PU(A,B)  _IQ26atan2PU(A,B)
#endif
#if GLOBAL_Q == 25
#define   _IQatan2PU(A,B)  _IQ25atan2PU(A,B)
#endif
#if GLOBAL_Q == 24
#define   _IQatan2PU(A,B)  _IQ24atan2PU(A,B)
#endif
#if GLOBAL_Q == 23
#define   _IQatan2PU(A,B)  _IQ23atan2PU(A,B)
#endif
#if GLOBAL_Q == 22
#define   _IQatan2PU(A,B)  _IQ22atan2PU(A,B)
#endif
#if GLOBAL_Q == 21
#define   _IQatan2PU(A,B)  _IQ21atan2PU(A,B)
#endif
#if GLOBAL_Q == 20
#define   _IQatan2PU(A,B)  _IQ20atan2PU(A,B)
#endif
#if GLOBAL_Q == 19
#define   _IQatan2PU(A,B)  _IQ19atan2PU(A,B)
#endif
#if GLOBAL_Q == 18
#define   _IQatan2PU(A,B)  _IQ18atan2PU(A,B)
#endif
#if GLOBAL_Q == 17
#define   _IQatan2PU(A,B)  _IQ17atan2PU(A,B)
#endif
#if GLOBAL_Q == 16
#define   _IQatan2PU(A,B)  _IQ16atan2PU(A,B)
#endif
#if GLOBAL_Q == 15
#define   _IQatan2PU(A,B)  _IQ15atan2PU(A,B)
#endif
#if GLOBAL_Q == 14
#define   _IQatan2PU(A,B)  _IQ14atan2PU(A,B)
#endif
#if GLOBAL_Q == 13
#define   _IQatan2PU(A,B)  _IQ13atan2PU(A,B)
#endif
#if GLOBAL_Q == 12
#define   _IQatan2PU(A,B)  _IQ12atan2PU(A,B)
#endif
#if GLOBAL_Q == 11
#define   _IQatan2PU(A,B)  _IQ11atan2PU(A,B)
#endif
#if GLOBAL_Q == 10
#define   _IQatan2PU(A,B)  _IQ10atan2PU(A,B)
#endif
#if GLOBAL_Q == 9
#define   _IQatan2PU(A,B)  _IQ9atan2PU(A,B)
#endif
#if GLOBAL_Q == 8
#define   _IQatan2PU(A,B)  _IQ8atan2PU(A,B)
#endif
#if GLOBAL_Q == 7
#define   _IQatan2PU(A,B)  _IQ7atan2PU(A,B)
#endif
#if GLOBAL_Q == 6
#define   _IQatan2PU(A,B)  _IQ6atan2PU(A,B)
#endif
#if GLOBAL_Q == 5
#define   _IQatan2PU(A,B)  _IQ5atan2PU(A,B)
#endif
#if GLOBAL_Q == 4
#define   _IQatan2PU(A,B)  _IQ4atan2PU(A,B)
#endif
#if GLOBAL_Q == 3
#define   _IQatan2PU(A,B)  _IQ3atan2PU(A,B)
#endif
#if GLOBAL_Q == 2
#define   _IQatan2PU(A,B)  _IQ2atan2PU(A,B)
#endif
#if GLOBAL_Q == 1
#define   _IQatan2PU(A,B)  _IQ1atan2PU(A,B)
#endif
//---------------------------------------------------------------------------
#define   _IQ30atan(A)  _IQ30atan2(A,_IQ30(1.0))
#define   _IQ29atan(A)  _IQ29atan2(A,_IQ29(1.0))
#define   _IQ28atan(A)  _IQ28atan2(A,_IQ28(1.0))
#define   _IQ27atan(A)  _IQ27atan2(A,_IQ27(1.0))
#define   _IQ26atan(A)  _IQ26atan2(A,_IQ26(1.0))
#define   _IQ25atan(A)  _IQ25atan2(A,_IQ25(1.0))
#define   _IQ24atan(A)  _IQ24atan2(A,_IQ24(1.0))
#define   _IQ23atan(A)  _IQ23atan2(A,_IQ23(1.0))
#define   _IQ22atan(A)  _IQ22atan2(A,_IQ22(1.0))
#define   _IQ21atan(A)  _IQ21atan2(A,_IQ21(1.0))
#define   _IQ20atan(A)  _IQ20atan2(A,_IQ20(1.0))
#define   _IQ19atan(A)  _IQ19atan2(A,_IQ19(1.0))
#define   _IQ18atan(A)  _IQ18atan2(A,_IQ18(1.0))
#define   _IQ17atan(A)  _IQ17atan2(A,_IQ17(1.0))
#define   _IQ16atan(A)  _IQ16atan2(A,_IQ16(1.0))
#define   _IQ15atan(A)  _IQ15atan2(A,_IQ15(1.0))
#define   _IQ14atan(A)  _IQ14atan2(A,_IQ14(1.0))
#define   _IQ13atan(A)  _IQ13atan2(A,_IQ13(1.0))
#define   _IQ12atan(A)  _IQ12atan2(A,_IQ12(1.0))
#define   _IQ11atan(A)  _IQ11atan2(A,_IQ11(1.0))
#define   _IQ10atan(A)  _IQ10atan2(A,_IQ10(1.0))
#define   _IQ9atan(A)   _IQ9atan2(A,_IQ9(1.0))
#define   _IQ8atan(A)   _IQ8atan2(A,_IQ8(1.0))
#define   _IQ7atan(A)   _IQ7atan2(A,_IQ7(1.0))
#define   _IQ6atan(A)   _IQ6atan2(A,_IQ6(1.0))
#define   _IQ5atan(A)   _IQ5atan2(A,_IQ5(1.0))
#define   _IQ4atan(A)   _IQ4atan2(A,_IQ4(1.0))
#define   _IQ3atan(A)   _IQ3atan2(A,_IQ3(1.0))
#define   _IQ2atan(A)   _IQ2atan2(A,_IQ2(1.0))
#define   _IQ1atan(A)   _IQ1atan2(A,_IQ1(1.0))
#if GLOBAL_Q == 30
#define   _IQatan(A)  _IQ30atan2(A,_IQ(1.0))
#endif
#if GLOBAL_Q == 29
#define   _IQatan(A)  _IQ29atan2(A,_IQ(1.0))
#endif
#if GLOBAL_Q == 28
#define   _IQatan(A)  _IQ28atan2(A,_IQ(1.0))
#endif
#if GLOBAL_Q == 27
#define   _IQatan(A)  _IQ27atan2(A,_IQ(1.0))
#endif
#if GLOBAL_Q == 26
#define   _IQatan(A)  _IQ26atan2(A,_IQ(1.0))
#endif
#if GLOBAL_Q == 25
#define   _IQatan(A)  _IQ25atan2(A,_IQ(1.0))
#endif
#if GLOBAL_Q == 24
#define   _IQatan(A)  _IQ24atan2(A,_IQ(1.0))
#endif
#if GLOBAL_Q == 23
#define   _IQatan(A)  _IQ23atan2(A,_IQ(1.0))
#endif
#if GLOBAL_Q == 22
#define   _IQatan(A)  _IQ22atan2(A,_IQ(1.0))
#endif
#if GLOBAL_Q == 21
#define   _IQatan(A)  _IQ21atan2(A,_IQ(1.0))
#endif
#if GLOBAL_Q == 20
#define   _IQatan(A)  _IQ20atan2(A,_IQ(1.0))
#endif
#if GLOBAL_Q == 19
#define   _IQatan(A)  _IQ19atan2(A,_IQ(1.0))
#endif
#if GLOBAL_Q == 18
#define   _IQatan(A)  _IQ18atan2(A,_IQ(1.0))
#endif
#if GLOBAL_Q == 17
#define   _IQatan(A)  _IQ17atan2(A,_IQ(1.0))
#endif
#if GLOBAL_Q == 16
#define   _IQatan(A)  _IQ16atan2(A,_IQ(1.0))
#endif
#if GLOBAL_Q == 15
#define   _IQatan(A)  _IQ15atan2(A,_IQ(1.0))
#endif
#if GLOBAL_Q == 14
#define   _IQatan(A)  _IQ14atan2(A,_IQ(1.0))
#endif
#if GLOBAL_Q == 13
#define   _IQatan(A)  _IQ13atan2(A,_IQ(1.0))
#endif
#if GLOBAL_Q == 12
#define   _IQatan(A)  _IQ12atan2(A,_IQ(1.0))
#endif
#if GLOBAL_Q == 11
#define   _IQatan(A)  _IQ11atan2(A,_IQ(1.0))
#endif
#if GLOBAL_Q == 10
#define   _IQatan(A)  _IQ10atan2(A,_IQ(1.0))
#endif
#if GLOBAL_Q == 9
#define   _IQatan(A)  _IQ9atan2(A,_IQ(1.0))
#endif
#if GLOBAL_Q == 8
#define   _IQatan(A)  _IQ8atan2(A,_IQ(1.0))
#endif
#if GLOBAL_Q == 7
#define   _IQatan(A)  _IQ7atan2(A,_IQ(1.0))
#endif
#if GLOBAL_Q == 6
#define   _IQatan(A)  _IQ6atan2(A,_IQ(1.0))
#endif
#if GLOBAL_Q == 5
#define   _IQatan(A)  _IQ5atan2(A,_IQ(1.0))
#endif
#if GLOBAL_Q == 4
#define   _IQatan(A)  _IQ4atan2(A,_IQ(1.0))
#endif
#if GLOBAL_Q == 3
#define   _IQatan(A)  _IQ3atan2(A,_IQ(1.0))
#endif
#if GLOBAL_Q == 2
#define   _IQatan(A)  _IQ2atan2(A,_IQ(1.0))
#endif
#if GLOBAL_Q == 1
#define   _IQatan(A)  _IQ1atan2(A,_IQ(1.0))
#endif
//---------------------------------------------------------------------------
extern    long _IQ30sqrt(long A);
extern    long _IQ29sqrt(long A);
extern    long _IQ28sqrt(long A);
extern    long _IQ27sqrt(long A);
extern    long _IQ26sqrt(long A);
extern    long _IQ25sqrt(long A);
extern    long _IQ24sqrt(long A);
extern    long _IQ23sqrt(long A);
extern    long _IQ22sqrt(long A);
extern    long _IQ21sqrt(long A);
extern    long _IQ20sqrt(long A);
extern    long _IQ19sqrt(long A);
extern    long _IQ18sqrt(long A);
extern    long _IQ17sqrt(long A);
extern    long _IQ16sqrt(long A);
extern    long _IQ15sqrt(long A);
extern    long _IQ14sqrt(long A);
extern    long _IQ13sqrt(long A);
extern    long _IQ12sqrt(long A);
extern    long _IQ11sqrt(long A);
extern    long _IQ10sqrt(long A);
extern    long _IQ9sqrt(long A);
extern    long _IQ8sqrt(long A);
extern    long _IQ7sqrt(long A);
extern    long _IQ6sqrt(long A);
extern    long _IQ5sqrt(long A);
extern    long _IQ4sqrt(long A);
extern    long _IQ3sqrt(long A);
extern    long _IQ2sqrt(long A);
extern    long _IQ1sqrt(long A);

#if GLOBAL_Q == 30
#define   _IQsqrt(A)  _IQ30sqrt(A)
#endif
#if GLOBAL_Q == 29
#define   _IQsqrt(A)  _IQ29sqrt(A)
#endif
#if GLOBAL_Q == 28
#define   _IQsqrt(A)  _IQ28sqrt(A)
#endif
#if GLOBAL_Q == 27
#define   _IQsqrt(A)  _IQ27sqrt(A)
#endif
#if GLOBAL_Q == 26
#define   _IQsqrt(A)  _IQ26sqrt(A)
#endif
#if GLOBAL_Q == 25
#define   _IQsqrt(A)  _IQ25sqrt(A)
#endif
#if GLOBAL_Q == 24
#define   _IQsqrt(A)  _IQ24sqrt(A)
#endif
#if GLOBAL_Q == 23
#define   _IQsqrt(A)  _IQ23sqrt(A)
#endif
#if GLOBAL_Q == 22
#define   _IQsqrt(A)  _IQ22sqrt(A)
#endif
#if GLOBAL_Q == 21
#define   _IQsqrt(A)  _IQ21sqrt(A)
#endif
#if GLOBAL_Q == 20
#define   _IQsqrt(A)  _IQ20sqrt(A)
#endif
#if GLOBAL_Q == 19
#define   _IQsqrt(A)  _IQ19sqrt(A)
#endif
#if GLOBAL_Q == 18
#define   _IQsqrt(A)  _IQ18sqrt(A)
#endif
#if GLOBAL_Q == 17
#define   _IQsqrt(A)  _IQ17sqrt(A)
#endif
#if GLOBAL_Q == 16
#define   _IQsqrt(A)  _IQ16sqrt(A)
#endif
#if GLOBAL_Q == 15
#define   _IQsqrt(A)  _IQ15sqrt(A)
#endif
#if GLOBAL_Q == 14
#define   _IQsqrt(A)  _IQ14sqrt(A)
#endif
#if GLOBAL_Q == 13
#define   _IQsqrt(A)  _IQ13sqrt(A)
#endif
#if GLOBAL_Q == 12
#define   _IQsqrt(A)  _IQ12sqrt(A)
#endif
#if GLOBAL_Q == 11
#define   _IQsqrt(A)  _IQ11sqrt(A)
#endif
#if GLOBAL_Q == 10
#define   _IQsqrt(A)  _IQ10sqrt(A)
#endif
#if GLOBAL_Q == 9
#define   _IQsqrt(A)  _IQ9sqrt(A)
#endif
#if GLOBAL_Q == 8
#define   _IQsqrt(A)  _IQ8sqrt(A)
#endif
#if GLOBAL_Q == 7
#define   _IQsqrt(A)  _IQ7sqrt(A)
#endif
#if GLOBAL_Q == 6
#define   _IQsqrt(A)  _IQ6sqrt(A)
#endif
#if GLOBAL_Q == 5
#define   _IQsqrt(A)  _IQ5sqrt(A)
#endif
#if GLOBAL_Q == 4
#define   _IQsqrt(A)  _IQ4sqrt(A)
#endif
#if GLOBAL_Q == 3
#define   _IQsqrt(A)  _IQ3sqrt(A)
#endif
#if GLOBAL_Q == 2
#define   _IQsqrt(A)  _IQ2sqrt(A)
#endif
#if GLOBAL_Q == 1
#define   _IQsqrt(A)  _IQ1sqrt(A)
#endif
//---------------------------------------------------------------------------
extern    long _IQ30isqrt(long A);
extern    long _IQ29isqrt(long A);
extern    long _IQ28isqrt(long A);
extern    long _IQ27isqrt(long A);
extern    long _IQ26isqrt(long A);
extern    long _IQ25isqrt(long A);
extern    long _IQ24isqrt(long A);
extern    long _IQ23isqrt(long A);
extern    long _IQ22isqrt(long A);
extern    long _IQ21isqrt(long A);
extern    long _IQ20isqrt(long A);
extern    long _IQ19isqrt(long A);
extern    long _IQ18isqrt(long A);
extern    long _IQ17isqrt(long A);
extern    long _IQ16isqrt(long A);
extern    long _IQ15isqrt(long A);
extern    long _IQ14isqrt(long A);
extern    long _IQ13isqrt(long A);
extern    long _IQ12isqrt(long A);
extern    long _IQ11isqrt(long A);
extern    long _IQ10isqrt(long A);
extern    long _IQ9isqrt(long A);
extern    long _IQ8isqrt(long A);
extern    long _IQ7isqrt(long A);
extern    long _IQ6isqrt(long A);
extern    long _IQ5isqrt(long A);
extern    long _IQ4isqrt(long A);
extern    long _IQ3isqrt(long A);
extern    long _IQ2isqrt(long A);
extern    long _IQ1isqrt(long A);

#if GLOBAL_Q == 30
#define   _IQisqrt(A)  _IQ30isqrt(A)
#endif
#if GLOBAL_Q == 29
#define   _IQisqrt(A)  _IQ29isqrt(A)
#endif
#if GLOBAL_Q == 28
#define   _IQisqrt(A)  _IQ28isqrt(A)
#endif
#if GLOBAL_Q == 27
#define   _IQisqrt(A)  _IQ27isqrt(A)
#endif
#if GLOBAL_Q == 26
#define   _IQisqrt(A)  _IQ26isqrt(A)
#endif
#if GLOBAL_Q == 25
#define   _IQisqrt(A)  _IQ25isqrt(A)
#endif
#if GLOBAL_Q == 24
#define   _IQisqrt(A)  _IQ24isqrt(A)
#endif
#if GLOBAL_Q == 23
#define   _IQisqrt(A)  _IQ23isqrt(A)
#endif
#if GLOBAL_Q == 22
#define   _IQisqrt(A)  _IQ22isqrt(A)
#endif
#if GLOBAL_Q == 21
#define   _IQisqrt(A)  _IQ21isqrt(A)
#endif
#if GLOBAL_Q == 20
#define   _IQisqrt(A)  _IQ20isqrt(A)
#endif
#if GLOBAL_Q == 19
#define   _IQisqrt(A)  _IQ19isqrt(A)
#endif
#if GLOBAL_Q == 18
#define   _IQisqrt(A)  _IQ18isqrt(A)
#endif
#if GLOBAL_Q == 17
#define   _IQisqrt(A)  _IQ17isqrt(A)
#endif
#if GLOBAL_Q == 16
#define   _IQisqrt(A)  _IQ16isqrt(A)
#endif
#if GLOBAL_Q == 15
#define   _IQisqrt(A)  _IQ15isqrt(A)
#endif
#if GLOBAL_Q == 14
#define   _IQisqrt(A)  _IQ14isqrt(A)
#endif
#if GLOBAL_Q == 13
#define   _IQisqrt(A)  _IQ13isqrt(A)
#endif
#if GLOBAL_Q == 12
#define   _IQisqrt(A)  _IQ12isqrt(A)
#endif
#if GLOBAL_Q == 11
#define   _IQisqrt(A)  _IQ11isqrt(A)
#endif
#if GLOBAL_Q == 10
#define   _IQisqrt(A)  _IQ10isqrt(A)
#endif
#if GLOBAL_Q == 9
#define   _IQisqrt(A)  _IQ9isqrt(A)
#endif
#if GLOBAL_Q == 8
#define   _IQisqrt(A)  _IQ8isqrt(A)
#endif
#if GLOBAL_Q == 7
#define   _IQisqrt(A)  _IQ7isqrt(A)
#endif
#if GLOBAL_Q == 6
#define   _IQisqrt(A)  _IQ6isqrt(A)
#endif
#if GLOBAL_Q == 5
#define   _IQisqrt(A)  _IQ5isqrt(A)
#endif
#if GLOBAL_Q == 4
#define   _IQisqrt(A)  _IQ4isqrt(A)
#endif
#if GLOBAL_Q == 3
#define   _IQisqrt(A)  _IQ3isqrt(A)
#endif
#if GLOBAL_Q == 2
#define   _IQisqrt(A)  _IQ2isqrt(A)
#endif
#if GLOBAL_Q == 1
#define   _IQisqrt(A)  _IQ1isqrt(A)
#endif
//---------------------------------------------------------------------------
extern    long _IQ30exp(long A);
extern    long _IQ29exp(long A);
extern    long _IQ28exp(long A);
extern    long _IQ27exp(long A);
extern    long _IQ26exp(long A);
extern    long _IQ25exp(long A);
extern    long _IQ24exp(long A);
extern    long _IQ23exp(long A);
extern    long _IQ22exp(long A);
extern    long _IQ21exp(long A);
extern    long _IQ20exp(long A);
extern    long _IQ19exp(long A);
extern    long _IQ18exp(long A);
extern    long _IQ17exp(long A);
extern    long _IQ16exp(long A);
extern    long _IQ15exp(long A);
extern    long _IQ14exp(long A);
extern    long _IQ13exp(long A);
extern    long _IQ12exp(long A);
extern    long _IQ11exp(long A);
extern    long _IQ10exp(long A);
extern    long _IQ9exp(long A);
extern    long _IQ8exp(long A);
extern    long _IQ7exp(long A);
extern    long _IQ6exp(long A);
extern    long _IQ5exp(long A);
extern    long _IQ4exp(long A);
extern    long _IQ3exp(long A);
extern    long _IQ2exp(long A);
extern    long _IQ1exp(long A);

#if GLOBAL_Q == 30
#define   _IQexp(A)  _IQ30exp(A)
#endif
#if GLOBAL_Q == 29
#define   _IQexp(A)  _IQ29exp(A)
#endif
#if GLOBAL_Q == 28
#define   _IQexp(A)  _IQ28exp(A)
#endif
#if GLOBAL_Q == 27
#define   _IQexp(A)  _IQ27exp(A)
#endif
#if GLOBAL_Q == 26
#define   _IQexp(A)  _IQ26exp(A)
#endif
#if GLOBAL_Q == 25
#define   _IQexp(A)  _IQ25exp(A)
#endif
#if GLOBAL_Q == 24
#define   _IQexp(A)  _IQ24exp(A)
#endif
#if GLOBAL_Q == 23
#define   _IQexp(A)  _IQ23exp(A)
#endif
#if GLOBAL_Q == 22
#define   _IQexp(A)  _IQ22exp(A)
#endif
#if GLOBAL_Q == 21
#define   _IQexp(A)  _IQ21exp(A)
#endif
#if GLOBAL_Q == 20
#define   _IQexp(A)  _IQ20exp(A)
#endif
#if GLOBAL_Q == 19
#define   _IQexp(A)  _IQ19exp(A)
#endif
#if GLOBAL_Q == 18
#define   _IQexp(A)  _IQ18exp(A)
#endif
#if GLOBAL_Q == 17
#define   _IQexp(A)  _IQ17exp(A)
#endif
#if GLOBAL_Q == 16
#define   _IQexp(A)  _IQ16exp(A)
#endif
#if GLOBAL_Q == 15
#define   _IQexp(A)  _IQ15exp(A)
#endif
#if GLOBAL_Q == 14
#define   _IQexp(A)  _IQ14exp(A)
#endif
#if GLOBAL_Q == 13
#define   _IQexp(A)  _IQ13exp(A)
#endif
#if GLOBAL_Q == 12
#define   _IQexp(A)  _IQ12exp(A)
#endif
#if GLOBAL_Q == 11
#define   _IQexp(A)  _IQ11exp(A)
#endif
#if GLOBAL_Q == 10
#define   _IQexp(A)  _IQ10exp(A)
#endif
#if GLOBAL_Q == 9
#define   _IQexp(A)  _IQ9exp(A)
#endif
#if GLOBAL_Q == 8
#define   _IQexp(A)  _IQ8exp(A)
#endif
#if GLOBAL_Q == 7
#define   _IQexp(A)  _IQ7exp(A)
#endif
#if GLOBAL_Q == 6
#define   _IQexp(A)  _IQ6exp(A)
#endif
#if GLOBAL_Q == 5
#define   _IQexp(A)  _IQ5exp(A)
#endif
#if GLOBAL_Q == 4
#define   _IQexp(A)  _IQ4exp(A)
#endif
#if GLOBAL_Q == 3
#define   _IQexp(A)  _IQ3exp(A)
#endif
#if GLOBAL_Q == 2
#define   _IQexp(A)  _IQ2exp(A)
#endif
#if GLOBAL_Q == 1
#define   _IQexp(A)  _IQ1exp(A)
#endif
//---------------------------------------------------------------------------
extern    long _IQ30int(long A);
extern    long _IQ29int(long A);
extern    long _IQ28int(long A);
extern    long _IQ27int(long A);
extern    long _IQ26int(long A);
extern    long _IQ25int(long A);
extern    long _IQ24int(long A);
extern    long _IQ23int(long A);
extern    long _IQ22int(long A);
extern    long _IQ21int(long A);
extern    long _IQ20int(long A);
extern    long _IQ19int(long A);
extern    long _IQ18int(long A);
extern    long _IQ17int(long A);
extern    long _IQ16int(long A);
extern    long _IQ15int(long A);
extern    long _IQ14int(long A);
extern    long _IQ13int(long A);
extern    long _IQ12int(long A);
extern    long _IQ11int(long A);
extern    long _IQ10int(long A);
extern    long _IQ9int(long A);
extern    long _IQ8int(long A);
extern    long _IQ7int(long A);
extern    long _IQ6int(long A);
extern    long _IQ5int(long A);
extern    long _IQ4int(long A);
extern    long _IQ3int(long A);
extern    long _IQ2int(long A);
extern    long _IQ1int(long A);

#if GLOBAL_Q == 30
#define   _IQint(A)  _IQ30int(A)
#endif
#if GLOBAL_Q == 29
#define   _IQint(A)  _IQ29int(A)
#endif
#if GLOBAL_Q == 28
#define   _IQint(A)  _IQ28int(A)
#endif
#if GLOBAL_Q == 27
#define   _IQint(A)  _IQ27int(A)
#endif
#if GLOBAL_Q == 26
#define   _IQint(A)  _IQ26int(A)
#endif
#if GLOBAL_Q == 25
#define   _IQint(A)  _IQ25int(A)
#endif
#if GLOBAL_Q == 24
#define   _IQint(A)  _IQ24int(A)
#endif
#if GLOBAL_Q == 23
#define   _IQint(A)  _IQ23int(A)
#endif
#if GLOBAL_Q == 22
#define   _IQint(A)  _IQ22int(A)
#endif
#if GLOBAL_Q == 21
#define   _IQint(A)  _IQ21int(A)
#endif
#if GLOBAL_Q == 20
#define   _IQint(A)  _IQ20int(A)
#endif
#if GLOBAL_Q == 19
#define   _IQint(A)  _IQ19int(A)
#endif
#if GLOBAL_Q == 18
#define   _IQint(A)  _IQ18int(A)
#endif
#if GLOBAL_Q == 17
#define   _IQint(A)  _IQ17int(A)
#endif
#if GLOBAL_Q == 16
#define   _IQint(A)  _IQ16int(A)
#endif
#if GLOBAL_Q == 15
#define   _IQint(A)  _IQ15int(A)
#endif
#if GLOBAL_Q == 14
#define   _IQint(A)  _IQ14int(A)
#endif
#if GLOBAL_Q == 13
#define   _IQint(A)  _IQ13int(A)
#endif
#if GLOBAL_Q == 12
#define   _IQint(A)  _IQ12int(A)
#endif
#if GLOBAL_Q == 11
#define   _IQint(A)  _IQ11int(A)
#endif
#if GLOBAL_Q == 10
#define   _IQint(A)  _IQ10int(A)
#endif
#if GLOBAL_Q == 9
#define   _IQint(A)  _IQ9int(A)
#endif
#if GLOBAL_Q == 8
#define   _IQint(A)  _IQ8int(A)
#endif
#if GLOBAL_Q == 7
#define   _IQint(A)  _IQ7int(A)
#endif
#if GLOBAL_Q == 6
#define   _IQint(A)  _IQ6int(A)
#endif
#if GLOBAL_Q == 5
#define   _IQint(A)  _IQ5int(A)
#endif
#if GLOBAL_Q == 4
#define   _IQint(A)  _IQ4int(A)
#endif
#if GLOBAL_Q == 3
#define   _IQint(A)  _IQ3int(A)
#endif
#if GLOBAL_Q == 2
#define   _IQint(A)  _IQ2int(A)
#endif
#if GLOBAL_Q == 1
#define   _IQint(A)  _IQ1int(A)
#endif
//---------------------------------------------------------------------------
extern    long _IQ30frac(long A);
extern    long _IQ29frac(long A);
extern    long _IQ28frac(long A);
extern    long _IQ27frac(long A);
extern    long _IQ26frac(long A);
extern    long _IQ25frac(long A);
extern    long _IQ24frac(long A);
extern    long _IQ23frac(long A);
extern    long _IQ22frac(long A);
extern    long _IQ21frac(long A);
extern    long _IQ20frac(long A);
extern    long _IQ19frac(long A);
extern    long _IQ18frac(long A);
extern    long _IQ17frac(long A);
extern    long _IQ16frac(long A);
extern    long _IQ15frac(long A);
extern    long _IQ14frac(long A);
extern    long _IQ13frac(long A);
extern    long _IQ12frac(long A);
extern    long _IQ11frac(long A);
extern    long _IQ10frac(long A);
extern    long _IQ9frac(long A);
extern    long _IQ8frac(long A);
extern    long _IQ7frac(long A);
extern    long _IQ6frac(long A);
extern    long _IQ5frac(long A);
extern    long _IQ4frac(long A);
extern    long _IQ3frac(long A);
extern    long _IQ2frac(long A);
extern    long _IQ1frac(long A);

#if GLOBAL_Q == 30
#define   _IQfrac(A)  _IQ30frac(A)
#endif
#if GLOBAL_Q == 29
#define   _IQfrac(A)  _IQ29frac(A)
#endif
#if GLOBAL_Q == 28
#define   _IQfrac(A)  _IQ28frac(A)
#endif
#if GLOBAL_Q == 27
#define   _IQfrac(A)  _IQ27frac(A)
#endif
#if GLOBAL_Q == 26
#define   _IQfrac(A)  _IQ26frac(A)
#endif
#if GLOBAL_Q == 25
#define   _IQfrac(A)  _IQ25frac(A)
#endif
#if GLOBAL_Q == 24
#define   _IQfrac(A)  _IQ24frac(A)
#endif
#if GLOBAL_Q == 23
#define   _IQfrac(A)  _IQ23frac(A)
#endif
#if GLOBAL_Q == 22
#define   _IQfrac(A)  _IQ22frac(A)
#endif
#if GLOBAL_Q == 21
#define   _IQfrac(A)  _IQ21frac(A)
#endif
#if GLOBAL_Q == 20
#define   _IQfrac(A)  _IQ20frac(A)
#endif
#if GLOBAL_Q == 19
#define   _IQfrac(A)  _IQ19frac(A)
#endif
#if GLOBAL_Q == 18
#define   _IQfrac(A)  _IQ18frac(A)
#endif
#if GLOBAL_Q == 17
#define   _IQfrac(A)  _IQ17frac(A)
#endif
#if GLOBAL_Q == 16
#define   _IQfrac(A)  _IQ16frac(A)
#endif
#if GLOBAL_Q == 15
#define   _IQfrac(A)  _IQ15frac(A)
#endif
#if GLOBAL_Q == 14
#define   _IQfrac(A)  _IQ14frac(A)
#endif
#if GLOBAL_Q == 13
#define   _IQfrac(A)  _IQ13frac(A)
#endif
#if GLOBAL_Q == 12
#define   _IQfrac(A)  _IQ12frac(A)
#endif
#if GLOBAL_Q == 11
#define   _IQfrac(A)  _IQ11frac(A)
#endif
#if GLOBAL_Q == 10
#define   _IQfrac(A)  _IQ10frac(A)
#endif
#if GLOBAL_Q == 9
#define   _IQfrac(A)  _IQ9frac(A)
#endif
#if GLOBAL_Q == 8
#define   _IQfrac(A)  _IQ8frac(A)
#endif
#if GLOBAL_Q == 7
#define   _IQfrac(A)  _IQ7frac(A)
#endif
#if GLOBAL_Q == 6
#define   _IQfrac(A)  _IQ6frac(A)
#endif
#if GLOBAL_Q == 5
#define   _IQfrac(A)  _IQ5frac(A)
#endif
#if GLOBAL_Q == 4
#define   _IQfrac(A)  _IQ4frac(A)
#endif
#if GLOBAL_Q == 3
#define   _IQfrac(A)  _IQ3frac(A)
#endif
#if GLOBAL_Q == 2
#define   _IQfrac(A)  _IQ2frac(A)
#endif
#if GLOBAL_Q == 1
#define   _IQfrac(A)  _IQ1frac(A)
#endif
//---------------------------------------------------------------------------
#define   _IQmpyIQX(A, IQA, B, IQB)    __IQxmpy(A, B, (GLOBAL_Q + 32 - IQA - IQB))
#define   _IQ30mpyIQX(A, IQA, B, IQB)  __IQxmpy(A, B, (30 + 32 - IQA - IQB))
#define   _IQ29mpyIQX(A, IQA, B, IQB)  __IQxmpy(A, B, (29 + 32 - IQA - IQB))
#define   _IQ28mpyIQX(A, IQA, B, IQB)  __IQxmpy(A, B, (28 + 32 - IQA - IQB))
#define   _IQ27mpyIQX(A, IQA, B, IQB)  __IQxmpy(A, B, (27 + 32 - IQA - IQB))
#define   _IQ26mpyIQX(A, IQA, B, IQB)  __IQxmpy(A, B, (26 + 32 - IQA - IQB))
#define   _IQ25mpyIQX(A, IQA, B, IQB)  __IQxmpy(A, B, (25 + 32 - IQA - IQB))
#define   _IQ24mpyIQX(A, IQA, B, IQB)  __IQxmpy(A, B, (24 + 32 - IQA - IQB))
#define   _IQ23mpyIQX(A, IQA, B, IQB)  __IQxmpy(A, B, (23 + 32 - IQA - IQB))
#define   _IQ22mpyIQX(A, IQA, B, IQB)  __IQxmpy(A, B, (22 + 32 - IQA - IQB))
#define   _IQ21mpyIQX(A, IQA, B, IQB)  __IQxmpy(A, B, (21 + 32 - IQA - IQB))
#define   _IQ20mpyIQX(A, IQA, B, IQB)  __IQxmpy(A, B, (20 + 32 - IQA - IQB))
#define   _IQ19mpyIQX(A, IQA, B, IQB)  __IQxmpy(A, B, (19 + 32 - IQA - IQB))
#define   _IQ18mpyIQX(A, IQA, B, IQB)  __IQxmpy(A, B, (18 + 32 - IQA - IQB))
#define   _IQ17mpyIQX(A, IQA, B, IQB)  __IQxmpy(A, B, (17 + 32 - IQA - IQB))
#define   _IQ16mpyIQX(A, IQA, B, IQB)  __IQxmpy(A, B, (16 + 32 - IQA - IQB))
#define   _IQ15mpyIQX(A, IQA, B, IQB)  __IQxmpy(A, B, (15 + 32 - IQA - IQB))
#define   _IQ14mpyIQX(A, IQA, B, IQB)  __IQxmpy(A, B, (14 + 32 - IQA - IQB))
#define   _IQ13mpyIQX(A, IQA, B, IQB)  __IQxmpy(A, B, (13 + 32 - IQA - IQB))
#define   _IQ12mpyIQX(A, IQA, B, IQB)  __IQxmpy(A, B, (12 + 32 - IQA - IQB))
#define   _IQ11mpyIQX(A, IQA, B, IQB)  __IQxmpy(A, B, (11 + 32 - IQA - IQB))
#define   _IQ10mpyIQX(A, IQA, B, IQB)  __IQxmpy(A, B, (10 + 32 - IQA - IQB))
#define   _IQ9mpyIQX(A, IQA, B, IQB)   __IQxmpy(A, B, (9 + 32 - IQA - IQB))
#define   _IQ8mpyIQX(A, IQA, B, IQB)   __IQxmpy(A, B, (8 + 32 - IQA - IQB))
#define   _IQ7mpyIQX(A, IQA, B, IQB)   __IQxmpy(A, B, (7 + 32 - IQA - IQB))
#define   _IQ6mpyIQX(A, IQA, B, IQB)   __IQxmpy(A, B, (6 + 32 - IQA - IQB))
#define   _IQ5mpyIQX(A, IQA, B, IQB)   __IQxmpy(A, B, (5 + 32 - IQA - IQB))
#define   _IQ4mpyIQX(A, IQA, B, IQB)   __IQxmpy(A, B, (4 + 32 - IQA - IQB))
#define   _IQ3mpyIQX(A, IQA, B, IQB)   __IQxmpy(A, B, (3 + 32 - IQA - IQB))
#define   _IQ2mpyIQX(A, IQA, B, IQB)   __IQxmpy(A, B, (2 + 32 - IQA - IQB))
#define   _IQ1mpyIQX(A, IQA, B, IQB)   __IQxmpy(A, B, (1 + 32 - IQA - IQB))
//---------------------------------------------------------------------------
#define   _IQmpyI32(A,B)    ((A)*(B))
#define   _IQ30mpyI32(A,B)  ((A)*(B))
#define   _IQ29mpyI32(A,B)  ((A)*(B))
#define   _IQ28mpyI32(A,B)  ((A)*(B))
#define   _IQ27mpyI32(A,B)  ((A)*(B))
#define   _IQ26mpyI32(A,B)  ((A)*(B))
#define   _IQ25mpyI32(A,B)  ((A)*(B))
#define   _IQ24mpyI32(A,B)  ((A)*(B))
#define   _IQ23mpyI32(A,B)  ((A)*(B))
#define   _IQ22mpyI32(A,B)  ((A)*(B))
#define   _IQ21mpyI32(A,B)  ((A)*(B))
#define   _IQ20mpyI32(A,B)  ((A)*(B))
#define   _IQ19mpyI32(A,B)  ((A)*(B))
#define   _IQ18mpyI32(A,B)  ((A)*(B))
#define   _IQ17mpyI32(A,B)  ((A)*(B))
#define   _IQ16mpyI32(A,B)  ((A)*(B))
#define   _IQ15mpyI32(A,B)  ((A)*(B))
#define   _IQ14mpyI32(A,B)  ((A)*(B))
#define   _IQ13mpyI32(A,B)  ((A)*(B))
#define   _IQ12mpyI32(A,B)  ((A)*(B))
#define   _IQ11mpyI32(A,B)  ((A)*(B))
#define   _IQ10mpyI32(A,B)  ((A)*(B))
#define   _IQ9mpyI32(A,B)   ((A)*(B))
#define   _IQ8mpyI32(A,B)   ((A)*(B))
#define   _IQ7mpyI32(A,B)   ((A)*(B))
#define   _IQ6mpyI32(A,B)   ((A)*(B))
#define   _IQ5mpyI32(A,B)   ((A)*(B))
#define   _IQ4mpyI32(A,B)   ((A)*(B))
#define   _IQ3mpyI32(A,B)   ((A)*(B))
#define   _IQ2mpyI32(A,B)   ((A)*(B))
#define   _IQ1mpyI32(A,B)   ((A)*(B))
//---------------------------------------------------------------------------
extern    long _IQ30mpyI32int(long A, long B);
extern    long _IQ29mpyI32int(long A, long B);
extern    long _IQ28mpyI32int(long A, long B);
extern    long _IQ27mpyI32int(long A, long B);
extern    long _IQ26mpyI32int(long A, long B);
extern    long _IQ25mpyI32int(long A, long B);
extern    long _IQ24mpyI32int(long A, long B);
extern    long _IQ23mpyI32int(long A, long B);
extern    long _IQ22mpyI32int(long A, long B);
extern    long _IQ21mpyI32int(long A, long B);
extern    long _IQ20mpyI32int(long A, long B);
extern    long _IQ19mpyI32int(long A, long B);
extern    long _IQ18mpyI32int(long A, long B);
extern    long _IQ17mpyI32int(long A, long B);
extern    long _IQ16mpyI32int(long A, long B);
extern    long _IQ15mpyI32int(long A, long B);
extern    long _IQ14mpyI32int(long A, long B);
extern    long _IQ13mpyI32int(long A, long B);
extern    long _IQ12mpyI32int(long A, long B);
extern    long _IQ11mpyI32int(long A, long B);
extern    long _IQ10mpyI32int(long A, long B);
extern    long _IQ9mpyI32int(long A, long B);
extern    long _IQ8mpyI32int(long A, long B);
extern    long _IQ7mpyI32int(long A, long B);
extern    long _IQ6mpyI32int(long A, long B);
extern    long _IQ5mpyI32int(long A, long B);
extern    long _IQ4mpyI32int(long A, long B);
extern    long _IQ3mpyI32int(long A, long B);
extern    long _IQ2mpyI32int(long A, long B);
extern    long _IQ1mpyI32int(long A, long B);

#if GLOBAL_Q == 30
#define   _IQmpyI32int(A, B)  _IQ30mpyI32int(A, B)
#endif
#if GLOBAL_Q == 29
#define   _IQmpyI32int(A, B)  _IQ29mpyI32int(A, B)
#endif
#if GLOBAL_Q == 28
#define   _IQmpyI32int(A, B)  _IQ28mpyI32int(A, B)
#endif
#if GLOBAL_Q == 27
#define   _IQmpyI32int(A, B)  _IQ27mpyI32int(A, B)
#endif
#if GLOBAL_Q == 26
#define   _IQmpyI32int(A, B)  _IQ26mpyI32int(A, B)
#endif
#if GLOBAL_Q == 25
#define   _IQmpyI32int(A, B)  _IQ25mpyI32int(A, B)
#endif
#if GLOBAL_Q == 24
#define   _IQmpyI32int(A, B)  _IQ24mpyI32int(A, B)
#endif
#if GLOBAL_Q == 23
#define   _IQmpyI32int(A, B)  _IQ23mpyI32int(A, B)
#endif
#if GLOBAL_Q == 22
#define   _IQmpyI32int(A, B)  _IQ22mpyI32int(A, B)
#endif
#if GLOBAL_Q == 21
#define   _IQmpyI32int(A, B)  _IQ21mpyI32int(A, B)
#endif
#if GLOBAL_Q == 20
#define   _IQmpyI32int(A, B)  _IQ20mpyI32int(A, B)
#endif
#if GLOBAL_Q == 19
#define   _IQmpyI32int(A, B)  _IQ19mpyI32int(A, B)
#endif
#if GLOBAL_Q == 18
#define   _IQmpyI32int(A, B)  _IQ18mpyI32int(A, B)
#endif
#if GLOBAL_Q == 17
#define   _IQmpyI32int(A, B)  _IQ17mpyI32int(A, B)
#endif
#if GLOBAL_Q == 16
#define   _IQmpyI32int(A, B)  _IQ16mpyI32int(A, B)
#endif
#if GLOBAL_Q == 15
#define   _IQmpyI32int(A, B)  _IQ15mpyI32int(A, B)
#endif
#if GLOBAL_Q == 14
#define   _IQmpyI32int(A, B)  _IQ14mpyI32int(A, B)
#endif
#if GLOBAL_Q == 13
#define   _IQmpyI32int(A, B)  _IQ13mpyI32int(A, B)
#endif
#if GLOBAL_Q == 12
#define   _IQmpyI32int(A, B)  _IQ12mpyI32int(A, B)
#endif
#if GLOBAL_Q == 11
#define   _IQmpyI32int(A, B)  _IQ11mpyI32int(A, B)
#endif
#if GLOBAL_Q == 10
#define   _IQmpyI32int(A, B)  _IQ10mpyI32int(A, B)
#endif
#if GLOBAL_Q == 9
#define   _IQmpyI32int(A, B)  _IQ9mpyI32int(A, B)
#endif
#if GLOBAL_Q == 8
#define   _IQmpyI32int(A, B)  _IQ8mpyI32int(A, B)
#endif
#if GLOBAL_Q == 7
#define   _IQmpyI32int(A, B)  _IQ7mpyI32int(A, B)
#endif
#if GLOBAL_Q == 6
#define   _IQmpyI32int(A, B)  _IQ6mpyI32int(A, B)
#endif
#if GLOBAL_Q == 5
#define   _IQmpyI32int(A, B)  _IQ5mpyI32int(A, B)
#endif
#if GLOBAL_Q == 4
#define   _IQmpyI32int(A, B)  _IQ4mpyI32int(A, B)
#endif
#if GLOBAL_Q == 3
#define   _IQmpyI32int(A, B)  _IQ3mpyI32int(A, B)
#endif
#if GLOBAL_Q == 2
#define   _IQmpyI32int(A, B)  _IQ2mpyI32int(A, B)
#endif
#if GLOBAL_Q == 1
#define   _IQmpyI32int(A, B)  _IQ1mpyI32int(A, B)
#endif
//---------------------------------------------------------------------------
extern    long _IQ30mpyI32frac(long A, long B);
extern    long _IQ29mpyI32frac(long A, long B);
extern    long _IQ28mpyI32frac(long A, long B);
extern    long _IQ27mpyI32frac(long A, long B);
extern    long _IQ26mpyI32frac(long A, long B);
extern    long _IQ25mpyI32frac(long A, long B);
extern    long _IQ24mpyI32frac(long A, long B);
extern    long _IQ23mpyI32frac(long A, long B);
extern    long _IQ22mpyI32frac(long A, long B);
extern    long _IQ21mpyI32frac(long A, long B);
extern    long _IQ20mpyI32frac(long A, long B);
extern    long _IQ19mpyI32frac(long A, long B);
extern    long _IQ18mpyI32frac(long A, long B);
extern    long _IQ17mpyI32frac(long A, long B);
extern    long _IQ16mpyI32frac(long A, long B);
extern    long _IQ15mpyI32frac(long A, long B);
extern    long _IQ14mpyI32frac(long A, long B);
extern    long _IQ13mpyI32frac(long A, long B);
extern    long _IQ12mpyI32frac(long A, long B);
extern    long _IQ11mpyI32frac(long A, long B);
extern    long _IQ10mpyI32frac(long A, long B);
extern    long _IQ9mpyI32frac(long A, long B);
extern    long _IQ8mpyI32frac(long A, long B);
extern    long _IQ7mpyI32frac(long A, long B);
extern    long _IQ6mpyI32frac(long A, long B);
extern    long _IQ5mpyI32frac(long A, long B);
extern    long _IQ4mpyI32frac(long A, long B);
extern    long _IQ3mpyI32frac(long A, long B);
extern    long _IQ2mpyI32frac(long A, long B);
extern    long _IQ1mpyI32frac(long A, long B);

#if GLOBAL_Q == 30
#define   _IQmpyI32frac(A, B)  _IQ30mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 29
#define   _IQmpyI32frac(A, B)  _IQ29mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 28
#define   _IQmpyI32frac(A, B)  _IQ28mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 27
#define   _IQmpyI32frac(A, B)  _IQ27mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 26
#define   _IQmpyI32frac(A, B)  _IQ26mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 25
#define   _IQmpyI32frac(A, B)  _IQ25mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 24
#define   _IQmpyI32frac(A, B)  _IQ24mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 23
#define   _IQmpyI32frac(A, B)  _IQ23mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 22
#define   _IQmpyI32frac(A, B)  _IQ22mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 21
#define   _IQmpyI32frac(A, B)  _IQ21mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 20
#define   _IQmpyI32frac(A, B)  _IQ20mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 19
#define   _IQmpyI32frac(A, B)  _IQ19mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 18
#define   _IQmpyI32frac(A, B)  _IQ18mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 17
#define   _IQmpyI32frac(A, B)  _IQ17mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 16
#define   _IQmpyI32frac(A, B)  _IQ16mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 15
#define   _IQmpyI32frac(A, B)  _IQ15mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 14
#define   _IQmpyI32frac(A, B)  _IQ14mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 13
#define   _IQmpyI32frac(A, B)  _IQ13mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 12
#define   _IQmpyI32frac(A, B)  _IQ12mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 11
#define   _IQmpyI32frac(A, B)  _IQ11mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 10
#define   _IQmpyI32frac(A, B)  _IQ10mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 9
#define   _IQmpyI32frac(A, B)  _IQ9mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 8
#define   _IQmpyI32frac(A, B)  _IQ8mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 7
#define   _IQmpyI32frac(A, B)  _IQ7mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 6
#define   _IQmpyI32frac(A, B)  _IQ6mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 5
#define   _IQmpyI32frac(A, B)  _IQ5mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 4
#define   _IQmpyI32frac(A, B)  _IQ4mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 3
#define   _IQmpyI32frac(A, B)  _IQ3mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 2
#define   _IQmpyI32frac(A, B)  _IQ2mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 1
#define   _IQmpyI32frac(A, B)  _IQ1mpyI32frac(A, B)
#endif
//---------------------------------------------------------------------------
extern    long _IQ30mag(long A, long B);
extern    long _IQ29mag(long A, long B);
extern    long _IQ28mag(long A, long B);
extern    long _IQ27mag(long A, long B);
extern    long _IQ26mag(long A, long B);
extern    long _IQ25mag(long A, long B);
extern    long _IQ24mag(long A, long B);
extern    long _IQ23mag(long A, long B);
extern    long _IQ22mag(long A, long B);
extern    long _IQ21mag(long A, long B);
extern    long _IQ20mag(long A, long B);
extern    long _IQ19mag(long A, long B);
extern    long _IQ18mag(long A, long B);
extern    long _IQ17mag(long A, long B);
extern    long _IQ16mag(long A, long B);
extern    long _IQ15mag(long A, long B);
extern    long _IQ14mag(long A, long B);
extern    long _IQ13mag(long A, long B);
extern    long _IQ12mag(long A, long B);
extern    long _IQ11mag(long A, long B);
extern    long _IQ10mag(long A, long B);
extern    long _IQ9mag(long A, long B);
extern    long _IQ8mag(long A, long B);
extern    long _IQ7mag(long A, long B);
extern    long _IQ6mag(long A, long B);
extern    long _IQ5mag(long A, long B);
extern    long _IQ4mag(long A, long B);
extern    long _IQ3mag(long A, long B);
extern    long _IQ2mag(long A, long B);
extern    long _IQ1mag(long A, long B);

#if GLOBAL_Q == 30
#define   _IQmag(A, B)  _IQ30mag(A, B)
#endif
#if GLOBAL_Q == 29
#define   _IQmag(A, B)  _IQ29mag(A, B)
#endif
#if GLOBAL_Q == 28
#define   _IQmag(A, B)  _IQ28mag(A, B)
#endif
#if GLOBAL_Q == 27
#define   _IQmag(A, B)  _IQ27mag(A, B)
#endif
#if GLOBAL_Q == 26
#define   _IQmag(A, B)  _IQ26mag(A, B)
#endif
#if GLOBAL_Q == 25
#define   _IQmag(A, B)  _IQ25mag(A, B)
#endif
#if GLOBAL_Q == 24
#define   _IQmag(A, B)  _IQ24mag(A, B)
#endif
#if GLOBAL_Q == 23
#define   _IQmag(A, B)  _IQ23mag(A, B)
#endif
#if GLOBAL_Q == 22
#define   _IQmag(A, B)  _IQ22mag(A, B)
#endif
#if GLOBAL_Q == 21
#define   _IQmag(A, B)  _IQ21mag(A, B)
#endif
#if GLOBAL_Q == 20
#define   _IQmag(A, B)  _IQ20mag(A, B)
#endif
#if GLOBAL_Q == 19
#define   _IQmag(A, B)  _IQ19mag(A, B)
#endif
#if GLOBAL_Q == 18
#define   _IQmag(A, B)  _IQ18mag(A, B)
#endif
#if GLOBAL_Q == 17
#define   _IQmag(A, B)  _IQ17mag(A, B)
#endif
#if GLOBAL_Q == 16
#define   _IQmag(A, B)  _IQ16mag(A, B)
#endif
#if GLOBAL_Q == 15
#define   _IQmag(A, B)  _IQ15mag(A, B)
#endif
#if GLOBAL_Q == 14
#define   _IQmag(A, B)  _IQ14mag(A, B)
#endif
#if GLOBAL_Q == 13
#define   _IQmag(A, B)  _IQ13mag(A, B)
#endif
#if GLOBAL_Q == 12
#define   _IQmag(A, B)  _IQ12mag(A, B)
#endif
#if GLOBAL_Q == 11
#define   _IQmag(A, B)  _IQ11mag(A, B)
#endif
#if GLOBAL_Q == 10
#define   _IQmag(A, B)  _IQ10mag(A, B)
#endif
#if GLOBAL_Q == 9
#define   _IQmag(A, B)  _IQ9mag(A, B)
#endif
#if GLOBAL_Q == 8
#define   _IQmag(A, B)  _IQ8mag(A, B)
#endif
#if GLOBAL_Q == 7
#define   _IQmag(A, B)  _IQ7mag(A, B)
#endif
#if GLOBAL_Q == 6
#define   _IQmag(A, B)  _IQ6mag(A, B)
#endif
#if GLOBAL_Q == 5
#define   _IQmag(A, B)  _IQ5mag(A, B)
#endif
#if GLOBAL_Q == 4
#define   _IQmag(A, B)  _IQ4mag(A, B)
#endif
#if GLOBAL_Q == 3
#define   _IQmag(A, B)  _IQ3mag(A, B)
#endif
#if GLOBAL_Q == 2
#define   _IQmag(A, B)  _IQ2mag(A, B)
#endif
#if GLOBAL_Q == 1
#define   _IQmag(A, B)  _IQ1mag(A, B)
#endif
//---------------------------------------------------------------------------
extern    long _atoIQN(const char *A, long q_value);
#define   _atoIQ(A)    _atoIQN(A, GLOBAL_Q)
#define   _atoIQ30(A)  _atoIQN(A, 30)
#define   _atoIQ29(A)  _atoIQN(A, 29)
#define   _atoIQ28(A)  _atoIQN(A, 28)
#define   _atoIQ27(A)  _atoIQN(A, 27)
#define   _atoIQ26(A)  _atoIQN(A, 26)
#define   _atoIQ25(A)  _atoIQN(A, 25)
#define   _atoIQ24(A)  _atoIQN(A, 24)
#define   _atoIQ23(A)  _atoIQN(A, 23)
#define   _atoIQ22(A)  _atoIQN(A, 22)
#define   _atoIQ21(A)  _atoIQN(A, 21)
#define   _atoIQ20(A)  _atoIQN(A, 20)
#define   _atoIQ19(A)  _atoIQN(A, 19)
#define   _atoIQ18(A)  _atoIQN(A, 18)
#define   _atoIQ17(A)  _atoIQN(A, 17)
#define   _atoIQ16(A)  _atoIQN(A, 16)
#define   _atoIQ15(A)  _atoIQN(A, 15)
#define   _atoIQ14(A)  _atoIQN(A, 14)
#define   _atoIQ13(A)  _atoIQN(A, 13)
#define   _atoIQ12(A)  _atoIQN(A, 12)
#define   _atoIQ11(A)  _atoIQN(A, 11)
#define   _atoIQ10(A)  _atoIQN(A, 10)
#define   _atoIQ9(A)   _atoIQN(A, 9)
#define   _atoIQ8(A)   _atoIQN(A, 8)
#define   _atoIQ7(A)   _atoIQN(A, 7)
#define   _atoIQ6(A)   _atoIQN(A, 6)
#define   _atoIQ5(A)   _atoIQN(A, 5)
#define   _atoIQ4(A)   _atoIQN(A, 4)
#define   _atoIQ3(A)   _atoIQN(A, 3)
#define   _atoIQ2(A)   _atoIQN(A, 2)
#define   _atoIQ1(A)   _atoIQN(A, 1)
//---------------------------------------------------------------------------
extern    int __IQNtoa(char *A, const char *B, long C, int D);
extern    int _IQ30toa(char *A, const char *B, long C);
extern    int _IQ29toa(char *A, const char *B, long C);
extern    int _IQ28toa(char *A, const char *B, long C);
extern    int _IQ27toa(char *A, const char *B, long C);
extern    int _IQ26toa(char *A, const char *B, long C);
extern    int _IQ25toa(char *A, const char *B, long C);
extern    int _IQ24toa(char *A, const char *B, long C);
extern    int _IQ23toa(char *A, const char *B, long C);
extern    int _IQ22toa(char *A, const char *B, long C);
extern    int _IQ21toa(char *A, const char *B, long C);
extern    int _IQ20toa(char *A, const char *B, long C);
extern    int _IQ19toa(char *A, const char *B, long C);
extern    int _IQ18toa(char *A, const char *B, long C);
extern    int _IQ17toa(char *A, const char *B, long C);
extern    int _IQ16toa(char *A, const char *B, long C);
extern    int _IQ15toa(char *A, const char *B, long C);
extern    int _IQ14toa(char *A, const char *B, long C);
extern    int _IQ13toa(char *A, const char *B, long C);
extern    int _IQ12toa(char *A, const char *B, long C);
extern    int _IQ11toa(char *A, const char *B, long C);
extern    int _IQ10toa(char *A, const char *B, long C);
extern    int  _IQ9toa(char *A, const char *B, long C);
extern    int  _IQ8toa(char *A, const char *B, long C);
extern    int  _IQ7toa(char *A, const char *B, long C);
extern    int  _IQ6toa(char *A, const char *B, long C);
extern    int  _IQ5toa(char *A, const char *B, long C);
extern    int  _IQ4toa(char *A, const char *B, long C);
extern    int  _IQ3toa(char *A, const char *B, long C);
extern    int  _IQ2toa(char *A, const char *B, long C);
extern    int  _IQ1toa(char *A, const char *B, long C);


#define   _IQ30toa(A, B, C)   __IQNtoa(A, B, C, 30);
#define   _IQ29toa(A, B, C)   __IQNtoa(A, B, C, 29);
#define   _IQ28toa(A, B, C)   __IQNtoa(A, B, C, 28);
#define   _IQ27toa(A, B, C)   __IQNtoa(A, B, C, 27);
#define   _IQ26toa(A, B, C)   __IQNtoa(A, B, C, 26);
#define   _IQ25toa(A, B, C)   __IQNtoa(A, B, C, 25);
#define   _IQ24toa(A, B, C)   __IQNtoa(A, B, C, 24);
#define   _IQ23toa(A, B, C)   __IQNtoa(A, B, C, 23);
#define   _IQ21toa(A, B, C)   __IQNtoa(A, B, C, 21);
#define   _IQ22toa(A, B, C)   __IQNtoa(A, B, C, 22);
#define   _IQ20toa(A, B, C)   __IQNtoa(A, B, C, 20);
#define   _IQ19toa(A, B, C)   __IQNtoa(A, B, C, 19);
#define   _IQ18toa(A, B, C)   __IQNtoa(A, B, C, 18);
#define   _IQ17toa(A, B, C)   __IQNtoa(A, B, C, 17);
#define   _IQ16toa(A, B, C)   __IQNtoa(A, B, C, 16);
#define   _IQ15toa(A, B, C)   __IQNtoa(A, B, C, 15);
#define   _IQ14toa(A, B, C)   __IQNtoa(A, B, C, 14);
#define   _IQ13toa(A, B, C)   __IQNtoa(A, B, C, 13);
#define   _IQ12toa(A, B, C)   __IQNtoa(A, B, C, 12);
#define   _IQ11toa(A, B, C)   __IQNtoa(A, B, C, 11);
#define   _IQ10toa(A, B, C)   __IQNtoa(A, B, C, 10);
#define   _IQ9toa(A, B, C)    __IQNtoa(A, B, C, 9);
#define   _IQ8toa(A, B, C)    __IQNtoa(A, B, C, 8);
#define   _IQ7toa(A, B, C)    __IQNtoa(A, B, C, 7);
#define   _IQ6toa(A, B, C)    __IQNtoa(A, B, C, 6);
#define   _IQ5toa(A, B, C)    __IQNtoa(A, B, C, 5);
#define   _IQ4toa(A, B, C)    __IQNtoa(A, B, C, 4);
#define   _IQ3toa(A, B, C)    __IQNtoa(A, B, C, 3);
#define   _IQ2toa(A, B, C)    __IQNtoa(A, B, C, 2);
#define   _IQ1toa(A, B, C)    __IQNtoa(A, B, C, 1);


#if GLOBAL_Q == 30
#define   _IQtoa(A, B, C)     __IQNtoa(A, B, C, 30)
#endif
#if GLOBAL_Q == 29
#define   _IQtoa(A, B, C)     __IQNtoa(A, B, C, 29)
#endif
#if GLOBAL_Q == 28
#define   _IQtoa(A, B, C)     __IQNtoa(A, B, C, 28)
#endif
#if GLOBAL_Q == 27
#define   _IQtoa(A, B, C)     __IQNtoa(A, B, C, 27)
#endif
#if GLOBAL_Q == 26
#define   _IQtoa(A, B, C)     __IQNtoa(A, B, C, 26)
#endif
#if GLOBAL_Q == 25
#define   _IQtoa(A, B, C)     __IQNtoa(A, B, C, 25)
#endif
#if GLOBAL_Q == 24
#define   _IQtoa(A, B, C)     __IQNtoa(A, B, C, 24)
#endif
#if GLOBAL_Q == 23
#define   _IQtoa(A, B, C)     __IQNtoa(A, B, C, 23)
#endif
#if GLOBAL_Q == 22
#define   _IQtoa(A, B, C)     __IQNtoa(A, B, C, 22)
#endif
#if GLOBAL_Q == 21
#define   _IQtoa(A, B, C)     __IQNtoa(A, B, C, 21)
#endif
#if GLOBAL_Q == 20
#define   _IQtoa(A, B, C)     __IQNtoa(A, B, C, 20)
#endif
#if GLOBAL_Q == 19
#define   _IQtoa(A, B, C)     __IQNtoa(A, B, C, 19)
#endif
#if GLOBAL_Q == 18
#define   _IQtoa(A, B, C)     __IQNtoa(A, B, C, 18)
#endif
#if GLOBAL_Q == 17
#define   _IQtoa(A, B, C)     __IQNtoa(A, B, C, 17)
#endif
#if GLOBAL_Q == 16
#define   _IQtoa(A, B, C)     __IQNtoa(A, B, C, 16)
#endif
#if GLOBAL_Q == 15
#define   _IQtoa(A, B, C)     __IQNtoa(A, B, C, 15)
#endif
#if GLOBAL_Q == 14
#define   _IQtoa(A, B, C)     __IQNtoa(A, B, C, 14)
#endif
#if GLOBAL_Q == 13
#define   _IQtoa(A, B, C)     __IQNtoa(A, B, C, 13)
#endif
#if GLOBAL_Q == 12
#define   _IQtoa(A, B, C)     __IQNtoa(A, B, C, 12)
#endif
#if GLOBAL_Q == 11
#define   _IQtoa(A, B, C)     __IQNtoa(A, B, C, 11)
#endif
#if GLOBAL_Q == 10
#define   _IQtoa(A, B, C)     __IQNtoa(A, B, C, 10)
#endif
#if GLOBAL_Q == 9
#define   _IQtoa(A, B, C)     __IQNtoa(A, B, C, 9)
#endif
#if GLOBAL_Q == 8
#define   _IQtoa(A, B, C)     __IQNtoa(A, B, C, 8)
#endif
#if GLOBAL_Q == 7
#define   _IQtoa(A, B, C)     __IQNtoa(A, B, C, 7)
#endif
#if GLOBAL_Q == 6
#define   _IQtoa(A, B, C)     __IQNtoa(A, B, C, 6)
#endif
#if GLOBAL_Q == 5
#define   _IQtoa(A, B, C)     __IQNtoa(A, B, C, 5)
#endif
#if GLOBAL_Q == 4
#define   _IQtoa(A, B, C)     __IQNtoa(A, B, C, 4)
#endif
#if GLOBAL_Q == 3
#define   _IQtoa(A, B, C)     __IQNtoa(A, B, C, 3)
#endif
#if GLOBAL_Q == 2
#define   _IQtoa(A, B, C)     __IQNtoa(A, B, C, 2)
#endif
#if GLOBAL_Q == 1
#define   _IQtoa(A, B, C)     __IQNtoa(A, B, C, 1)
#endif
//---------------------------------------------------------------------------
#define   _IQabs(A)    labs(A)
#define   _IQ30abs(A)  labs(A)
#define   _IQ29abs(A)  labs(A)
#define   _IQ28abs(A)  labs(A)
#define   _IQ27abs(A)  labs(A)
#define   _IQ26abs(A)  labs(A)
#define   _IQ25abs(A)  labs(A)
#define   _IQ24abs(A)  labs(A)
#define   _IQ23abs(A)  labs(A)
#define   _IQ22abs(A)  labs(A)
#define   _IQ21abs(A)  labs(A)
#define   _IQ20abs(A)  labs(A)
#define   _IQ19abs(A)  labs(A)
#define   _IQ18abs(A)  labs(A)
#define   _IQ17abs(A)  labs(A)
#define   _IQ16abs(A)  labs(A)
#define   _IQ15abs(A)  labs(A)
#define   _IQ14abs(A)  labs(A)
#define   _IQ13abs(A)  labs(A)
#define   _IQ12abs(A)  labs(A)
#define   _IQ11abs(A)  labs(A)
#define   _IQ10abs(A)  labs(A)
#define   _IQ9abs(A)   labs(A)
#define   _IQ8abs(A)   labs(A)
#define   _IQ7abs(A)   labs(A)
#define   _IQ6abs(A)   labs(A)
#define   _IQ5abs(A)   labs(A)
#define   _IQ4abs(A)   labs(A)
#define   _IQ3abs(A)   labs(A)
#define   _IQ2abs(A)   labs(A)
#define   _IQ1abs(A)   labs(A)
//###########################################################################
#else   // MATH_TYPE == FLOAT_MATH
//###########################################################################
// If FLOAT_MATH is used, the IQmath library function are replaced by
// equivalent floating point operations:
//===========================================================================
typedef   float   _iq;
typedef   float   _iq30;
typedef   float   _iq29;
typedef   float   _iq28;
typedef   float   _iq27;
typedef   float   _iq26;
typedef   float   _iq25;
typedef   float   _iq24;
typedef   float   _iq23;
typedef   float   _iq22;
typedef   float   _iq21;
typedef   float   _iq20;
typedef   float   _iq19;
typedef   float   _iq18;
typedef   float   _iq17;
typedef   float   _iq16;
typedef   float   _iq15;
typedef   float   _iq14;
typedef   float   _iq13;
typedef   float   _iq12;
typedef   float   _iq11;
typedef   float   _iq10;
typedef   float   _iq9;
typedef   float   _iq8;
typedef   float   _iq7;
typedef   float   _iq6;
typedef   float   _iq5;
typedef   float   _iq4;
typedef   float   _iq3;
typedef   float   _iq2;
typedef   float   _iq1;
//---------------------------------------------------------------------------
#define   _IQ(A)         (A)
#define   _IQ30(A)       (A)
#define   _IQ29(A)       (A)
#define   _IQ28(A)       (A)
#define   _IQ27(A)       (A)
#define   _IQ26(A)       (A)
#define   _IQ25(A)       (A)
#define   _IQ24(A)       (A)
#define   _IQ23(A)       (A)
#define   _IQ22(A)       (A)
#define   _IQ21(A)       (A)
#define   _IQ20(A)       (A)
#define   _IQ19(A)       (A)
#define   _IQ18(A)       (A)
#define   _IQ17(A)       (A)
#define   _IQ16(A)       (A)
#define   _IQ15(A)       (A)
#define   _IQ14(A)       (A)
#define   _IQ13(A)       (A)
#define   _IQ12(A)       (A)
#define   _IQ10(A)       (A)
#define   _IQ9(A)        (A)
#define   _IQ8(A)        (A)
#define   _IQ7(A)        (A)
#define   _IQ6(A)        (A)
#define   _IQ5(A)        (A)
#define   _IQ4(A)        (A)
#define   _IQ3(A)        (A)
#define   _IQ2(A)        (A)
#define   _IQ1(A)        (A)
//---------------------------------------------------------------------------
#define   _IQtoF(A)      (A)
#define   _IQ30toF(A)    (A)
#define   _IQ29toF(A)    (A)
#define   _IQ28toF(A)    (A)
#define   _IQ27toF(A)    (A)
#define   _IQ26toF(A)    (A)
#define   _IQ25toF(A)    (A)
#define   _IQ24toF(A)    (A)
#define   _IQ23toF(A)    (A)
#define   _IQ22toF(A)    (A)
#define   _IQ21toF(A)    (A)
#define   _IQ20toF(A)    (A)
#define   _IQ19toF(A)    (A)
#define   _IQ18toF(A)    (A)
#define   _IQ17toF(A)    (A)
#define   _IQ16toF(A)    (A)
#define   _IQ15toF(A)    (A)
#define   _IQ14toF(A)    (A)
#define   _IQ13toF(A)    (A)
#define   _IQ12toF(A)    (A)
#define   _IQ11toF(A)    (A)
#define   _IQ10toF(A)    (A)
#define   _IQ9toF(A)     (A)
#define   _IQ8toF(A)     (A)
#define   _IQ7toF(A)     (A)
#define   _IQ6toF(A)     (A)
#define   _IQ5toF(A)     (A)
#define   _IQ4toF(A)     (A)
#define   _IQ3toF(A)     (A)
#define   _IQ2toF(A)     (A)
#define   _IQ1toF(A)     (A)
//---------------------------------------------------------------------------
extern  float _satf(float A, float Pos, float Neg);
#define   _IQsat(A, Pos, Neg)    _satf(A, Pos, Neg)
//---------------------------------------------------------------------------
#define   _IQtoIQ30(A)   (A)
#define   _IQtoIQ29(A)   (A)
#define   _IQtoIQ28(A)   (A)
#define   _IQtoIQ27(A)   (A)
#define   _IQtoIQ26(A)   (A)
#define   _IQtoIQ25(A)   (A)
#define   _IQtoIQ24(A)   (A)
#define   _IQtoIQ23(A)   (A)
#define   _IQtoIQ22(A)   (A)
#define   _IQtoIQ21(A)   (A)
#define   _IQtoIQ20(A)   (A)
#define   _IQtoIQ19(A)   (A)
#define   _IQtoIQ18(A)   (A)
#define   _IQtoIQ17(A)   (A)
#define   _IQtoIQ16(A)   (A)
#define   _IQtoIQ15(A)   (A)
#define   _IQtoIQ14(A)   (A)
#define   _IQtoIQ13(A)   (A)
#define   _IQtoIQ12(A)   (A)
#define   _IQtoIQ11(A)   (A)
#define   _IQtoIQ10(A)   (A)
#define   _IQtoIQ9(A)    (A)
#define   _IQtoIQ8(A)    (A)
#define   _IQtoIQ7(A)    (A)
#define   _IQtoIQ6(A)    (A)
#define   _IQtoIQ5(A)    (A)
#define   _IQtoIQ4(A)    (A)
#define   _IQtoIQ3(A)    (A)
#define   _IQtoIQ2(A)    (A)
#define   _IQtoIQ1(A)    (A)
//---------------------------------------------------------------------------
#define   _IQ30toIQ(A)   (A)
#define   _IQ29toIQ(A)   (A)
#define   _IQ28toIQ(A)   (A)
#define   _IQ27toIQ(A)   (A)
#define   _IQ26toIQ(A)   (A)
#define   _IQ25toIQ(A)   (A)
#define   _IQ24toIQ(A)   (A)
#define   _IQ23toIQ(A)   (A)
#define   _IQ22toIQ(A)   (A)
#define   _IQ21toIQ(A)   (A)
#define   _IQ20toIQ(A)   (A)
#define   _IQ19toIQ(A)   (A)
#define   _IQ18toIQ(A)   (A)
#define   _IQ17toIQ(A)   (A)
#define   _IQ16toIQ(A)   (A)
#define   _IQ15toIQ(A)   (A)
#define   _IQ14toIQ(A)   (A)
#define   _IQ13toIQ(A)   (A)
#define   _IQ12toIQ(A)   (A)
#define   _IQ11toIQ(A)   (A)
#define   _IQ10toIQ(A)   (A)
#define   _IQ9toIQ(A)    (A)
#define   _IQ8toIQ(A)    (A)
#define   _IQ7toIQ(A)    (A)
#define   _IQ6toIQ(A)    (A)
#define   _IQ5toIQ(A)    (A)
#define   _IQ4toIQ(A)    (A)
#define   _IQ3toIQ(A)    (A)
#define   _IQ2toIQ(A)    (A)
#define   _IQ1toIQ(A)    (A)
//---------------------------------------------------------------------------
#define   _IQtoQ15(A)    (short) ((long)((A) * 32768.0L))
#define   _IQtoQ14(A)    (short) ((long)((A) * 16384.0L))
#define   _IQtoQ13(A)    (short) ((long)((A) * 8192.0L))
#define   _IQtoQ12(A)    (short) ((long)((A) * 4096.0L))
#define   _IQtoQ11(A)    (short) ((long)((A) * 2048.0L))
#define   _IQtoQ10(A)    (short) ((long)((A) * 1024.0L))
#define   _IQtoQ9(A)     (short) ((long)((A) * 512.0L))
#define   _IQtoQ8(A)     (short) ((long)((A) * 256.0L))
#define   _IQtoQ7(A)     (short) ((long)((A) * 128.0L))
#define   _IQtoQ6(A)     (short) ((long)((A) * 64.0L))
#define   _IQtoQ5(A)     (short) ((long)((A) * 32.0L))
#define   _IQtoQ4(A)     (short) ((long)((A) * 16.0L))
#define   _IQtoQ3(A)     (short) ((long)((A) * 8.0L))
#define   _IQtoQ2(A)     (short) ((long)((A) * 4.0L))
#define   _IQtoQ1(A)     (short) ((long)((A) * 2.0L))

//---------------------------------------------------------------------------
#define   _Q15toIQ(A)    (((float) (A)) * 0.000030518)
#define   _Q14toIQ(A)    (((float) (A)) * 0.000061035)
#define   _Q13toIQ(A)    (((float) (A)) * 0.000122070)
#define   _Q12toIQ(A)    (((float) (A)) * 0.000244141)
#define   _Q11toIQ(A)    (((float) (A)) * 0.000488281)
#define   _Q10toIQ(A)    (((float) (A)) * 0.000976563)
#define   _Q9toIQ(A)     (((float) (A)) * 0.001953125)
#define   _Q8toIQ(A)     (((float) (A)) * 0.003906250)
#define   _Q7toIQ(A)     (((float) (A)) * 0.007812500)
#define   _Q6toIQ(A)     (((float) (A)) * 0.015625000)
#define   _Q5toIQ(A)     (((float) (A)) * 0.031250000)
#define   _Q4toIQ(A)     (((float) (A)) * 0.062500000)
#define   _Q3toIQ(A)     (((float) (A)) * 0.125000000)
#define   _Q2toIQ(A)     (((float) (A)) * 0.250000000)
#define   _Q1toIQ(A)     (((float) (A)) * 0.500000000)
//---------------------------------------------------------------------------
#define   _IQmpy(A,B)         ((A) * (B))
#define   _IQ30mpy(A,B)       ((A) * (B))
#define   _IQ29mpy(A,B)       ((A) * (B))
#define   _IQ28mpy(A,B)       ((A) * (B))
#define   _IQ27mpy(A,B)       ((A) * (B))
#define   _IQ26mpy(A,B)       ((A) * (B))
#define   _IQ25mpy(A,B)       ((A) * (B))
#define   _IQ24mpy(A,B)       ((A) * (B))
#define   _IQ23mpy(A,B)       ((A) * (B))
#define   _IQ22mpy(A,B)       ((A) * (B))
#define   _IQ21mpy(A,B)       ((A) * (B))
#define   _IQ20mpy(A,B)       ((A) * (B))
#define   _IQ19mpy(A,B)       ((A) * (B))
#define   _IQ18mpy(A,B)       ((A) * (B))
#define   _IQ17mpy(A,B)       ((A) * (B))
#define   _IQ16mpy(A,B)       ((A) * (B))
#define   _IQ15mpy(A,B)       ((A) * (B))
#define   _IQ14mpy(A,B)       ((A) * (B))
#define   _IQ13mpy(A,B)       ((A) * (B))
#define   _IQ12mpy(A,B)       ((A) * (B))
#define   _IQ11mpy(A,B)       ((A) * (B))
#define   _IQ10mpy(A,B)       ((A) * (B))
#define   _IQ9mpy(A,B)        ((A) * (B))
#define   _IQ8mpy(A,B)        ((A) * (B))
#define   _IQ7mpy(A,B)        ((A) * (B))
#define   _IQ6mpy(A,B)        ((A) * (B))
#define   _IQ5mpy(A,B)        ((A) * (B))
#define   _IQ4mpy(A,B)        ((A) * (B))
#define   _IQ3mpy(A,B)        ((A) * (B))
#define   _IQ2mpy(A,B)        ((A) * (B))
#define   _IQ1mpy(A,B)        ((A) * (B))
//---------------------------------------------------------------------------
#define   _IQrmpy(A,B)        ((A) * (B))
#define   _IQ30rmpy(A,B)      ((A) * (B))
#define   _IQ29rmpy(A,B)      ((A) * (B))
#define   _IQ28rmpy(A,B)      ((A) * (B))
#define   _IQ27rmpy(A,B)      ((A) * (B))
#define   _IQ26rmpy(A,B)      ((A) * (B))
#define   _IQ25rmpy(A,B)      ((A) * (B))
#define   _IQ24rmpy(A,B)      ((A) * (B))
#define   _IQ23rmpy(A,B)      ((A) * (B))
#define   _IQ22rmpy(A,B)      ((A) * (B))
#define   _IQ21rmpy(A,B)      ((A) * (B))
#define   _IQ20rmpy(A,B)      ((A) * (B))
#define   _IQ19rmpy(A,B)      ((A) * (B))
#define   _IQ18rmpy(A,B)      ((A) * (B))
#define   _IQ17rmpy(A,B)      ((A) * (B))
#define   _IQ16rmpy(A,B)      ((A) * (B))
#define   _IQ15rmpy(A,B)      ((A) * (B))
#define   _IQ14rmpy(A,B)      ((A) * (B))
#define   _IQ13rmpy(A,B)      ((A) * (B))
#define   _IQ12rmpy(A,B)      ((A) * (B))
#define   _IQ11rmpy(A,B)      ((A) * (B))
#define   _IQ10rmpy(A,B)      ((A) * (B))
#define   _IQ9rmpy(A,B)       ((A) * (B))
#define   _IQ8rmpy(A,B)       ((A) * (B))
#define   _IQ7rmpy(A,B)       ((A) * (B))
#define   _IQ6rmpy(A,B)       ((A) * (B))
#define   _IQ5rmpy(A,B)       ((A) * (B))
#define   _IQ4rmpy(A,B)       ((A) * (B))
#define   _IQ3rmpy(A,B)       ((A) * (B))
#define   _IQ2rmpy(A,B)       ((A) * (B))
#define   _IQ1rmpy(A,B)       ((A) * (B))
//---------------------------------------------------------------------------
#define   _IQrsmpy(A,B)       ((A) * (B))
#define   _IQ30rsmpy(A,B)     ((A) * (B))
#define   _IQ29rsmpy(A,B)     ((A) * (B))
#define   _IQ28rsmpy(A,B)     ((A) * (B))
#define   _IQ27rsmpy(A,B)     ((A) * (B))
#define   _IQ26rsmpy(A,B)     ((A) * (B))
#define   _IQ25rsmpy(A,B)     ((A) * (B))
#define   _IQ24rsmpy(A,B)     ((A) * (B))
#define   _IQ23rsmpy(A,B)     ((A) * (B))
#define   _IQ22rsmpy(A,B)     ((A) * (B))
#define   _IQ21rsmpy(A,B)     ((A) * (B))
#define   _IQ20rsmpy(A,B)     ((A) * (B))
#define   _IQ19rsmpy(A,B)     ((A) * (B))
#define   _IQ18rsmpy(A,B)     ((A) * (B))
#define   _IQ17rsmpy(A,B)     ((A) * (B))
#define   _IQ16rsmpy(A,B)     ((A) * (B))
#define   _IQ15rsmpy(A,B)     ((A) * (B))
#define   _IQ14rsmpy(A,B)     ((A) * (B))
#define   _IQ13rsmpy(A,B)     ((A) * (B))
#define   _IQ12rsmpy(A,B)     ((A) * (B))
#define   _IQ11rsmpy(A,B)     ((A) * (B))
#define   _IQ10rsmpy(A,B)     ((A) * (B))
#define   _IQ9rsmpy(A,B)      ((A) * (B))
#define   _IQ8rsmpy(A,B)      ((A) * (B))
#define   _IQ7rsmpy(A,B)      ((A) * (B))
#define   _IQ6rsmpy(A,B)      ((A) * (B))
#define   _IQ5rsmpy(A,B)      ((A) * (B))
#define   _IQ4rsmpy(A,B)      ((A) * (B))
#define   _IQ3rsmpy(A,B)      ((A) * (B))
#define   _IQ2rsmpy(A,B)      ((A) * (B))
#define   _IQ1rsmpy(A,B)      ((A) * (B))
//---------------------------------------------------------------------------
#define   _IQdiv(A,B)         ((A) / (B))
#define   _IQ30div(A,B)       ((A) / (B))
#define   _IQ29div(A,B)       ((A) / (B))
#define   _IQ28div(A,B)       ((A) / (B))
#define   _IQ27div(A,B)       ((A) / (B))
#define   _IQ26div(A,B)       ((A) / (B))
#define   _IQ25div(A,B)       ((A) / (B))
#define   _IQ24div(A,B)       ((A) / (B))
#define   _IQ23div(A,B)       ((A) / (B))
#define   _IQ22div(A,B)       ((A) / (B))
#define   _IQ21div(A,B)       ((A) / (B))
#define   _IQ20div(A,B)       ((A) / (B))
#define   _IQ19div(A,B)       ((A) / (B))
#define   _IQ18div(A,B)       ((A) / (B))
#define   _IQ17div(A,B)       ((A) / (B))
#define   _IQ16div(A,B)       ((A) / (B))
#define   _IQ15div(A,B)       ((A) / (B))
#define   _IQ14div(A,B)       ((A) / (B))
#define   _IQ13div(A,B)       ((A) / (B))
#define   _IQ12div(A,B)       ((A) / (B))
#define   _IQ11div(A,B)       ((A) / (B))
#define   _IQ10div(A,B)       ((A) / (B))
#define   _IQ9div(A,B)        ((A) / (B))
#define   _IQ8div(A,B)        ((A) / (B))
#define   _IQ7div(A,B)        ((A) / (B))
#define   _IQ6div(A,B)        ((A) / (B))
#define   _IQ5div(A,B)        ((A) / (B))
#define   _IQ4div(A,B)        ((A) / (B))
#define   _IQ3div(A,B)        ((A) / (B))
#define   _IQ2div(A,B)        ((A) / (B))
#define   _IQ1div(A,B)        ((A) / (B))
//---------------------------------------------------------------------------
#define   _IQsin(A)           sin(A)
#define   _IQ30sin(A)         sin(A)
#define   _IQ29sin(A)         sin(A)
#define   _IQ28sin(A)         sin(A)
#define   _IQ27sin(A)         sin(A)
#define   _IQ26sin(A)         sin(A)
#define   _IQ25sin(A)         sin(A)
#define   _IQ24sin(A)         sin(A)
#define   _IQ23sin(A)         sin(A)
#define   _IQ22sin(A)         sin(A)
#define   _IQ21sin(A)         sin(A)
#define   _IQ20sin(A)         sin(A)
#define   _IQ19sin(A)         sin(A)
#define   _IQ18sin(A)         sin(A)
#define   _IQ17sin(A)         sin(A)
#define   _IQ16sin(A)         sin(A)
#define   _IQ15sin(A)         sin(A)
#define   _IQ14sin(A)         sin(A)
#define   _IQ13sin(A)         sin(A)
#define   _IQ12sin(A)         sin(A)
#define   _IQ11sin(A)         sin(A)
#define   _IQ10sin(A)         sin(A)
#define   _IQ9sin(A)          sin(A)
#define   _IQ8sin(A)          sin(A)
#define   _IQ7sin(A)          sin(A)
#define   _IQ6sin(A)          sin(A)
#define   _IQ5sin(A)          sin(A)
#define   _IQ4sin(A)          sin(A)
#define   _IQ3sin(A)          sin(A)
#define   _IQ2sin(A)          sin(A)
#define   _IQ1sin(A)          sin(A)
//---------------------------------------------------------------------------
#define   _IQsinPU(A)         sin((A)*6.283185307)
#define   _IQ30sinPU(A)       sin((A)*6.283185307)
#define   _IQ29sinPU(A)       sin((A)*6.283185307)
#define   _IQ28sinPU(A)       sin((A)*6.283185307)
#define   _IQ27sinPU(A)       sin((A)*6.283185307)
#define   _IQ26sinPU(A)       sin((A)*6.283185307)
#define   _IQ25sinPU(A)       sin((A)*6.283185307)
#define   _IQ24sinPU(A)       sin((A)*6.283185307)
#define   _IQ23sinPU(A)       sin((A)*6.283185307)
#define   _IQ22sinPU(A)       sin((A)*6.283185307)
#define   _IQ21sinPU(A)       sin((A)*6.283185307)
#define   _IQ20sinPU(A)       sin((A)*6.283185307)
#define   _IQ19sinPU(A)       sin((A)*6.283185307)
#define   _IQ18sinPU(A)       sin((A)*6.283185307)
#define   _IQ17sinPU(A)       sin((A)*6.283185307)
#define   _IQ16sinPU(A)       sin((A)*6.283185307)
#define   _IQ15sinPU(A)       sin((A)*6.283185307)
#define   _IQ14sinPU(A)       sin((A)*6.283185307)
#define   _IQ13sinPU(A)       sin((A)*6.283185307)
#define   _IQ12sinPU(A)       sin((A)*6.283185307)
#define   _IQ11sinPU(A)       sin((A)*6.283185307)
#define   _IQ10sinPU(A)       sin((A)*6.283185307)
#define   _IQ9sinPU(A)        sin((A)*6.283185307)
#define   _IQ8sinPU(A)        sin((A)*6.283185307)
#define   _IQ7sinPU(A)        sin((A)*6.283185307)
#define   _IQ6sinPU(A)        sin((A)*6.283185307)
#define   _IQ5sinPU(A)        sin((A)*6.283185307)
#define   _IQ4sinPU(A)        sin((A)*6.283185307)
#define   _IQ3sinPU(A)        sin((A)*6.283185307)
#define   _IQ2sinPU(A)        sin((A)*6.283185307)
#define   _IQ1sinPU(A)        sin((A)*6.283185307)
//---------------------------------------------------------------------------
#define   _IQasin(A)          asin(A)
#define   _IQ29asin(A)        asin(A)
#define   _IQ28asin(A)        asin(A)
#define   _IQ27asin(A)        asin(A)
#define   _IQ26asin(A)        asin(A)
#define   _IQ25asin(A)        asin(A)
#define   _IQ24asin(A)        asin(A)
#define   _IQ23asin(A)        asin(A)
#define   _IQ22asin(A)        asin(A)
#define   _IQ21asin(A)        asin(A)
#define   _IQ20asin(A)        asin(A)
#define   _IQ19asin(A)        asin(A)
#define   _IQ18asin(A)        asin(A)
#define   _IQ17asin(A)        asin(A)
#define   _IQ16asin(A)        asin(A)
#define   _IQ15asin(A)        asin(A)
#define   _IQ14asin(A)        asin(A)
#define   _IQ13asin(A)        asin(A)
#define   _IQ12asin(A)        asin(A)
#define   _IQ11asin(A)        asin(A)
#define   _IQ10asin(A)        asin(A)
#define   _IQ9asin(A)         asin(A)
#define   _IQ8asin(A)         asin(A)
#define   _IQ7asin(A)         asin(A)
#define   _IQ6asin(A)         asin(A)
#define   _IQ5asin(A)         asin(A)
#define   _IQ4asin(A)         asin(A)
#define   _IQ3asin(A)         asin(A)
#define   _IQ2asin(A)         asin(A)
#define   _IQ1asin(A)         asin(A)
//---------------------------------------------------------------------------
#define   _IQcos(A)           cos(A)
#define   _IQ30cos(A)         cos(A)
#define   _IQ29cos(A)         cos(A)
#define   _IQ28cos(A)         cos(A)
#define   _IQ27cos(A)         cos(A)
#define   _IQ26cos(A)         cos(A)
#define   _IQ25cos(A)         cos(A)
#define   _IQ24cos(A)         cos(A)
#define   _IQ23cos(A)         cos(A)
#define   _IQ22cos(A)         cos(A)
#define   _IQ21cos(A)         cos(A)
#define   _IQ20cos(A)         cos(A)
#define   _IQ19cos(A)         cos(A)
#define   _IQ18cos(A)         cos(A)
#define   _IQ17cos(A)         cos(A)
#define   _IQ16cos(A)         cos(A)
#define   _IQ15cos(A)         cos(A)
#define   _IQ14cos(A)         cos(A)
#define   _IQ13cos(A)         cos(A)
#define   _IQ12cos(A)         cos(A)
#define   _IQ11cos(A)         cos(A)
#define   _IQ10cos(A)         cos(A)
#define   _IQ9cos(A)          cos(A)
#define   _IQ8cos(A)          cos(A)
#define   _IQ7cos(A)          cos(A)
#define   _IQ6cos(A)          cos(A)
#define   _IQ5cos(A)          cos(A)
#define   _IQ4cos(A)          cos(A)
#define   _IQ3cos(A)          cos(A)
#define   _IQ2cos(A)          cos(A)
#define   _IQ1cos(A)          cos(A)
//---------------------------------------------------------------------------
#define   _IQcosPU(A)         cos((A)*6.283185307)
#define   _IQ30cosPU(A)       cos((A)*6.283185307)
#define   _IQ29cosPU(A)       cos((A)*6.283185307)
#define   _IQ28cosPU(A)       cos((A)*6.283185307)
#define   _IQ27cosPU(A)       cos((A)*6.283185307)
#define   _IQ26cosPU(A)       cos((A)*6.283185307)
#define   _IQ25cosPU(A)       cos((A)*6.283185307)
#define   _IQ24cosPU(A)       cos((A)*6.283185307)
#define   _IQ23cosPU(A)       cos((A)*6.283185307)
#define   _IQ22cosPU(A)       cos((A)*6.283185307)
#define   _IQ21cosPU(A)       cos((A)*6.283185307)
#define   _IQ20cosPU(A)       cos((A)*6.283185307)
#define   _IQ19cosPU(A)       cos((A)*6.283185307)
#define   _IQ18cosPU(A)       cos((A)*6.283185307)
#define   _IQ17cosPU(A)       cos((A)*6.283185307)
#define   _IQ16cosPU(A)       cos((A)*6.283185307)
#define   _IQ15cosPU(A)       cos((A)*6.283185307)
#define   _IQ14cosPU(A)       cos((A)*6.283185307)
#define   _IQ13cosPU(A)       cos((A)*6.283185307)
#define   _IQ12cosPU(A)       cos((A)*6.283185307)
#define   _IQ11cosPU(A)       cos((A)*6.283185307)
#define   _IQ10cosPU(A)       cos((A)*6.283185307)
#define   _IQ9cosPU(A)        cos((A)*6.283185307)
#define   _IQ8cosPU(A)        cos((A)*6.283185307)
#define   _IQ7cosPU(A)        cos((A)*6.283185307)
#define   _IQ6cosPU(A)        cos((A)*6.283185307)
#define   _IQ5cosPU(A)        cos((A)*6.283185307)
#define   _IQ4cosPU(A)        cos((A)*6.283185307)
#define   _IQ3cosPU(A)        cos((A)*6.283185307)
#define   _IQ2cosPU(A)        cos((A)*6.283185307)
#define   _IQ1cosPU(A)        cos((A)*6.283185307)
//---------------------------------------------------------------------------
#define   _IQacos(A)          acos(A)
#define   _IQ29acos(A)        acos(A)
#define   _IQ28acos(A)        acos(A)
#define   _IQ27acos(A)        acos(A)
#define   _IQ26acos(A)        acos(A)
#define   _IQ25acos(A)        acos(A)
#define   _IQ24acos(A)        acos(A)
#define   _IQ23acos(A)        acos(A)
#define   _IQ22acos(A)        acos(A)
#define   _IQ21acos(A)        acos(A)
#define   _IQ20acos(A)        acos(A)
#define   _IQ19acos(A)        acos(A)
#define   _IQ18acos(A)        acos(A)
#define   _IQ17acos(A)        acos(A)
#define   _IQ16acos(A)        acos(A)
#define   _IQ15acos(A)        acos(A)
#define   _IQ14acos(A)        acos(A)
#define   _IQ13acos(A)        acos(A)
#define   _IQ12acos(A)        acos(A)
#define   _IQ11acos(A)        acos(A)
#define   _IQ10acos(A)        acos(A)
#define   _IQ9acos(A)         acos(A)
#define   _IQ8acos(A)         acos(A)
#define   _IQ7acos(A)         acos(A)
#define   _IQ6acos(A)         acos(A)
#define   _IQ5acos(A)         acos(A)
#define   _IQ4acos(A)         acos(A)
#define   _IQ3acos(A)         acos(A)
#define   _IQ2acos(A)         acos(A)
#define   _IQ1acos(A)         acos(A)
//---------------------------------------------------------------------------
#define   _IQatan(A)          atan(A)
#define   _IQ30atan(A)        atan(A)
#define   _IQ29atan(A)        atan(A)
#define   _IQ28atan(A)        atan(A)
#define   _IQ27atan(A)        atan(A)
#define   _IQ26atan(A)        atan(A)
#define   _IQ25atan(A)        atan(A)
#define   _IQ24atan(A)        atan(A)
#define   _IQ23atan(A)        atan(A)
#define   _IQ22atan(A)        atan(A)
#define   _IQ21atan(A)        atan(A)
#define   _IQ20atan(A)        atan(A)
#define   _IQ19atan(A)        atan(A)
#define   _IQ18atan(A)        atan(A)
#define   _IQ17atan(A)        atan(A)
#define   _IQ16atan(A)        atan(A)
#define   _IQ15atan(A)        atan(A)
#define   _IQ14atan(A)        atan(A)
#define   _IQ13atan(A)        atan(A)
#define   _IQ12atan(A)        atan(A)
#define   _IQ11atan(A)        atan(A)
#define   _IQ10atan(A)        atan(A)
#define   _IQ9atan(A)         atan(A)
#define   _IQ8atan(A)         atan(A)
#define   _IQ7atan(A)         atan(A)
#define   _IQ6atan(A)         atan(A)
#define   _IQ5atan(A)         atan(A)
#define   _IQ4atan(A)         atan(A)
#define   _IQ3atan(A)         atan(A)
#define   _IQ2atan(A)         atan(A)
#define   _IQ1atan(A)         atan(A)
//---------------------------------------------------------------------------
#define   _IQatan2(A,B)       atan2(A,B)
#define   _IQ30atan2(A,B)     atan2(A,B)
#define   _IQ29atan2(A,B)     atan2(A,B)
#define   _IQ28atan2(A,B)     atan2(A,B)
#define   _IQ27atan2(A,B)     atan2(A,B)
#define   _IQ26atan2(A,B)     atan2(A,B)
#define   _IQ25atan2(A,B)     atan2(A,B)
#define   _IQ24atan2(A,B)     atan2(A,B)
#define   _IQ23atan2(A,B)     atan2(A,B)
#define   _IQ22atan2(A,B)     atan2(A,B)
#define   _IQ21atan2(A,B)     atan2(A,B)
#define   _IQ20atan2(A,B)     atan2(A,B)
#define   _IQ19atan2(A,B)     atan2(A,B)
#define   _IQ18atan2(A,B)     atan2(A,B)
#define   _IQ17atan2(A,B)     atan2(A,B)
#define   _IQ16atan2(A,B)     atan2(A,B)
#define   _IQ15atan2(A,B)     atan2(A,B)
#define   _IQ14atan2(A,B)     atan2(A,B)
#define   _IQ13atan2(A,B)     atan2(A,B)
#define   _IQ12atan2(A,B)     atan2(A,B)
#define   _IQ11atan2(A,B)     atan2(A,B)
#define   _IQ10atan2(A,B)     atan2(A,B)
#define   _IQ9atan2(A,B)      atan2(A,B)
#define   _IQ8atan2(A,B)      atan2(A,B)
#define   _IQ7atan2(A,B)      atan2(A,B)
#define   _IQ6atan2(A,B)      atan2(A,B)
#define   _IQ5atan2(A,B)      atan2(A,B)
#define   _IQ4atan2(A,B)      atan2(A,B)
#define   _IQ3atan2(A,B)      atan2(A,B)
#define   _IQ2atan2(A,B)      atan2(A,B)
#define   _IQ1atan2(A,B)      atan2(A,B)
//---------------------------------------------------------------------------
#define   _IQatan2PU(A,B)     ((atan2(A,B)*(1.0/6.283185307)) >= 0.0 ? (atan2(A,B)*(1.0/6.283185307)):1.0 + (atan2(A,B)*(1.0/6.283185307)))
#define   _IQ30atan2PU(A,B)   ((atan2(A,B)*(1.0/6.283185307)) >= 0.0 ? (atan2(A,B)*(1.0/6.283185307)):1.0 + (atan2(A,B)*(1.0/6.283185307)))
#define   _IQ29atan2PU(A,B)   ((atan2(A,B)*(1.0/6.283185307)) >= 0.0 ? (atan2(A,B)*(1.0/6.283185307)):1.0 + (atan2(A,B)*(1.0/6.283185307)))
#define   _IQ28atan2PU(A,B)   ((atan2(A,B)*(1.0/6.283185307)) >= 0.0 ? (atan2(A,B)*(1.0/6.283185307)):1.0 + (atan2(A,B)*(1.0/6.283185307)))
#define   _IQ27atan2PU(A,B)   ((atan2(A,B)*(1.0/6.283185307)) >= 0.0 ? (atan2(A,B)*(1.0/6.283185307)):1.0 + (atan2(A,B)*(1.0/6.283185307)))
#define   _IQ26atan2PU(A,B)   ((atan2(A,B)*(1.0/6.283185307)) >= 0.0 ? (atan2(A,B)*(1.0/6.283185307)):1.0 + (atan2(A,B)*(1.0/6.283185307)))
#define   _IQ25atan2PU(A,B)   ((atan2(A,B)*(1.0/6.283185307)) >= 0.0 ? (atan2(A,B)*(1.0/6.283185307)):1.0 + (atan2(A,B)*(1.0/6.283185307)))
#define   _IQ24atan2PU(A,B)   ((atan2(A,B)*(1.0/6.283185307)) >= 0.0 ? (atan2(A,B)*(1.0/6.283185307)):1.0 + (atan2(A,B)*(1.0/6.283185307)))
#define   _IQ23atan2PU(A,B)   ((atan2(A,B)*(1.0/6.283185307)) >= 0.0 ? (atan2(A,B)*(1.0/6.283185307)):1.0 + (atan2(A,B)*(1.0/6.283185307)))
#define   _IQ22atan2PU(A,B)   ((atan2(A,B)*(1.0/6.283185307)) >= 0.0 ? (atan2(A,B)*(1.0/6.283185307)):1.0 + (atan2(A,B)*(1.0/6.283185307)))
#define   _IQ21atan2PU(A,B)   ((atan2(A,B)*(1.0/6.283185307)) >= 0.0 ? (atan2(A,B)*(1.0/6.283185307)):1.0 + (atan2(A,B)*(1.0/6.283185307)))
#define   _IQ20atan2PU(A,B)   ((atan2(A,B)*(1.0/6.283185307)) >= 0.0 ? (atan2(A,B)*(1.0/6.283185307)):1.0 + (atan2(A,B)*(1.0/6.283185307)))
#define   _IQ19atan2PU(A,B)   ((atan2(A,B)*(1.0/6.283185307)) >= 0.0 ? (atan2(A,B)*(1.0/6.283185307)):1.0 + (atan2(A,B)*(1.0/6.283185307)))
#define   _IQ18atan2PU(A,B)   ((atan2(A,B)*(1.0/6.283185307)) >= 0.0 ? (atan2(A,B)*(1.0/6.283185307)):1.0 + (atan2(A,B)*(1.0/6.283185307)))
#define   _IQ17atan2PU(A,B)   ((atan2(A,B)*(1.0/6.283185307)) >= 0.0 ? (atan2(A,B)*(1.0/6.283185307)):1.0 + (atan2(A,B)*(1.0/6.283185307)))
#define   _IQ16atan2PU(A,B)   ((atan2(A,B)*(1.0/6.283185307)) >= 0.0 ? (atan2(A,B)*(1.0/6.283185307)):1.0 + (atan2(A,B)*(1.0/6.283185307)))
#define   _IQ15atan2PU(A,B)   ((atan2(A,B)*(1.0/6.283185307)) >= 0.0 ? (atan2(A,B)*(1.0/6.283185307)):1.0 + (atan2(A,B)*(1.0/6.283185307)))
#define   _IQ14atan2PU(A,B)   ((atan2(A,B)*(1.0/6.283185307)) >= 0.0 ? (atan2(A,B)*(1.0/6.283185307)):1.0 + (atan2(A,B)*(1.0/6.283185307)))
#define   _IQ13atan2PU(A,B)   ((atan2(A,B)*(1.0/6.283185307)) >= 0.0 ? (atan2(A,B)*(1.0/6.283185307)):1.0 + (atan2(A,B)*(1.0/6.283185307)))
#define   _IQ12atan2PU(A,B)   ((atan2(A,B)*(1.0/6.283185307)) >= 0.0 ? (atan2(A,B)*(1.0/6.283185307)):1.0 + (atan2(A,B)*(1.0/6.283185307)))
#define   _IQ11atan2PU(A,B)   ((atan2(A,B)*(1.0/6.283185307)) >= 0.0 ? (atan2(A,B)*(1.0/6.283185307)):1.0 + (atan2(A,B)*(1.0/6.283185307)))
#define   _IQ10atan2PU(A,B)   ((atan2(A,B)*(1.0/6.283185307)) >= 0.0 ? (atan2(A,B)*(1.0/6.283185307)):1.0 + (atan2(A,B)*(1.0/6.283185307)))
#define   _IQ9atan2PU(A,B)    ((atan2(A,B)*(1.0/6.283185307)) >= 0.0 ? (atan2(A,B)*(1.0/6.283185307)):1.0 + (atan2(A,B)*(1.0/6.283185307)))
#define   _IQ8atan2PU(A,B)    ((atan2(A,B)*(1.0/6.283185307)) >= 0.0 ? (atan2(A,B)*(1.0/6.283185307)):1.0 + (atan2(A,B)*(1.0/6.283185307)))
#define   _IQ7atan2PU(A,B)    ((atan2(A,B)*(1.0/6.283185307)) >= 0.0 ? (atan2(A,B)*(1.0/6.283185307)):1.0 + (atan2(A,B)*(1.0/6.283185307)))
#define   _IQ6atan2PU(A,B)    ((atan2(A,B)*(1.0/6.283185307)) >= 0.0 ? (atan2(A,B)*(1.0/6.283185307)):1.0 + (atan2(A,B)*(1.0/6.283185307)))
#define   _IQ5atan2PU(A,B)    ((atan2(A,B)*(1.0/6.283185307)) >= 0.0 ? (atan2(A,B)*(1.0/6.283185307)):1.0 + (atan2(A,B)*(1.0/6.283185307)))
#define   _IQ4atan2PU(A,B)    ((atan2(A,B)*(1.0/6.283185307)) >= 0.0 ? (atan2(A,B)*(1.0/6.283185307)):1.0 + (atan2(A,B)*(1.0/6.283185307)))
#define   _IQ3atan2PU(A,B)    ((atan2(A,B)*(1.0/6.283185307)) >= 0.0 ? (atan2(A,B)*(1.0/6.283185307)):1.0 + (atan2(A,B)*(1.0/6.283185307)))
#define   _IQ2atan2PU(A,B)    ((atan2(A,B)*(1.0/6.283185307)) >= 0.0 ? (atan2(A,B)*(1.0/6.283185307)):1.0 + (atan2(A,B)*(1.0/6.283185307)))
#define   _IQ1atan2PU(A,B)    ((atan2(A,B)*(1.0/6.283185307)) >= 0.0 ? (atan2(A,B)*(1.0/6.283185307)):1.0 + (atan2(A,B)*(1.0/6.283185307)))
//---------------------------------------------------------------------------
#define   _IQsqrt(A)          sqrt(A)
#define   _IQ30sqrt(A)        sqrt(A)
#define   _IQ29sqrt(A)        sqrt(A)
#define   _IQ28sqrt(A)        sqrt(A)
#define   _IQ27sqrt(A)        sqrt(A)
#define   _IQ26sqrt(A)        sqrt(A)
#define   _IQ25sqrt(A)        sqrt(A)
#define   _IQ24sqrt(A)        sqrt(A)
#define   _IQ23sqrt(A)        sqrt(A)
#define   _IQ22sqrt(A)        sqrt(A)
#define   _IQ21sqrt(A)        sqrt(A)
#define   _IQ20sqrt(A)        sqrt(A)
#define   _IQ19sqrt(A)        sqrt(A)
#define   _IQ18sqrt(A)        sqrt(A)
#define   _IQ17sqrt(A)        sqrt(A)
#define   _IQ16sqrt(A)        sqrt(A)
#define   _IQ15sqrt(A)        sqrt(A)
#define   _IQ14sqrt(A)        sqrt(A)
#define   _IQ13sqrt(A)        sqrt(A)
#define   _IQ12sqrt(A)        sqrt(A)
#define   _IQ11sqrt(A)        sqrt(A)
#define   _IQ10sqrt(A)        sqrt(A)
#define   _IQ9sqrt(A)         sqrt(A)
#define   _IQ8sqrt(A)         sqrt(A)
#define   _IQ7sqrt(A)         sqrt(A)
#define   _IQ6sqrt(A)         sqrt(A)
#define   _IQ5sqrt(A)         sqrt(A)
#define   _IQ4sqrt(A)         sqrt(A)
#define   _IQ3sqrt(A)         sqrt(A)
#define   _IQ2sqrt(A)         sqrt(A)
#define   _IQ1sqrt(A)         sqrt(A)
//---------------------------------------------------------------------------
#define   _IQisqrt(A)         (1.0/sqrt(A))
#define   _IQ30isqrt(A)       (1.0/sqrt(A))
#define   _IQ29isqrt(A)       (1.0/sqrt(A))
#define   _IQ28isqrt(A)       (1.0/sqrt(A))
#define   _IQ27isqrt(A)       (1.0/sqrt(A))
#define   _IQ26isqrt(A)       (1.0/sqrt(A))
#define   _IQ25isqrt(A)       (1.0/sqrt(A))
#define   _IQ24isqrt(A)       (1.0/sqrt(A))
#define   _IQ23isqrt(A)       (1.0/sqrt(A))
#define   _IQ22isqrt(A)       (1.0/sqrt(A))
#define   _IQ21isqrt(A)       (1.0/sqrt(A))
#define   _IQ20isqrt(A)       (1.0/sqrt(A))
#define   _IQ19isqrt(A)       (1.0/sqrt(A))
#define   _IQ18isqrt(A)       (1.0/sqrt(A))
#define   _IQ17isqrt(A)       (1.0/sqrt(A))
#define   _IQ16isqrt(A)       (1.0/sqrt(A))
#define   _IQ15isqrt(A)       (1.0/sqrt(A))
#define   _IQ14isqrt(A)       (1.0/sqrt(A))
#define   _IQ13isqrt(A)       (1.0/sqrt(A))
#define   _IQ12isqrt(A)       (1.0/sqrt(A))
#define   _IQ11isqrt(A)       (1.0/sqrt(A))
#define   _IQ10isqrt(A)       (1.0/sqrt(A))
#define   _IQ9isqrt(A)        (1.0/sqrt(A))
#define   _IQ8isqrt(A)        (1.0/sqrt(A))
#define   _IQ7isqrt(A)        (1.0/sqrt(A))
#define   _IQ6isqrt(A)        (1.0/sqrt(A))
#define   _IQ5isqrt(A)        (1.0/sqrt(A))
#define   _IQ4isqrt(A)        (1.0/sqrt(A))
#define   _IQ3isqrt(A)        (1.0/sqrt(A))
#define   _IQ2isqrt(A)        (1.0/sqrt(A))
#define   _IQ1isqrt(A)        (1.0/sqrt(A))
//---------------------------------------------------------------------------
#define   _IQexp(A)           exp(A)
#define   _IQ30exp(A)         exp(A)
#define   _IQ29exp(A)         exp(A)
#define   _IQ28exp(A)         exp(A)
#define   _IQ27exp(A)         exp(A)
#define   _IQ26exp(A)         exp(A)
#define   _IQ25exp(A)         exp(A)
#define   _IQ24exp(A)         exp(A)
#define   _IQ23exp(A)         exp(A)
#define   _IQ22exp(A)         exp(A)
#define   _IQ21exp(A)         exp(A)
#define   _IQ20exp(A)         exp(A)
#define   _IQ19exp(A)         exp(A)
#define   _IQ18exp(A)         exp(A)
#define   _IQ17exp(A)         exp(A)
#define   _IQ16exp(A)         exp(A)
#define   _IQ15exp(A)         exp(A)
#define   _IQ14exp(A)         exp(A)
#define   _IQ13exp(A)         exp(A)
#define   _IQ12exp(A)         exp(A)
#define   _IQ11exp(A)         exp(A)
#define   _IQ10exp(A)         exp(A)
#define   _IQ9exp(A)          exp(A)
#define   _IQ8exp(A)          exp(A)
#define   _IQ7exp(A)          exp(A)
#define   _IQ6exp(A)          exp(A)
#define   _IQ5exp(A)          exp(A)
#define   _IQ4exp(A)          exp(A)
#define   _IQ3exp(A)          exp(A)
#define   _IQ2exp(A)          exp(A)
#define   _IQ1exp(A)          exp(A)
//---------------------------------------------------------------------------
#define   _IQint(A)           ((long) (A))
#define   _IQ30int(A)         ((long) (A))
#define   _IQ29int(A)         ((long) (A))
#define   _IQ28int(A)         ((long) (A))
#define   _IQ27int(A)         ((long) (A))
#define   _IQ26int(A)         ((long) (A))
#define   _IQ25int(A)         ((long) (A))
#define   _IQ24int(A)         ((long) (A))
#define   _IQ23int(A)         ((long) (A))
#define   _IQ22int(A)         ((long) (A))
#define   _IQ21int(A)         ((long) (A))
#define   _IQ20int(A)         ((long) (A))
#define   _IQ19int(A)         ((long) (A))
#define   _IQ18int(A)         ((long) (A))
#define   _IQ17int(A)         ((long) (A))
#define   _IQ16int(A)         ((long) (A))
#define   _IQ15int(A)         ((long) (A))
#define   _IQ14int(A)         ((long) (A))
#define   _IQ13int(A)         ((long) (A))
#define   _IQ12int(A)         ((long) (A))
#define   _IQ11int(A)         ((long) (A))
#define   _IQ10int(A)         ((long) (A))
#define   _IQ9int(A)          ((long) (A))
#define   _IQ8int(A)          ((long) (A))
#define   _IQ7int(A)          ((long) (A))
#define   _IQ6int(A)          ((long) (A))
#define   _IQ5int(A)          ((long) (A))
#define   _IQ4int(A)          ((long) (A))
#define   _IQ3int(A)          ((long) (A))
#define   _IQ2int(A)          ((long) (A))
#define   _IQ1int(A)          ((long) (A))
//---------------------------------------------------------------------------
#define   _IQfrac(A)          ((A) - (float)((long) (A)))
#define   _IQ30frac(A)        ((A) - (float)((long) (A)))
#define   _IQ29frac(A)        ((A) - (float)((long) (A)))
#define   _IQ28frac(A)        ((A) - (float)((long) (A)))
#define   _IQ27frac(A)        ((A) - (float)((long) (A)))
#define   _IQ26frac(A)        ((A) - (float)((long) (A)))
#define   _IQ25frac(A)        ((A) - (float)((long) (A)))
#define   _IQ24frac(A)        ((A) - (float)((long) (A)))
#define   _IQ23frac(A)        ((A) - (float)((long) (A)))
#define   _IQ22frac(A)        ((A) - (float)((long) (A)))
#define   _IQ21frac(A)        ((A) - (float)((long) (A)))
#define   _IQ20frac(A)        ((A) - (float)((long) (A)))
#define   _IQ19frac(A)        ((A) - (float)((long) (A)))
#define   _IQ18frac(A)        ((A) - (float)((long) (A)))
#define   _IQ17frac(A)        ((A) - (float)((long) (A)))
#define   _IQ16frac(A)        ((A) - (float)((long) (A)))
#define   _IQ15frac(A)        ((A) - (float)((long) (A)))
#define   _IQ14frac(A)        ((A) - (float)((long) (A)))
#define   _IQ13frac(A)        ((A) - (float)((long) (A)))
#define   _IQ12frac(A)        ((A) - (float)((long) (A)))
#define   _IQ11frac(A)        ((A) - (float)((long) (A)))
#define   _IQ10frac(A)        ((A) - (float)((long) (A)))
#define   _IQ9frac(A)         ((A) - (float)((long) (A)))
#define   _IQ8frac(A)         ((A) - (float)((long) (A)))
#define   _IQ7frac(A)         ((A) - (float)((long) (A)))
#define   _IQ6frac(A)         ((A) - (float)((long) (A)))
#define   _IQ5frac(A)         ((A) - (float)((long) (A)))
#define   _IQ4frac(A)         ((A) - (float)((long) (A)))
#define   _IQ3frac(A)         ((A) - (float)((long) (A)))
#define   _IQ2frac(A)         ((A) - (float)((long) (A)))
#define   _IQ1frac(A)         ((A) - (float)((long) (A)))
//---------------------------------------------------------------------------
#define   _IQmpyIQX(A, IQA, B, IQB)    ((A)*(B))
#define   _IQ30mpyIQX(A, IQA, B, IQB)  ((A)*(B))
#define   _IQ29mpyIQX(A, IQA, B, IQB)  ((A)*(B))
#define   _IQ28mpyIQX(A, IQA, B, IQB)  ((A)*(B))
#define   _IQ27mpyIQX(A, IQA, B, IQB)  ((A)*(B))
#define   _IQ26mpyIQX(A, IQA, B, IQB)  ((A)*(B))
#define   _IQ25mpyIQX(A, IQA, B, IQB)  ((A)*(B))
#define   _IQ24mpyIQX(A, IQA, B, IQB)  ((A)*(B))
#define   _IQ23mpyIQX(A, IQA, B, IQB)  ((A)*(B))
#define   _IQ22mpyIQX(A, IQA, B, IQB)  ((A)*(B))
#define   _IQ21mpyIQX(A, IQA, B, IQB)  ((A)*(B))
#define   _IQ20mpyIQX(A, IQA, B, IQB)  ((A)*(B))
#define   _IQ19mpyIQX(A, IQA, B, IQB)  ((A)*(B))
#define   _IQ18mpyIQX(A, IQA, B, IQB)  ((A)*(B))
#define   _IQ17mpyIQX(A, IQA, B, IQB)  ((A)*(B))
#define   _IQ16mpyIQX(A, IQA, B, IQB)  ((A)*(B))
#define   _IQ15mpyIQX(A, IQA, B, IQB)  ((A)*(B))
#define   _IQ14mpyIQX(A, IQA, B, IQB)  ((A)*(B))
#define   _IQ13mpyIQX(A, IQA, B, IQB)  ((A)*(B))
#define   _IQ12mpyIQX(A, IQA, B, IQB)  ((A)*(B))
#define   _IQ11mpyIQX(A, IQA, B, IQB)  ((A)*(B))
#define   _IQ10mpyIQX(A, IQA, B, IQB)  ((A)*(B))
#define   _IQ9mpyIQX(A, IQA, B, IQB)   ((A)*(B))
#define   _IQ8mpyIQX(A, IQA, B, IQB)   ((A)*(B))
#define   _IQ7mpyIQX(A, IQA, B, IQB)   ((A)*(B))
#define   _IQ6mpyIQX(A, IQA, B, IQB)   ((A)*(B))
#define   _IQ5mpyIQX(A, IQA, B, IQB)   ((A)*(B))
#define   _IQ4mpyIQX(A, IQA, B, IQB)   ((A)*(B))
#define   _IQ3mpyIQX(A, IQA, B, IQB)   ((A)*(B))
#define   _IQ2mpyIQX(A, IQA, B, IQB)   ((A)*(B))
#define   _IQ1mpyIQX(A, IQA, B, IQB)   ((A)*(B))
//---------------------------------------------------------------------------
#define   _IQmpyI32(A,B)      ((A) * (float) (B))
#define   _IQ30mpyI32(A,B)    ((A) * (float) (B))
#define   _IQ29mpyI32(A,B)    ((A) * (float) (B))
#define   _IQ28mpyI32(A,B)    ((A) * (float) (B))
#define   _IQ27mpyI32(A,B)    ((A) * (float) (B))
#define   _IQ26mpyI32(A,B)    ((A) * (float) (B))
#define   _IQ25mpyI32(A,B)    ((A) * (float) (B))
#define   _IQ24mpyI32(A,B)    ((A) * (float) (B))
#define   _IQ23mpyI32(A,B)    ((A) * (float) (B))
#define   _IQ22mpyI32(A,B)    ((A) * (float) (B))
#define   _IQ21mpyI32(A,B)    ((A) * (float) (B))
#define   _IQ20mpyI32(A,B)    ((A) * (float) (B))
#define   _IQ19mpyI32(A,B)    ((A) * (float) (B))
#define   _IQ18mpyI32(A,B)    ((A) * (float) (B))
#define   _IQ17mpyI32(A,B)    ((A) * (float) (B))
#define   _IQ16mpyI32(A,B)    ((A) * (float) (B))
#define   _IQ15mpyI32(A,B)    ((A) * (float) (B))
#define   _IQ14mpyI32(A,B)    ((A) * (float) (B))
#define   _IQ13mpyI32(A,B)    ((A) * (float) (B))
#define   _IQ12mpyI32(A,B)    ((A) * (float) (B))
#define   _IQ11mpyI32(A,B)    ((A) * (float) (B))
#define   _IQ10mpyI32(A,B)    ((A) * (float) (B))
#define   _IQ9mpyI32(A,B)     ((A) * (float) (B))
#define   _IQ8mpyI32(A,B)     ((A) * (float) (B))
#define   _IQ7mpyI32(A,B)     ((A) * (float) (B))
#define   _IQ6mpyI32(A,B)     ((A) * (float) (B))
#define   _IQ5mpyI32(A,B)     ((A) * (float) (B))
#define   _IQ4mpyI32(A,B)     ((A) * (float) (B))
#define   _IQ3mpyI32(A,B)     ((A) * (float) (B))
#define   _IQ2mpyI32(A,B)     ((A) * (float) (B))
#define   _IQ1mpyI32(A,B)     ((A) * (float) (B))
//---------------------------------------------------------------------------
#define   _IQmpyI32int(A,B)   ((long) ((A) * (float) (B)))
#define   _IQ30mpyI32int(A,B) ((long) ((A) * (float) (B)))
#define   _IQ29mpyI32int(A,B) ((long) ((A) * (float) (B)))
#define   _IQ28mpyI32int(A,B) ((long) ((A) * (float) (B)))
#define   _IQ27mpyI32int(A,B) ((long) ((A) * (float) (B)))
#define   _IQ26mpyI32int(A,B) ((long) ((A) * (float) (B)))
#define   _IQ25mpyI32int(A,B) ((long) ((A) * (float) (B)))
#define   _IQ24mpyI32int(A,B) ((long) ((A) * (float) (B)))
#define   _IQ23mpyI32int(A,B) ((long) ((A) * (float) (B)))
#define   _IQ22mpyI32int(A,B) ((long) ((A) * (float) (B)))
#define   _IQ21mpyI32int(A,B) ((long) ((A) * (float) (B)))
#define   _IQ20mpyI32int(A,B) ((long) ((A) * (float) (B)))
#define   _IQ19mpyI32int(A,B) ((long) ((A) * (float) (B)))
#define   _IQ18mpyI32int(A,B) ((long) ((A) * (float) (B)))
#define   _IQ17mpyI32int(A,B) ((long) ((A) * (float) (B)))
#define   _IQ16mpyI32int(A,B) ((long) ((A) * (float) (B)))
#define   _IQ15mpyI32int(A,B) ((long) ((A) * (float) (B)))
#define   _IQ14mpyI32int(A,B) ((long) ((A) * (float) (B)))
#define   _IQ13mpyI32int(A,B) ((long) ((A) * (float) (B)))
#define   _IQ12mpyI32int(A,B) ((long) ((A) * (float) (B)))
#define   _IQ11mpyI32int(A,B) ((long) ((A) * (float) (B)))
#define   _IQ10mpyI32int(A,B) ((long) ((A) * (float) (B)))
#define   _IQ9mpyI32int(A,B)  ((long) ((A) * (float) (B)))
#define   _IQ8mpyI32int(A,B)  ((long) ((A) * (float) (B)))
#define   _IQ7mpyI32int(A,B)  ((long) ((A) * (float) (B)))
#define   _IQ6mpyI32int(A,B)  ((long) ((A) * (float) (B)))
#define   _IQ5mpyI32int(A,B)  ((long) ((A) * (float) (B)))
#define   _IQ4mpyI32int(A,B)  ((long) ((A) * (float) (B)))
#define   _IQ3mpyI32int(A,B)  ((long) ((A) * (float) (B)))
#define   _IQ2mpyI32int(A,B)  ((long) ((A) * (float) (B)))
#define   _IQ1mpyI32int(A,B)  ((long) ((A) * (float) (B)))
//---------------------------------------------------------------------------
#define   _IQmpyI32frac(A,B)    ((A) - (float)((long) ((A) * (float) (B))))
#define   _IQ30mpyI32frac(A,B)  ((A) - (float)((long) ((A) * (float) (B))))
#define   _IQ29mpyI32frac(A,B)  ((A) - (float)((long) ((A) * (float) (B))))
#define   _IQ28mpyI32frac(A,B)  ((A) - (float)((long) ((A) * (float) (B))))
#define   _IQ27mpyI32frac(A,B)  ((A) - (float)((long) ((A) * (float) (B))))
#define   _IQ26mpyI32frac(A,B)  ((A) - (float)((long) ((A) * (float) (B))))
#define   _IQ25mpyI32frac(A,B)  ((A) - (float)((long) ((A) * (float) (B))))
#define   _IQ24mpyI32frac(A,B)  ((A) - (float)((long) ((A) * (float) (B))))
#define   _IQ23mpyI32frac(A,B)  ((A) - (float)((long) ((A) * (float) (B))))
#define   _IQ22mpyI32frac(A,B)  ((A) - (float)((long) ((A) * (float) (B))))
#define   _IQ21mpyI32frac(A,B)  ((A) - (float)((long) ((A) * (float) (B))))
#define   _IQ20mpyI32frac(A,B)  ((A) - (float)((long) ((A) * (float) (B))))
#define   _IQ19mpyI32frac(A,B)  ((A) - (float)((long) ((A) * (float) (B))))
#define   _IQ18mpyI32frac(A,B)  ((A) - (float)((long) ((A) * (float) (B))))
#define   _IQ17mpyI32frac(A,B)  ((A) - (float)((long) ((A) * (float) (B))))
#define   _IQ16mpyI32frac(A,B)  ((A) - (float)((long) ((A) * (float) (B))))
#define   _IQ15mpyI32frac(A,B)  ((A) - (float)((long) ((A) * (float) (B))))
#define   _IQ14mpyI32frac(A,B)  ((A) - (float)((long) ((A) * (float) (B))))
#define   _IQ13mpyI32frac(A,B)  ((A) - (float)((long) ((A) * (float) (B))))
#define   _IQ12mpyI32frac(A,B)  ((A) - (float)((long) ((A) * (float) (B))))
#define   _IQ11mpyI32frac(A,B)  ((A) - (float)((long) ((A) * (float) (B))))
#define   _IQ10mpyI32frac(A,B)  ((A) - (float)((long) ((A) * (float) (B))))
#define   _IQ9mpyI32frac(A,B)   ((A) - (float)((long) ((A) * (float) (B))))
#define   _IQ8mpyI32frac(A,B)   ((A) - (float)((long) ((A) * (float) (B))))
#define   _IQ7mpyI32frac(A,B)   ((A) - (float)((long) ((A) * (float) (B))))
#define   _IQ6mpyI32frac(A,B)   ((A) - (float)((long) ((A) * (float) (B))))
#define   _IQ5mpyI32frac(A,B)   ((A) - (float)((long) ((A) * (float) (B))))
#define   _IQ4mpyI32frac(A,B)   ((A) - (float)((long) ((A) * (float) (B))))
#define   _IQ3mpyI32frac(A,B)   ((A) - (float)((long) ((A) * (float) (B))))
#define   _IQ2mpyI32frac(A,B)   ((A) - (float)((long) ((A) * (float) (B))))
#define   _IQ1mpyI32frac(A,B)   ((A) - (float)((long) ((A) * (float) (B))))
//---------------------------------------------------------------------------
#define   _IQmag(A,B)         sqrt((A)*(A) + (B)*(B))
#define   _IQ30mag(A,B)       sqrt((A)*(A) + (B)*(B))
#define   _IQ29mag(A,B)       sqrt((A)*(A) + (B)*(B))
#define   _IQ28mag(A,B)       sqrt((A)*(A) + (B)*(B))
#define   _IQ27mag(A,B)       sqrt((A)*(A) + (B)*(B))
#define   _IQ26mag(A,B)       sqrt((A)*(A) + (B)*(B))
#define   _IQ25mag(A,B)       sqrt((A)*(A) + (B)*(B))
#define   _IQ24mag(A,B)       sqrt((A)*(A) + (B)*(B))
#define   _IQ23mag(A,B)       sqrt((A)*(A) + (B)*(B))
#define   _IQ22mag(A,B)       sqrt((A)*(A) + (B)*(B))
#define   _IQ21mag(A,B)       sqrt((A)*(A) + (B)*(B))
#define   _IQ20mag(A,B)       sqrt((A)*(A) + (B)*(B))
#define   _IQ19mag(A,B)       sqrt((A)*(A) + (B)*(B))
#define   _IQ18mag(A,B)       sqrt((A)*(A) + (B)*(B))
#define   _IQ17mag(A,B)       sqrt((A)*(A) + (B)*(B))
#define   _IQ16mag(A,B)       sqrt((A)*(A) + (B)*(B))
#define   _IQ15mag(A,B)       sqrt((A)*(A) + (B)*(B))
#define   _IQ14mag(A,B)       sqrt((A)*(A) + (B)*(B))
#define   _IQ13mag(A,B)       sqrt((A)*(A) + (B)*(B))
#define   _IQ12mag(A,B)       sqrt((A)*(A) + (B)*(B))
#define   _IQ11mag(A,B)       sqrt((A)*(A) + (B)*(B))
#define   _IQ10mag(A,B)       sqrt((A)*(A) + (B)*(B))
#define   _IQ9mag(A,B)        sqrt((A)*(A) + (B)*(B))
#define   _IQ8mag(A,B)        sqrt((A)*(A) + (B)*(B))
#define   _IQ7mag(A,B)        sqrt((A)*(A) + (B)*(B))
#define   _IQ6mag(A,B)        sqrt((A)*(A) + (B)*(B))
#define   _IQ5mag(A,B)        sqrt((A)*(A) + (B)*(B))
#define   _IQ4mag(A,B)        sqrt((A)*(A) + (B)*(B))
#define   _IQ3mag(A,B)        sqrt((A)*(A) + (B)*(B))
#define   _IQ2mag(A,B)        sqrt((A)*(A) + (B)*(B))
#define   _IQ1mag(A,B)        sqrt((A)*(A) + (B)*(B))
//---------------------------------------------------------------------------
#define   _atoIQ(A)           atof(A)
#define   _atoIQ30(A)         atof(A)
#define   _atoIQ29(A)         atof(A)
#define   _atoIQ28(A)         atof(A)
#define   _atoIQ27(A)         atof(A)
#define   _atoIQ26(A)         atof(A)
#define   _atoIQ25(A)         atof(A)
#define   _atoIQ24(A)         atof(A)
#define   _atoIQ23(A)         atof(A)
#define   _atoIQ22(A)         atof(A)
#define   _atoIQ21(A)         atof(A)
#define   _atoIQ20(A)         atof(A)
#define   _atoIQ19(A)         atof(A)
#define   _atoIQ18(A)         atof(A)
#define   _atoIQ17(A)         atof(A)
#define   _atoIQ16(A)         atof(A)
#define   _atoIQ15(A)         atof(A)
#define   _atoIQ14(A)         atof(A)
#define   _atoIQ13(A)         atof(A)
#define   _atoIQ12(A)         atof(A)
#define   _atoIQ11(A)         atof(A)
#define   _atoIQ10(A)         atof(A)
#define   _atoIQ9(A)          atof(A)
#define   _atoIQ8(A)          atof(A)
#define   _atoIQ7(A)          atof(A)
#define   _atoIQ6(A)          atof(A)
#define   _atoIQ5(A)          atof(A)
#define   _atoIQ4(A)          atof(A)
#define   _atoIQ3(A)          atof(A)
#define   _atoIQ2(A)          atof(A)
#define   _atoIQ1(A)          atof(A)
//---------------------------------------------------------------------------
#define   _IQtoa(A, B, C)     sprintf(A, B, C)
#define   _IQ30toa(A, B, C)   sprintf(A, B, C)
#define   _IQ29toa(A, B, C)   sprintf(A, B, C)
#define   _IQ28toa(A, B, C)   sprintf(A, B, C)
#define   _IQ27toa(A, B, C)   sprintf(A, B, C)
#define   _IQ26toa(A, B, C)   sprintf(A, B, C)
#define   _IQ25toa(A, B, C)   sprintf(A, B, C)
#define   _IQ24toa(A, B, C)   sprintf(A, B, C)
#define   _IQ23toa(A, B, C)   sprintf(A, B, C)
#define   _IQ22toa(A, B, C)   sprintf(A, B, C)
#define   _IQ21toa(A, B, C)   sprintf(A, B, C)
#define   _IQ20toa(A, B, C)   sprintf(A, B, C)
#define   _IQ19toa(A, B, C)   sprintf(A, B, C)
#define   _IQ18toa(A, B, C)   sprintf(A, B, C)
#define   _IQ17toa(A, B, C)   sprintf(A, B, C)
#define   _IQ16toa(A, B, C)   sprintf(A, B, C)
#define   _IQ15toa(A, B, C)   sprintf(A, B, C)
#define   _IQ14toa(A, B, C)   sprintf(A, B, C)
#define   _IQ13toa(A, B, C)   sprintf(A, B, C)
#define   _IQ12toa(A, B, C)   sprintf(A, B, C)
#define   _IQ11toa(A, B, C)   sprintf(A, B, C)
#define   _IQ10toa(A, B, C)   sprintf(A, B, C)
#define   _IQ9toa(A, B, C)    sprintf(A, B, C)
#define   _IQ8toa(A, B, C)    sprintf(A, B, C)
#define   _IQ7toa(A, B, C)    sprintf(A, B, C)
#define   _IQ6toa(A, B, C)    sprintf(A, B, C)
#define   _IQ5toa(A, B, C)    sprintf(A, B, C)
#define   _IQ4toa(A, B, C)    sprintf(A, B, C)
#define   _IQ3toa(A, B, C)    sprintf(A, B, C)
#define   _IQ2toa(A, B, C)    sprintf(A, B, C)
#define   _IQ1toa(A, B, C)    sprintf(A, B, C)
//---------------------------------------------------------------------------
#define   _IQabs(A)    fabs(A)
#define   _IQ30abs(A)  fabs(A)
#define   _IQ29abs(A)  fabs(A)
#define   _IQ28abs(A)  fabs(A)
#define   _IQ27abs(A)  fabs(A)
#define   _IQ26abs(A)  fabs(A)
#define   _IQ25abs(A)  fabs(A)
#define   _IQ24abs(A)  fabs(A)
#define   _IQ23abs(A)  fabs(A)
#define   _IQ22abs(A)  fabs(A)
#define   _IQ21abs(A)  fabs(A)
#define   _IQ20abs(A)  fabs(A)
#define   _IQ19abs(A)  fabs(A)
#define   _IQ18abs(A)  fabs(A)
#define   _IQ17abs(A)  fabs(A)
#define   _IQ16abs(A)  fabs(A)
#define   _IQ15abs(A)  fabs(A)
#define   _IQ14abs(A)  fabs(A)
#define   _IQ13abs(A)  fabs(A)
#define   _IQ12abs(A)  fabs(A)
#define   _IQ11abs(A)  fabs(A)
#define   _IQ10abs(A)  fabs(A)
#define   _IQ9abs(A)   fabs(A)
#define   _IQ8abs(A)   fabs(A)
#define   _IQ7abs(A)   fabs(A)
#define   _IQ6abs(A)   fabs(A)
#define   _IQ5abs(A)   fabs(A)
#define   _IQ4abs(A)   fabs(A)
#define   _IQ3abs(A)   fabs(A)
#define   _IQ2abs(A)   fabs(A)
#define   _IQ1abs(A)   fabs(A)
//###########################################################################
#endif  // No more.
//###########################################################################

#endif /* __IQMATHLIB_H_INCLUDED__ */
