//###########################################################################
//
// FILE:	F2806x_PieVect.c
//
// TITLE:	F2806x Devices PIE Vector Table Initialization Functions.
//
//###########################################################################
// $TI Release: 2806x C/C++ Header Files V1.10 $
// $Release Date: April 7, 2011 $
//###########################################################################

#include "F2806x_Device.h"     // F2806x Headerfile Include File
#include "F2806x_Examples.h"   // F2806x Examples Include File

const struct PIE_VECT_TABLE PieVectTableInit = {

      PIE_RESERVED,  // 1  Reserved space
      PIE_RESERVED,  // 2  Reserved space
      PIE_RESERVED,  // 3  Reserved space
      PIE_RESERVED,  // 4  Reserved space
      PIE_RESERVED,  // 5  Reserved space
      PIE_RESERVED,  // 6  Reserved space
      PIE_RESERVED,  // 7  Reserved space
      PIE_RESERVED,  // 8  Reserved space
      PIE_RESERVED,  // 9  Reserved space
      PIE_RESERVED,  // 10 Reserved space
      PIE_RESERVED,  // 11 Reserved space
      PIE_RESERVED,  // 12 Reserved space
      PIE_RESERVED,  // 13 Reserved space

// Non-Peripheral Interrupts
      INT13_ISR,     // CPU-Timer 1
      INT14_ISR,     // CPU-Timer 2
      DATALOG_ISR,   // Datalogging interrupt
      RTOSINT_ISR,   // RTOS interrupt
      EMUINT_ISR,    // Emulation interrupt
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

// Group 1 PIE Vectors
      ADCINT1_ISR,     // 1.1 ADC  ADC - make rsvd1_1 if ADCINT1 is wanted in Group 10 instead.
      ADCINT2_ISR,     // 1.2 ADC  ADC - make rsvd1_2 if ADCINT2 is wanted in Group 10 instead.
      rsvd_ISR,        // 1.3
      XINT1_ISR,       // 1.4 External Interrupt
      XINT2_ISR,       // 1.5 External Interrupt
      ADCINT9_ISR,     // 1.6 ADC Interrupt 9
      TINT0_ISR,       // 1.7 Timer 0
      WAKEINT_ISR,     // 1.8 WD, Low Power

// Group 2 PIE Vectors
      EPWM1_TZINT_ISR, // 2.1 EPWM-1 Trip Zone
      EPWM2_TZINT_ISR, // 2.2 EPWM-2 Trip Zone
      EPWM3_TZINT_ISR, // 2.3 EPWM-3 Trip Zone
      EPWM4_TZINT_ISR, // 2.4 EPWM-4 Trip Zone
      EPWM5_TZINT_ISR, // 2.5 EPWM-5 Trip Zone
      EPWM6_TZINT_ISR, // 2.6 EPWM-6 Trip Zone
      EPWM7_TZINT_ISR, // 2.7 EPWM-7 Trip Zone
      EPWM8_TZINT_ISR, // 2.8 EPWM-8 Trip Zone

// Group 3 PIE Vectors
      EPWM1_INT_ISR,   // 3.1 EPWM-1 Interrupt
      EPWM2_INT_ISR,   // 3.2 EPWM-2 Interrupt
      EPWM3_INT_ISR,   // 3.3 EPWM-3 Interrupt
      EPWM4_INT_ISR,   // 3.4 EPWM-4 Interrupt
      EPWM5_INT_ISR,   // 3.5 EPWM-5 Interrupt
      EPWM6_INT_ISR,   // 3.6 EPWM-6 Interrupt
      EPWM7_INT_ISR,   // 3.7 EPWM-7 Interrupt
      EPWM8_INT_ISR,   // 3.8 EPWM-8 Interrupt

// Group 4 PIE Vectors
      ECAP1_INT_ISR,   // 4.1 ECAP-1
      ECAP2_INT_ISR,   // 4.2 ECAP-2
      ECAP3_INT_ISR,   // 4.3 ECAP-3
      rsvd_ISR,   	   // 4.4
      rsvd_ISR,        // 4.5
      rsvd_ISR,        // 4.6
      HRCAP1_INT_ISR,  // 4.7 HRCAP-1
      HRCAP2_INT_ISR,  // 4.8 HRCAP-2

// Group 5 PIE Vectors

      EQEP1_INT_ISR,   // 5.1 EQEP-1
      EQEP2_INT_ISR,   // 5.2 EQEP-2
      rsvd_ISR,   	   // 5.3
      HRCAP3_INT_ISR,  // 5.4 HRCAP-3
      HRCAP4_INT_ISR,  // 5.5 HRCAP-4
      rsvd_ISR,        // 5.6
      rsvd_ISR,        // 5.7
      USB0_INT_ISR,    // 5.8 USB-0

// Group 6 PIE Vectors
      SPIRXINTA_ISR,   // 6.1 SPI-A
      SPITXINTA_ISR,   // 6.2 SPI-A
      SPIRXINTB_ISR,   // 6.3 SPI-B
      SPITXINTA_ISR,   // 6.4 SPI-B
      MRINTA_ISR,      // 6.5 McBSP-A
      MXINTA_ISR,      // 6.6 McBSP-A
      rsvd_ISR,        // 6.7
      rsvd_ISR,        // 6.8

// Group 7 PIE Vectors
      DINTCH1_ISR,     // 7.1 DMA Channel 1
      DINTCH2_ISR,     // 7.2 DMA Channel 2
      DINTCH3_ISR,     // 7.3 DMA Channel 3
      DINTCH4_ISR,     // 7.4 DMA Channel 4
      DINTCH5_ISR,     // 7.5 DMA Channel 5
      DINTCH6_ISR,     // 7.6 DMA Channel 6
      rsvd_ISR,        // 7.7
      rsvd_ISR,        // 7.8

// Group 8 PIE Vectors
      I2CINT1A_ISR,    // 8.1 I2C-A
      I2CINT2A_ISR,    // 8.2 I2C-A
      rsvd_ISR,        // 8.3
      rsvd_ISR,        // 8.4
      rsvd_ISR,        // 8.5
      rsvd_ISR,        // 8.6
      rsvd_ISR,        // 8.7
      rsvd_ISR,        // 8.8

// Group 9 PIE Vectors
      SCIRXINTA_ISR,   // 9.1 SCI-A
      SCITXINTA_ISR,   // 9.2 SCI-A
      SCIRXINTB_ISR,   // 9.3 SCI-B
      SCITXINTB_ISR,   // 9.4 SCI-B
      ECAN0INTA_ISR,   // 9.5 ECAN-A
      ECAN1INTA_ISR,   // 9.6 ECAN-A
      rsvd_ISR,        // 9.7
      rsvd_ISR,        // 9.8

// Group 10 PIE Vectors
      rsvd_ISR,        // 10.1 Can be ADCINT1, but must make ADCINT1 in Group 1 space "reserved".
      rsvd_ISR,        // 10.2 Can be ADCINT2, but must make ADCINT2 in Group 1 space "reserved".
      ADCINT3_ISR,     // 10.3 ADC
      ADCINT4_ISR,     // 10.4 ADC
      ADCINT5_ISR,     // 10.5 ADC
      ADCINT6_ISR,     // 10.6 ADC
      ADCINT7_ISR,     // 10.7 ADC
      ADCINT8_ISR,     // 10.8 ADC

// Group 11 PIE Vectors
      CLA1_INT1_ISR,   // 11.1 CLA1
	  CLA1_INT2_ISR,   // 11.2 CLA1
	  CLA1_INT3_ISR,   // 11.3 CLA1
	  CLA1_INT4_ISR,   // 11.4 CLA1
	  CLA1_INT5_ISR,   // 11.5 CLA1
	  CLA1_INT6_ISR,   // 11.6 CLA1
	  CLA1_INT7_ISR,   // 11.7 CLA1
      CLA1_INT8_ISR,   // 11.8 CLA1

// Group 12 PIE Vectors
      XINT3_ISR,       // 12.1 External Interrupt
      rsvd_ISR,        // 12.2
      rsvd_ISR,        // 12.3
      rsvd_ISR,        // 12.4
      rsvd_ISR,        // 12.5
      rsvd_ISR,        // 12.6
      LVF_ISR,         // 12.7 Latched Overflow
      LUF_ISR          // 12.8 Latched Underflow
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
// End of file.
//===========================================================================
