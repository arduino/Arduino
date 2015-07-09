/******************************************************************************
*  Filename:       event.h
*  Revised:        2015-02-10 16:20:36 +0100 (ti, 10 feb 2015)
*  Revision:       42636
*
*  Description:    Defines and prototypes for the Event Handler.
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

//*****************************************************************************
//
//! \addtogroup event_api
//! @{
//
//*****************************************************************************

#ifndef __EVENT_H__
#define __EVENT_H__

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

#include <stdbool.h>
#include <stdint.h>
#include <inc/hw_types.h>
#include <inc/hw_memmap.h>
#include <inc/hw_event.h>
#include <driverlib/debug.h>

//*****************************************************************************
//
// Common input event list for the event module
//
//*****************************************************************************
#define EVENT_ALWAYS_0                   0  // Unused - always '0'
#define EVENT_AON_PROG_0                 1  // AON Programmable 0
#define EVENT_AON_PROG_1                 2  // AON Programmable 1
#define EVENT_AON_PROG_2                 3  // AON Programmable 2
#define EVENT_AON_EDGE_DETECT            4  // AON Edge Detect
#define EVENT_AON_SPIS_RTX               5  // AON SPIS RTX
#define EVENT_AON_SPIS_CS                6  // AON SPIS Chip Select
#define EVENT_AON_RTCCOMDLY              7  // AON Real Time Clock Combined Delayed
#define EVENT_AUX_SM                     8  // AUX State Machine
#define EVENT_I2C_INTERRUPT              9  // I2C Interrupt
#define EVENT_AON_AUX0                  10  // AON event for AUX
#define EVENT_PTIM_RTX                  11  // MCU Combined
#define EVENT_TIMER2_A                  12  // General Purpose Timer 2A
#define EVENT_TIMER2_B                  13  // General Purpose Timer 2B
#define EVENT_TIMER3_A                  14  // General Purpose Timer 3A
#define EVENT_TIMER3_B                  15  // General Purpose Timer 3B
#define EVENT_TIMER0_A                  16  // General Purpose Timer 0A
#define EVENT_TIMER0_B                  17  // General Purpose Timer 0B
#define EVENT_TIMER1_A                  18  // General Purpose Timer 1A
#define EVENT_TIMER1_B                  19  // General Purpose Timer 1B
#define EVENT_SW0_DONE                  20  // Software Event 0 Done
#define EVENT_FLASH                     21  // Flash event
#define EVENT_SW1_DMA_DONE              22  // Software event 1 DMA done
#define EVENT_ADC                       23  // ADC event
#define EVENT_WATCHDOG                  24  // Watchdog Timer
#define EVENT_RFCORE_CMD_ACK            25  // RF command acknowledge
#define EVENT_RFCORE_HW                 26  // RF Hardware Event
#define EVENT_RFCORE_CPE0               27  // RF Core Packet Engine 0
#define EVENT_PRCM_BUSON                28  // PRCM
#define EVENT_AUX_CMP                   29  // AUX Compare
#define EVENT_RFCORE_CPE1               30  // RF Core Packet Engine 1
#define EVENT_PRCM                      31  // Power Reset Clock Management
#define EVENT_AUX_ERR                   32  // AUX Error Event
#define EVENT_AUX_ADC                   33  // AUX_ADC
#define EVENT_SSI0                      34  // SSI0 combined
#define EVENT_SSI1                      35  // SSI1 combined
#define EVENT_UART0                     36  // UART0 combined
#define EVENT_UART1                     37  // UART1 combined
#define EVENT_DMA_ERR                   38  // Error event from DMA
#define EVENT_DMA_DONE                  39  // Combined done event from DMA
#define EVENT_SSI0_RX_BURST             40  // SSI0 Rx burst
#define EVENT_SSI0_RX_SINGLE            41  // SSI0 Rx single
#define EVENT_SSI0_TX_BURST             42  // SSI0 Tx burst
#define EVENT_SSI0_TX_SINGLE            43  // SSI0 Tx single
#define EVENT_SSI1_RX_BURST             44  // SSI1 Rx burst
#define EVENT_SSI1_RX_SINGLE            45  // SSI1 Rx single
#define EVENT_SSI1_TX_BURST             46  // SSI1 Tx burst
#define EVENT_SSI1_TX_SINGLE            47  // SSI1 Tx single
#define EVENT_UART0_RX_BURST            48  // UART0 Rx burst
#define EVENT_UART0_RX_SINGLE           49  // UART0 Rx single
#define EVENT_UART0_TX_BURST            50  // UART0 Tx burst
#define EVENT_UART0_TX_SINGLE           51  // UART0 Tx single
#define EVENT_UART1_RX_BURST            52  // UART1 Rx burst
#define EVENT_UART1_RX_SINGLE           53  // UART1 Rx single
#define EVENT_UART1_TX_BURST            54  // UART1 Tx burst
#define EVENT_UART1_TX_SINGLE           55  // UART1 Tx single
#define EVENT_SPIS                      56  // SPIS Combined event
#define EVENT_AON_SPIS_RX_BURST         57  // AON SPIS RX burst
#define EVENT_AON_SPIS_RX_SINGLE        58  // AON SPIS RX single
#define EVENT_AON_SPIS_TX_BURST         59  // AON SPIS TX burst
#define EVENT_AON_SPIS_TX_SINGLE        60  // AON SPIS TX single
#define EVENT_TIMER0_A_COMP             61  // GPT0 compare A
#define EVENT_TIMER0_B_COMP             62  // GPT0 compare B
#define EVENT_TIMER1_A_COMP             63  // GPT1 compare A
#define EVENT_TIMER1_B_COMP             64  // GPT1 compare B
#define EVENT_TIMER2_A_COMP             65  // GPT2 compare A
#define EVENT_TIMER2_B_COMP             66  // GPT2 compare B
#define EVENT_TIMER3_A_COMP             67  // GPT3 compare A
#define EVENT_TIMER3_B_COMP             68  // GPT3 compare B
#define EVENT_TIMER0_A_SREQ_            69  // GPT SREQ timer 0A
#define EVENT_TIMER0_B_SREQ             70  // GPT SREQ timer 0B
#define EVENT_TIMER1_A_SREQ             71  // GPT SREQ timer 1A
#define EVENT_TIMER1_B_SREQ             72  // GPT SREQ timer 1B
#define EVENT_TIMER2_A_SREQ             73  // GPT SREQ timer 2A
#define EVENT_TIMER2_B_SREQ             74  // GPT SREQ timer 2B
#define EVENT_TIMER3_A_SREQ             75  // GPT SREQ timer 3A
#define EVENT_TIMER3_B_SREQ             76  // GPT SREQ timer 3B
#define EVENT_TIMER0_A_REQ              77  // GPT REQ timer 0A
#define EVENT_TIMER0_B_REQ              78  // GPT REQ timer 0B
#define EVENT_TIMER1_A_REQ              79  // GPT REQ timer 1A
#define EVENT_TIMER1_B_REQ              80  // GPT REQ timer 1B
#define EVENT_TIMER2_A_REQ              81  // GPT REQ timer 2A
#define EVENT_TIMER2_B_REQ              82  // GPT REQ timer 2B
#define EVENT_TIMER3_A_REQ              83  // GPT REQ timer 3A
#define EVENT_TIMER3_B_REQ              84  // GPT REQ timer 3B
#define EVENT_PAD_IN_TIMER_SUB0         85  // Pad inputs for GPT subscribers - 0
#define EVENT_PAD_IN_TIMER_SUB1         86  // Pad inputs for GPT subscribers - 1
#define EVENT_PAD_IN_TIMER_SUB2         87  // Pad inputs for GPT subscribers - 2
#define EVENT_PAD_IN_TIMER_SUB3         88  // Pad inputs for GPT subscribers - 3
#define EVENT_PAD_IN_TIMER_SUB4         89  // Pad inputs for GPT subscribers - 4
#define EVENT_PAD_IN_TIMER_SUB5         90  // Pad inputs for GPT subscribers - 5
#define EVENT_PAD_IN_TIMER_SUB6         91  // Pad inputs for GPT subscribers - 6
#define EVENT_PAD_IN_TIMER_SUB7         92  // Pad inputs for GPT subscribers - 7
#define EVENT_CRYPTO_RES_RDY            93  // Crypto core result available
#define EVENT_CRYPTO_DMA_DONE           94  // Crypto core dma done
#define EVENT_RFCORE_INPUT_1            95  // RF Core input event 1
#define EVENT_RFCORE_INPUT_2            96  // RF Core input event 2
#define EVENT_RFCORE_INPUT_3            97  // RF Core input event 3
#define EVENT_RFCORE_INPUT_4            98  // RF Core input event 4
#define EVENT_NMI                       99  // Maskable Interrupt
#define EVENT_SW0                      100  // Software 0
#define EVENT_SW1                      101  // Software 1
#define EVENT_SW2                      102  // Software 2
#define EVENT_SW3                      103  // Software 3
#define EVENT_TRNG                     104  // TRNG interrupt
#define EVENT_AUX0                     105  // AUX MCU trigger 0 event
#define EVENT_AUX1                     106  // AUX MCU trigger 1 event
#define EVENT_AUX2                     107  // AUX MCU trigger 2 event
#define EVENT_AUX3                     108  // AUX MCU trigger 3 event
#define EVENT_AUX4                     109  // AUX MCU trigger 4 event
#define EVENT_AUX5                     110  // AUX MCU trigger 5 event
#define EVENT_AUX6                     111  // AUX MCU trigger 6 event
#define EVENT_AUX7                     112  // AUX MCU trigger 7 event
#define EVENT_AUX8                     113  // AUX MCU trigger 8 event
#define EVENT_AUX9                     114  // AUX MCU trigger 9 event
#define EVENT_AUX10                    115  // AUX MCU trigger 10 event
#define EVENT_AUX_DMA_SW               116  // AUX DMA SW request
#define EVENT_AUX_DMA_SINGLE           117  // AUX DMA single request
#define EVENT_AUX_DMA_BURST            118  // AUX DMA burst request
#define EVENT_AON_RTC_UPD              119  // AON RTC update
#define EVENT_HALTED                   120  // Halted
#define EVENT_ALWAYS_1                 121  // Unused - always '1'

//*****************************************************************************
//
// Defines for the dynamic event lines that can be configured in the
// event controller.
//
//*****************************************************************************
#define EVENT_CM3_PROG          EVENT_O_CPUIRQSEL30

#define EVENT_RFCORE_PROG       EVENT_O_RFCSEL9

#define EVENT_TIMER0_A_PROG       EVENT_O_GPT0ACAPTSEL
#define EVENT_TIMER0_B_PROG       EVENT_O_GPT0BCAPTSEL
#define EVENT_TIMER1_A_PROG       EVENT_O_GPT1ACAPTSEL
#define EVENT_TIMER1_B_PROG       EVENT_O_GPT1BCAPTSEL
#define EVENT_TIMER2_A_PROG       EVENT_O_GPT2ACAPTSEL
#define EVENT_TIMER2_B_PROG       EVENT_O_GPT2BCAPTSEL
#define EVENT_TIMER3_A_PROG       EVENT_O_GPT3ACAPTSEL
#define EVENT_TIMER3_B_PROG       EVENT_O_GPT3BCAPTSEL

#define EVENT_UDMA_PROG0        EVENT_O_UDMACH9SSEL
#define EVENT_UDMA_PROG1        EVENT_O_UDMACH9BSEL
#define EVENT_UDMA_PROG2        EVENT_O_UDMACH10SSEL
#define EVENT_UDMA_PROG3        EVENT_O_UDMACH10BSEL
#define EVENT_UDMA_PROG4        EVENT_O_UDMACH11SSEL
#define EVENT_UDMA_PROG5        EVENT_O_UDMACH11BSEL
#define EVENT_UDMA_PROG6        EVENT_O_UDMACH12SSEL
#define EVENT_UDMA_PROG7        EVENT_O_UDMACH12BSEL
#define EVENT_UDMA_PROG8        EVENT_O_UDMACH14BSEL
#define EVENT_UDMA_PROG9        EVENT_O_UDMACH14BSEL

#define EVENT_AUX_PROG          EVENT_O_GPT0ACAPTSEL

#define EVENT_I2S_PROG          EVENT_O_I2SSTMPSEL0

#define EVENT_FREEZE_PROG       EVENT_O_FRZSEL0

//*****************************************************************************
//
// API Functions and prototypes
//
//*****************************************************************************

//*****************************************************************************
//
//! \brief Register a dynamic Event in the event fabric and connect a subscriber.
//!
//! \note Not all events can be routed to all programmable output lines.
//!
//! \note Switching the event source is not glitch free, so it is imperative
//! that the subscriber is disabled for interrupts when switching the event
//! source. The behaviour is undefined if not disabled.
//!
//! \param ui32ProgOut is the programmable output line to the subcriber which too
//!        connects to the event.
//! \param ui32EventId is the specific event that must be acted upon.
//!
//! \return None
//
//*****************************************************************************
__STATIC_INLINE void
EventRegister(uint32_t ui32ProgOut, uint32_t ui32EventId)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32ProgOut == EVENT_CM3_PROG)     ||
           (ui32ProgOut == EVENT_RFCORE_PROG)  ||
           (ui32ProgOut == EVENT_TIMER0_A_PROG)  ||
           (ui32ProgOut == EVENT_TIMER0_B_PROG)  ||
           (ui32ProgOut == EVENT_TIMER1_A_PROG)  ||
           (ui32ProgOut == EVENT_TIMER1_B_PROG)  ||
           (ui32ProgOut == EVENT_TIMER2_A_PROG)  ||
           (ui32ProgOut == EVENT_TIMER2_B_PROG)  ||
           (ui32ProgOut == EVENT_TIMER3_A_PROG)  ||
           (ui32ProgOut == EVENT_TIMER3_B_PROG)  ||
           (ui32ProgOut == EVENT_UDMA_PROG0)   ||
           (ui32ProgOut == EVENT_UDMA_PROG1)   ||
           (ui32ProgOut == EVENT_UDMA_PROG2)   ||
           (ui32ProgOut == EVENT_UDMA_PROG3)   ||
           (ui32ProgOut == EVENT_UDMA_PROG4)   ||
           (ui32ProgOut == EVENT_UDMA_PROG5)   ||
           (ui32ProgOut == EVENT_UDMA_PROG6)   ||
           (ui32ProgOut == EVENT_UDMA_PROG7)   ||
           (ui32ProgOut == EVENT_UDMA_PROG8)   ||
           (ui32ProgOut == EVENT_UDMA_PROG9)   ||
           (ui32ProgOut == EVENT_AUX_PROG)     ||
           (ui32ProgOut == EVENT_I2S_PROG)     ||
           (ui32ProgOut == EVENT_FREEZE_PROG));
    ASSERT((ui32EventId == EVENT_ALWAYS_0)           ||
           (ui32EventId == EVENT_AON_PROG_0)         ||
           (ui32EventId == EVENT_AON_PROG_1)         ||
           (ui32EventId == EVENT_AON_PROG_2)         ||
           (ui32EventId == EVENT_AON_EDGE_DETECT)    ||
           (ui32EventId == EVENT_AON_SPIS_RTX)       ||
           (ui32EventId == EVENT_AON_SPIS_CS)        ||
           (ui32EventId == EVENT_AON_RTCCOMDLY)      ||
           (ui32EventId == EVENT_AUX_SM)             ||
           (ui32EventId == EVENT_I2C_INTERRUPT)      ||
           (ui32EventId == EVENT_AON_AUX0)           ||
           (ui32EventId == EVENT_PTIM_RTX)           ||
           (ui32EventId == EVENT_TIMER2_A)           ||
           (ui32EventId == EVENT_TIMER2_B)           ||
           (ui32EventId == EVENT_TIMER3_A)           ||
           (ui32EventId == EVENT_TIMER3_B)           ||
           (ui32EventId == EVENT_TIMER0_A)           ||
           (ui32EventId == EVENT_TIMER0_B)           ||
           (ui32EventId == EVENT_TIMER1_A)           ||
           (ui32EventId == EVENT_TIMER1_B)           ||
           (ui32EventId == EVENT_SW0_DONE)           ||
           (ui32EventId == EVENT_FLASH)              ||
           (ui32EventId == EVENT_SW1_DMA_DONE)       ||
           (ui32EventId == EVENT_ADC)                ||
           (ui32EventId == EVENT_WATCHDOG)           ||
           (ui32EventId == EVENT_RFCORE_CMD_ACK)     ||
           (ui32EventId == EVENT_RFCORE_HW)          ||
           (ui32EventId == EVENT_RFCORE_CPE0)        ||
           (ui32EventId == EVENT_PRCM_BUSON)         ||
           (ui32EventId == EVENT_AUX_CMP)            ||
           (ui32EventId == EVENT_RFCORE_CPE1)        ||
           (ui32EventId == EVENT_PRCM)               ||
           (ui32EventId == EVENT_AUX_ERR)            ||
           (ui32EventId == EVENT_AUX_ADC)            ||
           (ui32EventId == EVENT_SSI0)               ||
           (ui32EventId == EVENT_SSI1)               ||
           (ui32EventId == EVENT_UART0)              ||
           (ui32EventId == EVENT_UART1)              ||
           (ui32EventId == EVENT_DMA_ERR)            ||
           (ui32EventId == EVENT_DMA_DONE)           ||
           (ui32EventId == EVENT_SSI0_RX_BURST)      ||
           (ui32EventId == EVENT_SSI0_RX_SINGLE)     ||
           (ui32EventId == EVENT_SSI0_TX_BURST)      ||
           (ui32EventId == EVENT_SSI0_TX_SINGLE)     ||
           (ui32EventId == EVENT_SSI1_RX_BURST)      ||
           (ui32EventId == EVENT_SSI1_RX_SINGLE)     ||
           (ui32EventId == EVENT_SSI1_TX_BURST)      ||
           (ui32EventId == EVENT_SSI1_TX_SINGLE)     ||
           (ui32EventId == EVENT_UART0_RX_BURST)     ||
           (ui32EventId == EVENT_UART0_RX_SINGLE)    ||
           (ui32EventId == EVENT_UART0_TX_BURST)     ||
           (ui32EventId == EVENT_UART0_TX_SINGLE)    ||
           (ui32EventId == EVENT_UART1_RX_BURST)     ||
           (ui32EventId == EVENT_UART1_RX_SINGLE)    ||
           (ui32EventId == EVENT_UART1_TX_BURST)     ||
           (ui32EventId == EVENT_UART1_TX_SINGLE)    ||
           (ui32EventId == EVENT_SPIS)               ||
           (ui32EventId == EVENT_AON_SPIS_RX_BURST)  ||
           (ui32EventId == EVENT_AON_SPIS_RX_SINGLE) ||
           (ui32EventId == EVENT_AON_SPIS_TX_BURST)  ||
           (ui32EventId == EVENT_AON_SPIS_TX_SINGLE) ||
           (ui32EventId == EVENT_TIMER0_A_COMP)        ||
           (ui32EventId == EVENT_TIMER0_B_COMP)        ||
           (ui32EventId == EVENT_TIMER1_A_COMP)        ||
           (ui32EventId == EVENT_TIMER1_B_COMP)        ||
           (ui32EventId == EVENT_TIMER2_A_COMP)        ||
           (ui32EventId == EVENT_TIMER2_B_COMP)        ||
           (ui32EventId == EVENT_TIMER3_A_COMP)        ||
           (ui32EventId == EVENT_TIMER3_B_COMP)        ||
           (ui32EventId == EVENT_TIMER0_A_SREQ_)       ||
           (ui32EventId == EVENT_TIMER0_B_SREQ)        ||
           (ui32EventId == EVENT_TIMER1_A_SREQ)        ||
           (ui32EventId == EVENT_TIMER1_B_SREQ)        ||
           (ui32EventId == EVENT_TIMER2_A_SREQ)        ||
           (ui32EventId == EVENT_TIMER2_B_SREQ)        ||
           (ui32EventId == EVENT_TIMER3_A_SREQ)        ||
           (ui32EventId == EVENT_TIMER3_B_SREQ)        ||
           (ui32EventId == EVENT_TIMER0_A_REQ)         ||
           (ui32EventId == EVENT_TIMER0_B_REQ)         ||
           (ui32EventId == EVENT_TIMER1_A_REQ)         ||
           (ui32EventId == EVENT_TIMER1_B_REQ)         ||
           (ui32EventId == EVENT_TIMER2_A_REQ)         ||
           (ui32EventId == EVENT_TIMER2_B_REQ)         ||
           (ui32EventId == EVENT_TIMER3_A_REQ)         ||
           (ui32EventId == EVENT_TIMER3_B_REQ)         ||
           (ui32EventId == EVENT_PAD_IN_TIMER_SUB0)    ||
           (ui32EventId == EVENT_PAD_IN_TIMER_SUB1)    ||
           (ui32EventId == EVENT_PAD_IN_TIMER_SUB2)    ||
           (ui32EventId == EVENT_PAD_IN_TIMER_SUB3)    ||
           (ui32EventId == EVENT_PAD_IN_TIMER_SUB4)    ||
           (ui32EventId == EVENT_PAD_IN_TIMER_SUB5)    ||
           (ui32EventId == EVENT_PAD_IN_TIMER_SUB6)    ||
           (ui32EventId == EVENT_PAD_IN_TIMER_SUB7)    ||
           (ui32EventId == EVENT_CRYPTO_RES_RDY)     ||
           (ui32EventId == EVENT_CRYPTO_DMA_DONE)    ||
           (ui32EventId == EVENT_RFCORE_INPUT_1)     ||
           (ui32EventId == EVENT_RFCORE_INPUT_2)     ||
           (ui32EventId == EVENT_RFCORE_INPUT_3)     ||
           (ui32EventId == EVENT_RFCORE_INPUT_4)     ||
           (ui32EventId == EVENT_NMI)                ||
           (ui32EventId == EVENT_SW0)                ||
           (ui32EventId == EVENT_SW1)                ||
           (ui32EventId == EVENT_SW2)                ||
           (ui32EventId == EVENT_SW3)                ||
           (ui32EventId == EVENT_TRNG)               ||
           (ui32EventId == EVENT_AUX0)               ||
           (ui32EventId == EVENT_AUX1)               ||
           (ui32EventId == EVENT_AUX2)               ||
           (ui32EventId == EVENT_AUX3)               ||
           (ui32EventId == EVENT_AUX4)               ||
           (ui32EventId == EVENT_AUX5)               ||
           (ui32EventId == EVENT_AUX6)               ||
           (ui32EventId == EVENT_AUX7)               ||
           (ui32EventId == EVENT_AUX8)               ||
           (ui32EventId == EVENT_AUX9)               ||
           (ui32EventId == EVENT_AUX10)              ||
           (ui32EventId == EVENT_AUX_DMA_SW)         ||
           (ui32EventId == EVENT_AUX_DMA_SINGLE)     ||
           (ui32EventId == EVENT_AUX_DMA_BURST)      ||
           (ui32EventId == EVENT_AON_RTC_UPD)        ||
           (ui32EventId == EVENT_HALTED)             ||
           (ui32EventId == EVENT_ALWAYS_1));

    //
    // Register the event.
    //
    HWREG(EVENT_BASE + ui32ProgOut) = ui32EventId;
}

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif // __EVENT_H__

//*****************************************************************************
//
//! Close the Doxygen group.
//! @}
//
//*****************************************************************************
