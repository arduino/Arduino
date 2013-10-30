#ifndef __SimplelinkWifi_H__
#define __SimplelinkWifi_H__

#include "hci.h"
#include "interface.h"
#include "cc3000_common.h"
#include "evnt_handler.h"

#include "host_driver_version.h"
#include "netapp.h"
#include "nvmem.h"
#include "security.h"
#include "socket.h"
#include "board.h"
#include "patch.h"
#include "wlan.h"

#include "tcp.h"
#include "udp.h"
#include "wl_definitions.h"

#define RX_BUF_SIZE (CC3000_RX_BUFFER_SIZE-14)
#define TX_BUF_SIZE (CC3000_TX_BUFFER_SIZE-14)
//*****************************************************************************
//
//connect to an AP
//
//*****************************************************************************

void CC3000_UsynchCallback(long , char * , unsigned char );



//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef	__cplusplus
}
#endif // __cplusplus

#endif	// __SimplelinkWifi_H__
