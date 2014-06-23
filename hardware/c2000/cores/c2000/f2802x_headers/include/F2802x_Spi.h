//###########################################################################
//
// FILE:   F2802x_Spi.h
//
// TITLE:  F2802x Device SPI Register Definitions.
//
//###########################################################################
// $TI Release: 2802x C/C++ Header Files and Peripheral Examples V1.29 $
// $Release Date: January 11, 2011 $
//###########################################################################

#ifndef F2802x_SPI_H
#define F2802x_SPI_H

#ifdef __cplusplus
extern "C" {
#endif

//---------------------------------------------------------------------------
// SPI Individual Register Bit Definitions:
//
// SPI FIFO Transmit register bit    definitions:
struct  SPIFFTX_BITS {       // bit    description
    uint16_t TXFFIL:5;          // 4:0    Interrupt level
    uint16_t TXFFIENA:1;        // 5      Interrupt enable
    uint16_t TXFFINTCLR:1;      // 6      Clear INT flag
    uint16_t TXFFINT:1;         // 7      INT flag
    uint16_t TXFFST:5;          // 12:8   FIFO status
    uint16_t TXFIFO:1;          // 13     FIFO reset
    uint16_t SPIFFENA:1;        // 14     Enhancement enable
    uint16_t SPIRST:1;          // 15     Reset SPI
};

union SPIFFTX_REG {
    uint16_t               all;
    struct SPIFFTX_BITS  bit;
};

//--------------------------------------------
// SPI FIFO recieve register bit definitions:
//
//
struct  SPIFFRX_BITS {       // bits   description
    uint16_t RXFFIL:5;          // 4:0    Interrupt level
    uint16_t RXFFIENA:1;        // 5      Interrupt enable
    uint16_t RXFFINTCLR:1;      // 6      Clear INT flag
    uint16_t RXFFINT:1;         // 7      INT flag
    uint16_t RXFFST:5;          // 12:8   FIFO status
    uint16_t RXFIFORESET:1;     // 13     FIFO reset
    uint16_t RXFFOVFCLR:1;      // 14     Clear overflow
    uint16_t RXFFOVF:1;         // 15     FIFO overflow

};

union SPIFFRX_REG {
    uint16_t               all;
    struct SPIFFRX_BITS  bit;
};

//--------------------------------------------
// SPI FIFO control register bit definitions:
//
//
struct  SPIFFCT_BITS {       // bits   description
    uint16_t TXDLY:8;           // 7:0    FIFO transmit delay
    uint16_t rsvd:8;            // 15:8   reserved
};

union SPIFFCT_REG {
    uint16_t               all;
    struct SPIFFCT_BITS  bit;
};

//---------------------------------------------
// SPI configuration register bit definitions:
//
//
struct  SPICCR_BITS {        // bits   description
    uint16_t SPICHAR:4;         // 3:0    Character length control
    uint16_t SPILBK:1;          // 4      Loop-back enable/disable
    uint16_t rsvd1:1;           // 5      reserved
    uint16_t CLKPOLARITY:1;     // 6      Clock polarity
    uint16_t SPISWRESET:1;      // 7      SPI SW Reset
    uint16_t rsvd2:8;           // 15:8   reserved
};

union SPICCR_REG {
    uint16_t              all;
    struct SPICCR_BITS  bit;
};

//-------------------------------------------------
// SPI operation control register bit definitions:
//
//
struct  SPICTL_BITS {        // bits   description
    uint16_t SPIINTENA:1;       // 0      Interrupt enable
    uint16_t TALK:1;            // 1      Master/Slave transmit enable
    uint16_t MASTER_SLAVE:1;    // 2      Network control mode
    uint16_t CLK_PHASE:1;       // 3      Clock phase select
    uint16_t OVERRUNINTENA:1;   // 4      Overrun interrupt enable
    uint16_t rsvd:11;           // 15:5   reserved
};

union SPICTL_REG {
    uint16_t              all;
    struct SPICTL_BITS  bit;
};

//--------------------------------------
// SPI status register bit definitions:
//
//
struct  SPISTS_BITS {        // bits   description
    uint16_t rsvd1:5;           // 4:0    reserved
    uint16_t BUFFULL_FLAG:1;    // 5      SPI transmit buffer full flag
    uint16_t INT_FLAG:1;        // 6      SPI interrupt flag
    uint16_t OVERRUN_FLAG:1;    // 7      SPI reciever overrun flag
    uint16_t rsvd2:8;           // 15:8   reserved
};

union SPISTS_REG {
    uint16_t              all;
    struct SPISTS_BITS  bit;
};

//------------------------------------------------
// SPI priority control register bit definitions:
//
//
struct  SPIPRI_BITS {        // bits   description
    uint16_t TRIWIRE:1;         // 0      3-wire mode select bit
    uint16_t rsvd1:3;           // 3:1    reserved
    uint16_t FREE:1;            // 4      Free emulation mode control
    uint16_t SOFT:1;            // 5      Soft emulation mode control
    uint16_t PRIORITY:1;        // 6      Interrupt priority select
    uint16_t rsvd2:9;           // 15:7   reserved
};

union SPIPRI_REG {
    uint16_t              all;
    struct SPIPRI_BITS  bit;
};

//---------------------------------------------------------------------------
// SPI Register File:
//
struct  SPI_REGS {
    union SPICCR_REG     SPICCR;      // Configuration register
    union SPICTL_REG     SPICTL;      // Operation control register
    union SPISTS_REG     SPISTS;      // Status register
    uint16_t               rsvd1;       // reserved
    uint16_t               SPIBRR;      // Baud Rate
    uint16_t               rsvd2;       // reserved
    uint16_t               SPIRXEMU;    // Emulation buffer
    uint16_t               SPIRXBUF;    // Serial input buffer
    uint16_t               SPITXBUF;    // Serial output buffer
    uint16_t               SPIDAT;      // Serial data
    union SPIFFTX_REG    SPIFFTX;     // FIFO transmit register
    union SPIFFRX_REG    SPIFFRX;     // FIFO recieve register
    union SPIFFCT_REG    SPIFFCT;     // FIFO control register
    uint16_t               rsvd3[2];    // reserved
    union SPIPRI_REG     SPIPRI;      // FIFO Priority control
};

//---------------------------------------------------------------------------
// SPI External References & Function Declarations:
//
extern volatile struct SPI_REGS SpiaRegs;

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of F2802x_SPI_H definition

//===========================================================================
// End of file.
//===========================================================================

