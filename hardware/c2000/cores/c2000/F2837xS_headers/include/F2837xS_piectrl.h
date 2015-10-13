//###########################################################################
//
// FILE:    F2837xS_piectrl.h
//
// TITLE:   F2837xS Device PIECTRL Register Definitions.
//
//###########################################################################
// $TI Release: F2837xS Support Library v170 $
// $Release Date: Mon Sep 21 16:56:07 CDT 2015 $
// $Copyright: Copyright (C) 2014-2015 Texas Instruments Incorporated -
//             http://www.ti.com/ ALL RIGHTS RESERVED $
//###########################################################################

#ifndef __F2837xS_PIECTRL_H__
#define __F2837xS_PIECTRL_H__

#ifdef __cplusplus 
extern "C" {
#endif 


//---------------------------------------------------------------------------
// PIECTRL Individual Register Bit Definitions:

struct PIECTRL_BITS {                   // bits description
    Uint16 ENPIE:1;                     // 0 PIE Enable
    Uint16 PIEVECT:15;                  // 15:1 PIE Vector Address
};

union PIECTRL_REG {
    Uint16  all;
    struct  PIECTRL_BITS  bit;
};

struct PIEACK_BITS {                    // bits description
    Uint16 ACK1:1;                      // 0 Acknowledge PIE Interrupt Group 1
    Uint16 ACK2:1;                      // 1 Acknowledge PIE Interrupt Group 2
    Uint16 ACK3:1;                      // 2 Acknowledge PIE Interrupt Group 3
    Uint16 ACK4:1;                      // 3 Acknowledge PIE Interrupt Group 4
    Uint16 ACK5:1;                      // 4 Acknowledge PIE Interrupt Group 5
    Uint16 ACK6:1;                      // 5 Acknowledge PIE Interrupt Group 6
    Uint16 ACK7:1;                      // 6 Acknowledge PIE Interrupt Group 7
    Uint16 ACK8:1;                      // 7 Acknowledge PIE Interrupt Group 8
    Uint16 ACK9:1;                      // 8 Acknowledge PIE Interrupt Group 9
    Uint16 ACK10:1;                     // 9 Acknowledge PIE Interrupt Group 10
    Uint16 ACK11:1;                     // 10 Acknowledge PIE Interrupt Group 11
    Uint16 ACK12:1;                     // 11 Acknowledge PIE Interrupt Group 12
    Uint16 rsvd1:4;                     // 15:12 Reserved
};

union PIEACK_REG {
    Uint16  all;
    struct  PIEACK_BITS  bit;
};

struct PIEIER1_BITS {                   // bits description
    Uint16 INTx1:1;                     // 0 Interrupt Enable for INT1.1
    Uint16 INTx2:1;                     // 1 Interrupt Enable for INT1.2
    Uint16 INTx3:1;                     // 2 Interrupt Enable for INT1.3
    Uint16 INTx4:1;                     // 3 Interrupt Enable for INT1.4
    Uint16 INTx5:1;                     // 4 Interrupt Enable for INT1.5
    Uint16 INTx6:1;                     // 5 Interrupt Enable for INT1.6
    Uint16 INTx7:1;                     // 6 Interrupt Enable for INT1.7
    Uint16 INTx8:1;                     // 7 Interrupt Enable for INT1.8
    Uint16 INTx9:1;                     // 8 Interrupt Enable for INT1.9
    Uint16 INTx10:1;                    // 9 Interrupt Enable for INT1.10
    Uint16 INTx11:1;                    // 10 Interrupt Enable for INT1.11
    Uint16 INTx12:1;                    // 11 Interrupt Enable for INT1.12
    Uint16 INTx13:1;                    // 12 Interrupt Enable for INT1.13
    Uint16 INTx14:1;                    // 13 Interrupt Enable for INT1.14
    Uint16 INTx15:1;                    // 14 Interrupt Enable for INT1.15
    Uint16 INTx16:1;                    // 15 Interrupt Enable for INT1.16
};

union PIEIER1_REG {
    Uint16  all;
    struct  PIEIER1_BITS  bit;
};

struct PIEIFR1_BITS {                   // bits description
    Uint16 INTx1:1;                     // 0 Interrupt Flag for INT1.1
    Uint16 INTx2:1;                     // 1 Interrupt Flag for INT1.2
    Uint16 INTx3:1;                     // 2 Interrupt Flag for INT1.3
    Uint16 INTx4:1;                     // 3 Interrupt Flag for INT1.4
    Uint16 INTx5:1;                     // 4 Interrupt Flag for INT1.5
    Uint16 INTx6:1;                     // 5 Interrupt Flag for INT1.6
    Uint16 INTx7:1;                     // 6 Interrupt Flag for INT1.7
    Uint16 INTx8:1;                     // 7 Interrupt Flag for INT1.8
    Uint16 INTx9:1;                     // 8 Interrupt Flag for INT1.9
    Uint16 INTx10:1;                    // 9 Interrupt Flag for INT1.10
    Uint16 INTx11:1;                    // 10 Interrupt Flag for INT1.11
    Uint16 INTx12:1;                    // 11 Interrupt Flag for INT1.12
    Uint16 INTx13:1;                    // 12 Interrupt Flag for INT1.13
    Uint16 INTx14:1;                    // 13 Interrupt Flag for INT1.14
    Uint16 INTx15:1;                    // 14 Interrupt Flag for INT1.15
    Uint16 INTx16:1;                    // 15 Interrupt Flag for INT1.16
};

union PIEIFR1_REG {
    Uint16  all;
    struct  PIEIFR1_BITS  bit;
};

struct PIEIER2_BITS {                   // bits description
    Uint16 INTx1:1;                     // 0 Interrupt Enable for INT2.1
    Uint16 INTx2:1;                     // 1 Interrupt Enable for INT2.2
    Uint16 INTx3:1;                     // 2 Interrupt Enable for INT2.3
    Uint16 INTx4:1;                     // 3 Interrupt Enable for INT2.4
    Uint16 INTx5:1;                     // 4 Interrupt Enable for INT2.5
    Uint16 INTx6:1;                     // 5 Interrupt Enable for INT2.6
    Uint16 INTx7:1;                     // 6 Interrupt Enable for INT2.7
    Uint16 INTx8:1;                     // 7 Interrupt Enable for INT2.8
    Uint16 INTx9:1;                     // 8 Interrupt Enable for INT2.9
    Uint16 INTx10:1;                    // 9 Interrupt Enable for INT2.10
    Uint16 INTx11:1;                    // 10 Interrupt Enable for INT2.11
    Uint16 INTx12:1;                    // 11 Interrupt Enable for INT2.12
    Uint16 INTx13:1;                    // 12 Interrupt Enable for INT2.13
    Uint16 INTx14:1;                    // 13 Interrupt Enable for INT2.14
    Uint16 INTx15:1;                    // 14 Interrupt Enable for INT2.15
    Uint16 INTx16:1;                    // 15 Interrupt Enable for INT2.16
};

union PIEIER2_REG {
    Uint16  all;
    struct  PIEIER2_BITS  bit;
};

struct PIEIFR2_BITS {                   // bits description
    Uint16 INTx1:1;                     // 0 Interrupt Flag for INT2.1
    Uint16 INTx2:1;                     // 1 Interrupt Flag for INT2.2
    Uint16 INTx3:1;                     // 2 Interrupt Flag for INT2.3
    Uint16 INTx4:1;                     // 3 Interrupt Flag for INT2.4
    Uint16 INTx5:1;                     // 4 Interrupt Flag for INT2.5
    Uint16 INTx6:1;                     // 5 Interrupt Flag for INT2.6
    Uint16 INTx7:1;                     // 6 Interrupt Flag for INT2.7
    Uint16 INTx8:1;                     // 7 Interrupt Flag for INT2.8
    Uint16 INTx9:1;                     // 8 Interrupt Flag for INT2.9
    Uint16 INTx10:1;                    // 9 Interrupt Flag for INT2.10
    Uint16 INTx11:1;                    // 10 Interrupt Flag for INT2.11
    Uint16 INTx12:1;                    // 11 Interrupt Flag for INT2.12
    Uint16 INTx13:1;                    // 12 Interrupt Flag for INT2.13
    Uint16 INTx14:1;                    // 13 Interrupt Flag for INT2.14
    Uint16 INTx15:1;                    // 14 Interrupt Flag for INT2.15
    Uint16 INTx16:1;                    // 15 Interrupt Flag for INT2.16
};

union PIEIFR2_REG {
    Uint16  all;
    struct  PIEIFR2_BITS  bit;
};

struct PIEIER3_BITS {                   // bits description
    Uint16 INTx1:1;                     // 0 Interrupt Enable for INT3.1
    Uint16 INTx2:1;                     // 1 Interrupt Enable for INT3.2
    Uint16 INTx3:1;                     // 2 Interrupt Enable for INT3.3
    Uint16 INTx4:1;                     // 3 Interrupt Enable for INT3.4
    Uint16 INTx5:1;                     // 4 Interrupt Enable for INT3.5
    Uint16 INTx6:1;                     // 5 Interrupt Enable for INT3.6
    Uint16 INTx7:1;                     // 6 Interrupt Enable for INT3.7
    Uint16 INTx8:1;                     // 7 Interrupt Enable for INT3.8
    Uint16 INTx9:1;                     // 8 Interrupt Enable for INT3.9
    Uint16 INTx10:1;                    // 9 Interrupt Enable for INT3.10
    Uint16 INTx11:1;                    // 10 Interrupt Enable for INT3.11
    Uint16 INTx12:1;                    // 11 Interrupt Enable for INT3.12
    Uint16 INTx13:1;                    // 12 Interrupt Enable for INT3.13
    Uint16 INTx14:1;                    // 13 Interrupt Enable for INT3.14
    Uint16 INTx15:1;                    // 14 Interrupt Enable for INT3.15
    Uint16 INTx16:1;                    // 15 Interrupt Enable for INT3.16
};

union PIEIER3_REG {
    Uint16  all;
    struct  PIEIER3_BITS  bit;
};

struct PIEIFR3_BITS {                   // bits description
    Uint16 INTx1:1;                     // 0 Interrupt Flag for INT3.1
    Uint16 INTx2:1;                     // 1 Interrupt Flag for INT3.2
    Uint16 INTx3:1;                     // 2 Interrupt Flag for INT3.3
    Uint16 INTx4:1;                     // 3 Interrupt Flag for INT3.4
    Uint16 INTx5:1;                     // 4 Interrupt Flag for INT3.5
    Uint16 INTx6:1;                     // 5 Interrupt Flag for INT3.6
    Uint16 INTx7:1;                     // 6 Interrupt Flag for INT3.7
    Uint16 INTx8:1;                     // 7 Interrupt Flag for INT3.8
    Uint16 INTx9:1;                     // 8 Interrupt Flag for INT3.9
    Uint16 INTx10:1;                    // 9 Interrupt Flag for INT3.10
    Uint16 INTx11:1;                    // 10 Interrupt Flag for INT3.11
    Uint16 INTx12:1;                    // 11 Interrupt Flag for INT3.12
    Uint16 INTx13:1;                    // 12 Interrupt Flag for INT3.13
    Uint16 INTx14:1;                    // 13 Interrupt Flag for INT3.14
    Uint16 INTx15:1;                    // 14 Interrupt Flag for INT3.15
    Uint16 INTx16:1;                    // 15 Interrupt Flag for INT3.16
};

union PIEIFR3_REG {
    Uint16  all;
    struct  PIEIFR3_BITS  bit;
};

struct PIEIER4_BITS {                   // bits description
    Uint16 INTx1:1;                     // 0 Interrupt Enable for INT4.1
    Uint16 INTx2:1;                     // 1 Interrupt Enable for INT4.2
    Uint16 INTx3:1;                     // 2 Interrupt Enable for INT4.3
    Uint16 INTx4:1;                     // 3 Interrupt Enable for INT4.4
    Uint16 INTx5:1;                     // 4 Interrupt Enable for INT4.5
    Uint16 INTx6:1;                     // 5 Interrupt Enable for INT4.6
    Uint16 INTx7:1;                     // 6 Interrupt Enable for INT4.7
    Uint16 INTx8:1;                     // 7 Interrupt Enable for INT4.8
    Uint16 INTx9:1;                     // 8 Interrupt Enable for INT4.9
    Uint16 INTx10:1;                    // 9 Interrupt Enable for INT4.10
    Uint16 INTx11:1;                    // 10 Interrupt Enable for INT4.11
    Uint16 INTx12:1;                    // 11 Interrupt Enable for INT4.12
    Uint16 INTx13:1;                    // 12 Interrupt Enable for INT4.13
    Uint16 INTx14:1;                    // 13 Interrupt Enable for INT4.14
    Uint16 INTx15:1;                    // 14 Interrupt Enable for INT4.15
    Uint16 INTx16:1;                    // 15 Interrupt Enable for INT4.16
};

union PIEIER4_REG {
    Uint16  all;
    struct  PIEIER4_BITS  bit;
};

struct PIEIFR4_BITS {                   // bits description
    Uint16 INTx1:1;                     // 0 Interrupt Flag for INT4.1
    Uint16 INTx2:1;                     // 1 Interrupt Flag for INT4.2
    Uint16 INTx3:1;                     // 2 Interrupt Flag for INT4.3
    Uint16 INTx4:1;                     // 3 Interrupt Flag for INT4.4
    Uint16 INTx5:1;                     // 4 Interrupt Flag for INT4.5
    Uint16 INTx6:1;                     // 5 Interrupt Flag for INT4.6
    Uint16 INTx7:1;                     // 6 Interrupt Flag for INT4.7
    Uint16 INTx8:1;                     // 7 Interrupt Flag for INT4.8
    Uint16 INTx9:1;                     // 8 Interrupt Flag for INT4.9
    Uint16 INTx10:1;                    // 9 Interrupt Flag for INT4.10
    Uint16 INTx11:1;                    // 10 Interrupt Flag for INT4.11
    Uint16 INTx12:1;                    // 11 Interrupt Flag for INT4.12
    Uint16 INTx13:1;                    // 12 Interrupt Flag for INT4.13
    Uint16 INTx14:1;                    // 13 Interrupt Flag for INT4.14
    Uint16 INTx15:1;                    // 14 Interrupt Flag for INT4.15
    Uint16 INTx16:1;                    // 15 Interrupt Flag for INT4.16
};

union PIEIFR4_REG {
    Uint16  all;
    struct  PIEIFR4_BITS  bit;
};

struct PIEIER5_BITS {                   // bits description
    Uint16 INTx1:1;                     // 0 Interrupt Enable for INT5.1
    Uint16 INTx2:1;                     // 1 Interrupt Enable for INT5.2
    Uint16 INTx3:1;                     // 2 Interrupt Enable for INT5.3
    Uint16 INTx4:1;                     // 3 Interrupt Enable for INT5.4
    Uint16 INTx5:1;                     // 4 Interrupt Enable for INT5.5
    Uint16 INTx6:1;                     // 5 Interrupt Enable for INT5.6
    Uint16 INTx7:1;                     // 6 Interrupt Enable for INT5.7
    Uint16 INTx8:1;                     // 7 Interrupt Enable for INT5.8
    Uint16 INTx9:1;                     // 8 Interrupt Enable for INT5.9
    Uint16 INTx10:1;                    // 9 Interrupt Enable for INT5.10
    Uint16 INTx11:1;                    // 10 Interrupt Enable for INT5.11
    Uint16 INTx12:1;                    // 11 Interrupt Enable for INT5.12
    Uint16 INTx13:1;                    // 12 Interrupt Enable for INT5.13
    Uint16 INTx14:1;                    // 13 Interrupt Enable for INT5.14
    Uint16 INTx15:1;                    // 14 Interrupt Enable for INT5.15
    Uint16 INTx16:1;                    // 15 Interrupt Enable for INT5.16
};

union PIEIER5_REG {
    Uint16  all;
    struct  PIEIER5_BITS  bit;
};

struct PIEIFR5_BITS {                   // bits description
    Uint16 INTx1:1;                     // 0 Interrupt Flag for INT5.1
    Uint16 INTx2:1;                     // 1 Interrupt Flag for INT5.2
    Uint16 INTx3:1;                     // 2 Interrupt Flag for INT5.3
    Uint16 INTx4:1;                     // 3 Interrupt Flag for INT5.4
    Uint16 INTx5:1;                     // 4 Interrupt Flag for INT5.5
    Uint16 INTx6:1;                     // 5 Interrupt Flag for INT5.6
    Uint16 INTx7:1;                     // 6 Interrupt Flag for INT5.7
    Uint16 INTx8:1;                     // 7 Interrupt Flag for INT5.8
    Uint16 INTx9:1;                     // 8 Interrupt Flag for INT5.9
    Uint16 INTx10:1;                    // 9 Interrupt Flag for INT5.10
    Uint16 INTx11:1;                    // 10 Interrupt Flag for INT5.11
    Uint16 INTx12:1;                    // 11 Interrupt Flag for INT5.12
    Uint16 INTx13:1;                    // 12 Interrupt Flag for INT5.13
    Uint16 INTx14:1;                    // 13 Interrupt Flag for INT5.14
    Uint16 INTx15:1;                    // 14 Interrupt Flag for INT5.15
    Uint16 INTx16:1;                    // 15 Interrupt Flag for INT5.16
};

union PIEIFR5_REG {
    Uint16  all;
    struct  PIEIFR5_BITS  bit;
};

struct PIEIER6_BITS {                   // bits description
    Uint16 INTx1:1;                     // 0 Interrupt Enable for INT6.1
    Uint16 INTx2:1;                     // 1 Interrupt Enable for INT6.2
    Uint16 INTx3:1;                     // 2 Interrupt Enable for INT6.3
    Uint16 INTx4:1;                     // 3 Interrupt Enable for INT6.4
    Uint16 INTx5:1;                     // 4 Interrupt Enable for INT6.5
    Uint16 INTx6:1;                     // 5 Interrupt Enable for INT6.6
    Uint16 INTx7:1;                     // 6 Interrupt Enable for INT6.7
    Uint16 INTx8:1;                     // 7 Interrupt Enable for INT6.8
    Uint16 INTx9:1;                     // 8 Interrupt Enable for INT6.9
    Uint16 INTx10:1;                    // 9 Interrupt Enable for INT6.10
    Uint16 INTx11:1;                    // 10 Interrupt Enable for INT6.11
    Uint16 INTx12:1;                    // 11 Interrupt Enable for INT6.12
    Uint16 INTx13:1;                    // 12 Interrupt Enable for INT6.13
    Uint16 INTx14:1;                    // 13 Interrupt Enable for INT6.14
    Uint16 INTx15:1;                    // 14 Interrupt Enable for INT6.15
    Uint16 INTx16:1;                    // 15 Interrupt Enable for INT6.16
};

union PIEIER6_REG {
    Uint16  all;
    struct  PIEIER6_BITS  bit;
};

struct PIEIFR6_BITS {                   // bits description
    Uint16 INTx1:1;                     // 0 Interrupt Flag for INT6.1
    Uint16 INTx2:1;                     // 1 Interrupt Flag for INT6.2
    Uint16 INTx3:1;                     // 2 Interrupt Flag for INT6.3
    Uint16 INTx4:1;                     // 3 Interrupt Flag for INT6.4
    Uint16 INTx5:1;                     // 4 Interrupt Flag for INT6.5
    Uint16 INTx6:1;                     // 5 Interrupt Flag for INT6.6
    Uint16 INTx7:1;                     // 6 Interrupt Flag for INT6.7
    Uint16 INTx8:1;                     // 7 Interrupt Flag for INT6.8
    Uint16 INTx9:1;                     // 8 Interrupt Flag for INT6.9
    Uint16 INTx10:1;                    // 9 Interrupt Flag for INT6.10
    Uint16 INTx11:1;                    // 10 Interrupt Flag for INT6.11
    Uint16 INTx12:1;                    // 11 Interrupt Flag for INT6.12
    Uint16 INTx13:1;                    // 12 Interrupt Flag for INT6.13
    Uint16 INTx14:1;                    // 13 Interrupt Flag for INT6.14
    Uint16 INTx15:1;                    // 14 Interrupt Flag for INT6.15
    Uint16 INTx16:1;                    // 15 Interrupt Flag for INT6.16
};

union PIEIFR6_REG {
    Uint16  all;
    struct  PIEIFR6_BITS  bit;
};

struct PIEIER7_BITS {                   // bits description
    Uint16 INTx1:1;                     // 0 Interrupt Enable for INT7.1
    Uint16 INTx2:1;                     // 1 Interrupt Enable for INT7.2
    Uint16 INTx3:1;                     // 2 Interrupt Enable for INT7.3
    Uint16 INTx4:1;                     // 3 Interrupt Enable for INT7.4
    Uint16 INTx5:1;                     // 4 Interrupt Enable for INT7.5
    Uint16 INTx6:1;                     // 5 Interrupt Enable for INT7.6
    Uint16 INTx7:1;                     // 6 Interrupt Enable for INT7.7
    Uint16 INTx8:1;                     // 7 Interrupt Enable for INT7.8
    Uint16 INTx9:1;                     // 8 Interrupt Enable for INT7.9
    Uint16 INTx10:1;                    // 9 Interrupt Enable for INT7.10
    Uint16 INTx11:1;                    // 10 Interrupt Enable for INT7.11
    Uint16 INTx12:1;                    // 11 Interrupt Enable for INT7.12
    Uint16 INTx13:1;                    // 12 Interrupt Enable for INT7.13
    Uint16 INTx14:1;                    // 13 Interrupt Enable for INT7.14
    Uint16 INTx15:1;                    // 14 Interrupt Enable for INT7.15
    Uint16 INTx16:1;                    // 15 Interrupt Enable for INT7.16
};

union PIEIER7_REG {
    Uint16  all;
    struct  PIEIER7_BITS  bit;
};

struct PIEIFR7_BITS {                   // bits description
    Uint16 INTx1:1;                     // 0 Interrupt Flag for INT7.1
    Uint16 INTx2:1;                     // 1 Interrupt Flag for INT7.2
    Uint16 INTx3:1;                     // 2 Interrupt Flag for INT7.3
    Uint16 INTx4:1;                     // 3 Interrupt Flag for INT7.4
    Uint16 INTx5:1;                     // 4 Interrupt Flag for INT7.5
    Uint16 INTx6:1;                     // 5 Interrupt Flag for INT7.6
    Uint16 INTx7:1;                     // 6 Interrupt Flag for INT7.7
    Uint16 INTx8:1;                     // 7 Interrupt Flag for INT7.8
    Uint16 INTx9:1;                     // 8 Interrupt Flag for INT7.9
    Uint16 INTx10:1;                    // 9 Interrupt Flag for INT7.10
    Uint16 INTx11:1;                    // 10 Interrupt Flag for INT7.11
    Uint16 INTx12:1;                    // 11 Interrupt Flag for INT7.12
    Uint16 INTx13:1;                    // 12 Interrupt Flag for INT7.13
    Uint16 INTx14:1;                    // 13 Interrupt Flag for INT7.14
    Uint16 INTx15:1;                    // 14 Interrupt Flag for INT7.15
    Uint16 INTx16:1;                    // 15 Interrupt Flag for INT7.16
};

union PIEIFR7_REG {
    Uint16  all;
    struct  PIEIFR7_BITS  bit;
};

struct PIEIER8_BITS {                   // bits description
    Uint16 INTx1:1;                     // 0 Interrupt Enable for INT8.1
    Uint16 INTx2:1;                     // 1 Interrupt Enable for INT8.2
    Uint16 INTx3:1;                     // 2 Interrupt Enable for INT8.3
    Uint16 INTx4:1;                     // 3 Interrupt Enable for INT8.4
    Uint16 INTx5:1;                     // 4 Interrupt Enable for INT8.5
    Uint16 INTx6:1;                     // 5 Interrupt Enable for INT8.6
    Uint16 INTx7:1;                     // 6 Interrupt Enable for INT8.7
    Uint16 INTx8:1;                     // 7 Interrupt Enable for INT8.8
    Uint16 INTx9:1;                     // 8 Interrupt Enable for INT8.9
    Uint16 INTx10:1;                    // 9 Interrupt Enable for INT8.10
    Uint16 INTx11:1;                    // 10 Interrupt Enable for INT8.11
    Uint16 INTx12:1;                    // 11 Interrupt Enable for INT8.12
    Uint16 INTx13:1;                    // 12 Interrupt Enable for INT8.13
    Uint16 INTx14:1;                    // 13 Interrupt Enable for INT8.14
    Uint16 INTx15:1;                    // 14 Interrupt Enable for INT8.15
    Uint16 INTx16:1;                    // 15 Interrupt Enable for INT8.16
};

union PIEIER8_REG {
    Uint16  all;
    struct  PIEIER8_BITS  bit;
};

struct PIEIFR8_BITS {                   // bits description
    Uint16 INTx1:1;                     // 0 Interrupt Flag for INT8.1
    Uint16 INTx2:1;                     // 1 Interrupt Flag for INT8.2
    Uint16 INTx3:1;                     // 2 Interrupt Flag for INT8.3
    Uint16 INTx4:1;                     // 3 Interrupt Flag for INT8.4
    Uint16 INTx5:1;                     // 4 Interrupt Flag for INT8.5
    Uint16 INTx6:1;                     // 5 Interrupt Flag for INT8.6
    Uint16 INTx7:1;                     // 6 Interrupt Flag for INT8.7
    Uint16 INTx8:1;                     // 7 Interrupt Flag for INT8.8
    Uint16 INTx9:1;                     // 8 Interrupt Flag for INT8.9
    Uint16 INTx10:1;                    // 9 Interrupt Flag for INT8.10
    Uint16 INTx11:1;                    // 10 Interrupt Flag for INT8.11
    Uint16 INTx12:1;                    // 11 Interrupt Flag for INT8.12
    Uint16 INTx13:1;                    // 12 Interrupt Flag for INT8.13
    Uint16 INTx14:1;                    // 13 Interrupt Flag for INT8.14
    Uint16 INTx15:1;                    // 14 Interrupt Flag for INT8.15
    Uint16 INTx16:1;                    // 15 Interrupt Flag for INT8.16
};

union PIEIFR8_REG {
    Uint16  all;
    struct  PIEIFR8_BITS  bit;
};

struct PIEIER9_BITS {                   // bits description
    Uint16 INTx1:1;                     // 0 Interrupt Enable for INT9.1
    Uint16 INTx2:1;                     // 1 Interrupt Enable for INT9.2
    Uint16 INTx3:1;                     // 2 Interrupt Enable for INT9.3
    Uint16 INTx4:1;                     // 3 Interrupt Enable for INT9.4
    Uint16 INTx5:1;                     // 4 Interrupt Enable for INT9.5
    Uint16 INTx6:1;                     // 5 Interrupt Enable for INT9.6
    Uint16 INTx7:1;                     // 6 Interrupt Enable for INT9.7
    Uint16 INTx8:1;                     // 7 Interrupt Enable for INT9.8
    Uint16 INTx9:1;                     // 8 Interrupt Enable for INT9.9
    Uint16 INTx10:1;                    // 9 Interrupt Enable for INT9.10
    Uint16 INTx11:1;                    // 10 Interrupt Enable for INT9.11
    Uint16 INTx12:1;                    // 11 Interrupt Enable for INT9.12
    Uint16 INTx13:1;                    // 12 Interrupt Enable for INT9.13
    Uint16 INTx14:1;                    // 13 Interrupt Enable for INT9.14
    Uint16 INTx15:1;                    // 14 Interrupt Enable for INT9.15
    Uint16 INTx16:1;                    // 15 Interrupt Enable for INT9.16
};

union PIEIER9_REG {
    Uint16  all;
    struct  PIEIER9_BITS  bit;
};

struct PIEIFR9_BITS {                   // bits description
    Uint16 INTx1:1;                     // 0 Interrupt Flag for INT9.1
    Uint16 INTx2:1;                     // 1 Interrupt Flag for INT9.2
    Uint16 INTx3:1;                     // 2 Interrupt Flag for INT9.3
    Uint16 INTx4:1;                     // 3 Interrupt Flag for INT9.4
    Uint16 INTx5:1;                     // 4 Interrupt Flag for INT9.5
    Uint16 INTx6:1;                     // 5 Interrupt Flag for INT9.6
    Uint16 INTx7:1;                     // 6 Interrupt Flag for INT9.7
    Uint16 INTx8:1;                     // 7 Interrupt Flag for INT9.8
    Uint16 INTx9:1;                     // 8 Interrupt Flag for INT9.9
    Uint16 INTx10:1;                    // 9 Interrupt Flag for INT9.10
    Uint16 INTx11:1;                    // 10 Interrupt Flag for INT9.11
    Uint16 INTx12:1;                    // 11 Interrupt Flag for INT9.12
    Uint16 INTx13:1;                    // 12 Interrupt Flag for INT9.13
    Uint16 INTx14:1;                    // 13 Interrupt Flag for INT9.14
    Uint16 INTx15:1;                    // 14 Interrupt Flag for INT9.15
    Uint16 INTx16:1;                    // 15 Interrupt Flag for INT9.16
};

union PIEIFR9_REG {
    Uint16  all;
    struct  PIEIFR9_BITS  bit;
};

struct PIEIER10_BITS {                  // bits description
    Uint16 INTx1:1;                     // 0 Interrupt Enable for INT10.1
    Uint16 INTx2:1;                     // 1 Interrupt Enable for INT10.2
    Uint16 INTx3:1;                     // 2 Interrupt Enable for INT10.3
    Uint16 INTx4:1;                     // 3 Interrupt Enable for INT10.4
    Uint16 INTx5:1;                     // 4 Interrupt Enable for INT10.5
    Uint16 INTx6:1;                     // 5 Interrupt Enable for INT10.6
    Uint16 INTx7:1;                     // 6 Interrupt Enable for INT10.7
    Uint16 INTx8:1;                     // 7 Interrupt Enable for INT10.8
    Uint16 INTx9:1;                     // 8 Interrupt Enable for INT10.9
    Uint16 INTx10:1;                    // 9 Interrupt Enable for INT10.10
    Uint16 INTx11:1;                    // 10 Interrupt Enable for INT10.11
    Uint16 INTx12:1;                    // 11 Interrupt Enable for INT10.12
    Uint16 INTx13:1;                    // 12 Interrupt Enable for INT10.13
    Uint16 INTx14:1;                    // 13 Interrupt Enable for INT10.14
    Uint16 INTx15:1;                    // 14 Interrupt Enable for INT10.15
    Uint16 INTx16:1;                    // 15 Interrupt Enable for INT10.16
};

union PIEIER10_REG {
    Uint16  all;
    struct  PIEIER10_BITS  bit;
};

struct PIEIFR10_BITS {                  // bits description
    Uint16 INTx1:1;                     // 0 Interrupt Flag for INT10.1
    Uint16 INTx2:1;                     // 1 Interrupt Flag for INT10.2
    Uint16 INTx3:1;                     // 2 Interrupt Flag for INT10.3
    Uint16 INTx4:1;                     // 3 Interrupt Flag for INT10.4
    Uint16 INTx5:1;                     // 4 Interrupt Flag for INT10.5
    Uint16 INTx6:1;                     // 5 Interrupt Flag for INT10.6
    Uint16 INTx7:1;                     // 6 Interrupt Flag for INT10.7
    Uint16 INTx8:1;                     // 7 Interrupt Flag for INT10.8
    Uint16 INTx9:1;                     // 8 Interrupt Flag for INT10.9
    Uint16 INTx10:1;                    // 9 Interrupt Flag for INT10.10
    Uint16 INTx11:1;                    // 10 Interrupt Flag for INT10.11
    Uint16 INTx12:1;                    // 11 Interrupt Flag for INT10.12
    Uint16 INTx13:1;                    // 12 Interrupt Flag for INT10.13
    Uint16 INTx14:1;                    // 13 Interrupt Flag for INT10.14
    Uint16 INTx15:1;                    // 14 Interrupt Flag for INT10.15
    Uint16 INTx16:1;                    // 15 Interrupt Flag for INT10.16
};

union PIEIFR10_REG {
    Uint16  all;
    struct  PIEIFR10_BITS  bit;
};

struct PIEIER11_BITS {                  // bits description
    Uint16 INTx1:1;                     // 0 Interrupt Enable for INT11.1
    Uint16 INTx2:1;                     // 1 Interrupt Enable for INT11.2
    Uint16 INTx3:1;                     // 2 Interrupt Enable for INT11.3
    Uint16 INTx4:1;                     // 3 Interrupt Enable for INT11.4
    Uint16 INTx5:1;                     // 4 Interrupt Enable for INT11.5
    Uint16 INTx6:1;                     // 5 Interrupt Enable for INT11.6
    Uint16 INTx7:1;                     // 6 Interrupt Enable for INT11.7
    Uint16 INTx8:1;                     // 7 Interrupt Enable for INT11.8
    Uint16 INTx9:1;                     // 8 Interrupt Enable for INT11.9
    Uint16 INTx10:1;                    // 9 Interrupt Enable for INT11.10
    Uint16 INTx11:1;                    // 10 Interrupt Enable for INT11.11
    Uint16 INTx12:1;                    // 11 Interrupt Enable for INT11.12
    Uint16 INTx13:1;                    // 12 Interrupt Enable for INT11.13
    Uint16 INTx14:1;                    // 13 Interrupt Enable for INT11.14
    Uint16 INTx15:1;                    // 14 Interrupt Enable for INT11.15
    Uint16 INTx16:1;                    // 15 Interrupt Enable for INT11.16
};

union PIEIER11_REG {
    Uint16  all;
    struct  PIEIER11_BITS  bit;
};

struct PIEIFR11_BITS {                  // bits description
    Uint16 INTx1:1;                     // 0 Interrupt Flag for INT11.1
    Uint16 INTx2:1;                     // 1 Interrupt Flag for INT11.2
    Uint16 INTx3:1;                     // 2 Interrupt Flag for INT11.3
    Uint16 INTx4:1;                     // 3 Interrupt Flag for INT11.4
    Uint16 INTx5:1;                     // 4 Interrupt Flag for INT11.5
    Uint16 INTx6:1;                     // 5 Interrupt Flag for INT11.6
    Uint16 INTx7:1;                     // 6 Interrupt Flag for INT11.7
    Uint16 INTx8:1;                     // 7 Interrupt Flag for INT11.8
    Uint16 INTx9:1;                     // 8 Interrupt Flag for INT11.9
    Uint16 INTx10:1;                    // 9 Interrupt Flag for INT11.10
    Uint16 INTx11:1;                    // 10 Interrupt Flag for INT11.11
    Uint16 INTx12:1;                    // 11 Interrupt Flag for INT11.12
    Uint16 INTx13:1;                    // 12 Interrupt Flag for INT11.13
    Uint16 INTx14:1;                    // 13 Interrupt Flag for INT11.14
    Uint16 INTx15:1;                    // 14 Interrupt Flag for INT11.15
    Uint16 INTx16:1;                    // 15 Interrupt Flag for INT11.16
};

union PIEIFR11_REG {
    Uint16  all;
    struct  PIEIFR11_BITS  bit;
};

struct PIEIER12_BITS {                  // bits description
    Uint16 INTx1:1;                     // 0 Interrupt Enable for INT12.1
    Uint16 INTx2:1;                     // 1 Interrupt Enable for INT12.2
    Uint16 INTx3:1;                     // 2 Interrupt Enable for INT12.3
    Uint16 INTx4:1;                     // 3 Interrupt Enable for INT12.4
    Uint16 INTx5:1;                     // 4 Interrupt Enable for INT12.5
    Uint16 INTx6:1;                     // 5 Interrupt Enable for INT12.6
    Uint16 INTx7:1;                     // 6 Interrupt Enable for INT12.7
    Uint16 INTx8:1;                     // 7 Interrupt Enable for INT12.8
    Uint16 INTx9:1;                     // 8 Interrupt Enable for INT12.9
    Uint16 INTx10:1;                    // 9 Interrupt Enable for INT12.10
    Uint16 INTx11:1;                    // 10 Interrupt Enable for INT12.11
    Uint16 INTx12:1;                    // 11 Interrupt Enable for INT12.12
    Uint16 INTx13:1;                    // 12 Interrupt Enable for INT12.13
    Uint16 INTx14:1;                    // 13 Interrupt Enable for INT12.14
    Uint16 INTx15:1;                    // 14 Interrupt Enable for INT12.15
    Uint16 INTx16:1;                    // 15 Interrupt Enable for INT12.16
};

union PIEIER12_REG {
    Uint16  all;
    struct  PIEIER12_BITS  bit;
};

struct PIEIFR12_BITS {                  // bits description
    Uint16 INTx1:1;                     // 0 Interrupt Flag for INT12.1
    Uint16 INTx2:1;                     // 1 Interrupt Flag for INT12.2
    Uint16 INTx3:1;                     // 2 Interrupt Flag for INT12.3
    Uint16 INTx4:1;                     // 3 Interrupt Flag for INT12.4
    Uint16 INTx5:1;                     // 4 Interrupt Flag for INT12.5
    Uint16 INTx6:1;                     // 5 Interrupt Flag for INT12.6
    Uint16 INTx7:1;                     // 6 Interrupt Flag for INT12.7
    Uint16 INTx8:1;                     // 7 Interrupt Flag for INT12.8
    Uint16 INTx9:1;                     // 8 Interrupt Flag for INT12.9
    Uint16 INTx10:1;                    // 9 Interrupt Flag for INT12.10
    Uint16 INTx11:1;                    // 10 Interrupt Flag for INT12.11
    Uint16 INTx12:1;                    // 11 Interrupt Flag for INT12.12
    Uint16 INTx13:1;                    // 12 Interrupt Flag for INT12.13
    Uint16 INTx14:1;                    // 13 Interrupt Flag for INT12.14
    Uint16 INTx15:1;                    // 14 Interrupt Flag for INT12.15
    Uint16 INTx16:1;                    // 15 Interrupt Flag for INT12.16
};

union PIEIFR12_REG {
    Uint16  all;
    struct  PIEIFR12_BITS  bit;
};

struct PIE_CTRL_REGS {
    union   PIECTRL_REG                      PIECTRL;                      // Control Register
    union   PIEACK_REG                       PIEACK;                       // Acknowledge Register
    union   PIEIER1_REG                      PIEIER1;                      // INT1 Group Enable Register
    union   PIEIFR1_REG                      PIEIFR1;                      // INT1 Group Flag Register
    union   PIEIER2_REG                      PIEIER2;                      // INT2 Group Enable Register
    union   PIEIFR2_REG                      PIEIFR2;                      // INT2 Group Flag Register
    union   PIEIER3_REG                      PIEIER3;                      // INT3 Group Enable Register
    union   PIEIFR3_REG                      PIEIFR3;                      // INT3 Group Flag Register
    union   PIEIER4_REG                      PIEIER4;                      // INT4 Group Enable Register
    union   PIEIFR4_REG                      PIEIFR4;                      // INT4 Group Flag Register
    union   PIEIER5_REG                      PIEIER5;                      // INT5 Group Enable Register
    union   PIEIFR5_REG                      PIEIFR5;                      // INT5 Group Flag Register
    union   PIEIER6_REG                      PIEIER6;                      // INT6 Group Enable Register
    union   PIEIFR6_REG                      PIEIFR6;                      // INT6 Group Flag Register
    union   PIEIER7_REG                      PIEIER7;                      // INT7 Group Enable Register
    union   PIEIFR7_REG                      PIEIFR7;                      // INT7 Group Flag Register
    union   PIEIER8_REG                      PIEIER8;                      // INT8 Group Enable Register
    union   PIEIFR8_REG                      PIEIFR8;                      // INT8 Group Flag Register
    union   PIEIER9_REG                      PIEIER9;                      // INT9 Group Enable Register
    union   PIEIFR9_REG                      PIEIFR9;                      // INT9 Group Flag Register
    union   PIEIER10_REG                     PIEIER10;                     // INT10 Group Enable Register
    union   PIEIFR10_REG                     PIEIFR10;                     // INT10 Group Flag Register
    union   PIEIER11_REG                     PIEIER11;                     // INT11 Group Enable Register
    union   PIEIFR11_REG                     PIEIFR11;                     // INT11 Group Flag Register
    union   PIEIER12_REG                     PIEIER12;                     // INT12 Group Enable Register
    union   PIEIFR12_REG                     PIEIFR12;                     // INT12 Group Flag Register
};

//---------------------------------------------------------------------------
// PIECTRL External References & Function Declarations:
//
extern volatile struct PIE_CTRL_REGS PieCtrlRegs;
#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================
