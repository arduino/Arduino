/*
 * fs.c - CC31xx/CC32xx Host Driver Implementation
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
#include "driver.h"


#define sl_min(a,b) (((a) < (b)) ? (a) : (b))
#define MAX_NVMEM_CHUNK_SIZE  1460


/*****************************************************************************/
/*  sl_FsOpen */ 
/*****************************************************************************/
typedef union
{
	_FsOpenCommand_t	    Cmd;
	_FsOpenResponse_t	    Rsp;
}_SlFsOpenMsg_u;

const _SlCmdCtrl_t _SlFsOpenCmdCtrl =
{
    SL_OPCODE_NVMEM_FILEOPEN,
    sizeof(_FsOpenCommand_t),
    sizeof(_FsOpenResponse_t)
};

unsigned short sl_Strlen(const unsigned char *buffer)
{
    unsigned short len = 0;
    if( buffer != NULL )
    {
      while(*buffer++) len++;
    }
    return len;
}


unsigned long _GetCreateFsMode(unsigned long maxSizeInBytes,unsigned long accessFlags)
{
   unsigned long granIdx = 0;
   unsigned long granNum = 0;
   unsigned long granTable[_FS_MAX_MODE_SIZE_GRAN] = {256,1024,4096,16384,65536}; 
   for(granIdx= _FS_MODE_SIZE_GRAN_256B ;granIdx< _FS_MAX_MODE_SIZE_GRAN;granIdx++) 
   {                                                       
       if( granTable[granIdx]*255 >= maxSizeInBytes ) 
            break;                                                      
   }                                                                 
   granNum = maxSizeInBytes/granTable[granIdx];
   if( maxSizeInBytes % granTable[granIdx] != 0 )
         granNum++;

   return _FS_MODE(_FS_MODE_OPEN_WRITE_CREATE_IF_NOT_EXIST,  granIdx, granNum, accessFlags);
}


#if _SL_INCLUDE_FUNC(sl_FsOpen)
long sl_FsOpen(unsigned char *pFileName,unsigned long AccessModeAndMaxSize, unsigned long *pToken,long *pFileHandle)
{
    _SlReturnVal_t        RetVal;
    _SlFsOpenMsg_u        Msg;
    _SlCmdExt_t           CmdExt;

    CmdExt.TxPayloadLen = (sl_Strlen(pFileName)+4) & (~3); // add 4: 1 for NULL and the 3 for align 
    CmdExt.RxPayloadLen = 0;
    CmdExt.pTxPayload = pFileName;
    CmdExt.pRxPayload = NULL;

    Msg.Cmd.Mode          =  AccessModeAndMaxSize; 

	if(pToken != NULL)
	{
       Msg.Cmd.Token         = *pToken;
	}
    else
	{
       Msg.Cmd.Token         = 0;
	}



    RetVal = _SlDrvCmdOp((_SlCmdCtrl_t *)&_SlFsOpenCmdCtrl, &Msg, &CmdExt);
    *pFileHandle = Msg.Rsp.FileHandle;
	if (pToken != NULL)
	{
        *pToken =      Msg.Rsp.Token;
	}
       
	/* in case of an error, return the erros file handler as an error code */
	if( *pFileHandle < 0 )
	{
	   return *pFileHandle;
	}
    return (long)RetVal;
}
#endif

/*****************************************************************************/
/* sl_FsClose */ 
/*****************************************************************************/
typedef union
{
	_FsCloseCommand_t	    Cmd;
	_BasicResponse_t	    Rsp;
}_SlFsCloseMsg_u;

const _SlCmdCtrl_t _SlFsCloseCmdCtrl =
{
    SL_OPCODE_NVMEM_FILECLOSE,
    sizeof(_FsCloseCommand_t),
    sizeof(_FsCloseResponse_t)
};

#if _SL_INCLUDE_FUNC(sl_FsClose)
int sl_FsClose(long FileHdl, unsigned char* pCeritificateFileName,unsigned char* pSignature ,unsigned long SignatureLen)
{
    _SlFsCloseMsg_u Msg = {0};
    _SlCmdExt_t         ExtCtrl;
    
    Msg.Cmd.FileHandle             = FileHdl;
    if( pCeritificateFileName != NULL )
    {
        Msg.Cmd.CertificFileNameLength = (sl_Strlen(pCeritificateFileName)+4) & (~3); /* add 4: 1 for NULL and the 3 for align */
    }
    Msg.Cmd.SignatureLen           = SignatureLen;
    
    ExtCtrl.TxPayloadLen = ((SignatureLen+3) & (~3)); /* align */
    ExtCtrl.pTxPayload   = pSignature;
    ExtCtrl.RxPayloadLen = Msg.Cmd.CertificFileNameLength;
    ExtCtrl.pRxPayload   = pCeritificateFileName; /* Add signature */
    
    if(ExtCtrl.pRxPayload != NULL &&  ExtCtrl.RxPayloadLen != 0)
    {
        g_pCB->RelayFlagsViaRxPayload = TRUE;
    }

    VERIFY_RET_OK(_SlDrvCmdOp((_SlCmdCtrl_t *)&_SlFsCloseCmdCtrl, &Msg, &ExtCtrl));

    return (int)((short)Msg.Rsp.status);
}
#endif


/*****************************************************************************/
/* sl_FsRead */ 
/*****************************************************************************/
typedef union
{
	_FsReadCommand_t	    Cmd;
	_FsReadResponse_t	    Rsp;
}_SlFsReadMsg_u;

const _SlCmdCtrl_t _SlFsReadCmdCtrl =
{
    SL_OPCODE_NVMEM_FILEREADCOMMAND,
    sizeof(_FsReadCommand_t),
    sizeof(_FsReadResponse_t)
};

 
#if _SL_INCLUDE_FUNC(sl_FsRead)
long sl_FsRead(long FileHdl, unsigned long Offset, unsigned char* pData, unsigned long Len)
{
    _SlFsReadMsg_u      Msg;
    _SlCmdExt_t         ExtCtrl;
    unsigned short      ChunkLen;
    _SlReturnVal_t      RetVal =0;
    long                RetCount = 0;

    ExtCtrl.TxPayloadLen = 0;
    ExtCtrl.pTxPayload   = NULL;

    ChunkLen = (unsigned short)sl_min(MAX_NVMEM_CHUNK_SIZE,Len);
    ExtCtrl.RxPayloadLen = ChunkLen;
    ExtCtrl.pRxPayload   = (UINT8 *)(pData);
    Msg.Cmd.Offset       = Offset;
    Msg.Cmd.Len          = ChunkLen;
    Msg.Cmd.FileHandle   = FileHdl;
    do
    {
        RetVal = _SlDrvCmdOp((_SlCmdCtrl_t *)&_SlFsReadCmdCtrl, &Msg, &ExtCtrl);
        if(SL_OS_RET_CODE_OK == RetVal)
        {
            if( Msg.Rsp.status < 0)
            {
                if( RetCount > 0)
                {
                   return RetCount;
                }
                else
                {
                   return Msg.Rsp.status;
                }
            }
            RetCount += (long)Msg.Rsp.status;
            Len -= ChunkLen;
            Offset += ChunkLen;
            Msg.Cmd.Offset      = Offset;
            ExtCtrl.pRxPayload   += ChunkLen;
            ChunkLen = (unsigned short)sl_min(MAX_NVMEM_CHUNK_SIZE,Len);
            ExtCtrl.RxPayloadLen  = ChunkLen;
            Msg.Cmd.Len           = ChunkLen;
            Msg.Cmd.FileHandle  = FileHdl;
        }
        else
        {
            return RetVal;
        }
    }while(ChunkLen > 0);

    return (long)RetCount;
}
#endif

/*****************************************************************************/
/* sl_FsWrite */ 
/*****************************************************************************/
typedef union
{
	_FsWriteCommand_t	    Cmd;
	_FsWriteResponse_t	    Rsp;
}_SlFsWriteMsg_u;

const _SlCmdCtrl_t _SlFsWriteCmdCtrl =
{
    SL_OPCODE_NVMEM_FILEWRITECOMMAND,
    sizeof(_FsWriteCommand_t),
    sizeof(_FsWriteResponse_t)
};



#if _SL_INCLUDE_FUNC(sl_FsWrite)
long sl_FsWrite(long FileHdl, unsigned long Offset, unsigned char* pData, unsigned long Len)
{
    _SlFsWriteMsg_u     Msg;
    _SlCmdExt_t         ExtCtrl;
    unsigned short      ChunkLen;
    _SlReturnVal_t      RetVal;
    long                RetCount = 0;

    ExtCtrl.RxPayloadLen = 0;
    ExtCtrl.pRxPayload   = NULL;

    ChunkLen = (unsigned short)sl_min(MAX_NVMEM_CHUNK_SIZE,Len);
    ExtCtrl.TxPayloadLen = ChunkLen;
    ExtCtrl.pTxPayload   = (UINT8 *)(pData);
    Msg.Cmd.Offset      = Offset;
    Msg.Cmd.Len          = ChunkLen;
    Msg.Cmd.FileHandle  = FileHdl;

    do
    {
    
        RetVal = _SlDrvCmdOp((_SlCmdCtrl_t *)&_SlFsWriteCmdCtrl, &Msg, &ExtCtrl);
        if(SL_OS_RET_CODE_OK == RetVal)
        {
            if( Msg.Rsp.status < 0)
            {
                if( RetCount > 0)
                {
                   return RetCount;
                }
                else
                {
                   return Msg.Rsp.status;
                }
            }

            RetCount += (long)Msg.Rsp.status;
            Len -= ChunkLen;
            Offset += ChunkLen;
            Msg.Cmd.Offset        = Offset;
            ExtCtrl.pTxPayload   += ChunkLen;
            ChunkLen = (unsigned short)sl_min(MAX_NVMEM_CHUNK_SIZE,Len);
            ExtCtrl.TxPayloadLen  = ChunkLen;
            Msg.Cmd.Len           = ChunkLen;
            Msg.Cmd.FileHandle  = FileHdl;
        }
        else
        {
            return RetVal;
        }
    }while(ChunkLen > 0);

    return (long)RetCount;
}
#endif

/*****************************************************************************/
/* sl_FsGetInfo */ 
/*****************************************************************************/
typedef union
{
	_FsGetInfoCommand_t	    Cmd;
	_FsGetInfoResponse_t    Rsp;
}_SlFsGetInfoMsg_u;

const _SlCmdCtrl_t _SlFsGetInfoCmdCtrl =
{
    SL_OPCODE_NVMEM_FILEGETINFOCOMMAND,
    sizeof(_FsGetInfoCommand_t),
    sizeof(_FsGetInfoResponse_t)
};

#if _SL_INCLUDE_FUNC(sl_FsGetInfo)
int sl_FsGetInfo(unsigned char *pFileName,unsigned long Token,SlFsFileInfo_t* pFsFileInfo)
{
    _SlFsGetInfoMsg_u    Msg;
    _SlCmdExt_t          CmdExt;

    CmdExt.TxPayloadLen = (sl_Strlen(pFileName)+4) & (~3); /* add 4: 1 for NULL and the 3 for align  */
    CmdExt.RxPayloadLen = 0;
    CmdExt.pTxPayload   = pFileName;
    CmdExt.pRxPayload   = NULL;
    Msg.Cmd.Token       = Token;

    VERIFY_RET_OK(_SlDrvCmdOp((_SlCmdCtrl_t *)&_SlFsGetInfoCmdCtrl, &Msg, &CmdExt));

    pFsFileInfo->flags        = Msg.Rsp.flags;
    pFsFileInfo->FileLen      = Msg.Rsp.FileLen;
    pFsFileInfo->AllocatedLen = Msg.Rsp.AllocatedLen;
    pFsFileInfo->Token[0]     = Msg.Rsp.Token[0];
    pFsFileInfo->Token[1]     = Msg.Rsp.Token[1];
    pFsFileInfo->Token[2]     = Msg.Rsp.Token[2];
    pFsFileInfo->Token[3]     = Msg.Rsp.Token[3];
    return  (int)((short)Msg.Rsp.Status);
}
#endif

/*****************************************************************************/
/* sl_FsDel */ 
/*****************************************************************************/
typedef union
{
	_FsDeleteCommand_t   	    Cmd;
	_FsDeleteResponse_t	        Rsp;
}_SlFsDeleteMsg_u;

const _SlCmdCtrl_t _SlFsDeleteCmdCtrl =
{
    SL_OPCODE_NVMEM_FILEDELCOMMAND,
    sizeof(_FsDeleteCommand_t),
    sizeof(_FsDeleteResponse_t)
};

#if _SL_INCLUDE_FUNC(sl_FsDel)
int sl_FsDel(unsigned char *pFileName,unsigned long Token)
{
    _SlFsDeleteMsg_u Msg;
    _SlCmdExt_t          CmdExt;

    CmdExt.TxPayloadLen = (sl_Strlen(pFileName)+4) & (~3); /* add 4: 1 for NULL and the 3 for align */
    CmdExt.RxPayloadLen = 0;
    CmdExt.pTxPayload   = pFileName;
    CmdExt.pRxPayload   = NULL;
    Msg.Cmd.Token       = Token;


    VERIFY_RET_OK(_SlDrvCmdOp((_SlCmdCtrl_t *)&_SlFsDeleteCmdCtrl, &Msg, &CmdExt));

    return  (int)((short)Msg.Rsp.status);
}
#endif
