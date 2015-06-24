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

#ifndef UART_HAL_H__
#define UART_HAL_H__

#include "cc_types.h"
#include "stdint.h"

#define MAX_UART_MODULES         2

typedef void* cc31xx_hndl;

enum cc_transfer_mode{
        e_poll_based,
        e_int_based,
        e_dma_based
};

enum cc_uart_event{
		write_complete,
		write_fail,
		read_complete,
		read_fail
};

enum cc_fifo_trig_level{

        e_one_eighth = 0x1,
        e_one_fourth = 0x2,
        e_one_half = 0x4,
        e_three_fourth = 0x6,
        e_seven_eighth = 0x7
};

enum cc_boolean{

        e_false = 0x0,
        e_true = 0x1
};

enum cc_uart_ctrl_cmd{

        e_rx_change_mode,
        e_tx_change_mode,
        e_change_rx_fifo_trig,
        e_change_tx_fifo_trig,
        e_enable_disable_fifo,
        e_get_dma_info,
        e_start_tx_dma_transfer,
        e_start_rx_dma_transfer,
        e_context_save,
        e_context_restore
};

struct uart_dma_info{
		u32 tx_reg_addr;       /* Transmit register address */
		u32 tx_dma_ch;         /* DMA channel for transmit */
		u32 rx_reg_addr;       /* Receive register address */
		u32 rx_dma_ch;         /* DMA channel for receive */

};
struct cc_uart_info{

        u32 base_addr;         /* base address of the uart module */
        u32 inp_clk;           /* input clock frequency given to the uart module*/
        u32 baud_rate;         /* baud rate */
        u32 config_reg;        /* config for the data format */
        u32 fifo_size;         /* fifo size for tx and rx. by default 16 bytes long*/
        i32 (*int_callback)(void *rtos_hndl, enum cc_uart_event event,
                void *evt_data, void *cookie);     /* interrupt callback function */

};

struct cc_uart_config{
        /* Platform details */
        u32 module_id;      /* Peripheral identifier of UART module  */
        struct cc_uart_info module_info;

        struct uart_dma_info dma_info;
		/* transfer modes for tx and rx */
		enum cc_transfer_mode rx_transfer_mode;
		enum cc_transfer_mode tx_transfer_mode;

		/* fifo configurations */
		enum cc_fifo_trig_level rx_fifo_trig_level;
		enum cc_fifo_trig_level tx_fifo_trig_level;
		enum cc_boolean fifo_enabled;

		/* echo feature */
		enum cc_boolean echo_enabled;
        u8 irqvec_id;                  /* Interrupt vector number */

        void *rtos_hndl;               /* Reference to RTOS driver object */ 
};

extern void cc_uart_int_callback();

extern cc_hndl cc_uart_init(const struct cc_uart_config *uart_config);
extern i32 cc_uart_deinit(cc_hndl hndl);
extern i32 cc_uart_rd_submit(cc_hndl hndl,uint8_t *rd_data,
                             uint32_t rd_size, void *cookie);
extern i32 cc_uart_wr_submit(cc_hndl hndl,uint8_t *wrt_data,
                              uint32_t wrt_size, void *cookie);

extern i32 cc_uart_control(cc_hndl hndl, enum cc_uart_ctrl_cmd cmd,
                           void *arg);
void cc_uart_isr(cc_hndl uart_hndl);

#endif // UART_DRIVER_H_INCLUDED
