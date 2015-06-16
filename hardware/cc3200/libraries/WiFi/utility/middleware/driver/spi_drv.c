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
#include "hw_types.h"
#include "dma_hal.h"
#include "interrupt_hal.h"
#include "prcm.h"
#include "osi.h"
#include "cc_types.h"
#include "cc_pm.h"
#include "spi_hal.h"
#include "spi_drv.h"

#define SPI_DMA_TX              0x00000001
#define SPI_DMA_TX_NO_INCR      0x00000002
#define SPI_DMA_RX              0x00000010
#define SPI_DMA_RX_NO_INCR      0x00000020

#define DMA_BUFF_SIZE_MIN       (100)


struct rtos_spi_cb_info {
        i32 bytes2wr;
        i32 (*notify)(struct rtos_spi_cb_info *notice);
};

struct spi_rtos_driver {

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
        enum operation_mode     oper_mode;
        u32            temp_store;
};


struct spi_rtos_driver spi_rtos_drv[MAX_SPI_MODULES];
i8 is_spidrv_reset = 0;

void spi_interrupt_handler(cc_hndl hal_handle)
{
        /* Invoke the SPI event handler */
        cc_spi_isr(hal_handle);
        return;
}

/* Callback function invoked by SPI HAL */
i32 drv_callback_ops_complete(void *rtos_hndl, enum cc_spi_event event,
                                 void *evt_data, void *cookie)
{
        struct spi_rtos_driver *rtos_drv = 
                (struct spi_rtos_driver *)rtos_hndl;

        switch(event) {
                
        case SPI_EVT_TRANSFER_DONE: 
        case SPI_EVT_TRANSFER_FAIL:
                *(i32*) cookie = *(i32*)evt_data; /* pending data to write */
                break;
                
        default:
                break;
        }
        
        RTOS_SEM_SIGNAL(&rtos_drv->sync_obj); 
        
        return 0;
}


/* Reset the SPI rtos driver pool */
i32 spi_reset = 0;
static void reset_spi_rtosdrv()
{
        i32 loop_cnt;

        spi_reset = 1;
        /* Clear the inuse pointers to indicate availability 
         * of all control structure */
        for(loop_cnt = 0; loop_cnt < MAX_SPI_MODULES; loop_cnt++) {
                /* Clear the SPI control structure */
                memset(&spi_rtos_drv[loop_cnt], 0, 
                        sizeof(struct spi_rtos_driver));
        }
}

/*
   Check if the requested SPI module is already in use. This is 
   acheived by comparing the base address.
*/
static struct spi_rtos_driver* check_spi_rtosdrv_inuse(u32 dev_id)
{
        i32 loop_cnt;
        struct spi_rtos_driver *temp_store = NULL;

        /* Check if any of the control structures
         * already refer to the base address as specified in the SPI info
         * structure. If yes return the handle to that structure */
        for(loop_cnt = 0; loop_cnt < MAX_SPI_MODULES; loop_cnt++) {
                if(spi_rtos_drv[loop_cnt].device_id == dev_id) {
                        temp_store = &spi_rtos_drv[loop_cnt];
                        break;
                }
        }
        return temp_store;
}

/* Get an available SPI rtos driver structure from the pool */
static struct spi_rtos_driver* get_available_spi_rtosdrv()
{
        i32 loop_cnt;
        struct spi_rtos_driver *temp_store = NULL;

        /* Find an available rtos driver structure and return a handle */
        for(loop_cnt = 0; loop_cnt < MAX_SPI_MODULES; loop_cnt++) {
                if(0 == spi_rtos_drv[loop_cnt].hal_handle) {
                        temp_store = &spi_rtos_drv[loop_cnt];
                        break;
                }
        }
        return temp_store;
}

/* Free up the SPI rtos driver structure */
static i32 free_spi_rtosdrv(struct spi_rtos_driver *spi_rtos_hndl)
{
        i32 loop_cnt;
        i32 ret = -1;

        /* Free up the SPI rtos driver structure of the specified handle */
        for(loop_cnt = 0; loop_cnt < MAX_SPI_MODULES; loop_cnt++) {
                if(spi_rtos_hndl == &spi_rtos_drv[loop_cnt]) {
                        ret = 0;
                        /* Clear the SPI rtos driver structure */
                        memset(&spi_rtos_drv[loop_cnt], 0, 
                                sizeof(struct spi_rtos_driver));
                        break;
                }
        }
        return ret;
}

/* Setup the DMA descriptor parameters */
static void setup_dma_desc(struct cc_dma_cmd_desc *cmd_desc,
               u8 transfer_type,
               enum dma_type e_type,
               enum dma_incr e_incr)
{
        cmd_desc->buf_type = e_type;
        if(transfer_type & 0xF) {
                cmd_desc->dst_incr = DMA_INCR_NO_INCR;
                if(SPI_DMA_TX == transfer_type) {
                        cmd_desc->src_incr = e_incr;
                } else { /* SPI_DMA_TX_NO_INCR */
                        cmd_desc->src_incr = DMA_INCR_NO_INCR;
                }
        } else {
                cmd_desc->src_incr = DMA_INCR_NO_INCR;
                if(SPI_DMA_RX == transfer_type) {
                        cmd_desc->dst_incr = e_incr;
                } else { /* SPI_DMA_RX_NO_INCR */
                        cmd_desc->dst_incr = DMA_INCR_NO_INCR;
                }
        }

        return;
}

/* Setup the DMA parameters */
static void setup_spi_dma(cc_hndl *dma_hndl,
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
        cmd_desc->arb_size = ARB_0001_ITEM;
        cmd_desc->do_burst = false;

        if(SPI_WORDLEN_32 == word_len_bits) {
                
                setup_dma_desc(cmd_desc, 
                        transfer_type, DMA_TYPE_32_BITS, DMA_INCR_32_BITS);
                transfer_len /= 4;

        } else if(SPI_WORDLEN_16 == word_len_bits) {

                setup_dma_desc(cmd_desc, 
                        transfer_type, DMA_TYPE_16_BITS, DMA_INCR_16_BITS);
                transfer_len /= 2;
        } else {

                setup_dma_desc(cmd_desc, 
                        transfer_type, DMA_TYPE_08_BITS, DMA_INCR_08_BITS);
        }
        /* Setup the DMA for the write */ 
        cc_dma_desc_config(dma_hndl, cmd_desc);
        /* Configure the src, dst and size for write */
        cc_dma_submit_endp(dma_hndl, src_buf, dst_buf, transfer_len, false);
}

/* Setup the SPI and DMA modules to initiate the transfer */
static void setup_dma_transfer(struct spi_rtos_driver *rtos_hndl, 
                   const i8 *tx_data,
                   i8 *rx_data,
                   i32 size)
{
        struct spi_dma_info dma_info;
        u32 word_len;

        /* Get the SPI DMA specific info */
        cc_spi_control(rtos_hndl->hal_handle, SPI_CTL_GET_DMA_INFO, 
                       &dma_info);

        /* Get the SPI word length set in the driver */
        cc_spi_control(rtos_hndl->hal_handle, SPI_CTL_GET_WORDLEN,
                       &word_len); 

        if(tx_data && rx_data) { /* FULL DUPLEX */
                /* Setup the dma for the write transfer */
                setup_spi_dma(rtos_hndl->tx_dma_hndl,
                              (void *)dma_info.tx_reg_addr,
                              (void *)tx_data, 
                              size, word_len, SPI_DMA_TX);

                /* Setup the dma for the read transfer */
                setup_spi_dma(rtos_hndl->rx_dma_hndl,
                              rx_data,
                              (void *)dma_info.rx_reg_addr,
                              size, word_len, SPI_DMA_RX);

        } else if (tx_data) { /* HALF DUPLEX WRITE */
                /* Setup the dma for the write transfer */
                setup_spi_dma(rtos_hndl->tx_dma_hndl,
                              (void *)dma_info.tx_reg_addr,
                              (void *)tx_data, 
                              size, word_len, SPI_DMA_TX);

                /* Setup the dma for the dummy read transfer */
                setup_spi_dma(rtos_hndl->rx_dma_hndl,
                              (void *)&rtos_hndl->temp_store,
                              (void *)dma_info.rx_reg_addr,
                              size, word_len, SPI_DMA_RX_NO_INCR);
        } else { /* HALF DUPLEX READ */
                /* Setup the dma for the write transfer */
                rtos_hndl->temp_store = DUMMY_SPI_WORD;
                setup_spi_dma(rtos_hndl->tx_dma_hndl,
                              (void *)dma_info.tx_reg_addr,
                              (void *)&rtos_hndl->temp_store, 
                              size, word_len, SPI_DMA_TX_NO_INCR);

                /* Setup the dma for the dummy read transfer */
                setup_spi_dma(rtos_hndl->rx_dma_hndl,
                              rx_data,
                              (void *)dma_info.rx_reg_addr,
                              size, word_len, SPI_DMA_RX);
        }

        /* Setup the SPI word count for the DMA transfer */
        if(SPI_WORDLEN_32 == word_len) {
                size /= 4;
                cc_spi_control(rtos_hndl->hal_handle, SPI_CTL_SET_WORD_CNT,
                               &size);
        } else if(SPI_WORDLEN_16 == word_len) {
                size /= 2;
                cc_spi_control(rtos_hndl->hal_handle, SPI_CTL_SET_WORD_CNT,
                               &size);
        } else {
                cc_spi_control(rtos_hndl->hal_handle, SPI_CTL_SET_WORD_CNT,
                               &size);
        }
}

/* 
   Trigger the SPI DMA transfer. The parameters passed is used to identify the 
   mode of operation.
        tx_data: !NULL, rx_data: NULL --> Half duplex write
        tx_data: NULL, rx_data: !NULL --> Half duplex read
        tx_data: !NULL, rx_data: !NULL --> Full duplex write-read
*/
static void trigger_spi_dma_transfer(struct spi_rtos_driver *rtos_drv, 
                        const i8 *tx_data,
                        i8 *rx_data,
                        i32 size)
{
        i32 chipsel_enable = 1;
        
        /* Setup the SPI for DMA mode of tranfer */
        cc_spi_control(rtos_drv->hal_handle, SPI_CTL_SET_DMA_RW, NULL);

        /* Setup the DMA module for the transfer */
        setup_dma_transfer(rtos_drv, tx_data, rx_data, size);

        /* Initiate the DMA transfer */
        cc_spi_control(rtos_drv->hal_handle,
                       SPI_CTL_CS_CTRL,
                       &chipsel_enable);
}


/*
   The function checks if the request state transition can be supported
   and also initiates the corresponding action with the HAL.
*/
i32 spi_handle_pm_cmd(struct module_drv *mod_drv, const enum mod_pm pm_state)
{
        i32 retval = -1;
        struct spi_rtos_driver *rtos_drv = 
                (struct spi_rtos_driver *)mod_drv->rtos_drv;        

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
                retval = cc_spi_control(rtos_drv->hal_handle, 
                                        SPI_CTL_CONTEXT_SAVE, NULL);
                if(retval < 0) {
                        goto exit1;
                }
                /* Update the module state ?? */
                mod_drv->pm_state = e_pm_M4;
        } else if((e_pm_M4 == mod_drv->pm_state) && (e_pm_M0 == pm_state)) {
                /* Restore the peripheral context */
                retval = cc_spi_control(rtos_drv->hal_handle, 
                                        SPI_CTL_CONTEXT_RESTORE, NULL);
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

/* ------  Add it to config - portability */
static u8 map_moduleid_to_dmach(u32 moduleid, i8 is_tx)
{
        switch(moduleid) {
                case PRCM_LSPI:
                        if(is_tx) {
                                return DMA_USER_SPI2_TX;
                        } else {
                                return DMA_USER_SPI2_RX;
                        }
                case PRCM_GSPI:
                        if(is_tx) {
                                return DMA_USER_SPI1_TX;
                        } else {
                                return DMA_USER_SPI2_RX;
                        }
                case PRCM_SSPI:
                        if(is_tx) {
                                return DMA_USER_SPI0_TX;
                        } else {
                                return DMA_USER_SPI0_RX;
                        }
                default:
                        return 0;
        }
}


/* 
   This function should be called from centralized & RTOS specific initialization
   sequence. 

   Goal of this function is to extend information about SOC module to SW driver 
   enable it to initialize hardware through HAL. Driver could use private field 
   called 'hw_detail', if provisioned, to configure hardware. 

   Driver instance must enroll / register itself with PM / platfrom framework.

*/
i32 spi_driver_load(struct soc_module *spi_module)
{
        struct spi_rtos_driver *spi_rtos_drv_hndl;
        i32 ret_val;
        struct cc_spi_config *spi_config = 
                (struct cc_spi_config *)spi_module->hw_detail;
        cc_hndl hndl;
        struct cc_dma_chan_cfg chan_config;

        /* Reset the SPI driver structure once in the begining */
        if(!is_spidrv_reset) {
                reset_spi_rtosdrv();
                is_spidrv_reset = 1;
        }

        /* Initialize the SPI RTOS driver */
        spi_rtos_drv_hndl = check_spi_rtosdrv_inuse(spi_config->module_id);
        if(NULL == spi_rtos_drv_hndl) {
                /* Acquire a new rtos driver structure from the list */
                spi_rtos_drv_hndl = get_available_spi_rtosdrv();
                if(NULL == spi_rtos_drv_hndl) {
                        /* Something wrong - should have failed at spi_init */
                        goto exit1; /* Error */
                }
        } else {
                /* Module already in use. TBD?? */
                goto exit1;
        }

        /* Assign call back routines into spi_config structure for HAL  */
        spi_config->drv_rw_event_cb = drv_callback_ops_complete;
        spi_config->rtos_hndl = (void *)spi_rtos_drv_hndl;
        
        /* Initialize the SPI HAL */
        hndl = cc_spi_init(spi_config);
        if(NULL == hndl) {
                goto exit2; /* Error */
        }

        /* Derive other information from spi_haldrv.hw_module.priv_info */

        /* Initialize the module driver structure */
        spi_rtos_drv_hndl->device_id = spi_config->module_id;
        spi_rtos_drv_hndl->hal_driver.hw_module = NULL;
        spi_rtos_drv_hndl->hal_driver.clk_state = e_clk_cut_off;
        spi_rtos_drv_hndl->hal_driver.pm_state = e_pm_M0;
        spi_rtos_drv_hndl->hal_driver.rtos_drv = spi_rtos_drv_hndl;
        spi_rtos_drv_hndl->hal_driver.goto2pm_mode = spi_handle_pm_cmd;
        spi_rtos_drv_hndl->sync_obj = NULL;
        spi_rtos_drv_hndl->lock_obj = NULL;
        spi_rtos_drv_hndl->oper_mode = spi_config->oper_mode;

        /* Save HAL hndl in RTOS Driver structure */
        spi_rtos_drv_hndl->hal_handle = hndl;

        /* Setup the DMA based on the operation mode */
        chan_config.en_burst = false;
        chan_config.alt_cblk = false;
        chan_config.en_hwreq = false;
        chan_config.priority = false;
        spi_rtos_drv_hndl->rx_dma_hndl = 
                cc_dma_alloc(spi_config->dma_info.rx_dma_ch, 
                                map_moduleid_to_dmach(spi_config->module_id, 0));
        cc_dma_chan_config(spi_rtos_drv_hndl->rx_dma_hndl, &chan_config);

        spi_rtos_drv_hndl->tx_dma_hndl = 
                cc_dma_alloc(spi_config->dma_info.tx_dma_ch, 
                                map_moduleid_to_dmach(spi_config->module_id, 1));
        cc_dma_chan_config(spi_rtos_drv_hndl->tx_dma_hndl, &chan_config);

        /* Register with system INTC for irqvec_id */
        register_isr(spi_config->irqvec_id, 
                spi_interrupt_handler, 
                spi_rtos_drv_hndl->hal_handle);

        /* Register the module driver with the power management framework */
        ret_val = cc_module_drv_register(spi_module, 
                                       &spi_rtos_drv_hndl->hal_driver);
        if(ret_val < 0) {
                goto exit3; /* Error */
        }

        /* RTOS driver may need to do some more house-keeping ........  */

        return 0; /* Need to be RTOS specific */

exit3:
        cc_module_drv_unregister(&spi_rtos_drv_hndl->hal_driver);
exit2:
        cc_spi_deinit(hndl);
        free_spi_rtosdrv(spi_rtos_drv_hndl);
exit1:
        return -1;
}


/* Open the SPI module */
cc_hndl spi_open(u32 module_id)
{
        struct spi_rtos_driver *rtos_drv = NULL;
        i32 retval;

        /* Check if the driver has already been loaded */
        rtos_drv = check_spi_rtosdrv_inuse(module_id);
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

/* Close the SPI module */
i32 spi_close(cc_hndl spi_drv_hndl)
{
        struct spi_rtos_driver *rtos_drv = 
                (struct spi_rtos_driver *)spi_drv_hndl;

        RTOS_MUTEX_ACQUIRE(&rtos_drv->lock_obj);

        /* decrement the reference count */
        rtos_drv->ref_cnt--;

        RTOS_MUTEX_RELEASE(&rtos_drv->lock_obj);

        return 0;
}

/* Half duplex Write data over SPI */
i32 spi_write(cc_hndl spi_drv_hndl, const i8 *wr_data, i32 size)
{
        i32 retval;
        struct spi_rtos_driver *rtos_drv = 
                (struct spi_rtos_driver *)spi_drv_hndl;
        u32 wr_buf_addr = (u32)wr_data;

        i32 wr_pend = -1;

        RTOS_MUTEX_ACQUIRE(&rtos_drv->lock_obj); /* Can be part of RTOS framework */

        /* Check the mode of transfer. If DMA, handle it here else invoke HAL */
        //if(SPI_DMA_OPS == rtos_drv->oper_mode) {
        if((size > DMA_BUFF_SIZE_MIN) && ((wr_buf_addr % 4) == 0)) {
                retval = cc_spi_control(rtos_drv->hal_handle, 
                                    SPI_CTL_COOKIE_UPDATE, (void*)&wr_pend);
                
                /* Initiate the SPI transfer over DMA */
                trigger_spi_dma_transfer(rtos_drv, wr_data, NULL, size);

                RTOS_SEM_WAIT(&rtos_drv->sync_obj); /* RTOS function blocking */

        }else{
                if(0 > cc_spi_wr_submit(rtos_drv->hal_handle, wr_data, size,
                                        (void*)&wr_pend)) {
                        goto rtos_spi_drv_write_error;
                }
        }

 rtos_spi_drv_write_error:        

        RTOS_MUTEX_RELEASE(&rtos_drv->lock_obj);

        UNUSED(retval);

        return (wr_pend < 0) ? -1 : (size - wr_pend);
}

/* Half duplex Read data over SPI */
i32 spi_read(cc_hndl spi_drv_hndl, i8 *rd_data, i32 size)
{
        i32 retval;
        struct spi_rtos_driver *rtos_drv = 
                (struct spi_rtos_driver *)spi_drv_hndl;
        u32 rd_buf_addr = (u32)rd_data;
        i32 rd_pend = -1;
        
        RTOS_MUTEX_ACQUIRE(&rtos_drv->lock_obj);
        
        /* Check the mode of transfer. If DMA, handle it here else invoke HAL */
        //if(SPI_DMA_OPS == rtos_drv->oper_mode) {
        if((size > DMA_BUFF_SIZE_MIN) && ((rd_buf_addr % 4) == 0)) {
                retval = cc_spi_control(rtos_drv->hal_handle, 
                                    SPI_CTL_COOKIE_UPDATE, (void*)&rd_pend);
                
                /* Initiate the SPI transfer over DMA */
                trigger_spi_dma_transfer(rtos_drv, NULL, rd_data, size);

                RTOS_SEM_WAIT(&rtos_drv->sync_obj);

        }else{
                if(0 > cc_spi_rd_submit(rtos_drv->hal_handle, rd_data, size,
                                        (void*)&rd_pend)) {
                        goto rtos_spi_drv_read_error;
                }
        }

 rtos_spi_drv_read_error:      

        RTOS_MUTEX_RELEASE(&rtos_drv->lock_obj);

        UNUSED(retval);

        return (rd_pend < 0) ? -1 : (size - rd_pend);
}

/* Full duplex Write-Read over SPI */
i32 spi_write_read(cc_hndl spi_drv_hndl, const i8 *wr_data, 
                   i8 *rd_data, i32 size)
{
        i32 retval;
        struct spi_rtos_driver *rtos_drv = 
                (struct spi_rtos_driver *)spi_drv_hndl;
        u32 rd_buf_addr = (u32)rd_data;
        u32 wr_buf_addr = (u32)wr_data;
        i32 rw_pend = -1;

        RTOS_MUTEX_ACQUIRE(&rtos_drv->lock_obj);

        /* Check the mode of transfer. If DMA, handle it here else invoke HAL */
        //if(SPI_DMA_OPS == rtos_drv->oper_mode) {
        if((size > DMA_BUFF_SIZE_MIN) && ((rd_buf_addr % 4) == 0) &&
                ((wr_buf_addr % 4) == 0)) {
                retval = cc_spi_control(rtos_drv->hal_handle, 
                                    SPI_CTL_COOKIE_UPDATE, (void*)&rw_pend);
          
                /* Initiate the SPI transfer over DMA */
                trigger_spi_dma_transfer(rtos_drv, wr_data, rd_data, size);
                RTOS_SEM_WAIT(&rtos_drv->sync_obj); /* Make RTOS function blocking */

        }else{
                if(0 > cc_spi_rw_submit(rtos_drv->hal_handle, wr_data, 
                                        rd_data, size, (void*)&rw_pend)) {
                        goto rtos_spi_drv_rw_error;
                }
        }

 rtos_spi_drv_rw_error:        

        RTOS_MUTEX_RELEASE(&rtos_drv->lock_obj);

        UNUSED(retval);

        return (rw_pend < 0) ? -1 : (size - rw_pend);
}
