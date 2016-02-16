/******************************************************************************
*  Filename:       rf_ble_mailbox.h
*  Revised:        2015-09-28 11:32:09 +0200 (må, 28 sep 2015)
*  Revision:       44677
*
*  Description:    Definitions for BLE mode radio interface
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

#ifndef __BLE_MAILBOX_H
#define __BLE_MAILBOX_H

#include <driverlib/rf_mailbox.h>

/// \name CPE interrupt definitions for BLE
/// Interrupt masks for the CPE interrupt in RDBELL. These are new names for interrupts in rf_mailbox.h,
/// used for compartibility with previous versions with separate interrupt numbers.
///@{
#define IRQN_BLE_TX_DONE            IRQN_TX_DONE
#define IRQN_BLE_TX_ACK             IRQN_TX_ACK
#define IRQN_BLE_TX_CTRL            IRQN_TX_CTRL
#define IRQN_BLE_TX_CTRL_ACK        IRQN_TX_CTRL_ACK
#define IRQN_BLE_TX_CTRL_ACK_ACK    IRQN_TX_CTRL_ACK_ACK
#define IRQN_BLE_TX_RETRANS         IRQN_TX_RETRANS
#define IRQN_BLE_TX_ENTRY_DONE      IRQN_TX_ENTRY_DONE
#define IRQN_BLE_TX_BUFFER_CHANGED  IRQN_TX_BUFFER_CHANGED
#define IRQN_BLE_RX_OK              IRQN_RX_OK
#define IRQN_BLE_RX_NOK             IRQN_RX_NOK
#define IRQN_BLE_RX_IGNORED         IRQN_RX_IGNORED
#define IRQN_BLE_RX_EMPTY           IRQN_RX_EMPTY
#define IRQN_BLE_RX_CTRL            IRQN_RX_CTRL
#define IRQN_BLE_RX_CTRL_ACK        IRQN_RX_CTRL_ACK
#define IRQN_BLE_RX_BUF_FULL        IRQN_RX_BUF_FULL
#define IRQN_BLE_RX_ENTRY_DONE      IRQN_RX_ENTRY_DONE

#define IRQ_BLE_TX_DONE             (1U << IRQN_BLE_TX_DONE)
#define IRQ_BLE_TX_ACK              (1U << IRQN_BLE_TX_ACK)
#define IRQ_BLE_TX_CTRL             (1U << IRQN_BLE_TX_CTRL)
#define IRQ_BLE_TX_CTRL_ACK         (1U << IRQN_BLE_TX_CTRL_ACK)
#define IRQ_BLE_TX_CTRL_ACK_ACK     (1U << IRQN_BLE_TX_CTRL_ACK_ACK)
#define IRQ_BLE_TX_RETRANS          (1U << IRQN_BLE_TX_RETRANS)
#define IRQ_BLE_TX_ENTRY_DONE       (1U << IRQN_BLE_TX_ENTRY_DONE)
#define IRQ_BLE_TX_BUFFER_CHANGED   (1U << IRQN_BLE_TX_BUFFER_CHANGED)
#define IRQ_BLE_RX_OK               (1U << IRQN_BLE_RX_OK)
#define IRQ_BLE_RX_NOK              (1U << IRQN_BLE_RX_NOK)
#define IRQ_BLE_RX_IGNORED          (1U << IRQN_BLE_RX_IGNORED)
#define IRQ_BLE_RX_EMPTY            (1U << IRQN_BLE_RX_EMPTY)
#define IRQ_BLE_RX_CTRL             (1U << IRQN_BLE_RX_CTRL)
#define IRQ_BLE_RX_CTRL_ACK         (1U << IRQN_BLE_RX_CTRL_ACK)
#define IRQ_BLE_RX_BUF_FULL         (1U << IRQN_BLE_RX_BUF_FULL)
#define IRQ_BLE_RX_ENTRY_DONE       (1U << IRQN_BLE_RX_ENTRY_DONE)
///@}

/// \name Operation finished normally
///@{
#define BLE_DONE_OK             0x1400  ///< Operation ended normally
#define BLE_DONE_RXTIMEOUT      0x1401  ///< Timeout of first Rx of slave operation or end of scan window
#define BLE_DONE_NOSYNC         0x1402  ///< Timeout of subsequent Rx
#define BLE_DONE_RXERR          0x1403  ///< Operation ended because of receive error (CRC or other)
#define BLE_DONE_CONNECT        0x1404  ///< CONNECT_REQ received or transmitted
#define BLE_DONE_MAXNACK        0x1405  ///< Maximum number of retransmissions exceeded
#define BLE_DONE_ENDED          0x1406  ///< Operation stopped after end trigger
#define BLE_DONE_ABORT          0x1407  ///< Operation aborted by command
#define BLE_DONE_STOPPED        0x1408  ///< Operation stopped after stop command
///@}
/// \name Operation finished with error
///@{
#define BLE_ERROR_PAR           0x1800  ///< Illegal parameter
#define BLE_ERROR_RXBUF         0x1801  ///< No available Rx buffer (Advertiser, Scanner, Initiator)
#define BLE_ERROR_NO_SETUP      0x1802  ///< Operation using Rx or Tx attemted when not in BLE mode
#define BLE_ERROR_NO_FS         0x1803  ///< Operation using Rx or Tx attemted without frequency synth configured
#define BLE_ERROR_SYNTH_PROG    0x1804  ///< Synthesizer programming failed to complete on time
#define BLE_ERROR_RXOVF         0x1805  ///< Receiver overflowed during operation
#define BLE_ERROR_TXUNF         0x1806  ///< Transmitter underflowed during operation
///@}
///@}

#endif
