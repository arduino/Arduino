//###########################################################################
//
// FILE:    F2806x_DefaultIsr.h
//
// TITLE:   F2806x Devices Default Interrupt Service Routines Definitions.
//
//###########################################################################
// $TI Release: 2806x C/C++ Header Files V1.10 $
// $Release Date: April 7, 2011 $
//###########################################################################

#ifndef F2806x_DEFAULT_ISR_H
#define F2806x_DEFAULT_ISR_H

#ifdef __cplusplus
extern "C" {
#endif

//---------------------------------------------------------------------------
// Default Interrupt Service Routine Declarations:
//
// The following function prototypes are for the
// default ISR routines used with the default PIE vector table.
// This default vector table is found in the F2806x_PieVect.h
// file.
//

// Non-Peripheral Interrupts:
__interrupt void INT13_ISR(void);     // CPU-Timer 1
__interrupt void INT14_ISR(void);     // CPU-Timer 2
__interrupt void DATALOG_ISR(void);   // Datalogging interrupt
__interrupt void RTOSINT_ISR(void);   // RTOS interrupt
__interrupt void EMUINT_ISR(void);    // Emulation interrupt
__interrupt void NMI_ISR(void);       // Non-maskable interrupt
__interrupt void ILLEGAL_ISR(void);   // Illegal operation TRAP
__interrupt void USER1_ISR(void);     // User Defined trap 1
__interrupt void USER2_ISR(void);     // User Defined trap 2
__interrupt void USER3_ISR(void);     // User Defined trap 3
__interrupt void USER4_ISR(void);     // User Defined trap 4
__interrupt void USER5_ISR(void);     // User Defined trap 5
__interrupt void USER6_ISR(void);     // User Defined trap 6
__interrupt void USER7_ISR(void);     // User Defined trap 7
__interrupt void USER8_ISR(void);     // User Defined trap 8
__interrupt void USER9_ISR(void);     // User Defined trap 9
__interrupt void USER10_ISR(void);    // User Defined trap 10
__interrupt void USER11_ISR(void);    // User Defined trap 11
__interrupt void USER12_ISR(void);    // User Defined trap 12

// Group 1 PIE Interrupt Service Routines:
__interrupt void ADCINT1_ISR(void);   // ADC INT1 ISR - 1.1 OR 10.1
__interrupt void ADCINT2_ISR(void);   // ADC INT2 ISR - 1.2 OR 10.2
__interrupt void XINT1_ISR(void);     // External interrupt 1
__interrupt void XINT2_ISR(void);     // External interrupt 2
__interrupt void ADCINT9_ISR(void);   // ADC INT9
__interrupt void TINT0_ISR(void);     // Timer 0
__interrupt void WAKEINT_ISR(void);   // WD

// Group 2 PIE Interrupt Service Routines:
__interrupt void EPWM1_TZINT_ISR(void);    // EPWM Trip Zone-1
__interrupt void EPWM2_TZINT_ISR(void);    // EPWM Trip Zone-2
__interrupt void EPWM3_TZINT_ISR(void);    // EPWM Trip Zone-3
__interrupt void EPWM4_TZINT_ISR(void);    // EPWM Trip Zone-4
__interrupt void EPWM5_TZINT_ISR(void);    // EPWM Trip Zone-5
__interrupt void EPWM6_TZINT_ISR(void);    // EPWM Trip Zone-6
__interrupt void EPWM7_TZINT_ISR(void);    // EPWM Trip Zone-7
__interrupt void EPWM8_TZINT_ISR(void);	 // EPWM Trip Zone-8

// Group 3 PIE Interrupt Service Routines:
__interrupt void EPWM1_INT_ISR(void);      // EPWM-1
__interrupt void EPWM2_INT_ISR(void);      // EPWM-2
__interrupt void EPWM3_INT_ISR(void);      // EPWM-3
__interrupt void EPWM4_INT_ISR(void);      // EPWM-4
__interrupt void EPWM5_INT_ISR(void);      // EPWM-5
__interrupt void EPWM6_INT_ISR(void);      // EPWM-6
__interrupt void EPWM7_INT_ISR(void);      // EPWM-7
__interrupt void EPWM8_INT_ISR(void);		 // EPWM-8

// Group 4 PIE Interrupt Service Routines:
__interrupt void ECAP1_INT_ISR(void);      // ECAP-1
__interrupt void ECAP2_INT_ISR(void);      // ECAP-2
__interrupt void ECAP3_INT_ISR(void);      // ECAP-3
__interrupt void HRCAP1_INT_ISR(void);	 // HRCAP-1
__interrupt void HRCAP2_INT_ISR(void);	 // HRCAP-2

// Group 5 PIE Interrupt Service Routines:
__interrupt void EQEP1_INT_ISR(void);      // EQEP-1
__interrupt void EQEP2_INT_ISR(void);      // EQEP-2
__interrupt void HRCAP3_INT_ISR(void);	 // HRCAP-3
__interrupt void HRCAP4_INT_ISR(void);	 // HRCAP-4
__interrupt void USB0_INT_ISR(void);		 // USB-0

// Group 6 PIE Interrupt Service Routines:
__interrupt void SPIRXINTA_ISR(void);      // SPI-A
__interrupt void SPITXINTA_ISR(void);      // SPI-A
__interrupt void SPIRXINTB_ISR(void);		 // SPI-B
__interrupt void SPITXINTB_ISR(void);	     // SPI-B
__interrupt void MRINTA_ISR(void);         // McBSP-A
__interrupt void MXINTA_ISR(void);         // McBSP-A


// Group 7 PIE Interrupt Service Routines:
__interrupt void DINTCH1_ISR(void);		 // DMA Channel 1
__interrupt void DINTCH2_ISR(void);		 // DMA Channel 2
__interrupt void DINTCH3_ISR(void);		 // DMA Channel 3
__interrupt void DINTCH4_ISR(void);		 // DMA Channel 4
__interrupt void DINTCH5_ISR(void);		 // DMA Channel 5
__interrupt void DINTCH6_ISR(void);		 // DMA Channel 6

// Group 8 PIE Interrupt Service Routines:
__interrupt void I2CINT1A_ISR(void);       // I2C-A
__interrupt void I2CINT2A_ISR(void);       // I2C-A

// Group 9 PIE Interrupt Service Routines:
__interrupt void SCIRXINTA_ISR(void);      // SCI-A
__interrupt void SCITXINTA_ISR(void);      // SCI-A
__interrupt void SCIRXINTB_ISR(void);      // SCI-B
__interrupt void SCITXINTB_ISR(void);      // SCI-B
__interrupt void ECAN0INTA_ISR(void);		 // ECAN-A
__interrupt void ECAN1INTA_ISR(void);		 // ECAN-A

// Group 10 PIE Interrupt Service Routines:
// ADC INT1 ISR - 1.1 or 10.1
// ADC INT2 ISR - 1.2 or 10.2
__interrupt void ADCINT3_ISR(void);        // ADC INT3 ISR
__interrupt void ADCINT4_ISR(void);        // ADC INT4 ISR
__interrupt void ADCINT5_ISR(void);        // ADC INT5 ISR
__interrupt void ADCINT6_ISR(void);        // ADC INT6 ISR
__interrupt void ADCINT7_ISR(void);        // ADC INT7 ISR
__interrupt void ADCINT8_ISR(void);        // ADC INT8 ISR

// Group 11 PIE Interrupt Service Routines:
__interrupt void CLA1_INT1_ISR(void);      // CLA1 INT1 ISR
__interrupt void CLA1_INT2_ISR(void);      // CLA1 INT2 ISR
__interrupt void CLA1_INT3_ISR(void);      // CLA1 INT3 ISR
__interrupt void CLA1_INT4_ISR(void);      // CLA1 INT4 ISR
__interrupt void CLA1_INT5_ISR(void);      // CLA1 INT5 ISR
__interrupt void CLA1_INT6_ISR(void);      // CLA1 INT6 ISR
__interrupt void CLA1_INT7_ISR(void);      // CLA1 INT7 ISR
__interrupt void CLA1_INT8_ISR(void);      // CLA1 INT8 ISR

// Group 12 PIE Interrupt Service Routines:
__interrupt void XINT3_ISR(void);          // External interrupt 3
__interrupt void LVF_ISR(void);            // Latched overflow flag
__interrupt void LUF_ISR(void);            // Latched underflow flag


// Catch-all for Reserved Locations For testing purposes:
__interrupt void PIE_RESERVED(void);       // Reserved for test
__interrupt void rsvd_ISR(void);           // for test
__interrupt void INT_NOTUSED_ISR(void);    // for unused interrupts

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif    // end of F2806x_DEFAULT_ISR_H definition

//===========================================================================
// End of file.
//===========================================================================
