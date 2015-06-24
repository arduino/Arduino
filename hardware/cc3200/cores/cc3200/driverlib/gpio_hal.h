//*****************************************************************************
//
// Copyright (C) 2014 Texas Instruments Incorporated - http://www.ti.com/ 
// 
// 
//  Redistribution and use in source and binary forms, with or without 
//  modification, are permitted provided that the following conditions 
//  are met:
//
//    Redistributions of source code must retain the above copyright 
//    notice, this list of conditions and the following disclaimer.
//
//    Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the 
//    documentation and/or other materials provided with the   
//    distribution.
//
//    Neither the name of Texas Instruments Incorporated nor the names of
//    its contributors may be used to endorse or promote products derived
//    from this software without specific prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
//  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
//  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
//  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
//  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
//  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
//  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
//  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
//  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
//  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
//  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//*****************************************************************************

/*******************************************************************************
 *  gpio_hal.h - API and other data constructs to operate GPIO HAL.
 *******************************************************************************
 */

#ifndef __GPIO_HAL_H__
#define __GPIO_HAL_H__

#include "cc_pm.h"
#include <inc/hw_types.h>
#include <driverlib/gpio.h>
#include "cc_types.h"

#define MAX_GPIO_PORTS         4
#define MAX_SPL_PURPOSE_GPIOS   6

typedef i32 (*notification_cb)(i32);

enum gpio_int_type {
        INT_FALLING_EDGE = GPIO_FALLING_EDGE,
        INT_RISING_EDGE = GPIO_RISING_EDGE,
        INT_BOTH_EDGE = GPIO_BOTH_EDGES,
        INT_LEVEL_LOW = GPIO_LOW_LEVEL,
        INT_LEVEL_HIGH = GPIO_HIGH_LEVEL
};

enum gpio_dir {
        GPIO_DIR_INPUT,
        GPIO_DIR_OUTPUT
};

/* GPIO interrupt notification type */
#define GPIO_TYPE_NORMAL        0x1     /* Normal operation */
#define GPIO_TYPE_WAKE_SOURCE   0x2     /* As a wake source */

struct gpio_port_info {
        u32 module_id;     /* Peripheral identifier of GPIO module  */
        u32 base_addr;          /* Hardware address of GPIO module  */
        u8 irqvec_id;         /* Interrupt number of GPIO module  */
        u8 validity_mask;              /* Valid GPIO pins of port */
        u8 special_purpose_mask;     /* Special purpose GPIO pins */
};

struct cc_gpio_config {

        /* Platform details */
        struct gpio_port_info port_info[MAX_GPIO_PORTS];        /* Port Info */

        u8 wakeup_irqvec_id; /* Interrupt for GPIO wakeup source  */

        /* 
           Callback for a scheduled operation.
           event: identifies event or trigger point from GPIO
           evt_data: optional data associated with specified event
        */
        notification_cb drv_notify_cb;
        
        /* Function to enable critical section operations */
        sys_irq_enbl   enbl_irqc;
        sys_irq_dsbl   dsbl_irqc;
};

/*!
  \brief Initialize the GPIO module

  \return on success a handle specific indicated instance of HW, otherwise
  NULL on error.
 
*/
i32 cc_gpio_init(const struct cc_gpio_config *gpio_info);

/*!
*  \brief Indicate the begining of usage and setup the direction 
*         (input/output) of the specified GPIO.
*  \param  gpio_num:   Is the gpio number that encapsulates the port and pin
*       GPIO number -- | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
*                      [    <Port No.>     : <Pin No.> ]
*  \param  direction:   sets the GPIO to be input/output
* 
*  \return valid handle: on success, NULL on error
*/
cc_hndl cc_gpio_open(i32 gpio_num, enum gpio_dir direction);

/*!
*  \brief Indicate the stop of usage of the specified GPIO.
*  \param  gpio_num:   Is the gpio number that encapsulates the port and pin
*       GPIO number -- | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
*                      [    <Port No.>     : <Pin No.> ]
*  \return 0: on success, -1 on error
*/
i32 cc_gpio_close(cc_hndl gpio_hndl, i32 gpio_num);

/*!
*  \brief Read from the specified GPIO.
*  \param  gpio_num:   Is the gpio number that encapsulates the port and pin
*       GPIO number -- | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
*                      [    <Port No.>     : <Pin No.> ]
*  \param  gpio_val:   Value read on the specified GPIO
* 
*  \return 0: on success, -1 on error
*/
i32 cc_gpio_read(cc_hndl gpio_hndl, i32 gpio_num, i8 *gpio_val);

/*!
*  \brief Write to the specified GPIO.
*  \param  gpio_num:   Is the gpio number that encapsulates the port and pin
*       GPIO number -- | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
*                      [    <Port No.>     : <Pin No.> ]
*  \param  gpio_val:   Value to be written onto the specified GPIO
* 
*  \return 0: on success, -1 on error
*
*/
i32 cc_gpio_write(cc_hndl gpio_hndl, i32 gpio_num, i8 gpio_val);

/*!
*  \brief Toggle the specified GPIO.
*  \param  gpio_num:   Is the gpio number that encapsulates the port and pin
*       GPIO number -- | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
*                      [    <Port No.>     : <Pin No.> ]
*  \return 0: on success, -1 on error
*
*/
i32 cc_gpio_toggle(cc_hndl gpio_hndl, i32 gpio_num);

/*!
*  \brief Enable the interrupt and subsequent notification on the specified 
*         GPIO on the occurance of the specified interrupt type.
*  \param  gpio_num:   Is the gpio number that encapsulates the port and pin
*       GPIO number -- | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
*                      [    <Port No.>     : <Pin No.> ]
*  \param gpio_type defines the activity on the GPIO to trigger the 
*         notification
*  \param flags has to be GPIO_TYPE_NORMAL and/or GPIO_TYPE_WAKE_SOURCE
*         GPIO_TYPE_NORMAL : Interrupt during active/cortex gating power cycles
*         GPIO_TYPE_WAKE_SOURCE : Wakeup interrupt from low power mode
*         (GPIO_TYPE_NORMAL | GPIO_TYPE_WAKE_SOURCE) : Interrupt on any activity
*               during active/cortex gating/low power modes
*  \return 0: on success, -1 on error
*
*/
i32 cc_gpio_enable_notification(cc_hndl gpio_hndl, 
                                i32 gpio_num, 
                                enum gpio_int_type gpio_type,
                                i32 flags);

/*!
*  \brief Disable the interrupt and subsequent notification on the GPIO.
*  \param  gpio_num:   Is the gpio number that encapsulates the port and pin
*       GPIO number -- | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
*                      [    <Port No.>     : <Pin No.> ]
*  \return 0: on success, -1 on error
*
*/
i32 cc_gpio_disable_notification(cc_hndl gpio_hndl, i32 gpio_num);

/*!
*  \brief Get the special purpose GPIOs registered for notification.
*  \param  gpio_num: Pointer to the storage of GPIO number
*  \param  gpio_type: Pointer to the storage of GPIO interrupt type (index 
*                     matches with gpio_num)
*  \param  count: size of gpio_num and gpio_type buffers (should match).
*  \return 0: on success, -1 on error
*
*/
i32 cc_gpio_get_spl_purpose(u8 *gpio_num,
                            u8 *gpio_type,
                            i32 count);

/*!
*  \brief Get the callback regitered with the GPIO HAL.
*  \param  None.
*  \return registered callback, NULL if unregistered
*
*/
notification_cb cc_gpio_get_callback();

/*!
*  \brief GPIO wake interrupt handler.
*  \param  intr_param: parametered registered with the ISR 
*  \return None
*
*/
void gpio_wake_interrupt_handler(void *intr_param);

/*!
*  \brief Save the GPIO context.
*  \param  None.
*  \return None
*
*/
void cc_gpio_save_context();

/*!
*  \brief Restore the GPIO context.
*  \param  None.
*  \return None
*
*/
void cc_gpio_restore_context();

#endif //__GPIO_HAL_H__
