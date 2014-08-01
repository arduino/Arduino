//###########################################################################
//
// FILE:   F2802x_I2c.h
//
// TITLE:  F2802x Inter-Integrated Circuit (I2C) Module
//         Register Bit Definitions.
//
//###########################################################################
// $TI Release: 2802x C/C++ Header Files and Peripheral Examples V1.29 $
// $Release Date: January 11, 2011 $
//###########################################################################

#ifndef F2802x_I2C_H
#define F2802x_I2C_H

#ifdef __cplusplus
extern "C" {
#endif

//----------------------------------------------------
// I2C interrupt vector register bit definitions */
struct I2CISRC_BITS {         // bits   description
    uint16_t INTCODE:3;          // 2:0    Interrupt code
    uint16_t rsvd1:13;           // 15:3   reserved
};

union I2CISRC_REG {
    uint16_t                 all;
    struct I2CISRC_BITS    bit;
};

//----------------------------------------------------
// I2C interrupt mask register bit definitions */
struct I2CIER_BITS {          // bits   description
    uint16_t ARBL:1;               // 0      Arbitration lost interrupt
    uint16_t NACK:1;             // 1      No ack interrupt
    uint16_t ARDY:1;             // 2      Register access ready interrupt
    uint16_t RRDY:1;             // 3      Recieve data ready interrupt
    uint16_t XRDY:1;             // 4      Transmit data ready interrupt
    uint16_t SCD:1;              // 5      Stop condition detection
    uint16_t AAS:1;              // 6      Address as slave
    uint16_t rsvd:9;             // 15:7   reserved
};

union I2CIER_REG {
    uint16_t                 all;
    struct I2CIER_BITS     bit;
};

//----------------------------------------------------
// I2C status register bit definitions */
struct I2CSTR_BITS {          // bits   description
    uint16_t ARBL:1;               // 0      Arbitration lost interrupt
    uint16_t NACK:1;             // 1      No ack interrupt
    uint16_t ARDY:1;             // 2      Register access ready interrupt
    uint16_t RRDY:1;             // 3      Recieve data ready interrupt
    uint16_t XRDY:1;             // 4      Transmit data ready interrupt
    uint16_t SCD:1;              // 5      Stop condition detection
    uint16_t rsvd1:2;            // 7:6    reserved
    uint16_t AD0:1;              // 8      Address Zero
    uint16_t AAS:1;              // 9      Address as slave
    uint16_t XSMT:1;             // 10     XMIT shift empty
    uint16_t RSFULL:1;           // 11     Recieve shift full
    uint16_t BB:1;               // 12     Bus busy
    uint16_t NACKSNT:1;          // 13     A no ack sent
    uint16_t SDIR:1;             // 14     Slave direction
    uint16_t rsvd2:1;            // 15     reserved
};

union I2CSTR_REG {
    uint16_t                 all;
    struct I2CSTR_BITS     bit;
};

//----------------------------------------------------
// I2C mode control register bit definitions */
struct I2CMDR_BITS {          // bits   description
    uint16_t BC:3;               // 2:0    Bit count
    uint16_t FDF:1;              // 3      Free data format
    uint16_t STB:1;              // 4      Start byte
    uint16_t IRS:1;              // 5      I2C Reset not
    uint16_t DLB:1;              // 6      Digital loopback
    uint16_t RM:1;               // 7      Repeat mode
    uint16_t XA:1;               // 8      Expand address
    uint16_t TRX:1;              // 9      Transmitter/reciever
    uint16_t MST:1;              // 10     Master/slave
    uint16_t STP:1;              // 11     Stop condition
    uint16_t rsvd1:1;            // 12     reserved
    uint16_t STT:1;              // 13     Start condition
    uint16_t FREE:1;             // 14     Emulation mode
    uint16_t NACKMOD:1;          // 15     No Ack mode
};

union I2CMDR_REG {
    uint16_t                 all;
    struct I2CMDR_BITS     bit;
};

//----------------------------------------------------
// I2C extended mode control register bit definitions */
struct I2CEMDR_BITS {          // bits   description
    uint16_t BCM:1;               // 0      Bit count
    uint16_t rsvd1:15;            // 15:1   reserved
};

union I2CEMDR_REG {
    uint16_t                 all;
    struct I2CEMDR_BITS    bit;
};

//----------------------------------------------------
// I2C pre-scaler register bit definitions */
struct I2CPSC_BITS {         // bits   description
    uint16_t IPSC:8;            // 7:0    pre-scaler
    uint16_t rsvd1:8;           // 15:8   reserved
};

union I2CPSC_REG {
    uint16_t                 all;
    struct I2CPSC_BITS     bit;
};

//----------------------------------------------------
// TX FIFO control register bit definitions */
struct I2CFFTX_BITS {         // bits   description
    uint16_t TXFFIL:5;           // 4:0    FIFO interrupt level
    uint16_t TXFFIENA:1;         // 5      FIFO interrupt enable/disable
    uint16_t TXFFINTCLR:1;       // 6      FIFO clear
    uint16_t TXFFINT:1;          // 7      FIFO interrupt flag
    uint16_t TXFFST:5;           // 12:8   FIFO level status
    uint16_t TXFFRST:1;          // 13     FIFO reset
    uint16_t I2CFFEN:1;          // 14     enable/disable TX & RX FIFOs
    uint16_t rsvd1:1;            // 15     reserved

};

union I2CFFTX_REG {
    uint16_t                 all;
    struct I2CFFTX_BITS    bit;
};

//----------------------------------------------------
// RX FIFO control register bit definitions */
struct I2CFFRX_BITS {         // bits   description
    uint16_t RXFFIL:5;           // 4:0    FIFO interrupt level
    uint16_t RXFFIENA:1;         // 5      FIFO interrupt enable/disable
    uint16_t RXFFINTCLR:1;       // 6      FIFO clear
    uint16_t RXFFINT:1;          // 7      FIFO interrupt flag
    uint16_t RXFFST:5;           // 12:8   FIFO level
    uint16_t RXFFRST:1;          // 13     FIFO reset
    uint16_t rsvd1:2;            // 15:14  reserved
};

union I2CFFRX_REG {
    uint16_t                 all;
    struct I2CFFRX_BITS    bit;
};

//----------------------------------------------------

struct I2C_REGS {
    uint16_t              I2COAR;    // Own address register
    union  I2CIER_REG   I2CIER;    // Interrupt enable
    union  I2CSTR_REG   I2CSTR;    // Interrupt status
    uint16_t              I2CCLKL;   // Clock divider low
    uint16_t              I2CCLKH;   // Clock divider high
    uint16_t              I2CCNT;    // Data count
    uint16_t              I2CDRR;    // Data recieve
    uint16_t              I2CSAR;    // Slave address
    uint16_t              I2CDXR;    // Data transmit
    union  I2CMDR_REG   I2CMDR;    // Mode
    union  I2CISRC_REG  I2CISRC;   // Interrupt source
    union  I2CEMDR_REG  I2CEMDR;   // Extended mode
    union  I2CPSC_REG   I2CPSC;    // Pre-scaler
    uint16_t              rsvd2[19]; // reserved
    union  I2CFFTX_REG  I2CFFTX;   // Transmit FIFO
    union  I2CFFRX_REG  I2CFFRX;   // Recieve FIFO
};



//---------------------------------------------------------------------------
// External References & Function Declarations:
//
extern volatile struct I2C_REGS I2caRegs;

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of F2802x_I2C_H definition

//===========================================================================
// End of file.
//===========================================================================
