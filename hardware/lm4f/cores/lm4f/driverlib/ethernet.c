//*****************************************************************************
//
// ethernet.c - Driver for the Integrated Ethernet Controller
//
// Copyright (c) 2006-2012 Texas Instruments Incorporated.  All rights reserved.
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
// This is part of revision 9453 of the Stellaris Peripheral Driver Library.
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup ethernet_api
//! @{
//
//*****************************************************************************

#include "inc/hw_ethernet.h"
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/debug.h"
#include "driverlib/ethernet.h"
#include "driverlib/interrupt.h"

//*****************************************************************************
//
//! Initializes the Ethernet controller for operation.
//!
//! \param ulBase is the base address of the controller.
//! \param ulEthClk is the rate of the clock supplied to the Ethernet module.
//!
//! This function prepares the Ethernet controller for first-time use in
//! a given hardware/software configuration.  This function should be called
//! before any other Ethernet API functions are called.
//!
//! The peripheral clock is the same as the processor clock.  This value is
//! returned by SysCtlClockGet(), or it can be explicitly hard-coded if it is
//! constant and known (to save the code/execution overhead of a call to
//! SysCtlClockGet()).
//!
//! This function replaces the original EthernetInit() API and performs the
//! same actions.  A macro is provided in <tt>ethernet.h</tt> to map the
//! original API to this API.
//!
//! \note If the device configuration is changed (for example, the system clock
//! is reprogrammed to a different speed), then the Ethernet controller must be
//! disabled by calling the EthernetDisable() function and the controller must
//! be reinitialized by calling the EthernetInitExpClk() function again.  After
//! the controller has been reinitialized, the controller should be
//! reconfigured using the appropriate Ethernet API calls.
//!
//! \return None.
//
//*****************************************************************************
void
EthernetInitExpClk(unsigned long ulBase, unsigned long ulEthClk)
{
    unsigned long ulDiv;

    //
    // Check the arguments.
    //
    ASSERT(ulBase == ETH_BASE);

    //
    // Set the Management Clock Divider register for access to the PHY
    // register set (via EthernetPHYRead/Write).
    //
    // The MDC clock divided down from the system clock using the following
    // formula.  A maximum of 2.5MHz is allowed for F(mdc).
    //
    //      F(mdc) = F(sys) / (2 * (div + 1))
    //      div = (F(sys) / (2 * F(mdc))) - 1
    //      div = (F(sys) / 2 / F(mdc)) - 1
    //
    // Note: Because we should round up, to ensure we don't violate the
    // maximum clock speed, we can simplify this as follows:
    //
    //      div = F(sys) / 2 / F(mdc)
    //
    // For example, given a system clock of 6.0MHz, and a div value of 1,
    // the mdc clock would be programmed as 1.5 MHz.
    //
    ulDiv = (ulEthClk / 2) / 2500000;
    HWREG(ulBase + MAC_O_MDV) = (ulDiv & MAC_MDV_DIV_M);
}

//*****************************************************************************
//
//! Sets the configuration of the Ethernet controller.
//!
//! \param ulBase is the base address of the controller.
//! \param ulConfig is the configuration for the controller.
//!
//! After the EthernetInitExpClk() function has been called, this API function
//! can be used to configure the various features of the Ethernet controller.
//!
//! The Ethernet controller provides three control registers that are used
//! to configure the controller's operation.  The transmit control register
//! provides settings to enable full-duplex operation, to auto-generate the
//! frame check sequence, and to pad the transmit packets to the minimum
//! length as required by the IEEE standard.  The receive control register
//! provides settings to enable reception of packets with bad frame check
//! sequence values and to enable multi-cast or promiscuous modes.  The
//! timestamp control register provides settings that enable support logic in
//! the controller that allow the use of the General Purpose Timer 3 to capture
//! timestamps for the transmitted and received packets. Note that not all
//! devices support this functionality; see the data sheet to determine if
//! this feature is supported.
//!
//! The \e ulConfig parameter is the logical OR of the following values:
//!
//! - \b ETH_CFG_TS_TSEN - Enable TX and RX interrupt status as CCP timer
//! inputs
//! - \b ETH_CFG_RX_BADCRCDIS - Disable reception of packets with a bad CRC
//! - \b ETH_CFG_RX_PRMSEN - Enable promiscuous mode reception (all packets)
//! - \b ETH_CFG_RX_AMULEN - Enable reception of multicast packets
//! - \b ETH_CFG_TX_DPLXEN - Enable full duplex transmit mode
//! - \b ETH_CFG_TX_CRCEN - Enable transmit with auto CRC generation
//! - \b ETH_CFG_TX_PADEN - Enable padding of transmit data to minimum size
//!
//! These bit-mapped values are programmed into the transmit, receive, and/or
//! timestamp control register.
//!
//! \return None.
//
//*****************************************************************************
void
EthernetConfigSet(unsigned long ulBase, unsigned long ulConfig)
{
    unsigned long ulTemp;

    //
    // Check the arguments.
    //
    ASSERT(ulBase == ETH_BASE);
    ASSERT((ulConfig & ~(ETH_CFG_TX_DPLXEN | ETH_CFG_TX_CRCEN |
                         ETH_CFG_TX_PADEN | ETH_CFG_RX_BADCRCDIS |
                         ETH_CFG_RX_PRMSEN | ETH_CFG_RX_AMULEN |
                         ETH_CFG_TS_TSEN)) == 0);

    //
    // Setup the Transmit Control Register.
    //
    ulTemp  = HWREG(ulBase + MAC_O_TCTL);
    ulTemp &= ~(MAC_TCTL_DUPLEX | MAC_TCTL_CRC | MAC_TCTL_PADEN);
    ulTemp |= ulConfig & 0x0FF;
    HWREG(ulBase + MAC_O_TCTL) = ulTemp;

    //
    // Setup the Receive Control Register.
    //
    ulTemp  = HWREG(ulBase + MAC_O_RCTL);
    ulTemp &= ~(MAC_RCTL_BADCRC | MAC_RCTL_PRMS | MAC_RCTL_AMUL);
    ulTemp |= (ulConfig >> 8) & 0x0FF;
    HWREG(ulBase + MAC_O_RCTL) = ulTemp;

    //
    // Setup the Time Stamp Configuration register.
    //
    ulTemp = HWREG(ulBase + MAC_O_TS);
    ulTemp &= ~(MAC_TS_TSEN);
    ulTemp |= (ulConfig >> 16) & 0x0FF;
    HWREG(ulBase + MAC_O_TS) = ulTemp;
}

//*****************************************************************************
//
//! Gets the current configuration of the Ethernet controller.
//!
//! \param ulBase is the base address of the controller.
//!
//! This function queries the control registers of the Ethernet controller
//! and returns a bit-mapped configuration value.
//!
//! \sa The description of the EthernetConfigSet() function provides detailed
//! information for the bit-mapped configuration values that are returned.
//!
//! \return Returns the bit-mapped Ethernet controller configuration value.
//
//*****************************************************************************
unsigned long
EthernetConfigGet(unsigned long ulBase)
{
    unsigned long ulConfig;

    //
    // Check the arguments.
    //
    ASSERT(ulBase == ETH_BASE);

    //
    // Read and return the Ethernet controller configuration parameters,
    // properly shifted into the appropriate bit field positions.
    //
    ulConfig = HWREG(ulBase + MAC_O_TS) << 16;
    ulConfig |= (HWREG(ulBase + MAC_O_RCTL) & ~(MAC_RCTL_RXEN)) << 8;
    ulConfig |= HWREG(ulBase + MAC_O_TCTL) & ~(MAC_TCTL_TXEN);
    return(ulConfig);
}

//*****************************************************************************
//
//! Sets the MAC address of the Ethernet controller.
//!
//! \param ulBase is the base address of the controller.
//! \param pucMACAddr is the pointer to the array of MAC-48 address octets.
//!
//! This function programs the IEEE-defined MAC-48 address specified in
//! \e pucMACAddr into the Ethernet controller.  This address is used by the
//! Ethernet controller for hardware-level filtering of incoming Ethernet
//! packets (when promiscuous mode is not enabled).
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
//! \return None.
//
//*****************************************************************************
void
EthernetMACAddrSet(unsigned long ulBase, unsigned char *pucMACAddr)
{
    unsigned long ulTemp;
    unsigned char *pucTemp = (unsigned char *)&ulTemp;

    //
    // Check the arguments.
    //
    ASSERT(ulBase == ETH_BASE);
    ASSERT(pucMACAddr != 0);

    //
    // Program the MAC Address into the device.  The first four bytes of the
    // MAC Address are placed into the IA0 register.  The remaining two bytes
    // of the MAC address are placed into the IA1 register.
    //
    pucTemp[0] = pucMACAddr[0];
    pucTemp[1] = pucMACAddr[1];
    pucTemp[2] = pucMACAddr[2];
    pucTemp[3] = pucMACAddr[3];
    HWREG(ulBase + MAC_O_IA0) = ulTemp;
    ulTemp = 0;
    pucTemp[0] = pucMACAddr[4];
    pucTemp[1] = pucMACAddr[5];
    HWREG(ulBase + MAC_O_IA1) = ulTemp;
}

//*****************************************************************************
//
//! Gets the MAC address of the Ethernet controller.
//!
//! \param ulBase is the base address of the controller.
//! \param pucMACAddr is the pointer to the location in which to store the
//! array of MAC-48 address octets.
//!
//! This function reads the currently programmed MAC address into the
//! \e pucMACAddr buffer.
//!
//! \sa Refer to EthernetMACAddrSet() API description for more details about
//! the MAC address format.
//!
//! \return None.
//
//*****************************************************************************
void
EthernetMACAddrGet(unsigned long ulBase, unsigned char *pucMACAddr)
{
    unsigned long ulTemp;
    unsigned char *pucTemp = (unsigned char *)&ulTemp;

    //
    // Check the arguments.
    //
    ASSERT(ulBase == ETH_BASE);
    ASSERT(pucMACAddr != 0);

    //
    // Read the MAC address from the device.  The first four bytes of the
    // MAC address are read from the IA0 register.  The remaining two bytes
    // of the MAC addres
    //
    ulTemp = HWREG(ulBase + MAC_O_IA0);
    pucMACAddr[0] = pucTemp[0];
    pucMACAddr[1] = pucTemp[1];
    pucMACAddr[2] = pucTemp[2];
    pucMACAddr[3] = pucTemp[3];
    ulTemp = HWREG(ulBase + MAC_O_IA1);
    pucMACAddr[4] = pucTemp[0];
    pucMACAddr[5] = pucTemp[1];
}

//*****************************************************************************
//
//! Enables the Ethernet controller for normal operation.
//!
//! \param ulBase is the base address of the controller.
//!
//! Once the Ethernet controller has been configured using the
//! EthernetConfigSet() function and the MAC address has been programmed using
//! the EthernetMACAddrSet() function, this API function can be called to
//! enable the controller for normal operation.
//!
//! This function enables the controller's transmitter and receiver, and
//! resets the receive FIFO.
//!
//! \return None.
//
//*****************************************************************************
void
EthernetEnable(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == ETH_BASE);

    //
    // Reset the receive FIFO.
    //
    HWREG(ulBase + MAC_O_RCTL) |= MAC_RCTL_RSTFIFO;

    //
    // Enable the Ethernet receiver.
    //
    HWREG(ulBase + MAC_O_RCTL) |= MAC_RCTL_RXEN;

    //
    // Enable Ethernet transmitter.
    //
    HWREG(ulBase + MAC_O_TCTL) |= MAC_TCTL_TXEN;

    //
    // Reset the receive FIFO again, after the receiver has been enabled.
    //
    HWREG(ulBase + MAC_O_RCTL) |= MAC_RCTL_RSTFIFO;
}

//*****************************************************************************
//
//! Disables the Ethernet controller.
//!
//! \param ulBase is the base address of the controller.
//!
//! When terminating operations on the Ethernet interface, this function should
//! be called.  This function disables the transmitter and receiver, and
//! clears out the receive FIFO.
//!
//! \return None.
//
//*****************************************************************************
void
EthernetDisable(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == ETH_BASE);

    //
    // Reset the receive FIFO.
    //
    HWREG(ulBase + MAC_O_RCTL) |= MAC_RCTL_RSTFIFO;

    //
    // Disable the Ethernet transmitter.
    //
    HWREG(ulBase + MAC_O_TCTL) &= ~(MAC_TCTL_TXEN);

    //
    // Disable the Ethernet receiver.
    //
    HWREG(ulBase + MAC_O_RCTL) &= ~(MAC_RCTL_RXEN);

    //
    // Reset the receive FIFO again, after the receiver has been disabled.
    //
    HWREG(ulBase + MAC_O_RCTL) |= MAC_RCTL_RSTFIFO;
}

//*****************************************************************************
//
//! Check for packet available from the Ethernet controller.
//!
//! \param ulBase is the base address of the controller.
//!
//! The Ethernet controller provides a register that contains the number of
//! packets available in the receive FIFO.  When the last bytes of a packet are
//! successfully received (that is, the frame check sequence bytes), the packet
//! count is incremented.  Once the packet has been fully read (including the
//! frame check sequence bytes) from the FIFO, the packet count is decremented.
//!
//! \return Returns \b true if there are one or more packets available in the
//! receive FIFO, including the current packet being read, and \b false
//! otherwise.
//
//*****************************************************************************
tBoolean
EthernetPacketAvail(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == ETH_BASE);

    //
    // Return the availability of packets.
    //
    return((HWREG(ulBase + MAC_O_NP) & MAC_NP_NPR_M) ? true : false);
}

//*****************************************************************************
//
//! Checks for packet space available in the Ethernet controller.
//!
//! \param ulBase is the base address of the controller.
//!
//! The Ethernet controller's transmit FIFO is designed to support a single
//! packet at a time.  After the packet has been written into the FIFO, the
//! transmit request bit must be set to enable the transmission of the packet.
//! Only after the packet has been transmitted can a new packet be written
//! into the FIFO.  This function simply checks to see if a packet is
//! in progress.  If so, there is no space available in the transmit FIFO.
//!
//! \return Returns \b true if a space is available in the transmit FIFO, and
//! \b false otherwise.
//
//*****************************************************************************
tBoolean
EthernetSpaceAvail(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == ETH_BASE);

    //
    // Return the availability of space.
    //
    return((HWREG(ulBase + MAC_O_TR) & MAC_TR_NEWTX) ? false : true);
}

//*****************************************************************************
//
//! \internal
//!
//! Internal function for reading a packet from the Ethernet controller.
//!
//! \param ulBase is the base address of the controller.
//! \param pucBuf is the pointer to the packet buffer.
//! \param lBufLen is the maximum number of bytes to be read into the buffer.
//!
//! Based on the following table of how the receive frame is stored in the
//! receive FIFO, this function will extract a packet from the FIFO and store
//! it in the packet buffer that was passed in.
//!
//! Format of the data in the RX FIFO is as follows:
//!
//! \verbatim
//! +---------+----------+----------+----------+----------+
//! |         | 31:24    | 23:16    | 15:8     | 7:0      |
//! +---------+----------+----------+----------+----------+
//! | Word 0  | DA 2     | DA 1     | FL MSB   | FL LSB   |
//! +---------+----------+----------+----------+----------+
//! | Word 1  | DA 6     | DA 5     | DA 4     | DA 3     |
//! +---------+----------+----------+----------+----------+
//! | Word 2  | SA 4     | SA 3     | SA 2     | SA 1     |
//! +---------+----------+----------+----------+----------+
//! | Word 3  | FT LSB   | FT MSB   | SA 6     | SA 5     |
//! +---------+----------+----------+----------+----------+
//! | Word 4  | DATA 4   | DATA 3   | DATA 2   | DATA 1   |
//! +---------+----------+----------+----------+----------+
//! | Word 5  | DATA 8   | DATA 7   | DATA 6   | DATA 5   |
//! +---------+----------+----------+----------+----------+
//! | Word 6  | DATA 12  | DATA 11  | DATA 10  | DATA 9   |
//! +---------+----------+----------+----------+----------+
//! | ...     |          |          |          |          |
//! +---------+----------+----------+----------+----------+
//! | Word X  | DATA n   | DATA n-1 | DATA n-2 | DATA n-3 |
//! +---------+----------+----------+----------+----------+
//! | Word Y  | FCS 4    | FCS 3    | FCS 2    | FCS 1    |
//! +---------+----------+----------+----------+----------+
//! \endverbatim
//!
//! Where FL is Frame Length, (FL + DA + SA + FT + DATA + FCS) Bytes.
//! Where DA is Destination (MAC) Address.
//! Where SA is Source (MAC) Address.
//! Where FT is Frame Type (or Frame Length for Ethernet).
//! Where DATA is Payload Data for the Ethernet Frame.
//! Where FCS is the Frame Check Sequence.
//!
//! \return Returns the negated packet length \b -n if the packet is too large
//! for \e pucBuf, and returns the packet length \b n otherwise.
//
//*****************************************************************************
static long
EthernetPacketGetInternal(unsigned long ulBase, unsigned char *pucBuf,
                          long lBufLen)
{
    unsigned long ulTemp;
    long lFrameLen, lTempLen;
    long i = 0;

    //
    // Read WORD 0 (see format above) from the FIFO, set the receive
    // Frame Length and store the first two bytes of the destination
    // address in the receive buffer.
    //
    ulTemp = HWREG(ulBase + MAC_O_DATA);
    lFrameLen = (long)(ulTemp & 0xFFFF);
    pucBuf[i++] = (unsigned char) ((ulTemp >> 16) & 0xff);
    pucBuf[i++] = (unsigned char) ((ulTemp >> 24) & 0xff);

    //
    // Read all but the last WORD into the receive buffer.
    //
    lTempLen = (lBufLen < (lFrameLen - 6)) ? lBufLen : (lFrameLen - 6);
    while(i <= (lTempLen - 4))
    {
        *(unsigned long *)&pucBuf[i] = HWREG(ulBase + MAC_O_DATA);
        i += 4;
    }

    //
    // Read the last 1, 2, or 3 BYTES into the buffer
    //
    if(i < lTempLen)
    {
        ulTemp = HWREG(ulBase + MAC_O_DATA);
        if(i == lTempLen - 3)
        {
            pucBuf[i++] = ((ulTemp >>  0) & 0xff);
            pucBuf[i++] = ((ulTemp >>  8) & 0xff);
            pucBuf[i++] = ((ulTemp >> 16) & 0xff);
            i += 1;
        }
        else if(i == lTempLen - 2)
        {
            pucBuf[i++] = ((ulTemp >>  0) & 0xff);
            pucBuf[i++] = ((ulTemp >>  8) & 0xff);
            i += 2;
        }
        else if(i == lTempLen - 1)
        {
            pucBuf[i++] = ((ulTemp >>  0) & 0xff);
            i += 3;
        }
    }

    //
    // Read any remaining WORDS (that did not fit into the buffer).
    //
    while(i < (lFrameLen - 2))
    {
        ulTemp = HWREG(ulBase + MAC_O_DATA);
        i += 4;
    }

    //
    // If frame was larger than the buffer, return the "negative" frame length
    //
    lFrameLen -= 6;
    if(lFrameLen > lBufLen)
    {
        return(-lFrameLen);
    }

    //
    // Return the Frame Length
    //
    return(lFrameLen);
}

//*****************************************************************************
//
//! Receives a packet from the Ethernet controller.
//!
//! \param ulBase is the base address of the controller.
//! \param pucBuf is the pointer to the packet buffer.
//! \param lBufLen is the maximum number of bytes to be read into the buffer.
//!
//! This function reads a packet from the receive FIFO of the controller and
//! places it into \e pucBuf.  If no packet is available the function
//! returns immediately.  Otherwise, the function reads the entire packet
//! from the receive FIFO.  If there are more bytes in the packet than can fit
//! into \e pucBuf (as specified by \e lBufLen), the function returns the
//! negated length of the packet and the buffer contains \e lBufLen bytes
//! of the packet.  Otherwise, the function returns the length of the
//! packet that was read and \e pucBuf contains the entire packet
//! (excluding the frame check sequence bytes).
//!
//! This function replaces the original EthernetPacketNonBlockingGet() API and
//! performs the same actions.  A macro is provided in <tt>ethernet.h</tt> to
//! map the original API to this API.
//!
//! \note This function returns immediately if no packet is available.
//!
//! \return Returns \b 0 if no packet is available, the negated packet length
//! \b -n if the packet is too large for \e pucBuf, and the packet length \b n
//! otherwise.
//
//*****************************************************************************
long
EthernetPacketGetNonBlocking(unsigned long ulBase, unsigned char *pucBuf,
                             long lBufLen)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == ETH_BASE);
    ASSERT(pucBuf != 0);
    ASSERT(lBufLen > 0);

    //
    // Check to see if any packets are available.
    //
    if((HWREG(ulBase + MAC_O_NP) & MAC_NP_NPR_M) == 0)
    {
        return(0);
    }

    //
    // Read the packet, and return.
    //
    return(EthernetPacketGetInternal(ulBase, pucBuf, lBufLen));
}

//*****************************************************************************
//
//! Waits for a packet from the Ethernet controller.
//!
//! \param ulBase is the base address of the controller.
//! \param pucBuf is the pointer to the packet buffer.
//! \param lBufLen is the maximum number of bytes to be read into the buffer.
//!
//! This function reads a packet from the receive FIFO of the controller and
//! places it into \e pucBuf.  The function waits until a packet is
//! available in the FIFO.  Then the function reads the entire packet
//! from the receive FIFO.  If there are more bytes in the packet than can
//! fit into \e pucBuf (as specified by \e lBufLen), the function returns
//! the negated length of the packet and the buffer contains \e lBufLen
//! bytes of the packet.  Otherwise, the function returns the length of
//! the packet that was read and \e pucBuf contains the entire packet
//! (excluding the frame check sequence bytes).
//!
//! \note This function is blocking and does not return until a packet arrives.
//!
//! \return Returns the negated packet length \b -n if the packet is too large
//! for \e pucBuf, and returns the packet length \b n otherwise.
//
//*****************************************************************************
long
EthernetPacketGet(unsigned long ulBase, unsigned char *pucBuf,
                  long lBufLen)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == ETH_BASE);
    ASSERT(pucBuf != 0);
    ASSERT(lBufLen > 0);

    //
    // Wait for a packet to become available
    //
    while((HWREG(ulBase + MAC_O_NP) & MAC_NP_NPR_M) == 0)
    {
    }

    //
    // Read the packet
    //
    return(EthernetPacketGetInternal(ulBase, pucBuf, lBufLen));
}

//*****************************************************************************
//
//! \internal
//!
//! Internal function for sending a packet to the Ethernet controller.
//!
//! \param ulBase is the base address of the controller.
//! \param pucBuf is the pointer to the packet buffer.
//! \param lBufLen is number of bytes in the packet to be transmitted.
//!
//! Puts a packet into the transmit FIFO of the controller.
//!
//! Format of the data in the TX FIFO is as follows:
//!
//! \verbatim
//! +---------+----------+----------+----------+----------+
//! |         | 31:24    | 23:16    | 15:8     | 7:0      |
//! +---------+----------+----------+----------+----------+
//! | Word 0  | DA 2     | DA 1     | PL MSB   | PL LSB   |
//! +---------+----------+----------+----------+----------+
//! | Word 1  | DA 6     | DA 5     | DA 4     | DA 3     |
//! +---------+----------+----------+----------+----------+
//! | Word 2  | SA 4     | SA 3     | SA 2     | SA 1     |
//! +---------+----------+----------+----------+----------+
//! | Word 3  | FT LSB   | FT MSB   | SA 6     | SA 5     |
//! +---------+----------+----------+----------+----------+
//! | Word 4  | DATA 4   | DATA 3   | DATA 2   | DATA 1   |
//! +---------+----------+----------+----------+----------+
//! | Word 5  | DATA 8   | DATA 7   | DATA 6   | DATA 5   |
//! +---------+----------+----------+----------+----------+
//! | Word 6  | DATA 12  | DATA 11  | DATA 10  | DATA 9   |
//! +---------+----------+----------+----------+----------+
//! | ...     |          |          |          |          |
//! +---------+----------+----------+----------+----------+
//! | Word X  | DATA n   | DATA n-1 | DATA n-2 | DATA n-3 |
//! +---------+----------+----------+----------+----------+
//! \endverbatim
//!
//! Where PL is Payload Length, (DATA) only
//! Where DA is Destination (MAC) Address
//! Where SA is Source (MAC) Address
//! Where FT is Frame Type (or Frame Length for Ethernet)
//! Where DATA is Payload Data for the Ethernet Frame
//!
//! \return Returns the negated packet length \b -lBufLen if the packet is too
//! large for FIFO, and the packet length \b lBufLen otherwise.
//
//*****************************************************************************
static long
EthernetPacketPutInternal(unsigned long ulBase, unsigned char *pucBuf,
                          long lBufLen)
{
    unsigned long ulTemp;
    long i = 0;

    //
    // If the packet is too large, return the negative packet length as
    // an error code.
    //
    if(lBufLen > (2048 - 2))
    {
        return(-lBufLen);
    }

    //
    // Build and write WORD 0 (see format above) to the transmit FIFO.
    //
    ulTemp = (unsigned long)(lBufLen - 14);
    ulTemp |= (pucBuf[i++] << 16);
    ulTemp |= (pucBuf[i++] << 24);
    HWREG(ulBase + MAC_O_DATA) = ulTemp;

    //
    // Write each subsequent WORD n to the transmit FIFO, except for the last
    // WORD (if the word does not contain 4 bytes).
    //
    while(i <= (lBufLen - 4))
    {
        HWREG(ulBase + MAC_O_DATA) = *(unsigned long *)&pucBuf[i];
        i += 4;
    }

    //
    // Build the last word of the remaining 1, 2, or 3 bytes, and store
    // the WORD into the transmit FIFO.
    //
    if(i != lBufLen)
    {
        if(i == (lBufLen - 3))
        {
            ulTemp  = (pucBuf[i++] <<  0);
            ulTemp |= (pucBuf[i++] <<  8);
            ulTemp |= (pucBuf[i++] << 16);
            HWREG(ulBase + MAC_O_DATA) = ulTemp;
        }
        else if(i == (lBufLen - 2))
        {
            ulTemp  = (pucBuf[i++] <<  0);
            ulTemp |= (pucBuf[i++] <<  8);
            HWREG(ulBase + MAC_O_DATA) = ulTemp;
        }
        else if(i == (lBufLen - 1))
        {
            ulTemp  = (pucBuf[i++] <<  0);
            HWREG(ulBase + MAC_O_DATA) = ulTemp;
        }
    }

    //
    // Activate the transmitter
    //
    HWREG(ulBase + MAC_O_TR) = MAC_TR_NEWTX;

    //
    // Return the Buffer Length transmitted.
    //
    return(lBufLen);
}

//*****************************************************************************
//
//! Sends a packet to the Ethernet controller.
//!
//! \param ulBase is the base address of the controller.
//! \param pucBuf is the pointer to the packet buffer.
//! \param lBufLen is number of bytes in the packet to be transmitted.
//!
//! This function writes \e lBufLen bytes of the packet contained in \e pucBuf
//! into the transmit FIFO of the controller and then activates the
//! transmitter for this packet.  If no space is available in the FIFO, the
//! function returns immediately.  If space is available, the
//! function returns once \e lBufLen bytes of the packet have been placed
//! into the FIFO and the transmitter has been started.  The function does not
//! wait for the transmission to complete.  The function returns the
//! negated \e lBufLen if the length is larger than the space available in
//! the transmit FIFO.
//!
//! This function replaces the original EthernetPacketNonBlockingPut() API and
//! performs the same actions.  A macro is provided in <tt>ethernet.h</tt> to
//! map the original API to this API.
//!
//! \note This function does not block and returns immediately if no space
//! is available for the transmit packet.
//!
//! \return Returns \b 0 if no space is available in the transmit FIFO, the
//! negated packet length \b -lBufLen if the packet is too large for FIFO, and
//! the packet length \b lBufLen otherwise.
//
//*****************************************************************************
long
EthernetPacketPutNonBlocking(unsigned long ulBase, unsigned char *pucBuf,
                             long lBufLen)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == ETH_BASE);
    ASSERT(pucBuf != 0);
    ASSERT(lBufLen > 0);

    //
    // Check if the transmit FIFO is in use and return the appropriate code.
    //
    if(HWREG(ulBase + MAC_O_TR) & MAC_TR_NEWTX)
    {
        return(0);
    }

    //
    // Send the packet and return.
    //
    return(EthernetPacketPutInternal(ulBase, pucBuf, lBufLen));
}

//*****************************************************************************
//
//! Waits to send a packet from the Ethernet controller.
//!
//! \param ulBase is the base address of the controller.
//! \param pucBuf is the pointer to the packet buffer.
//! \param lBufLen is number of bytes in the packet to be transmitted.
//!
//! This function writes \e lBufLen bytes of the packet contained in \e pucBuf
//! into the transmit FIFO of the controller and then activates the transmitter
//! for this packet.  This function waits until the transmit FIFO is empty.
//! Once space is available, the function returns once \e lBufLen bytes of
//! the packet have been placed into the FIFO and the transmitter has been
//! started.  The function does not wait for the transmission to complete.  The
//! function returns the negated \e lBufLen if the length is larger than
//! the space available in the transmit FIFO.
//!
//! \note This function blocks and waits until space is available for the
//! transmit packet before returning.
//!
//! \return Returns the negated packet length \b -lBufLen if the packet is too
//! large for FIFO, and the packet length \b lBufLen otherwise.
//
//*****************************************************************************
long
EthernetPacketPut(unsigned long ulBase, unsigned char *pucBuf,
                  long lBufLen)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == ETH_BASE);
    ASSERT(pucBuf != 0);
    ASSERT(lBufLen > 0);

    //
    // Wait for current packet (if any) to complete.
    //
    while(HWREG(ulBase + MAC_O_TR) & MAC_TR_NEWTX)
    {
    }

    //
    // Send the packet and return.
    //
    return(EthernetPacketPutInternal(ulBase, pucBuf, lBufLen));
}

//*****************************************************************************
//
//! Registers an interrupt handler for an Ethernet interrupt.
//!
//! \param ulBase is the base address of the controller.
//! \param pfnHandler is a pointer to the function to be called when the
//! enabled Ethernet interrupts occur.
//!
//! This function sets the handler to be called when the Ethernet interrupt
//! occurs.  This function enables the global interrupt in the interrupt
//! controller; specific Ethernet interrupts must be enabled via
//! EthernetIntEnable().  It is the interrupt handler's responsibility to clear
//! the interrupt source.
//!
//! \sa IntRegister() for important information about registering interrupt
//! handlers.
//!
//! \return None.
//
//*****************************************************************************
void
EthernetIntRegister(unsigned long ulBase, void (*pfnHandler)(void))
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == ETH_BASE);
    ASSERT(pfnHandler != 0);

    //
    // Register the interrupt handler.
    //
    IntRegister(INT_ETH, pfnHandler);

    //
    // Enable the Ethernet interrupt.
    //
    IntEnable(INT_ETH);
}

//*****************************************************************************
//
//! Unregisters an interrupt handler for an Ethernet interrupt.
//!
//! \param ulBase is the base address of the controller.
//!
//! This function unregisters the interrupt handler.  This function disables
//! the global interrupt in the interrupt controller so that the interrupt
//! handler no longer is called.
//!
//! \sa IntRegister() for important information about registering interrupt
//! handlers.
//!
//! \return None.
//
//*****************************************************************************
void
EthernetIntUnregister(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == ETH_BASE);

    //
    // Disable the interrupt.
    //
    IntDisable(INT_ETH);

    //
    // Unregister the interrupt handler.
    //
    IntUnregister(INT_ETH);
}

//*****************************************************************************
//
//! Enables individual Ethernet interrupt sources.
//!
//! \param ulBase is the base address of the controller.
//! \param ulIntFlags is the bit mask of the interrupt sources to be enabled.
//!
//! This function enables the indicated Ethernet interrupt sources.  Only the
//! sources that are enabled can be reflected to the processor interrupt;
//! disabled sources have no effect on the processor.
//!
//! The \e ulIntFlags parameter is the logical OR of any of the following:
//!
//! - \b ETH_INT_PHY - An interrupt from the PHY has occurred.  The integrated
//! PHY supports a number of interrupt conditions.  The appropriate PHY
//! register, PHY_MR17 or PHY_MR29 depending on the device class, must be read
//! to determine which PHY interrupt has occurred.  This register can be read
//! using the EthernetPHYRead() API function.
//! - \b ETH_INT_MDIO - This interrupt indicates that a transaction on the
//! management interface has completed successfully.
//! - \b ETH_INT_RXER - This interrupt indicates that an error has occurred
//! during reception of a frame.  This error can indicate a length mismatch, a
//! CRC failure, or an error indication from the PHY.
//! - \b ETH_INT_RXOF - This interrupt indicates that a frame has been received
//! that exceeds the available space in the RX FIFO.
//! - \b ETH_INT_TX - This interrupt indicates that the packet stored in the TX
//! FIFO has been successfully transmitted.
//! - \b ETH_INT_TXER - This interrupt indicates that an error has occurred
//! during the transmission of a packet.  This error can be either a retry
//! failure during the back-off process, or an invalid length stored in the TX
//! FIFO.
//! - \b ETH_INT_RX - This interrupt indicates that one (or more) packets are
//! available in the RX FIFO for processing.
//!
//! \return None.
//
//*****************************************************************************
void
EthernetIntEnable(unsigned long ulBase, unsigned long ulIntFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == ETH_BASE);
    ASSERT(!(ulIntFlags & ~(ETH_INT_PHY | ETH_INT_MDIO | ETH_INT_RXER |
                            ETH_INT_RXOF | ETH_INT_TX | ETH_INT_TXER |
                            ETH_INT_RX)));

    //
    // Enable the specified interrupts.
    //
    HWREG(ulBase + MAC_O_IM) |= ulIntFlags;
}

//*****************************************************************************
//
//! Disables individual Ethernet interrupt sources.
//!
//! \param ulBase is the base address of the controller.
//! \param ulIntFlags is the bit mask of the interrupt sources to be disabled.
//!
//! Disables the indicated Ethernet interrupt sources.  Only the sources that
//! are enabled can be reflected to the processor interrupt; disabled sources
//! have no effect on the processor.
//!
//! The \e ulIntFlags parameter has the same definition as the \e ulIntFlags
//! parameter to EthernetIntEnable().
//!
//! \return None.
//
//*****************************************************************************
void
EthernetIntDisable(unsigned long ulBase, unsigned long ulIntFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == ETH_BASE);
    ASSERT(!(ulIntFlags & ~(ETH_INT_PHY | ETH_INT_MDIO | ETH_INT_RXER |
                            ETH_INT_RXOF | ETH_INT_TX | ETH_INT_TXER |
                            ETH_INT_RX)));

    //
    // Disable the specified interrupts.
    //
    HWREG(ulBase + MAC_O_IM) &= ~ulIntFlags;
}

//*****************************************************************************
//
//! Gets the current Ethernet interrupt status.
//!
//! \param ulBase is the base address of the controller.
//! \param bMasked is false if the raw interrupt status is required and true
//! if the masked interrupt status is required.
//!
//! This function returns the interrupt status for the Ethernet controller.
//! Either the raw interrupt status or the status of interrupts that are
//! allowed to reflect to the processor can be returned.
//!
//! \return Returns the current interrupt status, enumerated as a bit field of
//! values described in EthernetIntEnable().
//
//*****************************************************************************
unsigned long
EthernetIntStatus(unsigned long ulBase, tBoolean bMasked)
{
    unsigned long ulStatus;

    //
    // Check the arguments.
    //
    ASSERT(ulBase == ETH_BASE);

    //
    // Read the unmasked status.
    //
    ulStatus = HWREG(ulBase + MAC_O_RIS);

    //
    // If masked status is requested, mask it off.
    //
    if(bMasked)
    {
        ulStatus &= HWREG(ulBase + MAC_O_IM);
    }

    //
    // Return the interrupt status value.
    //
    return(ulStatus);
}

//*****************************************************************************
//
//! Clears Ethernet interrupt sources.
//!
//! \param ulBase is the base address of the controller.
//! \param ulIntFlags is a bit mask of the interrupt sources to be cleared.
//!
//! The specified Ethernet interrupt sources are cleared so that they no longer
//! assert.  This function must be called in the interrupt handler to keep the
//! interrupt from being triggered again immediately upon exit.
//!
//! The \e ulIntFlags parameter has the same definition as the \e ulIntFlags
//! parameter to EthernetIntEnable().
//!
//! \note Because there is a write buffer in the Cortex-M processor, it may
//! take several clock cycles before the interrupt source is actually cleared.
//! Therefore, it is recommended that the interrupt source be cleared early in
//! the interrupt handler (as opposed to the very last action) to avoid
//! returning from the interrupt handler before the interrupt source is
//! actually cleared.  Failure to do so may result in the interrupt handler
//! being immediately reentered (because the interrupt controller still sees
//! the interrupt source asserted).
//!
//! \return None.
//
//*****************************************************************************
void
EthernetIntClear(unsigned long ulBase, unsigned long ulIntFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == ETH_BASE);
    ASSERT(!(ulIntFlags & ~(ETH_INT_PHY | ETH_INT_MDIO | ETH_INT_RXER |
                            ETH_INT_RXOF | ETH_INT_TX | ETH_INT_TXER |
                            ETH_INT_RX)));

    //
    // Clear the requested interrupt sources.
    //
    HWREG(ulBase + MAC_O_IACK) = ulIntFlags;
}

//*****************************************************************************
//
//! Sets the PHY address.
//!
//! \param ulBase is the base address of the controller.
//! \param ucAddr is the address of the PHY.
//!
//! This function sets the address of the PHY that is accessed via
//! EthernetPHYRead() and EthernePHYWrite().  This configuration is only needed
//! when connecting to an external PHY via MII, and should not be used on
//! devices that have integrated PHYs.
//!
//! \return None.
//
//*****************************************************************************
void
EthernetPHYAddrSet(unsigned long ulBase, unsigned char ucAddr)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == ETH_BASE);

    //
    // Wait for any pending transaction to complete.
    //
    while(HWREG(ulBase + MAC_O_MCTL) & MAC_MCTL_START)
    {
    }

    //
    // Set the PHY address.
    //
    HWREG(ulBase + MAC_O_MADD) = ucAddr;
}

//*****************************************************************************
//
//! Writes to the PHY register.
//!
//! \param ulBase is the base address of the controller.
//! \param ucRegAddr is the address of the PHY register to be accessed.
//! \param ulData is the data to be written to the PHY register.
//!
//! This function writes the \e ulData to the PHY register specified by
//! \e ucRegAddr.
//!
//! \return None.
//
//*****************************************************************************
void
EthernetPHYWrite(unsigned long ulBase, unsigned char ucRegAddr,
                 unsigned long ulData)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == ETH_BASE);

    //
    // Wait for any pending transaction to complete.
    //
    while(HWREG(ulBase + MAC_O_MCTL) & MAC_MCTL_START)
    {
    }

    //
    // Program the DATA to be written.
    //
    HWREG(ulBase + MAC_O_MTXD) = ulData & MAC_MTXD_MDTX_M;

    //
    // Program the PHY register address and initiate the transaction.
    //
    HWREG(ulBase + MAC_O_MCTL) = (((ucRegAddr << 3) & MAC_MCTL_REGADR_M) |
                                  MAC_MCTL_WRITE | MAC_MCTL_START);

    //
    // Wait for the write transaction to complete.
    //
    while(HWREG(ulBase + MAC_O_MCTL) & MAC_MCTL_START)
    {
    }
}

//*****************************************************************************
//
//! Reads from a PHY register.
//!
//! \param ulBase is the base address of the controller.
//! \param ucRegAddr is the address of the PHY register to be accessed.
//!
//! This function returns the contents of the PHY register specified by
//! \e ucRegAddr.
//!
//! \return Returns the 16-bit value read from the PHY.
//
//*****************************************************************************
unsigned long
EthernetPHYRead(unsigned long ulBase, unsigned char ucRegAddr)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == ETH_BASE);

    //
    // Wait for any pending transaction to complete.
    //
    while(HWREG(ulBase + MAC_O_MCTL) & MAC_MCTL_START)
    {
    }

    //
    // Program the PHY register address and initiate the transaction.
    //
    HWREG(ulBase + MAC_O_MCTL) = (((ucRegAddr << 3) & MAC_MCTL_REGADR_M) |
                                  MAC_MCTL_START);

    //
    // Wait for the transaction to complete.
    //
    while(HWREG(ulBase + MAC_O_MCTL) & MAC_MCTL_START)
    {
    }

    //
    // Return the PHY data that was read.
    //
    return(HWREG(ulBase + MAC_O_MRXD) & MAC_MRXD_MDRX_M);
}

//*****************************************************************************
//
//! Powers off the Ethernet PHY.
//!
//! \param ulBase is the base address of the controller.
//!
//! This function powers off the Ethernet PHY, reducing the current
//! consumption of the device.  While in the powered off state, the Ethernet
//! controller is unable to connect to the Ethernet.
//!
//! \return None.
//
//*****************************************************************************
void
EthernetPHYPowerOff(unsigned long ulBase)
{
    //
    // Set the PWRDN bit and clear the ANEGEN bit in the PHY, putting it into
    // its low power mode.
    //
    EthernetPHYWrite(ulBase, PHY_MR0,
                     (EthernetPHYRead(ulBase, PHY_MR0) & ~PHY_MR0_ANEGEN) |
                     PHY_MR0_PWRDN);
}

//*****************************************************************************
//
//! Powers on the Ethernet PHY.
//!
//! \param ulBase is the base address of the controller.
//!
//! This function powers on the Ethernet PHY, enabling it return to normal
//! operation.  By default, the PHY is powered on, so this function is only
//! called if EthernetPHYPowerOff() has previously been called.
//!
//! \return None.
//
//*****************************************************************************
void
EthernetPHYPowerOn(unsigned long ulBase)
{
    //
    // Clear the PWRDN bit and set the ANEGEN bit in the PHY, putting it into
    // normal operating mode.
    //
    EthernetPHYWrite(ulBase, PHY_MR0,
                     (EthernetPHYRead(ulBase, PHY_MR0) & ~PHY_MR0_PWRDN) |
                     PHY_MR0_ANEGEN);
}

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************
