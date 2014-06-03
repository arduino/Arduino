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
// mpy32.h - Driver for the MPY32 Module.
//
//*****************************************************************************

#ifndef __MSP430WARE_MPY32_H__
#define __MSP430WARE_MPY32_H__

#include "inc/hw_memmap.h"

#ifdef __MSP430_HAS_MPY32__

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

//******************************************************************************
//
// The following is a struct that can be returned by MPY32_getResult64Bit()
//
//******************************************************************************
typedef struct {
        uint16_t RES0;
        uint16_t RES1;
        uint16_t RES2;
        uint16_t RES3;
} uint64;

//*****************************************************************************
//
// The following are values that can be passed to the writeDelaySelect
// parameter for functions: MPY32_setWriteDelay().
//
//*****************************************************************************
#define MPY32_WRITEDELAY_OFF                        (!(MPYDLY32 + MPYDLYWRTEN))
#define MPY32_WRITEDELAY_32BIT                                    (MPYDLYWRTEN)
#define MPY32_WRITEDELAY_64BIT                         (MPYDLY32 + MPYDLYWRTEN)

//*****************************************************************************
//
// The following are values that can be passed to the multiplicationType
// parameter for functions: MPY32_setOperandOne8Bit(),
// MPY32_setOperandOne16Bit(), MPY32_setOperandOne24Bit(), and
// MPY32_setOperandOne32Bit().
//
//*****************************************************************************
#define MPY32_MULTIPLY_UNSIGNED                                          (0x00)
#define MPY32_MULTIPLY_SIGNED                                            (0x02)
#define MPY32_MULTIPLYACCUMULATE_UNSIGNED                                (0x04)
#define MPY32_MULTIPLYACCUMULATE_SIGNED                                  (0x06)

//*****************************************************************************
//
// Prototypes for the APIs.
//
//*****************************************************************************
extern void MPY32_setWriteDelay(uint16_t writeDelaySelect);

extern void MPY32_setSaturationMode(void);

extern void MPY32_resetSaturationMode(void);

extern void MPY32_setFractionMode(void);

extern void MPY32_resetFractionMode(void);

extern void MPY32_setOperandOne8Bit(uint8_t multiplicationType,
                                    uint8_t operand);

extern void MPY32_setOperandOne16Bit(uint8_t multiplicationType,
                                     uint16_t operand);

extern void MPY32_setOperandOne24Bit(uint8_t multiplicationType,
                                     uint32_t operand);

extern void MPY32_setOperandOne32Bit(uint8_t multiplicationType,
                                     uint32_t operand);

extern void MPY32_setOperandTwo8Bit(uint8_t operand);

extern void MPY32_setOperandTwo16Bit(uint16_t operand);

extern void MPY32_setOperandTwo24Bit(uint32_t operand);

extern void MPY32_setOperandTwo32Bit(uint32_t operand);

extern uint8_t MPY32_getResult8Bit(void);

extern uint16_t MPY32_getResult16Bit(void);

extern uint32_t MPY32_getResult24Bit(void);

extern uint32_t MPY32_getResult32Bit(void);

extern uint64 MPY32_getResult64Bit(void);

extern uint16_t MPY32_getSumExtension(void);

extern uint16_t MPY32_getCarryBitValue(void);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif
#endif // __MSP430WARE_MPY32_H__

#endif
