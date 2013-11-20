//*****************************************************************************
//
// usb.c - Driver for the USB Interface.
//
// Copyright (c) 2007-2013 Texas Instruments Incorporated.  All rights reserved.
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
//! \addtogroup usb_api
//! @{
//
//*****************************************************************************

#include <stdbool.h>
#include <stdint.h>
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
#define USB_INTEP_RX_SHIFT      16

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
// \param ui32Base specifies the USB module base address.
// \param ui32Endpoint is the endpoint index to target for this write.
// \param ui32IndexedReg is the indexed register to write to.
// \param ui8Value is the value to write to the register.
//
// This function is used to access the indexed registers for each endpoint.
// The only registers that are indexed are the FIFO configuration registers,
// which are not used after configuration.
//
// \return None.
//
//*****************************************************************************
static void
_USBIndexWrite(uint32_t ui32Base, uint32_t ui32Endpoint,
               uint32_t ui32IndexedReg, uint32_t ui32Value, uint32_t ui32Size)
{
    uint32_t ui32Index;

    //
    // Check the arguments.
    //
    ASSERT(ui32Base == USB0_BASE);
    ASSERT((ui32Endpoint == 0) || (ui32Endpoint == 1) || (ui32Endpoint == 2) ||
           (ui32Endpoint == 3));
    ASSERT((ui32Size == 1) || (ui32Size == 2));

    //
    // Save the old index in case it was in use.
    //
    ui32Index = HWREGB(ui32Base + USB_O_EPIDX);

    //
    // Set the index.
    //
    HWREGB(ui32Base + USB_O_EPIDX) = ui32Endpoint;

    //
    // Determine the size of the register value.
    //
    if(ui32Size == 1)
    {
        //
        // Set the value.
        //
        HWREGB(ui32Base + ui32IndexedReg) = ui32Value;
    }
    else
    {
        //
        // Set the value.
        //
        HWREGH(ui32Base + ui32IndexedReg) = ui32Value;
    }

    //
    // Restore the old index in case it was in use.
    //
    HWREGB(ui32Base + USB_O_EPIDX) = ui32Index;
}

//*****************************************************************************
//
// Reads one of the indexed registers.
//
// \param ui32Base specifies the USB module base address.
// \param ui32Endpoint is the endpoint index to target for this write.
// \param ui32IndexedReg is the indexed register to write to.
//
// This function is used internally to access the indexed registers for each
// endpoint.  The only registers that are indexed are the FIFO configuration
// registers, which are not used after configuration.
//
// \return The value in the register requested.
//
//*****************************************************************************
static uint32_t
_USBIndexRead(uint32_t ui32Base, uint32_t ui32Endpoint,
              uint32_t ui32IndexedReg, uint32_t ui32Size)
{
    uint8_t ui8Index;
    uint8_t ui8Value;

    //
    // Check the arguments.
    //
    ASSERT(ui32Base == USB0_BASE);
    ASSERT((ui32Endpoint == 0) || (ui32Endpoint == 1) || (ui32Endpoint == 2) ||
           (ui32Endpoint == 3));
    ASSERT((ui32Size == 1) || (ui32Size == 2));

    //
    // Save the old index in case it was in use.
    //
    ui8Index = HWREGB(ui32Base + USB_O_EPIDX);

    //
    // Set the index.
    //
    HWREGB(ui32Base + USB_O_EPIDX) = ui32Endpoint;

    //
    // Determine the size of the register value.
    //
    if(ui32Size == 1)
    {
        //
        // Get the value.
        //
        ui8Value = HWREGB(ui32Base + ui32IndexedReg);
    }
    else
    {
        //
        // Get the value.
        //
        ui8Value = HWREGH(ui32Base + ui32IndexedReg);
    }

    //
    // Restore the old index in case it was in use.
    //
    HWREGB(ui32Base + USB_O_EPIDX) = ui8Index;

    //
    // Return the register's value.
    //
    return(ui8Value);
}

//*****************************************************************************
//
//! Puts the USB bus in a suspended state.
//!
//! \param ui32Base specifies the USB module base address.
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
USBHostSuspend(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == USB0_BASE);

    //
    // Send the suspend signaling to the USB bus.
    //
    HWREGB(ui32Base + USB_O_POWER) |= USB_POWER_SUSPEND;
}

//*****************************************************************************
//
//! Handles the USB bus reset condition.
//!
//! \param ui32Base specifies the USB module base address.
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
USBHostReset(uint32_t ui32Base, bool bStart)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == USB0_BASE);

    //
    // Send a reset signal to the bus.
    //
    if(bStart)
    {
        HWREGB(ui32Base + USB_O_POWER) |= USB_POWER_RESET;
    }
    else
    {
        HWREGB(ui32Base + USB_O_POWER) &= ~USB_POWER_RESET;
    }
}

//*****************************************************************************
//
//! Enable or disable USB high-speed negotiation.
//!
//! \param ui32Base specifies the USB module base address.
//! \param bEnable specifies whether to enable or disable high-speed
//! negotiation.
//!
//! High-speed negotiations for both host and device mode are enabled when this
//! function is called with the \e bEnable parameter set to \b true.  In device
//! mode this causes the device to negotiate for high speed when the
//! USB controller receives a reset from the host.  In host mode, the USB host
//! enables high-speed negotiations when resetting the connected device.  If
//! \e bEnable is set to \b false the controller only operates only in
//! full-speed or low-speed.
//!
//! \b Example: Enable USB high-speed mode.
//!
//! \verbatim
//! //
//! // Enable USB high-speed mode.
//! //
//! USBHighSpeed(USB0_BASE, true);
//! \endverbatim
//!
//! \return None.
//
//*****************************************************************************
void
USBHighSpeed(uint32_t ui32Base, bool bEnable)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == USB0_BASE);

    if(bEnable)
    {
        //
        // Enable high speed mode negotiations in hosts or device mode.
        //
        HWREGB(ui32Base + USB_O_POWER) |= USB_POWER_HSENAB;
    }
    else
    {
        //
        // Enable high speed mode negotiations in hosts or device mode.
        //
        HWREGB(ui32Base + USB_O_POWER) &= ~USB_POWER_HSENAB;
    }
}

//*****************************************************************************
//
//! Handles the USB bus resume condition.
//!
//! \param ui32Base specifies the USB module base address.
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
USBHostResume(uint32_t ui32Base, bool bStart)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == USB0_BASE);

    //
    // Send a resume signal to the bus.
    //
    if(bStart)
    {
        HWREGB(ui32Base + USB_O_POWER) |= USB_POWER_RESUME;
    }
    else
    {
        HWREGB(ui32Base + USB_O_POWER) &= ~USB_POWER_RESUME;
    }
}

//*****************************************************************************
//
//! Returns the current speed of the USB device connected.
//!
//! \param ui32Base specifies the USB module base address.
//!
//! This function returns the current speed of the USB bus in host mode.
//!
//! \b Example: Get the USB connection speed.
//!
//! \verbatim
//! //
//! // Get the connection speed of the device connected to the USB controller.
//! //
//! USBHostSpeedGet(USB0_BASE);
//! \endverbatim
//!
//! \note This function must only be called in host mode.
//!
//! \return Returns one of the following: \b USB_LOW_SPEED, \b USB_FULL_SPEED,
//! \b USB_HIGH_SPEED, or \b USB_UNDEF_SPEED.
//
//*****************************************************************************
uint32_t
USBHostSpeedGet(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == USB0_BASE);

    //
    // If the Full Speed device bit is set, then this is a full speed device.
    //
    if(HWREGB(ui32Base + USB_O_POWER) & USB_POWER_HSMODE)
    {
        return(USB_HIGH_SPEED);
    }

    //
    // If the Full Speed device bit is set, then this is a full speed device.
    //
    if(HWREGB(ui32Base + USB_O_DEVCTL) & USB_DEVCTL_FSDEV)
    {
        return(USB_FULL_SPEED);
    }

    //
    // If the Low Speed device bit is set, then this is a low speed device.
    //
    if(HWREGB(ui32Base + USB_O_DEVCTL) & USB_DEVCTL_LSDEV)
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
//! Returns the current speed of the USB controller in device mode.
//!
//! \param ui32Base specifies the USB module base address.
//!
//! This function returns the operating speed of the connection to the USB host
//! controller.  This function returns either \b USB_HIGH_SPEED or
//! \b USB_FULL_SPEED to indicate the connection speed in device mode.
//!
//! \b Example: Get the USB connection speed.
//!
//! \verbatim
//! //
//! // Get the connection speed of the USB controller.
//! //
//! USBDevSpeedGet(USB0_BASE);
//! \endverbatim
//!
//! \note This function must only be called in device mode.
//!
//! \return Returns either \b USB_HIGH_SPEED or \b USB_FULL_SPEED.
//
//*****************************************************************************
uint32_t
USBDevSpeedGet(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == USB0_BASE);

    //
    // If the Full Speed device bit is set, then this is a full speed device.
    //
    if(HWREGB(ui32Base + USB_O_POWER) & USB_POWER_HSMODE)
    {
        return(USB_HIGH_SPEED);
    }

    return(USB_FULL_SPEED);
}

//*****************************************************************************
//
//! Disables control interrupts on a given USB controller.
//!
//! \param ui32Base specifies the USB module base address.
//! \param ui32Flags specifies which control interrupts to disable.
//!
//! This function disables the control interrupts for the USB controller
//! specified by the \e ui32Base parameter.  The \e ui32Flags parameter
//! specifies which control interrupts to disable.  The flags passed in the
//! \e ui32Flags parameters must be the definitions that start with
//! \b USB_INTCTRL_* and not any other \b USB_INT flags.
//!
//! \return None.
//
//*****************************************************************************
void
USBIntDisableControl(uint32_t ui32Base, uint32_t ui32Flags)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == USB0_BASE);
    ASSERT((ui32Flags & ~(USB_INTCTRL_ALL)) == 0);

    //
    // If any general interrupts were disabled then write the general interrupt
    // settings out to the hardware.
    //
    if(ui32Flags & USB_INTCTRL_STATUS)
    {
        HWREGB(ui32Base + USB_O_IE) &= ~(ui32Flags & USB_INTCTRL_STATUS);
    }

    //
    // Disable the power fault interrupt.
    //
    if(ui32Flags & USB_INTCTRL_POWER_FAULT)
    {
        HWREG(ui32Base + USB_O_EPCIM) = 0;
    }

    //
    // Disable the ID pin detect interrupt.
    //
    if(ui32Flags & USB_INTCTRL_MODE_DETECT)
    {
        HWREG(USB0_BASE + USB_O_IDVIM) = 0;
    }
}

//*****************************************************************************
//
//! Enables control interrupts on a given USB controller.
//!
//! \param ui32Base specifies the USB module base address.
//! \param ui32Flags specifies which control interrupts to enable.
//!
//! This function enables the control interrupts for the USB controller
//! specified by the \e ui32Base parameter.  The \e ui32Flags parameter
//! specifies which control interrupts to enable.  The flags passed in the
//! \e ui32Flags parameters must be the definitions that start with
//! \b USB_INTCTRL_* and not any other \b USB_INT flags.
//!
//! \return None.
//
//*****************************************************************************
void
USBIntEnableControl(uint32_t ui32Base, uint32_t ui32Flags)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == USB0_BASE);
    ASSERT((ui32Flags & (~USB_INTCTRL_ALL)) == 0);

    //
    // If any general interrupts were enabled, then write the general
    // interrupt settings out to the hardware.
    //
    if(ui32Flags & USB_INTCTRL_STATUS)
    {
        HWREGB(ui32Base + USB_O_IE) |= ui32Flags;
    }

    //
    // Enable the power fault interrupt.
    //
    if(ui32Flags & USB_INTCTRL_POWER_FAULT)
    {
        HWREG(ui32Base + USB_O_EPCIM) = USB_EPCIM_PF;
    }

    //
    // Enable the ID pin detect interrupt.
    //
    if(ui32Flags & USB_INTCTRL_MODE_DETECT)
    {
        HWREG(USB0_BASE + USB_O_IDVIM) = USB_IDVIM_ID;
    }
}

//*****************************************************************************
//
//! Returns the control interrupt status on a given USB controller.
//!
//! \param ui32Base specifies the USB module base address.
//!
//! This function reads control interrupt status for a USB controller.  This
//! call returns the current status for control interrupts only, the endpoint
//! interrupt status is retrieved by calling USBIntStatusEndpoint().  The bit
//! values returned are compared against the \b USB_INTCTRL_* values.
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
//!                           the end of a frame (Host Only)
//! - \b USB_INTCTRL_RESET - Reset signaling detected by device (Device Only)
//! - \b USB_INTCTRL_RESUME - Resume signaling detected.
//! - \b USB_INTCTRL_SUSPEND - Suspend signaling detected by device (Device
//!                            Only)
//! - \b USB_INTCTRL_MODE_DETECT - OTG cable mode detection has completed
//!                                (OTG Only)
//! - \b USB_INTCTRL_POWER_FAULT - Power Fault detected (Host Only)
//!
//! \note This call clears the source of all of the control status interrupts.
//!
//! \return Returns the status of the control interrupts for a USB controller.
//
//*****************************************************************************
uint32_t
USBIntStatusControl(uint32_t ui32Base)
{
    uint32_t ui32Status;

    //
    // Check the arguments.
    //
    ASSERT(ui32Base == USB0_BASE);

    //
    // Get the general interrupt status, these bits go into the upper 8 bits
    // of the returned value.
    //
    ui32Status = HWREGB(ui32Base + USB_O_IS);

    //
    // Add the power fault status.
    //
    if(HWREG(ui32Base + USB_O_EPCISC) & USB_EPCISC_PF)
    {
        //
        // Indicate a power fault was detected.
        //
        ui32Status |= USB_INTCTRL_POWER_FAULT;

        //
        // Clear the power fault interrupt.
        //
        HWREGB(ui32Base + USB_O_EPCISC) |= USB_EPCISC_PF;
    }

    if(HWREG(USB0_BASE + USB_O_IDVISC) & USB_IDVRIS_ID)
    {
        //
        // Indicate an id detection.
        //
        ui32Status |= USB_INTCTRL_MODE_DETECT;

        //
        // Clear the id detection interrupt.
        //
        HWREG(USB0_BASE + USB_O_IDVISC) |= USB_IDVRIS_ID;
    }

    //
    // Return the combined interrupt status.
    //
    return(ui32Status);
}

//*****************************************************************************
//
//! Disables endpoint interrupts on a given USB controller.
//!
//! \param ui32Base specifies the USB module base address.
//! \param ui32Flags specifies which endpoint interrupts to disable.
//!
//! This function disables endpoint interrupts for the USB controller specified
//! by the \e ui32Base parameter.  The \e ui32Flags parameter specifies which
//! endpoint interrupts to disable.  The flags passed in the \e ui32Flags
//! parameters must be the definitions that start with \b USB_INTEP_* and not
//! any other \b USB_INT flags.
//!
//! \return None.
//
//*****************************************************************************
void
USBIntDisableEndpoint(uint32_t ui32Base, uint32_t ui32Flags)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == USB0_BASE);

    //
    // If any transmit interrupts were disabled, then write the transmit
    // interrupt settings out to the hardware.
    //
    HWREGH(ui32Base + USB_O_TXIE) &=
        ~(ui32Flags & (USB_INTEP_HOST_OUT | USB_INTEP_DEV_IN | USB_INTEP_0));

    //
    // If any receive interrupts were disabled, then write the receive
    // interrupt settings out to the hardware.
    //
    HWREGH(ui32Base + USB_O_RXIE) &=
        ~((ui32Flags & (USB_INTEP_HOST_IN | USB_INTEP_DEV_OUT)) >>
          USB_INTEP_RX_SHIFT);
}

//*****************************************************************************
//
//! Enables endpoint interrupts on a given USB controller.
//!
//! \param ui32Base specifies the USB module base address.
//! \param ui32Flags specifies which endpoint interrupts to enable.
//!
//! This function enables endpoint interrupts for the USB controller specified
//! by the \e ui32Base parameter.  The \e ui32Flags parameter specifies which
//! endpoint interrupts to enable.  The flags passed in the \e ui32Flags
//! parameters must be the definitions that start with \b USB_INTEP_* and not
//! any other \b USB_INT flags.
//!
//! \return None.
//
//*****************************************************************************
void
USBIntEnableEndpoint(uint32_t ui32Base, uint32_t ui32Flags)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == USB0_BASE);

    //
    // Enable any transmit endpoint interrupts.
    //
    HWREGH(ui32Base + USB_O_TXIE) |=
        ui32Flags & (USB_INTEP_HOST_OUT | USB_INTEP_DEV_IN | USB_INTEP_0);

    //
    // Enable any receive endpoint interrupts.
    //
    HWREGH(ui32Base + USB_O_RXIE) |=
        ((ui32Flags & (USB_INTEP_HOST_IN | USB_INTEP_DEV_OUT)) >>
         USB_INTEP_RX_SHIFT);
}

//*****************************************************************************
//
//! Returns the endpoint interrupt status on a given USB controller.
//!
//! \param ui32Base specifies the USB module base address.
//!
//! This function reads endpoint interrupt status for a USB controller.  This
//! call returns the current status for endpoint interrupts only, the control
//! interrupt status is retrieved by calling USBIntStatusControl().  The bit
//! values returned are compared against the \b USB_INTEP_* values.
//! These values are grouped into classes for \b USB_INTEP_HOST_* and
//! \b USB_INTEP_DEV_* values to handle both host and device modes with all
//! endpoints.
//!
//! \note This call clears the source of all of the endpoint interrupts.
//!
//! \return Returns the status of the endpoint interrupts for a USB controller.
//
//*****************************************************************************
uint32_t
USBIntStatusEndpoint(uint32_t ui32Base)
{
    uint32_t ui32Status;

    //
    // Check the arguments.
    //
    ASSERT(ui32Base == USB0_BASE);

    //
    // Get the transmit interrupt status.
    //
    ui32Status = HWREGH(ui32Base + USB_O_TXIS);
    ui32Status |= (HWREGH(ui32Base + USB_O_RXIS) << USB_INTEP_RX_SHIFT);

    //
    // Return the combined interrupt status.
    //
    return(ui32Status);
}

//*****************************************************************************
//
//! Returns the interrupt number for a given USB module.
//!
//! \param ui32Base is the base address of the USB module.
//!
//! This function returns the interrupt number for the USB module with the base
//! address passed in the \e ui32Base parameter.
//!
//! \return Returns the USB interrupt number or 0 if the interrupt does not
//! exist.
//
//*****************************************************************************
static uint32_t
_USBIntNumberGet(uint32_t ui32Base)
{
    uint32_t ui32Int;

    if(CLASS_IS_BLIZZARD)
    {
        ui32Int = INT_USB0_BLIZZARD;
    }
    else if(CLASS_IS_SNOWFLAKE)
    {
        ui32Int = INT_USB0_SNOWFLAKE;
    }
    else
    {
        ui32Int = 0;
    }
    return(ui32Int);
}

//*****************************************************************************
//
//! Registers an interrupt handler for the USB controller.
//!
//! \param ui32Base specifies the USB module base address.
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
USBIntRegister(uint32_t ui32Base, void (*pfnHandler)(void))
{
    uint32_t ui32Int;

    //
    // Check the arguments.
    //
    ASSERT(ui32Base == USB0_BASE);

    ui32Int = _USBIntNumberGet(ui32Base);

    ASSERT(ui32Int != 0);

    //
    // Register the interrupt handler.
    //
    IntRegister(ui32Int, pfnHandler);

    //
    // Enable the USB interrupt.
    //
    IntEnable(ui32Int);
}

//*****************************************************************************
//
//! Unregisters an interrupt handler for the USB controller.
//!
//! \param ui32Base specifies the USB module base address.
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
USBIntUnregister(uint32_t ui32Base)
{
    uint32_t ui32Int;

    //
    // Check the arguments.
    //
    ASSERT(ui32Base == USB0_BASE);

    ui32Int = _USBIntNumberGet(ui32Base);

    ASSERT(ui32Int != 0);

    //
    // Disable the USB interrupt.
    //
    IntDisable(ui32Int);

    //
    // Unregister the interrupt handler.
    //
    IntUnregister(ui32Int);
}

//*****************************************************************************
//
//! Returns the current status of an endpoint.
//!
//! \param ui32Base specifies the USB module base address.
//! \param ui32Endpoint is the endpoint to access.
//!
//! This function returns the status of a given endpoint.  If any of these
//! status bits must be cleared, then the USBDevEndpointStatusClear() or the
//! USBHostEndpointStatusClear() functions must be called.
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
uint32_t
USBEndpointStatus(uint32_t ui32Base, uint32_t ui32Endpoint)
{
    uint32_t ui32Status;

    //
    // Check the arguments.
    //
    ASSERT(ui32Base == USB0_BASE);
    ASSERT((ui32Endpoint == USB_EP_0) || (ui32Endpoint == USB_EP_1) ||
           (ui32Endpoint == USB_EP_2) || (ui32Endpoint == USB_EP_3) ||
           (ui32Endpoint == USB_EP_4) || (ui32Endpoint == USB_EP_5) ||
           (ui32Endpoint == USB_EP_6) || (ui32Endpoint == USB_EP_7));

    //
    // Get the TX portion of the endpoint status.
    //
    ui32Status = HWREGH(ui32Base + EP_OFFSET(ui32Endpoint) + USB_O_TXCSRL1);

    //
    // Get the RX portion of the endpoint status.
    //
    ui32Status |=
        ((HWREGH(ui32Base + EP_OFFSET(ui32Endpoint) + USB_O_RXCSRL1)) <<
         USB_RX_EPSTATUS_SHIFT);

    //
    // Return the endpoint status.
    //
    return(ui32Status);
}

//*****************************************************************************
//
//! Clears the status bits in this endpoint in host mode.
//!
//! \param ui32Base specifies the USB module base address.
//! \param ui32Endpoint is the endpoint to access.
//! \param ui32Flags are the status bits that are cleared.
//!
//! This function clears the status of any bits that are passed in the
//! \e ui32Flags parameter.  The \e ui32Flags parameter can take the value
//! returned from the USBEndpointStatus() call.
//!
//! \note This function must only be called in host mode.
//!
//! \return None.
//
//*****************************************************************************
void
USBHostEndpointStatusClear(uint32_t ui32Base, uint32_t ui32Endpoint,
                           uint32_t ui32Flags)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == USB0_BASE);
    ASSERT((ui32Endpoint == USB_EP_0) || (ui32Endpoint == USB_EP_1) ||
           (ui32Endpoint == USB_EP_2) || (ui32Endpoint == USB_EP_3) ||
           (ui32Endpoint == USB_EP_4) || (ui32Endpoint == USB_EP_5) ||
           (ui32Endpoint == USB_EP_6) || (ui32Endpoint == USB_EP_7));

    //
    // Clear the specified flags for the endpoint.
    //
    if(ui32Endpoint == USB_EP_0)
    {
        HWREGB(ui32Base + USB_O_CSRL0) &= ~ui32Flags;
    }
    else
    {
        HWREGB(ui32Base + USB_O_TXCSRL1 + EP_OFFSET(ui32Endpoint)) &=
            ~ui32Flags;
        HWREGB(ui32Base + USB_O_RXCSRL1 + EP_OFFSET(ui32Endpoint)) &=
            ~(ui32Flags >> USB_RX_EPSTATUS_SHIFT);
    }
}

//*****************************************************************************
//
//! Clears the status bits in this endpoint in device mode.
//!
//! \param ui32Base specifies the USB module base address.
//! \param ui32Endpoint is the endpoint to access.
//! \param ui32Flags are the status bits that are cleared.
//!
//! This function clears the status of any bits that are passed in the
//! \e ui32Flags parameter.  The \e ui32Flags parameter can take the value
//! returned from the USBEndpointStatus() call.
//!
//! \note This function must only be called in device mode.
//!
//! \return None.
//
//*****************************************************************************
void
USBDevEndpointStatusClear(uint32_t ui32Base, uint32_t ui32Endpoint,
                          uint32_t ui32Flags)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == USB0_BASE);
    ASSERT((ui32Endpoint == USB_EP_0) || (ui32Endpoint == USB_EP_1) ||
           (ui32Endpoint == USB_EP_2) || (ui32Endpoint == USB_EP_3) ||
           (ui32Endpoint == USB_EP_4) || (ui32Endpoint == USB_EP_5) ||
           (ui32Endpoint == USB_EP_6) || (ui32Endpoint == USB_EP_7));

    //
    // If this is endpoint 0, then the bits have different meaning and map
    // into the TX memory location.
    //
    if(ui32Endpoint == USB_EP_0)
    {
        //
        // Set the Serviced RxPktRdy bit to clear the RxPktRdy.
        //
        if(ui32Flags & USB_DEV_EP0_OUT_PKTRDY)
        {
            HWREGB(ui32Base + USB_O_CSRL0) |= USB_CSRL0_RXRDYC;
        }

        //
        // Set the serviced Setup End bit to clear the SetupEnd status.
        //
        if(ui32Flags & USB_DEV_EP0_SETUP_END)
        {
            HWREGB(ui32Base + USB_O_CSRL0) |= USB_CSRL0_SETENDC;
        }

        //
        // Clear the Sent Stall status flag.
        //
        if(ui32Flags & USB_DEV_EP0_SENT_STALL)
        {
            HWREGB(ui32Base + USB_O_CSRL0) &= ~(USB_DEV_EP0_SENT_STALL);
        }
    }
    else
    {
        //
        // Clear out any TX flags that were passed in.  Only
        // USB_DEV_TX_SENT_STALL and USB_DEV_TX_UNDERRUN must be cleared.
        //
        HWREGB(ui32Base + USB_O_TXCSRL1 + EP_OFFSET(ui32Endpoint)) &=
            ~(ui32Flags & (USB_DEV_TX_SENT_STALL | USB_DEV_TX_UNDERRUN));

        //
        // Clear out valid RX flags that were passed in.  Only
        // USB_DEV_RX_SENT_STALL, USB_DEV_RX_DATA_ERROR, and USB_DEV_RX_OVERRUN
        // must be cleared.
        //
        HWREGB(ui32Base + USB_O_RXCSRL1 + EP_OFFSET(ui32Endpoint)) &=
            ~((ui32Flags & (USB_DEV_RX_SENT_STALL | USB_DEV_RX_DATA_ERROR |
                            USB_DEV_RX_OVERRUN)) >> USB_RX_EPSTATUS_SHIFT);
    }
}

//*****************************************************************************
//
//! Sets the value data toggle on an endpoint in host mode.
//!
//! \param ui32Base specifies the USB module base address.
//! \param ui32Endpoint specifies the endpoint to reset the data toggle.
//! \param bDataToggle specifies whether to set the state to DATA0 or DATA1.
//! \param ui32Flags specifies whether to set the IN or OUT endpoint.
//!
//! This function is used to force the state of the data toggle in host mode.
//! If the value passed in the \e bDataToggle parameter is \b false, then the
//! data toggle is set to the DATA0 state, and if it is \b true it is set to
//! the DATA1 state.  The \e ui32Flags parameter can be \b USB_EP_HOST_IN or
//! \b USB_EP_HOST_OUT to access the desired portion of this endpoint.  The
//! \e ui32Flags parameter is ignored for endpoint zero.
//!
//! \note This function must only be called in host mode.
//!
//! \return None.
//
//*****************************************************************************
void
USBHostEndpointDataToggle(uint32_t ui32Base, uint32_t ui32Endpoint,
                          bool bDataToggle, uint32_t ui32Flags)
{
    uint32_t ui32DataToggle;

    //
    // Check the arguments.
    //
    ASSERT(ui32Base == USB0_BASE);
    ASSERT((ui32Endpoint == USB_EP_0) || (ui32Endpoint == USB_EP_1) ||
           (ui32Endpoint == USB_EP_2) || (ui32Endpoint == USB_EP_3) ||
           (ui32Endpoint == USB_EP_4) || (ui32Endpoint == USB_EP_5) ||
           (ui32Endpoint == USB_EP_6) || (ui32Endpoint == USB_EP_7));

    //
    // The data toggle defaults to DATA0.
    //
    ui32DataToggle = 0;

    //
    // See if the data toggle must be set to DATA1.
    //
    if(bDataToggle)
    {
        //
        // Select the data toggle bit based on the endpoint.
        //
        if(ui32Endpoint == USB_EP_0)
        {
            ui32DataToggle = USB_CSRH0_DT;
        }
        else if(ui32Flags == USB_EP_HOST_IN)
        {
            ui32DataToggle = USB_RXCSRH1_DT;
        }
        else
        {
            ui32DataToggle = USB_TXCSRH1_DT;
        }
    }

    //
    // Set the data toggle based on the endpoint.
    //
    if(ui32Endpoint == USB_EP_0)
    {
        //
        // Set the write enable and the bit value for endpoint zero.
        //
        HWREGB(ui32Base + USB_O_CSRH0) =
            ((HWREGB(ui32Base + USB_O_CSRH0) &
              ~(USB_CSRH0_DTWE | USB_CSRH0_DT)) |
             (ui32DataToggle | USB_CSRH0_DTWE));
    }
    else if(ui32Flags == USB_EP_HOST_IN)
    {
        //
        // Set the Write enable and the bit value for an IN endpoint.
        //
        HWREGB(ui32Base + USB_O_RXCSRH1 + EP_OFFSET(ui32Endpoint)) =
            ((HWREGB(ui32Base + USB_O_RXCSRH1 + EP_OFFSET(ui32Endpoint)) &
              ~(USB_RXCSRH1_DTWE | USB_RXCSRH1_DT)) |
             (ui32DataToggle | USB_RXCSRH1_DTWE));
    }
    else
    {
        //
        // Set the Write enable and the bit value for an OUT endpoint.
        //
        HWREGB(ui32Base + USB_O_TXCSRH1 + EP_OFFSET(ui32Endpoint)) =
            ((HWREGB(ui32Base + USB_O_TXCSRH1 + EP_OFFSET(ui32Endpoint)) &
              ~(USB_TXCSRH1_DTWE | USB_TXCSRH1_DT)) |
             (ui32DataToggle | USB_TXCSRH1_DTWE));
    }
}

//*****************************************************************************
//
//! Sets the data toggle on an endpoint to zero.
//!
//! \param ui32Base specifies the USB module base address.
//! \param ui32Endpoint specifies the endpoint to reset the data toggle.
//! \param ui32Flags specifies whether to access the IN or OUT endpoint.
//!
//! This function causes the USB controller to clear the data toggle for an
//! endpoint.  This call is not valid for endpoint zero and can be made with
//! host or device controllers.
//!
//! The \e ui32Flags parameter must be one of \b USB_EP_HOST_OUT,
//! \b USB_EP_HOST_IN, \b USB_EP_DEV_OUT, or \b USB_EP_DEV_IN.
//!
//! \return None.
//
//*****************************************************************************
void
USBEndpointDataToggleClear(uint32_t ui32Base, uint32_t ui32Endpoint,
                           uint32_t ui32Flags)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == USB0_BASE);
    ASSERT((ui32Endpoint == USB_EP_1) || (ui32Endpoint == USB_EP_2) ||
           (ui32Endpoint == USB_EP_3) || (ui32Endpoint == USB_EP_4) ||
           (ui32Endpoint == USB_EP_5) || (ui32Endpoint == USB_EP_6) ||
           (ui32Endpoint == USB_EP_7));

    //
    // See if the transmit or receive data toggle must be cleared.
    //
    if(ui32Flags & (USB_EP_HOST_OUT | USB_EP_DEV_IN))
    {
        HWREGB(ui32Base + USB_O_TXCSRL1 + EP_OFFSET(ui32Endpoint)) |=
            USB_TXCSRL1_CLRDT;
    }
    else
    {
        HWREGB(ui32Base + USB_O_RXCSRL1 + EP_OFFSET(ui32Endpoint)) |=
            USB_RXCSRL1_CLRDT;
    }
}

//*****************************************************************************
//
//! Enables or disables ping tokens for an endpoint using high-speed control
//! transfers in host mode.
//!
//! \param ui32Base specifies the USB module base address.
//! \param ui32Endpoint specifies the endpoint to enable/disable ping tokens.
//! \param bEnable specifies whether enable or disable ping tokens.
//!
//! This function configures the USB controller to either send or not send ping
//! tokens during the data and status phase of high speed control transfers.
//! The only supported value for \e ui32Endpoint is \b USB_EP_0 because all
//! control transfers are handled using this endpoint.  If the \e bEnable is
//! \b true then ping tokens are enabled, if \b false then ping tokens are
//! disabled.  This must be used if the controller must support
//! communications with devices that do not support ping tokens in high speed
//! mode.
//!
//! \b Example: Disable ping transactions in host mode on endpoint 0.
//!
//! \verbatim
//! //
//! // Disable ping transaction on endpoint 0.
//! //
//! USBHostEndpointPing(USB0_BASE, USB_EP_0, false);
//! \endverbatim
//!
//! \note This function must only be called in host mode.
//!
//! \return None.
//
//*****************************************************************************
void
USBHostEndpointPing(uint32_t ui32Base, uint32_t ui32Endpoint, bool bEnable)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == USB0_BASE);
    ASSERT((ui32Endpoint == USB_EP_0));

    //
    // Handle the endpoint 0 case separately.
    //
    if(bEnable)
    {
        HWREGB(USB0_BASE + USB_O_CSRH0) &= ~USB_CSRH0_DISPING;
    }
    else
    {
        HWREGB(USB0_BASE + USB_O_CSRH0) |= USB_CSRH0_DISPING;
    }
}

//*****************************************************************************
//
//! Stalls the specified endpoint in device mode.
//!
//! \param ui32Base specifies the USB module base address.
//! \param ui32Endpoint specifies the endpoint to stall.
//! \param ui32Flags specifies whether to stall the IN or OUT endpoint.
//!
//! This function causes the endpoint number passed in to go into a stall
//! condition.  If the \e ui32Flags parameter is \b USB_EP_DEV_IN, then the
//! stall is issued on the IN portion of this endpoint.  If the \e ui32Flags
//! parameter is \b USB_EP_DEV_OUT, then the stall is issued on the OUT portion
//! of this endpoint.
//!
//! \note This function must only be called in device mode.
//!
//! \return None.
//
//*****************************************************************************
void
USBDevEndpointStall(uint32_t ui32Base, uint32_t ui32Endpoint,
                    uint32_t ui32Flags)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == USB0_BASE);
    ASSERT((ui32Flags & ~(USB_EP_DEV_IN | USB_EP_DEV_OUT)) == 0);
    ASSERT((ui32Endpoint == USB_EP_0) || (ui32Endpoint == USB_EP_1) ||
           (ui32Endpoint == USB_EP_2) || (ui32Endpoint == USB_EP_3) ||
           (ui32Endpoint == USB_EP_4) || (ui32Endpoint == USB_EP_5) ||
           (ui32Endpoint == USB_EP_6) || (ui32Endpoint == USB_EP_7));

    //
    // Determine how to stall this endpoint.
    //
    if(ui32Endpoint == USB_EP_0)
    {
        //
        // Perform a stall on endpoint zero.
        //
        HWREGB(ui32Base + USB_O_CSRL0) |= USB_CSRL0_STALL | USB_CSRL0_RXRDYC;
    }
    else if(ui32Flags == USB_EP_DEV_IN)
    {
        //
        // Perform a stall on an IN endpoint.
        //
        HWREGB(ui32Base + USB_O_TXCSRL1 + EP_OFFSET(ui32Endpoint)) |=
            USB_TXCSRL1_STALL;
    }
    else
    {
        //
        // Perform a stall on an OUT endpoint.
        //
        HWREGB(ui32Base + USB_O_RXCSRL1 + EP_OFFSET(ui32Endpoint)) |=
            USB_RXCSRL1_STALL;
    }
}

//*****************************************************************************
//
//! Clears the stall condition on the specified endpoint in device mode.
//!
//! \param ui32Base specifies the USB module base address.
//! \param ui32Endpoint specifies which endpoint to remove the stall condition.
//! \param ui32Flags specifies whether to remove the stall condition from the
//! IN or the OUT portion of this endpoint.
//!
//! This function causes the endpoint number passed in to exit the stall
//! condition.  If the \e ui32Flags parameter is \b USB_EP_DEV_IN, then the
//! stall is cleared on the IN portion of this endpoint.  If the \e ui32Flags
//! parameter is \b USB_EP_DEV_OUT, then the stall is cleared on the OUT
//! portion of this endpoint.
//!
//! \note This function must only be called in device mode.
//!
//! \return None.
//
//*****************************************************************************
void
USBDevEndpointStallClear(uint32_t ui32Base, uint32_t ui32Endpoint,
                         uint32_t ui32Flags)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == USB0_BASE);
    ASSERT((ui32Endpoint == USB_EP_0) || (ui32Endpoint == USB_EP_1) ||
           (ui32Endpoint == USB_EP_2) || (ui32Endpoint == USB_EP_3) ||
           (ui32Endpoint == USB_EP_4) || (ui32Endpoint == USB_EP_5) ||
           (ui32Endpoint == USB_EP_6) || (ui32Endpoint == USB_EP_7));
    ASSERT((ui32Flags & ~(USB_EP_DEV_IN | USB_EP_DEV_OUT)) == 0);

    //
    // Determine how to clear the stall on this endpoint.
    //
    if(ui32Endpoint == USB_EP_0)
    {
        //
        // Clear the stall on endpoint zero.
        //
        HWREGB(ui32Base + USB_O_CSRL0) &= ~USB_CSRL0_STALLED;
    }
    else if(ui32Flags == USB_EP_DEV_IN)
    {
        //
        // Clear the stall on an IN endpoint.
        //
        HWREGB(ui32Base + USB_O_TXCSRL1 + EP_OFFSET(ui32Endpoint)) &=
            ~(USB_TXCSRL1_STALL | USB_TXCSRL1_STALLED);

        //
        // Reset the data toggle.
        //
        HWREGB(ui32Base + USB_O_TXCSRL1 + EP_OFFSET(ui32Endpoint)) |=
            USB_TXCSRL1_CLRDT;
    }
    else
    {
        //
        // Clear the stall on an OUT endpoint.
        //
        HWREGB(ui32Base + USB_O_RXCSRL1 + EP_OFFSET(ui32Endpoint)) &=
            ~(USB_RXCSRL1_STALL | USB_RXCSRL1_STALLED);

        //
        // Reset the data toggle.
        //
        HWREGB(ui32Base + USB_O_RXCSRL1 + EP_OFFSET(ui32Endpoint)) |=
            USB_RXCSRL1_CLRDT;
    }
}

//*****************************************************************************
//
//! Connects the USB controller to the bus in device mode.
//!
//! \param ui32Base specifies the USB module base address.
//!
//! This function causes the soft connect feature of the USB controller to
//! be enabled.  Call USBDevDisconnect() to remove the USB device from the bus.
//!
//! \note This function must only be called in device mode.
//!
//! \return None.
//
//*****************************************************************************
void
USBDevConnect(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == USB0_BASE);

    //
    // Enable connection to the USB bus.
    //
    HWREGB(ui32Base + USB_O_POWER) |= USB_POWER_SOFTCONN;
}

//*****************************************************************************
//
//! Removes the USB controller from the bus in device mode.
//!
//! \param ui32Base specifies the USB module base address.
//!
//! This function causes the soft connect feature of the USB controller to
//! remove the device from the USB bus.  A call to USBDevConnect() is needed to
//! reconnect to the bus.
//!
//! \note This function must only be called in device mode.
//!
//! \return None.
//
//*****************************************************************************
void
USBDevDisconnect(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == USB0_BASE);

    //
    // Disable connection to the USB bus.
    //
    HWREGB(ui32Base + USB_O_POWER) &= (~USB_POWER_SOFTCONN);
}

//*****************************************************************************
//
//! Sets the address in device mode.
//!
//! \param ui32Base specifies the USB module base address.
//! \param ui32Address is the address to use for a device.
//!
//! This function configures the device address on the USB bus.  This address
//! was likely received via a SET ADDRESS command from the host controller.
//!
//! \note This function must only be called in device mode.
//!
//! \return None.
//
//*****************************************************************************
void
USBDevAddrSet(uint32_t ui32Base, uint32_t ui32Address)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == USB0_BASE);

    //
    // Set the function address in the correct location.
    //
    HWREGB(ui32Base + USB_O_FADDR) = (uint8_t)ui32Address;
}

//*****************************************************************************
//
//! Returns the current device address in device mode.
//!
//! \param ui32Base specifies the USB module base address.
//!
//! This function returns the current device address.  This address was set
//! by a call to USBDevAddrSet().
//!
//! \note This function must only be called in device mode.
//!
//! \return The current device address.
//
//*****************************************************************************
uint32_t
USBDevAddrGet(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == USB0_BASE);

    //
    // Return the function address.
    //
    return(HWREGB(ui32Base + USB_O_FADDR));
}

//*****************************************************************************
//
//! Sets the base configuration for a host endpoint.
//!
//! \param ui32Base specifies the USB module base address.
//! \param ui32Endpoint is the endpoint to access.
//! \param ui32MaxPayload is the maximum payload for this endpoint.
//! \param ui32NAKPollInterval is the either the NAK timeout limit or the
//! polling interval, depending on the type of endpoint.
//! \param ui32TargetEndpoint is the endpoint that the host endpoint is
//! targeting.
//! \param ui32Flags are used to configure other endpoint settings.
//!
//! This function sets the basic configuration for the transmit or receive
//! portion of an endpoint in host mode.  The \e ui32Flags parameter determines
//! some of the configuration while the other parameters provide the rest.  The
//! \e ui32Flags parameter determines whether this is an IN endpoint
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
//! The \e ui32NAKPollInterval parameter has different meanings based on the
//! \b USB_EP_MODE value and whether or not this call is being made for
//! endpoint zero or another endpoint.  For endpoint zero or any Bulk
//! endpoints, this value always indicates the number of frames to allow a
//! device to NAK before considering it a timeout.  If this endpoint is an
//! isochronous or interrupt endpoint, this value is the polling interval for
//! this endpoint.
//!
//! For interrupt endpoints, the polling interval is the number of frames
//! between interrupt IN requests to an endpoint and has a range of 1 to 255.
//! For isochronous endpoints this value represents a polling interval of
//! 2 ^ (\e ui32NAKPollInterval - 1) frames.  When used as a NAK timeout, the
//! \e ui32NAKPollInterval value specifies 2 ^ (\e ui32NAKPollInterval - 1)
//! frames before issuing a time out.
//!
//! There are two special time out values that can be specified when setting
//! the \e ui32NAKPollInterval value.  The first is \b MAX_NAK_LIMIT, which is
//! the maximum value that can be passed in this variable.  The other is
//! \b DISABLE_NAK_LIMIT, which indicates that there is no limit on the
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
//! as soon as the number of bytes specified by \e ui32MaxPayload has been
//! written into the OUT FIFO for this endpoint.
//!
//! When configuring the IN portion of an endpoint, the \b USB_EP_AUTO_REQUEST
//! bit can be specified to trigger the request for more data once the FIFO has
//! been drained enough to fit \e ui32MaxPayload bytes.  The
//! \b USB_EP_AUTO_CLEAR bit can be used to clear the data packet ready flag
//! automatically once the data has been read from the FIFO.  If this option is
//! not used, this flag must be manually cleared via a call to
//! USBDevEndpointStatusClear() or USBHostEndpointStatusClear().
//!
//! \note This function must only be called in host mode.
//!
//! \return None.
//
//*****************************************************************************
void
USBHostEndpointConfig(uint32_t ui32Base, uint32_t ui32Endpoint,
                      uint32_t ui32MaxPayload, uint32_t ui32NAKPollInterval,
                      uint32_t ui32TargetEndpoint, uint32_t ui32Flags)
{
    uint32_t ui32Register;

    //
    // Check the arguments.
    //
    ASSERT(ui32Base == USB0_BASE);
    ASSERT((ui32Endpoint == USB_EP_0) || (ui32Endpoint == USB_EP_1) ||
           (ui32Endpoint == USB_EP_2) || (ui32Endpoint == USB_EP_3) ||
           (ui32Endpoint == USB_EP_4) || (ui32Endpoint == USB_EP_5) ||
           (ui32Endpoint == USB_EP_6) || (ui32Endpoint == USB_EP_7));
    ASSERT(ui32NAKPollInterval <= MAX_NAK_LIMIT);

    //
    // Endpoint zero is configured differently than the other endpoints, so see
    // if this is endpoint zero.
    //
    if(ui32Endpoint == USB_EP_0)
    {
        //
        // Set the NAK timeout.
        //
        HWREGB(ui32Base + USB_O_NAKLMT) = ui32NAKPollInterval;

        //
        // Set the transfer type information.
        //
        //
        // Set the speed of this endpoint.
        //
        if(ui32Flags & USB_EP_SPEED_HIGH)
        {
            HWREGB(ui32Base + USB_O_TYPE0) = USB_TYPE0_SPEED_HIGH;
        }
        else if(ui32Flags & USB_EP_SPEED_FULL)
        {
            HWREGB(ui32Base + USB_O_TYPE0) = USB_TYPE0_SPEED_FULL;
        }
        else
        {
            HWREGB(ui32Base + USB_O_TYPE0) = USB_TYPE0_SPEED_LOW;
        }
    }
    else
    {
        //
        // Start with the target endpoint.
        //
        ui32Register = ui32TargetEndpoint;

        //
        // Set the speed for the device using this endpoint.
        //
        if(ui32Flags & USB_EP_SPEED_HIGH)
        {
            ui32Register |= USB_TXTYPE1_SPEED_HIGH;
        }
        else if(ui32Flags & USB_EP_SPEED_FULL)
        {
            ui32Register |= USB_TXTYPE1_SPEED_FULL;
        }
        else
        {
            ui32Register |= USB_TXTYPE1_SPEED_LOW;
        }

        //
        // Set the protocol for the device using this endpoint.
        //
        switch(ui32Flags & USB_EP_MODE_MASK)
        {
            //
            // The bulk protocol is being used.
            //
            case USB_EP_MODE_BULK:
            {
                ui32Register |= USB_TXTYPE1_PROTO_BULK;
                break;
            }

            //
            // The isochronous protocol is being used.
            //
            case USB_EP_MODE_ISOC:
            {
                ui32Register |= USB_TXTYPE1_PROTO_ISOC;
                break;
            }

            //
            // The interrupt protocol is being used.
            //
            case USB_EP_MODE_INT:
            {
                ui32Register |= USB_TXTYPE1_PROTO_INT;
                break;
            }

            //
            // The control protocol is being used.
            //
            case USB_EP_MODE_CTRL:
            {
                ui32Register |= USB_TXTYPE1_PROTO_CTRL;
                break;
            }
        }

        //
        // See if the transmit or receive endpoint is being configured.
        //
        if(ui32Flags & USB_EP_HOST_OUT)
        {
            //
            // Set the transfer type information.
            //
            HWREGB(ui32Base + EP_OFFSET(ui32Endpoint) + USB_O_TXTYPE1) =
                ui32Register;

            //
            // Set the NAK timeout or polling interval.
            //
            HWREGB(ui32Base + EP_OFFSET(ui32Endpoint) + USB_O_TXINTERVAL1) =
                ui32NAKPollInterval;

            //
            // Set the Maximum Payload per transaction.
            //
            HWREGH(ui32Base + EP_OFFSET(ui32Endpoint) + USB_O_TXMAXP1) =
                ui32MaxPayload;

            //
            // Set the transmit control value to zero.
            //
            ui32Register = 0;

            //
            // Allow auto setting of TxPktRdy when max packet size has been
            // loaded into the FIFO.
            //
            if(ui32Flags & USB_EP_AUTO_SET)
            {
                ui32Register |= USB_TXCSRH1_AUTOSET;
            }

            //
            // Configure the DMA Mode.
            //
            if(ui32Flags & USB_EP_DMA_MODE_1)
            {
                ui32Register |= USB_TXCSRH1_DMAEN | USB_TXCSRH1_DMAMOD;
            }
            else if(ui32Flags & USB_EP_DMA_MODE_0)
            {
                ui32Register |= USB_TXCSRH1_DMAEN;
            }

            //
            // Write out the transmit control value.
            //
            HWREGB(ui32Base + EP_OFFSET(ui32Endpoint) + USB_O_TXCSRH1) =
                (uint8_t)ui32Register;
        }
        else
        {
            //
            // Set the transfer type information.
            //
            HWREGB(ui32Base + EP_OFFSET(ui32Endpoint) + USB_O_RXTYPE1) =
                ui32Register;

            //
            // Set the NAK timeout or polling interval.
            //
            HWREGB(ui32Base + EP_OFFSET(ui32Endpoint) + USB_O_RXINTERVAL1) =
                ui32NAKPollInterval;

            //
            // Set the Maximum Payload per transaction.
            //
            HWREGH(ui32Base + EP_OFFSET(ui32Endpoint) + USB_O_RXMAXP1) =
                ui32MaxPayload;

            //
            // Set the receive control value to zero.
            //
            ui32Register = 0;

            //
            // Allow auto clearing of RxPktRdy when packet of size max packet
            // has been unloaded from the FIFO.
            //
            if(ui32Flags & USB_EP_AUTO_CLEAR)
            {
                ui32Register |= USB_RXCSRH1_AUTOCL;
            }

            //
            // Allow auto generation of DMA requests.
            //
            if(ui32Flags & USB_EP_AUTO_REQUEST)
            {
                ui32Register |= USB_RXCSRH1_AUTORQ;
            }

            //
            // Configure the DMA Mode.
            //
            if(ui32Flags & USB_EP_DMA_MODE_1)
            {
                ui32Register |= USB_RXCSRH1_DMAEN | USB_RXCSRH1_DMAMOD;
            }
            else if(ui32Flags & USB_EP_DMA_MODE_0)
            {
                ui32Register |= USB_RXCSRH1_DMAEN;
            }

            //
            // Write out the receive control value.
            //
            HWREGB(ui32Base + EP_OFFSET(ui32Endpoint) + USB_O_RXCSRH1) =
                (uint8_t)ui32Register;
        }
    }
}

//*****************************************************************************
//
//! Changes the speed of the connection for a host endpoint.
//!
//! \param ui32Base specifies the USB module base address.
//! \param ui32Endpoint is the endpoint to access.
//! \param ui32Flags are used to configure other endpoint settings.
//!
//! This function sets the USB speed for an IN or OUT endpoint in host mode.
//! The \e ui32Flags parameter specifies the speed using one of the following
//! values: \b USB_EP_SPEED_LOW, \b USB_EP_SPEED_FULL, or \b USB_EP_SPEED_HIGH.
//! The \e ui32Flags parameter also specifies which direction is set by
//! adding the logical OR in either \b USB_EP_HOST_IN or \b USB_EP_HOST_OUT.
//! All other flags are ignored.  This is typically only used for endpoint 0,
//! but could be used with other endpoints as well.
//!
//! \b Example: Set host transactions on endpoint 0 to full speed..
//!
//! \verbatim
//! //
//! // Set host endpoint 0 transactions to full speed.
//! //
//! USBHostEndpointSpeed(USB0_BASE, USB_EP_0, USB_EP_SPEED_FULL);
//! \endverbatim
//!
//! \note This function must only be called in host mode.
//!
//! \return None.
//
//*****************************************************************************
void
USBHostEndpointSpeed(uint32_t ui32Base, uint32_t ui32Endpoint,
                     uint32_t ui32Flags)
{
    uint32_t ui32Reg;
    uint32_t ui32Speed;

    //
    // Check the arguments.
    //
    ASSERT(ui32Base == USB0_BASE);
    ASSERT((ui32Endpoint == USB_EP_0) || (ui32Endpoint == USB_EP_1) ||
           (ui32Endpoint == USB_EP_2) || (ui32Endpoint == USB_EP_3) ||
           (ui32Endpoint == USB_EP_4) || (ui32Endpoint == USB_EP_5) ||
           (ui32Endpoint == USB_EP_6) || (ui32Endpoint == USB_EP_7));

    //
    // Create the register speed value.
    //
    if(ui32Flags & USB_EP_SPEED_HIGH)
    {
        ui32Speed = USB_TYPE0_SPEED_HIGH;
    }
    else if(ui32Flags & USB_EP_SPEED_FULL)
    {
        ui32Speed = USB_TYPE0_SPEED_FULL;
    }
    else
    {
        ui32Speed = USB_TYPE0_SPEED_LOW;
    }

    //
    // Endpoint 0 is handled differently as it is bi-directional.
    //
    if(ui32Endpoint == USB_EP_0)
    {
        HWREGB(ui32Base + USB_O_TYPE0) = ui32Speed;
    }
    else if(ui32Flags & USB_EP_HOST_OUT)
    {
        //
        // Clear the current speed and set the new speed.
        //
        ui32Reg = (HWREGH(ui32Base + EP_OFFSET(ui32Endpoint) + USB_O_TXTYPE1) &
                   ~(USB_TXTYPE1_SPEED_M));
        ui32Reg |= ui32Speed;

        HWREGH(ui32Base + EP_OFFSET(ui32Endpoint) + USB_O_TXTYPE1) |= ui32Reg;
    }
    else
    {
        //
        // Clear the current speed and set the new speed.
        //
        ui32Reg = (HWREGH(ui32Base + EP_OFFSET(ui32Endpoint) + USB_O_RXTYPE1) &
                   ~(USB_RXTYPE1_SPEED_M));
        ui32Reg |= ui32Speed;

        HWREGH(ui32Base + EP_OFFSET(ui32Endpoint) + USB_O_RXTYPE1) |= ui32Reg;
    }
}

//*****************************************************************************
//
//! Sets the configuration for an endpoint.
//!
//! \param ui32Base specifies the USB module base address.
//! \param ui32Endpoint is the endpoint to access.
//! \param ui32MaxPacketSize is the maximum packet size for this endpoint.
//! \param ui32Flags are used to configure other endpoint settings.
//!
//! This function sets the basic configuration for an endpoint in device mode.
//! Endpoint zero does not have a dynamic configuration, so this function
//! must not be called for endpoint zero.  The \e ui32Flags parameter
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
//! soon as \e ui32MaxPacketSize bytes of data are written into the FIFO for
//! this endpoint.  This option is commonly used with DMA as no interaction is
//! required to start the transmission of data.
//!
//! When configuring an OUT endpoint, the \b USB_EP_AUTO_REQUEST bit is
//! specified to trigger the request for more data once the FIFO has been
//! drained enough to receive \e ui32MaxPacketSize more bytes of data.  Also
//! for OUT endpoints, the \b USB_EP_AUTO_CLEAR bit can be used to clear the
//! data packet ready flag automatically once the data has been read from the
//! FIFO.  If this option is not used, this flag must be manually cleared via a
//! call to USBDevEndpointStatusClear().  Both of these settings can be used to
//! remove the need for extra calls when using the controller in DMA mode.
//!
//! \note This function must only be called in device mode.
//!
//! \return None.
//
//*****************************************************************************
void
USBDevEndpointConfigSet(uint32_t ui32Base, uint32_t ui32Endpoint,
                        uint32_t ui32MaxPacketSize, uint32_t ui32Flags)
{
    uint32_t ui32Register;

    //
    // Check the arguments.
    //
    ASSERT(ui32Base == USB0_BASE);
    ASSERT((ui32Endpoint == USB_EP_1) || (ui32Endpoint == USB_EP_2) ||
           (ui32Endpoint == USB_EP_3) || (ui32Endpoint == USB_EP_4) ||
           (ui32Endpoint == USB_EP_5) || (ui32Endpoint == USB_EP_6) ||
           (ui32Endpoint == USB_EP_7));

    //
    // Determine if a transmit or receive endpoint is being configured.
    //
    if(ui32Flags & USB_EP_DEV_IN)
    {
        //
        // Set the maximum packet size.
        //
        HWREGH(ui32Base + EP_OFFSET(ui32Endpoint) + USB_O_TXMAXP1) =
            ui32MaxPacketSize;

        //
        // The transmit control value is zero unless options are enabled.
        //
        ui32Register = 0;

        //
        // Allow auto setting of TxPktRdy when max packet size has been loaded
        // into the FIFO.
        //
        if(ui32Flags & USB_EP_AUTO_SET)
        {
            ui32Register |= USB_TXCSRH1_AUTOSET;
        }

        //
        // Configure the DMA mode.
        //
        if(ui32Flags & USB_EP_DMA_MODE_1)
        {
            ui32Register |= USB_TXCSRH1_DMAEN | USB_TXCSRH1_DMAMOD;
        }
        else if(ui32Flags & USB_EP_DMA_MODE_0)
        {
            ui32Register |= USB_TXCSRH1_DMAEN;
        }

        //
        // Enable isochronous mode if requested.
        //
        if((ui32Flags & USB_EP_MODE_MASK) == USB_EP_MODE_ISOC)
        {
            ui32Register |= USB_TXCSRH1_ISO;
        }

        //
        // Write the transmit control value.
        //
        HWREGB(ui32Base + EP_OFFSET(ui32Endpoint) + USB_O_TXCSRH1) =
            (uint8_t)ui32Register;

        //
        // Reset the Data toggle to zero.
        //
        HWREGB(ui32Base + EP_OFFSET(ui32Endpoint) + USB_O_TXCSRL1) =
            USB_TXCSRL1_CLRDT;
    }
    else
    {
        //
        // Set the MaxPacketSize.
        //
        HWREGH(ui32Base + EP_OFFSET(ui32Endpoint) + USB_O_RXMAXP1) =
            ui32MaxPacketSize;

        //
        // The receive control value is zero unless options are enabled.
        //
        ui32Register = 0;

        //
        // Allow auto clearing of RxPktRdy when packet of size max packet
        // has been unloaded from the FIFO.
        //
        if(ui32Flags & USB_EP_AUTO_CLEAR)
        {
            ui32Register = USB_RXCSRH1_AUTOCL;
        }

        //
        // Configure the DMA mode.
        //
        if(ui32Flags & USB_EP_DMA_MODE_1)
        {
            ui32Register |= USB_RXCSRH1_DMAEN | USB_RXCSRH1_DMAMOD;
        }
        else if(ui32Flags & USB_EP_DMA_MODE_0)
        {
            ui32Register |= USB_RXCSRH1_DMAEN;
        }

        //
        // If requested, disable NYET responses for high-speed bulk and
        // interrupt endpoints.
        //
        if(ui32Flags & USB_EP_DIS_NYET)
        {
            ui32Register |= USB_RXCSRH1_DISNYET;
        }

        //
        // Enable isochronous mode if requested.
        //
        if((ui32Flags & USB_EP_MODE_MASK) == USB_EP_MODE_ISOC)
        {
            ui32Register |= USB_RXCSRH1_ISO;
        }

        //
        // Write the receive control value.
        //
        HWREGB(ui32Base + EP_OFFSET(ui32Endpoint) + USB_O_RXCSRH1) =
            (uint8_t)ui32Register;

        //
        // Reset the Data toggle to zero.
        //
        HWREGB(ui32Base + EP_OFFSET(ui32Endpoint) + USB_O_RXCSRL1) =
            USB_RXCSRL1_CLRDT;
    }
}

//*****************************************************************************
//
//! Gets the current configuration for an endpoint.
//!
//! \param ui32Base specifies the USB module base address.
//! \param ui32Endpoint is the endpoint to access.
//! \param pui32MaxPacketSize is a pointer which is written with the maximum
//! packet size for this endpoint.
//! \param pui32Flags is a pointer which is written with the current endpoint
//! settings.  On entry to the function, this pointer must contain either
//! \b USB_EP_DEV_IN or \b USB_EP_DEV_OUT to indicate whether the IN or OUT
//! endpoint is to be queried.
//!
//! This function returns the basic configuration for an endpoint in device
//! mode.  The values returned in \e *pui32MaxPacketSize and \e *pui32Flags are
//! equivalent to the \e ui32MaxPacketSize and \e ui32Flags previously passed
//! to USBDevEndpointConfigSet() for this endpoint.
//!
//! \note This function must only be called in device mode.
//!
//! \return None.
//
//*****************************************************************************
void
USBDevEndpointConfigGet(uint32_t ui32Base, uint32_t ui32Endpoint,
                        uint32_t *pui32MaxPacketSize, uint32_t *pui32Flags)
{
    uint32_t ui32Register;

    //
    // Check the arguments.
    //
    ASSERT(ui32Base == USB0_BASE);
    ASSERT(pui32MaxPacketSize && pui32Flags);
    ASSERT((ui32Endpoint == USB_EP_1) || (ui32Endpoint == USB_EP_2) ||
           (ui32Endpoint == USB_EP_3) || (ui32Endpoint == USB_EP_4) ||
           (ui32Endpoint == USB_EP_5) || (ui32Endpoint == USB_EP_6) ||
           (ui32Endpoint == USB_EP_7));

    //
    // Determine if a transmit or receive endpoint is being queried.
    //
    if(*pui32Flags & USB_EP_DEV_IN)
    {
        //
        // Clear the flags other than the direction bit.
        //
        *pui32Flags = USB_EP_DEV_IN;

        //
        // Get the maximum packet size.
        //
        *pui32MaxPacketSize = (uint32_t)HWREGH(ui32Base +
                                               EP_OFFSET(ui32Endpoint) +
                                               USB_O_TXMAXP1);

        //
        // Get the current transmit control register value.
        //
        ui32Register = (uint32_t)HWREGB(ui32Base + EP_OFFSET(ui32Endpoint) +
                                        USB_O_TXCSRH1);

        //
        // Are we allowing auto setting of TxPktRdy when max packet size has
        // been loaded into the FIFO?
        //
        if(ui32Register & USB_TXCSRH1_AUTOSET)
        {
            *pui32Flags |= USB_EP_AUTO_SET;
        }

        //
        // Get the DMA mode.
        //
        if(ui32Register & USB_TXCSRH1_DMAEN)
        {
            if(ui32Register & USB_TXCSRH1_DMAMOD)
            {
                *pui32Flags |= USB_EP_DMA_MODE_1;
            }
            else
            {
                *pui32Flags |= USB_EP_DMA_MODE_0;
            }
        }

        //
        // Are we in isochronous mode?
        //
        if(ui32Register & USB_TXCSRH1_ISO)
        {
            *pui32Flags |= USB_EP_MODE_ISOC;
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
            *pui32Flags |= USB_EP_MODE_BULK;
        }
    }
    else
    {
        //
        // Clear the flags other than the direction bit.
        //
        *pui32Flags = USB_EP_DEV_OUT;

        //
        // Get the MaxPacketSize.
        //
        *pui32MaxPacketSize = (uint32_t)HWREGH(ui32Base +
                                               EP_OFFSET(ui32Endpoint) +
                                               USB_O_RXMAXP1);

        //
        // Get the current receive control register value.
        //
        ui32Register = (uint32_t)HWREGB(ui32Base + EP_OFFSET(ui32Endpoint) +
                                        USB_O_RXCSRH1);

        //
        // Are we allowing auto clearing of RxPktRdy when packet of size max
        // packet has been unloaded from the FIFO?
        //
        if(ui32Register & USB_RXCSRH1_AUTOCL)
        {
            *pui32Flags |= USB_EP_AUTO_CLEAR;
        }

        //
        // Get the DMA mode.
        //
        if(ui32Register & USB_RXCSRH1_DMAEN)
        {
            if(ui32Register & USB_RXCSRH1_DMAMOD)
            {
                *pui32Flags |= USB_EP_DMA_MODE_1;
            }
            else
            {
                *pui32Flags |= USB_EP_DMA_MODE_0;
            }
        }

        //
        // Are we in isochronous mode?
        //
        if(ui32Register & USB_RXCSRH1_ISO)
        {
            *pui32Flags |= USB_EP_MODE_ISOC;
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
            *pui32Flags |= USB_EP_MODE_BULK;
        }
    }
}

//*****************************************************************************
//
//! Sets the FIFO configuration for an endpoint.
//!
//! \param ui32Base specifies the USB module base address.
//! \param ui32Endpoint is the endpoint to access.
//! \param ui32FIFOAddress is the starting address for the FIFO.
//! \param ui32FIFOSize is the size of the FIFO specified by one of the
//! USB_FIFO_SZ_ values.
//! \param ui32Flags specifies what information to set in the FIFO
//! configuration.
//!
//! This function configures the starting FIFO RAM address and size of the FIFO
//! for a given endpoint.  Endpoint zero does not have a dynamically
//! configurable FIFO, so this function must not be called for endpoint zero.
//! The \e ui32FIFOSize parameter must be one of the values in the
//! \b USB_FIFO_SZ_ values.
//!
//! The \e ui32FIFOAddress value must be a multiple of 8 bytes and directly
//! indicates the starting address in the USB controller's FIFO RAM.  For
//! example, a value of 64 indicates that the FIFO starts 64 bytes into
//! the USB controller's FIFO memory.  The \e ui32Flags value specifies whether
//! the endpoint's OUT or IN FIFO must be configured.  If in host mode, use
//! \b USB_EP_HOST_OUT or \b USB_EP_HOST_IN, and if in device mode, use
//! \b USB_EP_DEV_OUT or \b USB_EP_DEV_IN.
//!
//! \return None.
//
//*****************************************************************************
void
USBFIFOConfigSet(uint32_t ui32Base, uint32_t ui32Endpoint,
                 uint32_t ui32FIFOAddress, uint32_t ui32FIFOSize,
                 uint32_t ui32Flags)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == USB0_BASE);
    ASSERT((ui32Endpoint == USB_EP_1) || (ui32Endpoint == USB_EP_2) ||
           (ui32Endpoint == USB_EP_3) || (ui32Endpoint == USB_EP_4) ||
           (ui32Endpoint == USB_EP_5) || (ui32Endpoint == USB_EP_6) ||
           (ui32Endpoint == USB_EP_7));

    //
    // See if the transmit or receive FIFO is being configured.
    //
    if(ui32Flags & (USB_EP_HOST_OUT | USB_EP_DEV_IN))
    {
        //
        // Set the transmit FIFO location and size for this endpoint.
        //
        _USBIndexWrite(ui32Base, ui32Endpoint >> 4, USB_O_TXFIFOSZ,
                       ui32FIFOSize, 1);
        _USBIndexWrite(ui32Base, ui32Endpoint >> 4, USB_O_TXFIFOADD,
                       ui32FIFOAddress >> 3, 2);
    }
    else
    {
        //
        // Set the receive FIFO location and size for this endpoint.
        //
        _USBIndexWrite(ui32Base, ui32Endpoint >> 4, USB_O_RXFIFOSZ,
                       ui32FIFOSize, 1);
        _USBIndexWrite(ui32Base, ui32Endpoint >> 4, USB_O_RXFIFOADD,
                       ui32FIFOAddress >> 3, 2);
    }
}

//*****************************************************************************
//
//! Returns the FIFO configuration for an endpoint.
//!
//! \param ui32Base specifies the USB module base address.
//! \param ui32Endpoint is the endpoint to access.
//! \param pui32FIFOAddress is the starting address for the FIFO.
//! \param pui32FIFOSize is the size of the FIFO as specified by one of the
//! USB_FIFO_SZ_ values.
//! \param ui32Flags specifies what information to retrieve from the FIFO
//! configuration.
//!
//! This function returns the starting address and size of the FIFO for a
//! given endpoint.  Endpoint zero does not have a dynamically configurable
//! FIFO, so this function must not be called for endpoint zero.  The
//! \e ui32Flags parameter specifies whether the endpoint's OUT or IN FIFO must
//! be read.  If in host mode, the \e ui32Flags parameter must be
//! \b USB_EP_HOST_OUT or \b USB_EP_HOST_IN, and if in device mode, the
//! \e ui32Flags parameter must be either \b USB_EP_DEV_OUT or
//! \b USB_EP_DEV_IN.
//!
//! \return None.
//
//*****************************************************************************
void
USBFIFOConfigGet(uint32_t ui32Base, uint32_t ui32Endpoint,
                 uint32_t *pui32FIFOAddress, uint32_t *pui32FIFOSize,
                 uint32_t ui32Flags)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == USB0_BASE);
    ASSERT((ui32Endpoint == USB_EP_1) || (ui32Endpoint == USB_EP_2) ||
           (ui32Endpoint == USB_EP_3) || (ui32Endpoint == USB_EP_4) ||
           (ui32Endpoint == USB_EP_5) || (ui32Endpoint == USB_EP_6) ||
           (ui32Endpoint == USB_EP_7));

    //
    // See if the transmit or receive FIFO is being configured.
    //
    if(ui32Flags & (USB_EP_HOST_OUT | USB_EP_DEV_IN))
    {
        //
        // Get the transmit FIFO location and size for this endpoint.
        //
        *pui32FIFOAddress = (_USBIndexRead(ui32Base, ui32Endpoint >> 4,
                                           (uint32_t)USB_O_TXFIFOADD,
                                           2)) << 3;
        *pui32FIFOSize = _USBIndexRead(ui32Base, ui32Endpoint >> 4,
                                       (uint32_t)USB_O_TXFIFOSZ, 1);
    }
    else
    {
        //
        // Get the receive FIFO location and size for this endpoint.
        //
        *pui32FIFOAddress = (_USBIndexRead(ui32Base, ui32Endpoint >> 4,
                                           (uint32_t)USB_O_RXFIFOADD,
                                           2)) << 3;
        *pui32FIFOSize = _USBIndexRead(ui32Base, ui32Endpoint >> 4,
                                       (uint32_t)USB_O_RXFIFOSZ, 1);
    }
}

//*****************************************************************************
//
//! Configure the DMA settings for an endpoint.
//!
//! \param ui32Base specifies the USB module base address.
//! \param ui32Endpoint is the endpoint to access.
//! \param ui32Config specifies the configuration options for an endpoint.
//!
//! This function configures the DMA settings for a given endpoint without
//! changing other options that may already be configured.  In order for the
//! DMA transfer to be enabled, the USBEndpointDMAEnable() function must be
//! called before starting the DMA transfer.  The configuration
//! options are passed in the \e ui32Config parameter and can have the values
//! described below.
//!
//! One of the following values to specify direction:
//! - \b USB_EP_HOST_OUT or \b USB_EP_DEV_IN - This setting is used with
//!   DMA transfers from memory to the USB controller.
//! - \b USB_EP_HOST_IN or \b USB_EP_DEV_OUT - This setting is used with
//!   DMA transfers from the USB controller to memory.
//!
//! One of the following values:
//! - \b USB_EP_DMA_MODE_0(default) - This setting is typically used for
//!   transfers that do not span multiple packets or when interrupts are
//!   required for each packet.
//! - \b USB_EP_DMA_MODE_1 - This setting is typically used for
//!   transfers that span multiple packets and do not require interrupts
//!   between packets.
//!
//! Values only used with \b USB_EP_HOST_OUT or \b USB_EP_DEV_IN:
//! - \b USB_EP_AUTO_SET - This setting is used to allow transmit DMA transfers
//!   to automatically be sent when a full packet is loaded into a FIFO.
//!   This is needed with \b USB_EP_DMA_MODE_1 to ensure that packets go
//!   out when the FIFO becomes full and the DMA has more data to send.
//!
//! Values only used with \b USB_EP_HOST_IN or \b USB_EP_DEV_OUT:
//! - \b USB_EP_AUTO_CLEAR - This setting is used to allow receive DMA
//!   transfers to automatically be acknowledged as they are received.  This is
//!   needed with \b USB_EP_DMA_MODE_1 to ensure that packets continue to
//!   be received and acknowledged when the FIFO is emptied by the DMA
//!   transfer.
//!
//! Values only used with \b USB_EP_HOST_IN:
//! - \b USB_EP_AUTO_REQUEST - This setting is used to allow receive DMA
//!   transfers to automatically request a new IN transaction when the
//!   previous transfer has emptied the FIFO.  This is typically used in
//!   conjunction with \b USB_EP_AUTO_CLEAR so that receive DMA transfers
//!   can continue without interrupting the main processor.
//!
//! \b Example: Set endpoint 1 receive endpoint to automatically acknowledge
//! request and automatically generate a new IN request in host mode.
//!
//! \verbatim
//! //
//! // Configure endpoint 1 for receiving multiple packets using DMA.
//! //
//! USBEndpointDMAConfigSet(USB0_BASE, USB_EP_1, USB_EP_HOST_IN |
//!                                              USB_EP_DMA_MODE_1 |
//!                                              USB_EP_AUTO_CLEAR |
//!                                              USB_EP_AUTO_REQUEST);
//! \endverbatim
//!
//! \b Example: Set endpoint 2 transmit endpoint to automatically send each
//! packet in host mode when spanning multiple packets.
//!
//! \verbatim
//! //
//! // Configure endpoint 1 for transmitting multiple packets using DMA.
//! //
//! USBEndpointDMAConfigSet(USB0_BASE, USB_EP_2, USB_EP_HOST_OUT |
//!                                              USB_EP_DMA_MODE_1 |
//!                                              USB_EP_AUTO_SET);
//! \endverbatim
//!
//! \return None.
//
//*****************************************************************************
void
USBEndpointDMAConfigSet(uint32_t ui32Base, uint32_t ui32Endpoint,
                        uint32_t ui32Config)
{
    uint32_t ui32NewConfig;

    if(ui32Config & USB_EP_HOST_OUT)
    {
        //
        // Clear mode and DMA enable.
        //
        ui32NewConfig =
            (HWREGB(ui32Base + EP_OFFSET(ui32Endpoint) + USB_O_TXCSRH1) &
             ~(USB_TXCSRH1_DMAMOD | USB_TXCSRH1_AUTOSET));

        if(ui32Config & USB_EP_DMA_MODE_1)
        {
            ui32NewConfig |= USB_TXCSRH1_DMAMOD;
        }

        if(ui32Config & USB_EP_AUTO_SET)
        {
            ui32NewConfig |= USB_TXCSRH1_AUTOSET;
        }

        HWREGB(ui32Base + EP_OFFSET(ui32Endpoint) + USB_O_TXCSRH1) =
            ui32NewConfig;
    }
    else
    {
        ui32NewConfig =
            (HWREGB(ui32Base + EP_OFFSET(ui32Endpoint) + USB_O_RXCSRH1) &
             ~(USB_RXCSRH1_AUTORQ | USB_RXCSRH1_AUTOCL | USB_RXCSRH1_DMAMOD));

        if(ui32Config & USB_EP_DMA_MODE_1)
        {
            ui32NewConfig |= USB_RXCSRH1_DMAMOD;
        }

        if(ui32Config & USB_EP_AUTO_CLEAR)
        {
            ui32NewConfig |= USB_RXCSRH1_AUTOCL;
        }
        if(ui32Config & USB_EP_AUTO_REQUEST)
        {
            ui32NewConfig |= USB_RXCSRH1_AUTORQ;
        }
        HWREGB(ui32Base + EP_OFFSET(ui32Endpoint) + USB_O_RXCSRH1) =
            ui32NewConfig;
    }
}

//*****************************************************************************
//
//! Enable DMA on a given endpoint.
//!
//! \param ui32Base specifies the USB module base address.
//! \param ui32Endpoint is the endpoint to access.
//! \param ui32Flags specifies which direction and what mode to use when
//! enabling DMA.
//!
//! This function enables DMA on a given endpoint and configures the mode
//! according to the values in the \e ui32Flags parameter.  The \e ui32Flags
//! parameter must have \b USB_EP_DEV_IN or \b USB_EP_DEV_OUT set.  Once this
//! function is called the only DMA or error interrupts are generated by the
//! USB controller.
//!
//! \note If this function is called when an endpoint is configured in DMA
//! mode 0 the USB controller does not generate an interrupt.
//!
//! \return None.
//
//*****************************************************************************
void
USBEndpointDMAEnable(uint32_t ui32Base, uint32_t ui32Endpoint,
                     uint32_t ui32Flags)
{
    //
    // See if the transmit DMA is being enabled.
    //
    if(ui32Flags & USB_EP_DEV_IN)
    {
        //
        // Enable DMA on the transmit endpoint.
        //
        HWREGB(ui32Base + EP_OFFSET(ui32Endpoint) + USB_O_TXCSRH1) |=
            USB_TXCSRH1_DMAEN;
    }
    else
    {
        //
        // Enable DMA on the receive endpoint.
        //
        HWREGB(ui32Base + EP_OFFSET(ui32Endpoint) + USB_O_RXCSRH1) |=
            USB_RXCSRH1_DMAEN;
    }
}

//*****************************************************************************
//
//! Disable DMA on a given endpoint.
//!
//! \param ui32Base specifies the USB module base address.
//! \param ui32Endpoint is the endpoint to access.
//! \param ui32Flags specifies which direction to disable.
//!
//! This function disables DMA on a given endpoint to allow non-DMA USB
//! transactions to generate interrupts normally.  The \e ui32Flags parameter
//! must be \b USB_EP_DEV_IN or \b USB_EP_DEV_OUT; all other bits are ignored.
//!
//! \return None.
//
//*****************************************************************************
void
USBEndpointDMADisable(uint32_t ui32Base, uint32_t ui32Endpoint,
                      uint32_t ui32Flags)
{
    //
    // If this was a request to disable DMA on the IN portion of the endpoint
    // then handle it.
    //
    if(ui32Flags & USB_EP_DEV_IN)
    {
        //
        // Just disable DMA leave the mode setting.
        //
        HWREGB(ui32Base + EP_OFFSET(ui32Endpoint) + USB_O_TXCSRH1) &=
            ~USB_TXCSRH1_DMAEN;
    }
    else
    {
        //
        // Just disable DMA leave the mode setting.
        //
        HWREGB(ui32Base + EP_OFFSET(ui32Endpoint) + USB_O_RXCSRH1) &=
            ~USB_RXCSRH1_DMAEN;
    }
}

//*****************************************************************************
//
//! Determine the number of bytes of data available in a given endpoint's FIFO.
//!
//! \param ui32Base specifies the USB module base address.
//! \param ui32Endpoint is the endpoint to access.
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
uint32_t
USBEndpointDataAvail(uint32_t ui32Base, uint32_t ui32Endpoint)
{
    uint32_t ui32Register;

    //
    // Check the arguments.
    //
    ASSERT(ui32Base == USB0_BASE);
    ASSERT((ui32Endpoint == USB_EP_0) || (ui32Endpoint == USB_EP_1) ||
           (ui32Endpoint == USB_EP_2) || (ui32Endpoint == USB_EP_3) ||
           (ui32Endpoint == USB_EP_4) || (ui32Endpoint == USB_EP_5) ||
           (ui32Endpoint == USB_EP_6) || (ui32Endpoint == USB_EP_7));

    //
    // Get the address of the receive status register to use, based on the
    // endpoint.
    //
    if(ui32Endpoint == USB_EP_0)
    {
        ui32Register = USB_O_CSRL0;
    }
    else
    {
        ui32Register = USB_O_RXCSRL1 + EP_OFFSET(ui32Endpoint);
    }

    //
    // Is there a packet ready in the FIFO?
    //
    if((HWREGH(ui32Base + ui32Register) & USB_CSRL0_RXRDY) == 0)
    {
        return(0);
    }

    //
    // Return the byte count in the FIFO.
    //
    return(HWREGH(ui32Base + USB_O_COUNT0 + ui32Endpoint));
}

//*****************************************************************************
//
//! Retrieves data from the given endpoint's FIFO.
//!
//! \param ui32Base specifies the USB module base address.
//! \param ui32Endpoint is the endpoint to access.
//! \param pui8Data is a pointer to the data area used to return the data from
//! the FIFO.
//! \param pui32Size is initially the size of the buffer passed into this call
//! via the \e pui8Data parameter.  It is set to the amount of data returned in
//! the buffer.
//!
//! This function returns the data from the FIFO for the given endpoint.
//! The \e pui32Size parameter indicates the size of the buffer passed in
//! the \e pui32Data parameter.  The data in the \e pui32Size parameter is
//! changed to match the amount of data returned in the \e pui8Data parameter.
//! If a zero-byte packet is received, this call does not return an error but
//! instead just returns a zero in the \e pui32Size parameter.  The only error
//! case occurs when there is no data packet available.
//!
//! \return This call returns 0, or -1 if no packet was received.
//
//*****************************************************************************
int32_t
USBEndpointDataGet(uint32_t ui32Base, uint32_t ui32Endpoint,
                   uint8_t *pui8Data, uint32_t *pui32Size)
{
    uint32_t ui32Register, ui32ByteCount, ui32FIFO;

    //
    // Check the arguments.
    //
    ASSERT(ui32Base == USB0_BASE);
    ASSERT((ui32Endpoint == USB_EP_0) || (ui32Endpoint == USB_EP_1) ||
           (ui32Endpoint == USB_EP_2) || (ui32Endpoint == USB_EP_3) ||
           (ui32Endpoint == USB_EP_4) || (ui32Endpoint == USB_EP_5) ||
           (ui32Endpoint == USB_EP_6) || (ui32Endpoint == USB_EP_7));

    //
    // Get the address of the receive status register to use, based on the
    // endpoint.
    //
    if(ui32Endpoint == USB_EP_0)
    {
        ui32Register = USB_O_CSRL0;
    }
    else
    {
        ui32Register = USB_O_RXCSRL1 + EP_OFFSET(ui32Endpoint);
    }

    //
    // Don't allow reading of data if the RxPktRdy bit is not set.
    //
    if((HWREGH(ui32Base + ui32Register) & USB_CSRL0_RXRDY) == 0)
    {
        //
        // Can't read the data because none is available.
        //
        *pui32Size = 0;

        //
        // Return a failure since there is no data to read.
        //
        return(-1);
    }

    //
    // Get the byte count in the FIFO.
    //
    ui32ByteCount = HWREGH(ui32Base + USB_O_COUNT0 + ui32Endpoint);

    //
    // Determine how many bytes are copied.
    //
    ui32ByteCount = (ui32ByteCount < *pui32Size) ? ui32ByteCount : *pui32Size;

    //
    // Return the number of bytes we are going to read.
    //
    *pui32Size = ui32ByteCount;

    //
    // Calculate the FIFO address.
    //
    ui32FIFO = ui32Base + USB_O_FIFO0 + (ui32Endpoint >> 2);

    //
    // Read the data out of the FIFO.
    //
    for(; ui32ByteCount > 0; ui32ByteCount--)
    {
        //
        // Read a byte at a time from the FIFO.
        //
        *pui8Data++ = HWREGB(ui32FIFO);
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
//! \param ui32Base specifies the USB module base address.
//! \param ui32Endpoint is the endpoint to access.
//! \param bIsLastPacket indicates if this packet is the last one.
//!
//! This function acknowledges that the data was read from the endpoint's FIFO.
//! The \e bIsLastPacket parameter is set to a \b true value if this is the
//! last in a series of data packets on endpoint zero.  The \e bIsLastPacket
//! parameter is not used for endpoints other than endpoint zero.  This call
//! can be used if processing is required between reading the data and
//! acknowledging that the data has been read.
//!
//! \note This function must only be called in device mode.
//!
//! \return None.
//
//*****************************************************************************
void
USBDevEndpointDataAck(uint32_t ui32Base, uint32_t ui32Endpoint,
                      bool bIsLastPacket)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == USB0_BASE);
    ASSERT((ui32Endpoint == USB_EP_0) || (ui32Endpoint == USB_EP_1) ||
           (ui32Endpoint == USB_EP_2) || (ui32Endpoint == USB_EP_3) ||
           (ui32Endpoint == USB_EP_4) || (ui32Endpoint == USB_EP_5) ||
           (ui32Endpoint == USB_EP_6) || (ui32Endpoint == USB_EP_7));

    //
    // Determine which endpoint is being acked.
    //
    if(ui32Endpoint == USB_EP_0)
    {
        //
        // Clear RxPktRdy, and optionally DataEnd, on endpoint zero.
        //
        HWREGB(ui32Base + USB_O_CSRL0) =
            USB_CSRL0_RXRDYC | (bIsLastPacket ? USB_CSRL0_DATAEND : 0);
    }
    else
    {
        //
        // Clear RxPktRdy on all other endpoints.
        //
        HWREGB(ui32Base + USB_O_RXCSRL1 + EP_OFFSET(ui32Endpoint)) &=
            ~(USB_RXCSRL1_RXRDY);
    }
}

//*****************************************************************************
//
//! Acknowledge that data was read from the given endpoint's FIFO in host
//! mode.
//!
//! \param ui32Base specifies the USB module base address.
//! \param ui32Endpoint is the endpoint to access.
//!
//! This function acknowledges that the data was read from the endpoint's FIFO.
//! This call is used if processing is required between reading the data and
//! acknowledging that the data has been read.
//!
//! \note This function must only be called in host mode.
//!
//! \return None.
//
//*****************************************************************************
void
USBHostEndpointDataAck(uint32_t ui32Base, uint32_t ui32Endpoint)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == USB0_BASE);
    ASSERT((ui32Endpoint == USB_EP_0) || (ui32Endpoint == USB_EP_1) ||
           (ui32Endpoint == USB_EP_2) || (ui32Endpoint == USB_EP_3) ||
           (ui32Endpoint == USB_EP_4) || (ui32Endpoint == USB_EP_5) ||
           (ui32Endpoint == USB_EP_6) || (ui32Endpoint == USB_EP_7));

    //
    // Clear RxPktRdy.
    //
    if(ui32Endpoint == USB_EP_0)
    {
        HWREGB(ui32Base + USB_O_CSRL0) &= ~USB_CSRL0_RXRDY;
    }
    else
    {
        HWREGB(ui32Base + USB_O_RXCSRL1 + EP_OFFSET(ui32Endpoint)) &=
            ~(USB_RXCSRL1_RXRDY);
    }
}

//*****************************************************************************
//
//! Puts data into the given endpoint's FIFO.
//!
//! \param ui32Base specifies the USB module base address.
//! \param ui32Endpoint is the endpoint to access.
//! \param pui8Data is a pointer to the data area used as the source for the
//! data to put into the FIFO.
//! \param ui32Size is the amount of data to put into the FIFO.
//!
//! This function puts the data from the \e pui8Data parameter into the FIFO
//! for this endpoint.  If a packet is already pending for transmission, then
//! this call does not put any of the data into the FIFO and returns -1.  Care
//! must be taken to not write more data than can fit into the FIFO
//! allocated by the call to USBFIFOConfigSet().
//!
//! \return This call returns 0 on success, or -1 to indicate that the FIFO
//! is in use and cannot be written.
//
//*****************************************************************************
int32_t
USBEndpointDataPut(uint32_t ui32Base, uint32_t ui32Endpoint,
                   uint8_t *pui8Data, uint32_t ui32Size)
{
    uint32_t ui32FIFO;
    uint8_t ui8TxPktRdy;

    //
    // Check the arguments.
    //
    ASSERT(ui32Base == USB0_BASE);
    ASSERT((ui32Endpoint == USB_EP_0) || (ui32Endpoint == USB_EP_1) ||
           (ui32Endpoint == USB_EP_2) || (ui32Endpoint == USB_EP_3) ||
           (ui32Endpoint == USB_EP_4) || (ui32Endpoint == USB_EP_5) ||
           (ui32Endpoint == USB_EP_6) || (ui32Endpoint == USB_EP_7));

    //
    // Get the bit position of TxPktRdy based on the endpoint.
    //
    if(ui32Endpoint == USB_EP_0)
    {
        ui8TxPktRdy = USB_CSRL0_TXRDY;
    }
    else
    {
        ui8TxPktRdy = USB_TXCSRL1_TXRDY;
    }

    //
    // Don't allow transmit of data if the TxPktRdy bit is already set.
    //
    if(HWREGB(ui32Base + USB_O_CSRL0 + ui32Endpoint) & ui8TxPktRdy)
    {
        return(-1);
    }

    //
    // Calculate the FIFO address.
    //
    ui32FIFO = ui32Base + USB_O_FIFO0 + (ui32Endpoint >> 2);

    //
    // Write the data to the FIFO.
    //
    for(; ui32Size > 0; ui32Size--)
    {
        HWREGB(ui32FIFO) = *pui8Data++;
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
//! \param ui32Base specifies the USB module base address.
//! \param ui32Endpoint is the endpoint to access.
//! \param ui32TransType is set to indicate what type of data is being sent.
//!
//! This function starts the transfer of data from the FIFO for a given
//! endpoint.  This function is called if the \b USB_EP_AUTO_SET bit was
//! not enabled for the endpoint.  Setting the \e ui32TransType parameter
//! allows the appropriate signaling on the USB bus for the type of transaction
//! being requested.  The \e ui32TransType parameter must be one of the
//! following:
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
int32_t
USBEndpointDataSend(uint32_t ui32Base, uint32_t ui32Endpoint,
                    uint32_t ui32TransType)
{
    uint32_t ui32TxPktRdy;

    //
    // Check the arguments.
    //
    ASSERT(ui32Base == USB0_BASE);
    ASSERT((ui32Endpoint == USB_EP_0) || (ui32Endpoint == USB_EP_1) ||
           (ui32Endpoint == USB_EP_2) || (ui32Endpoint == USB_EP_3) ||
           (ui32Endpoint == USB_EP_4) || (ui32Endpoint == USB_EP_5) ||
           (ui32Endpoint == USB_EP_6) || (ui32Endpoint == USB_EP_7));

    //
    // Get the bit position of TxPktRdy based on the endpoint.
    //
    if(ui32Endpoint == USB_EP_0)
    {
        //
        // Don't allow transmit of data if the TxPktRdy bit is already set.
        //
        if(HWREGB(ui32Base + USB_O_CSRL0) & USB_CSRL0_TXRDY)
        {
            return(-1);
        }

        ui32TxPktRdy = ui32TransType & 0xff;
    }
    else
    {
        //
        // Don't allow transmit of data if the TxPktRdy bit is already set.
        //
        if(HWREGB(ui32Base + USB_O_CSRL0 + ui32Endpoint) & USB_TXCSRL1_TXRDY)
        {
            return(-1);
        }

        ui32TxPktRdy = (ui32TransType >> 8) & 0xff;
    }

    //
    // Set TxPktRdy in order to send the data.
    //
    HWREGB(ui32Base + USB_O_CSRL0 + ui32Endpoint) = ui32TxPktRdy;

    //
    // Success.
    //
    return(0);
}

//*****************************************************************************
//
//! Forces a flush of an endpoint's FIFO.
//!
//! \param ui32Base specifies the USB module base address.
//! \param ui32Endpoint is the endpoint to access.
//! \param ui32Flags specifies if the IN or OUT endpoint is accessed.
//!
//! This function forces the USB controller to flush out the data in the FIFO.
//! The function can be called with either host or device controllers and
//! requires the \e ui32Flags parameter be one of \b USB_EP_HOST_OUT,
//! \b USB_EP_HOST_IN, \b USB_EP_DEV_OUT, or \b USB_EP_DEV_IN.
//!
//! \return None.
//
//*****************************************************************************
void
USBFIFOFlush(uint32_t ui32Base, uint32_t ui32Endpoint, uint32_t ui32Flags)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == USB0_BASE);
    ASSERT((ui32Endpoint == USB_EP_0) || (ui32Endpoint == USB_EP_1) ||
           (ui32Endpoint == USB_EP_2) || (ui32Endpoint == USB_EP_3) ||
           (ui32Endpoint == USB_EP_4) || (ui32Endpoint == USB_EP_5) ||
           (ui32Endpoint == USB_EP_6) || (ui32Endpoint == USB_EP_7));

    //
    // Endpoint zero has a different register set for FIFO flushing.
    //
    if(ui32Endpoint == USB_EP_0)
    {
        //
        // Nothing in the FIFO if neither of these bits are set.
        //
        if((HWREGB(ui32Base + USB_O_CSRL0) &
            (USB_CSRL0_RXRDY | USB_CSRL0_TXRDY)) != 0)
        {
            //
            // Hit the Flush FIFO bit.
            //
            HWREGB(ui32Base + USB_O_CSRH0) = USB_CSRH0_FLUSH;
        }
    }
    else
    {
        //
        // Only reset the IN or OUT FIFO.
        //
        if(ui32Flags & (USB_EP_HOST_OUT | USB_EP_DEV_IN))
        {
            //
            // Make sure the FIFO is not empty.
            //
            if(HWREGB(ui32Base + USB_O_TXCSRL1 + EP_OFFSET(ui32Endpoint)) &
               USB_TXCSRL1_TXRDY)
            {
                //
                // Hit the Flush FIFO bit.
                //
                HWREGB(ui32Base + USB_O_TXCSRL1 + EP_OFFSET(ui32Endpoint)) |=
                    USB_TXCSRL1_FLUSH;
            }
        }
        else
        {
            //
            // Make sure that the FIFO is not empty.
            //
            if(HWREGB(ui32Base + USB_O_RXCSRL1 + EP_OFFSET(ui32Endpoint)) &
               USB_RXCSRL1_RXRDY)
            {
                //
                // Hit the Flush FIFO bit.
                //
                HWREGB(ui32Base + USB_O_RXCSRL1 + EP_OFFSET(ui32Endpoint)) |=
                    USB_RXCSRL1_FLUSH;
            }
        }
    }
}

//*****************************************************************************
//
//! Schedules a request for an IN transaction on an endpoint in host mode.
//!
//! \param ui32Base specifies the USB module base address.
//! \param ui32Endpoint is the endpoint to access.
//!
//! This function schedules a request for an IN transaction.  When the USB
//! device being communicated with responds with the data, the data can be
//! retrieved by calling USBEndpointDataGet() or via a DMA transfer.
//!
//! \note This function must only be called in host mode and only for IN
//! endpoints.
//!
//! \return None.
//
//*****************************************************************************
void
USBHostRequestIN(uint32_t ui32Base, uint32_t ui32Endpoint)
{
    uint32_t ui32Register;

    //
    // Check the arguments.
    //
    ASSERT(ui32Base == USB0_BASE);
    ASSERT((ui32Endpoint == USB_EP_0) || (ui32Endpoint == USB_EP_1) ||
           (ui32Endpoint == USB_EP_2) || (ui32Endpoint == USB_EP_3) ||
           (ui32Endpoint == USB_EP_4) || (ui32Endpoint == USB_EP_5) ||
           (ui32Endpoint == USB_EP_6) || (ui32Endpoint == USB_EP_7));

    //
    // Endpoint zero uses a different offset than the other endpoints.
    //
    if(ui32Endpoint == USB_EP_0)
    {
        ui32Register = USB_O_CSRL0;
    }
    else
    {
        ui32Register = USB_O_RXCSRL1 + EP_OFFSET(ui32Endpoint);
    }

    //
    // Set the request for an IN transaction.
    //
    HWREGB(ui32Base + ui32Register) = USB_RXCSRL1_REQPKT;
}

//*****************************************************************************
//
//! Clears a scheduled IN transaction for an endpoint in host mode.
//!
//! \param ui32Base specifies the USB module base address.
//! \param ui32Endpoint is the endpoint to access.
//!
//! This function clears a previously scheduled IN transaction if it is still
//! pending.  This function is used to safely disable any scheduled IN
//! transactions if the endpoint specified by \e ui32Endpoint is reconfigured
//! for communications with other devices.
//!
//! \note This function must only be called in host mode and only for IN
//! endpoints.
//!
//! \return None.
//
//*****************************************************************************
void
USBHostRequestINClear(uint32_t ui32Base, uint32_t ui32Endpoint)
{
    uint32_t ui32Register;

    //
    // Check the arguments.
    //
    ASSERT(ui32Base == USB0_BASE);
    ASSERT((ui32Endpoint == USB_EP_0) || (ui32Endpoint == USB_EP_1) ||
           (ui32Endpoint == USB_EP_2) || (ui32Endpoint == USB_EP_3) ||
           (ui32Endpoint == USB_EP_4) || (ui32Endpoint == USB_EP_5) ||
           (ui32Endpoint == USB_EP_6) || (ui32Endpoint == USB_EP_7));

    //
    // Endpoint zero uses a different offset than the other endpoints.
    //
    if(ui32Endpoint == USB_EP_0)
    {
        ui32Register = USB_O_CSRL0;
    }
    else
    {
        ui32Register = USB_O_RXCSRL1 + EP_OFFSET(ui32Endpoint);
    }

    //
    // Clear the request for an IN transaction.
    //
    HWREGB(ui32Base + ui32Register) &= ~USB_RXCSRL1_REQPKT;
}

//*****************************************************************************
//
//! Issues a request for a status IN transaction on endpoint zero.
//!
//! \param ui32Base specifies the USB module base address.
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
USBHostRequestStatus(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == USB0_BASE);

    //
    // Set the request for a status IN transaction.
    //
    HWREGB(ui32Base + USB_O_CSRL0) = USB_CSRL0_REQPKT | USB_CSRL0_STATUS;
}

//*****************************************************************************
//
//! Sets the functional address for the device that is connected to an
//! endpoint in host mode.
//!
//! \param ui32Base specifies the USB module base address.
//! \param ui32Endpoint is the endpoint to access.
//! \param ui32Addr is the functional address for the controller to use for
//! this endpoint.
//! \param ui32Flags determines if this is an IN or an OUT endpoint.
//!
//! This function configures the functional address for a device that is using
//! this endpoint for communication.  This \e ui32Addr parameter is the address
//! of the target device that this endpoint is communicating with.  The
//! \e ui32Flags parameter indicates if the IN or OUT endpoint is set.
//!
//! \note This function must only be called in host mode.
//!
//! \return None.
//
//*****************************************************************************
void
USBHostAddrSet(uint32_t ui32Base, uint32_t ui32Endpoint, uint32_t ui32Addr,
               uint32_t ui32Flags)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == USB0_BASE);
    ASSERT((ui32Endpoint == USB_EP_0) || (ui32Endpoint == USB_EP_1) ||
           (ui32Endpoint == USB_EP_2) || (ui32Endpoint == USB_EP_3) ||
           (ui32Endpoint == USB_EP_4) || (ui32Endpoint == USB_EP_5) ||
           (ui32Endpoint == USB_EP_6) || (ui32Endpoint == USB_EP_7));

    //
    // See if the transmit or receive address is set.
    //
    if(ui32Flags & USB_EP_HOST_OUT)
    {
        //
        // Set the transmit address.
        //
        HWREGB(ui32Base + USB_O_TXFUNCADDR0 + (ui32Endpoint >> 1)) = ui32Addr;
    }
    else
    {
        //
        // Set the receive address.
        //
        HWREGB(ui32Base + USB_O_TXFUNCADDR0 + 4 + (ui32Endpoint >> 1)) =
            ui32Addr;
    }
}

//*****************************************************************************
//
//! Gets the current functional device address for an endpoint.
//!
//! \param ui32Base specifies the USB module base address.
//! \param ui32Endpoint is the endpoint to access.
//! \param ui32Flags determines if this is an IN or an OUT endpoint.
//!
//! This function returns the current functional address that an endpoint is
//! using to communicate with a device.  The \e ui32Flags parameter determines
//! if the IN or OUT endpoint's device address is returned.
//!
//! \note This function must only be called in host mode.
//!
//! \return Returns the current function address being used by an endpoint.
//
//*****************************************************************************
uint32_t
USBHostAddrGet(uint32_t ui32Base, uint32_t ui32Endpoint, uint32_t ui32Flags)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == USB0_BASE);
    ASSERT((ui32Endpoint == USB_EP_0) || (ui32Endpoint == USB_EP_1) ||
           (ui32Endpoint == USB_EP_2) || (ui32Endpoint == USB_EP_3) ||
           (ui32Endpoint == USB_EP_4) || (ui32Endpoint == USB_EP_5) ||
           (ui32Endpoint == USB_EP_6) || (ui32Endpoint == USB_EP_7));

    //
    // See if the transmit or receive address is returned.
    //
    if(ui32Flags & USB_EP_HOST_OUT)
    {
        //
        // Return this endpoint's transmit address.
        //
        return(HWREGB(ui32Base + USB_O_TXFUNCADDR0 + (ui32Endpoint >> 1)));
    }
    else
    {
        //
        // Return this endpoint's receive address.
        //
        return(HWREGB(ui32Base + USB_O_TXFUNCADDR0 + 4 + (ui32Endpoint >> 1)));
    }
}

//*****************************************************************************
//
//! Sets the hub address for the device that is connected to an endpoint.
//!
//! \param ui32Base specifies the USB module base address.
//! \param ui32Endpoint is the endpoint to access.
//! \param ui32Addr is the hub address and port for the device using this
//! endpoint.  The hub address must be defined in bits 0 through 6 with the
//! port number in bits 8 through 14.
//! \param ui32Flags determines if this is an IN or an OUT endpoint.
//!
//! This function configures the hub address for a device that is using this
//! endpoint for communication.  The \e ui32Flags parameter determines if the
//! device address for the IN or the OUT endpoint is configured by this call
//! and sets the speed of the downstream device.  Valid values are one of
//! \b USB_EP_HOST_OUT or \b USB_EP_HOST_IN optionally ORed with
//! \b USB_EP_SPEED_LOW.
//!
//! \note This function must only be called in host mode.
//!
//! \return None.
//
//*****************************************************************************
void
USBHostHubAddrSet(uint32_t ui32Base, uint32_t ui32Endpoint, uint32_t ui32Addr,
                  uint32_t ui32Flags)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == USB0_BASE);
    ASSERT((ui32Endpoint == USB_EP_0) || (ui32Endpoint == USB_EP_1) ||
           (ui32Endpoint == USB_EP_2) || (ui32Endpoint == USB_EP_3) ||
           (ui32Endpoint == USB_EP_4) || (ui32Endpoint == USB_EP_5) ||
           (ui32Endpoint == USB_EP_6) || (ui32Endpoint == USB_EP_7));

    //
    // See if the hub transmit or receive address is being set.
    //
    if(ui32Flags & USB_EP_HOST_OUT)
    {
        //
        // Set the hub transmit address and port number for this endpoint.
        //
        HWREGH(ui32Base + USB_O_TXHUBADDR0 + (ui32Endpoint >> 1)) = ui32Addr;
    }
    else
    {
        //
        // Set the hub receive address and port number for this endpoint.
        //
        HWREGH(ui32Base + USB_O_TXHUBADDR0 + 4 + (ui32Endpoint >> 1)) =
            ui32Addr;
    }

    //
    // Set the speed of communication for endpoint 0.  This configuration is
    // done here because it changes on a transaction-by-transaction basis for
    // EP0.  For other endpoints, this is set in USBHostEndpointConfig().
    //
    if(ui32Endpoint == USB_EP_0)
    {
        if(ui32Flags & USB_EP_SPEED_FULL)
        {
            HWREGB(ui32Base + USB_O_TYPE0) = USB_TYPE0_SPEED_FULL;
        }
        else if(ui32Flags & USB_EP_SPEED_HIGH)
        {
            HWREGB(ui32Base + USB_O_TYPE0) = USB_TYPE0_SPEED_HIGH;
        }
        else
        {
            HWREGB(ui32Base + USB_O_TYPE0) = USB_TYPE0_SPEED_LOW;
        }
    }
}

//*****************************************************************************
//
//! Gets the current device hub address for this endpoint.
//!
//! \param ui32Base specifies the USB module base address.
//! \param ui32Endpoint is the endpoint to access.
//! \param ui32Flags determines if this is an IN or an OUT endpoint.
//!
//! This function returns the current hub address that an endpoint is using
//! to communicate with a device.  The \e ui32Flags parameter determines if the
//! device address for the IN or OUT endpoint is returned.
//!
//! \note This function must only be called in host mode.
//!
//! \return This function returns the current hub address being used by an
//! endpoint.
//
//*****************************************************************************
uint32_t
USBHostHubAddrGet(uint32_t ui32Base, uint32_t ui32Endpoint, uint32_t ui32Flags)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == USB0_BASE);
    ASSERT((ui32Endpoint == USB_EP_0) || (ui32Endpoint == USB_EP_1) ||
           (ui32Endpoint == USB_EP_2) || (ui32Endpoint == USB_EP_3) ||
           (ui32Endpoint == USB_EP_4) || (ui32Endpoint == USB_EP_5) ||
           (ui32Endpoint == USB_EP_6) || (ui32Endpoint == USB_EP_7));

    //
    // See if the hub transmit or receive address is returned.
    //
    if(ui32Flags & USB_EP_HOST_OUT)
    {
        //
        // Return the hub transmit address for this endpoint.
        //
        return(HWREGB(ui32Base + USB_O_TXHUBADDR0 + (ui32Endpoint >> 1)));
    }
    else
    {
        //
        // Return the hub receive address for this endpoint.
        //
        return(HWREGB(ui32Base + USB_O_TXHUBADDR0 + 4 + (ui32Endpoint >> 1)));
    }
}

//*****************************************************************************
//
//! Sets the configuration for USB power fault.
//!
//! \param ui32Base specifies the USB module base address.
//! \param ui32Flags specifies the configuration of the power fault.
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
//! \note This function must only be called on microcontrollers that support
//! host mode or OTG operation.
//!
//! \return None.
//
//*****************************************************************************
void
USBHostPwrConfig(uint32_t ui32Base, uint32_t ui32Flags)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == USB0_BASE);
    ASSERT((ui32Flags & ~(USB_HOST_PWREN_FILTER | USB_EPC_PFLTACT_M |
                          USB_EPC_PFLTAEN | USB_EPC_PFLTSEN_HIGH |
                          USB_EPC_EPEN_M)) == 0);

    //
    // If requested, enable VBUS droop detection on parts that support this
    // feature.
    //
    HWREG(ui32Base + USB_O_VDC) = ui32Flags >> 16;

    //
    // Set the power fault configuration as specified.  This configuration
    // does not change whether fault detection is enabled or not.
    //
    HWREGH(ui32Base + USB_O_EPC) =
        (ui32Flags | (HWREGH(ui32Base + USB_O_EPC) &
                      ~(USB_EPC_PFLTACT_M | USB_EPC_PFLTAEN |
                        USB_EPC_PFLTSEN_HIGH | USB_EPC_EPEN_M)));
}

//*****************************************************************************
//
//! Enables power fault detection.
//!
//! \param ui32Base specifies the USB module base address.
//!
//! This function enables power fault detection in the USB controller.  If the
//! USBnPFLT pin is not in use, this function must not be used.
//!
//! \note This function must only be called in host mode.
//!
//! \return None.
//
//*****************************************************************************
void
USBHostPwrFaultEnable(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == USB0_BASE);

    //
    // Enable power fault input.
    //
    HWREGH(ui32Base + USB_O_EPC) |= USB_EPC_PFLTEN;
}

//*****************************************************************************
//
//! Disables power fault detection.
//!
//! \param ui32Base specifies the USB module base address.
//!
//! This function disables power fault detection in the USB controller.
//!
//! \note This function must only be called in host mode.
//!
//! \return None.
//
//*****************************************************************************
void
USBHostPwrFaultDisable(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == USB0_BASE);

    //
    // Enable power fault input.
    //
    HWREGH(ui32Base + USB_O_EPC) &= ~USB_EPC_PFLTEN;
}

//*****************************************************************************
//
//! Enables the external power pin.
//!
//! \param ui32Base specifies the USB module base address.
//!
//! This function enables the USBnEPEN signal, which enables an external power
//! supply in host mode operation.
//!
//! \note This function must only be called in host mode.
//!
//! \return None.
//
//*****************************************************************************
void
USBHostPwrEnable(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == USB0_BASE);

    //
    // Enable the external power supply enable signal.
    //
    HWREGH(ui32Base + USB_O_EPC) |= USB_EPC_EPENDE;
}

//*****************************************************************************
//
//! Disables the external power pin.
//!
//! \param ui32Base specifies the USB module base address.
//!
//! This function disables the USBnEPEN signal, which disables an external
//! power supply in host mode operation.
//!
//! \note This function must only be called in host mode.
//!
//! \return None.
//
//*****************************************************************************
void
USBHostPwrDisable(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == USB0_BASE);

    //
    // Disable the external power supply enable signal.
    //
    HWREGH(ui32Base + USB_O_EPC) &= ~USB_EPC_EPENDE;
}

//*****************************************************************************
//
//! Get the current frame number.
//!
//! \param ui32Base specifies the USB module base address.
//!
//! This function returns the last frame number received.
//!
//! \return The last frame number received.
//
//*****************************************************************************
uint32_t
USBFrameNumberGet(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == USB0_BASE);

    //
    // Return the most recent frame number.
    //
    return(HWREGH(ui32Base + USB_O_FRAME));
}

//*****************************************************************************
//
//! Starts or ends a session.
//!
//! \param ui32Base specifies the USB module base address.
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
USBOTGSessionRequest(uint32_t ui32Base, bool bStart)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == USB0_BASE);

    //
    // Start or end the session as directed.
    //
    if(bStart)
    {
        HWREGB(ui32Base + USB_O_DEVCTL) |= USB_DEVCTL_SESSION;
    }
    else
    {
        HWREGB(ui32Base + USB_O_DEVCTL) &= ~USB_DEVCTL_SESSION;
    }
}

//*****************************************************************************
//
//! Returns the absolute FIFO address for a given endpoint.
//!
//! \param ui32Base specifies the USB module base address.
//! \param ui32Endpoint specifies which endpoint's FIFO address to return.
//!
//! This function returns the actual physical address of the FIFO.  This
//! address is needed when the USB is going to be used with the uDMA
//! controller and the source or destination address must be set to the
//! physical FIFO address for a given endpoint.
//!
//! \return None.
//
//*****************************************************************************
uint32_t
USBFIFOAddrGet(uint32_t ui32Base, uint32_t ui32Endpoint)
{
    //
    // Return the FIFO address for this endpoint.
    //
    return(ui32Base + USB_O_FIFO0 + (ui32Endpoint >> 2));
}

//*****************************************************************************
//
//! Returns the current operating mode of the controller.
//!
//! \param ui32Base specifies the USB module base address.
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
uint32_t
USBModeGet(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == USB0_BASE);

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
    return(HWREGB(ui32Base + USB_O_DEVCTL) &
           (USB_DEVCTL_DEV | USB_DEVCTL_HOST | USB_DEVCTL_SESSION |
            USB_DEVCTL_VBUS_M));
}

//*****************************************************************************
//
//! Sets the DMA channel to use for a given endpoint.
//!
//! \param ui32Base specifies the USB module base address.
//! \param ui32Endpoint specifies which endpoint's FIFO address to return.
//! \param ui32Channel specifies which DMA channel to use for which endpoint.
//!
//! This function is used to configure which DMA channel to use with a given
//! endpoint.  Receive DMA channels can only be used with receive endpoints
//! and transmit DMA channels can only be used with transmit endpoints.  As a
//! result, the 3 receive and 3 transmit DMA channels can be mapped to any
//! endpoint other than 0.  The values that are passed into the
//! \e ui32Channel value are the UDMA_CHANNEL_USBEP* values defined in udma.h.
//!
//! \note This function only has an effect on microcontrollers that have the
//! ability to change the DMA channel for an endpoint.  Calling this function
//! on other devices has no effect.
//!
//! \return None.
//!
//*****************************************************************************
void
USBEndpointDMAChannel(uint32_t ui32Base, uint32_t ui32Endpoint,
                      uint32_t ui32Channel)
{
    uint32_t ui32Mask;

    //
    // Check the arguments.
    //
    ASSERT(ui32Base == USB0_BASE);
    ASSERT((ui32Endpoint == USB_EP_1) || (ui32Endpoint == USB_EP_2) ||
           (ui32Endpoint == USB_EP_3) || (ui32Endpoint == USB_EP_4) ||
           (ui32Endpoint == USB_EP_5) || (ui32Endpoint == USB_EP_6) ||
           (ui32Endpoint == USB_EP_7));
    ASSERT(ui32Channel <= UDMA_CHANNEL_USBEP3TX);

    //
    // The input select mask must be shifted into the correct position
    // based on the channel.
    //
    ui32Mask = 0xf << (ui32Channel * 4);

    //
    // Clear out the current selection for the channel.
    //
    ui32Mask = HWREG(ui32Base + USB_O_DMASEL) & (~ui32Mask);

    //
    // The input select is now shifted into the correct position based on the
    // channel.
    //
    ui32Mask |= (USBEPToIndex(ui32Endpoint)) << (ui32Channel * 4);

    //
    // Write the value out to the register.
    //
    HWREG(ui32Base + USB_O_DMASEL) = ui32Mask;
}

//*****************************************************************************
//
//! Change the mode of the USB controller to host.
//!
//! \param ui32Base specifies the USB module base address.
//!
//! This function changes the mode of the USB controller to host mode.
//!
//! \note This function must only be called on microcontrollers that support
//! OTG operation and have the DEVMODOTG bit in the USBGPCS register.
//!
//! \return None.
//
//*****************************************************************************
void
USBHostMode(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == USB0_BASE);

    //
    // Force mode in OTG parts that support forcing USB controller mode.
    // This bit is not writable in USB controllers that do not support
    // forcing the mode.  Not setting the USB_GPCS_DEVMOD bit makes this a
    // force of host mode.
    //
    HWREGB(ui32Base + USB_O_GPCS) = USB_GPCS_DEVMODOTG;
}

//*****************************************************************************
//
//! Change the mode of the USB controller to device.
//!
//! \param ui32Base specifies the USB module base address.
//!
//! This function changes the mode of the USB controller to device mode.
//!
//! \note This function must only be called on microcontrollers that support
//! OTG operation and have the DEVMODOTG bit in the USBGPCS register.
//!
//! \return None.
//
//*****************************************************************************
void
USBDevMode(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == USB0_BASE);

    //
    // Set the USB controller mode to device.
    //
    HWREGB(ui32Base + USB_O_GPCS) = USB_GPCS_DEVMODOTG | USB_GPCS_DEVMOD;
}

//*****************************************************************************
//
//! Change the mode of the USB controller to OTG.
//!
//! \param ui32Base specifies the USB module base address.
//!
//! This function changes the mode of the USB controller to OTG mode.  This
//! function is only valid on microcontrollers that have the OTG capabilities.
//!
//! \return None.
//
//*****************************************************************************
void
USBOTGMode(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == USB0_BASE);

    //
    // Disable the override of the USB controller mode when running on an OTG
    // device.
    //
    HWREGB(ui32Base + USB_O_GPCS) = 0;
}

//*****************************************************************************
//
//! Change the operating mode of the USB controller.
//!
//! \param ui32Base specifies the USB module base address.
//! \param ui32Mode specifies the operating mode of the USB OTG pins.
//!
//! This function changes the operating modes of the USB controller.  When
//! operating in full OTG mode, the USB controller uses the VBUS and ID pins to
//! detect mode and voltage changes.  While these pins are primarily used in
//! OTG mode, they can also affect the operation of host and device modes.  In
//! device mode the USB controller can configured monitor or ignore VBUS.
//! Monitoring VBUS allows the controller to determine if it has been
//! disconnected from the host.  In host mode, the USB controller uses the
//! VBUS pin to detect loss of VBUS due to excessive power draw due to a drop
//! in the VBUS voltage.  This call takes the place of USBHostMode(),
//! USBDeviceMode(), and USBOTGMode().  The \e ui32Mode value should be one of
//! the following values:
//!
//! - \b USB_MODE_OTG enables operating in full OTG mode, VBUS and ID are
//!   used by the controller.
//! - \b USB_MODE_HOST enables operating only as a host with no monitoring of
//!   VBUS or ID pins.
//! - \b USB_MODE_HOST_VBUS enables operating only as a host with monitoring of
//!   VBUS pin.  This enables detection of VBUS droop while still
//!   forcing host mode.
//! - \b USB_MODE_DEVICE enables operating only as a device with no monitoring
//!   of VBUS or ID pins.
//! - \b USB_MODE_DEVICE_VBUS enables operating only as a device with
//!   monitoring of VBUS pin.  This enables disconnect detection while still
//!   forcing device mode.
//!
//! \note This feature is not available on all Tiva devices.  Please
//! check the data sheet to determine if the USB controller has the ability to
//! control monitoring VBUS while forcing the ID state.
//!
//! \b Example: Force device mode but allow monitoring of the USB VBUS pin.
//!
//! \verbatim
//! //
//! // Force device mode but allow monitoring of VBUS for disconnect.
//! //
//! USBModeConfig(USB_MODE_DEVICE_VBUS);
//! \endverbatim
//!
//! \return None.
//
//*****************************************************************************
void
USBModeConfig(uint32_t ui32Base, uint32_t ui32Mode)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == USB0_BASE);

    HWREG(ui32Base + USB_O_GPCS) = ui32Mode;
}

//*****************************************************************************
//
//! Powers off the USB PHY.
//!
//! \param ui32Base specifies the USB module base address.
//!
//! This function powers off the USB PHY, reducing the current consuption
//! of the device.  While in the powered-off state, the USB controller is
//! unable to operate.
//!
//! \return None.
//
//*****************************************************************************
void
USBPHYPowerOff(uint32_t ui32Base)
{
    //
    // Set the PWRDNPHY bit in the PHY, putting it into its low power mode.
    //
    HWREGB(ui32Base + USB_O_POWER) |= USB_POWER_PWRDNPHY;
}

//*****************************************************************************
//
//! Powers on the USB PHY.
//!
//! \param ui32Base specifies the USB module base address.
//!
//! This function powers on the USB PHY, enabling it return to normal
//! operation.  By default, the PHY is powered on, so this function must
//! only be called if USBPHYPowerOff() has previously been called.
//!
//! \return None.
//
//*****************************************************************************
void
USBPHYPowerOn(uint32_t ui32Base)
{
    //
    // Clear the PWRDNPHY bit in the PHY, putting it into normal operating
    // mode.
    //
    HWREGB(ui32Base + USB_O_POWER) &= ~USB_POWER_PWRDNPHY;
}

//*****************************************************************************
//
//! Sets the number of packets to request when transferring multiple bulk
//! packets.
//!
//! \param ui32Base specifies the USB module base address.
//! \param ui32Endpoint is the endpoint index to target for this write.
//! \param ui32Count is the number of packets to request.
//!
//! This function sets the number of consecutive bulk packets to request
//! when transferring multiple bulk packets with DMA.
//!
//! \note This feature is not available on all Tiva devices.  Please
//! check the data sheet to determine if the USB controller has a DMA
//! controller or if it must use the uDMA controller for DMA transfers.
//!
//! \return None.
//
//*****************************************************************************
void
USBEndpointPacketCountSet(uint32_t ui32Base, uint32_t ui32Endpoint,
                          uint32_t ui32Count)
{
    HWREG(ui32Base + USB_O_RQPKTCOUNT1 +
          (0x4 * (USBEPToIndex(ui32Endpoint) - 1))) = ui32Count;
}

//*****************************************************************************
//
//! Returns the number of USB endpoint pairs on the device.
//!
//! \param ui32Base specifies the USB module base address.
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
uint32_t
USBNumEndpointsGet(uint32_t ui32Base)
{
    //
    // Read the number of endpoints from the hardware.  The number of TX and
    // RX endpoints are always the same.
    //
    return(HWREGB(ui32Base + USB_O_EPINFO) & USB_EPINFO_TXEP_M);
}

//*****************************************************************************
//
//! Returns the version of the USB controller.
//!
//! \param ui32Base specifies the USB module base address.
//!
//! This function returns the version number of the USB controller, which can
//! be be used to adjust for slight differences between the USB controllers in
//! the Tiva family.  The values that are returned are
//! \b USB_CONTROLLER_VER_0 and \b USB_CONTROLLER_VER_1.
//!
//! \note The most significant difference between \b USB_CONTROLLER_VER_0 and
//! \b USB_CONTROLLER_VER_1 is that \b USB_CONTROLLER_VER_1 supports the USB
//! controller's own bus master DMA controller, while the
//! \b USB_CONTROLLER_VER_0 only supports using the uDMA controller with the
//! USB module.
//!
//! \b Example: Get the version of the Tiva USB controller.
//!
//! \verbatim
//! uint32_t ui32Version;
//!
//! //
//! // Retrieve the version of the Tiva USB controller.
//! //
//! ui32Version = USBControllerVersion(USB0_BASE);
//! \endverbatim
//!
//! \return This function returns one of the \b USB_CONTROLLER_VER_ values.
//
//*****************************************************************************
uint32_t
USBControllerVersion(uint32_t ui32Base)
{
    //
    // Return the type field of the peripheral properties.  This returns
    // zero for all parts that did not have a peripheral property.
    //
    return(HWREG(ui32Base + USB_O_PP) & USB_PP_TYPE_M);
}

//*****************************************************************************
//
//! Configures and enables the clocking to the USB controller's PHY.
//!
//! \param ui32Base specifies the USB module base address.
//! \param ui32Div specifies the divider for the input clock
//! \param ui32Flags specifies which clock to use for the USB clock.
//!
//! This function configures and enables the USB PHY clock as an input to the
//! USB controller or as and output to an externally connect USB PHY.  The
//! \e ui32Flags parameter specifies the clock source with the following
//! values:
//!
//! - \b USB_CLOCK_INTERNAL uses the internal clock for the USB PHY clock
//!   source.
//! - \b USB_CLOCK_EXTERNAL specifies that the USB0CLK input pin is used as the
//!   USB PHY clock source.
//!
//! The \e ui32Div parameter is used to specify a divider for the internal
//! clock if the \b USB_CLOCK_INTERNAL is specified and is ignored if
//! \b USB_CLOCK_EXTERNAL is specified.  When the \b USB_CLOCK_INTERNAL is
//! specified, the \e ui32Div value must be set so that the PLL_VCO/\e ui32Div
//! results in a 60-MHz clock.
//!
//! \b Example: Enable the USB clock with a 480-MHz PLL setting.
//!
//! \verbatim
//! //
//! // Enable the USB clock using a 480-MHz PLL.
//! // (480-MHz/8 = 60-MHz)
//! //
//! USBClockEnable(USB0_BASE, 8, USB_CLOCK_INTERNAL);
//! \endverbatim
//!
//! \note The ability to configure the USB PHY clock input is not available on
//! all Tiva devices.  Please consult the data sheet for the Tiva
//! device that you are using to determine if this feature is available.
//!
//! \return None.
//
//*****************************************************************************
void
USBClockEnable(uint32_t ui32Base, uint32_t ui32Div, uint32_t ui32Flags)
{
    ASSERT(ui32Base == USB0_BASE);

    //
    // Configure and enable the USB clock input.
    //
    HWREG(ui32Base + USB_O_CC) = (ui32Div - 1) | ui32Flags;
}

//*****************************************************************************
//
//! Disables the clocking of the USB controller's PHY.
//!
//! \param ui32Base specifies the USB module base address.
//!
//! This function disables the USB PHY clock input or output.
//!
//! \b Example: Disable the USB PHY clock input.
//!
//! \verbatim
//! //
//! // Disable clocking of the USB controller's PHY.
//! //
//! USBClockDisable(USB0_BASE);
//! \endverbatim
//!
//! \note The ability to configure the USB PHY clock is not available on all
//! Tiva devices.  Please consult the data sheet for the Tiva device
//! that you are using to determine if this feature is available.
//!
//! \return None.
//
//*****************************************************************************
void
USBClockDisable(uint32_t ui32Base)
{
    ASSERT(ui32Base == USB0_BASE);

    //
    // Disable the USB clock input.
    //
    HWREG(ui32Base + USB_O_CC) = 0;
}

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************
//*****************************************************************************
//
//! \addtogroup usb_dma
//! @{
//
//*****************************************************************************

//*****************************************************************************
//
//! Enable interrupts for a given USB DMA channel.
//!
//! \param ui32Base specifies the USB module base address.
//! \param ui32Channel specifies which DMA channel interrupt to enable.
//!
//! This function enables the USB DMA channel interrupt based on the
//! \e ui32Channel parameter.  The \e ui32Channel value is a zero-based
//! index of the USB DMA channel.  Once enabled, the USBDMAChannelIntStatus()
//! function returns if a DMA channel has generated an interrupt.
//!
//! \b Example: Enable the USB DMA channel 3 interrupt.
//!
//! \verbatim
//! //
//! // Enable the USB DMA channel 3 interrupt
//! //
//! USBDMAChannelIntEnable(USB0_BASE, 3);
//! \endverbatim
//!
//! \note This feature is not available on all Tiva devices.  Please
//! check the data sheet to determine if the USB controller has a DMA
//! controller or if it must use the uDMA controller for DMA transfers.
//!
//! \return None.
//
//*****************************************************************************
void
USBDMAChannelIntEnable(uint32_t ui32Base, uint32_t ui32Channel)
{
    ASSERT(ui32Base == USB0_BASE);
    ASSERT(ui32Channel < 8);

    //
    // Enable the specified DMA channel interrupts.
    //
    HWREG(ui32Base + USB_O_DMACTL0 + (0x10 * ui32Channel)) |= USB_DMACTL0_IE;
}

//*****************************************************************************
//
//! Disable interrupts for a given USB DMA channel.
//!
//! \param ui32Base specifies the USB module base address.
//! \param ui32Channel specifies which USB DMA channel interrupt to disable.
//!
//! This function disables the USB DMA channel interrupt based on the
//! \e ui32Channel parameter.  The \e ui32Channel value is a zero-based
//! index of the USB DMA channel.
//!
//! \b Example: Disable the USB DMA channel 3 interrupt.
//!
//! \verbatim
//! //
//! // Disable the USB DMA channel 3 interrupt
//! //
//! USBDMAChannelIntDisable(USB0_BASE, 3);
//! \endverbatim
//!
//! \note This feature is not available on all Tiva devices.  Please
//! check the data sheet to determine if the USB controller has a DMA
//! controller or if it must use the uDMA controller for DMA transfers.
//!
//! \return None.
//
//*****************************************************************************
void
USBDMAChannelIntDisable(uint32_t ui32Base, uint32_t ui32Channel)
{
    ASSERT(ui32Base == USB0_BASE);
    ASSERT(ui32Channel < 8);

    //
    // Enable the specified DMA channel interrupts.
    //
    HWREG(ui32Base + USB_O_DMACTL0 + (0x10 * ui32Channel)) &= ~USB_DMACTL0_IE;
}

//*****************************************************************************
//
//! Return the current status of the USB DMA interrupts.
//!
//! \param ui32Base specifies the USB module base address.
//!
//! This function returns the current bit-mapped interrupt status for all USB
//! DMA channel interrupt sources.  Calling this function automatically clears
//! all currently pending USB DMA interrupts.
//!
//! \note This feature is not available on all Tiva devices.  Please
//! check the data sheet to determine if the USB controller has a DMA
//! controller or if it must use the uDMA controller for DMA transfers.
//!
//! \b Example: Get the pending USB DMA interrupts.
//!
//! \verbatim
//! uint32_t ui32Ints;
//!
//! //
//! // Get the pending USB DMA interrupts.
//! //
//! ui32Ints = USBDMAChannelIntStatus(USB0_BASE);
//! \endverbatim
//!
//! \return The bit-mapped interrupts for the DMA channels.
//
//*****************************************************************************
uint32_t
USBDMAChannelIntStatus(uint32_t ui32Base)
{
    ASSERT(ui32Base == USB0_BASE);

    return(HWREG(ui32Base + USB_O_DMAINTR));
}

//*****************************************************************************
//
//! Enables USB DMA for a given channel.
//!
//! \param ui32Base specifies the USB module base address.
//! \param ui32Channel specifies the USB DMA channel to enable.
//!
//! This function enables the USB DMA channel passed in the \e ui32Channel
//! parameter.  The \e ui32Channel value is a zero-based index of the USB DMA
//! channel.
//!
//! \b Example: Enable USB DMA channel 2.
//!
//! \verbatim
//! //
//! // Enable USB DMA channel 2.
//! //
//! USBDMAChannelEnable(2);
//! \endverbatim
//!
//! \note This feature is not available on all Tiva devices.  Please
//! check the data sheet to determine if the USB controller has a DMA
//! controller or if it must use the uDMA controller for DMA transfers.
//!
//! \return None.
//
//*****************************************************************************
void
USBDMAChannelEnable(uint32_t ui32Base, uint32_t ui32Channel)
{
    ASSERT(ui32Base == USB0_BASE);
    ASSERT(ui32Channel < 8);

    //
    // Enable the USB DMA channel.
    //
    HWREG(ui32Base + USB_O_DMACTL0 + (0x10 * ui32Channel)) |=
        USB_DMACTL0_ENABLE;
}

//*****************************************************************************
//
//! Disables USB DMA for a given channel.
//!
//! \param ui32Base specifies the USB module base address.
//! \param ui32Channel specifies the USB DMA channel to disable.
//!
//! This function disables the USB DMA channel passed in the \e ui32Channel
//! parameter.  The \e ui32Channel parameter is a zero-based index of the DMA
//! channel.
//!
//! \b Example: Disable USB DMA channel 2.
//!
//! \verbatim
//! //
//! // Disable USB DMA channel 2.
//! //
//! USBDMAChannelDisable(2);
//! \endverbatim
//!
//! \note This feature is not available on all Tiva devices.  Please
//! check the data sheet to determine if the USB controller has a DMA
//! controller or if it must use the uDMA controller for DMA transfers.
//!
//! \return None.
//
//*****************************************************************************
void
USBDMAChannelDisable(uint32_t ui32Base, uint32_t ui32Channel)
{
    ASSERT(ui32Base == USB0_BASE);
    ASSERT(ui32Channel < 8);

    //
    // Disable the USB DMA channel.
    //
    HWREG(ui32Base + USB_O_DMACTL0 + (0x10 * ui32Channel)) &=
        ~USB_DMACTL0_ENABLE;
}

//*****************************************************************************
//
//! Assigns and configures an endpoint to a given USB DMA channel.
//!
//! \param ui32Base specifies the USB module base address.
//! \param ui32Channel specifies which DMA channel to access.
//! \param ui32Endpoint is the endpoint to assign to the USB DMA channel.
//! \param ui32Config is used to specify the configuration of the USB DMA
//! channel.
//!
//! This function assigns an endpoint and configures the settings for a
//! USB DMA channel.  The \e ui32Endpoint parameter is one of the
//! \b USB_EP_* values and the \e ui32Channel value is a zero-based index of
//! the DMA channel to configure.  The \e ui32Config parameter is a combination
//! of the \b USB_DMA_CFG_* values using the following guidelines.
//!
//! Use one of the following to set the DMA burst mode:
//! - \b USB_DMA_CFG_BURST_NONE disables bursting.
//! - \b USB_DMA_CFG_BURST_4 sets the DMA burst size to 4 words.
//! - \b USB_DMA_CFG_BURST_8 sets the DMA burst size to 8 words.
//! - \b USB_DMA_CFG_BURST_16 sets the DMA burst size to 16 words.
//!
//! Use one of the following to set the DMA mode:
//! - \b USB_DMA_CFG_MODE_0 is typically used when only a single packet is
//!   being sent via DMA and triggers one completion interrupt per packet.
//! - \b USB_DMA_CFG_MODE_1 is typically used when multiple packets are being
//!   sent via DMA and triggers one completion interrupt per transfer.
//!
//! Use one of the following to set the direction of the transfer:
//! - \b USB_DMA_CFG_DIR_RX selects a DMA transfer from the endpoint to a
//!   memory location.
//! - \b USB_DMA_CFG_DIR_TX selects a DMA transfer to the endpoint from a
//!   memory location.
//!
//! The following two optional settings allow an application to immediately
//! enable the DMA transfer and/or DMA interrupts when configuring the DMA
//! channel:
//! - \b USB_DMA_CFG_INT_EN enables interrupts for this channel immediately so
//!   that an added call to USBDMAChannelIntEnable() is not necessary.
//! - \b USB_DMA_CFG_EN enables the DMA channel immediately so that an added
//!   call to USBDMAChannelEnable() is not necessary.
//!
//! \b Example: Assign channel 0 to endpoint 1 in DMA mode 0, 4 word burst,
//!    enable interrupts and immediately enable the transfer.
//!
//! \verbatim
//! //
//! // Assign channel 0 to endpoint 1 in DMA mode 0, 4 word bursts,
//! // enable interrupts and immediately enable the transfer.
//! //
//! USBDMAChannelConfigSet(USB0_BASE, 0, USB_EP_1,
//!                        (USB_DMA_CFG_BURST_4 | USB_DMA_CFG_MODE0 |
//!                         USB_DMA_CFG_DIR_RX | USB_DMA_CFG_INT_EN |
//!                         USB_DMA_CFG_EN));
//! \endverbatim
//!
//! \note This feature is not available on all Tiva devices.  Please
//! check the data sheet to determine if the USB controller has a DMA
//! controller or if it must use the uDMA controller for DMA transfers.
//!
//! \return None.
//
//*****************************************************************************
void
USBDMAChannelConfigSet(uint32_t ui32Base, uint32_t ui32Channel,
                       uint32_t ui32Endpoint, uint32_t ui32Config)
{
    ASSERT(ui32Base == USB0_BASE);
    ASSERT(ui32Channel < 8);
    ASSERT((ui32Endpoint & ~USB_EP_7) == 0);

    //
    // Reset this USB DMA channel.
    //
    HWREG(ui32Base + USB_O_DMACTL0 + (0x10 * ui32Channel)) = 0;

    //
    // Set the configuration of the requested channel.
    //
    HWREG(ui32Base + USB_O_DMACTL0 + (0x10 * ui32Channel)) =
        ui32Config | ui32Endpoint;
}

//*****************************************************************************
//
//! Returns the current status for a USB DMA channel.
//!
//! \param ui32Base specifies the USB module base address.
//! \param ui32Channel specifies which DMA channel to query.
//!
//! This function returns the current status for the USB DMA channel specified
//! by the \e ui32Channel parameter.  The \e ui32Channel value is a zero-based
//! index of the USB DMA channel to query.
//!
//! \b Example: Get the current USB DMA status for channel 2.
//!
//! \verbatim
//! uint32_t ui32Status;
//!
//! //
//! // Get the current USB DMA status for channel 2.
//! //
//! ui32Status = USBDMAChannelStatus(USB0_BASE, 2);
//! \endverbatim
//!
//! \note This feature is not available on all Tiva devices.  Please
//! check the data sheet to determine if the USB controller has a DMA
//! controller or if it must use the uDMA controller for DMA transfers.
//!
//! \return Returns zero or \b USB_DMACTL0_ERR if there is a pending error
//! condition on a DMA channel.
//
//*****************************************************************************
uint32_t
USBDMAChannelStatus(uint32_t ui32Base, uint32_t ui32Channel)
{
    ASSERT(ui32Base == USB0_BASE);
    ASSERT(ui32Channel < 8);

    //
    // Return a non-zero value if there is a pending error condition.
    //
    return(HWREG(ui32Base + USB_O_DMACTL0 + (0x10 * ui32Channel)) &
           USB_DMACTL0_ERR);
}

//*****************************************************************************
//
//! Clears the USB DMA status for a given channel.
//!
//! \param ui32Base specifies the USB module base address.
//! \param ui32Channel specifies which DMA channel to clear.
//! \param ui32Status holds the status bits to clear.
//!
//! This function clears the USB DMA channel status for the channel specified
//! by the \e ui32Channel parameter.  The \e ui32Channel value is a zero-based
//! index of the USB DMA channel to query.  The \e ui32Status parameter
//! specifies the status bits to clear and must be the valid values that are
//! returned from a call to the USBDMAChannelStatus() function.
//!
//! \b Example: Clear the current USB DMA status for channel 2.
//!
//! \verbatim
//! //
//! // Clear the any pending USB DMA status for channel 2.
//! //
//! USBDMAChannelStatusClear(USB0_BASE, 2, USBDMAChannelStatus(USB0_BASE, 2));
//! \endverbatim
//!
//! \note This feature is not available on all Tiva devices.  Please
//! check the data sheet to determine if the USB controller has a DMA
//! controller or if it must use the uDMA controller for DMA transfers.
//!
//! \return None.
//
//*****************************************************************************
void
USBDMAChannelStatusClear(uint32_t ui32Base, uint32_t ui32Channel,
                         uint32_t ui32Status)
{
    ASSERT(ui32Base == USB0_BASE);
    ASSERT(ui32Channel < 8);

    //
    // The only status is the error bit.
    //
    ui32Status &= USB_DMACTL0_ERR;

    //
    // Clear the specified error condition.
    //
    HWREG(ui32Base + USB_O_DMACTL0 + (0x10 * ui32Channel)) &= ~ui32Status;
}

//*****************************************************************************
//
//! Sets the source or destination address for a USB DMA transfer on a given
//! channel.
//!
//! \param ui32Base specifies the USB module base address.
//! \param ui32Channel specifies which DMA channel to configure.
//! \param pvAddress specifies the source or destination address for the USB
//! DMA transfer.
//!
//! This function sets the source or destination address for the USB DMA
//! channel number specified in the \e ui32Channel parameter.  The
//! \e ui32Channel value is a zero-based index of the USB DMA channel.  The
//! \e pvAddress parameter is a source address if the transfer type for the DMA
//! channel is transmit and a destination address if the transfer type is
//! receive.
//!
//! \b Example: Set the transfer address for USB DMA channel 1.
//!
//! \verbatim
//! void *pvBuffer;
//!
//! //
//! // Set the address for USB DMA channel 1.
//! //
//! USBDMAChannelAddressSet(USB0_BASE, 1, pvBuffer);
//! \endverbatim
//!
//! \note This feature is not available on all Tiva devices.  Please
//! check the data sheet to determine if the USB controller has a DMA
//! controller or if it must use the uDMA controller for DMA transfers.
//!
//! \return None.
//
//*****************************************************************************
void
USBDMAChannelAddressSet(uint32_t ui32Base, uint32_t ui32Channel,
                        void *pvAddress)
{
    ASSERT(ui32Base == USB0_BASE);
    ASSERT(ui32Channel < 8);

    //
    // Set the DMA address.
    //
    HWREG(ui32Base + USB_O_DMAADDR0 + (0x10 * ui32Channel)) =
        (uint32_t)pvAddress;
}

//*****************************************************************************
//
//! Returns the source or destination address for a given USB controller's
//! DMA channel.
//!
//! \param ui32Base specifies the USB module base address.
//! \param ui32Channel specifies the USB DMA channel.
//!
//! This function returns the DMA address for the channel number specified
//! in the \e ui32Channel parameter.  The \e ui32Channel value is a zero-based
//! index of the DMA channel to query.  This function must not be used on
//! devices that return \b USB_CONTROLLER_VER_0 from the USBControllerVersion()
//! function.
//!
//! \b Example: Get the transfer address for USB DMA channel 1.
//!
//! \verbatim
//! void *pvBuffer;
//!
//! //
//! // Retrieve the current DMA address for channel 1.
//! //
//! pvBuffer = USBDMAChannelAddressGet(USB0_BASE, 1);
//! \endverbatim
//!
//! \note This feature is not available on all Tiva devices.  Please
//! check the data sheet to determine if the USB controller has a DMA
//! controller or if it must use the uDMA controller for DMA transfers.
//!
//! \return The current DMA address for a USB DMA channel.
//
//*****************************************************************************
void *
USBDMAChannelAddressGet(uint32_t ui32Base, uint32_t ui32Channel)
{
    ASSERT(ui32Base == USB0_BASE);
    ASSERT(ui32Channel < 8);

    //
    // Return the current DMA address.
    //
    return((void *)HWREG(ui32Base + USB_O_DMAADDR0 + (0x10 * ui32Channel)));
}

//*****************************************************************************
//
//! Sets the transfer count for a USB DMA channel.
//!
//! \param ui32Base specifies the USB module base address.
//! \param ui32Channel specifies which DMA channel to access.
//! \param ui32Count specifies the number of bytes to transfer.
//!
//! This function sets the USB DMA transfer count in bytes for the channel
//! number specified in the \e ui32Channel parameter.  The \e ui32Channel
//! value is a zero-based index of the DMA channel.
//!
//! \b Example: Set the transfer count to 512 bytes for USB DMA channel 1.
//!
//! \verbatim
//! //
//! // Set the transfer count to 512 bytes for USB DMA channel 1.
//! //
//! USBDMAChannelCountSet(USB0_BASE, 1, 512);
//! \endverbatim
//!
//! \note This feature is not available on all Tiva devices.  Please
//! check the data sheet to determine if the USB controller has a DMA
//! controller or if it must use the uDMA controller for DMA transfers.
//!
//! \return None.
//
//*****************************************************************************
void
USBDMAChannelCountSet(uint32_t ui32Base, uint32_t ui32Channel,
                      uint32_t ui32Count)
{
    ASSERT(ui32Base == USB0_BASE);
    ASSERT(ui32Channel < 8);

    //
    // Set the USB DMA count for the channel.
    //
    HWREG(ui32Base + USB_O_DMACOUNT0 + (0x10 * ui32Channel)) = ui32Count;
}

//*****************************************************************************
//
//! Returns the transfer count for a USB DMA channel.
//!
//! \param ui32Base specifies the USB module base address.
//! \param ui32Channel specifies which DMA channel to access.
//!
//! This function returns the USB DMA transfer count in bytes for the channel
//! number specified in the \e ui32Channel parameter.  The \e ui32Channel value
//! is a zero-based index of the DMA channel to query.
//!
//! \b Example: Get the transfer count for USB DMA channel 1.
//!
//! \verbatim
//! uint32_t ui32Count;
//!
//! //
//! // Get the transfer count for USB DMA channel 1.
//! //
//! ui32Count = USBDMAChannelCountGet(USB0_BASE, 1);
//! \endverbatim
//!
//! \note This feature is not available on all Tiva devices.  Please
//! check the data sheet to determine if the USB controller has a DMA
//! controller or if it must use the uDMA controller for DMA transfers.
//!
//! \return The current count for a USB DMA channel.
//
//*****************************************************************************
uint32_t
USBDMAChannelCountGet(uint32_t ui32Base, uint32_t ui32Channel)
{
    ASSERT(ui32Base == USB0_BASE);
    ASSERT(ui32Channel < 8);

    //
    // Return the current DMA count.
    //
    return(HWREG(ui32Base + USB_O_DMACOUNT0 + (0x10 * ui32Channel)));
}

//*****************************************************************************
//
//! Returns the available number of integrated USB DMA channels.
//!
//! \param ui32Base specifies the USB module base address.
//!
//! This function returns the total number of DMA channels available when using
//! the integrated USB DMA controller.  This function returns 0 if the
//! integrated controller is not present.
//!
//! \b Example: Get the number of integrated DMA channels.
//!
//! \verbatim
//! uint32_t ui32Count;
//!
//! //
//! // Get the number of integrated DMA channels.
//! //
//! ui32Count = USBDMANumChannels(USB0_BASE);
//! \endverbatim
//!
//! \return The number of integrated USB DMA channels or zero if the
//! integrated USB DMA controller is not present.
//
//*****************************************************************************
uint32_t
USBDMANumChannels(uint32_t ui32Base)
{
    ASSERT(ui32Base == USB0_BASE);

    //
    // Return the number of DMA channels for the integrated DMA controller.
    //
    return(HWREG(ui32Base + USB_O_RAMINFO) >> USB_RAMINFO_DMACHAN_S);
}
//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************
//*****************************************************************************
//
//! \addtogroup usb_ulpi
//! @{
//
//*****************************************************************************

//*****************************************************************************
//
//! Configures the USB controller's ULPI interface.
//!
//! \param ui32Base specifies the USB module base address.
//! \param ui32Config contains the configuration options.
//!
//! This function is used to configure the USB controller's ULPI interface.
//! The configuration options are set in the \e ui32Config parameter and are a
//! logical OR of the following values:
//!
//! - \b USB_ULPI_EXTVBUS enables the external ULPI PHY as the source for VBUS
//!   signaling.
//! - \b USB_ULPI_EXTVBUS_IND enables the external ULPI PHY to detect external
//!   VBUS over-current condition.
//!
//! \b Example: Enable ULPI PHY with full VBUS control.
//!
//! \verbatim
//! //
//! // Enable ULPI PHY with full VBUS control.
//! //
//! USBULPIConfig(USB0_BASE, USB_ULPI_EXTVBUS | USB_ULPI_EXTVBUS_IND);
//! \endverbatim
//!
//! \note The USB ULPI feature is not available on all Tiva devices.
//! Please consult the data sheet for the Tiva device that you
//! are using to determine if this feature is available.
//!
//! \return None.
//
//*****************************************************************************
void
USBULPIConfig(uint32_t ui32Base, uint32_t ui32Config)
{
    HWREGB(ui32Base + USB_O_ULPIVBUSCTL) = (uint8_t)ui32Config;
}

//*****************************************************************************
//
//! Enables the USB controller's ULPI interface.
//!
//! \param ui32Base specifies the USB module base address.
//!
//! This function enables the USB controller's ULPI interface and must be
//! called before attempting to access the ULPI-connected USB PHY.
//!
//! \b Example: Enable ULPI interface.
//!
//! \verbatim
//! //
//! // Enable ULPI interface.
//! //
//! USBULPIEnable(USB0_BASE);
//! \endverbatim
//!
//! \note The USB ULPI feature is not available on all Tiva devices.
//! Please consult the data sheet for the Tiva device that you
//! are using to determine if this feature is available.
//!
//! \return None.
//
//*****************************************************************************
void
USBULPIEnable(uint32_t ui32Base)
{
    HWREG(ui32Base + USB_O_PC) |= USB_PC_ULPIEN;
}

//*****************************************************************************
//
//! Disables the USB controller's ULPI interface.
//!
//! \param ui32Base specifies the USB module base address.
//!
//! This function disables the USB controller's ULPI interface.  Accesses to
//! the ULPI-connected PHY do not succeed after this function has been
//! called.
//!
//! \b Example: Disable ULPI interface.
//!
//! \verbatim
//! //
//! // Disable ULPI interface.
//! //
//! USBULPIDisable(USB0_BASE);
//! \endverbatim
//!
//! \note The USB ULPI feature is not available on all Tiva devices.
//! Please consult the data sheet for the Tiva device that you
//! are using to determine if this feature is available.
//!
//! \return None.
//
//*****************************************************************************
void
USBULPIDisable(uint32_t ui32Base)
{
    HWREG(ui32Base + USB_O_PC) &= ~USB_PC_ULPIEN;
}

//*****************************************************************************
//
//! Reads a register from a ULPI-connected USB PHY.
//!
//! \param ui32Base specifies the USB module base address.
//! \param ui8Reg specifies the register address to read.
//!
//! This function reads the register address specified in the \e ui8Reg
//! parameter using the ULPI interface.  This function is blocking and only
//! returns when the read access completes.  The function does not return if
//! there is not a ULPI-connected USB PHY present.
//!
//! \b Example: Read a register from the ULPI PHY.
//!
//! \verbatim
//! uint8_t ui8Value;
//!
//! //
//! // Read a register from the ULPI PHY register at 0x10.
//! //
//! ui8Value = USBULPIRegRead(USB0_BASE, 0x10);
//! \endverbatim
//!
//! \note The USB ULPI feature is not available on all Tiva devices.
//! Please consult the data sheet for the Tiva device that you
//! are using to determine if this feature is available.
//!
//! \return The value of the requested ULPI register.
//
//*****************************************************************************
uint8_t
USBULPIRegRead(uint32_t ui32Base, uint8_t ui8Reg)
{
    ASSERT(ui32Base == USB0_BASE);

    //
    // Set the register address and initiate a read access.
    //
    HWREGB(ui32Base + USB_O_ULPIREGADDR) = ui8Reg;
    HWREGB(ui32Base + USB_O_ULPIREGCTL) =
        USB_ULPIREGCTL_RDWR | USB_ULPIREGCTL_REGACC;

    //
    // Wait for the access to complete.
    //
    while((HWREGB(ui32Base + USB_O_ULPIREGCTL) & USB_ULPIREGCTL_REGCMPLT) == 0)
    {
    }

    //
    // Clear the register access complete flag.
    //
    HWREGB(ui32Base + USB_O_ULPIREGCTL) = 0;

    return(HWREGB(ui32Base + USB_O_ULPIREGDATA));
}

//*****************************************************************************
//
//! Writes a value to a register on a ULPI-connected USB PHY.
//!
//! \param ui32Base specifies the USB module base address.
//! \param ui8Reg specifies the register address to write.
//! \param ui8Data specifies the data to write.
//!
//! This function writes the register address specified in the \e ui8Reg
//! parameter with the value specified in the \e ui8Data parameter using the
//! ULPI interface.  This function is blocking and only returns when the
//! write access completes.  The function does not return if there is not a
//! ULPI-connected USB PHY present.
//!
//! \b Example: Write a register from the ULPI PHY.
//!
//! \verbatim
//! //
//! // Write the ULPI PHY register at 0x10 with 0x20.
//! //
//! USBULPIRegWrite(USB0_BASE, 0x10, 0x20);
//! \endverbatim
//!
//! \note The USB ULPI feature is not available on all Tiva devices.
//! Please consult the data sheet for the Tiva device that you
//! are using to determine if this feature is available.
//!
//! \return None.
//
//*****************************************************************************
void
USBULPIRegWrite(uint32_t ui32Base, uint8_t ui8Reg, uint8_t ui8Data)
{
    ASSERT(ui32Base == USB0_BASE);

    //
    // Set the register address and initiate a read access.
    //
    HWREGB(ui32Base + USB_O_ULPIREGADDR) = ui8Reg;
    HWREGB(ui32Base + USB_O_ULPIREGDATA) = ui8Data;
    HWREGB(ui32Base + USB_O_ULPIREGCTL) = USB_ULPIREGCTL_REGACC;

    //
    // Wait for the access to complete.
    //
    while((HWREGB(ui32Base + USB_O_ULPIREGCTL) & USB_ULPIREGCTL_REGCMPLT) == 0)
    {
    }

    //
    // Clear the register access complete flag.
    //
    HWREGB(ui32Base + USB_O_ULPIREGCTL) = 0;
}

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************
//*****************************************************************************
//
//! \addtogroup usb_lpm
//! @{
//
//*****************************************************************************

//*****************************************************************************
//
//! Sends an LPM request to a device at a given address and endpoint number.
//!
//! \param ui32Base specifies the USB module base address.
//! \param ui32Address is the target device address for the LPM request.
//! \param ui32Endpoint is the target endpoint for the LPM request.
//!
//! This function sends an LPM request to a connected device in host mode.
//! The \e ui32Address parameter specifies the device address and has a range
//! of values from 1 to 127.   The \e ui32Endpoint parameter specifies the
//! endpoint on the device to which to send the LPM request and must be one of
//! the \b USB_EP_* values. The function returns before the LPM request is
//! sent, requiring the caller to poll the USBLPMIntStatus() function or wait
//! for an interrupt to signal completion of the LPM transaction.  This
//! function must only be called after the USBHostLPMConfig() has configured
//! the LPM transaction settings.
//!
//! \b Example: Send an LPM request to the device at address 1 on endpoint 0.
//!
//! \verbatim
//! //
//! // Send an LPM request to the device at address 1 on endpoint 0.
//! //
//! USBHostLPMSend(USB0_BASE, 1, USB_EP_0);
//! \endverbatim
//!
//! \note The USB LPM feature is not available on all Tiva devices.
//! Please consult the data sheet for the Tiva device that you
//! are using to determine if this feature is available.
//!
//! \return None.
//
//*****************************************************************************
void
USBHostLPMSend(uint32_t ui32Base, uint32_t ui32Address, uint32_t ui32Endpoint)
{
    uint32_t ui32Reg;

    ASSERT(ui32Base == USB0_BASE);
    ASSERT(ui32Address < 127);

    //
    // Set the address and endpoint.
    //
    HWREGB(ui32Base + USB_O_LPMFADDR) = ui32Address;

    ui32Reg = HWREGH(ui32Base + USB_O_LPMATTR) & ~USB_LPMATTR_ENDPT_M;
    ui32Reg |= (USBEPToIndex(ui32Endpoint) << USB_LPMATTR_ENDPT_S);

    HWREGH(ui32Base + USB_O_LPMATTR) = ui32Reg;

    //
    // Send the LPM transaction.
    //
    HWREGB(ui32Base + USB_O_LPMCNTRL) |= USB_LPMCNTRL_TXLPM;
}

//*****************************************************************************
//
//! Sets the global configuration for all LPM requests.
//!
//! \param ui32Base specifies the USB module base address.
//! \param ui32ResumeTime specifies the resume signaling duration in 75us
//! increments.
//! \param ui32Config specifies the combination of configuration options for
//! LPM transactions.
//!
//! This function sets the global configuration options for LPM transactions
//! and must be called at least once before ever calling USBHostLPMSend() to
//! set the configuration parameters for LPM transactions.  The
//! \e ui32ResumeTime specifies the length of time that the host drives resume
//! signaling on the bus in microseconds.  The valid values
//! for \e ui32ResumeTime are from 50us to 1175us in 75us increments.  The
//! remaining configuration is specified by the \e ui32Config parameter and
//! includes the following options:
//!
//! - \b USB_HOST_LPM_RMTWAKE allows the device to signal a remote wake from
//!   the LPM state.
//! - \b USB_HOST_LPM_L1 is the LPM mode to enter and must always be included
//!   in the configuration.
//!
//! \b Example: Set the LPM configuration to allow remote wake with a resume
//! duration of 500us.
//!
//! \verbatim
//! //
//! // Set the LPM configuration to allow remote wake with a resume
//! // duration of 500us.
//! //
//! USBHostLPMConfig(USB0_BASE, 500, USB_HOST_LPM_RMTWAKE | USB_HOST_LPM_L1);
//! \endverbatim
//!
//! \note The USB LPM feature is not available on all Tiva devices.
//! Please consult the data sheet for the Tiva device that you
//! are using to determine if this feature is available.
//!
//! \return None.
//
//*****************************************************************************
void
USBHostLPMConfig(uint32_t ui32Base, uint32_t ui32ResumeTime,
                 uint32_t ui32Config)
{
    ASSERT(ui32Base == USB0_BASE);
    ASSERT(ui32ResumeTime <= 1175);
    ASSERT(ui32ResumeTime >= 50);

    //
    // Set the Host Initiated Resume Duration, Remote wake and Suspend mode.
    //
    HWREGH(ui32Base + USB_O_LPMATTR) =
        ui32Config | ((ui32ResumeTime - 50) / 75) << USB_LPMATTR_HIRD_S;
}

//*****************************************************************************
//
//! Initiates resume signaling to wake a device from LPM suspend mode.
//!
//! \param ui32Base specifies the USB module base address.
//!
//! In host mode, this function initiates resume signaling to wake a device
//! that has entered an LPM-triggered low power mode.  This LPM-triggered low
//! power mode is entered when the USBHostLPMSend() is called to put a specific
//! device into a low power state.
//!
//! \b Example: Initiate resume signaling.
//!
//! \verbatim
//! //
//! // Initiate resume signaling.
//! //
//! USBHostLPMResume(USB0_BASE);
//! \endverbatim
//!
//! \note This function must only be called in host mode.
//!
//! \note The USB LPM feature is not available on all Tiva devices.
//! Please consult the data sheet for the Tiva device that you
//! are using to determine if this feature is available.
//!
//! \return None.
//
//*****************************************************************************
void
USBHostLPMResume(uint32_t ui32Base)
{
    ASSERT(ui32Base == USB0_BASE);

    //
    // Send Resume signaling.
    //
    HWREGB(ui32Base + USB_O_LPMCNTRL) |= USB_LPMCNTRL_RES;
}

//*****************************************************************************
//
//! Initiates remote wake signaling to request the device to leave LPM
//! suspend mode.
//!
//! \param ui32Base specifies the USB module base address.
//!
//! This function initiates remote wake signaling to request that the host
//! wake a device that has entered an LPM-triggered low power mode.
//!
//! \b Example: Initiate remote wake signaling.
//!
//! \verbatim
//! //
//! // Initiate remote wake signaling.
//! //
//! USBDevLPMRemoteWake(USB0_BASE);
//! \endverbatim
//!
//! \note This function must only be called in device mode.
//!
//! \note The USB LPM feature is not available on all Tiva devices.
//! Please consult the data sheet for the Tiva device that you
//! are using to determine if this feature is available.
//!
//! \return None.
//
//*****************************************************************************
void
USBDevLPMRemoteWake(uint32_t ui32Base)
{
    ASSERT(ui32Base == USB0_BASE);

    //
    // Send remote wake signaling.
    //
    HWREGB(ui32Base + USB_O_LPMCNTRL) |= USB_LPMCNTRL_RES;
}

//*****************************************************************************
//
//! Configures the USB device mode response to LPM requests.
//!
//! \param ui32Base specifies the USB module base address.
//! \param ui32Config is the combination of configuration options for LPM
//! transactions in device mode.
//!
//! This function sets the global configuration options for LPM
//! transactions in device mode and must be called before ever calling
//! USBDevLPMEnable() to set the configuration for LPM transactions.  The
//! configuration options in device mode are specified in the \e ui32Config
//! parameter and include one of the following:
//!
//! - \b USB_DEV_LPM_NONE disables the USB controller from responding to LPM
//!   transactions.
//! - \b USB_DEV_LPM_EN enables the USB controller to respond to LPM
//!   and extended transactions.
//! - \b USB_DEV_LPM_EXTONLY enables the USB controller to respond to
//!   extended transactions, but not LPM transactions.
//!
//! The \e ui32Config option can also optionally include the
//! \b USB_DEV_LPM_NAK value to cause the USB controller to NAK all
//! transactions other than an LPM transaction once the USB controller is in
//! LPM suspend mode.  If this value is not included in the \e ui32Config
//! parameter, the USB controller does not respond in suspend mode.
//!
//! The USB controller does not enter LPM suspend mode until the application
//! calls the USBDevLPMEnable() function.
//!
//! \b Example: Enable LPM transactions and NAK while in LPM suspend mode.
//!
//! \verbatim
//! //
//! // Enable LPM transactions and NAK while in LPM suspend mode.
//! //
//! USBDevLPMConfig(USB0_BASE, USB_DEV_LPM_NAK | USB_DEV_LPM_EN);
//! \endverbatim
//!
//! \note The USB LPM feature is not available on all Tiva devices.
//! Please consult the data sheet for the Tiva device that you
//! are using to determine if this feature is available.
//!
//! \return None.
//
//*****************************************************************************
void
USBDevLPMConfig(uint32_t ui32Base, uint32_t ui32Config)
{
    ASSERT(ui32Base == USB0_BASE);

    //
    // Set the device LPM configuration.
    //
    HWREGB(ui32Base + USB_O_LPMCNTRL) = ui32Config;
}

//*****************************************************************************
//
//! Enables the USB controller to respond to LPM suspend requests.
//!
//! \param ui32Base specifies the USB module base address.
//!
//! This function is used to automatically respond to an LPM sleep request from
//! the USB host controller.  If there is no data pending in any transmit
//! FIFOs, then the USB controller acknowledges the packet and enters the
//! LPM L1 state and generate the \b USB_INTLPM_ACK interrupt.  If the USB
//! controller has pending transmit data in at least one FIFO, then the USB
//! controller responds with NYET and signals the \b USB_INTLPM_INCOMPLETE or
//! \b USB_INTLPM_NYET depending on if data is pending in receive or transmit
//! FIFOs.  A call to USBDevLPMEnable() is required after every
//! LPM resume event to re-enable LPM mode.
//!
//! \b Example: Enable LPM suspend mode.
//!
//! \verbatim
//!     //
//!     // Enable LPM suspend mode.
//!     //
//!     USBDevLPMEnable(USB0_BASE);
//! \endverbatim
//!
//! \note The USB LPM feature is not available on all Tiva devices.
//! Please consult the data sheet for the Tiva device that you
//! are using to determine if this feature is available.
//!
//! \return None.
//
//*****************************************************************************
void
USBDevLPMEnable(uint32_t ui32Base)
{
    ASSERT(ui32Base == USB0_BASE);

    //
    // Enable L1 mode on the next LPM transaction.
    //
    HWREGB(ui32Base + USB_O_LPMCNTRL) |=
        USB_LPMCNTRL_EN_LPMEXT | USB_LPMCNTRL_TXLPM;
}

//*****************************************************************************
//
//! Disables the USB controller from responding to LPM suspend requests.
//!
//! \param ui32Base specifies the USB module base address.
//!
//! This function disables the USB controller from responding to LPM
//! transactions.  When the device enters LPM L1 mode, the USB controller
//! automatically disables responding to further LPM transactions.
//!
//! \note If LPM transactions were enabled before calling this function, then
//! an LPM request can still occur before this function returns.  As a result,
//! the application must continue to handle LPM requests until this function
//! returns.
//!
//! \b Example: Disable LPM suspend mode.
//!
//! \verbatim
//!     //
//!     // Disable LPM suspend mode.
//!     //
//!     USBDevLPMDisable(USB0_BASE);
//! \endverbatim
//!
//! \note The USB LPM feature is not available on all Tiva devices.
//! Please consult the data sheet for the Tiva device that you
//! are using to determine if this feature is available.
//!
//! \return None.
//
//*****************************************************************************
void
USBDevLPMDisable(uint32_t ui32Base)
{
    ASSERT(ui32Base == USB0_BASE);

    //
    // Disable auto entering L1 mode on LPM transactions.
    //
    HWREGB(ui32Base + USB_O_LPMCNTRL) &= ~USB_LPMCNTRL_TXLPM;
}

//*****************************************************************************
//
//! Returns the current link state setting.
//!
//! \param ui32Base specifies the USB module base address.
//!
//! This function returns the current link state setting for the USB
//! controller.  When the controller is operating as a host, this link
//! state is sent with an LPM request.  When the controller is acting
//! as a device, this link state was received by the last LPM transaction
//! whether it was acknowledged or stalled because the requested
//! LPM mode is not supported.
//!
//! \b Example: Get the link state for the last LPM transaction.
//!
//! \verbatim
//! uint32_t ui32LinkState;
//!
//! //
//! // Get the endpoint number that received the LPM request.
//! //
//! ui32LinkState = USBLPMLinkStateGet(USB0_BASE);
//!
//! //
//! // Check if this was a supported link state.
//! //
//! if(ui32LinkState == USB_HOST_LPM_L1)
//! {
//!     //
//!     // Handle the supported L1 link state.
//!     //
//! }
//! else
//! {
//!     //
//!     // Handle the unsupported link state.
//!     //
//! }
//! \endverbatim
//!
//! \note The USB LPM feature is not available on all Tiva devices.
//! Please consult the data sheet for the Tiva device that you
//! are using to determine if this feature is available.
//!
//! \return The current LPM link state.
//
//*****************************************************************************
uint32_t
USBLPMLinkStateGet(uint32_t ui32Base)
{
    ASSERT(ui32Base == USB0_BASE);

    return(HWREGH(ui32Base + USB_O_LPMATTR) & USB_LPMATTR_LS_M);
}

//*****************************************************************************
//
//! Returns the current link state setting.
//!
//! \param ui32Base specifies the USB module base address.
//!
//! This function returns the current link state setting for the USB
//! controller.  When the controller is operating as a host, this link
//! state is sent with an LPM request.  When the controller is acting
//! as a device, this link state was received by the last LPM transaction
//! whether it was acknowledged or stalled because the requested
//! LPM mode is not supported.
//!
//! \b Example: Get the link state for the last LPM transaction.
//!
//! \verbatim
//! uint32_t ui32LinkState;
//!
//! //
//! // Get the endpoint number that received the LPM request.
//! //
//! ui32LinkState = USBLPMLinkStateGet(USB0_BASE);
//!
//! //
//! // Check if this was a supported link state.
//! //
//! if(ui32LinkState == USB_HOST_LPM_L1)
//! {
//!     //
//!     // Handle the supported L1 link state.
//!     //
//! }
//! else
//! {
//!     //
//!     // Handle the unsupported link state.
//!     //
//! }
//! \endverbatim
//!
//! \note The USB LPM feature is not available on all Tiva devices.
//! Please consult the data sheet for the Tiva device that you
//! are using to determine if this feature is available.
//!
//! \return The last endpoint to receive an LPM request.
//
//*****************************************************************************
uint32_t
USBLPMEndpointGet(uint32_t ui32Base)
{
    ASSERT(ui32Base == USB0_BASE);

    return((HWREGH(ui32Base + USB_O_LPMATTR) & USB_LPMATTR_ENDPT_M) >>
           USB_LPMATTR_ENDPT_S);
}

//*****************************************************************************
//
//! Returns if remote wake is currently enabled.
//!
//! \param ui32Base specifies the USB module base address.
//!
//! This function returns the current state of the remote wake setting for host
//! or device mode operation.  If the controller is acting as a host this
//! returns the current setting that is sent to devices when LPM requests are
//! sent to a device.  If the controller is in device mode, this returns the
//! state of the last LPM request sent from the host and indicates if the host
//! enabled remote wakeup.
//!
//! \b Example: Issue remote wake if remote wake is enabled.
//!
//! \verbatim
//!
//! if(USBLPMRemoteWakeEnabled(USB0_BASE))
//! {
//!     USBDevLPMRemoteWake(USB0_BASE);
//! }
//!
//! \endverbatim
//!
//! \note The USB LPM feature is not available on all Tiva devices.
//! Please consult the data sheet for the Tiva device that you
//! are using to determine if this feature is available.
//!
//! \return The \b true if remote wake is enabled or \b false if it is not.
//
//*****************************************************************************
bool
USBLPMRemoteWakeEnabled(uint32_t ui32Base)
{
    ASSERT(ui32Base == USB0_BASE);

    if(HWREGH(ui32Base + USB_O_LPMATTR) & USB_LPMATTR_RMTWAK)
    {
        return(true);
    }
    return(false);
}

//*****************************************************************************
//
//! Returns the current LPM interrupt status.
//!
//! \param ui32Base specifies the USB module base address.
//!
//! This function returns the current LPM interrupt status for the USB
//! controller.
//!
//! The valid interrupt status bits when the USB controller is acting as a host
//! are the following:
//!
//! - \b USB_INTLPM_ERROR a bus error occurred in the transmission of an LPM
//!   transaction.
//! - \b USB_INTLPM_RESUME the USB controller has resumed from the LPM low
//!   power state.
//! - \b USB_INTLPM_INCOMPLETE the LPM transaction failed because a timeout
//!   occurred or there were bit errors in the response for three attempts.
//! - \b USB_INTLPM_ACK the device has acknowledged an LPM transaction.
//! - \b USB_INTLPM_NYET the device has responded with a NYET to an LPM
//!   transaction.
//! - \b USB_INTLPM_STALL the device has stalled an LPM transaction.
//!
//! The valid interrupt status bits when the USB controller is acting as a
//! device are the following:
//!
//! - \b USB_INTLPM_ERROR an LPM transaction was received that has an
//!   unsupported link state field.  The transaction was stalled, but the
//!   requested link state can still be read using the USBLPMLinkStateGet()
//!   function.
//! - \b USB_INTLPM_RESUME the USB controller has resumed from the LPM low
//!   power state.
//! - \b USB_INTLPM_INCOMPLETE the USB controller responded to an LPM
//!   transaction with a NYET because data was still in the transmit FIFOs.
//! - \b USB_INTLPM_ACK the USB controller acknowledged an LPM transaction and
//!   is now in the LPM suspend mode.
//! - \b USB_INTLPM_NYET the USB controller responded to an LPM transaction
//!   with a NYET because LPM transactions are not yet enabled by a call to
//!   USBDevLPMEnable().
//! - \b USB_INTLPM_STALL the USB controller has stalled an incoming LPM
//!   transaction.
//!
//! \note This call clears the source of all LPM status interrupts, so the
//! caller must take care to save the value returned because a subsequent call
//! to USBLPMIntStatus() does not return the previous value.
//!
//! \b Example: Get the current LPM interrupt status.
//!
//! \verbatim
//! uint32_t ui32LPMIntStatus;
//!
//! //
//! // Get the current LPM interrupt status.
//! //
//! ui32LPMIntStatus = USBLPMIntStatus(USB0_BASE);
//!
//! //
//! // Check if an LPM transaction was acknowledged.
//! //
//! if(ui32LPMIntStatus & USB_INTLPM_ACK)
//! {
//!     //
//!     // Handle entering LPM suspend mode.
//!     //
//!     ...
//! }
//! \endverbatim
//!
//! \note The USB LPM feature is not available on all Tiva devices.
//! Please consult the data sheet for the Tiva device that you
//! are using to determine if this feature is available.
//!
//! \return The current LPM interrupt status.
//
//*****************************************************************************
uint32_t
USBLPMIntStatus(uint32_t ui32Base)
{
    ASSERT(ui32Base == USB0_BASE);

    //
    // Return the current raw interrupt status.
    //
    return(HWREGB(ui32Base + USB_O_LPMRIS));
}

//*****************************************************************************
//
//! Enables LPM interrupts.
//!
//! \param ui32Base specifies the USB module base address.
//! \param ui32Ints specifies which LPM interrupts to enable.
//!
//! This function enables a set of LPM interrupts so that they can trigger a
//! USB interrupt.  The \e ui32Ints parameter specifies which of the
//! \b USB_INTLPM_* to enable.
//!
//! The valid interrupt status bits when the USB controller is acting as a host
//! are the following:
//!
//! - \b USB_INTLPM_ERROR a bus error occurred in the transmission of an LPM
//!   transaction.
//! - \b USB_INTLPM_RESUME the USB controller has resumed from LPM low power
//!   state.
//! - \b USB_INTLPM_INCOMPLETE the LPM transaction failed because a timeout
//!   occurred or there were bit errors in the response for three attempts.
//! - \b USB_INTLPM_ACK the device has acknowledged an LPM transaction.
//! - \b USB_INTLPM_NYET the device has responded with a NYET to an LPM
//!   transaction.
//! - \b USB_INTLPM_STALL the device has stalled an LPM transaction.
//!
//! The valid interrupt status bits when the USB controller is acting as a
//! device are the following:
//!
//! - \b USB_INTLPM_ERROR an LPM transaction was received that has an
//!   unsupported link state field.  The transaction was stalled, but the
//!   requested link state can still be read using the USBLPMLinkStateGet()
//!   function.
//! - \b USB_INTLPM_RESUME the USB controller has resumed from the LPM low
//!   power state.
//! - \b USB_INTLPM_INCOMPLETE the USB controller responded to an LPM
//!   transaction with a NYET because data was still in the transmit FIFOs.
//! - \b USB_INTLPM_ACK the USB controller acknowledged an LPM transaction and
//!   is now in the LPM suspend mode.
//! - \b USB_INTLPM_NYET the USB controller responded to an LPM transaction
//!   with a NYET because LPM transactions are not yet enabled by a call to
//!   USBDevLPMEnable().
//! - \b USB_INTLPM_STALL the USB controller has stalled an incoming LPM
//!   transaction.
//!
//! \b Example: Enable all LPM interrupt sources.
//!
//! \verbatim
//! //
//! // Enable all LPM interrupt sources.
//! //
//! USBLPMIntEnable(USB0_BASE, USB_INTLPM_ERROR | USB_INTLPM_RESUME |
//!                            USB_INTLPM_INCOMPLETE | USB_INTLPM_ACK |
//!                            USB_INTLPM_NYET | USB_INTLPM_STALL);
//! \endverbatim
//!
//! \note The USB LPM feature is not available on all Tiva devices.
//! Please consult the data sheet for the Tiva device that you
//! are using to determine if this feature is available.
//!
//! \return None.
//
//*****************************************************************************
void
USBLPMIntEnable(uint32_t ui32Base, uint32_t ui32Ints)
{
    ASSERT(ui32Base == USB0_BASE);

    //
    // Enable the requested interrupts.
    //
    HWREGB(ui32Base + USB_O_LPMIM) |= ui32Ints;
}

//*****************************************************************************
//
//! Disables LPM interrupts.
//!
//! \param ui32Base specifies the USB module base address.
//! \param ui32Ints specifies which LPM interrupts to disable.
//!
//! This function disables the LPM interrupts specified in the \e ui32Ints
//! parameter, preventing them from triggering a USB interrupt.
//!
//! The valid interrupt status bits when the USB controller is acting as a host
//! are the following:
//!
//! - \b USB_INTLPM_ERROR a bus error occurred in the transmission of an LPM
//!   transaction.
//! - \b USB_INTLPM_RESUME the USB controller has resumed from LPM low power
//!   state.
//! - \b USB_INTLPM_INCOMPLETE the LPM transaction failed because a timeout
//!   occurred or there were bit errors in the response for three attempts.
//! - \b USB_INTLPM_ACK the device has acknowledged an LPM transaction.
//! - \b USB_INTLPM_NYET the device has responded with a NYET to an LPM
//!   transaction.
//! - \b USB_INTLPM_STALL the device has stalled an LPM transaction.
//!
//! The valid interrupt status bits when the USB controller is acting as a
//! device are the following:
//!
//! - \b USB_INTLPM_ERROR an LPM transaction was received that has an
//!   unsupported link state field.  The transaction was stalled, but the
//!   requested link state can still be read using the USBLPMLinkStateGet()
//!   function.
//! - \b USB_INTLPM_RESUME the USB controller has resumed from the LPM low
//!   power state.
//! - \b USB_INTLPM_INCOMPLETE the USB controller responded to an LPM
//!   transaction with a NYET because data was still in the transmit FIFOs.
//! - \b USB_INTLPM_ACK the USB controller acknowledged an LPM transaction and
//!   is now in the LPM suspend mode.
//! - \b USB_INTLPM_NYET the USB controller responded to an LPM transaction
//!   with a NYET because LPM transactions are not yet enabled by a call to
//!   USBDevLPMEnable().
//! - \b USB_INTLPM_STALL the USB controller has stalled an incoming LPM
//!   transaction.
//!
//! \b Example: Disable all LPM interrupt sources.
//!
//! \verbatim
//! //
//! // Disable all LPM interrupt sources.
//! //
//! USBLPMIntDisable(USB0_BASE, USB_INTLPM_ERROR | USB_INTLPM_RESUME |
//!                             USB_INTLPM_INCOMPLETE | USB_INTLPM_ACK |
//!                             USB_INTLPM_NYET | USB_INTLPM_STALL);
//! \endverbatim
//!
//! \note The USB LPM feature is not available on all Tiva devices.
//! Please consult the data sheet for the Tiva device that you
//! are using to determine if this feature is available.
//!
//! \return None.
//
//*****************************************************************************
void
USBLPMIntDisable(uint32_t ui32Base, uint32_t ui32Ints)
{
    ASSERT(ui32Base == USB0_BASE);

    //
    // Disable the requested interrupts.
    //
    HWREGB(ui32Base + USB_O_LPMIM) &= ~ui32Ints;
}

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************
