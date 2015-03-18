// TI File $
// Checkin $
//###########################################################################
//
// FILE:   F2806x_HRCap.h
//
// TITLE:  F2806x Device HRCAP Register Definitions.
//
//###########################################################################
// $TI Release: 2806x C/C++ Header Files V1.10 $
// $Release Date: April 7, 2011 $
//###########################################################################

#ifndef F2806x_HRCAP_H
#define F2806x_HRCAP_H

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// HRCAP Individual Register Bit Definitions:

struct HCCTL_BITS {     // bits description
	Uint16	SOFTRESET:1;			// 0	Soft reset
	Uint16	RISEINTE:1;				// 1	RISE capture interrupt enable
	Uint16	FALLINTE:1;				// 2	FALL capture interrupt enable
	Uint16	OVFINTE:1;				// 3	Counter overflow interrupt enable
	Uint16	rsvd1:4;				// 7:4	Reserved
	Uint16	HCCAPCLKSEL:1;			// 8	HRCAP Capture Clock Select Bit
	Uint16	rsvd2:7;				// 15:9	Reserved
};

union HCCTL_REG {
	Uint16 all;
	struct HCCTL_BITS	bit;
};

struct HCIFR_BITS {     // bits description
	Uint16	INT:1;				// 0	Global interrupt flag
	Uint16	RISE:1;				// 1	RISE capture interrupt flag
	Uint16	FALL:1;				// 2	FALL capture interrupt flag
	Uint16	COUNTEROVF:1;		// 3	Counter overflow interrupt flag
	Uint16	RISEOVF:1;			// 4	RISE interrupt overflow event flag
	Uint16	rsvd1:11;			// 15:5	Reserved
};

union HCIFR_REG {
	Uint16 all;
	struct HCIFR_BITS	bit;
};

struct HCICLR_BITS {     // bits description
	Uint16	INT:1;				// 0	Global interrupt clear
	Uint16	RISE:1;				// 1	RISE capture interrupt clear
	Uint16	FALL:1;				// 2	FALL capture interrupt clear
	Uint16	COUNTEROVF:1;		// 3	Counter overflow interrupt clear
	Uint16	RISEOVF:1;			// 4	RISE interrupt overflow event clear
	Uint16	rsvd1:11;			// 15:5	Reserved
};

union HCICLR_REG {
	Uint16 all;
	struct HCICLR_BITS	bit;
};

struct HCIFRC_BITS {     // bits description
	Uint16	rsvd1:1;			// 0	Reserved
	Uint16	RISE:1;				// 1	RISE capture interrupt force
	Uint16	FALL:1;				// 2	FALL capture interrupt force
	Uint16	COUNTEROVF:1;		// 3	Counter overflow interrupt force
	Uint16	RISEOVF:1;			// 4	Rise Interrupt Overflow Event Flag Force Bit
	Uint16	rsvd2:11;			// 15:5	Reserved
};

union HCIFRC_REG {
	Uint16 all;
	struct HCIFRC_BITS	bit;
};

struct HRCAP_REGS {
	union	HCCTL_REG			HCCTL;			// HRCAP Control Register
	union	HCIFR_REG			HCIFR;			// HRCAP Interrupt Flag Register
	union	HCICLR_REG			HCICLR;			// HRCAP Interrupt Clear Register
	union	HCIFRC_REG			HCIFRC;			// HRCAP Interrupt Force Register
	Uint16						HCCOUNTER;		// HRCAP 16-bit Counter Register
	Uint16						rsvd1[11];		// Reserved
	Uint16						HCCAPCNTRISE0;	// HRCAP Capture Counter On Rising Edge 0 Register
	Uint16						rsvd2;			// Reserved
	Uint16						HCCAPCNTFALL0;	// HRCAP Capture Counter On Falling Edge 0 Register
	Uint16						rsvd3;			// Reserved
	Uint16						rsvd4;			// Reserved
	Uint16						rsvd5;			// Reserved
	Uint16						rsvd6[2];		// Reserved
	Uint16						HCCAPCNTRISE1;	// HRCAP Capture Counter On Rising Edge 1 Register
	Uint16						rsvd7;			// Reserved
	Uint16						HCCAPCNTFALL1;	// HRCAP Capture Counter On Falling Edge 1 Register
	Uint16						rsvd8;			// Reserved
	Uint16						rsvd9;			// Reserved
	Uint16						rsvd10;			// Reserved
	Uint16						rsvd11;			// Reserved
    Uint16						rsvd12;			// Reserved
};

//---------------------------------------------------------------------------
// Hrcap External References & Function Declarations:
//
extern volatile struct HRCAP_REGS HRCap1Regs;
extern volatile struct HRCAP_REGS HRCap2Regs;
extern volatile struct HRCAP_REGS HRCap3Regs;
extern volatile struct HRCAP_REGS HRCap4Regs;

#ifdef __cplusplus
}
#endif /* extern "C" */


#endif  // end of F2806x_HRCAP_H definition
//===========================================================================
// End of file.
//===========================================================================
