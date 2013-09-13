/*****************************************************************************
*
*  board.c
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
#include "Energia.h"
#include <msp430.h>
#include "wlan.h" 
#include "evnt_handler.h"    // callback function declaration
#include "nvmem.h"
#include "socket.h"
#include "netapp.h"
#include "board.h"
#include "interface.h"



#define FIRST_TIME_CONFIG_SET 0xAA


extern unsigned char * ptrFtcAtStartup;

extern uint8_t CSpin;
extern uint8_t ENpin;
extern uint8_t IRQpin;
//*****************************************************************************
//
//! pio_init
//!
//! @param  none
//!
//! @return none
//!
//! @brief  Initialize the board's I/O
//
//*****************************************************************************    

void pio_init()
{

	
	//WLAN enable full DS
	pinMode(ENpin, OUTPUT);
	digitalWrite(ENpin, LOW);
	

	pinMode(IRQpin, INPUT);

	
	
	// Configure the SPI CS
	pinMode(CSpin, OUTPUT);
	digitalWrite(CSpin, HIGH);
	
	__delay_cycles(12000000);


	
}
//*****************************************************************************
//
//! ReadWlanInterruptPin
//!
//! @param  none
//!
//! @return none
//!
//! @brief  return wlan interrup pin
//
//*****************************************************************************

long ReadWlanInterruptPin(void)
{
	return digitalRead(IRQpin);
}

//*****************************************************************************
//
//! WlanInterruptEnable
//!
//! @param  none
//!
//! @return none
//!
//! @brief  Enable waln IrQ pin
//
//*****************************************************************************

void WlanInterruptEnable()
{

	//__bis_SR_register(GIE);
	//P2IES |= BIT3;
	//P2IE |= BIT3;
	//delay(500);
	//digitalWrite(P8_1,HIGH);
	attachInterrupt(IRQpin, IntSpiGPIOHandler, FALLING);
	if (!digitalRead(IRQpin))IntSpiGPIOHandler();
}

//*****************************************************************************
//
//! WlanInterruptDisable
//!
//! @param  none
//!
//! @return none
//!
//! @brief  Disable waln IrQ pin
//
//*****************************************************************************

void WlanInterruptDisable()
{
	//digitalWrite(P8_1,LOW);
	//P2IE &= ~BIT3;
	detachInterrupt(IRQpin);
	
}

//*****************************************************************************
//
//! WriteWlanPin
//!
//! @param  val value to write to wlan pin
//!
//! @return none
//!
//! @brief  write value to wlan pin
//
//*****************************************************************************

void WriteWlanPin( unsigned char val )
{
	if (val)
	{
		digitalWrite(ENpin, HIGH);
	}
	else
	{
		digitalWrite(ENpin, LOW);
	}
}

// Timer A0 interrupt service routine

#pragma vector=TIMER1_A0_VECTOR
__interrupt void TIMER1_A0_ISR(void)
{              
	__bic_SR_register_on_exit(LPM3_bits);
	__no_operation();                          // For debugger
}




//Catch interrupt vectors that are not initialized.

/*
#pragma vector=PORT1_VECTOR, WDT_VECTOR, TIMER1_A1_VECTOR, TIMER0_A1_VECTOR, TIMER0_A0_VECTOR, ADC10_VECTOR, UNMI_VECTOR,COMP_D_VECTOR,	DMA_VECTOR, PORT3_VECTOR, PORT4_VECTOR, RTC_VECTOR, TIMER0_B0_VECTOR, TIMER0_B1_VECTOR, TIMER1_B0_VECTOR, TIMER1_B1_VECTOR, TIMER2_B0_VECTOR, TIMER2_B1_VECTOR,SYSNMI_VECTOR, USCI_A1_VECTOR, USCI_B0_VECTOR
__interrupt void Trap_ISR(void)
{
  while(1);
}

*/


