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

#include <stdio.h>
#include <string.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "inc/hw_gpio.h"
#include "inc/hw_common_reg.h"
#include "driverlib/rom.h"
#include "driverlib/rom_map.h"
#include "driverlib/gpio.h"
#include "inc/hw_ints.h"
#include "driverlib/interrupt.h"

#include "cc_types.h"
#include "cc_pm.h"
#include "interrupt_hal.h"
#include "gpio_hal.h"

#define EXTRACT_PORT(gpio)      (gpio >> 3)
#define EXTRACT_PIN(gpio)       (gpio & 0x7)
#define RET_IF_TRUE(condition)  {if(condition) return -1;}

struct gpio_port_settings {
        u8 pin_status;    /* Pins currently in use */
        u8 pin_state;     /* State of the pin in use */
        u8 pin_direction; /* Direction of the pin in use */
        u8 pin_int_en;    /* Interrupt enabled on the pin */
        u32 pin_inttype;    /* Interrupt type */
        u8 pin_wake_src;  /* Is the pin a wake source */
};

struct gpio_port_details {
        struct gpio_port_info port_info;
        struct gpio_port_settings curr_port_settings;
};

struct cc_gpio_control {
        struct gpio_port_details port_details[MAX_GPIO_PORTS];
        i32 (*drv_notify_cb)(i32 gpio_num);
        sys_irq_enbl   enbl_irqc;
        sys_irq_dsbl   dsbl_irqc;
};

struct cc_gpio_control gpio_control;

/* Common Interrupt handler. Invokes the notification */
void gpio_interrupt_handler(void *intr_param)
{
        i32 indx;
        u32 intr_status, gpio_num;
        u8 port_num = 0;
        /* Get the handle to the port */
        struct gpio_port_info *intr_port = 
                (struct gpio_port_info *)intr_param;
        notification_cb drv_notify;
        drv_notify = gpio_control.drv_notify_cb;

        /* Get the interrupt status */
        intr_status = MAP_GPIOIntStatus(intr_port->base_addr, 1);

        /* Identify the port */
        for(indx = 0; indx < MAX_GPIO_PORTS; indx++) {
                if(gpio_control.port_details[indx].port_info.base_addr == \
                        intr_port->base_addr) {
                        port_num = indx;
                        break;
                }
        }

        if(drv_notify) {
                /* Identify the pin */
                for(indx = 0; indx < 7; indx++) {
                        if(intr_status & (1 << indx)) {
                                /* Invoke the notify routine */
                                gpio_num = (port_num << 3) | indx;
                                drv_notify(gpio_num);
                        }
                }
        }
        
        /* CLear the interrupt status */
        MAP_GPIOIntClear(intr_port->base_addr, intr_status);

        return;
}

/* GPIO handler to manage wake events based on GPIO */
void gpio_wake_interrupt_handler(void *intr_param)
{
        i32 gpio_num = *((i32 *)intr_param);
        notification_cb drv_notify;
        
        drv_notify = gpio_control.drv_notify_cb;        

        /* Notify the occurance of GPIO wake interrupt */
        if(drv_notify) {
                drv_notify(gpio_num);
        }
}

/* Initialize the GPIO module */
i32 cc_gpio_init(const struct cc_gpio_config *gpio_info)
{
        struct cc_gpio_control *gpio_ctrl = &gpio_control;
        struct gpio_port_info *port_info;
        i32 loopcnt;
        
        /* Clear the contents of the control register */
        memset(gpio_ctrl, 0, sizeof(struct cc_gpio_control));

        for(loopcnt = 0; loopcnt < MAX_GPIO_PORTS; loopcnt++) {
                port_info = &gpio_ctrl->port_details[loopcnt].port_info;
                
                if(gpio_info->port_info[loopcnt].module_id != 0) {
                    /* Copy the platform specific data */
                    memcpy(port_info,
                            &gpio_info->port_info[loopcnt],
                            sizeof(struct gpio_port_info));
                    /* Register with system INTC for irqvec_id */
                    register_isr(port_info->irqvec_id, 
                            gpio_interrupt_handler, 
                            (void *)port_info);
                }
        }
        
        gpio_ctrl->drv_notify_cb = gpio_info->drv_notify_cb;
        gpio_ctrl->enbl_irqc = gpio_info->enbl_irqc;
        gpio_ctrl->dsbl_irqc = gpio_info->dsbl_irqc;

        return 0;
}

/*
  Indicate the begining of usage and setup the direction 
  (input/output) of the specified GPIO.
*/
cc_hndl cc_gpio_open(i32 gpio_num, enum gpio_dir direction)
{
		u32 intr_mask;
        u32 port_num = 0;
        u8 pin_num, bitmask_pin;

        struct gpio_port_settings *curr_port_settings;
        struct gpio_port_info *port_info;

        /* Extract the port and pin number from the gpio_num */
        port_num = EXTRACT_PORT(gpio_num);
        pin_num = EXTRACT_PIN(gpio_num);
        bitmask_pin = (1 << pin_num);

        /* Check the validity of the port number */
        if(port_num >= MAX_GPIO_PORTS) {
                return NULL;
        }

        curr_port_settings = 
                &gpio_control.port_details[port_num].curr_port_settings;
        port_info = &gpio_control.port_details[port_num].port_info;

        /* Check the validity of the pin */
        if(!(port_info->validity_mask & bitmask_pin)) {
                return NULL;
        }

        intr_mask = gpio_control.dsbl_irqc();

        /* Setup the status to indicate in use */
        curr_port_settings->pin_status |= bitmask_pin;

        /* Setup the direction of operation */
        if(GPIO_DIR_OUTPUT == direction) {
                MAP_GPIODirModeSet(port_info->base_addr, 
                                          bitmask_pin,
                                          GPIO_DIR_MODE_OUT);
                curr_port_settings->pin_direction |= bitmask_pin;
        } else {
                MAP_GPIODirModeSet(port_info->base_addr, 
                                          bitmask_pin,
                                          GPIO_DIR_MODE_IN);
                curr_port_settings->pin_direction &= ~bitmask_pin;
        }

        gpio_control.enbl_irqc(intr_mask);
        
        return &gpio_control.port_details[port_num];
}

/* Indicate the stop of usage of the specified GPIO */
i32 cc_gpio_close(cc_hndl gpio_hndl, i32 gpio_num)
{
		u32 intr_mask;
        u32 port_num = 0;
        u8 pin_num, bitmask_pin;

        struct gpio_port_details *port_details = 
                (struct gpio_port_details *)gpio_hndl;
        struct gpio_port_settings *curr_port_settings = 
                                &port_details->curr_port_settings;
        struct gpio_port_info *port_info = 
                                &port_details->port_info;

        /* Extract the port and pin number from the gpio_num */
        port_num = EXTRACT_PORT(gpio_num);
        pin_num = EXTRACT_PIN(gpio_num);
        bitmask_pin = (1 << pin_num);

        /* Check the validity of the port number */
        RET_IF_TRUE(port_num >= MAX_GPIO_PORTS);

        /* Check the validity of the pin */
        RET_IF_TRUE(!(port_info->validity_mask & bitmask_pin));

        intr_mask = gpio_control.dsbl_irqc();

        /* Reset the control variables of the pin */
        curr_port_settings->pin_status &= ~bitmask_pin;
        curr_port_settings->pin_state &= ~bitmask_pin;
        curr_port_settings->pin_direction &= ~bitmask_pin;

        gpio_control.enbl_irqc(intr_mask);
        
        return 0;
}

/* Read from the specified GPIO */
i32 cc_gpio_read(cc_hndl gpio_hndl, i32 gpio_num, i8 *gpio_val)
{
		u32 intr_mask;
        u32 port_num = 0;
        u8 pin_num, bitmask_pin;
        u32 gpio_reg_val;

        struct gpio_port_details *port_details = 
                (struct gpio_port_details *)gpio_hndl;
        struct gpio_port_settings *curr_port_settings = 
                                &port_details->curr_port_settings;
        struct gpio_port_info *port_info = 
                                &port_details->port_info;

        /* Extract the port and pin number from the gpio_num */
        port_num = EXTRACT_PORT(gpio_num);
        pin_num = EXTRACT_PIN(gpio_num);
        bitmask_pin = (1 << pin_num);

        /* Check the validity of the port number */
        RET_IF_TRUE(port_num >= MAX_GPIO_PORTS);

        /* Check the validity of the pin */
        RET_IF_TRUE(!(port_info->validity_mask & bitmask_pin));

        /* Check if the pin has been registered for usage */
        RET_IF_TRUE(!(curr_port_settings->pin_status & bitmask_pin));

        intr_mask = gpio_control.dsbl_irqc();

        /* Read from the specified GPIO */
        gpio_reg_val = MAP_GPIOPinRead(port_info->base_addr, bitmask_pin);
        *gpio_val = (i8)((gpio_reg_val & bitmask_pin) >> pin_num);
        *gpio_val &= 0x1;
        curr_port_settings->pin_state &= ~bitmask_pin;
        curr_port_settings->pin_state |= (*gpio_val << pin_num);
        
        gpio_control.enbl_irqc(intr_mask);

        return 0;
}

/* Write to the specified GPIO */
i32 cc_gpio_write(cc_hndl gpio_hndl, i32 gpio_num, i8 gpio_val)
{
		u32 intr_mask;
        u32 port_num = 0;
        u8 pin_num, bitmask_pin, bitmask_val;

        struct gpio_port_details *port_details = 
                (struct gpio_port_details *)gpio_hndl;
        struct gpio_port_settings *curr_port_settings = 
                                &port_details->curr_port_settings;
        struct gpio_port_info *port_info = 
                                &port_details->port_info;

        /* Extract the port and pin number from the gpio_num */
        port_num = EXTRACT_PORT(gpio_num);
        pin_num = EXTRACT_PIN(gpio_num);
        bitmask_pin = (1 << pin_num);

        /* Check the validity of the port number */
        RET_IF_TRUE(port_num >= MAX_GPIO_PORTS);

        /* Check the validity of the pin */
        RET_IF_TRUE(!(port_info->validity_mask & bitmask_pin));

        /* Check if the pin has been registered for usage */
        RET_IF_TRUE(!(curr_port_settings->pin_status & bitmask_pin));

        intr_mask = gpio_control.dsbl_irqc();

        /* Write to the specified GPIO */
        bitmask_val = (gpio_val & 0x1) << pin_num;
        MAP_GPIOPinWrite(port_info->base_addr, bitmask_pin, bitmask_val);
        curr_port_settings->pin_state &= ~bitmask_pin;
        curr_port_settings->pin_state |= bitmask_val;
        
        gpio_control.enbl_irqc(intr_mask);

        return 0;
}

/* Toggle the specified GPIO */
i32 cc_gpio_toggle(cc_hndl gpio_hndl, i32 gpio_num)
{
		u32 intr_mask;
        u32 port_num = 0;
        u8 pin_num, bitmask_pin, bitmask_val, gpio_val, temp;
        u32 gpio_reg_val;

        struct gpio_port_details *port_details = 
                (struct gpio_port_details *)gpio_hndl;
        struct gpio_port_settings *curr_port_settings = 
                                &port_details->curr_port_settings;
        struct gpio_port_info *port_info = 
                                &port_details->port_info;

        /* Extract the port and pin number from the gpio_num */
        port_num = EXTRACT_PORT(gpio_num);
        pin_num = EXTRACT_PIN(gpio_num);
        bitmask_pin = (1 << pin_num);

        /* Check the validity of the port number */
        RET_IF_TRUE(port_num >= MAX_GPIO_PORTS);

        /* Check the validity of the pin */
        RET_IF_TRUE(!(port_info->validity_mask & bitmask_pin));

        /* Check if the pin has been registered for usage */
        RET_IF_TRUE(!(curr_port_settings->pin_status & bitmask_pin));

        intr_mask = gpio_control.dsbl_irqc();

        /* Read from the specified GPIO */
        gpio_reg_val = MAP_GPIOPinRead(port_info->base_addr, bitmask_pin);
        gpio_val = (gpio_reg_val & bitmask_pin) >> pin_num;
        temp = (gpio_val > 0)? 0x0: 0x1;
        bitmask_val = (temp << pin_num);
        MAP_GPIOPinWrite(port_info->base_addr, bitmask_pin, bitmask_val);
        curr_port_settings->pin_state |= bitmask_val;
        
        gpio_control.enbl_irqc(intr_mask);

        return 0;
}

/* Enable the interrupt and subsequent notification on the specified 
*  GPIO on the occurance of the specified interrupt type.
*/
i32 cc_gpio_enable_notification(cc_hndl gpio_hndl, 
                                i32 gpio_num, 
                                enum gpio_int_type gpio_type,
                                i32 flags)
{
		u32 intr_mask;
        u32 port_num = 0;
        u8 pin_num, bitmask_pin;

        struct gpio_port_details *port_details = 
                (struct gpio_port_details *)gpio_hndl;
        struct gpio_port_settings *curr_port_settings = 
                                &port_details->curr_port_settings;
        struct gpio_port_info *port_info = 
                                &port_details->port_info;

        /* Extract the port and pin number from the gpio_num */
        port_num = EXTRACT_PORT(gpio_num);
        pin_num = EXTRACT_PIN(gpio_num);
        bitmask_pin = (1 << pin_num);

        /* Check the validity of the port number */
        RET_IF_TRUE(port_num >= MAX_GPIO_PORTS);

        /* Check the validity of the pin */
        RET_IF_TRUE(!(port_info->validity_mask & bitmask_pin));

        /* Check if the pin has been registered for usage */
        RET_IF_TRUE(!(curr_port_settings->pin_status & bitmask_pin));

        if(flags & GPIO_TYPE_WAKE_SOURCE) {
                /* Check the validity of the pin as wake source */
                RET_IF_TRUE(!(port_info->special_purpose_mask & bitmask_pin));
        }
        intr_mask = gpio_control.dsbl_irqc();

        if(flags & GPIO_TYPE_NORMAL) {
                /* Set the interrupt type */
                MAP_GPIOIntTypeSet(port_info->base_addr, bitmask_pin, gpio_type);

                /* Enable the interrupt */
                MAP_GPIOIntClear(port_info->base_addr,bitmask_pin);
                MAP_GPIOIntEnable(port_info->base_addr,bitmask_pin);

                curr_port_settings->pin_int_en |= bitmask_pin;
        }

        if(flags & GPIO_TYPE_WAKE_SOURCE) {
                curr_port_settings->pin_wake_src |= bitmask_pin;
        }

        curr_port_settings->pin_inttype &= ~(0xF << (pin_num * 2));
        curr_port_settings->pin_inttype |= 
                        ((gpio_type & 0xF) << (pin_num * 2));

        gpio_control.enbl_irqc(intr_mask);

        return 0;
}

/* Disable the interrupt on the specified GPIO. */
i32 cc_gpio_disable_notification(cc_hndl gpio_hndl, 
                                i32 gpio_num)
{
		u32 intr_mask;
        u32 port_num = 0;
        u8 pin_num, bitmask_pin;

        struct gpio_port_details *port_details = 
                (struct gpio_port_details *)gpio_hndl;
        struct gpio_port_settings *curr_port_settings = 
                                &port_details->curr_port_settings;
        struct gpio_port_info *port_info = 
                                &port_details->port_info;

        /* Extract the port and pin number from the gpio_num */
        port_num = EXTRACT_PORT(gpio_num);
        pin_num = EXTRACT_PIN(gpio_num);
        bitmask_pin = (1 << pin_num);

        /* Check the validity of the port number */
        RET_IF_TRUE(port_num >= MAX_GPIO_PORTS);

        /* Check the validity of the pin */
        RET_IF_TRUE(!(port_info->validity_mask & bitmask_pin));

        /* Check if the pin has been registered for usage */
        RET_IF_TRUE(!(curr_port_settings->pin_status & bitmask_pin));

        intr_mask = gpio_control.dsbl_irqc();

        /* Disable the interrupt */
        MAP_GPIOIntDisable(port_info->base_addr,bitmask_pin);

        curr_port_settings->pin_int_en &= ~bitmask_pin;
        curr_port_settings->pin_inttype &= ~(0xF << (pin_num * 2));
        curr_port_settings->pin_wake_src &= ~bitmask_pin;

        gpio_control.enbl_irqc(intr_mask);

        return 0;
}

/* Get the details of all GPIO status */
i32 cc_gpio_get_spl_purpose(u8 *gpio_num,
                            u8 *gpio_type,
                            i32 count)
{
        i32 loop_cnt, indx, buf_indx = -1;
        u8 pin_select;

        struct gpio_port_settings *port_status;
        struct gpio_port_info *port_info;

        if((NULL == gpio_num) || (NULL == gpio_type) || (count == 0)) {
                return -1;
        }

        for(loop_cnt = 0; loop_cnt < MAX_GPIO_PORTS; loop_cnt++) {
                port_status =
                    &gpio_control.port_details[loop_cnt].curr_port_settings;
                port_info = &gpio_control.port_details[loop_cnt].port_info;

                pin_select = port_status->pin_wake_src & 
                                port_info->special_purpose_mask;
                if(pin_select) {
                        /* Found a port with spl. pin in use */
                        /* Find the index of the first occurance */
                        for(indx = 0; indx < 8; indx++) {
                                if(pin_select & (1 << indx)) {
                                        buf_indx++;
                                        if(buf_indx == (count - 1)) {
                                                return count;
                                        }
                                        gpio_num[buf_indx] = 
                                                (loop_cnt << 3) | indx;
                                        gpio_type[buf_indx] = 
                                                (port_status->pin_inttype >> 
                                                        (indx *2)) & 0xF;
                                }
                        }
                }
        }

        return (buf_indx + 1);
}

/* Get the callback regitered with the GPIO HAL. */
notification_cb cc_gpio_get_callback()
{
        /* Retunr the registered callback */
        return gpio_control.drv_notify_cb;
}

/* Save the GPIO context */
void cc_gpio_save_context()
{
        /* Save anu registers if required */

        return;
}

/* Restore the GPIO port context */
void restore_gpio_port(struct gpio_port_settings *curr_port_settings, 
                       struct gpio_port_info *port_info)
{
        i32 indx;
        u8 bitmask_pin;
        u16 gpio_type;

        for(indx = 0; indx < 8; indx++) {
                bitmask_pin = (1 << indx);
                if(curr_port_settings->pin_status & bitmask_pin) {
                        /* Setup the direction of the GPIO */
                        if(curr_port_settings->pin_direction 
                                & bitmask_pin) {
                                  MAP_GPIODirModeSet(
                                          port_info->base_addr,
                                          bitmask_pin,
                                          GPIO_DIR_MODE_OUT);
                        } else {
                                  MAP_GPIODirModeSet(
                                          port_info->base_addr,
                                          bitmask_pin,
                                          GPIO_DIR_MODE_IN);
                        }

                        /* For GPIOs on which interrupts are enabled,
                           restore the interrupt settings */
                        if(curr_port_settings->pin_int_en & bitmask_pin) {
                                gpio_type = curr_port_settings->pin_inttype & 
                                            (0xF << (indx * 2));
                                gpio_type >>= (indx * 2);
                                /* Set the interrupt type */
                                MAP_GPIOIntTypeSet(port_info->base_addr, 
                                        bitmask_pin, gpio_type);
                                /* Enable the interrupt */
                                MAP_GPIOIntClear(port_info->base_addr,
                                                 bitmask_pin);
                                MAP_GPIOIntEnable(port_info->base_addr,
                                                  bitmask_pin);
                        } else {
                                /* For output GPIOs, restore the GPIO state */
                                if(curr_port_settings->pin_direction 
                                        & bitmask_pin) {
                                          MAP_GPIOPinWrite(
                                                  port_info->base_addr, 
                                                  bitmask_pin, 
                                                  curr_port_settings->pin_state);
                                }
                        }
                }
        }
}

/* Restore the GPIO context */
void cc_gpio_restore_context()
{
		u32 intr_mask;
        struct cc_gpio_control *gpio_ctrl = &gpio_control;
        struct gpio_port_details *port_details;
        struct gpio_port_info *port_info;
        struct gpio_port_settings *curr_port_settings;
        i32 loopcnt;
        
        intr_mask = gpio_control.dsbl_irqc();

        /* Traverse each port and restore the GPIO state */ 
        for(loopcnt = 0; loopcnt < MAX_GPIO_PORTS; loopcnt++) {
                port_details = &gpio_ctrl->port_details[loopcnt];
                curr_port_settings = &port_details->curr_port_settings;
                port_info = &port_details->port_info;

                if(curr_port_settings->pin_status) {
                        restore_gpio_port(curr_port_settings, port_info);
                }
        }

        gpio_control.enbl_irqc(intr_mask);

}
