/******************************************************************************
*  Filename:       hw_aux_aiodio_h
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

#ifndef __HW_AUX_AIODIO_H__
#define __HW_AUX_AIODIO_H__

//*****************************************************************************
//
// This section defines the register offsets of
// AUX_AIODIO component
//
//*****************************************************************************
// General Purpose Input/Output Data Out
#define AUX_AIODIO_O_GPIODOUT                                       0x00000000

// Input Output Mode
#define AUX_AIODIO_O_IOMODE                                         0x00000004

// General Purpose Input Output Data In
#define AUX_AIODIO_O_GPIODIN                                        0x00000008

// General Purpose Input Output Data Out Set
#define AUX_AIODIO_O_GPIODOUTSET                                    0x0000000C

// General Purpose Input Output Data Out Clear
#define AUX_AIODIO_O_GPIODOUTCLR                                    0x00000010

// General Purpose Input Output Data Out Toggle
#define AUX_AIODIO_O_GPIODOUTTGL                                    0x00000014

// General Purpose Input Output Input Enable
#define AUX_AIODIO_O_GPIODIE                                        0x00000018

//*****************************************************************************
//
// Register: AUX_AIODIO_O_GPIODOUT
//
//*****************************************************************************
// Field:   [7:0] IO7_0
//
// Output values for AUXIO0 through AUXIO7 (for AIODIO0) or AUXIO8 through
// AUXIO15 (for AIODIO1).
#define AUX_AIODIO_GPIODOUT_IO7_0_W                                          8
#define AUX_AIODIO_GPIODOUT_IO7_0_M                                 0x000000FF
#define AUX_AIODIO_GPIODOUT_IO7_0_S                                          0

//*****************************************************************************
//
// Register: AUX_AIODIO_O_IOMODE
//
//*****************************************************************************
// Field: [15:14] IO7
//
// Selects mode for AUXIO7 (for AIODIO0) or AUXIO15 (for AIODIO1).
// ENUMs:
// OPEN_SOURCE              Open-source: The pin is driven high when the
//                          corresponding GPIODOUT bit is 1, and otherwise
//                          tri-stated or pulled depending on the
//                          corresponding IOC configuration.
// OPEN_DRAIN               Open-drain: The pin is driven low when the
//                          corresponding GPIODOUT bit is 0, and otherwise
//                          tri-stated or pulled depending on the
//                          corresponding IOC configuration.
// IN                       Digital input with GPIODIE bit 7 = 1
//                          Analog input/output with
//                          GPIODIE bit 7 = 0
// OUT                      Output
#define AUX_AIODIO_IOMODE_IO7_W                                              2
#define AUX_AIODIO_IOMODE_IO7_M                                     0x0000C000
#define AUX_AIODIO_IOMODE_IO7_S                                             14
#define AUX_AIODIO_IOMODE_IO7_OPEN_SOURCE                           0x0000C000
#define AUX_AIODIO_IOMODE_IO7_OPEN_DRAIN                            0x00008000
#define AUX_AIODIO_IOMODE_IO7_IN                                    0x00004000
#define AUX_AIODIO_IOMODE_IO7_OUT                                   0x00000000

// Field: [13:12] IO6
//
// Selects mode for AUXIO6 (for AIODIO0) or AUXIO14 (for AIODIO1).
// ENUMs:
// OPEN_SOURCE              Open-source: The pin is driven high when the
//                          corresponding GPIODOUT bit is 1, and otherwise
//                          tri-stated or pulled depending on the
//                          corresponding IOC configuration.
// OPEN_DRAIN               Open-drain: The pin is driven low when the
//                          corresponding GPIODOUT bit is 0, and otherwise
//                          tri-stated or pulled depending on the
//                          corresponding IOC configuration.
// IN                       Digital input with GPIODIE bit 6 = 1
//                          Analog input/output with
//                          GPIODIE bit 6 = 0
// OUT                      Output
#define AUX_AIODIO_IOMODE_IO6_W                                              2
#define AUX_AIODIO_IOMODE_IO6_M                                     0x00003000
#define AUX_AIODIO_IOMODE_IO6_S                                             12
#define AUX_AIODIO_IOMODE_IO6_OPEN_SOURCE                           0x00003000
#define AUX_AIODIO_IOMODE_IO6_OPEN_DRAIN                            0x00002000
#define AUX_AIODIO_IOMODE_IO6_IN                                    0x00001000
#define AUX_AIODIO_IOMODE_IO6_OUT                                   0x00000000

// Field: [11:10] IO5
//
// Selects mode for AUXIO5 (for AIODIO0) or AUXIO13 (for AIODIO1).
// ENUMs:
// OPEN_SOURCE              Open-source: The pin is driven high when the
//                          corresponding GPIODOUT bit is 1, and otherwise
//                          tri-stated or pulled depending on the
//                          corresponding IOC configuration.
// OPEN_DRAIN               Open-drain: The pin is driven low when the
//                          corresponding GPIODOUT bit is 0, and otherwise
//                          tri-stated or pulled depending on the
//                          corresponding IOC configuration.
// IN                       Digital input with GPIODIE bit 5 = 1
//                          Analog input/output with
//                          GPIODIE bit 5 = 0
// OUT                      Output
#define AUX_AIODIO_IOMODE_IO5_W                                              2
#define AUX_AIODIO_IOMODE_IO5_M                                     0x00000C00
#define AUX_AIODIO_IOMODE_IO5_S                                             10
#define AUX_AIODIO_IOMODE_IO5_OPEN_SOURCE                           0x00000C00
#define AUX_AIODIO_IOMODE_IO5_OPEN_DRAIN                            0x00000800
#define AUX_AIODIO_IOMODE_IO5_IN                                    0x00000400
#define AUX_AIODIO_IOMODE_IO5_OUT                                   0x00000000

// Field:   [9:8] IO4
//
// Selects mode for AUXIO4 (for AIODIO0) or AUXIO12 (for AIODIO1).
// ENUMs:
// OPEN_SOURCE              Open-source: The pin is driven high when the
//                          corresponding GPIODOUT bit is 1, and otherwise
//                          tri-stated or pulled depending on the
//                          corresponding IOC configuration.
// OPEN_DRAIN               Open-drain: The pin is driven low when the
//                          corresponding GPIODOUT bit is 0, and otherwise
//                          tri-stated or pulled depending on the
//                          corresponding IOC configuration.
// IN                       Digital input with GPIODIE bit 4 = 1
//                          Analog input/output with
//                          GPIODIE bit 4 = 0
// OUT                      Output
#define AUX_AIODIO_IOMODE_IO4_W                                              2
#define AUX_AIODIO_IOMODE_IO4_M                                     0x00000300
#define AUX_AIODIO_IOMODE_IO4_S                                              8
#define AUX_AIODIO_IOMODE_IO4_OPEN_SOURCE                           0x00000300
#define AUX_AIODIO_IOMODE_IO4_OPEN_DRAIN                            0x00000200
#define AUX_AIODIO_IOMODE_IO4_IN                                    0x00000100
#define AUX_AIODIO_IOMODE_IO4_OUT                                   0x00000000

// Field:   [7:6] IO3
//
// Selects mode for AUXIO3 (for AIODIO0) or AUXIO11 (for AIODIO1).
// ENUMs:
// OPEN_SOURCE              Open-source: The pin is driven high when the
//                          corresponding GPIODOUT bit is 1, and otherwise
//                          tri-stated or pulled depending on the
//                          corresponding IOC configuration.
// OPEN_DRAIN               Open-drain: The pin is driven low when the
//                          corresponding GPIODOUT bit is 0, and otherwise
//                          tri-stated or pulled depending on the
//                          corresponding IOC configuration.
// IN                       Digital input with GPIODIE bit 3 = 1
//                          Analog input/output with
//                          GPIODIE bit 3 = 0
// OUT                      Output
#define AUX_AIODIO_IOMODE_IO3_W                                              2
#define AUX_AIODIO_IOMODE_IO3_M                                     0x000000C0
#define AUX_AIODIO_IOMODE_IO3_S                                              6
#define AUX_AIODIO_IOMODE_IO3_OPEN_SOURCE                           0x000000C0
#define AUX_AIODIO_IOMODE_IO3_OPEN_DRAIN                            0x00000080
#define AUX_AIODIO_IOMODE_IO3_IN                                    0x00000040
#define AUX_AIODIO_IOMODE_IO3_OUT                                   0x00000000

// Field:   [5:4] IO2
//
// Selects mode for AUXIO2 (for AIODIO0) or AUXIO10 (for AIODIO1).
// ENUMs:
// OPEN_SOURCE              Open-source: The pin is driven high when the
//                          corresponding GPIODOUT bit is 1, and otherwise
//                          tri-stated or pulled depending on the
//                          corresponding IOC configuration.
// OPEN_DRAIN               Open-drain: The pin is driven low when the
//                          corresponding GPIODOUT bit is 0, and otherwise
//                          tri-stated or pulled depending on the
//                          corresponding IOC configuration.
// IN                       Digital input with GPIODIE bit 2 = 1
//                          Analog input/output with
//                          GPIODIE bit 2 = 0
// OUT                      Output
#define AUX_AIODIO_IOMODE_IO2_W                                              2
#define AUX_AIODIO_IOMODE_IO2_M                                     0x00000030
#define AUX_AIODIO_IOMODE_IO2_S                                              4
#define AUX_AIODIO_IOMODE_IO2_OPEN_SOURCE                           0x00000030
#define AUX_AIODIO_IOMODE_IO2_OPEN_DRAIN                            0x00000020
#define AUX_AIODIO_IOMODE_IO2_IN                                    0x00000010
#define AUX_AIODIO_IOMODE_IO2_OUT                                   0x00000000

// Field:   [3:2] IO1
//
// Selects mode for AUXIO1 (for AIODIO0) or AUXIO9 (for AIODIO1).
// ENUMs:
// OPEN_SOURCE              Open-source: The pin is driven high when the
//                          corresponding GPIODOUT bit is 1, and otherwise
//                          tri-stated or pulled depending on the
//                          corresponding IOC configuration.
// OPEN_DRAIN               Open-drain: The pin is driven low when the
//                          corresponding GPIODOUT bit is 0, and otherwise
//                          tri-stated or pulled depending on the
//                          corresponding IOC configuration.
// IN                       Digital input with GPIODIE bit 1 = 1
//                          Analog input/output with
//                          GPIODIE bit 1 = 0
// OUT                      Output
#define AUX_AIODIO_IOMODE_IO1_W                                              2
#define AUX_AIODIO_IOMODE_IO1_M                                     0x0000000C
#define AUX_AIODIO_IOMODE_IO1_S                                              2
#define AUX_AIODIO_IOMODE_IO1_OPEN_SOURCE                           0x0000000C
#define AUX_AIODIO_IOMODE_IO1_OPEN_DRAIN                            0x00000008
#define AUX_AIODIO_IOMODE_IO1_IN                                    0x00000004
#define AUX_AIODIO_IOMODE_IO1_OUT                                   0x00000000

// Field:   [1:0] IO0
//
// Selects mode for AUXIO0 (for AIODIO0) or AUXIO8 (for AIODIO1).
// ENUMs:
// OPEN_SOURCE              Open-source: The pin is driven high when the
//                          corresponding GPIODOUT bit is 1, and otherwise
//                          tri-stated or pulled depending on the
//                          corresponding IOC configuration.
// OPEN_DRAIN               Open-drain: The pin is driven low when the
//                          corresponding GPIODOUT bit is 0, and otherwise
//                          tri-stated or pulled depending on the
//                          corresponding IOC configuration.
// IN                       Digital input with GPIODIE bit 0 = 1
//                          Analog input/output with
//                          GPIODIE bit 0 = 0
// OUT                      Output
#define AUX_AIODIO_IOMODE_IO0_W                                              2
#define AUX_AIODIO_IOMODE_IO0_M                                     0x00000003
#define AUX_AIODIO_IOMODE_IO0_S                                              0
#define AUX_AIODIO_IOMODE_IO0_OPEN_SOURCE                           0x00000003
#define AUX_AIODIO_IOMODE_IO0_OPEN_DRAIN                            0x00000002
#define AUX_AIODIO_IOMODE_IO0_IN                                    0x00000001
#define AUX_AIODIO_IOMODE_IO0_OUT                                   0x00000000

//*****************************************************************************
//
// Register: AUX_AIODIO_O_GPIODIN
//
//*****************************************************************************
// Field:   [7:0] IO7_0
//
// Input values for AUXIO0 through AUXIO7 (for AIODIO0) or AUXIO8 through
// AUXIO15 (for AIODIO1).
#define AUX_AIODIO_GPIODIN_IO7_0_W                                           8
#define AUX_AIODIO_GPIODIN_IO7_0_M                                  0x000000FF
#define AUX_AIODIO_GPIODIN_IO7_0_S                                           0

//*****************************************************************************
//
// Register: AUX_AIODIO_O_GPIODOUTSET
//
//*****************************************************************************
// Field:   [7:0] IO7_0
//
// Writing 1(s) to one or more bit positions sets the corresponding bit(s) in
// GPIODOUT.
//
// Read value is 0x00.
#define AUX_AIODIO_GPIODOUTSET_IO7_0_W                                       8
#define AUX_AIODIO_GPIODOUTSET_IO7_0_M                              0x000000FF
#define AUX_AIODIO_GPIODOUTSET_IO7_0_S                                       0

//*****************************************************************************
//
// Register: AUX_AIODIO_O_GPIODOUTCLR
//
//*****************************************************************************
// Field:   [7:0] IO7_0
//
// Writing 1(s) to one or more bit positions clears the corresponding bit(s) in
// GPIODOUT.
//
// Read value is 0x00.
#define AUX_AIODIO_GPIODOUTCLR_IO7_0_W                                       8
#define AUX_AIODIO_GPIODOUTCLR_IO7_0_M                              0x000000FF
#define AUX_AIODIO_GPIODOUTCLR_IO7_0_S                                       0

//*****************************************************************************
//
// Register: AUX_AIODIO_O_GPIODOUTTGL
//
//*****************************************************************************
// Field:   [7:0] IO7_0
//
// Writing 1(s) to one or more bit positions toggles the corresponding bit(s)
// in GPIODOUT.
//
// Read value is 0x00.
#define AUX_AIODIO_GPIODOUTTGL_IO7_0_W                                       8
#define AUX_AIODIO_GPIODOUTTGL_IO7_0_M                              0x000000FF
#define AUX_AIODIO_GPIODOUTTGL_IO7_0_S                                       0

//*****************************************************************************
//
// Register: AUX_AIODIO_O_GPIODIE
//
//*****************************************************************************
// Field:   [7:0] IO7_0
//
// Enables (1) or disables (0) digital input buffers for each AUX I/O pin.
//
// Input buffers must be enabled to allow reading pin values through GPIODIN.
//
// Input buffers must be disabled for analog input or floating pins to avoid
// current leakage.
#define AUX_AIODIO_GPIODIE_IO7_0_W                                           8
#define AUX_AIODIO_GPIODIE_IO7_0_M                                  0x000000FF
#define AUX_AIODIO_GPIODIE_IO7_0_S                                           0


#endif // __AUX_AIODIO__
