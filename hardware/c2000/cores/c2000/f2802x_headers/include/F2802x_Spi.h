// TI File $Revision: /main/1 $
// Checkin $Date: August 14, 2008   16:56:02 $
//###########################################################################
//
// FILE:   DSP2802x_Spi.h
//
// TITLE:  DSP2802x Device SPI Register Definitions.
//
//###########################################################################
// $TI Release: f2802x Support Library v210 $
// $Release Date: Mon Sep 17 09:13:31 CDT 2012 $
//###########################################################################

#ifndef DSP2802x_SPI_H
#define DSP2802x_SPI_H

#ifdef __cplusplus
extern "C" {
#endif

//---------------------------------------------------------------------------
// SPI Individual Register Bit Definitions:
//
// SPI FIFO Transmit register bit    definitions:
struct  SPIFFTX_BITS {       // bit    description
   Uint16 TXFFIL:5;          // 4:0    Interrupt level
   Uint16 TXFFIENA:1;        // 5      Interrupt enable
   Uint16 TXFFINTCLR:1;      // 6      Clear INT flag
   Uint16 TXFFINT:1;         // 7      INT flag
   Uint16 TXFFST:5;          // 12:8   FIFO status
   Uint16 TXFIFO:1;          // 13     FIFO reset
   Uint16 SPIFFENA:1;        // 14     Enhancement enable
   Uint16 SPIRST:1;          // 15     Reset SPI
};

union SPIFFTX_REG {
   Uint16               all;
   struct SPIFFTX_BITS  bit;
};

//--------------------------------------------
// SPI FIFO recieve register bit definitions:
//
//
struct  SPIFFRX_BITS {       // bits   description
   Uint16 RXFFIL:5;          // 4:0    Interrupt level
   Uint16 RXFFIENA:1;        // 5      Interrupt enable
   Uint16 RXFFINTCLR:1;      // 6      Clear INT flag
   Uint16 RXFFINT:1;         // 7      INT flag
   Uint16 RXFFST:5;          // 12:8   FIFO status
   Uint16 RXFIFORESET:1;     // 13     FIFO reset
   Uint16 RXFFOVFCLR:1;      // 14     Clear overflow
   Uint16 RXFFOVF:1;         // 15     FIFO overflow

};

union SPIFFRX_REG {
   Uint16               all;
   struct SPIFFRX_BITS  bit;
};

//--------------------------------------------
// SPI FIFO control register bit definitions:
//
//
struct  SPIFFCT_BITS {       // bits   description
   Uint16 TXDLY:8;           // 7:0    FIFO transmit delay
   Uint16 rsvd:8;            // 15:8   reserved
};

union SPIFFCT_REG {
   Uint16               all;
   struct SPIFFCT_BITS  bit;
};

//---------------------------------------------
// SPI configuration register bit definitions:
//
//
struct  SPICCR_BITS {        // bits   description
   Uint16 SPICHAR:4;         // 3:0    Character length control
   Uint16 SPILBK:1;          // 4      Loop-back enable/disable
   Uint16 rsvd1:1;           // 5      reserved
   Uint16 CLKPOLARITY:1;     // 6      Clock polarity
   Uint16 SPISWRESET:1;      // 7      SPI SW Reset
   Uint16 rsvd2:8;           // 15:8   reserved
};

union SPICCR_REG {
   Uint16              all;
   struct SPICCR_BITS  bit;
};

//-------------------------------------------------
// SPI operation control register bit definitions:
//
//
struct  SPICTL_BITS {        // bits   description
   Uint16 SPIINTENA:1;       // 0      Interrupt enable
   Uint16 TALK:1;            // 1      Master/Slave transmit enable
   Uint16 MASTER_SLAVE:1;    // 2      Network control mode
   Uint16 CLK_PHASE:1;       // 3      Clock phase select
   Uint16 OVERRUNINTENA:1;   // 4      Overrun interrupt enable
   Uint16 rsvd:11;           // 15:5   reserved
};

union SPICTL_REG {
   Uint16              all;
   struct SPICTL_BITS  bit;
};

//--------------------------------------
// SPI status register bit definitions:
//
//
struct  SPISTS_BITS {        // bits   description
   Uint16 rsvd1:5;           // 4:0    reserved
   Uint16 BUFFULL_FLAG:1;    // 5      SPI transmit buffer full flag
   Uint16 INT_FLAG:1;        // 6      SPI interrupt flag
   Uint16 OVERRUN_FLAG:1;    // 7      SPI reciever overrun flag
   Uint16 rsvd2:8;           // 15:8   reserved
};

union SPISTS_REG {
   Uint16              all;
   struct SPISTS_BITS  bit;
};

//------------------------------------------------
// SPI priority control register bit definitions:
//
//
struct  SPIPRI_BITS {        // bits   description
   Uint16 TRIWIRE:1;         // 0      3-wire mode select bit
   Uint16 rsvd1:3;           // 3:1    reserved
   Uint16 FREE:1;            // 4      Free emulation mode control
   Uint16 SOFT:1;            // 5      Soft emulation mode control
   Uint16 PRIORITY:1;        // 6      Interrupt priority select
   Uint16 rsvd2:9;           // 15:7   reserved
};

union SPIPRI_REG {
   Uint16              all;
   struct SPIPRI_BITS  bit;
};

//---------------------------------------------------------------------------
// SPI Register File:
//
struct  SPI_REGS {
   union SPICCR_REG     SPICCR;      // Configuration register
   union SPICTL_REG     SPICTL;      // Operation control register
   union SPISTS_REG     SPISTS;      // Status register
   Uint16               rsvd1;       // reserved
   Uint16               SPIBRR;      // Baud Rate
   Uint16               rsvd2;       // reserved
   Uint16               SPIRXEMU;    // Emulation buffer
   Uint16               SPIRXBUF;    // Serial input buffer
   Uint16               SPITXBUF;    // Serial output buffer
   Uint16               SPIDAT;      // Serial data
   union SPIFFTX_REG    SPIFFTX;     // FIFO transmit register
   union SPIFFRX_REG    SPIFFRX;     // FIFO recieve register
   union SPIFFCT_REG    SPIFFCT;     // FIFO control register
   Uint16               rsvd3[2];    // reserved
   union SPIPRI_REG     SPIPRI;      // FIFO Priority control
};

//---------------------------------------------------------------------------
// SPI External References & Function Declarations:
//
extern volatile struct SPI_REGS SpiaRegs;

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of DSP2802x_SPI_H definition

//===========================================================================
// End of file.
//===========================================================================

