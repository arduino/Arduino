// TI File $Revision: /main/3 $
// Checkin $Date: October 6, 2010   15:08:36 $
//###########################################################################
//
// FILE:   DSP2802x_I2c.h
//
// TITLE:  DSP2802x Inter-Integrated Circuit (I2C) Module
//         Register Bit Definitions.
//
//###########################################################################
// $TI Release: f2802x Support Library v210 $
// $Release Date: Mon Sep 17 09:13:31 CDT 2012 $
//###########################################################################

#ifndef DSP2802x_I2C_H
#define DSP2802x_I2C_H

#ifdef __cplusplus
extern "C" {
#endif

//----------------------------------------------------
// I2C interrupt vector register bit definitions */
struct I2CISRC_BITS {         // bits   description
   Uint16 INTCODE:3;          // 2:0    Interrupt code
   Uint16 rsvd1:13;           // 15:3   reserved
};

union I2CISRC_REG {
   Uint16                 all;
   struct I2CISRC_BITS    bit;
};

//----------------------------------------------------
// I2C interrupt mask register bit definitions */
struct I2CIER_BITS {          // bits   description
   Uint16 ARBL:1;               // 0      Arbitration lost interrupt
   Uint16 NACK:1;             // 1      No ack interrupt
   Uint16 ARDY:1;             // 2      Register access ready interrupt
   Uint16 RRDY:1;             // 3      Recieve data ready interrupt
   Uint16 XRDY:1;             // 4      Transmit data ready interrupt
   Uint16 SCD:1;              // 5      Stop condition detection
   Uint16 AAS:1;              // 6      Address as slave
   Uint16 rsvd:9;             // 15:7   reserved
};

union I2CIER_REG {
   Uint16                 all;
   struct I2CIER_BITS     bit;
};

//----------------------------------------------------
// I2C status register bit definitions */
struct I2CSTR_BITS {          // bits   description
   Uint16 ARBL:1;               // 0      Arbitration lost interrupt
   Uint16 NACK:1;             // 1      No ack interrupt
   Uint16 ARDY:1;             // 2      Register access ready interrupt
   Uint16 RRDY:1;             // 3      Recieve data ready interrupt
   Uint16 XRDY:1;             // 4      Transmit data ready interrupt
   Uint16 SCD:1;              // 5      Stop condition detection
   Uint16 rsvd1:2;            // 7:6    reserved
   Uint16 AD0:1;              // 8      Address Zero
   Uint16 AAS:1;              // 9      Address as slave
   Uint16 XSMT:1;             // 10     XMIT shift empty
   Uint16 RSFULL:1;           // 11     Recieve shift full
   Uint16 BB:1;               // 12     Bus busy
   Uint16 NACKSNT:1;          // 13     A no ack sent
   Uint16 SDIR:1;             // 14     Slave direction
   Uint16 rsvd2:1;            // 15     reserved
};

union I2CSTR_REG {
   Uint16                 all;
   struct I2CSTR_BITS     bit;
};

//----------------------------------------------------
// I2C mode control register bit definitions */
struct I2CMDR_BITS {          // bits   description
   Uint16 BC:3;               // 2:0    Bit count
   Uint16 FDF:1;              // 3      Free data format
   Uint16 STB:1;              // 4      Start byte
   Uint16 IRS:1;              // 5      I2C Reset not
   Uint16 DLB:1;              // 6      Digital loopback
   Uint16 RM:1;               // 7      Repeat mode
   Uint16 XA:1;               // 8      Expand address
   Uint16 TRX:1;              // 9      Transmitter/reciever
   Uint16 MST:1;              // 10     Master/slave
   Uint16 STP:1;              // 11     Stop condition
   Uint16 rsvd1:1;            // 12     reserved
   Uint16 STT:1;              // 13     Start condition
   Uint16 FREE:1;             // 14     Emulation mode
   Uint16 NACKMOD:1;          // 15     No Ack mode
};

union I2CMDR_REG {
   Uint16                 all;
   struct I2CMDR_BITS     bit;
};

//----------------------------------------------------
// I2C extended mode control register bit definitions */
struct I2CEMDR_BITS {          // bits   description
   Uint16 BCM:1;               // 0      Bit count
   Uint16 rsvd1:15;            // 15:1   reserved
};

union I2CEMDR_REG {
   Uint16                 all;
   struct I2CEMDR_BITS    bit;
};

//----------------------------------------------------
// I2C pre-scaler register bit definitions */
struct I2CPSC_BITS {         // bits   description
   Uint16 IPSC:8;            // 7:0    pre-scaler
   Uint16 rsvd1:8;           // 15:8   reserved
};

union I2CPSC_REG {
   Uint16                 all;
   struct I2CPSC_BITS     bit;
};

//----------------------------------------------------
// TX FIFO control register bit definitions */
struct I2CFFTX_BITS {         // bits   description
   Uint16 TXFFIL:5;           // 4:0    FIFO interrupt level
   Uint16 TXFFIENA:1;         // 5      FIFO interrupt enable/disable
   Uint16 TXFFINTCLR:1;       // 6      FIFO clear
   Uint16 TXFFINT:1;          // 7      FIFO interrupt flag
   Uint16 TXFFST:5;           // 12:8   FIFO level status
   Uint16 TXFFRST:1;          // 13     FIFO reset
   Uint16 I2CFFEN:1;          // 14     enable/disable TX & RX FIFOs
   Uint16 rsvd1:1;            // 15     reserved

};

union I2CFFTX_REG {
   Uint16                 all;
   struct I2CFFTX_BITS    bit;
};

//----------------------------------------------------
// RX FIFO control register bit definitions */
struct I2CFFRX_BITS {         // bits   description
   Uint16 RXFFIL:5;           // 4:0    FIFO interrupt level
   Uint16 RXFFIENA:1;         // 5      FIFO interrupt enable/disable
   Uint16 RXFFINTCLR:1;       // 6      FIFO clear
   Uint16 RXFFINT:1;          // 7      FIFO interrupt flag
   Uint16 RXFFST:5;           // 12:8   FIFO level
   Uint16 RXFFRST:1;          // 13     FIFO reset
   Uint16 rsvd1:2;            // 15:14  reserved
};

union I2CFFRX_REG {
   Uint16                 all;
   struct I2CFFRX_BITS    bit;
};

//----------------------------------------------------

struct I2C_REGS {
   Uint16              I2COAR;    // Own address register
   union  I2CIER_REG   I2CIER;    // Interrupt enable
   union  I2CSTR_REG   I2CSTR;    // Interrupt status
   Uint16              I2CCLKL;   // Clock divider low
   Uint16              I2CCLKH;   // Clock divider high
   Uint16              I2CCNT;    // Data count
   Uint16              I2CDRR;    // Data recieve
   Uint16              I2CSAR;    // Slave address
   Uint16              I2CDXR;    // Data transmit
   union  I2CMDR_REG   I2CMDR;    // Mode
   union  I2CISRC_REG  I2CISRC;   // Interrupt source
   union  I2CEMDR_REG  I2CEMDR;   // Extended mode
   union  I2CPSC_REG   I2CPSC;    // Pre-scaler
   Uint16              rsvd2[19]; // reserved
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

#endif  // end of DSP2802x_I2C_H definition

//===========================================================================
// End of file.
//===========================================================================
