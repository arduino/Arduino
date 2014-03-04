//*****************************************************************************
//
// Only include parts of code relevant for Energia device
//
//*****************************************************************************
#ifdef __MSP430FR5969__

/* --COPYRIGHT--,BSD
 * Copyright (c) 2013, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * --/COPYRIGHT--*/
#ifndef __HW_MEMMAP__
#define __HW_MEMMAP__

#define __DRIVERLIB_MSP430FR5XX_6XX_FAMILY__
//*****************************************************************************
//
// Include device specific header file
//
//*****************************************************************************
#include "msp430fr5969_modified.h"

#if defined(__IAR_SYSTEMS_ICC__)
#include "../deprecated/IAR/msp430fr5xx_6xxgeneric.h"
#elif defined(__TI_COMPILER_VERSION__)
#include "../deprecated/CCS/msp430fr5xx_6xxgeneric.h"
#elif defined(__GNUC__)
#include "msp430fr5xx_6xxgeneric.h"
#else
#include "msp430fr5xx_6xxgeneric.h"
#endif

#include "stdint.h"
#include "stdbool.h"

//*****************************************************************************
//
// SUCCESS and FAILURE for API return value
//
//*****************************************************************************
#define STATUS_SUCCESS  0x01
#define STATUS_FAIL     0x00

//*****************************************************************************
//
// The following are defines for the base address of the peripherals.
//
//*****************************************************************************
#ifdef __MSP430_HAS_ADC10_A__
                                                                        #define ADC10_A_BASE    __MSP430_BASEADDRESS_ADC10_A__
#endif
#ifdef __MSP430_HAS_ADC10_B__
                                                                        #define ADC10_B_BASE    __MSP430_BASEADDRESS_ADC10_B__
#endif
#ifdef __MSP430_HAS_ADC12_B__
                                                                        #define ADC12_B_BASE    __MSP430_BASEADDRESS_ADC12_B__
#endif
#ifdef __MSP430_HAS_ADC12_PLUS__
                                                                        #define ADC12_A_BASE    __MSP430_BASEADDRESS_ADC12_PLUS__
#endif
#ifdef __MSP430_HAS_AES256__
                                                                        #define AES256_BASE             __MSP430_BASEADDRESS_AES256__
#endif
#ifdef __MSP430_HAS_AES__
                                                                        #define AES_BASE                __MSP430_BASEADDRESS_AES__
#endif
#ifdef __MSP430_HAS_AUX_SUPPLY__
                                                                        #define AUX_SUPPLY_BASE __MSP430_BASEADDRESS_AUX_SUPPLY__
#endif
#ifdef __MSP430_HAS_BACKUP_RAM__
                                                                        #define BAK_RAM_BASE    __MSP430_BASEADDRESS_BACKUP_RAM__
#endif
#ifdef __MSP430_HAS_BATTERY_CHARGER__
                                                                        #define BAK_BATT_BASE   __MSP430_BASEADDRESS_BATTERY_CHARGER__
#endif
#ifdef __MSP430_HAS_CAP_SENSE_IO_0__
                                                                        #define CAP_TOUCH_0_BASE        __MSP430_BASEADDRESS_CAP_SENSE_IO_0__
#endif
#ifdef __MSP430_HAS_CAP_SENSE_IO_1__
                                                                        #define CAP_TOUCH_1_BASE        __MSP430_BASEADDRESS_CAP_SENSE_IO_1__
#endif
#ifdef __MSP430_HAS_COMPB__
                                                                        #define COMP_B_BASE             __MSP430_BASEADDRESS_COMPB__
#endif
#ifdef __MSP430_HAS_COMPD__
                                                                        #define COMP_D_BASE             __MSP430_BASEADDRESS_COMPD__
#endif
#ifdef __MSP430_HAS_COMP_E__
                                                                        #define COMP_E_BASE             __MSP430_BASEADDRESS_COMP_E__
#endif
#ifdef __MSP430_HAS_COMPE__
                                                                        #define __MSP430_BASEADDRESS_COMP_E__           __MSP430_BASEADDRESS_COMPE__
#ifndef COMP_E_VECTOR
#ifdef COMP_B_VECTOR
#define COMP_E_VECTOR COMP_B_VECTOR
#endif
#endif

#ifndef COMP_B_VECTOR
#ifdef COMP_E_VECTOR
#define COMP_B_VECTOR COMP_E_VECTOR
#endif
#endif
#endif

#ifdef __MSP430_HAS_COMP_E__
                                                                        #define __MSP430_BASEADDRESS_COMPE__            __MSP430_BASEADDRESS_COMP_E__
#ifndef COMP_B_VECTOR
#ifdef COMP_E_VECTOR
#define COMP_B_VECTOR COMP_E_VECTOR
#endif
#endif
#ifndef COMP_E_VECTOR
#ifdef COMP_B_VECTOR
#define COMP_E_VECTOR COMP_B_VECTOR
#endif
#endif
#endif
#ifdef __MSP430_HAS_CRC__
                                                                        #define CRC_BASE                __MSP430_BASEADDRESS_CRC__
#endif
#ifdef __MSP430_HAS_CS__

#ifndef __MSP430_BASEADDRESS_CS_A__
#define __MSP430_BASEADDRESS_CS_A__     __MSP430_BASEADDRESS_CS__
#endif
#endif
#ifdef __MSP430_HAS_CS_A__
                                                                        #define CS_BASE                 __MSP430_BASEADDRESS_CS_A__
#ifndef __MSP430_BASEADDRESS_CS__
#define __MSP430_BASEADDRESS_CS__     __MSP430_BASEADDRESS_CS_A__
#endif
#endif
#ifdef __MSP430_HAS_DAC12_2__
                                                                        #define DAC12_A_BASE    __MSP430_BASEADDRESS_DAC12_2__
#endif
#ifdef __MSP430_HAS_DMAX_3__
                                                                        #define DMA_BASE                __MSP430_BASEADDRESS_DMAX_3__
#endif
#ifdef __MSP430_HAS_DMAX_6__
                                                                        #define DMA_BASE                __MSP430_BASEADDRESS_DMAX_6__
#endif
#ifdef __MSP430_HAS_EUSCI_A0__
                                                                        #define EUSCI_A0_BASE           __MSP430_BASEADDRESS_EUSCI_A0__
#endif
#ifdef __MSP430_HAS_EUSCI_A1__
                                                                        #define EUSCI_A1_BASE           __MSP430_BASEADDRESS_EUSCI_A1__
#endif
#ifdef __MSP430_HAS_EUSCI_A2__
                                                                        #define EUSCI_A2_BASE           __MSP430_BASEADDRESS_EUSCI_A2__
#endif
#ifdef __MSP430_HAS_EUSCI_A3__
                                                                        #define EUSCI_A3_BASE           __MSP430_BASEADDRESS_EUSCI_A3__
#endif
#ifdef __MSP430_HAS_EUSCI_B0__
                                                                        #define EUSCI_B0_BASE           __MSP430_BASEADDRESS_EUSCI_B0__
#endif
#ifdef __MSP430_HAS_EUSCI_B1__
                                                                        #define EUSCI_B1_BASE           __MSP430_BASEADDRESS_EUSCI_B1__
#endif
#ifdef __MSP430_HAS_FLASH__
                                                                        #define FLASH_BASE              __MSP430_BASEADDRESS_FLASH__
#endif
#ifdef __MSP430_HAS_FRAM_FR5XX__
                                                                        #define FRAM_BASE               __MSP430_BASEADDRESS_FRAM_FR5XX__
#endif
#ifdef __MSP430_HAS_FRAM__
                                                                        #define FRAM_BASE               __MSP430_BASEADDRESS_FRAM__
#endif
#ifdef __MSP430_HAS_LCD_B__
                                                                        #define LCD_B_BASE              __MSP430_BASEADDRESS_LCD_B__
#endif
#ifdef __MSP430_HAS_LCD_C__
                                                                        #define LCD_C_BASE              __MSP430_BASEADDRESS_LCD_C__
#endif
#ifdef __MSP430_HAS_MPU_A__
                                                                        #define MPU_BASE                __MSP430_BASEADDRESS_MPU_A__
#ifndef __MSP430_BASEADDRESS_MPU__
#define __MSP430_BASEADDRESS_MPU__     __MSP430_BASEADDRESS_MPU_A__
#endif
#endif
#ifdef __MSP430_HAS_MPU__

#ifndef __MSP430_BASEADDRESS_MPU_A__
#define __MSP430_BASEADDRESS_MPU_A__     __MSP430_BASEADDRESS_MPU__
#endif
#endif
#ifdef __MSP430_HAS_MPY32__
                                                                        #define MPY32_BASE              __MSP430_BASEADDRESS_MPY32__
#endif
#ifdef __MSP430_HAS_PMM_FR5xx__
                                                                        #define PMM_BASE        __MSP430_BASEADDRESS_PMM_FR5xx__
#endif
#ifdef __MSP430_HAS_PMM_FRAM__
                                                                        #define PMM_BASE        __MSP430_BASEADDRESS_PMM_FRAM__
#endif
#ifdef __MSP430_HAS_PMM__
                                                                        #define PMM_BASE        __MSP430_BASEADDRESS_PMM__
#endif
#ifdef __MSP430_HAS_PORT10_R__
                                                                        #define P10_BASE                __MSP430_BASEADDRESS_PORT10_R__
#endif
#ifdef __MSP430_HAS_PORT11_R__
                                                                        #define P11_BASE                __MSP430_BASEADDRESS_PORT11_R__
#endif
#ifdef __MSP430_HAS_PORT1_MAPPING__
                                                                        #define P1MAP_BASE              __MSP430_BASEADDRESS_PORT1_MAPPING__
#endif
#ifdef __MSP430_HAS_PORT1_R__
                                                                        #define P1_BASE         __MSP430_BASEADDRESS_PORT1_R__
#endif
#ifdef __MSP430_HAS_PORT2_MAPPING__
                                                                        #define P2MAP_BASE      __MSP430_BASEADDRESS_PORT2_MAPPING__
#endif
#ifdef __MSP430_HAS_PORT2_R__
                                                                        #define P2_BASE         __MSP430_BASEADDRESS_PORT2_R__
#endif
#ifdef __MSP430_HAS_PORT3_MAPPING__
                                                                        #define P3MAP_BASE              __MSP430_BASEADDRESS_PORT3_MAPPING__
#endif
#ifdef __MSP430_HAS_PORT3_R__
                                                                        #define P3_BASE         __MSP430_BASEADDRESS_PORT3_R__
#endif
#ifdef __MSP430_HAS_PORT4_MAPPING__
                                                                        #define P4MAP_BASE              __MSP430_BASEADDRESS_PORT4_MAPPING__
#endif
#ifdef __MSP430_HAS_PORT4_R__
                                                                        #define P4_BASE         __MSP430_BASEADDRESS_PORT4_R__
#endif
#ifdef __MSP430_HAS_PORT5_R__
                                                                        #define P5_BASE         __MSP430_BASEADDRESS_PORT5_R__
#endif
#ifdef __MSP430_HAS_PORT6_R__
                                                                        #define P6_BASE         __MSP430_BASEADDRESS_PORT6_R__
#endif
#ifdef __MSP430_HAS_PORT7_R__
                                                                        #define P7_BASE         __MSP430_BASEADDRESS_PORT7_R__
#endif
#ifdef __MSP430_HAS_PORT8_R__
                                                                        #define P8_BASE         __MSP430_BASEADDRESS_PORT8_R__
#endif
#ifdef __MSP430_HAS_PORT9_R__
                                                                        #define P9_BASE         __MSP430_BASEADDRESS_PORT9_R__
#endif
#ifdef __MSP430_HAS_PORTA_R__
                                                                        #define PA_BASE         __MSP430_BASEADDRESS_PORTA_R__
#endif
#ifdef __MSP430_HAS_PORTB_R__
                                                                        #define PB_BASE         __MSP430_BASEADDRESS_PORTB_R__
#endif
#ifdef __MSP430_HAS_PORTC_R__
                                                                        #define PC_BASE         __MSP430_BASEADDRESS_PORTC_R__
#endif
#ifdef __MSP430_HAS_PORTD_R__
                                                                        #define PD_BASE         __MSP430_BASEADDRESS_PORTD_R__
#endif
#ifdef __MSP430_HAS_PORTE_R__
                                                                        #define PE_BASE         __MSP430_BASEADDRESS_PORTE_R__
#endif
#ifdef __MSP430_HAS_PORTF_R__
                                                                        #define PF_BASE         __MSP430_BASEADDRESS_PORTF_R__
#endif
#ifdef __MSP430_HAS_PORTJ_R__
                                                                        #define PJ_BASE         __MSP430_BASEADDRESS_PORTJ_R__
#endif
#ifdef __MSP430_HAS_PORT_MAPPING__
                                                                        #define PMAP_CTRL_BASE          __MSP430_BASEADDRESS_PORT_MAPPING__
#endif
#ifdef __MSP430_HAS_PU__
                                                                        #define LDOPWR_BASE             __MSP430_BASEADDRESS_PU__
#endif
#ifdef __MSP430_HAS_RC__
                                                                        #define RAM_BASE                __MSP430_BASEADDRESS_RC__
#endif
#ifdef __MSP430_HAS_REF_A__
                                                                        #define REF_A_BASE              __MSP430_BASEADDRESS_REF_A__
#endif
#ifdef __MSP430_HAS_REF__
                                                                        #define REF_BASE                __MSP430_BASEADDRESS_REF__
#endif
#ifdef __MSP430_HAS_RTC_B__
                                                                        #define RTC_B_BASE              __MSP430_BASEADDRESS_RTC_B__
#endif
#ifdef __MSP430_HAS_RTC_C__
                                                                        #define RTC_C_BASE              __MSP430_BASEADDRESS_RTC_C__
#endif
#ifdef __MSP430_HAS_RTC_D__
                                                                        #define RTC_D_BASE              __MSP430_BASEADDRESS_RTC_D__
#endif
#ifdef __MSP430_HAS_RTC__
                                                                        #define RTC_A_BASE              __MSP430_BASEADDRESS_RTC__
#endif
#ifdef __MSP430_HAS_SD24_B__
                                                                        #define SD24_BASE               __MSP430_BASEADDRESS_SD24_B__
#endif
#ifdef __MSP430_HAS_SFR__
                                                                    #define SFR_BASE            __MSP430_BASEADDRESS_SFR__
#endif
#ifdef __MSP430_HAS_SYS__
                                                                        #define SYS_BASE                __MSP430_BASEADDRESS_SYS__
#endif
#ifdef __MSP430_HAS_T0A3__
                                                                        #define TIMER_A0_BASE           __MSP430_BASEADDRESS_T0A3__
#endif
#ifdef __MSP430_HAS_T0A5__
                                                                        #define TIMER_A0_BASE           __MSP430_BASEADDRESS_T0A5__
#endif
#ifdef __MSP430_HAS_T0B3__
                                                                        #define TIMER_B0_BASE           __MSP430_BASEADDRESS_T0B3__
#endif
#ifdef __MSP430_HAS_T0B7__
                                                                        #define TIMER_B0_BASE           __MSP430_BASEADDRESS_T0B7__
#endif
#ifdef __MSP430_HAS_T0D3__
                                                                        #define TIMER_D0_BASE           __MSP430_BASEADDRESS_T0D3__
#endif
#ifdef __MSP430_HAS_T1A2__
                                                                        #define TIMER_A1_BASE           __MSP430_BASEADDRESS_T1A2__
#endif
#ifdef __MSP430_HAS_T1A3__
                                                                        #define TIMER_A1_BASE           __MSP430_BASEADDRESS_T1A3__
#endif
#ifdef __MSP430_HAS_T1B3__
                                                                        #define TIMER_B1_BASE           __MSP430_BASEADDRESS_T1B3__
#endif
#ifdef __MSP430_HAS_T1D3__
                                                                        #define TIMER_D1_BASE           __MSP430_BASEADDRESS_T1D3__
#endif
#ifdef __MSP430_HAS_T2A2__
                                                                        #define TIMER_A2_BASE           __MSP430_BASEADDRESS_T2A2__
#endif
#ifdef __MSP430_HAS_T2A3__
                                                                        #define TIMER_A2_BASE           __MSP430_BASEADDRESS_T2A3__
#endif
#ifdef __MSP430_HAS_T2B3__
                                                                        #define TIMER_B2_BASE           __MSP430_BASEADDRESS_T2B3__
#endif
#ifdef __MSP430_HAS_T3A2__
                                                                        #define TIMER_A3_BASE           __MSP430_BASEADDRESS_T3A2__
#endif
#ifdef __MSP430_HAS_TEV0__
                                                                        #define TEC0_BASE               __MSP430_BASEADDRESS_TEV0__
#endif
#ifdef __MSP430_HAS_TEV1__
                                                                        #define TEC1_BASE               __MSP430_BASEADDRESS_TEV1__
#endif
#ifdef __MSP430_HAS_UCS__
                                                                        #define UCS_BASE                __MSP430_BASEADDRESS_UCS__
#endif
#ifdef __MSP430_HAS_USB__
                                                                        #define USB_BASE                __MSP430_BASEADDRESS_USB__
#endif
#ifdef __MSP430_HAS_USCI_A0__
                                                                        #define USCI_A0_BASE            __MSP430_BASEADDRESS_USCI_A0__
#endif
#ifdef __MSP430_HAS_USCI_A1__
                                                                        #define USCI_A1_BASE            __MSP430_BASEADDRESS_USCI_A1__
#endif
#ifdef __MSP430_HAS_USCI_A2__
                                                                        #define USCI_A2_BASE            __MSP430_BASEADDRESS_USCI_A2__
#endif
#ifdef __MSP430_HAS_USCI_A3__
                                                                        #define USCI_A3_BASE            __MSP430_BASEADDRESS_USCI_A3__
#endif
#ifdef __MSP430_HAS_USCI_B0__
                                                                        #define USCI_B0_BASE            __MSP430_BASEADDRESS_USCI_B0__
#endif
#ifdef __MSP430_HAS_USCI_B1__
                                                                        #define USCI_B1_BASE            __MSP430_BASEADDRESS_USCI_B1__
#endif
#ifdef __MSP430_HAS_USCI_B2__
                                                                        #define USCI_B2_BASE            __MSP430_BASEADDRESS_USCI_B2__
#endif
#ifdef __MSP430_HAS_USCI_B3__
                                                                        #define USCI_B3_BASE            __MSP430_BASEADDRESS_USCI_B3__
#endif
#ifdef __MSP430_HAS_WDT_A__
                                                                        #define WDT_A_BASE                      __MSP430_BASEADDRESS_WDT_A__
#endif

#endif // #ifndef __HW_MEMMAP__

#endif
//*****************************************************************************
//
// Only include parts of code relevant for Energia device
//
//*****************************************************************************
#ifdef __MSP430F5529__

/* --COPYRIGHT--,BSD
 * Copyright (c) 2013, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * --/COPYRIGHT--*/
#ifndef __HW_MEMMAP__
#define __HW_MEMMAP__

#define __DRIVERLIB_MSP430F5XX_6XX_FAMILY__
//*****************************************************************************
//
// Include device specific header file
//
//*****************************************************************************
#include <msp430.h>

#if defined(__IAR_SYSTEMS_ICC__)
#include "../deprecated/IAR/msp430f5xx_6xxgeneric.h"
#elif defined(__TI_COMPILER_VERSION__)
#include "../deprecated/CCS/msp430f5xx_6xxgeneric.h"
#elif defined(__GNUC__)
#include "msp430f5xx_6xxgeneric.h"
#else
#include "msp430f5xx_6xxgeneric.h"
#endif

#include "stdint.h"
#include "stdbool.h"

//*****************************************************************************
//
// SUCCESS and FAILURE for API return value
//
//*****************************************************************************
#define STATUS_SUCCESS  0x01
#define STATUS_FAIL     0x00

//*****************************************************************************
//
// The following are defines for the base address of the peripherals.
//
//*****************************************************************************
#ifdef __MSP430_HAS_ADC10_A__
                                                                        #define ADC10_A_BASE    __MSP430_BASEADDRESS_ADC10_A__
#endif
#ifdef __MSP430_HAS_ADC10_B__
                                                                        #define ADC10_B_BASE    __MSP430_BASEADDRESS_ADC10_B__
#endif
#ifdef __MSP430_HAS_ADC12_B__
                                                                        #define ADC12_B_BASE    __MSP430_BASEADDRESS_ADC12_B__
#endif
#ifdef __MSP430_HAS_ADC12_PLUS__
                                                                        #define ADC12_A_BASE    __MSP430_BASEADDRESS_ADC12_PLUS__
#endif
#ifdef __MSP430_HAS_AES256__
                                                                        #define AES256_BASE             __MSP430_BASEADDRESS_AES256__
#endif
#ifdef __MSP430_HAS_AES__
                                                                        #define AES_BASE                __MSP430_BASEADDRESS_AES__
#endif
#ifdef __MSP430_HAS_AUX_SUPPLY__
                                                                        #define AUX_SUPPLY_BASE __MSP430_BASEADDRESS_AUX_SUPPLY__
#endif
#ifdef __MSP430_HAS_BACKUP_RAM__
                                                                        #define BAK_RAM_BASE    __MSP430_BASEADDRESS_BACKUP_RAM__
#endif
#ifdef __MSP430_HAS_BATTERY_CHARGER__
                                                                        #define BAK_BATT_BASE   __MSP430_BASEADDRESS_BATTERY_CHARGER__
#endif
#ifdef __MSP430_HAS_CAP_SENSE_IO_0__
                                                                        #define CAP_TOUCH_0_BASE        __MSP430_BASEADDRESS_CAP_SENSE_IO_0__
#endif
#ifdef __MSP430_HAS_CAP_SENSE_IO_1__
                                                                        #define CAP_TOUCH_1_BASE        __MSP430_BASEADDRESS_CAP_SENSE_IO_1__
#endif
#ifdef __MSP430_HAS_COMPB__
                                                                        #define COMP_B_BASE             __MSP430_BASEADDRESS_COMPB__
#endif
#ifdef __MSP430_HAS_COMPD__
                                                                        #define COMP_D_BASE             __MSP430_BASEADDRESS_COMPD__
#endif
#ifdef __MSP430_HAS_COMP_E__
                                                                        #define COMP_E_BASE             __MSP430_BASEADDRESS_COMP_E__
#endif
#ifdef __MSP430_HAS_COMP_E__
                                                                        #define __MSP430_BASEADDRESS_COMPE__            __MSP430_BASEADDRESS_COMP_E__
#endif
#ifdef __MSP430_HAS_CRC__
                                                                        #define CRC_BASE                __MSP430_BASEADDRESS_CRC__
#endif
#ifdef __MSP430_HAS_CS__
                                                                        #define CS_BASE                 __MSP430_BASEADDRESS_CS__
#endif
#ifdef __MSP430_HAS_DAC12_2__
                                                                        #define DAC12_A_BASE    __MSP430_BASEADDRESS_DAC12_2__
#endif
#ifdef __MSP430_HAS_DMAX_3__
                                                                        #define DMA_BASE                __MSP430_BASEADDRESS_DMAX_3__
#endif
#ifdef __MSP430_HAS_DMAX_6__
                                                                        #define DMA_BASE                __MSP430_BASEADDRESS_DMAX_6__
#endif
#ifdef __MSP430_HAS_EUSCI_A0__
                                                                        #define EUSCI_A0_BASE           __MSP430_BASEADDRESS_EUSCI_A0__
#endif
#ifdef __MSP430_HAS_EUSCI_A1__
                                                                        #define EUSCI_A1_BASE           __MSP430_BASEADDRESS_EUSCI_A1__
#endif
#ifdef __MSP430_HAS_EUSCI_A2__
                                                                        #define EUSCI_A2_BASE           __MSP430_BASEADDRESS_EUSCI_A2__
#endif
#ifdef __MSP430_HAS_EUSCI_A3__
                                                                        #define EUSCI_A3_BASE           __MSP430_BASEADDRESS_EUSCI_A3__
#endif
#ifdef __MSP430_HAS_EUSCI_B0__
                                                                        #define EUSCI_B0_BASE           __MSP430_BASEADDRESS_EUSCI_B0__
#endif
#ifdef __MSP430_HAS_EUSCI_B1__
                                                                        #define EUSCI_B1_BASE           __MSP430_BASEADDRESS_EUSCI_B1__
#endif
#ifdef __MSP430_HAS_FLASH__
                                                                        #define FLASH_BASE              __MSP430_BASEADDRESS_FLASH__
#endif
#ifdef __MSP430_HAS_FRAM_FR5XX__
                                                                        #define FRAM_BASE               __MSP430_BASEADDRESS_FRAM_FR5XX__
#endif
#ifdef __MSP430_HAS_FRAM__
                                                                        #define FRAM_BASE               __MSP430_BASEADDRESS_FRAM__
#endif
#ifdef __MSP430_HAS_LCD_B__
                                                                        #define LCD_B_BASE              __MSP430_BASEADDRESS_LCD_B__
#endif
#ifdef __MSP430_HAS_LCD_C__
                                                                        #define LCD_C_BASE              __MSP430_BASEADDRESS_LCD_C__
#endif
#ifdef __MSP430_HAS_MPU_A__
                                                                        #define MPU_BASE                __MSP430_BASEADDRESS_MPU_A__
#endif
#ifdef __MSP430_HAS_MPU__
                                                                        #define MPU_BASE        __MSP430_BASEADDRESS_MPU__
#endif
#ifdef __MSP430_HAS_MPY32__
                                                                        #define MPY32_BASE              __MSP430_BASEADDRESS_MPY32__
#endif
#ifdef __MSP430_HAS_PMM_FR5xx__
                                                                        #define PMM_BASE        __MSP430_BASEADDRESS_PMM_FR5xx__
#endif
#ifdef __MSP430_HAS_PMM_FRAM__
                                                                        #define PMM_BASE        __MSP430_BASEADDRESS_PMM_FRAM__
#endif
#ifdef __MSP430_HAS_PMM__
                                                                        #define PMM_BASE        __MSP430_BASEADDRESS_PMM__
#endif
#ifdef __MSP430_HAS_PORT10_R__
                                                                        #define P10_BASE                __MSP430_BASEADDRESS_PORT10_R__
#endif
#ifdef __MSP430_HAS_PORT11_R__
                                                                        #define P11_BASE                __MSP430_BASEADDRESS_PORT11_R__
#endif
#ifdef __MSP430_HAS_PORT1_MAPPING__
                                                                        #define P1MAP_BASE              __MSP430_BASEADDRESS_PORT1_MAPPING__
#endif
#ifdef __MSP430_HAS_PORT1_R__
                                                                        #define P1_BASE         __MSP430_BASEADDRESS_PORT1_R__
#endif
#ifdef __MSP430_HAS_PORT2_MAPPING__
                                                                        #define P2MAP_BASE      __MSP430_BASEADDRESS_PORT2_MAPPING__
#endif
#ifdef __MSP430_HAS_PORT2_R__
                                                                        #define P2_BASE         __MSP430_BASEADDRESS_PORT2_R__
#endif
#ifdef __MSP430_HAS_PORT3_MAPPING__
                                                                        #define P3MAP_BASE              __MSP430_BASEADDRESS_PORT3_MAPPING__
#endif
#ifdef __MSP430_HAS_PORT3_R__
                                                                        #define P3_BASE         __MSP430_BASEADDRESS_PORT3_R__
#endif
#ifdef __MSP430_HAS_PORT4_MAPPING__
                                                                        #define P4MAP_BASE              __MSP430_BASEADDRESS_PORT4_MAPPING__
#endif
#ifdef __MSP430_HAS_PORT4_R__
                                                                        #define P4_BASE         __MSP430_BASEADDRESS_PORT4_R__
#endif
#ifdef __MSP430_HAS_PORT5_R__
                                                                        #define P5_BASE         __MSP430_BASEADDRESS_PORT5_R__
#endif
#ifdef __MSP430_HAS_PORT6_R__
                                                                        #define P6_BASE         __MSP430_BASEADDRESS_PORT6_R__
#endif
#ifdef __MSP430_HAS_PORT7_R__
                                                                        #define P7_BASE         __MSP430_BASEADDRESS_PORT7_R__
#endif
#ifdef __MSP430_HAS_PORT8_R__
                                                                        #define P8_BASE         __MSP430_BASEADDRESS_PORT8_R__
#endif
#ifdef __MSP430_HAS_PORT9_R__
                                                                        #define P9_BASE         __MSP430_BASEADDRESS_PORT9_R__
#endif
#ifdef __MSP430_HAS_PORTA_R__
                                                                        #define PA_BASE         __MSP430_BASEADDRESS_PORTA_R__
#endif
#ifdef __MSP430_HAS_PORTB_R__
                                                                        #define PB_BASE         __MSP430_BASEADDRESS_PORTB_R__
#endif
#ifdef __MSP430_HAS_PORTC_R__
                                                                        #define PC_BASE         __MSP430_BASEADDRESS_PORTC_R__
#endif
#ifdef __MSP430_HAS_PORTD_R__
                                                                        #define PD_BASE         __MSP430_BASEADDRESS_PORTD_R__
#endif
#ifdef __MSP430_HAS_PORTE_R__
                                                                        #define PE_BASE         __MSP430_BASEADDRESS_PORTE_R__
#endif
#ifdef __MSP430_HAS_PORTF_R__
                                                                        #define PF_BASE         __MSP430_BASEADDRESS_PORTF_R__
#endif
#ifdef __MSP430_HAS_PORTJ_R__
                                                                        #define PJ_BASE         __MSP430_BASEADDRESS_PORTJ_R__
#endif
#ifdef __MSP430_HAS_PORT_MAPPING__
                                                                        #define PMAP_CTRL_BASE          __MSP430_BASEADDRESS_PORT_MAPPING__
#endif
#ifdef __MSP430_HAS_PU__
                                                                        #define LDOPWR_BASE             __MSP430_BASEADDRESS_PU__
#endif
#ifdef __MSP430_HAS_RC__
                                                                        #define RAM_BASE                __MSP430_BASEADDRESS_RC__
#endif
#ifdef __MSP430_HAS_REF_A__
                                                                        #define REF_A_BASE              __MSP430_BASEADDRESS_REF_A__
#endif
#ifdef __MSP430_HAS_REF__
                                                                        #define REF_BASE                __MSP430_BASEADDRESS_REF__
#endif
#ifdef __MSP430_HAS_RTC_B__
                                                                        #define RTC_B_BASE              __MSP430_BASEADDRESS_RTC_B__
#endif
#ifdef __MSP430_HAS_RTC_C__
                                                                        #define RTC_C_BASE              __MSP430_BASEADDRESS_RTC_C__
#endif
#ifdef __MSP430_HAS_RTC_D__
                                                                        #define RTC_D_BASE              __MSP430_BASEADDRESS_RTC_D__
#endif
#ifdef __MSP430_HAS_RTC__
                                                                        #define RTC_A_BASE              __MSP430_BASEADDRESS_RTC__
#endif
#ifdef __MSP430_HAS_SD24_B__
                                                                        #define SD24_BASE               __MSP430_BASEADDRESS_SD24_B__
#endif
#ifdef __MSP430_HAS_SFR__
                                                                    #define SFR_BASE            __MSP430_BASEADDRESS_SFR__
#endif
#ifdef __MSP430_HAS_SYS__
                                                                        #define SYS_BASE                __MSP430_BASEADDRESS_SYS__
#endif
#ifdef __MSP430_HAS_T0A3__
                                                                        #define TIMER_A0_BASE           __MSP430_BASEADDRESS_T0A3__
#endif
#ifdef __MSP430_HAS_T0A5__
                                                                        #define TIMER_A0_BASE           __MSP430_BASEADDRESS_T0A5__
#endif
#ifdef __MSP430_HAS_T0B3__
                                                                        #define TIMER_B0_BASE           __MSP430_BASEADDRESS_T0B3__
#endif
#ifdef __MSP430_HAS_T0B7__
                                                                        #define TIMER_B0_BASE           __MSP430_BASEADDRESS_T0B7__
#endif
#ifdef __MSP430_HAS_T0D3__
                                                                        #define TIMER_D0_BASE           __MSP430_BASEADDRESS_T0D3__
#endif
#ifdef __MSP430_HAS_T1A2__
                                                                        #define TIMER_A1_BASE           __MSP430_BASEADDRESS_T1A2__
#endif
#ifdef __MSP430_HAS_T1A3__
                                                                        #define TIMER_A1_BASE           __MSP430_BASEADDRESS_T1A3__
#endif
#ifdef __MSP430_HAS_T1B3__
                                                                        #define TIMER_B1_BASE           __MSP430_BASEADDRESS_T1B3__
#endif
#ifdef __MSP430_HAS_T1D3__
                                                                        #define TIMER_D1_BASE           __MSP430_BASEADDRESS_T1D3__
#endif
#ifdef __MSP430_HAS_T2A2__
                                                                        #define TIMER_A2_BASE           __MSP430_BASEADDRESS_T2A2__
#endif
#ifdef __MSP430_HAS_T2A3__
                                                                        #define TIMER_A2_BASE           __MSP430_BASEADDRESS_T2A3__
#endif
#ifdef __MSP430_HAS_T2B3__
                                                                        #define TIMER_B2_BASE           __MSP430_BASEADDRESS_T2B3__
#endif
#ifdef __MSP430_HAS_T3A2__
                                                                        #define TIMER_A3_BASE           __MSP430_BASEADDRESS_T3A2__
#endif
#ifdef __MSP430_HAS_TEV0__
                                                                        #define TEC0_BASE               __MSP430_BASEADDRESS_TEV0__
#endif
#ifdef __MSP430_HAS_TEV1__
                                                                        #define TEC1_BASE               __MSP430_BASEADDRESS_TEV1__
#endif
#ifdef __MSP430_HAS_UCS__
                                                                        #define UCS_BASE                __MSP430_BASEADDRESS_UCS__
#endif
#ifdef __MSP430_HAS_USB__
                                                                        #define USB_BASE                __MSP430_BASEADDRESS_USB__
#endif
#ifdef __MSP430_HAS_USCI_A0__
                                                                        #define USCI_A0_BASE            __MSP430_BASEADDRESS_USCI_A0__
#endif
#ifdef __MSP430_HAS_USCI_A1__
                                                                        #define USCI_A1_BASE            __MSP430_BASEADDRESS_USCI_A1__
#endif
#ifdef __MSP430_HAS_USCI_A2__
                                                                        #define USCI_A2_BASE            __MSP430_BASEADDRESS_USCI_A2__
#endif
#ifdef __MSP430_HAS_USCI_A3__
                                                                        #define USCI_A3_BASE            __MSP430_BASEADDRESS_USCI_A3__
#endif
#ifdef __MSP430_HAS_USCI_B0__
                                                                        #define USCI_B0_BASE            __MSP430_BASEADDRESS_USCI_B0__
#endif
#ifdef __MSP430_HAS_USCI_B1__
                                                                        #define USCI_B1_BASE            __MSP430_BASEADDRESS_USCI_B1__
#endif
#ifdef __MSP430_HAS_USCI_B2__
                                                                        #define USCI_B2_BASE            __MSP430_BASEADDRESS_USCI_B2__
#endif
#ifdef __MSP430_HAS_USCI_B3__
                                                                        #define USCI_B3_BASE            __MSP430_BASEADDRESS_USCI_B3__
#endif
#ifdef __MSP430_HAS_WDT_A__
                                                                        #define WDT_A_BASE                      __MSP430_BASEADDRESS_WDT_A__
#endif

#endif // #ifndef __HW_MEMMAP__

#endif
//*****************************************************************************
//
// Only include parts of code relevant for Energia device
//
//*****************************************************************************
#ifdef __MSP430FR5739__

/* --COPYRIGHT--,BSD
 * Copyright (c) 2013, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * --/COPYRIGHT--*/
#ifndef __HW_MEMMAP__
#define __HW_MEMMAP__

#define __DRIVERLIB_MSP430FR57XX_FAMILY__
//*****************************************************************************
//
// Include device specific header file
//
//*****************************************************************************
#include <msp430.h>

#if defined(__IAR_SYSTEMS_ICC__)
#include "../deprecated/IAR/msp430fr57xxgeneric.h"
#elif defined(__TI_COMPILER_VERSION__)
#include "../deprecated/CCS/msp430fr57xxgeneric.h"
#elif defined(__GNUC__)
#include "msp430fr57xxgeneric.h"
#else
#include "msp430fr57xxgeneric.h"
#endif

#include "stdint.h"
#include "stdbool.h"

//*****************************************************************************
//
// SUCCESS and FAILURE for API return value
//
//*****************************************************************************
#define STATUS_SUCCESS  0x01
#define STATUS_FAIL     0x00

//*****************************************************************************
//
// The following are defines for the base address of the peripherals.
//
//*****************************************************************************
#ifdef __MSP430_HAS_ADC10_A__
                                                                        #define ADC10_A_BASE    __MSP430_BASEADDRESS_ADC10_A__
#endif
#ifdef __MSP430_HAS_ADC10_B__
                                                                        #define ADC10_B_BASE    __MSP430_BASEADDRESS_ADC10_B__
#endif
#ifdef __MSP430_HAS_ADC12_B__
                                                                        #define ADC12_B_BASE    __MSP430_BASEADDRESS_ADC12_B__
#endif
#ifdef __MSP430_HAS_ADC12_PLUS__
                                                                        #define ADC12_A_BASE    __MSP430_BASEADDRESS_ADC12_PLUS__
#endif
#ifdef __MSP430_HAS_AES256__
                                                                        #define AES256_BASE             __MSP430_BASEADDRESS_AES256__
#endif
#ifdef __MSP430_HAS_AES__
                                                                        #define AES_BASE                __MSP430_BASEADDRESS_AES__
#endif
#ifdef __MSP430_HAS_AUX_SUPPLY__
                                                                        #define AUX_SUPPLY_BASE __MSP430_BASEADDRESS_AUX_SUPPLY__
#endif
#ifdef __MSP430_HAS_BACKUP_RAM__
                                                                        #define BAK_RAM_BASE    __MSP430_BASEADDRESS_BACKUP_RAM__
#endif
#ifdef __MSP430_HAS_BATTERY_CHARGER__
                                                                        #define BAK_BATT_BASE   __MSP430_BASEADDRESS_BATTERY_CHARGER__
#endif
#ifdef __MSP430_HAS_CAP_SENSE_IO_0__
                                                                        #define CAP_TOUCH_0_BASE        __MSP430_BASEADDRESS_CAP_SENSE_IO_0__
#endif
#ifdef __MSP430_HAS_CAP_SENSE_IO_1__
                                                                        #define CAP_TOUCH_1_BASE        __MSP430_BASEADDRESS_CAP_SENSE_IO_1__
#endif
#ifdef __MSP430_HAS_COMPB__
                                                                        #define COMP_B_BASE             __MSP430_BASEADDRESS_COMPB__
#endif
#ifdef __MSP430_HAS_COMPD__
                                                                        #define COMP_D_BASE             __MSP430_BASEADDRESS_COMPD__
#endif
#ifdef __MSP430_HAS_COMP_E__
                                                                        #define COMP_E_BASE             __MSP430_BASEADDRESS_COMP_E__
#endif
#ifdef __MSP430_HAS_COMP_E__
                                                                        #define __MSP430_BASEADDRESS_COMPE__            __MSP430_BASEADDRESS_COMP_E__
#endif
#ifdef __MSP430_HAS_CRC__
                                                                        #define CRC_BASE                __MSP430_BASEADDRESS_CRC__
#endif
#ifdef __MSP430_HAS_CS__
                                                                        #define CS_BASE                 __MSP430_BASEADDRESS_CS__
#endif
#ifdef __MSP430_HAS_DAC12_2__
                                                                        #define DAC12_A_BASE    __MSP430_BASEADDRESS_DAC12_2__
#endif
#ifdef __MSP430_HAS_DMAX_3__
                                                                        #define DMA_BASE                __MSP430_BASEADDRESS_DMAX_3__
#endif
#ifdef __MSP430_HAS_DMAX_6__
                                                                        #define DMA_BASE                __MSP430_BASEADDRESS_DMAX_6__
#endif
#ifdef __MSP430_HAS_EUSCI_A0__
                                                                        #define EUSCI_A0_BASE           __MSP430_BASEADDRESS_EUSCI_A0__
#endif
#ifdef __MSP430_HAS_EUSCI_A1__
                                                                        #define EUSCI_A1_BASE           __MSP430_BASEADDRESS_EUSCI_A1__
#endif
#ifdef __MSP430_HAS_EUSCI_A2__
                                                                        #define EUSCI_A2_BASE           __MSP430_BASEADDRESS_EUSCI_A2__
#endif
#ifdef __MSP430_HAS_EUSCI_A3__
                                                                        #define EUSCI_A3_BASE           __MSP430_BASEADDRESS_EUSCI_A3__
#endif
#ifdef __MSP430_HAS_EUSCI_B0__
                                                                        #define EUSCI_B0_BASE           __MSP430_BASEADDRESS_EUSCI_B0__
#endif
#ifdef __MSP430_HAS_EUSCI_B1__
                                                                        #define EUSCI_B1_BASE           __MSP430_BASEADDRESS_EUSCI_B1__
#endif
#ifdef __MSP430_HAS_FLASH__
                                                                        #define FLASH_BASE              __MSP430_BASEADDRESS_FLASH__
#endif
#ifdef __MSP430_HAS_FRAM_FR5XX__
                                                                        #define FRAM_BASE               __MSP430_BASEADDRESS_FRAM_FR5XX__
#endif
#ifdef __MSP430_HAS_FRAM__
                                                                        #define FRAM_BASE               __MSP430_BASEADDRESS_FRAM__
#endif
#ifdef __MSP430_HAS_LCD_B__
                                                                        #define LCD_B_BASE              __MSP430_BASEADDRESS_LCD_B__
#endif
#ifdef __MSP430_HAS_LCD_C__
                                                                        #define LCD_C_BASE              __MSP430_BASEADDRESS_LCD_C__
#endif
#ifdef __MSP430_HAS_MPU_A__
                                                                        #define MPU_BASE                __MSP430_BASEADDRESS_MPU_A__
#endif
#ifdef __MSP430_HAS_MPU__
                                                                        #define MPU_BASE        __MSP430_BASEADDRESS_MPU__
#endif
#ifdef __MSP430_HAS_MPY32__
                                                                        #define MPY32_BASE              __MSP430_BASEADDRESS_MPY32__
#endif
#ifdef __MSP430_HAS_PMM_FR5xx__
                                                                        #define PMM_BASE        __MSP430_BASEADDRESS_PMM_FR5xx__
#endif
#ifdef __MSP430_HAS_PMM_FRAM__
                                                                        #define PMM_BASE        __MSP430_BASEADDRESS_PMM_FRAM__
#endif
#ifdef __MSP430_HAS_PMM__
                                                                        #define PMM_BASE        __MSP430_BASEADDRESS_PMM__
#endif
#ifdef __MSP430_HAS_PORT10_R__
                                                                        #define P10_BASE                __MSP430_BASEADDRESS_PORT10_R__
#endif
#ifdef __MSP430_HAS_PORT11_R__
                                                                        #define P11_BASE                __MSP430_BASEADDRESS_PORT11_R__
#endif
#ifdef __MSP430_HAS_PORT1_MAPPING__
                                                                        #define P1MAP_BASE              __MSP430_BASEADDRESS_PORT1_MAPPING__
#endif
#ifdef __MSP430_HAS_PORT1_R__
                                                                        #define P1_BASE         __MSP430_BASEADDRESS_PORT1_R__
#endif
#ifdef __MSP430_HAS_PORT2_MAPPING__
                                                                        #define P2MAP_BASE      __MSP430_BASEADDRESS_PORT2_MAPPING__
#endif
#ifdef __MSP430_HAS_PORT2_R__
                                                                        #define P2_BASE         __MSP430_BASEADDRESS_PORT2_R__
#endif
#ifdef __MSP430_HAS_PORT3_MAPPING__
                                                                        #define P3MAP_BASE              __MSP430_BASEADDRESS_PORT3_MAPPING__
#endif
#ifdef __MSP430_HAS_PORT3_R__
                                                                        #define P3_BASE         __MSP430_BASEADDRESS_PORT3_R__
#endif
#ifdef __MSP430_HAS_PORT4_MAPPING__
                                                                        #define P4MAP_BASE              __MSP430_BASEADDRESS_PORT4_MAPPING__
#endif
#ifdef __MSP430_HAS_PORT4_R__
                                                                        #define P4_BASE         __MSP430_BASEADDRESS_PORT4_R__
#endif
#ifdef __MSP430_HAS_PORT5_R__
                                                                        #define P5_BASE         __MSP430_BASEADDRESS_PORT5_R__
#endif
#ifdef __MSP430_HAS_PORT6_R__
                                                                        #define P6_BASE         __MSP430_BASEADDRESS_PORT6_R__
#endif
#ifdef __MSP430_HAS_PORT7_R__
                                                                        #define P7_BASE         __MSP430_BASEADDRESS_PORT7_R__
#endif
#ifdef __MSP430_HAS_PORT8_R__
                                                                        #define P8_BASE         __MSP430_BASEADDRESS_PORT8_R__
#endif
#ifdef __MSP430_HAS_PORT9_R__
                                                                        #define P9_BASE         __MSP430_BASEADDRESS_PORT9_R__
#endif
#ifdef __MSP430_HAS_PORTA_R__
                                                                        #define PA_BASE         __MSP430_BASEADDRESS_PORTA_R__
#endif
#ifdef __MSP430_HAS_PORTB_R__
                                                                        #define PB_BASE         __MSP430_BASEADDRESS_PORTB_R__
#endif
#ifdef __MSP430_HAS_PORTC_R__
                                                                        #define PC_BASE         __MSP430_BASEADDRESS_PORTC_R__
#endif
#ifdef __MSP430_HAS_PORTD_R__
                                                                        #define PD_BASE         __MSP430_BASEADDRESS_PORTD_R__
#endif
#ifdef __MSP430_HAS_PORTE_R__
                                                                        #define PE_BASE         __MSP430_BASEADDRESS_PORTE_R__
#endif
#ifdef __MSP430_HAS_PORTF_R__
                                                                        #define PF_BASE         __MSP430_BASEADDRESS_PORTF_R__
#endif
#ifdef __MSP430_HAS_PORTJ_R__
                                                                        #define PJ_BASE         __MSP430_BASEADDRESS_PORTJ_R__
#endif
#ifdef __MSP430_HAS_PORT_MAPPING__
                                                                        #define PMAP_CTRL_BASE          __MSP430_BASEADDRESS_PORT_MAPPING__
#endif
#ifdef __MSP430_HAS_PU__
                                                                        #define LDOPWR_BASE             __MSP430_BASEADDRESS_PU__
#endif
#ifdef __MSP430_HAS_RC__
                                                                        #define RAM_BASE                __MSP430_BASEADDRESS_RC__
#endif
#ifdef __MSP430_HAS_REF_A__
                                                                        #define REF_A_BASE              __MSP430_BASEADDRESS_REF_A__
#endif
#ifdef __MSP430_HAS_REF__
                                                                        #define REF_BASE                __MSP430_BASEADDRESS_REF__
#endif
#ifdef __MSP430_HAS_RTC_B__
                                                                        #define RTC_B_BASE              __MSP430_BASEADDRESS_RTC_B__
#endif
#ifdef __MSP430_HAS_RTC_C__
                                                                        #define RTC_C_BASE              __MSP430_BASEADDRESS_RTC_C__
#endif
#ifdef __MSP430_HAS_RTC_D__
                                                                        #define RTC_D_BASE              __MSP430_BASEADDRESS_RTC_D__
#endif
#ifdef __MSP430_HAS_RTC__
                                                                        #define RTC_A_BASE              __MSP430_BASEADDRESS_RTC__
#endif
#ifdef __MSP430_HAS_SD24_B__
                                                                        #define SD24_BASE               __MSP430_BASEADDRESS_SD24_B__
#endif
#ifdef __MSP430_HAS_SFR__
                                                                    #define SFR_BASE            __MSP430_BASEADDRESS_SFR__
#endif
#ifdef __MSP430_HAS_SYS__
                                                                        #define SYS_BASE                __MSP430_BASEADDRESS_SYS__
#endif
#ifdef __MSP430_HAS_T0A3__
                                                                        #define TIMER_A0_BASE           __MSP430_BASEADDRESS_T0A3__
#endif
#ifdef __MSP430_HAS_T0A5__
                                                                        #define TIMER_A0_BASE           __MSP430_BASEADDRESS_T0A5__
#endif
#ifdef __MSP430_HAS_T0B3__
                                                                        #define TIMER_B0_BASE           __MSP430_BASEADDRESS_T0B3__
#endif
#ifdef __MSP430_HAS_T0B7__
                                                                        #define TIMER_B0_BASE           __MSP430_BASEADDRESS_T0B7__
#endif
#ifdef __MSP430_HAS_T0D3__
                                                                        #define TIMER_D0_BASE           __MSP430_BASEADDRESS_T0D3__
#endif
#ifdef __MSP430_HAS_T1A2__
                                                                        #define TIMER_A1_BASE           __MSP430_BASEADDRESS_T1A2__
#endif
#ifdef __MSP430_HAS_T1A3__
                                                                        #define TIMER_A1_BASE           __MSP430_BASEADDRESS_T1A3__
#endif
#ifdef __MSP430_HAS_T1B3__
                                                                        #define TIMER_B1_BASE           __MSP430_BASEADDRESS_T1B3__
#endif
#ifdef __MSP430_HAS_T1D3__
                                                                        #define TIMER_D1_BASE           __MSP430_BASEADDRESS_T1D3__
#endif
#ifdef __MSP430_HAS_T2A2__
                                                                        #define TIMER_A2_BASE           __MSP430_BASEADDRESS_T2A2__
#endif
#ifdef __MSP430_HAS_T2A3__
                                                                        #define TIMER_A2_BASE           __MSP430_BASEADDRESS_T2A3__
#endif
#ifdef __MSP430_HAS_T2B3__
                                                                        #define TIMER_B2_BASE           __MSP430_BASEADDRESS_T2B3__
#endif
#ifdef __MSP430_HAS_T3A2__
                                                                        #define TIMER_A3_BASE           __MSP430_BASEADDRESS_T3A2__
#endif
#ifdef __MSP430_HAS_TEV0__
                                                                        #define TEC0_BASE               __MSP430_BASEADDRESS_TEV0__
#endif
#ifdef __MSP430_HAS_TEV1__
                                                                        #define TEC1_BASE               __MSP430_BASEADDRESS_TEV1__
#endif
#ifdef __MSP430_HAS_UCS__
                                                                        #define UCS_BASE                __MSP430_BASEADDRESS_UCS__
#endif
#ifdef __MSP430_HAS_USB__
                                                                        #define USB_BASE                __MSP430_BASEADDRESS_USB__
#endif
#ifdef __MSP430_HAS_USCI_A0__
                                                                        #define USCI_A0_BASE            __MSP430_BASEADDRESS_USCI_A0__
#endif
#ifdef __MSP430_HAS_USCI_A1__
                                                                        #define USCI_A1_BASE            __MSP430_BASEADDRESS_USCI_A1__
#endif
#ifdef __MSP430_HAS_USCI_A2__
                                                                        #define USCI_A2_BASE            __MSP430_BASEADDRESS_USCI_A2__
#endif
#ifdef __MSP430_HAS_USCI_A3__
                                                                        #define USCI_A3_BASE            __MSP430_BASEADDRESS_USCI_A3__
#endif
#ifdef __MSP430_HAS_USCI_B0__
                                                                        #define USCI_B0_BASE            __MSP430_BASEADDRESS_USCI_B0__
#endif
#ifdef __MSP430_HAS_USCI_B1__
                                                                        #define USCI_B1_BASE            __MSP430_BASEADDRESS_USCI_B1__
#endif
#ifdef __MSP430_HAS_USCI_B2__
                                                                        #define USCI_B2_BASE            __MSP430_BASEADDRESS_USCI_B2__
#endif
#ifdef __MSP430_HAS_USCI_B3__
                                                                        #define USCI_B3_BASE            __MSP430_BASEADDRESS_USCI_B3__
#endif
#ifdef __MSP430_HAS_WDT_A__
                                                                        #define WDT_A_BASE                      __MSP430_BASEADDRESS_WDT_A__
#endif

#endif // #ifndef __HW_MEMMAP__

#endif
