/*
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
 * EXEMPLARY, OR CONSEQueueNTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/*
 *  ======== PowerCC2650.h ========
 *
 *  Resource definitions.
 *
 */

#ifndef POWER_CC2650_
#define POWER_CC2650_

#ifdef __cplusplus
extern "C" {
#endif

typedef UInt8 Power_Resource;

#define PERIPH_GPT0    0       /* GPT0 */
#define PERIPH_GPT1    1       /* GPT1 */
#define PERIPH_GPT2    2       /* GPT2 */
#define PERIPH_GPT3    3       /* GPT3 */
#define PERIPH_SSI0    4       /* SSI0 */
#define PERIPH_SSI1    5       /* SSI1 */
#define PERIPH_UART0   6       /* UART0 */
#define PERIPH_I2C0    7       /* I2C0 */
#define PERIPH_TRNG    8       /* TRNG */
#define PERIPH_GPIO    9       /* GPIO */
#define PERIPH_UDMA    10      /* UDMA */
#define PERIPH_CRYPTO  11      /* CRYPTO */
#define PERIPH_I2S     12      /* I2S */
#define PERIPH_RFCORE  13      /* RFCORE */
#define XOSC_HF        14      /* XOSC_HF */

#define DOMAIN_PERIPH  15      /* PERIPH domain */
#define DOMAIN_SERIAL  16      /* SERIAL domain */
#define DOMAIN_RFCORE  17      /* RFCORE domain */
#define DOMAIN_SYSBUS  18      /* SYSBUS domain */

#define RESOURCE_END   19

#define PERIPH         0x80    /* resource is a peripheral */
#define SPECIAL        0x40    /* special resource requiring special handler */
#define DOMAIN         0x00    /* resource is a domain */

#define ENABLE		1
#define DISABLE		0

#define PARENTMASK     0x3F
#define NOPARENT       0x3F

/* Power resource database record format */
typedef struct ti_sysbios_family_arm_cc26xx_Power_ResourceRecord {
    UInt8 flags;          /* resource type : first parent */
    UInt8 flags2;         /* second parent */
    UInt16 driverlibID;
} ti_sysbios_family_arm_cc26xx_Power_ResourceRecord;

extern const ti_sysbios_family_arm_cc26xx_Power_ResourceRecord
    ti_sysbios_family_arm_cc26xx_Power_db[];
extern Fxn ti_sysbios_family_arm_cc26xx_Power_resourceHandlers[];
extern volatile UInt8 ti_sysbios_family_arm_cc26xx_Power_refCount[];

#ifdef __cplusplus
}
#endif

#endif /* POWER_CC2650_ */
