/* --COPYRIGHT--,BSD
 * Copyright (c) 2012, Texas Instruments Incorporated
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
/*******************************************************************************
 *
 * HAL_TLV.c
 * Provides Functions to Read the TLV Data Section of the MSP430 Devices
 * 
 *
 * Copyright (C) 2010 Texas Instruments Incorporated - http://www.ti.com/ 
 * 
 * 
 *  Redistribution and use in source and binary forms, with or without 
 *  modification, are permitted provided that the following conditions 
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright 
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the 
 *    documentation and/or other materials provided with the   
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 * Updated: Version 2.0 01/17/2011
 *  
 ******************************************************************************/

#ifndef HAL_TLV_H
#define HAL_TLV_H

#include <stdint.h>

/*******************************************************************************
 * Device Descriptors - Fixed Memory Locations
 ******************************************************************************/
#define DEVICE_ID_0		(0x1A04)
#define DEVICE_ID_1		(0x1A05)

/*******************************************************************************
 * Data Types
 ******************************************************************************/
struct s_TLV_Die_Record {
  uint8_t die_record[10];
};

struct s_TLV_ADC_Cal_Data {
  uint16_t adc_gain_factor;
  uint16_t adc_offset;
  uint16_t adc_ref15_30_temp;
  uint16_t adc_ref15_85_temp;
  uint16_t adc_ref20_30_temp;
  uint16_t adc_ref20_85_temp;
  uint16_t adc_ref25_30_temp;
  uint16_t adc_ref25_85_temp;
};

struct s_TLV_Timer_D_Cal_Data {
  uint16_t TDH0CTL1_64;
  uint16_t TDH0CTL1_128;
  uint16_t TDH0CTL1_200;
  uint16_t TDH0CTL1_256;
};

struct s_TLV_REF_Cal_Data {
  uint16_t ref_ref15;
  uint16_t ref_ref20;
  uint16_t adc_ref25;
};

/*******************************************************************************
 * Tag Defines
 ******************************************************************************/
#define TLV_LDTAG             (0x01)      /*  Legacy descriptor (1xx, 2xx,
                                              4xx families) */
#define TLV_PDTAG             (0x02)      /*  Peripheral discovery descriptor */
#define TLV_Reserved3         (0x03)      /*  Future usage */
#define TLV_Reserved4         (0x04)      /*  Future usage */
#define TLV_BLANK             (0x05)      /*  Blank descriptor */
#define TLV_Reserved6         (0x06)      /*  Future usage */
#define TLV_Reserved7         (0x07)      /*  Serial Number */
#define TLV_DIERECORD         (0x08)      /*  Die Record  */
#define TLV_ADCCAL            (0x11)      /*  ADC12 calibration */
#define TLV_ADC12CAL          (0x11)      /*  ADC12 calibration */
#define TLV_ADC10CAL          (0x13)      /*  ADC10 calibration */
#define TLV_REFCAL            (0x12)      /*  REF calibration */
#define TLV_TIMER_D_CAL       (0x15)      /*  Timer_Dx calibration */
#define TLV_TAGEXT            (0xFE)      /*  Tag extender */
#define TLV_TAGEND            (0xFF)      /*  Tag End of Table */

/*******************************************************************************
 * Peripheral Defines
 ******************************************************************************/
#define TLV_PID_NO_MODULE     (0x00)      /*  No Module */
#define TLV_PID_PORTMAPPING   (0x10)      /*  Port Mapping */
#define TLV_PID_MSP430CPUXV2  (0x23)      /*  MSP430CPUXV2 */
#define TLV_PID_JTAG          (0x09)      /*  JTAG */
#define TLV_PID_SBW           (0x0F)      /*  SBW */
#define TLV_PID_EEM_XS        (0x02)      /*  EEM X-Small */
#define TLV_PID_EEM_S         (0x03)      /*  EEM Small */
#define TLV_PID_EEM_M         (0x04)      /*  EEM Medium */
#define TLV_PID_EEM_L         (0x05)      /*  EEM Large */
#define TLV_PID_PMM           (0x30)      /*  PMM */
#define TLV_PID_PMM_FR        (0x32)      /*  PMM FRAM */
#define TLV_PID_FCTL          (0x39)      /*  Flash */
#define TLV_PID_CRC16         (0x3C)      /*  CRC16 */
#define TLV_PID_CRC16_RB      (0x3D)      /*  CRC16 Reverse */
#define TLV_PID_WDT_A         (0x40)      /*  WDT_A */
#define TLV_PID_SFR           (0x41)      /*  SFR */
#define TLV_PID_SYS           (0x42)      /*  SYS */
#define TLV_PID_RAMCTL        (0x44)      /*  RAMCTL */
#define TLV_PID_DMA_1         (0x46)      /*  DMA 1 */
#define TLV_PID_DMA_3         (0x47)      /*  DMA 3 */
#define TLV_PID_UCS           (0x48)      /*  UCS */
#define TLV_PID_DMA_6         (0x4A)      /*  DMA 6 */
#define TLV_PID_DMA_2         (0x4B)      /*  DMA 2 */
#define TLV_PID_PORT1_2       (0x51)      /*  Port 1 + 2 / A */
#define TLV_PID_PORT3_4       (0x52)      /*  Port 3 + 4 / B */
#define TLV_PID_PORT5_6       (0x53)      /*  Port 5 + 6 / C */
#define TLV_PID_PORT7_8       (0x54)      /*  Port 7 + 8 / D */
#define TLV_PID_PORT9_10      (0x55)      /*  Port 9 + 10 / E */
#define TLV_PID_PORT11_12     (0x56)      /*  Port 11 + 12 / F */
#define TLV_PID_PORTU         (0x5E)      /*  Port U */
#define TLV_PID_PORTJ         (0x5F)      /*  Port J */
#define TLV_PID_TA2           (0x60)      /*  Timer A2 */
#define TLV_PID_TA3           (0x61)      /*  Timer A1 */
#define TLV_PID_TA5           (0x62)      /*  Timer A5 */
#define TLV_PID_TA7           (0x63)      /*  Timer A7 */
#define TLV_PID_TB3           (0x65)      /*  Timer B3 */
#define TLV_PID_TB5           (0x66)      /*  Timer B5 */
#define TLV_PID_TB7           (0x67)      /*  Timer B7 */
#define TLV_PID_RTC           (0x68)      /*  RTC */
#define TLV_PID_BT_RTC        (0x69)      /*  BT + RTC */
#define TLV_PID_BBS           (0x6A)      /*  Battery Backup Switch */
#define TLV_PID_RTC_B         (0x6B)      /*  RTC_B */
#define TLV_PID_TD2           (0x6C)      /*  Timer D2 */
#define TLV_PID_TD3           (0x6D)      /*  Timer D1 */
#define TLV_PID_TD5           (0x6E)      /*  Timer D5 */
#define TLV_PID_TD7           (0x6F)      /*  Timer D7 */
#define TLV_PID_TEC           (0x70)      /*  Imer Event Control */
#define TLV_PID_RTC_C         (0x71)      /*  RTC_C */
#define TLV_PID_AES           (0x80)      /*  AES */
#define TLV_PID_MPY16         (0x84)      /*  MPY16 */
#define TLV_PID_MPY32         (0x85)      /*  MPY32 */
#define TLV_PID_MPU           (0x86)      /*  MPU */
#define TLV_PID_USCI_AB       (0x90)      /*  USCI_AB */
#define TLV_PID_USCI_A        (0x91)      /*  USCI_A */
#define TLV_PID_USCI_B        (0x92)      /*  USCI_B */
#define TLV_PID_EUSCI_A       (0x94)      /*  eUSCI_A */
#define TLV_PID_EUSCI_B       (0x95)      /*  eUSCI_B */
#define TLV_PID_REF           (0xA0)      /*  Shared Reference */
#define TLV_PID_COMP_B        (0xA8)      /*  COMP_B */
#define TLV_PID_COMP_D        (0xA9)      /*  COMP_D */
#define TLV_PID_USB           (0x98)      /*  USB */
#define TLV_PID_LCD_B         (0xB1)      /*  LCD_B */
#define TLV_PID_LCD_C         (0xB2)      /*  LCD_C */
#define TLV_PID_DAC12_A       (0xC0)      /*  DAC12_A */
#define TLV_PID_SD16_B_1      (0xC8)      /*  SD16_B 1 Channel */
#define TLV_PID_SD16_B_2      (0xC9)      /*  SD16_B 2 Channel */
#define TLV_PID_SD16_B_3      (0xCA)      /*  SD16_B 3 Channel */
#define TLV_PID_SD16_B_4      (0xCB)      /*  SD16_B 4 Channel */
#define TLV_PID_SD16_B_5      (0xCC)      /*  SD16_B 5 Channel */
#define TLV_PID_SD16_B_6      (0xCD)      /*  SD16_B 6 Channel */
#define TLV_PID_SD16_B_7      (0xCE)      /*  SD16_B 7 Channel */
#define TLV_PID_SD16_B_8      (0xCF)      /*  SD16_B 8 Channel */
#define TLV_PID_ADC12_A       (0xD1)      /*  ADC12_A */
#define TLV_PID_ADC10_A       (0xD3)      /*  ADC10_A */
#define TLV_PID_ADC10_B       (0xD4)      /*  ADC10_B */
#define TLV_PID_SD16_A        (0xD8)      /*  SD16_A */
#define TLV_PID_TI_BSL        (0xFC)      /*  BSL */

/*******************************************************************************
 * \brief   Get Information out of the TLV Table
 *
 * \param tag               Tag of the TLV entry
 * \param instance          Instance of the Tag of the TLV entry
 * \param *length           return: Length of the information if found
 * \param **data_address    return: start pointer of Data
 ******************************************************************************/
void Get_TLV_Info(uint8_t tag, uint8_t instance, uint8_t *length,
    uint16_t **data_address);

/*******************************************************************************
 * \brief   Get Device Type out of the TLV Table
 *
 * \return  Device dependent value
 ******************************************************************************/
uint16_t Get_Device_Type(void);

/*******************************************************************************
 * \brief   Get Memory Info out of the TLV Table
 *
 * \param instance  Index of the Instance [0..]
 * \return          Memory Data found
 ******************************************************************************/
uint16_t Get_TLV_Memory(uint8_t instance);

/*******************************************************************************
 * \brief Get Peripheral Info out of the TLV Table
 *
 * \param tag       Tag of the TLV entry
 * \param instance  Index of the Instance [0..]
 * \return          Peripheral Data found
 ******************************************************************************/
uint16_t Get_TLV_Peripheral(uint8_t tag, uint8_t instance);

/*******************************************************************************
 * \brief   Get Interrupt Info out of the TLV Table
 *
 * \param tag   Tag of the TLV entry
 * \return      Interrupt Data found
 ******************************************************************************/
uint8_t Get_TLV_Interrupt(uint8_t tag);

#endif /* HAL_TLV_H */
