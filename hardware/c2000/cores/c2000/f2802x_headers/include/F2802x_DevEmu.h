// TI File $Revision: /main/5 $
// Checkin $Date: October 20, 2009   11:04:38 $
//###########################################################################
//
// FILE:   F2802x_DevEmu.h
//
// TITLE:  F2802x Device Emulation Register Definitions.
//
//###########################################################################
// $TI Release: 2802x C/C++ Header Files and Peripheral Examples V1.29 $
// $Release Date: January 11, 2011 $
//###########################################################################

#ifndef F2802x_DEV_EMU_H
#define F2802x_DEV_EMU_H

#ifdef __cplusplus
extern "C" {
#endif

//---------------------------------------------------------------------------
// Device Emulation Register Bit Definitions:
//
// Device Configuration Register Bit Definitions
struct DEVICECNF_BITS  {     // bits  description
   uint16_t rsvd1:3;           // 2:0   reserved
   uint16_t VMAPS:1;           // 3     VMAP Status
   uint16_t rsvd2:1;           // 4     reserved
   uint16_t XRSn:1;            // 5     XRSn Signal Status
   uint16_t rsvd3:10;          // 15:6  reserved
   uint16_t rsvd4:3;           // 18:16 reserved
   uint16_t ENPROT:1;          // 19    Enable/Disable pipeline protection
   uint16_t rsvd5:7;           // 26:21 reserved
   uint16_t TRSTn:1;           // 27    Status of TRSTn signal
   uint16_t rsvd6:4;           // 31:28 reserved
};

union DEVICECNF_REG {
   uint32_t                 all;
   struct DEVICECNF_BITS  bit;
};

// CLASSID
struct CLASSID_BITS   {  // bits  description
   uint16_t CLASSNO:8;     // 7:0   Class Number
   uint16_t PARTTYPE:8;    // 15:8  Part Type
};

union CLASSID_REG {
   uint16_t               all;
   struct CLASSID_BITS  bit;
};



struct DEV_EMU_REGS {
   union DEVICECNF_REG DEVICECNF;  // Device Configuration
   union CLASSID_REG   CLASSID;    // Class ID
   uint16_t              REVID;      // Device ID
};

// PARTID
struct PARTID_BITS   {  // bits  description
   uint16_t PARTNO:8;     // 7:0   Part Number
   uint16_t PARTTYPE:8;   // 15:8  Part Type
};

union PARTID_REG {
   uint16_t               all;
   struct PARTID_BITS   bit;
};

struct PARTID_REGS {
   union PARTID_REG PARTID; // Part ID
};


//---------------------------------------------------------------------------
// Device Emulation Register References & Function Declarations:
//
extern volatile struct DEV_EMU_REGS DevEmuRegs;
extern volatile struct PARTID_REGS PartIdRegs;

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of DSP2802x_DEV_EMU_H definition

//===========================================================================
// End of file.
//===========================================================================
