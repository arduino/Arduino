// TI File $Revision: /main/7 $
// Checkin $Date: December 21, 2010   13:59:37 $
//###########################################################################
//
// FILE:   F2802x_EPWM.h
//
// TITLE:  F2802x Enhanced PWM Module Register Bit Definitions.
//
//###########################################################################
// $TI Release: 2802x C/C++ Header Files and Peripheral Examples V1.29 $
// $Release Date: January 11, 2011 $
//###########################################################################

#ifndef F2802x_EPWM_H
#define F2802x_EPWM_H


#ifdef __cplusplus
extern "C" {
#endif

//----------------------------------------------------
// Time base control register bit definitions */
struct TBCTL_BITS {          // bits   description
   uint16_t CTRMODE:2;         // 1:0    Counter Mode
   uint16_t PHSEN:1;           // 2      Phase load enable
   uint16_t PRDLD:1;           // 3      Active period load
   uint16_t SYNCOSEL:2;        // 5:4    Sync output select
   uint16_t SWFSYNC:1;         // 6      Software force sync pulse
   uint16_t HSPCLKDIV:3;       // 9:7    High speed time pre-scale
   uint16_t CLKDIV:3;          // 12:10  Timebase clock pre-scale
   uint16_t PHSDIR:1;          // 13     Phase Direction
   uint16_t FREE_SOFT:2;       // 15:14  Emulation mode
};

union TBCTL_REG {
   uint16_t              all;
   struct TBCTL_BITS   bit;
};

//----------------------------------------------------
// Time base status register bit definitions */
struct TBSTS_BITS {          // bits   description
   uint16_t CTRDIR:1;          // 0      Counter direction status
   uint16_t SYNCI:1;           // 1      External input sync status
   uint16_t CTRMAX:1;          // 2      Counter max latched status
   uint16_t rsvd1:13;          // 15:3   reserved
};

union TBSTS_REG {
   uint16_t              all;
   struct TBSTS_BITS   bit;
};

//----------------------------------------------------
// Compare control register bit definitions */
struct CMPCTL_BITS {          // bits   description
   uint16_t LOADAMODE:2;        // 0:1    Active compare A
   uint16_t LOADBMODE:2;        // 3:2    Active compare B
   uint16_t SHDWAMODE:1;        // 4      Compare A block operating mode
   uint16_t rsvd1:1;            // 5      reserved
   uint16_t SHDWBMODE:1;        // 6      Compare B block operating mode
   uint16_t rsvd2:1;            // 7      reserved
   uint16_t SHDWAFULL:1;        // 8      Compare A Shadow registers full Status
   uint16_t SHDWBFULL:1;        // 9      Compare B Shadow registers full Status
   uint16_t rsvd3:6;            // 15:10  reserved
};


union CMPCTL_REG {
   uint16_t                all;
   struct CMPCTL_BITS    bit;
};

//----------------------------------------------------
// Action qualifier register bit definitions */
struct AQCTL_BITS {           // bits   description
   uint16_t ZRO:2;              // 1:0    Action Counter = Zero
   uint16_t PRD:2;              // 3:2    Action Counter = Period
   uint16_t CAU:2;              // 5:4    Action Counter = Compare A up
   uint16_t CAD:2;              // 7:6    Action Counter = Compare A down
   uint16_t CBU:2;              // 9:8    Action Counter = Compare B up
   uint16_t CBD:2;              // 11:10  Action Counter = Compare B down
   uint16_t rsvd:4;             // 15:12  reserved
};

union AQCTL_REG {
   uint16_t                all;
   struct AQCTL_BITS     bit;
};

//----------------------------------------------------
// Action qualifier SW force register bit definitions */
struct AQSFRC_BITS {           // bits   description
   uint16_t ACTSFA:2;            // 1:0    Action when One-time SW Force A invoked
   uint16_t OTSFA:1;             // 2      One-time SW Force A output
   uint16_t ACTSFB:2;            // 4:3    Action when One-time SW Force B invoked
   uint16_t OTSFB:1;             // 5      One-time SW Force A output
   uint16_t RLDCSF:2;            // 7:6    Reload from Shadow options
   uint16_t rsvd1:8;             // 15:8   reserved
};

union AQSFRC_REG {
   uint16_t                 all;
   struct AQSFRC_BITS     bit;
};

//----------------------------------------------------
// Action qualifier continuous SW force register bit definitions */
struct AQCSFRC_BITS {          // bits   description
   uint16_t CSFA:2;              // 1:0    Continuous Software Force on output A
   uint16_t CSFB:2;              // 3:2    Continuous Software Force on output B
   uint16_t rsvd1:12;            // 15:4   reserved
};

union AQCSFRC_REG {
   uint16_t                  all;
   struct AQCSFRC_BITS     bit;
};


//----------------------------------------------------
// Dead-band generator control register bit definitions
struct DBCTL_BITS {          // bits   description
   uint16_t OUT_MODE:2;           // 1:0    Dead Band Output Mode Control
   uint16_t POLSEL:2;          // 3:2    Polarity Select Control
   uint16_t IN_MODE:2;         // 5:4    Dead Band Input Select Mode Control
   uint16_t rsvd1:9;           // 14:4   reserved
   uint16_t HALFCYCLE:1;       // 15     Half Cycle Clocking Enable
};

union DBCTL_REG {
   uint16_t                  all;
   struct DBCTL_BITS       bit;
};


//----------------------------------------------------
// Trip zone select register bit definitions
struct TZSEL_BITS {           // bits   description
   uint16_t  CBC1:1;            // 0      TZ1 CBC select
   uint16_t  CBC2:1;            // 1      TZ2 CBC select
   uint16_t  CBC3:1;            // 2      TZ3 CBC select
   uint16_t  CBC4:1;            // 3      TZ4 CBC select
   uint16_t  CBC5:1;            // 4      TZ5 CBC select
   uint16_t  CBC6:1;            // 5      TZ6 CBC select
   uint16_t  DCAEVT2:1;         // 6      DCAEVT2
   uint16_t  DCBEVT2:1;         // 7      DCBEVT2
   uint16_t  OSHT1:1;           // 8      One-shot TZ1 select
   uint16_t  OSHT2:1;           // 9      One-shot TZ2 select
   uint16_t  OSHT3:1;           // 10     One-shot TZ3 select
   uint16_t  OSHT4:1;           // 11     One-shot TZ4 select
   uint16_t  OSHT5:1;           // 12     One-shot TZ5 select
   uint16_t  OSHT6:1;           // 13     One-shot TZ6 select
   uint16_t  DCAEVT1:1;         // 14     DCAEVT1
   uint16_t  DCBEVT1:1;         // 15     DCBEVT1
};

union TZSEL_REG {
   uint16_t                  all;
   struct TZSEL_BITS       bit;
};


//----------------------------------------------------
// Trip zone digital compare event select register
struct TZDCSEL_BITS {        // bits   description
   uint16_t  DCAEVT1:3;        // 2:0    Digital Compare Output A Event 1
   uint16_t  DCAEVT2:3;        // 5:3    Digital Compare Output A Event 2
   uint16_t  DCBEVT1:3;        // 8:6    Digital Compare Output B Event 1
   uint16_t  DCBEVT2:3;        // 11:9   Digital Compare Output B Event 2
   uint16_t  rsvd1:4;          // 15:12  reserved
};

union TZDCSEL_REG {
   uint16_t                  all;
   struct TZDCSEL_BITS     bit;
};

//----------------------------------------------------
// Trip zone control register bit definitions */
struct TZCTL_BITS {         // bits   description
   uint16_t TZA:2;            // 1:0    TZ1 to TZ6 Trip Action On EPWMxA
   uint16_t TZB:2;            // 3:2    TZ1 to TZ6 Trip Action On EPWMxB
   uint16_t DCAEVT1:2;        // 5:4    EPWMxA action on DCAEVT1
   uint16_t DCAEVT2:2;        // 7:6    EPWMxA action on DCAEVT2
   uint16_t DCBEVT1:2;        // 9:8    EPWMxB action on DCBEVT1
   uint16_t DCBEVT2:2;        // 11:10  EPWMxB action on DCBEVT2
   uint16_t rsvd:4;           // 15:12  reserved
};

union TZCTL_REG {
   uint16_t                  all;
   struct TZCTL_BITS       bit;
};


//----------------------------------------------------
// Trip zone control register bit definitions */
struct TZEINT_BITS {         // bits   description
   uint16_t  rsvd1:1;          // 0      reserved
   uint16_t  CBC:1;            // 1      Trip Zones Cycle By Cycle Int Enable
   uint16_t  OST:1;            // 2      Trip Zones One Shot Int Enable
   uint16_t  DCAEVT1:1;        // 3      Force DCAEVT1 event
   uint16_t  DCAEVT2:1;        // 4      Force DCAEVT2 event
   uint16_t  DCBEVT1:1;        // 5      Force DCBEVT1 event
   uint16_t  DCBEVT2:1;        // 6      Force DCBEVT2 event
   uint16_t  rsvd2:9;          // 15:7   reserved
};


union TZEINT_REG {
   uint16_t                  all;
   struct TZEINT_BITS      bit;
};


//----------------------------------------------------
// Trip zone flag register bit definitions */
struct TZFLG_BITS {         // bits   description
   uint16_t  INT:1;           // 0      Global status
   uint16_t  CBC:1;           // 1      Trip Zones Cycle By Cycle Int
   uint16_t  OST:1;           // 2      Trip Zones One Shot Int
   uint16_t  DCAEVT1:1;       // 3      Force DCAEVT1 event
   uint16_t  DCAEVT2:1;       // 4      Force DCAEVT2 event
   uint16_t  DCBEVT1:1;       // 5      Force DCBEVT1 event
   uint16_t  DCBEVT2:1;       // 6      Force DCBEVT2 event
   uint16_t  rsvd2:9;         // 15:7   reserved
};

union TZFLG_REG {
   uint16_t                  all;
   struct TZFLG_BITS       bit;
};

//----------------------------------------------------
// Trip zone flag clear register bit definitions */
struct TZCLR_BITS {         // bits   description
   uint16_t  INT:1;           // 0      Global status
   uint16_t  CBC:1;           // 1      Trip Zones Cycle By Cycle Int
   uint16_t  OST:1;           // 2      Trip Zones One Shot Int
   uint16_t  DCAEVT1:1;       // 3      Force DCAEVT1 event
   uint16_t  DCAEVT2:1;       // 4      Force DCAEVT2 event
   uint16_t  DCBEVT1:1;       // 5      Force DCBEVT1 event
   uint16_t  DCBEVT2:1;       // 6      Force DCBEVT2 event
   uint16_t  rsvd2:9;         // 15:7   reserved
};

union TZCLR_REG {
   uint16_t                  all;
   struct TZCLR_BITS       bit;
};

//----------------------------------------------------
// Trip zone flag force register bit definitions */
struct TZFRC_BITS {         // bits   description
   uint16_t  rsvd1:1;         // 0      reserved
   uint16_t  CBC:1;           // 1      Trip Zones Cycle By Cycle Int
   uint16_t  OST:1;           // 2      Trip Zones One Shot Int
   uint16_t  DCAEVT1:1;       // 3      Force DCAEVT1 event
   uint16_t  DCAEVT2:1;       // 4      Force DCAEVT2 event
   uint16_t  DCBEVT1:1;       // 5      Force DCBEVT1 event
   uint16_t  DCBEVT2:1;       // 6      Force DCBEVT2 event
   uint16_t  rsvd2:9;        // 15:7   reserved
};

union TZFRC_REG {
   uint16_t                  all;
   struct TZFRC_BITS       bit;
};

//----------------------------------------------------
// Event trigger select register bit definitions */
struct ETSEL_BITS {         // bits   description
   uint16_t  INTSEL:3;        // 2:0    EPWMxINTn Select
   uint16_t  INTEN:1;         // 3      EPWMxINTn Enable
   uint16_t  rsvd1:4;         // 7:4    reserved
   uint16_t  SOCASEL:3;       // 10:8   Start of conversion A Select
   uint16_t  SOCAEN:1;        // 11     Start of conversion A Enable
   uint16_t  SOCBSEL:3;       // 14:12  Start of conversion B Select
   uint16_t  SOCBEN:1;        // 15     Start of conversion B Enable
};

union ETSEL_REG {
   uint16_t                  all;
   struct ETSEL_BITS       bit;
};


//----------------------------------------------------
// Event trigger pre-scale register bit definitions */
struct ETPS_BITS {         // bits   description
   uint16_t  INTPRD:2;       // 1:0    EPWMxINTn Period Select
   uint16_t  INTCNT:2;       // 3:2    EPWMxINTn Counter Register
   uint16_t  rsvd1:4;        // 7:4    reserved
   uint16_t  SOCAPRD:2;      // 9:8    EPWMxSOCA Period Select
   uint16_t  SOCACNT:2;      // 11:10  EPWMxSOCA Counter Register
   uint16_t  SOCBPRD:2;      // 13:12  EPWMxSOCB Period Select
   uint16_t  SOCBCNT:2;      // 15:14  EPWMxSOCB Counter Register
};

union ETPS_REG {
   uint16_t                  all;
   struct ETPS_BITS        bit;
};

//----------------------------------------------------
// Event trigger Flag register bit definitions */
struct ETFLG_BITS {         // bits   description
   uint16_t  INT:1;           // 0      EPWMxINTn Flag
   uint16_t  rsvd1:1;         // 1      reserved
   uint16_t  SOCA:1;          // 2      EPWMxSOCA Flag
   uint16_t  SOCB:1;          // 3      EPWMxSOCB Flag
   uint16_t  rsvd2:12;        // 15:4      reserved
};

union ETFLG_REG {
   uint16_t                   all;
   struct ETFLG_BITS        bit;
};


//----------------------------------------------------
// Event trigger Clear register bit definitions */
struct ETCLR_BITS {         // bits   description
   uint16_t  INT:1;           // 0      EPWMxINTn Clear
   uint16_t  rsvd1:1;         // 1      reserved
   uint16_t  SOCA:1;          // 2      EPWMxSOCA Clear
   uint16_t  SOCB:1;          // 3      EPWMxSOCB Clear
   uint16_t  rsvd2:12;        // 15:4      reserved
};

union ETCLR_REG {
   uint16_t                   all;
   struct ETCLR_BITS        bit;
};

//----------------------------------------------------
// Event trigger Force register bit definitions */
struct ETFRC_BITS {         // bits   description
   uint16_t  INT:1;           // 0      EPWMxINTn Force
   uint16_t  rsvd1:1;         // 1      reserved
   uint16_t  SOCA:1;          // 2      EPWMxSOCA Force
   uint16_t  SOCB:1;          // 3      EPWMxSOCB Force
   uint16_t  rsvd2:12;        // 15:4      reserved
};

union ETFRC_REG {
   uint16_t                  all;
   struct ETFRC_BITS        bit;
};
//----------------------------------------------------
// PWM chopper control register bit definitions */
struct PCCTL_BITS {         // bits   description
   uint16_t  CHPEN:1;         // 0      PWM chopping enable
   uint16_t  OSHTWTH:4;       // 4:1    One-shot pulse width
   uint16_t  CHPFREQ:3;       // 7:5    Chopping clock frequency
   uint16_t  CHPDUTY:3;       // 10:8   Chopping clock Duty cycle
   uint16_t  rsvd1:5;         // 15:11  reserved
};


union PCCTL_REG {
   uint16_t                  all;
   struct PCCTL_BITS       bit;
};


//----------------------------------------------------
// Enhanced Trip register bit definitions */

struct DCTRIPSEL_BITS {      // bits   description
   uint16_t DCAHCOMPSEL:4;     // 3:0    Digital Compare A High, COMP Input Select
   uint16_t DCALCOMPSEL:4;     // 7:4    Digital Compare A Low, COMP Input Select
   uint16_t DCBHCOMPSEL:4;     // 11:8   Digital Compare B High, COMP Input Select
   uint16_t DCBLCOMPSEL:4;     // 15:12  Digital Compare B Low, COMP Input Select
};

union DCTRIPSEL_REG {
   uint16_t                  all;
   struct DCTRIPSEL_BITS   bit;
};

struct DCCTL_BITS {          // bits   description
   uint16_t EVT1SRCSEL:1;      // 0      DCBEVT1 Source Signal Select
   uint16_t EVT1FRCSYNCSEL:1;  // 1      DCBEVT1 Force Cynchronization Signal Select
   uint16_t EVT1SOCE:1;        // 2      DCEVT1 SOC, Enable/Disable
   uint16_t EVT1SYNCE:1;       // 3      DCEVT1 Sync, Enable/Disable
   uint16_t rsvd1:4;           // 7:4    reserved
   uint16_t EVT2SRCSEL:1;      // 8      DCEVT2 Source Signal Select
   uint16_t EVT2FRCSYNCSEL:1;  // 9      DCEVT2 Force Synchronization Signal Select
   uint16_t rsvd2:6;           // 15:10  reserved
};

union DCCTL_REG {
   uint16_t                  all;
   struct DCCTL_BITS       bit;
};

struct DCCAPCTL_BITS {       // bits   description
   uint16_t CAPE:1;            // 0      Counter Capture Enable/Disable
   uint16_t SHDWMODE:1;        // 1      Counter Capture Mode
   uint16_t rsvd:14;           // 15:2   reserved
};

union DCCAPCTL_REG {
   uint16_t                  all;
   struct DCCAPCTL_BITS    bit;
};

struct DCFCTL_BITS {         // bits   description
   uint16_t SRCSEL:2;          // 1:0    Filter Block Signal Source Select
   uint16_t BLANKE:1;          // 2      Blanking Enable/Disable
   uint16_t BLANKINV:1;        // 3      Blanking Window Inversion
   uint16_t PULSESEL:2;        // 5:4    Pulse Select for Blanking & Capture Alignment
   uint16_t rsvd:10;           // 15:6   reserved
};

union DCFCTL_REG {
   uint16_t                  all;
   struct DCFCTL_BITS      bit;
};


//----------------------------------------------------
// High resolution period control register bit definitions */

struct HRPCTL_BITS {        // bits   description
   uint16_t  HRPE:1;          // 0      High resolution period enable
   uint16_t  rsvd1:1;         // 1      reserved
   uint16_t  TBPHSHRLOADE:1;  // 2      TBPHSHR Load Enable Bit
   uint16_t  rsvd2:13;        // 15:3   reserved
};

union HRPCTL_REG {
   uint16_t                      all;
   struct HRPCTL_BITS       bit;
};

//----------------------------------------------------
// High Resolution Register bit definitions */

struct HRCNFG_BITS {           // bits   description
   uint16_t  EDGMODE:2;         // 1:0    Edge Mode select Bits
   uint16_t  CTLMODE:1;         // 2      Control mode Select Bit
   uint16_t  HRLOAD:2;          // 4:3    Shadow mode Select Bit
   uint16_t  SELOUTB:1;       // 5      EPWMB Output Select Bit
   uint16_t  AUTOCONV:1;      // 6      Autoconversion Bit
   uint16_t  SWAPAB:1;        // 7      Swap EPWMA & EPWMB Outputs Bit
   uint16_t  rsvd1:8;          // 15:8   reserved
};

union HRCNFG_REG {
   uint16_t                      all;
   struct HRCNFG_BITS       bit;
};


struct HRPWR_BITS {           // bits   description
   uint16_t  rsvd1:6;         // 5:0    reserved
   uint16_t  MEPOFF:4;         // 9:6    MEP Calibration Off Bits
   uint16_t  rsvd2:6;          // 15:10  reserved
};

union HRPWR_REG {
   uint16_t                      all;
   struct HRPWR_BITS        bit;
};

struct TBPHS_HRPWM_REG {       // bits   description
   uint16_t  TBPHSHR;         // 15:0   Extension register for HRPWM Phase (8 bits)
   uint16_t  TBPHS;           // 31:16  Phase offset register
};

union TBPHS_HRPWM_GROUP {
   uint32_t                  all;
   struct TBPHS_HRPWM_REG  half;
};

struct CMPA_HRPWM_REG {       // bits   description
   uint16_t  CMPAHR;             // 15:0   Extension register for HRPWM compare (8 bits)
   uint16_t  CMPA;            // 31:16  Compare A reg
};

union CMPA_HRPWM_GROUP {
   uint32_t                 all;
   struct CMPA_HRPWM_REG  half;
};

struct TBPRD_HRPWM_REG {       // bits   description
   uint16_t  TBPRDHR;         // 15:0   Extension register for HRPWM Period (8 bits)
   uint16_t  TBPRD;           // 31:16  Timebase Period Register
};

union TBPRD_HRPWM_GROUP {
   uint32_t                  all;
   struct TBPRD_HRPWM_REG  half;
};


struct EPWM_REGS {
   union  TBCTL_REG           TBCTL;       // Time Base Control Register
   union  TBSTS_REG           TBSTS;       // Time Base Status Register
   union  TBPHS_HRPWM_GROUP   TBPHS;       // Union of TBPHS:TBPHSHR
   uint16_t                     TBCTR;       // Time Base Counter
   uint16_t                     TBPRD;       // Time Base Period register set
   uint16_t                     TBPRDHR;     // Time Base Period High Res Register
   union  CMPCTL_REG          CMPCTL;      // Compare control
   union  CMPA_HRPWM_GROUP    CMPA;        // Union of CMPA:CMPAHR
   uint16_t                     CMPB;        // Compare B reg
   union  AQCTL_REG           AQCTLA;      // Action qual output A
   union  AQCTL_REG           AQCTLB;      // Action qual output B
   union  AQSFRC_REG          AQSFRC;      // Action qual SW force
   union  AQCSFRC_REG         AQCSFRC;     // Action qualifier continuous SW force
   union  DBCTL_REG           DBCTL;       // Dead-band control
   uint16_t                     DBRED;       // Dead-band rising edge delay
   uint16_t                     DBFED;       // Dead-band falling edge delay
   union  TZSEL_REG           TZSEL;       // Trip zone select
   union  TZDCSEL_REG         TZDCSEL;     // Trip zone digital comparator select
   union  TZCTL_REG           TZCTL;       // Trip zone control
   union  TZEINT_REG          TZEINT;      // Trip zone interrupt enable
   union  TZFLG_REG           TZFLG;       // Trip zone interrupt flags
   union  TZCLR_REG           TZCLR;       // Trip zone clear
   union  TZFRC_REG              TZFRC;       // Trip zone force interrupt
   union  ETSEL_REG           ETSEL;       // Event trigger selection
   union  ETPS_REG            ETPS;        // Event trigger pre-scaler
   union  ETFLG_REG           ETFLG;       // Event trigger flags
   union  ETCLR_REG           ETCLR;       // Event trigger clear
   union  ETFRC_REG           ETFRC;       // Event trigger force
   union  PCCTL_REG           PCCTL;       // PWM chopper control
   uint16_t                     rsvd3;
   union  HRCNFG_REG          HRCNFG;      // HRPWM Config Reg
   union  HRPWR_REG              HRPWR;       // HRPWM Power Register
   uint16_t                     rsvd4[4];
   uint16_t                     HRMSTEP;     // HRPWM MEP Step Register
   uint16_t                     rsvd5;
   union  HRPCTL_REG          HRPCTL;      // High Resolution Period Control
   uint16_t                     rsvd6;
   union  TBPRD_HRPWM_GROUP   TBPRDM;      // Union of TBPRD:TBPRDHR mirror registers
   union  CMPA_HRPWM_GROUP    CMPAM;       // Union of CMPA:CMPAHR mirror registers
   uint16_t                     rsvd7[2];
   union  DCTRIPSEL_REG       DCTRIPSEL;   // Digital Compare Trip Select
   union  DCCTL_REG           DCACTL;      // Digital Compare A Control
   union  DCCTL_REG           DCBCTL;      // Digital Compare B Control
   union  DCFCTL_REG          DCFCTL;      // Digital Compare Filter Control
   union  DCCAPCTL_REG        DCCAPCTL;    // Digital Compare Capture Control
   uint16_t                     DCFOFFSET;   // Digital Compare Filter Offset
   uint16_t                     DCFOFFSETCNT;// Digital Compare Filter Offset Counter
   uint16_t                     DCFWINDOW;   // Digital Compare Filter Window
   uint16_t                     DCFWINDOWCNT;// Digital Compare Filter Window Counter
   uint16_t                     DCCAP;       // Digital Compare Filter Counter Capture
   uint16_t                     rsvd8[6];
};



//---------------------------------------------------------------------------
// External References & Function Declarations:
//
extern volatile struct EPWM_REGS EPwm1Regs;
extern volatile struct EPWM_REGS EPwm2Regs;
extern volatile struct EPWM_REGS EPwm3Regs;
extern volatile struct EPWM_REGS EPwm4Regs;

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of DSP2802x_EPWM_H definition

//===========================================================================
// End of file.
//===========================================================================
