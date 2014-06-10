/*
 SimpleLinkCallbacks.c
 Author: Noah Luskey
 Use: Place code for callbacks in this file if desired.
 
 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.
 
 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */


#include "simplelink.h"



#if (defined(sl_GeneralEvtHdlr))
extern void sl_GeneralEvtHdlr(SlDeviceEvent_t *pSlDeviceEvent)
{
}
#endif

#if (defined(sl_WlanEvtHdlr))
extern void sl_WlanEvtHdlr(SlWlanEvent_t *pSlWlanEvent)
{
}
#endif

#if (defined(sl_NetAppEvtHdlr))
extern void sl_NetAppEvtHdlr(SlNetAppEvent_t *pSlSockEvent)
{
}
#endif

#if (defined(sl_SockEvtHdlr))
extern void sl_SockEvtHdlr(SlSockEvent_t *pSlSockEvent)
{
}
#endif

#if (defined(sl_HttpServerCallback))
extern void sl_HttpServerCallback(SlHttpServerEvent_t *pSlHttpServerEvent, SlHttpServerResponse_t *pSlHttpServerResponse)
{
}
#endif