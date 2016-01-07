/******************************************************************************
*  Filename:       rf_ble_cmd.h
*  Revised:        2015-09-28 11:32:09 +0200 (må, 28 sep 2015)
*  Revision:       44677
*
*  Description:    CC26xx API for BLE mode commands
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

#ifndef __BLE_CMD_H
#define __BLE_CMD_H

#ifndef __RFC_STRUCT
#ifdef __GNUC__
#define __RFC_STRUCT __attribute__ ((aligned (4)))
#else
#define __RFC_STRUCT
#endif
#endif

//! \addtogroup rfc
//! @{

//! \addtogroup ble_cmd
//! @{

#include <stdint.h>
#include <driverlib/rf_mailbox.h>

typedef struct __RFC_STRUCT rfCoreHal_bleRadioOp_s rfCoreHal_bleRadioOp_t;
typedef struct __RFC_STRUCT rfCoreHal_CMD_BLE_SLAVE_s rfCoreHal_CMD_BLE_SLAVE_t;
typedef struct __RFC_STRUCT rfCoreHal_CMD_BLE_MASTER_s rfCoreHal_CMD_BLE_MASTER_t;
typedef struct __RFC_STRUCT rfCoreHal_CMD_BLE_ADV_s rfCoreHal_CMD_BLE_ADV_t;
typedef struct __RFC_STRUCT rfCoreHal_CMD_BLE_ADV_DIR_s rfCoreHal_CMD_BLE_ADV_DIR_t;
typedef struct __RFC_STRUCT rfCoreHal_CMD_BLE_ADV_NC_s rfCoreHal_CMD_BLE_ADV_NC_t;
typedef struct __RFC_STRUCT rfCoreHal_CMD_BLE_ADV_SCAN_s rfCoreHal_CMD_BLE_ADV_SCAN_t;
typedef struct __RFC_STRUCT rfCoreHal_CMD_BLE_SCANNER_s rfCoreHal_CMD_BLE_SCANNER_t;
typedef struct __RFC_STRUCT rfCoreHal_CMD_BLE_INITIATOR_s rfCoreHal_CMD_BLE_INITIATOR_t;
typedef struct __RFC_STRUCT rfCoreHal_CMD_BLE_GENERIC_RX_s rfCoreHal_CMD_BLE_GENERIC_RX_t;
typedef struct __RFC_STRUCT rfCoreHal_CMD_BLE_TX_TEST_s rfCoreHal_CMD_BLE_TX_TEST_t;
typedef struct __RFC_STRUCT rfCoreHal_CMD_BLE_ADV_PAYLOAD_s rfCoreHal_CMD_BLE_ADV_PAYLOAD_t;
typedef struct __RFC_STRUCT rfCoreHal_bleMasterSlavePar_s rfCoreHal_bleMasterSlavePar_t;
typedef struct __RFC_STRUCT rfCoreHal_bleMasterPar_s rfCoreHal_bleMasterPar_t;
typedef struct __RFC_STRUCT rfCoreHal_bleSlavePar_s rfCoreHal_bleSlavePar_t;
typedef struct __RFC_STRUCT rfCoreHal_bleAdvPar_s rfCoreHal_bleAdvPar_t;
typedef struct __RFC_STRUCT rfCoreHal_bleScannerPar_s rfCoreHal_bleScannerPar_t;
typedef struct __RFC_STRUCT rfCoreHal_bleInitiatorPar_s rfCoreHal_bleInitiatorPar_t;
typedef struct __RFC_STRUCT rfCoreHal_bleGenericRxPar_s rfCoreHal_bleGenericRxPar_t;
typedef struct __RFC_STRUCT rfCoreHal_bleTxTestPar_s rfCoreHal_bleTxTestPar_t;
typedef struct __RFC_STRUCT rfCoreHal_bleMasterSlaveOutput_s rfCoreHal_bleMasterSlaveOutput_t;
typedef struct __RFC_STRUCT rfCoreHal_bleAdvOutput_s rfCoreHal_bleAdvOutput_t;
typedef struct __RFC_STRUCT rfCoreHal_bleScannerOutput_s rfCoreHal_bleScannerOutput_t;
typedef struct __RFC_STRUCT rfCoreHal_bleInitiatorOutput_s rfCoreHal_bleInitiatorOutput_t;
typedef struct __RFC_STRUCT rfCoreHal_bleGenericRxOutput_s rfCoreHal_bleGenericRxOutput_t;
typedef struct __RFC_STRUCT rfCoreHal_bleTxTestOutput_s rfCoreHal_bleTxTestOutput_t;
typedef struct __RFC_STRUCT rfCoreHal_bleWhiteListEntry_s rfCoreHal_bleWhiteListEntry_t;
typedef struct __RFC_STRUCT rfCoreHal_bleWhiteListEntryWords_s rfCoreHal_bleWhiteListEntryWords_t;
typedef struct __RFC_STRUCT rfCoreHal_bleRxStatus_s rfCoreHal_bleRxStatus_t;


//! \addtogroup CMD_BLE_SLAVE
//! @{
struct rfCoreHal_bleRadioOp_s {
   uint16_t commandNo;
   uint16_t status;
   uint8_t* pNextOp;
   ratmr_t startTime;
   struct {
      uint8_t triggerType:4;
      uint8_t bEnaCmd:1;
      uint8_t triggerNo:2;
      uint8_t pastTrig:1;
   } startTrigger;
   struct {
      uint8_t rule:4;
      uint8_t nSkip:4;
   } condition;
   uint8_t channel;
   struct {
      uint8_t init:7;
      uint8_t bOverride:1;
   } whitening;
   uint8_t* pParams;
   uint8_t* pOutput;
};

//! @}

//! \addtogroup CMD_BLE_SLAVE
//! @{
#define CMD_BLE_SLAVE                                           0x1801
struct rfCoreHal_CMD_BLE_SLAVE_s {
   uint16_t commandNo;
   uint16_t status;
   uint8_t* pNextOp;
   ratmr_t startTime;
   struct {
      uint8_t triggerType:4;
      uint8_t bEnaCmd:1;
      uint8_t triggerNo:2;
      uint8_t pastTrig:1;
   } startTrigger;
   struct {
      uint8_t rule:4;
      uint8_t nSkip:4;
   } condition;
   uint8_t channel;
   struct {
      uint8_t init:7;
      uint8_t bOverride:1;
   } whitening;
   uint8_t* pParams;
   uint8_t* pOutput;
};

//! @}

//! \addtogroup CMD_BLE_MASTER
//! @{
#define CMD_BLE_MASTER                                          0x1802
struct rfCoreHal_CMD_BLE_MASTER_s {
   uint16_t commandNo;
   uint16_t status;
   uint8_t* pNextOp;
   ratmr_t startTime;
   struct {
      uint8_t triggerType:4;
      uint8_t bEnaCmd:1;
      uint8_t triggerNo:2;
      uint8_t pastTrig:1;
   } startTrigger;
   struct {
      uint8_t rule:4;
      uint8_t nSkip:4;
   } condition;
   uint8_t channel;
   struct {
      uint8_t init:7;
      uint8_t bOverride:1;
   } whitening;
   uint8_t* pParams;
   uint8_t* pOutput;
};

//! @}

//! \addtogroup CMD_BLE_ADV
//! @{
#define CMD_BLE_ADV                                             0x1803
struct rfCoreHal_CMD_BLE_ADV_s {
   uint16_t commandNo;
   uint16_t status;
   uint8_t* pNextOp;
   ratmr_t startTime;
   struct {
      uint8_t triggerType:4;
      uint8_t bEnaCmd:1;
      uint8_t triggerNo:2;
      uint8_t pastTrig:1;
   } startTrigger;
   struct {
      uint8_t rule:4;
      uint8_t nSkip:4;
   } condition;
   uint8_t channel;
   struct {
      uint8_t init:7;
      uint8_t bOverride:1;
   } whitening;
   uint8_t* pParams;
   uint8_t* pOutput;
};

//! @}

//! \addtogroup CMD_BLE_ADV_DIR
//! @{
#define CMD_BLE_ADV_DIR                                         0x1804
struct rfCoreHal_CMD_BLE_ADV_DIR_s {
   uint16_t commandNo;
   uint16_t status;
   uint8_t* pNextOp;
   ratmr_t startTime;
   struct {
      uint8_t triggerType:4;
      uint8_t bEnaCmd:1;
      uint8_t triggerNo:2;
      uint8_t pastTrig:1;
   } startTrigger;
   struct {
      uint8_t rule:4;
      uint8_t nSkip:4;
   } condition;
   uint8_t channel;
   struct {
      uint8_t init:7;
      uint8_t bOverride:1;
   } whitening;
   uint8_t* pParams;
   uint8_t* pOutput;
};

//! @}

//! \addtogroup CMD_BLE_ADV_NC
//! @{
#define CMD_BLE_ADV_NC                                          0x1805
struct rfCoreHal_CMD_BLE_ADV_NC_s {
   uint16_t commandNo;
   uint16_t status;
   uint8_t* pNextOp;
   ratmr_t startTime;
   struct {
      uint8_t triggerType:4;
      uint8_t bEnaCmd:1;
      uint8_t triggerNo:2;
      uint8_t pastTrig:1;
   } startTrigger;
   struct {
      uint8_t rule:4;
      uint8_t nSkip:4;
   } condition;
   uint8_t channel;
   struct {
      uint8_t init:7;
      uint8_t bOverride:1;
   } whitening;
   uint8_t* pParams;
   uint8_t* pOutput;
} ;

//! @}

//! \addtogroup CMD_BLE_ADV_SCAN
//! @{
#define CMD_BLE_ADV_SCAN                                        0x1806
struct rfCoreHal_CMD_BLE_ADV_SCAN_s {
   uint16_t commandNo;
   uint16_t status;
   uint8_t* pNextOp;
   ratmr_t startTime;
   struct {
      uint8_t triggerType:4;
      uint8_t bEnaCmd:1;
      uint8_t triggerNo:2;
      uint8_t pastTrig:1;
   } startTrigger;
   struct {
      uint8_t rule:4;
      uint8_t nSkip:4;
   } condition;
   uint8_t channel;
   struct {
      uint8_t init:7;
      uint8_t bOverride:1;
   } whitening;
   uint8_t* pParams;
   uint8_t* pOutput;
};

//! @}

//! \addtogroup CMD_BLE_SCANNER
//! @{
#define CMD_BLE_SCANNER                                         0x1807
struct rfCoreHal_CMD_BLE_SCANNER_s {
   uint16_t commandNo;
   uint16_t status;
   uint8_t* pNextOp;
   ratmr_t startTime;
   struct {
      uint8_t triggerType:4;
      uint8_t bEnaCmd:1;
      uint8_t triggerNo:2;
      uint8_t pastTrig:1;
   } startTrigger;
   struct {
      uint8_t rule:4;
      uint8_t nSkip:4;
   } condition;
   uint8_t channel;
   struct {
      uint8_t init:7;
      uint8_t bOverride:1;
   } whitening;
   uint8_t* pParams;
   uint8_t* pOutput;
};

//! @}

//! \addtogroup CMD_BLE_INITIATOR
//! @{
#define CMD_BLE_INITIATOR                                       0x1808
struct rfCoreHal_CMD_BLE_INITIATOR_s {
   uint16_t commandNo;
   uint16_t status;
   uint8_t* pNextOp;
   ratmr_t startTime;
   struct {
      uint8_t triggerType:4;
      uint8_t bEnaCmd:1;
      uint8_t triggerNo:2;
      uint8_t pastTrig:1;
   } startTrigger;
   struct {
      uint8_t rule:4;
      uint8_t nSkip:4;
   } condition;
   uint8_t channel;
   struct {
      uint8_t init:7;
      uint8_t bOverride:1;
   } whitening;
   uint8_t* pParams;
   uint8_t* pOutput;
};

//! @}

//! \addtogroup CMD_BLE_GENERIC_RX
//! @{
#define CMD_BLE_GENERIC_RX                                      0x1809
struct rfCoreHal_CMD_BLE_GENERIC_RX_s {
   uint16_t commandNo;
   uint16_t status;
   uint8_t* pNextOp;
   ratmr_t startTime;
   struct {
      uint8_t triggerType:4;
      uint8_t bEnaCmd:1;
      uint8_t triggerNo:2;
      uint8_t pastTrig:1;
   } startTrigger;
   struct {
      uint8_t rule:4;
      uint8_t nSkip:4;
   } condition;
   uint8_t channel;
   struct {
      uint8_t init:7;
      uint8_t bOverride:1;
   } whitening;
   uint8_t* pParams;
   uint8_t* pOutput;
};

//! @}

//! \addtogroup CMD_BLE_TX_TEST
//! @{
#define CMD_BLE_TX_TEST                                         0x180A
struct rfCoreHal_CMD_BLE_TX_TEST_s {
   uint16_t commandNo;
   uint16_t status;
   uint8_t* pNextOp;
   ratmr_t startTime;
   struct {
      uint8_t triggerType:4;
      uint8_t bEnaCmd:1;
      uint8_t triggerNo:2;
      uint8_t pastTrig:1;
   } startTrigger;
   struct {
      uint8_t rule:4;
      uint8_t nSkip:4;
   } condition;
   uint8_t channel;
   struct {
      uint8_t init:7;
      uint8_t bOverride:1;
   } whitening;
   uint8_t* pParams;
   uint8_t* pOutput;
};

//! @}

//! \addtogroup CMD_BLE_ADV_PAYLOAD
//! @{
#define CMD_BLE_ADV_PAYLOAD                                     0x1001
struct rfCoreHal_CMD_BLE_ADV_PAYLOAD_s {
   uint16_t commandNo;
   uint8_t payloadType;
   uint8_t newLen;
   uint8_t* pNewData;
   uint8_t* pParams;
};

//! @}

//! \addtogroup bleMasterSlavePar
//! @{
struct rfCoreHal_bleMasterSlavePar_s {
   dataQueue_t* pRxQ;
   dataQueue_t* pTxQ;
   struct {
      uint8_t bAutoFlushIgnored:1;
      uint8_t bAutoFlushCrcErr:1;
      uint8_t bAutoFlushEmpty:1;
      uint8_t bIncludeLenByte:1;
      uint8_t bIncludeCrc:1;
      uint8_t bAppendRssi:1;
      uint8_t bAppendStatus:1;
      uint8_t bAppendTimestamp:1;
   } rxConfig;
   struct {
      uint8_t lastRxSn:1;
      uint8_t lastTxSn:1;
      uint8_t nextTxSn:1;
      uint8_t bFirstPkt:1;
      uint8_t bAutoEmpty:1;
      uint8_t bLlCtrlTx:1;
      uint8_t bLlCtrlAckRx:1;
      uint8_t bLlCtrlAckPending:1;
   } seqStat;
   uint8_t maxNack;
   uint8_t maxPkt;
   uint32_t accessAddress;
   uint32_t crcInit;
};

//! @}

//! \addtogroup bleMasterPar
//! @{
struct rfCoreHal_bleMasterPar_s {
   dataQueue_t* pRxQ;
   dataQueue_t* pTxQ;
   struct {
      uint8_t bAutoFlushIgnored:1;
      uint8_t bAutoFlushCrcErr:1;
      uint8_t bAutoFlushEmpty:1;
      uint8_t bIncludeLenByte:1;
      uint8_t bIncludeCrc:1;
      uint8_t bAppendRssi:1;
      uint8_t bAppendStatus:1;
      uint8_t bAppendTimestamp:1;
   } rxConfig;
   struct {
      uint8_t lastRxSn:1;
      uint8_t lastTxSn:1;
      uint8_t nextTxSn:1;
      uint8_t bFirstPkt:1;
      uint8_t bAutoEmpty:1;
      uint8_t bLlCtrlTx:1;
      uint8_t bLlCtrlAckRx:1;
      uint8_t bLlCtrlAckPending:1;
   } seqStat;
   uint8_t maxNack;
   uint8_t maxPkt;
   uint32_t accessAddress;
   uint32_t crcInit;
   ratmr_t endTime;
};

//! @}

//! \addtogroup bleSlavePar
//! @{
struct rfCoreHal_bleSlavePar_s {
   dataQueue_t* pRxQ;
   dataQueue_t* pTxQ;
   struct {
      uint8_t bAutoFlushIgnored:1;
      uint8_t bAutoFlushCrcErr:1;
      uint8_t bAutoFlushEmpty:1;
      uint8_t bIncludeLenByte:1;
      uint8_t bIncludeCrc:1;
      uint8_t bAppendRssi:1;
      uint8_t bAppendStatus:1;
      uint8_t bAppendTimestamp:1;
   } rxConfig;
   struct {
      uint8_t lastRxSn:1;
      uint8_t lastTxSn:1;
      uint8_t nextTxSn:1;
      uint8_t bFirstPkt:1;
      uint8_t bAutoEmpty:1;
      uint8_t bLlCtrlTx:1;
      uint8_t bLlCtrlAckRx:1;
      uint8_t bLlCtrlAckPending:1;
   } seqStat;
   uint8_t maxNack;
   uint8_t maxPkt;
   uint32_t accessAddress;
   uint32_t crcInit;
   ratmr_t timeoutTime;
   uint16_t __dummy0;
   uint8_t __dummy1;
   struct {
      uint8_t triggerType:4;
      uint8_t bEnaCmd:1;
      uint8_t triggerNo:2;
      uint8_t pastTrig:1;
   } endTrigger;
   ratmr_t endTime;
};

//! @}

//! \addtogroup bleAdvPar
//! @{
struct rfCoreHal_bleAdvPar_s {
   dataQueue_t* pRxQ;
   struct {
      uint8_t bAutoFlushIgnored:1;
      uint8_t bAutoFlushCrcErr:1;
      uint8_t bAutoFlushEmpty:1;
      uint8_t bIncludeLenByte:1;
      uint8_t bIncludeCrc:1;
      uint8_t bAppendRssi:1;
      uint8_t bAppendStatus:1;
      uint8_t bAppendTimestamp:1;
   } rxConfig;
   struct {
      uint8_t advFilterPolicy:2;
      uint8_t deviceAddrType:1;
      uint8_t peerAddrType:1;
      uint8_t bStrictLenFilter:1;
   } advConfig;
   uint8_t advLen;
   uint8_t scanRspLen;
   uint8_t* pAdvData;
   uint8_t* pScanRspData;
   uint16_t* pDeviceAddress;
   uint32_t* pWhiteList;
   uint16_t __dummy0;
   uint8_t __dummy1;
   struct {
      uint8_t triggerType:4;
      uint8_t bEnaCmd:1;
      uint8_t triggerNo:2;
      uint8_t pastTrig:1;
   } endTrigger;
   ratmr_t endTime;
};

//! @}

//! \addtogroup bleScannerPar
//! @{
struct rfCoreHal_bleScannerPar_s {
   dataQueue_t* pRxQ;
   struct {
      uint8_t bAutoFlushIgnored:1;
      uint8_t bAutoFlushCrcErr:1;
      uint8_t bAutoFlushEmpty:1;
      uint8_t bIncludeLenByte:1;
      uint8_t bIncludeCrc:1;
      uint8_t bAppendRssi:1;
      uint8_t bAppendStatus:1;
      uint8_t bAppendTimestamp:1;
   } rxConfig;
   struct {
      uint8_t scanFilterPolicy:1;
      uint8_t bActiveScan:1;
      uint8_t deviceAddrType:1;
      uint8_t :1;
      uint8_t bStrictLenFilter:1;
      uint8_t bAutoWlIgnore:1;
      uint8_t bEndOnRpt:1;
   } scanConfig;
   uint16_t randomState;
   uint16_t backoffCount;
   struct {
      uint8_t logUpperLimit:4;
      uint8_t bLastSucceeded:1;
      uint8_t bLastFailed:1;
   } backoffPar;
   uint8_t scanReqLen;
   uint8_t* pScanReqData;
   uint16_t* pDeviceAddress;
   uint32_t* pWhiteList;
   uint16_t __dummy0;
   struct {
      uint8_t triggerType:4;
      uint8_t bEnaCmd:1;
      uint8_t triggerNo:2;
      uint8_t pastTrig:1;
   } timeoutTrigger;
   struct {
      uint8_t triggerType:4;
      uint8_t bEnaCmd:1;
      uint8_t triggerNo:2;
      uint8_t pastTrig:1;
   } endTrigger;
   ratmr_t timeoutTime;
   ratmr_t endTime;
};

//! @}

//! \addtogroup bleInitiatorPar
//! @{
struct rfCoreHal_bleInitiatorPar_s {
   dataQueue_t* pRxQ;
   struct {
      uint8_t bAutoFlushIgnored:1;
      uint8_t bAutoFlushCrcErr:1;
      uint8_t bAutoFlushEmpty:1;
      uint8_t bIncludeLenByte:1;
      uint8_t bIncludeCrc:1;
      uint8_t bAppendRssi:1;
      uint8_t bAppendStatus:1;
      uint8_t bAppendTimestamp:1;
   } rxConfig;
   struct {
      uint8_t bUseWhiteList:1;
      uint8_t bDynamicWinOffset:1;
      uint8_t deviceAddrType:1;
      uint8_t peerAddrType:1;
      uint8_t bStrictLenFilter:1;
   } initConfig;
   uint8_t __dummy0;
   uint8_t connectReqLen;
   uint8_t* pConnectReqData;
   uint16_t* pDeviceAddress;
   uint32_t* pWhiteList;
   ratmr_t connectTime;
   uint16_t __dummy1;
   struct {
      uint8_t triggerType:4;
      uint8_t bEnaCmd:1;
      uint8_t triggerNo:2;
      uint8_t pastTrig:1;
   } timeoutTrigger;
   struct {
      uint8_t triggerType:4;
      uint8_t bEnaCmd:1;
      uint8_t triggerNo:2;
      uint8_t pastTrig:1;
   } endTrigger;
   ratmr_t timeoutTime;
   ratmr_t endTime;
};

//! @}

//! \addtogroup bleGenericRxPar
//! @{
struct rfCoreHal_bleGenericRxPar_t{
   dataQueue_t* pRxQ;
   struct {
      uint8_t bAutoFlushIgnored:1;
      uint8_t bAutoFlushCrcErr:1;
      uint8_t bAutoFlushEmpty:1;
      uint8_t bIncludeLenByte:1;
      uint8_t bIncludeCrc:1;
      uint8_t bAppendRssi:1;
      uint8_t bAppendStatus:1;
      uint8_t bAppendTimestamp:1;
   } rxConfig;
   uint8_t bRepeat;
   uint16_t __dummy0;
   uint32_t accessAddress;
   uint32_t crcInit;
   ratmr_t endTime;
};

//! @}

//! \addtogroup bleTxTestPar
//! @{
struct rfCoreHal_bleTxTestPar_s {
   uint16_t numPackets;
   uint8_t payloadLength;
   uint8_t packetType;
   ratmr_t period;
   struct {
      uint8_t bOverrideDefault:1;
      uint8_t bUsePrbs9:1;
      uint8_t bUsePrbs15:1;
   } config;
   uint8_t byteVal;
   uint8_t __dummy0;
   struct {
      uint8_t triggerType:4;
      uint8_t bEnaCmd:1;
      uint8_t triggerNo:2;
      uint8_t pastTrig:1;
   } endTrigger;
   ratmr_t endTime;
};

//! @}

//! \addtogroup bleMasterSlaveOutput
//! @{
struct rfCoreHal_bleMasterSlaveOutput_s {
   uint8_t nTx;
   uint8_t nTxAck;
   uint8_t nTxCtrl;
   uint8_t nTxCtrlAck;
   uint8_t nTxCtrlAckAck;
   uint8_t nTxRetrans;
   uint8_t nTxEntryDone;
   uint8_t nRxOk;
   uint8_t nRxCtrl;
   uint8_t nRxCtrlAck;
   uint8_t nRxNok;
   uint8_t nRxIgnored;
   uint8_t nRxEmpty;
   uint8_t nRxBufFull;
   int8_t lastRssi;
   struct {
      uint8_t bTimeStampValid:1;
      uint8_t bLastCrcErr:1;
      uint8_t bLastIgnored:1;
      uint8_t bLastEmpty:1;
      uint8_t bLastCtrl:1;
      uint8_t bLastMd:1;
      uint8_t bLastAck:1;
   } pktStatus;
   ratmr_t timeStamp;
};

//! @}

//! \addtogroup bleAdvOutput
//! @{
struct rfCoreHal_bleAdvOutput_s {
   uint16_t nTxAdvInd;
   uint8_t nTxScanRsp;
   uint8_t nRxScanReq;
   uint8_t nRxConnectReq;
   uint8_t __dummy0;
   uint16_t nRxNok;
   uint16_t nRxIgnored;
   uint8_t nRxBufFull;
   int8_t lastRssi;
   ratmr_t timeStamp;
};

//! @}

//! \addtogroup bleScannerOutput
//! @{
struct rfCoreHal_bleScannerOutput_s {
   uint16_t nTxScanReq;
   uint16_t nBackedOffScanReq;
   uint16_t nRxAdvOk;
   uint16_t nRxAdvIgnored;
   uint16_t nRxAdvNok;
   uint16_t nRxScanRspOk;
   uint16_t nRxScanRspIgnored;
   uint16_t nRxScanRspNok;
   uint8_t nRxAdvBufFull;
   uint8_t nRxScanRspBufFull;
   int8_t lastRssi;
   uint8_t __dummy0;
   ratmr_t timeStamp;
};

//! @}

//! \addtogroup bleInitiatorOutput
//! @{
struct rfCoreHal_bleInitiatorOutput_s {
   uint8_t nTxConnectReq;
   uint8_t nRxAdvOk;
   uint16_t nRxAdvIgnored;
   uint16_t nRxAdvNok;
   uint8_t nRxAdvBufFull;
   int8_t lastRssi;
   ratmr_t timeStamp;
};

//! @}

//! \addtogroup bleGenericRxOutput
//! @{
struct rfCoreHal_bleGenericRxOutput_s {
   uint16_t nRxOk;
   uint16_t nRxNok;
   uint16_t nRxBufFull;
   int8_t lastRssi;
   uint8_t __dummy0;
   ratmr_t timeStamp;
};

//! @}

//! \addtogroup bleTxTestOutput
//! @{
struct rfCoreHal_bleTxTestOutput_s {
   uint16_t nTx;
};

//! @}

//! \addtogroup bleWhiteListEntry
//! @{
struct rfCoreHal_bleWhiteListEntry_s {
   uint8_t size;
   struct {
      uint8_t bEnable:1;
      uint8_t addrType:1;
      uint8_t bWlIgn:1;
   } conf;
   uint16_t address;
   uint32_t addressHi;
};

//! @}

//! \addtogroup bleWhiteListEntryWords
//! @{
struct rfCoreHal_bleWhiteListEntryWords_s {
   struct {
      uint32_t size:8;
      uint32_t conf:8;
      uint32_t addressLo:16;
   } entryLo;
   uint32_t addressHi;
};

//! @}

//! \addtogroup bleRxStatus
//! @{
struct rfCoreHal_bleRxStatus_s {
   struct {
      uint8_t channel:6;
      uint8_t bIgnore:1;
      uint8_t bCrcErr:1;
   } status;
};

//! @}

//! @}
//! @}
#endif
