//*****************************************************************************
//
// Only include parts of code relevant for Energia device
//
//*****************************************************************************
#if defined(__MSP430FR5969__) || defined(__MSP430F5529__) || defined(__MSP430FR5739__)

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
//*****************************************************************************
//
// tlv.c - Driver for the tlv Module.
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup tlv_api
//! @{
//
//*****************************************************************************

#include "inc/hw_regaccess.h"
#include "inc/hw_memmap.h"

#ifdef __MSP430_HAS_TLV__
#include "tlv.h"

#include <assert.h>

//*****************************************************************************
//
//! \brief Gets TLV Info
//!
//! The TLV structure uses a tag or base address to identify segments of the
//! table where information is stored. Some examples of TLV tags are Peripheral
//! Descriptor, Interrupts, Info Block and Die Record. This function retrieves
//! the value of a tag and the length of the tag.
//!
//! \param tag represents the tag for which the information needs to be
//!        retrieved.
//!        Valid values are:
//!        - \b TLV_TAG_LDTAG
//!        - \b TLV_TAG_PDTAG
//!        - \b TLV_TAG_Reserved3
//!        - \b TLV_TAG_Reserved4
//!        - \b TLV_TAG_BLANK
//!        - \b TLV_TAG_Reserved6
//!        - \b TLV_TAG_Reserved7
//!        - \b TLV_TAG_TAGEND
//!        - \b TLV_TAG_TAGEXT
//!        - \b TLV_TAG_TIMER_D_CAL
//!        - \b TLV_DEVICE_ID_0
//!        - \b TLV_DEVICE_ID_1
//!        - \b TLV_TAG_DIERECORD
//!        - \b TLV_TAG_ADCCAL
//!        - \b TLV_TAG_ADC12CAL
//!        - \b TLV_TAG_ADC10CAL
//!        - \b TLV_TAG_REFCAL
//! \param instance In some cases a specific tag may have more than one
//!        instance. For example there may be multiple instances of timer
//!        calibration data present under a single Timer Cal tag. This variable
//!        specifies the instance for which information is to be retrieved (0,
//!        1, etc.). When only one instance exists; 0 is passed.
//! \param length Acts as a return through indirect reference. The function
//!        retrieves the value of the TLV tag length. This value is pointed to
//!        by *length and can be used by the application level once the
//!        function is called. If the specified tag is not found then the
//!        pointer is null 0.
//! \param data_address acts as a return through indirect reference. Once the
//!        function is called data_address points to the pointer that holds the
//!        value retrieved from the specified TLV tag. If the specified tag is
//!        not found then the pointer is null 0.
//!
//! \return None
//
//*****************************************************************************
void TLV_getInfo(uint8_t tag,
                 uint8_t instance,
                 uint8_t *length,
                 uint16_t **data_address
                 )
{
        // TLV Structure Start Address
        char *TLV_address = (char*)TLV_START;

        while ((TLV_address < (char*)TLV_END)
               && ((*TLV_address != tag) || instance)   // check for tag and instance
               && (*TLV_address != TLV_TAGEND)) {       // do range check first
                if (*TLV_address == tag)
                        // repeat till requested instance is reached
                        instance--;
                // add (Current TAG address + LENGTH) + 2
                TLV_address += *(TLV_address + 1) + 2;
        }

        // Check if Tag match happened..
        if (*TLV_address == tag) {
                // Return length = Address + 1
                *length = *(TLV_address + 1);
                // Return address of first data/value info = Address + 2
                *data_address = (uint16_t*)(TLV_address + 2);
        }
        // If there was no tag match and the end of TLV structure was reached..
        else{
                // Return 0 for TAG not found
                *length = 0;
                // Return 0 for TAG not found
                *data_address = 0;
        }
}

//*****************************************************************************
//
//! \brief Retrieves the unique device ID from the TLV structure.
//!
//!
//! \return The device ID is returned as type uint16_t.
//
//*****************************************************************************
uint16_t TLV_getDeviceType()
{
        uint16_t *pDeviceType = (uint16_t*)TLV_DEVICE_ID_0;

        // Return Value from TLV Table
        return pDeviceType[0];
}

//*****************************************************************************
//
//! \brief Gets memory information
//!
//! The Peripheral Descriptor tag is split into two portions a list of the
//! available flash memory blocks followed by a list of available peripherals.
//! This function is used to parse through the first portion and calculate the
//! total flash memory available in a device. The typical usage is to call the
//! TLV_getMemory which returns a non-zero value until the entire memory list
//! has been parsed. When a zero is returned, it indicates that all the memory
//! blocks have been counted and the next address holds the beginning of the
//! device peripheral list.
//!
//! \param instance In some cases a specific tag may have more than one
//!        instance. This variable specifies the instance for which information
//!        is to be retrieved (0, 1 etc). When only one instance exists; 0 is
//!        passed.
//!
//! \return The returned value is zero if the end of the memory list is
//!         reached.
//
//*****************************************************************************
uint16_t TLV_getMemory(uint8_t instance)
{
        uint8_t *pPDTAG;
        uint8_t bPDTAG_bytes;
        uint16_t count;

        // set tag for word access comparison
        instance *= 2;

        // TLV access Function Call
        // Get Peripheral data pointer
        TLV_getInfo(TLV_PDTAG,
                    0,
                    &bPDTAG_bytes,
                    (uint16_t**)&pPDTAG
                    );

        for (count = 0; count <= instance; count += 2) {
                if (pPDTAG[count] == 0)
                        // Return 0 if end reached
                        return 0;
                if (count == instance)
                        return pPDTAG[count] | pPDTAG[count + 1] << 8;
        }

        // Return 0: not found
        return 0;
}

//*****************************************************************************
//
//! \brief Gets peripheral information from the TLV
//!
//! he Peripheral Descriptor tag is split into two portions a list of the
//! available flash memory blocks followed by a list of available peripherals.
//! This function is used to parse through the second portion and can be used
//! to check if a specific peripheral is present in a device. The function
//! calls TLV_getPeripheral() recursively until the end of the memory list and
//! consequently the beginning of the peripheral list is reached. <
//!
//! \param tag represents represents the tag for a specific peripheral for
//!        which the information needs to be retrieved. In the header file tlv.
//!        h specific peripheral tags are pre-defined, for example USCIA_B and
//!        TA0 are defined as TLV_PID_USCI_AB and TLV_PID_TA2 respectively.
//!        Valid values are:
//!        - \b TLV_PID_NO_MODULE - No Module
//!        - \b TLV_PID_PORTMAPPING - Port Mapping
//!        - \b TLV_PID_MSP430CPUXV2 - MSP430CPUXV2
//!        - \b TLV_PID_JTAG - JTAG
//!        - \b TLV_PID_SBW - SBW
//!        - \b TLV_PID_EEM_XS - EEM X-Small
//!        - \b TLV_PID_EEM_S - EEM Small
//!        - \b TLV_PID_EEM_M - EEM Medium
//!        - \b TLV_PID_EEM_L - EEM Large
//!        - \b TLV_PID_PMM - PMM
//!        - \b TLV_PID_PMM_FR - PMM FRAM
//!        - \b TLV_PID_FCTL - Flash
//!        - \b TLV_PID_CRC16 - CRC16
//!        - \b TLV_PID_CRC16_RB - CRC16 Reverse
//!        - \b TLV_PID_WDT_A - WDT_A
//!        - \b TLV_PID_SFR - SFR
//!        - \b TLV_PID_SYS - SYS
//!        - \b TLV_PID_RAMCTL - RAMCTL
//!        - \b TLV_PID_DMA_1 - DMA 1
//!        - \b TLV_PID_DMA_3 - DMA 3
//!        - \b TLV_PID_UCS - UCS
//!        - \b TLV_PID_DMA_6 - DMA 6
//!        - \b TLV_PID_DMA_2 - DMA 2
//!        - \b TLV_PID_PORT1_2 - Port 1 + 2 / A
//!        - \b TLV_PID_PORT3_4 - Port 3 + 4 / B
//!        - \b TLV_PID_PORT5_6 - Port 5 + 6 / C
//!        - \b TLV_PID_PORT7_8 - Port 7 + 8 / D
//!        - \b TLV_PID_PORT9_10 - Port 9 + 10 / E
//!        - \b TLV_PID_PORT11_12 - Port 11 + 12 / F
//!        - \b TLV_PID_PORTU - Port U
//!        - \b TLV_PID_PORTJ - Port J
//!        - \b TLV_PID_TA2 - Timer A2
//!        - \b TLV_PID_TA3 - Timer A1
//!        - \b TLV_PID_TA5 - Timer A5
//!        - \b TLV_PID_TA7 - Timer A7
//!        - \b TLV_PID_TB3 - Timer B3
//!        - \b TLV_PID_TB5 - Timer B5
//!        - \b TLV_PID_TB7 - Timer B7
//!        - \b TLV_PID_RTC - RTC
//!        - \b TLV_PID_BT_RTC - BT + RTC
//!        - \b TLV_PID_BBS - Battery Backup Switch
//!        - \b TLV_PID_RTC_B - RTC_B
//!        - \b TLV_PID_TD2 - Timer D2
//!        - \b TLV_PID_TD3 - Timer D1
//!        - \b TLV_PID_TD5 - Timer D5
//!        - \b TLV_PID_TD7 - Timer D7
//!        - \b TLV_PID_TEC - Timer Event Control
//!        - \b TLV_PID_RTC_C - RTC_C
//!        - \b TLV_PID_AES - AES
//!        - \b TLV_PID_MPY16 - MPY16
//!        - \b TLV_PID_MPY32 - MPY32
//!        - \b TLV_PID_MPU - MPU
//!        - \b TLV_PID_USCI_AB - USCI_AB
//!        - \b TLV_PID_USCI_A - USCI_A
//!        - \b TLV_PID_USCI_B - USCI_B
//!        - \b TLV_PID_EUSCI_A - eUSCI_A
//!        - \b TLV_PID_EUSCI_B - eUSCI_B
//!        - \b TLV_PID_REF - Shared Reference
//!        - \b TLV_PID_COMP_B - COMP_B
//!        - \b TLV_PID_COMP_D - COMP_D
//!        - \b TLV_PID_USB - USB
//!        - \b TLV_PID_LCD_B - LCD_B
//!        - \b TLV_PID_LCD_C - LCD_C
//!        - \b TLV_PID_DAC12_A - DAC12_A
//!        - \b TLV_PID_SD16_B_1 - SD16_B 1 Channel
//!        - \b TLV_PID_SD16_B_2 - SD16_B 2 Channel
//!        - \b TLV_PID_SD16_B_3 - SD16_B 3 Channel
//!        - \b TLV_PID_SD16_B_4 - SD16_B 4 Channel
//!        - \b TLV_PID_SD16_B_5 - SD16_B 5 Channel
//!        - \b TLV_PID_SD16_B_6 - SD16_B 6 Channel
//!        - \b TLV_PID_SD16_B_7 - SD16_B 7 Channel
//!        - \b TLV_PID_SD16_B_8 - SD16_B 8 Channel
//!        - \b TLV_PID_ADC12_A - ADC12_A
//!        - \b TLV_PID_ADC10_A - ADC10_A
//!        - \b TLV_PID_ADC10_B - ADC10_B
//!        - \b TLV_PID_SD16_A - SD16_A
//!        - \b TLV_PID_TI_BSL - BSL
//! \param instance In some cases a specific tag may have more than one
//!        instance. For example a device may have more than a single USCI
//!        module, each of which is defined by an instance number 0, 1, 2, etc.
//!        When only one instance exists; 0 is passed.
//!
//! \return The returned value is zero if the specified tag value (peripheral)
//!         is not available in the device.
//
//*****************************************************************************
uint16_t TLV_getPeripheral(uint8_t tag,
                           uint8_t instance
                           )
{
        uint8_t *pPDTAG;
        uint8_t bPDTAG_bytes;
        uint16_t count = 0;
        uint16_t pcount = 0;

        // Get Peripheral data pointer
        TLV_getInfo(TLV_PDTAG,
                    0,
                    &bPDTAG_bytes,
                    (uint16_t**)&pPDTAG
                    );

        // read memory configuration from TLV to get offset for Peripherals
        while (TLV_getMemory(count))
                count++;
        // get number of Peripheral entries
        pcount = pPDTAG[count * 2 + 1];
        // inc count to first Periperal
        count++;
        // adjust point to first address of Peripheral
        pPDTAG += count * 2;
        // set counter back to 0
        count = 0;
        // align pcount for work comparision
        pcount *= 2;

        // TLV access Function Call
        for (count = 0; count <= pcount; count += 2) {
                if (pPDTAG[count + 1] == tag) {
                        // test if required Peripheral is found
                        if (instance > 0)
                                // test if required instance is found
                                instance--;
                        else
                                // Return found data
                                return pPDTAG[count] | pPDTAG[count + 1] << 8;
                }
        }

        // Return 0: not found
        return 0;
}

//*****************************************************************************
//
//! \brief Get interrupt information from the TLV
//!
//! This function is used to retrieve information on available interrupt
//! vectors. It allows the user to check if a specific interrupt vector is
//! defined in a given device.
//!
//! \param tag represents the tag for the interrupt vector. Interrupt vector
//!        tags number from 0 to N depending on the number of available
//!        interrupts. Refer to the device datasheet for a list of available
//!        interrupts.
//!
//! \return The returned value is zero is the specified interrupt vector is not
//!         defined.
//
//*****************************************************************************
uint8_t TLV_getInterrupt(uint8_t tag)
{
        uint8_t *pPDTAG;
        uint8_t bPDTAG_bytes;
        uint16_t count = 0;
        uint16_t pcount = 0;

        // Get Peripheral data pointer
        TLV_getInfo(TLV_PDTAG,
                    0,
                    &bPDTAG_bytes,
                    (uint16_t**)&pPDTAG
                    );

        // read memory configuration from TLV to get offset for Peripherals
        while (TLV_getMemory(count))
                count++;

        pcount = pPDTAG[count * 2 + 1];
        // inc count to first Periperal
        count++;
        // adjust point to first address of Peripheral
        pPDTAG += (pcount + count) * 2;
        // set counter back to 0
        count = 0;

        // TLV access Function Call
        for (count = 0; count <= tag; count += 2) {
                if (pPDTAG[count] == 0)
                        // Return 0: not found/end of table
                        return 0;
                if (count == tag)
                        // Return found data
                        return pPDTAG[count];
        }

        // Return 0: not found
        return 0;
}

#endif
//*****************************************************************************
//
//! Close the doxygen group for tlv_api
//! @}
//
//*****************************************************************************

#endif
