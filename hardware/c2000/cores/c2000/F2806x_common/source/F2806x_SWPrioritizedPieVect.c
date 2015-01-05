//###########################################################################
//
// FILE:   F2806x_SWPiroritizedPieVect.c
//
// TITLE:  F2806x Devices SW Prioritized PIE Vector Table Initialization.
//
//###########################################################################
//
// Original Source by A.T.
//
// $TI Release: 2806x C/C++ Header Files V1.10 $
// $Release Date: April 7, 2011 $
//###########################################################################

#include "F2806x_Device.h"     // F2806x Headerfile Include File
#include "F2806x_Examples.h"   // F2806x Examples Include File
#include "F2806x_common/include/F2806x_SWPrioritizedIsrLevels.h"

const struct PIE_VECT_TABLE PieVectTableInit = {

      PIE_RESERVED,       // Reserved space
      PIE_RESERVED,       // reserved
      PIE_RESERVED,       // reserved
      PIE_RESERVED,       // reserved
      PIE_RESERVED,       // reserved
      PIE_RESERVED,       // reserved
      PIE_RESERVED,       // reserved
      PIE_RESERVED,       // reserved
      PIE_RESERVED,       // reserved
      PIE_RESERVED,       // reserved
      PIE_RESERVED,       // reserved
      PIE_RESERVED,       // reserved
      PIE_RESERVED,       // reserved

// Non-Peripheral Interrupts:
      #if (INT13PL != 0)
      INT13_ISR,    // CPU-Timer1
      #else
      INT_NOTUSED_ISR,
      #endif

      #if (INT14PL != 0)
      INT14_ISR,     // CPU-Timer2
      #else
      INT_NOTUSED_ISR,
      #endif

      #if (INT15PL != 0)
      DATALOG_ISR,   // Datalogging interrupt
      #else
      INT_NOTUSED_ISR,
      #endif

      #if (INT16PL != 0)
      RTOSINT_ISR,   // RTOS interrupt
      #else
      INT_NOTUSED_ISR,
      #endif

      rsvd_ISR,      // reserved interrupt
      NMI_ISR,       // Non-maskable interrupt
      ILLEGAL_ISR,   // Illegal operation TRAP
      USER1_ISR,     // User Defined trap 1
      USER2_ISR,     // User Defined trap 2
      USER3_ISR,     // User Defined trap 3
      USER4_ISR,     // User Defined trap 4
      USER5_ISR,     // User Defined trap 5
      USER6_ISR,     // User Defined trap 6
      USER7_ISR,     // User Defined trap 7
      USER8_ISR,     // User Defined trap 8
      USER9_ISR,     // User Defined trap 9
      USER10_ISR,    // User Defined trap 10
      USER11_ISR,    // User Defined trap 11
      USER12_ISR,    // User Defined trap 12

// Group 1 PIE Vectors:
      #if (G11PL != 0)
      ADCINT1_ISR,   // ADC	or change to rsvd_ISR if 10.1 is ADCINT1
      #else
      INT_NOTUSED_ISR,
      #endif

      #if (G12PL != 0)
      ADCINT2_ISR,   // ADC	or change to rsvd_ISR if 10.2 is ADCINT2
      #else
      INT_NOTUSED_ISR,
      #endif

      rsvd_ISR,

      #if (G14PL != 0)
      XINT1_ISR,     // External
      #else
      INT_NOTUSED_ISR,
      #endif

      #if (G15PL != 0)
      XINT2_ISR,     // External
      #else
      INT_NOTUSED_ISR,
      #endif

      #if (G16PL != 0)
	  ADCINT9_ISR,     // ADC 9
	  #else
	  INT_NOTUSED_ISR,
      #endif

      #if (G17PL != 0)
      TINT0_ISR,     // Timer 0
      #else
      INT_NOTUSED_ISR,
      #endif

      #if (G18PL != 0)
      WAKEINT_ISR,   // WD & Low Power
      #else
      INT_NOTUSED_ISR,
      #endif

// Group 2 PIE Vectors:
      #if (G21PL != 0)
      EPWM1_TZINT_ISR,   // ePWM1 Trip Zone
      #else
      INT_NOTUSED_ISR,
      #endif

      #if (G22PL != 0)
      EPWM2_TZINT_ISR,   // ePWM2 Trip Zone
      #else
      INT_NOTUSED_ISR,
      #endif

      #if (G23PL != 0)
      EPWM3_TZINT_ISR,   // ePWM3 Trip Zone
      #else
      INT_NOTUSED_ISR,
      #endif

      #if (G24PL != 0)
      EPWM4_TZINT_ISR,   // ePWM4 Trip Zone
      #else
      INT_NOTUSED_ISR,
      #endif

      #if (G25PL != 0)
      EPWM5_TZINT_ISR,   // ePWM5 Trip Zone
      #else
      INT_NOTUSED_ISR,
      #endif

      #if (G26PL != 0)
      EPWM6_TZINT_ISR,   // ePWM6 Trip Zone
      #else
      INT_NOTUSED_ISR,
      #endif

      #if (G27PL != 0)
      EPWM7_TZINT_ISR,   // ePWM7 Trip Zone
      #else
      INT_NOTUSED_ISR,
      #endif

      #if (G28PL != 0)
	  EPWM8_TZINT_ISR,   // ePWM8 Trip Zone
	  #else
	  INT_NOTUSED_ISR,
      #endif

// Group 3 PIE Vectors:
      #if (G31PL != 0)
      EPWM1_INT_ISR,     // ePWM1 Interrupt
      #else
      INT_NOTUSED_ISR,
      #endif

      #if (G32PL != 0)
      EPWM2_INT_ISR,     // ePWM2 Interrupt
      #else
      INT_NOTUSED_ISR,
      #endif

      #if (G33PL != 0)
      EPWM3_INT_ISR,     // ePWM3 Interrupt
      #else
      INT_NOTUSED_ISR,
      #endif

      #if (G34PL != 0)
      EPWM4_INT_ISR,     // ePWM4 Interrupt
      #else
      INT_NOTUSED_ISR,
      #endif

      #if (G35PL != 0)
      EPWM5_INT_ISR,     // ePWM5 Interrupt
      #else
      INT_NOTUSED_ISR,
      #endif

      #if (G36PL != 0)
      EPWM6_INT_ISR,     // ePWM6 Interrupt
      #else
      INT_NOTUSED_ISR,
      #endif

      #if (G37PL != 0)
      EPWM7_INT_ISR,     // ePWM7 Interrupt
      #else
      INT_NOTUSED_ISR,
      #endif

      #if (G38PL != 0)
	  EPWM8_INT_ISR,     // ePWM8 Interrupt
	  #else
	  INT_NOTUSED_ISR,
      #endif

// Group 4 PIE Vectors:
      #if (G41PL != 0)
      ECAP1_INT_ISR,     // eCAP1 Interrupt
      #else
      INT_NOTUSED_ISR,
      #endif

      #if (G42PL != 0)
	  ECAP2_INT_ISR,     // eCAP2 Interrupt
	  #else
	  INT_NOTUSED_ISR,
      #endif

      #if (G43PL != 0)
	  ECAP3_INT_ISR,     // eCAP3 Interrupt
	  #else
	  INT_NOTUSED_ISR,
      #endif

      rsvd_ISR,
      rsvd_ISR,
      rsvd_ISR,

      #if (G47PL != 0)
	  HRCAP1_INT_ISR,     // HRCAP1 Interrupt
	  #else
	  INT_NOTUSED_ISR,
      #endif

      #if (G48PL != 0)
	  HRCAP2_INT_ISR,     // HRCAP2 Interrupt
	  #else
	  INT_NOTUSED_ISR,
      #endif

// Group 5 PIE Vectors:

      #if (G51PL != 0)
      EQEP1_INT_ISR,     // eQEP1 Interrupt
      #else
      INT_NOTUSED_ISR,
      #endif

      #if (G52PL != 0)
	  EQEP2_INT_ISR,     // eQEP2 Interrupt
	  #else
	  INT_NOTUSED_ISR,
      #endif

      rsvd_ISR,

      #if (G54PL != 0)
	  HRCAP3_INT_ISR,     // HRCAP3 Interrupt
	  #else
	  INT_NOTUSED_ISR,
      #endif

      #if (G55PL != 0)
	  HRCAP4_INT_ISR,     // HRCAP4 Interrupt
	  #else
	  INT_NOTUSED_ISR,
      #endif

      rsvd_ISR,
      rsvd_ISR,

      #if (G58PL != 0)
	  USB0_INT_ISR,     // USB0 Interrupt
	  #else
	  INT_NOTUSED_ISR,
      #endif

// Group 6 PIE Vectors:
      #if (G61PL != 0)
      SPIRXINTA_ISR,  // SPI-A
      #else
      INT_NOTUSED_ISR,
      #endif

      #if (G62PL != 0)
      SPITXINTA_ISR,  // SPI-A
      #else
      INT_NOTUSED_ISR,
      #endif

      #if (G63PL != 0)
	  SPIRXINTB_ISR,  // SPI-B
	  #else
	  INT_NOTUSED_ISR,
	  #endif

	  #if (G64PL != 0)
	  SPITXINTB_ISR,  // SPI-B
	  #else
	  INT_NOTUSED_ISR,
      #endif

      #if (G65PL != 0)
      MRINTA_ISR,    // McBSP-A
      #else
      INT_NOTUSED_ISR,
      #endif

      #if (G66PL != 0)
      MXINTA_ISR,  // McBSP-A
      #else
      INT_NOTUSED_ISR,
      #endif

      rsvd_ISR,
      rsvd_ISR,

// Group 7 PIE Vectors:
      #if (G71PL != 0)
      DINTCH1_ISR,	// DMA Channel 1
      #else
      INT_NOTUSED_ISR,
      #endif

      #if (G72PL != 0)
	  DINTCH2_ISR,	// DMA Channel 2
	  #else
	  INT_NOTUSED_ISR,
      #endif

      #if (G73PL != 0)
	  DINTCH3_ISR,	// DMA Channel 3
	  #else
	  INT_NOTUSED_ISR,
      #endif

      #if (G74PL != 0)
	  DINTCH4_ISR,	// DMA Channel 4
	  #else
	  INT_NOTUSED_ISR,
      #endif

      #if (G75PL != 0)
	  DINTCH5_ISR,	// DMA Channel 5
	  #else
	  INT_NOTUSED_ISR,
      #endif

      #if (G76PL != 0)
	  DINTCH6_ISR,	// DMA Channel 6
	  #else
	  INT_NOTUSED_ISR,
      #endif

      rsvd_ISR,
      rsvd_ISR,


// Group 8 PIE Vectors:
      #if (G81PL != 0)
      I2CINT1A_ISR,    // I2C-A
      #else
      INT_NOTUSED_ISR,
      #endif

      #if (G82PL != 0)
      I2CINT2A_ISR,    // I2C-A
      #else
      INT_NOTUSED_ISR,
      #endif

      rsvd_ISR,
      rsvd_ISR,
      rsvd_ISR,
      rsvd_ISR,
      rsvd_ISR,
      rsvd_ISR,

// Group 9 PIE Vectors:
      #if (G91PL != 0)
      SCIRXINTA_ISR,    // SCI-A
      #else
      INT_NOTUSED_ISR,
      #endif

      #if (G92PL != 0)
      SCITXINTA_ISR,    // SCI-A
      #else
      INT_NOTUSED_ISR,
      #endif

	  #if (G93PL != 0)
	  SCIRXINTB_ISR,    // SCI-B
	  #else
	  INT_NOTUSED_ISR,
      #endif

      #if (G94PL != 0)
	  SCITXINTB_ISR,    // SCI-B
	  #else
	  INT_NOTUSED_ISR,
      #endif

      #if (G95PL != 0)
	  ECAN0INTA_ISR,    // eCAN-A
	  #else
	  INT_NOTUSED_ISR,
      #endif

      #if (G96PL != 0)
	  ECAN1INTA_ISR,    // eCAN-A
	  #else
	  INT_NOTUSED_ISR,
      #endif

      rsvd_ISR,
      rsvd_ISR,

// Group 10 PIE Vectors
     rsvd_ISR,	      // or change to ADCINT1_ISR if ADCINT1 is 10.1 in G101PL
     rsvd_ISR,		  // or change to ADCINT2_ISR if ADCINT2 is 10.2 in G102PL

     #if (G103PL != 0)
     ADCINT3_ISR,     // ADC
     #else
     INT_NOTUSED_ISR,
     #endif

     #if (G104PL != 0)
     ADCINT4_ISR,     // ADC
     #else
     INT_NOTUSED_ISR,
     #endif

     #if (G105PL != 0)
     ADCINT5_ISR,     // ADC
     #else
     INT_NOTUSED_ISR,
     #endif

     #if (G106PL != 0)
     ADCINT6_ISR,     // ADC
     #else
     INT_NOTUSED_ISR,
     #endif

     #if (G107PL != 0)
     ADCINT7_ISR,     // ADC
     #else
     INT_NOTUSED_ISR,
     #endif

     #if (G108PL != 0)
     ADCINT8_ISR,     // ADC
     #else
     INT_NOTUSED_ISR,
     #endif


// Group 11 PIE Vectors

     #if (G111PL != 0)
     CLA1_INT1_ISR,     // CLA1
     #else
     INT_NOTUSED_ISR,
     #endif

     #if (G112PL != 0)
     CLA1_INT2_ISR,     // CLA1
     #else
     INT_NOTUSED_ISR,
     #endif

     #if (G113PL != 0)
     CLA1_INT3_ISR,     // CLA1
     #else
     INT_NOTUSED_ISR,
     #endif

     #if (G114PL != 0)
     CLA1_INT4_ISR,     // CLA1
     #else
     INT_NOTUSED_ISR,
     #endif

     #if (G115PL != 0)
     CLA1_INT1_ISR,     // CLA1
     #else
     INT_NOTUSED_ISR,
     #endif

     #if (G116PL != 0)
     CLA1_INT2_ISR,     // CLA1
     #else
     INT_NOTUSED_ISR,
     #endif

     #if (G117PL != 0)
     CLA1_INT3_ISR,     // CLA1
     #else
     INT_NOTUSED_ISR,
     #endif

     #if (G118PL != 0)
     CLA1_INT4_ISR,     // CLA1
     #else
     INT_NOTUSED_ISR,
     #endif

// Group 12 PIE Vectors
     #if (G121PL != 0)
     XINT3_ISR,    		// External interrupt
     #else
     INT_NOTUSED_ISR,
     #endif

     rsvd_ISR,
     rsvd_ISR,
     rsvd_ISR,
     rsvd_ISR,
     rsvd_ISR,

     #if (G127PL != 0)
     LVF_ISR,     // Latched Overflow
     #else
     INT_NOTUSED_ISR,
     #endif

     #if (G128PL != 0)
     LUF_ISR,     // Latched Underflow
     #else
     INT_NOTUSED_ISR,
     #endif

};

//---------------------------------------------------------------------------
// InitPieVectTable:
//---------------------------------------------------------------------------
// This function initializes the PIE vector table to a known state.
// This function must be executed after boot time.
//

void InitPieVectTable(void)
{
	int16	i;
	Uint32 *Source = (void *) &PieVectTableInit;
	Uint32 *Dest = (void *) &PieVectTable;

	// Do not write over first 3 32-bit locations (these locations are
	// initialized by Boot ROM with boot variables)

	Source = Source + 3;
	Dest = Dest + 3;

	EALLOW;
	for(i=0; i < 125; i++)
		*Dest++ = *Source++;
	EDIS;

	// Enable the PIE Vector Table
	PieCtrlRegs.PIECTRL.bit.ENPIE = 1;

}

//===========================================================================
// No more.
//===========================================================================
