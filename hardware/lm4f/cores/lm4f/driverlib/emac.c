//*****************************************************************************
//
// emac.c - Driver for the Integrated Ethernet Controller on Snowflake-class
//          Tiva devices.
//
// Copyright (c) 2013 Texas Instruments Incorporated.  All rights reserved.
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

//*****************************************************************************
//
//! \addtogroup emac_api
//! @{
//
//*****************************************************************************

#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_emac.h"
#include "driverlib/debug.h"
#include "driverlib/emac.h"
#include "driverlib/sysctl.h"
#include "driverlib/interrupt.h"
#include "driverlib/sw_crc.h"

//*****************************************************************************
//
// Combined defines used in parameter validity checks.
//
//*****************************************************************************

//*****************************************************************************
//
// Combined valid configuration flags.
//
//*****************************************************************************
#define VALID_CONFIG_FLAGS      (EMAC_CONFIG_USE_MACADDR1 |                   \
                                 EMAC_CONFIG_SA_INSERT |                      \
                                 EMAC_CONFIG_SA_REPLACE |                     \
                                 EMAC_CONFIG_2K_PACKETS |                     \
                                 EMAC_CONFIG_STRIP_CRC |                      \
                                 EMAC_CONFIG_JABBER_DISABLE |                 \
                                 EMAC_CONFIG_JUMBO_ENABLE |                   \
                                 EMAC_CONFIG_IF_GAP_MASK |                    \
                                 EMAC_CONFIG_CS_DISABLE |                     \
                                 EMAC_CONFIG_100MBPS |                        \
                                 EMAC_CONFIG_RX_OWN_DISABLE |                 \
                                 EMAC_CONFIG_LOOPBACK |                       \
                                 EMAC_CONFIG_FULL_DUPLEX |                    \
                                 EMAC_CONFIG_CHECKSUM_OFFLOAD |               \
                                 EMAC_CONFIG_RETRY_DISABLE |                  \
                                 EMAC_CONFIG_AUTO_CRC_STRIPPING |             \
                                 EMAC_CONFIG_BO_MASK |                        \
                                 EMAC_CONFIG_DEFERRAL_CHK_ENABLE |            \
                                 EMAC_CONFIG_PREAMBLE_MASK)

//*****************************************************************************
//
// Combined valid frame filter flags.
//
//*****************************************************************************
#define VALID_FRMFILTER_FLAGS   (EMAC_FRMFILTER_RX_ALL |                      \
                                 EMAC_FRMFILTER_VLAN |                        \
                                 EMAC_FRMFILTER_HASH_AND_PERFECT |            \
                                 EMAC_FRMFILTER_SADDR |                       \
                                 EMAC_FRMFILTER_INV_SADDR |                   \
                                 EMAC_FRMFILTER_PASS_NO_PAUSE |               \
                                 EMAC_FRMFILTER_PASS_ALL_CTRL |               \
                                 EMAC_FRMFILTER_PASS_ADDR_CTRL |              \
                                 EMAC_FRMFILTER_BROADCAST |                   \
                                 EMAC_FRMFILTER_PASS_MULTICAST |              \
                                 EMAC_FRMFILTER_INV_DADDR |                   \
                                 EMAC_FRMFILTER_HASH_MULTICAST |              \
                                 EMAC_FRMFILTER_HASH_UNICAST |                \
                                 EMAC_FRMFILTER_PROMISCUOUS)

//*****************************************************************************
//
// Combined valid maskable interrupts.
//
//*****************************************************************************
#define EMAC_MASKABLE_INTS      (EMAC_INT_EARLY_RECEIVE |                     \
                                 EMAC_INT_BUS_ERROR |                         \
                                 EMAC_INT_EARLY_TRANSMIT |                    \
                                 EMAC_INT_RX_WATCHDOG |                       \
                                 EMAC_INT_RX_STOPPED |                        \
                                 EMAC_INT_RX_NO_BUFFER |                      \
                                 EMAC_INT_RECEIVE |                           \
                                 EMAC_INT_TX_UNDERFLOW |                      \
                                 EMAC_INT_RX_OVERFLOW |                       \
                                 EMAC_INT_TX_JABBER |                         \
                                 EMAC_INT_TX_NO_BUFFER |                      \
                                 EMAC_INT_TX_STOPPED |                        \
                                 EMAC_INT_TRANSMIT |                          \
                                 EMAC_INT_NORMAL_INT |                        \
                                 EMAC_INT_ABNORMAL_INT |                      \
                                 EMAC_INT_PHY)

//*****************************************************************************
//
// Combined valid normal interrupts.
//
//*****************************************************************************
#define EMAC_NORMAL_INTS        (EMAC_INT_TRANSMIT |                          \
                                 EMAC_INT_RECEIVE |                           \
                                 EMAC_INT_EARLY_RECEIVE |                     \
                                 EMAC_INT_TX_NO_BUFFER)

//*****************************************************************************
//
// Combined valid abnormal interrupts.
//
//*****************************************************************************
#define EMAC_ABNORMAL_INTS      (EMAC_INT_TX_STOPPED |                        \
                                 EMAC_INT_TX_JABBER |                         \
                                 EMAC_INT_RX_OVERFLOW |                       \
                                 EMAC_INT_TX_UNDERFLOW |                      \
                                 EMAC_INT_RX_NO_BUFFER |                      \
                                 EMAC_INT_RX_STOPPED |                        \
                                 EMAC_INT_RX_WATCHDOG |                       \
                                 EMAC_INT_EARLY_TRANSMIT |                    \
                                 EMAC_INT_BUS_ERROR)

//*****************************************************************************
//
// Interrupt sources reported via the DMARIS register but which are not
// masked (or enabled) via the DMAIM register.
//
//*****************************************************************************
#define EMAC_NON_MASKED_INTS    (EMAC_DMARIS_TT |                             \
                                 EMAC_DMARIS_PMT |                            \
                                 EMAC_DMARIS_MMC)

//*****************************************************************************
//
// The number of MAC addresses the module can store for filtering purposes.
//
//*****************************************************************************
#define NUM_MAC_ADDR            4

//*****************************************************************************
//
// Macros aiding access to the MAC address registers.
//
//*****************************************************************************
#define MAC_ADDR_OFFSET         (EMAC_O_ADDR1L - EMAC_O_ADDR0L)
#define EMAC_O_ADDRL(n)         (EMAC_O_ADDR0L + (MAC_ADDR_OFFSET * (n)))
#define EMAC_O_ADDRH(n)         (EMAC_O_ADDR0H + (MAC_ADDR_OFFSET * (n)))

//*****************************************************************************
//
// A structure used to help in choosing the correct clock divisor for the MII
// based on the current system clock rate.
//
//*****************************************************************************
static const struct
{
    uint32_t ui32SysClockMax;
    uint32_t ui32Divisor;
}
g_pi16MIIClockDiv[] =
{
    { 64000000, EMAC_MIIADDR_CR_35_60 },
    { 104000000, EMAC_MIIADDR_CR_60_100 },
    { 150000000, EMAC_MIIADDR_CR_100_150 }
};

//*****************************************************************************
//
// The number of clock divisors in the above table.
//
//*****************************************************************************
#define NUM_CLOCK_DIVISORS      (sizeof(g_pi16MIIClockDiv) /                  \
                                 sizeof(g_pi16MIIClockDiv[0]))

//*****************************************************************************
//
//! Initializes the Ethernet MAC and sets bus-related DMA parameters.
//!
//! \param ui32Base is the base address of the Ethernet controller.
//! \param ui32SysClk is the current system clock frequency in Hertz.
//! \param ui32BusConfig defines the bus operating mode for the Ethernet MAC
//! DMA controller.
//! \param ui32RxBurst is the maximum receive burst size in words.
//! \param ui32TxBurst is the maximum transmit burst size in words.
//! \param ui32DescSkipSize is the number of 32-bit words to skip between
//! two unchained DMA descriptors.  Values in the range 0 to 31 are valid.
//!
//! This function sets bus-related parameters for the Ethernet MAC DMA
//! engines.  It must be called after EMACPHYConfigSet() and called again
//! after any subsequent call to EMACPHYConfigSet().
//!
//! The \e ui32BusConfig parameter is the logical OR of various fields.  The
//! first sets the DMA channel priority weight:
//!
//! - \b EMAC_BCONFIG_DMA_PRIO_WEIGHT_1
//! - \b EMAC_BCONFIG_DMA_PRIO_WEIGHT_2
//! - \b EMAC_BCONFIG_DMA_PRIO_WEIGHT_3
//! - \b EMAC_BCONFIG_DMA_PRIO_WEIGHT_4
//!
//! The second field sets the receive and transmit priorities used when
//! arbitrating between the Rx and Tx DMA.  The priorities are Rx:Tx unless
//! \b EMAC_BCONFIG_TX_PRIORITY is also specified in which case they become
//! Tx:Rx.  The priority provided here is ignored if
//! \b EMAC_BCONFIG_PRIORITY_FIXED is specified.
//!
//! - \b EMAC_BCONFIG_PRIORITY_1_1
//! - \b EMAC_BCONFIG_PRIORITY_2_1
//! - \b EMAC_BCONFIG_PRIORITY_3_1
//! - \b EMAC_BCONFIG_PRIORITY_4_1
//!
//! The following additional flags may also be defined:
//!
//! - \b EMAC_BCONFIG_TX_PRIORITY indicates that the transmit DMA should be
//! higher priority in all arbitration for the system-side bus.  If this is not
//! defined, the receive DMA will have higher priority.
//! - \b EMAC_BCONFIG_ADDR_ALIGNED works in tandem with
//! \b EMAC_BCONFIG_FIXED_BURST to control address alignment of AHB bursts.
//! When both flags are specified, all bursts are aligned to the start address
//! least significant bits.  If \b EMAC_BCONFIG_FIXED_BURST is not specified,
//! the first burst will be unaligned but subsequent bursts are aligned to the
//! address.
//! - \b EMAC_BCONFIG_ALT_DESCRIPTORS indicates that the DMA engine should
//! use the alternate descriptor format as defined in type
//! \b tEMACDMADescriptor.  If absent, the basic descriptor type is used.
//! Alternate descriptors are required if using IEEE1588-2008 advanced
//! timestamping, VLAN or TCP/UDP/ICMP CRC insertion features.  Note that,
//! for clarity, emac.h does not contain type definitions for the basic
//! descriptor type.  Please see the part datasheet for information on basic
//! descriptor structures.
//! - \b EMAC_BCONFIG_PRIORITY_FIXED indicates that a fixed priority scheme
//! should be employed when arbitrating between the transmit and receive DMA
//! for system-side bus access.  In this case, the receive channel always has
//! priority unless \b EMAC_BCONFIG_TX_PRIORITY is set in which case the
//! transmit channel has priority.  If \b EMAC_BCONFIG_PRIORITY_FIXED is not
//! specified, a weighted round-robin arbitration scheme is used with the
//! weighting defined using \b EMAC_BCONFIG_PRIORITY_1_1,
//! \b EMAC_BCONFIG_PRIORITY_2_1, \b EMAC_BCONFIG_PRIORITY_3_1 or
//! \b EMAC_BCONFIG_PRIORITY_4_1, and \b EMAC_BCONFIG_TX_PRIORITY.
//! - \b EMAC_BCONFIG_FIXED_BURST indicates that fixed burst transfers should
//! be used.
//! - \b EMAC_BCONFIG_MIXED_BURST indicates that the DMA engine should use
//! mixed burst types depending upon the length of data to be transferred
//! across the system bus.
//!
//! The \e ui32RxBurst and \e ui32TxBurst parameters indicate the maximum
//! number of words that the relevant DMA should transfer in a single
//! transaction.  Valid values are 1, 2, 4, 8, 16 and 32.  Any other value
//! will result in undefined behavior.
//!
//! The \e ui32DescSkipSize parameter is used when the descriptor lists are
//! using ring mode (where descriptors are contiguous in memory with the last
//! descriptor marked with the \b END_OF_RING flag) rather than chained mode
//! (where each descriptor includes a field which points to the next descriptor
//! in the list).  In this case, the hardware uses the \e ui32DescSkipSize to
//! skip past any application-defined fields after the end the hardware-defined
//! descriptor fields.  The parameter value indicates the number of 32-bit
//! words to skip after the last field of the hardware-defined descriptor to
//! get to the first field of the next descriptor.  When using arrays of either
//! the \b tEMACDMADescriptor or \b tEMACAltDMADescriptor types defined for
//! this driver, \e ui32DescSkipSize must be set to 1 to skip the \e pvNext
//! pointer added to the end of each of these structures.  Applications may
//! modify these structure definitions to include their own
//! application-specific data and modify \e ui32DescSkipSize appropriately if
//! desired.
//!
//! \return None.
//
//*****************************************************************************
void
EMACInit(uint32_t ui32Base, uint32_t ui32SysClk, uint32_t ui32BusConfig,
         uint32_t ui32RxBurst, uint32_t ui32TxBurst, uint32_t ui32DescSkipSize)
{
    uint32_t ui32Val, ui32Div;

    //
    // Parameter sanity checks.
    //
    ASSERT(ui32DescSkipSize < 32);
    ASSERT(ui32TxBurst < (32 * 8));
    ASSERT(ui32RxBurst < (32 * 8));

    //
    // Make sure that the DMA software reset is clear before continuing.
    //
    while(HWREG(EMAC0_BASE + EMAC_O_DMABUSMOD) & EMAC_DMABUSMOD_SWR)
    {
    }

    //
    // Set common flags.  Note that this driver assumes we are always using
    // 8 word descriptors so we need to OR in EMAC_DMABUSMOD_ATDS here.
    //
    ui32Val = (ui32BusConfig | (ui32DescSkipSize << EMAC_DMABUSMOD_DSL_S) |
               EMAC_DMABUSMOD_ATDS);

    //
    // Do we need to use the 8X burst length multiplier?
    //
    if((ui32TxBurst > 32) || (ui32RxBurst > 32))
    {
        //
        // Divide both burst lengths by 8 and set the 8X burst length
        // multiplier.
        //
        ui32Val |= EMAC_DMABUSMOD_8XPBL;
        ui32TxBurst >>= 3;
        ui32RxBurst >>= 3;

        //
        // Sanity check - neither burst length should have become zero.  If
        // they did, this indicates that the values passed are invalid.
        //
        ASSERT(ui32RxBurst);
        ASSERT(ui32TxBurst);
    }

    //
    // Are the receive and transmit burst lengths the same?
    //
    if(ui32RxBurst == ui32TxBurst)
    {
        //
        // Yes - set up to use a single burst length.
        //
        ui32Val |= (ui32TxBurst << EMAC_DMABUSMOD_PBL_S);
    }
    else
    {
        //
        // No - we need to use separate burst lengths for each.
        //
        ui32Val |= (EMAC_DMABUSMOD_USP |
                    (ui32TxBurst << EMAC_DMABUSMOD_PBL_S) |
                    (ui32RxBurst << EMAC_DMABUSMOD_RPBL_S));
    }

    //
    // Finally, write the bus mode register.
    //
    HWREG(ui32Base + EMAC_O_DMABUSMOD) = ui32Val;

    //
    // Default the MII CSR clock divider based on the fastest system clock.
    //
    ui32Div = g_pi16MIIClockDiv[NUM_CLOCK_DIVISORS - 1].ui32Divisor;

    //
    // Find the MII CSR clock divider to use based on the current system clock.
    //
    for(ui32Val = 0; ui32Val < NUM_CLOCK_DIVISORS; ui32Val++)
    {
        if(ui32SysClk <= g_pi16MIIClockDiv[ui32Val].ui32SysClockMax)
        {
            ui32Div = g_pi16MIIClockDiv[ui32Val].ui32Divisor;
            break;
        }
    }

    //
    // Set the MII CSR clock speed.
    //
    HWREG(ui32Base + EMAC_O_MIIADDR) = ((HWREG(ui32Base + EMAC_O_MIIADDR) &
                                         ~EMAC_MIIADDR_CR_M) | ui32Div);

    //
    // Disable all the MMC interrupts as these are enabled by default at reset.
    //
    HWREG(ui32Base + EMAC_O_MMCRXIM) = 0xFFFFFFFF;
    HWREG(ui32Base + EMAC_O_MMCTXIM) = 0xFFFFFFFF;
}

//*****************************************************************************
//
//! Resets the Ethernet MAC.
//!
//! \param ui32Base is the base address of the Ethernet controller.
//!
//! This function performs a reset of the Ethernet MAC, resets all logic and
//! sets all registers to their default values.  The function returns only
//! once the hardware indicates that the reset has completed.
//!
//! \note To ensure that the reset completes, the selected PHY clock must be
//! enabled when this function is called.  If the PHY clock is absent, this
//! function will hang.
//!
//! \return None.
//
//*****************************************************************************
void
EMACReset(uint32_t ui32Base)
{
    //
    // Reset the Ethernet MAC.
    //
    HWREG(ui32Base + EMAC_O_DMABUSMOD) |= EMAC_DMABUSMOD_SWR;

    //
    // Wait for the reset to complete.
    //
    while(HWREG(ui32Base + EMAC_O_DMABUSMOD) & EMAC_DMABUSMOD_SWR)
    {
    }
}

//*****************************************************************************
//
//! Selects the Ethernet PHY in use.
//!
//! \param ui32Base is the base address of the Ethernet controller.
//! \param ui32Config selects the PHY in use and, when using the internal
//! PHY, allows various various PHY parameters to be configured.
//!
//! This function must be called prior to EMACInit() and EMACConfigSet() to
//! select the Ethernet PHY to be used.  If the internal PHY is selected, the
//! function also allows configuration of various PHY parameters.  Note that
//! the Ethernet MAC is reset during this function call since parameters set
//! here are latched by the hardware only on a MAC reset.  The call sequence to
//! select and configure the PHY, therefore, must be as follows:
//!
//! \verbatim
//!     // Enable and reset the MAC.
//!     SysCtlPeripheralEnable(SYSCTL_PERIPH_EMAC0);
//!     SysCtlPeripheralReset(SYSCTL_PERIPH_EMAC0);
//!     if(<using internal PHY>)
//!     {
//!         // Enable and reset the internal PHY.
//!         SysCtlPeripheralEnable(SYSCTL_PERIPH_EPHY0);
//!         SysCtlPeripheralReset(SYSCTL_PERIPH_EPHY0);
//!     }
//!
//!     // Ensure the MAC is completed its reset.
//!     while(!MAP_SysCtlPeripheralReady(SYSCTL_PERIPH_EMAC0))
//!     {
//!     }
//!
//!     // Set the PHY type and configuration options.
//!     EMACPHYConfigSet(EMAC0_BASE, <config>);
//!
//!     // Initialize and configure the MAC.
//!     EMACInit(EMAC0_BASE, <system clock rate>, <bus config>,
//!              <Rx burst size>, <Tx burst size>, <desc skip>);
//!     EMACConfigSet(EMAC0_BASE, <parameters>);
//! \endverbatim
//!
//! The \e ui32Config parameter must specify one of the following values:
//!
//! - \b EMAC_PHY_TYPE_INTERNAL selects the internal Ethernet PHY.
//! - \b EMAC_PHY_TYPE_EXTERNAL_MII selects an external PHY connected via the
//! MII interface.
//! - \b EMAC_PHY_TYPE_EXTERNAL_RMII selects an external PHY connected via the
//! RMII interface.
//!
//! If \b EMAC_PHY_TYPE_INTERNAL is selected, the following flags may be ORed
//! into \e ui32Config to control various PHY features and modes.  These are
//! ignored if an external PHY is selected.
//!
//! - \b EMAC_PHY_INT_NIB_TXERR_DET_DIS disables odd nibble transmit error
//! detection (sets the default value of PHY register 0x0A, bit 1).
//! - \b EMAC_PHY_INT_RX_ER_DURING_IDLE enables receive error detection during
//! idle  (sets the default value of PHY register 0x0A, bit 2).
//! - \b EMAC_PHY_INT_ISOLATE_MII_LLOSS ties the MII outputs low if no link is
//! established in 100B-T and full duplex modes(sets the default value of PHY
//! register 0x0A, bit 3).
//! - \b EMAC_PHY_INT_LINK_LOSS_RECOVERY enables link loss recovery (sets the
//! default value of PHY register 0x09, bit 7).
//! - \b EMAC_PHY_INT_TDRRUN enables execution of the TDR procedure after a link
//! down event (sets the default value of PHY register 0x09, bit 8).
//! - \b EMAC_PHY_INT_LD_ON_RX_ERR_COUNT enables link down if the receiver
//! error count reaches 32 within a 10uS interval (sets the default value of
//! PHY register 0x0B bit 3).
//! - \b EMAC_PHY_INT_LD_ON_MTL3_ERR_COUNT enables link down if the MTL3 error
//! count reaches 20 in a 10uS interval (sets the default value of PHY register
//! 0x0B bit 2).
//! - \b EMAC_PHY_INT_LD_ON_LOW_SNR enables link down if the low SNR threshold
//! is crossed 20 times in a 10uS interval (sets the default value of PHY
//! register 0x0B bit 1).
//! - \b EMAC_PHY_INT_LD_ON_SIGNAL_ENERGY enables link down if energy detector
//! indicates Energy Loss (sets the default value of PHY register 0x0B bit 0).
//! - \b EMAC_PHY_INT_POLARITY_SWAP inverts the polarity on both TPTD and TPRD
//! pairs (sets the default value of PHY register 0x0B bit 5).
//! - \b EMAC_PHY_INT_MDI_SWAP swaps the MDI pairs putting receive on the TPTD
//! pair and transmit on TPRD (sets the default value of PHY register 0x0B bit
//! 6).
//! - \b EMAC_PHY_INT_ROBUST_MDIX enables robust auto MDI-X resolution (sets the
//! default value of PHY register 0x09 bit 5).
//! - \b EMAC_PHY_INT_FAST_MDIX enables fast auto-MDI/MDIX resolution (sets the
//! default value of PHY register 0x09 bit 6).
//! - \b EMAC_PHY_INT_MDIX_EN enables auto-MDI/MDIX crossover (sets the
//! default value of PHY register 0x09 bit 14).
//! - \b EMAC_PHY_INT_FAST_RXDV_DETECT enables fast RXDV detection (set the
//! default value of PHY register 0x09 bit 1).
//! - \b EMAC_PHY_INT_FAST_L_UP_DETECT enables fast link-up time during parallel
//! detection (sets the default value of PHY register 0x0A bit 6)
//! - \b EMAC_PHY_INT_EXT_FULL_DUPLEX forces full-duplex while working with a
//! link partner in forced 100B-TX (sets the default value of PHY register
//! 0x0A bit 5).
//! - \b EMAC_PHY_INT_FAST_AN_80_50_35 enables fast auto-negotiation using
//! break link, link fail inhibit and wait timers set to 80, 50 and 35
//! respectively (sets the default value of PHY register 9 bits [4:2] to
//! 3b100).
//! - \b EMAC_PHY_INT_FAST_AN_120_75_50 enables fast auto-negotiation using
//! break link, link fail inhibit and wait timers set to 120, 75 and 50
//! respectively (sets the default value of PHY register 9 bits [4:2] to
//! 3b101).
//! - \b EMAC_PHY_INT_FAST_AN_140_150_100 enables fast auto-negotiation using
//! break link, link fail inhibit and wait timers set to 140, 150 and 100
//! respectively (sets the default value of PHY register 9 bits [4:2] to
//! 3b110).
//! - \b EMAC_PHY_FORCE_10B_T_HALF_DUPLEX disables auto-negotiation and forces
//! operation in 10Base-T, half duplex mode (sets the default value of PHY
//! register 9 bits [13:11] to 3b000).
//! - \b EMAC_PHY_FORCE_10B_T_FULL_DUPLEX disables auto-negotiation and forces
//! operation in 10Base-T, full duplex mode (sets the default value of PHY
//! register 9 bits [13:11] to 3b001).
//! - \b EMAC_PHY_FORCE_100B_T_HALF_DUPLEX disables auto-negotiation and forces
//! operation in 100Base-T, half duplex mode (sets the default value of PHY
//! register 9 bits [13:11] to 3b010).
//! - \b EMAC_PHY_FORCE_100B_T_FULL_DUPLEX disables auto-negotiation and forces
//! operation in 100Base-T, full duplex mode (sets the default value of PHY
//! register 9 bits [13:11] to 3b011).
//! - \b EMAC_PHY_AN_10B_T_HALF_DUPLEX enables auto-negotiation and advertises
//! 10Base-T, half duplex mode (sets the default value of PHY register 9 bits
//! [13:11] to 3b100).
//! - \b EMAC_PHY_AN_10B_T_FULL_DUPLEX enables auto-negotiation and advertises
//! 10Base-T half or full duplex modes (sets the default value of PHY register
//! 9 bits [13:11] to 3b101).
//! - \b EMAC_PHY_AN_100B_T_HALF_DUPLEX enables auto-negotiation and advertises
//! 10Base-T half or full duplex, and 100Base-T half duplex modes (sets the
//! default value of PHY register 9 bits [13:11] to 3b110).
//! - \b EMAC_PHY_AN_100B_T_FULL_DUPLEX enables auto-negotiation and advertises
//! 10Base-T half or full duplex, and 100Base-T half or full duplex modes (sets
//! the default value of PHY register 9 bits [13:11] to 3b111).
//! - \b EMAC_PHY_INT_HOLD prevents the PHY from transmitting energy on the
//! line.
//!
//! As a side-effect of this function, the Ethernet MAC is reset so any
//! previous MAC configuration is lost.
//!
//! \return None.
//
//*****************************************************************************
void
EMACPHYConfigSet(uint32_t ui32Base, uint32_t ui32Config)
{
    uint32_t ui32Val;

    //
    // Remember the current configuration.
    //
    ui32Val = HWREG(ui32Base + EMAC_O_PC) & EMAC_PHY_TYPE_MASK;

    //
    // Write the Ethernet PHY configuration to the peripheral configuration
    // register.
    //
    HWREG(ui32Base + EMAC_O_PC) = ui32Config;

    //
    // If using the internal PHY, reset it to ensure that new configuration is
    // latched there.
    //
    if((ui32Config & EMAC_PHY_TYPE_MASK) == EMAC_PHY_TYPE_INTERNAL)
    {
        SysCtlPeripheralReset(SYSCTL_PERIPH_EPHY0);
        while(!SysCtlPeripheralReady(SYSCTL_PERIPH_EPHY0))
        {
            //
            // Wait for the PHY reset to complete.
            //
        }

        //
        // Delay a bit longer to ensure that the PHY reset has completed.
        //
        SysCtlDelay(1000);
    }

    //
    // If using an external RMII PHY, we must set 2 bits in the Ethernet MAC
    // Clock Configuration Register.
    //
    if((ui32Config & EMAC_PHY_TYPE_MASK) == EMAC_PHY_TYPE_EXTERNAL_RMII)
    {
        //
        // Select and enable the external clock from the RMII PHY.
        //
        HWREG(EMAC0_BASE + EMAC_O_CC) |= (EMAC_CC_ECEXT | EMAC_CC_CLKEN);
    }
    else
    {
        //
        // Disable the external clock.
        //
        HWREG(EMAC0_BASE + EMAC_O_CC) &= ~(EMAC_CC_ECEXT | EMAC_CC_CLKEN);
    }

    //
    // If the PHY connection changed, reset the MAC.
    //
    if(ui32Val != (ui32Config & EMAC_PHY_TYPE_MASK))
    {
        //
        // Reset the MAC.
        //
        EMACReset(EMAC0_BASE);

        SysCtlDelay(1000);
    }
}

//*****************************************************************************
//
//! Configures basic Ethernet MAC operation parameters.
//!
//! \param ui32Base is the base address of the Ethernet controller.
//! \param ui32Config provides various flags and values configuring the MAC.
//! \param ui32ModeFlags provides configuration relating to the transmit and
//! receive DMA engines.
//! \param ui32RxMaxFrameSize sets the maximum receive frame size above which
//! an error will be reported.
//!
//! This function is called to configure basic operating parameters for the
//! MAC and its DMA engines.
//!
//! The \e ui32Config parameter is the logical OR of various fields and
//! flags.  The first field determines which MAC address is used during
//! insertion or replacement for all transmitted frames.  Valid options are
//!
//! - \b EMAC_CONFIG_USE_MACADDR1 and
//! - \b EMAC_CONFIG_USE_MACADDR0
//!
//! The interframe gap between transmitted frames is controlled using one of
//! the following values:
//!
//! - \b EMAC_CONFIG_IF_GAP_96BITS
//! - \b EMAC_CONFIG_IF_GAP_88BITS
//! - \b EMAC_CONFIG_IF_GAP_80BITS
//! - \b EMAC_CONFIG_IF_GAP_72BITS
//! - \b EMAC_CONFIG_IF_GAP_64BITS
//! - \b EMAC_CONFIG_IF_GAP_56BITS
//! - \b EMAC_CONFIG_IF_GAP_48BITS
//! - \b EMAC_CONFIG_IF_GAP_40BITS
//!
//! The number of bytes of preamble added to the beginning of every transmitted
//! frame is selected using one of the following values:
//!
//! - \b EMAC_CONFIG_7BYTE_PREAMBLE
//! - \b EMAC_CONFIG_5BYTE_PREAMBLE
//! - \b EMAC_CONFIG_3BYTE_PREAMBLE
//!
//! The back-off limit determines the range of the random time that the MAC
//! delays after a collision and before attempting to retransmit a frame.  One
//! of the following values must be used to select this limit.  In each case,
//! the retransmission delay in terms of 512 bit time slots, will be the lower
//! of (2 ** N) and a random number between 0 and the selected backoff-limit.
//!
//! - \b EMAC_CONFIG_BO_LIMIT_1024
//! - \b EMAC_CONFIG_BO_LIMIT_256
//! - \b EMAC_CONFIG_BO_LIMIT_16
//! - \b EMAC_CONFIG_BO_LIMIT_2
//!
//! Control over insertion or replacement of the source address in all
//! transmitted frames is provided by using one of the following fields:
//!
//! - \b EMAC_CONFIG_SA_INSERT causes the MAC address (0 or 1 depending
//! upon whether \b EMAC_CONFIG_USE_MACADDR0 or \b EMAC_CONFIG_USE_MACADDR1
//! was specified) to be inserted into all transmitted frames.
//! - \b EMAC_CONFIG_SA_REPLACE causes the MAC address to be replaced with
//! the selected address in all transmitted frames.
//! - \b EMAC_CONFIG_SA_FROM_DESCRIPTOR causes control of source address
//! insertion or deletion to be controlled by fields in the DMA transmit
//! descriptor, allowing control on a frame-by-frame basis.
//!
//! Whether the interface attempts to operate in full- or half-duplex mode is
//! controlled by one of the following flags:
//!
//! - \b EMAC_CONFIG_FULL_DUPLEX
//! - \b EMAC_CONFIG_HALF_DUPLEX
//!
//! The following additional flags may also be specified:
//!
//! - \b EMAC_CONFIG_2K_PACKETS enables IEEE802.3as support for 2K packets.
//! When specified, the MAC considers all frames up to 2000 bytes in length as
//! normal packets.  When \b EMAC_CONFIG_JUMBO_ENABLE is not specified, all
//! frames larger than 2000 bytes are treated as Giant frames.  This flag is
//! ignored if \b EMAC_CONFIG_JUMBO_ENABLE is specified.
//! - \b EMAC_CONFIG_STRIP_CRC causes the 4 byte CRC of all Ethernet type
//! frames to be stripped and dropped before the frame is forwarded to the
//! application.
//! - \b EMAC_CONFIG_JABBER_DISABLE disables the jabber timer on the
//! transmitter and enables frames of up to 16384 bytes to be transmitted.  If
//! this flag is absent, the MAC does not allow more than 2048 (or 10240 if
//! \b EMAC_CONFIG_JUMBO_ENABLE is specified) bytes to be sent in any one
//! frame.
//! - \b EMAC_CONFIG_JUMBO_ENABLE enables Jumbo Frames, allowing frames of
//! up to 9018 (or 9022 if using VLAN tagging) to be handled without reporting
//! giant frame errors.
//! - \b EMAC_CONFIG_100MBPS forces the MAC to communicate with the PHY using
//! 100Mbps signaling.  If this option is not specified, the MAC will use
//! 10Mbps signaling.  This speed setting is important when using an external
//! RMII PHY where the selected rate must match the PHY's setting which may
//! have been made as a result of auto-negotiation.  When using the internal
//! PHY or an external MII PHY, the signaling rate is controlled by the
//! PHY-provided transmit and receive clocks.
//! - \b EMAC_CONFIG_CS_DISABLE disables Carrier Sense during transmission
//! when operating in half-duplex mode.
//! - \b EMAC_CONFIG_RX_OWN_DISABLE disables reception of transmitted frames
//! when operating in half-duplex mode.
//! - \b EMAC_CONFIG_LOOPBACK enables internal loopback.
//! - \b EMAC_CONFIG_CHECKSUM_OFFLOAD enables IPv4 header checksum checking
//! and IPv4 or IPv6 TCP, UPD or ICMP payload checksum checking.  The results
//! of the checksum calculations are reported via status fields in the DMA
//! receive descriptors.
//! - \b EMAC_CONFIG_RETRY_DISABLE disables retransmission in cases where
//! half-duplex mode is in use and a collision occurs.  This causes the current
//! frame to be ignored and a frame abort to be reported in the transmit frame
//! status.
//! - \b EMAC_CONFIG_AUTO_CRC_STRIPPING strips the last 4 bytes (frame check
//! sequence) from all Ether type frames before forwarding the frames to the
//! application.
//! - \b EMAC_CONFIG_DEFERRAL_CHK_ENABLE enables transmit deferral checking
//! in half-duplex mode.  When enabled, the transmitter will report an error
//! if it is unable to transmit a frame for more than 24288 bit times (or
//! 155680 bit times in Jumbo frame mode) due to an active carrier sense signal
//! on the MII.
//!
//! The \e ui32ModeFlags parameter sets operating parameters related to the
//! internal MAC FIFOs.  It comprises a logical OR of the following fields.
//! The first selects the transmit FIFO threshold.  Transmission of a frame
//! begins when this amount of data or a full frame exists in the transmit
//! FIFO.  This field is ignored if \b EMAC_MODE_TX_STORE_FORWARD is
//! included.  One of the following must be specified:
//!
//! - \b EMAC_MODE_TX_THRESHOLD_16_BYTES
//! - \b EMAC_MODE_TX_THRESHOLD_24_BYTES
//! - \b EMAC_MODE_TX_THRESHOLD_32_BYTES
//! - \b EMAC_MODE_TX_THRESHOLD_40_BYTES
//! - \b EMAC_MODE_TX_THRESHOLD_64_BYTES
//! - \b EMAC_MODE_TX_THRESHOLD_128_BYTES
//! - \b EMAC_MODE_TX_THRESHOLD_192_BYTES
//! - \b EMAC_MODE_TX_THRESHOLD_256_BYTES
//!
//! The second field controls the receive FIFO threshold.  DMA transfers of
//! received data begin either when the receive FIFO contains a full frame
//! or this number of bytes.  This field is ignored if
//! \b EMAC_MODE_RX_STORE_FORWARD is included.  One of the following must be
//! specified:
//!
//! - \b EMAC_MODE_RX_THRESHOLD_64_BYTES
//! - \b EMAC_MODE_RX_THRESHOLD_32_BYTES
//! - \b EMAC_MODE_RX_THRESHOLD_96_BYTES
//! - \b EMAC_MODE_RX_THRESHOLD_128_BYTES
//!
//! The following additional flags may be specified:
//!
//! - \b EMAC_MODE_KEEP_BAD_CRC causes frames with TCP/IP checksum errors
//! to be forwarded to the application if those frames do not have any errors
//! (including FCS errors) in the Ethernet framing.  In these cases, the frames
//! have errors only in the payload.  If this flag is not specified, all frames
//! with any detected error are discarded unless \b EMAC_MODE_RX_ERROR_FRAMES
//! is also specified.
//! - \b EMAC_MODE_RX_STORE_FORWARD causes the receive DMA to read frames
//! from the FIFO only after the complete frame has been written to it.  If
//! this mode is enabled, the receive threshold is ignored.
//! - \b EMAC_MODE_RX_FLUSH_DISABLE disables the flushing of received frames
//! in cases where receive descriptors or buffers are unavailable.
//! - \b EMAC_MODE_TX_STORE_FORWARD causes the transmitter to start
//! transmitting a frame only after the whole frame has been written to the
//! transmit FIFO.  If this mode is enabled, the transmit threshold is ignored.
//! - \b EMAC_MODE_RX_ERROR_FRAMES causes all frames other than runt error
//! frames to be forwarded to the receive DMA regardless of any errors detected
//! in the frames.
//! - \b EMAC_MODE_RX_UNDERSIZED_FRAMES causes undersized frames (frames
//! shorter than 64 bytes but with no errors) to the application.  If this
//! option is not selected, all undersized frames are dropped by the receiver
//! unless it has already started transferring them to the receive FIFO due to
//! the receive threshold setting.
//! - \b EMAC_MODE_OPERATE_2ND_FRAME enables the transmit DMA to operate on a
//! second frame while waiting for the previous frame to be transmitted and
//! associated status and timestamps to be reported.  If absent, the transmit
//! DMA works on a single frame at any one time, waiting for that frame to be
//! transmitted and its status to be received before moving on to the next
//! frame.
//!
//! The \e ui32RxMaxFrameSize parameter may be used to override the default
//! setting for the maximum number of bytes that can be received in a frame
//! before that frame is flagged as being in error.  If the parameter is set
//! to 0, the default hardware settings are applied.  If non-zero, any frame
//! received which is longer than the \e ui32RxMaxFrameSize, regardless of
//! whether the MAC is configured for normal or Jumbo frame operation, will be
//! flagged as an error.
//!
//! \return None.
//
//*****************************************************************************
void
EMACConfigSet(uint32_t ui32Base, uint32_t ui32Config, uint32_t ui32ModeFlags,
              uint32_t ui32RxMaxFrameSize)
{
    //
    // Parameter sanity check.
    //
    ASSERT((ui32Config & ~VALID_CONFIG_FLAGS) == 0);
    ASSERT(!ui32RxMaxFrameSize || ((ui32RxMaxFrameSize < 0x4000) &&
                                   (ui32RxMaxFrameSize > 1522)));

    //
    // Set the configuration flags as specified.  Note that we unconditionally
    // OR in the EMAC_CFG_PS bit here since this implementation supports only
    // MII and RMII interfaces to the PHYs.
    //
    HWREG(ui32Base + EMAC_O_CFG) =
        ((HWREG(ui32Base + EMAC_O_CFG) & ~VALID_CONFIG_FLAGS) | ui32Config |
         EMAC_CFG_PS);

    //
    // Set the maximum receive frame size.  If 0 is passed, this implies
    // that the default maximum frame size should be used so just turn off
    // the override.
    //
    if(ui32RxMaxFrameSize)
    {
        HWREG(ui32Base + EMAC_O_WDOGTO) = ui32RxMaxFrameSize | EMAC_WDOGTO_PWE;
    }
    else
    {
        HWREG(ui32Base + EMAC_O_WDOGTO) &= ~EMAC_WDOGTO_PWE;
    }

    //
    // Set the operating mode register.
    //
    HWREG(ui32Base + EMAC_O_DMAOPMODE) = ui32ModeFlags;
}

//*****************************************************************************
//
//! Returns the Ethernet MAC's current basic configuration parameters.
//!
//! \param ui32Base is the base address of the Ethernet controller.
//! \param pui32Config points to storage that is written with Ethernet MAC
//! configuration.
//! \param pui32Mode points to storage that is written with Ethernet MAC mode
//! information.
//! \param pui32RxMaxFrameSize points to storage that is written with the
//! maximum receive frame size.
//!
//! This function is called to query the basic operating parameters for the
//! MAC and its DMA engines.
//!
//! The \e pui32Config parameter is written with the logical OR of various
//! fields and flags.  The first field describes which MAC address is used
//! during insertion or replacement for all transmitted frames.  Valid options
//! are
//!
//! - \b EMAC_CONFIG_USE_MACADDR1
//! - \b EMAC_CONFIG_USE_MACADDR0
//!
//! The interframe gap between transmitted frames is given using one of the
//! following values:
//!
//! - \b EMAC_CONFIG_IF_GAP_96BITS
//! - \b EMAC_CONFIG_IF_GAP_88BITS
//! - \b EMAC_CONFIG_IF_GAP_80BITS
//! - \b EMAC_CONFIG_IF_GAP_72BITS
//! - \b EMAC_CONFIG_IF_GAP_64BITS
//! - \b EMAC_CONFIG_IF_GAP_56BITS
//! - \b EMAC_CONFIG_IF_GAP_48BITS
//! - \b EMAC_CONFIG_IF_GAP_40BITS
//!
//! The number of bytes of preamble added to the beginning of every transmitted
//! frame is described using one of the following values:
//!
//! - \b EMAC_CONFIG_7BYTE_PREAMBLE
//! - \b EMAC_CONFIG_5BYTE_PREAMBLE
//! - \b EMAC_CONFIG_3BYTE_PREAMBLE
//!
//! The back-off limit determines the range of the random time that the MAC
//! delays after a collision and before attempting to retransmit a frame.  One
//! of the following values provides the currently selected limit.  In each
//! case the retransmission delay in terms of 512 bit time slots, is the
//! lower of (2 ** N) and a random number between 0 and the reported
//! backoff-limit.
//!
//! - \b EMAC_CONFIG_BO_LIMIT_1024
//! - \b EMAC_CONFIG_BO_LIMIT_256
//! - \b EMAC_CONFIG_BO_LIMIT_16
//! - \b EMAC_CONFIG_BO_LIMIT_2
//!
//! Handling of insertion or replacement of the source address in all
//! transmitted frames is described by one of the following fields:
//!
//! - \b EMAC_CONFIG_SA_INSERT causes the MAC address (0 or 1 depending
//! upon whether \b EMAC_CONFIG_USE_MACADDR0 or \b EMAC_CONFIG_USE_MACADDR1
//! was specified) to be inserted into all transmitted frames.
//! - \b EMAC_CONFIG_SA_REPLACE causes the MAC address to be replaced with
//! the selected address in all transmitted frames.
//! - \b EMAC_CONFIG_SA_FROM_DESCRIPTOR causes control of source address
//! insertion or deletion to be controlled by fields in the DMA transmit
//! descriptor, allowing control on a frame-by-frame basis.
//!
//! Whether the interface attempts to operate in full- or half-duplex mode is
//! reported by one of the following flags:
//!
//! - \b EMAC_CONFIG_FULL_DUPLEX
//! - \b EMAC_CONFIG_HALF_DUPLEX
//!
//! The following additional flags may also be included:
//!
//! - \b EMAC_CONFIG_2K_PACKETS indicates that IEEE802.3as support for 2K
//! packets is enabled.  When present, the MAC considers all frames up to 2000
//! bytes in length as normal packets.  When \b EMAC_CONFIG_JUMBO_ENABLE is
//! not reported, all frames larger than 2000 bytes are treated as Giant
//! frames.  The value of this flag should be ignored if
//! \b EMAC_CONFIG_JUMBO_ENABLE is also reported.
//! - \b EMAC_CONFIG_STRIP_CRC indicates that the 4 byte CRC of all Ethernet
//! type frames is being stripped and dropped before the frame is forwarded to
//! the application.
//! - \b EMAC_CONFIG_JABBER_DISABLE indicates that the the jabber timer on the
//! transmitter is disabled, allowing frames of up to 16384 bytes to be
//! transmitted.  If this flag is absent, the MAC does not allow more than 2048
//! (or 10240 if \b EMAC_CONFIG_JUMBO_ENABLE is reported) bytes to be sent in
//! any one frame.
//! - \b EMAC_CONFIG_JUMBO_ENABLE indicates that Jumbo Frames of up to 9018
//! (or 9022 if using VLAN tagging) are enabled.
//! - \b EMAC_CONFIG_CS_DISABLE indicates that Carrier Sense is disabled
//! during transmission when operating in half-duplex mode.
//! - \b EMAC_CONFIG_100MBPS indicates that the MAC is using 100Mbps
//! signaling to communicate with the PHY.
//! - \b EMAC_CONFIG_RX_OWN_DISABLE indicates that reception of transmitted
//! frames is disabled when operating in half-duplex mode.
//! - \b EMAC_CONFIG_LOOPBACK indicates that internal loopback is enabled.
//! - \b EMAC_CONFIG_CHECKSUM_OFFLOAD indicates that IPv4 header checksum
//! checking and IPv4 or IPv6 TCP, UPD or ICMP payload checksum checking is
//! enabled.  The results of the checksum calculations are reported via status
//! fields in the DMA receive descriptors.
//! - \b EMAC_CONFIG_RETRY_DISABLE indicates that retransmission is disabled
//! in cases where half-duplex mode is in use and a collision occurs.  This
//! causes the current frame to be ignored and a frame abort to be reported in
//! the transmit frame status.
//! - \b EMAC_CONFIG_AUTO_CRC_STRIPPING indicates that the last 4 bytes
//! (frame check sequence) from all Ether type frames are being stripped before
//! frames are forwarded to the application.
//! - \b EMAC_CONFIG_DEFERRAL_CHK_ENABLE indicates that transmit deferral
//! checking is disabled in half-duplex mode.  When enabled, the transmitter
//! will report an error if it is unable to transmit a frame for more than
//! 24288 bit times (or 155680 bit times in Jumbo frame mode) due to an active
//! carrier sense signal on the MII.
//! - \b EMAC_CONFIG_TX_ENABLED indicates that the MAC transmitter is
//! currently enabled.
//! - \b EMAC_CONFIG_RX_ENABLED indicates that the MAC receiver is
//! currently enabled.
//!
//! The \e pui32ModeFlags parameter is written with operating parameters
//! related to the internal MAC FIFOs.  It comprises a logical OR of the
//! following fields.  The first reports the transmit FIFO threshold.
//! Transmission of a frame begins when this amount of data or a full frame
//! exists in the transmit FIFO.  This field should be ignored if
//! \b EMAC_MODE_TX_STORE_FORWARD is also reported.  One of the following
//! values is reported:
//!
//! - \b EMAC_MODE_TX_THRESHOLD_16_BYTES
//! - \b EMAC_MODE_TX_THRESHOLD_24_BYTES
//! - \b EMAC_MODE_TX_THRESHOLD_32_BYTES
//! - \b EMAC_MODE_TX_THRESHOLD_40_BYTES
//! - \b EMAC_MODE_TX_THRESHOLD_64_BYTES
//! - \b EMAC_MODE_TX_THRESHOLD_128_BYTES
//! - \b EMAC_MODE_TX_THRESHOLD_192_BYTES
//! - \b EMAC_MODE_TX_THRESHOLD_256_BYTES
//!
//! The second field reports the receive FIFO threshold.  DMA transfers of
//! received data begin either when the receive FIFO contains a full frame
//! or this number of bytes.  This field should be ignored if
//! \b EMAC_MODE_RX_STORE_FORWARD is included.  One of the following values
//! is reported:
//!
//! - \b EMAC_MODE_RX_THRESHOLD_64_BYTES
//! - \b EMAC_MODE_RX_THRESHOLD_32_BYTES
//! - \b EMAC_MODE_RX_THRESHOLD_96_BYTES
//! - \b EMAC_MODE_RX_THRESHOLD_128_BYTES
//!
//! The following additional flags may be included:
//!
//! - \b EMAC_MODE_KEEP_BAD_CRC indicates that frames with TCP/IP checksum
//! errors are being forwarded to the application if those frames do not have
//! any errors (including FCS errors) in the Ethernet framing.  In these cases,
//! the frames have errors only in the payload.  If this flag is not reported,
//! all frames with any detected error are discarded unless
//! \b EMAC_MODE_RX_ERROR_FRAMES is also reported.
//! - \b EMAC_MODE_RX_STORE_FORWARD indicates that the receive DMA is
//! configured to read frames from the FIFO only after the complete frame has
//! been written to it.  If this mode is enabled, the receive threshold is
//! ignored.
//! - \b EMAC_MODE_RX_FLUSH_DISABLE indicates that the flushing of received
//! frames is disabled in cases where receive descriptors or buffers are
//! unavailable.
//! - \b EMAC_MODE_TX_STORE_FORWARD indicates that the transmitter is
//! configured to transmit a frame only after the whole frame has been written
//! to the transmit FIFO.  If this mode is enabled, the transmit threshold is
//! ignored.
//! - \b EMAC_MODE_RX_ERROR_FRAMES indicates that all frames other than runt
//! error frames are being forwarded to the receive DMA regardless of any
//! errors detected in the frames.
//! - \b EMAC_MODE_RX_UNDERSIZED_FRAMES indicates that undersized frames
//! (frames shorter than 64 bytes but with no errors) are being forwarded to
//! the application.  If this option is not reported, all undersized frames are
//! dropped by the receiver unless it has already started transferring them to
//! the receive FIFO due to the receive threshold setting.
//! - \b EMAC_MODE_OPERATE_2ND_FRAME indicates that the transmit DMA is
//! configured to operate on a second frame while waiting for the previous
//! frame to be transmitted and associated status and timestamps to be reported.
//! If absent, the transmit DMA works on a single frame at any one time,
//! waiting for that frame to be transmitted and its status to be received
//! before moving on to the next frame.
//! - \b EMAC_MODE_TX_DMA_ENABLED indicates that the transmit DMA engine is
//! currently enabled.
//! - \b EMAC_MODE_RX_DMA_ENABLED indicates that the receive DMA engine is
//! currently enabled.
//!
//! The \e pui32RxMaxFrameSize is written with the currently configured maximum
//! receive packet size.  Packets larger than this will be flagged as being in
//! error.
//!
//! \return None.
//
//*****************************************************************************
void
EMACConfigGet(uint32_t ui32Base, uint32_t *pui32Config, uint32_t *pui32Mode,
              uint32_t *pui32RxMaxFrameSize)
{
    uint32_t ui32Value;

    //
    // Parameter sanity check.
    //
    ASSERT(pui32Mode);
    ASSERT(pui32Config);
    ASSERT(pui32RxMaxFrameSize);

    //
    // Return the mode information from the operation mode register.
    //
    *pui32Mode = HWREG(ui32Base + EMAC_O_DMAOPMODE);

    //
    // Return the current configuration flags from the EMAC_O_CFG register.
    //
    *pui32Config = (HWREG(ui32Base + EMAC_O_CFG) &
                    (VALID_CONFIG_FLAGS | EMAC_CONFIG_TX_ENABLED |
                     EMAC_CONFIG_RX_ENABLED));

    //
    // Get the receive packet size watchdog value.
    //
    ui32Value = HWREG(ui32Base + EMAC_O_WDOGTO);
    if(ui32Value & EMAC_WDOGTO_PWE)
    {
        //
        // The watchdog is enables so the maximum packet length can be read
        // from the watchdog timeout register.
        //
        *pui32RxMaxFrameSize = ui32Value & EMAC_WDOGTO_WTO_M;
    }
    else
    {
        //
        // The maximum packet size override found in the watchdog timer
        // register is not enabled so the maximum packet size is determined
        // by whether or not jumbo frame mode is enabled.
        //
        if(HWREG(ui32Base + EMAC_O_CFG) & EMAC_CFG_JFEN)
        {
            //
            // Jumbo frames are enabled so the watchdog kicks in at 10240
            // bytes.
            //
            *pui32RxMaxFrameSize = 10240;
        }
        else
        {
            //
            // Jumbo frames are not enabled so the watchdog kicks in at
            // 2048 bytes.
            //
            *pui32RxMaxFrameSize = 2048;
        }
    }
}

//*****************************************************************************
//
//! Sets the MAC address of the Ethernet controller.
//!
//! \param ui32Base is the base address of the Ethernet controller.
//! \param ui32Index is the zero-based index of the MAC address to set.
//! \param pui8MACAddr is the pointer to the array of MAC-48 address octets.
//!
//! This function programs the IEEE-defined MAC-48 address specified in
//! \e pui8MACAddr into the Ethernet controller.  This address is used by the
//! Ethernet controller for hardware-level filtering of incoming Ethernet
//! packets (when promiscuous mode is not enabled).  Index 0 is used to hold
//! the local node's MAC address which is inserted into all transmitted
//! packets.
//!
//! The controller may support several Ethernet MAC address slots, each of which
//! may be programmed independently and used to filter incoming packets.  The
//! number of MAC addresses that the hardware supports may be queried using a
//! call to EMACNumAddrGet().  The value of the \e ui32Index parameter must
//! lie in the range from 0 to (number of MAC addresses - 1) inclusive.
//!
//! The MAC-48 address is defined as 6 octets, illustrated by the following
//! example address.  The numbers are shown in hexadecimal format.
//!
//!         AC-DE-48-00-00-80
//!
//! In this representation, the first three octets (AC-DE-48) are the
//! Organizationally Unique Identifier (OUI).  This is a number assigned by
//! the IEEE to an organization that requests a block of MAC addresses.  The
//! last three octets (00-00-80) are a 24-bit number managed by the OUI owner
//! to uniquely identify a piece of hardware within that organization that is
//! to be connected to the Ethernet.
//!
//! In this representation, the octets are transmitted from left to right,
//! with the ``AC'' octet being transmitted first and the ``80'' octet being
//! transmitted last.  Within an octet, the bits are transmitted LSB to MSB.
//! For this address, the first bit to be transmitted would be ``0'', the LSB
//! of ``AC'', and the last bit to be transmitted would be ``1'', the MSB of
//! ``80''.
//!
//! The address passed to this function in the \e pui8MACAddr array is
//! ordered with the first byte to be transmitted in the first array entry.
//! For example, the address given above could be represented using the
//! following array:
//!
//! uint8_t g_pui8MACAddr[] = { 0xAC, 0xDE, 0x48, 0x00, 0x00, 0x80 };
//!
//! If the MAC address set by this function is currently enabled, it will
//! remain enabled following this call.  Similarly, any filter configured for
//! the MAC address will remain unaffected by a change in the address.
//!
//! \return None.
//
//*****************************************************************************
void
EMACAddrSet(uint32_t ui32Base, uint32_t ui32Index, const uint8_t *pui8MACAddr)
{
    //
    // Parameter sanity check.
    //
    ASSERT(ui32Index < NUM_MAC_ADDR);
    ASSERT(pui8MACAddr);

    //
    // Set the high 2 bytes of the MAC address.  Note that we must set the
    // registers in this order since the address is latched internally
    // on the write to EMAC_O_ADDRL.
    //
    HWREG(ui32Base + EMAC_O_ADDRH(ui32Index)) =
        ((HWREG(ui32Base + EMAC_O_ADDRH(ui32Index)) & 0xFFFF0000) |
         pui8MACAddr[4] | (pui8MACAddr[5] << 8));

    //
    // Set the first 4 bytes of the MAC address
    //
    HWREG(ui32Base + EMAC_O_ADDRL(ui32Index)) =
        (pui8MACAddr[0] | (pui8MACAddr[1] << 8) | (pui8MACAddr[2] << 16) |
         (pui8MACAddr[3] << 24));
}

//*****************************************************************************
//
//! Gets one of the MAC addresses stored in the Ethernet controller.
//!
//! \param ui32Base is the base address of the controller.
//! \param ui32Index is the zero-based index of the MAC address to return.
//! \param pui8MACAddr is the pointer to the location in which to store the
//! array of MAC-48 address octets.
//!
//! This function reads the currently programmed MAC address into the
//! \e pui8MACAddr buffer.  The \e ui32Index parameter defines which of the
//! hardware's MAC addresses to return.  The number of MAC addresses supported
//! by the controller may be queried using a call to EMACNumAddrGet().
//! Index 0 refers to the MAC address of the local node.  Other indices are
//! used to MAC addresses when filtering incoming packets.
//!
//! The address is written to the pui8MACAddr array ordered with the first byte
//! to be transmitted in the first array entry.  For example, if the address
//! is written in its usual form with the Organizationally Unique Identifier
//! (OUI) shown first as:
//!
//! AC-DE-48-00-00-80
//!
//! the data would be returned with 0xAC in the first byte of the array, 0xDE
//! in the second, 0x48 in the third and so on.
//!
//! \return None.
//
//*****************************************************************************
void
EMACAddrGet(uint32_t ui32Base, uint32_t ui32Index, uint8_t *pui8MACAddr)
{
    uint32_t ui32Val;

    //
    // Parameter sanity check.
    //
    ASSERT(ui32Index < NUM_MAC_ADDR);
    ASSERT(pui8MACAddr);

    //
    // Get the first 4 bytes of the MAC address.
    //
    ui32Val = HWREG(ui32Base + EMAC_O_ADDRL(ui32Index));
    pui8MACAddr[0] = ui32Val & 0xFF;
    pui8MACAddr[1] = (ui32Val >> 8) & 0xFF;
    pui8MACAddr[2] = (ui32Val >> 16) & 0xFF;
    pui8MACAddr[3] = (ui32Val >> 24) & 0xFF;

    //
    // Get the last 2 bytes of the MAC address.
    //
    ui32Val = HWREG(ui32Base + EMAC_O_ADDRH(ui32Index));
    pui8MACAddr[4] = ui32Val & 0xFF;
    pui8MACAddr[5] = (ui32Val >> 8) & 0xFF;
}

//*****************************************************************************
//
//! Returns the number of MAC addresses supported by the Ethernet controller.
//!
//! \param ui32Base is the base address of the Ethernet controller.
//!
//! This function may be used to determine the number of MAC addresses that the
//! given controller supports.  MAC address slots may be used when performing
//! perfect (rather than hash table) filtering of packets.
//!
//! \return Returns the number of supported MAC addresses.
//
//*****************************************************************************
uint32_t
EMACNumAddrGet(uint32_t ui32Base)
{
    //
    // The only Ethernet controller on Snowflake supports 4 MAC addresses.
    //
    return(NUM_MAC_ADDR);
}

//*****************************************************************************
//
//! Sets filtering parameters associated with one of the configured MAC
//! addresses.
//!
//! \param ui32Base is the base address of the controller.
//! \param ui32Index is the index of the MAC address slot whose filter is to be
//!        set.
//! \param ui32Config sets the filter parameters for the given MAC address.
//!
//! This function sets filtering parameters associated with one of the MAC
//! address slots that the controller supports.  This configuration is used
//! when perfect filtering (rather than hash table filtering) is selected.
//!
//! Valid values for \e ui32Index are from 1 to (number of MAC address slots
//! - 1). The number of supported MAC address slots may be found by calling
//! EMACNumAddrGet().  MAC index 0 is the local MAC address and does not
//! have filtering parameters associated with it.
//!
//! The \e ui32Config parameter determines how the given MAC address is used
//! when filtering incoming Ethernet frames.  It is comprised of a logical OR
//! of the fields:
//!
//! - \b EMAC_FILTER_ADDR_ENABLE indicates that this MAC address is enabled
//! and should be used when performing perfect filtering.  If this flag is
//! absent, the MAC address at the given index is disabled and will not take
//! part in filtering.
//! - \b EMAC_FILTER_SOURCE_ADDR indicates that the MAC address at the given
//! index will be compared to the source address of incoming frames while
//! performing perfect filtering.  If absent, the MAC address is compared
//! against the destination address.
//! - \b EMAC_FILTER_MASK_BYTE_6 indicates that the MAC should ignore the
//! sixth byte of the source or destination address when filtering.
//! - \b EMAC_FILTER_MASK_BYTE_5 indicates that the MAC should ignore the
//! fifth byte of the source or destination address when filtering.
//! - \b EMAC_FILTER_MASK_BYTE_4 indicates that the MAC should ignore the
//! fourth byte of the source or destination address when filtering.
//! - \b EMAC_FILTER_MASK_BYTE_3 indicates that the MAC should ignore the
//! third byte of the source or destination address when filtering.
//! - \b EMAC_FILTER_MASK_BYTE_2 indicates that the MAC should ignore the
//! second byte of the source or destination address when filtering.
//! - \b EMAC_FILTER_MASK_BYTE_1 indicates that the MAC should ignore the
//! first byte of the source or destination address when filtering.
//!
//! \return None.
//
//*****************************************************************************
void
EMACAddrFilterSet(uint32_t ui32Base, uint32_t ui32Index, uint32_t ui32Config)
{
    uint32_t ui32Val;

    //
    // Parameter sanity check.
    //
    ASSERT(ui32Index < NUM_MAC_ADDR);
    ASSERT((ui32Config & ~(EMAC_FILTER_BYTE_MASK_M |
                           EMAC_FILTER_ADDR_ENABLE |
                           EMAC_FILTER_SOURCE_ADDR)) == 0);
    ASSERT(ui32Index);

    //
    // Set the filter configuration for a particular MAC address.
    //
    HWREG(ui32Base + EMAC_O_ADDRH(ui32Index)) =
        (HWREG(ui32Base + EMAC_O_ADDRH(ui32Index)) & 0xFFFF) | ui32Config;

    //
    // Read and rewrite the low half of the MAC address register to ensure
    // that the upper half's data is latched.
    //
    ui32Val = HWREG(ui32Base + EMAC_O_ADDRL(ui32Index));
    HWREG(ui32Base + EMAC_O_ADDRL(ui32Index)) = ui32Val;
}

//*****************************************************************************
//
//! Gets filtering parameters associated with one of the configured MAC
//! addresses.
//!
//! \param ui32Base is the base address of the controller.
//! \param ui32Index is the index of the MAC address slot whose filter is to be
//!        queried.
//!
//! This function returns filtering parameters associated with one of the MAC
//! address slots that the controller supports.  This configuration is used
//! when perfect filtering (rather than hash table filtering) is selected.
//!
//! Valid values for \e ui32Index are from 1 to (number of MAC address slots
//! - 1). The number of supported MAC address slots may be found by calling
//! EMACNumAddrGet().  MAC index 0 is the local MAC address and does not
//! have filtering parameters associated with it.
//!
//! \return Returns the filter configuration as the logical OR of the
//! following labels:
//!
//! - \b EMAC_FILTER_ADDR_ENABLE indicates that this MAC address is enabled
//! and is used when performing perfect filtering.  If this flag is absent,
//! the MAC address at the given index is disabled and does not take part in
//! filtering.
//! - \b EMAC_FILTER_SOURCE_ADDR indicates that the MAC address at the given
//! index is compared to the source address of incoming frames while performing
//! perfect filtering.  If absent, the MAC address is compared against the
//! destination address.
//! - \b EMAC_FILTER_MASK_BYTE_6 indicates that the MAC ignores the
//! sixth byte of the source or destination address when filtering.
//! - \b EMAC_FILTER_MASK_BYTE_5 indicates that the MAC ignores the
//! fifth byte of the source or destination address when filtering.
//! - \b EMAC_FILTER_MASK_BYTE_4 indicates that the MAC ignores the
//! fourth byte of the source or destination address when filtering.
//! - \b EMAC_FILTER_MASK_BYTE_3 indicates that the MAC ignores the
//! third byte of the source or destination address when filtering.
//! - \b EMAC_FILTER_MASK_BYTE_2 indicates that the MAC ignores the
//! second byte of the source or destination address when filtering.
//! - \b EMAC_FILTER_MASK_BYTE_1 indicates that the MAC ignores the
//! first byte of the source or destination address when filtering.
//
//*****************************************************************************
uint32_t
EMACAddrFilterGet(uint32_t ui32Base, uint32_t ui32Index)
{
    //
    // Parameter sanity check.
    //
    ASSERT(ui32Index < NUM_MAC_ADDR);
    ASSERT(ui32Index);

    //
    // Read and return the filter settings for the requested MAC address slot.
    //
    return(HWREG(ui32Base + EMAC_O_ADDRH(ui32Index)) &
           (EMAC_FILTER_BYTE_MASK_M | EMAC_FILTER_ADDR_ENABLE |
            EMAC_FILTER_SOURCE_ADDR));
}

//*****************************************************************************
//
//! Sets options related to Ethernet frame filtering.
//!
//! \param ui32Base is the base address of the controller.
//! \param ui32FilterOpts is a logical OR of flags defining the required MAC
//! address filtering options.
//!
//! This function allows various filtering options to be defined and allows
//! an application to control which frames are received based upon various
//! criteria related to the frame source and destination MAC addresses or VLAN
//! tagging.
//!
//! The \e ui32FilterOpts parameter is a logical OR of any of the following
//! flags:
//!
//! - \b EMAC_FRMFILTER_RX_ALL configures the MAC to pass all received frames
//! regardless of whether or not they pass any address filter that is
//! configured.  The receive status word in the relevant DMA descriptor is
//! updated to indicate whether the configured filter passed or failed for
//! the frame.
//! - \b EMAC_FRMFILTER_VLAN configures the MAC to drop any frames which do
//! not pass the VLAN tag comparison.
//! - \b EMAC_FRMFILTER_HASH_AND_PERFECT configures the MAC to filter frames
//! based on both any perfect filters set and the hash filter if enabled using
//! \b EMAC_FRMFILTER_HASH_UNICAST or \b EMAC_FRMFILTER_HASH_MULTICAST.  In
//! this case, only of both filters fail will the packet be rejected.  If this
//! option is absent, only one of the filter types is used, as controlled by
//! \b EMAC_FRMFILTER_HASH_UNICAST and \b EMAC_FRMFILTER_HASH_MULTICAST
//! for unicast and multicast frames respectively.
//! - \b EMAC_FRMFILTER_SADDR configures the MAC to drop received frames
//! when the source address field in the frame does not match the values
//! programmed into the enabled SA registers.
//! - \b EMAC_FRMFILTER_INV_SADDR enables inverse source address filtering.
//! When this option is specified, frames whose SA does not match the SA
//! registers are marked as passing the source address filter.
//! - \b EMAC_FRMFILTER_BROADCAST configures the MAC to discard all incoming
//! broadcast frames.
//! - \b EMAC_FRMFILTER_PASS_MULTICAST configures the MAC to pass all
//! incoming frames with multicast destinations addresses.
//! - \b EMAC_FRMFILTER_INV_DADDR inverts the sense of the destination
//! address filtering for both unicast and multicast frames.
//! - \b EMAC_FRMFILTER_HASH_MULTICAST enables destination address filtering
//! of received multicast frames using the hash table.  If absent, perfect
//! destination address filtering is used.  If used in conjunction with \b
//! EMAC_FRMFILTER_HASH_AND_PERFECT, this flag indicates that the hash filter
//! should be used for incoming multicast packets along with the perfect
//! filter.
//! - \b EMAC_FRMFILTER_HASH_UNICAST enables destination address filtering
//! of received unicast frames using the hash table.  If absent, perfect
//! destination address filtering is used.  If used in conjunction with \b
//! EMAC_FRMFILTER_HASH_AND_PERFECT, this flag indicates that the hash filter
//! should be used for incoming unicast packets along with the perfect filter.
//! - \b EMAC_FRMFILTER_PROMISCUOUS configures the MAC to operate in
//! promiscuous mode where all received frames are passed to the application
//! and the SA and DA filter status bits of the descriptor receive status word
//! are always cleared.
//!
//! Control frame filtering may be configured by ORing one of the following
//! values into \e ui32FilterOpts:
//!
//! - \b EMAC_FRMFILTER_PASS_NO_CTRL prevents any control frame from reaching
//! the application.
//! - \b EMAC_FRMFILTER_PASS_NO_PAUSE passes all control frames other than
//! PAUSE even if they fail the configured address filter.
//! - \b EMAC_FRMFILTER_PASS_ALL_CTRL passes all control frames, including
//! PAUSE even if they fail the configured address filter.
//! - \b EMAC_FRMFILTER_PASS_ADDR_CTRL passes all control frames only if they
//! pass the configured address filter.
//!
//! \return None.
//
//*****************************************************************************
void
EMACFrameFilterSet(uint32_t ui32Base, uint32_t ui32FilterOpts)
{
    ASSERT((ui32FilterOpts & ~VALID_FRMFILTER_FLAGS) == 0);

    //
    // Set the Ethernet MAC frame filter according to the flags passed.
    //
    HWREG(ui32Base + EMAC_O_FRAMEFLTR) =
        ((HWREG(ui32Base + EMAC_O_FRAMEFLTR) & ~VALID_FRMFILTER_FLAGS) |
         ui32FilterOpts);
}

//*****************************************************************************
//
//! Returns the current Ethernet frame filtering settings.
//!
//! \param ui32Base is the base address of the controller.
//!
//! This function may be called to retrieve the frame filtering configuration
//! set using a prior call to EMACFrameFilterSet().
//!
//! \return Returns a value comprising the logical OR of various flags
//! indicating the frame filtering options in use.  Possible flags are:
//!
//! - \b EMAC_FRMFILTER_RX_ALL indicates that the MAC to is configured to
//! pass all received frames regardless of whether or not they pass any
//! address filter that is configured.  The receive status word in the
//! relevant DMA descriptor is updated to indicate whether the configured
//! filter passed or failed for the frame.
//! - \b EMAC_FRMFILTER_VLAN indicates that the MAC is configured to drop any
//! frames which do not pass the VLAN tag comparison.
//! - \b EMAC_FRMFILTER_HASH_AND_PERFECT indicates that the MAC is configured
//! to pass frames if they match either the hash filter or the perfect filter.
//! If this flag is absent, frames passing based on the result of a single
//! filter, the perfect filter if \b EMAC_FRMFILTER_HASH_MULTICAST or
//! \b EMAC_FRMFILTER_HASH_UNICAST are clear or the hash filter otherwise.
//! - \b EMAC_FRMFILTER_SADDR indicates that the MAC is configured to drop
//! received frames when the source address field in the frame does not match
//! the values programmed into the enabled SA registers.
//! - \b EMAC_FRMFILTER_INV_SADDR enables inverse source address filtering.
//! When this option is specified, frames whose SA does not match the SA
//! registers are marked as passing the source address filter.
//! - \b EMAC_FRMFILTER_BROADCAST indicates that the MAC is configured to
//! discard all incoming broadcast frames.
//! - \b EMAC_FRMFILTER_PASS_MULTICAST indicates that the MAC is configured
//! to pass all incoming frames with multicast destinations addresses.
//! - \b EMAC_FRMFILTER_INV_DADDR indicates that the sense of the destination
//! address filtering for both unicast and multicast frames is inverted.
//! - \b EMAC_FRMFILTER_HASH_MULTICAST indicates that destination address
//! filtering of received multicast frames is enabled using the hash table.  If
//! absent, perfect destination address filtering is used.  If used in
//! conjunction with \b EMAC_FRMFILTER_HASH_AND_PERFECT, this flag indicates
//! that the hash filter should be used for incoming multicast packets along
//! with the perfect filter.
//! - \b EMAC_FRMFILTER_HASH_UNICAST indicates that destination address
//! filtering of received unicast frames is enabled using the hash table.  If
//! absent, perfect destination address filtering is used.  If used in
//! conjunction with \b EMAC_FRMFILTER_HASH_AND_PERFECT, this flag indicates
//! that the hash filter should be used for incoming unicast packets along with
//! the perfect filter.
//! - \b EMAC_FRMFILTER_PROMISCUOUS indicates that the MAC is configured to
//! operate in promiscuous mode where all received frames are passed to the
//! application and the SA and DA filter status bits of the descriptor receive
//! status word are always cleared.
//!
//! Control frame filtering configuration is indicated by one of the following
//! values which may be extracted from the returned value using the mask
//! \b EMAC_FRMFILTER_PASS_MASK:
//!
//! - \b EMAC_FRMFILTER_PASS_NO_CTRL prevents any control frame from reaching
//! the application.
//! - \b EMAC_FRMFILTER_PASS_NO_PAUSE passes all control frames other than
//! PAUSE even if they fail the configured address filter.
//! - \b EMAC_FRMFILTER_PASS_ALL_CTRL passes all control frames, including
//! PAUSE even if they fail the configured address filter.
//! - \b EMAC_FRMFILTER_PASS_ADDR_CTRL passes all control frames only if they
//! pass the configured address filter.
//
//*****************************************************************************
uint32_t
EMACFrameFilterGet(uint32_t ui32Base)
{
    //
    // Return the current MAC frame filter setting.
    //
    return(HWREG(ui32Base + EMAC_O_FRAMEFLTR) & VALID_FRMFILTER_FLAGS);
}

//*****************************************************************************
//
//! Sets the MAC address hash filter table.
//!
//! \param ui32Base is the base address of the controller.
//! \param ui32HashHi is the upper 32 bits of the current 64-bit hash filter
//! table to set.
//! \param ui32HashLo is the lower 32 bits of the current 64-bit hash filter
//! table to set.
//!
//! This function may be used to set the current 64-bit hash filter table
//! used by the MAC to filter incoming packets when hash filtering is enabled.
//! Hash filtering is enabled by passing \b EMAC_FRMFILTER_HASH_UNICAST
//! and/or EMAC_FRMFILTER_HASH_MULTICAST in the \e ui32FilterOpts parameter
//! to EMACFrameFilterSet().  The current hash filter may be retrieved
//! by calling EMACHashFilterGet().
//!
//! Hash table filtering allows many different MAC addresses to be filtered
//! simultaneously at the cost of some false-positive results (in the form of
//! packets passing the filter when their MAC address was not one of those
//! required).  A CRC of the packet source or destination MAC address is
//! calculated and the bottom 6 bits used as a bit index into the 64-bit
//! hash filter table.  If the bit in the hash table is set, the filter is
//! considered to have passed.  If the bit is clear, the filter fails and the
//! packet is rejected (assuming normal rather than inverse filtering is
//! configured).
//!
//! \return None.
//
//*****************************************************************************
void
EMACHashFilterSet(uint32_t ui32Base, uint32_t ui32HashHi, uint32_t ui32HashLo)
{
    // Set the hash table with the values provided.
    HWREG(ui32Base + EMAC_O_HASHTBLL) = ui32HashLo;
    HWREG(ui32Base + EMAC_O_HASHTBLH) = ui32HashHi;
}

//*****************************************************************************
//
//! Returns the current MAC address hash filter table.
//!
//! \param ui32Base is the base address of the controller.
//! \param pui32HashHi points to storage which will be written with the upper
//! 32 bits of the current 64-bit hash filter table.
//! \param pui32HashLo points to storage which will be written with the lower
//! 32 bits of the current 64-bit hash filter table.
//!
//! This function may be used to retrieve the current 64-bit hash filter table
//! from the MAC prior to making changes and setting the new hash filter via a
//! call to EMACHashFilterSet().
//!
//! Hash table filtering allows many different MAC addresses to be filtered
//! simultaneously at the cost of some false-positive results in the form of
//! packets passing the filter when their MAC address was not one of those
//! required.  A CRC of the packet source or destination MAC address is
//! calculated and the bottom 6 bits used as a bit index into the 64-bit
//! hash filter table.  If the bit in the hash table is set, the filter is
//! considered to have passed.  If the bit is clear, the filter fails and the
//! packet is rejected (assuming normal rather than inverse filtering is
//! configured).
//!
//! \return None.
//
//*****************************************************************************
void
EMACHashFilterGet(uint32_t ui32Base, uint32_t *pui32HashHi,
                  uint32_t *pui32HashLo)
{
    ASSERT(pui32HashHi);
    ASSERT(pui32HashLo);

    //
    // Get the current hash table values.
    //
    *pui32HashLo = HWREG(ui32Base + EMAC_O_HASHTBLL);
    *pui32HashHi = HWREG(ui32Base + EMAC_O_HASHTBLH);
}

//*****************************************************************************
//
//! Returns the bit number to set in the MAC hash filter corresponding to a
//! given MAC address.
//!
//! \param pui8MACAddr points to a buffer containing the 6 byte MAC address
//!  whose hash filter bit is to be determined.
//!
//! This function may be used to determine which bit in the MAC address hash
//! filter to set to describe a given 6 byte MAC address.  The returned value is
//! a 6 bit number where bit 5 indicates which of the two hash table words is
//! affected and the bottom 5 bits indicate the bit number to set within that
//! word.  For example, if 0x22 (100010b) is returned, this indicates that bit
//! 2 of word 1 (\e ui32HashHi as passed to EMACHashFilterSet()) must be set
//! to describe the passed MAC address.
//!
//! \return Returns the bit number to set in the MAC hash table to describe the
//! passed MAC address.
//
//*****************************************************************************
uint32_t
EMACHashFilterBitCalculate(uint8_t *pui8MACAddr)
{
    uint32_t ui32CRC, ui32Mask, ui32Loop;

    //
    // Parameter sanity check.
    //
    ASSERT(pui8MACAddr);

    //
    // Calculate the CRC for the MAC address.
    //
    ui32CRC = Crc32(0xFFFFFFFF, pui8MACAddr, 6);
    ui32CRC ^= 0xFFFFFFFF;

    //
    // Determine the hash bit to use from the calculated CRC.  This is the
    // top 6 bits of the reversed CRC (or the bottom 6 bits of the calculated
    // CRC with the bit order of those 6 bits reversed).
    //
    ui32Mask = 0;

    //
    // Reverse the order of the bottom 6 bits of the calculated CRC.
    //
    for(ui32Loop = 0; ui32Loop < 6; ui32Loop++)
    {
        ui32Mask <<= 1;
        ui32Mask |= (ui32CRC & 1);
        ui32CRC >>= 1;
    }

    //
    // Return the final hash table bit index.
    //
    return(ui32Mask);
}

//*****************************************************************************
//
//! Sets the receive interrupt watchdog timer period.
//!
//! \param ui32Base is the base address of the Ethernet controller.
//! \param ui8Timeout is the desired timeout expressed as a number of 256
//! system clock periods.
//!
//! This function configures the receive interrupt watchdog timer.
//! The \e uiTimeout parameter specifies the number of 256 system clock periods
//! that will elapse before the timer expires.  In cases where the DMA has
//! transferred a frame using a descriptor which has
//! \b DES1_RX_CTRL_DISABLE_INT set, the watchdog will cause a receive
//! interrupt to be triggered when it times out.  The watchdog timer is reset
//! whenever a packet is transferred to memory using a DMA descriptor which
//! does not disable the receive interrupt.
//!
//! To disable the receive interrupt watchdog function, set \e ui8Timeout to 0.
//!
//! \return None.
//
//*****************************************************************************
void
EMACRxWatchdogTimerSet(uint32_t ui32Base, uint8_t ui8Timeout)
{
    //
    // Set the receive interrupt watchdog timeout period.
    //
    HWREG(ui32Base + EMAC_O_RXINTWDT) = (uint32_t)ui8Timeout;
}

//*****************************************************************************
//
//! Returns the current Ethernet MAC status.
//!
//! \param ui32Base is the base address of the Ethernet controller.
//!
//! This function returns information on the current status of all the main
//! modules in the MAC transmit and receive data paths.
//!
//! \return Returns the current MAC status as a logical OR of any of the
//! following flags:
//!
//! - \b EMAC_STATUS_TX_NOT_EMPTY
//! - \b EMAC_STATUS_TX_WRITING_FIFO
//! - \b EMAC_STATUS_TX_PAUSED
//! - \b EMAC_STATUS_MAC_NOT_IDLE
//! - \b EMAC_STATUS_RWC_ACTIVE
//! - \b EMAC_STATUS_RPE_ACTIVE
//!
//! The transmit frame controller status will be one of the following.  This
//! can be extracted from the returned value by ANDing with
//! \b EMAC_STATUS_TFC_STATE_MASK:
//!
//! - \b EMAC_STATUS_TFC_STATE_IDLE
//! - \b EMAC_STATUS_TFC_STATE_WAITING
//! - \b EMAC_STATUS_TFC_STATE_PAUSING
//! - \b EMAC_STATUS_TFC_STATE_WRITING
//!
//! The transmit FIFO read controller status will be one of the following.
//! This can be extracted from the returned value by ANDing with
//! \b EMAC_STATUS_TRC_STATE_MASK:
//!
//! - \b EMAC_STATUS_TRC_STATE_IDLE
//! - \b EMAC_STATUS_TRC_STATE_READING
//! - \b EMAC_STATUS_TRC_STATE_WAITING
//! - \b EMAC_STATUS_TRC_STATE_STATUS
//!
//! The current receive FIFO level will be one of the following.  This can be
//! extracted from the returned value by ANDing with
//! \b EMAC_STATUS_RX_FIFO_LEVEL_MASK:
//!
//! - \b EMAC_STATUS_RX_FIFO_EMPTY indicating that the FIFO is empty.
//! - \b EMAC_STATUS_RX_FIFO_BELOW indicating that the FIFO fill level is
//! below the flow-control deactivate threshold.
//! - \b EMAC_STATUS_RX_FIFO_ABOVE indicating that the FIFO fill level is
//! above the flow=control activate threshold.
//! - \b EMAC_STATUS_RX_FIFO_FULL indicating that the FIFO is full.
//!
//! The current receive FIFO state will be one of the following.  This can be
//! extracted from the returned value by ANDing with
//! \b EMAC_STATUS_RX_FIFO_STATE_MASK:
//!
//! - \b EMAC_STATUS_RX_FIFO_IDLE
//! - \b EMAC_STATUS_RX_FIFO_READING
//! - \b EMAC_STATUS_RX_FIFO_STATUS
//! - \b EMAC_STATUS_RX_FIFO_FLUSHING
//
//*****************************************************************************
uint32_t
EMACStatusGet(uint32_t ui32Base)
{
    //
    // Read and return the MAC status register content.
    //
    return(HWREG(ui32Base + EMAC_O_STATUS));
}

//*****************************************************************************
//
//! Orders the MAC DMA controller to attempt to acquire the next transmit
//! descriptor.
//!
//! \param ui32Base is the base address of the Ethernet controller.
//!
//! This function must be called to restart the transmitter if it has been
//! suspended due to the current transmit DMA descriptor being owned by the
//! host.  Once the application writes new values to the descriptor and marks
//! it as being owned by the MAC DMA, this function will cause the hardware to
//! attempt to acquire the descriptor and start transmission of the new
//! data.
//!
//! \return None.
//
//*****************************************************************************
void
EMACTxDMAPollDemand(uint32_t ui32Base)
{
    //
    // Any write to the MACTXPOLLD register causes the transmit DMA to attempt
    // to resume.
    //
    HWREG(ui32Base + EMAC_O_TXPOLLD) = 0;
}

//*****************************************************************************
//
//! Orders the MAC DMA controller to attempt to acquire the next receive
//! descriptor.
//!
//! \param ui32Base is the base address of the Ethernet controller.
//!
//! This function must be called to restart the receiver if it has been
//! suspended due to the current receive DMA descriptor being owned by the
//! host.  Once the application reads any data from the descriptor and marks
//! it as being owned by the MAC DMA, this function will cause the hardware to
//! attempt to acquire the descriptor before writing the next received packet
//! into its buffer(s).
//!
//! \return None.
//
//*****************************************************************************
void
EMACRxDMAPollDemand(uint32_t ui32Base)
{
    //
    // Any write to the MACRXPOLLD register causes the receive DMA to attempt
    // to resume.
    //
    HWREG(ui32Base + EMAC_O_RXPOLLD) = 0;
}

//*****************************************************************************
//
//! Sets the DMA receive descriptor list pointer.
//!
//! \param ui32Base is the base address of the controller.
//! \param pDescriptor points to the first DMA descriptor in the list to
//! be passed to the receive DMA engine.
//!
//! This function sets the Ethernet MAC's receive DMA descriptor list pointer.
//! The \e pDescriptor pointer must point to one or more descriptor
//! structures.
//!
//! When multiple descriptors are provided, they can be either chained or
//! unchained.  Chained descriptors are indicated by setting the flag
//! \b DES0_TX_CTRL_CHAINED or \b DES1_RX_CTRL_CHAINED bits in the relevant
//! word of the transmit or receive descriptor.  If this bit is clear,
//! unchained descriptors are assumed.
//!
//! Chained descriptors use a link pointer in each descriptor to
//! point to the next descriptor in the chain.
//!
//! Unchained descriptors are assumed to be contiguous in memory with a
//! consistent offset between the start of one descriptor and the next.
//! If unchained descriptors are used, the \e pvLink field in the descriptor
//! becomes available to store a second buffer pointer, allowing each
//! descriptor to point to two buffers rather than one.  In this case,
//! the \e ui32DescSkipSize parameter to EMACInit() must previously have
//! been set to the number of words between the end of one descriptor and
//! the start of the next.  This value must be 0 in cases where a packed array
//! of \b tEMACDMADescriptor structures is used. If the application wishes to
//! add new state fields to the end of the descriptor structure, the skip size
//! should be set to accommodate the newly sized structure.
//!
//! Applications are responsible for initializing all descriptor fields
//! appropriately before passing the descriptor list to the hardware.
//!
//! \return None.
//
//*****************************************************************************
void
EMACRxDMADescriptorListSet(uint32_t ui32Base, tEMACDMADescriptor *pDescriptor)
{
    //
    // Parameter sanity check.
    //
    ASSERT(pDescriptor);
    ASSERT(((uint32_t)pDescriptor & 3) == 0);

    //
    // Write the supplied address to the MACRXDLADDR register.
    //
    HWREG(ui32Base + EMAC_O_RXDLADDR) = (uint32_t)pDescriptor;
}

//*****************************************************************************
//
//! Returns a pointer to the start of the DMA receive descriptor list.
//!
//! \param ui32Base is the base address of the controller.
//!
//! This function returns a pointer to the head of the Ethernet MAC's receive
//! DMA descriptor list.  This value will correspond to the pointer originally
//! set using a call to EMACRxDMADescriptorListSet().
//!
//! \return Returns a pointer to the start of the DMA receive descriptor list.
//
//*****************************************************************************
tEMACDMADescriptor *
EMACRxDMADescriptorListGet(uint32_t ui32Base)
{
    //
    // Return the current receive DMA descriptor list pointer.
    //
    return((tEMACDMADescriptor *)HWREG(ui32Base + EMAC_O_RXDLADDR));
}

//*****************************************************************************
//
//! Returns the current DMA receive descriptor pointer.
//!
//! \param ui32Base is the base address of the controller.
//!
//! This function returns a pointer to the current Ethernet receive descriptor
//! read by the DMA.
//!
//! \return Returns a pointer to the start of the current receive DMA
//! descriptor.
//
//*****************************************************************************
tEMACDMADescriptor *
EMACRxDMACurrentDescriptorGet(uint32_t ui32Base)
{
    //
    // Return the address of the current receive descriptor written by the DMA.
    //
    return((tEMACDMADescriptor *)HWREG(ui32Base + EMAC_O_HOSRXDESC));
}

//*****************************************************************************
//
//! Returns the current DMA receive buffer pointer.
//!
//! \param ui32Base is the base address of the controller.
//!
//! This function may be called to determine which buffer the receive DMA
//! engine is currently writing to.
//!
//! \return Returns the receive buffer address currently being written by
//! the DMA engine.
//
//*****************************************************************************
uint8_t *
EMACRxDMACurrentBufferGet(uint32_t ui32Base)
{
    //
    // Return the receive buffer address currently being written by the DMA.
    //
    return((uint8_t *)HWREG(ui32Base + EMAC_O_HOSRXBA));
}

//*****************************************************************************
//
//! Sets the DMA transmit descriptor list pointer.
//!
//! \param ui32Base is the base address of the controller.
//! \param pDescriptor points to the first DMA descriptor in the list to
//! be passed to the transmit DMA engine.
//!
//! This function sets the Ethernet MAC's transmit DMA descriptor list pointer.
//! The \e pDescriptor pointer must point to one or more descriptor
//! structures.
//!
//! When multiple descriptors are provided, they can be either chained or
//! unchained.  Chained descriptors are indicated by setting the flag
//! \b DES0_TX_CTRL_CHAINED or \b DES1_RX_CTRL_CHAINED bits in the relevant
//! word of the transmit or receive descriptor.  If this bit is clear,
//! unchained descriptors are assumed.
//!
//! Chained descriptors use a link pointer in each descriptor to
//! point to the next descriptor in the chain.
//!
//! Unchained descriptors are assumed to be contiguous in memory with a
//! consistent offset between the start of one descriptor and the next.
//! If unchained descriptors are used, the \e pvLink field in the descriptor
//! becomes available to store a second buffer pointer, allowing each
//! descriptor to point to two buffers rather than one.  In this case,
//! the \e ui32DescSkipSize parameter to EMACInit() must previously have
//! been set to the number of words between the end of one descriptor and
//! the start of the next.  This value must be 0 in cases where a packed array
//! of \b tEMACDMADescriptor structures is used. If the application wishes to
//! add new state fields to the end of the descriptor structure, the skip size
//! should be set to accommodate the newly sized structure.
//!
//! Applications are responsible for initializing all descriptor fields
//! appropriately before passing the descriptor list to the hardware.
//!
//! \return None.
//
//*****************************************************************************
void
EMACTxDMADescriptorListSet(uint32_t ui32Base, tEMACDMADescriptor *pDescriptor)
{
    //
    // Parameter sanity check.
    //
    ASSERT(pDescriptor);
    ASSERT(((uint32_t)pDescriptor & 3) == 0);

    //
    // Write the supplied address to the MACTXDLADDR register.
    //
    HWREG(ui32Base + EMAC_O_TXDLADDR) = (uint32_t)pDescriptor;
}

//*****************************************************************************
//
//! Returns a pointer to the start of the DMA transmit descriptor list.
//!
//! \param ui32Base is the base address of the controller.
//!
//! This function returns a pointer to the head of the Ethernet MAC's transmit
//! DMA descriptor list.  This value will correspond to the pointer originally
//! set using a call to EMACTxDMADescriptorListSet().
//!
//! \return Returns a pointer to the start of the DMA transmit descriptor list.
//
//*****************************************************************************
tEMACDMADescriptor *
EMACTxDMADescriptorListGet(uint32_t ui32Base)
{
    //
    // Return the current transmit DMA descriptor list pointer.
    //
    return((tEMACDMADescriptor *)HWREG(ui32Base + EMAC_O_TXDLADDR));
}

//*****************************************************************************
//
//! Returns the current DMA transmit descriptor pointer.
//!
//! \param ui32Base is the base address of the controller.
//!
//! This function returns a pointer to the current Ethernet transmit descriptor
//! read by the DMA.
//!
//! \return Returns a pointer to the start of the current transmit DMA
//! descriptor.
//
//*****************************************************************************
tEMACDMADescriptor *
EMACTxDMACurrentDescriptorGet(uint32_t ui32Base)
{
    //
    // Return the address of the current transmit descriptor read by the DMA.
    //
    return((tEMACDMADescriptor *)HWREG(ui32Base + EMAC_O_HOSTXDESC));
}

//*****************************************************************************
//
//! Returns the current DMA transmit buffer pointer.
//!
//! \param ui32Base is the base address of the controller.
//!
//! This function may be called to determine which buffer the transmit DMA
//! engine is currently reading from.
//!
//! \return Returns the transmit buffer address currently being read by the
//! DMA engine.
//
//*****************************************************************************
uint8_t *
EMACTxDMACurrentBufferGet(uint32_t ui32Base)
{
    //
    // Return the transmit buffer address currently being read by the DMA.
    //
    return((uint8_t *)HWREG(ui32Base + EMAC_O_HOSTXBA));
}

//*****************************************************************************
//
//! Returns the current states of the Ethernet MAC transmit and receive DMA
//! engines.
//!
//! \param ui32Base is the base address of the controller.
//!
//! This function may be used to query the current states of the transmit and
//! receive DMA engines.  The return value contains two fields, one providing
//! the transmit state and the other the receive state.  Macros
//! \b EMAC_TX_DMA_STATE() and \b EMAC_RX_DMA_STATE() may be used to
//! extract these fields from the returned value.  Alternatively, masks
//! \b EMAC_DMA_TXSTAT_MASK and \b EMAC_DMA_RXSTAT_MASK may be used
//! directly to mask out the individual states from the returned value.
//!
//! \return Returns the states of the transmit and receive DMA engines.  These
//! states are ORed together into a single word containing one of:
//!
//! - \b EMAC_DMA_TXSTAT_STOPPED indicating that the transmit engine is
//! stopped.
//! - \b EMAC_DMA_TXSTAT_RUN_FETCH_DESC indicating that the transmit engine
//! is fetching the next descriptor.
//! - \b EMAC_DMA_TXSTAT_RUN_WAIT_STATUS indicating that the transmit engine
//! is waiting for status from the MAC.
//! - \b EMAC_DMA_TXSTAT_RUN_READING indicating that the transmit engine is
//! currently transferring data from memory to the MAC transmit FIFO.
//! - \b EMAC_DMA_TXSTAT_RUN_CLOSE_DESC indicating that the transmit engine
//! is closing the descriptor after transmission of the buffer data.
//! - \b EMAC_DMA_TXSTAT_TS_WRITE indicating that the transmit engine is
//! currently writing timestamp information to the descriptor.
//! - \b EMAC_DMA_TXSTAT_SUSPENDED indicating that the transmit engine is
//! suspended due to the next descriptor being unavailable (owned by the host)
//! or a transmit buffer underflow.
//!
//! and one of:
//!
//! - \b EMAC_DMA_RXSTAT_STOPPED indicating that the receive engine is
//! stopped.
//! - \b EMAC_DMA_RXSTAT_RUN_FETCH_DESC indicating that the receive engine
//! is fetching the next descriptor.
//! - \b EMAC_DMA_RXSTAT_RUN_WAIT_PACKET indicating that the receive engine
//! is waiting for the next packet.
//! - \b EMAC_DMA_RXSTAT_SUSPENDED indicating that the receive engine is
//! suspended due to the next descriptor being unavailable.
//! - \b EMAC_DMA_RXSTAT_RUN_CLOSE_DESC indicating that the receive engine
//! is closing the descriptor after receiving a buffer of data.
//! - \b EMAC_DMA_RXSTAT_TS_WRITE indicating that the transmit engine is
//! currently writing timestamp information to the descriptor.
//! - \b EMAC_DMA_RXSTAT_RUN_RECEIVING indicating that the receive engine is
//! currently transferring data from the MAC receive FIFO to memory.
//!
//! Additionally, a DMA bus error may be signaled using \b EMAC_DMA_ERROR.
//! If this flag is present, the source of the error is identified using one
//! of the following values which may be extracted from the return value using
//! \b EMAC_DMA_ERR_MASK:
//!
//! - \b EMAC_DMA_ERR_RX_DATA_WRITE indicates that an error occurred when
//! writing received data to memory.
//! - \b EMAC_DMA_ERR_TX_DATA_READ indicates that an error occurred when
//! reading data from memory for transmission.
//! - \b EMAC_DMA_ERR_RX_DESC_WRITE indicates that an error occurred when
//! writing to the receive descriptor.
//! - \b EMAC_DMA_ERR_TX_DESC_WRITE indicates that an error occurred when
//! writing to the transmit descriptor.
//! - \b EMAC_DMA_ERR_RX_DESC_READ indicates that an error occurred when
//! reading the receive descriptor.
//! - \b EMAC_DMA_ERR_TX_DESC_READ indicates that an error occurred when
//! reading the transmit descriptor.
//
//*****************************************************************************
uint32_t
EMACDMAStateGet(uint32_t ui32Base)
{
    //
    // Return the status of the DMA channels.
    //
    return(HWREG(ui32Base + EMAC_O_DMARIS) &
           (EMAC_DMARIS_FBI | EMAC_DMARIS_AE_M | EMAC_DMARIS_RS_M |
            EMAC_DMARIS_TS_M));
}

//*****************************************************************************
//
//! Flushes the Ethernet controller transmit FIFO.
//!
//! \param ui32Base is the base address of the controller.
//!
//! This function will flush any data currently held in the Ethernet transmit
//! FIFO.  Data which has already been passed to the MAC for transmission will
//! be transmitted possibly resulting in a transmit underflow or runt frame
//! transmission.
//!
//! \return None.
//
//*****************************************************************************
void
EMACTxFlush(uint32_t ui32Base)
{
    //
    // Check to make sure that the FIFO is not already empty.
    //
    if(HWREG(ui32Base + EMAC_O_STATUS) & EMAC_STATUS_TXFE)
    {
        //
        // Flush the transmit FIFO since it is not currently empty.
        //
        HWREG(ui32Base + EMAC_O_DMAOPMODE) |= EMAC_DMAOPMODE_FTF;

        //
        // Wait for the flush to complete.
        //
        while(HWREG(ui32Base + EMAC_O_DMAOPMODE) & EMAC_DMAOPMODE_FTF)
        {
        }
    }
}

//*****************************************************************************
//
//! Enables the Ethernet controller transmitter.
//!
//! \param ui32Base is the base address of the controller.
//!
//! When starting operations on the Ethernet interface, this function should
//! be called to enable the transmitter after all configuration has been
//! completed.
//!
//! \return None.
//
//*****************************************************************************
void
EMACTxEnable(uint32_t ui32Base)
{
    //
    // Enable the MAC transmit path in the opmode register.
    //
    HWREG(ui32Base + EMAC_O_DMAOPMODE) |= EMAC_DMAOPMODE_ST;

    //
    // Enable transmission in the MAC configuration register.
    //
    HWREG(ui32Base + EMAC_O_CFG) |= EMAC_CFG_TE;
}

//*****************************************************************************
//
//! Disables the Ethernet controller transmitter.
//!
//! \param ui32Base is the base address of the controller.
//!
//! When terminating operations on the Ethernet interface, this function should
//! be called.  This function disables the transmitter.
//!
//! \return None.
//
//*****************************************************************************
void
EMACTxDisable(uint32_t ui32Base)
{
    //
    // Disable transmission in the MAC configuration register.
    //
    HWREG(ui32Base + EMAC_O_CFG) &= ~EMAC_CFG_TE;

    //
    // Disable the MAC transmit path in the opmode register.
    //
    HWREG(ui32Base + EMAC_O_DMAOPMODE) &= ~EMAC_DMAOPMODE_ST;
}

//*****************************************************************************
//
//! Enables the Ethernet controller receiver.
//!
//! \param ui32Base is the base address of the controller.
//!
//! When starting operations on the Ethernet interface, this function should
//! be called to enable the receiver after all configuration has been
//! completed.
//!
//! \return None.
//
//*****************************************************************************
void
EMACRxEnable(uint32_t ui32Base)
{
    //
    // Enable the MAC receive path.
    //
    HWREG(ui32Base + EMAC_O_DMAOPMODE) |= EMAC_DMAOPMODE_SR;

    //
    // Enable receive in the MAC configuration register.
    //
    HWREG(ui32Base + EMAC_O_CFG) |= EMAC_CFG_RE;
}

//*****************************************************************************
//
//! Disables the Ethernet controller receiver.
//!
//! \param ui32Base is the base address of the controller.
//!
//! When terminating operations on the Ethernet interface, this function should
//! be called.  This function disables the receiver.
//!
//! \return None.
//
//*****************************************************************************
void
EMACRxDisable(uint32_t ui32Base)
{
    //
    // Disable reception in the MAC configuration register.
    //
    HWREG(ui32Base + EMAC_O_CFG) &= ~EMAC_CFG_RE;

    //
    // Disable the MAC receive path.
    //
    HWREG(ui32Base + EMAC_O_DMAOPMODE) &= ~EMAC_DMAOPMODE_SR;
}

//*****************************************************************************
//
//! Registers an interrupt handler for an Ethernet interrupt.
//!
//! \param ui32Base is the base address of the controller.
//! \param pfnHandler is a pointer to the function to be called when the
//! enabled Ethernet interrupts occur.
//!
//! This function sets the handler to be called when the Ethernet interrupt
//! occurs.  This function enables the global interrupt in the interrupt
//! controller; specific Ethernet interrupts must be enabled via
//! EMACIntEnable().  It is the interrupt handler's responsibility to clear
//! the interrupt source.
//!
//! \sa IntRegister() for important information about registering interrupt
//! handlers.
//!
//! \return None.
//
//*****************************************************************************
void
EMACIntRegister(uint32_t ui32Base, void (*pfnHandler)(void))
{
    //
    // Check the arguments.
    //
    ASSERT(pfnHandler != 0);

    //
    // Register the interrupt handler.
    //
    IntRegister(INT_EMAC0_SNOWFLAKE, pfnHandler);

    //
    // Enable the Ethernet interrupt.
    //
    IntEnable(INT_EMAC0_SNOWFLAKE);
}

//*****************************************************************************
//
//! Unregisters an interrupt handler for an Ethernet interrupt.
//!
//! \param ui32Base is the base address of the controller.
//!
//! This function unregisters the interrupt handler.  This function disables
//! the global interrupt in the interrupt controller so that the interrupt
//! handler is no longer called.
//!
//! \sa IntRegister() for important information about registering interrupt
//! handlers.
//!
//! \return None.
//
//*****************************************************************************
void
EMACIntUnregister(uint32_t ui32Base)
{
    //
    // Disable the interrupt.
    //
    IntDisable(INT_EMAC0_SNOWFLAKE);

    //
    // Unregister the interrupt handler.
    //
    IntUnregister(INT_EMAC0_SNOWFLAKE);
}

//*****************************************************************************
//
//! Enables individual Ethernet MAC interrupt sources.
//!
//! \param ui32Base is the base address of the Ethernet MAC.
//! \param ui32IntFlags is the bit mask of the interrupt sources to be enabled.
//!
//! This function enables the indicated Ethernet MAC interrupt sources.  Only
//! the sources that are enabled can be reflected to the processor interrupt;
//! disabled sources have no effect on the processor.
//!
//! The \e ui32IntFlags parameter is the logical OR of any of the following:
//!
//! - \b EMAC_INT_PHY indicates that the PHY has signaled a change of state.
//! Software must read and write the appropriate PHY registers to enable and
//! disable particular notifications.
//! - \b EMAC_INT_EARLY_RECEIVE indicates that the DMA engine has filled the
//! first data buffer of a packet.
//! - \b EMAC_INT_BUS_ERROR indicates that a fatal bus error has occurred and
//! that the DMA engine has been disabled.
//! - \b EMAC_INT_EARLY_TRANSMIT indicates that a frame to be transmitted has
//! been fully written from memory into the MAC transmit FIFO.
//! - \b EMAC_INT_RX_WATCHDOG indicates that a frame with length greater than
//! 2048 bytes (of 10240 bytes in Jumbo Frame mode) was received.
//! - \b EMAC_INT_RX_STOPPED indicates that the receive process has entered
//! the stopped state.
//! - \b EMAC_INT_RX_NO_BUFFER indicates that the host owns the next buffer
//! in the DMA's receive descriptor list and the DMA cannot, therefore, acquire
//! a buffer.  The receive process is suspended and can be resumed by changing
//! the descriptor ownership and calling EMACRxDMAPollDemand().
//! - \b EMAC_INT_RECEIVE indicates that reception of a frame has completed
//! and all requested status has been written to the appropriate DMA receive
//! descriptor.
//! - \b EMAC_INT_TX_UNDERFLOW indicates that the transmitter experienced an
//! underflow during transmission.  The transmit process is suspended.
//! - \b EMAC_INT_RX_OVERFLOW indicates that an overflow was experienced
//! during reception.
//! - \b EMAC_INT_TX_JABBER indicates that the transmit jabber timer expired.
//! This happens when the frame size exceeds 2048 bytes (or 10240 bytes in
//! Jumbo Frame mode) and causes the transmit process to abort and enter the
//! Stopped state.
//! - \b EMAC_INT_TX_NO_BUFFER indicates that the host owns the next buffer
//! in the DMA's transmit descriptor list and that the DMA cannot, therefore,
//! acquire a buffer.  Transmission is suspended and can be resumed by changing
//! the descriptor ownership and calling EMACTxDMAPollDemand().
//! - \b EMAC_INT_TX_STOPPED indicates that the transmit process has stopped.
//! - \b EMAC_INT_TRANSMIT indicates that transmission of a frame has
//! completed and that all requested status has been updated in the descriptor.
//!
//! Summary interrupt bits \b EMAC_INT_NORMAL_INT and
//! \b EMAC_INT_ABNORMAL_INT are enabled automatically by the driver if any
//! of their constituent sources are enabled.  Applications do not need to
//! explicitly enable these bits.
//!
//! \note Timestamp-related interrupts from the IEEE-1588 module must be
//! enabled independently by using a call to EMACTimestampTargetIntEnable().
//!
//! \return None.
//
//*****************************************************************************
void
EMACIntEnable(uint32_t ui32Base, uint32_t ui32IntFlags)
{
    //
    // Parameter sanity check.
    //
    ASSERT((ui32IntFlags & ~EMAC_MASKABLE_INTS) == 0);

    //
    // Enable the normal interrupt if any of its individual sources are
    // enabled.
    //
    if(ui32IntFlags & EMAC_NORMAL_INTS)
    {
        ui32IntFlags |= EMAC_INT_NORMAL_INT;
    }

    //
    // Similarly, enable the abnormal interrupt if any of its individual
    // sources are enabled.
    //
    if(ui32IntFlags & EMAC_ABNORMAL_INTS)
    {
        ui32IntFlags |= EMAC_INT_ABNORMAL_INT;
    }

    //
    // Set the MAC DMA interrupt mask appropriately if any of the sources
    // we've been asked to enable are found in that register.
    //
    if(ui32IntFlags & ~EMAC_INT_PHY)
    {
        HWREG(ui32Base + EMAC_O_DMAIM) |= ui32IntFlags & ~EMAC_INT_PHY;
    }

    //
    // Enable the PHY interrupt if we've been asked to do this.
    //
    if(ui32IntFlags & EMAC_INT_PHY)
    {
        HWREG(ui32Base + EMAC_O_EPHYIM) |= EMAC_EPHYIM_INT;
    }
}

//*****************************************************************************
//
//! Disables individual Ethernet MAC interrupt sources.
//!
//! \param ui32Base is the base address of the Ethernet MAC.
//! \param ui32IntFlags is the bit mask of the interrupt sources to be disabled.
//!
//! This function disables the indicated Ethernet MAC interrupt sources.
//!
//! The \e ui32IntFlags parameter is the logical OR of any of the following:
//!
//! - \b EMAC_INT_PHY indicates that the PHY has signaled a change of state.
//! Software must read and write the appropriate PHY registers to enable and
//! disable particular notifications.
//! - \b EMAC_INT_EARLY_RECEIVE indicates that the DMA engine has filled the
//! first data buffer of a packet.
//! - \b EMAC_INT_BUS_ERROR indicates that a fatal bus error has occurred and
//! that the DMA engine has been disabled.
//! - \b EMAC_INT_EARLY_TRANSMIT indicates that a frame to be transmitted has
//! been fully written from memory into the MAC transmit FIFO.
//! - \b EMAC_INT_RX_WATCHDOG indicates that a frame with length greater than
//! 2048 bytes (of 10240 bytes in Jumbo Frame mode) was received.
//! - \b EMAC_INT_RX_STOPPED indicates that the receive process has entered
//! the stopped state.
//! - \b EMAC_INT_RX_NO_BUFFER indicates that the host owns the next buffer
//! in the DMA's receive descriptor list and the DMA cannot, therefore, acquire
//! a buffer.  The receive process is suspended and can be resumed by changing
//! the descriptor ownership and calling EMACRxDMAPollDemand().
//! - \b EMAC_INT_RECEIVE indicates that reception of a frame has completed
//! and all requested status has been written to the appropriate DMA receive
//! descriptor.
//! - \b EMAC_INT_TX_UNDERFLOW indicates that the transmitter experienced an
//! underflow during transmission.  The transmit process is suspended.
//! - \b EMAC_INT_RX_OVERFLOW indicates that an overflow was experienced
//! during reception.
//! - \b EMAC_INT_TX_JABBER indicates that the transmit jabber timer expired.
//! This happens when the frame size exceeds 2048 bytes (or 10240 bytes in
//! Jumbo Frame mode) and causes the transmit process to abort and enter the
//! Stopped state.
//! - \b EMAC_INT_TX_NO_BUFFER indicates that the host owns the next buffer
//! in the DMA's transmit descriptor list and that the DMA cannot, therefore,
//! acquire a buffer.  Transmission is suspended and can be resumed by changing
//! the descriptor ownership and calling EMACTxDMAPollDemand().
//! - \b EMAC_INT_TX_STOPPED indicates that the transmit process has stopped.
//! - \b EMAC_INT_TRANSMIT indicates that transmission of a frame has
//! completed and that all requested status has been updated in the descriptor.
//! - \b EMAC_INT_TIMESTAMP indicates that an interrupt from the timestamp
//! module has occurred.  This precise source of the interrupt can be
//! determined by calling EMACTimestampIntStatus() which will also clear
//! this bit.
//!
//! Summary interrupt bits \b EMAC_INT_NORMAL_INT and
//! \b EMAC_INT_ABNORMAL_INT are disabled automatically by the driver if none
//! of their constituent sources are enabled.  Applications do not need to
//! explicitly disable these bits.
//!
//! \note Timestamp-related interrupts from the IEEE-1588 module must be
//! disabled independently by using a call to EMACTimestampTargetIntDisable().
//!
//! \return None.
//
//*****************************************************************************
void
EMACIntDisable(uint32_t ui32Base, uint32_t ui32IntFlags)
{
    uint32_t ui32Mask;

    //
    // Parameter sanity check.
    //
    ASSERT(ui32Base == EMAC0_BASE);
    ASSERT((ui32IntFlags & ~EMAC_MASKABLE_INTS) == 0);

    //
    // Get the current interrupt mask.
    //
    ui32Mask = HWREG(ui32Base + EMAC_O_DMAIM);

    //
    // Clear the requested bits.
    //
    ui32Mask &= ~(ui32IntFlags & ~EMAC_INT_PHY);

    //
    // If none of the normal interrupt sources are enabled, disable the
    // normal interrupt.
    //
    if(!(ui32Mask & EMAC_NORMAL_INTS))
    {
        ui32Mask &= ~EMAC_INT_NORMAL_INT;
    }

    //
    // Similarly, if none of the abnormal interrupt sources are enabled,
    // disable the abnormal interrupt.
    //
    if(!(ui32Mask & EMAC_ABNORMAL_INTS))
    {
        ui32Mask &= ~EMAC_INT_ABNORMAL_INT;
    }

    //
    // Write the new mask back to the hardware.
    //
    HWREG(ui32Base + EMAC_O_DMAIM) = ui32Mask;

    //
    // Disable the PHY interrupt if we've been asked to do this.
    //
    if(ui32IntFlags & EMAC_INT_PHY)
    {
        HWREG(ui32Base + EMAC_O_EPHYIM) &= ~EMAC_EPHYIM_INT;
    }
}

//*****************************************************************************
//
//! Gets the current Ethernet MAC interrupt status.
//!
//! \param ui32Base is the base address of the Ethernet MAC.
//! \param bMasked is \b true to return the masked interrupt status or \b false
//! to return the unmasked status.
//!
//! This function returns the interrupt status for the Ethernet MAC.  Either
//! the raw interrupt status or the status of interrupts that are allowed
//! to reflect to the processor can be returned.
//!
//! \return Returns the current interrupt status as the logical OR of any of
//! the following:
//!
//! - \b EMAC_INT_PHY indicates that the PHY interrupt has occurred.
//! Software must read the relevant PHY interrupt status register to determine
//! the cause.
//! - \b EMAC_INT_EARLY_RECEIVE indicates that the DMA engine has filled the
//! first data buffer of a packet.
//! - \b EMAC_INT_BUS_ERROR indicates that a fatal bus error has occurred and
//! that the DMA engine has been disabled.  The cause of the error can be
//! determined by calling EMACDMAStateGet().
//! - \b EMAC_INT_EARLY_TRANSMIT indicates that a frame to be transmitted has
//! been fully written from memory into the MAC transmit FIFO.
//! - \b EMAC_INT_RX_WATCHDOG indicates that a frame with length greater than
//! 2048 bytes (of 10240 bytes in Jumbo Frame mode) was received.
//! - \b EMAC_INT_RX_STOPPED indicates that the receive process has entered
//! the stopped state.
//! - \b EMAC_INT_RX_NO_BUFFER indicates that the host owns the next buffer
//! in the DMA's receive descriptor list and the DMA cannot, therefore, acquire
//! a buffer.  The receive process is suspended and can be resumed by changing
//! the descriptor ownership and calling EMACRxDMAPollDemand().
//! - \b EMAC_INT_RECEIVE indicates that reception of a frame has completed
//! and all requested status has been written to the appropriate DMA receive
//! descriptor.
//! - \b EMAC_INT_TX_UNDERFLOW indicates that the transmitter experienced an
//! underflow during transmission.  The transmit process is suspended.
//! - \b EMAC_INT_RX_OVERFLOW indicates that an overflow was experienced
//! during reception.
//! - \b EMAC_INT_TX_JABBER indicates that the transmit jabber timer expired.
//! This happens when the frame size exceeds 2048 bytes (or 10240 bytes in
//! Jumbo Frame mode) and causes the transmit process to abort and enter the
//! Stopped state.
//! - \b EMAC_INT_TX_NO_BUFFER indicates that the host owns the next buffer
//! in the DMA's transmit descriptor list and that the DMA cannot, therefore,
//! acquire a buffer.  Transmission is suspended and can be resumed by changing
//! the descriptor ownership and calling EMACTxDMAPollDemand().
//! - \b EMAC_INT_TX_STOPPED indicates that the transmit process has stopped.
//! - \b EMAC_INT_TRANSMIT indicates that transmission of a frame has
//! completed and that all requested status has been updated in the descriptor.
//! - \b EMAC_INT_NORMAL_INT is a summary interrupt comprising the logical
//! OR of the masked state of \b EMAC_INT_TRANSMIT, \b EMAC_INT_RECEIVE,
//! \b EMAC_INT_TX_NO_BUFFER and \b EMAC_INT_EARLY_RECEIVE.
//! - \b EMAC_INT_ABNORMAL_INT is a summary interrupt comprising the logical
//! OR of the masked state of \b EMAC_INT_TX_STOPPED, \b EMAC_INT_TX_JABBER,
//! \b EMAC_INT_RX_OVERFLOW, \b EMAC_INT_TX_UNDERFLOW,
//! \b EMAC_INT_RX_NO_BUFFER, \b EMAC_INT_RX_STOPPED,
//! \b EMAC_INT_RX_WATCHDOG, \b EMAC_INT_EARLY_TRANSMIT and
//! \b EMAC_INT_BUS_ERROR.
//
//*****************************************************************************
uint32_t
EMACIntStatus(uint32_t ui32Base, bool bMasked)
{
    uint32_t ui32Val, ui32PHYStat;

    //
    // Parameter sanity check.
    //
    ASSERT(ui32Base == EMAC0_BASE);

    //
    // Get the unmasked interrupt status and clear any unwanted status fields.
    //
    ui32Val = HWREG(ui32Base + EMAC_O_DMARIS);
    ui32Val &= ~(EMAC_DMARIS_AE_M | EMAC_DMARIS_TS_M | EMAC_DMARIS_RS_M);

    //
    // This peripheral doesn't have a masked interrupt status register
    // so perform the masking manually.  Note that only the bottom 16 bits
    // of the register can be masked so make sure we take this into account.
    //
    if(bMasked)
    {
        ui32Val &= (EMAC_NON_MASKED_INTS | HWREG(ui32Base + EMAC_O_DMAIM));
    }

    //
    // Read the PHY interrupt status.
    //
    if(bMasked)
    {
        ui32PHYStat = HWREG(ui32Base + EMAC_O_EPHYMISC);
    }
    else
    {
        ui32PHYStat = HWREG(ui32Base + EMAC_O_EPHYRIS);
    }

    //
    // If the PHY interrupt is reported, add the appropriate flag to the
    // return value.
    //
    if(ui32PHYStat & EMAC_EPHYMISC_INT)
    {
        ui32Val |= EMAC_INT_PHY;
    }

    return(ui32Val);
}

//*****************************************************************************
//
//! Clears individual Ethernet MAC interrupt sources.
//!
//! \param ui32Base is the base address of the Ethernet MAC.
//! \param ui32IntFlags is the bit mask of the interrupt sources to be cleared.
//!
//! This function disables the indicated Ethernet MAC interrupt sources.
//!
//! The \e ui32IntFlags parameter is the logical OR of any of the following:
//!
//! - \b EMAC_INT_PHY indicates that the PHY has signaled a change of state.
//! Software must read and write the appropriate PHY registers to enable,
//! disable and clear particular notifications.
//! - \b EMAC_INT_EARLY_RECEIVE indicates that the DMA engine has filled the
//! first data buffer of a packet.
//! - \b EMAC_INT_BUS_ERROR indicates that a fatal bus error has occurred and
//! that the DMA engine has been disabled.
//! - \b EMAC_INT_EARLY_TRANSMIT indicates that a frame to be transmitted has
//! been fully written from memory into the MAC transmit FIFO.
//! - \b EMAC_INT_RX_WATCHDOG indicates that a frame with length greater than
//! 2048 bytes (of 10240 bytes in Jumbo Frame mode) was received.
//! - \b EMAC_INT_RX_STOPPED indicates that the receive process has entered
//! the stopped state.
//! - \b EMAC_INT_RX_NO_BUFFER indicates that the host owns the next buffer
//! in the DMA's receive descriptor list and the DMA cannot, therefore, acquire
//! a buffer.  The receive process is suspended and can be resumed by changing
//! the descriptor ownership and calling EMACRxDMAPollDemand().
//! - \b EMAC_INT_RECEIVE indicates that reception of a frame has completed
//! and all requested status has been written to the appropriate DMA receive
//! descriptor.
//! - \b EMAC_INT_TX_UNDERFLOW indicates that the transmitter experienced an
//! underflow during transmission.  The transmit process is suspended.
//! - \b EMAC_INT_RX_OVERFLOW indicates that an overflow was experienced
//! during reception.
//! - \b EMAC_INT_TX_JABBER indicates that the transmit jabber timer expired.
//! This happens when the frame size exceeds 2048 bytes (or 10240 bytes in
//! Jumbo Frame mode) and causes the transmit process to abort and enter the
//! Stopped state.
//! - \b EMAC_INT_TX_NO_BUFFER indicates that the host owns the next buffer
//! in the DMA's transmit descriptor list and that the DMA cannot, therefore,
//! acquire a buffer.  Transmission is suspended and can be resumed by changing
//! the descriptor ownership and calling EMACTxDMAPollDemand().
//! - \b EMAC_INT_TX_STOPPED indicates that the transmit process has stopped.
//! - \b EMAC_INT_TRANSMIT indicates that transmission of a frame has
//! completed and that all requested status has been updated in the descriptor.
//!
//! Summary interrupt bits \b EMAC_INT_NORMAL_INT and
//! \b EMAC_INT_ABNORMAL_INT are cleared automatically by the driver if any
//! of their constituent sources are cleared.  Applications do not need to
//! explicitly clear these bits.
//!
//! \return None.
//
//*****************************************************************************
void
EMACIntClear(uint32_t ui32Base, uint32_t ui32IntFlags)
{
    //
    // Parameter sanity check.
    //
    ASSERT(ui32Base == EMAC0_BASE);

    //
    // Mask in the normal interrupt if one of the sources it relates to is
    // specified.
    //
    if(ui32IntFlags & EMAC_NORMAL_INTS)
    {
        ui32IntFlags |= EMAC_INT_NORMAL_INT;
    }

    //
    // Similarly, mask in the abnormal interrupt if one of the sources it
    // relates to is specified.
    //
    if(ui32IntFlags & EMAC_ABNORMAL_INTS)
    {
        ui32IntFlags |= EMAC_INT_ABNORMAL_INT;
    }

    //
    // Clear the maskable interrupt sources.  We write exactly the value passed
    // (with the summary sources added if necessary) but remember that only
    // the bottom 17 bits of the register are actually clearable.  Only do
    // this if some bits are actually set that refer to the DMA interrupt
    // sources.
    //
    if(ui32IntFlags & ~EMAC_INT_PHY)
    {
        HWREG(ui32Base + EMAC_O_DMARIS) = (ui32IntFlags & ~EMAC_INT_PHY);
    }

    //
    // Clear the PHY interrupt if we've been asked to do this.
    //
    if(ui32IntFlags & EMAC_INT_PHY)
    {
        HWREG(ui32Base + EMAC_O_EPHYMISC) |= EMAC_EPHYMISC_INT;
    }
}

//*****************************************************************************
//
//! Writes to the PHY register.
//!
//! \param ui32Base is the base address of the controller.
//! \param ui8PhyAddr is the physical address of the PHY to access.
//! \param ui8RegAddr is the address of the PHY register to be accessed.
//! \param ui16Data is the data to be written to the PHY register.
//!
//! This function writes the \e ui16Data value to the PHY register specified by
//! \e ui8RegAddr.
//!
//! \return None.
//
//*****************************************************************************
void
EMACPHYWrite(uint32_t ui32Base, uint8_t ui8PhyAddr, uint8_t ui8RegAddr,
             uint16_t ui16Data)
{
    //
    // Parameter sanity check.
    //
    ASSERT(ui32Base == EMAC0_BASE);

    //
    // Parameter sanity check.
    //
    ASSERT(ui8PhyAddr < 32);

    //
    // Make sure the MII is idle.
    //
    while(HWREG(ui32Base + EMAC_O_MIIADDR) & EMAC_MIIADDR_MIIB)
    {
    }

    //
    // Write the value provided.
    //
    HWREG(ui32Base + EMAC_O_MIIDATA) = ui16Data;

    //
    // Tell the MAC to write the given PHY register.
    //
    HWREG(ui32Base + EMAC_O_MIIADDR) =
        ((HWREG(ui32Base + EMAC_O_MIIADDR) &
          EMAC_MIIADDR_CR_M) | (ui8RegAddr << EMAC_MIIADDR_MII_S) |
         (ui8PhyAddr << EMAC_MIIADDR_PLA_S) | EMAC_MIIADDR_MIIW |
         EMAC_MIIADDR_MIIB);

    //
    // Wait for the write to complete.
    //
    while(HWREG(ui32Base + EMAC_O_MIIADDR) & EMAC_MIIADDR_MIIB)
    {
    }
}

//*****************************************************************************
//
//! Reads from a PHY register.
//!
//! \param ui32Base is the base address of the controller.
//! \param ui8PhyAddr is the physical address of the PHY to access.
//! \param ui8RegAddr is the address of the PHY register to be accessed.
//!
//! This function returns the contents of the PHY register specified by
//! \e ui8RegAddr.
//!
//! \return Returns the 16-bit value read from the PHY.
//
//*****************************************************************************
uint16_t
EMACPHYRead(uint32_t ui32Base, uint8_t ui8PhyAddr, uint8_t ui8RegAddr)
{
    //
    // Parameter sanity check.
    //
    ASSERT(ui8PhyAddr < 32);
    ASSERT(ui32Base == EMAC0_BASE);

    //
    // Make sure the MII is idle.
    //
    while(HWREG(ui32Base + EMAC_O_MIIADDR) & EMAC_MIIADDR_MIIB)
    {
    }

    //
    // Tell the MAC to read the given PHY register.
    //
    HWREG(ui32Base + EMAC_O_MIIADDR) =
        ((HWREG(ui32Base + EMAC_O_MIIADDR) & EMAC_MIIADDR_CR_M) |
         (ui8RegAddr << EMAC_MIIADDR_MII_S) |
         (ui8PhyAddr << EMAC_MIIADDR_PLA_S) | EMAC_MIIADDR_MIIB);

    //
    // Wait for the read to complete.
    //
    while(HWREG(ui32Base + EMAC_O_MIIADDR) & EMAC_MIIADDR_MIIB)
    {
    }

    //
    // Return the result.
    //
    return(HWREG(ui32Base + EMAC_O_MIIDATA) & EMAC_MIIDATA_DATA_M);
}

//*****************************************************************************
//
//! Reads from an extended PHY register.
//!
//! \param ui32Base is the base address of the controller.
//! \param ui8PhyAddr is the physical address of the PHY to access.
//! \param ui16RegAddr is the address of the PHY extended register to be
//! accessed.
//!
//! When using the internal PHY or when connected to an external PHY
//! supporting extended registers, this function returns the contents of the
//! extended PHY register specified by \e ui16RegAddr.
//!
//! \return Returns the 16-bit value read from the PHY.
//
//*****************************************************************************
uint16_t
EMACPHYExtendedRead(uint32_t ui32Base, uint8_t ui8PhyAddr,
                    uint16_t ui16RegAddr)
{
    //
    // Parameter sanity check.
    //
    ASSERT(ui8PhyAddr < 32);
    ASSERT(ui32Base == EMAC0_BASE);

    //
    // Set the address of the register we're about to read.
    //
    EMACPHYWrite(EMAC0_BASE, ui8PhyAddr, EPHY_REGCTL, 0x001F);
    EMACPHYWrite(EMAC0_BASE, ui8PhyAddr, EPHY_ADDAR, ui16RegAddr);

    //
    // Read the extended register value.
    //
    EMACPHYWrite(EMAC0_BASE, ui8PhyAddr, EPHY_REGCTL, 0x401F);
    return(EMACPHYRead(EMAC0_BASE, ui8PhyAddr, EPHY_ADDAR));
}

//*****************************************************************************
//
//! Writes a value to an extended PHY register.
//!
//! \param ui32Base is the base address of the controller.
//! \param ui8PhyAddr is the physical address of the PHY to access.
//! \param ui16RegAddr is the address of the PHY extended register to be
//! accessed.
//! \param ui16Value is the value to write to the register.
//!
//! When using the internal PHY or when connected to an external PHY
//! supporting extended registers, this function allows a value to be written
//! to the extended PHY register specified by \e ui16RegAddr.
//!
//! \return None.
//
//*****************************************************************************
void
EMACPHYExtendedWrite(uint32_t ui32Base, uint8_t ui8PhyAddr,
                     uint16_t ui16RegAddr, uint16_t ui16Value)
{
    //
    // Parameter sanity check.
    //
    ASSERT(ui8PhyAddr < 32);
    ASSERT(ui32Base == EMAC0_BASE);

    //
    // Set the address of the register we're about to write.
    //
    EMACPHYWrite(EMAC0_BASE, ui8PhyAddr, EPHY_REGCTL, 0x001F);
    EMACPHYWrite(EMAC0_BASE, ui8PhyAddr, EPHY_ADDAR, ui16RegAddr);

    //
    // Write the extended register.
    //
    EMACPHYWrite(EMAC0_BASE, ui8PhyAddr, EPHY_REGCTL, 0x401F);
    EMACPHYWrite(EMAC0_BASE, ui8PhyAddr, EPHY_ADDAR, ui16Value);
}

//*****************************************************************************
//
//! Powers off the Ethernet PHY.
//!
//! \param ui32Base is the base address of the controller.
//! \param ui8PhyAddr is the physical address of the PHY to power down.
//!
//! This function powers off the Ethernet PHY, reducing the current
//! consumption of the device.  While in the powered off state, the Ethernet
//! controller is unable to connect to the Ethernet.
//!
//! \return None.
//
//*****************************************************************************
void
EMACPHYPowerOff(uint32_t ui32Base, uint8_t ui8PhyAddr)
{
    //
    // Set the PWRDN bit and clear the ANEN bit in the PHY, putting it into
    // its low power mode.
    //
    EMACPHYWrite(ui32Base, ui8PhyAddr, EPHY_BMCR,
                 (EMACPHYRead(ui32Base, ui8PhyAddr, EPHY_BMCR) &
                  ~EPHY_BMCR_ANEN) | EPHY_BMCR_PWRDWN);
}

//*****************************************************************************
//
//! Powers on the Ethernet PHY.
//!
//! \param ui32Base is the base address of the controller.
//! \param ui8PhyAddr is the physical address of the PHY to power up.
//!
//! This function powers on the Ethernet PHY, enabling it return to normal
//! operation.  By default, the PHY is powered on, so this function is only
//! called if EMACPHYPowerOff() has previously been called.
//!
//! \return None.
//
//*****************************************************************************
void
EMACPHYPowerOn(uint32_t ui32Base, uint8_t ui8PhyAddr)
{
    //
    // Clear the PWRDN bit and set the ANEGEN bit in the PHY, putting it into
    // normal operating mode.
    //
    EMACPHYWrite(ui32Base, ui8PhyAddr, EPHY_BMCR,
                 (EMACPHYRead(ui32Base, ui8PhyAddr, EPHY_BMCR) &
                  ~EPHY_BMCR_PWRDWN) | EPHY_BMCR_ANEN);
}

//*****************************************************************************
//
//! Configures the Ethernet MAC's IEEE-1588 timestamping options.
//!
//! \param ui32Base is the base address of the controller.
//! \param ui32Config contains flags selecting particular configuration
//! options.
//! \param ui32SubSecondInc is the number that the IEEE-1588 subsecond clock
//! should increment on each tick.
//!
//! This function is used to configure the operation of the Ethernet MAC's
//! internal timestamping clock.  This clock is used to timestamp incoming
//! and outgoing packets and as an accurate system time reference when
//! IEEE-1588 Precision Time Protocol is in use.
//!
//! The \e ui32Config parameter contains a collection of flags selecting the
//! desired options.  Valid flags are:
//!
//! One of the following to determine whether IEEE-1588 version 1 or version 2
//! packet format is to be processed.
//!
//! - \b EMAC_TS_PTP_VERSION_2
//! - \b EMAC_TS_PTP_VERSION_1
//!
//! One or other of the following to determine how the IEEE-1588 clock's
//! subsecond value should be interpreted and handled.
//!
//! - \b EMAC_TS_DIGITAL_ROLLOVER causes the clock's subsecond value to roll
//! over at 0x3BA9C9FF (999999999 decimal). In this mode, it can be considered
//! as a nanosecond counter with each digit representing 1nS.
//! - \b EMAC_TS_BINARY_ROLLOVER causes the clock's subsecond value to roll
//! over at 0x7FFFFFFF.  In this mode, the subsecond value counts 0.465nS
//! periods.
//!
//! One of the following to enable or disable MAC address filtering. When
//! enabled, PTP frames are filtered unless the destination MAC address matches
//! any of the currently programmed MAC addresses.
//!
//! - \b EMAC_TS_MAC_FILTER_ENABLE
//! - \b EMAC_TS_MAC_FILTER_DISABLE
//!
//! One of the following to determine how the clock is updated.
//! - \b EMAC_TS_UPDATE_COARSE causes the IEEE-1588 clock to advance by
//! the value supplied in the \e ui32SubSecondInc parameter on each main
//! oscillator clock cycle.
//! - \b EMAC_TS_UPDATE_FINE selects the fine update method which causes the
//! IEEE-1588 clock to advance by the the value supplied in the
//! \e ui32SubSecondInc parameter each time a carry is generated from the
//! addend accumulator register.
//!
//! One of the following determines which IEEE-1588 messages are timestamped:
//!
//! - \b EMAC_TS_SYNC_FOLLOW_DREQ_DRESP timestamps SYNC, Follow_Up, Delay_Req
//!   and Delay_Resp messages.
//! - \b EMAC_TS_SYNC_ONLY timestamps only SYNC messages.
//! - \b EMAC_TS_DELAYREQ_ONLY timestamps only Delay_Req messages.
//! - \b EMAC_TS_ALL timestamps all IEEE-1588 messages.
//! - \b EMAC_TS_SYNC_PDREQ_PDRESP timestamps only SYNC, Pdelay_Req and
//!   Pdelay_Resp messages.
//! - \b EMAC_TS_DREQ_PDREQ_PDRESP timestamps only Delay_Req, Pdelay_Req and
//!   Pdelay_Resp messages.
//! - \b EMAC_TS_SYNC_DELAYREQ timestamps only Delay_Req messages.
//! - \b EMAC_TS_PDREQ_PDRESP timestamps only Pdelay_Req and Pdelay_Resp
//!   messages.
//!
//! Optional, additional flags are:
//!
//! - \b EMAC_TS_PROCESS_IPV4_UDP processes PTP packets encapsulated in UDP
//!   over IPv4 packets.  If absent, the MAC ignores these frames.
//! - \b EMAC_TS_PROCESS_IPV6_UDP processes PTP packets encapsulated in UDP
//!   over IPv6 packets.  If absent, the MAC ignores these frames.
//! - \b EMAC_TS_PROCESS_ETHERNET processes PTP packets encapsulated directly
//!   in Ethernet frames.  If absent, the MAC ignores these frames.
//! - \b EMAC_TS_ALL_RX_FRAMES enables timestamping for all frames received
//!   by the MAC, regardless of type.
//!
//! The \e ui32SubSecondInc controls the rate at which the timestamp clock's
//! subsecond count increments.  Its meaning depends upon which of \b
//! EMAC_TS_DIGITAL_ROLLOVER or \b EMAC_TS_BINARY_ROLLOVER and
//! \b EMAC_TS_UPDATE_FINE or \b EMAC_TS_UPDATE_COARSE was included
//! in \e ui32Config.
//!
//! The timestamp second counter is incremented each time the subsecond counter
//! rolls over.  In digital rollover mode, the subsecond counter acts as a
//! simple 31-bit counter, rolling over to 0 after reaching 0x7FFFFFFF.  In
//! this case, each lsb of the subsecond counter represents 0.465nS (assuming
//! that we maintain the definition of 1 second resolution for the seconds
//! counter).  When binary rollover mode is selected, the subsecond counter
//! acts as a nanosecond counter and rolls over to 0 after reaching 999,999,999
//! making each lsb represent 1 nanosecond.
//!
//! In course update mode, the timestamp subsecond counter is incremented by
//! \e ui32SubSecondInc on each main oscillator clock tick.  Setting
//! \e ui32SubSecondInc to the main oscillator clock period in either 1nS or
//! 0.465nS units will ensure that the time stamp, read as seconds and
//! subseconds, increments at the same rate as the main oscillator clock.  For
//! example, if the main oscillator is 25MHz, \e ui32SubSecondInc would be set
//! to 40 if digital rollover mode was selected or (40 / 0.465) = 86 in binary
//! rollover mode.
//!
//! In fine update mode, the subsecond increment value must be set according
//! to the desired accuracy of the recovered IEEE-1588 clock which must be
//! lower than the system clock rate.  Fine update mode is typically used when
//! synchronizing the local clock to the IEEE-1588 master clock.  The subsecond
//! counter is incremented by \e ui32SubSecondInc counts each time a 32-bit
//! accumulator register generates a carry.  The accumulator register is
//! incremented by the "addend" value on each main oscillator tick and this
//! addend value is modified to allow fine control over the rate of change of
//! the timestamp counter.  The addend value is calculated using the ratio of
//! the main oscillator clock rate and the desired IEEE-1588 clock rate and the
//! \e ui32SubSecondInc value is set to correspond to the desired IEEE-1588
//! clock rate.  As an example, using digital rollover mode and a 25MHz
//! main oscillator clock with a desired IEEE-1588 clock accuracy of 12.5MHz,
//! we would set \e ui32SubSecondInc to the 12.5MHz clock period of 80nS and
//! set the initial addend value to 0x80000000 to generate a carry on every
//! second system clock.
//!
//! \sa EMACTimestampAddendSet()
//!
//! \return None.
//
//*****************************************************************************
void
EMACTimestampConfigSet(uint32_t ui32Base, uint32_t ui32Config,
                       uint32_t ui32SubSecondInc)
{
    //
    // Parameter sanity check.
    //
    ASSERT(ui32Base == EMAC0_BASE);

    //
    // Ensure that the PTP module clock is enabled.
    //
    HWREG(ui32Base + EMAC_O_CC) |= EMAC_CC_PTPCEN;

    //
    // Write the subsecond increment value.
    //
    HWREG(ui32Base + EMAC_O_SUBSECINC) = ((ui32SubSecondInc <<
                                           EMAC_SUBSECINC_SSINC_S) &
                                          EMAC_SUBSECINC_SSINC_M);

    //
    // Set the timestamp configuration.
    //
    HWREG(ui32Base + EMAC_O_TIMSTCTRL) = ui32Config;
}

//*****************************************************************************
//
//! Returns the current IEEE1588 timestamping configuration.
//!
//! \param ui32Base is the base address of the controller.
//! \param pui32SubSecondInc points to storage which is written with the
//! current subsecond increment value for the IEEE-1588 clock.
//!
//! This function may be used to retreive the current MAC timestamping
//! configuration.
//!
//! \sa EMACTimestampConfigSet()
//!
//! \return Returns the current timestamping configuration as a logical OR of
//! the following flags:
//!
//! - \b EMAC_TS_PTP_VERSION_2 indicates that the MAC is processing PTP
//! version 2 messages.  If this flag is absent, PTP version 1 messages are
//! expected.
//! - \b EMAC_TS_DIGITAL_ROLLOVER causes the clock's subsecond value to roll
//! over at 0x3BA9C9FF (999999999 decimal). In this mode, it can be considered
//! as a nanosecond counter with each digit representing 1nS.  If this flag is
//! absent, the subsecond value rolls over at 0x7FFFFFFF effectively counting
//! increments of 0.465nS.
//! - \b EMAC_TS_MAC_FILTER_ENABLE indicates that incoming PTP messages
//! are filtered using any of the configured MAC addresses.  Messages with a
//! destination address that has been programmed into the MAC address filter
//! will be passed, others will be discarded.  If this flag is absent, the MAC
//! address is ignored
//! - \b EMAC_TS_UPDATE_FINE indicates that the fine update method which
//! causes the IEEE-1588 clock to advance by the the value returned in the
//! \e *pui32SubSecondInc parameter each time a carry is generated from the
//! addend accumulator register.  If this flag is absent, the course update
//! method is in use and the clock is advanced by the \e *pui32SubSecondInc
//! value on each system clock tick.
//! - \b EMAC_TS_SYNC_ONLY indicates that timestamps are only generated for
//! SYNC messages.
//! - \b EMAC_TS_DELAYREQ_ONLY indicates that timestamps are only generated
//! for Delay_Req messages.
//! - \b EMAC_TS_ALL indicates that timestamps are generated for all
//! IEEE-1588 messages.
//! - \b EMAC_TS_SYNC_PDREQ_PDRESP timestamps only SYNC, Pdelay_Req and
//! Pdelay_Resp messages.
//! - \b EMAC_TS_DREQ_PDREQ_PDRESP indicates that timestamps are only
//! generated for Delay_Req, Pdelay_Req and Pdelay_Resp messages.
//! - \b EMAC_TS_SYNC_DELAYREQ indicates that timestamps are only generated
//! for Delay_Req messages.
//! - \b EMAC_TS_PDREQ_PDRESP indicates that timestamps are only generated
//! for Pdelay_Req and Pdelay_Resp messages.
//! - \b EMAC_TS_PROCESS_IPV4_UDP indicates that PTP packets encapsulated in
//! UDP over IPv4 packets are being processed.  If absent, the MAC ignores
//! these frames.
//! - \b EMAC_TS_PROCESS_IPV6_UDP indicates that PTP packets encapsulated in
//! UDP over IPv6 packets are being processed.  If absent, the MAC ignores
//! these frames.
//! - \b EMAC_TS_PROCESS_ETHERNET indicates that PTP packets encapsulated
//! directly in Ethernet frames are being processd.  If absent, the MAC ignores
//! these frames.
//! - \b EMAC_TS_ALL_RX_FRAMES indicates that timestamping is enabled for all
//! frames received by the MAC, regardless of type.
//!
//! If \b EMAC_TS_ALL_RX_FRAMES and none of the options specifying subsets
//! of PTP packets to timestamp are set, the MAC is configured to timestamp
//! SYNC, Follow_Up, Delay_Req and Delay_Resp messages only.
//
//*****************************************************************************
uint32_t
EMACTimestampConfigGet(uint32_t ui32Base, uint32_t *pui32SubSecondInc)
{
    //
    // Parameter sanity check.
    //
    ASSERT(ui32Base == EMAC0_BASE);
    ASSERT(pui32SubSecondInc);

    //
    // Read the current subsecond increment value.
    //
    *pui32SubSecondInc = (HWREG(ui32Base + EMAC_O_SUBSECINC) &
                          EMAC_SUBSECINC_SSINC_M) >> EMAC_SUBSECINC_SSINC_S;

    //
    // Return the current timestamp configuration.
    //
    return(HWREG(ui32Base + EMAC_O_TIMSTCTRL));
}

//*****************************************************************************
//
//! Enables packet timestamping and starts the system clock running.
//!
//! \param ui32Base is the base address of the controller.
//!
//! This function may be used to enable the system clock used to timestamp
//! Ethernet frames and to enable that timestamping.
//!
//! \return None.
//
//*****************************************************************************
void
EMACTimestampEnable(uint32_t ui32Base)
{
    //
    // Parameter sanity check.
    //
    ASSERT(ui32Base == EMAC0_BASE);

    //
    // Enable IEEE1588 timestamping.
    //
    HWREG(ui32Base + EMAC_O_TIMSTCTRL) |= EMAC_TIMSTCTRL_TSEN;

    //
    // If necessary, initialize the timestamping system.  This bit self-clears
    // once the system time is loaded.  Only do this if initialization is not
    // currently ongoing.
    //
    if(!(HWREG(ui32Base + EMAC_O_TIMSTCTRL) & EMAC_TIMSTCTRL_TSINIT))
    {
        HWREG(ui32Base + EMAC_O_TIMSTCTRL) |= EMAC_TIMSTCTRL_TSINIT;
    }
}

//*****************************************************************************
//
//! Disables packet timestamping and stops the system clock.
//!
//! \param ui32Base is the base address of the controller.
//!
//! This function may be used to stop the system clock used to timestamp
//! Ethernet frames and to disable timestamping.
//!
//! \return None.
//
//*****************************************************************************
void
EMACTimestampDisable(uint32_t ui32Base)
{
    //
    // Parameter sanity check.
    //
    ASSERT(ui32Base == EMAC0_BASE);

    //
    // Disable IEEE1588 timestamping.
    //
    HWREG(ui32Base + EMAC_O_TIMSTCTRL) &= ~EMAC_TIMSTCTRL_TSEN;
}

//*****************************************************************************
//
//! Sets the current system time.
//!
//! \param ui32Base is the base address of the controller.
//! \param ui32Seconds is the seconds value of the new system clock setting.
//! \param ui32SubSeconds is the subseconds value of the new system clock
//! setting.
//!
//! This function may be used to set the current system time.  The system
//! clock us set to the value passed in the \e ui32Seconds and
//! \e ui32SubSeconds parameters.
//!
//! The meaning of \e ui32SubSeconds depends upon the current system time
//! configuration.  If EMACTimestampConfigSet() was previously called with
//! the \e EMAC_TS_DIGITAL_ROLLOVER configuration option, each bit in the
//! \e ui32SubSeconds value represents 1nS. If \e EMAC_TS_BINARY_ROLLOVER was
//! specified instead, a \e ui32SubSeconds bit represents 0.46nS.
//!
//! \return None.
//
//*****************************************************************************
void
EMACTimestampSysTimeSet(uint32_t ui32Base, uint32_t ui32Seconds,
                        uint32_t ui32SubSeconds)
{
    //
    // Parameter sanity check.
    //
    ASSERT(ui32Base == EMAC0_BASE);

    //
    // Write the new time to the system time update registers.
    //
    HWREG(ui32Base + EMAC_O_TIMSECU) = ui32Seconds;
    HWREG(ui32Base + EMAC_O_TIMNANOU) = ui32SubSeconds;

    //
    // Wait for any previous update to complete.
    //
    while(HWREG(ui32Base + EMAC_O_TIMSTCTRL) & EMAC_TIMSTCTRL_TSINIT)
    {
        //
        // Spin for a while.
        //
    }

    //
    // Force the system clock to reset.
    //
    HWREG(ui32Base + EMAC_O_TIMSTCTRL) |= EMAC_TIMSTCTRL_TSINIT;
}

//*****************************************************************************
//
//! Gets the current system time.
//!
//! \param ui32Base is the base address of the controller.
//! \param pui32Seconds points to storage for the current seconds value.
//! \param pui32SubSeconds points to storage for the current subseconds value.
//!
//! This function may be used to get the current system time.
//!
//! The meaning of \e ui32SubSeconds depends upon the current system time
//! configuration.  If EMACTimestampConfigSet() was previously called with
//! the \e EMAC_TS_DIGITAL_ROLLOVER configuration option, each bit in the
//! \e ui32SubSeconds value represents 1nS. If \e EMAC_TS_BINARY_ROLLOVER was
//! specified instead, a \e ui32SubSeconds bit represents 0.46nS.
//!
//! \return None.
//
//*****************************************************************************
void
EMACTimestampSysTimeGet(uint32_t ui32Base, uint32_t *pui32Seconds,
                        uint32_t *pui32SubSeconds)
{
    //
    // Parameter sanity check.
    //
    ASSERT(ui32Base == EMAC0_BASE);
    ASSERT(pui32Seconds);
    ASSERT(pui32SubSeconds);

    //
    // Read the two-part system time from the seconds and nanoseconds
    // registers.  We do this in a way that should guard against us reading
    // the registers across a nanosecond wrap.
    //
    do
    {
        *pui32Seconds = HWREG(ui32Base + EMAC_O_TIMSEC);
        *pui32SubSeconds = HWREG(ui32Base + EMAC_O_TIMNANO);
    }
    while(*pui32SubSeconds > HWREG(ui32Base + EMAC_O_TIMNANO));
}

//*****************************************************************************
//
//! Adjusts the current system time upwards or downwards by a given amount.
//!
//! \param ui32Base is the base address of the controller.
//! \param ui32Seconds is the seconds value of the time update to apply.
//! \param ui32SubSeconds is the subseconds value of the time update to apply.
//! \param bInc defines the direction of the update.
//!
//! This function may be used to adjust the current system time either upwards
//! or downwards by a given amount.  The size of the adjustment is given by
//! the \e ui32Seconds and \e ui32SubSeconds parameter and the direction
//! by the \e bInc parameter.  When \e bInc is \e true, the system time is
//! advanced by the interval given.  When it is \e false, the time is retarded
//! by the interval.
//!
//! The meaning of \e ui32SubSeconds depends upon the current system time
//! configuration.  If EMACTimestampConfigSet() was previously called with
//! the \e EMAC_TS_DIGITAL_ROLLOVER configuration option, each bit in the
//! subsecond value represents 1nS. If \e EMAC_TS_BINARY_ROLLOVER was
//! specified instead, a subsecond bit represents 0.46nS.
//!
//! \return None.
//
//*****************************************************************************
void
EMACTimestampSysTimeUpdate(uint32_t ui32Base, uint32_t ui32Seconds,
                           uint32_t ui32SubSeconds, bool bInc)
{
    //
    // Parameter sanity check.
    //
    ASSERT(ui32Base == EMAC0_BASE);

    //
    // Write the new time to the system time update registers.
    //
    HWREG(ui32Base + EMAC_O_TIMSECU) = ui32Seconds;
    HWREG(ui32Base + EMAC_O_TIMNANOU) = ui32SubSeconds |
                                        (bInc ? 0 : EMAC_TIMNANOU_ADDSUB);

    //
    // Wait for any previous update to complete.
    //
    while(HWREG(ui32Base + EMAC_O_TIMSTCTRL) & EMAC_TIMSTCTRL_TSUPDT)
    {
        //
        // Spin for a while.
        //
    }

    //
    // Force the system clock to update by the value provided.
    //
    HWREG(ui32Base + EMAC_O_TIMSTCTRL) |= EMAC_TIMSTCTRL_TSUPDT;
}

//*****************************************************************************
//
//! Adjusts the system time update rate when using the fine correction method.
//!
//! \param ui32Base is the base address of the controller.
//! \param ui32Increment is the number to add to the accumulator register on
//! each tick of the 25MHz main oscillator.
//!
//! This function is used to control the rate of update of the system time
//! when in fine update mode.  Fine correction mode is selected if
//! \e EMAC_TS_UPDATE_FINE is supplied in the \e ui32Config parameter passed
//! to a previous call to EMACTimestampConfigSet().  Fine update mode is
//! typically used when synchronizing the local clock to the IEEE-1588 master
//! clock.  The subsecond counter is incremented by the number passed to
//! EMACTimestampConfigSet() in teh \e ui32SubSecondInc parameter each time a
//! 32-bit accumulator register generates a carry.  The accumulator register is
//! incremented by the "addend" value on each main oscillator tick and this
//! addend value is modified to allow fine control over the rate of change of
//! the timestamp counter.  The addend value is calculated using the ratio of
//! the main oscillator clock rate and the desired IEEE-1588 clock rate and the
//! \e ui32SubSecondInc value is set to correspond to the desired IEEE-1588
//! clock rate.
//!
//! As an example, using digital rollover mode and a 25MHz main oscillator
//! clock with a desired IEEE-1588 clock accuracy of 12.5MHz, and having made
//! a previous call to EMACTimestampConfigSet() with \e ui32SubSecondInc set to
//! the 12.5MHz clock period of 80nS and, the initial \e ui32Increment value
//! would be set to 0x80000000 to generate a carry on every second main
//! oscillator tick.  Because the system time updates each time the accumulator
//! overflows, small changes in the \e ui32Increment value can be used to very
//! finely control the system time rate.
//!
//! \return None.
//!
//! \sa EMACTimestampConfigSet()
//
//*****************************************************************************
void
EMACTimestampAddendSet(uint32_t ui32Base, uint32_t ui32Increment)
{
    //
    // Parameter sanity check.
    //
    ASSERT(ui32Base == EMAC0_BASE);

    HWREG(ui32Base + EMAC_O_TIMADD) = ui32Increment;

    //
    // Wait for any previous update to complete.
    //
    while(HWREG(ui32Base + EMAC_O_TIMSTCTRL) & EMAC_TIMSTCTRL_ADDREGUP)
    {
        //
        // Spin for a while.
        //
    }

    //
    // Force the system clock to update by the value provided.
    //
    HWREG(ui32Base + EMAC_O_TIMSTCTRL) |= EMAC_TIMSTCTRL_ADDREGUP;
}

//*****************************************************************************
//
//! Sets the target system time at which the next Ethernet timer interrupt will
//! fire.
//!
//! \param ui32Base is the base address of the controller.
//! \param ui32Seconds is the second value of the desired target time.
//! \param ui32SubSeconds is the subseconds value of the desired target time.
//!
//! This function may be used to schedule an interrupt at some future time.
//! The time reference for the function is the IEEE1588 time as returned by
//! EMACTimestampSysTimeGet().  To generate an interrupt when the system
//! time exceeds a given value, call this function to set the desired time
//! then EMACTimestampTargetIntEnable() to enable the interrupt.  When the
//! system time increments past the target time, an Ethernet interrupt with
//! status EMAC_INT_TIMESTAMP will be generated.
//!
//! The accuracy of the interrupt timing depends upon the Ethernet timer
//! update frequency and the subsecond increment value currently in use.  The
//! interrupt is generated on the first timer increment which causes the
//! system time to be greater than or equal to the target time set.
//!
//! \return None.
//
//*****************************************************************************
void
EMACTimestampTargetSet(uint32_t ui32Base, uint32_t ui32Seconds,
                       uint32_t ui32SubSeconds)
{
    //
    // Parameter sanity check.
    //
    ASSERT(ui32Base == EMAC0_BASE);

    //
    // Wait for any previous write to complete.
    //
    while(HWREG(ui32Base + EMAC_O_TARGNANO) & EMAC_TARGNANO_TRGTBUSY)
    {
    }

    //
    // Write the new target time.
    //
    HWREG(ui32Base + EMAC_O_TARGSEC) = ui32Seconds;
    HWREG(ui32Base + EMAC_O_TARGNANO) = ui32SubSeconds;
}

//*****************************************************************************
//
//! Enables the Ethernet system time interrupt.
//!
//! \param ui32Base is the base address of the controller.
//!
//! This function may be used after EMACTimestampTargetSet() to schedule an
//! interrupt at some future time.  The time reference for the function is
//! the IEEE1588 time as returned by EMACTimestampSysTimeGet().  To generate
//! an interrupt when the system time exceeds a given value, call this function
//! to set the desired time then EMACTimestampTargetIntEnable() to enable the
//! interrupt.  When the system time increments past the target time, an
//! Ethernet interrupt with status \b EMAC_INT_TIMESTAMP will be generated.
//!
//! \return None.
//
//*****************************************************************************
void
EMACTimestampTargetIntEnable(uint32_t ui32Base)
{
    //
    // Parameter sanity check.
    //
    ASSERT(ui32Base == EMAC0_BASE);

    //
    // Set the bit to enable the timestamp target interrupt.  This bit will
    // clear automatically when the interrupt fires after which point, you
    // need to set a new target time and re-enable the interrupts.
    //
    HWREG(ui32Base + EMAC_O_TIMSTCTRL) |= EMAC_TIMSTCTRL_INTTRIG;
}

//*****************************************************************************
//
//! Disables the Ethernet system time interrupt.
//!
//! \param ui32Base is the base address of the controller.
//!
//! This function may be used to disable any pending Ethernet system time
//! interrupt previously scheduled using calls to EMACTimestampTargetSet()
//! and EMACTimestampTargetIntEnable().
//!
//! \return None.
//
//*****************************************************************************
void
EMACTimestampTargetIntDisable(uint32_t ui32Base)
{
    //
    // Parameter sanity check.
    //
    ASSERT(ui32Base == EMAC0_BASE);

    //
    // Clear the bit to disable the timestamp target interrupt.  This bit will
    // clear automatically when the interrupt fires so it only needs to be
    // disabled if you want to cancel a previously-set interrupt.
    //
    HWREG(ui32Base + EMAC_O_TIMSTCTRL) &= ~EMAC_TIMSTCTRL_INTTRIG;
}

//*****************************************************************************
//
//! Reads the status of the Ethernet system time interrupt.
//!
//! \param ui32Base is the base address of the controller.
//!
//! When an Ethernet interrupt occurs and \b EMAC_INT_TIMESTAMP is reported
//! bu EMACIntStatus(), this function must be called to read and clear the
//! timer interrupt status.
//!
//! \return The return value is the logical OR of the values
//! \b EMAC_TS_INT_TS_SEC_OVERFLOW and \b EMAC_TS_INT_TARGET_REACHED.
//!
//! - \b EMAC_TS_INT_TS_SEC_OVERFLOW indicates that the second counter in the
//! hardware timer has rolled over.
//! - \b EMAC_TS_INT_TARGET_REACHED indicates that the system time incremented
//! past the value set in an earlier call to EMACTimestampTargetSet().  When
//! this occurs, a new target time may be set and the interrupt re-enabled
//! using calls to EMACTimestampTargetSet() and
//! EMACTimestampTargetIntEnable().
//
//*****************************************************************************
uint32_t
EMACTimestampIntStatus(uint32_t ui32Base)
{
    //
    // Parameter sanity check.
    //
    ASSERT(ui32Base == EMAC0_BASE);

    //
    // Return the current interrupt status from the timestamp module.
    //
    return(HWREG(ui32Base + EMAC_O_TIMSTAT));
}

//*****************************************************************************
//
//! Configures the Ethernet MAC PPS output in simple mode.
//!
//! \param ui32Base is the base address of the controller.
//! \param ui32FreqConfig determines the frequency of the output generated on
//! the PPS pin.
//!
//! This function configures the Ethernet MAC PPS (Pulse Per Second) engine to
//! operate in its simple mode which allows the generation of a few, fixed
//! frequencies and pulse widths on the PPS pin.  If more complex pulse
//! train generation is required, the MAC also provides a command-based
//! PPS control mode which may be selected by calling
//! EMACTimestampPPSCommandModeSet().
//!
//! The \e ui32FreqConfig parameter may take one of the following values:
//!
//! - \b EMAC_PPS_SINGLE_PULSE generates a single high pulse on the PPS
//! output once per second.  The pulse width is the same as the system clock
//! period.
//! - \b EMAC_PPS_1HZ generates a 1Hz signal on the PPS output.  This option
//! is not available if the system time subsecond counter is currently
//! configured to operate in binary rollover mode.
//! - \b EMAC_PPS_2HZ, \b EMAC_PPS_4HZ, \b EMAC_PPS_8HZ,
//!   \b EMAC_PPS_16HZ, \b EMAC_PPS_32HZ, \b EMAC_PPS_64HZ,
//!   \b EMAC_PPS_128HZ, \b EMAC_PPS_256HZ, \b EMAC_PPS_512HZ,
//!   \b EMAC_PPS_1024HZ, \b EMAC_PPS_2048HZ, \b EMAC_PPS_4096HZ,
//!   \b EMAC_PPS_8192HZ, \b EMAC_PPS_16384HZ generate the requested
//! frequency on the PPS output in both binary and digital rollover modes.
//! - \b EMAC_PPS_32768HZ generates a 32KHz signal on the PPS output.  This
//! option is not available if the system time subsecond counter is currently
//! configured to operate in digital rollover mode.
//!
//! Except when \b EMAC_PPS_SINGLE_PULSE is specified, the signal generated
//! on PPS will have a duty cycle of 50% when binary rollover mode is used for
//! the system time subsecond count.  In digital mode, the output frequency
//! averages the value requested and is resynchronized each second.  For
//! example, if \b EMAC_PPS_4HZ is selected in digital rollover mode, the
//! output will generate three clocks with 50 percent duty cycle and 268ms
//! period followed by a fourth clock of 195mS period, 134mS low and 61mS high.
//!
//! \return None.
//
//*****************************************************************************
void
EMACTimestampPPSSimpleModeSet(uint32_t ui32Base, uint32_t ui32FreqConfig)
{
    bool bDigital;

    //
    // Parameter sanity check.
    //
    ASSERT(ui32Base == EMAC0_BASE);

    //
    // Are we currently running the clock in digital or binary rollover mode?
    //
    bDigital = (HWREG(ui32Base + EMAC_O_TIMSTCTRL) &
                EMAC_TS_DIGITAL_ROLLOVER) ? true : false;

    //
    // Weed out some unsupported frequencies.  The hardware can't produce a
    // 1Hz output when we are in binary rollover mode and can't produce a
    // 32KHz output when we are digital rollover mode.
    //
    ASSERT(bDigital || (ui32FreqConfig != EMAC_PPS_1HZ));
    ASSERT(!bDigital || (ui32FreqConfig != EMAC_PPS_32768HZ));

    //
    // Adjust the supplied frequency if we are currently in binary update mode
    // where the control value generates an output that is twice as fast as
    // in digital mode.
    //
    if((ui32FreqConfig != EMAC_PPS_SINGLE_PULSE) && !bDigital)
    {
        ui32FreqConfig--;
    }

    //
    // Write the frequency control value to the PPS control register, clearing
    // the PPSEN0 bit to ensure that the PPS engine is in simple mode and not
    // waiting for a command.  We also clear the TRGMODS0 field to revert to
    // the default operation of the target time registers.
    //
    HWREG(ui32Base + EMAC_O_PPSCTRL) = ui32FreqConfig;
}

//*****************************************************************************
//
//! Configures the Ethernet MAC PPS output in command mode.

//! \param ui32Base is the base address of the controller.
//! \param ui32Config determines how the system target time is used.
//!
//! The simple mode of operation offered by the PPS (Pulse Per Second) engine
//! may be too restrictive for some applications.  The second mode, however,
//! allows complex pulse trains to be generated using commands that tell the
//! engine to send individual pulses or start and stop trains if pulses.  In
//! this mode, the pulse width and period may be set arbitrarily based upon
//! ticks of the clock used to update the system time.  Commands are triggered
//! at specific times using the target time last set using a call to
//! EMACTimestampTargetSet().
//!
//! The \e ui32Config parameter may be used to control whether the target
//! time is used to trigger commands only or can also generate an interrupt
//! to the CPU.  Valid values are:
//!
//! - \b EMAC_PPS_TARGET_INT configures the target time to only raise
//! an interrupt and not to trigger any pending PPS command.
//! - \b EMAC_PPS_TARGET_PPS configures the target time to trigger a pending
//! PPS command but not raise an interrupt.
//! - \b EMAC_PPS_TARGET_BOTH configures the target time to trigger any
//! pending PPS command and also raise an interrupt.
//!
//! To use command mode, an application must call this function to enable the
//! mode, then call:
//!
//! - EMACTimestampPPSPeriodSet() to set the desired pulse width and period
//! then
//! - EMACTimestampTargetSet() to set the time at which the next command will
//! be executed, and finally
//! - EMACTimestampPPSCommand() to send a command to cause the pulse or
//! pulse train to be started at the required time.
//!
//! \return None.
//
//*****************************************************************************
void
EMACTimestampPPSCommandModeSet(uint32_t ui32Base, uint32_t ui32Config)
{
    //
    // Parameter sanity check.
    //
    ASSERT(ui32Base == EMAC0_BASE);
    ASSERT(!(ui32Config & (EMAC_PPS_TARGET_INT | EMAC_PPS_TARGET_PPS |
                           EMAC_PPS_TARGET_BOTH)));

    //
    // Wait for any previous command write to complete.
    //
    while(HWREG(ui32Base + EMAC_O_PPSCTRL) & EMAC_PPSCTRL_PPSCTRL_M)
    {
        //
        // Wait a bit.
        //
    }

    //
    // Write the configuration value to the PPS control register, setting the
    // PPSEN0 bit to ensure that the PPS engine is in command mode and
    // clearing the command in the PPSCTRL field.
    //
    HWREG(ui32Base + EMAC_O_PPSCTRL) = (EMAC_PPSCTRL_PPSEN0 | ui32Config);
}

//*****************************************************************************
//
//! Sends a command to control the PPS output from the Ethernet MAC.
//!
//! \param ui32Base is the base address of the controller.
//! \param ui8Cmd identifies the command to be sent.
//!
//! This function may be used to send a command to the MAC PPS (Pulse Per
//! Second) controller when it is operating in command mode.  Command mode
//! is selected by calling EMACTimestampPPSCommandModeSet(). Valid
//! commands are as follow:
//!
//! - \b EMAC_PPS_COMMAND_NONE indicates no command.
//! - \b EMAC_PPS_COMMAND_START_SINGLE indicates that a single high pulse
//! should be generate when the system time reaches the current target time.
//! - \b EMAC_PPS_COMMAND_START_TRAIN indicates that a train of pulses
//! should be started when the system time reaches the current target time.
//! - \b EMAC_PPS_COMMAND_CANCEL_START cancels any pending start command if
//! the system time has not yet reached the programmed target time.
//! - \b EMAC_PPS_COMMAND_STOP_AT_TIME indicates that the current pulse
//! train should be stopped when the system time reaches the current target
//! time.
//! - \b EMAC_PPS_COMMAND_STOP_NOW indicates that the current pulse train
//! should be stopped immediately.
//! - \b EMAC_PPS_COMMAND_CANCEL_STOP cancels any pending stop command if
//! the system time has not yet reached the programmed target time.
//!
//! In all cases, the width of the pulses generated is governed by the
//! \e ui32Width parameter passed to EMACTimestampPPSPeriodSet().  If a
//! command starts a train of pulses, the period of the pulses is governed
//! by the \e ui32Period parameter passed to the same function.
//! Target times associated with PPS commands are set by calling
//! EMACTimestampTargetSet().
//!
//! \return None.
//
//*****************************************************************************
void
EMACTimestampPPSCommand(uint32_t ui32Base, uint8_t ui8Cmd)
{
    //
    // Parameter sanity check.
    //
    ASSERT(ui32Base == EMAC0_BASE);

    //
    // Wait for any previous command write to complete.
    //
    while(HWREG(ui32Base + EMAC_O_PPSCTRL) & EMAC_PPSCTRL_PPSCTRL_M)
    {
        //
        // Wait a bit.
        //
    }

    //
    // Write the command to the PPS control register.
    //
    HWREG(ui32Base + EMAC_O_PPSCTRL) = (EMAC_PPSCTRL_PPSEN0 | ui8Cmd);
}

//*****************************************************************************
//
//! Sets the period and width of the pulses on the Ethernet MAC PPS output.
//!
//! \param ui32Base is the base address of the controller.
//! \param ui32Period is the period of the PPS output expressed in terms of
//! system time update ticks.
//! \param ui32Width is the width of the high portion of the PPS output
//! expressed in terms of system time update ticks.
//!
//! This function may be used to control the period and duty cycle of the
//! signal output on the Ethernet MAC PPS pin when the PPS generator is
//! operating in command mode and a command to send one or more pulses has been
//! executed.  Command mode is selected by calling
//! EMACTimestampPPSCommandModeSet().
//!
//! In simple mode the PPS output signal frequency is controlled by the
//! \e ui32FreqConfig parameter passed to EMACTimestampPPSSimpleModeSet().
//!
//! The \e ui32Period and \e ui32Width parameters are expressed in terms of
//! system time update ticks.  When the system time is operating in coarse
//! update mode, each tick is equivalent to the system clock.  In fine update
//! mode, a tick occurs every time the 32-bit system time accumulator overflows
//! and this, in turn, is determined by the value passed to the function
//! EMACTimestampAddendSet().  Regardless of the tick source, each tick will
//! increment the actual system time, queried using EMACTimestampSysTimeGet()
//! by the subsecond increment value passed in the \e ui32SubSecondInc to
//! EMACTimestampConfigSet().
//!
//! \return None.
//
//*****************************************************************************
void
EMACTimestampPPSPeriodSet(uint32_t ui32Base, uint32_t ui32Period,
                          uint32_t ui32Width)
{
    //
    // Parameter sanity check.
    //
    ASSERT(ui32Base == EMAC0_BASE);

    //
    // Write the desired PPS period and pulse width.
    //
    HWREG(ui32Base + EMAC_O_PPS0INTVL) = ui32Period;
    HWREG(ui32Base + EMAC_O_PPS0WIDTH) = ui32Width;
}

//*****************************************************************************
//
//! Sets options related to reception of VLAN-tagged frames.
//!
//! \param ui32Base is the base address of the controller.
//! \param ui16Tag is the IEEE 802.1Q VLAN tag expected for incoming frames.
//! \param ui32Config determines how the receiver handles VLAN-tagged frames.
//!
//! This function configures the receiver's handling of IEEE 802.1Q VLAN
//! tagged frames.  Incoming tagged frames are filtered using either a perfect
//! filter or a hash filter.  When hash filtering is disabled, VLAN frames
//! tagged with the value of \e ui16Tag pass the filter and all others are
//! rejected.  The tag comparison may involve all 16 bits or only the 12-bit
//! VLAN ID portion of the tag.
//!
//! The \e ui32Config parameter is a logical OR of the following values:
//!
//! - \b EMAC_VLAN_RX_HASH_ENABLE enables hash filtering for VLAN tags.  If
//! this flag is absent, perfect filtering using the tag supplied in \e ui16Tag
//! is performed.  The hash filter may be set using EMACVLANHashFilterSet()
//! and EMACVLANHashFilterBitCalculate() may be used to determine which bits
//! to set in the filter for given VLAN tags.
//! - \b EMAC_VLAN_RX_SVLAN_ENABLE causes the receiver to recognize S-VLAN
//! (Type = 0x88A8) frames as valid VLAN-tagged frames.  If absent, only
//! frames with type 0x8100 are considered valid VLAN frames.
//! - \b EMAC_VLAN_RX_INVERSE_MATCH causes the receiver to pass all VLAN
//! frames whose tags do not match the supplied \e ui16Tag value.  If this
//! flag is absent, only tagged frames matching \e ui16Tag are passed.
//! - \b EMAC_VLAN_RX_12BIT_TAG causes the receiver to compare only the
//! bottom 12 bits of \e ui16Tag when performing either perfect or hash
//! filtering of VLAN frames.  If this flag is absent, all 16 bits of the frame
//! tag are examined when filtering.  If this flag is set and \e ui16Tag has
//! all bottom 12 bits clear, the receiver will pass all frames with types
//! 0x8100 or 0x88A8 regardless of the tag values they contain.
//!
//! \note To ensure that VLAN frames which fail the tag filter are dropped
//! by the MAC, EMACFrameFilterSet() must be called with the \b
//! EMAC_FRMFILTER_VLAN flag set in the \e ui32FilterOpts parameter.  If
//! this flag is not set, failing VLAN packets will be received by the
//! application but bit 10 of RDES0 (\b EMAC_FRMFILTER_VLAN) will be clear
//! indicating that the packet did not match the current VLAG tag filter.
//!
//! \sa EMACVLANRxConfigGet()
//!
//! \return None
//
//*****************************************************************************
void
EMACVLANRxConfigSet(uint32_t ui32Base, uint16_t ui16Tag, uint32_t ui32Config)
{
    //
    // Parameter sanity check.
    //
    ASSERT(ui32Base == EMAC0_BASE);

    //
    // Write the VLAN tag register.
    //
    HWREG(ui32Base + EMAC_O_VLANTG) =
        ui32Config | (((uint32_t)ui16Tag) << EMAC_VLANTG_VL_S);
}

//*****************************************************************************
//
//! Returns the currently-set options related to reception of VLAN-tagged
//! frames.
//!
//! \param ui32Base is the base address of the controller.
//! \param pui16Tag points to storage which is written with the currently
//! configured VLAN tag used for perfect filtering.
//!
//! This function returns information on how the receiver is currently
//! handling IEEE 802.1Q VLAN-tagged frames.
//!
//! \sa EMACVLANRxConfigSet()
//!
//! \return Returns flags defining how VLAN-tagged frames are handled.  The
//! value will be a logical OR of the following flags:
//!
//! - \b EMAC_VLAN_RX_HASH_ENABLE indicates that hash filtering is enabled
//! for VLAN tags.  If this flag is absent, perfect filtering using the tag
//! returned in \e *pui16Tag is performed.
//! - \b EMAC_VLAN_RX_SVLAN_ENABLE indicates that the receiver recognizes
//! S-VLAN (Type = 0x88A8) frames as valid VLAN-tagged frames.  If absent, only
//! frames with type 0x8100 are considered valid VLAN frames.
//! - \b EMAC_VLAN_RX_INVERSE_MATCH indicates that the receiver passes all
//! VLAN frames whose tags do not match the \e *pui16Tag value.  If this
//! flag is absent, only tagged frames matching \e *pui16Tag are passed.
//! - \b EMAC_VLAN_RX_12BIT_TAG indicates that the receiver is comparing only
//! the bottom 12 bits of \e *pui16Tag when performing either perfect or hash
//! filtering of VLAN frames.  If this flag is absent, all 16 bits of the frame
//! tag are examined when filtering.  If this flag is set and \e *pui16Tag has
//! all bottom 12 bits clear, the receiver will pass all frames with types
//! 0x8100 or 0x88A8 regardless of the tag values they contain.
//
//*****************************************************************************
uint32_t
EMACVLANRxConfigGet(uint32_t ui32Base, uint16_t *pui16Tag)
{
    uint32_t ui32Value;

    //
    // Parameter sanity check.
    //
    ASSERT(ui32Base == EMAC0_BASE);
    ASSERT(pui16Tag);

    //
    // Read the VLAN tag register.
    //
    ui32Value = HWREG(ui32Base + EMAC_O_VLANTG);

    //
    // Extract the VLAN tag from the register.
    //
    *pui16Tag = (ui32Value & EMAC_VLANTG_VL_M) >> EMAC_VLANTG_VL_S;

    //
    // Return the configuration flags.
    //
    return(ui32Value & ~EMAC_VLANTG_VL_M);
}

//*****************************************************************************
//
//! Sets options related to transmission of VLAN-tagged frames.
//!
//! \param ui32Base is the base address of the controller.
//! \param ui16Tag is the VLAN tag to be used when inserting or replacing tags
//! in transmitted frames.
//! \param ui32Config determines the VLAN-related processing performed by
//! the transmitter.
//!
//! This function is used to configure transmitter options relating to
//! IEEE 802.1Q VLAN tagging.  The transmitter may be set to insert tagging
//! into untagged frames or replace existing tags with new values.
//!
//! The \e ui16Tag parameter contains the VLAN tag that is to be used in
//! outgoing tagged frames.  The \e ui32Config parameter is a logical OR of
//! the following labels:
//!
//! - \b EMAC_VLAN_TX_SVLAN uses the S-VLAN type (0x88A8) when inserting or
//! replacing tags in transmitted frames.  If this label is absent, C-VLAN
//! type (0x8100) is used.
//! - \b EMAC_VLAN_TX_USE_VLC informs the transmitter that the VLAN tag
//! handling should be defined by the VLAN control (VLC) value provided in
//! this function call.  If this tag is absent, VLAN handling is controlled
//! by fields in the transmit descriptor.
//!
//! If \b EMAC_VLAN_TX_USE_VLC is set, one of the following four labels
//! must also be included to define the transmit VLAN tag handling:
//!
//! - \b EMAC_VLAN_TX_VLC_NONE instructs the transmitter to perform no VLAN
//! tag insertion, deletion or replacement.
//! - \b EMAC_VLAN_TX_VLC_DELETE instructs the transmitter to remove VLAN
//! tags from all transmitted frames which contain them.  This removes bytes
//! 13, 14, 15 and 16 from all frames with types 0x8100 or 0x88A8.
//! - \b EMAC_VLAN_TX_VLC_INSERT instructs the transmitter to insert a VLAN
//! type and tag into all outgoing frames regardless of whether or not they
//! already contain a VLAN tag.
//! - \b EMAC_VLAN_TX_VLC_REPLACE instructs the transmitter to replace the
//! VLAN tag in all frames of type 0x8100 or 0x88A8 with the value provided to
//! this function in the \e ui16Tag parameter.
//!
//! \return None
//
//*****************************************************************************
void
EMACVLANTxConfigSet(uint32_t ui32Base, uint16_t ui16Tag, uint32_t ui32Config)
{
    //
    // Parameter sanity check.
    //
    ASSERT(ui32Base == EMAC0_BASE);

    //
    // Write the VLAN Tag Inclusion or Replacement register.
    //
    HWREG(ui32Base + EMAC_O_VLNINCREP) =
        ui32Config | ((uint32_t)ui16Tag << EMAC_VLNINCREP_VLT_S);
}

//*****************************************************************************
//
//! Returns currently-selected options related to transmission of VLAN-tagged
//! frames.
//!
//! \param ui32Base is the base address of the controller.
//! \param pui16Tag points to storage which is written with the VLAN tag
//! currently being used for insertion or replacement.
//!
//! This function returns information on the current settings related to VLAN
//! tagging of transmitted frames.
//!
//! \sa EMACVLANTxConfigSet()
//!
//! \return Returns flags describing the current VLAN configuration relating
//! to frame transmission.  The return value is a logical OR of the following
//! values:
//!
//! - \b EMAC_VLAN_TX_SVLAN indicates that the S-VLAN type (0x88A8) is
//! being used when inserting or replacing tags in transmitted frames.  If
//! this label is absent, C-VLAN type (0x8100) is being used.
//! - \b EMAC_VLAN_TX_USE_VLC indicates that the transmitter is processing
//! VLAN frames according to the VLAN control (VLC) value returned here.  If
//! this tag is absent, VLAN handling is controlled by fields in the transmit
//! descriptor.
//!
//! If \b EMAC_VLAN_TX_USE_VLC is returned, one of the following four labels
//! is also included to define the transmit VLAN tag handling.  Note that this
//! value may be extracted from the return value using the mask \b
//! EMAC_VLAN_TX_VLC_MASK.
//!
//! - \b EMAC_VLAN_TX_VLC_NONE indicates that the transmitter is not
//! performing VLAN tag insertion, deletion or replacement.
//! - \b EMAC_VLAN_TX_VLC_DELETE indicates that the transmitter is removing
//! VLAN tags from all transmitted frames which contain them.
//! - \b EMAC_VLAN_TX_VLC_INSERT indicates that the transmitter is inserting
//! a VLAN type and tag into all outgoing frames regardless of whether or not
//! they already contain a VLAN tag.
//! - \b EMAC_VLAN_TX_VLC_REPLACE indicates that the transmitter is replacing
//! the VLAN tag in all transmitted frames of type 0x8100 or 0x88A8 with the
//! value returned in \e *pui16Tag.
//
//*****************************************************************************
uint32_t
EMACVLANTxConfigGet(uint32_t ui32Base, uint16_t *pui16Tag)
{
    uint32_t ui32Value;

    //
    // Parameter sanity check.
    //
    ASSERT(ui32Base == EMAC0_BASE);
    ASSERT(pui16Tag);

    //
    // Read the VLAN Tag Inclusion or Replacement register.
    //
    ui32Value = HWREG(ui32Base + EMAC_O_VLNINCREP);

    //
    // Extract the tag.
    //
    *pui16Tag = (uint16_t)((ui32Value & EMAC_VLNINCREP_VLT_M) >>
                           EMAC_VLNINCREP_VLT_S);

    //
    // Return the configuration flags.
    //
    return(ui32Value & ~EMAC_VLNINCREP_VLT_M);
}

//*****************************************************************************
//
//! Returns the bit number to set in the VLAN hash filter corresponding to a
//! given tag.
//!
//! \param ui16Tag is the VLAN tag whose hash filter bit number is to be
//! determined.
//!
//! This function may be used to determine which bit in the VLAN hash filter
//! to set to describe a given 12- or 16-bit VLAN tag.  The returned value is
//! a 4 bit value indicating the bit number to set within the 16-bit VLAN
//! hash filter. For example, if 0x02 is returned, this indicates that bit
//! 2 of the hash filter must be set to pass the supplied VLAN tag.
//!
//! \return Returns the bit number to set in the VLAN hash filter to describe
//! the passed tag.
//
//*****************************************************************************
uint32_t
EMACVLANHashFilterBitCalculate(uint16_t ui16Tag)
{
    uint32_t ui32CRC, ui32Mask, ui32Loop;

    //
    // Calculate the CRC for the MAC address.
    //
    ui32CRC = Crc32(0xFFFFFFFF, (uint8_t *)&ui16Tag, 2);
    ui32CRC ^= 0xFFFFFFFF;

    //
    // Determine the hash bit to use from the calculated CRC.  This is the
    // top 4 bits of the reversed CRC (or the bottom 4 bits of the calculated
    // CRC with the bit order of those 4 bits reversed).
    //
    ui32Mask = 0;

    //
    // Reverse the order of the bottom 4 bits of the calculated CRC.
    //
    for(ui32Loop = 0; ui32Loop < 4; ui32Loop++)
    {
        ui32Mask <<= 1;
        ui32Mask |= (ui32CRC & 1);
        ui32CRC >>= 1;
    }

    //
    // Return the final hash filter bit index.
    //
    return(ui32Mask);
}

//*****************************************************************************
//
//! Sets the hash filter used to control reception of VLAN-tagged frames.
//!
//! \param ui32Base is the base address of the controller.
//! \param ui32Hash is the hash filter value to set.
//!
//! This function allows the VLAG tag hash filter to be set.  By using hash
//! filtering, several different VLAN tags can be filtered very easily at the
//! cost of some false positive results which must be removed by software.
//!
//! The hash filter value passed in \e ui32Hash may be built up by calling
//! EMACVLANHashFilterBitCalculate() for each VLAN tag which is to pass the
//! filter and then setting each of the bits whose numbers are returned by
//! that function.  Care must be taken when clearing bits in the hash filter
//! due to the fact that there is a many-to-one correspondence between VLAN
//! tags and hash filter bits.
//!
//! \return None
//
//*****************************************************************************
void
EMACVLANHashFilterSet(uint32_t ui32Base, uint32_t ui32Hash)
{
    //
    // Parameter sanity check.
    //
    ASSERT(ui32Base == EMAC0_BASE);

    //
    // Write the VLAN Hash Table register.
    //
    HWREG(ui32Base + EMAC_O_VLANHASH) = ui32Hash;
}

//*****************************************************************************
//
//! Returns the current value of the hash filter used to control reception of
//! VLAN-tagged frames.
//!
//! \param ui32Base is the base address of the controller.
//!
//! This function allows the current VLAN tag hash filter value to be returned.
//! Additional VLAN tags may be added to this filter by setting the appropriate
//! bits, determined by calling EMACVLANHashFilterBitCalculate(), and then
//! calling EMACVLANHashFilterSet() to set the new filter value.
//!
//! \return Returns the current value of the VLAN hash filter.
//
//*****************************************************************************
uint32_t
EMACVLANHashFilterGet(uint32_t ui32Base)
{
    //
    // Parameter sanity check.
    //
    ASSERT(ui32Base == EMAC0_BASE);

    //
    // Return the VLAN Hash Table register.
    //
    return(HWREG(ui32Base + EMAC_O_VLANHASH));
}

//*****************************************************************************
//
//! Sets values defining up to four frames use to trigger a remote wake-up.
//!
//! \param ui32Base is the base address of the controller.
//! \param pFilter points to the structure containing remote wake-up frame
//! filter information.
//!
//! This function may be used to define up to four different frames which
//! are considered by the Ethernet MAC to be remote wake-up signals.  The
//! data passed to the function describes a wake-up frame in terms of a CRC
//! calculated on up to 31 payload bytes in the frame.  The actual bytes used
//! in the CRC calculation are defined by means of a bit mask where a ``1''
//! indicates that a byte in the frame should contribute to the CRC
//! calculation and a ``0'' indicates that the byte should be skipped, and an
//! offset from the start of the frame to payload byte which represents the
//! first byte in the 31-byte CRC-checked sequence.
//!
//! The \e pFilter parameter points to a structure containing the information
//! necessary to set up the filters.  This structure contains the following
//! fields, each of which is replicated 4 times, once for each possible wake-up
//! frame:
//!
//! - \b pui32ByteMask defines whether a given byte in the chosen 31-byte
//! sequence within the frame should contribute to the CRC calculation or not.
//! A 1 indicates that the byte should contribute to the calculation, a 0
//! causes the byte to be skipped.
//! - \b pui8Command contains flags defining whether this filter is enabled
//! and, if so, whether it refers to unicast or multicast packets.  Valid
//! values are one of \b EMAC_RWU_FILTER_MULTICAST or \b
//! EMAC_RWU_FILTER_UNICAST ORed with one of \b EMAC_RWU_FILTER_ENABLE or
//! \b EMAC_RWU_FILTER_DISABLE.
//! - \b pui8Offset defines the zero-based index of the byte within the frame
//! at which CRC checking defined by \b pui32ByteMask will begin.
//! Alternatively, this value can be thought of as the number of bytes in the
//! that the MAC will skip before accumulating the CRC based on the pattern
//! in \b pui32ByteMask.
//! - \b pui16CRC provides the value of the calculated CRC for a valid remote
//! wake-up frame.  If the incoming frame is processed according to the filter
//! values provided and the final CRC calculation equals this value, the
//! frame is considered to be a valid remote wake-up frame.
//!
//! Note that this filter uses CRC16 rather than CRC32 as used in frame
//! checksums. The required CRC uses a direct algorithm with polynomial 0x8005,
//! initial seed value 0xFFFF, no final XOR and reversed data order.  CRCs
//! for use in this function may be determined using the online calculator
//! found at http://www.zorc.breitbandkatze.de/crc.html.
//!
//! \return None.
//
//*****************************************************************************
void
EMACRemoteWakeUpFrameFilterSet(uint32_t ui32Base,
                               const tEMACWakeUpFrameFilter *pFilter)
{
    uint32_t *pui32Data;
    uint32_t ui32Loop;

    //
    // Parameter sanity check.
    //
    ASSERT(ui32Base == EMAC0_BASE);
    ASSERT(pFilter);

    //
    // Make sure that the internal register counter for the frame filter
    // is reset.  This bit automatically resets after 1 clock cycle.
    //
    HWREG(ui32Base + EMAC_O_PMTCTLSTAT) |= EMAC_PMTCTLSTAT_WUPFRRST;

    //
    // Get a word pointer to the supplied structure.
    //
    pui32Data = (uint32_t *)pFilter;

    //
    // Write the 8 words of the wake-up filter definition to the hardware.
    //
    for(ui32Loop = 0; ui32Loop < 8; ui32Loop++)
    {
        //
        // Write a word of the filter definition.
        //
        HWREG(ui32Base + EMAC_O_RWUFF) = pui32Data[ui32Loop];
    }
}

//*****************************************************************************
//
//! Returns the current remote wake-up frame filter configuration.
//!
//! \param ui32Base is the base address of the controller.
//! \param pFilter points to the structure which is written with the current
//! remote wake-up frame filter information.
//!
//! This function may be used to read the current wake-up frame filter
//! settings.  The data returned by the function describes wake-up frames in
//! terms of a CRC calculated on up to 31 payload bytes in the frame.  The
//! actual bytes used in the CRC calculation are defined by means of a bit mask
//! where a ``1'' indicates that a byte in the frame should contribute to the
//! CRC calculation and a ``0'' indicates that the byte should be skipped, and
//! an offset from the start of the frame to payload byte which represents the
//! first byte in the 31-byte CRC-checked sequence.
//!
//! The \e pFilter parameter points to storage which is written with a
//! structure containing the information defining the frame filters.  This
//! structure contains the following fields, each of which is replicated 4
//! times, once for each possible wake-up frame:
//!
//! - \b pui32ByteMask defines whether a given byte in the chosen 31-byte
//! sequence within the frame should contribute to the CRC calculation or not.
//! A 1 indicates that the byte should contribute to the calculation, a 0
//! causes the byte to be skipped.
//! - \b pui8Command contains flags defining whether this filter is enabled
//! and, if so, whether it refers to unicast or multicast packets.  Valid
//! values are one of \b EMAC_RWU_FILTER_MULTICAST or \b
//! EMAC_RWU_FILTER_UNICAST ORed with one of \b EMAC_RWU_FILTER_ENABLE or
//! \b EMAC_RWU_FILTER_DISABLE.
//! - \b pui8Offset defines the zero-based index of the byte within the frame
//! at which CRC checking defined by \b pui32ByteMask will begin.
//! Alternatively, this value can be thought of as the number of bytes in the
//! that the MAC will skip before accumulating the CRC based on the pattern
//! in \b pui32ByteMask.
//! - \b pui16CRC provides the value of the calculated CRC for a valid remote
//! wake-up frame.  If the incoming frame is processed according to the filter
//! values provided and the final CRC calculation equals this value, the
//! frame is considered to be a valid remote wake-up frame.
//!
//! Note that this filter uses CRC16 rather than CRC32 as used in frame
//! checksums.
//!
//! \return None.
//
//*****************************************************************************
void
EMACRemoteWakeUpFrameFilterGet(uint32_t ui32Base,
                               tEMACWakeUpFrameFilter *pFilter)
{
    uint32_t *pui32Data;
    uint32_t ui32Loop;

    //
    // Parameter sanity check.
    //
    ASSERT(ui32Base == EMAC0_BASE);
    ASSERT(pFilter);

    //
    // Make sure that the internal register counter for the frame filter
    // is reset.  This bit automatically resets after 1 clock cycle.
    //
    HWREG(ui32Base + EMAC_O_PMTCTLSTAT) |= EMAC_PMTCTLSTAT_WUPFRRST;

    //
    // Get a word pointer to the supplied structure.
    //
    pui32Data = (uint32_t *)pFilter;

    //
    // Read the 8 words of the wake-up filter definition from the hardware.
    //
    for(ui32Loop = 0; ui32Loop < 8; ui32Loop++)
    {
        //
        // Read a word of the filter definition.
        //
        pui32Data[ui32Loop] = HWREG(ui32Base + EMAC_O_RWUFF);
    }
}

//*****************************************************************************
//
//! Sets the Ethernet MAC remote wake-up configuration.
//!
//! \param ui32Base is the base address of the controller.
//! \param ui32Flags defines which types of frame should trigger a remote
//! wake-up and allows the MAC to be put into power-down mode.
//!
//! This function allows the MAC's remote wake-up features to be configured,
//! determining which types of frame should trigger a wake-up event and
//! allowing an application to place the MAC in power-down mode.  In this
//! mode, the MAC will ignore all received frames until one matching a
//! configured remote wake-up frame is received, at which point the MAC will
//! automatically exit power-down mode and continue to receive frames.
//!
//! The \e ui32Flags parameter is a logical OR of the following flags:
//!
//! - \b EMAC_PMT_GLOBAL_UNICAST_ENABLE instructs the MAC to wake up when any
//! unicast frame matching the MAC destination address filter is received.
//! - \b EMAC_PMT_WAKEUP_PACKET_ENABLE instructs the MAC to wake up when any
//! received frame matches the remote wake-up filter configured via a call
//! to EMACRemoteWakeupFrameFilterSet().
//! - \b EMAC_PMT_MAGIC_PACKET_ENABLE instructs the MAC to wake up when a
//! standard Wake-on-LAN "magic packet" is received.  The magic packet contains
//! 6 bytes of 0xFF followed immediately by 16 repetitions of the destination
//! MAC address.
//! - \b EMAC_PMT_POWER_DOWN instructs the MAC to enter power-down mode and
//! wait for an incoming frame matching the remote wake-up frames as described
//! by other flags and via the remote wake-up filter.  This flag should only
//! set set if at least one other flag is specified to configure a wake-up
//! frame type.
//!
//! When the MAC is in power-down mode, software may exit the mode by calling
//! this function with the \b EMAC_PMT_POWER_DOWN flag absent from \e ui32Flags.
//! If a configured wake-up frame is received while in power-down mode, the
//! \b EMAC_INT_POWER_MGMNT interrupt will be signaled and this may be cleared
//! by reading the status using EMACPowerManagementStatusGet().
//!
//! \note While it is possible to gate the clock to the MAC while it is in
//! power-down mode, doing so will prevent the reading of the registers
//! required to determine the interrupt status and will also prevent power-down
//! mode from exiting via another call to this function.
//!
//! \return None.
//
//*****************************************************************************
void
EMACPowerManagementControlSet(uint32_t ui32Base, uint32_t ui32Flags)
{
    uint32_t ui32Value;

    //
    // Parameter sanity check.
    //
    ASSERT(ui32Base == EMAC0_BASE);
    ASSERT(~(ui32Flags & ~(EMAC_PMT_GLOBAL_UNICAST_ENABLE |
                           EMAC_PMT_WAKEUP_PACKET_ENABLE |
                           EMAC_PMT_MAGIC_PACKET_ENABLE |
                           EMAC_PMT_POWER_DOWN)));

    //
    // Read the control/status register, clear all the bits we can set, mask
    // in the new values then rewrite the new register value.
    //
    ui32Value = HWREG(ui32Base + EMAC_O_PMTCTLSTAT);
    ui32Value &= ~(EMAC_PMTCTLSTAT_GLBLUCAST | EMAC_PMTCTLSTAT_WUPFREN |
                   EMAC_PMTCTLSTAT_MGKPKTEN | EMAC_PMTCTLSTAT_PWRDWN);
    ui32Value |= ui32Flags;
    HWREG(ui32Base + EMAC_O_PMTCTLSTAT) = ui32Value;
}

//*****************************************************************************
//
//! Queries the current Ethernet MAC remote wake-up configuration.
//!
//! \param ui32Base is the base address of the controller.
//!
//! This function allows the MAC's remote wake-up settings to be queried.
//! These settings determine which types of frame should trigger a remote
//! wake-up event
//!
//! \return Returns a logical OR of the following flags:
//!
//! - \b EMAC_PMT_GLOBAL_UNICAST_ENABLE indicates that the MAC wakes up when
//! any unicast frame matching the MAC destination address filter is received.
//! - \b EMAC_PMT_WAKEUP_PACKET_ENABLE indicates that the MAC wakes up when any
//! received frame matches the remote wake-up filter configured via a call
//! to EMACRemoteWakeupFrameFilterSet().
//! - \b EMAC_PMT_MAGIC_PACKET_ENABLE indicates that the MAC wakes up when a
//! standard Wake-on-LAN "magic packet" is received.  The magic packet contains
//! 6 bytes of 0xFF followed immediately by 16 repetitions of the destination
//! MAC address.
//! - \b EMAC_PMT_POWER_DOWN indicates that the MAC is currently in power-down
//! mode and is  waiting for an incoming frame matching the remote wake-up
//! frames as described by other returned flags and via the remote wake-up
//! filter.
//
//*****************************************************************************
uint32_t
EMACPowerManagementControlGet(uint32_t ui32Base)
{
    //
    // Parameter sanity check.
    //
    ASSERT(ui32Base == EMAC0_BASE);

    //
    // Read the control/status register and mask off the control bits to return
    // them to the caller.
    //
    return(HWREG(ui32Base + EMAC_O_PMTCTLSTAT) &
           (EMAC_PMTCTLSTAT_GLBLUCAST | EMAC_PMTCTLSTAT_WUPFREN |
            EMAC_PMTCTLSTAT_MGKPKTEN | EMAC_PMTCTLSTAT_PWRDWN));
}

//*****************************************************************************
//
//! Queries the current Ethernet MAC remote wake-up status.
//!
//! \param ui32Base is the base address of the controller.
//!
//! This function returns information on the remote wake-up state of the
//! Ethernet MAC. If the MAC has been woken up since the last call, the
//! returned value indicates the type of received frame which caused the MAC
//! to exit power-down state.
//!
//! \return Returns a logical OR of the following flags:
//!
//! - \b EMAC_PMT_POWER_DOWN indicates that the MAC is currently in power-down
//! mode.
//! - \b EMAC_PMT_WAKEUP_PACKET_RECEIVED indicates that the MAC exited
//! power-down mode due to a remote wake-up frame being received.  This
//! function call clears this flag.
//! - \b EMAC_PMT_MAGIC_PACKET_RECEIVED indicates that the MAC exited
//! power-down mode due to a wake-on-LAN magic packet being received.  This
//! function call clears this flag.
//
//*****************************************************************************
uint32_t
EMACPowerManagementStatusGet(uint32_t ui32Base)
{
    //
    // Parameter sanity check.
    //
    ASSERT(ui32Base == EMAC0_BASE);

    //
    // Read the control/status register and mask off the status bits to return
    // them to the caller.
    //
    return(HWREG(ui32Base + EMAC_O_PMTCTLSTAT) &
           (EMAC_PMTCTLSTAT_WUPRX | EMAC_PMTCTLSTAT_MGKPRX |
            EMAC_PMTCTLSTAT_PWRDWN));
}

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************
