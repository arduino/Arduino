//###########################################################################
//
// FILE:   F2806x_Cla.h
//
// TITLE:  F2806x Device CLA Register Definitions.
//
//###########################################################################
// $TI Release: 2806x C/C++ Header Files V1.10 $
// $Release Date: April 7, 2011 $
//###########################################################################

#ifndef F2806x_CLA_H
#define F2806x_CLA_H

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// CLA Individual Register Bit Definitions:

struct MCTL_BITS {     // bits description
	Uint16	HARDRESET:1;		// 0	Issue a hard reset
	Uint16	SOFTRESET:1;		// 1	Issue a soft reset
	Uint16	IACKE:1;			// 2	Enable IACK for task start
	Uint16	rsvd1:13;			// 15:3	Reserved
};

union MCTL_REG {
	Uint16 all;
	struct MCTL_BITS	bit;
};

struct MMEMCFG_BITS {     // bits description
	Uint16	PROGE:1;			// 0	Program RAM Enable
	Uint16	rsvd1:3;			// 3:1	Reserved
	Uint16	RAM0E:1;			// 4	Data RAM 0 Enable
	Uint16	RAM1E:1;			// 5	Data RAM 1 Enable
	Uint16  RAM2E:1;			// 6	Data RAM 2 Enable
	Uint16	rsvd2:1;			// 7	Reserved
	Uint16	RAM0CPUE:1;			// 8	Data RAM 0 CPU Access Enable Bit
	Uint16	RAM1CPUE:1;			// 9    Data RAM 1 CPU Access Enable Bit
	Uint16	RAM2CPUE:1;			// 10	Data RAM 2 CPU Access Enable Bit
	Uint16	rsvd3:5;			// 15:11 Reserved
};

union MMEMCFG_REG {
	Uint16 all;
	struct MMEMCFG_BITS	bit;
};

struct MPISRCSEL1_BITS {     // bits description
	Uint16	PERINT1SEL:4;			// 3:0	Source for CLA Interrupt 1
	Uint16	PERINT2SEL:4;			// 7:4	Source for CLA Interrupt 2
	Uint16	PERINT3SEL:4;			// 11:8	Source for CLA Interrupt 3
	Uint16	PERINT4SEL:4;			// 15:12	Source for CLA Interrupt 4
	Uint16	PERINT5SEL:4;			// 19:16	Source for CLA Interrupt 5
	Uint16	PERINT6SEL:4;			// 23:20	Source for CLA Interrupt 6
	Uint16	PERINT7SEL:4;			// 27:24	Source for CLA Interrupt 7
	Uint16	PERINT8SEL:4;			// 31:28	Source for CLA Interrupt 8
};

union MPISRCSEL1_REG {
	Uint32 all;
	struct MPISRCSEL1_BITS	bit;
};

struct MIFR_BITS {     // bits description
	Uint16	INT1:1;			// 0	Interrupt 1 Flag
	Uint16	INT2:1;			// 1	Interrupt 2 Flag
	Uint16	INT3:1;			// 2	Interrupt 3 Flag
	Uint16	INT4:1;			// 3	Interrupt 4 Flag
	Uint16	INT5:1;			// 4	Interrupt 5 Flag
	Uint16	INT6:1;			// 5	Interrupt 6 Flag
	Uint16	INT7:1;			// 6	Interrupt 7 Flag
	Uint16	INT8:1;			// 7	Interrupt 8 Flag
	Uint16	rsvd1:8;		// 15:8	Reserved
};

union MIFR_REG {
	Uint16 all;
	struct MIFR_BITS	bit;
};

union MIOVF_REG {
   Uint16              all;
   struct MIFR_BITS    bit;
};

union MIFRC_REG {
   Uint16              all;
   struct MIFR_BITS    bit;
};

union MICLR_REG {
   Uint16              all;
   struct MIFR_BITS    bit;
};

union MICLROVF_REG {
   Uint16              all;
   struct MIFR_BITS    bit;
};

union MIER_REG {
   Uint16              all;
   struct MIFR_BITS    bit;
};

union MIRUN_REG {
   Uint16              all;
   struct MIFR_BITS    bit;
};

struct MSTF_BITS {     // bits description
	Uint16	LVF:1;			// 0	Latched Overflow Flag
	Uint16	LUF:1;			// 1	Latched Underflow Flag
	Uint16	NF:1;			// 2	Negative Float Flag
	Uint16	ZF:1;			// 3	Zero Float Flag
	Uint16	rsvd1:2;		// 5:4	Reserved
	Uint16	TF:1;			// 6	Test Flag
	Uint16	rsvd2:2;		// 8:7	Reserved
	Uint16	RNDF32:1;		// 9	Rounding Mode
	Uint16	rsvd3:1;		// 10	Reserved
	Uint16	MEALLOW:1;		// 11	MEALLOW Status
	Uint16	RPCL:4;			// 15:12	Return PC: Low Portion
	Uint16	RPCH:8;			// 23:16	Return PC: High Portion
	Uint16	rsvd4:8;		// 31:24	Reserved
};

union MSTF_REG {
	Uint32 all;
	struct MSTF_BITS	bit;
};

union MR_REG {
	Uint32				i32;
	float				f32;
};

struct CLA_REGS {
	Uint16					MVECT1;		// Task 1 Vecotr
	Uint16					MVECT2;		// Task 2 Vector
	Uint16					MVECT3;		// Task 3 Vector
	Uint16					MVECT4;		// Task 4 Vector
	Uint16					MVECT5;		// Task 5 Vector
	Uint16					MVECT6;		// Task 6 Vector
	Uint16					MVECT7;		// Task 7 Vecotr
	Uint16					MVECT8;		// Task 8 Vector
	Uint16					rsvd1[8];	// Reserved
	union	MCTL_REG		MCTL;		// CLA Control
	union	MMEMCFG_REG		MMEMCFG;	// CLA Memory Configuration
	Uint16					rsvd2[2];	// Reserved
	union	MPISRCSEL1_REG	MPISRCSEL1;	// CLA Interrupt Source Select
	Uint16					rsvd3[10];	// Reserved
	union	MIFR_REG		MIFR;		// CLA Interrupt Flag
	union	MIOVF_REG		MIOVF;		// CLA Interrupt Overflow Flag
	union	MIFRC_REG		MIFRC;		// CLA Interrupt Force
	union	MICLR_REG		MICLR;		// CLA Interrupt Flag Clear
	union	MICLROVF_REG	MICLROVF;	// CLA Interrupt Overflow Flag Clear
	union	MIER_REG		MIER;		// CLA Interrupt Enable
	union	MIRUN_REG		MIRUN;		// CLA Interrupt Run Status
	Uint16					rsvd4;		// Reserved
	Uint16					_MPC;		// CLA Program Counter
	Uint16					rsvd5;		// Reserved
	Uint16					_MAR0;		// CLA Auxillary Register 0
	Uint16					_MAR1;		// CLA Auxillary Register 1
	Uint16					rsvd6[2];	// Reserved
	union	MSTF_REG		_MSTF;		// CLA Floating-Point Status Register
	union	MR_REG			_MR0;		// CLA Result Register 0
	Uint32					rsvd7;		// Reserved
	union	MR_REG			_MR1;		// CLA Result Register 1
	Uint32					rsvd8;		// Reserved
	union	MR_REG			_MR2;		// CLA Result Register 2
	Uint32					rsvd9;		// Reserved
	union	MR_REG			_MR3;		// CLA Result Register 3
	Uint32					rsvd10;		// Reserved
};

//---------------------------------------------------------------------------
// Cla External References & Function Declarations:
//
extern volatile struct CLA_REGS Cla1Regs;

#ifdef __cplusplus
}
#endif /* extern "C" */


#endif  // end of F2806x_CLA_H definition
//===========================================================================
// End of file.
//===========================================================================
