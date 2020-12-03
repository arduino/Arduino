/*****************************************************************************
 *
 * Copyright (C) 2015 Atmel Corporation
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in
 *   the documentation and/or other materials provided with the
 *   distribution.
 *
 * * Neither the name of the copyright holders nor the names of
 *   contributors may be used to endorse or promote products derived
 *   from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 ****************************************************************************/


#ifndef _AVR_IO_H_
#  error "Include <avr/io.h> instead of this file."
#endif

#ifndef _AVR_IOXXX_H_
#  define _AVR_IOXXX_H_ "iox8e5.h"
#else
#  error "Attempt to include more than one <avr/ioXXX.h> file."
#endif

#ifndef _AVR_ATXMEGA8E5_H_INCLUDED
#define _AVR_ATXMEGA8E5_H_INCLUDED

/* Ungrouped common registers */
#define GPIOR0  _SFR_MEM8(0x0000)  /* General Purpose IO Register 0 */
#define GPIOR1  _SFR_MEM8(0x0001)  /* General Purpose IO Register 1 */
#define GPIOR2  _SFR_MEM8(0x0002)  /* General Purpose IO Register 2 */
#define GPIOR3  _SFR_MEM8(0x0003)  /* General Purpose IO Register 3 */

/* Deprecated */
#define GPIO0  _SFR_MEM8(0x0000)  /* General Purpose IO Register 0 */
#define GPIO1  _SFR_MEM8(0x0001)  /* General Purpose IO Register 1 */
#define GPIO2  _SFR_MEM8(0x0002)  /* General Purpose IO Register 2 */
#define GPIO3  _SFR_MEM8(0x0003)  /* General Purpose IO Register 3 */

#define CCP  _SFR_MEM8(0x0034)  /* Configuration Change Protection */
#define RAMPD  _SFR_MEM8(0x0038)  /* Ramp D */
#define RAMPX  _SFR_MEM8(0x0039)  /* Ramp X */
#define RAMPY  _SFR_MEM8(0x003A)  /* Ramp Y */
#define RAMPZ  _SFR_MEM8(0x003B)  /* Ramp Z */
#define EIND  _SFR_MEM8(0x003C)  /* Extended Indirect Jump */
#define SPL  _SFR_MEM8(0x003D)  /* Stack Pointer Low */
#define SPH  _SFR_MEM8(0x003E)  /* Stack Pointer High */
#define SREG  _SFR_MEM8(0x003F)  /* Status Register */

/* C Language Only */
#if !defined (__ASSEMBLER__)

#include <stdint.h>

typedef volatile uint8_t register8_t;
typedef volatile uint16_t register16_t;
typedef volatile uint32_t register32_t;


#ifdef _WORDREGISTER
#undef _WORDREGISTER
#endif
#define _WORDREGISTER(regname)   \
    __extension__ union \
    { \
        register16_t regname; \
        struct \
        { \
            register8_t regname ## L; \
            register8_t regname ## H; \
        }; \
    }

#ifdef _DWORDREGISTER
#undef _DWORDREGISTER
#endif
#define _DWORDREGISTER(regname)  \
    __extension__ union \
    { \
        register32_t regname; \
        struct \
        { \
            register8_t regname ## 0; \
            register8_t regname ## 1; \
            register8_t regname ## 2; \
            register8_t regname ## 3; \
        }; \
    }


/*
==========================================================================
IO Module Structures
==========================================================================
*/


/*
--------------------------------------------------------------------------
VPORT - Virtual Ports
--------------------------------------------------------------------------
*/

/* Virtual Port */
typedef struct VPORT_struct
{
    register8_t DIR;  /* I/O Port Data Direction */
    register8_t OUT;  /* I/O Port Output */
    register8_t IN;  /* I/O Port Input */
    register8_t INTFLAGS;  /* Interrupt Flag Register */
} VPORT_t;


/*
--------------------------------------------------------------------------
XOCD - On-Chip Debug System
--------------------------------------------------------------------------
*/

/* On-Chip Debug System */
typedef struct OCD_struct
{
    register8_t OCDR0;  /* OCD Register 0 */
    register8_t OCDR1;  /* OCD Register 1 */
} OCD_t;


/*
--------------------------------------------------------------------------
CPU - CPU
--------------------------------------------------------------------------
*/

/* CCP signatures */
typedef enum CCP_enum
{
    CCP_SPM_gc = (0x9D<<0),  /* SPM Instruction Protection */
    CCP_IOREG_gc = (0xD8<<0),  /* IO Register Protection */
} CCP_t;


/*
--------------------------------------------------------------------------
CLK - Clock System
--------------------------------------------------------------------------
*/

/* Clock System */
typedef struct CLK_struct
{
    register8_t CTRL;  /* Control Register */
    register8_t PSCTRL;  /* Prescaler Control Register */
    register8_t LOCK;  /* Lock register */
    register8_t RTCCTRL;  /* RTC Control Register */
    register8_t reserved_0x04;
} CLK_t;


/* Power Reduction */
typedef struct PR_struct
{
    register8_t PRGEN;  /* General Power Reduction */
    register8_t PRPA;  /* Power Reduction Port A */
    register8_t reserved_0x02;
    register8_t PRPC;  /* Power Reduction Port C */
    register8_t PRPD;  /* Power Reduction Port D */
    register8_t reserved_0x05;
    register8_t reserved_0x06;
} PR_t;

/* System Clock Selection */
typedef enum CLK_SCLKSEL_enum
{
    CLK_SCLKSEL_RC2M_gc = (0x00<<0),  /* Internal 2 MHz RC Oscillator */
    CLK_SCLKSEL_RC32M_gc = (0x01<<0),  /* Internal 32 MHz RC Oscillator */
    CLK_SCLKSEL_RC32K_gc = (0x02<<0),  /* Internal 32.768 kHz RC Oscillator */
    CLK_SCLKSEL_XOSC_gc = (0x03<<0),  /* External Crystal Oscillator or Clock */
    CLK_SCLKSEL_PLL_gc = (0x04<<0),  /* Phase Locked Loop */
    CLK_SCLKSEL_RC8M_gc = (0x05<<0),  /* Internal 8 MHz RC Oscillator */
} CLK_SCLKSEL_t;

/* Prescaler A Division Factor */
typedef enum CLK_PSADIV_enum
{
    CLK_PSADIV_1_gc = (0x00<<2),  /* Divide by 1 */
    CLK_PSADIV_2_gc = (0x01<<2),  /* Divide by 2 */
    CLK_PSADIV_4_gc = (0x03<<2),  /* Divide by 4 */
    CLK_PSADIV_8_gc = (0x05<<2),  /* Divide by 8 */
    CLK_PSADIV_16_gc = (0x07<<2),  /* Divide by 16 */
    CLK_PSADIV_32_gc = (0x09<<2),  /* Divide by 32 */
    CLK_PSADIV_64_gc = (0x0B<<2),  /* Divide by 64 */
    CLK_PSADIV_128_gc = (0x0D<<2),  /* Divide by 128 */
    CLK_PSADIV_256_gc = (0x0F<<2),  /* Divide by 256 */
    CLK_PSADIV_512_gc = (0x11<<2),  /* Divide by 512 */
    CLK_PSADIV_6_gc = (0x13<<2),  /* Divide by 6 */
    CLK_PSADIV_10_gc = (0x15<<2),  /* Divide by 10 */
    CLK_PSADIV_12_gc = (0x17<<2),  /* Divide by 12 */
    CLK_PSADIV_24_gc = (0x19<<2),  /* Divide by 24 */
    CLK_PSADIV_48_gc = (0x1B<<2),  /* Divide by 48 */
} CLK_PSADIV_t;

/* Prescaler B and C Division Factor */
typedef enum CLK_PSBCDIV_enum
{
    CLK_PSBCDIV_1_1_gc = (0x00<<0),  /* Divide B by 1 and C by 1 */
    CLK_PSBCDIV_1_2_gc = (0x01<<0),  /* Divide B by 1 and C by 2 */
    CLK_PSBCDIV_4_1_gc = (0x02<<0),  /* Divide B by 4 and C by 1 */
    CLK_PSBCDIV_2_2_gc = (0x03<<0),  /* Divide B by 2 and C by 2 */
} CLK_PSBCDIV_t;

/* RTC Clock Source */
typedef enum CLK_RTCSRC_enum
{
    CLK_RTCSRC_ULP_gc = (0x00<<1),  /* 1.024 kHz from internal 32kHz ULP */
    CLK_RTCSRC_TOSC_gc = (0x01<<1),  /* 1.024 kHz from 32.768 kHz crystal oscillator on TOSC */
    CLK_RTCSRC_RCOSC_gc = (0x02<<1),  /* 1.024 kHz from internal 32.768 kHz RC oscillator */
    CLK_RTCSRC_TOSC32_gc = (0x05<<1),  /* 32.768 kHz from 32.768 kHz crystal oscillator on TOSC */
    CLK_RTCSRC_RCOSC32_gc = (0x06<<1),  /* 32.768 kHz from internal 32.768 kHz RC oscillator */
    CLK_RTCSRC_EXTCLK_gc = (0x07<<1),  /* External Clock from TOSC1 */
} CLK_RTCSRC_t;


/*
--------------------------------------------------------------------------
SLEEP - Sleep Controller
--------------------------------------------------------------------------
*/

/* Sleep Controller */
typedef struct SLEEP_struct
{
    register8_t CTRL;  /* Control Register */
} SLEEP_t;

/* Sleep Mode */
typedef enum SLEEP_SMODE_enum
{
    SLEEP_SMODE_IDLE_gc = (0x00<<1),  /* Idle mode */
    SLEEP_SMODE_PDOWN_gc = (0x02<<1),  /* Power-down Mode */
    SLEEP_SMODE_PSAVE_gc = (0x03<<1),  /* Power-save Mode */
    SLEEP_SMODE_STDBY_gc = (0x06<<1),  /* Standby Mode */
    SLEEP_SMODE_ESTDBY_gc = (0x07<<1),  /* Extended Standby Mode */
} SLEEP_SMODE_t;



#define SLEEP_MODE_IDLE (0x00<<1)
#define SLEEP_MODE_PWR_DOWN (0x02<<1)
#define SLEEP_MODE_PWR_SAVE (0x03<<1)
#define SLEEP_MODE_STANDBY (0x06<<1)
#define SLEEP_MODE_EXT_STANDBY (0x07<<1)
/*
--------------------------------------------------------------------------
OSC - Oscillator
--------------------------------------------------------------------------
*/

/* Oscillator */
typedef struct OSC_struct
{
    register8_t CTRL;  /* Control Register */
    register8_t STATUS;  /* Status Register */
    register8_t XOSCCTRL;  /* External Oscillator Control Register */
    register8_t XOSCFAIL;  /* Oscillator Failure Detection Register */
    register8_t RC32KCAL;  /* 32.768 kHz Internal Oscillator Calibration Register */
    register8_t PLLCTRL;  /* PLL Control Register */
    register8_t DFLLCTRL;  /* DFLL Control Register */
    register8_t RC8MCAL;  /* Internal 8 MHz RC Oscillator Calibration Register */
} OSC_t;

/* Oscillator Frequency Range */
typedef enum OSC_FRQRANGE_enum
{
    OSC_FRQRANGE_04TO2_gc = (0x00<<6),  /* 0.4 - 2 MHz */
    OSC_FRQRANGE_2TO9_gc = (0x01<<6),  /* 2 - 9 MHz */
    OSC_FRQRANGE_9TO12_gc = (0x02<<6),  /* 9 - 12 MHz */
    OSC_FRQRANGE_12TO16_gc = (0x03<<6),  /* 12 - 16 MHz */
} OSC_FRQRANGE_t;

/* External Oscillator Selection and Startup Time */
typedef enum OSC_XOSCSEL_enum
{
    OSC_XOSCSEL_EXTCLK_gc = (0x00<<0),  /* External Clock on port R1 - 6 CLK */
    OSC_XOSCSEL_32KHz_gc = (0x02<<0),  /* 32.768 kHz TOSC - 32K CLK */
    OSC_XOSCSEL_XTAL_256CLK_gc = (0x03<<0),  /* 0.4-16 MHz XTAL - 256 CLK */
    OSC_XOSCSEL_XTAL_1KCLK_gc = (0x07<<0),  /* 0.4-16 MHz XTAL - 1K CLK */
    OSC_XOSCSEL_XTAL_16KCLK_gc = (0x0B<<0),  /* 0.4-16 MHz XTAL - 16K CLK */
    OSC_XOSCSEL_EXTCLK_C4_gc = (0x14<<0),  /* External Clock on port C4 - 6 CLK */
} OSC_XOSCSEL_t;

/* PLL Clock Source */
typedef enum OSC_PLLSRC_enum
{
    OSC_PLLSRC_RC2M_gc = (0x00<<6),  /* Internal 2 MHz RC Oscillator */
    OSC_PLLSRC_RC8M_gc = (0x01<<6),  /* Internal 8 MHz RC Oscillator */
    OSC_PLLSRC_RC32M_gc = (0x02<<6),  /* Internal 32 MHz RC Oscillator */
    OSC_PLLSRC_XOSC_gc = (0x03<<6),  /* External Oscillator */
} OSC_PLLSRC_t;

/* 32 MHz DFLL Calibration Reference */
typedef enum OSC_RC32MCREF_enum
{
    OSC_RC32MCREF_RC32K_gc = (0x00<<1),  /* Internal 32.768 kHz RC Oscillator */
    OSC_RC32MCREF_XOSC32K_gc = (0x01<<1),  /* External 32.768 kHz Crystal Oscillator */
} OSC_RC32MCREF_t;


/*
--------------------------------------------------------------------------
DFLL - DFLL
--------------------------------------------------------------------------
*/

/* DFLL */
typedef struct DFLL_struct
{
    register8_t CTRL;  /* Control Register */
    register8_t reserved_0x01;
    register8_t CALA;  /* Calibration Register A */
    register8_t CALB;  /* Calibration Register B */
    register8_t COMP0;  /* Oscillator Compare Register 0 */
    register8_t COMP1;  /* Oscillator Compare Register 1 */
    register8_t COMP2;  /* Oscillator Compare Register 2 */
    register8_t reserved_0x07;
} DFLL_t;


/*
--------------------------------------------------------------------------
RST - Reset
--------------------------------------------------------------------------
*/

/* Reset */
typedef struct RST_struct
{
    register8_t STATUS;  /* Status Register */
    register8_t CTRL;  /* Control Register */
} RST_t;


/*
--------------------------------------------------------------------------
WDT - Watch-Dog Timer
--------------------------------------------------------------------------
*/

/* Watch-Dog Timer */
typedef struct WDT_struct
{
    register8_t CTRL;  /* Control */
    register8_t WINCTRL;  /* Windowed Mode Control */
    register8_t STATUS;  /* Status */
} WDT_t;

/* Period setting */
typedef enum WDT_PER_enum
{
    WDT_PER_8CLK_gc = (0x00<<2),  /* 8 cycles (8ms @ 3.3V) */
    WDT_PER_16CLK_gc = (0x01<<2),  /* 16 cycles (16ms @ 3.3V) */
    WDT_PER_32CLK_gc = (0x02<<2),  /* 32 cycles (32ms @ 3.3V) */
    WDT_PER_64CLK_gc = (0x03<<2),  /* 64 cycles (64ms @ 3.3V) */
    WDT_PER_128CLK_gc = (0x04<<2),  /* 128 cycles (0.128s @ 3.3V) */
    WDT_PER_256CLK_gc = (0x05<<2),  /* 256 cycles (0.256s @ 3.3V) */
    WDT_PER_512CLK_gc = (0x06<<2),  /* 512 cycles (0.512s @ 3.3V) */
    WDT_PER_1KCLK_gc = (0x07<<2),  /* 1K cycles (1s @ 3.3V) */
    WDT_PER_2KCLK_gc = (0x08<<2),  /* 2K cycles (2s @ 3.3V) */
    WDT_PER_4KCLK_gc = (0x09<<2),  /* 4K cycles (4s @ 3.3V) */
    WDT_PER_8KCLK_gc = (0x0A<<2),  /* 8K cycles (8s @ 3.3V) */
} WDT_PER_t;

/* Closed window period */
typedef enum WDT_WPER_enum
{
    WDT_WPER_8CLK_gc = (0x00<<2),  /* 8 cycles (8ms @ 3.3V) */
    WDT_WPER_16CLK_gc = (0x01<<2),  /* 16 cycles (16ms @ 3.3V) */
    WDT_WPER_32CLK_gc = (0x02<<2),  /* 32 cycles (32ms @ 3.3V) */
    WDT_WPER_64CLK_gc = (0x03<<2),  /* 64 cycles (64ms @ 3.3V) */
    WDT_WPER_128CLK_gc = (0x04<<2),  /* 128 cycles (0.128s @ 3.3V) */
    WDT_WPER_256CLK_gc = (0x05<<2),  /* 256 cycles (0.256s @ 3.3V) */
    WDT_WPER_512CLK_gc = (0x06<<2),  /* 512 cycles (0.512s @ 3.3V) */
    WDT_WPER_1KCLK_gc = (0x07<<2),  /* 1K cycles (1s @ 3.3V) */
    WDT_WPER_2KCLK_gc = (0x08<<2),  /* 2K cycles (2s @ 3.3V) */
    WDT_WPER_4KCLK_gc = (0x09<<2),  /* 4K cycles (4s @ 3.3V) */
    WDT_WPER_8KCLK_gc = (0x0A<<2),  /* 8K cycles (8s @ 3.3V) */
} WDT_WPER_t;


/*
--------------------------------------------------------------------------
MCU - MCU Control
--------------------------------------------------------------------------
*/

/* MCU Control */
typedef struct MCU_struct
{
    register8_t DEVID0;  /* Device ID byte 0 */
    register8_t DEVID1;  /* Device ID byte 1 */
    register8_t DEVID2;  /* Device ID byte 2 */
    register8_t REVID;  /* Revision ID */
    register8_t reserved_0x04;
    register8_t reserved_0x05;
    register8_t reserved_0x06;
    register8_t ANAINIT;  /* Analog Startup Delay */
    register8_t EVSYSLOCK;  /* Event System Lock */
    register8_t WEXLOCK;  /* WEX Lock */
    register8_t FAULTLOCK;  /* FAULT Lock */
    register8_t reserved_0x0B;
} MCU_t;


/*
--------------------------------------------------------------------------
PMIC - Programmable Multi-level Interrupt Controller
--------------------------------------------------------------------------
*/

/* Programmable Multi-level Interrupt Controller */
typedef struct PMIC_struct
{
    register8_t STATUS;  /* Status Register */
    register8_t INTPRI;  /* Interrupt Priority */
    register8_t CTRL;  /* Control Register */
    register8_t reserved_0x03;
    register8_t reserved_0x04;
    register8_t reserved_0x05;
    register8_t reserved_0x06;
    register8_t reserved_0x07;
    register8_t reserved_0x08;
    register8_t reserved_0x09;
    register8_t reserved_0x0A;
    register8_t reserved_0x0B;
    register8_t reserved_0x0C;
    register8_t reserved_0x0D;
    register8_t reserved_0x0E;
    register8_t reserved_0x0F;
} PMIC_t;


/*
--------------------------------------------------------------------------
PORTCFG - Port Configuration
--------------------------------------------------------------------------
*/

/* I/O port Configuration */
typedef struct PORTCFG_struct
{
    register8_t MPCMASK;  /* Multi-pin Configuration Mask */
    register8_t reserved_0x01;
    register8_t reserved_0x02;
    register8_t reserved_0x03;
    register8_t CLKOUT;  /* Clock Out Register */
    register8_t reserved_0x05;
    register8_t ACEVOUT;  /* Analog Comparator and Event Out Register */
    register8_t SRLCTRL;  /* Slew Rate Limit Control Register */
} PORTCFG_t;

/* Clock and Event Output Port */
typedef enum PORTCFG_CLKEVPIN_enum
{
    PORTCFG_CLKEVPIN_PIN7_gc = (0x00<<7),  /* Clock and Event Ouput on PIN 7 */
    PORTCFG_CLKEVPIN_PIN4_gc = (0x01<<7),  /* Clock and Event Ouput on PIN 4 */
} PORTCFG_CLKEVPIN_t;

/* RTC Clock Output Port */
typedef enum PORTCFG_RTCCLKOUT_enum
{
    PORTCFG_RTCCLKOUT_OFF_gc = (0x00<<5),  /* System Clock Output Disabled */
    PORTCFG_RTCCLKOUT_PC6_gc = (0x01<<5),  /* System Clock Output on Port C pin 6 */
    PORTCFG_RTCCLKOUT_PD6_gc = (0x02<<5),  /* System Clock Output on Port D pin 6 */
    PORTCFG_RTCCLKOUT_PR0_gc = (0x03<<5),  /* System Clock Output on Port R pin 0 */
} PORTCFG_RTCCLKOUT_t;

/* Peripheral Clock Output Select */
typedef enum PORTCFG_CLKOUTSEL_enum
{
    PORTCFG_CLKOUTSEL_CLK1X_gc = (0x00<<2),  /* 1x Peripheral Clock Output to pin */
    PORTCFG_CLKOUTSEL_CLK2X_gc = (0x01<<2),  /* 2x Peripheral Clock Output to pin */
    PORTCFG_CLKOUTSEL_CLK4X_gc = (0x02<<2),  /* 4x Peripheral Clock Output to pin */
} PORTCFG_CLKOUTSEL_t;

/* System Clock Output Port */
typedef enum PORTCFG_CLKOUT_enum
{
    PORTCFG_CLKOUT_OFF_gc = (0x00<<0),  /* System Clock Output Disabled */
    PORTCFG_CLKOUT_PC7_gc = (0x01<<0),  /* System Clock Output on Port C pin 7 */
    PORTCFG_CLKOUT_PD7_gc = (0x02<<0),  /* System Clock Output on Port D pin 7 */
    PORTCFG_CLKOUT_PR0_gc = (0x03<<0),  /* System Clock Output on Port R pin 0 */
} PORTCFG_CLKOUT_t;

/* Analog Comparator Output Port */
typedef enum PORTCFG_ACOUT_enum
{
    PORTCFG_ACOUT_PA_gc = (0x00<<6),  /* Analog Comparator Outputs on Port A, Pin 6-7 */
    PORTCFG_ACOUT_PC_gc = (0x01<<6),  /* Analog Comparator Outputs on Port C, Pin 6-7 */
    PORTCFG_ACOUT_PD_gc = (0x02<<6),  /* Analog Comparator Outputs on Port D, Pin 6-7 */
    PORTCFG_ACOUT_PR_gc = (0x03<<6),  /* Analog Comparator Outputs on Port R, Pin 0-1 */
} PORTCFG_ACOUT_t;

/* Event Output Port */
typedef enum PORTCFG_EVOUT_enum
{
    PORTCFG_EVOUT_OFF_gc = (0x00<<4),  /* Event Output Disabled */
    PORTCFG_EVOUT_PC7_gc = (0x01<<4),  /* Event Channel n Output on Port C pin 7 */
    PORTCFG_EVOUT_PD7_gc = (0x02<<4),  /* Event Channel n Output on Port D pin 7 */
    PORTCFG_EVOUT_PR0_gc = (0x03<<4),  /* Event Channel n Output on Port R pin 0 */
} PORTCFG_EVOUT_t;

/* Event Output Select */
typedef enum PORTCFG_EVOUTSEL_enum
{
    PORTCFG_EVOUTSEL_0_gc = (0x00<<0),  /* Event Channel 0 output to pin */
    PORTCFG_EVOUTSEL_1_gc = (0x01<<0),  /* Event Channel 1 output to pin */
    PORTCFG_EVOUTSEL_2_gc = (0x02<<0),  /* Event Channel 2 output to pin */
    PORTCFG_EVOUTSEL_3_gc = (0x03<<0),  /* Event Channel 3 output to pin */
    PORTCFG_EVOUTSEL_4_gc = (0x04<<0),  /* Event Channel 4 output to pin */
    PORTCFG_EVOUTSEL_5_gc = (0x05<<0),  /* Event Channel 5 output to pin */
    PORTCFG_EVOUTSEL_6_gc = (0x06<<0),  /* Event Channel 6 output to pin */
    PORTCFG_EVOUTSEL_7_gc = (0x07<<0),  /* Event Channel 7 output to pin */
} PORTCFG_EVOUTSEL_t;


/*
--------------------------------------------------------------------------
CRC - Cyclic Redundancy Checker
--------------------------------------------------------------------------
*/

/* Cyclic Redundancy Checker */
typedef struct CRC_struct
{
    register8_t CTRL;  /* Control Register */
    register8_t STATUS;  /* Status Register */
    register8_t reserved_0x02;
    register8_t DATAIN;  /* Data Input */
    register8_t CHECKSUM0;  /* Checksum byte 0 */
    register8_t CHECKSUM1;  /* Checksum byte 1 */
    register8_t CHECKSUM2;  /* Checksum byte 2 */
    register8_t CHECKSUM3;  /* Checksum byte 3 */
} CRC_t;

/* Reset */
typedef enum CRC_RESET_enum
{
    CRC_RESET_NO_gc = (0x00<<6),  /* No Reset */
    CRC_RESET_RESET0_gc = (0x02<<6),  /* Reset CRC with CHECKSUM to all zeros */
    CRC_RESET_RESET1_gc = (0x03<<6),  /* Reset CRC with CHECKSUM to all ones */
} CRC_RESET_t;

/* Input Source */
typedef enum CRC_SOURCE_enum
{
    CRC_SOURCE_DISABLE_gc = (0x00<<0),  /* Disabled */
    CRC_SOURCE_IO_gc = (0x01<<0),  /* I/O Interface */
    CRC_SOURCE_FLASH_gc = (0x02<<0),  /* Flash */
    CRC_SOURCE_DMAC0_gc = (0x04<<0),  /* DMAC Channel 0 */
    CRC_SOURCE_DMAC1_gc = (0x05<<0),  /* DMAC Channel 1 */
    CRC_SOURCE_DMAC2_gc = (0x06<<0),  /* DMAC Channel 2 */
    CRC_SOURCE_DMAC3_gc = (0x07<<0),  /* DMAC Channel 3 */
} CRC_SOURCE_t;


/*
--------------------------------------------------------------------------
EDMA - Enhanced DMA Controller
--------------------------------------------------------------------------
*/

/* EDMA Channel */
typedef struct EDMA_CH_struct
{
    register8_t CTRLA;  /* Channel Control A */
    register8_t CTRLB;  /* Channel Control */
    register8_t ADDRCTRL;  /* Memory Address Control for Peripheral Ch., or Source Address Control for Standard Ch. */
    register8_t DESTADDRCTRL;  /* Destination Address Control for Standard Channels Only. */
    register8_t TRIGSRC;  /* Channel Trigger Source */
    register8_t reserved_0x05;
    _WORDREGISTER(TRFCNT);  /* Channel Block Transfer Count for Peripheral Ch., or Channel Block Transfer Count Low for Standard Ch. */
    _WORDREGISTER(ADDR);  /* Channel Memory Address for Peripheral Ch., or Channel Source Address Low for Standard Ch. */
    register8_t reserved_0x0A;
    register8_t reserved_0x0B;
    _WORDREGISTER(DESTADDR);  /* Channel Destination Address for Standard Channels Only. */
    register8_t reserved_0x0E;
    register8_t reserved_0x0F;
} EDMA_CH_t;


/* Enhanced DMA Controller */
typedef struct EDMA_struct
{
    register8_t CTRL;  /* Control */
    register8_t reserved_0x01;
    register8_t reserved_0x02;
    register8_t INTFLAGS;  /* Transfer Interrupt Status */
    register8_t STATUS;  /* Status */
    register8_t reserved_0x05;
    register8_t TEMP;  /* Temporary Register For 16-bit Access */
    register8_t reserved_0x07;
    register8_t reserved_0x08;
    register8_t reserved_0x09;
    register8_t reserved_0x0A;
    register8_t reserved_0x0B;
    register8_t reserved_0x0C;
    register8_t reserved_0x0D;
    register8_t reserved_0x0E;
    register8_t reserved_0x0F;
    EDMA_CH_t CH0;  /* EDMA Channel 0 */
    EDMA_CH_t CH1;  /* EDMA Channel 1 */
    EDMA_CH_t CH2;  /* EDMA Channel 2 */
    EDMA_CH_t CH3;  /* EDMA Channel 3 */
} EDMA_t;

/* Channel mode */
typedef enum EDMA_CHMODE_enum
{
    EDMA_CHMODE_PER0123_gc = (0x00<<4),  /* Channels 0, 1, 2 and 3 in peripheal conf. */
    EDMA_CHMODE_STD0_gc = (0x01<<4),  /* Channel 0 in standard conf.; channels 2 and 3 in peripheral conf. */
    EDMA_CHMODE_STD2_gc = (0x02<<4),  /* Channel 2 in standard conf.; channels 0 and 1 in peripheral conf. */
    EDMA_CHMODE_STD02_gc = (0x03<<4),  /* Channels 0 and 2 in standard conf. */
} EDMA_CHMODE_t;

/* Double buffer mode */
typedef enum EDMA_DBUFMODE_enum
{
    EDMA_DBUFMODE_DISABLE_gc = (0x00<<2),  /* No double buffer enabled */
    EDMA_DBUFMODE_BUF01_gc = (0x01<<2),  /* Double buffer enabled on peripheral channels 0/1 (if exist)  */
    EDMA_DBUFMODE_BUF23_gc = (0x02<<2),  /* Double buffer enabled on peripheral channels 2/3 (if exist) */
    EDMA_DBUFMODE_BUF0123_gc = (0x03<<2),  /* Double buffer enabled on peripheral channels 0/1 and 2/3 or standard channels 0/2 */
} EDMA_DBUFMODE_t;

/* Priority mode */
typedef enum EDMA_PRIMODE_enum
{
    EDMA_PRIMODE_RR0123_gc = (0x00<<0),  /* Round robin on all channels */
    EDMA_PRIMODE_RR123_gc = (0x01<<0),  /* Ch0 > round robin (Ch 1 ch2 Ch3) */
    EDMA_PRIMODE_RR23_gc = (0x02<<0),  /* Ch0 > Ch 1 > round robin (Ch2 Ch3) */
    EDMA_PRIMODE_CH0123_gc = (0x03<<0),  /* Ch0 > Ch1 > Ch2 > Ch3  */
} EDMA_PRIMODE_t;

/* Memory Address Reload for Peripheral Ch., or Source Address Reload for Standard Ch. */
typedef enum EDMA_CH_RELOAD_enum
{
    EDMA_CH_RELOAD_NONE_gc = (0x00<<4),  /* No reload */
    EDMA_CH_RELOAD_BLOCK_gc = (0x01<<4),  /* Reload at end of each block transfer */
    EDMA_CH_RELOAD_BURST_gc = (0x02<<4),  /* Reload at end of each burst transfer */
    EDMA_CH_RELOAD_TRANSACTION_gc = (0x03<<4),  /* Reload at end of each transaction */
} EDMA_CH_RELOAD_t;

/* Memory Address Mode for Peripheral Ch., or Source Address Mode for Standard Ch. */
typedef enum EDMA_CH_DIR_enum
{
    EDMA_CH_DIR_FIXED_gc = (0x00<<0),  /* Fixed */
    EDMA_CH_DIR_INC_gc = (0x01<<0),  /* Increment */
    EDMA_CH_DIR_MP1_gc = (0x04<<0),  /* If Peripheral Ch. (Per ==> Mem), 1-byte 'mask-match' (data: ADDRL, mask: ADDRH), else reserved conf.  */
    EDMA_CH_DIR_MP2_gc = (0x05<<0),  /* If Peripheral Ch. (Per ==> Mem), 1-byte 'OR-match' (data-1: ADDRL OR data-2: ADDRH), else reserved conf.  */
    EDMA_CH_DIR_MP3_gc = (0x06<<0),  /* If Peripheral Ch. (Per ==> Mem), 2-byte 'match' (data-1: ADDRL followed by data-2: ADDRH), else reserved conf.  */
} EDMA_CH_DIR_t;

/* Destination addressing mode */
typedef enum EDMA_CH_DESTDIR_enum
{
    EDMA_CH_DESTDIR_FIXED_gc = (0x00<<0),  /* Fixed */
    EDMA_CH_DESTDIR_INC_gc = (0x01<<0),  /* Increment */
    EDMA_CH_DESTDIR_MP1_gc = (0x04<<0),  /* 1-byte 'mask-match' (data: ADDRL, mask: ADDRH) */
    EDMA_CH_DESTDIR_MP2_gc = (0x05<<0),  /* 1-byte 'OR-match' (data-1: ADDRL OR data-2: ADDRH) */
    EDMA_CH_DESTDIR_MP3_gc = (0x06<<0),  /* 2-byte 'match' (data1: ADDRL followed by data2: ADDRH) */
} EDMA_CH_DESTDIR_t;

/* Transfer trigger source */
typedef enum EDMA_CH_TRIGSRC_enum
{
    EDMA_CH_TRIGSRC_OFF_gc = (0x00<<0),  /* Software triggers only */
    EDMA_CH_TRIGSRC_EVSYS_CH0_gc = (0x01<<0),  /* Event CH0 as trigger (Standard Channels Only) */
    EDMA_CH_TRIGSRC_EVSYS_CH1_gc = (0x02<<0),  /* Event CH1 as trigger (Standard Channels Only) */
    EDMA_CH_TRIGSRC_EVSYS_CH2_gc = (0x03<<0),  /* Event CH2 as trigger (Standard Channels Only) */
    EDMA_CH_TRIGSRC_ADCA_CH0_gc = (0x10<<0),  /* ADCA CH0 as trigger */
    EDMA_CH_TRIGSRC_DACA_CH0_gc = (0x15<<0),  /* DACA CH0 as trigger */
    EDMA_CH_TRIGSRC_DACA_CH1_gc = (0x16<<0),  /* DACA CH1 as trigger */
    EDMA_CH_TRIGSRC_TCC4_OVF_gc = (0x40<<0),  /* TCC4 overflow/underflow as trigger (Standard Channels Only) */
    EDMA_CH_TRIGSRC_TCC4_ERR_gc = (0x41<<0),  /* TCC4 error as trigger (Standard Channels Only) */
    EDMA_CH_TRIGSRC_TCC4_CCA_gc = (0x42<<0),  /* TCC4 compare or capture channel A as trigger (Standard Channels Only) */
    EDMA_CH_TRIGSRC_TCC4_CCB_gc = (0x43<<0),  /* TCC4 compare or capture channel B as trigger (Standard Channels Only) */
    EDMA_CH_TRIGSRC_TCC4_CCC_gc = (0x44<<0),  /* TCC4 compare or capture channel C as trigger (Standard Channels Only) */
    EDMA_CH_TRIGSRC_TCC4_CCD_gc = (0x45<<0),  /* TCC4 compare or capture channel D as trigger (Standard Channels Only) */
    EDMA_CH_TRIGSRC_TCC5_OVF_gc = (0x46<<0),  /* TCC5 overflow/underflow as trigger (Standard Channels Only) */
    EDMA_CH_TRIGSRC_TCC5_ERR_gc = (0x47<<0),  /* TCC5 error as trigger (Standard Channels Only) */
    EDMA_CH_TRIGSRC_TCC5_CCA_gc = (0x48<<0),  /* TCC5 compare or capture channel A as trigger (Standard Channels Only) */
    EDMA_CH_TRIGSRC_TCC5_CCB_gc = (0x49<<0),  /* TCC5 compare or capture channel B as trigger (Standard Channels Only) */
    EDMA_CH_TRIGSRC_SPIC_RXC_gc = (0x4A<<0),  /* SPI C transfer complete (SPI Standard Mode) or SPI C receive complete as trigger (SPI Buffer Modes) */
    EDMA_CH_TRIGSRC_SPIC_DRE_gc = (0x4B<<0),  /* SPI C transfer complete (SPI Standard Mode) or SPI C data register empty as trigger (SPI Buffer modes) */
    EDMA_CH_TRIGSRC_USARTC0_RXC_gc = (0x4C<<0),  /* USART C0 receive complete as trigger */
    EDMA_CH_TRIGSRC_USARTC0_DRE_gc = (0x4D<<0),  /* USART C0 data register empty as trigger */
    EDMA_CH_TRIGSRC_TCD5_OVF_gc = (0x66<<0),  /* TCD5 overflow/underflow as trigger (Standard Channels Only) */
    EDMA_CH_TRIGSRC_TCD5_ERR_gc = (0x67<<0),  /* TCD5 error as trigger (Standard Channels Only) */
    EDMA_CH_TRIGSRC_TCD5_CCA_gc = (0x68<<0),  /* TCD5 compare or capture channel A as trigger (Standard Channels Only) */
    EDMA_CH_TRIGSRC_TCD5_CCB_gc = (0x69<<0),  /* TCD5 compare or capture channel B as trigger (Standard Channels Only) */
    EDMA_CH_TRIGSRC_USARTD0_RXC_gc = (0x6C<<0),  /* USART D0 receive complete as trigger */
    EDMA_CH_TRIGSRC_USARTD0_DRE_gc = (0x6D<<0),  /* USART D0 data register empty as trigger */
} EDMA_CH_TRIGSRC_t;

/* Interrupt level */
typedef enum EDMA_CH_INTLVL_enum
{
    EDMA_CH_INTLVL_OFF_gc = (0x00<<2),  /* Interrupt disabled */
    EDMA_CH_INTLVL_LO_gc = (0x01<<2),  /* Low level */
    EDMA_CH_INTLVL_MED_gc = (0x02<<2),  /* Medium level */
    EDMA_CH_INTLVL_HI_gc = (0x03<<2),  /* High level */
} EDMA_CH_INTLVL_t;


/*
--------------------------------------------------------------------------
EVSYS - Event System
--------------------------------------------------------------------------
*/

/* Event System */
typedef struct EVSYS_struct
{
    register8_t CH0MUX;  /* Event Channel 0 Multiplexer */
    register8_t CH1MUX;  /* Event Channel 1 Multiplexer */
    register8_t CH2MUX;  /* Event Channel 2 Multiplexer */
    register8_t CH3MUX;  /* Event Channel 3 Multiplexer */
    register8_t CH4MUX;  /* Event Channel 4 Multiplexer */
    register8_t CH5MUX;  /* Event Channel 5 Multiplexer */
    register8_t CH6MUX;  /* Event Channel 6 Multiplexer */
    register8_t CH7MUX;  /* Event Channel 7 Multiplexer */
    register8_t CH0CTRL;  /* Channel 0 Control Register */
    register8_t CH1CTRL;  /* Channel 1 Control Register */
    register8_t CH2CTRL;  /* Channel 2 Control Register */
    register8_t CH3CTRL;  /* Channel 3 Control Register */
    register8_t CH4CTRL;  /* Channel 4 Control Register */
    register8_t CH5CTRL;  /* Channel 5 Control Register */
    register8_t CH6CTRL;  /* Channel 6 Control Register */
    register8_t CH7CTRL;  /* Channel 7 Control Register */
    register8_t STROBE;  /* Event Strobe */
    register8_t DATA;  /* Event Data */
    register8_t DFCTRL;  /* Digital Filter Control Register */
} EVSYS_t;

/* Event Channel multiplexer input selection */
typedef enum EVSYS_CHMUX_enum
{
    EVSYS_CHMUX_OFF_gc = (0x00<<0),  /* Off */
    EVSYS_CHMUX_RTC_OVF_gc = (0x08<<0),  /* RTC Overflow */
    EVSYS_CHMUX_RTC_CMP_gc = (0x09<<0),  /* RTC Compare Match */
    EVSYS_CHMUX_ACA_CH0_gc = (0x10<<0),  /* Analog Comparator A Channel 0 */
    EVSYS_CHMUX_ACA_CH1_gc = (0x11<<0),  /* Analog Comparator A Channel 1 */
    EVSYS_CHMUX_ACA_WIN_gc = (0x12<<0),  /* Analog Comparator A Window */
    EVSYS_CHMUX_ADCA_CH0_gc = (0x20<<0),  /* ADC A Channel 0 */
    EVSYS_CHMUX_PORTA_PIN0_gc = (0x50<<0),  /* Port A, Pin0 */
    EVSYS_CHMUX_PORTA_PIN1_gc = (0x51<<0),  /* Port A, Pin1 */
    EVSYS_CHMUX_PORTA_PIN2_gc = (0x52<<0),  /* Port A, Pin2 */
    EVSYS_CHMUX_PORTA_PIN3_gc = (0x53<<0),  /* Port A, Pin3 */
    EVSYS_CHMUX_PORTA_PIN4_gc = (0x54<<0),  /* Port A, Pin4 */
    EVSYS_CHMUX_PORTA_PIN5_gc = (0x55<<0),  /* Port A, Pin5 */
    EVSYS_CHMUX_PORTA_PIN6_gc = (0x56<<0),  /* Port A, Pin6 */
    EVSYS_CHMUX_PORTA_PIN7_gc = (0x57<<0),  /* Port A, Pin7 */
    EVSYS_CHMUX_PORTC_PIN0_gc = (0x60<<0),  /* Port C, Pin0 */
    EVSYS_CHMUX_PORTC_PIN1_gc = (0x61<<0),  /* Port C, Pin1 */
    EVSYS_CHMUX_PORTC_PIN2_gc = (0x62<<0),  /* Port C, Pin2 */
    EVSYS_CHMUX_PORTC_PIN3_gc = (0x63<<0),  /* Port C, Pin3 */
    EVSYS_CHMUX_PORTC_PIN4_gc = (0x64<<0),  /* Port C, Pin4 */
    EVSYS_CHMUX_PORTC_PIN5_gc = (0x65<<0),  /* Port C, Pin5 */
    EVSYS_CHMUX_PORTC_PIN6_gc = (0x66<<0),  /* Port C, Pin6 */
    EVSYS_CHMUX_PORTC_PIN7_gc = (0x67<<0),  /* Port C, Pin7 */
    EVSYS_CHMUX_PORTD_PIN0_gc = (0x68<<0),  /* Port D, Pin0 */
    EVSYS_CHMUX_PORTD_PIN1_gc = (0x69<<0),  /* Port D, Pin1 */
    EVSYS_CHMUX_PORTD_PIN2_gc = (0x6A<<0),  /* Port D, Pin2 */
    EVSYS_CHMUX_PORTD_PIN3_gc = (0x6B<<0),  /* Port D, Pin3 */
    EVSYS_CHMUX_PORTD_PIN4_gc = (0x6C<<0),  /* Port D, Pin4 */
    EVSYS_CHMUX_PORTD_PIN5_gc = (0x6D<<0),  /* Port D, Pin5 */
    EVSYS_CHMUX_PORTD_PIN6_gc = (0x6E<<0),  /* Port D, Pin6 */
    EVSYS_CHMUX_PORTD_PIN7_gc = (0x6F<<0),  /* Port D, Pin7 */
    EVSYS_CHMUX_PRESCALER_1_gc = (0x80<<0),  /* Prescaler, divide by 1 */
    EVSYS_CHMUX_PRESCALER_2_gc = (0x81<<0),  /* Prescaler, divide by 2 */
    EVSYS_CHMUX_PRESCALER_4_gc = (0x82<<0),  /* Prescaler, divide by 4 */
    EVSYS_CHMUX_PRESCALER_8_gc = (0x83<<0),  /* Prescaler, divide by 8 */
    EVSYS_CHMUX_PRESCALER_16_gc = (0x84<<0),  /* Prescaler, divide by 16 */
    EVSYS_CHMUX_PRESCALER_32_gc = (0x85<<0),  /* Prescaler, divide by 32 */
    EVSYS_CHMUX_PRESCALER_64_gc = (0x86<<0),  /* Prescaler, divide by 64 */
    EVSYS_CHMUX_PRESCALER_128_gc = (0x87<<0),  /* Prescaler, divide by 128 */
    EVSYS_CHMUX_PRESCALER_256_gc = (0x88<<0),  /* Prescaler, divide by 256 */
    EVSYS_CHMUX_PRESCALER_512_gc = (0x89<<0),  /* Prescaler, divide by 512 */
    EVSYS_CHMUX_PRESCALER_1024_gc = (0x8A<<0),  /* Prescaler, divide by 1024 */
    EVSYS_CHMUX_PRESCALER_2048_gc = (0x8B<<0),  /* Prescaler, divide by 2048 */
    EVSYS_CHMUX_PRESCALER_4096_gc = (0x8C<<0),  /* Prescaler, divide by 4096 */
    EVSYS_CHMUX_PRESCALER_8192_gc = (0x8D<<0),  /* Prescaler, divide by 8192 */
    EVSYS_CHMUX_PRESCALER_16384_gc = (0x8E<<0),  /* Prescaler, divide by 16384 */
    EVSYS_CHMUX_PRESCALER_32768_gc = (0x8F<<0),  /* Prescaler, divide by 32768 */
    EVSYS_CHMUX_XCL_UNF0_gc = (0xB0<<0),  /* XCL BTC0 underflow */
    EVSYS_CHMUX_XCL_UNF1_gc = (0xB1<<0),  /* XCL BTC1 underflow */
    EVSYS_CHMUX_XCL_CC0_gc = (0xB2<<0),  /* XCL BTC0 capture or compare */
    EVSYS_CHMUX_XCL_CC1_gc = (0xB3<<0),  /* XCL BTC0 capture or compare */
    EVSYS_CHMUX_XCL_PEC0_gc = (0xB4<<0),  /* XCL PEC0 restart */
    EVSYS_CHMUX_XCL_PEC1_gc = (0xB5<<0),  /* XCL PEC1 restart */
    EVSYS_CHMUX_XCL_LUT0_gc = (0xB6<<0),  /* XCL LUT0 output */
    EVSYS_CHMUX_XCL_LUT1_gc = (0xB7<<0),  /* XCL LUT1 output */
    EVSYS_CHMUX_TCC4_OVF_gc = (0xC0<<0),  /* Timer/Counter C4 Overflow */
    EVSYS_CHMUX_TCC4_ERR_gc = (0xC1<<0),  /* Timer/Counter C4 Error */
    EVSYS_CHMUX_TCC4_CCA_gc = (0xC4<<0),  /* Timer/Counter C4 Compare or Capture A */
    EVSYS_CHMUX_TCC4_CCB_gc = (0xC5<<0),  /* Timer/Counter C4 Compare or Capture B */
    EVSYS_CHMUX_TCC4_CCC_gc = (0xC6<<0),  /* Timer/Counter C4 Compare or Capture C */
    EVSYS_CHMUX_TCC4_CCD_gc = (0xC7<<0),  /* Timer/Counter C4 Compare or Capture D */
    EVSYS_CHMUX_TCC5_OVF_gc = (0xC8<<0),  /* Timer/Counter C5 Overflow */
    EVSYS_CHMUX_TCC5_ERR_gc = (0xC9<<0),  /* Timer/Counter C5 Error */
    EVSYS_CHMUX_TCC5_CCA_gc = (0xCC<<0),  /* Timer/Counter C5 Compare or Capture A */
    EVSYS_CHMUX_TCC5_CCB_gc = (0xCD<<0),  /* Timer/Counter C5 Compare or Capture B */
    EVSYS_CHMUX_TCD5_OVF_gc = (0xD8<<0),  /* Timer/Counter D5 Overflow */
    EVSYS_CHMUX_TCD5_ERR_gc = (0xD9<<0),  /* Timer/Counter D5 Error */
    EVSYS_CHMUX_TCD5_CCA_gc = (0xDC<<0),  /* Timer/Counter D5 Compare or Capture A */
    EVSYS_CHMUX_TCD5_CCB_gc = (0xDD<<0),  /* Timer/Counter D5 Compare or Capture B */
} EVSYS_CHMUX_t;

/* Quadrature Decoder Index Recognition Mode */
typedef enum EVSYS_QDIRM_enum
{
    EVSYS_QDIRM_00_gc = (0x00<<5),  /* QDPH0 = 0, QDPH90 = 0 */
    EVSYS_QDIRM_01_gc = (0x01<<5),  /* QDPH0 = 0, QDPH90 = 1 */
    EVSYS_QDIRM_10_gc = (0x02<<5),  /* QDPH0 = 1, QDPH90 = 0 */
    EVSYS_QDIRM_11_gc = (0x03<<5),  /* QDPH0 = 1, QDPH90 = 1 */
} EVSYS_QDIRM_t;

/* Digital filter coefficient */
typedef enum EVSYS_DIGFILT_enum
{
    EVSYS_DIGFILT_1SAMPLE_gc = (0x00<<0),  /* 1 SAMPLE */
    EVSYS_DIGFILT_2SAMPLES_gc = (0x01<<0),  /* 2 SAMPLES */
    EVSYS_DIGFILT_3SAMPLES_gc = (0x02<<0),  /* 3 SAMPLES */
    EVSYS_DIGFILT_4SAMPLES_gc = (0x03<<0),  /* 4 SAMPLES */
    EVSYS_DIGFILT_5SAMPLES_gc = (0x04<<0),  /* 5 SAMPLES */
    EVSYS_DIGFILT_6SAMPLES_gc = (0x05<<0),  /* 6 SAMPLES */
    EVSYS_DIGFILT_7SAMPLES_gc = (0x06<<0),  /* 7 SAMPLES */
    EVSYS_DIGFILT_8SAMPLES_gc = (0x07<<0),  /* 8 SAMPLES */
} EVSYS_DIGFILT_t;

/* Prescaler Filter */
typedef enum EVSYS_PRESCFILT_enum
{
    EVSYS_PRESCFILT_CH04_gc = (0x01<<4),  /* Enable prescaler filter for either channel 0 or 4 */
    EVSYS_PRESCFILT_CH15_gc = (0x02<<4),  /* Enable prescaler filter for either channel 1 or 5 */
    EVSYS_PRESCFILT_CH26_gc = (0x04<<4),  /* Enable prescaler filter for either channel 2 or 6 */
    EVSYS_PRESCFILT_CH37_gc = (0x08<<4),  /* Enable prescaler filter for either channel 3 or 7 */
} EVSYS_PRESCFILT_t;

/* Prescaler */
typedef enum EVSYS_PRESCALER_enum
{
    EVSYS_PRESCALER_CLKPER_8_gc = (0x00<<0),  /* CLKPER, divide by 8 */
    EVSYS_PRESCALER_CLKPER_64_gc = (0x01<<0),  /* CLKPER, divide by 64 */
    EVSYS_PRESCALER_CLKPER_512_gc = (0x02<<0),  /* CLKPER, divide by 512 */
    EVSYS_PRESCALER_CLKPER_4096_gc = (0x03<<0),  /* CLKPER, divide by 4096 */
    EVSYS_PRESCALER_CLKPER_32768_gc = (0x04<<0),  /* CLKPER, divide by 32768 */
} EVSYS_PRESCALER_t;


/*
--------------------------------------------------------------------------
NVM - Non Volatile Memory Controller
--------------------------------------------------------------------------
*/

/* Non-volatile Memory Controller */
typedef struct NVM_struct
{
    register8_t ADDR0;  /* Address Register 0 */
    register8_t ADDR1;  /* Address Register 1 */
    register8_t ADDR2;  /* Address Register 2 */
    register8_t reserved_0x03;
    register8_t DATA0;  /* Data Register 0 */
    register8_t DATA1;  /* Data Register 1 */
    register8_t DATA2;  /* Data Register 2 */
    register8_t reserved_0x07;
    register8_t reserved_0x08;
    register8_t reserved_0x09;
    register8_t CMD;  /* Command */
    register8_t CTRLA;  /* Control Register A */
    register8_t CTRLB;  /* Control Register B */
    register8_t INTCTRL;  /* Interrupt Control */
    register8_t reserved_0x0E;
    register8_t STATUS;  /* Status */
    register8_t LOCK_BITS;  /* Lock Bits (Changed from LOCKBITS to avoid avr-libc collision) */
} NVM_t;

/* NVM Command */
typedef enum NVM_CMD_enum
{
    NVM_CMD_NO_OPERATION_gc = (0x00<<0),  /* Noop/Ordinary LPM */
    NVM_CMD_READ_USER_SIG_ROW_gc = (0x01<<0),  /* Read user signature row */
    NVM_CMD_READ_CALIB_ROW_gc = (0x02<<0),  /* Read calibration row */
    NVM_CMD_READ_FUSES_gc = (0x07<<0),  /* Read fuse byte */
    NVM_CMD_WRITE_LOCK_BITS_gc = (0x08<<0),  /* Write lock bits */
    NVM_CMD_ERASE_USER_SIG_ROW_gc = (0x18<<0),  /* Erase user signature row */
    NVM_CMD_WRITE_USER_SIG_ROW_gc = (0x1A<<0),  /* Write user signature row */
    NVM_CMD_ERASE_APP_gc = (0x20<<0),  /* Erase Application Section */
    NVM_CMD_ERASE_APP_PAGE_gc = (0x22<<0),  /* Erase Application Section page */
    NVM_CMD_LOAD_FLASH_BUFFER_gc = (0x23<<0),  /* Load Flash page buffer */
    NVM_CMD_WRITE_APP_PAGE_gc = (0x24<<0),  /* Write Application Section page */
    NVM_CMD_ERASE_WRITE_APP_PAGE_gc = (0x25<<0),  /* Erase-and-write Application Section page */
    NVM_CMD_ERASE_FLASH_BUFFER_gc = (0x26<<0),  /* Erase/flush Flash page buffer */
    NVM_CMD_ERASE_BOOT_PAGE_gc = (0x2A<<0),  /* Erase Boot Section page */
    NVM_CMD_ERASE_FLASH_PAGE_gc = (0x2B<<0),  /* Erase Flash Page */
    NVM_CMD_WRITE_BOOT_PAGE_gc = (0x2C<<0),  /* Write Boot Section page */
    NVM_CMD_ERASE_WRITE_BOOT_PAGE_gc = (0x2D<<0),  /* Erase-and-write Boot Section page */
    NVM_CMD_WRITE_FLASH_PAGE_gc = (0x2E<<0),  /* Write Flash Page */
    NVM_CMD_ERASE_WRITE_FLASH_PAGE_gc = (0x2F<<0),  /* Erase-and-write Flash Page */
    NVM_CMD_ERASE_EEPROM_gc = (0x30<<0),  /* Erase EEPROM */
    NVM_CMD_ERASE_EEPROM_PAGE_gc = (0x32<<0),  /* Erase EEPROM page */
    NVM_CMD_WRITE_EEPROM_PAGE_gc = (0x34<<0),  /* Write EEPROM page */
    NVM_CMD_ERASE_WRITE_EEPROM_PAGE_gc = (0x35<<0),  /* Erase-and-write EEPROM page */
    NVM_CMD_ERASE_EEPROM_BUFFER_gc = (0x36<<0),  /* Erase/flush EEPROM page buffer */
    NVM_CMD_APP_CRC_gc = (0x38<<0),  /* Application section CRC */
    NVM_CMD_BOOT_CRC_gc = (0x39<<0),  /*  Boot Section CRC */
    NVM_CMD_FLASH_RANGE_CRC_gc = (0x3A<<0),  /* Flash Range CRC */
    NVM_CMD_CHIP_ERASE_gc = (0x40<<0),  /* Erase Chip */
    NVM_CMD_READ_NVM_gc = (0x43<<0),  /* Read NVM */
    NVM_CMD_WRITE_FUSE_gc = (0x4C<<0),  /* Write Fuse byte */
    NVM_CMD_ERASE_BOOT_gc = (0x68<<0),  /* Erase Boot Section */
    NVM_CMD_FLASH_CRC_gc = (0x78<<0),  /* Flash CRC */
} NVM_CMD_t;

/* SPM ready interrupt level */
typedef enum NVM_SPMLVL_enum
{
    NVM_SPMLVL_OFF_gc = (0x00<<2),  /* Interrupt disabled */
    NVM_SPMLVL_LO_gc = (0x01<<2),  /* Low level */
    NVM_SPMLVL_MED_gc = (0x02<<2),  /* Medium level */
    NVM_SPMLVL_HI_gc = (0x03<<2),  /* High level */
} NVM_SPMLVL_t;

/* EEPROM ready interrupt level */
typedef enum NVM_EELVL_enum
{
    NVM_EELVL_OFF_gc = (0x00<<0),  /* Interrupt disabled */
    NVM_EELVL_LO_gc = (0x01<<0),  /* Low level */
    NVM_EELVL_MED_gc = (0x02<<0),  /* Medium level */
    NVM_EELVL_HI_gc = (0x03<<0),  /* High level */
} NVM_EELVL_t;

/* Boot lock bits - boot setcion */
typedef enum NVM_BLBB_enum
{
    NVM_BLBB_RWLOCK_gc = (0x00<<6),  /* Read and write not allowed */
    NVM_BLBB_RLOCK_gc = (0x01<<6),  /* Read not allowed */
    NVM_BLBB_WLOCK_gc = (0x02<<6),  /* Write not allowed */
    NVM_BLBB_NOLOCK_gc = (0x03<<6),  /* No locks */
} NVM_BLBB_t;

/* Boot lock bits - application section */
typedef enum NVM_BLBA_enum
{
    NVM_BLBA_RWLOCK_gc = (0x00<<4),  /* Read and write not allowed */
    NVM_BLBA_RLOCK_gc = (0x01<<4),  /* Read not allowed */
    NVM_BLBA_WLOCK_gc = (0x02<<4),  /* Write not allowed */
    NVM_BLBA_NOLOCK_gc = (0x03<<4),  /* No locks */
} NVM_BLBA_t;

/* Boot lock bits - application table section */
typedef enum NVM_BLBAT_enum
{
    NVM_BLBAT_RWLOCK_gc = (0x00<<2),  /* Read and write not allowed */
    NVM_BLBAT_RLOCK_gc = (0x01<<2),  /* Read not allowed */
    NVM_BLBAT_WLOCK_gc = (0x02<<2),  /* Write not allowed */
    NVM_BLBAT_NOLOCK_gc = (0x03<<2),  /* No locks */
} NVM_BLBAT_t;

/* Lock bits */
typedef enum NVM_LB_enum
{
    NVM_LB_RWLOCK_gc = (0x00<<0),  /* Read and write not allowed */
    NVM_LB_WLOCK_gc = (0x02<<0),  /* Write not allowed */
    NVM_LB_NOLOCK_gc = (0x03<<0),  /* No locks */
} NVM_LB_t;


/*
--------------------------------------------------------------------------
ADC - Analog/Digital Converter
--------------------------------------------------------------------------
*/

/* ADC Channel */
typedef struct ADC_CH_struct
{
    register8_t CTRL;  /* Control Register */
    register8_t MUXCTRL;  /* MUX Control */
    register8_t INTCTRL;  /* Channel Interrupt Control Register */
    register8_t INTFLAGS;  /* Interrupt Flags */
    _WORDREGISTER(RES);  /* Channel Result */
    register8_t SCAN;  /* Input Channel Scan */
    register8_t CORRCTRL;  /* Correction Control Register */
    register8_t OFFSETCORR0;  /* Offset Correction Register 0 */
    register8_t OFFSETCORR1;  /* Offset Correction Register 1 */
    register8_t GAINCORR0;  /* Gain Correction Register 0 */
    register8_t GAINCORR1;  /* Gain Correction Register 1 */
    register8_t AVGCTRL;  /* Average Control Register */
    register8_t reserved_0x0D;
    register8_t reserved_0x0E;
    register8_t reserved_0x0F;
} ADC_CH_t;


/* Analog-to-Digital Converter */
typedef struct ADC_struct
{
    register8_t CTRLA;  /* Control Register A */
    register8_t CTRLB;  /* Control Register B */
    register8_t REFCTRL;  /* Reference Control */
    register8_t EVCTRL;  /* Event Control */
    register8_t PRESCALER;  /* Clock Prescaler */
    register8_t reserved_0x05;
    register8_t INTFLAGS;  /* Interrupt Flags */
    register8_t TEMP;  /* Temporary Register */
    register8_t SAMPCTRL;  /* ADC Sampling Time Control Register */
    register8_t reserved_0x09;
    register8_t reserved_0x0A;
    register8_t reserved_0x0B;
    _WORDREGISTER(CAL);  /* Calibration Value */
    register8_t reserved_0x0E;
    register8_t reserved_0x0F;
    _WORDREGISTER(CH0RES);  /* Channel 0 Result */
    register8_t reserved_0x12;
    register8_t reserved_0x13;
    register8_t reserved_0x14;
    register8_t reserved_0x15;
    register8_t reserved_0x16;
    register8_t reserved_0x17;
    _WORDREGISTER(CMP);  /* Compare Value */
    register8_t reserved_0x1A;
    register8_t reserved_0x1B;
    register8_t reserved_0x1C;
    register8_t reserved_0x1D;
    register8_t reserved_0x1E;
    register8_t reserved_0x1F;
    ADC_CH_t CH0;  /* ADC Channel 0 */
} ADC_t;

/* Current Limitation */
typedef enum ADC_CURRLIMIT_enum
{
    ADC_CURRLIMIT_NO_gc = (0x00<<5),  /* No current limit,     300ksps max sampling rate */
    ADC_CURRLIMIT_LOW_gc = (0x01<<5),  /* Low current limit,    250ksps max sampling rate */
    ADC_CURRLIMIT_MED_gc = (0x02<<5),  /* Medium current limit, 150ksps max sampling rate */
    ADC_CURRLIMIT_HIGH_gc = (0x03<<5),  /* High current limit,   50ksps max sampling rate */
} ADC_CURRLIMIT_t;

/* Conversion result resolution */
typedef enum ADC_RESOLUTION_enum
{
    ADC_RESOLUTION_12BIT_gc = (0x00<<1),  /* 12-bit right-adjusted result */
    ADC_RESOLUTION_MT12BIT_gc = (0x01<<1),  /* More than 12-bit (oversapling) right-adjusted result */
    ADC_RESOLUTION_8BIT_gc = (0x02<<1),  /* 8-bit right-adjusted result */
    ADC_RESOLUTION_LEFT12BIT_gc = (0x03<<1),  /* 12-bit left-adjusted result */
} ADC_RESOLUTION_t;

/* Voltage reference selection */
typedef enum ADC_REFSEL_enum
{
    ADC_REFSEL_INT1V_gc = (0x00<<4),  /* Internal 1V */
    ADC_REFSEL_INTVCC_gc = (0x01<<4),  /* Internal VCC / 1.6 */
    ADC_REFSEL_AREFA_gc = (0x02<<4),  /* External reference on PORT A */
    ADC_REFSEL_AREFD_gc = (0x03<<4),  /* External reference on PORT D */
    ADC_REFSEL_INTVCC2_gc = (0x04<<4),  /* Internal VCC / 2 */
} ADC_REFSEL_t;

/* Event channel input selection */
typedef enum ADC_EVSEL_enum
{
    ADC_EVSEL_0_gc = (0x00<<3),  /* Event Channel 0 */
    ADC_EVSEL_1_gc = (0x01<<3),  /* Event Channel 1 */
    ADC_EVSEL_2_gc = (0x02<<3),  /* Event Channel 2 */
    ADC_EVSEL_3_gc = (0x03<<3),  /* Event Channel 3 */
    ADC_EVSEL_4_gc = (0x04<<3),  /* Event Channel 4 */
    ADC_EVSEL_5_gc = (0x05<<3),  /* Event Channel 5 */
    ADC_EVSEL_6_gc = (0x06<<3),  /* Event Channel 6 */
    ADC_EVSEL_7_gc = (0x07<<3),  /* Event Channel 7 */
} ADC_EVSEL_t;

/* Event action selection */
typedef enum ADC_EVACT_enum
{
    ADC_EVACT_NONE_gc = (0x00<<0),  /* No event action */
    ADC_EVACT_CH0_gc = (0x01<<0),  /* First event triggers channel conversion */
    ADC_EVACT_SYNCSWEEP_gc = (0x06<<0),  /* The ADC is flushed and restarted for accurate timing */
} ADC_EVACT_t;

/* Clock prescaler */
typedef enum ADC_PRESCALER_enum
{
    ADC_PRESCALER_DIV4_gc = (0x00<<0),  /* Divide clock by 4 */
    ADC_PRESCALER_DIV8_gc = (0x01<<0),  /* Divide clock by 8 */
    ADC_PRESCALER_DIV16_gc = (0x02<<0),  /* Divide clock by 16 */
    ADC_PRESCALER_DIV32_gc = (0x03<<0),  /* Divide clock by 32 */
    ADC_PRESCALER_DIV64_gc = (0x04<<0),  /* Divide clock by 64 */
    ADC_PRESCALER_DIV128_gc = (0x05<<0),  /* Divide clock by 128 */
    ADC_PRESCALER_DIV256_gc = (0x06<<0),  /* Divide clock by 256 */
    ADC_PRESCALER_DIV512_gc = (0x07<<0),  /* Divide clock by 512 */
} ADC_PRESCALER_t;

/* Gain factor */
typedef enum ADC_CH_GAIN_enum
{
    ADC_CH_GAIN_1X_gc = (0x00<<2),  /* 1x gain */
    ADC_CH_GAIN_2X_gc = (0x01<<2),  /* 2x gain */
    ADC_CH_GAIN_4X_gc = (0x02<<2),  /* 4x gain */
    ADC_CH_GAIN_8X_gc = (0x03<<2),  /* 8x gain */
    ADC_CH_GAIN_16X_gc = (0x04<<2),  /* 16x gain */
    ADC_CH_GAIN_32X_gc = (0x05<<2),  /* 32x gain */
    ADC_CH_GAIN_64X_gc = (0x06<<2),  /* 64x gain */
    ADC_CH_GAIN_DIV2_gc = (0x07<<2),  /* x/2 gain */
} ADC_CH_GAIN_t;

/* Input mode */
typedef enum ADC_CH_INPUTMODE_enum
{
    ADC_CH_INPUTMODE_INTERNAL_gc = (0x00<<0),  /* Internal inputs, no gain */
    ADC_CH_INPUTMODE_SINGLEENDED_gc = (0x01<<0),  /* Single-ended input, no gain */
    ADC_CH_INPUTMODE_DIFFWGAINL_gc = (0x02<<0),  /* Differential input, gain with 4 LSB pins selection */
    ADC_CH_INPUTMODE_DIFFWGAINH_gc = (0x03<<0),  /* Differential input, gain with 4 MSB pins selection */
} ADC_CH_INPUTMODE_t;

/* Positive input multiplexer selection */
typedef enum ADC_CH_MUXPOS_enum
{
    ADC_CH_MUXPOS_PIN0_gc = (0x00<<3),  /* Input pin 0 */
    ADC_CH_MUXPOS_PIN1_gc = (0x01<<3),  /* Input pin 1 */
    ADC_CH_MUXPOS_PIN2_gc = (0x02<<3),  /* Input pin 2 */
    ADC_CH_MUXPOS_PIN3_gc = (0x03<<3),  /* Input pin 3 */
    ADC_CH_MUXPOS_PIN4_gc = (0x04<<3),  /* Input pin 4 */
    ADC_CH_MUXPOS_PIN5_gc = (0x05<<3),  /* Input pin 5 */
    ADC_CH_MUXPOS_PIN6_gc = (0x06<<3),  /* Input pin 6 */
    ADC_CH_MUXPOS_PIN7_gc = (0x07<<3),  /* Input pin 7 */
    ADC_CH_MUXPOS_PIN8_gc = (0x08<<3),  /* Input pin 8 */
    ADC_CH_MUXPOS_PIN9_gc = (0x09<<3),  /* Input pin 9 */
    ADC_CH_MUXPOS_PIN10_gc = (0x0A<<3),  /* Input pin 10 */
    ADC_CH_MUXPOS_PIN11_gc = (0x0B<<3),  /* Input pin 11 */
    ADC_CH_MUXPOS_PIN12_gc = (0x0C<<3),  /* Input pin 12 */
    ADC_CH_MUXPOS_PIN13_gc = (0x0D<<3),  /* Input pin 13 */
    ADC_CH_MUXPOS_PIN14_gc = (0x0E<<3),  /* Input pin 14 */
    ADC_CH_MUXPOS_PIN15_gc = (0x0F<<3),  /* Input pin 15 */
} ADC_CH_MUXPOS_t;

/* Internal input multiplexer selections */
typedef enum ADC_CH_MUXINT_enum
{
    ADC_CH_MUXINT_TEMP_gc = (0x00<<3),  /* Temperature Reference */
    ADC_CH_MUXINT_BANDGAP_gc = (0x01<<3),  /* Bandgap Reference */
    ADC_CH_MUXINT_SCALEDVCC_gc = (0x02<<3),  /* 1/10 Scaled VCC */
    ADC_CH_MUXINT_DAC_gc = (0x03<<3),  /* DAC Output */
} ADC_CH_MUXINT_t;

/* Negative input multiplexer selection when gain on 4 LSB pins */
typedef enum ADC_CH_MUXNEGL_enum
{
    ADC_CH_MUXNEGL_PIN0_gc = (0x00<<0),  /* Input pin 0 */
    ADC_CH_MUXNEGL_PIN1_gc = (0x01<<0),  /* Input pin 1 */
    ADC_CH_MUXNEGL_PIN2_gc = (0x02<<0),  /* Input pin 2 */
    ADC_CH_MUXNEGL_PIN3_gc = (0x03<<0),  /* Input pin 3 */
    ADC_CH_MUXNEGL_GND_gc = (0x05<<0),  /* PAD ground */
    ADC_CH_MUXNEGL_INTGND_gc = (0x07<<0),  /* Internal ground */
} ADC_CH_MUXNEGL_t;

/* Negative input multiplexer selection when gain on 4 MSB pins */
typedef enum ADC_CH_MUXNEGH_enum
{
    ADC_CH_MUXNEGH_PIN4_gc = (0x00<<0),  /* Input pin 4 */
    ADC_CH_MUXNEGH_PIN5_gc = (0x01<<0),  /* Input pin 5 */
    ADC_CH_MUXNEGH_PIN6_gc = (0x02<<0),  /* Input pin 6 */
    ADC_CH_MUXNEGH_PIN7_gc = (0x03<<0),  /* Input pin 7 */
    ADC_CH_MUXNEGH_GND_gc = (0x05<<0),  /* PAD ground */
} ADC_CH_MUXNEGH_t;

/* Negative input multiplexer selection */
typedef enum ADC_CH_MUXNEG_enum
{
    ADC_CH_MUXNEG_PIN0_gc = (0x00<<0),  /* Input pin 0 */
} ADC_CH_MUXNEG_t;

/* Interupt mode */
typedef enum ADC_CH_INTMODE_enum
{
    ADC_CH_INTMODE_COMPLETE_gc = (0x00<<2),  /* Interrupt on conversion complete */
    ADC_CH_INTMODE_BELOW_gc = (0x01<<2),  /* Interrupt on result below compare value */
    ADC_CH_INTMODE_ABOVE_gc = (0x03<<2),  /* Interrupt on result above compare value */
} ADC_CH_INTMODE_t;

/* Interrupt level */
typedef enum ADC_CH_INTLVL_enum
{
    ADC_CH_INTLVL_OFF_gc = (0x00<<0),  /* Interrupt disabled */
    ADC_CH_INTLVL_LO_gc = (0x01<<0),  /* Low level */
    ADC_CH_INTLVL_MED_gc = (0x02<<0),  /* Medium level */
    ADC_CH_INTLVL_HI_gc = (0x03<<0),  /* High level */
} ADC_CH_INTLVL_t;

/* Averaged Number of Samples */
typedef enum ADC_SAMPNUM_enum
{
    ADC_SAMPNUM_1X_gc = (0x00<<0),  /* 1 Sample */
    ADC_SAMPNUM_2X_gc = (0x01<<0),  /* 2 Samples */
    ADC_SAMPNUM_4X_gc = (0x02<<0),  /* 4 Samples */
    ADC_SAMPNUM_8X_gc = (0x03<<0),  /* 8 Samples */
    ADC_SAMPNUM_16X_gc = (0x04<<0),  /* 16 Samples */
    ADC_SAMPNUM_32X_gc = (0x05<<0),  /* 32 Samples */
    ADC_SAMPNUM_64X_gc = (0x06<<0),  /* 64 Samples */
    ADC_SAMPNUM_128X_gc = (0x07<<0),  /* 128 Samples */
    ADC_SAMPNUM_256X_gc = (0x08<<0),  /* 256 Samples */
    ADC_SAMPNUM_512X_gc = (0x09<<0),  /* 512 Samples */
    ADC_SAMPNUM_1024X_gc = (0x0A<<0),  /* 1024 Samples */
} ADC_SAMPNUM_t;


/*
--------------------------------------------------------------------------
DAC - Digital/Analog Converter
--------------------------------------------------------------------------
*/

/* Digital-to-Analog Converter */
typedef struct DAC_struct
{
    register8_t CTRLA;  /* Control Register A */
    register8_t CTRLB;  /* Control Register B */
    register8_t CTRLC;  /* Control Register C */
    register8_t EVCTRL;  /* Event Input Control */
    register8_t reserved_0x04;
    register8_t STATUS;  /* Status */
    register8_t reserved_0x06;
    register8_t reserved_0x07;
    register8_t CH0GAINCAL;  /* Gain Calibration */
    register8_t CH0OFFSETCAL;  /* Offset Calibration */
    register8_t CH1GAINCAL;  /* Gain Calibration */
    register8_t CH1OFFSETCAL;  /* Offset Calibration */
    register8_t reserved_0x0C;
    register8_t reserved_0x0D;
    register8_t reserved_0x0E;
    register8_t reserved_0x0F;
    register8_t reserved_0x10;
    register8_t reserved_0x11;
    register8_t reserved_0x12;
    register8_t reserved_0x13;
    register8_t reserved_0x14;
    register8_t reserved_0x15;
    register8_t reserved_0x16;
    register8_t reserved_0x17;
    _WORDREGISTER(CH0DATA);  /* Channel 0 Data */
    _WORDREGISTER(CH1DATA);  /* Channel 1 Data */
} DAC_t;

/* Output channel selection */
typedef enum DAC_CHSEL_enum
{
    DAC_CHSEL_SINGLE_gc = (0x00<<5),  /* Single channel operation (Channel 0 only) */
    DAC_CHSEL_SINGLE1_gc = (0x01<<5),  /* Single channel operation (Channel 1 only) */
    DAC_CHSEL_DUAL_gc = (0x02<<5),  /* Dual channel operation (Channel 0 and channel 1) */
} DAC_CHSEL_t;

/* Reference voltage selection */
typedef enum DAC_REFSEL_enum
{
    DAC_REFSEL_INT1V_gc = (0x00<<3),  /* Internal 1V  */
    DAC_REFSEL_AVCC_gc = (0x01<<3),  /* Analog supply voltage */
    DAC_REFSEL_AREFA_gc = (0x02<<3),  /* External reference on AREF on PORTA */
    DAC_REFSEL_AREFB_gc = (0x03<<3),  /* External reference on AREF on PORTB */
} DAC_REFSEL_t;

/* Event channel selection */
typedef enum DAC_EVSEL_enum
{
    DAC_EVSEL_0_gc = (0x00<<0),  /* Event Channel 0 */
    DAC_EVSEL_1_gc = (0x01<<0),  /* Event Channel 1 */
    DAC_EVSEL_2_gc = (0x02<<0),  /* Event Channel 2 */
    DAC_EVSEL_3_gc = (0x03<<0),  /* Event Channel 3 */
    DAC_EVSEL_4_gc = (0x04<<0),  /* Event Channel 4 */
    DAC_EVSEL_5_gc = (0x05<<0),  /* Event Channel 5 */
    DAC_EVSEL_6_gc = (0x06<<0),  /* Event Channel 6 */
    DAC_EVSEL_7_gc = (0x07<<0),  /* Event Channel 7 */
} DAC_EVSEL_t;


/*
--------------------------------------------------------------------------
AC - Analog Comparator
--------------------------------------------------------------------------
*/

/* Analog Comparator */
typedef struct AC_struct
{
    register8_t AC0CTRL;  /* Analog Comparator 0 Control */
    register8_t AC1CTRL;  /* Analog Comparator 1 Control */
    register8_t AC0MUXCTRL;  /* Analog Comparator 0 MUX Control */
    register8_t AC1MUXCTRL;  /* Analog Comparator 1 MUX Control */
    register8_t CTRLA;  /* Control Register A */
    register8_t CTRLB;  /* Control Register B */
    register8_t WINCTRL;  /* Window Mode Control */
    register8_t STATUS;  /* Status */
    register8_t CURRCTRL;  /* Current Source Control Register */
    register8_t CURRCALIB;  /* Current Source Calibration Register */
} AC_t;

/* Interrupt mode */
typedef enum AC_INTMODE_enum
{
    AC_INTMODE_BOTHEDGES_gc = (0x00<<6),  /* Interrupt on both edges */
    AC_INTMODE_FALLING_gc = (0x02<<6),  /* Interrupt on falling edge */
    AC_INTMODE_RISING_gc = (0x03<<6),  /* Interrupt on rising edge */
} AC_INTMODE_t;

/* Interrupt level */
typedef enum AC_INTLVL_enum
{
    AC_INTLVL_OFF_gc = (0x00<<4),  /* Interrupt disabled */
    AC_INTLVL_LO_gc = (0x01<<4),  /* Low level */
    AC_INTLVL_MED_gc = (0x02<<4),  /* Medium level */
    AC_INTLVL_HI_gc = (0x03<<4),  /* High level */
} AC_INTLVL_t;

/* Hysteresis mode selection */
typedef enum AC_HYSMODE_enum
{
    AC_HYSMODE_NO_gc = (0x00<<1),  /* No hysteresis */
    AC_HYSMODE_SMALL_gc = (0x01<<1),  /* Small hysteresis */
    AC_HYSMODE_LARGE_gc = (0x02<<1),  /* Large hysteresis */
} AC_HYSMODE_t;

/* Positive input multiplexer selection */
typedef enum AC_MUXPOS_enum
{
    AC_MUXPOS_PIN0_gc = (0x00<<3),  /* Pin 0 */
    AC_MUXPOS_PIN1_gc = (0x01<<3),  /* Pin 1 */
    AC_MUXPOS_PIN2_gc = (0x02<<3),  /* Pin 2 */
    AC_MUXPOS_PIN3_gc = (0x03<<3),  /* Pin 3 */
    AC_MUXPOS_PIN4_gc = (0x04<<3),  /* Pin 4 */
    AC_MUXPOS_PIN5_gc = (0x05<<3),  /* Pin 5 */
    AC_MUXPOS_PIN6_gc = (0x06<<3),  /* Pin 6 */
    AC_MUXPOS_DAC_gc = (0x07<<3),  /* DAC output */
} AC_MUXPOS_t;

/* Negative input multiplexer selection */
typedef enum AC_MUXNEG_enum
{
    AC_MUXNEG_PIN0_gc = (0x00<<0),  /* Pin 0 */
    AC_MUXNEG_PIN1_gc = (0x01<<0),  /* Pin 1 */
    AC_MUXNEG_PIN3_gc = (0x02<<0),  /* Pin 3 */
    AC_MUXNEG_PIN5_gc = (0x03<<0),  /* Pin 5 */
    AC_MUXNEG_PIN7_gc = (0x04<<0),  /* Pin 7 */
    AC_MUXNEG_DAC_gc = (0x05<<0),  /* DAC output */
    AC_MUXNEG_BANDGAP_gc = (0x06<<0),  /* Bandgap Reference */
    AC_MUXNEG_SCALER_gc = (0x07<<0),  /* Internal voltage scaler */
} AC_MUXNEG_t;

/* Windows interrupt mode */
typedef enum AC_WINTMODE_enum
{
    AC_WINTMODE_ABOVE_gc = (0x00<<2),  /* Interrupt on above window */
    AC_WINTMODE_INSIDE_gc = (0x01<<2),  /* Interrupt on inside window */
    AC_WINTMODE_BELOW_gc = (0x02<<2),  /* Interrupt on below window */
    AC_WINTMODE_OUTSIDE_gc = (0x03<<2),  /* Interrupt on outside window */
} AC_WINTMODE_t;

/* Window interrupt level */
typedef enum AC_WINTLVL_enum
{
    AC_WINTLVL_OFF_gc = (0x00<<0),  /* Interrupt disabled */
    AC_WINTLVL_LO_gc = (0x01<<0),  /* Low priority */
    AC_WINTLVL_MED_gc = (0x02<<0),  /* Medium priority */
    AC_WINTLVL_HI_gc = (0x03<<0),  /* High priority */
} AC_WINTLVL_t;

/* Window mode state */
typedef enum AC_WSTATE_enum
{
    AC_WSTATE_ABOVE_gc = (0x00<<6),  /* Signal above window */
    AC_WSTATE_INSIDE_gc = (0x01<<6),  /* Signal inside window */
    AC_WSTATE_BELOW_gc = (0x02<<6),  /* Signal below window */
} AC_WSTATE_t;


/*
--------------------------------------------------------------------------
RTC - Real-Time Clounter
--------------------------------------------------------------------------
*/

/* Real-Time Counter */
typedef struct RTC_struct
{
    register8_t CTRL;  /* Control Register */
    register8_t STATUS;  /* Status Register */
    register8_t INTCTRL;  /* Interrupt Control Register */
    register8_t INTFLAGS;  /* Interrupt Flags */
    register8_t TEMP;  /* Temporary register */
    register8_t reserved_0x05;
    register8_t CALIB;  /* Calibration Register */
    register8_t reserved_0x07;
    _WORDREGISTER(CNT);  /* Count Register */
    _WORDREGISTER(PER);  /* Period Register */
    _WORDREGISTER(COMP);  /* Compare Register */
} RTC_t;

/* Prescaler Factor */
typedef enum RTC_PRESCALER_enum
{
    RTC_PRESCALER_OFF_gc = (0x00<<0),  /* RTC Off */
    RTC_PRESCALER_DIV1_gc = (0x01<<0),  /* RTC Clock */
    RTC_PRESCALER_DIV2_gc = (0x02<<0),  /* RTC Clock / 2 */
    RTC_PRESCALER_DIV8_gc = (0x03<<0),  /* RTC Clock / 8 */
    RTC_PRESCALER_DIV16_gc = (0x04<<0),  /* RTC Clock / 16 */
    RTC_PRESCALER_DIV64_gc = (0x05<<0),  /* RTC Clock / 64 */
    RTC_PRESCALER_DIV256_gc = (0x06<<0),  /* RTC Clock / 256 */
    RTC_PRESCALER_DIV1024_gc = (0x07<<0),  /* RTC Clock / 1024 */
} RTC_PRESCALER_t;

/* Compare Interrupt level */
typedef enum RTC_COMPINTLVL_enum
{
    RTC_COMPINTLVL_OFF_gc = (0x00<<2),  /* Interrupt Disabled */
    RTC_COMPINTLVL_LO_gc = (0x01<<2),  /* Low Level */
    RTC_COMPINTLVL_MED_gc = (0x02<<2),  /* Medium Level */
    RTC_COMPINTLVL_HI_gc = (0x03<<2),  /* High Level */
} RTC_COMPINTLVL_t;

/* Overflow Interrupt level */
typedef enum RTC_OVFINTLVL_enum
{
    RTC_OVFINTLVL_OFF_gc = (0x00<<0),  /* Interrupt Disabled */
    RTC_OVFINTLVL_LO_gc = (0x01<<0),  /* Low Level */
    RTC_OVFINTLVL_MED_gc = (0x02<<0),  /* Medium Level */
    RTC_OVFINTLVL_HI_gc = (0x03<<0),  /* High Level */
} RTC_OVFINTLVL_t;


/*
--------------------------------------------------------------------------
XCL - XMEGA Custom Logic
--------------------------------------------------------------------------
*/

/* XMEGA Custom Logic */
typedef struct XCL_struct
{
    register8_t CTRLA;  /* Control Register A */
    register8_t CTRLB;  /* Control Register B */
    register8_t CTRLC;  /* Control Register C */
    register8_t CTRLD;  /* Control Register D */
    register8_t CTRLE;  /* Control Register E */
    register8_t CTRLF;  /* Control Register F */
    register8_t CTRLG;  /* Control Register G */
    register8_t INTCTRL;  /* Interrupt Control Register */
    register8_t INTFLAGS;  /* Interrupt Flag Register */
    register8_t PLC;  /* Peripheral Lenght Control Register  */
    register8_t CNTL;  /* Counter Register Low */
    register8_t CNTH;  /* Counter Register High */
    register8_t CMPL;  /* Compare Register Low */
    register8_t CMPH;  /* Compare Register High */
    register8_t PERCAPTL;  /* Period or Capture Register Low */
    register8_t PERCAPTH;  /* Period or Capture Register High */
} XCL_t;

/* LUT0 Output Enable */
typedef enum XCL_LUTOUTEN_enum
{
    XCL_LUTOUTEN_DISABLE_gc = (0x00<<6),  /* LUT0 output disabled */
    XCL_LUTOUTEN_PIN0_gc = (0x01<<6),  /* LUT0 Output to pin 0 */
    XCL_LUTOUTEN_PIN4_gc = (0x02<<6),  /* LUT0 Output to pin 4 */
} XCL_LUTOUTEN_t;

/* Port Selection */
typedef enum XCL_PORTSEL_enum
{
    XCL_PORTSEL_PC_gc = (0x00<<4),  /* Port C for LUT or USARTC0 for PEC */
    XCL_PORTSEL_PD_gc = (0x01<<4),  /* Port D for LUT or USARTD0 for PEC */
} XCL_PORTSEL_t;

/* LUT Configuration */
typedef enum XCL_LUTCONF_enum
{
    XCL_LUTCONF_2LUT2IN_gc = (0x00<<0),  /* 2-Input two LUT */
    XCL_LUTCONF_2LUT1IN_gc = (0x01<<0),  /* Two LUT with duplicated input  */
    XCL_LUTCONF_2LUT3IN_gc = (0x02<<0),  /* Two LUT with one common input  */
    XCL_LUTCONF_1LUT3IN_gc = (0x03<<0),  /* 3-Input LUT  */
    XCL_LUTCONF_MUX_gc = (0x04<<0),  /* One LUT Mux  */
    XCL_LUTCONF_DLATCH_gc = (0x05<<0),  /* One D-Latch LUT  */
    XCL_LUTCONF_RSLATCH_gc = (0x06<<0),  /* One RS-Latch LUT  */
    XCL_LUTCONF_DFF_gc = (0x07<<0),  /* One DFF LUT  */
} XCL_LUTCONF_t;

/* Input Selection */
typedef enum XCL_INSEL_enum
{
    XCL_INSEL_EVSYS_gc = (0x00<<6),  /* Event system selected as source */
    XCL_INSEL_XCL_gc = (0x01<<6),  /* XCL selected as source */
    XCL_INSEL_PINL_gc = (0x02<<6),  /* LSB port pin selected as source */
    XCL_INSEL_PINH_gc = (0x03<<6),  /* MSB port pin selected as source */
} XCL_INSEL_t;

/* Delay Configuration on LUT */
typedef enum XCL_DLYCONF_enum
{
    XCL_DLYCONF_DISABLE_gc = (0x00<<2),  /* Delay element disabled */
    XCL_DLYCONF_IN_gc = (0x01<<2),  /* Delay enabled on LUT input */
    XCL_DLYCONF_OUT_gc = (0x02<<2),  /* Delay enabled on LUT output */
} XCL_DLYCONF_t;

/* Delay Selection */
typedef enum XCL_DLYSEL_enum
{
    XCL_DLYSEL_DLY11_gc = (0x00<<4),  /* One cycle delay for each LUT1 and LUT0 */
    XCL_DLYSEL_DLY12_gc = (0x01<<4),  /* One cycle delay for LUT1 and two cycles for LUT0 */
    XCL_DLYSEL_DLY21_gc = (0x02<<4),  /* Two cycles delay for LUT1 and one cycle for LUT0 */
    XCL_DLYSEL_DLY22_gc = (0x03<<4),  /* Two cycle delays for each LUT1 and LUT0 */
} XCL_DLYSEL_t;

/* Clock Selection */
typedef enum XCL_CLKSEL_enum
{
    XCL_CLKSEL_OFF_gc = (0x00<<0),  /* OFF */
    XCL_CLKSEL_DIV1_gc = (0x01<<0),  /* Prescaler clk */
    XCL_CLKSEL_DIV2_gc = (0x02<<0),  /* Prescaler clk/2 */
    XCL_CLKSEL_DIV4_gc = (0x03<<0),  /* Prescaler clk/4 */
    XCL_CLKSEL_DIV8_gc = (0x04<<0),  /* Prescaler clk/8 */
    XCL_CLKSEL_DIV64_gc = (0x05<<0),  /* Prescaler clk/64 */
    XCL_CLKSEL_DIV256_gc = (0x06<<0),  /* Prescaler clk/256 */
    XCL_CLKSEL_DIV1024_gc = (0x07<<0),  /* Prescaler clk/1024 */
    XCL_CLKSEL_EVCH0_gc = (0x08<<0),  /* Event channel 0 */
    XCL_CLKSEL_EVCH1_gc = (0x09<<0),  /* Event channel 1 */
    XCL_CLKSEL_EVCH2_gc = (0x0A<<0),  /* Event channel 2 */
    XCL_CLKSEL_EVCH3_gc = (0x0B<<0),  /* Event channel 3 */
    XCL_CLKSEL_EVCH4_gc = (0x0C<<0),  /* Event channel 4 */
    XCL_CLKSEL_EVCH5_gc = (0x0D<<0),  /* Event channel 5 */
    XCL_CLKSEL_EVCH6_gc = (0x0E<<0),  /* Event channel 6 */
    XCL_CLKSEL_EVCH7_gc = (0x0F<<0),  /* Event channel 7 */
} XCL_CLKSEL_t;

/* Timer/Counter Command Selection */
typedef enum XCL_CMDSEL_enum
{
    XCL_CMDSEL_NONE_gc = (0x00<<7),  /* None */
    XCL_CMDSEL_RESTART_gc = (0x01<<7),  /* Force restart */
} XCL_CMDSEL_t;

/* Timer/Counter Selection */
typedef enum XCL_TCSEL_enum
{
    XCL_TCSEL_TC16_gc = (0x00<<4),  /* 16-bit timer/counter */
    XCL_TCSEL_BTC0_gc = (0x01<<4),  /* One 8-bit timer/counter */
    XCL_TCSEL_BTC01_gc = (0x02<<4),  /* Two 8-bit timer/counters */
    XCL_TCSEL_BTC0PEC1_gc = (0x03<<4),  /* One 8-bit timer/counter and one 8-bit peripheral counter */
    XCL_TCSEL_PEC0BTC1_gc = (0x04<<4),  /* One 8-bit timer/counter and one 8-bit peripheral counter */
    XCL_TCSEL_PEC01_gc = (0x05<<4),  /* Two 8-bit peripheral counters */
    XCL_TCSEL_BTC0PEC2_gc = (0x06<<4),  /* One 8-bit timer/counter and two 4-bit peripheral counters */
} XCL_TCSEL_t;

/* Timer/Counter Mode */
typedef enum XCL_TCMODE_enum
{
    XCL_TCMODE_NORMAL_gc = (0x00<<0),  /* Normal mode with compare/period */
    XCL_TCMODE_CAPT_gc = (0x01<<0),  /* Capture mode */
    XCL_TCMODE_PWM_gc = (0x02<<0),  /* Single Slope PWM */
} XCL_TCMODE_t;

/* Compare Output Value Timer */
typedef enum XCL_CMPEN_enum
{
    XCL_CMPEN_CLEAR_gc = (0x00<<5),  /* Clear WG Output  */
    XCL_CMPEN_SET_gc = (0x01<<5),  /* Set WG Output  */
} XCL_CMPEN_t;

/* Command Enable */
typedef enum XCL_CMDEN_enum
{
    XCL_CMDEN_DISABLE_gc = (0x00<<6),  /* Command Ignored */
    XCL_CMDEN_CMD0_gc = (0x01<<6),  /* Command valid for timer/counter 0 */
    XCL_CMDEN_CMD1_gc = (0x02<<6),  /* Command valid for timer/counter 1 */
    XCL_CMDEN_CMD01_gc = (0x03<<6),  /* Command valid for both timer/counter 0 and 1 */
} XCL_CMDEN_t;

/* Timer/Counter Event Source Selection */
typedef enum XCL_EVSRC_enum
{
    XCL_EVSRC_EVCH0_gc = (0x00<<0),  /* Event channel 0 */
    XCL_EVSRC_EVCH1_gc = (0x01<<0),  /* Event channel 1 */
    XCL_EVSRC_EVCH2_gc = (0x02<<0),  /* Event channel 2 */
    XCL_EVSRC_EVCH3_gc = (0x03<<0),  /* Event channel 3 */
    XCL_EVSRC_EVCH4_gc = (0x04<<0),  /* Event channel 4 */
    XCL_EVSRC_EVCH5_gc = (0x05<<0),  /* Event channel 5 */
    XCL_EVSRC_EVCH6_gc = (0x06<<0),  /* Event channel 6 */
    XCL_EVSRC_EVCH7_gc = (0x07<<0),  /* Event channel 7 */
} XCL_EVSRC_t;

/* Timer/Counter Event Action Selection */
typedef enum XCL_EVACT_enum
{
    XCL_EVACT_INPUT_gc = (0x00<<5),  /* Input Capture */
    XCL_EVACT_FREQ_gc = (0x01<<5),  /* Frequency Capture */
    XCL_EVACT_PW_gc = (0x02<<5),  /* Pulse Width Capture */
    XCL_EVACT_RESTART_gc = (0x03<<5),  /* Restart timer/counter */
} XCL_EVACT_t;

/* Underflow Interrupt level */
typedef enum XCL_UNF_INTLVL_enum
{
    XCL_UNF_INTLVL_OFF_gc = (0x00<<2),  /* Interrupt Disabled */
    XCL_UNF_INTLVL_LO_gc = (0x01<<2),  /* Low Level */
    XCL_UNF_INTLVL_MED_gc = (0x02<<2),  /* Medium Level */
    XCL_UNF_INTLVL_HI_gc = (0x03<<2),  /* High Level */
} XCL_UNF_INTLVL_t;

/* Compare/Capture Interrupt level */
typedef enum XCL_CC_INTLVL_enum
{
    XCL_CC_INTLVL_OFF_gc = (0x00<<0),  /* Interrupt Disabled */
    XCL_CC_INTLVL_LO_gc = (0x01<<0),  /* Low Level */
    XCL_CC_INTLVL_MED_gc = (0x02<<0),  /* Medium Level */
    XCL_CC_INTLVL_HI_gc = (0x03<<0),  /* High Level */
} XCL_CC_INTLVL_t;


/*
--------------------------------------------------------------------------
TWI - Two-Wire Interface
--------------------------------------------------------------------------
*/

/*  */
typedef struct TWI_MASTER_struct
{
    register8_t CTRLA;  /* Control Register A */
    register8_t CTRLB;  /* Control Register B */
    register8_t CTRLC;  /* Control Register C */
    register8_t STATUS;  /* Status Register */
    register8_t BAUD;  /* Baurd Rate Control Register */
    register8_t ADDR;  /* Address Register */
    register8_t DATA;  /* Data Register */
} TWI_MASTER_t;


/*  */
typedef struct TWI_SLAVE_struct
{
    register8_t CTRLA;  /* Control Register A */
    register8_t CTRLB;  /* Control Register B */
    register8_t STATUS;  /* Status Register */
    register8_t ADDR;  /* Address Register */
    register8_t DATA;  /* Data Register */
    register8_t ADDRMASK;  /* Address Mask Register */
} TWI_SLAVE_t;


/*  */
typedef struct TWI_TIMEOUT_struct
{
    register8_t TOS;  /* Timeout Status Register */
    register8_t TOCONF;  /* Timeout Configuration Register */
} TWI_TIMEOUT_t;


/* Two-Wire Interface */
typedef struct TWI_struct
{
    register8_t CTRL;  /* TWI Common Control Register */
    TWI_MASTER_t MASTER;  /* TWI master module */
    TWI_SLAVE_t SLAVE;  /* TWI slave module */
    TWI_TIMEOUT_t TIMEOUT;  /* TWI SMBUS timeout module */
} TWI_t;

/* SDA Hold Time */
typedef enum TWI_SDAHOLD_enum
{
    TWI_SDAHOLD_OFF_gc = (0x00<<4),  /* SDA Hold Time off */
    TWI_SDAHOLD_50NS_gc = (0x01<<4),  /* SDA Hold Time 50 ns */
    TWI_SDAHOLD_300NS_gc = (0x02<<4),  /* SDA Hold Time 300 ns */
    TWI_SDAHOLD_400NS_gc = (0x03<<4),  /* SDA Hold Time 400 ns */
} TWI_SDAHOLD_t;

/* Master Interrupt Level */
typedef enum TWI_MASTER_INTLVL_enum
{
    TWI_MASTER_INTLVL_OFF_gc = (0x00<<6),  /* Interrupt Disabled */
    TWI_MASTER_INTLVL_LO_gc = (0x01<<6),  /* Low Level */
    TWI_MASTER_INTLVL_MED_gc = (0x02<<6),  /* Medium Level */
    TWI_MASTER_INTLVL_HI_gc = (0x03<<6),  /* High Level */
} TWI_MASTER_INTLVL_t;

/* Inactive Timeout */
typedef enum TWI_MASTER_TIMEOUT_enum
{
    TWI_MASTER_TIMEOUT_DISABLED_gc = (0x00<<2),  /* Bus Timeout Disabled */
    TWI_MASTER_TIMEOUT_50US_gc = (0x01<<2),  /* 50 Microseconds */
    TWI_MASTER_TIMEOUT_100US_gc = (0x02<<2),  /* 100 Microseconds */
    TWI_MASTER_TIMEOUT_200US_gc = (0x03<<2),  /* 200 Microseconds */
} TWI_MASTER_TIMEOUT_t;

/* Master Command */
typedef enum TWI_MASTER_CMD_enum
{
    TWI_MASTER_CMD_NOACT_gc = (0x00<<0),  /* No Action */
    TWI_MASTER_CMD_REPSTART_gc = (0x01<<0),  /* Issue Repeated Start Condition */
    TWI_MASTER_CMD_RECVTRANS_gc = (0x02<<0),  /* Receive or Transmit Data */
    TWI_MASTER_CMD_STOP_gc = (0x03<<0),  /* Issue Stop Condition */
} TWI_MASTER_CMD_t;

/* Master Bus State */
typedef enum TWI_MASTER_BUSSTATE_enum
{
    TWI_MASTER_BUSSTATE_UNKNOWN_gc = (0x00<<0),  /* Unknown Bus State */
    TWI_MASTER_BUSSTATE_IDLE_gc = (0x01<<0),  /* Bus is Idle */
    TWI_MASTER_BUSSTATE_OWNER_gc = (0x02<<0),  /* This Module Controls The Bus */
    TWI_MASTER_BUSSTATE_BUSY_gc = (0x03<<0),  /* The Bus is Busy */
} TWI_MASTER_BUSSTATE_t;

/* Slave Interrupt Level */
typedef enum TWI_SLAVE_INTLVL_enum
{
    TWI_SLAVE_INTLVL_OFF_gc = (0x00<<6),  /* Interrupt Disabled */
    TWI_SLAVE_INTLVL_LO_gc = (0x01<<6),  /* Low Level */
    TWI_SLAVE_INTLVL_MED_gc = (0x02<<6),  /* Medium Level */
    TWI_SLAVE_INTLVL_HI_gc = (0x03<<6),  /* High Level */
} TWI_SLAVE_INTLVL_t;

/* Slave Command */
typedef enum TWI_SLAVE_CMD_enum
{
    TWI_SLAVE_CMD_NOACT_gc = (0x00<<0),  /* No Action */
    TWI_SLAVE_CMD_COMPTRANS_gc = (0x02<<0),  /* Used To Complete a Transaction */
    TWI_SLAVE_CMD_RESPONSE_gc = (0x03<<0),  /* Used in Response to Address/Data Interrupt */
} TWI_SLAVE_CMD_t;

/* Master Timeout */
typedef enum TWI_MASTER_TTIMEOUT_enum
{
    TWI_MASTER_TTIMEOUT_25MS_gc = (0x00<<0),  /* 25 Milliseconds */
    TWI_MASTER_TTIMEOUT_24MS_gc = (0x01<<0),  /* 24 Milliseconds */
    TWI_MASTER_TTIMEOUT_23MS_gc = (0x02<<0),  /* 23 Milliseconds */
    TWI_MASTER_TTIMEOUT_22MS_gc = (0x03<<0),  /* 22 Milliseconds */
    TWI_MASTER_TTIMEOUT_26MS_gc = (0x04<<0),  /* 26 Milliseconds */
    TWI_MASTER_TTIMEOUT_27MS_gc = (0x05<<0),  /* 27 Milliseconds */
    TWI_MASTER_TTIMEOUT_28MS_gc = (0x06<<0),  /* 28 Milliseconds */
    TWI_MASTER_TTIMEOUT_29MS_gc = (0x07<<0),  /* 29 Milliseconds */
} TWI_MASTER_TTIMEOUT_t;

/* Slave Ttimeout */
typedef enum TWI_SLAVE_TTIMEOUT_enum
{
    TWI_SLAVE_TTIMEOUT_25MS_gc = (0x00<<5),  /* 25 Milliseconds */
    TWI_SLAVE_TTIMEOUT_24MS_gc = (0x01<<5),  /* 24 Milliseconds */
    TWI_SLAVE_TTIMEOUT_23MS_gc = (0x02<<5),  /* 23 Milliseconds */
    TWI_SLAVE_TTIMEOUT_22MS_gc = (0x03<<5),  /* 22 Milliseconds */
    TWI_SLAVE_TTIMEOUT_26MS_gc = (0x04<<5),  /* 26 Milliseconds */
    TWI_SLAVE_TTIMEOUT_27MS_gc = (0x05<<5),  /* 27 Milliseconds */
    TWI_SLAVE_TTIMEOUT_28MS_gc = (0x06<<5),  /* 28 Milliseconds */
    TWI_SLAVE_TTIMEOUT_29MS_gc = (0x07<<5),  /* 29 Milliseconds */
} TWI_SLAVE_TTIMEOUT_t;

/* Master/Slave Extend Timeout */
typedef enum TWI_MASTER_TMSEXT_enum
{
    TWI_MASTER_TMSEXT_10MS25MS_gc = (0x00<<3),  /* Tmext 10ms Tsext 25ms */
    TWI_MASTER_TMSEXT_9MS24MS_gc = (0x01<<3),  /* Tmext 9ms  Tsext 24ms */
    TWI_MASTER_TMSEXT_11MS26MS_gc = (0x02<<3),  /* Tmext 11ms Tsext 26ms */
    TWI_MASTER_TMSEXT_12MS27MS_gc = (0x03<<3),  /* Tmext 12ms Tsext 27ms */
} TWI_MASTER_TMSEXT_t;


/*
--------------------------------------------------------------------------
PORT - Port Configuration
--------------------------------------------------------------------------
*/

/* I/O Ports */
typedef struct PORT_struct
{
    register8_t DIR;  /* I/O Port Data Direction */
    register8_t DIRSET;  /* I/O Port Data Direction Set */
    register8_t DIRCLR;  /* I/O Port Data Direction Clear */
    register8_t DIRTGL;  /* I/O Port Data Direction Toggle */
    register8_t OUT;  /* I/O Port Output */
    register8_t OUTSET;  /* I/O Port Output Set */
    register8_t OUTCLR;  /* I/O Port Output Clear */
    register8_t OUTTGL;  /* I/O Port Output Toggle */
    register8_t IN;  /* I/O port Input */
    register8_t INTCTRL;  /* Interrupt Control Register */
    register8_t INTMASK;  /* Port Interrupt Mask */
    register8_t reserved_0x0B;
    register8_t INTFLAGS;  /* Interrupt Flag Register */
    register8_t reserved_0x0D;
    register8_t REMAP;  /* Pin Remap Register */
    register8_t reserved_0x0F;
    register8_t PIN0CTRL;  /* Pin 0 Control Register */
    register8_t PIN1CTRL;  /* Pin 1 Control Register */
    register8_t PIN2CTRL;  /* Pin 2 Control Register */
    register8_t PIN3CTRL;  /* Pin 3 Control Register */
    register8_t PIN4CTRL;  /* Pin 4 Control Register */
    register8_t PIN5CTRL;  /* Pin 5 Control Register */
    register8_t PIN6CTRL;  /* Pin 6 Control Register */
    register8_t PIN7CTRL;  /* Pin 7 Control Register */
} PORT_t;

/* Port Interrupt Level */
typedef enum PORT_INTLVL_enum
{
    PORT_INTLVL_OFF_gc = (0x00<<0),  /* Interrupt Disabled */
    PORT_INTLVL_LO_gc = (0x01<<0),  /* Low Level */
    PORT_INTLVL_MED_gc = (0x02<<0),  /* Medium Level */
    PORT_INTLVL_HI_gc = (0x03<<0),  /* High Level */
} PORT_INTLVL_t;

/* Output/Pull Configuration */
typedef enum PORT_OPC_enum
{
    PORT_OPC_TOTEM_gc = (0x00<<3),  /* Totempole */
    PORT_OPC_BUSKEEPER_gc = (0x01<<3),  /* Totempole w/ Bus keeper on Input and Output */
    PORT_OPC_PULLDOWN_gc = (0x02<<3),  /* Totempole w/ Pull-down on Input */
    PORT_OPC_PULLUP_gc = (0x03<<3),  /* Totempole w/ Pull-up on Input */
    PORT_OPC_WIREDOR_gc = (0x04<<3),  /* Wired OR */
    PORT_OPC_WIREDAND_gc = (0x05<<3),  /* Wired AND */
    PORT_OPC_WIREDORPULL_gc = (0x06<<3),  /* Wired OR w/ Pull-down */
    PORT_OPC_WIREDANDPULL_gc = (0x07<<3),  /* Wired AND w/ Pull-up */
} PORT_OPC_t;

/* Input/Sense Configuration */
typedef enum PORT_ISC_enum
{
    PORT_ISC_BOTHEDGES_gc = (0x00<<0),  /* Sense Both Edges */
    PORT_ISC_RISING_gc = (0x01<<0),  /* Sense Rising Edge */
    PORT_ISC_FALLING_gc = (0x02<<0),  /* Sense Falling Edge */
    PORT_ISC_LEVEL_gc = (0x03<<0),  /* Sense Level (Transparent For Events) */
    PORT_ISC_FORCE_ENABLE_gc = (0x06<<0),  /* Digital Input Buffer Forced Enable */
    PORT_ISC_INPUT_DISABLE_gc = (0x07<<0),  /* Disable Digital Input Buffer */
} PORT_ISC_t;


/*
--------------------------------------------------------------------------
TC - 16-bit Timer/Counter With PWM
--------------------------------------------------------------------------
*/

/* 16-bit Timer/Counter 4 */
typedef struct TC4_struct
{
    register8_t CTRLA;  /* Control  Register A */
    register8_t CTRLB;  /* Control Register B */
    register8_t CTRLC;  /* Control register C */
    register8_t CTRLD;  /* Control Register D */
    register8_t CTRLE;  /* Control Register E */
    register8_t CTRLF;  /* Control Register F */
    register8_t INTCTRLA;  /* Interrupt Control Register A */
    register8_t INTCTRLB;  /* Interrupt Control Register B */
    register8_t CTRLGCLR;  /* Control Register G Clear */
    register8_t CTRLGSET;  /* Control Register G Set */
    register8_t CTRLHCLR;  /* Control Register H Clear */
    register8_t CTRLHSET;  /* Control Register H Set */
    register8_t INTFLAGS;  /* Interrupt Flag Register */
    register8_t reserved_0x0D;
    register8_t reserved_0x0E;
    register8_t TEMP;  /* Temporary Register For 16-bit Access */
    register8_t reserved_0x10;
    register8_t reserved_0x11;
    register8_t reserved_0x12;
    register8_t reserved_0x13;
    register8_t reserved_0x14;
    register8_t reserved_0x15;
    register8_t reserved_0x16;
    register8_t reserved_0x17;
    register8_t reserved_0x18;
    register8_t reserved_0x19;
    register8_t reserved_0x1A;
    register8_t reserved_0x1B;
    register8_t reserved_0x1C;
    register8_t reserved_0x1D;
    register8_t reserved_0x1E;
    register8_t reserved_0x1F;
    _WORDREGISTER(CNT);  /* Count */
    register8_t reserved_0x22;
    register8_t reserved_0x23;
    register8_t reserved_0x24;
    register8_t reserved_0x25;
    _WORDREGISTER(PER);  /* Period */
    _WORDREGISTER(CCA);  /* Compare or Capture A */
    _WORDREGISTER(CCB);  /* Compare or Capture B */
    _WORDREGISTER(CCC);  /* Compare or Capture C */
    _WORDREGISTER(CCD);  /* Compare or Capture D */
    register8_t reserved_0x30;
    register8_t reserved_0x31;
    register8_t reserved_0x32;
    register8_t reserved_0x33;
    register8_t reserved_0x34;
    register8_t reserved_0x35;
    _WORDREGISTER(PERBUF);  /* Period Buffer */
    _WORDREGISTER(CCABUF);  /* Compare Or Capture A Buffer */
    _WORDREGISTER(CCBBUF);  /* Compare Or Capture B Buffer */
    _WORDREGISTER(CCCBUF);  /* Compare Or Capture C Buffer */
    _WORDREGISTER(CCDBUF);  /* Compare Or Capture D Buffer */
} TC4_t;


/* 16-bit Timer/Counter 5 */
typedef struct TC5_struct
{
    register8_t CTRLA;  /* Control  Register A */
    register8_t CTRLB;  /* Control Register B */
    register8_t CTRLC;  /* Control register C */
    register8_t CTRLD;  /* Control Register D */
    register8_t CTRLE;  /* Control Register E */
    register8_t CTRLF;  /* Control Register F */
    register8_t INTCTRLA;  /* Interrupt Control Register A */
    register8_t INTCTRLB;  /* Interrupt Control Register B */
    register8_t CTRLGCLR;  /* Control Register G Clear */
    register8_t CTRLGSET;  /* Control Register G Set */
    register8_t CTRLHCLR;  /* Control Register H Clear */
    register8_t CTRLHSET;  /* Control Register H Set */
    register8_t INTFLAGS;  /* Interrupt Flag Register */
    register8_t reserved_0x0D;
    register8_t reserved_0x0E;
    register8_t TEMP;  /* Temporary Register For 16-bit Access */
    register8_t reserved_0x10;
    register8_t reserved_0x11;
    register8_t reserved_0x12;
    register8_t reserved_0x13;
    register8_t reserved_0x14;
    register8_t reserved_0x15;
    register8_t reserved_0x16;
    register8_t reserved_0x17;
    register8_t reserved_0x18;
    register8_t reserved_0x19;
    register8_t reserved_0x1A;
    register8_t reserved_0x1B;
    register8_t reserved_0x1C;
    register8_t reserved_0x1D;
    register8_t reserved_0x1E;
    register8_t reserved_0x1F;
    _WORDREGISTER(CNT);  /* Count */
    register8_t reserved_0x22;
    register8_t reserved_0x23;
    register8_t reserved_0x24;
    register8_t reserved_0x25;
    _WORDREGISTER(PER);  /* Period */
    _WORDREGISTER(CCA);  /* Compare or Capture A */
    _WORDREGISTER(CCB);  /* Compare or Capture B */
    register8_t reserved_0x2C;
    register8_t reserved_0x2D;
    register8_t reserved_0x2E;
    register8_t reserved_0x2F;
    register8_t reserved_0x30;
    register8_t reserved_0x31;
    register8_t reserved_0x32;
    register8_t reserved_0x33;
    register8_t reserved_0x34;
    register8_t reserved_0x35;
    _WORDREGISTER(PERBUF);  /* Period Buffer */
    _WORDREGISTER(CCABUF);  /* Compare Or Capture A Buffer */
    _WORDREGISTER(CCBBUF);  /* Compare Or Capture B Buffer */
    register8_t reserved_0x3C;
    register8_t reserved_0x3D;
    register8_t reserved_0x3E;
    register8_t reserved_0x3F;
} TC5_t;

/* Clock Selection */
typedef enum TC45_CLKSEL_enum
{
    TC45_CLKSEL_OFF_gc = (0x00<<0),  /* Timer Off */
    TC45_CLKSEL_DIV1_gc = (0x01<<0),  /* System Clock */
    TC45_CLKSEL_DIV2_gc = (0x02<<0),  /* System Clock / 2 */
    TC45_CLKSEL_DIV4_gc = (0x03<<0),  /* System Clock / 4 */
    TC45_CLKSEL_DIV8_gc = (0x04<<0),  /* System Clock / 8 */
    TC45_CLKSEL_DIV64_gc = (0x05<<0),  /* System Clock / 64 */
    TC45_CLKSEL_DIV256_gc = (0x06<<0),  /* System Clock / 256 */
    TC45_CLKSEL_DIV1024_gc = (0x07<<0),  /* System Clock / 1024 */
    TC45_CLKSEL_EVCH0_gc = (0x08<<0),  /* Event Channel 0 */
    TC45_CLKSEL_EVCH1_gc = (0x09<<0),  /* Event Channel 1 */
    TC45_CLKSEL_EVCH2_gc = (0x0A<<0),  /* Event Channel 2 */
    TC45_CLKSEL_EVCH3_gc = (0x0B<<0),  /* Event Channel 3 */
    TC45_CLKSEL_EVCH4_gc = (0x0C<<0),  /* Event Channel 4 */
    TC45_CLKSEL_EVCH5_gc = (0x0D<<0),  /* Event Channel 5 */
    TC45_CLKSEL_EVCH6_gc = (0x0E<<0),  /* Event Channel 6 */
    TC45_CLKSEL_EVCH7_gc = (0x0F<<0),  /* Event Channel 7 */
} TC45_CLKSEL_t;

/* Byte Mode */
typedef enum TC45_BYTEM_enum
{
    TC45_BYTEM_NORMAL_gc = (0x00<<6),  /* 16-bit mode */
    TC45_BYTEM_BYTEMODE_gc = (0x01<<6),  /* Timer/Counter Operating in Byte Mode Only */
} TC45_BYTEM_t;

/* Circular Enable Mode */
typedef enum TC45_CIRCEN_enum
{
    TC45_CIRCEN_DISABLE_gc = (0x00<<4),  /* Circular Buffer Disabled */
    TC45_CIRCEN_PER_gc = (0x01<<4),  /* Circular Buffer Enabled on PER/PERBUF */
    TC45_CIRCEN_CCA_gc = (0x02<<4),  /* Circular Buffer Enabled on CCA/CCABUF */
    TC45_CIRCEN_BOTH_gc = (0x03<<4),  /* Circular Buffer Enabled on All Buffered Registers */
} TC45_CIRCEN_t;

/* Waveform Generation Mode */
typedef enum TC45_WGMODE_enum
{
    TC45_WGMODE_NORMAL_gc = (0x00<<0),  /* Normal Mode */
    TC45_WGMODE_FRQ_gc = (0x01<<0),  /* Frequency Generation Mode */
    TC45_WGMODE_SINGLESLOPE_gc = (0x03<<0),  /* Single Slope */
    TC45_WGMODE_DSTOP_gc = (0x05<<0),  /* Dual Slope, Update on TOP */
    TC45_WGMODE_DSBOTH_gc = (0x06<<0),  /* Dual Slope, Both */
    TC45_WGMODE_DSBOTTOM_gc = (0x07<<0),  /* Dual Slope, Update on BOTTOM */
} TC45_WGMODE_t;

/* Event Action */
typedef enum TC45_EVACT_enum
{
    TC45_EVACT_OFF_gc = (0x00<<5),  /* No Event Action */
    TC45_EVACT_FMODE1_gc = (0x01<<5),  /* Fault Mode 1 capture */
    TC45_EVACT_FMODE2_gc = (0x02<<5),  /* Fault Mode 2 capture */
    TC45_EVACT_UPDOWN_gc = (0x03<<5),  /* Up/down count */
    TC45_EVACT_QDEC_gc = (0x04<<5),  /* Quadrature decode */
    TC45_EVACT_RESTART_gc = (0x05<<5),  /* Restart */
    TC45_EVACT_PWF_gc = (0x06<<5),  /* Pulse-width Capture */
} TC45_EVACT_t;

/* Event Selection */
typedef enum TC45_EVSEL_enum
{
    TC45_EVSEL_OFF_gc = (0x00<<0),  /* No Event Source */
    TC45_EVSEL_CH0_gc = (0x08<<0),  /* Event Channel 0 */
    TC45_EVSEL_CH1_gc = (0x09<<0),  /* Event Channel 1 */
    TC45_EVSEL_CH2_gc = (0x0A<<0),  /* Event Channel 2 */
    TC45_EVSEL_CH3_gc = (0x0B<<0),  /* Event Channel 3 */
    TC45_EVSEL_CH4_gc = (0x0C<<0),  /* Event Channel 4 */
    TC45_EVSEL_CH5_gc = (0x0D<<0),  /* Event Channel 5 */
    TC45_EVSEL_CH6_gc = (0x0E<<0),  /* Event Channel 6 */
    TC45_EVSEL_CH7_gc = (0x0F<<0),  /* Event Channel 7 */
} TC45_EVSEL_t;

/* Compare or Capture Channel A Mode */
typedef enum TC45_CCAMODE_enum
{
    TC45_CCAMODE_DISABLE_gc = (0x00<<0),  /* Channel Disabled */
    TC45_CCAMODE_COMP_gc = (0x01<<0),  /* Ouput Compare enabled */
    TC45_CCAMODE_CAPT_gc = (0x02<<0),  /* Input Capture enabled */
    TC45_CCAMODE_BOTHCC_gc = (0x03<<0),  /* Both Compare and Capture enabled */
} TC45_CCAMODE_t;

/* Compare or Capture Channel B Mode */
typedef enum TC45_CCBMODE_enum
{
    TC45_CCBMODE_DISABLE_gc = (0x00<<2),  /* Channel Disabled */
    TC45_CCBMODE_COMP_gc = (0x01<<2),  /* Ouput Compare enabled */
    TC45_CCBMODE_CAPT_gc = (0x02<<2),  /* Input Capture enabled */
    TC45_CCBMODE_BOTHCC_gc = (0x03<<2),  /* Both Compare and Capture enabled */
} TC45_CCBMODE_t;

/* Compare or Capture Channel C Mode */
typedef enum TC45_CCCMODE_enum
{
    TC45_CCCMODE_DISABLE_gc = (0x00<<4),  /* Channel Disabled */
    TC45_CCCMODE_COMP_gc = (0x01<<4),  /* Ouput Compare enabled */
    TC45_CCCMODE_CAPT_gc = (0x02<<4),  /* Input Capture enabled */
    TC45_CCCMODE_BOTHCC_gc = (0x03<<4),  /* Both Compare and Capture enabled */
} TC45_CCCMODE_t;

/* Compare or Capture Channel D Mode */
typedef enum TC45_CCDMODE_enum
{
    TC45_CCDMODE_DISABLE_gc = (0x00<<6),  /* Channel Disabled */
    TC45_CCDMODE_COMP_gc = (0x01<<6),  /* Ouput Compare enabled */
    TC45_CCDMODE_CAPT_gc = (0x02<<6),  /* Input Capture enabled */
    TC45_CCDMODE_BOTHCC_gc = (0x03<<6),  /* Both Compare and Capture enabled */
} TC45_CCDMODE_t;

/* Compare or Capture Low Channel A Mode */
typedef enum TC45_LCCAMODE_enum
{
    TC45_LCCAMODE_DISABLE_gc = (0x00<<0),  /* Channel Disabled */
    TC45_LCCAMODE_COMP_gc = (0x01<<0),  /* Ouput Compare enabled */
    TC45_LCCAMODE_CAPT_gc = (0x02<<0),  /* Input Capture enabled */
    TC45_LCCAMODE_BOTHCC_gc = (0x03<<0),  /* Both Compare and Capture enabled */
} TC45_LCCAMODE_t;

/* Compare or Capture Low Channel B Mode */
typedef enum TC45_LCCBMODE_enum
{
    TC45_LCCBMODE_DISABLE_gc = (0x00<<2),  /* Channel Disabled */
    TC45_LCCBMODE_COMP_gc = (0x01<<2),  /* Ouput Compare enabled */
    TC45_LCCBMODE_CAPT_gc = (0x02<<2),  /* Input Capture enabled */
    TC45_LCCBMODE_BOTHCC_gc = (0x03<<2),  /* Both Compare and Capture enabled */
} TC45_LCCBMODE_t;

/* Compare or Capture Low Channel C Mode */
typedef enum TC45_LCCCMODE_enum
{
    TC45_LCCCMODE_DISABLE_gc = (0x00<<4),  /* Channel Disabled */
    TC45_LCCCMODE_COMP_gc = (0x01<<4),  /* Ouput Compare enabled */
    TC45_LCCCMODE_CAPT_gc = (0x02<<4),  /* Input Capture enabled */
    TC45_LCCCMODE_BOTHCC_gc = (0x03<<4),  /* Both Compare and Capture enabled */
} TC45_LCCCMODE_t;

/* Compare or Capture Low Channel D Mode */
typedef enum TC45_LCCDMODE_enum
{
    TC45_LCCDMODE_DISABLE_gc = (0x00<<6),  /* Channel Disabled */
    TC45_LCCDMODE_COMP_gc = (0x01<<6),  /* Ouput Compare enabled */
    TC45_LCCDMODE_CAPT_gc = (0x02<<6),  /* Input Capture enabled */
    TC45_LCCDMODE_BOTHCC_gc = (0x03<<6),  /* Both Compare and Capture enabled */
} TC45_LCCDMODE_t;

/* Compare or Capture High Channel A Mode */
typedef enum TC45_HCCAMODE_enum
{
    TC45_HCCAMODE_DISABLE_gc = (0x00<<0),  /* Channel Disabled */
    TC45_HCCAMODE_COMP_gc = (0x01<<0),  /* Ouput Compare enabled */
    TC45_HCCAMODE_CAPT_gc = (0x02<<0),  /* Input Capture enabled */
    TC45_HCCAMODE_BOTHCC_gc = (0x03<<0),  /* Both Compare and Capture enabled */
} TC45_HCCAMODE_t;

/* Compare or Capture High Channel B Mode */
typedef enum TC45_HCCBMODE_enum
{
    TC45_HCCBMODE_DISABLE_gc = (0x00<<2),  /* Channel Disabled */
    TC45_HCCBMODE_COMP_gc = (0x01<<2),  /* Ouput Compare enabled */
    TC45_HCCBMODE_CAPT_gc = (0x02<<2),  /* Input Capture enabled */
    TC45_HCCBMODE_BOTHCC_gc = (0x03<<2),  /* Both Compare and Capture enabled */
} TC45_HCCBMODE_t;

/* Compare or Capture High Channel C Mode */
typedef enum TC45_HCCCMODE_enum
{
    TC45_HCCCMODE_DISABLE_gc = (0x00<<4),  /* Channel Disabled */
    TC45_HCCCMODE_COMP_gc = (0x01<<4),  /* Ouput Compare enabled */
    TC45_HCCCMODE_CAPT_gc = (0x02<<4),  /* Input Capture enabled */
    TC45_HCCCMODE_BOTHCC_gc = (0x03<<4),  /* Both Compare and Capture enabled */
} TC45_HCCCMODE_t;

/* Compare or Capture High Channel D Mode */
typedef enum TC45_HCCDMODE_enum
{
    TC45_HCCDMODE_DISABLE_gc = (0x00<<6),  /* Channel Disabled */
    TC45_HCCDMODE_COMP_gc = (0x01<<6),  /* Ouput Compare enabled */
    TC45_HCCDMODE_CAPT_gc = (0x02<<6),  /* Input Capture enabled */
    TC45_HCCDMODE_BOTHCC_gc = (0x03<<6),  /* Both Compare and Capture enabled */
} TC45_HCCDMODE_t;

/* Timer Trigger Restart Interrupt Level */
typedef enum TC45_TRGINTLVL_enum
{
    TC45_TRGINTLVL_OFF_gc = (0x00<<4),  /* Interrupt Disabled */
    TC45_TRGINTLVL_LO_gc = (0x01<<4),  /* Low Level */
    TC45_TRGINTLVL_MED_gc = (0x02<<4),  /* Medium Level */
    TC45_TRGINTLVL_HI_gc = (0x03<<4),  /* High Level */
} TC45_TRGINTLVL_t;

/* Error Interrupt Level */
typedef enum TC45_ERRINTLVL_enum
{
    TC45_ERRINTLVL_OFF_gc = (0x00<<2),  /* Interrupt Disabled */
    TC45_ERRINTLVL_LO_gc = (0x01<<2),  /* Low Level */
    TC45_ERRINTLVL_MED_gc = (0x02<<2),  /* Medium Level */
    TC45_ERRINTLVL_HI_gc = (0x03<<2),  /* High Level */
} TC45_ERRINTLVL_t;

/* Overflow Interrupt Level */
typedef enum TC45_OVFINTLVL_enum
{
    TC45_OVFINTLVL_OFF_gc = (0x00<<0),  /* Interrupt Disabled */
    TC45_OVFINTLVL_LO_gc = (0x01<<0),  /* Low Level */
    TC45_OVFINTLVL_MED_gc = (0x02<<0),  /* Medium Level */
    TC45_OVFINTLVL_HI_gc = (0x03<<0),  /* High Level */
} TC45_OVFINTLVL_t;

/* Compare or Capture Channel A Interrupt Level */
typedef enum TC45_CCAINTLVL_enum
{
    TC45_CCAINTLVL_OFF_gc = (0x00<<0),  /* Interrupt Disabled */
    TC45_CCAINTLVL_LO_gc = (0x01<<0),  /* Low Level */
    TC45_CCAINTLVL_MED_gc = (0x02<<0),  /* Medium Level */
    TC45_CCAINTLVL_HI_gc = (0x03<<0),  /* High Level */
} TC45_CCAINTLVL_t;

/* Compare or Capture Channel B Interrupt Level */
typedef enum TC45_CCBINTLVL_enum
{
    TC45_CCBINTLVL_OFF_gc = (0x00<<2),  /* Interrupt Disabled */
    TC45_CCBINTLVL_LO_gc = (0x01<<2),  /* Low Level */
    TC45_CCBINTLVL_MED_gc = (0x02<<2),  /* Medium Level */
    TC45_CCBINTLVL_HI_gc = (0x03<<2),  /* High Level */
} TC45_CCBINTLVL_t;

/* Compare or Capture Channel C Interrupt Level */
typedef enum TC45_CCCINTLVL_enum
{
    TC45_CCCINTLVL_OFF_gc = (0x00<<4),  /* Interrupt Disabled */
    TC45_CCCINTLVL_LO_gc = (0x01<<4),  /* Low Level */
    TC45_CCCINTLVL_MED_gc = (0x02<<4),  /* Medium Level */
    TC45_CCCINTLVL_HI_gc = (0x03<<4),  /* High Level */
} TC45_CCCINTLVL_t;

/* Compare or Capture Channel D Interrupt Level */
typedef enum TC45_CCDINTLVL_enum
{
    TC45_CCDINTLVL_OFF_gc = (0x00<<6),  /* Interrupt Disabled */
    TC45_CCDINTLVL_LO_gc = (0x01<<6),  /* Low Level */
    TC45_CCDINTLVL_MED_gc = (0x02<<6),  /* Medium Level */
    TC45_CCDINTLVL_HI_gc = (0x03<<6),  /* High Level */
} TC45_CCDINTLVL_t;

/* Compare or Capture Low Channel A Interrupt Level */
typedef enum TC45_LCCAINTLVL_enum
{
    TC45_LCCAINTLVL_OFF_gc = (0x00<<0),  /* Interrupt Disabled */
    TC45_LCCAINTLVL_LO_gc = (0x01<<0),  /* Low Level */
    TC45_LCCAINTLVL_MED_gc = (0x02<<0),  /* Medium Level */
    TC45_LCCAINTLVL_HI_gc = (0x03<<0),  /* High Level */
} TC45_LCCAINTLVL_t;

/* Compare or Capture Low Channel B Interrupt Level */
typedef enum TC45_LCCBINTLVL_enum
{
    TC45_LCCBINTLVL_OFF_gc = (0x00<<2),  /* Interrupt Disabled */
    TC45_LCCBINTLVL_LO_gc = (0x01<<2),  /* Low Level */
    TC45_LCCBINTLVL_MED_gc = (0x02<<2),  /* Medium Level */
    TC45_LCCBINTLVL_HI_gc = (0x03<<2),  /* High Level */
} TC45_LCCBINTLVL_t;

/* Compare or Capture Low Channel C Interrupt Level */
typedef enum TC45_LCCCINTLVL_enum
{
    TC45_LCCCINTLVL_OFF_gc = (0x00<<4),  /* Interrupt Disabled */
    TC45_LCCCINTLVL_LO_gc = (0x01<<4),  /* Low Level */
    TC45_LCCCINTLVL_MED_gc = (0x02<<4),  /* Medium Level */
    TC45_LCCCINTLVL_HI_gc = (0x03<<4),  /* High Level */
} TC45_LCCCINTLVL_t;

/* Compare or Capture Low Channel D Interrupt Level */
typedef enum TC45_LCCDINTLVL_enum
{
    TC45_LCCDINTLVL_OFF_gc = (0x00<<6),  /* Interrupt Disabled */
    TC45_LCCDINTLVL_LO_gc = (0x01<<6),  /* Low Level */
    TC45_LCCDINTLVL_MED_gc = (0x02<<6),  /* Medium Level */
    TC45_LCCDINTLVL_HI_gc = (0x03<<6),  /* High Level */
} TC45_LCCDINTLVL_t;

/* Timer/Counter Command */
typedef enum TC45_CMD_enum
{
    TC45_CMD_NONE_gc = (0x00<<2),  /* No Command */
    TC45_CMD_UPDATE_gc = (0x01<<2),  /* Force Update */
    TC45_CMD_RESTART_gc = (0x02<<2),  /* Force Restart */
    TC45_CMD_RESET_gc = (0x03<<2),  /* Force Hard Reset */
} TC45_CMD_t;


/*
--------------------------------------------------------------------------
FAULT - Fault Extension
--------------------------------------------------------------------------
*/

/* Fault Extension */
typedef struct FAULT_struct
{
    register8_t CTRLA;  /* Control A Register */
    register8_t CTRLB;  /* Control B Register */
    register8_t CTRLC;  /* Control C Register */
    register8_t CTRLD;  /* Control D Register */
    register8_t CTRLE;  /* Control E Register */
    register8_t STATUS;  /* Status Register */
    register8_t CTRLGCLR;  /* Control Register G Clear */
    register8_t CTRLGSET;  /* Control Register G set */
} FAULT_t;

/* Ramp Mode Selection */
typedef enum FAULT_RAMP_enum
{
    FAULT_RAMP_RAMP1_gc = (0x00<<6),  /* Normal Mode */
    FAULT_RAMP_RAMP2_gc = (0x02<<6),  /* RAMP2 Mode */
} FAULT_RAMP_t;

/* Fault E Input Source Selection */
typedef enum FAULT_SRCE_enum
{
    FAULT_SRCE_DISABLE_gc = (0x00<<0),  /* Fault Protection Disabled */
    FAULT_SRCE_CHN_gc = (0x01<<0),  /* Event Channel n */
    FAULT_SRCE_CHN1_gc = (0x02<<0),  /* Event Channel n+1 */
    FAULT_SRCE_CHN2_gc = (0x03<<0),  /* Event Channel n+2 */
} FAULT_SRCE_t;

/* Fault A Halt Action Selection */
typedef enum FAULT_HALTA_enum
{
    FAULT_HALTA_DISABLE_gc = (0x00<<5),  /* Halt Action Disabled */
    FAULT_HALTA_HW_gc = (0x01<<5),  /* Hardware Halt Action */
    FAULT_HALTA_SW_gc = (0x02<<5),  /* Software Halt Action */
} FAULT_HALTA_t;

/* Fault A Source Selection */
typedef enum FAULT_SRCA_enum
{
    FAULT_SRCA_DISABLE_gc = (0x00<<0),  /* Fault A Disabled */
    FAULT_SRCA_CHN_gc = (0x01<<0),  /* Event Channel n */
    FAULT_SRCA_CHN1_gc = (0x02<<0),  /* Event Channel n+1 */
    FAULT_SRCA_LINK_gc = (0x03<<0),  /* Fault A linked to Fault B State from previous cycle */
} FAULT_SRCA_t;

/* Fault B Halt Action Selection */
typedef enum FAULT_HALTB_enum
{
    FAULT_HALTB_DISABLE_gc = (0x00<<5),  /* Halt Action Disabled */
    FAULT_HALTB_HW_gc = (0x01<<5),  /* Hardware Halt Action */
    FAULT_HALTB_SW_gc = (0x02<<5),  /* Software Halt Action */
} FAULT_HALTB_t;

/* Fault B Source Selection */
typedef enum FAULT_SRCB_enum
{
    FAULT_SRCB_DISABLE_gc = (0x00<<0),  /* Fault B disabled */
    FAULT_SRCB_CHN_gc = (0x01<<0),  /* Event Channel n */
    FAULT_SRCB_CHN1_gc = (0x02<<0),  /* Event Channel n+1 */
    FAULT_SRCB_LINK_gc = (0x03<<0),  /* Fault B linked to Fault A State from previous cycle */
} FAULT_SRCB_t;

/* Channel index Command */
typedef enum FAULT_IDXCMD_enum
{
    FAULT_IDXCMD_DISABLE_gc = (0x00<<3),  /* Command Disabled */
    FAULT_IDXCMD_SET_gc = (0x01<<3),  /* Force Cycle B in Next Cycle */
    FAULT_IDXCMD_CLEAR_gc = (0x02<<3),  /* Force Cycle A in Next Cycle */
    FAULT_IDXCMD_HOLD_gc = (0x03<<3),  /* Hold Current Cycle Index in Next Cycle  */
} FAULT_IDXCMD_t;


/*
--------------------------------------------------------------------------
WEX - Waveform Extension
--------------------------------------------------------------------------
*/

/* Waveform Extension */
typedef struct WEX_struct
{
    register8_t CTRL;  /* Control Register */
    register8_t DTBOTH;  /* Dead-time Concurrent Write to Both Sides Register */
    register8_t DTLS;  /* Dead-time Low Side Register */
    register8_t DTHS;  /* Dead-time High Side Register */
    register8_t STATUSCLR;  /* Status Clear Register */
    register8_t STATUSSET;  /* Status Set Register */
    register8_t SWAP;  /* Swap Register */
    register8_t PGO;  /* Pattern Generation Override Register */
    register8_t PGV;  /* Pattern Generation Value Register */
    register8_t reserved_0x09;
    register8_t SWAPBUF;  /* Dead Time Low Side Buffer */
    register8_t PGOBUF;  /* Pattern Generation Overwrite Buffer Register */
    register8_t PGVBUF;  /* Pattern Generation Value Buffer Register */
    register8_t reserved_0x0D;
    register8_t reserved_0x0E;
    register8_t OUTOVDIS;  /* Output Override Disable Register  */
} WEX_t;

/* Output Matrix Mode */
typedef enum WEX_OTMX_enum
{
    WEX_OTMX_DEFAULT_gc = (0x00<<4),  /* Default Ouput Matrix Mode */
    WEX_OTMX_FIRST_gc = (0x01<<4),  /* First Output matrix Mode */
    WEX_OTMX_SECOND_gc = (0x02<<4),  /* Second Output matrix Mode */
    WEX_OTMX_THIRD_gc = (0x03<<4),  /* Third Output matrix Mode */
    WEX_OTMX_FOURTH_gc = (0x04<<4),  /* Fourth Output matrix Mode */
} WEX_OTMX_t;


/*
--------------------------------------------------------------------------
HIRES - High-Resolution Extension
--------------------------------------------------------------------------
*/

/* High-Resolution Extension */
typedef struct HIRES_struct
{
    register8_t CTRLA;  /* Control Register A */
} HIRES_t;

/* High Resolution Plus Mode */
typedef enum HIRES_HRPLUS_enum
{
    HIRES_HRPLUS_NONE_gc = (0x00<<2),  /* No Hi-Res Plus */
    HIRES_HRPLUS_HRP4_gc = (0x01<<2),  /* Hi-Res Plus enabled on Timer 4 */
    HIRES_HRPLUS_HRP5_gc = (0x02<<2),  /* Hi-Res Plus enabled on Timer 5 */
    HIRES_HRPLUS_BOTH_gc = (0x03<<2),  /* Hi-Res Plus enabled on Timer 4 and 5 */
} HIRES_HRPLUS_t;

/* High Resolution Mode */
typedef enum HIRES_HREN_enum
{
    HIRES_HREN_NONE_gc = (0x00<<0),  /* No Hi-Res */
    HIRES_HREN_HRP4_gc = (0x01<<0),  /* Hi-Res enabled on Timer 4 */
    HIRES_HREN_HRP5_gc = (0x02<<0),  /* Hi-Res enabled on Timer 5 */
    HIRES_HREN_BOTH_gc = (0x03<<0),  /* Hi-Res enabled on Timer 4 and 5 */
} HIRES_HREN_t;


/*
--------------------------------------------------------------------------
USART - Universal Asynchronous Receiver-Transmitter
--------------------------------------------------------------------------
*/

/* Universal Synchronous/Asynchronous Receiver/Transmitter */
typedef struct USART_struct
{
    register8_t DATA;  /* Data Register */
    register8_t STATUS;  /* Status Register */
    register8_t CTRLA;  /* Control Register A */
    register8_t CTRLB;  /* Control Register B */
    register8_t CTRLC;  /* Control Register C */
    register8_t CTRLD;  /* Control Register D */
    register8_t BAUDCTRLA;  /* Baud Rate Control Register A */
    register8_t BAUDCTRLB;  /* Baud Rate Control Register B */
} USART_t;

/* Receive Start Interrupt level */
typedef enum USART_RXSINTLVL_enum
{
    USART_RXSINTLVL_OFF_gc = (0x00<<0),  /* Interrupt Disabled */
    USART_RXSINTLVL_LO_gc = (0x01<<0),  /* Low Level */
    USART_RXSINTLVL_MED_gc = (0x02<<0),  /* Medium Level */
    USART_RXSINTLVL_HI_gc = (0x03<<0),  /* High Level */
} USART_RXSINTLVL_t;

/* Receive Complete Interrupt level */
typedef enum USART_RXCINTLVL_enum
{
    USART_RXCINTLVL_OFF_gc = (0x00<<4),  /* Interrupt Disabled */
    USART_RXCINTLVL_LO_gc = (0x01<<4),  /* Low Level */
    USART_RXCINTLVL_MED_gc = (0x02<<4),  /* Medium Level */
    USART_RXCINTLVL_HI_gc = (0x03<<4),  /* High Level */
} USART_RXCINTLVL_t;

/* Transmit Complete Interrupt level */
typedef enum USART_TXCINTLVL_enum
{
    USART_TXCINTLVL_OFF_gc = (0x00<<2),  /* Interrupt Disabled */
    USART_TXCINTLVL_LO_gc = (0x01<<2),  /* Low Level */
    USART_TXCINTLVL_MED_gc = (0x02<<2),  /* Medium Level */
    USART_TXCINTLVL_HI_gc = (0x03<<2),  /* High Level */
} USART_TXCINTLVL_t;

/* Data Register Empty Interrupt level */
typedef enum USART_DREINTLVL_enum
{
    USART_DREINTLVL_OFF_gc = (0x00<<0),  /* Interrupt Disabled */
    USART_DREINTLVL_LO_gc = (0x01<<0),  /* Low Level */
    USART_DREINTLVL_MED_gc = (0x02<<0),  /* Medium Level */
    USART_DREINTLVL_HI_gc = (0x03<<0),  /* High Level */
} USART_DREINTLVL_t;

/* Character Size */
typedef enum USART_CHSIZE_enum
{
    USART_CHSIZE_5BIT_gc = (0x00<<0),  /* Character size: 5 bit */
    USART_CHSIZE_6BIT_gc = (0x01<<0),  /* Character size: 6 bit */
    USART_CHSIZE_7BIT_gc = (0x02<<0),  /* Character size: 7 bit */
    USART_CHSIZE_8BIT_gc = (0x03<<0),  /* Character size: 8 bit */
    USART_CHSIZE_9BIT_gc = (0x07<<0),  /* Character size: 9 bit */
} USART_CHSIZE_t;

/* Communication Mode */
typedef enum USART_CMODE_enum
{
    USART_CMODE_ASYNCHRONOUS_gc = (0x00<<6),  /* Asynchronous Mode */
    USART_CMODE_SYNCHRONOUS_gc = (0x01<<6),  /* Synchronous Mode */
    USART_CMODE_IRDA_gc = (0x02<<6),  /* IrDA Mode */
    USART_CMODE_MSPI_gc = (0x03<<6),  /* Master SPI Mode */
} USART_CMODE_t;

/* Parity Mode */
typedef enum USART_PMODE_enum
{
    USART_PMODE_DISABLED_gc = (0x00<<4),  /* No Parity */
    USART_PMODE_EVEN_gc = (0x02<<4),  /* Even Parity */
    USART_PMODE_ODD_gc = (0x03<<4),  /* Odd Parity */
} USART_PMODE_t;

/* Encoding and Decoding Type */
typedef enum USART_DECTYPE_enum
{
    USART_DECTYPE_DATA_gc = (0x00<<4),  /* DATA Field Encoding */
    USART_DECTYPE_SDATA_gc = (0x02<<4),  /* Start and Data Fields Encoding */
    USART_DECTYPE_NOTSDATA_gc = (0x03<<4),  /* Start and Data Fields Encoding, with invertion in START field */
} USART_DECTYPE_t;

/* XCL LUT Action */
typedef enum USART_LUTACT_enum
{
    USART_LUTACT_OFF_gc = (0x00<<2),  /* Standard Frame Configuration */
    USART_LUTACT_RX_gc = (0x01<<2),  /* Receiver Decoding Enabled */
    USART_LUTACT_TX_gc = (0x02<<2),  /* Transmitter Encoding Enabled */
    USART_LUTACT_BOTH_gc = (0x03<<2),  /* Both Encoding and Decoding Enabled */
} USART_LUTACT_t;

/* XCL Peripheral Counter Action */
typedef enum USART_PECACT_enum
{
    USART_PECACT_OFF_gc = (0x00<<0),  /* Standard Mode */
    USART_PECACT_PEC0_gc = (0x01<<0),  /* Variable Data Lenght in Reception */
    USART_PECACT_PEC1_gc = (0x02<<0),  /* Variable Data Lenght in Transmission */
    USART_PECACT_PERC01_gc = (0x03<<0),  /* Variable Data Lenght in both Reception and Transmission */
} USART_PECACT_t;


/*
--------------------------------------------------------------------------
SPI - Serial Peripheral Interface
--------------------------------------------------------------------------
*/

/* Serial Peripheral Interface with Buffer Modes */
typedef struct SPI_struct
{
    register8_t CTRL;  /* Control Register */
    register8_t INTCTRL;  /* Interrupt Control Register */
    register8_t STATUS;  /* Status Register */
    register8_t DATA;  /* Data Register */
    register8_t CTRLB;  /* Control Register B */
} SPI_t;

/* SPI Mode */
typedef enum SPI_MODE_enum
{
    SPI_MODE_0_gc = (0x00<<2),  /* SPI Mode 0, base clock at "0", sampling on leading edge (rising) & set-up on trailling edge (falling). */
    SPI_MODE_1_gc = (0x01<<2),  /* SPI Mode 1, base clock at "0", set-up on leading edge (rising) & sampling on trailling edge (falling). */
    SPI_MODE_2_gc = (0x02<<2),  /* SPI Mode 2, base clock at "1", sampling on leading edge (falling) & set-up on trailling edge (rising). */
    SPI_MODE_3_gc = (0x03<<2),  /* SPI Mode 3, base clock at "1", set-up on leading edge (falling) & sampling on trailling edge (rising). */
} SPI_MODE_t;

/* Prescaler setting */
typedef enum SPI_PRESCALER_enum
{
    SPI_PRESCALER_DIV4_gc = (0x00<<0),  /* If CLK2X=1 CLKper/2, else (CLK2X=0) CLKper/4. */
    SPI_PRESCALER_DIV16_gc = (0x01<<0),  /* If CLK2X=1 CLKper/8, else (CLK2X=0) CLKper/16. */
    SPI_PRESCALER_DIV64_gc = (0x02<<0),  /* If CLK2X=1 CLKper/32, else (CLK2X=0) CLKper/64. */
    SPI_PRESCALER_DIV128_gc = (0x03<<0),  /* If CLK2X=1 CLKper/64, else (CLK2X=0) CLKper/128. */
} SPI_PRESCALER_t;

/* Interrupt level */
typedef enum SPI_INTLVL_enum
{
    SPI_INTLVL_OFF_gc = (0x00<<0),  /* Interrupt Disabled */
    SPI_INTLVL_LO_gc = (0x01<<0),  /* Low Level */
    SPI_INTLVL_MED_gc = (0x02<<0),  /* Medium Level */
    SPI_INTLVL_HI_gc = (0x03<<0),  /* High Level */
} SPI_INTLVL_t;

/* Buffer Modes */
typedef enum SPI_BUFMODE_enum
{
    SPI_BUFMODE_OFF_gc = (0x00<<6),  /* SPI Unbuffered Mode */
    SPI_BUFMODE_BUFMODE1_gc = (0x02<<6),  /* Buffer Mode 1 (with dummy byte) */
    SPI_BUFMODE_BUFMODE2_gc = (0x03<<6),  /* Buffer Mode 2 (no dummy byte) */
} SPI_BUFMODE_t;


/*
--------------------------------------------------------------------------
IRCOM - IR Communication Module
--------------------------------------------------------------------------
*/

/* IR Communication Module */
typedef struct IRCOM_struct
{
    register8_t CTRL;  /* Control Register */
    register8_t TXPLCTRL;  /* IrDA Transmitter Pulse Length Control Register */
    register8_t RXPLCTRL;  /* IrDA Receiver Pulse Length Control Register */
} IRCOM_t;

/* Event channel selection */
typedef enum IRDA_EVSEL_enum
{
    IRDA_EVSEL_OFF_gc = (0x00<<0),  /* No Event Source */
    IRDA_EVSEL_0_gc = (0x08<<0),  /* Event Channel 0 */
    IRDA_EVSEL_1_gc = (0x09<<0),  /* Event Channel 1 */
    IRDA_EVSEL_2_gc = (0x0A<<0),  /* Event Channel 2 */
    IRDA_EVSEL_3_gc = (0x0B<<0),  /* Event Channel 3 */
    IRDA_EVSEL_4_gc = (0x0C<<0),  /* Event Channel 4 */
    IRDA_EVSEL_5_gc = (0x0D<<0),  /* Event Channel 5 */
    IRDA_EVSEL_6_gc = (0x0E<<0),  /* Event Channel 6 */
    IRDA_EVSEL_7_gc = (0x0F<<0),  /* Event Channel 7 */
} IRDA_EVSEL_t;


/*
--------------------------------------------------------------------------
FUSE - Fuses and Lockbits
--------------------------------------------------------------------------
*/

/* Lock Bits */
typedef struct NVM_LOCKBITS_struct
{
    register8_t LOCK_BITS;  /* Lock Bits (Changed from LOCKBITS to avoid avr-libc collision) */
} NVM_LOCKBITS_t;


/* Fuses */
typedef struct NVM_FUSES_struct
{
    register8_t reserved_0x00;
    register8_t FUSEBYTE1;  /* Watchdog Configuration */
    register8_t FUSEBYTE2;  /* Reset Configuration */
    register8_t reserved_0x03;
    register8_t FUSEBYTE4;  /* Start-up Configuration */
    register8_t FUSEBYTE5;  /* EESAVE and BOD Level */
    register8_t FUSEBYTE6;  /* Fault State */
} NVM_FUSES_t;

/* Boot lock bits - boot setcion */
typedef enum FUSE_BLBB_enum
{
    FUSE_BLBB_RWLOCK_gc = (0x00<<6),  /* Read and write not allowed */
    FUSE_BLBB_RLOCK_gc = (0x01<<6),  /* Read not allowed */
    FUSE_BLBB_WLOCK_gc = (0x02<<6),  /* Write not allowed */
    FUSE_BLBB_NOLOCK_gc = (0x03<<6),  /* No locks */
} FUSE_BLBB_t;

/* Boot lock bits - application section */
typedef enum FUSE_BLBA_enum
{
    FUSE_BLBA_RWLOCK_gc = (0x00<<4),  /* Read and write not allowed */
    FUSE_BLBA_RLOCK_gc = (0x01<<4),  /* Read not allowed */
    FUSE_BLBA_WLOCK_gc = (0x02<<4),  /* Write not allowed */
    FUSE_BLBA_NOLOCK_gc = (0x03<<4),  /* No locks */
} FUSE_BLBA_t;

/* Boot lock bits - application table section */
typedef enum FUSE_BLBAT_enum
{
    FUSE_BLBAT_RWLOCK_gc = (0x00<<2),  /* Read and write not allowed */
    FUSE_BLBAT_RLOCK_gc = (0x01<<2),  /* Read not allowed */
    FUSE_BLBAT_WLOCK_gc = (0x02<<2),  /* Write not allowed */
    FUSE_BLBAT_NOLOCK_gc = (0x03<<2),  /* No locks */
} FUSE_BLBAT_t;

/* Lock bits */
typedef enum FUSE_LB_enum
{
    FUSE_LB_RWLOCK_gc = (0x00<<0),  /* Read and write not allowed */
    FUSE_LB_WLOCK_gc = (0x02<<0),  /* Write not allowed */
    FUSE_LB_NOLOCK_gc = (0x03<<0),  /* No locks */
} FUSE_LB_t;

/* Boot Loader Section Reset Vector */
typedef enum BOOTRST_enum
{
    BOOTRST_BOOTLDR_gc = (0x00<<6),  /* Boot Loader Reset */
    BOOTRST_APPLICATION_gc = (0x01<<6),  /* Application Reset */
} BOOTRST_t;

/* BOD operation */
typedef enum BOD_enum
{
    BOD_SAMPLED_gc = (0x01<<4),  /* BOD enabled in sampled mode */
    BOD_CONTINUOUS_gc = (0x02<<4),  /* BOD enabled continuously */
    BOD_DISABLED_gc = (0x03<<4),  /* BOD Disabled */
} BOD_t;

/* Watchdog (Window) Timeout Period */
typedef enum WD_enum
{
    WD_8CLK_gc = (0x00<<4),  /* 8 cycles (8ms @ 3.3V) */
    WD_16CLK_gc = (0x01<<4),  /* 16 cycles (16ms @ 3.3V) */
    WD_32CLK_gc = (0x02<<4),  /* 32 cycles (32ms @ 3.3V) */
    WD_64CLK_gc = (0x03<<4),  /* 64 cycles (64ms @ 3.3V) */
    WD_128CLK_gc = (0x04<<4),  /* 128 cycles (0.125s @ 3.3V) */
    WD_256CLK_gc = (0x05<<4),  /* 256 cycles (0.25s @ 3.3V) */
    WD_512CLK_gc = (0x06<<4),  /* 512 cycles (0.5s @ 3.3V) */
    WD_1KCLK_gc = (0x07<<4),  /* 1K cycles (1s @ 3.3V) */
    WD_2KCLK_gc = (0x08<<4),  /* 2K cycles (2s @ 3.3V) */
    WD_4KCLK_gc = (0x09<<4),  /* 4K cycles (4s @ 3.3V) */
    WD_8KCLK_gc = (0x0A<<4),  /* 8K cycles (8s @ 3.3V) */
} WD_t;

/* Start-up Time */
typedef enum SUT_enum
{
    SUT_0MS_gc = (0x03<<2),  /* 0 ms */
    SUT_4MS_gc = (0x01<<2),  /* 4 ms */
    SUT_64MS_gc = (0x00<<2),  /* 64 ms */
} SUT_t;

/* Brownout Detection Voltage Level */
typedef enum BODLVL_enum
{
    BODLVL_1V6_gc = (0x07<<0),  /* 1.6 V */
    BODLVL_1V8_gc = (0x06<<0),  /* 1.8 V */
    BODLVL_2V0_gc = (0x05<<0),  /* 2.0 V */
    BODLVL_2V2_gc = (0x04<<0),  /* 2.2 V */
    BODLVL_2V4_gc = (0x03<<0),  /* 2.4 V */
    BODLVL_2V6_gc = (0x02<<0),  /* 2.6 V */
    BODLVL_2V8_gc = (0x01<<0),  /* 2.8 V */
    BODLVL_3V0_gc = (0x00<<0),  /* 3.0 V */
} BODLVL_t;


/*
--------------------------------------------------------------------------
SIGROW - Signature Row
--------------------------------------------------------------------------
*/

/* Production Signatures */
typedef struct NVM_PROD_SIGNATURES_struct
{
    register8_t RCOSC8M;  /* RCOSC 8MHz Calibration Value */
    register8_t reserved_0x01;
    register8_t RCOSC32K;  /* RCOSC 32.768 kHz Calibration Value */
    register8_t RCOSC32M;  /* RCOSC 32 MHz Calibration Value B */
    register8_t RCOSC32MA;  /* RCOSC 32 MHz Calibration Value A */
    register8_t reserved_0x05;
    register8_t reserved_0x06;
    register8_t reserved_0x07;
    register8_t LOTNUM0;  /* Lot Number Byte 0, ASCII */
    register8_t LOTNUM1;  /* Lot Number Byte 1, ASCII */
    register8_t LOTNUM2;  /* Lot Number Byte 2, ASCII */
    register8_t LOTNUM3;  /* Lot Number Byte 3, ASCII */
    register8_t LOTNUM4;  /* Lot Number Byte 4, ASCII */
    register8_t LOTNUM5;  /* Lot Number Byte 5, ASCII */
    register8_t reserved_0x0E;
    register8_t reserved_0x0F;
    register8_t WAFNUM;  /* Wafer Number */
    register8_t reserved_0x11;
    register8_t COORDX0;  /* Wafer Coordinate X Byte 0 */
    register8_t COORDX1;  /* Wafer Coordinate X Byte 1 */
    register8_t COORDY0;  /* Wafer Coordinate Y Byte 0 */
    register8_t COORDY1;  /* Wafer Coordinate Y Byte 1 */
    register8_t reserved_0x16;
    register8_t reserved_0x17;
    register8_t reserved_0x18;
    register8_t reserved_0x19;
    register8_t reserved_0x1A;
    register8_t reserved_0x1B;
    register8_t reserved_0x1C;
    register8_t reserved_0x1D;
    register8_t ROOMTEMP;  /* Temperature corresponds to TEMPSENSE3/2 */
    register8_t HOTTEMP;  /* Temperature corresponds to TEMPSENSE1/0 */
    register8_t ADCACAL0;  /* ADCA Calibration Byte 0 */
    register8_t ADCACAL1;  /* ADCA Calibration Byte 1 */
    register8_t reserved_0x22;
    register8_t reserved_0x23;
    register8_t reserved_0x24;
    register8_t reserved_0x25;
    register8_t reserved_0x26;
    register8_t reserved_0x27;
    register8_t ACACURRCAL;  /* ACA Current Calibration Byte */
    register8_t reserved_0x29;
    register8_t reserved_0x2A;
    register8_t reserved_0x2B;
    register8_t TEMPSENSE2;  /* Temperature Sensor Calibration Byte 2 */
    register8_t TEMPSENSE3;  /* Temperature Sensor Calibration Byte 3 */
    register8_t TEMPSENSE0;  /* Temperature Sensor Calibration Byte 0 */
    register8_t TEMPSENSE1;  /* Temperature Sensor Calibration Byte 1 */
    register8_t DACA0OFFCAL;  /* DACA0 Calibration Byte 0 */
    register8_t DACA0GAINCAL;  /* DACA0 Calibration Byte 1 */
    register8_t reserved_0x32;
    register8_t reserved_0x33;
    register8_t DACA1OFFCAL;  /* DACA1 Calibration Byte 0 */
    register8_t DACA1GAINCAL;  /* DACA1 Calibration Byte 1 */
    register8_t reserved_0x36;
    register8_t reserved_0x37;
    register8_t reserved_0x38;
    register8_t reserved_0x39;
    register8_t reserved_0x3A;
    register8_t reserved_0x3B;
    register8_t reserved_0x3C;
    register8_t reserved_0x3D;
    register8_t reserved_0x3E;
    register8_t reserved_0x3F;
} NVM_PROD_SIGNATURES_t;

/*
==========================================================================
IO Module Instances. Mapped to memory.
==========================================================================
*/

#define VPORT0    (*(VPORT_t *) 0x0010)  /* Virtual Port */
#define VPORT1    (*(VPORT_t *) 0x0014)  /* Virtual Port */
#define VPORT2    (*(VPORT_t *) 0x0018)  /* Virtual Port */
#define VPORT3    (*(VPORT_t *) 0x001C)  /* Virtual Port */
#define OCD    (*(OCD_t *) 0x002E)  /* On-Chip Debug System */
#define CLK    (*(CLK_t *) 0x0040)  /* Clock System */
#define SLEEP    (*(SLEEP_t *) 0x0048)  /* Sleep Controller */
#define OSC    (*(OSC_t *) 0x0050)  /* Oscillator */
#define DFLLRC32M    (*(DFLL_t *) 0x0060)  /* DFLL */
#define PR    (*(PR_t *) 0x0070)  /* Power Reduction */
#define RST    (*(RST_t *) 0x0078)  /* Reset */
#define WDT    (*(WDT_t *) 0x0080)  /* Watch-Dog Timer */
#define MCU    (*(MCU_t *) 0x0090)  /* MCU Control */
#define PMIC    (*(PMIC_t *) 0x00A0)  /* Programmable Multi-level Interrupt Controller */
#define PORTCFG    (*(PORTCFG_t *) 0x00B0)  /* I/O port Configuration */
#define CRC    (*(CRC_t *) 0x00D0)  /* Cyclic Redundancy Checker */
#define EDMA    (*(EDMA_t *) 0x0100)  /* Enhanced DMA Controller */
#define EVSYS    (*(EVSYS_t *) 0x0180)  /* Event System */
#define NVM    (*(NVM_t *) 0x01C0)  /* Non-volatile Memory Controller */
#define ADCA    (*(ADC_t *) 0x0200)  /* Analog-to-Digital Converter */
#define DACA    (*(DAC_t *) 0x0300)  /* Digital-to-Analog Converter */
#define ACA    (*(AC_t *) 0x0380)  /* Analog Comparator */
#define RTC    (*(RTC_t *) 0x0400)  /* Real-Time Counter */
#define XCL    (*(XCL_t *) 0x0460)  /* XMEGA Custom Logic */
#define TWIC    (*(TWI_t *) 0x0480)  /* Two-Wire Interface */
#define PORTA    (*(PORT_t *) 0x0600)  /* I/O Ports */
#define PORTC    (*(PORT_t *) 0x0640)  /* I/O Ports */
#define PORTD    (*(PORT_t *) 0x0660)  /* I/O Ports */
#define PORTR    (*(PORT_t *) 0x07E0)  /* I/O Ports */
#define TCC4    (*(TC4_t *) 0x0800)  /* 16-bit Timer/Counter 4 */
#define TCC5    (*(TC5_t *) 0x0840)  /* 16-bit Timer/Counter 5 */
#define FAULTC4    (*(FAULT_t *) 0x0880)  /* Fault Extension */
#define FAULTC5    (*(FAULT_t *) 0x0890)  /* Fault Extension */
#define WEXC    (*(WEX_t *) 0x08A0)  /* Waveform Extension */
#define HIRESC    (*(HIRES_t *) 0x08B0)  /* High-Resolution Extension */
#define USARTC0    (*(USART_t *) 0x08C0)  /* Universal Synchronous/Asynchronous Receiver/Transmitter */
#define SPIC    (*(SPI_t *) 0x08E0)  /* Serial Peripheral Interface with Buffer Modes */
#define IRCOM    (*(IRCOM_t *) 0x08F8)  /* IR Communication Module */
#define TCD5    (*(TC5_t *) 0x0940)  /* 16-bit Timer/Counter 5 */
#define USARTD0    (*(USART_t *) 0x09C0)  /* Universal Synchronous/Asynchronous Receiver/Transmitter */


#endif /* !defined (__ASSEMBLER__) */


/* ========== Flattened fully qualified IO register names ========== */

/* GPIO - General Purpose IO Registers */
#define GPIO_GPIOR0  _SFR_MEM8(0x0000)
#define GPIO_GPIOR1  _SFR_MEM8(0x0001)
#define GPIO_GPIOR2  _SFR_MEM8(0x0002)
#define GPIO_GPIOR3  _SFR_MEM8(0x0003)

/* Deprecated */
#define GPIO_GPIO0  _SFR_MEM8(0x0000)
#define GPIO_GPIO1  _SFR_MEM8(0x0001)
#define GPIO_GPIO2  _SFR_MEM8(0x0002)
#define GPIO_GPIO3  _SFR_MEM8(0x0003)

/* NVM_FUSES - Fuses */
#define FUSE_FUSEBYTE1  _SFR_MEM8(0x0001)
#define FUSE_FUSEBYTE2  _SFR_MEM8(0x0002)
#define FUSE_FUSEBYTE4  _SFR_MEM8(0x0004)
#define FUSE_FUSEBYTE5  _SFR_MEM8(0x0005)
#define FUSE_FUSEBYTE6  _SFR_MEM8(0x0006)

/* NVM_LOCKBITS - Lock Bits */
#define LOCKBIT_LOCKBITS  _SFR_MEM8(0x0000)

/* NVM_PROD_SIGNATURES - Production Signatures */
#define PRODSIGNATURES_RCOSC8M  _SFR_MEM8(0x0000)
#define PRODSIGNATURES_RCOSC32K  _SFR_MEM8(0x0002)
#define PRODSIGNATURES_RCOSC32M  _SFR_MEM8(0x0003)
#define PRODSIGNATURES_RCOSC32MA  _SFR_MEM8(0x0004)
#define PRODSIGNATURES_LOTNUM0  _SFR_MEM8(0x0008)
#define PRODSIGNATURES_LOTNUM1  _SFR_MEM8(0x0009)
#define PRODSIGNATURES_LOTNUM2  _SFR_MEM8(0x000A)
#define PRODSIGNATURES_LOTNUM3  _SFR_MEM8(0x000B)
#define PRODSIGNATURES_LOTNUM4  _SFR_MEM8(0x000C)
#define PRODSIGNATURES_LOTNUM5  _SFR_MEM8(0x000D)
#define PRODSIGNATURES_WAFNUM  _SFR_MEM8(0x0010)
#define PRODSIGNATURES_COORDX0  _SFR_MEM8(0x0012)
#define PRODSIGNATURES_COORDX1  _SFR_MEM8(0x0013)
#define PRODSIGNATURES_COORDY0  _SFR_MEM8(0x0014)
#define PRODSIGNATURES_COORDY1  _SFR_MEM8(0x0015)
#define PRODSIGNATURES_ROOMTEMP  _SFR_MEM8(0x001E)
#define PRODSIGNATURES_HOTTEMP  _SFR_MEM8(0x001F)
#define PRODSIGNATURES_ADCACAL0  _SFR_MEM8(0x0020)
#define PRODSIGNATURES_ADCACAL1  _SFR_MEM8(0x0021)
#define PRODSIGNATURES_ACACURRCAL  _SFR_MEM8(0x0028)
#define PRODSIGNATURES_TEMPSENSE2  _SFR_MEM8(0x002C)
#define PRODSIGNATURES_TEMPSENSE3  _SFR_MEM8(0x002D)
#define PRODSIGNATURES_TEMPSENSE0  _SFR_MEM8(0x002E)
#define PRODSIGNATURES_TEMPSENSE1  _SFR_MEM8(0x002F)
#define PRODSIGNATURES_DACA0OFFCAL  _SFR_MEM8(0x0030)
#define PRODSIGNATURES_DACA0GAINCAL  _SFR_MEM8(0x0031)
#define PRODSIGNATURES_DACA1OFFCAL  _SFR_MEM8(0x0034)
#define PRODSIGNATURES_DACA1GAINCAL  _SFR_MEM8(0x0035)

/* VPORT - Virtual Port */
#define VPORT0_DIR  _SFR_MEM8(0x0010)
#define VPORT0_OUT  _SFR_MEM8(0x0011)
#define VPORT0_IN  _SFR_MEM8(0x0012)
#define VPORT0_INTFLAGS  _SFR_MEM8(0x0013)

/* VPORT - Virtual Port */
#define VPORT1_DIR  _SFR_MEM8(0x0014)
#define VPORT1_OUT  _SFR_MEM8(0x0015)
#define VPORT1_IN  _SFR_MEM8(0x0016)
#define VPORT1_INTFLAGS  _SFR_MEM8(0x0017)

/* VPORT - Virtual Port */
#define VPORT2_DIR  _SFR_MEM8(0x0018)
#define VPORT2_OUT  _SFR_MEM8(0x0019)
#define VPORT2_IN  _SFR_MEM8(0x001A)
#define VPORT2_INTFLAGS  _SFR_MEM8(0x001B)

/* VPORT - Virtual Port */
#define VPORT3_DIR  _SFR_MEM8(0x001C)
#define VPORT3_OUT  _SFR_MEM8(0x001D)
#define VPORT3_IN  _SFR_MEM8(0x001E)
#define VPORT3_INTFLAGS  _SFR_MEM8(0x001F)

/* OCD - On-Chip Debug System */
#define OCD_OCDR0  _SFR_MEM8(0x002E)
#define OCD_OCDR1  _SFR_MEM8(0x002F)

/* CPU - CPU registers */
#define CPU_CCP  _SFR_MEM8(0x0034)
#define CPU_RAMPD  _SFR_MEM8(0x0038)
#define CPU_RAMPX  _SFR_MEM8(0x0039)
#define CPU_RAMPY  _SFR_MEM8(0x003A)
#define CPU_RAMPZ  _SFR_MEM8(0x003B)
#define CPU_EIND  _SFR_MEM8(0x003C)
#define CPU_SPL  _SFR_MEM8(0x003D)
#define CPU_SPH  _SFR_MEM8(0x003E)
#define CPU_SREG  _SFR_MEM8(0x003F)

/* CLK - Clock System */
#define CLK_CTRL  _SFR_MEM8(0x0040)
#define CLK_PSCTRL  _SFR_MEM8(0x0041)
#define CLK_LOCK  _SFR_MEM8(0x0042)
#define CLK_RTCCTRL  _SFR_MEM8(0x0043)

/* SLEEP - Sleep Controller */
#define SLEEP_CTRL  _SFR_MEM8(0x0048)

/* OSC - Oscillator */
#define OSC_CTRL  _SFR_MEM8(0x0050)
#define OSC_STATUS  _SFR_MEM8(0x0051)
#define OSC_XOSCCTRL  _SFR_MEM8(0x0052)
#define OSC_XOSCFAIL  _SFR_MEM8(0x0053)
#define OSC_RC32KCAL  _SFR_MEM8(0x0054)
#define OSC_PLLCTRL  _SFR_MEM8(0x0055)
#define OSC_DFLLCTRL  _SFR_MEM8(0x0056)
#define OSC_RC8MCAL  _SFR_MEM8(0x0057)

/* DFLL - DFLL */
#define DFLLRC32M_CTRL  _SFR_MEM8(0x0060)
#define DFLLRC32M_CALA  _SFR_MEM8(0x0062)
#define DFLLRC32M_CALB  _SFR_MEM8(0x0063)
#define DFLLRC32M_COMP0  _SFR_MEM8(0x0064)
#define DFLLRC32M_COMP1  _SFR_MEM8(0x0065)
#define DFLLRC32M_COMP2  _SFR_MEM8(0x0066)

/* PR - Power Reduction */
#define PR_PRGEN  _SFR_MEM8(0x0070)
#define PR_PRPA  _SFR_MEM8(0x0071)
#define PR_PRPC  _SFR_MEM8(0x0073)
#define PR_PRPD  _SFR_MEM8(0x0074)

/* RST - Reset */
#define RST_STATUS  _SFR_MEM8(0x0078)
#define RST_CTRL  _SFR_MEM8(0x0079)

/* WDT - Watch-Dog Timer */
#define WDT_CTRL  _SFR_MEM8(0x0080)
#define WDT_WINCTRL  _SFR_MEM8(0x0081)
#define WDT_STATUS  _SFR_MEM8(0x0082)

/* MCU - MCU Control */
#define MCU_DEVID0  _SFR_MEM8(0x0090)
#define MCU_DEVID1  _SFR_MEM8(0x0091)
#define MCU_DEVID2  _SFR_MEM8(0x0092)
#define MCU_REVID  _SFR_MEM8(0x0093)
#define MCU_ANAINIT  _SFR_MEM8(0x0097)
#define MCU_EVSYSLOCK  _SFR_MEM8(0x0098)
#define MCU_WEXLOCK  _SFR_MEM8(0x0099)
#define MCU_FAULTLOCK  _SFR_MEM8(0x009A)

/* PMIC - Programmable Multi-level Interrupt Controller */
#define PMIC_STATUS  _SFR_MEM8(0x00A0)
#define PMIC_INTPRI  _SFR_MEM8(0x00A1)
#define PMIC_CTRL  _SFR_MEM8(0x00A2)

/* PORTCFG - I/O port Configuration */
#define PORTCFG_MPCMASK  _SFR_MEM8(0x00B0)
#define PORTCFG_CLKOUT  _SFR_MEM8(0x00B4)
#define PORTCFG_ACEVOUT  _SFR_MEM8(0x00B6)
#define PORTCFG_SRLCTRL  _SFR_MEM8(0x00B7)

/* CRC - Cyclic Redundancy Checker */
#define CRC_CTRL  _SFR_MEM8(0x00D0)
#define CRC_STATUS  _SFR_MEM8(0x00D1)
#define CRC_DATAIN  _SFR_MEM8(0x00D3)
#define CRC_CHECKSUM0  _SFR_MEM8(0x00D4)
#define CRC_CHECKSUM1  _SFR_MEM8(0x00D5)
#define CRC_CHECKSUM2  _SFR_MEM8(0x00D6)
#define CRC_CHECKSUM3  _SFR_MEM8(0x00D7)

/* EDMA - Enhanced DMA Controller */
#define EDMA_CTRL  _SFR_MEM8(0x0100)
#define EDMA_INTFLAGS  _SFR_MEM8(0x0103)
#define EDMA_STATUS  _SFR_MEM8(0x0104)
#define EDMA_TEMP  _SFR_MEM8(0x0106)
#define EDMA_CH0_CTRLA  _SFR_MEM8(0x0110)
#define EDMA_CH0_CTRLB  _SFR_MEM8(0x0111)
#define EDMA_CH0_ADDRCTRL  _SFR_MEM8(0x0112)
#define EDMA_CH0_DESTADDRCTRL  _SFR_MEM8(0x0113)
#define EDMA_CH0_TRIGSRC  _SFR_MEM8(0x0114)
#define EDMA_CH0_TRFCNT  _SFR_MEM16(0x0116)
#define EDMA_CH0_ADDR  _SFR_MEM16(0x0118)
#define EDMA_CH0_DESTADDR  _SFR_MEM16(0x011C)
#define EDMA_CH1_CTRLA  _SFR_MEM8(0x0120)
#define EDMA_CH1_CTRLB  _SFR_MEM8(0x0121)
#define EDMA_CH1_ADDRCTRL  _SFR_MEM8(0x0122)
#define EDMA_CH1_DESTADDRCTRL  _SFR_MEM8(0x0123)
#define EDMA_CH1_TRIGSRC  _SFR_MEM8(0x0124)
#define EDMA_CH1_TRFCNT  _SFR_MEM16(0x0126)
#define EDMA_CH1_ADDR  _SFR_MEM16(0x0128)
#define EDMA_CH1_DESTADDR  _SFR_MEM16(0x012C)
#define EDMA_CH2_CTRLA  _SFR_MEM8(0x0130)
#define EDMA_CH2_CTRLB  _SFR_MEM8(0x0131)
#define EDMA_CH2_ADDRCTRL  _SFR_MEM8(0x0132)
#define EDMA_CH2_DESTADDRCTRL  _SFR_MEM8(0x0133)
#define EDMA_CH2_TRIGSRC  _SFR_MEM8(0x0134)
#define EDMA_CH2_TRFCNT  _SFR_MEM16(0x0136)
#define EDMA_CH2_ADDR  _SFR_MEM16(0x0138)
#define EDMA_CH2_DESTADDR  _SFR_MEM16(0x013C)
#define EDMA_CH3_CTRLA  _SFR_MEM8(0x0140)
#define EDMA_CH3_CTRLB  _SFR_MEM8(0x0141)
#define EDMA_CH3_ADDRCTRL  _SFR_MEM8(0x0142)
#define EDMA_CH3_DESTADDRCTRL  _SFR_MEM8(0x0143)
#define EDMA_CH3_TRIGSRC  _SFR_MEM8(0x0144)
#define EDMA_CH3_TRFCNT  _SFR_MEM16(0x0146)
#define EDMA_CH3_ADDR  _SFR_MEM16(0x0148)
#define EDMA_CH3_DESTADDR  _SFR_MEM16(0x014C)

/* EVSYS - Event System */
#define EVSYS_CH0MUX  _SFR_MEM8(0x0180)
#define EVSYS_CH1MUX  _SFR_MEM8(0x0181)
#define EVSYS_CH2MUX  _SFR_MEM8(0x0182)
#define EVSYS_CH3MUX  _SFR_MEM8(0x0183)
#define EVSYS_CH4MUX  _SFR_MEM8(0x0184)
#define EVSYS_CH5MUX  _SFR_MEM8(0x0185)
#define EVSYS_CH6MUX  _SFR_MEM8(0x0186)
#define EVSYS_CH7MUX  _SFR_MEM8(0x0187)
#define EVSYS_CH0CTRL  _SFR_MEM8(0x0188)
#define EVSYS_CH1CTRL  _SFR_MEM8(0x0189)
#define EVSYS_CH2CTRL  _SFR_MEM8(0x018A)
#define EVSYS_CH3CTRL  _SFR_MEM8(0x018B)
#define EVSYS_CH4CTRL  _SFR_MEM8(0x018C)
#define EVSYS_CH5CTRL  _SFR_MEM8(0x018D)
#define EVSYS_CH6CTRL  _SFR_MEM8(0x018E)
#define EVSYS_CH7CTRL  _SFR_MEM8(0x018F)
#define EVSYS_STROBE  _SFR_MEM8(0x0190)
#define EVSYS_DATA  _SFR_MEM8(0x0191)
#define EVSYS_DFCTRL  _SFR_MEM8(0x0192)

/* NVM - Non-volatile Memory Controller */
#define NVM_ADDR0  _SFR_MEM8(0x01C0)
#define NVM_ADDR1  _SFR_MEM8(0x01C1)
#define NVM_ADDR2  _SFR_MEM8(0x01C2)
#define NVM_DATA0  _SFR_MEM8(0x01C4)
#define NVM_DATA1  _SFR_MEM8(0x01C5)
#define NVM_DATA2  _SFR_MEM8(0x01C6)
#define NVM_CMD  _SFR_MEM8(0x01CA)
#define NVM_CTRLA  _SFR_MEM8(0x01CB)
#define NVM_CTRLB  _SFR_MEM8(0x01CC)
#define NVM_INTCTRL  _SFR_MEM8(0x01CD)
#define NVM_STATUS  _SFR_MEM8(0x01CF)
#define NVM_LOCKBITS  _SFR_MEM8(0x01D0)

/* ADC - Analog-to-Digital Converter */
#define ADCA_CTRLA  _SFR_MEM8(0x0200)
#define ADCA_CTRLB  _SFR_MEM8(0x0201)
#define ADCA_REFCTRL  _SFR_MEM8(0x0202)
#define ADCA_EVCTRL  _SFR_MEM8(0x0203)
#define ADCA_PRESCALER  _SFR_MEM8(0x0204)
#define ADCA_INTFLAGS  _SFR_MEM8(0x0206)
#define ADCA_TEMP  _SFR_MEM8(0x0207)
#define ADCA_SAMPCTRL  _SFR_MEM8(0x0208)
#define ADCA_CAL  _SFR_MEM16(0x020C)
#define ADCA_CH0RES  _SFR_MEM16(0x0210)
#define ADCA_CMP  _SFR_MEM16(0x0218)
#define ADCA_CH0_CTRL  _SFR_MEM8(0x0220)
#define ADCA_CH0_MUXCTRL  _SFR_MEM8(0x0221)
#define ADCA_CH0_INTCTRL  _SFR_MEM8(0x0222)
#define ADCA_CH0_INTFLAGS  _SFR_MEM8(0x0223)
#define ADCA_CH0_RES  _SFR_MEM16(0x0224)
#define ADCA_CH0_SCAN  _SFR_MEM8(0x0226)
#define ADCA_CH0_CORRCTRL  _SFR_MEM8(0x0227)
#define ADCA_CH0_OFFSETCORR0  _SFR_MEM8(0x0228)
#define ADCA_CH0_OFFSETCORR1  _SFR_MEM8(0x0229)
#define ADCA_CH0_GAINCORR0  _SFR_MEM8(0x022A)
#define ADCA_CH0_GAINCORR1  _SFR_MEM8(0x022B)
#define ADCA_CH0_AVGCTRL  _SFR_MEM8(0x022C)

/* DAC - Digital-to-Analog Converter */
#define DACA_CTRLA  _SFR_MEM8(0x0300)
#define DACA_CTRLB  _SFR_MEM8(0x0301)
#define DACA_CTRLC  _SFR_MEM8(0x0302)
#define DACA_EVCTRL  _SFR_MEM8(0x0303)
#define DACA_STATUS  _SFR_MEM8(0x0305)
#define DACA_CH0GAINCAL  _SFR_MEM8(0x0308)
#define DACA_CH0OFFSETCAL  _SFR_MEM8(0x0309)
#define DACA_CH1GAINCAL  _SFR_MEM8(0x030A)
#define DACA_CH1OFFSETCAL  _SFR_MEM8(0x030B)
#define DACA_CH0DATA  _SFR_MEM16(0x0318)
#define DACA_CH1DATA  _SFR_MEM16(0x031A)

/* AC - Analog Comparator */
#define ACA_AC0CTRL  _SFR_MEM8(0x0380)
#define ACA_AC1CTRL  _SFR_MEM8(0x0381)
#define ACA_AC0MUXCTRL  _SFR_MEM8(0x0382)
#define ACA_AC1MUXCTRL  _SFR_MEM8(0x0383)
#define ACA_CTRLA  _SFR_MEM8(0x0384)
#define ACA_CTRLB  _SFR_MEM8(0x0385)
#define ACA_WINCTRL  _SFR_MEM8(0x0386)
#define ACA_STATUS  _SFR_MEM8(0x0387)
#define ACA_CURRCTRL  _SFR_MEM8(0x0388)
#define ACA_CURRCALIB  _SFR_MEM8(0x0389)

/* RTC - Real-Time Counter */
#define RTC_CTRL  _SFR_MEM8(0x0400)
#define RTC_STATUS  _SFR_MEM8(0x0401)
#define RTC_INTCTRL  _SFR_MEM8(0x0402)
#define RTC_INTFLAGS  _SFR_MEM8(0x0403)
#define RTC_TEMP  _SFR_MEM8(0x0404)
#define RTC_CALIB  _SFR_MEM8(0x0406)
#define RTC_CNT  _SFR_MEM16(0x0408)
#define RTC_PER  _SFR_MEM16(0x040A)
#define RTC_COMP  _SFR_MEM16(0x040C)

/* XCL - XMEGA Custom Logic */
#define XCL_CTRLA  _SFR_MEM8(0x0460)
#define XCL_CTRLB  _SFR_MEM8(0x0461)
#define XCL_CTRLC  _SFR_MEM8(0x0462)
#define XCL_CTRLD  _SFR_MEM8(0x0463)
#define XCL_CTRLE  _SFR_MEM8(0x0464)
#define XCL_CTRLF  _SFR_MEM8(0x0465)
#define XCL_CTRLG  _SFR_MEM8(0x0466)
#define XCL_INTCTRL  _SFR_MEM8(0x0467)
#define XCL_INTFLAGS  _SFR_MEM8(0x0468)
#define XCL_PLC  _SFR_MEM8(0x0469)
#define XCL_CNTL  _SFR_MEM8(0x046A)
#define XCL_CNTH  _SFR_MEM8(0x046B)
#define XCL_CMPL  _SFR_MEM8(0x046C)
#define XCL_CMPH  _SFR_MEM8(0x046D)
#define XCL_PERCAPTL  _SFR_MEM8(0x046E)
#define XCL_PERCAPTH  _SFR_MEM8(0x046F)

/* TWI - Two-Wire Interface */
#define TWIC_CTRL  _SFR_MEM8(0x0480)
#define TWIC_MASTER_CTRLA  _SFR_MEM8(0x0481)
#define TWIC_MASTER_CTRLB  _SFR_MEM8(0x0482)
#define TWIC_MASTER_CTRLC  _SFR_MEM8(0x0483)
#define TWIC_MASTER_STATUS  _SFR_MEM8(0x0484)
#define TWIC_MASTER_BAUD  _SFR_MEM8(0x0485)
#define TWIC_MASTER_ADDR  _SFR_MEM8(0x0486)
#define TWIC_MASTER_DATA  _SFR_MEM8(0x0487)
#define TWIC_SLAVE_CTRLA  _SFR_MEM8(0x0488)
#define TWIC_SLAVE_CTRLB  _SFR_MEM8(0x0489)
#define TWIC_SLAVE_STATUS  _SFR_MEM8(0x048A)
#define TWIC_SLAVE_ADDR  _SFR_MEM8(0x048B)
#define TWIC_SLAVE_DATA  _SFR_MEM8(0x048C)
#define TWIC_SLAVE_ADDRMASK  _SFR_MEM8(0x048D)
#define TWIC_TIMEOUT_TOS  _SFR_MEM8(0x048E)
#define TWIC_TIMEOUT_TOCONF  _SFR_MEM8(0x048F)

/* PORT - I/O Ports */
#define PORTA_DIR  _SFR_MEM8(0x0600)
#define PORTA_DIRSET  _SFR_MEM8(0x0601)
#define PORTA_DIRCLR  _SFR_MEM8(0x0602)
#define PORTA_DIRTGL  _SFR_MEM8(0x0603)
#define PORTA_OUT  _SFR_MEM8(0x0604)
#define PORTA_OUTSET  _SFR_MEM8(0x0605)
#define PORTA_OUTCLR  _SFR_MEM8(0x0606)
#define PORTA_OUTTGL  _SFR_MEM8(0x0607)
#define PORTA_IN  _SFR_MEM8(0x0608)
#define PORTA_INTCTRL  _SFR_MEM8(0x0609)
#define PORTA_INTMASK  _SFR_MEM8(0x060A)
#define PORTA_INTFLAGS  _SFR_MEM8(0x060C)
#define PORTA_REMAP  _SFR_MEM8(0x060E)
#define PORTA_PIN0CTRL  _SFR_MEM8(0x0610)
#define PORTA_PIN1CTRL  _SFR_MEM8(0x0611)
#define PORTA_PIN2CTRL  _SFR_MEM8(0x0612)
#define PORTA_PIN3CTRL  _SFR_MEM8(0x0613)
#define PORTA_PIN4CTRL  _SFR_MEM8(0x0614)
#define PORTA_PIN5CTRL  _SFR_MEM8(0x0615)
#define PORTA_PIN6CTRL  _SFR_MEM8(0x0616)
#define PORTA_PIN7CTRL  _SFR_MEM8(0x0617)

/* PORT - I/O Ports */
#define PORTC_DIR  _SFR_MEM8(0x0640)
#define PORTC_DIRSET  _SFR_MEM8(0x0641)
#define PORTC_DIRCLR  _SFR_MEM8(0x0642)
#define PORTC_DIRTGL  _SFR_MEM8(0x0643)
#define PORTC_OUT  _SFR_MEM8(0x0644)
#define PORTC_OUTSET  _SFR_MEM8(0x0645)
#define PORTC_OUTCLR  _SFR_MEM8(0x0646)
#define PORTC_OUTTGL  _SFR_MEM8(0x0647)
#define PORTC_IN  _SFR_MEM8(0x0648)
#define PORTC_INTCTRL  _SFR_MEM8(0x0649)
#define PORTC_INTMASK  _SFR_MEM8(0x064A)
#define PORTC_INTFLAGS  _SFR_MEM8(0x064C)
#define PORTC_REMAP  _SFR_MEM8(0x064E)
#define PORTC_PIN0CTRL  _SFR_MEM8(0x0650)
#define PORTC_PIN1CTRL  _SFR_MEM8(0x0651)
#define PORTC_PIN2CTRL  _SFR_MEM8(0x0652)
#define PORTC_PIN3CTRL  _SFR_MEM8(0x0653)
#define PORTC_PIN4CTRL  _SFR_MEM8(0x0654)
#define PORTC_PIN5CTRL  _SFR_MEM8(0x0655)
#define PORTC_PIN6CTRL  _SFR_MEM8(0x0656)
#define PORTC_PIN7CTRL  _SFR_MEM8(0x0657)

/* PORT - I/O Ports */
#define PORTD_DIR  _SFR_MEM8(0x0660)
#define PORTD_DIRSET  _SFR_MEM8(0x0661)
#define PORTD_DIRCLR  _SFR_MEM8(0x0662)
#define PORTD_DIRTGL  _SFR_MEM8(0x0663)
#define PORTD_OUT  _SFR_MEM8(0x0664)
#define PORTD_OUTSET  _SFR_MEM8(0x0665)
#define PORTD_OUTCLR  _SFR_MEM8(0x0666)
#define PORTD_OUTTGL  _SFR_MEM8(0x0667)
#define PORTD_IN  _SFR_MEM8(0x0668)
#define PORTD_INTCTRL  _SFR_MEM8(0x0669)
#define PORTD_INTMASK  _SFR_MEM8(0x066A)
#define PORTD_INTFLAGS  _SFR_MEM8(0x066C)
#define PORTD_REMAP  _SFR_MEM8(0x066E)
#define PORTD_PIN0CTRL  _SFR_MEM8(0x0670)
#define PORTD_PIN1CTRL  _SFR_MEM8(0x0671)
#define PORTD_PIN2CTRL  _SFR_MEM8(0x0672)
#define PORTD_PIN3CTRL  _SFR_MEM8(0x0673)
#define PORTD_PIN4CTRL  _SFR_MEM8(0x0674)
#define PORTD_PIN5CTRL  _SFR_MEM8(0x0675)
#define PORTD_PIN6CTRL  _SFR_MEM8(0x0676)
#define PORTD_PIN7CTRL  _SFR_MEM8(0x0677)

/* PORT - I/O Ports */
#define PORTR_DIR  _SFR_MEM8(0x07E0)
#define PORTR_DIRSET  _SFR_MEM8(0x07E1)
#define PORTR_DIRCLR  _SFR_MEM8(0x07E2)
#define PORTR_DIRTGL  _SFR_MEM8(0x07E3)
#define PORTR_OUT  _SFR_MEM8(0x07E4)
#define PORTR_OUTSET  _SFR_MEM8(0x07E5)
#define PORTR_OUTCLR  _SFR_MEM8(0x07E6)
#define PORTR_OUTTGL  _SFR_MEM8(0x07E7)
#define PORTR_IN  _SFR_MEM8(0x07E8)
#define PORTR_INTCTRL  _SFR_MEM8(0x07E9)
#define PORTR_INTMASK  _SFR_MEM8(0x07EA)
#define PORTR_INTFLAGS  _SFR_MEM8(0x07EC)
#define PORTR_REMAP  _SFR_MEM8(0x07EE)
#define PORTR_PIN0CTRL  _SFR_MEM8(0x07F0)
#define PORTR_PIN1CTRL  _SFR_MEM8(0x07F1)
#define PORTR_PIN2CTRL  _SFR_MEM8(0x07F2)
#define PORTR_PIN3CTRL  _SFR_MEM8(0x07F3)
#define PORTR_PIN4CTRL  _SFR_MEM8(0x07F4)
#define PORTR_PIN5CTRL  _SFR_MEM8(0x07F5)
#define PORTR_PIN6CTRL  _SFR_MEM8(0x07F6)
#define PORTR_PIN7CTRL  _SFR_MEM8(0x07F7)

/* TC4 - 16-bit Timer/Counter 4 */
#define TCC4_CTRLA  _SFR_MEM8(0x0800)
#define TCC4_CTRLB  _SFR_MEM8(0x0801)
#define TCC4_CTRLC  _SFR_MEM8(0x0802)
#define TCC4_CTRLD  _SFR_MEM8(0x0803)
#define TCC4_CTRLE  _SFR_MEM8(0x0804)
#define TCC4_CTRLF  _SFR_MEM8(0x0805)
#define TCC4_INTCTRLA  _SFR_MEM8(0x0806)
#define TCC4_INTCTRLB  _SFR_MEM8(0x0807)
#define TCC4_CTRLGCLR  _SFR_MEM8(0x0808)
#define TCC4_CTRLGSET  _SFR_MEM8(0x0809)
#define TCC4_CTRLHCLR  _SFR_MEM8(0x080A)
#define TCC4_CTRLHSET  _SFR_MEM8(0x080B)
#define TCC4_INTFLAGS  _SFR_MEM8(0x080C)
#define TCC4_TEMP  _SFR_MEM8(0x080F)
#define TCC4_CNT  _SFR_MEM16(0x0820)
#define TCC4_PER  _SFR_MEM16(0x0826)
#define TCC4_CCA  _SFR_MEM16(0x0828)
#define TCC4_CCB  _SFR_MEM16(0x082A)
#define TCC4_CCC  _SFR_MEM16(0x082C)
#define TCC4_CCD  _SFR_MEM16(0x082E)
#define TCC4_PERBUF  _SFR_MEM16(0x0836)
#define TCC4_CCABUF  _SFR_MEM16(0x0838)
#define TCC4_CCBBUF  _SFR_MEM16(0x083A)
#define TCC4_CCCBUF  _SFR_MEM16(0x083C)
#define TCC4_CCDBUF  _SFR_MEM16(0x083E)

/* TC5 - 16-bit Timer/Counter 5 */
#define TCC5_CTRLA  _SFR_MEM8(0x0840)
#define TCC5_CTRLB  _SFR_MEM8(0x0841)
#define TCC5_CTRLC  _SFR_MEM8(0x0842)
#define TCC5_CTRLD  _SFR_MEM8(0x0843)
#define TCC5_CTRLE  _SFR_MEM8(0x0844)
#define TCC5_CTRLF  _SFR_MEM8(0x0845)
#define TCC5_INTCTRLA  _SFR_MEM8(0x0846)
#define TCC5_INTCTRLB  _SFR_MEM8(0x0847)
#define TCC5_CTRLGCLR  _SFR_MEM8(0x0848)
#define TCC5_CTRLGSET  _SFR_MEM8(0x0849)
#define TCC5_CTRLHCLR  _SFR_MEM8(0x084A)
#define TCC5_CTRLHSET  _SFR_MEM8(0x084B)
#define TCC5_INTFLAGS  _SFR_MEM8(0x084C)
#define TCC5_TEMP  _SFR_MEM8(0x084F)
#define TCC5_CNT  _SFR_MEM16(0x0860)
#define TCC5_PER  _SFR_MEM16(0x0866)
#define TCC5_CCA  _SFR_MEM16(0x0868)
#define TCC5_CCB  _SFR_MEM16(0x086A)
#define TCC5_PERBUF  _SFR_MEM16(0x0876)
#define TCC5_CCABUF  _SFR_MEM16(0x0878)
#define TCC5_CCBBUF  _SFR_MEM16(0x087A)

/* FAULT - Fault Extension */
#define FAULTC4_CTRLA  _SFR_MEM8(0x0880)
#define FAULTC4_CTRLB  _SFR_MEM8(0x0881)
#define FAULTC4_CTRLC  _SFR_MEM8(0x0882)
#define FAULTC4_CTRLD  _SFR_MEM8(0x0883)
#define FAULTC4_CTRLE  _SFR_MEM8(0x0884)
#define FAULTC4_STATUS  _SFR_MEM8(0x0885)
#define FAULTC4_CTRLGCLR  _SFR_MEM8(0x0886)
#define FAULTC4_CTRLGSET  _SFR_MEM8(0x0887)

/* FAULT - Fault Extension */
#define FAULTC5_CTRLA  _SFR_MEM8(0x0890)
#define FAULTC5_CTRLB  _SFR_MEM8(0x0891)
#define FAULTC5_CTRLC  _SFR_MEM8(0x0892)
#define FAULTC5_CTRLD  _SFR_MEM8(0x0893)
#define FAULTC5_CTRLE  _SFR_MEM8(0x0894)
#define FAULTC5_STATUS  _SFR_MEM8(0x0895)
#define FAULTC5_CTRLGCLR  _SFR_MEM8(0x0896)
#define FAULTC5_CTRLGSET  _SFR_MEM8(0x0897)

/* WEX - Waveform Extension */
#define WEXC_CTRL  _SFR_MEM8(0x08A0)
#define WEXC_DTBOTH  _SFR_MEM8(0x08A1)
#define WEXC_DTLS  _SFR_MEM8(0x08A2)
#define WEXC_DTHS  _SFR_MEM8(0x08A3)
#define WEXC_STATUSCLR  _SFR_MEM8(0x08A4)
#define WEXC_STATUSSET  _SFR_MEM8(0x08A5)
#define WEXC_SWAP  _SFR_MEM8(0x08A6)
#define WEXC_PGO  _SFR_MEM8(0x08A7)
#define WEXC_PGV  _SFR_MEM8(0x08A8)
#define WEXC_SWAPBUF  _SFR_MEM8(0x08AA)
#define WEXC_PGOBUF  _SFR_MEM8(0x08AB)
#define WEXC_PGVBUF  _SFR_MEM8(0x08AC)
#define WEXC_OUTOVDIS  _SFR_MEM8(0x08AF)

/* HIRES - High-Resolution Extension */
#define HIRESC_CTRLA  _SFR_MEM8(0x08B0)

/* USART - Universal Synchronous/Asynchronous Receiver/Transmitter */
#define USARTC0_DATA  _SFR_MEM8(0x08C0)
#define USARTC0_STATUS  _SFR_MEM8(0x08C1)
#define USARTC0_CTRLA  _SFR_MEM8(0x08C2)
#define USARTC0_CTRLB  _SFR_MEM8(0x08C3)
#define USARTC0_CTRLC  _SFR_MEM8(0x08C4)
#define USARTC0_CTRLD  _SFR_MEM8(0x08C5)
#define USARTC0_BAUDCTRLA  _SFR_MEM8(0x08C6)
#define USARTC0_BAUDCTRLB  _SFR_MEM8(0x08C7)

/* SPI - Serial Peripheral Interface with Buffer Modes */
#define SPIC_CTRL  _SFR_MEM8(0x08E0)
#define SPIC_INTCTRL  _SFR_MEM8(0x08E1)
#define SPIC_STATUS  _SFR_MEM8(0x08E2)
#define SPIC_DATA  _SFR_MEM8(0x08E3)
#define SPIC_CTRLB  _SFR_MEM8(0x08E4)

/* IRCOM - IR Communication Module */
#define IRCOM_CTRL  _SFR_MEM8(0x08F8)
#define IRCOM_TXPLCTRL  _SFR_MEM8(0x08F9)
#define IRCOM_RXPLCTRL  _SFR_MEM8(0x08FA)

/* TC5 - 16-bit Timer/Counter 5 */
#define TCD5_CTRLA  _SFR_MEM8(0x0940)
#define TCD5_CTRLB  _SFR_MEM8(0x0941)
#define TCD5_CTRLC  _SFR_MEM8(0x0942)
#define TCD5_CTRLD  _SFR_MEM8(0x0943)
#define TCD5_CTRLE  _SFR_MEM8(0x0944)
#define TCD5_CTRLF  _SFR_MEM8(0x0945)
#define TCD5_INTCTRLA  _SFR_MEM8(0x0946)
#define TCD5_INTCTRLB  _SFR_MEM8(0x0947)
#define TCD5_CTRLGCLR  _SFR_MEM8(0x0948)
#define TCD5_CTRLGSET  _SFR_MEM8(0x0949)
#define TCD5_CTRLHCLR  _SFR_MEM8(0x094A)
#define TCD5_CTRLHSET  _SFR_MEM8(0x094B)
#define TCD5_INTFLAGS  _SFR_MEM8(0x094C)
#define TCD5_TEMP  _SFR_MEM8(0x094F)
#define TCD5_CNT  _SFR_MEM16(0x0960)
#define TCD5_PER  _SFR_MEM16(0x0966)
#define TCD5_CCA  _SFR_MEM16(0x0968)
#define TCD5_CCB  _SFR_MEM16(0x096A)
#define TCD5_PERBUF  _SFR_MEM16(0x0976)
#define TCD5_CCABUF  _SFR_MEM16(0x0978)
#define TCD5_CCBBUF  _SFR_MEM16(0x097A)

/* USART - Universal Synchronous/Asynchronous Receiver/Transmitter */
#define USARTD0_DATA  _SFR_MEM8(0x09C0)
#define USARTD0_STATUS  _SFR_MEM8(0x09C1)
#define USARTD0_CTRLA  _SFR_MEM8(0x09C2)
#define USARTD0_CTRLB  _SFR_MEM8(0x09C3)
#define USARTD0_CTRLC  _SFR_MEM8(0x09C4)
#define USARTD0_CTRLD  _SFR_MEM8(0x09C5)
#define USARTD0_BAUDCTRLA  _SFR_MEM8(0x09C6)
#define USARTD0_BAUDCTRLB  _SFR_MEM8(0x09C7)



/*================== Bitfield Definitions ================== */

/* VPORT - Virtual Ports */
/* VPORT.INTFLAGS  bit masks and bit positions */
#define VPORT_INT7IF_bm  0x80  /* Interrupt Pin 7 Flag bit mask. */
#define VPORT_INT7IF_bp  7  /* Interrupt Pin 7 Flag bit position. */

#define VPORT_INT6IF_bm  0x40  /* Interrupt Pin 6 Flag bit mask. */
#define VPORT_INT6IF_bp  6  /* Interrupt Pin 6 Flag bit position. */

#define VPORT_INT5IF_bm  0x20  /* Interrupt Pin 5 Flag bit mask. */
#define VPORT_INT5IF_bp  5  /* Interrupt Pin 5 Flag bit position. */

#define VPORT_INT4IF_bm  0x10  /* Interrupt Pin 4 Flag bit mask. */
#define VPORT_INT4IF_bp  4  /* Interrupt Pin 4 Flag bit position. */

#define VPORT_INT3IF_bm  0x08  /* Interrupt Pin 3 Flag bit mask. */
#define VPORT_INT3IF_bp  3  /* Interrupt Pin 3 Flag bit position. */

#define VPORT_INT2IF_bm  0x04  /* Interrupt Pin 2 Flag bit mask. */
#define VPORT_INT2IF_bp  2  /* Interrupt Pin 2 Flag bit position. */

#define VPORT_INT1IF_bm  0x02  /* Interrupt Pin 1 Flag bit mask. */
#define VPORT_INT1IF_bp  1  /* Interrupt Pin 1 Flag bit position. */

#define VPORT_INT0IF_bm  0x01  /* Interrupt Pin 0 Flag bit mask. */
#define VPORT_INT0IF_bp  0  /* Interrupt Pin 0 Flag bit position. */

/* XOCD - On-Chip Debug System */
/* OCD.OCDR0  bit masks and bit positions */
#define OCD_OCDRD_gm  0xFF  /* OCDR Dirty group mask. */
#define OCD_OCDRD_gp  0  /* OCDR Dirty group position. */
#define OCD_OCDRD0_bm  (1<<0)  /* OCDR Dirty bit 0 mask. */
#define OCD_OCDRD0_bp  0  /* OCDR Dirty bit 0 position. */
#define OCD_OCDRD1_bm  (1<<1)  /* OCDR Dirty bit 1 mask. */
#define OCD_OCDRD1_bp  1  /* OCDR Dirty bit 1 position. */
#define OCD_OCDRD2_bm  (1<<2)  /* OCDR Dirty bit 2 mask. */
#define OCD_OCDRD2_bp  2  /* OCDR Dirty bit 2 position. */
#define OCD_OCDRD3_bm  (1<<3)  /* OCDR Dirty bit 3 mask. */
#define OCD_OCDRD3_bp  3  /* OCDR Dirty bit 3 position. */
#define OCD_OCDRD4_bm  (1<<4)  /* OCDR Dirty bit 4 mask. */
#define OCD_OCDRD4_bp  4  /* OCDR Dirty bit 4 position. */
#define OCD_OCDRD5_bm  (1<<5)  /* OCDR Dirty bit 5 mask. */
#define OCD_OCDRD5_bp  5  /* OCDR Dirty bit 5 position. */
#define OCD_OCDRD6_bm  (1<<6)  /* OCDR Dirty bit 6 mask. */
#define OCD_OCDRD6_bp  6  /* OCDR Dirty bit 6 position. */
#define OCD_OCDRD7_bm  (1<<7)  /* OCDR Dirty bit 7 mask. */
#define OCD_OCDRD7_bp  7  /* OCDR Dirty bit 7 position. */

/* OCD.OCDR1  bit masks and bit positions */
/* OCD_OCDRD  Predefined. */
/* OCD_OCDRD  Predefined. */

/* CPU - CPU */
/* CPU.CCP  bit masks and bit positions */
#define CPU_CCP_gm  0xFF  /* CCP signature group mask. */
#define CPU_CCP_gp  0  /* CCP signature group position. */
#define CPU_CCP0_bm  (1<<0)  /* CCP signature bit 0 mask. */
#define CPU_CCP0_bp  0  /* CCP signature bit 0 position. */
#define CPU_CCP1_bm  (1<<1)  /* CCP signature bit 1 mask. */
#define CPU_CCP1_bp  1  /* CCP signature bit 1 position. */
#define CPU_CCP2_bm  (1<<2)  /* CCP signature bit 2 mask. */
#define CPU_CCP2_bp  2  /* CCP signature bit 2 position. */
#define CPU_CCP3_bm  (1<<3)  /* CCP signature bit 3 mask. */
#define CPU_CCP3_bp  3  /* CCP signature bit 3 position. */
#define CPU_CCP4_bm  (1<<4)  /* CCP signature bit 4 mask. */
#define CPU_CCP4_bp  4  /* CCP signature bit 4 position. */
#define CPU_CCP5_bm  (1<<5)  /* CCP signature bit 5 mask. */
#define CPU_CCP5_bp  5  /* CCP signature bit 5 position. */
#define CPU_CCP6_bm  (1<<6)  /* CCP signature bit 6 mask. */
#define CPU_CCP6_bp  6  /* CCP signature bit 6 position. */
#define CPU_CCP7_bm  (1<<7)  /* CCP signature bit 7 mask. */
#define CPU_CCP7_bp  7  /* CCP signature bit 7 position. */

/* CPU.SREG  bit masks and bit positions */
#define CPU_I_bm  0x80  /* Global Interrupt Enable Flag bit mask. */
#define CPU_I_bp  7  /* Global Interrupt Enable Flag bit position. */

#define CPU_T_bm  0x40  /* Transfer Bit bit mask. */
#define CPU_T_bp  6  /* Transfer Bit bit position. */

#define CPU_H_bm  0x20  /* Half Carry Flag bit mask. */
#define CPU_H_bp  5  /* Half Carry Flag bit position. */

#define CPU_S_bm  0x10  /* N Exclusive Or V Flag bit mask. */
#define CPU_S_bp  4  /* N Exclusive Or V Flag bit position. */

#define CPU_V_bm  0x08  /* Two's Complement Overflow Flag bit mask. */
#define CPU_V_bp  3  /* Two's Complement Overflow Flag bit position. */

#define CPU_N_bm  0x04  /* Negative Flag bit mask. */
#define CPU_N_bp  2  /* Negative Flag bit position. */

#define CPU_Z_bm  0x02  /* Zero Flag bit mask. */
#define CPU_Z_bp  1  /* Zero Flag bit position. */

#define CPU_C_bm  0x01  /* Carry Flag bit mask. */
#define CPU_C_bp  0  /* Carry Flag bit position. */

/* CLK - Clock System */
/* CLK.CTRL  bit masks and bit positions */
#define CLK_SCLKSEL_gm  0x07  /* System Clock Selection group mask. */
#define CLK_SCLKSEL_gp  0  /* System Clock Selection group position. */
#define CLK_SCLKSEL0_bm  (1<<0)  /* System Clock Selection bit 0 mask. */
#define CLK_SCLKSEL0_bp  0  /* System Clock Selection bit 0 position. */
#define CLK_SCLKSEL1_bm  (1<<1)  /* System Clock Selection bit 1 mask. */
#define CLK_SCLKSEL1_bp  1  /* System Clock Selection bit 1 position. */
#define CLK_SCLKSEL2_bm  (1<<2)  /* System Clock Selection bit 2 mask. */
#define CLK_SCLKSEL2_bp  2  /* System Clock Selection bit 2 position. */

/* CLK.PSCTRL  bit masks and bit positions */
#define CLK_PSADIV_gm  0x7C  /* Prescaler A Division Factor group mask. */
#define CLK_PSADIV_gp  2  /* Prescaler A Division Factor group position. */
#define CLK_PSADIV0_bm  (1<<2)  /* Prescaler A Division Factor bit 0 mask. */
#define CLK_PSADIV0_bp  2  /* Prescaler A Division Factor bit 0 position. */
#define CLK_PSADIV1_bm  (1<<3)  /* Prescaler A Division Factor bit 1 mask. */
#define CLK_PSADIV1_bp  3  /* Prescaler A Division Factor bit 1 position. */
#define CLK_PSADIV2_bm  (1<<4)  /* Prescaler A Division Factor bit 2 mask. */
#define CLK_PSADIV2_bp  4  /* Prescaler A Division Factor bit 2 position. */
#define CLK_PSADIV3_bm  (1<<5)  /* Prescaler A Division Factor bit 3 mask. */
#define CLK_PSADIV3_bp  5  /* Prescaler A Division Factor bit 3 position. */
#define CLK_PSADIV4_bm  (1<<6)  /* Prescaler A Division Factor bit 4 mask. */
#define CLK_PSADIV4_bp  6  /* Prescaler A Division Factor bit 4 position. */

#define CLK_PSBCDIV_gm  0x03  /* Prescaler B and C Division factor group mask. */
#define CLK_PSBCDIV_gp  0  /* Prescaler B and C Division factor group position. */
#define CLK_PSBCDIV0_bm  (1<<0)  /* Prescaler B and C Division factor bit 0 mask. */
#define CLK_PSBCDIV0_bp  0  /* Prescaler B and C Division factor bit 0 position. */
#define CLK_PSBCDIV1_bm  (1<<1)  /* Prescaler B and C Division factor bit 1 mask. */
#define CLK_PSBCDIV1_bp  1  /* Prescaler B and C Division factor bit 1 position. */

/* CLK.LOCK  bit masks and bit positions */
#define CLK_LOCK_bm  0x01  /* Clock System Lock bit mask. */
#define CLK_LOCK_bp  0  /* Clock System Lock bit position. */

/* CLK.RTCCTRL  bit masks and bit positions */
#define CLK_RTCSRC_gm  0x0E  /* Clock Source group mask. */
#define CLK_RTCSRC_gp  1  /* Clock Source group position. */
#define CLK_RTCSRC0_bm  (1<<1)  /* Clock Source bit 0 mask. */
#define CLK_RTCSRC0_bp  1  /* Clock Source bit 0 position. */
#define CLK_RTCSRC1_bm  (1<<2)  /* Clock Source bit 1 mask. */
#define CLK_RTCSRC1_bp  2  /* Clock Source bit 1 position. */
#define CLK_RTCSRC2_bm  (1<<3)  /* Clock Source bit 2 mask. */
#define CLK_RTCSRC2_bp  3  /* Clock Source bit 2 position. */

#define CLK_RTCEN_bm  0x01  /* Clock Source Enable bit mask. */
#define CLK_RTCEN_bp  0  /* Clock Source Enable bit position. */

/* PR.PRGEN  bit masks and bit positions */
#define PR_XCL_bm  0x80  /* XMEGA Custom Logic bit mask. */
#define PR_XCL_bp  7  /* XMEGA Custom Logic bit position. */

#define PR_RTC_bm  0x04  /* Real-time Counter bit mask. */
#define PR_RTC_bp  2  /* Real-time Counter bit position. */

#define PR_EVSYS_bm  0x02  /* Event System bit mask. */
#define PR_EVSYS_bp  1  /* Event System bit position. */

#define PR_EDMA_bm  0x01  /* Enhanced DMA-Controller bit mask. */
#define PR_EDMA_bp  0  /* Enhanced DMA-Controller bit position. */

/* PR.PRPA  bit masks and bit positions */
#define PR_DAC_bm  0x04  /* Port A DAC bit mask. */
#define PR_DAC_bp  2  /* Port A DAC bit position. */

#define PR_ADC_bm  0x02  /* Port A ADC bit mask. */
#define PR_ADC_bp  1  /* Port A ADC bit position. */

#define PR_AC_bm  0x01  /* Port A Analog Comparator bit mask. */
#define PR_AC_bp  0  /* Port A Analog Comparator bit position. */

/* PR.PRPC  bit masks and bit positions */
#define PR_TWI_bm  0x40  /* Port C Two-wire Interface bit mask. */
#define PR_TWI_bp  6  /* Port C Two-wire Interface bit position. */

#define PR_USART0_bm  0x10  /* Port C USART0 bit mask. */
#define PR_USART0_bp  4  /* Port C USART0 bit position. */

#define PR_SPI_bm  0x08  /* Port C SPI bit mask. */
#define PR_SPI_bp  3  /* Port C SPI bit position. */

#define PR_HIRES_bm  0x04  /* Port C WEX bit mask. */
#define PR_HIRES_bp  2  /* Port C WEX bit position. */

#define PR_TC5_bm  0x02  /* Port C Timer/Counter5 bit mask. */
#define PR_TC5_bp  1  /* Port C Timer/Counter5 bit position. */

#define PR_TC4_bm  0x01  /* Port C Timer/Counter4 bit mask. */
#define PR_TC4_bp  0  /* Port C Timer/Counter4 bit position. */

/* PR.PRPD  bit masks and bit positions */
/* PR_USART0  Predefined. */
/* PR_USART0  Predefined. */

/* PR_TC5  Predefined. */
/* PR_TC5  Predefined. */

/* SLEEP - Sleep Controller */
/* SLEEP.CTRL  bit masks and bit positions */
#define SLEEP_SMODE_gm  0x0E  /* Sleep Mode group mask. */
#define SLEEP_SMODE_gp  1  /* Sleep Mode group position. */
#define SLEEP_SMODE0_bm  (1<<1)  /* Sleep Mode bit 0 mask. */
#define SLEEP_SMODE0_bp  1  /* Sleep Mode bit 0 position. */
#define SLEEP_SMODE1_bm  (1<<2)  /* Sleep Mode bit 1 mask. */
#define SLEEP_SMODE1_bp  2  /* Sleep Mode bit 1 position. */
#define SLEEP_SMODE2_bm  (1<<3)  /* Sleep Mode bit 2 mask. */
#define SLEEP_SMODE2_bp  3  /* Sleep Mode bit 2 position. */

#define SLEEP_SEN_bm  0x01  /* Sleep Enable bit mask. */
#define SLEEP_SEN_bp  0  /* Sleep Enable bit position. */

/* OSC - Oscillator */
/* OSC.CTRL  bit masks and bit positions */
#define OSC_RC8MLPM_bm  0x40  /* Internal 8 MHz RC Low Power Mode Enable bit mask. */
#define OSC_RC8MLPM_bp  6  /* Internal 8 MHz RC Low Power Mode Enable bit position. */

#define OSC_RC8MEN_bm  0x20  /* Internal 8 MHz RC Oscillator Enable bit mask. */
#define OSC_RC8MEN_bp  5  /* Internal 8 MHz RC Oscillator Enable bit position. */

#define OSC_PLLEN_bm  0x10  /* PLL Enable bit mask. */
#define OSC_PLLEN_bp  4  /* PLL Enable bit position. */

#define OSC_XOSCEN_bm  0x08  /* External Oscillator Enable bit mask. */
#define OSC_XOSCEN_bp  3  /* External Oscillator Enable bit position. */

#define OSC_RC32KEN_bm  0x04  /* Internal 32.768 kHz RC Oscillator Enable bit mask. */
#define OSC_RC32KEN_bp  2  /* Internal 32.768 kHz RC Oscillator Enable bit position. */

#define OSC_RC32MEN_bm  0x02  /* Internal 32 MHz RC Oscillator Enable bit mask. */
#define OSC_RC32MEN_bp  1  /* Internal 32 MHz RC Oscillator Enable bit position. */

#define OSC_RC2MEN_bm  0x01  /* Internal 2 MHz RC Oscillator Enable bit mask. */
#define OSC_RC2MEN_bp  0  /* Internal 2 MHz RC Oscillator Enable bit position. */

/* OSC.STATUS  bit masks and bit positions */
#define OSC_RC8MRDY_bm  0x20  /* Internal 8 MHz RC Oscillator Ready bit mask. */
#define OSC_RC8MRDY_bp  5  /* Internal 8 MHz RC Oscillator Ready bit position. */

#define OSC_PLLRDY_bm  0x10  /* PLL Ready bit mask. */
#define OSC_PLLRDY_bp  4  /* PLL Ready bit position. */

#define OSC_XOSCRDY_bm  0x08  /* External Oscillator Ready bit mask. */
#define OSC_XOSCRDY_bp  3  /* External Oscillator Ready bit position. */

#define OSC_RC32KRDY_bm  0x04  /* Internal 32.768 kHz RC Oscillator Ready bit mask. */
#define OSC_RC32KRDY_bp  2  /* Internal 32.768 kHz RC Oscillator Ready bit position. */

#define OSC_RC32MRDY_bm  0x02  /* Internal 32 MHz RC Oscillator Ready bit mask. */
#define OSC_RC32MRDY_bp  1  /* Internal 32 MHz RC Oscillator Ready bit position. */

#define OSC_RC2MRDY_bm  0x01  /* Internal 2 MHz RC Oscillator Ready bit mask. */
#define OSC_RC2MRDY_bp  0  /* Internal 2 MHz RC Oscillator Ready bit position. */

/* OSC.XOSCCTRL  bit masks and bit positions */
#define OSC_FRQRANGE_gm  0xC0  /* Frequency Range group mask. */
#define OSC_FRQRANGE_gp  6  /* Frequency Range group position. */
#define OSC_FRQRANGE0_bm  (1<<6)  /* Frequency Range bit 0 mask. */
#define OSC_FRQRANGE0_bp  6  /* Frequency Range bit 0 position. */
#define OSC_FRQRANGE1_bm  (1<<7)  /* Frequency Range bit 1 mask. */
#define OSC_FRQRANGE1_bp  7  /* Frequency Range bit 1 position. */

#define OSC_X32KLPM_bm  0x20  /* 32.768 kHz XTAL OSC Low-power Mode bit mask. */
#define OSC_X32KLPM_bp  5  /* 32.768 kHz XTAL OSC Low-power Mode bit position. */

#define OSC_XOSCPWR_bm  0x10  /* 16 MHz Crystal Oscillator High Power mode bit mask. */
#define OSC_XOSCPWR_bp  4  /* 16 MHz Crystal Oscillator High Power mode bit position. */

#define OSC_XOSCSEL_gm  0x1F  /* External Oscillator Selection and Startup Time group mask. */
#define OSC_XOSCSEL_gp  0  /* External Oscillator Selection and Startup Time group position. */
#define OSC_XOSCSEL0_bm  (1<<0)  /* External Oscillator Selection and Startup Time bit 0 mask. */
#define OSC_XOSCSEL0_bp  0  /* External Oscillator Selection and Startup Time bit 0 position. */
#define OSC_XOSCSEL1_bm  (1<<1)  /* External Oscillator Selection and Startup Time bit 1 mask. */
#define OSC_XOSCSEL1_bp  1  /* External Oscillator Selection and Startup Time bit 1 position. */
#define OSC_XOSCSEL2_bm  (1<<2)  /* External Oscillator Selection and Startup Time bit 2 mask. */
#define OSC_XOSCSEL2_bp  2  /* External Oscillator Selection and Startup Time bit 2 position. */
#define OSC_XOSCSEL3_bm  (1<<3)  /* External Oscillator Selection and Startup Time bit 3 mask. */
#define OSC_XOSCSEL3_bp  3  /* External Oscillator Selection and Startup Time bit 3 position. */
#define OSC_XOSCSEL4_bm  (1<<4)  /* External Oscillator Selection and Startup Time bit 4 mask. */
#define OSC_XOSCSEL4_bp  4  /* External Oscillator Selection and Startup Time bit 4 position. */

/* OSC.XOSCFAIL  bit masks and bit positions */
#define OSC_PLLFDIF_bm  0x08  /* PLL Failure Detection Interrupt Flag bit mask. */
#define OSC_PLLFDIF_bp  3  /* PLL Failure Detection Interrupt Flag bit position. */

#define OSC_PLLFDEN_bm  0x04  /* PLL Failure Detection Enable bit mask. */
#define OSC_PLLFDEN_bp  2  /* PLL Failure Detection Enable bit position. */

#define OSC_XOSCFDIF_bm  0x02  /* XOSC Failure Detection Interrupt Flag bit mask. */
#define OSC_XOSCFDIF_bp  1  /* XOSC Failure Detection Interrupt Flag bit position. */

#define OSC_XOSCFDEN_bm  0x01  /* XOSC Failure Detection Enable bit mask. */
#define OSC_XOSCFDEN_bp  0  /* XOSC Failure Detection Enable bit position. */

/* OSC.PLLCTRL  bit masks and bit positions */
#define OSC_PLLSRC_gm  0xC0  /* Clock Source group mask. */
#define OSC_PLLSRC_gp  6  /* Clock Source group position. */
#define OSC_PLLSRC0_bm  (1<<6)  /* Clock Source bit 0 mask. */
#define OSC_PLLSRC0_bp  6  /* Clock Source bit 0 position. */
#define OSC_PLLSRC1_bm  (1<<7)  /* Clock Source bit 1 mask. */
#define OSC_PLLSRC1_bp  7  /* Clock Source bit 1 position. */

#define OSC_PLLDIV_bm  0x20  /* Divide by 2 bit mask. */
#define OSC_PLLDIV_bp  5  /* Divide by 2 bit position. */

#define OSC_PLLFAC_gm  0x1F  /* Multiplication Factor group mask. */
#define OSC_PLLFAC_gp  0  /* Multiplication Factor group position. */
#define OSC_PLLFAC0_bm  (1<<0)  /* Multiplication Factor bit 0 mask. */
#define OSC_PLLFAC0_bp  0  /* Multiplication Factor bit 0 position. */
#define OSC_PLLFAC1_bm  (1<<1)  /* Multiplication Factor bit 1 mask. */
#define OSC_PLLFAC1_bp  1  /* Multiplication Factor bit 1 position. */
#define OSC_PLLFAC2_bm  (1<<2)  /* Multiplication Factor bit 2 mask. */
#define OSC_PLLFAC2_bp  2  /* Multiplication Factor bit 2 position. */
#define OSC_PLLFAC3_bm  (1<<3)  /* Multiplication Factor bit 3 mask. */
#define OSC_PLLFAC3_bp  3  /* Multiplication Factor bit 3 position. */
#define OSC_PLLFAC4_bm  (1<<4)  /* Multiplication Factor bit 4 mask. */
#define OSC_PLLFAC4_bp  4  /* Multiplication Factor bit 4 position. */

/* OSC.DFLLCTRL  bit masks and bit positions */
#define OSC_RC32MCREF_gm  0x06  /* 32 MHz DFLL Calibration Reference group mask. */
#define OSC_RC32MCREF_gp  1  /* 32 MHz DFLL Calibration Reference group position. */
#define OSC_RC32MCREF0_bm  (1<<1)  /* 32 MHz DFLL Calibration Reference bit 0 mask. */
#define OSC_RC32MCREF0_bp  1  /* 32 MHz DFLL Calibration Reference bit 0 position. */
#define OSC_RC32MCREF1_bm  (1<<2)  /* 32 MHz DFLL Calibration Reference bit 1 mask. */
#define OSC_RC32MCREF1_bp  2  /* 32 MHz DFLL Calibration Reference bit 1 position. */

/* OSC.RC8MCAL  bit masks and bit positions */
#define OSC_RC8MCAL_gm  0xFF  /* Calibration Bits group mask. */
#define OSC_RC8MCAL_gp  0  /* Calibration Bits group position. */
#define OSC_RC8MCAL0_bm  (1<<0)  /* Calibration Bits bit 0 mask. */
#define OSC_RC8MCAL0_bp  0  /* Calibration Bits bit 0 position. */
#define OSC_RC8MCAL1_bm  (1<<1)  /* Calibration Bits bit 1 mask. */
#define OSC_RC8MCAL1_bp  1  /* Calibration Bits bit 1 position. */
#define OSC_RC8MCAL2_bm  (1<<2)  /* Calibration Bits bit 2 mask. */
#define OSC_RC8MCAL2_bp  2  /* Calibration Bits bit 2 position. */
#define OSC_RC8MCAL3_bm  (1<<3)  /* Calibration Bits bit 3 mask. */
#define OSC_RC8MCAL3_bp  3  /* Calibration Bits bit 3 position. */
#define OSC_RC8MCAL4_bm  (1<<4)  /* Calibration Bits bit 4 mask. */
#define OSC_RC8MCAL4_bp  4  /* Calibration Bits bit 4 position. */
#define OSC_RC8MCAL5_bm  (1<<5)  /* Calibration Bits bit 5 mask. */
#define OSC_RC8MCAL5_bp  5  /* Calibration Bits bit 5 position. */
#define OSC_RC8MCAL6_bm  (1<<6)  /* Calibration Bits bit 6 mask. */
#define OSC_RC8MCAL6_bp  6  /* Calibration Bits bit 6 position. */
#define OSC_RC8MCAL7_bm  (1<<7)  /* Calibration Bits bit 7 mask. */
#define OSC_RC8MCAL7_bp  7  /* Calibration Bits bit 7 position. */

/* DFLL - DFLL */
/* DFLL.CTRL  bit masks and bit positions */
#define DFLL_ENABLE_bm  0x01  /* DFLL Enable bit mask. */
#define DFLL_ENABLE_bp  0  /* DFLL Enable bit position. */

/* DFLL.CALA  bit masks and bit positions */
#define DFLL_CALL_gm  0x7F  /* DFLL Calibration Value A group mask. */
#define DFLL_CALL_gp  0  /* DFLL Calibration Value A group position. */
#define DFLL_CALL0_bm  (1<<0)  /* DFLL Calibration Value A bit 0 mask. */
#define DFLL_CALL0_bp  0  /* DFLL Calibration Value A bit 0 position. */
#define DFLL_CALL1_bm  (1<<1)  /* DFLL Calibration Value A bit 1 mask. */
#define DFLL_CALL1_bp  1  /* DFLL Calibration Value A bit 1 position. */
#define DFLL_CALL2_bm  (1<<2)  /* DFLL Calibration Value A bit 2 mask. */
#define DFLL_CALL2_bp  2  /* DFLL Calibration Value A bit 2 position. */
#define DFLL_CALL3_bm  (1<<3)  /* DFLL Calibration Value A bit 3 mask. */
#define DFLL_CALL3_bp  3  /* DFLL Calibration Value A bit 3 position. */
#define DFLL_CALL4_bm  (1<<4)  /* DFLL Calibration Value A bit 4 mask. */
#define DFLL_CALL4_bp  4  /* DFLL Calibration Value A bit 4 position. */
#define DFLL_CALL5_bm  (1<<5)  /* DFLL Calibration Value A bit 5 mask. */
#define DFLL_CALL5_bp  5  /* DFLL Calibration Value A bit 5 position. */
#define DFLL_CALL6_bm  (1<<6)  /* DFLL Calibration Value A bit 6 mask. */
#define DFLL_CALL6_bp  6  /* DFLL Calibration Value A bit 6 position. */

/* DFLL.CALB  bit masks and bit positions */
#define DFLL_CALH_gm  0x3F  /* DFLL Calibration Value B group mask. */
#define DFLL_CALH_gp  0  /* DFLL Calibration Value B group position. */
#define DFLL_CALH0_bm  (1<<0)  /* DFLL Calibration Value B bit 0 mask. */
#define DFLL_CALH0_bp  0  /* DFLL Calibration Value B bit 0 position. */
#define DFLL_CALH1_bm  (1<<1)  /* DFLL Calibration Value B bit 1 mask. */
#define DFLL_CALH1_bp  1  /* DFLL Calibration Value B bit 1 position. */
#define DFLL_CALH2_bm  (1<<2)  /* DFLL Calibration Value B bit 2 mask. */
#define DFLL_CALH2_bp  2  /* DFLL Calibration Value B bit 2 position. */
#define DFLL_CALH3_bm  (1<<3)  /* DFLL Calibration Value B bit 3 mask. */
#define DFLL_CALH3_bp  3  /* DFLL Calibration Value B bit 3 position. */
#define DFLL_CALH4_bm  (1<<4)  /* DFLL Calibration Value B bit 4 mask. */
#define DFLL_CALH4_bp  4  /* DFLL Calibration Value B bit 4 position. */
#define DFLL_CALH5_bm  (1<<5)  /* DFLL Calibration Value B bit 5 mask. */
#define DFLL_CALH5_bp  5  /* DFLL Calibration Value B bit 5 position. */

/* RST - Reset */
/* RST.STATUS  bit masks and bit positions */
#define RST_SDRF_bm  0x40  /* Spike Detection Reset Flag bit mask. */
#define RST_SDRF_bp  6  /* Spike Detection Reset Flag bit position. */

#define RST_SRF_bm  0x20  /* Software Reset Flag bit mask. */
#define RST_SRF_bp  5  /* Software Reset Flag bit position. */

#define RST_PDIRF_bm  0x10  /* Programming and Debug Interface Interface Reset Flag bit mask. */
#define RST_PDIRF_bp  4  /* Programming and Debug Interface Interface Reset Flag bit position. */

#define RST_WDRF_bm  0x08  /* Watchdog Reset Flag bit mask. */
#define RST_WDRF_bp  3  /* Watchdog Reset Flag bit position. */

#define RST_BORF_bm  0x04  /* Brown-out Reset Flag bit mask. */
#define RST_BORF_bp  2  /* Brown-out Reset Flag bit position. */

#define RST_EXTRF_bm  0x02  /* External Reset Flag bit mask. */
#define RST_EXTRF_bp  1  /* External Reset Flag bit position. */

#define RST_PORF_bm  0x01  /* Power-on Reset Flag bit mask. */
#define RST_PORF_bp  0  /* Power-on Reset Flag bit position. */

/* RST.CTRL  bit masks and bit positions */
#define RST_SWRST_bm  0x01  /* Software Reset bit mask. */
#define RST_SWRST_bp  0  /* Software Reset bit position. */

/* WDT - Watch-Dog Timer */
/* WDT.CTRL  bit masks and bit positions */
#define WDT_PER_gm  0x3C  /* Period group mask. */
#define WDT_PER_gp  2  /* Period group position. */
#define WDT_PER0_bm  (1<<2)  /* Period bit 0 mask. */
#define WDT_PER0_bp  2  /* Period bit 0 position. */
#define WDT_PER1_bm  (1<<3)  /* Period bit 1 mask. */
#define WDT_PER1_bp  3  /* Period bit 1 position. */
#define WDT_PER2_bm  (1<<4)  /* Period bit 2 mask. */
#define WDT_PER2_bp  4  /* Period bit 2 position. */
#define WDT_PER3_bm  (1<<5)  /* Period bit 3 mask. */
#define WDT_PER3_bp  5  /* Period bit 3 position. */

#define WDT_ENABLE_bm  0x02  /* Enable bit mask. */
#define WDT_ENABLE_bp  1  /* Enable bit position. */

#define WDT_CEN_bm  0x01  /* Change Enable bit mask. */
#define WDT_CEN_bp  0  /* Change Enable bit position. */

/* WDT.WINCTRL  bit masks and bit positions */
#define WDT_WPER_gm  0x3C  /* Windowed Mode Period group mask. */
#define WDT_WPER_gp  2  /* Windowed Mode Period group position. */
#define WDT_WPER0_bm  (1<<2)  /* Windowed Mode Period bit 0 mask. */
#define WDT_WPER0_bp  2  /* Windowed Mode Period bit 0 position. */
#define WDT_WPER1_bm  (1<<3)  /* Windowed Mode Period bit 1 mask. */
#define WDT_WPER1_bp  3  /* Windowed Mode Period bit 1 position. */
#define WDT_WPER2_bm  (1<<4)  /* Windowed Mode Period bit 2 mask. */
#define WDT_WPER2_bp  4  /* Windowed Mode Period bit 2 position. */
#define WDT_WPER3_bm  (1<<5)  /* Windowed Mode Period bit 3 mask. */
#define WDT_WPER3_bp  5  /* Windowed Mode Period bit 3 position. */

#define WDT_WEN_bm  0x02  /* Windowed Mode Enable bit mask. */
#define WDT_WEN_bp  1  /* Windowed Mode Enable bit position. */

#define WDT_WCEN_bm  0x01  /* Windowed Mode Change Enable bit mask. */
#define WDT_WCEN_bp  0  /* Windowed Mode Change Enable bit position. */

/* WDT.STATUS  bit masks and bit positions */
#define WDT_SYNCBUSY_bm  0x01  /* Syncronization busy bit mask. */
#define WDT_SYNCBUSY_bp  0  /* Syncronization busy bit position. */

/* MCU - MCU Control */
/* MCU.ANAINIT  bit masks and bit positions */
#define MCU_STARTUPDLYA_gm  0x03  /* Analog startup delay Port A group mask. */
#define MCU_STARTUPDLYA_gp  0  /* Analog startup delay Port A group position. */
#define MCU_STARTUPDLYA0_bm  (1<<0)  /* Analog startup delay Port A bit 0 mask. */
#define MCU_STARTUPDLYA0_bp  0  /* Analog startup delay Port A bit 0 position. */
#define MCU_STARTUPDLYA1_bm  (1<<1)  /* Analog startup delay Port A bit 1 mask. */
#define MCU_STARTUPDLYA1_bp  1  /* Analog startup delay Port A bit 1 position. */

/* MCU.EVSYSLOCK  bit masks and bit positions */
#define MCU_EVSYS1LOCK_bm  0x10  /* Event Channel 4-7 Lock bit mask. */
#define MCU_EVSYS1LOCK_bp  4  /* Event Channel 4-7 Lock bit position. */

#define MCU_EVSYS0LOCK_bm  0x01  /* Event Channel 0-3 Lock bit mask. */
#define MCU_EVSYS0LOCK_bp  0  /* Event Channel 0-3 Lock bit position. */

/* MCU.WEXLOCK  bit masks and bit positions */
#define MCU_WEXCLOCK_bm  0x01  /* WeX on T/C C4 Lock bit mask. */
#define MCU_WEXCLOCK_bp  0  /* WeX on T/C C4 Lock bit position. */

/* MCU.FAULTLOCK  bit masks and bit positions */
#define MCU_FAULTC5LOCK_bm  0x02  /* Fault on T/C C5 Lock bit mask. */
#define MCU_FAULTC5LOCK_bp  1  /* Fault on T/C C5 Lock bit position. */

#define MCU_FAULTC4LOCK_bm  0x01  /* Fault on T/C C4 Lock bit mask. */
#define MCU_FAULTC4LOCK_bp  0  /* Fault on T/C C4 Lock bit position. */

/* PMIC - Programmable Multi-level Interrupt Controller */
/* PMIC.STATUS  bit masks and bit positions */
#define PMIC_NMIEX_bm  0x80  /* Non-maskable Interrupt Executing bit mask. */
#define PMIC_NMIEX_bp  7  /* Non-maskable Interrupt Executing bit position. */

#define PMIC_HILVLEX_bm  0x04  /* High Level Interrupt Executing bit mask. */
#define PMIC_HILVLEX_bp  2  /* High Level Interrupt Executing bit position. */

#define PMIC_MEDLVLEX_bm  0x02  /* Medium Level Interrupt Executing bit mask. */
#define PMIC_MEDLVLEX_bp  1  /* Medium Level Interrupt Executing bit position. */

#define PMIC_LOLVLEX_bm  0x01  /* Low Level Interrupt Executing bit mask. */
#define PMIC_LOLVLEX_bp  0  /* Low Level Interrupt Executing bit position. */

/* PMIC.INTPRI  bit masks and bit positions */
#define PMIC_INTPRI_gm  0xFF  /* Interrupt Priority group mask. */
#define PMIC_INTPRI_gp  0  /* Interrupt Priority group position. */
#define PMIC_INTPRI0_bm  (1<<0)  /* Interrupt Priority bit 0 mask. */
#define PMIC_INTPRI0_bp  0  /* Interrupt Priority bit 0 position. */
#define PMIC_INTPRI1_bm  (1<<1)  /* Interrupt Priority bit 1 mask. */
#define PMIC_INTPRI1_bp  1  /* Interrupt Priority bit 1 position. */
#define PMIC_INTPRI2_bm  (1<<2)  /* Interrupt Priority bit 2 mask. */
#define PMIC_INTPRI2_bp  2  /* Interrupt Priority bit 2 position. */
#define PMIC_INTPRI3_bm  (1<<3)  /* Interrupt Priority bit 3 mask. */
#define PMIC_INTPRI3_bp  3  /* Interrupt Priority bit 3 position. */
#define PMIC_INTPRI4_bm  (1<<4)  /* Interrupt Priority bit 4 mask. */
#define PMIC_INTPRI4_bp  4  /* Interrupt Priority bit 4 position. */
#define PMIC_INTPRI5_bm  (1<<5)  /* Interrupt Priority bit 5 mask. */
#define PMIC_INTPRI5_bp  5  /* Interrupt Priority bit 5 position. */
#define PMIC_INTPRI6_bm  (1<<6)  /* Interrupt Priority bit 6 mask. */
#define PMIC_INTPRI6_bp  6  /* Interrupt Priority bit 6 position. */
#define PMIC_INTPRI7_bm  (1<<7)  /* Interrupt Priority bit 7 mask. */
#define PMIC_INTPRI7_bp  7  /* Interrupt Priority bit 7 position. */

/* PMIC.CTRL  bit masks and bit positions */
#define PMIC_RREN_bm  0x80  /* Round-Robin Priority Enable bit mask. */
#define PMIC_RREN_bp  7  /* Round-Robin Priority Enable bit position. */

#define PMIC_IVSEL_bm  0x40  /* Interrupt Vector Select bit mask. */
#define PMIC_IVSEL_bp  6  /* Interrupt Vector Select bit position. */

#define PMIC_HILVLEN_bm  0x04  /* High Level Enable bit mask. */
#define PMIC_HILVLEN_bp  2  /* High Level Enable bit position. */

#define PMIC_MEDLVLEN_bm  0x02  /* Medium Level Enable bit mask. */
#define PMIC_MEDLVLEN_bp  1  /* Medium Level Enable bit position. */

#define PMIC_LOLVLEN_bm  0x01  /* Low Level Enable bit mask. */
#define PMIC_LOLVLEN_bp  0  /* Low Level Enable bit position. */

/* PORTCFG - Port Configuration */
/* PORTCFG.CLKOUT  bit masks and bit positions */
#define PORTCFG_CLKEVPIN_bm  0x80  /* Clock and Event Output Pin Select bit mask. */
#define PORTCFG_CLKEVPIN_bp  7  /* Clock and Event Output Pin Select bit position. */

#define PORTCFG_RTCOUT_gm  0x60  /* RTC Clock Output Enable group mask. */
#define PORTCFG_RTCOUT_gp  5  /* RTC Clock Output Enable group position. */
#define PORTCFG_RTCOUT0_bm  (1<<5)  /* RTC Clock Output Enable bit 0 mask. */
#define PORTCFG_RTCOUT0_bp  5  /* RTC Clock Output Enable bit 0 position. */
#define PORTCFG_RTCOUT1_bm  (1<<6)  /* RTC Clock Output Enable bit 1 mask. */
#define PORTCFG_RTCOUT1_bp  6  /* RTC Clock Output Enable bit 1 position. */

#define PORTCFG_CLKOUTSEL_gm  0x0C  /* Clock Output Select group mask. */
#define PORTCFG_CLKOUTSEL_gp  2  /* Clock Output Select group position. */
#define PORTCFG_CLKOUTSEL0_bm  (1<<2)  /* Clock Output Select bit 0 mask. */
#define PORTCFG_CLKOUTSEL0_bp  2  /* Clock Output Select bit 0 position. */
#define PORTCFG_CLKOUTSEL1_bm  (1<<3)  /* Clock Output Select bit 1 mask. */
#define PORTCFG_CLKOUTSEL1_bp  3  /* Clock Output Select bit 1 position. */

#define PORTCFG_CLKOUT_gm  0x03  /* Clock Output Port group mask. */
#define PORTCFG_CLKOUT_gp  0  /* Clock Output Port group position. */
#define PORTCFG_CLKOUT0_bm  (1<<0)  /* Clock Output Port bit 0 mask. */
#define PORTCFG_CLKOUT0_bp  0  /* Clock Output Port bit 0 position. */
#define PORTCFG_CLKOUT1_bm  (1<<1)  /* Clock Output Port bit 1 mask. */
#define PORTCFG_CLKOUT1_bp  1  /* Clock Output Port bit 1 position. */

/* PORTCFG.ACEVOUT  bit masks and bit positions */
#define PORTCFG_ACOUT_gm  0xC0  /* Analog Comparator Output Port group mask. */
#define PORTCFG_ACOUT_gp  6  /* Analog Comparator Output Port group position. */
#define PORTCFG_ACOUT0_bm  (1<<6)  /* Analog Comparator Output Port bit 0 mask. */
#define PORTCFG_ACOUT0_bp  6  /* Analog Comparator Output Port bit 0 position. */
#define PORTCFG_ACOUT1_bm  (1<<7)  /* Analog Comparator Output Port bit 1 mask. */
#define PORTCFG_ACOUT1_bp  7  /* Analog Comparator Output Port bit 1 position. */

#define PORTCFG_EVOUT_gm  0x30  /* Event Channel Output Port group mask. */
#define PORTCFG_EVOUT_gp  4  /* Event Channel Output Port group position. */
#define PORTCFG_EVOUT0_bm  (1<<4)  /* Event Channel Output Port bit 0 mask. */
#define PORTCFG_EVOUT0_bp  4  /* Event Channel Output Port bit 0 position. */
#define PORTCFG_EVOUT1_bm  (1<<5)  /* Event Channel Output Port bit 1 mask. */
#define PORTCFG_EVOUT1_bp  5  /* Event Channel Output Port bit 1 position. */

#define PORTCFG_EVASYEN_bm  0x08  /* Asynchronous Event Enabled bit mask. */
#define PORTCFG_EVASYEN_bp  3  /* Asynchronous Event Enabled bit position. */

#define PORTCFG_EVOUTSEL_gm  0x07  /* Event Channel Output Selection group mask. */
#define PORTCFG_EVOUTSEL_gp  0  /* Event Channel Output Selection group position. */
#define PORTCFG_EVOUTSEL0_bm  (1<<0)  /* Event Channel Output Selection bit 0 mask. */
#define PORTCFG_EVOUTSEL0_bp  0  /* Event Channel Output Selection bit 0 position. */
#define PORTCFG_EVOUTSEL1_bm  (1<<1)  /* Event Channel Output Selection bit 1 mask. */
#define PORTCFG_EVOUTSEL1_bp  1  /* Event Channel Output Selection bit 1 position. */
#define PORTCFG_EVOUTSEL2_bm  (1<<2)  /* Event Channel Output Selection bit 2 mask. */
#define PORTCFG_EVOUTSEL2_bp  2  /* Event Channel Output Selection bit 2 position. */

/* PORTCFG.SRLCTRL  bit masks and bit positions */
#define PORTCFG_SRLENRA_bm  0x01  /* Slew Rate Limit Enable on PORTA bit mask. */
#define PORTCFG_SRLENRA_bp  0  /* Slew Rate Limit Enable on PORTA bit position. */

#define PORTCFG_SRLENRC_bm  0x04  /* Slew Rate Limit Enable on PORTC bit mask. */
#define PORTCFG_SRLENRC_bp  2  /* Slew Rate Limit Enable on PORTC bit position. */

#define PORTCFG_SRLENRD_bm  0x08  /* Slew Rate Limit Enable on PORTD bit mask. */
#define PORTCFG_SRLENRD_bp  3  /* Slew Rate Limit Enable on PORTD bit position. */

#define PORTCFG_SRLENRR_bm  0x80  /* Slew Rate Limit Enable on PORTR bit mask. */
#define PORTCFG_SRLENRR_bp  7  /* Slew Rate Limit Enable on PORTR bit position. */

/* CRC - Cyclic Redundancy Checker */
/* CRC.CTRL  bit masks and bit positions */
#define CRC_RESET_gm  0xC0  /* Reset group mask. */
#define CRC_RESET_gp  6  /* Reset group position. */
#define CRC_RESET0_bm  (1<<6)  /* Reset bit 0 mask. */
#define CRC_RESET0_bp  6  /* Reset bit 0 position. */
#define CRC_RESET1_bm  (1<<7)  /* Reset bit 1 mask. */
#define CRC_RESET1_bp  7  /* Reset bit 1 position. */

#define CRC_CRC32_bm  0x20  /* CRC Mode bit mask. */
#define CRC_CRC32_bp  5  /* CRC Mode bit position. */

#define CRC_SOURCE_gm  0x0F  /* Input Source group mask. */
#define CRC_SOURCE_gp  0  /* Input Source group position. */
#define CRC_SOURCE0_bm  (1<<0)  /* Input Source bit 0 mask. */
#define CRC_SOURCE0_bp  0  /* Input Source bit 0 position. */
#define CRC_SOURCE1_bm  (1<<1)  /* Input Source bit 1 mask. */
#define CRC_SOURCE1_bp  1  /* Input Source bit 1 position. */
#define CRC_SOURCE2_bm  (1<<2)  /* Input Source bit 2 mask. */
#define CRC_SOURCE2_bp  2  /* Input Source bit 2 position. */
#define CRC_SOURCE3_bm  (1<<3)  /* Input Source bit 3 mask. */
#define CRC_SOURCE3_bp  3  /* Input Source bit 3 position. */

/* CRC.STATUS  bit masks and bit positions */
#define CRC_ZERO_bm  0x02  /* Zero detection bit mask. */
#define CRC_ZERO_bp  1  /* Zero detection bit position. */

#define CRC_BUSY_bm  0x01  /* Busy bit mask. */
#define CRC_BUSY_bp  0  /* Busy bit position. */

/* EDMA - Enhanced DMA Controller */
/* EDMA.CTRL  bit masks and bit positions */
#define EDMA_ENABLE_bm  0x80  /* Enable bit mask. */
#define EDMA_ENABLE_bp  7  /* Enable bit position. */

#define EDMA_RESET_bm  0x40  /* Software Reset bit mask. */
#define EDMA_RESET_bp  6  /* Software Reset bit position. */

#define EDMA_CHMODE_gm  0x30  /* Channel Mode group mask. */
#define EDMA_CHMODE_gp  4  /* Channel Mode group position. */
#define EDMA_CHMODE0_bm  (1<<4)  /* Channel Mode bit 0 mask. */
#define EDMA_CHMODE0_bp  4  /* Channel Mode bit 0 position. */
#define EDMA_CHMODE1_bm  (1<<5)  /* Channel Mode bit 1 mask. */
#define EDMA_CHMODE1_bp  5  /* Channel Mode bit 1 position. */

#define EDMA_DBUFMODE_gm  0x0C  /* Double Buffer Mode group mask. */
#define EDMA_DBUFMODE_gp  2  /* Double Buffer Mode group position. */
#define EDMA_DBUFMODE0_bm  (1<<2)  /* Double Buffer Mode bit 0 mask. */
#define EDMA_DBUFMODE0_bp  2  /* Double Buffer Mode bit 0 position. */
#define EDMA_DBUFMODE1_bm  (1<<3)  /* Double Buffer Mode bit 1 mask. */
#define EDMA_DBUFMODE1_bp  3  /* Double Buffer Mode bit 1 position. */

#define EDMA_PRIMODE_gm  0x03  /* Priority Mode group mask. */
#define EDMA_PRIMODE_gp  0  /* Priority Mode group position. */
#define EDMA_PRIMODE0_bm  (1<<0)  /* Priority Mode bit 0 mask. */
#define EDMA_PRIMODE0_bp  0  /* Priority Mode bit 0 position. */
#define EDMA_PRIMODE1_bm  (1<<1)  /* Priority Mode bit 1 mask. */
#define EDMA_PRIMODE1_bp  1  /* Priority Mode bit 1 position. */

/* EDMA.INTFLAGS  bit masks and bit positions */
#define EDMA_CH3ERRIF_bm  0x80  /* Channel 3 Transaction Error Interrupt Flag bit mask. */
#define EDMA_CH3ERRIF_bp  7  /* Channel 3 Transaction Error Interrupt Flag bit position. */

#define EDMA_CH2ERRIF_bm  0x40  /* Channel 2 Transaction Error Interrupt Flag bit mask. */
#define EDMA_CH2ERRIF_bp  6  /* Channel 2 Transaction Error Interrupt Flag bit position. */

#define EDMA_CH1ERRIF_bm  0x20  /* Channel 1 Transaction Error Interrupt Flag bit mask. */
#define EDMA_CH1ERRIF_bp  5  /* Channel 1 Transaction Error Interrupt Flag bit position. */

#define EDMA_CH0ERRIF_bm  0x10  /* Channel 0 Transaction Error Interrupt Flag bit mask. */
#define EDMA_CH0ERRIF_bp  4  /* Channel 0 Transaction Error Interrupt Flag bit position. */

#define EDMA_CH3TRNFIF_bm  0x08  /* Channel 3 Transaction Complete Interrupt Flag bit mask. */
#define EDMA_CH3TRNFIF_bp  3  /* Channel 3 Transaction Complete Interrupt Flag bit position. */

#define EDMA_CH2TRNFIF_bm  0x04  /* Channel 2 Transaction Complete Interrupt Flag bit mask. */
#define EDMA_CH2TRNFIF_bp  2  /* Channel 2 Transaction Complete Interrupt Flag bit position. */

#define EDMA_CH1TRNFIF_bm  0x02  /* Channel 1 Transaction Complete Interrupt Flag bit mask. */
#define EDMA_CH1TRNFIF_bp  1  /* Channel 1 Transaction Complete Interrupt Flag bit position. */

#define EDMA_CH0TRNFIF_bm  0x01  /* Channel 0 Transaction Complete Interrupt Flag bit mask. */
#define EDMA_CH0TRNFIF_bp  0  /* Channel 0 Transaction Complete Interrupt Flag bit position. */

/* EDMA.STATUS  bit masks and bit positions */
#define EDMA_CH3BUSY_bm  0x80  /* Channel 3 Busy Flag bit mask. */
#define EDMA_CH3BUSY_bp  7  /* Channel 3 Busy Flag bit position. */

#define EDMA_CH2BUSY_bm  0x40  /* Channel 2 Busy Flag bit mask. */
#define EDMA_CH2BUSY_bp  6  /* Channel 2 Busy Flag bit position. */

#define EDMA_CH1BUSY_bm  0x20  /* Channel 1 Busy Flag bit mask. */
#define EDMA_CH1BUSY_bp  5  /* Channel 1 Busy Flag bit position. */

#define EDMA_CH0BUSY_bm  0x10  /* Channel 0 Busy Flag bit mask. */
#define EDMA_CH0BUSY_bp  4  /* Channel 0 Busy Flag bit position. */

#define EDMA_CH3PEND_bm  0x08  /* Channel 3 Pending Flag bit mask. */
#define EDMA_CH3PEND_bp  3  /* Channel 3 Pending Flag bit position. */

#define EDMA_CH2PEND_bm  0x04  /* Channel 2 Pending Flag bit mask. */
#define EDMA_CH2PEND_bp  2  /* Channel 2 Pending Flag bit position. */

#define EDMA_CH1PEND_bm  0x02  /* Channel 1 Pending Flag bit mask. */
#define EDMA_CH1PEND_bp  1  /* Channel 1 Pending Flag bit position. */

#define EDMA_CH0PEND_bm  0x01  /* Channel 0 Pending Flag bit mask. */
#define EDMA_CH0PEND_bp  0  /* Channel 0 Pending Flag bit position. */

/* EDMA_CH.CTRLA  bit masks and bit positions */
#define EDMA_CH_ENABLE_bm  0x80  /* Channel Enable bit mask. */
#define EDMA_CH_ENABLE_bp  7  /* Channel Enable bit position. */

#define EDMA_CH_RESET_bm  0x40  /* Channel Software Reset bit mask. */
#define EDMA_CH_RESET_bp  6  /* Channel Software Reset bit position. */

#define EDMA_CH_REPEAT_bm  0x20  /* Channel Repeat Mode bit mask. */
#define EDMA_CH_REPEAT_bp  5  /* Channel Repeat Mode bit position. */

#define EDMA_CH_TRFREQ_bm  0x10  /* Channel Transfer Request bit mask. */
#define EDMA_CH_TRFREQ_bp  4  /* Channel Transfer Request bit position. */

#define EDMA_CH_SINGLE_bm  0x04  /* Channel Single Shot Data Transfer bit mask. */
#define EDMA_CH_SINGLE_bp  2  /* Channel Single Shot Data Transfer bit position. */

#define EDMA_CH_BURSTLEN_bm  0x01  /* Channel 2-bytes Burst Length bit mask. */
#define EDMA_CH_BURSTLEN_bp  0  /* Channel 2-bytes Burst Length bit position. */

/* EDMA_CH.CTRLB  bit masks and bit positions */
#define EDMA_CH_CHBUSY_bm  0x80  /* Channel Block Transfer Busy bit mask. */
#define EDMA_CH_CHBUSY_bp  7  /* Channel Block Transfer Busy bit position. */

#define EDMA_CH_CHPEND_bm  0x40  /* Channel Block Transfer Pending bit mask. */
#define EDMA_CH_CHPEND_bp  6  /* Channel Block Transfer Pending bit position. */

#define EDMA_CH_ERRIF_bm  0x20  /* Channel Transaction Error Interrupt Flag bit mask. */
#define EDMA_CH_ERRIF_bp  5  /* Channel Transaction Error Interrupt Flag bit position. */

#define EDMA_CH_TRNIF_bm  0x10  /* Channel Transaction Complete Interrup Flag bit mask. */
#define EDMA_CH_TRNIF_bp  4  /* Channel Transaction Complete Interrup Flag bit position. */

#define EDMA_CH_ERRINTLVL_gm  0x0C  /* Channel Transaction Error Interrupt Level group mask. */
#define EDMA_CH_ERRINTLVL_gp  2  /* Channel Transaction Error Interrupt Level group position. */
#define EDMA_CH_ERRINTLVL0_bm  (1<<2)  /* Channel Transaction Error Interrupt Level bit 0 mask. */
#define EDMA_CH_ERRINTLVL0_bp  2  /* Channel Transaction Error Interrupt Level bit 0 position. */
#define EDMA_CH_ERRINTLVL1_bm  (1<<3)  /* Channel Transaction Error Interrupt Level bit 1 mask. */
#define EDMA_CH_ERRINTLVL1_bp  3  /* Channel Transaction Error Interrupt Level bit 1 position. */

#define EDMA_CH_TRNINTLVL_gm  0x03  /* Channel Transaction Complete Interrupt Level group mask. */
#define EDMA_CH_TRNINTLVL_gp  0  /* Channel Transaction Complete Interrupt Level group position. */
#define EDMA_CH_TRNINTLVL0_bm  (1<<0)  /* Channel Transaction Complete Interrupt Level bit 0 mask. */
#define EDMA_CH_TRNINTLVL0_bp  0  /* Channel Transaction Complete Interrupt Level bit 0 position. */
#define EDMA_CH_TRNINTLVL1_bm  (1<<1)  /* Channel Transaction Complete Interrupt Level bit 1 mask. */
#define EDMA_CH_TRNINTLVL1_bp  1  /* Channel Transaction Complete Interrupt Level bit 1 position. */

/* EDMA_CH.ADDRCTRL  bit masks and bit positions */
#define EDMA_CH_RELOAD_gm  0x30  /* Memory Address Reload for Peripheral Ch., or Source Address Reload for Standard Ch. group mask. */
#define EDMA_CH_RELOAD_gp  4  /* Memory Address Reload for Peripheral Ch., or Source Address Reload for Standard Ch. group position. */
#define EDMA_CH_RELOAD0_bm  (1<<4)  /* Memory Address Reload for Peripheral Ch., or Source Address Reload for Standard Ch. bit 0 mask. */
#define EDMA_CH_RELOAD0_bp  4  /* Memory Address Reload for Peripheral Ch., or Source Address Reload for Standard Ch. bit 0 position. */
#define EDMA_CH_RELOAD1_bm  (1<<5)  /* Memory Address Reload for Peripheral Ch., or Source Address Reload for Standard Ch. bit 1 mask. */
#define EDMA_CH_RELOAD1_bp  5  /* Memory Address Reload for Peripheral Ch., or Source Address Reload for Standard Ch. bit 1 position. */

#define EDMA_CH_DIR_gm  0x07  /* Memory Address Mode for Peripheral Ch., or Source Address Mode for Standard Ch. group mask. */
#define EDMA_CH_DIR_gp  0  /* Memory Address Mode for Peripheral Ch., or Source Address Mode for Standard Ch. group position. */
#define EDMA_CH_DIR0_bm  (1<<0)  /* Memory Address Mode for Peripheral Ch., or Source Address Mode for Standard Ch. bit 0 mask. */
#define EDMA_CH_DIR0_bp  0  /* Memory Address Mode for Peripheral Ch., or Source Address Mode for Standard Ch. bit 0 position. */
#define EDMA_CH_DIR1_bm  (1<<1)  /* Memory Address Mode for Peripheral Ch., or Source Address Mode for Standard Ch. bit 1 mask. */
#define EDMA_CH_DIR1_bp  1  /* Memory Address Mode for Peripheral Ch., or Source Address Mode for Standard Ch. bit 1 position. */
#define EDMA_CH_DIR2_bm  (1<<2)  /* Memory Address Mode for Peripheral Ch., or Source Address Mode for Standard Ch. bit 2 mask. */
#define EDMA_CH_DIR2_bp  2  /* Memory Address Mode for Peripheral Ch., or Source Address Mode for Standard Ch. bit 2 position. */

/* EDMA_CH.DESTADDRCTRL  bit masks and bit positions */
#define EDMA_CH_DESTRELOAD_gm  0x30  /* Destination Address Reload for Standard Channels Only. group mask. */
#define EDMA_CH_DESTRELOAD_gp  4  /* Destination Address Reload for Standard Channels Only. group position. */
#define EDMA_CH_DESTRELOAD0_bm  (1<<4)  /* Destination Address Reload for Standard Channels Only. bit 0 mask. */
#define EDMA_CH_DESTRELOAD0_bp  4  /* Destination Address Reload for Standard Channels Only. bit 0 position. */
#define EDMA_CH_DESTRELOAD1_bm  (1<<5)  /* Destination Address Reload for Standard Channels Only. bit 1 mask. */
#define EDMA_CH_DESTRELOAD1_bp  5  /* Destination Address Reload for Standard Channels Only. bit 1 position. */

#define EDMA_CH_DESTDIR_gm  0x07  /* Destination Address Mode for Standard Channels Only. group mask. */
#define EDMA_CH_DESTDIR_gp  0  /* Destination Address Mode for Standard Channels Only. group position. */
#define EDMA_CH_DESTDIR0_bm  (1<<0)  /* Destination Address Mode for Standard Channels Only. bit 0 mask. */
#define EDMA_CH_DESTDIR0_bp  0  /* Destination Address Mode for Standard Channels Only. bit 0 position. */
#define EDMA_CH_DESTDIR1_bm  (1<<1)  /* Destination Address Mode for Standard Channels Only. bit 1 mask. */
#define EDMA_CH_DESTDIR1_bp  1  /* Destination Address Mode for Standard Channels Only. bit 1 position. */
#define EDMA_CH_DESTDIR2_bm  (1<<2)  /* Destination Address Mode for Standard Channels Only. bit 2 mask. */
#define EDMA_CH_DESTDIR2_bp  2  /* Destination Address Mode for Standard Channels Only. bit 2 position. */

/* EDMA_CH.TRIGSRC  bit masks and bit positions */
#define EDMA_CH_TRIGSRC_gm  0xFF  /* Channel Trigger Source group mask. */
#define EDMA_CH_TRIGSRC_gp  0  /* Channel Trigger Source group position. */
#define EDMA_CH_TRIGSRC0_bm  (1<<0)  /* Channel Trigger Source bit 0 mask. */
#define EDMA_CH_TRIGSRC0_bp  0  /* Channel Trigger Source bit 0 position. */
#define EDMA_CH_TRIGSRC1_bm  (1<<1)  /* Channel Trigger Source bit 1 mask. */
#define EDMA_CH_TRIGSRC1_bp  1  /* Channel Trigger Source bit 1 position. */
#define EDMA_CH_TRIGSRC2_bm  (1<<2)  /* Channel Trigger Source bit 2 mask. */
#define EDMA_CH_TRIGSRC2_bp  2  /* Channel Trigger Source bit 2 position. */
#define EDMA_CH_TRIGSRC3_bm  (1<<3)  /* Channel Trigger Source bit 3 mask. */
#define EDMA_CH_TRIGSRC3_bp  3  /* Channel Trigger Source bit 3 position. */
#define EDMA_CH_TRIGSRC4_bm  (1<<4)  /* Channel Trigger Source bit 4 mask. */
#define EDMA_CH_TRIGSRC4_bp  4  /* Channel Trigger Source bit 4 position. */
#define EDMA_CH_TRIGSRC5_bm  (1<<5)  /* Channel Trigger Source bit 5 mask. */
#define EDMA_CH_TRIGSRC5_bp  5  /* Channel Trigger Source bit 5 position. */
#define EDMA_CH_TRIGSRC6_bm  (1<<6)  /* Channel Trigger Source bit 6 mask. */
#define EDMA_CH_TRIGSRC6_bp  6  /* Channel Trigger Source bit 6 position. */
#define EDMA_CH_TRIGSRC7_bm  (1<<7)  /* Channel Trigger Source bit 7 mask. */
#define EDMA_CH_TRIGSRC7_bp  7  /* Channel Trigger Source bit 7 position. */

/* EVSYS - Event System */
/* EVSYS.CH0MUX  bit masks and bit positions */
#define EVSYS_CHMUX_gm  0xFF  /* Event Channel 0 Multiplexer group mask. */
#define EVSYS_CHMUX_gp  0  /* Event Channel 0 Multiplexer group position. */
#define EVSYS_CHMUX0_bm  (1<<0)  /* Event Channel 0 Multiplexer bit 0 mask. */
#define EVSYS_CHMUX0_bp  0  /* Event Channel 0 Multiplexer bit 0 position. */
#define EVSYS_CHMUX1_bm  (1<<1)  /* Event Channel 0 Multiplexer bit 1 mask. */
#define EVSYS_CHMUX1_bp  1  /* Event Channel 0 Multiplexer bit 1 position. */
#define EVSYS_CHMUX2_bm  (1<<2)  /* Event Channel 0 Multiplexer bit 2 mask. */
#define EVSYS_CHMUX2_bp  2  /* Event Channel 0 Multiplexer bit 2 position. */
#define EVSYS_CHMUX3_bm  (1<<3)  /* Event Channel 0 Multiplexer bit 3 mask. */
#define EVSYS_CHMUX3_bp  3  /* Event Channel 0 Multiplexer bit 3 position. */
#define EVSYS_CHMUX4_bm  (1<<4)  /* Event Channel 0 Multiplexer bit 4 mask. */
#define EVSYS_CHMUX4_bp  4  /* Event Channel 0 Multiplexer bit 4 position. */
#define EVSYS_CHMUX5_bm  (1<<5)  /* Event Channel 0 Multiplexer bit 5 mask. */
#define EVSYS_CHMUX5_bp  5  /* Event Channel 0 Multiplexer bit 5 position. */
#define EVSYS_CHMUX6_bm  (1<<6)  /* Event Channel 0 Multiplexer bit 6 mask. */
#define EVSYS_CHMUX6_bp  6  /* Event Channel 0 Multiplexer bit 6 position. */
#define EVSYS_CHMUX7_bm  (1<<7)  /* Event Channel 0 Multiplexer bit 7 mask. */
#define EVSYS_CHMUX7_bp  7  /* Event Channel 0 Multiplexer bit 7 position. */

/* EVSYS.CH1MUX  bit masks and bit positions */
/* EVSYS_CHMUX  Predefined. */
/* EVSYS_CHMUX  Predefined. */

/* EVSYS.CH2MUX  bit masks and bit positions */
/* EVSYS_CHMUX  Predefined. */
/* EVSYS_CHMUX  Predefined. */

/* EVSYS.CH3MUX  bit masks and bit positions */
/* EVSYS_CHMUX  Predefined. */
/* EVSYS_CHMUX  Predefined. */

/* EVSYS.CH4MUX  bit masks and bit positions */
/* EVSYS_CHMUX  Predefined. */
/* EVSYS_CHMUX  Predefined. */

/* EVSYS.CH5MUX  bit masks and bit positions */
/* EVSYS_CHMUX  Predefined. */
/* EVSYS_CHMUX  Predefined. */

/* EVSYS.CH6MUX  bit masks and bit positions */
/* EVSYS_CHMUX  Predefined. */
/* EVSYS_CHMUX  Predefined. */

/* EVSYS.CH7MUX  bit masks and bit positions */
/* EVSYS_CHMUX  Predefined. */
/* EVSYS_CHMUX  Predefined. */

/* EVSYS.CH0CTRL  bit masks and bit positions */
#define EVSYS_ROTARY_bm  0x80  /* Rotary Decoder Enable bit mask. */
#define EVSYS_ROTARY_bp  7  /* Rotary Decoder Enable bit position. */

#define EVSYS_QDIRM_gm  0x60  /* Quadrature Decoder Index Recognition Mode group mask. */
#define EVSYS_QDIRM_gp  5  /* Quadrature Decoder Index Recognition Mode group position. */
#define EVSYS_QDIRM0_bm  (1<<5)  /* Quadrature Decoder Index Recognition Mode bit 0 mask. */
#define EVSYS_QDIRM0_bp  5  /* Quadrature Decoder Index Recognition Mode bit 0 position. */
#define EVSYS_QDIRM1_bm  (1<<6)  /* Quadrature Decoder Index Recognition Mode bit 1 mask. */
#define EVSYS_QDIRM1_bp  6  /* Quadrature Decoder Index Recognition Mode bit 1 position. */

#define EVSYS_QDIEN_bm  0x10  /* Quadrature Decoder Index Enable bit mask. */
#define EVSYS_QDIEN_bp  4  /* Quadrature Decoder Index Enable bit position. */

#define EVSYS_QDEN_bm  0x08  /* Quadrature Decoder Enable bit mask. */
#define EVSYS_QDEN_bp  3  /* Quadrature Decoder Enable bit position. */

#define EVSYS_DIGFILT_gm  0x07  /* Digital Filter group mask. */
#define EVSYS_DIGFILT_gp  0  /* Digital Filter group position. */
#define EVSYS_DIGFILT0_bm  (1<<0)  /* Digital Filter bit 0 mask. */
#define EVSYS_DIGFILT0_bp  0  /* Digital Filter bit 0 position. */
#define EVSYS_DIGFILT1_bm  (1<<1)  /* Digital Filter bit 1 mask. */
#define EVSYS_DIGFILT1_bp  1  /* Digital Filter bit 1 position. */
#define EVSYS_DIGFILT2_bm  (1<<2)  /* Digital Filter bit 2 mask. */
#define EVSYS_DIGFILT2_bp  2  /* Digital Filter bit 2 position. */

/* EVSYS.CH1CTRL  bit masks and bit positions */
/* EVSYS_DIGFILT  Predefined. */
/* EVSYS_DIGFILT  Predefined. */

/* EVSYS.CH2CTRL  bit masks and bit positions */
/* EVSYS_DIGFILT  Predefined. */
/* EVSYS_DIGFILT  Predefined. */

/* EVSYS.CH3CTRL  bit masks and bit positions */
/* EVSYS_DIGFILT  Predefined. */
/* EVSYS_DIGFILT  Predefined. */

/* EVSYS.CH4CTRL  bit masks and bit positions */
/* EVSYS_DIGFILT  Predefined. */
/* EVSYS_DIGFILT  Predefined. */

/* EVSYS.CH5CTRL  bit masks and bit positions */
/* EVSYS_DIGFILT  Predefined. */
/* EVSYS_DIGFILT  Predefined. */

/* EVSYS.CH6CTRL  bit masks and bit positions */
/* EVSYS_DIGFILT  Predefined. */
/* EVSYS_DIGFILT  Predefined. */

/* EVSYS.CH7CTRL  bit masks and bit positions */
/* EVSYS_DIGFILT  Predefined. */
/* EVSYS_DIGFILT  Predefined. */

/* EVSYS.DFCTRL  bit masks and bit positions */
#define EVSYS_PRESCFILT_gm  0xF0  /* Prescaler Filter group mask. */
#define EVSYS_PRESCFILT_gp  4  /* Prescaler Filter group position. */
#define EVSYS_PRESCFILT0_bm  (1<<4)  /* Prescaler Filter bit 0 mask. */
#define EVSYS_PRESCFILT0_bp  4  /* Prescaler Filter bit 0 position. */
#define EVSYS_PRESCFILT1_bm  (1<<5)  /* Prescaler Filter bit 1 mask. */
#define EVSYS_PRESCFILT1_bp  5  /* Prescaler Filter bit 1 position. */
#define EVSYS_PRESCFILT2_bm  (1<<6)  /* Prescaler Filter bit 2 mask. */
#define EVSYS_PRESCFILT2_bp  6  /* Prescaler Filter bit 2 position. */
#define EVSYS_PRESCFILT3_bm  (1<<7)  /* Prescaler Filter bit 3 mask. */
#define EVSYS_PRESCFILT3_bp  7  /* Prescaler Filter bit 3 position. */

#define EVSYS_FILTSEL_bm  0x08  /* Prescaler Filter Select bit mask. */
#define EVSYS_FILTSEL_bp  3  /* Prescaler Filter Select bit position. */

#define EVSYS_PRESC_gm  0x07  /* Prescaler group mask. */
#define EVSYS_PRESC_gp  0  /* Prescaler group position. */
#define EVSYS_PRESC0_bm  (1<<0)  /* Prescaler bit 0 mask. */
#define EVSYS_PRESC0_bp  0  /* Prescaler bit 0 position. */
#define EVSYS_PRESC1_bm  (1<<1)  /* Prescaler bit 1 mask. */
#define EVSYS_PRESC1_bp  1  /* Prescaler bit 1 position. */
#define EVSYS_PRESC2_bm  (1<<2)  /* Prescaler bit 2 mask. */
#define EVSYS_PRESC2_bp  2  /* Prescaler bit 2 position. */

/* NVM - Non Volatile Memory Controller */
/* NVM.CMD  bit masks and bit positions */
#define NVM_CMD_gm  0x7F  /* Command group mask. */
#define NVM_CMD_gp  0  /* Command group position. */
#define NVM_CMD0_bm  (1<<0)  /* Command bit 0 mask. */
#define NVM_CMD0_bp  0  /* Command bit 0 position. */
#define NVM_CMD1_bm  (1<<1)  /* Command bit 1 mask. */
#define NVM_CMD1_bp  1  /* Command bit 1 position. */
#define NVM_CMD2_bm  (1<<2)  /* Command bit 2 mask. */
#define NVM_CMD2_bp  2  /* Command bit 2 position. */
#define NVM_CMD3_bm  (1<<3)  /* Command bit 3 mask. */
#define NVM_CMD3_bp  3  /* Command bit 3 position. */
#define NVM_CMD4_bm  (1<<4)  /* Command bit 4 mask. */
#define NVM_CMD4_bp  4  /* Command bit 4 position. */
#define NVM_CMD5_bm  (1<<5)  /* Command bit 5 mask. */
#define NVM_CMD5_bp  5  /* Command bit 5 position. */
#define NVM_CMD6_bm  (1<<6)  /* Command bit 6 mask. */
#define NVM_CMD6_bp  6  /* Command bit 6 position. */

/* NVM.CTRLA  bit masks and bit positions */
#define NVM_CMDEX_bm  0x01  /* Command Execute bit mask. */
#define NVM_CMDEX_bp  0  /* Command Execute bit position. */

/* NVM.CTRLB  bit masks and bit positions */
#define NVM_EPRM_bm  0x02  /* EEPROM Power Reduction Enable bit mask. */
#define NVM_EPRM_bp  1  /* EEPROM Power Reduction Enable bit position. */

#define NVM_SPMLOCK_bm  0x01  /* SPM Lock bit mask. */
#define NVM_SPMLOCK_bp  0  /* SPM Lock bit position. */

/* NVM.INTCTRL  bit masks and bit positions */
#define NVM_SPMLVL_gm  0x0C  /* SPM Interrupt Level group mask. */
#define NVM_SPMLVL_gp  2  /* SPM Interrupt Level group position. */
#define NVM_SPMLVL0_bm  (1<<2)  /* SPM Interrupt Level bit 0 mask. */
#define NVM_SPMLVL0_bp  2  /* SPM Interrupt Level bit 0 position. */
#define NVM_SPMLVL1_bm  (1<<3)  /* SPM Interrupt Level bit 1 mask. */
#define NVM_SPMLVL1_bp  3  /* SPM Interrupt Level bit 1 position. */

#define NVM_EELVL_gm  0x03  /* EEPROM Interrupt Level group mask. */
#define NVM_EELVL_gp  0  /* EEPROM Interrupt Level group position. */
#define NVM_EELVL0_bm  (1<<0)  /* EEPROM Interrupt Level bit 0 mask. */
#define NVM_EELVL0_bp  0  /* EEPROM Interrupt Level bit 0 position. */
#define NVM_EELVL1_bm  (1<<1)  /* EEPROM Interrupt Level bit 1 mask. */
#define NVM_EELVL1_bp  1  /* EEPROM Interrupt Level bit 1 position. */

/* NVM.STATUS  bit masks and bit positions */
#define NVM_NVMBUSY_bm  0x80  /* Non-volatile Memory Busy bit mask. */
#define NVM_NVMBUSY_bp  7  /* Non-volatile Memory Busy bit position. */

#define NVM_FBUSY_bm  0x40  /* Flash Memory Busy bit mask. */
#define NVM_FBUSY_bp  6  /* Flash Memory Busy bit position. */

#define NVM_EELOAD_bm  0x02  /* EEPROM Page Buffer Active Loading bit mask. */
#define NVM_EELOAD_bp  1  /* EEPROM Page Buffer Active Loading bit position. */

#define NVM_FLOAD_bm  0x01  /* Flash Page Buffer Active Loading bit mask. */
#define NVM_FLOAD_bp  0  /* Flash Page Buffer Active Loading bit position. */

/* NVM.LOCKBITS  bit masks and bit positions */
#define NVM_BLBB_gm  0xC0  /* Boot Lock Bits - Boot Section group mask. */
#define NVM_BLBB_gp  6  /* Boot Lock Bits - Boot Section group position. */
#define NVM_BLBB0_bm  (1<<6)  /* Boot Lock Bits - Boot Section bit 0 mask. */
#define NVM_BLBB0_bp  6  /* Boot Lock Bits - Boot Section bit 0 position. */
#define NVM_BLBB1_bm  (1<<7)  /* Boot Lock Bits - Boot Section bit 1 mask. */
#define NVM_BLBB1_bp  7  /* Boot Lock Bits - Boot Section bit 1 position. */

#define NVM_BLBA_gm  0x30  /* Boot Lock Bits - Application Section group mask. */
#define NVM_BLBA_gp  4  /* Boot Lock Bits - Application Section group position. */
#define NVM_BLBA0_bm  (1<<4)  /* Boot Lock Bits - Application Section bit 0 mask. */
#define NVM_BLBA0_bp  4  /* Boot Lock Bits - Application Section bit 0 position. */
#define NVM_BLBA1_bm  (1<<5)  /* Boot Lock Bits - Application Section bit 1 mask. */
#define NVM_BLBA1_bp  5  /* Boot Lock Bits - Application Section bit 1 position. */

#define NVM_BLBAT_gm  0x0C  /* Boot Lock Bits - Application Table group mask. */
#define NVM_BLBAT_gp  2  /* Boot Lock Bits - Application Table group position. */
#define NVM_BLBAT0_bm  (1<<2)  /* Boot Lock Bits - Application Table bit 0 mask. */
#define NVM_BLBAT0_bp  2  /* Boot Lock Bits - Application Table bit 0 position. */
#define NVM_BLBAT1_bm  (1<<3)  /* Boot Lock Bits - Application Table bit 1 mask. */
#define NVM_BLBAT1_bp  3  /* Boot Lock Bits - Application Table bit 1 position. */

#define NVM_LB_gm  0x03  /* Lock Bits group mask. */
#define NVM_LB_gp  0  /* Lock Bits group position. */
#define NVM_LB0_bm  (1<<0)  /* Lock Bits bit 0 mask. */
#define NVM_LB0_bp  0  /* Lock Bits bit 0 position. */
#define NVM_LB1_bm  (1<<1)  /* Lock Bits bit 1 mask. */
#define NVM_LB1_bp  1  /* Lock Bits bit 1 position. */

/* ADC - Analog/Digital Converter */
/* ADC_CH.CTRL  bit masks and bit positions */
#define ADC_CH_START_bm  0x80  /* Channel Start Conversion bit mask. */
#define ADC_CH_START_bp  7  /* Channel Start Conversion bit position. */

#define ADC_CH_GAIN_gm  0x1C  /* Gain Factor group mask. */
#define ADC_CH_GAIN_gp  2  /* Gain Factor group position. */
#define ADC_CH_GAIN0_bm  (1<<2)  /* Gain Factor bit 0 mask. */
#define ADC_CH_GAIN0_bp  2  /* Gain Factor bit 0 position. */
#define ADC_CH_GAIN1_bm  (1<<3)  /* Gain Factor bit 1 mask. */
#define ADC_CH_GAIN1_bp  3  /* Gain Factor bit 1 position. */
#define ADC_CH_GAIN2_bm  (1<<4)  /* Gain Factor bit 2 mask. */
#define ADC_CH_GAIN2_bp  4  /* Gain Factor bit 2 position. */

#define ADC_CH_INPUTMODE_gm  0x03  /* Input Mode Select group mask. */
#define ADC_CH_INPUTMODE_gp  0  /* Input Mode Select group position. */
#define ADC_CH_INPUTMODE0_bm  (1<<0)  /* Input Mode Select bit 0 mask. */
#define ADC_CH_INPUTMODE0_bp  0  /* Input Mode Select bit 0 position. */
#define ADC_CH_INPUTMODE1_bm  (1<<1)  /* Input Mode Select bit 1 mask. */
#define ADC_CH_INPUTMODE1_bp  1  /* Input Mode Select bit 1 position. */

/* ADC_CH.MUXCTRL  bit masks and bit positions */
#define ADC_CH_MUXPOS_gm  0x78  /* MUX selection on Positive ADC Input group mask. */
#define ADC_CH_MUXPOS_gp  3  /* MUX selection on Positive ADC Input group position. */
#define ADC_CH_MUXPOS0_bm  (1<<3)  /* MUX selection on Positive ADC Input bit 0 mask. */
#define ADC_CH_MUXPOS0_bp  3  /* MUX selection on Positive ADC Input bit 0 position. */
#define ADC_CH_MUXPOS1_bm  (1<<4)  /* MUX selection on Positive ADC Input bit 1 mask. */
#define ADC_CH_MUXPOS1_bp  4  /* MUX selection on Positive ADC Input bit 1 position. */
#define ADC_CH_MUXPOS2_bm  (1<<5)  /* MUX selection on Positive ADC Input bit 2 mask. */
#define ADC_CH_MUXPOS2_bp  5  /* MUX selection on Positive ADC Input bit 2 position. */
#define ADC_CH_MUXPOS3_bm  (1<<6)  /* MUX selection on Positive ADC Input bit 3 mask. */
#define ADC_CH_MUXPOS3_bp  6  /* MUX selection on Positive ADC Input bit 3 position. */

#define ADC_CH_MUXINT_gm  0x78  /* MUX selection on Internal ADC Input group mask. */
#define ADC_CH_MUXINT_gp  3  /* MUX selection on Internal ADC Input group position. */
#define ADC_CH_MUXINT0_bm  (1<<3)  /* MUX selection on Internal ADC Input bit 0 mask. */
#define ADC_CH_MUXINT0_bp  3  /* MUX selection on Internal ADC Input bit 0 position. */
#define ADC_CH_MUXINT1_bm  (1<<4)  /* MUX selection on Internal ADC Input bit 1 mask. */
#define ADC_CH_MUXINT1_bp  4  /* MUX selection on Internal ADC Input bit 1 position. */
#define ADC_CH_MUXINT2_bm  (1<<5)  /* MUX selection on Internal ADC Input bit 2 mask. */
#define ADC_CH_MUXINT2_bp  5  /* MUX selection on Internal ADC Input bit 2 position. */
#define ADC_CH_MUXINT3_bm  (1<<6)  /* MUX selection on Internal ADC Input bit 3 mask. */
#define ADC_CH_MUXINT3_bp  6  /* MUX selection on Internal ADC Input bit 3 position. */

#define ADC_CH_MUXNEG_gm  0x03  /* MUX selection on Negative ADC Input group mask. */
#define ADC_CH_MUXNEG_gp  0  /* MUX selection on Negative ADC Input group position. */
#define ADC_CH_MUXNEG0_bm  (1<<0)  /* MUX selection on Negative ADC Input bit 0 mask. */
#define ADC_CH_MUXNEG0_bp  0  /* MUX selection on Negative ADC Input bit 0 position. */
#define ADC_CH_MUXNEG1_bm  (1<<1)  /* MUX selection on Negative ADC Input bit 1 mask. */
#define ADC_CH_MUXNEG1_bp  1  /* MUX selection on Negative ADC Input bit 1 position. */

#define ADC_CH_MUXNEGL_gm  0x03  /* MUX selection on Negative ADC Input Gain on 4 LSB pins group mask. */
#define ADC_CH_MUXNEGL_gp  0  /* MUX selection on Negative ADC Input Gain on 4 LSB pins group position. */
#define ADC_CH_MUXNEGL0_bm  (1<<0)  /* MUX selection on Negative ADC Input Gain on 4 LSB pins bit 0 mask. */
#define ADC_CH_MUXNEGL0_bp  0  /* MUX selection on Negative ADC Input Gain on 4 LSB pins bit 0 position. */
#define ADC_CH_MUXNEGL1_bm  (1<<1)  /* MUX selection on Negative ADC Input Gain on 4 LSB pins bit 1 mask. */
#define ADC_CH_MUXNEGL1_bp  1  /* MUX selection on Negative ADC Input Gain on 4 LSB pins bit 1 position. */

#define ADC_CH_MUXNEGH_gm  0x03  /* MUX selection on Negative ADC Input Gain on 4 MSB pins group mask. */
#define ADC_CH_MUXNEGH_gp  0  /* MUX selection on Negative ADC Input Gain on 4 MSB pins group position. */
#define ADC_CH_MUXNEGH0_bm  (1<<0)  /* MUX selection on Negative ADC Input Gain on 4 MSB pins bit 0 mask. */
#define ADC_CH_MUXNEGH0_bp  0  /* MUX selection on Negative ADC Input Gain on 4 MSB pins bit 0 position. */
#define ADC_CH_MUXNEGH1_bm  (1<<1)  /* MUX selection on Negative ADC Input Gain on 4 MSB pins bit 1 mask. */
#define ADC_CH_MUXNEGH1_bp  1  /* MUX selection on Negative ADC Input Gain on 4 MSB pins bit 1 position. */

/* ADC_CH.INTCTRL  bit masks and bit positions */
#define ADC_CH_INTMODE_gm  0x0C  /* Interrupt Mode group mask. */
#define ADC_CH_INTMODE_gp  2  /* Interrupt Mode group position. */
#define ADC_CH_INTMODE0_bm  (1<<2)  /* Interrupt Mode bit 0 mask. */
#define ADC_CH_INTMODE0_bp  2  /* Interrupt Mode bit 0 position. */
#define ADC_CH_INTMODE1_bm  (1<<3)  /* Interrupt Mode bit 1 mask. */
#define ADC_CH_INTMODE1_bp  3  /* Interrupt Mode bit 1 position. */

#define ADC_CH_INTLVL_gm  0x03  /* Interrupt Level group mask. */
#define ADC_CH_INTLVL_gp  0  /* Interrupt Level group position. */
#define ADC_CH_INTLVL0_bm  (1<<0)  /* Interrupt Level bit 0 mask. */
#define ADC_CH_INTLVL0_bp  0  /* Interrupt Level bit 0 position. */
#define ADC_CH_INTLVL1_bm  (1<<1)  /* Interrupt Level bit 1 mask. */
#define ADC_CH_INTLVL1_bp  1  /* Interrupt Level bit 1 position. */

/* ADC_CH.INTFLAGS  bit masks and bit positions */
#define ADC_CH_IF_bm  0x01  /* Channel Interrupt Flag bit mask. */
#define ADC_CH_IF_bp  0  /* Channel Interrupt Flag bit position. */

/* ADC_CH.SCAN  bit masks and bit positions */
#define ADC_CH_INPUTOFFSET_gm  0xF0  /* Positive MUX Setting Offset group mask. */
#define ADC_CH_INPUTOFFSET_gp  4  /* Positive MUX Setting Offset group position. */
#define ADC_CH_INPUTOFFSET0_bm  (1<<4)  /* Positive MUX Setting Offset bit 0 mask. */
#define ADC_CH_INPUTOFFSET0_bp  4  /* Positive MUX Setting Offset bit 0 position. */
#define ADC_CH_INPUTOFFSET1_bm  (1<<5)  /* Positive MUX Setting Offset bit 1 mask. */
#define ADC_CH_INPUTOFFSET1_bp  5  /* Positive MUX Setting Offset bit 1 position. */
#define ADC_CH_INPUTOFFSET2_bm  (1<<6)  /* Positive MUX Setting Offset bit 2 mask. */
#define ADC_CH_INPUTOFFSET2_bp  6  /* Positive MUX Setting Offset bit 2 position. */
#define ADC_CH_INPUTOFFSET3_bm  (1<<7)  /* Positive MUX Setting Offset bit 3 mask. */
#define ADC_CH_INPUTOFFSET3_bp  7  /* Positive MUX Setting Offset bit 3 position. */

#define ADC_CH_INPUTSCAN_gm  0x0F  /* Number of Channels Included in Scan group mask. */
#define ADC_CH_INPUTSCAN_gp  0  /* Number of Channels Included in Scan group position. */
#define ADC_CH_INPUTSCAN0_bm  (1<<0)  /* Number of Channels Included in Scan bit 0 mask. */
#define ADC_CH_INPUTSCAN0_bp  0  /* Number of Channels Included in Scan bit 0 position. */
#define ADC_CH_INPUTSCAN1_bm  (1<<1)  /* Number of Channels Included in Scan bit 1 mask. */
#define ADC_CH_INPUTSCAN1_bp  1  /* Number of Channels Included in Scan bit 1 position. */
#define ADC_CH_INPUTSCAN2_bm  (1<<2)  /* Number of Channels Included in Scan bit 2 mask. */
#define ADC_CH_INPUTSCAN2_bp  2  /* Number of Channels Included in Scan bit 2 position. */
#define ADC_CH_INPUTSCAN3_bm  (1<<3)  /* Number of Channels Included in Scan bit 3 mask. */
#define ADC_CH_INPUTSCAN3_bp  3  /* Number of Channels Included in Scan bit 3 position. */

/* ADC_CH.CORRCTRL  bit masks and bit positions */
#define ADC_CH_CORREN_bm  0x01  /* Correction Enable bit mask. */
#define ADC_CH_CORREN_bp  0  /* Correction Enable bit position. */

/* ADC_CH.OFFSETCORR1  bit masks and bit positions */
#define ADC_CH_OFFSETCORR_gm  0x0F  /* Offset Correction Byte 1 group mask. */
#define ADC_CH_OFFSETCORR_gp  0  /* Offset Correction Byte 1 group position. */
#define ADC_CH_OFFSETCORR0_bm  (1<<0)  /* Offset Correction Byte 1 bit 0 mask. */
#define ADC_CH_OFFSETCORR0_bp  0  /* Offset Correction Byte 1 bit 0 position. */
#define ADC_CH_OFFSETCORR1_bm  (1<<1)  /* Offset Correction Byte 1 bit 1 mask. */
#define ADC_CH_OFFSETCORR1_bp  1  /* Offset Correction Byte 1 bit 1 position. */
#define ADC_CH_OFFSETCORR2_bm  (1<<2)  /* Offset Correction Byte 1 bit 2 mask. */
#define ADC_CH_OFFSETCORR2_bp  2  /* Offset Correction Byte 1 bit 2 position. */
#define ADC_CH_OFFSETCORR3_bm  (1<<3)  /* Offset Correction Byte 1 bit 3 mask. */
#define ADC_CH_OFFSETCORR3_bp  3  /* Offset Correction Byte 1 bit 3 position. */

/* ADC_CH.GAINCORR1  bit masks and bit positions */
#define ADC_CH_GAINCORR_gm  0x0F  /* Gain Correction Byte 1 group mask. */
#define ADC_CH_GAINCORR_gp  0  /* Gain Correction Byte 1 group position. */
#define ADC_CH_GAINCORR0_bm  (1<<0)  /* Gain Correction Byte 1 bit 0 mask. */
#define ADC_CH_GAINCORR0_bp  0  /* Gain Correction Byte 1 bit 0 position. */
#define ADC_CH_GAINCORR1_bm  (1<<1)  /* Gain Correction Byte 1 bit 1 mask. */
#define ADC_CH_GAINCORR1_bp  1  /* Gain Correction Byte 1 bit 1 position. */
#define ADC_CH_GAINCORR2_bm  (1<<2)  /* Gain Correction Byte 1 bit 2 mask. */
#define ADC_CH_GAINCORR2_bp  2  /* Gain Correction Byte 1 bit 2 position. */
#define ADC_CH_GAINCORR3_bm  (1<<3)  /* Gain Correction Byte 1 bit 3 mask. */
#define ADC_CH_GAINCORR3_bp  3  /* Gain Correction Byte 1 bit 3 position. */

/* ADC_CH.AVGCTRL  bit masks and bit positions */
#define ADC_CH_RIGHTSHIFT_gm  0x70  /* Right Shift group mask. */
#define ADC_CH_RIGHTSHIFT_gp  4  /* Right Shift group position. */
#define ADC_CH_RIGHTSHIFT0_bm  (1<<4)  /* Right Shift bit 0 mask. */
#define ADC_CH_RIGHTSHIFT0_bp  4  /* Right Shift bit 0 position. */
#define ADC_CH_RIGHTSHIFT1_bm  (1<<5)  /* Right Shift bit 1 mask. */
#define ADC_CH_RIGHTSHIFT1_bp  5  /* Right Shift bit 1 position. */
#define ADC_CH_RIGHTSHIFT2_bm  (1<<6)  /* Right Shift bit 2 mask. */
#define ADC_CH_RIGHTSHIFT2_bp  6  /* Right Shift bit 2 position. */

#define ADC_CH_SAMPNUM_gm  0x0F  /* Averaged Number of Samples group mask. */
#define ADC_CH_SAMPNUM_gp  0  /* Averaged Number of Samples group position. */
#define ADC_CH_SAMPNUM0_bm  (1<<0)  /* Averaged Number of Samples bit 0 mask. */
#define ADC_CH_SAMPNUM0_bp  0  /* Averaged Number of Samples bit 0 position. */
#define ADC_CH_SAMPNUM1_bm  (1<<1)  /* Averaged Number of Samples bit 1 mask. */
#define ADC_CH_SAMPNUM1_bp  1  /* Averaged Number of Samples bit 1 position. */
#define ADC_CH_SAMPNUM2_bm  (1<<2)  /* Averaged Number of Samples bit 2 mask. */
#define ADC_CH_SAMPNUM2_bp  2  /* Averaged Number of Samples bit 2 position. */
#define ADC_CH_SAMPNUM3_bm  (1<<3)  /* Averaged Number of Samples bit 3 mask. */
#define ADC_CH_SAMPNUM3_bp  3  /* Averaged Number of Samples bit 3 position. */

/* ADC.CTRLA  bit masks and bit positions */
#define ADC_START_bm  0x04  /* Start Conversion bit mask. */
#define ADC_START_bp  2  /* Start Conversion bit position. */

#define ADC_FLUSH_bm  0x02  /* ADC Flush bit mask. */
#define ADC_FLUSH_bp  1  /* ADC Flush bit position. */

#define ADC_ENABLE_bm  0x01  /* Enable ADC bit mask. */
#define ADC_ENABLE_bp  0  /* Enable ADC bit position. */

/* ADC.CTRLB  bit masks and bit positions */
#define ADC_CURRLIMIT_gm  0x60  /* Current Limitation group mask. */
#define ADC_CURRLIMIT_gp  5  /* Current Limitation group position. */
#define ADC_CURRLIMIT0_bm  (1<<5)  /* Current Limitation bit 0 mask. */
#define ADC_CURRLIMIT0_bp  5  /* Current Limitation bit 0 position. */
#define ADC_CURRLIMIT1_bm  (1<<6)  /* Current Limitation bit 1 mask. */
#define ADC_CURRLIMIT1_bp  6  /* Current Limitation bit 1 position. */

#define ADC_CONMODE_bm  0x10  /* Conversion Mode bit mask. */
#define ADC_CONMODE_bp  4  /* Conversion Mode bit position. */

#define ADC_FREERUN_bm  0x08  /* Free Running Mode Enable bit mask. */
#define ADC_FREERUN_bp  3  /* Free Running Mode Enable bit position. */

#define ADC_RESOLUTION_gm  0x06  /* Result Resolution group mask. */
#define ADC_RESOLUTION_gp  1  /* Result Resolution group position. */
#define ADC_RESOLUTION0_bm  (1<<1)  /* Result Resolution bit 0 mask. */
#define ADC_RESOLUTION0_bp  1  /* Result Resolution bit 0 position. */
#define ADC_RESOLUTION1_bm  (1<<2)  /* Result Resolution bit 1 mask. */
#define ADC_RESOLUTION1_bp  2  /* Result Resolution bit 1 position. */

/* ADC.REFCTRL  bit masks and bit positions */
#define ADC_REFSEL_gm  0x70  /* Reference Selection group mask. */
#define ADC_REFSEL_gp  4  /* Reference Selection group position. */
#define ADC_REFSEL0_bm  (1<<4)  /* Reference Selection bit 0 mask. */
#define ADC_REFSEL0_bp  4  /* Reference Selection bit 0 position. */
#define ADC_REFSEL1_bm  (1<<5)  /* Reference Selection bit 1 mask. */
#define ADC_REFSEL1_bp  5  /* Reference Selection bit 1 position. */
#define ADC_REFSEL2_bm  (1<<6)  /* Reference Selection bit 2 mask. */
#define ADC_REFSEL2_bp  6  /* Reference Selection bit 2 position. */

#define ADC_BANDGAP_bm  0x02  /* Bandgap enable bit mask. */
#define ADC_BANDGAP_bp  1  /* Bandgap enable bit position. */

#define ADC_TEMPREF_bm  0x01  /* Temperature Reference Enable bit mask. */
#define ADC_TEMPREF_bp  0  /* Temperature Reference Enable bit position. */

/* ADC.EVCTRL  bit masks and bit positions */
#define ADC_EVSEL_gm  0x38  /* Event Input Select group mask. */
#define ADC_EVSEL_gp  3  /* Event Input Select group position. */
#define ADC_EVSEL0_bm  (1<<3)  /* Event Input Select bit 0 mask. */
#define ADC_EVSEL0_bp  3  /* Event Input Select bit 0 position. */
#define ADC_EVSEL1_bm  (1<<4)  /* Event Input Select bit 1 mask. */
#define ADC_EVSEL1_bp  4  /* Event Input Select bit 1 position. */
#define ADC_EVSEL2_bm  (1<<5)  /* Event Input Select bit 2 mask. */
#define ADC_EVSEL2_bp  5  /* Event Input Select bit 2 position. */

#define ADC_EVACT_gm  0x07  /* Event Action Select group mask. */
#define ADC_EVACT_gp  0  /* Event Action Select group position. */
#define ADC_EVACT0_bm  (1<<0)  /* Event Action Select bit 0 mask. */
#define ADC_EVACT0_bp  0  /* Event Action Select bit 0 position. */
#define ADC_EVACT1_bm  (1<<1)  /* Event Action Select bit 1 mask. */
#define ADC_EVACT1_bp  1  /* Event Action Select bit 1 position. */
#define ADC_EVACT2_bm  (1<<2)  /* Event Action Select bit 2 mask. */
#define ADC_EVACT2_bp  2  /* Event Action Select bit 2 position. */

/* ADC.PRESCALER  bit masks and bit positions */
#define ADC_PRESCALER_gm  0x07  /* Clock Prescaler Selection group mask. */
#define ADC_PRESCALER_gp  0  /* Clock Prescaler Selection group position. */
#define ADC_PRESCALER0_bm  (1<<0)  /* Clock Prescaler Selection bit 0 mask. */
#define ADC_PRESCALER0_bp  0  /* Clock Prescaler Selection bit 0 position. */
#define ADC_PRESCALER1_bm  (1<<1)  /* Clock Prescaler Selection bit 1 mask. */
#define ADC_PRESCALER1_bp  1  /* Clock Prescaler Selection bit 1 position. */
#define ADC_PRESCALER2_bm  (1<<2)  /* Clock Prescaler Selection bit 2 mask. */
#define ADC_PRESCALER2_bp  2  /* Clock Prescaler Selection bit 2 position. */

/* ADC.INTFLAGS  bit masks and bit positions */
#define ADC_CH0IF_bm  0x01  /* Channel 0 Interrupt Flag bit mask. */
#define ADC_CH0IF_bp  0  /* Channel 0 Interrupt Flag bit position. */

/* ADC.SAMPCTRL  bit masks and bit positions */
#define ADC_SAMPVAL_gm  0x3F  /* Sampling time control register group mask. */
#define ADC_SAMPVAL_gp  0  /* Sampling time control register group position. */
#define ADC_SAMPVAL0_bm  (1<<0)  /* Sampling time control register bit 0 mask. */
#define ADC_SAMPVAL0_bp  0  /* Sampling time control register bit 0 position. */
#define ADC_SAMPVAL1_bm  (1<<1)  /* Sampling time control register bit 1 mask. */
#define ADC_SAMPVAL1_bp  1  /* Sampling time control register bit 1 position. */
#define ADC_SAMPVAL2_bm  (1<<2)  /* Sampling time control register bit 2 mask. */
#define ADC_SAMPVAL2_bp  2  /* Sampling time control register bit 2 position. */
#define ADC_SAMPVAL3_bm  (1<<3)  /* Sampling time control register bit 3 mask. */
#define ADC_SAMPVAL3_bp  3  /* Sampling time control register bit 3 position. */
#define ADC_SAMPVAL4_bm  (1<<4)  /* Sampling time control register bit 4 mask. */
#define ADC_SAMPVAL4_bp  4  /* Sampling time control register bit 4 position. */
#define ADC_SAMPVAL5_bm  (1<<5)  /* Sampling time control register bit 5 mask. */
#define ADC_SAMPVAL5_bp  5  /* Sampling time control register bit 5 position. */

/* DAC - Digital/Analog Converter */
/* DAC.CTRLA  bit masks and bit positions */
#define DAC_IDOEN_bm  0x10  /* Internal Output Enable bit mask. */
#define DAC_IDOEN_bp  4  /* Internal Output Enable bit position. */

#define DAC_CH1EN_bm  0x08  /* Channel 1 Output Enable bit mask. */
#define DAC_CH1EN_bp  3  /* Channel 1 Output Enable bit position. */

#define DAC_CH0EN_bm  0x04  /* Channel 0 Output Enable bit mask. */
#define DAC_CH0EN_bp  2  /* Channel 0 Output Enable bit position. */

#define DAC_LPMODE_bm  0x02  /* Low Power Mode bit mask. */
#define DAC_LPMODE_bp  1  /* Low Power Mode bit position. */

#define DAC_ENABLE_bm  0x01  /* Enable bit mask. */
#define DAC_ENABLE_bp  0  /* Enable bit position. */

/* DAC.CTRLB  bit masks and bit positions */
#define DAC_CHSEL_gm  0x60  /* Channel Select group mask. */
#define DAC_CHSEL_gp  5  /* Channel Select group position. */
#define DAC_CHSEL0_bm  (1<<5)  /* Channel Select bit 0 mask. */
#define DAC_CHSEL0_bp  5  /* Channel Select bit 0 position. */
#define DAC_CHSEL1_bm  (1<<6)  /* Channel Select bit 1 mask. */
#define DAC_CHSEL1_bp  6  /* Channel Select bit 1 position. */

#define DAC_CH1TRIG_bm  0x02  /* Channel 1 Event Trig Enable bit mask. */
#define DAC_CH1TRIG_bp  1  /* Channel 1 Event Trig Enable bit position. */

#define DAC_CH0TRIG_bm  0x01  /* Channel 0 Event Trig Enable bit mask. */
#define DAC_CH0TRIG_bp  0  /* Channel 0 Event Trig Enable bit position. */

/* DAC.CTRLC  bit masks and bit positions */
#define DAC_REFSEL_gm  0x18  /* Reference Select group mask. */
#define DAC_REFSEL_gp  3  /* Reference Select group position. */
#define DAC_REFSEL0_bm  (1<<3)  /* Reference Select bit 0 mask. */
#define DAC_REFSEL0_bp  3  /* Reference Select bit 0 position. */
#define DAC_REFSEL1_bm  (1<<4)  /* Reference Select bit 1 mask. */
#define DAC_REFSEL1_bp  4  /* Reference Select bit 1 position. */

#define DAC_LEFTADJ_bm  0x01  /* Left-adjust Result bit mask. */
#define DAC_LEFTADJ_bp  0  /* Left-adjust Result bit position. */

/* DAC.EVCTRL  bit masks and bit positions */
#define DAC_EVSPLIT_bm  0x08  /* Separate Event Channel Input for Channel 1 bit mask. */
#define DAC_EVSPLIT_bp  3  /* Separate Event Channel Input for Channel 1 bit position. */

#define DAC_EVSEL_gm  0x07  /* Event Input Selection group mask. */
#define DAC_EVSEL_gp  0  /* Event Input Selection group position. */
#define DAC_EVSEL0_bm  (1<<0)  /* Event Input Selection bit 0 mask. */
#define DAC_EVSEL0_bp  0  /* Event Input Selection bit 0 position. */
#define DAC_EVSEL1_bm  (1<<1)  /* Event Input Selection bit 1 mask. */
#define DAC_EVSEL1_bp  1  /* Event Input Selection bit 1 position. */
#define DAC_EVSEL2_bm  (1<<2)  /* Event Input Selection bit 2 mask. */
#define DAC_EVSEL2_bp  2  /* Event Input Selection bit 2 position. */

/* DAC.STATUS  bit masks and bit positions */
#define DAC_CH1DRE_bm  0x02  /* Channel 1 Data Register Empty bit mask. */
#define DAC_CH1DRE_bp  1  /* Channel 1 Data Register Empty bit position. */

#define DAC_CH0DRE_bm  0x01  /* Channel 0 Data Register Empty bit mask. */
#define DAC_CH0DRE_bp  0  /* Channel 0 Data Register Empty bit position. */

/* DAC.CH0GAINCAL  bit masks and bit positions */
#define DAC_CH0GAINCAL_gm  0x7F  /* Gain Calibration group mask. */
#define DAC_CH0GAINCAL_gp  0  /* Gain Calibration group position. */
#define DAC_CH0GAINCAL0_bm  (1<<0)  /* Gain Calibration bit 0 mask. */
#define DAC_CH0GAINCAL0_bp  0  /* Gain Calibration bit 0 position. */
#define DAC_CH0GAINCAL1_bm  (1<<1)  /* Gain Calibration bit 1 mask. */
#define DAC_CH0GAINCAL1_bp  1  /* Gain Calibration bit 1 position. */
#define DAC_CH0GAINCAL2_bm  (1<<2)  /* Gain Calibration bit 2 mask. */
#define DAC_CH0GAINCAL2_bp  2  /* Gain Calibration bit 2 position. */
#define DAC_CH0GAINCAL3_bm  (1<<3)  /* Gain Calibration bit 3 mask. */
#define DAC_CH0GAINCAL3_bp  3  /* Gain Calibration bit 3 position. */
#define DAC_CH0GAINCAL4_bm  (1<<4)  /* Gain Calibration bit 4 mask. */
#define DAC_CH0GAINCAL4_bp  4  /* Gain Calibration bit 4 position. */
#define DAC_CH0GAINCAL5_bm  (1<<5)  /* Gain Calibration bit 5 mask. */
#define DAC_CH0GAINCAL5_bp  5  /* Gain Calibration bit 5 position. */
#define DAC_CH0GAINCAL6_bm  (1<<6)  /* Gain Calibration bit 6 mask. */
#define DAC_CH0GAINCAL6_bp  6  /* Gain Calibration bit 6 position. */

/* DAC.CH0OFFSETCAL  bit masks and bit positions */
#define DAC_CH0OFFSETCAL_gm  0x7F  /* Offset Calibration group mask. */
#define DAC_CH0OFFSETCAL_gp  0  /* Offset Calibration group position. */
#define DAC_CH0OFFSETCAL0_bm  (1<<0)  /* Offset Calibration bit 0 mask. */
#define DAC_CH0OFFSETCAL0_bp  0  /* Offset Calibration bit 0 position. */
#define DAC_CH0OFFSETCAL1_bm  (1<<1)  /* Offset Calibration bit 1 mask. */
#define DAC_CH0OFFSETCAL1_bp  1  /* Offset Calibration bit 1 position. */
#define DAC_CH0OFFSETCAL2_bm  (1<<2)  /* Offset Calibration bit 2 mask. */
#define DAC_CH0OFFSETCAL2_bp  2  /* Offset Calibration bit 2 position. */
#define DAC_CH0OFFSETCAL3_bm  (1<<3)  /* Offset Calibration bit 3 mask. */
#define DAC_CH0OFFSETCAL3_bp  3  /* Offset Calibration bit 3 position. */
#define DAC_CH0OFFSETCAL4_bm  (1<<4)  /* Offset Calibration bit 4 mask. */
#define DAC_CH0OFFSETCAL4_bp  4  /* Offset Calibration bit 4 position. */
#define DAC_CH0OFFSETCAL5_bm  (1<<5)  /* Offset Calibration bit 5 mask. */
#define DAC_CH0OFFSETCAL5_bp  5  /* Offset Calibration bit 5 position. */
#define DAC_CH0OFFSETCAL6_bm  (1<<6)  /* Offset Calibration bit 6 mask. */
#define DAC_CH0OFFSETCAL6_bp  6  /* Offset Calibration bit 6 position. */

/* DAC.CH1GAINCAL  bit masks and bit positions */
#define DAC_CH1GAINCAL_gm  0x7F  /* Gain Calibration group mask. */
#define DAC_CH1GAINCAL_gp  0  /* Gain Calibration group position. */
#define DAC_CH1GAINCAL0_bm  (1<<0)  /* Gain Calibration bit 0 mask. */
#define DAC_CH1GAINCAL0_bp  0  /* Gain Calibration bit 0 position. */
#define DAC_CH1GAINCAL1_bm  (1<<1)  /* Gain Calibration bit 1 mask. */
#define DAC_CH1GAINCAL1_bp  1  /* Gain Calibration bit 1 position. */
#define DAC_CH1GAINCAL2_bm  (1<<2)  /* Gain Calibration bit 2 mask. */
#define DAC_CH1GAINCAL2_bp  2  /* Gain Calibration bit 2 position. */
#define DAC_CH1GAINCAL3_bm  (1<<3)  /* Gain Calibration bit 3 mask. */
#define DAC_CH1GAINCAL3_bp  3  /* Gain Calibration bit 3 position. */
#define DAC_CH1GAINCAL4_bm  (1<<4)  /* Gain Calibration bit 4 mask. */
#define DAC_CH1GAINCAL4_bp  4  /* Gain Calibration bit 4 position. */
#define DAC_CH1GAINCAL5_bm  (1<<5)  /* Gain Calibration bit 5 mask. */
#define DAC_CH1GAINCAL5_bp  5  /* Gain Calibration bit 5 position. */
#define DAC_CH1GAINCAL6_bm  (1<<6)  /* Gain Calibration bit 6 mask. */
#define DAC_CH1GAINCAL6_bp  6  /* Gain Calibration bit 6 position. */

/* DAC.CH1OFFSETCAL  bit masks and bit positions */
#define DAC_CH1OFFSETCAL_gm  0x7F  /* Offset Calibration group mask. */
#define DAC_CH1OFFSETCAL_gp  0  /* Offset Calibration group position. */
#define DAC_CH1OFFSETCAL0_bm  (1<<0)  /* Offset Calibration bit 0 mask. */
#define DAC_CH1OFFSETCAL0_bp  0  /* Offset Calibration bit 0 position. */
#define DAC_CH1OFFSETCAL1_bm  (1<<1)  /* Offset Calibration bit 1 mask. */
#define DAC_CH1OFFSETCAL1_bp  1  /* Offset Calibration bit 1 position. */
#define DAC_CH1OFFSETCAL2_bm  (1<<2)  /* Offset Calibration bit 2 mask. */
#define DAC_CH1OFFSETCAL2_bp  2  /* Offset Calibration bit 2 position. */
#define DAC_CH1OFFSETCAL3_bm  (1<<3)  /* Offset Calibration bit 3 mask. */
#define DAC_CH1OFFSETCAL3_bp  3  /* Offset Calibration bit 3 position. */
#define DAC_CH1OFFSETCAL4_bm  (1<<4)  /* Offset Calibration bit 4 mask. */
#define DAC_CH1OFFSETCAL4_bp  4  /* Offset Calibration bit 4 position. */
#define DAC_CH1OFFSETCAL5_bm  (1<<5)  /* Offset Calibration bit 5 mask. */
#define DAC_CH1OFFSETCAL5_bp  5  /* Offset Calibration bit 5 position. */
#define DAC_CH1OFFSETCAL6_bm  (1<<6)  /* Offset Calibration bit 6 mask. */
#define DAC_CH1OFFSETCAL6_bp  6  /* Offset Calibration bit 6 position. */

/* AC - Analog Comparator */
/* AC.AC0CTRL  bit masks and bit positions */
#define AC_INTMODE_gm  0xC0  /* Interrupt Mode group mask. */
#define AC_INTMODE_gp  6  /* Interrupt Mode group position. */
#define AC_INTMODE0_bm  (1<<6)  /* Interrupt Mode bit 0 mask. */
#define AC_INTMODE0_bp  6  /* Interrupt Mode bit 0 position. */
#define AC_INTMODE1_bm  (1<<7)  /* Interrupt Mode bit 1 mask. */
#define AC_INTMODE1_bp  7  /* Interrupt Mode bit 1 position. */

#define AC_INTLVL_gm  0x30  /* Interrupt Level group mask. */
#define AC_INTLVL_gp  4  /* Interrupt Level group position. */
#define AC_INTLVL0_bm  (1<<4)  /* Interrupt Level bit 0 mask. */
#define AC_INTLVL0_bp  4  /* Interrupt Level bit 0 position. */
#define AC_INTLVL1_bm  (1<<5)  /* Interrupt Level bit 1 mask. */
#define AC_INTLVL1_bp  5  /* Interrupt Level bit 1 position. */

#define AC_HYSMODE_gm  0x06  /* Hysteresis Mode group mask. */
#define AC_HYSMODE_gp  1  /* Hysteresis Mode group position. */
#define AC_HYSMODE0_bm  (1<<1)  /* Hysteresis Mode bit 0 mask. */
#define AC_HYSMODE0_bp  1  /* Hysteresis Mode bit 0 position. */
#define AC_HYSMODE1_bm  (1<<2)  /* Hysteresis Mode bit 1 mask. */
#define AC_HYSMODE1_bp  2  /* Hysteresis Mode bit 1 position. */

#define AC_ENABLE_bm  0x01  /* Enable bit mask. */
#define AC_ENABLE_bp  0  /* Enable bit position. */

/* AC.AC1CTRL  bit masks and bit positions */
/* AC_INTMODE  Predefined. */
/* AC_INTMODE  Predefined. */

/* AC_INTLVL  Predefined. */
/* AC_INTLVL  Predefined. */

/* AC_HYSMODE  Predefined. */
/* AC_HYSMODE  Predefined. */

/* AC_ENABLE  Predefined. */
/* AC_ENABLE  Predefined. */

/* AC.AC0MUXCTRL  bit masks and bit positions */
#define AC_MUXPOS_gm  0x38  /* MUX Positive Input group mask. */
#define AC_MUXPOS_gp  3  /* MUX Positive Input group position. */
#define AC_MUXPOS0_bm  (1<<3)  /* MUX Positive Input bit 0 mask. */
#define AC_MUXPOS0_bp  3  /* MUX Positive Input bit 0 position. */
#define AC_MUXPOS1_bm  (1<<4)  /* MUX Positive Input bit 1 mask. */
#define AC_MUXPOS1_bp  4  /* MUX Positive Input bit 1 position. */
#define AC_MUXPOS2_bm  (1<<5)  /* MUX Positive Input bit 2 mask. */
#define AC_MUXPOS2_bp  5  /* MUX Positive Input bit 2 position. */

#define AC_MUXNEG_gm  0x07  /* MUX Negative Input group mask. */
#define AC_MUXNEG_gp  0  /* MUX Negative Input group position. */
#define AC_MUXNEG0_bm  (1<<0)  /* MUX Negative Input bit 0 mask. */
#define AC_MUXNEG0_bp  0  /* MUX Negative Input bit 0 position. */
#define AC_MUXNEG1_bm  (1<<1)  /* MUX Negative Input bit 1 mask. */
#define AC_MUXNEG1_bp  1  /* MUX Negative Input bit 1 position. */
#define AC_MUXNEG2_bm  (1<<2)  /* MUX Negative Input bit 2 mask. */
#define AC_MUXNEG2_bp  2  /* MUX Negative Input bit 2 position. */

/* AC.AC1MUXCTRL  bit masks and bit positions */
/* AC_MUXPOS  Predefined. */
/* AC_MUXPOS  Predefined. */

/* AC_MUXNEG  Predefined. */
/* AC_MUXNEG  Predefined. */

/* AC.CTRLA  bit masks and bit positions */
#define AC_AC1INVEN_bm  0x08  /* Analog Comparator 1 Output Invert Enable bit mask. */
#define AC_AC1INVEN_bp  3  /* Analog Comparator 1 Output Invert Enable bit position. */

#define AC_AC0INVEN_bm  0x04  /* Analog Comparator 0 Output Invert Enable bit mask. */
#define AC_AC0INVEN_bp  2  /* Analog Comparator 0 Output Invert Enable bit position. */

#define AC_AC1OUT_bm  0x02  /* Analog Comparator 1 Output Enable bit mask. */
#define AC_AC1OUT_bp  1  /* Analog Comparator 1 Output Enable bit position. */

#define AC_AC0OUT_bm  0x01  /* Analog Comparator 0 Output Enable bit mask. */
#define AC_AC0OUT_bp  0  /* Analog Comparator 0 Output Enable bit position. */

/* AC.CTRLB  bit masks and bit positions */
#define AC_SCALEFAC_gm  0x3F  /* VCC Voltage Scaler Factor group mask. */
#define AC_SCALEFAC_gp  0  /* VCC Voltage Scaler Factor group position. */
#define AC_SCALEFAC0_bm  (1<<0)  /* VCC Voltage Scaler Factor bit 0 mask. */
#define AC_SCALEFAC0_bp  0  /* VCC Voltage Scaler Factor bit 0 position. */
#define AC_SCALEFAC1_bm  (1<<1)  /* VCC Voltage Scaler Factor bit 1 mask. */
#define AC_SCALEFAC1_bp  1  /* VCC Voltage Scaler Factor bit 1 position. */
#define AC_SCALEFAC2_bm  (1<<2)  /* VCC Voltage Scaler Factor bit 2 mask. */
#define AC_SCALEFAC2_bp  2  /* VCC Voltage Scaler Factor bit 2 position. */
#define AC_SCALEFAC3_bm  (1<<3)  /* VCC Voltage Scaler Factor bit 3 mask. */
#define AC_SCALEFAC3_bp  3  /* VCC Voltage Scaler Factor bit 3 position. */
#define AC_SCALEFAC4_bm  (1<<4)  /* VCC Voltage Scaler Factor bit 4 mask. */
#define AC_SCALEFAC4_bp  4  /* VCC Voltage Scaler Factor bit 4 position. */
#define AC_SCALEFAC5_bm  (1<<5)  /* VCC Voltage Scaler Factor bit 5 mask. */
#define AC_SCALEFAC5_bp  5  /* VCC Voltage Scaler Factor bit 5 position. */

/* AC.WINCTRL  bit masks and bit positions */
#define AC_WEN_bm  0x10  /* Window Mode Enable bit mask. */
#define AC_WEN_bp  4  /* Window Mode Enable bit position. */

#define AC_WINTMODE_gm  0x0C  /* Window Interrupt Mode group mask. */
#define AC_WINTMODE_gp  2  /* Window Interrupt Mode group position. */
#define AC_WINTMODE0_bm  (1<<2)  /* Window Interrupt Mode bit 0 mask. */
#define AC_WINTMODE0_bp  2  /* Window Interrupt Mode bit 0 position. */
#define AC_WINTMODE1_bm  (1<<3)  /* Window Interrupt Mode bit 1 mask. */
#define AC_WINTMODE1_bp  3  /* Window Interrupt Mode bit 1 position. */

#define AC_WINTLVL_gm  0x03  /* Window Interrupt Level group mask. */
#define AC_WINTLVL_gp  0  /* Window Interrupt Level group position. */
#define AC_WINTLVL0_bm  (1<<0)  /* Window Interrupt Level bit 0 mask. */
#define AC_WINTLVL0_bp  0  /* Window Interrupt Level bit 0 position. */
#define AC_WINTLVL1_bm  (1<<1)  /* Window Interrupt Level bit 1 mask. */
#define AC_WINTLVL1_bp  1  /* Window Interrupt Level bit 1 position. */

/* AC.STATUS  bit masks and bit positions */
#define AC_WSTATE_gm  0xC0  /* Window Mode State group mask. */
#define AC_WSTATE_gp  6  /* Window Mode State group position. */
#define AC_WSTATE0_bm  (1<<6)  /* Window Mode State bit 0 mask. */
#define AC_WSTATE0_bp  6  /* Window Mode State bit 0 position. */
#define AC_WSTATE1_bm  (1<<7)  /* Window Mode State bit 1 mask. */
#define AC_WSTATE1_bp  7  /* Window Mode State bit 1 position. */

#define AC_AC1STATE_bm  0x20  /* Analog Comparator 1 State bit mask. */
#define AC_AC1STATE_bp  5  /* Analog Comparator 1 State bit position. */

#define AC_AC0STATE_bm  0x10  /* Analog Comparator 0 State bit mask. */
#define AC_AC0STATE_bp  4  /* Analog Comparator 0 State bit position. */

#define AC_WIF_bm  0x04  /* Window Mode Interrupt Flag bit mask. */
#define AC_WIF_bp  2  /* Window Mode Interrupt Flag bit position. */

#define AC_AC1IF_bm  0x02  /* Analog Comparator 1 Interrupt Flag bit mask. */
#define AC_AC1IF_bp  1  /* Analog Comparator 1 Interrupt Flag bit position. */

#define AC_AC0IF_bm  0x01  /* Analog Comparator 0 Interrupt Flag bit mask. */
#define AC_AC0IF_bp  0  /* Analog Comparator 0 Interrupt Flag bit position. */

/* AC.CURRCTRL  bit masks and bit positions */
#define AC_CURREN_bm  0x80  /* Current Source Enable bit mask. */
#define AC_CURREN_bp  7  /* Current Source Enable bit position. */

#define AC_CURRMODE_bm  0x40  /* Current Mode bit mask. */
#define AC_CURRMODE_bp  6  /* Current Mode bit position. */

#define AC_AC1CURR_bm  0x02  /* Analog Comparator 1 current source output bit mask. */
#define AC_AC1CURR_bp  1  /* Analog Comparator 1 current source output bit position. */

#define AC_AC0CURR_bm  0x01  /* Analog Comparator 0 current source output bit mask. */
#define AC_AC0CURR_bp  0  /* Analog Comparator 0 current source output bit position. */

/* AC.CURRCALIB  bit masks and bit positions */
#define AC_CALIB_gm  0x0F  /* Current Source Calibration group mask. */
#define AC_CALIB_gp  0  /* Current Source Calibration group position. */
#define AC_CALIB0_bm  (1<<0)  /* Current Source Calibration bit 0 mask. */
#define AC_CALIB0_bp  0  /* Current Source Calibration bit 0 position. */
#define AC_CALIB1_bm  (1<<1)  /* Current Source Calibration bit 1 mask. */
#define AC_CALIB1_bp  1  /* Current Source Calibration bit 1 position. */
#define AC_CALIB2_bm  (1<<2)  /* Current Source Calibration bit 2 mask. */
#define AC_CALIB2_bp  2  /* Current Source Calibration bit 2 position. */
#define AC_CALIB3_bm  (1<<3)  /* Current Source Calibration bit 3 mask. */
#define AC_CALIB3_bp  3  /* Current Source Calibration bit 3 position. */

/* RTC - Real-Time Clounter */
/* RTC.CTRL  bit masks and bit positions */
#define RTC_CORREN_bm  0x08  /* Correction Enable bit mask. */
#define RTC_CORREN_bp  3  /* Correction Enable bit position. */

#define RTC_PRESCALER_gm  0x07  /* Prescaling Factor group mask. */
#define RTC_PRESCALER_gp  0  /* Prescaling Factor group position. */
#define RTC_PRESCALER0_bm  (1<<0)  /* Prescaling Factor bit 0 mask. */
#define RTC_PRESCALER0_bp  0  /* Prescaling Factor bit 0 position. */
#define RTC_PRESCALER1_bm  (1<<1)  /* Prescaling Factor bit 1 mask. */
#define RTC_PRESCALER1_bp  1  /* Prescaling Factor bit 1 position. */
#define RTC_PRESCALER2_bm  (1<<2)  /* Prescaling Factor bit 2 mask. */
#define RTC_PRESCALER2_bp  2  /* Prescaling Factor bit 2 position. */

/* RTC.STATUS  bit masks and bit positions */
#define RTC_SYNCBUSY_bm  0x01  /* Synchronization Busy Flag bit mask. */
#define RTC_SYNCBUSY_bp  0  /* Synchronization Busy Flag bit position. */

/* RTC.INTCTRL  bit masks and bit positions */
#define RTC_COMPINTLVL_gm  0x0C  /* Compare Match Interrupt Level group mask. */
#define RTC_COMPINTLVL_gp  2  /* Compare Match Interrupt Level group position. */
#define RTC_COMPINTLVL0_bm  (1<<2)  /* Compare Match Interrupt Level bit 0 mask. */
#define RTC_COMPINTLVL0_bp  2  /* Compare Match Interrupt Level bit 0 position. */
#define RTC_COMPINTLVL1_bm  (1<<3)  /* Compare Match Interrupt Level bit 1 mask. */
#define RTC_COMPINTLVL1_bp  3  /* Compare Match Interrupt Level bit 1 position. */

#define RTC_OVFINTLVL_gm  0x03  /* Overflow Interrupt Level group mask. */
#define RTC_OVFINTLVL_gp  0  /* Overflow Interrupt Level group position. */
#define RTC_OVFINTLVL0_bm  (1<<0)  /* Overflow Interrupt Level bit 0 mask. */
#define RTC_OVFINTLVL0_bp  0  /* Overflow Interrupt Level bit 0 position. */
#define RTC_OVFINTLVL1_bm  (1<<1)  /* Overflow Interrupt Level bit 1 mask. */
#define RTC_OVFINTLVL1_bp  1  /* Overflow Interrupt Level bit 1 position. */

/* RTC.INTFLAGS  bit masks and bit positions */
#define RTC_COMPIF_bm  0x02  /* Compare Match Interrupt Flag bit mask. */
#define RTC_COMPIF_bp  1  /* Compare Match Interrupt Flag bit position. */

#define RTC_OVFIF_bm  0x01  /* Overflow Interrupt Flag bit mask. */
#define RTC_OVFIF_bp  0  /* Overflow Interrupt Flag bit position. */

/* RTC.CALIB  bit masks and bit positions */
#define RTC_SIGN_bm  0x80  /* Correction Sign bit mask. */
#define RTC_SIGN_bp  7  /* Correction Sign bit position. */

#define RTC_ERROR_gm  0x7F  /* Error Value group mask. */
#define RTC_ERROR_gp  0  /* Error Value group position. */
#define RTC_ERROR0_bm  (1<<0)  /* Error Value bit 0 mask. */
#define RTC_ERROR0_bp  0  /* Error Value bit 0 position. */
#define RTC_ERROR1_bm  (1<<1)  /* Error Value bit 1 mask. */
#define RTC_ERROR1_bp  1  /* Error Value bit 1 position. */
#define RTC_ERROR2_bm  (1<<2)  /* Error Value bit 2 mask. */
#define RTC_ERROR2_bp  2  /* Error Value bit 2 position. */
#define RTC_ERROR3_bm  (1<<3)  /* Error Value bit 3 mask. */
#define RTC_ERROR3_bp  3  /* Error Value bit 3 position. */
#define RTC_ERROR4_bm  (1<<4)  /* Error Value bit 4 mask. */
#define RTC_ERROR4_bp  4  /* Error Value bit 4 position. */
#define RTC_ERROR5_bm  (1<<5)  /* Error Value bit 5 mask. */
#define RTC_ERROR5_bp  5  /* Error Value bit 5 position. */
#define RTC_ERROR6_bm  (1<<6)  /* Error Value bit 6 mask. */
#define RTC_ERROR6_bp  6  /* Error Value bit 6 position. */

/* XCL - XMEGA Custom Logic */
/* XCL.CTRLA  bit masks and bit positions */
#define XCL_LUT0OUTEN_gm  0xC0  /* LUT0 Output Enable group mask. */
#define XCL_LUT0OUTEN_gp  6  /* LUT0 Output Enable group position. */
#define XCL_LUT0OUTEN0_bm  (1<<6)  /* LUT0 Output Enable bit 0 mask. */
#define XCL_LUT0OUTEN0_bp  6  /* LUT0 Output Enable bit 0 position. */
#define XCL_LUT0OUTEN1_bm  (1<<7)  /* LUT0 Output Enable bit 1 mask. */
#define XCL_LUT0OUTEN1_bp  7  /* LUT0 Output Enable bit 1 position. */

#define XCL_PORTSEL_gm  0x30  /* Port Selection group mask. */
#define XCL_PORTSEL_gp  4  /* Port Selection group position. */
#define XCL_PORTSEL0_bm  (1<<4)  /* Port Selection bit 0 mask. */
#define XCL_PORTSEL0_bp  4  /* Port Selection bit 0 position. */
#define XCL_PORTSEL1_bm  (1<<5)  /* Port Selection bit 1 mask. */
#define XCL_PORTSEL1_bp  5  /* Port Selection bit 1 position. */

#define XCL_LUTCONF_gm  0x07  /* LUT Configuration group mask. */
#define XCL_LUTCONF_gp  0  /* LUT Configuration group position. */
#define XCL_LUTCONF0_bm  (1<<0)  /* LUT Configuration bit 0 mask. */
#define XCL_LUTCONF0_bp  0  /* LUT Configuration bit 0 position. */
#define XCL_LUTCONF1_bm  (1<<1)  /* LUT Configuration bit 1 mask. */
#define XCL_LUTCONF1_bp  1  /* LUT Configuration bit 1 position. */
#define XCL_LUTCONF2_bm  (1<<2)  /* LUT Configuration bit 2 mask. */
#define XCL_LUTCONF2_bp  2  /* LUT Configuration bit 2 position. */

/* XCL.CTRLB  bit masks and bit positions */
#define XCL_IN3SEL_gm  0xC0  /* Input Selection 3 group mask. */
#define XCL_IN3SEL_gp  6  /* Input Selection 3 group position. */
#define XCL_IN3SEL0_bm  (1<<6)  /* Input Selection 3 bit 0 mask. */
#define XCL_IN3SEL0_bp  6  /* Input Selection 3 bit 0 position. */
#define XCL_IN3SEL1_bm  (1<<7)  /* Input Selection 3 bit 1 mask. */
#define XCL_IN3SEL1_bp  7  /* Input Selection 3 bit 1 position. */

#define XCL_IN2SEL_gm  0x30  /* Input Selection 2 group mask. */
#define XCL_IN2SEL_gp  4  /* Input Selection 2 group position. */
#define XCL_IN2SEL0_bm  (1<<4)  /* Input Selection 2 bit 0 mask. */
#define XCL_IN2SEL0_bp  4  /* Input Selection 2 bit 0 position. */
#define XCL_IN2SEL1_bm  (1<<5)  /* Input Selection 2 bit 1 mask. */
#define XCL_IN2SEL1_bp  5  /* Input Selection 2 bit 1 position. */

#define XCL_IN1SEL_gm  0x0C  /* Input Selection 1 group mask. */
#define XCL_IN1SEL_gp  2  /* Input Selection 1 group position. */
#define XCL_IN1SEL0_bm  (1<<2)  /* Input Selection 1 bit 0 mask. */
#define XCL_IN1SEL0_bp  2  /* Input Selection 1 bit 0 position. */
#define XCL_IN1SEL1_bm  (1<<3)  /* Input Selection 1 bit 1 mask. */
#define XCL_IN1SEL1_bp  3  /* Input Selection 1 bit 1 position. */

#define XCL_IN0SEL_gm  0x03  /* Input Selection 0 group mask. */
#define XCL_IN0SEL_gp  0  /* Input Selection 0 group position. */
#define XCL_IN0SEL0_bm  (1<<0)  /* Input Selection 0 bit 0 mask. */
#define XCL_IN0SEL0_bp  0  /* Input Selection 0 bit 0 position. */
#define XCL_IN0SEL1_bm  (1<<1)  /* Input Selection 0 bit 1 mask. */
#define XCL_IN0SEL1_bp  1  /* Input Selection 0 bit 1 position. */

/* XCL.CTRLC  bit masks and bit positions */
#define XCL_EVASYSEL1_bm  0x80  /* Asynchronous Event Line Selection for LUT1 bit mask. */
#define XCL_EVASYSEL1_bp  7  /* Asynchronous Event Line Selection for LUT1 bit position. */

#define XCL_EVASYSEL0_bm  0x40  /* Asynchronous Event Line Selection for LUT0 bit mask. */
#define XCL_EVASYSEL0_bp  6  /* Asynchronous Event Line Selection for LUT0 bit position. */

#define XCL_DLYSEL_gm  0x30  /* Delay Selection group mask. */
#define XCL_DLYSEL_gp  4  /* Delay Selection group position. */
#define XCL_DLYSEL0_bm  (1<<4)  /* Delay Selection bit 0 mask. */
#define XCL_DLYSEL0_bp  4  /* Delay Selection bit 0 position. */
#define XCL_DLYSEL1_bm  (1<<5)  /* Delay Selection bit 1 mask. */
#define XCL_DLYSEL1_bp  5  /* Delay Selection bit 1 position. */

#define XCL_DLY1CONF_gm  0x0C  /* Delay Configuration on LUT1 group mask. */
#define XCL_DLY1CONF_gp  2  /* Delay Configuration on LUT1 group position. */
#define XCL_DLY1CONF0_bm  (1<<2)  /* Delay Configuration on LUT1 bit 0 mask. */
#define XCL_DLY1CONF0_bp  2  /* Delay Configuration on LUT1 bit 0 position. */
#define XCL_DLY1CONF1_bm  (1<<3)  /* Delay Configuration on LUT1 bit 1 mask. */
#define XCL_DLY1CONF1_bp  3  /* Delay Configuration on LUT1 bit 1 position. */

#define XCL_DLY0CONF_gm  0x03  /* Delay Configuration on LUT0 group mask. */
#define XCL_DLY0CONF_gp  0  /* Delay Configuration on LUT0 group position. */
#define XCL_DLY0CONF0_bm  (1<<0)  /* Delay Configuration on LUT0 bit 0 mask. */
#define XCL_DLY0CONF0_bp  0  /* Delay Configuration on LUT0 bit 0 position. */
#define XCL_DLY0CONF1_bm  (1<<1)  /* Delay Configuration on LUT0 bit 1 mask. */
#define XCL_DLY0CONF1_bp  1  /* Delay Configuration on LUT0 bit 1 position. */

/* XCL.CTRLD  bit masks and bit positions */
#define XCL_TRUTH1_gm  0xF0  /* Truth Table of LUT1 group mask. */
#define XCL_TRUTH1_gp  4  /* Truth Table of LUT1 group position. */
#define XCL_TRUTH10_bm  (1<<4)  /* Truth Table of LUT1 bit 0 mask. */
#define XCL_TRUTH10_bp  4  /* Truth Table of LUT1 bit 0 position. */
#define XCL_TRUTH11_bm  (1<<5)  /* Truth Table of LUT1 bit 1 mask. */
#define XCL_TRUTH11_bp  5  /* Truth Table of LUT1 bit 1 position. */
#define XCL_TRUTH12_bm  (1<<6)  /* Truth Table of LUT1 bit 2 mask. */
#define XCL_TRUTH12_bp  6  /* Truth Table of LUT1 bit 2 position. */
#define XCL_TRUTH13_bm  (1<<7)  /* Truth Table of LUT1 bit 3 mask. */
#define XCL_TRUTH13_bp  7  /* Truth Table of LUT1 bit 3 position. */

#define XCL_TRUTH0_gm  0x0F  /* Truth Table of LUT0 group mask. */
#define XCL_TRUTH0_gp  0  /* Truth Table of LUT0 group position. */
#define XCL_TRUTH00_bm  (1<<0)  /* Truth Table of LUT0 bit 0 mask. */
#define XCL_TRUTH00_bp  0  /* Truth Table of LUT0 bit 0 position. */
#define XCL_TRUTH01_bm  (1<<1)  /* Truth Table of LUT0 bit 1 mask. */
#define XCL_TRUTH01_bp  1  /* Truth Table of LUT0 bit 1 position. */
#define XCL_TRUTH02_bm  (1<<2)  /* Truth Table of LUT0 bit 2 mask. */
#define XCL_TRUTH02_bp  2  /* Truth Table of LUT0 bit 2 position. */
#define XCL_TRUTH03_bm  (1<<3)  /* Truth Table of LUT0 bit 3 mask. */
#define XCL_TRUTH03_bp  3  /* Truth Table of LUT0 bit 3 position. */

/* XCL.CTRLE  bit masks and bit positions */
#define XCL_CMDSEL_bm  0x80  /* Timer/Counter Command Selection bit mask. */
#define XCL_CMDSEL_bp  7  /* Timer/Counter Command Selection bit position. */

#define XCL_TCSEL_gm  0x70  /* Timer/Counter Selection group mask. */
#define XCL_TCSEL_gp  4  /* Timer/Counter Selection group position. */
#define XCL_TCSEL0_bm  (1<<4)  /* Timer/Counter Selection bit 0 mask. */
#define XCL_TCSEL0_bp  4  /* Timer/Counter Selection bit 0 position. */
#define XCL_TCSEL1_bm  (1<<5)  /* Timer/Counter Selection bit 1 mask. */
#define XCL_TCSEL1_bp  5  /* Timer/Counter Selection bit 1 position. */
#define XCL_TCSEL2_bm  (1<<6)  /* Timer/Counter Selection bit 2 mask. */
#define XCL_TCSEL2_bp  6  /* Timer/Counter Selection bit 2 position. */

#define XCL_CLKSEL_gm  0x0F  /* Clock Selection group mask. */
#define XCL_CLKSEL_gp  0  /* Clock Selection group position. */
#define XCL_CLKSEL0_bm  (1<<0)  /* Clock Selection bit 0 mask. */
#define XCL_CLKSEL0_bp  0  /* Clock Selection bit 0 position. */
#define XCL_CLKSEL1_bm  (1<<1)  /* Clock Selection bit 1 mask. */
#define XCL_CLKSEL1_bp  1  /* Clock Selection bit 1 position. */
#define XCL_CLKSEL2_bm  (1<<2)  /* Clock Selection bit 2 mask. */
#define XCL_CLKSEL2_bp  2  /* Clock Selection bit 2 position. */
#define XCL_CLKSEL3_bm  (1<<3)  /* Clock Selection bit 3 mask. */
#define XCL_CLKSEL3_bp  3  /* Clock Selection bit 3 position. */

/* XCL.CTRLF  bit masks and bit positions */
#define XCL_CMDEN_gm  0xC0  /* Command Enable group mask. */
#define XCL_CMDEN_gp  6  /* Command Enable group position. */
#define XCL_CMDEN0_bm  (1<<6)  /* Command Enable bit 0 mask. */
#define XCL_CMDEN0_bp  6  /* Command Enable bit 0 position. */
#define XCL_CMDEN1_bm  (1<<7)  /* Command Enable bit 1 mask. */
#define XCL_CMDEN1_bp  7  /* Command Enable bit 1 position. */

#define XCL_CMP1_bm  0x20  /* Compare Channel 1 Output Value bit mask. */
#define XCL_CMP1_bp  5  /* Compare Channel 1 Output Value bit position. */

#define XCL_CMP0_bm  0x10  /* Compare Channel 0 Output Value bit mask. */
#define XCL_CMP0_bp  4  /* Compare Channel 0 Output Value bit position. */

#define XCL_CCEN1_bm  0x08  /* Compare or Capture Channel 1 Enable bit mask. */
#define XCL_CCEN1_bp  3  /* Compare or Capture Channel 1 Enable bit position. */

#define XCL_CCEN0_bm  0x04  /* Compare or Capture Channel 0 Enable bit mask. */
#define XCL_CCEN0_bp  2  /* Compare or Capture Channel 0 Enable bit position. */

#define XCL_MODE_gm  0x03  /* Timer/Counter Mode group mask. */
#define XCL_MODE_gp  0  /* Timer/Counter Mode group position. */
#define XCL_MODE0_bm  (1<<0)  /* Timer/Counter Mode bit 0 mask. */
#define XCL_MODE0_bp  0  /* Timer/Counter Mode bit 0 position. */
#define XCL_MODE1_bm  (1<<1)  /* Timer/Counter Mode bit 1 mask. */
#define XCL_MODE1_bp  1  /* Timer/Counter Mode bit 1 position. */

/* XCL.CTRLG  bit masks and bit positions */
#define XCL_EVACTEN_bm  0x80  /* Event Action Enable bit mask. */
#define XCL_EVACTEN_bp  7  /* Event Action Enable bit position. */

#define XCL_EVACT1_gm  0x60  /* Event Action Selection on Timer/Counter 1 group mask. */
#define XCL_EVACT1_gp  5  /* Event Action Selection on Timer/Counter 1 group position. */
#define XCL_EVACT10_bm  (1<<5)  /* Event Action Selection on Timer/Counter 1 bit 0 mask. */
#define XCL_EVACT10_bp  5  /* Event Action Selection on Timer/Counter 1 bit 0 position. */
#define XCL_EVACT11_bm  (1<<6)  /* Event Action Selection on Timer/Counter 1 bit 1 mask. */
#define XCL_EVACT11_bp  6  /* Event Action Selection on Timer/Counter 1 bit 1 position. */

#define XCL_EVACT0_gm  0x18  /* Event Action Selection on Timer/Counter 0 group mask. */
#define XCL_EVACT0_gp  3  /* Event Action Selection on Timer/Counter 0 group position. */
#define XCL_EVACT00_bm  (1<<3)  /* Event Action Selection on Timer/Counter 0 bit 0 mask. */
#define XCL_EVACT00_bp  3  /* Event Action Selection on Timer/Counter 0 bit 0 position. */
#define XCL_EVACT01_bm  (1<<4)  /* Event Action Selection on Timer/Counter 0 bit 1 mask. */
#define XCL_EVACT01_bp  4  /* Event Action Selection on Timer/Counter 0 bit 1 position. */

#define XCL_EVSRC_gm  0x07  /* Event Source Selection group mask. */
#define XCL_EVSRC_gp  0  /* Event Source Selection group position. */
#define XCL_EVSRC0_bm  (1<<0)  /* Event Source Selection bit 0 mask. */
#define XCL_EVSRC0_bp  0  /* Event Source Selection bit 0 position. */
#define XCL_EVSRC1_bm  (1<<1)  /* Event Source Selection bit 1 mask. */
#define XCL_EVSRC1_bp  1  /* Event Source Selection bit 1 position. */
#define XCL_EVSRC2_bm  (1<<2)  /* Event Source Selection bit 2 mask. */
#define XCL_EVSRC2_bp  2  /* Event Source Selection bit 2 position. */

/* XCL.INTCTRL  bit masks and bit positions */
#define XCL_UNF1IE_bm  0x80  /* Underflow 1 Interrupt Enable bit mask. */
#define XCL_UNF1IE_bp  7  /* Underflow 1 Interrupt Enable bit position. */

#define XCL_PEC1IE_bm  0x80  /* Peripheral Counter 1 Interrupt Enable bit mask. */
#define XCL_PEC1IE_bp  7  /* Peripheral Counter 1 Interrupt Enable bit position. */

#define XCL_PEC21IE_bm  0x80  /* Peripheral High Counter 2 Interrupt Enable bit mask. */
#define XCL_PEC21IE_bp  7  /* Peripheral High Counter 2 Interrupt Enable bit position. */

#define XCL_UNF0IE_bm  0x40  /* Underflow 0 Interrupt Enable bit mask. */
#define XCL_UNF0IE_bp  6  /* Underflow 0 Interrupt Enable bit position. */

#define XCL_PEC0IE_bm  0x40  /* Peripheral Counter 0 Interrupt Enable bit mask. */
#define XCL_PEC0IE_bp  6  /* Peripheral Counter 0 Interrupt Enable bit position. */

#define XCL_CC1IE_bm  0x20  /* Compare Or Capture 1 Interrupt Enable bit mask. */
#define XCL_CC1IE_bp  5  /* Compare Or Capture 1 Interrupt Enable bit position. */

#define XCL_PEC20IE_bm  0x20  /* Peripheral Low Counter 2 Interrupt Enable bit mask. */
#define XCL_PEC20IE_bp  5  /* Peripheral Low Counter 2 Interrupt Enable bit position. */

#define XCL_CC0IE_bm  0x10  /* Compare Or Capture 0 Interrupt Enable bit mask. */
#define XCL_CC0IE_bp  4  /* Compare Or Capture 0 Interrupt Enable bit position. */

#define XCL_UNFINTLVL_gm  0x0C  /* Timer Underflow Interrupt Level group mask. */
#define XCL_UNFINTLVL_gp  2  /* Timer Underflow Interrupt Level group position. */
#define XCL_UNFINTLVL0_bm  (1<<2)  /* Timer Underflow Interrupt Level bit 0 mask. */
#define XCL_UNFINTLVL0_bp  2  /* Timer Underflow Interrupt Level bit 0 position. */
#define XCL_UNFINTLVL1_bm  (1<<3)  /* Timer Underflow Interrupt Level bit 1 mask. */
#define XCL_UNFINTLVL1_bp  3  /* Timer Underflow Interrupt Level bit 1 position. */

#define XCL_CCINTLVL_gm  0x03  /* Timer Compare or Capture Interrupt Level group mask. */
#define XCL_CCINTLVL_gp  0  /* Timer Compare or Capture Interrupt Level group position. */
#define XCL_CCINTLVL0_bm  (1<<0)  /* Timer Compare or Capture Interrupt Level bit 0 mask. */
#define XCL_CCINTLVL0_bp  0  /* Timer Compare or Capture Interrupt Level bit 0 position. */
#define XCL_CCINTLVL1_bm  (1<<1)  /* Timer Compare or Capture Interrupt Level bit 1 mask. */
#define XCL_CCINTLVL1_bp  1  /* Timer Compare or Capture Interrupt Level bit 1 position. */

/* XCL.INTFLAGS  bit masks and bit positions */
#define XCL_UNF1IF_bm  0x80  /* Timer/Counter 1 Underflow Interrupt Flag bit mask. */
#define XCL_UNF1IF_bp  7  /* Timer/Counter 1 Underflow Interrupt Flag bit position. */

#define XCL_PEC1IF_bm  0x80  /* Peripheral Counter 1 Interrupt Flag bit mask. */
#define XCL_PEC1IF_bp  7  /* Peripheral Counter 1 Interrupt Flag bit position. */

#define XCL_PEC21IF_bm  0x80  /* Peripheral High Counter 2 Interrupt Flag bit mask. */
#define XCL_PEC21IF_bp  7  /* Peripheral High Counter 2 Interrupt Flag bit position. */

#define XCL_UNF0IF_bm  0x40  /* Timer/Counter 0 Underflow Interrupt Flag bit mask. */
#define XCL_UNF0IF_bp  6  /* Timer/Counter 0 Underflow Interrupt Flag bit position. */

#define XCL_PEC0IF_bm  0x40  /* Peripheral Counter 0 Interrupt Flag bit mask. */
#define XCL_PEC0IF_bp  6  /* Peripheral Counter 0 Interrupt Flag bit position. */

#define XCL_CC1IF_bm  0x20  /* Compare or Capture Channel 1 Interrupt Flag bit mask. */
#define XCL_CC1IF_bp  5  /* Compare or Capture Channel 1 Interrupt Flag bit position. */

#define XCL_PEC20IF_bm  0x20  /* Peripheral Low Counter 2 Interrupt Flag bit mask. */
#define XCL_PEC20IF_bp  5  /* Peripheral Low Counter 2 Interrupt Flag bit position. */

#define XCL_CC0IF_bm  0x10  /* Compare or Capture Channel 0 Interrupt Flag bit mask. */
#define XCL_CC0IF_bp  4  /* Compare or Capture Channel 0 Interrupt Flag bit position. */

/* XCL.PLC  bit masks and bit positions */
#define XCL_PLC_gm  0xFF  /* Peripheral Lenght Control Bits group mask. */
#define XCL_PLC_gp  0  /* Peripheral Lenght Control Bits group position. */
#define XCL_PLC0_bm  (1<<0)  /* Peripheral Lenght Control Bits bit 0 mask. */
#define XCL_PLC0_bp  0  /* Peripheral Lenght Control Bits bit 0 position. */
#define XCL_PLC1_bm  (1<<1)  /* Peripheral Lenght Control Bits bit 1 mask. */
#define XCL_PLC1_bp  1  /* Peripheral Lenght Control Bits bit 1 position. */
#define XCL_PLC2_bm  (1<<2)  /* Peripheral Lenght Control Bits bit 2 mask. */
#define XCL_PLC2_bp  2  /* Peripheral Lenght Control Bits bit 2 position. */
#define XCL_PLC3_bm  (1<<3)  /* Peripheral Lenght Control Bits bit 3 mask. */
#define XCL_PLC3_bp  3  /* Peripheral Lenght Control Bits bit 3 position. */
#define XCL_PLC4_bm  (1<<4)  /* Peripheral Lenght Control Bits bit 4 mask. */
#define XCL_PLC4_bp  4  /* Peripheral Lenght Control Bits bit 4 position. */
#define XCL_PLC5_bm  (1<<5)  /* Peripheral Lenght Control Bits bit 5 mask. */
#define XCL_PLC5_bp  5  /* Peripheral Lenght Control Bits bit 5 position. */
#define XCL_PLC6_bm  (1<<6)  /* Peripheral Lenght Control Bits bit 6 mask. */
#define XCL_PLC6_bp  6  /* Peripheral Lenght Control Bits bit 6 position. */
#define XCL_PLC7_bm  (1<<7)  /* Peripheral Lenght Control Bits bit 7 mask. */
#define XCL_PLC7_bp  7  /* Peripheral Lenght Control Bits bit 7 position. */

/* XCL.CNTL  bit masks and bit positions */
#define XCL_BCNTO_gm  0xFF  /* BTC0 Counter Byte group mask. */
#define XCL_BCNTO_gp  0  /* BTC0 Counter Byte group position. */
#define XCL_BCNTO0_bm  (1<<0)  /* BTC0 Counter Byte bit 0 mask. */
#define XCL_BCNTO0_bp  0  /* BTC0 Counter Byte bit 0 position. */
#define XCL_BCNTO1_bm  (1<<1)  /* BTC0 Counter Byte bit 1 mask. */
#define XCL_BCNTO1_bp  1  /* BTC0 Counter Byte bit 1 position. */
#define XCL_BCNTO2_bm  (1<<2)  /* BTC0 Counter Byte bit 2 mask. */
#define XCL_BCNTO2_bp  2  /* BTC0 Counter Byte bit 2 position. */
#define XCL_BCNTO3_bm  (1<<3)  /* BTC0 Counter Byte bit 3 mask. */
#define XCL_BCNTO3_bp  3  /* BTC0 Counter Byte bit 3 position. */
#define XCL_BCNTO4_bm  (1<<4)  /* BTC0 Counter Byte bit 4 mask. */
#define XCL_BCNTO4_bp  4  /* BTC0 Counter Byte bit 4 position. */
#define XCL_BCNTO5_bm  (1<<5)  /* BTC0 Counter Byte bit 5 mask. */
#define XCL_BCNTO5_bp  5  /* BTC0 Counter Byte bit 5 position. */
#define XCL_BCNTO6_bm  (1<<6)  /* BTC0 Counter Byte bit 6 mask. */
#define XCL_BCNTO6_bp  6  /* BTC0 Counter Byte bit 6 position. */
#define XCL_BCNTO7_bm  (1<<7)  /* BTC0 Counter Byte bit 7 mask. */
#define XCL_BCNTO7_bp  7  /* BTC0 Counter Byte bit 7 position. */

#define XCL_CNTL_gm  0xFF  /* TC16 Counter Low Byte group mask. */
#define XCL_CNTL_gp  0  /* TC16 Counter Low Byte group position. */
#define XCL_CNTL0_bm  (1<<0)  /* TC16 Counter Low Byte bit 0 mask. */
#define XCL_CNTL0_bp  0  /* TC16 Counter Low Byte bit 0 position. */
#define XCL_CNTL1_bm  (1<<1)  /* TC16 Counter Low Byte bit 1 mask. */
#define XCL_CNTL1_bp  1  /* TC16 Counter Low Byte bit 1 position. */
#define XCL_CNTL2_bm  (1<<2)  /* TC16 Counter Low Byte bit 2 mask. */
#define XCL_CNTL2_bp  2  /* TC16 Counter Low Byte bit 2 position. */
#define XCL_CNTL3_bm  (1<<3)  /* TC16 Counter Low Byte bit 3 mask. */
#define XCL_CNTL3_bp  3  /* TC16 Counter Low Byte bit 3 position. */
#define XCL_CNTL4_bm  (1<<4)  /* TC16 Counter Low Byte bit 4 mask. */
#define XCL_CNTL4_bp  4  /* TC16 Counter Low Byte bit 4 position. */
#define XCL_CNTL5_bm  (1<<5)  /* TC16 Counter Low Byte bit 5 mask. */
#define XCL_CNTL5_bp  5  /* TC16 Counter Low Byte bit 5 position. */
#define XCL_CNTL6_bm  (1<<6)  /* TC16 Counter Low Byte bit 6 mask. */
#define XCL_CNTL6_bp  6  /* TC16 Counter Low Byte bit 6 position. */
#define XCL_CNTL7_bm  (1<<7)  /* TC16 Counter Low Byte bit 7 mask. */
#define XCL_CNTL7_bp  7  /* TC16 Counter Low Byte bit 7 position. */

#define XCL_PCNTO_gm  0xFF  /* Peripheral Counter 0 Byte group mask. */
#define XCL_PCNTO_gp  0  /* Peripheral Counter 0 Byte group position. */
#define XCL_PCNTO0_bm  (1<<0)  /* Peripheral Counter 0 Byte bit 0 mask. */
#define XCL_PCNTO0_bp  0  /* Peripheral Counter 0 Byte bit 0 position. */
#define XCL_PCNTO1_bm  (1<<1)  /* Peripheral Counter 0 Byte bit 1 mask. */
#define XCL_PCNTO1_bp  1  /* Peripheral Counter 0 Byte bit 1 position. */
#define XCL_PCNTO2_bm  (1<<2)  /* Peripheral Counter 0 Byte bit 2 mask. */
#define XCL_PCNTO2_bp  2  /* Peripheral Counter 0 Byte bit 2 position. */
#define XCL_PCNTO3_bm  (1<<3)  /* Peripheral Counter 0 Byte bit 3 mask. */
#define XCL_PCNTO3_bp  3  /* Peripheral Counter 0 Byte bit 3 position. */
#define XCL_PCNTO4_bm  (1<<4)  /* Peripheral Counter 0 Byte bit 4 mask. */
#define XCL_PCNTO4_bp  4  /* Peripheral Counter 0 Byte bit 4 position. */
#define XCL_PCNTO5_bm  (1<<5)  /* Peripheral Counter 0 Byte bit 5 mask. */
#define XCL_PCNTO5_bp  5  /* Peripheral Counter 0 Byte bit 5 position. */
#define XCL_PCNTO6_bm  (1<<6)  /* Peripheral Counter 0 Byte bit 6 mask. */
#define XCL_PCNTO6_bp  6  /* Peripheral Counter 0 Byte bit 6 position. */
#define XCL_PCNTO7_bm  (1<<7)  /* Peripheral Counter 0 Byte bit 7 mask. */
#define XCL_PCNTO7_bp  7  /* Peripheral Counter 0 Byte bit 7 position. */

/* XCL.CNTH  bit masks and bit positions */
#define XCL_BCNT1_gm  0xFF  /* BTC1 Counter Byte group mask. */
#define XCL_BCNT1_gp  0  /* BTC1 Counter Byte group position. */
#define XCL_BCNT10_bm  (1<<0)  /* BTC1 Counter Byte bit 0 mask. */
#define XCL_BCNT10_bp  0  /* BTC1 Counter Byte bit 0 position. */
#define XCL_BCNT11_bm  (1<<1)  /* BTC1 Counter Byte bit 1 mask. */
#define XCL_BCNT11_bp  1  /* BTC1 Counter Byte bit 1 position. */
#define XCL_BCNT12_bm  (1<<2)  /* BTC1 Counter Byte bit 2 mask. */
#define XCL_BCNT12_bp  2  /* BTC1 Counter Byte bit 2 position. */
#define XCL_BCNT13_bm  (1<<3)  /* BTC1 Counter Byte bit 3 mask. */
#define XCL_BCNT13_bp  3  /* BTC1 Counter Byte bit 3 position. */
#define XCL_BCNT14_bm  (1<<4)  /* BTC1 Counter Byte bit 4 mask. */
#define XCL_BCNT14_bp  4  /* BTC1 Counter Byte bit 4 position. */
#define XCL_BCNT15_bm  (1<<5)  /* BTC1 Counter Byte bit 5 mask. */
#define XCL_BCNT15_bp  5  /* BTC1 Counter Byte bit 5 position. */
#define XCL_BCNT16_bm  (1<<6)  /* BTC1 Counter Byte bit 6 mask. */
#define XCL_BCNT16_bp  6  /* BTC1 Counter Byte bit 6 position. */
#define XCL_BCNT17_bm  (1<<7)  /* BTC1 Counter Byte bit 7 mask. */
#define XCL_BCNT17_bp  7  /* BTC1 Counter Byte bit 7 position. */

#define XCL_CNTH_gm  0xFF  /* TC16 Counter High Byte group mask. */
#define XCL_CNTH_gp  0  /* TC16 Counter High Byte group position. */
#define XCL_CNTH0_bm  (1<<0)  /* TC16 Counter High Byte bit 0 mask. */
#define XCL_CNTH0_bp  0  /* TC16 Counter High Byte bit 0 position. */
#define XCL_CNTH1_bm  (1<<1)  /* TC16 Counter High Byte bit 1 mask. */
#define XCL_CNTH1_bp  1  /* TC16 Counter High Byte bit 1 position. */
#define XCL_CNTH2_bm  (1<<2)  /* TC16 Counter High Byte bit 2 mask. */
#define XCL_CNTH2_bp  2  /* TC16 Counter High Byte bit 2 position. */
#define XCL_CNTH3_bm  (1<<3)  /* TC16 Counter High Byte bit 3 mask. */
#define XCL_CNTH3_bp  3  /* TC16 Counter High Byte bit 3 position. */
#define XCL_CNTH4_bm  (1<<4)  /* TC16 Counter High Byte bit 4 mask. */
#define XCL_CNTH4_bp  4  /* TC16 Counter High Byte bit 4 position. */
#define XCL_CNTH5_bm  (1<<5)  /* TC16 Counter High Byte bit 5 mask. */
#define XCL_CNTH5_bp  5  /* TC16 Counter High Byte bit 5 position. */
#define XCL_CNTH6_bm  (1<<6)  /* TC16 Counter High Byte bit 6 mask. */
#define XCL_CNTH6_bp  6  /* TC16 Counter High Byte bit 6 position. */
#define XCL_CNTH7_bm  (1<<7)  /* TC16 Counter High Byte bit 7 mask. */
#define XCL_CNTH7_bp  7  /* TC16 Counter High Byte bit 7 position. */

#define XCL_PCNT1_gm  0xFF  /* Peripheral Counter 1 Byte group mask. */
#define XCL_PCNT1_gp  0  /* Peripheral Counter 1 Byte group position. */
#define XCL_PCNT10_bm  (1<<0)  /* Peripheral Counter 1 Byte bit 0 mask. */
#define XCL_PCNT10_bp  0  /* Peripheral Counter 1 Byte bit 0 position. */
#define XCL_PCNT11_bm  (1<<1)  /* Peripheral Counter 1 Byte bit 1 mask. */
#define XCL_PCNT11_bp  1  /* Peripheral Counter 1 Byte bit 1 position. */
#define XCL_PCNT12_bm  (1<<2)  /* Peripheral Counter 1 Byte bit 2 mask. */
#define XCL_PCNT12_bp  2  /* Peripheral Counter 1 Byte bit 2 position. */
#define XCL_PCNT13_bm  (1<<3)  /* Peripheral Counter 1 Byte bit 3 mask. */
#define XCL_PCNT13_bp  3  /* Peripheral Counter 1 Byte bit 3 position. */
#define XCL_PCNT14_bm  (1<<4)  /* Peripheral Counter 1 Byte bit 4 mask. */
#define XCL_PCNT14_bp  4  /* Peripheral Counter 1 Byte bit 4 position. */
#define XCL_PCNT15_bm  (1<<5)  /* Peripheral Counter 1 Byte bit 5 mask. */
#define XCL_PCNT15_bp  5  /* Peripheral Counter 1 Byte bit 5 position. */
#define XCL_PCNT16_bm  (1<<6)  /* Peripheral Counter 1 Byte bit 6 mask. */
#define XCL_PCNT16_bp  6  /* Peripheral Counter 1 Byte bit 6 position. */
#define XCL_PCNT17_bm  (1<<7)  /* Peripheral Counter 1 Byte bit 7 mask. */
#define XCL_PCNT17_bp  7  /* Peripheral Counter 1 Byte bit 7 position. */

#define XCL_PCNT21_gm  0xF0  /* Peripheral High Counter 2 Bits group mask. */
#define XCL_PCNT21_gp  4  /* Peripheral High Counter 2 Bits group position. */
#define XCL_PCNT210_bm  (1<<4)  /* Peripheral High Counter 2 Bits bit 0 mask. */
#define XCL_PCNT210_bp  4  /* Peripheral High Counter 2 Bits bit 0 position. */
#define XCL_PCNT211_bm  (1<<5)  /* Peripheral High Counter 2 Bits bit 1 mask. */
#define XCL_PCNT211_bp  5  /* Peripheral High Counter 2 Bits bit 1 position. */
#define XCL_PCNT212_bm  (1<<6)  /* Peripheral High Counter 2 Bits bit 2 mask. */
#define XCL_PCNT212_bp  6  /* Peripheral High Counter 2 Bits bit 2 position. */
#define XCL_PCNT213_bm  (1<<7)  /* Peripheral High Counter 2 Bits bit 3 mask. */
#define XCL_PCNT213_bp  7  /* Peripheral High Counter 2 Bits bit 3 position. */

#define XCL_PCNT20_gm  0x0F  /* Peripheral Low Counter 2 Bits group mask. */
#define XCL_PCNT20_gp  0  /* Peripheral Low Counter 2 Bits group position. */
#define XCL_PCNT200_bm  (1<<0)  /* Peripheral Low Counter 2 Bits bit 0 mask. */
#define XCL_PCNT200_bp  0  /* Peripheral Low Counter 2 Bits bit 0 position. */
#define XCL_PCNT201_bm  (1<<1)  /* Peripheral Low Counter 2 Bits bit 1 mask. */
#define XCL_PCNT201_bp  1  /* Peripheral Low Counter 2 Bits bit 1 position. */
#define XCL_PCNT202_bm  (1<<2)  /* Peripheral Low Counter 2 Bits bit 2 mask. */
#define XCL_PCNT202_bp  2  /* Peripheral Low Counter 2 Bits bit 2 position. */
#define XCL_PCNT203_bm  (1<<3)  /* Peripheral Low Counter 2 Bits bit 3 mask. */
#define XCL_PCNT203_bp  3  /* Peripheral Low Counter 2 Bits bit 3 position. */

/* XCL.CMPL  bit masks and bit positions */
#define XCL_CMPL_gm  0xFF  /* TC16 Compare Low Byte group mask. */
#define XCL_CMPL_gp  0  /* TC16 Compare Low Byte group position. */
#define XCL_CMPL0_bm  (1<<0)  /* TC16 Compare Low Byte bit 0 mask. */
#define XCL_CMPL0_bp  0  /* TC16 Compare Low Byte bit 0 position. */
#define XCL_CMPL1_bm  (1<<1)  /* TC16 Compare Low Byte bit 1 mask. */
#define XCL_CMPL1_bp  1  /* TC16 Compare Low Byte bit 1 position. */
#define XCL_CMPL2_bm  (1<<2)  /* TC16 Compare Low Byte bit 2 mask. */
#define XCL_CMPL2_bp  2  /* TC16 Compare Low Byte bit 2 position. */
#define XCL_CMPL3_bm  (1<<3)  /* TC16 Compare Low Byte bit 3 mask. */
#define XCL_CMPL3_bp  3  /* TC16 Compare Low Byte bit 3 position. */
#define XCL_CMPL4_bm  (1<<4)  /* TC16 Compare Low Byte bit 4 mask. */
#define XCL_CMPL4_bp  4  /* TC16 Compare Low Byte bit 4 position. */
#define XCL_CMPL5_bm  (1<<5)  /* TC16 Compare Low Byte bit 5 mask. */
#define XCL_CMPL5_bp  5  /* TC16 Compare Low Byte bit 5 position. */
#define XCL_CMPL6_bm  (1<<6)  /* TC16 Compare Low Byte bit 6 mask. */
#define XCL_CMPL6_bp  6  /* TC16 Compare Low Byte bit 6 position. */
#define XCL_CMPL7_bm  (1<<7)  /* TC16 Compare Low Byte bit 7 mask. */
#define XCL_CMPL7_bp  7  /* TC16 Compare Low Byte bit 7 position. */

#define XCL_BCMP0_gm  0xFF  /* BTC0 Compare Byte group mask. */
#define XCL_BCMP0_gp  0  /* BTC0 Compare Byte group position. */
#define XCL_BCMP00_bm  (1<<0)  /* BTC0 Compare Byte bit 0 mask. */
#define XCL_BCMP00_bp  0  /* BTC0 Compare Byte bit 0 position. */
#define XCL_BCMP01_bm  (1<<1)  /* BTC0 Compare Byte bit 1 mask. */
#define XCL_BCMP01_bp  1  /* BTC0 Compare Byte bit 1 position. */
#define XCL_BCMP02_bm  (1<<2)  /* BTC0 Compare Byte bit 2 mask. */
#define XCL_BCMP02_bp  2  /* BTC0 Compare Byte bit 2 position. */
#define XCL_BCMP03_bm  (1<<3)  /* BTC0 Compare Byte bit 3 mask. */
#define XCL_BCMP03_bp  3  /* BTC0 Compare Byte bit 3 position. */
#define XCL_BCMP04_bm  (1<<4)  /* BTC0 Compare Byte bit 4 mask. */
#define XCL_BCMP04_bp  4  /* BTC0 Compare Byte bit 4 position. */
#define XCL_BCMP05_bm  (1<<5)  /* BTC0 Compare Byte bit 5 mask. */
#define XCL_BCMP05_bp  5  /* BTC0 Compare Byte bit 5 position. */
#define XCL_BCMP06_bm  (1<<6)  /* BTC0 Compare Byte bit 6 mask. */
#define XCL_BCMP06_bp  6  /* BTC0 Compare Byte bit 6 position. */
#define XCL_BCMP07_bm  (1<<7)  /* BTC0 Compare Byte bit 7 mask. */
#define XCL_BCMP07_bp  7  /* BTC0 Compare Byte bit 7 position. */

/* XCL.CMPH  bit masks and bit positions */
#define XCL_CMPH_gm  0xFF  /* TC16 Compare High Byte group mask. */
#define XCL_CMPH_gp  0  /* TC16 Compare High Byte group position. */
#define XCL_CMPH0_bm  (1<<0)  /* TC16 Compare High Byte bit 0 mask. */
#define XCL_CMPH0_bp  0  /* TC16 Compare High Byte bit 0 position. */
#define XCL_CMPH1_bm  (1<<1)  /* TC16 Compare High Byte bit 1 mask. */
#define XCL_CMPH1_bp  1  /* TC16 Compare High Byte bit 1 position. */
#define XCL_CMPH2_bm  (1<<2)  /* TC16 Compare High Byte bit 2 mask. */
#define XCL_CMPH2_bp  2  /* TC16 Compare High Byte bit 2 position. */
#define XCL_CMPH3_bm  (1<<3)  /* TC16 Compare High Byte bit 3 mask. */
#define XCL_CMPH3_bp  3  /* TC16 Compare High Byte bit 3 position. */
#define XCL_CMPH4_bm  (1<<4)  /* TC16 Compare High Byte bit 4 mask. */
#define XCL_CMPH4_bp  4  /* TC16 Compare High Byte bit 4 position. */
#define XCL_CMPH5_bm  (1<<5)  /* TC16 Compare High Byte bit 5 mask. */
#define XCL_CMPH5_bp  5  /* TC16 Compare High Byte bit 5 position. */
#define XCL_CMPH6_bm  (1<<6)  /* TC16 Compare High Byte bit 6 mask. */
#define XCL_CMPH6_bp  6  /* TC16 Compare High Byte bit 6 position. */
#define XCL_CMPH7_bm  (1<<7)  /* TC16 Compare High Byte bit 7 mask. */
#define XCL_CMPH7_bp  7  /* TC16 Compare High Byte bit 7 position. */

#define XCL_BCMP1_gm  0xFF  /* BTC1 Compare Byte group mask. */
#define XCL_BCMP1_gp  0  /* BTC1 Compare Byte group position. */
#define XCL_BCMP10_bm  (1<<0)  /* BTC1 Compare Byte bit 0 mask. */
#define XCL_BCMP10_bp  0  /* BTC1 Compare Byte bit 0 position. */
#define XCL_BCMP11_bm  (1<<1)  /* BTC1 Compare Byte bit 1 mask. */
#define XCL_BCMP11_bp  1  /* BTC1 Compare Byte bit 1 position. */
#define XCL_BCMP12_bm  (1<<2)  /* BTC1 Compare Byte bit 2 mask. */
#define XCL_BCMP12_bp  2  /* BTC1 Compare Byte bit 2 position. */
#define XCL_BCMP13_bm  (1<<3)  /* BTC1 Compare Byte bit 3 mask. */
#define XCL_BCMP13_bp  3  /* BTC1 Compare Byte bit 3 position. */
#define XCL_BCMP14_bm  (1<<4)  /* BTC1 Compare Byte bit 4 mask. */
#define XCL_BCMP14_bp  4  /* BTC1 Compare Byte bit 4 position. */
#define XCL_BCMP15_bm  (1<<5)  /* BTC1 Compare Byte bit 5 mask. */
#define XCL_BCMP15_bp  5  /* BTC1 Compare Byte bit 5 position. */
#define XCL_BCMP16_bm  (1<<6)  /* BTC1 Compare Byte bit 6 mask. */
#define XCL_BCMP16_bp  6  /* BTC1 Compare Byte bit 6 position. */
#define XCL_BCMP17_bm  (1<<7)  /* BTC1 Compare Byte bit 7 mask. */
#define XCL_BCMP17_bp  7  /* BTC1 Compare Byte bit 7 position. */

/* XCL.PERCAPTL  bit masks and bit positions */
#define XCL_PERL_gm  0xFF  /* TC16 Low Byte Period group mask. */
#define XCL_PERL_gp  0  /* TC16 Low Byte Period group position. */
#define XCL_PERL0_bm  (1<<0)  /* TC16 Low Byte Period bit 0 mask. */
#define XCL_PERL0_bp  0  /* TC16 Low Byte Period bit 0 position. */
#define XCL_PERL1_bm  (1<<1)  /* TC16 Low Byte Period bit 1 mask. */
#define XCL_PERL1_bp  1  /* TC16 Low Byte Period bit 1 position. */
#define XCL_PERL2_bm  (1<<2)  /* TC16 Low Byte Period bit 2 mask. */
#define XCL_PERL2_bp  2  /* TC16 Low Byte Period bit 2 position. */
#define XCL_PERL3_bm  (1<<3)  /* TC16 Low Byte Period bit 3 mask. */
#define XCL_PERL3_bp  3  /* TC16 Low Byte Period bit 3 position. */
#define XCL_PERL4_bm  (1<<4)  /* TC16 Low Byte Period bit 4 mask. */
#define XCL_PERL4_bp  4  /* TC16 Low Byte Period bit 4 position. */
#define XCL_PERL5_bm  (1<<5)  /* TC16 Low Byte Period bit 5 mask. */
#define XCL_PERL5_bp  5  /* TC16 Low Byte Period bit 5 position. */
#define XCL_PERL6_bm  (1<<6)  /* TC16 Low Byte Period bit 6 mask. */
#define XCL_PERL6_bp  6  /* TC16 Low Byte Period bit 6 position. */
#define XCL_PERL7_bm  (1<<7)  /* TC16 Low Byte Period bit 7 mask. */
#define XCL_PERL7_bp  7  /* TC16 Low Byte Period bit 7 position. */

#define XCL_CAPTL_gm  0xFF  /* TC16 Capture Value Low Byte group mask. */
#define XCL_CAPTL_gp  0  /* TC16 Capture Value Low Byte group position. */
#define XCL_CAPTL0_bm  (1<<0)  /* TC16 Capture Value Low Byte bit 0 mask. */
#define XCL_CAPTL0_bp  0  /* TC16 Capture Value Low Byte bit 0 position. */
#define XCL_CAPTL1_bm  (1<<1)  /* TC16 Capture Value Low Byte bit 1 mask. */
#define XCL_CAPTL1_bp  1  /* TC16 Capture Value Low Byte bit 1 position. */
#define XCL_CAPTL2_bm  (1<<2)  /* TC16 Capture Value Low Byte bit 2 mask. */
#define XCL_CAPTL2_bp  2  /* TC16 Capture Value Low Byte bit 2 position. */
#define XCL_CAPTL3_bm  (1<<3)  /* TC16 Capture Value Low Byte bit 3 mask. */
#define XCL_CAPTL3_bp  3  /* TC16 Capture Value Low Byte bit 3 position. */
#define XCL_CAPTL4_bm  (1<<4)  /* TC16 Capture Value Low Byte bit 4 mask. */
#define XCL_CAPTL4_bp  4  /* TC16 Capture Value Low Byte bit 4 position. */
#define XCL_CAPTL5_bm  (1<<5)  /* TC16 Capture Value Low Byte bit 5 mask. */
#define XCL_CAPTL5_bp  5  /* TC16 Capture Value Low Byte bit 5 position. */
#define XCL_CAPTL6_bm  (1<<6)  /* TC16 Capture Value Low Byte bit 6 mask. */
#define XCL_CAPTL6_bp  6  /* TC16 Capture Value Low Byte bit 6 position. */
#define XCL_CAPTL7_bm  (1<<7)  /* TC16 Capture Value Low Byte bit 7 mask. */
#define XCL_CAPTL7_bp  7  /* TC16 Capture Value Low Byte bit 7 position. */

#define XCL_BPER0_gm  0xFF  /* BTC0 Period group mask. */
#define XCL_BPER0_gp  0  /* BTC0 Period group position. */
#define XCL_BPER00_bm  (1<<0)  /* BTC0 Period bit 0 mask. */
#define XCL_BPER00_bp  0  /* BTC0 Period bit 0 position. */
#define XCL_BPER01_bm  (1<<1)  /* BTC0 Period bit 1 mask. */
#define XCL_BPER01_bp  1  /* BTC0 Period bit 1 position. */
#define XCL_BPER02_bm  (1<<2)  /* BTC0 Period bit 2 mask. */
#define XCL_BPER02_bp  2  /* BTC0 Period bit 2 position. */
#define XCL_BPER03_bm  (1<<3)  /* BTC0 Period bit 3 mask. */
#define XCL_BPER03_bp  3  /* BTC0 Period bit 3 position. */
#define XCL_BPER04_bm  (1<<4)  /* BTC0 Period bit 4 mask. */
#define XCL_BPER04_bp  4  /* BTC0 Period bit 4 position. */
#define XCL_BPER05_bm  (1<<5)  /* BTC0 Period bit 5 mask. */
#define XCL_BPER05_bp  5  /* BTC0 Period bit 5 position. */
#define XCL_BPER06_bm  (1<<6)  /* BTC0 Period bit 6 mask. */
#define XCL_BPER06_bp  6  /* BTC0 Period bit 6 position. */
#define XCL_BPER07_bm  (1<<7)  /* BTC0 Period bit 7 mask. */
#define XCL_BPER07_bp  7  /* BTC0 Period bit 7 position. */

#define XCL_BCAPT0_gm  0xFF  /* BTC0 Capture Value Byte group mask. */
#define XCL_BCAPT0_gp  0  /* BTC0 Capture Value Byte group position. */
#define XCL_BCAPT00_bm  (1<<0)  /* BTC0 Capture Value Byte bit 0 mask. */
#define XCL_BCAPT00_bp  0  /* BTC0 Capture Value Byte bit 0 position. */
#define XCL_BCAPT01_bm  (1<<1)  /* BTC0 Capture Value Byte bit 1 mask. */
#define XCL_BCAPT01_bp  1  /* BTC0 Capture Value Byte bit 1 position. */
#define XCL_BCAPT02_bm  (1<<2)  /* BTC0 Capture Value Byte bit 2 mask. */
#define XCL_BCAPT02_bp  2  /* BTC0 Capture Value Byte bit 2 position. */
#define XCL_BCAPT03_bm  (1<<3)  /* BTC0 Capture Value Byte bit 3 mask. */
#define XCL_BCAPT03_bp  3  /* BTC0 Capture Value Byte bit 3 position. */
#define XCL_BCAPT04_bm  (1<<4)  /* BTC0 Capture Value Byte bit 4 mask. */
#define XCL_BCAPT04_bp  4  /* BTC0 Capture Value Byte bit 4 position. */
#define XCL_BCAPT05_bm  (1<<5)  /* BTC0 Capture Value Byte bit 5 mask. */
#define XCL_BCAPT05_bp  5  /* BTC0 Capture Value Byte bit 5 position. */
#define XCL_BCAPT06_bm  (1<<6)  /* BTC0 Capture Value Byte bit 6 mask. */
#define XCL_BCAPT06_bp  6  /* BTC0 Capture Value Byte bit 6 position. */
#define XCL_BCAPT07_bm  (1<<7)  /* BTC0 Capture Value Byte bit 7 mask. */
#define XCL_BCAPT07_bp  7  /* BTC0 Capture Value Byte bit 7 position. */

/* XCL.PERCAPTH  bit masks and bit positions */
#define XCL_PERH_gm  0xFF  /* TC16 High Byte Period group mask. */
#define XCL_PERH_gp  0  /* TC16 High Byte Period group position. */
#define XCL_PERH0_bm  (1<<0)  /* TC16 High Byte Period bit 0 mask. */
#define XCL_PERH0_bp  0  /* TC16 High Byte Period bit 0 position. */
#define XCL_PERH1_bm  (1<<1)  /* TC16 High Byte Period bit 1 mask. */
#define XCL_PERH1_bp  1  /* TC16 High Byte Period bit 1 position. */
#define XCL_PERH2_bm  (1<<2)  /* TC16 High Byte Period bit 2 mask. */
#define XCL_PERH2_bp  2  /* TC16 High Byte Period bit 2 position. */
#define XCL_PERH3_bm  (1<<3)  /* TC16 High Byte Period bit 3 mask. */
#define XCL_PERH3_bp  3  /* TC16 High Byte Period bit 3 position. */
#define XCL_PERH4_bm  (1<<4)  /* TC16 High Byte Period bit 4 mask. */
#define XCL_PERH4_bp  4  /* TC16 High Byte Period bit 4 position. */
#define XCL_PERH5_bm  (1<<5)  /* TC16 High Byte Period bit 5 mask. */
#define XCL_PERH5_bp  5  /* TC16 High Byte Period bit 5 position. */
#define XCL_PERH6_bm  (1<<6)  /* TC16 High Byte Period bit 6 mask. */
#define XCL_PERH6_bp  6  /* TC16 High Byte Period bit 6 position. */
#define XCL_PERH7_bm  (1<<7)  /* TC16 High Byte Period bit 7 mask. */
#define XCL_PERH7_bp  7  /* TC16 High Byte Period bit 7 position. */

#define XCL_CAPTH_gm  0xFF  /* TC16 Capture Value High Byte group mask. */
#define XCL_CAPTH_gp  0  /* TC16 Capture Value High Byte group position. */
#define XCL_CAPTH0_bm  (1<<0)  /* TC16 Capture Value High Byte bit 0 mask. */
#define XCL_CAPTH0_bp  0  /* TC16 Capture Value High Byte bit 0 position. */
#define XCL_CAPTH1_bm  (1<<1)  /* TC16 Capture Value High Byte bit 1 mask. */
#define XCL_CAPTH1_bp  1  /* TC16 Capture Value High Byte bit 1 position. */
#define XCL_CAPTH2_bm  (1<<2)  /* TC16 Capture Value High Byte bit 2 mask. */
#define XCL_CAPTH2_bp  2  /* TC16 Capture Value High Byte bit 2 position. */
#define XCL_CAPTH3_bm  (1<<3)  /* TC16 Capture Value High Byte bit 3 mask. */
#define XCL_CAPTH3_bp  3  /* TC16 Capture Value High Byte bit 3 position. */
#define XCL_CAPTH4_bm  (1<<4)  /* TC16 Capture Value High Byte bit 4 mask. */
#define XCL_CAPTH4_bp  4  /* TC16 Capture Value High Byte bit 4 position. */
#define XCL_CAPTH5_bm  (1<<5)  /* TC16 Capture Value High Byte bit 5 mask. */
#define XCL_CAPTH5_bp  5  /* TC16 Capture Value High Byte bit 5 position. */
#define XCL_CAPTH6_bm  (1<<6)  /* TC16 Capture Value High Byte bit 6 mask. */
#define XCL_CAPTH6_bp  6  /* TC16 Capture Value High Byte bit 6 position. */
#define XCL_CAPTH7_bm  (1<<7)  /* TC16 Capture Value High Byte bit 7 mask. */
#define XCL_CAPTH7_bp  7  /* TC16 Capture Value High Byte bit 7 position. */

#define XCL_BPER1_gm  0xFF  /* BTC1 Period group mask. */
#define XCL_BPER1_gp  0  /* BTC1 Period group position. */
#define XCL_BPER10_bm  (1<<0)  /* BTC1 Period bit 0 mask. */
#define XCL_BPER10_bp  0  /* BTC1 Period bit 0 position. */
#define XCL_BPER11_bm  (1<<1)  /* BTC1 Period bit 1 mask. */
#define XCL_BPER11_bp  1  /* BTC1 Period bit 1 position. */
#define XCL_BPER12_bm  (1<<2)  /* BTC1 Period bit 2 mask. */
#define XCL_BPER12_bp  2  /* BTC1 Period bit 2 position. */
#define XCL_BPER13_bm  (1<<3)  /* BTC1 Period bit 3 mask. */
#define XCL_BPER13_bp  3  /* BTC1 Period bit 3 position. */
#define XCL_BPER14_bm  (1<<4)  /* BTC1 Period bit 4 mask. */
#define XCL_BPER14_bp  4  /* BTC1 Period bit 4 position. */
#define XCL_BPER15_bm  (1<<5)  /* BTC1 Period bit 5 mask. */
#define XCL_BPER15_bp  5  /* BTC1 Period bit 5 position. */
#define XCL_BPER16_bm  (1<<6)  /* BTC1 Period bit 6 mask. */
#define XCL_BPER16_bp  6  /* BTC1 Period bit 6 position. */
#define XCL_BPER17_bm  (1<<7)  /* BTC1 Period bit 7 mask. */
#define XCL_BPER17_bp  7  /* BTC1 Period bit 7 position. */

#define XCL_BCAPT1_gm  0xFF  /* BTC1 Capture Value Byte group mask. */
#define XCL_BCAPT1_gp  0  /* BTC1 Capture Value Byte group position. */
#define XCL_BCAPT10_bm  (1<<0)  /* BTC1 Capture Value Byte bit 0 mask. */
#define XCL_BCAPT10_bp  0  /* BTC1 Capture Value Byte bit 0 position. */
#define XCL_BCAPT11_bm  (1<<1)  /* BTC1 Capture Value Byte bit 1 mask. */
#define XCL_BCAPT11_bp  1  /* BTC1 Capture Value Byte bit 1 position. */
#define XCL_BCAPT12_bm  (1<<2)  /* BTC1 Capture Value Byte bit 2 mask. */
#define XCL_BCAPT12_bp  2  /* BTC1 Capture Value Byte bit 2 position. */
#define XCL_BCAPT13_bm  (1<<3)  /* BTC1 Capture Value Byte bit 3 mask. */
#define XCL_BCAPT13_bp  3  /* BTC1 Capture Value Byte bit 3 position. */
#define XCL_BCAPT14_bm  (1<<4)  /* BTC1 Capture Value Byte bit 4 mask. */
#define XCL_BCAPT14_bp  4  /* BTC1 Capture Value Byte bit 4 position. */
#define XCL_BCAPT15_bm  (1<<5)  /* BTC1 Capture Value Byte bit 5 mask. */
#define XCL_BCAPT15_bp  5  /* BTC1 Capture Value Byte bit 5 position. */
#define XCL_BCAPT16_bm  (1<<6)  /* BTC1 Capture Value Byte bit 6 mask. */
#define XCL_BCAPT16_bp  6  /* BTC1 Capture Value Byte bit 6 position. */
#define XCL_BCAPT17_bm  (1<<7)  /* BTC1 Capture Value Byte bit 7 mask. */
#define XCL_BCAPT17_bp  7  /* BTC1 Capture Value Byte bit 7 position. */

/* TWI - Two-Wire Interface */
/* TWI.CTRL  bit masks and bit positions */
#define TWI_BRIDGEEN_bm  0x80  /* Bridge Enable bit mask. */
#define TWI_BRIDGEEN_bp  7  /* Bridge Enable bit position. */

#define TWI_SFMPEN_bm  0x40  /* Slave Fast Mode Plus Enable bit mask. */
#define TWI_SFMPEN_bp  6  /* Slave Fast Mode Plus Enable bit position. */

#define TWI_SSDAHOLD_gm  0x30  /* Slave SDA Hold Time Enable group mask. */
#define TWI_SSDAHOLD_gp  4  /* Slave SDA Hold Time Enable group position. */
#define TWI_SSDAHOLD0_bm  (1<<4)  /* Slave SDA Hold Time Enable bit 0 mask. */
#define TWI_SSDAHOLD0_bp  4  /* Slave SDA Hold Time Enable bit 0 position. */
#define TWI_SSDAHOLD1_bm  (1<<5)  /* Slave SDA Hold Time Enable bit 1 mask. */
#define TWI_SSDAHOLD1_bp  5  /* Slave SDA Hold Time Enable bit 1 position. */

#define TWI_FMPEN_bm  0x08  /* FMPLUS Enable bit mask. */
#define TWI_FMPEN_bp  3  /* FMPLUS Enable bit position. */

#define TWI_SDAHOLD_gm  0x06  /* SDA Hold Time Enable group mask. */
#define TWI_SDAHOLD_gp  1  /* SDA Hold Time Enable group position. */
#define TWI_SDAHOLD0_bm  (1<<1)  /* SDA Hold Time Enable bit 0 mask. */
#define TWI_SDAHOLD0_bp  1  /* SDA Hold Time Enable bit 0 position. */
#define TWI_SDAHOLD1_bm  (1<<2)  /* SDA Hold Time Enable bit 1 mask. */
#define TWI_SDAHOLD1_bp  2  /* SDA Hold Time Enable bit 1 position. */

#define TWI_EDIEN_bm  0x01  /* External Driver Interface Enable bit mask. */
#define TWI_EDIEN_bp  0  /* External Driver Interface Enable bit position. */

/* TWI_MASTER.CTRLA  bit masks and bit positions */
#define TWI_MASTER_INTLVL_gm  0xC0  /* Interrupt Level group mask. */
#define TWI_MASTER_INTLVL_gp  6  /* Interrupt Level group position. */
#define TWI_MASTER_INTLVL0_bm  (1<<6)  /* Interrupt Level bit 0 mask. */
#define TWI_MASTER_INTLVL0_bp  6  /* Interrupt Level bit 0 position. */
#define TWI_MASTER_INTLVL1_bm  (1<<7)  /* Interrupt Level bit 1 mask. */
#define TWI_MASTER_INTLVL1_bp  7  /* Interrupt Level bit 1 position. */

#define TWI_MASTER_RIEN_bm  0x20  /* Read Interrupt Enable bit mask. */
#define TWI_MASTER_RIEN_bp  5  /* Read Interrupt Enable bit position. */

#define TWI_MASTER_WIEN_bm  0x10  /* Write Interrupt Enable bit mask. */
#define TWI_MASTER_WIEN_bp  4  /* Write Interrupt Enable bit position. */

#define TWI_MASTER_ENABLE_bm  0x08  /* Enable TWI Master bit mask. */
#define TWI_MASTER_ENABLE_bp  3  /* Enable TWI Master bit position. */

/* TWI_MASTER.CTRLB  bit masks and bit positions */
#define TWI_MASTER_TIMEOUT_gm  0x0C  /* Inactive Bus Timeout group mask. */
#define TWI_MASTER_TIMEOUT_gp  2  /* Inactive Bus Timeout group position. */
#define TWI_MASTER_TIMEOUT0_bm  (1<<2)  /* Inactive Bus Timeout bit 0 mask. */
#define TWI_MASTER_TIMEOUT0_bp  2  /* Inactive Bus Timeout bit 0 position. */
#define TWI_MASTER_TIMEOUT1_bm  (1<<3)  /* Inactive Bus Timeout bit 1 mask. */
#define TWI_MASTER_TIMEOUT1_bp  3  /* Inactive Bus Timeout bit 1 position. */

#define TWI_MASTER_QCEN_bm  0x02  /* Quick Command Enable bit mask. */
#define TWI_MASTER_QCEN_bp  1  /* Quick Command Enable bit position. */

#define TWI_MASTER_SMEN_bm  0x01  /* Smart Mode Enable bit mask. */
#define TWI_MASTER_SMEN_bp  0  /* Smart Mode Enable bit position. */

#define TWI_MASTER_TTOUTEN_bm  0x10  /* Ttimeout Enable bit mask. */
#define TWI_MASTER_TTOUTEN_bp  4  /* Ttimeout Enable bit position. */

#define TWI_MASTER_TSEXTEN_bm  0x20  /* Slave Extend Timeout Enable bit mask. */
#define TWI_MASTER_TSEXTEN_bp  5  /* Slave Extend Timeout Enable bit position. */

#define TWI_MASTER_TMEXTEN_bm  0x40  /* Master Extend Timeout Enable bit mask. */
#define TWI_MASTER_TMEXTEN_bp  6  /* Master Extend Timeout Enable bit position. */

#define TWI_MASTER_TOIE_bm  0x80  /* Timeout Interrupt Enable bit mask. */
#define TWI_MASTER_TOIE_bp  7  /* Timeout Interrupt Enable bit position. */

/* TWI_MASTER.CTRLC  bit masks and bit positions */
#define TWI_MASTER_ACKACT_bm  0x04  /* Acknowledge Action bit mask. */
#define TWI_MASTER_ACKACT_bp  2  /* Acknowledge Action bit position. */

#define TWI_MASTER_CMD_gm  0x03  /* Command group mask. */
#define TWI_MASTER_CMD_gp  0  /* Command group position. */
#define TWI_MASTER_CMD0_bm  (1<<0)  /* Command bit 0 mask. */
#define TWI_MASTER_CMD0_bp  0  /* Command bit 0 position. */
#define TWI_MASTER_CMD1_bm  (1<<1)  /* Command bit 1 mask. */
#define TWI_MASTER_CMD1_bp  1  /* Command bit 1 position. */

/* TWI_MASTER.STATUS  bit masks and bit positions */
#define TWI_MASTER_RIF_bm  0x80  /* Read Interrupt Flag bit mask. */
#define TWI_MASTER_RIF_bp  7  /* Read Interrupt Flag bit position. */

#define TWI_MASTER_WIF_bm  0x40  /* Write Interrupt Flag bit mask. */
#define TWI_MASTER_WIF_bp  6  /* Write Interrupt Flag bit position. */

#define TWI_MASTER_CLKHOLD_bm  0x20  /* Clock Hold bit mask. */
#define TWI_MASTER_CLKHOLD_bp  5  /* Clock Hold bit position. */

#define TWI_MASTER_RXACK_bm  0x10  /* Received Acknowledge bit mask. */
#define TWI_MASTER_RXACK_bp  4  /* Received Acknowledge bit position. */

#define TWI_MASTER_ARBLOST_bm  0x08  /* Arbitration Lost bit mask. */
#define TWI_MASTER_ARBLOST_bp  3  /* Arbitration Lost bit position. */

#define TWI_MASTER_BUSERR_bm  0x04  /* Bus Error bit mask. */
#define TWI_MASTER_BUSERR_bp  2  /* Bus Error bit position. */

#define TWI_MASTER_BUSSTATE_gm  0x03  /* Bus State group mask. */
#define TWI_MASTER_BUSSTATE_gp  0  /* Bus State group position. */
#define TWI_MASTER_BUSSTATE0_bm  (1<<0)  /* Bus State bit 0 mask. */
#define TWI_MASTER_BUSSTATE0_bp  0  /* Bus State bit 0 position. */
#define TWI_MASTER_BUSSTATE1_bm  (1<<1)  /* Bus State bit 1 mask. */
#define TWI_MASTER_BUSSTATE1_bp  1  /* Bus State bit 1 position. */

/* TWI_SLAVE.CTRLA  bit masks and bit positions */
#define TWI_SLAVE_INTLVL_gm  0xC0  /* Interrupt Level group mask. */
#define TWI_SLAVE_INTLVL_gp  6  /* Interrupt Level group position. */
#define TWI_SLAVE_INTLVL0_bm  (1<<6)  /* Interrupt Level bit 0 mask. */
#define TWI_SLAVE_INTLVL0_bp  6  /* Interrupt Level bit 0 position. */
#define TWI_SLAVE_INTLVL1_bm  (1<<7)  /* Interrupt Level bit 1 mask. */
#define TWI_SLAVE_INTLVL1_bp  7  /* Interrupt Level bit 1 position. */

#define TWI_SLAVE_DIEN_bm  0x20  /* Data Interrupt Enable bit mask. */
#define TWI_SLAVE_DIEN_bp  5  /* Data Interrupt Enable bit position. */

#define TWI_SLAVE_APIEN_bm  0x10  /* Address/Stop Interrupt Enable bit mask. */
#define TWI_SLAVE_APIEN_bp  4  /* Address/Stop Interrupt Enable bit position. */

#define TWI_SLAVE_ENABLE_bm  0x08  /* Enable TWI Slave bit mask. */
#define TWI_SLAVE_ENABLE_bp  3  /* Enable TWI Slave bit position. */

#define TWI_SLAVE_PIEN_bm  0x04  /* Stop Interrupt Enable bit mask. */
#define TWI_SLAVE_PIEN_bp  2  /* Stop Interrupt Enable bit position. */

#define TWI_SLAVE_PMEN_bm  0x02  /* Promiscuous Mode Enable bit mask. */
#define TWI_SLAVE_PMEN_bp  1  /* Promiscuous Mode Enable bit position. */

#define TWI_SLAVE_SMEN_bm  0x01  /* Smart Mode Enable bit mask. */
#define TWI_SLAVE_SMEN_bp  0  /* Smart Mode Enable bit position. */

/* TWI_SLAVE.CTRLB  bit masks and bit positions */
#define TWI_SLAVE_ACKACT_bm  0x04  /* Acknowledge Action bit mask. */
#define TWI_SLAVE_ACKACT_bp  2  /* Acknowledge Action bit position. */

#define TWI_SLAVE_CMD_gm  0x03  /* Command group mask. */
#define TWI_SLAVE_CMD_gp  0  /* Command group position. */
#define TWI_SLAVE_CMD0_bm  (1<<0)  /* Command bit 0 mask. */
#define TWI_SLAVE_CMD0_bp  0  /* Command bit 0 position. */
#define TWI_SLAVE_CMD1_bm  (1<<1)  /* Command bit 1 mask. */
#define TWI_SLAVE_CMD1_bp  1  /* Command bit 1 position. */

#define TWI_SLAVE_TTOUTEN_bm  0x10  /* Ttimeout Enable bit mask. */
#define TWI_SLAVE_TTOUTEN_bp  4  /* Ttimeout Enable bit position. */

#define TWI_SLAVE_TOIE_bm  0x80  /* Timeout Interrupt Enable bit mask. */
#define TWI_SLAVE_TOIE_bp  7  /* Timeout Interrupt Enable bit position. */

/* TWI_SLAVE.STATUS  bit masks and bit positions */
#define TWI_SLAVE_DIF_bm  0x80  /* Data Interrupt Flag bit mask. */
#define TWI_SLAVE_DIF_bp  7  /* Data Interrupt Flag bit position. */

#define TWI_SLAVE_APIF_bm  0x40  /* Address/Stop Interrupt Flag bit mask. */
#define TWI_SLAVE_APIF_bp  6  /* Address/Stop Interrupt Flag bit position. */

#define TWI_SLAVE_CLKHOLD_bm  0x20  /* Clock Hold bit mask. */
#define TWI_SLAVE_CLKHOLD_bp  5  /* Clock Hold bit position. */

#define TWI_SLAVE_RXACK_bm  0x10  /* Received Acknowledge bit mask. */
#define TWI_SLAVE_RXACK_bp  4  /* Received Acknowledge bit position. */

#define TWI_SLAVE_COLL_bm  0x08  /* Collision bit mask. */
#define TWI_SLAVE_COLL_bp  3  /* Collision bit position. */

#define TWI_SLAVE_BUSERR_bm  0x04  /* Bus Error bit mask. */
#define TWI_SLAVE_BUSERR_bp  2  /* Bus Error bit position. */

#define TWI_SLAVE_DIR_bm  0x02  /* Read/Write Direction bit mask. */
#define TWI_SLAVE_DIR_bp  1  /* Read/Write Direction bit position. */

#define TWI_SLAVE_AP_bm  0x01  /* Slave Address or Stop bit mask. */
#define TWI_SLAVE_AP_bp  0  /* Slave Address or Stop bit position. */

/* TWI_SLAVE.ADDRMASK  bit masks and bit positions */
#define TWI_SLAVE_ADDRMASK_gm  0xFE  /* Address Mask group mask. */
#define TWI_SLAVE_ADDRMASK_gp  1  /* Address Mask group position. */
#define TWI_SLAVE_ADDRMASK0_bm  (1<<1)  /* Address Mask bit 0 mask. */
#define TWI_SLAVE_ADDRMASK0_bp  1  /* Address Mask bit 0 position. */
#define TWI_SLAVE_ADDRMASK1_bm  (1<<2)  /* Address Mask bit 1 mask. */
#define TWI_SLAVE_ADDRMASK1_bp  2  /* Address Mask bit 1 position. */
#define TWI_SLAVE_ADDRMASK2_bm  (1<<3)  /* Address Mask bit 2 mask. */
#define TWI_SLAVE_ADDRMASK2_bp  3  /* Address Mask bit 2 position. */
#define TWI_SLAVE_ADDRMASK3_bm  (1<<4)  /* Address Mask bit 3 mask. */
#define TWI_SLAVE_ADDRMASK3_bp  4  /* Address Mask bit 3 position. */
#define TWI_SLAVE_ADDRMASK4_bm  (1<<5)  /* Address Mask bit 4 mask. */
#define TWI_SLAVE_ADDRMASK4_bp  5  /* Address Mask bit 4 position. */
#define TWI_SLAVE_ADDRMASK5_bm  (1<<6)  /* Address Mask bit 5 mask. */
#define TWI_SLAVE_ADDRMASK5_bp  6  /* Address Mask bit 5 position. */
#define TWI_SLAVE_ADDRMASK6_bm  (1<<7)  /* Address Mask bit 6 mask. */
#define TWI_SLAVE_ADDRMASK6_bp  7  /* Address Mask bit 6 position. */

#define TWI_SLAVE_ADDREN_bm  0x01  /* Address Enable bit mask. */
#define TWI_SLAVE_ADDREN_bp  0  /* Address Enable bit position. */

/* TWI_TIMEOUT.TOS  bit masks and bit positions */
#define TWI_TIMEOUT_TTOUTMIF_bm  0x01  /* Master Ttimeout Interrupt Flag bit mask. */
#define TWI_TIMEOUT_TTOUTMIF_bp  0  /* Master Ttimeout Interrupt Flag bit position. */

#define TWI_TIMEOUT_TSEXTIF_bm  0x02  /* Slave Extend Interrupt Flag bit mask. */
#define TWI_TIMEOUT_TSEXTIF_bp  1  /* Slave Extend Interrupt Flag bit position. */

#define TWI_TIMEOUT_TMEXTIF_bm  0x04  /* Master Extend Interrupt Flag bit mask. */
#define TWI_TIMEOUT_TMEXTIF_bp  2  /* Master Extend Interrupt Flag bit position. */

#define TWI_TIMEOUT_TTOUTSIF_bm  0x10  /* Slave Ttimeout Interrupt Flag bit mask. */
#define TWI_TIMEOUT_TTOUTSIF_bp  4  /* Slave Ttimeout Interrupt Flag bit position. */

/* TWI_TIMEOUT.TOCONF  bit masks and bit positions */
#define TWI_TIMEOUT_TTOUTMSEL_gm  0x07  /* Master Ttimeout Select group mask. */
#define TWI_TIMEOUT_TTOUTMSEL_gp  0  /* Master Ttimeout Select group position. */
#define TWI_TIMEOUT_TTOUTMSEL0_bm  (1<<0)  /* Master Ttimeout Select bit 0 mask. */
#define TWI_TIMEOUT_TTOUTMSEL0_bp  0  /* Master Ttimeout Select bit 0 position. */
#define TWI_TIMEOUT_TTOUTMSEL1_bm  (1<<1)  /* Master Ttimeout Select bit 1 mask. */
#define TWI_TIMEOUT_TTOUTMSEL1_bp  1  /* Master Ttimeout Select bit 1 position. */
#define TWI_TIMEOUT_TTOUTMSEL2_bm  (1<<2)  /* Master Ttimeout Select bit 2 mask. */
#define TWI_TIMEOUT_TTOUTMSEL2_bp  2  /* Master Ttimeout Select bit 2 position. */

#define TWI_TIMEOUT_TMSEXTSEL_gm  0x18  /* Master/Slave Timeout Select group mask. */
#define TWI_TIMEOUT_TMSEXTSEL_gp  3  /* Master/Slave Timeout Select group position. */
#define TWI_TIMEOUT_TMSEXTSEL0_bm  (1<<3)  /* Master/Slave Timeout Select bit 0 mask. */
#define TWI_TIMEOUT_TMSEXTSEL0_bp  3  /* Master/Slave Timeout Select bit 0 position. */
#define TWI_TIMEOUT_TMSEXTSEL1_bm  (1<<4)  /* Master/Slave Timeout Select bit 1 mask. */
#define TWI_TIMEOUT_TMSEXTSEL1_bp  4  /* Master/Slave Timeout Select bit 1 position. */

#define TWI_TIMEOUT_TTOUTSSEL_gm  0xE0  /* Slave Ttimeout Select group mask. */
#define TWI_TIMEOUT_TTOUTSSEL_gp  5  /* Slave Ttimeout Select group position. */
#define TWI_TIMEOUT_TTOUTSSEL0_bm  (1<<5)  /* Slave Ttimeout Select bit 0 mask. */
#define TWI_TIMEOUT_TTOUTSSEL0_bp  5  /* Slave Ttimeout Select bit 0 position. */
#define TWI_TIMEOUT_TTOUTSSEL1_bm  (1<<6)  /* Slave Ttimeout Select bit 1 mask. */
#define TWI_TIMEOUT_TTOUTSSEL1_bp  6  /* Slave Ttimeout Select bit 1 position. */
#define TWI_TIMEOUT_TTOUTSSEL2_bm  (1<<7)  /* Slave Ttimeout Select bit 2 mask. */
#define TWI_TIMEOUT_TTOUTSSEL2_bp  7  /* Slave Ttimeout Select bit 2 position. */

/* PORT - Port Configuration */
/* PORT.INTCTRL  bit masks and bit positions */
#define PORT_INTLVL_gm  0x03  /* Port Interrupt Level group mask. */
#define PORT_INTLVL_gp  0  /* Port Interrupt Level group position. */
#define PORT_INTLVL0_bm  (1<<0)  /* Port Interrupt Level bit 0 mask. */
#define PORT_INTLVL0_bp  0  /* Port Interrupt Level bit 0 position. */
#define PORT_INTLVL1_bm  (1<<1)  /* Port Interrupt Level bit 1 mask. */
#define PORT_INTLVL1_bp  1  /* Port Interrupt Level bit 1 position. */

/* PORT.INTFLAGS  bit masks and bit positions */
#define PORT_INT7IF_bm  0x80  /* Pin 7 Interrupt Flag bit mask. */
#define PORT_INT7IF_bp  7  /* Pin 7 Interrupt Flag bit position. */

#define PORT_INT6IF_bm  0x40  /* Pin 6 Interrupt Flag bit mask. */
#define PORT_INT6IF_bp  6  /* Pin 6 Interrupt Flag bit position. */

#define PORT_INT5IF_bm  0x20  /* Pin 5 Interrupt Flag bit mask. */
#define PORT_INT5IF_bp  5  /* Pin 5 Interrupt Flag bit position. */

#define PORT_INT4IF_bm  0x10  /* Pin 4 Interrupt Flag bit mask. */
#define PORT_INT4IF_bp  4  /* Pin 4 Interrupt Flag bit position. */

#define PORT_INT3IF_bm  0x08  /* Pin 3 Interrupt Flag bit mask. */
#define PORT_INT3IF_bp  3  /* Pin 3 Interrupt Flag bit position. */

#define PORT_INT2IF_bm  0x04  /* Pin 2 Interrupt Flag bit mask. */
#define PORT_INT2IF_bp  2  /* Pin 2 Interrupt Flag bit position. */

#define PORT_INT1IF_bm  0x02  /* Pin 1 Interrupt Flag bit mask. */
#define PORT_INT1IF_bp  1  /* Pin 1 Interrupt Flag bit position. */

#define PORT_INT0IF_bm  0x01  /* Pin 0 Interrupt Flag bit mask. */
#define PORT_INT0IF_bp  0  /* Pin 0 Interrupt Flag bit position. */

/* PORT.REMAP  bit masks and bit positions */
#define PORT_USART0_bm  0x10  /* Usart0 bit mask. */
#define PORT_USART0_bp  4  /* Usart0 bit position. */

#define PORT_TC4D_bm  0x08  /* Timer/Counter 4 Output Compare D bit mask. */
#define PORT_TC4D_bp  3  /* Timer/Counter 4 Output Compare D bit position. */

#define PORT_TC4C_bm  0x04  /* Timer/Counter 4 Output Compare C bit mask. */
#define PORT_TC4C_bp  2  /* Timer/Counter 4 Output Compare C bit position. */

#define PORT_TC4B_bm  0x02  /* Timer/Counter 4 Output Compare B bit mask. */
#define PORT_TC4B_bp  1  /* Timer/Counter 4 Output Compare B bit position. */

#define PORT_TC4A_bm  0x01  /* Timer/Counter 4 Output Compare A bit mask. */
#define PORT_TC4A_bp  0  /* Timer/Counter 4 Output Compare A bit position. */

/* PORT.PIN0CTRL  bit masks and bit positions */
#define PORT_INVEN_bm  0x40  /* Inverted I/O Enable bit mask. */
#define PORT_INVEN_bp  6  /* Inverted I/O Enable bit position. */

#define PORT_OPC_gm  0x38  /* Output/Pull Configuration group mask. */
#define PORT_OPC_gp  3  /* Output/Pull Configuration group position. */
#define PORT_OPC0_bm  (1<<3)  /* Output/Pull Configuration bit 0 mask. */
#define PORT_OPC0_bp  3  /* Output/Pull Configuration bit 0 position. */
#define PORT_OPC1_bm  (1<<4)  /* Output/Pull Configuration bit 1 mask. */
#define PORT_OPC1_bp  4  /* Output/Pull Configuration bit 1 position. */
#define PORT_OPC2_bm  (1<<5)  /* Output/Pull Configuration bit 2 mask. */
#define PORT_OPC2_bp  5  /* Output/Pull Configuration bit 2 position. */

#define PORT_ISC_gm  0x07  /* Input/Sense Configuration group mask. */
#define PORT_ISC_gp  0  /* Input/Sense Configuration group position. */
#define PORT_ISC0_bm  (1<<0)  /* Input/Sense Configuration bit 0 mask. */
#define PORT_ISC0_bp  0  /* Input/Sense Configuration bit 0 position. */
#define PORT_ISC1_bm  (1<<1)  /* Input/Sense Configuration bit 1 mask. */
#define PORT_ISC1_bp  1  /* Input/Sense Configuration bit 1 position. */
#define PORT_ISC2_bm  (1<<2)  /* Input/Sense Configuration bit 2 mask. */
#define PORT_ISC2_bp  2  /* Input/Sense Configuration bit 2 position. */

/* PORT.PIN1CTRL  bit masks and bit positions */
/* PORT_INVEN  Predefined. */
/* PORT_INVEN  Predefined. */

/* PORT_OPC  Predefined. */
/* PORT_OPC  Predefined. */

/* PORT_ISC  Predefined. */
/* PORT_ISC  Predefined. */

/* PORT.PIN2CTRL  bit masks and bit positions */
/* PORT_INVEN  Predefined. */
/* PORT_INVEN  Predefined. */

/* PORT_OPC  Predefined. */
/* PORT_OPC  Predefined. */

/* PORT_ISC  Predefined. */
/* PORT_ISC  Predefined. */

/* PORT.PIN3CTRL  bit masks and bit positions */
/* PORT_INVEN  Predefined. */
/* PORT_INVEN  Predefined. */

/* PORT_OPC  Predefined. */
/* PORT_OPC  Predefined. */

/* PORT_ISC  Predefined. */
/* PORT_ISC  Predefined. */

/* PORT.PIN4CTRL  bit masks and bit positions */
/* PORT_INVEN  Predefined. */
/* PORT_INVEN  Predefined. */

/* PORT_OPC  Predefined. */
/* PORT_OPC  Predefined. */

/* PORT_ISC  Predefined. */
/* PORT_ISC  Predefined. */

/* PORT.PIN5CTRL  bit masks and bit positions */
/* PORT_INVEN  Predefined. */
/* PORT_INVEN  Predefined. */

/* PORT_OPC  Predefined. */
/* PORT_OPC  Predefined. */

/* PORT_ISC  Predefined. */
/* PORT_ISC  Predefined. */

/* PORT.PIN6CTRL  bit masks and bit positions */
/* PORT_INVEN  Predefined. */
/* PORT_INVEN  Predefined. */

/* PORT_OPC  Predefined. */
/* PORT_OPC  Predefined. */

/* PORT_ISC  Predefined. */
/* PORT_ISC  Predefined. */

/* PORT.PIN7CTRL  bit masks and bit positions */
/* PORT_INVEN  Predefined. */
/* PORT_INVEN  Predefined. */

/* PORT_OPC  Predefined. */
/* PORT_OPC  Predefined. */

/* PORT_ISC  Predefined. */
/* PORT_ISC  Predefined. */

/* TC - 16-bit Timer/Counter With PWM */
/* TC4.CTRLA  bit masks and bit positions */
#define TC4_SYNCHEN_bm  0x40  /* Synchronization Enabled bit mask. */
#define TC4_SYNCHEN_bp  6  /* Synchronization Enabled bit position. */

#define TC4_EVSTART_bm  0x20  /* Start on Next Event bit mask. */
#define TC4_EVSTART_bp  5  /* Start on Next Event bit position. */

#define TC4_UPSTOP_bm  0x10  /* Stop on Next Update bit mask. */
#define TC4_UPSTOP_bp  4  /* Stop on Next Update bit position. */

#define TC4_CLKSEL_gm  0x0F  /* Clock Select group mask. */
#define TC4_CLKSEL_gp  0  /* Clock Select group position. */
#define TC4_CLKSEL0_bm  (1<<0)  /* Clock Select bit 0 mask. */
#define TC4_CLKSEL0_bp  0  /* Clock Select bit 0 position. */
#define TC4_CLKSEL1_bm  (1<<1)  /* Clock Select bit 1 mask. */
#define TC4_CLKSEL1_bp  1  /* Clock Select bit 1 position. */
#define TC4_CLKSEL2_bm  (1<<2)  /* Clock Select bit 2 mask. */
#define TC4_CLKSEL2_bp  2  /* Clock Select bit 2 position. */
#define TC4_CLKSEL3_bm  (1<<3)  /* Clock Select bit 3 mask. */
#define TC4_CLKSEL3_bp  3  /* Clock Select bit 3 position. */

/* TC4.CTRLB  bit masks and bit positions */
#define TC4_BYTEM_gm  0xC0  /* Byte Mode group mask. */
#define TC4_BYTEM_gp  6  /* Byte Mode group position. */
#define TC4_BYTEM0_bm  (1<<6)  /* Byte Mode bit 0 mask. */
#define TC4_BYTEM0_bp  6  /* Byte Mode bit 0 position. */
#define TC4_BYTEM1_bm  (1<<7)  /* Byte Mode bit 1 mask. */
#define TC4_BYTEM1_bp  7  /* Byte Mode bit 1 position. */

#define TC4_CIRCEN_gm  0x30  /* Circular Buffer Enable group mask. */
#define TC4_CIRCEN_gp  4  /* Circular Buffer Enable group position. */
#define TC4_CIRCEN0_bm  (1<<4)  /* Circular Buffer Enable bit 0 mask. */
#define TC4_CIRCEN0_bp  4  /* Circular Buffer Enable bit 0 position. */
#define TC4_CIRCEN1_bm  (1<<5)  /* Circular Buffer Enable bit 1 mask. */
#define TC4_CIRCEN1_bp  5  /* Circular Buffer Enable bit 1 position. */

#define TC4_WGMODE_gm  0x07  /* Waveform Generation Mode group mask. */
#define TC4_WGMODE_gp  0  /* Waveform Generation Mode group position. */
#define TC4_WGMODE0_bm  (1<<0)  /* Waveform Generation Mode bit 0 mask. */
#define TC4_WGMODE0_bp  0  /* Waveform Generation Mode bit 0 position. */
#define TC4_WGMODE1_bm  (1<<1)  /* Waveform Generation Mode bit 1 mask. */
#define TC4_WGMODE1_bp  1  /* Waveform Generation Mode bit 1 position. */
#define TC4_WGMODE2_bm  (1<<2)  /* Waveform Generation Mode bit 2 mask. */
#define TC4_WGMODE2_bp  2  /* Waveform Generation Mode bit 2 position. */

/* TC4.CTRLC  bit masks and bit positions */
#define TC4_POLD_bm  0x80  /* Channel D Output Polarity bit mask. */
#define TC4_POLD_bp  7  /* Channel D Output Polarity bit position. */

#define TC4_POLC_bm  0x40  /* Channel C Output Polarity bit mask. */
#define TC4_POLC_bp  6  /* Channel C Output Polarity bit position. */

#define TC4_POLB_bm  0x20  /* Channel B Output Polarity bit mask. */
#define TC4_POLB_bp  5  /* Channel B Output Polarity bit position. */

#define TC4_POLA_bm  0x10  /* Channel A Output Polarity bit mask. */
#define TC4_POLA_bp  4  /* Channel A Output Polarity bit position. */

#define TC4_CMPD_bm  0x08  /* Channel D Compare Output Value bit mask. */
#define TC4_CMPD_bp  3  /* Channel D Compare Output Value bit position. */

#define TC4_CMPC_bm  0x04  /* Channel C Compare Output Value bit mask. */
#define TC4_CMPC_bp  2  /* Channel C Compare Output Value bit position. */

#define TC4_CMPB_bm  0x02  /* Channel B Compare Output Value bit mask. */
#define TC4_CMPB_bp  1  /* Channel B Compare Output Value bit position. */

#define TC4_CMPA_bm  0x01  /* Channel A Compare Output Value bit mask. */
#define TC4_CMPA_bp  0  /* Channel A Compare Output Value bit position. */

#define TC4_HCMPD_bm  0x80  /* High Channel D Compare Output Value bit mask. */
#define TC4_HCMPD_bp  7  /* High Channel D Compare Output Value bit position. */

#define TC4_HCMPC_bm  0x40  /* High Channel C Compare Output Value bit mask. */
#define TC4_HCMPC_bp  6  /* High Channel C Compare Output Value bit position. */

#define TC4_HCMPB_bm  0x20  /* High Channel B Compare Output Value bit mask. */
#define TC4_HCMPB_bp  5  /* High Channel B Compare Output Value bit position. */

#define TC4_HCMPA_bm  0x10  /* High Channel A Compare Output Value bit mask. */
#define TC4_HCMPA_bp  4  /* High Channel A Compare Output Value bit position. */

#define TC4_LCMPD_bm  0x08  /* Low Channel D Compare Output Value bit mask. */
#define TC4_LCMPD_bp  3  /* Low Channel D Compare Output Value bit position. */

#define TC4_LCMPC_bm  0x04  /* Low Channel C Compare Output Value bit mask. */
#define TC4_LCMPC_bp  2  /* Low Channel C Compare Output Value bit position. */

#define TC4_LCMPB_bm  0x02  /* Low Channel B Compare Output Value bit mask. */
#define TC4_LCMPB_bp  1  /* Low Channel B Compare Output Value bit position. */

#define TC4_LCMPA_bm  0x01  /* Low Channel A Compare Output Value bit mask. */
#define TC4_LCMPA_bp  0  /* Low Channel A Compare Output Value bit position. */

/* TC4.CTRLD  bit masks and bit positions */
#define TC4_EVACT_gm  0xE0  /* Event Action group mask. */
#define TC4_EVACT_gp  5  /* Event Action group position. */
#define TC4_EVACT0_bm  (1<<5)  /* Event Action bit 0 mask. */
#define TC4_EVACT0_bp  5  /* Event Action bit 0 position. */
#define TC4_EVACT1_bm  (1<<6)  /* Event Action bit 1 mask. */
#define TC4_EVACT1_bp  6  /* Event Action bit 1 position. */
#define TC4_EVACT2_bm  (1<<7)  /* Event Action bit 2 mask. */
#define TC4_EVACT2_bp  7  /* Event Action bit 2 position. */

#define TC4_EVDLY_bm  0x10  /* Event Delay bit mask. */
#define TC4_EVDLY_bp  4  /* Event Delay bit position. */

#define TC4_EVSEL_gm  0x0F  /* Event Source Select group mask. */
#define TC4_EVSEL_gp  0  /* Event Source Select group position. */
#define TC4_EVSEL0_bm  (1<<0)  /* Event Source Select bit 0 mask. */
#define TC4_EVSEL0_bp  0  /* Event Source Select bit 0 position. */
#define TC4_EVSEL1_bm  (1<<1)  /* Event Source Select bit 1 mask. */
#define TC4_EVSEL1_bp  1  /* Event Source Select bit 1 position. */
#define TC4_EVSEL2_bm  (1<<2)  /* Event Source Select bit 2 mask. */
#define TC4_EVSEL2_bp  2  /* Event Source Select bit 2 position. */
#define TC4_EVSEL3_bm  (1<<3)  /* Event Source Select bit 3 mask. */
#define TC4_EVSEL3_bp  3  /* Event Source Select bit 3 position. */

/* TC4.CTRLE  bit masks and bit positions */
#define TC4_CCDMODE_gm  0xC0  /* Channel D Compare or Capture Mode group mask. */
#define TC4_CCDMODE_gp  6  /* Channel D Compare or Capture Mode group position. */
#define TC4_CCDMODE0_bm  (1<<6)  /* Channel D Compare or Capture Mode bit 0 mask. */
#define TC4_CCDMODE0_bp  6  /* Channel D Compare or Capture Mode bit 0 position. */
#define TC4_CCDMODE1_bm  (1<<7)  /* Channel D Compare or Capture Mode bit 1 mask. */
#define TC4_CCDMODE1_bp  7  /* Channel D Compare or Capture Mode bit 1 position. */

#define TC4_CCCMODE_gm  0x30  /* Channel C Compare or Capture Mode group mask. */
#define TC4_CCCMODE_gp  4  /* Channel C Compare or Capture Mode group position. */
#define TC4_CCCMODE0_bm  (1<<4)  /* Channel C Compare or Capture Mode bit 0 mask. */
#define TC4_CCCMODE0_bp  4  /* Channel C Compare or Capture Mode bit 0 position. */
#define TC4_CCCMODE1_bm  (1<<5)  /* Channel C Compare or Capture Mode bit 1 mask. */
#define TC4_CCCMODE1_bp  5  /* Channel C Compare or Capture Mode bit 1 position. */

#define TC4_CCBMODE_gm  0x0C  /* Channel B Compare or Capture Mode group mask. */
#define TC4_CCBMODE_gp  2  /* Channel B Compare or Capture Mode group position. */
#define TC4_CCBMODE0_bm  (1<<2)  /* Channel B Compare or Capture Mode bit 0 mask. */
#define TC4_CCBMODE0_bp  2  /* Channel B Compare or Capture Mode bit 0 position. */
#define TC4_CCBMODE1_bm  (1<<3)  /* Channel B Compare or Capture Mode bit 1 mask. */
#define TC4_CCBMODE1_bp  3  /* Channel B Compare or Capture Mode bit 1 position. */

#define TC4_CCAMODE_gm  0x03  /* Channel A Compare or Capture Mode group mask. */
#define TC4_CCAMODE_gp  0  /* Channel A Compare or Capture Mode group position. */
#define TC4_CCAMODE0_bm  (1<<0)  /* Channel A Compare or Capture Mode bit 0 mask. */
#define TC4_CCAMODE0_bp  0  /* Channel A Compare or Capture Mode bit 0 position. */
#define TC4_CCAMODE1_bm  (1<<1)  /* Channel A Compare or Capture Mode bit 1 mask. */
#define TC4_CCAMODE1_bp  1  /* Channel A Compare or Capture Mode bit 1 position. */

#define TC4_LCCDMODE_gm  0xC0  /* Channel Low D Compare or Capture Mode group mask. */
#define TC4_LCCDMODE_gp  6  /* Channel Low D Compare or Capture Mode group position. */
#define TC4_LCCDMODE0_bm  (1<<6)  /* Channel Low D Compare or Capture Mode bit 0 mask. */
#define TC4_LCCDMODE0_bp  6  /* Channel Low D Compare or Capture Mode bit 0 position. */
#define TC4_LCCDMODE1_bm  (1<<7)  /* Channel Low D Compare or Capture Mode bit 1 mask. */
#define TC4_LCCDMODE1_bp  7  /* Channel Low D Compare or Capture Mode bit 1 position. */

#define TC4_LCCCMODE_gm  0x30  /* Channel Low C Compare or Capture Mode group mask. */
#define TC4_LCCCMODE_gp  4  /* Channel Low C Compare or Capture Mode group position. */
#define TC4_LCCCMODE0_bm  (1<<4)  /* Channel Low C Compare or Capture Mode bit 0 mask. */
#define TC4_LCCCMODE0_bp  4  /* Channel Low C Compare or Capture Mode bit 0 position. */
#define TC4_LCCCMODE1_bm  (1<<5)  /* Channel Low C Compare or Capture Mode bit 1 mask. */
#define TC4_LCCCMODE1_bp  5  /* Channel Low C Compare or Capture Mode bit 1 position. */

#define TC4_LCCBMODE_gm  0x0C  /* Channel Low B Compare or Capture Mode group mask. */
#define TC4_LCCBMODE_gp  2  /* Channel Low B Compare or Capture Mode group position. */
#define TC4_LCCBMODE0_bm  (1<<2)  /* Channel Low B Compare or Capture Mode bit 0 mask. */
#define TC4_LCCBMODE0_bp  2  /* Channel Low B Compare or Capture Mode bit 0 position. */
#define TC4_LCCBMODE1_bm  (1<<3)  /* Channel Low B Compare or Capture Mode bit 1 mask. */
#define TC4_LCCBMODE1_bp  3  /* Channel Low B Compare or Capture Mode bit 1 position. */

#define TC4_LCCAMODE_gm  0x03  /* Channel Low A Compare or Capture Mode group mask. */
#define TC4_LCCAMODE_gp  0  /* Channel Low A Compare or Capture Mode group position. */
#define TC4_LCCAMODE0_bm  (1<<0)  /* Channel Low A Compare or Capture Mode bit 0 mask. */
#define TC4_LCCAMODE0_bp  0  /* Channel Low A Compare or Capture Mode bit 0 position. */
#define TC4_LCCAMODE1_bm  (1<<1)  /* Channel Low A Compare or Capture Mode bit 1 mask. */
#define TC4_LCCAMODE1_bp  1  /* Channel Low A Compare or Capture Mode bit 1 position. */

/* TC4.CTRLF  bit masks and bit positions */
#define TC4_HCCDMODE_gm  0xC0  /* Channel High D Compare or Capture Mode group mask. */
#define TC4_HCCDMODE_gp  6  /* Channel High D Compare or Capture Mode group position. */
#define TC4_HCCDMODE0_bm  (1<<6)  /* Channel High D Compare or Capture Mode bit 0 mask. */
#define TC4_HCCDMODE0_bp  6  /* Channel High D Compare or Capture Mode bit 0 position. */
#define TC4_HCCDMODE1_bm  (1<<7)  /* Channel High D Compare or Capture Mode bit 1 mask. */
#define TC4_HCCDMODE1_bp  7  /* Channel High D Compare or Capture Mode bit 1 position. */

#define TC4_HCCCMODE_gm  0x30  /* Channel High C Compare or Capture Mode group mask. */
#define TC4_HCCCMODE_gp  4  /* Channel High C Compare or Capture Mode group position. */
#define TC4_HCCCMODE0_bm  (1<<4)  /* Channel High C Compare or Capture Mode bit 0 mask. */
#define TC4_HCCCMODE0_bp  4  /* Channel High C Compare or Capture Mode bit 0 position. */
#define TC4_HCCCMODE1_bm  (1<<5)  /* Channel High C Compare or Capture Mode bit 1 mask. */
#define TC4_HCCCMODE1_bp  5  /* Channel High C Compare or Capture Mode bit 1 position. */

#define TC4_HCCBMODE_gm  0x0C  /* Channel High B Compare or Capture Mode group mask. */
#define TC4_HCCBMODE_gp  2  /* Channel High B Compare or Capture Mode group position. */
#define TC4_HCCBMODE0_bm  (1<<2)  /* Channel High B Compare or Capture Mode bit 0 mask. */
#define TC4_HCCBMODE0_bp  2  /* Channel High B Compare or Capture Mode bit 0 position. */
#define TC4_HCCBMODE1_bm  (1<<3)  /* Channel High B Compare or Capture Mode bit 1 mask. */
#define TC4_HCCBMODE1_bp  3  /* Channel High B Compare or Capture Mode bit 1 position. */

#define TC4_HCCAMODE_gm  0x03  /* Channel High A Compare or Capture Mode group mask. */
#define TC4_HCCAMODE_gp  0  /* Channel High A Compare or Capture Mode group position. */
#define TC4_HCCAMODE0_bm  (1<<0)  /* Channel High A Compare or Capture Mode bit 0 mask. */
#define TC4_HCCAMODE0_bp  0  /* Channel High A Compare or Capture Mode bit 0 position. */
#define TC4_HCCAMODE1_bm  (1<<1)  /* Channel High A Compare or Capture Mode bit 1 mask. */
#define TC4_HCCAMODE1_bp  1  /* Channel High A Compare or Capture Mode bit 1 position. */

/* TC4.INTCTRLA  bit masks and bit positions */
#define TC4_TRGINTLVL_gm  0x30  /* Timer Trigger Restart Interrupt Level group mask. */
#define TC4_TRGINTLVL_gp  4  /* Timer Trigger Restart Interrupt Level group position. */
#define TC4_TRGINTLVL0_bm  (1<<4)  /* Timer Trigger Restart Interrupt Level bit 0 mask. */
#define TC4_TRGINTLVL0_bp  4  /* Timer Trigger Restart Interrupt Level bit 0 position. */
#define TC4_TRGINTLVL1_bm  (1<<5)  /* Timer Trigger Restart Interrupt Level bit 1 mask. */
#define TC4_TRGINTLVL1_bp  5  /* Timer Trigger Restart Interrupt Level bit 1 position. */

#define TC4_ERRINTLVL_gm  0x0C  /* Timer Error Interrupt Level group mask. */
#define TC4_ERRINTLVL_gp  2  /* Timer Error Interrupt Level group position. */
#define TC4_ERRINTLVL0_bm  (1<<2)  /* Timer Error Interrupt Level bit 0 mask. */
#define TC4_ERRINTLVL0_bp  2  /* Timer Error Interrupt Level bit 0 position. */
#define TC4_ERRINTLVL1_bm  (1<<3)  /* Timer Error Interrupt Level bit 1 mask. */
#define TC4_ERRINTLVL1_bp  3  /* Timer Error Interrupt Level bit 1 position. */

#define TC4_OVFINTLVL_gm  0x03  /* Timer Overflow/Underflow Interrupt Level group mask. */
#define TC4_OVFINTLVL_gp  0  /* Timer Overflow/Underflow Interrupt Level group position. */
#define TC4_OVFINTLVL0_bm  (1<<0)  /* Timer Overflow/Underflow Interrupt Level bit 0 mask. */
#define TC4_OVFINTLVL0_bp  0  /* Timer Overflow/Underflow Interrupt Level bit 0 position. */
#define TC4_OVFINTLVL1_bm  (1<<1)  /* Timer Overflow/Underflow Interrupt Level bit 1 mask. */
#define TC4_OVFINTLVL1_bp  1  /* Timer Overflow/Underflow Interrupt Level bit 1 position. */

/* TC4.INTCTRLB  bit masks and bit positions */
#define TC4_CCDINTLVL_gm  0xC0  /* Channel D Compare or Capture Interrupt Level group mask. */
#define TC4_CCDINTLVL_gp  6  /* Channel D Compare or Capture Interrupt Level group position. */
#define TC4_CCDINTLVL0_bm  (1<<6)  /* Channel D Compare or Capture Interrupt Level bit 0 mask. */
#define TC4_CCDINTLVL0_bp  6  /* Channel D Compare or Capture Interrupt Level bit 0 position. */
#define TC4_CCDINTLVL1_bm  (1<<7)  /* Channel D Compare or Capture Interrupt Level bit 1 mask. */
#define TC4_CCDINTLVL1_bp  7  /* Channel D Compare or Capture Interrupt Level bit 1 position. */

#define TC4_CCCINTLVL_gm  0x30  /* Channel C Compare or Capture Interrupt Level group mask. */
#define TC4_CCCINTLVL_gp  4  /* Channel C Compare or Capture Interrupt Level group position. */
#define TC4_CCCINTLVL0_bm  (1<<4)  /* Channel C Compare or Capture Interrupt Level bit 0 mask. */
#define TC4_CCCINTLVL0_bp  4  /* Channel C Compare or Capture Interrupt Level bit 0 position. */
#define TC4_CCCINTLVL1_bm  (1<<5)  /* Channel C Compare or Capture Interrupt Level bit 1 mask. */
#define TC4_CCCINTLVL1_bp  5  /* Channel C Compare or Capture Interrupt Level bit 1 position. */

#define TC4_CCBINTLVL_gm  0x0C  /* Channel B Compare or Capture Interrupt Level group mask. */
#define TC4_CCBINTLVL_gp  2  /* Channel B Compare or Capture Interrupt Level group position. */
#define TC4_CCBINTLVL0_bm  (1<<2)  /* Channel B Compare or Capture Interrupt Level bit 0 mask. */
#define TC4_CCBINTLVL0_bp  2  /* Channel B Compare or Capture Interrupt Level bit 0 position. */
#define TC4_CCBINTLVL1_bm  (1<<3)  /* Channel B Compare or Capture Interrupt Level bit 1 mask. */
#define TC4_CCBINTLVL1_bp  3  /* Channel B Compare or Capture Interrupt Level bit 1 position. */

#define TC4_CCAINTLVL_gm  0x03  /* Channel A Compare or Capture Interrupt Level group mask. */
#define TC4_CCAINTLVL_gp  0  /* Channel A Compare or Capture Interrupt Level group position. */
#define TC4_CCAINTLVL0_bm  (1<<0)  /* Channel A Compare or Capture Interrupt Level bit 0 mask. */
#define TC4_CCAINTLVL0_bp  0  /* Channel A Compare or Capture Interrupt Level bit 0 position. */
#define TC4_CCAINTLVL1_bm  (1<<1)  /* Channel A Compare or Capture Interrupt Level bit 1 mask. */
#define TC4_CCAINTLVL1_bp  1  /* Channel A Compare or Capture Interrupt Level bit 1 position. */

#define TC4_LCCDINTLVL_gm  0xC0  /* Channel Low D Compare or Capture Interrupt Level group mask. */
#define TC4_LCCDINTLVL_gp  6  /* Channel Low D Compare or Capture Interrupt Level group position. */
#define TC4_LCCDINTLVL0_bm  (1<<6)  /* Channel Low D Compare or Capture Interrupt Level bit 0 mask. */
#define TC4_LCCDINTLVL0_bp  6  /* Channel Low D Compare or Capture Interrupt Level bit 0 position. */
#define TC4_LCCDINTLVL1_bm  (1<<7)  /* Channel Low D Compare or Capture Interrupt Level bit 1 mask. */
#define TC4_LCCDINTLVL1_bp  7  /* Channel Low D Compare or Capture Interrupt Level bit 1 position. */

#define TC4_LCCCINTLVL_gm  0x30  /* Channel Low C Compare or Capture Interrupt Level group mask. */
#define TC4_LCCCINTLVL_gp  4  /* Channel Low C Compare or Capture Interrupt Level group position. */
#define TC4_LCCCINTLVL0_bm  (1<<4)  /* Channel Low C Compare or Capture Interrupt Level bit 0 mask. */
#define TC4_LCCCINTLVL0_bp  4  /* Channel Low C Compare or Capture Interrupt Level bit 0 position. */
#define TC4_LCCCINTLVL1_bm  (1<<5)  /* Channel Low C Compare or Capture Interrupt Level bit 1 mask. */
#define TC4_LCCCINTLVL1_bp  5  /* Channel Low C Compare or Capture Interrupt Level bit 1 position. */

#define TC4_LCCBINTLVL_gm  0x0C  /* Channel Low B Compare or Capture Interrupt Level group mask. */
#define TC4_LCCBINTLVL_gp  2  /* Channel Low B Compare or Capture Interrupt Level group position. */
#define TC4_LCCBINTLVL0_bm  (1<<2)  /* Channel Low B Compare or Capture Interrupt Level bit 0 mask. */
#define TC4_LCCBINTLVL0_bp  2  /* Channel Low B Compare or Capture Interrupt Level bit 0 position. */
#define TC4_LCCBINTLVL1_bm  (1<<3)  /* Channel Low B Compare or Capture Interrupt Level bit 1 mask. */
#define TC4_LCCBINTLVL1_bp  3  /* Channel Low B Compare or Capture Interrupt Level bit 1 position. */

#define TC4_LCCAINTLVL_gm  0x03  /* Channel Low A Compare or Capture Interrupt Level group mask. */
#define TC4_LCCAINTLVL_gp  0  /* Channel Low A Compare or Capture Interrupt Level group position. */
#define TC4_LCCAINTLVL0_bm  (1<<0)  /* Channel Low A Compare or Capture Interrupt Level bit 0 mask. */
#define TC4_LCCAINTLVL0_bp  0  /* Channel Low A Compare or Capture Interrupt Level bit 0 position. */
#define TC4_LCCAINTLVL1_bm  (1<<1)  /* Channel Low A Compare or Capture Interrupt Level bit 1 mask. */
#define TC4_LCCAINTLVL1_bp  1  /* Channel Low A Compare or Capture Interrupt Level bit 1 position. */

/* TC4.CTRLGCLR  bit masks and bit positions */
#define TC4_STOP_bm  0x20  /* Timer/Counter Stop bit mask. */
#define TC4_STOP_bp  5  /* Timer/Counter Stop bit position. */

#define TC4_CMD_gm  0x0C  /* Command group mask. */
#define TC4_CMD_gp  2  /* Command group position. */
#define TC4_CMD0_bm  (1<<2)  /* Command bit 0 mask. */
#define TC4_CMD0_bp  2  /* Command bit 0 position. */
#define TC4_CMD1_bm  (1<<3)  /* Command bit 1 mask. */
#define TC4_CMD1_bp  3  /* Command bit 1 position. */

#define TC4_LUPD_bm  0x02  /* Lock Update bit mask. */
#define TC4_LUPD_bp  1  /* Lock Update bit position. */

#define TC4_DIR_bm  0x01  /* Counter Direction bit mask. */
#define TC4_DIR_bp  0  /* Counter Direction bit position. */

/* TC4.CTRLGSET  bit masks and bit positions */
/* TC4_STOP  Predefined. */
/* TC4_STOP  Predefined. */

/* TC4_CMD  Predefined. */
/* TC4_CMD  Predefined. */

/* TC4_LUPD  Predefined. */
/* TC4_LUPD  Predefined. */

/* TC4_DIR  Predefined. */
/* TC4_DIR  Predefined. */

/* TC4.CTRLHCLR  bit masks and bit positions */
#define TC4_CCDBV_bm  0x10  /* Channel D Compare or Capture Buffer Valid bit mask. */
#define TC4_CCDBV_bp  4  /* Channel D Compare or Capture Buffer Valid bit position. */

#define TC4_CCCBV_bm  0x08  /* Channel C Compare or Capture Buffer Valid bit mask. */
#define TC4_CCCBV_bp  3  /* Channel C Compare or Capture Buffer Valid bit position. */

#define TC4_CCBBV_bm  0x04  /* Channel B Compare or Capture Buffer Valid bit mask. */
#define TC4_CCBBV_bp  2  /* Channel B Compare or Capture Buffer Valid bit position. */

#define TC4_CCABV_bm  0x02  /* Channel A Compare or Capture Buffer Valid bit mask. */
#define TC4_CCABV_bp  1  /* Channel A Compare or Capture Buffer Valid bit position. */

#define TC4_PERBV_bm  0x01  /* Period Buffer Valid bit mask. */
#define TC4_PERBV_bp  0  /* Period Buffer Valid bit position. */

#define TC4_LCCDBV_bm  0x10  /* Channel Low D Compare or Capture Buffer Valid bit mask. */
#define TC4_LCCDBV_bp  4  /* Channel Low D Compare or Capture Buffer Valid bit position. */

#define TC4_LCCCBV_bm  0x08  /* Channel Low C Compare or Capture Buffer Valid bit mask. */
#define TC4_LCCCBV_bp  3  /* Channel Low C Compare or Capture Buffer Valid bit position. */

#define TC4_LCCBBV_bm  0x04  /* Channel Low B Compare or Capture Buffer Valid bit mask. */
#define TC4_LCCBBV_bp  2  /* Channel Low B Compare or Capture Buffer Valid bit position. */

#define TC4_LCCABV_bm  0x02  /* Channel Low A Compare or Capture Buffer Valid bit mask. */
#define TC4_LCCABV_bp  1  /* Channel Low A Compare or Capture Buffer Valid bit position. */

#define TC4_LPERBV_bm  0x01  /* Period Low Buffer Valid bit mask. */
#define TC4_LPERBV_bp  0  /* Period Low Buffer Valid bit position. */

/* TC4.CTRLHSET  bit masks and bit positions */
/* TC4_CCDBV  Predefined. */
/* TC4_CCDBV  Predefined. */

/* TC4_CCCBV  Predefined. */
/* TC4_CCCBV  Predefined. */

/* TC4_CCBBV  Predefined. */
/* TC4_CCBBV  Predefined. */

/* TC4_CCABV  Predefined. */
/* TC4_CCABV  Predefined. */

/* TC4_PERBV  Predefined. */
/* TC4_PERBV  Predefined. */

/* TC4_LCCDBV  Predefined. */
/* TC4_LCCDBV  Predefined. */

/* TC4_LCCCBV  Predefined. */
/* TC4_LCCCBV  Predefined. */

/* TC4_LCCBBV  Predefined. */
/* TC4_LCCBBV  Predefined. */

/* TC4_LCCABV  Predefined. */
/* TC4_LCCABV  Predefined. */

/* TC4_LPERBV  Predefined. */
/* TC4_LPERBV  Predefined. */

/* TC4.INTFLAGS  bit masks and bit positions */
#define TC4_CCDIF_bm  0x80  /* Channel D Compare or Capture Interrupt Flag bit mask. */
#define TC4_CCDIF_bp  7  /* Channel D Compare or Capture Interrupt Flag bit position. */

#define TC4_CCCIF_bm  0x40  /* Channel C Compare or Capture Interrupt Flag bit mask. */
#define TC4_CCCIF_bp  6  /* Channel C Compare or Capture Interrupt Flag bit position. */

#define TC4_CCBIF_bm  0x20  /* Channel B Compare or Capture Interrupt Flag bit mask. */
#define TC4_CCBIF_bp  5  /* Channel B Compare or Capture Interrupt Flag bit position. */

#define TC4_CCAIF_bm  0x10  /* Channel A Compare or Capture Interrupt Flag bit mask. */
#define TC4_CCAIF_bp  4  /* Channel A Compare or Capture Interrupt Flag bit position. */

#define TC4_TRGIF_bm  0x04  /* Trigger Restart Interrupt Flag bit mask. */
#define TC4_TRGIF_bp  2  /* Trigger Restart Interrupt Flag bit position. */

#define TC4_ERRIF_bm  0x02  /* Error Interrupt Flag bit mask. */
#define TC4_ERRIF_bp  1  /* Error Interrupt Flag bit position. */

#define TC4_OVFIF_bm  0x01  /* Overflow/Underflow Interrupt Flag bit mask. */
#define TC4_OVFIF_bp  0  /* Overflow/Underflow Interrupt Flag bit position. */

#define TC4_LCCDIF_bm  0x80  /* Channel Low D Compare or Capture Interrupt Flag bit mask. */
#define TC4_LCCDIF_bp  7  /* Channel Low D Compare or Capture Interrupt Flag bit position. */

#define TC4_LCCCIF_bm  0x40  /* Channel Low C Compare or Capture Interrupt Flag bit mask. */
#define TC4_LCCCIF_bp  6  /* Channel Low C Compare or Capture Interrupt Flag bit position. */

#define TC4_LCCBIF_bm  0x20  /* Channel Low B Compare or Capture Interrupt Flag bit mask. */
#define TC4_LCCBIF_bp  5  /* Channel Low B Compare or Capture Interrupt Flag bit position. */

#define TC4_LCCAIF_bm  0x10  /* Channel Low A Compare or Capture Interrupt Flag bit mask. */
#define TC4_LCCAIF_bp  4  /* Channel Low A Compare or Capture Interrupt Flag bit position. */

/* TC5.CTRLA  bit masks and bit positions */
#define TC5_SYNCHEN_bm  0x40  /* Synchronization Enabled bit mask. */
#define TC5_SYNCHEN_bp  6  /* Synchronization Enabled bit position. */

#define TC5_EVSTART_bm  0x20  /* Start on Next Event bit mask. */
#define TC5_EVSTART_bp  5  /* Start on Next Event bit position. */

#define TC5_UPSTOP_bm  0x10  /* Stop on Next Update bit mask. */
#define TC5_UPSTOP_bp  4  /* Stop on Next Update bit position. */

#define TC5_CLKSEL_gm  0x0F  /* Clock Select group mask. */
#define TC5_CLKSEL_gp  0  /* Clock Select group position. */
#define TC5_CLKSEL0_bm  (1<<0)  /* Clock Select bit 0 mask. */
#define TC5_CLKSEL0_bp  0  /* Clock Select bit 0 position. */
#define TC5_CLKSEL1_bm  (1<<1)  /* Clock Select bit 1 mask. */
#define TC5_CLKSEL1_bp  1  /* Clock Select bit 1 position. */
#define TC5_CLKSEL2_bm  (1<<2)  /* Clock Select bit 2 mask. */
#define TC5_CLKSEL2_bp  2  /* Clock Select bit 2 position. */
#define TC5_CLKSEL3_bm  (1<<3)  /* Clock Select bit 3 mask. */
#define TC5_CLKSEL3_bp  3  /* Clock Select bit 3 position. */

/* TC5.CTRLB  bit masks and bit positions */
#define TC5_BYTEM_gm  0xC0  /* Byte Mode group mask. */
#define TC5_BYTEM_gp  6  /* Byte Mode group position. */
#define TC5_BYTEM0_bm  (1<<6)  /* Byte Mode bit 0 mask. */
#define TC5_BYTEM0_bp  6  /* Byte Mode bit 0 position. */
#define TC5_BYTEM1_bm  (1<<7)  /* Byte Mode bit 1 mask. */
#define TC5_BYTEM1_bp  7  /* Byte Mode bit 1 position. */

#define TC5_CIRCEN_gm  0x30  /* Circular Buffer Enable group mask. */
#define TC5_CIRCEN_gp  4  /* Circular Buffer Enable group position. */
#define TC5_CIRCEN0_bm  (1<<4)  /* Circular Buffer Enable bit 0 mask. */
#define TC5_CIRCEN0_bp  4  /* Circular Buffer Enable bit 0 position. */
#define TC5_CIRCEN1_bm  (1<<5)  /* Circular Buffer Enable bit 1 mask. */
#define TC5_CIRCEN1_bp  5  /* Circular Buffer Enable bit 1 position. */

#define TC5_WGMODE_gm  0x07  /* Waveform Generation Mode group mask. */
#define TC5_WGMODE_gp  0  /* Waveform Generation Mode group position. */
#define TC5_WGMODE0_bm  (1<<0)  /* Waveform Generation Mode bit 0 mask. */
#define TC5_WGMODE0_bp  0  /* Waveform Generation Mode bit 0 position. */
#define TC5_WGMODE1_bm  (1<<1)  /* Waveform Generation Mode bit 1 mask. */
#define TC5_WGMODE1_bp  1  /* Waveform Generation Mode bit 1 position. */
#define TC5_WGMODE2_bm  (1<<2)  /* Waveform Generation Mode bit 2 mask. */
#define TC5_WGMODE2_bp  2  /* Waveform Generation Mode bit 2 position. */

/* TC5.CTRLC  bit masks and bit positions */
#define TC5_POLB_bm  0x20  /* Channel B Output Polarity bit mask. */
#define TC5_POLB_bp  5  /* Channel B Output Polarity bit position. */

#define TC5_POLA_bm  0x10  /* Channel A Output Polarity bit mask. */
#define TC5_POLA_bp  4  /* Channel A Output Polarity bit position. */

#define TC5_CMPB_bm  0x02  /* Channel B Compare Output Value bit mask. */
#define TC5_CMPB_bp  1  /* Channel B Compare Output Value bit position. */

#define TC5_CMPA_bm  0x01  /* Channel A Compare Output Value bit mask. */
#define TC5_CMPA_bp  0  /* Channel A Compare Output Value bit position. */

#define TC5_HCMPB_bm  0x20  /* High Channel B Compare Output Value bit mask. */
#define TC5_HCMPB_bp  5  /* High Channel B Compare Output Value bit position. */

#define TC5_HCMPA_bm  0x10  /* High Channel A Compare Output Value bit mask. */
#define TC5_HCMPA_bp  4  /* High Channel A Compare Output Value bit position. */

#define TC5_LCMPB_bm  0x02  /* Low Channel B Compare Output Value bit mask. */
#define TC5_LCMPB_bp  1  /* Low Channel B Compare Output Value bit position. */

#define TC5_LCMPA_bm  0x01  /* Low Channel A Compare Output Value bit mask. */
#define TC5_LCMPA_bp  0  /* Low Channel A Compare Output Value bit position. */

/* TC5.CTRLD  bit masks and bit positions */
#define TC5_EVACT_gm  0xE0  /* Event Action group mask. */
#define TC5_EVACT_gp  5  /* Event Action group position. */
#define TC5_EVACT0_bm  (1<<5)  /* Event Action bit 0 mask. */
#define TC5_EVACT0_bp  5  /* Event Action bit 0 position. */
#define TC5_EVACT1_bm  (1<<6)  /* Event Action bit 1 mask. */
#define TC5_EVACT1_bp  6  /* Event Action bit 1 position. */
#define TC5_EVACT2_bm  (1<<7)  /* Event Action bit 2 mask. */
#define TC5_EVACT2_bp  7  /* Event Action bit 2 position. */

#define TC5_EVDLY_bm  0x10  /* Event Delay bit mask. */
#define TC5_EVDLY_bp  4  /* Event Delay bit position. */

#define TC5_EVSEL_gm  0x0F  /* Event Source Select group mask. */
#define TC5_EVSEL_gp  0  /* Event Source Select group position. */
#define TC5_EVSEL0_bm  (1<<0)  /* Event Source Select bit 0 mask. */
#define TC5_EVSEL0_bp  0  /* Event Source Select bit 0 position. */
#define TC5_EVSEL1_bm  (1<<1)  /* Event Source Select bit 1 mask. */
#define TC5_EVSEL1_bp  1  /* Event Source Select bit 1 position. */
#define TC5_EVSEL2_bm  (1<<2)  /* Event Source Select bit 2 mask. */
#define TC5_EVSEL2_bp  2  /* Event Source Select bit 2 position. */
#define TC5_EVSEL3_bm  (1<<3)  /* Event Source Select bit 3 mask. */
#define TC5_EVSEL3_bp  3  /* Event Source Select bit 3 position. */

/* TC5.CTRLE  bit masks and bit positions */
#define TC5_CCBMODE_gm  0x0C  /* Channel B Compare or Capture Mode group mask. */
#define TC5_CCBMODE_gp  2  /* Channel B Compare or Capture Mode group position. */
#define TC5_CCBMODE0_bm  (1<<2)  /* Channel B Compare or Capture Mode bit 0 mask. */
#define TC5_CCBMODE0_bp  2  /* Channel B Compare or Capture Mode bit 0 position. */
#define TC5_CCBMODE1_bm  (1<<3)  /* Channel B Compare or Capture Mode bit 1 mask. */
#define TC5_CCBMODE1_bp  3  /* Channel B Compare or Capture Mode bit 1 position. */

#define TC5_CCAMODE_gm  0x03  /* Channel A Compare or Capture Mode group mask. */
#define TC5_CCAMODE_gp  0  /* Channel A Compare or Capture Mode group position. */
#define TC5_CCAMODE0_bm  (1<<0)  /* Channel A Compare or Capture Mode bit 0 mask. */
#define TC5_CCAMODE0_bp  0  /* Channel A Compare or Capture Mode bit 0 position. */
#define TC5_CCAMODE1_bm  (1<<1)  /* Channel A Compare or Capture Mode bit 1 mask. */
#define TC5_CCAMODE1_bp  1  /* Channel A Compare or Capture Mode bit 1 position. */

#define TC5_LCCBMODE_gm  0x0C  /* Channel Low B Compare or Capture Mode group mask. */
#define TC5_LCCBMODE_gp  2  /* Channel Low B Compare or Capture Mode group position. */
#define TC5_LCCBMODE0_bm  (1<<2)  /* Channel Low B Compare or Capture Mode bit 0 mask. */
#define TC5_LCCBMODE0_bp  2  /* Channel Low B Compare or Capture Mode bit 0 position. */
#define TC5_LCCBMODE1_bm  (1<<3)  /* Channel Low B Compare or Capture Mode bit 1 mask. */
#define TC5_LCCBMODE1_bp  3  /* Channel Low B Compare or Capture Mode bit 1 position. */

#define TC5_LCCAMODE_gm  0x03  /* Channel Low A Compare or Capture Mode group mask. */
#define TC5_LCCAMODE_gp  0  /* Channel Low A Compare or Capture Mode group position. */
#define TC5_LCCAMODE0_bm  (1<<0)  /* Channel Low A Compare or Capture Mode bit 0 mask. */
#define TC5_LCCAMODE0_bp  0  /* Channel Low A Compare or Capture Mode bit 0 position. */
#define TC5_LCCAMODE1_bm  (1<<1)  /* Channel Low A Compare or Capture Mode bit 1 mask. */
#define TC5_LCCAMODE1_bp  1  /* Channel Low A Compare or Capture Mode bit 1 position. */

/* TC5.CTRLF  bit masks and bit positions */
#define TC5_HCCBMODE_gm  0x0C  /* Channel High B Compare or Capture Mode group mask. */
#define TC5_HCCBMODE_gp  2  /* Channel High B Compare or Capture Mode group position. */
#define TC5_HCCBMODE0_bm  (1<<2)  /* Channel High B Compare or Capture Mode bit 0 mask. */
#define TC5_HCCBMODE0_bp  2  /* Channel High B Compare or Capture Mode bit 0 position. */
#define TC5_HCCBMODE1_bm  (1<<3)  /* Channel High B Compare or Capture Mode bit 1 mask. */
#define TC5_HCCBMODE1_bp  3  /* Channel High B Compare or Capture Mode bit 1 position. */

#define TC5_HCCAMODE_gm  0x03  /* Channel High A Compare or Capture Mode group mask. */
#define TC5_HCCAMODE_gp  0  /* Channel High A Compare or Capture Mode group position. */
#define TC5_HCCAMODE0_bm  (1<<0)  /* Channel High A Compare or Capture Mode bit 0 mask. */
#define TC5_HCCAMODE0_bp  0  /* Channel High A Compare or Capture Mode bit 0 position. */
#define TC5_HCCAMODE1_bm  (1<<1)  /* Channel High A Compare or Capture Mode bit 1 mask. */
#define TC5_HCCAMODE1_bp  1  /* Channel High A Compare or Capture Mode bit 1 position. */

/* TC5.INTCTRLA  bit masks and bit positions */
#define TC5_TRGINTLVL_gm  0x30  /* Timer Trigger Restart Interrupt Level group mask. */
#define TC5_TRGINTLVL_gp  4  /* Timer Trigger Restart Interrupt Level group position. */
#define TC5_TRGINTLVL0_bm  (1<<4)  /* Timer Trigger Restart Interrupt Level bit 0 mask. */
#define TC5_TRGINTLVL0_bp  4  /* Timer Trigger Restart Interrupt Level bit 0 position. */
#define TC5_TRGINTLVL1_bm  (1<<5)  /* Timer Trigger Restart Interrupt Level bit 1 mask. */
#define TC5_TRGINTLVL1_bp  5  /* Timer Trigger Restart Interrupt Level bit 1 position. */

#define TC5_ERRINTLVL_gm  0x0C  /* Timer Error Interrupt Level group mask. */
#define TC5_ERRINTLVL_gp  2  /* Timer Error Interrupt Level group position. */
#define TC5_ERRINTLVL0_bm  (1<<2)  /* Timer Error Interrupt Level bit 0 mask. */
#define TC5_ERRINTLVL0_bp  2  /* Timer Error Interrupt Level bit 0 position. */
#define TC5_ERRINTLVL1_bm  (1<<3)  /* Timer Error Interrupt Level bit 1 mask. */
#define TC5_ERRINTLVL1_bp  3  /* Timer Error Interrupt Level bit 1 position. */

#define TC5_OVFINTLVL_gm  0x03  /* Timer Overflow/Underflow Interrupt Level group mask. */
#define TC5_OVFINTLVL_gp  0  /* Timer Overflow/Underflow Interrupt Level group position. */
#define TC5_OVFINTLVL0_bm  (1<<0)  /* Timer Overflow/Underflow Interrupt Level bit 0 mask. */
#define TC5_OVFINTLVL0_bp  0  /* Timer Overflow/Underflow Interrupt Level bit 0 position. */
#define TC5_OVFINTLVL1_bm  (1<<1)  /* Timer Overflow/Underflow Interrupt Level bit 1 mask. */
#define TC5_OVFINTLVL1_bp  1  /* Timer Overflow/Underflow Interrupt Level bit 1 position. */

/* TC5.INTCTRLB  bit masks and bit positions */
#define TC5_CCBINTLVL_gm  0x0C  /* Channel B Compare or Capture Interrupt Level group mask. */
#define TC5_CCBINTLVL_gp  2  /* Channel B Compare or Capture Interrupt Level group position. */
#define TC5_CCBINTLVL0_bm  (1<<2)  /* Channel B Compare or Capture Interrupt Level bit 0 mask. */
#define TC5_CCBINTLVL0_bp  2  /* Channel B Compare or Capture Interrupt Level bit 0 position. */
#define TC5_CCBINTLVL1_bm  (1<<3)  /* Channel B Compare or Capture Interrupt Level bit 1 mask. */
#define TC5_CCBINTLVL1_bp  3  /* Channel B Compare or Capture Interrupt Level bit 1 position. */

#define TC5_CCAINTLVL_gm  0x03  /* Channel A Compare or Capture Interrupt Level group mask. */
#define TC5_CCAINTLVL_gp  0  /* Channel A Compare or Capture Interrupt Level group position. */
#define TC5_CCAINTLVL0_bm  (1<<0)  /* Channel A Compare or Capture Interrupt Level bit 0 mask. */
#define TC5_CCAINTLVL0_bp  0  /* Channel A Compare or Capture Interrupt Level bit 0 position. */
#define TC5_CCAINTLVL1_bm  (1<<1)  /* Channel A Compare or Capture Interrupt Level bit 1 mask. */
#define TC5_CCAINTLVL1_bp  1  /* Channel A Compare or Capture Interrupt Level bit 1 position. */

#define TC5_LCCBINTLVL_gm  0x0C  /* Channel Low B Compare or Capture Interrupt Level group mask. */
#define TC5_LCCBINTLVL_gp  2  /* Channel Low B Compare or Capture Interrupt Level group position. */
#define TC5_LCCBINTLVL0_bm  (1<<2)  /* Channel Low B Compare or Capture Interrupt Level bit 0 mask. */
#define TC5_LCCBINTLVL0_bp  2  /* Channel Low B Compare or Capture Interrupt Level bit 0 position. */
#define TC5_LCCBINTLVL1_bm  (1<<3)  /* Channel Low B Compare or Capture Interrupt Level bit 1 mask. */
#define TC5_LCCBINTLVL1_bp  3  /* Channel Low B Compare or Capture Interrupt Level bit 1 position. */

#define TC5_LCCAINTLVL_gm  0x03  /* Channel Low A Compare or Capture Interrupt Level group mask. */
#define TC5_LCCAINTLVL_gp  0  /* Channel Low A Compare or Capture Interrupt Level group position. */
#define TC5_LCCAINTLVL0_bm  (1<<0)  /* Channel Low A Compare or Capture Interrupt Level bit 0 mask. */
#define TC5_LCCAINTLVL0_bp  0  /* Channel Low A Compare or Capture Interrupt Level bit 0 position. */
#define TC5_LCCAINTLVL1_bm  (1<<1)  /* Channel Low A Compare or Capture Interrupt Level bit 1 mask. */
#define TC5_LCCAINTLVL1_bp  1  /* Channel Low A Compare or Capture Interrupt Level bit 1 position. */

/* TC5.CTRLGCLR  bit masks and bit positions */
#define TC5_STOP_bm  0x20  /* Timer/Counter Stop bit mask. */
#define TC5_STOP_bp  5  /* Timer/Counter Stop bit position. */

#define TC5_CMD_gm  0x0C  /* Command group mask. */
#define TC5_CMD_gp  2  /* Command group position. */
#define TC5_CMD0_bm  (1<<2)  /* Command bit 0 mask. */
#define TC5_CMD0_bp  2  /* Command bit 0 position. */
#define TC5_CMD1_bm  (1<<3)  /* Command bit 1 mask. */
#define TC5_CMD1_bp  3  /* Command bit 1 position. */

#define TC5_LUPD_bm  0x02  /* Lock Update bit mask. */
#define TC5_LUPD_bp  1  /* Lock Update bit position. */

#define TC5_DIR_bm  0x01  /* Counter Direction bit mask. */
#define TC5_DIR_bp  0  /* Counter Direction bit position. */

/* TC5.CTRLGSET  bit masks and bit positions */
/* TC5_STOP  Predefined. */
/* TC5_STOP  Predefined. */

/* TC5_CMD  Predefined. */
/* TC5_CMD  Predefined. */

/* TC5_LUPD  Predefined. */
/* TC5_LUPD  Predefined. */

/* TC5_DIR  Predefined. */
/* TC5_DIR  Predefined. */

/* TC5.CTRLHCLR  bit masks and bit positions */
#define TC5_CCBBV_bm  0x04  /* Channel B Compare or Capture Buffer Valid bit mask. */
#define TC5_CCBBV_bp  2  /* Channel B Compare or Capture Buffer Valid bit position. */

#define TC5_CCABV_bm  0x02  /* Channel A Compare or Capture Buffer Valid bit mask. */
#define TC5_CCABV_bp  1  /* Channel A Compare or Capture Buffer Valid bit position. */

#define TC5_PERBV_bm  0x01  /* Period Buffer Valid bit mask. */
#define TC5_PERBV_bp  0  /* Period Buffer Valid bit position. */

#define TC5_LCCBBV_bm  0x04  /* Channel Low B Compare or Capture Buffer Valid bit mask. */
#define TC5_LCCBBV_bp  2  /* Channel Low B Compare or Capture Buffer Valid bit position. */

#define TC5_LCCABV_bm  0x02  /* Channel Low A Compare or Capture Buffer Valid bit mask. */
#define TC5_LCCABV_bp  1  /* Channel Low A Compare or Capture Buffer Valid bit position. */

#define TC5_LPERBV_bm  0x01  /* Period Low Buffer Valid bit mask. */
#define TC5_LPERBV_bp  0  /* Period Low Buffer Valid bit position. */

/* TC5.CTRLHSET  bit masks and bit positions */
/* TC5_CCBBV  Predefined. */
/* TC5_CCBBV  Predefined. */

/* TC5_CCABV  Predefined. */
/* TC5_CCABV  Predefined. */

/* TC5_PERBV  Predefined. */
/* TC5_PERBV  Predefined. */

/* TC5_LCCBBV  Predefined. */
/* TC5_LCCBBV  Predefined. */

/* TC5_LCCABV  Predefined. */
/* TC5_LCCABV  Predefined. */

/* TC5_LPERBV  Predefined. */
/* TC5_LPERBV  Predefined. */

/* TC5.INTFLAGS  bit masks and bit positions */
#define TC5_CCBIF_bm  0x20  /* Channel B Compare or Capture Interrupt Flag bit mask. */
#define TC5_CCBIF_bp  5  /* Channel B Compare or Capture Interrupt Flag bit position. */

#define TC5_CCAIF_bm  0x10  /* Channel A Compare or Capture Interrupt Flag bit mask. */
#define TC5_CCAIF_bp  4  /* Channel A Compare or Capture Interrupt Flag bit position. */

#define TC5_TRGIF_bm  0x04  /* Trigger Restart Interrupt Flag bit mask. */
#define TC5_TRGIF_bp  2  /* Trigger Restart Interrupt Flag bit position. */

#define TC5_ERRIF_bm  0x02  /* Error Interrupt Flag bit mask. */
#define TC5_ERRIF_bp  1  /* Error Interrupt Flag bit position. */

#define TC5_OVFIF_bm  0x01  /* Overflow/Underflow Interrupt Flag bit mask. */
#define TC5_OVFIF_bp  0  /* Overflow/Underflow Interrupt Flag bit position. */

#define TC5_LCCBIF_bm  0x20  /* Channel Low B Compare or Capture Interrupt Flag bit mask. */
#define TC5_LCCBIF_bp  5  /* Channel Low B Compare or Capture Interrupt Flag bit position. */

#define TC5_LCCAIF_bm  0x10  /* Channel Low A Compare or Capture Interrupt Flag bit mask. */
#define TC5_LCCAIF_bp  4  /* Channel Low A Compare or Capture Interrupt Flag bit position. */

/* FAULT - Fault Extension */
/* FAULT.CTRLA  bit masks and bit positions */
#define FAULT_RAMP_gm  0xC0  /* Ramp Mode Selection group mask. */
#define FAULT_RAMP_gp  6  /* Ramp Mode Selection group position. */
#define FAULT_RAMP0_bm  (1<<6)  /* Ramp Mode Selection bit 0 mask. */
#define FAULT_RAMP0_bp  6  /* Ramp Mode Selection bit 0 position. */
#define FAULT_RAMP1_bm  (1<<7)  /* Ramp Mode Selection bit 1 mask. */
#define FAULT_RAMP1_bp  7  /* Ramp Mode Selection bit 1 position. */

#define FAULT_FDDBD_bm  0x20  /* Fault on Debug Break Detection bit mask. */
#define FAULT_FDDBD_bp  5  /* Fault on Debug Break Detection bit position. */

#define FAULT_PORTCTRL_bm  0x10  /* Port Control Mode bit mask. */
#define FAULT_PORTCTRL_bp  4  /* Port Control Mode bit position. */

#define FAULT_FUSE_bm  0x08  /* Fuse State  bit mask. */
#define FAULT_FUSE_bp  3  /* Fuse State  bit position. */

#define FAULT_FILTERE_bm  0x04  /* Fault E Digital Filter Selection bit mask. */
#define FAULT_FILTERE_bp  2  /* Fault E Digital Filter Selection bit position. */

#define FAULT_SRCE_gm  0x03  /* Fault E Input selection group mask. */
#define FAULT_SRCE_gp  0  /* Fault E Input selection group position. */
#define FAULT_SRCE0_bm  (1<<0)  /* Fault E Input selection bit 0 mask. */
#define FAULT_SRCE0_bp  0  /* Fault E Input selection bit 0 position. */
#define FAULT_SRCE1_bm  (1<<1)  /* Fault E Input selection bit 1 mask. */
#define FAULT_SRCE1_bp  1  /* Fault E Input selection bit 1 position. */

/* FAULT.CTRLB  bit masks and bit positions */
#define FAULT_SOFTA_bm  0x80  /* Fault A Software Mode bit mask. */
#define FAULT_SOFTA_bp  7  /* Fault A Software Mode bit position. */

#define FAULT_HALTA_gm  0x60  /* Fault A Halt Action group mask. */
#define FAULT_HALTA_gp  5  /* Fault A Halt Action group position. */
#define FAULT_HALTA0_bm  (1<<5)  /* Fault A Halt Action bit 0 mask. */
#define FAULT_HALTA0_bp  5  /* Fault A Halt Action bit 0 position. */
#define FAULT_HALTA1_bm  (1<<6)  /* Fault A Halt Action bit 1 mask. */
#define FAULT_HALTA1_bp  6  /* Fault A Halt Action bit 1 position. */

#define FAULT_RESTARTA_bm  0x10  /* Fault A Restart Action bit mask. */
#define FAULT_RESTARTA_bp  4  /* Fault A Restart Action bit position. */

#define FAULT_KEEPA_bm  0x08  /* Fault A Keep Action bit mask. */
#define FAULT_KEEPA_bp  3  /* Fault A Keep Action bit position. */

#define FAULT_SRCA_gm  0x03  /* Fault A Source Selection group mask. */
#define FAULT_SRCA_gp  0  /* Fault A Source Selection group position. */
#define FAULT_SRCA0_bm  (1<<0)  /* Fault A Source Selection bit 0 mask. */
#define FAULT_SRCA0_bp  0  /* Fault A Source Selection bit 0 position. */
#define FAULT_SRCA1_bm  (1<<1)  /* Fault A Source Selection bit 1 mask. */
#define FAULT_SRCA1_bp  1  /* Fault A Source Selection bit 1 position. */

/* FAULT.CTRLC  bit masks and bit positions */
#define FAULT_CAPTA_bm  0x20  /* Fault A Capture bit mask. */
#define FAULT_CAPTA_bp  5  /* Fault A Capture bit position. */

#define FAULT_FILTERA_bm  0x04  /* Fault A Digital Filter Selection bit mask. */
#define FAULT_FILTERA_bp  2  /* Fault A Digital Filter Selection bit position. */

#define FAULT_BLANKA_bm  0x02  /* Fault A Blanking bit mask. */
#define FAULT_BLANKA_bp  1  /* Fault A Blanking bit position. */

#define FAULT_QUALA_bm  0x01  /* Fault A Qualification bit mask. */
#define FAULT_QUALA_bp  0  /* Fault A Qualification bit position. */

/* FAULT.CTRLD  bit masks and bit positions */
#define FAULT_SOFTB_bm  0x80  /* Fault B Software Mode bit mask. */
#define FAULT_SOFTB_bp  7  /* Fault B Software Mode bit position. */

#define FAULT_HALTB_gm  0x60  /* Fault B Halt Action group mask. */
#define FAULT_HALTB_gp  5  /* Fault B Halt Action group position. */
#define FAULT_HALTB0_bm  (1<<5)  /* Fault B Halt Action bit 0 mask. */
#define FAULT_HALTB0_bp  5  /* Fault B Halt Action bit 0 position. */
#define FAULT_HALTB1_bm  (1<<6)  /* Fault B Halt Action bit 1 mask. */
#define FAULT_HALTB1_bp  6  /* Fault B Halt Action bit 1 position. */

#define FAULT_RESTARTB_bm  0x10  /* Fault B Restart Action bit mask. */
#define FAULT_RESTARTB_bp  4  /* Fault B Restart Action bit position. */

#define FAULT_KEEPB_bm  0x08  /* Fault B Keep Action bit mask. */
#define FAULT_KEEPB_bp  3  /* Fault B Keep Action bit position. */

#define FAULT_SRCB_gm  0x03  /* Fault B Source Selection group mask. */
#define FAULT_SRCB_gp  0  /* Fault B Source Selection group position. */
#define FAULT_SRCB0_bm  (1<<0)  /* Fault B Source Selection bit 0 mask. */
#define FAULT_SRCB0_bp  0  /* Fault B Source Selection bit 0 position. */
#define FAULT_SRCB1_bm  (1<<1)  /* Fault B Source Selection bit 1 mask. */
#define FAULT_SRCB1_bp  1  /* Fault B Source Selection bit 1 position. */

/* FAULT.CTRLE  bit masks and bit positions */
#define FAULT_CAPTB_bm  0x20  /* Fault B Capture bit mask. */
#define FAULT_CAPTB_bp  5  /* Fault B Capture bit position. */

#define FAULT_FILTERB_bm  0x04  /* Fault B Digital Filter Selection bit mask. */
#define FAULT_FILTERB_bp  2  /* Fault B Digital Filter Selection bit position. */

#define FAULT_BLANKB_bm  0x02  /* Fault B Blanking bit mask. */
#define FAULT_BLANKB_bp  1  /* Fault B Blanking bit position. */

#define FAULT_QUALB_bm  0x01  /* Fault B Qualification bit mask. */
#define FAULT_QUALB_bp  0  /* Fault B Qualification bit position. */

/* FAULT.STATUS  bit masks and bit positions */
#define FAULT_STATEB_bm  0x80  /* Fault B State bit mask. */
#define FAULT_STATEB_bp  7  /* Fault B State bit position. */

#define FAULT_STATEA_bm  0x40  /* Fault A State bit mask. */
#define FAULT_STATEA_bp  6  /* Fault A State bit position. */

#define FAULT_STATEE_bm  0x20  /* Fault E State bit mask. */
#define FAULT_STATEE_bp  5  /* Fault E State bit position. */

#define FAULT_IDX_bm  0x08  /* Channel Index Flag bit mask. */
#define FAULT_IDX_bp  3  /* Channel Index Flag bit position. */

#define FAULT_FAULTBIN_bm  0x04  /* Fault B Flag bit mask. */
#define FAULT_FAULTBIN_bp  2  /* Fault B Flag bit position. */

#define FAULT_FAULTAIN_bm  0x02  /* Fault A Flag bit mask. */
#define FAULT_FAULTAIN_bp  1  /* Fault A Flag bit position. */

#define FAULT_FAULTEIN_bm  0x01  /* Fault E Flag bit mask. */
#define FAULT_FAULTEIN_bp  0  /* Fault E Flag bit position. */

/* FAULT.CTRLGCLR  bit masks and bit positions */
#define FAULT_HALTBCLR_bm  0x80  /* State B Clear bit mask. */
#define FAULT_HALTBCLR_bp  7  /* State B Clear bit position. */

#define FAULT_HALTACLR_bm  0x40  /* State A Clear bit mask. */
#define FAULT_HALTACLR_bp  6  /* State A Clear bit position. */

#define FAULT_STATEECLR_bm  0x20  /* State E Clear bit mask. */
#define FAULT_STATEECLR_bp  5  /* State E Clear bit position. */

#define FAULT_FAULTB_bm  0x04  /* Fault B Flag bit mask. */
#define FAULT_FAULTB_bp  2  /* Fault B Flag bit position. */

#define FAULT_FAULTA_bm  0x02  /* Fault A Flag bit mask. */
#define FAULT_FAULTA_bp  1  /* Fault A Flag bit position. */

#define FAULT_FAULTE_bm  0x01  /* Fault E Flag bit mask. */
#define FAULT_FAULTE_bp  0  /* Fault E Flag bit position. */

/* FAULT.CTRLGSET  bit masks and bit positions */
#define FAULT_FAULTBSW_bm  0x80  /* Software Fault B bit mask. */
#define FAULT_FAULTBSW_bp  7  /* Software Fault B bit position. */

#define FAULT_FAULTASW_bm  0x40  /* Software Fault A bit mask. */
#define FAULT_FAULTASW_bp  6  /* Software Fault A bit position. */

#define FAULT_FAULTESW_bm  0x20  /* Software Fault E bit mask. */
#define FAULT_FAULTESW_bp  5  /* Software Fault E bit position. */

#define FAULT_IDXCMD_gm  0x18  /* Channel index Command group mask. */
#define FAULT_IDXCMD_gp  3  /* Channel index Command group position. */
#define FAULT_IDXCMD0_bm  (1<<3)  /* Channel index Command bit 0 mask. */
#define FAULT_IDXCMD0_bp  3  /* Channel index Command bit 0 position. */
#define FAULT_IDXCMD1_bm  (1<<4)  /* Channel index Command bit 1 mask. */
#define FAULT_IDXCMD1_bp  4  /* Channel index Command bit 1 position. */

/* WEX - Waveform Extension */
/* WEX.CTRL  bit masks and bit positions */
#define WEX_UPSEL_bm  0x80  /* Update Source Selection bit mask. */
#define WEX_UPSEL_bp  7  /* Update Source Selection bit position. */

#define WEX_OTMX_gm  0x70  /* Output Matrix group mask. */
#define WEX_OTMX_gp  4  /* Output Matrix group position. */
#define WEX_OTMX0_bm  (1<<4)  /* Output Matrix bit 0 mask. */
#define WEX_OTMX0_bp  4  /* Output Matrix bit 0 position. */
#define WEX_OTMX1_bm  (1<<5)  /* Output Matrix bit 1 mask. */
#define WEX_OTMX1_bp  5  /* Output Matrix bit 1 position. */
#define WEX_OTMX2_bm  (1<<6)  /* Output Matrix bit 2 mask. */
#define WEX_OTMX2_bp  6  /* Output Matrix bit 2 position. */

#define WEX_DTI3EN_bm  0x08  /* Dead-Time Insertion Generator 3 Enable bit mask. */
#define WEX_DTI3EN_bp  3  /* Dead-Time Insertion Generator 3 Enable bit position. */

#define WEX_DTI2EN_bm  0x04  /* Dead-Time Insertion Generator 2 Enable bit mask. */
#define WEX_DTI2EN_bp  2  /* Dead-Time Insertion Generator 2 Enable bit position. */

#define WEX_DTI1EN_bm  0x02  /* Dead-Time Insertion Generator 1 Enable bit mask. */
#define WEX_DTI1EN_bp  1  /* Dead-Time Insertion Generator 1 Enable bit position. */

#define WEX_DTI0EN_bm  0x01  /* Dead-Time Insertion Generator 0 Enable bit mask. */
#define WEX_DTI0EN_bp  0  /* Dead-Time Insertion Generator 0 Enable bit position. */

/* WEX.STATUSCLR  bit masks and bit positions */
#define WEX_SWAPBUF_bm  0x04  /* Swap Buffer Valid  bit mask. */
#define WEX_SWAPBUF_bp  2  /* Swap Buffer Valid  bit position. */

#define WEX_PGVBUFV_bm  0x02  /* Pattern Generator Value Buffer Valid  bit mask. */
#define WEX_PGVBUFV_bp  1  /* Pattern Generator Value Buffer Valid  bit position. */

#define WEX_PGOBUFV_bm  0x01  /* Pattern Generator Overwrite Buffer Valid bit mask. */
#define WEX_PGOBUFV_bp  0  /* Pattern Generator Overwrite Buffer Valid bit position. */

/* WEX.STATUSSET  bit masks and bit positions */
/* WEX_SWAPBUF  Predefined. */
/* WEX_SWAPBUF  Predefined. */

/* WEX_PGVBUFV  Predefined. */
/* WEX_PGVBUFV  Predefined. */

/* WEX_PGOBUFV  Predefined. */
/* WEX_PGOBUFV  Predefined. */

/* WEX.SWAP  bit masks and bit positions */
#define WEX_SWAP3_bm  0x08  /* Swap DTI output pair 3 bit mask. */
#define WEX_SWAP3_bp  3  /* Swap DTI output pair 3 bit position. */

#define WEX_SWAP2_bm  0x04  /* Swap DTI output pair 2 bit mask. */
#define WEX_SWAP2_bp  2  /* Swap DTI output pair 2 bit position. */

#define WEX_SWAP1_bm  0x02  /* Swap DTI output pair 1 bit mask. */
#define WEX_SWAP1_bp  1  /* Swap DTI output pair 1 bit position. */

#define WEX_SWAP0_bm  0x01  /* Swap DTI output pair 0 bit mask. */
#define WEX_SWAP0_bp  0  /* Swap DTI output pair 0 bit position. */

/* WEX.SWAPBUF  bit masks and bit positions */
#define WEX_SWAP3BUF_bm  0x08  /* Swap DTI output pair 3  bit mask. */
#define WEX_SWAP3BUF_bp  3  /* Swap DTI output pair 3  bit position. */

#define WEX_SWAP2BUF_bm  0x04  /* Swap DTI output pair 2 bit mask. */
#define WEX_SWAP2BUF_bp  2  /* Swap DTI output pair 2 bit position. */

#define WEX_SWAP1BUF_bm  0x02  /* Swap DTI output pair 1  bit mask. */
#define WEX_SWAP1BUF_bp  1  /* Swap DTI output pair 1  bit position. */

#define WEX_SWAP0BUF_bm  0x01  /* Swap DTI output pair 0 bit mask. */
#define WEX_SWAP0BUF_bp  0  /* Swap DTI output pair 0 bit position. */

/* HIRES - High-Resolution Extension */
/* HIRES.CTRLA  bit masks and bit positions */
#define HIRES_HRPLUS_gm  0x0C  /* High Resolution Plus group mask. */
#define HIRES_HRPLUS_gp  2  /* High Resolution Plus group position. */
#define HIRES_HRPLUS0_bm  (1<<2)  /* High Resolution Plus bit 0 mask. */
#define HIRES_HRPLUS0_bp  2  /* High Resolution Plus bit 0 position. */
#define HIRES_HRPLUS1_bm  (1<<3)  /* High Resolution Plus bit 1 mask. */
#define HIRES_HRPLUS1_bp  3  /* High Resolution Plus bit 1 position. */

#define HIRES_HREN_gm  0x03  /* High Resolution Mode group mask. */
#define HIRES_HREN_gp  0  /* High Resolution Mode group position. */
#define HIRES_HREN0_bm  (1<<0)  /* High Resolution Mode bit 0 mask. */
#define HIRES_HREN0_bp  0  /* High Resolution Mode bit 0 position. */
#define HIRES_HREN1_bm  (1<<1)  /* High Resolution Mode bit 1 mask. */
#define HIRES_HREN1_bp  1  /* High Resolution Mode bit 1 position. */

/* USART - Universal Asynchronous Receiver-Transmitter */
/* USART.STATUS  bit masks and bit positions */
#define USART_RXCIF_bm  0x80  /* Receive Interrupt Flag bit mask. */
#define USART_RXCIF_bp  7  /* Receive Interrupt Flag bit position. */

#define USART_TXCIF_bm  0x40  /* Transmit Interrupt Flag bit mask. */
#define USART_TXCIF_bp  6  /* Transmit Interrupt Flag bit position. */

#define USART_DREIF_bm  0x20  /* Data Register Empty Flag bit mask. */
#define USART_DREIF_bp  5  /* Data Register Empty Flag bit position. */

#define USART_FERR_bm  0x10  /* Frame Error bit mask. */
#define USART_FERR_bp  4  /* Frame Error bit position. */

#define USART_BUFOVF_bm  0x08  /* Buffer Overflow bit mask. */
#define USART_BUFOVF_bp  3  /* Buffer Overflow bit position. */

#define USART_PERR_bm  0x04  /* Parity Error bit mask. */
#define USART_PERR_bp  2  /* Parity Error bit position. */

#define USART_RXSIF_bm  0x02  /* Receive Start Bit Interrupt Flag bit mask. */
#define USART_RXSIF_bp  1  /* Receive Start Bit Interrupt Flag bit position. */

#define USART_RXB8_bm  0x01  /* Receive Bit 8 bit mask. */
#define USART_RXB8_bp  0  /* Receive Bit 8 bit position. */

#define USART_DRIF_bm  0x01  /* Data Reception Flag bit mask. */
#define USART_DRIF_bp  0  /* Data Reception Flag bit position. */

/* USART.CTRLA  bit masks and bit positions */
#define USART_RXSIE_bm  0x80  /* Receive Start Interrupt Enable bit mask. */
#define USART_RXSIE_bp  7  /* Receive Start Interrupt Enable bit position. */

#define USART_DRIE_bm  0x40  /* Data Reception Interrupt Enable bit mask. */
#define USART_DRIE_bp  6  /* Data Reception Interrupt Enable bit position. */

#define USART_RXCINTLVL_gm  0x30  /* Receive Interrupt Level group mask. */
#define USART_RXCINTLVL_gp  4  /* Receive Interrupt Level group position. */
#define USART_RXCINTLVL0_bm  (1<<4)  /* Receive Interrupt Level bit 0 mask. */
#define USART_RXCINTLVL0_bp  4  /* Receive Interrupt Level bit 0 position. */
#define USART_RXCINTLVL1_bm  (1<<5)  /* Receive Interrupt Level bit 1 mask. */
#define USART_RXCINTLVL1_bp  5  /* Receive Interrupt Level bit 1 position. */

#define USART_TXCINTLVL_gm  0x0C  /* Transmit Interrupt Level group mask. */
#define USART_TXCINTLVL_gp  2  /* Transmit Interrupt Level group position. */
#define USART_TXCINTLVL0_bm  (1<<2)  /* Transmit Interrupt Level bit 0 mask. */
#define USART_TXCINTLVL0_bp  2  /* Transmit Interrupt Level bit 0 position. */
#define USART_TXCINTLVL1_bm  (1<<3)  /* Transmit Interrupt Level bit 1 mask. */
#define USART_TXCINTLVL1_bp  3  /* Transmit Interrupt Level bit 1 position. */

#define USART_DREINTLVL_gm  0x03  /* Data Register Empty Interrupt Level group mask. */
#define USART_DREINTLVL_gp  0  /* Data Register Empty Interrupt Level group position. */
#define USART_DREINTLVL0_bm  (1<<0)  /* Data Register Empty Interrupt Level bit 0 mask. */
#define USART_DREINTLVL0_bp  0  /* Data Register Empty Interrupt Level bit 0 position. */
#define USART_DREINTLVL1_bm  (1<<1)  /* Data Register Empty Interrupt Level bit 1 mask. */
#define USART_DREINTLVL1_bp  1  /* Data Register Empty Interrupt Level bit 1 position. */

/* USART.CTRLB  bit masks and bit positions */
#define USART_ONEWIRE_bm  0x80  /* One Wire Mode bit mask. */
#define USART_ONEWIRE_bp  7  /* One Wire Mode bit position. */

#define USART_SFDEN_bm  0x40  /* Start Frame Detection Enable bit mask. */
#define USART_SFDEN_bp  6  /* Start Frame Detection Enable bit position. */

#define USART_RXEN_bm  0x10  /* Receiver Enable bit mask. */
#define USART_RXEN_bp  4  /* Receiver Enable bit position. */

#define USART_TXEN_bm  0x08  /* Transmitter Enable bit mask. */
#define USART_TXEN_bp  3  /* Transmitter Enable bit position. */

#define USART_CLK2X_bm  0x04  /* Double transmission speed bit mask. */
#define USART_CLK2X_bp  2  /* Double transmission speed bit position. */

#define USART_MPCM_bm  0x02  /* Multi-processor Communication Mode bit mask. */
#define USART_MPCM_bp  1  /* Multi-processor Communication Mode bit position. */

#define USART_TXB8_bm  0x01  /* Transmit bit 8 bit mask. */
#define USART_TXB8_bp  0  /* Transmit bit 8 bit position. */

/* USART.CTRLC  bit masks and bit positions */
#define USART_CMODE_gm  0xC0  /* Communication Mode group mask. */
#define USART_CMODE_gp  6  /* Communication Mode group position. */
#define USART_CMODE0_bm  (1<<6)  /* Communication Mode bit 0 mask. */
#define USART_CMODE0_bp  6  /* Communication Mode bit 0 position. */
#define USART_CMODE1_bm  (1<<7)  /* Communication Mode bit 1 mask. */
#define USART_CMODE1_bp  7  /* Communication Mode bit 1 position. */

#define USART_PMODE_gm  0x30  /* Parity Mode group mask. */
#define USART_PMODE_gp  4  /* Parity Mode group position. */
#define USART_PMODE0_bm  (1<<4)  /* Parity Mode bit 0 mask. */
#define USART_PMODE0_bp  4  /* Parity Mode bit 0 position. */
#define USART_PMODE1_bm  (1<<5)  /* Parity Mode bit 1 mask. */
#define USART_PMODE1_bp  5  /* Parity Mode bit 1 position. */

#define USART_SBMODE_bm  0x08  /* Stop Bit Mode bit mask. */
#define USART_SBMODE_bp  3  /* Stop Bit Mode bit position. */

#define USART_CHSIZE_gm  0x07  /* Character Size group mask. */
#define USART_CHSIZE_gp  0  /* Character Size group position. */
#define USART_CHSIZE0_bm  (1<<0)  /* Character Size bit 0 mask. */
#define USART_CHSIZE0_bp  0  /* Character Size bit 0 position. */
#define USART_CHSIZE1_bm  (1<<1)  /* Character Size bit 1 mask. */
#define USART_CHSIZE1_bp  1  /* Character Size bit 1 position. */
#define USART_CHSIZE2_bm  (1<<2)  /* Character Size bit 2 mask. */
#define USART_CHSIZE2_bp  2  /* Character Size bit 2 position. */

/* USART.CTRLD  bit masks and bit positions */
#define USART_DECTYPE_gm  0x30  /* Receive Interrupt Level group mask. */
#define USART_DECTYPE_gp  4  /* Receive Interrupt Level group position. */
#define USART_DECTYPE0_bm  (1<<4)  /* Receive Interrupt Level bit 0 mask. */
#define USART_DECTYPE0_bp  4  /* Receive Interrupt Level bit 0 position. */
#define USART_DECTYPE1_bm  (1<<5)  /* Receive Interrupt Level bit 1 mask. */
#define USART_DECTYPE1_bp  5  /* Receive Interrupt Level bit 1 position. */

#define USART_LUTACT_gm  0x0C  /* Transmit Interrupt Level group mask. */
#define USART_LUTACT_gp  2  /* Transmit Interrupt Level group position. */
#define USART_LUTACT0_bm  (1<<2)  /* Transmit Interrupt Level bit 0 mask. */
#define USART_LUTACT0_bp  2  /* Transmit Interrupt Level bit 0 position. */
#define USART_LUTACT1_bm  (1<<3)  /* Transmit Interrupt Level bit 1 mask. */
#define USART_LUTACT1_bp  3  /* Transmit Interrupt Level bit 1 position. */

#define USART_PECACT_gm  0x03  /* Data Register Empty Interrupt Level group mask. */
#define USART_PECACT_gp  0  /* Data Register Empty Interrupt Level group position. */
#define USART_PECACT0_bm  (1<<0)  /* Data Register Empty Interrupt Level bit 0 mask. */
#define USART_PECACT0_bp  0  /* Data Register Empty Interrupt Level bit 0 position. */
#define USART_PECACT1_bm  (1<<1)  /* Data Register Empty Interrupt Level bit 1 mask. */
#define USART_PECACT1_bp  1  /* Data Register Empty Interrupt Level bit 1 position. */

/* USART.BAUDCTRLA  bit masks and bit positions */
#define USART_BSEL_gm  0xFF  /* Baud Rate Selection Bits [7:0] group mask. */
#define USART_BSEL_gp  0  /* Baud Rate Selection Bits [7:0] group position. */
#define USART_BSEL0_bm  (1<<0)  /* Baud Rate Selection Bits [7:0] bit 0 mask. */
#define USART_BSEL0_bp  0  /* Baud Rate Selection Bits [7:0] bit 0 position. */
#define USART_BSEL1_bm  (1<<1)  /* Baud Rate Selection Bits [7:0] bit 1 mask. */
#define USART_BSEL1_bp  1  /* Baud Rate Selection Bits [7:0] bit 1 position. */
#define USART_BSEL2_bm  (1<<2)  /* Baud Rate Selection Bits [7:0] bit 2 mask. */
#define USART_BSEL2_bp  2  /* Baud Rate Selection Bits [7:0] bit 2 position. */
#define USART_BSEL3_bm  (1<<3)  /* Baud Rate Selection Bits [7:0] bit 3 mask. */
#define USART_BSEL3_bp  3  /* Baud Rate Selection Bits [7:0] bit 3 position. */
#define USART_BSEL4_bm  (1<<4)  /* Baud Rate Selection Bits [7:0] bit 4 mask. */
#define USART_BSEL4_bp  4  /* Baud Rate Selection Bits [7:0] bit 4 position. */
#define USART_BSEL5_bm  (1<<5)  /* Baud Rate Selection Bits [7:0] bit 5 mask. */
#define USART_BSEL5_bp  5  /* Baud Rate Selection Bits [7:0] bit 5 position. */
#define USART_BSEL6_bm  (1<<6)  /* Baud Rate Selection Bits [7:0] bit 6 mask. */
#define USART_BSEL6_bp  6  /* Baud Rate Selection Bits [7:0] bit 6 position. */
#define USART_BSEL7_bm  (1<<7)  /* Baud Rate Selection Bits [7:0] bit 7 mask. */
#define USART_BSEL7_bp  7  /* Baud Rate Selection Bits [7:0] bit 7 position. */

/* USART.BAUDCTRLB  bit masks and bit positions */
#define USART_BSCALE_gm  0xF0  /* Baud Rate Scale group mask. */
#define USART_BSCALE_gp  4  /* Baud Rate Scale group position. */
#define USART_BSCALE0_bm  (1<<4)  /* Baud Rate Scale bit 0 mask. */
#define USART_BSCALE0_bp  4  /* Baud Rate Scale bit 0 position. */
#define USART_BSCALE1_bm  (1<<5)  /* Baud Rate Scale bit 1 mask. */
#define USART_BSCALE1_bp  5  /* Baud Rate Scale bit 1 position. */
#define USART_BSCALE2_bm  (1<<6)  /* Baud Rate Scale bit 2 mask. */
#define USART_BSCALE2_bp  6  /* Baud Rate Scale bit 2 position. */
#define USART_BSCALE3_bm  (1<<7)  /* Baud Rate Scale bit 3 mask. */
#define USART_BSCALE3_bp  7  /* Baud Rate Scale bit 3 position. */

/* USART_BSEL  Predefined. */
/* USART_BSEL  Predefined. */

/* SPI - Serial Peripheral Interface */
/* SPI.CTRL  bit masks and bit positions */
#define SPI_CLK2X_bm  0x80  /* Enable Double Speed bit mask. */
#define SPI_CLK2X_bp  7  /* Enable Double Speed bit position. */

#define SPI_ENABLE_bm  0x40  /* Enable SPI Module bit mask. */
#define SPI_ENABLE_bp  6  /* Enable SPI Module bit position. */

#define SPI_DORD_bm  0x20  /* Data Order Setting bit mask. */
#define SPI_DORD_bp  5  /* Data Order Setting bit position. */

#define SPI_MASTER_bm  0x10  /* Master Operation Enable bit mask. */
#define SPI_MASTER_bp  4  /* Master Operation Enable bit position. */

#define SPI_MODE_gm  0x0C  /* SPI Mode group mask. */
#define SPI_MODE_gp  2  /* SPI Mode group position. */
#define SPI_MODE0_bm  (1<<2)  /* SPI Mode bit 0 mask. */
#define SPI_MODE0_bp  2  /* SPI Mode bit 0 position. */
#define SPI_MODE1_bm  (1<<3)  /* SPI Mode bit 1 mask. */
#define SPI_MODE1_bp  3  /* SPI Mode bit 1 position. */

#define SPI_PRESCALER_gm  0x03  /* Prescaler group mask. */
#define SPI_PRESCALER_gp  0  /* Prescaler group position. */
#define SPI_PRESCALER0_bm  (1<<0)  /* Prescaler bit 0 mask. */
#define SPI_PRESCALER0_bp  0  /* Prescaler bit 0 position. */
#define SPI_PRESCALER1_bm  (1<<1)  /* Prescaler bit 1 mask. */
#define SPI_PRESCALER1_bp  1  /* Prescaler bit 1 position. */

/* SPI.INTCTRL  bit masks and bit positions */
#define SPI_RXCIE_bm  0x80  /* Receive Complete Interrupt Enable (In Buffer Modes Only). bit mask. */
#define SPI_RXCIE_bp  7  /* Receive Complete Interrupt Enable (In Buffer Modes Only). bit position. */

#define SPI_TXCIE_bm  0x40  /* Transmit Complete Interrupt Enable (In Buffer Modes Only). bit mask. */
#define SPI_TXCIE_bp  6  /* Transmit Complete Interrupt Enable (In Buffer Modes Only). bit position. */

#define SPI_DREIE_bm  0x20  /* Data Register Empty Interrupt Enable (In Buffer Modes Only). bit mask. */
#define SPI_DREIE_bp  5  /* Data Register Empty Interrupt Enable (In Buffer Modes Only). bit position. */

#define SPI_SSIE_bm  0x10  /* Slave Select Trigger Interrupt Enable (In Buffer Modes Only). bit mask. */
#define SPI_SSIE_bp  4  /* Slave Select Trigger Interrupt Enable (In Buffer Modes Only). bit position. */

#define SPI_INTLVL_gm  0x03  /* Interrupt level group mask. */
#define SPI_INTLVL_gp  0  /* Interrupt level group position. */
#define SPI_INTLVL0_bm  (1<<0)  /* Interrupt level bit 0 mask. */
#define SPI_INTLVL0_bp  0  /* Interrupt level bit 0 position. */
#define SPI_INTLVL1_bm  (1<<1)  /* Interrupt level bit 1 mask. */
#define SPI_INTLVL1_bp  1  /* Interrupt level bit 1 position. */

/* SPI.STATUS  bit masks and bit positions */
#define SPI_IF_bm  0x80  /* Interrupt Flag (In Standard Mode Only). bit mask. */
#define SPI_IF_bp  7  /* Interrupt Flag (In Standard Mode Only). bit position. */

#define SPI_RXCIF_bm  0x80  /* Receive Complete Interrupt Flag (In Buffer Modes Only). bit mask. */
#define SPI_RXCIF_bp  7  /* Receive Complete Interrupt Flag (In Buffer Modes Only). bit position. */

#define SPI_WRCOL_bm  0x40  /* Write Collision Flag (In Standard Mode Only). bit mask. */
#define SPI_WRCOL_bp  6  /* Write Collision Flag (In Standard Mode Only). bit position. */

#define SPI_TXCIF_bm  0x40  /* Transmit Complete Interrupt Flag (In Buffer Modes Only). bit mask. */
#define SPI_TXCIF_bp  6  /* Transmit Complete Interrupt Flag (In Buffer Modes Only). bit position. */

#define SPI_DREIF_bm  0x20  /* Data Register Empty Interrupt Flag (In Buffer Modes Only). bit mask. */
#define SPI_DREIF_bp  5  /* Data Register Empty Interrupt Flag (In Buffer Modes Only). bit position. */

#define SPI_SSIF_bm  0x10  /* Slave Select Trigger Interrupt Flag (In Buffer Modes Only). bit mask. */
#define SPI_SSIF_bp  4  /* Slave Select Trigger Interrupt Flag (In Buffer Modes Only). bit position. */

#define SPI_BUFOVF_bm  0x01  /* Buffer Overflow (In Buffer Modes Only). bit mask. */
#define SPI_BUFOVF_bp  0  /* Buffer Overflow (In Buffer Modes Only). bit position. */

/* SPI.CTRLB  bit masks and bit positions */
#define SPI_BUFMODE_gm  0xC0  /* Buffer Modes group mask. */
#define SPI_BUFMODE_gp  6  /* Buffer Modes group position. */
#define SPI_BUFMODE0_bm  (1<<6)  /* Buffer Modes bit 0 mask. */
#define SPI_BUFMODE0_bp  6  /* Buffer Modes bit 0 position. */
#define SPI_BUFMODE1_bm  (1<<7)  /* Buffer Modes bit 1 mask. */
#define SPI_BUFMODE1_bp  7  /* Buffer Modes bit 1 position. */

#define SPI_SSD_bm  0x04  /* Slave Select Disable bit mask. */
#define SPI_SSD_bp  2  /* Slave Select Disable bit position. */

/* IRCOM - IR Communication Module */
/* IRCOM.CTRL  bit masks and bit positions */
#define IRCOM_EVSEL_gm  0x0F  /* Event Channel Select group mask. */
#define IRCOM_EVSEL_gp  0  /* Event Channel Select group position. */
#define IRCOM_EVSEL0_bm  (1<<0)  /* Event Channel Select bit 0 mask. */
#define IRCOM_EVSEL0_bp  0  /* Event Channel Select bit 0 position. */
#define IRCOM_EVSEL1_bm  (1<<1)  /* Event Channel Select bit 1 mask. */
#define IRCOM_EVSEL1_bp  1  /* Event Channel Select bit 1 position. */
#define IRCOM_EVSEL2_bm  (1<<2)  /* Event Channel Select bit 2 mask. */
#define IRCOM_EVSEL2_bp  2  /* Event Channel Select bit 2 position. */
#define IRCOM_EVSEL3_bm  (1<<3)  /* Event Channel Select bit 3 mask. */
#define IRCOM_EVSEL3_bp  3  /* Event Channel Select bit 3 position. */

/* FUSE - Fuses and Lockbits */
/* NVM_LOCKBITS.LOCKBITS  bit masks and bit positions */
#define NVM_LOCKBITS_BLBB_gm  0xC0  /* Boot Lock Bits - Boot Section group mask. */
#define NVM_LOCKBITS_BLBB_gp  6  /* Boot Lock Bits - Boot Section group position. */
#define NVM_LOCKBITS_BLBB0_bm  (1<<6)  /* Boot Lock Bits - Boot Section bit 0 mask. */
#define NVM_LOCKBITS_BLBB0_bp  6  /* Boot Lock Bits - Boot Section bit 0 position. */
#define NVM_LOCKBITS_BLBB1_bm  (1<<7)  /* Boot Lock Bits - Boot Section bit 1 mask. */
#define NVM_LOCKBITS_BLBB1_bp  7  /* Boot Lock Bits - Boot Section bit 1 position. */

#define NVM_LOCKBITS_BLBA_gm  0x30  /* Boot Lock Bits - Application Section group mask. */
#define NVM_LOCKBITS_BLBA_gp  4  /* Boot Lock Bits - Application Section group position. */
#define NVM_LOCKBITS_BLBA0_bm  (1<<4)  /* Boot Lock Bits - Application Section bit 0 mask. */
#define NVM_LOCKBITS_BLBA0_bp  4  /* Boot Lock Bits - Application Section bit 0 position. */
#define NVM_LOCKBITS_BLBA1_bm  (1<<5)  /* Boot Lock Bits - Application Section bit 1 mask. */
#define NVM_LOCKBITS_BLBA1_bp  5  /* Boot Lock Bits - Application Section bit 1 position. */

#define NVM_LOCKBITS_BLBAT_gm  0x0C  /* Boot Lock Bits - Application Table group mask. */
#define NVM_LOCKBITS_BLBAT_gp  2  /* Boot Lock Bits - Application Table group position. */
#define NVM_LOCKBITS_BLBAT0_bm  (1<<2)  /* Boot Lock Bits - Application Table bit 0 mask. */
#define NVM_LOCKBITS_BLBAT0_bp  2  /* Boot Lock Bits - Application Table bit 0 position. */
#define NVM_LOCKBITS_BLBAT1_bm  (1<<3)  /* Boot Lock Bits - Application Table bit 1 mask. */
#define NVM_LOCKBITS_BLBAT1_bp  3  /* Boot Lock Bits - Application Table bit 1 position. */

#define NVM_LOCKBITS_LB_gm  0x03  /* Lock Bits group mask. */
#define NVM_LOCKBITS_LB_gp  0  /* Lock Bits group position. */
#define NVM_LOCKBITS_LB0_bm  (1<<0)  /* Lock Bits bit 0 mask. */
#define NVM_LOCKBITS_LB0_bp  0  /* Lock Bits bit 0 position. */
#define NVM_LOCKBITS_LB1_bm  (1<<1)  /* Lock Bits bit 1 mask. */
#define NVM_LOCKBITS_LB1_bp  1  /* Lock Bits bit 1 position. */

/* NVM_FUSES.FUSEBYTE1  bit masks and bit positions */
#define NVM_FUSES_WDWP_gm  0xF0  /* Watchdog Window Timeout Period group mask. */
#define NVM_FUSES_WDWP_gp  4  /* Watchdog Window Timeout Period group position. */
#define NVM_FUSES_WDWP0_bm  (1<<4)  /* Watchdog Window Timeout Period bit 0 mask. */
#define NVM_FUSES_WDWP0_bp  4  /* Watchdog Window Timeout Period bit 0 position. */
#define NVM_FUSES_WDWP1_bm  (1<<5)  /* Watchdog Window Timeout Period bit 1 mask. */
#define NVM_FUSES_WDWP1_bp  5  /* Watchdog Window Timeout Period bit 1 position. */
#define NVM_FUSES_WDWP2_bm  (1<<6)  /* Watchdog Window Timeout Period bit 2 mask. */
#define NVM_FUSES_WDWP2_bp  6  /* Watchdog Window Timeout Period bit 2 position. */
#define NVM_FUSES_WDWP3_bm  (1<<7)  /* Watchdog Window Timeout Period bit 3 mask. */
#define NVM_FUSES_WDWP3_bp  7  /* Watchdog Window Timeout Period bit 3 position. */

#define NVM_FUSES_WDP_gm  0x0F  /* Watchdog Timeout Period group mask. */
#define NVM_FUSES_WDP_gp  0  /* Watchdog Timeout Period group position. */
#define NVM_FUSES_WDP0_bm  (1<<0)  /* Watchdog Timeout Period bit 0 mask. */
#define NVM_FUSES_WDP0_bp  0  /* Watchdog Timeout Period bit 0 position. */
#define NVM_FUSES_WDP1_bm  (1<<1)  /* Watchdog Timeout Period bit 1 mask. */
#define NVM_FUSES_WDP1_bp  1  /* Watchdog Timeout Period bit 1 position. */
#define NVM_FUSES_WDP2_bm  (1<<2)  /* Watchdog Timeout Period bit 2 mask. */
#define NVM_FUSES_WDP2_bp  2  /* Watchdog Timeout Period bit 2 position. */
#define NVM_FUSES_WDP3_bm  (1<<3)  /* Watchdog Timeout Period bit 3 mask. */
#define NVM_FUSES_WDP3_bp  3  /* Watchdog Timeout Period bit 3 position. */

/* NVM_FUSES.FUSEBYTE2  bit masks and bit positions */
#define NVM_FUSES_BOOTRST_bm  0x40  /* Boot Loader Section Reset Vector bit mask. */
#define NVM_FUSES_BOOTRST_bp  6  /* Boot Loader Section Reset Vector bit position. */

#define NVM_FUSES_BODPD_gm  0x03  /* BOD Operation in Power-Down Mode group mask. */
#define NVM_FUSES_BODPD_gp  0  /* BOD Operation in Power-Down Mode group position. */
#define NVM_FUSES_BODPD0_bm  (1<<0)  /* BOD Operation in Power-Down Mode bit 0 mask. */
#define NVM_FUSES_BODPD0_bp  0  /* BOD Operation in Power-Down Mode bit 0 position. */
#define NVM_FUSES_BODPD1_bm  (1<<1)  /* BOD Operation in Power-Down Mode bit 1 mask. */
#define NVM_FUSES_BODPD1_bp  1  /* BOD Operation in Power-Down Mode bit 1 position. */

/* NVM_FUSES.FUSEBYTE4  bit masks and bit positions */
#define NVM_FUSES_RSTDISBL_bm  0x10  /* External Reset Disable bit mask. */
#define NVM_FUSES_RSTDISBL_bp  4  /* External Reset Disable bit position. */

#define NVM_FUSES_SUT_gm  0x0C  /* Start-up Time group mask. */
#define NVM_FUSES_SUT_gp  2  /* Start-up Time group position. */
#define NVM_FUSES_SUT0_bm  (1<<2)  /* Start-up Time bit 0 mask. */
#define NVM_FUSES_SUT0_bp  2  /* Start-up Time bit 0 position. */
#define NVM_FUSES_SUT1_bm  (1<<3)  /* Start-up Time bit 1 mask. */
#define NVM_FUSES_SUT1_bp  3  /* Start-up Time bit 1 position. */

#define NVM_FUSES_WDLOCK_bm  0x02  /* Watchdog Timer Lock bit mask. */
#define NVM_FUSES_WDLOCK_bp  1  /* Watchdog Timer Lock bit position. */

/* NVM_FUSES.FUSEBYTE5  bit masks and bit positions */
#define NVM_FUSES_BODACT_gm  0x30  /* BOD Operation in Active Mode group mask. */
#define NVM_FUSES_BODACT_gp  4  /* BOD Operation in Active Mode group position. */
#define NVM_FUSES_BODACT0_bm  (1<<4)  /* BOD Operation in Active Mode bit 0 mask. */
#define NVM_FUSES_BODACT0_bp  4  /* BOD Operation in Active Mode bit 0 position. */
#define NVM_FUSES_BODACT1_bm  (1<<5)  /* BOD Operation in Active Mode bit 1 mask. */
#define NVM_FUSES_BODACT1_bp  5  /* BOD Operation in Active Mode bit 1 position. */

#define NVM_FUSES_EESAVE_bm  0x08  /* Preserve EEPROM Through Chip Erase bit mask. */
#define NVM_FUSES_EESAVE_bp  3  /* Preserve EEPROM Through Chip Erase bit position. */

#define NVM_FUSES_BODLVL_gm  0x07  /* Brownout Detection Voltage Level group mask. */
#define NVM_FUSES_BODLVL_gp  0  /* Brownout Detection Voltage Level group position. */
#define NVM_FUSES_BODLVL0_bm  (1<<0)  /* Brownout Detection Voltage Level bit 0 mask. */
#define NVM_FUSES_BODLVL0_bp  0  /* Brownout Detection Voltage Level bit 0 position. */
#define NVM_FUSES_BODLVL1_bm  (1<<1)  /* Brownout Detection Voltage Level bit 1 mask. */
#define NVM_FUSES_BODLVL1_bp  1  /* Brownout Detection Voltage Level bit 1 position. */
#define NVM_FUSES_BODLVL2_bm  (1<<2)  /* Brownout Detection Voltage Level bit 2 mask. */
#define NVM_FUSES_BODLVL2_bp  2  /* Brownout Detection Voltage Level bit 2 position. */

/* NVM_FUSES.FUSEBYTE6  bit masks and bit positions */
#define NVM_FUSES_FDACT5_bm  0x80  /* Fault Dectection Action on TC5 bit mask. */
#define NVM_FUSES_FDACT5_bp  7  /* Fault Dectection Action on TC5 bit position. */

#define NVM_FUSES_FDACT4_bm  0x40  /* Fault Dectection Action on TC4 bit mask. */
#define NVM_FUSES_FDACT4_bp  6  /* Fault Dectection Action on TC4 bit position. */

#define NVM_FUSES_VALUE_gm  0x3F  /* Port Pin Value group mask. */
#define NVM_FUSES_VALUE_gp  0  /* Port Pin Value group position. */
#define NVM_FUSES_VALUE0_bm  (1<<0)  /* Port Pin Value bit 0 mask. */
#define NVM_FUSES_VALUE0_bp  0  /* Port Pin Value bit 0 position. */
#define NVM_FUSES_VALUE1_bm  (1<<1)  /* Port Pin Value bit 1 mask. */
#define NVM_FUSES_VALUE1_bp  1  /* Port Pin Value bit 1 position. */
#define NVM_FUSES_VALUE2_bm  (1<<2)  /* Port Pin Value bit 2 mask. */
#define NVM_FUSES_VALUE2_bp  2  /* Port Pin Value bit 2 position. */
#define NVM_FUSES_VALUE3_bm  (1<<3)  /* Port Pin Value bit 3 mask. */
#define NVM_FUSES_VALUE3_bp  3  /* Port Pin Value bit 3 position. */
#define NVM_FUSES_VALUE4_bm  (1<<4)  /* Port Pin Value bit 4 mask. */
#define NVM_FUSES_VALUE4_bp  4  /* Port Pin Value bit 4 position. */
#define NVM_FUSES_VALUE5_bm  (1<<5)  /* Port Pin Value bit 5 mask. */
#define NVM_FUSES_VALUE5_bp  5  /* Port Pin Value bit 5 position. */



// Generic Port Pins

#define PIN0_bm 0x01
#define PIN0_bp 0
#define PIN1_bm 0x02
#define PIN1_bp 1
#define PIN2_bm 0x04
#define PIN2_bp 2
#define PIN3_bm 0x08
#define PIN3_bp 3
#define PIN4_bm 0x10
#define PIN4_bp 4
#define PIN5_bm 0x20
#define PIN5_bp 5
#define PIN6_bm 0x40
#define PIN6_bp 6
#define PIN7_bm 0x80
#define PIN7_bp 7

/* ========== Interrupt Vector Definitions ========== */
/* Vector 0 is the reset vector */

/* OSC interrupt vectors */
#define OSC_OSCF_vect_num  1
#define OSC_OSCF_vect      _VECTOR(1)  /* Oscillator Failure Interrupt (NMI) */

/* PORTR interrupt vectors */
#define PORTR_INT_vect_num  2
#define PORTR_INT_vect      _VECTOR(2)  /* External Interrupt */

/* EDMA interrupt vectors */
#define EDMA_CH0_vect_num  3
#define EDMA_CH0_vect      _VECTOR(3)  /* EDMA Channel 0 Interrupt */
#define EDMA_CH1_vect_num  4
#define EDMA_CH1_vect      _VECTOR(4)  /* EDMA Channel 1 Interrupt */
#define EDMA_CH2_vect_num  5
#define EDMA_CH2_vect      _VECTOR(5)  /* EDMA Channel 2 Interrupt */
#define EDMA_CH3_vect_num  6
#define EDMA_CH3_vect      _VECTOR(6)  /* EDMA Channel 3 Interrupt */

/* RTC interrupt vectors */
#define RTC_OVF_vect_num  7
#define RTC_OVF_vect      _VECTOR(7)  /* Overflow Interrupt */
#define RTC_COMP_vect_num  8
#define RTC_COMP_vect      _VECTOR(8)  /* Compare Interrupt */

/* PORTC interrupt vectors */
#define PORTC_INT_vect_num  9
#define PORTC_INT_vect      _VECTOR(9)  /* External Interrupt */

/* TWIC interrupt vectors */
#define TWIC_TWIS_vect_num  10
#define TWIC_TWIS_vect      _VECTOR(10)  /* TWI Slave Interrupt */
#define TWIC_TWIM_vect_num  11
#define TWIC_TWIM_vect      _VECTOR(11)  /* TWI Master Interrupt */

/* TCC4 interrupt vectors */
#define TCC4_OVF_vect_num  12
#define TCC4_OVF_vect      _VECTOR(12)  /* Overflow Interrupt */
#define TCC4_ERR_vect_num  13
#define TCC4_ERR_vect      _VECTOR(13)  /* Error Interrupt */
#define TCC4_CCA_vect_num  14
#define TCC4_CCA_vect      _VECTOR(14)  /* Channel A Compare or Capture Interrupt */
#define TCC4_CCB_vect_num  15
#define TCC4_CCB_vect      _VECTOR(15)  /* Channel B Compare or Capture Interrupt */
#define TCC4_CCC_vect_num  16
#define TCC4_CCC_vect      _VECTOR(16)  /* Channel C Compare or Capture Interrupt */
#define TCC4_CCD_vect_num  17
#define TCC4_CCD_vect      _VECTOR(17)  /* Channel D Compare or Capture Interrupt */

/* TCC5 interrupt vectors */
#define TCC5_OVF_vect_num  18
#define TCC5_OVF_vect      _VECTOR(18)  /* Overflow Interrupt */
#define TCC5_ERR_vect_num  19
#define TCC5_ERR_vect      _VECTOR(19)  /* Error Interrupt */
#define TCC5_CCA_vect_num  20
#define TCC5_CCA_vect      _VECTOR(20)  /* Channel A Compare or Capture Interrupt */
#define TCC5_CCB_vect_num  21
#define TCC5_CCB_vect      _VECTOR(21)  /* Channel B Compare or Capture Interrupt */

/* SPIC interrupt vectors */
#define SPIC_INT_vect_num  22
#define SPIC_INT_vect      _VECTOR(22)  /* SPI Interrupt */

/* USARTC0 interrupt vectors */
#define USARTC0_RXC_vect_num  23
#define USARTC0_RXC_vect      _VECTOR(23)  /* Reception Complete Interrupt */
#define USARTC0_DRE_vect_num  24
#define USARTC0_DRE_vect      _VECTOR(24)  /* Data Register Empty Interrupt */
#define USARTC0_TXC_vect_num  25
#define USARTC0_TXC_vect      _VECTOR(25)  /* Transmission Complete Interrupt */

/* NVM interrupt vectors */
#define NVM_EE_vect_num  26
#define NVM_EE_vect      _VECTOR(26)  /* EE Interrupt */
#define NVM_SPM_vect_num  27
#define NVM_SPM_vect      _VECTOR(27)  /* SPM Interrupt */

/* XCL interrupt vectors */
#define XCL_UNF_vect_num  28
#define XCL_UNF_vect      _VECTOR(28)  /* Timer/Counter Underflow Interrupt */
#define XCL_CC_vect_num  29
#define XCL_CC_vect      _VECTOR(29)  /* Timer/Counter Compare or Capture Interrupt */

/* PORTA interrupt vectors */
#define PORTA_INT_vect_num  30
#define PORTA_INT_vect      _VECTOR(30)  /* External Interrupt */

/* ACA interrupt vectors */
#define ACA_AC0_vect_num  31
#define ACA_AC0_vect      _VECTOR(31)  /* AC0 Interrupt */
#define ACA_AC1_vect_num  32
#define ACA_AC1_vect      _VECTOR(32)  /* AC1 Interrupt */
#define ACA_ACW_vect_num  33
#define ACA_ACW_vect      _VECTOR(33)  /* ACW Window Mode Interrupt */

/* ADCA interrupt vectors */
#define ADCA_CH0_vect_num  34
#define ADCA_CH0_vect      _VECTOR(34)  /* ADC Channel Interrupt */

/* PORTD interrupt vectors */
#define PORTD_INT_vect_num  35
#define PORTD_INT_vect      _VECTOR(35)  /* External Interrupt */

/* TCD5 interrupt vectors */
#define TCD5_OVF_vect_num  36
#define TCD5_OVF_vect      _VECTOR(36)  /* Overflow Interrupt */
#define TCD5_ERR_vect_num  37
#define TCD5_ERR_vect      _VECTOR(37)  /* Error Interrupt */
#define TCD5_CCA_vect_num  38
#define TCD5_CCA_vect      _VECTOR(38)  /* Channel A Compare or Capture Interrupt */
#define TCD5_CCB_vect_num  39
#define TCD5_CCB_vect      _VECTOR(39)  /* Channel B Compare or Capture Interrupt */

/* USARTD0 interrupt vectors */
#define USARTD0_RXC_vect_num  40
#define USARTD0_RXC_vect      _VECTOR(40)  /* Reception Complete Interrupt */
#define USARTD0_DRE_vect_num  41
#define USARTD0_DRE_vect      _VECTOR(41)  /* Data Register Empty Interrupt */
#define USARTD0_TXC_vect_num  42
#define USARTD0_TXC_vect      _VECTOR(42)  /* Transmission Complete Interrupt */

#define _VECTOR_SIZE 4 /* Size of individual vector. */
#define _VECTORS_SIZE (43 * _VECTOR_SIZE)


/* ========== Constants ========== */

#define PROGMEM_START     (0x0000)
#define PROGMEM_SIZE      (10240)
#define PROGMEM_END       (PROGMEM_START + PROGMEM_SIZE - 1)

#define APP_SECTION_START     (0x0000)
#define APP_SECTION_SIZE      (8192)
#define APP_SECTION_PAGE_SIZE (128)
#define APP_SECTION_END       (APP_SECTION_START + APP_SECTION_SIZE - 1)

#define APPTABLE_SECTION_START     (0x1800)
#define APPTABLE_SECTION_SIZE      (2048)
#define APPTABLE_SECTION_PAGE_SIZE (128)
#define APPTABLE_SECTION_END       (APPTABLE_SECTION_START + APPTABLE_SECTION_SIZE - 1)

#define BOOT_SECTION_START     (0x2000)
#define BOOT_SECTION_SIZE      (2048)
#define BOOT_SECTION_PAGE_SIZE (128)
#define BOOT_SECTION_END       (BOOT_SECTION_START + BOOT_SECTION_SIZE - 1)

#define DATAMEM_START     (0x0000)
#define DATAMEM_SIZE      (9216)
#define DATAMEM_END       (DATAMEM_START + DATAMEM_SIZE - 1)

#define IO_START     (0x0000)
#define IO_SIZE      (4096)
#define IO_PAGE_SIZE (0)
#define IO_END       (IO_START + IO_SIZE - 1)

#define MAPPED_EEPROM_START     (0x1000)
#define MAPPED_EEPROM_SIZE      (512)
#define MAPPED_EEPROM_PAGE_SIZE (0)
#define MAPPED_EEPROM_END       (MAPPED_EEPROM_START + MAPPED_EEPROM_SIZE - 1)

#define INTERNAL_SRAM_START     (0x2000)
#define INTERNAL_SRAM_SIZE      (1024)
#define INTERNAL_SRAM_PAGE_SIZE (0)
#define INTERNAL_SRAM_END       (INTERNAL_SRAM_START + INTERNAL_SRAM_SIZE - 1)

#define EEPROM_START     (0x0000)
#define EEPROM_SIZE      (512)
#define EEPROM_PAGE_SIZE (32)
#define EEPROM_END       (EEPROM_START + EEPROM_SIZE - 1)

#define SIGNATURES_START     (0x0000)
#define SIGNATURES_SIZE      (3)
#define SIGNATURES_PAGE_SIZE (0)
#define SIGNATURES_END       (SIGNATURES_START + SIGNATURES_SIZE - 1)

#define FUSES_START     (0x0000)
#define FUSES_SIZE      (7)
#define FUSES_PAGE_SIZE (0)
#define FUSES_END       (FUSES_START + FUSES_SIZE - 1)

#define LOCKBITS_START     (0x0000)
#define LOCKBITS_SIZE      (1)
#define LOCKBITS_PAGE_SIZE (0)
#define LOCKBITS_END       (LOCKBITS_START + LOCKBITS_SIZE - 1)

#define USER_SIGNATURES_START     (0x0000)
#define USER_SIGNATURES_SIZE      (128)
#define USER_SIGNATURES_PAGE_SIZE (128)
#define USER_SIGNATURES_END       (USER_SIGNATURES_START + USER_SIGNATURES_SIZE - 1)

#define PROD_SIGNATURES_START     (0x0000)
#define PROD_SIGNATURES_SIZE      (54)
#define PROD_SIGNATURES_PAGE_SIZE (128)
#define PROD_SIGNATURES_END       (PROD_SIGNATURES_START + PROD_SIGNATURES_SIZE - 1)

#define FLASHSTART   PROGMEM_START
#define FLASHEND     PROGMEM_END
#define SPM_PAGESIZE 128
#define RAMSTART     INTERNAL_SRAM_START
#define RAMSIZE      INTERNAL_SRAM_SIZE
#define RAMEND       INTERNAL_SRAM_END
#define E2END        EEPROM_END
#define E2PAGESIZE   EEPROM_PAGE_SIZE


/* ========== Fuses ========== */
#define FUSE_MEMORY_SIZE 7

/* Fuse Byte 0 Reserved */

/* Fuse Byte 1 */
#define FUSE_WDP0  (unsigned char)~_BV(0)  /* Watchdog Timeout Period Bit 0 */
#define FUSE_WDP1  (unsigned char)~_BV(1)  /* Watchdog Timeout Period Bit 1 */
#define FUSE_WDP2  (unsigned char)~_BV(2)  /* Watchdog Timeout Period Bit 2 */
#define FUSE_WDP3  (unsigned char)~_BV(3)  /* Watchdog Timeout Period Bit 3 */
#define FUSE_WDWP0  (unsigned char)~_BV(4)  /* Watchdog Window Timeout Period Bit 0 */
#define FUSE_WDWP1  (unsigned char)~_BV(5)  /* Watchdog Window Timeout Period Bit 1 */
#define FUSE_WDWP2  (unsigned char)~_BV(6)  /* Watchdog Window Timeout Period Bit 2 */
#define FUSE_WDWP3  (unsigned char)~_BV(7)  /* Watchdog Window Timeout Period Bit 3 */
#define FUSE1_DEFAULT  (0xFF)

/* Fuse Byte 2 */
#define FUSE_BODPD0  (unsigned char)~_BV(0)  /* BOD Operation in Power-Down Mode Bit 0 */
#define FUSE_BODPD1  (unsigned char)~_BV(1)  /* BOD Operation in Power-Down Mode Bit 1 */
#define FUSE_BOOTRST  (unsigned char)~_BV(6)  /* Boot Loader Section Reset Vector */
#define FUSE2_DEFAULT  (0xFF)

/* Fuse Byte 3 Reserved */

/* Fuse Byte 4 */
#define FUSE_WDLOCK  (unsigned char)~_BV(1)  /* Watchdog Timer Lock */
#define FUSE_SUT0  (unsigned char)~_BV(2)  /* Start-up Time Bit 0 */
#define FUSE_SUT1  (unsigned char)~_BV(3)  /* Start-up Time Bit 1 */
#define FUSE_RSTDISBL  (unsigned char)~_BV(4)  /* External Reset Disable */
#define FUSE4_DEFAULT  (0xFF)

/* Fuse Byte 5 */
#define FUSE_BODLVL0  (unsigned char)~_BV(0)  /* Brownout Detection Voltage Level Bit 0 */
#define FUSE_BODLVL1  (unsigned char)~_BV(1)  /* Brownout Detection Voltage Level Bit 1 */
#define FUSE_BODLVL2  (unsigned char)~_BV(2)  /* Brownout Detection Voltage Level Bit 2 */
#define FUSE_EESAVE  (unsigned char)~_BV(3)  /* Preserve EEPROM Through Chip Erase */
#define FUSE_BODACT0  (unsigned char)~_BV(4)  /* BOD Operation in Active Mode Bit 0 */
#define FUSE_BODACT1  (unsigned char)~_BV(5)  /* BOD Operation in Active Mode Bit 1 */
#define FUSE5_DEFAULT  (0xFF)

/* Fuse Byte 6 */
#define FUSE_VALUE0  (unsigned char)~_BV(0)  /* Port Pin Value Bit 0 */
#define FUSE_VALUE1  (unsigned char)~_BV(1)  /* Port Pin Value Bit 1 */
#define FUSE_VALUE2  (unsigned char)~_BV(2)  /* Port Pin Value Bit 2 */
#define FUSE_VALUE3  (unsigned char)~_BV(3)  /* Port Pin Value Bit 3 */
#define FUSE_VALUE4  (unsigned char)~_BV(4)  /* Port Pin Value Bit 4 */
#define FUSE_VALUE5  (unsigned char)~_BV(5)  /* Port Pin Value Bit 5 */
#define FUSE_FDACT4  (unsigned char)~_BV(6)  /* Fault Dectection Action on TC4 */
#define FUSE_FDACT5  (unsigned char)~_BV(7)  /* Fault Dectection Action on TC5 */
#define FUSE6_DEFAULT  (0xFF)

/* ========== Lock Bits ========== */
#define __LOCK_BITS_EXIST
#define __BOOT_LOCK_APPLICATION_TABLE_BITS_EXIST
#define __BOOT_LOCK_APPLICATION_BITS_EXIST
#define __BOOT_LOCK_BOOT_BITS_EXIST

/* ========== Signature ========== */
#define SIGNATURE_0 0x1E
#define SIGNATURE_1 0x93
#define SIGNATURE_2 0x41

/* ========== Power Reduction Condition Definitions ========== */

/* PR.PRGEN */
#define __AVR_HAVE_PRGEN	(PR_XCL_bm|PR_RTC_bm|PR_EVSYS_bm|PR_EDMA_bm)
#define __AVR_HAVE_PRGEN_XCL
#define __AVR_HAVE_PRGEN_RTC
#define __AVR_HAVE_PRGEN_EVSYS
#define __AVR_HAVE_PRGEN_EDMA

/* PR.PRPA */
#define __AVR_HAVE_PRPA	(PR_DAC_bm|PR_ADC_bm|PR_AC_bm)
#define __AVR_HAVE_PRPA_DAC
#define __AVR_HAVE_PRPA_ADC
#define __AVR_HAVE_PRPA_AC

/* PR.PRPC */
#define __AVR_HAVE_PRPC	(PR_TWI_bm|PR_USART0_bm|PR_SPI_bm|PR_HIRES_bm|PR_TC5_bm|PR_TC4_bm)
#define __AVR_HAVE_PRPC_TWI
#define __AVR_HAVE_PRPC_USART0
#define __AVR_HAVE_PRPC_SPI
#define __AVR_HAVE_PRPC_HIRES
#define __AVR_HAVE_PRPC_TC5
#define __AVR_HAVE_PRPC_TC4

/* PR.PRPD */
#define __AVR_HAVE_PRPD	(PR_USART0_bm|PR_TC5_bm)
#define __AVR_HAVE_PRPD_USART0
#define __AVR_HAVE_PRPD_TC5


#endif /* #ifdef _AVR_ATXMEGA8E5_H_INCLUDED */

