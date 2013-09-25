/* --COPYRIGHT--,BSD
 * Copyright (c) 2012, Texas Instruments Incorporated
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
 * --/COPYRIGHT--*/
/* 
 * ======== dma.c ========
 */
#include "device.h"
#include "types.h"    //Basic Type declarations
#include "defMSP430USB.h"
#include <descriptors.h>
#include <string.h>


#ifdef __REGISTER_MODEL__
/* for IAR */
#   if __REGISTER_MODEL__ == __REGISTER_MODEL_REG20__
#       define __DMA_ACCESS_REG__ (void __data20 *)
#   else
#       define __DMA_ACCESS_REG__ (unsigned short)
#   endif
#else
/* for CCS */
#   define __DMA_ACCESS_REG__ (__SFR_FARPTR)(unsigned long)
#endif

#ifdef __GNUC__
#undef __DMA_ACCESS_REG__
#define __DMA_ACCESS_REG__ (uint16_t)
#endif

//function pointers
VOID *(*USB_TX_memcpy)(VOID * dest, const VOID * source, size_t count);
VOID *(*USB_RX_memcpy)(VOID * dest, const VOID * source, size_t count);

VOID * memcpyDMA0 (VOID * dest, const VOID * source, size_t count);
VOID * memcpyDMA1 (VOID * dest, const VOID * source, size_t count);
VOID * memcpyDMA2 (VOID * dest, const VOID * source, size_t count);

//NOTE: this functin works only with data in the area <64k (small memory model)
VOID * memcpyV (VOID * dest, const VOID * source, size_t count)
{
    WORD i;
    volatile BYTE bTmp;

    for (i = 0; i < count; i++)
    {
        bTmp = *((BYTE*)source + i);
        *((BYTE*)dest  + i) = bTmp;
    }
    return (dest);
}

//this function inits the DMA
VOID USB_initMemcpy (VOID)
{
    USB_TX_memcpy = memcpyV;
    USB_RX_memcpy = memcpyV;

    switch (USB_DMA_CHAN)
    {
        case 0:
            DMACTL0 &= ~DMA0TSEL_31;                        //DMA0 is triggered by DMAREQ
            DMACTL0 |= DMA0TSEL_0;                          //DMA0 is triggered by DMAREQ
            DMA0CTL = (DMADT_1 + DMASBDB + DMASRCINCR_3 +   //configure block transfer (byte-wise) with increasing source
                       DMADSTINCR_3 );                      //and destination address
            DMACTL4 |= ENNMI;                               //enable NMI interrupt
            USB_TX_memcpy = memcpyDMA0;
            USB_RX_memcpy = memcpyDMA0;
            break;
        case 1:
            DMACTL0 &= ~DMA1TSEL_31;                        //DMA1 is triggered by DMAREQ
            DMACTL0 |= DMA1TSEL_0;                          //DMA1 is triggered by DMAREQ
            DMA1CTL = (DMADT_1 + DMASBDB + DMASRCINCR_3 +   //configure block transfer (byte-wise) with increasing source
                       DMADSTINCR_3 );                      //and destination address
            DMACTL4 |= ENNMI;                               //enable NMI interrupt
            USB_TX_memcpy = memcpyDMA1;
            USB_RX_memcpy = memcpyDMA1;
            break;
        case 2:
            DMACTL0 &= ~DMA2TSEL_31;                        //DMA2 is triggered by DMAREQ
            DMACTL0 |= DMA2TSEL_0;                          //DMA2 is triggered by DMAREQ
            DMA2CTL = (DMADT_1 + DMASBDB + DMASRCINCR_3 +   //configure block transfer (byte-wise) with increasing source
                       DMADSTINCR_3 );                      //and destination address
            DMACTL4 |= ENNMI;                               //enable NMI interrupt
            USB_TX_memcpy = memcpyDMA2;
            USB_RX_memcpy = memcpyDMA2;
            break;
    }
}

//this functions starts DMA transfer to/from USB memory into/from RAM
//Using DMA0
//Support only for data in <64k memory area.
VOID * memcpyDMA0 (VOID * dest, const VOID *  source, size_t count)
{
    if (count == 0){                                        //do nothing if zero bytes to transfer
        return (dest);
    }

    DMA0DA = __DMA_ACCESS_REG__ dest;                       //set destination for DMAx
    DMA0SA = __DMA_ACCESS_REG__ source;                     //set source for DMAx
    DMA0SZ = count;                                         //how many bytes to transfer

    DMA0CTL |= DMAEN;                                       //enable DMAx
    DMA0CTL |= DMAREQ;                                      //trigger DMAx

    //wait for DMA transfer finished
    while (!(DMA0CTL & DMAIFG)) ;

    DMA0CTL &= ~DMAEN;                                      //disable DMAx
    return (dest);
}

//this functions starts DMA transfer to/from USB memory into/from RAM
//Using DMA1
//Support only for data in <64k memory area.
VOID * memcpyDMA1 (VOID * dest, const VOID * source, size_t count)
{
    if (count == 0){                                        //do nothing if zero bytes to transfer
        return (dest);
    }

    DMA1DA = __DMA_ACCESS_REG__ dest;                       //set destination for DMAx
    DMA1SA = __DMA_ACCESS_REG__ source;                     //set source for DMAx
    DMA1SZ = count;                                         //how many bytes to transfer

    DMA1CTL |= DMAEN;                                       //enable DMAx
    DMA1CTL |= DMAREQ;                                      //trigger DMAx

    //wait for DMA transfer finished
    while (!(DMA1CTL & DMAIFG)) ;

    DMA1CTL &= ~DMAEN;                                      //disable DMAx
    return (dest);
}

//this functions starts DMA transfer to/from USB memory into/from RAM
//Using DMA2
//Support only for data in <64k memory area.
VOID * memcpyDMA2 (VOID * dest, const VOID * source, size_t count)
{
    if (count == 0){                                        //do nothing if zero bytes to transfer
        return (dest);
    }

    DMA2DA = __DMA_ACCESS_REG__ dest;                       //set destination for DMAx
    DMA2SA = __DMA_ACCESS_REG__ source;                     //set source for DMAx
    DMA2SZ = count;                                         //how many bytes to transfer

    DMA2CTL |= DMAEN;                                       //enable DMAx
    DMA2CTL |= DMAREQ;                                      //trigger DMAx

    //wait for DMA transfer finished
    while (!(DMA2CTL & DMAIFG)) ;

    DMA2CTL &= ~DMAEN;                                      //disable DMAx
    return (dest);
}

/*----------------------------------------------------------------------------+
 | End of source file                                                          |
 +----------------------------------------------------------------------------*/
/*------------------------ Nothing Below This Line --------------------------*/
