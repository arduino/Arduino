// TI File $Revision: /main/6 $
// Checkin $Date: October 16, 2009   15:43:41 $
//###########################################################################
//
// FILE:   DSP2802x_SysCtrl.h
//
// TITLE:  DSP2802x Device System Control Register Definitions.
//
//###########################################################################
// $TI Release: 2802x C/C++ Header Files and Peripheral Examples V1.29 $
// $Release Date: January 11, 2011 $
//###########################################################################

#ifndef DSP2802x_SYS_CTRL_H
#define DSP2802x_SYS_CTRL_H

#ifdef __cplusplus
extern "C" {
#endif

//---------------------------------------------------------------------------
// System Control Individual Register Bit Definitions:
//

// XCLKOUT Control
struct XCLK_BITS   {    // bits  description
   Uint16 XCLKOUTDIV:2; // 1:0   XCLKOUT Divide Ratio
   Uint16 rsvd1:3;      // 4:2   reserved
   Uint16 rsvd2:1;      // 5     reserved
   Uint16 XCLKINSEL:1;  // 6     XCLKIN Source Select bit
   Uint16 rsvd3:9;     // 15:7   reserved
};

union XCLK_REG {
   Uint16                     all;
   struct XCLK_BITS           bit;
};

// PLL Status Register
struct PLLSTS_BITS   {    // bits  description
   Uint16 PLLLOCKS:1;     // 0     PLL lock status
   Uint16 rsvd1:1;        // 1     reserved
   Uint16 PLLOFF:1;       // 2     PLL off bit
   Uint16 MCLKSTS:1;      // 3     Missing clock status bit
   Uint16 MCLKCLR:1;      // 4     Missing clock clear bit
   Uint16 OSCOFF:1;       // 5     Oscillator clock off
   Uint16 MCLKOFF:1;      // 6     Missing clock detect
   Uint16 DIVSEL:2;       // 8:7   Divide select (/4 default)
   Uint16 rsvd2:6;        // 14:9  reserved
   Uint16 NORMRDYE:1;     // 15    VREG NORMRDY enable bit
};

union PLLSTS_REG {
   Uint16                     all;
   struct PLLSTS_BITS         bit;
};

// Clock Control Register
struct CLKCTL_BITS   {        // bits  description
   Uint16 OSCCLKSRCSEL:1;     // 0     Oscillator clock source select bit
   Uint16 OSCCLKSRC2SEL:1;    // 1     Oscillator 2 clock source select bit
   Uint16 WDCLKSRCSEL:1;      // 2     Watchdog clock source select bit
   Uint16 TMR2CLKSRCSEL:2;    // 4:3   CPU timer 2 clock source select bit
   Uint16 TMR2CLKPRESCALE:3;  // 7:5   CPU timer 2 clock pre-scale value
   Uint16 INTOSC1OFF:1;       // 8     Internal oscillator off bit
   Uint16 INTOSC1HALTI:1;     // 9     Internal oscillator 1 halt mode ignore bit
   Uint16 INTOSC2OFF:1;       // 10    Internal oscillator 2 off bit
   Uint16 INTOSC2HALTI:1;     // 11    Internal oscillator 2 halt mode ignore bit
   Uint16 WDHALTI:1;          // 12    Watchdog halt mode ignore bit
   Uint16 XCLKINOFF:1;        // 13    XCLKIN off bit
   Uint16 XTALOSCOFF:1;       // 14    Crystal (External) oscillator off bit
   Uint16 NMIRESETSEL:1;      // 15    NMI reset select bit
};

union CLKCTL_REG {
   Uint16                     all;
   struct CLKCTL_BITS         bit;
};

// Internal Oscillator 1 Trim
struct INTOSC1TRIM_BITS   {    // bits  description
   Uint16 COARSETRIM:8;        // 7:0   8-bit coarse trim value
   Uint16 rsvd1:1;             // 8     reserved
   Uint16 FINETRIM:6;          // 9:14  6-bit fine trim value
   Uint16 rsvd2:1;             // 15    reserved
};

union INTOSC1TRIM_REG {
   Uint16                     all;
   struct INTOSC1TRIM_BITS    bit;
};

// Internal Oscillator 2 Trim
struct INTOSC2TRIM_BITS   {    // bits  description
   Uint16 COARSETRIM:8;        // 7:0   8-bit coarse trim value
   Uint16 rsvd1:1;             // 8     reserved
   Uint16 FINETRIM:6;          // 9:14  6-bit fine trim value
   Uint16 rsvd2:1;             // 15    reserved
};

union INTOSC2TRIM_REG {
   Uint16                     all;
   struct INTOSC2TRIM_BITS    bit;
};

// Low speed peripheral clock register bit definitions:
struct LOSPCP_BITS  {   // bits  description
   Uint16 LSPCLK:3;     // 2:0   Rate relative to SYSCLKOUT
   Uint16 rsvd1:13;     // 15:3  reserved
};

union LOSPCP_REG {
   Uint16                     all;
   struct LOSPCP_BITS         bit;
};

// Peripheral clock control register 0 bit definitions:
struct PCLKCR0_BITS  {  // bits  description
   Uint16 HRPWMENCLK:1; // 0     Enable low speed clk to HRPWM
   Uint16 rsvd1:1;      // 1     reserved
   Uint16 TBCLKSYNC:1;  // 2     ETWPM Module TBCLK enable/sync
   Uint16 ADCENCLK:1;   // 3     Enable high speed clk to ADC
   Uint16 I2CAENCLK:1;  // 4     Enable SYSCLKOUT to I2C-A
   Uint16 rsvd2:3;      // 7:5   reserved
   Uint16 SPIAENCLK:1;  // 8     Enable low speed clk to SPI-A
   Uint16 rsvd3:1;      // 9     reserved
   Uint16 SCIAENCLK:1;  // 10    Enable low speed clk to SCI-A
   Uint16 rsvd4:5;      // 15:11 reserved

};

union PCLKCR0_REG {
   Uint16                     all;
   struct PCLKCR0_BITS        bit;
};

// Peripheral clock control register 1 bit definitions:
struct PCLKCR1_BITS  {    // bits  description
   Uint16 EPWM1ENCLK:1;   // 0     Enable SYSCLKOUT to EPWM1
   Uint16 EPWM2ENCLK:1;   // 1     Enable SYSCLKOUT to EPWM2
   Uint16 EPWM3ENCLK:1;   // 2     Enable SYSCLKOUT to EPWM3
   Uint16 EPWM4ENCLK:1;   // 3     Enable SYSCLKOUT to EPWM4
   Uint16 rsvd1:4;        // 7:4   reserved
   Uint16 ECAP1ENCLK:1;   // 8     Enable SYSCLKOUT to ECAP1
   Uint16 rsvd2:7;        // 15:9  reserved
};

union PCLKCR1_REG {
   Uint16                     all;
   struct PCLKCR1_BITS        bit;
};

// Peripheral clock control register 3 bit definitions:
struct PCLKCR3_BITS  {       // bits  description
   Uint16 COMP1ENCLK:1;      // 0     Enable SYSCLKOUT to COMP1
   Uint16 COMP2ENCLK:1;      // 1     Enable SYSCLKOUT to COMP2
   Uint16 rsvd1:1;           // 2     reserved
   Uint16 rsvd2:5;           // 7:3   reserved
   Uint16 CPUTIMER0ENCLK:1;  // 8     Enable SYSCLKOUT to CPUTIMER0
   Uint16 CPUTIMER1ENCLK:1;  // 9     Enable SYSCLKOUT to CPUTIMER1
   Uint16 CPUTIMER2ENCLK:1;  // 10    Enable SYSCLKOUT to CPUTIMER2
   Uint16 rsvd3:2;           // 12:11 reserved
   Uint16 GPIOINENCLK:1;     // 13    Enable SYSCLKOUT to GPIO
   Uint16 rsvd4:2;           // 15:14
};

union PCLKCR3_REG {
   Uint16              all;
   struct PCLKCR3_BITS bit;
};

// PLL control register bit definitions:
struct PLLCR_BITS {      // bits  description
   Uint16 DIV:4;         // 3:0   Set clock ratio for the PLL
   Uint16 rsvd1:12;      // 15:4  reserved
};

union PLLCR_REG {
   Uint16             all;
   struct PLLCR_BITS  bit;
};

// Low Power Mode 0 control register bit definitions:
struct LPMCR0_BITS {     // bits  description
   Uint16 LPM:2;         // 1:0   Set the low power mode
   Uint16 QUALSTDBY:6;   // 7:2   Qualification
   Uint16 rsvd1:7;       // 14:8  reserved
   Uint16 WDINTE:1;      // 15    Enables WD to wake the device from STANDBY
};

union LPMCR0_REG {
   Uint16              all;
   struct LPMCR0_BITS  bit;
};




//---------------------------------------------------------------------------
// System Control Register File:
//
struct SYS_CTRL_REGS {
   union   XCLK_REG        XCLK;        // 0: XCLKOUT Control
   union   PLLSTS_REG      PLLSTS;      // 1: PLL Status Register
   union   CLKCTL_REG      CLKCTL;      // 2: Clock Control Register
   Uint16                  PLLLOCKPRD;  // 3: PLL Lock Period Register
   union   INTOSC1TRIM_REG INTOSC1TRIM; // 4: Internal Oscillator 1 Trim
   Uint16                  rsvd1;       // 5: reserved
   union   INTOSC2TRIM_REG INTOSC2TRIM; // 6: Internal Oscillator 2 Trim
   Uint16                  rsvd2[4];    // 7-10
   union   LOSPCP_REG      LOSPCP;      // 11: Low-speed peripheral clock pre-scaler
   union   PCLKCR0_REG     PCLKCR0;     // 12: Peripheral clock control register
   union   PCLKCR1_REG     PCLKCR1;     // 13: Peripheral clock control register
   union   LPMCR0_REG      LPMCR0;      // 14: Low-power mode control register 0
   Uint16                  rsvd3;       // 15: reserved
   union   PCLKCR3_REG     PCLKCR3;     // 16: Peripheral clock register
   union   PLLCR_REG       PLLCR;       // 17: PLL control register
   // No bit definitions are defined for SCSR because
   // a read-modify-write instruction can clear the WDOVERRIDE bit
   Uint16                  SCSR;        // 18: System control and status register
   Uint16                  WDCNTR;      // 19: WD counter register
   Uint16                  rsvd4;       // 20
   Uint16                  WDKEY;       // 21: WD reset key register
   Uint16                  rsvd5[3];    // 22-24
   // No bit definitions are defined for WDCR because
   // the proper value must be written to the WDCHK field
   // whenever writing to this register.
   Uint16                  WDCR;        // 25: WD timer control register
   Uint16                  rsvd6[5];    // 26-28
};

//---------------------------------------------------------------------------
// System Power Control Registers:
//

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
    union    BORCFG_REG   BORCFG;       // 0: BOR Configuration Register
    Uint16   rsvd1[2];                  // 1-2
};

/* --------------------------------------------------- */
/* CSM Registers                                       */
/*                                                     */
/* ----------------------------------------------------*/

/* CSM Status & Control register bit definitions */
struct  CSMSCR_BITS {      // bit   description
   Uint16     SECURE:1;    // 0     Secure flag
   Uint16     rsvd1:14;    // 14-1  reserved
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
   Uint16           rsvd1;   // reserved
   Uint16           rsvd2;   // reserved
   Uint16           rsvd3;   // reserved
   Uint16           rsvd4;   // reserved
   Uint16           rsvd5;   // reserved
   Uint16           rsvd6;   // reserved
   Uint16           rsvd7;   // reserved
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

/* Flash Registers */

#define FLASH_SLEEP   0x0000;
#define FLASH_STANDBY 0x0001;
#define FLASH_ACTIVE  0x0003;

/* Flash Option Register bit definitions */
struct  FOPT_BITS {       // bit   description
   Uint16     ENPIPE:1;   // 0     Enable Pipeline Mode
   Uint16     rsvd:15;    // 1-15  reserved
};

/* Allow access to the bit fields or entire register */
union FOPT_REG {
   Uint16           all;
   struct FOPT_BITS bit;
};

/* Flash Power Modes Register bit definitions */
struct  FPWR_BITS {       // bit   description
   Uint16     PWR:2;      // 0-1   Power Mode bits
   Uint16     rsvd:14;    // 2-15  reserved
};

/* Allow access to the bit fields or entire register */
union FPWR_REG {
   Uint16           all;
   struct FPWR_BITS bit;
};

/* Flash Status Register bit definitions */
struct  FSTATUS_BITS {       // bit   description
   Uint16     PWRS:2;        // 0-1   Power Mode Status bits
   Uint16     STDBYWAITS:1;  // 2     Bank/Pump Sleep to Standby Wait Counter Status bits
   Uint16     ACTIVEWAITS:1; // 3     Bank/Pump Standby to Active Wait Counter Status bits
   Uint16     rsvd1:4;       // 4-7   reserved
   Uint16     V3STAT:1;      // 8     VDD3V Status Latch bit
   Uint16     rsvd2:7;       // 9-15  reserved
};

/* Allow access to the bit fields or entire register */
union FSTATUS_REG {
   Uint16              all;
   struct FSTATUS_BITS bit;
};

/* Flash Sleep to Standby Wait Counter Register bit definitions */
struct  FSTDBYWAIT_BITS {    // bit   description
   Uint16     STDBYWAIT:9;   // 0-8   Bank/Pump Sleep to Standby Wait Count bits
   Uint16     rsvd:7;        // 9-15  reserved
};

/* Allow access to the bit fields or entire register */
union FSTDBYWAIT_REG {
   Uint16                 all;
   struct FSTDBYWAIT_BITS bit;
};

/* Flash Standby to Active Wait Counter Register bit definitions */
struct  FACTIVEWAIT_BITS {   // bit   description
   Uint16     ACTIVEWAIT:9;  // 0-8   Bank/Pump Standby to Active Wait Count bits
   Uint16     rsvd:7;        // 9-15  reserved
};

/* Allow access to the bit fields or entire register */
union FACTIVEWAIT_REG {
   Uint16                  all;
   struct FACTIVEWAIT_BITS bit;
};

/* Bank Read Access Wait State Register bit definitions */
struct  FBANKWAIT_BITS {     // bit   description
   Uint16     RANDWAIT:4;    // 0-3   Flash Random Read Wait State bits
   Uint16     rsvd1:4;       // 4-7   reserved
   Uint16     PAGEWAIT:4;    // 8-11  Flash Paged Read Wait State bits
   Uint16     rsvd2:4;       // 12-15 reserved
};

/* Allow access to the bit fields or entire register */
union FBANKWAIT_REG {
   Uint16                all;
   struct FBANKWAIT_BITS bit;
};

/* OTP Read Access Wait State Register bit definitions */
struct  FOTPWAIT_BITS {      // bit   description
   Uint16     OTPWAIT:5;     // 0-4   OTP Read Wait State bits
   Uint16     rsvd:11;       // 5-15  reserved
};

/* Allow access to the bit fields or entire register */
union FOTPWAIT_REG {
   Uint16               all;
   struct FOTPWAIT_BITS bit;
};

struct FLASH_REGS {
   union FOPT_REG        FOPT;        // Option Register
   Uint16                rsvd1;       // reserved
   union FPWR_REG        FPWR;        // Power Modes Register
   union FSTATUS_REG     FSTATUS;     // Status Register
   union FSTDBYWAIT_REG  FSTDBYWAIT;  // Pump/Bank Sleep to Standby Wait State Register
   union FACTIVEWAIT_REG FACTIVEWAIT; // Pump/Bank Standby to Active Wait State Register
   union FBANKWAIT_REG   FBANKWAIT;   // Bank Read Access Wait State Register
   union FOTPWAIT_REG    FOTPWAIT;    // OTP Read Access Wait State Register
};

//---------------------------------------------------------------------------
// System Control External References & Function Declarations:
//
extern volatile struct SYS_CTRL_REGS SysCtrlRegs;
extern volatile struct SYS_PWR_CTRL_REGS SysPwrCtrlRegs;
extern volatile struct CSM_REGS CsmRegs;
extern volatile struct CSM_PWL CsmPwl;
extern volatile struct FLASH_REGS FlashRegs;

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of DSP2802x_SYS_CTRL_H definition

//===========================================================================
// End of file.
//===========================================================================

