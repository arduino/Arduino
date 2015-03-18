//###########################################################################
//
// FILE:   F2806x_Sysctrl.h
//
// TITLE:  F2806x Device SYSCTRL Register Definitions.
//
//###########################################################################
// $TI Release: 2806x C/C++ Header Files V1.10 $
// $Release Date: April 7, 2011 $
//###########################################################################

#ifndef F2806x_SYSCTRL_H
#define F2806x_SYSCTRL_H

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// SYSCTRL Individual Register Bit Definitions:


struct XCLK_BITS {     // bits description
	Uint16	XCLKOUTDIV:2;			// 1:0 	XCLKOUT Divide Ratio
	Uint16	rsvd1:4;				// 5:2	Reserved
	Uint16	XCLKINSEL:1;			// 6	XCLKIN Source Select
	Uint16	rsvd2:9;				// 15:7	Reserved
};

union XCLK_REG {
	Uint16 all;
	struct XCLK_BITS	bit;
};

struct PLLSTS_BITS {     // bits description
	Uint16	PLLLOCKS:1;			// 0	PLL lock status
	Uint16	rsvd1:1;			// 1	Reserved
	Uint16	PLLOFF:1;			// 2	PLL off bit
	Uint16	MCLKSTS:1;			// 3	Missing clock status bit
	Uint16	MCLKCLR:1;			// 4	Missing clock clear bit
	Uint16	OSCOFF:1;			// 5	Oscillator clock off
	Uint16	MCLKOFF:1;			// 6	Missing clock detect
	Uint16	DIVSEL:2;			// 8:7	Divide select (/4 default)
	Uint16	rsvd2:6;			// 14:9	Reserved
	Uint16	NORMRDYE:1;			// 15	VREG NORMRDY enable bit
};

union PLLSTS_REG {
	Uint16 all;
	struct PLLSTS_BITS	bit;
};

struct CLKCTL_BITS {     // bits description
	Uint16	OSCCLKSRCSEL:1;			// 0	Oscillator clock source select bit
	Uint16	OSCCLKSRC2SEL:1;		// 1	Oscillator 2 clock source select bit
	Uint16	WDCLKSRCSEL:1;			// 2	Watchdog clock source select bit
	Uint16	TMR2CLKSRCSEL:2;		// 4:3	CPU timer 2 clock source select bit
	Uint16	TMR2CLKPRESCALE:3;		// 7:5	CPU timer 2 clock pre-scale value
	Uint16	INTOSC1OFF:1;			// 8	Internal oscillator off bit
	Uint16	INTOSC1HALTI:1;			// 9	Internal oscillator 1 halt mode ignore bit
	Uint16	INTOSC2OFF:1;			// 10	Internal oscillator 2 off bit
	Uint16	INTOSC2HALTI:1;			// 11	Internal oscillator 2 halt mode ignore bit
	Uint16	WDHALTI:1;				// 12	Watchdog halt mode ignore bit
	Uint16	XCLKINOFF:1;			// 13	XCLKIN off bit
	Uint16	XTALOSCOFF:1;			// 14	Crystal (External) oscillator off bit
	Uint16	NMIRESETSEL:1;			// 15	NMI reset select bit
};

union CLKCTL_REG {
	Uint16 all;
	struct CLKCTL_BITS	bit;
};

struct INTOSC1TRIM_BITS {     // bits description
	Uint16	COARSETRIM:8;		// 7:0	8-bit coarse trim value
	Uint16	rsvd1:1;			// 8	Reserved
	Uint16	FINETRIM:6;			// 14:9	6-bit fine trim value
	Uint16	rsvd2:1;			// 15	Reserved
};

union INTOSC1TRIM_REG {
	Uint16 all;
	struct INTOSC1TRIM_BITS	bit;
};

struct INTOSC2TRIM_BITS {     // bits description
	Uint16	COARSETRIM:8;		// 7:0	8-bit coarse trim value
	Uint16	rsvd1:1;			// 8	Reserved
	Uint16	FINETRIM:6;			// 14:9	6-bit fine trim value
	Uint16	rsvd2:1;			// 15	Reserved
};

union INTOSC2TRIM_REG {
	Uint16 all;
	struct INTOSC2TRIM_BITS	bit;
};

struct PCLKCR2_BITS {	// bits description
	Uint16	rsvd1:8;			// 7:0	Reserved
	Uint16	HRCAP1ENCLK:1;		// 8 	HRCAP1 Clock Enable
	Uint16	HRCAP2ENCLK:1;		// 9	HRCAP2 Clock Enable
	Uint16	HRCAP3ENCLK:1;		// 10	HRCAP3 Clock Enable
	Uint16	HRCAP4ENCLK:1;		// 11	HRCAP4 Clock Enable
	Uint16	rsvd2:4;			// 15:12 Reserved
};

union PCLKCR2_REG {
	Uint16 all;
	struct PCLKCR2_BITS	bit;
};

struct LOSPCP_BITS {     // bits description
	Uint16	LSPCLK:3;			// 2:0	Rate relative to SYSCLKOUT
	Uint16	rsvd1:13;			// 15:3	Reserved
};

union LOSPCP_REG {
	Uint16 all;
	struct LOSPCP_BITS	bit;
};

struct PCLKCR0_BITS {     // bits description
	Uint16	HRPWMENCLK:1;		// 0	HRPWM Clock Enable
	Uint16	rsvd1:1;			// 1	Reserved
	Uint16	TBCLKSYNC:1;		// 2	EWPM Module TBCLK enable/sync
	Uint16	ADCENCLK:1;			// 3	Enable high speed clk to ADC1
	Uint16	I2CAENCLK:1;		// 4	I2C-A Clock Enable
	Uint16	rsvd2:1;			// 5	Reserved
	Uint16	rsvd3:2;			// 7:6	Reserved
	Uint16	SPIAENCLK:1;		// 8	SPI A Clock Enable
	Uint16	SPIBENCLK:1;		// 9	SPI B Clock Enable
	Uint16	SCIAENCLK:1;		// 10	SCI A Clock Enable
	Uint16	SCIBENCLK:1;		// 11	SCI B Clock Enable
	Uint16	MCBSPAENCLK:1;		// 12	McBSP-A Clock Enable
	Uint16	rsvd4:1;			// 13	Reserved
	Uint16	ECANAENCLK:1;		// 14	CAN A Clock Enable
	Uint16	rsvd5:1;			// 15	Reserved
};

union PCLKCR0_REG {
	Uint16 all;
	struct PCLKCR0_BITS	bit;
};

struct PCLKCR1_BITS {     // bits description
	Uint16	EPWM1ENCLK:1;			// 0	EPWM1 Clock Enable
	Uint16	EPWM2ENCLK:1;			// 1	EPWM2 Clock Enable
	Uint16	EPWM3ENCLK:1;			// 2	EPWM3 Clock Enable
	Uint16	EPWM4ENCLK:1;			// 3	EPWM4 Clock Enable
	Uint16	EPWM5ENCLK:1;			// 4	EPWM5 Clock Enable
	Uint16	EPWM6ENCLK:1;			// 5	EPWM6 Clock Enable
	Uint16	EPWM7ENCLK:1;			// 6	EPWM7 Clock Enable
	Uint16	EPWM8ENCLK:1;			// 7	EPWM8 Clock Enable
	Uint16	ECAP1ENCLK:1;			// 8	ECAP1 Clock Enable
	Uint16	ECAP2ENCLK:1;			// 9	ECAP2 Clock Enable
	Uint16	ECAP3ENCLK:1;			// 10	ECAP3 Clock Enable
	Uint16	rsvd1:3;				// 13:11	Reserved
	Uint16	EQEP1ENCLK:1;			// 14	EQEP1 Clock Enable
	Uint16	EQEP2ENCLK:1;			// 15	EQEP2 Clock Enable
};

union PCLKCR1_REG {
	Uint16 all;
	struct PCLKCR1_BITS	bit;
};

struct PCLKCR3_BITS {     // bits description
	Uint16	COMP1ENCLK:1;			// 0	COMP1 and DAC1 Clock Enable
	Uint16	COMP2ENCLK:1;			// 1	COMP2 and DAC2 Clock Enable
	Uint16	COMP3ENCLK:1;			// 2	COMP3 and DAC3 Clock Enable
	Uint16	rsvd1:5;				// 7:3	Reserved
	Uint16	CPUTIMER0ENCLK:1;		// 8	Enable SYSCLKOUT to CPUTIMER0
	Uint16	CPUTIMER1ENCLK:1;		// 9	Enable SYSCLKOUT to CPUTIMER1
	Uint16	CPUTIMER2ENCLK:1;		// 10	Enable SYSCLKOUT to CPUTIMER2
	Uint16	DMAENCLK:1;				// 11	DMA Clock Enable
	Uint16	rsvd2:1;				// 12	Reserved
	Uint16	rsvd3:1;				// 13	Reserved
	Uint16	CLA1ENCLK:1;			// 14	CLA Clock Enable
	Uint16	USB0ENCLK:1;			// 15	USB0 Clock Enable
};

union PCLKCR3_REG {
	Uint16 all;
	struct PCLKCR3_BITS	bit;
};

struct PLLCR_BITS {     // bits description
	Uint16	DIV:5;				// 4:0	Set Clock ratio for the PLL
	Uint16	rsvd1:11;			// 15:4	Reserved
};

union PLLCR_REG {
	Uint16 all;
	struct PLLCR_BITS	bit;
};

struct JTAGDEBUG_BITS {	// bits description
	Uint16	JTAGDIS:1;		// JTAG Port Disable Bit
	Uint16	rsvd1:15;		// Reserved
};

union JTAGDEBUG_REG {
	Uint16	all;
	struct	JTAGDEBUG_BITS	bit;
};

struct LPMCR0_BITS {     // bits description
	Uint16	LPM:2;				// 1:0	Set the low power mode
	Uint16	QUALSTDBY:6;		// 7:2	Qualification
	Uint16	rsvd1:7;			// 14:8	Reserved
	Uint16	WDINTE:1;			// 15	Enables WD to wake the device from STANDBY
};

union LPMCR0_REG {
	Uint16 all;
	struct LPMCR0_BITS	bit;
};

struct PLL2CTL_BITS {	// bits description
	Uint16	PLL2CLKSRCSEL:2;	// 1:0	PLL2 Clock Source Select Bits
	Uint16	PLL2EN:1;			// 2	PLL2 Enable Bit
	Uint16	rsvd1:13;			// 15:3	Reserved
};

union PLL2CTL_REG {
	Uint16 all;
	struct PLL2CTL_BITS	bit;
};

struct PLL2MULT_BITS {	// bits description
	Uint16	PLL2MULT:4;		// 3:0	PLL2 Integer Multiplier
	Uint16	rsvd1:12;		// 15:4	Reserved
};

union PLL2MULT_REG {
	Uint16 all;
	struct PLL2MULT_BITS	bit;
};

struct PLL2STS_BITS {	// bits description
	Uint16	PLL2LOCKS:1;	// 0	PLL2 Lock Status Bit
	Uint16	rsvd1:15;		// 15:1	Reserved
};

union PLL2STS_REG {
	Uint16 all;
	struct PLL2STS_BITS	bit;
};

struct EPWMCFG_BITS {     // bits description
	Uint16	CONFIG:1;			// 0	EPWM to DMA/CLA Enable Bit
	Uint16	rsvd1:15;			// 15:1	Reserved
};

union EPWMCFG_REG {
	Uint16 all;
	struct EPWMCFG_BITS	bit;
};

/* System Power Control Registers */

// BOR configuration register bit definitions:
struct BORCFG_BITS {     // bits  description
   Uint16 BORENZ:1;      // 0     BOR enable active low bit
   Uint16 rsvd1:15;      // 15:1  reserved
};

union BORCFG_REG {
   Uint16              all;
   struct BORCFG_BITS  bit;
};

struct SYS_PWR_CTRL_REGS {
    union    BORCFG_REG   BORCFG;       // 0 BOR Configuration Register
    Uint16   rsvd1[2];                  // 1-2
};

/* CSM Status & Control register bit definitions */
struct  CSMSCR_BITS {      // bit   description
   Uint16     SECURE:1;    // 0     Secure flag
   Uint16     rsvd1:14;    // 14:1  Reserved
   Uint16     FORCESEC:1;  // 15    Force Secure control bit
};

/* Allow access to the bit fields or entire register */
union CSMSCR_REG {
   Uint16             all;
   struct CSMSCR_BITS bit;
};

/* CSM Register File */
struct  CSM_REGS {
   Uint16           KEY0;    // KEY reg bits 15-0
   Uint16           KEY1;    // KEY reg bits 31-16
   Uint16           KEY2;    // KEY reg bits 47-32
   Uint16           KEY3;    // KEY reg bits 63-48
   Uint16           KEY4;    // KEY reg bits 79-64
   Uint16           KEY5;    // KEY reg bits 95-80
   Uint16           KEY6;    // KEY reg bits 111-96
   Uint16           KEY7;    // KEY reg bits 127-112
   Uint16           rsvd1;   // Reserved
   Uint16           rsvd2;   // Reserved
   Uint16           rsvd3;   // Reserved
   Uint16           rsvd4;   // Reserved
   Uint16           rsvd5;   // Reserved
   Uint16           rsvd6;   // Reserved
   Uint16           rsvd7;   // Reserved
   union CSMSCR_REG CSMSCR;  // CSM Status & Control register
};

/* Password locations */
struct  CSM_PWL {
   Uint16   PSWD0;  // PSWD bits 15-0
   Uint16   PSWD1;  // PSWD bits 31-16
   Uint16   PSWD2;  // PSWD bits 47-32
   Uint16   PSWD3;  // PSWD bits 63-48
   Uint16   PSWD4;  // PSWD bits 79-64
   Uint16   PSWD5;  // PSWD bits 95-80
   Uint16   PSWD6;  // PSWD bits 111-96
   Uint16   PSWD7;  // PSWD bits 127-112
};

//Flash Registers
#define FLASH_SLEEP   0x0000;
#define FLASH_STANDBY 0x0001;
#define FLASH_ACTIVE  0x0003;

struct FOPT_BITS {     // bits description
	Uint16	ENPIPE:1;			// 0	Enable Pipeline Mode
	Uint16	rsvd1:15;			// 15:1	Reserved
};

union FOPT_REG {
	Uint16 all;
	struct FOPT_BITS	bit;
};

struct FPWR_BITS {     // bits description
	Uint16	PWR:2;				// 1:0	Power Mode Bits
	Uint16	rsvd1:14;			// 15:2	Reserved
};

union FPWR_REG {
	Uint16 all;
	struct FPWR_BITS	bit;
};

struct FSTATUS_BITS {     // bits description
	Uint16	PWRS:2;				// 1:0	Power Mode Status Bits
	Uint16	STDBYWAITS:1;		// 2	Bank/Pump Sleep to Standby Wait Counter Status Bits
	Uint16	ACTIVEWAITS:1;		// 3	Bank/Pump Standby to Active Wait Counter Status Bits
	Uint16	rsvd1:4;			// 7:4	Reserved
	Uint16	V3STAT:1;			// 8	VDD3V Status Latch Bit
	Uint16	rsvd2:7;			// 15:9	Reserved
};

union FSTATUS_REG {
	Uint16 all;
	struct FSTATUS_BITS	bit;
};

struct FSTDBYWAIT_BITS {     // bits description
	Uint16	STDBYWAIT:9;		// 8:0	Bank/Pump Sleep to Standby Wait Count Bits
	Uint16	rsvd1:7;			// 15:9	Reserved
};

union FSTDBYWAIT_REG {
	Uint16 all;
	struct FSTDBYWAIT_BITS	bit;
};

struct FACTIVEWAIT_BITS {     // bits description
	Uint16	ACTIVEWAIT:9;		// 8:0	Bank/Pump Standby to Active Wait Count Bits
	Uint16	rsvd1:7;			// 15:9	Reserved
};

union FACTIVEWAIT_REG {
	Uint16 all;
	struct FACTIVEWAIT_BITS	bit;
};

struct FBANKWAIT_BITS {     // bits description
	Uint16	RANDWAIT:4;			// 3:0	Flash Random Read Wait State Bits
	Uint16	rsvd1:4;			// 7:4	Reserved
	Uint16	PAGEWAIT:4;			// 11:8	Flash Paged Read Wait State Bits
	Uint16	rsvd2:4;			// 15:12	Reserved
};

union FBANKWAIT_REG {
	Uint16 all;
	struct FBANKWAIT_BITS	bit;
};

struct FOTPWAIT_BITS {     // bits description
	Uint16	OTPWAIT:5;			// 4:0	OTP Read Wait State Bits
	Uint16	rsvd1:11;			// 15:5	Reserved
};

union FOTPWAIT_REG {
	Uint16 all;
	struct FOTPWAIT_BITS	bit;
};

struct SYS_CTRL_REGS {
	union	XCLK_REG		XCLK;			// XCLKOUT Control
	union	PLLSTS_REG		PLLSTS;			// PLL Status Register
	union	CLKCTL_REG		CLKCTL;			// Clock Control Register
	Uint16					PLLLOCKPRD;		// PLL Lock Period Register
	union	INTOSC1TRIM_REG	INTOSC1TRIM;	// Internal Oscillator 1 Trim Register
	Uint16					rsvd1;			// Reserved
	union	INTOSC2TRIM_REG	INTOSC2TRIM;	// Internal Oscillator 2 Trim
	Uint16					rsvd2[2];		// Reserved
	union	PCLKCR2_REG		PCLKCR2;		// Peripheral Clock Control Regsiter 2
	Uint16					rsvd3;			// Reserved
	union	LOSPCP_REG		LOSPCP;			// Low-Speed Peripheral Clock Pre-Scaler Register
	union	PCLKCR0_REG		PCLKCR0;		// Peripheral Clock Control Register 0
	union	PCLKCR1_REG		PCLKCR1;		// Peripheral Clock Control Register 1
	union	LPMCR0_REG		LPMCR0;			// Low Power Mode Control Register 0
	Uint16					rsvd4;			// Reserved
	union	PCLKCR3_REG		PCLKCR3;		// Peripheral Clock Control Register 3
	union	PLLCR_REG		PLLCR;			// PLL Control Register
	Uint16					SCSR;			// System Control and Status Register
	Uint16					WDCNTR;			// Watchdog Counter Register
	Uint16					rsvd5;			// Reserved
	Uint16					WDKEY;			// Watchdog Reset Key Register
	Uint16					rsvd6[3];		// Reserved
	Uint16					WDCR;			// Watchdog Control Register
	union	JTAGDEBUG_REG	JTAGDEBUG;		// JTAG Port Debug Register
	Uint16					rsvd7[5];		// Reserved
	union	PLL2CTL_REG		PLL2CTL;		// PLL2 Configuration Register
	Uint16					rsvd8;			// Reserved
	union	PLL2MULT_REG	PLL2MULT;		// PLL2 Multiplier Register
	Uint16					rsvd9;			// Reserved
	union	PLL2STS_REG		PLL2STS;		// PLL2 Lock Status Register
	Uint16					rsvd10;			// Reserved
	Uint16					SYSCLK2CNTR;	// SYSCLK2 Clock Counter Register
	Uint16					rsvd11[3];		// Reserved
	union	EPWMCFG_REG		EPWMCFG;		// EPWM DMA/CLA Configuration Register
	Uint16					rsvd12[5];		// Reserved
};

struct FLASH_REGS {
	union	FOPT_REG		FOPT;			// Option Register
	Uint16					rsvd1;			// Reserved
	union	FPWR_REG		FPWR;			// Power Modes Register
	union	FSTATUS_REG		FSTATUS;		// Status Register
	union	FSTDBYWAIT_REG	FSTDBYWAIT;		// Pump/Bank Sleep to Standby Wait State Register
	union	FACTIVEWAIT_REG	FACTIVEWAIT;	// Pump/Bank Standby to Active Wait State Register
	union	FBANKWAIT_REG	FBANKWAIT;		// Bank Read Access Wait State Register
	union	FOTPWAIT_REG	FOTPWAIT;		// OTP Read Access Wait State Regsiter
};

//---------------------------------------------------------------------------
// Sysctrl External References & Function Declarations:
//
extern volatile struct SYS_CTRL_REGS SysCtrlRegs;
extern volatile struct SYS_PWR_CTRL_REGS SysPwrCtrlRegs;
extern volatile struct CSM_PWL CsmPwl;
extern volatile struct CSM_REGS CsmRegs;
extern volatile struct FLASH_REGS FlashRegs;

#ifdef __cplusplus
}
#endif /* extern "C" */


#endif  // end of F2806x_SYSCTRL_H definition
//===========================================================================
// End of file.
//===========================================================================
