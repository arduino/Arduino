//*****************************************************************************
//
// hw_peci.h - Macros used when accessing the PECI hardware.
//
// Copyright (c) 2010-2012 Texas Instruments Incorporated.  All rights reserved.
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
// This is part of revision 9453 of the Stellaris Firmware Development Package.
//
//*****************************************************************************

#ifndef __HW_PECI_H__
#define __HW_PECI_H__

//*****************************************************************************
//
// The following are defines for the PECI register addresses.
//
//*****************************************************************************
#define PECI_O_CTL              0x00000000  // PECI Control
#define PECI_O_DIV              0x00000004  // PECI Poll-Rate Divider
#define PECI_O_M0D0C            0x00000010  // PECI Microprocessor 0 / Domain 0
                                            // Control
#define PECI_O_M0D1C            0x00000014  // PECI Microprocessor 0 / Domain 1
                                            // Control
#define PECI_O_M1D0C            0x00000018  // PECI Microprocessor 1 / Domain 0
                                            // Control
#define PECI_O_M1D1C            0x0000001C  // PECI Microprocessor 1 / Domain 1
                                            // Control
#define PECI_O_M0D0             0x00000040  // PECI Microprocessor 0 / Domain 0
                                            // Value
#define PECI_O_M0D1             0x00000044  // PECI Microprocessor 0 / Domain 1
                                            // Value
#define PECI_O_M1D0             0x00000048  // PECI Microprocessor 1 / Domain 0
                                            // Value
#define PECI_O_M1D1             0x0000004C  // PECI Microprocessor 1 / Domain 1
                                            // Value
#define PECI_O_IM               0x00000080  // PECI Interrupt Mask
#define PECI_O_RIS              0x00000084  // PECI Raw Interrupt Status
#define PECI_O_MIS              0x00000088  // PECI Masked Interrupt Status
#define PECI_O_IC               0x0000008C  // PECI Interrupt Clear
#define PECI_O_ACADDR           0x00000100  // PECI Advanced Command Address
#define PECI_O_ACARG            0x00000104  // PECI Advanced Command Argument
#define PECI_O_ACRDWR0          0x00000108  // PECI Advanced Command Data 0
#define PECI_O_ACRDWR1          0x0000010C  // PECI Advanced Command Data 1
#define PECI_O_ACCMD            0x00000110  // PECI Advanced Command
#define PECI_O_ACCODE           0x00000114  // PECI Advanced Command Completion
                                            // Code

//*****************************************************************************
//
// The following are defines for the bit fields in the PECI_O_CTL register.
//
//*****************************************************************************
#define PECI_CTL_OFFSET_M       0xFFFF0000  // Offset Value
#define PECI_CTL_CRETRY_M       0x00007000  // Number of Controller Retries
#define PECI_CTL_BYERR          0x00000800  // Timing Negotiation Error Bypass
#define PECI_CTL_RXINV          0x00000400  // Invert PECI RX Input
#define PECI_CTL_M1D1EN         0x00000008  // Enable Microprocessor 1 and
                                            // Domain 1
#define PECI_CTL_M1D0EN         0x00000004  // Enable Microprocessor 1 and
                                            // Domain 0
#define PECI_CTL_M0D1EN         0x00000002  // Enable Microprocessor 0 and
                                            // Domain 1
#define PECI_CTL_M0D0EN         0x00000001  // Enable Microprocessor 0 and
                                            // Domain 0
#define PECI_CTL_OFFSET_S       16
#define PECI_CTL_CRETRY_S       12

//*****************************************************************************
//
// The following are defines for the bit fields in the PECI_O_DIV register.
//
//*****************************************************************************
#define PECI_DIV_BAUD_M         0xFFFF0000  // Baud Rate
#define PECI_DIV_POLL_M         0x0000FFFF  // Counter for Inter-Poll Delay
#define PECI_DIV_BAUD_S         16
#define PECI_DIV_POLL_S         0

//*****************************************************************************
//
// The following are defines for the bit fields in the PECI_O_M0D0C register.
//
//*****************************************************************************
#define PECI_M0D0C_HITHR_M      0xFFFF0000  // High Threshold
#define PECI_M0D0C_LOTHR_M      0x0000FFFF  // Low Threshold
#define PECI_M0D0C_HITHR_S      16
#define PECI_M0D0C_LOTHR_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the PECI_O_M0D1C register.
//
//*****************************************************************************
#define PECI_M0D1C_HITHR_M      0xFFFF0000  // High Threshold
#define PECI_M0D1C_LOTHR_M      0x0000FFFF  // Low Threshold
#define PECI_M0D1C_HITHR_S      16
#define PECI_M0D1C_LOTHR_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the PECI_O_M1D0C register.
//
//*****************************************************************************
#define PECI_M1D0C_HITHR_M      0xFFFF0000  // High Threshold
#define PECI_M1D0C_LOTHR_M      0x0000FFFF  // Low Threshold
#define PECI_M1D0C_HITHR_S      16
#define PECI_M1D0C_LOTHR_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the PECI_O_M1D1C register.
//
//*****************************************************************************
#define PECI_M1D1C_HITHR_M      0xFFFF0000  // High Threshold
#define PECI_M1D1C_LOTHR_M      0x0000FFFF  // Low Threshold
#define PECI_M1D1C_HITHR_S      16
#define PECI_M1D1C_LOTHR_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the PECI_O_M0D0 register.
//
//*****************************************************************************
#define PECI_M0D0_MAXREAD_M     0xFFFF0000  // Highest Value Read
#define PECI_M0D0_VALUE_M       0x0000FFFF  // Last Value Read
#define PECI_M0D0_VALUE_MCRCTX  0x000081F9  // Microprocessor abort CRC error
                                            // on transmitted data
#define PECI_M0D0_VALUE_CRCRX   0x000081FA  // CRC error on received data
#define PECI_M0D0_VALUE_CRCTX   0x000081FB  // CRC error on transmitted data
#define PECI_M0D0_VALUE_NEG     0x000081FC  // Negotiation error
#define PECI_M0D0_VALUE_TO      0x000081FD  // Timeout error
#define PECI_M0D0_MAXREAD_S     16

//*****************************************************************************
//
// The following are defines for the bit fields in the PECI_O_M0D1 register.
//
//*****************************************************************************
#define PECI_M0D1_MAXREAD_M     0xFFFF0000  // Highest Value Read
#define PECI_M0D1_VALUE_M       0x0000FFFF  // Last Value Read
#define PECI_M0D1_VALUE_MCRCTX  0x000081F9  // Microprocessor abort CRC error
                                            // on transmitted data
#define PECI_M0D1_VALUE_CRCRX   0x000081FA  // CRC error on received data
#define PECI_M0D1_VALUE_CRCTX   0x000081FB  // CRC error on transmitted data
#define PECI_M0D1_VALUE_NEG     0x000081FC  // Negotiation error
#define PECI_M0D1_VALUE_TO      0x000081FD  // Timeout error
#define PECI_M0D1_MAXREAD_S     16

//*****************************************************************************
//
// The following are defines for the bit fields in the PECI_O_M1D0 register.
//
//*****************************************************************************
#define PECI_M1D0_MAXREAD_M     0xFFFF0000  // Highest Value Read
#define PECI_M1D0_VALUE_M       0x0000FFFF  // Last Value Read
#define PECI_M1D0_VALUE_MCRCTX  0x000081F9  // Microprocessor abort CRC error
                                            // on transmitted data
#define PECI_M1D0_VALUE_CRCRX   0x000081FA  // CRC error on received data
#define PECI_M1D0_VALUE_CRCTX   0x000081FB  // CRC error on transmitted data
#define PECI_M1D0_VALUE_NEG     0x000081FC  // Negotiation error
#define PECI_M1D0_VALUE_TO      0x000081FD  // Timeout error
#define PECI_M1D0_MAXREAD_S     16

//*****************************************************************************
//
// The following are defines for the bit fields in the PECI_O_M1D1 register.
//
//*****************************************************************************
#define PECI_M1D1_MAXREAD_M     0xFFFF0000  // Highest Value Read
#define PECI_M1D1_VALUE_M       0x0000FFFF  // Last Value Read
#define PECI_M1D1_VALUE_MCRCTX  0x000081F9  // Microprocessor abort CRC error
                                            // on transmitted data
#define PECI_M1D1_VALUE_CRCRX   0x000081FA  // CRC error on received data
#define PECI_M1D1_VALUE_CRCTX   0x000081FB  // CRC error on transmitted data
#define PECI_M1D1_VALUE_NEG     0x000081FC  // Negotiation error
#define PECI_M1D1_VALUE_TO      0x000081FD  // Timeout error
#define PECI_M1D1_MAXREAD_S     16

//*****************************************************************************
//
// The following are defines for the bit fields in the PECI_O_IM register.
//
//*****************************************************************************
#define PECI_IM_M1D1IM_M        0x00C00000  // Microprocessor 1 and Domain 1
                                            // Interrupt Mask
#define PECI_IM_M1D1IM_HIGH     0x00400000  // Interrupt when crossing above
                                            // high threshold
#define PECI_IM_M1D1IM_CROSSUP  0x00800000  // Interrupt when crossing above
                                            // either threshold
#define PECI_IM_M1D1IM_CROSSANY 0x00C00000  // Interrupt when crossing either
                                            // threshold in either direction
#define PECI_IM_M1D0IM_M        0x00300000  // Microprocessor 1 and Domain 0
                                            // Interrupt Mask
#define PECI_IM_M0D1IM_M        0x000C0000  // Microprocessor 0 and Domain 1
                                            // Interrupt Mask
#define PECI_IM_M0D0IM_M        0x00030000  // Microprocessor 0 and Domain 0
                                            // Interrupt Mask
#define PECI_IM_ACIM            0x00000004  // Advanced Command Interrupt Mask
#define PECI_IM_ERRIM           0x00000002  // Polling Error Detected Interrupt
                                            // Mask
#define PECI_IM_POLLIM          0x00000001  // Poll Completed Interrupt Mask
#define PECI_IM_M1D0IM_S        20
#define PECI_IM_M0D1IM_S        18
#define PECI_IM_M0D0IM_S        16

//*****************************************************************************
//
// The following are defines for the bit fields in the PECI_O_RIS register.
//
//*****************************************************************************
#define PECI_RIS_M1D1RIS_M      0x00C00000  // Microprocessor 1 and Domain 1
                                            // Raw Interrupt Status
#define PECI_RIS_M1D0RIS_M      0x00300000  // Microprocessor 1 and Domain 0
                                            // Raw Interrupt Status
#define PECI_RIS_M0D1RIS_M      0x000C0000  // Microprocessor 0 and Domain 1
                                            // Raw Interrupt Status
#define PECI_RIS_M0D0RIS_M      0x00030000  // Microprocessor 0 and Domain 0
                                            // Raw Interrupt Status
#define PECI_RIS_ACRIS          0x00000004  // Advanced Command Raw Interrupt
                                            // Status
#define PECI_RIS_ERRRIS         0x00000002  // Polling Error Detected Raw
                                            // Interrupt Status
#define PECI_RIS_POLLRIS        0x00000001  // Poll Completed Raw Interrupt
                                            // Status
#define PECI_RIS_M1D1RIS_S      22
#define PECI_RIS_M1D0RIS_S      20
#define PECI_RIS_M0D1RIS_S      18
#define PECI_RIS_M0D0RIS_S      16

//*****************************************************************************
//
// The following are defines for the bit fields in the PECI_O_MIS register.
//
//*****************************************************************************
#define PECI_MIS_M1D1MIS_M      0x00C00000  // Microprocessor 1 and Domain 1
                                            // Masked Interrupt Status
#define PECI_MIS_M1D0MIS_M      0x00300000  // Microprocessor 1 and Domain 0
                                            // Masked Interrupt Status
#define PECI_MIS_M0D1MIS_M      0x000C0000  // Microprocessor 0 and Domain 1
                                            // Masked Interrupt Status
#define PECI_MIS_M0D0MIS_M      0x00030000  // Microprocessor 0 and Domain 0
                                            // Masked Interrupt Status
#define PECI_MIS_ACMIS          0x00000004  // Advanced Command Masked
                                            // Interrupt Status
#define PECI_MIS_ERRMIS         0x00000002  // Polling Error Detected Masked
                                            // Interrupt Status
#define PECI_MIS_POLLMIS        0x00000001  // Poll Completed Masked Interrupt
                                            // Status
#define PECI_MIS_M1D1MIS_S      22
#define PECI_MIS_M1D0MIS_S      20
#define PECI_MIS_M0D1MIS_S      18
#define PECI_MIS_M0D0MIS_S      16

//*****************************************************************************
//
// The following are defines for the bit fields in the PECI_O_IC register.
//
//*****************************************************************************
#define PECI_IC_M1D1IC_M        0x00C00000  // Microprocessor 1 and Domain 1
                                            // Interrupt Clear
#define PECI_IC_M1D0IC_M        0x00300000  // Microprocessor 1 and Domain 0
                                            // Interrupt Clear
#define PECI_IC_M0D1IC_M        0x000C0000  // Microprocessor 0 and Domain 1
                                            // Interrupt Clear
#define PECI_IC_M0D0IC_M        0x00030000  // Microprocessor 0 and Domain 0
                                            // Interrupt Clear
#define PECI_IC_ACIC            0x00000004  // Advanced Command Interrupt Clear
#define PECI_IC_ERRIC           0x00000002  // Polling Error Detected Interrupt
                                            // Clear
#define PECI_IC_POLLIC          0x00000001  // Poll Completed Interrupt Clear
#define PECI_IC_M1D1IC_S        22
#define PECI_IC_M1D0IC_S        20
#define PECI_IC_M0D1IC_S        18
#define PECI_IC_M0D0IC_S        16

//*****************************************************************************
//
// The following are defines for the bit fields in the PECI_O_ACADDR register.
//
//*****************************************************************************
#define PECI_ACADDR_HIDRE_M     0xFF000000  // HostID and Retry
#define PECI_ACADDR_SIZE_M      0x00FF0000  // Data Size
#define PECI_ACADDR_DOMAIN_M    0x0000FF00  // Domain Select
#define PECI_ACADDR_PROCADD_M   0x000000FF  // Processor Address
#define PECI_ACADDR_HIDRE_S     24
#define PECI_ACADDR_SIZE_S      16
#define PECI_ACADDR_DOMAIN_S    8
#define PECI_ACADDR_PROCADD_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the PECI_O_ACARG register.
//
//*****************************************************************************
#define PECI_ACARG_ARG3_M       0xFF000000  // Argument 3
#define PECI_ACARG_ARG2_M       0x00FF0000  // Argument 2
#define PECI_ACARG_ARG1_M       0x0000FF00  // Argument 1
#define PECI_ACARG_ARG0_M       0x000000FF  // Argument 0
#define PECI_ACARG_ARG3_S       24
#define PECI_ACARG_ARG2_S       16
#define PECI_ACARG_ARG1_S       8
#define PECI_ACARG_ARG0_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the PECI_O_ACRDWR0 register.
//
//*****************************************************************************
#define PECI_ACRDWR0_D3_M       0xFF000000  // Data 3
#define PECI_ACRDWR0_D2_M       0x00FF0000  // Data 2
#define PECI_ACRDWR0_D1_M       0x0000FF00  // Data 1
#define PECI_ACRDWR0_D0_M       0x000000FF  // Data 0
#define PECI_ACRDWR0_D3_S       24
#define PECI_ACRDWR0_D2_S       16
#define PECI_ACRDWR0_D1_S       8
#define PECI_ACRDWR0_D0_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the PECI_O_ACRDWR1 register.
//
//*****************************************************************************
#define PECI_ACRDWR1_D3_M       0xFF000000  // Data 3
#define PECI_ACRDWR1_D2_M       0x00FF0000  // Data 2
#define PECI_ACRDWR1_D1_M       0x0000FF00  // Data 1
#define PECI_ACRDWR1_D0_M       0x000000FF  // Data 0
#define PECI_ACRDWR1_D3_S       24
#define PECI_ACRDWR1_D2_S       16
#define PECI_ACRDWR1_D1_S       8
#define PECI_ACRDWR1_D0_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the PECI_O_ACCMD register.
//
//*****************************************************************************
#define PECI_ACCMD_CMD_M        0x000000FF  // Base Command
#define PECI_ACCMD_CMD_S        0

//*****************************************************************************
//
// The following are defines for the bit fields in the PECI_O_ACCODE register.
//
//*****************************************************************************
#define PECI_ACCODE_CODE_M      0xFFFFFFFF  // Signed Completion Code

#endif // __HW_PECI_H__
