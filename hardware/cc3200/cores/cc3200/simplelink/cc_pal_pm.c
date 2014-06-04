//*****************************************************************************
// ccc_pal_pm.c
//
// simplelink abstraction file for CC3200 (for power management framework)
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
//****************************************************************************


#include "datatypes.h"
#include "simplelink.h"
#include "cc_pal.h"
#include <hw_types.h>
#include <pin.h>
#include <hw_memmap.h>
#include "hw_mcspi.h"
#include <hw_common_reg.h>
#include <rom.h>
#include <rom_map.h>
#include <spi.h>
#include <prcm.h>
#include <hw_ints.h>
#include <interrupt.h>
#include <udma.h>
#include <utils.h>
#include <spi_drv.h>

P_EVENT_HANDLER g_pHostIntHdl  = NULL;

#define REG_INT_MASK_SET 0x400F7088
#define REG_INT_MASK_CLR 0x400F708C

#define APPS_SOFT_RESET_REG             0x4402D000
#define OCP_SHARED_MAC_RESET_REG        0x4402E168

#include <osi.h>

//******************************************************************************
// This defines the system Clock in Hz
//******************************************************************************

#define SYS_CLK 80000000


#define MAX_DMA_RECV_TRANSACTION_SIZE 4000
/*!
    \brief open spi communication port to be used for communicating with a SimpleLink device

	Given an interface name and option flags, this function opens the spi communication port
	and creates a file descriptor. This file descriptor can be used afterwards to read and
	write data from and to this specific spi channel.
	The SPI speed, clock polarity, clock phase, chip select and all other attributes are all
	set to hardcoded values in this function.

	\param	 		ifName		-	points to the interface name/path. The interface name is an
									optional attributes that the simple link driver receives
									on opening the device. in systems that the spi channel is
									not implemented as part of the os device drivers, this
									parameter could be NULL.
	\param			flags		-	option flags

	\return			upon successful completion, the function shall open the spi channel and return
					a non-negative integer representing the file descriptor.
					Otherwise, -1 shall be returned

    \sa             spi_Close , spi_Read , spi_Write
	\note
    \warning
*/
Fd_t spi_Open(char *ifName, unsigned long flags)
{
        void *lspi_hndl;
        lspi_hndl = spi_open(PRCM_LSPI);
        if(NULL == lspi_hndl) {
                return -1;
        } else {
                return (unsigned int)lspi_hndl;
        }
}

/*!
    \brief closes an opened spi communication port

	\param	 		fd			-	file descriptor of an opened SPI channel

	\return			upon successful completion, the function shall return 0.
					Otherwise, -1 shall be returned

    \sa             spi_Open
	\note
    \warning
*/
int spi_Close(Fd_t fd)
{
    spi_close((void *)fd);
    return 0;
}

/*!
    \brief attempts to read up to len bytes from SPI channel into a buffer starting at pBuff.

	\param			pBuff		- 	points to first location to start writing the data

	\param			len			-	number of bytes to read from the SPI channel

	\return			upon successful completion, the function shall return Read Size.
					Otherwise, -1 shall be returned

    \sa             spi_Read_CPU , spi_Write_CPU
	\note
    \warning
*/
int spi_Read(Fd_t fd, unsigned char *pBuff, int len)
{    
    int read_size = 0;
    if(fd < 0)
        return -1;

    while (len>0)
    {
        if( len < MAX_DMA_RECV_TRANSACTION_SIZE)
        {
                spi_read((void *)fd, (char *)&pBuff[read_size], len);
                read_size += len;
                len = 0;
        }
        else
        {
                spi_read((void *)fd, (char *)&pBuff[read_size], 
                        MAX_DMA_RECV_TRANSACTION_SIZE);
                read_size += MAX_DMA_RECV_TRANSACTION_SIZE;
                len -= MAX_DMA_RECV_TRANSACTION_SIZE;
        }
    }

    return read_size;
}

/*!
    \brief attempts to write up to len bytes to the SPI channel

	\param	 		fd			-	file descriptor of an opened SPI channel

	\param			pBuff		- 	points to first location to start getting the data from

	\param			len			-	number of bytes to write to the SPI channel

	\return			upon successful completion, the function shall return 0.
					Otherwise, -1 shall be returned

    \sa             spi_Open , spi_Read
	\note			This function could be implemented as zero copy and return only upon successful completion
					of writing the whole buffer, but in cases that memory allocation is not too tight, the
					function could copy the data to internal buffer, return back and complete the write in
					parallel to other activities as long as the other SPI activities would be blocked untill
					the entire buffer write would be completed
    \warning
*/
int spi_Write(Fd_t fd, unsigned char *pBuff, int len)
{
    int write_size = 0;

    if(fd < 0)
        return -1;

    write_size = spi_write((void *)fd, (const char *)pBuff, len);

    return write_size;
}



void HostIntHanlder()
{
    if(g_pHostIntHdl != NULL)
    {
        g_pHostIntHdl();
    }
    else
    {
        while(1)
        {

        }
    }
}
/*!
    \brief register an interrupt handler for the host IRQ

	\param	 		InterruptHdl	-	pointer to interrupt handler function

	\param 			pValue			-	pointer to a memory strcuture that is passed to the interrupt handler.

	\return			upon successful registration, the function shall return 0.
					Otherwise, -1 shall be returned

    \sa
	\note			If there is already registered interrupt handler, the function should overwrite the old handler
					with the new one
    \warning
*/

int NwpRegisterInterruptHandler(P_EVENT_HANDLER InterruptHdl , void* pValue)    //do not know what to do with pValue
{

    if(InterruptHdl == NULL)
    {
        //De-register Interprocessor communication interrupt between App and NWP
        IntDisable(INT_NWPIC);
        IntUnregister(INT_NWPIC);
        IntPendClear(INT_NWPIC);
        g_pHostIntHdl = NULL;
    }
    else
    {
          g_pHostIntHdl = InterruptHdl;
          #ifdef SL_PLATFORM_MULTI_THREADED
             osi_InterruptRegister(INT_NWPIC, (P_OSI_INTR_ENTRY)HostIntHanlder,
                                   (1<<5));
          #else             
              IntRegister(INT_NWPIC, HostIntHanlder);
              IntEnable(INT_NWPIC);
          #endif
    }

  return 0;
}


/*!
    \brief 				Masks host IRQ

					
    \sa             		NwpUnMaskInterrupt

    \warning        
*/
void NwpMaskInterrupt()
{
	(*(unsigned long *)REG_INT_MASK_SET) = 0x1;
}


/*!
    \brief 				Unmasks host IRQ

					
    \sa             		NwpMaskInterrupt

    \warning        
*/
void NwpUnMaskInterrupt()
{
	(*(unsigned long *)REG_INT_MASK_CLR) = 0x1;
}


void NwpPowerOn(void)
{

    PinModeSet(PIN_11,PIN_MODE_1);
    PinModeSet(PIN_12,PIN_MODE_1);
    PinModeSet(PIN_13,PIN_MODE_1);
    PinModeSet(PIN_14,PIN_MODE_1);

    MAP_PRCMPeripheralClkEnable(PRCM_SSPI, PRCM_RUN_MODE_CLK|PRCM_SLP_MODE_CLK);

#if CC3200_ES_1_2_1
    //SPI CLK GATING
    HWREG(0x440250C8) = 0;

    //WLAN PD ON
    HWREG(OCP_SHARED_MAC_RESET_REG) &= ~(0xC00);
    
    //Remove NWP Reset
    HWREG(APPS_SOFT_RESET_REG) &= ~4;
#else
    //bring the 1.32 eco out of reset
    HWREG(0x4402E16C) &= 0xFFFFFFFD;
#endif
    //UnMask Host Interrupt
    NwpUnMaskInterrupt();   
    
    //NWP Wakeup
    //PRCMNWPEnable();     
    HWREG(0x44025118) = 1;

}

void NwpPowerOff(void)
{
	//Must delay 300 usec to enable the NWP to finish all sl_stop activities
	UtilsDelay(300*80/3);

    //Mask Host Interrupt
    NwpMaskInterrupt();
    
    //Switch to PFM Mode
    HWREG(0x4402F024) &= 0xF7FFFFFF;
#if CC3200_ES_1_2_1
    //Reset NWP
    HWREG(APPS_SOFT_RESET_REG) |= 4; 
    //WLAN PD OFF
    HWREG(OCP_SHARED_MAC_RESET_REG) |= 0xC00;
#else
    //sl_stop eco for PG1.32 devices
    HWREG(0x4402E16C) |= 0x2;

    UtilsDelay(4000);
#endif
}

