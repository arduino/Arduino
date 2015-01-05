//###########################################################################
//
// FILE:   F2806x_Eqep.h
//
// TITLE:  F2806x Device EQEP Register Definitions.
//
//###########################################################################
// $TI Release: 2806x C/C++ Header Files V1.10 $   
// $Release Date: April 7, 2011 $   
//###########################################################################

#ifndef F2806x_EQEP_H
#define F2806x_EQEP_H

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// EQEP Individual Register Bit Definitions:

struct QDECCTL_BITS {     // bits description
	Uint16	rsvd1:5;		// 4:0	Reserved
	Uint16	QSP:1;			// 5	QEPS Input Polarity
	Uint16	QIP:1;			// 6	QEPI Input Polarity
	Uint16	QBP:1;			// 7	QEPB Input Polarity
	Uint16	QAP:1;			// 8	QEPA Input Polarity
	Uint16	IGATE:1;		// 9	Index Pulse Gating Option
	Uint16	SWAP:1;			// 10	CLK/DIR Signal Source for Position Counter
	Uint16	XCR:1;			// 11	External Clock Rate
	Uint16	SPSEL:1;		// 12	Sync Output Pin Select
	Uint16	SOEN:1;			// 13	Enable Position Compare Sync
	Uint16	QSRC:2;			// 15:14	Postion Counter Source
};

union QDECCTL_REG {
	Uint16 all;
	struct QDECCTL_BITS	bit;
};

struct QEPCTL_BITS {     // bits description
	Uint16	WDE:1;			// 0	QEP watchdog enable
	Uint16	UTE:1;			// 1	QEP unit timer enable
	Uint16	QCLM:1;			// 2	QEP capture latch mode
	Uint16	QPEN:1;			// 3	Quadrature postotion counter enable
	Uint16	IEL:2;			// 5:4	Index event latch
	Uint16	SEL:1;			// 6	Strobe event latch
	Uint16	SWI:1;			// 7	Software init position counter
	Uint16	IEI:2;			// 9:8	Index event init of position count
	Uint16	SEI:2;			// 11:10	Strobe event init
	Uint16	PCRM:2;			// 13:12	Postion counter reset
	Uint16	FREE_SOFT:2;	// 15:14	Emulation mode
};

union QEPCTL_REG {
	Uint16 all;
	struct QEPCTL_BITS	bit;
};

struct QCAPCTL_BITS {     // bits description
	Uint16	UPPS:4;			// 3:0	Unit position pre-scale
	Uint16	CCPS:3;			// 6:4	QEP capture timer pre-scale
	Uint16	rsvd1:8;		// 14:7	Reserved
	Uint16	CEN:1;			// 15	Enable QEP capture
};

union QCAPCTL_REG {
	Uint16 all;
	struct QCAPCTL_BITS	bit;
};

struct QPOSCTL_BITS {     // bits description
	Uint16	PCSPW:12;		// 11:0	Position compare sync pulse width
	Uint16	PCE:1;			// 12	Position compare enable/disable
	Uint16	PCPOL:1;		// 13	Polarity of sync output
	Uint16	PCLOAD:1;		// 14	Position compare of shadow load
	Uint16	PCSHDW:1;		// 15	Position compare of shadow enable
};

union QPOSCTL_REG {
	Uint16 all;
	struct QPOSCTL_BITS	bit;
};

struct QEINT_BITS {     // bits description
	Uint16	rsvd1:1;		// 0	Reserved
	Uint16	PCE:1;			// 1	Position counter error
	Uint16	QPE:1;			// 2	Quadrature phase error
	Uint16	QDC:1;			// 3	Quadrature dir change
	Uint16	WTO:1;			// 4	Watchdog timeout
	Uint16	PCU:1;			// 5	Position counter underflow
	Uint16	PCO:1;			// 6	Position counter overflow
	Uint16	PCR:1;			// 7	Position compare ready
	Uint16	PCM:1;			// 8	Position compare match
	Uint16	SEL:1;			// 9	Strobe event latch
	Uint16	IEL:1;			// 10	Event latch
	Uint16	UTO:1;			// 11	Unit timeout
	Uint16	rsvd2:4;		// 15:12	Reserved
};

union QEINT_REG {
	Uint16 all;
	struct QEINT_BITS	bit;
};

struct QFLG_BITS {     // bits description
	Uint16	INT:1;			// 0	Global.interrupt
	Uint16	PCE:1;			// 1	Position counter error
	Uint16	PHE:1;			// 2	Quadrature phase error
	Uint16	QDC:1;			// 3	Quadrature dir change
	Uint16	WTO:1;			// 4	Watchdog timeout
	Uint16	PCU:1;			// 5	Position counter underflow
	Uint16	PCO:1;			// 6	Position counter overflow
	Uint16	PCR:1;			// 7	Position compare ready
	Uint16	PCM:1;			// 8	Position compare match
	Uint16	SEL:1;			// 9	Strobe event latch
	Uint16	IEL:1;			// 10	Event latch
	Uint16	UTO:1;			// 11	Unit timeout
	Uint16	rsvd1:4;		// 15:12	Reserved
};

union QFLG_REG {
	Uint16 all;
	struct QFLG_BITS	bit;
};

struct QFRC_BITS {     // bits description
	Uint16	rsvd1:1;		// 0	Reserved
	Uint16	PCE:1;			// 1	Position counter error
	Uint16	PHE:1;			// 2	Quadrature phase error
	Uint16	QDC:1;			// 3	Quadrature dir change
	Uint16	WTO:1;			// 4	Watchdog timeout
	Uint16	PCU:1;			// 5	Position counter underflow
	Uint16	PCO:1;			// 6	Position counter overflow
	Uint16	PCR:1;			// 7	Position compare ready
	Uint16	PCM:1;			// 8	Position compare match
	Uint16	SEL:1;			// 9	Strobe event latch
	Uint16	IEL:1;			// 10	Event latch
	Uint16	UTO:1;			// 11	Unit timeout
	Uint16	rsvd2:4;		// 15:12	Reserved
};

union QFRC_REG {
	Uint16 all;
	struct QFRC_BITS	bit;
};

struct QEPSTS_BITS {     // bits description
	Uint16	PCEF:1;			// 0	Position counter error
	Uint16	FIMF:1;			// 1	First index marker
	Uint16	CDEF:1;			// 2	Capture direction error
	Uint16	COEF:1;			// 3	Capture overflow error
	Uint16	QDLF:1;			// 4	QEP direction latch
	Uint16	QDF:1;			// 5	Quadrature direction
	Uint16	FIDF:1;			// 6	Direction on first index marker
	Uint16	UPEVNT:1;		// 7	Unit position event flag
	Uint16	rsvd1:8;		// 15:8	Reserved
};

union QEPSTS_REG {
	Uint16 all;
	struct QEPSTS_BITS	bit;
};

struct EQEP_REGS {
	Uint32				QPOSCNT;	// Position Counter
	Uint32				QPOSINIT;	// Position Counter Init
	Uint32				QPOSMAX;	// Maximum Position Count
	Uint32				QPOSCMP;	// Position Compare
	Uint32				QPOSILAT;	// Index Position Latch
	Uint32				QPOSSLAT;	// Strobe Position Latch
	Uint32				QPOSLAT;	// Position Latch
	Uint32				QUTMR;		// QEP Unit Timer
	Uint32				QUPRD;		// QEP Unit Period
	Uint16				QWDTMR;		// QEP Watchdog Timer
	Uint16				QWDPRD;		// QEP Watchdog Period
	union	QDECCTL_REG	QDECCTL;	// Quadrature Decoder Control
	union	QEPCTL_REG	QEPCTL;		// QEP Control
	union	QCAPCTL_REG	QCAPCTL;	// Qaudrature Capture Control
	union	QPOSCTL_REG	QPOSCTL;	// Position Compare Control
	union	QEINT_REG	QEINT;		// QEP Interrupt Control
	union	QFLG_REG	QFLG;		// QEP Interrupt Flag
	union	QFLG_REG	QCLR;		// QEP Interrupt Clear
	union	QFRC_REG	QFRC;		// QEP Interrupt Force
	union	QEPSTS_REG	QEPSTS;		// QEP Status
	Uint16				QCTMR;		// QEP Capture Timer
	Uint16				QCPRD;		// QEP Capture Period
	Uint16				QCTMRLAT;	// QEP Capture Latch
	Uint16				QCPRDLAT;	// QEP Capture Period Latch
	Uint16				rsvd1;		// Reserved
};

//---------------------------------------------------------------------------
// Eqep External References & Function Declarations:
//
extern volatile struct EQEP_REGS EQep1Regs;
extern volatile struct EQEP_REGS EQep2Regs;

#ifdef __cplusplus
}
#endif /* extern "C" */


#endif  // end of F2806x_EQEP_H definition
//===========================================================================
// End of file.
//===========================================================================
