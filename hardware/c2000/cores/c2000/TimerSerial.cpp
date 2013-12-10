/*
  ************************************************************************
  *	TimerSerial.cpp
  *
  *	Arduino core files for C2000
  *		Copyright (c) 2012 Trey German. All right reserved.
  *
  *
  ***********************************************************************
  Derived from:
  HardwareSerial.cpp - Hardware serial library for Wiring
  Copyright (c) 2006 Nicholas Zambetti.  All right reserved.
  and
  msp430softserial by Rick Kimball
  https://github.com/RickKimball

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "Energia.h"
#include "TimerSerial.h"

#define SERIAL_BUFFER_SIZE 16

#define DISABLE_EXTERNAL1_INTERRUPT( )  XIntruptRegs.XINT1CR.bit.ENABLE = 0
#define ENABLE_EXTERNAL1_INTERRUPT( )   XIntruptRegs.XINT1CR.bit.ENABLE = 1
#define ENABLE_TIMER_INTERRUPT( )       CpuTimer0Regs.TCR.bit.TIE = 1
#define DISABLE_TIMER_INTERRUPT( )      CpuTimer0Regs.TCR.bit.TIE = 0
struct ring_buffer_ts
{
    volatile unsigned int head;
    volatile unsigned int tail;
    unsigned char buffer[SERIAL_BUFFER_SIZE];
};

/**
 * uint8x2_t - optimized structure storage for ISR. Fits our static variables in one register
 *             This tweak allows the ISR to use one less register saving a push and pop
 *             We also save a couple of instructions being able to write to both values with
 *             one mov.w instruction.
 */
typedef union uint8x2_t {
    //---------- word access
    uint16_t mask_data;     // access both as a word: mask is low byte, data is high byte
    //--- or --- individual byte access
    struct {
        uint8_t mask:8;     // bit mask to set data bits. Also used as a loop end flag
        uint8_t data:8;     // working value for bits received
    } b;
} uint8x2_t;


/*! \brief  Type defined enumeration holding software UART's state.
 *
 */
typedef enum
{
    IDLE,                                       //!< Idle state, both transmit and receive possible.
    TRANSMIT,                                   //!< Transmitting byte.
    TRANSMIT_STOP_BIT,                          //!< Transmitting stop bit.
    RECEIVE,                                    //!< Receiving byte.
    DATA_PENDING                                //!< Byte received and ready to read.
}AsynchronousStates_t;

static volatile AsynchronousStates_t state;     //!< Holds the state of the UART.

// --- ---
static volatile unsigned int USARTTXBUF;
static volatile unsigned int BaudRate;
unsigned int RxStart = 0;
struct CPUTIMER_VARS CpuTimer0;

//static ring_buffer_ts timer_rx_buffer
ring_buffer_ts timer_rx_buffer =  {  0, 0, { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 } }; //this rx_buffer is different as the one in the HardwareSerial
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	   //in the Expressions window, the address should be 0x8c56

#if NEEDS_BUFF_PTR
 static ring_buffer_ts timer_tx_buffer; // required for the g2231, without it we get garbage
#endif


TimerSerial timerSerial; //Serial legacy, but incompatible as HardwareSerial, so change it as timerSerial

/*
void serialEvent() __attribute__((weak));
void serialEvent() {}

void serialEventRun(void)
{
  if (timerSerial.available()) serialEvent();
}
*/
TimerSerial::TimerSerial()
{
#if NEEDS_BUFF_PTR
    _rx_buffer = &timer_rx_buffer;
    _tx_buffer = &timer_tx_buffer;
#endif
}

#define CPU_FREQ     60E6        // Default = 60 MHz. Change to 50E6 for 50 MHz devices

void TimerSerial::begin(register unsigned long baud)
{

	EALLOW;	// This is needed to write to EALLOW protected registers
	PieVectTable.XINT1 = &xint1_isr;
	PieVectTable.TINT0 = &cpu_timer0_isr;
	EDIS;   // This is needed to disable write to EALLOW protected registers
	PieCtrlRegs.PIECTRL.bit.ENPIE = 1;          // Enable the PIE block
	PieCtrlRegs.PIEIER1.bit.INTx4 = 1;          // Enable PIE Gropu 1 INT4
	PieCtrlRegs.PIEIER1.bit.INTx7 = 1;          // Enable TINT0 in the PIE: Group 1 interrupt 7
	IER |= M_INT1;                              // Enable CPU INT1
	EINT;

	/* Serial port*/
	EALLOW;
	/* Enable internal pull-up for the selected pins */
	GpioCtrlRegs.GPAPUD.bit.GPIO28 = 0;    // Enable pull-up for GPIO28 (SCIRXDA)
	GpioCtrlRegs.GPAPUD.bit.GPIO29 = 1;	   // Disable pull-up for GPIO29 (SCITXDA)

	/* Configure SCI-A pins using GPIO regs*/
	// This specifies which of the possible GPIO pins will be SCI functional pins.
	GpioCtrlRegs.GPAMUX2.bit.GPIO28 = 0;   // Configure GPIO28 for timer-UART RX operation
	GpioCtrlRegs.GPAMUX2.bit.GPIO29 = 0;   // Configure GPIO29 for timer-UART TX operation

	// GPIO28 is input, GPIO29 is output
	GpioCtrlRegs.GPADIR.bit.GPIO28 = 0;          // input
	GpioCtrlRegs.GPADIR.bit.GPIO29 = 1;          // output

	// SET GPIO29 TX IDLE state as Mark = "1"
	GpioDataRegs.GPASET.bit.GPIO29 = 1;

	GpioCtrlRegs.GPAQSEL2.bit.GPIO28 = 0;        // XINT1 Synch to SYSCLKOUT only
	EDIS;

	/* CPU timer0 */
	// Initialize address pointers to respective timer registers:
	CpuTimer0.RegsAddr = &CpuTimer0Regs;
	// Initialize timer period to maximum:
	BaudRate = baud;
	CpuTimer0Regs.PRD.all  = CPU_FREQ/BaudRate;
	// Initialize pre-scale counter to divide by 1 (SYSCLKOUT):
	CpuTimer0Regs.TPR.all  = 0;
	CpuTimer0Regs.TPRH.all = 0;
	// Make sure timer is stopped:
	CpuTimer0Regs.TCR.bit.TSS = 1;
	// Reload all counter register with period value:
	CpuTimer0Regs.TCR.bit.TRB = 1;
	// Reset interrupt counters:
	CpuTimer0.InterruptCount = 0;

	/* External interrupt*/
	EALLOW;
	GpioIntRegs.GPIOXINT1SEL.bit.GPIOSEL = 28;   // XINT1 is GPIO28
	EDIS;

	// Configure XINT1
	XIntruptRegs.XINT1CR.bit.POLARITY = 0;      // Falling edge interrupt

	// Enable XINT1
	ENABLE_EXTERNAL1_INTERRUPT( );       // Enable XINT1

	//Internal State Variable
	state = IDLE;

}

void TimerSerial::end()
{
	while( state != IDLE )
	  {
	    ;                               // Don't send while busy receiving or transmitting.
	  }
	DISABLE_EXTERNAL1_INTERRUPT( );     // disable Receive
    DISABLE_TIMER_INTERRUPT( );
    EALLOW;
    GpioCtrlRegs.GPADIR.bit.GPIO29 = 0; // TX pin as input
    EDIS;
}

int TimerSerial::read()
{
    register uint16_t temp_tail=timer_rx_buffer.tail;

    if (timer_rx_buffer.head != temp_tail) {
        uint8_t c = timer_rx_buffer.buffer[temp_tail++];
        timer_rx_buffer.tail = temp_tail % SERIAL_BUFFER_SIZE;
        return c;
    }
    else {
        return -1;
    }
}

int TimerSerial::available()
{
    unsigned cnt = (timer_rx_buffer.head - timer_rx_buffer.tail) % SERIAL_BUFFER_SIZE;

    return cnt;
}

void TimerSerial::flush()
{
	while( state != IDLE ) // or while (state == TRANSMIT)
		  {
		    ;              // Don't send while busy receiving or transmitting.
		  }
}

int TimerSerial::peek()
{
    register uint16_t temp_tail=timer_rx_buffer.tail;

    if (timer_rx_buffer.head != temp_tail) {
        return timer_rx_buffer.buffer[temp_tail];
    }
    else {
        return -1;
    }
}

size_t TimerSerial::write(uint8_t c)
{
	while( state != IDLE )
	  {
	    ;                                 // Don't send while busy receiving or transmitting.
	  }

	state = TRANSMIT;
	DISABLE_EXTERNAL1_INTERRUPT( );       // Disable reception.

    register unsigned value = c | 0x100;  // add stop bit '1'
    value <<= 1;                          // Add the start bit '0'
    USARTTXBUF=value;                     // queue up the byte for xmit
    ENABLE_TIMER_INTERRUPT( );            // Enable interrupt
    CpuTimer0Regs.TCR.bit.TRB = 1;        // reload the period of baud rate
    CpuTimer0Regs.TCR.bit.TSS = 0;        // Start the timer0
    return 1;
}


#define store_rxchar(c) { \
    register unsigned int next_head;\
    next_head = timer_rx_buffer.head;\
    timer_rx_buffer.buffer[next_head++]=c; \
    next_head %= SERIAL_BUFFER_SIZE; \
    if ( next_head != timer_rx_buffer.tail ) { \
        timer_rx_buffer.head = next_head; \
    } \
}


interrupt void xint1_isr(void)
{
	state = RECEIVE;
	RxStart = 1;
	// Disable XINT1
	DISABLE_EXTERNAL1_INTERRUPT( );   // Disable XINT1
	DISABLE_TIMER_INTERRUPT( );       // Disable timer to change its registers
	CpuTimer0Regs.PRD.all  = 1.5*CPU_FREQ/BaudRate;

	CpuTimer0Regs.TCR.bit.TRB = 1;    // reload the period of baud rate
	CpuTimer0Regs.TCR.bit.TSS = 0;    // Start the timer0
	ENABLE_TIMER_INTERRUPT( );        // Use write-only instruction to set TSS bit = 0 and enable the CPU timer0 interrupt

	// Acknowledge this interrupt to get more from group 1
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}

interrupt void cpu_timer0_isr(void)
{
	static uint8x2_t rx_bits;                      // persistent storage for data and mask. fits in one 16 bit register
	switch (state) { 
	  // Transmit Byte.
	  case TRANSMIT:
	     if( USARTTXBUF & 0x01 ) {                 // If the LSB of the TX buffer is 1:
	        GpioDataRegs.GPASET.bit.GPIO29 = 1;    // Send a logic 1 on the TX_PIN.
	        }
	     else {                                    // Otherwise:
	        GpioDataRegs.GPACLEAR.bit.GPIO29 = 1;  // Send a logic 0 on the TX_PIN.
	        }

	     if (!(USARTTXBUF >>= 1)) {                // All bits transmitted ?
	    	 DISABLE_TIMER_INTERRUPT( );           // Stop the timer interrupts.
	    	 state = IDLE;                         // Go back to idle.
	    	 ENABLE_EXTERNAL1_INTERRUPT( );        // Enable reception again.
	         }
	   PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
	   break;

    //Receive Byte.
	 case RECEIVE:
		if(RxStart == 1){
			rx_bits.mask_data = 0x0001;         // initialize both values, set data to 0x00 and mask to 0x01
			RxStart = 0;
			CpuTimer0Regs.PRD.all  = CPU_FREQ/BaudRate;
			CpuTimer0Regs.TCR.bit.TRB = 1;    // reload the period of baud rate
			CpuTimer0Regs.TCR.bit.TSS = 0;    // Start the timer0
		}

	    if (GpioDataRegs.GPADAT.bit.GPIO28 ==1 ) {  // sampled bit value from receive latch
	        rx_bits.b.data|=rx_bits.b.mask;         // if latch is high, then set the bit using the sliding mask
	        }

	    if (!(rx_bits.b.mask <<= 1)) {       // Are all bits received? Use the mask to end loop
	       store_rxchar(rx_bits.b.data);     // Store the bits into the rx_buffer
	       state = IDLE;
	       DISABLE_TIMER_INTERRUPT( );
	       ENABLE_EXTERNAL1_INTERRUPT( );         // Enable XINT1 to receive the next byte
	       }
	    PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
	    break;

	    // Unknown state.
	  default:
	  state = IDLE;                           // Error, should not occur. Going to a safe state.

   // Acknowledge this interrupt to receive more interrupts from group 1
   PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
	}
}
