/*
 * flowcont.h - CC31xx/CC32xx Host Driver Implementation
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

#ifndef __FLOWCONT_H__
#define __FLOWCONT_H__

/******************************************************************************

 If building with a C++ compiler, make all of the definitions in this header
 have a C binding.

*****************************************************************************/
#ifdef	__cplusplus
extern "C" {
#endif

#define WLAN_STATUS_CONN 1
#define WLAN_STATUS_DISCONN 0
#define EVENT_Q_STATUS_NOT_EMPTY 1
#define EVENT_Q_STATUS_EMPTY 0
#define PENDING_RECV_STATUS_PRESENT 1
#define PENDING_RECV_STATUS_ABSENT 0
#define FW_BUSY_PKTS_STATUS_PRESENT 1
#define FW_BUSY_PKTS_STATUS_ABSENT 0
#define PENDING_CMD_STATUS_PRESENT 1
#define PENDING_CMD_STATUS_ABSENT 0

#define FLOW_CONT_WLAN_STATUS_BIT          0
#define FLOW_CONT_EVENT_Q_STATUS_BIT       1
#define FLOW_CONT_PENDING_RECV_STATUS_BIT  2
#define FLOW_CONT_FW_BUSY_PKTS_STATUS_BIT  3
#define FLOW_CONT_PENDING_CMD_STATUS_BIT   4

#define FLOW_CONT_WLAN_STATUS_DEFAULT          (WLAN_STATUS_DISCONN         << FLOW_CONT_WLAN_STATUS_BIT        )
#define FLOW_CONT_EVENT_Q_STATUS_DEFAULT       (EVENT_Q_STATUS_NOT_EMPTY    << FLOW_CONT_EVENT_Q_STATUS_BIT     )
#define FLOW_CONT_PENDING_RECV_STATUS_DEFAULT  (PENDING_RECV_STATUS_ABSENT  << FLOW_CONT_PENDING_RECV_STATUS_BIT)
#define FLOW_CONT_FW_BUSY_PKTS_STATUS_DEFAULT  (FW_BUSY_PKTS_STATUS_ABSENT  << FLOW_CONT_FW_BUSY_PKTS_STATUS_BIT)
#define FLOW_CONT_PENDING_CMD_STATUS_DEFAULT   (PENDING_CMD_STATUS_ABSENT   << FLOW_CONT_PENDING_CMD_STATUS_BIT )

#define FLOW_CONT_STATUS_DEFAULT (FLOW_CONT_WLAN_STATUS_DEFAULT        |\
                                  FLOW_CONT_EVENT_Q_STATUS_DEFAULT     |\
                                  FLOW_CONT_PENDING_RECV_STATUS_DEFAULT|\
                                  FLOW_CONT_FW_BUSY_PKTS_STATUS_DEFAULT|\
                                  FLOW_CONT_PENDING_CMD_STATUS_DEFAULT )

/*****************************************************************************

 Prototypes for the APIs.

*****************************************************************************/

#define FLOW_CONT_MIN 1

extern void _SlDrvFlowContInit(void);

extern void _SlDrvFlowContDeinit(void);

/*****************************************************************************

 Mark the end of the C bindings section for C++ compilers.

*****************************************************************************/
#ifdef  __cplusplus
}
#endif /* __cplusplus */

#endif /* __FLOWCONT_H__ */

