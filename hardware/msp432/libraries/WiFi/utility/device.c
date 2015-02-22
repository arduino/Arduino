/*
 * device.c - CC31xx/CC32xx Host Driver Implementation
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

/*****************************************************************************

    API Prototypes

 *****************************************************************************/
#include "datatypes.h"
#include "SimpleLink.h"
#include "protocol.h"
#include "flowcont.h"
#include "driver.h"
#include "SimpleLinkForEnergia.h"


/*****************************************************************************
******************************************************************************/
#if _SL_INCLUDE_FUNC(sl_Task)
void sl_Task()
{
#ifdef _SlTaskEntry
    _SlTaskEntry();
#endif
}
#endif

int GetStartResponseConvert(unsigned long Status)
{
    switch(Status)
    {
    case INIT_STA_OK:
        return ROLE_STA;
    case INIT_STA_ERR:
        return ROLE_STA_ERR;
    case INIT_AP_OK:
        return ROLE_AP;
    case INIT_AP_ERR:
        return ROLE_AP_ERR;
    case INIT_P2P_OK:
        return ROLE_P2P;
    case INIT_P2P_ERR:
        return ROLE_P2P_ERR;
    default:
        return (int)Status;
    }
}


/*****************************************************************************
******************************************************************************/
#if _SL_INCLUDE_FUNC(sl_Start)
int sl_Start(const void* pIfHdl, char* pDevName, const P_INIT_CALLBACK pInitCallBack)
{
    int pObjIdx = MAX_CONCURRENT_ACTIONS;
    InitComplete_t  AsyncRsp;
  
    /* callback init */
    _SlDrvDriverCBInit();

    /* open the interface: usually SPI or UART */
    if (NULL == pIfHdl)
    {
        g_pCB->FD = sl_IfOpen(pDevName, 0);
    }
    else
    {
        g_pCB->FD = (_SlFd_t)pIfHdl;
    }
    /* Use Obj to issue the command, if not available try later */
    pObjIdx = _SlDrvWaitForPoolObj(START_STOP_ID,SL_MAX_SOCKETS);
    if (MAX_CONCURRENT_ACTIONS == pObjIdx)
    {
         return SL_POOL_IS_EMPTY;
    }
    OSI_RET_OK_CHECK(sl_LockObjLock(&g_pCB->ProtectionLockObj, SL_OS_WAIT_FOREVER));
    g_pCB->ObjPool[pObjIdx].pRespArgs = (UINT8 *)&AsyncRsp;
    OSI_RET_OK_CHECK(sl_LockObjUnlock(&g_pCB->ProtectionLockObj));

    if( g_pCB->FD >= 0)
    {
        sl_DeviceDisable();

        sl_IfRegIntHdlr((SL_P_EVENT_HANDLER)_SlDrvRxIrqHandler, NULL);

        sl_DeviceEnable();

        if (NULL != pInitCallBack)
        {
            g_pCB->pInitCallback = pInitCallBack;
        }
        else
        {
			OSI_RET_OK_CHECK(sl_SyncObjWait(&g_pCB->ObjPool[pObjIdx].SyncObj, SL_OS_WAIT_FOREVER));
	        /*release Pool Object*/
            _SlDrvReleasePoolObj(g_pCB->FunctionParams.AsyncExt.ActionIndex);
			return GetStartResponseConvert(AsyncRsp.Status);
		}
    }

    return (int)g_pCB->FD;
 
}
#endif

/*****************************************************************************
 _sl_HandleAsync_InitComplete - handles init complete signalling to 
                                a waiting object
****************************************************************************/
void _sl_HandleAsync_InitComplete(void *pVoidBuf)
{
    InitComplete_t     *pMsgArgs   = (InitComplete_t *)_SL_RESP_ARGS_START(pVoidBuf);

    OSI_RET_OK_CHECK(sl_LockObjLock(&g_pCB->ProtectionLockObj, SL_OS_WAIT_FOREVER));

    if(g_pCB->pInitCallback)
    {
		g_pCB->pInitCallback(GetStartResponseConvert(pMsgArgs->Status));
    }
    else
    {
		memcpy(g_pCB->ObjPool[g_pCB->FunctionParams.AsyncExt.ActionIndex].pRespArgs, pMsgArgs, sizeof(InitComplete_t));
        OSI_RET_OK_CHECK(sl_SyncObjSignal(&g_pCB->ObjPool[g_pCB->FunctionParams.AsyncExt.ActionIndex].SyncObj));
    }
   OSI_RET_OK_CHECK(sl_LockObjUnlock(&g_pCB->ProtectionLockObj));

   if(g_pCB->pInitCallback)
   {
     _SlDrvReleasePoolObj(g_pCB->FunctionParams.AsyncExt.ActionIndex);
   }
}

void _sl_HandleAsync_Stop(void *pVoidBuf)
{
    _BasicResponse_t     *pMsgArgs   = (_BasicResponse_t *)_SL_RESP_ARGS_START(pVoidBuf);

    VERIFY_SOCKET_CB(NULL != g_pCB->StopCB.pAsyncRsp);

    OSI_RET_OK_CHECK(sl_LockObjLock(&g_pCB->ProtectionLockObj, SL_OS_WAIT_FOREVER));

    memcpy(g_pCB->ObjPool[g_pCB->FunctionParams.AsyncExt.ActionIndex].pRespArgs, pMsgArgs, sizeof(_BasicResponse_t));
    OSI_RET_OK_CHECK(sl_SyncObjSignal(&g_pCB->ObjPool[g_pCB->FunctionParams.AsyncExt.ActionIndex].SyncObj));
    OSI_RET_OK_CHECK(sl_LockObjUnlock(&g_pCB->ProtectionLockObj));
    return;
}


/*****************************************************************************
 sl_stop
******************************************************************************/
typedef union
{
	_DevStopCommand_t  Cmd;
	_BasicResponse_t   Rsp;    
}_SlStopMsg_u;

const _SlCmdCtrl_t _SlStopCmdCtrl =
{
    SL_OPCODE_DEVICE_STOP_COMMAND,
    sizeof(_DevStopCommand_t),
    sizeof(_BasicResponse_t)
};

#if _SL_INCLUDE_FUNC(sl_Stop)
int sl_Stop(unsigned short timeout)
{
    int RetVal=0;
    _SlStopMsg_u      Msg;
    _BasicResponse_t  AsyncRsp;
	int				  pObjIdx = MAX_CONCURRENT_ACTIONS;
    /* if timeout is 0 the shutdown is forced immediately */
    if( 0 == timeout ) 
    {
      sl_IfRegIntHdlr(NULL, NULL);
      sl_DeviceDisable();
      RetVal = sl_IfClose(g_pCB->FD);

    }
    else
    {
      /* let the device make the shutdown using the defined timeout */
      Msg.Cmd.Timeout = timeout;
	  /* Use Obj to issue the command, if not available try later */
	  pObjIdx = _SlDrvWaitForPoolObj(START_STOP_ID,SL_MAX_SOCKETS);
	  if (MAX_CONCURRENT_ACTIONS == pObjIdx)
 	  {
		return SL_POOL_IS_EMPTY;
	  }
      OSI_RET_OK_CHECK(sl_LockObjLock(&g_pCB->ProtectionLockObj, SL_OS_WAIT_FOREVER));

      g_pCB->ObjPool[pObjIdx].pRespArgs = (UINT8 *)&AsyncRsp;

      OSI_RET_OK_CHECK(sl_LockObjUnlock(&g_pCB->ProtectionLockObj));

      VERIFY_RET_OK(_SlDrvCmdOp((_SlCmdCtrl_t *)&_SlStopCmdCtrl, &Msg, NULL));

      if(SL_OS_RET_CODE_OK == (int)Msg.Rsp.status)
      {
         OSI_RET_OK_CHECK(sl_SyncObjWait(&g_pCB->ObjPool[pObjIdx].SyncObj, SL_OS_WAIT_FOREVER));
         Msg.Rsp.status = AsyncRsp.status;
         RetVal = Msg.Rsp.status;
      }

      _SlDrvReleasePoolObj(pObjIdx);

      sl_IfRegIntHdlr(NULL, NULL);
      sl_DeviceDisable();
      sl_IfClose(g_pCB->FD);
    }
    _SlDrvDriverCBDeinit();

    return RetVal;
}
#endif


/*****************************************************************************
 sl_EventMaskSet/sl_EventMaskGet
*****************************************************************************/
typedef union
{
	_DevMaskEventSetCommand_t	    Cmd;
	_BasicResponse_t	            Rsp;
}_SlEventMaskSetMsg_u;

const _SlCmdCtrl_t _SlEventMaskSetCmdCtrl =
{
    SL_OPCODE_DEVICE_EVENTMASKSET,
    sizeof(_DevMaskEventSetCommand_t),
    sizeof(_BasicResponse_t)
};

#if _SL_INCLUDE_FUNC(sl_EventMaskSet)
int sl_EventMaskSet(unsigned char EventClass , unsigned long Mask)
{
    _SlEventMaskSetMsg_u Msg;

    Msg.Cmd.group = EventClass;
    Msg.Cmd.mask = Mask;

    VERIFY_RET_OK(_SlDrvCmdOp((_SlCmdCtrl_t *)&_SlEventMaskSetCmdCtrl, &Msg, NULL));

    return (int)Msg.Rsp.status;
}
#endif

/******************************************************************************

******************************************************************************/
typedef union
{
	_DevMaskEventGetCommand_t	    Cmd;
	_DevMaskEventGetResponse_t      Rsp;
}_SlEventMaskGetMsg_u;

const _SlCmdCtrl_t _SlEventMaskGetCmdCtrl =
{
    SL_OPCODE_DEVICE_EVENTMASKGET,
    sizeof(_DevMaskEventGetCommand_t),
    sizeof(_DevMaskEventGetResponse_t)
};

#if _SL_INCLUDE_FUNC(sl_EventMaskGet)
int sl_EventMaskGet(unsigned char EventClass, unsigned long *pMask)
{
    _SlEventMaskGetMsg_u Msg;

    Msg.Cmd.group = EventClass;

    VERIFY_RET_OK(_SlDrvCmdOp((_SlCmdCtrl_t *)&_SlEventMaskGetCmdCtrl, &Msg, NULL));

    *pMask = Msg.Rsp.mask;
    return SL_RET_CODE_OK;
}
#endif



/******************************************************************************
 sl_DevGet
******************************************************************************/

typedef union
{
	_DeviceSetGet_t	    Cmd;
	_DeviceSetGet_t	    Rsp;
}_SlDeviceMsgGet_u;

const _SlCmdCtrl_t _SlDeviceGetCmdCtrl =
{
	SL_OPCODE_DEVICE_DEVICEGET,
	sizeof(_DeviceSetGet_t),
	sizeof(_DeviceSetGet_t)
};



#if _SL_INCLUDE_FUNC(sl_DevGet)
long sl_DevGet(unsigned char DeviceGetId, unsigned char *pOption,unsigned char *pConfigLen, unsigned char *pValues)
{
	_SlDeviceMsgGet_u         Msg;
	_SlCmdExt_t               CmdExt;

	if (*pConfigLen == 0)
	{
		return SL_EZEROLEN;
	}

	if( pOption )
	{
	  CmdExt.TxPayloadLen = 0;
	  CmdExt.RxPayloadLen = *pConfigLen;
	  CmdExt.pTxPayload = NULL;
	  CmdExt.pRxPayload = (UINT8 *)pValues;
	  CmdExt.ActualRxPayloadLen = 0;
  
	  Msg.Cmd.DeviceSetId = DeviceGetId;

	  Msg.Cmd.Option   = (UINT16)*pOption;
	  
	  VERIFY_RET_OK(_SlDrvCmdOp((_SlCmdCtrl_t *)&_SlDeviceGetCmdCtrl, &Msg, &CmdExt));
	  
	  if( pOption )
	  {
		  *pOption = (UINT8)Msg.Rsp.Option;
	  }
	 
	  if (CmdExt.RxPayloadLen < CmdExt.ActualRxPayloadLen) 
	  {
		  *pConfigLen = (UINT8)CmdExt.RxPayloadLen;
		  return SL_ESMALLBUF;
	  }
	  else
	  {
		  *pConfigLen = (UINT8)CmdExt.ActualRxPayloadLen;
	  }
  
	  return (int)Msg.Rsp.Status;
	}
    else
    {
		return -1;
    }
}
#endif

/******************************************************************************
 sl_DevSet
******************************************************************************/
typedef union
{
    _DeviceSetGet_t    Cmd;
    _BasicResponse_t   Rsp;
}_SlDeviceMsgSet_u;

const _SlCmdCtrl_t _SlDeviceSetCmdCtrl =
{
    SL_OPCODE_DEVICE_DEVICESET,
    sizeof(_DeviceSetGet_t),
    sizeof(_BasicResponse_t)
};

#if _SL_INCLUDE_FUNC(sl_DevSet)
long sl_DevSet(unsigned char DeviceSetId ,unsigned char Option,unsigned char ConfigLen, unsigned char *pValues)
{
	_SlDeviceMsgSet_u         Msg;
	_SlCmdExt_t               CmdExt;

	CmdExt.TxPayloadLen = (ConfigLen+3) & (~3);
	CmdExt.RxPayloadLen = 0;
	CmdExt.pTxPayload = (UINT8 *)pValues;
	CmdExt.pRxPayload = NULL;


	Msg.Cmd.DeviceSetId    = DeviceSetId;
	Msg.Cmd.ConfigLen   = ConfigLen;
	Msg.Cmd.Option   = Option;

	VERIFY_RET_OK(_SlDrvCmdOp((_SlCmdCtrl_t *)&_SlDeviceSetCmdCtrl, &Msg, &CmdExt));

	return (int)Msg.Rsp.status;
}
#endif


/******************************************************************************
 _SlDrvDeviceEventHandler - handles internally device async events
******************************************************************************/
void _SlDrvDeviceEventHandler(void *pArgs)
{
    _SlResponseHeader_t      *pHdr       = (_SlResponseHeader_t *)pArgs;

    switch(pHdr->GenHeader.Opcode)
    {
        case SL_OPCODE_DEVICE_INITCOMPLETE:
            _sl_HandleAsync_InitComplete(pHdr);
            break;
        case SL_OPCODE_DEVICE_STOP_ASYNC_RESPONSE:
            _sl_HandleAsync_Stop(pHdr);
            break;
        case  SL_OPCODE_DEVICE_DEVICEASYNCFATALERROR:
#ifdef sl_GeneralEvtHdlr
            {
              _BasicResponse_t     *pMsgArgs   = (_BasicResponse_t *)_SL_RESP_ARGS_START(pHdr);
              SlDeviceEvent_t      devHandler;
              devHandler.EventData.deviceEvent.status = pMsgArgs->status & 0xFF;
              devHandler.EventData.deviceEvent.sender = (pMsgArgs->status >> 8) & 0xFF;
              sl_GeneralEvtHdlr(&devHandler);
            }
#endif
            break;
        default:
            SL_ERROR_TRACE2(MSG_306, "ASSERT: _SlDrvDeviceEventHandler : invalid opcode = 0x%x = %1", pHdr->GenHeader.Opcode, pHdr->GenHeader.Opcode);
            VERIFY_PROTOCOL(0);
    }
}


/******************************************************************************
 sl_UartSetMode 
******************************************************************************/
#ifdef SL_IF_TYPE_UART
typedef union
{
	_DevUartSetModeCommand_t	  Cmd;
	_DevUartSetModeResponse_t     Rsp;
}_SlUartSetModeMsg_u;

const _SlCmdCtrl_t _SlUartSetModeCmdCtrl =
{
    SL_OPCODE_DEVICE_SETUARTMODECOMMAND,
    sizeof(_DevUartSetModeCommand_t),
    sizeof(_DevUartSetModeResponse_t)
};


#if _SL_INCLUDE_FUNC(sl_UartSetMode)
int sl_UartSetMode(const SlUartIfParams_t* pUartParams)
{
	_SlUartSetModeMsg_u Msg;
        UINT32 magicCode = 0xFFFFFFFF;
        
	Msg.Cmd.BaudRate = pUartParams->BaudRate;
	Msg.Cmd.FlowControlEnable = pUartParams->FlowControlEnable;

    
    VERIFY_RET_OK(_SlDrvCmdOp((_SlCmdCtrl_t *)&_SlUartSetModeCmdCtrl, &Msg, NULL));
        
	/* cmd response OK, we can continue with the handshake */
	if (SL_RET_CODE_OK == Msg.Rsp.status)
	{
            sl_IfMaskIntHdlr();

            /* Close the comm port */
            sl_IfClose(g_pCB->FD);
              
              /* Re-open the comm port */
            sl_IfOpen((char*)pUartParams, UART_IF_OPEN_FLAG_RE_OPEN);

            sl_IfUnMaskIntHdlr();
              
            /* send the magic code and wait for the response */
            sl_IfWrite(g_pCB->FD, (unsigned char*)&magicCode, 4);
            
            magicCode = UART_SET_MODE_MAGIC_CODE;
            sl_IfWrite(g_pCB->FD, (unsigned char*)&magicCode, 4);
            
            /* clear magic code */
            magicCode = 0;
            
            /* wait (blocking) till the magic code to be returned from device */
            sl_IfRead(g_pCB->FD, (unsigned char*)&magicCode, 4);
            
            /* check for the received magic code matching */
            if (UART_SET_MODE_MAGIC_CODE != magicCode)
            {
                _SL_ASSERT(0);
            }
	}
       
	return (int)Msg.Rsp.status;
}
#endif
#endif


