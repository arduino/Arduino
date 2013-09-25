/* --COPYRIGHT--,BSD
 * Copyright (c) 2012, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * --/COPYRIGHT--*/
/* 
 * ======== types.h ========
 */
#ifndef _TYPES_H_
#define _TYPES_H_

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef __TI_COMPILER_VERSION__
#define __no_init
#define __data16
#endif

#ifdef __GNUC__
#define __no_init
#define __data16
#endif


/*----------------------------------------------------------------------------+
 | Include files                                                               |
 +----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------+
 | Function Prototype                                                          |
 +----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------+
 | Type Definition & Macro                                                     |
 +----------------------------------------------------------------------------*/
typedef char CHAR;
typedef unsigned char UCHAR;
typedef int INT;
typedef unsigned int UINT;
typedef short SHORT;
typedef unsigned short USHORT;
typedef long LONG;
typedef unsigned long ULONG;
typedef void VOID;
typedef unsigned long HANDLE;
typedef char *          PSTR;
typedef int BOOL;
typedef double DOUBLE;
typedef unsigned char BYTE;
typedef unsigned char*  PBYTE;
typedef unsigned int WORD;
typedef unsigned long DWORD;
typedef unsigned long*  PDWORD;

#define SUCCESS 0
#define FAILURE 1
#define VOID void

//DEVICE_REQUEST Structure
typedef struct _tDEVICE_REQUEST {
    BYTE bmRequestType;         //See bit definitions below
    BYTE bRequest;              //See value definitions below
    WORD wValue;                //Meaning varies with request type
    WORD wIndex;                //Meaning varies with request type
    WORD wLength;               //Number of bytes of data to transfer
} tDEVICE_REQUEST, *ptDEVICE_REQUEST;

typedef struct _tDEVICE_REQUEST_COMPARE {
    BYTE bmRequestType;         //See bit definitions below
    BYTE bRequest;              //See value definitions below
    BYTE bValueL;               //Meaning varies with request type
    BYTE bValueH;               //Meaning varies with request type
    BYTE bIndexL;               //Meaning varies with request type
    BYTE bIndexH;               //Meaning varies with request type
    BYTE bLengthL;              //Number of bytes of data to transfer (LSByte)
    BYTE bLengthH;              //Number of bytes of data to transfer (MSByte)
    BYTE bCompareMask;          //MSB is bRequest, if set 1, bRequest should be matched
    BYTE (*pUsbFunction)(VOID); //function pointer
} tDEVICE_REQUEST_COMPARE, *ptDEVICE_REQUEST_COMPARE;

//----------------------------------------------------------------------------
typedef enum {
    STATUS_ACTION_NOTHING,
    STATUS_ACTION_DATA_IN,
    STATUS_ACTION_DATA_OUT
} tSTATUS_ACTION_LIST;

typedef enum {
    DISABLE,
    ENABLE
} tSTATUS_EN_DISABLED;

#define FALSE   0
#define TRUE    1

/*----------------------------------------------------------------------------+
 | Constant Definition                                                         |
 +----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------+
 | End of header file                                                          |
 +----------------------------------------------------------------------------*/
#ifdef __cplusplus
}
#endif
#endif  /*
         * _TYPES_H_
         *------------------------ Nothing Below This Line --------------------------
         */
