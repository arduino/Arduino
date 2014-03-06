//*****************************************************************************
//
// lwiplib.h - Prototypes for the lwIP library wrapper API.
//
// Copyright (c) 2008-2013 Texas Instruments Incorporated.  All rights reserved.
// Software License Agreement
// 
// Texas Instruments (TI) is supplying this software for use solely and
// exclusively on TI's microcontroller products. The software is owned by
// TI and/or its suppliers, and is protected under applicable copyright
// laws. You may not combine this software with "viral" open-source
// software in order to form a larger program.
// 
// THIS SOFTWARE IS PROVIDED "AS IS" AND WITH ALL FAULTS.
// NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT
// NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. TI SHALL NOT, UNDER ANY
// CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR CONSEQUENTIAL
// DAMAGES, FOR ANY REASON WHATSOEVER.
// 
// This is part of revision 2.0.1.11577 of the Tiva Utility Library.
//
//*****************************************************************************

#ifndef __LWIPLIB_H__
#define __LWIPLIB_H__

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

//*****************************************************************************
//
// lwIP Options
//
//*****************************************************************************
#include "lwip/opt.h"

//*****************************************************************************
//
// Ensure that AUTOIP COOP option is configured correctly.
//
//*****************************************************************************
#undef LWIP_DHCP_AUTOIP_COOP
#define LWIP_DHCP_AUTOIP_COOP   ((LWIP_DHCP) && (LWIP_AUTOIP))

//*****************************************************************************
//
// lwIP API Header Files
//
//*****************************************************************************
#include <stdint.h>
#include "lwip/api.h"
#include "lwip/netifapi.h"
#include "lwip/tcp.h"
#include "lwip/udp.h"
#include "lwip/tcpip.h"
#include "lwip/sockets.h"
#include "lwip/mem.h"
#include "lwip/stats.h"
#include "lwip/def.h"
#include "lwip/tcp_impl.h"
#include "lwip/timers.h"
#include "lwip/netif.h"
//*****************************************************************************
//
// IP Address Acquisition Modes
//
//*****************************************************************************
#define IPADDR_USE_STATIC       0
#define IPADDR_USE_DHCP         1
#define IPADDR_USE_AUTOIP       2

//*****************************************************************************
//
// Hardware timer interrupt callback function type (available only when running
// on TM4C parts).  This function is called in interrupt context whenever the
// Ethernet MAC reports an interrupt from the IEEE-1588 timestamping
// timer.  The first parameter is the base address of the MAC and the second
// is the interrupt status as reported via EthMACTimestampIntStatus.
//
//*****************************************************************************
typedef void (* tHardwareTimerHandler)(uint32_t ui32Base,
                                       uint32_t ui32IntStatus);

//*****************************************************************************
//
// lwIP Abstraction Layer API
//
//*****************************************************************************
extern void lwIPInit(uint32_t ui32SysClkHz, const uint8_t *pui8Mac,
                     uint32_t ui32IPAddr, uint32_t ui32NetMask,
                     uint32_t ui32GWAddr, uint32_t ui32IPMode);
extern void lwIPTimerCallbackRegister(tHardwareTimerHandler pfnTimerFunc);
extern void lwIPTimer(uint32_t ui32TimeMS);
extern void lwIPEthernetIntHandler(void);
extern uint32_t lwIPLocalIPAddrGet(void);
extern uint32_t lwIPLocalNetMaskGet(void);
extern uint32_t lwIPLocalGWAddrGet(void);
extern uint32_t lwIPDNSAddrGet(void);
extern void lwIPDNSAddrSet(uint32_t dns_server);
extern bool lwIPLinkActive(void);
extern void lwIPLocalMACGet(uint8_t *pui8Mac);
extern void lwIPNetworkConfigChange(uint32_t ui32IPAddr, uint32_t ui32NetMask,
                                    uint32_t ui32GWAddr, uint32_t ui32IPMode);
extern uint32_t lwIPAcceptUDPPort(uint16_t ui16Port);
extern void lwIPNetifSetStatusCallback(netif_status_callback_fn status_callback);
extern bool lwIPDHCPWaitLeaseValid(void);
//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif // __LWIPLIB_H__
