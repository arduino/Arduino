/*****************************************************************************
 *
 * Copyright (C) 2020 Atmel Corporation, a wholly owned subsidiary of Microchip Technology Inc.
 * All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 ****************************************************************************/


#ifndef _AVR_IO_H_
#  error "Include <avr/io.h> instead of this file."
#endif

#ifndef _AVR_IOXXX_H_
#  define _AVR_IOXXX_H_ "iotn817.h"
#else
#  error "Attempt to include more than one <avr/ioXXX.h> file."
#endif

#ifndef _AVR_ATTINY817_H_INCLUDED
#define _AVR_ATTINY817_H_INCLUDED

/* Ungrouped common registers */
#define CCP  _SFR_MEM8(0x0034)  /* Configuration Change Protection */
#define SPH  _SFR_MEM8(0x003E)  /* Stack Pointer High */
#define SPL  _SFR_MEM8(0x003D)  /* Stack Pointer Low */
#define SREG  _SFR_MEM8(0x003F)  /* Status Register */

#define GPIOR0  _SFR_MEM8(0x001C)  /* General Purpose IO Register 0 */
#define GPIOR1  _SFR_MEM8(0x001D)  /* General Purpose IO Register 1 */
#define GPIOR2  _SFR_MEM8(0x001E)  /* General Purpose IO Register 2 */
#define GPIOR3  _SFR_MEM8(0x001F)  /* General Purpose IO Register 3 */

/* Deprecated */
#define GPIO0  _SFR_MEM8(0x001C)  /* General Purpose IO Register 0 */
#define GPIO1  _SFR_MEM8(0x001D)  /* General Purpose IO Register 1 */
#define GPIO2  _SFR_MEM8(0x001E)  /* General Purpose IO Register 2 */
#define GPIO3  _SFR_MEM8(0x001F)  /* General Purpose IO Register 3 */

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
AC - Analog Comparator
--------------------------------------------------------------------------
*/

/* Analog Comparator */
typedef struct AC_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t reserved_1[1];
    register8_t MUXCTRLA;  /* Mux Control A */
    register8_t reserved_2[3];
    register8_t INTCTRL;  /* Interrupt Control */
    register8_t STATUS;  /* Status */
} AC_t;

/* Hysteresis Mode select */
typedef enum AC_HYSMODE_enum
{
    AC_HYSMODE_OFF_gc = (0x00<<1),  /* No hysteresis */
    AC_HYSMODE_10mV_gc = (0x01<<1),  /* 10mV hysteresis */
    AC_HYSMODE_25mV_gc = (0x02<<1),  /* 25mV hysteresis */
    AC_HYSMODE_50mV_gc = (0x03<<1),  /* 50mV hysteresis */
} AC_HYSMODE_t;

/* Interrupt Mode select */
typedef enum AC_INTMODE_enum
{
    AC_INTMODE_BOTHEDGE_gc = (0x00<<4),  /* Any Edge */
    AC_INTMODE_NEGEDGE_gc = (0x02<<4),  /* Negative Edge */
    AC_INTMODE_POSEDGE_gc = (0x03<<4),  /* Positive Edge */
} AC_INTMODE_t;

/* Low Power Mode select */
typedef enum AC_LPMODE_enum
{
    AC_LPMODE_DIS_gc = (0x00<<3),  /* Low power mode disabled */
    AC_LPMODE_EN_gc = (0x01<<3),  /* Low power mode enabled */
} AC_LPMODE_t;

/* Negative Input MUX Selection select */
typedef enum AC_MUXNEG_enum
{
    AC_MUXNEG_PIN0_gc = (0x00<<0),  /* Negative Pin 0 */
    AC_MUXNEG_PIN1_gc = (0x01<<0),  /* Negative Pin 1 */
    AC_MUXNEG_VREF_gc = (0x02<<0),  /* Voltage Reference */
    AC_MUXNEG_DAC_gc = (0x03<<0),  /* DAC output */
} AC_MUXNEG_t;

/* Positive Input MUX Selection select */
typedef enum AC_MUXPOS_enum
{
    AC_MUXPOS_PIN0_gc = (0x00<<3),  /* Positive Pin 0 */
    AC_MUXPOS_PIN1_gc = (0x01<<3),  /* Positive Pin 1 */
} AC_MUXPOS_t;

/*
--------------------------------------------------------------------------
ADC - Analog to Digital Converter
--------------------------------------------------------------------------
*/

/* Analog to Digital Converter */
typedef struct ADC_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t CTRLB;  /* Control B */
    register8_t CTRLC;  /* Control C */
    register8_t CTRLD;  /* Control D */
    register8_t CTRLE;  /* Control E */
    register8_t SAMPCTRL;  /* Sample Control */
    register8_t MUXPOS;  /* Positive mux input */
    register8_t reserved_1[1];
    register8_t COMMAND;  /* Command */
    register8_t EVCTRL;  /* Event Control */
    register8_t INTCTRL;  /* Interrupt Control */
    register8_t INTFLAGS;  /* Interrupt Flags */
    register8_t DBGCTRL;  /* Debug Control */
    register8_t TEMP;  /* Temporary Data */
    register8_t reserved_2[2];
    _WORDREGISTER(RES);  /* ADC Accumulator Result */
    _WORDREGISTER(WINLT);  /* Window comparator low threshold */
    _WORDREGISTER(WINHT);  /* Window comparator high threshold */
    register8_t CALIB;  /* Calibration */
    register8_t reserved_3[1];
} ADC_t;

/* Automatic Sampling Delay Variation select */
typedef enum ADC_ASDV_enum
{
    ADC_ASDV_ASVOFF_gc = (0x00<<4),  /* The Automatic Sampling Delay Variation is disabled */
    ADC_ASDV_ASVON_gc = (0x01<<4),  /* The Automatic Sampling Delay Variation is enabled */
} ADC_ASDV_t;

/* Duty Cycle select */
typedef enum ADC_DUTYCYC_enum
{
    ADC_DUTYCYC_DUTY50_gc = (0x00<<0),  /* 50% Duty cycle */
    ADC_DUTYCYC_DUTY25_gc = (0x01<<0),  /* 25% Duty cycle */
} ADC_DUTYCYC_t;

/* Initial Delay Selection select */
typedef enum ADC_INITDLY_enum
{
    ADC_INITDLY_DLY0_gc = (0x00<<5),  /* Delay 0 CLK_ADC cycles */
    ADC_INITDLY_DLY16_gc = (0x01<<5),  /* Delay 16 CLK_ADC cycles */
    ADC_INITDLY_DLY32_gc = (0x02<<5),  /* Delay 32 CLK_ADC cycles */
    ADC_INITDLY_DLY64_gc = (0x03<<5),  /* Delay 64 CLK_ADC cycles */
    ADC_INITDLY_DLY128_gc = (0x04<<5),  /* Delay 128 CLK_ADC cycles */
    ADC_INITDLY_DLY256_gc = (0x05<<5),  /* Delay 256 CLK_ADC cycles */
} ADC_INITDLY_t;

/* Analog Channel Selection Bits select */
typedef enum ADC_MUXPOS_enum
{
    ADC_MUXPOS_AIN0_gc = (0x00<<0),  /* ADC input pin 0 */
    ADC_MUXPOS_AIN1_gc = (0x01<<0),  /* ADC input pin 1 */
    ADC_MUXPOS_AIN2_gc = (0x02<<0),  /* ADC input pin 2 */
    ADC_MUXPOS_AIN3_gc = (0x03<<0),  /* ADC input pin 3 */
    ADC_MUXPOS_AIN4_gc = (0x04<<0),  /* ADC input pin 4 */
    ADC_MUXPOS_AIN5_gc = (0x05<<0),  /* ADC input pin 5 */
    ADC_MUXPOS_AIN6_gc = (0x06<<0),  /* ADC input pin 6 */
    ADC_MUXPOS_AIN7_gc = (0x07<<0),  /* ADC input pin 7 */
    ADC_MUXPOS_AIN8_gc = (0x08<<0),  /* ADC input pin 8 */
    ADC_MUXPOS_AIN9_gc = (0x09<<0),  /* ADC input pin 9 */
    ADC_MUXPOS_AIN10_gc = (0x0A<<0),  /* ADC input pin 10 */
    ADC_MUXPOS_AIN11_gc = (0x0B<<0),  /* ADC input pin 11 */
    ADC_MUXPOS_DAC0_gc = (0x1C<<0),  /* DAC0 */
    ADC_MUXPOS_INTREF_gc = (0x1D<<0),  /* Internal Ref */
    ADC_MUXPOS_TEMPSENSE_gc = (0x1E<<0),  /* Temp sensor */
    ADC_MUXPOS_GND_gc = (0x1F<<0),  /* GND */
} ADC_MUXPOS_t;

/* Clock Pre-scaler select */
typedef enum ADC_PRESC_enum
{
    ADC_PRESC_DIV2_gc = (0x00<<0),  /* CLK_PER divided by 2 */
    ADC_PRESC_DIV4_gc = (0x01<<0),  /* CLK_PER divided by 4 */
    ADC_PRESC_DIV8_gc = (0x02<<0),  /* CLK_PER divided by 8 */
    ADC_PRESC_DIV16_gc = (0x03<<0),  /* CLK_PER divided by 16 */
    ADC_PRESC_DIV32_gc = (0x04<<0),  /* CLK_PER divided by 32 */
    ADC_PRESC_DIV64_gc = (0x05<<0),  /* CLK_PER divided by 64 */
    ADC_PRESC_DIV128_gc = (0x06<<0),  /* CLK_PER divided by 128 */
    ADC_PRESC_DIV256_gc = (0x07<<0),  /* CLK_PER divided by 256 */
} ADC_PRESC_t;

/* Reference Selection select */
typedef enum ADC_REFSEL_enum
{
    ADC_REFSEL_INTREF_gc = (0x00<<4),  /* Internal reference */
    ADC_REFSEL_VDDREF_gc = (0x01<<4),  /* VDD */
} ADC_REFSEL_t;

/* ADC Resolution select */
typedef enum ADC_RESSEL_enum
{
    ADC_RESSEL_10BIT_gc = (0x00<<2),  /* 10-bit mode */
    ADC_RESSEL_8BIT_gc = (0x01<<2),  /* 8-bit mode */
} ADC_RESSEL_t;

/* Accumulation Samples select */
typedef enum ADC_SAMPNUM_enum
{
    ADC_SAMPNUM_ACC1_gc = (0x00<<0),  /* 1 ADC sample */
    ADC_SAMPNUM_ACC2_gc = (0x01<<0),  /* Accumulate 2 samples */
    ADC_SAMPNUM_ACC4_gc = (0x02<<0),  /* Accumulate 4 samples */
    ADC_SAMPNUM_ACC8_gc = (0x03<<0),  /* Accumulate 8 samples */
    ADC_SAMPNUM_ACC16_gc = (0x04<<0),  /* Accumulate 16 samples */
    ADC_SAMPNUM_ACC32_gc = (0x05<<0),  /* Accumulate 32 samples */
    ADC_SAMPNUM_ACC64_gc = (0x06<<0),  /* Accumulate 64 samples */
} ADC_SAMPNUM_t;

/* Window Comparator Mode select */
typedef enum ADC_WINCM_enum
{
    ADC_WINCM_NONE_gc = (0x00<<0),  /* No Window Comparison */
    ADC_WINCM_BELOW_gc = (0x01<<0),  /* Below Window */
    ADC_WINCM_ABOVE_gc = (0x02<<0),  /* Above Window */
    ADC_WINCM_INSIDE_gc = (0x03<<0),  /* Inside Window */
    ADC_WINCM_OUTSIDE_gc = (0x04<<0),  /* Outside Window */
} ADC_WINCM_t;

/*
--------------------------------------------------------------------------
BOD - Bod interface
--------------------------------------------------------------------------
*/

/* Bod interface */
typedef struct BOD_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t CTRLB;  /* Control B */
    register8_t reserved_1[6];
    register8_t VLMCTRLA;  /* Voltage level monitor Control */
    register8_t INTCTRL;  /* Voltage level monitor interrupt Control */
    register8_t INTFLAGS;  /* Voltage level monitor interrupt Flags */
    register8_t STATUS;  /* Voltage level monitor status */
    register8_t reserved_2[4];
} BOD_t;

/* Operation in active mode select */
typedef enum BOD_ACTIVE_enum
{
    BOD_ACTIVE_DIS_gc = (0x00<<2),  /* Disabled */
    BOD_ACTIVE_ENABLED_gc = (0x01<<2),  /* Enabled */
    BOD_ACTIVE_SAMPLED_gc = (0x02<<2),  /* Sampled */
    BOD_ACTIVE_ENWAKE_gc = (0x03<<2),  /* Enabled with wakeup halt */
} BOD_ACTIVE_t;

/* Bod level select */
typedef enum BOD_LVL_enum
{
    BOD_LVL_BODLEVEL0_gc = (0x00<<0),  /* 1.8 V */
    BOD_LVL_BODLEVEL1_gc = (0x01<<0),  /* 2.1 V */
    BOD_LVL_BODLEVEL2_gc = (0x02<<0),  /* 2.6 V */
    BOD_LVL_BODLEVEL3_gc = (0x03<<0),  /* 2.9 V */
    BOD_LVL_BODLEVEL4_gc = (0x04<<0),  /* 3.3 V */
    BOD_LVL_BODLEVEL5_gc = (0x05<<0),  /* 3.7 V */
    BOD_LVL_BODLEVEL6_gc = (0x06<<0),  /* 4.0 V */
    BOD_LVL_BODLEVEL7_gc = (0x07<<0),  /* 4.2 V */
} BOD_LVL_t;

/* Sample frequency select */
typedef enum BOD_SAMPFREQ_enum
{
    BOD_SAMPFREQ_1KHZ_gc = (0x00<<4),  /* 1kHz sampling */
    BOD_SAMPFREQ_125Hz_gc = (0x01<<4),  /* 125Hz sampling */
} BOD_SAMPFREQ_t;

/* Operation in sleep mode select */
typedef enum BOD_SLEEP_enum
{
    BOD_SLEEP_DIS_gc = (0x00<<0),  /* Disabled */
    BOD_SLEEP_ENABLED_gc = (0x01<<0),  /* Enabled */
    BOD_SLEEP_SAMPLED_gc = (0x02<<0),  /* Sampled */
} BOD_SLEEP_t;

/* Configuration select */
typedef enum BOD_VLMCFG_enum
{
    BOD_VLMCFG_BELOW_gc = (0x00<<1),  /* Interrupt when supply goes below VLM level */
    BOD_VLMCFG_ABOVE_gc = (0x01<<1),  /* Interrupt when supply goes above VLM level */
    BOD_VLMCFG_CROSS_gc = (0x02<<1),  /* Interrupt when supply crosses VLM level */
} BOD_VLMCFG_t;

/* voltage level monitor level select */
typedef enum BOD_VLMLVL_enum
{
    BOD_VLMLVL_5ABOVE_gc = (0x00<<0),  /* VLM threshold 5% above BOD level */
    BOD_VLMLVL_15ABOVE_gc = (0x01<<0),  /* VLM threshold 15% above BOD level */
    BOD_VLMLVL_25ABOVE_gc = (0x02<<0),  /* VLM threshold 25% above BOD level */
} BOD_VLMLVL_t;

/*
--------------------------------------------------------------------------
CCL - Configurable Custom Logic
--------------------------------------------------------------------------
*/

/* Configurable Custom Logic */
typedef struct CCL_struct
{
    register8_t CTRLA;  /* Control Register A */
    register8_t SEQCTRL0;  /* Sequential Control 0 */
    register8_t reserved_1[3];
    register8_t LUT0CTRLA;  /* LUT Control 0 A */
    register8_t LUT0CTRLB;  /* LUT Control 0 B */
    register8_t LUT0CTRLC;  /* LUT Control 0 C */
    register8_t TRUTH0;  /* Truth 0 */
    register8_t LUT1CTRLA;  /* LUT Control 1 A */
    register8_t LUT1CTRLB;  /* LUT Control 1 B */
    register8_t LUT1CTRLC;  /* LUT Control 1 C */
    register8_t TRUTH1;  /* Truth 1 */
    register8_t reserved_2[3];
} CCL_t;

/* Edge Detection Enable select */
typedef enum CCL_EDGEDET_enum
{
    CCL_EDGEDET_DIS_gc = (0x00<<7),  /* Edge detector is disabled */
    CCL_EDGEDET_EN_gc = (0x01<<7),  /* Edge detector is enabled */
} CCL_EDGEDET_t;

/* Filter Selection select */
typedef enum CCL_FILTSEL_enum
{
    CCL_FILTSEL_DISABLE_gc = (0x00<<4),  /* Filter disabled */
    CCL_FILTSEL_SYNCH_gc = (0x01<<4),  /* Synchronizer enabled */
    CCL_FILTSEL_FILTER_gc = (0x02<<4),  /* Filter enabled */
} CCL_FILTSEL_t;

/* LUT Input 0 Source Selection select */
typedef enum CCL_INSEL0_enum
{
    CCL_INSEL0_MASK_gc = (0x00<<0),  /* Masked input */
    CCL_INSEL0_FEEDBACK_gc = (0x01<<0),  /* Feedback input source */
    CCL_INSEL0_LINK_gc = (0x02<<0),  /* Linked LUT input source */
    CCL_INSEL0_EVENT0_gc = (0x03<<0),  /* Event input source 0 */
    CCL_INSEL0_EVENT1_gc = (0x04<<0),  /* Event input source 1 */
    CCL_INSEL0_IO_gc = (0x05<<0),  /* IO pin LUTn-IN0 input source */
    CCL_INSEL0_AC0_gc = (0x06<<0),  /* AC0 OUT input source */
    CCL_INSEL0_TCB0_gc = (0x07<<0),  /* TCB0 WO input source */
    CCL_INSEL0_TCA0_gc = (0x08<<0),  /* TCA0 WO0 input source */
    CCL_INSEL0_TCD0_gc = (0x09<<0),  /* TCD0 WOA input source */
    CCL_INSEL0_USART0_gc = (0x0A<<0),  /* USART0 XCK input source */
    CCL_INSEL0_SPI0_gc = (0x0B<<0),  /* SPI0 SCK source */
} CCL_INSEL0_t;

/* LUT Input 1 Source Selection select */
typedef enum CCL_INSEL1_enum
{
    CCL_INSEL1_MASK_gc = (0x00<<4),  /* Masked input */
    CCL_INSEL1_FEEDBACK_gc = (0x01<<4),  /* Feedback input source */
    CCL_INSEL1_LINK_gc = (0x02<<4),  /* Linked LUT input source */
    CCL_INSEL1_EVENT0_gc = (0x03<<4),  /* Event input source 0 */
    CCL_INSEL1_EVENT1_gc = (0x04<<4),  /* Event input source 1 */
    CCL_INSEL1_IO_gc = (0x05<<4),  /* IO pin LUTn-N1 input source */
    CCL_INSEL1_AC0_gc = (0x06<<4),  /* AC0 OUT input source */
    CCL_INSEL1_TCB0_gc = (0x07<<4),  /* TCB0 WO input source */
    CCL_INSEL1_TCA0_gc = (0x08<<4),  /* TCA0 WO1 input source */
    CCL_INSEL1_TCD0_gc = (0x09<<4),  /* TCD0 WOB input source */
    CCL_INSEL1_USART0_gc = (0x0A<<4),  /* USART0 TXD input source */
    CCL_INSEL1_SPI0_gc = (0x0B<<4),  /* SPI0 MOSI input source */
} CCL_INSEL1_t;

/* LUT Input 2 Source Selection select */
typedef enum CCL_INSEL2_enum
{
    CCL_INSEL2_MASK_gc = (0x00<<0),  /* Masked input */
    CCL_INSEL2_FEEDBACK_gc = (0x01<<0),  /* Feedback input source */
    CCL_INSEL2_LINK_gc = (0x02<<0),  /* Linked LUT input source */
    CCL_INSEL2_EVENT0_gc = (0x03<<0),  /* Event input source 0 */
    CCL_INSEL2_EVENT1_gc = (0x04<<0),  /* Event input source 1 */
    CCL_INSEL2_IO_gc = (0x05<<0),  /* IO pin LUTn-IN2 input source */
    CCL_INSEL2_AC0_gc = (0x06<<0),  /* AC0 OUT input source */
    CCL_INSEL2_TCB0_gc = (0x07<<0),  /* TCB0 WO input source */
    CCL_INSEL2_TCA0_gc = (0x08<<0),  /* TCA0 WO2 input source */
    CCL_INSEL2_TCD0_gc = (0x09<<0),  /* TCD0 WOA input source */
    CCL_INSEL2_SPI0_gc = (0x0B<<0),  /* SPI0 MISO source */
} CCL_INSEL2_t;

/* Sequential Selection select */
typedef enum CCL_SEQSEL_enum
{
    CCL_SEQSEL_DISABLE_gc = (0x00<<0),  /* Sequential logic disabled */
    CCL_SEQSEL_DFF_gc = (0x01<<0),  /* D FlipFlop */
    CCL_SEQSEL_JK_gc = (0x02<<0),  /* JK FlipFlop */
    CCL_SEQSEL_LATCH_gc = (0x03<<0),  /* D Latch */
    CCL_SEQSEL_RS_gc = (0x04<<0),  /* RS Latch */
} CCL_SEQSEL_t;

/*
--------------------------------------------------------------------------
CLKCTRL - Clock controller
--------------------------------------------------------------------------
*/

/* Clock controller */
typedef struct CLKCTRL_struct
{
    register8_t MCLKCTRLA;  /* MCLK Control A */
    register8_t MCLKCTRLB;  /* MCLK Control B */
    register8_t MCLKLOCK;  /* MCLK Lock */
    register8_t MCLKSTATUS;  /* MCLK Status */
    register8_t reserved_1[12];
    register8_t OSC20MCTRLA;  /* OSC20M Control A */
    register8_t OSC20MCALIBA;  /* OSC20M Calibration A */
    register8_t OSC20MCALIBB;  /* OSC20M Calibration B */
    register8_t reserved_2[5];
    register8_t OSC32KCTRLA;  /* OSC32K Control A */
    register8_t reserved_3[3];
    register8_t XOSC32KCTRLA;  /* XOSC32K Control A */
    register8_t reserved_4[3];
} CLKCTRL_t;

/* clock select select */
typedef enum CLKCTRL_CLKSEL_enum
{
    CLKCTRL_CLKSEL_OSC20M_gc = (0x00<<0),  /* 20MHz internal oscillator */
    CLKCTRL_CLKSEL_OSCULP32K_gc = (0x01<<0),  /* 32KHz internal Ultra Low Power oscillator */
    CLKCTRL_CLKSEL_XOSC32K_gc = (0x02<<0),  /* 32.768kHz external crystal oscillator */
    CLKCTRL_CLKSEL_EXTCLK_gc = (0x03<<0),  /* External clock */
} CLKCTRL_CLKSEL_t;

/* Crystal startup time select */
typedef enum CLKCTRL_CSUT_enum
{
    CLKCTRL_CSUT_1K_gc = (0x00<<4),  /* 1K cycles */
    CLKCTRL_CSUT_16K_gc = (0x01<<4),  /* 16K cycles */
    CLKCTRL_CSUT_32K_gc = (0x02<<4),  /* 32K cycles */
    CLKCTRL_CSUT_64K_gc = (0x03<<4),  /* 64K cycles */
} CLKCTRL_CSUT_t;

/* Prescaler division select */
typedef enum CLKCTRL_PDIV_enum
{
    CLKCTRL_PDIV_2X_gc = (0x00<<1),  /* 2X */
    CLKCTRL_PDIV_4X_gc = (0x01<<1),  /* 4X */
    CLKCTRL_PDIV_8X_gc = (0x02<<1),  /* 8X */
    CLKCTRL_PDIV_16X_gc = (0x03<<1),  /* 16X */
    CLKCTRL_PDIV_32X_gc = (0x04<<1),  /* 32X */
    CLKCTRL_PDIV_64X_gc = (0x05<<1),  /* 64X */
    CLKCTRL_PDIV_6X_gc = (0x08<<1),  /* 6X */
    CLKCTRL_PDIV_10X_gc = (0x09<<1),  /* 10X */
    CLKCTRL_PDIV_12X_gc = (0x0A<<1),  /* 12X */
    CLKCTRL_PDIV_24X_gc = (0x0B<<1),  /* 24X */
    CLKCTRL_PDIV_48X_gc = (0x0C<<1),  /* 48X */
} CLKCTRL_PDIV_t;

/*
--------------------------------------------------------------------------
CPU - CPU
--------------------------------------------------------------------------
*/

/* CCP signature select */
typedef enum CCP_enum
{
    CCP_SPM_gc = (0x9D<<0),  /* SPM Instruction Protection */
    CCP_IOREG_gc = (0xD8<<0),  /* IO Register Protection */
} CCP_t;

/*
--------------------------------------------------------------------------
CPUINT - Interrupt Controller
--------------------------------------------------------------------------
*/

/* Interrupt Controller */
typedef struct CPUINT_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t STATUS;  /* Status */
    register8_t LVL0PRI;  /* Interrupt Level 0 Priority */
    register8_t LVL1VEC;  /* Interrupt Level 1 Priority Vector */
} CPUINT_t;


/*
--------------------------------------------------------------------------
CRCSCAN - CRCSCAN
--------------------------------------------------------------------------
*/

/* CRCSCAN */
typedef struct CRCSCAN_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t CTRLB;  /* Control B */
    register8_t STATUS;  /* Status */
    register8_t reserved_1[1];
} CRCSCAN_t;

/* CRC Flash Access Mode select */
typedef enum CRCSCAN_MODE_enum
{
    CRCSCAN_MODE_PRIORITY_gc = (0x00<<4),  /* Priority to flash */
    CRCSCAN_MODE_RESERVED_gc = (0x01<<4),  /* Reserved */
    CRCSCAN_MODE_BACKGROUND_gc = (0x02<<4),  /* Lowest priority to flash */
    CRCSCAN_MODE_CONTINUOUS_gc = (0x03<<4),  /* Continuous checks in background */
} CRCSCAN_MODE_t;

/* CRC Source select */
typedef enum CRCSCAN_SRC_enum
{
    CRCSCAN_SRC_FLASH_gc = (0x00<<0),  /* CRC on entire flash */
    CRCSCAN_SRC_APPLICATION_gc = (0x01<<0),  /* CRC on boot and appl section of flash */
    CRCSCAN_SRC_BOOT_gc = (0x02<<0),  /* CRC on boot section of flash */
} CRCSCAN_SRC_t;

/*
--------------------------------------------------------------------------
DAC - Digital to Analog Converter
--------------------------------------------------------------------------
*/

/* Digital to Analog Converter */
typedef struct DAC_struct
{
    register8_t CTRLA;  /* Control Register A */
    register8_t DATA;  /* DATA Register */
    register8_t reserved_1[2];
} DAC_t;


/*
--------------------------------------------------------------------------
EVSYS - Event System
--------------------------------------------------------------------------
*/

/* Event System */
typedef struct EVSYS_struct
{
    register8_t ASYNCSTROBE;  /* Asynchronous Channel Strobe */
    register8_t SYNCSTROBE;  /* Synchronous Channel Strobe */
    register8_t ASYNCCH0;  /* Asynchronous Channel 0 Generator Selection */
    register8_t ASYNCCH1;  /* Asynchronous Channel 1 Generator Selection */
    register8_t ASYNCCH2;  /* Asynchronous Channel 2 Generator Selection */
    register8_t ASYNCCH3;  /* Asynchronous Channel 3 Generator Selection */
    register8_t reserved_1[4];
    register8_t SYNCCH0;  /* Synchronous Channel 0 Generator Selection */
    register8_t SYNCCH1;  /* Synchronous Channel 1 Generator Selection */
    register8_t reserved_2[6];
    register8_t ASYNCUSER0;  /* Asynchronous User Ch 0 Input Selection - TCB0 */
    register8_t ASYNCUSER1;  /* Asynchronous User Ch 1 Input Selection - ADC0 */
    register8_t ASYNCUSER2;  /* Asynchronous User Ch 2 Input Selection - CCL LUT0 Event 0 */
    register8_t ASYNCUSER3;  /* Asynchronous User Ch 3 Input Selection - CCL LUT1 Event 0 */
    register8_t ASYNCUSER4;  /* Asynchronous User Ch 4 Input Selection - CCL LUT0 Event 1 */
    register8_t ASYNCUSER5;  /* Asynchronous User Ch 5 Input Selection - CCL LUT1 Event 1 */
    register8_t ASYNCUSER6;  /* Asynchronous User Ch 6 Input Selection - TCD0 Event 0 */
    register8_t ASYNCUSER7;  /* Asynchronous User Ch 7 Input Selection - TCD0 Event 1 */
    register8_t ASYNCUSER8;  /* Asynchronous User Ch 8 Input Selection - Event Out 0 */
    register8_t ASYNCUSER9;  /* Asynchronous User Ch 9 Input Selection - Event Out 1 */
    register8_t ASYNCUSER10;  /* Asynchronous User Ch 10 Input Selection - Event Out 2 */
    register8_t reserved_3[5];
    register8_t SYNCUSER0;  /* Synchronous User Ch 0 Input Selection - TCA0 */
    register8_t SYNCUSER1;  /* Synchronous User Ch 1 Input Selection - USART0 */
    register8_t reserved_4[28];
} EVSYS_t;

/* Asynchronous Channel 0 Generator Selection select */
typedef enum EVSYS_ASYNCCH0_enum
{
    EVSYS_ASYNCCH0_OFF_gc = (0x00<<0),  /* Off */
    EVSYS_ASYNCCH0_CCL_LUT0_gc = (0x01<<0),  /* Configurable Custom Logic LUT0 */
    EVSYS_ASYNCCH0_CCL_LUT1_gc = (0x02<<0),  /* Configurable Custom Logic LUT1 */
    EVSYS_ASYNCCH0_AC0_OUT_gc = (0x03<<0),  /* Analog Comparator 0 out */
    EVSYS_ASYNCCH0_TCD0_CMPBCLR_gc = (0x04<<0),  /* Timer/Counter D0 compare B clear */
    EVSYS_ASYNCCH0_TCD0_CMPASET_gc = (0x05<<0),  /* Timer/Counter D0 compare A set */
    EVSYS_ASYNCCH0_TCD0_CMPBSET_gc = (0x06<<0),  /* Timer/Counter D0 compare B set */
    EVSYS_ASYNCCH0_TCD0_PROGEV_gc = (0x07<<0),  /* Timer/Counter D0 program event */
    EVSYS_ASYNCCH0_RTC_OVF_gc = (0x08<<0),  /* Real Time Counter overflow */
    EVSYS_ASYNCCH0_RTC_CMP_gc = (0x09<<0),  /* Real Time Counter compare */
    EVSYS_ASYNCCH0_PORTA_PIN0_gc = (0x0A<<0),  /* Asynchronous Event from Pin PA0 */
    EVSYS_ASYNCCH0_PORTA_PIN1_gc = (0x0B<<0),  /* Asynchronous Event from Pin PA1 */
    EVSYS_ASYNCCH0_PORTA_PIN2_gc = (0x0C<<0),  /* Asynchronous Event from Pin PA2 */
    EVSYS_ASYNCCH0_PORTA_PIN3_gc = (0x0D<<0),  /* Asynchronous Event from Pin PA3 */
    EVSYS_ASYNCCH0_PORTA_PIN4_gc = (0x0E<<0),  /* Asynchronous Event from Pin PA4 */
    EVSYS_ASYNCCH0_PORTA_PIN5_gc = (0x0F<<0),  /* Asynchronous Event from Pin PA5 */
    EVSYS_ASYNCCH0_PORTA_PIN6_gc = (0x10<<0),  /* Asynchronous Event from Pin PA6 */
    EVSYS_ASYNCCH0_PORTA_PIN7_gc = (0x11<<0),  /* Asynchronous Event from Pin PA7 */
    EVSYS_ASYNCCH0_UPDI_gc = (0x12<<0),  /* Unified Program and debug interface */
} EVSYS_ASYNCCH0_t;

/* Asynchronous Channel 1 Generator Selection select */
typedef enum EVSYS_ASYNCCH1_enum
{
    EVSYS_ASYNCCH1_OFF_gc = (0x00<<0),  /* Off */
    EVSYS_ASYNCCH1_CCL_LUT0_gc = (0x01<<0),  /* Configurable custom logic LUT0 */
    EVSYS_ASYNCCH1_CCL_LUT1_gc = (0x02<<0),  /* Configurable custom logic LUT1 */
    EVSYS_ASYNCCH1_AC0_OUT_gc = (0x03<<0),  /* Analog Comparator 0 out */
    EVSYS_ASYNCCH1_TCD0_CMPBCLR_gc = (0x04<<0),  /* Timer/Counter D0 compare B clear */
    EVSYS_ASYNCCH1_TCD0_CMPASET_gc = (0x05<<0),  /* Timer/Counter D0 compare A set */
    EVSYS_ASYNCCH1_TCD0_CMPBSET_gc = (0x06<<0),  /* Timer/Counter D0 compare B set */
    EVSYS_ASYNCCH1_TCD0_PROGEV_gc = (0x07<<0),  /* Timer/Counter D0 program event */
    EVSYS_ASYNCCH1_RTC_OVF_gc = (0x08<<0),  /* Real Time Counter overflow */
    EVSYS_ASYNCCH1_RTC_CMP_gc = (0x09<<0),  /* Real Time Counter compare */
    EVSYS_ASYNCCH1_PORTB_PIN0_gc = (0x0A<<0),  /* Asynchronous Event from Pin PB0 */
    EVSYS_ASYNCCH1_PORTB_PIN1_gc = (0x0B<<0),  /* Asynchronous Event from Pin PB1 */
    EVSYS_ASYNCCH1_PORTB_PIN2_gc = (0x0C<<0),  /* Asynchronous Event from Pin PB2 */
    EVSYS_ASYNCCH1_PORTB_PIN3_gc = (0x0D<<0),  /* Asynchronous Event from Pin PB3 */
    EVSYS_ASYNCCH1_PORTB_PIN4_gc = (0x0E<<0),  /* Asynchronous Event from Pin PB4 */
    EVSYS_ASYNCCH1_PORTB_PIN5_gc = (0x0F<<0),  /* Asynchronous Event from Pin PB5 */
    EVSYS_ASYNCCH1_PORTB_PIN6_gc = (0x10<<0),  /* Asynchronous Event from Pin PB6 */
    EVSYS_ASYNCCH1_PORTB_PIN7_gc = (0x11<<0),  /* Asynchronous Event from Pin PB7 */
} EVSYS_ASYNCCH1_t;

/* Asynchronous Channel 2 Generator Selection select */
typedef enum EVSYS_ASYNCCH2_enum
{
    EVSYS_ASYNCCH2_OFF_gc = (0x00<<0),  /* Off */
    EVSYS_ASYNCCH2_CCL_LUT0_gc = (0x01<<0),  /* Configurable Custom Logic LUT0 */
    EVSYS_ASYNCCH2_CCL_LUT1_gc = (0x02<<0),  /* Configurable Custom Logic LUT1 */
    EVSYS_ASYNCCH2_AC0_OUT_gc = (0x03<<0),  /* Analog Comparator 0 out */
    EVSYS_ASYNCCH2_TCD0_CMPBCLR_gc = (0x04<<0),  /* Timer/Counter D0 compare B clear */
    EVSYS_ASYNCCH2_TCD0_CMPASET_gc = (0x05<<0),  /* Timer/Counter D0 compare A set */
    EVSYS_ASYNCCH2_TCD0_CMPBSET_gc = (0x06<<0),  /* Timer/Counter D0 compare B set */
    EVSYS_ASYNCCH2_TCD0_PROGEV_gc = (0x07<<0),  /* Timer/Counter D0 program event */
    EVSYS_ASYNCCH2_RTC_OVF_gc = (0x08<<0),  /* Real Time Counter overflow */
    EVSYS_ASYNCCH2_RTC_CMP_gc = (0x09<<0),  /* Real Time Counter compare */
    EVSYS_ASYNCCH2_PORTC_PIN0_gc = (0x0A<<0),  /* Asynchronous Event from Pin PC0 */
    EVSYS_ASYNCCH2_PORTC_PIN1_gc = (0x0B<<0),  /* Asynchronous Event from Pin PC1 */
    EVSYS_ASYNCCH2_PORTC_PIN2_gc = (0x0C<<0),  /* Asynchronous Event from Pin PC2 */
    EVSYS_ASYNCCH2_PORTC_PIN3_gc = (0x0D<<0),  /* Asynchronous Event from Pin PC3 */
    EVSYS_ASYNCCH2_PORTC_PIN4_gc = (0x0E<<0),  /* Asynchronous Event from Pin PC4 */
    EVSYS_ASYNCCH2_PORTC_PIN5_gc = (0x0F<<0),  /* Asynchronous Event from Pin PC5 */
} EVSYS_ASYNCCH2_t;

/* Asynchronous Channel 3 Generator Selection select */
typedef enum EVSYS_ASYNCCH3_enum
{
    EVSYS_ASYNCCH3_OFF_gc = (0x00<<0),  /* Off */
    EVSYS_ASYNCCH3_CCL_LUT0_gc = (0x01<<0),  /* Configurable custom logic LUT0 */
    EVSYS_ASYNCCH3_CCL_LUT1_gc = (0x02<<0),  /* Configurable custom logic LUT1 */
    EVSYS_ASYNCCH3_AC0_OUT_gc = (0x03<<0),  /* Analog Comparator 0 out */
    EVSYS_ASYNCCH3_TCD0_CMPBCLR_gc = (0x04<<0),  /* Timer/Counter type D compare B clear */
    EVSYS_ASYNCCH3_TCD0_CMPASET_gc = (0x05<<0),  /* Timer/Counter type D compare A set */
    EVSYS_ASYNCCH3_TCD0_CMPBSET_gc = (0x06<<0),  /* Timer/Counter type D compare B set */
    EVSYS_ASYNCCH3_TCD0_PROGEV_gc = (0x07<<0),  /* Timer/Counter type D program event */
    EVSYS_ASYNCCH3_RTC_OVF_gc = (0x08<<0),  /* Real Time Counter overflow */
    EVSYS_ASYNCCH3_RTC_CMP_gc = (0x09<<0),  /* Real Time Counter compare */
    EVSYS_ASYNCCH3_PIT_DIV8192_gc = (0x0A<<0),  /* Periodic Interrupt CLK_RTC div 8192 */
    EVSYS_ASYNCCH3_PIT_DIV4096_gc = (0x0B<<0),  /* Periodic Interrupt CLK_RTC div 4096 */
    EVSYS_ASYNCCH3_PIT_DIV2048_gc = (0x0C<<0),  /* Periodic Interrupt CLK_RTC div 2048 */
    EVSYS_ASYNCCH3_PIT_DIV1024_gc = (0x0D<<0),  /* Periodic Interrupt CLK_RTC div 1024 */
    EVSYS_ASYNCCH3_PIT_DIV512_gc = (0x0E<<0),  /* Periodic Interrupt CLK_RTC div 512 */
    EVSYS_ASYNCCH3_PIT_DIV256_gc = (0x0F<<0),  /* Periodic Interrupt CLK_RTC div 256 */
    EVSYS_ASYNCCH3_PIT_DIV128_gc = (0x10<<0),  /* Periodic Interrupt CLK_RTC div 128 */
    EVSYS_ASYNCCH3_PIT_DIV64_gc = (0x11<<0),  /* Periodic Interrupt CLK_RTC div 64 */
} EVSYS_ASYNCCH3_t;

/* Asynchronous User Ch 0 Input Selection - TCB0 select */
typedef enum EVSYS_ASYNCUSER0_enum
{
    EVSYS_ASYNCUSER0_OFF_gc = (0x00<<0),  /* Off */
    EVSYS_ASYNCUSER0_SYNCCH0_gc = (0x01<<0),  /* Synchronous Event Channel 0 */
    EVSYS_ASYNCUSER0_SYNCCH1_gc = (0x02<<0),  /* Synchronous Event Channel 1 */
    EVSYS_ASYNCUSER0_ASYNCCH0_gc = (0x03<<0),  /* Asynchronous Event Channel 0 */
    EVSYS_ASYNCUSER0_ASYNCCH1_gc = (0x04<<0),  /* Asynchronous Event Channel 1 */
    EVSYS_ASYNCUSER0_ASYNCCH2_gc = (0x05<<0),  /* Asynchronous Event Channel 2 */
    EVSYS_ASYNCUSER0_ASYNCCH3_gc = (0x06<<0),  /* Asynchronous Event Channel 3 */
} EVSYS_ASYNCUSER0_t;

/* Asynchronous User Ch 1 Input Selection - ADC0 select */
typedef enum EVSYS_ASYNCUSER1_enum
{
    EVSYS_ASYNCUSER1_OFF_gc = (0x00<<0),  /* Off */
    EVSYS_ASYNCUSER1_SYNCCH0_gc = (0x01<<0),  /* Synchronous Event Channel 0 */
    EVSYS_ASYNCUSER1_SYNCCH1_gc = (0x02<<0),  /* Synchronous Event Channel 1 */
    EVSYS_ASYNCUSER1_ASYNCCH0_gc = (0x03<<0),  /* Asynchronous Event Channel 0 */
    EVSYS_ASYNCUSER1_ASYNCCH1_gc = (0x04<<0),  /* Asynchronous Event Channel 1 */
    EVSYS_ASYNCUSER1_ASYNCCH2_gc = (0x05<<0),  /* Asynchronous Event Channel 2 */
    EVSYS_ASYNCUSER1_ASYNCCH3_gc = (0x06<<0),  /* Asynchronous Event Channel 3 */
} EVSYS_ASYNCUSER1_t;

/* Asynchronous User Ch 10 Input Selection - Event Out 2 select */
typedef enum EVSYS_ASYNCUSER10_enum
{
    EVSYS_ASYNCUSER10_OFF_gc = (0x00<<0),  /* Off */
    EVSYS_ASYNCUSER10_SYNCCH0_gc = (0x01<<0),  /* Synchronous Event Channel 0 */
    EVSYS_ASYNCUSER10_SYNCCH1_gc = (0x02<<0),  /* Synchronous Event Channel 1 */
    EVSYS_ASYNCUSER10_ASYNCCH0_gc = (0x03<<0),  /* Asynchronous Event Channel 0 */
    EVSYS_ASYNCUSER10_ASYNCCH1_gc = (0x04<<0),  /* Asynchronous Event Channel 1 */
    EVSYS_ASYNCUSER10_ASYNCCH2_gc = (0x05<<0),  /* Asynchronous Event Channel 2 */
    EVSYS_ASYNCUSER10_ASYNCCH3_gc = (0x06<<0),  /* Asynchronous Event Channel 3 */
} EVSYS_ASYNCUSER10_t;

/* Asynchronous User Ch 2 Input Selection - CCL LUT0 Event 0 select */
typedef enum EVSYS_ASYNCUSER2_enum
{
    EVSYS_ASYNCUSER2_OFF_gc = (0x00<<0),  /* Off */
    EVSYS_ASYNCUSER2_SYNCCH0_gc = (0x01<<0),  /* Synchronous Event Channel 0 */
    EVSYS_ASYNCUSER2_SYNCCH1_gc = (0x02<<0),  /* Synchronous Event Channel 1 */
    EVSYS_ASYNCUSER2_ASYNCCH0_gc = (0x03<<0),  /* Asynchronous Event Channel 0 */
    EVSYS_ASYNCUSER2_ASYNCCH1_gc = (0x04<<0),  /* Asynchronous Event Channel 1 */
    EVSYS_ASYNCUSER2_ASYNCCH2_gc = (0x05<<0),  /* Asynchronous Event Channel 2 */
    EVSYS_ASYNCUSER2_ASYNCCH3_gc = (0x06<<0),  /* Asynchronous Event Channel 3 */
} EVSYS_ASYNCUSER2_t;

/* Asynchronous User Ch 3 Input Selection - CCL LUT1 Event 0 select */
typedef enum EVSYS_ASYNCUSER3_enum
{
    EVSYS_ASYNCUSER3_OFF_gc = (0x00<<0),  /* Off */
    EVSYS_ASYNCUSER3_SYNCCH0_gc = (0x01<<0),  /* Synchronous Event Channel 0 */
    EVSYS_ASYNCUSER3_SYNCCH1_gc = (0x02<<0),  /* Synchronous Event Channel 1 */
    EVSYS_ASYNCUSER3_ASYNCCH0_gc = (0x03<<0),  /* Asynchronous Event Channel 0 */
    EVSYS_ASYNCUSER3_ASYNCCH1_gc = (0x04<<0),  /* Asynchronous Event Channel 1 */
    EVSYS_ASYNCUSER3_ASYNCCH2_gc = (0x05<<0),  /* Asynchronous Event Channel 2 */
    EVSYS_ASYNCUSER3_ASYNCCH3_gc = (0x06<<0),  /* Asynchronous Event Channel 3 */
} EVSYS_ASYNCUSER3_t;

/* Asynchronous User Ch 4 Input Selection - CCL LUT0 Event 1 select */
typedef enum EVSYS_ASYNCUSER4_enum
{
    EVSYS_ASYNCUSER4_OFF_gc = (0x00<<0),  /* Off */
    EVSYS_ASYNCUSER4_SYNCCH0_gc = (0x01<<0),  /* Synchronous Event Channel 0 */
    EVSYS_ASYNCUSER4_SYNCCH1_gc = (0x02<<0),  /* Synchronous Event Channel 1 */
    EVSYS_ASYNCUSER4_ASYNCCH0_gc = (0x03<<0),  /* Asynchronous Event Channel 0 */
    EVSYS_ASYNCUSER4_ASYNCCH1_gc = (0x04<<0),  /* Asynchronous Event Channel 1 */
    EVSYS_ASYNCUSER4_ASYNCCH2_gc = (0x05<<0),  /* Asynchronous Event Channel 2 */
    EVSYS_ASYNCUSER4_ASYNCCH3_gc = (0x06<<0),  /* Asynchronous Event Channel 3 */
} EVSYS_ASYNCUSER4_t;

/* Asynchronous User Ch 5 Input Selection - CCL LUT1 Event 1 select */
typedef enum EVSYS_ASYNCUSER5_enum
{
    EVSYS_ASYNCUSER5_OFF_gc = (0x00<<0),  /* Off */
    EVSYS_ASYNCUSER5_SYNCCH0_gc = (0x01<<0),  /* Synchronous Event Channel 0 */
    EVSYS_ASYNCUSER5_SYNCCH1_gc = (0x02<<0),  /* Synchronous Event Channel 1 */
    EVSYS_ASYNCUSER5_ASYNCCH0_gc = (0x03<<0),  /* Asynchronous Event Channel 0 */
    EVSYS_ASYNCUSER5_ASYNCCH1_gc = (0x04<<0),  /* Asynchronous Event Channel 1 */
    EVSYS_ASYNCUSER5_ASYNCCH2_gc = (0x05<<0),  /* Asynchronous Event Channel 2 */
    EVSYS_ASYNCUSER5_ASYNCCH3_gc = (0x06<<0),  /* Asynchronous Event Channel 3 */
} EVSYS_ASYNCUSER5_t;

/* Asynchronous User Ch 6 Input Selection - TCD0 Event 0 select */
typedef enum EVSYS_ASYNCUSER6_enum
{
    EVSYS_ASYNCUSER6_OFF_gc = (0x00<<0),  /* Off */
    EVSYS_ASYNCUSER6_SYNCCH0_gc = (0x01<<0),  /* Synchronous Event Channel 0 */
    EVSYS_ASYNCUSER6_SYNCCH1_gc = (0x02<<0),  /* Synchronous Event Channel 1 */
    EVSYS_ASYNCUSER6_ASYNCCH0_gc = (0x03<<0),  /* Asynchronous Event Channel 0 */
    EVSYS_ASYNCUSER6_ASYNCCH1_gc = (0x04<<0),  /* Asynchronous Event Channel 1 */
    EVSYS_ASYNCUSER6_ASYNCCH2_gc = (0x05<<0),  /* Asynchronous Event Channel 2 */
    EVSYS_ASYNCUSER6_ASYNCCH3_gc = (0x06<<0),  /* Asynchronous Event Channel 3 */
} EVSYS_ASYNCUSER6_t;

/* Asynchronous User Ch 7 Input Selection - TCD0 Event 1 select */
typedef enum EVSYS_ASYNCUSER7_enum
{
    EVSYS_ASYNCUSER7_OFF_gc = (0x00<<0),  /* Off */
    EVSYS_ASYNCUSER7_SYNCCH0_gc = (0x01<<0),  /* Synchronous Event Channel 0 */
    EVSYS_ASYNCUSER7_SYNCCH1_gc = (0x02<<0),  /* Synchronous Event Channel 1 */
    EVSYS_ASYNCUSER7_ASYNCCH0_gc = (0x03<<0),  /* Asynchronous Event Channel 0 */
    EVSYS_ASYNCUSER7_ASYNCCH1_gc = (0x04<<0),  /* Asynchronous Event Channel 1 */
    EVSYS_ASYNCUSER7_ASYNCCH2_gc = (0x05<<0),  /* Asynchronous Event Channel 2 */
    EVSYS_ASYNCUSER7_ASYNCCH3_gc = (0x06<<0),  /* Asynchronous Event Channel 3 */
} EVSYS_ASYNCUSER7_t;

/* Asynchronous User Ch 8 Input Selection - Event Out 0 select */
typedef enum EVSYS_ASYNCUSER8_enum
{
    EVSYS_ASYNCUSER8_OFF_gc = (0x00<<0),  /* Off */
    EVSYS_ASYNCUSER8_SYNCCH0_gc = (0x01<<0),  /* Synchronous Event Channel 0 */
    EVSYS_ASYNCUSER8_SYNCCH1_gc = (0x02<<0),  /* Synchronous Event Channel 1 */
    EVSYS_ASYNCUSER8_ASYNCCH0_gc = (0x03<<0),  /* Asynchronous Event Channel 0 */
    EVSYS_ASYNCUSER8_ASYNCCH1_gc = (0x04<<0),  /* Asynchronous Event Channel 1 */
    EVSYS_ASYNCUSER8_ASYNCCH2_gc = (0x05<<0),  /* Asynchronous Event Channel 2 */
    EVSYS_ASYNCUSER8_ASYNCCH3_gc = (0x06<<0),  /* Asynchronous Event Channel 3 */
} EVSYS_ASYNCUSER8_t;

/* Asynchronous User Ch 9 Input Selection - Event Out 1 select */
typedef enum EVSYS_ASYNCUSER9_enum
{
    EVSYS_ASYNCUSER9_OFF_gc = (0x00<<0),  /* Off */
    EVSYS_ASYNCUSER9_SYNCCH0_gc = (0x01<<0),  /* Synchronous Event Channel 0 */
    EVSYS_ASYNCUSER9_SYNCCH1_gc = (0x02<<0),  /* Synchronous Event Channel 1 */
    EVSYS_ASYNCUSER9_ASYNCCH0_gc = (0x03<<0),  /* Asynchronous Event Channel 0 */
    EVSYS_ASYNCUSER9_ASYNCCH1_gc = (0x04<<0),  /* Asynchronous Event Channel 1 */
    EVSYS_ASYNCUSER9_ASYNCCH2_gc = (0x05<<0),  /* Asynchronous Event Channel 2 */
    EVSYS_ASYNCUSER9_ASYNCCH3_gc = (0x06<<0),  /* Asynchronous Event Channel 3 */
} EVSYS_ASYNCUSER9_t;

/* Synchronous Channel 0 Generator Selection select */
typedef enum EVSYS_SYNCCH0_enum
{
    EVSYS_SYNCCH0_OFF_gc = (0x00<<0),  /* Off */
    EVSYS_SYNCCH0_TCB0_gc = (0x01<<0),  /* Timer/Counter B0 */
    EVSYS_SYNCCH0_TCA0_OVF_LUNF_gc = (0x02<<0),  /* Timer/Counter A0 overflow */
    EVSYS_SYNCCH0_TCA0_HUNF_gc = (0x03<<0),  /* Timer/Counter A0 underflow high byte (split mode) */
    EVSYS_SYNCCH0_TCA0_CMP0_gc = (0x04<<0),  /* Timer/Counter A0 compare 0 */
    EVSYS_SYNCCH0_TCA0_CMP1_gc = (0x05<<0),  /* Timer/Counter A0 compare 1 */
    EVSYS_SYNCCH0_TCA0_CMP2_gc = (0x06<<0),  /* Timer/Counter A0 compare 2 */
    EVSYS_SYNCCH0_PORTC_PIN0_gc = (0x07<<0),  /* Synchronous Event from Pin PC0 */
    EVSYS_SYNCCH0_PORTC_PIN1_gc = (0x08<<0),  /* Synchronous Event from Pin PC1 */
    EVSYS_SYNCCH0_PORTC_PIN2_gc = (0x09<<0),  /* Synchronous Event from Pin PC2 */
    EVSYS_SYNCCH0_PORTC_PIN3_gc = (0x0A<<0),  /* Synchronous Event from Pin PC3 */
    EVSYS_SYNCCH0_PORTC_PIN4_gc = (0x0B<<0),  /* Synchronous Event from Pin PC4 */
    EVSYS_SYNCCH0_PORTC_PIN5_gc = (0x0C<<0),  /* Synchronous Event from Pin PC5 */
    EVSYS_SYNCCH0_PORTA_PIN0_gc = (0x0D<<0),  /* Synchronous Event from Pin PA0 */
    EVSYS_SYNCCH0_PORTA_PIN1_gc = (0x0E<<0),  /* Synchronous Event from Pin PA1 */
    EVSYS_SYNCCH0_PORTA_PIN2_gc = (0x0F<<0),  /* Synchronous Event from Pin PA2 */
    EVSYS_SYNCCH0_PORTA_PIN3_gc = (0x10<<0),  /* Synchronous Event from Pin PA3 */
    EVSYS_SYNCCH0_PORTA_PIN4_gc = (0x11<<0),  /* Synchronous Event from Pin PA4 */
    EVSYS_SYNCCH0_PORTA_PIN5_gc = (0x12<<0),  /* Synchronous Event from Pin PA5 */
    EVSYS_SYNCCH0_PORTA_PIN6_gc = (0x13<<0),  /* Synchronous Event from Pin PA6 */
    EVSYS_SYNCCH0_PORTA_PIN7_gc = (0x14<<0),  /* Synchronous Event from Pin PA7 */
} EVSYS_SYNCCH0_t;

/* Synchronous Channel 1 Generator Selection select */
typedef enum EVSYS_SYNCCH1_enum
{
    EVSYS_SYNCCH1_OFF_gc = (0x00<<0),  /* Off */
    EVSYS_SYNCCH1_TCB0_gc = (0x01<<0),  /* Timer/Counter B0 */
    EVSYS_SYNCCH1_TCA0_OVF_LUNF_gc = (0x02<<0),  /* Timer/Counter A0 overflow */
    EVSYS_SYNCCH1_TCA0_HUNF_gc = (0x03<<0),  /* Timer/Counter A0 underflow high byte (split mode) */
    EVSYS_SYNCCH1_TCA0_CMP0_gc = (0x04<<0),  /* Timer/Counter A0 compare 0 */
    EVSYS_SYNCCH1_TCA0_CMP1_gc = (0x05<<0),  /* Timer/Counter A0 compare 1 */
    EVSYS_SYNCCH1_TCA0_CMP2_gc = (0x06<<0),  /* Timer/Counter A0 compare 2 */
    EVSYS_SYNCCH1_PORTB_PIN0_gc = (0x08<<0),  /* Synchronous Event from Pin PB0 */
    EVSYS_SYNCCH1_PORTB_PIN1_gc = (0x09<<0),  /* Synchronous Event from Pin PB1 */
    EVSYS_SYNCCH1_PORTB_PIN2_gc = (0x0A<<0),  /* Synchronous Event from Pin PB2 */
    EVSYS_SYNCCH1_PORTB_PIN3_gc = (0x0B<<0),  /* Synchronous Event from Pin PB3 */
    EVSYS_SYNCCH1_PORTB_PIN4_gc = (0x0C<<0),  /* Synchronous Event from Pin PB4 */
    EVSYS_SYNCCH1_PORTB_PIN5_gc = (0x0D<<0),  /* Synchronous Event from Pin PB5 */
    EVSYS_SYNCCH1_PORTB_PIN6_gc = (0x0E<<0),  /* Synchronous Event from Pin PB6 */
    EVSYS_SYNCCH1_PORTB_PIN7_gc = (0x0F<<0),  /* Synchronous Event from Pin PB7 */
} EVSYS_SYNCCH1_t;

/* Synchronous User Ch 0 Input Selection - TCA0 select */
typedef enum EVSYS_SYNCUSER0_enum
{
    EVSYS_SYNCUSER0_OFF_gc = (0x00<<0),  /* Off */
    EVSYS_SYNCUSER0_SYNCCH0_gc = (0x01<<0),  /* Synchronous Event Channel 0 */
    EVSYS_SYNCUSER0_SYNCCH1_gc = (0x02<<0),  /* Synchronous Event Channel 1 */
} EVSYS_SYNCUSER0_t;

/* Synchronous User Ch 1 Input Selection - USART0 select */
typedef enum EVSYS_SYNCUSER1_enum
{
    EVSYS_SYNCUSER1_OFF_gc = (0x00<<0),  /* Off */
    EVSYS_SYNCUSER1_SYNCCH0_gc = (0x01<<0),  /* Synchronous Event Channel 0 */
    EVSYS_SYNCUSER1_SYNCCH1_gc = (0x02<<0),  /* Synchronous Event Channel 1 */
} EVSYS_SYNCUSER1_t;

/*
--------------------------------------------------------------------------
FUSE - Fuses
--------------------------------------------------------------------------
*/

/* Fuses */
typedef struct FUSE_struct
{
    register8_t WDTCFG;  /* Watchdog Configuration */
    register8_t BODCFG;  /* BOD Configuration */
    register8_t OSCCFG;  /* Oscillator Configuration */
    register8_t reserved_1[1];
    register8_t TCD0CFG;  /* TCD0 Configuration */
    register8_t SYSCFG0;  /* System Configuration 0 */
    register8_t SYSCFG1;  /* System Configuration 1 */
    register8_t APPEND;  /* Application Code Section End */
    register8_t BOOTEND;  /* Boot Section End */
} FUSE_t;


/* avr-libc typedef for avr/fuse.h */
typedef FUSE_t NVM_FUSES_t;

/* BOD Operation in Active Mode select */
typedef enum ACTIVE_enum
{
    ACTIVE_DIS_gc = (0x00<<2),  /* Disabled */
    ACTIVE_ENABLED_gc = (0x01<<2),  /* Enabled */
    ACTIVE_SAMPLED_gc = (0x02<<2),  /* Sampled */
    ACTIVE_ENWAKE_gc = (0x03<<2),  /* Enabled with wake-up halted until BOD is ready */
} ACTIVE_t;

/* CRC Source select */
typedef enum CRCSRC_enum
{
    CRCSRC_FLASH_gc = (0x00<<6),  /* The CRC is performed on the entire Flash (boot, application code and application data section). */
    CRCSRC_BOOT_gc = (0x01<<6),  /* The CRC is performed on the boot section of Flash */
    CRCSRC_BOOTAPP_gc = (0x02<<6),  /* The CRC is performed on the boot and application code section of Flash */
    CRCSRC_NOCRC_gc = (0x03<<6),  /* Disable CRC. */
} CRCSRC_t;

/* Frequency Select select */
typedef enum FREQSEL_enum
{
    FREQSEL_16MHZ_gc = (0x01<<0),  /* 16 MHz */
    FREQSEL_20MHZ_gc = (0x02<<0),  /* 20 MHz */
} FREQSEL_t;

/* BOD Level select */
typedef enum LVL_enum
{
    LVL_BODLEVEL0_gc = (0x00<<5),  /* 1.8 V */
    LVL_BODLEVEL2_gc = (0x02<<5),  /* 2.6 V */
    LVL_BODLEVEL7_gc = (0x07<<5),  /* 4.2 V */
} LVL_t;

/* Watchdog Timeout Period select */
typedef enum PERIOD_enum
{
    PERIOD_OFF_gc = (0x00<<0),  /* Watch-Dog timer Off */
    PERIOD_8CLK_gc = (0x01<<0),  /* 8 cycles (8ms) */
    PERIOD_16CLK_gc = (0x02<<0),  /* 16 cycles (16ms) */
    PERIOD_32CLK_gc = (0x03<<0),  /* 32 cycles (32ms) */
    PERIOD_64CLK_gc = (0x04<<0),  /* 64 cycles (64ms) */
    PERIOD_128CLK_gc = (0x05<<0),  /* 128 cycles (0.128s) */
    PERIOD_256CLK_gc = (0x06<<0),  /* 256 cycles (0.256s) */
    PERIOD_512CLK_gc = (0x07<<0),  /* 512 cycles (0.512s) */
    PERIOD_1KCLK_gc = (0x08<<0),  /* 1K cycles (1.0s) */
    PERIOD_2KCLK_gc = (0x09<<0),  /* 2K cycles (2.0s) */
    PERIOD_4KCLK_gc = (0x0A<<0),  /* 4K cycles (4.1s) */
    PERIOD_8KCLK_gc = (0x0B<<0),  /* 8K cycles (8.2s) */
} PERIOD_t;

/* Reset Pin Configuration select */
typedef enum RSTPINCFG_enum
{
    RSTPINCFG_GPIO_gc = (0x00<<2),  /* GPIO mode */
    RSTPINCFG_UPDI_gc = (0x01<<2),  /* UPDI mode */
    RSTPINCFG_RST_gc = (0x02<<2),  /* Reset mode */
} RSTPINCFG_t;

/* BOD Sample Frequency select */
typedef enum SAMPFREQ_enum
{
    SAMPFREQ_1KHz_gc = (0x00<<4),  /* 1kHz sampling frequency */
    SAMPFREQ_125Hz_gc = (0x01<<4),  /* 125Hz sampling frequency */
} SAMPFREQ_t;

/* BOD Operation in Sleep Mode select */
typedef enum SLEEP_enum
{
    SLEEP_DIS_gc = (0x00<<0),  /* Disabled */
    SLEEP_ENABLED_gc = (0x01<<0),  /* Enabled */
    SLEEP_SAMPLED_gc = (0x02<<0),  /* Sampled */
} SLEEP_t;

/* Startup Time select */
typedef enum SUT_enum
{
    SUT_0MS_gc = (0x00<<0),  /* 0 ms */
    SUT_1MS_gc = (0x01<<0),  /* 1 ms */
    SUT_2MS_gc = (0x02<<0),  /* 2 ms */
    SUT_4MS_gc = (0x03<<0),  /* 4 ms */
    SUT_8MS_gc = (0x04<<0),  /* 8 ms */
    SUT_16MS_gc = (0x05<<0),  /* 16 ms */
    SUT_32MS_gc = (0x06<<0),  /* 32 ms */
    SUT_64MS_gc = (0x07<<0),  /* 64 ms */
} SUT_t;

/* Watchdog Window Timeout Period select */
typedef enum WINDOW_enum
{
    WINDOW_OFF_gc = (0x00<<4),  /* Window mode off */
    WINDOW_8CLK_gc = (0x01<<4),  /* 8 cycles (8ms) */
    WINDOW_16CLK_gc = (0x02<<4),  /* 16 cycles (16ms) */
    WINDOW_32CLK_gc = (0x03<<4),  /* 32 cycles (32ms) */
    WINDOW_64CLK_gc = (0x04<<4),  /* 64 cycles (64ms) */
    WINDOW_128CLK_gc = (0x05<<4),  /* 128 cycles (0.128s) */
    WINDOW_256CLK_gc = (0x06<<4),  /* 256 cycles (0.256s) */
    WINDOW_512CLK_gc = (0x07<<4),  /* 512 cycles (0.512s) */
    WINDOW_1KCLK_gc = (0x08<<4),  /* 1K cycles (1.0s) */
    WINDOW_2KCLK_gc = (0x09<<4),  /* 2K cycles (2.0s) */
    WINDOW_4KCLK_gc = (0x0A<<4),  /* 4K cycles (4.1s) */
    WINDOW_8KCLK_gc = (0x0B<<4),  /* 8K cycles (8.2s) */
} WINDOW_t;

/*
--------------------------------------------------------------------------
LOCKBIT - Lockbit
--------------------------------------------------------------------------
*/

/* Lockbit */
typedef struct LOCKBIT_struct
{
    register8_t LOCKBIT;  /* Lock bits */
} LOCKBIT_t;

/* Lock Bits select */
typedef enum LB_enum
{
    LB_RWLOCK_gc = (0x3A<<0),  /* Read and write lock */
    LB_NOLOCK_gc = (0xC5<<0),  /* No locks */
} LB_t;

/*
--------------------------------------------------------------------------
NVMCTRL - Non-volatile Memory Controller
--------------------------------------------------------------------------
*/

/* Non-volatile Memory Controller */
typedef struct NVMCTRL_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t CTRLB;  /* Control B */
    register8_t STATUS;  /* Status */
    register8_t INTCTRL;  /* Interrupt Control */
    register8_t INTFLAGS;  /* Interrupt Flags */
    register8_t reserved_1[1];
    _WORDREGISTER(DATA);  /* Data */
    _WORDREGISTER(ADDR);  /* Address */
    register8_t reserved_2[6];
} NVMCTRL_t;

/* Command select */
typedef enum NVMCTRL_CMD_enum
{
    NVMCTRL_CMD_NONE_gc = (0x00<<0),  /* No Command */
    NVMCTRL_CMD_PAGEWRITE_gc = (0x01<<0),  /* Write page */
    NVMCTRL_CMD_PAGEERASE_gc = (0x02<<0),  /* Erase page */
    NVMCTRL_CMD_PAGEERASEWRITE_gc = (0x03<<0),  /* Erase and write page */
    NVMCTRL_CMD_PAGEBUFCLR_gc = (0x04<<0),  /* Page buffer clear */
    NVMCTRL_CMD_CHIPERASE_gc = (0x05<<0),  /* Chip erase */
    NVMCTRL_CMD_EEERASE_gc = (0x06<<0),  /* EEPROM erase */
    NVMCTRL_CMD_FUSEWRITE_gc = (0x07<<0),  /* Write fuse (PDI only) */
} NVMCTRL_CMD_t;

/*
--------------------------------------------------------------------------
PORT - I/O Ports
--------------------------------------------------------------------------
*/

/* I/O Ports */
typedef struct PORT_struct
{
    register8_t DIR;  /* Data Direction */
    register8_t DIRSET;  /* Data Direction Set */
    register8_t DIRCLR;  /* Data Direction Clear */
    register8_t DIRTGL;  /* Data Direction Toggle */
    register8_t OUT;  /* Output Value */
    register8_t OUTSET;  /* Output Value Set */
    register8_t OUTCLR;  /* Output Value Clear */
    register8_t OUTTGL;  /* Output Value Toggle */
    register8_t IN;  /* Input Value */
    register8_t INTFLAGS;  /* Interrupt Flags */
    register8_t reserved_1[6];
    register8_t PIN0CTRL;  /* Pin 0 Control */
    register8_t PIN1CTRL;  /* Pin 1 Control */
    register8_t PIN2CTRL;  /* Pin 2 Control */
    register8_t PIN3CTRL;  /* Pin 3 Control */
    register8_t PIN4CTRL;  /* Pin 4 Control */
    register8_t PIN5CTRL;  /* Pin 5 Control */
    register8_t PIN6CTRL;  /* Pin 6 Control */
    register8_t PIN7CTRL;  /* Pin 7 Control */
    register8_t reserved_2[8];
} PORT_t;

/* Input/Sense Configuration select */
typedef enum PORT_ISC_enum
{
    PORT_ISC_INTDISABLE_gc = (0x00<<0),  /* Interrupt disabled but input buffer enabled */
    PORT_ISC_BOTHEDGES_gc = (0x01<<0),  /* Sense Both Edges */
    PORT_ISC_RISING_gc = (0x02<<0),  /* Sense Rising Edge */
    PORT_ISC_FALLING_gc = (0x03<<0),  /* Sense Falling Edge */
    PORT_ISC_INPUT_DISABLE_gc = (0x04<<0),  /* Digital Input Buffer disabled */
    PORT_ISC_LEVEL_gc = (0x05<<0),  /* Sense low Level */
} PORT_ISC_t;

/*
--------------------------------------------------------------------------
PORTMUX - Port Multiplexer
--------------------------------------------------------------------------
*/

/* Port Multiplexer */
typedef struct PORTMUX_struct
{
    register8_t CTRLA;  /* Port Multiplexer Control A */
    register8_t CTRLB;  /* Port Multiplexer Control B */
    register8_t CTRLC;  /* Port Multiplexer Control C */
    register8_t CTRLD;  /* Port Multiplexer Control D */
    register8_t reserved_1[12];
} PORTMUX_t;

/* Configurable Custom Logic LUT0 select */
typedef enum PORTMUX_LUT0_enum
{
    PORTMUX_LUT0_DEFAULT_gc = (0x00<<4),  /* Default pin */
    PORTMUX_LUT0_ALTERNATE_gc = (0x01<<4),  /* Alternate pin */
} PORTMUX_LUT0_t;

/* Configurable Custom Logic LUT1 select */
typedef enum PORTMUX_LUT1_enum
{
    PORTMUX_LUT1_DEFAULT_gc = (0x00<<5),  /* Default pin */
    PORTMUX_LUT1_ALTERNATE_gc = (0x01<<5),  /* Alternate pin */
} PORTMUX_LUT1_t;

/* Port Multiplexer SPI0 select */
typedef enum PORTMUX_SPI0_enum
{
    PORTMUX_SPI0_DEFAULT_gc = (0x00<<2),  /* Default pins */
    PORTMUX_SPI0_ALTERNATE_gc = (0x01<<2),  /* Alternate pins */
} PORTMUX_SPI0_t;

/* Port Multiplexer TCA0 Output 0 select */
typedef enum PORTMUX_TCA00_enum
{
    PORTMUX_TCA00_DEFAULT_gc = (0x00<<0),  /* Default pin */
    PORTMUX_TCA00_ALTERNATE_gc = (0x01<<0),  /* Alternate pin */
} PORTMUX_TCA00_t;

/* Port Multiplexer TCA0 Output 1 select */
typedef enum PORTMUX_TCA01_enum
{
    PORTMUX_TCA01_DEFAULT_gc = (0x00<<1),  /* Default pin */
    PORTMUX_TCA01_ALTERNATE_gc = (0x01<<1),  /* Alternate pin */
} PORTMUX_TCA01_t;

/* Port Multiplexer TCA0 Output 2 select */
typedef enum PORTMUX_TCA02_enum
{
    PORTMUX_TCA02_DEFAULT_gc = (0x00<<2),  /* Default pin */
    PORTMUX_TCA02_ALTERNATE_gc = (0x01<<2),  /* Alternate pin */
} PORTMUX_TCA02_t;

/* Port Multiplexer TCA0 Output 3 select */
typedef enum PORTMUX_TCA03_enum
{
    PORTMUX_TCA03_DEFAULT_gc = (0x00<<3),  /* Default pin */
    PORTMUX_TCA03_ALTERNATE_gc = (0x01<<3),  /* Alternate pin */
} PORTMUX_TCA03_t;

/* Port Multiplexer TCA0 Output 4 select */
typedef enum PORTMUX_TCA04_enum
{
    PORTMUX_TCA04_DEFAULT_gc = (0x00<<4),  /* Default pin */
    PORTMUX_TCA04_ALTERNATE_gc = (0x01<<4),  /* Alternate pin */
} PORTMUX_TCA04_t;

/* Port Multiplexer TCA0 Output 5 select */
typedef enum PORTMUX_TCA05_enum
{
    PORTMUX_TCA05_DEFAULT_gc = (0x00<<5),  /* Default pin */
    PORTMUX_TCA05_ALTERNATE_gc = (0x01<<5),  /* Alternate pin */
} PORTMUX_TCA05_t;

/* Port Multiplexer TCB select */
typedef enum PORTMUX_TCB0_enum
{
    PORTMUX_TCB0_DEFAULT_gc = (0x00<<0),  /* Default pin */
    PORTMUX_TCB0_ALTERNATE_gc = (0x01<<0),  /* Alternate pin */
} PORTMUX_TCB0_t;

/* Port Multiplexer TWI0 select */
typedef enum PORTMUX_TWI0_enum
{
    PORTMUX_TWI0_DEFAULT_gc = (0x00<<4),  /* Default pins */
    PORTMUX_TWI0_ALTERNATE_gc = (0x01<<4),  /* Alternate pins */
} PORTMUX_TWI0_t;

/* Port Multiplexer USART0 select */
typedef enum PORTMUX_USART0_enum
{
    PORTMUX_USART0_DEFAULT_gc = (0x00<<0),  /* Default pins */
    PORTMUX_USART0_ALTERNATE_gc = (0x01<<0),  /* Alternate pins */
} PORTMUX_USART0_t;

/*
--------------------------------------------------------------------------
RSTCTRL - Reset controller
--------------------------------------------------------------------------
*/

/* Reset controller */
typedef struct RSTCTRL_struct
{
    register8_t RSTFR;  /* Reset Flags */
    register8_t SWRR;  /* Software Reset */
    register8_t reserved_1[2];
} RSTCTRL_t;


/*
--------------------------------------------------------------------------
RTC - Real-Time Counter
--------------------------------------------------------------------------
*/

/* Real-Time Counter */
typedef struct RTC_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t STATUS;  /* Status */
    register8_t INTCTRL;  /* Interrupt Control */
    register8_t INTFLAGS;  /* Interrupt Flags */
    register8_t TEMP;  /* Temporary */
    register8_t DBGCTRL;  /* Debug control */
    register8_t reserved_1[1];
    register8_t CLKSEL;  /* Clock Select */
    _WORDREGISTER(CNT);  /* Counter */
    _WORDREGISTER(PER);  /* Period */
    _WORDREGISTER(CMP);  /* Compare */
    register8_t reserved_2[2];
    register8_t PITCTRLA;  /* PIT Control A */
    register8_t PITSTATUS;  /* PIT Status */
    register8_t PITINTCTRL;  /* PIT Interrupt Control */
    register8_t PITINTFLAGS;  /* PIT Interrupt Flags */
    register8_t reserved_3[1];
    register8_t PITDBGCTRL;  /* PIT Debug control */
    register8_t reserved_4[10];
} RTC_t;

/* Clock Select select */
typedef enum RTC_CLKSEL_enum
{
    RTC_CLKSEL_INT32K_gc = (0x00<<0),  /* Internal 32kHz OSC */
    RTC_CLKSEL_INT1K_gc = (0x01<<0),  /* Internal 1kHz OSC */
    RTC_CLKSEL_TOSC32K_gc = (0x02<<0),  /* 32KHz Crystal OSC */
    RTC_CLKSEL_EXTCLK_gc = (0x03<<0),  /* External Clock */
} RTC_CLKSEL_t;

/* Period select */
typedef enum RTC_PERIOD_enum
{
    RTC_PERIOD_OFF_gc = (0x00<<3),  /* Off */
    RTC_PERIOD_CYC4_gc = (0x01<<3),  /* RTC Clock Cycles 4 */
    RTC_PERIOD_CYC8_gc = (0x02<<3),  /* RTC Clock Cycles 8 */
    RTC_PERIOD_CYC16_gc = (0x03<<3),  /* RTC Clock Cycles 16 */
    RTC_PERIOD_CYC32_gc = (0x04<<3),  /* RTC Clock Cycles 32 */
    RTC_PERIOD_CYC64_gc = (0x05<<3),  /* RTC Clock Cycles 64 */
    RTC_PERIOD_CYC128_gc = (0x06<<3),  /* RTC Clock Cycles 128 */
    RTC_PERIOD_CYC256_gc = (0x07<<3),  /* RTC Clock Cycles 256 */
    RTC_PERIOD_CYC512_gc = (0x08<<3),  /* RTC Clock Cycles 512 */
    RTC_PERIOD_CYC1024_gc = (0x09<<3),  /* RTC Clock Cycles 1024 */
    RTC_PERIOD_CYC2048_gc = (0x0A<<3),  /* RTC Clock Cycles 2048 */
    RTC_PERIOD_CYC4096_gc = (0x0B<<3),  /* RTC Clock Cycles 4096 */
    RTC_PERIOD_CYC8192_gc = (0x0C<<3),  /* RTC Clock Cycles 8192 */
    RTC_PERIOD_CYC16384_gc = (0x0D<<3),  /* RTC Clock Cycles 16384 */
    RTC_PERIOD_CYC32768_gc = (0x0E<<3),  /* RTC Clock Cycles 32768 */
} RTC_PERIOD_t;

/* Prescaling Factor select */
typedef enum RTC_PRESCALER_enum
{
    RTC_PRESCALER_DIV1_gc = (0x00<<3),  /* RTC Clock / 1 */
    RTC_PRESCALER_DIV2_gc = (0x01<<3),  /* RTC Clock / 2 */
    RTC_PRESCALER_DIV4_gc = (0x02<<3),  /* RTC Clock / 4 */
    RTC_PRESCALER_DIV8_gc = (0x03<<3),  /* RTC Clock / 8 */
    RTC_PRESCALER_DIV16_gc = (0x04<<3),  /* RTC Clock / 16 */
    RTC_PRESCALER_DIV32_gc = (0x05<<3),  /* RTC Clock / 32 */
    RTC_PRESCALER_DIV64_gc = (0x06<<3),  /* RTC Clock / 64 */
    RTC_PRESCALER_DIV128_gc = (0x07<<3),  /* RTC Clock / 128 */
    RTC_PRESCALER_DIV256_gc = (0x08<<3),  /* RTC Clock / 256 */
    RTC_PRESCALER_DIV512_gc = (0x09<<3),  /* RTC Clock / 512 */
    RTC_PRESCALER_DIV1024_gc = (0x0A<<3),  /* RTC Clock / 1024 */
    RTC_PRESCALER_DIV2048_gc = (0x0B<<3),  /* RTC Clock / 2048 */
    RTC_PRESCALER_DIV4096_gc = (0x0C<<3),  /* RTC Clock / 4096 */
    RTC_PRESCALER_DIV8192_gc = (0x0D<<3),  /* RTC Clock / 8192 */
    RTC_PRESCALER_DIV16384_gc = (0x0E<<3),  /* RTC Clock / 16384 */
    RTC_PRESCALER_DIV32768_gc = (0x0F<<3),  /* RTC Clock / 32768 */
} RTC_PRESCALER_t;

/*
--------------------------------------------------------------------------
SIGROW - Signature row
--------------------------------------------------------------------------
*/

/* Signature row */
typedef struct SIGROW_struct
{
    register8_t DEVICEID0;  /* Device ID Byte 0 */
    register8_t DEVICEID1;  /* Device ID Byte 1 */
    register8_t DEVICEID2;  /* Device ID Byte 2 */
    register8_t SERNUM0;  /* Serial Number Byte 0 */
    register8_t SERNUM1;  /* Serial Number Byte 1 */
    register8_t SERNUM2;  /* Serial Number Byte 2 */
    register8_t SERNUM3;  /* Serial Number Byte 3 */
    register8_t SERNUM4;  /* Serial Number Byte 4 */
    register8_t SERNUM5;  /* Serial Number Byte 5 */
    register8_t SERNUM6;  /* Serial Number Byte 6 */
    register8_t SERNUM7;  /* Serial Number Byte 7 */
    register8_t SERNUM8;  /* Serial Number Byte 8 */
    register8_t SERNUM9;  /* Serial Number Byte 9 */
    register8_t reserved_1[19];
    register8_t TEMPSENSE0;  /* Temperature Sensor Calibration Byte 0 */
    register8_t TEMPSENSE1;  /* Temperature Sensor Calibration Byte 1 */
    register8_t OSC16ERR3V;  /* OSC16 error at 3V */
    register8_t OSC16ERR5V;  /* OSC16 error at 5V */
    register8_t OSC20ERR3V;  /* OSC20 error at 3V */
    register8_t OSC20ERR5V;  /* OSC20 error at 5V */
    register8_t reserved_2[26];
} SIGROW_t;


/*
--------------------------------------------------------------------------
SLPCTRL - Sleep Controller
--------------------------------------------------------------------------
*/

/* Sleep Controller */
typedef struct SLPCTRL_struct
{
    register8_t CTRLA;  /* Control */
    register8_t reserved_1[1];
} SLPCTRL_t;

/* Sleep mode select */
typedef enum SLPCTRL_SMODE_enum
{
    SLPCTRL_SMODE_IDLE_gc = (0x00<<1),  /* Idle mode */
    SLPCTRL_SMODE_STDBY_gc = (0x01<<1),  /* Standby Mode */
    SLPCTRL_SMODE_PDOWN_gc = (0x02<<1),  /* Power-down Mode */
} SLPCTRL_SMODE_t;

#define SLEEP_MODE_IDLE (0x00<<1)
#define SLEEP_MODE_STANDBY (0x01<<1)
#define SLEEP_MODE_PWR_DOWN (0x02<<1)
/*
--------------------------------------------------------------------------
SPI - Serial Peripheral Interface
--------------------------------------------------------------------------
*/

/* Serial Peripheral Interface */
typedef struct SPI_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t CTRLB;  /* Control B */
    register8_t INTCTRL;  /* Interrupt Control */
    register8_t INTFLAGS;  /* Interrupt Flags */
    register8_t DATA;  /* Data */
    register8_t reserved_1[3];
} SPI_t;

/* SPI Mode select */
typedef enum SPI_MODE_enum
{
    SPI_MODE_0_gc = (0x00<<0),  /* SPI Mode 0 */
    SPI_MODE_1_gc = (0x01<<0),  /* SPI Mode 1 */
    SPI_MODE_2_gc = (0x02<<0),  /* SPI Mode 2 */
    SPI_MODE_3_gc = (0x03<<0),  /* SPI Mode 3 */
} SPI_MODE_t;

/* Prescaler select */
typedef enum SPI_PRESC_enum
{
    SPI_PRESC_DIV4_gc = (0x00<<1),  /* System Clock / 4 */
    SPI_PRESC_DIV16_gc = (0x01<<1),  /* System Clock / 16 */
    SPI_PRESC_DIV64_gc = (0x02<<1),  /* System Clock / 64 */
    SPI_PRESC_DIV128_gc = (0x03<<1),  /* System Clock / 128 */
} SPI_PRESC_t;

/*
--------------------------------------------------------------------------
SYSCFG - System Configuration Registers
--------------------------------------------------------------------------
*/

/* System Configuration Registers */
typedef struct SYSCFG_struct
{
    register8_t reserved_1[1];
    register8_t REVID;  /* Revision ID */
    register8_t EXTBRK;  /* External Break */
    register8_t reserved_2[29];
} SYSCFG_t;


/*
--------------------------------------------------------------------------
TCA - 16-bit Timer/Counter Type A
--------------------------------------------------------------------------
*/

/* 16-bit Timer/Counter Type A - Single Mode */
typedef struct TCA_SINGLE_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t CTRLB;  /* Control B */
    register8_t CTRLC;  /* Control C */
    register8_t CTRLD;  /* Control D */
    register8_t CTRLECLR;  /* Control E Clear */
    register8_t CTRLESET;  /* Control E Set */
    register8_t CTRLFCLR;  /* Control F Clear */
    register8_t CTRLFSET;  /* Control F Set */
    register8_t reserved_1[1];
    register8_t EVCTRL;  /* Event Control */
    register8_t INTCTRL;  /* Interrupt Control */
    register8_t INTFLAGS;  /* Interrupt Flags */
    register8_t reserved_2[2];
    register8_t DBGCTRL;  /* Degbug Control */
    register8_t TEMP;  /* Temporary data for 16-bit Access */
    register8_t reserved_3[16];
    _WORDREGISTER(CNT);  /* Count */
    register8_t reserved_4[4];
    _WORDREGISTER(PER);  /* Period */
    _WORDREGISTER(CMP0);  /* Compare 0 */
    _WORDREGISTER(CMP1);  /* Compare 1 */
    _WORDREGISTER(CMP2);  /* Compare 2 */
    register8_t reserved_5[8];
    _WORDREGISTER(PERBUF);  /* Period Buffer */
    _WORDREGISTER(CMP0BUF);  /* Compare 0 Buffer */
    _WORDREGISTER(CMP1BUF);  /* Compare 1 Buffer */
    _WORDREGISTER(CMP2BUF);  /* Compare 2 Buffer */
    register8_t reserved_6[2];
} TCA_SINGLE_t;


/* 16-bit Timer/Counter Type A - Split Mode */
typedef struct TCA_SPLIT_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t CTRLB;  /* Control B */
    register8_t CTRLC;  /* Control C */
    register8_t CTRLD;  /* Control D */
    register8_t CTRLECLR;  /* Control E Clear */
    register8_t CTRLESET;  /* Control E Set */
    register8_t reserved_1[4];
    register8_t INTCTRL;  /* Interrupt Control */
    register8_t INTFLAGS;  /* Interrupt Flags */
    register8_t reserved_2[2];
    register8_t DBGCTRL;  /* Degbug Control */
    register8_t reserved_3[17];
    register8_t LCNT;  /* Low Count */
    register8_t HCNT;  /* High Count */
    register8_t reserved_4[4];
    register8_t LPER;  /* Low Period */
    register8_t HPER;  /* High Period */
    register8_t LCMP0;  /* Low Compare */
    register8_t HCMP0;  /* High Compare */
    register8_t LCMP1;  /* Low Compare */
    register8_t HCMP1;  /* High Compare */
    register8_t LCMP2;  /* Low Compare */
    register8_t HCMP2;  /* High Compare */
    register8_t reserved_5[18];
} TCA_SPLIT_t;


/* 16-bit Timer/Counter Type A */
typedef union TCA_union
{
    TCA_SINGLE_t SINGLE;  /* 16-bit Timer/Counter Type A - Single Mode */
    TCA_SPLIT_t SPLIT;  /* 16-bit Timer/Counter Type A - Split Mode */
} TCA_t;

/* Clock Selection select */
typedef enum TCA_SINGLE_CLKSEL_enum
{
    TCA_SINGLE_CLKSEL_DIV1_gc = (0x00<<1),  /* System Clock */
    TCA_SINGLE_CLKSEL_DIV2_gc = (0x01<<1),  /* System Clock / 2 */
    TCA_SINGLE_CLKSEL_DIV4_gc = (0x02<<1),  /* System Clock / 4 */
    TCA_SINGLE_CLKSEL_DIV8_gc = (0x03<<1),  /* System Clock / 8 */
    TCA_SINGLE_CLKSEL_DIV16_gc = (0x04<<1),  /* System Clock / 16 */
    TCA_SINGLE_CLKSEL_DIV64_gc = (0x05<<1),  /* System Clock / 64 */
    TCA_SINGLE_CLKSEL_DIV256_gc = (0x06<<1),  /* System Clock / 256 */
    TCA_SINGLE_CLKSEL_DIV1024_gc = (0x07<<1),  /* System Clock / 1024 */
} TCA_SINGLE_CLKSEL_t;

/* Command select */
typedef enum TCA_SINGLE_CMD_enum
{
    TCA_SINGLE_CMD_NONE_gc = (0x00<<2),  /* No Command */
    TCA_SINGLE_CMD_UPDATE_gc = (0x01<<2),  /* Force Update */
    TCA_SINGLE_CMD_RESTART_gc = (0x02<<2),  /* Force Restart */
    TCA_SINGLE_CMD_RESET_gc = (0x03<<2),  /* Force Hard Reset */
} TCA_SINGLE_CMD_t;

/* Direction select */
typedef enum TCA_SINGLE_DIR_enum
{
    TCA_SINGLE_DIR_UP_gc = (0x00<<0),  /* Count up */
    TCA_SINGLE_DIR_DOWN_gc = (0x01<<0),  /* Count down */
} TCA_SINGLE_DIR_t;

/* Event Action select */
typedef enum TCA_SINGLE_EVACT_enum
{
    TCA_SINGLE_EVACT_POSEDGE_gc = (0x00<<1),  /* Count on positive edge event */
    TCA_SINGLE_EVACT_ANYEDGE_gc = (0x01<<1),  /* Count on any edge event */
    TCA_SINGLE_EVACT_HIGHLVL_gc = (0x02<<1),  /* Count on prescaled clock while event line is 1. */
    TCA_SINGLE_EVACT_UPDOWN_gc = (0x03<<1),  /* Count on prescaled clock. Event controls count direction. Up-count when event line is 0, down-count when event line is 1. */
} TCA_SINGLE_EVACT_t;

/* Waveform generation mode select */
typedef enum TCA_SINGLE_WGMODE_enum
{
    TCA_SINGLE_WGMODE_NORMAL_gc = (0x00<<0),  /* Normal Mode */
    TCA_SINGLE_WGMODE_FRQ_gc = (0x01<<0),  /* Frequency Generation Mode */
    TCA_SINGLE_WGMODE_SINGLESLOPE_gc = (0x03<<0),  /* Single Slope PWM */
    TCA_SINGLE_WGMODE_DSTOP_gc = (0x05<<0),  /* Dual Slope PWM, overflow on TOP */
    TCA_SINGLE_WGMODE_DSBOTH_gc = (0x06<<0),  /* Dual Slope PWM, overflow on TOP and BOTTOM */
    TCA_SINGLE_WGMODE_DSBOTTOM_gc = (0x07<<0),  /* Dual Slope PWM, overflow on BOTTOM */
} TCA_SINGLE_WGMODE_t;

/* Clock Selection select */
typedef enum TCA_SPLIT_CLKSEL_enum
{
    TCA_SPLIT_CLKSEL_DIV1_gc = (0x00<<1),  /* System Clock */
    TCA_SPLIT_CLKSEL_DIV2_gc = (0x01<<1),  /* System Clock / 2 */
    TCA_SPLIT_CLKSEL_DIV4_gc = (0x02<<1),  /* System Clock / 4 */
    TCA_SPLIT_CLKSEL_DIV8_gc = (0x03<<1),  /* System Clock / 8 */
    TCA_SPLIT_CLKSEL_DIV16_gc = (0x04<<1),  /* System Clock / 16 */
    TCA_SPLIT_CLKSEL_DIV64_gc = (0x05<<1),  /* System Clock / 64 */
    TCA_SPLIT_CLKSEL_DIV256_gc = (0x06<<1),  /* System Clock / 256 */
    TCA_SPLIT_CLKSEL_DIV1024_gc = (0x07<<1),  /* System Clock / 1024 */
} TCA_SPLIT_CLKSEL_t;

/* Command select */
typedef enum TCA_SPLIT_CMD_enum
{
    TCA_SPLIT_CMD_NONE_gc = (0x00<<2),  /* No Command */
    TCA_SPLIT_CMD_UPDATE_gc = (0x01<<2),  /* Force Update */
    TCA_SPLIT_CMD_RESTART_gc = (0x02<<2),  /* Force Restart */
    TCA_SPLIT_CMD_RESET_gc = (0x03<<2),  /* Force Hard Reset */
} TCA_SPLIT_CMD_t;

/*
--------------------------------------------------------------------------
TCB - 16-bit Timer Type B
--------------------------------------------------------------------------
*/

/* 16-bit Timer Type B */
typedef struct TCB_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t CTRLB;  /* Control Register B */
    register8_t reserved_1[2];
    register8_t EVCTRL;  /* Event Control */
    register8_t INTCTRL;  /* Interrupt Control */
    register8_t INTFLAGS;  /* Interrupt Flags */
    register8_t STATUS;  /* Status */
    register8_t DBGCTRL;  /* Debug Control */
    register8_t TEMP;  /* Temporary Value */
    _WORDREGISTER(CNT);  /* Count */
    _WORDREGISTER(CCMP);  /* Compare or Capture */
    register8_t reserved_2[2];
} TCB_t;

/* Clock Select select */
typedef enum TCB_CLKSEL_enum
{
    TCB_CLKSEL_CLKDIV1_gc = (0x00<<1),  /* CLK_PER (No Prescaling) */
    TCB_CLKSEL_CLKDIV2_gc = (0x01<<1),  /* CLK_PER/2 (From Prescaler) */
    TCB_CLKSEL_CLKTCA_gc = (0x02<<1),  /* Use Clock from TCA */
} TCB_CLKSEL_t;

/* Timer Mode select */
typedef enum TCB_CNTMODE_enum
{
    TCB_CNTMODE_INT_gc = (0x00<<0),  /* Periodic Interrupt */
    TCB_CNTMODE_TIMEOUT_gc = (0x01<<0),  /* Periodic Timeout */
    TCB_CNTMODE_CAPT_gc = (0x02<<0),  /* Input Capture Event */
    TCB_CNTMODE_FRQ_gc = (0x03<<0),  /* Input Capture Frequency measurement */
    TCB_CNTMODE_PW_gc = (0x04<<0),  /* Input Capture Pulse-Width measurement */
    TCB_CNTMODE_FRQPW_gc = (0x05<<0),  /* Input Capture Frequency and Pulse-Width measurement */
    TCB_CNTMODE_SINGLE_gc = (0x06<<0),  /* Single Shot */
    TCB_CNTMODE_PWM8_gc = (0x07<<0),  /* 8-bit PWM */
} TCB_CNTMODE_t;

/*
--------------------------------------------------------------------------
TCD - Timer Counter D
--------------------------------------------------------------------------
*/

/* Timer Counter D */
typedef struct TCD_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t CTRLB;  /* Control B */
    register8_t CTRLC;  /* Control C */
    register8_t CTRLD;  /* Control D */
    register8_t CTRLE;  /* Control E */
    register8_t reserved_1[3];
    register8_t EVCTRLA;  /* EVCTRLA */
    register8_t EVCTRLB;  /* EVCTRLB */
    register8_t reserved_2[2];
    register8_t INTCTRL;  /* Interrupt Control */
    register8_t INTFLAGS;  /* Interrupt Flags */
    register8_t STATUS;  /* Status */
    register8_t reserved_3[1];
    register8_t INPUTCTRLA;  /* Input Control A */
    register8_t INPUTCTRLB;  /* Input Control B */
    register8_t FAULTCTRL;  /* Fault Control */
    register8_t reserved_4[1];
    register8_t DLYCTRL;  /* Delay Control */
    register8_t DLYVAL;  /* Delay value */
    register8_t reserved_5[2];
    register8_t DITCTRL;  /* Dither Control A */
    register8_t DITVAL;  /* Dither value */
    register8_t reserved_6[4];
    register8_t DBGCTRL;  /* Debug Control */
    register8_t reserved_7[3];
    _WORDREGISTER(CAPTUREA);  /* Capture A */
    _WORDREGISTER(CAPTUREB);  /* Capture B */
    register8_t reserved_8[2];
    _WORDREGISTER(CMPASET);  /* Compare A Set */
    _WORDREGISTER(CMPACLR);  /* Compare A Clear */
    _WORDREGISTER(CMPBSET);  /* Compare B Set */
    _WORDREGISTER(CMPBCLR);  /* Compare B Clear */
    register8_t reserved_9[16];
} TCD_t;

/* event action select */
typedef enum TCD_ACTION_enum
{
    TCD_ACTION_FAULT_gc = (0x00<<2),  /* Event trigger a fault */
    TCD_ACTION_CAPTURE_gc = (0x01<<2),  /* Event trigger a fault and capture */
} TCD_ACTION_t;

/* event config select */
typedef enum TCD_CFG_enum
{
    TCD_CFG_NEITHER_gc = (0x00<<6),  /* Neither Filter nor Asynchronous Event is enabled */
    TCD_CFG_FILTER_gc = (0x01<<6),  /* Input Capture Noise Cancellation Filter enabled */
    TCD_CFG_ASYNC_gc = (0x02<<6),  /* Asynchronous Event output qualification enabled */
} TCD_CFG_t;

/* clock select select */
typedef enum TCD_CLKSEL_enum
{
    TCD_CLKSEL_20MHZ_gc = (0x00<<5),  /* 20 MHz oscillator */
    TCD_CLKSEL_EXTCLK_gc = (0x02<<5),  /* External clock */
    TCD_CLKSEL_SYSCLK_gc = (0x03<<5),  /* System clock */
} TCD_CLKSEL_t;

/* Compare C output select select */
typedef enum TCD_CMPCSEL_enum
{
    TCD_CMPCSEL_PWMA_gc = (0x00<<6),  /* PWM A output */
    TCD_CMPCSEL_PWMB_gc = (0x01<<6),  /* PWM B output */
} TCD_CMPCSEL_t;

/* Compare D output select select */
typedef enum TCD_CMPDSEL_enum
{
    TCD_CMPDSEL_PWMA_gc = (0x00<<7),  /* PWM A output */
    TCD_CMPDSEL_PWMB_gc = (0x01<<7),  /* PWM B output */
} TCD_CMPDSEL_t;

/* counter prescaler select */
typedef enum TCD_CNTPRES_enum
{
    TCD_CNTPRES_DIV1_gc = (0x00<<3),  /* Sync clock divided by 1 */
    TCD_CNTPRES_DIV4_gc = (0x01<<3),  /* Sync clock divided by 4 */
    TCD_CNTPRES_DIV32_gc = (0x02<<3),  /* Sync clock divided by 32 */
} TCD_CNTPRES_t;

/* dither select select */
typedef enum TCD_DITHERSEL_enum
{
    TCD_DITHERSEL_ONTIMEB_gc = (0x00<<0),  /* On-time ramp B */
    TCD_DITHERSEL_ONTIMEAB_gc = (0x01<<0),  /* On-time ramp A and B */
    TCD_DITHERSEL_DEADTIMEB_gc = (0x02<<0),  /* Dead-time rampB */
    TCD_DITHERSEL_DEADTIMEAB_gc = (0x03<<0),  /* Dead-time ramp A and B */
} TCD_DITHERSEL_t;

/* Delay prescaler select */
typedef enum TCD_DLYPRESC_enum
{
    TCD_DLYPRESC_DIV1_gc = (0x00<<4),  /* No prescaling */
    TCD_DLYPRESC_DIV2_gc = (0x01<<4),  /* Prescale with 2 */
    TCD_DLYPRESC_DIV4_gc = (0x02<<4),  /* Prescale with 4 */
    TCD_DLYPRESC_DIV8_gc = (0x03<<4),  /* Prescale with 8 */
} TCD_DLYPRESC_t;

/* Delay select select */
typedef enum TCD_DLYSEL_enum
{
    TCD_DLYSEL_OFF_gc = (0x00<<0),  /* No delay */
    TCD_DLYSEL_INBLANK_gc = (0x01<<0),  /* Input blanking enabled */
    TCD_DLYSEL_EVENT_gc = (0x02<<0),  /* Event delay enabled */
} TCD_DLYSEL_t;

/* Delay trigger select */
typedef enum TCD_DLYTRIG_enum
{
    TCD_DLYTRIG_CMPASET_gc = (0x00<<2),  /* Compare A set */
    TCD_DLYTRIG_CMPACLR_gc = (0x01<<2),  /* Compare A clear */
    TCD_DLYTRIG_CMPBSET_gc = (0x02<<2),  /* Compare B set */
    TCD_DLYTRIG_CMPBCLR_gc = (0x03<<2),  /* Compare B clear */
} TCD_DLYTRIG_t;

/* edge select select */
typedef enum TCD_EDGE_enum
{
    TCD_EDGE_FALL_LOW_gc = (0x00<<4),  /* The falling edge or low level of event generates retrigger or fault action */
    TCD_EDGE_RISE_HIGH_gc = (0x01<<4),  /* The rising edge or high level of event generates retrigger or fault action */
} TCD_EDGE_t;

/* Input mode select */
typedef enum TCD_INPUTMODE_enum
{
    TCD_INPUTMODE_NONE_gc = (0x00<<0),  /* Input has no actions */
    TCD_INPUTMODE_JMPWAIT_gc = (0x01<<0),  /* Stop output, jump to opposite compare cycle and wait */
    TCD_INPUTMODE_EXECWAIT_gc = (0x02<<0),  /* Stop output, execute opposite compare cycle and wait */
    TCD_INPUTMODE_EXECFAULT_gc = (0x03<<0),  /* stop output, execute opposite compare cycle while fault active */
    TCD_INPUTMODE_FREQ_gc = (0x04<<0),  /* Stop all outputs, maintain frequency */
    TCD_INPUTMODE_EXECDT_gc = (0x05<<0),  /* Stop all outputs, execute dead time while fault active */
    TCD_INPUTMODE_WAIT_gc = (0x06<<0),  /* Stop all outputs, jump to next compare cycle and wait */
    TCD_INPUTMODE_WAITSW_gc = (0x07<<0),  /* Stop all outputs, wait for software action */
    TCD_INPUTMODE_EDGETRIG_gc = (0x08<<0),  /* Stop output on edge, jump to next compare cycle */
    TCD_INPUTMODE_EDGETRIGFREQ_gc = (0x09<<0),  /* Stop output on edge, maintain frequency */
    TCD_INPUTMODE_LVLTRIGFREQ_gc = (0x0A<<0),  /* Stop output at level, maintain frequency */
} TCD_INPUTMODE_t;

/* Syncronization prescaler select */
typedef enum TCD_SYNCPRES_enum
{
    TCD_SYNCPRES_DIV1_gc = (0x00<<1),  /* Selevted clock source divided by 1 */
    TCD_SYNCPRES_DIV2_gc = (0x01<<1),  /* Selevted clock source divided by 2 */
    TCD_SYNCPRES_DIV4_gc = (0x02<<1),  /* Selevted clock source divided by 4 */
    TCD_SYNCPRES_DIV8_gc = (0x03<<1),  /* Selevted clock source divided by 8 */
} TCD_SYNCPRES_t;

/* Waveform generation mode select */
typedef enum TCD_WGMODE_enum
{
    TCD_WGMODE_ONERAMP_gc = (0x00<<0),  /* One ramp mode */
    TCD_WGMODE_TWORAMP_gc = (0x01<<0),  /* Two ramp mode */
    TCD_WGMODE_FOURRAMP_gc = (0x02<<0),  /* Four ramp mode */
    TCD_WGMODE_DS_gc = (0x03<<0),  /* Dual slope mode */
} TCD_WGMODE_t;

/*
--------------------------------------------------------------------------
TWI - Two-Wire Interface
--------------------------------------------------------------------------
*/

/* Two-Wire Interface */
typedef struct TWI_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t reserved_1[1];
    register8_t DBGCTRL;  /* Debug Control Register */
    register8_t MCTRLA;  /* Master Control A */
    register8_t MCTRLB;  /* Master Control B */
    register8_t MSTATUS;  /* Master Status */
    register8_t MBAUD;  /* Master Baurd Rate Control */
    register8_t MADDR;  /* Master Address */
    register8_t MDATA;  /* Master Data */
    register8_t SCTRLA;  /* Slave Control A */
    register8_t SCTRLB;  /* Slave Control B */
    register8_t SSTATUS;  /* Slave Status */
    register8_t SADDR;  /* Slave Address */
    register8_t SDATA;  /* Slave Data */
    register8_t SADDRMASK;  /* Slave Address Mask */
    register8_t reserved_2[1];
} TWI_t;

/* Acknowledge Action select */
typedef enum TWI_ACKACT_enum
{
    TWI_ACKACT_ACK_gc = (0x00<<2),  /* Send ACK */
    TWI_ACKACT_NACK_gc = (0x01<<2),  /* Send NACK */
} TWI_ACKACT_t;

/* Slave Address or Stop select */
typedef enum TWI_AP_enum
{
    TWI_AP_STOP_gc = (0x00<<0),  /* Stop condition generated APIF */
    TWI_AP_ADR_gc = (0x01<<0),  /* Address detection generated APIF */
} TWI_AP_t;

/* Bus State select */
typedef enum TWI_BUSSTATE_enum
{
    TWI_BUSSTATE_UNKNOWN_gc = (0x00<<0),  /* Unknown Bus State */
    TWI_BUSSTATE_IDLE_gc = (0x01<<0),  /* Bus is Idle */
    TWI_BUSSTATE_OWNER_gc = (0x02<<0),  /* This Module Controls The Bus */
    TWI_BUSSTATE_BUSY_gc = (0x03<<0),  /* The Bus is Busy */
} TWI_BUSSTATE_t;

/* Command select */
typedef enum TWI_MCMD_enum
{
    TWI_MCMD_NOACT_gc = (0x00<<0),  /* No Action */
    TWI_MCMD_REPSTART_gc = (0x01<<0),  /* Issue Repeated Start Condition */
    TWI_MCMD_RECVTRANS_gc = (0x02<<0),  /* Receive or Transmit Data, depending on DIR */
    TWI_MCMD_STOP_gc = (0x03<<0),  /* Issue Stop Condition */
} TWI_MCMD_t;

/* Command select */
typedef enum TWI_SCMD_enum
{
    TWI_SCMD_NOACT_gc = (0x00<<0),  /* No Action */
    TWI_SCMD_COMPTRANS_gc = (0x02<<0),  /* Used To Complete a Transaction */
    TWI_SCMD_RESPONSE_gc = (0x03<<0),  /* Used in Response to Address/Data Interrupt */
} TWI_SCMD_t;

/* SDA Hold Time select */
typedef enum TWI_SDAHOLD_enum
{
    TWI_SDAHOLD_OFF_gc = (0x00<<2),  /* SDA hold time off */
    TWI_SDAHOLD_50NS_gc = (0x01<<2),  /* Typical 50ns hold time */
    TWI_SDAHOLD_300NS_gc = (0x02<<2),  /* Typical 300ns hold time */
    TWI_SDAHOLD_500NS_gc = (0x03<<2),  /* Typical 500ns hold time */
} TWI_SDAHOLD_t;

/* SDA Setup Time select */
typedef enum TWI_SDASETUP_enum
{
    TWI_SDASETUP_4CYC_gc = (0x00<<4),  /* SDA setup time is 4 clock cycles */
    TWI_SDASETUP_8CYC_gc = (0x01<<4),  /* SDA setup time is 8 clock cycles */
} TWI_SDASETUP_t;

/* Inactive Bus Timeout select */
typedef enum TWI_TIMEOUT_enum
{
    TWI_TIMEOUT_DISABLED_gc = (0x00<<2),  /* Bus Timeout Disabled */
    TWI_TIMEOUT_50US_gc = (0x01<<2),  /* 50 Microseconds */
    TWI_TIMEOUT_100US_gc = (0x02<<2),  /* 100 Microseconds */
    TWI_TIMEOUT_200US_gc = (0x03<<2),  /* 200 Microseconds */
} TWI_TIMEOUT_t;

/*
--------------------------------------------------------------------------
USART - Universal Synchronous and Asynchronous Receiver and Transmitter
--------------------------------------------------------------------------
*/

/* Universal Synchronous and Asynchronous Receiver and Transmitter */
typedef struct USART_struct
{
    register8_t RXDATAL;  /* Receive Data Low Byte */
    register8_t RXDATAH;  /* Receive Data High Byte */
    register8_t TXDATAL;  /* Transmit Data Low Byte */
    register8_t TXDATAH;  /* Transmit Data High Byte */
    register8_t STATUS;  /* Status */
    register8_t CTRLA;  /* Control A */
    register8_t CTRLB;  /* Control B */
    register8_t CTRLC;  /* Control C */
    _WORDREGISTER(BAUD);  /* Baud Rate */
    register8_t reserved_1[1];
    register8_t DBGCTRL;  /* Debug Control */
    register8_t EVCTRL;  /* Event Control */
    register8_t TXPLCTRL;  /* IRCOM Transmitter Pulse Length Control */
    register8_t RXPLCTRL;  /* IRCOM Receiver Pulse Length Control */
    register8_t reserved_2[1];
} USART_t;

/* Character Size select */
typedef enum USART_CHSIZE_enum
{
    USART_CHSIZE_5BIT_gc = (0x00<<0),  /* Character size: 5 bit */
    USART_CHSIZE_6BIT_gc = (0x01<<0),  /* Character size: 6 bit */
    USART_CHSIZE_7BIT_gc = (0x02<<0),  /* Character size: 7 bit */
    USART_CHSIZE_8BIT_gc = (0x03<<0),  /* Character size: 8 bit */
    USART_CHSIZE_9BITL_gc = (0x06<<0),  /* Character size: 9 bit read low byte first */
    USART_CHSIZE_9BITH_gc = (0x07<<0),  /* Character size: 9 bit read high byte first */
} USART_CHSIZE_t;

/* Communication Mode select */
typedef enum USART_CMODE_enum
{
    USART_CMODE_ASYNCHRONOUS_gc = (0x00<<6),  /* Asynchronous Mode */
    USART_CMODE_SYNCHRONOUS_gc = (0x01<<6),  /* Synchronous Mode */
    USART_CMODE_IRCOM_gc = (0x02<<6),  /* Infrared Communication */
    USART_CMODE_MSPI_gc = (0x03<<6),  /* Master SPI Mode */
} USART_CMODE_t;

/* Parity Mode select */
typedef enum USART_PMODE_enum
{
    USART_PMODE_DISABLED_gc = (0x00<<4),  /* No Parity */
    USART_PMODE_EVEN_gc = (0x02<<4),  /* Even Parity */
    USART_PMODE_ODD_gc = (0x03<<4),  /* Odd Parity */
} USART_PMODE_t;

/* RS485 Mode internal transmitter select */
typedef enum USART_RS485_enum
{
    USART_RS485_OFF_gc = (0x00<<0),  /* RS485 Mode disabled */
    USART_RS485_EXT_gc = (0x01<<0),  /* RS485 Mode External drive */
    USART_RS485_INT_gc = (0x02<<0),  /* RS485 Mode Internal drive */
} USART_RS485_t;

/* Receiver Mode select */
typedef enum USART_RXMODE_enum
{
    USART_RXMODE_NORMAL_gc = (0x00<<1),  /* Normal mode */
    USART_RXMODE_CLK2X_gc = (0x01<<1),  /* CLK2x mode */
    USART_RXMODE_GENAUTO_gc = (0x02<<1),  /* Generic autobaud mode */
    USART_RXMODE_LINAUTO_gc = (0x03<<1),  /* LIN constrained autobaud mode */
} USART_RXMODE_t;

/* Stop Bit Mode select */
typedef enum USART_SBMODE_enum
{
    USART_SBMODE_1BIT_gc = (0x00<<3),  /* 1 stop bit */
    USART_SBMODE_2BIT_gc = (0x01<<3),  /* 2 stop bits */
} USART_SBMODE_t;

/*
--------------------------------------------------------------------------
USERROW - User Row
--------------------------------------------------------------------------
*/

/* User Row */
typedef struct USERROW_struct
{
    register8_t USERROW0;  /* User Row Byte 0 */
    register8_t USERROW1;  /* User Row Byte 1 */
    register8_t USERROW2;  /* User Row Byte 2 */
    register8_t USERROW3;  /* User Row Byte 3 */
    register8_t USERROW4;  /* User Row Byte 4 */
    register8_t USERROW5;  /* User Row Byte 5 */
    register8_t USERROW6;  /* User Row Byte 6 */
    register8_t USERROW7;  /* User Row Byte 7 */
    register8_t USERROW8;  /* User Row Byte 8 */
    register8_t USERROW9;  /* User Row Byte 9 */
    register8_t USERROW10;  /* User Row Byte 10 */
    register8_t USERROW11;  /* User Row Byte 11 */
    register8_t USERROW12;  /* User Row Byte 12 */
    register8_t USERROW13;  /* User Row Byte 13 */
    register8_t USERROW14;  /* User Row Byte 14 */
    register8_t USERROW15;  /* User Row Byte 15 */
    register8_t USERROW16;  /* User Row Byte 16 */
    register8_t USERROW17;  /* User Row Byte 17 */
    register8_t USERROW18;  /* User Row Byte 18 */
    register8_t USERROW19;  /* User Row Byte 19 */
    register8_t USERROW20;  /* User Row Byte 20 */
    register8_t USERROW21;  /* User Row Byte 21 */
    register8_t USERROW22;  /* User Row Byte 22 */
    register8_t USERROW23;  /* User Row Byte 23 */
    register8_t USERROW24;  /* User Row Byte 24 */
    register8_t USERROW25;  /* User Row Byte 25 */
    register8_t USERROW26;  /* User Row Byte 26 */
    register8_t USERROW27;  /* User Row Byte 27 */
    register8_t USERROW28;  /* User Row Byte 28 */
    register8_t USERROW29;  /* User Row Byte 29 */
    register8_t USERROW30;  /* User Row Byte 30 */
    register8_t USERROW31;  /* User Row Byte 31 */
} USERROW_t;


/*
--------------------------------------------------------------------------
VPORT - Virtual Ports
--------------------------------------------------------------------------
*/

/* Virtual Ports */
typedef struct VPORT_struct
{
    register8_t DIR;  /* Data Direction */
    register8_t OUT;  /* Output Value */
    register8_t IN;  /* Input Value */
    register8_t INTFLAGS;  /* Interrupt Flags */
} VPORT_t;


/*
--------------------------------------------------------------------------
VREF - Voltage reference
--------------------------------------------------------------------------
*/

/* Voltage reference */
typedef struct VREF_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t CTRLB;  /* Control B */
} VREF_t;

/* ADC0 reference select select */
typedef enum VREF_ADC0REFSEL_enum
{
    VREF_ADC0REFSEL_0V55_gc = (0x00<<4),  /* Voltage reference at 0.55V */
    VREF_ADC0REFSEL_1V1_gc = (0x01<<4),  /* Voltage reference at 1.1V */
    VREF_ADC0REFSEL_2V5_gc = (0x02<<4),  /* Voltage reference at 2.5V */
    VREF_ADC0REFSEL_4V34_gc = (0x03<<4),  /* Voltage reference at 4.34V */
    VREF_ADC0REFSEL_1V5_gc = (0x04<<4),  /* Voltage reference at 1.5V */
} VREF_ADC0REFSEL_t;

/* DAC0/AC0 reference select select */
typedef enum VREF_DAC0REFSEL_enum
{
    VREF_DAC0REFSEL_0V55_gc = (0x00<<0),  /* Voltage reference at 0.55V */
    VREF_DAC0REFSEL_1V1_gc = (0x01<<0),  /* Voltage reference at 1.1V */
    VREF_DAC0REFSEL_2V5_gc = (0x02<<0),  /* Voltage reference at 2.5V */
    VREF_DAC0REFSEL_4V34_gc = (0x03<<0),  /* Voltage reference at 4.34V */
    VREF_DAC0REFSEL_1V5_gc = (0x04<<0),  /* Voltage reference at 1.5V */
} VREF_DAC0REFSEL_t;

/*
--------------------------------------------------------------------------
WDT - Watch-Dog Timer
--------------------------------------------------------------------------
*/

/* Watch-Dog Timer */
typedef struct WDT_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t STATUS;  /* Status */
} WDT_t;

/* Period select */
typedef enum WDT_PERIOD_enum
{
    WDT_PERIOD_OFF_gc = (0x00<<0),  /* Watch-Dog timer Off */
    WDT_PERIOD_8CLK_gc = (0x01<<0),  /* 8 cycles (8ms) */
    WDT_PERIOD_16CLK_gc = (0x02<<0),  /* 16 cycles (16ms) */
    WDT_PERIOD_32CLK_gc = (0x03<<0),  /* 32 cycles (32ms) */
    WDT_PERIOD_64CLK_gc = (0x04<<0),  /* 64 cycles (64ms) */
    WDT_PERIOD_128CLK_gc = (0x05<<0),  /* 128 cycles (0.128s) */
    WDT_PERIOD_256CLK_gc = (0x06<<0),  /* 256 cycles (0.256s) */
    WDT_PERIOD_512CLK_gc = (0x07<<0),  /* 512 cycles (0.512s) */
    WDT_PERIOD_1KCLK_gc = (0x08<<0),  /* 1K cycles (1.0s) */
    WDT_PERIOD_2KCLK_gc = (0x09<<0),  /* 2K cycles (2.0s) */
    WDT_PERIOD_4KCLK_gc = (0x0A<<0),  /* 4K cycles (4.1s) */
    WDT_PERIOD_8KCLK_gc = (0x0B<<0),  /* 8K cycles (8.2s) */
} WDT_PERIOD_t;

/* Window select */
typedef enum WDT_WINDOW_enum
{
    WDT_WINDOW_OFF_gc = (0x00<<4),  /* Window mode off */
    WDT_WINDOW_8CLK_gc = (0x01<<4),  /* 8 cycles (8ms) */
    WDT_WINDOW_16CLK_gc = (0x02<<4),  /* 16 cycles (16ms) */
    WDT_WINDOW_32CLK_gc = (0x03<<4),  /* 32 cycles (32ms) */
    WDT_WINDOW_64CLK_gc = (0x04<<4),  /* 64 cycles (64ms) */
    WDT_WINDOW_128CLK_gc = (0x05<<4),  /* 128 cycles (0.128s) */
    WDT_WINDOW_256CLK_gc = (0x06<<4),  /* 256 cycles (0.256s) */
    WDT_WINDOW_512CLK_gc = (0x07<<4),  /* 512 cycles (0.512s) */
    WDT_WINDOW_1KCLK_gc = (0x08<<4),  /* 1K cycles (1.0s) */
    WDT_WINDOW_2KCLK_gc = (0x09<<4),  /* 2K cycles (2.0s) */
    WDT_WINDOW_4KCLK_gc = (0x0A<<4),  /* 4K cycles (4.1s) */
    WDT_WINDOW_8KCLK_gc = (0x0B<<4),  /* 8K cycles (8.2s) */
} WDT_WINDOW_t;
/*
==========================================================================
IO Module Instances. Mapped to memory.
==========================================================================
*/

#define VPORTA              (*(VPORT_t *) 0x0000) /* Virtual Ports */
#define VPORTB              (*(VPORT_t *) 0x0004) /* Virtual Ports */
#define VPORTC              (*(VPORT_t *) 0x0008) /* Virtual Ports */
#define RSTCTRL           (*(RSTCTRL_t *) 0x0040) /* Reset controller */
#define SLPCTRL           (*(SLPCTRL_t *) 0x0050) /* Sleep Controller */
#define CLKCTRL           (*(CLKCTRL_t *) 0x0060) /* Clock controller */
#define BOD                   (*(BOD_t *) 0x0080) /* Bod interface */
#define VREF                 (*(VREF_t *) 0x00A0) /* Voltage reference */
#define WDT                   (*(WDT_t *) 0x0100) /* Watch-Dog Timer */
#define CPUINT             (*(CPUINT_t *) 0x0110) /* Interrupt Controller */
#define CRCSCAN           (*(CRCSCAN_t *) 0x0120) /* CRCSCAN */
#define RTC                   (*(RTC_t *) 0x0140) /* Real-Time Counter */
#define EVSYS               (*(EVSYS_t *) 0x0180) /* Event System */
#define CCL                   (*(CCL_t *) 0x01C0) /* Configurable Custom Logic */
#define PORTMUX           (*(PORTMUX_t *) 0x0200) /* Port Multiplexer */
#define PORTA                (*(PORT_t *) 0x0400) /* I/O Ports */
#define PORTB                (*(PORT_t *) 0x0420) /* I/O Ports */
#define PORTC                (*(PORT_t *) 0x0440) /* I/O Ports */
#define ADC0                  (*(ADC_t *) 0x0600) /* Analog to Digital Converter */
#define AC0                    (*(AC_t *) 0x0670) /* Analog Comparator */
#define DAC0                  (*(DAC_t *) 0x0680) /* Digital to Analog Converter */
#define USART0              (*(USART_t *) 0x0800) /* Universal Synchronous and Asynchronous Receiver and Transmitter */
#define TWI0                  (*(TWI_t *) 0x0810) /* Two-Wire Interface */
#define SPI0                  (*(SPI_t *) 0x0820) /* Serial Peripheral Interface */
#define TCA0                  (*(TCA_t *) 0x0A00) /* 16-bit Timer/Counter Type A */
#define TCB0                  (*(TCB_t *) 0x0A40) /* 16-bit Timer Type B */
#define TCD0                  (*(TCD_t *) 0x0A80) /* Timer Counter D */
#define SYSCFG             (*(SYSCFG_t *) 0x0F00) /* System Configuration Registers */
#define NVMCTRL           (*(NVMCTRL_t *) 0x1000) /* Non-volatile Memory Controller */
#define SIGROW             (*(SIGROW_t *) 0x1100) /* Signature row */
#define FUSE                 (*(FUSE_t *) 0x1280) /* Fuses */
#define LOCKBIT           (*(LOCKBIT_t *) 0x128A) /* Lockbit */
#define USERROW           (*(USERROW_t *) 0x1300) /* User Row */

#endif /* !defined (__ASSEMBLER__) */


/* ========== Flattened fully qualified IO register names ========== */


/* VPORT (VPORTA) - Virtual Ports */
#define VPORTA_DIR  _SFR_MEM8(0x0000)
#define VPORTA_OUT  _SFR_MEM8(0x0001)
#define VPORTA_IN  _SFR_MEM8(0x0002)
#define VPORTA_INTFLAGS  _SFR_MEM8(0x0003)


/* VPORT (VPORTB) - Virtual Ports */
#define VPORTB_DIR  _SFR_MEM8(0x0004)
#define VPORTB_OUT  _SFR_MEM8(0x0005)
#define VPORTB_IN  _SFR_MEM8(0x0006)
#define VPORTB_INTFLAGS  _SFR_MEM8(0x0007)


/* VPORT (VPORTC) - Virtual Ports */
#define VPORTC_DIR  _SFR_MEM8(0x0008)
#define VPORTC_OUT  _SFR_MEM8(0x0009)
#define VPORTC_IN  _SFR_MEM8(0x000A)
#define VPORTC_INTFLAGS  _SFR_MEM8(0x000B)


/* GPIO - General Purpose IO */
#define GPIO_GPIOR0  _SFR_MEM8(0x001C)
#define GPIO_GPIOR1  _SFR_MEM8(0x001D)
#define GPIO_GPIOR2  _SFR_MEM8(0x001E)
#define GPIO_GPIOR3  _SFR_MEM8(0x001F)


/* Deprecated */
#define GPIO_GPIO0  _SFR_MEM8(0x001C)
#define GPIO_GPIO1  _SFR_MEM8(0x001D)
#define GPIO_GPIO2  _SFR_MEM8(0x001E)
#define GPIO_GPIO3  _SFR_MEM8(0x001F)


/* CPU - CPU */
#define CPU_CCP  _SFR_MEM8(0x0034)
#define CPU_SPL  _SFR_MEM8(0x003D)
#define CPU_SPH  _SFR_MEM8(0x003E)
#define CPU_SREG  _SFR_MEM8(0x003F)


/* RSTCTRL - Reset controller */
#define RSTCTRL_RSTFR  _SFR_MEM8(0x0040)
#define RSTCTRL_SWRR  _SFR_MEM8(0x0041)


/* SLPCTRL - Sleep Controller */
#define SLPCTRL_CTRLA  _SFR_MEM8(0x0050)


/* CLKCTRL - Clock controller */
#define CLKCTRL_MCLKCTRLA  _SFR_MEM8(0x0060)
#define CLKCTRL_MCLKCTRLB  _SFR_MEM8(0x0061)
#define CLKCTRL_MCLKLOCK  _SFR_MEM8(0x0062)
#define CLKCTRL_MCLKSTATUS  _SFR_MEM8(0x0063)
#define CLKCTRL_OSC20MCTRLA  _SFR_MEM8(0x0070)
#define CLKCTRL_OSC20MCALIBA  _SFR_MEM8(0x0071)
#define CLKCTRL_OSC20MCALIBB  _SFR_MEM8(0x0072)
#define CLKCTRL_OSC32KCTRLA  _SFR_MEM8(0x0078)
#define CLKCTRL_XOSC32KCTRLA  _SFR_MEM8(0x007C)


/* BOD - Bod interface */
#define BOD_CTRLA  _SFR_MEM8(0x0080)
#define BOD_CTRLB  _SFR_MEM8(0x0081)
#define BOD_VLMCTRLA  _SFR_MEM8(0x0088)
#define BOD_INTCTRL  _SFR_MEM8(0x0089)
#define BOD_INTFLAGS  _SFR_MEM8(0x008A)
#define BOD_STATUS  _SFR_MEM8(0x008B)


/* VREF - Voltage reference */
#define VREF_CTRLA  _SFR_MEM8(0x00A0)
#define VREF_CTRLB  _SFR_MEM8(0x00A1)


/* WDT - Watch-Dog Timer */
#define WDT_CTRLA  _SFR_MEM8(0x0100)
#define WDT_STATUS  _SFR_MEM8(0x0101)


/* CPUINT - Interrupt Controller */
#define CPUINT_CTRLA  _SFR_MEM8(0x0110)
#define CPUINT_STATUS  _SFR_MEM8(0x0111)
#define CPUINT_LVL0PRI  _SFR_MEM8(0x0112)
#define CPUINT_LVL1VEC  _SFR_MEM8(0x0113)


/* CRCSCAN - CRCSCAN */
#define CRCSCAN_CTRLA  _SFR_MEM8(0x0120)
#define CRCSCAN_CTRLB  _SFR_MEM8(0x0121)
#define CRCSCAN_STATUS  _SFR_MEM8(0x0122)


/* RTC - Real-Time Counter */
#define RTC_CTRLA  _SFR_MEM8(0x0140)
#define RTC_STATUS  _SFR_MEM8(0x0141)
#define RTC_INTCTRL  _SFR_MEM8(0x0142)
#define RTC_INTFLAGS  _SFR_MEM8(0x0143)
#define RTC_TEMP  _SFR_MEM8(0x0144)
#define RTC_DBGCTRL  _SFR_MEM8(0x0145)
#define RTC_CLKSEL  _SFR_MEM8(0x0147)
#define RTC_CNT  _SFR_MEM16(0x0148)
#define RTC_CNTL  _SFR_MEM8(0x0148)
#define RTC_CNTH  _SFR_MEM8(0x0149)
#define RTC_PER  _SFR_MEM16(0x014A)
#define RTC_PERL  _SFR_MEM8(0x014A)
#define RTC_PERH  _SFR_MEM8(0x014B)
#define RTC_CMP  _SFR_MEM16(0x014C)
#define RTC_CMPL  _SFR_MEM8(0x014C)
#define RTC_CMPH  _SFR_MEM8(0x014D)
#define RTC_PITCTRLA  _SFR_MEM8(0x0150)
#define RTC_PITSTATUS  _SFR_MEM8(0x0151)
#define RTC_PITINTCTRL  _SFR_MEM8(0x0152)
#define RTC_PITINTFLAGS  _SFR_MEM8(0x0153)
#define RTC_PITDBGCTRL  _SFR_MEM8(0x0155)


/* EVSYS - Event System */
#define EVSYS_ASYNCSTROBE  _SFR_MEM8(0x0180)
#define EVSYS_SYNCSTROBE  _SFR_MEM8(0x0181)
#define EVSYS_ASYNCCH0  _SFR_MEM8(0x0182)
#define EVSYS_ASYNCCH1  _SFR_MEM8(0x0183)
#define EVSYS_ASYNCCH2  _SFR_MEM8(0x0184)
#define EVSYS_ASYNCCH3  _SFR_MEM8(0x0185)
#define EVSYS_SYNCCH0  _SFR_MEM8(0x018A)
#define EVSYS_SYNCCH1  _SFR_MEM8(0x018B)
#define EVSYS_ASYNCUSER0  _SFR_MEM8(0x0192)
#define EVSYS_ASYNCUSER1  _SFR_MEM8(0x0193)
#define EVSYS_ASYNCUSER2  _SFR_MEM8(0x0194)
#define EVSYS_ASYNCUSER3  _SFR_MEM8(0x0195)
#define EVSYS_ASYNCUSER4  _SFR_MEM8(0x0196)
#define EVSYS_ASYNCUSER5  _SFR_MEM8(0x0197)
#define EVSYS_ASYNCUSER6  _SFR_MEM8(0x0198)
#define EVSYS_ASYNCUSER7  _SFR_MEM8(0x0199)
#define EVSYS_ASYNCUSER8  _SFR_MEM8(0x019A)
#define EVSYS_ASYNCUSER9  _SFR_MEM8(0x019B)
#define EVSYS_ASYNCUSER10  _SFR_MEM8(0x019C)
#define EVSYS_SYNCUSER0  _SFR_MEM8(0x01A2)
#define EVSYS_SYNCUSER1  _SFR_MEM8(0x01A3)


/* CCL - Configurable Custom Logic */
#define CCL_CTRLA  _SFR_MEM8(0x01C0)
#define CCL_SEQCTRL0  _SFR_MEM8(0x01C1)
#define CCL_LUT0CTRLA  _SFR_MEM8(0x01C5)
#define CCL_LUT0CTRLB  _SFR_MEM8(0x01C6)
#define CCL_LUT0CTRLC  _SFR_MEM8(0x01C7)
#define CCL_TRUTH0  _SFR_MEM8(0x01C8)
#define CCL_LUT1CTRLA  _SFR_MEM8(0x01C9)
#define CCL_LUT1CTRLB  _SFR_MEM8(0x01CA)
#define CCL_LUT1CTRLC  _SFR_MEM8(0x01CB)
#define CCL_TRUTH1  _SFR_MEM8(0x01CC)


/* PORTMUX - Port Multiplexer */
#define PORTMUX_CTRLA  _SFR_MEM8(0x0200)
#define PORTMUX_CTRLB  _SFR_MEM8(0x0201)
#define PORTMUX_CTRLC  _SFR_MEM8(0x0202)
#define PORTMUX_CTRLD  _SFR_MEM8(0x0203)


/* PORT (PORTA) - I/O Ports */
#define PORTA_DIR  _SFR_MEM8(0x0400)
#define PORTA_DIRSET  _SFR_MEM8(0x0401)
#define PORTA_DIRCLR  _SFR_MEM8(0x0402)
#define PORTA_DIRTGL  _SFR_MEM8(0x0403)
#define PORTA_OUT  _SFR_MEM8(0x0404)
#define PORTA_OUTSET  _SFR_MEM8(0x0405)
#define PORTA_OUTCLR  _SFR_MEM8(0x0406)
#define PORTA_OUTTGL  _SFR_MEM8(0x0407)
#define PORTA_IN  _SFR_MEM8(0x0408)
#define PORTA_INTFLAGS  _SFR_MEM8(0x0409)
#define PORTA_PIN0CTRL  _SFR_MEM8(0x0410)
#define PORTA_PIN1CTRL  _SFR_MEM8(0x0411)
#define PORTA_PIN2CTRL  _SFR_MEM8(0x0412)
#define PORTA_PIN3CTRL  _SFR_MEM8(0x0413)
#define PORTA_PIN4CTRL  _SFR_MEM8(0x0414)
#define PORTA_PIN5CTRL  _SFR_MEM8(0x0415)
#define PORTA_PIN6CTRL  _SFR_MEM8(0x0416)
#define PORTA_PIN7CTRL  _SFR_MEM8(0x0417)


/* PORT (PORTB) - I/O Ports */
#define PORTB_DIR  _SFR_MEM8(0x0420)
#define PORTB_DIRSET  _SFR_MEM8(0x0421)
#define PORTB_DIRCLR  _SFR_MEM8(0x0422)
#define PORTB_DIRTGL  _SFR_MEM8(0x0423)
#define PORTB_OUT  _SFR_MEM8(0x0424)
#define PORTB_OUTSET  _SFR_MEM8(0x0425)
#define PORTB_OUTCLR  _SFR_MEM8(0x0426)
#define PORTB_OUTTGL  _SFR_MEM8(0x0427)
#define PORTB_IN  _SFR_MEM8(0x0428)
#define PORTB_INTFLAGS  _SFR_MEM8(0x0429)
#define PORTB_PIN0CTRL  _SFR_MEM8(0x0430)
#define PORTB_PIN1CTRL  _SFR_MEM8(0x0431)
#define PORTB_PIN2CTRL  _SFR_MEM8(0x0432)
#define PORTB_PIN3CTRL  _SFR_MEM8(0x0433)
#define PORTB_PIN4CTRL  _SFR_MEM8(0x0434)
#define PORTB_PIN5CTRL  _SFR_MEM8(0x0435)
#define PORTB_PIN6CTRL  _SFR_MEM8(0x0436)
#define PORTB_PIN7CTRL  _SFR_MEM8(0x0437)


/* PORT (PORTC) - I/O Ports */
#define PORTC_DIR  _SFR_MEM8(0x0440)
#define PORTC_DIRSET  _SFR_MEM8(0x0441)
#define PORTC_DIRCLR  _SFR_MEM8(0x0442)
#define PORTC_DIRTGL  _SFR_MEM8(0x0443)
#define PORTC_OUT  _SFR_MEM8(0x0444)
#define PORTC_OUTSET  _SFR_MEM8(0x0445)
#define PORTC_OUTCLR  _SFR_MEM8(0x0446)
#define PORTC_OUTTGL  _SFR_MEM8(0x0447)
#define PORTC_IN  _SFR_MEM8(0x0448)
#define PORTC_INTFLAGS  _SFR_MEM8(0x0449)
#define PORTC_PIN0CTRL  _SFR_MEM8(0x0450)
#define PORTC_PIN1CTRL  _SFR_MEM8(0x0451)
#define PORTC_PIN2CTRL  _SFR_MEM8(0x0452)
#define PORTC_PIN3CTRL  _SFR_MEM8(0x0453)
#define PORTC_PIN4CTRL  _SFR_MEM8(0x0454)
#define PORTC_PIN5CTRL  _SFR_MEM8(0x0455)
#define PORTC_PIN6CTRL  _SFR_MEM8(0x0456)
#define PORTC_PIN7CTRL  _SFR_MEM8(0x0457)


/* ADC (ADC0) - Analog to Digital Converter */
#define ADC0_CTRLA  _SFR_MEM8(0x0600)
#define ADC0_CTRLB  _SFR_MEM8(0x0601)
#define ADC0_CTRLC  _SFR_MEM8(0x0602)
#define ADC0_CTRLD  _SFR_MEM8(0x0603)
#define ADC0_CTRLE  _SFR_MEM8(0x0604)
#define ADC0_SAMPCTRL  _SFR_MEM8(0x0605)
#define ADC0_MUXPOS  _SFR_MEM8(0x0606)
#define ADC0_COMMAND  _SFR_MEM8(0x0608)
#define ADC0_EVCTRL  _SFR_MEM8(0x0609)
#define ADC0_INTCTRL  _SFR_MEM8(0x060A)
#define ADC0_INTFLAGS  _SFR_MEM8(0x060B)
#define ADC0_DBGCTRL  _SFR_MEM8(0x060C)
#define ADC0_TEMP  _SFR_MEM8(0x060D)
#define ADC0_RES  _SFR_MEM16(0x0610)
#define ADC0_RESL  _SFR_MEM8(0x0610)
#define ADC0_RESH  _SFR_MEM8(0x0611)
#define ADC0_WINLT  _SFR_MEM16(0x0612)
#define ADC0_WINLTL  _SFR_MEM8(0x0612)
#define ADC0_WINLTH  _SFR_MEM8(0x0613)
#define ADC0_WINHT  _SFR_MEM16(0x0614)
#define ADC0_WINHTL  _SFR_MEM8(0x0614)
#define ADC0_WINHTH  _SFR_MEM8(0x0615)
#define ADC0_CALIB  _SFR_MEM8(0x0616)


/* AC (AC0) - Analog Comparator */
#define AC0_CTRLA  _SFR_MEM8(0x0670)
#define AC0_MUXCTRLA  _SFR_MEM8(0x0672)
#define AC0_INTCTRL  _SFR_MEM8(0x0676)
#define AC0_STATUS  _SFR_MEM8(0x0677)


/* DAC (DAC0) - Digital to Analog Converter */
#define DAC0_CTRLA  _SFR_MEM8(0x0680)
#define DAC0_DATA  _SFR_MEM8(0x0681)


/* USART (USART0) - Universal Synchronous and Asynchronous Receiver and Transmitter */
#define USART0_RXDATAL  _SFR_MEM8(0x0800)
#define USART0_RXDATAH  _SFR_MEM8(0x0801)
#define USART0_TXDATAL  _SFR_MEM8(0x0802)
#define USART0_TXDATAH  _SFR_MEM8(0x0803)
#define USART0_STATUS  _SFR_MEM8(0x0804)
#define USART0_CTRLA  _SFR_MEM8(0x0805)
#define USART0_CTRLB  _SFR_MEM8(0x0806)
#define USART0_CTRLC  _SFR_MEM8(0x0807)
#define USART0_BAUD  _SFR_MEM16(0x0808)
#define USART0_BAUDL  _SFR_MEM8(0x0808)
#define USART0_BAUDH  _SFR_MEM8(0x0809)
#define USART0_DBGCTRL  _SFR_MEM8(0x080B)
#define USART0_EVCTRL  _SFR_MEM8(0x080C)
#define USART0_TXPLCTRL  _SFR_MEM8(0x080D)
#define USART0_RXPLCTRL  _SFR_MEM8(0x080E)


/* TWI (TWI0) - Two-Wire Interface */
#define TWI0_CTRLA  _SFR_MEM8(0x0810)
#define TWI0_DBGCTRL  _SFR_MEM8(0x0812)
#define TWI0_MCTRLA  _SFR_MEM8(0x0813)
#define TWI0_MCTRLB  _SFR_MEM8(0x0814)
#define TWI0_MSTATUS  _SFR_MEM8(0x0815)
#define TWI0_MBAUD  _SFR_MEM8(0x0816)
#define TWI0_MADDR  _SFR_MEM8(0x0817)
#define TWI0_MDATA  _SFR_MEM8(0x0818)
#define TWI0_SCTRLA  _SFR_MEM8(0x0819)
#define TWI0_SCTRLB  _SFR_MEM8(0x081A)
#define TWI0_SSTATUS  _SFR_MEM8(0x081B)
#define TWI0_SADDR  _SFR_MEM8(0x081C)
#define TWI0_SDATA  _SFR_MEM8(0x081D)
#define TWI0_SADDRMASK  _SFR_MEM8(0x081E)


/* SPI (SPI0) - Serial Peripheral Interface */
#define SPI0_CTRLA  _SFR_MEM8(0x0820)
#define SPI0_CTRLB  _SFR_MEM8(0x0821)
#define SPI0_INTCTRL  _SFR_MEM8(0x0822)
#define SPI0_INTFLAGS  _SFR_MEM8(0x0823)
#define SPI0_DATA  _SFR_MEM8(0x0824)


/* TCA (TCA0) - 16-bit Timer/Counter Type A */
#define TCA0_SINGLE_CTRLA  _SFR_MEM8(0x0A00)
#define TCA0_SINGLE_CTRLB  _SFR_MEM8(0x0A01)
#define TCA0_SINGLE_CTRLC  _SFR_MEM8(0x0A02)
#define TCA0_SINGLE_CTRLD  _SFR_MEM8(0x0A03)
#define TCA0_SINGLE_CTRLECLR  _SFR_MEM8(0x0A04)
#define TCA0_SINGLE_CTRLESET  _SFR_MEM8(0x0A05)
#define TCA0_SINGLE_CTRLFCLR  _SFR_MEM8(0x0A06)
#define TCA0_SINGLE_CTRLFSET  _SFR_MEM8(0x0A07)
#define TCA0_SINGLE_EVCTRL  _SFR_MEM8(0x0A09)
#define TCA0_SINGLE_INTCTRL  _SFR_MEM8(0x0A0A)
#define TCA0_SINGLE_INTFLAGS  _SFR_MEM8(0x0A0B)
#define TCA0_SINGLE_DBGCTRL  _SFR_MEM8(0x0A0E)
#define TCA0_SINGLE_TEMP  _SFR_MEM8(0x0A0F)
#define TCA0_SINGLE_CNT  _SFR_MEM16(0x0A20)
#define TCA0_SINGLE_PER  _SFR_MEM16(0x0A26)
#define TCA0_SINGLE_CMP0  _SFR_MEM16(0x0A28)
#define TCA0_SINGLE_CMP1  _SFR_MEM16(0x0A2A)
#define TCA0_SINGLE_CMP2  _SFR_MEM16(0x0A2C)
#define TCA0_SINGLE_PERBUF  _SFR_MEM16(0x0A36)
#define TCA0_SINGLE_CMP0BUF  _SFR_MEM16(0x0A38)
#define TCA0_SINGLE_CMP1BUF  _SFR_MEM16(0x0A3A)
#define TCA0_SINGLE_CMP2BUF  _SFR_MEM16(0x0A3C)


#define TCA0_SPLIT_CTRLA  _SFR_MEM8(0x0A00)
#define TCA0_SPLIT_CTRLB  _SFR_MEM8(0x0A01)
#define TCA0_SPLIT_CTRLC  _SFR_MEM8(0x0A02)
#define TCA0_SPLIT_CTRLD  _SFR_MEM8(0x0A03)
#define TCA0_SPLIT_CTRLECLR  _SFR_MEM8(0x0A04)
#define TCA0_SPLIT_CTRLESET  _SFR_MEM8(0x0A05)
#define TCA0_SPLIT_INTCTRL  _SFR_MEM8(0x0A0A)
#define TCA0_SPLIT_INTFLAGS  _SFR_MEM8(0x0A0B)
#define TCA0_SPLIT_DBGCTRL  _SFR_MEM8(0x0A0E)
#define TCA0_SPLIT_LCNT  _SFR_MEM8(0x0A20)
#define TCA0_SPLIT_HCNT  _SFR_MEM8(0x0A21)
#define TCA0_SPLIT_LPER  _SFR_MEM8(0x0A26)
#define TCA0_SPLIT_HPER  _SFR_MEM8(0x0A27)
#define TCA0_SPLIT_LCMP0  _SFR_MEM8(0x0A28)
#define TCA0_SPLIT_HCMP0  _SFR_MEM8(0x0A29)
#define TCA0_SPLIT_LCMP1  _SFR_MEM8(0x0A2A)
#define TCA0_SPLIT_HCMP1  _SFR_MEM8(0x0A2B)
#define TCA0_SPLIT_LCMP2  _SFR_MEM8(0x0A2C)
#define TCA0_SPLIT_HCMP2  _SFR_MEM8(0x0A2D)




/* TCB (TCB0) - 16-bit Timer Type B */
#define TCB0_CTRLA  _SFR_MEM8(0x0A40)
#define TCB0_CTRLB  _SFR_MEM8(0x0A41)
#define TCB0_EVCTRL  _SFR_MEM8(0x0A44)
#define TCB0_INTCTRL  _SFR_MEM8(0x0A45)
#define TCB0_INTFLAGS  _SFR_MEM8(0x0A46)
#define TCB0_STATUS  _SFR_MEM8(0x0A47)
#define TCB0_DBGCTRL  _SFR_MEM8(0x0A48)
#define TCB0_TEMP  _SFR_MEM8(0x0A49)
#define TCB0_CNT  _SFR_MEM16(0x0A4A)
#define TCB0_CNTL  _SFR_MEM8(0x0A4A)
#define TCB0_CNTH  _SFR_MEM8(0x0A4B)
#define TCB0_CCMP  _SFR_MEM16(0x0A4C)
#define TCB0_CCMPL  _SFR_MEM8(0x0A4C)
#define TCB0_CCMPH  _SFR_MEM8(0x0A4D)


/* TCD (TCD0) - Timer Counter D */
#define TCD0_CTRLA  _SFR_MEM8(0x0A80)
#define TCD0_CTRLB  _SFR_MEM8(0x0A81)
#define TCD0_CTRLC  _SFR_MEM8(0x0A82)
#define TCD0_CTRLD  _SFR_MEM8(0x0A83)
#define TCD0_CTRLE  _SFR_MEM8(0x0A84)
#define TCD0_EVCTRLA  _SFR_MEM8(0x0A88)
#define TCD0_EVCTRLB  _SFR_MEM8(0x0A89)
#define TCD0_INTCTRL  _SFR_MEM8(0x0A8C)
#define TCD0_INTFLAGS  _SFR_MEM8(0x0A8D)
#define TCD0_STATUS  _SFR_MEM8(0x0A8E)
#define TCD0_INPUTCTRLA  _SFR_MEM8(0x0A90)
#define TCD0_INPUTCTRLB  _SFR_MEM8(0x0A91)
#define TCD0_FAULTCTRL  _SFR_MEM8(0x0A92)
#define TCD0_DLYCTRL  _SFR_MEM8(0x0A94)
#define TCD0_DLYVAL  _SFR_MEM8(0x0A95)
#define TCD0_DITCTRL  _SFR_MEM8(0x0A98)
#define TCD0_DITVAL  _SFR_MEM8(0x0A99)
#define TCD0_DBGCTRL  _SFR_MEM8(0x0A9E)
#define TCD0_CAPTUREA  _SFR_MEM16(0x0AA2)
#define TCD0_CAPTUREAL  _SFR_MEM8(0x0AA2)
#define TCD0_CAPTUREAH  _SFR_MEM8(0x0AA3)
#define TCD0_CAPTUREB  _SFR_MEM16(0x0AA4)
#define TCD0_CAPTUREBL  _SFR_MEM8(0x0AA4)
#define TCD0_CAPTUREBH  _SFR_MEM8(0x0AA5)
#define TCD0_CMPASET  _SFR_MEM16(0x0AA8)
#define TCD0_CMPASETL  _SFR_MEM8(0x0AA8)
#define TCD0_CMPASETH  _SFR_MEM8(0x0AA9)
#define TCD0_CMPACLR  _SFR_MEM16(0x0AAA)
#define TCD0_CMPACLRL  _SFR_MEM8(0x0AAA)
#define TCD0_CMPACLRH  _SFR_MEM8(0x0AAB)
#define TCD0_CMPBSET  _SFR_MEM16(0x0AAC)
#define TCD0_CMPBSETL  _SFR_MEM8(0x0AAC)
#define TCD0_CMPBSETH  _SFR_MEM8(0x0AAD)
#define TCD0_CMPBCLR  _SFR_MEM16(0x0AAE)
#define TCD0_CMPBCLRL  _SFR_MEM8(0x0AAE)
#define TCD0_CMPBCLRH  _SFR_MEM8(0x0AAF)


/* SYSCFG - System Configuration Registers */
#define SYSCFG_REVID  _SFR_MEM8(0x0F01)
#define SYSCFG_EXTBRK  _SFR_MEM8(0x0F02)


/* NVMCTRL - Non-volatile Memory Controller */
#define NVMCTRL_CTRLA  _SFR_MEM8(0x1000)
#define NVMCTRL_CTRLB  _SFR_MEM8(0x1001)
#define NVMCTRL_STATUS  _SFR_MEM8(0x1002)
#define NVMCTRL_INTCTRL  _SFR_MEM8(0x1003)
#define NVMCTRL_INTFLAGS  _SFR_MEM8(0x1004)
#define NVMCTRL_DATA  _SFR_MEM16(0x1006)
#define NVMCTRL_DATAL  _SFR_MEM8(0x1006)
#define NVMCTRL_DATAH  _SFR_MEM8(0x1007)
#define NVMCTRL_ADDR  _SFR_MEM16(0x1008)
#define NVMCTRL_ADDRL  _SFR_MEM8(0x1008)
#define NVMCTRL_ADDRH  _SFR_MEM8(0x1009)


/* SIGROW - Signature row */
#define SIGROW_DEVICEID0  _SFR_MEM8(0x1100)
#define SIGROW_DEVICEID1  _SFR_MEM8(0x1101)
#define SIGROW_DEVICEID2  _SFR_MEM8(0x1102)
#define SIGROW_SERNUM0  _SFR_MEM8(0x1103)
#define SIGROW_SERNUM1  _SFR_MEM8(0x1104)
#define SIGROW_SERNUM2  _SFR_MEM8(0x1105)
#define SIGROW_SERNUM3  _SFR_MEM8(0x1106)
#define SIGROW_SERNUM4  _SFR_MEM8(0x1107)
#define SIGROW_SERNUM5  _SFR_MEM8(0x1108)
#define SIGROW_SERNUM6  _SFR_MEM8(0x1109)
#define SIGROW_SERNUM7  _SFR_MEM8(0x110A)
#define SIGROW_SERNUM8  _SFR_MEM8(0x110B)
#define SIGROW_SERNUM9  _SFR_MEM8(0x110C)
#define SIGROW_TEMPSENSE0  _SFR_MEM8(0x1120)
#define SIGROW_TEMPSENSE1  _SFR_MEM8(0x1121)
#define SIGROW_OSC16ERR3V  _SFR_MEM8(0x1122)
#define SIGROW_OSC16ERR5V  _SFR_MEM8(0x1123)
#define SIGROW_OSC20ERR3V  _SFR_MEM8(0x1124)
#define SIGROW_OSC20ERR5V  _SFR_MEM8(0x1125)


/* FUSE - Fuses */
#define FUSE_WDTCFG  _SFR_MEM8(0x1280)
#define FUSE_BODCFG  _SFR_MEM8(0x1281)
#define FUSE_OSCCFG  _SFR_MEM8(0x1282)
#define FUSE_TCD0CFG  _SFR_MEM8(0x1284)
#define FUSE_SYSCFG0  _SFR_MEM8(0x1285)
#define FUSE_SYSCFG1  _SFR_MEM8(0x1286)
#define FUSE_APPEND  _SFR_MEM8(0x1287)
#define FUSE_BOOTEND  _SFR_MEM8(0x1288)


/* LOCKBIT - Lockbit */
#define LOCKBIT_LOCKBIT  _SFR_MEM8(0x128A)


/* USERROW - User Row */
#define USERROW_USERROW0  _SFR_MEM8(0x1300)
#define USERROW_USERROW1  _SFR_MEM8(0x1301)
#define USERROW_USERROW2  _SFR_MEM8(0x1302)
#define USERROW_USERROW3  _SFR_MEM8(0x1303)
#define USERROW_USERROW4  _SFR_MEM8(0x1304)
#define USERROW_USERROW5  _SFR_MEM8(0x1305)
#define USERROW_USERROW6  _SFR_MEM8(0x1306)
#define USERROW_USERROW7  _SFR_MEM8(0x1307)
#define USERROW_USERROW8  _SFR_MEM8(0x1308)
#define USERROW_USERROW9  _SFR_MEM8(0x1309)
#define USERROW_USERROW10  _SFR_MEM8(0x130A)
#define USERROW_USERROW11  _SFR_MEM8(0x130B)
#define USERROW_USERROW12  _SFR_MEM8(0x130C)
#define USERROW_USERROW13  _SFR_MEM8(0x130D)
#define USERROW_USERROW14  _SFR_MEM8(0x130E)
#define USERROW_USERROW15  _SFR_MEM8(0x130F)
#define USERROW_USERROW16  _SFR_MEM8(0x1310)
#define USERROW_USERROW17  _SFR_MEM8(0x1311)
#define USERROW_USERROW18  _SFR_MEM8(0x1312)
#define USERROW_USERROW19  _SFR_MEM8(0x1313)
#define USERROW_USERROW20  _SFR_MEM8(0x1314)
#define USERROW_USERROW21  _SFR_MEM8(0x1315)
#define USERROW_USERROW22  _SFR_MEM8(0x1316)
#define USERROW_USERROW23  _SFR_MEM8(0x1317)
#define USERROW_USERROW24  _SFR_MEM8(0x1318)
#define USERROW_USERROW25  _SFR_MEM8(0x1319)
#define USERROW_USERROW26  _SFR_MEM8(0x131A)
#define USERROW_USERROW27  _SFR_MEM8(0x131B)
#define USERROW_USERROW28  _SFR_MEM8(0x131C)
#define USERROW_USERROW29  _SFR_MEM8(0x131D)
#define USERROW_USERROW30  _SFR_MEM8(0x131E)
#define USERROW_USERROW31  _SFR_MEM8(0x131F)



/*================== Bitfield Definitions ================== */

/* AC - Analog Comparator */
/* AC.CTRLA  bit masks and bit positions */
#define AC_ENABLE_bm  0x01  /* Enable bit mask. */
#define AC_ENABLE_bp  0  /* Enable bit position. */
#define AC_HYSMODE_gm  0x06  /* Hysteresis Mode group mask. */
#define AC_HYSMODE_gp  1  /* Hysteresis Mode group position. */
#define AC_HYSMODE0_bm  (1<<1)  /* Hysteresis Mode bit 0 mask. */
#define AC_HYSMODE0_bp  1  /* Hysteresis Mode bit 0 position. */
#define AC_HYSMODE1_bm  (1<<2)  /* Hysteresis Mode bit 1 mask. */
#define AC_HYSMODE1_bp  2  /* Hysteresis Mode bit 1 position. */
#define AC_LPMODE_bm  0x08  /* Low Power Mode bit mask. */
#define AC_LPMODE_bp  3  /* Low Power Mode bit position. */
#define AC_INTMODE_gm  0x30  /* Interrupt Mode group mask. */
#define AC_INTMODE_gp  4  /* Interrupt Mode group position. */
#define AC_INTMODE0_bm  (1<<4)  /* Interrupt Mode bit 0 mask. */
#define AC_INTMODE0_bp  4  /* Interrupt Mode bit 0 position. */
#define AC_INTMODE1_bm  (1<<5)  /* Interrupt Mode bit 1 mask. */
#define AC_INTMODE1_bp  5  /* Interrupt Mode bit 1 position. */
#define AC_OUTEN_bm  0x40  /* Output Buffer Enable bit mask. */
#define AC_OUTEN_bp  6  /* Output Buffer Enable bit position. */
#define AC_RUNSTDBY_bm  0x80  /* Run in Standby Mode bit mask. */
#define AC_RUNSTDBY_bp  7  /* Run in Standby Mode bit position. */

/* AC.MUXCTRLA  bit masks and bit positions */
#define AC_MUXNEG_gm  0x03  /* Negative Input MUX Selection group mask. */
#define AC_MUXNEG_gp  0  /* Negative Input MUX Selection group position. */
#define AC_MUXNEG0_bm  (1<<0)  /* Negative Input MUX Selection bit 0 mask. */
#define AC_MUXNEG0_bp  0  /* Negative Input MUX Selection bit 0 position. */
#define AC_MUXNEG1_bm  (1<<1)  /* Negative Input MUX Selection bit 1 mask. */
#define AC_MUXNEG1_bp  1  /* Negative Input MUX Selection bit 1 position. */
#define AC_MUXPOS_bm  0x08  /* Positive Input MUX Selection bit mask. */
#define AC_MUXPOS_bp  3  /* Positive Input MUX Selection bit position. */
#define AC_INVERT_bm  0x80  /* Invert AC Output bit mask. */
#define AC_INVERT_bp  7  /* Invert AC Output bit position. */

/* AC.INTCTRL  bit masks and bit positions */
#define AC_CMP_bm  0x01  /* Analog Comparator 0 Interrupt Enable bit mask. */
#define AC_CMP_bp  0  /* Analog Comparator 0 Interrupt Enable bit position. */

/* AC.STATUS  bit masks and bit positions */
/* AC_CMP  is already defined. */
#define AC_STATE_bm  0x10  /* Analog Comparator State bit mask. */
#define AC_STATE_bp  4  /* Analog Comparator State bit position. */

/* ADC - Analog to Digital Converter */
/* ADC.CTRLA  bit masks and bit positions */
#define ADC_ENABLE_bm  0x01  /* ADC Enable bit mask. */
#define ADC_ENABLE_bp  0  /* ADC Enable bit position. */
#define ADC_FREERUN_bm  0x02  /* ADC Freerun mode bit mask. */
#define ADC_FREERUN_bp  1  /* ADC Freerun mode bit position. */
#define ADC_RESSEL_bm  0x04  /* ADC Resolution bit mask. */
#define ADC_RESSEL_bp  2  /* ADC Resolution bit position. */
#define ADC_RUNSTBY_bm  0x80  /* Run standby mode bit mask. */
#define ADC_RUNSTBY_bp  7  /* Run standby mode bit position. */

/* ADC.CTRLB  bit masks and bit positions */
#define ADC_SAMPNUM_gm  0x07  /* Accumulation Samples group mask. */
#define ADC_SAMPNUM_gp  0  /* Accumulation Samples group position. */
#define ADC_SAMPNUM0_bm  (1<<0)  /* Accumulation Samples bit 0 mask. */
#define ADC_SAMPNUM0_bp  0  /* Accumulation Samples bit 0 position. */
#define ADC_SAMPNUM1_bm  (1<<1)  /* Accumulation Samples bit 1 mask. */
#define ADC_SAMPNUM1_bp  1  /* Accumulation Samples bit 1 position. */
#define ADC_SAMPNUM2_bm  (1<<2)  /* Accumulation Samples bit 2 mask. */
#define ADC_SAMPNUM2_bp  2  /* Accumulation Samples bit 2 position. */

/* ADC.CTRLC  bit masks and bit positions */
#define ADC_PRESC_gm  0x07  /* Clock Pre-scaler group mask. */
#define ADC_PRESC_gp  0  /* Clock Pre-scaler group position. */
#define ADC_PRESC0_bm  (1<<0)  /* Clock Pre-scaler bit 0 mask. */
#define ADC_PRESC0_bp  0  /* Clock Pre-scaler bit 0 position. */
#define ADC_PRESC1_bm  (1<<1)  /* Clock Pre-scaler bit 1 mask. */
#define ADC_PRESC1_bp  1  /* Clock Pre-scaler bit 1 position. */
#define ADC_PRESC2_bm  (1<<2)  /* Clock Pre-scaler bit 2 mask. */
#define ADC_PRESC2_bp  2  /* Clock Pre-scaler bit 2 position. */
#define ADC_REFSEL_gm  0x30  /* Reference Selection group mask. */
#define ADC_REFSEL_gp  4  /* Reference Selection group position. */
#define ADC_REFSEL0_bm  (1<<4)  /* Reference Selection bit 0 mask. */
#define ADC_REFSEL0_bp  4  /* Reference Selection bit 0 position. */
#define ADC_REFSEL1_bm  (1<<5)  /* Reference Selection bit 1 mask. */
#define ADC_REFSEL1_bp  5  /* Reference Selection bit 1 position. */
#define ADC_SAMPCAP_bm  0x40  /* Sample Capacitance Selection bit mask. */
#define ADC_SAMPCAP_bp  6  /* Sample Capacitance Selection bit position. */

/* ADC.CTRLD  bit masks and bit positions */
#define ADC_SAMPDLY_gm  0x0F  /* Sampling Delay Selection group mask. */
#define ADC_SAMPDLY_gp  0  /* Sampling Delay Selection group position. */
#define ADC_SAMPDLY0_bm  (1<<0)  /* Sampling Delay Selection bit 0 mask. */
#define ADC_SAMPDLY0_bp  0  /* Sampling Delay Selection bit 0 position. */
#define ADC_SAMPDLY1_bm  (1<<1)  /* Sampling Delay Selection bit 1 mask. */
#define ADC_SAMPDLY1_bp  1  /* Sampling Delay Selection bit 1 position. */
#define ADC_SAMPDLY2_bm  (1<<2)  /* Sampling Delay Selection bit 2 mask. */
#define ADC_SAMPDLY2_bp  2  /* Sampling Delay Selection bit 2 position. */
#define ADC_SAMPDLY3_bm  (1<<3)  /* Sampling Delay Selection bit 3 mask. */
#define ADC_SAMPDLY3_bp  3  /* Sampling Delay Selection bit 3 position. */
#define ADC_ASDV_bm  0x10  /* Automatic Sampling Delay Variation bit mask. */
#define ADC_ASDV_bp  4  /* Automatic Sampling Delay Variation bit position. */
#define ADC_INITDLY_gm  0xE0  /* Initial Delay Selection group mask. */
#define ADC_INITDLY_gp  5  /* Initial Delay Selection group position. */
#define ADC_INITDLY0_bm  (1<<5)  /* Initial Delay Selection bit 0 mask. */
#define ADC_INITDLY0_bp  5  /* Initial Delay Selection bit 0 position. */
#define ADC_INITDLY1_bm  (1<<6)  /* Initial Delay Selection bit 1 mask. */
#define ADC_INITDLY1_bp  6  /* Initial Delay Selection bit 1 position. */
#define ADC_INITDLY2_bm  (1<<7)  /* Initial Delay Selection bit 2 mask. */
#define ADC_INITDLY2_bp  7  /* Initial Delay Selection bit 2 position. */

/* ADC.CTRLE  bit masks and bit positions */
#define ADC_WINCM_gm  0x07  /* Window Comparator Mode group mask. */
#define ADC_WINCM_gp  0  /* Window Comparator Mode group position. */
#define ADC_WINCM0_bm  (1<<0)  /* Window Comparator Mode bit 0 mask. */
#define ADC_WINCM0_bp  0  /* Window Comparator Mode bit 0 position. */
#define ADC_WINCM1_bm  (1<<1)  /* Window Comparator Mode bit 1 mask. */
#define ADC_WINCM1_bp  1  /* Window Comparator Mode bit 1 position. */
#define ADC_WINCM2_bm  (1<<2)  /* Window Comparator Mode bit 2 mask. */
#define ADC_WINCM2_bp  2  /* Window Comparator Mode bit 2 position. */

/* ADC.SAMPCTRL  bit masks and bit positions */
#define ADC_SAMPLEN_gm  0x1F  /* Sample lenght group mask. */
#define ADC_SAMPLEN_gp  0  /* Sample lenght group position. */
#define ADC_SAMPLEN0_bm  (1<<0)  /* Sample lenght bit 0 mask. */
#define ADC_SAMPLEN0_bp  0  /* Sample lenght bit 0 position. */
#define ADC_SAMPLEN1_bm  (1<<1)  /* Sample lenght bit 1 mask. */
#define ADC_SAMPLEN1_bp  1  /* Sample lenght bit 1 position. */
#define ADC_SAMPLEN2_bm  (1<<2)  /* Sample lenght bit 2 mask. */
#define ADC_SAMPLEN2_bp  2  /* Sample lenght bit 2 position. */
#define ADC_SAMPLEN3_bm  (1<<3)  /* Sample lenght bit 3 mask. */
#define ADC_SAMPLEN3_bp  3  /* Sample lenght bit 3 position. */
#define ADC_SAMPLEN4_bm  (1<<4)  /* Sample lenght bit 4 mask. */
#define ADC_SAMPLEN4_bp  4  /* Sample lenght bit 4 position. */

/* ADC.MUXPOS  bit masks and bit positions */
#define ADC_MUXPOS_gm  0x1F  /* Analog Channel Selection Bits group mask. */
#define ADC_MUXPOS_gp  0  /* Analog Channel Selection Bits group position. */
#define ADC_MUXPOS0_bm  (1<<0)  /* Analog Channel Selection Bits bit 0 mask. */
#define ADC_MUXPOS0_bp  0  /* Analog Channel Selection Bits bit 0 position. */
#define ADC_MUXPOS1_bm  (1<<1)  /* Analog Channel Selection Bits bit 1 mask. */
#define ADC_MUXPOS1_bp  1  /* Analog Channel Selection Bits bit 1 position. */
#define ADC_MUXPOS2_bm  (1<<2)  /* Analog Channel Selection Bits bit 2 mask. */
#define ADC_MUXPOS2_bp  2  /* Analog Channel Selection Bits bit 2 position. */
#define ADC_MUXPOS3_bm  (1<<3)  /* Analog Channel Selection Bits bit 3 mask. */
#define ADC_MUXPOS3_bp  3  /* Analog Channel Selection Bits bit 3 position. */
#define ADC_MUXPOS4_bm  (1<<4)  /* Analog Channel Selection Bits bit 4 mask. */
#define ADC_MUXPOS4_bp  4  /* Analog Channel Selection Bits bit 4 position. */

/* ADC.COMMAND  bit masks and bit positions */
#define ADC_STCONV_bm  0x01  /* Start Conversion Operation bit mask. */
#define ADC_STCONV_bp  0  /* Start Conversion Operation bit position. */

/* ADC.EVCTRL  bit masks and bit positions */
#define ADC_STARTEI_bm  0x01  /* Start Event Input Enable bit mask. */
#define ADC_STARTEI_bp  0  /* Start Event Input Enable bit position. */

/* ADC.INTCTRL  bit masks and bit positions */
#define ADC_RESRDY_bm  0x01  /* Result Ready Interrupt Enable bit mask. */
#define ADC_RESRDY_bp  0  /* Result Ready Interrupt Enable bit position. */
#define ADC_WCMP_bm  0x02  /* Window Comparator Interrupt Enable bit mask. */
#define ADC_WCMP_bp  1  /* Window Comparator Interrupt Enable bit position. */

/* ADC.INTFLAGS  bit masks and bit positions */
/* ADC_RESRDY  is already defined. */
/* ADC_WCMP  is already defined. */

/* ADC.DBGCTRL  bit masks and bit positions */
#define ADC_DBGRUN_bm  0x01  /* Debug run bit mask. */
#define ADC_DBGRUN_bp  0  /* Debug run bit position. */

/* ADC.TEMP  bit masks and bit positions */
#define ADC_TEMP_gm  0xFF  /* Temporary group mask. */
#define ADC_TEMP_gp  0  /* Temporary group position. */
#define ADC_TEMP0_bm  (1<<0)  /* Temporary bit 0 mask. */
#define ADC_TEMP0_bp  0  /* Temporary bit 0 position. */
#define ADC_TEMP1_bm  (1<<1)  /* Temporary bit 1 mask. */
#define ADC_TEMP1_bp  1  /* Temporary bit 1 position. */
#define ADC_TEMP2_bm  (1<<2)  /* Temporary bit 2 mask. */
#define ADC_TEMP2_bp  2  /* Temporary bit 2 position. */
#define ADC_TEMP3_bm  (1<<3)  /* Temporary bit 3 mask. */
#define ADC_TEMP3_bp  3  /* Temporary bit 3 position. */
#define ADC_TEMP4_bm  (1<<4)  /* Temporary bit 4 mask. */
#define ADC_TEMP4_bp  4  /* Temporary bit 4 position. */
#define ADC_TEMP5_bm  (1<<5)  /* Temporary bit 5 mask. */
#define ADC_TEMP5_bp  5  /* Temporary bit 5 position. */
#define ADC_TEMP6_bm  (1<<6)  /* Temporary bit 6 mask. */
#define ADC_TEMP6_bp  6  /* Temporary bit 6 position. */
#define ADC_TEMP7_bm  (1<<7)  /* Temporary bit 7 mask. */
#define ADC_TEMP7_bp  7  /* Temporary bit 7 position. */




/* ADC.CALIB  bit masks and bit positions */
#define ADC_DUTYCYC_bm  0x01  /* Duty Cycle bit mask. */
#define ADC_DUTYCYC_bp  0  /* Duty Cycle bit position. */

/* BOD - Bod interface */
/* BOD.CTRLA  bit masks and bit positions */
#define BOD_SLEEP_gm  0x03  /* Operation in sleep mode group mask. */
#define BOD_SLEEP_gp  0  /* Operation in sleep mode group position. */
#define BOD_SLEEP0_bm  (1<<0)  /* Operation in sleep mode bit 0 mask. */
#define BOD_SLEEP0_bp  0  /* Operation in sleep mode bit 0 position. */
#define BOD_SLEEP1_bm  (1<<1)  /* Operation in sleep mode bit 1 mask. */
#define BOD_SLEEP1_bp  1  /* Operation in sleep mode bit 1 position. */
#define BOD_ACTIVE_gm  0x0C  /* Operation in active mode group mask. */
#define BOD_ACTIVE_gp  2  /* Operation in active mode group position. */
#define BOD_ACTIVE0_bm  (1<<2)  /* Operation in active mode bit 0 mask. */
#define BOD_ACTIVE0_bp  2  /* Operation in active mode bit 0 position. */
#define BOD_ACTIVE1_bm  (1<<3)  /* Operation in active mode bit 1 mask. */
#define BOD_ACTIVE1_bp  3  /* Operation in active mode bit 1 position. */
#define BOD_SAMPFREQ_bm  0x10  /* Sample frequency bit mask. */
#define BOD_SAMPFREQ_bp  4  /* Sample frequency bit position. */

/* BOD.CTRLB  bit masks and bit positions */
#define BOD_LVL_gm  0x07  /* Bod level group mask. */
#define BOD_LVL_gp  0  /* Bod level group position. */
#define BOD_LVL0_bm  (1<<0)  /* Bod level bit 0 mask. */
#define BOD_LVL0_bp  0  /* Bod level bit 0 position. */
#define BOD_LVL1_bm  (1<<1)  /* Bod level bit 1 mask. */
#define BOD_LVL1_bp  1  /* Bod level bit 1 position. */
#define BOD_LVL2_bm  (1<<2)  /* Bod level bit 2 mask. */
#define BOD_LVL2_bp  2  /* Bod level bit 2 position. */

/* BOD.VLMCTRLA  bit masks and bit positions */
#define BOD_VLMLVL_gm  0x03  /* voltage level monitor level group mask. */
#define BOD_VLMLVL_gp  0  /* voltage level monitor level group position. */
#define BOD_VLMLVL0_bm  (1<<0)  /* voltage level monitor level bit 0 mask. */
#define BOD_VLMLVL0_bp  0  /* voltage level monitor level bit 0 position. */
#define BOD_VLMLVL1_bm  (1<<1)  /* voltage level monitor level bit 1 mask. */
#define BOD_VLMLVL1_bp  1  /* voltage level monitor level bit 1 position. */

/* BOD.INTCTRL  bit masks and bit positions */
#define BOD_VLMIE_bm  0x01  /* voltage level monitor interrrupt enable bit mask. */
#define BOD_VLMIE_bp  0  /* voltage level monitor interrrupt enable bit position. */
#define BOD_VLMCFG_gm  0x06  /* Configuration group mask. */
#define BOD_VLMCFG_gp  1  /* Configuration group position. */
#define BOD_VLMCFG0_bm  (1<<1)  /* Configuration bit 0 mask. */
#define BOD_VLMCFG0_bp  1  /* Configuration bit 0 position. */
#define BOD_VLMCFG1_bm  (1<<2)  /* Configuration bit 1 mask. */
#define BOD_VLMCFG1_bp  2  /* Configuration bit 1 position. */

/* BOD.INTFLAGS  bit masks and bit positions */
#define BOD_VLMIF_bm  0x01  /* Voltage level monitor interrupt flag bit mask. */
#define BOD_VLMIF_bp  0  /* Voltage level monitor interrupt flag bit position. */

/* BOD.STATUS  bit masks and bit positions */
#define BOD_VLMS_bm  0x01  /* Voltage level monitor status bit mask. */
#define BOD_VLMS_bp  0  /* Voltage level monitor status bit position. */

/* CCL - Configurable Custom Logic */
/* CCL.CTRLA  bit masks and bit positions */
#define CCL_ENABLE_bm  0x01  /* Enable bit mask. */
#define CCL_ENABLE_bp  0  /* Enable bit position. */
#define CCL_RUNSTDBY_bm  0x40  /* Run in Standby bit mask. */
#define CCL_RUNSTDBY_bp  6  /* Run in Standby bit position. */

/* CCL.SEQCTRL0  bit masks and bit positions */
#define CCL_SEQSEL_gm  0x07  /* Sequential Selection group mask. */
#define CCL_SEQSEL_gp  0  /* Sequential Selection group position. */
#define CCL_SEQSEL0_bm  (1<<0)  /* Sequential Selection bit 0 mask. */
#define CCL_SEQSEL0_bp  0  /* Sequential Selection bit 0 position. */
#define CCL_SEQSEL1_bm  (1<<1)  /* Sequential Selection bit 1 mask. */
#define CCL_SEQSEL1_bp  1  /* Sequential Selection bit 1 position. */
#define CCL_SEQSEL2_bm  (1<<2)  /* Sequential Selection bit 2 mask. */
#define CCL_SEQSEL2_bp  2  /* Sequential Selection bit 2 position. */

/* CCL.LUT0CTRLA  bit masks and bit positions */
/* CCL_ENABLE  is already defined. */
#define CCL_OUTEN_bm  0x08  /* Output Enable bit mask. */
#define CCL_OUTEN_bp  3  /* Output Enable bit position. */
#define CCL_FILTSEL_gm  0x30  /* Filter Selection group mask. */
#define CCL_FILTSEL_gp  4  /* Filter Selection group position. */
#define CCL_FILTSEL0_bm  (1<<4)  /* Filter Selection bit 0 mask. */
#define CCL_FILTSEL0_bp  4  /* Filter Selection bit 0 position. */
#define CCL_FILTSEL1_bm  (1<<5)  /* Filter Selection bit 1 mask. */
#define CCL_FILTSEL1_bp  5  /* Filter Selection bit 1 position. */
#define CCL_CLKSRC_bm  0x40  /* Clock Source Selection bit mask. */
#define CCL_CLKSRC_bp  6  /* Clock Source Selection bit position. */
#define CCL_EDGEDET_bm  0x80  /* Edge Detection Enable bit mask. */
#define CCL_EDGEDET_bp  7  /* Edge Detection Enable bit position. */

/* CCL.LUT0CTRLB  bit masks and bit positions */
#define CCL_INSEL0_gm  0x0F  /* LUT Input 0 Source Selection group mask. */
#define CCL_INSEL0_gp  0  /* LUT Input 0 Source Selection group position. */
#define CCL_INSEL00_bm  (1<<0)  /* LUT Input 0 Source Selection bit 0 mask. */
#define CCL_INSEL00_bp  0  /* LUT Input 0 Source Selection bit 0 position. */
#define CCL_INSEL01_bm  (1<<1)  /* LUT Input 0 Source Selection bit 1 mask. */
#define CCL_INSEL01_bp  1  /* LUT Input 0 Source Selection bit 1 position. */
#define CCL_INSEL02_bm  (1<<2)  /* LUT Input 0 Source Selection bit 2 mask. */
#define CCL_INSEL02_bp  2  /* LUT Input 0 Source Selection bit 2 position. */
#define CCL_INSEL03_bm  (1<<3)  /* LUT Input 0 Source Selection bit 3 mask. */
#define CCL_INSEL03_bp  3  /* LUT Input 0 Source Selection bit 3 position. */
#define CCL_INSEL1_gm  0xF0  /* LUT Input 1 Source Selection group mask. */
#define CCL_INSEL1_gp  4  /* LUT Input 1 Source Selection group position. */
#define CCL_INSEL10_bm  (1<<4)  /* LUT Input 1 Source Selection bit 0 mask. */
#define CCL_INSEL10_bp  4  /* LUT Input 1 Source Selection bit 0 position. */
#define CCL_INSEL11_bm  (1<<5)  /* LUT Input 1 Source Selection bit 1 mask. */
#define CCL_INSEL11_bp  5  /* LUT Input 1 Source Selection bit 1 position. */
#define CCL_INSEL12_bm  (1<<6)  /* LUT Input 1 Source Selection bit 2 mask. */
#define CCL_INSEL12_bp  6  /* LUT Input 1 Source Selection bit 2 position. */
#define CCL_INSEL13_bm  (1<<7)  /* LUT Input 1 Source Selection bit 3 mask. */
#define CCL_INSEL13_bp  7  /* LUT Input 1 Source Selection bit 3 position. */

/* CCL.LUT0CTRLC  bit masks and bit positions */
#define CCL_INSEL2_gm  0x0F  /* LUT Input 2 Source Selection group mask. */
#define CCL_INSEL2_gp  0  /* LUT Input 2 Source Selection group position. */
#define CCL_INSEL20_bm  (1<<0)  /* LUT Input 2 Source Selection bit 0 mask. */
#define CCL_INSEL20_bp  0  /* LUT Input 2 Source Selection bit 0 position. */
#define CCL_INSEL21_bm  (1<<1)  /* LUT Input 2 Source Selection bit 1 mask. */
#define CCL_INSEL21_bp  1  /* LUT Input 2 Source Selection bit 1 position. */
#define CCL_INSEL22_bm  (1<<2)  /* LUT Input 2 Source Selection bit 2 mask. */
#define CCL_INSEL22_bp  2  /* LUT Input 2 Source Selection bit 2 position. */
#define CCL_INSEL23_bm  (1<<3)  /* LUT Input 2 Source Selection bit 3 mask. */
#define CCL_INSEL23_bp  3  /* LUT Input 2 Source Selection bit 3 position. */


/* CCL.LUT1CTRLA  bit masks and bit positions */
/* CCL_ENABLE  is already defined. */
/* CCL_OUTEN  is already defined. */
/* CCL_FILTSEL  is already defined. */
/* CCL_CLKSRC  is already defined. */
/* CCL_EDGEDET  is already defined. */

/* CCL.LUT1CTRLB  bit masks and bit positions */
/* CCL_INSEL0  is already defined. */
/* CCL_INSEL1  is already defined. */

/* CCL.LUT1CTRLC  bit masks and bit positions */
/* CCL_INSEL2  is already defined. */


/* CLKCTRL - Clock controller */
/* CLKCTRL.MCLKCTRLA  bit masks and bit positions */
#define CLKCTRL_CLKSEL_gm  0x03  /* clock select group mask. */
#define CLKCTRL_CLKSEL_gp  0  /* clock select group position. */
#define CLKCTRL_CLKSEL0_bm  (1<<0)  /* clock select bit 0 mask. */
#define CLKCTRL_CLKSEL0_bp  0  /* clock select bit 0 position. */
#define CLKCTRL_CLKSEL1_bm  (1<<1)  /* clock select bit 1 mask. */
#define CLKCTRL_CLKSEL1_bp  1  /* clock select bit 1 position. */
#define CLKCTRL_CLKOUT_bm  0x80  /* System clock out bit mask. */
#define CLKCTRL_CLKOUT_bp  7  /* System clock out bit position. */

/* CLKCTRL.MCLKCTRLB  bit masks and bit positions */
#define CLKCTRL_PEN_bm  0x01  /* Prescaler enable bit mask. */
#define CLKCTRL_PEN_bp  0  /* Prescaler enable bit position. */
#define CLKCTRL_PDIV_gm  0x1E  /* Prescaler division group mask. */
#define CLKCTRL_PDIV_gp  1  /* Prescaler division group position. */
#define CLKCTRL_PDIV0_bm  (1<<1)  /* Prescaler division bit 0 mask. */
#define CLKCTRL_PDIV0_bp  1  /* Prescaler division bit 0 position. */
#define CLKCTRL_PDIV1_bm  (1<<2)  /* Prescaler division bit 1 mask. */
#define CLKCTRL_PDIV1_bp  2  /* Prescaler division bit 1 position. */
#define CLKCTRL_PDIV2_bm  (1<<3)  /* Prescaler division bit 2 mask. */
#define CLKCTRL_PDIV2_bp  3  /* Prescaler division bit 2 position. */
#define CLKCTRL_PDIV3_bm  (1<<4)  /* Prescaler division bit 3 mask. */
#define CLKCTRL_PDIV3_bp  4  /* Prescaler division bit 3 position. */

/* CLKCTRL.MCLKLOCK  bit masks and bit positions */
#define CLKCTRL_LOCKEN_bm  0x01  /* lock ebable bit mask. */
#define CLKCTRL_LOCKEN_bp  0  /* lock ebable bit position. */

/* CLKCTRL.MCLKSTATUS  bit masks and bit positions */
#define CLKCTRL_SOSC_bm  0x01  /* System Oscillator changing bit mask. */
#define CLKCTRL_SOSC_bp  0  /* System Oscillator changing bit position. */
#define CLKCTRL_OSC20MS_bm  0x10  /* 20MHz oscillator status bit mask. */
#define CLKCTRL_OSC20MS_bp  4  /* 20MHz oscillator status bit position. */
#define CLKCTRL_OSC32KS_bm  0x20  /* 32KHz oscillator status bit mask. */
#define CLKCTRL_OSC32KS_bp  5  /* 32KHz oscillator status bit position. */
#define CLKCTRL_XOSC32KS_bm  0x40  /* 32.768 kHz Crystal Oscillator status bit mask. */
#define CLKCTRL_XOSC32KS_bp  6  /* 32.768 kHz Crystal Oscillator status bit position. */
#define CLKCTRL_EXTS_bm  0x80  /* External Clock status bit mask. */
#define CLKCTRL_EXTS_bp  7  /* External Clock status bit position. */

/* CLKCTRL.OSC20MCTRLA  bit masks and bit positions */
#define CLKCTRL_RUNSTDBY_bm  0x02  /* Run standby bit mask. */
#define CLKCTRL_RUNSTDBY_bp  1  /* Run standby bit position. */

/* CLKCTRL.OSC20MCALIBA  bit masks and bit positions */
#define CLKCTRL_CAL20M_gm  0x3F  /* Calibration group mask. */
#define CLKCTRL_CAL20M_gp  0  /* Calibration group position. */
#define CLKCTRL_CAL20M0_bm  (1<<0)  /* Calibration bit 0 mask. */
#define CLKCTRL_CAL20M0_bp  0  /* Calibration bit 0 position. */
#define CLKCTRL_CAL20M1_bm  (1<<1)  /* Calibration bit 1 mask. */
#define CLKCTRL_CAL20M1_bp  1  /* Calibration bit 1 position. */
#define CLKCTRL_CAL20M2_bm  (1<<2)  /* Calibration bit 2 mask. */
#define CLKCTRL_CAL20M2_bp  2  /* Calibration bit 2 position. */
#define CLKCTRL_CAL20M3_bm  (1<<3)  /* Calibration bit 3 mask. */
#define CLKCTRL_CAL20M3_bp  3  /* Calibration bit 3 position. */
#define CLKCTRL_CAL20M4_bm  (1<<4)  /* Calibration bit 4 mask. */
#define CLKCTRL_CAL20M4_bp  4  /* Calibration bit 4 position. */
#define CLKCTRL_CAL20M5_bm  (1<<5)  /* Calibration bit 5 mask. */
#define CLKCTRL_CAL20M5_bp  5  /* Calibration bit 5 position. */

/* CLKCTRL.OSC20MCALIBB  bit masks and bit positions */
#define CLKCTRL_TEMPCAL20M_gm  0x0F  /* Oscillator temperature coefficient group mask. */
#define CLKCTRL_TEMPCAL20M_gp  0  /* Oscillator temperature coefficient group position. */
#define CLKCTRL_TEMPCAL20M0_bm  (1<<0)  /* Oscillator temperature coefficient bit 0 mask. */
#define CLKCTRL_TEMPCAL20M0_bp  0  /* Oscillator temperature coefficient bit 0 position. */
#define CLKCTRL_TEMPCAL20M1_bm  (1<<1)  /* Oscillator temperature coefficient bit 1 mask. */
#define CLKCTRL_TEMPCAL20M1_bp  1  /* Oscillator temperature coefficient bit 1 position. */
#define CLKCTRL_TEMPCAL20M2_bm  (1<<2)  /* Oscillator temperature coefficient bit 2 mask. */
#define CLKCTRL_TEMPCAL20M2_bp  2  /* Oscillator temperature coefficient bit 2 position. */
#define CLKCTRL_TEMPCAL20M3_bm  (1<<3)  /* Oscillator temperature coefficient bit 3 mask. */
#define CLKCTRL_TEMPCAL20M3_bp  3  /* Oscillator temperature coefficient bit 3 position. */
#define CLKCTRL_LOCK_bm  0x80  /* Lock bit mask. */
#define CLKCTRL_LOCK_bp  7  /* Lock bit position. */

/* CLKCTRL.OSC32KCTRLA  bit masks and bit positions */
/* CLKCTRL_RUNSTDBY  is already defined. */

/* CLKCTRL.XOSC32KCTRLA  bit masks and bit positions */
#define CLKCTRL_ENABLE_bm  0x01  /* Enable bit mask. */
#define CLKCTRL_ENABLE_bp  0  /* Enable bit position. */
/* CLKCTRL_RUNSTDBY  is already defined. */
#define CLKCTRL_SEL_bm  0x04  /* Select bit mask. */
#define CLKCTRL_SEL_bp  2  /* Select bit position. */
#define CLKCTRL_CSUT_gm  0x30  /* Crystal startup time group mask. */
#define CLKCTRL_CSUT_gp  4  /* Crystal startup time group position. */
#define CLKCTRL_CSUT0_bm  (1<<4)  /* Crystal startup time bit 0 mask. */
#define CLKCTRL_CSUT0_bp  4  /* Crystal startup time bit 0 position. */
#define CLKCTRL_CSUT1_bm  (1<<5)  /* Crystal startup time bit 1 mask. */
#define CLKCTRL_CSUT1_bp  5  /* Crystal startup time bit 1 position. */

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
#define CPU_C_bm  0x01  /* Carry Flag bit mask. */
#define CPU_C_bp  0  /* Carry Flag bit position. */
#define CPU_Z_bm  0x02  /* Zero Flag bit mask. */
#define CPU_Z_bp  1  /* Zero Flag bit position. */
#define CPU_N_bm  0x04  /* Negative Flag bit mask. */
#define CPU_N_bp  2  /* Negative Flag bit position. */
#define CPU_V_bm  0x08  /* Two's Complement Overflow Flag bit mask. */
#define CPU_V_bp  3  /* Two's Complement Overflow Flag bit position. */
#define CPU_S_bm  0x10  /* N Exclusive Or V Flag bit mask. */
#define CPU_S_bp  4  /* N Exclusive Or V Flag bit position. */
#define CPU_H_bm  0x20  /* Half Carry Flag bit mask. */
#define CPU_H_bp  5  /* Half Carry Flag bit position. */
#define CPU_T_bm  0x40  /* Transfer Bit bit mask. */
#define CPU_T_bp  6  /* Transfer Bit bit position. */
#define CPU_I_bm  0x80  /* Global Interrupt Enable Flag bit mask. */
#define CPU_I_bp  7  /* Global Interrupt Enable Flag bit position. */

/* CPUINT - Interrupt Controller */
/* CPUINT.CTRLA  bit masks and bit positions */
#define CPUINT_LVL0RR_bm  0x01  /* Round-robin Scheduling Enable bit mask. */
#define CPUINT_LVL0RR_bp  0  /* Round-robin Scheduling Enable bit position. */
#define CPUINT_CVT_bm  0x20  /* Compact Vector Table bit mask. */
#define CPUINT_CVT_bp  5  /* Compact Vector Table bit position. */
#define CPUINT_IVSEL_bm  0x40  /* Interrupt Vector Select bit mask. */
#define CPUINT_IVSEL_bp  6  /* Interrupt Vector Select bit position. */

/* CPUINT.STATUS  bit masks and bit positions */
#define CPUINT_LVL0EX_bm  0x01  /* Level 0 Interrupt Executing bit mask. */
#define CPUINT_LVL0EX_bp  0  /* Level 0 Interrupt Executing bit position. */
#define CPUINT_LVL1EX_bm  0x02  /* Level 1 Interrupt Executing bit mask. */
#define CPUINT_LVL1EX_bp  1  /* Level 1 Interrupt Executing bit position. */
#define CPUINT_NMIEX_bm  0x80  /* Non-maskable Interrupt Executing bit mask. */
#define CPUINT_NMIEX_bp  7  /* Non-maskable Interrupt Executing bit position. */

/* CPUINT.LVL0PRI  bit masks and bit positions */
#define CPUINT_LVL0PRI_gm  0xFF  /* Interrupt Level Priority group mask. */
#define CPUINT_LVL0PRI_gp  0  /* Interrupt Level Priority group position. */
#define CPUINT_LVL0PRI0_bm  (1<<0)  /* Interrupt Level Priority bit 0 mask. */
#define CPUINT_LVL0PRI0_bp  0  /* Interrupt Level Priority bit 0 position. */
#define CPUINT_LVL0PRI1_bm  (1<<1)  /* Interrupt Level Priority bit 1 mask. */
#define CPUINT_LVL0PRI1_bp  1  /* Interrupt Level Priority bit 1 position. */
#define CPUINT_LVL0PRI2_bm  (1<<2)  /* Interrupt Level Priority bit 2 mask. */
#define CPUINT_LVL0PRI2_bp  2  /* Interrupt Level Priority bit 2 position. */
#define CPUINT_LVL0PRI3_bm  (1<<3)  /* Interrupt Level Priority bit 3 mask. */
#define CPUINT_LVL0PRI3_bp  3  /* Interrupt Level Priority bit 3 position. */
#define CPUINT_LVL0PRI4_bm  (1<<4)  /* Interrupt Level Priority bit 4 mask. */
#define CPUINT_LVL0PRI4_bp  4  /* Interrupt Level Priority bit 4 position. */
#define CPUINT_LVL0PRI5_bm  (1<<5)  /* Interrupt Level Priority bit 5 mask. */
#define CPUINT_LVL0PRI5_bp  5  /* Interrupt Level Priority bit 5 position. */
#define CPUINT_LVL0PRI6_bm  (1<<6)  /* Interrupt Level Priority bit 6 mask. */
#define CPUINT_LVL0PRI6_bp  6  /* Interrupt Level Priority bit 6 position. */
#define CPUINT_LVL0PRI7_bm  (1<<7)  /* Interrupt Level Priority bit 7 mask. */
#define CPUINT_LVL0PRI7_bp  7  /* Interrupt Level Priority bit 7 position. */

/* CPUINT.LVL1VEC  bit masks and bit positions */
#define CPUINT_LVL1VEC_gm  0xFF  /* Interrupt Vector with High Priority group mask. */
#define CPUINT_LVL1VEC_gp  0  /* Interrupt Vector with High Priority group position. */
#define CPUINT_LVL1VEC0_bm  (1<<0)  /* Interrupt Vector with High Priority bit 0 mask. */
#define CPUINT_LVL1VEC0_bp  0  /* Interrupt Vector with High Priority bit 0 position. */
#define CPUINT_LVL1VEC1_bm  (1<<1)  /* Interrupt Vector with High Priority bit 1 mask. */
#define CPUINT_LVL1VEC1_bp  1  /* Interrupt Vector with High Priority bit 1 position. */
#define CPUINT_LVL1VEC2_bm  (1<<2)  /* Interrupt Vector with High Priority bit 2 mask. */
#define CPUINT_LVL1VEC2_bp  2  /* Interrupt Vector with High Priority bit 2 position. */
#define CPUINT_LVL1VEC3_bm  (1<<3)  /* Interrupt Vector with High Priority bit 3 mask. */
#define CPUINT_LVL1VEC3_bp  3  /* Interrupt Vector with High Priority bit 3 position. */
#define CPUINT_LVL1VEC4_bm  (1<<4)  /* Interrupt Vector with High Priority bit 4 mask. */
#define CPUINT_LVL1VEC4_bp  4  /* Interrupt Vector with High Priority bit 4 position. */
#define CPUINT_LVL1VEC5_bm  (1<<5)  /* Interrupt Vector with High Priority bit 5 mask. */
#define CPUINT_LVL1VEC5_bp  5  /* Interrupt Vector with High Priority bit 5 position. */
#define CPUINT_LVL1VEC6_bm  (1<<6)  /* Interrupt Vector with High Priority bit 6 mask. */
#define CPUINT_LVL1VEC6_bp  6  /* Interrupt Vector with High Priority bit 6 position. */
#define CPUINT_LVL1VEC7_bm  (1<<7)  /* Interrupt Vector with High Priority bit 7 mask. */
#define CPUINT_LVL1VEC7_bp  7  /* Interrupt Vector with High Priority bit 7 position. */

/* CRCSCAN - CRCSCAN */
/* CRCSCAN.CTRLA  bit masks and bit positions */
#define CRCSCAN_ENABLE_bm  0x01  /* Enable CRC scan bit mask. */
#define CRCSCAN_ENABLE_bp  0  /* Enable CRC scan bit position. */
#define CRCSCAN_NMIEN_bm  0x02  /* Enable NMI Trigger bit mask. */
#define CRCSCAN_NMIEN_bp  1  /* Enable NMI Trigger bit position. */
#define CRCSCAN_RESET_bm  0x80  /* Reset CRC scan bit mask. */
#define CRCSCAN_RESET_bp  7  /* Reset CRC scan bit position. */

/* CRCSCAN.CTRLB  bit masks and bit positions */
#define CRCSCAN_SRC_gm  0x03  /* CRC Source group mask. */
#define CRCSCAN_SRC_gp  0  /* CRC Source group position. */
#define CRCSCAN_SRC0_bm  (1<<0)  /* CRC Source bit 0 mask. */
#define CRCSCAN_SRC0_bp  0  /* CRC Source bit 0 position. */
#define CRCSCAN_SRC1_bm  (1<<1)  /* CRC Source bit 1 mask. */
#define CRCSCAN_SRC1_bp  1  /* CRC Source bit 1 position. */
#define CRCSCAN_MODE_gm  0x30  /* CRC Flash Access Mode group mask. */
#define CRCSCAN_MODE_gp  4  /* CRC Flash Access Mode group position. */
#define CRCSCAN_MODE0_bm  (1<<4)  /* CRC Flash Access Mode bit 0 mask. */
#define CRCSCAN_MODE0_bp  4  /* CRC Flash Access Mode bit 0 position. */
#define CRCSCAN_MODE1_bm  (1<<5)  /* CRC Flash Access Mode bit 1 mask. */
#define CRCSCAN_MODE1_bp  5  /* CRC Flash Access Mode bit 1 position. */

/* CRCSCAN.STATUS  bit masks and bit positions */
#define CRCSCAN_BUSY_bm  0x01  /* CRC Busy bit mask. */
#define CRCSCAN_BUSY_bp  0  /* CRC Busy bit position. */
#define CRCSCAN_OK_bm  0x02  /* CRC Ok bit mask. */
#define CRCSCAN_OK_bp  1  /* CRC Ok bit position. */

/* DAC - Digital to Analog Converter */
/* DAC.CTRLA  bit masks and bit positions */
#define DAC_ENABLE_bm  0x01  /* DAC Enable bit mask. */
#define DAC_ENABLE_bp  0  /* DAC Enable bit position. */
#define DAC_OUTEN_bm  0x40  /* Output Buffer Enable bit mask. */
#define DAC_OUTEN_bp  6  /* Output Buffer Enable bit position. */
#define DAC_RUNSTDBY_bm  0x80  /* Run in Standby Mode bit mask. */
#define DAC_RUNSTDBY_bp  7  /* Run in Standby Mode bit position. */




/* EVSYS - Event System */
/* EVSYS.ASYNCCH0  bit masks and bit positions */
#define EVSYS_ASYNCCH0_gm  0xFF  /* Asynchronous Channel 0 Generator Selection group mask. */
#define EVSYS_ASYNCCH0_gp  0  /* Asynchronous Channel 0 Generator Selection group position. */
#define EVSYS_ASYNCCH00_bm  (1<<0)  /* Asynchronous Channel 0 Generator Selection bit 0 mask. */
#define EVSYS_ASYNCCH00_bp  0  /* Asynchronous Channel 0 Generator Selection bit 0 position. */
#define EVSYS_ASYNCCH01_bm  (1<<1)  /* Asynchronous Channel 0 Generator Selection bit 1 mask. */
#define EVSYS_ASYNCCH01_bp  1  /* Asynchronous Channel 0 Generator Selection bit 1 position. */
#define EVSYS_ASYNCCH02_bm  (1<<2)  /* Asynchronous Channel 0 Generator Selection bit 2 mask. */
#define EVSYS_ASYNCCH02_bp  2  /* Asynchronous Channel 0 Generator Selection bit 2 position. */
#define EVSYS_ASYNCCH03_bm  (1<<3)  /* Asynchronous Channel 0 Generator Selection bit 3 mask. */
#define EVSYS_ASYNCCH03_bp  3  /* Asynchronous Channel 0 Generator Selection bit 3 position. */
#define EVSYS_ASYNCCH04_bm  (1<<4)  /* Asynchronous Channel 0 Generator Selection bit 4 mask. */
#define EVSYS_ASYNCCH04_bp  4  /* Asynchronous Channel 0 Generator Selection bit 4 position. */
#define EVSYS_ASYNCCH05_bm  (1<<5)  /* Asynchronous Channel 0 Generator Selection bit 5 mask. */
#define EVSYS_ASYNCCH05_bp  5  /* Asynchronous Channel 0 Generator Selection bit 5 position. */
#define EVSYS_ASYNCCH06_bm  (1<<6)  /* Asynchronous Channel 0 Generator Selection bit 6 mask. */
#define EVSYS_ASYNCCH06_bp  6  /* Asynchronous Channel 0 Generator Selection bit 6 position. */
#define EVSYS_ASYNCCH07_bm  (1<<7)  /* Asynchronous Channel 0 Generator Selection bit 7 mask. */
#define EVSYS_ASYNCCH07_bp  7  /* Asynchronous Channel 0 Generator Selection bit 7 position. */

/* EVSYS.ASYNCCH1  bit masks and bit positions */
#define EVSYS_ASYNCCH1_gm  0xFF  /* Asynchronous Channel 1 Generator Selection group mask. */
#define EVSYS_ASYNCCH1_gp  0  /* Asynchronous Channel 1 Generator Selection group position. */
#define EVSYS_ASYNCCH10_bm  (1<<0)  /* Asynchronous Channel 1 Generator Selection bit 0 mask. */
#define EVSYS_ASYNCCH10_bp  0  /* Asynchronous Channel 1 Generator Selection bit 0 position. */
#define EVSYS_ASYNCCH11_bm  (1<<1)  /* Asynchronous Channel 1 Generator Selection bit 1 mask. */
#define EVSYS_ASYNCCH11_bp  1  /* Asynchronous Channel 1 Generator Selection bit 1 position. */
#define EVSYS_ASYNCCH12_bm  (1<<2)  /* Asynchronous Channel 1 Generator Selection bit 2 mask. */
#define EVSYS_ASYNCCH12_bp  2  /* Asynchronous Channel 1 Generator Selection bit 2 position. */
#define EVSYS_ASYNCCH13_bm  (1<<3)  /* Asynchronous Channel 1 Generator Selection bit 3 mask. */
#define EVSYS_ASYNCCH13_bp  3  /* Asynchronous Channel 1 Generator Selection bit 3 position. */
#define EVSYS_ASYNCCH14_bm  (1<<4)  /* Asynchronous Channel 1 Generator Selection bit 4 mask. */
#define EVSYS_ASYNCCH14_bp  4  /* Asynchronous Channel 1 Generator Selection bit 4 position. */
#define EVSYS_ASYNCCH15_bm  (1<<5)  /* Asynchronous Channel 1 Generator Selection bit 5 mask. */
#define EVSYS_ASYNCCH15_bp  5  /* Asynchronous Channel 1 Generator Selection bit 5 position. */
#define EVSYS_ASYNCCH16_bm  (1<<6)  /* Asynchronous Channel 1 Generator Selection bit 6 mask. */
#define EVSYS_ASYNCCH16_bp  6  /* Asynchronous Channel 1 Generator Selection bit 6 position. */
#define EVSYS_ASYNCCH17_bm  (1<<7)  /* Asynchronous Channel 1 Generator Selection bit 7 mask. */
#define EVSYS_ASYNCCH17_bp  7  /* Asynchronous Channel 1 Generator Selection bit 7 position. */

/* EVSYS.ASYNCCH2  bit masks and bit positions */
#define EVSYS_ASYNCCH2_gm  0xFF  /* Asynchronous Channel 2 Generator Selection group mask. */
#define EVSYS_ASYNCCH2_gp  0  /* Asynchronous Channel 2 Generator Selection group position. */
#define EVSYS_ASYNCCH20_bm  (1<<0)  /* Asynchronous Channel 2 Generator Selection bit 0 mask. */
#define EVSYS_ASYNCCH20_bp  0  /* Asynchronous Channel 2 Generator Selection bit 0 position. */
#define EVSYS_ASYNCCH21_bm  (1<<1)  /* Asynchronous Channel 2 Generator Selection bit 1 mask. */
#define EVSYS_ASYNCCH21_bp  1  /* Asynchronous Channel 2 Generator Selection bit 1 position. */
#define EVSYS_ASYNCCH22_bm  (1<<2)  /* Asynchronous Channel 2 Generator Selection bit 2 mask. */
#define EVSYS_ASYNCCH22_bp  2  /* Asynchronous Channel 2 Generator Selection bit 2 position. */
#define EVSYS_ASYNCCH23_bm  (1<<3)  /* Asynchronous Channel 2 Generator Selection bit 3 mask. */
#define EVSYS_ASYNCCH23_bp  3  /* Asynchronous Channel 2 Generator Selection bit 3 position. */
#define EVSYS_ASYNCCH24_bm  (1<<4)  /* Asynchronous Channel 2 Generator Selection bit 4 mask. */
#define EVSYS_ASYNCCH24_bp  4  /* Asynchronous Channel 2 Generator Selection bit 4 position. */
#define EVSYS_ASYNCCH25_bm  (1<<5)  /* Asynchronous Channel 2 Generator Selection bit 5 mask. */
#define EVSYS_ASYNCCH25_bp  5  /* Asynchronous Channel 2 Generator Selection bit 5 position. */
#define EVSYS_ASYNCCH26_bm  (1<<6)  /* Asynchronous Channel 2 Generator Selection bit 6 mask. */
#define EVSYS_ASYNCCH26_bp  6  /* Asynchronous Channel 2 Generator Selection bit 6 position. */
#define EVSYS_ASYNCCH27_bm  (1<<7)  /* Asynchronous Channel 2 Generator Selection bit 7 mask. */
#define EVSYS_ASYNCCH27_bp  7  /* Asynchronous Channel 2 Generator Selection bit 7 position. */

/* EVSYS.ASYNCCH3  bit masks and bit positions */
#define EVSYS_ASYNCCH3_gm  0xFF  /* Asynchronous Channel 3 Generator Selection group mask. */
#define EVSYS_ASYNCCH3_gp  0  /* Asynchronous Channel 3 Generator Selection group position. */
#define EVSYS_ASYNCCH30_bm  (1<<0)  /* Asynchronous Channel 3 Generator Selection bit 0 mask. */
#define EVSYS_ASYNCCH30_bp  0  /* Asynchronous Channel 3 Generator Selection bit 0 position. */
#define EVSYS_ASYNCCH31_bm  (1<<1)  /* Asynchronous Channel 3 Generator Selection bit 1 mask. */
#define EVSYS_ASYNCCH31_bp  1  /* Asynchronous Channel 3 Generator Selection bit 1 position. */
#define EVSYS_ASYNCCH32_bm  (1<<2)  /* Asynchronous Channel 3 Generator Selection bit 2 mask. */
#define EVSYS_ASYNCCH32_bp  2  /* Asynchronous Channel 3 Generator Selection bit 2 position. */
#define EVSYS_ASYNCCH33_bm  (1<<3)  /* Asynchronous Channel 3 Generator Selection bit 3 mask. */
#define EVSYS_ASYNCCH33_bp  3  /* Asynchronous Channel 3 Generator Selection bit 3 position. */
#define EVSYS_ASYNCCH34_bm  (1<<4)  /* Asynchronous Channel 3 Generator Selection bit 4 mask. */
#define EVSYS_ASYNCCH34_bp  4  /* Asynchronous Channel 3 Generator Selection bit 4 position. */
#define EVSYS_ASYNCCH35_bm  (1<<5)  /* Asynchronous Channel 3 Generator Selection bit 5 mask. */
#define EVSYS_ASYNCCH35_bp  5  /* Asynchronous Channel 3 Generator Selection bit 5 position. */
#define EVSYS_ASYNCCH36_bm  (1<<6)  /* Asynchronous Channel 3 Generator Selection bit 6 mask. */
#define EVSYS_ASYNCCH36_bp  6  /* Asynchronous Channel 3 Generator Selection bit 6 position. */
#define EVSYS_ASYNCCH37_bm  (1<<7)  /* Asynchronous Channel 3 Generator Selection bit 7 mask. */
#define EVSYS_ASYNCCH37_bp  7  /* Asynchronous Channel 3 Generator Selection bit 7 position. */

/* EVSYS.SYNCCH0  bit masks and bit positions */
#define EVSYS_SYNCCH0_gm  0xFF  /* Synchronous Channel 0 Generator Selection group mask. */
#define EVSYS_SYNCCH0_gp  0  /* Synchronous Channel 0 Generator Selection group position. */
#define EVSYS_SYNCCH00_bm  (1<<0)  /* Synchronous Channel 0 Generator Selection bit 0 mask. */
#define EVSYS_SYNCCH00_bp  0  /* Synchronous Channel 0 Generator Selection bit 0 position. */
#define EVSYS_SYNCCH01_bm  (1<<1)  /* Synchronous Channel 0 Generator Selection bit 1 mask. */
#define EVSYS_SYNCCH01_bp  1  /* Synchronous Channel 0 Generator Selection bit 1 position. */
#define EVSYS_SYNCCH02_bm  (1<<2)  /* Synchronous Channel 0 Generator Selection bit 2 mask. */
#define EVSYS_SYNCCH02_bp  2  /* Synchronous Channel 0 Generator Selection bit 2 position. */
#define EVSYS_SYNCCH03_bm  (1<<3)  /* Synchronous Channel 0 Generator Selection bit 3 mask. */
#define EVSYS_SYNCCH03_bp  3  /* Synchronous Channel 0 Generator Selection bit 3 position. */
#define EVSYS_SYNCCH04_bm  (1<<4)  /* Synchronous Channel 0 Generator Selection bit 4 mask. */
#define EVSYS_SYNCCH04_bp  4  /* Synchronous Channel 0 Generator Selection bit 4 position. */
#define EVSYS_SYNCCH05_bm  (1<<5)  /* Synchronous Channel 0 Generator Selection bit 5 mask. */
#define EVSYS_SYNCCH05_bp  5  /* Synchronous Channel 0 Generator Selection bit 5 position. */
#define EVSYS_SYNCCH06_bm  (1<<6)  /* Synchronous Channel 0 Generator Selection bit 6 mask. */
#define EVSYS_SYNCCH06_bp  6  /* Synchronous Channel 0 Generator Selection bit 6 position. */
#define EVSYS_SYNCCH07_bm  (1<<7)  /* Synchronous Channel 0 Generator Selection bit 7 mask. */
#define EVSYS_SYNCCH07_bp  7  /* Synchronous Channel 0 Generator Selection bit 7 position. */

/* EVSYS.SYNCCH1  bit masks and bit positions */
#define EVSYS_SYNCCH1_gm  0xFF  /* Synchronous Channel 1 Generator Selection group mask. */
#define EVSYS_SYNCCH1_gp  0  /* Synchronous Channel 1 Generator Selection group position. */
#define EVSYS_SYNCCH10_bm  (1<<0)  /* Synchronous Channel 1 Generator Selection bit 0 mask. */
#define EVSYS_SYNCCH10_bp  0  /* Synchronous Channel 1 Generator Selection bit 0 position. */
#define EVSYS_SYNCCH11_bm  (1<<1)  /* Synchronous Channel 1 Generator Selection bit 1 mask. */
#define EVSYS_SYNCCH11_bp  1  /* Synchronous Channel 1 Generator Selection bit 1 position. */
#define EVSYS_SYNCCH12_bm  (1<<2)  /* Synchronous Channel 1 Generator Selection bit 2 mask. */
#define EVSYS_SYNCCH12_bp  2  /* Synchronous Channel 1 Generator Selection bit 2 position. */
#define EVSYS_SYNCCH13_bm  (1<<3)  /* Synchronous Channel 1 Generator Selection bit 3 mask. */
#define EVSYS_SYNCCH13_bp  3  /* Synchronous Channel 1 Generator Selection bit 3 position. */
#define EVSYS_SYNCCH14_bm  (1<<4)  /* Synchronous Channel 1 Generator Selection bit 4 mask. */
#define EVSYS_SYNCCH14_bp  4  /* Synchronous Channel 1 Generator Selection bit 4 position. */
#define EVSYS_SYNCCH15_bm  (1<<5)  /* Synchronous Channel 1 Generator Selection bit 5 mask. */
#define EVSYS_SYNCCH15_bp  5  /* Synchronous Channel 1 Generator Selection bit 5 position. */
#define EVSYS_SYNCCH16_bm  (1<<6)  /* Synchronous Channel 1 Generator Selection bit 6 mask. */
#define EVSYS_SYNCCH16_bp  6  /* Synchronous Channel 1 Generator Selection bit 6 position. */
#define EVSYS_SYNCCH17_bm  (1<<7)  /* Synchronous Channel 1 Generator Selection bit 7 mask. */
#define EVSYS_SYNCCH17_bp  7  /* Synchronous Channel 1 Generator Selection bit 7 position. */

/* EVSYS.ASYNCUSER0  bit masks and bit positions */
#define EVSYS_ASYNCUSER0_gm  0xFF  /* Asynchronous User Ch 0 Input Selection - TCB0 group mask. */
#define EVSYS_ASYNCUSER0_gp  0  /* Asynchronous User Ch 0 Input Selection - TCB0 group position. */
#define EVSYS_ASYNCUSER00_bm  (1<<0)  /* Asynchronous User Ch 0 Input Selection - TCB0 bit 0 mask. */
#define EVSYS_ASYNCUSER00_bp  0  /* Asynchronous User Ch 0 Input Selection - TCB0 bit 0 position. */
#define EVSYS_ASYNCUSER01_bm  (1<<1)  /* Asynchronous User Ch 0 Input Selection - TCB0 bit 1 mask. */
#define EVSYS_ASYNCUSER01_bp  1  /* Asynchronous User Ch 0 Input Selection - TCB0 bit 1 position. */
#define EVSYS_ASYNCUSER02_bm  (1<<2)  /* Asynchronous User Ch 0 Input Selection - TCB0 bit 2 mask. */
#define EVSYS_ASYNCUSER02_bp  2  /* Asynchronous User Ch 0 Input Selection - TCB0 bit 2 position. */
#define EVSYS_ASYNCUSER03_bm  (1<<3)  /* Asynchronous User Ch 0 Input Selection - TCB0 bit 3 mask. */
#define EVSYS_ASYNCUSER03_bp  3  /* Asynchronous User Ch 0 Input Selection - TCB0 bit 3 position. */
#define EVSYS_ASYNCUSER04_bm  (1<<4)  /* Asynchronous User Ch 0 Input Selection - TCB0 bit 4 mask. */
#define EVSYS_ASYNCUSER04_bp  4  /* Asynchronous User Ch 0 Input Selection - TCB0 bit 4 position. */
#define EVSYS_ASYNCUSER05_bm  (1<<5)  /* Asynchronous User Ch 0 Input Selection - TCB0 bit 5 mask. */
#define EVSYS_ASYNCUSER05_bp  5  /* Asynchronous User Ch 0 Input Selection - TCB0 bit 5 position. */
#define EVSYS_ASYNCUSER06_bm  (1<<6)  /* Asynchronous User Ch 0 Input Selection - TCB0 bit 6 mask. */
#define EVSYS_ASYNCUSER06_bp  6  /* Asynchronous User Ch 0 Input Selection - TCB0 bit 6 position. */
#define EVSYS_ASYNCUSER07_bm  (1<<7)  /* Asynchronous User Ch 0 Input Selection - TCB0 bit 7 mask. */
#define EVSYS_ASYNCUSER07_bp  7  /* Asynchronous User Ch 0 Input Selection - TCB0 bit 7 position. */

/* EVSYS.ASYNCUSER1  bit masks and bit positions */
#define EVSYS_ASYNCUSER1_gm  0xFF  /* Asynchronous User Ch 1 Input Selection - ADC0 group mask. */
#define EVSYS_ASYNCUSER1_gp  0  /* Asynchronous User Ch 1 Input Selection - ADC0 group position. */
#define EVSYS_ASYNCUSER10_bm  (1<<0)  /* Asynchronous User Ch 1 Input Selection - ADC0 bit 0 mask. */
#define EVSYS_ASYNCUSER10_bp  0  /* Asynchronous User Ch 1 Input Selection - ADC0 bit 0 position. */
#define EVSYS_ASYNCUSER11_bm  (1<<1)  /* Asynchronous User Ch 1 Input Selection - ADC0 bit 1 mask. */
#define EVSYS_ASYNCUSER11_bp  1  /* Asynchronous User Ch 1 Input Selection - ADC0 bit 1 position. */
#define EVSYS_ASYNCUSER12_bm  (1<<2)  /* Asynchronous User Ch 1 Input Selection - ADC0 bit 2 mask. */
#define EVSYS_ASYNCUSER12_bp  2  /* Asynchronous User Ch 1 Input Selection - ADC0 bit 2 position. */
#define EVSYS_ASYNCUSER13_bm  (1<<3)  /* Asynchronous User Ch 1 Input Selection - ADC0 bit 3 mask. */
#define EVSYS_ASYNCUSER13_bp  3  /* Asynchronous User Ch 1 Input Selection - ADC0 bit 3 position. */
#define EVSYS_ASYNCUSER14_bm  (1<<4)  /* Asynchronous User Ch 1 Input Selection - ADC0 bit 4 mask. */
#define EVSYS_ASYNCUSER14_bp  4  /* Asynchronous User Ch 1 Input Selection - ADC0 bit 4 position. */
#define EVSYS_ASYNCUSER15_bm  (1<<5)  /* Asynchronous User Ch 1 Input Selection - ADC0 bit 5 mask. */
#define EVSYS_ASYNCUSER15_bp  5  /* Asynchronous User Ch 1 Input Selection - ADC0 bit 5 position. */
#define EVSYS_ASYNCUSER16_bm  (1<<6)  /* Asynchronous User Ch 1 Input Selection - ADC0 bit 6 mask. */
#define EVSYS_ASYNCUSER16_bp  6  /* Asynchronous User Ch 1 Input Selection - ADC0 bit 6 position. */
#define EVSYS_ASYNCUSER17_bm  (1<<7)  /* Asynchronous User Ch 1 Input Selection - ADC0 bit 7 mask. */
#define EVSYS_ASYNCUSER17_bp  7  /* Asynchronous User Ch 1 Input Selection - ADC0 bit 7 position. */

/* EVSYS.ASYNCUSER2  bit masks and bit positions */
#define EVSYS_ASYNCUSER2_gm  0xFF  /* Asynchronous User Ch 2 Input Selection - CCL LUT0 Event 0 group mask. */
#define EVSYS_ASYNCUSER2_gp  0  /* Asynchronous User Ch 2 Input Selection - CCL LUT0 Event 0 group position. */
#define EVSYS_ASYNCUSER20_bm  (1<<0)  /* Asynchronous User Ch 2 Input Selection - CCL LUT0 Event 0 bit 0 mask. */
#define EVSYS_ASYNCUSER20_bp  0  /* Asynchronous User Ch 2 Input Selection - CCL LUT0 Event 0 bit 0 position. */
#define EVSYS_ASYNCUSER21_bm  (1<<1)  /* Asynchronous User Ch 2 Input Selection - CCL LUT0 Event 0 bit 1 mask. */
#define EVSYS_ASYNCUSER21_bp  1  /* Asynchronous User Ch 2 Input Selection - CCL LUT0 Event 0 bit 1 position. */
#define EVSYS_ASYNCUSER22_bm  (1<<2)  /* Asynchronous User Ch 2 Input Selection - CCL LUT0 Event 0 bit 2 mask. */
#define EVSYS_ASYNCUSER22_bp  2  /* Asynchronous User Ch 2 Input Selection - CCL LUT0 Event 0 bit 2 position. */
#define EVSYS_ASYNCUSER23_bm  (1<<3)  /* Asynchronous User Ch 2 Input Selection - CCL LUT0 Event 0 bit 3 mask. */
#define EVSYS_ASYNCUSER23_bp  3  /* Asynchronous User Ch 2 Input Selection - CCL LUT0 Event 0 bit 3 position. */
#define EVSYS_ASYNCUSER24_bm  (1<<4)  /* Asynchronous User Ch 2 Input Selection - CCL LUT0 Event 0 bit 4 mask. */
#define EVSYS_ASYNCUSER24_bp  4  /* Asynchronous User Ch 2 Input Selection - CCL LUT0 Event 0 bit 4 position. */
#define EVSYS_ASYNCUSER25_bm  (1<<5)  /* Asynchronous User Ch 2 Input Selection - CCL LUT0 Event 0 bit 5 mask. */
#define EVSYS_ASYNCUSER25_bp  5  /* Asynchronous User Ch 2 Input Selection - CCL LUT0 Event 0 bit 5 position. */
#define EVSYS_ASYNCUSER26_bm  (1<<6)  /* Asynchronous User Ch 2 Input Selection - CCL LUT0 Event 0 bit 6 mask. */
#define EVSYS_ASYNCUSER26_bp  6  /* Asynchronous User Ch 2 Input Selection - CCL LUT0 Event 0 bit 6 position. */
#define EVSYS_ASYNCUSER27_bm  (1<<7)  /* Asynchronous User Ch 2 Input Selection - CCL LUT0 Event 0 bit 7 mask. */
#define EVSYS_ASYNCUSER27_bp  7  /* Asynchronous User Ch 2 Input Selection - CCL LUT0 Event 0 bit 7 position. */

/* EVSYS.ASYNCUSER3  bit masks and bit positions */
#define EVSYS_ASYNCUSER3_gm  0xFF  /* Asynchronous User Ch 3 Input Selection - CCL LUT1 Event 0 group mask. */
#define EVSYS_ASYNCUSER3_gp  0  /* Asynchronous User Ch 3 Input Selection - CCL LUT1 Event 0 group position. */
#define EVSYS_ASYNCUSER30_bm  (1<<0)  /* Asynchronous User Ch 3 Input Selection - CCL LUT1 Event 0 bit 0 mask. */
#define EVSYS_ASYNCUSER30_bp  0  /* Asynchronous User Ch 3 Input Selection - CCL LUT1 Event 0 bit 0 position. */
#define EVSYS_ASYNCUSER31_bm  (1<<1)  /* Asynchronous User Ch 3 Input Selection - CCL LUT1 Event 0 bit 1 mask. */
#define EVSYS_ASYNCUSER31_bp  1  /* Asynchronous User Ch 3 Input Selection - CCL LUT1 Event 0 bit 1 position. */
#define EVSYS_ASYNCUSER32_bm  (1<<2)  /* Asynchronous User Ch 3 Input Selection - CCL LUT1 Event 0 bit 2 mask. */
#define EVSYS_ASYNCUSER32_bp  2  /* Asynchronous User Ch 3 Input Selection - CCL LUT1 Event 0 bit 2 position. */
#define EVSYS_ASYNCUSER33_bm  (1<<3)  /* Asynchronous User Ch 3 Input Selection - CCL LUT1 Event 0 bit 3 mask. */
#define EVSYS_ASYNCUSER33_bp  3  /* Asynchronous User Ch 3 Input Selection - CCL LUT1 Event 0 bit 3 position. */
#define EVSYS_ASYNCUSER34_bm  (1<<4)  /* Asynchronous User Ch 3 Input Selection - CCL LUT1 Event 0 bit 4 mask. */
#define EVSYS_ASYNCUSER34_bp  4  /* Asynchronous User Ch 3 Input Selection - CCL LUT1 Event 0 bit 4 position. */
#define EVSYS_ASYNCUSER35_bm  (1<<5)  /* Asynchronous User Ch 3 Input Selection - CCL LUT1 Event 0 bit 5 mask. */
#define EVSYS_ASYNCUSER35_bp  5  /* Asynchronous User Ch 3 Input Selection - CCL LUT1 Event 0 bit 5 position. */
#define EVSYS_ASYNCUSER36_bm  (1<<6)  /* Asynchronous User Ch 3 Input Selection - CCL LUT1 Event 0 bit 6 mask. */
#define EVSYS_ASYNCUSER36_bp  6  /* Asynchronous User Ch 3 Input Selection - CCL LUT1 Event 0 bit 6 position. */
#define EVSYS_ASYNCUSER37_bm  (1<<7)  /* Asynchronous User Ch 3 Input Selection - CCL LUT1 Event 0 bit 7 mask. */
#define EVSYS_ASYNCUSER37_bp  7  /* Asynchronous User Ch 3 Input Selection - CCL LUT1 Event 0 bit 7 position. */

/* EVSYS.ASYNCUSER4  bit masks and bit positions */
#define EVSYS_ASYNCUSER4_gm  0xFF  /* Asynchronous User Ch 4 Input Selection - CCL LUT0 Event 1 group mask. */
#define EVSYS_ASYNCUSER4_gp  0  /* Asynchronous User Ch 4 Input Selection - CCL LUT0 Event 1 group position. */
#define EVSYS_ASYNCUSER40_bm  (1<<0)  /* Asynchronous User Ch 4 Input Selection - CCL LUT0 Event 1 bit 0 mask. */
#define EVSYS_ASYNCUSER40_bp  0  /* Asynchronous User Ch 4 Input Selection - CCL LUT0 Event 1 bit 0 position. */
#define EVSYS_ASYNCUSER41_bm  (1<<1)  /* Asynchronous User Ch 4 Input Selection - CCL LUT0 Event 1 bit 1 mask. */
#define EVSYS_ASYNCUSER41_bp  1  /* Asynchronous User Ch 4 Input Selection - CCL LUT0 Event 1 bit 1 position. */
#define EVSYS_ASYNCUSER42_bm  (1<<2)  /* Asynchronous User Ch 4 Input Selection - CCL LUT0 Event 1 bit 2 mask. */
#define EVSYS_ASYNCUSER42_bp  2  /* Asynchronous User Ch 4 Input Selection - CCL LUT0 Event 1 bit 2 position. */
#define EVSYS_ASYNCUSER43_bm  (1<<3)  /* Asynchronous User Ch 4 Input Selection - CCL LUT0 Event 1 bit 3 mask. */
#define EVSYS_ASYNCUSER43_bp  3  /* Asynchronous User Ch 4 Input Selection - CCL LUT0 Event 1 bit 3 position. */
#define EVSYS_ASYNCUSER44_bm  (1<<4)  /* Asynchronous User Ch 4 Input Selection - CCL LUT0 Event 1 bit 4 mask. */
#define EVSYS_ASYNCUSER44_bp  4  /* Asynchronous User Ch 4 Input Selection - CCL LUT0 Event 1 bit 4 position. */
#define EVSYS_ASYNCUSER45_bm  (1<<5)  /* Asynchronous User Ch 4 Input Selection - CCL LUT0 Event 1 bit 5 mask. */
#define EVSYS_ASYNCUSER45_bp  5  /* Asynchronous User Ch 4 Input Selection - CCL LUT0 Event 1 bit 5 position. */
#define EVSYS_ASYNCUSER46_bm  (1<<6)  /* Asynchronous User Ch 4 Input Selection - CCL LUT0 Event 1 bit 6 mask. */
#define EVSYS_ASYNCUSER46_bp  6  /* Asynchronous User Ch 4 Input Selection - CCL LUT0 Event 1 bit 6 position. */
#define EVSYS_ASYNCUSER47_bm  (1<<7)  /* Asynchronous User Ch 4 Input Selection - CCL LUT0 Event 1 bit 7 mask. */
#define EVSYS_ASYNCUSER47_bp  7  /* Asynchronous User Ch 4 Input Selection - CCL LUT0 Event 1 bit 7 position. */

/* EVSYS.ASYNCUSER5  bit masks and bit positions */
#define EVSYS_ASYNCUSER5_gm  0xFF  /* Asynchronous User Ch 5 Input Selection - CCL LUT1 Event 1 group mask. */
#define EVSYS_ASYNCUSER5_gp  0  /* Asynchronous User Ch 5 Input Selection - CCL LUT1 Event 1 group position. */
#define EVSYS_ASYNCUSER50_bm  (1<<0)  /* Asynchronous User Ch 5 Input Selection - CCL LUT1 Event 1 bit 0 mask. */
#define EVSYS_ASYNCUSER50_bp  0  /* Asynchronous User Ch 5 Input Selection - CCL LUT1 Event 1 bit 0 position. */
#define EVSYS_ASYNCUSER51_bm  (1<<1)  /* Asynchronous User Ch 5 Input Selection - CCL LUT1 Event 1 bit 1 mask. */
#define EVSYS_ASYNCUSER51_bp  1  /* Asynchronous User Ch 5 Input Selection - CCL LUT1 Event 1 bit 1 position. */
#define EVSYS_ASYNCUSER52_bm  (1<<2)  /* Asynchronous User Ch 5 Input Selection - CCL LUT1 Event 1 bit 2 mask. */
#define EVSYS_ASYNCUSER52_bp  2  /* Asynchronous User Ch 5 Input Selection - CCL LUT1 Event 1 bit 2 position. */
#define EVSYS_ASYNCUSER53_bm  (1<<3)  /* Asynchronous User Ch 5 Input Selection - CCL LUT1 Event 1 bit 3 mask. */
#define EVSYS_ASYNCUSER53_bp  3  /* Asynchronous User Ch 5 Input Selection - CCL LUT1 Event 1 bit 3 position. */
#define EVSYS_ASYNCUSER54_bm  (1<<4)  /* Asynchronous User Ch 5 Input Selection - CCL LUT1 Event 1 bit 4 mask. */
#define EVSYS_ASYNCUSER54_bp  4  /* Asynchronous User Ch 5 Input Selection - CCL LUT1 Event 1 bit 4 position. */
#define EVSYS_ASYNCUSER55_bm  (1<<5)  /* Asynchronous User Ch 5 Input Selection - CCL LUT1 Event 1 bit 5 mask. */
#define EVSYS_ASYNCUSER55_bp  5  /* Asynchronous User Ch 5 Input Selection - CCL LUT1 Event 1 bit 5 position. */
#define EVSYS_ASYNCUSER56_bm  (1<<6)  /* Asynchronous User Ch 5 Input Selection - CCL LUT1 Event 1 bit 6 mask. */
#define EVSYS_ASYNCUSER56_bp  6  /* Asynchronous User Ch 5 Input Selection - CCL LUT1 Event 1 bit 6 position. */
#define EVSYS_ASYNCUSER57_bm  (1<<7)  /* Asynchronous User Ch 5 Input Selection - CCL LUT1 Event 1 bit 7 mask. */
#define EVSYS_ASYNCUSER57_bp  7  /* Asynchronous User Ch 5 Input Selection - CCL LUT1 Event 1 bit 7 position. */

/* EVSYS.ASYNCUSER6  bit masks and bit positions */
#define EVSYS_ASYNCUSER6_gm  0xFF  /* Asynchronous User Ch 6 Input Selection - TCD0 Event 0 group mask. */
#define EVSYS_ASYNCUSER6_gp  0  /* Asynchronous User Ch 6 Input Selection - TCD0 Event 0 group position. */
#define EVSYS_ASYNCUSER60_bm  (1<<0)  /* Asynchronous User Ch 6 Input Selection - TCD0 Event 0 bit 0 mask. */
#define EVSYS_ASYNCUSER60_bp  0  /* Asynchronous User Ch 6 Input Selection - TCD0 Event 0 bit 0 position. */
#define EVSYS_ASYNCUSER61_bm  (1<<1)  /* Asynchronous User Ch 6 Input Selection - TCD0 Event 0 bit 1 mask. */
#define EVSYS_ASYNCUSER61_bp  1  /* Asynchronous User Ch 6 Input Selection - TCD0 Event 0 bit 1 position. */
#define EVSYS_ASYNCUSER62_bm  (1<<2)  /* Asynchronous User Ch 6 Input Selection - TCD0 Event 0 bit 2 mask. */
#define EVSYS_ASYNCUSER62_bp  2  /* Asynchronous User Ch 6 Input Selection - TCD0 Event 0 bit 2 position. */
#define EVSYS_ASYNCUSER63_bm  (1<<3)  /* Asynchronous User Ch 6 Input Selection - TCD0 Event 0 bit 3 mask. */
#define EVSYS_ASYNCUSER63_bp  3  /* Asynchronous User Ch 6 Input Selection - TCD0 Event 0 bit 3 position. */
#define EVSYS_ASYNCUSER64_bm  (1<<4)  /* Asynchronous User Ch 6 Input Selection - TCD0 Event 0 bit 4 mask. */
#define EVSYS_ASYNCUSER64_bp  4  /* Asynchronous User Ch 6 Input Selection - TCD0 Event 0 bit 4 position. */
#define EVSYS_ASYNCUSER65_bm  (1<<5)  /* Asynchronous User Ch 6 Input Selection - TCD0 Event 0 bit 5 mask. */
#define EVSYS_ASYNCUSER65_bp  5  /* Asynchronous User Ch 6 Input Selection - TCD0 Event 0 bit 5 position. */
#define EVSYS_ASYNCUSER66_bm  (1<<6)  /* Asynchronous User Ch 6 Input Selection - TCD0 Event 0 bit 6 mask. */
#define EVSYS_ASYNCUSER66_bp  6  /* Asynchronous User Ch 6 Input Selection - TCD0 Event 0 bit 6 position. */
#define EVSYS_ASYNCUSER67_bm  (1<<7)  /* Asynchronous User Ch 6 Input Selection - TCD0 Event 0 bit 7 mask. */
#define EVSYS_ASYNCUSER67_bp  7  /* Asynchronous User Ch 6 Input Selection - TCD0 Event 0 bit 7 position. */

/* EVSYS.ASYNCUSER7  bit masks and bit positions */
#define EVSYS_ASYNCUSER7_gm  0xFF  /* Asynchronous User Ch 7 Input Selection - TCD0 Event 1 group mask. */
#define EVSYS_ASYNCUSER7_gp  0  /* Asynchronous User Ch 7 Input Selection - TCD0 Event 1 group position. */
#define EVSYS_ASYNCUSER70_bm  (1<<0)  /* Asynchronous User Ch 7 Input Selection - TCD0 Event 1 bit 0 mask. */
#define EVSYS_ASYNCUSER70_bp  0  /* Asynchronous User Ch 7 Input Selection - TCD0 Event 1 bit 0 position. */
#define EVSYS_ASYNCUSER71_bm  (1<<1)  /* Asynchronous User Ch 7 Input Selection - TCD0 Event 1 bit 1 mask. */
#define EVSYS_ASYNCUSER71_bp  1  /* Asynchronous User Ch 7 Input Selection - TCD0 Event 1 bit 1 position. */
#define EVSYS_ASYNCUSER72_bm  (1<<2)  /* Asynchronous User Ch 7 Input Selection - TCD0 Event 1 bit 2 mask. */
#define EVSYS_ASYNCUSER72_bp  2  /* Asynchronous User Ch 7 Input Selection - TCD0 Event 1 bit 2 position. */
#define EVSYS_ASYNCUSER73_bm  (1<<3)  /* Asynchronous User Ch 7 Input Selection - TCD0 Event 1 bit 3 mask. */
#define EVSYS_ASYNCUSER73_bp  3  /* Asynchronous User Ch 7 Input Selection - TCD0 Event 1 bit 3 position. */
#define EVSYS_ASYNCUSER74_bm  (1<<4)  /* Asynchronous User Ch 7 Input Selection - TCD0 Event 1 bit 4 mask. */
#define EVSYS_ASYNCUSER74_bp  4  /* Asynchronous User Ch 7 Input Selection - TCD0 Event 1 bit 4 position. */
#define EVSYS_ASYNCUSER75_bm  (1<<5)  /* Asynchronous User Ch 7 Input Selection - TCD0 Event 1 bit 5 mask. */
#define EVSYS_ASYNCUSER75_bp  5  /* Asynchronous User Ch 7 Input Selection - TCD0 Event 1 bit 5 position. */
#define EVSYS_ASYNCUSER76_bm  (1<<6)  /* Asynchronous User Ch 7 Input Selection - TCD0 Event 1 bit 6 mask. */
#define EVSYS_ASYNCUSER76_bp  6  /* Asynchronous User Ch 7 Input Selection - TCD0 Event 1 bit 6 position. */
#define EVSYS_ASYNCUSER77_bm  (1<<7)  /* Asynchronous User Ch 7 Input Selection - TCD0 Event 1 bit 7 mask. */
#define EVSYS_ASYNCUSER77_bp  7  /* Asynchronous User Ch 7 Input Selection - TCD0 Event 1 bit 7 position. */

/* EVSYS.ASYNCUSER8  bit masks and bit positions */
#define EVSYS_ASYNCUSER8_gm  0xFF  /* Asynchronous User Ch 8 Input Selection - Event Out 0 group mask. */
#define EVSYS_ASYNCUSER8_gp  0  /* Asynchronous User Ch 8 Input Selection - Event Out 0 group position. */
#define EVSYS_ASYNCUSER80_bm  (1<<0)  /* Asynchronous User Ch 8 Input Selection - Event Out 0 bit 0 mask. */
#define EVSYS_ASYNCUSER80_bp  0  /* Asynchronous User Ch 8 Input Selection - Event Out 0 bit 0 position. */
#define EVSYS_ASYNCUSER81_bm  (1<<1)  /* Asynchronous User Ch 8 Input Selection - Event Out 0 bit 1 mask. */
#define EVSYS_ASYNCUSER81_bp  1  /* Asynchronous User Ch 8 Input Selection - Event Out 0 bit 1 position. */
#define EVSYS_ASYNCUSER82_bm  (1<<2)  /* Asynchronous User Ch 8 Input Selection - Event Out 0 bit 2 mask. */
#define EVSYS_ASYNCUSER82_bp  2  /* Asynchronous User Ch 8 Input Selection - Event Out 0 bit 2 position. */
#define EVSYS_ASYNCUSER83_bm  (1<<3)  /* Asynchronous User Ch 8 Input Selection - Event Out 0 bit 3 mask. */
#define EVSYS_ASYNCUSER83_bp  3  /* Asynchronous User Ch 8 Input Selection - Event Out 0 bit 3 position. */
#define EVSYS_ASYNCUSER84_bm  (1<<4)  /* Asynchronous User Ch 8 Input Selection - Event Out 0 bit 4 mask. */
#define EVSYS_ASYNCUSER84_bp  4  /* Asynchronous User Ch 8 Input Selection - Event Out 0 bit 4 position. */
#define EVSYS_ASYNCUSER85_bm  (1<<5)  /* Asynchronous User Ch 8 Input Selection - Event Out 0 bit 5 mask. */
#define EVSYS_ASYNCUSER85_bp  5  /* Asynchronous User Ch 8 Input Selection - Event Out 0 bit 5 position. */
#define EVSYS_ASYNCUSER86_bm  (1<<6)  /* Asynchronous User Ch 8 Input Selection - Event Out 0 bit 6 mask. */
#define EVSYS_ASYNCUSER86_bp  6  /* Asynchronous User Ch 8 Input Selection - Event Out 0 bit 6 position. */
#define EVSYS_ASYNCUSER87_bm  (1<<7)  /* Asynchronous User Ch 8 Input Selection - Event Out 0 bit 7 mask. */
#define EVSYS_ASYNCUSER87_bp  7  /* Asynchronous User Ch 8 Input Selection - Event Out 0 bit 7 position. */

/* EVSYS.ASYNCUSER9  bit masks and bit positions */
#define EVSYS_ASYNCUSER9_gm  0xFF  /* Asynchronous User Ch 9 Input Selection - Event Out 1 group mask. */
#define EVSYS_ASYNCUSER9_gp  0  /* Asynchronous User Ch 9 Input Selection - Event Out 1 group position. */
#define EVSYS_ASYNCUSER90_bm  (1<<0)  /* Asynchronous User Ch 9 Input Selection - Event Out 1 bit 0 mask. */
#define EVSYS_ASYNCUSER90_bp  0  /* Asynchronous User Ch 9 Input Selection - Event Out 1 bit 0 position. */
#define EVSYS_ASYNCUSER91_bm  (1<<1)  /* Asynchronous User Ch 9 Input Selection - Event Out 1 bit 1 mask. */
#define EVSYS_ASYNCUSER91_bp  1  /* Asynchronous User Ch 9 Input Selection - Event Out 1 bit 1 position. */
#define EVSYS_ASYNCUSER92_bm  (1<<2)  /* Asynchronous User Ch 9 Input Selection - Event Out 1 bit 2 mask. */
#define EVSYS_ASYNCUSER92_bp  2  /* Asynchronous User Ch 9 Input Selection - Event Out 1 bit 2 position. */
#define EVSYS_ASYNCUSER93_bm  (1<<3)  /* Asynchronous User Ch 9 Input Selection - Event Out 1 bit 3 mask. */
#define EVSYS_ASYNCUSER93_bp  3  /* Asynchronous User Ch 9 Input Selection - Event Out 1 bit 3 position. */
#define EVSYS_ASYNCUSER94_bm  (1<<4)  /* Asynchronous User Ch 9 Input Selection - Event Out 1 bit 4 mask. */
#define EVSYS_ASYNCUSER94_bp  4  /* Asynchronous User Ch 9 Input Selection - Event Out 1 bit 4 position. */
#define EVSYS_ASYNCUSER95_bm  (1<<5)  /* Asynchronous User Ch 9 Input Selection - Event Out 1 bit 5 mask. */
#define EVSYS_ASYNCUSER95_bp  5  /* Asynchronous User Ch 9 Input Selection - Event Out 1 bit 5 position. */
#define EVSYS_ASYNCUSER96_bm  (1<<6)  /* Asynchronous User Ch 9 Input Selection - Event Out 1 bit 6 mask. */
#define EVSYS_ASYNCUSER96_bp  6  /* Asynchronous User Ch 9 Input Selection - Event Out 1 bit 6 position. */
#define EVSYS_ASYNCUSER97_bm  (1<<7)  /* Asynchronous User Ch 9 Input Selection - Event Out 1 bit 7 mask. */
#define EVSYS_ASYNCUSER97_bp  7  /* Asynchronous User Ch 9 Input Selection - Event Out 1 bit 7 position. */

/* EVSYS.ASYNCUSER10  bit masks and bit positions */
#define EVSYS_ASYNCUSER10_gm  0xFF  /* Asynchronous User Ch 10 Input Selection - Event Out 2 group mask. */
#define EVSYS_ASYNCUSER10_gp  0  /* Asynchronous User Ch 10 Input Selection - Event Out 2 group position. */
#define EVSYS_ASYNCUSER100_bm  (1<<0)  /* Asynchronous User Ch 10 Input Selection - Event Out 2 bit 0 mask. */
#define EVSYS_ASYNCUSER100_bp  0  /* Asynchronous User Ch 10 Input Selection - Event Out 2 bit 0 position. */
#define EVSYS_ASYNCUSER101_bm  (1<<1)  /* Asynchronous User Ch 10 Input Selection - Event Out 2 bit 1 mask. */
#define EVSYS_ASYNCUSER101_bp  1  /* Asynchronous User Ch 10 Input Selection - Event Out 2 bit 1 position. */
#define EVSYS_ASYNCUSER102_bm  (1<<2)  /* Asynchronous User Ch 10 Input Selection - Event Out 2 bit 2 mask. */
#define EVSYS_ASYNCUSER102_bp  2  /* Asynchronous User Ch 10 Input Selection - Event Out 2 bit 2 position. */
#define EVSYS_ASYNCUSER103_bm  (1<<3)  /* Asynchronous User Ch 10 Input Selection - Event Out 2 bit 3 mask. */
#define EVSYS_ASYNCUSER103_bp  3  /* Asynchronous User Ch 10 Input Selection - Event Out 2 bit 3 position. */
#define EVSYS_ASYNCUSER104_bm  (1<<4)  /* Asynchronous User Ch 10 Input Selection - Event Out 2 bit 4 mask. */
#define EVSYS_ASYNCUSER104_bp  4  /* Asynchronous User Ch 10 Input Selection - Event Out 2 bit 4 position. */
#define EVSYS_ASYNCUSER105_bm  (1<<5)  /* Asynchronous User Ch 10 Input Selection - Event Out 2 bit 5 mask. */
#define EVSYS_ASYNCUSER105_bp  5  /* Asynchronous User Ch 10 Input Selection - Event Out 2 bit 5 position. */
#define EVSYS_ASYNCUSER106_bm  (1<<6)  /* Asynchronous User Ch 10 Input Selection - Event Out 2 bit 6 mask. */
#define EVSYS_ASYNCUSER106_bp  6  /* Asynchronous User Ch 10 Input Selection - Event Out 2 bit 6 position. */
#define EVSYS_ASYNCUSER107_bm  (1<<7)  /* Asynchronous User Ch 10 Input Selection - Event Out 2 bit 7 mask. */
#define EVSYS_ASYNCUSER107_bp  7  /* Asynchronous User Ch 10 Input Selection - Event Out 2 bit 7 position. */

/* EVSYS.SYNCUSER0  bit masks and bit positions */
#define EVSYS_SYNCUSER0_gm  0xFF  /* Synchronous User Ch 0 Input Selection - TCA0 group mask. */
#define EVSYS_SYNCUSER0_gp  0  /* Synchronous User Ch 0 Input Selection - TCA0 group position. */
#define EVSYS_SYNCUSER00_bm  (1<<0)  /* Synchronous User Ch 0 Input Selection - TCA0 bit 0 mask. */
#define EVSYS_SYNCUSER00_bp  0  /* Synchronous User Ch 0 Input Selection - TCA0 bit 0 position. */
#define EVSYS_SYNCUSER01_bm  (1<<1)  /* Synchronous User Ch 0 Input Selection - TCA0 bit 1 mask. */
#define EVSYS_SYNCUSER01_bp  1  /* Synchronous User Ch 0 Input Selection - TCA0 bit 1 position. */
#define EVSYS_SYNCUSER02_bm  (1<<2)  /* Synchronous User Ch 0 Input Selection - TCA0 bit 2 mask. */
#define EVSYS_SYNCUSER02_bp  2  /* Synchronous User Ch 0 Input Selection - TCA0 bit 2 position. */
#define EVSYS_SYNCUSER03_bm  (1<<3)  /* Synchronous User Ch 0 Input Selection - TCA0 bit 3 mask. */
#define EVSYS_SYNCUSER03_bp  3  /* Synchronous User Ch 0 Input Selection - TCA0 bit 3 position. */
#define EVSYS_SYNCUSER04_bm  (1<<4)  /* Synchronous User Ch 0 Input Selection - TCA0 bit 4 mask. */
#define EVSYS_SYNCUSER04_bp  4  /* Synchronous User Ch 0 Input Selection - TCA0 bit 4 position. */
#define EVSYS_SYNCUSER05_bm  (1<<5)  /* Synchronous User Ch 0 Input Selection - TCA0 bit 5 mask. */
#define EVSYS_SYNCUSER05_bp  5  /* Synchronous User Ch 0 Input Selection - TCA0 bit 5 position. */
#define EVSYS_SYNCUSER06_bm  (1<<6)  /* Synchronous User Ch 0 Input Selection - TCA0 bit 6 mask. */
#define EVSYS_SYNCUSER06_bp  6  /* Synchronous User Ch 0 Input Selection - TCA0 bit 6 position. */
#define EVSYS_SYNCUSER07_bm  (1<<7)  /* Synchronous User Ch 0 Input Selection - TCA0 bit 7 mask. */
#define EVSYS_SYNCUSER07_bp  7  /* Synchronous User Ch 0 Input Selection - TCA0 bit 7 position. */

/* EVSYS.SYNCUSER1  bit masks and bit positions */
#define EVSYS_SYNCUSER1_gm  0xFF  /* Synchronous User Ch 1 Input Selection - USART0 group mask. */
#define EVSYS_SYNCUSER1_gp  0  /* Synchronous User Ch 1 Input Selection - USART0 group position. */
#define EVSYS_SYNCUSER10_bm  (1<<0)  /* Synchronous User Ch 1 Input Selection - USART0 bit 0 mask. */
#define EVSYS_SYNCUSER10_bp  0  /* Synchronous User Ch 1 Input Selection - USART0 bit 0 position. */
#define EVSYS_SYNCUSER11_bm  (1<<1)  /* Synchronous User Ch 1 Input Selection - USART0 bit 1 mask. */
#define EVSYS_SYNCUSER11_bp  1  /* Synchronous User Ch 1 Input Selection - USART0 bit 1 position. */
#define EVSYS_SYNCUSER12_bm  (1<<2)  /* Synchronous User Ch 1 Input Selection - USART0 bit 2 mask. */
#define EVSYS_SYNCUSER12_bp  2  /* Synchronous User Ch 1 Input Selection - USART0 bit 2 position. */
#define EVSYS_SYNCUSER13_bm  (1<<3)  /* Synchronous User Ch 1 Input Selection - USART0 bit 3 mask. */
#define EVSYS_SYNCUSER13_bp  3  /* Synchronous User Ch 1 Input Selection - USART0 bit 3 position. */
#define EVSYS_SYNCUSER14_bm  (1<<4)  /* Synchronous User Ch 1 Input Selection - USART0 bit 4 mask. */
#define EVSYS_SYNCUSER14_bp  4  /* Synchronous User Ch 1 Input Selection - USART0 bit 4 position. */
#define EVSYS_SYNCUSER15_bm  (1<<5)  /* Synchronous User Ch 1 Input Selection - USART0 bit 5 mask. */
#define EVSYS_SYNCUSER15_bp  5  /* Synchronous User Ch 1 Input Selection - USART0 bit 5 position. */
#define EVSYS_SYNCUSER16_bm  (1<<6)  /* Synchronous User Ch 1 Input Selection - USART0 bit 6 mask. */
#define EVSYS_SYNCUSER16_bp  6  /* Synchronous User Ch 1 Input Selection - USART0 bit 6 position. */
#define EVSYS_SYNCUSER17_bm  (1<<7)  /* Synchronous User Ch 1 Input Selection - USART0 bit 7 mask. */
#define EVSYS_SYNCUSER17_bp  7  /* Synchronous User Ch 1 Input Selection - USART0 bit 7 position. */

/* FUSE - Fuses */
/* FUSE.WDTCFG  bit masks and bit positions */
#define FUSE_PERIOD_gm  0x0F  /* Watchdog Timeout Period group mask. */
#define FUSE_PERIOD_gp  0  /* Watchdog Timeout Period group position. */
#define FUSE_PERIOD0_bm  (1<<0)  /* Watchdog Timeout Period bit 0 mask. */
#define FUSE_PERIOD0_bp  0  /* Watchdog Timeout Period bit 0 position. */
#define FUSE_PERIOD1_bm  (1<<1)  /* Watchdog Timeout Period bit 1 mask. */
#define FUSE_PERIOD1_bp  1  /* Watchdog Timeout Period bit 1 position. */
#define FUSE_PERIOD2_bm  (1<<2)  /* Watchdog Timeout Period bit 2 mask. */
#define FUSE_PERIOD2_bp  2  /* Watchdog Timeout Period bit 2 position. */
#define FUSE_PERIOD3_bm  (1<<3)  /* Watchdog Timeout Period bit 3 mask. */
#define FUSE_PERIOD3_bp  3  /* Watchdog Timeout Period bit 3 position. */
#define FUSE_WINDOW_gm  0xF0  /* Watchdog Window Timeout Period group mask. */
#define FUSE_WINDOW_gp  4  /* Watchdog Window Timeout Period group position. */
#define FUSE_WINDOW0_bm  (1<<4)  /* Watchdog Window Timeout Period bit 0 mask. */
#define FUSE_WINDOW0_bp  4  /* Watchdog Window Timeout Period bit 0 position. */
#define FUSE_WINDOW1_bm  (1<<5)  /* Watchdog Window Timeout Period bit 1 mask. */
#define FUSE_WINDOW1_bp  5  /* Watchdog Window Timeout Period bit 1 position. */
#define FUSE_WINDOW2_bm  (1<<6)  /* Watchdog Window Timeout Period bit 2 mask. */
#define FUSE_WINDOW2_bp  6  /* Watchdog Window Timeout Period bit 2 position. */
#define FUSE_WINDOW3_bm  (1<<7)  /* Watchdog Window Timeout Period bit 3 mask. */
#define FUSE_WINDOW3_bp  7  /* Watchdog Window Timeout Period bit 3 position. */

/* FUSE.BODCFG  bit masks and bit positions */
#define FUSE_SLEEP_gm  0x03  /* BOD Operation in Sleep Mode group mask. */
#define FUSE_SLEEP_gp  0  /* BOD Operation in Sleep Mode group position. */
#define FUSE_SLEEP0_bm  (1<<0)  /* BOD Operation in Sleep Mode bit 0 mask. */
#define FUSE_SLEEP0_bp  0  /* BOD Operation in Sleep Mode bit 0 position. */
#define FUSE_SLEEP1_bm  (1<<1)  /* BOD Operation in Sleep Mode bit 1 mask. */
#define FUSE_SLEEP1_bp  1  /* BOD Operation in Sleep Mode bit 1 position. */
#define FUSE_ACTIVE_gm  0x0C  /* BOD Operation in Active Mode group mask. */
#define FUSE_ACTIVE_gp  2  /* BOD Operation in Active Mode group position. */
#define FUSE_ACTIVE0_bm  (1<<2)  /* BOD Operation in Active Mode bit 0 mask. */
#define FUSE_ACTIVE0_bp  2  /* BOD Operation in Active Mode bit 0 position. */
#define FUSE_ACTIVE1_bm  (1<<3)  /* BOD Operation in Active Mode bit 1 mask. */
#define FUSE_ACTIVE1_bp  3  /* BOD Operation in Active Mode bit 1 position. */
#define FUSE_SAMPFREQ_bm  0x10  /* BOD Sample Frequency bit mask. */
#define FUSE_SAMPFREQ_bp  4  /* BOD Sample Frequency bit position. */
#define FUSE_LVL_gm  0xE0  /* BOD Level group mask. */
#define FUSE_LVL_gp  5  /* BOD Level group position. */
#define FUSE_LVL0_bm  (1<<5)  /* BOD Level bit 0 mask. */
#define FUSE_LVL0_bp  5  /* BOD Level bit 0 position. */
#define FUSE_LVL1_bm  (1<<6)  /* BOD Level bit 1 mask. */
#define FUSE_LVL1_bp  6  /* BOD Level bit 1 position. */
#define FUSE_LVL2_bm  (1<<7)  /* BOD Level bit 2 mask. */
#define FUSE_LVL2_bp  7  /* BOD Level bit 2 position. */

/* FUSE.OSCCFG  bit masks and bit positions */
#define FUSE_FREQSEL_gm  0x03  /* Frequency Select group mask. */
#define FUSE_FREQSEL_gp  0  /* Frequency Select group position. */
#define FUSE_FREQSEL0_bm  (1<<0)  /* Frequency Select bit 0 mask. */
#define FUSE_FREQSEL0_bp  0  /* Frequency Select bit 0 position. */
#define FUSE_FREQSEL1_bm  (1<<1)  /* Frequency Select bit 1 mask. */
#define FUSE_FREQSEL1_bp  1  /* Frequency Select bit 1 position. */
#define FUSE_OSCLOCK_bm  0x80  /* Oscillator Lock bit mask. */
#define FUSE_OSCLOCK_bp  7  /* Oscillator Lock bit position. */

/* FUSE.TCD0CFG  bit masks and bit positions */
#define FUSE_CMPA_bm  0x01  /* Compare A Default Output Value bit mask. */
#define FUSE_CMPA_bp  0  /* Compare A Default Output Value bit position. */
#define FUSE_CMPB_bm  0x02  /* Compare B Default Output Value bit mask. */
#define FUSE_CMPB_bp  1  /* Compare B Default Output Value bit position. */
#define FUSE_CMPC_bm  0x04  /* Compare C Default Output Value bit mask. */
#define FUSE_CMPC_bp  2  /* Compare C Default Output Value bit position. */
#define FUSE_CMPD_bm  0x08  /* Compare D Default Output Value bit mask. */
#define FUSE_CMPD_bp  3  /* Compare D Default Output Value bit position. */
#define FUSE_CMPAEN_bm  0x10  /* Compare A Output Enable bit mask. */
#define FUSE_CMPAEN_bp  4  /* Compare A Output Enable bit position. */
#define FUSE_CMPBEN_bm  0x20  /* Compare B Output Enable bit mask. */
#define FUSE_CMPBEN_bp  5  /* Compare B Output Enable bit position. */
#define FUSE_CMPCEN_bm  0x40  /* Compare C Output Enable bit mask. */
#define FUSE_CMPCEN_bp  6  /* Compare C Output Enable bit position. */
#define FUSE_CMPDEN_bm  0x80  /* Compare D Output Enable bit mask. */
#define FUSE_CMPDEN_bp  7  /* Compare D Output Enable bit position. */

/* FUSE.SYSCFG0  bit masks and bit positions */
#define FUSE_EESAVE_bm  0x01  /* EEPROM Save bit mask. */
#define FUSE_EESAVE_bp  0  /* EEPROM Save bit position. */
#define FUSE_RSTPINCFG_gm  0x0C  /* Reset Pin Configuration group mask. */
#define FUSE_RSTPINCFG_gp  2  /* Reset Pin Configuration group position. */
#define FUSE_RSTPINCFG0_bm  (1<<2)  /* Reset Pin Configuration bit 0 mask. */
#define FUSE_RSTPINCFG0_bp  2  /* Reset Pin Configuration bit 0 position. */
#define FUSE_RSTPINCFG1_bm  (1<<3)  /* Reset Pin Configuration bit 1 mask. */
#define FUSE_RSTPINCFG1_bp  3  /* Reset Pin Configuration bit 1 position. */
#define FUSE_CRCSRC_gm  0xC0  /* CRC Source group mask. */
#define FUSE_CRCSRC_gp  6  /* CRC Source group position. */
#define FUSE_CRCSRC0_bm  (1<<6)  /* CRC Source bit 0 mask. */
#define FUSE_CRCSRC0_bp  6  /* CRC Source bit 0 position. */
#define FUSE_CRCSRC1_bm  (1<<7)  /* CRC Source bit 1 mask. */
#define FUSE_CRCSRC1_bp  7  /* CRC Source bit 1 position. */

/* FUSE.SYSCFG1  bit masks and bit positions */
#define FUSE_SUT_gm  0x07  /* Startup Time group mask. */
#define FUSE_SUT_gp  0  /* Startup Time group position. */
#define FUSE_SUT0_bm  (1<<0)  /* Startup Time bit 0 mask. */
#define FUSE_SUT0_bp  0  /* Startup Time bit 0 position. */
#define FUSE_SUT1_bm  (1<<1)  /* Startup Time bit 1 mask. */
#define FUSE_SUT1_bp  1  /* Startup Time bit 1 position. */
#define FUSE_SUT2_bm  (1<<2)  /* Startup Time bit 2 mask. */
#define FUSE_SUT2_bp  2  /* Startup Time bit 2 position. */







/* LOCKBIT - Lockbit */
/* LOCKBIT.LOCKBIT  bit masks and bit positions */
#define LOCKBIT_LB_gm  0xFF  /* Lock Bits group mask. */
#define LOCKBIT_LB_gp  0  /* Lock Bits group position. */
#define LOCKBIT_LB0_bm  (1<<0)  /* Lock Bits bit 0 mask. */
#define LOCKBIT_LB0_bp  0  /* Lock Bits bit 0 position. */
#define LOCKBIT_LB1_bm  (1<<1)  /* Lock Bits bit 1 mask. */
#define LOCKBIT_LB1_bp  1  /* Lock Bits bit 1 position. */
#define LOCKBIT_LB2_bm  (1<<2)  /* Lock Bits bit 2 mask. */
#define LOCKBIT_LB2_bp  2  /* Lock Bits bit 2 position. */
#define LOCKBIT_LB3_bm  (1<<3)  /* Lock Bits bit 3 mask. */
#define LOCKBIT_LB3_bp  3  /* Lock Bits bit 3 position. */
#define LOCKBIT_LB4_bm  (1<<4)  /* Lock Bits bit 4 mask. */
#define LOCKBIT_LB4_bp  4  /* Lock Bits bit 4 position. */
#define LOCKBIT_LB5_bm  (1<<5)  /* Lock Bits bit 5 mask. */
#define LOCKBIT_LB5_bp  5  /* Lock Bits bit 5 position. */
#define LOCKBIT_LB6_bm  (1<<6)  /* Lock Bits bit 6 mask. */
#define LOCKBIT_LB6_bp  6  /* Lock Bits bit 6 position. */
#define LOCKBIT_LB7_bm  (1<<7)  /* Lock Bits bit 7 mask. */
#define LOCKBIT_LB7_bp  7  /* Lock Bits bit 7 position. */

/* NVMCTRL - Non-volatile Memory Controller */
/* NVMCTRL.CTRLA  bit masks and bit positions */
#define NVMCTRL_CMD_gm  0x07  /* Command group mask. */
#define NVMCTRL_CMD_gp  0  /* Command group position. */
#define NVMCTRL_CMD0_bm  (1<<0)  /* Command bit 0 mask. */
#define NVMCTRL_CMD0_bp  0  /* Command bit 0 position. */
#define NVMCTRL_CMD1_bm  (1<<1)  /* Command bit 1 mask. */
#define NVMCTRL_CMD1_bp  1  /* Command bit 1 position. */
#define NVMCTRL_CMD2_bm  (1<<2)  /* Command bit 2 mask. */
#define NVMCTRL_CMD2_bp  2  /* Command bit 2 position. */

/* NVMCTRL.CTRLB  bit masks and bit positions */
#define NVMCTRL_APCWP_bm  0x01  /* Application code write protect bit mask. */
#define NVMCTRL_APCWP_bp  0  /* Application code write protect bit position. */
#define NVMCTRL_BOOTLOCK_bm  0x02  /* Boot Lock bit mask. */
#define NVMCTRL_BOOTLOCK_bp  1  /* Boot Lock bit position. */

/* NVMCTRL.STATUS  bit masks and bit positions */
#define NVMCTRL_FBUSY_bm  0x01  /* Flash busy bit mask. */
#define NVMCTRL_FBUSY_bp  0  /* Flash busy bit position. */
#define NVMCTRL_EEBUSY_bm  0x02  /* EEPROM busy bit mask. */
#define NVMCTRL_EEBUSY_bp  1  /* EEPROM busy bit position. */
#define NVMCTRL_WRERROR_bm  0x04  /* Write error bit mask. */
#define NVMCTRL_WRERROR_bp  2  /* Write error bit position. */

/* NVMCTRL.INTCTRL  bit masks and bit positions */
#define NVMCTRL_EEREADY_bm  0x01  /* EEPROM Ready bit mask. */
#define NVMCTRL_EEREADY_bp  0  /* EEPROM Ready bit position. */

/* NVMCTRL.INTFLAGS  bit masks and bit positions */
/* NVMCTRL_EEREADY  is already defined. */












/* PORT - I/O Ports */
/* PORT.INTFLAGS  bit masks and bit positions */
#define PORT_INT_gm  0xFF  /* Pin Interrupt group mask. */
#define PORT_INT_gp  0  /* Pin Interrupt group position. */
#define PORT_INT0_bm  (1<<0)  /* Pin Interrupt bit 0 mask. */
#define PORT_INT0_bp  0  /* Pin Interrupt bit 0 position. */
#define PORT_INT1_bm  (1<<1)  /* Pin Interrupt bit 1 mask. */
#define PORT_INT1_bp  1  /* Pin Interrupt bit 1 position. */
#define PORT_INT2_bm  (1<<2)  /* Pin Interrupt bit 2 mask. */
#define PORT_INT2_bp  2  /* Pin Interrupt bit 2 position. */
#define PORT_INT3_bm  (1<<3)  /* Pin Interrupt bit 3 mask. */
#define PORT_INT3_bp  3  /* Pin Interrupt bit 3 position. */
#define PORT_INT4_bm  (1<<4)  /* Pin Interrupt bit 4 mask. */
#define PORT_INT4_bp  4  /* Pin Interrupt bit 4 position. */
#define PORT_INT5_bm  (1<<5)  /* Pin Interrupt bit 5 mask. */
#define PORT_INT5_bp  5  /* Pin Interrupt bit 5 position. */
#define PORT_INT6_bm  (1<<6)  /* Pin Interrupt bit 6 mask. */
#define PORT_INT6_bp  6  /* Pin Interrupt bit 6 position. */
#define PORT_INT7_bm  (1<<7)  /* Pin Interrupt bit 7 mask. */
#define PORT_INT7_bp  7  /* Pin Interrupt bit 7 position. */

/* PORT.PIN0CTRL  bit masks and bit positions */
#define PORT_ISC_gm  0x07  /* Input/Sense Configuration group mask. */
#define PORT_ISC_gp  0  /* Input/Sense Configuration group position. */
#define PORT_ISC0_bm  (1<<0)  /* Input/Sense Configuration bit 0 mask. */
#define PORT_ISC0_bp  0  /* Input/Sense Configuration bit 0 position. */
#define PORT_ISC1_bm  (1<<1)  /* Input/Sense Configuration bit 1 mask. */
#define PORT_ISC1_bp  1  /* Input/Sense Configuration bit 1 position. */
#define PORT_ISC2_bm  (1<<2)  /* Input/Sense Configuration bit 2 mask. */
#define PORT_ISC2_bp  2  /* Input/Sense Configuration bit 2 position. */
#define PORT_PULLUPEN_bm  0x08  /* Pullup enable bit mask. */
#define PORT_PULLUPEN_bp  3  /* Pullup enable bit position. */
#define PORT_INVEN_bm  0x80  /* Inverted I/O Enable bit mask. */
#define PORT_INVEN_bp  7  /* Inverted I/O Enable bit position. */

/* PORT.PIN1CTRL  bit masks and bit positions */
/* PORT_ISC  is already defined. */
/* PORT_PULLUPEN  is already defined. */
/* PORT_INVEN  is already defined. */

/* PORT.PIN2CTRL  bit masks and bit positions */
/* PORT_ISC  is already defined. */
/* PORT_PULLUPEN  is already defined. */
/* PORT_INVEN  is already defined. */

/* PORT.PIN3CTRL  bit masks and bit positions */
/* PORT_ISC  is already defined. */
/* PORT_PULLUPEN  is already defined. */
/* PORT_INVEN  is already defined. */

/* PORT.PIN4CTRL  bit masks and bit positions */
/* PORT_ISC  is already defined. */
/* PORT_PULLUPEN  is already defined. */
/* PORT_INVEN  is already defined. */

/* PORT.PIN5CTRL  bit masks and bit positions */
/* PORT_ISC  is already defined. */
/* PORT_PULLUPEN  is already defined. */
/* PORT_INVEN  is already defined. */

/* PORT.PIN6CTRL  bit masks and bit positions */
/* PORT_ISC  is already defined. */
/* PORT_PULLUPEN  is already defined. */
/* PORT_INVEN  is already defined. */

/* PORT.PIN7CTRL  bit masks and bit positions */
/* PORT_ISC  is already defined. */
/* PORT_PULLUPEN  is already defined. */
/* PORT_INVEN  is already defined. */

/* PORTMUX - Port Multiplexer */
/* PORTMUX.CTRLA  bit masks and bit positions */
#define PORTMUX_EVOUT0_bm  0x01  /* Event Output 0 bit mask. */
#define PORTMUX_EVOUT0_bp  0  /* Event Output 0 bit position. */
#define PORTMUX_EVOUT1_bm  0x02  /* Event Output 1 bit mask. */
#define PORTMUX_EVOUT1_bp  1  /* Event Output 1 bit position. */
#define PORTMUX_EVOUT2_bm  0x04  /* Event Output 2 bit mask. */
#define PORTMUX_EVOUT2_bp  2  /* Event Output 2 bit position. */
#define PORTMUX_LUT0_bm  0x10  /* Configurable Custom Logic LUT0 bit mask. */
#define PORTMUX_LUT0_bp  4  /* Configurable Custom Logic LUT0 bit position. */
#define PORTMUX_LUT1_bm  0x20  /* Configurable Custom Logic LUT1 bit mask. */
#define PORTMUX_LUT1_bp  5  /* Configurable Custom Logic LUT1 bit position. */

/* PORTMUX.CTRLB  bit masks and bit positions */
#define PORTMUX_USART0_bm  0x01  /* Port Multiplexer USART0 bit mask. */
#define PORTMUX_USART0_bp  0  /* Port Multiplexer USART0 bit position. */
#define PORTMUX_SPI0_bm  0x04  /* Port Multiplexer SPI0 bit mask. */
#define PORTMUX_SPI0_bp  2  /* Port Multiplexer SPI0 bit position. */
#define PORTMUX_TWI0_bm  0x10  /* Port Multiplexer TWI0 bit mask. */
#define PORTMUX_TWI0_bp  4  /* Port Multiplexer TWI0 bit position. */

/* PORTMUX.CTRLC  bit masks and bit positions */
#define PORTMUX_TCA00_bm  0x01  /* Port Multiplexer TCA0 Output 0 bit mask. */
#define PORTMUX_TCA00_bp  0  /* Port Multiplexer TCA0 Output 0 bit position. */
#define PORTMUX_TCA01_bm  0x02  /* Port Multiplexer TCA0 Output 1 bit mask. */
#define PORTMUX_TCA01_bp  1  /* Port Multiplexer TCA0 Output 1 bit position. */
#define PORTMUX_TCA02_bm  0x04  /* Port Multiplexer TCA0 Output 2 bit mask. */
#define PORTMUX_TCA02_bp  2  /* Port Multiplexer TCA0 Output 2 bit position. */
#define PORTMUX_TCA03_bm  0x08  /* Port Multiplexer TCA0 Output 3 bit mask. */
#define PORTMUX_TCA03_bp  3  /* Port Multiplexer TCA0 Output 3 bit position. */
#define PORTMUX_TCA04_bm  0x10  /* Port Multiplexer TCA0 Output 4 bit mask. */
#define PORTMUX_TCA04_bp  4  /* Port Multiplexer TCA0 Output 4 bit position. */
#define PORTMUX_TCA05_bm  0x20  /* Port Multiplexer TCA0 Output 5 bit mask. */
#define PORTMUX_TCA05_bp  5  /* Port Multiplexer TCA0 Output 5 bit position. */

/* PORTMUX.CTRLD  bit masks and bit positions */
#define PORTMUX_TCB0_bm  0x01  /* Port Multiplexer TCB bit mask. */
#define PORTMUX_TCB0_bp  0  /* Port Multiplexer TCB bit position. */

/* RSTCTRL - Reset controller */
/* RSTCTRL.RSTFR  bit masks and bit positions */
#define RSTCTRL_PORF_bm  0x01  /* Power on Reset flag bit mask. */
#define RSTCTRL_PORF_bp  0  /* Power on Reset flag bit position. */
#define RSTCTRL_BORF_bm  0x02  /* Brown out detector Reset flag bit mask. */
#define RSTCTRL_BORF_bp  1  /* Brown out detector Reset flag bit position. */
#define RSTCTRL_EXTRF_bm  0x04  /* External Reset flag bit mask. */
#define RSTCTRL_EXTRF_bp  2  /* External Reset flag bit position. */
#define RSTCTRL_WDRF_bm  0x08  /* Watch dog Reset flag bit mask. */
#define RSTCTRL_WDRF_bp  3  /* Watch dog Reset flag bit position. */
#define RSTCTRL_SWRF_bm  0x10  /* Software Reset flag bit mask. */
#define RSTCTRL_SWRF_bp  4  /* Software Reset flag bit position. */
#define RSTCTRL_UPDIRF_bm  0x20  /* UPDI Reset flag bit mask. */
#define RSTCTRL_UPDIRF_bp  5  /* UPDI Reset flag bit position. */

/* RSTCTRL.SWRR  bit masks and bit positions */
#define RSTCTRL_SWRE_bm  0x01  /* Software reset enable bit mask. */
#define RSTCTRL_SWRE_bp  0  /* Software reset enable bit position. */

/* RTC - Real-Time Counter */
/* RTC.CTRLA  bit masks and bit positions */
#define RTC_RTCEN_bm  0x01  /* Enable bit mask. */
#define RTC_RTCEN_bp  0  /* Enable bit position. */
#define RTC_PRESCALER_gm  0x78  /* Prescaling Factor group mask. */
#define RTC_PRESCALER_gp  3  /* Prescaling Factor group position. */
#define RTC_PRESCALER0_bm  (1<<3)  /* Prescaling Factor bit 0 mask. */
#define RTC_PRESCALER0_bp  3  /* Prescaling Factor bit 0 position. */
#define RTC_PRESCALER1_bm  (1<<4)  /* Prescaling Factor bit 1 mask. */
#define RTC_PRESCALER1_bp  4  /* Prescaling Factor bit 1 position. */
#define RTC_PRESCALER2_bm  (1<<5)  /* Prescaling Factor bit 2 mask. */
#define RTC_PRESCALER2_bp  5  /* Prescaling Factor bit 2 position. */
#define RTC_PRESCALER3_bm  (1<<6)  /* Prescaling Factor bit 3 mask. */
#define RTC_PRESCALER3_bp  6  /* Prescaling Factor bit 3 position. */
#define RTC_RUNSTDBY_bm  0x80  /* Run In Standby bit mask. */
#define RTC_RUNSTDBY_bp  7  /* Run In Standby bit position. */

/* RTC.STATUS  bit masks and bit positions */
#define RTC_CTRLABUSY_bm  0x01  /* CTRLA Synchronization Busy Flag bit mask. */
#define RTC_CTRLABUSY_bp  0  /* CTRLA Synchronization Busy Flag bit position. */
#define RTC_CNTBUSY_bm  0x02  /* Count Synchronization Busy Flag bit mask. */
#define RTC_CNTBUSY_bp  1  /* Count Synchronization Busy Flag bit position. */
#define RTC_PERBUSY_bm  0x04  /* Period Synchronization Busy Flag bit mask. */
#define RTC_PERBUSY_bp  2  /* Period Synchronization Busy Flag bit position. */
#define RTC_CMPBUSY_bm  0x08  /* Comparator Synchronization Busy Flag bit mask. */
#define RTC_CMPBUSY_bp  3  /* Comparator Synchronization Busy Flag bit position. */

/* RTC.INTCTRL  bit masks and bit positions */
#define RTC_OVF_bm  0x01  /* Overflow Interrupt enable bit mask. */
#define RTC_OVF_bp  0  /* Overflow Interrupt enable bit position. */
#define RTC_CMP_bm  0x02  /* Compare Match Interrupt enable bit mask. */
#define RTC_CMP_bp  1  /* Compare Match Interrupt enable bit position. */

/* RTC.INTFLAGS  bit masks and bit positions */
/* RTC_OVF  is already defined. */
/* RTC_CMP  is already defined. */


/* RTC.DBGCTRL  bit masks and bit positions */
#define RTC_DBGRUN_bm  0x01  /* Run in debug bit mask. */
#define RTC_DBGRUN_bp  0  /* Run in debug bit position. */

/* RTC.CLKSEL  bit masks and bit positions */
#define RTC_CLKSEL_gm  0x03  /* Clock Select group mask. */
#define RTC_CLKSEL_gp  0  /* Clock Select group position. */
#define RTC_CLKSEL0_bm  (1<<0)  /* Clock Select bit 0 mask. */
#define RTC_CLKSEL0_bp  0  /* Clock Select bit 0 position. */
#define RTC_CLKSEL1_bm  (1<<1)  /* Clock Select bit 1 mask. */
#define RTC_CLKSEL1_bp  1  /* Clock Select bit 1 position. */




/* RTC.PITCTRLA  bit masks and bit positions */
#define RTC_PITEN_bm  0x01  /* Enable bit mask. */
#define RTC_PITEN_bp  0  /* Enable bit position. */
#define RTC_PERIOD_gm  0x78  /* Period group mask. */
#define RTC_PERIOD_gp  3  /* Period group position. */
#define RTC_PERIOD0_bm  (1<<3)  /* Period bit 0 mask. */
#define RTC_PERIOD0_bp  3  /* Period bit 0 position. */
#define RTC_PERIOD1_bm  (1<<4)  /* Period bit 1 mask. */
#define RTC_PERIOD1_bp  4  /* Period bit 1 position. */
#define RTC_PERIOD2_bm  (1<<5)  /* Period bit 2 mask. */
#define RTC_PERIOD2_bp  5  /* Period bit 2 position. */
#define RTC_PERIOD3_bm  (1<<6)  /* Period bit 3 mask. */
#define RTC_PERIOD3_bp  6  /* Period bit 3 position. */

/* RTC.PITSTATUS  bit masks and bit positions */
#define RTC_CTRLBUSY_bm  0x01  /* CTRLA Synchronization Busy Flag bit mask. */
#define RTC_CTRLBUSY_bp  0  /* CTRLA Synchronization Busy Flag bit position. */

/* RTC.PITINTCTRL  bit masks and bit positions */
#define RTC_PI_bm  0x01  /* Periodic Interrupt bit mask. */
#define RTC_PI_bp  0  /* Periodic Interrupt bit position. */

/* RTC.PITINTFLAGS  bit masks and bit positions */
/* RTC_PI  is already defined. */

/* RTC.PITDBGCTRL  bit masks and bit positions */
/* RTC_DBGRUN  is already defined. */




















/* SLPCTRL - Sleep Controller */
/* SLPCTRL.CTRLA  bit masks and bit positions */
#define SLPCTRL_SEN_bm  0x01  /* Sleep enable bit mask. */
#define SLPCTRL_SEN_bp  0  /* Sleep enable bit position. */
#define SLPCTRL_SMODE_gm  0x06  /* Sleep mode group mask. */
#define SLPCTRL_SMODE_gp  1  /* Sleep mode group position. */
#define SLPCTRL_SMODE0_bm  (1<<1)  /* Sleep mode bit 0 mask. */
#define SLPCTRL_SMODE0_bp  1  /* Sleep mode bit 0 position. */
#define SLPCTRL_SMODE1_bm  (1<<2)  /* Sleep mode bit 1 mask. */
#define SLPCTRL_SMODE1_bp  2  /* Sleep mode bit 1 position. */

/* SPI - Serial Peripheral Interface */
/* SPI.CTRLA  bit masks and bit positions */
#define SPI_ENABLE_bm  0x01  /* Enable Module bit mask. */
#define SPI_ENABLE_bp  0  /* Enable Module bit position. */
#define SPI_PRESC_gm  0x06  /* Prescaler group mask. */
#define SPI_PRESC_gp  1  /* Prescaler group position. */
#define SPI_PRESC0_bm  (1<<1)  /* Prescaler bit 0 mask. */
#define SPI_PRESC0_bp  1  /* Prescaler bit 0 position. */
#define SPI_PRESC1_bm  (1<<2)  /* Prescaler bit 1 mask. */
#define SPI_PRESC1_bp  2  /* Prescaler bit 1 position. */
#define SPI_CLK2X_bm  0x10  /* Enable Double Speed bit mask. */
#define SPI_CLK2X_bp  4  /* Enable Double Speed bit position. */
#define SPI_MASTER_bm  0x20  /* Master Operation Enable bit mask. */
#define SPI_MASTER_bp  5  /* Master Operation Enable bit position. */
#define SPI_DORD_bm  0x40  /* Data Order Setting bit mask. */
#define SPI_DORD_bp  6  /* Data Order Setting bit position. */

/* SPI.CTRLB  bit masks and bit positions */
#define SPI_MODE_gm  0x03  /* SPI Mode group mask. */
#define SPI_MODE_gp  0  /* SPI Mode group position. */
#define SPI_MODE0_bm  (1<<0)  /* SPI Mode bit 0 mask. */
#define SPI_MODE0_bp  0  /* SPI Mode bit 0 position. */
#define SPI_MODE1_bm  (1<<1)  /* SPI Mode bit 1 mask. */
#define SPI_MODE1_bp  1  /* SPI Mode bit 1 position. */
#define SPI_SSD_bm  0x04  /* Slave Select Disable bit mask. */
#define SPI_SSD_bp  2  /* Slave Select Disable bit position. */
#define SPI_BUFWR_bm  0x40  /* Buffer Write Mode bit mask. */
#define SPI_BUFWR_bp  6  /* Buffer Write Mode bit position. */
#define SPI_BUFEN_bm  0x80  /* Buffer Mode Enable bit mask. */
#define SPI_BUFEN_bp  7  /* Buffer Mode Enable bit position. */

/* SPI.INTCTRL  bit masks and bit positions */
#define SPI_IE_bm  0x01  /* Interrupt Enable bit mask. */
#define SPI_IE_bp  0  /* Interrupt Enable bit position. */
#define SPI_SSIE_bm  0x10  /* Slave Select Trigger Interrupt Enable bit mask. */
#define SPI_SSIE_bp  4  /* Slave Select Trigger Interrupt Enable bit position. */
#define SPI_DREIE_bm  0x20  /* Data Register Empty Interrupt Enable bit mask. */
#define SPI_DREIE_bp  5  /* Data Register Empty Interrupt Enable bit position. */
#define SPI_TXCIE_bm  0x40  /* Transfer Complete Interrupt Enable bit mask. */
#define SPI_TXCIE_bp  6  /* Transfer Complete Interrupt Enable bit position. */
#define SPI_RXCIE_bm  0x80  /* Receive Complete Interrupt Enable bit mask. */
#define SPI_RXCIE_bp  7  /* Receive Complete Interrupt Enable bit position. */

/* SPI.INTFLAGS  bit masks and bit positions */
#define SPI_BUFOVF_bm  0x01  /* Buffer Overflow bit mask. */
#define SPI_BUFOVF_bp  0  /* Buffer Overflow bit position. */
#define SPI_SSIF_bm  0x10  /* Slave Select Trigger Interrupt Flag bit mask. */
#define SPI_SSIF_bp  4  /* Slave Select Trigger Interrupt Flag bit position. */
#define SPI_DREIF_bm  0x20  /* Data Register Empty Interrupt Flag bit mask. */
#define SPI_DREIF_bp  5  /* Data Register Empty Interrupt Flag bit position. */
#define SPI_TXCIF_bm  0x40  /* Transfer Complete Interrupt Flag bit mask. */
#define SPI_TXCIF_bp  6  /* Transfer Complete Interrupt Flag bit position. */
#define SPI_WRCOL_bm  0x40  /* Write Collision bit mask. */
#define SPI_WRCOL_bp  6  /* Write Collision bit position. */
#define SPI_RXCIF_bm  0x80  /* Receive Complete Interrupt Flag bit mask. */
#define SPI_RXCIF_bp  7  /* Receive Complete Interrupt Flag bit position. */
#define SPI_IF_bm  0x80  /* Interrupt Flag bit mask. */
#define SPI_IF_bp  7  /* Interrupt Flag bit position. */



/* SYSCFG - System Configuration Registers */
/* SYSCFG.EXTBRK  bit masks and bit positions */
#define SYSCFG_ENEXTBRK_bm  0x01  /* External break enable bit mask. */
#define SYSCFG_ENEXTBRK_bp  0  /* External break enable bit position. */

/* TCA - 16-bit Timer/Counter Type A */
/* TCA_SINGLE.CTRLA  bit masks and bit positions */
#define TCA_SINGLE_ENABLE_bm  0x01  /* Module Enable bit mask. */
#define TCA_SINGLE_ENABLE_bp  0  /* Module Enable bit position. */
#define TCA_SINGLE_CLKSEL_gm  0x0E  /* Clock Selection group mask. */
#define TCA_SINGLE_CLKSEL_gp  1  /* Clock Selection group position. */
#define TCA_SINGLE_CLKSEL0_bm  (1<<1)  /* Clock Selection bit 0 mask. */
#define TCA_SINGLE_CLKSEL0_bp  1  /* Clock Selection bit 0 position. */
#define TCA_SINGLE_CLKSEL1_bm  (1<<2)  /* Clock Selection bit 1 mask. */
#define TCA_SINGLE_CLKSEL1_bp  2  /* Clock Selection bit 1 position. */
#define TCA_SINGLE_CLKSEL2_bm  (1<<3)  /* Clock Selection bit 2 mask. */
#define TCA_SINGLE_CLKSEL2_bp  3  /* Clock Selection bit 2 position. */

/* TCA_SINGLE.CTRLB  bit masks and bit positions */
#define TCA_SINGLE_WGMODE_gm  0x07  /* Waveform generation mode group mask. */
#define TCA_SINGLE_WGMODE_gp  0  /* Waveform generation mode group position. */
#define TCA_SINGLE_WGMODE0_bm  (1<<0)  /* Waveform generation mode bit 0 mask. */
#define TCA_SINGLE_WGMODE0_bp  0  /* Waveform generation mode bit 0 position. */
#define TCA_SINGLE_WGMODE1_bm  (1<<1)  /* Waveform generation mode bit 1 mask. */
#define TCA_SINGLE_WGMODE1_bp  1  /* Waveform generation mode bit 1 position. */
#define TCA_SINGLE_WGMODE2_bm  (1<<2)  /* Waveform generation mode bit 2 mask. */
#define TCA_SINGLE_WGMODE2_bp  2  /* Waveform generation mode bit 2 position. */
#define TCA_SINGLE_ALUPD_bm  0x08  /* Auto Lock Update bit mask. */
#define TCA_SINGLE_ALUPD_bp  3  /* Auto Lock Update bit position. */
#define TCA_SINGLE_CMP0EN_bm  0x10  /* Compare 0 Enable bit mask. */
#define TCA_SINGLE_CMP0EN_bp  4  /* Compare 0 Enable bit position. */
#define TCA_SINGLE_CMP1EN_bm  0x20  /* Compare 1 Enable bit mask. */
#define TCA_SINGLE_CMP1EN_bp  5  /* Compare 1 Enable bit position. */
#define TCA_SINGLE_CMP2EN_bm  0x40  /* Compare 2 Enable bit mask. */
#define TCA_SINGLE_CMP2EN_bp  6  /* Compare 2 Enable bit position. */

/* TCA_SINGLE.CTRLC  bit masks and bit positions */
#define TCA_SINGLE_CMP0OV_bm  0x01  /* Compare 0 Waveform Output Value bit mask. */
#define TCA_SINGLE_CMP0OV_bp  0  /* Compare 0 Waveform Output Value bit position. */
#define TCA_SINGLE_CMP1OV_bm  0x02  /* Compare 1 Waveform Output Value bit mask. */
#define TCA_SINGLE_CMP1OV_bp  1  /* Compare 1 Waveform Output Value bit position. */
#define TCA_SINGLE_CMP2OV_bm  0x04  /* Compare 2 Waveform Output Value bit mask. */
#define TCA_SINGLE_CMP2OV_bp  2  /* Compare 2 Waveform Output Value bit position. */

/* TCA_SINGLE.CTRLD  bit masks and bit positions */
#define TCA_SINGLE_SPLITM_bm  0x01  /* Split Mode Enable bit mask. */
#define TCA_SINGLE_SPLITM_bp  0  /* Split Mode Enable bit position. */

/* TCA_SINGLE.CTRLECLR  bit masks and bit positions */
#define TCA_SINGLE_DIR_bm  0x01  /* Direction bit mask. */
#define TCA_SINGLE_DIR_bp  0  /* Direction bit position. */
#define TCA_SINGLE_LUPD_bm  0x02  /* Lock Update bit mask. */
#define TCA_SINGLE_LUPD_bp  1  /* Lock Update bit position. */
#define TCA_SINGLE_CMD_gm  0x0C  /* Command group mask. */
#define TCA_SINGLE_CMD_gp  2  /* Command group position. */
#define TCA_SINGLE_CMD0_bm  (1<<2)  /* Command bit 0 mask. */
#define TCA_SINGLE_CMD0_bp  2  /* Command bit 0 position. */
#define TCA_SINGLE_CMD1_bm  (1<<3)  /* Command bit 1 mask. */
#define TCA_SINGLE_CMD1_bp  3  /* Command bit 1 position. */

/* TCA_SINGLE.CTRLESET  bit masks and bit positions */
/* TCA_SINGLE_DIR  is already defined. */
/* TCA_SINGLE_LUPD  is already defined. */
/* TCA_SINGLE_CMD  is already defined. */

/* TCA_SINGLE.CTRLFCLR  bit masks and bit positions */
#define TCA_SINGLE_PERBV_bm  0x01  /* Period Buffer Valid bit mask. */
#define TCA_SINGLE_PERBV_bp  0  /* Period Buffer Valid bit position. */
#define TCA_SINGLE_CMP0BV_bm  0x02  /* Compare 0 Buffer Valid bit mask. */
#define TCA_SINGLE_CMP0BV_bp  1  /* Compare 0 Buffer Valid bit position. */
#define TCA_SINGLE_CMP1BV_bm  0x04  /* Compare 1 Buffer Valid bit mask. */
#define TCA_SINGLE_CMP1BV_bp  2  /* Compare 1 Buffer Valid bit position. */
#define TCA_SINGLE_CMP2BV_bm  0x08  /* Compare 2 Buffer Valid bit mask. */
#define TCA_SINGLE_CMP2BV_bp  3  /* Compare 2 Buffer Valid bit position. */

/* TCA_SINGLE.CTRLFSET  bit masks and bit positions */
/* TCA_SINGLE_PERBV  is already defined. */
/* TCA_SINGLE_CMP0BV  is already defined. */
/* TCA_SINGLE_CMP1BV  is already defined. */
/* TCA_SINGLE_CMP2BV  is already defined. */

/* TCA_SINGLE.EVCTRL  bit masks and bit positions */
#define TCA_SINGLE_CNTEI_bm  0x01  /* Count on Event Input bit mask. */
#define TCA_SINGLE_CNTEI_bp  0  /* Count on Event Input bit position. */
#define TCA_SINGLE_EVACT_gm  0x06  /* Event Action group mask. */
#define TCA_SINGLE_EVACT_gp  1  /* Event Action group position. */
#define TCA_SINGLE_EVACT0_bm  (1<<1)  /* Event Action bit 0 mask. */
#define TCA_SINGLE_EVACT0_bp  1  /* Event Action bit 0 position. */
#define TCA_SINGLE_EVACT1_bm  (1<<2)  /* Event Action bit 1 mask. */
#define TCA_SINGLE_EVACT1_bp  2  /* Event Action bit 1 position. */

/* TCA_SINGLE.INTCTRL  bit masks and bit positions */
#define TCA_SINGLE_OVF_bm  0x01  /* Overflow Interrupt bit mask. */
#define TCA_SINGLE_OVF_bp  0  /* Overflow Interrupt bit position. */
#define TCA_SINGLE_CMP0_bm  0x10  /* Compare 0 Interrupt bit mask. */
#define TCA_SINGLE_CMP0_bp  4  /* Compare 0 Interrupt bit position. */
#define TCA_SINGLE_CMP1_bm  0x20  /* Compare 1 Interrupt bit mask. */
#define TCA_SINGLE_CMP1_bp  5  /* Compare 1 Interrupt bit position. */
#define TCA_SINGLE_CMP2_bm  0x40  /* Compare 2 Interrupt bit mask. */
#define TCA_SINGLE_CMP2_bp  6  /* Compare 2 Interrupt bit position. */

/* TCA_SINGLE.INTFLAGS  bit masks and bit positions */
/* TCA_SINGLE_OVF  is already defined. */
/* TCA_SINGLE_CMP0  is already defined. */
/* TCA_SINGLE_CMP1  is already defined. */
/* TCA_SINGLE_CMP2  is already defined. */

/* TCA_SINGLE.DBGCTRL  bit masks and bit positions */
#define TCA_SINGLE_DBGRUN_bm  0x01  /* Debug Run bit mask. */
#define TCA_SINGLE_DBGRUN_bp  0  /* Debug Run bit position. */











/* TCA_SPLIT.CTRLA  bit masks and bit positions */
#define TCA_SPLIT_ENABLE_bm  0x01  /* Module Enable bit mask. */
#define TCA_SPLIT_ENABLE_bp  0  /* Module Enable bit position. */
#define TCA_SPLIT_CLKSEL_gm  0x0E  /* Clock Selection group mask. */
#define TCA_SPLIT_CLKSEL_gp  1  /* Clock Selection group position. */
#define TCA_SPLIT_CLKSEL0_bm  (1<<1)  /* Clock Selection bit 0 mask. */
#define TCA_SPLIT_CLKSEL0_bp  1  /* Clock Selection bit 0 position. */
#define TCA_SPLIT_CLKSEL1_bm  (1<<2)  /* Clock Selection bit 1 mask. */
#define TCA_SPLIT_CLKSEL1_bp  2  /* Clock Selection bit 1 position. */
#define TCA_SPLIT_CLKSEL2_bm  (1<<3)  /* Clock Selection bit 2 mask. */
#define TCA_SPLIT_CLKSEL2_bp  3  /* Clock Selection bit 2 position. */

/* TCA_SPLIT.CTRLB  bit masks and bit positions */
#define TCA_SPLIT_LCMP0EN_bm  0x01  /* Low Compare 0 Enable bit mask. */
#define TCA_SPLIT_LCMP0EN_bp  0  /* Low Compare 0 Enable bit position. */
#define TCA_SPLIT_LCMP1EN_bm  0x02  /* Low Compare 1 Enable bit mask. */
#define TCA_SPLIT_LCMP1EN_bp  1  /* Low Compare 1 Enable bit position. */
#define TCA_SPLIT_LCMP2EN_bm  0x04  /* Low Compare 2 Enable bit mask. */
#define TCA_SPLIT_LCMP2EN_bp  2  /* Low Compare 2 Enable bit position. */
#define TCA_SPLIT_HCMP0EN_bm  0x10  /* High Compare 0 Enable bit mask. */
#define TCA_SPLIT_HCMP0EN_bp  4  /* High Compare 0 Enable bit position. */
#define TCA_SPLIT_HCMP1EN_bm  0x20  /* High Compare 1 Enable bit mask. */
#define TCA_SPLIT_HCMP1EN_bp  5  /* High Compare 1 Enable bit position. */
#define TCA_SPLIT_HCMP2EN_bm  0x40  /* High Compare 2 Enable bit mask. */
#define TCA_SPLIT_HCMP2EN_bp  6  /* High Compare 2 Enable bit position. */

/* TCA_SPLIT.CTRLC  bit masks and bit positions */
#define TCA_SPLIT_LCMP0OV_bm  0x01  /* Low Compare 0 Output Value bit mask. */
#define TCA_SPLIT_LCMP0OV_bp  0  /* Low Compare 0 Output Value bit position. */
#define TCA_SPLIT_LCMP1OV_bm  0x02  /* Low Compare 1 Output Value bit mask. */
#define TCA_SPLIT_LCMP1OV_bp  1  /* Low Compare 1 Output Value bit position. */
#define TCA_SPLIT_LCMP2OV_bm  0x04  /* Low Compare 2 Output Value bit mask. */
#define TCA_SPLIT_LCMP2OV_bp  2  /* Low Compare 2 Output Value bit position. */
#define TCA_SPLIT_HCMP0OV_bm  0x10  /* High Compare 0 Output Value bit mask. */
#define TCA_SPLIT_HCMP0OV_bp  4  /* High Compare 0 Output Value bit position. */
#define TCA_SPLIT_HCMP1OV_bm  0x20  /* High Compare 1 Output Value bit mask. */
#define TCA_SPLIT_HCMP1OV_bp  5  /* High Compare 1 Output Value bit position. */
#define TCA_SPLIT_HCMP2OV_bm  0x40  /* High Compare 2 Output Value bit mask. */
#define TCA_SPLIT_HCMP2OV_bp  6  /* High Compare 2 Output Value bit position. */

/* TCA_SPLIT.CTRLD  bit masks and bit positions */
#define TCA_SPLIT_SPLITM_bm  0x01  /* Split Mode Enable bit mask. */
#define TCA_SPLIT_SPLITM_bp  0  /* Split Mode Enable bit position. */

/* TCA_SPLIT.CTRLECLR  bit masks and bit positions */
#define TCA_SPLIT_CMD_gm  0x0C  /* Command group mask. */
#define TCA_SPLIT_CMD_gp  2  /* Command group position. */
#define TCA_SPLIT_CMD0_bm  (1<<2)  /* Command bit 0 mask. */
#define TCA_SPLIT_CMD0_bp  2  /* Command bit 0 position. */
#define TCA_SPLIT_CMD1_bm  (1<<3)  /* Command bit 1 mask. */
#define TCA_SPLIT_CMD1_bp  3  /* Command bit 1 position. */

/* TCA_SPLIT.CTRLESET  bit masks and bit positions */
/* TCA_SPLIT_CMD  is already defined. */

/* TCA_SPLIT.INTCTRL  bit masks and bit positions */
#define TCA_SPLIT_LUNF_bm  0x01  /* Low Underflow Interrupt Enable bit mask. */
#define TCA_SPLIT_LUNF_bp  0  /* Low Underflow Interrupt Enable bit position. */
#define TCA_SPLIT_HUNF_bm  0x02  /* High Underflow Interrupt Enable bit mask. */
#define TCA_SPLIT_HUNF_bp  1  /* High Underflow Interrupt Enable bit position. */
#define TCA_SPLIT_LCMP0_bm  0x10  /* Low Compare 0 Interrupt Enable bit mask. */
#define TCA_SPLIT_LCMP0_bp  4  /* Low Compare 0 Interrupt Enable bit position. */
#define TCA_SPLIT_LCMP1_bm  0x20  /* Low Compare 1 Interrupt Enable bit mask. */
#define TCA_SPLIT_LCMP1_bp  5  /* Low Compare 1 Interrupt Enable bit position. */
#define TCA_SPLIT_LCMP2_bm  0x40  /* Low Compare 2 Interrupt Enable bit mask. */
#define TCA_SPLIT_LCMP2_bp  6  /* Low Compare 2 Interrupt Enable bit position. */

/* TCA_SPLIT.INTFLAGS  bit masks and bit positions */
/* TCA_SPLIT_LUNF  is already defined. */
/* TCA_SPLIT_HUNF  is already defined. */
/* TCA_SPLIT_LCMP0  is already defined. */
/* TCA_SPLIT_LCMP1  is already defined. */
/* TCA_SPLIT_LCMP2  is already defined. */

/* TCA_SPLIT.DBGCTRL  bit masks and bit positions */
#define TCA_SPLIT_DBGRUN_bm  0x01  /* Debug Run bit mask. */
#define TCA_SPLIT_DBGRUN_bp  0  /* Debug Run bit position. */











/* TCB - 16-bit Timer Type B */
/* TCB.CTRLA  bit masks and bit positions */
#define TCB_ENABLE_bm  0x01  /* Enable bit mask. */
#define TCB_ENABLE_bp  0  /* Enable bit position. */
#define TCB_CLKSEL_gm  0x06  /* Clock Select group mask. */
#define TCB_CLKSEL_gp  1  /* Clock Select group position. */
#define TCB_CLKSEL0_bm  (1<<1)  /* Clock Select bit 0 mask. */
#define TCB_CLKSEL0_bp  1  /* Clock Select bit 0 position. */
#define TCB_CLKSEL1_bm  (1<<2)  /* Clock Select bit 1 mask. */
#define TCB_CLKSEL1_bp  2  /* Clock Select bit 1 position. */
#define TCB_SYNCUPD_bm  0x10  /* Synchronize Update bit mask. */
#define TCB_SYNCUPD_bp  4  /* Synchronize Update bit position. */
#define TCB_RUNSTDBY_bm  0x40  /* Run Standby bit mask. */
#define TCB_RUNSTDBY_bp  6  /* Run Standby bit position. */

/* TCB.CTRLB  bit masks and bit positions */
#define TCB_CNTMODE_gm  0x07  /* Timer Mode group mask. */
#define TCB_CNTMODE_gp  0  /* Timer Mode group position. */
#define TCB_CNTMODE0_bm  (1<<0)  /* Timer Mode bit 0 mask. */
#define TCB_CNTMODE0_bp  0  /* Timer Mode bit 0 position. */
#define TCB_CNTMODE1_bm  (1<<1)  /* Timer Mode bit 1 mask. */
#define TCB_CNTMODE1_bp  1  /* Timer Mode bit 1 position. */
#define TCB_CNTMODE2_bm  (1<<2)  /* Timer Mode bit 2 mask. */
#define TCB_CNTMODE2_bp  2  /* Timer Mode bit 2 position. */
#define TCB_CCMPEN_bm  0x10  /* Pin Output Enable bit mask. */
#define TCB_CCMPEN_bp  4  /* Pin Output Enable bit position. */
#define TCB_CCMPINIT_bm  0x20  /* Pin Initial State bit mask. */
#define TCB_CCMPINIT_bp  5  /* Pin Initial State bit position. */
#define TCB_ASYNC_bm  0x40  /* Asynchronous Enable bit mask. */
#define TCB_ASYNC_bp  6  /* Asynchronous Enable bit position. */

/* TCB.EVCTRL  bit masks and bit positions */
#define TCB_CAPTEI_bm  0x01  /* Event Input Enable bit mask. */
#define TCB_CAPTEI_bp  0  /* Event Input Enable bit position. */
#define TCB_EDGE_bm  0x10  /* Event Edge bit mask. */
#define TCB_EDGE_bp  4  /* Event Edge bit position. */
#define TCB_FILTER_bm  0x40  /* Input Capture Noise Cancellation Filter bit mask. */
#define TCB_FILTER_bp  6  /* Input Capture Noise Cancellation Filter bit position. */

/* TCB.INTCTRL  bit masks and bit positions */
#define TCB_CAPT_bm  0x01  /* Capture or Timeout bit mask. */
#define TCB_CAPT_bp  0  /* Capture or Timeout bit position. */

/* TCB.INTFLAGS  bit masks and bit positions */
/* TCB_CAPT  is already defined. */

/* TCB.STATUS  bit masks and bit positions */
#define TCB_RUN_bm  0x01  /* Run bit mask. */
#define TCB_RUN_bp  0  /* Run bit position. */

/* TCB.DBGCTRL  bit masks and bit positions */
#define TCB_DBGRUN_bm  0x01  /* Debug Run bit mask. */
#define TCB_DBGRUN_bp  0  /* Debug Run bit position. */




/* TCD - Timer Counter D */
/* TCD.CTRLA  bit masks and bit positions */
#define TCD_ENABLE_bm  0x01  /* Enable bit mask. */
#define TCD_ENABLE_bp  0  /* Enable bit position. */
#define TCD_SYNCPRES_gm  0x06  /* Syncronization prescaler group mask. */
#define TCD_SYNCPRES_gp  1  /* Syncronization prescaler group position. */
#define TCD_SYNCPRES0_bm  (1<<1)  /* Syncronization prescaler bit 0 mask. */
#define TCD_SYNCPRES0_bp  1  /* Syncronization prescaler bit 0 position. */
#define TCD_SYNCPRES1_bm  (1<<2)  /* Syncronization prescaler bit 1 mask. */
#define TCD_SYNCPRES1_bp  2  /* Syncronization prescaler bit 1 position. */
#define TCD_CNTPRES_gm  0x18  /* counter prescaler group mask. */
#define TCD_CNTPRES_gp  3  /* counter prescaler group position. */
#define TCD_CNTPRES0_bm  (1<<3)  /* counter prescaler bit 0 mask. */
#define TCD_CNTPRES0_bp  3  /* counter prescaler bit 0 position. */
#define TCD_CNTPRES1_bm  (1<<4)  /* counter prescaler bit 1 mask. */
#define TCD_CNTPRES1_bp  4  /* counter prescaler bit 1 position. */
#define TCD_CLKSEL_gm  0x60  /* clock select group mask. */
#define TCD_CLKSEL_gp  5  /* clock select group position. */
#define TCD_CLKSEL0_bm  (1<<5)  /* clock select bit 0 mask. */
#define TCD_CLKSEL0_bp  5  /* clock select bit 0 position. */
#define TCD_CLKSEL1_bm  (1<<6)  /* clock select bit 1 mask. */
#define TCD_CLKSEL1_bp  6  /* clock select bit 1 position. */

/* TCD.CTRLB  bit masks and bit positions */
#define TCD_WGMODE_gm  0x03  /* Waveform generation mode group mask. */
#define TCD_WGMODE_gp  0  /* Waveform generation mode group position. */
#define TCD_WGMODE0_bm  (1<<0)  /* Waveform generation mode bit 0 mask. */
#define TCD_WGMODE0_bp  0  /* Waveform generation mode bit 0 position. */
#define TCD_WGMODE1_bm  (1<<1)  /* Waveform generation mode bit 1 mask. */
#define TCD_WGMODE1_bp  1  /* Waveform generation mode bit 1 position. */

/* TCD.CTRLC  bit masks and bit positions */
#define TCD_CMPOVR_bm  0x01  /* Compare output value override bit mask. */
#define TCD_CMPOVR_bp  0  /* Compare output value override bit position. */
#define TCD_AUPDATE_bm  0x02  /* Auto update bit mask. */
#define TCD_AUPDATE_bp  1  /* Auto update bit position. */
#define TCD_FIFTY_bm  0x08  /* Fifty percent waveform bit mask. */
#define TCD_FIFTY_bp  3  /* Fifty percent waveform bit position. */
#define TCD_CMPCSEL_bm  0x40  /* Compare C output select bit mask. */
#define TCD_CMPCSEL_bp  6  /* Compare C output select bit position. */
#define TCD_CMPDSEL_bm  0x80  /* Compare D output select bit mask. */
#define TCD_CMPDSEL_bp  7  /* Compare D output select bit position. */

/* TCD.CTRLD  bit masks and bit positions */
#define TCD_CMPAVAL_gm  0x0F  /* Compare A value group mask. */
#define TCD_CMPAVAL_gp  0  /* Compare A value group position. */
#define TCD_CMPAVAL0_bm  (1<<0)  /* Compare A value bit 0 mask. */
#define TCD_CMPAVAL0_bp  0  /* Compare A value bit 0 position. */
#define TCD_CMPAVAL1_bm  (1<<1)  /* Compare A value bit 1 mask. */
#define TCD_CMPAVAL1_bp  1  /* Compare A value bit 1 position. */
#define TCD_CMPAVAL2_bm  (1<<2)  /* Compare A value bit 2 mask. */
#define TCD_CMPAVAL2_bp  2  /* Compare A value bit 2 position. */
#define TCD_CMPAVAL3_bm  (1<<3)  /* Compare A value bit 3 mask. */
#define TCD_CMPAVAL3_bp  3  /* Compare A value bit 3 position. */
#define TCD_CMPBVAL_gm  0xF0  /* Compare B value group mask. */
#define TCD_CMPBVAL_gp  4  /* Compare B value group position. */
#define TCD_CMPBVAL0_bm  (1<<4)  /* Compare B value bit 0 mask. */
#define TCD_CMPBVAL0_bp  4  /* Compare B value bit 0 position. */
#define TCD_CMPBVAL1_bm  (1<<5)  /* Compare B value bit 1 mask. */
#define TCD_CMPBVAL1_bp  5  /* Compare B value bit 1 position. */
#define TCD_CMPBVAL2_bm  (1<<6)  /* Compare B value bit 2 mask. */
#define TCD_CMPBVAL2_bp  6  /* Compare B value bit 2 position. */
#define TCD_CMPBVAL3_bm  (1<<7)  /* Compare B value bit 3 mask. */
#define TCD_CMPBVAL3_bp  7  /* Compare B value bit 3 position. */

/* TCD.CTRLE  bit masks and bit positions */
#define TCD_SYNCEOC_bm  0x01  /* synchronize end of cycle strobe bit mask. */
#define TCD_SYNCEOC_bp  0  /* synchronize end of cycle strobe bit position. */
#define TCD_SYNC_bm  0x02  /* synchronize strobe bit mask. */
#define TCD_SYNC_bp  1  /* synchronize strobe bit position. */
#define TCD_RESTART_bm  0x04  /* Restart strobe bit mask. */
#define TCD_RESTART_bp  2  /* Restart strobe bit position. */
#define TCD_SCAPTUREA_bm  0x08  /* Software Capture A Strobe bit mask. */
#define TCD_SCAPTUREA_bp  3  /* Software Capture A Strobe bit position. */
#define TCD_SCAPTUREB_bm  0x10  /* Software Capture B Strobe bit mask. */
#define TCD_SCAPTUREB_bp  4  /* Software Capture B Strobe bit position. */
#define TCD_DISEOC_bm  0x80  /* Disable at end of cycle bit mask. */
#define TCD_DISEOC_bp  7  /* Disable at end of cycle bit position. */

/* TCD.EVCTRLA  bit masks and bit positions */
#define TCD_TRIGEI_bm  0x01  /* Trigger event enable bit mask. */
#define TCD_TRIGEI_bp  0  /* Trigger event enable bit position. */
#define TCD_ACTION_bm  0x04  /* event action bit mask. */
#define TCD_ACTION_bp  2  /* event action bit position. */
#define TCD_EDGE_bm  0x10  /* edge select bit mask. */
#define TCD_EDGE_bp  4  /* edge select bit position. */
#define TCD_CFG_gm  0xC0  /* event config group mask. */
#define TCD_CFG_gp  6  /* event config group position. */
#define TCD_CFG0_bm  (1<<6)  /* event config bit 0 mask. */
#define TCD_CFG0_bp  6  /* event config bit 0 position. */
#define TCD_CFG1_bm  (1<<7)  /* event config bit 1 mask. */
#define TCD_CFG1_bp  7  /* event config bit 1 position. */

/* TCD.EVCTRLB  bit masks and bit positions */
/* TCD_TRIGEI  is already defined. */
/* TCD_ACTION  is already defined. */
/* TCD_EDGE  is already defined. */
/* TCD_CFG  is already defined. */

/* TCD.INTCTRL  bit masks and bit positions */
#define TCD_OVF_bm  0x01  /* Overflow interrupt enable bit mask. */
#define TCD_OVF_bp  0  /* Overflow interrupt enable bit position. */
#define TCD_TRIGA_bm  0x04  /* Trigger A interrupt enable bit mask. */
#define TCD_TRIGA_bp  2  /* Trigger A interrupt enable bit position. */
#define TCD_TRIGB_bm  0x08  /* Trigger B interrupt enable bit mask. */
#define TCD_TRIGB_bp  3  /* Trigger B interrupt enable bit position. */

/* TCD.INTFLAGS  bit masks and bit positions */
/* TCD_OVF  is already defined. */
/* TCD_TRIGA  is already defined. */
/* TCD_TRIGB  is already defined. */

/* TCD.STATUS  bit masks and bit positions */
#define TCD_ENRDY_bm  0x01  /* Enable ready bit mask. */
#define TCD_ENRDY_bp  0  /* Enable ready bit position. */
#define TCD_CMDRDY_bm  0x02  /* Command ready bit mask. */
#define TCD_CMDRDY_bp  1  /* Command ready bit position. */
#define TCD_PWMACTA_bm  0x40  /* PWM activity on A bit mask. */
#define TCD_PWMACTA_bp  6  /* PWM activity on A bit position. */
#define TCD_PWMACTB_bm  0x80  /* PWM activity on B bit mask. */
#define TCD_PWMACTB_bp  7  /* PWM activity on B bit position. */

/* TCD.INPUTCTRLA  bit masks and bit positions */
#define TCD_INPUTMODE_gm  0x0F  /* Input mode group mask. */
#define TCD_INPUTMODE_gp  0  /* Input mode group position. */
#define TCD_INPUTMODE0_bm  (1<<0)  /* Input mode bit 0 mask. */
#define TCD_INPUTMODE0_bp  0  /* Input mode bit 0 position. */
#define TCD_INPUTMODE1_bm  (1<<1)  /* Input mode bit 1 mask. */
#define TCD_INPUTMODE1_bp  1  /* Input mode bit 1 position. */
#define TCD_INPUTMODE2_bm  (1<<2)  /* Input mode bit 2 mask. */
#define TCD_INPUTMODE2_bp  2  /* Input mode bit 2 position. */
#define TCD_INPUTMODE3_bm  (1<<3)  /* Input mode bit 3 mask. */
#define TCD_INPUTMODE3_bp  3  /* Input mode bit 3 position. */

/* TCD.INPUTCTRLB  bit masks and bit positions */
/* TCD_INPUTMODE  is already defined. */

/* TCD.FAULTCTRL  bit masks and bit positions */
#define TCD_CMPA_bm  0x01  /* Compare A value bit mask. */
#define TCD_CMPA_bp  0  /* Compare A value bit position. */
#define TCD_CMPB_bm  0x02  /* Compare B value bit mask. */
#define TCD_CMPB_bp  1  /* Compare B value bit position. */
#define TCD_CMPC_bm  0x04  /* Compare C value bit mask. */
#define TCD_CMPC_bp  2  /* Compare C value bit position. */
#define TCD_CMPD_bm  0x08  /* Compare D vaule bit mask. */
#define TCD_CMPD_bp  3  /* Compare D vaule bit position. */
#define TCD_CMPAEN_bm  0x10  /* Compare A enable bit mask. */
#define TCD_CMPAEN_bp  4  /* Compare A enable bit position. */
#define TCD_CMPBEN_bm  0x20  /* Compare B enable bit mask. */
#define TCD_CMPBEN_bp  5  /* Compare B enable bit position. */
#define TCD_CMPCEN_bm  0x40  /* Compare C enable bit mask. */
#define TCD_CMPCEN_bp  6  /* Compare C enable bit position. */
#define TCD_CMPDEN_bm  0x80  /* Compare D enable bit mask. */
#define TCD_CMPDEN_bp  7  /* Compare D enable bit position. */

/* TCD.DLYCTRL  bit masks and bit positions */
#define TCD_DLYSEL_gm  0x03  /* Delay select group mask. */
#define TCD_DLYSEL_gp  0  /* Delay select group position. */
#define TCD_DLYSEL0_bm  (1<<0)  /* Delay select bit 0 mask. */
#define TCD_DLYSEL0_bp  0  /* Delay select bit 0 position. */
#define TCD_DLYSEL1_bm  (1<<1)  /* Delay select bit 1 mask. */
#define TCD_DLYSEL1_bp  1  /* Delay select bit 1 position. */
#define TCD_DLYTRIG_gm  0x0C  /* Delay trigger group mask. */
#define TCD_DLYTRIG_gp  2  /* Delay trigger group position. */
#define TCD_DLYTRIG0_bm  (1<<2)  /* Delay trigger bit 0 mask. */
#define TCD_DLYTRIG0_bp  2  /* Delay trigger bit 0 position. */
#define TCD_DLYTRIG1_bm  (1<<3)  /* Delay trigger bit 1 mask. */
#define TCD_DLYTRIG1_bp  3  /* Delay trigger bit 1 position. */
#define TCD_DLYPRESC_gm  0x30  /* Delay prescaler group mask. */
#define TCD_DLYPRESC_gp  4  /* Delay prescaler group position. */
#define TCD_DLYPRESC0_bm  (1<<4)  /* Delay prescaler bit 0 mask. */
#define TCD_DLYPRESC0_bp  4  /* Delay prescaler bit 0 position. */
#define TCD_DLYPRESC1_bm  (1<<5)  /* Delay prescaler bit 1 mask. */
#define TCD_DLYPRESC1_bp  5  /* Delay prescaler bit 1 position. */

/* TCD.DLYVAL  bit masks and bit positions */
#define TCD_DLYVAL_gm  0xFF  /* Delay value group mask. */
#define TCD_DLYVAL_gp  0  /* Delay value group position. */
#define TCD_DLYVAL0_bm  (1<<0)  /* Delay value bit 0 mask. */
#define TCD_DLYVAL0_bp  0  /* Delay value bit 0 position. */
#define TCD_DLYVAL1_bm  (1<<1)  /* Delay value bit 1 mask. */
#define TCD_DLYVAL1_bp  1  /* Delay value bit 1 position. */
#define TCD_DLYVAL2_bm  (1<<2)  /* Delay value bit 2 mask. */
#define TCD_DLYVAL2_bp  2  /* Delay value bit 2 position. */
#define TCD_DLYVAL3_bm  (1<<3)  /* Delay value bit 3 mask. */
#define TCD_DLYVAL3_bp  3  /* Delay value bit 3 position. */
#define TCD_DLYVAL4_bm  (1<<4)  /* Delay value bit 4 mask. */
#define TCD_DLYVAL4_bp  4  /* Delay value bit 4 position. */
#define TCD_DLYVAL5_bm  (1<<5)  /* Delay value bit 5 mask. */
#define TCD_DLYVAL5_bp  5  /* Delay value bit 5 position. */
#define TCD_DLYVAL6_bm  (1<<6)  /* Delay value bit 6 mask. */
#define TCD_DLYVAL6_bp  6  /* Delay value bit 6 position. */
#define TCD_DLYVAL7_bm  (1<<7)  /* Delay value bit 7 mask. */
#define TCD_DLYVAL7_bp  7  /* Delay value bit 7 position. */

/* TCD.DITCTRL  bit masks and bit positions */
#define TCD_DITHERSEL_gm  0x03  /* dither select group mask. */
#define TCD_DITHERSEL_gp  0  /* dither select group position. */
#define TCD_DITHERSEL0_bm  (1<<0)  /* dither select bit 0 mask. */
#define TCD_DITHERSEL0_bp  0  /* dither select bit 0 position. */
#define TCD_DITHERSEL1_bm  (1<<1)  /* dither select bit 1 mask. */
#define TCD_DITHERSEL1_bp  1  /* dither select bit 1 position. */

/* TCD.DITVAL  bit masks and bit positions */
#define TCD_DITHER_gm  0x0F  /* Dither value group mask. */
#define TCD_DITHER_gp  0  /* Dither value group position. */
#define TCD_DITHER0_bm  (1<<0)  /* Dither value bit 0 mask. */
#define TCD_DITHER0_bp  0  /* Dither value bit 0 position. */
#define TCD_DITHER1_bm  (1<<1)  /* Dither value bit 1 mask. */
#define TCD_DITHER1_bp  1  /* Dither value bit 1 position. */
#define TCD_DITHER2_bm  (1<<2)  /* Dither value bit 2 mask. */
#define TCD_DITHER2_bp  2  /* Dither value bit 2 position. */
#define TCD_DITHER3_bm  (1<<3)  /* Dither value bit 3 mask. */
#define TCD_DITHER3_bp  3  /* Dither value bit 3 position. */

/* TCD.DBGCTRL  bit masks and bit positions */
#define TCD_DBGRUN_bm  0x01  /* Debug run bit mask. */
#define TCD_DBGRUN_bp  0  /* Debug run bit position. */
#define TCD_FAULTDET_bm  0x04  /* Fault detection bit mask. */
#define TCD_FAULTDET_bp  2  /* Fault detection bit position. */







/* TWI - Two-Wire Interface */
/* TWI.CTRLA  bit masks and bit positions */
#define TWI_FMPEN_bm  0x02  /* FM Plus Enable bit mask. */
#define TWI_FMPEN_bp  1  /* FM Plus Enable bit position. */
#define TWI_SDAHOLD_gm  0x0C  /* SDA Hold Time group mask. */
#define TWI_SDAHOLD_gp  2  /* SDA Hold Time group position. */
#define TWI_SDAHOLD0_bm  (1<<2)  /* SDA Hold Time bit 0 mask. */
#define TWI_SDAHOLD0_bp  2  /* SDA Hold Time bit 0 position. */
#define TWI_SDAHOLD1_bm  (1<<3)  /* SDA Hold Time bit 1 mask. */
#define TWI_SDAHOLD1_bp  3  /* SDA Hold Time bit 1 position. */
#define TWI_SDASETUP_bm  0x10  /* SDA Setup Time bit mask. */
#define TWI_SDASETUP_bp  4  /* SDA Setup Time bit position. */

/* TWI.DBGCTRL  bit masks and bit positions */
#define TWI_DBGRUN_bm  0x01  /* Debug Run bit mask. */
#define TWI_DBGRUN_bp  0  /* Debug Run bit position. */

/* TWI.MCTRLA  bit masks and bit positions */
#define TWI_ENABLE_bm  0x01  /* Enable TWI Master bit mask. */
#define TWI_ENABLE_bp  0  /* Enable TWI Master bit position. */
#define TWI_SMEN_bm  0x02  /* Smart Mode Enable bit mask. */
#define TWI_SMEN_bp  1  /* Smart Mode Enable bit position. */
#define TWI_TIMEOUT_gm  0x0C  /* Inactive Bus Timeout group mask. */
#define TWI_TIMEOUT_gp  2  /* Inactive Bus Timeout group position. */
#define TWI_TIMEOUT0_bm  (1<<2)  /* Inactive Bus Timeout bit 0 mask. */
#define TWI_TIMEOUT0_bp  2  /* Inactive Bus Timeout bit 0 position. */
#define TWI_TIMEOUT1_bm  (1<<3)  /* Inactive Bus Timeout bit 1 mask. */
#define TWI_TIMEOUT1_bp  3  /* Inactive Bus Timeout bit 1 position. */
#define TWI_QCEN_bm  0x10  /* Quick Command Enable bit mask. */
#define TWI_QCEN_bp  4  /* Quick Command Enable bit position. */
#define TWI_WIEN_bm  0x40  /* Write Interrupt Enable bit mask. */
#define TWI_WIEN_bp  6  /* Write Interrupt Enable bit position. */
#define TWI_RIEN_bm  0x80  /* Read Interrupt Enable bit mask. */
#define TWI_RIEN_bp  7  /* Read Interrupt Enable bit position. */

/* TWI.MCTRLB  bit masks and bit positions */
#define TWI_MCMD_gm  0x03  /* Command group mask. */
#define TWI_MCMD_gp  0  /* Command group position. */
#define TWI_MCMD0_bm  (1<<0)  /* Command bit 0 mask. */
#define TWI_MCMD0_bp  0  /* Command bit 0 position. */
#define TWI_MCMD1_bm  (1<<1)  /* Command bit 1 mask. */
#define TWI_MCMD1_bp  1  /* Command bit 1 position. */
#define TWI_ACKACT_bm  0x04  /* Acknowledge Action bit mask. */
#define TWI_ACKACT_bp  2  /* Acknowledge Action bit position. */
#define TWI_FLUSH_bm  0x08  /* Flush bit mask. */
#define TWI_FLUSH_bp  3  /* Flush bit position. */

/* TWI.MSTATUS  bit masks and bit positions */
#define TWI_BUSSTATE_gm  0x03  /* Bus State group mask. */
#define TWI_BUSSTATE_gp  0  /* Bus State group position. */
#define TWI_BUSSTATE0_bm  (1<<0)  /* Bus State bit 0 mask. */
#define TWI_BUSSTATE0_bp  0  /* Bus State bit 0 position. */
#define TWI_BUSSTATE1_bm  (1<<1)  /* Bus State bit 1 mask. */
#define TWI_BUSSTATE1_bp  1  /* Bus State bit 1 position. */
#define TWI_BUSERR_bm  0x04  /* Bus Error bit mask. */
#define TWI_BUSERR_bp  2  /* Bus Error bit position. */
#define TWI_ARBLOST_bm  0x08  /* Arbitration Lost bit mask. */
#define TWI_ARBLOST_bp  3  /* Arbitration Lost bit position. */
#define TWI_RXACK_bm  0x10  /* Received Acknowledge bit mask. */
#define TWI_RXACK_bp  4  /* Received Acknowledge bit position. */
#define TWI_CLKHOLD_bm  0x20  /* Clock Hold bit mask. */
#define TWI_CLKHOLD_bp  5  /* Clock Hold bit position. */
#define TWI_WIF_bm  0x40  /* Write Interrupt Flag bit mask. */
#define TWI_WIF_bp  6  /* Write Interrupt Flag bit position. */
#define TWI_RIF_bm  0x80  /* Read Interrupt Flag bit mask. */
#define TWI_RIF_bp  7  /* Read Interrupt Flag bit position. */




/* TWI.SCTRLA  bit masks and bit positions */
/* TWI_ENABLE  is already defined. */
/* TWI_SMEN  is already defined. */
#define TWI_PMEN_bm  0x04  /* Promiscuous Mode Enable bit mask. */
#define TWI_PMEN_bp  2  /* Promiscuous Mode Enable bit position. */
#define TWI_PIEN_bm  0x20  /* Stop Interrupt Enable bit mask. */
#define TWI_PIEN_bp  5  /* Stop Interrupt Enable bit position. */
#define TWI_APIEN_bm  0x40  /* Address/Stop Interrupt Enable bit mask. */
#define TWI_APIEN_bp  6  /* Address/Stop Interrupt Enable bit position. */
#define TWI_DIEN_bm  0x80  /* Data Interrupt Enable bit mask. */
#define TWI_DIEN_bp  7  /* Data Interrupt Enable bit position. */

/* TWI.SCTRLB  bit masks and bit positions */
#define TWI_SCMD_gm  0x03  /* Command group mask. */
#define TWI_SCMD_gp  0  /* Command group position. */
#define TWI_SCMD0_bm  (1<<0)  /* Command bit 0 mask. */
#define TWI_SCMD0_bp  0  /* Command bit 0 position. */
#define TWI_SCMD1_bm  (1<<1)  /* Command bit 1 mask. */
#define TWI_SCMD1_bp  1  /* Command bit 1 position. */
/* TWI_ACKACT  is already defined. */

/* TWI.SSTATUS  bit masks and bit positions */
#define TWI_AP_bm  0x01  /* Slave Address or Stop bit mask. */
#define TWI_AP_bp  0  /* Slave Address or Stop bit position. */
#define TWI_DIR_bm  0x02  /* Read/Write Direction bit mask. */
#define TWI_DIR_bp  1  /* Read/Write Direction bit position. */
/* TWI_BUSERR  is already defined. */
#define TWI_COLL_bm  0x08  /* Collision bit mask. */
#define TWI_COLL_bp  3  /* Collision bit position. */
/* TWI_RXACK  is already defined. */
/* TWI_CLKHOLD  is already defined. */
#define TWI_APIF_bm  0x40  /* Address/Stop Interrupt Flag bit mask. */
#define TWI_APIF_bp  6  /* Address/Stop Interrupt Flag bit position. */
#define TWI_DIF_bm  0x80  /* Data Interrupt Flag bit mask. */
#define TWI_DIF_bp  7  /* Data Interrupt Flag bit position. */



/* TWI.SADDRMASK  bit masks and bit positions */
#define TWI_ADDREN_bm  0x01  /* Address Enable bit mask. */
#define TWI_ADDREN_bp  0  /* Address Enable bit position. */
#define TWI_ADDRMASK_gm  0xFE  /* Address Mask group mask. */
#define TWI_ADDRMASK_gp  1  /* Address Mask group position. */
#define TWI_ADDRMASK0_bm  (1<<1)  /* Address Mask bit 0 mask. */
#define TWI_ADDRMASK0_bp  1  /* Address Mask bit 0 position. */
#define TWI_ADDRMASK1_bm  (1<<2)  /* Address Mask bit 1 mask. */
#define TWI_ADDRMASK1_bp  2  /* Address Mask bit 1 position. */
#define TWI_ADDRMASK2_bm  (1<<3)  /* Address Mask bit 2 mask. */
#define TWI_ADDRMASK2_bp  3  /* Address Mask bit 2 position. */
#define TWI_ADDRMASK3_bm  (1<<4)  /* Address Mask bit 3 mask. */
#define TWI_ADDRMASK3_bp  4  /* Address Mask bit 3 position. */
#define TWI_ADDRMASK4_bm  (1<<5)  /* Address Mask bit 4 mask. */
#define TWI_ADDRMASK4_bp  5  /* Address Mask bit 4 position. */
#define TWI_ADDRMASK5_bm  (1<<6)  /* Address Mask bit 5 mask. */
#define TWI_ADDRMASK5_bp  6  /* Address Mask bit 5 position. */
#define TWI_ADDRMASK6_bm  (1<<7)  /* Address Mask bit 6 mask. */
#define TWI_ADDRMASK6_bp  7  /* Address Mask bit 6 position. */

/* USART - Universal Synchronous and Asynchronous Receiver and Transmitter */
/* USART.RXDATAL  bit masks and bit positions */
#define USART_DATA_gm  0xFF  /* RX Data group mask. */
#define USART_DATA_gp  0  /* RX Data group position. */
#define USART_DATA0_bm  (1<<0)  /* RX Data bit 0 mask. */
#define USART_DATA0_bp  0  /* RX Data bit 0 position. */
#define USART_DATA1_bm  (1<<1)  /* RX Data bit 1 mask. */
#define USART_DATA1_bp  1  /* RX Data bit 1 position. */
#define USART_DATA2_bm  (1<<2)  /* RX Data bit 2 mask. */
#define USART_DATA2_bp  2  /* RX Data bit 2 position. */
#define USART_DATA3_bm  (1<<3)  /* RX Data bit 3 mask. */
#define USART_DATA3_bp  3  /* RX Data bit 3 position. */
#define USART_DATA4_bm  (1<<4)  /* RX Data bit 4 mask. */
#define USART_DATA4_bp  4  /* RX Data bit 4 position. */
#define USART_DATA5_bm  (1<<5)  /* RX Data bit 5 mask. */
#define USART_DATA5_bp  5  /* RX Data bit 5 position. */
#define USART_DATA6_bm  (1<<6)  /* RX Data bit 6 mask. */
#define USART_DATA6_bp  6  /* RX Data bit 6 position. */
#define USART_DATA7_bm  (1<<7)  /* RX Data bit 7 mask. */
#define USART_DATA7_bp  7  /* RX Data bit 7 position. */

/* USART.RXDATAH  bit masks and bit positions */
#define USART_DATA8_bm  0x01  /* Receiver Data Register bit mask. */
#define USART_DATA8_bp  0  /* Receiver Data Register bit position. */
#define USART_PERR_bm  0x02  /* Parity Error bit mask. */
#define USART_PERR_bp  1  /* Parity Error bit position. */
#define USART_FERR_bm  0x04  /* Frame Error bit mask. */
#define USART_FERR_bp  2  /* Frame Error bit position. */
#define USART_BUFOVF_bm  0x40  /* Buffer Overflow bit mask. */
#define USART_BUFOVF_bp  6  /* Buffer Overflow bit position. */
#define USART_RXCIF_bm  0x80  /* Receive Complete Interrupt Flag bit mask. */
#define USART_RXCIF_bp  7  /* Receive Complete Interrupt Flag bit position. */

/* USART.TXDATAL  bit masks and bit positions */
/* USART_DATA  is already defined. */

/* USART.TXDATAH  bit masks and bit positions */
/* USART_DATA8  is already defined. */

/* USART.STATUS  bit masks and bit positions */
#define USART_WFB_bm  0x01  /* Wait For Break bit mask. */
#define USART_WFB_bp  0  /* Wait For Break bit position. */
#define USART_BDF_bm  0x02  /* Break Detected Flag bit mask. */
#define USART_BDF_bp  1  /* Break Detected Flag bit position. */
#define USART_ISFIF_bm  0x08  /* Inconsistent Sync Field Interrupt Flag bit mask. */
#define USART_ISFIF_bp  3  /* Inconsistent Sync Field Interrupt Flag bit position. */
#define USART_RXSIF_bm  0x10  /* Receive Start Interrupt bit mask. */
#define USART_RXSIF_bp  4  /* Receive Start Interrupt bit position. */
#define USART_DREIF_bm  0x20  /* Data Register Empty Flag bit mask. */
#define USART_DREIF_bp  5  /* Data Register Empty Flag bit position. */
#define USART_TXCIF_bm  0x40  /* Transmit Interrupt Flag bit mask. */
#define USART_TXCIF_bp  6  /* Transmit Interrupt Flag bit position. */
/* USART_RXCIF  is already defined. */

/* USART.CTRLA  bit masks and bit positions */
#define USART_RS485_gm  0x03  /* RS485 Mode internal transmitter group mask. */
#define USART_RS485_gp  0  /* RS485 Mode internal transmitter group position. */
#define USART_RS4850_bm  (1<<0)  /* RS485 Mode internal transmitter bit 0 mask. */
#define USART_RS4850_bp  0  /* RS485 Mode internal transmitter bit 0 position. */
#define USART_RS4851_bm  (1<<1)  /* RS485 Mode internal transmitter bit 1 mask. */
#define USART_RS4851_bp  1  /* RS485 Mode internal transmitter bit 1 position. */
#define USART_ABEIE_bm  0x04  /* Auto-baud Error Interrupt Enable bit mask. */
#define USART_ABEIE_bp  2  /* Auto-baud Error Interrupt Enable bit position. */
#define USART_LBME_bm  0x08  /* Loop-back Mode Enable bit mask. */
#define USART_LBME_bp  3  /* Loop-back Mode Enable bit position. */
#define USART_RXSIE_bm  0x10  /* Receiver Start Frame Interrupt Enable bit mask. */
#define USART_RXSIE_bp  4  /* Receiver Start Frame Interrupt Enable bit position. */
#define USART_DREIE_bm  0x20  /* Data Register Empty Interrupt Enable bit mask. */
#define USART_DREIE_bp  5  /* Data Register Empty Interrupt Enable bit position. */
#define USART_TXCIE_bm  0x40  /* Transmit Complete Interrupt Enable bit mask. */
#define USART_TXCIE_bp  6  /* Transmit Complete Interrupt Enable bit position. */
#define USART_RXCIE_bm  0x80  /* Receive Complete Interrupt Enable bit mask. */
#define USART_RXCIE_bp  7  /* Receive Complete Interrupt Enable bit position. */

/* USART.CTRLB  bit masks and bit positions */
#define USART_MPCM_bm  0x01  /* Multi-processor Communication Mode bit mask. */
#define USART_MPCM_bp  0  /* Multi-processor Communication Mode bit position. */
#define USART_RXMODE_gm  0x06  /* Receiver Mode group mask. */
#define USART_RXMODE_gp  1  /* Receiver Mode group position. */
#define USART_RXMODE0_bm  (1<<1)  /* Receiver Mode bit 0 mask. */
#define USART_RXMODE0_bp  1  /* Receiver Mode bit 0 position. */
#define USART_RXMODE1_bm  (1<<2)  /* Receiver Mode bit 1 mask. */
#define USART_RXMODE1_bp  2  /* Receiver Mode bit 1 position. */
#define USART_ODME_bm  0x08  /* Open Drain Mode Enable bit mask. */
#define USART_ODME_bp  3  /* Open Drain Mode Enable bit position. */
#define USART_SFDEN_bm  0x10  /* Start Frame Detection Enable bit mask. */
#define USART_SFDEN_bp  4  /* Start Frame Detection Enable bit position. */
#define USART_TXEN_bm  0x40  /* Transmitter Enable bit mask. */
#define USART_TXEN_bp  6  /* Transmitter Enable bit position. */
#define USART_RXEN_bm  0x80  /* Reciever enable bit mask. */
#define USART_RXEN_bp  7  /* Reciever enable bit position. */

/* USART.CTRLC  bit masks and bit positions */
#define USART_UCPHA_bm  0x02  /* SPI Master Mode, Clock Phase bit mask. */
#define USART_UCPHA_bp  1  /* SPI Master Mode, Clock Phase bit position. */
#define USART_UDORD_bm  0x04  /* SPI Master Mode, Data Order bit mask. */
#define USART_UDORD_bp  2  /* SPI Master Mode, Data Order bit position. */
#define USART_CHSIZE_gm  0x07  /* Character Size group mask. */
#define USART_CHSIZE_gp  0  /* Character Size group position. */
#define USART_CHSIZE0_bm  (1<<0)  /* Character Size bit 0 mask. */
#define USART_CHSIZE0_bp  0  /* Character Size bit 0 position. */
#define USART_CHSIZE1_bm  (1<<1)  /* Character Size bit 1 mask. */
#define USART_CHSIZE1_bp  1  /* Character Size bit 1 position. */
#define USART_CHSIZE2_bm  (1<<2)  /* Character Size bit 2 mask. */
#define USART_CHSIZE2_bp  2  /* Character Size bit 2 position. */
#define USART_SBMODE_bm  0x08  /* Stop Bit Mode bit mask. */
#define USART_SBMODE_bp  3  /* Stop Bit Mode bit position. */
#define USART_PMODE_gm  0x30  /* Parity Mode group mask. */
#define USART_PMODE_gp  4  /* Parity Mode group position. */
#define USART_PMODE0_bm  (1<<4)  /* Parity Mode bit 0 mask. */
#define USART_PMODE0_bp  4  /* Parity Mode bit 0 position. */
#define USART_PMODE1_bm  (1<<5)  /* Parity Mode bit 1 mask. */
#define USART_PMODE1_bp  5  /* Parity Mode bit 1 position. */
#define USART_CMODE_gm  0xC0  /* Communication Mode group mask. */
#define USART_CMODE_gp  6  /* Communication Mode group position. */
#define USART_CMODE0_bm  (1<<6)  /* Communication Mode bit 0 mask. */
#define USART_CMODE0_bp  6  /* Communication Mode bit 0 position. */
#define USART_CMODE1_bm  (1<<7)  /* Communication Mode bit 1 mask. */
#define USART_CMODE1_bp  7  /* Communication Mode bit 1 position. */


/* USART.DBGCTRL  bit masks and bit positions */
#define USART_DBGRUN_bm  0x01  /* Debug Run bit mask. */
#define USART_DBGRUN_bp  0  /* Debug Run bit position. */

/* USART.EVCTRL  bit masks and bit positions */
#define USART_IREI_bm  0x01  /* IrDA Event Input Enable bit mask. */
#define USART_IREI_bp  0  /* IrDA Event Input Enable bit position. */

/* USART.TXPLCTRL  bit masks and bit positions */
#define USART_TXPL_gm  0xFF  /* Transmit pulse length group mask. */
#define USART_TXPL_gp  0  /* Transmit pulse length group position. */
#define USART_TXPL0_bm  (1<<0)  /* Transmit pulse length bit 0 mask. */
#define USART_TXPL0_bp  0  /* Transmit pulse length bit 0 position. */
#define USART_TXPL1_bm  (1<<1)  /* Transmit pulse length bit 1 mask. */
#define USART_TXPL1_bp  1  /* Transmit pulse length bit 1 position. */
#define USART_TXPL2_bm  (1<<2)  /* Transmit pulse length bit 2 mask. */
#define USART_TXPL2_bp  2  /* Transmit pulse length bit 2 position. */
#define USART_TXPL3_bm  (1<<3)  /* Transmit pulse length bit 3 mask. */
#define USART_TXPL3_bp  3  /* Transmit pulse length bit 3 position. */
#define USART_TXPL4_bm  (1<<4)  /* Transmit pulse length bit 4 mask. */
#define USART_TXPL4_bp  4  /* Transmit pulse length bit 4 position. */
#define USART_TXPL5_bm  (1<<5)  /* Transmit pulse length bit 5 mask. */
#define USART_TXPL5_bp  5  /* Transmit pulse length bit 5 position. */
#define USART_TXPL6_bm  (1<<6)  /* Transmit pulse length bit 6 mask. */
#define USART_TXPL6_bp  6  /* Transmit pulse length bit 6 position. */
#define USART_TXPL7_bm  (1<<7)  /* Transmit pulse length bit 7 mask. */
#define USART_TXPL7_bp  7  /* Transmit pulse length bit 7 position. */

/* USART.RXPLCTRL  bit masks and bit positions */
#define USART_RXPL_gm  0x7F  /* Receiver Pulse Lenght group mask. */
#define USART_RXPL_gp  0  /* Receiver Pulse Lenght group position. */
#define USART_RXPL0_bm  (1<<0)  /* Receiver Pulse Lenght bit 0 mask. */
#define USART_RXPL0_bp  0  /* Receiver Pulse Lenght bit 0 position. */
#define USART_RXPL1_bm  (1<<1)  /* Receiver Pulse Lenght bit 1 mask. */
#define USART_RXPL1_bp  1  /* Receiver Pulse Lenght bit 1 position. */
#define USART_RXPL2_bm  (1<<2)  /* Receiver Pulse Lenght bit 2 mask. */
#define USART_RXPL2_bp  2  /* Receiver Pulse Lenght bit 2 position. */
#define USART_RXPL3_bm  (1<<3)  /* Receiver Pulse Lenght bit 3 mask. */
#define USART_RXPL3_bp  3  /* Receiver Pulse Lenght bit 3 position. */
#define USART_RXPL4_bm  (1<<4)  /* Receiver Pulse Lenght bit 4 mask. */
#define USART_RXPL4_bp  4  /* Receiver Pulse Lenght bit 4 position. */
#define USART_RXPL5_bm  (1<<5)  /* Receiver Pulse Lenght bit 5 mask. */
#define USART_RXPL5_bp  5  /* Receiver Pulse Lenght bit 5 position. */
#define USART_RXPL6_bm  (1<<6)  /* Receiver Pulse Lenght bit 6 mask. */
#define USART_RXPL6_bp  6  /* Receiver Pulse Lenght bit 6 position. */




































/* VPORT - Virtual Ports */
/* VPORT.INTFLAGS  bit masks and bit positions */
#define VPORT_INT_gm  0xFF  /* Pin Interrupt group mask. */
#define VPORT_INT_gp  0  /* Pin Interrupt group position. */
#define VPORT_INT0_bm  (1<<0)  /* Pin Interrupt bit 0 mask. */
#define VPORT_INT0_bp  0  /* Pin Interrupt bit 0 position. */
#define VPORT_INT1_bm  (1<<1)  /* Pin Interrupt bit 1 mask. */
#define VPORT_INT1_bp  1  /* Pin Interrupt bit 1 position. */
#define VPORT_INT2_bm  (1<<2)  /* Pin Interrupt bit 2 mask. */
#define VPORT_INT2_bp  2  /* Pin Interrupt bit 2 position. */
#define VPORT_INT3_bm  (1<<3)  /* Pin Interrupt bit 3 mask. */
#define VPORT_INT3_bp  3  /* Pin Interrupt bit 3 position. */
#define VPORT_INT4_bm  (1<<4)  /* Pin Interrupt bit 4 mask. */
#define VPORT_INT4_bp  4  /* Pin Interrupt bit 4 position. */
#define VPORT_INT5_bm  (1<<5)  /* Pin Interrupt bit 5 mask. */
#define VPORT_INT5_bp  5  /* Pin Interrupt bit 5 position. */
#define VPORT_INT6_bm  (1<<6)  /* Pin Interrupt bit 6 mask. */
#define VPORT_INT6_bp  6  /* Pin Interrupt bit 6 position. */
#define VPORT_INT7_bm  (1<<7)  /* Pin Interrupt bit 7 mask. */
#define VPORT_INT7_bp  7  /* Pin Interrupt bit 7 position. */

/* VREF - Voltage reference */
/* VREF.CTRLA  bit masks and bit positions */
#define VREF_DAC0REFSEL_gm  0x07  /* DAC0/AC0 reference select group mask. */
#define VREF_DAC0REFSEL_gp  0  /* DAC0/AC0 reference select group position. */
#define VREF_DAC0REFSEL0_bm  (1<<0)  /* DAC0/AC0 reference select bit 0 mask. */
#define VREF_DAC0REFSEL0_bp  0  /* DAC0/AC0 reference select bit 0 position. */
#define VREF_DAC0REFSEL1_bm  (1<<1)  /* DAC0/AC0 reference select bit 1 mask. */
#define VREF_DAC0REFSEL1_bp  1  /* DAC0/AC0 reference select bit 1 position. */
#define VREF_DAC0REFSEL2_bm  (1<<2)  /* DAC0/AC0 reference select bit 2 mask. */
#define VREF_DAC0REFSEL2_bp  2  /* DAC0/AC0 reference select bit 2 position. */
#define VREF_ADC0REFSEL_gm  0x70  /* ADC0 reference select group mask. */
#define VREF_ADC0REFSEL_gp  4  /* ADC0 reference select group position. */
#define VREF_ADC0REFSEL0_bm  (1<<4)  /* ADC0 reference select bit 0 mask. */
#define VREF_ADC0REFSEL0_bp  4  /* ADC0 reference select bit 0 position. */
#define VREF_ADC0REFSEL1_bm  (1<<5)  /* ADC0 reference select bit 1 mask. */
#define VREF_ADC0REFSEL1_bp  5  /* ADC0 reference select bit 1 position. */
#define VREF_ADC0REFSEL2_bm  (1<<6)  /* ADC0 reference select bit 2 mask. */
#define VREF_ADC0REFSEL2_bp  6  /* ADC0 reference select bit 2 position. */

/* VREF.CTRLB  bit masks and bit positions */
#define VREF_DAC0REFEN_bm  0x01  /* DAC0/AC0 reference enable bit mask. */
#define VREF_DAC0REFEN_bp  0  /* DAC0/AC0 reference enable bit position. */
#define VREF_ADC0REFEN_bm  0x02  /* ADC0 reference enable bit mask. */
#define VREF_ADC0REFEN_bp  1  /* ADC0 reference enable bit position. */

/* WDT - Watch-Dog Timer */
/* WDT.CTRLA  bit masks and bit positions */
#define WDT_PERIOD_gm  0x0F  /* Period group mask. */
#define WDT_PERIOD_gp  0  /* Period group position. */
#define WDT_PERIOD0_bm  (1<<0)  /* Period bit 0 mask. */
#define WDT_PERIOD0_bp  0  /* Period bit 0 position. */
#define WDT_PERIOD1_bm  (1<<1)  /* Period bit 1 mask. */
#define WDT_PERIOD1_bp  1  /* Period bit 1 position. */
#define WDT_PERIOD2_bm  (1<<2)  /* Period bit 2 mask. */
#define WDT_PERIOD2_bp  2  /* Period bit 2 position. */
#define WDT_PERIOD3_bm  (1<<3)  /* Period bit 3 mask. */
#define WDT_PERIOD3_bp  3  /* Period bit 3 position. */
#define WDT_WINDOW_gm  0xF0  /* Window group mask. */
#define WDT_WINDOW_gp  4  /* Window group position. */
#define WDT_WINDOW0_bm  (1<<4)  /* Window bit 0 mask. */
#define WDT_WINDOW0_bp  4  /* Window bit 0 position. */
#define WDT_WINDOW1_bm  (1<<5)  /* Window bit 1 mask. */
#define WDT_WINDOW1_bp  5  /* Window bit 1 position. */
#define WDT_WINDOW2_bm  (1<<6)  /* Window bit 2 mask. */
#define WDT_WINDOW2_bp  6  /* Window bit 2 position. */
#define WDT_WINDOW3_bm  (1<<7)  /* Window bit 3 mask. */
#define WDT_WINDOW3_bp  7  /* Window bit 3 position. */

/* WDT.STATUS  bit masks and bit positions */
#define WDT_SYNCBUSY_bm  0x01  /* Syncronization busy bit mask. */
#define WDT_SYNCBUSY_bp  0  /* Syncronization busy bit position. */
#define WDT_LOCK_bm  0x80  /* Lock enable bit mask. */
#define WDT_LOCK_bp  7  /* Lock enable bit position. */



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

/* CRCSCAN interrupt vectors */
#define CRCSCAN_NMI_vect_num  1
#define CRCSCAN_NMI_vect      _VECTOR(1)  /*  */

/* BOD interrupt vectors */
#define BOD_VLM_vect_num  2
#define BOD_VLM_vect      _VECTOR(2)  /*  */

/* PORTA interrupt vectors */
#define PORTA_PORT_vect_num  3
#define PORTA_PORT_vect      _VECTOR(3)  /*  */

/* PORTB interrupt vectors */
#define PORTB_PORT_vect_num  4
#define PORTB_PORT_vect      _VECTOR(4)  /*  */

/* PORTC interrupt vectors */
#define PORTC_PORT_vect_num  5
#define PORTC_PORT_vect      _VECTOR(5)  /*  */

/* RTC interrupt vectors */
#define RTC_CNT_vect_num  6
#define RTC_CNT_vect      _VECTOR(6)  /*  */
#define RTC_PIT_vect_num  7
#define RTC_PIT_vect      _VECTOR(7)  /*  */

/* TCA0 interrupt vectors */
#define TCA0_LUNF_vect_num  8
#define TCA0_LUNF_vect      _VECTOR(8)  /*  */
#define TCA0_OVF_vect_num  8
#define TCA0_OVF_vect      _VECTOR(8)  /*  */
#define TCA0_HUNF_vect_num  9
#define TCA0_HUNF_vect      _VECTOR(9)  /*  */
#define TCA0_CMP0_vect_num  10
#define TCA0_CMP0_vect      _VECTOR(10)  /*  */
#define TCA0_LCMP0_vect_num  10
#define TCA0_LCMP0_vect      _VECTOR(10)  /*  */
#define TCA0_CMP1_vect_num  11
#define TCA0_CMP1_vect      _VECTOR(11)  /*  */
#define TCA0_LCMP1_vect_num  11
#define TCA0_LCMP1_vect      _VECTOR(11)  /*  */
#define TCA0_CMP2_vect_num  12
#define TCA0_CMP2_vect      _VECTOR(12)  /*  */
#define TCA0_LCMP2_vect_num  12
#define TCA0_LCMP2_vect      _VECTOR(12)  /*  */

/* TCB0 interrupt vectors */
#define TCB0_INT_vect_num  13
#define TCB0_INT_vect      _VECTOR(13)  /*  */

/* TCD0 interrupt vectors */
#define TCD0_OVF_vect_num  14
#define TCD0_OVF_vect      _VECTOR(14)  /*  */
#define TCD0_TRIG_vect_num  15
#define TCD0_TRIG_vect      _VECTOR(15)  /*  */

/* AC0 interrupt vectors */
#define AC0_AC_vect_num  16
#define AC0_AC_vect      _VECTOR(16)  /*  */

/* ADC0 interrupt vectors */
#define ADC0_RESRDY_vect_num  17
#define ADC0_RESRDY_vect      _VECTOR(17)  /*  */
#define ADC0_WCOMP_vect_num  18
#define ADC0_WCOMP_vect      _VECTOR(18)  /*  */

/* TWI0 interrupt vectors */
#define TWI0_TWIS_vect_num  19
#define TWI0_TWIS_vect      _VECTOR(19)  /*  */
#define TWI0_TWIM_vect_num  20
#define TWI0_TWIM_vect      _VECTOR(20)  /*  */

/* SPI0 interrupt vectors */
#define SPI0_INT_vect_num  21
#define SPI0_INT_vect      _VECTOR(21)  /*  */

/* USART0 interrupt vectors */
#define USART0_RXC_vect_num  22
#define USART0_RXC_vect      _VECTOR(22)  /*  */
#define USART0_DRE_vect_num  23
#define USART0_DRE_vect      _VECTOR(23)  /*  */
#define USART0_TXC_vect_num  24
#define USART0_TXC_vect      _VECTOR(24)  /*  */

/* NVMCTRL interrupt vectors */
#define NVMCTRL_EE_vect_num  25
#define NVMCTRL_EE_vect      _VECTOR(25)  /*  */

#define _VECTOR_SIZE 2 /* Size of individual vector. */
#define _VECTORS_SIZE (26 * _VECTOR_SIZE)


/* ========== Constants ========== */

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define DATAMEM_START     (0x0000)
#  define DATAMEM_SIZE      (40960)
#else
#  define DATAMEM_START     (0x0000U)
#  define DATAMEM_SIZE      (40960U)
#endif
#define DATAMEM_END       (DATAMEM_START + DATAMEM_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define EEPROM_START     (0x1400)
#  define EEPROM_SIZE      (128)
#  define EEPROM_PAGE_SIZE (32)
#else
#  define EEPROM_START     (0x1400U)
#  define EEPROM_SIZE      (128U)
#  define EEPROM_PAGE_SIZE (32U)
#endif
#define EEPROM_END       (EEPROM_START + EEPROM_SIZE - 1)

/* Added MAPPED_EEPROM segment names for avr-libc */
#define MAPPED_EEPROM_START     (EEPROM_START)
#define MAPPED_EEPROM_SIZE      (EEPROM_SIZE)
#define MAPPED_EEPROM_PAGE_SIZE (EEPROM_PAGE_SIZE)
#define MAPPED_EEPROM_END       (MAPPED_EEPROM_START + MAPPED_EEPROM_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define FUSES_START     (0x1280)
#  define FUSES_SIZE      (10)
#  define FUSES_PAGE_SIZE (32)
#else
#  define FUSES_START     (0x1280U)
#  define FUSES_SIZE      (10U)
#  define FUSES_PAGE_SIZE (32U)
#endif
#define FUSES_END       (FUSES_START + FUSES_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define INTERNAL_SRAM_START     (0x3E00)
#  define INTERNAL_SRAM_SIZE      (512)
#  define INTERNAL_SRAM_PAGE_SIZE (0)
#else
#  define INTERNAL_SRAM_START     (0x3E00U)
#  define INTERNAL_SRAM_SIZE      (512U)
#  define INTERNAL_SRAM_PAGE_SIZE (0U)
#endif
#define INTERNAL_SRAM_END       (INTERNAL_SRAM_START + INTERNAL_SRAM_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define IO_START     (0x0000)
#  define IO_SIZE      (4352)
#  define IO_PAGE_SIZE (0)
#else
#  define IO_START     (0x0000U)
#  define IO_SIZE      (4352U)
#  define IO_PAGE_SIZE (0U)
#endif
#define IO_END       (IO_START + IO_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define LOCKBITS_START     (0x128A)
#  define LOCKBITS_SIZE      (1)
#  define LOCKBITS_PAGE_SIZE (32)
#else
#  define LOCKBITS_START     (0x128AU)
#  define LOCKBITS_SIZE      (1U)
#  define LOCKBITS_PAGE_SIZE (32U)
#endif
#define LOCKBITS_END       (LOCKBITS_START + LOCKBITS_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define MAPPED_PROGMEM_START     (0x8000)
#  define MAPPED_PROGMEM_SIZE      (8192)
#  define MAPPED_PROGMEM_PAGE_SIZE (64)
#else
#  define MAPPED_PROGMEM_START     (0x8000U)
#  define MAPPED_PROGMEM_SIZE      (8192U)
#  define MAPPED_PROGMEM_PAGE_SIZE (64U)
#endif
#define MAPPED_PROGMEM_END       (MAPPED_PROGMEM_START + MAPPED_PROGMEM_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define PROD_SIGNATURES_START     (0x1103)
#  define PROD_SIGNATURES_SIZE      (61)
#  define PROD_SIGNATURES_PAGE_SIZE (64)
#else
#  define PROD_SIGNATURES_START     (0x1103U)
#  define PROD_SIGNATURES_SIZE      (61U)
#  define PROD_SIGNATURES_PAGE_SIZE (64U)
#endif
#define PROD_SIGNATURES_END       (PROD_SIGNATURES_START + PROD_SIGNATURES_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define SIGNATURES_START     (0x1100)
#  define SIGNATURES_SIZE      (3)
#  define SIGNATURES_PAGE_SIZE (64)
#else
#  define SIGNATURES_START     (0x1100U)
#  define SIGNATURES_SIZE      (3U)
#  define SIGNATURES_PAGE_SIZE (64U)
#endif
#define SIGNATURES_END       (SIGNATURES_START + SIGNATURES_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define USER_SIGNATURES_START     (0x1300)
#  define USER_SIGNATURES_SIZE      (32)
#  define USER_SIGNATURES_PAGE_SIZE (32)
#else
#  define USER_SIGNATURES_START     (0x1300U)
#  define USER_SIGNATURES_SIZE      (32U)
#  define USER_SIGNATURES_PAGE_SIZE (32U)
#endif
#define USER_SIGNATURES_END       (USER_SIGNATURES_START + USER_SIGNATURES_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define PROGMEM_START     (0x0000)
#  define PROGMEM_SIZE      (8192)
#  define PROGMEM_PAGE_SIZE (64)
#else
#  define PROGMEM_START     (0x0000U)
#  define PROGMEM_SIZE      (8192U)
#  define PROGMEM_PAGE_SIZE (64U)
#endif
#define PROGMEM_END       (PROGMEM_START + PROGMEM_SIZE - 1)

#define FLASHSTART   PROGMEM_START
#define FLASHEND     PROGMEM_END
#define RAMSTART     INTERNAL_SRAM_START
#define RAMSIZE      INTERNAL_SRAM_SIZE
#define RAMEND       INTERNAL_SRAM_END
#define E2END        EEPROM_END
#define E2PAGESIZE   EEPROM_PAGE_SIZE


/* ========== Fuses ========== */
#define FUSE_MEMORY_SIZE 10

/* Fuse Byte 0 (WDTCFG) */
#define FUSE_PERIOD0  (unsigned char)_BV(0)  /* Watchdog Timeout Period Bit 0 */
#define FUSE_PERIOD1  (unsigned char)_BV(1)  /* Watchdog Timeout Period Bit 1 */
#define FUSE_PERIOD2  (unsigned char)_BV(2)  /* Watchdog Timeout Period Bit 2 */
#define FUSE_PERIOD3  (unsigned char)_BV(3)  /* Watchdog Timeout Period Bit 3 */
#define FUSE_WINDOW0  (unsigned char)_BV(4)  /* Watchdog Window Timeout Period Bit 0 */
#define FUSE_WINDOW1  (unsigned char)_BV(5)  /* Watchdog Window Timeout Period Bit 1 */
#define FUSE_WINDOW2  (unsigned char)_BV(6)  /* Watchdog Window Timeout Period Bit 2 */
#define FUSE_WINDOW3  (unsigned char)_BV(7)  /* Watchdog Window Timeout Period Bit 3 */
#define FUSE0_DEFAULT  (0x0)
#define FUSE_WDTCFG_DEFAULT  (0x0)

/* Fuse Byte 1 (BODCFG) */
#define FUSE_SLEEP0  (unsigned char)_BV(0)  /* BOD Operation in Sleep Mode Bit 0 */
#define FUSE_SLEEP1  (unsigned char)_BV(1)  /* BOD Operation in Sleep Mode Bit 1 */
#define FUSE_ACTIVE0  (unsigned char)_BV(2)  /* BOD Operation in Active Mode Bit 0 */
#define FUSE_ACTIVE1  (unsigned char)_BV(3)  /* BOD Operation in Active Mode Bit 1 */
#define FUSE_SAMPFREQ  (unsigned char)_BV(4)  /* BOD Sample Frequency */
#define FUSE_LVL0  (unsigned char)_BV(5)  /* BOD Level Bit 0 */
#define FUSE_LVL1  (unsigned char)_BV(6)  /* BOD Level Bit 1 */
#define FUSE_LVL2  (unsigned char)_BV(7)  /* BOD Level Bit 2 */
#define FUSE1_DEFAULT  (0x0)
#define FUSE_BODCFG_DEFAULT  (0x0)

/* Fuse Byte 2 (OSCCFG) */
#define FUSE_FREQSEL0  (unsigned char)_BV(0)  /* Frequency Select Bit 0 */
#define FUSE_FREQSEL1  (unsigned char)_BV(1)  /* Frequency Select Bit 1 */
#define FUSE_OSCLOCK  (unsigned char)_BV(7)  /* Oscillator Lock */
#define FUSE2_DEFAULT  (0x2)
#define FUSE_OSCCFG_DEFAULT  (0x2)

/* Fuse Byte 3 Reserved */

/* Fuse Byte 4 (TCD0CFG) */
#define FUSE_CMPA  (unsigned char)_BV(0)  /* Compare A Default Output Value */
#define FUSE_CMPB  (unsigned char)_BV(1)  /* Compare B Default Output Value */
#define FUSE_CMPC  (unsigned char)_BV(2)  /* Compare C Default Output Value */
#define FUSE_CMPD  (unsigned char)_BV(3)  /* Compare D Default Output Value */
#define FUSE_CMPAEN  (unsigned char)_BV(4)  /* Compare A Output Enable */
#define FUSE_CMPBEN  (unsigned char)_BV(5)  /* Compare B Output Enable */
#define FUSE_CMPCEN  (unsigned char)_BV(6)  /* Compare C Output Enable */
#define FUSE_CMPDEN  (unsigned char)_BV(7)  /* Compare D Output Enable */
#define FUSE4_DEFAULT  (0x0)
#define FUSE_TCD0CFG_DEFAULT  (0x0)

/* Fuse Byte 5 (SYSCFG0) */
#define FUSE_EESAVE  (unsigned char)_BV(0)  /* EEPROM Save */
#define FUSE_RSTPINCFG0  (unsigned char)_BV(2)  /* Reset Pin Configuration Bit 0 */
#define FUSE_RSTPINCFG1  (unsigned char)_BV(3)  /* Reset Pin Configuration Bit 1 */
#define FUSE_CRCSRC0  (unsigned char)_BV(6)  /* CRC Source Bit 0 */
#define FUSE_CRCSRC1  (unsigned char)_BV(7)  /* CRC Source Bit 1 */
#define FUSE5_DEFAULT  (0xc4)
#define FUSE_SYSCFG0_DEFAULT  (0xc4)

/* Fuse Byte 6 (SYSCFG1) */
#define FUSE_SUT0  (unsigned char)_BV(0)  /* Startup Time Bit 0 */
#define FUSE_SUT1  (unsigned char)_BV(1)  /* Startup Time Bit 1 */
#define FUSE_SUT2  (unsigned char)_BV(2)  /* Startup Time Bit 2 */
#define FUSE6_DEFAULT  (0x7)
#define FUSE_SYSCFG1_DEFAULT  (0x7)

/* Fuse Byte 7 (APPEND) */
#define FUSE7_DEFAULT  (0x0)
#define FUSE_APPEND_DEFAULT  (0x0)

/* Fuse Byte 8 (BOOTEND) */
#define FUSE8_DEFAULT  (0x0)
#define FUSE_BOOTEND_DEFAULT  (0x0)

/* ========== Lock Bits ========== */
#define __LOCK_BITS_EXIST
#ifdef LOCKBITS_DEFAULT
#undef LOCKBITS_DEFAULT
#endif //LOCKBITS_DEFAULT
#define LOCKBITS_DEFAULT  (0xc5)

/* ========== Signature ========== */
#define SIGNATURE_0 0x1E
#define SIGNATURE_1 0x93
#define SIGNATURE_2 0x20


#endif /* #ifdef _AVR_ATTINY817_H_INCLUDED */

