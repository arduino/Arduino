//###########################################################################
//
// FILE:   F2806x_Epwm.h
//
// TITLE:  F2806x Device EPWM Register Definitions.
//
//###########################################################################
// $TI Release: 2806x C/C++ Header Files V1.10 $   
// $Release Date: April 7, 2011 $   
//###########################################################################

#ifndef F2806x_EPWM_H
#define F2806x_EPWM_H

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// EPWM Individual Register Bit Definitions:

struct TBCTL_BITS {     // bits description
	Uint16	CTRMODE:2;			// 1:0	Counter Mode
	Uint16	PHSEN:1;			// 2	Phase Load Enable
	Uint16	PRDLD:1;			// 3	Active Period Load
	Uint16	SYNCOSEL:2;			// 5:4	Sync Output Select
	Uint16	SWFSYNC:1;			// 6	Software Force Sync Pulse
	Uint16	HSPCLKDIV:3;		// 9:7	High Speed TBCLK Pre-scaler
	Uint16	CLKDIV:3;			// 12:10	Time Base Clock Pre-scaler
	Uint16	PHSDIR:1;			// 13	Phase Direction Bit
	Uint16	FREE_SOFT:2;		// 15:14	Emulation Mode Bits
};

union TBCTL_REG {
	Uint16 all;
	struct TBCTL_BITS	bit;
};

struct TBSTS_BITS {     // bits description
	Uint16	CTRDIR:1;			// 0	Counter Direction Status
	Uint16	SYNCI:1;			// 1	External Input Sync Status
	Uint16	CTRMAX:1;			// 2	Counter Max Latched Status
	Uint16	rsvd1:13;			// 15:3	Reserved
};

union TBSTS_REG {
	Uint16 all;
	struct TBSTS_BITS	bit;
};

struct CMPCTL_BITS {     // bits description
	Uint16	LOADAMODE:2;		// 1:0	Active Compare A Load
	Uint16	LOADBMODE:2;		// 3:2	Active Compare B Load
	Uint16	SHDWAMODE:1;		// 4	Compare A Register Block Operating Mode
	Uint16	rsvd1:1;			// 5	Reserved
	Uint16	SHDWBMODE:1;		// 6	Compare B Register Block Operating Mode
	Uint16	rsvd2:1;			// 7	Reserved
	Uint16	SHDWAFULL:1;		// 8	Compare A Shadow Register Full Status
	Uint16	SHDWBFULL:1;		// 9	Compare B Shadow Register Full Status
    Uint16 rsvd3:6;            // 15:10  reserved
};

union CMPCTL_REG {
	Uint16 all;
	struct CMPCTL_BITS	bit;
};

struct AQCTL_BITS {     // bits description
	Uint16	ZRO:2;			// 1:0	Action Counter = Zero
	Uint16	PRD:2;			// 3:2	Action Counter = Period
	Uint16	CAU:2;			// 5:4	Action Counter = Compare A Up
	Uint16	CAD:2;			// 7:6	Action Counter = Compare A Down
	Uint16	CBU:2;			// 9:8	Action Counter = Compare B Up
	Uint16	CBD:2;			// 11:10	Action Counter = Compare B Down
	Uint16	rsvd1:4;		// 15:12	Reserved
};

union AQCTL_REG {
	Uint16 all;
	struct AQCTL_BITS	bit;
};

struct AQSFRC_BITS {     // bits description
	Uint16	ACTSFA:2;			// 1:0	Action when One-time SW Force A Invoked
	Uint16	OTSFA:1;			// 2	One-time SW Force A Output
	Uint16	ACTSFB:2;			// 4:3	Action when One-time SW Force B Invoked
	Uint16	OTSFB:1;			// 5	One-time SW Force A Output
	Uint16	RLDCSF:2;			// 7:6	Reload from Shadow Options
	Uint16	rsvd1:8;			// 15:8	Reserved
};

union AQSFRC_REG {
	Uint16 all;
	struct AQSFRC_BITS	bit;
};

struct AQCSFRC_BITS {     // bits description
	Uint16	CSFA:2;			// 1:0	Continuous Software Force on output A
	Uint16	CSFB:2;			// 3:2	Continuous Software Force on output B
	Uint16	rsvd1:12;		// 15:4	Reserved
};

union AQCSFRC_REG {
	Uint16 all;
	struct AQCSFRC_BITS	bit;
};

struct DBCTL_BITS {     // bits description
	Uint16	OUT_MODE:2;			// 1:0	Dead Band Output Mode Control
	Uint16	POLSEL:2;			// 3:2	Polarity Select Control
	Uint16	IN_MODE:2;			// 5:4	Dead Band Input Select Mode Control
	Uint16	rsvd1:9;			// 14:6	Reserved
	Uint16	HALFCYCLE:1;		// 15	Half Cycle Clocking Enable
};

union DBCTL_REG {
	Uint16 all;
	struct DBCTL_BITS	bit;
};

struct TZSEL_BITS {     // bits description
	Uint16	CBC1:1;			// 0	TZ1 CBC select
	Uint16	CBC2:1;			// 1	TZ2 CBC select
	Uint16	CBC3:1;			// 2	TZ3 CBC select
	Uint16	CBC4:1;			// 3	TZ4 CBC select
	Uint16	CBC5:1;			// 4	TZ5 CBC select
	Uint16	CBC6:1;			// 5	TZ6 CBC select
	Uint16	DCAEVT2:1;		// 6	DCAEVT2 CBC select
	Uint16	DCBEVT2:1;		// 7	DCBEVT2 CBC select
	Uint16	OSHT1:1;		// 8	One-shot TZ1 select
	Uint16	OSHT2:1;		// 9	One-shot TZ2 select
	Uint16	OSHT3:1;		// 10	One-shot TZ3 select
	Uint16	OSHT4:1;		// 11	One-shot TZ4 select
	Uint16	OSHT5:1;		// 12	One-shot TZ5 select
	Uint16	OSHT6:1;		// 13	One-shot TZ6 select
	Uint16	DCAEVT1:1;		// 14	One-shot DCAEVT1 select
	Uint16	DCBEVT1:1;		// 15	One-shot DCBEVT1 select
};

union TZSEL_REG {
	Uint16 all;
	struct TZSEL_BITS	bit;
};

struct TZDCSEL_BITS {     // bits description
	Uint16	DCAEVT1:3;			// 2:0	Digital Compare Output A Event 1
	Uint16	DCAEVT2:3;			// 5:3	Digital Compare Output A Event 2
	Uint16	DCBEVT1:3;			// 8:6	Digital Compare Output B Event 1
	Uint16	DCBEVT2:3;			// 11:9	Digital Compare Output B Event 2
	Uint16	rsvd1:4;			// 15:12	Reserved
};

union TZDCSEL_REG {
	Uint16 all;
	struct TZDCSEL_BITS	bit;
};

struct TZCTL_BITS {     // bits description
	Uint16	TZA:2;			// 1:0	TZ1 to TZ6 Trip Action On EPWMxA
	Uint16	TZB:2;			// 3:2	TZ1 to TZ6 Trip Action On EPWMxB
	Uint16	DCAEVT1:2;		// 5:4	EPWMxA action on DCAEVT1
	Uint16	DCAEVT2:2;		// 7:6	EPWMxA action on DCAEVT2
	Uint16	DCBEVT1:2;		// 9:8	EPWMxB action on DCBEVT1
	Uint16	DCBEVT2:2;		// 11:10	EPWMxB action on DCBEVT2
	Uint16	rsvd1:4;		// 15:12	Reserved
};

union TZCTL_REG {
	Uint16 all;
	struct TZCTL_BITS	bit;
};

struct TZEINT_BITS {     // bits description
	Uint16	rsvd1:1;		// 0	Reserved
	Uint16	CBC:1;			// 1	Trip Zones Cycle By Cycle Int Enable
	Uint16	OST:1;			// 2	Trip Zones One Shot Int Enable
	Uint16	DCAEVT1:1;		// 3	Digital Compare A Event 1 Int Enable
	Uint16	DCAEVT2:1;		// 4	Digital Compare A Event 2 Int Enable
	Uint16	DCBEVT1:1;		// 5	Digital Compare B Event 1 Int Enable
	Uint16	DCBEVT2:1;		// 6	Digital Compare B Event 2 Int Enable
	Uint16	rsvd2:9;		// 15:7	Reserved
};

union TZEINT_REG {
	Uint16 all;
	struct TZEINT_BITS	bit;
};

struct TZFLG_BITS {     // bits description
	Uint16	INT:1;			// 0	Global Int Status Flag
	Uint16	CBC:1;			// 1	Trip Zones Cycle By Cycle Flag
	Uint16	OST:1;			// 2	Trip Zones One Shot Flag
	Uint16	DCAEVT1:1;		// 3	Digital Compare A Event 1 Flag
	Uint16	DCAEVT2:1;		// 4	Digital Compare A Event 2 Flag
	Uint16	DCBEVT1:1;		// 5	Digital Compare B Event 1 Flag
	Uint16	DCBEVT2:1;		// 6	Digital Compare B Event 2 Flag
	Uint16	rsvd1:9;		// 15:7	Reserved
};

union TZFLG_REG {
	Uint16 all;
	struct TZFLG_BITS	bit;
};

struct TZCLR_BITS {     // bits description
	Uint16	INT:1;			// 0	Global Interrupt Clear Flag
	Uint16	CBC:1;			// 1	Cycle-By-Cycle Flag Clear
	Uint16	OST:1;			// 2	One-Shot Flag Clear
	Uint16	DCAEVT1:1;		// 3	DCAVET1 Flag Clear
	Uint16	DCAEVT2:1;		// 4	DCAEVT2 Flag Clear
	Uint16	DCBEVT1:1;		// 5	DCBEVT1 Flag Clear
	Uint16	DCBEVT2:1;		// 6	DCBEVT2 Flag Clear
	Uint16	rsvd1:9;		// 15:7	Reserved
};

union TZCLR_REG {
	Uint16 all;
	struct TZCLR_BITS	bit;
};

struct TZFRC_BITS {     // bits description
	Uint16	rsvd1:1;		// 0	Reserved
	Uint16	CBC:1;			// 1	Force Trip Zones Cycle By Cycle Event
	Uint16	OST:1;			// 2	Force Trip Zones One Shot Event
	Uint16	DCAEVT1:1;		// 3	Force Digital Compare A Event 1
	Uint16	DCAEVT2:1;		// 4	Force Digital Compare A Event 2
	Uint16	DCBEVT1:1;		// 5	Force Digital Compare B Event 1
	Uint16	DCBEVT2:1;		// 6	Force Digital Compare B Event 2
	Uint16	rsvd2:9;		// 15:7	Reserved
};

union TZFRC_REG {
	Uint16 all;
	struct TZFRC_BITS	bit;
};

struct ETSEL_BITS {     // bits description
	Uint16	INTSEL:3;			// 2:0	EPWMxINTn Select
	Uint16	INTEN:1;			// 3	EPWMxINTn Enable
	Uint16	rsvd1:4;			// 7:4	Reserved
	Uint16	SOCASEL:3;			// 10:8	Start of Conversion A Select
	Uint16	SOCAEN:1;			// 11	Start of Conversion A Enable
	Uint16	SOCBSEL:3;			// 14:12	Start of Conversion B Select
	Uint16	SOCBEN:1;			// 15	Start of Conversion B Enable
};

union ETSEL_REG {
	Uint16 all;
	struct ETSEL_BITS	bit;
};

struct ETPS_BITS {     // bits description
	Uint16	INTPRD:2;			// 1:0	EPWMxINTn Period Select
	Uint16	INTCNT:2;			// 3:2	EPWMxINTn Counter Register
	Uint16	rsvd1:4;			// 7:4	Reserved
	Uint16	SOCAPRD:2;			// 9:8	EPWMxSOCA Period Select
	Uint16	SOCACNT:2;			// 11:10	EPWMxSOCA Counter Register
	Uint16	SOCBPRD:2;			// 13:12	EPWMxSOCB Period Select
	Uint16	SOCBCNT:2;			// 15:14	EPWMxSOCB Counter
};

union ETPS_REG {
	Uint16 all;
	struct ETPS_BITS	bit;
};

struct ETFLG_BITS {     // bits description
	Uint16	INT:1;			// 0	EPWMxINTn Flag
	Uint16	rsvd1:1;		// 1	Reserved
	Uint16	SOCA:1;			// 2	EPWMxSOCA Flag
	Uint16	SOCB:1;			// 3	EPWMxSOCB Flag
	Uint16	rsvd2:12;		// 15:4	Reserved
};

union ETFLG_REG {
	Uint16 all;
	struct ETFLG_BITS	bit;
};

struct ETCLR_BITS {     // bits description
	Uint16	INT:1;			// 0	EPWMxINTn Clear
	Uint16	rsvd1:1;		// 1	Reserved
	Uint16	SOCA:1;			// 2	EPWMxSOCA Clear
	Uint16	SOCB:1;			// 3	EPWMxSOCB Clear
	Uint16	rsvd2:12;		// 15:4	Reserved
};

union ETCLR_REG {
	Uint16 all;
	struct ETCLR_BITS	bit;
};

struct ETFRC_BITS {     // bits description
	Uint16	INT:1;			// 0	EPWMxINTn Force
	Uint16	rsvd1:1;		// 1	Reserved
	Uint16	SOCA:1;			// 2	EPWMxSOCA Force
	Uint16	SOCB:1;			// 3	EPWMxSOCB Force
	Uint16	rsvd2:12;		// 15:4	Reserved
};

union ETFRC_REG {
	Uint16 all;
	struct ETFRC_BITS	bit;
};

struct PCCTL_BITS {     // bits description
	Uint16	CHPEN:1;			// 0	PWM chopping enable
	Uint16	OSHTWTH:4;			// 4:1	One-shot pulse width
	Uint16	CHPFREQ:3;			// 7:5	Chopping clock frequency
	Uint16	CHPDUTY:3;			// 10:8	Chopping clock Duty cycle
	Uint16	rsvd1:5;			// 15:11	Reserved
};

union PCCTL_REG {
	Uint16 all;
	struct PCCTL_BITS	bit;
};

struct HRCNFG_BITS {     // bits description
	Uint16	EDGMODE:2;			// 1:0	ePWMxA Edge Mode Select Bits
	Uint16	CTLMODE:1;			// 2	ePWMxA Control Mode Select Bits
	Uint16	HRLOAD:2;			// 4:3	ePWMxA Shadow Mode Select Bits
	Uint16	SELOUTB:1;			// 5	EPWMB Output Selection Bit
	Uint16	AUTOCONV:1;			// 6	Autoconversion Bit
	Uint16	SWAPAB:1;			// 7	Swap EPWMA and EPWMB Outputs Bit
	Uint16	rsvd1:8;			// 15:8	Reserved
};

union HRCNFG_REG {
	Uint16 all;
	struct HRCNFG_BITS	bit;
};

struct HRPWR_BITS {       	// bits   description
   Uint16  rsvd1:6;     	// 5:0    reserved
   Uint16  MEPOFF:4;     	// 9:6    MEP Calibration Off Bits
   Uint16  rsvd2:6;      	// 15:10  reserved
};

union HRPWR_REG {
   Uint16                  	all;
   struct HRPWR_BITS        bit;
};

struct HRPCTL_BITS {     // bits description
	Uint16	HRPE:1;				// 0	High Resolution Period Enable
	Uint16	PWMSYNCSEL:1;       // 1      PWMSYNC Source Select Bit 
	Uint16	TBPHSHRLOADE:1;		// 2	TBPHSHR Load Enable
	Uint16	rsvd1:13;			// 15:3	Reserved
};

union HRPCTL_REG {
	Uint16 all;
	struct HRPCTL_BITS	bit;
};

struct DCTRIPSEL_BITS {     // bits description
	Uint16	DCAHCOMPSEL:4;			// 3:0	Digital Compare A High COMP Input Select
	Uint16	DCALCOMPSEL:4;			// 7:4	Digital Compare A Low COMP Input Select
	Uint16	DCBHCOMPSEL:4;			// 11:8	Digital Compare B High COMP Input Select
	Uint16	DCBLCOMPSEL:4;			// 15:12	Digital Compare B Low COMP Input Select
};

union DCTRIPSEL_REG {
	Uint16 all;
	struct DCTRIPSEL_BITS	bit;
};

struct DCCTL_BITS {     // bits description
	Uint16	EVT1SRCSEL:1;			// 0	DCAEVT1 Source Signal
	Uint16	EVT1FRCSYNCSEL:1;		// 1	DCAEVT1 Force Sync Signal
	Uint16	EVT1SOCE:1;				// 2	DCAEVT1 SOC Enable
	Uint16	EVT1SYNCE:1;			// 3	DCAEVT1 SYNC Enable
	Uint16	rsvd1:4;				// 7:4	Reserved
	Uint16	EVT2SRCSEL:1;			// 8	DCAEVT2 Source Signal
	Uint16	EVT2FRCSYNCSEL:1;		// 9	DCAEVT2 Force Sync Signal
	Uint16	rsvd2:6;				// 15:10	Reserved
};

union DCCTL_REG {
	Uint16 all;
	struct DCCTL_BITS	bit;
};

struct DCFCTL_BITS {     // bits description
	Uint16	SRCSEL:2;			// 1:0	Filter Block Signal Source Select
	Uint16	BLANKE:1;			// 2	Blanking Enable/Disable
	Uint16	BLANKINV:1;			// 3	Blanking Window Inversion
	Uint16	PULSESEL:2;			// 5:4	Pulse Select for Blanking & Capture Alignment
	Uint16	rsvd1:10;			// 15:6	Reserved
};

union DCFCTL_REG {
	Uint16 all;
	struct DCFCTL_BITS	bit;
};

struct DCCAPCTL_BITS {     // bits description
	Uint16	CAPE:1;				// 0	Counter Capture Enable
	Uint16	SHDWMODE:1;			// 1	Counter Capture Mode
	Uint16	rsvd1:14;			// 15:2	Reserved
};

union DCCAPCTL_REG {
	Uint16 all;
	struct DCCAPCTL_BITS	bit;
};

struct TBPHS_HRPWM_REG {   	// bits   description
   Uint16  TBPHSHR;     	// 15:0   Extension register for HRPWM Phase (8 bits)
   Uint16  TBPHS;           // 31:16  Phase offset register
};

union TBPHS_HRPWM_GROUP {
   Uint32                  all;
   struct TBPHS_HRPWM_REG  half;
};

struct CMPA_HRPWM_REG {   	// bits   description
   Uint16  CMPAHR;     	    // 15:0   Extension register for HRPWM compare (8 bits)
   Uint16  CMPA;            // 31:16  Compare A reg
};

union CMPA_HRPWM_GROUP {
   Uint32                 all;
   struct CMPA_HRPWM_REG  half;
};

struct TBPRD_HRPWM_REG {   	// bits   description
   Uint16  TBPRDHR;     	// 15:0   Extension register for HRPWM Period (8 bits)
   Uint16  TBPRD;           // 31:16  Timebase Period Register
};

union TBPRD_HRPWM_GROUP {
   Uint32                  all;
   struct TBPRD_HRPWM_REG  half;
};

struct EPWM_REGS {
	union	TBCTL_REG			TBCTL;			// Time Base Control Register
	union	TBSTS_REG			TBSTS;			// Time Base Status Register
	union	TBPHS_HRPWM_GROUP   TBPHS;			// Union of TBPHS:TBPHSHR
	Uint16						TBCTR;			// Time Base Counter Register
	Uint16						TBPRD;			// Time Base Period Register
	Uint16						TBPRDHR;		// Time Base Period High Resolution Register
	union	CMPCTL_REG			CMPCTL;			// Counter Compare Control Register
	union	CMPA_HRPWM_GROUP 	CMPA;			// Union of CMPA:CMPAHR
	Uint16						CMPB;			// Counter Compare B Register
	union	AQCTL_REG			AQCTLA;			// Action Qualifier Control Register For Output A
	union	AQCTL_REG			AQCTLB;			// Action Qualifier Control Register For Output B
	union	AQSFRC_REG			AQSFRC;			// Action Qualifier Software Force Register
	union	AQCSFRC_REG			AQCSFRC;		// Action Qualifier Continuous S/W Force Register
	union	DBCTL_REG			DBCTL;			// Dead-Band Generator Control Register
	Uint16						DBRED;			// Dead-Band Generator Rising Edge Delay Count Register
	Uint16						DBFED;			// Dead-Band Generator Falling Edge Delay Count Register
	union	TZSEL_REG			TZSEL;			// Trip Zone Select Register
	union	TZDCSEL_REG			TZDCSEL;		// Trip Zone Digital Comparator Select Register
	union	TZCTL_REG			TZCTL;			// Trip Zone Control Register
	union	TZEINT_REG			TZEINT;			// Trip Zone Enable Interrupt Register
	union	TZFLG_REG			TZFLG;			// Trip Zone Flag Register
	union	TZCLR_REG			TZCLR;			// Trip Zone Clear Register
	union	TZFRC_REG			TZFRC;			// Trip Zone Force Register
	union	ETSEL_REG			ETSEL;			// Event Trigger Selection Register
	union	ETPS_REG			ETPS;			// Event Trigger Pre-Scale Register
	union	ETFLG_REG			ETFLG;			// Event Trigger Flag Register
	union	ETCLR_REG			ETCLR;			// Event Trigger Clear Register
	union	ETFRC_REG			ETFRC;			// Event Trigger Force Register
	union	PCCTL_REG			PCCTL;			// PWM Chopper Control Register
	Uint16						rsvd1;			// Reserved
	union	HRCNFG_REG			HRCNFG;			// HRPWM Configuration Register
    union   HRPWR_REG			HRPWR;          // HRPWM Power Register
	Uint16						rsvd2;			// Reserved
	Uint16						rsvd3;			// Reserved
	Uint16						rsvd4;			// Reserved
	Uint16						rsvd5;			// Reserved
	Uint16						HRMSTEP;		// HRPWM MEP Step Register
	Uint16						rsvd6;			// Reserved
	union	HRPCTL_REG			HRPCTL;			// High Resolution Period Control Register
	Uint16						rsvd7;			// Reserved
	union   TBPRD_HRPWM_GROUP   TBPRDM;     	// Union of TBPRD:TBPRDHR mirror registers
    union   CMPA_HRPWM_GROUP    CMPAM;      	// Union of CMPA:CMPAHR mirror registers
	Uint16						rsvd8[2];		// Reserved
	union	DCTRIPSEL_REG		DCTRIPSEL;		// Digital Compare Trip Select Register
	union	DCCTL_REG			DCACTL;			// Digital Compare A Control Register
	union	DCCTL_REG			DCBCTL;			// Digital Compare B Control Register
	union	DCFCTL_REG			DCFCTL;			// Digital Compare Filter Control Register
	union	DCCAPCTL_REG		DCCAPCTL;		// Digital Compare Capture Control Register
	Uint16						DCFOFFSET;		// Digital Compare Filter Offset Register
	Uint16						DCFOFFSETCNT;	// Digital Compare Filter Offset Counter Register
	Uint16						DCFWINDOW;		// Digital Compare Filter Window Register
	Uint16						DCFWINDOWCNT;	// Digital Compare Filter Window Counter Register
	Uint16						DCCAP;			// Digital Compare Counter Capture Register
	Uint16                      rsvd9[6];
};

//---------------------------------------------------------------------------
// Epwm External References & Function Declarations:
//
extern volatile struct EPWM_REGS EPwm1Regs;
extern volatile struct EPWM_REGS EPwm2Regs;
extern volatile struct EPWM_REGS EPwm3Regs;
extern volatile struct EPWM_REGS EPwm4Regs;
extern volatile struct EPWM_REGS EPwm5Regs;
extern volatile struct EPWM_REGS EPwm6Regs;
extern volatile struct EPWM_REGS EPwm7Regs;
extern volatile struct EPWM_REGS EPwm8Regs;

#ifdef __cplusplus
}
#endif /* extern "C" */


#endif  // end of F2806x_EPWM_H definition
//===========================================================================
// End of file.
//===========================================================================
