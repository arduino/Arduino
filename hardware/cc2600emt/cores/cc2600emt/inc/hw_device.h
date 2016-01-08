/******************************************************************************
*  Filename:       hw_device.h
*  Revised:        2015-09-23 13:35:28 +0200 (Wed, 23 Sep 2015)
*  Revision:       44644
*
*  Copyright (c) 2015, Texas Instruments Incorporated
*  All rights reserved.
*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions are met:
*
*  1) Redistributions of source code must retain the above copyright notice,
*     this list of conditions and the following disclaimer.
*
*  2) Redistributions in binary form must reproduce the above copyright notice,
*     this list of conditions and the following disclaimer in the documentation
*     and/or other materials provided with the distribution.
*
*  3) Neither the name of the ORGANIZATION nor the names of its contributors may
*     be used to endorse or promote products derived from this software without
*     specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
*  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
*  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
*  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
*  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
*  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
*  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
*  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
*  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
*  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
*  POSSIBILITY OF SUCH DAMAGE.
*
******************************************************************************/

#ifndef __HW_DEVICE_H__
#define __HW_DEVICE_H__

#include <inc/hw_chip_def.h>

#ifdef CC_GET_CHIP_PACKAGE

#if ( CC_GET_CHIP_PACKAGE == 0x7 )
//*****************************************************************************
//
// The following are defines for edge detection on wake up events for the
// CC26xx 7x7 packaged device.
//
//*****************************************************************************
#define AON_EVENT_DIO0         18
#define AON_EVENT_DIO1         17
#define AON_EVENT_DIO2         16
#define AON_EVENT_DIO3         15
#define AON_EVENT_DIO4         14
#define AON_EVENT_DIO5         13
#define AON_EVENT_DIO6         12
#define AON_EVENT_DIO7         11
#define AON_EVENT_DIO8         10
#define AON_EVENT_DIO9         9
#define AON_EVENT_DIO10        8
#define AON_EVENT_DIO11        7
#define AON_EVENT_DIO12        6
#define AON_EVENT_DIO13        5
#define AON_EVENT_DIO14        4
#define AON_EVENT_DIO15        3
#define AON_EVENT_DIO16        2
#define AON_EVENT_DIO17        1
#define AON_EVENT_DIO18        31
#define AON_EVENT_DIO19        30
#define AON_EVENT_DIO20        29
#define AON_EVENT_DIO21        28
#define AON_EVENT_DIO22        27
#define AON_EVENT_DIO23        26
#define AON_EVENT_DIO24        25
#define AON_EVENT_DIO25        24
#define AON_EVENT_DIO26        23
#define AON_EVENT_DIO27        22
#define AON_EVENT_DIO28        21
#define AON_EVENT_DIO29        20
#define AON_EVENT_DIO30        19
#define AON_EVENT_DIO31        0x3F
#endif // ( CC_GET_CHIP_PACKAGE == 0x7 )

#if ( CC_GET_CHIP_PACKAGE == 0x5 )
//*****************************************************************************
//
// The following are defines for edge detection on wake up events for the
// CC26xx 5x5 packaged device.
//
//*****************************************************************************
#define AON_EVENT_DIO0         15
#define AON_EVENT_DIO1         14
#define AON_EVENT_DIO2         13
#define AON_EVENT_DIO3         12
#define AON_EVENT_DIO4         11
#define AON_EVENT_DIO5         2
#define AON_EVENT_DIO6         1
#define AON_EVENT_DIO7         26
#define AON_EVENT_DIO8         25
#define AON_EVENT_DIO9         23
#define AON_EVENT_DIO10        24
#define AON_EVENT_DIO11        22
#define AON_EVENT_DIO12        21
#define AON_EVENT_DIO13        20
#define AON_EVENT_DIO14        19
#define AON_EVENT_DIO15        0x3F
#define AON_EVENT_DIO16        0x3F
#define AON_EVENT_DIO17        0x3F
#define AON_EVENT_DIO18        0x3F
#define AON_EVENT_DIO19        0x3F
#define AON_EVENT_DIO20        0x3F
#define AON_EVENT_DIO21        0x3F
#define AON_EVENT_DIO22        0x3F
#define AON_EVENT_DIO23        0x3F
#define AON_EVENT_DIO24        0x3F
#define AON_EVENT_DIO25        0x3F
#define AON_EVENT_DIO26        0x3F
#define AON_EVENT_DIO27        0x3F
#define AON_EVENT_DIO28        0x3F
#define AON_EVENT_DIO29        0x3F
#define AON_EVENT_DIO30        0x3F
#define AON_EVENT_DIO31        0x3F
#endif // ( CC_GET_CHIP_PACKAGE == 0x5 )

#if ( CC_GET_CHIP_PACKAGE == 0x4 )
//*****************************************************************************
//
// The following are defines for edge detection on wake up events for the
// CC26xx 4x4 packaged device.
//
//*****************************************************************************
#define AON_EVENT_DIO0         13
#define AON_EVENT_DIO1         12
#define AON_EVENT_DIO2         11
#define AON_EVENT_DIO3         2
#define AON_EVENT_DIO4         1
#define AON_EVENT_DIO5         26
#define AON_EVENT_DIO6         25
#define AON_EVENT_DIO7         24
#define AON_EVENT_DIO8         23
#define AON_EVENT_DIO9         22
#define AON_EVENT_DIO10        0x3F
#define AON_EVENT_DIO11        0x3F
#define AON_EVENT_DIO12        0x3F
#define AON_EVENT_DIO13        0x3F
#define AON_EVENT_DIO14        0x3F
#define AON_EVENT_DIO15        0x3F
#define AON_EVENT_DIO16        0x3F
#define AON_EVENT_DIO17        0x3F
#define AON_EVENT_DIO18        0x3F
#define AON_EVENT_DIO19        0x3F
#define AON_EVENT_DIO20        0x3F
#define AON_EVENT_DIO21        0x3F
#define AON_EVENT_DIO22        0x3F
#define AON_EVENT_DIO23        0x3F
#define AON_EVENT_DIO24        0x3F
#define AON_EVENT_DIO25        0x3F
#define AON_EVENT_DIO26        0x3F
#define AON_EVENT_DIO27        0x3F
#define AON_EVENT_DIO28        0x3F
#define AON_EVENT_DIO29        0x3F
#define AON_EVENT_DIO30        0x3F
#define AON_EVENT_DIO31        0x3F
#endif // ( CC_GET_CHIP_PACKAGE == 0x4 )

#endif // defined( CC_GET_CHIP_PACKAGE )
#endif // __HW_DEVICE_H__
