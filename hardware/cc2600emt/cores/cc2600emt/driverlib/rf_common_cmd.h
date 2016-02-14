/******************************************************************************
*  Filename:       rf_common_cmd.h
*  Revised:        2015-09-08 16:06:29 +0200 (ti, 08 sep 2015)
*  Revision:       44530
*
*  Description:    CC26xx API for common/generic commands
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

#ifndef __COMMON_CMD_H
#define __COMMON_CMD_H

#ifndef __RFC_STRUCT
#ifdef __GNUC__
#define __RFC_STRUCT __attribute__ ((aligned (4)))
#else
#define __RFC_STRUCT
#endif
#endif

//! \addtogroup rfc
//! @{

//! \addtogroup common_cmd
//! @{

#include <stdint.h>
#include <driverlib/rf_mailbox.h>

typedef struct __RFC_STRUCT rfc_command_s rfc_command_t;
typedef struct __RFC_STRUCT rfc_radioOp_s rfc_radioOp_t;
typedef struct __RFC_STRUCT rfc_CMD_NOP_s rfc_CMD_NOP_t;
typedef struct __RFC_STRUCT rfc_CMD_RADIO_SETUP_s rfc_CMD_RADIO_SETUP_t;
typedef struct __RFC_STRUCT rfc_CMD_FS_s rfc_CMD_FS_t;
typedef struct __RFC_STRUCT rfc_CMD_FS_OFF_s rfc_CMD_FS_OFF_t;
typedef struct __RFC_STRUCT rfc_CMD_RX_s rfc_CMD_RX_t;
typedef struct __RFC_STRUCT rfc_CMD_TX_s rfc_CMD_TX_t;
typedef struct __RFC_STRUCT rfc_CMD_RX_TEST_s rfc_CMD_RX_TEST_t;
typedef struct __RFC_STRUCT rfc_CMD_TX_TEST_s rfc_CMD_TX_TEST_t;
typedef struct __RFC_STRUCT rfc_CMD_SYNC_STOP_RAT_s rfc_CMD_SYNC_STOP_RAT_t;
typedef struct __RFC_STRUCT rfc_CMD_SYNC_START_RAT_s rfc_CMD_SYNC_START_RAT_t;
typedef struct __RFC_STRUCT rfc_CMD_COUNT_s rfc_CMD_COUNT_t;
typedef struct __RFC_STRUCT rfc_CMD_FS_POWERUP_s rfc_CMD_FS_POWERUP_t;
typedef struct __RFC_STRUCT rfc_CMD_FS_POWERDOWN_s rfc_CMD_FS_POWERDOWN_t;
typedef struct __RFC_STRUCT rfc_CMD_SCH_IMM_s rfc_CMD_SCH_IMM_t;
typedef struct __RFC_STRUCT rfc_CMD_COUNT_BRANCH_s rfc_CMD_COUNT_BRANCH_t;
typedef struct __RFC_STRUCT rfc_CMD_PATTERN_CHECK_s rfc_CMD_PATTERN_CHECK_t;
typedef struct __RFC_STRUCT rfc_CMD_ABORT_s rfc_CMD_ABORT_t;
typedef struct __RFC_STRUCT rfc_CMD_STOP_s rfc_CMD_STOP_t;
typedef struct __RFC_STRUCT rfc_CMD_GET_RSSI_s rfc_CMD_GET_RSSI_t;
typedef struct __RFC_STRUCT rfc_CMD_UPDATE_RADIO_SETUP_s rfc_CMD_UPDATE_RADIO_SETUP_t;
typedef struct __RFC_STRUCT rfc_CMD_TRIGGER_s rfc_CMD_TRIGGER_t;
typedef struct __RFC_STRUCT rfc_CMD_GET_FW_INFO_s rfc_CMD_GET_FW_INFO_t;
typedef struct __RFC_STRUCT rfc_CMD_START_RAT_s rfc_CMD_START_RAT_t;
typedef struct __RFC_STRUCT rfc_CMD_PING_s rfc_CMD_PING_t;
typedef struct __RFC_STRUCT rfc_CMD_READ_RFREG_s rfc_CMD_READ_RFREG_t;
typedef struct __RFC_STRUCT rfc_CMD_ADD_DATA_ENTRY_s rfc_CMD_ADD_DATA_ENTRY_t;
typedef struct __RFC_STRUCT rfc_CMD_REMOVE_DATA_ENTRY_s rfc_CMD_REMOVE_DATA_ENTRY_t;
typedef struct __RFC_STRUCT rfc_CMD_FLUSH_QUEUE_s rfc_CMD_FLUSH_QUEUE_t;
typedef struct __RFC_STRUCT rfc_CMD_CLEAR_RX_s rfc_CMD_CLEAR_RX_t;
typedef struct __RFC_STRUCT rfc_CMD_REMOVE_PENDING_ENTRIES_s rfc_CMD_REMOVE_PENDING_ENTRIES_t;
typedef struct __RFC_STRUCT rfc_CMD_SET_RAT_CMP_s rfc_CMD_SET_RAT_CMP_t;
typedef struct __RFC_STRUCT rfc_CMD_SET_RAT_CPT_s rfc_CMD_SET_RAT_CPT_t;
typedef struct __RFC_STRUCT rfc_CMD_DISABLE_RAT_CH_s rfc_CMD_DISABLE_RAT_CH_t;
typedef struct __RFC_STRUCT rfc_CMD_SET_RAT_OUTPUT_s rfc_CMD_SET_RAT_OUTPUT_t;
typedef struct __RFC_STRUCT rfc_CMD_ARM_RAT_CH_s rfc_CMD_ARM_RAT_CH_t;
typedef struct __RFC_STRUCT rfc_CMD_DISARM_RAT_CH_s rfc_CMD_DISARM_RAT_CH_t;
typedef struct __RFC_STRUCT rfc_CMD_SET_TX_POWER_s rfc_CMD_SET_TX_POWER_t;
typedef struct __RFC_STRUCT rfc_CMD_UPDATE_FS_s rfc_CMD_UPDATE_FS_t;
typedef struct __RFC_STRUCT rfc_CMD_BUS_REQUEST_s rfc_CMD_BUS_REQUEST_t;

//! \addtogroup command
//! @{
struct __RFC_STRUCT rfc_command_s {
   uint16_t commandNo;                  //!<        The command ID number
};

//! @}

//! \addtogroup radioOp
//! @{
//! Common definition for radio operation commands

struct __RFC_STRUCT rfc_radioOp_s {
   uint16_t commandNo;                  //!<        The command ID number
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
};

//! @}

//! \addtogroup CMD_NOP
//! @{
#define CMD_NOP                                                 0x0801
struct __RFC_STRUCT rfc_CMD_NOP_s {
   uint16_t commandNo;                  //!<        The command ID number 0x0801
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
};

//! @}

//! \addtogroup CMD_RADIO_SETUP
//! @{
#define CMD_RADIO_SETUP                                         0x0802
struct __RFC_STRUCT rfc_CMD_RADIO_SETUP_s {
   uint16_t commandNo;                  //!<        The command ID number 0x0802
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
   uint8_t mode;                        //!< \brief The main mode to use<br>
                                        //!<        0x00: BLE<br>
                                        //!<        0x01: IEEE 802.15.4<br>
                                        //!<        0x02: 2 Mbps GFSK<br>
                                        //!<        0x05: 5 Mbps coded 8-FSK<br>
                                        //!<        0x06: ANT<br>
                                        //!<        0xFF: Keep existing mode; update overrides only<br>
                                        //!<        Others: <i>Reserved</i>
   uint8_t __dummy0;
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
   uint16_t txPower;					//!<        Transmit power
   uint32_t* pRegOverride;              //!< \brief Pointer to a list of hardware and configuration registers to override. If NULL, no
                                        //!<        override is used.
};

//! @}

//! \addtogroup CMD_FS
//! @{
#define CMD_FS                                                  0x0803
struct __RFC_STRUCT rfc_CMD_FS_s {
   uint16_t commandNo;                  //!<        The command ID number 0x0803
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
   uint16_t frequency;                  //!<        The frequency in MHz to tune to
   uint16_t fractFreq;                  //!<        Fractional part of the frequency to tune to
   struct {
      uint8_t bTxMode:1;                //!< \brief 0: Start synth in Rx mode<br>
                                        //!<        1: Start synth in Tx mode
      uint8_t refFreq:6;                //!< \brief <i>Reserved</i>
   } synthConf;
   uint8_t __dummy0;
   uint8_t midPrecal;                   //!<        Mid pre-calibration value to use when <code>bOverrideCalib</code> and <code>bSkipCoarseCalib</code> are both 1
   uint8_t ktPrecal;                    //!<        KT pre-calibration value to use when <code>bOverrideCalib</code> and <code>bSkipCoarseCalib</code> are both 1
   uint16_t tdcPrecal;                  //!<        TDC pre-calibration value to use when <code>bOverrideCalib</code> and <code>bSkipCoarseCalib</code> are both 1
};

//! @}

//! \addtogroup CMD_FS_OFF
//! @{
#define CMD_FS_OFF                                              0x0804
struct __RFC_STRUCT rfc_CMD_FS_OFF_s {
   uint16_t commandNo;                  //!<        The command ID number 0x0804
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
};

//! @}

//! \addtogroup CMD_RX
//! @{
#define CMD_RX                                                  0x0805
struct __RFC_STRUCT rfc_CMD_RX_s {
   uint16_t commandNo;                  //!<        The command ID number 0x0805
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
      uint16_t endianness:1;            //!< \brief 0: Least significant bit first<br>
                                        //!<        1: Most significant bit first
      uint16_t numHdrBits:6;            //!<        Number of bits in the header
      uint16_t bFsOff:1;                //!< \brief 0: Keep frequency synth on after command<br>
                                        //!<        1: Turn frequency synth off after command
      uint16_t bUseCrc:1;               //!< \brief 0: No CRC<br>
                                        //!<        1: The last bytes of the packet are a CRC
      uint16_t bCrcIncSw:1;             //!< \brief 0: Do not include sync word in CRC calculation<br>
                                        //!<        1: Include sync word in CRC calculation
      uint16_t bCrcIncHdr:1;            //!< \brief 0: Do not include header in CRC calculation<br>
                                        //!<        1: Include header in CRC calculation
      uint16_t bReportCrc:1;            //!< \brief 0: Do not write CRC to receive buffer<br>
                                        //!<        1: Write received CRC to receive buffer
      uint16_t endType:1;               //!< \brief 0: Packet is received to the end if end trigger happens after sync is obtained<br>
                                        //!<        1: Packet reception is stopped if end trigger happens
      uint16_t bDualSw:1;               //!< \brief 0: Single sync word<br>
                                        //!<        1: Dual sync word.
   } pktConfig;
   uint32_t syncWord;                   //!<        Sync word to receive
   uint32_t syncWord2;                  //!<        Secondary sync word to receive if <code>pktConfig.bDualSw</code> = 1
   struct {
      uint16_t numLenBits:4;            //!<        Number of bits in the length field
      uint16_t lenFieldPos:5;           //!<        Bit position of the first bit in the length field
      uint16_t lenOffset:7;             //!<        Signed number to add to the received length field
   } lenConfig;
   uint16_t maxLen;                     //!<        Maximum number of bytes in the received packet (including header, excluding CRC)
   uint8_t* pRecPkt;                    //!<        Pointer to buffer for received packet. NULL: Do not store the contents.
   ratmr_t endTime;                     //!<        Time to end the operation
   struct {
      uint8_t triggerType:4;            //!<        The type of trigger
      uint8_t bEnaCmd:1;                //!< \brief 0: No alternative trigger command<br>
                                        //!<        1: CMD_TRIGGER can be used as an alternative trigger
      uint8_t triggerNo:2;              //!<        The trigger number of the CMD_TRIGGER command that triggers this action
      uint8_t pastTrig:1;               //!< \brief 0: A trigger in the past is never triggered, or for start of commands, give an error<br>
                                        //!<        1: A trigger in the past is triggered as soon as possible
   } endTrigger;                        //!<        Trigger classifier for ending the operation
   int8_t rssi;                         //!<        RSSI of received packet
   uint16_t recLen;                     //!<        Number of bytes written to receive buffer
   ratmr_t timeStamp;                   //!<        Time stamp of received packet
   uint16_t nRxOk;                      //!<        Counter of number of received packets with CRC OK and first sync word
   uint16_t nRxNok;                     //!<        Counter of number of received packets with CRC error and first sync word
   uint16_t nRx2Ok;                     //!< \brief Counter of number of received packets with CRC OK and second sync word; may safely be
                                        //!<        omitted if <code>pktConfig.bDualSw</code> is 0
   uint16_t nRx2Nok;                    //!< \brief Counter of number of received packets with CRC error and second sync word; may safely be
                                        //!<        omitted if <code>pktConfig.bDualSw</code> is 0
};

//! @}

//! \addtogroup CMD_TX
//! @{
#define CMD_TX                                                  0x0806
struct __RFC_STRUCT rfc_CMD_TX_s {
   uint16_t commandNo;                  //!<        The command ID number 0x0806
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
      uint16_t endianness:1;            //!< \brief 0: Least significant bit first<br>
                                        //!<        1: Most significant bit first
      uint16_t numHdrBits:6;            //!<        Number of bits in the header
      uint16_t bFsOff:1;                //!< \brief 0: Keep frequency synth on after command<br>
                                        //!<        1: Turn frequency synth off after command
      uint16_t bUseCrc:1;               //!< \brief 0: No CRC<br>
                                        //!<        1: Append a CRC to the packet
      uint16_t bCrcIncSw:1;             //!< \brief 0: Do not include sync word in CRC calculation<br>
                                        //!<        1: Include sync word in CRC calculation
      uint16_t bCrcIncHdr:1;            //!< \brief 0: Do not include header in CRC calculation<br>
                                        //!<        1: Include header in CRC calculation
   } pktConfig;
   uint32_t syncWord;                   //!<        Sync word to transmit
   uint8_t* pTxPkt;                     //!<        Pointer to buffer for transmitted packet.
   uint16_t pktLen;                     //!<        Number of bytes in the transmitted packet
};

//! @}

//! \addtogroup CMD_RX_TEST
//! @{
#define CMD_RX_TEST                                             0x0807
struct __RFC_STRUCT rfc_CMD_RX_TEST_s {
   uint16_t commandNo;                  //!<        The command ID number 0x0807
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
      uint8_t bEnaFifo:1;               //!< \brief 0: Do not enable FIFO in modem, so that received data is not available<br>
                                        //!<        1: Enable FIFO in modem &ndash; the data must be read out by the application
      uint8_t bFsOff:1;                 //!< \brief 0: Keep frequency synth on after command<br>
                                        //!<        1: Turn frequency synth off after command
      uint8_t bNoSync:1;                //!< \brief 0: Run sync search as normal for the configured mode<br>
                                        //!<        1: Write correlation thresholds to the maximum value to avoid getting sync
   } config;
   struct {
      uint8_t triggerType:4;            //!<        The type of trigger
      uint8_t bEnaCmd:1;                //!< \brief 0: No alternative trigger command<br>
                                        //!<        1: CMD_TRIGGER can be used as an alternative trigger
      uint8_t triggerNo:2;              //!<        The trigger number of the CMD_TRIGGER command that triggers this action
      uint8_t pastTrig:1;               //!< \brief 0: A trigger in the past is never triggered, or for start of commands, give an error<br>
                                        //!<        1: A trigger in the past is triggered as soon as possible
   } endTrigger;                        //!<        Trigger classifier for ending the operation
   uint32_t syncWord;                   //!<        Sync word to use for receiver
   ratmr_t endTime;                     //!<        Time to end the operation
};

//! @}

//! \addtogroup CMD_TX_TEST
//! @{
#define CMD_TX_TEST                                             0x0808
struct __RFC_STRUCT rfc_CMD_TX_TEST_s {
   uint16_t commandNo;                  //!<        The command ID number 0x0808
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
      uint8_t bUseCw:1;                 //!< \brief 0: Send modulated signal<br>
                                        //!<        1: Send continuous wave
      uint8_t bFsOff:1;                 //!< \brief 0: Keep frequency synth on after command<br>
                                        //!<        1: Turn frequency synth off after command
      uint8_t whitenMode:2;             //!< \brief 0: No whitening<br>
                                        //!<        1: Default whitening<br>
                                        //!<        2: PRBS-15<br>
                                        //!<        3: PRBS-32
   } config;
   uint8_t __dummy0;
   uint16_t txWord;                     //!<        Value to send to the modem before whitening
   uint8_t __dummy1;
   struct {
      uint8_t triggerType:4;            //!<        The type of trigger
      uint8_t bEnaCmd:1;                //!< \brief 0: No alternative trigger command<br>
                                        //!<        1: CMD_TRIGGER can be used as an alternative trigger
      uint8_t triggerNo:2;              //!<        The trigger number of the CMD_TRIGGER command that triggers this action
      uint8_t pastTrig:1;               //!< \brief 0: A trigger in the past is never triggered, or for start of commands, give an error<br>
                                        //!<        1: A trigger in the past is triggered as soon as possible
   } endTrigger;                        //!<        Trigger classifier for ending the operation
   uint32_t syncWord;                   //!<        Sync word to use for transmitter
   ratmr_t endTime;                     //!<        Time to end the operation
};

//! @}

//! \addtogroup CMD_SYNC_STOP_RAT
//! @{
#define CMD_SYNC_STOP_RAT                                       0x0809
struct __RFC_STRUCT rfc_CMD_SYNC_STOP_RAT_s {
   uint16_t commandNo;                  //!<        The command ID number 0x0809
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
   uint16_t __dummy0;
   ratmr_t rat0;                        //!< \brief The returned RAT timer value corresponding to the value the RAT would have had when the
                                        //!<        RTC was zero
};

//! @}

//! \addtogroup CMD_SYNC_START_RAT
//! @{
#define CMD_SYNC_START_RAT                                      0x080A
struct __RFC_STRUCT rfc_CMD_SYNC_START_RAT_s {
   uint16_t commandNo;                  //!<        The command ID number 0x080A
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
   uint16_t __dummy0;
   ratmr_t rat0;                        //!< \brief The desired RAT timer value corresponding to the value the RAT would have had when the
                                        //!<        RTC was zero. This parameter is returned by CMD_SYNC_STOP_RAT
};

//! @}

//! \addtogroup CMD_COUNT
//! @{
#define CMD_COUNT                                               0x080B
struct __RFC_STRUCT rfc_CMD_COUNT_s {
   uint16_t commandNo;                  //!<        The command ID number 0x080B
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
   uint16_t counter;                    //!< \brief Counter. On start, the radio CPU decrements the value, and the end status of the operation
                                        //!<        differs if the result is zero
};

//! @}

//! \addtogroup CMD_FS_POWERUP
//! @{
#define CMD_FS_POWERUP                                          0x080C
struct __RFC_STRUCT rfc_CMD_FS_POWERUP_s {
   uint16_t commandNo;                  //!<        The command ID number 0x080C
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
   uint16_t __dummy0;
   uint32_t* pRegOverride;              //!<        Pointer to a list of hardware and configuration registers to override. If NULL, no override is used.
};

//! @}

//! \addtogroup CMD_FS_POWERDOWN
//! @{
#define CMD_FS_POWERDOWN                                        0x080D
struct __RFC_STRUCT rfc_CMD_FS_POWERDOWN_s {
   uint16_t commandNo;                  //!<        The command ID number 0x080D
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
};

//! @}

//! \addtogroup CMD_SCH_IMM
//! @{
#define CMD_SCH_IMM                                             0x0810
struct __RFC_STRUCT rfc_CMD_SCH_IMM_s {
   uint16_t commandNo;                  //!<        The command ID number 0x0810
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
   uint16_t __dummy0;
   uint32_t cmdrVal;                    //!<        Value as would be written to CMDR
   uint32_t cmdstaVal;                  //!<        Value as would be returned in CMDSTA
};

//! @}

//! \addtogroup CMD_COUNT_BRANCH
//! @{
#define CMD_COUNT_BRANCH                                        0x0812
struct __RFC_STRUCT rfc_CMD_COUNT_BRANCH_s {
   uint16_t commandNo;                  //!<        The command ID number 0x0812
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
   uint16_t counter;                    //!< \brief Counter. On start, the radio CPU decrements the value, and the end status of the operation
                                        //!<        differs if the result is zero
   rfc_radioOp_t *pNextOpIfOk;          //!<        Pointer to next operation if counter did not expire
};

//! @}

//! \addtogroup CMD_PATTERN_CHECK
//! @{
#define CMD_PATTERN_CHECK                                       0x0813
struct __RFC_STRUCT rfc_CMD_PATTERN_CHECK_s {
   uint16_t commandNo;                  //!<        The command ID number 0x0813
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
      uint16_t operation:2;             //!< \brief Operation to perform<br>
                                        //!<        0: True if value == <code>compareVal</code><br>
                                        //!<        1: True if value < <code>compareVal</code><br>
                                        //!<        2: True if value > <code>compareVal</code><br>
                                        //!<        3: <i>Reserved</i>
      uint16_t bByteRev:1;              //!< \brief If 1, interchange the four bytes of the value, so that they are read
                                        //!<        most-significant-byte-first.
      uint16_t bBitRev:1;               //!<        If 1, perform bit reversal of the value
      uint16_t signExtend:5;            //!< \brief 0: Treat value and <code>compareVal</code> as unsigned<br>
                                        //!<        1&ndash;31: Treat value and <code>compareVal</code> as signed, where the value
                                        //!<        gives the number of the most significant bit in the signed number.
      uint16_t bRxVal:1;                //!< \brief 0: Use <code>pValue</code> as a pointer<br>
                                        //!<        1: Use <code>pValue</code> as a signed offset to the start of the last
                                        //!<        committed Rx entry element
   } patternOpt;                        //!<        Options for comparison
   rfc_radioOp_t *pNextOpIfOk;          //!<        Pointer to next operation if comparison result was true
   uint8_t* pValue;                     //!<        Pointer to read from, or offset from last Rx entry if <code>patternOpt.bRxVal</code> == 1
   uint32_t mask;                       //!<        Bit mask to apply before comparison
   uint32_t compareVal;                 //!<        Value to compare to
};

//! @}

//! \addtogroup CMD_ABORT
//! @{
#define CMD_ABORT                                               0x0401
struct __RFC_STRUCT rfc_CMD_ABORT_s {
   uint16_t commandNo;                  //!<        The command ID number 0x0401
};

//! @}

//! \addtogroup CMD_STOP
//! @{
#define CMD_STOP                                                0x0402
struct __RFC_STRUCT rfc_CMD_STOP_s {
   uint16_t commandNo;                  //!<        The command ID number 0x0402
};

//! @}

//! \addtogroup CMD_GET_RSSI
//! @{
#define CMD_GET_RSSI                                            0x0403
struct __RFC_STRUCT rfc_CMD_GET_RSSI_s {
   uint16_t commandNo;                  //!<        The command ID number 0x0403
};

//! @}

//! \addtogroup CMD_UPDATE_RADIO_SETUP
//! @{
#define CMD_UPDATE_RADIO_SETUP                                  0x0001
struct __RFC_STRUCT rfc_CMD_UPDATE_RADIO_SETUP_s {
   uint16_t commandNo;                  //!<        The command ID number 0x0001
   uint16_t __dummy0;
   uint32_t* pRegOverride;              //!<        Pointer to a list of hardware and configuration registers to override
};

//! @}

//! \addtogroup CMD_TRIGGER
//! @{
#define CMD_TRIGGER                                             0x0404
struct __RFC_STRUCT rfc_CMD_TRIGGER_s {
   uint16_t commandNo;                  //!<        The command ID number 0x0404
   uint8_t triggerNo;                   //!<        Command trigger number
};

//! @}

//! \addtogroup CMD_GET_FW_INFO
//! @{
#define CMD_GET_FW_INFO                                         0x0002
struct __RFC_STRUCT rfc_CMD_GET_FW_INFO_s {
   uint16_t commandNo;                  //!<        The command ID number 0x0002
   uint16_t versionNo;                  //!<        Firmware version number
   uint16_t startOffset;                //!<        The start of free RAM
   uint16_t freeRamSz;                  //!<        The size of free RAM
   uint16_t availRatCh;                 //!<        Bitmap of available RAT channels
};

//! @}

//! \addtogroup CMD_START_RAT
//! @{
#define CMD_START_RAT                                           0x0405
struct __RFC_STRUCT rfc_CMD_START_RAT_s {
   uint16_t commandNo;                  //!<        The command ID number 0x0405
};

//! @}

//! \addtogroup CMD_PING
//! @{
#define CMD_PING                                                0x0406
struct __RFC_STRUCT rfc_CMD_PING_s {
   uint16_t commandNo;                  //!<        The command ID number 0x0406
};

//! @}

//! \addtogroup CMD_READ_RFREG
//! @{
#define CMD_READ_RFREG                                          0x0601

struct __RFC_STRUCT rfc_CMD_READ_RFREG_s {
   uint16_t commandNo;                  //!<        The command ID number 0x0601
   uint16_t address;                    //!<        The offset from the start of the RF core HW register bank (0x40040000)
   uint32_t value;                      //!<        Returned value of the register
};

//! @}

//! \addtogroup CMD_ADD_DATA_ENTRY
//! @{
#define CMD_ADD_DATA_ENTRY                                      0x0005
struct __RFC_STRUCT rfc_CMD_ADD_DATA_ENTRY_s {
   uint16_t commandNo;                  //!<        The command ID number 0x0005
   uint16_t __dummy0;
   dataQueue_t* pQueue;                 //!<        Pointer to the queue structure to which the entry will be added
   uint8_t* pEntry;                     //!<        Pointer to the entry
};

//! @}

//! \addtogroup CMD_REMOVE_DATA_ENTRY
//! @{
#define CMD_REMOVE_DATA_ENTRY                                   0x0006
struct __RFC_STRUCT rfc_CMD_REMOVE_DATA_ENTRY_s {
   uint16_t commandNo;                  //!<        The command ID number 0x0006
   uint16_t __dummy0;
   dataQueue_t* pQueue;                 //!<        Pointer to the queue structure from which the entry will be removed
   uint8_t* pEntry;                     //!<        Pointer to the entry that was removed
};

//! @}

//! \addtogroup CMD_FLUSH_QUEUE
//! @{
#define CMD_FLUSH_QUEUE                                         0x0007
struct __RFC_STRUCT rfc_CMD_FLUSH_QUEUE_s {
   uint16_t commandNo;                  //!<        The command ID number 0x0007
   uint16_t __dummy0;
   dataQueue_t* pQueue;                 //!<        Pointer to the queue structure to be flushed
   uint8_t* pFirstEntry;                //!<        Pointer to the first entry that was removed
};

//! @}

//! \addtogroup CMD_CLEAR_RX
//! @{
#define CMD_CLEAR_RX                                            0x0008
struct __RFC_STRUCT rfc_CMD_CLEAR_RX_s {
   uint16_t commandNo;                  //!<        The command ID number 0x0008
   uint16_t __dummy0;
   dataQueue_t* pQueue;                 //!<        Pointer to the queue structure to be cleared
};

//! @}

//! \addtogroup CMD_REMOVE_PENDING_ENTRIES
//! @{
#define CMD_REMOVE_PENDING_ENTRIES                              0x0009
struct __RFC_STRUCT rfc_CMD_REMOVE_PENDING_ENTRIES_s {
   uint16_t commandNo;                  //!<        The command ID number 0x0009
   uint16_t __dummy0;
   dataQueue_t* pQueue;                 //!<        Pointer to the queue structure to be flushed
   uint8_t* pFirstEntry;                //!<        Pointer to the first entry that was removed
};

//! @}

//! \addtogroup CMD_SET_RAT_CMP
//! @{
#define CMD_SET_RAT_CMP                                         0x000A
struct __RFC_STRUCT rfc_CMD_SET_RAT_CMP_s {
   uint16_t commandNo;                  //!<        The command ID number 0x000A
   uint8_t ratCh;                       //!<        The radio timer channel number
   uint8_t __dummy0;
   ratmr_t compareTime;                 //!<        The time at which the compare occurs
};

//! @}

//! \addtogroup CMD_SET_RAT_CPT
//! @{
#define CMD_SET_RAT_CPT                                         0x0603
struct __RFC_STRUCT rfc_CMD_SET_RAT_CPT_s {
   uint16_t commandNo;                  //!<        The command ID number 0x0603
   struct {
      uint16_t :3;
      uint16_t inputSrc:5;              //!<        Input source indicator
      uint16_t ratCh:4;                 //!<        The radio timer channel number
      uint16_t bRepeated:1;             //!< \brief 0: Single capture mode<br>
                                        //!<        1: Repeated capture mode
      uint16_t inputMode:2;             //!< \brief Input mode:<br>
                                        //!<        0: Capture on rising edge<br>
                                        //!<        1: Capture on falling edge<br>
                                        //!<        2: Capture on both edges<br>
                                        //!<        3: <i>Reserved</i>
   } config;
};

//! @}

//! \addtogroup CMD_DISABLE_RAT_CH
//! @{
#define CMD_DISABLE_RAT_CH                                      0x0408
struct __RFC_STRUCT rfc_CMD_DISABLE_RAT_CH_s {
   uint16_t commandNo;                  //!<        The command ID number 0x0408
   uint8_t ratCh;                       //!<        The radio timer channel number
};

//! @}

//! \addtogroup CMD_SET_RAT_OUTPUT
//! @{
#define CMD_SET_RAT_OUTPUT                                      0x0604
struct __RFC_STRUCT rfc_CMD_SET_RAT_OUTPUT_s {
   uint16_t commandNo;                  //!<        The command ID number 0x0604
   struct {
      uint16_t :2;
      uint16_t outputSel:3;             //!<        Output event indicator
      uint16_t outputMode:3;            //!< \brief 0: Set output line low as default; and pulse on event. Duration of pulse is one RF Core clock period (ca. 41.67 ns).<br>
                                        //!<        1: Set output line high on event<br>
                                        //!<        2: Set output line low on event<br>
                                        //!<        3: Toggle (invert) output line state on event<br>
                                        //!<        4: Immediately set output line to low (does not change upon event)<br>
                                        //!<        5: Immediately set output line to high (does not change upon event)<br>
                                        //!<        Others: <i>Reserved</i>
      uint16_t ratCh:4;                 //!<        The radio timer channel number
   } config;
};

//! @}

//! \addtogroup CMD_ARM_RAT_CH
//! @{
#define CMD_ARM_RAT_CH                                          0x0409
struct __RFC_STRUCT rfc_CMD_ARM_RAT_CH_s {
   uint16_t commandNo;                  //!<        The command ID number 0x0409
   uint8_t ratCh;                       //!<        The radio timer channel number
};

//! @}

//! \addtogroup CMD_DISARM_RAT_CH
//! @{
#define CMD_DISARM_RAT_CH                                       0x040A
struct __RFC_STRUCT rfc_CMD_DISARM_RAT_CH_s {
   uint16_t commandNo;                  //!<        The command ID number 0x040A
   uint8_t ratCh;                       //!<        The radio timer channel number
};

//! @}

//! \addtogroup CMD_SET_TX_POWER
//! @{
#define CMD_SET_TX_POWER                                        0x0010
struct __RFC_STRUCT rfc_CMD_SET_TX_POWER_s {
   uint16_t commandNo;                  //!<        The command ID number 0x0010
   struct {
      uint16_t IB:6;                    //!<        Value to write to the PA power control field at 25 &deg;C
      uint16_t GC:2;                    //!<        Value to write to the gain control of the 1st stage of the PA
      uint16_t boost:1;                 //!<        Value of boost bit in synth
      uint16_t tempCoeff:7;             //!<        Temperature coefficient for IB. 0: No temperature compensation
   } txPower;                           //!<        New Tx power setting
};

//! @}

//! \addtogroup CMD_UPDATE_FS
//! @{
#define CMD_UPDATE_FS                                           0x0011
struct __RFC_STRUCT rfc_CMD_UPDATE_FS_s {
   uint16_t commandNo;                  //!<        The command ID number 0x0011
   uint16_t frequency;                  //!<        The frequency in MHz to tune to
   uint16_t fractFreq;                  //!<        Fractional part of the frequency to tune to
};

//! @}

//! \addtogroup CMD_BUS_REQUEST
//! @{
#define CMD_BUS_REQUEST                                         0x040E
struct __RFC_STRUCT rfc_CMD_BUS_REQUEST_s {
   uint16_t commandNo;                  //!<        The command ID number 0x040E
   uint8_t bSysBusNeeded;               //!< \brief 0: System bus may sleep<br>
                                        //!<        1: System bus access needed
};

//! @}

//! @}
//! @}
#endif
