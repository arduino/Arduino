//###########################################################################
//
// FILE:   F2806x_Adc.h
//
// TITLE:  F2806x Device ADC Register Definitions.
//
//###########################################################################
// $TI Release: 2806x C/C++ Header Files V1.10 $
// $Release Date: April 7, 2011 $
//###########################################################################

#ifndef F2806x_ADC_H
#define F2806x_ADC_H

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// ADC Individual Register Bit Definitions:

struct ADCCTL1_BITS {     // bits description
	Uint16	TEMPCONV:1;				// 0	Temperature sensor connection
	Uint16	VREFLOCONV:1;			// 1	VSSA connection
	Uint16	INTPULSEPOS :1;			// 2	INT pulse generation control
	Uint16	ADCREFSEL:1;			// 3	Internal/external reference select
	Uint16	rsvd1:1;				// 4	Reserved
	Uint16	ADCREFPWD:1;			// 5	Reference buffers powerdown
	Uint16	ADCBGPWD:1;				// 6	ADC bandgap powerdown
	Uint16	ADCPWDN:1;				// 7	ADC powerdown
	Uint16	ADCBSYCHN:5;			// 12:8	ADC busy on a channel
	Uint16	ADCBSY:1;				// 13	ADC Busy
	Uint16	ADCENABLE:1;			// 14	ADC Enable
	Uint16	RESET:1;				// 15	ADC Master Reset
};

union ADCCTL1_REG {
	Uint16 all;
	struct ADCCTL1_BITS	bit;
};

struct ADCCTL2_BITS {     // bits description
	Uint16	CLKDIV2EN:1;		// 0	ADC CLK Div2 enable
	Uint16	ADCNONOVERLAP:1;	// 1	Non Sample Overlap enable
	Uint16	CLKDIV4EN:1;		// 2	ADC CLK Div4 enable
	Uint16	rsvd1:13;			// 15:3	Reserved
};

union ADCCTL2_REG {
	Uint16 all;
	struct ADCCTL2_BITS	bit;
};

struct ADCSAMPLEMODE_BITS {     // bits description
	Uint16	SIMULEN0:1;			// 0	Simultaneous sampling enable for SOC0
	Uint16	SIMULEN2:1;			// 1	Simultaneous sampling enable for SOC2
	Uint16	SIMULEN4:1;			// 2	Simultaneous sampling enable for SOC4
	Uint16	SIMULEN6:1;			// 3	Simultaneous sampling enable for SOC6
	Uint16	SIMULEN8:1;			// 4	Simultaneous sampling enable for SOC8
	Uint16	SIMULEN10:1;		// 5	Simultaneous sampling enable for SOC10
	Uint16	SIMULEN12:1;		// 6	Simultaneous sampling enable for SOC12
	Uint16	SIMULEN14:1;		// 7	Simultaneous sampling enable for SOC14
	Uint16	rsvd1:8;			// 15:8	Reserved
};

union ADCSAMPLEMODE_REG {
	Uint16 all;
	struct ADCSAMPLEMODE_BITS	bit;
};

struct SOCPRICTL_BITS {     // bits description
	Uint16	SOCPRIORITY:5;		// 4:0	Start-of-conversion Priority
	Uint16	RRPOINTER:6;		// 10:5	Round Robin Pointer
	Uint16	rsvd1:4;			// 14:11	Reserved
	Uint16	ONESHOT:1;			// 15	One Shot Mode Enabled
};

union SOCPRICTL_REG {
	Uint16 all;
	struct SOCPRICTL_BITS	bit;
};

struct ADCSOC_BITS {     // bits description
	Uint16	SOC0:1;			// 0	Start of conversion for CONV0
	Uint16	SOC1:1;			// 1	Start of conversion for CONV1
	Uint16	SOC2:1;			// 2	Start of conversion for CONV2
	Uint16	SOC3:1;			// 3	Start of conversion for CONV3
	Uint16	SOC4:1;			// 4	Start of conversion for CONV4
	Uint16	SOC5:1;			// 5	Start of conversion for CONV5
	Uint16	SOC6:1;			// 6	Start of conversion for CONV6
	Uint16	SOC7:1;			// 7	Start of conversion for CONV7
	Uint16	SOC8:1;			// 8	Start of conversion for CONV8
	Uint16	SOC9:1;			// 9	Start of conversion for CONV9
	Uint16	SOC10:1;		// 10	Start of conversion for CONV10
	Uint16	SOC11:1;		// 11	Start of conversion for CONV11
	Uint16	SOC12:1;		// 12	Start of conversion for CONV12
	Uint16	SOC13:1;		// 13	Start of conversion for CONV13
	Uint16	SOC14:1;		// 14	Start of conversion for CONV14
	Uint16	SOC15:1;		// 15	Start of conversion for CONV15
};

union ADCSOC_REG {
	Uint16 all;
	struct ADCSOC_BITS	bit;
};

struct INTSEL1N2_BITS {     // bits description
	Uint16	INT1SEL:5;			// 4:0	INT1 EOC Source Select
	Uint16	INT1E:1;			// 5	INT1 Interrupt Enable
	Uint16	INT1CONT:1;			// 6	INT1 Continuous Mode Enable
	Uint16	rsvd1:1;			// 7	Reserved
	Uint16	INT2SEL:5;			// 12:8	INT2 EOC Source Select
	Uint16	INT2E:1;			// 13	INT2 Interrupt Enable
	Uint16	INT2CONT:1;			// 14	INT2 Continuous Mode Enable
	Uint16	rsvd2:1;			// 15	Reserved
};

union INTSEL1N2_REG {
	Uint16 all;
	struct INTSEL1N2_BITS	bit;
};

struct INTSEL3N4_BITS {     // bits description
	Uint16	INT3SEL:5;			// 4:0	INT3 EOC Source Select
	Uint16	INT3E:1;			// 5	INT3 Interrupt Enable
	Uint16	INT3CONT:1;			// 6	INT3 Continuous Mode Enable
	Uint16	rsvd1:1;			// 7	Reserved
	Uint16	INT4SEL:5;			// 12:8	INT4 EOC Source Select
	Uint16	INT4E:1;			// 13	INT4 Interrupt Enable
	Uint16	INT4CONT:1;			// 14	INT4 Continuous Mode Enable
	Uint16	rsvd2:1;			// 15	Reserved
};

union INTSEL3N4_REG {
	Uint16 all;
	struct INTSEL3N4_BITS	bit;
};

struct INTSEL5N6_BITS {     // bits description
	Uint16	INT5SEL:5;			// 4:0	INT5 EOC Source Select
	Uint16	INT5E:1;			// 5	INT5 Interrupt Enable
	Uint16	INT5CONT:1;			// 6	INT5 Continuous Mode Enable
	Uint16	rsvd1:1;			// 7	Reserved
	Uint16	INT6SEL:5;			// 12:8	INT6 EOC Source Select
	Uint16	INT6E:1;			// 13	INT6 Interrupt Enable
	Uint16	INT6CONT:1;			// 14	INT6 Continuous Mode Enable
	Uint16	rsvd2:1;			// 15	Reserved
};

union INTSEL5N6_REG {
	Uint16 all;
	struct INTSEL5N6_BITS	bit;
};

struct INTSEL7N8_BITS {     // bits description
	Uint16	INT7SEL:5;			// 4:0	INT7 EOC Source Select
	Uint16	INT7E:1;			// 5	INT7 Interrupt Enable
	Uint16	INT7CONT:1;			// 6	INT7 Continuous Mode Enable
	Uint16	rsvd1:1;			// 7	Reserved
	Uint16	INT8SEL:5;			// 12:8	INT8 EOC Source Select
	Uint16	INT8E:1;			// 13	INT8 Interrupt Enable
	Uint16	INT8CONT:1;			// 14	INT8 Continuous Mode Enable
	Uint16	rsvd2:1;			// 15	Reserved
};

union INTSEL7N8_REG {
	Uint16 all;
	struct INTSEL7N8_BITS	bit;
};

struct INTSEL9N10_BITS {     // bits description
	Uint16	INT9SEL:5;			// 4:0	INT9 EOC Source Select
	Uint16	INT9E:1;			// 5	INT9 Interrupt Enable
	Uint16	INT9CONT:1;			// 6	INT9 Continuous Mode Enable
	Uint16	rsvd1:1;			// 7	Reserved
	Uint16	INT10SEL:5;			// 12:8	INT10 EOC Source Select
	Uint16	INT10E:1;			// 13	INT10 Interrupt Enable
	Uint16	INT10CONT:1;		// 14	INT10 Continuous Mode Enable
	Uint16	rsvd2:1;			// 15	Reserved
};

union INTSEL9N10_REG {
	Uint16 all;
	struct INTSEL9N10_BITS	bit;
};

struct ADCINT_BITS {     // bits description
	Uint16	ADCINT1:1;			// 0	ADC Interrupt Flag 1
	Uint16	ADCINT2:1;			// 1	ADC Interrupt Flag 2
	Uint16	ADCINT3:1;			// 2	ADC Interrupt Flag 3
	Uint16	ADCINT4:1;			// 3	ADC Interrupt Flag 4
	Uint16	ADCINT5:1;			// 4	ADC Interrupt Flag 5
	Uint16	ADCINT6:1;			// 5	ADC Interrupt Flag 6
	Uint16	ADCINT7:1;			// 6	ADC Interrupt Flag 7
	Uint16	ADCINT8:1;			// 7	ADC Interrupt Flag 8
	Uint16	ADCINT9:1;			// 8	ADC Interrupt Flag 9
	Uint16	rsvd1:7;			// 15:9	Reserved
};

union ADCINT_REG {
	Uint16 all;
	struct ADCINT_BITS	bit;
};

struct ADCINTSOCSEL1_BITS {     // bits description
	Uint16	SOC0:2;			// 1:0	ADCINT Start-of-conversion Select
	Uint16	SOC1:2;			// 3:2	ADCINT Start-of-conversion Select
	Uint16	SOC2:2;			// 5:4	ADCINT Start-of-conversion Select
	Uint16	SOC3:2;			// 7:6	ADCINT Start-of-conversion Select
	Uint16	SOC4:2;			// 9:8	ADCINT Start-of-conversion Select
	Uint16	SOC5:2;			// 11:10	ADCINT Start-of-conversion Select
	Uint16	SOC6:2;			// 13:12	ADCINT Start-of-conversion Select
	Uint16	SOC7:2;			// 15:14	ADCINT Start-of-conversion Select
};

union ADCINTSOCSEL1_REG {
	Uint16 all;
	struct ADCINTSOCSEL1_BITS	bit;
};

struct ADCINTSOCSEL2_BITS {     // bits description
	Uint16	SOC8:2;				// 1:0	ADCINT Start-of-conversion Select
	Uint16	SOC9:2;				// 3:2	ADCINT Start-of-conversion Select
	Uint16	SOC10:2;			// 5:4	ADCINT Start-of-conversion Select
	Uint16	SOC11:2;			// 7:6	ADCINT Start-of-conversion Select
	Uint16	SOC12:2;			// 9:8	ADCINT Start-of-conversion Select
	Uint16	SOC13:2;			// 11:10	ADCINT Start-of-conversion Select
	Uint16	SOC14:2;			// 13:12	ADCINT Start-of-conversion Select
	Uint16	SOC15:2;			// 15:14	ADCINT Start-of-conversion Select
};

union ADCINTSOCSEL2_REG {
	Uint16 all;
	struct ADCINTSOCSEL2_BITS	bit;
};

struct ADCSOCxCTL_BITS {     // bits description
	Uint16	ACQPS:6;			// 5:0	Acquisition Pulse Size
	Uint16	CHSEL:4;			// 9:6	SOCx Channel Select
	Uint16	rsvd1:1;			// 10	Reserved
	Uint16	TRIGSEL:5;			// 15:11	SOCx Trigger Select
};

union ADCSOCxCTL_REG {
	Uint16 all;
	struct ADCSOCxCTL_BITS	bit;
};

struct ADCREFTRIM_BITS {     // bits description
	Uint16	BG_FINE_TRIM:5;			// 4:0	Course Trim for Internal BG
	Uint16	BG_COARSE_TRIM:4;		// 8:5	Fine Trim for Internal BG
	Uint16	EXTREF_FINE_TRIM:5;		// 13:9	Fine Trim for External Reference
	Uint16	rsvd1:2;				// 15:14	Reserved
};

union ADCREFTRIM_REG {
	Uint16 all;
	struct ADCREFTRIM_BITS	bit;
};

struct ADCOFFTRIM_BITS {     // bits description
	int16	OFFTRIM:9;			// 8:0	Offset Trim
	Uint16	rsvd1:7;			// 15:9	Reserved
};

union ADCOFFTRIM_REG {
	Uint16 all;
	struct ADCOFFTRIM_BITS	bit;
};

struct COMPHYSTCTL_BITS{                // bits description
    Uint16  rsvd1:1;             	   // 0    reserved
    Uint16  COMP1_HYST_DISABLE:1;      // 1    Comparator 1 Hysteresis Disable
    Uint16  rsvd2:4;                   // 5:2  reserved
    Uint16  COMP2_HYST_DISABLE:1;      // 6    Comparator 2 Hysteresis Disable
    Uint16  rsvd3:4;                   // 10:7 reserved
    Uint16  COMP3_HYST_DISABLE:1;      // 11   Comparator 3 Hysteresis Disable
    Uint16  rsvd4:4;                   // 15:12 reserved
};

union COMPHYSTCTL_REG{
    Uint16      all;
    struct COMPHYSTCTL_BITS bit;
};

struct ADC_REGS {
	union	ADCCTL1_REG			ADCCTL1;		// Control 1 Register
	union	ADCCTL2_REG			ADCCTL2;		// Control 2 Register
	Uint16						rsvd1;			// Reserved
	Uint16						rsvd2;			// Reserved
	union	ADCINT_REG			ADCINTFLG;		// Interrupt Flag Register
	union	ADCINT_REG			ADCINTFLGCLR;	// Interrupt Flag Clear Register
	union	ADCINT_REG			ADCINTOVF;		// Interrupt Overflow Register
	union	ADCINT_REG			ADCINTOVFCLR;	// Interrupt Overflow Clear Register
	union	INTSEL1N2_REG		INTSEL1N2;		// Interrupt 1 and 2 Selection Register
	union	INTSEL3N4_REG		INTSEL3N4;		// Interrupt 3 and 4 Selection Register
	union	INTSEL5N6_REG		INTSEL5N6;		// Interrupt 5 and 6 Selection Register
	union	INTSEL7N8_REG		INTSEL7N8;		// Interrupt 7 and 8 Selection Register
	union	INTSEL9N10_REG		INTSEL9N10;		// Interrupt 9 Selection Register
	Uint16						rsvd3;			// Reserved
	Uint16						rsvd4;			// Reserved
	Uint16						rsvd5;			// Reserved
	union	SOCPRICTL_REG		SOCPRICTL;		// SOC Priority Control Register
	Uint16						rsvd6;			// Reserved
	union	ADCSAMPLEMODE_REG	ADCSAMPLEMODE;	// Sampling Mode Register
	Uint16						rsvd7;			// Reserved
	union	ADCINTSOCSEL1_REG	ADCINTSOCSEL1;	// Interrupt SOC Selection 1 Register (for 8 channels)
	union	ADCINTSOCSEL2_REG	ADCINTSOCSEL2;	// Interrupt SOC Selection 2 Register (for 8 channels)
	Uint16						rsvd8;			// Reserved
	Uint16						rsvd9;			// Reserved
	union	ADCSOC_REG			ADCSOCFLG1;		// SOC Flag 1 Register (for 16 channels)
	Uint16						rsvd10;			// Reserved
	union	ADCSOC_REG			ADCSOCFRC1;		// SOC Force 1 Register (for 16 channels)
	Uint16						rsvd11;			// Reserved
	union	ADCSOC_REG			ADCSOCOVF1;		// SOC Overflow 1 Register (for 16 channels)
	Uint16						rsvd12;			// Reserved
	union	ADCSOC_REG			ADCSOCOVFCLR1;	// SOC Overflow Clear 1 Register (for 16 channels)
	Uint16						rsvd13;			// Reserved
	union	ADCSOCxCTL_REG		ADCSOC0CTL;		// SOC0 Control Register
	union	ADCSOCxCTL_REG		ADCSOC1CTL;		// SOC1 Control Register
	union	ADCSOCxCTL_REG		ADCSOC2CTL;		// SOC2 Control Register
	union	ADCSOCxCTL_REG		ADCSOC3CTL;		// SOC3 Control Register
	union	ADCSOCxCTL_REG		ADCSOC4CTL;		// SOC4 Control Register
	union	ADCSOCxCTL_REG		ADCSOC5CTL;		// SOC5 Control Register
	union	ADCSOCxCTL_REG		ADCSOC6CTL;		// SOC6 Control Register
	union	ADCSOCxCTL_REG		ADCSOC7CTL;		// SOC7 Control Register
	union	ADCSOCxCTL_REG		ADCSOC8CTL;		// SOC8 Control Register
	union	ADCSOCxCTL_REG		ADCSOC9CTL;		// SOC9 Control Register
	union	ADCSOCxCTL_REG		ADCSOC10CTL;	// SOC10 Control Register
	union	ADCSOCxCTL_REG		ADCSOC11CTL;	// SOC11 Control Register
	union	ADCSOCxCTL_REG		ADCSOC12CTL;	// SOC12 Control Register
	union	ADCSOCxCTL_REG		ADCSOC13CTL;	// SOC13 Control Register
	union	ADCSOCxCTL_REG		ADCSOC14CTL;	// SOC14 Control Register
	union	ADCSOCxCTL_REG		ADCSOC15CTL;	// SOC15 Control Register
	Uint16						rsvd14[16];		// Reserved
	union	ADCREFTRIM_REG		ADCREFTRIM;		// Reference Trim Register
	union	ADCOFFTRIM_REG		ADCOFFTRIM;		// Offset Trim Register
	Uint16                      rsvd15 [10];    // reserved
	union   COMPHYSTCTL_REG     COMPHYSTCTL;    // COMP Hysteresis Control Register
	Uint16                      rsvd16 [3];     // reserved
};

struct ADC_RESULT_REGS {
	Uint16		ADCRESULT0;		// Conversion Result Buffer 0
	Uint16		ADCRESULT1;		// Conversion Result Buffer 1
	Uint16		ADCRESULT2;		// Conversion Result Buffer 2
	Uint16		ADCRESULT3;		// Conversion Result Buffer 3
	Uint16		ADCRESULT4;		// Conversion Result Buffer 4
	Uint16		ADCRESULT5;		// Conversion Result Buffer 5
	Uint16		ADCRESULT6;		// Conversion Result Buffer 6
	Uint16		ADCRESULT7;		// Conversion Result Buffer 7
	Uint16		ADCRESULT8;		// Conversion Result Buffer 8
	Uint16		ADCRESULT9;		// Conversion Result Buffer 9
	Uint16		ADCRESULT10;	// Conversion Result Buffer 10
	Uint16		ADCRESULT11;	// Conversion Result Buffer 11
	Uint16		ADCRESULT12;	// Conversion Result Buffer 12
	Uint16		ADCRESULT13;	// Conversion Result Buffer 13
	Uint16		ADCRESULT14;	// Conversion Result Buffer 14
	Uint16		ADCRESULT15;	// Conversion Result Buffer 15
};

//---------------------------------------------------------------------------
// Adc External References & Function Declarations:
//
extern volatile struct ADC_REGS AdcRegs;
extern volatile struct ADC_RESULT_REGS AdcResult;

#ifdef __cplusplus
}
#endif /* extern "C" */


#endif  // end of F2806x_ADC_H definition
//===========================================================================
// End of file.
//===========================================================================
