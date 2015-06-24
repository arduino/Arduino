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

#include "rom.h"
#include "rom_map.h"
#include "cc_types.h"
#include "dma_hal.h"

/*------------------------------------------------------------------------------
 *   Util functions to tranlate HAL public enums to Driver Lib Values
 *------------------------------------------------------------------------------
 */

static u32 dma_type_bitmap(enum dma_type buf_type)
{
        u32 bitmap = 0;
        
        switch(buf_type) {
                
        case DMA_TYPE_08_BITS: bitmap = UDMA_SIZE_8;  break;
        case DMA_TYPE_16_BITS: bitmap = UDMA_SIZE_16; break;
        case DMA_TYPE_32_BITS: bitmap = UDMA_SIZE_32; break;
        default:                                      break;
                
        }
        
        return bitmap;
}

static u32 incr_bitmap(enum dma_incr val_incr, bool src)
{
        u32 bitmap = 0;
        
#define DMA_INC_CATVAL_BITMAP(str) src? UDMA_SRC_INC_##str : UDMA_DST_INC_##str
        
        switch(val_incr) {
                
        case DMA_INCR_08_BITS: bitmap = DMA_INC_CATVAL_BITMAP(8);    break;
        case DMA_INCR_16_BITS: bitmap = DMA_INC_CATVAL_BITMAP(16);   break;
        case DMA_INCR_32_BITS: bitmap = DMA_INC_CATVAL_BITMAP(32);   break;
        case DMA_INCR_NO_INCR: bitmap = DMA_INC_CATVAL_BITMAP(NONE); break;
        default:                                                     break;
                
        }
        
        return bitmap;
}

static u32 src_incr_bitmap(enum dma_incr val_incr)
{
        return incr_bitmap(val_incr,  true);
}

static u32 dst_incr_bitmap(enum dma_incr val_incr)
{
        return incr_bitmap(val_incr, false);
}

static u32 dma_mode_bitmap(enum dma_mode mode_dma)
{
        u32 bitmap = 0;
        
        switch(mode_dma) {
                
        case DMA_BASIC_REQ: bitmap = UDMA_MODE_BASIC;              break;
        case DMA_AUTO_MODE: bitmap = UDMA_MODE_AUTO;               break;
        case DMA_PING_PONG: bitmap = UDMA_MODE_PINGPONG;           break;
        case DMA_MEMORY_SG: bitmap = UDMA_MODE_MEM_SCATTER_GATHER; break;
        case DMA_PERIPH_SG: bitmap = UDMA_MODE_PER_SCATTER_GATHER; break;
        default:                                                   break;
        }

        return bitmap;
}

static u32 dma_arbt_bitmap(enum dma_arbt arb_size)
{
        u32 bitmap = 0;

#define DMA_ARBT_CATVAL_BITMAP(str)  UDMA_ARB_##str

        switch(arb_size) {
                
        case ARB_0001_ITEM: bitmap = DMA_ARBT_CATVAL_BITMAP(1);    break;
        case ARB_0002_ITEM: bitmap = DMA_ARBT_CATVAL_BITMAP(2);    break;
        case ARB_0004_ITEM: bitmap = DMA_ARBT_CATVAL_BITMAP(4);    break;
        case ARB_0008_ITEM: bitmap = DMA_ARBT_CATVAL_BITMAP(8);    break;
        case ARB_0016_ITEM: bitmap = DMA_ARBT_CATVAL_BITMAP(16);   break;
        case ARB_0032_ITEM: bitmap = DMA_ARBT_CATVAL_BITMAP(32);   break;
        case ARB_0064_ITEM: bitmap = DMA_ARBT_CATVAL_BITMAP(64);   break;
        case ARB_0128_ITEM: bitmap = DMA_ARBT_CATVAL_BITMAP(128);  break;
        case ARB_0256_ITEM: bitmap = DMA_ARBT_CATVAL_BITMAP(256);  break;
        case ARB_0512_ITEM: bitmap = DMA_ARBT_CATVAL_BITMAP(512);  break;
        case ARB_1024_ITEM: bitmap = DMA_ARBT_CATVAL_BITMAP(1024); break;
                
        default:                                                   break;
                
        }

        return bitmap;
}


/*------------------------------------------------------------------------------
 *   Implementation of core functions of DMA HAL
 *------------------------------------------------------------------------------
 */

struct dma_chan_desc {

        u8    chan_id;  /* Channel ID: Range 0 to 31 */
        u8    user_id;  /* Allocated user of channel */

        u8    free_ep;  /* num free endpoint for use */ 
        u8    use_alt;  /* Use alternate Control BLK */
        u32   ctl_val;  /* HW Channel Control Value  */
        
        u32   n_ppdma;  /* num of ping-pong dma xfer */

        enum dma_mode   mode_dma;
};

static struct dma_chan_desc chan_desc[32];
u32  i;
i32 cc_dma_init(const struct cc_dma_cfg *dma_cfg)
{
        MAP_uDMAEnable();
        
        MAP_uDMAControlBaseSet(dma_cfg->ctl_table);
        i = sizeof(chan_desc);
        memset(chan_desc, 0, sizeof(chan_desc));
        
        return 0;
}

void cc_dma_exit()
{
        MAP_uDMADisable();
}

#define MAX_CHAN_MUX      4
#define MAX_DMA_CHAN     32

struct chan_mux_desc {
        u8 user_id[MAX_CHAN_MUX];
};

#define CHAN_MUX_OPT(m1, m2, m3)                                        \
        {DMA_USER_##m1, DMA_USER_##m2, DMA_USER_##m3, DMA_USER_SW_PROG}

static const struct chan_mux_desc chan_mux[] = {
        CHAN_MUX_OPT(TIMER0_A, MOD_NONE, MOD_NONE), /* Chan# 00 */
        CHAN_MUX_OPT(TIMER0_B, MOD_NONE, MOD_NONE), /* Chan# 01 */
        CHAN_MUX_OPT(TIMER1_A, MOD_NONE, MOD_NONE), /* Chan# 02 */
        CHAN_MUX_OPT(TIMER1_B, MOD_NONE, MOD_NONE), /* Chan# 03 */
        CHAN_MUX_OPT(TIMER2_A, MOD_NONE, MASP0_RX), /* Chan# 04 */
        CHAN_MUX_OPT(TIMER2_B, MOD_NONE, MASP0_TX), /* Chan# 05 */
        CHAN_MUX_OPT(TIMER3_A, SPI1_RX,  GPIO_C  ), /* Chan# 06 */
        CHAN_MUX_OPT(TIMER3_B, SPI1_TX,  GPIO_D  ), /* Chan# 07 */
        CHAN_MUX_OPT(UART0_RX, TIMER0_A, TIMER2_A), /* Chan# 08 */
        CHAN_MUX_OPT(UART0_TX, TIMER0_B, TIMER2_B), /* Chan# 09 */
        CHAN_MUX_OPT(UART1_RX, TIMER1_A, TIMER3_A), /* Chan# 10 */
        CHAN_MUX_OPT(UART1_TX, TIMER1_B, TIMER3_B), /* Chan# 11 */
        CHAN_MUX_OPT(SPI2_RX,  MOD_NONE, MOD_NONE), /* Chan# 12 */
        CHAN_MUX_OPT(SPI2_TX,  MOD_NONE, MOD_NONE), /* Chan# 13 */
        CHAN_MUX_OPT(MOD_ADC0, MOD_NONE, MOD_NONE), /* Chan# 14 */
        CHAN_MUX_OPT(MOD_ADC2, MOD_NONE, MOD_NONE), /* Chan# 15 */
        CHAN_MUX_OPT(MOD_ADC4, TIMER2_A, MOD_NONE), /* Chan# 16 */
        CHAN_MUX_OPT(MOD_ADC6, TIMER2_B, MOD_NONE), /* Chan# 17 */
        CHAN_MUX_OPT(GPIO_A,   MOD_NONE, MASP0_RX), /* Chan# 18 */
        CHAN_MUX_OPT(GPIO_B,   MOD_NONE, MASP0_TX), /* Chan# 19 */
        CHAN_MUX_OPT(GPIO_C,   MOD_NONE, MOD_NONE), /* Chan# 20 */
        CHAN_MUX_OPT(GPIO_D,   MOD_NONE, MOD_NONE), /* Chan# 21 */
        CHAN_MUX_OPT(CAM_PORT, MOD_NONE, MOD_NONE), /* Chan# 22 */
        CHAN_MUX_OPT(MOD_NONE, TIMER3_A, TIMER2_A), /* Chan# 23 */
        CHAN_MUX_OPT(MOD_NONE, TIMER3_B, TIMER2_B), /* Chan# 24 */
        CHAN_MUX_OPT(SPI0_RX,  I2C0_RX,  TIMER2_A), /* Chan# 25 */
        CHAN_MUX_OPT(SPI0_TX,  I2C0_TX,  TIMER2_B), /* Chan# 26 */
        CHAN_MUX_OPT(MOD_NONE, GPIO_A,   TIMER2_A), /* Chan# 27 */
        CHAN_MUX_OPT(MOD_NONE, GPIO_B,   TIMER2_B), /* Chan# 28 */
        CHAN_MUX_OPT(MOD_NONE, MOD_NONE, TIMER2_A), /* Chan# 29 */
        CHAN_MUX_OPT(SPI1_RX,  MOD_NONE, I2C0_RX),  /* Chan# 30 */
        CHAN_MUX_OPT(SPI1_TX,  MOD_NONE, I2C0_TX)   /* Chan# 31 */
};

static u32 get_user_mux_mode(u8 chan_id, u8 user_id)
{
        const struct chan_mux_desc *mux_chan = chan_mux + chan_id;
        u32 mux_mode = 0;
        
        for(mux_mode = 0; mux_mode < MAX_CHAN_MUX; mux_mode++) {
                if(user_id == mux_chan->user_id[mux_mode])
                        break;
        }
        
        return mux_mode;
}

static bool is_user_alloted(u8 user_id)
{
        struct dma_chan_desc *desc = NULL;
        i32 i = 0;
        
        for(i = 0, desc = chan_desc + 0; i < MAX_DMA_CHAN; desc++) {
                if(user_id == desc->user_id)
                        return true;
                i++;
        }

        return false;
}

cc_hndl cc_dma_alloc(u8 chan_id, u8 user_id)
{
        u32 mux_mode = MAX_CHAN_MUX;
        struct dma_chan_desc *desc = NULL;
        
        if((chan_id > 31) || (true == is_user_alloted(user_id)))
                return NULL;
        
        mux_mode = get_user_mux_mode(chan_id, user_id);
        if(MAX_CHAN_MUX == mux_mode)
                return NULL;

        /* Configure DMA MUX mode in HW */
        MAP_uDMAChannelAssign(mux_mode << 16 | chan_id);

        /* House keeping for channel */
        desc          = chan_desc + chan_id;
        desc->user_id = user_id;
        desc->chan_id = chan_id;

        return (cc_hndl) desc;
}

void cc_dma_free(cc_hndl hndl)
{
        struct dma_chan_desc *desc = (struct dma_chan_desc*) hndl;
        
        if(NULL != desc) {
                desc->user_id = DMA_USER_MOD_NONE;
                
                /* Need to access Hardware to disable assignment */
                /* No device ROM API availalbe */
        }

        return;
}

i32 cc_dma_chan_config(cc_hndl hndl, const struct cc_dma_chan_cfg *chan_cfg)
{
        u32 bitmap = 0;

        struct dma_chan_desc *desc = (struct dma_chan_desc*) hndl;
        if((NULL == desc) || (NULL == chan_cfg))
                return -1;

        if(chan_cfg->priority) bitmap |= UDMA_ATTR_HIGH_PRIORITY;
        
        if(chan_cfg->en_burst) bitmap |= UDMA_ATTR_USEBURST;

        if(chan_cfg->en_hwreq) bitmap |= UDMA_ATTR_REQMASK;

        if(chan_cfg->alt_cblk) bitmap |= UDMA_ATTR_ALTSELECT;

        desc->use_alt = chan_cfg->alt_cblk;
        
        if(bitmap) 
                MAP_uDMAChannelAttributeEnable(desc->chan_id, bitmap);

        bitmap = ~bitmap & (UDMA_ATTR_HIGH_PRIORITY |
                            UDMA_ATTR_USEBURST      |
                            UDMA_ATTR_REQMASK       |
                            UDMA_ATTR_ALTSELECT);

        if(bitmap)
                MAP_uDMAChannelAttributeDisable(desc->chan_id, bitmap);

        return 0;
}

i32 cc_dma_desc_config(cc_hndl hndl, const struct cc_dma_cmd_desc *cmd_desc)
{
        struct dma_chan_desc *desc = (struct dma_chan_desc*) hndl;

        if((NULL == desc)  || (NULL == cmd_desc))
                return -1;
                        
        desc->ctl_val = (dma_type_bitmap(cmd_desc->buf_type)         |
                         dst_incr_bitmap(cmd_desc->dst_incr)         |
                         src_incr_bitmap(cmd_desc->src_incr)         |
                         dma_arbt_bitmap(cmd_desc->arb_size)         |
                         (cmd_desc->do_burst? UDMA_NEXT_USEBURST : 0));
        
        desc->mode_dma =   cmd_desc->mode_dma;
        desc->free_ep  =  (DMA_PING_PONG == desc->mode_dma) ? 2 : 1;

        return 0;
}

#define DMA_CHAN_SELECT(chan_id, use_alt)                               \
        (chan_id | (use_alt? UDMA_ALT_SELECT : UDMA_PRI_SELECT))

static 
void dma_submit_endp(struct dma_chan_desc *desc, void *src_endp, void *dst_endp,
                     i32 n_item, bool use_alt, enum dma_mode mode_dma)
{
        MAP_uDMAChannelControlSet(DMA_CHAN_SELECT(desc->chan_id, use_alt),
                                  desc->ctl_val);
        
        MAP_uDMAChannelTransferSet(DMA_CHAN_SELECT(desc->chan_id, use_alt),
        						   dma_mode_bitmap(mode_dma),
        						   src_endp, dst_endp, n_item);

        MAP_uDMAChannelEnable(desc->chan_id);
        
        desc->free_ep--;
        
        return;
}

i32 cc_dma_submit_pp_endp(cc_hndl hndl, struct cc_dma_buf *buf1,
                          struct cc_dma_buf *buf2)
{
        if((0 != cc_dma_submit_endp(hndl, buf1->src_endp, buf1->dst_endp,
                                    buf1->u.num_item, false))   ||
           (0 != cc_dma_submit_endp(hndl, buf2->src_endp, buf2->dst_endp,
                                    buf2->u.num_item, false)))   {
                return -1;
        }
        
        return 0;
}


i32 cc_dma_submit_endp(cc_hndl hndl, void *src_endp,  void *dst_endp,
                       i32 n_item, bool pp_last)
{
        i32 ret_val = 0;
        
        struct dma_chan_desc *desc = (struct dma_chan_desc*) hndl;
        if((NULL == desc)  /*(0 == desc->free_ep)*/)
                return -1;
        
#define DMA_SUBMIT_ENDP(use_alt, mode_dma)                              \
        dma_submit_endp(desc, src_endp, dst_endp, n_item, use_alt, mode_dma)
        
        switch(desc->mode_dma) {
                
        case DMA_BASIC_REQ:
                DMA_SUBMIT_ENDP(desc->use_alt, desc->mode_dma);
                break;
                
        case DMA_AUTO_MODE:
                DMA_SUBMIT_ENDP(desc->use_alt, desc->mode_dma);
                MAP_uDMAChannelRequest(desc->chan_id);
                break;

        case DMA_PING_PONG:
            DMA_SUBMIT_ENDP(((desc->n_ppdma & 0x1)? true : false), 
                                (pp_last? DMA_BASIC_REQ : desc->mode_dma));
                desc->n_ppdma++;
                break;
                
        case DMA_MEMORY_SG:
        case DMA_PERIPH_SG:
        default:
                ret_val = -1;
                break;

        }

        return ret_val;
}

#define CTLW_INCL_NITEM_MODE(ctlw, n_item, mode_bitmap)         \
        ((ctlw & ~0x3FF7) | (n_item << 4) | mode_bitmap)

i32 cc_dma_prep_sg_elem_ctlw(const struct cc_dma_cmd_desc *cmd_desc,
                             struct cc_dma_buf *vec_elem)
{
        u32 ctl_word = 0;

        if((NULL == cmd_desc) || (NULL == vec_elem))
                return -1;

        ctl_word = (dma_type_bitmap(cmd_desc->buf_type)         |
                    dst_incr_bitmap(cmd_desc->dst_incr)         |
                    src_incr_bitmap(cmd_desc->src_incr)         |
                    dma_arbt_bitmap(cmd_desc->arb_size)         |
                    cmd_desc->do_burst? UDMA_NEXT_USEBURST : 0);
        
        vec_elem->u.ctl_word = CTLW_INCL_NITEM_MODE(ctl_word,
                                                    vec_elem->u.num_item,
                                                    cmd_desc->mode_dma);
        
        return 0;
}

static void prep_sg_bvec_ctlw(struct dma_chan_desc *desc, i32 n_bvec,
                              struct cc_dma_buf *buf_vec, 
                              bool mem_sg)
{
        struct cc_dma_buf *vec = NULL;
        i32 i = 0;
        
        for(vec = buf_vec, i = 0; i < n_bvec - 1; vec++, i++) {
                vec->u.ctl_word = 
                        CTLW_INCL_NITEM_MODE(desc->ctl_val, vec->u.num_item,
                                             dma_mode_bitmap(desc->mode_dma));
        }
        
        vec->u.ctl_word = 
                CTLW_INCL_NITEM_MODE(desc->ctl_val, vec->u.num_item, 
                                     mem_sg? DMA_AUTO_MODE : DMA_BASIC_REQ);
}

static void submit_sg_bvec(struct dma_chan_desc *desc, i32 n_bvec, 
                           struct cc_dma_buf *buf_vec, 
                           bool has_ctlw, bool mem_sg)
{
        if(false == has_ctlw) 
                prep_sg_bvec_ctlw(desc, n_bvec, buf_vec, mem_sg);
        
        MAP_uDMAChannelControlSet(DMA_CHAN_SELECT(desc->chan_id, false),
                              desc->ctl_val);
        
        MAP_uDMAChannelScatterGatherSet(desc->chan_id, n_bvec, buf_vec,
                                    mem_sg ? 1: 0);
        
        MAP_uDMAChannelEnable(desc->chan_id);

        desc->free_ep--;
        
        return;
}

i32 cc_dma_submit_sg_bvec(cc_hndl hndl, i32 n_bvec, struct cc_dma_buf *buf_vec,
                          bool has_ctlw)
{
        i32 ret_val = 0;
        
        struct dma_chan_desc *desc = (struct dma_chan_desc*) hndl;
        if((NULL == desc) || (0 == desc->free_ep) || (n_bvec < 1) || !buf_vec)
                return -1;
        
        switch(desc->mode_dma) {
                
        case DMA_PERIPH_SG:
                submit_sg_bvec(desc, n_bvec, buf_vec, has_ctlw, false);
                break;
                      
        case DMA_MEMORY_SG:
                submit_sg_bvec(desc, n_bvec, buf_vec, has_ctlw, true);
                MAP_uDMAChannelRequest(desc->chan_id);
                break;

        case DMA_BASIC_REQ:
        case DMA_AUTO_MODE:
        case DMA_PING_PONG:
        default:
                ret_val = -1;
                break;
        }
        
        return ret_val;
}

i32 cc_dma_done(cc_hndl hndl)
{
        struct dma_chan_desc *desc = (struct dma_chan_desc*) hndl;
        
        if(NULL == desc)
                return -1;

        if(DMA_PING_PONG == desc->mode_dma) {
                desc->n_ppdma = 0;
                if(2 > desc->free_ep) desc->free_ep++;
        } else {
                if(1 > desc->free_ep) desc->free_ep++;
        }
         
        return 0;
}
