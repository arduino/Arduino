//###########################################################################
//
// FILE:    F2837xS_adc.h
//
// TITLE:   F2837xS Device ADC Register Definitions.
//
//###########################################################################
// $TI Release: F2837xS Support Library v170 $
// $Release Date: Mon Sep 21 16:56:07 CDT 2015 $
// $Copyright: Copyright (C) 2014-2015 Texas Instruments Incorporated -
//             http://www.ti.com/ ALL RIGHTS RESERVED $
//###########################################################################

#ifndef __F2837xS_ADC_H__
#define __F2837xS_ADC_H__

#ifdef __cplusplus 
extern "C" {
#endif 


//---------------------------------------------------------------------------
// ADC Individual Register Bit Definitions:

struct ADCCTL1_BITS {                   // bits description
    Uint16 rsvd1:2;                     // 1:0 Reserved
    Uint16 INTPULSEPOS:1;               // 2 ADC Interrupt Pulse Position
    Uint16 rsvd2:4;                     // 6:3 Reserved
    Uint16 ADCPWDNZ:1;                  // 7 ADC Power Down
    Uint16 ADCBSYCHN:4;                 // 11:8 ADC Busy Channel
    Uint16 rsvd3:1;                     // 12 Reserved
    Uint16 ADCBSY:1;                    // 13 ADC Busy
    Uint16 rsvd4:2;                     // 15:14 Reserved
};

union ADCCTL1_REG {
    Uint16  all;
    struct  ADCCTL1_BITS  bit;
};

struct ADCCTL2_BITS {                   // bits description
    Uint16 PRESCALE:4;                  // 3:0 ADC Clock Prescaler
    Uint16 rsvd1:2;                     // 5:4 Reserved
    Uint16 RESOLUTION:1;                // 6 SOC Conversion Resolution
    Uint16 SIGNALMODE:1;                // 7 SOC Signaling Mode
    Uint16 rsvd2:5;                     // 12:8 Reserved
    Uint16 rsvd3:3;                     // 15:13 Reserved
};

union ADCCTL2_REG {
    Uint16  all;
    struct  ADCCTL2_BITS  bit;
};

struct ADCBURSTCTL_BITS {               // bits description
    Uint16 BURSTTRIGSEL:6;              // 5:0 SOC Burst Trigger Source Select
    Uint16 rsvd1:2;                     // 7:6 Reserved
    Uint16 BURSTSIZE:4;                 // 11:8 SOC Burst Size Select
    Uint16 rsvd2:3;                     // 14:12 Reserved
    Uint16 BURSTEN:1;                   // 15 SOC Burst Mode Enable
};

union ADCBURSTCTL_REG {
    Uint16  all;
    struct  ADCBURSTCTL_BITS  bit;
};

struct ADCINTFLG_BITS {                 // bits description
    Uint16 ADCINT1:1;                   // 0 ADC Interrupt 1 Flag
    Uint16 ADCINT2:1;                   // 1 ADC Interrupt 2 Flag
    Uint16 ADCINT3:1;                   // 2 ADC Interrupt 3 Flag
    Uint16 ADCINT4:1;                   // 3 ADC Interrupt 4 Flag
    Uint16 rsvd1:12;                    // 15:4 Reserved
};

union ADCINTFLG_REG {
    Uint16  all;
    struct  ADCINTFLG_BITS  bit;
};

struct ADCINTFLGCLR_BITS {              // bits description
    Uint16 ADCINT1:1;                   // 0 ADC Interrupt 1 Flag Clear
    Uint16 ADCINT2:1;                   // 1 ADC Interrupt 2 Flag Clear
    Uint16 ADCINT3:1;                   // 2 ADC Interrupt 3 Flag Clear
    Uint16 ADCINT4:1;                   // 3 ADC Interrupt 4 Flag Clear
    Uint16 rsvd1:12;                    // 15:4 Reserved
};

union ADCINTFLGCLR_REG {
    Uint16  all;
    struct  ADCINTFLGCLR_BITS  bit;
};

struct ADCINTOVF_BITS {                 // bits description
    Uint16 ADCINT1:1;                   // 0 ADC Interrupt 1 Overflow Flags
    Uint16 ADCINT2:1;                   // 1 ADC Interrupt 2 Overflow Flags
    Uint16 ADCINT3:1;                   // 2 ADC Interrupt 3 Overflow Flags
    Uint16 ADCINT4:1;                   // 3 ADC Interrupt 4 Overflow Flags
    Uint16 rsvd1:12;                    // 15:4 Reserved
};

union ADCINTOVF_REG {
    Uint16  all;
    struct  ADCINTOVF_BITS  bit;
};

struct ADCINTOVFCLR_BITS {              // bits description
    Uint16 ADCINT1:1;                   // 0 ADC Interrupt 1 Overflow Clear Bits
    Uint16 ADCINT2:1;                   // 1 ADC Interrupt 2 Overflow Clear Bits
    Uint16 ADCINT3:1;                   // 2 ADC Interrupt 3 Overflow Clear Bits
    Uint16 ADCINT4:1;                   // 3 ADC Interrupt 4 Overflow Clear Bits
    Uint16 rsvd1:12;                    // 15:4 Reserved
};

union ADCINTOVFCLR_REG {
    Uint16  all;
    struct  ADCINTOVFCLR_BITS  bit;
};

struct ADCINTSEL1N2_BITS {              // bits description
    Uint16 INT1SEL:4;                   // 3:0 ADCINT1 EOC Source Select
    Uint16 rsvd1:1;                     // 4 Reserved
    Uint16 INT1E:1;                     // 5 ADCINT1 Interrupt Enable
    Uint16 INT1CONT:1;                  // 6 ADCINT1 Continuous Mode Enable
    Uint16 rsvd2:1;                     // 7 Reserved
    Uint16 INT2SEL:4;                   // 11:8 ADCINT2 EOC Source Select
    Uint16 rsvd3:1;                     // 12 Reserved
    Uint16 INT2E:1;                     // 13 ADCINT2 Interrupt Enable
    Uint16 INT2CONT:1;                  // 14 ADCINT2 Continuous Mode Enable
    Uint16 rsvd4:1;                     // 15 Reserved
};

union ADCINTSEL1N2_REG {
    Uint16  all;
    struct  ADCINTSEL1N2_BITS  bit;
};

struct ADCINTSEL3N4_BITS {              // bits description
    Uint16 INT3SEL:4;                   // 3:0 ADCINT3 EOC Source Select
    Uint16 rsvd1:1;                     // 4 Reserved
    Uint16 INT3E:1;                     // 5 ADCINT3 Interrupt Enable
    Uint16 INT3CONT:1;                  // 6 ADCINT3 Continuous Mode Enable
    Uint16 rsvd2:1;                     // 7 Reserved
    Uint16 INT4SEL:4;                   // 11:8 ADCINT4 EOC Source Select
    Uint16 rsvd3:1;                     // 12 Reserved
    Uint16 INT4E:1;                     // 13 ADCINT4 Interrupt Enable
    Uint16 INT4CONT:1;                  // 14 ADCINT4 Continuous Mode Enable
    Uint16 rsvd4:1;                     // 15 Reserved
};

union ADCINTSEL3N4_REG {
    Uint16  all;
    struct  ADCINTSEL3N4_BITS  bit;
};

struct ADCSOCPRICTL_BITS {              // bits description
    Uint16 SOCPRIORITY:5;               // 4:0 SOC Priority
    Uint16 RRPOINTER:5;                 // 9:5 Round Robin Pointer
    Uint16 rsvd1:6;                     // 15:10 Reserved
};

union ADCSOCPRICTL_REG {
    Uint16  all;
    struct  ADCSOCPRICTL_BITS  bit;
};

struct ADCINTSOCSEL1_BITS {             // bits description
    Uint16 SOC0:2;                      // 1:0 SOC0 ADC Interrupt Trigger Select
    Uint16 SOC1:2;                      // 3:2 SOC1 ADC Interrupt Trigger Select
    Uint16 SOC2:2;                      // 5:4 SOC2 ADC Interrupt Trigger Select
    Uint16 SOC3:2;                      // 7:6 SOC3 ADC Interrupt Trigger Select
    Uint16 SOC4:2;                      // 9:8 SOC4 ADC Interrupt Trigger Select
    Uint16 SOC5:2;                      // 11:10 SOC5 ADC Interrupt Trigger Select
    Uint16 SOC6:2;                      // 13:12 SOC6 ADC Interrupt Trigger Select
    Uint16 SOC7:2;                      // 15:14 SOC7 ADC Interrupt Trigger Select
};

union ADCINTSOCSEL1_REG {
    Uint16  all;
    struct  ADCINTSOCSEL1_BITS  bit;
};

struct ADCINTSOCSEL2_BITS {             // bits description
    Uint16 SOC8:2;                      // 1:0 SOC8 ADC Interrupt Trigger Select
    Uint16 SOC9:2;                      // 3:2 SOC9 ADC Interrupt Trigger Select
    Uint16 SOC10:2;                     // 5:4 SOC10 ADC Interrupt Trigger Select
    Uint16 SOC11:2;                     // 7:6 SOC11 ADC Interrupt Trigger Select
    Uint16 SOC12:2;                     // 9:8 SOC12 ADC Interrupt Trigger Select
    Uint16 SOC13:2;                     // 11:10 SOC13 ADC Interrupt Trigger Select
    Uint16 SOC14:2;                     // 13:12 SOC14 ADC Interrupt Trigger Select
    Uint16 SOC15:2;                     // 15:14 SOC15 ADC Interrupt Trigger Select
};

union ADCINTSOCSEL2_REG {
    Uint16  all;
    struct  ADCINTSOCSEL2_BITS  bit;
};

struct ADCSOCFLG1_BITS {                // bits description
    Uint16 SOC0:1;                      // 0 SOC0 Start of Conversion Flag
    Uint16 SOC1:1;                      // 1 SOC1 Start of Conversion Flag
    Uint16 SOC2:1;                      // 2 SOC2 Start of Conversion Flag
    Uint16 SOC3:1;                      // 3 SOC3 Start of Conversion Flag
    Uint16 SOC4:1;                      // 4 SOC4 Start of Conversion Flag
    Uint16 SOC5:1;                      // 5 SOC5 Start of Conversion Flag
    Uint16 SOC6:1;                      // 6 SOC6 Start of Conversion Flag
    Uint16 SOC7:1;                      // 7 SOC7 Start of Conversion Flag
    Uint16 SOC8:1;                      // 8 SOC8 Start of Conversion Flag
    Uint16 SOC9:1;                      // 9 SOC9 Start of Conversion Flag
    Uint16 SOC10:1;                     // 10 SOC10 Start of Conversion Flag
    Uint16 SOC11:1;                     // 11 SOC11 Start of Conversion Flag
    Uint16 SOC12:1;                     // 12 SOC12 Start of Conversion Flag
    Uint16 SOC13:1;                     // 13 SOC13 Start of Conversion Flag
    Uint16 SOC14:1;                     // 14 SOC14 Start of Conversion Flag
    Uint16 SOC15:1;                     // 15 SOC15 Start of Conversion Flag
};

union ADCSOCFLG1_REG {
    Uint16  all;
    struct  ADCSOCFLG1_BITS  bit;
};

struct ADCSOCFRC1_BITS {                // bits description
    Uint16 SOC0:1;                      // 0 SOC0 Force Start of Conversion Bit
    Uint16 SOC1:1;                      // 1 SOC1 Force Start of Conversion Bit
    Uint16 SOC2:1;                      // 2 SOC2 Force Start of Conversion Bit
    Uint16 SOC3:1;                      // 3 SOC3 Force Start of Conversion Bit
    Uint16 SOC4:1;                      // 4 SOC4 Force Start of Conversion Bit
    Uint16 SOC5:1;                      // 5 SOC5 Force Start of Conversion Bit
    Uint16 SOC6:1;                      // 6 SOC6 Force Start of Conversion Bit
    Uint16 SOC7:1;                      // 7 SOC7 Force Start of Conversion Bit
    Uint16 SOC8:1;                      // 8 SOC8 Force Start of Conversion Bit
    Uint16 SOC9:1;                      // 9 SOC9 Force Start of Conversion Bit
    Uint16 SOC10:1;                     // 10 SOC10 Force Start of Conversion Bit
    Uint16 SOC11:1;                     // 11 SOC11 Force Start of Conversion Bit
    Uint16 SOC12:1;                     // 12 SOC12 Force Start of Conversion Bit
    Uint16 SOC13:1;                     // 13 SOC13 Force Start of Conversion Bit
    Uint16 SOC14:1;                     // 14 SOC14 Force Start of Conversion Bit
    Uint16 SOC15:1;                     // 15 SOC15 Force Start of Conversion Bit
};

union ADCSOCFRC1_REG {
    Uint16  all;
    struct  ADCSOCFRC1_BITS  bit;
};

struct ADCSOCOVF1_BITS {                // bits description
    Uint16 SOC0:1;                      // 0 SOC0 Start of Conversion Overflow Flag
    Uint16 SOC1:1;                      // 1 SOC1 Start of Conversion Overflow Flag
    Uint16 SOC2:1;                      // 2 SOC2 Start of Conversion Overflow Flag
    Uint16 SOC3:1;                      // 3 SOC3 Start of Conversion Overflow Flag
    Uint16 SOC4:1;                      // 4 SOC4 Start of Conversion Overflow Flag
    Uint16 SOC5:1;                      // 5 SOC5 Start of Conversion Overflow Flag
    Uint16 SOC6:1;                      // 6 SOC6 Start of Conversion Overflow Flag
    Uint16 SOC7:1;                      // 7 SOC7 Start of Conversion Overflow Flag
    Uint16 SOC8:1;                      // 8 SOC8 Start of Conversion Overflow Flag
    Uint16 SOC9:1;                      // 9 SOC9 Start of Conversion Overflow Flag
    Uint16 SOC10:1;                     // 10 SOC10 Start of Conversion Overflow Flag
    Uint16 SOC11:1;                     // 11 SOC11 Start of Conversion Overflow Flag
    Uint16 SOC12:1;                     // 12 SOC12 Start of Conversion Overflow Flag
    Uint16 SOC13:1;                     // 13 SOC13 Start of Conversion Overflow Flag
    Uint16 SOC14:1;                     // 14 SOC14 Start of Conversion Overflow Flag
    Uint16 SOC15:1;                     // 15 SOC15 Start of Conversion Overflow Flag
};

union ADCSOCOVF1_REG {
    Uint16  all;
    struct  ADCSOCOVF1_BITS  bit;
};

struct ADCSOCOVFCLR1_BITS {             // bits description
    Uint16 SOC0:1;                      // 0 SOC0 Clear Start of Conversion Overflow Bit
    Uint16 SOC1:1;                      // 1 SOC1 Clear Start of Conversion Overflow Bit
    Uint16 SOC2:1;                      // 2 SOC2 Clear Start of Conversion Overflow Bit
    Uint16 SOC3:1;                      // 3 SOC3 Clear Start of Conversion Overflow Bit
    Uint16 SOC4:1;                      // 4 SOC4 Clear Start of Conversion Overflow Bit
    Uint16 SOC5:1;                      // 5 SOC5 Clear Start of Conversion Overflow Bit
    Uint16 SOC6:1;                      // 6 SOC6 Clear Start of Conversion Overflow Bit
    Uint16 SOC7:1;                      // 7 SOC7 Clear Start of Conversion Overflow Bit
    Uint16 SOC8:1;                      // 8 SOC8 Clear Start of Conversion Overflow Bit
    Uint16 SOC9:1;                      // 9 SOC9 Clear Start of Conversion Overflow Bit
    Uint16 SOC10:1;                     // 10 SOC10 Clear Start of Conversion Overflow Bit
    Uint16 SOC11:1;                     // 11 SOC11 Clear Start of Conversion Overflow Bit
    Uint16 SOC12:1;                     // 12 SOC12 Clear Start of Conversion Overflow Bit
    Uint16 SOC13:1;                     // 13 SOC13 Clear Start of Conversion Overflow Bit
    Uint16 SOC14:1;                     // 14 SOC14 Clear Start of Conversion Overflow Bit
    Uint16 SOC15:1;                     // 15 SOC15 Clear Start of Conversion Overflow Bit
};

union ADCSOCOVFCLR1_REG {
    Uint16  all;
    struct  ADCSOCOVFCLR1_BITS  bit;
};

struct ADCSOC0CTL_BITS {                // bits description
    Uint16 ACQPS:9;                     // 8:0 SOC Acquisition Prescale
    Uint16 rsvd1:6;                     // 14:9 Reserved
    Uint32 CHSEL:4;                     // 18:15 SOC Channel Select
    Uint16 rsvd2:1;                     // 19 Reserved
    Uint16 TRIGSEL:5;                   // 24:20 SOC Trigger Source Select
    Uint16 rsvd3:7;                     // 31:25 Reserved
};

union ADCSOC0CTL_REG {
    Uint32  all;
    struct  ADCSOC0CTL_BITS  bit;
};

struct ADCSOC1CTL_BITS {                // bits description
    Uint16 ACQPS:9;                     // 8:0 SOC Acquisition Prescale
    Uint16 rsvd1:6;                     // 14:9 Reserved
    Uint32 CHSEL:4;                     // 18:15 SOC Channel Select
    Uint16 rsvd2:1;                     // 19 Reserved
    Uint16 TRIGSEL:5;                   // 24:20 SOC Trigger Source Select
    Uint16 rsvd3:7;                     // 31:25 Reserved
};

union ADCSOC1CTL_REG {
    Uint32  all;
    struct  ADCSOC1CTL_BITS  bit;
};

struct ADCSOC2CTL_BITS {                // bits description
    Uint16 ACQPS:9;                     // 8:0 SOC Acquisition Prescale
    Uint16 rsvd1:6;                     // 14:9 Reserved
    Uint32 CHSEL:4;                     // 18:15 SOC Channel Select
    Uint16 rsvd2:1;                     // 19 Reserved
    Uint16 TRIGSEL:5;                   // 24:20 SOC Trigger Source Select
    Uint16 rsvd3:7;                     // 31:25 Reserved
};

union ADCSOC2CTL_REG {
    Uint32  all;
    struct  ADCSOC2CTL_BITS  bit;
};

struct ADCSOC3CTL_BITS {                // bits description
    Uint16 ACQPS:9;                     // 8:0 SOC Acquisition Prescale
    Uint16 rsvd1:6;                     // 14:9 Reserved
    Uint32 CHSEL:4;                     // 18:15 SOC Channel Select
    Uint16 rsvd2:1;                     // 19 Reserved
    Uint16 TRIGSEL:5;                   // 24:20 SOC Trigger Source Select
    Uint16 rsvd3:7;                     // 31:25 Reserved
};

union ADCSOC3CTL_REG {
    Uint32  all;
    struct  ADCSOC3CTL_BITS  bit;
};

struct ADCSOC4CTL_BITS {                // bits description
    Uint16 ACQPS:9;                     // 8:0 SOC Acquisition Prescale
    Uint16 rsvd1:6;                     // 14:9 Reserved
    Uint32 CHSEL:4;                     // 18:15 SOC Channel Select
    Uint16 rsvd2:1;                     // 19 Reserved
    Uint16 TRIGSEL:5;                   // 24:20 SOC Trigger Source Select
    Uint16 rsvd3:7;                     // 31:25 Reserved
};

union ADCSOC4CTL_REG {
    Uint32  all;
    struct  ADCSOC4CTL_BITS  bit;
};

struct ADCSOC5CTL_BITS {                // bits description
    Uint16 ACQPS:9;                     // 8:0 SOC Acquisition Prescale
    Uint16 rsvd1:6;                     // 14:9 Reserved
    Uint32 CHSEL:4;                     // 18:15 SOC Channel Select
    Uint16 rsvd2:1;                     // 19 Reserved
    Uint16 TRIGSEL:5;                   // 24:20 SOC Trigger Source Select
    Uint16 rsvd3:7;                     // 31:25 Reserved
};

union ADCSOC5CTL_REG {
    Uint32  all;
    struct  ADCSOC5CTL_BITS  bit;
};

struct ADCSOC6CTL_BITS {                // bits description
    Uint16 ACQPS:9;                     // 8:0 SOC Acquisition Prescale
    Uint16 rsvd1:6;                     // 14:9 Reserved
    Uint32 CHSEL:4;                     // 18:15 SOC Channel Select
    Uint16 rsvd2:1;                     // 19 Reserved
    Uint16 TRIGSEL:5;                   // 24:20 SOC Trigger Source Select
    Uint16 rsvd3:7;                     // 31:25 Reserved
};

union ADCSOC6CTL_REG {
    Uint32  all;
    struct  ADCSOC6CTL_BITS  bit;
};

struct ADCSOC7CTL_BITS {                // bits description
    Uint16 ACQPS:9;                     // 8:0 SOC Acquisition Prescale
    Uint16 rsvd1:6;                     // 14:9 Reserved
    Uint32 CHSEL:4;                     // 18:15 SOC Channel Select
    Uint16 rsvd2:1;                     // 19 Reserved
    Uint16 TRIGSEL:5;                   // 24:20 SOC Trigger Source Select
    Uint16 rsvd3:7;                     // 31:25 Reserved
};

union ADCSOC7CTL_REG {
    Uint32  all;
    struct  ADCSOC7CTL_BITS  bit;
};

struct ADCSOC8CTL_BITS {                // bits description
    Uint16 ACQPS:9;                     // 8:0 SOC Acquisition Prescale
    Uint16 rsvd1:6;                     // 14:9 Reserved
    Uint32 CHSEL:4;                     // 18:15 SOC Channel Select
    Uint16 rsvd2:1;                     // 19 Reserved
    Uint16 TRIGSEL:5;                   // 24:20 SOC Trigger Source Select
    Uint16 rsvd3:7;                     // 31:25 Reserved
};

union ADCSOC8CTL_REG {
    Uint32  all;
    struct  ADCSOC8CTL_BITS  bit;
};

struct ADCSOC9CTL_BITS {                // bits description
    Uint16 ACQPS:9;                     // 8:0 SOC Acquisition Prescale
    Uint16 rsvd1:6;                     // 14:9 Reserved
    Uint32 CHSEL:4;                     // 18:15 SOC Channel Select
    Uint16 rsvd2:1;                     // 19 Reserved
    Uint16 TRIGSEL:5;                   // 24:20 SOC Trigger Source Select
    Uint16 rsvd3:7;                     // 31:25 Reserved
};

union ADCSOC9CTL_REG {
    Uint32  all;
    struct  ADCSOC9CTL_BITS  bit;
};

struct ADCSOC10CTL_BITS {               // bits description
    Uint16 ACQPS:9;                     // 8:0 SOC Acquisition Prescale
    Uint16 rsvd1:6;                     // 14:9 Reserved
    Uint32 CHSEL:4;                     // 18:15 SOC Channel Select
    Uint16 rsvd2:1;                     // 19 Reserved
    Uint16 TRIGSEL:5;                   // 24:20 SOC Trigger Source Select
    Uint16 rsvd3:7;                     // 31:25 Reserved
};

union ADCSOC10CTL_REG {
    Uint32  all;
    struct  ADCSOC10CTL_BITS  bit;
};

struct ADCSOC11CTL_BITS {               // bits description
    Uint16 ACQPS:9;                     // 8:0 SOC Acquisition Prescale
    Uint16 rsvd1:6;                     // 14:9 Reserved
    Uint32 CHSEL:4;                     // 18:15 SOC Channel Select
    Uint16 rsvd2:1;                     // 19 Reserved
    Uint16 TRIGSEL:5;                   // 24:20 SOC Trigger Source Select
    Uint16 rsvd3:7;                     // 31:25 Reserved
};

union ADCSOC11CTL_REG {
    Uint32  all;
    struct  ADCSOC11CTL_BITS  bit;
};

struct ADCSOC12CTL_BITS {               // bits description
    Uint16 ACQPS:9;                     // 8:0 SOC Acquisition Prescale
    Uint16 rsvd1:6;                     // 14:9 Reserved
    Uint32 CHSEL:4;                     // 18:15 SOC Channel Select
    Uint16 rsvd2:1;                     // 19 Reserved
    Uint16 TRIGSEL:5;                   // 24:20 SOC Trigger Source Select
    Uint16 rsvd3:7;                     // 31:25 Reserved
};

union ADCSOC12CTL_REG {
    Uint32  all;
    struct  ADCSOC12CTL_BITS  bit;
};

struct ADCSOC13CTL_BITS {               // bits description
    Uint16 ACQPS:9;                     // 8:0 SOC Acquisition Prescale
    Uint16 rsvd1:6;                     // 14:9 Reserved
    Uint32 CHSEL:4;                     // 18:15 SOC Channel Select
    Uint16 rsvd2:1;                     // 19 Reserved
    Uint16 TRIGSEL:5;                   // 24:20 SOC Trigger Source Select
    Uint16 rsvd3:7;                     // 31:25 Reserved
};

union ADCSOC13CTL_REG {
    Uint32  all;
    struct  ADCSOC13CTL_BITS  bit;
};

struct ADCSOC14CTL_BITS {               // bits description
    Uint16 ACQPS:9;                     // 8:0 SOC Acquisition Prescale
    Uint16 rsvd1:6;                     // 14:9 Reserved
    Uint32 CHSEL:4;                     // 18:15 SOC Channel Select
    Uint16 rsvd2:1;                     // 19 Reserved
    Uint16 TRIGSEL:5;                   // 24:20 SOC Trigger Source Select
    Uint16 rsvd3:7;                     // 31:25 Reserved
};

union ADCSOC14CTL_REG {
    Uint32  all;
    struct  ADCSOC14CTL_BITS  bit;
};

struct ADCSOC15CTL_BITS {               // bits description
    Uint16 ACQPS:9;                     // 8:0 SOC Acquisition Prescale
    Uint16 rsvd1:6;                     // 14:9 Reserved
    Uint32 CHSEL:4;                     // 18:15 SOC Channel Select
    Uint16 rsvd2:1;                     // 19 Reserved
    Uint16 TRIGSEL:5;                   // 24:20 SOC Trigger Source Select
    Uint16 rsvd3:7;                     // 31:25 Reserved
};

union ADCSOC15CTL_REG {
    Uint32  all;
    struct  ADCSOC15CTL_BITS  bit;
};

struct ADCEVTSTAT_BITS {                // bits description
    Uint16 PPB1TRIPHI:1;                // 0 Post Processing Block 1 Trip High Flag
    Uint16 PPB1TRIPLO:1;                // 1 Post Processing Block 1 Trip Low Flag
    Uint16 PPB1ZERO:1;                  // 2 Post Processing Block 1 Zero Crossing Flag
    Uint16 rsvd1:1;                     // 3 Reserved
    Uint16 PPB2TRIPHI:1;                // 4 Post Processing Block 2 Trip High Flag
    Uint16 PPB2TRIPLO:1;                // 5 Post Processing Block 2 Trip Low Flag
    Uint16 PPB2ZERO:1;                  // 6 Post Processing Block 2 Zero Crossing Flag
    Uint16 rsvd2:1;                     // 7 Reserved
    Uint16 PPB3TRIPHI:1;                // 8 Post Processing Block 3 Trip High Flag
    Uint16 PPB3TRIPLO:1;                // 9 Post Processing Block 3 Trip Low Flag
    Uint16 PPB3ZERO:1;                  // 10 Post Processing Block 3 Zero Crossing Flag
    Uint16 rsvd3:1;                     // 11 Reserved
    Uint16 PPB4TRIPHI:1;                // 12 Post Processing Block 4 Trip High Flag
    Uint16 PPB4TRIPLO:1;                // 13 Post Processing Block 4 Trip Low Flag
    Uint16 PPB4ZERO:1;                  // 14 Post Processing Block 4 Zero Crossing Flag
    Uint16 rsvd4:1;                     // 15 Reserved
};

union ADCEVTSTAT_REG {
    Uint16  all;
    struct  ADCEVTSTAT_BITS  bit;
};

struct ADCEVTCLR_BITS {                 // bits description
    Uint16 PPB1TRIPHI:1;                // 0 Post Processing Block 1 Trip High Clear
    Uint16 PPB1TRIPLO:1;                // 1 Post Processing Block 1 Trip Low Clear
    Uint16 PPB1ZERO:1;                  // 2 Post Processing Block 1 Zero Crossing Clear
    Uint16 rsvd1:1;                     // 3 Reserved
    Uint16 PPB2TRIPHI:1;                // 4 Post Processing Block 2 Trip High Clear
    Uint16 PPB2TRIPLO:1;                // 5 Post Processing Block 2 Trip Low Clear
    Uint16 PPB2ZERO:1;                  // 6 Post Processing Block 2 Zero Crossing Clear
    Uint16 rsvd2:1;                     // 7 Reserved
    Uint16 PPB3TRIPHI:1;                // 8 Post Processing Block 3 Trip High Clear
    Uint16 PPB3TRIPLO:1;                // 9 Post Processing Block 3 Trip Low Clear
    Uint16 PPB3ZERO:1;                  // 10 Post Processing Block 3 Zero Crossing Clear
    Uint16 rsvd3:1;                     // 11 Reserved
    Uint16 PPB4TRIPHI:1;                // 12 Post Processing Block 4 Trip High Clear
    Uint16 PPB4TRIPLO:1;                // 13 Post Processing Block 4 Trip Low Clear
    Uint16 PPB4ZERO:1;                  // 14 Post Processing Block 4 Zero Crossing Clear
    Uint16 rsvd4:1;                     // 15 Reserved
};

union ADCEVTCLR_REG {
    Uint16  all;
    struct  ADCEVTCLR_BITS  bit;
};

struct ADCEVTSEL_BITS {                 // bits description
    Uint16 PPB1TRIPHI:1;                // 0 Post Processing Block 1 Trip High Event Enable
    Uint16 PPB1TRIPLO:1;                // 1 Post Processing Block 1 Trip Low Event Enable
    Uint16 PPB1ZERO:1;                  // 2 Post Processing Block 1 Zero Crossing Event Enable
    Uint16 rsvd1:1;                     // 3 Reserved
    Uint16 PPB2TRIPHI:1;                // 4 Post Processing Block 2 Trip High Event Enable
    Uint16 PPB2TRIPLO:1;                // 5 Post Processing Block 2 Trip Low Event Enable
    Uint16 PPB2ZERO:1;                  // 6 Post Processing Block 2 Zero Crossing Event Enable
    Uint16 rsvd2:1;                     // 7 Reserved
    Uint16 PPB3TRIPHI:1;                // 8 Post Processing Block 3 Trip High Event Enable
    Uint16 PPB3TRIPLO:1;                // 9 Post Processing Block 3 Trip Low Event Enable
    Uint16 PPB3ZERO:1;                  // 10 Post Processing Block 3 Zero Crossing Event Enable
    Uint16 rsvd3:1;                     // 11 Reserved
    Uint16 PPB4TRIPHI:1;                // 12 Post Processing Block 4 Trip High Event Enable
    Uint16 PPB4TRIPLO:1;                // 13 Post Processing Block 4 Trip Low Event Enable
    Uint16 PPB4ZERO:1;                  // 14 Post Processing Block 4 Zero Crossing Event Enable
    Uint16 rsvd4:1;                     // 15 Reserved
};

union ADCEVTSEL_REG {
    Uint16  all;
    struct  ADCEVTSEL_BITS  bit;
};

struct ADCEVTINTSEL_BITS {              // bits description
    Uint16 PPB1TRIPHI:1;                // 0 Post Processing Block 1 Trip High Interrupt Enable
    Uint16 PPB1TRIPLO:1;                // 1 Post Processing Block 1 Trip Low Interrupt Enable
    Uint16 PPB1ZERO:1;                  // 2 Post Processing Block 1 Zero Crossing Interrupt Enable
    Uint16 rsvd1:1;                     // 3 Reserved
    Uint16 PPB2TRIPHI:1;                // 4 Post Processing Block 2 Trip High Interrupt Enable
    Uint16 PPB2TRIPLO:1;                // 5 Post Processing Block 2 Trip Low Interrupt Enable
    Uint16 PPB2ZERO:1;                  // 6 Post Processing Block 2 Zero Crossing Interrupt Enable
    Uint16 rsvd2:1;                     // 7 Reserved
    Uint16 PPB3TRIPHI:1;                // 8 Post Processing Block 3 Trip High Interrupt Enable
    Uint16 PPB3TRIPLO:1;                // 9 Post Processing Block 3 Trip Low Interrupt Enable
    Uint16 PPB3ZERO:1;                  // 10 Post Processing Block 3 Zero Crossing Interrupt Enable
    Uint16 rsvd3:1;                     // 11 Reserved
    Uint16 PPB4TRIPHI:1;                // 12 Post Processing Block 4 Trip High Interrupt Enable
    Uint16 PPB4TRIPLO:1;                // 13 Post Processing Block 4 Trip Low Interrupt Enable
    Uint16 PPB4ZERO:1;                  // 14 Post Processing Block 4 Zero Crossing Interrupt Enable
    Uint16 rsvd4:1;                     // 15 Reserved
};

union ADCEVTINTSEL_REG {
    Uint16  all;
    struct  ADCEVTINTSEL_BITS  bit;
};

struct ADCCOUNTER_BITS {                // bits description
    Uint16 FREECOUNT:12;                // 11:0 ADC Free Running Counter Value
    Uint16 rsvd1:4;                     // 15:12 Reserved
};

union ADCCOUNTER_REG {
    Uint16  all;
    struct  ADCCOUNTER_BITS  bit;
};

struct ADCREV_BITS {                    // bits description
    Uint16 TYPE:8;                      // 7:0 ADC Type
    Uint16 REV:8;                       // 15:8 ADC Revision
};

union ADCREV_REG {
    Uint16  all;
    struct  ADCREV_BITS  bit;
};

struct ADCOFFTRIM_BITS {                // bits description
    Uint16 OFFTRIM:8;                   // 7:0 ADC Offset Trim
    Uint16 rsvd1:8;                     // 15:8 Reserved
};

union ADCOFFTRIM_REG {
    Uint16  all;
    struct  ADCOFFTRIM_BITS  bit;
};

struct ADCPPB1CONFIG_BITS {             // bits description
    Uint16 CONFIG:4;                    // 3:0 ADC Post Processing Block Configuration
    Uint16 TWOSCOMPEN:1;                // 4 ADC Post Processing Block Two's Complement Enable
    Uint16 rsvd1:11;                    // 15:5 Reserved
};

union ADCPPB1CONFIG_REG {
    Uint16  all;
    struct  ADCPPB1CONFIG_BITS  bit;
};

struct ADCPPB1STAMP_BITS {              // bits description
    Uint16 DLYSTAMP:12;                 // 11:0 ADC Post Processing Block Delay Time Stamp
    Uint16 rsvd1:4;                     // 15:12 Reserved
};

union ADCPPB1STAMP_REG {
    Uint16  all;
    struct  ADCPPB1STAMP_BITS  bit;
};

struct ADCPPB1OFFCAL_BITS {             // bits description
    Uint16 OFFCAL:10;                   // 9:0 ADC Post Processing Block Offset Correction
    Uint16 rsvd1:6;                     // 15:10 Reserved
};

union ADCPPB1OFFCAL_REG {
    Uint16  all;
    struct  ADCPPB1OFFCAL_BITS  bit;
};

struct ADCPPB1TRIPHI_BITS {             // bits description
    Uint16 LIMITHI:16;                  // 15:0 ADC Post Processing Block Trip High Limit
    Uint16 HSIGN:1;                     // 16 High Limit Sign Bit
    Uint16 rsvd1:15;                    // 31:17 Reserved
};

union ADCPPB1TRIPHI_REG {
    Uint32  all;
    struct  ADCPPB1TRIPHI_BITS  bit;
};

struct ADCPPB1TRIPLO_BITS {             // bits description
    Uint16 LIMITLO:16;                  // 15:0 ADC Post Processing Block Trip Low Limit
    Uint16 LSIGN:1;                     // 16 Low Limit Sign Bit
    Uint16 rsvd1:3;                     // 19:17 Reserved
    Uint16 REQSTAMP:12;                 // 31:20 ADC Post Processing Block Request Time Stamp
};

union ADCPPB1TRIPLO_REG {
    Uint32  all;
    struct  ADCPPB1TRIPLO_BITS  bit;
};

struct ADCPPB2CONFIG_BITS {             // bits description
    Uint16 CONFIG:4;                    // 3:0 ADC Post Processing Block Configuration
    Uint16 TWOSCOMPEN:1;                // 4 ADC Post Processing Block Two's Complement Enable
    Uint16 rsvd1:11;                    // 15:5 Reserved
};

union ADCPPB2CONFIG_REG {
    Uint16  all;
    struct  ADCPPB2CONFIG_BITS  bit;
};

struct ADCPPB2STAMP_BITS {              // bits description
    Uint16 DLYSTAMP:12;                 // 11:0 ADC Post Processing Block Delay Time Stamp
    Uint16 rsvd1:4;                     // 15:12 Reserved
};

union ADCPPB2STAMP_REG {
    Uint16  all;
    struct  ADCPPB2STAMP_BITS  bit;
};

struct ADCPPB2OFFCAL_BITS {             // bits description
    Uint16 OFFCAL:10;                   // 9:0 ADC Post Processing Block Offset Correction
    Uint16 rsvd1:6;                     // 15:10 Reserved
};

union ADCPPB2OFFCAL_REG {
    Uint16  all;
    struct  ADCPPB2OFFCAL_BITS  bit;
};

struct ADCPPB2TRIPHI_BITS {             // bits description
    Uint16 LIMITHI:16;                  // 15:0 ADC Post Processing Block Trip High Limit
    Uint16 HSIGN:1;                     // 16 High Limit Sign Bit
    Uint16 rsvd1:15;                    // 31:17 Reserved
};

union ADCPPB2TRIPHI_REG {
    Uint32  all;
    struct  ADCPPB2TRIPHI_BITS  bit;
};

struct ADCPPB2TRIPLO_BITS {             // bits description
    Uint16 LIMITLO:16;                  // 15:0 ADC Post Processing Block Trip Low Limit
    Uint16 LSIGN:1;                     // 16 Low Limit Sign Bit
    Uint16 rsvd1:3;                     // 19:17 Reserved
    Uint16 REQSTAMP:12;                 // 31:20 ADC Post Processing Block Request Time Stamp
};

union ADCPPB2TRIPLO_REG {
    Uint32  all;
    struct  ADCPPB2TRIPLO_BITS  bit;
};

struct ADCPPB3CONFIG_BITS {             // bits description
    Uint16 CONFIG:4;                    // 3:0 ADC Post Processing Block Configuration
    Uint16 TWOSCOMPEN:1;                // 4 ADC Post Processing Block Two's Complement Enable
    Uint16 rsvd1:11;                    // 15:5 Reserved
};

union ADCPPB3CONFIG_REG {
    Uint16  all;
    struct  ADCPPB3CONFIG_BITS  bit;
};

struct ADCPPB3STAMP_BITS {              // bits description
    Uint16 DLYSTAMP:12;                 // 11:0 ADC Post Processing Block Delay Time Stamp
    Uint16 rsvd1:4;                     // 15:12 Reserved
};

union ADCPPB3STAMP_REG {
    Uint16  all;
    struct  ADCPPB3STAMP_BITS  bit;
};

struct ADCPPB3OFFCAL_BITS {             // bits description
    Uint16 OFFCAL:10;                   // 9:0 ADC Post Processing Block Offset Correction
    Uint16 rsvd1:6;                     // 15:10 Reserved
};

union ADCPPB3OFFCAL_REG {
    Uint16  all;
    struct  ADCPPB3OFFCAL_BITS  bit;
};

struct ADCPPB3TRIPHI_BITS {             // bits description
    Uint16 LIMITHI:16;                  // 15:0 ADC Post Processing Block Trip High Limit
    Uint16 HSIGN:1;                     // 16 High Limit Sign Bit
    Uint16 rsvd1:15;                    // 31:17 Reserved
};

union ADCPPB3TRIPHI_REG {
    Uint32  all;
    struct  ADCPPB3TRIPHI_BITS  bit;
};

struct ADCPPB3TRIPLO_BITS {             // bits description
    Uint16 LIMITLO:16;                  // 15:0 ADC Post Processing Block Trip Low Limit
    Uint16 LSIGN:1;                     // 16 Low Limit Sign Bit
    Uint16 rsvd1:3;                     // 19:17 Reserved
    Uint16 REQSTAMP:12;                 // 31:20 ADC Post Processing Block Request Time Stamp
};

union ADCPPB3TRIPLO_REG {
    Uint32  all;
    struct  ADCPPB3TRIPLO_BITS  bit;
};

struct ADCPPB4CONFIG_BITS {             // bits description
    Uint16 CONFIG:4;                    // 3:0 ADC Post Processing Block Configuration
    Uint16 TWOSCOMPEN:1;                // 4 ADC Post Processing Block Two's Complement Enable
    Uint16 rsvd1:11;                    // 15:5 Reserved
};

union ADCPPB4CONFIG_REG {
    Uint16  all;
    struct  ADCPPB4CONFIG_BITS  bit;
};

struct ADCPPB4STAMP_BITS {              // bits description
    Uint16 DLYSTAMP:12;                 // 11:0 ADC Post Processing Block Delay Time Stamp
    Uint16 rsvd1:4;                     // 15:12 Reserved
};

union ADCPPB4STAMP_REG {
    Uint16  all;
    struct  ADCPPB4STAMP_BITS  bit;
};

struct ADCPPB4OFFCAL_BITS {             // bits description
    Uint16 OFFCAL:10;                   // 9:0 ADC Post Processing Block Offset Correction
    Uint16 rsvd1:6;                     // 15:10 Reserved
};

union ADCPPB4OFFCAL_REG {
    Uint16  all;
    struct  ADCPPB4OFFCAL_BITS  bit;
};

struct ADCPPB4TRIPHI_BITS {             // bits description
    Uint16 LIMITHI:16;                  // 15:0 ADC Post Processing Block Trip High Limit
    Uint16 HSIGN:1;                     // 16 High Limit Sign Bit
    Uint16 rsvd1:15;                    // 31:17 Reserved
};

union ADCPPB4TRIPHI_REG {
    Uint32  all;
    struct  ADCPPB4TRIPHI_BITS  bit;
};

struct ADCPPB4TRIPLO_BITS {             // bits description
    Uint16 LIMITLO:16;                  // 15:0 ADC Post Processing Block Trip Low Limit
    Uint16 LSIGN:1;                     // 16 Low Limit Sign Bit
    Uint16 rsvd1:3;                     // 19:17 Reserved
    Uint16 REQSTAMP:12;                 // 31:20 ADC Post Processing Block Request Time Stamp
};

union ADCPPB4TRIPLO_REG {
    Uint32  all;
    struct  ADCPPB4TRIPLO_BITS  bit;
};

struct ADC_REGS {
    union   ADCCTL1_REG                      ADCCTL1;                      // ADC Control 1 Register
    union   ADCCTL2_REG                      ADCCTL2;                      // ADC Control 2 Register
    union   ADCBURSTCTL_REG                  ADCBURSTCTL;                  // ADC Burst Control Register
    union   ADCINTFLG_REG                    ADCINTFLG;                    // ADC Interrupt Flag Register
    union   ADCINTFLGCLR_REG                 ADCINTFLGCLR;                 // ADC Interrupt Flag Clear Register
    union   ADCINTOVF_REG                    ADCINTOVF;                    // ADC Interrupt Overflow Register
    union   ADCINTOVFCLR_REG                 ADCINTOVFCLR;                 // ADC Interrupt Overflow Clear Register
    union   ADCINTSEL1N2_REG                 ADCINTSEL1N2;                 // ADC Interrupt 1 and 2 Selection Register
    union   ADCINTSEL3N4_REG                 ADCINTSEL3N4;                 // ADC Interrupt 3 and 4 Selection Register
    union   ADCSOCPRICTL_REG                 ADCSOCPRICTL;                 // ADC SOC Priority Control Register
    union   ADCINTSOCSEL1_REG                ADCINTSOCSEL1;                // ADC Interrupt SOC Selection 1 Register
    union   ADCINTSOCSEL2_REG                ADCINTSOCSEL2;                // ADC Interrupt SOC Selection 2 Register
    union   ADCSOCFLG1_REG                   ADCSOCFLG1;                   // ADC SOC Flag 1 Register
    union   ADCSOCFRC1_REG                   ADCSOCFRC1;                   // ADC SOC Force 1 Register
    union   ADCSOCOVF1_REG                   ADCSOCOVF1;                   // ADC SOC Overflow 1 Register
    union   ADCSOCOVFCLR1_REG                ADCSOCOVFCLR1;                // ADC SOC Overflow Clear 1 Register
    union   ADCSOC0CTL_REG                   ADCSOC0CTL;                   // ADC SOC0 Control Register
    union   ADCSOC1CTL_REG                   ADCSOC1CTL;                   // ADC SOC1 Control Register
    union   ADCSOC2CTL_REG                   ADCSOC2CTL;                   // ADC SOC2 Control Register
    union   ADCSOC3CTL_REG                   ADCSOC3CTL;                   // ADC SOC3 Control Register
    union   ADCSOC4CTL_REG                   ADCSOC4CTL;                   // ADC SOC4 Control Register
    union   ADCSOC5CTL_REG                   ADCSOC5CTL;                   // ADC SOC5 Control Register
    union   ADCSOC6CTL_REG                   ADCSOC6CTL;                   // ADC SOC6 Control Register
    union   ADCSOC7CTL_REG                   ADCSOC7CTL;                   // ADC SOC7 Control Register
    union   ADCSOC8CTL_REG                   ADCSOC8CTL;                   // ADC SOC8 Control Register
    union   ADCSOC9CTL_REG                   ADCSOC9CTL;                   // ADC SOC9 Control Register
    union   ADCSOC10CTL_REG                  ADCSOC10CTL;                  // ADC SOC10 Control Register
    union   ADCSOC11CTL_REG                  ADCSOC11CTL;                  // ADC SOC11 Control Register
    union   ADCSOC12CTL_REG                  ADCSOC12CTL;                  // ADC SOC12 Control Register
    union   ADCSOC13CTL_REG                  ADCSOC13CTL;                  // ADC SOC13 Control Register
    union   ADCSOC14CTL_REG                  ADCSOC14CTL;                  // ADC SOC14 Control Register
    union   ADCSOC15CTL_REG                  ADCSOC15CTL;                  // ADC SOC15 Control Register
    union   ADCEVTSTAT_REG                   ADCEVTSTAT;                   // ADC Event Status Register
    Uint16                                   rsvd1;                        // Reserved
    union   ADCEVTCLR_REG                    ADCEVTCLR;                    // ADC Event Clear Register
    Uint16                                   rsvd2;                        // Reserved
    union   ADCEVTSEL_REG                    ADCEVTSEL;                    // ADC Event Selection Register
    Uint16                                   rsvd3;                        // Reserved
    union   ADCEVTINTSEL_REG                 ADCEVTINTSEL;                 // ADC Event Interrupt Selection Register
    Uint16                                   rsvd4[2];                     // Reserved
    union   ADCCOUNTER_REG                   ADCCOUNTER;                   // ADC Counter Register
    union   ADCREV_REG                       ADCREV;                       // ADC Revision Register
    union   ADCOFFTRIM_REG                   ADCOFFTRIM;                   // ADC Offset Trim Register
    Uint16                                   rsvd5[4];                     // Reserved
    union   ADCPPB1CONFIG_REG                ADCPPB1CONFIG;                // ADC PPB1 Config Register
    union   ADCPPB1STAMP_REG                 ADCPPB1STAMP;                 // ADC PPB1 Sample Delay Time Stamp Register
    union   ADCPPB1OFFCAL_REG                ADCPPB1OFFCAL;                // ADC PPB1 Offset Calibration Register
    Uint16                                   ADCPPB1OFFREF;                // ADC PPB1 Offset Reference Register
    union   ADCPPB1TRIPHI_REG                ADCPPB1TRIPHI;                // ADC PPB1 Trip High Register
    union   ADCPPB1TRIPLO_REG                ADCPPB1TRIPLO;                // ADC PPB1 Trip Low/Trigger Time Stamp Register
    union   ADCPPB2CONFIG_REG                ADCPPB2CONFIG;                // ADC PPB2 Config Register
    union   ADCPPB2STAMP_REG                 ADCPPB2STAMP;                 // ADC PPB2 Sample Delay Time Stamp Register
    union   ADCPPB2OFFCAL_REG                ADCPPB2OFFCAL;                // ADC PPB2 Offset Calibration Register
    Uint16                                   ADCPPB2OFFREF;                // ADC PPB2 Offset Reference Register
    union   ADCPPB2TRIPHI_REG                ADCPPB2TRIPHI;                // ADC PPB2 Trip High Register
    union   ADCPPB2TRIPLO_REG                ADCPPB2TRIPLO;                // ADC PPB2 Trip Low/Trigger Time Stamp Register
    union   ADCPPB3CONFIG_REG                ADCPPB3CONFIG;                // ADC PPB3 Config Register
    union   ADCPPB3STAMP_REG                 ADCPPB3STAMP;                 // ADC PPB3 Sample Delay Time Stamp Register
    union   ADCPPB3OFFCAL_REG                ADCPPB3OFFCAL;                // ADC PPB3 Offset Calibration Register
    Uint16                                   ADCPPB3OFFREF;                // ADC PPB3 Offset Reference Register
    union   ADCPPB3TRIPHI_REG                ADCPPB3TRIPHI;                // ADC PPB3 Trip High Register
    union   ADCPPB3TRIPLO_REG                ADCPPB3TRIPLO;                // ADC PPB3 Trip Low/Trigger Time Stamp Register
    union   ADCPPB4CONFIG_REG                ADCPPB4CONFIG;                // ADC PPB4 Config Register
    union   ADCPPB4STAMP_REG                 ADCPPB4STAMP;                 // ADC PPB4 Sample Delay Time Stamp Register
    union   ADCPPB4OFFCAL_REG                ADCPPB4OFFCAL;                // ADC PPB4 Offset Calibration Register
    Uint16                                   ADCPPB4OFFREF;                // ADC PPB4 Offset Reference Register
    union   ADCPPB4TRIPHI_REG                ADCPPB4TRIPHI;                // ADC PPB4 Trip High Register
    union   ADCPPB4TRIPLO_REG                ADCPPB4TRIPLO;                // ADC PPB4 Trip Low/Trigger Time Stamp Register
    Uint16                                   rsvd6[16];                    // Reserved
    Uint32                                   ADCINLTRIM1;                  // ADC Linearity Trim 1 Register
    Uint32                                   ADCINLTRIM2;                  // ADC Linearity Trim 2 Register
    Uint32                                   ADCINLTRIM3;                  // ADC Linearity Trim 3 Register
    Uint32                                   ADCINLTRIM4;                  // ADC Linearity Trim 4 Register
    Uint32                                   ADCINLTRIM5;                  // ADC Linearity Trim 5 Register
    Uint32                                   ADCINLTRIM6;                  // ADC Linearity Trim 6 Register
    Uint16                                   rsvd7[4];                     // Reserved
};

struct ADCPPB1RESULT_BITS {             // bits description
    Uint16 PPBRESULT:16;                // 15:0 ADC Post Processing Block Result
    Uint16 SIGN:16;                     // 31:16 Sign Extended Bits
};

union ADCPPB1RESULT_REG {
    Uint32  all;
    struct  ADCPPB1RESULT_BITS  bit;
};

struct ADCPPB2RESULT_BITS {             // bits description
    Uint16 PPBRESULT:16;                // 15:0 ADC Post Processing Block Result
    Uint16 SIGN:16;                     // 31:16 Sign Extended Bits
};

union ADCPPB2RESULT_REG {
    Uint32  all;
    struct  ADCPPB2RESULT_BITS  bit;
};

struct ADCPPB3RESULT_BITS {             // bits description
    Uint16 PPBRESULT:16;                // 15:0 ADC Post Processing Block Result
    Uint16 SIGN:16;                     // 31:16 Sign Extended Bits
};

union ADCPPB3RESULT_REG {
    Uint32  all;
    struct  ADCPPB3RESULT_BITS  bit;
};

struct ADCPPB4RESULT_BITS {             // bits description
    Uint16 PPBRESULT:16;                // 15:0 ADC Post Processing Block Result
    Uint16 SIGN:16;                     // 31:16 Sign Extended Bits
};

union ADCPPB4RESULT_REG {
    Uint32  all;
    struct  ADCPPB4RESULT_BITS  bit;
};

struct ADC_RESULT_REGS {
    Uint16                                   ADCRESULT0;                   // ADC Result 0 Register
    Uint16                                   ADCRESULT1;                   // ADC Result 1 Register
    Uint16                                   ADCRESULT2;                   // ADC Result 2 Register
    Uint16                                   ADCRESULT3;                   // ADC Result 3 Register
    Uint16                                   ADCRESULT4;                   // ADC Result 4 Register
    Uint16                                   ADCRESULT5;                   // ADC Result 5 Register
    Uint16                                   ADCRESULT6;                   // ADC Result 6 Register
    Uint16                                   ADCRESULT7;                   // ADC Result 7 Register
    Uint16                                   ADCRESULT8;                   // ADC Result 8 Register
    Uint16                                   ADCRESULT9;                   // ADC Result 9 Register
    Uint16                                   ADCRESULT10;                  // ADC Result 10 Register
    Uint16                                   ADCRESULT11;                  // ADC Result 11 Register
    Uint16                                   ADCRESULT12;                  // ADC Result 12 Register
    Uint16                                   ADCRESULT13;                  // ADC Result 13 Register
    Uint16                                   ADCRESULT14;                  // ADC Result 14 Register
    Uint16                                   ADCRESULT15;                  // ADC Result 15 Register
    union   ADCPPB1RESULT_REG                ADCPPB1RESULT;                // ADC Post Processing Block 1 Result Register
    union   ADCPPB2RESULT_REG                ADCPPB2RESULT;                // ADC Post Processing Block 2 Result Register
    union   ADCPPB3RESULT_REG                ADCPPB3RESULT;                // ADC Post Processing Block 3 Result Register
    union   ADCPPB4RESULT_REG                ADCPPB4RESULT;                // ADC Post Processing Block 4 Result Register
};

//---------------------------------------------------------------------------
// ADC External References & Function Declarations:
//
extern volatile struct ADC_RESULT_REGS AdcaResultRegs;
extern volatile struct ADC_RESULT_REGS AdcbResultRegs;
extern volatile struct ADC_RESULT_REGS AdccResultRegs;
extern volatile struct ADC_RESULT_REGS AdcdResultRegs;
extern volatile struct ADC_REGS AdcaRegs;
extern volatile struct ADC_REGS AdcbRegs;
extern volatile struct ADC_REGS AdccRegs;
extern volatile struct ADC_REGS AdcdRegs;
#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================
