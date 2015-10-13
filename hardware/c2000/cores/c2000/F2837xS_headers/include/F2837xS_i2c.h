//###########################################################################
//
// FILE:    F2837xS_i2c.h
//
// TITLE:   F2837xS Device I2C Register Definitions.
//
//###########################################################################
// $TI Release: F2837xS Support Library v170 $
// $Release Date: Mon Sep 21 16:56:07 CDT 2015 $
// $Copyright: Copyright (C) 2014-2015 Texas Instruments Incorporated -
//             http://www.ti.com/ ALL RIGHTS RESERVED $
//###########################################################################

#ifndef __F2837xS_I2C_H__
#define __F2837xS_I2C_H__

#ifdef __cplusplus 
extern "C" {
#endif 


//---------------------------------------------------------------------------
// I2C Individual Register Bit Definitions:

struct I2COAR_BITS {                    // bits description
    Uint16 OAR:10;                      // 9:0 I2C Own address 
    Uint16 rsvd1:6;                     // 15:10 Reserved
};

union I2COAR_REG {
    Uint16  all;
    struct  I2COAR_BITS  bit;
};

struct I2CIER_BITS {                    // bits description
    Uint16 ARBL:1;                      // 0 Arbitration-lost interrupt enable
    Uint16 NACK:1;                      // 1 No-acknowledgment interrupt enable
    Uint16 ARDY:1;                      // 2 Register-access-ready interrupt enable
    Uint16 RRDY:1;                      // 3 Receive-data-ready interrupt enable
    Uint16 XRDY:1;                      // 4 Transmit-data-ready interrupt enable
    Uint16 SCD:1;                       // 5 Stop condition detected interrupt enable
    Uint16 AAS:1;                       // 6 Addressed as slave interrupt enable
    Uint16 rsvd1:9;                     // 15:7 Reserved
};

union I2CIER_REG {
    Uint16  all;
    struct  I2CIER_BITS  bit;
};

struct I2CSTR_BITS {                    // bits description
    Uint16 ARBL:1;                      // 0 Arbitration-lost interrupt flag bit
    Uint16 NACK:1;                      // 1 No-acknowledgment interrupt flag bit.
    Uint16 ARDY:1;                      // 2 Register-access-ready interrupt flag bit
    Uint16 RRDY:1;                      // 3 Receive-data-ready interrupt flag bit.
    Uint16 XRDY:1;                      // 4 Transmit-data-ready interrupt flag bit.
    Uint16 SCD:1;                       // 5 Stop condition detected bit.
    Uint16 rsvd1:2;                     // 7:6 Reserved
    Uint16 AD0:1;                       // 8 Address 0 bits
    Uint16 AAS:1;                       // 9 Addressed-as-slave bit
    Uint16 XSMT:1;                      // 10 Transmit shift register empty bit.
    Uint16 RSFULL:1;                    // 11 Receive shift register full bit.
    Uint16 BB:1;                        // 12 Bus busy bit.
    Uint16 NACKSNT:1;                   // 13 NACK sent bit.
    Uint16 SDIR:1;                      // 14 Slave direction bit
    Uint16 rsvd2:1;                     // 15 Reserved
};

union I2CSTR_REG {
    Uint16  all;
    struct  I2CSTR_BITS  bit;
};

struct I2CDRR_BITS {                    // bits description
    Uint16 DATA:8;                      // 7:0 Receive data
    Uint16 rsvd1:8;                     // 15:8 Reserved
};

union I2CDRR_REG {
    Uint16  all;
    struct  I2CDRR_BITS  bit;
};

struct I2CSAR_BITS {                    // bits description
    Uint16 SAR:10;                      // 9:0 Slave Address
    Uint16 rsvd1:6;                     // 15:10 Reserved
};

union I2CSAR_REG {
    Uint16  all;
    struct  I2CSAR_BITS  bit;
};

struct I2CDXR_BITS {                    // bits description
    Uint16 DATA:8;                      // 7:0 Transmit data
    Uint16 rsvd1:8;                     // 15:8 Reserved
};

union I2CDXR_REG {
    Uint16  all;
    struct  I2CDXR_BITS  bit;
};

struct I2CMDR_BITS {                    // bits description
    Uint16 BC:3;                        // 2:0 Bit count bits.
    Uint16 FDF:1;                       // 3 Free Data Format 
    Uint16 STB:1;                       // 4 START Byte Mode
    Uint16 IRS:1;                       // 5 I2C Module Reset 
    Uint16 DLB:1;                       // 6 Digital Loopback Mode 
    Uint16 RM:1;                        // 7 Repeat Mode
    Uint16 XA:1;                        // 8 Expanded Address Mode 
    Uint16 TRX:1;                       // 9 Transmitter Mode 
    Uint16 MST:1;                       // 10 Master Mode 
    Uint16 STP:1;                       // 11 STOP Condition 
    Uint16 rsvd1:1;                     // 12 Reserved
    Uint16 STT:1;                       // 13 START condition bit
    Uint16 FREE:1;                      // 14 Debug Action
    Uint16 NACKMOD:1;                   // 15 NACK mode bit
};

union I2CMDR_REG {
    Uint16  all;
    struct  I2CMDR_BITS  bit;
};

struct I2CISRC_BITS {                   // bits description
    Uint16 INTCODE:3;                   // 2:0 Interrupt code bits.
    Uint16 rsvd1:5;                     // 7:3 Reserved
    Uint16 rsvd2:4;                     // 11:8 Reserved
    Uint16 rsvd3:4;                     // 15:12 Reserved
};

union I2CISRC_REG {
    Uint16  all;
    struct  I2CISRC_BITS  bit;
};

struct I2CEMDR_BITS {                   // bits description
    Uint16 BC:1;                        // 0 Backwards compatibility mode
    Uint16 rsvd1:15;                    // 15:1 Reserved
};

union I2CEMDR_REG {
    Uint16  all;
    struct  I2CEMDR_BITS  bit;
};

struct I2CPSC_BITS {                    // bits description
    Uint16 IPSC:8;                      // 7:0 I2C Prescaler Divide Down 
    Uint16 rsvd1:8;                     // 15:8 Reserved
};

union I2CPSC_REG {
    Uint16  all;
    struct  I2CPSC_BITS  bit;
};

struct I2CFFTX_BITS {                   // bits description
    Uint16 TXFFIL:5;                    // 4:0 Transmit FIFO Interrupt Level 
    Uint16 TXFFIENA:1;                  // 5 Transmit FIFO Interrupt Enable
    Uint16 TXFFINTCLR:1;                // 6 Transmit FIFO Interrupt Flag Clear 
    Uint16 TXFFINT:1;                   // 7 Transmit FIFO Interrupt Flag
    Uint16 TXFFST:5;                    // 12:8 Transmit FIFO Status 
    Uint16 TXFFRST:1;                   // 13 Transmit FIFO Reset 
    Uint16 I2CFFEN:1;                   // 14 Transmit FIFO Enable 
    Uint16 rsvd1:1;                     // 15 Reserved
};

union I2CFFTX_REG {
    Uint16  all;
    struct  I2CFFTX_BITS  bit;
};

struct I2CFFRX_BITS {                   // bits description
    Uint16 RXFFIL:5;                    // 4:0 Receive FIFO Interrupt Level 
    Uint16 RXFFIENA:1;                  // 5 Receive FIFO Interrupt Enable 
    Uint16 RXFFINTCLR:1;                // 6 Receive FIFO Interrupt Flag Clear 
    Uint16 RXFFINT:1;                   // 7 Receive FIFO Interrupt Flag
    Uint16 RXFFST:5;                    // 12:8 Receive FIFO Status 
    Uint16 RXFFRST:1;                   // 13 Receive FIFO Reset 
    Uint16 rsvd1:2;                     // 15:14 Reserved
};

union I2CFFRX_REG {
    Uint16  all;
    struct  I2CFFRX_BITS  bit;
};

struct I2C_REGS {
    union   I2COAR_REG                       I2COAR;                       // I2C Own address 
    union   I2CIER_REG                       I2CIER;                       // I2C Interrupt Enable 
    union   I2CSTR_REG                       I2CSTR;                       // I2C Status
    Uint16                                   I2CCLKL;                      // I2C Clock low-time divider 
    Uint16                                   I2CCLKH;                      // I2C Clock high-time divider 
    Uint16                                   I2CCNT;                       // I2C Data count
    union   I2CDRR_REG                       I2CDRR;                       // I2C Data receive
    union   I2CSAR_REG                       I2CSAR;                       // I2C Slave address
    union   I2CDXR_REG                       I2CDXR;                       // I2C Data Transmit 
    union   I2CMDR_REG                       I2CMDR;                       // I2C Mode 
    union   I2CISRC_REG                      I2CISRC;                      // I2C Interrupt Source
    union   I2CEMDR_REG                      I2CEMDR;                      // I2C Extended Mode 
    union   I2CPSC_REG                       I2CPSC;                       // I2C Prescaler 
    Uint16                                   rsvd1[19];                    // Reserved
    union   I2CFFTX_REG                      I2CFFTX;                      // I2C FIFO Transmit 
    union   I2CFFRX_REG                      I2CFFRX;                      // I2C FIFO Receive 
};

//---------------------------------------------------------------------------
// I2C External References & Function Declarations:
//
extern volatile struct I2C_REGS I2caRegs;
extern volatile struct I2C_REGS I2cbRegs;
#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================
