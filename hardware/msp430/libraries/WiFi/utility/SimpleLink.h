/*
 * SimpleLink.h - CC31xx/CC32xx Host Driver Implementation
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


/*!
    \mainpage SimpleLink Driver

    \section intro_sec Introduction

 The SimpleLink CC31XX family allows to add Wi-Fi and networking capabilities
 to low-cost embedded products without having prior Wi-Fi, RF or networking expertise.
 The CC31XX is an ideal solution for microcontroller-based sensor and control
 applications such as home appliances, home automation and smart metering.
 The CC31XX has integrated a comprehensive TCP/IP network stack, Wi-Fi driver and
 security supplicant leading to easier portability to microcontrollers, to an
 ultra-low memory footprint, all without compromising the capabilities and robustness
 of the final application.



 \section modules_sec Modules
 To make it simple, TI's SimpleLink CC3100 platform capabilities were divided into modules by topic (Silo). 
 These capabilities range from basic device management through wireless
 network configuration, standard BSD socket and much more.
 Listed below are the various modules in the SimpleLink CC31XX driver:
     -# \ref device - controls the behavior of the CC3100 device (start/stop, events masking and obtaining specific device status)
     -# \ref wlan - controls the use of the WiFi WLAN module including:
	   - Connection features, such as: profiles, policies, SmartConfig™
	   - Advanced WLAN features, such as: scans, rx filters and rx statistics collection
     -# \ref socket - controls standard client/server sockets programming options and capabilities 
     -# \ref netapp - activates networking applications, such as: HTTP Server, DHCP Server, Ping, DNS and mDNS.
     -# \ref netcfg - controls the configuration of the device addresses (i.e. IP and MAC addresses)
     -# \ref fs     - provides file system capabilities to TI's CC31XX that can be used by both the CC31XX device and the user.


 \section 		proting_sec 	Porting

 The porting of the SimpleLink driver to any new platform is based on few simple steps.
 This guide takes you through this process step by step. Please follow the instructions
 carefully to avoid any problems during this process and to enable efficient and proper
 work with the device.
 Please notice that all modifications and porting adjustments of the driver should be
 made in the user.h header file only.
 Keep making any of the changes only in this file will ensure smoothly transaction to
 new versions of the driver at the future!


 \subsection 	porting_step1   Step 1 - Create your own user.h file

 The first step is to create a user.h file that will include your configurations and
 adjustments. You can use the empty template provided as part of this driver or
 you can choose to base your file on file from one of the wide range of examples
 applications provided by Texas Instruments


 \subsection    porting_step2   Step 2 - Select the capabilities set required for your application

 Texas Instruments made a lot of efforts to build set of predefined capability sets that would
 fit most of the target application.
 It is recommended to try and choose one of this predefined capabilities set before going to
 build your own customized set. If you find compatible set you can skip the rest of this step.

 The available sets are:
     -# SL_TINY     -   Compatible to be used on platforms with very limited resources. Provides
                        the best in class foot print in terms of Code and Data consumption.
     -# SL_SMALL    -   Compatible to most common networking applications. Provide the most
                        common APIs with decent balance between code size, data size, functionality
                        and performances
     -# SL_FULL     -   Provide access to all SimpleLink functionalities


 \subsection    porting_step3   Step 3 - Bind the device enable/disable output line

 The enable/disable line (nHib) provide mechanism to enter the device into the least current
 consumption mode. This mode could be used when no traffic is required (tx/rx).
 when this line is not connected to any IO of the host this define should be left empty.
 Not connecting this line results in ability to start the driver only once.


 \subsection 	porting_step4   Step 4 - Writing your interface communication driver

 The SimpleLink device support several standard communication protocol among SPI and
 UART. Depending on your needs and your hardware design, you should choose the
 communication channel type.
 The interface for this communication channel should include 4 simple access functions:
 -# open
 -# close
 -# read
 -# write

 The way this driver would be implemented is directly effecting the efficiency and
 the performances of the SimpleLink device on this platform.
 If your system has DMA you should consider to use it in order to increase the utilization
 of the communication channel
 If you have enough memory resources you should consider using a buffer to increase the
 efficiency of the write operations.


 \subsection     porting_step5   Step 5 - Choose your memory management model

 The SimpleLink driver support two memory models:
     -# Static (default)
     -# Dynamic

 If you choose to work in dynamic model you will have to provide alloc and free functions
 to be used by the Simple Link driver otherwise nothing need to be done.


 \subsection     porting_step6   Step 6 - OS adaptation

 The SimpleLink driver could run on two kind of platforms:
     -# Non-Os / Single Threaded (default)
     -# Multi-Threaded

 If you choose to work in multi-threaded environment under operating system you will have to
 provide some basic adaptation routines to allow the driver to protect access to resources
 for different threads (locking object) and to allow synchronization between threads (sync objects).
 In additional the driver support running without dedicated thread allocated solely to the simple
 link driver. If you choose to work in this mode, you should also supply a spawn method that
 will enable to run function on a temporary context.


 \subsection     porting_step7   Step 7 - Set your asynchronous event handlers routines

 The SimpleLink device generate asynchronous events in several situations.
 These asynchronous events could be masked.
 In order to catch these events you have to provide handler routines.
 Please notice that if you not provide a handler routine and the event is received,
 the driver will drop this event without any indication of this drop.


 \subsection     porting_step8   Step 8 - Run diagnostic tools to validate the correctness of your porting

 The driver is delivered with some porting diagnostic tools to simplify the porting validation process
 and to reduce issues latter. It is very important to follow carefully this process.

 The diagnostic process include:
     -# Validating Interface Communication Driver
     -# Validating OS adaptation layer
     -# Validating HW integrity
     -# Validating basic work with the device


    \section sw_license License


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
    
    

#include "user.h"

#ifndef __SIMPLELINK_H__
#define	__SIMPLELINK_H__

#ifdef	__cplusplus
extern "C"
{
#endif

#define SL_DRIVER_VERSION   "0.0.5.1"
#define SL_MAJOR_VERSION_NUM	0L
#define SL_MINOR_VERSION_NUM	0L
#define SL_VERSION_NUM		5L
#define SL_SUB_VERSION_NUM	1L

/* Compilation Integrity Check */



/*****************************************************************************

 Predefined configurations

 *****************************************************************************/

#ifdef SL_TINY
#undef SL_INC_ARG_CHECK
#undef SL_INC_EXT_API
#undef SL_INC_SOCK_CLIENT_SIDE_API
#undef SL_INC_SOCK_SEND_API
#undef SL_INC_WLAN_PKG
#undef SL_INC_NET_APP_PKG
#undef SL_INC_NET_CFG_PKG
#undef SL_INC_FS_PKG
#define SL_INC_STD_BSD_API_NAMING
#define SL_INC_SOCK_SERVER_SIDE_API
#define SL_INC_SOCK_RECV_API
#define SL_INC_SOCKET_PKG
#endif

#ifdef SL_SMALL
#undef SL_INC_EXT_API
#undef SL_INC_NET_APP_PKG
#undef SL_INC_NET_CFG_PKG
#undef SL_INC_FS_PKG
#define SL_INC_ARG_CHECK
#define SL_INC_WLAN_PKG
#define SL_INC_SOCKET_PKG
#define SL_INC_STD_BSD_API_NAMING
#define SL_INC_SOCK_CLIENT_SIDE_API
#define SL_INC_SOCK_SERVER_SIDE_API
#define SL_INC_SOCK_RECV_API
#define SL_INC_SOCK_SEND_API
#endif

#ifdef SL_FULL
#define SL_INC_EXT_API
#define SL_INC_NET_APP_PKG
#define SL_INC_NET_CFG_PKG
#define SL_INC_FS_PKG
#define SL_INC_ARG_CHECK
#define SL_INC_WLAN_PKG
#define SL_INC_SOCKET_PKG
#define SL_INC_STD_BSD_API_NAMING
#define SL_INC_SOCK_CLIENT_SIDE_API
#define SL_INC_SOCK_SERVER_SIDE_API
#define SL_INC_SOCK_RECV_API
#define SL_INC_SOCK_SEND_API
#endif


typedef void (*_SlSpawnEntryFunc_t)(void* pValue);


#define SL_RET_CODE_OK                          (0)
#define SL_RET_CODE_INVALID_INPUT               (-2)
#define SL_RET_CODE_SELF_ERROR                  (-3)
#define SL_RET_CODE_NWP_IF_ERROR                (-4)
#define SL_RET_CODE_MALLOC_ERROR                (-5)

#define sl_Memcpy		memcpy
#define sl_Memset		memset

#define sl_SyncObjClear(pObj)		sl_SyncObjWait(pObj,SL_OS_NO_WAIT)

#define SL_MAX_SOCKETS      8



#ifdef	__cplusplus
}
#endif /*  __cplusplus */


#ifdef SL_PLATFORM_MULTI_THREADED
    #include "spawn.h"
#else
    #include "nonos.h"
#endif

/* 
   objInclusion.h and user.h must be included before all api header files 
   objInclusion.h must be the last arrangement just before including the API header files 
   since it based on the other configurations to decide which object should be included 
*/
#include "objInclusion.h"
#include "datatypes.h"
#include "trace.h"
#include "fs.h"
#include "socket.h"
#include "netapp.h"
#include "wlan.h"
#include "device.h"
#include "netcfg.h"
#include "wlan_rx_filters.h"


/*****************************************************************************

Create prototypes for all event handlers

*****************************************************************************/

#if (defined(sl_GeneralEvtHdlr))
extern void sl_GeneralEvtHdlr(SlDeviceEvent_t *pSlDeviceEvent);
#endif

#if (defined(sl_WlanEvtHdlr))
extern void sl_WlanEvtHdlr(SlWlanEvent_t *pSlWlanEvent);
#endif

#if (defined(sl_NetAppEvtHdlr))
extern void sl_NetAppEvtHdlr(SlNetAppEvent_t *pSlSockEvent);
#endif

#if (defined(sl_SockEvtHdlr))
extern void sl_SockEvtHdlr(SlSockEvent_t *pSlSockEvent);
#endif

#if (defined(sl_HttpServerCallback))
extern void sl_HttpServerCallback(SlHttpServerEvent_t *pSlHttpServerEvent, SlHttpServerResponse_t *pSlHttpServerResponse);
#endif

#endif	/*  __SIMPLELINK_H__ */
