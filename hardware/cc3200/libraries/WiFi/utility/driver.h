/*
 * driver.h - CC31xx/CC32xx Host Driver Implementation
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
 
#ifndef __DRIVER_INT_H__
#define __DRIVER_INT_H__

typedef struct
{
    _SlOpcode_t      Opcode;
    _SlArgSize_t     TxDescLen;
    _SlArgSize_t     RxDescLen;
}_SlCmdCtrl_t;

typedef struct
{
    UINT16  TxPayloadLen;
    UINT16  RxPayloadLen;
	UINT16  ActualRxPayloadLen;
    UINT8   *pTxPayload;
    UINT8   *pRxPayload;
}_SlCmdExt_t;


typedef struct _SlArgsData_t
{
    UINT8	 *pArgs;
	UINT8    *pData;
} _SlArgsData_t;


typedef struct _SlPoolObj_t
{
    _SlSyncObj_t	      SyncObj;
	 UINT8                *pRespArgs;
	UINT8			      ActionID; 
	UINT8			      AdditionalData; /* use for socketID and one bit which indicate supprt IPV6 or not (1=support, 0 otherwise) */
    UINT8				  NextIndex;  

} _SlPoolObj_t;


typedef enum
{
	SOCKET_0,
	SOCKET_1,
	SOCKET_2,
	SOCKET_3,
	SOCKET_4,
	SOCKET_5,
	SOCKET_6,
	SOCKET_7,
	MAX_SOCKET_ENUM_IDX,
    ACCEPT_ID = MAX_SOCKET_ENUM_IDX,
    CONNECT_ID,
	SELECT_ID,
	GETHOSYBYNAME_ID,
	GETHOSYBYSERVICE_ID,
	PING_ID,
    START_STOP_ID,
	RECV_ID
}_SlActionID_e;

typedef struct _SlActionLookup_t
{
    UINT8					ActionID;
    UINT16				    ActionAsyncOpcode;
	_SlSpawnEntryFunc_t		AsyncEventHandler; 

} _SlActionLookup_t;


typedef struct
{
    UINT8           TxPoolCnt;
    _SlLockObj_t    TxLockObj;
    _SlSyncObj_t    TxSyncObj;
}_SlFlowContCB_t;

typedef enum
{
    RECV_RESP_CLASS,
    CMD_RESP_CLASS,
    ASYNC_EVT_CLASS,
    DUMMY_MSG_CLASS
}_SlRxMsgClass_e;

typedef struct
{
    UINT8                   *pAsyncBuf;         /* place to write pointer to buffer with CmdResp's Header + Arguments */
	UINT8					ActionIndex; 
    _SlSpawnEntryFunc_t     AsyncEvtHandler;    /* place to write pointer to AsyncEvent handler (calc-ed by Opcode)   */
    _SlRxMsgClass_e         RxMsgClass;         /* type of Rx message                                                 */
} AsyncExt_t;

typedef UINT8 _SlSd_t;

typedef struct
{
	_SlCmdCtrl_t         *pCmdCtrl;
	UINT8                *pTxRxDescBuff;
	_SlCmdExt_t          *pCmdExt;
    AsyncExt_t            AsyncExt;
}_SlFunctionParams_t;


typedef struct
{
    _SlFd_t                          FD;
    _SlLockObj_t                     GlobalLockObj;
    _SlCommandHeader_t               TempProtocolHeader;
    P_INIT_CALLBACK                  pInitCallback;

    _SlPoolObj_t                    ObjPool[MAX_CONCURRENT_ACTIONS];
	UINT8							FreePoolIdx;
	UINT8							PendingPoolIdx;
	UINT8							ActivePoolIdx;
	UINT32							ActiveActionsBitmap;
	_SlLockObj_t                    ProtectionLockObj;

    _SlSyncObj_t                     CmdSyncObj;  
    UINT8                            IsCmdRespWaited;

    _SlFlowContCB_t                  FlowContCB;

    UINT8                            TxSeqNum;
    volatile UINT8                   RxIrqCnt;
    UINT8                            RxDoneCnt;
    UINT8                            SocketNonBlocking;
	UINT8                            SocketTXFailure;
    UINT8                            RelayFlagsViaRxPayload;
    /* for stack reduction the parameters are globals */
    _SlFunctionParams_t              FunctionParams;

}_SlDriverCb_t;

extern _SlDriverCb_t* g_pCB;
extern P_SL_DEV_PING_CALLBACK  pPingCallBackFunc;
extern void _SlDrvDriverCBInit(void);
extern void _SlDrvDriverCBDeinit(void);
extern void _SlDrvRxIrqHandler(void *pValue);
extern _SlReturnVal_t  _SlDrvCmdOp(_SlCmdCtrl_t *pCmdCtrl , void* pTxRxDescBuff , _SlCmdExt_t* pCmdExt);
extern _SlReturnVal_t  _SlDrvCmdSend(_SlCmdCtrl_t *pCmdCtrl , void* pTxRxDescBuff , _SlCmdExt_t* pCmdExt);
extern _SlReturnVal_t  _SlDrvDataReadOp(_SlSd_t Sd, _SlCmdCtrl_t *pCmdCtrl , void* pTxRxDescBuff , _SlCmdExt_t* pCmdExt);
extern _SlReturnVal_t  _SlDrvDataWriteOp(_SlSd_t Sd, _SlCmdCtrl_t *pCmdCtrl , void* pTxRxDescBuff , _SlCmdExt_t* pCmdExt);
extern int  _SlDrvBasicCmd(_SlOpcode_t Opcode);

extern void _sl_HandleAsync_InitComplete(void *pVoidBuf);
extern void _sl_HandleAsync_Connect(void *pVoidBuf);
extern void _sl_HandleAsync_Accept(void *pVoidBuf);
extern void _sl_HandleAsync_Select(void *pVoidBuf);
extern void _sl_HandleAsync_DnsGetHostByName(void *pVoidBuf);
extern void _sl_HandleAsync_DnsGetHostByService(void *pVoidBuf);
extern void _sl_HandleAsync_DnsGetHostByAddr(void *pVoidBuf);
extern void _sl_HandleAsync_PingResponse(void *pVoidBuf);
extern void _SlDrvNetAppEventHandler(void *pArgs);
extern void _SlDrvDeviceEventHandler(void *pArgs);
extern void _sl_HandleAsync_Stop(void *pVoidBuf);
extern int _SlDrvWaitForPoolObj(UINT32 ActionID, UINT8 SocketID);
extern void _SlDrvReleasePoolObj(UINT8 pObj);
extern void _SlDrvObjInit(void);  

#define _SL_PROTOCOL_ALIGN_SIZE(msgLen)             (((msgLen)+3) & (~3))
#define _SL_IS_PROTOCOL_ALIGNED_SIZE(msgLen)        (!((msgLen) & 3))
#define _SL_PROTOCOL_CALC_LEN(pCmdCtrl,pCmdExt)     ((pCmdExt) ? \
                                                     (_SL_PROTOCOL_ALIGN_SIZE(pCmdCtrl->TxDescLen) + _SL_PROTOCOL_ALIGN_SIZE(pCmdExt->TxPayloadLen)) : \
                                                     (_SL_PROTOCOL_ALIGN_SIZE(pCmdCtrl->TxDescLen)))
#endif /* __DRIVER_INT_H__ */
