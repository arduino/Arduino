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
/* 
 * ======== device.h ========
 */
#include <msp430.h>

#if defined (__MSP430F6638__) || defined (__MSP430F6637__) || \
    defined (__MSP430F6636__) || \
    defined (__MSP430F6635__) || defined (__MSP430F6634__) || \
    defined (__MSP430F6633__) || \
    defined (__MSP430F6632__) || defined (__MSP430F6631__) || \
    defined (__MSP430F6630__) || \
    defined (__MSP430F5638__) || defined (__MSP430F5637__) || \
    defined (__MSP430F5636__) || \
    defined (__MSP430F5635__) || defined (__MSP430F5634__) || \
    defined (__MSP430F5633__) || \
    defined (__MSP430F5632__) || defined (__MSP430F5631__) || \
    defined (__MSP430F5630__)
    #define __MSP430F563x_F663x
#elif defined (__MSP430F5510__) || defined (__MSP430F5509__) || \
    defined (__MSP430F5508__) || \
    defined (__MSP430F5507__) || defined (__MSP430F5506__) || \
    defined (__MSP430F5505__) || \
    defined (__MSP430F5504__) || defined (__MSP430F5503__) || \
    defined (__MSP430F5502__) || \
    defined (__MSP430F5501__) || defined (__MSP430F5500__)
    #define __MSP430F550x
#elif defined (__MSP430F5529__) || defined (__MSP430F5528__) || \
    defined (__MSP430F5527__) || \
    defined (__MSP430F5526__) || defined (__MSP430F5525__) || \
    defined (__MSP430F5524__) || \
    defined (__MSP430F5522__) || defined (__MSP430F5521__) || \
    defined (__MSP430F5519__) || \
    defined (__MSP430F5517__) || defined (__MSP430F5515__) || \
    defined (__MSP430F5514__) || \
    defined (__MSP430F5513__)
    #define __MSP430F552x
#else
    #error \
    Define a constant of format __MSP430Fxxxx__ within the projects preprocessor settings,
according to the device being used.
#endif
/*------------------------ Nothing Below This Line --------------------------*/
