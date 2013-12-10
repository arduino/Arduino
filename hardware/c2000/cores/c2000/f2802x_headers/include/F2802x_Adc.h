// TI File $Revision: /main/7 $
// Checkin $Date: December 21, 2010   13:59:36 $
//###########################################################################
//
// FILE:   DSP2802x_Adc.h
//
// TITLE:  DSP2802x Device ADC Register Definitions.
//
//###########################################################################
// $TI Release: f2802x Support Library v210 $
// $Release Date: Mon Sep 17 09:13:31 CDT 2012 $
//###########################################################################

#ifndef DSP2802x_ADC_H
#define DSP2802x_ADC_H

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// ADC Individual Register Bit Definitions:

struct ADCCTL1_BITS {      // bits  description
    Uint16  TEMPCONV:1;    // 0     Temperature sensor connection
    Uint16  VREFLOCONV:1;  // 1     VSSA connection
    Uint16  INTPULSEPOS:1; // 2     INT pulse generation control
    Uint16  ADCREFSEL:1;   // 3     Internal/external reference select
    Uint16  rsvd1:1;       // 4     reserved
    Uint16  ADCREFPWD:1;   // 5     Reference buffers powerdown
    Uint16  ADCBGPWD:1;    // 6     ADC bandgap powerdown
    Uint16  ADCPWDN:1;     // 7     ADC powerdown
    Uint16  ADCBSYCHN:5;   // 12:8  ADC busy on a channel
    Uint16  ADCBSY:1;      // 13    ADC busy signal
    Uint16  ADCENABLE:1;   // 14    ADC enable
    Uint16  RESET:1;       // 15    ADC master reset
};


union ADCCTL1_REG {
   Uint16                all;
   struct ADCCTL1_BITS   bit;
};

// This register is not supported in Rev. 0 silicon.
struct ADCCTL2_BITS {        // bits  description
    Uint16  CLKDIV2EN:1;     // 0     ADC input clock /2 enable
    Uint16  ADCNONOVERLAP:1; // 1     ADCNONOVERLAP Control bit
    Uint16  rsvd1:14;        // 15:2  reserved
};

union ADCCTL2_REG {
   Uint16                all;
   struct ADCCTL2_BITS   bit;
};

struct ADCINT_BITS {       // bits   description
    Uint16  ADCINT1:1;     // 0      ADC Interrupt Flag 1
    Uint16  ADCINT2:1;     // 1      ADC Interrupt Flag 2
    Uint16  ADCINT3:1;     // 2      ADC Interrupt Flag 3
    Uint16  ADCINT4:1;     // 3      ADC Interrupt Flag 4
    Uint16  ADCINT5:1;     // 4      ADC Interrupt Flag 5
    Uint16  ADCINT6:1;     // 5      ADC Interrupt Flag 6
    Uint16  ADCINT7:1;     // 6      ADC Interrupt Flag 7
    Uint16  ADCINT8:1;     // 7      ADC Interrupt Flag 8
    Uint16  ADCINT9:1;     // 8      ADC Interrupt Flag 9
    Uint16  rsvd1:7;       // 15:9   reserved
};

union ADCINT_REG {
   Uint16                 all;
   struct ADCINT_BITS     bit;
};

struct INTSEL1N2_BITS {       // bits   description
    Uint16  INT1SEL:5;        // 4:0    INTx EOC Source Select
    Uint16  INT1E:1;          // 5      INTx Interrupt Enable
    Uint16  INT1CONT:1;       // 6      INTx Continuous Mode Enable
    Uint16  rsvd1:1;          // 7      reserved
    Uint16  INT2SEL:5;        // 12:8   INTy EOC Source Select
    Uint16  INT2E:1;          // 13     INTy Interrupt Enable
    Uint16  INT2CONT:1;       // 14     INTy Continuous Mode Enable
    Uint16  rsvd2:1;          // 15     reserved
};

union INTSEL1N2_REG {
    Uint16                all;
    struct INTSEL1N2_BITS bit;
};


struct INTSEL3N4_BITS {       // bits   description
    Uint16  INT3SEL:5;        // 4:0    INTx EOC Source Select
    Uint16  INT3E:1;          // 5      INTx Interrupt Enable
    Uint16  INT3CONT:1;       // 6      INTx Continuous Mode Enable
    Uint16  rsvd1:1;          // 7      reserved
    Uint16  INT4SEL:5;        // 12:8   INTy EOC Source Select
    Uint16  INT4E:1;          // 13     INTy Interrupt Enable
    Uint16  INT4CONT:1;       // 14     INTy Continuous Mode Enable
    Uint16  rsvd2:1;          // 15     reserved
};

union INTSEL3N4_REG {
    Uint16                all;
    struct INTSEL3N4_BITS bit;
};


struct INTSEL5N6_BITS {       // bits   description
    Uint16  INT5SEL:5;        // 4:0    INTx EOC Source Select
    Uint16  INT5E:1;          // 5      INTx Interrupt Enable
    Uint16  INT5CONT:1;       // 6      INTx Continuous Mode Enable
    Uint16  rsvd1:1;          // 7      reserved
    Uint16  INT6SEL:5;        // 12:8   INTy EOC Source Select
    Uint16  INT6E:1;          // 13     INTy Interrupt Enable
    Uint16  INT6CONT:1;       // 14     INTy Continuous Mode Enable
    Uint16  rsvd2:1;          // 15     reserved
};

union INTSEL5N6_REG {
    Uint16                all;
    struct INTSEL5N6_BITS bit;
};


struct INTSEL7N8_BITS {       // bits   description
    Uint16  INT7SEL:5;        // 4:0    INTx EOC Source Select
    Uint16  INT7E:1;          // 5      INTx Interrupt Enable
    Uint16  INT7CONT:1;       // 6      INTx Continuous Mode Enable
    Uint16  rsvd1:1;          // 7      reserved
    Uint16  INT8SEL:5;        // 12:8   INTy EOC Source Select
    Uint16  INT8E:1;          // 13     INTy Interrupt Enable
    Uint16  INT8CONT:1;       // 14     INTy Continuous Mode Enable
    Uint16  rsvd2:1;          // 15     reserved
};

union INTSEL7N8_REG {
    Uint16                all;
    struct INTSEL7N8_BITS bit;
};


struct INTSEL9N10_BITS {      // bits   description
    Uint16  INT9SEL:5;        // 4:0    INTx EOC Source Select
    Uint16  INT9E:1;          // 5      INTx Interrupt Enable
    Uint16  INT9CONT:1;       // 6      INTx Continuous Mode Enable
    Uint16  rsvd1:1;          // 7      reserved
    Uint16  INT10SEL:5;       // 12:8   INTy EOC Source Select
    Uint16  INT10E:1;         // 13     INTy Interrupt Enable
    Uint16  INT10CONT:1;      // 14     INTy Continuous Mode Enable
    Uint16  rsvd2:1;          // 15     reserved
};

union INTSEL9N10_REG {
    Uint16                all;
    struct INTSEL9N10_BITS bit;
};

struct SOCPRICTL_BITS {       // bits   description
    Uint16  SOCPRIORITY:5;    // 4:0    Start-of-conversion Priority
    Uint16  RRPOINTER:6;      // 10:5   Round Robin Pointer
    Uint16  rsvd1:4;          // 14:11  reserved
    Uint16  ONESHOT:1;        // 15     One Shot Mode Enabled - bit does not exist in Rev. 0 silicon
};

union SOCPRICTL_REG {
    Uint16                 all;
    struct SOCPRICTL_BITS  bit;
};

struct ADCSAMPLEMODE_BITS {   // bits   description
    Uint16 SIMULEN0:1;        // 0      SOC0 Simultaneous Sampling Enable
    Uint16 SIMULEN2:1;        // 1      SOC2 Simultaneous Sampling Enable
    Uint16 SIMULEN4:1;        // 2      SOC4 Simultaneous Sampling Enable
    Uint16 SIMULEN6:1;        // 3      SOC6 Simultaneous Sampling Enable
    Uint16 SIMULEN8:1;        // 4      SOC8 Simultaneous Sampling Enable
    Uint16 SIMULEN10:1;       // 5      SOC10 Simultaneous Sampling Enable
    Uint16 SIMULEN12:1;       // 6      SOC12 Simultaneous Sampling Enable
    Uint16 SIMULEN14:1;       // 7      SOC14 Simultaneous Sampling Enable
    Uint16 rsvd1:8;           //15:8    reserved
};

union ADCSAMPLEMODE_REG {
    Uint16                      all;
    struct ADCSAMPLEMODE_BITS   bit;
};

struct ADCINTSOCSEL1_BITS {   // bits   description
    Uint16 SOC0:2;            // 1:0      ADCINT Start-of-conversion Select
    Uint16 SOC1:2;            // 3:2      ADCINT Start-of-conversion Select
    Uint16 SOC2:2;            // 5:4      ADCINT Start-of-conversion Select
    Uint16 SOC3:2;            // 7:6      ADCINT Start-of-conversion Select
    Uint16 SOC4:2;            // 9:8      ADCINT Start-of-conversion Select
    Uint16 SOC5:2;            // 11:10    ADCINT Start-of-conversion Select
    Uint16 SOC6:2;            // 13:12    ADCINT Start-of-conversion Select
    Uint16 SOC7:2;            // 15:14    ADCINT Start-of-conversion Select
};

union ADCINTSOCSEL1_REG {
    Uint16                    all;
    struct ADCINTSOCSEL1_BITS bit;
};

struct ADCINTSOCSEL2_BITS {   // bits   description
    Uint16 SOC8:2;            // 1:0      ADCINT Start-of-conversion Select
    Uint16 SOC9:2;            // 3:2      ADCINT Start-of-conversion Select
    Uint16 SOC10:2;           // 5:4      ADCINT Start-of-conversion Select
    Uint16 SOC11:2;           // 7:6      ADCINT Start-of-conversion Select
    Uint16 SOC12:2;           // 9:8      ADCINT Start-of-conversion Select
    Uint16 SOC13:2;           // 11:10    ADCINT Start-of-conversion Select
    Uint16 SOC14:2;           // 13:12    ADCINT Start-of-conversion Select
    Uint16 SOC15:2;           // 15:14    ADCINT Start-of-conversion Select
};

union ADCINTSOCSEL2_REG {
    Uint16                    all;
    struct ADCINTSOCSEL2_BITS bit;
};

struct ADCSOC_BITS {          // bits  description
    Uint16 SOC0:1;            // 0     Start-of-conversion for CONV0
    Uint16 SOC1:1;            // 1     Start-of-conversion for CONV1
    Uint16 SOC2:1;            // 2     Start-of-conversion for CONV2
    Uint16 SOC3:1;            // 3     Start-of-conversion for CONV3
    Uint16 SOC4:1;            // 4     Start-of-conversion for CONV4
    Uint16 SOC5:1;            // 5     Start-of-conversion for CONV5
    Uint16 SOC6:1;            // 6     Start-of-conversion for CONV6
    Uint16 SOC7:1;            // 7     Start-of-conversion for CONV7
    Uint16 SOC8:1;            // 8     Start-of-conversion for CONV8
    Uint16 SOC9:1;            // 9     Start-of-conversion for CONV9
    Uint16 SOC10:1;           // 10    Start-of-conversion for CONV10
    Uint16 SOC11:1;           // 11    Start-of-conversion for CONV11
    Uint16 SOC12:1;           // 12    Start-of-conversion for CONV12
    Uint16 SOC13:1;           // 13    Start-of-conversion for CONV13
    Uint16 SOC14:1;           // 14    Start-of-conversion for CONV14
    Uint16 SOC15:1;           // 15    Start-of-conversion for CONV15
};

union ADCSOC_REG {
    Uint16                    all;
    struct ADCSOC_BITS        bit;
};

struct ADCSOCxCTL_BITS {      // bits  description
    Uint16 ACQPS:6;           // 5:0   Acquisition Pulse Size
    Uint16 CHSEL:4;           // 9:6   SOCx Channel Select
    Uint16 rsvd1:1;           // 10    reserved
    Uint16 TRIGSEL:5;         // 15:11 SOCx Trigger Select
};

union ADCSOCxCTL_REG {
    Uint16                  all;
    struct ADCSOCxCTL_BITS  bit;
};

// Rev. 0 silicon - BG_FINE_TRIM = bits 3:0.
//                  BG_COARSE_TRIM = bits : 8:4
// Rev. A and beyond silicon = below register definition:
struct ADCREFTRIM_BITS{         // bits   description
    Uint16  BG_FINE_TRIM:5;     // 4:0    Coarse trim for internal BG
    Uint16  BG_COARSE_TRIM:4;   // 8:5    Fine trim for internal BG
    Uint16  EXTREF_FINE_TRIM:5; // 13:9   Fine trim for external reference
    Uint16  rsvd1:2;            // 15:14  reserved
};

union ADCREFTRIM_REG{
    Uint16      all;
    struct ADCREFTRIM_BITS bit;
};

struct ADCOFFTRIM_BITS{       // bits   description
    int16   OFFTRIM:9;        // 8:0    Offset Trim
    Uint16  rsvd1:7;          // 15:9   reserved
};

union ADCOFFTRIM_REG{
    Uint16      all;
    struct ADCOFFTRIM_BITS bit;
};

struct COMPHYSTCTL_BITS{                // bits description
    Uint16  rsvd1:1;                    // 0    reserved
    Uint16  COMP1_HYST_DISABLE:1;      // 1    Comparator 1 Hysteresis Disable
    Uint16  rsvd2:4;                   // 5:2  reserved
    Uint16  COMP2_HYST_DISABLE:1;      // 6    Comparator 2 Hysteresis Disable
    Uint16  rsvd3:10;                  // 15:7 reserved
};

union COMPHYSTCTL_REG{
    Uint16      all;
    struct COMPHYSTCTL_BITS bit;
};

//---------------------------------------------------------------------------
// ADC Register Definitions:

struct ADC_REGS {
    union  ADCCTL1_REG           ADCCTL1;         // ADC Control 1
    union  ADCCTL2_REG           ADCCTL2;         // ADC Control 2 - not available in Rev. 0 silicon
    Uint16                       rsvd1[2];        // reserved
    union  ADCINT_REG            ADCINTFLG;       // ADC Interrupt Flag
    union  ADCINT_REG            ADCINTFLGCLR;    // ADC Interrupt Flag Clear
    union  ADCINT_REG            ADCINTOVF;       // ADC Interrupt Overflow
    union  ADCINT_REG            ADCINTOVFCLR;    // ADC Interrupt Overflow Clear
    union  INTSEL1N2_REG         INTSEL1N2;       // ADC Interrupt 1 and 2 Selection
    union  INTSEL3N4_REG         INTSEL3N4;       // ADC Interrupt 3 and 4 Selection
    union  INTSEL5N6_REG         INTSEL5N6;       // ADC Interrupt 5 and 6 Selection
    union  INTSEL7N8_REG         INTSEL7N8;       // ADC Interrupt 7 and 8 Selection
    union  INTSEL9N10_REG        INTSEL9N10;      // ADC Interrupt 9 and 10 Selection
    Uint16                       rsvd2[3];        // reserved
    union  SOCPRICTL_REG         SOCPRICTL;       // ADC SOC Priority Control
    Uint16                       rsvd3;           // reserved
    union  ADCSAMPLEMODE_REG     ADCSAMPLEMODE;   // ADC Sampling Mode
    Uint16                       rsvd4;           // reserved
    union  ADCINTSOCSEL1_REG     ADCINTSOCSEL1;   // ADC Interrupt SOC Selection 1
    union  ADCINTSOCSEL2_REG     ADCINTSOCSEL2;   // ADC Interrupt SOC Selection 2
    Uint16                       rsvd5[2];        // reserved
    union  ADCSOC_REG            ADCSOCFLG1;      // ADC SOC Flag 1
    Uint16                       rsvd6;           // reserved
    union  ADCSOC_REG            ADCSOCFRC1;      // ADC SOC Flag Force 1
    Uint16                       rsvd7;           // reserved
    union  ADCSOC_REG            ADCSOCOVF1;      // ADC SOC Overflow 1
    Uint16                       rsvd8;           // reserved
    union  ADCSOC_REG            ADCSOCOVFCLR1;   // ADC SOC Overflow Clear 1
    Uint16                       rsvd9;           // reserved
    union  ADCSOCxCTL_REG        ADCSOC0CTL;      // ADC SOC0 Control
    union  ADCSOCxCTL_REG        ADCSOC1CTL;      // ADC SOC1 Control
    union  ADCSOCxCTL_REG        ADCSOC2CTL;      // ADC SOC2 Control
    union  ADCSOCxCTL_REG        ADCSOC3CTL;      // ADC SOC3 Control
    union  ADCSOCxCTL_REG        ADCSOC4CTL;      // ADC SOC4 Control
    union  ADCSOCxCTL_REG        ADCSOC5CTL;      // ADC SOC5 Control
    union  ADCSOCxCTL_REG        ADCSOC6CTL;      // ADC SOC6 Control
    union  ADCSOCxCTL_REG        ADCSOC7CTL;      // ADC SOC7 Control
    union  ADCSOCxCTL_REG        ADCSOC8CTL;      // ADC SOC8 Control
    union  ADCSOCxCTL_REG        ADCSOC9CTL;      // ADC SOC9 Control
    union  ADCSOCxCTL_REG        ADCSOC10CTL;     // ADC SOC10 Control
    union  ADCSOCxCTL_REG        ADCSOC11CTL;     // ADC SOC11 Control
    union  ADCSOCxCTL_REG        ADCSOC12CTL;     // ADC SOC12 Control
    union  ADCSOCxCTL_REG        ADCSOC13CTL;     // ADC SOC13 Control
    union  ADCSOCxCTL_REG        ADCSOC14CTL;     // ADC SOC14 Control
    union  ADCSOCxCTL_REG        ADCSOC15CTL;     // ADC SOC15 Control
    Uint16                       rsvd10 [16];     // reserved
    union  ADCREFTRIM_REG        ADCREFTRIM;      // Reference Trim Register
    union  ADCOFFTRIM_REG        ADCOFFTRIM;      // Offset Trim Register
    Uint16                       rsvd11 [10];     // reserved
    union  COMPHYSTCTL_REG       COMPHYSTCTL;     // COMP Hysteresis Control Register
    Uint16                       rsvd12 [3];      // reserved
};


struct ADC_RESULT_REGS
{
    Uint16                 ADCRESULT0;    // Conversion Result Buffer 0
    Uint16                 ADCRESULT1;    // Conversion Result Buffer 1
    Uint16                 ADCRESULT2;    // Conversion Result Buffer 2
    Uint16                 ADCRESULT3;    // Conversion Result Buffer 3
    Uint16                 ADCRESULT4;    // Conversion Result Buffer 4
    Uint16                 ADCRESULT5;    // Conversion Result Buffer 5
    Uint16                 ADCRESULT6;    // Conversion Result Buffer 6
    Uint16                 ADCRESULT7;    // Conversion Result Buffer 7
    Uint16                 ADCRESULT8;    // Conversion Result Buffer 8
    Uint16                 ADCRESULT9;    // Conversion Result Buffer 9
    Uint16                 ADCRESULT10;   // Conversion Result Buffer 10
    Uint16                 ADCRESULT11;   // Conversion Result Buffer 11
    Uint16                 ADCRESULT12;   // Conversion Result Buffer 12
    Uint16                 ADCRESULT13;   // Conversion Result Buffer 13
    Uint16                 ADCRESULT14;   // Conversion Result Buffer 14
    Uint16                 ADCRESULT15;   // Conversion Result Buffer 15
    Uint16                 rsvd[16];      // reserved
};

//---------------------------------------------------------------------------
// ADC External References & Function Declarations:
//
extern volatile struct ADC_REGS AdcRegs;
extern volatile struct ADC_RESULT_REGS AdcResult;


#ifdef __cplusplus
}
#endif /* extern "C" */


#endif  // end of DSP2802x_ADC_H definition
//===========================================================================
// End of file.
//===========================================================================

