/*
 * datatypes.h - CC31xx/CC32xx Host Driver Implementation
 *
 * Copyright (C) 2014 Texas Instruments Incorporated - http://www.ti.com/ 
 * 
 * 
 *  Redistribution and use in source and binary forms, with or without 
 *  modification, are permitted provided that the following conditions 
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright 
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the 
 *    documentation and/or other materials provided with the   
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
*/

#ifndef __SL_DATA_TYPES__
#define __SL_DATA_TYPES__


#ifdef	__cplusplus
extern "C" {
#endif


#ifndef NULL
#define NULL        (0)
#endif

#ifndef FALSE
#define FALSE       (0)
#endif

#ifndef TRUE
#define TRUE        (!FALSE)
#endif

#ifndef OK
#define OK          (0)
#endif

#ifndef _INT8
#define _INT8
typedef signed   char   INT8;
#endif

#ifndef _UINT8
#define _UINT8
typedef unsigned char   UINT8;
#endif

#ifndef _INT16
#define _INT16
typedef signed   short  INT16;
#endif

#ifndef _UINT16
#define _UINT16
typedef unsigned short  UINT16;
#endif

#ifndef _BOOLEAN
#define _BOOLEAN
typedef unsigned char   BOOLEAN;
#endif

#ifdef _WIN32
    typedef unsigned int    UINT32, *PUINT32;
    typedef signed   int    INT32, *PINT32;
#else

#ifndef _INT32
#define _INT32
typedef signed   long   INT32;
#endif

#ifndef _UINT32
#define _UINT32
typedef unsigned long   UINT32;
#endif

#ifndef _UINT64
#define _UINT64
typedef unsigned long long   UINT64;
#endif

#endif /* _WIN32 */

typedef int             INT;
typedef char            CHAR;

typedef float			FLOAT;
typedef double			DOUBLE;

typedef UINT16  _SlOpcode_t;
typedef UINT8   _SlArgSize_t;
typedef INT16   _SlDataSize_t;
typedef INT     _SlReturnVal_t;

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif /* __SL_DATA_TYPE__ */
