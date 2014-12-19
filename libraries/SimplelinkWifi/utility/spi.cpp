
/*****************************************************************************
*
*  spi.c - CC3000 Host Driver Implementation.
*  Copyright (C) 2011 Texas Instruments Incorporated - http://www.ti.com/
*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions
*  are met:
*
*    Redistributions of source code must retain the above copyright
*    notice, this list of conditions and the following disclaimer.
*
*    Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in the
*    documentation and/or other materials provided with the   
*    distribution.
*
*    Neither the name of Texas Instruments Incorporated nor the names of
*    its contributors may be used to endorse or promote products derived
*    from this software without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
*  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
*  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*****************************************************************************/

//*****************************************************************************
//
//! \addtogroup link_buff_api
//! @{
//
//*****************************************************************************
#include "SPI.h"
#include "hci.h"
#include "interface.h"

#include "evnt_handler.h"
#include "board.h"


#define READ                    3
#define WRITE                   1

#define HI(value)               (((value) & 0xFF00) >> 8)
#define LO(value)               ((value) & 0x00FF)


#define ASSERT_CS()          digitalWrite(CSpin, LOW);//CSpin low

#define DEASSERT_CS()        digitalWrite(CSpin, HIGH);//CSpin high

#define HEADERS_SIZE_EVNT       (SPI_HEADER_SIZE + 5)

#define SPI_HEADER_SIZE			(5)

#define 	eSPI_STATE_POWERUP 				 (0)
#define 	eSPI_STATE_INITIALIZED  		 (1)
#define 	eSPI_STATE_IDLE					 (2)
#define 	eSPI_STATE_WRITE_IRQ	   		 (3)
#define 	eSPI_STATE_WRITE_FIRST_PORTION   (4)
#define 	eSPI_STATE_WRITE_EOT			 (5)
#define 	eSPI_STATE_READ_IRQ				 (6)
#define 	eSPI_STATE_READ_FIRST_PORTION	 (7)
#define 	eSPI_STATE_READ_EOT				 (8)


typedef struct
{
	gcSpiHandleRx  SPIRxHandler;
	unsigned short usTxPacketLength;
	unsigned short usRxPacketLength;
	unsigned long  ulSpiState;
	unsigned char *pTxPacket;
	unsigned char *pRxPacket;

}tSpiInformation;


tSpiInformation sSpiInformation;


// buffer for 5 bytes of SPI HEADER
unsigned char tSpiReadHeader[] = {READ, 0, 0, 0, 0};
uint8_t CSpin=18;
uint8_t ENpin=2;
uint8_t IRQpin=19;

void SpiWriteDataSynchronous(unsigned char *data, unsigned short size);
void SpiWriteAsync(const unsigned char *data, unsigned short size);
void SpiPauseSpi(void);
void SpiResumeSpi(void);
void SSIContReadOperation(void);

// The magic number that resides at the end of the TX/RX buffer (1 byte after
// the allocated size) for the purpose of detection of the overrun. The location
// of the memory where the magic number resides shall never be written. In case 
// it is written - the overrun occurred and either receive function or send
// function will stuck forever.
#define CC3000_BUFFER_MAGIC_NUMBER (0xDE)

///////////////////////////////////////////////////////////////////////////////////////////////////////////
//#pragma is used for determine the memory location for a specific variable.                            ///       
//__no_init is used to prevent the buffer initialization in order to prevent hardware WDT expiration    ///
// before entering to 'main()'.                                                                         ///
//for every IDE, different syntax exists :          1.   __CCS__ for CCS v5                             ///
//                                                  2.  __IAR_SYSTEMS_ICC__ for IAR Embedded Workbench  ///
// *CCS does not initialize variables - therefore, __no_init is not needed.                             ///
///////////////////////////////////////////////////////////////////////////////////////////////////////////

//#pragma DATA_SECTION(spi_buffer, ".FRAM_DATA")
char spi_buffer[CC3000_RX_BUFFER_SIZE];
//#pragma DATA_SECTION(wlan_tx_buffer, ".FRAM_DATA")
unsigned char wlan_tx_buffer[CC3000_TX_BUFFER_SIZE];

char deassert_cs=0;
//*****************************************************************************
//
//!  SpiClose
//!
//!  @param  none
//!
//!  @return none
//!
//!  @brief  Close Spi interface
//
//*****************************************************************************
void
SpiClose(void)
{
	if (sSpiInformation.pRxPacket)
	{
		sSpiInformation.pRxPacket = 0;
	}
	
	//	Disable Interrupt in GPIOA module...
	tSLInformation.WlanInterruptDisable();
}


//*****************************************************************************
//
//!  SpiOpen
//!
//!  @param  none
//!
//!  @return none
//!
//!  @brief  Open Spi interface 
//
//*****************************************************************************
void 
SpiOpen(gcSpiHandleRx pfRxHandler)
{
	sSpiInformation.ulSpiState = eSPI_STATE_POWERUP;
	//add by 07/18
	//memset(spi_buffer, 0, sizeof(spi_buffer));
    //memset(wlan_tx_buffer, 0, sizeof(spi_buffer));
	//end
	sSpiInformation.SPIRxHandler = pfRxHandler;
	sSpiInformation.usTxPacketLength = 0;
	sSpiInformation.pTxPacket = NULL;
	sSpiInformation.pRxPacket = (unsigned char *)spi_buffer;
	sSpiInformation.usRxPacketLength = 0;
	spi_buffer[CC3000_RX_BUFFER_SIZE - 1] = CC3000_BUFFER_MAGIC_NUMBER;
	wlan_tx_buffer[CC3000_TX_BUFFER_SIZE - 1] = CC3000_BUFFER_MAGIC_NUMBER;
	
	// Enable interrupt on the GPIOA pin of WLAN IRQ
	tSLInformation.WlanInterruptEnable();
	//attachInterrupt(P2_3, IntSpiGPIOHandler, FALLING);
}

//*****************************************************************************
//
//!  init_spi
//!
//!  @param  none
//!
//!  @return none
//!
//!  @brief  initializes an SPI interface
//
//*****************************************************************************

int init_spi(void)
{


	SPI.begin();
	DEASSERT_CS();
	SPI.setBitOrder(MSBFIRST);
	SPI.setDataMode(SPI_MODE1);

	return(ESUCCESS);
	
}

//*****************************************************************************
//
//! SpiFirstWrite
//!
//!  @param  ucBuf     buffer to write
//!  @param  usLength  buffer's length
//!
//!  @return none
//!
//!  @brief  enter point for first write flow
//
//*****************************************************************************
long
SpiFirstWrite(unsigned char *ucBuf, unsigned short usLength)
{
	// workaround for first transaction
	ASSERT_CS();
	
	// Assuming we are running on 24 MHz ~50 micro delay is 1200 cycles;
	delayMicroseconds(50);
	
	// SPI writes first 4 bytes of data
	SpiWriteDataSynchronous(ucBuf, 4);
	
	delayMicroseconds(50);
	
	SpiWriteDataSynchronous(ucBuf + 4, usLength - 4);
	
	// From this point on - operate in a regular way
	sSpiInformation.ulSpiState = eSPI_STATE_IDLE;
	
	DEASSERT_CS();
	
	return(0);
}


//*****************************************************************************
//
//!  SpiWrite
//!
//!  @param  pUserBuffer  buffer to write
//!  @param  usLength     buffer's length
//!
//!  @return none
//!
//!  @brief  Spi write operation
//
//*****************************************************************************
long
SpiWrite(unsigned char *pUserBuffer, unsigned short usLength)
{

	unsigned char ucPad = 0;


	// Figure out the total length of the packet in order to figure out if there 
	// is padding or not
	if(!(usLength & 0x0001))
	{
		ucPad++;
	}
	

	pUserBuffer[0] = WRITE;
	pUserBuffer[1] = HI(usLength + ucPad);
	pUserBuffer[2] = LO(usLength + ucPad);
	pUserBuffer[3] = 0;
	pUserBuffer[4] = 0;
	
	usLength += (SPI_HEADER_SIZE + ucPad);
	

	// The magic number that resides at the end of the TX/RX buffer (1 byte after 
	// the allocated size) for the purpose of detection of the overrun. If the 
	// magic number is overwritten - buffer overrun occurred - and we will stuck 
	// here forever!
	if (wlan_tx_buffer[CC3000_TX_BUFFER_SIZE - 1] != CC3000_BUFFER_MAGIC_NUMBER)
	{
	
		while (1)
			;
	}
	
	if (sSpiInformation.ulSpiState == eSPI_STATE_POWERUP)
	{
		while (sSpiInformation.ulSpiState != eSPI_STATE_INITIALIZED)
			;
	}
		

	if (sSpiInformation.ulSpiState == eSPI_STATE_INITIALIZED)
	{
		// This is time for first TX/RX transactions over SPI: the IRQ is down - 
		// so need to send read buffer size command
		SpiFirstWrite(pUserBuffer, usLength);
	}
	else 
	{
		// We need to prevent here race that can occur in case 2 back to back 
		// packets are sent to the  device, so the state will move to IDLE and once 
		//again to not IDLE due to IRQ
		tSLInformation.WlanInterruptDisable();
		
		while (sSpiInformation.ulSpiState != eSPI_STATE_IDLE)
		{
			;
		}
		
		sSpiInformation.ulSpiState = eSPI_STATE_WRITE_IRQ;
		sSpiInformation.pTxPacket = pUserBuffer;
		sSpiInformation.usTxPacketLength = usLength;
		
		// Assert the CS line and wait till SSI IRQ line is active and then
		// initialize write operation
		ASSERT_CS();
		
		// Re-enable IRQ - if it was not disabled - this is not a problem...
		tSLInformation.WlanInterruptEnable();

		// check for a missing interrupt between the CS assertion and enabling back the interrupts
		if (tSLInformation.ReadWlanInterruptPin() == 0)
		{
		
            SpiWriteDataSynchronous(sSpiInformation.pTxPacket, sSpiInformation.usTxPacketLength);
			sSpiInformation.ulSpiState = eSPI_STATE_IDLE;
			DEASSERT_CS();
		}
	}

	// Due to the fact that we are currently implementing a blocking situation
	// here we will wait till end of transaction
	while (eSPI_STATE_IDLE != sSpiInformation.ulSpiState)
		;

	return(0);
}

 
//*****************************************************************************
//
//!  SpiWriteDataSynchronous
//!
//!  @param  data  buffer to write
//!  @param  size  buffer's size
//!
//!  @return none
//!
//!  @brief  Spi write operation
//
//*****************************************************************************
void
SpiWriteDataSynchronous(unsigned char *data, unsigned short size)
{
	while (size)
	{
		SPI.transfer(*data);
		size --;
		data++;
	}
}

//*****************************************************************************
//
//! SpiReadDataSynchronous
//!
//!  @param  data  buffer to read
//!  @param  size  buffer's size
//!
//!  @return none
//!
//!  @brief  Spi read operation
//
//*****************************************************************************
void
SpiReadDataSynchronous(unsigned char *data, unsigned short size)
{
	long i = 0,j=0;
	unsigned char *data_to_send = tSpiReadHeader;
	
	for (i = 0; i < size; i ++)
	{

		data[i] = SPI.transfer(data_to_send[j]);
		if(j<5)j++;
	}
	
	
}


//*****************************************************************************
//
//!  SpiReadHeader
//!
//!  \param  buffer
//!
//!  \return none
//!
//!  \brief   This function enter point for read flow: first we read minimal 5 
//!	          SPI header bytes and 5 Event Data bytes
//
//*****************************************************************************
void
SpiReadHeader(void)
{
	SpiReadDataSynchronous(sSpiInformation.pRxPacket, 10);
}


//*****************************************************************************
//
//!  SpiReadDataCont
//!
//!  @param  None
//!
//!  @return None
//!
//!  @brief  This function processes received SPI Header and in accordance with 
//!	         it - continues reading the packet
//
//*****************************************************************************
long
SpiReadDataCont(void)
{
	long data_to_recv;
	unsigned char *evnt_buff, type;
	
	//determine what type of packet we have
	evnt_buff =  sSpiInformation.pRxPacket;
	data_to_recv = 0;
	STREAM_TO_UINT8((char *)(evnt_buff + SPI_HEADER_SIZE), HCI_PACKET_TYPE_OFFSET,
									type);
	
	switch(type)
	{
	case HCI_TYPE_DATA:
		{
			// We need to read the rest of data..
			STREAM_TO_UINT16((char *)(evnt_buff + SPI_HEADER_SIZE), 
											 HCI_DATA_LENGTH_OFFSET, data_to_recv);
			if (!((HEADERS_SIZE_EVNT + data_to_recv) & 1))
			{	
				data_to_recv++;
			}
			
			if (data_to_recv)
			{
				SpiReadDataSynchronous(evnt_buff + 10, data_to_recv);
			}
			break;
		}
	case HCI_TYPE_EVNT:
		{
			// Calculate the rest length of the data
			STREAM_TO_UINT8((char *)(evnt_buff + SPI_HEADER_SIZE), 
											HCI_EVENT_LENGTH_OFFSET, data_to_recv);
			data_to_recv -= 1;
			
			// Add padding byte if needed
			if ((HEADERS_SIZE_EVNT + data_to_recv) & 1)
			{
				
				data_to_recv++;
			}
			
			if (data_to_recv)
			{
				SpiReadDataSynchronous(evnt_buff + 10, data_to_recv);
			}
			
			sSpiInformation.ulSpiState = eSPI_STATE_READ_EOT;
			break;
		}
	}
	
	return (0);
}


//*****************************************************************************
//
//! SpiPauseSpi
//!
//!  @param  none
//!
//!  @return none
//!
//!  @brief  Spi pause operation
//
//*****************************************************************************

void 
SpiPauseSpi(void)
{

	//digitalWrite(P8_1,LOW);
	detachInterrupt(IRQpin);
	
	//SPI_IRQ_PORT &= ~SPI_IRQ_PIN;
}


//*****************************************************************************
//
//! SpiResumeSpi
//!
//!  @param  none
//!
//!  @return none
//!
//!  @brief  Spi resume operation
//
//*****************************************************************************

void 
SpiResumeSpi(void)
{
	tSLInformation.WlanInterruptEnable();
	//digitalWrite(P8_1,HIGH);
	//attachInterrupt(IRQpin, IntSpiGPIOHandler, FALLING);
	//if (! digitalRead(IRQpin))IntSpiGPIOHandler();
	//SPI_IRQ_PORT |= SPI_IRQ_PIN;
}


//*****************************************************************************
//
//! SpiTriggerRxProcessing
//!
//!  @param  none
//!
//!  @return none
//!
//!  @brief  Spi RX processing 
//
//*****************************************************************************
void 
SpiTriggerRxProcessing(void)
{
	
	// Trigger Rx processing
	SpiPauseSpi();
	DEASSERT_CS(); //8888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888
	
	// The magic number that resides at the end of the TX/RX buffer (1 byte after 
	// the allocated size) for the purpose of detection of the overrun. If the 
	// magic number is overwritten - buffer overrun occurred - and we will stuck 
	// here forever!
	if (sSpiInformation.pRxPacket[CC3000_RX_BUFFER_SIZE - 1] != CC3000_BUFFER_MAGIC_NUMBER)
	{
		while (1)
			;
	}
	
	sSpiInformation.ulSpiState = eSPI_STATE_IDLE;
	sSpiInformation.SPIRxHandler(sSpiInformation.pRxPacket + SPI_HEADER_SIZE);
	
}

//*****************************************************************************
// 
//!  IntSpiGPIOHandler
//! 
//!  @param  none
//! 
//!  @return none
//! 
//!  @brief  GPIO A interrupt handler. When the external SSI WLAN device is
//!          ready to interact with Host CPU it generates an interrupt signal.
//!          After that Host CPU has registered this interrupt request
//!          it set the corresponding /CS in active state.
// 
//*****************************************************************************

void IntSpiGPIOHandler(void)
{
	if (sSpiInformation.ulSpiState == eSPI_STATE_POWERUP)
	{
		//This means IRQ line was low call a callback of HCI Layer to inform 
		//on event 
		sSpiInformation.ulSpiState = eSPI_STATE_INITIALIZED;
	}
	else if (sSpiInformation.ulSpiState == eSPI_STATE_IDLE)
	{
		sSpiInformation.ulSpiState = eSPI_STATE_READ_IRQ;
		
		// IRQ line goes down - we are start reception 
		ASSERT_CS();
		
		// Wait for TX/RX Compete which will come as DMA interrupt
		SpiReadHeader();
		
		sSpiInformation.ulSpiState = eSPI_STATE_READ_EOT;
		
		SSIContReadOperation();
		
	}
	else if (sSpiInformation.ulSpiState == eSPI_STATE_WRITE_IRQ)
	{
		SpiWriteDataSynchronous(sSpiInformation.pTxPacket, 
														sSpiInformation.usTxPacketLength);
		
		sSpiInformation.ulSpiState = eSPI_STATE_IDLE;
		
		DEASSERT_CS();
	}
	
	//if(deassert_cs){DEASSERT_CS();deassert_cs=0;}

}


/*
#pragma vector=PORT2_VECTOR
__interrupt void IntSpiGPIOHandler(void)
{

	switch(P2IV)
	{
	case P2IV_P2IFG3:
		if (sSpiInformation.ulSpiState == eSPI_STATE_POWERUP)
		{
			//This means IRQ line was low call a callback of HCI Layer to inform 
			//on event 
	 		sSpiInformation.ulSpiState = eSPI_STATE_INITIALIZED;
		}
		else if (sSpiInformation.ulSpiState == eSPI_STATE_IDLE)
		{
			sSpiInformation.ulSpiState = eSPI_STATE_READ_IRQ;
			
			// IRQ line goes down - we are start reception 
			ASSERT_CS();
			
			// Wait for TX/RX Compete which will come as DMA interrupt
			SpiReadHeader();
			
			sSpiInformation.ulSpiState = eSPI_STATE_READ_EOT;
			
			SSIContReadOperation();
		}
		else if (sSpiInformation.ulSpiState == eSPI_STATE_WRITE_IRQ)
		{
			SpiWriteDataSynchronous(sSpiInformation.pTxPacket, 
															sSpiInformation.usTxPacketLength);
			
			sSpiInformation.ulSpiState = eSPI_STATE_IDLE;
			
			DEASSERT_CS();
		}
		break;
	default:
		break;
	}
	
}

*/
//*****************************************************************************
//
//! SSIContReadOperation
//!
//!  @param  none
//!
//!  @return none
//!
//!  @brief  SPI read operation
//
//*****************************************************************************

void
SSIContReadOperation(void)
{
	// The header was read - continue with  the payload read
	deassert_cs=0;
	if (!SpiReadDataCont())
	{
	deassert_cs=1;
		// All the data was read - finalize handling by switching to the task
		//	and calling from task Event Handler
		SpiTriggerRxProcessing();
	}
	
}




//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************
