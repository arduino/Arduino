/******************************************************************************
*  Filename:       hw_ddi.h
*  Revised:        2015-03-04 17:53:59 +0100 (Wed, 04 Mar 2015)
*  Revision:       42892
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

#ifndef __HW_DDI_H__
#define __HW_DDI_H__

//*****************************************************************************
//
// This file contains macros for controlling the DDI master and
// accessing DDI Slave registers via the DDI Master.
// There are 3 categories of macros in this file:
//                 - macros that provide an offset to a register
//                   located within the DDI Master itself.
//                 - macros that define bits or bitfields
//                   within the DDI Master Registers.
//                 - macros that provide an "instruction offset"
//                   that are used when accessing a DDI Slave.
//
// The macros that that provide DDI Master register offsets and
// define bits and bitfields for those registers are the typical
// macros that appear in most hw_<module>.h header files.  In
// the following example DDI_O_CFG is a macro for a
// register offset and DDI_CFG_WAITFORACK is a macro for
// a bit in that register. This example code will set the WAITFORACK
// bit in register DDI_O_CFG of the DDI Master. (Note: this
// access the Master not the Slave).
//
//    HWREG(AUX_OSCDDI_BASE + DDI_O_CFG) |= DDI_CFG_WAITFORACK;
//
//
// The "instruction offset" macros are used to pass an instruction to
// the DDI Master when accessing DDI slave registers. These macros are
// only used when accessing DDI Slave Registers. (Remember DDI
// Master Registers are accessed normally).
//
// The instructions supported when accessing a DDI Slave Regsiter follow:
//        - Direct Access to a DDI Slave register. I.e. read or
//          write the register.
//        - Set the specified bits in a DDI Slave register.
//        - Clear the specified bits in a DDI Slave register.
//        - Mask write of 4 bits to the a DDI Slave register.
//        - Mask write of 8 bits to the a DDI Slave register.
//        - Mask write of 16 bits to the a DDI Slave register.
//
// Note: only the "Direct Access" offset should be used when reading
// a DDI Slave register. Only 8- and 16-bit reads are supported.
//
// The generic format of using this marcos for a read follows:
//       // read low 16-bits in DDI_SLAVE_OFF
//       myushortvar = HWREGH(DDI_MASTER_BASE + DDI_SLAVE_OFF + DDI_O_DIR);
//
//       // read high 16-bits in DDI_SLAVE_OFF
//       // add 2 for data[31:16]
//       myushortvar = HWREGH(DDI_MASTER_BASE + DDI_SLAVE_OFF + 2 + DDI_O_DIR);

//       // read data[31:24] byte in DDI_SLAVE_OFF
//       // add 3 for data[31:24]
//       myuchar = HWREGB(DDI_MASTER_BASE + DDI_SLAVE_OFF + 3 + DDI_O_DIR);
//
// Notes: In the above example:
//     - DDI_MASTER_BASE is the base address of the DDI Master defined
//       in the hw_memmap.h header file.
//     - DDI_SLAVE_OFF is the DDI Slave offset defined in the
//       hw_<ddi_slave>.h header file (e.g. hw_osc_top.h for the oscsc
//       oscillator modules.
//     - DDI_O_DIR is the "instruction offset" macro defined in this
//       file that specifies the Direct Access instruction.
//
// Writes can use any of the "instruction macros".
// The following examples do a "direct write" to DDI Slave register
// DDI_SLAVE_OFF using different size operands:
//
//     // ---------- DIRECT WRITES ----------
//     // Write 32-bits aligned
//     HWREG(DDI_MASTER_BASE + DDI_SLAVE_OFF + DDI_O_DIR) = 0x12345678;

//     // Write 16-bits aligned to high 16-bits then low 16-bits
//     // Add 2 to get to high 16-bits.
//     HWREGH(DDI_MASTER_BASE + DDI_SLAVE_OFF + DDI_O_DIR + 2) = 0xabcd;
//     HWREGH(DDI_MASTER_BASE + DDI_SLAVE_OFF + DDI_O_DIR) = 0xef01;
//
//     // Write each byte at DDI_SLAVE_OFF, one at a time.
//     // Add 1,2,or 3 to get to bytes 1,2, or 3.
//     HWREGB(DDI_MASTER_BASE + DDI_SLAVE_OFF + DDI_O_DIR) = 0x33;
//     HWREGB(DDI_MASTER_BASE + DDI_SLAVE_OFF + DDI_O_DIR + 1) = 0x44;
//     HWREGB(DDI_MASTER_BASE + DDI_SLAVE_OFF + DDI_O_DIR + 2) = 0x55;
//     HWREGB(DDI_MASTER_BASE + DDI_SLAVE_OFF + DDI_O_DIR + 3) = 0x66;
//
//     // ---------- SET/CLR ----------
//     The set and clear functions behave similarly to eachother. Each
//     can be performed on an 8-, 16-, or 32-bit operand.
//     Examples follow:
//     // Set all odd bits in a 32-bit words
//     HWREG(DDI_MASTER_BASE + DDI_SLAVE_OFF + DDI_O_SET) = 0xaaaaaaaa;
//
//     // Clear all bits in byte 2 (data[23:16]) using 32-bit operand
//     HWREG(DDI_MASTER_BASE + DDI_SLAVE_OFF + DDI_O_CLR) = 0x00ff0000;
//
//     // Set even bits in byte 2 (data[23:16]) using 8-bit operand
//     HWREGB(DDI_MASTER_BASE + DDI_SLAVE_OFF  + 2 + DDI_O_CLR) = 0x55;
//
//     // ---------- MASKED WRITES ----------
//     The mask writes are a bit different. They operate on nibbles,
//     bytes, and 16-bit elements. Two operands are required; a 'mask'
//     and 'data'; The operands are concatenated and written to the master.
//     e.g. the mask and data are combined as follows for a 16 bit masked
//     write:
//           (mask << 16) | data;
//     Examples follow:
//
//     // Write 5555 to low 16-bits of DDI_SLAVE_OFF register
//     // a long write is needed (32-bits).
//     HWREG(DDI_MASTER_BASE + DDI_SLAVE_OFF + DDI_O_MASK16B) = 0xffff5555;

//     // Write 1AA to data bits 24:16 in high 16-bits of DDI_SLAVE_OFF register
//     // Note add 4 for high 16-bits at DDI_SLAVE_OFF; mask is 1ff!
//     HWREG(DDI_MASTER_BASE + DDI_SLAVE_OFF + DDI_O_MASK16B + 4) = 0x01ff01aa;
//
//     // Do an 8 bit masked write of 00 to low byte of register (data[7:0]).
//     // a short write is needed (16-bits).
//     HWREGH(DDI_MASTER_BASE + DDI_SLAVE_OFF + DDI_O_MASK16B) = 0xff00;
//
//     // Do an 8 bit masked write of 11 to byte 1 of register (data[15:8]).
//     // add 2 to get to byte 1.
//     HWREGH(DDI_MASTER_BASE + DDI_SLAVE_OFF + DDI_O_MASK16B + 2) = 0xff11;
//
//     // Do an 8 bit masked write of 33 to high byte of register (data[31:24]).
//     // add 6 to get to byte 3.
//     HWREGH(DDI_MASTER_BASE + DDI_SLAVE_OFF + DDI_O_MASK16B + 6) = 0xff33;
//
//     // Do an 4 bit masked write (Nibble) of 7 to data[3:0]).
//     // Byte write is needed.
//     HWREGB(DDI_MASTER_BASE + DDI_SLAVE_OFF + DDI_O_MASK16B) = 0xf7;
//
//     // Do an 4 bit masked write of 4 to data[7:4]).
//     // Add 1 for next nibble
//     HWREGB(DDI_MASTER_BASE + DDI_SLAVE_OFF + DDI_O_MASK16B + 1) = 0xf4;
//
//*****************************************************************************

//*****************************************************************************
//
// The following are defines for the DDI master instruction offsets.
//
//*****************************************************************************
#define DDI_O_DIR             0x00000000  // Offset for the direct access instruction
#define DDI_O_SET             0x00000040  // Offset for 'Set' instruction.
#define DDI_O_CLR             0x00000080  // Offset for 'Clear' instruction.
#define DDI_O_MASK4B          0x00000100  // Offset for 4-bit masked access.
                                          // Data bit[n] is written if mask bit[n] is set ('1').
                                          // Bits 7:4 are mask. Bits 3:0 are data.
                                          // Requires 'byte' write.
#define DDI_O_MASK8B          0x00000180  // Offset for 8-bit masked access.
                                          // Data bit[n] is written if mask bit[n] is set ('1').
                                          // Bits 15:8 are mask. Bits 7:0 are data.
                                          // Requires 'short' write.
#define DDI_O_MASK16B         0x00000200  // Offset for 16-bit masked access.
                                          // Data bit[n] is written if mask bit[n] is set ('1').
                                          // Bits 31:16 are mask. Bits 15:0 are data.
                                          // Requires 'long' write.

//*****************************************************************************
//
// The following are defines for the DDI register offsets.
//
//*****************************************************************************
#define DDI_O_SYNC              0x000000C0  // DDI Slave status register
#define DDI_O_CFG               0x000000C8  // DDI Slave configuration
                                            // register

//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_SYNC register.
//
//*****************************************************************************
#define DDI_SYNC_DI_REQ         0x00000002  // Read current value of DI_REQ
                                            // signal. Writing 0 to this bit
                                            // forces a sync with slave,
                                            // ensuring that req will be 0. It
                                            // is recommended to write 0 to
                                            // this register before power down
                                            // of the master.
#define DDI_SYNC_DI_REQ_M       0x00000002
#define DDI_SYNC_DI_REQ_S       1
#define DDI_SYNC_DI_ACK         0x00000001  // Read current value of DI_ACK
                                            // signal
#define DDI_SYNC_DI_ACK_M       0x00000001
#define DDI_SYNC_DI_ACK_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_CFG register.
//
//*****************************************************************************
#define DDI_CFG_CONFLOCK        0x00000080  // This register is no longer
                                            // accessible when this bit is set.
                                            // (unless sticky_bit_overwrite is
                                            // asserted on top module)
#define DDI_CFG_CONFLOCK_M      0x00000080
#define DDI_CFG_CONFLOCK_S      7
#define DDI_CFG_WAITFORACK      0x00000004  // A transaction does not end
                                            // until ack has been received when
                                            // this bit is set.

#define DDI_CFG_WAITFORACK_M    0x00000004
#define DDI_CFG_WAITFORACK_S    2
#define DDI_CFG_DDICLKSPEED_M   0x00000003  // Sets the period of an DDI
                                            // transactions. All transactions
                                            // takes an even number of clock
                                            // cycles,- DDI clock rising edge
                                            // occurs in the middle of the
                                            // period. Data and ctrl to slave
                                            // is set up in beginning of cycle,
                                            // and data from slave is read in
                                            // after the transaction 00: An DDI
                                            // transaction takes 2 master clock
                                            // cyclkes 01: An DDI transaction
                                            // takes 4 master clock cycles 10:
                                            // And DDI Transaction takes 8
                                            // master clock cycles 11: An DDI
                                            // transaction takes 16 master
                                            // clock cycles

#define DDI_CFG_DDICLKSPEED_S   0

//*****************************************************************************
//
// The following are defines pseudo-magic numbers that should go away.
// New code should not use these registers and old code should be ported
// to not use these.
//
//*****************************************************************************
#define DDI_O_DIR03             0x00000000  // Direct access for DDI byte
                                            // offsets 0 to 3
#define DDI_O_DIR47             0x00000004  // Direct access for DDI byte
                                            // offsets 4 to 7
#define DDI_O_DIR811            0x00000008  // Direct access for DDI byte
                                            // offsets 8 to 11
#define DDI_O_DIR1215           0x0000000C  // Direct access for DDI byte
                                            // offsets 12 to 15
#define DDI_O_DIR1619           0x00000010  // Direct access for DDI byte
                                            // offsets 16 to 19
#define DDI_O_DIR2023           0x00000014  // Direct access for DDI byte
                                            // offsets 20 to 23
#define DDI_O_DIR2427           0x00000018  // Direct access for DDI byte
                                            // offsets 24 to 27
#define DDI_O_DIR2831           0x0000001C  // Direct access for DDI byte
                                            // offsets 28 to 31
#define DDI_O_DIR3235           0x00000020  // Direct access for DDI byte
                                            // offsets 32 to 35
#define DDI_O_DIR3639           0x00000024  // Direct access for DDI byte
                                            // offsets 36 to 39
#define DDI_O_DIR4043           0x00000028  // Direct access for DDI byte
                                            // offsets 40 to 43
#define DDI_O_DIR4447           0x0000002C  // Direct access for DDI byte
                                            // offsets 44 to 47
#define DDI_O_DIR4851           0x00000030  // Direct access for DDI byte
                                            // offsets 48 to 51
#define DDI_O_DIR5255           0x00000034  // Direct access for DDI byte
                                            // offsets 52 to 55
#define DDI_O_DIR5659           0x00000038  // Direct access for DDI byte
                                            // offsets 56 to 59
#define DDI_O_DIR6063           0x0000003C  // Direct access for DDI byte
                                            // offsets 60 to 63
#define DDI_O_SET03             0x00000040  // Set register for DDI byte
                                            // offsets 0 to 3
#define DDI_O_SET47             0x00000044  // Set register for DDI byte
                                            // offsets 4 to 7
#define DDI_O_SET811            0x00000048  // Set register for DDI byte
                                            // offsets 8 to 11
#define DDI_O_SET1215           0x0000004C  // Set register for DDI byte
                                            // offsets 12 to 15
#define DDI_O_SET1619           0x00000050  // Set register for DDI byte
                                            // offsets 16 to 19
#define DDI_O_SET2023           0x00000054  // Set register for DDI byte
                                            // offsets 20 to 23
#define DDI_O_SET2427           0x00000058  // Set register for DDI byte
                                            // offsets 24 to 27
#define DDI_O_SET2831           0x0000005C  // Set register for DDI byte
                                            // offsets 28 to 31
#define DDI_O_SET3235           0x00000060  // Set register for DDI byte
                                            // offsets 32 to 35
#define DDI_O_SET3639           0x00000064  // Set register for DDI byte
                                            // offsets 36 to 39
#define DDI_O_SET4043           0x00000068  // Set register for DDI byte
                                            // offsets 40 to 43
#define DDI_O_SET4447           0x0000006C  // Set register for DDI byte
                                            // offsets 44 to 47
#define DDI_O_SET4851           0x00000070  // Set register for DDI byte
                                            // offsets 48 to 51
#define DDI_O_SET5255           0x00000074  // Set register for DDI byte
                                            // offsets 52 to 55
#define DDI_O_SET5659           0x00000078  // Set register for DDI byte
                                            // offsets 56 to 59
#define DDI_O_SET6063           0x0000007C  // Set register for DDI byte
                                            // offsets 60 to 63
#define DDI_O_CLR03             0x00000080  // Clear register for DDI byte
                                            // offsets 0 to 3
#define DDI_O_CLR47             0x00000084  // Clear register for DDI byte
                                            // offsets 4 to 7
#define DDI_O_CLR811            0x00000088  // Clear register for DDI byte
                                            // offsets 8 to 11
#define DDI_O_CLR1215           0x0000008C  // Clear register for DDI byte
                                            // offsets 12 to 15
#define DDI_O_CLR1619           0x00000090  // Clear register for DDI byte
                                            // offsets 16 to 19
#define DDI_O_CLR2023           0x00000094  // Clear register for DDI byte
                                            // offsets 20 to 23
#define DDI_O_CLR2427           0x00000098  // Clear register for DDI byte
                                            // offsets 24 to 27
#define DDI_O_CLR2831           0x0000009C  // Clear register for DDI byte
                                            // offsets 28 to 31
#define DDI_O_CLR3235           0x000000A0  // Clear register for DDI byte
                                            // offsets 32 to 35
#define DDI_O_CLR3639           0x000000A4  // Clear register for DDI byte
                                            // offsets 36 to 39
#define DDI_O_CLR4043           0x000000A8  // Clear register for DDI byte
                                            // offsets 40 to 43
#define DDI_O_CLR4447           0x000000AC  // Clear register for DDI byte
                                            // offsets 44 to 47
#define DDI_O_CLR4851           0x000000B0  // Clear register for DDI byte
                                            // offsets 48 to 51
#define DDI_O_CLR5255           0x000000B4  // Clear register for DDI byte
                                            // offsets 52 to 55
#define DDI_O_CLR5659           0x000000B8  // Clear register for DDI byte
                                            // offsets 56 to 59
#define DDI_O_CLR6063           0x000000BC  // Clear register for DDI byte
                                            // offsets 60 to 63
#define DDI_O_MASK4B01          0x00000100  // Masked access (4m/4d) for DDI
                                            // Registers at byte offsets 0 and
                                            // 1
#define DDI_O_MASK4B23          0x00000104  // Masked access (4m/4d) for DDI
                                            // Registers at byte offsets 2 and
                                            // 3
#define DDI_O_MASK4B45          0x00000108  // Masked access (4m/4d) for DDI
                                            // Registers at byte offsets 4 and
                                            // 5
#define DDI_O_MASK4B67          0x0000010C  // Masked access (4m/4d) for DDI
                                            // Registers at byte offsets 6 and
                                            // 7
#define DDI_O_MASK4B89          0x00000110  // Masked access (4m/4d) for DDI
                                            // Registers at byte offsets 8 and
                                            // 9
#define DDI_O_MASK4B1011        0x00000114  // Masked access (4m/4d) for DDI
                                            // Registers at byte offsets 10 and
                                            // 11
#define DDI_O_MASK4B1213        0x00000118  // Masked access (4m/4d) for DDI
                                            // Registers at byte offsets 12 and
                                            // 13
#define DDI_O_MASK4B1415        0x0000011C  // Masked access (4m/4d) for DDI
                                            // Registers at byte offsets 14 and
                                            // 15
#define DDI_O_MASK4B1617        0x00000120  // Masked access (4m/4d) for DDI
                                            // Registers at byte offsets 16 and
                                            // 17
#define DDI_O_MASK4B1819        0x00000124  // Masked access (4m/4d) for DDI
                                            // Registers at byte offsets 18 and
                                            // 19
#define DDI_O_MASK4B2021        0x00000128  // Masked access (4m/4d) for DDI
                                            // Registers at byte offsets 20 and
                                            // 21
#define DDI_O_MASK4B2223        0x0000012C  // Masked access (4m/4d) for DDI
                                            // Registers at byte offsets 22 and
                                            // 23
#define DDI_O_MASK4B2425        0x00000130  // Masked access (4m/4d) for DDI
                                            // Registers at byte offsets 24 and
                                            // 25
#define DDI_O_MASK4B2627        0x00000134  // Masked access (4m/4d) for DDI
                                            // Registers at byte offsets 26 and
                                            // 27
#define DDI_O_MASK4B2829        0x00000138  // Masked access (4m/4d) for DDI
                                            // Registers at byte offsets 28 and
                                            // 29
#define DDI_O_MASK4B3031        0x0000013C  // Masked access (4m/4d) for DDI
                                            // Registers at byte offsets 30 and
                                            // 31
#define DDI_O_MASK4B3233        0x00000140  // Masked access (4m/4d) for DDI
                                            // Registers at byte offsets 32 and
                                            // 33
#define DDI_O_MASK4B3435        0x00000144  // Masked access (4m/4d) for DDI
                                            // Registers at byte offsets 34 and
                                            // 35
#define DDI_O_MASK4B3637        0x00000148  // Masked access (4m/4d) for DDI
                                            // Registers at byte offsets 36 and
                                            // 37
#define DDI_O_MASK4B3839        0x0000014C  // Masked access (4m/4d) for DDI
                                            // Registers at byte offsets 38 and
                                            // 39
#define DDI_O_MASK4B4041        0x00000150  // Masked access (4m/4d) for DDI
                                            // Registers at byte offsets 40 and
                                            // 41
#define DDI_O_MASK4B4243        0x00000154  // Masked access (4m/4d) for DDI
                                            // Registers at byte offsets 42 and
                                            // 43
#define DDI_O_MASK4B4445        0x00000158  // Masked access (4m/4d) for DDI
                                            // Registers at byte offsets 44 and
                                            // 45
#define DDI_O_MASK4B4647        0x0000015C  // Masked access (4m/4d) for DDI
                                            // Registers at byte offsets 46 and
                                            // 47
#define DDI_O_MASK4B4849        0x00000160  // Masked access (4m/4d) for DDI
                                            // Registers at byte offsets 48 and
                                            // 49
#define DDI_O_MASK4B5051        0x00000164  // Masked access (4m/4d) for DDI
                                            // Registers at byte offsets 50 and
                                            // 51
#define DDI_O_MASK4B5253        0x00000168  // Masked access (4m/4d) for DDI
                                            // Registers at byte offsets 52 and
                                            // 53
#define DDI_O_MASK4B5455        0x0000016C  // Masked access (4m/4d) for DDI
                                            // Registers at byte offsets 54 and
                                            // 55
#define DDI_O_MASK4B5657        0x00000170  // Masked access (4m/4d) for DDI
                                            // Registers at byte offsets 56 and
                                            // 57
#define DDI_O_MASK4B5859        0x00000174  // Masked access (4m/4d) for DDI
                                            // Registers at byte offsets 58 and
                                            // 59
#define DDI_O_MASK4B6061        0x00000178  // Masked access (4m/4d) for DDI
                                            // Registers at byte offsets 60 and
                                            // 61
#define DDI_O_MASK4B6263        0x0000017C  // Masked access (4m/4d) for DDI
                                            // Registers at byte offsets 62 and
                                            // 63
#define DDI_O_MASK8B01          0x00000180  // Masked access (8m/8d) for DDI
                                            // Registers at byte offsets 0 and
                                            // 1
#define DDI_O_MASK8B23          0x00000184  // Masked access (8m/8d) for DDI
                                            // Registers at byte offsets 2 and
                                            // 3
#define DDI_O_MASK8B45          0x00000188  // Masked access (8m/8d) for DDI
                                            // Registers at byte offsets 4 and
                                            // 5
#define DDI_O_MASK8B67          0x0000018C  // Masked access (8m/8d) for DDI
                                            // Registers at byte offsets 6 and
                                            // 7
#define DDI_O_MASK8B89          0x00000190  // Masked access (8m/8d) for DDI
                                            // Registers at byte offsets 8 and
                                            // 9
#define DDI_O_MASK8B1011        0x00000194  // Masked access (8m/8d) for DDI
                                            // Registers at byte offsets 10 and
                                            // 11
#define DDI_O_MASK8B1213        0x00000198  // Masked access (8m/8d) for DDI
                                            // Registers at byte offsets 12 and
                                            // 13
#define DDI_O_MASK8B1415        0x0000019C  // Masked access (8m/8d) for DDI
                                            // Registers at byte offsets 14 and
                                            // 15
#define DDI_O_MASK8B1617        0x000001A0  // Masked access (8m/8d) for DDI
                                            // Registers at byte offsets 16 and
                                            // 17
#define DDI_O_MASK8B1819        0x000001A4  // Masked access (8m/8d) for DDI
                                            // Registers at byte offsets 18 and
                                            // 19
#define DDI_O_MASK8B2021        0x000001A8  // Masked access (8m/8d) for DDI
                                            // Registers at byte offsets 20 and
                                            // 21
#define DDI_O_MASK8B2223        0x000001AC  // Masked access (8m/8d) for DDI
                                            // Registers at byte offsets 22 and
                                            // 23
#define DDI_O_MASK8B2425        0x000001B0  // Masked access (8m/8d) for DDI
                                            // Registers at byte offsets 24 and
                                            // 25
#define DDI_O_MASK8B2627        0x000001B4  // Masked access (8m/8d) for DDI
                                            // Registers at byte offsets 26 and
                                            // 27
#define DDI_O_MASK8B2829        0x000001B8  // Masked access (8m/8d) for DDI
                                            // Registers at byte offsets 28 and
                                            // 29
#define DDI_O_MASK8B3031        0x000001BC  // Masked access (8m/8d) for DDI
                                            // Registers at byte offsets 30 and
                                            // 31
#define DDI_O_MASK8B3233        0x000001C0  // Masked access (8m/8d) for DDI
                                            // Registers at byte offsets 32 and
                                            // 33
#define DDI_O_MASK8B3435        0x000001C4  // Masked access (8m/8d) for DDI
                                            // Registers at byte offsets 34 and
                                            // 35
#define DDI_O_MASK8B3637        0x000001C8  // Masked access (8m/8d) for DDI
                                            // Registers at byte offsets 36 and
                                            // 37
#define DDI_O_MASK8B3839        0x000001CC  // Masked access (8m/8d) for DDI
                                            // Registers at byte offsets 38 and
                                            // 39
#define DDI_O_MASK8B4041        0x000001D0  // Masked access (8m/8d) for DDI
                                            // Registers at byte offsets 40 and
                                            // 41
#define DDI_O_MASK8B4243        0x000001D4  // Masked access (8m/8d) for DDI
                                            // Registers at byte offsets 42 and
                                            // 43
#define DDI_O_MASK8B4445        0x000001D8  // Masked access (8m/8d) for DDI
                                            // Registers at byte offsets 44 and
                                            // 45
#define DDI_O_MASK8B4647        0x000001DC  // Masked access (8m/8d) for DDI
                                            // Registers at byte offsets 46 and
                                            // 47
#define DDI_O_MASK8B4849        0x000001E0  // Masked access (8m/8d) for DDI
                                            // Registers at byte offsets 48 and
                                            // 49
#define DDI_O_MASK8B5051        0x000001E4  // Masked access (8m/8d) for DDI
                                            // Registers at byte offsets 50 and
                                            // 51
#define DDI_O_MASK8B5253        0x000001E8  // Masked access (8m/8d) for DDI
                                            // Registers at byte offsets 52 and
                                            // 53
#define DDI_O_MASK8B5455        0x000001EC  // Masked access (8m/8d) for DDI
                                            // Registers at byte offsets 54 and
                                            // 55
#define DDI_O_MASK8B5657        0x000001F0  // Masked access (8m/8d) for DDI
                                            // Registers at byte offsets 56 and
                                            // 57
#define DDI_O_MASK8B5859        0x000001F4  // Masked access (8m/8d) for DDI
                                            // Registers at byte offsets 58 and
                                            // 59
#define DDI_O_MASK8B6061        0x000001F8  // Masked access (8m/8d) for DDI
                                            // Registers at byte offsets 60 and
                                            // 61
#define DDI_O_MASK8B6263        0x000001FC  // Masked access (8m/8d) for DDI
                                            // Registers at byte offsets 62 and
                                            // 63
#define DDI_O_MASK16B01         0x00000200  // Masked access (16m/16d) for DDI
                                            // Registers at byte offsets 0 and
                                            // 1
#define DDI_O_MASK16B23         0x00000204  // Masked access (16m/16d) for DDI
                                            // Registers at byte offsets 2 and
                                            // 3
#define DDI_O_MASK16B45         0x00000208  // Masked access (16m/16d) for DDI
                                            // Registers at byte offsets 4 and
                                            // 5
#define DDI_O_MASK16B67         0x0000020C  // Masked access (16m/16d) for DDI
                                            // Registers at byte offsets 6 and
                                            // 7
#define DDI_O_MASK16B89         0x00000210  // Masked access (16m/16d) for DDI
                                            // Registers at byte offsets 8 and
                                            // 9
#define DDI_O_MASK16B1011       0x00000214  // Masked access (16m/16d) for DDI
                                            // Registers at byte offsets 10 and
                                            // 11
#define DDI_O_MASK16B1213       0x00000218  // Masked access (16m/16d) for DDI
                                            // Registers at byte offsets 12 and
                                            // 13
#define DDI_O_MASK16B1415       0x0000021C  // Masked access (16m/16d) for DDI
                                            // Registers at byte offsets 14 and
                                            // 15
#define DDI_O_MASK16B1617       0x00000220  // Masked access (16m/16d) for DDI
                                            // Registers at byte offsets 16 and
                                            // 17
#define DDI_O_MASK16B1819       0x00000224  // Masked access (16m/16d) for DDI
                                            // Registers at byte offsets 18 and
                                            // 19
#define DDI_O_MASK16B2021       0x00000228  // Masked access (16m/16d) for DDI
                                            // Registers at byte offsets 20 and
                                            // 21
#define DDI_O_MASK16B2223       0x0000022C  // Masked access (16m/16d) for DDI
                                            // Registers at byte offsets 22 and
                                            // 23
#define DDI_O_MASK16B2425       0x00000230  // Masked access (16m/16d) for DDI
                                            // Registers at byte offsets 24 and
                                            // 25
#define DDI_O_MASK16B2627       0x00000234  // Masked access (16m/16d) for DDI
                                            // Registers at byte offsets 26 and
                                            // 27
#define DDI_O_MASK16B2829       0x00000238  // Masked access (16m/16d) for DDI
                                            // Registers at byte offsets 28 and
                                            // 29
#define DDI_O_MASK16B3031       0x0000023C  // Masked access (16m/16d) for DDI
                                            // Registers at byte offsets 30 and
                                            // 31
#define DDI_O_MASK16B3233       0x00000240  // Masked access (16m/16d) for DDI
                                            // Registers at byte offsets 32 and
                                            // 33
#define DDI_O_MASK16B3435       0x00000244  // Masked access (16m/16d) for DDI
                                            // Registers at byte offsets 34 and
                                            // 35
#define DDI_O_MASK16B3637       0x00000248  // Masked access (16m/16d) for DDI
                                            // Registers at byte offsets 36 and
                                            // 37
#define DDI_O_MASK16B3839       0x0000024C  // Masked access (16m/16d) for DDI
                                            // Registers at byte offsets 38 and
                                            // 39
#define DDI_O_MASK16B4041       0x00000250  // Masked access (16m/16d) for DDI
                                            // Registers at byte offsets 40 and
                                            // 41
#define DDI_O_MASK16B4243       0x00000254  // Masked access (16m/16d) for DDI
                                            // Registers at byte offsets 42 and
                                            // 43
#define DDI_O_MASK16B4445       0x00000258  // Masked access (16m/16d) for DDI
                                            // Registers at byte offsets 44 and
                                            // 45
#define DDI_O_MASK16B4647       0x0000025C  // Masked access (16m/16d) for DDI
                                            // Registers at byte offsets 46 and
                                            // 47
#define DDI_O_MASK16B4849       0x00000260  // Masked access (16m/16d) for DDI
                                            // Registers at byte offsets 48 and
                                            // 49
#define DDI_O_MASK16B5051       0x00000264  // Masked access (16m/16d) for DDI
                                            // Registers at byte offsets 50 and
                                            // 51
#define DDI_O_MASK16B5253       0x00000268  // Masked access (16m/16d) for DDI
                                            // Registers at byte offsets 52 and
                                            // 53
#define DDI_O_MASK16B5455       0x0000026C  // Masked access (16m/16d) for DDI
                                            // Registers at byte offsets 54 and
                                            // 55
#define DDI_O_MASK16B5657       0x00000270  // Masked access (16m/16d) for DDI
                                            // Registers at byte offsets 56 and
                                            // 57
#define DDI_O_MASK16B5859       0x00000274  // Masked access (16m/16d) for DDI
                                            // Registers at byte offsets 58 and
                                            // 59
#define DDI_O_MASK16B6061       0x00000278  // Masked access (16m/16d) for DDI
                                            // Registers at byte offsets 60 and
                                            // 61
#define DDI_O_MASK16B6263       0x0000027C  // Masked access (16m/16d) for DDI
                                            // Registers at byte offsets 62 and
                                            // 63


//*****************************************************************************
//
// The following are defines for the bit fields in the DDI_O_DIR03 register.
//
//*****************************************************************************
#define DDI_DIR03_B3_M          0xFF000000  // Direct access to DDI register 3
#define DDI_DIR03_B3_S          24
#define DDI_DIR03_B2_M          0x00FF0000  // Direct access to DDI register 2
#define DDI_DIR03_B2_S          16
#define DDI_DIR03_B1_M          0x0000FF00  // Direct access to DDI register 1
#define DDI_DIR03_B1_S          8
#define DDI_DIR03_B0_M          0x000000FF  // Direct access to DDI register 0
#define DDI_DIR03_B0_S          0
//*****************************************************************************
//
// The following are defines for the bit fields in the DDI_O_DIR47 register.
//
//*****************************************************************************
#define DDI_DIR47_B3_M          0xFF000000  // Direct access to DDI register 7
#define DDI_DIR47_B3_S          24
#define DDI_DIR47_B2_M          0x00FF0000  // Direct access to DDI register 6
#define DDI_DIR47_B2_S          16
#define DDI_DIR47_B1_M          0x0000FF00  // Direct access to DDI register 5
#define DDI_DIR47_B1_S          8
#define DDI_DIR47_B0_M          0x000000FF  // Direct access to DDI register 4
#define DDI_DIR47_B0_S          0
//*****************************************************************************
//
// The following are defines for the bit fields in the DDI_O_DIR811 register.
//
//*****************************************************************************
#define DDI_DIR811_B3_M         0xFF000000  // Direct access to DDI register
                                            // 11
#define DDI_DIR811_B3_S         24
#define DDI_DIR811_B2_M         0x00FF0000  // Direct access to DDI register
                                            // 10
#define DDI_DIR811_B2_S         16
#define DDI_DIR811_B1_M         0x0000FF00  // Direct access to DDI register 9
#define DDI_DIR811_B1_S         8
#define DDI_DIR811_B0_M         0x000000FF  // Direct access to DDI register 8
#define DDI_DIR811_B0_S         0
//*****************************************************************************
//
// The following are defines for the bit fields in the DDI_O_DIR1215 register.
//
//*****************************************************************************
#define DDI_DIR1215_B3_M        0xFF000000  // Direct access to DDI register
                                            // 15
#define DDI_DIR1215_B3_S        24
#define DDI_DIR1215_B2_M        0x00FF0000  // Direct access to DDI register
                                            // 14
#define DDI_DIR1215_B2_S        16
#define DDI_DIR1215_B1_M        0x0000FF00  // Direct access to DDI register
                                            // 13
#define DDI_DIR1215_B1_S        8
#define DDI_DIR1215_B0_M        0x000000FF  // Direct access to DDI register
                                            // 12
#define DDI_DIR1215_B0_S        0
//*****************************************************************************
//
// The following are defines for the bit fields in the DDI_O_DIR1619 register.
//
//*****************************************************************************
#define DDI_DIR1619_B3_M        0xFF000000  // Direct access to DDI register
                                            // 19
#define DDI_DIR1619_B3_S        24
#define DDI_DIR1619_B2_M        0x00FF0000  // Direct access to DDI register
                                            // 18
#define DDI_DIR1619_B2_S        16
#define DDI_DIR1619_B1_M        0x0000FF00  // Direct access to DDI register
                                            // 17
#define DDI_DIR1619_B1_S        8
#define DDI_DIR1619_B0_M        0x000000FF  // Direct access to DDI register
                                            // 16
#define DDI_DIR1619_B0_S        0
//*****************************************************************************
//
// The following are defines for the bit fields in the DDI_O_DIR2023 register.
//
//*****************************************************************************
#define DDI_DIR2023_B3_M        0xFF000000  // Direct access to DDI register
                                            // 23
#define DDI_DIR2023_B3_S        24
#define DDI_DIR2023_B2_M        0x00FF0000  // Direct access to DDI register
                                            // 22
#define DDI_DIR2023_B2_S        16
#define DDI_DIR2023_B1_M        0x0000FF00  // Direct access to DDI register
                                            // 21
#define DDI_DIR2023_B1_S        8
#define DDI_DIR2023_B0_M        0x000000FF  // Direct access to DDI register
                                            // 20
#define DDI_DIR2023_B0_S        0
//*****************************************************************************
//
// The following are defines for the bit fields in the DDI_O_DIR2427 register.
//
//*****************************************************************************
#define DDI_DIR2427_B3_M        0xFF000000  // Direct access to DDI register
                                            // 27
#define DDI_DIR2427_B3_S        24
#define DDI_DIR2427_B2_M        0x00FF0000  // Direct access to DDI register
                                            // 26
#define DDI_DIR2427_B2_S        16
#define DDI_DIR2427_B1_M        0x0000FF00  // Direct access to DDI register
                                            // 25
#define DDI_DIR2427_B1_S        8
#define DDI_DIR2427_B0_M        0x000000FF  // Direct access to DDI register
                                            // 24
#define DDI_DIR2427_B0_S        0
//*****************************************************************************
//
// The following are defines for the bit fields in the DDI_O_DIR2831 register.
//
//*****************************************************************************
#define DDI_DIR2831_B3_M        0xFF000000  // Direct access to DDI register
                                            // 31
#define DDI_DIR2831_B3_S        24
#define DDI_DIR2831_B2_M        0x00FF0000  // Direct access to DDI register
                                            // 30
#define DDI_DIR2831_B2_S        16
#define DDI_DIR2831_B1_M        0x0000FF00  // Direct access to DDI register
                                            // 29
#define DDI_DIR2831_B1_S        8
#define DDI_DIR2831_B0_M        0x000000FF  // Direct access to DDI register
                                            // 28
#define DDI_DIR2831_B0_S        0
//*****************************************************************************
//
// The following are defines for the bit fields in the DDI_O_DIR3235 register.
//
//*****************************************************************************
#define DDI_DIR3235_B3_M        0xFF000000  // Direct access to DDI register
                                            // 35
#define DDI_DIR3235_B3_S        24
#define DDI_DIR3235_B2_M        0x00FF0000  // Direct access to DDI register
                                            // 34
#define DDI_DIR3235_B2_S        16
#define DDI_DIR3235_B1_M        0x0000FF00  // Direct access to DDI register
                                            // 33
#define DDI_DIR3235_B1_S        8
#define DDI_DIR3235_B0_M        0x000000FF  // Direct access to DDI register
                                            // 32
#define DDI_DIR3235_B0_S        0
//*****************************************************************************
//
// The following are defines for the bit fields in the DDI_O_DIR3639 register.
//
//*****************************************************************************
#define DDI_DIR3639_B3_M        0xFF000000  // Direct access to DDI register
                                            // 39
#define DDI_DIR3639_B3_S        24
#define DDI_DIR3639_B2_M        0x00FF0000  // Direct access to DDI register
                                            // 38
#define DDI_DIR3639_B2_S        16
#define DDI_DIR3639_B1_M        0x0000FF00  // Direct access to DDI register
                                            // 37
#define DDI_DIR3639_B1_S        8
#define DDI_DIR3639_B0_M        0x000000FF  // Direct access to DDI register
                                            // 36
#define DDI_DIR3639_B0_S        0
//*****************************************************************************
//
// The following are defines for the bit fields in the DDI_O_DIR4043 register.
//
//*****************************************************************************
#define DDI_DIR4043_B3_M        0xFF000000  // Direct access to DDI register
                                            // 43
#define DDI_DIR4043_B3_S        24
#define DDI_DIR4043_B2_M        0x00FF0000  // Direct access to DDI register
                                            // 42
#define DDI_DIR4043_B2_S        16
#define DDI_DIR4043_B1_M        0x0000FF00  // Direct access to DDI register
                                            // 41
#define DDI_DIR4043_B1_S        8
#define DDI_DIR4043_B0_M        0x000000FF  // Direct access to DDI register
                                            // 40
#define DDI_DIR4043_B0_S        0
//*****************************************************************************
//
// The following are defines for the bit fields in the DDI_O_DIR4447 register.
//
//*****************************************************************************
#define DDI_DIR4447_B3_M        0xFF000000  // Direct access to DDI register
                                            // 47
#define DDI_DIR4447_B3_S        24
#define DDI_DIR4447_B2_M        0x00FF0000  // Direct access to DDI register
                                            // 46
#define DDI_DIR4447_B2_S        16
#define DDI_DIR4447_B1_M        0x0000FF00  // Direct access to DDI register
                                            // 45
#define DDI_DIR4447_B1_S        8
#define DDI_DIR4447_B0_M        0x000000FF  // Direct access to DDI register
                                            // 44
#define DDI_DIR4447_B0_S        0
//*****************************************************************************
//
// The following are defines for the bit fields in the DDI_O_DIR4851 register.
//
//*****************************************************************************
#define DDI_DIR4851_B3_M        0xFF000000  // Direct access to DDI register
                                            // 51
#define DDI_DIR4851_B3_S        24
#define DDI_DIR4851_B2_M        0x00FF0000  // Direct access to DDI register
                                            // 50
#define DDI_DIR4851_B2_S        16
#define DDI_DIR4851_B1_M        0x0000FF00  // Direct access to DDI register
                                            // 49
#define DDI_DIR4851_B1_S        8
#define DDI_DIR4851_B0_M        0x000000FF  // Direct access to DDI register
                                            // 48
#define DDI_DIR4851_B0_S        0
//*****************************************************************************
//
// The following are defines for the bit fields in the DDI_O_DIR5255 register.
//
//*****************************************************************************
#define DDI_DIR5255_B3_M        0xFF000000  // Direct access to DDI register
                                            // 55
#define DDI_DIR5255_B3_S        24
#define DDI_DIR5255_B2_M        0x00FF0000  // Direct access to DDI register
                                            // 54
#define DDI_DIR5255_B2_S        16
#define DDI_DIR5255_B1_M        0x0000FF00  // Direct access to DDI register
                                            // 53
#define DDI_DIR5255_B1_S        8
#define DDI_DIR5255_B0_M        0x000000FF  // Direct access to DDI register
                                            // 52
#define DDI_DIR5255_B0_S        0
//*****************************************************************************
//
// The following are defines for the bit fields in the DDI_O_DIR5659 register.
//
//*****************************************************************************
#define DDI_DIR5659_B3_M        0xFF000000  // Direct access to DDI register
                                            // 59
#define DDI_DIR5659_B3_S        24
#define DDI_DIR5659_B2_M        0x00FF0000  // Direct access to DDI register
                                            // 58
#define DDI_DIR5659_B2_S        16
#define DDI_DIR5659_B1_M        0x0000FF00  // Direct access to DDI register
                                            // 57
#define DDI_DIR5659_B1_S        8
#define DDI_DIR5659_B0_M        0x000000FF  // Direct access to DDI register
                                            // 56
#define DDI_DIR5659_B0_S        0
//*****************************************************************************
//
// The following are defines for the bit fields in the DDI_O_DIR6063 register.
//
//*****************************************************************************
#define DDI_DIR6063_B3_M        0xFF000000  // Direct access to DDI register
                                            // 63
#define DDI_DIR6063_B3_S        24
#define DDI_DIR6063_B2_M        0x00FF0000  // Direct access to DDI register
                                            // 62
#define DDI_DIR6063_B2_S        16
#define DDI_DIR6063_B1_M        0x0000FF00  // Direct access to DDI register
                                            // 61
#define DDI_DIR6063_B1_S        8
#define DDI_DIR6063_B0_M        0x000000FF  // Direct access to DDI register
                                            // 60
#define DDI_DIR6063_B0_S        0
//*****************************************************************************
//
// The following are defines for the bit fields in the DDI_O_SET03 register.
//
//*****************************************************************************
#define DDI_SET03_S3_M          0xFF000000  // A high bit value will set the
                                            // corresponding bit in DDI
                                            // register 3. Read returns 0.
#define DDI_SET03_S3_S          24
#define DDI_SET03_S2_M          0x00FF0000  // A high bit value will set the
                                            // corresponding bit in DDI
                                            // register 2. Read returns 0.
#define DDI_SET03_S2_S          16
#define DDI_SET03_S1_M          0x0000FF00  // A high bit value will set the
                                            // corresponding bit in DDI
                                            // register 1. Read returns 0.
#define DDI_SET03_S1_S          8
#define DDI_SET03_S0_M          0x000000FF  // A high bit value will set the
                                            // corresponding bit in DDI
                                            // register 0. Read returns 0.
#define DDI_SET03_S0_S          0
//*****************************************************************************
//
// The following are defines for the bit fields in the DDI_O_SET47 register.
//
//*****************************************************************************
#define DDI_SET47_S3_M          0xFF000000  // A high bit value will set the
                                            // corresponding bit in DDI
                                            // register 7. Read returns 0.
#define DDI_SET47_S3_S          24
#define DDI_SET47_S2_M          0x00FF0000  // A high bit value will set the
                                            // corresponding bit in DDI
                                            // register 6. Read returns 0.
#define DDI_SET47_S2_S          16
#define DDI_SET47_S1_M          0x0000FF00  // A high bit value will set the
                                            // corresponding bit in DDI
                                            // register 5. Read returns 0.
#define DDI_SET47_S1_S          8
#define DDI_SET47_S0_M          0x000000FF  // A high bit value will set the
                                            // corresponding bit in DDI
                                            // register 4. Read returns 0.
#define DDI_SET47_S0_S          0
//*****************************************************************************
//
// The following are defines for the bit fields in the DDI_O_SET811 register.
//
//*****************************************************************************
#define DDI_SET811_S3_M         0xFF000000  // A high bit value will set the
                                            // corresponding bit in DDI
                                            // register 11. Read returns 0.
#define DDI_SET811_S3_S         24
#define DDI_SET811_S2_M         0x00FF0000  // A high bit value will set the
                                            // corresponding bit in DDI
                                            // register 10. Read returns 0.
#define DDI_SET811_S2_S         16
#define DDI_SET811_S1_M         0x0000FF00  // A high bit value will set the
                                            // corresponding bit in DDI
                                            // register 9. Read returns 0.
#define DDI_SET811_S1_S         8
#define DDI_SET811_S0_M         0x000000FF  // A high bit value will set the
                                            // corresponding bit in DDI
                                            // register 8. Read returns 0.
#define DDI_SET811_S0_S         0
//*****************************************************************************
//
// The following are defines for the bit fields in the DDI_O_SET1215 register.
//
//*****************************************************************************
#define DDI_SET1215_S3_M        0xFF000000  // A high bit value will set the
                                            // corresponding bit in DDI
                                            // register 15. Read returns 0.
#define DDI_SET1215_S3_S        24
#define DDI_SET1215_S2_M        0x00FF0000  // A high bit value will set the
                                            // corresponding bit in DDI
                                            // register 14. Read returns 0.
#define DDI_SET1215_S2_S        16
#define DDI_SET1215_S1_M        0x0000FF00  // A high bit value will set the
                                            // corresponding bit in DDI
                                            // register 13. Read returns 0.
#define DDI_SET1215_S1_S        8
#define DDI_SET1215_S0_M        0x000000FF  // A high bit value will set the
                                            // corresponding bit in DDI
                                            // register 12. Read returns 0.
#define DDI_SET1215_S0_S        0
//*****************************************************************************
//
// The following are defines for the bit fields in the DDI_O_SET1619 register.
//
//*****************************************************************************
#define DDI_SET1619_S3_M        0xFF000000  // A high bit value will set the
                                            // corresponding bit in DDI
                                            // register 19. Read returns 0.
#define DDI_SET1619_S3_S        24
#define DDI_SET1619_S2_M        0x00FF0000  // A high bit value will set the
                                            // corresponding bit in DDI
                                            // register 18. Read returns 0.
#define DDI_SET1619_S2_S        16
#define DDI_SET1619_S1_M        0x0000FF00  // A high bit value will set the
                                            // corresponding bit in DDI
                                            // register 17. Read returns 0.
#define DDI_SET1619_S1_S        8
#define DDI_SET1619_S0_M        0x000000FF  // A high bit value will set the
                                            // corresponding bit in DDI
                                            // register 16. Read returns 0.
#define DDI_SET1619_S0_S        0
//*****************************************************************************
//
// The following are defines for the bit fields in the DDI_O_SET2023 register.
//
//*****************************************************************************
#define DDI_SET2023_S3_M        0xFF000000  // A high bit value will set the
                                            // corresponding bit in DDI
                                            // register 23. Read returns 0.
#define DDI_SET2023_S3_S        24
#define DDI_SET2023_S2_M        0x00FF0000  // A high bit value will set the
                                            // corresponding bit in DDI
                                            // register 22. Read returns 0.
#define DDI_SET2023_S2_S        16
#define DDI_SET2023_S1_M        0x0000FF00  // A high bit value will set the
                                            // corresponding bit in DDI
                                            // register 21. Read returns 0.
#define DDI_SET2023_S1_S        8
#define DDI_SET2023_S0_M        0x000000FF  // A high bit value will set the
                                            // corresponding bit in DDI
                                            // register 20. Read returns 0.
#define DDI_SET2023_S0_S        0
//*****************************************************************************
//
// The following are defines for the bit fields in the DDI_O_SET2427 register.
//
//*****************************************************************************
#define DDI_SET2427_S3_M        0xFF000000  // A high bit value will set the
                                            // corresponding bit in DDI
                                            // register 27. Read returns 0.
#define DDI_SET2427_S3_S        24
#define DDI_SET2427_S2_M        0x00FF0000  // A high bit value will set the
                                            // corresponding bit in DDI
                                            // register 26. Read returns 0.
#define DDI_SET2427_S2_S        16
#define DDI_SET2427_S1_M        0x0000FF00  // A high bit value will set the
                                            // corresponding bit in DDI
                                            // register 25. Read returns 0.
#define DDI_SET2427_S1_S        8
#define DDI_SET2427_S0_M        0x000000FF  // A high bit value will set the
                                            // corresponding bit in DDI
                                            // register 24. Read returns 0.
#define DDI_SET2427_S0_S        0
//*****************************************************************************
//
// The following are defines for the bit fields in the DDI_O_SET2831 register.
//
//*****************************************************************************
#define DDI_SET2831_S3_M        0xFF000000  // A high bit value will set the
                                            // corresponding bit in DDI
                                            // register 31. Read returns 0.
#define DDI_SET2831_S3_S        24
#define DDI_SET2831_S2_M        0x00FF0000  // A high bit value will set the
                                            // corresponding bit in DDI
                                            // register 30. Read returns 0.
#define DDI_SET2831_S2_S        16
#define DDI_SET2831_S1_M        0x0000FF00  // A high bit value will set the
                                            // corresponding bit in DDI
                                            // register 29. Read returns 0.
#define DDI_SET2831_S1_S        8
#define DDI_SET2831_S0_M        0x000000FF  // A high bit value will set the
                                            // corresponding bit in DDI
                                            // register 28. Read returns 0.
#define DDI_SET2831_S0_S        0
//*****************************************************************************
//
// The following are defines for the bit fields in the DDI_O_SET3235 register.
//
//*****************************************************************************
#define DDI_SET3235_S3_M        0xFF000000  // A high bit value will set the
                                            // corresponding bit in DDI
                                            // register 35. Read returns 0.
#define DDI_SET3235_S3_S        24
#define DDI_SET3235_S2_M        0x00FF0000  // A high bit value will set the
                                            // corresponding bit in DDI
                                            // register 34. Read returns 0.
#define DDI_SET3235_S2_S        16
#define DDI_SET3235_S1_M        0x0000FF00  // A high bit value will set the
                                            // corresponding bit in DDI
                                            // register 33. Read returns 0.
#define DDI_SET3235_S1_S        8
#define DDI_SET3235_S0_M        0x000000FF  // A high bit value will set the
                                            // corresponding bit in DDI
                                            // register 32. Read returns 0.
#define DDI_SET3235_S0_S        0
//*****************************************************************************
//
// The following are defines for the bit fields in the DDI_O_SET3639 register.
//
//*****************************************************************************
#define DDI_SET3639_S3_M        0xFF000000  // A high bit value will set the
                                            // corresponding bit in DDI
                                            // register 39. Read returns 0.
#define DDI_SET3639_S3_S        24
#define DDI_SET3639_S2_M        0x00FF0000  // A high bit value will set the
                                            // corresponding bit in DDI
                                            // register 38. Read returns 0.
#define DDI_SET3639_S2_S        16
#define DDI_SET3639_S1_M        0x0000FF00  // A high bit value will set the
                                            // corresponding bit in DDI
                                            // register 37. Read returns 0.
#define DDI_SET3639_S1_S        8
#define DDI_SET3639_S0_M        0x000000FF  // A high bit value will set the
                                            // corresponding bit in DDI
                                            // register 36. Read returns 0.
#define DDI_SET3639_S0_S        0
//*****************************************************************************
//
// The following are defines for the bit fields in the DDI_O_SET4043 register.
//
//*****************************************************************************
#define DDI_SET4043_S3_M        0xFF000000  // A high bit value will set the
                                            // corresponding bit in DDI
                                            // register 43. Read returns 0.
#define DDI_SET4043_S3_S        24
#define DDI_SET4043_S2_M        0x00FF0000  // A high bit value will set the
                                            // corresponding bit in DDI
                                            // register 42. Read returns 0.
#define DDI_SET4043_S2_S        16
#define DDI_SET4043_S1_M        0x0000FF00  // A high bit value will set the
                                            // corresponding bit in DDI
                                            // register 41. Read returns 0.
#define DDI_SET4043_S1_S        8
#define DDI_SET4043_S0_M        0x000000FF  // A high bit value will set the
                                            // corresponding bit in DDI
                                            // register 40. Read returns 0.
#define DDI_SET4043_S0_S        0
//*****************************************************************************
//
// The following are defines for the bit fields in the DDI_O_SET4447 register.
//
//*****************************************************************************
#define DDI_SET4447_S3_M        0xFF000000  // A high bit value will set the
                                            // corresponding bit in DDI
                                            // register 47. Read returns 0.
#define DDI_SET4447_S3_S        24
#define DDI_SET4447_S2_M        0x00FF0000  // A high bit value will set the
                                            // corresponding bit in DDI
                                            // register 46. Read returns 0.
#define DDI_SET4447_S2_S        16
#define DDI_SET4447_S1_M        0x0000FF00  // A high bit value will set the
                                            // corresponding bit in DDI
                                            // register 45. Read returns 0.
#define DDI_SET4447_S1_S        8
#define DDI_SET4447_S0_M        0x000000FF  // A high bit value will set the
                                            // corresponding bit in DDI
                                            // register 44. Read returns 0.
#define DDI_SET4447_S0_S        0
//*****************************************************************************
//
// The following are defines for the bit fields in the DDI_O_SET4851 register.
//
//*****************************************************************************
#define DDI_SET4851_S3_M        0xFF000000  // A high bit value will set the
                                            // corresponding bit in DDI
                                            // register 51. Read returns 0.
#define DDI_SET4851_S3_S        24
#define DDI_SET4851_S2_M        0x00FF0000  // A high bit value will set the
                                            // corresponding bit in DDI
                                            // register 50. Read returns 0.
#define DDI_SET4851_S2_S        16
#define DDI_SET4851_S1_M        0x0000FF00  // A high bit value will set the
                                            // corresponding bit in DDI
                                            // register 49. Read returns 0.
#define DDI_SET4851_S1_S        8
#define DDI_SET4851_S0_M        0x000000FF  // A high bit value will set the
                                            // corresponding bit in DDI
                                            // register 48. Read returns 0.
#define DDI_SET4851_S0_S        0
//*****************************************************************************
//
// The following are defines for the bit fields in the DDI_O_SET5255 register.
//
//*****************************************************************************
#define DDI_SET5255_S3_M        0xFF000000  // A high bit value will set the
                                            // corresponding bit in DDI
                                            // register 55. Read returns 0.
#define DDI_SET5255_S3_S        24
#define DDI_SET5255_S2_M        0x00FF0000  // A high bit value will set the
                                            // corresponding bit in DDI
                                            // register 54. Read returns 0.
#define DDI_SET5255_S2_S        16
#define DDI_SET5255_S1_M        0x0000FF00  // A high bit value will set the
                                            // corresponding bit in DDI
                                            // register 53. Read returns 0.
#define DDI_SET5255_S1_S        8
#define DDI_SET5255_S0_M        0x000000FF  // A high bit value will set the
                                            // corresponding bit in DDI
                                            // register 52. Read returns 0.
#define DDI_SET5255_S0_S        0
//*****************************************************************************
//
// The following are defines for the bit fields in the DDI_O_SET5659 register.
//
//*****************************************************************************
#define DDI_SET5659_S3_M        0xFF000000  // A high bit value will set the
                                            // corresponding bit in DDI
                                            // register 59. Read returns 0.
#define DDI_SET5659_S3_S        24
#define DDI_SET5659_S2_M        0x00FF0000  // A high bit value will set the
                                            // corresponding bit in DDI
                                            // register 58. Read returns 0.
#define DDI_SET5659_S2_S        16
#define DDI_SET5659_S1_M        0x0000FF00  // A high bit value will set the
                                            // corresponding bit in DDI
                                            // register 57. Read returns 0.
#define DDI_SET5659_S1_S        8
#define DDI_SET5659_S0_M        0x000000FF  // A high bit value will set the
                                            // corresponding bit in DDI
                                            // register 56. Read returns 0.
#define DDI_SET5659_S0_S        0
//*****************************************************************************
//
// The following are defines for the bit fields in the DDI_O_SET6063 register.
//
//*****************************************************************************
#define DDI_SET6063_S3_M        0xFF000000  // A high bit value will set the
                                            // corresponding bit in DDI
                                            // register 63. Read returns 0.
#define DDI_SET6063_S3_S        24
#define DDI_SET6063_S2_M        0x00FF0000  // A high bit value will set the
                                            // corresponding bit in DDI
                                            // register 62. Read returns 0.
#define DDI_SET6063_S2_S        16
#define DDI_SET6063_S1_M        0x0000FF00  // A high bit value will set the
                                            // corresponding bit in DDI
                                            // register 61. Read returns 0.
#define DDI_SET6063_S1_S        8
#define DDI_SET6063_S0_M        0x000000FF  // A high bit value will set the
                                            // corresponding bit in DDI
                                            // register 60. Read returns 0.
#define DDI_SET6063_S0_S        0
//*****************************************************************************
//
// The following are defines for the bit fields in the DDI_O_CLR03 register.
//
//*****************************************************************************
#define DDI_CLR03_S3_M          0xFF000000  // A high bit value will clear the
                                            // corresponding bit in DDI
                                            // register 3
#define DDI_CLR03_S3_S          24
#define DDI_CLR03_S2_M          0x00FF0000  // A high bit value will clear the
                                            // corresponding bit in DDI
                                            // register 2
#define DDI_CLR03_S2_S          16
#define DDI_CLR03_S1_M          0x0000FF00  // A high bit value will clear the
                                            // corresponding bit in DDI
                                            // register 1
#define DDI_CLR03_S1_S          8
#define DDI_CLR03_S0_M          0x000000FF  // A high bit value will clear the
                                            // corresponding bit in DDI
                                            // register 0
#define DDI_CLR03_S0_S          0
//*****************************************************************************
//
// The following are defines for the bit fields in the DDI_O_CLR47 register.
//
//*****************************************************************************
#define DDI_CLR47_S3_M          0xFF000000  // A high bit value will clear the
                                            // corresponding bit in DDI
                                            // register 7
#define DDI_CLR47_S3_S          24
#define DDI_CLR47_S2_M          0x00FF0000  // A high bit value will clear the
                                            // corresponding bit in DDI
                                            // register 6
#define DDI_CLR47_S2_S          16
#define DDI_CLR47_S1_M          0x0000FF00  // A high bit value will clear the
                                            // corresponding bit in DDI
                                            // register 5
#define DDI_CLR47_S1_S          8
#define DDI_CLR47_S0_M          0x000000FF  // A high bit value will clear the
                                            // corresponding bit in DDI
                                            // register 4
#define DDI_CLR47_S0_S          0
//*****************************************************************************
//
// The following are defines for the bit fields in the DDI_O_CLR811 register.
//
//*****************************************************************************
#define DDI_CLR811_S3_M         0xFF000000  // A high bit value will clear the
                                            // corresponding bit in DDI
                                            // register 11
#define DDI_CLR811_S3_S         24
#define DDI_CLR811_S2_M         0x00FF0000  // A high bit value will clear the
                                            // corresponding bit in DDI
                                            // register 10
#define DDI_CLR811_S2_S         16
#define DDI_CLR811_S1_M         0x0000FF00  // A high bit value will clear the
                                            // corresponding bit in DDI
                                            // register 9
#define DDI_CLR811_S1_S         8
#define DDI_CLR811_S0_M         0x000000FF  // A high bit value will clear the
                                            // corresponding bit in DDI
                                            // register 8
#define DDI_CLR811_S0_S         0
//*****************************************************************************
//
// The following are defines for the bit fields in the DDI_O_CLR1215 register.
//
//*****************************************************************************
#define DDI_CLR1215_S3_M        0xFF000000  // A high bit value will clear the
                                            // corresponding bit in DDI
                                            // register 15
#define DDI_CLR1215_S3_S        24
#define DDI_CLR1215_S2_M        0x00FF0000  // A high bit value will clear the
                                            // corresponding bit in DDI
                                            // register 14
#define DDI_CLR1215_S2_S        16
#define DDI_CLR1215_S1_M        0x0000FF00  // A high bit value will clear the
                                            // corresponding bit in DDI
                                            // register 13
#define DDI_CLR1215_S1_S        8
#define DDI_CLR1215_S0_M        0x000000FF  // A high bit value will clear the
                                            // corresponding bit in DDI
                                            // register 12
#define DDI_CLR1215_S0_S        0
//*****************************************************************************
//
// The following are defines for the bit fields in the DDI_O_CLR1619 register.
//
//*****************************************************************************
#define DDI_CLR1619_S3_M        0xFF000000  // A high bit value will clear the
                                            // corresponding bit in DDI
                                            // register 19
#define DDI_CLR1619_S3_S        24
#define DDI_CLR1619_S2_M        0x00FF0000  // A high bit value will clear the
                                            // corresponding bit in DDI
                                            // register 18
#define DDI_CLR1619_S2_S        16
#define DDI_CLR1619_S1_M        0x0000FF00  // A high bit value will clear the
                                            // corresponding bit in DDI
                                            // register 17
#define DDI_CLR1619_S1_S        8
#define DDI_CLR1619_S0_M        0x000000FF  // A high bit value will clear the
                                            // corresponding bit in DDI
                                            // register 16
#define DDI_CLR1619_S0_S        0
//*****************************************************************************
//
// The following are defines for the bit fields in the DDI_O_CLR2023 register.
//
//*****************************************************************************
#define DDI_CLR2023_S3_M        0xFF000000  // A high bit value will clear the
                                            // corresponding bit in DDI
                                            // register 23
#define DDI_CLR2023_S3_S        24
#define DDI_CLR2023_S2_M        0x00FF0000  // A high bit value will clear the
                                            // corresponding bit in DDI
                                            // register 22
#define DDI_CLR2023_S2_S        16
#define DDI_CLR2023_S1_M        0x0000FF00  // A high bit value will clear the
                                            // corresponding bit in DDI
                                            // register 21
#define DDI_CLR2023_S1_S        8
#define DDI_CLR2023_S0_M        0x000000FF  // A high bit value will clear the
                                            // corresponding bit in DDI
                                            // register 20
#define DDI_CLR2023_S0_S        0
//*****************************************************************************
//
// The following are defines for the bit fields in the DDI_O_CLR2427 register.
//
//*****************************************************************************
#define DDI_CLR2427_S3_M        0xFF000000  // A high bit value will clear the
                                            // corresponding bit in DDI
                                            // register 27
#define DDI_CLR2427_S3_S        24
#define DDI_CLR2427_S2_M        0x00FF0000  // A high bit value will clear the
                                            // corresponding bit in DDI
                                            // register 26
#define DDI_CLR2427_S2_S        16
#define DDI_CLR2427_S1_M        0x0000FF00  // A high bit value will clear the
                                            // corresponding bit in DDI
                                            // register 25
#define DDI_CLR2427_S1_S        8
#define DDI_CLR2427_S0_M        0x000000FF  // A high bit value will clear the
                                            // corresponding bit in DDI
                                            // register 24
#define DDI_CLR2427_S0_S        0
//*****************************************************************************
//
// The following are defines for the bit fields in the DDI_O_CLR2831 register.
//
//*****************************************************************************
#define DDI_CLR2831_S3_M        0xFF000000  // A high bit value will clear the
                                            // corresponding bit in DDI
                                            // register 31
#define DDI_CLR2831_S3_S        24
#define DDI_CLR2831_S2_M        0x00FF0000  // A high bit value will clear the
                                            // corresponding bit in DDI
                                            // register 30
#define DDI_CLR2831_S2_S        16
#define DDI_CLR2831_S1_M        0x0000FF00  // A high bit value will clear the
                                            // corresponding bit in DDI
                                            // register 29
#define DDI_CLR2831_S1_S        8
#define DDI_CLR2831_S0_M        0x000000FF  // A high bit value will clear the
                                            // corresponding bit in DDI
                                            // register 28
#define DDI_CLR2831_S0_S        0
//*****************************************************************************
//
// The following are defines for the bit fields in the DDI_O_CLR3235 register.
//
//*****************************************************************************
#define DDI_CLR3235_S3_M        0xFF000000  // A high bit value will clear the
                                            // corresponding bit in DDI
                                            // register 35
#define DDI_CLR3235_S3_S        24
#define DDI_CLR3235_S2_M        0x00FF0000  // A high bit value will clear the
                                            // corresponding bit in DDI
                                            // register 34
#define DDI_CLR3235_S2_S        16
#define DDI_CLR3235_S1_M        0x0000FF00  // A high bit value will clear the
                                            // corresponding bit in DDI
                                            // register 33
#define DDI_CLR3235_S1_S        8
#define DDI_CLR3235_S0_M        0x000000FF  // A high bit value will clear the
                                            // corresponding bit in DDI
                                            // register 32
#define DDI_CLR3235_S0_S        0
//*****************************************************************************
//
// The following are defines for the bit fields in the DDI_O_CLR3639 register.
//
//*****************************************************************************
#define DDI_CLR3639_S3_M        0xFF000000  // A high bit value will clear the
                                            // corresponding bit in DDI
                                            // register 39
#define DDI_CLR3639_S3_S        24
#define DDI_CLR3639_S2_M        0x00FF0000  // A high bit value will clear the
                                            // corresponding bit in DDI
                                            // register 38
#define DDI_CLR3639_S2_S        16
#define DDI_CLR3639_S1_M        0x0000FF00  // A high bit value will clear the
                                            // corresponding bit in DDI
                                            // register 37
#define DDI_CLR3639_S1_S        8
#define DDI_CLR3639_S0_M        0x000000FF  // A high bit value will clear the
                                            // corresponding bit in DDI
                                            // register 36
#define DDI_CLR3639_S0_S        0
//*****************************************************************************
//
// The following are defines for the bit fields in the DDI_O_CLR4043 register.
//
//*****************************************************************************
#define DDI_CLR4043_S3_M        0xFF000000  // A high bit value will clear the
                                            // corresponding bit in DDI
                                            // register 43
#define DDI_CLR4043_S3_S        24
#define DDI_CLR4043_S2_M        0x00FF0000  // A high bit value will clear the
                                            // corresponding bit in DDI
                                            // register 42
#define DDI_CLR4043_S2_S        16
#define DDI_CLR4043_S1_M        0x0000FF00  // A high bit value will clear the
                                            // corresponding bit in DDI
                                            // register 41
#define DDI_CLR4043_S1_S        8
#define DDI_CLR4043_S0_M        0x000000FF  // A high bit value will clear the
                                            // corresponding bit in DDI
                                            // register 40
#define DDI_CLR4043_S0_S        0
//*****************************************************************************
//
// The following are defines for the bit fields in the DDI_O_CLR4447 register.
//
//*****************************************************************************
#define DDI_CLR4447_S3_M        0xFF000000  // A high bit value will clear the
                                            // corresponding bit in DDI
                                            // register 47
#define DDI_CLR4447_S3_S        24
#define DDI_CLR4447_S2_M        0x00FF0000  // A high bit value will clear the
                                            // corresponding bit in DDI
                                            // register 46
#define DDI_CLR4447_S2_S        16
#define DDI_CLR4447_S1_M        0x0000FF00  // A high bit value will clear the
                                            // corresponding bit in DDI
                                            // register 45
#define DDI_CLR4447_S1_S        8
#define DDI_CLR4447_S0_M        0x000000FF  // A high bit value will clear the
                                            // corresponding bit in DDI
                                            // register 44
#define DDI_CLR4447_S0_S        0
//*****************************************************************************
//
// The following are defines for the bit fields in the DDI_O_CLR4851 register.
//
//*****************************************************************************
#define DDI_CLR4851_S3_M        0xFF000000  // A high bit value will clear the
                                            // corresponding bit in DDI
                                            // register 51
#define DDI_CLR4851_S3_S        24
#define DDI_CLR4851_S2_M        0x00FF0000  // A high bit value will clear the
                                            // corresponding bit in DDI
                                            // register 50
#define DDI_CLR4851_S2_S        16
#define DDI_CLR4851_S1_M        0x0000FF00  // A high bit value will clear the
                                            // corresponding bit in DDI
                                            // register 49
#define DDI_CLR4851_S1_S        8
#define DDI_CLR4851_S0_M        0x000000FF  // A high bit value will clear the
                                            // corresponding bit in DDI
                                            // register 48
#define DDI_CLR4851_S0_S        0
//*****************************************************************************
//
// The following are defines for the bit fields in the DDI_O_CLR5255 register.
//
//*****************************************************************************
#define DDI_CLR5255_S3_M        0xFF000000  // A high bit value will clear the
                                            // corresponding bit in DDI
                                            // register 55
#define DDI_CLR5255_S3_S        24
#define DDI_CLR5255_S2_M        0x00FF0000  // A high bit value will clear the
                                            // corresponding bit in DDI
                                            // register 54
#define DDI_CLR5255_S2_S        16
#define DDI_CLR5255_S1_M        0x0000FF00  // A high bit value will clear the
                                            // corresponding bit in DDI
                                            // register 53
#define DDI_CLR5255_S1_S        8
#define DDI_CLR5255_S0_M        0x000000FF  // A high bit value will clear the
                                            // corresponding bit in DDI
                                            // register 52
#define DDI_CLR5255_S0_S        0
//*****************************************************************************
//
// The following are defines for the bit fields in the DDI_O_CLR5659 register.
//
//*****************************************************************************
#define DDI_CLR5659_S3_M        0xFF000000  // A high bit value will clear the
                                            // corresponding bit in DDI
                                            // register 59
#define DDI_CLR5659_S3_S        24
#define DDI_CLR5659_S2_M        0x00FF0000  // A high bit value will clear the
                                            // corresponding bit in DDI
                                            // register 58
#define DDI_CLR5659_S2_S        16
#define DDI_CLR5659_S1_M        0x0000FF00  // A high bit value will clear the
                                            // corresponding bit in DDI
                                            // register 57
#define DDI_CLR5659_S1_S        8
#define DDI_CLR5659_S0_M        0x000000FF  // A high bit value will clear the
                                            // corresponding bit in DDI
                                            // register 56
#define DDI_CLR5659_S0_S        0
//*****************************************************************************
//
// The following are defines for the bit fields in the DDI_O_CLR6063 register.
//
//*****************************************************************************
#define DDI_CLR6063_S3_M        0xFF000000  // A high bit value will clear the
                                            // corresponding bit in DDI
                                            // register 63
#define DDI_CLR6063_S3_S        24
#define DDI_CLR6063_S2_M        0x00FF0000  // A high bit value will clear the
                                            // corresponding bit in DDI
                                            // register 62
#define DDI_CLR6063_S2_S        16
#define DDI_CLR6063_S1_M        0x0000FF00  // A high bit value will clear the
                                            // corresponding bit in DDI
                                            // register 61
#define DDI_CLR6063_S1_S        8
#define DDI_CLR6063_S0_M        0x000000FF  // A high bit value will clear the
                                            // corresponding bit in DDI
                                            // register 60
#define DDI_CLR6063_S0_S        0
//*****************************************************************************
//
// The following are defines for the bit fields in the DDI_O_MASK4B01 register.
//
//*****************************************************************************
#define DDI_MASK4B01_M1H_M      0xF0000000  // Mask for bits [7:4] in DDI
                                            // register 1
#define DDI_MASK4B01_M1H_S      28
#define DDI_MASK4B01_D1H_M      0x0F000000  // Data for bits [7:4] in DDI
                                            // register 1, - only bits selected
                                            // by mask M1H will be affected by
                                            // access
#define DDI_MASK4B01_D1H_S      24
#define DDI_MASK4B01_M1L_M      0x00F00000  // Mask for bits [3:0] in DDI
                                            // register 1
#define DDI_MASK4B01_M1L_S      20
#define DDI_MASK4B01_D1L_M      0x000F0000  // Data for bits [3:0] in DDI
                                            // register 1, - only bits selected
                                            // by mask M1L will be affected by
                                            // access
#define DDI_MASK4B01_D1L_S      16
#define DDI_MASK4B01_M0H_M      0x0000F000  // Mask for bits [7:4] in DDI
                                            // register 0
#define DDI_MASK4B01_M0H_S      12
#define DDI_MASK4B01_D0H_M      0x00000F00  // Data for bits [7:4] in DDI
                                            // register 0, - only bits selected
                                            // by mask M0H will be affected by
                                            // access
#define DDI_MASK4B01_D0H_S      8
#define DDI_MASK4B01_M0L_M      0x000000F0  // Mask for bits [3:0] in DDI
                                            // register 0
#define DDI_MASK4B01_M0L_S      4
#define DDI_MASK4B01_D0L_M      0x0000000F  // Data for bits [3:0] in DDI
                                            // register 0, - only bits selected
                                            // by mask M0L will be affected by
                                            // access
#define DDI_MASK4B01_D0L_S      0
//*****************************************************************************
//
// The following are defines for the bit fields in the DDI_O_MASK4B23 register.
//
//*****************************************************************************
#define DDI_MASK4B23_M1H_M      0xF0000000  // Mask for bits [7:4] in DDI
                                            // register 3
#define DDI_MASK4B23_M1H_S      28
#define DDI_MASK4B23_D1H_M      0x0F000000  // Data for bits [7:4] in DDI
                                            // register 3, - only bits selected
                                            // by mask M1H will be affected by
                                            // access
#define DDI_MASK4B23_D1H_S      24
#define DDI_MASK4B23_M1L_M      0x00F00000  // Mask for bits [3:0] in DDI
                                            // register 3
#define DDI_MASK4B23_M1L_S      20
#define DDI_MASK4B23_D1L_M      0x000F0000  // Data for bits [3:0] in DDI
                                            // register 3, - only bits selected
                                            // by mask M1L will be affected by
                                            // access
#define DDI_MASK4B23_D1L_S      16
#define DDI_MASK4B23_M0H_M      0x0000F000  // Mask for bits [7:4] in DDI
                                            // register 2
#define DDI_MASK4B23_M0H_S      12
#define DDI_MASK4B23_D0H_M      0x00000F00  // Data for bits [7:4] in DDI
                                            // register 2, - only bits selected
                                            // by mask M0H will be affected by
                                            // access
#define DDI_MASK4B23_D0H_S      8
#define DDI_MASK4B23_M0L_M      0x000000F0  // Mask for bits [3:0] in DDI
                                            // register 2
#define DDI_MASK4B23_M0L_S      4
#define DDI_MASK4B23_D0L_M      0x0000000F  // Data for bits [3:0] in DDI
                                            // register 2, - only bits selected
                                            // by mask M0L will be affected by
                                            // access
#define DDI_MASK4B23_D0L_S      0
//*****************************************************************************
//
// The following are defines for the bit fields in the DDI_O_MASK4B45 register.
//
//*****************************************************************************
#define DDI_MASK4B45_M1H_M      0xF0000000  // Mask for bits [7:4] in DDI
                                            // register 5
#define DDI_MASK4B45_M1H_S      28
#define DDI_MASK4B45_D1H_M      0x0F000000  // Data for bits [7:4] in DDI
                                            // register 5, - only bits selected
                                            // by mask M1H will be affected by
                                            // access
#define DDI_MASK4B45_D1H_S      24
#define DDI_MASK4B45_M1L_M      0x00F00000  // Mask for bits [3:0] in DDI
                                            // register 5
#define DDI_MASK4B45_M1L_S      20
#define DDI_MASK4B45_D1L_M      0x000F0000  // Data for bits [3:0] in DDI
                                            // register 5, - only bits selected
                                            // by mask M1L will be affected by
                                            // access
#define DDI_MASK4B45_D1L_S      16
#define DDI_MASK4B45_M0H_M      0x0000F000  // Mask for bits [7:4] in DDI
                                            // register 4
#define DDI_MASK4B45_M0H_S      12
#define DDI_MASK4B45_D0H_M      0x00000F00  // Data for bits [7:4] in DDI
                                            // register 4, - only bits selected
                                            // by mask M0H will be affected by
                                            // access
#define DDI_MASK4B45_D0H_S      8
#define DDI_MASK4B45_M0L_M      0x000000F0  // Mask for bits [3:0] in DDI
                                            // register 4
#define DDI_MASK4B45_M0L_S      4
#define DDI_MASK4B45_D0L_M      0x0000000F  // Data for bits [3:0] in DDI
                                            // register 4, - only bits selected
                                            // by mask M0L will be affected by
                                            // access
#define DDI_MASK4B45_D0L_S      0
//*****************************************************************************
//
// The following are defines for the bit fields in the DDI_O_MASK4B67 register.
//
//*****************************************************************************
#define DDI_MASK4B67_M1H_M      0xF0000000  // Mask for bits [7:4] in DDI
                                            // register 7
#define DDI_MASK4B67_M1H_S      28
#define DDI_MASK4B67_D1H_M      0x0F000000  // Data for bits [7:4] in DDI
                                            // register 7, - only bits selected
                                            // by mask M1H will be affected by
                                            // access
#define DDI_MASK4B67_D1H_S      24
#define DDI_MASK4B67_M1L_M      0x00F00000  // Mask for bits [3:0] in DDI
                                            // register 7
#define DDI_MASK4B67_M1L_S      20
#define DDI_MASK4B67_D1L_M      0x000F0000  // Data for bits [3:0] in DDI
                                            // register 7, - only bits selected
                                            // by mask M1L will be affected by
                                            // access
#define DDI_MASK4B67_D1L_S      16
#define DDI_MASK4B67_M0H_M      0x0000F000  // Mask for bits [7:4] in DDI
                                            // register 6
#define DDI_MASK4B67_M0H_S      12
#define DDI_MASK4B67_D0H_M      0x00000F00  // Data for bits [7:4] in DDI
                                            // register 6, - only bits selected
                                            // by mask M0H will be affected by
                                            // access
#define DDI_MASK4B67_D0H_S      8
#define DDI_MASK4B67_M0L_M      0x000000F0  // Mask for bits [3:0] in DDI
                                            // register 6
#define DDI_MASK4B67_M0L_S      4
#define DDI_MASK4B67_D0L_M      0x0000000F  // Data for bits [3:0] in DDI
                                            // register 6, - only bits selected
                                            // by mask M0L will be affected by
                                            // access
#define DDI_MASK4B67_D0L_S      0
//*****************************************************************************
//
// The following are defines for the bit fields in the DDI_O_MASK4B89 register.
//
//*****************************************************************************
#define DDI_MASK4B89_M1H_M      0xF0000000  // Mask for bits [7:4] in DDI
                                            // register 9
#define DDI_MASK4B89_M1H_S      28
#define DDI_MASK4B89_D1H_M      0x0F000000  // Data for bits [7:4] in DDI
                                            // register 9, - only bits selected
                                            // by mask M1H will be affected by
                                            // access
#define DDI_MASK4B89_D1H_S      24
#define DDI_MASK4B89_M1L_M      0x00F00000  // Mask for bits [3:0] in DDI
                                            // register 9
#define DDI_MASK4B89_M1L_S      20
#define DDI_MASK4B89_D1L_M      0x000F0000  // Data for bits [3:0] in DDI
                                            // register 9, - only bits selected
                                            // by mask M1L will be affected by
                                            // access
#define DDI_MASK4B89_D1L_S      16
#define DDI_MASK4B89_M0H_M      0x0000F000  // Mask for bits [7:4] in DDI
                                            // register 8
#define DDI_MASK4B89_M0H_S      12
#define DDI_MASK4B89_D0H_M      0x00000F00  // Data for bits [7:4] in DDI
                                            // register 8, - only bits selected
                                            // by mask M0H will be affected by
                                            // access
#define DDI_MASK4B89_D0H_S      8
#define DDI_MASK4B89_M0L_M      0x000000F0  // Mask for bits [3:0] in DDI
                                            // register 8
#define DDI_MASK4B89_M0L_S      4
#define DDI_MASK4B89_D0L_M      0x0000000F  // Data for bits [3:0] in DDI
                                            // register 8, - only bits selected
                                            // by mask M0L will be affected by
                                            // access
#define DDI_MASK4B89_D0L_S      0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK4B1011 register.
//
//*****************************************************************************
#define DDI_MASK4B1011_M1H_M    0xF0000000  // Mask for bits [7:4] in DDI
                                            // register 11
#define DDI_MASK4B1011_M1H_S    28
#define DDI_MASK4B1011_D1H_M    0x0F000000  // Data for bits [7:4] in DDI
                                            // register 11, - only bits
                                            // selected by mask M1H will be
                                            // affected by access
#define DDI_MASK4B1011_D1H_S    24
#define DDI_MASK4B1011_M1L_M    0x00F00000  // Mask for bits [3:0] in DDI
                                            // register 11
#define DDI_MASK4B1011_M1L_S    20
#define DDI_MASK4B1011_D1L_M    0x000F0000  // Data for bits [3:0] in DDI
                                            // register 11, - only bits
                                            // selected by mask M1L will be
                                            // affected by access
#define DDI_MASK4B1011_D1L_S    16
#define DDI_MASK4B1011_M0H_M    0x0000F000  // Mask for bits [7:4] in DDI
                                            // register 10
#define DDI_MASK4B1011_M0H_S    12
#define DDI_MASK4B1011_D0H_M    0x00000F00  // Data for bits [7:4] in DDI
                                            // register 10, - only bits
                                            // selected by mask M0H will be
                                            // affected by access
#define DDI_MASK4B1011_D0H_S    8
#define DDI_MASK4B1011_M0L_M    0x000000F0  // Mask for bits [3:0] in DDI
                                            // register 10
#define DDI_MASK4B1011_M0L_S    4
#define DDI_MASK4B1011_D0L_M    0x0000000F  // Data for bits [3:0] in DDI
                                            // register 10, - only bits
                                            // selected by mask M0L will be
                                            // affected by access
#define DDI_MASK4B1011_D0L_S    0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK4B1213 register.
//
//*****************************************************************************
#define DDI_MASK4B1213_M1H_M    0xF0000000  // Mask for bits [7:4] in DDI
                                            // register 13
#define DDI_MASK4B1213_M1H_S    28
#define DDI_MASK4B1213_D1H_M    0x0F000000  // Data for bits [7:4] in DDI
                                            // register 13, - only bits
                                            // selected by mask M1H will be
                                            // affected by access
#define DDI_MASK4B1213_D1H_S    24
#define DDI_MASK4B1213_M1L_M    0x00F00000  // Mask for bits [3:0] in DDI
                                            // register 13
#define DDI_MASK4B1213_M1L_S    20
#define DDI_MASK4B1213_D1L_M    0x000F0000  // Data for bits [3:0] in DDI
                                            // register 13, - only bits
                                            // selected by mask M1L will be
                                            // affected by access
#define DDI_MASK4B1213_D1L_S    16
#define DDI_MASK4B1213_M0H_M    0x0000F000  // Mask for bits [7:4] in DDI
                                            // register 12
#define DDI_MASK4B1213_M0H_S    12
#define DDI_MASK4B1213_D0H_M    0x00000F00  // Data for bits [7:4] in DDI
                                            // register 12, - only bits
                                            // selected by mask M0H will be
                                            // affected by access
#define DDI_MASK4B1213_D0H_S    8
#define DDI_MASK4B1213_M0L_M    0x000000F0  // Mask for bits [3:0] in DDI
                                            // register 12
#define DDI_MASK4B1213_M0L_S    4
#define DDI_MASK4B1213_D0L_M    0x0000000F  // Data for bits [3:0] in DDI
                                            // register 12, - only bits
                                            // selected by mask M0L will be
                                            // affected by access
#define DDI_MASK4B1213_D0L_S    0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK4B1415 register.
//
//*****************************************************************************
#define DDI_MASK4B1415_M1H_M    0xF0000000  // Mask for bits [7:4] in DDI
                                            // register 15
#define DDI_MASK4B1415_M1H_S    28
#define DDI_MASK4B1415_D1H_M    0x0F000000  // Data for bits [7:4] in DDI
                                            // register 15, - only bits
                                            // selected by mask M1H will be
                                            // affected by access
#define DDI_MASK4B1415_D1H_S    24
#define DDI_MASK4B1415_M1L_M    0x00F00000  // Mask for bits [3:0] in DDI
                                            // register 15
#define DDI_MASK4B1415_M1L_S    20
#define DDI_MASK4B1415_D1L_M    0x000F0000  // Data for bits [3:0] in DDI
                                            // register 15, - only bits
                                            // selected by mask M1L will be
                                            // affected by access
#define DDI_MASK4B1415_D1L_S    16
#define DDI_MASK4B1415_M0H_M    0x0000F000  // Mask for bits [7:4] in DDI
                                            // register 14
#define DDI_MASK4B1415_M0H_S    12
#define DDI_MASK4B1415_D0H_M    0x00000F00  // Data for bits [7:4] in DDI
                                            // register 14, - only bits
                                            // selected by mask M0H will be
                                            // affected by access
#define DDI_MASK4B1415_D0H_S    8
#define DDI_MASK4B1415_M0L_M    0x000000F0  // Mask for bits [3:0] in DDI
                                            // register 14
#define DDI_MASK4B1415_M0L_S    4
#define DDI_MASK4B1415_D0L_M    0x0000000F  // Data for bits [3:0] in DDI
                                            // register 14, - only bits
                                            // selected by mask M0L will be
                                            // affected by access
#define DDI_MASK4B1415_D0L_S    0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK4B1617 register.
//
//*****************************************************************************
#define DDI_MASK4B1617_M1H_M    0xF0000000  // Mask for bits [7:4] in DDI
                                            // register 17
#define DDI_MASK4B1617_M1H_S    28
#define DDI_MASK4B1617_D1H_M    0x0F000000  // Data for bits [7:4] in DDI
                                            // register 17, - only bits
                                            // selected by mask M1H will be
                                            // affected by access
#define DDI_MASK4B1617_D1H_S    24
#define DDI_MASK4B1617_M1L_M    0x00F00000  // Mask for bits [3:0] in DDI
                                            // register 17
#define DDI_MASK4B1617_M1L_S    20
#define DDI_MASK4B1617_D1L_M    0x000F0000  // Data for bits [3:0] in DDI
                                            // register 17, - only bits
                                            // selected by mask M1L will be
                                            // affected by access
#define DDI_MASK4B1617_D1L_S    16
#define DDI_MASK4B1617_M0H_M    0x0000F000  // Mask for bits [7:4] in DDI
                                            // register 16
#define DDI_MASK4B1617_M0H_S    12
#define DDI_MASK4B1617_D0H_M    0x00000F00  // Data for bits [7:4] in DDI
                                            // register 16, - only bits
                                            // selected by mask M0H will be
                                            // affected by access
#define DDI_MASK4B1617_D0H_S    8
#define DDI_MASK4B1617_M0L_M    0x000000F0  // Mask for bits [3:0] in DDI
                                            // register 16
#define DDI_MASK4B1617_M0L_S    4
#define DDI_MASK4B1617_D0L_M    0x0000000F  // Data for bits [3:0] in DDI
                                            // register 16, - only bits
                                            // selected by mask M0L will be
                                            // affected by access
#define DDI_MASK4B1617_D0L_S    0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK4B1819 register.
//
//*****************************************************************************
#define DDI_MASK4B1819_M1H_M    0xF0000000  // Mask for bits [7:4] in DDI
                                            // register 19
#define DDI_MASK4B1819_M1H_S    28
#define DDI_MASK4B1819_D1H_M    0x0F000000  // Data for bits [7:4] in DDI
                                            // register 19, - only bits
                                            // selected by mask M1H will be
                                            // affected by access
#define DDI_MASK4B1819_D1H_S    24
#define DDI_MASK4B1819_M1L_M    0x00F00000  // Mask for bits [3:0] in DDI
                                            // register 19
#define DDI_MASK4B1819_M1L_S    20
#define DDI_MASK4B1819_D1L_M    0x000F0000  // Data for bits [3:0] in DDI
                                            // register 19, - only bits
                                            // selected by mask M1L will be
                                            // affected by access
#define DDI_MASK4B1819_D1L_S    16
#define DDI_MASK4B1819_M0H_M    0x0000F000  // Mask for bits [7:4] in DDI
                                            // register 18
#define DDI_MASK4B1819_M0H_S    12
#define DDI_MASK4B1819_D0H_M    0x00000F00  // Data for bits [7:4] in DDI
                                            // register 18, - only bits
                                            // selected by mask M0H will be
                                            // affected by access
#define DDI_MASK4B1819_D0H_S    8
#define DDI_MASK4B1819_M0L_M    0x000000F0  // Mask for bits [3:0] in DDI
                                            // register 18
#define DDI_MASK4B1819_M0L_S    4
#define DDI_MASK4B1819_D0L_M    0x0000000F  // Data for bits [3:0] in DDI
                                            // register 18, - only bits
                                            // selected by mask M0L will be
                                            // affected by access
#define DDI_MASK4B1819_D0L_S    0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK4B2021 register.
//
//*****************************************************************************
#define DDI_MASK4B2021_M1H_M    0xF0000000  // Mask for bits [7:4] in DDI
                                            // register 21
#define DDI_MASK4B2021_M1H_S    28
#define DDI_MASK4B2021_D1H_M    0x0F000000  // Data for bits [7:4] in DDI
                                            // register 21, - only bits
                                            // selected by mask M1H will be
                                            // affected by access
#define DDI_MASK4B2021_D1H_S    24
#define DDI_MASK4B2021_M1L_M    0x00F00000  // Mask for bits [3:0] in DDI
                                            // register 21
#define DDI_MASK4B2021_M1L_S    20
#define DDI_MASK4B2021_D1L_M    0x000F0000  // Data for bits [3:0] in DDI
                                            // register 21, - only bits
                                            // selected by mask M1L will be
                                            // affected by access
#define DDI_MASK4B2021_D1L_S    16
#define DDI_MASK4B2021_M0H_M    0x0000F000  // Mask for bits [7:4] in DDI
                                            // register 20
#define DDI_MASK4B2021_M0H_S    12
#define DDI_MASK4B2021_D0H_M    0x00000F00  // Data for bits [7:4] in DDI
                                            // register 20, - only bits
                                            // selected by mask M0H will be
                                            // affected by access
#define DDI_MASK4B2021_D0H_S    8
#define DDI_MASK4B2021_M0L_M    0x000000F0  // Mask for bits [3:0] in DDI
                                            // register 20
#define DDI_MASK4B2021_M0L_S    4
#define DDI_MASK4B2021_D0L_M    0x0000000F  // Data for bits [3:0] in DDI
                                            // register 20, - only bits
                                            // selected by mask M0L will be
                                            // affected by access
#define DDI_MASK4B2021_D0L_S    0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK4B2223 register.
//
//*****************************************************************************
#define DDI_MASK4B2223_M1H_M    0xF0000000  // Mask for bits [7:4] in DDI
                                            // register 23
#define DDI_MASK4B2223_M1H_S    28
#define DDI_MASK4B2223_D1H_M    0x0F000000  // Data for bits [7:4] in DDI
                                            // register 23, - only bits
                                            // selected by mask M1H will be
                                            // affected by access
#define DDI_MASK4B2223_D1H_S    24
#define DDI_MASK4B2223_M1L_M    0x00F00000  // Mask for bits [3:0] in DDI
                                            // register 23
#define DDI_MASK4B2223_M1L_S    20
#define DDI_MASK4B2223_D1L_M    0x000F0000  // Data for bits [3:0] in DDI
                                            // register 23, - only bits
                                            // selected by mask M1L will be
                                            // affected by access
#define DDI_MASK4B2223_D1L_S    16
#define DDI_MASK4B2223_M0H_M    0x0000F000  // Mask for bits [7:4] in DDI
                                            // register 22
#define DDI_MASK4B2223_M0H_S    12
#define DDI_MASK4B2223_D0H_M    0x00000F00  // Data for bits [7:4] in DDI
                                            // register 22, - only bits
                                            // selected by mask M0H will be
                                            // affected by access
#define DDI_MASK4B2223_D0H_S    8
#define DDI_MASK4B2223_M0L_M    0x000000F0  // Mask for bits [3:0] in DDI
                                            // register 22
#define DDI_MASK4B2223_M0L_S    4
#define DDI_MASK4B2223_D0L_M    0x0000000F  // Data for bits [3:0] in DDI
                                            // register 22, - only bits
                                            // selected by mask M0L will be
                                            // affected by access
#define DDI_MASK4B2223_D0L_S    0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK4B2425 register.
//
//*****************************************************************************
#define DDI_MASK4B2425_M1H_M    0xF0000000  // Mask for bits [7:4] in DDI
                                            // register 25
#define DDI_MASK4B2425_M1H_S    28
#define DDI_MASK4B2425_D1H_M    0x0F000000  // Data for bits [7:4] in DDI
                                            // register 25, - only bits
                                            // selected by mask M1H will be
                                            // affected by access
#define DDI_MASK4B2425_D1H_S    24
#define DDI_MASK4B2425_M1L_M    0x00F00000  // Mask for bits [3:0] in DDI
                                            // register 25
#define DDI_MASK4B2425_M1L_S    20
#define DDI_MASK4B2425_D1L_M    0x000F0000  // Data for bits [3:0] in DDI
                                            // register 25, - only bits
                                            // selected by mask M1L will be
                                            // affected by access
#define DDI_MASK4B2425_D1L_S    16
#define DDI_MASK4B2425_M0H_M    0x0000F000  // Mask for bits [7:4] in DDI
                                            // register 24
#define DDI_MASK4B2425_M0H_S    12
#define DDI_MASK4B2425_D0H_M    0x00000F00  // Data for bits [7:4] in DDI
                                            // register 24, - only bits
                                            // selected by mask M0H will be
                                            // affected by access
#define DDI_MASK4B2425_D0H_S    8
#define DDI_MASK4B2425_M0L_M    0x000000F0  // Mask for bits [3:0] in DDI
                                            // register 24
#define DDI_MASK4B2425_M0L_S    4
#define DDI_MASK4B2425_D0L_M    0x0000000F  // Data for bits [3:0] in DDI
                                            // register 24, - only bits
                                            // selected by mask M0L will be
                                            // affected by access
#define DDI_MASK4B2425_D0L_S    0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK4B2627 register.
//
//*****************************************************************************
#define DDI_MASK4B2627_M1H_M    0xF0000000  // Mask for bits [7:4] in DDI
                                            // register 27
#define DDI_MASK4B2627_M1H_S    28
#define DDI_MASK4B2627_D1H_M    0x0F000000  // Data for bits [7:4] in DDI
                                            // register 27, - only bits
                                            // selected by mask M1H will be
                                            // affected by access
#define DDI_MASK4B2627_D1H_S    24
#define DDI_MASK4B2627_M1L_M    0x00F00000  // Mask for bits [3:0] in DDI
                                            // register 27
#define DDI_MASK4B2627_M1L_S    20
#define DDI_MASK4B2627_D1L_M    0x000F0000  // Data for bits [3:0] in DDI
                                            // register 27, - only bits
                                            // selected by mask M1L will be
                                            // affected by access
#define DDI_MASK4B2627_D1L_S    16
#define DDI_MASK4B2627_M0H_M    0x0000F000  // Mask for bits [7:4] in DDI
                                            // register 26
#define DDI_MASK4B2627_M0H_S    12
#define DDI_MASK4B2627_D0H_M    0x00000F00  // Data for bits [7:4] in DDI
                                            // register 26, - only bits
                                            // selected by mask M0H will be
                                            // affected by access
#define DDI_MASK4B2627_D0H_S    8
#define DDI_MASK4B2627_M0L_M    0x000000F0  // Mask for bits [3:0] in DDI
                                            // register 26
#define DDI_MASK4B2627_M0L_S    4
#define DDI_MASK4B2627_D0L_M    0x0000000F  // Data for bits [3:0] in DDI
                                            // register 26, - only bits
                                            // selected by mask M0L will be
                                            // affected by access
#define DDI_MASK4B2627_D0L_S    0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK4B2829 register.
//
//*****************************************************************************
#define DDI_MASK4B2829_M1H_M    0xF0000000  // Mask for bits [7:4] in DDI
                                            // register 29
#define DDI_MASK4B2829_M1H_S    28
#define DDI_MASK4B2829_D1H_M    0x0F000000  // Data for bits [7:4] in DDI
                                            // register 29, - only bits
                                            // selected by mask M1H will be
                                            // affected by access
#define DDI_MASK4B2829_D1H_S    24
#define DDI_MASK4B2829_M1L_M    0x00F00000  // Mask for bits [3:0] in DDI
                                            // register 29
#define DDI_MASK4B2829_M1L_S    20
#define DDI_MASK4B2829_D1L_M    0x000F0000  // Data for bits [3:0] in DDI
                                            // register 29, - only bits
                                            // selected by mask M1L will be
                                            // affected by access
#define DDI_MASK4B2829_D1L_S    16
#define DDI_MASK4B2829_M0H_M    0x0000F000  // Mask for bits [7:4] in DDI
                                            // register 28
#define DDI_MASK4B2829_M0H_S    12
#define DDI_MASK4B2829_D0H_M    0x00000F00  // Data for bits [7:4] in DDI
                                            // register 28, - only bits
                                            // selected by mask M0H will be
                                            // affected by access
#define DDI_MASK4B2829_D0H_S    8
#define DDI_MASK4B2829_M0L_M    0x000000F0  // Mask for bits [3:0] in DDI
                                            // register 28
#define DDI_MASK4B2829_M0L_S    4
#define DDI_MASK4B2829_D0L_M    0x0000000F  // Data for bits [3:0] in DDI
                                            // register 28, - only bits
                                            // selected by mask M0L will be
                                            // affected by access
#define DDI_MASK4B2829_D0L_S    0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK4B3031 register.
//
//*****************************************************************************
#define DDI_MASK4B3031_M1H_M    0xF0000000  // Mask for bits [7:4] in DDI
                                            // register 31
#define DDI_MASK4B3031_M1H_S    28
#define DDI_MASK4B3031_D1H_M    0x0F000000  // Data for bits [7:4] in DDI
                                            // register 31, - only bits
                                            // selected by mask M1H will be
                                            // affected by access
#define DDI_MASK4B3031_D1H_S    24
#define DDI_MASK4B3031_M1L_M    0x00F00000  // Mask for bits [3:0] in DDI
                                            // register 31
#define DDI_MASK4B3031_M1L_S    20
#define DDI_MASK4B3031_D1L_M    0x000F0000  // Data for bits [3:0] in DDI
                                            // register 31, - only bits
                                            // selected by mask M1L will be
                                            // affected by access
#define DDI_MASK4B3031_D1L_S    16
#define DDI_MASK4B3031_M0H_M    0x0000F000  // Mask for bits [7:4] in DDI
                                            // register 30
#define DDI_MASK4B3031_M0H_S    12
#define DDI_MASK4B3031_D0H_M    0x00000F00  // Data for bits [7:4] in DDI
                                            // register 30, - only bits
                                            // selected by mask M0H will be
                                            // affected by access
#define DDI_MASK4B3031_D0H_S    8
#define DDI_MASK4B3031_M0L_M    0x000000F0  // Mask for bits [3:0] in DDI
                                            // register 30
#define DDI_MASK4B3031_M0L_S    4
#define DDI_MASK4B3031_D0L_M    0x0000000F  // Data for bits [3:0] in DDI
                                            // register 30, - only bits
                                            // selected by mask M0L will be
                                            // affected by access
#define DDI_MASK4B3031_D0L_S    0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK4B3233 register.
//
//*****************************************************************************
#define DDI_MASK4B3233_M1H_M    0xF0000000  // Mask for bits [7:4] in DDI
                                            // register 33
#define DDI_MASK4B3233_M1H_S    28
#define DDI_MASK4B3233_D1H_M    0x0F000000  // Data for bits [7:4] in DDI
                                            // register 33, - only bits
                                            // selected by mask M1H will be
                                            // affected by access
#define DDI_MASK4B3233_D1H_S    24
#define DDI_MASK4B3233_M1L_M    0x00F00000  // Mask for bits [3:0] in DDI
                                            // register 33
#define DDI_MASK4B3233_M1L_S    20
#define DDI_MASK4B3233_D1L_M    0x000F0000  // Data for bits [3:0] in DDI
                                            // register 33, - only bits
                                            // selected by mask M1L will be
                                            // affected by access
#define DDI_MASK4B3233_D1L_S    16
#define DDI_MASK4B3233_M0H_M    0x0000F000  // Mask for bits [7:4] in DDI
                                            // register 32
#define DDI_MASK4B3233_M0H_S    12
#define DDI_MASK4B3233_D0H_M    0x00000F00  // Data for bits [7:4] in DDI
                                            // register 32, - only bits
                                            // selected by mask M0H will be
                                            // affected by access
#define DDI_MASK4B3233_D0H_S    8
#define DDI_MASK4B3233_M0L_M    0x000000F0  // Mask for bits [3:0] in DDI
                                            // register 32
#define DDI_MASK4B3233_M0L_S    4
#define DDI_MASK4B3233_D0L_M    0x0000000F  // Data for bits [3:0] in DDI
                                            // register 32, - only bits
                                            // selected by mask M0L will be
                                            // affected by access
#define DDI_MASK4B3233_D0L_S    0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK4B3435 register.
//
//*****************************************************************************
#define DDI_MASK4B3435_M1H_M    0xF0000000  // Mask for bits [7:4] in DDI
                                            // register 35
#define DDI_MASK4B3435_M1H_S    28
#define DDI_MASK4B3435_D1H_M    0x0F000000  // Data for bits [7:4] in DDI
                                            // register 35, - only bits
                                            // selected by mask M1H will be
                                            // affected by access
#define DDI_MASK4B3435_D1H_S    24
#define DDI_MASK4B3435_M1L_M    0x00F00000  // Mask for bits [3:0] in DDI
                                            // register 35
#define DDI_MASK4B3435_M1L_S    20
#define DDI_MASK4B3435_D1L_M    0x000F0000  // Data for bits [3:0] in DDI
                                            // register 35, - only bits
                                            // selected by mask M1L will be
                                            // affected by access
#define DDI_MASK4B3435_D1L_S    16
#define DDI_MASK4B3435_M0H_M    0x0000F000  // Mask for bits [7:4] in DDI
                                            // register 34
#define DDI_MASK4B3435_M0H_S    12
#define DDI_MASK4B3435_D0H_M    0x00000F00  // Data for bits [7:4] in DDI
                                            // register 34, - only bits
                                            // selected by mask M0H will be
                                            // affected by access
#define DDI_MASK4B3435_D0H_S    8
#define DDI_MASK4B3435_M0L_M    0x000000F0  // Mask for bits [3:0] in DDI
                                            // register 34
#define DDI_MASK4B3435_M0L_S    4
#define DDI_MASK4B3435_D0L_M    0x0000000F  // Data for bits [3:0] in DDI
                                            // register 34, - only bits
                                            // selected by mask M0L will be
                                            // affected by access
#define DDI_MASK4B3435_D0L_S    0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK4B3637 register.
//
//*****************************************************************************
#define DDI_MASK4B3637_M1H_M    0xF0000000  // Mask for bits [7:4] in DDI
                                            // register 37
#define DDI_MASK4B3637_M1H_S    28
#define DDI_MASK4B3637_D1H_M    0x0F000000  // Data for bits [7:4] in DDI
                                            // register 37, - only bits
                                            // selected by mask M1H will be
                                            // affected by access
#define DDI_MASK4B3637_D1H_S    24
#define DDI_MASK4B3637_M1L_M    0x00F00000  // Mask for bits [3:0] in DDI
                                            // register 37
#define DDI_MASK4B3637_M1L_S    20
#define DDI_MASK4B3637_D1L_M    0x000F0000  // Data for bits [3:0] in DDI
                                            // register 37, - only bits
                                            // selected by mask M1L will be
                                            // affected by access
#define DDI_MASK4B3637_D1L_S    16
#define DDI_MASK4B3637_M0H_M    0x0000F000  // Mask for bits [7:4] in DDI
                                            // register 36
#define DDI_MASK4B3637_M0H_S    12
#define DDI_MASK4B3637_D0H_M    0x00000F00  // Data for bits [7:4] in DDI
                                            // register 36, - only bits
                                            // selected by mask M0H will be
                                            // affected by access
#define DDI_MASK4B3637_D0H_S    8
#define DDI_MASK4B3637_M0L_M    0x000000F0  // Mask for bits [3:0] in DDI
                                            // register 36
#define DDI_MASK4B3637_M0L_S    4
#define DDI_MASK4B3637_D0L_M    0x0000000F  // Data for bits [3:0] in DDI
                                            // register 36, - only bits
                                            // selected by mask M0L will be
                                            // affected by access
#define DDI_MASK4B3637_D0L_S    0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK4B3839 register.
//
//*****************************************************************************
#define DDI_MASK4B3839_M1H_M    0xF0000000  // Mask for bits [7:4] in DDI
                                            // register 39
#define DDI_MASK4B3839_M1H_S    28
#define DDI_MASK4B3839_D1H_M    0x0F000000  // Data for bits [7:4] in DDI
                                            // register 39, - only bits
                                            // selected by mask M1H will be
                                            // affected by access
#define DDI_MASK4B3839_D1H_S    24
#define DDI_MASK4B3839_M1L_M    0x00F00000  // Mask for bits [3:0] in DDI
                                            // register 39
#define DDI_MASK4B3839_M1L_S    20
#define DDI_MASK4B3839_D1L_M    0x000F0000  // Data for bits [3:0] in DDI
                                            // register 39, - only bits
                                            // selected by mask M1L will be
                                            // affected by access
#define DDI_MASK4B3839_D1L_S    16
#define DDI_MASK4B3839_M0H_M    0x0000F000  // Mask for bits [7:4] in DDI
                                            // register 38
#define DDI_MASK4B3839_M0H_S    12
#define DDI_MASK4B3839_D0H_M    0x00000F00  // Data for bits [7:4] in DDI
                                            // register 38, - only bits
                                            // selected by mask M0H will be
                                            // affected by access
#define DDI_MASK4B3839_D0H_S    8
#define DDI_MASK4B3839_M0L_M    0x000000F0  // Mask for bits [3:0] in DDI
                                            // register 38
#define DDI_MASK4B3839_M0L_S    4
#define DDI_MASK4B3839_D0L_M    0x0000000F  // Data for bits [3:0] in DDI
                                            // register 38, - only bits
                                            // selected by mask M0L will be
                                            // affected by access
#define DDI_MASK4B3839_D0L_S    0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK4B4041 register.
//
//*****************************************************************************
#define DDI_MASK4B4041_M1H_M    0xF0000000  // Mask for bits [7:4] in DDI
                                            // register 41
#define DDI_MASK4B4041_M1H_S    28
#define DDI_MASK4B4041_D1H_M    0x0F000000  // Data for bits [7:4] in DDI
                                            // register 41, - only bits
                                            // selected by mask M1H will be
                                            // affected by access
#define DDI_MASK4B4041_D1H_S    24
#define DDI_MASK4B4041_M1L_M    0x00F00000  // Mask for bits [3:0] in DDI
                                            // register 41
#define DDI_MASK4B4041_M1L_S    20
#define DDI_MASK4B4041_D1L_M    0x000F0000  // Data for bits [3:0] in DDI
                                            // register 41, - only bits
                                            // selected by mask M1L will be
                                            // affected by access
#define DDI_MASK4B4041_D1L_S    16
#define DDI_MASK4B4041_M0H_M    0x0000F000  // Mask for bits [7:4] in DDI
                                            // register 40
#define DDI_MASK4B4041_M0H_S    12
#define DDI_MASK4B4041_D0H_M    0x00000F00  // Data for bits [7:4] in DDI
                                            // register 40, - only bits
                                            // selected by mask M0H will be
                                            // affected by access
#define DDI_MASK4B4041_D0H_S    8
#define DDI_MASK4B4041_M0L_M    0x000000F0  // Mask for bits [3:0] in DDI
                                            // register 40
#define DDI_MASK4B4041_M0L_S    4
#define DDI_MASK4B4041_D0L_M    0x0000000F  // Data for bits [3:0] in DDI
                                            // register 40, - only bits
                                            // selected by mask M0L will be
                                            // affected by access
#define DDI_MASK4B4041_D0L_S    0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK4B4243 register.
//
//*****************************************************************************
#define DDI_MASK4B4243_M1H_M    0xF0000000  // Mask for bits [7:4] in DDI
                                            // register 43
#define DDI_MASK4B4243_M1H_S    28
#define DDI_MASK4B4243_D1H_M    0x0F000000  // Data for bits [7:4] in DDI
                                            // register 43, - only bits
                                            // selected by mask M1H will be
                                            // affected by access
#define DDI_MASK4B4243_D1H_S    24
#define DDI_MASK4B4243_M1L_M    0x00F00000  // Mask for bits [3:0] in DDI
                                            // register 43
#define DDI_MASK4B4243_M1L_S    20
#define DDI_MASK4B4243_D1L_M    0x000F0000  // Data for bits [3:0] in DDI
                                            // register 43, - only bits
                                            // selected by mask M1L will be
                                            // affected by access
#define DDI_MASK4B4243_D1L_S    16
#define DDI_MASK4B4243_M0H_M    0x0000F000  // Mask for bits [7:4] in DDI
                                            // register 42
#define DDI_MASK4B4243_M0H_S    12
#define DDI_MASK4B4243_D0H_M    0x00000F00  // Data for bits [7:4] in DDI
                                            // register 42, - only bits
                                            // selected by mask M0H will be
                                            // affected by access
#define DDI_MASK4B4243_D0H_S    8
#define DDI_MASK4B4243_M0L_M    0x000000F0  // Mask for bits [3:0] in DDI
                                            // register 42
#define DDI_MASK4B4243_M0L_S    4
#define DDI_MASK4B4243_D0L_M    0x0000000F  // Data for bits [3:0] in DDI
                                            // register 42, - only bits
                                            // selected by mask M0L will be
                                            // affected by access
#define DDI_MASK4B4243_D0L_S    0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK4B4445 register.
//
//*****************************************************************************
#define DDI_MASK4B4445_M1H_M    0xF0000000  // Mask for bits [7:4] in DDI
                                            // register 45
#define DDI_MASK4B4445_M1H_S    28
#define DDI_MASK4B4445_D1H_M    0x0F000000  // Data for bits [7:4] in DDI
                                            // register 45, - only bits
                                            // selected by mask M1H will be
                                            // affected by access
#define DDI_MASK4B4445_D1H_S    24
#define DDI_MASK4B4445_M1L_M    0x00F00000  // Mask for bits [3:0] in DDI
                                            // register 45
#define DDI_MASK4B4445_M1L_S    20
#define DDI_MASK4B4445_D1L_M    0x000F0000  // Data for bits [3:0] in DDI
                                            // register 45, - only bits
                                            // selected by mask M1L will be
                                            // affected by access
#define DDI_MASK4B4445_D1L_S    16
#define DDI_MASK4B4445_M0H_M    0x0000F000  // Mask for bits [7:4] in DDI
                                            // register 44
#define DDI_MASK4B4445_M0H_S    12
#define DDI_MASK4B4445_D0H_M    0x00000F00  // Data for bits [7:4] in DDI
                                            // register 44, - only bits
                                            // selected by mask M0H will be
                                            // affected by access
#define DDI_MASK4B4445_D0H_S    8
#define DDI_MASK4B4445_M0L_M    0x000000F0  // Mask for bits [3:0] in DDI
                                            // register 44
#define DDI_MASK4B4445_M0L_S    4
#define DDI_MASK4B4445_D0L_M    0x0000000F  // Data for bits [3:0] in DDI
                                            // register 44, - only bits
                                            // selected by mask M0L will be
                                            // affected by access
#define DDI_MASK4B4445_D0L_S    0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK4B4647 register.
//
//*****************************************************************************
#define DDI_MASK4B4647_M1H_M    0xF0000000  // Mask for bits [7:4] in DDI
                                            // register 47
#define DDI_MASK4B4647_M1H_S    28
#define DDI_MASK4B4647_D1H_M    0x0F000000  // Data for bits [7:4] in DDI
                                            // register 47, - only bits
                                            // selected by mask M1H will be
                                            // affected by access
#define DDI_MASK4B4647_D1H_S    24
#define DDI_MASK4B4647_M1L_M    0x00F00000  // Mask for bits [3:0] in DDI
                                            // register 47
#define DDI_MASK4B4647_M1L_S    20
#define DDI_MASK4B4647_D1L_M    0x000F0000  // Data for bits [3:0] in DDI
                                            // register 47, - only bits
                                            // selected by mask M1L will be
                                            // affected by access
#define DDI_MASK4B4647_D1L_S    16
#define DDI_MASK4B4647_M0H_M    0x0000F000  // Mask for bits [7:4] in DDI
                                            // register 46
#define DDI_MASK4B4647_M0H_S    12
#define DDI_MASK4B4647_D0H_M    0x00000F00  // Data for bits [7:4] in DDI
                                            // register 46, - only bits
                                            // selected by mask M0H will be
                                            // affected by access
#define DDI_MASK4B4647_D0H_S    8
#define DDI_MASK4B4647_M0L_M    0x000000F0  // Mask for bits [3:0] in DDI
                                            // register 46
#define DDI_MASK4B4647_M0L_S    4
#define DDI_MASK4B4647_D0L_M    0x0000000F  // Data for bits [3:0] in DDI
                                            // register 46, - only bits
                                            // selected by mask M0L will be
                                            // affected by access
#define DDI_MASK4B4647_D0L_S    0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK4B4849 register.
//
//*****************************************************************************
#define DDI_MASK4B4849_M1H_M    0xF0000000  // Mask for bits [7:4] in DDI
                                            // register 49
#define DDI_MASK4B4849_M1H_S    28
#define DDI_MASK4B4849_D1H_M    0x0F000000  // Data for bits [7:4] in DDI
                                            // register 49, - only bits
                                            // selected by mask M1H will be
                                            // affected by access
#define DDI_MASK4B4849_D1H_S    24
#define DDI_MASK4B4849_M1L_M    0x00F00000  // Mask for bits [3:0] in DDI
                                            // register 49
#define DDI_MASK4B4849_M1L_S    20
#define DDI_MASK4B4849_D1L_M    0x000F0000  // Data for bits [3:0] in DDI
                                            // register 49, - only bits
                                            // selected by mask M1L will be
                                            // affected by access
#define DDI_MASK4B4849_D1L_S    16
#define DDI_MASK4B4849_M0H_M    0x0000F000  // Mask for bits [7:4] in DDI
                                            // register 48
#define DDI_MASK4B4849_M0H_S    12
#define DDI_MASK4B4849_D0H_M    0x00000F00  // Data for bits [7:4] in DDI
                                            // register 48, - only bits
                                            // selected by mask M0H will be
                                            // affected by access
#define DDI_MASK4B4849_D0H_S    8
#define DDI_MASK4B4849_M0L_M    0x000000F0  // Mask for bits [3:0] in DDI
                                            // register 48
#define DDI_MASK4B4849_M0L_S    4
#define DDI_MASK4B4849_D0L_M    0x0000000F  // Data for bits [3:0] in DDI
                                            // register 48, - only bits
                                            // selected by mask M0L will be
                                            // affected by access
#define DDI_MASK4B4849_D0L_S    0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK4B5051 register.
//
//*****************************************************************************
#define DDI_MASK4B5051_M1H_M    0xF0000000  // Mask for bits [7:4] in DDI
                                            // register 51
#define DDI_MASK4B5051_M1H_S    28
#define DDI_MASK4B5051_D1H_M    0x0F000000  // Data for bits [7:4] in DDI
                                            // register 51, - only bits
                                            // selected by mask M1H will be
                                            // affected by access
#define DDI_MASK4B5051_D1H_S    24
#define DDI_MASK4B5051_M1L_M    0x00F00000  // Mask for bits [3:0] in DDI
                                            // register 51
#define DDI_MASK4B5051_M1L_S    20
#define DDI_MASK4B5051_D1L_M    0x000F0000  // Data for bits [3:0] in DDI
                                            // register 51, - only bits
                                            // selected by mask M1L will be
                                            // affected by access
#define DDI_MASK4B5051_D1L_S    16
#define DDI_MASK4B5051_M0H_M    0x0000F000  // Mask for bits [7:4] in DDI
                                            // register 50
#define DDI_MASK4B5051_M0H_S    12
#define DDI_MASK4B5051_D0H_M    0x00000F00  // Data for bits [7:4] in DDI
                                            // register 50, - only bits
                                            // selected by mask M0H will be
                                            // affected by access
#define DDI_MASK4B5051_D0H_S    8
#define DDI_MASK4B5051_M0L_M    0x000000F0  // Mask for bits [3:0] in DDI
                                            // register 50
#define DDI_MASK4B5051_M0L_S    4
#define DDI_MASK4B5051_D0L_M    0x0000000F  // Data for bits [3:0] in DDI
                                            // register 50, - only bits
                                            // selected by mask M0L will be
                                            // affected by access
#define DDI_MASK4B5051_D0L_S    0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK4B5253 register.
//
//*****************************************************************************
#define DDI_MASK4B5253_M1H_M    0xF0000000  // Mask for bits [7:4] in DDI
                                            // register 53
#define DDI_MASK4B5253_M1H_S    28
#define DDI_MASK4B5253_D1H_M    0x0F000000  // Data for bits [7:4] in DDI
                                            // register 53, - only bits
                                            // selected by mask M1H will be
                                            // affected by access
#define DDI_MASK4B5253_D1H_S    24
#define DDI_MASK4B5253_M1L_M    0x00F00000  // Mask for bits [3:0] in DDI
                                            // register 53
#define DDI_MASK4B5253_M1L_S    20
#define DDI_MASK4B5253_D1L_M    0x000F0000  // Data for bits [3:0] in DDI
                                            // register 53, - only bits
                                            // selected by mask M1L will be
                                            // affected by access
#define DDI_MASK4B5253_D1L_S    16
#define DDI_MASK4B5253_M0H_M    0x0000F000  // Mask for bits [7:4] in DDI
                                            // register 52
#define DDI_MASK4B5253_M0H_S    12
#define DDI_MASK4B5253_D0H_M    0x00000F00  // Data for bits [7:4] in DDI
                                            // register 52, - only bits
                                            // selected by mask M0H will be
                                            // affected by access
#define DDI_MASK4B5253_D0H_S    8
#define DDI_MASK4B5253_M0L_M    0x000000F0  // Mask for bits [3:0] in DDI
                                            // register 52
#define DDI_MASK4B5253_M0L_S    4
#define DDI_MASK4B5253_D0L_M    0x0000000F  // Data for bits [3:0] in DDI
                                            // register 52, - only bits
                                            // selected by mask M0L will be
                                            // affected by access
#define DDI_MASK4B5253_D0L_S    0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK4B5455 register.
//
//*****************************************************************************
#define DDI_MASK4B5455_M1H_M    0xF0000000  // Mask for bits [7:4] in DDI
                                            // register 55
#define DDI_MASK4B5455_M1H_S    28
#define DDI_MASK4B5455_D1H_M    0x0F000000  // Data for bits [7:4] in DDI
                                            // register 55, - only bits
                                            // selected by mask M1H will be
                                            // affected by access
#define DDI_MASK4B5455_D1H_S    24
#define DDI_MASK4B5455_M1L_M    0x00F00000  // Mask for bits [3:0] in DDI
                                            // register 55
#define DDI_MASK4B5455_M1L_S    20
#define DDI_MASK4B5455_D1L_M    0x000F0000  // Data for bits [3:0] in DDI
                                            // register 55, - only bits
                                            // selected by mask M1L will be
                                            // affected by access
#define DDI_MASK4B5455_D1L_S    16
#define DDI_MASK4B5455_M0H_M    0x0000F000  // Mask for bits [7:4] in DDI
                                            // register 54
#define DDI_MASK4B5455_M0H_S    12
#define DDI_MASK4B5455_D0H_M    0x00000F00  // Data for bits [7:4] in DDI
                                            // register 54, - only bits
                                            // selected by mask M0H will be
                                            // affected by access
#define DDI_MASK4B5455_D0H_S    8
#define DDI_MASK4B5455_M0L_M    0x000000F0  // Mask for bits [3:0] in DDI
                                            // register 54
#define DDI_MASK4B5455_M0L_S    4
#define DDI_MASK4B5455_D0L_M    0x0000000F  // Data for bits [3:0] in DDI
                                            // register 54, - only bits
                                            // selected by mask M0L will be
                                            // affected by access
#define DDI_MASK4B5455_D0L_S    0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK4B5657 register.
//
//*****************************************************************************
#define DDI_MASK4B5657_M1H_M    0xF0000000  // Mask for bits [7:4] in DDI
                                            // register 57
#define DDI_MASK4B5657_M1H_S    28
#define DDI_MASK4B5657_D1H_M    0x0F000000  // Data for bits [7:4] in DDI
                                            // register 57, - only bits
                                            // selected by mask M1H will be
                                            // affected by access
#define DDI_MASK4B5657_D1H_S    24
#define DDI_MASK4B5657_M1L_M    0x00F00000  // Mask for bits [3:0] in DDI
                                            // register 57
#define DDI_MASK4B5657_M1L_S    20
#define DDI_MASK4B5657_D1L_M    0x000F0000  // Data for bits [3:0] in DDI
                                            // register 57, - only bits
                                            // selected by mask M1L will be
                                            // affected by access
#define DDI_MASK4B5657_D1L_S    16
#define DDI_MASK4B5657_M0H_M    0x0000F000  // Mask for bits [7:4] in DDI
                                            // register 56
#define DDI_MASK4B5657_M0H_S    12
#define DDI_MASK4B5657_D0H_M    0x00000F00  // Data for bits [7:4] in DDI
                                            // register 56, - only bits
                                            // selected by mask M0H will be
                                            // affected by access
#define DDI_MASK4B5657_D0H_S    8
#define DDI_MASK4B5657_M0L_M    0x000000F0  // Mask for bits [3:0] in DDI
                                            // register 56
#define DDI_MASK4B5657_M0L_S    4
#define DDI_MASK4B5657_D0L_M    0x0000000F  // Data for bits [3:0] in DDI
                                            // register 56, - only bits
                                            // selected by mask M0L will be
                                            // affected by access
#define DDI_MASK4B5657_D0L_S    0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK4B5859 register.
//
//*****************************************************************************
#define DDI_MASK4B5859_M1H_M    0xF0000000  // Mask for bits [7:4] in DDI
                                            // register 59
#define DDI_MASK4B5859_M1H_S    28
#define DDI_MASK4B5859_D1H_M    0x0F000000  // Data for bits [7:4] in DDI
                                            // register 59, - only bits
                                            // selected by mask M1H will be
                                            // affected by access
#define DDI_MASK4B5859_D1H_S    24
#define DDI_MASK4B5859_M1L_M    0x00F00000  // Mask for bits [3:0] in DDI
                                            // register 59
#define DDI_MASK4B5859_M1L_S    20
#define DDI_MASK4B5859_D1L_M    0x000F0000  // Data for bits [3:0] in DDI
                                            // register 59, - only bits
                                            // selected by mask M1L will be
                                            // affected by access
#define DDI_MASK4B5859_D1L_S    16
#define DDI_MASK4B5859_M0H_M    0x0000F000  // Mask for bits [7:4] in DDI
                                            // register 58
#define DDI_MASK4B5859_M0H_S    12
#define DDI_MASK4B5859_D0H_M    0x00000F00  // Data for bits [7:4] in DDI
                                            // register 58, - only bits
                                            // selected by mask M0H will be
                                            // affected by access
#define DDI_MASK4B5859_D0H_S    8
#define DDI_MASK4B5859_M0L_M    0x000000F0  // Mask for bits [3:0] in DDI
                                            // register 58
#define DDI_MASK4B5859_M0L_S    4
#define DDI_MASK4B5859_D0L_M    0x0000000F  // Data for bits [3:0] in DDI
                                            // register 58, - only bits
                                            // selected by mask M0L will be
                                            // affected by access
#define DDI_MASK4B5859_D0L_S    0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK4B6061 register.
//
//*****************************************************************************
#define DDI_MASK4B6061_M1H_M    0xF0000000  // Mask for bits [7:4] in DDI
                                            // register 61
#define DDI_MASK4B6061_M1H_S    28
#define DDI_MASK4B6061_D1H_M    0x0F000000  // Data for bits [7:4] in DDI
                                            // register 61, - only bits
                                            // selected by mask M1H will be
                                            // affected by access
#define DDI_MASK4B6061_D1H_S    24
#define DDI_MASK4B6061_M1L_M    0x00F00000  // Mask for bits [3:0] in DDI
                                            // register 61
#define DDI_MASK4B6061_M1L_S    20
#define DDI_MASK4B6061_D1L_M    0x000F0000  // Data for bits [3:0] in DDI
                                            // register 61, - only bits
                                            // selected by mask M1L will be
                                            // affected by access
#define DDI_MASK4B6061_D1L_S    16
#define DDI_MASK4B6061_M0H_M    0x0000F000  // Mask for bits [7:4] in DDI
                                            // register 60
#define DDI_MASK4B6061_M0H_S    12
#define DDI_MASK4B6061_D0H_M    0x00000F00  // Data for bits [7:4] in DDI
                                            // register 60, - only bits
                                            // selected by mask M0H will be
                                            // affected by access
#define DDI_MASK4B6061_D0H_S    8
#define DDI_MASK4B6061_M0L_M    0x000000F0  // Mask for bits [3:0] in DDI
                                            // register 60
#define DDI_MASK4B6061_M0L_S    4
#define DDI_MASK4B6061_D0L_M    0x0000000F  // Data for bits [3:0] in DDI
                                            // register 60, - only bits
                                            // selected by mask M0L will be
                                            // affected by access
#define DDI_MASK4B6061_D0L_S    0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK4B6263 register.
//
//*****************************************************************************
#define DDI_MASK4B6263_M1H_M    0xF0000000  // Mask for bits [7:4] in DDI
                                            // register 63
#define DDI_MASK4B6263_M1H_S    28
#define DDI_MASK4B6263_D1H_M    0x0F000000  // Data for bits [7:4] in DDI
                                            // register 63, - only bits
                                            // selected by mask M1H will be
                                            // affected by access
#define DDI_MASK4B6263_D1H_S    24
#define DDI_MASK4B6263_M1L_M    0x00F00000  // Mask for bits [3:0] in DDI
                                            // register 63
#define DDI_MASK4B6263_M1L_S    20
#define DDI_MASK4B6263_D1L_M    0x000F0000  // Data for bits [3:0] in DDI
                                            // register 63, - only bits
                                            // selected by mask M1L will be
                                            // affected by access
#define DDI_MASK4B6263_D1L_S    16
#define DDI_MASK4B6263_M0H_M    0x0000F000  // Mask for bits [7:4] in DDI
                                            // register 62
#define DDI_MASK4B6263_M0H_S    12
#define DDI_MASK4B6263_D0H_M    0x00000F00  // Data for bits [7:4] in DDI
                                            // register 62, - only bits
                                            // selected by mask M0H will be
                                            // affected by access
#define DDI_MASK4B6263_D0H_S    8
#define DDI_MASK4B6263_M0L_M    0x000000F0  // Mask for bits [3:0] in DDI
                                            // register 62
#define DDI_MASK4B6263_M0L_S    4
#define DDI_MASK4B6263_D0L_M    0x0000000F  // Data for bits [3:0] in DDI
                                            // register 62, - only bits
                                            // selected by mask M0L will be
                                            // affected by access
#define DDI_MASK4B6263_D0L_S    0
//*****************************************************************************
//
// The following are defines for the bit fields in the DDI_O_MASK8B01 register.
//
//*****************************************************************************
#define DDI_MASK8B01_M1_M       0xFF000000  // Mask for DDI register 1
#define DDI_MASK8B01_M1_S       24
#define DDI_MASK8B01_D1_M       0x00FF0000  // Data for DDI register 1, - only
                                            // bits selected by mask M1 will be
                                            // affected by access
#define DDI_MASK8B01_D1_S       16
#define DDI_MASK8B01_M0_M       0x0000FF00  // Mask for DDI register 0
#define DDI_MASK8B01_M0_S       8
#define DDI_MASK8B01_D0_M       0x000000FF  // Data for DDI register 0, - only
                                            // bits selected by mask M0 will be
                                            // affected by access
#define DDI_MASK8B01_D0_S       0
//*****************************************************************************
//
// The following are defines for the bit fields in the DDI_O_MASK8B23 register.
//
//*****************************************************************************
#define DDI_MASK8B23_M1_M       0xFF000000  // Mask for DDI register 3
#define DDI_MASK8B23_M1_S       24
#define DDI_MASK8B23_D1_M       0x00FF0000  // Data for DDI register 3, - only
                                            // bits selected by mask M1 will be
                                            // affected by access
#define DDI_MASK8B23_D1_S       16
#define DDI_MASK8B23_M0_M       0x0000FF00  // Mask for DDI register 2
#define DDI_MASK8B23_M0_S       8
#define DDI_MASK8B23_D0_M       0x000000FF  // Data for DDI register 2, - only
                                            // bits selected by mask M0 will be
                                            // affected by access
#define DDI_MASK8B23_D0_S       0
//*****************************************************************************
//
// The following are defines for the bit fields in the DDI_O_MASK8B45 register.
//
//*****************************************************************************
#define DDI_MASK8B45_M1_M       0xFF000000  // Mask for DDI register 5
#define DDI_MASK8B45_M1_S       24
#define DDI_MASK8B45_D1_M       0x00FF0000  // Data for DDI register 5, - only
                                            // bits selected by mask M1 will be
                                            // affected by access
#define DDI_MASK8B45_D1_S       16
#define DDI_MASK8B45_M0_M       0x0000FF00  // Mask for DDI register 4
#define DDI_MASK8B45_M0_S       8
#define DDI_MASK8B45_D0_M       0x000000FF  // Data for DDI register 4, - only
                                            // bits selected by mask M0 will be
                                            // affected by access
#define DDI_MASK8B45_D0_S       0
//*****************************************************************************
//
// The following are defines for the bit fields in the DDI_O_MASK8B67 register.
//
//*****************************************************************************
#define DDI_MASK8B67_M1_M       0xFF000000  // Mask for DDI register 7
#define DDI_MASK8B67_M1_S       24
#define DDI_MASK8B67_D1_M       0x00FF0000  // Data for DDI register 7, - only
                                            // bits selected by mask M1 will be
                                            // affected by access
#define DDI_MASK8B67_D1_S       16
#define DDI_MASK8B67_M0_M       0x0000FF00  // Mask for DDI register 6
#define DDI_MASK8B67_M0_S       8
#define DDI_MASK8B67_D0_M       0x000000FF  // Data for DDI register 6, - only
                                            // bits selected by mask M0 will be
                                            // affected by access
#define DDI_MASK8B67_D0_S       0
//*****************************************************************************
//
// The following are defines for the bit fields in the DDI_O_MASK8B89 register.
//
//*****************************************************************************
#define DDI_MASK8B89_M1_M       0xFF000000  // Mask for DDI register 9
#define DDI_MASK8B89_M1_S       24
#define DDI_MASK8B89_D1_M       0x00FF0000  // Data for DDI register 9, - only
                                            // bits selected by mask M1 will be
                                            // affected by access
#define DDI_MASK8B89_D1_S       16
#define DDI_MASK8B89_M0_M       0x0000FF00  // Mask for DDI register 8
#define DDI_MASK8B89_M0_S       8
#define DDI_MASK8B89_D0_M       0x000000FF  // Data for DDI register 8, - only
                                            // bits selected by mask M0 will be
                                            // affected by access
#define DDI_MASK8B89_D0_S       0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK8B1011 register.
//
//*****************************************************************************
#define DDI_MASK8B1011_M1_M     0xFF000000  // Mask for DDI register 11
#define DDI_MASK8B1011_M1_S     24
#define DDI_MASK8B1011_D1_M     0x00FF0000  // Data for DDI register 11, -
                                            // only bits selected by mask M1
                                            // will be affected by access
#define DDI_MASK8B1011_D1_S     16
#define DDI_MASK8B1011_M0_M     0x0000FF00  // Mask for DDI register 10
#define DDI_MASK8B1011_M0_S     8
#define DDI_MASK8B1011_D0_M     0x000000FF  // Data for DDI register 10, -
                                            // only bits selected by mask M0
                                            // will be affected by access
#define DDI_MASK8B1011_D0_S     0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK8B1213 register.
//
//*****************************************************************************
#define DDI_MASK8B1213_M1_M     0xFF000000  // Mask for DDI register 13
#define DDI_MASK8B1213_M1_S     24
#define DDI_MASK8B1213_D1_M     0x00FF0000  // Data for DDI register 13, -
                                            // only bits selected by mask M1
                                            // will be affected by access
#define DDI_MASK8B1213_D1_S     16
#define DDI_MASK8B1213_M0_M     0x0000FF00  // Mask for DDI register 12
#define DDI_MASK8B1213_M0_S     8
#define DDI_MASK8B1213_D0_M     0x000000FF  // Data for DDI register 12, -
                                            // only bits selected by mask M0
                                            // will be affected by access
#define DDI_MASK8B1213_D0_S     0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK8B1415 register.
//
//*****************************************************************************
#define DDI_MASK8B1415_M1_M     0xFF000000  // Mask for DDI register 15
#define DDI_MASK8B1415_M1_S     24
#define DDI_MASK8B1415_D1_M     0x00FF0000  // Data for DDI register 15, -
                                            // only bits selected by mask M1
                                            // will be affected by access
#define DDI_MASK8B1415_D1_S     16
#define DDI_MASK8B1415_M0_M     0x0000FF00  // Mask for DDI register 14
#define DDI_MASK8B1415_M0_S     8
#define DDI_MASK8B1415_D0_M     0x000000FF  // Data for DDI register 14, -
                                            // only bits selected by mask M0
                                            // will be affected by access
#define DDI_MASK8B1415_D0_S     0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK8B1617 register.
//
//*****************************************************************************
#define DDI_MASK8B1617_M1_M     0xFF000000  // Mask for DDI register 17
#define DDI_MASK8B1617_M1_S     24
#define DDI_MASK8B1617_D1_M     0x00FF0000  // Data for DDI register 17, -
                                            // only bits selected by mask M1
                                            // will be affected by access
#define DDI_MASK8B1617_D1_S     16
#define DDI_MASK8B1617_M0_M     0x0000FF00  // Mask for DDI register 16
#define DDI_MASK8B1617_M0_S     8
#define DDI_MASK8B1617_D0_M     0x000000FF  // Data for DDI register 16, -
                                            // only bits selected by mask M0
                                            // will be affected by access
#define DDI_MASK8B1617_D0_S     0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK8B1819 register.
//
//*****************************************************************************
#define DDI_MASK8B1819_M1_M     0xFF000000  // Mask for DDI register 19
#define DDI_MASK8B1819_M1_S     24
#define DDI_MASK8B1819_D1_M     0x00FF0000  // Data for DDI register 19, -
                                            // only bits selected by mask M1
                                            // will be affected by access
#define DDI_MASK8B1819_D1_S     16
#define DDI_MASK8B1819_M0_M     0x0000FF00  // Mask for DDI register 18
#define DDI_MASK8B1819_M0_S     8
#define DDI_MASK8B1819_D0_M     0x000000FF  // Data for DDI register 18, -
                                            // only bits selected by mask M0
                                            // will be affected by access
#define DDI_MASK8B1819_D0_S     0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK8B2021 register.
//
//*****************************************************************************
#define DDI_MASK8B2021_M1_M     0xFF000000  // Mask for DDI register 21
#define DDI_MASK8B2021_M1_S     24
#define DDI_MASK8B2021_D1_M     0x00FF0000  // Data for DDI register 21, -
                                            // only bits selected by mask M1
                                            // will be affected by access
#define DDI_MASK8B2021_D1_S     16
#define DDI_MASK8B2021_M0_M     0x0000FF00  // Mask for DDI register 20
#define DDI_MASK8B2021_M0_S     8
#define DDI_MASK8B2021_D0_M     0x000000FF  // Data for DDI register 20, -
                                            // only bits selected by mask M0
                                            // will be affected by access
#define DDI_MASK8B2021_D0_S     0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK8B2223 register.
//
//*****************************************************************************
#define DDI_MASK8B2223_M1_M     0xFF000000  // Mask for DDI register 23
#define DDI_MASK8B2223_M1_S     24
#define DDI_MASK8B2223_D1_M     0x00FF0000  // Data for DDI register 23, -
                                            // only bits selected by mask M1
                                            // will be affected by access
#define DDI_MASK8B2223_D1_S     16
#define DDI_MASK8B2223_M0_M     0x0000FF00  // Mask for DDI register 22
#define DDI_MASK8B2223_M0_S     8
#define DDI_MASK8B2223_D0_M     0x000000FF  // Data for DDI register 22, -
                                            // only bits selected by mask M0
                                            // will be affected by access
#define DDI_MASK8B2223_D0_S     0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK8B2425 register.
//
//*****************************************************************************
#define DDI_MASK8B2425_M1_M     0xFF000000  // Mask for DDI register 25
#define DDI_MASK8B2425_M1_S     24
#define DDI_MASK8B2425_D1_M     0x00FF0000  // Data for DDI register 25, -
                                            // only bits selected by mask M1
                                            // will be affected by access
#define DDI_MASK8B2425_D1_S     16
#define DDI_MASK8B2425_M0_M     0x0000FF00  // Mask for DDI register 24
#define DDI_MASK8B2425_M0_S     8
#define DDI_MASK8B2425_D0_M     0x000000FF  // Data for DDI register 24, -
                                            // only bits selected by mask M0
                                            // will be affected by access
#define DDI_MASK8B2425_D0_S     0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK8B2627 register.
//
//*****************************************************************************
#define DDI_MASK8B2627_M1_M     0xFF000000  // Mask for DDI register 27
#define DDI_MASK8B2627_M1_S     24
#define DDI_MASK8B2627_D1_M     0x00FF0000  // Data for DDI register 27, -
                                            // only bits selected by mask M1
                                            // will be affected by access
#define DDI_MASK8B2627_D1_S     16
#define DDI_MASK8B2627_M0_M     0x0000FF00  // Mask for DDI register 26
#define DDI_MASK8B2627_M0_S     8
#define DDI_MASK8B2627_D0_M     0x000000FF  // Data for DDI register 26, -
                                            // only bits selected by mask M0
                                            // will be affected by access
#define DDI_MASK8B2627_D0_S     0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK8B2829 register.
//
//*****************************************************************************
#define DDI_MASK8B2829_M1_M     0xFF000000  // Mask for DDI register 29
#define DDI_MASK8B2829_M1_S     24
#define DDI_MASK8B2829_D1_M     0x00FF0000  // Data for DDI register 29, -
                                            // only bits selected by mask M1
                                            // will be affected by access
#define DDI_MASK8B2829_D1_S     16
#define DDI_MASK8B2829_M0_M     0x0000FF00  // Mask for DDI register 28
#define DDI_MASK8B2829_M0_S     8
#define DDI_MASK8B2829_D0_M     0x000000FF  // Data for DDI register 28, -
                                            // only bits selected by mask M0
                                            // will be affected by access
#define DDI_MASK8B2829_D0_S     0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK8B3031 register.
//
//*****************************************************************************
#define DDI_MASK8B3031_M1_M     0xFF000000  // Mask for DDI register 31
#define DDI_MASK8B3031_M1_S     24
#define DDI_MASK8B3031_D1_M     0x00FF0000  // Data for DDI register 31, -
                                            // only bits selected by mask M1
                                            // will be affected by access
#define DDI_MASK8B3031_D1_S     16
#define DDI_MASK8B3031_M0_M     0x0000FF00  // Mask for DDI register 30
#define DDI_MASK8B3031_M0_S     8
#define DDI_MASK8B3031_D0_M     0x000000FF  // Data for DDI register 30, -
                                            // only bits selected by mask M0
                                            // will be affected by access
#define DDI_MASK8B3031_D0_S     0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK8B3233 register.
//
//*****************************************************************************
#define DDI_MASK8B3233_M1_M     0xFF000000  // Mask for DDI register 33
#define DDI_MASK8B3233_M1_S     24
#define DDI_MASK8B3233_D1_M     0x00FF0000  // Data for DDI register 33, -
                                            // only bits selected by mask M1
                                            // will be affected by access
#define DDI_MASK8B3233_D1_S     16
#define DDI_MASK8B3233_M0_M     0x0000FF00  // Mask for DDI register 32
#define DDI_MASK8B3233_M0_S     8
#define DDI_MASK8B3233_D0_M     0x000000FF  // Data for DDI register 32, -
                                            // only bits selected by mask M0
                                            // will be affected by access
#define DDI_MASK8B3233_D0_S     0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK8B3435 register.
//
//*****************************************************************************
#define DDI_MASK8B3435_M1_M     0xFF000000  // Mask for DDI register 35
#define DDI_MASK8B3435_M1_S     24
#define DDI_MASK8B3435_D1_M     0x00FF0000  // Data for DDI register 35, -
                                            // only bits selected by mask M1
                                            // will be affected by access
#define DDI_MASK8B3435_D1_S     16
#define DDI_MASK8B3435_M0_M     0x0000FF00  // Mask for DDI register 34
#define DDI_MASK8B3435_M0_S     8
#define DDI_MASK8B3435_D0_M     0x000000FF  // Data for DDI register 34, -
                                            // only bits selected by mask M0
                                            // will be affected by access
#define DDI_MASK8B3435_D0_S     0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK8B3637 register.
//
//*****************************************************************************
#define DDI_MASK8B3637_M1_M     0xFF000000  // Mask for DDI register 37
#define DDI_MASK8B3637_M1_S     24
#define DDI_MASK8B3637_D1_M     0x00FF0000  // Data for DDI register 37, -
                                            // only bits selected by mask M1
                                            // will be affected by access
#define DDI_MASK8B3637_D1_S     16
#define DDI_MASK8B3637_M0_M     0x0000FF00  // Mask for DDI register 36
#define DDI_MASK8B3637_M0_S     8
#define DDI_MASK8B3637_D0_M     0x000000FF  // Data for DDI register 36, -
                                            // only bits selected by mask M0
                                            // will be affected by access
#define DDI_MASK8B3637_D0_S     0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK8B3839 register.
//
//*****************************************************************************
#define DDI_MASK8B3839_M1_M     0xFF000000  // Mask for DDI register 39
#define DDI_MASK8B3839_M1_S     24
#define DDI_MASK8B3839_D1_M     0x00FF0000  // Data for DDI register 39, -
                                            // only bits selected by mask M1
                                            // will be affected by access
#define DDI_MASK8B3839_D1_S     16
#define DDI_MASK8B3839_M0_M     0x0000FF00  // Mask for DDI register 38
#define DDI_MASK8B3839_M0_S     8
#define DDI_MASK8B3839_D0_M     0x000000FF  // Data for DDI register 38, -
                                            // only bits selected by mask M0
                                            // will be affected by access
#define DDI_MASK8B3839_D0_S     0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK8B4041 register.
//
//*****************************************************************************
#define DDI_MASK8B4041_M1_M     0xFF000000  // Mask for DDI register 41
#define DDI_MASK8B4041_M1_S     24
#define DDI_MASK8B4041_D1_M     0x00FF0000  // Data for DDI register 41, -
                                            // only bits selected by mask M1
                                            // will be affected by access
#define DDI_MASK8B4041_D1_S     16
#define DDI_MASK8B4041_M0_M     0x0000FF00  // Mask for DDI register 40
#define DDI_MASK8B4041_M0_S     8
#define DDI_MASK8B4041_D0_M     0x000000FF  // Data for DDI register 40, -
                                            // only bits selected by mask M0
                                            // will be affected by access
#define DDI_MASK8B4041_D0_S     0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK8B4243 register.
//
//*****************************************************************************
#define DDI_MASK8B4243_M1_M     0xFF000000  // Mask for DDI register 43
#define DDI_MASK8B4243_M1_S     24
#define DDI_MASK8B4243_D1_M     0x00FF0000  // Data for DDI register 43, -
                                            // only bits selected by mask M1
                                            // will be affected by access
#define DDI_MASK8B4243_D1_S     16
#define DDI_MASK8B4243_M0_M     0x0000FF00  // Mask for DDI register 42
#define DDI_MASK8B4243_M0_S     8
#define DDI_MASK8B4243_D0_M     0x000000FF  // Data for DDI register 42, -
                                            // only bits selected by mask M0
                                            // will be affected by access
#define DDI_MASK8B4243_D0_S     0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK8B4445 register.
//
//*****************************************************************************
#define DDI_MASK8B4445_M1_M     0xFF000000  // Mask for DDI register 45
#define DDI_MASK8B4445_M1_S     24
#define DDI_MASK8B4445_D1_M     0x00FF0000  // Data for DDI register 45, -
                                            // only bits selected by mask M1
                                            // will be affected by access
#define DDI_MASK8B4445_D1_S     16
#define DDI_MASK8B4445_M0_M     0x0000FF00  // Mask for DDI register 44
#define DDI_MASK8B4445_M0_S     8
#define DDI_MASK8B4445_D0_M     0x000000FF  // Data for DDI register 44, -
                                            // only bits selected by mask M0
                                            // will be affected by access
#define DDI_MASK8B4445_D0_S     0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK8B4647 register.
//
//*****************************************************************************
#define DDI_MASK8B4647_M1_M     0xFF000000  // Mask for DDI register 47
#define DDI_MASK8B4647_M1_S     24
#define DDI_MASK8B4647_D1_M     0x00FF0000  // Data for DDI register 47, -
                                            // only bits selected by mask M1
                                            // will be affected by access
#define DDI_MASK8B4647_D1_S     16
#define DDI_MASK8B4647_M0_M     0x0000FF00  // Mask for DDI register 46
#define DDI_MASK8B4647_M0_S     8
#define DDI_MASK8B4647_D0_M     0x000000FF  // Data for DDI register 46, -
                                            // only bits selected by mask M0
                                            // will be affected by access
#define DDI_MASK8B4647_D0_S     0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK8B4849 register.
//
//*****************************************************************************
#define DDI_MASK8B4849_M1_M     0xFF000000  // Mask for DDI register 49
#define DDI_MASK8B4849_M1_S     24
#define DDI_MASK8B4849_D1_M     0x00FF0000  // Data for DDI register 49, -
                                            // only bits selected by mask M1
                                            // will be affected by access
#define DDI_MASK8B4849_D1_S     16
#define DDI_MASK8B4849_M0_M     0x0000FF00  // Mask for DDI register 48
#define DDI_MASK8B4849_M0_S     8
#define DDI_MASK8B4849_D0_M     0x000000FF  // Data for DDI register 48, -
                                            // only bits selected by mask M0
                                            // will be affected by access
#define DDI_MASK8B4849_D0_S     0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK8B5051 register.
//
//*****************************************************************************
#define DDI_MASK8B5051_M1_M     0xFF000000  // Mask for DDI register 51
#define DDI_MASK8B5051_M1_S     24
#define DDI_MASK8B5051_D1_M     0x00FF0000  // Data for DDI register 51, -
                                            // only bits selected by mask M1
                                            // will be affected by access
#define DDI_MASK8B5051_D1_S     16
#define DDI_MASK8B5051_M0_M     0x0000FF00  // Mask for DDI register 50
#define DDI_MASK8B5051_M0_S     8
#define DDI_MASK8B5051_D0_M     0x000000FF  // Data for DDI register 50, -
                                            // only bits selected by mask M0
                                            // will be affected by access
#define DDI_MASK8B5051_D0_S     0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK8B5253 register.
//
//*****************************************************************************
#define DDI_MASK8B5253_M1_M     0xFF000000  // Mask for DDI register 53
#define DDI_MASK8B5253_M1_S     24
#define DDI_MASK8B5253_D1_M     0x00FF0000  // Data for DDI register 53, -
                                            // only bits selected by mask M1
                                            // will be affected by access
#define DDI_MASK8B5253_D1_S     16
#define DDI_MASK8B5253_M0_M     0x0000FF00  // Mask for DDI register 52
#define DDI_MASK8B5253_M0_S     8
#define DDI_MASK8B5253_D0_M     0x000000FF  // Data for DDI register 52, -
                                            // only bits selected by mask M0
                                            // will be affected by access
#define DDI_MASK8B5253_D0_S     0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK8B5455 register.
//
//*****************************************************************************
#define DDI_MASK8B5455_M1_M     0xFF000000  // Mask for DDI register 55
#define DDI_MASK8B5455_M1_S     24
#define DDI_MASK8B5455_D1_M     0x00FF0000  // Data for DDI register 55, -
                                            // only bits selected by mask M1
                                            // will be affected by access
#define DDI_MASK8B5455_D1_S     16
#define DDI_MASK8B5455_M0_M     0x0000FF00  // Mask for DDI register 54
#define DDI_MASK8B5455_M0_S     8
#define DDI_MASK8B5455_D0_M     0x000000FF  // Data for DDI register 54, -
                                            // only bits selected by mask M0
                                            // will be affected by access
#define DDI_MASK8B5455_D0_S     0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK8B5657 register.
//
//*****************************************************************************
#define DDI_MASK8B5657_M1_M     0xFF000000  // Mask for DDI register 57
#define DDI_MASK8B5657_M1_S     24
#define DDI_MASK8B5657_D1_M     0x00FF0000  // Data for DDI register 57, -
                                            // only bits selected by mask M1
                                            // will be affected by access
#define DDI_MASK8B5657_D1_S     16
#define DDI_MASK8B5657_M0_M     0x0000FF00  // Mask for DDI register 56
#define DDI_MASK8B5657_M0_S     8
#define DDI_MASK8B5657_D0_M     0x000000FF  // Data for DDI register 56, -
                                            // only bits selected by mask M0
                                            // will be affected by access
#define DDI_MASK8B5657_D0_S     0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK8B5859 register.
//
//*****************************************************************************
#define DDI_MASK8B5859_M1_M     0xFF000000  // Mask for DDI register 59
#define DDI_MASK8B5859_M1_S     24
#define DDI_MASK8B5859_D1_M     0x00FF0000  // Data for DDI register 59, -
                                            // only bits selected by mask M1
                                            // will be affected by access
#define DDI_MASK8B5859_D1_S     16
#define DDI_MASK8B5859_M0_M     0x0000FF00  // Mask for DDI register 58
#define DDI_MASK8B5859_M0_S     8
#define DDI_MASK8B5859_D0_M     0x000000FF  // Data for DDI register 58, -
                                            // only bits selected by mask M0
                                            // will be affected by access
#define DDI_MASK8B5859_D0_S     0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK8B6061 register.
//
//*****************************************************************************
#define DDI_MASK8B6061_M1_M     0xFF000000  // Mask for DDI register 61
#define DDI_MASK8B6061_M1_S     24
#define DDI_MASK8B6061_D1_M     0x00FF0000  // Data for DDI register 61, -
                                            // only bits selected by mask M1
                                            // will be affected by access
#define DDI_MASK8B6061_D1_S     16
#define DDI_MASK8B6061_M0_M     0x0000FF00  // Mask for DDI register 60
#define DDI_MASK8B6061_M0_S     8
#define DDI_MASK8B6061_D0_M     0x000000FF  // Data for DDI register 60, -
                                            // only bits selected by mask M0
                                            // will be affected by access
#define DDI_MASK8B6061_D0_S     0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK8B6263 register.
//
//*****************************************************************************
#define DDI_MASK8B6263_M1_M     0xFF000000  // Mask for DDI register 63
#define DDI_MASK8B6263_M1_S     24
#define DDI_MASK8B6263_D1_M     0x00FF0000  // Data for DDI register 63, -
                                            // only bits selected by mask M1
                                            // will be affected by access
#define DDI_MASK8B6263_D1_S     16
#define DDI_MASK8B6263_M0_M     0x0000FF00  // Mask for DDI register 62
#define DDI_MASK8B6263_M0_S     8
#define DDI_MASK8B6263_D0_M     0x000000FF  // Data for DDI register 62, -
                                            // only bits selected by mask M0
                                            // will be affected by access
#define DDI_MASK8B6263_D0_S     0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK16B01 register.
//
//*****************************************************************************
#define DDI_MASK16B01_M_M       0xFFFF0000  // Mask for DDI register 0 and 1
#define DDI_MASK16B01_M_S       16
#define DDI_MASK16B01_D_M       0x0000FFFF  // Data for DDI register at
                                            // offsets 0 and 1, - only bits
                                            // selected by mask M will be
                                            // affected by access
#define DDI_MASK16B01_D_S       0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK16B23 register.
//
//*****************************************************************************
#define DDI_MASK16B23_M_M       0xFFFF0000  // Mask for DDI register 2 and 3
#define DDI_MASK16B23_M_S       16
#define DDI_MASK16B23_D_M       0x0000FFFF  // Data for DDI register at
                                            // offsets 2 and 3, - only bits
                                            // selected by mask M will be
                                            // affected by access
#define DDI_MASK16B23_D_S       0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK16B45 register.
//
//*****************************************************************************
#define DDI_MASK16B45_M_M       0xFFFF0000  // Mask for DDI register 4 and 5
#define DDI_MASK16B45_M_S       16
#define DDI_MASK16B45_D_M       0x0000FFFF  // Data for DDI register at
                                            // offsets 4 and 5, - only bits
                                            // selected by mask M will be
                                            // affected by access
#define DDI_MASK16B45_D_S       0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK16B67 register.
//
//*****************************************************************************
#define DDI_MASK16B67_M_M       0xFFFF0000  // Mask for DDI register 6 and 7
#define DDI_MASK16B67_M_S       16
#define DDI_MASK16B67_D_M       0x0000FFFF  // Data for DDI register at
                                            // offsets 6 and 7, - only bits
                                            // selected by mask M will be
                                            // affected by access
#define DDI_MASK16B67_D_S       0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK16B89 register.
//
//*****************************************************************************
#define DDI_MASK16B89_M_M       0xFFFF0000  // Mask for DDI register 8 and 9
#define DDI_MASK16B89_M_S       16
#define DDI_MASK16B89_D_M       0x0000FFFF  // Data for DDI register at
                                            // offsets 8 and 9, - only bits
                                            // selected by mask M will be
                                            // affected by access
#define DDI_MASK16B89_D_S       0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK16B1011 register.
//
//*****************************************************************************
#define DDI_MASK16B1011_M_M     0xFFFF0000  // Mask for DDI register 10 and 11
#define DDI_MASK16B1011_M_S     16
#define DDI_MASK16B1011_D_M     0x0000FFFF  // Data for DDI register at
                                            // offsets 10 and 11, - only bits
                                            // selected by mask M will be
                                            // affected by access
#define DDI_MASK16B1011_D_S     0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK16B1213 register.
//
//*****************************************************************************
#define DDI_MASK16B1213_M_M     0xFFFF0000  // Mask for DDI register 12 and 13
#define DDI_MASK16B1213_M_S     16
#define DDI_MASK16B1213_D_M     0x0000FFFF  // Data for DDI register at
                                            // offsets 12 and 13, - only bits
                                            // selected by mask M will be
                                            // affected by access
#define DDI_MASK16B1213_D_S     0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK16B1415 register.
//
//*****************************************************************************
#define DDI_MASK16B1415_M_M     0xFFFF0000  // Mask for DDI register 14 and 15
#define DDI_MASK16B1415_M_S     16
#define DDI_MASK16B1415_D_M     0x0000FFFF  // Data for DDI register at
                                            // offsets 14 and 15, - only bits
                                            // selected by mask M will be
                                            // affected by access
#define DDI_MASK16B1415_D_S     0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK16B1617 register.
//
//*****************************************************************************
#define DDI_MASK16B1617_M_M     0xFFFF0000  // Mask for DDI register 16 and 17
#define DDI_MASK16B1617_M_S     16
#define DDI_MASK16B1617_D_M     0x0000FFFF  // Data for DDI register at
                                            // offsets 16 and 17, - only bits
                                            // selected by mask M will be
                                            // affected by access
#define DDI_MASK16B1617_D_S     0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK16B1819 register.
//
//*****************************************************************************
#define DDI_MASK16B1819_M_M     0xFFFF0000  // Mask for DDI register 18 and 19
#define DDI_MASK16B1819_M_S     16
#define DDI_MASK16B1819_D_M     0x0000FFFF  // Data for DDI register at
                                            // offsets 18 and 19, - only bits
                                            // selected by mask M will be
                                            // affected by access
#define DDI_MASK16B1819_D_S     0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK16B2021 register.
//
//*****************************************************************************
#define DDI_MASK16B2021_M_M     0xFFFF0000  // Mask for DDI register 20 and 21
#define DDI_MASK16B2021_M_S     16
#define DDI_MASK16B2021_D_M     0x0000FFFF  // Data for DDI register at
                                            // offsets 20 and 21, - only bits
                                            // selected by mask M will be
                                            // affected by access
#define DDI_MASK16B2021_D_S     0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK16B2223 register.
//
//*****************************************************************************
#define DDI_MASK16B2223_M_M     0xFFFF0000  // Mask for DDI register 22 and 23
#define DDI_MASK16B2223_M_S     16
#define DDI_MASK16B2223_D_M     0x0000FFFF  // Data for DDI register at
                                            // offsets 22 and 23, - only bits
                                            // selected by mask M will be
                                            // affected by access
#define DDI_MASK16B2223_D_S     0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK16B2425 register.
//
//*****************************************************************************
#define DDI_MASK16B2425_M_M     0xFFFF0000  // Mask for DDI register 24 and 25
#define DDI_MASK16B2425_M_S     16
#define DDI_MASK16B2425_D_M     0x0000FFFF  // Data for DDI register at
                                            // offsets 24 and 25, - only bits
                                            // selected by mask M will be
                                            // affected by access
#define DDI_MASK16B2425_D_S     0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK16B2627 register.
//
//*****************************************************************************
#define DDI_MASK16B2627_M_M     0xFFFF0000  // Mask for DDI register 26 and 27
#define DDI_MASK16B2627_M_S     16
#define DDI_MASK16B2627_D_M     0x0000FFFF  // Data for DDI register at
                                            // offsets 26 and 27, - only bits
                                            // selected by mask M will be
                                            // affected by access
#define DDI_MASK16B2627_D_S     0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK16B2829 register.
//
//*****************************************************************************
#define DDI_MASK16B2829_M_M     0xFFFF0000  // Mask for DDI register 28 and 29
#define DDI_MASK16B2829_M_S     16
#define DDI_MASK16B2829_D_M     0x0000FFFF  // Data for DDI register at
                                            // offsets 28 and 29, - only bits
                                            // selected by mask M will be
                                            // affected by access
#define DDI_MASK16B2829_D_S     0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK16B3031 register.
//
//*****************************************************************************
#define DDI_MASK16B3031_M_M     0xFFFF0000  // Mask for DDI register 30 and 31
#define DDI_MASK16B3031_M_S     16
#define DDI_MASK16B3031_D_M     0x0000FFFF  // Data for DDI register at
                                            // offsets 30 and 31, - only bits
                                            // selected by mask M will be
                                            // affected by access
#define DDI_MASK16B3031_D_S     0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK16B3233 register.
//
//*****************************************************************************
#define DDI_MASK16B3233_M_M     0xFFFF0000  // Mask for DDI register 32 and 33
#define DDI_MASK16B3233_M_S     16
#define DDI_MASK16B3233_D_M     0x0000FFFF  // Data for DDI register at
                                            // offsets 32 and 33, - only bits
                                            // selected by mask M will be
                                            // affected by access
#define DDI_MASK16B3233_D_S     0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK16B3435 register.
//
//*****************************************************************************
#define DDI_MASK16B3435_M_M     0xFFFF0000  // Mask for DDI register 34 and 35
#define DDI_MASK16B3435_M_S     16
#define DDI_MASK16B3435_D_M     0x0000FFFF  // Data for DDI register at
                                            // offsets 34 and 35, - only bits
                                            // selected by mask M will be
                                            // affected by access
#define DDI_MASK16B3435_D_S     0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK16B3637 register.
//
//*****************************************************************************
#define DDI_MASK16B3637_M_M     0xFFFF0000  // Mask for DDI register 36 and 37
#define DDI_MASK16B3637_M_S     16
#define DDI_MASK16B3637_D_M     0x0000FFFF  // Data for DDI register at
                                            // offsets 36 and 37, - only bits
                                            // selected by mask M will be
                                            // affected by access
#define DDI_MASK16B3637_D_S     0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK16B3839 register.
//
//*****************************************************************************
#define DDI_MASK16B3839_M_M     0xFFFF0000  // Mask for DDI register 38 and 39
#define DDI_MASK16B3839_M_S     16
#define DDI_MASK16B3839_D_M     0x0000FFFF  // Data for DDI register at
                                            // offsets 38 and 39, - only bits
                                            // selected by mask M will be
                                            // affected by access
#define DDI_MASK16B3839_D_S     0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK16B4041 register.
//
//*****************************************************************************
#define DDI_MASK16B4041_M_M     0xFFFF0000  // Mask for DDI register 40 and 41
#define DDI_MASK16B4041_M_S     16
#define DDI_MASK16B4041_D_M     0x0000FFFF  // Data for DDI register at
                                            // offsets 40 and 41, - only bits
                                            // selected by mask M will be
                                            // affected by access
#define DDI_MASK16B4041_D_S     0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK16B4243 register.
//
//*****************************************************************************
#define DDI_MASK16B4243_M_M     0xFFFF0000  // Mask for DDI register 42 and 43
#define DDI_MASK16B4243_M_S     16
#define DDI_MASK16B4243_D_M     0x0000FFFF  // Data for DDI register at
                                            // offsets 42 and 43, - only bits
                                            // selected by mask M will be
                                            // affected by access
#define DDI_MASK16B4243_D_S     0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK16B4445 register.
//
//*****************************************************************************
#define DDI_MASK16B4445_M_M     0xFFFF0000  // Mask for DDI register 44 and 45
#define DDI_MASK16B4445_M_S     16
#define DDI_MASK16B4445_D_M     0x0000FFFF  // Data for DDI register at
                                            // offsets 44 and 45, - only bits
                                            // selected by mask M will be
                                            // affected by access
#define DDI_MASK16B4445_D_S     0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK16B4647 register.
//
//*****************************************************************************
#define DDI_MASK16B4647_M_M     0xFFFF0000  // Mask for DDI register 46 and 47
#define DDI_MASK16B4647_M_S     16
#define DDI_MASK16B4647_D_M     0x0000FFFF  // Data for DDI register at
                                            // offsets 46 and 47, - only bits
                                            // selected by mask M will be
                                            // affected by access
#define DDI_MASK16B4647_D_S     0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK16B4849 register.
//
//*****************************************************************************
#define DDI_MASK16B4849_M_M     0xFFFF0000  // Mask for DDI register 48 and 49
#define DDI_MASK16B4849_M_S     16
#define DDI_MASK16B4849_D_M     0x0000FFFF  // Data for DDI register at
                                            // offsets 48 and 49, - only bits
                                            // selected by mask M will be
                                            // affected by access
#define DDI_MASK16B4849_D_S     0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK16B5051 register.
//
//*****************************************************************************
#define DDI_MASK16B5051_M_M     0xFFFF0000  // Mask for DDI register 50 and 51
#define DDI_MASK16B5051_M_S     16
#define DDI_MASK16B5051_D_M     0x0000FFFF  // Data for DDI register at
                                            // offsets 50 and 51, - only bits
                                            // selected by mask M will be
                                            // affected by access
#define DDI_MASK16B5051_D_S     0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK16B5253 register.
//
//*****************************************************************************
#define DDI_MASK16B5253_M_M     0xFFFF0000  // Mask for DDI register 52 and 53
#define DDI_MASK16B5253_M_S     16
#define DDI_MASK16B5253_D_M     0x0000FFFF  // Data for DDI register at
                                            // offsets 52 and 53, - only bits
                                            // selected by mask M will be
                                            // affected by access
#define DDI_MASK16B5253_D_S     0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK16B5455 register.
//
//*****************************************************************************
#define DDI_MASK16B5455_M_M     0xFFFF0000  // Mask for DDI register 54 and 55
#define DDI_MASK16B5455_M_S     16
#define DDI_MASK16B5455_D_M     0x0000FFFF  // Data for DDI register at
                                            // offsets 54 and 55, - only bits
                                            // selected by mask M will be
                                            // affected by access
#define DDI_MASK16B5455_D_S     0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK16B5657 register.
//
//*****************************************************************************
#define DDI_MASK16B5657_M_M     0xFFFF0000  // Mask for DDI register 56 and 57
#define DDI_MASK16B5657_M_S     16
#define DDI_MASK16B5657_D_M     0x0000FFFF  // Data for DDI register at
                                            // offsets 56 and 57, - only bits
                                            // selected by mask M will be
                                            // affected by access
#define DDI_MASK16B5657_D_S     0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK16B5859 register.
//
//*****************************************************************************
#define DDI_MASK16B5859_M_M     0xFFFF0000  // Mask for DDI register 58 and 59
#define DDI_MASK16B5859_M_S     16
#define DDI_MASK16B5859_D_M     0x0000FFFF  // Data for DDI register at
                                            // offsets 58 and 59, - only bits
                                            // selected by mask M will be
                                            // affected by access
#define DDI_MASK16B5859_D_S     0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK16B6061 register.
//
//*****************************************************************************
#define DDI_MASK16B6061_M_M     0xFFFF0000  // Mask for DDI register 60 and 61
#define DDI_MASK16B6061_M_S     16
#define DDI_MASK16B6061_D_M     0x0000FFFF  // Data for DDI register at
                                            // offsets 60 and 61, - only bits
                                            // selected by mask M will be
                                            // affected by access
#define DDI_MASK16B6061_D_S     0
//*****************************************************************************
//
// The following are defines for the bit fields in the
// DDI_O_MASK16B6263 register.
//
//*****************************************************************************
#define DDI_MASK16B6263_M_M     0xFFFF0000  // Mask for DDI register 62 and 63
#define DDI_MASK16B6263_M_S     16
#define DDI_MASK16B6263_D_M     0x0000FFFF  // Data for DDI register at
                                            // offsets 62 and 63, - only bits
                                            // selected by mask M will be
                                            // affected by access
#define DDI_MASK16B6263_D_S     0

#endif // __HW_DDI_H__
