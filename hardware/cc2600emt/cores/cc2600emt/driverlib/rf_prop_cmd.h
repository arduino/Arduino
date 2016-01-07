/******************************************************************************
*  Filename:       rf_prop_cmd.h
*  Revised:        2015-09-28 11:32:09 +0200 (må, 28 sep 2015)
*  Revision:       44677
*
*  Description:    CC26xx API for Proprietary mode commands
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

#ifndef __PROP_CMD_H
#define __PROP_CMD_H

#ifndef __RFC_STRUCT
#ifdef __GNUC__
#define __RFC_STRUCT __attribute__ ((aligned (4)))
#else
#define __RFC_STRUCT
#endif
#endif

//! \addtogroup rfc
//! @{

//! \addtogroup prop_cmd
//! @{

#include <stdint.h>
#include <driverlib/rf_mailbox.h>
#include <driverlib/rf_common_cmd.h>

typedef struct __RFC_STRUCT rfc_CMD_PROP_TX_s rfc_CMD_PROP_TX_t;
typedef struct __RFC_STRUCT rfc_CMD_PROP_RX_s rfc_CMD_PROP_RX_t;
typedef struct __RFC_STRUCT rfc_CMD_PROP_TX_ADV_s rfc_CMD_PROP_TX_ADV_t;
typedef struct __RFC_STRUCT rfc_CMD_PROP_RX_ADV_s rfc_CMD_PROP_RX_ADV_t;
typedef struct __RFC_STRUCT rfc_CMD_PROP_RADIO_SETUP_s rfc_CMD_PROP_RADIO_SETUP_t;
typedef struct __RFC_STRUCT rfc_CMD_PROP_SET_LEN_s rfc_CMD_PROP_SET_LEN_t;
typedef struct __RFC_STRUCT rfc_CMD_PROP_RESTART_RX_s rfc_CMD_PROP_RESTART_RX_t;
typedef struct __RFC_STRUCT rfc_propRxOutput_s rfc_propRxOutput_t;
typedef struct __RFC_STRUCT rfc_propRxStatus_s rfc_propRxStatus_t;

//! \addtogroup CMD_PROP_TX
//! @{
#define CMD_PROP_TX                                             0x3801
struct __RFC_STRUCT rfc_CMD_PROP_TX_s {
   uint16_t commandNo;                  //!<        The command ID number 0x3801
   uint16_t status;                     //!< \brief An integer telling the status of the command. This value is
                                        //!<        updated by the radio CPU during operation and may be read by the
                                        //!<        system CPU at any time.
   rfc_radioOp_t *pNextOp;              //!<        Pointer to the next operation to run after this operation is done
   ratmr_t startTime;                   //!<        Absolute or relative start time (depending on the value of <code>startTrigger</code>)
   struct {
      uint8_t triggerType:4;            //!<        The type of trigger
      uint8_t bEnaCmd:1;                //!< \brief 0: No alternative trigger command<br>
                                        //!<        1: CMD_TRIGGER can be used as an alternative trigger
      uint8_t triggerNo:2;              //!<        The trigger number of the CMD_TRIGGER command that triggers this action
      uint8_t pastTrig:1;               //!< \brief 0: A trigger in the past is never triggered, or for start of commands, give an error<br>
                                        //!<        1: A trigger in the past is triggered as soon as possible
   } startTrigger;                      //!<        Identification of the trigger that starts the operation
   struct {
      uint8_t rule:4;                   //!<        Condition for running next command: Rule for how to proceed
      uint8_t nSkip:4;                  //!<        Number of skips if the rule involves skipping
   } condition;
   struct {
      uint8_t bFsOff:1;                 //!< \brief 0: Keep frequency synth on after command<br>
                                        //!<        1: Turn frequency synth off after command
      uint8_t :2;
      uint8_t bUseCrc:1;                //!< \brief 0: Do not append CRC<br>
                                        //!<        1: Append CRC
      uint8_t bVarLen:1;                //!< \brief 0: Fixed length<br>
                                        //!<        1: Transmit length as first byte
   } pktConf;
   uint8_t pktLen;                      //!<        Packet length
   uint32_t syncWord;                   //!<        Sync word to transmit
   uint8_t* pPkt;                       //!<        Pointer to packet
};

//! @}

//! \addtogroup CMD_PROP_RX
//! @{
#define CMD_PROP_RX                                             0x3802
struct __RFC_STRUCT rfc_CMD_PROP_RX_s {
   uint16_t commandNo;                  //!<        The command ID number 0x3802
   uint16_t status;                     //!< \brief An integer telling the status of the command. This value is
                                        //!<        updated by the radio CPU during operation and may be read by the
                                        //!<        system CPU at any time.
   rfc_radioOp_t *pNextOp;              //!<        Pointer to the next operation to run after this operation is done
   ratmr_t startTime;                   //!<        Absolute or relative start time (depending on the value of <code>startTrigger</code>)
   struct {
      uint8_t triggerType:4;            //!<        The type of trigger
      uint8_t bEnaCmd:1;                //!< \brief 0: No alternative trigger command<br>
                                        //!<        1: CMD_TRIGGER can be used as an alternative trigger
      uint8_t triggerNo:2;              //!<        The trigger number of the CMD_TRIGGER command that triggers this action
      uint8_t pastTrig:1;               //!< \brief 0: A trigger in the past is never triggered, or for start of commands, give an error<br>
                                        //!<        1: A trigger in the past is triggered as soon as possible
   } startTrigger;                      //!<        Identification of the trigger that starts the operation
   struct {
      uint8_t rule:4;                   //!<        Condition for running next command: Rule for how to proceed
      uint8_t nSkip:4;                  //!<        Number of skips if the rule involves skipping
   } condition;
   struct {
      uint8_t bFsOff:1;                 //!< \brief 0: Keep frequency synth on after command<br>
                                        //!<        1: Turn frequency synth off after command
      uint8_t bRepeatOk:1;              //!< \brief 0: End operation after receiving a packet correctly<br>
                                        //!<        1: Go back to sync search after receiving a packet correctly
      uint8_t bRepeatNok:1;             //!< \brief 0: End operation after receiving a packet with CRC error<br>
                                        //!<        1: Go back to sync search after receiving a packet with CRC error
      uint8_t bUseCrc:1;                //!< \brief 0: Do not check CRC<br>
                                        //!<        1: Check CRC
      uint8_t bVarLen:1;                //!< \brief 0: Fixed length<br>
                                        //!<        1: Receive length as first byte
      uint8_t bChkAddress:1;            //!< \brief 0: No address check<br>
                                        //!<        1: Check address
      uint8_t endType:1;                //!< \brief 0: Packet is received to the end if end trigger happens after sync is obtained<br>
                                        //!<        1: Packet reception is stopped if end trigger happens
      uint8_t filterOp:1;               //!< \brief 0: Stop receiver and restart sync search on address mismatch<br>
                                        //!<        1: Receive packet and mark it as ignored on address mismatch
   } pktConf;
   struct {
      uint8_t bAutoFlushIgnored:1;      //!<        If 1, automatically discard ignored packets from Rx queue
      uint8_t bAutoFlushCrcErr:1;       //!<        If 1, automatically discard packets with CRC error from Rx queue
      uint8_t :1;
      uint8_t bIncludeHdr:1;            //!<        If 1, include the received header or length byte in the stored packet; otherwise discard it
      uint8_t bIncludeCrc:1;            //!<        If 1, include the received CRC field in the stored packet; otherwise discard it
      uint8_t bAppendRssi:1;            //!<        If 1, append an RSSI byte to the packet in the Rx queue
      uint8_t bAppendTimestamp:1;       //!<        If 1, append a timestamp to the packet in the Rx queue
      uint8_t bAppendStatus:1;          //!<        If 1, append a status byte to the packet in the Rx queue
   } rxConf;                            //!<        Rx configuration
   uint32_t syncWord;                   //!<        Sync word to listen for
   uint8_t maxPktLen;                   //!< \brief Packet length for fixed length, maximum packet length for variable length<br>
                                        //!<        0: Unlimited or unknown length
   uint8_t address0;                    //!<        Address
   uint8_t address1;                    //!< \brief Address (set equal to <code>address0</code> to accept only one address. If 0xFF, accept
                                        //!<        0x00 as well)
   struct {
      uint8_t triggerType:4;            //!<        The type of trigger
      uint8_t bEnaCmd:1;                //!< \brief 0: No alternative trigger command<br>
                                        //!<        1: CMD_TRIGGER can be used as an alternative trigger
      uint8_t triggerNo:2;              //!<        The trigger number of the CMD_TRIGGER command that triggers this action
      uint8_t pastTrig:1;               //!< \brief 0: A trigger in the past is never triggered, or for start of commands, give an error<br>
                                        //!<        1: A trigger in the past is triggered as soon as possible
   } endTrigger;                        //!<        Trigger classifier for ending the operation
   ratmr_t endTime;                     //!<        Time used together with <code>endTrigger</code> for ending the operation
   dataQueue_t* pQueue;                 //!<        Pointer to receive queue
   uint8_t* pOutput;                    //!<        Pointer to output structure
};

//! @}

//! \addtogroup CMD_PROP_TX_ADV
//! @{
#define CMD_PROP_TX_ADV                                         0x3803
struct __RFC_STRUCT rfc_CMD_PROP_TX_ADV_s {
   uint16_t commandNo;                  //!<        The command ID number 0x3803
   uint16_t status;                     //!< \brief An integer telling the status of the command. This value is
                                        //!<        updated by the radio CPU during operation and may be read by the
                                        //!<        system CPU at any time.
   rfc_radioOp_t *pNextOp;              //!<        Pointer to the next operation to run after this operation is done
   ratmr_t startTime;                   //!<        Absolute or relative start time (depending on the value of <code>startTrigger</code>)
   struct {
      uint8_t triggerType:4;            //!<        The type of trigger
      uint8_t bEnaCmd:1;                //!< \brief 0: No alternative trigger command<br>
                                        //!<        1: CMD_TRIGGER can be used as an alternative trigger
      uint8_t triggerNo:2;              //!<        The trigger number of the CMD_TRIGGER command that triggers this action
      uint8_t pastTrig:1;               //!< \brief 0: A trigger in the past is never triggered, or for start of commands, give an error<br>
                                        //!<        1: A trigger in the past is triggered as soon as possible
   } startTrigger;                      //!<        Identification of the trigger that starts the operation
   struct {
      uint8_t rule:4;                   //!<        Condition for running next command: Rule for how to proceed
      uint8_t nSkip:4;                  //!<        Number of skips if the rule involves skipping
   } condition;
   struct {
      uint8_t bFsOff:1;                 //!< \brief 0: Keep frequency synth on after command<br>
                                        //!<        1: Turn frequency synth off after command
      uint8_t :2;
      uint8_t bUseCrc:1;                //!< \brief 0: Do not append CRC<br>
                                        //!<        1: Append CRC
      uint8_t bCrcIncSw:1;              //!< \brief 0:Do not include sync word in CRC calculation<br>
                                        //!<        1: Include sync word in CRC calculation
      uint8_t bCrcIncHdr:1;             //!< \brief 0: Do not include header in CRC calculation<br>
                                        //!<        1: Include header in CRC calculation
   } pktConf;
   uint8_t numHdrBits;                  //!<        Number of bits in header (0&ndash;32)
   uint16_t pktLen;                     //!<        Packet length. 0: Unlimited
   struct {
      uint8_t bExtTxTrig:1;             //!< \brief 0: Start packet on a fixed time from the command start trigger<br>
                                        //!<        1: Start packet on an external trigger (input event to RAT)
      uint8_t inputMode:2;              //!< \brief Input mode if external trigger is used for Tx start<br>
                                        //!<        0: Rising edge<br>
                                        //!<        1: Falling edge<br>
                                        //!<        2: Both edges<br>
                                        //!<        3: <i>Reserved</i>
      uint8_t source:5;                 //!<        RAT input event number used for capture if external trigger is used for Tx start
   } startConf;
   struct {
      uint8_t triggerType:4;            //!<        The type of trigger
      uint8_t bEnaCmd:1;                //!< \brief 0: No alternative trigger command<br>
                                        //!<        1: CMD_TRIGGER can be used as an alternative trigger
      uint8_t triggerNo:2;              //!<        The trigger number of the CMD_TRIGGER command that triggers this action
      uint8_t pastTrig:1;               //!< \brief 0: A trigger in the past is never triggered, or for start of commands, give an error<br>
                                        //!<        1: A trigger in the past is triggered as soon as possible
   } preTrigger;                        //!<        Trigger for transition from preamble to sync word
   ratmr_t preTime;                     //!< \brief Time used together with <code>preTrigger</code> for transition from preamble to sync
                                        //!<        word. If <code>preTrigger.triggerType</code> is set to "now", one preamble as
                                        //!<        configured in the setup will be sent. Otherwise, the preamble will be repeated until
                                        //!<        this trigger is observed.
   uint32_t syncWord;                   //!<        Sync word to transmit
   uint8_t* pPkt;                       //!<        Pointer to packet, or Tx queue for unlimited length
};

//! @}

//! \addtogroup CMD_PROP_RX_ADV
//! @{
#define CMD_PROP_RX_ADV                                         0x3804
struct __RFC_STRUCT rfc_CMD_PROP_RX_ADV_s {
   uint16_t commandNo;                  //!<        The command ID number 0x3804
   uint16_t status;                     //!< \brief An integer telling the status of the command. This value is
                                        //!<        updated by the radio CPU during operation and may be read by the
                                        //!<        system CPU at any time.
   rfc_radioOp_t *pNextOp;              //!<        Pointer to the next operation to run after this operation is done
   ratmr_t startTime;                   //!<        Absolute or relative start time (depending on the value of <code>startTrigger</code>)
   struct {
      uint8_t triggerType:4;            //!<        The type of trigger
      uint8_t bEnaCmd:1;                //!< \brief 0: No alternative trigger command<br>
                                        //!<        1: CMD_TRIGGER can be used as an alternative trigger
      uint8_t triggerNo:2;              //!<        The trigger number of the CMD_TRIGGER command that triggers this action
      uint8_t pastTrig:1;               //!< \brief 0: A trigger in the past is never triggered, or for start of commands, give an error<br>
                                        //!<        1: A trigger in the past is triggered as soon as possible
   } startTrigger;                      //!<        Identification of the trigger that starts the operation
   struct {
      uint8_t rule:4;                   //!<        Condition for running next command: Rule for how to proceed
      uint8_t nSkip:4;                  //!<        Number of skips if the rule involves skipping
   } condition;
   struct {
      uint8_t bFsOff:1;                 //!< \brief 0: Keep frequency synth on after command<br>
                                        //!<        1: Turn frequency synth off after command
      uint8_t bRepeatOk:1;              //!< \brief 0: End operation after receiving a packet correctly<br>
                                        //!<        1: Go back to sync search after receiving a packet correctly
      uint8_t bRepeatNok:1;             //!< \brief 0: End operation after receiving a packet with CRC error<br>
                                        //!<        1: Go back to sync search after receiving a packet with CRC error
      uint8_t bUseCrc:1;                //!< \brief 0: Do not check CRC<br>
                                        //!<        1: Check CRC
      uint8_t bCrcIncSw:1;              //!< \brief 0: Do not include sync word in CRC calculation<br>
                                        //!<        1: Include sync word in CRC calculation
      uint8_t bCrcIncHdr:1;             //!< \brief 0: Do not include header in CRC calculation <br>
                                        //!<        1: Include header in CRC calculation
      uint8_t endType:1;                //!< \brief 0: Packet is received to the end if end trigger happens after sync is obtained<br>
                                        //!<        1: Packet reception is stopped if end trigger happens
      uint8_t filterOp:1;               //!< \brief 0: Stop receiver and restart sync search on address mismatch<br>
                                        //!<        1: Receive packet and mark it as ignored on address mismatch
   } pktConf;
   struct {
      uint8_t bAutoFlushIgnored:1;      //!<        If 1, automatically discard ignored packets from Rx queue
      uint8_t bAutoFlushCrcErr:1;       //!<        If 1, automatically discard packets with CRC error from Rx queue
      uint8_t :1;
      uint8_t bIncludeHdr:1;            //!<        If 1, include the received header or length byte in the stored packet; otherwise discard it
      uint8_t bIncludeCrc:1;            //!<        If 1, include the received CRC field in the stored packet; otherwise discard it
      uint8_t bAppendRssi:1;            //!<        If 1, append an RSSI byte to the packet in the Rx queue
      uint8_t bAppendTimestamp:1;       //!<        If 1, append a timestamp to the packet in the Rx queue
      uint8_t bAppendStatus:1;          //!<        If 1, append a status byte to the packet in the Rx queue
   } rxConf;                            //!<        Rx configuration
   uint32_t syncWord0;                  //!<        Sync word to listen for
   uint32_t syncWord1;                  //!<        Alternative sync word if non-zero
   uint16_t maxPktLen;                  //!< \brief Packet length for fixed length, maximum packet length for variable length<br>
                                        //!<        0: Unlimited or unknown length
   struct {
      uint16_t numHdrBits:6;            //!<        Number of bits in header (0&ndash;32)
      uint16_t lenPos:5;                //!<        Position of length field in header (0&ndash;31)
      uint16_t numLenBits:5;            //!<        Number of bits in length field (0&ndash;16)
   } hdrConf;
   struct {
      uint16_t addrType:1;              //!< \brief 0: Address after header<br>
                                        //!<        1: Address in header
      uint16_t addrSize:5;              //!< \brief If <code>addrType</code> = 0: Address size in bytes<br>
                                        //!<        If <code>addrType</code> = 1: Address size in bits
      uint16_t addrPos:5;               //!< \brief If <code>addrType</code> = 1: Bit position of address in header<br>
                                        //!<        If <code>addrType</code> = 0: Non-zero to extend address with sync word identifier
      uint16_t numAddr:5;               //!<        Number of addresses in address list
   } addrConf;
   int8_t lenOffset;                    //!<        Signed value to add to length field
   struct {
      uint8_t triggerType:4;            //!<        The type of trigger
      uint8_t bEnaCmd:1;                //!< \brief 0: No alternative trigger command<br>
                                        //!<        1: CMD_TRIGGER can be used as an alternative trigger
      uint8_t triggerNo:2;              //!<        The trigger number of the CMD_TRIGGER command that triggers this action
      uint8_t pastTrig:1;               //!< \brief 0: A trigger in the past is never triggered, or for start of commands, give an error<br>
                                        //!<        1: A trigger in the past is triggered as soon as possible
   } endTrigger;                        //!<        Trigger classifier for ending the operation
   ratmr_t endTime;                     //!<        Time used together with <code>endTrigger</code> for ending the operation
   uint8_t* pAddr;                      //!<        Pointer to address list
   dataQueue_t* pQueue;                 //!<        Pointer to receive queue
   uint8_t* pOutput;                    //!<        Pointer to output structure
};

//! @}

//! \addtogroup CMD_PROP_RADIO_SETUP
//! @{
#define CMD_PROP_RADIO_SETUP                                    0x3806
struct __RFC_STRUCT rfc_CMD_PROP_RADIO_SETUP_s {
   uint16_t commandNo;                  //!<        The command ID number 0x3806
   uint16_t status;                     //!< \brief An integer telling the status of the command. This value is
                                        //!<        updated by the radio CPU during operation and may be read by the
                                        //!<        system CPU at any time.
   rfc_radioOp_t *pNextOp;              //!<        Pointer to the next operation to run after this operation is done
   ratmr_t startTime;                   //!<        Absolute or relative start time (depending on the value of <code>startTrigger</code>)
   struct {
      uint8_t triggerType:4;            //!<        The type of trigger
      uint8_t bEnaCmd:1;                //!< \brief 0: No alternative trigger command<br>
                                        //!<        1: CMD_TRIGGER can be used as an alternative trigger
      uint8_t triggerNo:2;              //!<        The trigger number of the CMD_TRIGGER command that triggers this action
      uint8_t pastTrig:1;               //!< \brief 0: A trigger in the past is never triggered, or for start of commands, give an error<br>
                                        //!<        1: A trigger in the past is triggered as soon as possible
   } startTrigger;                      //!<        Identification of the trigger that starts the operation
   struct {
      uint8_t rule:4;                   //!<        Condition for running next command: Rule for how to proceed
      uint8_t nSkip:4;                  //!<        Number of skips if the rule involves skipping
   } condition;
   struct {
      uint16_t modType:3;               //!< \brief 0: FSK<br>
                                        //!<        1: GFSK<br>
                                        //!<        Others: <i>Reserved</i>
      uint16_t deviation:13;            //!<        Deviation (250 Hz steps)
   } modulation;
   struct {
      uint32_t preScale:4;              //!<        Prescaler value
      uint32_t :4;
      uint32_t rateWord:21;             //!<        Rate word
   } symbolRate;
   uint8_t rxBw;                        //!<        Receiver bandwidth
   struct {
      uint8_t nPreamBytes:6;            //!< \brief 0&ndash;30: Number of preamble bytes<br>
                                        //!<        31: 4 preamble bits
      uint8_t preamMode:2;              //!< \brief 0: Send 0 as the first preamble bit<br>
                                        //!<        1: Send 1 as the first preamble bit<br>
                                        //!<        2: Send same first bit in preamble and sync word<br>
                                        //!<        3: Send different first bit in preamble and sync word
   } preamConf;
   struct {
      uint16_t nSwBits:6;               //!<        Number of sync word bits (up to 32)
      uint16_t bBitReversal:1;          //!< \brief 0: Use positive deviation for 1<br>
                                        //!<        1: Use positive deviation for 0
      uint16_t bMsbFirst:1;             //!< \brief 0: Least significant bit transmitted first<br>
                                        //!<        1: Most significant bit transmitted first
      uint16_t fecMode:4;               //!< \brief Select coding<br>
                                        //!<        0: Uncoded binary modulation<br>
                                        //!<        Others: <i>Reserved</i>
      uint16_t bOuterCode:1;            //!<        <i>Reserved</i>
      uint16_t whitenMode:2;            //!< \brief 0: No whitening<br>
                                        //!<        1: CC1101/CC2500 compatible whitening<br>
                                        //!<        2: PN9 whitening without byte reversal<br>
                                        //!<        3: <i>Reserved</i>
      uint16_t bAgcDisable:1;           //!<        <i>Reserved</i>
   } formatConf;
   struct {
      uint16_t frontEndMode:3;          //!< \brief 0x00: Differential mode<br>
                                        //!<        0x01: Single-ended mode RFP<br>
                                        //!<        0x02: Single-ended mode RFN<br>
                                        //!<        0x05 Single-ended mode RFP with external frontend control on RF pins (RFN and RXTX)<br>
                                        //!<        0x06 Single-ended mode RFN with external frontend control on RF pins (RFP and RXTX)<br>
                                        //!<        Others: <i>Reserved</i>
      uint16_t biasMode:1;              //!< \brief 0: Internal bias<br>
                                        //!<        1: External bias
      uint16_t :6;
      uint16_t bNoFsPowerUp:1;          //!< \brief 0: Power up frequency synth<br>
                                        //!<        1: Do not power up frequency synth
   } config;                            //!<        Configuration options
   uint16_t txPower;                    //!<        Transmit power
   uint32_t* pRegOverride;              //!<        Pointer to a list of hardware and configuration registers to override. If NULL, no override is used.
};

//! @}

//! \addtogroup CMD_PROP_SET_LEN
//! @{
#define CMD_PROP_SET_LEN                                        0x3401
struct __RFC_STRUCT rfc_CMD_PROP_SET_LEN_s {
   uint16_t commandNo;                  //!<        The command ID number 0x3401
   uint16_t rxLen;                      //!<        Payload length to use
};

//! @}

//! \addtogroup CMD_PROP_RESTART_RX
//! @{
#define CMD_PROP_RESTART_RX                                     0x3402
struct __RFC_STRUCT rfc_CMD_PROP_RESTART_RX_s {
   uint16_t commandNo;                  //!<        The command ID number 0x3402
};

//! @}

//! \addtogroup propRxOutput
//! @{
//! Output structure for Rx operations

struct __RFC_STRUCT rfc_propRxOutput_s {
   uint16_t nRxOk;                      //!<        Number of packets that have been received with payload, CRC OK and not ignored
   uint16_t nRxNok;                     //!<        Number of packets that have been received with CRC error
   uint8_t nRxIgnored;                  //!<        Number of packets that have been received with CRC OK and ignored due to address mismatch
   uint8_t nRxStopped;                  //!<        Number of packets not received due to illegal length or address mismatch with pktConf.filterOp = 1
   uint8_t nRxBufFull;                  //!<        Number of packets that have been received and discarded due to lack of buffer space
   int8_t lastRssi;                     //!<        RSSI of last received packet
   ratmr_t timeStamp;                   //!<        Time stamp of last received packet
};

//! @}

//! \addtogroup propRxStatus
//! @{
//! Receive status byte that may be appended to message in receive buffer

struct __RFC_STRUCT rfc_propRxStatus_s {
   struct {
      uint8_t addressInd:5;             //!<        Index of address found (0 if not applicable)
      uint8_t syncWordId:1;             //!<        0 for primary sync word, 1 for alternate sync word
      uint8_t result:2;                 //!< \brief 0: Packet received correctly, not ignored<br>
                                        //!<        1: Packet received with CRC error<br>
                                        //!<        2: Packet received correctly, but can be ignored<br>
                                        //!<        3: Packet reception was aborted
   } status;
};

//! @}

//! @}
//! @}
#endif
