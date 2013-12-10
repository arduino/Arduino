//*****************************************************************************
//
// hw_lcd.h - Defines and macros used when accessing the LCD controller.
//
// Copyright (c) 2011-2013 Texas Instruments Incorporated.  All rights reserved.
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
// This is part of revision 2.0.1.11577 of the Tiva Firmware Development Package.
//
//*****************************************************************************

#ifndef __HW_LCD_H__
#define __HW_LCD_H__

//*****************************************************************************
//
// The following are defines for the LCD register offsets.
//
//*****************************************************************************
#define LCD_O_PID               0x00000000  // PID Register Format
#define LCD_O_CTL               0x00000004  // LCD Control
#define LCD_O_LIDDCTL           0x0000000C  // LCD LIDD Control
#define LCD_O_LIDDCS0CFG        0x00000010  // LCD LIDD CS0 Configuration
#define LCD_O_LIDDCS0ADDR       0x00000014  // LIDD CS0 Read/Write Address
#define LCD_O_LIDDCS0DATA       0x00000018  // LIDD CS0 Data Read/Write
                                            // Initiation
#define LCD_O_LIDDCS1CFG        0x0000001C  // LIDD CS1 Configuration
#define LCD_O_LIDDCS1ADDR       0x00000020  // LIDD CS1 Address Read/Write
                                            // Initiation
#define LCD_O_LIDDCS1DATA       0x00000024  // LIDD CS1 Data Read/Write
                                            // Initiation
#define LCD_O_RASTRCTL          0x00000028  // LCD Raster Control
#define LCD_O_RASTRTIM0         0x0000002C  // LCD Raster Timing 0
#define LCD_O_RASTRTIM1         0x00000030  // LCD Raster Timing 1
#define LCD_O_RASTRTIM2         0x00000034  // LCD Raster Timing 2
#define LCD_O_RASTRSUBP1        0x00000038  // LCD Raster Subpanel Display 1
#define LCD_O_RASTRSUBP2        0x0000003C  // LCD Raster Subpanel Display 2
#define LCD_O_DMACTL            0x00000040  // LCD DMA Control
#define LCD_O_DMABAFB0          0x00000044  // LCD DMA Frame Buffer 0 Base
                                            // Address
#define LCD_O_DMACAFB0          0x00000048  // LCD DMA Frame Buffer 0 Ceiling
                                            // Address
#define LCD_O_DMABAFB1          0x0000004C  // LCD DMA Frame Buffer 1 Base
                                            // Address
#define LCD_O_DMACAFB1          0x00000050  // LCD DMA Frame Buffer 1 Ceiling
                                            // Address
#define LCD_O_SYSCFG            0x00000054  // LCD System Configuration
                                            // Register
#define LCD_O_RISSET            0x00000058  // LCD Interrupt Raw Status and Set
                                            // Register
#define LCD_O_MISCLR            0x0000005C  // LCD Interrupt Status and Clear
#define LCD_O_IM                0x00000060  // LCD Interrupt Interrupt Mask
#define LCD_O_IENC              0x00000064  // LCD Interrupt Enable Clear
#define LCD_O_CLKEN             0x0000006C  // LCD Clock Enable
#define LCD_O_CLKRESET          0x00000070  // LCD Clock Resets

//*****************************************************************************
//
// The following are defines for the bit fields in the LCD_O_PID register.
//
//*****************************************************************************
#define LCD_PID_MAJOR_M         0x00000700  // Major Release Number
#define LCD_PID_MINOR_M         0x0000003F  // Minor Release Number
#define LCD_PID_MAJOR_S         8
#define LCD_PID_MINOR_S         0

//*****************************************************************************
//
// The following are defines for the bit fields in the LCD_O_CTL register.
//
//*****************************************************************************
#define LCD_CTL_CLKDIV_M        0x0000FF00  // Clock Divisor
#define LCD_CTL_UFLOWRST        0x00000002  // Underflow Restart
#define LCD_CTL_LCDMODE         0x00000001  // LCD Mode Select
#define LCD_CTL_CLKDIV_S        8

//*****************************************************************************
//
// The following are defines for the bit fields in the LCD_O_LIDDCTL register.
//
//*****************************************************************************
#define LCD_LIDDCTL_DMACS       0x00000200  // CS0/CS1 Select for LIDD DMA
                                            // Writes
#define LCD_LIDDCTL_DMAEN       0x00000100  // LIDD DMA Enable
#define LCD_LIDDCTL_CS1E1       0x00000080  // Chip Select 1 (CS1)/Enable 1(E1)
                                            // Polarity Control
#define LCD_LIDDCTL_CS0E0       0x00000040  // Chip Select 0 (CS0)/Enable 0
                                            // (E0) Polarity Control
#define LCD_LIDDCTL_WRDIRINV    0x00000020  // Write Strobe (WR) /Direction
                                            // (DIR) Polarity Control
#define LCD_LIDDCTL_RDEN        0x00000010  // Read Strobe (RD) /Direct Enable
                                            // (EN) Polarity Control
#define LCD_LIDDCTL_ALE         0x00000008  // Address Latch Enable (ALE)
                                            // Polarity Control
#define LCD_LIDDCTL_MODE_M      0x00000007  // LIDD Mode Select
#define LCD_LIDDCTL_MODE_SYNCM68                                              \
                                0x00000000  // Sync MPU68
#define LCD_LIDDCTL_MODE_ASYNCM68                                             \
                                0x00000001  // Async MPU68
#define LCD_LIDDCTL_MODE_SYNCM80                                              \
                                0x00000002  // Sync MPU80
#define LCD_LIDDCTL_MODE_ASYNCM80                                             \
                                0x00000003  // Async MPU80
#define LCD_LIDDCTL_MODE_ASYNCHIT                                             \
                                0x00000004  // Hitachi (Async)

//*****************************************************************************
//
// The following are defines for the bit fields in the LCD_O_LIDDCS0CFG
// register.
//
//*****************************************************************************
#define LCD_LIDDCS0CFG_WRSU_M   0xF8000000  // Write Strobe (WR) Set-Up Cycles
#define LCD_LIDDCS0CFG_WRDUR_M  0x07E00000  // Write Strobe (WR) Duration
                                            // Cycles
#define LCD_LIDDCS0CFG_WRHOLD_M 0x001E0000  // Write Strobe (WR) Hold cycles
#define LCD_LIDDCS0CFG_RDSU_M   0x0001F000  // Read Strobe (RD) Set-Up cycles
#define LCD_LIDDCS0CFG_RDDUR_M  0x00000FC0  // Read Strobe (RD) Duration cycles
#define LCD_LIDDCS0CFG_RDHOLD_M 0x0000003C  // Read Strobe (RD) Hold cycles
#define LCD_LIDDCS0CFG_GAP_M    0x00000003  // Field value defines the number
                                            // of LCDMCLK (ta+1) cycles between
                                            // the end of one CS0 (LCDAC)
                                            // device access and the start of
                                            // another CS0 (LCDAC) device
                                            // access unless the two accesses
                                            // are both Reads
#define LCD_LIDDCS0CFG_WRSU_S   27
#define LCD_LIDDCS0CFG_WRDUR_S  21
#define LCD_LIDDCS0CFG_WRHOLD_S 17
#define LCD_LIDDCS0CFG_RDSU_S   12
#define LCD_LIDDCS0CFG_RDDUR_S  6
#define LCD_LIDDCS0CFG_RDHOLD_S 2
#define LCD_LIDDCS0CFG_GAP_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the LCD_O_LIDDCS0ADDR
// register.
//
//*****************************************************************************
#define LCD_LIDDCS0ADDR_CS0ADDR_M                                             \
                                0x0000FFFF  // LCD Address Bus Initiation
#define LCD_LIDDCS0ADDR_CS0ADDR_S                                             \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the LCD_O_LIDDCS0DATA
// register.
//
//*****************************************************************************
#define LCD_LIDDCS0DATA_CS0DATA_M                                             \
                                0x0000FFFF  // LCD Data Read/Write Initiation
#define LCD_LIDDCS0DATA_CS0DATA_S                                             \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the LCD_O_LIDDCS1CFG
// register.
//
//*****************************************************************************
#define LCD_LIDDCS1CFG_WRSU_M   0xF8000000  // Write Strobe (WR) Set-Up Cycles
#define LCD_LIDDCS1CFG_WRDUR_M  0x07E00000  // Write Strobe (WR) Duration
                                            // Cycles
#define LCD_LIDDCS1CFG_WRHOLD_M 0x001E0000  // Write Strobe (WR) Hold cycles
#define LCD_LIDDCS1CFG_RDSU_M   0x0001F000  // Read Strobe (RD) Set-Up cycles
#define LCD_LIDDCS1CFG_RDDUR_M  0x00000FC0  // Read Strobe (RD) Duration cycles
#define LCD_LIDDCS1CFG_RDHOLD_M 0x0000003C  // Read Strobe (RD) Hold cycles
#define LCD_LIDDCS1CFG_GAP_M    0x00000003  // Field value defines the number
                                            // of LCDMCLK (ta+1) cycles between
                                            // the end of one CS1 (LCDAC)
                                            // device access and the start of
                                            // another CS0 (LCDAC) device
                                            // access unless the two accesses
                                            // are both Reads
#define LCD_LIDDCS1CFG_WRSU_S   27
#define LCD_LIDDCS1CFG_WRDUR_S  21
#define LCD_LIDDCS1CFG_WRHOLD_S 17
#define LCD_LIDDCS1CFG_RDSU_S   12
#define LCD_LIDDCS1CFG_RDDUR_S  6
#define LCD_LIDDCS1CFG_RDHOLD_S 2
#define LCD_LIDDCS1CFG_GAP_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the LCD_O_LIDDCS1ADDR
// register.
//
//*****************************************************************************
#define LCD_LIDDCS1ADDR_CS1ADDR_M                                             \
                                0x0000FFFF  // LCD Address Bus Initiation
#define LCD_LIDDCS1ADDR_CS1ADDR_S                                             \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the LCD_O_LIDDCS1DATA
// register.
//
//*****************************************************************************
#define LCD_LIDDCS1DATA_CS0DATA_M                                             \
                                0x0000FFFF  // LCD Data Read/Write Initiation
#define LCD_LIDDCS1DATA_CS0DATA_S                                             \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the LCD_O_RASTRCTL register.
//
//*****************************************************************************
#define LCD_RASTRCTL_TFT24UPCK  0x04000000  // 24-bit TFT Mode Packing
#define LCD_RASTRCTL_TFT24      0x02000000  // 24-Bit TFT Mode
#define LCD_RASTRCTL_FRMBUFSZ   0x01000000  // Frame Buffer Select
#define LCD_RASTRCTL_TFTMAP     0x00800000  // TFT Mode Alternate Signal
                                            // Mapping for Palettized
                                            // Framebuffer
#define LCD_RASTRCTL_NIBMODE    0x00400000  // Nibble Mode
#define LCD_RASTRCTL_PALMODE_M  0x00300000  // Pallette Loading Mode
#define LCD_RASTRCTL_PALMODE_PALDAT                                           \
                                0x00000000  // Palette and data loading, reset
                                            // value
#define LCD_RASTRCTL_PALMODE_PAL                                              \
                                0x00100000  // Palette loading only
#define LCD_RASTRCTL_PALMODE_DAT                                              \
                                0x00200000  // Data loading only
#define LCD_RASTRCTL_REQDLY_M   0x000FF000  // Palette Loading Delay
#define LCD_RASTRCTL_MONO8B     0x00000200  // Mono 8-Bit
#define LCD_RASTRCTL_RDORDER    0x00000100  // Raster Data Order Select
#define LCD_RASTRCTL_LCDTFT     0x00000080  // LCD TFT
#define LCD_RASTRCTL_LCDBW      0x00000002  // LCD Monochrome
#define LCD_RASTRCTL_LCDEN      0x00000001  // LCD Controller Enable for Raster
                                            // Operations
#define LCD_RASTRCTL_REQDLY_S   12

//*****************************************************************************
//
// The following are defines for the bit fields in the LCD_O_RASTRTIM0
// register.
//
//*****************************************************************************
#define LCD_RASTRTIM0_HBP_M     0xFF000000  // Horizontal Back Porch Lowbits
#define LCD_RASTRTIM0_HFP_M     0x00FF0000  // Horizontal Front Porch Lowbits
#define LCD_RASTRTIM0_HSW_M     0x0000FC00  // Horizontal Sync Pulse Width
                                            // Lowbits
#define LCD_RASTRTIM0_PPL_M     0x000003F0  // Pixels-per-line LSB[9:4]
#define LCD_RASTRTIM0_MSBPPL    0x00000008  // Pixels-per-line MSB[10]
#define LCD_RASTRTIM0_HBP_S     24
#define LCD_RASTRTIM0_HFP_S     16
#define LCD_RASTRTIM0_HSW_S     10
#define LCD_RASTRTIM0_PPL_S     4

//*****************************************************************************
//
// The following are defines for the bit fields in the LCD_O_RASTRTIM1
// register.
//
//*****************************************************************************
#define LCD_RASTRTIM1_VBP_M     0xFF000000  // Vertical Back Porch
#define LCD_RASTRTIM1_VFP_M     0x00FF0000  // Vertical Front Porch
#define LCD_RASTRTIM1_VSW_M     0x0000FC00  // Vertical Sync Width Pulse
#define LCD_RASTRTIM1_LPP_M     0x000003FF  // Lines Per Panel
#define LCD_RASTRTIM1_VBP_S     24
#define LCD_RASTRTIM1_VFP_S     16
#define LCD_RASTRTIM1_VSW_S     10
#define LCD_RASTRTIM1_LPP_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the LCD_O_RASTRTIM2
// register.
//
//*****************************************************************************
#define LCD_RASTRTIM2_HSW_M     0x78000000  // Bits 9:6 of the horizontal sync
                                            // width field
#define LCD_RASTRTIM2_MSBLPP    0x04000000  // MSB of Lines Per Panel
#define LCD_RASTRTIM2_PXLCLKCTL 0x02000000  // Hsync/Vsync Pixel Clock Control
                                            // On/Off
#define LCD_RASTRTIM2_PSYNCRF   0x01000000  // Program HSYNC/VSYNC Rise or Fall
#define LCD_RASTRTIM2_INVOE     0x00800000  // Invert Output Enable
#define LCD_RASTRTIM2_INVPXLCLK 0x00400000  // Invert Pixel Clock
#define LCD_RASTRTIM2_IHS       0x00200000  // Invert Hysync
#define LCD_RASTRTIM2_IVS       0x00100000  // Invert Vsync
#define LCD_RASTRTIM2_ACBI_M    0x000F0000  // AC Bias Pins Transitions per
                                            // Interrupt
#define LCD_RASTRTIM2_ACBF_M    0x0000FF00  // AC Bias Pin Frequency
#define LCD_RASTRTIM2_MSBHBP_M  0x00000030  // Bits 9:8 of the horizontal back
                                            // porch field
#define LCD_RASTRTIM2_MSBHFP_M  0x00000003  // Bits 9:8 of the horizontal front
                                            // porch field
#define LCD_RASTRTIM2_HSW_S     27
#define LCD_RASTRTIM2_ACBI_S    16
#define LCD_RASTRTIM2_ACBF_S    8
#define LCD_RASTRTIM2_MSBHBP_S  4
#define LCD_RASTRTIM2_MSBHFP_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the LCD_O_RASTRSUBP1
// register.
//
//*****************************************************************************
#define LCD_RASTRSUBP1_SPEN     0x80000000  // Sub Panel Enable
#define LCD_RASTRSUBP1_HOLS     0x20000000  // High or Low Signal
#define LCD_RASTRSUBP1_LPPT_M   0x03FF0000  // Line Per Panel Threshold
#define LCD_RASTRSUBP1_DPDLSB_M 0x0000FFFF  // Default Pixel Data LSB[15:0]
#define LCD_RASTRSUBP1_LPPT_S   16
#define LCD_RASTRSUBP1_DPDLSB_S 0

//*****************************************************************************
//
// The following are defines for the bit fields in the LCD_O_RASTRSUBP2
// register.
//
//*****************************************************************************
#define LCD_RASTRSUBP2_LPPTMSB  0x00000100  // Lines Per Panel Threshold Bit 10
#define LCD_RASTRSUBP2_DPDMSB_M 0x000000FF  // Default Pixel Data MSB [23:16]
#define LCD_RASTRSUBP2_DPDMSB_S 0

//*****************************************************************************
//
// The following are defines for the bit fields in the LCD_O_DMACTL register.
//
//*****************************************************************************
#define LCD_DMACTL_DMAMSTRP_M   0x00070000  // Priority for the L3 OCP Master
                                            // Bus
#define LCD_DMACTL_FIFORDY_M    0x00000700  // DMA FIFO threshold
#define LCD_DMACTL_FIFORDY_8    0x00000000  // 8 words
#define LCD_DMACTL_FIFORDY_16   0x00000100  // 16 words
#define LCD_DMACTL_FIFORDY_32   0x00000200  // 32 words
#define LCD_DMACTL_FIFORDY_64   0x00000300  // 64 words
#define LCD_DMACTL_FIFORDY_128  0x00000400  // 128 words
#define LCD_DMACTL_FIFORDY_256  0x00000500  // 256 words
#define LCD_DMACTL_FIFORDY_512  0x00000600  // 512 words
#define LCD_DMACTL_BURSTSZ_M    0x00000070  // Burst Size setting for DMA
                                            // transfers (all DMA transfers are
                                            // 32 bits wide):
#define LCD_DMACTL_BURSTSZ_4    0x00000020  // burst size of 4
#define LCD_DMACTL_BURSTSZ_8    0x00000030  // burst size of 8
#define LCD_DMACTL_BURSTSZ_16   0x00000040  // burst size of 16
#define LCD_DMACTL_BYTESWAP     0x00000008  // This bit controls the bytelane
                                            // ordering of the data on the
                                            // output of the DMA module
#define LCD_DMACTL_BIGDEND      0x00000002  // The BIGEND and BYTESWAP bits
                                            // control the bytelane ordering of
                                            // the data on the output of the
                                            // DMA module
#define LCD_DMACTL_FMODE        0x00000001  // Frame Mode
#define LCD_DMACTL_DMAMSTRP_S   16

//*****************************************************************************
//
// The following are defines for the bit fields in the LCD_O_DMABAFB0 register.
//
//*****************************************************************************
#define LCD_DMABAFB0_FB0BA_M    0xFFFFFFFC  // Frame Buffer 0 Base Address
                                            // pointer
#define LCD_DMABAFB0_FB0BA_S    2

//*****************************************************************************
//
// The following are defines for the bit fields in the LCD_O_DMACAFB0 register.
//
//*****************************************************************************
#define LCD_DMACAFB0_FB0CA_M    0xFFFFFFFC  // Frame Buffer 0 Ceiling Address
                                            // pointer
#define LCD_DMACAFB0_FB0CA_S    2

//*****************************************************************************
//
// The following are defines for the bit fields in the LCD_O_DMABAFB1 register.
//
//*****************************************************************************
#define LCD_DMABAFB1_FB1BA_M    0xFFFFFFFC  // Frame Buffer 1 Base Address
                                            // pointer
#define LCD_DMABAFB1_FB1BA_S    2

//*****************************************************************************
//
// The following are defines for the bit fields in the LCD_O_DMACAFB1 register.
//
//*****************************************************************************
#define LCD_DMACAFB1_FB1CA_M    0xFFFFFFFC  // Frame Buffer 1 Ceiling Address
                                            // pointer
#define LCD_DMACAFB1_FB1CA_S    2

//*****************************************************************************
//
// The following are defines for the bit fields in the LCD_O_SYSCFG register.
//
//*****************************************************************************
#define LCD_SYSCFG_STDBY_M      0x00000030  // Configuration of the local
                                            // initiator state management mode
#define LCD_SYSCFG_STDBY_FORCE  0x00000000  // Force-standby mode: local
                                            // initiator is unconditionally
                                            // placed in standby state. Backup
                                            // mode, for debug only
#define LCD_SYSCFG_STDBY_NONE   0x00000010  // No-standby mode: local initiator
                                            // is unconditionally placed out of
                                            // standby state. Backup mode, for
                                            // debug only
#define LCD_SYSCFG_STDBY_SMART  0x00000020  // Smart-standby mode: local
                                            // initiator standby status depends
                                            // on local conditions, i.e. the
                                            // module's functional requirement
                                            // from the initiator. IP module
                                            // shall not generate
                                            // (initiator-related) wakeup
                                            // events
#define LCD_SYSCFG_STDBY_SMWAKE 0x00000030  // Smart-Standby wakeup-capable
                                            // mode: local initiator standby
                                            // status depends on local
                                            // conditions, i.e. the module's
                                            // functional requirement from the
                                            // initiator
#define LCD_SYSCFG_IDLEMODE_M   0x0000000C  // Configuration of the local
                                            // target state management mode
#define LCD_SYSCFG_IDLEMODE_FORCE                                             \
                                0x00000000  // Force-idle mode: local target's
                                            // idle state follows
                                            // (acknowledges) the system's idle
                                            // requests unconditionally, i.e.
                                            // regardless of the IP module's
                                            // internal requirements. Backup
                                            // mode, for debug only
#define LCD_SYSCFG_IDLEMODE_NONE                                              \
                                0x00000004  // No-idle mode: local target never
                                            // enters idle state. Backup mode,
                                            // for debug only
#define LCD_SYSCFG_IDLEMODE_SMART                                             \
                                0x00000008  // Smart-idle mode: local target's
                                            // idle state eventually follows
                                            // (acknowledges) the system's idle
                                            // requests, depending on the IP
                                            // module's internal requirements.
                                            // IP module shall not generate
                                            // (IRQ- or DMA-requestrelated)
                                            // wakeup events
#define LCD_SYSCFG_IDLEMODE_SMWAKE                                            \
                                0x0000000C  // Smart-idle wakeup-capable mode:
                                            // local target's idle state
                                            // eventually follows
                                            // (acknowledges) the system's idle
                                            // requests, depending on the IP
                                            // module's internal requirements

//*****************************************************************************
//
// The following are defines for the bit fields in the LCD_O_RISSET register.
//
//*****************************************************************************
#define LCD_RISSET_EOF1         0x00000200  // DMA End-of-Frame 1 Raw Interrupt
                                            // Status and Set
#define LCD_RISSET_EOF0         0x00000100  // DMA End-of-Frame 0 Raw Interrupt
                                            // Status and Set
#define LCD_RISSET_PALLOAD      0x00000040  // DMA Palette Loaded Raw Interrupt
                                            // Status and Set
#define LCD_RISSET_FIFOU        0x00000020  // DMA FIFO Underflow Raw Interrupt
                                            // Status and Set
#define LCD_RISSET_ACBS         0x00000008  // AC Bias Count Raw Interrupt
                                            // Status and Set
#define LCD_RISSET_SYNCS        0x00000004  // Frame Synchronization Lost Raw
                                            // Interrupt Status and Set
#define LCD_RISSET_RRASTRDONE   0x00000002  // Raster Mode Frame Done interrupt
#define LCD_RISSET_DONE         0x00000001  // Raster or LIDD Frame Done
                                            // (shared, depends on whether
                                            // Raster or LIDD mode enabled) Raw
                                            // Interrupt Status and Set

//*****************************************************************************
//
// The following are defines for the bit fields in the LCD_O_MISCLR register.
//
//*****************************************************************************
#define LCD_MISCLR_EOF1         0x00000200  // DMA End-of-Frame 1 Enabled
                                            // Interrupt and Clear
#define LCD_MISCLR_EOF0         0x00000100  // DMA End-of-Frame 0 Raw Interrupt
                                            // and Clear
#define LCD_MISCLR_PALLOAD      0x00000040  // DMA Palette Loaded Enabled
                                            // Interrupt and Clear
#define LCD_MISCLR_FIFOU        0x00000020  // DMA FIFO Underflow Enabled
                                            // Interrupt and Clear
#define LCD_MISCLR_ACBS         0x00000008  // AC Bias Count Enabled Interrupt
                                            // and Clear
#define LCD_MISCLR_SYNCS        0x00000004  // Frame Synchronization Lost
                                            // Enabled Interrupt and Clear
#define LCD_MISCLR_RRASTRDONE   0x00000002  // Raster Mode Frame Done interrupt
#define LCD_MISCLR_DONE         0x00000001  // Raster or LIDD Frame Done
                                            // (shared, depends on whether
                                            // Raster or LIDD mode enabled)
                                            // Enabled Interrupt and Clear

//*****************************************************************************
//
// The following are defines for the bit fields in the LCD_O_IM register.
//
//*****************************************************************************
#define LCD_IM_EOF1             0x00000200  // DMA End-of-Frame 1 Interrupt
                                            // Enable Set
#define LCD_IM_EOF0             0x00000100  // DMA End-of-Frame 0 Interrupt
                                            // Enable Set
#define LCD_IM_PALLOAD          0x00000040  // DMA Palette Loaded Interrupt
                                            // Enable Set
#define LCD_IM_FIFOU            0x00000020  // DMA FIFO Underflow Interrupt
                                            // Enable Set
#define LCD_IM_ACBS             0x00000008  // AC Bias Count Interrupt Enable
                                            // Set
#define LCD_IM_SYNCS            0x00000004  // Frame Synchronization Lost
                                            // Interrupt Enable Set
#define LCD_IM_RRASTRDONE       0x00000002  // Raster Mode Frame Done Interrupt
                                            // Enable Set
#define LCD_IM_DONE             0x00000001  // Raster or LIDD Frame Done
                                            // (shared, depends on whether
                                            // Raster or LIDD mode enabled)
                                            // Interrupt Enable Set

//*****************************************************************************
//
// The following are defines for the bit fields in the LCD_O_IENC register.
//
//*****************************************************************************
#define LCD_IENC_EOF1           0x00000200  // DMA End-of-Frame 1 Interrupt
                                            // Enable Clear
#define LCD_IENC_EOF0           0x00000100  // DMA End-of-Frame 0 Interrupt
                                            // Enable Clear
#define LCD_IENC_PALLOAD        0x00000040  // DMA Palette Loaded Interrupt
                                            // Enable Clear
#define LCD_IENC_FIFOU          0x00000020  // DMA FIFO Underflow Interrupt
                                            // Enable Clear
#define LCD_IENC_ACBS           0x00000008  // AC Bias Count Interrupt Enable
                                            // Clear
#define LCD_IENC_SYNCS          0x00000004  // Frame Synchronization Lost
                                            // Interrupt Enable Clear
#define LCD_IENC_RRASTRDONE     0x00000002  // Raster Mode Frame Done Interrupt
                                            // Enable Clear
#define LCD_IENC_DONE           0x00000001  // Raster or LIDD Frame Done
                                            // (shared, depends on whether
                                            // Raster or LIDD mode enabled)
                                            // Interrupt Enable Clear

//*****************************************************************************
//
// The following are defines for the bit fields in the LCD_O_CLKEN register.
//
//*****************************************************************************
#define LCD_CLKEN_DMA           0x00000004  // Software Clock Enable for the
                                            // DMA submodule
#define LCD_CLKEN_LIDD          0x00000002  // Software Clock Enable for the
                                            // LIDD submodule (character
                                            // displays)
#define LCD_CLKEN_CORE          0x00000001  // Software Clock Enable for the
                                            // Core, which encompasses the
                                            // Raster Active Matrix and Passive
                                            // Matrix logic

//*****************************************************************************
//
// The following are defines for the bit fields in the LCD_O_CLKRESET register.
//
//*****************************************************************************
#define LCD_CLKRESET_MAIN       0x00000008  // Software Reset for the entire
                                            // LCD module
#define LCD_CLKRESET_DMA        0x00000004  // Software Reset for the DMA
                                            // submodule
#define LCD_CLKRESET_LIDD       0x00000002  // Software Reset for the LIDD
                                            // submodule (character displays)
#define LCD_CLKRESET_CORE       0x00000001  // Software Reset for the Core,
                                            // which encompasses the Raster
                                            // Active Matrix and Passive Matrix
                                            // logic

#endif // __HW_LCD_H__
