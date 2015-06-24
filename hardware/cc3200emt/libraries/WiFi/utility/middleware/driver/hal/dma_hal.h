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
 *  dma_hal.h - API and other data constructs to operate DMA HAL.
 *******************************************************************************
 */
#ifndef __DMA_HAL_H__
#define __DMA_HAL_H__

#include "hw_types.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "udma.h"
#include "cc_types.h"

/*
            |   Mode 0   |   Mode 1   |   Mode 2   |  Mode 3   |
  --------------------------------------------------------------
  Chan# 00: |  TIMER0_A  |  MOD_NONE  |  MOD_NONE  |  SW_PROG  |
  Chan# 01: |  TIMER0_B  |  MOD_NONE  |  MOD_NONE  |  SW_PROG  |
  Chan# 02: |  TIMER1_A  |  MOD_NONE  |  MOD_NONE  |  SW_PROG  |
  Chan# 03: |  TIMER1_B  |  MOD_NONE  |  MOD_NONE  |  SW_PROG  |
  Chan# 04: |  TIMER2_A  |  MOD_NONE  |  MASP0_RX  |  SW_PROG  |
  Chan# 05: |  TIMER2_B  |  MOD_NONE  |  MASP0_TX  |  SW_PROG  |
  Chan# 06: |  TIMER3_A  |  SPI1_RX   |  GPIO_C    |  SW_PROG  |
  Chan# 07: |  TIMER3_B  |  SPI1_TX   |  GPIO_D    |  SW_PROG  |
  Chan# 08: |  UART0_RX  |  TIMER0_A  |  TIMER2_A  |  SW_PROG  |
  Chan# 09: |  UART0_TX  |  TIMER0_B  |  TIMER2_B  |  SW_PROG  |
  Chan# 10: |  UART1_RX  |  TIMER1_A  |  TIMER3_A  |  SW_PROG  |
  Chan# 11: |  UART1_TX  |  TIMER1_B  |  TIMER3_B  |  SW_PROG  |
  Chan# 12: |  SPI2_RX   |  MOD_NONE  |  MOD_NONE  |  SW_PROG  |
  Chan# 13: |  SPI2_TX   |  MOD_NONE  |  MOD_NONE  |  SW_PROG  |
  Chan# 14: |  MOD_ADC0  |  MOD_NONE  |  MOD_NONE  |  SW_PROG  |
  Chan# 15: |  MOD_ADC2  |  MOD_NONE  |  MOD_NONE  |  SW_PROG  |
  Chan# 16: |  MOD_ADC4  |  TIMER2_A  |  MOD_NONE  |  SW_PROG  |
  Chan# 17: |  MOD_ADC6  |  TIMER2_B  |  MOD_NONE  |  SW_PROG  |
  Chan# 18: |  GPIO_A    |  MOD_NONE  |  MASP0_RX  |  SW_PROG  |
  Chan# 19: |  GPIO_B    |  MOD_NONE  |  MASP0_TX  |  SW_PROG  |
  Chan# 20: |  GPIO_C    |  MOD_NONE  |  MOD_NONE  |  SW_PROG  |
  Chan# 21: |  GPIO_D    |  MOD_NONE  |  MOD_NONE  |  SW_PROG  |
  Chan# 22: |  CAM_PORT  |  MOD_NONE  |  MOD_NONE  |  SW_PROG  |
  Chan# 23: |  MOD_NONE  |  TIMER3_A  |  TIMER2_A  |  SW_PROG  |
  Chan# 24: |  MOD_NONE  |  TIMER3_B  |  TIMER2_B  |  SW_PROG  |
  Chan# 25: |  SPI0_RX   |  I2C0_RX   |  TIMER2_A  |  SW_PROG  |
  Chan# 26: |  SPI0_TX   |  I2C0_TX   |  TIMER2_B  |  SW_PROG  |
  Chan# 27: |  MOD_NONE  |  GPIO_A    |  TIMER2_A  |  SW_PROG  |
  Chan# 28: |  MOD_NONE  |  GPIO_B    |  TIMER2_B  |  SW_PROG  |
  Chan# 29: |  MOD_NONE  |  MOD_NONE  |  TIMER2_A  |  SW_PROG  |
  Chan# 30: |  SPI1_RX   |  MOD_NONE  |  I2C0_RX   |  SW_PROG  |
  Chan# 31: |  SPI1_TX   |  MOD_NONE  |  I2C0_TX   |  SW_PROG  |

  Steps: 
  
  1. Initialize DMA Module by using cc_dma_init().

  2. After reviewing afore-mentioned channel table, allocate an appropriate 
  DMA channel for module of interest by using cc_dma_alloc( ). For e.g.,
  

  3. Set-up or configure properties for operation of DMA channel by invoking 
  cc_dma_chan_config().

  4. Set-up or configure descriptor for a DMA data transaction by invoking
  cc_dma_desc_config();

  5. Depening up-on mode of transaction indicated in cc_dma_desc_config(),
  invoke applicable API to submit buffers to DMA for processing. Specifically,
  for initiating a ping-pong transaction, cc_dma_submit_pp_endp() must be 
  used. Similarly, for scatter-gather transaction cc_dma_submit_sg_bvec()
  API must be invoked. For all other transactions, cc_dma_submit_endp()
  must be used.

  6. Interrupts for completion of peripheral co-ordinated DMA operations are
  generated by peripherals. Interrupts for software initiated DMA operations
  are generated by DMA module. However, DMA module doesn't report status for
  completion of individual transactions. Therefore, users of DMA channel, on
  completion of DMA transaction, must invoke cc_dma_done() API to enable
  DMA HAL complete certain house-keeping and set-up the channel for followup
  operation. 

  Note: There can be only one software initiated DMA transaction in system.
  
*/

struct cc_dma_cfg {

        void         *ctl_table;  /* Must be 1024 byte alligned */

        /* add more */
};

i32  cc_dma_init(const struct cc_dma_cfg *dma_cfg);
void cc_dma_exit();

#define DMA_USER_MOD_NONE        0x00

#define DMA_USER_TIMER0_A        0x01
#define DMA_USER_TIMER0_B        0x02
#define DMA_USER_TIMER1_A        0x03
#define DMA_USER_TIMER1_B        0x04
#define DMA_USER_TIMER2_A        0x05
#define DMA_USER_TIMER2_B        0x06
#define DMA_USER_TIMER3_A        0x07
#define DMA_USER_TIMER3_B        0x08
#define DMA_USER_UART0_RX        0x09
#define DMA_USER_UART0_TX        0x0A
#define DMA_USER_UART1_RX        0x0B
#define DMA_USER_UART1_TX        0x0C
#define DMA_USER_CAM_PORT        0x0D
#define DMA_USER_I2C0_RX         0x0E
#define DMA_USER_I2C0_TX         0x0F
#define DMA_USER_MOD_ADC0        0x10
#define DMA_USER_MOD_ADC2        0x11
#define DMA_USER_MOD_ADC4        0x12
#define DMA_USER_MOD_ADC6        0x13
#define DMA_USER_MASP0_RX        0x14
#define DMA_USER_MASP0_TX        0x15
#define DMA_USER_MASP1_RX        0x16
#define DMA_USER_MASP1_TX        0x17
#define DMA_USER_MASP2_RX        0x18
#define DMA_USER_MASP2_TX        0x19

#define DMA_USER_SPI0_RX         0x1A
#define DMA_USER_SPI0_TX         0x1B
#define DMA_USER_SPI1_RX         0x1C
#define DMA_USER_SPI1_TX         0x1D
#define DMA_USER_SPI2_RX         0x1E
#define DMA_USER_SPI2_TX         0x1F

#define DMA_USER_GPIO_A          0x20
#define DMA_USER_GPIO_B          0x21
#define DMA_USER_GPIO_C          0x22
#define DMA_USER_GPIO_D          0x23

#define DMA_USER_SW_PROG         0xFF

/* 
   Allocate a DMA channel. User ID and Channel ID should be commensurate with
   hardware connection. Refer to CC3200 datasheet for details. 

   Returns a valid handle on success otherwise NULL
*/

cc_hndl cc_dma_alloc(u8 chan_id, u8 user_id);
void cc_dma_free(cc_hndl);

struct cc_dma_chan_cfg {

        bool            priority; /* Must it get a priority? */
        bool            en_burst; /* Must it use burst xfer? */
        bool            en_hwreq; /* Must it trig by signal? */
        bool            alt_cblk; /* Use alternate cntl blk? */
};

/* 
   Configure channel centric parameters.

   Returns 0 on success otherwise -1
*/
i32 cc_dma_chan_config(cc_hndl hndl, const struct cc_dma_chan_cfg *chan_cfg);

enum dma_incr {

        DMA_INCR_08_BITS,
        DMA_INCR_16_BITS,
        DMA_INCR_32_BITS,
        DMA_INCR_NO_INCR
};

enum dma_type {

        DMA_TYPE_08_BITS,
        DMA_TYPE_16_BITS,
        DMA_TYPE_32_BITS
};

/*
  Basic Mode: HW triggered single & contiguous transfer b/w peripheral & memory
  Auto  Mode: SW initiated single & contiguous transfer from memory to memory
  Ping  Pong: HW triggered continous tranfer through memory replenishment
  SG  Memory: SW initiated scatter gather transfer from memory to memory
  SG  Periph: HW triggered scatter gather transfer b/w peripheral & memory 
  
*/

enum dma_mode {

        DMA_BASIC_REQ,   /* Basic Mode */
        DMA_AUTO_MODE,   /* Auto  Mode */
        DMA_PING_PONG,   /* Ping  Pong */
        DMA_MEMORY_SG,   /* Scatter Gather */
        DMA_PERIPH_SG    /* Scatter-Gather */

};

enum dma_arbt {

        ARB_0001_ITEM = 0x0,
        ARB_0002_ITEM = 0x1,
        ARB_0004_ITEM = 0x2,
        ARB_0008_ITEM = 0x3,
        ARB_0016_ITEM = 0x4,
        ARB_0032_ITEM = 0x5,
        ARB_0064_ITEM = 0x6,
        ARB_0128_ITEM = 0x7,
        ARB_0256_ITEM = 0x8,
        ARB_0512_ITEM = 0x9,
        ARB_1024_ITEM = 0xA
};
        
struct cc_dma_cmd_desc {
        
        enum dma_type   buf_type;  /* Same for both SRC and DST */

        enum dma_incr   dst_incr;
        enum dma_incr   src_incr;

        enum dma_mode   mode_dma;

        enum dma_arbt   arb_size;

        bool            do_burst;
};

/*
  Set-up nuances for a DMA transaction to be scheduled later.
  
  Returns 0 on success otherwise -1
*/
i32 cc_dma_desc_config(cc_hndl hndl, const struct cc_dma_cmd_desc *cmd_desc);

/* 
   Schedule a transaction for 'basic mode', 'auto mode', 'ping-pong replishment'
   
   Return 0 on success otherwise -1
*/
i32 cc_dma_submit_endp(cc_hndl hndl, void *src_endp, void *dst_endp,
                       i32 n_item, bool pp_last);

struct cc_dma_buf {
        
        /* Size of this construct must be 16 Bytes and its composition is tied 
           to underlying hardware - do not change without good considerations.
           
           Provider of construct must provide values for 'src_endp', 'dst_endp'
           & 'num_item'
        */
        
        void           *src_endp;  /* Callee: SRC Address for DMA */
        void           *dst_endp;  /* Callee: DST Address for DMA */

        union {
                u32     num_item;  /* Callee: # src to dst xfers  */
                u32     ctl_word;  /* HAL creates HW control word */
        } u;

        u32             reserved;
};

/* 
   Buffer Vector (array) for scatter-gather, depending upon intended use, can 
   be prepared in two ways. a) Explicit configuration of each element of buff 
   vector by creating hardware control word b) Use of a common descriptor for
   all element of buffer vector (array).

   This routine serves option (a), where hardware control word is configured
   for specified vector element. All elements of vector must be set-up using
   this routine. Further, for option (a), parameter 'has_ctlw' must be set as
   true in function cc_dma_submit_sg_bvec(). 

   Note: Callee must provide correct values for each member of each element.

*/
i32 cc_dma_prep_sg_elem_ctlw(const struct cc_dma_cmd_desc *cmd_desc,
                             struct cc_dma_buf *vec_elem);

/* 
   Schedule a transaction for 'scatter gather mode'.

   If buffer vector (array) has been configured for DMA control word in each of
   element by using cc_dma_prep_sg_elem_ctlw(), then the parameter 'has_ctw'
   must set as true.

   If 'has_ctlw' parameter is set as false, then HAL implementation will apply
   a common DMA control word, created from configuration info provided by API
   cc_dma_desc_config(), to all elements of vector / array. However, callee
   must provide correct values for each member of each element of buffer vector.
   
   Return 0 on success otherwise -1
*/
i32 cc_dma_submit_sg_bvec(cc_hndl hndl,   i32 n_bvec, 
                          struct cc_dma_buf *buf_vec,
                          bool has_ctlw);

/* 
   Schedule a transaction for 'ping-pong mode'

   Return 0 on success otherwise -1
*/
i32 cc_dma_submit_pp_endp(cc_hndl hndl, struct cc_dma_buf *buf1,
                          struct cc_dma_buf *buf2);

i32 cc_dma_done(cc_hndl hndl);

#endif //__DMA_HAL_H__
