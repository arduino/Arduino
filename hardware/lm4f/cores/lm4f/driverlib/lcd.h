//*****************************************************************************
//
// lcd.h - Defines and Macros for the LCD Controller module.
//
// Copyright (c) 2012-2013 Texas Instruments Incorporated.  All rights reserved.
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

#ifndef __DRIVERLIB_LCD_H__
#define __DRIVERLIB_LCD_H__

//*****************************************************************************
//
//! \addtogroup lcd_api
//! @{
//
//*****************************************************************************

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

//*****************************************************************************
//
//! This macro can be used to convert a 24-bit RGB color value as used by the
//! TivaWare Graphics Library into a 12-bit LCD controller color palette
//! entry.
//
//*****************************************************************************
#define PAL_FROM_RGB(ui32RGBColor) (((ui32RGBColor & 0xF0) >> 4) |            \
                                    ((ui32RGBColor & 0xF000) >> 8) |          \
                                    ((ui32RGBColor & 0xF00000) >> 12))

//*****************************************************************************
//
//! This macro can be used to convert from time in microseconds to periods of
//! the supplied clock in Hertz as required when setting up the LIDD and raster
//! timing structures.  The calculation will round such that the number of
//! cycles returned represents no longer a time than specified in the
//! ui32Time_uS parameter.  Values of ui32Time_uS less than or equal to
//! 4294967uS (4.29 seconds) are supported by the macro.  Larger values will
//! cause arithmetic overflow and yield incorrect values.  It is further
//! assumed that ui32ClockFreq is a non-zero multiple of 1000000 (1MHz).
//
//*****************************************************************************
#define CYCLES_FROM_TIME_US(ui32ClockFreq, ui32Time_uS)                       \
    (((ui32Time_uS) == 0) ? 0 :                                               \
    (((ui32ClockFreq) / 1000000) * ((((ui32Time_uS) * 1000) - 1) / 1000)) + 1)

//*****************************************************************************
//
//! This macro can be used to convert from time in nanoseconds to periods of
//! the supplied clock in Hertz as required when setting up the LIDD and raster
//! timing structures.  The calculation will round such that the number of
//! cycles returned represents no longer a time than specified in the
//! ui32Time_nS parameter.  Values of ui32Time_nS less than or equal to
//! 35791394 (35.79 milliseconds) are supported by the macro.  Larger values
//! will cause arithmetic overflow and yield incorrect values.  It is further
//! assumed that ui32ClockFreq is a non-zero multiple of 1000000 (1MHz).
//
//*****************************************************************************
#define CYCLES_FROM_TIME_NS(ui32ClockFreq, ui32Time_nS)                       \
    (((ui32Time_nS) == 0) ? 0 :                                               \
    ((((((ui32ClockFreq) / 1000000) * ((ui32Time_nS) - 1)) / 1000)) + 1))

//*****************************************************************************
//
//! A structure containing timing parameters for the LIDD (LCD Interface
//! Display Driver) interface.  This is used with the LCDIDDTimingSet function.
//
//*****************************************************************************
typedef struct
{
    //
    //! Write Strobe Set-Up cycles.  When performing a write access, this
    //! field defines the number of MCLK cycles that Data Bus/Pad Output
    //! Enable, ALE, the Direction bit, and Chip Select have to be ready before
    //! the Write Strobe is asserted.  Valid values are from 0 to 31.
    //
    uint8_t ui8WSSetup;

    //
    //! Write Strobe Duration cycles.  Field value defines the number of MCLK
    //! cycles for which the Write Strobe is held active when performing a
    //! write access.  Valid values are from 1 to 63.
    //
    uint8_t ui8WSDuration;

    //
    //! Write Strobe Hold cycles.  Field value defines the number of MCLK
    //! cycles for which Data Bus/Pad Output Enable, ALE, the Direction bit,
    //! and Chip Select are held after the Write Strobe is deasserted when
    //! performing a write access.  Valid values are from 1 to 15.
    //
    uint8_t ui8WSHold;

    //
    //! Read Strobe Set-Up cycles.  When performing a read access, this field
    //! defines the number of MCLK cycles that Data Bus/Pad Output Enable, ALE,
    //! the Direction bit, and Chip Select have to be ready before the Read
    //! Strobe is asserted.  Valid values are from 0 to 31.
    //
    uint8_t ui8RSSetup;

    //
    //! Read Strobe Duration cycles.  Field value defines the number of MCLK
    //! cycles for which the Read Strobe is held active when performing a read
    //! access.  Valid values are from 1 to 63.
    //
    uint8_t ui8RSDuration;

    //
    //! Read Strobe Hold cycles.  Field value defines the number of MCLK cycles
    //! for which Data Bus/Pad Output Enable, ALE, the Direction bit, and Chip
    //! Select are held after the Read Strobe is deasserted when performing a
    //! read access.  Valid values are from 1 to 15.
    //
    uint8_t ui8RSHold;

    //
    //! Field value defines the number of MCLK cycles between the end of one
    //! device access and the start of another device access using the same
    //! Chip Select unless the two accesses are both Reads.  In this case,
    //! this delay is not incurred.  Valid vales are from 1 to 4.
    //
    uint8_t ui8DelayCycles;
}
tLCDIDDTiming;

//
// Values which can be ORed together within the ui32Flags field of the
// tLCDRasterTiming structure.
//
#define RASTER_TIMING_SYNCS_OPPOSITE_PIXCLK                                   \
                                0x00000000
#define RASTER_TIMING_SYNCS_ON_RISING_PIXCLK                                  \
                                0x02000000
#define RASTER_TIMING_SYNCS_ON_FALLING_PIXCLK                                 \
                                0x03000000
#define RASTER_TIMING_ACTIVE_HIGH_OE                                          \
                                0x00000000
#define RASTER_TIMING_ACTIVE_LOW_OE                                           \
                                0x00800000
#define RASTER_TIMING_ACTIVE_HIGH_PIXCLK                                      \
                                0x00000000
#define RASTER_TIMING_ACTIVE_LOW_PIXCLK                                       \
                                0x00400000
#define RASTER_TIMING_ACTIVE_HIGH_HSYNC                                       \
                                0x00000000
#define RASTER_TIMING_ACTIVE_LOW_HSYNC                                        \
                                0x00200000
#define RASTER_TIMING_ACTIVE_HIGH_VSYNC                                       \
                                0x00000000
#define RASTER_TIMING_ACTIVE_LOW_VSYNC                                        \
                                0x00100000

//
//! A structure containing timing parameters for the raster interface.  This is
//! used with the LCDRasterTimingSet function.
//
typedef struct
{
    //
    //! Flags configuring the polarity and active edges of the various signals
    //! in the raster interface.  This field is comprised of a logical OR of
    //! the labels with prefix  ``RASTER_TIMING_''.
    //
    uint32_t ui32Flags;

    //
    //! The number of pixels contained within each line on the LCD display.
    //! Valid values are multiple of 16 less than or equal to 2048.
    //
    uint16_t ui16PanelWidth;

    //
    //! The number of lines on the LCD display.  Valid values are from 1 to
    //! 2048.
    //
    uint16_t ui16PanelHeight;

    //
    //! A value from 1 to 1024 that specifies the number of pixel clock periods
    //! to add to the end of each line after active video has ended.
    //
    uint16_t ui16HFrontPorch;

    //
    //! A value from 1 to 1024 that specifies the number of pixel clock periods
    //! to add to the beginning of a line before active video is asserted.
    //
    uint16_t ui16HBackPorch;

    //
    //! A value from 1 to 1024 that specifies the number of pixel clock periods
    //! to pulse the line clock at the end of each line.
    //
    uint16_t ui16HSyncWidth;

    //
    //! A value from 0 to 255 that specifies the number of line clock periods
    //! to add to the end of each frame after the last active line.
    //
    uint8_t ui8VFrontPorch;

    //
    //! A value from 0 to 255 that specifies the number of line clock periods
    //! to add to the beginning of a frame before the first active line is
    //! output to the display.
    //
    uint8_t ui8VBackPorch;

    //
    //! In active mode, a value from 1 to 64 that specifies the number of
    //! line clock periods to set the lcd_fp pin active at the end of each
    //! frame after the vertical front porch period elapses.  The number of
    //! The frame clock is used as the VSYNC signal in active mode.
    //!
    //! In passive mode, a value from 1 to 64 that specifies the number of
    //! extra line clock periods to insert after the vertical front porch
    //! period has elapsed.  Note that the width of lcd_fp is not affected by
    //! this value in passive mode.
    //
    uint8_t ui8VSyncWidth;

    //
    //! A value from 0 to 255 that specifies the number of line clocks to
    //! count before transitioning the AC Bias pin.  This pin is used to
    //! periodically invert the polarity of the power supply to prevent DC
    //! charge build-up within the display.
    //
    uint8_t ui8ACBiasLineCount;
}
tLCDRasterTiming;

//*****************************************************************************
//
// Possible values for the ui8Mode parameter to LCDModeSet().  The label
// LCD_MODE_AUTO_UFLOW_RESTART may be ORed with either of the other two.
//
//*****************************************************************************
#define LCD_MODE_LIDD           ((uint8_t)0x00)
#define LCD_MODE_RASTER         ((uint8_t)0x01)
#define LCD_MODE_AUTO_UFLOW_RESTART                                           \
                                ((uint8_t)0x02)

//*****************************************************************************
//
// Values used to construct the ui32Config parameter to LCDIDDConfigSet().
//
//*****************************************************************************
#define LIDD_CONFIG_SYNC_MPU68  0x00000000
#define LIDD_CONFIG_ASYNC_MPU68 0x00000001
#define LIDD_CONFIG_SYNC_MPU80  0x00000002
#define LIDD_CONFIG_ASYNC_MPU80 0x00000003
#define LIDD_CONFIG_ASYNC_HITACHI                                             \
                                0x00000004
#define LIDD_CONFIG_INVERT_ALE  0x00000008
#define LIDD_CONFIG_INVERT_RS_EN                                              \
                                0x00000010
#define LIDD_CONFIG_INVERT_WS_DIR                                             \
                                0x00000020
#define LIDD_CONFIG_INVERT_CS0  0x00000040
#define LIDD_CONFIG_INVERT_CS1  0x00000080

//*****************************************************************************
//
// Values used to construct the ui32Config parameter to
// LCDRasterConfigSet().  Valid parameters contain one of the RASTER_FMT_xxx
// labels optionally ORed with the other flags.  Only one of
// RASTER_LOAD_DATA_ONLY and RASTER_LOAD_PALETTE_ONLY may be specified (if
// neither is specified, the controller will load both palette and data when
// scanning out the frame buffer).
//
//*****************************************************************************
#define RASTER_FMT_ACTIVE_24BPP_PACKED                                        \
                                0x02000080
#define RASTER_FMT_ACTIVE_24BPP_UNPACKED                                      \
                                0x06000080
#define RASTER_FMT_ACTIVE_PALETTIZED_12BIT                                    \
                                0x00000080
#define RASTER_FMT_ACTIVE_PALETTIZED_16BIT                                    \
                                0x00800080
#define RASTER_FMT_PASSIVE_MONO_4PIX                                          \
                                0x00000002
#define RASTER_FMT_PASSIVE_MONO_8PIX                                          \
                                0x00000202
#define RASTER_FMT_PASSIVE_PALETTIZED                                         \
                                0x00000000
#define RASTER_FMT_PASSIVE_COLOR_12BIT                                        \
                                0x00000000
#define RASTER_FMT_PASSIVE_COLOR_16BIT                                        \
                                0x01000000
#define RASTER_ACTVID_DURING_BLANK                                            \
                                0x08000000
#define RASTER_NIBBLE_MODE_ENABLED                                            \
                                0x00400000
#define RASTER_LOAD_DATA_ONLY   0x00200000
#define RASTER_LOAD_PALETTE_ONLY                                              \
                                0x00100000
#define RASTER_READ_ORDER_REVERSED                                            \
                                0x00000100

//*****************************************************************************
//
// Interrupt sources for the LCD controller.  These may be ORed together and
// passed to LCDIntEnable(), LCDIntDisable() and LCDIntClear().  They are also
// returned by LCDIntStatus().
//
//*****************************************************************************
#define LCD_INT_DMA_DONE        0x00000001
#define LCD_INT_RASTER_FRAME_DONE                                             \
                                0x00000002
#define LCD_INT_SYNC_LOST       0x00000004
#define LCD_INT_AC_BIAS_CNT     0x00000008
#define LCD_INT_UNDERFLOW       0x00000020
#define LCD_INT_PAL_LOAD        0x00000040
#define LCD_INT_EOF0            0x00000100
#define LCD_INT_EOF1            0x00000200

//*****************************************************************************
//
// Configuration values used with LCDDMAConfigSet().
//
//*****************************************************************************
#define LCD_DMA_PRIORITY_0      0x00000000
#define LCD_DMA_PRIORITY_1      0x00010000
#define LCD_DMA_PRIORITY_2      0x00020000
#define LCD_DMA_PRIORITY_3      0x00030000
#define LCD_DMA_PRIORITY_4      0x00040000
#define LCD_DMA_PRIORITY_5      0x00050000
#define LCD_DMA_PRIORITY_6      0x00060000
#define LCD_DMA_PRIORITY_7      0x00070000
#define LCD_DMA_FIFORDY_8_WORDS 0x00000000
#define LCD_DMA_FIFORDY_16_WORDS                                              \
                                0x00000100
#define LCD_DMA_FIFORDY_32_WORDS                                              \
                                0x00000200
#define LCD_DMA_FIFORDY_64_WORDS                                              \
                                0x00000300
#define LCD_DMA_FIFORDY_128_WORDS                                             \
                                0x00000400
#define LCD_DMA_FIFORDY_256_WORDS                                             \
                                0x00000500
#define LCD_DMA_FIFORDY_512_WORDS                                             \
                                0x00000600
#define LCD_DMA_BURST_1         0x00000010
#define LCD_DMA_BURST_2         0x00000010
#define LCD_DMA_BURST_4         0x00000020
#define LCD_DMA_BURST_8         0x00000030
#define LCD_DMA_BURST_16        0x00000040
#define LCD_DMA_BYTE_ORDER_0123 0x00000000
#define LCD_DMA_BYTE_ORDER_1023 0x00000008
#define LCD_DMA_BYTE_ORDER_3210 0x00000002
#define LCD_DMA_BYTE_ORDER_2301 0x0000000A
#define LCD_DMA_PING_PONG       0x00000001

//*****************************************************************************
//
// Type values used with LCDRasterPaletteSet().
//
//*****************************************************************************
#define LCD_PALETTE_TYPE_1BPP   0x00000000
#define LCD_PALETTE_TYPE_2BPP   0x00001000
#define LCD_PALETTE_TYPE_4BPP   0x00002000
#define LCD_PALETTE_TYPE_8BPP   0x00003000
#define LCD_PALETTE_TYPE_DIRECT 0x00004000
#define LCD_PALETTE_SRC_24BIT   0x80000000

//*****************************************************************************
//
// Flags used in the ui32Clocks parameter to LCDClockReset().
//
//*****************************************************************************
#define LCD_CLOCK_MAIN          0x00000008
#define LCD_CLOCK_DMA           0x00000004
#define LCD_CLOCK_LIDD          0x00000002
#define LCD_CLOCK_CORE          0x00000001

//*****************************************************************************
//
// Flags used in with LCDSubPanelConfigSet().
//
//*****************************************************************************
#define LCD_SUBPANEL_AT_TOP     0x20000000
#define LCD_SUBPANEL_AT_BOTTOM  0x00000000

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
// Function Prototypes.
//
//*****************************************************************************
extern uint32_t LCDModeSet(uint32_t ui32Base, uint8_t ui8Mode,
                           uint32_t ui32PixClk, uint32_t ui32SysClk);
extern void LCDClockReset(uint32_t ui32Base, uint32_t ui32Clocks);
extern void LCDIDDConfigSet(uint32_t ui32Base, uint32_t ui32Config);
extern void LCDIDDTimingSet(uint32_t ui32Base, uint32_t ui32CS,
                            const tLCDIDDTiming *pTiming);
extern void LCDIDDDMADisable(uint32_t ui32Base);
extern void LCDIDDCommandWrite(uint32_t ui32Base, uint32_t ui32CS,
                               uint16_t ui16Cmd);
extern void LCDIDDDataWrite(uint32_t ui32Base, uint32_t ui32CS,
                            uint16_t ui16Data);
extern void LCDIDDIndexedWrite(uint32_t ui32Base, uint32_t ui32CS,
                               uint16_t ui16Addr, uint16_t ui16Data);
extern uint16_t LCDIDDStatusRead(uint32_t ui32Base, uint32_t ui32CS);
extern uint16_t LCDIDDDataRead(uint32_t ui32Base, uint32_t ui32CS);
extern uint16_t LCDIDDIndexedRead(uint32_t ui32Base, uint32_t ui32CS,
                                  uint16_t ui16Addr);
extern void LCDIDDDMAWrite(uint32_t ui32Base, uint32_t ui32CS,
                           const uint32_t *pui32Data, uint32_t ui32Count);
extern void LCDRasterConfigSet(uint32_t ui32Base, uint32_t ui32Config,
                               uint8_t ui8PalLoadDelay);
extern void LCDRasterTimingSet(uint32_t ui32Base,
                               const tLCDRasterTiming *pTiming);
extern void LCDRasterACBiasIntCountSet(uint32_t ui32Base, uint8_t ui8Count);
extern void LCDRasterEnable(uint32_t ui32Base);
extern bool LCDRasterEnabled(uint32_t ui32Base);
extern void LCDRasterDisable(uint32_t ui32Base);
extern void LCDRasterSubPanelConfigSet(uint32_t ui32Base, uint32_t ui32Flags,
                                       uint32_t ui32BottomLines,
                                       uint32_t ui32DefaultPixel);
extern void LCDRasterSubPanelEnable(uint32_t ui32Base);
extern void LCDRasterSubPanelDisable(uint32_t ui32Base);
extern void LCDDMAConfigSet(uint32_t ui32Base, uint32_t ui32Config);
extern void LCDRasterPaletteSet(uint32_t ui32Base, uint32_t ui32Type,
                                uint32_t *pui32PalAddr,
                                const uint32_t *pui32SrcColors,
                                uint32_t ui32Start,
                                uint32_t ui32Count);
extern void LCDRasterFrameBufferSet(uint32_t ui32Base, uint8_t ui8Buffer,
                                    uint32_t *pui32Addr,
                                    uint32_t ui32NumBytes);
extern void LCDIntEnable(uint32_t ui32Base, uint32_t ui32IntFlags);
extern void LCDIntDisable(uint32_t ui32Base, uint32_t ui32IntFlags);
extern uint32_t LCDIntStatus(uint32_t ui32Base, bool bMasked);
extern void LCDIntClear(uint32_t ui32Base, uint32_t ui32IntFlags);
extern void LCDIntRegister(uint32_t ui32Base, void (*pfnHandler)(void));
extern void LCDIntUnregister(uint32_t ui32Base);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif // __DRIVERLIB_LCD_H__
