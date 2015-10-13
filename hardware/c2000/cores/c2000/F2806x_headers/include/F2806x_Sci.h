//###########################################################################
//
// FILE:   F2806x_Sci.h
//
// TITLE:  F2806x Device SCI Register Definitions.
//
//###########################################################################
// $TI Release: 2806x C/C++ Header Files V1.10 $   
// $Release Date: April 7, 2011 $   
//###########################################################################

#ifndef F2806x_SCI_H
#define F2806x_SCI_H

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// SCI Individual Register Bit Definitions:

struct SCICCR_BITS {     // bits description
	Uint16	SCICHAR:3;			// 2:0	Character length control
	Uint16	ADDRIDLE_MODE:1;	// 3	ADDR/IDLE Mode control
	Uint16	LOOPBKENA:1;		// 4	Loop Back enable
	Uint16	PARITYENA:1;		// 5	Parity enable
	Uint16	PARITY:1;			// 6	Even or Odd Parity
	Uint16	STOPBITS:1;			// 7	Number of Stop Bits
	Uint16	rsvd1:8;			// 15:8	Reserved
};

union SCICCR_REG {
	Uint16 all;
	struct SCICCR_BITS	bit;
};

struct SCICTL1_BITS {     // bits description
	Uint16	RXENA:1;			// 0	SCI receiver enable
	Uint16	TXENA:1;			// 1	SCI transmitter enable
	Uint16	SLEEP:1;			// 2	SCI sleep
	Uint16	TXWAKE:1;			// 3	Transmitter wakeup method
	Uint16	rsvd1:1;			// 4	Reserved
	Uint16	SWRESET:1;			// 5	Software reset
	Uint16	RXERRINTENA:1;		// 6	Recieve interrupt enable
	Uint16	rsvd2:9;			// 15:7	Reserved
};

union SCICTL1_REG {
	Uint16 all;
	struct SCICTL1_BITS	bit;
};

struct SCICTL2_BITS {     // bits description
	Uint16	TXINTENA:1;			// 0	Transmit interrupt enable
	Uint16	RXBKINTENA:1;		// 1	Receiver-buffer break enable
	Uint16	rsvd1:4;			// 5:2	Reserved
	Uint16	TXEMPTY:1;			// 6	Transmitter empty flag
	Uint16	TXRDY:1;			// 7	Transmitter ready flag
	Uint16	rsvd2:8;			// 15:8	Reserved
};

union SCICTL2_REG {
	Uint16 all;
	struct SCICTL2_BITS	bit;
};

struct SCIRXST_BITS {     // bits description
	Uint16	rsvd1:1;		// 0	Reserved
	Uint16	RXWAKE:1;		// 1	Receiver wakeup detect flag
	Uint16	PE:1;			// 2	Parity error flag
	Uint16	OE:1;			// 3	Overrun error flag
	Uint16	FE:1;			// 4	Framing error flag
	Uint16	BRKDT:1;		// 5	Break-detect flag
	Uint16	RXRDY:1;		// 6	Receiver ready flag
	Uint16	RXERROR:1;		// 7	Receiver error flag
	Uint16	rsvd2:8;		// 15:8	Reserved
};

union SCIRXST_REG {
	Uint16 all;
	struct SCIRXST_BITS	bit;
};

struct SCIRXBUF_BITS {     // bits description
	Uint16	RXDT:8;			// 7:0  	Receive word
	Uint16	rsvd1:6;		// 13:8	Reserved
	Uint16	SCIFFPE:1;		// 14 	SCI PE error in FIFO mode
	Uint16	SCIFFFE:1;		// 15	SCI FE error in FIFO mode
};

union SCIRXBUF_REG {
	Uint16 all;
	struct SCIRXBUF_BITS	bit;
};

struct SCIFFTX_BITS {     // bits description
	Uint16	TXFFIL:5;			// 4:0	Interrupt level
	Uint16	TXFFIENA:1;			// 5	Interrupt enable
	Uint16	TXFFINTCLR:1;		// 6	Clear INT flag
	Uint16	TXFFINT:1;			// 7	INT flag
	Uint16	TXFFST:5;			// 12:8	FIFO status
	Uint16	TXFIFORESET:1;		// 13	FIFO reset
	Uint16	SCIFFENA:1;			// 14	Enhancement enable
	Uint16	SCIRST:1;			// 15	SCI reset rx/tx channels
};

union SCIFFTX_REG {
	Uint16 all;
	struct SCIFFTX_BITS	bit;
};

struct SCIFFRX_BITS {     // bits description
	Uint16	RXFFIL:5;			// 4:0	Interrupt level
	Uint16	RXFFIENA:1;			// 5	Interrupt enable
	Uint16	RXFFINTCLR:1;		// 6	Clear INT flag
	Uint16	RXFFINT:1;			// 7	INT flag
	Uint16	RXFFST:5;			// 12:8 	FIFO status
	Uint16	RXFIFORESET:1;		// 13	FIFO reset
	Uint16	RXFFOVRCLR:1;		// 14	Clear overflow
	Uint16	RXFFOVF:1;			// 15	FIFO overflow
};

union SCIFFRX_REG {
	Uint16 all;
	struct SCIFFRX_BITS	bit;
};

struct SCIFFCT_BITS {     // bits description
	Uint16	FFTXDLY:8;		// 7:0	FIFO transmit delay
	Uint16	rsvd1:5;		// 12:8	Reserved
	Uint16	CDC:1;			// 13	Auto baud mode enable
	Uint16	ABDCLR:1;		// 14	Auto baud clear
	Uint16	ABD:1;			// 15	Auto baud detect
};

union SCIFFCT_REG {
	Uint16 all;
	struct SCIFFCT_BITS	bit;
};

struct SCIPRI_BITS {     // bits description
	Uint16	rsvd1:3;		// 2:0	Reserved
	Uint16	FREE:1;			// 3	Free emulation suspend mode
	Uint16	SOFT:1;			// 4	Soft emulation suspend mode
	Uint16	rsvd2:3;		// 7:5	Reserved
	Uint16	rsvd3:8;		// 15:8	Reserved
};

union SCIPRI_REG {
	Uint16 all;
	struct SCIPRI_BITS	bit;
};

struct SCI_REGS {
	union	SCICCR_REG		SCICCR;		// Communications control register
	union	SCICTL1_REG		SCICTL1;	// Control register 1
	Uint16	SCIHBAUD;					// Baud rate (high) register
	Uint16	SCILBAUD;					// Baud rate (low) register
	union	SCICTL2_REG		SCICTL2;	// Control register 2
	union	SCIRXST_REG		SCIRXST;	// Recieve status register
	Uint16					SCIRXEMU;	// Recieve emulation buffer register
	union	SCIRXBUF_REG	SCIRXBUF;	// Recieve data buffer
	Uint16					rsvd1;		// Reserved
	Uint16					SCITXBUF;	// Transmit data buffer
	union	SCIFFTX_REG		SCIFFTX;	// FIFO transmit register
	union	SCIFFRX_REG		SCIFFRX;	// FIFO recieve register
	union	SCIFFCT_REG		SCIFFCT;	// FIFO control register
	Uint16					rsvd2;		// Reserved
	Uint16					rsvd3;		// Reserved
	union	SCIPRI_REG		SCIPRI;		// FIFO Priority control
};

//---------------------------------------------------------------------------
// Sci External References & Function Declarations:
//
extern volatile struct SCI_REGS SciaRegs;
extern volatile struct SCI_REGS ScibRegs;

#ifdef __cplusplus
}
#endif /* extern "C" */


#endif  // end of F2806x_SCI_H definition
//===========================================================================
// End of file.
//===========================================================================
