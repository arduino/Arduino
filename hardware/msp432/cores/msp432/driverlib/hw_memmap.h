/*
 * -------------------------------------------
 *    MSP432 DriverLib - v3_10_00_09 
 * -------------------------------------------
 *
 * --COPYRIGHT--,BSD,BSD
 * Copyright (c) 2014, Texas Instruments Incorporated
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

#define __DRIVERLIB_MSP432P4XX_FAMILY__
//*****************************************************************************
//
// Include device specific header file
//
//*****************************************************************************


//*****************************************************************************
//
// SUCCESS and FAILURE for API return value
//
//*****************************************************************************
#define STATUS_SUCCESS  0x01
#define STATUS_FAIL     0x00

//*****************************************************************************
//
// Macros for hardware access
//
//*****************************************************************************
#define HWREG8(x)         (*((volatile uint8_t *)(x)))
#define HWREG16(x)        (*((volatile uint16_t *)(x)))
#define HWREG32(x)        (*((volatile uint32_t *)(x)))
#define HWREG(x)          (HWREG16(x))
#define HWREG8_L(x)       (*((volatile uint8_t *)((uint8_t *)&x)))
#define HWREG8_H(x)       (*((volatile uint8_t *)(((uint8_t *)&x)+1)))
#define HWREG16_L(x)      (*((volatile uint16_t *)((uint16_t *)&x)))
#define HWREG16_H(x)      (*((volatile uint16_t *)(((uint16_t *)&x)+1)))

/******************************************************************************
* Device memory map                                                           *
******************************************************************************/
#define __MAIN_MEMORY_START__                              (0x00000000)          /**< Main Flash memory start address */
#define __MAIN_MEMORY_END__                                (0x0003FFFF)          /**< Main Flash memory end address */
#define __BSL_MEMORY_START__                               (0x00202000)          /**< BSL memory start address */
#define __BSL_MEMORY_END__                                 (0x00203FFF)          /**< BSL memory end address */
#define __SRAM_START__                                     (0x20000000)          /**< SRAM memory start address */
#define __SRAM_END__                                       (0x2000FFFF)          /**< SRAM memory end address */

/******************************************************************************
* Definitions for 8/16/32-bit wide bit band access                            *
******************************************************************************/
#define HWREGBIT8(x, b)   (HWREG8(((uint32_t)(x) & 0xF0000000) | 0x02000000 | (((uint32_t)(x) & 0x000FFFFF) << 5) | ((b) << 2)))
#define HWREGBIT16(x, b)  (HWREG16(((uint32_t)(x) & 0xF0000000) | 0x02000000 | (((uint32_t)(x) & 0x000FFFFF) << 5) | ((b) << 2)))
#define HWREGBIT32(x, b)  (HWREG32(((uint32_t)(x) & 0xF0000000) | 0x02000000 | (((uint32_t)(x) & 0x000FFFFF) << 5) | ((b) << 2)))

#endif // #ifndef __HW_MEMMAP__
