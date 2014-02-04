/**
 * @file - tivaif.c
 * lwIP Ethernet interface for Stellaris LM4F Devices
 *
 */

/**
 * Copyright (c) 2001-2004 Swedish Institute of Computer Science.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICui32AR PURPOSE ARE DISCLAIMED. IN NO EVENT
 * SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 *
 * This file is part of the lwIP TCP/IP stack.
 *
 * Author: Adam Dunkels <adam@sics.se>
 *
 */

/**
 * Copyright (c) 2008-2012 Texas Instruments Incorporated
 *
 * This file is derived from the ``ethernetif.c'' skeleton Ethernet network
 * interface driver for lwIP.
 *
 */

#include <stdbool.h>
#include <stdint.h>
#include "lwip/opt.h"
#include "lwip/def.h"
#include "lwip/mem.h"
#include "lwip/pbuf.h"
#include "lwip/sys.h"
#include <lwip/stats.h>
#include <lwip/snmp.h>
#include "lwip/tcpip.h"
#include "netif/etharp.h"
#include "netif/ppp_oe.h"
#include "netif/tivaif.h"

/**
 * Sanity Check:  This interface driver will NOT work if the following defines
 * are incorrect.
 *
 */
#if (PBUF_LINK_HLEN != 16)
#error "PBUF_LINK_HLEN must be 16 for this interface driver!"
#endif
#if (ETH_PAD_SIZE != 0)
#error "ETH_PAD_SIZE must be 0 for this interface driver!"
#endif
#if (!SYS_LIGHTWEIGHT_PROT)
#error "SYS_LIGHTWEIGHT_PROT must be enabled for this interface driver!"
#endif

/**
 * Set the physical address of the PHY we will be using if this is not
 * specified in lwipopts.h.  We assume 0 for the internal PHY.
 */
#ifndef PHY_PHYS_ADDR
#define PHY_PHYS_ADDR 0
#endif

#if 0
#ifndef EMAC_PHY_CONFIG
#define EMAC_PHY_CONFIG (EMAC_PHY_TYPE_INTERNAL | EMAC_PHY_INT_MDIX_EN |      \
                         EMAC_PHY_AN_100B_T_FULL_DUPLEX)
#endif
#endif

/**
 * If necessary, set the defaui32t number of transmit and receive DMA descriptors
 * used by the Ethernet MAC.
 *
 */
#ifndef NUM_RX_DESCRIPTORS
#define NUM_RX_DESCRIPTORS 4
#endif

#ifndef NUM_TX_DESCRIPTORS
#define NUM_TX_DESCRIPTORS 8
#endif

/**
 * Setup processing for PTP (IEEE-1588).
 *
 */
#if LWIP_PTPD
extern uint32_t g_ui32SysClk;
extern uint32_t g_ui32PTPTickRate;
extern void lwIPHostGetTime(u32_t *time_s, u32_t *time_ns);
#endif

/**
 * Stellaris DriverLib Header Files required for this interface driver.
 *
 */
#include <stdint.h>
#include <stdbool.h>
#include <Energia.h>
#include "inc/hw_emac.h"
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/emac.h"
#include "driverlib/interrupt.h"
#include "driverlib/sysctl.h"

/* Define those to better describe your network interface. */
#define IFNAME0 't'
#define IFNAME1 'i'

/**
 * A structure used to keep track of driver state and error counts.
 */
typedef struct {
    uint32_t ui32TXCount;
    uint32_t ui32TXCopyCount;
    uint32_t ui32TXCopyFailCount;
    uint32_t ui32TXNoDescCount;
    uint32_t ui32TXBufQueuedCount;
    uint32_t ui32TXBufFreedCount;
    uint32_t ui32RXBufReadCount;
    uint32_t ui32RXPacketReadCount;
    uint32_t ui32RXPacketErrCount;
    uint32_t ui32RXPacketCBErrCount;
    uint32_t ui32RXNoBufCount;
}
tDriverStats;

tDriverStats g_sDriverStats;

#ifdef DEBUG
/**
 * Note: This rather weird construction where we invoke the macro with the
 * name of the field minus its Hungarian prefix is a workaround for a problem
 * experienced with GCC which does not like concatenating tokens after an
 * operator, specifically '.' or '->', in a macro.
 */
#define DRIVER_STATS_INC(x) do{ g_sDriverStats.ui32##x++; } while(0)
#define DRIVER_STATS_DEC(x) do{ g_sDriverStats.ui32##x--; } while(0)
#define DRIVER_STATS_ADD(x, inc) do{ g_sDriverStats.ui32##x += (inc); } while(0)
#define DRIVER_STATS_SUB(x, dec) do{ g_sDriverStats.ui32##x -= (dec); } while(0)
#else
#define DRIVER_STATS_INC(x)
#define DRIVER_STATS_DEC(x)
#define DRIVER_STATS_ADD(x, inc)
#define DRIVER_STATS_SUB(x, dec)
#endif

/**
 *  Helper struct holding a DMA descriptor and the pbuf it currently refers
 *  to.
 */
typedef struct {
  tEMACDMADescriptor Desc;
  struct pbuf *pBuf;
} tDescriptor;

typedef struct {
    tDescriptor *pDescriptors;
    uint32_t ui32NumDescs;
    uint32_t ui32Read;
    uint32_t ui32Write;
} tDescriptorList;

/**
 * Helper struct to hold private data used to operate your ethernet interface.
 * Keeping the ethernet address of the MAC in this struct is not necessary
 * as it is already kept in the struct netif.
 * But this is only an example, anyway...
 */
typedef struct {
  struct eth_addr *ethaddr;
  /* Add whatever per-interface state that is needed here. */
  tDescriptorList *pTxDescList;
  tDescriptorList *pRxDescList;
} tStellarisIF;

/**
 * Global variable for this interface's private data.  Needed to allow
 * the interrupt handlers access to this information outside of the
 * context of the lwIP netif.
 *
 */
tDescriptor g_pTxDescriptors[NUM_TX_DESCRIPTORS];
tDescriptor g_pRxDescriptors[NUM_RX_DESCRIPTORS];
tDescriptorList g_TxDescList = {
    g_pTxDescriptors, NUM_TX_DESCRIPTORS, 0, 0
};
tDescriptorList g_RxDescList = {
    g_pRxDescriptors, NUM_RX_DESCRIPTORS, 0, 0
};
static tStellarisIF g_StellarisIFData = {
    0, &g_TxDescList, &g_RxDescList
};

/**
 * Interrupt counters (for debug purposes).
 */
volatile uint32_t g_ui32NormalInts;
volatile uint32_t g_ui32AbnormalInts;

/**
 * A macro which determines whether a pointer is within the SRAM address
 * space and, hence, points to a buffer that the Ethernet MAC can directly
 * DMA from.
 */
#define PTR_SAFE_FOR_EMAC_DMA(ptr) (((uint32_t)(ptr) >= 0x2000000) &&   \
                                    ((uint32_t)(ptr) < 0x20070000))
/**
 * Initialize the transmit and receive DMA descriptor lists.
 */
void
InitDMADescriptors(void)
{
    uint32_t ui32Loop;

    /* Transmit list -  mark all descriptors as not owned by the hardware */
   for(ui32Loop = 0; ui32Loop < NUM_TX_DESCRIPTORS; ui32Loop++)
   {
       g_pTxDescriptors[ui32Loop].pBuf = (struct pbuf *)0;
       g_pTxDescriptors[ui32Loop].Desc.ui32Count = 0;
       g_pTxDescriptors[ui32Loop].Desc.pvBuffer1 = 0;
       g_pTxDescriptors[ui32Loop].Desc.DES3.pLink =
               ((ui32Loop == (NUM_TX_DESCRIPTORS - 1)) ?
               &g_pTxDescriptors[0].Desc : &g_pTxDescriptors[ui32Loop + 1].Desc);
       g_pTxDescriptors[ui32Loop].Desc.ui32CtrlStatus = DES0_TX_CTRL_INTERRUPT |
               DES0_TX_CTRL_CHAINED | DES0_TX_CTRL_IP_ALL_CKHSUMS;

   }

   g_TxDescList.ui32Read = 0;
   g_TxDescList.ui32Write = 0;


   /* Receive list -  tag each descriptor with a pbuf and set all fields to
    * allow packets to be received.
    */
  for(ui32Loop = 0; ui32Loop < NUM_RX_DESCRIPTORS; ui32Loop++)
  {
      g_pRxDescriptors[ui32Loop].pBuf = pbuf_alloc(PBUF_RAW, PBUF_POOL_BUFSIZE,
                                                 PBUF_POOL);
      g_pRxDescriptors[ui32Loop].Desc.ui32Count = DES1_RX_CTRL_CHAINED;
      if(g_pRxDescriptors[ui32Loop].pBuf)
      {
          /* Set the DMA to write directly into the pbuf payload. */
          g_pRxDescriptors[ui32Loop].Desc.pvBuffer1 =
                  g_pRxDescriptors[ui32Loop].pBuf->payload;
          g_pRxDescriptors[ui32Loop].Desc.ui32Count |=
             (g_pRxDescriptors[ui32Loop].pBuf->len << DES1_RX_CTRL_BUFF1_SIZE_S);
          g_pRxDescriptors[ui32Loop].Desc.ui32CtrlStatus = DES0_RX_CTRL_OWN;
      }
      else
      {
          LWIP_DEBUGF(NETIF_DEBUG, ("tivaif_init: pbuf_alloc error\n"));

          /* No pbuf available so leave the buffer pointer empty. */
          g_pRxDescriptors[ui32Loop].Desc.pvBuffer1 = 0;
          g_pRxDescriptors[ui32Loop].Desc.ui32CtrlStatus = 0;
      }
      g_pRxDescriptors[ui32Loop].Desc.DES3.pLink =
              ((ui32Loop == (NUM_RX_DESCRIPTORS - 1)) ?
              &g_pRxDescriptors[0].Desc : &g_pRxDescriptors[ui32Loop + 1].Desc);
  }

  g_TxDescList.ui32Read = 0;
  g_TxDescList.ui32Write = 0;

  //
  // Set the descriptor pointers in the hardware.
  //
  EMACRxDMADescriptorListSet(EMAC0_BASE, &g_pRxDescriptors[0].Desc);
  EMACTxDMADescriptorListSet(EMAC0_BASE, &g_pTxDescriptors[0].Desc);
}

/**
 * In this function, the hardware should be initialized.
 * Called from tivaif_init().
 *
 * @param netif the already initialized lwip network interface structure
 *        for this ethernetif
 */
static void
tivaif_hwinit(struct netif *psNetif)
{
  uint16_t ui16Val;

  /* Set MAC hardware address length */
  psNetif->hwaddr_len = ETHARP_HWADDR_LEN;

  /* Set MAC hardware address */
  EMACAddrGet(EMAC0_BASE, 0, &(psNetif->hwaddr[0]));

  /* Maximum transfer unit */
  psNetif->mtu = 1500;

  /* Device capabilities */
  psNetif->flags = NETIF_FLAG_BROADCAST | NETIF_FLAG_ETHARP | NETIF_FLAG_LINK_UP;

  /* Initialize the DMA descriptors. */
  InitDMADescriptors();

  /* Clear any stray PHY interrupts that may be set. */
  ui16Val = EMACPHYRead(EMAC0_BASE, PHY_PHYS_ADDR, EPHY_MISR1);
  ui16Val = EMACPHYRead(EMAC0_BASE, PHY_PHYS_ADDR, EPHY_MISR2);

  /* Configure and enable the link status change interrupt in the PHY. */
  ui16Val = EMACPHYRead(EMAC0_BASE, PHY_PHYS_ADDR, EPHY_SCR);
  ui16Val |= (EPHY_SCR_INTEN_EXT | EPHY_SCR_INTOE_EXT);
  EMACPHYWrite(EMAC0_BASE, PHY_PHYS_ADDR, EPHY_SCR, ui16Val);
  EMACPHYWrite(EMAC0_BASE, PHY_PHYS_ADDR, EPHY_MISR1, (EPHY_MISR1_LINKSTATEN |
               EPHY_MISR1_SPEEDEN | EPHY_MISR1_DUPLEXMEN | EPHY_MISR1_ANCEN));

  /* Read the PHY interrupt status to clear any stray events. */
  ui16Val = EMACPHYRead(EMAC0_BASE, PHY_PHYS_ADDR, EPHY_MISR1);

  /**
   * Set MAC filtering options.  We receive all broadcast and mui32ticast
   * packets along with those addressed specifically for us.
   */
  EMACFrameFilterSet(EMAC0_BASE, (EMAC_FRMFILTER_HASH_AND_PERFECT |
                     EMAC_FRMFILTER_PASS_MULTICAST));

#if LWIP_PTPD
  //
  // Enable timestamping on all received packets.
  //
  // We set the fine clock adjustment mode and configure the subsecond
  // increment to half the 25MHz PTPD clock.  This will give us maximum control
  // over the clock rate adjustment and keep the arithmetic easy later.  It
  // should be possible to synchronize with higher accuracy than this with
  // appropriate juggling of the subsecond increment count and the addend
  // register value, though.
  //
  EMACTimestampConfigSet(EMAC0_BASE, (EMAC_TS_ALL_RX_FRAMES |
                         EMAC_TS_DIGITAL_ROLLOVER |
                         EMAC_TS_PROCESS_IPV4_UDP | EMAC_TS_ALL |
                         EMAC_TS_PTP_VERSION_1 | EMAC_TS_UPDATE_FINE),
                         (1000000000 / (25000000 / 2)));
  EMACTimestampAddendSet(EMAC0_BASE, 0x80000000);
  EMACTimestampEnable(EMAC0_BASE);
#endif

  /* Clear any pending MAC interrupts. */
  EMACIntClear(EMAC0_BASE, EMACIntStatus(EMAC0_BASE, false));

  /* Enable the Ethernet MAC transmitter and receiver. */
  EMACTxEnable(EMAC0_BASE);
  EMACRxEnable(EMAC0_BASE);

  /* Enable the Ethernet RX and TX interrupt source. */
  EMACIntEnable(EMAC0_BASE, (EMAC_INT_RECEIVE | EMAC_INT_TRANSMIT |
                EMAC_INT_TX_STOPPED | EMAC_INT_RX_NO_BUFFER |
                EMAC_INT_RX_STOPPED | EMAC_INT_PHY));

  /* Enable the Ethernet interrupt. */
  IntEnable(INT_EMAC0);

  /* Enable all processor interrupts. */
  IntMasterEnable();

  /* Tell the PHY to start an auto-negotiation cycle. */
  EMACPHYWrite(EMAC0_BASE, PHY_PHYS_ADDR, EPHY_BMCR, (EPHY_BMCR_ANEN |
               EPHY_BMCR_RESTARTAN));
}

#ifdef DEBUG
/**
 * Dump the chain of pbuf pointers to the debug output.
 */
void
tivaif_trace_pbuf(const char *pcTitle, struct pbuf *p)
{
    LWIP_DEBUGF(NETIF_DEBUG, ("%s %08x (%d, %d)", pcTitle, p, p->tot_len,
                p->len));

    do
    {
        p = p->next;
        if(p)
        {
            LWIP_DEBUGF(NETIF_DEBUG, ("->%08x(%d)", p, p->len));
        }
        else
        {
            LWIP_DEBUGF(NETIF_DEBUG, ("->%08x", p));
        }

    } while((p != NULL) && (p->tot_len != p->len));

    LWIP_DEBUGF(NETIF_DEBUG, ("\n"));
}
#endif

/**
 * This function is used to check whether a passed pbuf contains only buffers
 * resident in regions of memory that the Ethernet MAC can access.  If any
 * buffers in the chain are outside a directly-DMAable section of memory,
 * the pbuf is copied to SRAM and a different pointer returned.  If all
 * buffers are safe, the pbuf reference count is incremented and the original
 * pointer returned.
 */
static struct pbuf *
tivaif_check_pbuf(struct pbuf *p)
{
    struct pbuf *pBuf;
    err_t Err;

    pBuf = p;

#ifdef DEBUG
    tivaif_trace_pbuf("Original:", p);
#endif

    /* Walk the list of buffers in the pbuf checking each. */
    do
    {
        /* Does this pbuf's payload reside in memory that the Ethernet DMA
         * can access?
         */
        if(!PTR_SAFE_FOR_EMAC_DMA(pBuf->payload))
        {
            /* This buffer is outside the DMA-able memory space so we need
             * to copy the pbuf.
             */
            pBuf = pbuf_alloc(PBUF_RAW, p->tot_len, PBUF_POOL);

            /* If we got a new pbuf... */
            if(pBuf)
            {
                /* ...copy the old pbuf into the new one. */
                Err = pbuf_copy(pBuf, p);

                /* If we failed to copy the pbuf, free the newly allocated one
                 * and make sure we return a NULL to show a problem.
                 */
                if(Err != ERR_OK)
                {
                    DRIVER_STATS_INC(TXCopyFailCount);
                    pbuf_free(pBuf);
                    pBuf = NULL;
                }
                else
                {
#ifdef DEBUG
                    tivaif_trace_pbuf("Copied:", pBuf);
#endif
                    DRIVER_STATS_INC(TXCopyCount);

                    /* Reduce the reference count on the original pbuf since
                     * we're not going to hold on to it after returning from
                     * tivaif_transmit.  Note that we already bumped
                     * the reference count at the top of tivaif_transmit.
                     */
                    pbuf_free(p);
                }
            }

            /* Send back the new pbuf pointer or NULL if an error occurred. */
            return(pBuf);
        }

        /* Move on to the next buffer in the queue */
        pBuf = pBuf->next;
    }
    while(pBuf);

    /**
     * If we get here, the passed pbuf can be safely used without needing to
     * be copied.
     */
    return(p);
}

/**
 * This function should do the actual transmission of the packet. The packet is
 * contained in the pbuf that is passed to the function. This pbuf might be
 * chained.
 *
 * @param psNetif the lwip network interface structure for this ethernetif
 * @param p the MAC packet to send (e.g. IP packet including MAC addresses and type)
 * @return ERR_OK if the packet coui32d be sent
 *         an err_t value if the packet coui32dn't be sent
 */
static err_t
tivaif_transmit(struct netif *psNetif, struct pbuf *p)
{
  tStellarisIF *pIF;
  tDescriptor *pDesc;
  struct pbuf *pBuf;
  uint32_t ui32NumChained, ui32NumDescs;
  bool bFirst;
  SYS_ARCH_DECL_PROTECT(lev);

  LWIP_DEBUGF(NETIF_DEBUG, ("tivaif_transmit 0x%08x, len %d\n", p,
              p->tot_len));

  /**
   * This entire function must run within a "critical section" to preserve
   * the integrity of the transmit pbuf queue.
   */
  SYS_ARCH_PROTECT(lev);

  /* Update our transmit attempt counter. */
  DRIVER_STATS_INC(TXCount);

  /**
   * Increase the reference count on the packet provided so that we can
   * hold on to it until we are finished transmitting its content.
   */
  pbuf_ref(p);

  /**
   * Determine whether all buffers passed are within SRAM and, if not, copy
   * the pbuf into SRAM-resident buffers so that the Ethernet DMA can access
   * the data.
   */
  p = tivaif_check_pbuf(p);

  /* Make sure we still have a valid buffer (it may have been copied) */
  if(!p)
  {
      LINK_STATS_INC(link.memerr);
      SYS_ARCH_UNPROTECT(lev);
      return(ERR_MEM);
  }

  /* Get our state data from the netif structure we were passed. */
  pIF = (tStellarisIF *)psNetif->state;

  /* Make sure that the transmit descriptors are not all in use */
  pDesc = &(pIF->pTxDescList->pDescriptors[pIF->pTxDescList->ui32Write]);
  if(pDesc->pBuf)
  {
      /**
       * The current write descriptor has a pbuf attached to it so this
       * implies that the ring is fui32l. Reject this transmit request with a
       * memory error since we can't satisfy it just now.
       */
      pbuf_free(p);
      LINK_STATS_INC(link.memerr);
      DRIVER_STATS_INC(TXNoDescCount);
      SYS_ARCH_UNPROTECT(lev);
      return (ERR_MEM);
  }

  /* How many pbufs are in the chain passed? */
  ui32NumChained = (uint32_t)pbuf_clen(p);

  /* How many free transmit descriptors do we have? */
  ui32NumDescs = (pIF->pTxDescList->ui32Read > pIF->pTxDescList->ui32Write) ?
          (pIF->pTxDescList->ui32Read - pIF->pTxDescList->ui32Write) :
          ((NUM_TX_DESCRIPTORS - pIF->pTxDescList->ui32Write) +
           pIF->pTxDescList->ui32Read);

  /* Do we have enough free descriptors to send the whole packet? */
  if(ui32NumDescs < ui32NumChained)
  {
      /* No - we can't transmit this whole packet so return an error. */
      pbuf_free(p);
      LINK_STATS_INC(link.memerr);
      DRIVER_STATS_INC(TXNoDescCount);
      SYS_ARCH_UNPROTECT(lev);
      return (ERR_MEM);
  }

  /* Tag the first descriptor as the start of the packet. */
  bFirst = true;
  pDesc->Desc.ui32CtrlStatus = DES0_TX_CTRL_FIRST_SEG;

  /* Here, we know we can send the packet so write it to the descriptors */
  pBuf = p;

  while(ui32NumChained)
  {
      /* Get a pointer to the descriptor we will write next. */
      pDesc = &(pIF->pTxDescList->pDescriptors[pIF->pTxDescList->ui32Write]);

      /* Fill in the buffer pointer and length */
      pDesc->Desc.ui32Count = (uint32_t)pBuf->len;
      pDesc->Desc.pvBuffer1 = pBuf->payload;

      /* Tag the first descriptor as the start of the packet. */
      if(bFirst)
      {
          bFirst = false;
          pDesc->Desc.ui32CtrlStatus = DES0_TX_CTRL_FIRST_SEG;
      }
      else
      {
          pDesc->Desc.ui32CtrlStatus = 0;
      }

      pDesc->Desc.ui32CtrlStatus |= (DES0_TX_CTRL_IP_ALL_CKHSUMS |
                                     DES0_TX_CTRL_CHAINED);

      /* Decrement our descriptor counter, move on to the next buffer in the
       * pbuf chain. */
      ui32NumChained--;
      pBuf = pBuf->next;

      /* Update the descriptor list write index. */
      pIF->pTxDescList->ui32Write++;
      if(pIF->pTxDescList->ui32Write == NUM_TX_DESCRIPTORS)
      {
          pIF->pTxDescList->ui32Write = 0;
      }

      /* If this is the last descriptor, mark it as the end of the packet. */
      if(!ui32NumChained)
      {
          pDesc->Desc.ui32CtrlStatus |= (DES0_TX_CTRL_LAST_SEG |
                                         DES0_TX_CTRL_INTERRUPT);

          /* Tag the descriptor with the original pbuf pointer. */
          pDesc->pBuf = p;
      }
      else
      {
          /* Set the lsb of the pbuf pointer.  We use this as a signal that
           * we should not free the pbuf when we are walking the descriptor
           * list while processing the transmit interrupt.  We only free the
           * pbuf when processing the last descriptor used to transmit its
           * chain.
           */
          pDesc->pBuf = (struct pbuf *)((uint32_t)p + 1);
      }

      DRIVER_STATS_INC(TXBufQueuedCount);

      /* Hand the descriptor over to the hardware. */
      pDesc->Desc.ui32CtrlStatus |= DES0_TX_CTRL_OWN;
  }

  /* Tell the transmitter to start (in case it had stopped). */
  EMACTxDMAPollDemand(EMAC0_BASE);

  /* Update lwIP statistics */
  LINK_STATS_INC(link.xmit);

  SYS_ARCH_UNPROTECT(lev);

  return(ERR_OK);
}

/**
 * This function will process all transmit descriptors and free pbufs attached
 * to any that have been transmitted since we last checked.
 *
 * This function is called only from the Ethernet interrupt handler.
 *
 * @param netif the lwip network interface structure for this ethernetif
 * @return None.
 */
static void
tivaif_process_transmit(tStellarisIF *pIF)
{
    tDescriptorList *pDescList;
    uint32_t ui32NumDescs;

    /* Get a pointer to the transmit descriptor list. */
    pDescList = pIF->pTxDescList;

    /* Walk the list until we have checked all descriptors or we reach the
     * write pointer or find a descriptor that the hardware is still working
     * on.
     */
    for(ui32NumDescs = 0; ui32NumDescs < pDescList->ui32NumDescs; ui32NumDescs++)
    {
        /* Has the buffer attached to this descriptor been transmitted? */
        if(pDescList->pDescriptors[pDescList->ui32Read].Desc.ui32CtrlStatus &
           DES0_TX_CTRL_OWN)
        {
            /* No - we're finished. */
            break;
        }

        /* Does this descriptor have a buffer attached to it? */
        if(pDescList->pDescriptors[pDescList->ui32Read].pBuf)
        {
            /* Yes - free it if it's not marked as an intermediate pbuf */
            if(!((uint32_t)(pDescList->pDescriptors[pDescList->ui32Read].pBuf) & 1))
            {
                pbuf_free(pDescList->pDescriptors[pDescList->ui32Read].pBuf);
                DRIVER_STATS_INC(TXBufFreedCount);
            }
            pDescList->pDescriptors[pDescList->ui32Read].pBuf = NULL;
        }
        else
        {
            /* If the descriptor has no buffer, we are finished. */
            break;
        }

        /* Move on to the next descriptor. */
        pDescList->ui32Read++;
        if(pDescList->ui32Read == pDescList->ui32NumDescs)
        {
            pDescList->ui32Read = 0;
        }
    }
}

/**
 * This function will process all receive descriptors that contain newly read
 * data and pass complete frames up the lwIP stack as they are found.  The
 * timestamp of the packet will be placed into the pbuf structure if PTPD is
 * enabled.
 *
 * This function is called only from the Ethernet interrupt handler.
 *
 * @param psNetif the lwip network interface structure for this ethernetif
 * @return None.
 */
static void
tivaif_receive(struct netif *psNetif)
{
  tDescriptorList *pDescList;
  tStellarisIF *pIF;
  struct pbuf *pBuf;
  uint32_t ui32DescEnd;

  /* Get a pointer to our state data */
  pIF = (tStellarisIF *)(psNetif->state);

  /* Get a pointer to the receive descriptor list. */
  pDescList = pIF->pRxDescList;

  /* Start with a NULL pbuf so that we don't try to link chain the first
   * time round.
   */
  pBuf = NULL;

  /* Determine where we start and end our walk of the descriptor list */
   ui32DescEnd = pDescList->ui32Read ? (pDescList->ui32Read - 1) : (pDescList->ui32NumDescs - 1);

  /* Step through the descriptors that are marked for CPU attention. */
  while(pDescList->ui32Read != ui32DescEnd)
  {
      /* Does the current descriptor have a buffer attached to it? */
      if(pDescList->pDescriptors[pDescList->ui32Read].pBuf)
      {
          /* Yes - determine if the host has filled it yet. */
          if(pDescList->pDescriptors[pDescList->ui32Read].Desc.ui32CtrlStatus &
             DES0_RX_CTRL_OWN)
          {
              /* The DMA engine still owns the descriptor so we are finished */
              break;
          }

          DRIVER_STATS_INC(RXBufReadCount);

          /* If this descriptor contains the end of the packet, fix up the
           * buffer size accordingly.
           */
          if(pDescList->pDescriptors[pDescList->ui32Read].Desc.ui32CtrlStatus &
             DES0_RX_STAT_LAST_DESC)
          {
              /* This is the last descriptor for the frame so fix up the
               * length.  It is safe for us to modify the internal fields
               * directly here (rather than calling pbuf_realloc) since we
               * know each of these pbufs is never chained.
               */
              pDescList->pDescriptors[pDescList->ui32Read].pBuf->len =
                       (pDescList->pDescriptors[pDescList->ui32Read].Desc.ui32CtrlStatus &
                        DES0_RX_STAT_FRAME_LENGTH_M) >>
                        DES0_RX_STAT_FRAME_LENGTH_S;
              pDescList->pDescriptors[pDescList->ui32Read].pBuf->tot_len =
                        pDescList->pDescriptors[pDescList->ui32Read].pBuf->len;
          }

          if(pBuf)
          {
              /* Link this pbuf to the last one we looked at since this buffer
               * is a continuation of an existing frame (split across mui32tiple
               * pbufs).  Note that we use pbuf_cat() here rather than
               * pbuf_chain() since we don't want to increase the reference
               * count of either pbuf - we only want to link them together.
               */
              pbuf_cat(pBuf, pDescList->pDescriptors[pDescList->ui32Read].pBuf);
              pDescList->pDescriptors[pDescList->ui32Read].pBuf = pBuf;
          }

          /* Remember the buffer associated with this descriptor. */
          pBuf = pDescList->pDescriptors[pDescList->ui32Read].pBuf;

          /* Is this the last descriptor for the current frame? */
          if(pDescList->pDescriptors[pDescList->ui32Read].Desc.ui32CtrlStatus &
             DES0_RX_STAT_LAST_DESC)
          {
              /* Yes - does the frame contain errors? */
              if(pDescList->pDescriptors[pDescList->ui32Read].Desc.ui32CtrlStatus &
                 DES0_RX_STAT_ERR)
              {
                  /* This is a bad frame so discard it and update the relevant
                   * statistics.
                   */
                  LWIP_DEBUGF(NETIF_DEBUG, ("tivaif_receive: packet error\n"));
                  pbuf_free(pBuf);
                  LINK_STATS_INC(link.drop);
                  DRIVER_STATS_INC(RXPacketErrCount);
              }
              else
              {
                  /* This is a good frame so pass it up the stack. */
                  LINK_STATS_INC(link.recv);
                  DRIVER_STATS_INC(RXPacketReadCount);

#if LWIP_PTPD
                  /* Place the timestamp in the PBUF if PTPD is enabled */
                  pBuf->time_s =
                       pDescList->pDescriptors[pDescList->ui32Read].Desc.ui32IEEE1588TimeHi;
                  pBuf->time_ns =
                       pDescList->pDescriptors[pDescList->ui32Read].Desc.ui32IEEE1588TimeLo;
#endif

#if NO_SYS
                  if(ethernet_input(pBuf, psNetif) != ERR_OK)
                  {
#else
                  if(tcpip_input(pBuf, psNetif) != ERR_OK)
                  {
#endif
                      /* drop the packet */
                      LWIP_DEBUGF(NETIF_DEBUG, ("tivaif_input: input error\n"));
                      pbuf_free(pBuf);

                      /* Adjust the link statistics */
                      LINK_STATS_INC(link.memerr);
                      LINK_STATS_INC(link.drop);
                      DRIVER_STATS_INC(RXPacketCBErrCount);
                  }

                  /* We're finished with this packet so make sure we don't try
                   * to link the next buffer to it.
                   */
                  pBuf = NULL;
              }
          }
      }

      /* Allocate a new buffer for this descriptor */
      pDescList->pDescriptors[pDescList->ui32Read].pBuf = pbuf_alloc(PBUF_RAW,
                                                        PBUF_POOL_BUFSIZE,
                                                        PBUF_POOL);
      pDescList->pDescriptors[pDescList->ui32Read].Desc.ui32Count =
                                                        DES1_RX_CTRL_CHAINED;
      if(pDescList->pDescriptors[pDescList->ui32Read].pBuf)
      {
          /* We got a buffer so fill in the payload pointer and size. */
          pDescList->pDescriptors[pDescList->ui32Read].Desc.pvBuffer1 =
                              pDescList->pDescriptors[pDescList->ui32Read].pBuf->payload;
          pDescList->pDescriptors[pDescList->ui32Read].Desc.ui32Count |=
                              (pDescList->pDescriptors[pDescList->ui32Read].pBuf->len <<
                               DES1_RX_CTRL_BUFF1_SIZE_S);

          /* Give this descriptor back to the hardware */
          pDescList->pDescriptors[pDescList->ui32Read].Desc.ui32CtrlStatus =
                              DES0_RX_CTRL_OWN;
      }
      else
      {
          LWIP_DEBUGF(NETIF_DEBUG, ("tivaif_receive: pbuf_alloc error\n"));

          pDescList->pDescriptors[pDescList->ui32Read].Desc.pvBuffer1 = 0;

          /* Update the stats to show we coui32dn't allocate a pbuf. */
          DRIVER_STATS_INC(RXNoBufCount);
          LINK_STATS_INC(link.memerr);

          /* Stop parsing here since we can't leave a broken descriptor in
           * the chain.
           */
          break;
      }

      /* Move on to the next descriptor in the chain, taking care to wrap. */
      pDescList->ui32Read++;
      if(pDescList->ui32Read == pDescList->ui32NumDescs)
      {
          pDescList->ui32Read = 0;
      }
  }
}

/**
 * should be called at the beginning of the program to set up the
 * network interface. It calls the function tivaif_hwinit() to do the
 * actual setup of the hardware.
 *
 * This function should be passed as a parameter to netif_add().
 *
 * @param psNetif the lwip network interface structure for this ethernetif
 * @return ERR_OK if the loopif is initialized
 *         ERR_MEM if private data coui32dn't be allocated
 *         any other err_t on error
 */
err_t
tivaif_init(struct netif *psNetif)
{

  LWIP_ASSERT("psNetif != NULL", (psNetif != NULL));

#if LWIP_NETIF_HOSTNAME
  /* Initialize interface hostname */
  psNetif->hostname = "lwip";
#endif /* LWIP_NETIF_HOSTNAME */

  /*
   * Initialize the snmp variables and counters inside the struct netif.
   * The last argument should be replaced with your link speed, in units
   * of bits per second.
   */
  NETIF_INIT_SNMP(psNetif, snmp_ifType_ethernet_csmacd, 1000000);

  psNetif->state = &g_StellarisIFData;
  psNetif->name[0] = IFNAME0;
  psNetif->name[1] = IFNAME1;
  /* We directly use etharp_output() here to save a function call.
   * You can instead declare your own function an call etharp_output()
   * from it if you have to do some checks before sending (e.g. if link
   * is available...) */
  psNetif->output = etharp_output;
  psNetif->linkoutput = tivaif_transmit;

  /* Remember our MAC address. */
  g_StellarisIFData.ethaddr = (struct eth_addr *)&(psNetif->hwaddr[0]);

  /* Initialize the hardware */
  tivaif_hwinit(psNetif);

  return ERR_OK;
}

/**
 * Process interrupts from the PHY.
 *
 * should be called from the Stellaris Ethernet Interrupt Handler.  This
 * function will read packets from the Stellaris Ethernet fifo and place them
 * into a pbuf queue.  If the transmitter is idle and there is at least one packet
 * on the transmit queue, it will place it in the transmit fifo and start the
 * transmitter.
 *
 */
void
tivaif_process_phy_interrupt(struct netif *psNetif)
{
    uint16_t ui16Val, ui16Status;
    uint32_t ui32Config, ui32Mode, ui32RxMaxFrameSize;

    /* Read the PHY interrupt status.  This clears all interrupt sources.
     * Note that we are only enabling sources in EPHY_MISR1 so we don't
     * read EPHY_MISR2.
     */
    ui16Val = EMACPHYRead(EMAC0_BASE, PHY_PHYS_ADDR, EPHY_MISR1);

    /* Read the current PHY status. */
    ui16Status = EMACPHYRead(EMAC0_BASE, PHY_PHYS_ADDR, EPHY_STS);

    /* Has the link status changed? */
    if(ui16Val & EPHY_MISR1_LINKSTAT)
    {
        /* Is link up or down now? */
        if(ui16Status & EPHY_STS_LINK)
        {
            /* Tell lwIP the link is up. */
#if NO_SYS
            netif_set_link_up(psNetif);
#else
            tcpip_callback((tcpip_callback_fn)netif_set_link_up, psNetif);
#endif

            /* In this case we drop through since we may need to reconfigure
             * the MAC depending upon the speed and half/fui32l-duplex settings.
             */
        }
        else
        {
            /* Tell lwIP the link is down */
#if NO_SYS
            netif_set_link_down(psNetif);
#else
            tcpip_callback((tcpip_callback_fn)netif_set_link_down, psNetif);
#endif
        }
    }

    /* Has the speed or duplex status changed? */
    if(ui16Val & (EPHY_MISR1_SPEED | EPHY_MISR1_SPEED | EPHY_MISR1_ANC))
    {
        /* Get the current MAC configuration. */
        EMACConfigGet(EMAC0_BASE, &ui32Config, &ui32Mode,
                        &ui32RxMaxFrameSize);

        /* What speed is the interface running at now?
         */
        if(ui16Status & EPHY_STS_SPEED)
        {
            /* 10Mbps is selected */
            ui32Config &= ~EMAC_CONFIG_100MBPS;
        }
        else
        {
            /* 100Mbps is selected */
            ui32Config |= EMAC_CONFIG_100MBPS;
        }

        /* Are we in fui32l- or half-duplex mode? */
        if(ui16Status & EPHY_STS_DUPLEX)
        {
            /* Fui32l duplex. */
            ui32Config |= EMAC_CONFIG_FULL_DUPLEX;
        }
        else
        {
            /* Half duplex. */
            ui32Config &= ~EMAC_CONFIG_FULL_DUPLEX;
        }

        /* Reconfigure the MAC */
        EMACConfigSet(EMAC0_BASE, ui32Config, ui32Mode, ui32RxMaxFrameSize);
    }
}

/**
 * Process tx and rx packets at the low-level interrupt.
 *
 * should be called from the Stellaris Ethernet Interrupt Handler.  This
 * function will read packets from the Stellaris Ethernet fifo and place them
 * into a pbuf queue.  If the transmitter is idle and there is at least one packet
 * on the transmit queue, it will place it in the transmit fifo and start the
 * transmitter.
 *
 */
void
tivaif_interrupt(struct netif *psNetif, uint32_t ui32Status)
{
  tStellarisIF *tivaif;

  /* setup pointer to the if state data */
  tivaif = psNetif->state;

  /* Update our debug interrupt counters. */
  if(ui32Status & EMAC_INT_NORMAL_INT)
  {
      g_ui32NormalInts++;
  }

  if(ui32Status & EMAC_INT_ABNORMAL_INT)
  {
      g_ui32AbnormalInts++;
  }

  /* Is this an interrupt from the PHY? */
  if(ui32Status & EMAC_INT_PHY)
  {
      tivaif_process_phy_interrupt(psNetif);
  }

  /* Process the transmit DMA list, freeing any buffers that have been
   * transmitted since our last interrupt.
   */
  if(ui32Status & EMAC_INT_TRANSMIT)
  {
      tivaif_process_transmit(tivaif);
  }

  /**
   * Process the receive DMA list and pass all successfui32ly received packets
   * up the stack.  We also call this function in cases where the receiver has
   * stalled due to missing buffers since the receive function will attempt to
   * allocate new pbufs for descriptor entries which have none.
   */
  if(ui32Status & (EMAC_INT_RECEIVE | EMAC_INT_RX_NO_BUFFER |
     EMAC_INT_RX_STOPPED))
  {
      tivaif_receive(psNetif);
  }
}

#if NETIF_DEBUG
/* Print an IP header by using LWIP_DEBUGF
 * @param p an IP packet, p->payload pointing to the IP header
 */
void
tivaif_debug_print(struct pbuf *p)
{
  struct eth_hdr *ethhdr = (struct eth_hdr *)p->payload;
  u16_t *plen = (u16_t *)p->payload;

  LWIP_DEBUGF(NETIF_DEBUG, ("ETH header:\n"));
  LWIP_DEBUGF(NETIF_DEBUG, ("Packet Length:%5"U16_F" \n",*plen));
  LWIP_DEBUGF(NETIF_DEBUG, ("Destination: %02"X8_F"-%02"X8_F"-%02"X8_F"-%02"X8_F"-%02"X8_F"-%02"X8_F"\n",
    ethhdr->dest.addr[0],
    ethhdr->dest.addr[1],
    ethhdr->dest.addr[2],
    ethhdr->dest.addr[3],
    ethhdr->dest.addr[4],
    ethhdr->dest.addr[5]));
  LWIP_DEBUGF(NETIF_DEBUG, ("Source: %02"X8_F"-%02"X8_F"-%02"X8_F"-%02"X8_F"-%02"X8_F"-%02"X8_F"\n",
    ethhdr->src.addr[0],
    ethhdr->src.addr[1],
    ethhdr->src.addr[2],
    ethhdr->src.addr[3],
    ethhdr->src.addr[4],
    ethhdr->src.addr[5]));
  LWIP_DEBUGF(NETIF_DEBUG, ("Packet Type:0x%04"U16_F" \n", ethhdr->type));
}
#endif /* NETIF_DEBUG */
