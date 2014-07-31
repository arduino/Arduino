//###########################################################################
//
// FILE:    F2802x_Sci.h
//
// TITLE:    F2802x Device SCI Register Definitions.
//
//###########################################################################
// $TI Release: 2802x C/C++ Header Files and Peripheral Examples V1.29 $
// $Release Date: January 11, 2011 $
//###########################################################################

#ifndef F2802x_SCI_H
#define F2802x_SCI_H

#ifdef __cplusplus
extern "C" {
#endif

//---------------------------------------------------------------------------
// SCI Individual Register Bit Definitions

//----------------------------------------------------------
// SCICCR communication control register bit definitions:
//

struct  SCICCR_BITS {        // bit    description
    uint16_t SCICHAR:3;         // 2:0    Character length control
    uint16_t ADDRIDLE_MODE:1;   // 3      ADDR/IDLE Mode control
    uint16_t LOOPBKENA:1;       // 4      Loop Back enable
    uint16_t PARITYENA:1;       // 5      Parity enable
    uint16_t PARITY:1;          // 6      Even or Odd Parity
    uint16_t STOPBITS:1;        // 7      Number of Stop Bits
    uint16_t rsvd1:8;           // 15:8   reserved
};

union SCICCR_REG {
    uint16_t              all;
    struct SCICCR_BITS  bit;
};

//-------------------------------------------
// SCICTL1 control register 1 bit definitions:
//

struct  SCICTL1_BITS {       // bit    description
    uint16_t RXENA:1;           // 0      SCI receiver enable
    uint16_t TXENA:1;           // 1      SCI transmitter enable
    uint16_t SLEEP:1;           // 2      SCI sleep
    uint16_t TXWAKE:1;          // 3      Transmitter wakeup method
    uint16_t rsvd:1;            // 4      reserved
    uint16_t SWRESET:1;         // 5      Software reset
    uint16_t RXERRINTENA:1;     // 6      Recieve interrupt enable
    uint16_t rsvd1:9;           // 15:7   reserved

};

union SCICTL1_REG {
    uint16_t               all;
    struct SCICTL1_BITS  bit;
};

//---------------------------------------------
// SCICTL2 control register 2 bit definitions:
//

struct  SCICTL2_BITS {       // bit    description
    uint16_t TXINTENA:1;        // 0      Transmit interrupt enable
    uint16_t RXBKINTENA:1;      // 1      Receiver-buffer break enable
    uint16_t rsvd:4;            // 5:2    reserved
    uint16_t TXEMPTY:1;         // 6      Transmitter empty flag
    uint16_t TXRDY:1;           // 7      Transmitter ready flag
    uint16_t rsvd1:8;           // 15:8   reserved

};

union SCICTL2_REG {
    uint16_t               all;
    struct SCICTL2_BITS  bit;
};

//---------------------------------------------------
// SCIRXST Receiver status register bit definitions:
//

struct  SCIRXST_BITS {       // bit    description
    uint16_t rsvd:1;            // 0      reserved
    uint16_t RXWAKE:1;          // 1      Receiver wakeup detect flag
    uint16_t PE:1;              // 2      Parity error flag
    uint16_t OE:1;              // 3      Overrun error flag
    uint16_t FE:1;              // 4      Framing error flag
    uint16_t BRKDT:1;           // 5      Break-detect flag
    uint16_t RXRDY:1;           // 6      Receiver ready flag
    uint16_t RXERROR:1;         // 7      Receiver error flag

};

union SCIRXST_REG {
    uint16_t               all;
    struct SCIRXST_BITS  bit;
};

//----------------------------------------------------
// SCIRXBUF Receiver Data Buffer with FIFO bit definitions:
//

struct  SCIRXBUF_BITS {      // bits   description
    uint16_t RXDT:8;            // 7:0    Receive word
    uint16_t rsvd:6;            // 13:8   reserved
    uint16_t SCIFFPE:1;         // 14     SCI PE error in FIFO mode
    uint16_t SCIFFFE:1;         // 15     SCI FE error in FIFO mode
};

union SCIRXBUF_REG {
    uint16_t                all;
    struct SCIRXBUF_BITS  bit;
};

//--------------------------------------------------
// SCIPRI Priority control register bit definitions:
//
//

struct  SCIPRI_BITS {        // bit    description
    uint16_t rsvd:3;            // 2:0    reserved
    uint16_t FREE:1;            // 3      Free emulation suspend mode
    uint16_t SOFT:1;            // 4      Soft emulation suspend mode
    uint16_t rsvd1:3;           // 7:5    reserved
};

union SCIPRI_REG {
    uint16_t              all;
    struct SCIPRI_BITS  bit;
};

//-------------------------------------------------
// SCI FIFO Transmit register bit definitions:
//
//

struct  SCIFFTX_BITS {       // bit    description
    uint16_t TXFFIL:5;          // 4:0    Interrupt level
    uint16_t TXFFIENA:1;        // 5      Interrupt enable
    uint16_t TXFFINTCLR:1;      // 6      Clear INT flag
    uint16_t TXFFINT:1;         // 7      INT flag
    uint16_t TXFFST:5;          // 12:8   FIFO status
    uint16_t TXFIFOXRESET:1;    // 13     FIFO reset
    uint16_t SCIFFENA:1;        // 14     Enhancement enable
    uint16_t SCIRST:1;          // 15     SCI reset rx/tx channels

};

union SCIFFTX_REG {
    uint16_t               all;
    struct SCIFFTX_BITS  bit;
};

//------------------------------------------------
// SCI FIFO recieve register bit definitions:
//
//

struct  SCIFFRX_BITS {       // bits   description
    uint16_t RXFFIL:5;          // 4:0    Interrupt level
    uint16_t RXFFIENA:1;        // 5      Interrupt enable
    uint16_t RXFFINTCLR:1;      // 6      Clear INT flag
    uint16_t RXFFINT:1;         // 7      INT flag
    uint16_t RXFFST:5;          // 12:8   FIFO status
    uint16_t RXFIFORESET:1;     // 13     FIFO reset
    uint16_t RXFFOVRCLR:1;      // 14     Clear overflow
    uint16_t RXFFOVF:1;         // 15     FIFO overflow

};

union SCIFFRX_REG {
    uint16_t               all;
    struct SCIFFRX_BITS  bit;
};

// SCI FIFO control register bit definitions:
struct  SCIFFCT_BITS {     // bits   description
    uint16_t FFTXDLY:8;         // 7:0    FIFO transmit delay
    uint16_t rsvd:5;            // 12:8   reserved
    uint16_t CDC:1;             // 13     Auto baud mode enable
    uint16_t ABDCLR:1;          // 14     Auto baud clear
    uint16_t ABD:1;             // 15     Auto baud detect
};

union SCIFFCT_REG {
    uint16_t               all;
    struct SCIFFCT_BITS  bit;
};

//---------------------------------------------------------------------------
// SCI Register File:
//
struct  SCI_REGS {
    union SCICCR_REG     SCICCR;     // Communications control register
    union SCICTL1_REG    SCICTL1;    // Control register 1
    uint16_t               SCIHBAUD;   // Baud rate (high) register
    uint16_t               SCILBAUD;   // Baud rate (low) register
    union SCICTL2_REG    SCICTL2;    // Control register 2
    union SCIRXST_REG    SCIRXST;    // Recieve status register
    uint16_t               SCIRXEMU;   // Recieve emulation buffer register
    union SCIRXBUF_REG   SCIRXBUF;   // Recieve data buffer
    uint16_t               rsvd1;      // reserved
    uint16_t               SCITXBUF;   // Transmit data buffer
    union SCIFFTX_REG    SCIFFTX;    // FIFO transmit register
    union SCIFFRX_REG    SCIFFRX;    // FIFO recieve register
    union SCIFFCT_REG    SCIFFCT;    // FIFO control register
    uint16_t               rsvd2;      // reserved
    uint16_t               rsvd3;      // reserved
    union SCIPRI_REG     SCIPRI;     // FIFO Priority control
};

//---------------------------------------------------------------------------
// SCI External References & Function Declarations:
//
extern volatile struct SCI_REGS SciaRegs;

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of F2802x_SCI_H definition

//===========================================================================
// End of file.
//===========================================================================

