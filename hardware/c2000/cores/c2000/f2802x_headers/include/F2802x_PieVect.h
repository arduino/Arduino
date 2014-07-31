//###########################################################################
//
// FILE:   F2802x_PieVect.h
//
// TITLE:  F2802x Devices PIE Vector Table Definitions.
//
//###########################################################################
// $TI Release: 2802x C/C++ Header Files and Peripheral Examples V1.29 $
// $Release Date: January 11, 2011 $
//###########################################################################

#ifndef F2802x_PIE_VECT_H
#define F2802x_PIE_VECT_H

#ifdef __cplusplus
extern "C" {
#endif

//---------------------------------------------------------------------------
// PIE Interrupt Vector Table Definition:
//
// Create a user type called PINT (pointer to interrupt):

typedef interrupt void(*PINT)(void);

// Define Vector Table:
struct PIE_VECT_TABLE {

// Reset is never fetched from this table.
// It will always be fetched from 0x3FFFC0 in
// boot ROM

      PINT     PIE1_RESERVED;
      PINT     PIE2_RESERVED;
      PINT     PIE3_RESERVED;
      PINT     PIE4_RESERVED;
      PINT     PIE5_RESERVED;
      PINT     PIE6_RESERVED;
      PINT     PIE7_RESERVED;
      PINT     PIE8_RESERVED;
      PINT     PIE9_RESERVED;
      PINT     PIE10_RESERVED;
      PINT     PIE11_RESERVED;
      PINT     PIE12_RESERVED;
      PINT     PIE13_RESERVED;

// Non-Peripheral Interrupts:
      PINT     TINT1;     // CPU-Timer1
      PINT     TINT2;     // CPU-Timer2
      PINT     DATALOG;   // Datalogging interrupt
      PINT     RTOSINT;   // RTOS interrupt
      PINT     EMUINT;    // Emulation interrupt
      PINT     NMI;       // Non-maskable interrupt
      PINT     ILLEGAL;   // Illegal operation TRAP
      PINT     USER1;     // User Defined trap 1
      PINT     USER2;     // User Defined trap 2
      PINT     USER3;     // User Defined trap 3
      PINT     USER4;     // User Defined trap 4
      PINT     USER5;     // User Defined trap 5
      PINT     USER6;     // User Defined trap 6
      PINT     USER7;     // User Defined trap 7
      PINT     USER8;     // User Defined trap 8
      PINT     USER9;     // User Defined trap 9
      PINT     USER10;    // User Defined trap 10
      PINT     USER11;    // User Defined trap 11
      PINT     USER12;    // User Defined trap 12

// Group 1 PIE Peripheral Vectors:
      PINT     ADCINT1;   // ADC - if Group 10 ADCINT1 is enabled, this must be rsvd1_1
      PINT     ADCINT2;   // ADC - if Group 10 ADCINT2 is enabled, this must be rsvd1_2
      PINT     rsvd1_3;
      PINT     XINT1;
      PINT     XINT2;
      PINT     ADCINT9;   // ADC
      PINT     TINT0;     // Timer 0
      PINT     WAKEINT;   // WD

// Group 2 PIE Peripheral Vectors:
      PINT     EPWM1_TZINT; // EPWM-1
      PINT     EPWM2_TZINT; // EPWM-2
      PINT     EPWM3_TZINT; // EPWM-3
      PINT     EPWM4_TZINT; // EPWM-4
      PINT     rsvd2_5;
      PINT     rsvd2_6;
      PINT     rsvd2_7;
      PINT     rsvd2_8;

// Group 3 PIE Peripheral Vectors:
      PINT     EPWM1_INT;  // EPWM-1
      PINT     EPWM2_INT;  // EPWM-2
      PINT     EPWM3_INT;  // EPWM-3
      PINT     EPWM4_INT;  // EPWM-4
      PINT     rsvd3_5;
      PINT     rsvd3_6;
      PINT     rsvd3_7;
      PINT     rsvd3_8;

// Group 4 PIE Peripheral Vectors:
      PINT     ECAP1_INT; // ECAP-1
      PINT     rsvd4_2;
      PINT     rsvd4_3;
      PINT     rsvd4_4;
      PINT     rsvd4_5;
      PINT     rsvd4_6;
      PINT     rsvd4_7;
      PINT     rsvd4_8;

// Group 5 PIE Peripheral Vectors:

      PINT     rsvd5_1;
      PINT     rsvd5_2;
      PINT     rsvd5_3;
      PINT     rsvd5_4;
      PINT     rsvd5_5;
      PINT     rsvd5_6;
      PINT     rsvd5_7;
      PINT     rsvd5_8;

// Group 6 PIE Peripheral Vectors:
      PINT     SPIRXINTA; // SPI-A
      PINT     SPITXINTA; // SPI-A
      PINT     rsvd6_3;
      PINT     rsvd6_4;
      PINT     rsvd6_5;
      PINT     rsvd6_6;
      PINT     rsvd6_7;
      PINT     rsvd6_8;

// Group 7 PIE Peripheral Vectors:
      PINT     rsvd7_1;
      PINT     rsvd7_2;
      PINT     rsvd7_3;
      PINT     rsvd7_4;
      PINT     rsvd7_5;
      PINT     rsvd7_6;
      PINT     rsvd7_7;
      PINT     rsvd7_8;

// Group 8 PIE Peripheral Vectors:
      PINT     I2CINT1A;  // I2C-A
      PINT     I2CINT2A;  // I2C-A
      PINT     rsvd8_3;
      PINT     rsvd8_4;
      PINT     rsvd8_5;
      PINT     rsvd8_6;
      PINT     rsvd8_7;
      PINT     rsvd8_8;

// Group 9 PIE Peripheral Vectors:

      PINT     SCIRXINTA;  // SCI-A
      PINT     SCITXINTA;  // SCI-A
      PINT     rsvd9_3;
      PINT     rsvd9_4;
      PINT     rsvd9_5;
      PINT     rsvd9_6;
      PINT     rsvd9_7;
      PINT     rsvd9_8;

// Group 10 PIE Peripheral Vectors:
      PINT     rsvd10_1; // Can be ADCINT1, but must make ADCINT1 in Group 1 space "reserved".
      PINT     rsvd10_2; // Can be ADCINT2, but must make ADCINT2 in Group 1 space "reserved".
      PINT     ADCINT3;  // ADC
      PINT     ADCINT4;  // ADC
      PINT     ADCINT5;  // ADC
      PINT     ADCINT6;  // ADC
      PINT     ADCINT7;  // ADC
      PINT     ADCINT8;  // ADC
// Group 11 PIE Peripheral Vectors:
      PINT     rsvd11_1;
      PINT     rsvd11_2;
      PINT     rsvd11_3;
      PINT     rsvd11_4;
      PINT     rsvd11_5;
      PINT     rsvd11_6;
      PINT     rsvd11_7;
      PINT     rsvd11_8;
// Group 12 PIE Peripheral Vectors:
      PINT     XINT3;
      PINT     rsvd12_2;
      PINT     rsvd12_3;
      PINT     rsvd12_4;
      PINT     rsvd12_5;
      PINT     rsvd12_6;
      PINT     rsvd12_7;
      PINT     rsvd12_8;
};

//---------------------------------------------------------------------------
// PIE Interrupt Vector Table External References & Function Declarations:
//
extern volatile struct PIE_VECT_TABLE PieVectTable;

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif    // end of F2802x_PIE_VECT_H definition

//===========================================================================
// End of file.
//===========================================================================

