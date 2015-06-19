/*
 * Copyright (c) 2015, Texas Instruments Incorporated
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
 */

#ifndef WiringPrivate_h
#define WiringPrivate_h

#include <ti/runtime/wiring/Energia.h>

#ifdef __cplusplus
extern "C" {
#endif

#define PIN_FUNC_UNUSED             0
#define PIN_FUNC_DIGITAL_OUTPUT     1
#define PIN_FUNC_DIGITAL_INPUT      2
#define PIN_FUNC_ANALOG_OUTPUT      3
#define PIN_FUNC_ANALOG_INPUT       4

#define NOT_ON_TIMER    128

#define TIMERA0A 0
#define TIMERA0B 1
#define TIMERA1A 2
#define TIMERA1B 3
#define TIMERA2A 4
#define TIMERA2B 5
#define TIMERA3A 6
#define TIMERA3B 7

#define NOT_A_PIN       0
#define NOT_ON_ADC      0xff

extern void stopAnalogWrite(uint8_t pin);
extern void stopAnalogRead(uint8_t pin);

extern uint8_t digital_pin_to_pin_function[];
extern const uint8_t digital_pin_to_timer[];
extern const uint16_t digital_pin_to_pin_num[];
extern const uint32_t digital_pin_to_analog_in[];

#ifdef __cplusplus
} // extern "C"
#endif

#endif
