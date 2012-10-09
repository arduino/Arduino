//*****************************************************************************
//
// usb.c - Driver for the USB Interface.
//
// Copyright (c) 2007-2012 Texas Instruments Incorporated.  All rights reserved.
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
//! \addtogroup usb_api
//! @{
//
//*****************************************************************************

#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_sysctl.h"
#include "inc/hw_usb.h"
#include "driverlib/debug.h"
#include "driverlib/interrupt.h"
#include "driverlib/sysctl.h"
#include "driverlib/udma.h"
#include "driverlib/usb.h"

//*****************************************************************************
//
// Amount to shift the RX interrupt sources by in the flags used in the
// interrupt calls.
//
//*****************************************************************************
#ifndef DEPRECATED
#define USB_INT_RX_SHIFT        8
#endif
#define USB_INTEP_RX_SHIFT      16

//*****************************************************************************
//
// Amount to shift the status interrupt sources by in the flags used in the
// interrupt calls.
//
//*****************************************************************************
#ifndef DEPRECATED
#define USB_INT_STATUS_SHIFT    24
#endif

//*****************************************************************************
//
// Amount to shift the RX endpoint status sources by in the flags used in the
// calls.
//
//*****************************************************************************
#define USB_RX_EPSTATUS_SHIFT   16

//*****************************************************************************
//
// Converts from an endpoint specifier to the offset of the endpoint's
// control/status registers.
//
//*****************************************************************************
#define EP_OFFSET(Endpoint)     (Endpoint - 0x10)

//*****************************************************************************
//
// Sets one of the indexed registers.
//
// \param ulBase specifies the USB module base address.
// \param ulEndpoint is the endpoint index to target for this write.
// \param ulIndexedReg is the indexed register to write to.
// \param ucValue is the value to write to the register.
//
// This function is used to access the indexed registers for each endpoint.
// The only registers that are indexed are the FIFO configuration registers,
// which are not used after configuration.
//
// \return None.
//
//*****************************************************************************
static void
USBIndexWrite(unsigned long ulBase, unsigned long ulEndpoint,
              unsigned long ulIndexedReg, unsigned long ulValue,
              unsigned long ulSize)
{
    unsigned long ulIndex;

    //
    // Check the arguments.
    //
    ASSERT(ulBase == USB0_BASE);
    ASSERT((ulEndpoint == 0) || (ulEndpoint == 1) || (ulEndpoint == 2) ||
           (ulEndpoint == 3));
    ASSERT((ulSize == 1) || (ulSize == 2));

    //
    // Save the old index in case it was in use.
    //
    ulIndex = HWREGB(ulBase + USB_O_EPIDX);

    //
    // Set the index.
    //
    HWREGB(ulBase + USB_O_EPIDX) = ulEndpoint;

    //
    // Determine the size of the register value.
    //
    if(ulSize == 1)
    {
        //
        // Set the value.
        //
        HWREGB(ulBase + ulIndexedReg) = ulValue;
    }
    else
    {
        //
        // Set the value.
        //
        HWREGH(ulBase + ulIndexedReg) = ulValue;
    }

    //
    // Restore the old index in case it was in use.
    //
    HWREGB(ulBase + USB_O_EPIDX) = ulIndex;
}

//*****************************************************************************
//
// Reads one of the indexed registers.
//
// \param ulBase specifies the USB module base address.
// \param ulEndpoint is the endpoint index to target for this write.
// \param ulIndexedReg is the indexed register to write to.
//
// This function is used internally to access the indexed registers for each
// endpoint.  The only registers that are indexed are the FIFO configuration
// registers, which are not used after configuration.
//
// \return The value in the register requested.
//
//*****************************************************************************
static unsigned long
USBIndexRead(unsigned long ulBase, unsigned long ulEndpoint,
             unsigned long ulIndexedReg, unsigned long ulSize)
{
    unsigned char ulIndex;
    unsigned char ulValue;

    //
    // Check the arguments.
    //
    ASSERT(ulBase == USB0_BASE);
    ASSERT((ulEndpoint == 0) || (ulEndpoint == 1) || (ulEndpoint == 2) ||
           (ulEndpoint == 3));
    ASSERT((ulSize == 1) || (ulSize == 2));

    //
    // Save the old index in case it was in use.
    //
    ulIndex = HWREGB(ulBase + USB_O_EPIDX);

    //
    // Set the index.
    //
    HWREGB(ulBase + USB_O_EPIDX) = ulEndpoint;

    //
    // Determine the size of the register value.
    //
    if(ulSize == 1)
    {
        //
        // Get the value.
        //
        ulValue = HWREGB(ulBase + ulIndexedReg);
    }
    else
    {
        //
        // Get the value.
        //
        ulValue = HWREGH(ulBase + ulIndexedReg);
    }

    //
    // Restore the old index in case it was in use.
    //
    HWREGB(ulBase + USB_O_EPIDX) = ulIndex;

    //
    // Return the register's value.
    //
    return(ulValue);
}

//*****************************************************************************
//
//! Puts the USB bus in a suspended state.
//!
//! \param ulBase specifies the USB module base address.
//!
//! When used in host mode, this function puts the USB bus in the suspended
//! state.
//!
//! \note This function must only be called in host mode.
//!
//! \return None.
//
//*****************************************************************************
void
USBHostSuspend(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == USB0_BASE);

    //
    // Send the suspend signaling to the USB bus.
    //
    HWREGB(ulBase + USB_O_POWER) |= USB_POWER_SUSPEND;
}

//*****************************************************************************
//
//! Handles the USB bus reset condition.
//!
//! \param ulBase specifies the USB module base address.
//! \param bStart specifies whether to start or stop signaling reset on the USB
//! bus.
//!
//! When this function is called with the \e bStart parameter set to \b true,
//! this function causes the start of a reset condition on the USB bus.
//! The caller must then delay at least 20ms before calling this function
//! again with the \e bStart parameter set to \b false.
//!
//! \note This function must only be called in host mode.
//!
//! \return None.
//
//*****************************************************************************
void
USBHostReset(unsigned long ulBase, tBoolean bStart)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == USB0_BASE);

    //
    // Send a reset signal to the bus.
    //
    if(bStart)
    {
        HWREGB(ulBase + USB_O_POWER) |= USB_POWER_RESET;
    }
    else
    {
        HWREGB(ulBase + USB_O_POWER) &= ~USB_POWER_RESET;
    }
}

//*****************************************************************************
//
//! Handles the USB bus resume condition.
//!
//! \param ulBase specifies the USB module base address.
//! \param bStart specifies if the USB controller is entering or leaving the
//! resume signaling state.
//!
//! When in device mode, this function brings the USB controller out of the
//! suspend state.  This call must first be made with the \e bStart parameter
//! set to \b true to start resume signaling.  The device application must
//! then delay at least 10ms but not more than 15ms before calling this
//! function with the \e bStart parameter set to \b false.
//!
//! When in host mode, this function signals devices to leave the suspend
//! state.  This call must first be made with the \e bStart parameter set to
//! \b true to start resume signaling.  The host application must then delay
//! at least 20ms before calling this function with the \e bStart parameter set
//! to \b false.  This action causes the controller to complete the resume
//! signaling on the USB bus.
//!
//! \return None.
//
//*****************************************************************************
void
USBHostResume(unsigned long ulBase, tBoolean bStart)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == USB0_BASE);

    //
    // Send a resume signal to the bus.
    //
    if(bStart)
    {
        HWREGB(ulBase + USB_O_POWER) |= USB_POWER_RESUME;
    }
    else
    {
        HWREGB(ulBase + USB_O_POWER) &= ~USB_POWER_RESUME;
    }
}

//*****************************************************************************
//
//! Returns the current speed of the USB device connected.
//!
//! \param ulBase specifies the USB module base address.
//!
//! This function returns the current speed of the USB bus.
//!
//! \note This function must only be called in host mode.
//!
//! \return Returns either \b USB_LOW_SPEED, \b USB_FULL_SPEED, or
//! \b USB_UNDEF_SPEED.
//
//*****************************************************************************
unsigned long
USBHostSpeedGet(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == USB0_BASE);

    //
    // If the Full Speed device bit is set, then this is a full speed device.
    //
    if(HWREGB(ulBase + USB_O_DEVCTL) & USB_DEVCTL_FSDEV)
    {
        return(USB_FULL_SPEED);
    }

    //
    // If the Low Speed device bit is set, then this is a low speed device.
    //
    if(HWREGB(ulBase + USB_O_DEVCTL) & USB_DEVCTL_LSDEV)
    {
        return(USB_LOW_SPEED);
    }

    //
    // The device speed is not known.
    //
    return(USB_UNDEF_SPEED);
}

//*****************************************************************************
//
//! Returns the status of the USB interrupts.
//!
//! \param ulBase specifies the USB module base address.
//!
//! This function reads the source of the interrupt for the USB controller.
//! There are three groups of interrupt sources, IN Endpoints, OUT Endpoints,
//! and general status changes.  This call returns the current status for
//! all of these interrupts.  The bit values returned should be compared
//! against the \b USB_HOST_IN, \b USB_HOST_OUT, \b USB_HOST_EP0,
//! \b USB_DEV_IN, \b USB_DEV_OUT, and \b USB_DEV_EP0 values.
//!
//! \note This call clears the source of all of the general status interrupts.
//!
//! \note WARNING: This API cannot be used on endpoint numbers greater than
//! endpoint 3 so USBIntStatusControl() or USBIntStatusEndpoint() should be
//! used instead.
//!
//! \return Returns the status of the sources for the USB controller's
//! interrupt.
//
//*****************************************************************************
#ifndef DEPRECATED
unsigned long
USBIntStatus(unsigned long ulBase)
{
    unsigned long ulStatus;

    //
    // Check the arguments.
    //
    ASSERT(ulBase == USB0_BASE);

    //
    // Get the transmit interrupt status.
    //
    ulStatus = (HWREGB(ulBase + USB_O_TXIS));

    //
    // Get the receive interrupt status, these bits go into the second byte of
    // the returned value.
    //
    ulStatus |= (HWREGB(ulBase + USB_O_RXIS) << USB_INT_RX_SHIFT);

    //
    // Get the general interrupt status, these bits go into the upper 8 bits
    // of the returned value.
    //
    ulStatus |= (HWREGB(ulBase + USB_O_IS) << USB_INT_STATUS_SHIFT);

    //
    // Add the power fault status.
    //
    if(HWREG(ulBase + USB_O_EPCISC) & USB_EPCISC_PF)
    {
        //
        // Indicate a power fault was detected.
        //
        ulStatus |= USB_INT_POWER_FAULT;

        //
        // Clear the power fault interrupt.
        //
        HWREGB(ulBase + USB_O_EPCISC) |= USB_EPCISC_PF;
    }

    if(HWREG(USB0_BASE + USB_O_IDVISC) & USB_IDVRIS_ID)
    {
        //
        // Indicate an id detection was detected.
        //
        ulStatus |= USB_INT_MODE_DETECT;

        //
        // Clear the id detection interrupt.
        //
        HWREG(USB0_BASE + USB_O_IDVISC) |= USB_IDVRIS_ID;
    }

    //
    // Return the combined interrupt status.
    //
    return(ulStatus);
}
#endif

//*****************************************************************************
//
//! Disables the sources for USB interrupts.
//!
//! \param ulBase specifies the USB module base address.
//! \param ulFlags specifies which interrupts to disable.
//!
//! This function disables the USB controller from generating the
//! interrupts indicated by the \e ulFlags parameter.  There are three groups
//! of interrupt sources, IN Endpoints, OUT Endpoints, and general status
//! changes, specified by \b USB_INT_HOST_IN, \b USB_INT_HOST_OUT,
//! \b USB_INT_DEV_IN, \b USB_INT_DEV_OUT, and \b USB_INT_STATUS.  If
//! \b USB_INT_ALL is specified, then all interrupts are disabled.
//!
//! \note WARNING: This API cannot be used on endpoint numbers greater than
//! endpoint 3 so USBIntDisableControl() or USBIntDisableEndpoint() should be
//! used instead.
//!
//! \return None.
//
//*****************************************************************************
#ifndef DEPRECATED
void
USBIntDisable(unsigned long ulBase, unsigned long ulFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == USB0_BASE);
    ASSERT((ulFlags & ~(USB_INT_ALL)) == 0);

    //
    // If any transmit interrupts were disabled, then write the transmit
    // interrupt settings out to the hardware.
    //
    if(ulFlags & (USB_INT_HOST_OUT | USB_INT_DEV_IN | USB_INT_EP0))
    {
        HWREGH(ulBase + USB_O_TXIE) &=
            ~(ulFlags & (USB_INT_HOST_OUT | USB_INT_DEV_IN | USB_INT_EP0));
    }

    //
    // If any receive interrupts were disabled, then write the receive
    // interrupt settings out to the hardware.
    //
    if(ulFlags & (USB_INT_HOST_IN | USB_INT_DEV_OUT))
    {
        HWREGH(ulBase + USB_O_RXIE) &=
            ~((ulFlags & (USB_INT_HOST_IN | USB_INT_DEV_OUT)) >>
              USB_INT_RX_SHIFT);
    }

    //
    // If any general interrupts were disabled, then write the general
    // interrupt settings out to the hardware.
    //
    if(ulFlags & USB_INT_STATUS)
    {
        HWREGB(ulBase + USB_O_IE) &=
            ~((ulFlags & USB_INT_STATUS) >> USB_INT_STATUS_SHIFT);
    }

    //
    // Disable the power fault interrupt.
    //
    if(ulFlags & USB_INT_POWER_FAULT)
    {
        HWREG(ulBase + USB_O_EPCIM) = 0;
    }

    //
    // Disable the ID pin detect interrupt.
    //
    if(ulFlags & USB_INT_MODE_DETECT)
    {
        HWREG(USB0_BASE + USB_O_IDVIM) = 0;
    }
}
#endif

//*****************************************************************************
//
//! Enables the sources for USB interrupts.
//!
//! \param ulBase specifies the USB module base address.
//! \param ulFlags specifies which interrupts to enable.
//!
//! This function enables the USB controller's ability to generate the
//! interrupts indicated by the \e ulFlags parameter.  There are three
//! groups of interrupt sources, IN Endpoints, OUT Endpoints, and
//! general status changes, specified by \b USB_INT_HOST_IN,
//! \b USB_INT_HOST_OUT, \b USB_INT_DEV_IN, \b USB_INT_DEV_OUT, and
//! \b USB_STATUS.  If \b USB_INT_ALL is specified then all interrupts are
//! enabled.
//!
//! \note A call must be made to enable the interrupt in the main interrupt
//! controller to receive interrupts.  The USBIntRegister() API performs this
//! controller-level interrupt enable.  However if static interrupt handlers
//! are used, then then a call to IntEnable() must be made in order to allow
//! any USB interrupts to occur.
//!
//! \note WARNING: This API cannot be used on endpoint numbers greater than
//! endpoint 3 so USBIntEnableControl() or USBIntEnableEndpoint() should be
//! used instead.
//!
//! \return None.
//
//*****************************************************************************
#ifndef DEPRECATED
void
USBIntEnable(unsigned long ulBase, unsigned long ulFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == USB0_BASE);
    ASSERT((ulFlags & (~USB_INT_ALL)) == 0);

    //
    // If any transmit interrupts were enabled, then write the transmit
    // interrupt settings out to the hardware.
    //
    if(ulFlags & (USB_INT_HOST_OUT | USB_INT_DEV_IN | USB_INT_EP0))
    {
        HWREGH(ulBase + USB_O_TXIE) |=
            ulFlags & (USB_INT_HOST_OUT | USB_INT_DEV_IN | USB_INT_EP0);
    }

    //
    // If any receive interrupts were enabled, then write the receive
    // interrupt settings out to the hardware.
    //
    if(ulFlags & (USB_INT_HOST_IN | USB_INT_DEV_OUT))
    {
        HWREGH(ulBase + USB_O_RXIE) |=
            ((ulFlags & (USB_INT_HOST_IN | USB_INT_DEV_OUT)) >>
             USB_INT_RX_SHIFT);
    }

    //
    // If any general interrupts were enabled, then write the general
    // interrupt settings out to the hardware.
    //
    if(ulFlags & USB_INT_STATUS)
    {
        HWREGB(ulBase + USB_O_IE) |=
            (ulFlags & USB_INT_STATUS) >> USB_INT_STATUS_SHIFT;
    }

    //
    // Enable the power fault interrupt.
    //
    if(ulFlags & USB_INT_POWER_FAULT)
    {
        HWREG(ulBase + USB_O_EPCIM) = USB_EPCIM_PF;
    }

    //
    // Enable the ID pin detect interrupt.
    //
    if(ulFlags & USB_INT_MODE_DETECT)
    {
        HWREG(USB0_BASE + USB_O_IDVIM) = USB_IDVIM_ID;
    }
}
#endif

//*****************************************************************************
//
//! Disables control interrupts on a given USB controller.
//!
//! \param ulBase specifies the USB module base address.
//! \param ulFlags specifies which control interrupts to disable.
//!
//! This function disables the control interrupts for the USB controller
//! specified by the \e ulBase parameter.  The \e ulFlags parameter specifies
//! which control interrupts to disable.  The flags passed in the \e ulFlags
//! parameters should be the definitions that start with \b USB_INTCTRL_* and
//! not any other \b USB_INT flags.
//!
//! \return None.
//
//*****************************************************************************
void
USBIntDisableControl(unsigned long ulBase, unsigned long ulFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == USB0_BASE);
    ASSERT((ulFlags & ~(USB_INTCTRL_ALL)) == 0);

    //
    // If any general interrupts were disabled then write the general interrupt
    // settings out to the hardware.
    //
    if(ulFlags & USB_INTCTRL_STATUS)
    {
        HWREGB(ulBase + USB_O_IE) &= ~(ulFlags & USB_INTCTRL_STATUS);
    }

    //
    // Disable the power fault interrupt.
    //
    if(ulFlags & USB_INTCTRL_POWER_FAULT)
    {
        HWREG(ulBase + USB_O_EPCIM) = 0;
    }

    //
    // Disable the ID pin detect interrupt.
    //
    if(ulFlags & USB_INTCTRL_MODE_DETECT)
    {
        HWREG(USB0_BASE + USB_O_IDVIM) = 0;
    }
}

//*****************************************************************************
//
//! Enables control interrupts on a given USB controller.
//!
//! \param ulBase specifies the USB module base address.
//! \param ulFlags specifies which control interrupts to enable.
//!
//! This function enables the control interrupts for the USB controller
//! specified by the \e ulBase parameter.  The \e ulFlags parameter specifies
//! which control interrupts to enable.  The flags passed in the \e ulFlags
//! parameters should be the definitions that start with \b USB_INTCTRL_* and
//! not any other \b USB_INT flags.
//!
//! \return None.
//
//*****************************************************************************
void
USBIntEnableControl(unsigned long ulBase, unsigned long ulFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == USB0_BASE);
    ASSERT((ulFlags & (~USB_INTCTRL_ALL)) == 0);

    //
    // If any general interrupts were enabled, then write the general
    // interrupt settings out to the hardware.
    //
    if(ulFlags & USB_INTCTRL_STATUS)
    {
        HWREGB(ulBase + USB_O_IE) |= ulFlags;
    }

    //
    // Enable the power fault interrupt.
    //
    if(ulFlags & USB_INTCTRL_POWER_FAULT)
    {
        HWREG(ulBase + USB_O_EPCIM) = USB_EPCIM_PF;
    }

    //
    // Enable the ID pin detect interrupt.
    //
    if(ulFlags & USB_INTCTRL_MODE_DETECT)
    {
        HWREG(USB0_BASE + USB_O_IDVIM) = USB_IDVIM_ID;
    }
}

//*****************************************************************************
//
//! Returns the control interrupt status on a given USB controller.
//!
//! \param ulBase specifies the USB module base address.
//!
//! This function reads control interrupt status for a USB controller. This
//! call returns the current status for control interrupts only, the endpoint
//! interrupt status is retrieved by calling USBIntStatusEndpoint(). The bit
//! values returned should be compared against the \b USB_INTCTRL_*
//! values.
//!
//! The following are the meanings of all \b USB_INCTRL_ flags and the modes
//! for which they are valid.  These values apply to any calls to
//! USBIntStatusControl(), USBIntEnableControl(), and USBIntDisableControl().
//! Some of these flags are only valid in the following modes as indicated in
//! the parentheses:  Host, Device, and OTG.
//!
//! - \b USB_INTCTRL_ALL - A full mask of all control interrupt sources.
//! - \b USB_INTCTRL_VBUS_ERR - A VBUS error has occurred (Host Only).
//! - \b USB_INTCTRL_SESSION - Session Start Detected on A-side of cable
//!                            (OTG Only).
//! - \b USB_INTCTRL_SESSION_END - Session End Detected (Device Only)
//! - \b USB_INTCTRL_DISCONNECT - Device Disconnect Detected (Host Only)
//! - \b USB_INTCTRL_CONNECT - Device Connect Detected (Host Only)
//! - \b USB_INTCTRL_SOF - Start of Frame Detected.
//! - \b USB_INTCTRL_BABBLE - USB controller detected a device signaling past
//!                           the end of a frame. (Host Only)
//! - \b USB_INTCTRL_RESET - Reset signaling detected by device. (Device Only)
//! - \b USB_INTCTRL_RESUME - Resume signaling detected.
//! - \b USB_INTCTRL_SUSPEND - Suspend signaling detected by device (Device
//!                            Only)
//! - \b USB_INTCTRL_MODE_DETECT - OTG cable mode detection has completed
//!                                (OTG Only)
//! - \b USB_INTCTRL_POWER_FAULT - Power Fault detected. (Host Only)
//!
//! \note This call clears the source of all of the control status interrupts.
//!
//! \return Returns the status of the control interrupts for a USB controller.
//
//*****************************************************************************
unsigned long
USBIntStatusControl(unsigned long ulBase)
{
    unsigned long ulStatus;

    //
    // Check the arguments.
    //
    ASSERT(ulBase == USB0_BASE);

    //
    // Get the general interrupt status, these bits go into the upper 8 bits
    // of the returned value.
    //
    ulStatus = HWREGB(ulBase + USB_O_IS);

    //
    // Add the power fault status.
    //
    if(HWREG(ulBase + USB_O_EPCISC) & USB_EPCISC_PF)
    {
        //
        // Indicate a power fault was detected.
        //
        ulStatus |= USB_INTCTRL_POWER_FAULT;

        //
        // Clear the power fault interrupt.
        //
        HWREGB(ulBase + USB_O_EPCISC) |= USB_EPCISC_PF;
    }

    if(HWREG(USB0_BASE + USB_O_IDVISC) & USB_IDVRIS_ID)
    {
        //
        // Indicate an id detection.
        //
        ulStatus |= USB_INTCTRL_MODE_DETECT;

        //
        // Clear the id detection interrupt.
        //
        HWREG(USB0_BASE + USB_O_IDVISC) |= USB_IDVRIS_ID;
    }

    //
    // Return the combined interrupt status.
    //
    return(ulStatus);
}

//*****************************************************************************
//
//! Disables endpoint interrupts on a given USB controller.
//!
//! \param ulBase specifies the USB module base address.
//! \param ulFlags specifies which endpoint interrupts to disable.
//!
//! This function disables endpoint interrupts for the USB controller specified
//! by the \e ulBase parameter.  The \e ulFlags parameter specifies which
//! endpoint interrupts to disable.  The flags passed in the \e ulFlags
//! parameters should be the definitions that start with \b USB_INTEP_* and not
//! any other \b USB_INT flags.
//!
//! \return None.
//
//*****************************************************************************
void
USBIntDisableEndpoint(unsigned long ulBase, unsigned long ulFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == USB0_BASE);

    //
    // If any transmit interrupts were disabled, then write the transmit
    // interrupt settings out to the hardware.
    //
    HWREGH(ulBase + USB_O_TXIE) &=
        ~(ulFlags & (USB_INTEP_HOST_OUT | USB_INTEP_DEV_IN | USB_INTEP_0));

    //
    // If any receive interrupts were disabled, then write the receive interrupt
    // settings out to the hardware.
    //
    HWREGH(ulBase + USB_O_RXIE) &=
        ~((ulFlags & (USB_INTEP_HOST_IN | USB_INTEP_DEV_OUT)) >>
          USB_INTEP_RX_SHIFT);
}

//*****************************************************************************
//
//! Enables endpoint interrupts on a given USB controller.
//!
//! \param ulBase specifies the USB module base address.
//! \param ulFlags specifies which endpoint interrupts to enable.
//!
//! This function enables endpoint interrupts for the USB controller specified
//! by the \e ulBase parameter.  The \e ulFlags parameter specifies which
//! endpoint interrupts to enable.  The flags passed in the \e ulFlags
//! parameters should be the definitions that start with \b USB_INTEP_* and not
//! any other \b USB_INT flags.
//!
//! \return None.
//
//*****************************************************************************
void
USBIntEnableEndpoint(unsigned long ulBase, unsigned long ulFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == USB0_BASE);

    //
    // Enable any transmit endpoint interrupts.
    //
    HWREGH(ulBase + USB_O_TXIE) |=
           ulFlags & (USB_INTEP_HOST_OUT | USB_INTEP_DEV_IN | USB_INTEP_0);

    //
    // Enable any receive endpoint interrupts.
    //
    HWREGH(ulBase + USB_O_RXIE) |=
        ((ulFlags & (USB_INTEP_HOST_IN | USB_INTEP_DEV_OUT)) >>
         USB_INTEP_RX_SHIFT);
}

//*****************************************************************************
//
//! Returns the endpoint interrupt status on a given USB controller.
//!
//! \param ulBase specifies the USB module base address.
//!
//! This function reads endpoint interrupt status for a USB controller. This
//! call returns the current status for endpoint interrupts only, the control
//! interrupt status is retrieved by calling USBIntStatusControl(). The bit
//! values returned should be compared against the \b USB_INTEP_* values.
//! These values are grouped into classes for \b USB_INTEP_HOST_* and
//! \b USB_INTEP_DEV_* values to handle both host and device modes with all
//! endpoints.
//!
//! \note This call clears the source of all of the endpoint interrupts.
//!
//! \return Returns the status of the endpoint interrupts for a USB controller.
//
//*****************************************************************************
unsigned long
USBIntStatusEndpoint(unsigned long ulBase)
{
    unsigned long ulStatus;

    //
    // Check the arguments.
    //
    ASSERT(ulBase == USB0_BASE);

    //
    // Get the transmit interrupt status.
    //
    ulStatus = HWREGH(ulBase + USB_O_TXIS);

    ulStatus |= (HWREGH(ulBase + USB_O_RXIS) << USB_INTEP_RX_SHIFT);

    //
    // Return the combined interrupt status.
    //
    return(ulStatus);
}

//*****************************************************************************
//
//! Registers an interrupt handler for the USB controller.
//!
//! \param ulBase specifies the USB module base address.
//! \param pfnHandler is a pointer to the function to be called when a USB
//! interrupt occurs.
//!
//! This function registers the handler to be called when a USB interrupt
//! occurs and enables the global USB interrupt in the interrupt controller.
//! The specific desired USB interrupts must be enabled via a separate call to
//! USBIntEnable().  It is the interrupt handler's responsibility to clear the
//! interrupt sources via calls to USBIntStatusControl() and
//! USBIntStatusEndpoint().
//!
//! \sa IntRegister() for important information about registering interrupt
//! handlers.
//!
//! \return None.
//
//*****************************************************************************
void
USBIntRegister(unsigned long ulBase, void(*pfnHandler)(void))
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == USB0_BASE);

    //
    // Register the interrupt handler.
    //
    IntRegister(INT_USB0, pfnHandler);

    //
    // Enable the USB interrupt.
    //
    IntEnable(INT_USB0);
}

//*****************************************************************************
//
//! Unregisters an interrupt handler for the USB controller.
//!
//! \param ulBase specifies the USB module base address.
//!
//! This function unregisters the interrupt handler.  This function also
//! disables the USB interrupt in the interrupt controller.
//!
//! \sa IntRegister() for important information about registering or
//! unregistering interrupt handlers.
//!
//! \return None.
//
//*****************************************************************************
void
USBIntUnregister(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == USB0_BASE);

    //
    // Disable the USB interrupt.
    //
    IntDisable(INT_USB0);

    //
    // Unregister the interrupt handler.
    //
    IntUnregister(INT_USB0);
}

//*****************************************************************************
//
//! Returns the current status of an endpoint.
//!
//! \param ulBase specifies the USB module base address.
//! \param ulEndpoint is the endpoint to access.
//!
//! This function returns the status of a given endpoint.  If any of these
//! status bits must be cleared, then the USBDevEndpointStatusClear() or the
//! USBHostEndpointStatusClear() functions should be called.
//!
//! The following are the status flags for host mode:
//!
//! - \b USB_HOST_IN_PID_ERROR - PID error on the given endpoint.
//! - \b USB_HOST_IN_NOT_COMP - The device failed to respond to an IN request.
//! - \b USB_HOST_IN_STALL - A stall was received on an IN endpoint.
//! - \b USB_HOST_IN_DATA_ERROR - There was a CRC or bit-stuff error on an IN
//!   endpoint in Isochronous mode.
//! - \b USB_HOST_IN_NAK_TO - NAKs received on this IN endpoint for more than
//!   the specified timeout period.
//! - \b USB_HOST_IN_ERROR - Failed to communicate with a device using this IN
//!   endpoint.
//! - \b USB_HOST_IN_FIFO_FULL - This IN endpoint's FIFO is full.
//! - \b USB_HOST_IN_PKTRDY - Data packet ready on this IN endpoint.
//! - \b USB_HOST_OUT_NAK_TO - NAKs received on this OUT endpoint for more than
//!   the specified timeout period.
//! - \b USB_HOST_OUT_NOT_COMP - The device failed to respond to an OUT
//!   request.
//! - \b USB_HOST_OUT_STALL - A stall was received on this OUT endpoint.
//! - \b USB_HOST_OUT_ERROR - Failed to communicate with a device using this
//!   OUT endpoint.
//! - \b USB_HOST_OUT_FIFO_NE - This endpoint's OUT FIFO is not empty.
//! - \b USB_HOST_OUT_PKTPEND - The data transfer on this OUT endpoint has not
//!   completed.
//! - \b USB_HOST_EP0_NAK_TO - NAKs received on endpoint zero for more than the
//!   specified timeout period.
//! - \b USB_HOST_EP0_ERROR - The device failed to respond to a request on
//!   endpoint zero.
//! - \b USB_HOST_EP0_IN_STALL - A stall was received on endpoint zero for an
//!   IN transaction.
//! - \b USB_HOST_EP0_IN_PKTRDY - Data packet ready on endpoint zero for an IN
//!   transaction.
//!
//! The following are the status flags for device mode:
//!
//! - \b USB_DEV_OUT_SENT_STALL - A stall was sent on this OUT endpoint.
//! - \b USB_DEV_OUT_DATA_ERROR - There was a CRC or bit-stuff error on an OUT
//!   endpoint.
//! - \b USB_DEV_OUT_OVERRUN - An OUT packet was not loaded due to a full FIFO.
//! - \b USB_DEV_OUT_FIFO_FULL - The OUT endpoint's FIFO is full.
//! - \b USB_DEV_OUT_PKTRDY - There is a data packet ready in the OUT
//!   endpoint's FIFO.
//! - \b USB_DEV_IN_NOT_COMP - A larger packet was split up, more data to come.
//! - \b USB_DEV_IN_SENT_STALL - A stall was sent on this IN endpoint.
//! - \b USB_DEV_IN_UNDERRUN - Data was requested on the IN endpoint and no
//!   data was ready.
//! - \b USB_DEV_IN_FIFO_NE - The IN endpoint's FIFO is not empty.
//! - \b USB_DEV_IN_PKTPEND - The data transfer on this IN endpoint has not
//!   completed.
//! - \b USB_DEV_EP0_SETUP_END - A control transaction ended before Data End
//!   condition was sent.
//! - \b USB_DEV_EP0_SENT_STALL - A stall was sent on endpoint zero.
//! - \b USB_DEV_EP0_IN_PKTPEND - The data transfer on endpoint zero has not
//!   completed.
//! - \b USB_DEV_EP0_OUT_PKTRDY - There is a data packet ready in endpoint
//!   zero's OUT FIFO.
//!
//! \return The current status flags for the endpoint depending on mode.
//
//*****************************************************************************
unsigned long
USBEndpointStatus(unsigned long ulBase, unsigned long ulEndpoint)
{
    unsigned long ulStatus;

    //
    // Check the arguments.
    //
    ASSERT(ulBase == USB0_BASE);
    ASSERT((ulEndpoint == USB_EP_0) || (ulEndpoint == USB_EP_1) ||
           (ulEndpoint == USB_EP_2) || (ulEndpoint == USB_EP_3) ||
           (ulEndpoint == USB_EP_4) || (ulEndpoint == USB_EP_5) ||
           (ulEndpoint == USB_EP_6) || (ulEndpoint == USB_EP_7) ||
           (ulEndpoint == USB_EP_8) || (ulEndpoint == USB_EP_9) ||
           (ulEndpoint == USB_EP_10) || (ulEndpoint == USB_EP_11) ||
           (ulEndpoint == USB_EP_12) || (ulEndpoint == USB_EP_13) ||
           (ulEndpoint == USB_EP_14) || (ulEndpoint == USB_EP_15));

    //
    // Get the TX portion of the endpoint status.
    //
    ulStatus = HWREGH(ulBase + EP_OFFSET(ulEndpoint) + USB_O_TXCSRL1);

    //
    // Get the RX portion of the endpoint status.
    //
    ulStatus |= ((HWREGH(ulBase + EP_OFFSET(ulEndpoint) + USB_O_RXCSRL1)) <<
                 USB_RX_EPSTATUS_SHIFT);

    //
    // Return the endpoint status.
    //
    return(ulStatus);
}

//*****************************************************************************
//
//! Clears the status bits in this endpoint in host mode.
//!
//! \param ulBase specifies the USB module base address.
//! \param ulEndpoint is the endpoint to access.
//! \param ulFlags are the status bits that should be cleared.
//!
//! This function clears the status of any bits that are passed in the
//! \e ulFlags parameter.  The \e ulFlags parameter can take the value returned
//! from the USBEndpointStatus() call.
//!
//! \note This function should only be called in host mode.
//!
//! \return None.
//
//*****************************************************************************
void
USBHostEndpointStatusClear(unsigned long ulBase, unsigned long ulEndpoint,
                           unsigned long ulFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == USB0_BASE);
    ASSERT((ulEndpoint == USB_EP_0) || (ulEndpoint == USB_EP_1) ||
           (ulEndpoint == USB_EP_2) || (ulEndpoint == USB_EP_3) ||
           (ulEndpoint == USB_EP_4) || (ulEndpoint == USB_EP_5) ||
           (ulEndpoint == USB_EP_6) || (ulEndpoint == USB_EP_7) ||
           (ulEndpoint == USB_EP_8) || (ulEndpoint == USB_EP_9) ||
           (ulEndpoint == USB_EP_10) || (ulEndpoint == USB_EP_11) ||
           (ulEndpoint == USB_EP_12) || (ulEndpoint == USB_EP_13) ||
           (ulEndpoint == USB_EP_14) || (ulEndpoint == USB_EP_15));

    //
    // Clear the specified flags for the endpoint.
    //
    if(ulEndpoint == USB_EP_0)
    {
        HWREGB(ulBase + USB_O_CSRL0) &= ~ulFlags;
    }
    else
    {
        HWREGB(ulBase + USB_O_TXCSRL1 + EP_OFFSET(ulEndpoint)) &= ~ulFlags;
        HWREGB(ulBase + USB_O_RXCSRL1 + EP_OFFSET(ulEndpoint)) &=
            ~(ulFlags >> USB_RX_EPSTATUS_SHIFT);
    }
}

//*****************************************************************************
//
//! Clears the status bits in this endpoint in device mode.
//!
//! \param ulBase specifies the USB module base address.
//! \param ulEndpoint is the endpoint to access.
//! \param ulFlags are the status bits that should be cleared.
//!
//! This function clears the status of any bits that are passed in the
//! \e ulFlags parameter.  The \e ulFlags parameter can take the value returned
//! from the USBEndpointStatus() call.
//!
//! \note This function should only be called in device mode.
//!
//! \return None.
//
//*****************************************************************************
void
USBDevEndpointStatusClear(unsigned long ulBase, unsigned long ulEndpoint,
                          unsigned long ulFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == USB0_BASE);
    ASSERT((ulEndpoint == USB_EP_0) || (ulEndpoint == USB_EP_1) ||
           (ulEndpoint == USB_EP_2) || (ulEndpoint == USB_EP_3) ||
           (ulEndpoint == USB_EP_4) || (ulEndpoint == USB_EP_5) ||
           (ulEndpoint == USB_EP_6) || (ulEndpoint == USB_EP_7) ||
           (ulEndpoint == USB_EP_8) || (ulEndpoint == USB_EP_9) ||
           (ulEndpoint == USB_EP_10) || (ulEndpoint == USB_EP_11) ||
           (ulEndpoint == USB_EP_12) || (ulEndpoint == USB_EP_13) ||
           (ulEndpoint == USB_EP_14) || (ulEndpoint == USB_EP_15));

    //
    // If this is endpoint 0, then the bits have different meaning and map
    // into the TX memory location.
    //
    if(ulEndpoint == USB_EP_0)
    {
        //
        // Set the Serviced RxPktRdy bit to clear the RxPktRdy.
        //
        if(ulFlags & USB_DEV_EP0_OUT_PKTRDY)
        {
            HWREGB(ulBase + USB_O_CSRL0) |= USB_CSRL0_RXRDYC;
        }

        //
        // Set the serviced Setup End bit to clear the SetupEnd status.
        //
        if(ulFlags & USB_DEV_EP0_SETUP_END)
        {
            HWREGB(ulBase + USB_O_CSRL0) |= USB_CSRL0_SETENDC;
        }

        //
        // Clear the Sent Stall status flag.
        //
        if(ulFlags & USB_DEV_EP0_SENT_STALL)
        {
            HWREGB(ulBase + USB_O_CSRL0) &= ~(USB_DEV_EP0_SENT_STALL);
        }
    }
    else
    {
        //
        // Clear out any TX flags that were passed in.  Only
        // USB_DEV_TX_SENT_STALL and USB_DEV_TX_UNDERRUN should be cleared.
        //
        HWREGB(ulBase + USB_O_TXCSRL1 + EP_OFFSET(ulEndpoint)) &=
            ~(ulFlags & (USB_DEV_TX_SENT_STALL | USB_DEV_TX_UNDERRUN));

        //
        // Clear out valid RX flags that were passed in.  Only
        // USB_DEV_RX_SENT_STALL, USB_DEV_RX_DATA_ERROR, and USB_DEV_RX_OVERRUN
        // should be cleared.
        //
        HWREGB(ulBase + USB_O_RXCSRL1 + EP_OFFSET(ulEndpoint)) &=
            ~((ulFlags & (USB_DEV_RX_SENT_STALL | USB_DEV_RX_DATA_ERROR |
                          USB_DEV_RX_OVERRUN)) >> USB_RX_EPSTATUS_SHIFT);
    }
}

//*****************************************************************************
//
//! Sets the value data toggle on an endpoint in host mode.
//!
//! \param ulBase specifies the USB module base address.
//! \param ulEndpoint specifies the endpoint to reset the data toggle.
//! \param bDataToggle specifies whether to set the state to DATA0 or DATA1.
//! \param ulFlags specifies whether to set the IN or OUT endpoint.
//!
//! This function is used to force the state of the data toggle in host mode.
//! If the value passed in the \e bDataToggle parameter is \b false, then the
//! data toggle is set to the DATA0 state, and if it is \b true it is set to
//! the DATA1 state.  The \e ulFlags parameter can be \b USB_EP_HOST_IN or
//! \b USB_EP_HOST_OUT to access the desired portion of this endpoint.  The
//! \e ulFlags parameter is ignored for endpoint zero.
//!
//! \note This function should only be called in host mode.
//!
//! \return None.
//
//*****************************************************************************
void
USBHostEndpointDataToggle(unsigned long ulBase, unsigned long ulEndpoint,
                          tBoolean bDataToggle, unsigned long ulFlags)
{
    unsigned long ulDataToggle;

    //
    // Check the arguments.
    //
    ASSERT(ulBase == USB0_BASE);
    ASSERT((ulEndpoint == USB_EP_0) || (ulEndpoint == USB_EP_1) ||
           (ulEndpoint == USB_EP_2) || (ulEndpoint == USB_EP_3) ||
           (ulEndpoint == USB_EP_4) || (ulEndpoint == USB_EP_5) ||
           (ulEndpoint == USB_EP_6) || (ulEndpoint == USB_EP_7) ||
           (ulEndpoint == USB_EP_8) || (ulEndpoint == USB_EP_9) ||
           (ulEndpoint == USB_EP_10) || (ulEndpoint == USB_EP_11) ||
           (ulEndpoint == USB_EP_12) || (ulEndpoint == USB_EP_13) ||
           (ulEndpoint == USB_EP_14) || (ulEndpoint == USB_EP_15));

    //
    // The data toggle defaults to DATA0.
    //
    ulDataToggle = 0;

    //
    // See if the data toggle should be set to DATA1.
    //
    if(bDataToggle)
    {
        //
        // Select the data toggle bit based on the endpoint.
        //
        if(ulEndpoint == USB_EP_0)
        {
            ulDataToggle = USB_CSRH0_DT;
        }
        else if(ulFlags == USB_EP_HOST_IN)
        {
            ulDataToggle = USB_RXCSRH1_DT;
        }
        else
        {
            ulDataToggle = USB_TXCSRH1_DT;
        }
    }

    //
    // Set the data toggle based on the endpoint.
    //
    if(ulEndpoint == USB_EP_0)
    {
        //
        // Set the write enable and the bit value for endpoint zero.
        //
        HWREGB(ulBase + USB_O_CSRH0) =
            ((HWREGB(ulBase + USB_O_CSRH0) &
              ~(USB_CSRH0_DTWE | USB_CSRH0_DT)) |
             (ulDataToggle | USB_CSRH0_DTWE));
    }
    else if(ulFlags == USB_EP_HOST_IN)
    {
        //
        // Set the Write enable and the bit value for an IN endpoint.
        //
        HWREGB(ulBase + USB_O_RXCSRH1 + EP_OFFSET(ulEndpoint)) =
            ((HWREGB(ulBase + USB_O_RXCSRH1 + EP_OFFSET(ulEndpoint)) &
              ~(USB_RXCSRH1_DTWE | USB_RXCSRH1_DT)) |
             (ulDataToggle | USB_RXCSRH1_DTWE));
    }
    else
    {
        //
        // Set the Write enable and the bit value for an OUT endpoint.
        //
        HWREGB(ulBase + USB_O_TXCSRH1 + EP_OFFSET(ulEndpoint)) =
            ((HWREGB(ulBase + USB_O_TXCSRH1 + EP_OFFSET(ulEndpoint)) &
              ~(USB_TXCSRH1_DTWE | USB_TXCSRH1_DT)) |
             (ulDataToggle | USB_TXCSRH1_DTWE));
    }
}

//*****************************************************************************
//
//! Sets the data toggle on an endpoint to zero.
//!
//! \param ulBase specifies the USB module base address.
//! \param ulEndpoint specifies the endpoint to reset the data toggle.
//! \param ulFlags specifies whether to access the IN or OUT endpoint.
//!
//! This function causes the USB controller to clear the data toggle for an
//! endpoint.  This call is not valid for endpoint zero and can be made with
//! host or device controllers.
//!
//! The \e ulFlags parameter should be one of \b USB_EP_HOST_OUT,
//! \b USB_EP_HOST_IN, \b USB_EP_DEV_OUT, or \b USB_EP_DEV_IN.
//!
//! \return None.
//
//*****************************************************************************
void
USBEndpointDataToggleClear(unsigned long ulBase, unsigned long ulEndpoint,
                           unsigned long ulFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == USB0_BASE);
    ASSERT((ulEndpoint == USB_EP_1) || (ulEndpoint == USB_EP_2) ||
           (ulEndpoint == USB_EP_3) || (ulEndpoint == USB_EP_4) ||
           (ulEndpoint == USB_EP_5) || (ulEndpoint == USB_EP_6) ||
           (ulEndpoint == USB_EP_7) || (ulEndpoint == USB_EP_8) ||
           (ulEndpoint == USB_EP_9) || (ulEndpoint == USB_EP_10) ||
           (ulEndpoint == USB_EP_11) || (ulEndpoint == USB_EP_12) ||
           (ulEndpoint == USB_EP_13) || (ulEndpoint == USB_EP_14) ||
           (ulEndpoint == USB_EP_15));

    //
    // See if the transmit or receive data toggle should be cleared.
    //
    if(ulFlags & (USB_EP_HOST_OUT | USB_EP_DEV_IN))
    {
        HWREGB(ulBase + USB_O_TXCSRL1 + EP_OFFSET(ulEndpoint)) |=
            USB_TXCSRL1_CLRDT;
    }
    else
    {
        HWREGB(ulBase + USB_O_RXCSRL1 + EP_OFFSET(ulEndpoint)) |=
            USB_RXCSRL1_CLRDT;
    }
}

//*****************************************************************************
//
//! Stalls the specified endpoint in device mode.
//!
//! \param ulBase specifies the USB module base address.
//! \param ulEndpoint specifies the endpoint to stall.
//! \param ulFlags specifies whether to stall the IN or OUT endpoint.
//!
//! This function causes the endpoint number passed in to go into a stall
//! condition.  If the \e ulFlags parameter is \b USB_EP_DEV_IN, then the stall
//! is issued on the IN portion of this endpoint.  If the \e ulFlags parameter
//! is \b USB_EP_DEV_OUT, then the stall is issued on the OUT portion of this
//! endpoint.
//!
//! \note This function should only be called in device mode.
//!
//! \return None.
//
//*****************************************************************************
void
USBDevEndpointStall(unsigned long ulBase, unsigned long ulEndpoint,
                    unsigned long ulFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == USB0_BASE);
    ASSERT((ulFlags & ~(USB_EP_DEV_IN | USB_EP_DEV_OUT)) == 0)
    ASSERT((ulEndpoint == USB_EP_0) || (ulEndpoint == USB_EP_1) ||
           (ulEndpoint == USB_EP_2) || (ulEndpoint == USB_EP_3) ||
           (ulEndpoint == USB_EP_4) || (ulEndpoint == USB_EP_5) ||
           (ulEndpoint == USB_EP_6) || (ulEndpoint == USB_EP_7) ||
           (ulEndpoint == USB_EP_8) || (ulEndpoint == USB_EP_9) ||
           (ulEndpoint == USB_EP_10) || (ulEndpoint == USB_EP_11) ||
           (ulEndpoint == USB_EP_12) || (ulEndpoint == USB_EP_13) ||
           (ulEndpoint == USB_EP_14) || (ulEndpoint == USB_EP_15));

    //
    // Determine how to stall this endpoint.
    //
    if(ulEndpoint == USB_EP_0)
    {
        //
        // Perform a stall on endpoint zero.
        //
        HWREGB(ulBase + USB_O_CSRL0) |=
            (USB_CSRL0_STALL | USB_CSRL0_RXRDYC);
    }
    else if(ulFlags == USB_EP_DEV_IN)
    {
        //
        // Perform a stall on an IN endpoint.
        //
        HWREGB(ulBase + USB_O_TXCSRL1 + EP_OFFSET(ulEndpoint)) |=
            USB_TXCSRL1_STALL;
    }
    else
    {
        //
        // Perform a stall on an OUT endpoint.
        //
        HWREGB(ulBase + USB_O_RXCSRL1 + EP_OFFSET(ulEndpoint)) |=
            USB_RXCSRL1_STALL;
    }
}

//*****************************************************************************
//
//! Clears the stall condition on the specified endpoint in device mode.
//!
//! \param ulBase specifies the USB module base address.
//! \param ulEndpoint specifies which endpoint to remove the stall condition.
//! \param ulFlags specifies whether to remove the stall condition from the IN
//! or the OUT portion of this endpoint.
//!
//! This function causes the endpoint number passed in to exit the stall
//! condition.  If the \e ulFlags parameter is \b USB_EP_DEV_IN, then the stall
//! is cleared on the IN portion of this endpoint.  If the \e ulFlags parameter
//! is \b USB_EP_DEV_OUT, then the stall is cleared on the OUT portion of this
//! endpoint.
//!
//! \note This function should only be called in device mode.
//!
//! \return None.
//
//*****************************************************************************
void
USBDevEndpointStallClear(unsigned long ulBase, unsigned long ulEndpoint,
                         unsigned long ulFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == USB0_BASE);
    ASSERT((ulEndpoint == USB_EP_0) || (ulEndpoint == USB_EP_1) ||
           (ulEndpoint == USB_EP_2) || (ulEndpoint == USB_EP_3) ||
           (ulEndpoint == USB_EP_4) || (ulEndpoint == USB_EP_5) ||
           (ulEndpoint == USB_EP_6) || (ulEndpoint == USB_EP_7) ||
           (ulEndpoint == USB_EP_8) || (ulEndpoint == USB_EP_9) ||
           (ulEndpoint == USB_EP_10) || (ulEndpoint == USB_EP_11) ||
           (ulEndpoint == USB_EP_12) || (ulEndpoint == USB_EP_13) ||
           (ulEndpoint == USB_EP_14) || (ulEndpoint == USB_EP_15));
    ASSERT((ulFlags & ~(USB_EP_DEV_IN | USB_EP_DEV_OUT)) == 0)

    //
    // Determine how to clear the stall on this endpoint.
    //
    if(ulEndpoint == USB_EP_0)
    {
        //
        // Clear the stall on endpoint zero.
        //
        HWREGB(ulBase + USB_O_CSRL0) &= ~USB_CSRL0_STALLED;
    }
    else if(ulFlags == USB_EP_DEV_IN)
    {
        //
        // Clear the stall on an IN endpoint.
        //
        HWREGB(ulBase + USB_O_TXCSRL1 + EP_OFFSET(ulEndpoint)) &=
            ~(USB_TXCSRL1_STALL | USB_TXCSRL1_STALLED);

        //
        // Reset the data toggle.
        //
        HWREGB(ulBase + USB_O_TXCSRL1 + EP_OFFSET(ulEndpoint)) |=
            USB_TXCSRL1_CLRDT;
    }
    else
    {
        //
        // Clear the stall on an OUT endpoint.
        //
        HWREGB(ulBase + USB_O_RXCSRL1 + EP_OFFSET(ulEndpoint)) &=
            ~(USB_RXCSRL1_STALL | USB_RXCSRL1_STALLED);

        //
        // Reset the data toggle.
        //
        HWREGB(ulBase + USB_O_RXCSRL1 + EP_OFFSET(ulEndpoint)) |=
            USB_RXCSRL1_CLRDT;
    }
}

//*****************************************************************************
//
//! Connects the USB controller to the bus in device mode.
//!
//! \param ulBase specifies the USB module base address.
//!
//! This function causes the soft connect feature of the USB controller to
//! be enabled.  Call USBDevDisconnect() to remove the USB device from the bus.
//!
//! \note This function should only be called in device mode.
//!
//! \return None.
//
//*****************************************************************************
void
USBDevConnect(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == USB0_BASE);

    //
    // Enable connection to the USB bus.
    //
    HWREGB(ulBase + USB_O_POWER) |= USB_POWER_SOFTCONN;
}

//*****************************************************************************
//
//! Removes the USB controller from the bus in device mode.
//!
//! \param ulBase specifies the USB module base address.
//!
//! This function causes the soft connect feature of the USB controller to
//! remove the device from the USB bus.  A call to USBDevConnect() is needed to
//! reconnect to the bus.
//!
//! \note This function should only be called in device mode.
//!
//! \return None.
//
//*****************************************************************************
void
USBDevDisconnect(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == USB0_BASE);

    //
    // Disable connection to the USB bus.
    //
    HWREGB(ulBase + USB_O_POWER) &= (~USB_POWER_SOFTCONN);
}

//*****************************************************************************
//
//! Sets the address in device mode.
//!
//! \param ulBase specifies the USB module base address.
//! \param ulAddress is the address to use for a device.
//!
//! This function configures the device address on the USB bus.  This address
//! was likely received via a SET ADDRESS command from the host controller.
//!
//! \note This function should only be called in device mode.
//!
//! \return None.
//
//*****************************************************************************
void
USBDevAddrSet(unsigned long ulBase, unsigned long ulAddress)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == USB0_BASE);

    //
    // Set the function address in the correct location.
    //
    HWREGB(ulBase + USB_O_FADDR) = (unsigned char)ulAddress;
}

//*****************************************************************************
//
//! Returns the current device address in device mode.
//!
//! \param ulBase specifies the USB module base address.
//!
//! This function returns the current device address.  This address was set
//! by a call to USBDevAddrSet().
//!
//! \note This function should only be called in device mode.
//!
//! \return The current device address.
//
//*****************************************************************************
unsigned long
USBDevAddrGet(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == USB0_BASE);

    //
    // Return the function address.
    //
    return(HWREGB(ulBase + USB_O_FADDR));
}

//*****************************************************************************
//
//! Sets the base configuration for a host endpoint.
//!
//! \param ulBase specifies the USB module base address.
//! \param ulEndpoint is the endpoint to access.
//! \param ulMaxPayload is the maximum payload for this endpoint.
//! \param ulNAKPollInterval is the either the NAK timeout limit or the polling
//! interval, depending on the type of endpoint.
//! \param ulTargetEndpoint is the endpoint that the host endpoint is
//! targeting.
//! \param ulFlags are used to configure other endpoint settings.
//!
//! This function sets the basic configuration for the transmit or receive
//! portion of an endpoint in host mode.  The \e ulFlags parameter determines
//! some of the configuration while the other parameters provide the rest.  The
//! \e ulFlags parameter determines whether this is an IN endpoint
//! (\b USB_EP_HOST_IN or \b USB_EP_DEV_IN) or an OUT endpoint
//! (\b USB_EP_HOST_OUT or \b USB_EP_DEV_OUT), whether this is a Full speed
//! endpoint (\b USB_EP_SPEED_FULL) or a Low speed endpoint
//! (\b USB_EP_SPEED_LOW).
//!
//! The \b USB_EP_MODE_ flags control the type of the endpoint.
//! - \b USB_EP_MODE_CTRL is a control endpoint.
//! - \b USB_EP_MODE_ISOC is an isochronous endpoint.
//! - \b USB_EP_MODE_BULK is a bulk endpoint.
//! - \b USB_EP_MODE_INT is an interrupt endpoint.
//!
//! The \e ulNAKPollInterval parameter has different meanings based on the
//! \b USB_EP_MODE value and whether or not this call is being made for
//! endpoint zero or another endpoint.  For endpoint zero or any Bulk
//! endpoints, this value always indicates the number of frames to allow a
//! device to NAK before considering it a timeout.  If this endpoint is an
//! isochronous or interrupt endpoint, this value is the polling interval for
//! this endpoint.
//!
//! For interrupt endpoints, the polling interval is simply the number of
//! frames between polling an interrupt endpoint.  For isochronous endpoints
//! this value represents a polling interval of 2 ^ (\e ulNAKPollInterval - 1)
//! frames.  When used as a NAK timeout, the \e ulNAKPollInterval value
//! specifies 2 ^ (\e ulNAKPollInterval - 1) frames before issuing a time out.
//! There are two special time out values that can be specified when setting
//! the \e ulNAKPollInterval value.  The first is \b MAX_NAK_LIMIT, which is
//! the maximum value that can be passed in this variable.  The other is
//! \b DISABLE_NAK_LIMIT, which indicates that there should be no limit on the
//! number of NAKs.
//!
//! The \b USB_EP_DMA_MODE_ flags enable the type of DMA used to access the
//! endpoint's data FIFOs.  The choice of the DMA mode depends on how the DMA
//! controller is configured and how it is being used.  See the ``Using USB
//! with the uDMA Controller'' section for more information on DMA
//! configuration.
//!
//! When configuring the OUT portion of an endpoint, the \b USB_EP_AUTO_SET bit
//! is specified to cause the transmission of data on the USB bus to start
//! as soon as the number of bytes specified by \e ulMaxPayload has been
//! written into the OUT FIFO for this endpoint.
//!
//! When configuring the IN portion of an endpoint, the \b USB_EP_AUTO_REQUEST
//! bit can be specified to trigger the request for more data once the FIFO has
//! been drained enough to fit \e ulMaxPayload bytes.  The \b USB_EP_AUTO_CLEAR
//! bit can be used to clear the data packet ready flag automatically once the
//! data has been read from the FIFO.  If this option is not used, this flag
//! must be manually cleared via a call to USBDevEndpointStatusClear() or
//! USBHostEndpointStatusClear().
//!
//! \note This function should only be called in host mode.
//!
//! \return None.
//
//*****************************************************************************
void
USBHostEndpointConfig(unsigned long ulBase, unsigned long ulEndpoint,
                      unsigned long ulMaxPayload,
                      unsigned long ulNAKPollInterval,
                      unsigned long ulTargetEndpoint, unsigned long ulFlags)
{
    unsigned long ulRegister;

    //
    // Check the arguments.
    //
    ASSERT(ulBase == USB0_BASE);
    ASSERT((ulEndpoint == USB_EP_0) || (ulEndpoint == USB_EP_1) ||
           (ulEndpoint == USB_EP_2) || (ulEndpoint == USB_EP_3) ||
           (ulEndpoint == USB_EP_4) || (ulEndpoint == USB_EP_5) ||
           (ulEndpoint == USB_EP_6) || (ulEndpoint == USB_EP_7) ||
           (ulEndpoint == USB_EP_8) || (ulEndpoint == USB_EP_9) ||
           (ulEndpoint == USB_EP_10) || (ulEndpoint == USB_EP_11) ||
           (ulEndpoint == USB_EP_12) || (ulEndpoint == USB_EP_13) ||
           (ulEndpoint == USB_EP_14) || (ulEndpoint == USB_EP_15));
    ASSERT(ulNAKPollInterval <= MAX_NAK_LIMIT);

    //
    // Endpoint zero is configured differently than the other endpoints, so see
    // if this is endpoint zero.
    //
    if(ulEndpoint == USB_EP_0)
    {
        //
        // Set the NAK timeout.
        //
        HWREGB(ulBase + USB_O_NAKLMT) = ulNAKPollInterval;

        //
        // Set the transfer type information.
        //
        HWREGB(ulBase + USB_O_TYPE0) =
            ((ulFlags & USB_EP_SPEED_FULL) ? USB_TYPE0_SPEED_FULL :
             USB_TYPE0_SPEED_LOW);
    }
    else
    {
        //
        // Start with the target endpoint.
        //
        ulRegister = ulTargetEndpoint;

        //
        // Set the speed for the device using this endpoint.
        //
        if(ulFlags & USB_EP_SPEED_FULL)
        {
            ulRegister |= USB_TXTYPE1_SPEED_FULL;
        }
        else
        {
            ulRegister |= USB_TXTYPE1_SPEED_LOW;
        }

        //
        // Set the protocol for the device using this endpoint.
        //
        switch(ulFlags & USB_EP_MODE_MASK)
        {
            //
            // The bulk protocol is being used.
            //
            case USB_EP_MODE_BULK:
            {
                ulRegister |= USB_TXTYPE1_PROTO_BULK;
                break;
            }

            //
            // The isochronous protocol is being used.
            //
            case USB_EP_MODE_ISOC:
            {
                ulRegister |= USB_TXTYPE1_PROTO_ISOC;
                break;
            }

            //
            // The interrupt protocol is being used.
            //
            case USB_EP_MODE_INT:
            {
                ulRegister |= USB_TXTYPE1_PROTO_INT;
                break;
            }

            //
            // The control protocol is being used.
            //
            case USB_EP_MODE_CTRL:
            {
                ulRegister |= USB_TXTYPE1_PROTO_CTRL;
                break;
            }
        }

        //
        // See if the transmit or receive endpoint is being configured.
        //
        if(ulFlags & USB_EP_HOST_OUT)
        {
            //
            // Set the transfer type information.
            //
            HWREGB(ulBase + EP_OFFSET(ulEndpoint) + USB_O_TXTYPE1) =
                ulRegister;

            //
            // Set the NAK timeout or polling interval.
            //
            HWREGB(ulBase + EP_OFFSET(ulEndpoint) + USB_O_TXINTERVAL1) =
                ulNAKPollInterval;

            //
            // Set the Maximum Payload per transaction.
            //
            HWREGH(ulBase + EP_OFFSET(ulEndpoint) + USB_O_TXMAXP1) =
                ulMaxPayload;

            //
            // Set the transmit control value to zero.
            //
            ulRegister = 0;

            //
            // Allow auto setting of TxPktRdy when max packet size has been
            // loaded into the FIFO.
            //
            if(ulFlags & USB_EP_AUTO_SET)
            {
                ulRegister |= USB_TXCSRH1_AUTOSET;
            }

            //
            // Configure the DMA Mode.
            //
            if(ulFlags & USB_EP_DMA_MODE_1)
            {
                ulRegister |= USB_TXCSRH1_DMAEN | USB_TXCSRH1_DMAMOD;
            }
            else if(ulFlags & USB_EP_DMA_MODE_0)
            {
                ulRegister |= USB_TXCSRH1_DMAEN;
            }

            //
            // Write out the transmit control value.
            //
            HWREGB(ulBase + EP_OFFSET(ulEndpoint) + USB_O_TXCSRH1) =
                (unsigned char)ulRegister;
        }
        else
        {
            //
            // Set the transfer type information.
            //
            HWREGB(ulBase + EP_OFFSET(ulEndpoint) + USB_O_RXTYPE1) =
                ulRegister;

            //
            // Set the NAK timeout or polling interval.
            //
            HWREGB(ulBase + EP_OFFSET(ulEndpoint) + USB_O_RXINTERVAL1) =
                ulNAKPollInterval;

            //
            // Set the Maximum Payload per transaction.
            //
            HWREGH(ulBase + EP_OFFSET(ulEndpoint) + USB_O_RXMAXP1) =
                ulMaxPayload;

            //
            // Set the receive control value to zero.
            //
            ulRegister = 0;

            //
            // Allow auto clearing of RxPktRdy when packet of size max packet
            // has been unloaded from the FIFO.
            //
            if(ulFlags & USB_EP_AUTO_CLEAR)
            {
                ulRegister |= USB_RXCSRH1_AUTOCL;
            }

            //
            // Configure the DMA Mode.
            //
            if(ulFlags & USB_EP_DMA_MODE_1)
            {
                ulRegister |= USB_RXCSRH1_DMAEN | USB_RXCSRH1_DMAMOD;
            }
            else if(ulFlags & USB_EP_DMA_MODE_0)
            {
                ulRegister |= USB_RXCSRH1_DMAEN;
            }

            //
            // Write out the receive control value.
            //
            HWREGB(ulBase + EP_OFFSET(ulEndpoint) + USB_O_RXCSRH1) =
                (unsigned char)ulRegister;
        }
    }
}

//*****************************************************************************
//
//! Sets the configuration for an endpoint.
//!
//! \param ulBase specifies the USB module base address.
//! \param ulEndpoint is the endpoint to access.
//! \param ulMaxPacketSize is the maximum packet size for this endpoint.
//! \param ulFlags are used to configure other endpoint settings.
//!
//! This function sets the basic configuration for an endpoint in device mode.
//! Endpoint zero does not have a dynamic configuration, so this function
//! should not be called for endpoint zero.  The \e ulFlags parameter
//! determines some of the configuration while the other parameters provide the
//! rest.
//!
//! The \b USB_EP_MODE_ flags define what the type is for the given endpoint.
//!
//! - \b USB_EP_MODE_CTRL is a control endpoint.
//! - \b USB_EP_MODE_ISOC is an isochronous endpoint.
//! - \b USB_EP_MODE_BULK is a bulk endpoint.
//! - \b USB_EP_MODE_INT is an interrupt endpoint.
//!
//! The \b USB_EP_DMA_MODE_ flags determine the type of DMA access to the
//! endpoint data FIFOs.  The choice of the DMA mode depends on how the DMA
//! controller is configured and how it is being used.  See the ``Using USB
//! with the uDMA Controller'' section for more information on DMA
//! configuration.
//!
//! When configuring an IN endpoint, the \b USB_EP_AUTO_SET bit can be
//! specified to cause the automatic transmission of data on the USB bus as
//! soon as \e ulMaxPacketSize bytes of data are written into the FIFO for
//! this endpoint.  This option is commonly used with DMA as no interaction is
//! required to start the transmission of data.
//!
//! When configuring an OUT endpoint, the \b USB_EP_AUTO_REQUEST bit is
//! specified to trigger the request for more data once the FIFO has been
//! drained enough to receive \e ulMaxPacketSize more bytes of data.  Also for
//! OUT endpoints, the \b USB_EP_AUTO_CLEAR bit can be used to clear the data
//! packet ready flag automatically once the data has been read from the FIFO.
//! If this option is not used, this flag must be manually cleared via a call
//! to USBDevEndpointStatusClear().  Both of these settings can be used to
//! remove the need for extra calls when using the controller in DMA mode.
//!
//! \note This function should only be called in device mode.
//!
//! \return None.
//
//*****************************************************************************
void
USBDevEndpointConfigSet(unsigned long ulBase, unsigned long ulEndpoint,
                        unsigned long ulMaxPacketSize, unsigned long ulFlags)
{
    unsigned long ulRegister;

    //
    // Check the arguments.
    //
    ASSERT(ulBase == USB0_BASE);
    ASSERT((ulEndpoint == USB_EP_1) || (ulEndpoint == USB_EP_2) ||
           (ulEndpoint == USB_EP_3) || (ulEndpoint == USB_EP_4) ||
           (ulEndpoint == USB_EP_5) || (ulEndpoint == USB_EP_6) ||
           (ulEndpoint == USB_EP_7) || (ulEndpoint == USB_EP_8) ||
           (ulEndpoint == USB_EP_9) || (ulEndpoint == USB_EP_10) ||
           (ulEndpoint == USB_EP_11) || (ulEndpoint == USB_EP_12) ||
           (ulEndpoint == USB_EP_13) || (ulEndpoint == USB_EP_14) ||
           (ulEndpoint == USB_EP_15));

    //
    // Determine if a transmit or receive endpoint is being configured.
    //
    if(ulFlags & USB_EP_DEV_IN)
    {
        //
        // Set the maximum packet size.
        //
        HWREGH(ulBase + EP_OFFSET(ulEndpoint) + USB_O_TXMAXP1) =
            ulMaxPacketSize;

        //
        // The transmit control value is zero unless options are enabled.
        //
        ulRegister = 0;

        //
        // Allow auto setting of TxPktRdy when max packet size has been loaded
        // into the FIFO.
        //
        if(ulFlags & USB_EP_AUTO_SET)
        {
            ulRegister |= USB_TXCSRH1_AUTOSET;
        }

        //
        // Configure the DMA mode.
        //
        if(ulFlags & USB_EP_DMA_MODE_1)
        {
            ulRegister |= USB_TXCSRH1_DMAEN | USB_TXCSRH1_DMAMOD;
        }
        else if(ulFlags & USB_EP_DMA_MODE_0)
        {
            ulRegister |= USB_TXCSRH1_DMAEN;
        }

        //
        // Enable isochronous mode if requested.
        //
        if((ulFlags & USB_EP_MODE_MASK) == USB_EP_MODE_ISOC)
        {
            ulRegister |= USB_TXCSRH1_ISO;
        }

        //
        // Write the transmit control value.
        //
        HWREGB(ulBase + EP_OFFSET(ulEndpoint) + USB_O_TXCSRH1) =
            (unsigned char)ulRegister;

        //
        // Reset the Data toggle to zero.
        //
        HWREGB(ulBase + EP_OFFSET(ulEndpoint) + USB_O_TXCSRL1) =
            USB_TXCSRL1_CLRDT;
    }
    else
    {
        //
        // Set the MaxPacketSize.
        //
        HWREGH(ulBase + EP_OFFSET(ulEndpoint) + USB_O_RXMAXP1) =
            ulMaxPacketSize;

        //
        // The receive control value is zero unless options are enabled.
        //
        ulRegister = 0;

        //
        // Allow auto clearing of RxPktRdy when packet of size max packet
        // has been unloaded from the FIFO.
        //
        if(ulFlags & USB_EP_AUTO_CLEAR)
        {
            ulRegister = USB_RXCSRH1_AUTOCL;
        }

        //
        // Configure the DMA mode.
        //
        if(ulFlags & USB_EP_DMA_MODE_1)
        {
            ulRegister |= USB_RXCSRH1_DMAEN | USB_RXCSRH1_DMAMOD;
        }
        else if(ulFlags & USB_EP_DMA_MODE_0)
        {
            ulRegister |= USB_RXCSRH1_DMAEN;
        }

        //
        // Enable isochronous mode if requested.
        //
        if((ulFlags & USB_EP_MODE_MASK) == USB_EP_MODE_ISOC)
        {
            ulRegister |= USB_RXCSRH1_ISO;
        }

        //
        // Write the receive control value.
        //
        HWREGB(ulBase + EP_OFFSET(ulEndpoint) + USB_O_RXCSRH1) =
            (unsigned char)ulRegister;

        //
        // Reset the Data toggle to zero.
        //
        HWREGB(ulBase + EP_OFFSET(ulEndpoint) + USB_O_RXCSRL1) =
            USB_RXCSRL1_CLRDT;
    }
}

//*****************************************************************************
//
//! Gets the current configuration for an endpoint.
//!
//! \param ulBase specifies the USB module base address.
//! \param ulEndpoint is the endpoint to access.
//! \param pulMaxPacketSize is a pointer which is written with the maximum
//! packet size for this endpoint.
//! \param pulFlags is a pointer which is written with the current endpoint
//! settings.  On entry to the function, this pointer must contain either
//! \b USB_EP_DEV_IN or \b USB_EP_DEV_OUT to indicate whether the IN or OUT
//! endpoint is to be queried.
//!
//! This function returns the basic configuration for an endpoint in device
//! mode. The values returned in \e *pulMaxPacketSize and \e *pulFlags are
//! equivalent to the \e ulMaxPacketSize and \e ulFlags previously passed to
//! USBDevEndpointConfigSet() for this endpoint.
//!
//! \note This function should only be called in device mode.
//!
//! \return None.
//
//*****************************************************************************
void
USBDevEndpointConfigGet(unsigned long ulBase, unsigned long ulEndpoint,
                        unsigned long *pulMaxPacketSize,
                        unsigned long *pulFlags)
{
    unsigned long ulRegister;

    //
    // Check the arguments.
    //
    ASSERT(ulBase == USB0_BASE);
    ASSERT(pulMaxPacketSize && pulFlags);
    ASSERT((ulEndpoint == USB_EP_1) || (ulEndpoint == USB_EP_2) ||
           (ulEndpoint == USB_EP_3) || (ulEndpoint == USB_EP_4) ||
           (ulEndpoint == USB_EP_5) || (ulEndpoint == USB_EP_6) ||
           (ulEndpoint == USB_EP_7) || (ulEndpoint == USB_EP_8) ||
           (ulEndpoint == USB_EP_9) || (ulEndpoint == USB_EP_10) ||
           (ulEndpoint == USB_EP_11) || (ulEndpoint == USB_EP_12) ||
           (ulEndpoint == USB_EP_13) || (ulEndpoint == USB_EP_14) ||
           (ulEndpoint == USB_EP_15));

    //
    // Determine if a transmit or receive endpoint is being queried.
    //
    if(*pulFlags & USB_EP_DEV_IN)
    {
        //
        // Clear the flags other than the direction bit.
        //
        *pulFlags = USB_EP_DEV_IN;

        //
        // Get the maximum packet size.
        //
        *pulMaxPacketSize = (unsigned long)HWREGH(ulBase +
                                                  EP_OFFSET(ulEndpoint) +
                                                  USB_O_TXMAXP1);

        //
        // Get the current transmit control register value.
        //
        ulRegister = (unsigned long)HWREGB(ulBase + EP_OFFSET(ulEndpoint) +
                                           USB_O_TXCSRH1);

        //
        // Are we allowing auto setting of TxPktRdy when max packet size has
        // been loaded into the FIFO?
        //
        if(ulRegister & USB_TXCSRH1_AUTOSET)
        {
            *pulFlags |= USB_EP_AUTO_SET;
        }

        //
        // Get the DMA mode.
        //
        if(ulRegister & USB_TXCSRH1_DMAEN)
        {
            if(ulRegister & USB_TXCSRH1_DMAMOD)
            {
                *pulFlags |= USB_EP_DMA_MODE_1;
            }
            else
            {
                *pulFlags |= USB_EP_DMA_MODE_0;
            }
        }

        //
        // Are we in isochronous mode?
        //
        if(ulRegister & USB_TXCSRH1_ISO)
        {
            *pulFlags |= USB_EP_MODE_ISOC;
        }
        else
        {
            //
            // The hardware doesn't differentiate between bulk, interrupt
            // and control mode for the endpoint so we just set something
            // that isn't isochronous.  This protocol ensures that anyone
            // modifying the returned flags in preparation for a call to
            // USBDevEndpointConfigSet do not see an unexpected mode change.
            // If they decode the returned mode, however, they may be in for
            // a surprise.
            //
            *pulFlags |= USB_EP_MODE_BULK;
        }
    }
    else
    {
        //
        // Clear the flags other than the direction bit.
        //
        *pulFlags = USB_EP_DEV_OUT;

        //
        // Get the MaxPacketSize.
        //
        *pulMaxPacketSize = (unsigned long)HWREGH(ulBase +
                                                  EP_OFFSET(ulEndpoint) +
                                                  USB_O_RXMAXP1);

        //
        // Get the current receive control register value.
        //
        ulRegister = (unsigned long)HWREGB(ulBase + EP_OFFSET(ulEndpoint) +
                                           USB_O_RXCSRH1);

        //
        // Are we allowing auto clearing of RxPktRdy when packet of size max
        // packet has been unloaded from the FIFO?
        //
        if(ulRegister & USB_RXCSRH1_AUTOCL)
        {
            *pulFlags |= USB_EP_AUTO_CLEAR;
        }

        //
        // Get the DMA mode.
        //
        if(ulRegister & USB_RXCSRH1_DMAEN)
        {
            if(ulRegister & USB_RXCSRH1_DMAMOD)
            {
                *pulFlags |= USB_EP_DMA_MODE_1;
            }
            else
            {
                *pulFlags |= USB_EP_DMA_MODE_0;
            }
        }

        //
        // Are we in isochronous mode?
        //
        if(ulRegister & USB_RXCSRH1_ISO)
        {
            *pulFlags |= USB_EP_MODE_ISOC;
        }
        else
        {
            //
            // The hardware doesn't differentiate between bulk, interrupt
            // and control mode for the endpoint so we just set something
            // that isn't isochronous.  This protocol ensures that anyone
            // modifying the returned flags in preparation for a call to
            // USBDevEndpointConfigSet do not see an unexpected mode change.
            // If they decode the returned mode, however, they may be in for
            // a surprise.
            //
            *pulFlags |= USB_EP_MODE_BULK;
        }
    }
}

//*****************************************************************************
//
//! Sets the FIFO configuration for an endpoint.
//!
//! \param ulBase specifies the USB module base address.
//! \param ulEndpoint is the endpoint to access.
//! \param ulFIFOAddress is the starting address for the FIFO.
//! \param ulFIFOSize is the size of the FIFO specified by one of the
//! USB_FIFO_SZ_ values.
//! \param ulFlags specifies what information to set in the FIFO configuration.
//!
//! This function configures the starting FIFO RAM address and size of the FIFO
//! for a given endpoint.  Endpoint zero does not have a dynamically
//! configurable FIFO, so this function must not be called for endpoint zero.
//! The \e ulFIFOSize parameter must be one of the values in the
//! \b USB_FIFO_SZ_ values.  If the endpoint is going to use double buffering,
//! it should use the values with the \b _DB at the end of the value.  For
//! example, use \b USB_FIFO_SZ_16_DB to configure an endpoint to have a 16-
//! byte, double-buffered FIFO.  If a double-buffered FIFO is used, then the
//! actual size of the FIFO is twice the size indicated by the \e ulFIFOSize
//! parameter.  For example, the \b USB_FIFO_SZ_16_DB value uses 32 bytes of
//! the USB controller's FIFO memory.
//!
//! The \e ulFIFOAddress value should be a multiple of 8 bytes and directly
//! indicates the starting address in the USB controller's FIFO RAM.  For
//! example, a value of 64 indicates that the FIFO should start 64 bytes into
//! the USB controller's FIFO memory.  The \e ulFlags value specifies whether
//! the endpoint's OUT or IN FIFO should be configured.  If in host mode, use
//! \b USB_EP_HOST_OUT or \b USB_EP_HOST_IN, and if in device mode, use
//! \b USB_EP_DEV_OUT or \b USB_EP_DEV_IN.
//!
//! \return None.
//
//*****************************************************************************
void
USBFIFOConfigSet(unsigned long ulBase, unsigned long ulEndpoint,
                 unsigned long ulFIFOAddress, unsigned long ulFIFOSize,
                 unsigned long ulFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == USB0_BASE);
    ASSERT((ulEndpoint == USB_EP_1) || (ulEndpoint == USB_EP_2) ||
           (ulEndpoint == USB_EP_3) || (ulEndpoint == USB_EP_4) ||
           (ulEndpoint == USB_EP_5) || (ulEndpoint == USB_EP_6) ||
           (ulEndpoint == USB_EP_7) || (ulEndpoint == USB_EP_8) ||
           (ulEndpoint == USB_EP_9) || (ulEndpoint == USB_EP_10) ||
           (ulEndpoint == USB_EP_11) || (ulEndpoint == USB_EP_12) ||
           (ulEndpoint == USB_EP_13) || (ulEndpoint == USB_EP_14) ||
           (ulEndpoint == USB_EP_15));

    //
    // See if the transmit or receive FIFO is being configured.
    //
    if(ulFlags & (USB_EP_HOST_OUT | USB_EP_DEV_IN))
    {
        //
        // Set the transmit FIFO location and size for this endpoint.
        //
        USBIndexWrite(ulBase, ulEndpoint >> 4, USB_O_TXFIFOSZ, ulFIFOSize, 1);
        USBIndexWrite(ulBase, ulEndpoint >> 4, USB_O_TXFIFOADD,
                      ulFIFOAddress >> 3, 2);
    }
    else
    {
        //
        // Set the receive FIFO location and size for this endpoint.
        //
        USBIndexWrite(ulBase, ulEndpoint >> 4, USB_O_RXFIFOSZ, ulFIFOSize, 1);
        USBIndexWrite(ulBase, ulEndpoint >> 4, USB_O_RXFIFOADD,
                      ulFIFOAddress >> 3, 2);
    }
}

//*****************************************************************************
//
//! Returns the FIFO configuration for an endpoint.
//!
//! \param ulBase specifies the USB module base address.
//! \param ulEndpoint is the endpoint to access.
//! \param pulFIFOAddress is the starting address for the FIFO.
//! \param pulFIFOSize is the size of the FIFO as specified by one of the
//! USB_FIFO_SZ_ values.
//! \param ulFlags specifies what information to retrieve from the FIFO
//! configuration.
//!
//! This function returns the starting address and size of the FIFO for a
//! given endpoint.  Endpoint zero does not have a dynamically configurable
//! FIFO, so this function should not be called for endpoint zero.  The
//! \e ulFlags parameter specifies whether the endpoint's OUT or IN FIFO should
//! be read.  If in host mode, the \e ulFlags parameter should be
//! \b USB_EP_HOST_OUT or \b USB_EP_HOST_IN, and if in device mode, the
//! \e ulFlags parameter should be either \b USB_EP_DEV_OUT or
//! \b USB_EP_DEV_IN.
//!
//! \return None.
//
//*****************************************************************************
void
USBFIFOConfigGet(unsigned long ulBase, unsigned long ulEndpoint,
                 unsigned long *pulFIFOAddress, unsigned long *pulFIFOSize,
                 unsigned long ulFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == USB0_BASE);
    ASSERT((ulEndpoint == USB_EP_1) || (ulEndpoint == USB_EP_2) ||
           (ulEndpoint == USB_EP_3) || (ulEndpoint == USB_EP_4) ||
           (ulEndpoint == USB_EP_5) || (ulEndpoint == USB_EP_6) ||
           (ulEndpoint == USB_EP_7) || (ulEndpoint == USB_EP_8) ||
           (ulEndpoint == USB_EP_9) || (ulEndpoint == USB_EP_10) ||
           (ulEndpoint == USB_EP_11) || (ulEndpoint == USB_EP_12) ||
           (ulEndpoint == USB_EP_13) || (ulEndpoint == USB_EP_14) ||
           (ulEndpoint == USB_EP_15));

    //
    // See if the transmit or receive FIFO is being configured.
    //
    if(ulFlags & (USB_EP_HOST_OUT | USB_EP_DEV_IN))
    {
        //
        // Get the transmit FIFO location and size for this endpoint.
        //
        *pulFIFOAddress = (USBIndexRead(ulBase, ulEndpoint >> 4,
                                        (unsigned long)USB_O_TXFIFOADD,
                                        2)) << 3;
        *pulFIFOSize = USBIndexRead(ulBase, ulEndpoint >> 4,
                                    (unsigned long)USB_O_TXFIFOSZ, 1);

    }
    else
    {
        //
        // Get the receive FIFO location and size for this endpoint.
        //
        *pulFIFOAddress = (USBIndexRead(ulBase, ulEndpoint >> 4,
                                        (unsigned long)USB_O_RXFIFOADD,
                                        2)) << 3;
        *pulFIFOSize = USBIndexRead(ulBase, ulEndpoint >> 4,
                                    (unsigned long)USB_O_RXFIFOSZ, 1);
    }
}

//*****************************************************************************
//
//! Enable DMA on a given endpoint.
//!
//! \param ulBase specifies the USB module base address.
//! \param ulEndpoint is the endpoint to access.
//! \param ulFlags specifies which direction and what mode to use when enabling
//! DMA.
//!
//! This function enables DMA on a given endpoint and configures the mode
//! according to the values in the \e ulFlags parameter.  The \e ulFlags
//! parameter should have \b USB_EP_DEV_IN or \b USB_EP_DEV_OUT set.
//!
//! \return None.
//
//*****************************************************************************
void
USBEndpointDMAEnable(unsigned long ulBase, unsigned long ulEndpoint,
                     unsigned long ulFlags)
{
    //
    // See if the transmit DMA is being enabled.
    //
    if(ulFlags & USB_EP_DEV_IN)
    {
        //
        // Enable DMA on the transmit endpoint.
        //
        HWREGB(ulBase + EP_OFFSET(ulEndpoint) + USB_O_TXCSRH1) |=
            USB_TXCSRH1_DMAEN;
    }
    else
    {
        //
        // Enable DMA on the receive endpoint.
        //
        HWREGB(ulBase + EP_OFFSET(ulEndpoint) + USB_O_RXCSRH1) |=
            USB_RXCSRH1_DMAEN;
    }
}

//*****************************************************************************
//
//! Disable DMA on a given endpoint.
//!
//! \param ulBase specifies the USB module base address.
//! \param ulEndpoint is the endpoint to access.
//! \param ulFlags specifies which direction to disable.
//!
//! This function disables DMA on a given endpoint to allow non-DMA USB
//! transactions to generate interrupts normally.  The ulFlags should be
//! \b USB_EP_DEV_IN or \b USB_EP_DEV_OUT; all other bits are ignored.
//!
//! \return None.
//
//*****************************************************************************
void
USBEndpointDMADisable(unsigned long ulBase, unsigned long ulEndpoint,
                      unsigned long ulFlags)
{
    //
    // If this was a request to disable DMA on the IN portion of the endpoint
    // then handle it.
    //
    if(ulFlags & USB_EP_DEV_IN)
    {
        //
        // Just disable DMA leave the mode setting.
        //
        HWREGB(ulBase + EP_OFFSET(ulEndpoint) + USB_O_TXCSRH1) &=
               ~USB_TXCSRH1_DMAEN;
    }
    else
    {
        //
        // Just disable DMA leave the mode setting.
        //
        HWREGB(ulBase + EP_OFFSET(ulEndpoint) + USB_O_RXCSRH1) &=
               ~USB_RXCSRH1_DMAEN;
    }
}

//*****************************************************************************
//
//! Determine the number of bytes of data available in a given endpoint's FIFO.
//!
//! \param ulBase specifies the USB module base address.
//! \param ulEndpoint is the endpoint to access.
//!
//! This function returns the number of bytes of data currently available in
//! the FIFO for the given receive (OUT) endpoint.  It may be used prior to
//! calling USBEndpointDataGet() to determine the size of buffer required to
//! hold the newly-received packet.
//!
//! \return This call returns the number of bytes available in a given endpoint
//! FIFO.
//
//*****************************************************************************
unsigned long
USBEndpointDataAvail(unsigned long ulBase, unsigned long ulEndpoint)
{
    unsigned long ulRegister;

    //
    // Check the arguments.
    //
    ASSERT(ulBase == USB0_BASE);
    ASSERT((ulEndpoint == USB_EP_0) || (ulEndpoint == USB_EP_1) ||
           (ulEndpoint == USB_EP_2) || (ulEndpoint == USB_EP_3) ||
           (ulEndpoint == USB_EP_4) || (ulEndpoint == USB_EP_5) ||
           (ulEndpoint == USB_EP_6) || (ulEndpoint == USB_EP_7) ||
           (ulEndpoint == USB_EP_8) || (ulEndpoint == USB_EP_9) ||
           (ulEndpoint == USB_EP_10) || (ulEndpoint == USB_EP_11) ||
           (ulEndpoint == USB_EP_12) || (ulEndpoint == USB_EP_13) ||
           (ulEndpoint == USB_EP_14) || (ulEndpoint == USB_EP_15));

    //
    // Get the address of the receive status register to use, based on the
    // endpoint.
    //
    if(ulEndpoint == USB_EP_0)
    {
        ulRegister = USB_O_CSRL0;
    }
    else
    {
        ulRegister = USB_O_RXCSRL1 + EP_OFFSET(ulEndpoint);
    }

    //
    // Is there a packet ready in the FIFO?
    //
    if((HWREGH(ulBase + ulRegister) & USB_CSRL0_RXRDY) == 0)
    {
        return(0);
    }

    //
    // Return the byte count in the FIFO.
    //
    return(HWREGH(ulBase + USB_O_COUNT0 + ulEndpoint));
}

//*****************************************************************************
//
//! Retrieves data from the given endpoint's FIFO.
//!
//! \param ulBase specifies the USB module base address.
//! \param ulEndpoint is the endpoint to access.
//! \param pucData is a pointer to the data area used to return the data from
//! the FIFO.
//! \param pulSize is initially the size of the buffer passed into this call
//! via the \e pucData parameter.  It is set to the amount of data returned in
//! the buffer.
//!
//! This function returns the data from the FIFO for the given endpoint.
//! The \e pulSize parameter should indicate the size of the buffer passed in
//! the \e pulData parameter.  The data in the \e pulSize parameter is changed
//! to match the amount of data returned in the \e pucData parameter.  If a
//! zero-byte packet is received, this call does not return an error but
//! instead just returns a zero in the \e pulSize parameter.  The only error
//! case occurs when there is no data packet available.
//!
//! \return This call returns 0, or -1 if no packet was received.
//
//*****************************************************************************
long
USBEndpointDataGet(unsigned long ulBase, unsigned long ulEndpoint,
                   unsigned char *pucData, unsigned long *pulSize)
{
    unsigned long ulRegister, ulByteCount, ulFIFO;

    //
    // Check the arguments.
    //
    ASSERT(ulBase == USB0_BASE);
    ASSERT((ulEndpoint == USB_EP_0) || (ulEndpoint == USB_EP_1) ||
           (ulEndpoint == USB_EP_2) || (ulEndpoint == USB_EP_3) ||
           (ulEndpoint == USB_EP_4) || (ulEndpoint == USB_EP_5) ||
           (ulEndpoint == USB_EP_6) || (ulEndpoint == USB_EP_7) ||
           (ulEndpoint == USB_EP_8) || (ulEndpoint == USB_EP_9) ||
           (ulEndpoint == USB_EP_10) || (ulEndpoint == USB_EP_11) ||
           (ulEndpoint == USB_EP_12) || (ulEndpoint == USB_EP_13) ||
           (ulEndpoint == USB_EP_14) || (ulEndpoint == USB_EP_15));

    //
    // Get the address of the receive status register to use, based on the
    // endpoint.
    //
    if(ulEndpoint == USB_EP_0)
    {
        ulRegister = USB_O_CSRL0;
    }
    else
    {
        ulRegister = USB_O_RXCSRL1 + EP_OFFSET(ulEndpoint);
    }

    //
    // Don't allow reading of data if the RxPktRdy bit is not set.
    //
    if((HWREGH(ulBase + ulRegister) & USB_CSRL0_RXRDY) == 0)
    {
        //
        // Can't read the data because none is available.
        //
        *pulSize = 0;

        //
        // Return a failure since there is no data to read.
        //
        return(-1);
    }

    //
    // Get the byte count in the FIFO.
    //
    ulByteCount = HWREGH(ulBase + USB_O_COUNT0 + ulEndpoint);

    //
    // Determine how many bytes are copied.
    //
    ulByteCount = (ulByteCount < *pulSize) ? ulByteCount : *pulSize;

    //
    // Return the number of bytes we are going to read.
    //
    *pulSize = ulByteCount;

    //
    // Calculate the FIFO address.
    //
    ulFIFO = ulBase + USB_O_FIFO0 + (ulEndpoint >> 2);

    //
    // Read the data out of the FIFO.
    //
    for(; ulByteCount > 0; ulByteCount--)
    {
        //
        // Read a byte at a time from the FIFO.
        //
        *pucData++ = HWREGB(ulFIFO);
    }

    //
    // Success.
    //
    return(0);
}

//*****************************************************************************
//
//! Acknowledge that data was read from the given endpoint's FIFO in device
//! mode.
//!
//! \param ulBase specifies the USB module base address.
//! \param ulEndpoint is the endpoint to access.
//! \param bIsLastPacket indicates if this packet is the last one.
//!
//! This function acknowledges that the data was read from the endpoint's FIFO.
//! The \e bIsLastPacket parameter is set to a \b true value if this is the
//! last in a series of data packets on endpoint zero.  The \e bIsLastPacket
//! parameter is not used for endpoints other than endpoint zero.  This call
//! can be used if processing is required between reading the data and
//! acknowledging that the data has been read.
//!
//! \note This function should only be called in device mode.
//!
//! \return None.
//
//*****************************************************************************
void
USBDevEndpointDataAck(unsigned long ulBase, unsigned long ulEndpoint,
                      tBoolean bIsLastPacket)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == USB0_BASE);
    ASSERT((ulEndpoint == USB_EP_0) || (ulEndpoint == USB_EP_1) ||
           (ulEndpoint == USB_EP_2) || (ulEndpoint == USB_EP_3) ||
           (ulEndpoint == USB_EP_4) || (ulEndpoint == USB_EP_5) ||
           (ulEndpoint == USB_EP_6) || (ulEndpoint == USB_EP_7) ||
           (ulEndpoint == USB_EP_8) || (ulEndpoint == USB_EP_9) ||
           (ulEndpoint == USB_EP_10) || (ulEndpoint == USB_EP_11) ||
           (ulEndpoint == USB_EP_12) || (ulEndpoint == USB_EP_13) ||
           (ulEndpoint == USB_EP_14) || (ulEndpoint == USB_EP_15));

    //
    // Determine which endpoint is being acked.
    //
    if(ulEndpoint == USB_EP_0)
    {
        //
        // Clear RxPktRdy, and optionally DataEnd, on endpoint zero.
        //
        HWREGB(ulBase + USB_O_CSRL0) =
            USB_CSRL0_RXRDYC | (bIsLastPacket ? USB_CSRL0_DATAEND : 0);
    }
    else
    {
        //
        // Clear RxPktRdy on all other endpoints.
        //
        HWREGB(ulBase + USB_O_RXCSRL1 + EP_OFFSET(ulEndpoint)) &=
            ~(USB_RXCSRL1_RXRDY);
    }
}

//*****************************************************************************
//
//! Acknowledge that data was read from the given endpoint's FIFO in host
//! mode.
//!
//! \param ulBase specifies the USB module base address.
//! \param ulEndpoint is the endpoint to access.
//!
//! This function acknowledges that the data was read from the endpoint's FIFO.
//! This call is used if processing is required between reading the data and
//! acknowledging that the data has been read.
//!
//! \note This function should only be called in host mode.
//!
//! \return None.
//
//*****************************************************************************
void
USBHostEndpointDataAck(unsigned long ulBase, unsigned long ulEndpoint)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == USB0_BASE);
    ASSERT((ulEndpoint == USB_EP_0) || (ulEndpoint == USB_EP_1) ||
           (ulEndpoint == USB_EP_2) || (ulEndpoint == USB_EP_3) ||
           (ulEndpoint == USB_EP_4) || (ulEndpoint == USB_EP_5) ||
           (ulEndpoint == USB_EP_6) || (ulEndpoint == USB_EP_7) ||
           (ulEndpoint == USB_EP_8) || (ulEndpoint == USB_EP_9) ||
           (ulEndpoint == USB_EP_10) || (ulEndpoint == USB_EP_11) ||
           (ulEndpoint == USB_EP_12) || (ulEndpoint == USB_EP_13) ||
           (ulEndpoint == USB_EP_14) || (ulEndpoint == USB_EP_15));

    //
    // Clear RxPktRdy.
    //
    if(ulEndpoint == USB_EP_0)
    {
        HWREGB(ulBase + USB_O_CSRL0) &= ~USB_CSRL0_RXRDY;
    }
    else
    {
        HWREGB(ulBase + USB_O_RXCSRL1 + EP_OFFSET(ulEndpoint)) &=
            ~(USB_RXCSRL1_RXRDY);
    }
}

//*****************************************************************************
//
//! Puts data into the given endpoint's FIFO.
//!
//! \param ulBase specifies the USB module base address.
//! \param ulEndpoint is the endpoint to access.
//! \param pucData is a pointer to the data area used as the source for the
//! data to put into the FIFO.
//! \param ulSize is the amount of data to put into the FIFO.
//!
//! This function puts the data from the \e pucData parameter into the FIFO
//! for this endpoint.  If a packet is already pending for transmission, then
//! this call does not put any of the data into the FIFO and returns -1. Care
//! should be taken to not write more data than can fit into the FIFO
//! allocated by the call to USBFIFOConfigSet().
//!
//! \return This call returns 0 on success, or -1 to indicate that the FIFO
//! is in use and cannot be written.
//
//*****************************************************************************
long
USBEndpointDataPut(unsigned long ulBase, unsigned long ulEndpoint,
                   unsigned char *pucData, unsigned long ulSize)
{
    unsigned long ulFIFO;
    unsigned char ucTxPktRdy;

    //
    // Check the arguments.
    //
    ASSERT(ulBase == USB0_BASE);
    ASSERT((ulEndpoint == USB_EP_0) || (ulEndpoint == USB_EP_1) ||
           (ulEndpoint == USB_EP_2) || (ulEndpoint == USB_EP_3) ||
           (ulEndpoint == USB_EP_4) || (ulEndpoint == USB_EP_5) ||
           (ulEndpoint == USB_EP_6) || (ulEndpoint == USB_EP_7) ||
           (ulEndpoint == USB_EP_8) || (ulEndpoint == USB_EP_9) ||
           (ulEndpoint == USB_EP_10) || (ulEndpoint == USB_EP_11) ||
           (ulEndpoint == USB_EP_12) || (ulEndpoint == USB_EP_13) ||
           (ulEndpoint == USB_EP_14) || (ulEndpoint == USB_EP_15));

    //
    // Get the bit position of TxPktRdy based on the endpoint.
    //
    if(ulEndpoint == USB_EP_0)
    {
        ucTxPktRdy = USB_CSRL0_TXRDY;
    }
    else
    {
        ucTxPktRdy = USB_TXCSRL1_TXRDY;
    }

    //
    // Don't allow transmit of data if the TxPktRdy bit is already set.
    //
    if(HWREGB(ulBase + USB_O_CSRL0 + ulEndpoint) & ucTxPktRdy)
    {
        return(-1);
    }

    //
    // Calculate the FIFO address.
    //
    ulFIFO = ulBase + USB_O_FIFO0 + (ulEndpoint >> 2);

    //
    // Write the data to the FIFO.
    //
    for(; ulSize > 0; ulSize--)
    {
        HWREGB(ulFIFO) = *pucData++;
    }

    //
    // Success.
    //
    return(0);
}

//*****************************************************************************
//
//! Starts the transfer of data from an endpoint's FIFO.
//!
//! \param ulBase specifies the USB module base address.
//! \param ulEndpoint is the endpoint to access.
//! \param ulTransType is set to indicate what type of data is being sent.
//!
//! This function starts the transfer of data from the FIFO for a given
//! endpoint.  This function should be called if the \b USB_EP_AUTO_SET bit was
//! not enabled for the endpoint.  Setting the \e ulTransType parameter allows
//! the appropriate signaling on the USB bus for the type of transaction being
//! requested.  The \e ulTransType parameter should be one of the following:
//!
//! - \b USB_TRANS_OUT for OUT transaction on any endpoint in host mode.
//! - \b USB_TRANS_IN for IN transaction on any endpoint in device mode.
//! - \b USB_TRANS_IN_LAST for the last IN transaction on endpoint zero in a
//!   sequence of IN transactions.
//! - \b USB_TRANS_SETUP for setup transactions on endpoint zero.
//! - \b USB_TRANS_STATUS for status results on endpoint zero.
//!
//! \return This call returns 0 on success, or -1 if a transmission is already
//! in progress.
//
//*****************************************************************************
long
USBEndpointDataSend(unsigned long ulBase, unsigned long ulEndpoint,
                    unsigned long ulTransType)
{
    unsigned long ulTxPktRdy;

    //
    // Check the arguments.
    //
    ASSERT(ulBase == USB0_BASE);
    ASSERT((ulEndpoint == USB_EP_0) || (ulEndpoint == USB_EP_1) ||
           (ulEndpoint == USB_EP_2) || (ulEndpoint == USB_EP_3) ||
           (ulEndpoint == USB_EP_4) || (ulEndpoint == USB_EP_5) ||
           (ulEndpoint == USB_EP_6) || (ulEndpoint == USB_EP_7) ||
           (ulEndpoint == USB_EP_8) || (ulEndpoint == USB_EP_9) ||
           (ulEndpoint == USB_EP_10) || (ulEndpoint == USB_EP_11) ||
           (ulEndpoint == USB_EP_12) || (ulEndpoint == USB_EP_13) ||
           (ulEndpoint == USB_EP_14) || (ulEndpoint == USB_EP_15));

    //
    // Get the bit position of TxPktRdy based on the endpoint.
    //
    if(ulEndpoint == USB_EP_0)
    {
        //
        // Don't allow transmit of data if the TxPktRdy bit is already set.
        //
        if(HWREGB(ulBase + USB_O_CSRL0) & USB_CSRL0_TXRDY)
        {
            return(-1);
        }

        ulTxPktRdy = ulTransType & 0xff;
    }
    else
    {
        //
        // Don't allow transmit of data if the TxPktRdy bit is already set.
        //
        if(HWREGB(ulBase + USB_O_CSRL0 + ulEndpoint) & USB_TXCSRL1_TXRDY)
        {
            return(-1);
        }

        ulTxPktRdy = (ulTransType >> 8) & 0xff;
    }

    //
    // Set TxPktRdy in order to send the data.
    //
    HWREGB(ulBase + USB_O_CSRL0 + ulEndpoint) = ulTxPktRdy;

    //
    // Success.
    //
    return(0);
}

//*****************************************************************************
//
//! Forces a flush of an endpoint's FIFO.
//!
//! \param ulBase specifies the USB module base address.
//! \param ulEndpoint is the endpoint to access.
//! \param ulFlags specifies if the IN or OUT endpoint should be accessed.
//!
//! This function forces the USB controller to flush out the data in the FIFO.
//! The function can be called with either host or device controllers and
//! requires the \e ulFlags parameter be one of \b USB_EP_HOST_OUT,
//! \b USB_EP_HOST_IN, \b USB_EP_DEV_OUT, or \b USB_EP_DEV_IN.
//!
//! \return None.
//
//*****************************************************************************
void
USBFIFOFlush(unsigned long ulBase, unsigned long ulEndpoint,
             unsigned long ulFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == USB0_BASE);
    ASSERT((ulEndpoint == USB_EP_0) || (ulEndpoint == USB_EP_1) ||
           (ulEndpoint == USB_EP_2) || (ulEndpoint == USB_EP_3) ||
           (ulEndpoint == USB_EP_4) || (ulEndpoint == USB_EP_5) ||
           (ulEndpoint == USB_EP_6) || (ulEndpoint == USB_EP_7) ||
           (ulEndpoint == USB_EP_8) || (ulEndpoint == USB_EP_9) ||
           (ulEndpoint == USB_EP_10) || (ulEndpoint == USB_EP_11) ||
           (ulEndpoint == USB_EP_12) || (ulEndpoint == USB_EP_13) ||
           (ulEndpoint == USB_EP_14) || (ulEndpoint == USB_EP_15));

    //
    // Endpoint zero has a different register set for FIFO flushing.
    //
    if(ulEndpoint == USB_EP_0)
    {
        //
        // Nothing in the FIFO if neither of these bits are set.
        //
        if((HWREGB(ulBase + USB_O_CSRL0) &
            (USB_CSRL0_RXRDY | USB_CSRL0_TXRDY)) != 0)
        {
            //
            // Hit the Flush FIFO bit.
            //
            HWREGB(ulBase + USB_O_CSRH0) = USB_CSRH0_FLUSH;
        }
    }
    else
    {
        //
        // Only reset the IN or OUT FIFO.
        //
        if(ulFlags & (USB_EP_HOST_OUT | USB_EP_DEV_IN))
        {
            //
            // Make sure the FIFO is not empty.
            //
            if(HWREGB(ulBase + USB_O_TXCSRL1 + EP_OFFSET(ulEndpoint)) &
               USB_TXCSRL1_TXRDY)
            {
                //
                // Hit the Flush FIFO bit.
                //
                HWREGB(ulBase + USB_O_TXCSRL1 + EP_OFFSET(ulEndpoint)) |=
                    USB_TXCSRL1_FLUSH;
            }
        }
        else
        {
            //
            // Make sure that the FIFO is not empty.
            //
            if(HWREGB(ulBase + USB_O_RXCSRL1 + EP_OFFSET(ulEndpoint)) &
               USB_RXCSRL1_RXRDY)
            {
                //
                // Hit the Flush FIFO bit.
                //
                HWREGB(ulBase + USB_O_RXCSRL1 + EP_OFFSET(ulEndpoint)) |=
                    USB_RXCSRL1_FLUSH;
            }
        }
    }
}

//*****************************************************************************
//
//! Schedules a request for an IN transaction on an endpoint in host mode.
//!
//! \param ulBase specifies the USB module base address.
//! \param ulEndpoint is the endpoint to access.
//!
//! This function schedules a request for an IN transaction.  When the USB
//! device being communicated with responds with the data, the data can be
//! retrieved by calling USBEndpointDataGet() or via a DMA transfer.
//!
//! \note This function should only be called in host mode and only for IN
//! endpoints.
//!
//! \return None.
//
//*****************************************************************************
void
USBHostRequestIN(unsigned long ulBase, unsigned long ulEndpoint)
{
    unsigned long ulRegister;

    //
    // Check the arguments.
    //
    ASSERT(ulBase == USB0_BASE);
    ASSERT((ulEndpoint == USB_EP_0) || (ulEndpoint == USB_EP_1) ||
           (ulEndpoint == USB_EP_2) || (ulEndpoint == USB_EP_3) ||
           (ulEndpoint == USB_EP_4) || (ulEndpoint == USB_EP_5) ||
           (ulEndpoint == USB_EP_6) || (ulEndpoint == USB_EP_7) ||
           (ulEndpoint == USB_EP_8) || (ulEndpoint == USB_EP_9) ||
           (ulEndpoint == USB_EP_10) || (ulEndpoint == USB_EP_11) ||
           (ulEndpoint == USB_EP_12) || (ulEndpoint == USB_EP_13) ||
           (ulEndpoint == USB_EP_14) || (ulEndpoint == USB_EP_15));

    //
    // Endpoint zero uses a different offset than the other endpoints.
    //
    if(ulEndpoint == USB_EP_0)
    {
        ulRegister = USB_O_CSRL0;
    }
    else
    {
        ulRegister = USB_O_RXCSRL1 + EP_OFFSET(ulEndpoint);
    }

    //
    // Set the request for an IN transaction.
    //
    HWREGB(ulBase + ulRegister) = USB_RXCSRL1_REQPKT;
}

//*****************************************************************************
//
//! Clears a scheduled IN transaction for an endpoint in host mode.
//!
//! \param ulBase specifies the USB module base address.
//! \param ulEndpoint is the endpoint to access.
//!
//! This function clears a previously scheduled IN transaction if it is
//! still pending.  This function should be used to safely disable any
//! scheduled IN transactions if the endpoint specified by \e ulEndpoint
//! is reconfigured for communications with other devices.
//!
//! \note This function should only be called in host mode and only for IN
//! endpoints.
//!
//! \return None.
//
//*****************************************************************************
void
USBHostRequestINClear(unsigned long ulBase, unsigned long ulEndpoint)
{
    unsigned long ulRegister;

    //
    // Check the arguments.
    //
    ASSERT(ulBase == USB0_BASE);
    ASSERT((ulEndpoint == USB_EP_0) || (ulEndpoint == USB_EP_1) ||
           (ulEndpoint == USB_EP_2) || (ulEndpoint == USB_EP_3) ||
           (ulEndpoint == USB_EP_4) || (ulEndpoint == USB_EP_5) ||
           (ulEndpoint == USB_EP_6) || (ulEndpoint == USB_EP_7) ||
           (ulEndpoint == USB_EP_8) || (ulEndpoint == USB_EP_9) ||
           (ulEndpoint == USB_EP_10) || (ulEndpoint == USB_EP_11) ||
           (ulEndpoint == USB_EP_12) || (ulEndpoint == USB_EP_13) ||
           (ulEndpoint == USB_EP_14) || (ulEndpoint == USB_EP_15));

    //
    // Endpoint zero uses a different offset than the other endpoints.
    //
    if(ulEndpoint == USB_EP_0)
    {
        ulRegister = USB_O_CSRL0;
    }
    else
    {
        ulRegister = USB_O_RXCSRL1 + EP_OFFSET(ulEndpoint);
    }

    //
    // Clear the request for an IN transaction.
    //
    HWREGB(ulBase + ulRegister) &= ~USB_RXCSRL1_REQPKT;
}

//*****************************************************************************
//
//! Issues a request for a status IN transaction on endpoint zero.
//!
//! \param ulBase specifies the USB module base address.
//!
//! This function is used to cause a request for a status IN transaction from
//! a device on endpoint zero.  This function can only be used with endpoint
//! zero as that is the only control endpoint that supports this ability.  This
//! function is used to complete the last phase of a control transaction to a
//! device and an interrupt is signaled when the status packet has been
//! received.
//!
//! \return None.
//
//*****************************************************************************
void
USBHostRequestStatus(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == USB0_BASE);

    //
    // Set the request for a status IN transaction.
    //
    HWREGB(ulBase + USB_O_CSRL0) = USB_CSRL0_REQPKT | USB_CSRL0_STATUS;
}

//*****************************************************************************
//
//! Sets the functional address for the device that is connected to an
//! endpoint in host mode.
//!
//! \param ulBase specifies the USB module base address.
//! \param ulEndpoint is the endpoint to access.
//! \param ulAddr is the functional address for the controller to use for this
//! endpoint.
//! \param ulFlags determines if this is an IN or an OUT endpoint.
//!
//! This function configures the functional address for a device that is using
//! this endpoint for communication.  This \e ulAddr parameter is the address
//! of the target device that this endpoint is communicating with.  The
//! \e ulFlags parameter indicates if the IN or OUT endpoint should be set.
//!
//! \note This function should only be called in host mode.
//!
//! \return None.
//
//*****************************************************************************
void
USBHostAddrSet(unsigned long ulBase, unsigned long ulEndpoint,
               unsigned long ulAddr, unsigned long ulFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == USB0_BASE);
    ASSERT((ulEndpoint == USB_EP_0) || (ulEndpoint == USB_EP_1) ||
           (ulEndpoint == USB_EP_2) || (ulEndpoint == USB_EP_3) ||
           (ulEndpoint == USB_EP_4) || (ulEndpoint == USB_EP_5) ||
           (ulEndpoint == USB_EP_6) || (ulEndpoint == USB_EP_7) ||
           (ulEndpoint == USB_EP_8) || (ulEndpoint == USB_EP_9) ||
           (ulEndpoint == USB_EP_10) || (ulEndpoint == USB_EP_11) ||
           (ulEndpoint == USB_EP_12) || (ulEndpoint == USB_EP_13) ||
           (ulEndpoint == USB_EP_14) || (ulEndpoint == USB_EP_15));

    //
    // See if the transmit or receive address should be set.
    //
    if(ulFlags & USB_EP_HOST_OUT)
    {
        //
        // Set the transmit address.
        //
        HWREGB(ulBase + USB_O_TXFUNCADDR0 + (ulEndpoint >> 1)) = ulAddr;
    }
    else
    {
        //
        // Set the receive address.
        //
        HWREGB(ulBase + USB_O_TXFUNCADDR0 + 4 + (ulEndpoint >> 1)) = ulAddr;
    }
}

//*****************************************************************************
//
//! Gets the current functional device address for an endpoint.
//!
//! \param ulBase specifies the USB module base address.
//! \param ulEndpoint is the endpoint to access.
//! \param ulFlags determines if this is an IN or an OUT endpoint.
//!
//! This function returns the current functional address that an endpoint is
//! using to communicate with a device.  The \e ulFlags parameter determines if
//! the IN or OUT endpoint's device address is returned.
//!
//! \note This function should only be called in host mode.
//!
//! \return Returns the current function address being used by an endpoint.
//
//*****************************************************************************
unsigned long
USBHostAddrGet(unsigned long ulBase, unsigned long ulEndpoint,
               unsigned long ulFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == USB0_BASE);
    ASSERT((ulEndpoint == USB_EP_0) || (ulEndpoint == USB_EP_1) ||
           (ulEndpoint == USB_EP_2) || (ulEndpoint == USB_EP_3) ||
           (ulEndpoint == USB_EP_4) || (ulEndpoint == USB_EP_5) ||
           (ulEndpoint == USB_EP_6) || (ulEndpoint == USB_EP_7) ||
           (ulEndpoint == USB_EP_8) || (ulEndpoint == USB_EP_9) ||
           (ulEndpoint == USB_EP_10) || (ulEndpoint == USB_EP_11) ||
           (ulEndpoint == USB_EP_12) || (ulEndpoint == USB_EP_13) ||
           (ulEndpoint == USB_EP_14) || (ulEndpoint == USB_EP_15));

    //
    // See if the transmit or receive address should be returned.
    //
    if(ulFlags & USB_EP_HOST_OUT)
    {
        //
        // Return this endpoint's transmit address.
        //
        return(HWREGB(ulBase + USB_O_TXFUNCADDR0 + (ulEndpoint >> 1)));
    }
    else
    {
        //
        // Return this endpoint's receive address.
        //
        return(HWREGB(ulBase + USB_O_TXFUNCADDR0 + 4 + (ulEndpoint >> 1)));
    }
}

//*****************************************************************************
//
//! Sets the hub address for the device that is connected to an endpoint.
//!
//! \param ulBase specifies the USB module base address.
//! \param ulEndpoint is the endpoint to access.
//! \param ulAddr is the hub address and port for the device using this
//!  endpoint.  The hub address must be defined in bits 8 through 15 with the
//!  port number in bits 0 through 6.
//! \param ulFlags determines if this is an IN or an OUT endpoint.
//!
//! This function configures the hub address for a device that is using this
//! endpoint for communication.  The \e ulFlags parameter determines if the
//! device address for the IN or the OUT endpoint is configured by this call
//! and sets the speed of the downstream device.  Valid values are one of \b
//! USB_EP_HOST_OUT or \b USB_EP_HOST_IN optionally ORed with \b
//! USB_EP_SPEED_LOW.
//!
//! \note This function should only be called in host mode.
//!
//! \return None.
//
//*****************************************************************************
void
USBHostHubAddrSet(unsigned long ulBase, unsigned long ulEndpoint,
                  unsigned long ulAddr, unsigned long ulFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == USB0_BASE);
    ASSERT((ulEndpoint == USB_EP_0) || (ulEndpoint == USB_EP_1) ||
           (ulEndpoint == USB_EP_2) || (ulEndpoint == USB_EP_3) ||
           (ulEndpoint == USB_EP_4) || (ulEndpoint == USB_EP_5) ||
           (ulEndpoint == USB_EP_6) || (ulEndpoint == USB_EP_7) ||
           (ulEndpoint == USB_EP_8) || (ulEndpoint == USB_EP_9) ||
           (ulEndpoint == USB_EP_10) || (ulEndpoint == USB_EP_11) ||
           (ulEndpoint == USB_EP_12) || (ulEndpoint == USB_EP_13) ||
           (ulEndpoint == USB_EP_14) || (ulEndpoint == USB_EP_15));

    //
    // See if the hub transmit or receive address is being set.
    //
    if(ulFlags & USB_EP_HOST_OUT)
    {
        //
        // Set the hub transmit address and port number for this endpoint.
        //
        HWREGH(ulBase + USB_O_TXHUBADDR0 + (ulEndpoint >> 1)) = ulAddr;
    }
    else
    {
        //
        // Set the hub receive address and port number for this endpoint.
        //
        HWREGH(ulBase + USB_O_TXHUBADDR0 + 4 + (ulEndpoint >> 1)) = ulAddr;
    }

    //
    // Set the speed of communication for endpoint 0.  This configuration is
    // done here because it changes on a transaction-by-transaction basis for
    // EP0.  For other endpoints, this is set in USBHostEndpointConfig().
    //
    if(ulEndpoint == USB_EP_0)
    {
        if(ulFlags & USB_EP_SPEED_FULL)
        {
            HWREGB(ulBase + USB_O_TYPE0) = USB_TYPE0_SPEED_FULL;
        }
        else
        {
            HWREGB(ulBase + USB_O_TYPE0) = USB_TYPE0_SPEED_LOW;
        }
    }
}

//*****************************************************************************
//
//! Gets the current device hub address for this endpoint.
//!
//! \param ulBase specifies the USB module base address.
//! \param ulEndpoint is the endpoint to access.
//! \param ulFlags determines if this is an IN or an OUT endpoint.
//!
//! This function returns the current hub address that an endpoint is using
//! to communicate with a device.  The \e ulFlags parameter determines if the
//! device address for the IN or OUT endpoint is returned.
//!
//! \note This function should only be called in host mode.
//!
//! \return This function returns the current hub address being used by an
//! endpoint.
//
//*****************************************************************************
unsigned long
USBHostHubAddrGet(unsigned long ulBase, unsigned long ulEndpoint,
                  unsigned long ulFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == USB0_BASE);
    ASSERT((ulEndpoint == USB_EP_0) || (ulEndpoint == USB_EP_1) ||
           (ulEndpoint == USB_EP_2) || (ulEndpoint == USB_EP_3) ||
           (ulEndpoint == USB_EP_4) || (ulEndpoint == USB_EP_5) ||
           (ulEndpoint == USB_EP_6) || (ulEndpoint == USB_EP_7) ||
           (ulEndpoint == USB_EP_8) || (ulEndpoint == USB_EP_9) ||
           (ulEndpoint == USB_EP_10) || (ulEndpoint == USB_EP_11) ||
           (ulEndpoint == USB_EP_12) || (ulEndpoint == USB_EP_13) ||
           (ulEndpoint == USB_EP_14) || (ulEndpoint == USB_EP_15));

    //
    // See if the hub transmit or receive address should be returned.
    //
    if(ulFlags & USB_EP_HOST_OUT)
    {
        //
        // Return the hub transmit address for this endpoint.
        //
        return(HWREGB(ulBase + USB_O_TXHUBADDR0 + (ulEndpoint >> 1)));
    }
    else
    {
        //
        // Return the hub receive address for this endpoint.
        //
        return(HWREGB(ulBase + USB_O_TXHUBADDR0 + 4 + (ulEndpoint >> 1)));
    }
}

//*****************************************************************************
//
//! Sets the configuration for USB power fault.
//!
//! \param ulBase specifies the USB module base address.
//! \param ulFlags specifies the configuration of the power fault.
//!
//! This function controls how the USB controller uses its external power
//! control pins (USBnPFLT and USBnEPEN).  The flags specify the power
//! fault level sensitivity, the power fault action, and the power enable level
//! and source.
//!
//! One of the following can be selected as the power fault level sensitivity:
//!
//! - \b USB_HOST_PWRFLT_LOW - An external power fault is indicated by the pin
//!                            being driven low.
//! - \b USB_HOST_PWRFLT_HIGH - An external power fault is indicated by the pin
//!                             being driven high.
//!
//! One of the following can be selected as the power fault action:
//!
//! - \b USB_HOST_PWRFLT_EP_NONE - No automatic action when power fault
//!   detected.
//! - \b USB_HOST_PWRFLT_EP_TRI - Automatically tri-state the USBnEPEN pin on a
//!                               power fault.
//! - \b USB_HOST_PWRFLT_EP_LOW - Automatically drive USBnEPEN pin low on a
//!                               power fault.
//! - \b USB_HOST_PWRFLT_EP_HIGH - Automatically drive USBnEPEN pin high on a
//!                                power fault.
//!
//! One of the following can be selected as the power enable level and source:
//!
//! - \b USB_HOST_PWREN_MAN_LOW - USBnEPEN is driven low by the USB controller
//!                               when USBHostPwrEnable() is called.
//! - \b USB_HOST_PWREN_MAN_HIGH - USBnEPEN is driven high by the USB
//!                                controller when USBHostPwrEnable() is
//!                                called.
//! - \b USB_HOST_PWREN_AUTOLOW - USBnEPEN is driven low by the USB controller
//!                               automatically if USBOTGSessionRequest() has
//!                               enabled a session.
//! - \b USB_HOST_PWREN_AUTOHIGH - USBnEPEN is driven high by the USB
//!                                controller automatically if
//!                                USBOTGSessionRequest() has enabled a
//!                                session.
//!
//! On devices that support the VBUS glitch filter, the
//! \b USB_HOST_PWREN_FILTER can be added to ignore small, short drops in VBUS
//! level caused by high power consumption.  This feature is mainly used to
//! avoid causing VBUS errors caused by devices with high in-rush current.
//!
//! \note The following values have been deprecated and should no longer be
//!       used.
//! - \b USB_HOST_PWREN_LOW - Automatically drive USBnEPEN low when power is
//!                           enabled.
//! - \b USB_HOST_PWREN_HIGH - Automatically drive USBnEPEN high when power is
//!                            enabled.
//! - \b USB_HOST_PWREN_VBLOW - Automatically drive USBnEPEN low when power is
//!                             enabled.
//! - \b USB_HOST_PWREN_VBHIGH - Automatically drive USBnEPEN high when power
//!                              is enabled.
//!
//! \note This function should only be called on microcontrollers that support
//! host mode or OTG operation.
//!
//! \return None.
//
//*****************************************************************************
void
USBHostPwrConfig(unsigned long ulBase, unsigned long ulFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == USB0_BASE);
    ASSERT((ulFlags & ~(USB_HOST_PWREN_FILTER | USB_EPC_PFLTACT_M |
                        USB_EPC_PFLTAEN | USB_EPC_PFLTSEN_HIGH |
                        USB_EPC_EPEN_M)) == 0);

    //
    // If requested, enable VBUS droop detection on parts that support this
    // feature.
    //
    HWREG(ulBase + USB_O_VDC) = ulFlags >> 16;

    //
    // Set the power fault configuration as specified.  This configuration
    // does not change whether fault detection is enabled or not.
    //
    HWREGH(ulBase + USB_O_EPC) =
        (ulFlags | (HWREGH(ulBase + USB_O_EPC) &
                    ~(USB_EPC_PFLTACT_M | USB_EPC_PFLTAEN |
                      USB_EPC_PFLTSEN_HIGH | USB_EPC_EPEN_M)));
}

//*****************************************************************************
//
//! Enables power fault detection.
//!
//! \param ulBase specifies the USB module base address.
//!
//! This function enables power fault detection in the USB controller.  If the
//! USBnPFLT pin is not in use, this function should not be used.
//!
//! \note This function should only be called in host mode.
//!
//! \return None.
//
//*****************************************************************************
void
USBHostPwrFaultEnable(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == USB0_BASE);

    //
    // Enable power fault input.
    //
    HWREGH(ulBase + USB_O_EPC) |= USB_EPC_PFLTEN;
}

//*****************************************************************************
//
//! Disables power fault detection.
//!
//! \param ulBase specifies the USB module base address.
//!
//! This function disables power fault detection in the USB controller.
//!
//! \note This function should only be called in host mode.
//!
//! \return None.
//
//*****************************************************************************
void
USBHostPwrFaultDisable(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == USB0_BASE);

    //
    // Enable power fault input.
    //
    HWREGH(ulBase + USB_O_EPC) &= ~USB_EPC_PFLTEN;
}

//*****************************************************************************
//
//! Enables the external power pin.
//!
//! \param ulBase specifies the USB module base address.
//!
//! This function enables the USBnEPEN signal, which enables an external power
//! supply in host mode operation.
//!
//! \note This function should only be called in host mode.
//!
//! \return None.
//
//*****************************************************************************
void
USBHostPwrEnable(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == USB0_BASE);

    //
    // Enable the external power supply enable signal.
    //
    HWREGH(ulBase + USB_O_EPC) |= USB_EPC_EPENDE;
}

//*****************************************************************************
//
//! Disables the external power pin.
//!
//! \param ulBase specifies the USB module base address.
//!
//! This function disables the USBnEPEN signal, which disables an external
//! power supply in host mode operation.
//!
//! \note This function should only be called in host mode.
//!
//! \return None.
//
//*****************************************************************************
void
USBHostPwrDisable(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == USB0_BASE);

    //
    // Disable the external power supply enable signal.
    //
    HWREGH(ulBase + USB_O_EPC) &= ~USB_EPC_EPENDE;
}

//*****************************************************************************
//
//! Get the current frame number.
//!
//! \param ulBase specifies the USB module base address.
//!
//! This function returns the last frame number received.
//!
//! \return The last frame number received.
//
//*****************************************************************************
unsigned long
USBFrameNumberGet(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == USB0_BASE);

    //
    // Return the most recent frame number.
    //
    return(HWREGH(ulBase + USB_O_FRAME));
}

//*****************************************************************************
//
//! Starts or ends a session.
//!
//! \param ulBase specifies the USB module base address.
//! \param bStart specifies if this call starts or ends a session.
//!
//! This function is used in OTG mode to start a session request or end a
//! session.  If the \e bStart parameter is set to \b true, then this function
//! starts a session and if it is \b false it ends a session.
//!
//! \return None.
//
//*****************************************************************************
void
USBOTGSessionRequest(unsigned long ulBase, tBoolean bStart)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == USB0_BASE);

    //
    // Start or end the session as directed.
    //
    if(bStart)
    {
        HWREGB(ulBase + USB_O_DEVCTL) |= USB_DEVCTL_SESSION;
    }
    else
    {
        HWREGB(ulBase + USB_O_DEVCTL) &= ~USB_DEVCTL_SESSION;
    }
}

//*****************************************************************************
//
//! Returns the absolute FIFO address for a given endpoint.
//!
//! \param ulBase specifies the USB module base address.
//! \param ulEndpoint specifies which endpoint's FIFO address to return.
//!
//! This function returns the actual physical address of the FIFO.  This
//! address is needed when the USB is going to be used with the uDMA
//! controller and the source or destination address must be set to the
//! physical FIFO address for a given endpoint.
//!
//! \return None.
//
//*****************************************************************************
unsigned long
USBFIFOAddrGet(unsigned long ulBase, unsigned long ulEndpoint)
{
    //
    // Return the FIFO address for this endpoint.
    //
    return(ulBase + USB_O_FIFO0 + (ulEndpoint >> 2));
}

//*****************************************************************************
//
//! Returns the current operating mode of the controller.
//!
//! \param ulBase specifies the USB module base address.
//!
//! This function returns the current operating mode on USB controllers with
//! OTG or Dual mode functionality.
//!
//! For OTG controllers:
//!
//! The function returns one of the following values on OTG controllers:
//! \b USB_OTG_MODE_ASIDE_HOST, \b USB_OTG_MODE_ASIDE_DEV,
//! \b USB_OTG_MODE_BSIDE_HOST, \b USB_OTG_MODE_BSIDE_DEV,
//! \b USB_OTG_MODE_NONE.
//!
//! \b USB_OTG_MODE_ASIDE_HOST indicates that the controller is in host mode
//! on the A-side of the cable.
//!
//! \b USB_OTG_MODE_ASIDE_DEV indicates that the controller is in device mode
//! on the A-side of the cable.
//!
//! \b USB_OTG_MODE_BSIDE_HOST indicates that the controller is in host mode
//! on the B-side of the cable.
//!
//! \b USB_OTG_MODE_BSIDE_DEV indicates that the controller is in device mode
//! on the B-side of the cable.  If an OTG session request is started with no
//! cable in place, this mode is the default.
//!
//! \b USB_OTG_MODE_NONE indicates that the controller is not attempting to
//! determine its role in the system.
//!
//! For Dual Mode controllers:
//!
//! The function returns one of the following values:
//! \b USB_DUAL_MODE_HOST, \b USB_DUAL_MODE_DEVICE, or
//! \b USB_DUAL_MODE_NONE.
//!
//! \b USB_DUAL_MODE_HOST indicates that the controller is acting as a host.
//!
//! \b USB_DUAL_MODE_DEVICE indicates that the controller acting as a device.
//!
//! \b USB_DUAL_MODE_NONE indicates that the controller is not active as
//! either a host or device.
//!
//! \return Returns \b USB_OTG_MODE_ASIDE_HOST, \b USB_OTG_MODE_ASIDE_DEV,
//! \b USB_OTG_MODE_BSIDE_HOST, \b USB_OTG_MODE_BSIDE_DEV,
//! \b USB_OTG_MODE_NONE, \b USB_DUAL_MODE_HOST, \b USB_DUAL_MODE_DEVICE, or
//! \b USB_DUAL_MODE_NONE.
//
//*****************************************************************************
unsigned long
USBModeGet(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == USB0_BASE);

    //
    // Checks the current mode in the USB_O_DEVCTL and returns the current
    // mode.
    //
    // USB_OTG_MODE_ASIDE_HOST:  USB_DEVCTL_HOST | USB_DEVCTL_SESSION
    // USB_OTG_MODE_ASIDE_DEV:   USB_DEVCTL_SESSION
    // USB_OTG_MODE_BSIDE_HOST:  USB_DEVCTL_DEV | USB_DEVCTL_SESSION |
    //                           USB_DEVCTL_HOST
    // USB_OTG_MODE_BSIDE_DEV:   USB_DEVCTL_DEV | USB_DEVCTL_SESSION
    // USB_OTG_MODE_NONE:        USB_DEVCTL_DEV
    //
    return(HWREGB(ulBase + USB_O_DEVCTL) &
           (USB_DEVCTL_DEV | USB_DEVCTL_HOST | USB_DEVCTL_SESSION |
            USB_DEVCTL_VBUS_M));
}

//*****************************************************************************
//
//! Sets the DMA channel to use for a given endpoint.
//!
//! \param ulBase specifies the USB module base address.
//! \param ulEndpoint specifies which endpoint's FIFO address to return.
//! \param ulChannel specifies which DMA channel to use for which endpoint.
//!
//! This function is used to configure which DMA channel to use with a given
//! endpoint.  Receive DMA channels can only be used with receive endpoints
//! and transmit DMA channels can only be used with transmit endpoints.  As a
//! result, the 3 receive and 3 transmit DMA channels can be mapped to any
//! endpoint other than 0.  The values that should be passed into the
//! \e ulChannel value are the UDMA_CHANNEL_USBEP* values defined in udma.h.
//!
//! \note This function only has an effect on microcontrollers that have the
//! ability to change the DMA channel for an endpoint.  Calling this function
//! on other devices has no effect.
//!
//! \return None.
//!
//*****************************************************************************
void
USBEndpointDMAChannel(unsigned long ulBase, unsigned long ulEndpoint,
                      unsigned long ulChannel)
{
    unsigned long ulMask;

    //
    // Check the arguments.
    //
    ASSERT(ulBase == USB0_BASE);
    ASSERT((ulEndpoint == USB_EP_1) || (ulEndpoint == USB_EP_2) ||
           (ulEndpoint == USB_EP_3) || (ulEndpoint == USB_EP_4) ||
           (ulEndpoint == USB_EP_5) || (ulEndpoint == USB_EP_6) ||
           (ulEndpoint == USB_EP_7) || (ulEndpoint == USB_EP_8) ||
           (ulEndpoint == USB_EP_9) || (ulEndpoint == USB_EP_10) ||
           (ulEndpoint == USB_EP_11) || (ulEndpoint == USB_EP_12) ||
           (ulEndpoint == USB_EP_13) || (ulEndpoint == USB_EP_14) ||
           (ulEndpoint == USB_EP_15));
    ASSERT(ulChannel <= UDMA_CHANNEL_USBEP3TX);

    //
    // The input select mask must be shifted into the correct position
    // based on the channel.
    //
    ulMask = 0xf << (ulChannel * 4);

    //
    // Clear out the current selection for the channel.
    //
    ulMask = HWREG(ulBase + USB_O_DMASEL) & (~ulMask);

    //
    // The input select is now shifted into the correct position based on the
    // channel.
    //
    ulMask |= (USB_EP_TO_INDEX(ulEndpoint)) << (ulChannel * 4);

    //
    // Write the value out to the register.
    //
    HWREG(ulBase + USB_O_DMASEL) = ulMask;
}

//*****************************************************************************
//
//! Change the mode of the USB controller to host.
//!
//! \param ulBase specifies the USB module base address.
//!
//! This function changes the mode of the USB controller to host mode.
//!
//! \note This function should only be called on microcontrollers that support
//! OTG operation and have the DEVMODOTG bit in the USBGPCS register.
//!
//! \return None.
//
//*****************************************************************************
void
USBHostMode(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == USB0_BASE);

    //
    // Force mode in OTG parts that support forcing USB controller mode.
    // This bit is not writable in USB controllers that do not support
    // forcing the mode.  Not setting the USB_GPCS_DEVMOD bit makes this a
    // force of host mode.
    //
    HWREGB(ulBase + USB_O_GPCS) = USB_GPCS_DEVMODOTG;
}

//*****************************************************************************
//
//! Change the mode of the USB controller to device.
//!
//! \param ulBase specifies the USB module base address.
//!
//! This function changes the mode of the USB controller to device mode.
//!
//! \note This function should only be called on microcontrollers that support
//! OTG operation and have the DEVMODOTG bit in the USBGPCS register.
//!
//! \return None.
//
//*****************************************************************************
void
USBDevMode(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == USB0_BASE);

    //
    // Set the USB controller mode to device.
    //
    HWREGB(ulBase + USB_O_GPCS) = USB_GPCS_DEVMODOTG | USB_GPCS_DEVMOD;
}

//*****************************************************************************
//
//! Change the mode of the USB controller to OTG.
//!
//! \param ulBase specifies the USB module base address.
//!
//! This function changes the mode of the USB controller to OTG mode.  This
//! function is only valid on microcontrollers that have the OTG capabilities.
//!
//! \return None.
//
//*****************************************************************************
void
USBOTGMode(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == USB0_BASE);

    //
    // Disable the override of the USB controller mode when running on an OTG
    // device.
    //
    HWREGB(ulBase + USB_O_GPCS) = 0;
}

//*****************************************************************************
//
//! Powers off the USB PHY.
//!
//! \param ulBase specifies the USB module base address.
//!
//! This function powers off the USB PHY, reducing the current consuption
//! of the device.  While in the powered-off state, the USB controller is
//! unable to operate.
//!
//! \return None.
//
//*****************************************************************************
void
USBPHYPowerOff(unsigned long ulBase)
{
    //
    // Set the PWRDNPHY bit in the PHY, putting it into its low power mode.
    //
    HWREGB(ulBase + USB_O_POWER) |= USB_POWER_PWRDNPHY;
}

//*****************************************************************************
//
//! Powers on the USB PHY.
//!
//! \param ulBase specifies the USB module base address.
//!
//! This function powers on the USB PHY, enabling it return to normal
//! operation.  By default, the PHY is powered on, so this function should
//! only be called if USBPHYPowerOff() has previously been called.
//!
//! \return None.
//
//*****************************************************************************
void
USBPHYPowerOn(unsigned long ulBase)
{
    //
    // Clear the PWRDNPHY bit in the PHY, putting it into normal operating
    // mode.
    //
    HWREGB(ulBase + USB_O_POWER) &= ~USB_POWER_PWRDNPHY;
}

//*****************************************************************************
//
//! Returns the number of USB endpoint pairs on the device.
//!
//! \param ulBase specifies the USB module base address.
//!
//! This function returns the number of endpoint pairs supported by the USB
//! controller corresponding to the passed base address.  The value returned is
//! the number of IN or OUT endpoints available and does not include endpoint 0
//! (the control endpoint).  For example, if 15 is returned, there are 15 IN
//! and 15 OUT endpoints available in addition to endpoint 0.
//!
//! \return Returns the number of IN or OUT endpoints available.
//
//*****************************************************************************
unsigned long
USBNumEndpointsGet(unsigned long ulBase)
{
    if(CLASS_IS_SANDSTORM || CLASS_IS_FURY)
    {
        //
        // These part families do not support USB.
        //
        return(0);
    }
    else if(CLASS_IS_DUSTDEVIL)
    {
        //
        // DustDevil class devices support 3 endpoint pairs.
        //
        return(3);
    }
    else if(CLASS_IS_TEMPEST || CLASS_IS_FIRESTORM)
    {
        //
        // Tempest and Firestorm class devices support 15 endpoint pairs.
        //
        return(15);
    }
    else if(CLASS_IS_BLIZZARD)
    {
        //
        // Blizzard class devices support 7 endpoint pairs.
        //
        return(7);
    }
    else
    {
        //
        // The device class is not recognized so default to assuming no USB
        // support.
        //
        return(0);
    }
}

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************
