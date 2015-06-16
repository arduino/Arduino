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
#include "hw_memmap.h"
#include "hw_mcspi.h"
#include "hw_common_reg.h"
#include "rom.h"
#include "rom_map.h"
#include "spi.h"
#include "prcm.h"
#include "hw_ints.h"
#include "interrupt.h"
#include "cc_types.h"
#include "spi_hal.h"

struct cc_spi_control {
        struct cc_spi_config  spi_setup_info;     /* SPI setup information */

        union {
                u32    *ibuf_ptr;
                u16  *sbuf_ptr;
                u8   *cbuf_ptr;
        }wr_ptr, rd_ptr;

        u32           temp_store;
        i32                     wr_len;
        i32                     rd_len;
        i8                    wr_incr;
        i8                    rd_incr;

        void                    *user_cookie;
};

struct cc_spi_control spi_ctrl[MAX_SPI_MODULES];
i8 is_spictrl_reset = 0;

/* Reset the SPI control pool */
static void reset_spictrl()
{
        i32 loop_cnt;

        /* Clear the inuse pointers to indicate availability 
         * of all control structure */
        for(loop_cnt = 0; loop_cnt < MAX_SPI_MODULES; loop_cnt++) {
                /* Clear the SPI control structure */
                memset(&spi_ctrl[loop_cnt], 0, sizeof(struct cc_spi_control));
        }
}

/*
*   Check if the requested SPI module is already in use. This is 
*   acheived by comparing the base address.
*/
static struct cc_spi_control* check_spictrl_inuse(const struct cc_spi_config *spi_config)
{
        i32 loop_cnt;
        struct cc_spi_control *temp_store = NULL;

        /* Check if any of the control structures
         * already refer to the base address as specified in the SPI info
         * structure. If yes return the handle to that structure */
        for(loop_cnt = 0; loop_cnt < MAX_SPI_MODULES; loop_cnt++) {
                if(spi_ctrl[loop_cnt].spi_setup_info.base_addr == 
                        spi_config->base_addr) {
                        temp_store = &spi_ctrl[loop_cnt];
                        break;
                }
        }
        return temp_store;
}

/* Get an available SPI control structure from the pool */
static struct cc_spi_control* get_available_spictrl()
{
        i32 loop_cnt;
        struct cc_spi_control *temp_store = NULL;

        /* Find an available control structure and return a handle */
        for(loop_cnt = 0; loop_cnt < MAX_SPI_MODULES; loop_cnt++) {
                if(0 == spi_ctrl[loop_cnt].spi_setup_info.base_addr) {
                        temp_store = &spi_ctrl[loop_cnt];
                        break;
                }
        }
        return temp_store;
}

/* Free up the SPI control structure */
static i32 free_spictrl(struct cc_spi_control *spi_ctrl_hndl)
{
        i32 loop_cnt;
        i32 ret = -1;

        /* Free up the SPI control structure of the specified handle */
        for(loop_cnt = 0; loop_cnt < MAX_SPI_MODULES; loop_cnt++) {
                if(spi_ctrl_hndl == &spi_ctrl[loop_cnt]) {
                        ret = 0;
                        /* Clear the SPI control structure */
                        memset(spi_ctrl_hndl, 0, 
                                sizeof(struct cc_spi_control));
                        break;
                }
        }
        return ret;
}

/* Setup the SPI registers to work with the DMA */
static void setup_spi_dma_reg(const struct cc_spi_config *spi_config)
{
        /* Enable the read and write FIFOs */
        MAP_SPIFIFOEnable(spi_config->base_addr, SPI_RX_FIFO);
        MAP_SPIFIFOEnable(spi_config->base_addr, SPI_TX_FIFO);

        /* Enable the Rx and Tx DMAs */
        MAP_SPIDmaEnable(spi_config->base_addr, SPI_RX_DMA);
        MAP_SPIDmaEnable(spi_config->base_addr, SPI_TX_DMA);

        /* Enable the EOW interrupt to indicate DMA completion */
        MAP_SPIIntEnable(spi_config->base_addr, SPI_INT_EOW);

        /* Setup the SPI FIFO levels */
        MAP_SPIFIFOLevelSet(spi_config->base_addr,1,1);
}

/* Initialize the SPI module */
void cc_spi_configure(const struct cc_spi_config *spi_config)
{
        i32 sub_mode;

        /* Reset the module before configurations */
        MAP_SPICSDisable(spi_config->base_addr);     // Disable chip select
        MAP_SPIDisable(spi_config->base_addr);       // Disable channel
        MAP_SPIReset(spi_config->base_addr);         // Reset module

        sub_mode = (spi_config->clk_settings.clk_pol << 1) |
                        (spi_config->clk_settings.clk_phase);
        /* Configure the device */
        MAP_SPIConfigSetExpClk(spi_config->base_addr,
                    PRCMPeripheralClockGet(spi_config->module_id),
                    spi_config->baud_rate,
                    spi_config->master_op,
                    sub_mode,
                    (spi_config->word_len_bits |
                    (spi_config->chip_sel_ctrl & 0xFF000000) |
                    spi_config->chip_sel_pol |
                    SPI_4PIN_MODE | SPI_TURBO_OFF)
                    );

        setup_spi_dma_reg(spi_config);

        /* Enable the device */
        MAP_SPIEnable(spi_config->base_addr);

        return;
}

/* Initialize SPI HAL */
cc_hndl cc_spi_init(const struct cc_spi_config *spi_config)
{
        struct cc_spi_control *spi_ctrl_hndl;

        /* Range check of the parameters input */
        /************ TBD **********************/

        /* Reset the SPI control structure once in the begining */
        if(!is_spictrl_reset) {
                reset_spictrl();
                is_spictrl_reset = 1;
        }
        
        /* Check if the module is already in use */
        spi_ctrl_hndl = check_spictrl_inuse(spi_config);
        if(NULL == spi_ctrl_hndl) {
                /* Acquire a new control structure from the list */
                spi_ctrl_hndl = get_available_spictrl();
                if(NULL == spi_ctrl_hndl) {
                        /* Cannot support more modules of this type */
                        return NULL;
                }
        } else {
                /* Module already in use. */
                return spi_ctrl_hndl;
        }

        /* Configure the SPI module */
        cc_spi_configure(spi_config);

        /* Copy the user selection of SPI parameters */
        memcpy(&spi_ctrl_hndl->spi_setup_info,
                spi_config,
                sizeof(struct cc_spi_config));
        /* Return the handle */
        return spi_ctrl_hndl;
}

/* DeInitialize SPI HAL */
i32 cc_spi_deinit(cc_hndl hndl)
{
        struct cc_spi_control *spi_control = (struct cc_spi_control *)hndl;
        i32 retval;

        /* Free up the SPI control structure */
        retval = free_spictrl(spi_control);

        return retval;
}

/* Interrupt service routine handling SPI events */
void cc_spi_isr(cc_hndl hndl)
{
        struct cc_spi_control *spi_control = (struct cc_spi_control *)hndl;
        struct cc_spi_config *spi_config = &spi_control->spi_setup_info;
        u32 intr_status;

        intr_status = MAP_SPIIntStatus(spi_config->base_addr, true);

        if(intr_status & SPI_INT_EOW){
                /* Clear the interrupt status */
                MAP_SPIIntClear(spi_config->base_addr, SPI_INT_EOW);

                if((spi_config->master_op) &&
                        (SPI_CS_SW_CTRL_AUTO == spi_config->chip_sel_ctrl)) {
                        /* Disable the SPI chip select line */
                        MAP_SPICSDisable(spi_config->base_addr);
                }

                /* Invoke the callback */
                if(spi_config->drv_rw_event_cb) {
                        spi_config->drv_rw_event_cb(
                                spi_config->rtos_hndl, SPI_EVT_TRANSFER_DONE,
                                (void *)&spi_control->wr_len, 
                                spi_control->user_cookie);
                }
        }

        /* Clear the interrupt status */
        MAP_SPIIntClear(spi_config->base_addr, intr_status);

}

/* Submit a byte array to be written onto SPI bus in Half duplex mode */
i32 cc_spi_wr_submit(cc_hndl hndl, const i8 *data, i32 size, 
                         void *cookie)
{
        struct cc_spi_control *spi_control = (struct cc_spi_control *)hndl;
        struct cc_spi_config *spi_config = &spi_control->spi_setup_info;
        i32 retval = -1, cs_ctrl;

        /*
         * Validate the input parameters
         */

        if(SPI_POLLED_OPS == spi_config->oper_mode) {
                /* Polled mode */
                /* Write the data bytewise over SPI */
                if(SPI_CS_SW_CTRL_AUTO == spi_config->chip_sel_ctrl) {
                        cs_ctrl = (SPI_CS_ENABLE | SPI_CS_DISABLE);
                } else {
                        cs_ctrl = 0;
                }

                /* Added to handle combinations of DMA and CPU transfers*/
                MAP_SPIWordCountSet(spi_config->base_addr, 0);

                MAP_SPITransfer(spi_config->base_addr,
                                (u8 *)data,
                                NULL,
                                size,
                                cs_ctrl
                                );
                *((i32 *)cookie) = 0;
                retval = 0;
        }else if(SPI_INTERRUPT_OPS == spi_config->oper_mode) {
                /* Interrupt mode */
        }else{

        }
        
        return retval;
}

/* Submit a byte array to be filled from SPI bus in Half duplex mode */
i32 cc_spi_rd_submit(cc_hndl hndl,i8 *rd_data, i32 rd_size, 
                         void *cookie)
{
        struct cc_spi_control *spi_control = (struct cc_spi_control *)hndl;
        struct cc_spi_config *spi_config = &spi_control->spi_setup_info;
        i32 retval = -1, cs_ctrl;
        
        /*
         * Validate the input parameters
         */


        if(SPI_POLLED_OPS == spi_config->oper_mode) {
                /* Polled mode */
                /* Write the data bytewise over SPI */
                if(SPI_CS_SW_CTRL_AUTO == spi_config->chip_sel_ctrl) {
                        cs_ctrl = (SPI_CS_ENABLE | SPI_CS_DISABLE);
                } else {
                        cs_ctrl = 0;
                }

                /* Added to handle combinations of DMA and CPU transfers*/
                MAP_SPIWordCountSet(spi_config->base_addr, 0);

                MAP_SPITransfer(spi_config->base_addr,
                                NULL,
                                (u8 *)rd_data,
                                rd_size,
                                cs_ctrl
                                );
                *((i32 *)cookie) = 0;
                retval = 0;
        }else if(SPI_INTERRUPT_OPS == spi_config->oper_mode) {
                /* Interrupt mode */
        }else{
        }

        return retval;
}

/*
*  Submit a byte array to be written to and another byte array to be 
*  filled from SPI bus in Full duplex mode.
*/
i32 cc_spi_rw_submit(cc_hndl hndl, const i8 *wr_data, i8 *rd_data, 
                         i32 rw_size, void *cookie)
{
        struct cc_spi_control *spi_control = (struct cc_spi_control *)hndl;
        struct cc_spi_config *spi_config = &spi_control->spi_setup_info;
        i32 retval = -1, cs_ctrl;
        
        /*
         * Validate the input parameters
         */


        if(SPI_POLLED_OPS == spi_config->oper_mode) {
                /* Polled mode */
                /* ReadWrite the data bytewise over SPI */
                if(SPI_CS_SW_CTRL_AUTO == spi_config->chip_sel_ctrl) {
                        cs_ctrl = (SPI_CS_ENABLE | SPI_CS_DISABLE);
                } else {
                        cs_ctrl = 0;
                }

                /* Added to handle combinations of DMA and CPU transfers*/
                MAP_SPIWordCountSet(spi_config->base_addr, 0);

                MAP_SPITransfer(spi_config->base_addr,
                                (u8 *)wr_data,
                                (u8 *)rd_data,
                                rw_size,
                                cs_ctrl
                                );
                *((i32 *)cookie) = 0;
                retval = 0;
        }else if(SPI_INTERRUPT_OPS == spi_config->oper_mode) {
                /* Interrupt mode */
        }else{

        }
        
        return retval;
}

/* Setup the SPI registers to work with the DMA */
static void get_dma_info(struct cc_spi_config *spi_config, void *arg)
{
        struct spi_dma_info *dma_details = (struct spi_dma_info *)arg;

        /* Populate the DMA info parameters */
        dma_details->tx_reg_addr = spi_config->dma_info.tx_reg_addr;
        dma_details->tx_dma_ch = spi_config->dma_info.tx_dma_ch;
        dma_details->rx_reg_addr = spi_config->dma_info.rx_reg_addr;
        dma_details->rx_dma_ch = spi_config->dma_info.rx_dma_ch;

}
/* Control commands to be serviced by the driver */
i32 cc_spi_control(cc_hndl hndl, enum cc_spi_ctl cmd, void *arg)
{
        struct cc_spi_control *spi_control = (struct cc_spi_control *)hndl;
        struct cc_spi_config *spi_config = &spi_control->spi_setup_info;
        i32 retval = 0;

        switch(cmd) {
                case SPI_CTL_SET_DMA_RW:
                        /* Setup the SPI registers to work with the DMA */
                        //setup_spi_dma_reg(spi_config);
                        break;
                case SPI_CTL_GET_DMA_INFO:
                        /* Get the platform specific DMA info --- Move TBD??? */
                        get_dma_info(spi_config, arg);
                        break;
                case SPI_CTL_SET_WORD_CNT:
                        /* Set the specified word count */
                        {
                                i32 word_cnt = *((u32 *)arg);
                                MAP_SPIWordCountSet(spi_config->base_addr, word_cnt);
                                break;
                        }
                case SPI_CTL_CS_CTRL:
                        /* Enable/Disable the chip select */
                        {
                                i32 cs_ctrl = *((u8 *)arg);
                                if(1 == cs_ctrl) {
                                        MAP_SPICSEnable(spi_config->base_addr);
                                } else {
                                        MAP_SPICSDisable(spi_config->base_addr);
                                }
                                break;
                        }
                case SPI_CTL_SET_TIMEOUT:
                        break;
                case SPI_CTL_GET_STATUS:
                        break;
                case SPI_CTL_GET_WORDLEN:
                        /* Get the SPI word length */
                        {
                                *((u32 *)arg) = 
                                (HWREG(spi_config->base_addr + MCSPI_O_CH0CONF) 
                                                & MCSPI_CH0CONF_WL_M);
                                break;
                        }
                case SPI_CTL_CONTEXT_SAVE:
                        /* Perform any registers saves here */
                        break;
                case SPI_CTL_CONTEXT_RESTORE:
                        /* Restore the peripheral context */
                        cc_spi_configure(spi_config);
                        break;
                case SPI_CTL_COOKIE_UPDATE:
                        spi_control->user_cookie = (void *)arg;
                        break;
                default:
                        break;
        }
        
        return retval;
}



