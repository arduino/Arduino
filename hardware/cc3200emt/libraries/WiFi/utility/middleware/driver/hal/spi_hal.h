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
 *  spi_hal.h - API and other data constructs to operate SPI HAL.
 *******************************************************************************
 */
#ifndef __SPI_HAL_H__
#define __SPI_HAL_H__

#include "cc_types.h"
#include "hw_types.h"
#include <spi.h>

#define MAX_SPI_MODULES         3
#define DUMMY_SPI_WORD          0xFFFFFFFF   

/* 
        SPI clock polarity and phase
        [Pol:Phase]
        00 -- SPICLK active high and sampling occurs on the rising edge
        01 -- SPICLK active high and sampling occurs on the falling edge
        10 -- SPICLK active low and sampling occurs on the rising edge
        11 -- SPICLK active low and sampling occurs on the falling edge

        SPI Chip select polarity:
        0 -- SPIEN active high
        1 -- SPIEN active low
*/

enum spi_clk_phase {
        SPI_LATCH_ODD_EDGE = 0x0,
        SPI_LATCH_EVEN_EDGE
};

enum spi_clk_polarity {
        SPI_CLK_ACTIVE_HIGH = 0x0,
        SPI_CLK_ACTIVE_LOW
};

struct spi_clk_settings {
        enum spi_clk_phase clk_phase;
        enum spi_clk_polarity clk_pol;
};

enum spi_cs_polarity {
        SPI_CS_ACTIVE_HIGH = SPI_CS_ACTIVEHIGH,
        SPI_CS_ACTIVE_LOW = SPI_CS_ACTIVELOW
};

enum spi_word_len {
        SPI_WORDLEN_8 = SPI_WL_8,
        SPI_WORDLEN_16 = SPI_WL_16,
        SPI_WORDLEN_32 = SPI_WL_32
};

/*
  Note: Incoming slave RD or WR request can be used to invoke WR or RD operation
  respectively on HAL.
*/

enum cc_spi_event {

        SPI_EVT_TRANSFER_DONE = 0x01,  /* Transfer on spi bus was a success */
        SPI_EVT_TRANSFER_FAIL,         /* Transfer on spi bus was a success */
        SPI_EVT_SLAVE_READ_REQ,        /* Incoming RD REQ from spi master */
        SPI_EVT_SLAVE_WRITE_REQ        /* Incoming WR REQ from spi master */
};

enum cc_spi_error {

	SPI_BUS_ERR        = 0x01
};

enum spi_cs_ctrl {
        SPI_CS_SW_CTRL = SPI_SW_CTRL_CS,
        SPI_CS_HW_CTRL = SPI_HW_CTRL_CS,
        SPI_CS_SW_CTRL_AUTO = (SPI_SW_CTRL_CS | 0x1)
};

enum operation_mode{

        SPI_POLLED_OPS,              /* Polling based operation */
        SPI_INTERRUPT_OPS,           /* Interrupt based operation */
        SPI_DMA_OPS                  /* DMA based operation */
};

struct spi_dma_info {
        u32 tx_reg_addr;       /* Transmit register address */
        u32 tx_dma_ch;         /* DMA channel for transmit */
        u32 rx_reg_addr;       /* Receive register address */
        u32 rx_dma_ch;         /* DMA channel for receive */
};

struct spi_platform_details {
        u32 module_id;  /* Peripheral identifier of SPI module  */
        u32 base_addr;           /* Hardware address of SPI module  */
        struct spi_dma_info dma_info; /* DMA info specific to the SPI module */
        u8 irqvec_id;                  /* Interrupt vector number */
};

struct spi_config_settings {
        struct spi_clk_settings clk_settings;          /* SPI Clock settings */
        enum spi_cs_polarity chip_sel_pol;     /* SPIEN Chip Select polarity */
        enum spi_cs_ctrl chip_sel_ctrl; /* SPIEN CS control: HW, SW, SW-Auto */
        u32 baud_rate;                    /* SPI transfer baud rate */
        enum spi_word_len word_len_bits; /* word length in bits (8, 16 or 32)*/
        u8 master_op;           /* Operate HW as a SPI bus master */
        enum operation_mode oper_mode;            /* Poll/Interrupt/DMA mode */
};

struct cc_spi_config {

        /* Platform details */
        u32 module_id;      /* Peripheral identifier of SPI module  */
        u32 base_addr;           /* Hardware address of SPI module  */
        struct spi_dma_info dma_info; /* DMA info specific to the SPI module */
        u8 irqvec_id;                  /* Interrupt vector number */

        /* Module setting details */
        struct spi_clk_settings clk_settings;          /* SPI Clock settings */
        enum spi_cs_polarity chip_sel_pol;        /* SPIEN Chip Select polarity */
        enum spi_cs_ctrl chip_sel_ctrl; /* SPIEN CS control: HW, SW, SW-Auto */
        u32 baud_rate;                    /* SPI transfer baud rate */
        enum spi_word_len word_len_bits; /* word length in bits (8, 16 or 32)*/
        u8 master_op;           /* Operate HW as a SPI bus master */
        enum operation_mode oper_mode;            /* Poll/Interrupt/DMA mode */

        void *rtos_hndl;               /* Reference to RTOS driver object */ 

        /* 
           Callback to RTOS driver from SPI HAL for a scheduled operation.

           event:    identifies event or trigger point from HW or SPI bus
           evt_data: optional data associated with specified event
           cookie:   reference provided by RTOS driver for a transaction
           
        */
        i32 (*drv_rw_event_cb)(void *rtos_hndl, enum cc_spi_event event,
                               void *evt_data, void *cookie);
        
        /* 
           Callback to RTOS driver from SPI HAL for (fatal) erros in HW.
           
           error:    identifies error or trigger point from HW or SPI bus

           Note: This routine must be mandatorily populated
        */
        i32 (*drv_hw_error_cb)(void *rtos_hndl, 
                               enum cc_spi_error error);
};

/*!
  Initialize SPI HAL

  Returns: on success a handle specific indicated instance of HW, otherwise
  NULL on error.
 
*/
cc_hndl cc_spi_init(const struct cc_spi_config *spi_info);

/*!
  DeInitialize SPI HAL

  Returns: 0 on success , otherwise -1 on error.
 
*/
i32 cc_spi_deinit(cc_hndl hndl);

/*!
*  \brief Submit a byte array to be written onto SPI bus in Half duplex mode.
*
*  If SPI HAL has been configured to write data to HW in a polled mode, then 
*  function will return either on encountering an error or after completing 
*  the write operation. 
*  
*  If configured to operate in async/interrupt mode, the function will return 
*  after scheduling a transaction to be initiated immediately. The caller of 
*  API must not free-up or relinquish the data buffer until async write
*  to bus is completed (to be indicated using call-back).
*
* \param  data:   an array of bytes to be written onto bus
* \param  size:   number of bytes that needs to be written
* \param cookie: reference returned to driver in callback (async mode only)
*
* \return polled mode: -1 on error otherwise number of bytes written to SPI bus
*  async  mode: -1 on error otherwise 0 on successful scheduling WR oper
*
*/
i32 cc_spi_wr_submit(cc_hndl hndl, const i8 *data, i32 size, 
                         void *cookie);

/*!
*  \brief Submit a byte array to be filled from SPI bus in Half duplex mode.
*
*  If SPI HAL has been configured to read data to HW in a polled mode, then 
*  function will return either on encountering an error or after completing 
*  the read operation. 
*  
*  If configured to operate in async/interrupt mode, the function will return 
*  after scheduling a transaction to be initiated immediately. The caller of 
*  API must not free-up or relinquish the data buffer until async read
*  to bus is completed (to be indicated using call-back).
*
* \param  rd_data:   an array of bytes to be read from the bus
* \param  rd_size:   number of bytes that needs to be read
* \param  cookie: reference returned to driver in callback (async mode only)
*
* \return polled mode: -1 on error otherwise number of bytes read from SPI bus
*  async  mode: -1 on error otherwise 0 on successful scheduling read oper
*
*/
i32 cc_spi_rd_submit(cc_hndl hndl,i8 *rd_data, i32 rd_size, 
                         void *cookie);

/*!
*  \brief Submit a byte array to be written to and another byte array to be 
*  filled from SPI bus in Full duplex mode.
*
*  If SPI HAL has been configured to write-read data to HW in a polled mode, 
*  then function will return either on encountering an error or after 
*  completing the write-read operation. 
*  
*  If configured to operate in async/interrupt mode, the function will return 
*  after scheduling a transaction to be initiated immediately. The caller of 
*  API must not free-up or relinquish the data buffer until async read
*  to bus is completed (to be indicated using call-back).
*
* \param  hndl:  handle to the SPI HAL driver
* \param  wr_data:   an array of bytes to be written to the bus
* \param  rd_data:   an array of bytes to be read from the bus
* \param  rw_size:   number of bytes that needs to be read-write
* \param  cookie: reference returned to driver in callback (async mode only)
*
* \return polled mode: -1 on error otherwise number of bytes read from SPI bus
*  async  mode: -1 on error otherwise 0 on successful scheduling read oper
*
*/
i32 cc_spi_rw_submit(cc_hndl hndl, const i8 *wr_data, i8 *rd_data, 
                         i32 rw_size, void *cookie);

/*
  Interrupt service routine to be invoked by platform software / RTOS
*/
void cc_spi_isr(cc_hndl hndl);

enum cc_spi_ctl {

        SPI_CTL_SET_DMA_RW,           /* Operate in dma mode */
        SPI_CTL_GET_DMA_INFO,         /* Get info related to the SPI-DMA */
        SPI_CTL_SET_WORD_CNT,         /* Set up the DMA transfer word count  */
        SPI_CTL_CS_CTRL,              /* Chipselect ctrl 1:Enable,0:Disable,2:Auto */ 
        SPI_CTL_SET_TIMEOUT,          /* Set timeout of RD / WR Units: msecs */
        SPI_CTL_GET_STATUS,           /* Get status of HW, needs placeholder */
        SPI_CTL_GET_WORDLEN,          /* Get the SPI word length */
        SPI_CTL_CONTEXT_SAVE,         /* Save the module context */
        SPI_CTL_CONTEXT_RESTORE,      /* Restore the module context */
        SPI_CTL_COOKIE_UPDATE         /* Update the cookie */
};

/*!
  \brief Control commands to be serviced by the driver

  \param cmd: Command on HAL to update, modify or fetch operational  parameter.
  \param arg: (Optional / placeholder) value of parameter to processed by  HAL. 

  Returns:
  
  0 on success, otherwise -1 on error.
*/
i32 cc_spi_control(cc_hndl hndl, enum cc_spi_ctl cmd, void *arg);


#endif //__SPI_HAL_H__
