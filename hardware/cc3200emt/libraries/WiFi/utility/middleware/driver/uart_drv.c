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
#include <stdbool.h>
#include "hw_types.h"
#include "prcm.h"
#include "uart.h"
#include "osi.h"
#include "cc_types.h"
#include "cc_pm.h"
#include "dma_hal.h"
#include "uart_hal.h"
#include "uart_drv.h"
#include "interrupt_hal.h"

#define DMA_BUFF_SIZE_MIN		80

struct uart_rtos_driver{
        
        /* RTOS implementation specific */
        u32            device_id;
        struct module_drv       hal_driver;
        cc_hndl                 hal_handle;
        cc_hndl                 tx_dma_hndl;
        cc_hndl                 rx_dma_hndl;
        OsiSyncObj_t            sync_obj;
        OsiLockObj_t            lock_obj;
        u32            ref_cnt;
        /* Operating mode - Polled, Interrupt or DMA based transfer */
        enum cc_transfer_mode   tx_oper_mode;
        enum cc_transfer_mode	rx_oper_mode;
        u32            temp_store;
};

struct uart_rtos_driver uart_rtos_drv[MAX_UART_MODULES];

void uart_interrupt_handler(cc_hndl hal_handle)
{
        /* Invoke the UART event handler */
        cc_uart_isr(hal_handle);

        return;
}

/* Callback function invoked by UART HAL */
i32 uart_callback_from_hal(void *rtos_hndl, enum cc_uart_event event,
                                 void *evt_data, void *cookie)
{
		struct uart_rtos_driver *rtos_drv =
	                (struct uart_rtos_driver *)rtos_hndl;
		switch(event) {

		        case write_complete:
		        case write_fail:
		        case read_complete:
		        case read_fail:
                        /* pending data to write */
		                *(i32*) cookie = *(i32*)evt_data; 
		                break;

		        default:
		                break;
		        }

		        RTOS_SEM_SIGNAL(&rtos_drv->sync_obj);

		        return 0;
}
/* Reset the UART rtos driver pool */
static void reset_uart_rtosdrv()
{
        i32 loop_cnt;

        /* Clear the inuse pointers to indicate availability 
         * of all control structure */
        for(loop_cnt = 0; loop_cnt < MAX_UART_MODULES; loop_cnt++) {
                /* Clear the UART control structure */
                memset(&uart_rtos_drv[loop_cnt], 0, 
                        sizeof(struct uart_rtos_driver));
        }
}

/* Free up the UART rtos driver structure */
static i32 free_uart_rtosdrv(struct uart_rtos_driver *uart_rtos_hndl)
{
        i32 loop_cnt;
        i32 ret = -1;

        /* Free up the UART rtos driver structure of the specified handle */
        for(loop_cnt = 0; loop_cnt < MAX_UART_MODULES; loop_cnt++) {
                if(uart_rtos_hndl == &uart_rtos_drv[loop_cnt]) {
                        ret = 0;
                        /* Clear the UART rtos driver structure */
                        memset(&uart_rtos_drv[loop_cnt], 0, 
                                sizeof(struct uart_rtos_driver));
                        break;
                }
        }
        return ret;
}

/* Get an available UART rtos driver structure from the pool */
static struct uart_rtos_driver* get_available_uart_rtosdrv()
{
        i32 loop_cnt;
        struct uart_rtos_driver *temp_store = NULL;

        /* Find an available rtos driver structure and return a handle */
        for(loop_cnt = 0; loop_cnt < MAX_UART_MODULES; loop_cnt++) {
                if(0 == uart_rtos_drv[loop_cnt].hal_handle) {
                        temp_store = &uart_rtos_drv[loop_cnt];
                        break;
                }
        }
        return temp_store;
}

/*
   Check if the requested UART module is already in use. This is 
   acheived by comparing the base address.
*/
static struct uart_rtos_driver* check_uart_rtosdrv_inuse(u32 dev_id)
{
        i32 loop_cnt;
        struct uart_rtos_driver *temp_store = NULL;

        /* Check if any of the control structures
         * already refer to the base address as specified in the UART info
         * structure. If yes return the handle to that structure */
        for(loop_cnt = 0; loop_cnt < MAX_UART_MODULES; loop_cnt++) {
                if(uart_rtos_drv[loop_cnt].device_id == dev_id) {
                        temp_store = &uart_rtos_drv[loop_cnt];
                        break;
                }
        }
        return temp_store;
}

/* Setup the DMA parameters */
static void setup_uart_dma(cc_hndl *dma_hndl,
                 void *dst_buf,
                 void *src_buf,
                 u32 transfer_len,
                 u32 word_len_bits,
                 u8 transfer_type)
{
        /* Transmit DMA descriptor configuration */
        struct cc_dma_cmd_desc dma_cmd_desc, *cmd_desc;

        cmd_desc = &dma_cmd_desc;

        cmd_desc->mode_dma = DMA_BASIC_REQ;
        cmd_desc->buf_type= DMA_TYPE_08_BITS;
        cmd_desc->arb_size = ARB_0008_ITEM;
        cmd_desc->do_burst = true;
        if(transfer_type == UART_DMA_TX){
        		cmd_desc->src_incr = DMA_INCR_08_BITS;
        	    cmd_desc->dst_incr = DMA_INCR_NO_INCR;
        }else if(transfer_type == UART_DMA_RX){
        		cmd_desc->src_incr = DMA_INCR_NO_INCR;
        	    cmd_desc->dst_incr = DMA_INCR_08_BITS;
        }
        /* Setup the DMA for the write */
        cc_dma_desc_config(dma_hndl, cmd_desc);
        /* Configure the src, dst and size for write */
        cc_dma_submit_endp(dma_hndl, src_buf, dst_buf, transfer_len, false);
}

/* Setup the UART and DMA modules to initiate the transfer */
static void setup_dma_transfer(struct uart_rtos_driver *rtos_hndl,
                   const i8 *tx_data, i8 *rx_data,
                   i32 size)
{
    	struct uart_dma_info dma_info = { 0, 0, 0, 0 };
        u32 word_len = 8;

        /* Get the UART DMA specific info */
        cc_uart_control(rtos_hndl->hal_handle, e_get_dma_info,
                       &dma_info);
        if(tx_data && rx_data) { /* FULL DUPLEX */
                /* Setup the dma for the write transfer */
                setup_uart_dma(rtos_hndl->tx_dma_hndl,
                              (void *)dma_info.tx_reg_addr,
                              (void *)tx_data,
                              size, word_len, UART_DMA_TX);

                /* Setup the dma for the read transfer */
                setup_uart_dma(rtos_hndl->rx_dma_hndl,
                              rx_data,
                              (void *)dma_info.rx_reg_addr,
                              size, word_len, UART_DMA_RX);

        } else if (tx_data) { /* HALF DUPLEX WRITE */
                /* Setup the dma for the write transfer */
                setup_uart_dma(rtos_hndl->tx_dma_hndl,
                              (void *)dma_info.tx_reg_addr,
                              (void *)tx_data,
                              size, word_len, UART_DMA_TX);

        } else { /* HALF DUPLEX READ */

                /* Setup the dma for the dummy read transfer */
                setup_uart_dma(rtos_hndl->rx_dma_hndl,
                              rx_data,
                              (void *)dma_info.rx_reg_addr,
                              size, word_len, UART_DMA_RX);
        }
}

/*
   Trigger the UART DMA transfer. The parameters passed is used to identify the
   mode of operation.
        tx_data: !NULL, rx_data: NULL --> Half duplex write
        tx_data: NULL, rx_data: !NULL --> Half duplex read
        tx_data: !NULL, rx_data: !NULL --> Full duplex write-read
*/
static void trigger_uart_dma_transfer(struct uart_rtos_driver *rtos_drv,
                        const i8 *tx_data,
                        i8 *rx_data,
                        i32 size)
{
        i32 enable = 1;

        /* Setup the DMA module for the transfer */
        setup_dma_transfer(rtos_drv, tx_data, rx_data, size);

        /* Initiate the DMA transfer */
        if(tx_data != NULL){
				cc_uart_control(rtos_drv->hal_handle,
							   e_start_tx_dma_transfer,
							   &enable);
        }
        if(rx_data != NULL){
        				cc_uart_control(rtos_drv->hal_handle,
        							   e_start_rx_dma_transfer,
        							   &enable);
        }
}

/*
   The function checks if the request state transition can be supported
   and also initiates the corresponding action with the HAL.
*/
i32 uart_handle_pm_cmd(struct module_drv *mod_drv, const enum mod_pm pm_state)
{
        i32 retval = -1;
        struct uart_rtos_driver *rtos_drv =
                (struct uart_rtos_driver *)mod_drv->rtos_drv;

        /* Check if any of the transactions are ongoing */
        if(rtos_drv->lock_obj) {
                retval = RTOS_MUTEX_ACQUIRE_IMM(&rtos_drv->lock_obj);
                if(retval < 0) {
                        /* Cannot transition power modes as transaction
                           in progress */
                        goto exit;
                }
        }

        /* Handle the transition into the desired state */
        if((e_pm_M0 == mod_drv->pm_state) && (e_pm_M4 == pm_state)) {
                /* Save the peripheral context */
                retval = cc_uart_control(rtos_drv->hal_handle,
                						 e_context_save, NULL);
                if(retval < 0) {
                        goto exit1;
                }
                /* Update the module state ?? */
                mod_drv->pm_state = e_pm_M4;
        } else if((e_pm_M4 == mod_drv->pm_state) && (e_pm_M0 == pm_state)) {
                /* Restore the peripheral context */
                retval = cc_uart_control(rtos_drv->hal_handle,
                						e_context_restore, NULL);
                if(retval < 0) {
                        goto exit1;
                }
                /* Update the module state ?? */
                mod_drv->pm_state = e_pm_M0;
        } else {
                /* unsupported state transition */
                goto exit1;
        }

exit1:
        if(rtos_drv->lock_obj) {
                RTOS_MUTEX_RELEASE(&rtos_drv->lock_obj);
        }
exit:
        return retval;
}

/*
   This function should be called from centralized & RTOS specific
    initialization sequence.

   Goal of this function is to extend information about SOC module to SW driver
   enable it to initialize hardware through HAL. Driver could use private field
   called 'hw_detail', if provisioned, to configure hardware.

   Driver instance must enroll / register itself with PM / platfrom framework.

*/
i32 uart_driver_load(struct soc_module *uart_module)
{
        struct uart_rtos_driver *uart_rtos_drv_hndl;
        i32 ret_val;
        struct cc_uart_config *uart_config =
                (struct cc_uart_config *)uart_module->hw_detail;
        cc_hndl hndl;
        struct cc_dma_chan_cfg chan_config;

        /* Reset the UART driver structure once in the begining */
        reset_uart_rtosdrv();

        /* Initialize the UART RTOS driver */
        uart_rtos_drv_hndl = check_uart_rtosdrv_inuse(uart_config->module_id);
        if(NULL == uart_rtos_drv_hndl) {
                /* Acquire a new rtos driver structure from the list */
                uart_rtos_drv_hndl = get_available_uart_rtosdrv();
                if(NULL == uart_rtos_drv_hndl) {
                        /* Something wrong - should have failed at uart_init */
                        goto exit1; /* Error */
                }
        } else {
                /* Module already in use. TBD?? */
                goto exit1;
        }

        /* Assign call back routines into uart_config structure for HAL  */
        (uart_config->module_info).int_callback = uart_callback_from_hal;
        uart_config->rtos_hndl = (void *)uart_rtos_drv_hndl;

        /* Initialize the UART HAL */
        hndl = cc_uart_init(uart_config);
        if(NULL == hndl) {
                goto exit2; /* Error */
        }

        /* Initialize the module driver structure */
        uart_rtos_drv_hndl->device_id = uart_config->module_id;
        uart_rtos_drv_hndl->hal_driver.hw_module = NULL;
        uart_rtos_drv_hndl->hal_driver.clk_state = e_clk_cut_off;
        uart_rtos_drv_hndl->hal_driver.pm_state = e_pm_M0;
        uart_rtos_drv_hndl->hal_driver.rtos_drv = uart_rtos_drv_hndl;
        uart_rtos_drv_hndl->hal_driver.goto2pm_mode = uart_handle_pm_cmd;
        uart_rtos_drv_hndl->sync_obj = NULL;
        uart_rtos_drv_hndl->lock_obj = NULL;
        uart_rtos_drv_hndl->tx_oper_mode = uart_config->tx_transfer_mode;
        uart_rtos_drv_hndl->rx_oper_mode = uart_config->rx_transfer_mode;

        /* Save HAL hndl in RTOS Driver structure */
        uart_rtos_drv_hndl->hal_handle = hndl;

        /* Setup the DMA based on the operation mode */
        chan_config.en_burst = false;
        chan_config.alt_cblk = false;
        chan_config.en_hwreq = false;
        chan_config.priority = false;

        uart_rtos_drv_hndl->rx_dma_hndl =
                cc_dma_alloc(uart_config->dma_info.rx_dma_ch,
                             (DMA_USER_UART0_RX +
                              2*(uart_config->module_id - PRCM_UARTA0)));
        cc_dma_chan_config(uart_rtos_drv_hndl->rx_dma_hndl, &chan_config);

        uart_rtos_drv_hndl->tx_dma_hndl =
                cc_dma_alloc(uart_config->dma_info.tx_dma_ch,
                		     (DMA_USER_UART0_TX +
                		      2*(uart_config->module_id - PRCM_UARTA0)));
        cc_dma_chan_config(uart_rtos_drv_hndl->tx_dma_hndl, &chan_config);

        /* Register with system INTC for irqvec_id */
        register_isr(uart_config->irqvec_id,
                uart_interrupt_handler,
                uart_rtos_drv_hndl->hal_handle);

        /* Register the module driver with the power management framework */
        ret_val = cc_module_drv_register(uart_module,
                                       &uart_rtos_drv_hndl->hal_driver);
        if(ret_val < 0) {
                goto exit3; /* Error */
        }

        /* RTOS driver may need to do some more house-keeping ........  */

        return 0; /* Need to be RTOS specific */

exit3:
        cc_module_drv_unregister(&uart_rtos_drv_hndl->hal_driver);
exit2:
        cc_uart_deinit(hndl);
        free_uart_rtosdrv(uart_rtos_drv_hndl);
exit1:
        return -1;
}


/* Open the UART module */
cc_hndl uart_open(u32 module_id)
{
        struct uart_rtos_driver *rtos_drv = NULL;
        i32 retval;

        /* Check if the driver has already been loaded */
        rtos_drv = check_uart_rtosdrv_inuse(module_id);
        if(NULL == rtos_drv) {
                /* Driver not loaded, return error */
                goto exit;
        }

        if(rtos_drv->lock_obj) {
                RTOS_MUTEX_ACQUIRE(&rtos_drv->lock_obj);
        } else {
                /* Create the lock and sync objects */
                retval = RTOS_SEM_CREATE(&rtos_drv->sync_obj);
                if(retval < 0) {
                        goto exit1;
                }
                retval = RTOS_MUTEX_CREATE(&rtos_drv->lock_obj);
                if(retval < 0) {
                        goto exit2;
                }

                RTOS_MUTEX_ACQUIRE(&rtos_drv->lock_obj);
        }

        /* increment the reference count */
        rtos_drv->ref_cnt++;

        RTOS_MUTEX_RELEASE(&rtos_drv->lock_obj);

        return rtos_drv;

exit2:
        RTOS_MUTEX_DELETE(&rtos_drv->lock_obj);
exit1:
        RTOS_SEM_DELETE(&rtos_drv->sync_obj);

        rtos_drv->lock_obj = NULL;
        rtos_drv->sync_obj = NULL;
exit:
        return NULL;
}

/* Close the UART module */
i32 uart_close(cc_hndl uart_drv_hndl)
{
        struct uart_rtos_driver *rtos_drv =
                (struct uart_rtos_driver *)uart_drv_hndl;

        RTOS_MUTEX_ACQUIRE(&rtos_drv->lock_obj);

        /* decrement the reference count */
        rtos_drv->ref_cnt--;

        RTOS_MUTEX_RELEASE(&rtos_drv->lock_obj);

        return 0;
}

i32 uart_write(cc_hndl uart_drv_hndl, i8 *wr_data, i32 size)
{
        i32 retval;
        struct uart_rtos_driver *rtos_drv =
                (struct uart_rtos_driver *)uart_drv_hndl;

        i32 wr_pend = -1;
        /* Can be part of RTOS framework */
        RTOS_MUTEX_ACQUIRE(&rtos_drv->lock_obj);

        /* Check the mode of transfer. If DMA, handle it here else invoke HAL */
        if(e_dma_based == rtos_drv->rx_oper_mode) {

                /* Initiate the UART transfer over DMA */
                trigger_uart_dma_transfer(rtos_drv, wr_data, NULL, size);

                RTOS_SEM_WAIT(&rtos_drv->sync_obj); /* RTOS function blocking */

        }else{
                if(0 > cc_uart_wr_submit(rtos_drv->hal_handle,
                                         (uint8_t*)wr_data, size,
                                         (void*)&wr_pend)) {
                        goto rtos_uart_drv_write_error;
                }
                if(e_int_based == rtos_drv->tx_oper_mode) {
                        /* RTOS function blocking */
                		RTOS_SEM_WAIT(&rtos_drv->sync_obj); 
                }
        }

 rtos_uart_drv_write_error:

        RTOS_MUTEX_RELEASE(&rtos_drv->lock_obj);

        UNUSED(retval);

        return (wr_pend < 0) ? -1 : (size - wr_pend);
}

/* Half duplex Read data over UART */
i32 uart_read(cc_hndl uart_drv_hndl, i8 *rd_data, i32 size)
{
        i32 retval;
        struct uart_rtos_driver *rtos_drv =
                (struct uart_rtos_driver *)uart_drv_hndl;

        i32 rd_pend = -1;

        RTOS_MUTEX_ACQUIRE(&rtos_drv->lock_obj);

        /* Check the mode of transfer. If DMA, handle it here else invoke HAL */
        if(e_dma_based == rtos_drv->rx_oper_mode) {
               /* Initiate the UART transfer over DMA */
                trigger_uart_dma_transfer(rtos_drv, NULL, rd_data, size);

                RTOS_SEM_WAIT(&rtos_drv->sync_obj);

        }else{
                if(0 > cc_uart_rd_submit(rtos_drv->hal_handle,
                                         (uint8_t*)rd_data, size,
                                         (void*)&rd_pend)) {
                        goto rtos_uart_drv_read_error;
                }
                if(e_int_based == rtos_drv->rx_oper_mode) {
                        /* RTOS function blocking */
                        RTOS_SEM_WAIT(&rtos_drv->sync_obj); 
                }
        }

 rtos_uart_drv_read_error:

        RTOS_MUTEX_RELEASE(&rtos_drv->lock_obj);

        UNUSED(retval);

        return (rd_pend < 0) ? -1 : (size - rd_pend);
}
