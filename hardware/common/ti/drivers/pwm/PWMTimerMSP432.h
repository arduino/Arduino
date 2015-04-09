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
 * @file       PWMTimerMSP432.h
 *
 * @brief      PWM driver implementation
 *
 * The PWM header file should be included in an application as follows:
 * @code
 * #include <ti/drivers/PWM.h>
 * #include <ti/drivers/pwm/PWMTimerMSP432.h>
 * @endcode
 *
 * ## Operation #
 * This driver configures an MSP432 Timer_A peripheral for PWM. Opening a PWM
 * instance will make the corresponding timer unavailable to the TI-RTOS kernel
 * until all PWM instances dependant on that timer are closed. Additionally, if
 * the required timer is already used by the kernel, PWM instances will not be
 * opened.
 *
 * When used for PWM generation, each Timer_A can produce up to 6 PWM outputs.
 * This driver manages each output as an independent PWM instance.  However
 * since a single period and prescalar are used for all Timer outputs, there are
 * limitations in place to ensure proper operation:
 *   1.  The PWM period and prescalar are calculated and set based on the first
 *       instance opened. Opening a second instance will fail if the period
 *       is not the same as what was set by the first instance.
 *
 * The timer is automatically configured in count-up mode using the SMCLK clock
 * as the source.  In PWM mode, the timers capture/compare register 0 is used
 * as the period register and cannot be used to generate a PWM output.
 *
 * The period and duty registers are 16 bits wide, thus a prescalar is used to
 * divide the input clock and allow for larger periods.  The maximum period
 * supported is calculated as:
 *     MAX_PERIOD = (MAX_PRESCALAR * MAX_MATCH_VALUE) / CYCLES_PER_US
 *     12 MHz clock: (64 * 65535) / 12 = 349520 microseconds
 *     6 MHz clock: (64 * 65535) / 6 = 699040 microseconds
 *     3 MHz clock: (64 * 65535) / 3 = 1398080 microseconds
 *
 * After opening, the PWM_control() API can be used to change the PWM period.
 * Keep in mind the period is shared by all other PWMs on the timer.  Below is
 * an example of how to use the PWM_control() API to change a period:
 *
 * @code
 * int rc = 0;
 * int newPeriod = 6000;   // Period in microseconds
 *
 * rc = PWM_control(pwmHandle, PWMTimerMSP432_CHANGE_PERIOD, &newPeriod);
 * if (rc < 0) {
 *   // handle error condition
 * }
 * @endcode
 *
 * Updates to a PWM instance will occur instantaneously.  If the duty supplied
 * is greater than the period, the output will remain in active state.
 *
 * =============================================================================
 */

#ifndef ti_driver_pwm_PWMTimerMSP432__include
#define ti_driver_pwm_PWMTimerMSP432__include

#ifdef __cplusplus
extern "C" {
#endif

#include <ti/drivers/PWM.h>

/* Number of PWM peripherals available on a device */
#define PWMTimerMSP432_NUM_TIMERS       4

/* PWM_control commands */
#define PWMTimerMSP432_CHANGE_PERIOD    PWM_CMD_RESERVED + 0

/* PWM function table pointer */
extern const PWM_FxnTable PWMTimerMSP432_fxnTable;

/*!
 *  @brief  PWMTimerMSP432 Hardware attributes
 *
 *  These fields are used by driverlib APIs and therefore must be populated by
 *  driverlib macro definitions. For MSP430Ware these definitions are found in:
 *      - timer_a.h
 *
 *  A sample structure is shown below:
 *  @code
 *  const PWMTimerMSP432_HWAttrs PWMTimerMSP432HWAttrs[] = {
 *      {
 *          .baseAddr = TIMER_A0_BASE,
 *          .compareRegister = TIMER_A_CAPTURECOMPARE_REGISTER_1
 *      },
 *  };
 *  @endcode
 */
typedef struct PWMTimerMSP432_HWAttrs {
    uint32_t baseAddr;           /*!< PWMTimer peripheral base address*/
    uint8_t  compareRegister;    /*!< Timer compare register for PWM */
} PWMTimerMSP432_HWAttrs;

/*!
 *  @brief PWMTimerMSP432_Status
 *
 *  The application must not access any member variables of this structure!
 */
typedef struct PWMTimerMSP432_Status {
    uint16_t period;
    uint8_t  prescalar;
    uint8_t  cyclesPerMicroSec;
    uint8_t  activeOutputsMask;
} PWMTimerMSP432_Status;

/*!
 *  @brief  PWMTimerMSP432 Object
 *
 *  The application must not access any member variables of this structure!
 */
typedef struct PWMTimerMSP432_Object {
    PWMTimerMSP432_Status *pwmTimerStatus;
    uint8_t                pwmCompareOutputBit;
    uint8_t                dutyMode;
    bool                   isOpen;
} PWMTimerMSP432_Object;

#ifdef __cplusplus
}
#endif

#endif /* ti_driver_pwm_PWMTimerMSP432__include */
