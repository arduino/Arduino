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
/** ============================================================================
 * @file       PWMTiva.h
 *
 * @brief      PWM driver implementation for Tiva PWM perhiperals.
 *
 * The PWM header file should be included in an application as follows:
 * @code
 * #include <ti/drivers/PWM.h>
 * #include <ti/drivers/pwm/PWMTiva.h>
 * @endcode
 *
 * ## Operation #
 * This driver implementation uses the Pulse Width Modulator (PWM) peripherals
 * present on Tiva devices to generate PWM signals.  Each PWM peripheral
 * instance contains 4 PWM signal generators, each controling 2 PWM outputs
 * (8 PWM outputs total).  This driver manages each PWM output individually
 * (each output has it's own PWM handle/instance).  However since a single clock
 * prescalar is available for a peripheral and a generator is responsable for
 * producing 2 outputs, there are some limitations in place to ensure proper
 * operation:
 *   1.  The peripheral prescalar will be set according to the period of the
 *       first PWM instance opened.  Any subsequent outputs will fail to open if
 *       a greater prescalar is required to generate the PWM period.
 *   2.  A PWM generators period is set to the period of the instance opened.
 *       Opening the second output will fail if the period used is not the same
 *       as what was set by the first output.
 *   3.  A PWM generators options are set by the first instance opened.  Opening
 *       the second output will fail if the options are not the same as what was
 *       set by the first output.
 *
 * Since the period and duty registers are 16 bits wide the prescalar is used to
 * divide the input clock and allow for larger periods.  The maximum period
 * supported is calculated as:
 *     MAX_PERIOD = (MAX_PRESCALAR * MAX_MATCH_VALUE) / CYCLES_PER_US
 *     80 MHz clock: (64 * 65535) / 80 = 52428 microseconds
 *     120 MHz clock: (64 * 65535) / 120 = 34952 microseconds
 *
 * After opening, the PWM_control() API can be used to change a PWM generator
 * period. However, the clock prescalar is shared by all generators so the new
 * period must be a value that can generated with the same prescaler.  Also keep
 * in mind that changing a period affects both generator outputs.  The equation
 * below can be used to determine the prescalar for a given period:
 *   The prescalar will be the following power of 2 number (2^x):
 *     prescalar = (period * CYCLES_PER_US) / MAX_MATCH_VALUE
 *     100 microseconds = (100 * 80) / 65535 = (0.1220) = 1
 *     10000 microseconds = (10000 * 80) / 65535 = (12.20) = 16
 *
 * Below is an example of how to use the PWM_control() API to change a period:
 *
 * @code
 * #include <ti/drivers/pwm/PWMTiva.h>
 * #include <driverlib/pwm.h>
 *
 * int rc = 0;
 * int newPeriod = 2000;
 *
 * rc = PWM_control(pwmHandle, PWMTiva_CHANGE_GEN_PERIOD, &newPeriod);
 * if (rc < 0) {
 *     // handle error condition
 * }
 * @endcode
 *
 * Finally, if the duty supplied is greater than the period; the output will
 * remain in active state.
 *
 * =============================================================================
 */

#ifndef ti_driver_pwm_PWMTiva__include
#define ti_driver_pwm_PWMTiva__include

#ifdef __cplusplus
extern "C" {
#endif

#include <ti/drivers/PWM.h>

/* Number of PWM peripherals available on a device */
#define PWMTiva_NUM_PWM_PERIPHERALS      2

/* Number of signal generator blocks per PWM peripheral */
#define PWMTiva_NUM_PWM_GENERATORS       4

/* PWM_control commands */
#define PWMTiva_CHANGE_GEN_PERIOD        PWM_CMD_RESERVED + 0

/* PWM function table pointer */
extern const PWM_FxnTable PWMTiva_fxnTable;

/*!
 *  @brief  PWMTiva Hardware attributes
 *
 *  These fields are used by driverlib APIs and therefore must be populated by
 *  driverlib macro definitions. For TivaWare these definitions are found in:
 *      - driverlib/pwm.h
 *
 *  A sample structure is shown below:
 *  @code
 *  const PWMTiva_HWAttrs PWMTivaHWAttrs[] = {
 *      {
 *          PWM0_BASE,
 *          PWM_OUT_0,
 *          PWM_GEN_MODE_DOWN | PWM_GEN_MODE_DBG_RUN
 *      }
 *  };
 *  @endcode
 */
typedef struct PWMTiva_HWAttrs {
    uint32_t baseAddr;                  /*!< PWM peripheral base address */
    uint32_t pwmOutput;                 /*!< Encoded PWM offset address */
    uint32_t pwmGenOpts;                /*!< Generator options for PWM */
} PWMTiva_HWAttrs;

/*!
 *  @brief PWMTiva_Status
 *
 *  The application must not access any member variables of this structure!
 */
typedef struct PWMTiva_Status {
    uint16_t genPeriods[PWMTiva_NUM_PWM_GENERATORS];
    uint8_t  cyclesPerMicroSec;
    uint8_t  prescalar;
    uint8_t  activeOutputs;
} PWMTiva_Status;

/*!
 *  @brief  PWMTiva Object
 *
 *  The application must not access any member variables of this structure!
 */
typedef struct PWMTiva_Object {
    PWMTiva_Status *pwmStatus;
    uint16_t        pwmDuty;
    uint8_t         pwmOutputBit;
    uint8_t         dutyMode;            /* Units in which duty is specified */
} PWMTiva_Object;

#ifdef __cplusplus
}
#endif

#endif /* ti_driver_pwm_PWMTiva__include */
