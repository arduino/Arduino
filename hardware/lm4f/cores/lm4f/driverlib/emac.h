//*****************************************************************************
//
// emac.h - Defines and Macros for the Ethernet module on Snowflake-class
//          devices.
//
// Copyright (c) 2012-2013 Texas Instruments Incorporated.  All rights reserved.
// Software License Agreement
// 
//   Redistribution and use in source and binary forms, with or without
//   modification, are permitted provided that the following conditions
//   are met:
// 
//   Redistributions of source code must retain the above copyright
//   notice, this list of conditions and the following disclaimer.
// 
//   Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the
//   documentation and/or other materials provided with the  
//   distribution.
// 
//   Neither the name of Texas Instruments Incorporated nor the names of
//   its contributors may be used to endorse or promote products derived
//   from this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// 
// This is part of revision 2.0.1.11577 of the Tiva Peripheral Driver Library.
//
//*****************************************************************************

#ifndef __DRIVERLIB_EMAC_H__
#define __DRIVERLIB_EMAC_H__

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

//*****************************************************************************
//
//! \addtogroup emac_api
//! @{
//
//*****************************************************************************

//*****************************************************************************
//
// The physical address of the internal PHY.  This should be in hw_emac.h.
//
//*****************************************************************************
#define EMAC_PHY_ADDR 0

//*****************************************************************************
//
// Helper Macros for Ethernet Processing
//
//*****************************************************************************
//
// htonl/ntohl - Big endian/little endian byte swapping macros for 32-bit
// values.
//
//*****************************************************************************
#ifndef htonl
    #define htonl(a)                    \
        ((((a) >> 24) & 0x000000ff) |   \
         (((a) >>  8) & 0x0000ff00) |   \
         (((a) <<  8) & 0x00ff0000) |   \
         (((a) << 24) & 0xff000000))
#endif

#ifndef ntohl
    #define ntohl(a)    htonl((a))
#endif

//*****************************************************************************
//
// htons/ntohs - Big endian/little endian byte swapping macros for 16-bit
// values.
//
//*****************************************************************************
#ifndef htons
    #define htons(a)                \
        ((((a) >> 8) & 0x00ff) |    \
         (((a) << 8) & 0xff00))
#endif

#ifndef ntohs
    #define ntohs(a)    htons((a))
#endif

//*****************************************************************************
//
// Forward reference to the Ethernet DMA descriptor structure.
//
//*****************************************************************************
typedef struct tEMACDMADescriptor tEMACDMADescriptor;

//*****************************************************************************
//
//! A union used to describe the two overlapping fields forming the third
//! word of the Ethernet DMA descriptor.
//
//*****************************************************************************
typedef union
{
    //
    //! When DMA descriptors are used in chained mode, this field is used to
    //! provide a link to the next descriptor.
    //
    tEMACDMADescriptor *pLink;

    //
    //! When the DMA descriptors are unchained, this field may be used to point
    //! to a second buffer containing data for transmission or providing
    //! storage for a received frame.
    //
    void *pvBuffer2;
}
tEMACDES3;

//*****************************************************************************
//
//! A structure defining a single Ethernet DMA buffer descriptor.
//
//*****************************************************************************
struct tEMACDMADescriptor
{
    //
    //! The first DMA descriptor word contains various control and status bits
    //! depending upon whether the descriptor is in the transmit or receive
    //! queue.  Bit 31 is always the ``OWN'' bit which, when set, indicates
    //! that the hardware has control of the descriptor.
    //
    uint32_t ui32CtrlStatus;

    //
    //! The second descriptor word contains information on the size of the
    //! buffer or buffers attached to the descriptor and various additional
    //! control bits.
    //
    uint32_t ui32Count;

    //
    //! The third descriptor word contains a pointer to the buffer containing
    //! data to transmit or into which received data should be written.  This
    //! pointer must refer to a buffer in internal SRAM.  Pointers to flash or
    //! EPI-connected memory may not be used and will result in the MAC
    //! reporting a bus error.
    //
    void *pvBuffer1;

    //
    //! The fourth descriptor word contains either a pointer to the next
    //! descriptor in the ring or a pointer to a second data buffer.  The
    //! meaning of the word is controlled by the ``CHAINED'' control bit which
    //! appears in the first word of the transmit descriptor or the second
    //! word of the receive descriptor.
    //!
    tEMACDES3 DES3;

    //
    //! The fifth descriptor word is reserved for transmit descriptors but
    //! used to report extended status in a receive descriptor.
    //
    uint32_t ui32ExtRxStatus;

    //
    //! The sixth descriptor word is reserved for both transmit and receive
    //! descriptors.
    //
    uint32_t ui32Reserved;

    //
    //! The seventh descriptor word contains the low 32 bits of the 64-bit
    //! timestamp captured for transmitted or received data.  The value is set
    //! only when the transmitted or received data contains the end of a
    //! packet.  Availability of the timestamp is indicated via a status bit
    //! in the first descriptor word.
    //
    uint32_t ui32IEEE1588TimeLo;

    //
    //! The eighth descriptor word contains the high 32 bits of the 64-bit
    //! timestamp captured for transmitted or received data.
    //
    uint32_t ui32IEEE1588TimeHi;
};

//*****************************************************************************
//
// Fields found in the DES0 word of the transmit descriptor (ui32CtrlStatus in
// tEMACDMADescriptor)
//
//*****************************************************************************
#define DES0_TX_CTRL_OWN                    0x80000000
#define DES0_TX_CTRL_INTERRUPT              0x40000000
#define DES0_TX_CTRL_LAST_SEG               0x20000000
#define DES0_TX_CTRL_FIRST_SEG              0x10000000

//
// This value indicates that the MAC should not append a CRC to transmitted
// packets.  If used with DES0_TX_CTRL_REPLACE_CRC, the last 4 bytes of the
// packet passed to the transmitter are replaced with a newly calculated CRC.
// If DES0_TX_CTRL_REPLACE_CRC is not specified, it is assumed that packets
// transmitted have valid CRCs precomputed and included in the frame data.
//
// If DES0_TX_CTRL_DISABLE_CRC is not specified, the MAC will calculate the
// CRC for all frames transmitted and append this value as the 4-byte FCS
// after the last data byte in the frame.
//
#define DES0_TX_CTRL_DISABLE_CRC            0x08000000
#define DES0_TX_CTRL_DISABLE_PADDING        0x04000000
#define DES0_TX_CTRL_ENABLE_TS              0x02000000

//
// This value is only valid if used alongside DES0_TX_CTRL_DISABLE_CRC.  When
// specified, the MAC will replace the last 4 bytes of a transmitted frame
// with a newly calculated CRC.
//
#define DES0_TX_CTRL_REPLACE_CRC            0x01000000
#define DES0_TX_CTRL_CHKSUM_M               0x00C00000
#define DES0_TX_CTRL_NO_CHKSUM              0x00000000
#define DES0_TX_CTRL_IP_HDR_CHKSUM          0x00400000
#define DES0_TX_CTRL_IP_HDR_PAY_CHKSUM      0x00800000
#define DES0_TX_CTRL_IP_ALL_CKHSUMS         0x00C00000
#define DES0_TX_CTRL_END_OF_RING            0x00200000
#define DES0_TX_CTRL_CHAINED                0x00100000
#define DES0_TX_CTRL_VLAN_M                 0x000C0000
#define DES0_TX_CTRL_VLAN_NONE              0x00000000
#define DES0_TX_CTRL_VLAN_REMOVE            0x00040000
#define DES0_TX_CTRL_VLAN_INSERT            0x00080000
#define DES0_TX_CTRL_VLAN_REPLACE           0x000C0000
#define DES0_TX_STAT_TS_CAPTURED            0x00020000
#define DES0_TX_STAT_IPH_ERR                0x00010000
#define DES0_TX_STAT_ERR                    0x00008000
#define DES0_TX_STAT_JABBER_TO              0x00004000
#define DES0_TX_STAT_FLUSHED                0x00002000
#define DES0_TX_STAT_PAYLOAD_ERR            0x00001000
#define DES0_TX_STAT_CARRIER_LOST           0x00000800
#define DES0_TX_STAT_NO_CARRIER             0x00000400
#define DES0_TX_STAT_TX_L_COLLISION         0x00000200
#define DES0_TX_STAT_E_COLLISION            0x00000100
#define DES0_TX_STAT_VLAN_FRAME             0x00000080
#define DES0_TX_STAT_COL_COUNT_M            0x00000078
#define DES0_TX_STAT_COL_COUNT_S            3
#define DES0_TX_STAT_E_DEFERRAL             0x00000004
#define DES0_TX_STAT_UNDERFLOW              0x00000002
#define DES0_TX_STAT_DEFERRED               0x00000001

//*****************************************************************************
//
// Fields found in the DES1 word of the transmit descriptor (ui32Count in
// tEMACDMADescriptor)
//
//*****************************************************************************
#define DES1_TX_CTRL_SADDR_MAC1             0x80000000
#define DES1_TX_CTRL_SADDR_M                0x60000000
#define DES1_TX_CTRL_SADDR_NONE             0x00000000
#define DES1_TX_CTRL_SADDR_INSERT           0x20000000
#define DES1_TX_CTRL_SADDR_REPLACE          0x40000000
#define DES1_TX_CTRL_BUFF2_SIZE_M           0x1FFF0000
#define DES1_TX_CTRL_BUFF1_SIZE_M           0x00001FFF
#define DES1_TX_CTRL_BUFF2_SIZE_S           16
#define DES1_TX_CTRL_BUFF1_SIZE_S           0

//*****************************************************************************
//
// Fields found in the DES0 word of the receive descriptor (ui32CtrlStatus in
// tEMACDMADescriptor)
//
//*****************************************************************************
#define DES0_RX_CTRL_OWN                    0x80000000
#define DES0_RX_STAT_DEST_ADDR_FAIL         0x40000000
#define DES0_RX_STAT_FRAME_LENGTH_M         0x3FFF0000
#define DES0_RX_STAT_FRAME_LENGTH_S         16
#define DES0_RX_STAT_ERR                    0x00008000
#define DES0_RX_STAT_DESCRIPTOR_ERR         0x00004000
#define DES0_RX_STAT_SRC_ADDR_FAIL          0x00002000
#define DES0_RX_STAT_LENGTH_ERR             0x00001000
#define DES0_RX_STAT_OVERFLOW               0x00000800
#define DES0_RX_STAT_VLAN_TAG               0x00000400
#define DES0_RX_STAT_FIRST_DESC             0x00000200
#define DES0_RX_STAT_LAST_DESC              0x00000100
#define DES0_RX_STAT_TS_AVAILABLE           0x00000080
#define DES0_RX_STAT_RX_L_COLLISION         0x00000040
#define DES0_RX_STAT_FRAME_TYPE             0x00000020
#define DES0_RX_STAT_WDOG_TIMEOUT           0x00000010
#define DES0_RX_STAT_RX_ERR                 0x00000008
#define DES0_RX_STAT_DRIBBLE_ERR            0x00000004
#define DES0_RX_STAT_CRC_ERR                0x00000002
#define DES0_RX_STAT_MAC_ADDR               0x00000001
#define DES0_RX_STAT_EXT_AVAILABLE          0x00000001

//*****************************************************************************
//
// Fields found in the DES1 word of the receive descriptor (ui32Count in
// tEMACDMADescriptor)
//
//*****************************************************************************
#define DES1_RX_CTRL_DISABLE_INT            0x80000000
#define DES1_RX_CTRL_BUFF2_SIZE_M           0x1FFF0000
#define DES1_RX_CTRL_BUFF2_SIZE_S           16
#define DES1_RX_CTRL_END_OF_RING            0x00008000
#define DES1_RX_CTRL_CHAINED                0x00004000
#define DES1_RX_CTRL_BUFF1_SIZE_M           0x00001FFF
#define DES1_RX_CTRL_BUFF1_SIZE_S           0

//*****************************************************************************
//
// Fields found in the DES4 word of the receive descriptor (ui32ExtRxStatus in
// tEMACDMADescriptor)
//
//*****************************************************************************
#define DES4_RX_STAT_TS_DROPPED             0x00004000
#define DES4_RX_STAT_PTP_VERSION2           0x00002000
#define DES4_RX_STAT_PTP_TYPE_ETH           0x00001000
#define DES4_RX_STAT_PTP_TYPE_UDP           0x00000000
#define DES4_RX_STAT_PTP_MT_M               0x00000F00
#define DES4_RX_STAT_PTP_MT_NONE            0x00000000
#define DES4_RX_STAT_PTP_MT_SYNC            0x00000100
#define DES4_RX_STAT_PTP_MT_FOLLOW_UP       0x00000200
#define DES4_RX_STAT_PTP_MT_DELAY_REQ       0x00000300
#define DES4_RX_STAT_PTP_MT_DELAY_RESP      0x00000400
#define DES4_RX_STAT_PTP_MT_PDELAY_REQ      0x00000500
#define DES4_RX_STAT_PTP_MT_PDELAY_RESP     0x00000600
#define DES4_RX_STAT_PTP_MT_PDELAY_RFU      0x00000700
#define DES4_RX_STAT_PTP_MT_ANNOUNCE        0x00000800
#define DES4_RX_STAT_PTP_MT_SIGNALLING      0x00000A00
#define DES4_RX_STAT_PTP_MT_RESERVED        0x00000F00
#define DES4_RX_STAT_IPV6                   0x00000080
#define DES4_RX_STAT_IPV4                   0x00000040
#define DES4_RX_STAT_IP_CHK_BYPASSED        0x00000020
#define DES4_RX_STAT_IP_PAYLOAD_ERR         0x00000010
#define DES4_RX_STAT_IP_HEADER_ERR          0x00000008
#define DES4_RX_STAT_PAYLOAD_M              0x00000007
#define DES4_RX_STAT_PAYLOAD_UNKNOWN        0x00000000
#define DES4_RX_STAT_PAYLOAD_UDP            0x00000001
#define DES4_RX_STAT_PAYLOAD_TCP            0x00000002
#define DES4_RX_STAT_PAYLOAD_ICMP           0x00000003

//*****************************************************************************
//
// Values used in the ui32BusConfig parameter to EMACInit().
//
//***************************************************************************
#define EMAC_BCONFIG_DMA_PRIO_WEIGHT_M      0x30000000
#define EMAC_BCONFIG_DMA_PRIO_WEIGHT_1      0x00000000
#define EMAC_BCONFIG_DMA_PRIO_WEIGHT_2      0x10000000
#define EMAC_BCONFIG_DMA_PRIO_WEIGHT_3      0x20000000
#define EMAC_BCONFIG_DMA_PRIO_WEIGHT_4      0x30000000
#define EMAC_BCONFIG_TX_PRIORITY            0x08000000
#define EMAC_BCONFIG_ADDR_ALIGNED           0x02000000
#define EMAC_BCONFIG_PRIORITY_M             0x0000C000
#define EMAC_BCONFIG_PRIORITY_1_1           (0 << 14)
#define EMAC_BCONFIG_PRIORITY_2_1           (1 << 14)
#define EMAC_BCONFIG_PRIORITY_3_1           (2 << 14)
#define EMAC_BCONFIG_PRIORITY_4_1           (3 << 14)
#define EMAC_BCONFIG_PRIORITY_FIXED         0x00000002
#define EMAC_BCONFIG_FIXED_BURST            0x00010000
#define EMAC_BCONFIG_MIXED_BURST            0x04000000

//*****************************************************************************
//
// Options used in the ui32Config parameter to EMACPHYConfigSet().
//
//*****************************************************************************
#define EMAC_PHY_TYPE_INTERNAL              0x00000000
#define EMAC_PHY_TYPE_EXTERNAL_MII          0x80000000
#define EMAC_PHY_TYPE_EXTERNAL_RMII         0xC0000000
#define EMAC_PHY_INT_NIB_TXERR_DET_DIS      0x01000000
#define EMAC_PHY_INT_RX_ER_DURING_IDLE      0x00800000
#define EMAC_PHY_INT_ISOLATE_MII_LLOSS      0x00400000
#define EMAC_PHY_INT_LINK_LOSS_RECOVERY     0x00200000
#define EMAC_PHY_INT_TDRRUN                 0x00100000
#define EMAC_PHY_INT_LD_ON_RX_ERR_COUNT     0x00040000
#define EMAC_PHY_INT_LD_ON_MTL3_ERR_COUNT   0x00020000
#define EMAC_PHY_INT_LD_ON_LOW_SNR          0x00010000
#define EMAC_PHY_INT_LD_ON_SIGNAL_ENERGY    0x00008000
#define EMAC_PHY_INT_POLARITY_SWAP          0x00004000
#define EMAC_PHY_INT_MDI_SWAP               0x00002000
#define EMAC_PHY_INT_ROBUST_MDIX            0x00001000
#define EMAC_PHY_INT_FAST_MDIX              0x00000800
#define EMAC_PHY_INT_MDIX_EN                0x00000400
#define EMAC_PHY_INT_FAST_RXDV_DETECT       0x00000200
#define EMAC_PHY_INT_FAST_L_UP_DETECT       0x00000100
#define EMAC_PHY_INT_EXT_FULL_DUPLEX        0x00000080
#define EMAC_PHY_INT_FAST_AN_80_50_35       0x00000040
#define EMAC_PHY_INT_FAST_AN_120_75_50      0x00000050
#define EMAC_PHY_INT_FAST_AN_140_150_100    0x00000060
#define EMAC_PHY_FORCE_10B_T_HALF_DUPLEX    0x00000000
#define EMAC_PHY_FORCE_10B_T_FULL_DUPLEX    0x00000002
#define EMAC_PHY_FORCE_100B_T_HALF_DUPLEX   0x00000004
#define EMAC_PHY_FORCE_100B_T_FULL_DUPLEX   0x00000006
#define EMAC_PHY_AN_10B_T_HALF_DUPLEX       0x00000008
#define EMAC_PHY_AN_10B_T_FULL_DUPLEX       0x0000000A
#define EMAC_PHY_AN_100B_T_HALF_DUPLEX      0x0000000C
#define EMAC_PHY_AN_100B_T_FULL_DUPLEX      0x0000000E
#define EMAC_PHY_INT_HOLD                   0x00000001

#define EMAC_PHY_TYPE_MASK                  0xC0000000

//*****************************************************************************
//
// Options used in the ui32Config parameter to EMACConfigSet().
//
//*****************************************************************************
#define EMAC_CONFIG_USE_MACADDR1          0x40000000
#define EMAC_CONFIG_USE_MACADDR0          0x00000000
#define EMAC_CONFIG_SA_FROM_DESCRIPTOR    0x00000000
#define EMAC_CONFIG_SA_INSERT             0x20000000
#define EMAC_CONFIG_SA_REPLACE            0x30000000
#define EMAC_CONFIG_2K_PACKETS            0x08000000
#define EMAC_CONFIG_STRIP_CRC             0x02000000
#define EMAC_CONFIG_JABBER_DISABLE        0x00400000
#define EMAC_CONFIG_JUMBO_ENABLE          0x00100000
#define EMAC_CONFIG_IF_GAP_MASK           0x000E0000
#define EMAC_CONFIG_IF_GAP_96BITS         (0x0 << 17)
#define EMAC_CONFIG_IF_GAP_88BITS         (0x1 << 17)
#define EMAC_CONFIG_IF_GAP_80BITS         (0x2 << 17)
#define EMAC_CONFIG_IF_GAP_72BITS         (0x3 << 17)
#define EMAC_CONFIG_IF_GAP_64BITS         (0x4 << 17)
#define EMAC_CONFIG_IF_GAP_56BITS         (0x5 << 17)
#define EMAC_CONFIG_IF_GAP_48BITS         (0x6 << 17)
#define EMAC_CONFIG_IF_GAP_40BITS         (0x7 << 17)
#define EMAC_CONFIG_CS_DISABLE            0x00010000
#define EMAC_CONFIG_100MBPS               0x00004000
#define EMAC_CONFIG_10MBPS                0x00000000
#define EMAC_CONFIG_RX_OWN_DISABLE        0x00002000
#define EMAC_CONFIG_LOOPBACK              0x00001000
#define EMAC_CONFIG_FULL_DUPLEX           0x00000800
#define EMAC_CONFIG_HALF_DUPLEX           0x00000000
#define EMAC_CONFIG_CHECKSUM_OFFLOAD      0x00000400
#define EMAC_CONFIG_RETRY_DISABLE         0x00000200
#define EMAC_CONFIG_AUTO_CRC_STRIPPING    0x00000080
#define EMAC_CONFIG_BO_MASK               0x00000060
#define EMAC_CONFIG_BO_LIMIT_1024         (0x0 << 5)
#define EMAC_CONFIG_BO_LIMIT_256          (0x1 << 5)
#define EMAC_CONFIG_BO_LIMIT_16           (0x2 << 5)
#define EMAC_CONFIG_BO_LIMIT_2            (0x3 << 5)
#define EMAC_CONFIG_DEFERRAL_CHK_ENABLE   0x00000010
#define EMAC_CONFIG_PREAMBLE_MASK         0x00000003
#define EMAC_CONFIG_7BYTE_PREAMBLE        0x00000000
#define EMAC_CONFIG_5BYTE_PREAMBLE        0x00000001
#define EMAC_CONFIG_3BYTE_PREAMBLE        0x00000002

//*****************************************************************************
//
// Options used in the ui32ModeFlags parameter to EMACConfigSet().
//
//*****************************************************************************
#define EMAC_MODE_KEEP_BAD_CRC            0x04000000
#define EMAC_MODE_RX_STORE_FORWARD        0x02000000
#define EMAC_MODE_RX_FLUSH_DISABLE        0x01000000
#define EMAC_MODE_TX_STORE_FORWARD        0x00200000
#define EMAC_MODE_TX_THRESHOLD_16_BYTES   (7 << 14)
#define EMAC_MODE_TX_THRESHOLD_24_BYTES   (6 << 14)
#define EMAC_MODE_TX_THRESHOLD_32_BYTES   (5 << 14)
#define EMAC_MODE_TX_THRESHOLD_40_BYTES   (4 << 14)
#define EMAC_MODE_TX_THRESHOLD_64_BYTES   (0 << 14)
#define EMAC_MODE_TX_THRESHOLD_128_BYTES  (1 << 14)
#define EMAC_MODE_TX_THRESHOLD_192_BYTES  (2 << 14)
#define EMAC_MODE_TX_THRESHOLD_256_BYTES  (3 << 14)
#define EMAC_MODE_RX_ERROR_FRAMES         0x00000080
#define EMAC_MODE_RX_UNDERSIZED_FRAMES    0x00000040
#define EMAC_MODE_RX_THRESHOLD_64_BYTES   (0 << 3)
#define EMAC_MODE_RX_THRESHOLD_32_BYTES   (1 << 3)
#define EMAC_MODE_RX_THRESHOLD_96_BYTES   (2 << 3)
#define EMAC_MODE_RX_THRESHOLD_128_BYTES  (3 << 3)
#define EMAC_MODE_OPERATE_2ND_FRAME       0x00000002

//*****************************************************************************
//
// These two values may be returned by EMACConfigGet() in the *pui32Config
// parameter.  The transmitter and receiver are, however, enabled and disabled
// using independent functions, EMACTxEnable/Disable() and
// EMACRxEnable/Disable().
//
//*****************************************************************************
#define EMAC_CONFIG_TX_ENABLED            0x00000008
#define EMAC_CONFIG_RX_ENABLED            0x00000004

//*****************************************************************************
//
// These two values may be returned by EMACConfigGet() in the *pui32Mode
// parameter. The transmit and receive DMA channels are, however, enabled and
// disabled using independent functions, EMACTxEnable/Disable() and
// EMACRxEnable/Disable().
//
//*****************************************************************************
#define EMAC_MODE_TX_DMA_ENABLED          0x00002000
#define EMAC_MODE_RX_DMA_ENABLED          0x00000002

//*****************************************************************************
//
// These values may be passed to EMACFrameFilterSet() in the ui32FilterOpts
// parameter, and are returned by EMACFrameFilterGet().
//
//*****************************************************************************
#define EMAC_FRMFILTER_RX_ALL             0x80000000
#define EMAC_FRMFILTER_VLAN               0x00010000
#define EMAC_FRMFILTER_HASH_AND_PERFECT   0x00000400
#define EMAC_FRMFILTER_SADDR              0x00000200
#define EMAC_FRMFILTER_INV_SADDR          0x00000100
#define EMAC_FRMFILTER_PASS_MASK          (0x03 << 6)
#define EMAC_FRMFILTER_PASS_NO_CTRL       (0x00 << 6)
#define EMAC_FRMFILTER_PASS_NO_PAUSE      (0x01 << 6)
#define EMAC_FRMFILTER_PASS_ALL_CTRL      (0x02 << 6)
#define EMAC_FRMFILTER_PASS_ADDR_CTRL     (0x03 << 6)
#define EMAC_FRMFILTER_BROADCAST          0x00000020
#define EMAC_FRMFILTER_PASS_MULTICAST     0x00000010
#define EMAC_FRMFILTER_INV_DADDR          0x00000008
#define EMAC_FRMFILTER_HASH_MULTICAST     0x00000004
#define EMAC_FRMFILTER_HASH_UNICAST       0x00000002
#define EMAC_FRMFILTER_PROMISCUOUS        0x00000001

//*****************************************************************************
//
// Values which may be returned by EMACStatusGet().
//
//*****************************************************************************
#define EMAC_STATUS_TX_NOT_EMPTY          0x01000000
#define EMAC_STATUS_TX_WRITING_FIFO       0x00400000
#define EMAC_STATUS_TRC_STATE_MASK        0x00300000
#define EMAC_STATUS_TRC_STATE_IDLE        (0x00 << 20)
#define EMAC_STATUS_TRC_STATE_READING     (0x01 << 20)
#define EMAC_STATUS_TRC_STATE_WAITING     (0x02 << 20)
#define EMAC_STATUS_TRC_STATE_STATUS      (0x03 << 20)
#define EMAC_STATUS_TX_PAUSED             0x00080000
#define EMAC_STATUS_TFC_STATE_MASK        0x00060000
#define EMAC_STATUS_TFC_STATE_IDLE        (0x00 << 17)
#define EMAC_STATUS_TFC_STATE_WAITING     (0x01 << 17)
#define EMAC_STATUS_TFC_STATE_PAUSING     (0x02 << 17)
#define EMAC_STATUS_TFC_STATE_WRITING     (0x03 << 17)
#define EMAC_STATUS_MAC_NOT_IDLE          0x00010000
#define EMAC_STATUS_RX_FIFO_LEVEL_MASK    0x00000300
#define EMAC_STATUS_RX_FIFO_EMPTY         (0x00 << 8)
#define EMAC_STATUS_RX_FIFO_BELOW         (0x01 << 8)
#define EMAC_STATUS_RX_FIFO_ABOVE         (0x02 << 8)
#define EMAC_STATUS_RX_FIFO_FULL          (0x03 << 8)
#define EMAC_STATUS_RX_FIFO_STATE_MASK    0x00000060
#define EMAC_STATUS_RX_FIFO_IDLE          (0x00 << 5)
#define EMAC_STATUS_RX_FIFO_READING       (0x01 << 5)
#define EMAC_STATUS_RX_FIFO_STATUS        (0x02 << 5)
#define EMAC_STATUS_RX_FIFO_FLUSHING      (0x03 << 5)
#define EMAC_STATUS_RWC_ACTIVE            0x00000010
#define EMAC_STATUS_RPE_ACTIVE            0x00000001

//*****************************************************************************
//
// Values which may be returned by EMACDMAStateGet().
//
//*****************************************************************************
#define EMAC_DMA_TXSTAT_MASK              (0x07 << 20)
#define EMAC_DMA_TXSTAT_STOPPED           (0x00 << 20)
#define EMAC_DMA_TXSTAT_RUN_FETCH_DESC    (0x01 << 20)
#define EMAC_DMA_TXSTAT_RUN_WAIT_STATUS   (0x02 << 20)
#define EMAC_DMA_TXSTAT_RUN_READING       (0x03 << 20)
#define EMAC_DMA_TXSTAT_RUN_CLOSE_DESC    (0x07 << 20)
#define EMAC_DMA_TXSTAT_TS_WRITE          (0x04 << 20)
#define EMAC_DMA_TXSTAT_SUSPENDED         (0x06 << 20)

#define EMAC_DMA_RXSTAT_MASK              (0x07 << 17)
#define EMAC_DMA_RXSTAT_STOPPED           (0x00 << 17)
#define EMAC_DMA_RXSTAT_RUN_FETCH_DESC    (0x01 << 17)
#define EMAC_DMA_RXSTAT_RUN_WAIT_PACKET   (0x03 << 17)
#define EMAC_DMA_RXSTAT_SUSPENDED         (0x04 << 17)
#define EMAC_DMA_RXSTAT_RUN_CLOSE_DESC    (0x05 << 17)
#define EMAC_DMA_RXSTAT_TS_WRITE          (0x06 << 17)
#define EMAC_DMA_RXSTAT_RUN_RECEIVING     (0x07 << 17)

#define EMAC_TX_DMA_STATE(x) ((x) & EMAC_DMA_TXSTAT_MASK)
#define EMAC_RX_DMA_STATE(x) ((x) & EMAC_DMA_RXSTAT_MASK)

#define EMAC_DMA_ERROR                    0x00002000
#define EMAC_DMA_ERR_MASK                 0x03800000
#define EMAC_DMA_ERR_RX_DATA_WRITE        0x00000000
#define EMAC_DMA_ERR_TX_DATA_READ         0x01800000
#define EMAC_DMA_ERR_RX_DESC_WRITE        0x02000000
#define EMAC_DMA_ERR_TX_DESC_WRITE        0x02800000
#define EMAC_DMA_ERR_RX_DESC_READ         0x03000000
#define EMAC_DMA_ERR_TX_DESC_READ         0x03800000

//*****************************************************************************
//
// Values which may be ORed together in the ui32Config parameter passed to
// EMACAddrFilterSet and which may be returned by EMACAddrFilterGet.
//
//*****************************************************************************
#define EMAC_FILTER_ADDR_ENABLE           0x80000000
#define EMAC_FILTER_SOURCE_ADDR           0x40000000
#define EMAC_FILTER_MASK_BYTE_6           0x20000000
#define EMAC_FILTER_MASK_BYTE_5           0x10000000
#define EMAC_FILTER_MASK_BYTE_4           0x08000000
#define EMAC_FILTER_MASK_BYTE_3           0x04000000
#define EMAC_FILTER_MASK_BYTE_2           0x03000000
#define EMAC_FILTER_MASK_BYTE_1           0x01000000

#define EMAC_FILTER_BYTE_MASK_M           0x3F000000
#define EMAC_FILTER_BYTE_MASK_S           24

//*****************************************************************************
//
// Flags passed to EMACTimestampConfigSet or returned from
// EMACTimestampConfigGet.
//
//*****************************************************************************
#define EMAC_TS_MAC_FILTER_ENABLE         0x00040000
#define EMAC_TS_MAC_FILTER_DISABLE        0x00000000
#define EMAC_TS_SYNC_FOLLOW_DREQ_DRESP    0x00000000
#define EMAC_TS_SYNC_ONLY                 0x00004000
#define EMAC_TS_DELAYREQ_ONLY             0x0000C000
#define EMAC_TS_ALL                       0x00010000
#define EMAC_TS_SYNC_PDREQ_PDRESP         0x00014000
#define EMAC_TS_DREQ_PDREQ_PDRESP         0x0001C000
#define EMAC_TS_SYNC_DELAYREQ             0x00020000
#define EMAC_TS_PDREQ_PDRESP              0x00030000
#define EMAC_TS_PROCESS_IPV4_UDP          0x00002000
#define EMAC_TS_PROCESS_IPV6_UDP          0x00001000
#define EMAC_TS_PROCESS_ETHERNET          0x00000800
#define EMAC_TS_PTP_VERSION_2             0x00000400
#define EMAC_TS_PTP_VERSION_1             0x00000000
#define EMAC_TS_DIGITAL_ROLLOVER          0x00000200
#define EMAC_TS_BINARY_ROLLOVER           0x00000000
#define EMAC_TS_ALL_RX_FRAMES             0x00000100
#define EMAC_TS_UPDATE_FINE               0x00000002
#define EMAC_TS_UPDATE_COARSE             0x00000000

//*****************************************************************************
//
// Some register bit definitions relating to external PHYs.  These are not
// relevant (or available) when using the internal Ethernet PHY but having
// the definitions here helps when using an external MII or RMII PHY.
//
//*****************************************************************************
#define EPHY_SCR_INPOL_EXT                0x00000008
#define EPHY_SCR_TINT_EXT                 0x00000004
#define EPHY_SCR_INTEN_EXT                0x00000002
#define EPHY_SCR_INTOE_EXT                0x00000001

//*****************************************************************************
//
// These interrupt sources may be passed to EMACIntEnable() and
// EMACIntDisable() to enable or disable various Ethernet interrupt sources.
//
//*****************************************************************************
//
// Note that interrupts relating to timestamping and power management must be
// independently enabled via calls to functions EMACTimestampTargetIntEnable
// and EMACPowerManagementControlSet.
//
// EMAC_INT_PHY is deliberately set to a reserved bit in the MAC interrupt
// register.  We handle the fact that the PHY interrupt is controlled via an
// independent register within the code.  If we didn't do this, the app would
// have to enable the MAC interrupt then enable the PHY interrupt via a
// different API (since they share a vector).  To further complicate matters,
// they would have to call EMACIntStatus() and then, if it returned 0,
// read the PHY interrupt status to see that it fired.  This would be nasty
// and unfriendly so we hide it inside DriverLib.
//
//*****************************************************************************
#define EMAC_INT_PHY                      0x80000000
#define EMAC_INT_EARLY_RECEIVE            0x00004000
#define EMAC_INT_BUS_ERROR                0x00002000
#define EMAC_INT_EARLY_TRANSMIT           0x00000400
#define EMAC_INT_RX_WATCHDOG              0x00000200
#define EMAC_INT_RX_STOPPED               0x00000100
#define EMAC_INT_RX_NO_BUFFER             0x00000080
#define EMAC_INT_RECEIVE                  0x00000040
#define EMAC_INT_TX_UNDERFLOW             0x00000020
#define EMAC_INT_RX_OVERFLOW              0x00000010
#define EMAC_INT_TX_JABBER                0x00000008
#define EMAC_INT_TX_NO_BUFFER             0x00000004
#define EMAC_INT_TX_STOPPED               0x00000002
#define EMAC_INT_TRANSMIT                 0x00000001

//
// These interrupt sources are summary indicators.  They are readable
// using EMACIntStatus() and must be cleared using EMACIntClear().  They
// may be enabled or disabled independently of the group of interrupts that
// they are derived from but offer merely a simple way to be informed of a
// normal or abnormal condition requiring software attention.
//
// EMAC_INT_NORMAL_INT is the logical OR of the masked state of
// EMAC_INT_TRANSMIT | EMAC_INT_RECEIVE | EMAC_INT_TX_NO_BUFFER |
// EMAC_INT_EARLY_RECEIVE.
//
// EMAC_INT_ABNORMAL_INT is the logical OR of the masked state of
// EMAC_INT_TX_STOPPED | EMAC_INT_TX_JABBER | EMAC_INT_RX_OVERFLOW |
// EMAC_INT_TX_UNDERFLOW | EMAC_INT_RX_NO_BUFFER | EMAC_INT_RX_STOPPED |
// EMAC_INT_RX_WATCHDOG | EMAC_INT_EARLY_TRANSMIT | EMAC_INT_BUS_ERROR.
//
#define EMAC_INT_NORMAL_INT               0x00010000
#define EMAC_INT_ABNORMAL_INT             0x00008000

//
// This interrupt source is readable using EMACIntStatus but must
// be cleared by calling the EMACTimestampIntStatus().
//
#define EMAC_INT_TIMESTAMP                0x20000000

//
// Interrupt sources which may be returned from EMACTimestampIntStatus().
//
#define EMAC_TS_INT_TARGET_REACHED        0x00000002
#define EMAC_TS_INT_TS_SEC_OVERFLOW       0x00000001

//
// This interrupt source is readable using EMACIntStatus but must
// be cleared by calling EMACPowerManagementStatusGet().
//
#define EMAC_INT_POWER_MGMNT              0x10000000

//*****************************************************************************
//
// Configuration flags that may be passed in the ui32FreqConfig parameter to
// EMACTimestampPPSSimpleModeSet().
//
//*****************************************************************************
#define EMAC_PPS_SINGLE_PULSE             0x00000000
#define EMAC_PPS_1HZ                      0x00000001
#define EMAC_PPS_2HZ                      0x00000002
#define EMAC_PPS_4HZ                      0x00000003
#define EMAC_PPS_8HZ                      0x00000004
#define EMAC_PPS_16HZ                     0x00000005
#define EMAC_PPS_32HZ                     0x00000006
#define EMAC_PPS_64HZ                     0x00000007
#define EMAC_PPS_128HZ                    0x00000008
#define EMAC_PPS_256HZ                    0x00000009
#define EMAC_PPS_512HZ                    0x0000000A
#define EMAC_PPS_1024HZ                   0x0000000B
#define EMAC_PPS_2048HZ                   0x0000000C
#define EMAC_PPS_4096HZ                   0x0000000D
#define EMAC_PPS_8192HZ                   0x0000000E
#define EMAC_PPS_16384HZ                  0x0000000F
#define EMAC_PPS_32768HZ                  0x00000010

//*****************************************************************************
//
// Configuration flags that may be passed in the ui32Config parameter to
// EMACTimestampPPSCommandModeSet().
//
//*****************************************************************************
#define EMAC_PPS_TARGET_INT               0x00000000
#define EMAC_PPS_TARGET_PPS               0x00000060
#define EMAC_PPS_TARGET_BOTH              0x00000040

//*****************************************************************************
//
// Commands which may be passed to EMACTimestampPPSCmd.
//
//*****************************************************************************
#define EMAC_PPS_COMMAND_NONE             0x00
#define EMAC_PPS_COMMAND_START_SINGLE     0x01
#define EMAC_PPS_COMMAND_START_TRAIN      0x02
#define EMAC_PPS_COMMAND_CANCEL_START     0x03
#define EMAC_PPS_COMMAND_STOP_AT_TIME     0x04
#define EMAC_PPS_COMMAND_STOP_NOW         0x05
#define EMAC_PPS_COMMAND_CANCEL_STOP      0x06

//*****************************************************************************
//
// Values which may be passed to EMACVLANRxConfigSet in the ui32Config
// parameter and which may be returned from EMACVLANRxConfigGet.
//
//*****************************************************************************
#define EMAC_VLAN_RX_HASH_ENABLE          0x00080000
#define EMAC_VLAN_RX_HASH_DISABLE         0x00000000
#define EMAC_VLAN_RX_SVLAN_ENABLE         0x00040000
#define EMAC_VLAN_RX_SVLAN_DISABLE        0x00000000
#define EMAC_VLAN_RX_NORMAL_MATCH         0x00000000
#define EMAC_VLAN_RX_INVERSE_MATCH        0x00020000
#define EMAC_VLAN_RX_12BIT_TAG            0x00010000
#define EMAC_VLAN_RX_16BIT_TAG            0x00000000

//*****************************************************************************
//
// Values which may be passed to EMACVLANTxConfigSet in the ui32Config
// parameter and which may be returned from EMACVLANTxConfigGet.
//
//*****************************************************************************
#define EMAC_VLAN_TX_CVLAN                0x00000000
#define EMAC_VLAN_TX_SVLAN                0x00080000
#define EMAC_VLAN_TX_USE_VLC              0x00040000
#define EMAC_VLAN_TX_VLC_NONE             0x00000000
#define EMAC_VLAN_TX_VLC_DELETE           0x00010000
#define EMAC_VLAN_TX_VLC_INSERT           0x00020000
#define EMAC_VLAN_TX_VLC_REPLACE          0x00030000

#define EMAC_VLAN_TX_VLC_MASK             0x00030000

#define EMAC_RWU_FILTER_ENABLE            1
#define EMAC_RWU_FILTER_DISABLE           0
#define EMAC_RWU_FILTER_MULTICAST         8
#define EMAC_RWU_FILTER_UNICAST           0

//*****************************************************************************
//
// The following structure fields must be packed.
//
//*****************************************************************************
#ifdef ewarm
#pragma pack(1)
#endif

//*****************************************************************************
//
//! This structure defines up to 4 filters that can be used to define specific
//! frames which will cause the MAC to wake up from sleep mode.
//
//*****************************************************************************
typedef struct
{
    //
    //! A byte mask for each filter defining which bytes from a sequence of
    //! 31 (bit 31 must be clear in each mask) are used to filter incoming
    //! packets. A 1 indicates that the relevant byte is used to update the
    //! CRC16 for the filter, a 0 indicates that the byte is ignored.
    //
    uint32_t pui32ByteMask[4];

    //
    //! Defines whether each filter is enabled and, if so, whether it filters
    //! multicast or unicast frames.  Valid values are one of
    //! EMAC_RWU_FILTER_ENABLE or EMAC_RWU_FILTER_DISABLE ORed with one of
    //! EMAC_RWU_FILTER_UNICAST or EMAC_RWU_FILTER_MULTICAST.
    //
    uint8_t pui8Command[4];

    //
    //! Determines the byte offset within the frame at which the filter starts
    //! examining bytes.  The minimum value for each offset is 12.  The first
    //! byte of a frame is offset 0.
    //
    uint8_t pui8Offset[4];

    //
    //! The CRC16 value that is expected for each filter if it passes.  The
    //! CRC is calculated using all bytes indicated by the filter's mask.
    //
    uint16_t pui16CRC[4];
}
#if defined(ccs) ||             \
    defined(codered) ||         \
    defined(gcc) ||             \
    defined(rvmdk) ||           \
    defined(__ARMCC_VERSION) || \
    defined(sourcerygxx)
__attribute__ ((packed)) tEMACWakeUpFrameFilter;
#else
tEMACWakeUpFrameFilter;
#endif

//*****************************************************************************
//
// Turn off structure packing again.
//
//*****************************************************************************
#ifdef ewarm
#pragma pack()
#endif

//*****************************************************************************
//
// Values which may be ORed together and used in the ui32Flags parameter to
// EMACPowerManagementControlSet.  These may also returned be from a call to
// EMACPowerManagementControlGet.
//
//*****************************************************************************
#define EMAC_PMT_GLOBAL_UNICAST_ENABLE    0x00000200
#define EMAC_PMT_WAKEUP_PACKET_ENABLE     0x00000004
#define EMAC_PMT_MAGIC_PACKET_ENABLE      0x00000002
#define EMAC_PMT_POWER_DOWN               0x00000001

//*****************************************************************************
//
// Values which may be ORed together and returned from a call to
// EMACPowerManagementStatusGet.  This call will also return
// EMAC_PMT_POWER_DOWN if the MAC is in power-down mode.
//
//*****************************************************************************
#define EMAC_PMT_WAKEUP_PACKET_RECEIVED   0x00000040
#define EMAC_PMT_MAGIC_PACKET_RECEIVED    0x00000020

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
// Public function prototypes.
//
//*****************************************************************************
extern void EMACInit(uint32_t ui32Base, uint32_t ui32SysClk,
                     uint32_t ui32BusConfig, uint32_t ui32RxBurst,
                     uint32_t ui32TxBurst, uint32_t ui32DescSkipSize);
extern void EMACReset(uint32_t ui32Base);
extern void EMACPHYConfigSet(uint32_t ui32Base, uint32_t ui32Config);
extern void EMACConfigSet(uint32_t ui32Base, uint32_t ui32Config,
                          uint32_t ui32ModeFlags,
                          uint32_t ui32RxMaxFrameSize);
extern void EMACFrameFilterSet(uint32_t ui32Base, uint32_t ui32FilterOpts);
extern uint32_t EMACFrameFilterGet(uint32_t ui32Base);
extern void EMACHashFilterSet(uint32_t ui32Base, uint32_t ui32HashHi,
                              uint32_t ui32HashLo);
extern void EMACHashFilterGet(uint32_t ui32Base, uint32_t *pui32HashHi,
                              uint32_t *pui32HashLo);
extern uint32_t EMACHashFilterBitCalculate(uint8_t *pui8MACAddr);
extern void EMACTxDMAPollDemand(uint32_t ui32Base);
extern void EMACRxDMAPollDemand(uint32_t ui32Base);
extern void EMACRxDMADescriptorListSet(uint32_t ui32Base,
                                       tEMACDMADescriptor *pDescriptor);
extern tEMACDMADescriptor *EMACRxDMADescriptorListGet(uint32_t ui32Base);
extern tEMACDMADescriptor *EMACRxDMACurrentDescriptorGet(uint32_t ui32Base);
extern uint8_t *EMACRxDMACurrentBufferGet(uint32_t ui32Base);
extern void EMACTxDMADescriptorListSet(uint32_t ui32Base,
                                       tEMACDMADescriptor *pDescriptor);
extern tEMACDMADescriptor *EMACTxDMADescriptorListGet(uint32_t ui32Base);
extern tEMACDMADescriptor *EMACTxDMACurrentDescriptorGet(uint32_t ui32Base);
extern uint8_t *EMACTxDMACurrentBufferGet(uint32_t ui32Base);
extern void EMACConfigGet(uint32_t ui32Base, uint32_t *pui32Config,
                          uint32_t *pui32Mode, uint32_t *pui32RxMaxFrameSize);
extern void EMACAddrSet(uint32_t ui32Base, uint32_t ui32Index,
                        const uint8_t *pui8MACAddr);
extern void EMACAddrGet(uint32_t ui32Base, uint32_t ui32Index,
                        uint8_t *pui8MACAddr);
extern uint32_t EMACNumAddrGet(uint32_t ui32Base);
extern void EMACAddrFilterSet(uint32_t ui32Base, uint32_t ui32Index,
                              uint32_t ui32Config);
extern uint32_t EMACAddrFilterGet(uint32_t ui32Base, uint32_t ui32Index);
extern void EMACRxWatchdogTimerSet(uint32_t ui32Base, uint8_t ui8Timeout);
extern uint32_t EMACStatusGet(uint32_t ui32Base);
extern uint32_t EMACDMAStateGet(uint32_t ui32Base);
extern void EMACTxFlush(uint32_t ui32Base);
extern void EMACTxEnable(uint32_t ui32Base);
extern void EMACTxDisable(uint32_t ui32Base);
extern void EMACRxEnable(uint32_t ui32Base);
extern void EMACRxDisable(uint32_t ui32Base);
extern void EMACIntEnable(uint32_t ui32Base, uint32_t ui32IntFlags);
extern void EMACIntDisable(uint32_t ui32Base, uint32_t ui32IntFlags);
extern uint32_t EMACIntStatus(uint32_t ui32Base, bool bMasked);
extern void EMACIntClear(uint32_t ui32Base, uint32_t ui32IntFlags);
extern void EMACIntRegister(uint32_t ui32Base, void (*pfnHandler)(void));
extern void EMACIntUnregister(uint32_t ui32Base);
extern void EMACPHYWrite(uint32_t ui32Base, uint8_t ui8PhyAddr,
                         uint8_t ui8RegAddr, uint16_t ui16Data);
extern void EMACPHYExtendedWrite(uint32_t ui32Base, uint8_t ui8PhyAddr,
                                  uint16_t ui16RegAddr, uint16_t ui16Data);
extern uint16_t EMACPHYRead(uint32_t ui32Base,  uint8_t ui8PhyAddr,
                            uint8_t ui8RegAddr);
extern uint16_t EMACPHYExtendedRead(uint32_t ui32Base, uint8_t ui8PhyAddr,
                                    uint16_t ui16RegAddr);
extern void EMACPHYPowerOff(uint32_t ui32Base, uint8_t ui8PhyAddr);
extern void EMACPHYPowerOn(uint32_t ui32Base, uint8_t ui8PhyAddr);
extern void EMACTimestampConfigSet(uint32_t ui32Base, uint32_t ui32Config,
                                   uint32_t ui32SubSecondInc);
extern uint32_t EMACTimestampConfigGet(uint32_t ui32Base,
                                       uint32_t *pui32SubSecondInc);
extern void EMACTimestampAddendSet(uint32_t ui32Base, uint32_t ui32Seconds);
extern void EMACTimestampEnable(uint32_t ui32Base);
extern void EMACTimestampDisable(uint32_t ui32Base);
extern void EMACTimestampSysTimeSet(uint32_t ui32Base, uint32_t ui32Seconds,
                                    uint32_t ui32SubSeconds);
extern void EMACTimestampSysTimeGet(uint32_t ui32Base, uint32_t *pui32Seconds,
                                    uint32_t *pui32SubSeconds);
extern void EMACTimestampSysTimeUpdate(uint32_t ui32Base, uint32_t ui32Seconds,
                                         uint32_t ui32SubSeconds, bool bInc);
extern void EMACTimestampTargetSet(uint32_t ui32Base, uint32_t ui32Seconds,
                                   uint32_t ui32Nanoseconds);
extern void EMACTimestampTargetIntEnable(uint32_t ui32Base);
extern void EMACTimestampTargetIntDisable(uint32_t ui32Base);
extern uint32_t EMACTimestampIntStatus(uint32_t ui32Base);
extern void EMACTimestampPPSSimpleModeSet(uint32_t ui32Base,
                                          uint32_t ui32FreqConfig);
extern void EMACTimestampPPSCommandModeSet(uint32_t ui32Base,
                                           uint32_t ui32Config);
extern void EMACTimestampPPSCommand(uint32_t ui32Base, uint8_t ui8Cmd);
extern void EMACTimestampPPSPeriodSet(uint32_t ui32Base, uint32_t ui32Period,
                                      uint32_t ui32Width);
extern void EMACVLANRxConfigSet(uint32_t ui32Base, uint16_t ui16Tag,
                                uint32_t ui32Config);
extern uint32_t EMACVLANRxConfigGet(uint32_t ui32Base, uint16_t *pui16Tag);
extern void EMACVLANTxConfigSet(uint32_t ui32Base, uint16_t ui16Tag,
                                uint32_t ui32Config);
extern uint32_t EMACVLANTxConfigGet(uint32_t ui32Base, uint16_t *pui16Tag);
extern uint32_t EMACVLANHashFilterBitCalculate(uint16_t ui16Tag);
extern void EMACVLANHashFilterSet(uint32_t ui32Base, uint32_t ui32Hash);
extern uint32_t EMACVLANHashFilterGet(uint32_t ui32Base);
extern void EMACRemoteWakeUpFrameFilterSet(uint32_t ui32Base,
                                       const tEMACWakeUpFrameFilter *pFilter);
extern void EMACRemoteWakeUpFrameFilterGet(uint32_t ui32Base,
                                             tEMACWakeUpFrameFilter *pFilter);
extern void EMACPowerManagementControlSet(uint32_t ui32Base,
                                          uint32_t ui32Flags);
extern uint32_t EMACPowerManagementControlGet(uint32_t ui32Base);
extern uint32_t EMACPowerManagementStatusGet(uint32_t ui32Base);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif // __DRIVERLIB_EMAC_H__
