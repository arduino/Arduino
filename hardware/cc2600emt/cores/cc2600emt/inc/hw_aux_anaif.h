/******************************************************************************
*  Filename:       hw_aux_anaif_h
*  Revised:        2015-11-12 13:07:02 +0100 (Thu, 12 Nov 2015)
*  Revision:       45056
*
* Copyright (c) 2015, Texas Instruments Incorporated
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
* 1) Redistributions of source code must retain the above copyright notice,
*    this list of conditions and the following disclaimer.
*
* 2) Redistributions in binary form must reproduce the above copyright notice,
*    this list of conditions and the following disclaimer in the documentation
*    and/or other materials provided with the distribution.
*
* 3) Neither the name of the ORGANIZATION nor the names of its contributors may
*    be used to endorse or promote products derived from this software without
*    specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
* LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*
******************************************************************************/

#ifndef __HW_AUX_ANAIF_H__
#define __HW_AUX_ANAIF_H__

//*****************************************************************************
//
// This section defines the register offsets of
// AUX_ANAIF component
//
//*****************************************************************************
// ADC Control
#define AUX_ANAIF_O_ADCCTL                                          0x00000010

// ADC FIFO Status
#define AUX_ANAIF_O_ADCFIFOSTAT                                     0x00000014

// ADC FIFO
#define AUX_ANAIF_O_ADCFIFO                                         0x00000018

// ADC Trigger
#define AUX_ANAIF_O_ADCTRIG                                         0x0000001C

// Current Source Control
#define AUX_ANAIF_O_ISRCCTL                                         0x00000020

//*****************************************************************************
//
// Register: AUX_ANAIF_O_ADCCTL
//
//*****************************************************************************
// Field:    [13] START_POL
//
// Selected active edge for start event / Selected polarity for start event
// ENUMs:
// FALL                     Start on falling edge of event
// RISE                     Start on rising edge of event
#define AUX_ANAIF_ADCCTL_START_POL                                  0x00002000
#define AUX_ANAIF_ADCCTL_START_POL_BITN                                     13
#define AUX_ANAIF_ADCCTL_START_POL_M                                0x00002000
#define AUX_ANAIF_ADCCTL_START_POL_S                                        13
#define AUX_ANAIF_ADCCTL_START_POL_FALL                             0x00002000
#define AUX_ANAIF_ADCCTL_START_POL_RISE                             0x00000000

// Field:  [12:8] START_SRC
//
// Selected source for ADC conversion start event. The start source selected by
// this field is OR'ed with any trigger coming from writes to ADCTRIG.START. If
// it is desired to only trigger ADC conversions by writes to ADCTRIG.START one
// should select NO_EVENT<n> here
// ENUMs:
// ADC_IRQ                  Selects ADC_IRQ as start signal
// MCU_EV                   Selects MCU_EV as start signal
// ACLK_REF                 Selects ACLK_REF as start signal
// AUXIO15                  Selects AUXIO15 as start signal
// AUXIO14                  Selects AUXIO14 as start signal
// AUXIO13                  Selects AUXIO13 as start signal
// AUXIO12                  Selects AUXIO12 as start signal
// AUXIO11                  Selects AUXIO11 as start signal
// AUXIO10                  Selects AUXIO10 as start signal
// AUXIO9                   Selects AUXIO9 as start signal
// AUXIO8                   Selects AUXIO8 as start signal
// AUXIO7                   Selects AUXIO7 as start signal
// AUXIO6                   Selects AUXIO6 as start signal
// AUXIO5                   Selects AUXIO5 as start signal
// AUXIO4                   Selects AUXIO4 as start signal
// AUXIO3                   Selects AUXIO3 as start signal
// AUXIO2                   Selects AUXIO2 as start signal
// AUXIO1                   Selects AUXIO1 as start signal
// AUXIO0                   Selects AUXIO0 as start signal
// AON_PROG_WU              Selects AON_PROG_WU as start signal
// AON_SW                   Selects AON_SW as start signal
// NO_EVENT1                No event selected
// NO_EVENT0                No event selected
// RESERVED1                Reserved do not use
// RESERVED0                Reserved do not use
// SMPH_AUTOTAKE_DONE       Selects SMPH_AUTOTAKE_DONE as start signal
// TIMER1_EV                Selects TIMER1_EV as start signal
// TIMER0_EV                Selects TIMER0_EV as start signal
// TDC_DONE                 Selects TDC_DONE as start signal
// AUX_COMPB                Selects AUX_COMPB as start signal
// AUX_COMPA                Selects AUX_COMPA as start signal
// RTC_CH2_EV               Selects RTC_CH2_EV as start signal
#define AUX_ANAIF_ADCCTL_START_SRC_W                                         5
#define AUX_ANAIF_ADCCTL_START_SRC_M                                0x00001F00
#define AUX_ANAIF_ADCCTL_START_SRC_S                                         8
#define AUX_ANAIF_ADCCTL_START_SRC_ADC_IRQ                          0x00001F00
#define AUX_ANAIF_ADCCTL_START_SRC_MCU_EV                           0x00001E00
#define AUX_ANAIF_ADCCTL_START_SRC_ACLK_REF                         0x00001D00
#define AUX_ANAIF_ADCCTL_START_SRC_AUXIO15                          0x00001C00
#define AUX_ANAIF_ADCCTL_START_SRC_AUXIO14                          0x00001B00
#define AUX_ANAIF_ADCCTL_START_SRC_AUXIO13                          0x00001A00
#define AUX_ANAIF_ADCCTL_START_SRC_AUXIO12                          0x00001900
#define AUX_ANAIF_ADCCTL_START_SRC_AUXIO11                          0x00001800
#define AUX_ANAIF_ADCCTL_START_SRC_AUXIO10                          0x00001700
#define AUX_ANAIF_ADCCTL_START_SRC_AUXIO9                           0x00001600
#define AUX_ANAIF_ADCCTL_START_SRC_AUXIO8                           0x00001500
#define AUX_ANAIF_ADCCTL_START_SRC_AUXIO7                           0x00001400
#define AUX_ANAIF_ADCCTL_START_SRC_AUXIO6                           0x00001300
#define AUX_ANAIF_ADCCTL_START_SRC_AUXIO5                           0x00001200
#define AUX_ANAIF_ADCCTL_START_SRC_AUXIO4                           0x00001100
#define AUX_ANAIF_ADCCTL_START_SRC_AUXIO3                           0x00001000
#define AUX_ANAIF_ADCCTL_START_SRC_AUXIO2                           0x00000F00
#define AUX_ANAIF_ADCCTL_START_SRC_AUXIO1                           0x00000E00
#define AUX_ANAIF_ADCCTL_START_SRC_AUXIO0                           0x00000D00
#define AUX_ANAIF_ADCCTL_START_SRC_AON_PROG_WU                      0x00000C00
#define AUX_ANAIF_ADCCTL_START_SRC_AON_SW                           0x00000B00
#define AUX_ANAIF_ADCCTL_START_SRC_NO_EVENT1                        0x00000A00
#define AUX_ANAIF_ADCCTL_START_SRC_NO_EVENT0                        0x00000900
#define AUX_ANAIF_ADCCTL_START_SRC_RESERVED1                        0x00000800
#define AUX_ANAIF_ADCCTL_START_SRC_RESERVED0                        0x00000700
#define AUX_ANAIF_ADCCTL_START_SRC_SMPH_AUTOTAKE_DONE               0x00000600
#define AUX_ANAIF_ADCCTL_START_SRC_TIMER1_EV                        0x00000500
#define AUX_ANAIF_ADCCTL_START_SRC_TIMER0_EV                        0x00000400
#define AUX_ANAIF_ADCCTL_START_SRC_TDC_DONE                         0x00000300
#define AUX_ANAIF_ADCCTL_START_SRC_AUX_COMPB                        0x00000200
#define AUX_ANAIF_ADCCTL_START_SRC_AUX_COMPA                        0x00000100
#define AUX_ANAIF_ADCCTL_START_SRC_RTC_CH2_EV                       0x00000000

// Field:   [1:0] CMD
//
// ADC interface control command
// ENUMs:
// FLUSH                    ADC FIFO flush. Note that CMD needs to be set to
//                          'EN' again for FIFO to be functional after a
//                          flush. A flush takes two clock periods on the
//                          AUX clock to finish.
// EN                       ADC interface enabled
// DIS                      ADC interface disabled
#define AUX_ANAIF_ADCCTL_CMD_W                                               2
#define AUX_ANAIF_ADCCTL_CMD_M                                      0x00000003
#define AUX_ANAIF_ADCCTL_CMD_S                                               0
#define AUX_ANAIF_ADCCTL_CMD_FLUSH                                  0x00000003
#define AUX_ANAIF_ADCCTL_CMD_EN                                     0x00000001
#define AUX_ANAIF_ADCCTL_CMD_DIS                                    0x00000000

//*****************************************************************************
//
// Register: AUX_ANAIF_O_ADCFIFOSTAT
//
//*****************************************************************************
// Field:     [4] OVERFLOW
//
// FIFO overflow flag.
//
// 0: FIFO has not overflowed.
// 1: FIFO has overflowed, this flag is sticky until FIFO is flushed.
#define AUX_ANAIF_ADCFIFOSTAT_OVERFLOW                              0x00000010
#define AUX_ANAIF_ADCFIFOSTAT_OVERFLOW_BITN                                  4
#define AUX_ANAIF_ADCFIFOSTAT_OVERFLOW_M                            0x00000010
#define AUX_ANAIF_ADCFIFOSTAT_OVERFLOW_S                                     4

// Field:     [3] UNDERFLOW
//
// FIFO underflow flag.
//
// 0: FIFO has not underflowed
// 1: FIFO has underflowed, this flag is sticky until the FIFO is flushed
#define AUX_ANAIF_ADCFIFOSTAT_UNDERFLOW                             0x00000008
#define AUX_ANAIF_ADCFIFOSTAT_UNDERFLOW_BITN                                 3
#define AUX_ANAIF_ADCFIFOSTAT_UNDERFLOW_M                           0x00000008
#define AUX_ANAIF_ADCFIFOSTAT_UNDERFLOW_S                                    3

// Field:     [2] FULL
//
// FIFO full flag.
//
// 0: FIFO is not full, i.e. there is less than 4 samples in the FIFO.
// 1: FIFO is full, i.e. there are 4 samples in the FIFO
#define AUX_ANAIF_ADCFIFOSTAT_FULL                                  0x00000004
#define AUX_ANAIF_ADCFIFOSTAT_FULL_BITN                                      2
#define AUX_ANAIF_ADCFIFOSTAT_FULL_M                                0x00000004
#define AUX_ANAIF_ADCFIFOSTAT_FULL_S                                         2

// Field:     [1] ALMOST_FULL
//
// FIFO almost full flag.
//
// 0: There is less than 3 samples in the FIFO, or the FIFO is full in which
// case the FULL flag is asserted
// 1: There are 3 samples in the FIFO, i.e. there is room for one more sample
#define AUX_ANAIF_ADCFIFOSTAT_ALMOST_FULL                           0x00000002
#define AUX_ANAIF_ADCFIFOSTAT_ALMOST_FULL_BITN                               1
#define AUX_ANAIF_ADCFIFOSTAT_ALMOST_FULL_M                         0x00000002
#define AUX_ANAIF_ADCFIFOSTAT_ALMOST_FULL_S                                  1

// Field:     [0] EMPTY
//
// FIFO empty flag.
//
// 0: FIFO contains one or more samples
// 1: FIFO is empty
#define AUX_ANAIF_ADCFIFOSTAT_EMPTY                                 0x00000001
#define AUX_ANAIF_ADCFIFOSTAT_EMPTY_BITN                                     0
#define AUX_ANAIF_ADCFIFOSTAT_EMPTY_M                               0x00000001
#define AUX_ANAIF_ADCFIFOSTAT_EMPTY_S                                        0

//*****************************************************************************
//
// Register: AUX_ANAIF_O_ADCFIFO
//
//*****************************************************************************
// Field:  [11:0] DATA
//
// FIFO is popped when read. Data is pushed into FIFO when written. Writing is
// intended for debugging/code development purposes
#define AUX_ANAIF_ADCFIFO_DATA_W                                            12
#define AUX_ANAIF_ADCFIFO_DATA_M                                    0x00000FFF
#define AUX_ANAIF_ADCFIFO_DATA_S                                             0

//*****************************************************************************
//
// Register: AUX_ANAIF_O_ADCTRIG
//
//*****************************************************************************
// Field:     [0] START
//
// Writing to this register will trigger an ADC conversion given that
// ADCCTL.START_SRC is set to NO_EVENT0 or NO_EVENT1. If other setting is used
// in ADCCTL.START_SRC behavior can be unpredictable
#define AUX_ANAIF_ADCTRIG_START                                     0x00000001
#define AUX_ANAIF_ADCTRIG_START_BITN                                         0
#define AUX_ANAIF_ADCTRIG_START_M                                   0x00000001
#define AUX_ANAIF_ADCTRIG_START_S                                            0

//*****************************************************************************
//
// Register: AUX_ANAIF_O_ISRCCTL
//
//*****************************************************************************
// Field:     [0] RESET_N
//
// Current source control
//
// 0: Current source is clamped
// 1: Current source is active/charging
#define AUX_ANAIF_ISRCCTL_RESET_N                                   0x00000001
#define AUX_ANAIF_ISRCCTL_RESET_N_BITN                                       0
#define AUX_ANAIF_ISRCCTL_RESET_N_M                                 0x00000001
#define AUX_ANAIF_ISRCCTL_RESET_N_S                                          0


#endif // __AUX_ANAIF__
