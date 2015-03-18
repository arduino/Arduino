//###########################################################################
//
// FILE:   F2806x_Pie_ctrl.h
//
// TITLE:  F2806x Device PIE_CTRL Register Definitions.
//
//###########################################################################
// $TI Release: 2806x C/C++ Header Files V1.10 $   
// $Release Date: April 7, 2011 $   
//###########################################################################

#ifndef F2806x_PIE_CTRL_H
#define F2806x_PIE_CTRL_H

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// PIE_CTRL Individual Register Bit Definitions:

struct PIECTRL_BITS {     // bits description
	Uint16	ENPIE:1;			// 0	Enable PIE Block
	Uint16	PIEVECT:15;			// 15:1	Fetched Vector Address
};

union PIECTRL_REG {
	Uint16 all;
	struct PIECTRL_BITS	bit;
};

struct PIEIER_BITS {     // bits description
	Uint16	INTx1:1;			// 0	INTx1
	Uint16	INTx2:1;			// 1	INTx2
	Uint16	INTx3:1;			// 2	INTx3
	Uint16	INTx4:1;			// 3	INTx4
	Uint16	INTx5:1;			// 4	INTx5
	Uint16	INTx6:1;			// 5	INTx6
	Uint16	INTx7:1;			// 6	INTx7
	Uint16	INTx8:1;			// 7	INTx8
	Uint16	rsvd1:8;			// 15:8	Reserved
};

union PIEIER_REG {
	Uint16 all;
	struct PIEIER_BITS	bit;
};

struct PIEIFR_BITS {     // bits description
	Uint16	INTx1:1;			// 0	INTx1
	Uint16	INTx2:1;			// 1	INTx2
	Uint16	INTx3:1;			// 2	INTx3
	Uint16	INTx4:1;			// 3	INTx4
	Uint16	INTx5:1;			// 4	INTx5
	Uint16	INTx6:1;			// 5	INTx6
	Uint16	INTx7:1;			// 6	INTx7
	Uint16	INTx8:1;			// 7	INTx8
	Uint16	rsvd1:8;			// 15:8	Reserved
};

union PIEIFR_REG {
	Uint16 all;
	struct PIEIFR_BITS	bit;
};

struct PIEACK_BITS {     // bits description
	Uint16	ACK1:1;			// 0	Acknowledge PIE Interrupt Group 1
	Uint16	ACK2:1;			// 1	Acknowledge PIE Interrupt Group 2
	Uint16	ACK3:1;			// 2	Acknowledge PIE Interrupt Group 3
	Uint16	ACK4:1;			// 3	Acknowledge PIE Interrupt Group 4
	Uint16	ACK5:1;			// 4	Acknowledge PIE Interrupt Group 5
	Uint16	ACK6:1;			// 5	Acknowledge PIE Interrupt Group 6
	Uint16	ACK7:1;			// 6	Acknowledge PIE Interrupt Group 7
	Uint16	ACK8:1;			// 7	Acknowledge PIE Interrupt Group 8
	Uint16	ACK9:1;			// 8	Acknowledge PIE Interrupt Group 9
	Uint16	ACK10:1;		// 9	Acknowledge PIE Interrupt Group 10
	Uint16	ACK11:1;		// 10	Acknowledge PIE Interrupt Group 11
	Uint16	ACK12:1;		// 11	Acknowledge PIE Interrupt Group 12
	Uint16	rsvd1:4;		// 15:12	Reserved
};

union PIEACK_REG {
	Uint16 all;
	struct PIEACK_BITS	bit;
};

struct PIE_CTRL_REGS {
	union	PIECTRL_REG	PIECTRL;	// PIE Control Register
	union	PIEACK_REG	PIEACK;		// PIE Acknowledge Register
	union	PIEIER_REG	PIEIER1;	// PIE INT1 IER Register
	union	PIEIFR_REG	PIEIFR1;	// PIE INT1 IFR Register
	union	PIEIER_REG	PIEIER2;	// PIE INT2 IER Register
	union	PIEIFR_REG	PIEIFR2;	// PIE INT2 IFR Register
	union	PIEIER_REG	PIEIER3;	// PIE INT3 IER Register
	union	PIEIFR_REG	PIEIFR3;	// PIE INT3 IFR Register
	union	PIEIER_REG	PIEIER4;	// PIE INT4 IER Register
	union	PIEIFR_REG	PIEIFR4;	// PIE INT4 IFR Register
	union	PIEIER_REG	PIEIER5;	// PIE INT5 IER Register
	union	PIEIFR_REG	PIEIFR5;	// PIE INT5 IFR Register
	union	PIEIER_REG	PIEIER6;	// PIE INT6 IER Register
	union	PIEIFR_REG	PIEIFR6;	// PIE INT6 IFR Register
	union	PIEIER_REG	PIEIER7;	// PIE INT7 IER Register
	union	PIEIFR_REG	PIEIFR7;	// PIE INT7 IFR Register
	union	PIEIER_REG	PIEIER8;	// PIE INT8 IER Register
	union	PIEIFR_REG	PIEIFR8;	// PIE INT8 IFR Register
	union	PIEIER_REG	PIEIER9;	// PIE INT9 IER Register
	union	PIEIFR_REG	PIEIFR9;	// PIE INT9 IFR Register
	union	PIEIER_REG	PIEIER10;	// PIE INT10 IER Register
	union	PIEIFR_REG	PIEIFR10;	// PIE INT10 IFR Register
	union	PIEIER_REG	PIEIER11;	// PIE INT11 IER Register
	union	PIEIFR_REG	PIEIFR11;	// PIE INT11 IFR Register
	union	PIEIER_REG	PIEIER12;	// PIE INT12 IER Register
	union	PIEIFR_REG	PIEIFR12;	// PIE INT12 IFR Register
};

#define PIEACK_GROUP1   0x0001
#define PIEACK_GROUP2   0x0002
#define PIEACK_GROUP3   0x0004
#define PIEACK_GROUP4   0x0008
#define PIEACK_GROUP5   0x0010
#define PIEACK_GROUP6   0x0020
#define PIEACK_GROUP7   0x0040
#define PIEACK_GROUP8   0x0080
#define PIEACK_GROUP9   0x0100
#define PIEACK_GROUP10  0x0200
#define PIEACK_GROUP11  0x0400
#define PIEACK_GROUP12  0x0800

//---------------------------------------------------------------------------
// Pie_ctrl External References & Function Declarations:
//
extern volatile struct PIE_CTRL_REGS PieCtrlRegs;

#ifdef __cplusplus
}
#endif /* extern "C" */


#endif  // end of F2806x_PIE_CTRL_H definition
//===========================================================================
// End of file.
//===========================================================================
