//*****************************************************************************
//
// adc.c - Driver for the ADC.
//
// Copyright (c) 2005-2012 Texas Instruments Incorporated.  All rights reserved.
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
//! \addtogroup adc_api
//! @{
//
//*****************************************************************************

#include "inc/hw_adc.h"
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_sysctl.h"
#include "driverlib/adc.h"
#include "driverlib/debug.h"
#include "driverlib/interrupt.h"

//*****************************************************************************
//
// These defines are used by the ADC driver to simplify access to the ADC
// sequencer's registers.
//
//*****************************************************************************
#define ADC_SEQ                 (ADC_O_SSMUX0)
#define ADC_SEQ_STEP            (ADC_O_SSMUX1 - ADC_O_SSMUX0)
#define ADC_SSMUX               (ADC_O_SSMUX0 - ADC_O_SSMUX0)
#define ADC_SSEMUX              (ADC_O_SSEMUX0 - ADC_O_SSMUX0)
#define ADC_SSCTL               (ADC_O_SSCTL0 - ADC_O_SSMUX0)
#define ADC_SSFIFO              (ADC_O_SSFIFO0 - ADC_O_SSMUX0)
#define ADC_SSFSTAT             (ADC_O_SSFSTAT0 - ADC_O_SSMUX0)
#define ADC_SSOP                (ADC_O_SSOP0 - ADC_O_SSMUX0)
#define ADC_SSDC                (ADC_O_SSDC0 - ADC_O_SSMUX0)

//*****************************************************************************
//
// The currently configured software oversampling factor for each of the ADC
// sequencers.
//
//*****************************************************************************
static unsigned char g_pucOversampleFactor[3];

//*****************************************************************************
//
//! Registers an interrupt handler for an ADC interrupt.
//!
//! \param ulBase is the base address of the ADC module.
//! \param ulSequenceNum is the sample sequence number.
//! \param pfnHandler is a pointer to the function to be called when the
//! ADC sample sequence interrupt occurs.
//!
//! This function sets the handler to be called when a sample sequence
//! interrupt occurs.  This function enables the global interrupt in the
//! interrupt controller; the sequence interrupt must be enabled with
//! ADCIntEnable().  It is the interrupt handler's responsibility to clear the
//! interrupt source via ADCIntClear().
//!
//! \sa IntRegister() for important information about registering interrupt
//! handlers.
//!
//! \return None.
//
//*****************************************************************************
void
ADCIntRegister(unsigned long ulBase, unsigned long ulSequenceNum,
               void (*pfnHandler)(void))
{
    unsigned long ulInt;

    //
    // Check the arguments.
    //
    ASSERT((ulBase == ADC0_BASE) || (ulBase == ADC1_BASE));
    ASSERT(ulSequenceNum < 4);

    //
    // Determine the interrupt to register based on the sequence number.
    //
    ulInt = ((ulBase == ADC0_BASE) ? (INT_ADC0SS0 + ulSequenceNum) :
             (INT_ADC1SS0 + ulSequenceNum));

    //
    // Register the interrupt handler.
    //
    IntRegister(ulInt, pfnHandler);

    //
    // Enable the timer interrupt.
    //
    IntEnable(ulInt);
}

//*****************************************************************************
//
//! Unregisters the interrupt handler for an ADC interrupt.
//!
//! \param ulBase is the base address of the ADC module.
//! \param ulSequenceNum is the sample sequence number.
//!
//! This function unregisters the interrupt handler.  This function disables
//! the global interrupt in the interrupt controller; the sequence interrupt
//! must be disabled via ADCIntDisable().
//!
//! \sa IntRegister() for important information about registering interrupt
//! handlers.
//!
//! \return None.
//
//*****************************************************************************
void
ADCIntUnregister(unsigned long ulBase, unsigned long ulSequenceNum)
{
    unsigned long ulInt;

    //
    // Check the arguments.
    //
    ASSERT((ulBase == ADC0_BASE) || (ulBase == ADC1_BASE));
    ASSERT(ulSequenceNum < 4);

    //
    // Determine the interrupt to unregister based on the sequence number.
    //
    ulInt = ((ulBase == ADC0_BASE) ? (INT_ADC0SS0 + ulSequenceNum) :
             (INT_ADC1SS0 + ulSequenceNum));

    //
    // Disable the interrupt.
    //
    IntDisable(ulInt);

    //
    // Unregister the interrupt handler.
    //
    IntUnregister(ulInt);
}

//*****************************************************************************
//
//! Disables a sample sequence interrupt.
//!
//! \param ulBase is the base address of the ADC module.
//! \param ulSequenceNum is the sample sequence number.
//!
//! This function disables the requested sample sequence interrupt.
//!
//! \return None.
//
//*****************************************************************************
void
ADCIntDisable(unsigned long ulBase, unsigned long ulSequenceNum)
{
    //
    // Check the arguments.
    //
    ASSERT((ulBase == ADC0_BASE) || (ulBase == ADC1_BASE));
    ASSERT(ulSequenceNum < 4);

    //
    // Disable this sample sequence interrupt.
    //
    HWREG(ulBase + ADC_O_IM) &= ~(1 << ulSequenceNum);
}

//*****************************************************************************
//
//! Enables a sample sequence interrupt.
//!
//! \param ulBase is the base address of the ADC module.
//! \param ulSequenceNum is the sample sequence number.
//!
//! This function enables the requested sample sequence interrupt.  Any
//! outstanding interrupts are cleared before enabling the sample sequence
//! interrupt.
//!
//! \return None.
//
//*****************************************************************************
void
ADCIntEnable(unsigned long ulBase, unsigned long ulSequenceNum)
{
    //
    // Check the arguments.
    //
    ASSERT((ulBase == ADC0_BASE) || (ulBase == ADC1_BASE));
    ASSERT(ulSequenceNum < 4);

    //
    // Clear any outstanding interrupts on this sample sequence.
    //
    HWREG(ulBase + ADC_O_ISC) = 1 << ulSequenceNum;

    //
    // Enable this sample sequence interrupt.
    //
    HWREG(ulBase + ADC_O_IM) |= 1 << ulSequenceNum;
}

//*****************************************************************************
//
//! Gets the current interrupt status.
//!
//! \param ulBase is the base address of the ADC module.
//! \param ulSequenceNum is the sample sequence number.
//! \param bMasked is false if the raw interrupt status is required and true if
//! the masked interrupt status is required.
//!
//! This function returns the interrupt status for the specified sample
//! sequence. Either the raw interrupt status or the status of interrupts that
//! are allowed to reflect to the processor can be returned.
//!
//! \return The current raw or masked interrupt status.
//
//*****************************************************************************
unsigned long
ADCIntStatus(unsigned long ulBase, unsigned long ulSequenceNum,
             tBoolean bMasked)
{
    unsigned long ulTemp;

    //
    // Check the arguments.
    //
    ASSERT((ulBase == ADC0_BASE) || (ulBase == ADC1_BASE));
    ASSERT(ulSequenceNum < 4);

    //
    // Return either the interrupt status or the raw interrupt status as
    // requested.
    //
    if(bMasked)
    {
        ulTemp = HWREG(ulBase + ADC_O_ISC) & (0x10001 << ulSequenceNum);
    }
    else
    {
        ulTemp = HWREG(ulBase + ADC_O_RIS) & (0x10000 | (1 << ulSequenceNum));

        //
        // If the digital comparator status bit is set, reflect it to the
        // appropriate sequence bit.
        //
        if(ulTemp & 0x10000)
        {
            ulTemp |= 0xF0000;
            ulTemp &= ~(0x10000 << ulSequenceNum);
        }
    }

    //
    // Return the interrupt status
    //
    return(ulTemp);
}

//*****************************************************************************
//
//! Clears sample sequence interrupt source.
//!
//! \param ulBase is the base address of the ADC module.
//! \param ulSequenceNum is the sample sequence number.
//!
//! The specified sample sequence interrupt is cleared, so that it no longer
//! asserts.  This function must be called in the interrupt handler to keep
//! the interrupt from being triggered again immediately upon exit.
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
ADCIntClear(unsigned long ulBase, unsigned long ulSequenceNum)
{
    //
    // Check the arguments.
    //
    ASSERT((ulBase == ADC0_BASE) || (ulBase == ADC1_BASE));
    ASSERT(ulSequenceNum < 4);

    //
    // Clear the interrupt.
    //
    HWREG(ulBase + ADC_O_ISC) = 1 << ulSequenceNum;
}

//*****************************************************************************
//
//! Enables a sample sequence.
//!
//! \param ulBase is the base address of the ADC module.
//! \param ulSequenceNum is the sample sequence number.
//!
//! Allows the specified sample sequence to be captured when its trigger is
//! detected.  A sample sequence must be configured before it is enabled.
//!
//! \return None.
//
//*****************************************************************************
void
ADCSequenceEnable(unsigned long ulBase, unsigned long ulSequenceNum)
{
    //
    // Check the arguments.
    //
    ASSERT((ulBase == ADC0_BASE) || (ulBase == ADC1_BASE));
    ASSERT(ulSequenceNum < 4);

    //
    // Enable the specified sequence.
    //
    HWREG(ulBase + ADC_O_ACTSS) |= 1 << ulSequenceNum;
}

//*****************************************************************************
//
//! Disables a sample sequence.
//!
//! \param ulBase is the base address of the ADC module.
//! \param ulSequenceNum is the sample sequence number.
//!
//! Prevents the specified sample sequence from being captured when its trigger
//! is detected.  A sample sequence should be disabled before it is configured.
//!
//! \return None.
//
//*****************************************************************************
void
ADCSequenceDisable(unsigned long ulBase, unsigned long ulSequenceNum)
{
    //
    // Check the arguments.
    //
    ASSERT((ulBase == ADC0_BASE) || (ulBase == ADC1_BASE));
    ASSERT(ulSequenceNum < 4);

    //
    // Disable the specified sequences.
    //
    HWREG(ulBase + ADC_O_ACTSS) &= ~(1 << ulSequenceNum);
}

//*****************************************************************************
//
//! Configures the trigger source and priority of a sample sequence.
//!
//! \param ulBase is the base address of the ADC module.
//! \param ulSequenceNum is the sample sequence number.
//! \param ulTrigger is the trigger source that initiates the sample sequence;
//! must be one of the \b ADC_TRIGGER_* values.
//! \param ulPriority is the relative priority of the sample sequence with
//! respect to the other sample sequences.
//!
//! This function configures the initiation criteria for a sample sequence.
//! Valid sample sequencers range from zero to three; sequencer zero captures
//! up to eight samples, sequencers one and two capture up to four samples,
//! and sequencer three captures a single sample.  The trigger condition and
//! priority (with respect to other sample sequencer execution) are set.
//!
//! The \e ulTrigger parameter can take on the following values:
//!
//! - \b ADC_TRIGGER_PROCESSOR - A trigger generated by the processor, via the
//!                              ADCProcessorTrigger() function.
//! - \b ADC_TRIGGER_COMP0 - A trigger generated by the first analog
//!                          comparator; configured with ComparatorConfigure().
//! - \b ADC_TRIGGER_COMP1 - A trigger generated by the second analog
//!                          comparator; configured with ComparatorConfigure().
//! - \b ADC_TRIGGER_COMP2 - A trigger generated by the third analog
//!                          comparator; configured with ComparatorConfigure().
//! - \b ADC_TRIGGER_EXTERNAL - A trigger generated by an input from the Port
//!                             B4 pin. Note that some microcontrollers can
//!                             select from any GPIO using the
//!                             GPIOADCTriggerEnable() function.
//! - \b ADC_TRIGGER_TIMER - A trigger generated by a timer; configured with
//!                          TimerControlTrigger().
//! - \b ADC_TRIGGER_PWM0 - A trigger generated by the first PWM generator;
//!                         configured with PWMGenIntTrigEnable().
//! - \b ADC_TRIGGER_PWM1 - A trigger generated by the second PWM generator;
//!                         configured with PWMGenIntTrigEnable().
//! - \b ADC_TRIGGER_PWM2 - A trigger generated by the third PWM generator;
//!                         configured with PWMGenIntTrigEnable().
//! - \b ADC_TRIGGER_PWM3 - A trigger generated by the fourth PWM generator;
//!                         configured with PWMGenIntTrigEnable().
//! - \b ADC_TRIGGER_ALWAYS - A trigger that is always asserted, causing the
//!                           sample sequence to capture repeatedly (so long as
//!                           there is not a higher priority source active).
//!
//! Note that not all trigger sources are available on all Stellaris family
//! members; consult the data sheet for the device in question to determine the
//! availability of triggers.
//!
//! The \e ulPriority parameter is a value between 0 and 3, where 0 represents
//! the highest priority and 3 the lowest.  Note that when programming the
//! priority among a set of sample sequences, each must have unique priority;
//! it is up to the caller to guarantee the uniqueness of the priorities.
//!
//! \return None.
//
//*****************************************************************************
void
ADCSequenceConfigure(unsigned long ulBase, unsigned long ulSequenceNum,
                     unsigned long ulTrigger, unsigned long ulPriority)
{
    //
    // Check the arugments.
    //
    ASSERT((ulBase == ADC0_BASE) || (ulBase == ADC1_BASE));
    ASSERT(ulSequenceNum < 4);
    ASSERT((ulTrigger == ADC_TRIGGER_PROCESSOR) ||
           (ulTrigger == ADC_TRIGGER_COMP0) ||
           (ulTrigger == ADC_TRIGGER_COMP1) ||
           (ulTrigger == ADC_TRIGGER_COMP2) ||
           (ulTrigger == ADC_TRIGGER_EXTERNAL) ||
           (ulTrigger == ADC_TRIGGER_TIMER) ||
           (ulTrigger == ADC_TRIGGER_PWM0) ||
           (ulTrigger == ADC_TRIGGER_PWM1) ||
           (ulTrigger == ADC_TRIGGER_PWM2) ||
           (ulTrigger == ADC_TRIGGER_PWM3) ||
           (ulTrigger == ADC_TRIGGER_ALWAYS));
    ASSERT(ulPriority < 4);

    //
    // Compute the shift for the bits that control this sample sequence.
    //
    ulSequenceNum *= 4;

    //
    // Set the trigger event for this sample sequence.
    //
    HWREG(ulBase + ADC_O_EMUX) = ((HWREG(ulBase + ADC_O_EMUX) &
                                   ~(0xf << ulSequenceNum)) |
                                  ((ulTrigger & 0xf) << ulSequenceNum));

    //
    // Set the priority for this sample sequence.
    //
    HWREG(ulBase + ADC_O_SSPRI) = ((HWREG(ulBase + ADC_O_SSPRI) &
                                    ~(0xf << ulSequenceNum)) |
                                   ((ulPriority & 0x3) << ulSequenceNum));
}

//*****************************************************************************
//
//! Configure a step of the sample sequencer.
//!
//! \param ulBase is the base address of the ADC module.
//! \param ulSequenceNum is the sample sequence number.
//! \param ulStep is the step to be configured.
//! \param ulConfig is the configuration of this step; must be a logical OR of
//! \b ADC_CTL_TS, \b ADC_CTL_IE, \b ADC_CTL_END, \b ADC_CTL_D, one of the
//! input channel selects (\b ADC_CTL_CH0 through \b ADC_CTL_CH23), and one of
//! the digital comparator selects (\b ADC_CTL_CMP0 through \b ADC_CTL_CMP7).
//!
//! This function configures the ADC for one step of a sample sequence.  The
//! ADC can be configured for single-ended or differential operation
//! (the \b ADC_CTL_D bit selects differential operation when set), the
//! channel to be sampled can be chosen (the \b ADC_CTL_CH0 through
//! \b ADC_CTL_CH23 values), and the internal temperature sensor can be
//! selected (the \b ADC_CTL_TS bit).  Additionally, this step can be defined
//! as the last in the sequence (the \b ADC_CTL_END bit) and it can be
//! configured to cause an interrupt when the step is complete (the
//! \b ADC_CTL_IE bit).  If the digital comparators are present on the device,
//! this step may also be configured to send the ADC sample to the selected
//! comparator using \b ADC_CTL_CMP0 through \b ADC_CTL_CMP7. The configuration
//! is used by the ADC at the appropriate time when the trigger for
//! this sequence occurs.
//!
//! \note If the Digital Comparator is present and enabled using the
//! \b ADC_CTL_CMP0 through \b ADC_CTL_CMP7 selects, the ADC sample is NOT
//! written into the ADC sequence data FIFO.
//!
//! The \e ulStep parameter determines the order in which the samples are
//! captured by the ADC when the trigger occurs.  It can range from zero to
//! seven for the first sample sequencer, from zero to three for the second and
//! third sample sequencer, and can only be zero for the fourth sample
//! sequencer.
//!
//! Differential mode only works with adjacent channel pairs (for example, 0
//! and 1).  The channel select must be the number of the channel pair to
//! sample (for example, \b ADC_CTL_CH0 for 0 and 1, or \b ADC_CTL_CH1 for 2
//! and 3) or undefined results are returned by the ADC.  Additionally, if
//! differential mode is selected when the temperature sensor is being sampled,
//! undefined results are returned by the ADC.
//!
//! It is the responsibility of the caller to ensure that a valid configuration
//! is specified; this function does not check the validity of the specified
//! configuration.
//!
//! \return None.
//
//*****************************************************************************
void
ADCSequenceStepConfigure(unsigned long ulBase, unsigned long ulSequenceNum,
                         unsigned long ulStep, unsigned long ulConfig)
{
    unsigned long ulTemp;

    //
    // Check the arguments.
    //
    ASSERT((ulBase == ADC0_BASE) || (ulBase == ADC1_BASE));
    ASSERT(ulSequenceNum < 4);
    ASSERT(((ulSequenceNum == 0) && (ulStep < 8)) ||
           ((ulSequenceNum == 1) && (ulStep < 4)) ||
           ((ulSequenceNum == 2) && (ulStep < 4)) ||
           ((ulSequenceNum == 3) && (ulStep < 1)));

    //
    // Get the offset of the sequence to be configured.
    //
    ulBase += ADC_SEQ + (ADC_SEQ_STEP * ulSequenceNum);

    //
    // Compute the shift for the bits that control this step.
    //
    ulStep *= 4;

    //
    // Set the analog mux value for this step.
    //
    HWREG(ulBase + ADC_SSMUX) = ((HWREG(ulBase + ADC_SSMUX) &
                                  ~(0x0000000f << ulStep)) |
                                 ((ulConfig & 0x0f) << ulStep));

    //
    // Set the upper bits of the analog mux value for this step.
    //
    HWREG(ulBase + ADC_SSEMUX) = ((HWREG(ulBase + ADC_SSEMUX) &
                                  ~(0x0000000f << ulStep)) |
                                  (((ulConfig & 0xf00) >> 8) << ulStep));

    //
    // Set the control value for this step.
    //
    HWREG(ulBase + ADC_SSCTL) = ((HWREG(ulBase + ADC_SSCTL) &
                                  ~(0x0000000f << ulStep)) |
                                 (((ulConfig & 0xf0) >> 4) << ulStep));

    //
    // Enable digital comparator if specified in the ulConfig bit-fields.
    //
    if(ulConfig & 0x000F0000)
    {
        //
        // Program the comparator for the specified step.
        //
        ulTemp = HWREG(ulBase + ADC_SSDC);
        ulTemp &= ~(0xF << ulStep);
        ulTemp |= (((ulConfig & 0x00070000) >> 16) << ulStep);
        HWREG(ulBase + ADC_SSDC) = ulTemp;

        //
        // Enable the comparator.
        //
        ulTemp = HWREG(ulBase + ADC_SSOP);
        ulTemp |= (1 << ulStep);
        HWREG(ulBase + ADC_SSOP) = ulTemp;
    }

    //
    // Disable digital comparator if not specified.
    //
    else
    {
        ulTemp = HWREG(ulBase + ADC_SSOP);
        ulTemp &= ~(1 << ulStep);
        HWREG(ulBase + ADC_SSOP) = ulTemp;
    }
}

//*****************************************************************************
//
//! Determines if a sample sequence overflow occurred.
//!
//! \param ulBase is the base address of the ADC module.
//! \param ulSequenceNum is the sample sequence number.
//!
//! This function determines if a sample sequence overflow has occurred.
//! Overflow happens if the captured samples are not read from the FIFO before
//! the next trigger occurs.
//!
//! \return Returns zero if there was not an overflow, and non-zero if there
//! was.
//
//*****************************************************************************
long
ADCSequenceOverflow(unsigned long ulBase, unsigned long ulSequenceNum)
{
    //
    // Check the arguments.
    //
    ASSERT((ulBase == ADC0_BASE) || (ulBase == ADC1_BASE));
    ASSERT(ulSequenceNum < 4);

    //
    // Determine if there was an overflow on this sequence.
    //
    return(HWREG(ulBase + ADC_O_OSTAT) & (1 << ulSequenceNum));
}

//*****************************************************************************
//
//! Clears the overflow condition on a sample sequence.
//!
//! \param ulBase is the base address of the ADC module.
//! \param ulSequenceNum is the sample sequence number.
//!
//! This function clears an overflow condition on one of the sample sequences.
//! The overflow condition must be cleared in order to detect a subsequent
//! overflow condition (it otherwise causes no harm).
//!
//! \return None.
//
//*****************************************************************************
void
ADCSequenceOverflowClear(unsigned long ulBase, unsigned long ulSequenceNum)
{
    //
    // Check the arguments.
    //
    ASSERT((ulBase == ADC0_BASE) || (ulBase == ADC1_BASE));
    ASSERT(ulSequenceNum < 4);

    //
    // Clear the overflow condition for this sequence.
    //
    HWREG(ulBase + ADC_O_OSTAT) = 1 << ulSequenceNum;
}

//*****************************************************************************
//
//! Determines if a sample sequence underflow occurred.
//!
//! \param ulBase is the base address of the ADC module.
//! \param ulSequenceNum is the sample sequence number.
//!
//! This function determines if a sample sequence underflow has occurred.
//! Underflow happens if too many samples are read from the FIFO.
//!
//! \return Returns zero if there was not an underflow, and non-zero if there
//! was.
//
//*****************************************************************************
long
ADCSequenceUnderflow(unsigned long ulBase, unsigned long ulSequenceNum)
{
    //
    // Check the arguments.
    //
    ASSERT((ulBase == ADC0_BASE) || (ulBase == ADC1_BASE));
    ASSERT(ulSequenceNum < 4);

    //
    // Determine if there was an underflow on this sequence.
    //
    return(HWREG(ulBase + ADC_O_USTAT) & (1 << ulSequenceNum));
}

//*****************************************************************************
//
//! Clears the underflow condition on a sample sequence.
//!
//! \param ulBase is the base address of the ADC module.
//! \param ulSequenceNum is the sample sequence number.
//!
//! This function clears an underflow condition on one of the sample sequencers.
//! The underflow condition must be cleared in order to detect a subsequent
//! underflow condition (it otherwise causes no harm).
//!
//! \return None.
//
//*****************************************************************************
void
ADCSequenceUnderflowClear(unsigned long ulBase, unsigned long ulSequenceNum)
{
    //
    // Check the arguments.
    //
    ASSERT((ulBase == ADC0_BASE) || (ulBase == ADC1_BASE));
    ASSERT(ulSequenceNum < 4);

    //
    // Clear the underflow condition for this sequence.
    //
    HWREG(ulBase + ADC_O_USTAT) = 1 << ulSequenceNum;
}

//*****************************************************************************
//
//! Gets the captured data for a sample sequence.
//!
//! \param ulBase is the base address of the ADC module.
//! \param ulSequenceNum is the sample sequence number.
//! \param pulBuffer is the address where the data is stored.
//!
//! This function copies data from the specified sample sequencer output FIFO
//! to a memory resident buffer.  The number of samples available in the
//! hardware FIFO are copied into the buffer, which is assumed to be large
//! enough to hold that many samples.  This function only returns the samples
//! that are presently available, which may not be the entire sample sequence
//! if it is in the process of being executed.
//!
//! \return Returns the number of samples copied to the buffer.
//
//*****************************************************************************
long
ADCSequenceDataGet(unsigned long ulBase, unsigned long ulSequenceNum,
                   unsigned long *pulBuffer)
{
    unsigned long ulCount;

    //
    // Check the arguments.
    //
    ASSERT((ulBase == ADC0_BASE) || (ulBase == ADC1_BASE));
    ASSERT(ulSequenceNum < 4);

    //
    // Get the offset of the sequence to be read.
    //
    ulBase += ADC_SEQ + (ADC_SEQ_STEP * ulSequenceNum);

    //
    // Read samples from the FIFO until it is empty.
    //
    ulCount = 0;
    while(!(HWREG(ulBase + ADC_SSFSTAT) & ADC_SSFSTAT0_EMPTY) && (ulCount < 8))
    {
        //
        // Read the FIFO and copy it to the destination.
        //
        *pulBuffer++ = HWREG(ulBase + ADC_SSFIFO);

        //
        // Increment the count of samples read.
        //
        ulCount++;
    }

    //
    // Return the number of samples read.
    //
    return(ulCount);
}

//*****************************************************************************
//
//! Causes a processor trigger for a sample sequence.
//!
//! \param ulBase is the base address of the ADC module.
//! \param ulSequenceNum is the sample sequence number, with
//! \b ADC_TRIGGER_WAIT or \b ADC_TRIGGER_SIGNAL optionally ORed into it.
//!
//! This function triggers a processor-initiated sample sequence if the sample
//! sequence trigger is configured to \b ADC_TRIGGER_PROCESSOR.  If
//! \b ADC_TRIGGER_WAIT is ORed into the sequence number, the
//! processor-initiated trigger is delayed until a later processor-initiated
//! trigger to a different ADC module that specifies \b ADC_TRIGGER_SIGNAL,
//! allowing multiple ADCs to start from a processor-initiated trigger in a
//! synchronous manner.
//!
//! \return None.
//
//*****************************************************************************
void
ADCProcessorTrigger(unsigned long ulBase, unsigned long ulSequenceNum)
{
    //
    // Check the arguments.
    //
    ASSERT((ulBase == ADC0_BASE) || (ulBase == ADC1_BASE));
    ASSERT((ulSequenceNum & 0xf) < 4);

    //
    // Generate a processor trigger for this sample sequence.
    //
    HWREG(ulBase + ADC_O_PSSI) |= ((ulSequenceNum & 0xffff0000) |
                                   (1 << (ulSequenceNum & 0xf)));
}

//*****************************************************************************
//
//! Configures the software oversampling factor of the ADC.
//!
//! \param ulBase is the base address of the ADC module.
//! \param ulSequenceNum is the sample sequence number.
//! \param ulFactor is the number of samples to be averaged.
//!
//! This function configures the software oversampling for the ADC, which can
//! be used to provide better resolution on the sampled data.  Oversampling is
//! accomplished by averaging multiple samples from the same analog input.
//! Three different oversampling rates are supported; 2x, 4x, and 8x.
//!
//! Oversampling is only supported on the sample sequencers that are more than
//! one sample in depth (that is, the fourth sample sequencer is not
//! supported).  Oversampling by 2x (for example) divides the depth of the
//! sample sequencer by two; so 2x oversampling on the first sample sequencer
//! can only provide four samples per trigger.  This also means that 8x
//! oversampling is only available on the first sample sequencer.
//!
//! \return None.
//
//*****************************************************************************
void
ADCSoftwareOversampleConfigure(unsigned long ulBase,
                               unsigned long ulSequenceNum,
                               unsigned long ulFactor)
{
    unsigned long ulValue;

    //
    // Check the arguments.
    //
    ASSERT((ulBase == ADC0_BASE) || (ulBase == ADC1_BASE));
    ASSERT(ulSequenceNum < 3);
    ASSERT(((ulFactor == 2) || (ulFactor == 4) || (ulFactor == 8)) &&
           ((ulSequenceNum == 0) || (ulFactor != 8)));

    //
    // Convert the oversampling factor to a shift factor.
    //
    for(ulValue = 0, ulFactor >>= 1; ulFactor; ulValue++, ulFactor >>= 1)
    {
    }

    //
    // Save the shift factor.
    //
    g_pucOversampleFactor[ulSequenceNum] = ulValue;
}

//*****************************************************************************
//
//! Configures a step of the software oversampled sequencer.
//!
//! \param ulBase is the base address of the ADC module.
//! \param ulSequenceNum is the sample sequence number.
//! \param ulStep is the step to be configured.
//! \param ulConfig is the configuration of this step.
//!
//! This function configures a step of the sample sequencer when using the
//! software oversampling feature.  The number of steps available depends on
//! the oversampling factor set by ADCSoftwareOversampleConfigure().  The value
//! of \e ulConfig is the same as defined for ADCSequenceStepConfigure().
//!
//! \return None.
//
//*****************************************************************************
void
ADCSoftwareOversampleStepConfigure(unsigned long ulBase,
                                   unsigned long ulSequenceNum,
                                   unsigned long ulStep,
                                   unsigned long ulConfig)
{
    //
    // Check the arguments.
    //
    ASSERT((ulBase == ADC0_BASE) || (ulBase == ADC1_BASE));
    ASSERT(ulSequenceNum < 3);
    ASSERT(((ulSequenceNum == 0) &&
            (ulStep < (8 >> g_pucOversampleFactor[ulSequenceNum]))) ||
           (ulStep < (4 >> g_pucOversampleFactor[ulSequenceNum])));

    //
    // Get the offset of the sequence to be configured.
    //
    ulBase += ADC_SEQ + (ADC_SEQ_STEP * ulSequenceNum);

    //
    // Compute the shift for the bits that control this step.
    //
    ulStep *= 4 << g_pucOversampleFactor[ulSequenceNum];

    //
    // Loop through the hardware steps that make up this step of the software
    // oversampled sequence.
    //
    for(ulSequenceNum = 1 << g_pucOversampleFactor[ulSequenceNum];
        ulSequenceNum; ulSequenceNum--)
    {
        //
        // Set the analog mux value for this step.
        //
        HWREG(ulBase + ADC_SSMUX) = ((HWREG(ulBase + ADC_SSMUX) &
                                      ~(0x0000000f << ulStep)) |
                                     ((ulConfig & 0x0f) << ulStep));

        //
        // Set the upper bits of the analog mux value for this step.
        //
        HWREG(ulBase + ADC_SSEMUX) = ((HWREG(ulBase + ADC_SSEMUX) &
                                      ~(0x0000000f << ulStep)) |
                                      (((ulConfig & 0xf00) >> 8) << ulStep));

        //
        // Set the control value for this step.
        //
        HWREG(ulBase + ADC_SSCTL) = ((HWREG(ulBase + ADC_SSCTL) &
                                      ~(0x0000000f << ulStep)) |
                                     (((ulConfig & 0xf0) >> 4) << ulStep));
        if(ulSequenceNum != 1)
        {
            HWREG(ulBase + ADC_SSCTL) &= ~((ADC_SSCTL0_IE0 |
                                            ADC_SSCTL0_END0) << ulStep);
        }

        //
        // Go to the next hardware step.
        //
        ulStep += 4;
    }
}

//*****************************************************************************
//
//! Gets the captured data for a sample sequence using software oversampling.
//!
//! \param ulBase is the base address of the ADC module.
//! \param ulSequenceNum is the sample sequence number.
//! \param pulBuffer is the address where the data is stored.
//! \param ulCount is the number of samples to be read.
//!
//! This function copies data from the specified sample sequence output FIFO to
//! a memory resident buffer with software oversampling applied.  The requested
//! number of samples are copied into the data buffer; if there are not enough
//! samples in the hardware FIFO to satisfy this many oversampled data items,
//! then incorrect results are returned.  It is the caller's responsibility to
//! read only the samples that are available and wait until enough data is
//! available, for example as a result of receiving an interrupt.
//!
//! \return None.
//
//*****************************************************************************
void
ADCSoftwareOversampleDataGet(unsigned long ulBase, unsigned long ulSequenceNum,
                             unsigned long *pulBuffer, unsigned long ulCount)
{
    unsigned long ulIdx, ulAccum;

    //
    // Check the arguments.
    //
    ASSERT((ulBase == ADC0_BASE) || (ulBase == ADC1_BASE));
    ASSERT(ulSequenceNum < 3);
    ASSERT(((ulSequenceNum == 0) &&
            (ulCount < (8 >> g_pucOversampleFactor[ulSequenceNum]))) ||
           (ulCount < (4 >> g_pucOversampleFactor[ulSequenceNum])));

    //
    // Get the offset of the sequence to be read.
    //
    ulBase += ADC_SEQ + (ADC_SEQ_STEP * ulSequenceNum);

    //
    // Read the samples from the FIFO until it is empty.
    //
    while(ulCount--)
    {
        //
        // Compute the sum of the samples.
        //
        ulAccum = 0;
        for(ulIdx = 1 << g_pucOversampleFactor[ulSequenceNum]; ulIdx; ulIdx--)
        {
            //
            // Read the FIFO and add it to the accumulator.
            //
            ulAccum += HWREG(ulBase + ADC_SSFIFO);
        }

        //
        // Write the averaged sample to the output buffer.
        //
        *pulBuffer++ = ulAccum >> g_pucOversampleFactor[ulSequenceNum];
    }
}

//*****************************************************************************
//
//! Configures the hardware oversampling factor of the ADC.
//!
//! \param ulBase is the base address of the ADC module.
//! \param ulFactor is the number of samples to be averaged.
//!
//! This function configures the hardware oversampling for the ADC, which can
//! be used to provide better resolution on the sampled data.  Oversampling is
//! accomplished by averaging multiple samples from the same analog input.  Six
//! different oversampling rates are supported; 2x, 4x, 8x, 16x, 32x, and 64x.
//! Specifying an oversampling factor of zero disables hardware
//! oversampling.
//!
//! Hardware oversampling applies uniformly to all sample sequencers.  It does
//! not reduce the depth of the sample sequencers like the software
//! oversampling APIs; each sample written into the sample sequencer FIFO is a
//! fully oversampled analog input reading.
//!
//! Enabling hardware averaging increases the precision of the ADC at the cost
//! of throughput.  For example, enabling 4x oversampling reduces the
//! throughput of a 250 K samples/second ADC to 62.5 K samples/second.
//!
//! \return None.
//
//*****************************************************************************
void
ADCHardwareOversampleConfigure(unsigned long ulBase, unsigned long ulFactor)
{
    unsigned long ulValue;

    //
    // Check the arguments.
    //
    ASSERT((ulBase == ADC0_BASE) || (ulBase == ADC1_BASE));
    ASSERT(((ulFactor == 0) || (ulFactor == 2) || (ulFactor == 4) ||
           (ulFactor == 8) || (ulFactor == 16) || (ulFactor == 32) ||
           (ulFactor == 64)));

    //
    // Convert the oversampling factor to a shift factor.
    //
    for(ulValue = 0, ulFactor >>= 1; ulFactor; ulValue++, ulFactor >>= 1)
    {
    }

    //
    // Write the shift factor to the ADC to configure the hardware oversampler.
    //
    HWREG(ulBase + ADC_O_SAC) = ulValue;
}

//*****************************************************************************
//
//! Configures an ADC digital comparator.
//!
//! \param ulBase is the base address of the ADC module.
//! \param ulComp is the index of the comparator to configure.
//! \param ulConfig is the configuration of the comparator.
//!
//! This function configures a comparator.  The \e ulConfig parameter is
//! the result of a logical OR operation between the \b ADC_COMP_TRIG_xxx, and
//! \b ADC_COMP_INT_xxx values.
//!
//! The \b ADC_COMP_TRIG_xxx term can take on the following values:
//!
//! - \b ADC_COMP_TRIG_NONE to never trigger PWM fault condition.
//! - \b ADC_COMP_TRIG_LOW_ALWAYS to always trigger PWM fault condition when
//! ADC output is in the low-band.
//! - \b ADC_COMP_TRIG_LOW_ONCE to trigger PWM fault condition once when ADC
//! output transitions into the low-band.
//! - \b ADC_COMP_TRIG_LOW_HALWAYS to always trigger PWM fault condition when
//! ADC output is in the low-band only if ADC output has been in the high-band
//! since the last trigger output.
//! - \b ADC_COMP_TRIG_LOW_HONCE to trigger PWM fault condition once when ADC
//! output transitions into low-band only if ADC output has been in the
//! high-band since the last trigger output.
//! - \b ADC_COMP_TRIG_MID_ALWAYS to always trigger PWM fault condition when
//! ADC output is in the mid-band.
//! - \b ADC_COMP_TRIG_MID_ONCE to trigger PWM fault condition once when ADC
//! output transitions into the mid-band.
//! - \b ADC_COMP_TRIG_HIGH_ALWAYS to always trigger PWM fault condition when
//! ADC output is in the high-band.
//! - \b ADC_COMP_TRIG_HIGH_ONCE to trigger PWM fault condition once when ADC
//! output transitions into the high-band.
//! - \b ADC_COMP_TRIG_HIGH_HALWAYS to always trigger PWM fault condition when
//! ADC output is in the high-band only if ADC output has been in the low-band
//! since the last trigger output.
//! - \b ADC_COMP_TRIG_HIGH_HONCE to trigger PWM fault condition once when ADC
//! output transitions into high-band only if ADC output has been in the
//! low-band since the last trigger output.
//!
//! The \b ADC_COMP_INT_xxx term can take on the following values:
//!
//! - \b ADC_COMP_INT_NONE to never generate ADC interrupt.
//! - \b ADC_COMP_INT_LOW_ALWAYS to always generate ADC interrupt when ADC
//! output is in the low-band.
//! - \b ADC_COMP_INT_LOW_ONCE to generate ADC interrupt once when ADC output
//! transitions into the low-band.
//! - \b ADC_COMP_INT_LOW_HALWAYS to always generate ADC interrupt when ADC
//! output is in the low-band only if ADC output has been in the high-band
//! since the last trigger output.
//! - \b ADC_COMP_INT_LOW_HONCE to generate ADC interrupt once when ADC output
//! transitions into low-band only if ADC output has been in the high-band
//! since the last trigger output.
//! - \b ADC_COMP_INT_MID_ALWAYS to always generate ADC interrupt when ADC
//! output is in the mid-band.
//! - \b ADC_COMP_INT_MID_ONCE to generate ADC interrupt once when ADC output
//! transitions into the mid-band.
//! - \b ADC_COMP_INT_HIGH_ALWAYS to always generate ADC interrupt when ADC
//! output is in the high-band.
//! - \b ADC_COMP_INT_HIGH_ONCE to generate ADC interrupt once when ADC output
//! transitions into the high-band.
//! - \b ADC_COMP_INT_HIGH_HALWAYS to always generate ADC interrupt when ADC
//! output is in the high-band only if ADC output has been in the low-band
//! since the last trigger output.
//! - \b ADC_COMP_INT_HIGH_HONCE to generate ADC interrupt once when ADC output
//! transitions into high-band only if ADC output has been in the low-band
//! since the last trigger output.
//!
//! \return None.
//
//*****************************************************************************
void
ADCComparatorConfigure(unsigned long ulBase, unsigned long ulComp,
                       unsigned long ulConfig)
{
    //
    // Check the arguments.
    //
    ASSERT((ulBase == ADC0_BASE) || (ulBase == ADC1_BASE));
    ASSERT(ulComp < 8);

    //
    // Save the new setting.
    //
    HWREG(ulBase + ADC_O_DCCTL0 + (ulComp * 4)) = ulConfig;
}

//*****************************************************************************
//
//! Defines the ADC digital comparator regions.
//!
//! \param ulBase is the base address of the ADC module.
//! \param ulComp is the index of the comparator to configure.
//! \param ulLowRef is the reference point for the low/mid band threshold.
//! \param ulHighRef is the reference point for the mid/high band threshold.
//!
//! The ADC digital comparator operation is based on three ADC value regions:
//! - \b low-band is defined as any ADC value less than or equal to the
//! \e ulLowRef value.
//! - \b mid-band is defined as any ADC value greater than the \e ulLowRef
//! value but less than or equal to the \e ulHighRef value.
//! - \b high-band is defined as any ADC value greater than the \e ulHighRef
//! value.
//!
//! \return None.
//
//*****************************************************************************
void
ADCComparatorRegionSet(unsigned long ulBase, unsigned long ulComp,
                       unsigned long ulLowRef, unsigned long ulHighRef)
{
    //
    // Check the arguments.
    //
    ASSERT((ulBase == ADC0_BASE) || (ulBase == ADC1_BASE));
    ASSERT(ulComp < 8);
    ASSERT((ulLowRef < 1024) && (ulLowRef <= ulHighRef));
    ASSERT(ulHighRef < 1024);

    //
    // Save the new region settings.
    //
    HWREG(ulBase + ADC_O_DCCMP0 + (ulComp * 4)) = (ulHighRef << 16) | ulLowRef;
}

//*****************************************************************************
//
//! Resets the current ADC digital comparator conditions.
//!
//! \param ulBase is the base address of the ADC module.
//! \param ulComp is the index of the comparator.
//! \param bTrigger is the flag to indicate reset of Trigger conditions.
//! \param bInterrupt is the flag to indicate reset of Interrupt conditions.
//!
//! Because the digital comparator uses current and previous ADC values, this
//! function allows the comparator to be reset to its initial
//! value to prevent stale data from being used when a sequence is enabled.
//!
//! \return None.
//
//*****************************************************************************
void
ADCComparatorReset(unsigned long ulBase, unsigned long ulComp,
                   tBoolean bTrigger, tBoolean bInterrupt)
{
    unsigned long ulTemp = 0;

    //
    // Check the arguments.
    //
    ASSERT((ulBase == ADC0_BASE) || (ulBase == ADC1_BASE));
    ASSERT(ulComp < 8);

    //
    // Set the appropriate bits to reset the trigger and/or interrupt
    // comparator conditions.
    //
    if(bTrigger)
    {
        ulTemp |= (1 << (16 + ulComp));
    }
    if(bInterrupt)
    {
        ulTemp |= (1 << ulComp);
    }

    HWREG(ulBase + ADC_O_DCRIC) = ulTemp;
}

//*****************************************************************************
//
//! Disables a sample sequence comparator interrupt.
//!
//! \param ulBase is the base address of the ADC module.
//! \param ulSequenceNum is the sample sequence number.
//!
//! This function disables the requested sample sequence comparator interrupt.
//!
//! \return None.
//
//*****************************************************************************
void
ADCComparatorIntDisable(unsigned long ulBase, unsigned long ulSequenceNum)
{
    //
    // Check the arguments.
    //
    ASSERT((ulBase == ADC0_BASE) || (ulBase == ADC1_BASE));
    ASSERT(ulSequenceNum < 4);

    //
    // Disable this sample sequence comparator interrupt.
    //
    HWREG(ulBase + ADC_O_IM) &= ~(0x10000 << ulSequenceNum);
}

//*****************************************************************************
//
//! Enables a sample sequence comparator interrupt.
//!
//! \param ulBase is the base address of the ADC module.
//! \param ulSequenceNum is the sample sequence number.
//!
//! This function enables the requested sample sequence comparator interrupt.
//!
//! \return None.
//
//*****************************************************************************
void
ADCComparatorIntEnable(unsigned long ulBase, unsigned long ulSequenceNum)
{
    //
    // Check the arguments.
    //
    ASSERT((ulBase == ADC0_BASE) || (ulBase == ADC1_BASE));
    ASSERT(ulSequenceNum < 4);

    //
    // Enable this sample sequence interrupt.
    //
    HWREG(ulBase + ADC_O_IM) |= 0x10000 << ulSequenceNum;
}

//*****************************************************************************
//
//! Gets the current comparator interrupt status.
//!
//! \param ulBase is the base address of the ADC module.
//!
//! This function returns the digital comparator interrupt status bits.  This
//! status is sequence agnostic.
//!
//! \return The current comparator interrupt status.
//
//*****************************************************************************
unsigned long
ADCComparatorIntStatus(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT((ulBase == ADC0_BASE) || (ulBase == ADC1_BASE));

    //
    // Return the digital comparator interrupt status.
    //
    return(HWREG(ulBase + ADC_O_DCISC));
}

//*****************************************************************************
//
//! Clears sample sequence comparator interrupt source.
//!
//! \param ulBase is the base address of the ADC module.
//! \param ulStatus is the bit-mapped interrupts status to clear.
//!
//! The specified interrupt status is cleared.
//!
//! \return None.
//
//*****************************************************************************
void
ADCComparatorIntClear(unsigned long ulBase, unsigned long ulStatus)
{
    //
    // Check the arguments.
    //
    ASSERT((ulBase == ADC0_BASE) || (ulBase == ADC1_BASE));

    //
    // Clear the interrupt.
    //
    HWREG(ulBase + ADC_O_DCISC) = ulStatus;
}

//*****************************************************************************
//
//! Selects the ADC reference.
//!
//! \param ulBase is the base address of the ADC module.
//! \param ulRef is the reference to use.
//!
//! The ADC reference is set as specified by \e ulRef.  It must be one of
//! \b ADC_REF_INT, \b ADC_REF_EXT_3V, or \b ADC_REF_EXT_1V for internal or
//! external reference.  If \b ADC_REF_INT is chosen, then an internal 3V
//! reference is used and no external reference is needed.  If
//! \b ADC_REF_EXT_3V is chosen, then a 3V reference must be supplied to the
//! AVREF pin.  If \b ADC_REF_EXT_1V is chosen, then a 1V external reference
//! must be supplied to the AVREF pin.
//!
//! \note The ADC reference can only be selected on parts that have an external
//! reference.  Consult the data sheet for your part to determine if there is
//! an external reference.
//!
//! \return None.
//
//*****************************************************************************
void
ADCReferenceSet(unsigned long ulBase, unsigned long ulRef)
{
    //
    // Check the arguments.
    //
    ASSERT((ulBase == ADC0_BASE) || (ulBase == ADC1_BASE));
    ASSERT((ulRef == ADC_REF_INT) || (ulRef == ADC_REF_EXT_3V) ||
           (ulRef == ADC_REF_EXT_1V));

    //
    // Set the reference.
    //
    HWREG(ulBase + ADC_O_CTL) = (HWREG(ulBase + ADC_O_CTL) & ~ADC_CTL_VREF_M) |
                                ulRef;
}

//*****************************************************************************
//
//! Returns the current setting of the ADC reference.
//!
//! \param ulBase is the base address of the ADC module.
//!
//! Returns the value of the ADC reference setting.  The returned value is one
//! of \b ADC_REF_INT, \b ADC_REF_EXT_3V, or \b ADC_REF_EXT_1V.
//!
//! \note The value returned by this function is only meaningful if used on a
//! part that is capable of using an external reference.  Consult the data
//! sheet for your part to determine if it has an external reference input.
//!
//! \return The current setting of the ADC reference.
//
//*****************************************************************************
unsigned long
ADCReferenceGet(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT((ulBase == ADC0_BASE) || (ulBase == ADC1_BASE));

    //
    // Return the value of the reference.
    //
    return(HWREG(ulBase + ADC_O_CTL) & ADC_CTL_VREF_M);
}

//*****************************************************************************
//
//! Selects the ADC resolution.
//!
//! \param ulBase is the base address of the ADC module.
//! \param ulResolution is the ADC bit resolution.
//!
//! The ADC resolution is set as specified by \e ulResolution.  It must be one
//! of \b ADC_RES_12BIT or \b ADC_RES_10BIT.
//!
//! \note The ADC resolution can only be set on parts that are capable of
//! changing ADC resolution mode.  Consult the data sheet for your part to
//! determine if it is capable of operating in more than one resolution mode.
//!
//! \return None.
//
//*****************************************************************************
void
ADCResolutionSet(unsigned long ulBase, unsigned long ulResolution)
{
    //
    // Check the arguments.
    //
    ASSERT((ulBase == ADC0_BASE) || (ulBase == ADC1_BASE));
    ASSERT((ulResolution == ADC_RES_10BIT) || (ulResolution == ADC_RES_12BIT));

    //
    // Set the resolution.
    //
    HWREG(ulBase + ADC_O_CTL) = (HWREG(ulBase + ADC_O_CTL) & ~ADC_CTL_RES) |
                                ulResolution;
}

//*****************************************************************************
//
//! Gets the setting of ADC resolution.
//!
//! \param ulBase is the base address of the ADC module.
//!
//! The ADC resolution is returned as one of \b ADC_RES_12BIT or
//! \b ADC_RES_10BIT.
//!
//! \note The value returned by this function is only meaningful if used on a
//! part that is capable of changing ADC resolution mode.  Consult the
//! data sheet for your part to determine if it is capable of operating in
//! more than one resolution mode.
//!
//! \return The current setting of the ADC resolution.
//
//*****************************************************************************
unsigned long
ADCResolutionGet(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT((ulBase == ADC0_BASE) || (ulBase == ADC1_BASE));

    //
    // Get the resolution and return it to the caller.
    //
    return(HWREG(ulBase + ADC_O_CTL) & ADC_CTL_RES);
}

//*****************************************************************************
//
//! Sets the phase delay between a trigger and the start of a sequence.
//!
//! \param ulBase is the base address of the ADC module.
//! \param ulPhase is the phase delay, specified as one of \b ADC_PHASE_0,
//! \b ADC_PHASE_22_5, \b ADC_PHASE_45, \b ADC_PHASE_67_5, \b ADC_PHASE_90,
//! \b ADC_PHASE_112_5, \b ADC_PHASE_135, \b ADC_PHASE_157_5, \b ADC_PHASE_180,
//! \b ADC_PHASE_202_5, \b ADC_PHASE_225, \b ADC_PHASE_247_5, \b ADC_PHASE_270,
//! \b ADC_PHASE_292_5, \b ADC_PHASE_315, or \b ADC_PHASE_337_5.
//!
//! This function sets the phase delay between the detection of an ADC trigger
//! event and the start of the sample sequence.  By selecting a different phase
//! delay for a pair of ADC modules (such as \b ADC_PHASE_0 and
//! \b ADC_PHASE_180) and having each ADC module sample the same analog input,
//! it is possible to increase the sampling rate of the analog input (with
//! samples N, N+2, N+4, and so on, coming from the first ADC and samples N+1,
//! N+3, N+5, and so on, coming from the second ADC).  The ADC module has a
//! single phase delay that is applied to all sample sequences within that
//! module.
//!
//! \note This capability is not available on all parts.
//!
//! \return None.
//
//*****************************************************************************
void
ADCPhaseDelaySet(unsigned long ulBase, unsigned long ulPhase)
{
    //
    // Check the arguments.
    //
    ASSERT((ulBase == ADC0_BASE) || (ulBase == ADC1_BASE));
    ASSERT((ulPhase == ADC_PHASE_0) || (ulPhase == ADC_PHASE_22_5) ||
           (ulPhase == ADC_PHASE_45) || (ulPhase == ADC_PHASE_67_5) ||
           (ulPhase == ADC_PHASE_90) || (ulPhase == ADC_PHASE_112_5) ||
           (ulPhase == ADC_PHASE_135) || (ulPhase == ADC_PHASE_157_5) ||
           (ulPhase == ADC_PHASE_180) || (ulPhase == ADC_PHASE_202_5) ||
           (ulPhase == ADC_PHASE_225) || (ulPhase == ADC_PHASE_247_5) ||
           (ulPhase == ADC_PHASE_270) || (ulPhase == ADC_PHASE_292_5) ||
           (ulPhase == ADC_PHASE_315) || (ulPhase == ADC_PHASE_337_5));

    //
    // Set the phase delay.
    //
    HWREG(ulBase + ADC_O_SPC) = ulPhase;
}

//*****************************************************************************
//
//! Gets the phase delay between a trigger and the start of a sequence.
//!
//! \param ulBase is the base address of the ADC module.
//!
//! This function gets the current phase delay between the detection of an ADC
//! trigger event and the start of the sample sequence.
//!
//! \return Returns the phase delay, specified as one of \b ADC_PHASE_0,
//! \b ADC_PHASE_22_5, \b ADC_PHASE_45, \b ADC_PHASE_67_5, \b ADC_PHASE_90,
//! \b ADC_PHASE_112_5, \b ADC_PHASE_135, \b ADC_PHASE_157_5, \b ADC_PHASE_180,
//! \b ADC_PHASE_202_5, \b ADC_PHASE_225, \b ADC_PHASE_247_5, \b ADC_PHASE_270,
//! \b ADC_PHASE_292_5, \b ADC_PHASE_315, or \b ADC_PHASE_337_5.
//
//*****************************************************************************
unsigned long
ADCPhaseDelayGet(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT((ulBase == ADC0_BASE) || (ulBase == ADC1_BASE));

    //
    // Return the phase delay.
    //
    return(HWREG(ulBase + ADC_O_SPC));
}

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************
