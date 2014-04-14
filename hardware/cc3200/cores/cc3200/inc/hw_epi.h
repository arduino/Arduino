//*****************************************************************************
//
//  Copyright (C) 2013 Texas Instruments Incorporated
//
//  All rights reserved. Property of Texas Instruments Incorporated.
//  Restricted rights to use, duplicate or disclose this code are
//  granted through contract.
//
//  The program may not be used without the written permission of
//  Texas Instruments Incorporated or against the terms and conditions
//  stipulated in the agreement under which this program has been supplied,
//  and under no circumstances can it be used with non-TI connectivity device.
//
//*****************************************************************************

#ifndef __HW_EPI_H__
#define __HW_EPI_H__

//*****************************************************************************
//
// The following are defines for the EPI register offsets.
//
//*****************************************************************************
#define EPI_O_CFG               0x00000000  
#define EPI_O_BAUD              0x00000004  
#define EPI_O_BAUD2             0x00000008  
#define EPI_O_GPCFG             0x00000010  
#define EPI_O_GPCFG2            0x00000014  
#define EPI_O_ADDRMAP           0x0000001C  
#define EPI_O_RSIZE0            0x00000020  
#define EPI_O_RADDR0            0x00000024  
#define EPI_O_RPSTD0            0x00000028  
#define EPI_O_RSIZE1            0x00000030  
#define EPI_O_RADDR1            0x00000034  
#define EPI_O_RPSTD1            0x00000038  
#define EPI_O_STAT              0x00000060  
#define EPI_O_RFIFOCNT          0x0000006C  
#define EPI_O_READFIFO          0x00000070  
#define EPI_O_READFIFO1         0x00000074  
#define EPI_O_READFIFO2         0x00000078  
#define EPI_O_READFIFO3         0x0000007C  
#define EPI_O_READFIFO4         0x00000080  
#define EPI_O_READFIFO5         0x00000084  
#define EPI_O_READFIFO6         0x00000088  
#define EPI_O_READFIFO7         0x0000008C  
#define EPI_O_FIFOLVL           0x00000200  
#define EPI_O_WFIFOCNT          0x00000204  
#define EPI_O_IM                0x00000210  
#define EPI_O_RIS               0x00000214  
#define EPI_O_MIS               0x00000218  
#define EPI_O_EISC              0x0000021C  
#define EPI_O_HB16CFG3          0x00000308  
#define EPI_O_HB16CFG4          0x0000030C  
#define EPI_O_HB16TIME          0x00000310  
#define EPI_O_HB16TIME2         0x00000314  
#define EPI_O_HB16TIME3         0x00000318  
#define EPI_O_HB16TIME4         0x0000031C  
#define EPI_O_HBPSRAM           0x00000360  



//******************************************************************************
//
// The following are defines for the bit fields in the EPI_O_CFG register.
//
//******************************************************************************
#define EPI_CFG_INTDIV          0x00000100  // Integer Clock Divider Enable 
#define EPI_CFG_BLKEN           0x00000010  // Block Enable 
#define EPI_CFG_MODE_M        0x0000000F  // Mode Select 0x00000003 : 
                                            // EPI_CFG_MODE_HB16 : 16-Bit 
                                            // Host-Bus (HB16) 0x00000002 : 
                                            // EPI_CFG_MODE_HB8 : 8-Bit Host-Bus 
                                            // (HB8) 0x00000000 : 
                                            // EPI_CFG_MODE_NONE : General 
                                            // Purpose 0x00000001 : 
                                            // EPI_CFG_MODE_SDRAM : SDRAM 
#define EPI_CFG_MODE_S        0 
//******************************************************************************
//
// The following are defines for the bit fields in the EPI_O_BAUD register.
//
//******************************************************************************
#define EPI_BAUD_COUNT1_M     0xFFFF0000  // Baud Rate Counter 1 
#define EPI_BAUD_COUNT1_S     16 
#define EPI_BAUD_COUNT0_M     0x0000FFFF  // Baud Rate Counter 0 
#define EPI_BAUD_COUNT0_S     0 
//******************************************************************************
//
// The following are defines for the bit fields in the EPI_O_BAUD2 register.
//
//******************************************************************************
#define EPI_BAUD2_COUNT1_M    0xFFFF0000  // CS3n Baud Rate Counter 1 
#define EPI_BAUD2_COUNT1_S    16 
#define EPI_BAUD2_COUNT0_M    0x0000FFFF  // CS2n Baud Rate Counter 0 
#define EPI_BAUD2_COUNT0_S    0 
//******************************************************************************
//
// The following are defines for the bit fields in the EPI_O_GPCFG register.
//
//******************************************************************************
#define EPI_GPCFG_CLKPIN        0x80000000  // Clock Pin 
#define EPI_GPCFG_CLKGATE       0x40000000  // Clock Gated 
#define EPI_GPCFG_RDYEN         0x10000000  // Ready Enable 
#define EPI_GPCFG_FRMPIN        0x08000000  // Framing Pin 
#define EPI_GPCFG_FRM50         0x04000000  // 50/50 Frame 
#define EPI_GPCFG_FRMCNT_M    0x03C00000  // Frame Count 
#define EPI_GPCFG_FRMCNT_S    22 
#define EPI_GPCFG_RW            0x00200000  // Read and Write 
#define EPI_GPCFG_WR2CYC        0x00080000  // 2-Cycle Writes 
#define EPI_GPCFG_RD2CYC        0x00040000  // 2-Cycle Reads 
#define EPI_GPCFG_MAXWAIT_M   0x0000FF00  // Maximum Wait 
#define EPI_GPCFG_MAXWAIT_S   8 
#define EPI_GPCFG_ASIZE_M     0x00000030  // Address Bus Size 0x00000020 : 
                                            // EPI_GPCFG_ASIZE_12BIT : Up to 12 
                                            // bits wide. This size cannot be 
                                            // used with 24-bit data 0x00000030 
                                            // : EPI_GPCFG_ASIZE_20BIT : Up to 
                                            // 20 bits wide. This size cannot be 
                                            // used with data sizes other than 8 
                                            // 0x00000010 : EPI_GPCFG_ASIZE_4BIT 
                                            // : Up to 4 bits wide 0x00000000 : 
                                            // EPI_GPCFG_ASIZE_NONE : No address 
#define EPI_GPCFG_ASIZE_S     4 
#define EPI_GPCFG_DSIZE_M     0x00000003  // Size of Data Bus 0x00000001 : 
                                            // EPI_GPCFG_DSIZE_16BIT : 16 Bits 
                                            // Wide (EPI0S0 to EPI0S15) 
                                            // 0x00000002 : 
                                            // EPI_GPCFG_DSIZE_24BIT : 24 Bits 
                                            // Wide (EPI0S0 to EPI0S23) 
                                            // 0x00000003 : 
                                            // EPI_GPCFG_DSIZE_32BIT : 32 Bits 
                                            // Wide (EPI0S0 to EPI0S31) 
                                            // 0x00000000 : EPI_GPCFG_DSIZE_4BIT 
                                            // : 8 Bits Wide (EPI0S0 to EPI0S7) 
#define EPI_GPCFG_DSIZE_S     0 
//******************************************************************************
//
// The following are defines for the bit fields in the EPI_O_GPCFG2 register.
//
//******************************************************************************
#define EPI_GPCFG2_WORD         0x80000000  // Word Access Mode 
//******************************************************************************
//
// The following are defines for the bit fields in the EPI_O_ADDRMAP register.
//
//******************************************************************************
#define EPI_ADDRMAP_ECSZ_M    0x00000C00  // External Code Size 0x00000000 : 
                                            // EPI_ADDRMAP_ECSZ__0 : 256 bytes; 
                                            // lower address range: 0x00 to 0xFF 
                                            // 0x00000400 : EPI_ADDRMAP_ECSZ__1 
                                            // : 64 KB; lower address range: 
                                            // 0x0000 to 0xFFFF 0x00000800 : 
                                            // EPI_ADDRMAP_ECSZ__2 : 16 MB; 
                                            // lower address range: 0x00.0000 to 
                                            // 0xFF.FFFF 0x00000C00 : 
                                            // EPI_ADDRMAP_ECSZ__3 : 256MB; 
                                            // lower address range: 0x000.0000 
                                            // to 0x0FFF.FFFF 
#define EPI_ADDRMAP_ECSZ_S    10 
#define EPI_ADDRMAP_ECADR_M   0x00000300  // External Code Address 0x00000000 
                                            // : EPI_ADDRMAP_ECADR__0 : Not 
                                            // mapped 0x00000100 : 
                                            // EPI_ADDRMAP_ECADR__1 : At 
                                            // 0x1000.0000 
#define EPI_ADDRMAP_ECADR_S   8 
#define EPI_ADDRMAP_EPSZ_M    0x000000C0  // External Peripheral Size 
                                            // 0x00000080 : 
                                            // EPI_ADDRMAP_EPSZ_16MB : 16 MB; 
                                            // lower address range: 0x00.0000 to 
                                            // 0xFF.FFFF 0x00000000 : 
                                            // EPI_ADDRMAP_EPSZ_256B : 256 
                                            // bytes; lower address range: 0x00 
                                            // to 0xFF 0x000000C0 : 
                                            // EPI_ADDRMAP_EPSZ_512MB : 512 MB; 
                                            // lower address range: 0x000.0000 
                                            // to 0x1FFF.FFFF 0x00000040 : 
                                            // EPI_ADDRMAP_EPSZ_64KB : 64 KB; 
                                            // lower address range: 0x0000 to 
                                            // 0xFFFF 
#define EPI_ADDRMAP_EPSZ_S    6 
#define EPI_ADDRMAP_EPADR_M   0x00000030  // External Peripheral Address 
                                            // 0x00000010 : 
                                            // EPI_ADDRMAP_EPADR_A000 : At 
                                            // 0xA000.0000 0x00000020 : 
                                            // EPI_ADDRMAP_EPADR_C000 : At 
                                            // 0xC000.0000 0x00000000 : 
                                            // EPI_ADDRMAP_EPADR_NONE : Not 
                                            // mapped 0x00000030 : 
                                            // EPI_ADDRMAP_EPADR__3 : Only to be 
                                            // used with Host Bus quad chip 
                                            // select. In quad chip select 
                                            // mode@@ CS2n maps to 0xA000.0000 
                                            // and CS3n maps to 0xC000.0000 
#define EPI_ADDRMAP_EPADR_S   4 
#define EPI_ADDRMAP_ERSZ_M    0x0000000C  // External RAM Size 0x00000008 : 
                                            // EPI_ADDRMAP_ERSZ_16MB : 16 MB; 
                                            // lower address range: 0x00.0000 to 
                                            // 0xFF.FFFF 0x00000000 : 
                                            // EPI_ADDRMAP_ERSZ_256B : 256 
                                            // bytes; lower address range: 0x00 
                                            // to 0xFF 0x0000000C : 
                                            // EPI_ADDRMAP_ERSZ_512MB : 512 MB; 
                                            // lower address range: 0x000.0000 
                                            // to 0x1FFF.FFFF 0x00000004 : 
                                            // EPI_ADDRMAP_ERSZ_64KB : 64 KB; 
                                            // lower address range: 0x0000 to 
                                            // 0xFFFF 
#define EPI_ADDRMAP_ERSZ_S    2 
#define EPI_ADDRMAP_ERADR_M   0x00000003  // External RAM Address 0x00000001 
                                            // : EPI_ADDRMAP_ERADR_6000 : At 
                                            // 0x6000.0000 0x00000002 : 
                                            // EPI_ADDRMAP_ERADR_8000 : At 
                                            // 0x8000.0000 0x00000000 : 
                                            // EPI_ADDRMAP_ERADR_NONE : Not 
                                            // mapped 0x00000003 : 
                                            // EPI_ADDRMAP_ERADR__3 : Only to be 
                                            // used with Host Bus quad chip 
                                            // select. In quad chip select 
                                            // mode@@ CS0n maps to 0x6000.0000 
                                            // and CS1n maps to 0x8000.0000 
#define EPI_ADDRMAP_ERADR_S   0 
//******************************************************************************
//
// The following are defines for the bit fields in the EPI_O_RSIZE0 register.
//
//******************************************************************************
#define EPI_RSIZE0_SIZE_M     0x00000003  // Current Size 0x00000002 : 
                                            // EPI_RSIZE0_SIZE_16BIT : Half-word 
                                            // (16 bits) 0x00000003 : 
                                            // EPI_RSIZE0_SIZE_32BIT : Word (32 
                                            // bits) 0x00000001 : 
                                            // EPI_RSIZE0_SIZE_8BIT : Byte (8 
                                            // bits) 
#define EPI_RSIZE0_SIZE_S     0 
//******************************************************************************
//
// The following are defines for the bit fields in the EPI_O_RADDR0 register.
//
//******************************************************************************
#define EPI_RADDR0_ADDR_M     0x1FFFFFFF  // Current Address 
#define EPI_RADDR0_ADDR_S     0 
//******************************************************************************
//
// The following are defines for the bit fields in the EPI_O_RPSTD0 register.
//
//******************************************************************************
#define EPI_RPSTD0_POSTCNT_M  0x00001FFF  // Post Count 
#define EPI_RPSTD0_POSTCNT_S  0 
//******************************************************************************
//
// The following are defines for the bit fields in the EPI_O_RSIZE1 register.
//
//******************************************************************************
#define EPI_RSIZE1_SIZE_M     0x00000003  // Current Size 0x00000002 : 
                                            // EPI_RSIZE1_SIZE_16BIT : Half-word 
                                            // (16 bits) 0x00000003 : 
                                            // EPI_RSIZE1_SIZE_32BIT : Word (32 
                                            // bits) 0x00000001 : 
                                            // EPI_RSIZE1_SIZE_8BIT : Byte (8 
                                            // bits) 
#define EPI_RSIZE1_SIZE_S     0 
//******************************************************************************
//
// The following are defines for the bit fields in the EPI_O_RADDR1 register.
//
//******************************************************************************
#define EPI_RADDR1_ADDR_M     0x1FFFFFFF  // Current Address 
#define EPI_RADDR1_ADDR_S     0 
//******************************************************************************
//
// The following are defines for the bit fields in the EPI_O_RPSTD1 register.
//
//******************************************************************************
#define EPI_RPSTD1_POSTCNT_M  0x00001FFF  // Post Count 
#define EPI_RPSTD1_POSTCNT_S  0 
//******************************************************************************
//
// The following are defines for the bit fields in the EPI_O_STAT register.
//
//******************************************************************************
#define EPI_STAT_CELOW          0x00000200  // Clock Enable Low 
#define EPI_STAT_XFFULL         0x00000100  // External FIFO Full 
#define EPI_STAT_XFEMPTY        0x00000080  // External FIFO Empty 
#define EPI_STAT_INITSEQ        0x00000040  // Initialization Sequence 
#define EPI_STAT_WBUSY          0x00000020  // Write Busy 
#define EPI_STAT_NBRBUSY        0x00000010  // Non-Blocking Read Busy 
#define EPI_STAT_ACTIVE         0x00000001  // Register Active 
//******************************************************************************
//
// The following are defines for the bit fields in the EPI_O_RFIFOCNT register.
//
//******************************************************************************
#define EPI_RFIFOCNT_COUNT_M  0x0000000F  // FIFO Count 
#define EPI_RFIFOCNT_COUNT_S  0 
//******************************************************************************
//
// The following are defines for the bit fields in the EPI_O_READFIFO register.
//
//******************************************************************************
#define EPI_READFIFO_DATA_M   0xFFFFFFFF  // Reads Data 
#define EPI_READFIFO_DATA_S   0 
//******************************************************************************
//
// The following are defines for the bit fields in the EPI_O_READFIFO1 register.
//
//******************************************************************************
#define EPI_READFIFO1_DATA_M  0xFFFFFFFF  // Reads Data 
#define EPI_READFIFO1_DATA_S  0 
//******************************************************************************
//
// The following are defines for the bit fields in the EPI_O_READFIFO2 register.
//
//******************************************************************************
#define EPI_READFIFO2_DATA_M  0xFFFFFFFF  // Reads Data 
#define EPI_READFIFO2_DATA_S  0 
//******************************************************************************
//
// The following are defines for the bit fields in the EPI_O_READFIFO3 register.
//
//******************************************************************************
#define EPI_READFIFO3_DATA_M  0xFFFFFFFF  // Reads Data 
#define EPI_READFIFO3_DATA_S  0 
//******************************************************************************
//
// The following are defines for the bit fields in the EPI_O_READFIFO4 register.
//
//******************************************************************************
#define EPI_READFIFO4_DATA_M  0xFFFFFFFF  // Reads Data 
#define EPI_READFIFO4_DATA_S  0 
//******************************************************************************
//
// The following are defines for the bit fields in the EPI_O_READFIFO5 register.
//
//******************************************************************************
#define EPI_READFIFO5_DATA_M  0xFFFFFFFF  // Reads Data 
#define EPI_READFIFO5_DATA_S  0 
//******************************************************************************
//
// The following are defines for the bit fields in the EPI_O_READFIFO6 register.
//
//******************************************************************************
#define EPI_READFIFO6_DATA_M  0xFFFFFFFF  // Reads Data 
#define EPI_READFIFO6_DATA_S  0 
//******************************************************************************
//
// The following are defines for the bit fields in the EPI_O_READFIFO7 register.
//
//******************************************************************************
#define EPI_READFIFO7_DATA_M  0xFFFFFFFF  // Reads Data 
#define EPI_READFIFO7_DATA_S  0 
//******************************************************************************
//
// The following are defines for the bit fields in the EPI_O_FIFOLVL register.
//
//******************************************************************************
#define EPI_FIFOLVL_WFERR       0x00020000  // Write Full Error 
#define EPI_FIFOLVL_RSERR       0x00010000  // Read Stall Error 
#define EPI_FIFOLVL_WRFIFO_M  0x00000070  // Write FIFO 0x00000030 : 
                                            // EPI_FIFOLVL_WRFIFO_1_2 : Trigger 
                                            // when there are up to 2 spaces 
                                            // available in the WFIFO 0x00000020 
                                            // : EPI_FIFOLVL_WRFIFO_1_4 : 
                                            // Trigger when there are up to 3 
                                            // spaces available in the WFIFO 
                                            // 0x00000040 : 
                                            // EPI_FIFOLVL_WRFIFO_3_4 : Trigger 
                                            // when there is 1 space available 
                                            // in the WFIFO 0x00000000 : 
                                            // EPI_FIFOLVL_WRFIFO_EMPT : Trigger 
                                            // when there are any spaces 
                                            // available in the WFIFO 
#define EPI_FIFOLVL_WRFIFO_S  4 
#define EPI_FIFOLVL_RDFIFO_M  0x00000007  // Read FIFO 0x00000003 : 
                                            // EPI_FIFOLVL_RDFIFO_1_2 : Trigger 
                                            // when there are 4 or more entries 
                                            // in the NBRFIFO 0x00000002 : 
                                            // EPI_FIFOLVL_RDFIFO_1_4 : Trigger 
                                            // when there are 2 or more entries 
                                            // in the NBRFIFO 0x00000001 : 
                                            // EPI_FIFOLVL_RDFIFO_1_8 : Trigger 
                                            // when there are 1 or more entries 
                                            // in the NBRFIFO 0x00000004 : 
                                            // EPI_FIFOLVL_RDFIFO_3_4 : Trigger 
                                            // when there are 6 or more entries 
                                            // in the NBRFIFO 0x00000005 : 
                                            // EPI_FIFOLVL_RDFIFO_7_8 : Trigger 
                                            // when there are 7 or more entries 
                                            // in the NBRFIFO 0x00000005 : 
                                            // EPI_FIFOLVL_RDFIFO_EMPT : Empty 
                                            // 0x00000006 : 
                                            // EPI_FIFOLVL_RDFIFO_FULL : Trigger 
                                            // when there are 8 entries in the 
                                            // NBRFIFO 
#define EPI_FIFOLVL_RDFIFO_S  0 
//******************************************************************************
//
// The following are defines for the bit fields in the EPI_O_WFIFOCNT register.
//
//******************************************************************************
#define EPI_WFIFOCNT_WTAV_M   0x00000007  // Available Write Transactions 
#define EPI_WFIFOCNT_WTAV_S   0 
//******************************************************************************
//
// The following are defines for the bit fields in the EPI_O_IM register.
//
//******************************************************************************
#define EPI_IM_DMAWRIM          0x00000010  // Write uDMA Interrupt Mask 
#define EPI_IM_DMARDIM          0x00000008  // Read uDMA Interrupt Mask 
#define EPI_IM_WRIM             0x00000004  // Write FIFO Empty Interrupt Mask 
#define EPI_IM_RDIM             0x00000002  // Read FIFO Full Interrupt Mask 
#define EPI_IM_ERRIM            0x00000001  // Error Interrupt Mask 
//******************************************************************************
//
// The following are defines for the bit fields in the EPI_O_RIS register.
//
//******************************************************************************
#define EPI_RIS_DMAWRRIS        0x00000010  // Write uDMA Raw Interrupt Status 
#define EPI_RIS_DMARDRIS        0x00000008  // Read uDMA Raw Interrupt Status 
#define EPI_RIS_WRRIS           0x00000004  // Write Raw Interrupt Status 
#define EPI_RIS_RDRIS           0x00000002  // Read Raw Interrupt Status 
#define EPI_RIS_ERRRIS          0x00000001  // Error Raw Interrupt Status 
//******************************************************************************
//
// The following are defines for the bit fields in the EPI_O_MIS register.
//
//******************************************************************************
#define EPI_MIS_DMAWRMIS        0x00000010  // Write uDMA Masked Interrupt 
                                            // Status 
#define EPI_MIS_DMARDMIS        0x00000008  // Read uDMA Masked Interrupt 
                                            // Status 
#define EPI_MIS_WRMIS           0x00000004  // Write Masked Interrupt Status 
#define EPI_MIS_RDMIS           0x00000002  // Read Masked Interrupt Status 
#define EPI_MIS_ERRMIS          0x00000001  // Error Masked Interrupt Status 
//******************************************************************************
//
// The following are defines for the bit fields in the EPI_O_EISC register.
//
//******************************************************************************
#define EPI_EISC_DMAWRIC        0x00000010  // Write uDMA Interrupt Clear 
#define EPI_EISC_DMARDIC        0x00000008  // Read uDMA Interrupt Clear 
#define EPI_EISC_WTFULL         0x00000004  // Write FIFO Full Error 
#define EPI_EISC_RSTALL         0x00000002  // Read Stalled Error 
#define EPI_EISC_TOUT           0x00000001  // Timeout Error 
//******************************************************************************
//
// The following are defines for the bit fields in the EPI_O_HB16CFG3 register.
//
//******************************************************************************
#define EPI_HB16CFG3_WRHIGH     0x00200000  // CS2n WRITE Strobe Polarity 
#define EPI_HB16CFG3_RDHIGH     0x00100000  // CS2n READ Strobe Polarity 
#define EPI_HB16CFG3_ALEHIGH    0x00080000  // CS2n ALE Strobe Polarity 
#define EPI_HB16CFG3_WRCRE      0x00040000  // CS2n PSRAM Configuration 
                                            // Register Write 
#define EPI_HB16CFG3_RDCRE      0x00020000  // CS2n PSRAM Configuration 
                                            // Register Read 
#define EPI_HB16CFG3_BURST      0x00010000  // CS2n Burst Mode 
#define EPI_HB16CFG3_WRWS_M   0x000000C0  // CS2n Write Wait States 
                                            // 0x00000000 : EPI_HB16CFG3_WRWS__0 
                                            // : Active WRn is 2 EPI clocks 
                                            // 0x00000040 : EPI_HB16CFG3_WRWS__1 
                                            // : Active WRn is 4 EPI clocks 
                                            // 0x00000080 : EPI_HB16CFG3_WRWS__2 
                                            // : Active WRn is 6 EPI clocks 
                                            // 0x000000C0 : EPI_HB16CFG3_WRWS__3 
                                            // : Active WRn is 8 EPI clocks 
#define EPI_HB16CFG3_WRWS_S   6 
#define EPI_HB16CFG3_HPI        0x00000008  // Host Port Interface Enable 
#define EPI_HB16CFG3_MODE_M   0x00000003  // CS2n Host Bus Sub-Mode 
                                            // 0x00000000 : EPI_HB16CFG3_MODE__0 
                                            // : ADMUX - AD[15:0] 0x00000001 : 
                                            // EPI_HB16CFG3_MODE__1 : ADNONMUX - 
                                            // D[15:0] 0x00000002 : 
                                            // EPI_HB16CFG3_MODE__2 : Continuous 
                                            // Read - D[15:0] 
#define EPI_HB16CFG3_MODE_S   0 
//******************************************************************************
//
// The following are defines for the bit fields in the EPI_O_HB16CFG4 register.
//
//******************************************************************************
#define EPI_HB16CFG4_WRHIGH     0x00200000  // CS3n WRITE Strobe Polarity 
#define EPI_HB16CFG4_RDHIGH     0x00100000  // CS3n READ Strobe Polarity 
#define EPI_HB16CFG4_ALEHIGH    0x00080000  // CS3n ALE Strobe Polarity 
#define EPI_HB16CFG4_WRCRE      0x00040000  // CS3n PSRAM Configuration 
                                            // Register Write 
#define EPI_HB16CFG4_RDCRE      0x00020000  // CS3n PSRAM Configuration 
                                            // Register Read 
#define EPI_HB16CFG4_BURST      0x00010000  // CS3n Burst Mode 
#define EPI_HB16CFG4_WRWS_M   0x000000C0  // CS3n Write Wait States 
                                            // 0x00000000 : EPI_HB16CFG4_WRWS__0 
                                            // : Active WRn is 2 EPI clocks 
                                            // 0x00000040 : EPI_HB16CFG4_WRWS__1 
                                            // : Active WRn is 4 EPI clocks 
                                            // 0x00000080 : EPI_HB16CFG4_WRWS__2 
                                            // : Active WRn is 6 EPI clocks 
                                            // 0x000000C0 : EPI_HB16CFG4_WRWS__3 
                                            // : Active WRn is 8 EPI clocks 
#define EPI_HB16CFG4_WRWS_S   6 
#define EPI_HB16CFG4_HPI        0x00000008  // Host Port Interface Enable 
#define EPI_HB16CFG4_MODE_M   0x00000003  // CS3n Host Bus Sub-Mode 
                                            // 0x00000000 : EPI_HB16CFG4_MODE__0 
                                            // : ADMUX - AD[15:0] 0x00000001 : 
                                            // EPI_HB16CFG4_MODE__1 : ADNONMUX - 
                                            // D[15:0] 0x00000002 : 
                                            // EPI_HB16CFG4_MODE__2 : Continuous 
                                            // Read - D[15:0] 
#define EPI_HB16CFG4_MODE_S   0 
//******************************************************************************
//
// The following are defines for the bit fields in the EPI_O_HB16TIME register.
//
//******************************************************************************
#define EPI_HB16TIME_IRDYDLY_M \
                                0x03000000  // CS0n Input Ready Delay 
                                            // 0x00000000 : 
                                            // EPI_HB16TIME_IRDYDLY__0 : Stall 
                                            // is immediate of data present on 
                                            // EPIO at time of iRDY low being 
                                            // sampled on rising edge of EPIO 
                                            // clock 0x01000000 : 
                                            // EPI_HB16TIME_IRDYDLY__1 : Stall 
                                            // begins one EPI clocks past iRDY 
                                            // low being sampled on the rising 
                                            // edge of EPIO clock 0x02000000 : 
                                            // EPI_HB16TIME_IRDYDLY__2 : Stall 
                                            // begins two EPI clocks past iRDY 
                                            // low being sampled on the rising 
                                            // edge of EPIO clock 0x03000000 : 
                                            // EPI_HB16TIME_IRDYDLY__3 : Stall 
                                            // begins three EPI clocks past iRDY 
                                            // low being sampled on the rising 
                                            // edge of EPIO clock 

#define EPI_HB16TIME_IRDYDLY_S 24 
#define EPI_HB16TIME_PSRAMSZ_M \
                                0x00070000  // PSRAM Row Size 0x00000000 : 
                                            // EPI_HB16TIME_PSRAMSZ__0 : No 
                                            // PSRAM 0x00010000 : 
                                            // EPI_HB16TIME_PSRAMSZ__1 : 128 B 
                                            // 0x00020000 : 
                                            // EPI_HB16TIME_PSRAMSZ__2 : 256 B 
                                            // 0x00030000 : 
                                            // EPI_HB16TIME_PSRAMSZ__3 : 512 B 
                                            // 0x00040000 : 
                                            // EPI_HB16TIME_PSRAMSZ__4 : 1024 B 
                                            // 0x00050000 : 
                                            // EPI_HB16TIME_PSRAMSZ__5 : 2048 B 
                                            // 0x00060000 : 
                                            // EPI_HB16TIME_PSRAMSZ__6 : 4096 B 
                                            // 0x00070000 : 
                                            // EPI_HB16TIME_PSRAMSZ__7 : 8192 B 

#define EPI_HB16TIME_PSRAMSZ_S 16 
#define EPI_HB16TIME_CAPWIDTH_M \
                                0x00003000  // CS0n Inter-transfer Capture 
                                            // Width 0x00001000 : 
                                            // EPI_HB16TIME_CAPWIDTH__1 : 1 EPI 
                                            // clock 0x00002000 : 
                                            // EPI_HB16TIME_CAPWIDTH__2 : 2 EPI 
                                            // clock 

#define EPI_HB16TIME_CAPWIDTH_S 12 
#define EPI_HB16TIME_WRWSM      0x00000010  // Write Wait State Minus One 
#define EPI_HB16TIME_RDWSM      0x00000001  // Read Wait State Minus One 
//******************************************************************************
//
// The following are defines for the bit fields in the EPI_O_HB16TIME2 register.
//
//******************************************************************************
#define EPI_HB16TIME2_IRDYDLY_M \
                                0x03000000  // CS1n Input Ready Delay 
                                            // 0x00000000 : 
                                            // EPI_HB16TIME2_IRDYDLY__0 : Stall 
                                            // is immediate of data present on 
                                            // EPIO at time of iRDY low being 
                                            // sampled on rising edge of EPIO 
                                            // clock 0x01000000 : 
                                            // EPI_HB16TIME2_IRDYDLY__1 : Stall 
                                            // begins one EPI clocks past iRDY 
                                            // low being sampled on the rising 
                                            // edge of EPIO clock 0x02000000 : 
                                            // EPI_HB16TIME2_IRDYDLY__2 : Stall 
                                            // begins two EPI clocks past iRDY 
                                            // low being sampled on the rising 
                                            // edge of EPIO clock 0x03000000 : 
                                            // EPI_HB16TIME2_IRDYDLY__3 : Stall 
                                            // begins three EPI clocks past iRDY 
                                            // low being sampled on the rising 
                                            // edge of EPIO clock 

#define EPI_HB16TIME2_IRDYDLY_S 24 
#define EPI_HB16TIME2_PSRAMSZ_M \
                                0x00070000  // PSRAM Row Size 0x00000000 : 
                                            // EPI_HB16TIME2_PSRAMSZ__0 : No 
                                            // PSRAM 0x00010000 : 
                                            // EPI_HB16TIME2_PSRAMSZ__1 : 128 B 
                                            // 0x00020000 : 
                                            // EPI_HB16TIME2_PSRAMSZ__2 : 256 B 
                                            // 0x00030000 : 
                                            // EPI_HB16TIME2_PSRAMSZ__3 : 512 B 
                                            // 0x00040000 : 
                                            // EPI_HB16TIME2_PSRAMSZ__4 : 1024 B 
                                            // 0x00050000 : 
                                            // EPI_HB16TIME2_PSRAMSZ__5 : 2048 B 
                                            // 0x00060000 : 
                                            // EPI_HB16TIME2_PSRAMSZ__6 : 4096 B 
                                            // 0x00070000 : 
                                            // EPI_HB16TIME2_PSRAMSZ__7 : 8192 B 

#define EPI_HB16TIME2_PSRAMSZ_S 16 
#define EPI_HB16TIME2_CAPWIDTH_M \
                                0x00003000  // CS1n Inter-transfer Capture 
                                            // Width 0x00001000 : 
                                            // EPI_HB16TIME2_CAPWIDTH__1 : 1 EPI 
                                            // clock 0x00002000 : 
                                            // EPI_HB16TIME2_CAPWIDTH__2 : 2 EPI 
                                            // clock 

#define EPI_HB16TIME2_CAPWIDTH_S 12 
#define EPI_HB16TIME2_WRWSM     0x00000010  // CS1n Write Wait State Minus One 
#define EPI_HB16TIME2_RDWSM     0x00000001  // CS1n Read Wait State Minus One 
//******************************************************************************
//
// The following are defines for the bit fields in the EPI_O_HB16TIME3 register.
//
//******************************************************************************
#define EPI_HB16TIME3_IRDYDLY_M \
                                0x03000000  // CS2n Input Ready Delay 
                                            // 0x00000000 : 
                                            // EPI_HB16TIME3_IRDYDLY__0 : Stall 
                                            // is immediate of data present on 
                                            // EPIO at time of iRDY low being 
                                            // sampled on rising edge of EPIO 
                                            // clock 0x01000000 : 
                                            // EPI_HB16TIME3_IRDYDLY__1 : Stall 
                                            // begins one EPI clocks past iRDY 
                                            // low being sampled on the rising 
                                            // edge of EPIO clock 0x02000000 : 
                                            // EPI_HB16TIME3_IRDYDLY__2 : Stall 
                                            // begins two EPI clocks past iRDY 
                                            // low being sampled on the rising 
                                            // edge of EPIO clock 0x03000000 : 
                                            // EPI_HB16TIME3_IRDYDLY__3 : Stall 
                                            // begins three EPI clocks past iRDY 
                                            // low being sampled on the rising 
                                            // edge of EPIO clock 

#define EPI_HB16TIME3_IRDYDLY_S 24 
#define EPI_HB16TIME3_PSRAMSZ_M \
                                0x00070000  // PSRAM Row Size 0x00000000 : 
                                            // EPI_HB16TIME3_PSRAMSZ__0 : No 
                                            // PSRAM 0x00010000 : 
                                            // EPI_HB16TIME3_PSRAMSZ__1 : 128 B 
                                            // 0x00020000 : 
                                            // EPI_HB16TIME3_PSRAMSZ__2 : 256 B 
                                            // 0x00030000 : 
                                            // EPI_HB16TIME3_PSRAMSZ__3 : 512 B 
                                            // 0x00040000 : 
                                            // EPI_HB16TIME3_PSRAMSZ__4 : 1024 B 
                                            // 0x00050000 : 
                                            // EPI_HB16TIME3_PSRAMSZ__5 : 2048 B 
                                            // 0x00060000 : 
                                            // EPI_HB16TIME3_PSRAMSZ__6 : 4096 B 
                                            // 0x00070000 : 
                                            // EPI_HB16TIME3_PSRAMSZ__7 : 8192 B 

#define EPI_HB16TIME3_PSRAMSZ_S 16 
#define EPI_HB16TIME3_CAPWIDTH_M \
                                0x00003000  // CS2n Inter-transfer Capture 
                                            // Width 0x00001000 : 
                                            // EPI_HB16TIME3_CAPWIDTH__1 : 1 EPI 
                                            // clock 0x00002000 : 
                                            // EPI_HB16TIME3_CAPWIDTH__2 : 2 EPI 
                                            // clock 

#define EPI_HB16TIME3_CAPWIDTH_S 12 
#define EPI_HB16TIME3_WRWSM     0x00000010  // CS2n Write Wait State Minus One 
#define EPI_HB16TIME3_RDWSM     0x00000001  // CS2n Read Wait State Minus One 
//******************************************************************************
//
// The following are defines for the bit fields in the EPI_O_HB16TIME4 register.
//
//******************************************************************************
#define EPI_HB16TIME4_IRDYDLY_M \
                                0x03000000  // CS3n Input Ready Delay 
                                            // 0x00000000 : 
                                            // EPI_HB16TIME4_IRDYDLY__0 : Stall 
                                            // is immediate of data present on 
                                            // EPIO at time of iRDY low being 
                                            // sampled on rising edge of EPIO 
                                            // clock 0x01000000 : 
                                            // EPI_HB16TIME4_IRDYDLY__1 : Stall 
                                            // begins one EPI clocks past iRDY 
                                            // low being sampled on the rising 
                                            // edge of EPIO clock 0x02000000 : 
                                            // EPI_HB16TIME4_IRDYDLY__2 : Stall 
                                            // begins two EPI clocks past iRDY 
                                            // low being sampled on the rising 
                                            // edge of EPIO clock 0x03000000 : 
                                            // EPI_HB16TIME4_IRDYDLY__3 : Stall 
                                            // begins three EPI clocks past iRDY 
                                            // low being sampled on the rising 
                                            // edge of EPIO clock 

#define EPI_HB16TIME4_IRDYDLY_S 24 
#define EPI_HB16TIME4_PSRAMSZ_M \
                                0x00070000  // PSRAM Row Size 0x00000000 : 
                                            // EPI_HB16TIME4_PSRAMSZ__0 : No 
                                            // PSRAM 0x00010000 : 
                                            // EPI_HB16TIME4_PSRAMSZ__1 : 128 B 
                                            // 0x00020000 : 
                                            // EPI_HB16TIME4_PSRAMSZ__2 : 256 B 
                                            // 0x00030000 : 
                                            // EPI_HB16TIME4_PSRAMSZ__3 : 512 B 
                                            // 0x00040000 : 
                                            // EPI_HB16TIME4_PSRAMSZ__4 : 1024 B 
                                            // 0x00050000 : 
                                            // EPI_HB16TIME4_PSRAMSZ__5 : 2048 B 
                                            // 0x00060000 : 
                                            // EPI_HB16TIME4_PSRAMSZ__6 : 4096 B 
                                            // 0x00070000 : 
                                            // EPI_HB16TIME4_PSRAMSZ__7 : 8192 B 

#define EPI_HB16TIME4_PSRAMSZ_S 16 
#define EPI_HB16TIME4_CAPWIDTH_M \
                                0x00003000  // CS3n Inter-transfer Capture 
                                            // Width 0x00001000 : 
                                            // EPI_HB16TIME4_CAPWIDTH__1 : 1 EPI 
                                            // clock 0x00002000 : 
                                            // EPI_HB16TIME4_CAPWIDTH__2 : 2 EPI 
                                            // clock 

#define EPI_HB16TIME4_CAPWIDTH_S 12 
#define EPI_HB16TIME4_WRWSM     0x00000010  // CS3n Write Wait State Minus One 
#define EPI_HB16TIME4_RDWSM     0x00000001  // CS3n Read Wait State Minus One 
//******************************************************************************
//
// The following are defines for the bit fields in the EPI_O_HBPSRAM register.
//
//******************************************************************************
#define EPI_HBPSRAM_CR_M      0x001FFFFF  // PSRAM Config Register 
#define EPI_HBPSRAM_CR_S      0 



#endif // __HW_EPI_H__
