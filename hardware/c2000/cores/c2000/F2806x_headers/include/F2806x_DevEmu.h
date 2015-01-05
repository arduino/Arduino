//###########################################################################
//
// FILE:   F2806x_DevEmu.h
//
// TITLE:  F2806x Device DEVEMU Register Definitions.
//
//###########################################################################
// $TI Release: 2806x C/C++ Header Files V1.10 $   
// $Release Date: April 7, 2011 $   
//###########################################################################

#ifndef F2806x_DEVEMU_H
#define F2806x_DEVEMU_H

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// DEVEMU Individual Register Bit Definitions:

struct DEVICECNF_BITS {     // bits description
	Uint16	rsvd1:3;			// 2:0	Reserved
	Uint16	VMAPS:1;			// 3	VMAP Configure Status
	Uint16	rsvd2:1;			// 4	Reserved
	Uint16	XRSn:1;				// 5	Reset Input Signal Status
	Uint16	rsvd3:10;			// 15:6	Reserved
	Uint16  rsvd4:3;			// 18:16 Reserved
	Uint16	ENPROT:1;			// 19	Enable Write-Read Protection Mode Bit
	Uint16	rsvd5:7;			// 26:20 Reserved
	Uint16	TRSTn:1;			// 27	Read Status of TRSTn Signal
	Uint16	rsvd6:2;			// 29:28 Reserved
	Uint16	SYSCLK2DIV2DIS:1;	// 30 	SYSCLK2 Clock Divide by 2 Disable Bit
	Uint16	rsvd8:1;			// 31	Reserved
};

union DEVICECNF_REG {
	Uint32 all;
	struct DEVICECNF_BITS	bit;
};

// CLASSID
struct CLASSID_BITS   {  // bits  description
   Uint16 CLASSNO:8;     // 7:0   Class Number
   Uint16 PARTTYPE:8;    // 15:8  Part Type
};

union CLASSID_REG {
   Uint16               all;
   struct CLASSID_BITS  bit;
};


struct DEV_EMU_REGS {
   union DEVICECNF_REG DEVICECNF;  // Device Configuration
   union CLASSID_REG   CLASSID;    // Class ID
   Uint16              REVID;      // Device ID
};

// PARTID
struct PARTID_BITS   {  // bits  description
   Uint16 PARTNO:8;     // 7:0   Part Number
   Uint16 PARTTYPE:8;   // 15:8  Part Type
};

union PARTID_REG {
   Uint16               all;
   struct PARTID_BITS   bit;
};

struct PARTID_REGS {
   union PARTID_REG PARTID; // Part ID
};

//---------------------------------------------------------------------------
// Devemu External References & Function Declarations:
//
extern volatile struct DEV_EMU_REGS DevEmuRegs;
extern volatile struct PARTID_REGS PartIdRegs;

#ifdef __cplusplus
}
#endif /* extern "C" */


#endif  // end of F2806x_DEVEMU_H definition
//===========================================================================
// End of file.
//===========================================================================
