//###########################################################################
//
// FILE:    F2837xS_SWPrioritizedIsrLevels.h
//
// TITLE:   F28 Devices Software Prioritized Interrupt Service Routine
//          Level definitions.
//
//###########################################################################
// $TI Release: F2837xS Support Library v170 $
// $Release Date: Mon Sep 21 16:56:07 CDT 2015 $
// $Copyright: Copyright (C) 2014-2015 Texas Instruments Incorporated -
//             http://www.ti.com/ ALL RIGHTS RESERVED $
//###########################################################################

#ifndef F2837xS_SW_PRIORITZIED_ISR_H
#define F2837xS_SW_PRIORITZIED_ISR_H

#ifdef __cplusplus
extern "C" {
#endif

//-------------------------------------------------------------------------------
// Interrupt Enable Register Allocation For F2837xS Devices:
//-------------------------------------------------------------------------------
// Interrupts can be enabled/disabled using the CPU interrupt enable register
// (IER) and the PIE interrupt enable registers (PIEIER1 to PIEIER12).
//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------
// Set "Global" Interrupt Priority Level (IER register):
//-------------------------------------------------------------------------------
// The user must set the appropriate priority level for each of the CPU
// interrupts. This is termed as the "global" priority. The priority level
// must be a number between 1 (highest) to 16 (lowest). A value of 0 must
// be entered for reserved interrupts or interrupts that are not used. This
// will also reduce code size by not including ISR's that are not used.
//
// Note: The priority levels below are used to calculate the IER register
//       interrupt masks MINT1 to MINT16.
//
//
// Note: The priority levels shown here may not make sense in a
//       real application.  This is for demonstration purposes only!!!
//
//       The user should change these to values that make sense for
//       their application.
//
// 0  = not used
// 1  = highest priority
// ...
// 16 = lowest priority
#define	INT1PL      2        // Group1 Interrupts (PIEIER1)
#define	INT2PL      1        // Group2 Interrupts (PIEIER2)
#define	INT3PL      4        // Group3 Interrupts (PIEIER3)
#define	INT4PL      2        // Group4 Interrupts (PIEIER4)
#define	INT5PL      2        // Group5 Interrupts (PIEIER5)
#define	INT6PL      3        // Group6 Interrupts (PIEIER6)
#define	INT7PL      5        // Group7 Interrupts (PIEIER6)
#define	INT8PL      5        // Group8 Interrupts (PIEIER6)
#define	INT9PL      3        // Group9 Interrupts (PIEIER9)
#define	INT10PL     6        // Group10 Interrupts (PIEIER6)
#define	INT11PL     6        // Group11 Interrupts (PIEIER6)
#define	INT12PL     8        // Group12 Interrupts (PIEIER6)
#define	INT13PL     4        // XINT13
#define	INT14PL     4        // INT14 (TINT2)
#define	INT15PL     4        // DATALOG
#define	INT16PL     4        // RTOSINT

//-------------------------------------------------------------------------------
// Set "Group" Interrupt Priority Level (PIEIER1 to PIEIER12 registers):
//-------------------------------------------------------------------------------
// The user must set the appropriate priority level for each of the PIE
// interrupts. This is termed as the "group" priority. The priority level
// must be a number between 1 (highest) to 16 (lowest). A value of 0 must
// be entered for reserved interrupts or interrupts that are not used. This
// will also reduce code size by not including ISR's that are not used:
//
// Note: The priority levels below are used to calculate the following
//       PIEIER register interrupt masks:
//                           MG1_1 to MG1_16
//                           MG2_1 to MG2_16
//                           MG3_1 to MG3_16
//                           MG4_1 to MG4_16
//                           MG5_1 to MG5_16
//                           MG6_1 to MG6_16
//                           MG7_1 to MG7_16
//                           MG8_1 to MG8_16
//                           MG9_1 to MG9_16
//                           MG10_1 to MG10_16
//                           MG11_1 to MG11_16
//                           MG12_1 to MG12_16
//
// Note: The priority levels shown here may not make sense in a
//       real application.  This is for demonstration purposes only!!!
//
//       The user should change these to values that make sense for
//       their application.
//
// 0  = not used
// 1  = highest priority
// ...
// 16  = lowest priority
//
#define G1_1PL		5		// ADCA1_INT
#define G1_2PL		3		// ADCB1_INT
#define G1_3PL		1		// ADCC1_INT
#define G1_4PL		4		// XINT1_INT
#define G1_5PL		4		// XINT2_INT
#define G1_6PL		1		// ADCD1_INT
#define G1_7PL		12		// TIMER0_INT
#define G1_8PL		5		// WAKE_INT
#define G1_9PL		0   	// Reserved
#define G1_10PL		0   	// Reserved
#define G1_11PL		0   	// Reserved
#define G1_12PL		0   	// Reserved
#define G1_13PL		8		// IPC1_INT
#define G1_14PL		13		// IPC2_INT
#define G1_15PL		15		// IPC3_INT
#define G1_16PL		9		// IPC4_INT
                            
                            
#define G2_1PL		13		// EPWM1_TZ_INT
#define G2_2PL		1		// EPWM2_TZ_INT
#define G2_3PL		1		// EPWM3_TZ_INT
#define G2_4PL		9		// EPWM4_TZ_INT
#define G2_5PL      3		// EPWM5_TZ_INT
#define G2_6PL		13		// EPWM6_TZ_INT
#define G2_7PL		9		// EPWM7_TZ_INT
#define G2_8PL		13		// EPWM8_TZ_INT
#define G2_9PL		15		// EPWM9_TZ_INT
#define G2_10PL		11		// EPWM10_TZ_INT
#define G2_11PL		7		// EPWM11_TZ_INT
#define G2_12PL		10		// EPWM12_TZ_INT
#define G2_13PL		0   	// Reserved
#define G2_14PL		0   	// Reserved
#define G2_15PL		0   	// Reserved
#define G2_16PL		0   	// Reserved
                            
                            
#define G3_1PL		5		// EPWM1_INT
#define G3_2PL		9		// EPWM2_INT
#define G3_3PL		5		// EPWM3_INT
#define G3_4PL		2		// EPWM4_INT
#define G3_5PL		12		// EPWM5_INT
#define G3_6PL		4		// EPWM6_INT
#define G3_7PL		2		// EPWM7_INT
#define G3_8PL		13		// EPWM8_INT
#define G3_9PL		4		// EPWM9_INT
#define G3_10PL		12		// EPWM10_INT
#define G3_11PL		4		// EPWM11_INT
#define G3_12PL		14		// EPWM12_INT
#define G3_13PL		0		// Reserved
#define G3_14PL		0		// Reserved
#define G3_15PL		0		// Reserved
#define G3_16PL		0		// Reserved
                            
                            
#define G4_1PL		3		// ECAP1_INT
#define G4_2PL		3		// ECAP2_INT
#define G4_3PL		3		// ECAP3_INT
#define G4_4PL		6		// ECAP4_INT
#define G4_5PL		7		// ECAP5_INT
#define G4_6PL		7       // ECAP6_INT
#define G4_7PL		0   	// Reserved
#define G4_8PL		0   	// Reserved
#define G4_9PL		0   	// Reserved
#define G4_10PL		0   	// Reserved
#define G4_11PL		0       // Reserved
#define G4_12PL		0       // Reserved
#define G4_13PL		0       // Reserved
#define G4_14PL		0   	// Reserved
#define G4_15PL		0   	// Reserved
#define G4_16PL		0       // Reserved
                            
                            
#define G5_1PL		6		// EQEP1_INT
#define G5_2PL		5		// EQEP2_INT
#define G5_3PL		5		// EQEP3_INT
#define G5_4PL		1		// Reserved
#define G5_5PL		9		// CLB1_INT
#define G5_6PL		10		// CLB2_INT
#define G5_7PL		15		// CLB3_INT
#define G5_8PL		13		// CLB4_INT
#define G5_9PL		12		// SD1_INT
#define G5_10PL		9		// SD2_INT
#define G5_11PL		0   	// Reserved
#define G5_12PL		0   	// Reserved
#define G5_13PL		0   	// Reserved
#define G5_14PL		0   	// Reserved
#define G5_15PL		0   	// Reserved
#define G5_16PL		0   	// Reserved
                            
                            
#define G6_1PL		1		// SPIA_RX_INT
#define G6_2PL		7		// SPIA_TX_INT
#define G6_3PL		3		// SPIB_RX_INT
#define G6_4PL		3		// SPIB_TX_INT
#define G6_5PL		10		// MCBSPA_RX_INT
#define G6_6PL		7		// MCBSPA_TX_INT
#define G6_7PL		6		// MCBSPB_RX_INT
#define G6_8PL		13		// MCBSPB_TX_INT
#define G6_9PL		14		// SPIC_RX_INT
#define G6_10PL		3		// SPIC_TX_INT
#define G6_11PL		0		// Reserved
#define G6_12PL		0		// Reserved
#define G6_13PL		0		// Reserved
#define G6_14PL		0		// Reserved
#define G6_15PL		0		// Reserved
#define G6_16PL		0		// Reserved
                            
                            
#define G7_1PL		1		// DMA_CH1_INT
#define G7_2PL		11		// DMA_CH2_INT
#define G7_3PL		14		// DMA_CH3_INT
#define G7_4PL		3		// DMA_CH4_INT
#define G7_5PL		13		// DMA_CH5_INT
#define G7_6PL		14		// DMA_CH6_INT
#define G7_7PL		0   	// Reserved
#define G7_8PL		0   	// Reserved
#define G7_9PL		0   	// Reserved
#define G7_10PL		0   	// Reserved
#define G7_11PL		0   	// Reserved
#define G7_12PL		0   	// Reserved
#define G7_13PL		0   	// Reserved
#define G7_14PL		0   	// Reserved
#define G7_15PL		0   	// Reserved
#define G7_16PL		0   	// Reserved
                            
                            
#define G8_1PL		14		// I2CA_INT
#define G8_2PL		10		// I2CA_FIFO_INT
#define G8_3PL		11		// I2CB_INT
#define G8_4PL		9		// I2CB_FIFO_INT
#define G8_5PL		12		// SCIC_RX_INT
#define G8_6PL		2		// SCIC_TX_INT
#define G8_7PL		8		// SCID_RX_INT
#define G8_8PL		7		// SCID_TX_INT
#define G8_9PL		0		// Reserved
#define G8_10PL		0		// Reserved
#define G8_11PL		0		// Reserved
#define G8_12PL		0		// Reserved
#define G8_13PL		0		// Reserved
#define G8_14PL		0		// Reserved
#define G8_15PL		1		// UPPA_INT
#define G8_16PL		0		// Reserved
                            
                            
#define G9_1PL		12		// SCIA_RX_INT
#define G9_2PL		14		// SCIA_TX_INT
#define G9_3PL		11		// SCIB_RX_INT
#define G9_4PL		6		// SCIB_TX_INT
#define G9_5PL		14		// CANA0_INT
#define G9_6PL		10		// CANA1_INT
#define G9_7PL		10		// CANB0_INT
#define G9_8PL		5		// CANB1_INT
#define G9_9PL		0		// Reserved
#define G9_10PL		0		// Reserved
#define G9_11PL		0		// Reserved
#define G9_12PL		0		// Reserved
#define G9_13PL		0		// Reserved
#define G9_14PL		0		// Reserved
#define G9_15PL		12		// USBA_INT
#define G9_16PL		0		// Reserved
                            
                            
#define G10_1PL		14		// ADCA_EVT_INT
#define G10_2PL		3		// ADCA2_INT
#define G10_3PL		1		// ADCA3_INT
#define G10_4PL		12		// ADCA4_INT
#define G10_5PL		5		// ADCB_EVT_INT
#define G10_6PL		11		// ADCB2_INT
#define G10_7PL		12		// ADCB3_INT
#define G10_8PL		13		// ADCB4_INT
#define G10_9PL		7		// ADCC_EVT_INT
#define G10_10PL	8		// ADCC2_INT
#define G10_11PL	4		// ADCC3_INT
#define G10_12PL	9		// ADCC4_INT
#define G10_13PL	2		// ADCD_EVT_INT
#define G10_14PL	10		// ADCD2_INT
#define G10_15PL	11		// ADCD3_INT
#define G10_16PL	5		// ADCD4_INT
                            
                            
#define G11_1PL		9		// CLA1_1_INT
#define G11_2PL		6		// CLA1_2_INT
#define G11_3PL		9		// CLA1_3_INT
#define G11_4PL		9		// CLA1_4_INT
#define G11_5PL		6		// CLA1_5_INT
#define G11_6PL		13		// CLA1_6_INT
#define G11_7PL		10		// CLA1_7_INT
#define G11_8PL		15		// CLA1_8_INT
#define G11_9PL		0		// Reserved
#define G11_10PL	0	    // Reserved
#define G11_11PL	0	    // Reserved
#define G11_12PL	0	    // Reserved
#define G11_13PL	0	    // Reserved
#define G11_14PL	0	    // Reserved
#define G11_15PL	0	    // Reserved
#define G11_16PL	0	    // Reserved
                            
                            
#define G12_1PL		3		// XINT3_INT
#define G12_2PL		6		// XINT4_INT
#define G12_3PL		10		// XINT5_INT
#define G12_4PL		5		// Reserved
#define G12_5PL		2		// FMC_INT
#define G12_6PL		11		// VCU_INT
#define G12_7PL		14		// FPU_OVERFLOW_ISR
#define G12_8PL		14  	// FPU_UNDERFLOW_ISR
#define G12_9PL		6   	// EMIF_ERROR_ISR
#define G12_10PL	5   	// RAM_CORRECTABLE_ERROR_ISR
#define G12_11PL	4   	// FLASH_CORRECTABLE_ERROR_ISR
#define G12_12PL	12		// RAM_ACCESS_VIOLATION_INT
#define G12_13PL	8		// SYS_PLL_SLIP_INT
#define G12_14PL	2		// AUX_PLL_SLIP_INT
#define G12_15PL	12		// CLA_UNDERFLOW_INT
#define G12_16PL	2		// CLA_OVERFLOW_INT


// There should be no need to modify code below this line
//-------------------------------------------------------------------------------
// Automatically generate IER interrupt masks MINT1 to MINT16:
//
// Beginning of MINT1:
#if (INT1PL == 0)
#define  MINT1_1PL    ~(1 << 0)
#else
#define  MINT1_1PL    0xFFFF
#endif

#if (INT2PL >= INT1PL) || (INT2PL == 0)
#define  MINT1_2PL    ~(1 << 1)
#else
#define  MINT1_2PL    0xFFFF
#endif

#if (INT3PL >= INT1PL) || (INT3PL == 0)
#define  MINT1_3PL    ~(1 << 2)
#else
#define  MINT1_3PL    0xFFFF
#endif

#if (INT4PL >= INT1PL) || (INT4PL == 0)
#define  MINT1_4PL    ~(1 << 3)
#else
#define  MINT1_4PL    0xFFFF
#endif

#if (INT5PL >= INT1PL) || (INT5PL == 0)
#define  MINT1_5PL    ~(1 << 4)
#else
#define  MINT1_5PL    0xFFFF
#endif

#if (INT6PL >= INT1PL) || (INT6PL == 0)
#define  MINT1_6PL    ~(1 << 5)
#else
#define  MINT1_6PL    0xFFFF
#endif

#if (INT7PL >= INT1PL) || (INT7PL == 0)
#define  MINT1_7PL    ~(1 << 6)
#else
#define  MINT1_7PL    0xFFFF
#endif

#if (INT8PL >= INT1PL) || (INT8PL == 0)
#define  MINT1_8PL    ~(1 << 7)
#else
#define  MINT1_8PL    0xFFFF
#endif

#if (INT9PL >= INT1PL) || (INT9PL == 0)
#define  MINT1_9PL    ~(1 << 8)
#else
#define  MINT1_9PL    0xFFFF
#endif

#if (INT10PL >= INT1PL) || (INT10PL == 0)
#define  MINT1_10PL    ~(1 << 9)
#else
#define  MINT1_10PL    0xFFFF
#endif

#if (INT11PL >= INT1PL) || (INT11PL == 0)
#define  MINT1_11PL    ~(1 << 10)
#else
#define  MINT1_11PL    0xFFFF
#endif

#if (INT12PL >= INT1PL) || (INT12PL == 0)
#define  MINT1_12PL    ~(1 << 11)
#else
#define  MINT1_12PL    0xFFFF
#endif

#if (INT13PL >= INT1PL) || (INT13PL == 0)
#define  MINT1_13PL    ~(1 << 12)
#else
#define  MINT1_13PL    0xFFFF
#endif

#if (INT14PL >= INT1PL) || (INT14PL == 0)
#define  MINT1_14PL    ~(1 << 13)
#else
#define  MINT1_14PL    0xFFFF
#endif

#if (INT15PL >= INT1PL) || (INT15PL == 0)
#define  MINT1_15PL    ~(1 << 14)
#else
#define  MINT1_15PL    0xFFFF
#endif

#if (INT16PL >= INT1PL) || (INT16PL == 0)
#define  MINT1_16PL    ~(1 << 15)
#else
#define  MINT1_16PL    0xFFFF
#endif

#define  MINT1    (MINT1_1PL  & MINT1_2PL  & MINT1_3PL  & MINT1_4PL  & \
                   MINT1_5PL  & MINT1_6PL  & MINT1_7PL  & MINT1_8PL  & \
                   MINT1_9PL  & MINT1_10PL & MINT1_11PL & MINT1_12PL & \
                   MINT1_13PL & MINT1_14PL & MINT1_15PL & MINT1_16PL)
// End Of MINT1.

// Beginning of MINT2:
#if (INT1PL >= INT2PL) || (INT1PL == 0)
#define  MINT2_1PL    ~(1 << 0)
#else
#define  MINT2_1PL    0xFFFF
#endif

#if (INT2PL == 0)
#define  MINT2_2PL    ~(1 << 1)
#else
#define  MINT2_2PL    0xFFFF
#endif

#if (INT3PL >= INT2PL) || (INT3PL == 0)
#define  MINT2_3PL    ~(1 << 2)
#else
#define  MINT2_3PL    0xFFFF
#endif

#if (INT4PL >= INT2PL) || (INT4PL == 0)
#define  MINT2_4PL    ~(1 << 3)
#else
#define  MINT2_4PL    0xFFFF
#endif

#if (INT5PL >= INT2PL) || (INT5PL == 0)
#define  MINT2_5PL    ~(1 << 4)
#else
#define  MINT2_5PL    0xFFFF
#endif

#if (INT6PL >= INT2PL) || (INT6PL == 0)
#define  MINT2_6PL    ~(1 << 5)
#else
#define  MINT2_6PL    0xFFFF
#endif

#if (INT7PL >= INT2PL) || (INT7PL == 0)
#define  MINT2_7PL    ~(1 << 6)
#else
#define  MINT2_7PL    0xFFFF
#endif

#if (INT8PL >= INT2PL) || (INT8PL == 0)
#define  MINT2_8PL    ~(1 << 7)
#else
#define  MINT2_8PL    0xFFFF
#endif

#if (INT9PL >= INT2PL) || (INT9PL == 0)
#define  MINT2_9PL    ~(1 << 8)
#else
#define  MINT2_9PL    0xFFFF
#endif

#if (INT10PL >= INT2PL) || (INT10PL == 0)
#define  MINT2_10PL    ~(1 << 9)
#else
#define  MINT2_10PL    0xFFFF
#endif

#if (INT11PL >= INT2PL) || (INT11PL == 0)
#define  MINT2_11PL    ~(1 << 10)
#else
#define  MINT2_11PL    0xFFFF
#endif

#if (INT12PL >= INT2PL) || (INT12PL == 0)
#define  MINT2_12PL    ~(1 << 11)
#else
#define  MINT2_12PL    0xFFFF
#endif

#if (INT13PL >= INT2PL) || (INT13PL == 0)
#define  MINT2_13PL    ~(1 << 12)
#else
#define  MINT2_13PL    0xFFFF
#endif

#if (INT14PL >= INT2PL) || (INT14PL == 0)
#define  MINT2_14PL    ~(1 << 13)
#else
#define  MINT2_14PL    0xFFFF
#endif

#if (INT15PL >= INT2PL) || (INT15PL == 0)
#define  MINT2_15PL    ~(1 << 14)
#else
#define  MINT2_15PL    0xFFFF
#endif

#if (INT16PL >= INT2PL) || (INT16PL == 0)
#define  MINT2_16PL    ~(1 << 15)
#else
#define  MINT2_16PL    0xFFFF
#endif

#define  MINT2    (MINT2_1PL  & MINT2_2PL  & MINT2_3PL  & MINT2_4PL  & \
                   MINT2_5PL  & MINT2_6PL  & MINT2_7PL  & MINT2_8PL  & \
                   MINT2_9PL  & MINT2_10PL & MINT2_11PL & MINT2_12PL & \
                   MINT2_13PL & MINT2_14PL & MINT2_15PL & MINT2_16PL)
// End Of MINT2.

// Beginning of MINT3:
#if (INT1PL >= INT3PL) || (INT1PL == 0)
#define  MINT3_1PL    ~(1 << 0)
#else
#define  MINT3_1PL    0xFFFF
#endif

#if (INT2PL >= INT3PL) || (INT2PL == 0)
#define  MINT3_2PL    ~(1 << 1)
#else
#define  MINT3_2PL    0xFFFF
#endif

#if (INT3PL == 0)
#define  MINT3_3PL    ~(1 << 2)
#else
#define  MINT3_3PL    0xFFFF
#endif

#if (INT4PL >= INT3PL) || (INT4PL == 0)
#define  MINT3_4PL    ~(1 << 3)
#else
#define  MINT3_4PL    0xFFFF
#endif

#if (INT5PL >= INT3PL) || (INT5PL == 0)
#define  MINT3_5PL    ~(1 << 4)
#else
#define  MINT3_5PL    0xFFFF
#endif

#if (INT6PL >= INT3PL) || (INT6PL == 0)
#define  MINT3_6PL    ~(1 << 5)
#else
#define  MINT3_6PL    0xFFFF
#endif

#if (INT7PL >= INT3PL) || (INT7PL == 0)
#define  MINT3_7PL    ~(1 << 6)
#else
#define  MINT3_7PL    0xFFFF
#endif

#if (INT8PL >= INT3PL) || (INT8PL == 0)
#define  MINT3_8PL    ~(1 << 7)
#else
#define  MINT3_8PL    0xFFFF
#endif

#if (INT9PL >= INT3PL) || (INT9PL == 0)
#define  MINT3_9PL    ~(1 << 8)
#else
#define  MINT3_9PL    0xFFFF
#endif

#if (INT10PL >= INT3PL) || (INT10PL == 0)
#define  MINT3_10PL    ~(1 << 9)
#else
#define  MINT3_10PL    0xFFFF
#endif

#if (INT11PL >= INT3PL) || (INT11PL == 0)
#define  MINT3_11PL    ~(1 << 10)
#else
#define  MINT3_11PL    0xFFFF
#endif

#if (INT12PL >= INT3PL) || (INT12PL == 0)
#define  MINT3_12PL    ~(1 << 11)
#else
#define  MINT3_12PL    0xFFFF
#endif

#if (INT13PL >= INT3PL) || (INT13PL == 0)
#define  MINT3_13PL    ~(1 << 12)
#else
#define  MINT3_13PL    0xFFFF
#endif

#if (INT14PL >= INT3PL) || (INT14PL == 0)
#define  MINT3_14PL    ~(1 << 13)
#else
#define  MINT3_14PL    0xFFFF
#endif

#if (INT15PL >= INT3PL) || (INT15PL == 0)
#define  MINT3_15PL    ~(1 << 14)
#else
#define  MINT3_15PL    0xFFFF
#endif

#if (INT16PL >= INT3PL) || (INT16PL == 0)
#define  MINT3_16PL    ~(1 << 15)
#else
#define  MINT3_16PL    0xFFFF
#endif

#define  MINT3    (MINT3_1PL  & MINT3_2PL  & MINT3_3PL  & MINT3_4PL  & \
                   MINT3_5PL  & MINT3_6PL  & MINT3_7PL  & MINT3_8PL  & \
                   MINT3_9PL  & MINT3_10PL & MINT3_11PL & MINT3_12PL & \
                   MINT3_13PL & MINT3_14PL & MINT3_15PL & MINT3_16PL)
// End Of MINT3.

// Beginning of MINT4:
#if (INT1PL >= INT4PL) || (INT1PL == 0)
#define  MINT4_1PL    ~(1 << 0)
#else
#define  MINT4_1PL    0xFFFF
#endif

#if (INT2PL >= INT4PL) || (INT2PL == 0)
#define  MINT4_2PL    ~(1 << 1)
#else
#define  MINT4_2PL    0xFFFF
#endif

#if (INT3PL >= INT4PL) || (INT3PL == 0)
#define  MINT4_3PL    ~(1 << 2)
#else
#define  MINT4_3PL    0xFFFF
#endif

#if (INT4PL == 0)
#define  MINT4_4PL    ~(1 << 3)
#else
#define  MINT4_4PL    0xFFFF
#endif

#if (INT5PL >= INT4PL) || (INT5PL == 0)
#define  MINT4_5PL    ~(1 << 4)
#else
#define  MINT4_5PL    0xFFFF
#endif

#if (INT6PL >= INT4PL) || (INT6PL == 0)
#define  MINT4_6PL    ~(1 << 5)
#else
#define  MINT4_6PL    0xFFFF
#endif

#if (INT7PL >= INT4PL) || (INT7PL == 0)
#define  MINT4_7PL    ~(1 << 6)
#else
#define  MINT4_7PL    0xFFFF
#endif

#if (INT8PL >= INT4PL) || (INT8PL == 0)
#define  MINT4_8PL    ~(1 << 7)
#else
#define  MINT4_8PL    0xFFFF
#endif

#if (INT9PL >= INT4PL) || (INT9PL == 0)
#define  MINT4_9PL    ~(1 << 8)
#else
#define  MINT4_9PL    0xFFFF
#endif

#if (INT10PL >= INT4PL) || (INT10PL == 0)
#define  MINT4_10PL    ~(1 << 9)
#else
#define  MINT4_10PL    0xFFFF
#endif

#if (INT11PL >= INT4PL) || (INT11PL == 0)
#define  MINT4_11PL    ~(1 << 10)
#else
#define  MINT4_11PL    0xFFFF
#endif

#if (INT12PL >= INT4PL) || (INT12PL == 0)
#define  MINT4_12PL    ~(1 << 11)
#else
#define  MINT4_12PL    0xFFFF
#endif

#if (INT13PL >= INT4PL) || (INT13PL == 0)
#define  MINT4_13PL    ~(1 << 12)
#else
#define  MINT4_13PL    0xFFFF
#endif

#if (INT14PL >= INT4PL) || (INT14PL == 0)
#define  MINT4_14PL    ~(1 << 13)
#else
#define  MINT4_14PL    0xFFFF
#endif

#if (INT15PL >= INT4PL) || (INT15PL == 0)
#define  MINT4_15PL    ~(1 << 14)
#else
#define  MINT4_15PL    0xFFFF
#endif

#if (INT16PL >= INT4PL) || (INT16PL == 0)
#define  MINT4_16PL    ~(1 << 15)
#else
#define  MINT4_16PL    0xFFFF
#endif

#define  MINT4    (MINT4_1PL  & MINT4_2PL  & MINT4_3PL  & MINT4_4PL  & \
                   MINT4_5PL  & MINT4_6PL  & MINT4_7PL  & MINT4_8PL  & \
                   MINT4_9PL  & MINT4_10PL & MINT4_11PL & MINT4_12PL & \
                   MINT4_13PL & MINT4_14PL & MINT4_15PL & MINT4_16PL)
// End Of MINT4.

// Beginning of MINT5:
#if (INT1PL >= INT5PL) || (INT1PL == 0)
#define  MINT5_1PL    ~(1 << 0)
#else
#define  MINT5_1PL    0xFFFF
#endif

#if (INT2PL >= INT5PL) || (INT2PL == 0)
#define  MINT5_2PL    ~(1 << 1)
#else
#define  MINT5_2PL    0xFFFF
#endif

#if (INT3PL >= INT5PL) || (INT3PL == 0)
#define  MINT5_3PL    ~(1 << 2)
#else
#define  MINT5_3PL    0xFFFF
#endif

#if (INT4PL >= INT5PL) || (INT4PL == 0)
#define  MINT5_4PL    ~(1 << 3)
#else
#define  MINT5_4PL    0xFFFF
#endif

#if (INT5PL == 0)
#define  MINT5_5PL    ~(1 << 4)
#else
#define  MINT5_5PL    0xFFFF
#endif

#if (INT6PL >= INT5PL) || (INT6PL == 0)
#define  MINT5_6PL    ~(1 << 5)
#else
#define  MINT5_6PL    0xFFFF
#endif

#if (INT7PL >= INT5PL) || (INT7PL == 0)
#define  MINT5_7PL    ~(1 << 6)
#else
#define  MINT5_7PL    0xFFFF
#endif

#if (INT8PL >= INT5PL) || (INT8PL == 0)
#define  MINT5_8PL    ~(1 << 7)
#else
#define  MINT5_8PL    0xFFFF
#endif

#if (INT9PL >= INT5PL) || (INT9PL == 0)
#define  MINT5_9PL    ~(1 << 8)
#else
#define  MINT5_9PL    0xFFFF
#endif

#if (INT10PL >= INT5PL) || (INT10PL == 0)
#define  MINT5_10PL    ~(1 << 9)
#else
#define  MINT5_10PL    0xFFFF
#endif

#if (INT11PL >= INT5PL) || (INT11PL == 0)
#define  MINT5_11PL    ~(1 << 10)
#else
#define  MINT5_11PL    0xFFFF
#endif

#if (INT12PL >= INT5PL) || (INT12PL == 0)
#define  MINT5_12PL    ~(1 << 11)
#else
#define  MINT5_12PL    0xFFFF
#endif

#if (INT13PL >= INT5PL) || (INT13PL == 0)
#define  MINT5_13PL    ~(1 << 12)
#else
#define  MINT5_13PL    0xFFFF
#endif

#if (INT14PL >= INT5PL) || (INT14PL == 0)
#define  MINT5_14PL    ~(1 << 13)
#else
#define  MINT5_14PL    0xFFFF
#endif

#if (INT15PL >= INT5PL) || (INT15PL == 0)
#define  MINT5_15PL    ~(1 << 14)
#else
#define  MINT5_15PL    0xFFFF
#endif

#if (INT16PL >= INT5PL) || (INT16PL == 0)
#define  MINT5_16PL    ~(1 << 15)
#else
#define  MINT5_16PL    0xFFFF
#endif

#define  MINT5    (MINT5_1PL  & MINT5_2PL  & MINT5_3PL  & MINT5_4PL  & \
                   MINT5_5PL  & MINT5_6PL  & MINT5_7PL  & MINT5_8PL  & \
                   MINT5_9PL  & MINT5_10PL & MINT5_11PL & MINT5_12PL & \
                   MINT5_13PL & MINT5_14PL & MINT5_15PL & MINT5_16PL)
// End Of MINT5.

// Beginning of MINT6:
#if (INT1PL >= INT6PL) || (INT1PL == 0)
#define  MINT6_1PL    ~(1 << 0)
#else
#define  MINT6_1PL    0xFFFF
#endif

#if (INT2PL >= INT6PL) || (INT2PL == 0)
#define  MINT6_2PL    ~(1 << 1)
#else
#define  MINT6_2PL    0xFFFF
#endif

#if (INT3PL >= INT6PL) || (INT3PL == 0)
#define  MINT6_3PL    ~(1 << 2)
#else
#define  MINT6_3PL    0xFFFF
#endif

#if (INT4PL >= INT6PL) || (INT4PL == 0)
#define  MINT6_4PL    ~(1 << 3)
#else
#define  MINT6_4PL    0xFFFF
#endif

#if (INT5PL >= INT6PL) || (INT5PL == 0)
#define  MINT6_5PL    ~(1 << 4)
#else
#define  MINT6_5PL    0xFFFF
#endif

#if (INT6PL == 0)
#define  MINT6_6PL    ~(1 << 5)
#else
#define  MINT6_6PL    0xFFFF
#endif

#if (INT7PL >= INT6PL) || (INT7PL == 0)
#define  MINT6_7PL    ~(1 << 6)
#else
#define  MINT6_7PL    0xFFFF
#endif

#if (INT8PL >= INT6PL) || (INT8PL == 0)
#define  MINT6_8PL    ~(1 << 7)
#else
#define  MINT6_8PL    0xFFFF
#endif

#if (INT9PL >= INT6PL) || (INT9PL == 0)
#define  MINT6_9PL    ~(1 << 8)
#else
#define  MINT6_9PL    0xFFFF
#endif

#if (INT10PL >= INT6PL) || (INT10PL == 0)
#define  MINT6_10PL    ~(1 << 9)
#else
#define  MINT6_10PL    0xFFFF
#endif

#if (INT11PL >= INT6PL) || (INT11PL == 0)
#define  MINT6_11PL    ~(1 << 10)
#else
#define  MINT6_11PL    0xFFFF
#endif

#if (INT12PL >= INT6PL) || (INT12PL == 0)
#define  MINT6_12PL    ~(1 << 11)
#else
#define  MINT6_12PL    0xFFFF
#endif

#if (INT13PL >= INT6PL) || (INT13PL == 0)
#define  MINT6_13PL    ~(1 << 12)
#else
#define  MINT6_13PL    0xFFFF
#endif

#if (INT14PL >= INT6PL) || (INT14PL == 0)
#define  MINT6_14PL    ~(1 << 13)
#else
#define  MINT6_14PL    0xFFFF
#endif

#if (INT15PL >= INT6PL) || (INT15PL == 0)
#define  MINT6_15PL    ~(1 << 14)
#else
#define  MINT6_15PL    0xFFFF
#endif

#if (INT16PL >= INT6PL) || (INT16PL == 0)
#define  MINT6_16PL    ~(1 << 15)
#else
#define  MINT6_16PL    0xFFFF
#endif

#define  MINT6    (MINT6_1PL  & MINT6_2PL  & MINT6_3PL  & MINT6_4PL  & \
                   MINT6_5PL  & MINT6_6PL  & MINT6_7PL  & MINT6_8PL  & \
                   MINT6_9PL  & MINT6_10PL & MINT6_11PL & MINT6_12PL & \
                   MINT6_13PL & MINT6_14PL & MINT6_15PL & MINT6_16PL)
// End Of MINT6.

// Beginning of MINT7:
#if (INT1PL >= INT7PL) || (INT1PL == 0)
#define  MINT7_1PL    ~(1 << 0)
#else
#define  MINT7_1PL    0xFFFF
#endif

#if (INT2PL >= INT7PL) || (INT2PL == 0)
#define  MINT7_2PL    ~(1 << 1)
#else
#define  MINT7_2PL    0xFFFF
#endif

#if (INT3PL >= INT7PL) || (INT3PL == 0)
#define  MINT7_3PL    ~(1 << 2)
#else
#define  MINT7_3PL    0xFFFF
#endif

#if (INT4PL >= INT7PL) || (INT4PL == 0)
#define  MINT7_4PL    ~(1 << 3)
#else
#define  MINT7_4PL    0xFFFF
#endif

#if (INT5PL >= INT7PL) || (INT5PL == 0)
#define  MINT7_5PL    ~(1 << 4)
#else
#define  MINT7_5PL    0xFFFF
#endif

#if (INT6PL >= INT7PL) || (INT6PL == 0)
#define  MINT7_6PL    ~(1 << 5)
#else
#define  MINT7_6PL    0xFFFF
#endif

#if (INT7PL == 0)
#define  MINT7_7PL    ~(1 << 6)
#else
#define  MINT7_7PL    0xFFFF
#endif

#if (INT8PL >= INT7PL) || (INT8PL == 0)
#define  MINT7_8PL    ~(1 << 7)
#else
#define  MINT7_8PL    0xFFFF
#endif

#if (INT9PL >= INT7PL) || (INT9PL == 0)
#define  MINT7_9PL    ~(1 << 8)
#else
#define  MINT7_9PL    0xFFFF
#endif

#if (INT10PL >= INT7PL) || (INT10PL == 0)
#define  MINT7_10PL    ~(1 << 9)
#else
#define  MINT7_10PL    0xFFFF
#endif

#if (INT11PL >= INT7PL) || (INT11PL == 0)
#define  MINT7_11PL    ~(1 << 10)
#else
#define  MINT7_11PL    0xFFFF
#endif

#if (INT12PL >= INT7PL) || (INT12PL == 0)
#define  MINT7_12PL    ~(1 << 11)
#else
#define  MINT7_12PL    0xFFFF
#endif

#if (INT13PL >= INT7PL) || (INT13PL == 0)
#define  MINT7_13PL    ~(1 << 12)
#else
#define  MINT7_13PL    0xFFFF
#endif

#if (INT14PL >= INT7PL) || (INT14PL == 0)
#define  MINT7_14PL    ~(1 << 13)
#else
#define  MINT7_14PL    0xFFFF
#endif

#if (INT15PL >= INT7PL) || (INT15PL == 0)
#define  MINT7_15PL    ~(1 << 14)
#else
#define  MINT7_15PL    0xFFFF
#endif

#if (INT16PL >= INT7PL) || (INT16PL == 0)
#define  MINT7_16PL    ~(1 << 15)
#else
#define  MINT7_16PL    0xFFFF
#endif

#define  MINT7    (MINT7_1PL  & MINT7_2PL  & MINT7_3PL  & MINT7_4PL  & \
                   MINT7_5PL  & MINT7_6PL  & MINT7_7PL  & MINT7_8PL  & \
                   MINT7_9PL  & MINT7_10PL & MINT7_11PL & MINT7_12PL & \
                   MINT7_13PL & MINT7_14PL & MINT7_15PL & MINT7_16PL)
// End Of MINT7.

// Beginning of MINT8:
#if (INT1PL >= INT8PL) || (INT1PL == 0)
#define  MINT8_1PL    ~(1 << 0)
#else
#define  MINT8_1PL    0xFFFF
#endif

#if (INT2PL >= INT8PL) || (INT2PL == 0)
#define  MINT8_2PL    ~(1 << 1)
#else
#define  MINT8_2PL    0xFFFF
#endif

#if (INT3PL >= INT8PL) || (INT3PL == 0)
#define  MINT8_3PL    ~(1 << 2)
#else
#define  MINT8_3PL    0xFFFF
#endif

#if (INT4PL >= INT8PL) || (INT4PL == 0)
#define  MINT8_4PL    ~(1 << 3)
#else
#define  MINT8_4PL    0xFFFF
#endif

#if (INT5PL >= INT8PL) || (INT5PL == 0)
#define  MINT8_5PL    ~(1 << 4)
#else
#define  MINT8_5PL    0xFFFF
#endif

#if (INT6PL >= INT8PL) || (INT6PL == 0)
#define  MINT8_6PL    ~(1 << 5)
#else
#define  MINT8_6PL    0xFFFF
#endif

#if (INT7PL >= INT8PL) || (INT7PL == 0)
#define  MINT8_7PL    ~(1 << 6)
#else
#define  MINT8_7PL    0xFFFF
#endif

#if (INT8PL == 0)
#define  MINT8_8PL    ~(1 << 7)
#else
#define  MINT8_8PL    0xFFFF
#endif

#if (INT9PL >= INT8PL) || (INT9PL == 0)
#define  MINT8_9PL    ~(1 << 8)
#else
#define  MINT8_9PL    0xFFFF
#endif

#if (INT10PL >= INT8PL) || (INT10PL == 0)
#define  MINT8_10PL    ~(1 << 9)
#else
#define  MINT8_10PL    0xFFFF
#endif

#if (INT11PL >= INT8PL) || (INT11PL == 0)
#define  MINT8_11PL    ~(1 << 10)
#else
#define  MINT8_11PL    0xFFFF
#endif

#if (INT12PL >= INT8PL) || (INT12PL == 0)
#define  MINT8_12PL    ~(1 << 11)
#else
#define  MINT8_12PL    0xFFFF
#endif

#if (INT13PL >= INT8PL) || (INT13PL == 0)
#define  MINT8_13PL    ~(1 << 12)
#else
#define  MINT8_13PL    0xFFFF
#endif

#if (INT14PL >= INT8PL) || (INT14PL == 0)
#define  MINT8_14PL    ~(1 << 13)
#else
#define  MINT8_14PL    0xFFFF
#endif

#if (INT15PL >= INT8PL) || (INT15PL == 0)
#define  MINT8_15PL    ~(1 << 14)
#else
#define  MINT8_15PL    0xFFFF
#endif

#if (INT16PL >= INT8PL) || (INT16PL == 0)
#define  MINT8_16PL    ~(1 << 15)
#else
#define  MINT8_16PL    0xFFFF
#endif

#define  MINT8    (MINT8_1PL  & MINT8_2PL  & MINT8_3PL  & MINT8_4PL  & \
                   MINT8_5PL  & MINT8_6PL  & MINT8_7PL  & MINT8_8PL  & \
                   MINT8_9PL  & MINT8_10PL & MINT8_11PL & MINT8_12PL & \
                   MINT8_13PL & MINT8_14PL & MINT8_15PL & MINT8_16PL)
// End Of MINT8.

// Beginning of MINT9:
#if (INT1PL >= INT9PL) || (INT1PL == 0)
#define  MINT9_1PL    ~(1 << 0)
#else
#define  MINT9_1PL    0xFFFF
#endif

#if (INT2PL >= INT9PL) || (INT2PL == 0)
#define  MINT9_2PL    ~(1 << 1)
#else
#define  MINT9_2PL    0xFFFF
#endif

#if (INT3PL >= INT9PL) || (INT3PL == 0)
#define  MINT9_3PL    ~(1 << 2)
#else
#define  MINT9_3PL    0xFFFF
#endif

#if (INT4PL >= INT9PL) || (INT4PL == 0)
#define  MINT9_4PL    ~(1 << 3)
#else
#define  MINT9_4PL    0xFFFF
#endif

#if (INT5PL >= INT9PL) || (INT5PL == 0)
#define  MINT9_5PL    ~(1 << 4)
#else
#define  MINT9_5PL    0xFFFF
#endif

#if (INT6PL >= INT9PL) || (INT6PL == 0)
#define  MINT9_6PL    ~(1 << 5)
#else
#define  MINT9_6PL    0xFFFF
#endif

#if (INT7PL >= INT9PL) || (INT7PL == 0)
#define  MINT9_7PL    ~(1 << 6)
#else
#define  MINT9_7PL    0xFFFF
#endif

#if (INT8PL >= INT9PL) || (INT8PL == 0)
#define  MINT9_8PL    ~(1 << 7)
#else
#define  MINT9_8PL    0xFFFF
#endif

#if (INT9PL == 0)
#define  MINT9_9PL    ~(1 << 8)
#else
#define  MINT9_9PL    0xFFFF
#endif

#if (INT10PL >= INT9PL) || (INT10PL == 0)
#define  MINT9_10PL    ~(1 << 9)
#else
#define  MINT9_10PL    0xFFFF
#endif

#if (INT11PL >= INT9PL) || (INT11PL == 0)
#define  MINT9_11PL    ~(1 << 10)
#else
#define  MINT9_11PL    0xFFFF
#endif

#if (INT12PL >= INT9PL) || (INT12PL == 0)
#define  MINT9_12PL    ~(1 << 11)
#else
#define  MINT9_12PL    0xFFFF
#endif

#if (INT13PL >= INT9PL) || (INT13PL == 0)
#define  MINT9_13PL    ~(1 << 12)
#else
#define  MINT9_13PL    0xFFFF
#endif

#if (INT14PL >= INT9PL) || (INT14PL == 0)
#define  MINT9_14PL    ~(1 << 13)
#else
#define  MINT9_14PL    0xFFFF
#endif

#if (INT15PL >= INT9PL) || (INT15PL == 0)
#define  MINT9_15PL    ~(1 << 14)
#else
#define  MINT9_15PL    0xFFFF
#endif

#if (INT16PL >= INT9PL) || (INT16PL == 0)
#define  MINT9_16PL    ~(1 << 15)
#else
#define  MINT9_16PL    0xFFFF
#endif

#define  MINT9    (MINT9_1PL  & MINT9_2PL  & MINT9_3PL  & MINT9_4PL  & \
                   MINT9_5PL  & MINT9_6PL  & MINT9_7PL  & MINT9_8PL  & \
                   MINT9_9PL  & MINT9_10PL & MINT9_11PL & MINT9_12PL & \
                   MINT9_13PL & MINT9_14PL & MINT9_15PL & MINT9_16PL)
// End Of MINT9.

// Beginning of MINT10:
#if (INT1PL >= INT10PL) || (INT1PL == 0)
#define  MINT10_1PL    ~(1 << 0)
#else
#define  MINT10_1PL    0xFFFF
#endif

#if (INT2PL >= INT10PL) || (INT2PL == 0)
#define  MINT10_2PL    ~(1 << 1)
#else
#define  MINT10_2PL    0xFFFF
#endif

#if (INT3PL >= INT10PL) || (INT3PL == 0)
#define  MINT10_3PL    ~(1 << 2)
#else
#define  MINT10_3PL    0xFFFF
#endif

#if (INT4PL >= INT10PL) || (INT4PL == 0)
#define  MINT10_4PL    ~(1 << 3)
#else
#define  MINT10_4PL    0xFFFF
#endif

#if (INT5PL >= INT10PL) || (INT5PL == 0)
#define  MINT10_5PL    ~(1 << 4)
#else
#define  MINT10_5PL    0xFFFF
#endif

#if (INT6PL >= INT10PL) || (INT6PL == 0)
#define  MINT10_6PL    ~(1 << 5)
#else
#define  MINT10_6PL    0xFFFF
#endif

#if (INT7PL >= INT10PL) || (INT7PL == 0)
#define  MINT10_7PL    ~(1 << 6)
#else
#define  MINT10_7PL    0xFFFF
#endif

#if (INT8PL >= INT10PL) || (INT8PL == 0)
#define  MINT10_8PL    ~(1 << 7)
#else
#define  MINT10_8PL    0xFFFF
#endif

#if (INT9PL >= INT10PL) || (INT9PL == 0)
#define  MINT10_9PL    ~(1 << 8)
#else
#define  MINT10_9PL    0xFFFF
#endif

#if (INT10PL == 0)
#define  MINT10_10PL    ~(1 << 9)
#else
#define  MINT10_10PL    0xFFFF
#endif

#if (INT11PL >= INT10PL) || (INT11PL == 0)
#define  MINT10_11PL    ~(1 << 10)
#else
#define  MINT10_11PL    0xFFFF
#endif

#if (INT12PL >= INT10PL) || (INT12PL == 0)
#define  MINT10_12PL    ~(1 << 11)
#else
#define  MINT10_12PL    0xFFFF
#endif

#if (INT13PL >= INT10PL) || (INT13PL == 0)
#define  MINT10_13PL    ~(1 << 12)
#else
#define  MINT10_13PL    0xFFFF
#endif

#if (INT14PL >= INT10PL) || (INT14PL == 0)
#define  MINT10_14PL    ~(1 << 13)
#else
#define  MINT10_14PL    0xFFFF
#endif

#if (INT15PL >= INT10PL) || (INT15PL == 0)
#define  MINT10_15PL    ~(1 << 14)
#else
#define  MINT10_15PL    0xFFFF
#endif

#if (INT16PL >= INT10PL) || (INT16PL == 0)
#define  MINT10_16PL    ~(1 << 15)
#else
#define  MINT10_16PL    0xFFFF
#endif

#define  MINT10    (MINT10_1PL  & MINT10_2PL  & MINT10_3PL  & MINT10_4PL  & \
                   MINT10_5PL  & MINT10_6PL  & MINT10_7PL  & MINT10_8PL  & \
                   MINT10_9PL  & MINT10_10PL & MINT10_11PL & MINT10_12PL & \
                   MINT10_13PL & MINT10_14PL & MINT10_15PL & MINT10_16PL)
// End Of MINT10.

// Beginning of MINT11:
#if (INT1PL >= INT11PL) || (INT1PL == 0)
#define  MINT11_1PL    ~(1 << 0)
#else
#define  MINT11_1PL    0xFFFF
#endif

#if (INT2PL >= INT11PL) || (INT2PL == 0)
#define  MINT11_2PL    ~(1 << 1)
#else
#define  MINT11_2PL    0xFFFF
#endif

#if (INT3PL >= INT11PL) || (INT3PL == 0)
#define  MINT11_3PL    ~(1 << 2)
#else
#define  MINT11_3PL    0xFFFF
#endif

#if (INT4PL >= INT11PL) || (INT4PL == 0)
#define  MINT11_4PL    ~(1 << 3)
#else
#define  MINT11_4PL    0xFFFF
#endif

#if (INT5PL >= INT11PL) || (INT5PL == 0)
#define  MINT11_5PL    ~(1 << 4)
#else
#define  MINT11_5PL    0xFFFF
#endif

#if (INT6PL >= INT11PL) || (INT6PL == 0)
#define  MINT11_6PL    ~(1 << 5)
#else
#define  MINT11_6PL    0xFFFF
#endif

#if (INT7PL >= INT11PL) || (INT7PL == 0)
#define  MINT11_7PL    ~(1 << 6)
#else
#define  MINT11_7PL    0xFFFF
#endif

#if (INT8PL >= INT11PL) || (INT8PL == 0)
#define  MINT11_8PL    ~(1 << 7)
#else
#define  MINT11_8PL    0xFFFF
#endif

#if (INT9PL >= INT11PL) || (INT9PL == 0)
#define  MINT11_9PL    ~(1 << 8)
#else
#define  MINT11_9PL    0xFFFF
#endif

#if (INT10PL >= INT11PL) || (INT10PL == 0)
#define  MINT11_10PL    ~(1 << 9)
#else
#define  MINT11_10PL    0xFFFF
#endif

#if (INT11PL == 0)
#define  MINT11_11PL    ~(1 << 10)
#else
#define  MINT11_11PL    0xFFFF
#endif

#if (INT12PL >= INT11PL) || (INT12PL == 0)
#define  MINT11_12PL    ~(1 << 11)
#else
#define  MINT11_12PL    0xFFFF
#endif

#if (INT13PL >= INT11PL) || (INT13PL == 0)
#define  MINT11_13PL    ~(1 << 12)
#else
#define  MINT11_13PL    0xFFFF
#endif

#if (INT14PL >= INT11PL) || (INT14PL == 0)
#define  MINT11_14PL    ~(1 << 13)
#else
#define  MINT11_14PL    0xFFFF
#endif

#if (INT15PL >= INT11PL) || (INT15PL == 0)
#define  MINT11_15PL    ~(1 << 14)
#else
#define  MINT11_15PL    0xFFFF
#endif

#if (INT16PL >= INT11PL) || (INT16PL == 0)
#define  MINT11_16PL    ~(1 << 15)
#else
#define  MINT11_16PL    0xFFFF
#endif

#define  MINT11    (MINT11_1PL  & MINT11_2PL  & MINT11_3PL  & MINT11_4PL  & \
                   MINT11_5PL  & MINT11_6PL  & MINT11_7PL  & MINT11_8PL  & \
                   MINT11_9PL  & MINT11_10PL & MINT11_11PL & MINT11_12PL & \
                   MINT11_13PL & MINT11_14PL & MINT11_15PL & MINT11_16PL)
// End Of MINT11.

// Beginning of MINT12:
#if (INT1PL >= INT12PL) || (INT1PL == 0)
#define  MINT12_1PL    ~(1 << 0)
#else
#define  MINT12_1PL    0xFFFF
#endif

#if (INT2PL >= INT12PL) || (INT2PL == 0)
#define  MINT12_2PL    ~(1 << 1)
#else
#define  MINT12_2PL    0xFFFF
#endif

#if (INT3PL >= INT12PL) || (INT3PL == 0)
#define  MINT12_3PL    ~(1 << 2)
#else
#define  MINT12_3PL    0xFFFF
#endif

#if (INT4PL >= INT12PL) || (INT4PL == 0)
#define  MINT12_4PL    ~(1 << 3)
#else
#define  MINT12_4PL    0xFFFF
#endif

#if (INT5PL >= INT12PL) || (INT5PL == 0)
#define  MINT12_5PL    ~(1 << 4)
#else
#define  MINT12_5PL    0xFFFF
#endif

#if (INT6PL >= INT12PL) || (INT6PL == 0)
#define  MINT12_6PL    ~(1 << 5)
#else
#define  MINT12_6PL    0xFFFF
#endif

#if (INT7PL >= INT12PL) || (INT7PL == 0)
#define  MINT12_7PL    ~(1 << 6)
#else
#define  MINT12_7PL    0xFFFF
#endif

#if (INT8PL >= INT12PL) || (INT8PL == 0)
#define  MINT12_8PL    ~(1 << 7)
#else
#define  MINT12_8PL    0xFFFF
#endif

#if (INT9PL >= INT12PL) || (INT9PL == 0)
#define  MINT12_9PL    ~(1 << 8)
#else
#define  MINT12_9PL    0xFFFF
#endif

#if (INT10PL >= INT12PL) || (INT10PL == 0)
#define  MINT12_10PL    ~(1 << 9)
#else
#define  MINT12_10PL    0xFFFF
#endif

#if (INT11PL >= INT12PL) || (INT11PL == 0)
#define  MINT12_11PL    ~(1 << 10)
#else
#define  MINT12_11PL    0xFFFF
#endif

#if (INT12PL == 0)
#define  MINT12_12PL    ~(1 << 11)
#else
#define  MINT12_12PL    0xFFFF
#endif

#if (INT13PL >= INT12PL) || (INT13PL == 0)
#define  MINT12_13PL    ~(1 << 12)
#else
#define  MINT12_13PL    0xFFFF
#endif

#if (INT14PL >= INT12PL) || (INT14PL == 0)
#define  MINT12_14PL    ~(1 << 13)
#else
#define  MINT12_14PL    0xFFFF
#endif

#if (INT15PL >= INT12PL) || (INT15PL == 0)
#define  MINT12_15PL    ~(1 << 14)
#else
#define  MINT12_15PL    0xFFFF
#endif

#if (INT16PL >= INT12PL) || (INT16PL == 0)
#define  MINT12_16PL    ~(1 << 15)
#else
#define  MINT12_16PL    0xFFFF
#endif

#define  MINT12    (MINT12_1PL  & MINT12_2PL  & MINT12_3PL  & MINT12_4PL  & \
                   MINT12_5PL  & MINT12_6PL  & MINT12_7PL  & MINT12_8PL  & \
                   MINT12_9PL  & MINT12_10PL & MINT12_11PL & MINT12_12PL & \
                   MINT12_13PL & MINT12_14PL & MINT12_15PL & MINT12_16PL)
// End Of MINT12.

// Beginning of MINT13:
#if (INT1PL >= INT13PL) || (INT1PL == 0)
#define  MINT13_1PL    ~(1 << 0)
#else
#define  MINT13_1PL    0xFFFF
#endif

#if (INT2PL >= INT13PL) || (INT2PL == 0)
#define  MINT13_2PL    ~(1 << 1)
#else
#define  MINT13_2PL    0xFFFF
#endif

#if (INT3PL >= INT13PL) || (INT3PL == 0)
#define  MINT13_3PL    ~(1 << 2)
#else
#define  MINT13_3PL    0xFFFF
#endif

#if (INT4PL >= INT13PL) || (INT4PL == 0)
#define  MINT13_4PL    ~(1 << 3)
#else
#define  MINT13_4PL    0xFFFF
#endif

#if (INT5PL >= INT13PL) || (INT5PL == 0)
#define  MINT13_5PL    ~(1 << 4)
#else
#define  MINT13_5PL    0xFFFF
#endif

#if (INT6PL >= INT13PL) || (INT6PL == 0)
#define  MINT13_6PL    ~(1 << 5)
#else
#define  MINT13_6PL    0xFFFF
#endif

#if (INT7PL >= INT13PL) || (INT7PL == 0)
#define  MINT13_7PL    ~(1 << 6)
#else
#define  MINT13_7PL    0xFFFF
#endif

#if (INT8PL >= INT13PL) || (INT8PL == 0)
#define  MINT13_8PL    ~(1 << 7)
#else
#define  MINT13_8PL    0xFFFF
#endif

#if (INT9PL >= INT13PL) || (INT9PL == 0)
#define  MINT13_9PL    ~(1 << 8)
#else
#define  MINT13_9PL    0xFFFF
#endif

#if (INT10PL >= INT13PL) || (INT10PL == 0)
#define  MINT13_10PL    ~(1 << 9)
#else
#define  MINT13_10PL    0xFFFF
#endif

#if (INT11PL >= INT13PL) || (INT11PL == 0)
#define  MINT13_11PL    ~(1 << 10)
#else
#define  MINT13_11PL    0xFFFF
#endif

#if (INT12PL >= INT13PL) || (INT12PL == 0)
#define  MINT13_12PL    ~(1 << 11)
#else
#define  MINT13_12PL    0xFFFF
#endif

#if (INT13PL == 0)
#define  MINT13_13PL    ~(1 << 12)
#else
#define  MINT13_13PL    0xFFFF
#endif

#if (INT14PL >= INT13PL) || (INT14PL == 0)
#define  MINT13_14PL    ~(1 << 13)
#else
#define  MINT13_14PL    0xFFFF
#endif

#if (INT15PL >= INT13PL) || (INT15PL == 0)
#define  MINT13_15PL    ~(1 << 14)
#else
#define  MINT13_15PL    0xFFFF
#endif

#if (INT16PL >= INT13PL) || (INT16PL == 0)
#define  MINT13_16PL    ~(1 << 15)
#else
#define  MINT13_16PL    0xFFFF
#endif

#define  MINT13    (MINT13_1PL  & MINT13_2PL  & MINT13_3PL  & MINT13_4PL  & \
                   MINT13_5PL  & MINT13_6PL  & MINT13_7PL  & MINT13_8PL  & \
                   MINT13_9PL  & MINT13_10PL & MINT13_11PL & MINT13_12PL & \
                   MINT13_13PL & MINT13_14PL & MINT13_15PL & MINT13_16PL)
// End Of MINT13.

// Beginning of MINT14:
#if (INT1PL >= INT14PL) || (INT1PL == 0)
#define  MINT14_1PL    ~(1 << 0)
#else
#define  MINT14_1PL    0xFFFF
#endif

#if (INT2PL >= INT14PL) || (INT2PL == 0)
#define  MINT14_2PL    ~(1 << 1)
#else
#define  MINT14_2PL    0xFFFF
#endif

#if (INT3PL >= INT14PL) || (INT3PL == 0)
#define  MINT14_3PL    ~(1 << 2)
#else
#define  MINT14_3PL    0xFFFF
#endif

#if (INT4PL >= INT14PL) || (INT4PL == 0)
#define  MINT14_4PL    ~(1 << 3)
#else
#define  MINT14_4PL    0xFFFF
#endif

#if (INT5PL >= INT14PL) || (INT5PL == 0)
#define  MINT14_5PL    ~(1 << 4)
#else
#define  MINT14_5PL    0xFFFF
#endif

#if (INT6PL >= INT14PL) || (INT6PL == 0)
#define  MINT14_6PL    ~(1 << 5)
#else
#define  MINT14_6PL    0xFFFF
#endif

#if (INT7PL >= INT14PL) || (INT7PL == 0)
#define  MINT14_7PL    ~(1 << 6)
#else
#define  MINT14_7PL    0xFFFF
#endif

#if (INT8PL >= INT14PL) || (INT8PL == 0)
#define  MINT14_8PL    ~(1 << 7)
#else
#define  MINT14_8PL    0xFFFF
#endif

#if (INT9PL >= INT14PL) || (INT9PL == 0)
#define  MINT14_9PL    ~(1 << 8)
#else
#define  MINT14_9PL    0xFFFF
#endif

#if (INT10PL >= INT14PL) || (INT10PL == 0)
#define  MINT14_10PL    ~(1 << 9)
#else
#define  MINT14_10PL    0xFFFF
#endif

#if (INT11PL >= INT14PL) || (INT11PL == 0)
#define  MINT14_11PL    ~(1 << 10)
#else
#define  MINT14_11PL    0xFFFF
#endif

#if (INT12PL >= INT14PL) || (INT12PL == 0)
#define  MINT14_12PL    ~(1 << 11)
#else
#define  MINT14_12PL    0xFFFF
#endif

#if (INT13PL >= INT14PL) || (INT13PL == 0)
#define  MINT14_13PL    ~(1 << 12)
#else
#define  MINT14_13PL    0xFFFF
#endif

#define  MINT14_14PL    ~(1 << 13)

#if (INT15PL >= INT14PL) || (INT15PL == 0)
#define  MINT14_15PL    ~(1 << 14)
#else
#define  MINT14_15PL    0xFFFF
#endif

#if (INT16PL >= INT14PL) || (INT16PL == 0)
#define  MINT14_16PL    ~(1 << 15)
#else
#define  MINT14_16PL    0xFFFF
#endif

#define  MINT14    (MINT14_1PL  & MINT14_2PL  & MINT14_3PL  & MINT14_4PL  & \
                   MINT14_5PL  & MINT14_6PL  & MINT14_7PL  & MINT14_8PL  & \
                   MINT14_9PL  & MINT14_10PL & MINT14_11PL & MINT14_12PL & \
                   MINT14_13PL & MINT14_14PL & MINT14_15PL & MINT14_16PL)
// End Of MINT14.

// Beginning of MINT15:
#if (INT1PL >= INT15PL) || (INT1PL == 0)
#define  MINT15_1PL    ~(1 << 0)
#else
#define  MINT15_1PL    0xFFFF
#endif

#if (INT2PL >= INT15PL) || (INT2PL == 0)
#define  MINT15_2PL    ~(1 << 1)
#else
#define  MINT15_2PL    0xFFFF
#endif

#if (INT3PL >= INT15PL) || (INT3PL == 0)
#define  MINT15_3PL    ~(1 << 2)
#else
#define  MINT15_3PL    0xFFFF
#endif

#if (INT4PL >= INT15PL) || (INT4PL == 0)
#define  MINT15_4PL    ~(1 << 3)
#else
#define  MINT15_4PL    0xFFFF
#endif

#if (INT5PL >= INT15PL) || (INT5PL == 0)
#define  MINT15_5PL    ~(1 << 4)
#else
#define  MINT15_5PL    0xFFFF
#endif

#if (INT6PL >= INT15PL) || (INT6PL == 0)
#define  MINT15_6PL    ~(1 << 5)
#else
#define  MINT15_6PL    0xFFFF
#endif

#if (INT7PL >= INT15PL) || (INT7PL == 0)
#define  MINT15_7PL    ~(1 << 6)
#else
#define  MINT15_7PL    0xFFFF
#endif

#if (INT8PL >= INT15PL) || (INT8PL == 0)
#define  MINT15_8PL    ~(1 << 7)
#else
#define  MINT15_8PL    0xFFFF
#endif

#if (INT9PL >= INT15PL) || (INT9PL == 0)
#define  MINT15_9PL    ~(1 << 8)
#else
#define  MINT15_9PL    0xFFFF
#endif

#if (INT10PL >= INT15PL) || (INT10PL == 0)
#define  MINT15_10PL    ~(1 << 9)
#else
#define  MINT15_10PL    0xFFFF
#endif

#if (INT11PL >= INT15PL) || (INT11PL == 0)
#define  MINT15_11PL    ~(1 << 10)
#else
#define  MINT15_11PL    0xFFFF
#endif

#if (INT12PL >= INT15PL) || (INT12PL == 0)
#define  MINT15_12PL    ~(1 << 11)
#else
#define  MINT15_12PL    0xFFFF
#endif

#if (INT13PL >= INT15PL) || (INT13PL == 0)
#define  MINT15_13PL    ~(1 << 12)
#else
#define  MINT15_13PL    0xFFFF
#endif

#if (INT14PL >= INT15PL) || (INT14PL == 0)
#define  MINT15_14PL    ~(1 << 13)
#else
#define  MINT15_14PL    0xFFFF
#endif

#define  MINT15_15PL    ~(1 << 14)

#if (INT16PL >= INT15PL) || (INT16PL == 0)
#define  MINT15_16PL    ~(1 << 15)
#else
#define  MINT15_16PL    0xFFFF
#endif

#define  MINT15    (MINT15_1PL  & MINT15_2PL  & MINT15_3PL  & MINT15_4PL  & \
                   MINT15_5PL  & MINT15_6PL  & MINT15_7PL  & MINT15_8PL  & \
                   MINT15_9PL  & MINT15_10PL & MINT15_11PL & MINT15_12PL & \
                   MINT15_13PL & MINT15_14PL & MINT15_15PL & MINT15_16PL)
// End Of MINT15.

// Beginning of MINT16:
#if (INT1PL >= INT16PL) || (INT1PL == 0)
#define  MINT16_1PL    ~(1 << 0)
#else
#define  MINT16_1PL    0xFFFF
#endif

#if (INT2PL >= INT16PL) || (INT2PL == 0)
#define  MINT16_2PL    ~(1 << 1)
#else
#define  MINT16_2PL    0xFFFF
#endif

#if (INT3PL >= INT16PL) || (INT3PL == 0)
#define  MINT16_3PL    ~(1 << 2)
#else
#define  MINT16_3PL    0xFFFF
#endif

#if (INT4PL >= INT16PL) || (INT4PL == 0)
#define  MINT16_4PL    ~(1 << 3)
#else
#define  MINT16_4PL    0xFFFF
#endif

#if (INT5PL >= INT16PL) || (INT5PL == 0)
#define  MINT16_5PL    ~(1 << 4)
#else
#define  MINT16_5PL    0xFFFF
#endif

#if (INT6PL >= INT16PL) || (INT6PL == 0)
#define  MINT16_6PL    ~(1 << 5)
#else
#define  MINT16_6PL    0xFFFF
#endif

#if (INT7PL >= INT16PL) || (INT7PL == 0)
#define  MINT16_7PL    ~(1 << 6)
#else
#define  MINT16_7PL    0xFFFF
#endif

#if (INT8PL >= INT16PL) || (INT8PL == 0)
#define  MINT16_8PL    ~(1 << 7)
#else
#define  MINT16_8PL    0xFFFF
#endif

#if (INT9PL >= INT16PL) || (INT9PL == 0)
#define  MINT16_9PL    ~(1 << 8)
#else
#define  MINT16_9PL    0xFFFF
#endif

#if (INT10PL >= INT16PL) || (INT10PL == 0)
#define  MINT16_10PL    ~(1 << 9)
#else
#define  MINT16_10PL    0xFFFF
#endif

#if (INT11PL >= INT16PL) || (INT11PL == 0)
#define  MINT16_11PL    ~(1 << 10)
#else
#define  MINT16_11PL    0xFFFF
#endif

#if (INT12PL >= INT16PL) || (INT12PL == 0)
#define  MINT16_12PL    ~(1 << 11)
#else
#define  MINT16_12PL    0xFFFF
#endif

#if (INT13PL >= INT16PL) || (INT13PL == 0)
#define  MINT16_13PL    ~(1 << 12)
#else
#define  MINT16_13PL    0xFFFF
#endif

#if (INT14PL >= INT16PL) || (INT14PL == 0)
#define  MINT16_14PL    ~(1 << 13)
#else
#define  MINT16_14PL    0xFFFF
#endif

#if (INT15PL >= INT16PL) || (INT15PL == 0)
#define  MINT16_15PL    ~(1 << 14)
#else
#define  MINT16_15PL    0xFFFF
#endif

#define  MINT16_16PL    ~(1 << 15)

#define  MINT16    (MINT16_1PL  & MINT16_2PL  & MINT16_3PL  & MINT16_4PL  & \
                   MINT16_5PL  & MINT16_6PL  & MINT16_7PL  & MINT16_8PL  & \
                   MINT16_9PL  & MINT16_10PL & MINT16_11PL & MINT16_12PL & \
                   MINT16_13PL & MINT16_14PL & MINT16_15PL & MINT16_16PL)
// End Of MINT16.

//-------------------------------------------------------------------------------
// Automatically generate PIEIER1 interrupt masks MG11 to MG116:

// Beginning of MG11:
#if (G1_2PL >= G1_1PL) || (G1_2PL == 0)
#define  MG1_1_12PL    ~(1 << 1)
#else
#define  MG1_1_12PL    0xFFFF
#endif

#if (G1_3PL >= G1_1PL) || (G1_3PL == 0)
#define  MG1_1_13PL    ~(1 << 2)
#else
#define  MG1_1_13PL    0xFFFF
#endif

#if (G1_4PL >= G1_1PL) || (G1_4PL == 0)
#define  MG1_1_14PL    ~(1 << 3)
#else
#define  MG1_1_14PL    0xFFFF
#endif

#if (G1_5PL >= G1_1PL) || (G1_5PL == 0)
#define  MG1_1_15PL    ~(1 << 4)
#else
#define  MG1_1_15PL    0xFFFF
#endif

#if (G1_6PL >= G1_1PL) || (G1_6PL == 0)
#define  MG1_1_16PL    ~(1 << 5)
#else
#define  MG1_1_16PL    0xFFFF
#endif

#if (G1_7PL >= G1_1PL) || (G1_7PL == 0)
#define  MG1_1_17PL    ~(1 << 6)
#else
#define  MG1_1_17PL    0xFFFF
#endif

#if (G1_8PL >= G1_1PL) || (G1_8PL == 0)
#define  MG1_1_18PL    ~(1 << 7)
#else
#define  MG1_1_18PL    0xFFFF
#endif

#if (G1_9PL >= G1_1PL) || (G1_9PL == 0)
#define  MG1_1_19PL    ~(1 << 8)
#else
#define  MG1_1_19PL    0xFFFF
#endif

#if (G1_10PL >= G1_1PL) || (G1_10PL == 0)
#define  MG1_1_110PL    ~(1 << 9)
#else
#define  MG1_1_110PL    0xFFFF
#endif

#if (G1_11PL >= G1_1PL) || (G1_11PL == 0)
#define  MG1_1_111PL    ~(1 << 10)
#else
#define  MG1_1_111PL    0xFFFF
#endif

#if (G1_12PL >= G1_1PL) || (G1_12PL == 0)
#define  MG1_1_112PL    ~(1 << 11)
#else
#define  MG1_1_112PL    0xFFFF
#endif

#if (G1_13PL >= G1_1PL) || (G1_13PL == 0)
#define  MG1_1_113PL    ~(1 << 12)
#else
#define  MG1_1_113PL    0xFFFF
#endif

#if (G1_14PL >= G1_1PL) || (G1_14PL == 0)
#define  MG1_1_114PL    ~(1 << 13)
#else
#define  MG1_1_114PL    0xFFFF
#endif

#if (G1_15PL >= G1_1PL) || (G1_15PL == 0)
#define  MG1_1_115PL    ~(1 << 14)
#else
#define  MG1_1_115PL    0xFFFF
#endif

#if (G1_16PL >= G1_1PL) || (G1_16PL == 0)
#define  MG1_1_116PL    ~(1 << 15)
#else
#define  MG1_1_116PL    0xFFFF
#endif

#define  MG1_1_11PL	0xFFFE
#define  MG1_1    (MG1_1_11PL & MG1_1_12PL & MG1_1_13PL & MG1_1_14PL & \
                    MG1_1_15PL & MG1_1_16PL & MG1_1_17PL & MG1_1_18PL & \
                    MG1_1_19PL & MG1_1_110PL & MG1_1_111PL & MG1_1_112PL & \
                    MG1_1_113PL & MG1_1_114PL & MG1_1_115PL & MG1_1_116PL)
// End of MG1_1:
// Beginning of MG12:
#if (G1_1PL >= G1_2PL) || (G1_1PL == 0)
#define  MG1_2_11PL    ~(1 << 0)
#else
#define  MG1_2_11PL    0xFFFF
#endif

#if (G1_3PL >= G1_2PL) || (G1_3PL == 0)
#define  MG1_2_13PL    ~(1 << 2)
#else
#define  MG1_2_13PL    0xFFFF
#endif

#if (G1_4PL >= G1_2PL) || (G1_4PL == 0)
#define  MG1_2_14PL    ~(1 << 3)
#else
#define  MG1_2_14PL    0xFFFF
#endif

#if (G1_5PL >= G1_2PL) || (G1_5PL == 0)
#define  MG1_2_15PL    ~(1 << 4)
#else
#define  MG1_2_15PL    0xFFFF
#endif

#if (G1_6PL >= G1_2PL) || (G1_6PL == 0)
#define  MG1_2_16PL    ~(1 << 5)
#else
#define  MG1_2_16PL    0xFFFF
#endif

#if (G1_7PL >= G1_2PL) || (G1_7PL == 0)
#define  MG1_2_17PL    ~(1 << 6)
#else
#define  MG1_2_17PL    0xFFFF
#endif

#if (G1_8PL >= G1_2PL) || (G1_8PL == 0)
#define  MG1_2_18PL    ~(1 << 7)
#else
#define  MG1_2_18PL    0xFFFF
#endif

#if (G1_9PL >= G1_2PL) || (G1_9PL == 0)
#define  MG1_2_19PL    ~(1 << 8)
#else
#define  MG1_2_19PL    0xFFFF
#endif

#if (G1_10PL >= G1_2PL) || (G1_10PL == 0)
#define  MG1_2_110PL    ~(1 << 9)
#else
#define  MG1_2_110PL    0xFFFF
#endif

#if (G1_11PL >= G1_2PL) || (G1_11PL == 0)
#define  MG1_2_111PL    ~(1 << 10)
#else
#define  MG1_2_111PL    0xFFFF
#endif

#if (G1_12PL >= G1_2PL) || (G1_12PL == 0)
#define  MG1_2_112PL    ~(1 << 11)
#else
#define  MG1_2_112PL    0xFFFF
#endif

#if (G1_13PL >= G1_2PL) || (G1_13PL == 0)
#define  MG1_2_113PL    ~(1 << 12)
#else
#define  MG1_2_113PL    0xFFFF
#endif

#if (G1_14PL >= G1_2PL) || (G1_14PL == 0)
#define  MG1_2_114PL    ~(1 << 13)
#else
#define  MG1_2_114PL    0xFFFF
#endif

#if (G1_15PL >= G1_2PL) || (G1_15PL == 0)
#define  MG1_2_115PL    ~(1 << 14)
#else
#define  MG1_2_115PL    0xFFFF
#endif

#if (G1_16PL >= G1_2PL) || (G1_16PL == 0)
#define  MG1_2_116PL    ~(1 << 15)
#else
#define  MG1_2_116PL    0xFFFF
#endif

#define  MG1_2_12PL	0xFFFD
#define  MG1_2    (MG1_2_11PL & MG1_2_12PL & MG1_2_13PL & MG1_2_14PL & \
                    MG1_2_15PL & MG1_2_16PL & MG1_2_17PL & MG1_2_18PL & \
                    MG1_2_19PL & MG1_2_110PL & MG1_2_111PL & MG1_2_112PL & \
                    MG1_2_113PL & MG1_2_114PL & MG1_2_115PL & MG1_2_116PL)
// End of MG1_2:
// Beginning of MG13:
#if (G1_1PL >= G1_3PL) || (G1_1PL == 0)
#define  MG1_3_11PL    ~(1 << 0)
#else
#define  MG1_3_11PL    0xFFFF
#endif

#if (G1_2PL >= G1_3PL) || (G1_2PL == 0)
#define  MG1_3_12PL    ~(1 << 1)
#else
#define  MG1_3_12PL    0xFFFF
#endif

#if (G1_4PL >= G1_3PL) || (G1_4PL == 0)
#define  MG1_3_14PL    ~(1 << 3)
#else
#define  MG1_3_14PL    0xFFFF
#endif

#if (G1_5PL >= G1_3PL) || (G1_5PL == 0)
#define  MG1_3_15PL    ~(1 << 4)
#else
#define  MG1_3_15PL    0xFFFF
#endif

#if (G1_6PL >= G1_3PL) || (G1_6PL == 0)
#define  MG1_3_16PL    ~(1 << 5)
#else
#define  MG1_3_16PL    0xFFFF
#endif

#if (G1_7PL >= G1_3PL) || (G1_7PL == 0)
#define  MG1_3_17PL    ~(1 << 6)
#else
#define  MG1_3_17PL    0xFFFF
#endif

#if (G1_8PL >= G1_3PL) || (G1_8PL == 0)
#define  MG1_3_18PL    ~(1 << 7)
#else
#define  MG1_3_18PL    0xFFFF
#endif

#if (G1_9PL >= G1_3PL) || (G1_9PL == 0)
#define  MG1_3_19PL    ~(1 << 8)
#else
#define  MG1_3_19PL    0xFFFF
#endif

#if (G1_10PL >= G1_3PL) || (G1_10PL == 0)
#define  MG1_3_110PL    ~(1 << 9)
#else
#define  MG1_3_110PL    0xFFFF
#endif

#if (G1_11PL >= G1_3PL) || (G1_11PL == 0)
#define  MG1_3_111PL    ~(1 << 10)
#else
#define  MG1_3_111PL    0xFFFF
#endif

#if (G1_12PL >= G1_3PL) || (G1_12PL == 0)
#define  MG1_3_112PL    ~(1 << 11)
#else
#define  MG1_3_112PL    0xFFFF
#endif

#if (G1_13PL >= G1_3PL) || (G1_13PL == 0)
#define  MG1_3_113PL    ~(1 << 12)
#else
#define  MG1_3_113PL    0xFFFF
#endif

#if (G1_14PL >= G1_3PL) || (G1_14PL == 0)
#define  MG1_3_114PL    ~(1 << 13)
#else
#define  MG1_3_114PL    0xFFFF
#endif

#if (G1_15PL >= G1_3PL) || (G1_15PL == 0)
#define  MG1_3_115PL    ~(1 << 14)
#else
#define  MG1_3_115PL    0xFFFF
#endif

#if (G1_16PL >= G1_3PL) || (G1_16PL == 0)
#define  MG1_3_116PL    ~(1 << 15)
#else
#define  MG1_3_116PL    0xFFFF
#endif

#define  MG1_3_13PL	0xFFFB
#define  MG1_3    (MG1_3_11PL & MG1_3_12PL & MG1_3_13PL & MG1_3_14PL & \
                    MG1_3_15PL & MG1_3_16PL & MG1_3_17PL & MG1_3_18PL & \
                    MG1_3_19PL & MG1_3_110PL & MG1_3_111PL & MG1_3_112PL & \
                    MG1_3_113PL & MG1_3_114PL & MG1_3_115PL & MG1_3_116PL)
// End of MG1_3:
// Beginning of MG14:
#if (G1_1PL >= G1_4PL) || (G1_1PL == 0)
#define  MG1_4_11PL    ~(1 << 0)
#else
#define  MG1_4_11PL    0xFFFF
#endif

#if (G1_2PL >= G1_4PL) || (G1_2PL == 0)
#define  MG1_4_12PL    ~(1 << 1)
#else
#define  MG1_4_12PL    0xFFFF
#endif

#if (G1_3PL >= G1_4PL) || (G1_3PL == 0)
#define  MG1_4_13PL    ~(1 << 2)
#else
#define  MG1_4_13PL    0xFFFF
#endif

#if (G1_5PL >= G1_4PL) || (G1_5PL == 0)
#define  MG1_4_15PL    ~(1 << 4)
#else
#define  MG1_4_15PL    0xFFFF
#endif

#if (G1_6PL >= G1_4PL) || (G1_6PL == 0)
#define  MG1_4_16PL    ~(1 << 5)
#else
#define  MG1_4_16PL    0xFFFF
#endif

#if (G1_7PL >= G1_4PL) || (G1_7PL == 0)
#define  MG1_4_17PL    ~(1 << 6)
#else
#define  MG1_4_17PL    0xFFFF
#endif

#if (G1_8PL >= G1_4PL) || (G1_8PL == 0)
#define  MG1_4_18PL    ~(1 << 7)
#else
#define  MG1_4_18PL    0xFFFF
#endif

#if (G1_9PL >= G1_4PL) || (G1_9PL == 0)
#define  MG1_4_19PL    ~(1 << 8)
#else
#define  MG1_4_19PL    0xFFFF
#endif

#if (G1_10PL >= G1_4PL) || (G1_10PL == 0)
#define  MG1_4_110PL    ~(1 << 9)
#else
#define  MG1_4_110PL    0xFFFF
#endif

#if (G1_11PL >= G1_4PL) || (G1_11PL == 0)
#define  MG1_4_111PL    ~(1 << 10)
#else
#define  MG1_4_111PL    0xFFFF
#endif

#if (G1_12PL >= G1_4PL) || (G1_12PL == 0)
#define  MG1_4_112PL    ~(1 << 11)
#else
#define  MG1_4_112PL    0xFFFF
#endif

#if (G1_13PL >= G1_4PL) || (G1_13PL == 0)
#define  MG1_4_113PL    ~(1 << 12)
#else
#define  MG1_4_113PL    0xFFFF
#endif

#if (G1_14PL >= G1_4PL) || (G1_14PL == 0)
#define  MG1_4_114PL    ~(1 << 13)
#else
#define  MG1_4_114PL    0xFFFF
#endif

#if (G1_15PL >= G1_4PL) || (G1_15PL == 0)
#define  MG1_4_115PL    ~(1 << 14)
#else
#define  MG1_4_115PL    0xFFFF
#endif

#if (G1_16PL >= G1_4PL) || (G1_16PL == 0)
#define  MG1_4_116PL    ~(1 << 15)
#else
#define  MG1_4_116PL    0xFFFF
#endif

#define  MG1_4_14PL	0xFFF7
#define  MG1_4    (MG1_4_11PL & MG1_4_12PL & MG1_4_13PL & MG1_4_14PL & \
                    MG1_4_15PL & MG1_4_16PL & MG1_4_17PL & MG1_4_18PL & \
                    MG1_4_19PL & MG1_4_110PL & MG1_4_111PL & MG1_4_112PL & \
                    MG1_4_113PL & MG1_4_114PL & MG1_4_115PL & MG1_4_116PL)
// End of MG1_4:
// Beginning of MG15:
#if (G1_1PL >= G1_5PL) || (G1_1PL == 0)
#define  MG1_5_11PL    ~(1 << 0)
#else
#define  MG1_5_11PL    0xFFFF
#endif

#if (G1_2PL >= G1_5PL) || (G1_2PL == 0)
#define  MG1_5_12PL    ~(1 << 1)
#else
#define  MG1_5_12PL    0xFFFF
#endif

#if (G1_3PL >= G1_5PL) || (G1_3PL == 0)
#define  MG1_5_13PL    ~(1 << 2)
#else
#define  MG1_5_13PL    0xFFFF
#endif

#if (G1_4PL >= G1_5PL) || (G1_4PL == 0)
#define  MG1_5_14PL    ~(1 << 3)
#else
#define  MG1_5_14PL    0xFFFF
#endif

#if (G1_6PL >= G1_5PL) || (G1_6PL == 0)
#define  MG1_5_16PL    ~(1 << 5)
#else
#define  MG1_5_16PL    0xFFFF
#endif

#if (G1_7PL >= G1_5PL) || (G1_7PL == 0)
#define  MG1_5_17PL    ~(1 << 6)
#else
#define  MG1_5_17PL    0xFFFF
#endif

#if (G1_8PL >= G1_5PL) || (G1_8PL == 0)
#define  MG1_5_18PL    ~(1 << 7)
#else
#define  MG1_5_18PL    0xFFFF
#endif

#if (G1_9PL >= G1_5PL) || (G1_9PL == 0)
#define  MG1_5_19PL    ~(1 << 8)
#else
#define  MG1_5_19PL    0xFFFF
#endif

#if (G1_10PL >= G1_5PL) || (G1_10PL == 0)
#define  MG1_5_110PL    ~(1 << 9)
#else
#define  MG1_5_110PL    0xFFFF
#endif

#if (G1_11PL >= G1_5PL) || (G1_11PL == 0)
#define  MG1_5_111PL    ~(1 << 10)
#else
#define  MG1_5_111PL    0xFFFF
#endif

#if (G1_12PL >= G1_5PL) || (G1_12PL == 0)
#define  MG1_5_112PL    ~(1 << 11)
#else
#define  MG1_5_112PL    0xFFFF
#endif

#if (G1_13PL >= G1_5PL) || (G1_13PL == 0)
#define  MG1_5_113PL    ~(1 << 12)
#else
#define  MG1_5_113PL    0xFFFF
#endif

#if (G1_14PL >= G1_5PL) || (G1_14PL == 0)
#define  MG1_5_114PL    ~(1 << 13)
#else
#define  MG1_5_114PL    0xFFFF
#endif

#if (G1_15PL >= G1_5PL) || (G1_15PL == 0)
#define  MG1_5_115PL    ~(1 << 14)
#else
#define  MG1_5_115PL    0xFFFF
#endif

#if (G1_16PL >= G1_5PL) || (G1_16PL == 0)
#define  MG1_5_116PL    ~(1 << 15)
#else
#define  MG1_5_116PL    0xFFFF
#endif

#define  MG1_5_15PL	0xFFEF
#define  MG1_5    (MG1_5_11PL & MG1_5_12PL & MG1_5_13PL & MG1_5_14PL & \
                    MG1_5_15PL & MG1_5_16PL & MG1_5_17PL & MG1_5_18PL & \
                    MG1_5_19PL & MG1_5_110PL & MG1_5_111PL & MG1_5_112PL & \
                    MG1_5_113PL & MG1_5_114PL & MG1_5_115PL & MG1_5_116PL)
// End of MG1_5:
// Beginning of MG16:
#if (G1_1PL >= G1_6PL) || (G1_1PL == 0)
#define  MG1_6_11PL    ~(1 << 0)
#else
#define  MG1_6_11PL    0xFFFF
#endif

#if (G1_2PL >= G1_6PL) || (G1_2PL == 0)
#define  MG1_6_12PL    ~(1 << 1)
#else
#define  MG1_6_12PL    0xFFFF
#endif

#if (G1_3PL >= G1_6PL) || (G1_3PL == 0)
#define  MG1_6_13PL    ~(1 << 2)
#else
#define  MG1_6_13PL    0xFFFF
#endif

#if (G1_4PL >= G1_6PL) || (G1_4PL == 0)
#define  MG1_6_14PL    ~(1 << 3)
#else
#define  MG1_6_14PL    0xFFFF
#endif

#if (G1_5PL >= G1_6PL) || (G1_5PL == 0)
#define  MG1_6_15PL    ~(1 << 4)
#else
#define  MG1_6_15PL    0xFFFF
#endif

#if (G1_7PL >= G1_6PL) || (G1_7PL == 0)
#define  MG1_6_17PL    ~(1 << 6)
#else
#define  MG1_6_17PL    0xFFFF
#endif

#if (G1_8PL >= G1_6PL) || (G1_8PL == 0)
#define  MG1_6_18PL    ~(1 << 7)
#else
#define  MG1_6_18PL    0xFFFF
#endif

#if (G1_9PL >= G1_6PL) || (G1_9PL == 0)
#define  MG1_6_19PL    ~(1 << 8)
#else
#define  MG1_6_19PL    0xFFFF
#endif

#if (G1_10PL >= G1_6PL) || (G1_10PL == 0)
#define  MG1_6_110PL    ~(1 << 9)
#else
#define  MG1_6_110PL    0xFFFF
#endif

#if (G1_11PL >= G1_6PL) || (G1_11PL == 0)
#define  MG1_6_111PL    ~(1 << 10)
#else
#define  MG1_6_111PL    0xFFFF
#endif

#if (G1_12PL >= G1_6PL) || (G1_12PL == 0)
#define  MG1_6_112PL    ~(1 << 11)
#else
#define  MG1_6_112PL    0xFFFF
#endif

#if (G1_13PL >= G1_6PL) || (G1_13PL == 0)
#define  MG1_6_113PL    ~(1 << 12)
#else
#define  MG1_6_113PL    0xFFFF
#endif

#if (G1_14PL >= G1_6PL) || (G1_14PL == 0)
#define  MG1_6_114PL    ~(1 << 13)
#else
#define  MG1_6_114PL    0xFFFF
#endif

#if (G1_15PL >= G1_6PL) || (G1_15PL == 0)
#define  MG1_6_115PL    ~(1 << 14)
#else
#define  MG1_6_115PL    0xFFFF
#endif

#if (G1_16PL >= G1_6PL) || (G1_16PL == 0)
#define  MG1_6_116PL    ~(1 << 15)
#else
#define  MG1_6_116PL    0xFFFF
#endif

#define  MG1_6_16PL	0xFFDF
#define  MG1_6    (MG1_6_11PL & MG1_6_12PL & MG1_6_13PL & MG1_6_14PL & \
                    MG1_6_15PL & MG1_6_16PL & MG1_6_17PL & MG1_6_18PL & \
                    MG1_6_19PL & MG1_6_110PL & MG1_6_111PL & MG1_6_112PL & \
                    MG1_6_113PL & MG1_6_114PL & MG1_6_115PL & MG1_6_116PL)
// End of MG1_6:
// Beginning of MG17:
#if (G1_1PL >= G1_7PL) || (G1_1PL == 0)
#define  MG1_7_11PL    ~(1 << 0)
#else
#define  MG1_7_11PL    0xFFFF
#endif

#if (G1_2PL >= G1_7PL) || (G1_2PL == 0)
#define  MG1_7_12PL    ~(1 << 1)
#else
#define  MG1_7_12PL    0xFFFF
#endif

#if (G1_3PL >= G1_7PL) || (G1_3PL == 0)
#define  MG1_7_13PL    ~(1 << 2)
#else
#define  MG1_7_13PL    0xFFFF
#endif

#if (G1_4PL >= G1_7PL) || (G1_4PL == 0)
#define  MG1_7_14PL    ~(1 << 3)
#else
#define  MG1_7_14PL    0xFFFF
#endif

#if (G1_5PL >= G1_7PL) || (G1_5PL == 0)
#define  MG1_7_15PL    ~(1 << 4)
#else
#define  MG1_7_15PL    0xFFFF
#endif

#if (G1_6PL >= G1_7PL) || (G1_6PL == 0)
#define  MG1_7_16PL    ~(1 << 5)
#else
#define  MG1_7_16PL    0xFFFF
#endif

#if (G1_8PL >= G1_7PL) || (G1_8PL == 0)
#define  MG1_7_18PL    ~(1 << 7)
#else
#define  MG1_7_18PL    0xFFFF
#endif

#if (G1_9PL >= G1_7PL) || (G1_9PL == 0)
#define  MG1_7_19PL    ~(1 << 8)
#else
#define  MG1_7_19PL    0xFFFF
#endif

#if (G1_10PL >= G1_7PL) || (G1_10PL == 0)
#define  MG1_7_110PL    ~(1 << 9)
#else
#define  MG1_7_110PL    0xFFFF
#endif

#if (G1_11PL >= G1_7PL) || (G1_11PL == 0)
#define  MG1_7_111PL    ~(1 << 10)
#else
#define  MG1_7_111PL    0xFFFF
#endif

#if (G1_12PL >= G1_7PL) || (G1_12PL == 0)
#define  MG1_7_112PL    ~(1 << 11)
#else
#define  MG1_7_112PL    0xFFFF
#endif

#if (G1_13PL >= G1_7PL) || (G1_13PL == 0)
#define  MG1_7_113PL    ~(1 << 12)
#else
#define  MG1_7_113PL    0xFFFF
#endif

#if (G1_14PL >= G1_7PL) || (G1_14PL == 0)
#define  MG1_7_114PL    ~(1 << 13)
#else
#define  MG1_7_114PL    0xFFFF
#endif

#if (G1_15PL >= G1_7PL) || (G1_15PL == 0)
#define  MG1_7_115PL    ~(1 << 14)
#else
#define  MG1_7_115PL    0xFFFF
#endif

#if (G1_16PL >= G1_7PL) || (G1_16PL == 0)
#define  MG1_7_116PL    ~(1 << 15)
#else
#define  MG1_7_116PL    0xFFFF
#endif

#define  MG1_7_17PL	0xFFBF
#define  MG1_7    (MG1_7_11PL & MG1_7_12PL & MG1_7_13PL & MG1_7_14PL & \
                    MG1_7_15PL & MG1_7_16PL & MG1_7_17PL & MG1_7_18PL & \
                    MG1_7_19PL & MG1_7_110PL & MG1_7_111PL & MG1_7_112PL & \
                    MG1_7_113PL & MG1_7_114PL & MG1_7_115PL & MG1_7_116PL)
// End of MG1_7:
// Beginning of MG18:
#if (G1_1PL >= G1_8PL) || (G1_1PL == 0)
#define  MG1_8_11PL    ~(1 << 0)
#else
#define  MG1_8_11PL    0xFFFF
#endif

#if (G1_2PL >= G1_8PL) || (G1_2PL == 0)
#define  MG1_8_12PL    ~(1 << 1)
#else
#define  MG1_8_12PL    0xFFFF
#endif

#if (G1_3PL >= G1_8PL) || (G1_3PL == 0)
#define  MG1_8_13PL    ~(1 << 2)
#else
#define  MG1_8_13PL    0xFFFF
#endif

#if (G1_4PL >= G1_8PL) || (G1_4PL == 0)
#define  MG1_8_14PL    ~(1 << 3)
#else
#define  MG1_8_14PL    0xFFFF
#endif

#if (G1_5PL >= G1_8PL) || (G1_5PL == 0)
#define  MG1_8_15PL    ~(1 << 4)
#else
#define  MG1_8_15PL    0xFFFF
#endif

#if (G1_6PL >= G1_8PL) || (G1_6PL == 0)
#define  MG1_8_16PL    ~(1 << 5)
#else
#define  MG1_8_16PL    0xFFFF
#endif

#if (G1_7PL >= G1_8PL) || (G1_7PL == 0)
#define  MG1_8_17PL    ~(1 << 6)
#else
#define  MG1_8_17PL    0xFFFF
#endif

#if (G1_9PL >= G1_8PL) || (G1_9PL == 0)
#define  MG1_8_19PL    ~(1 << 8)
#else
#define  MG1_8_19PL    0xFFFF
#endif

#if (G1_10PL >= G1_8PL) || (G1_10PL == 0)
#define  MG1_8_110PL    ~(1 << 9)
#else
#define  MG1_8_110PL    0xFFFF
#endif

#if (G1_11PL >= G1_8PL) || (G1_11PL == 0)
#define  MG1_8_111PL    ~(1 << 10)
#else
#define  MG1_8_111PL    0xFFFF
#endif

#if (G1_12PL >= G1_8PL) || (G1_12PL == 0)
#define  MG1_8_112PL    ~(1 << 11)
#else
#define  MG1_8_112PL    0xFFFF
#endif

#if (G1_13PL >= G1_8PL) || (G1_13PL == 0)
#define  MG1_8_113PL    ~(1 << 12)
#else
#define  MG1_8_113PL    0xFFFF
#endif

#if (G1_14PL >= G1_8PL) || (G1_14PL == 0)
#define  MG1_8_114PL    ~(1 << 13)
#else
#define  MG1_8_114PL    0xFFFF
#endif

#if (G1_15PL >= G1_8PL) || (G1_15PL == 0)
#define  MG1_8_115PL    ~(1 << 14)
#else
#define  MG1_8_115PL    0xFFFF
#endif

#if (G1_16PL >= G1_8PL) || (G1_16PL == 0)
#define  MG1_8_116PL    ~(1 << 15)
#else
#define  MG1_8_116PL    0xFFFF
#endif

#define  MG1_8_18PL	0xFF7F
#define  MG1_8    (MG1_8_11PL & MG1_8_12PL & MG1_8_13PL & MG1_8_14PL & \
                    MG1_8_15PL & MG1_8_16PL & MG1_8_17PL & MG1_8_18PL & \
                    MG1_8_19PL & MG1_8_110PL & MG1_8_111PL & MG1_8_112PL & \
                    MG1_8_113PL & MG1_8_114PL & MG1_8_115PL & MG1_8_116PL)
// End of MG1_8:
// Beginning of MG19:
#if (G1_1PL >= G1_9PL) || (G1_1PL == 0)
#define  MG1_9_11PL    ~(1 << 0)
#else
#define  MG1_9_11PL    0xFFFF
#endif

#if (G1_2PL >= G1_9PL) || (G1_2PL == 0)
#define  MG1_9_12PL    ~(1 << 1)
#else
#define  MG1_9_12PL    0xFFFF
#endif

#if (G1_3PL >= G1_9PL) || (G1_3PL == 0)
#define  MG1_9_13PL    ~(1 << 2)
#else
#define  MG1_9_13PL    0xFFFF
#endif

#if (G1_4PL >= G1_9PL) || (G1_4PL == 0)
#define  MG1_9_14PL    ~(1 << 3)
#else
#define  MG1_9_14PL    0xFFFF
#endif

#if (G1_5PL >= G1_9PL) || (G1_5PL == 0)
#define  MG1_9_15PL    ~(1 << 4)
#else
#define  MG1_9_15PL    0xFFFF
#endif

#if (G1_6PL >= G1_9PL) || (G1_6PL == 0)
#define  MG1_9_16PL    ~(1 << 5)
#else
#define  MG1_9_16PL    0xFFFF
#endif

#if (G1_7PL >= G1_9PL) || (G1_7PL == 0)
#define  MG1_9_17PL    ~(1 << 6)
#else
#define  MG1_9_17PL    0xFFFF
#endif

#if (G1_8PL >= G1_9PL) || (G1_8PL == 0)
#define  MG1_9_18PL    ~(1 << 7)
#else
#define  MG1_9_18PL    0xFFFF
#endif

#if (G1_10PL >= G1_9PL) || (G1_10PL == 0)
#define  MG1_9_110PL    ~(1 << 9)
#else
#define  MG1_9_110PL    0xFFFF
#endif

#if (G1_11PL >= G1_9PL) || (G1_11PL == 0)
#define  MG1_9_111PL    ~(1 << 10)
#else
#define  MG1_9_111PL    0xFFFF
#endif

#if (G1_12PL >= G1_9PL) || (G1_12PL == 0)
#define  MG1_9_112PL    ~(1 << 11)
#else
#define  MG1_9_112PL    0xFFFF
#endif

#if (G1_13PL >= G1_9PL) || (G1_13PL == 0)
#define  MG1_9_113PL    ~(1 << 12)
#else
#define  MG1_9_113PL    0xFFFF
#endif

#if (G1_14PL >= G1_9PL) || (G1_14PL == 0)
#define  MG1_9_114PL    ~(1 << 13)
#else
#define  MG1_9_114PL    0xFFFF
#endif

#if (G1_15PL >= G1_9PL) || (G1_15PL == 0)
#define  MG1_9_115PL    ~(1 << 14)
#else
#define  MG1_9_115PL    0xFFFF
#endif

#if (G1_16PL >= G1_9PL) || (G1_16PL == 0)
#define  MG1_9_116PL    ~(1 << 15)
#else
#define  MG1_9_116PL    0xFFFF
#endif

#define  MG1_9_19PL	0xFEFF
#define  MG1_9    (MG1_9_11PL & MG1_9_12PL & MG1_9_13PL & MG1_9_14PL & \
                    MG1_9_15PL & MG1_9_16PL & MG1_9_17PL & MG1_9_18PL & \
                    MG1_9_19PL & MG1_9_110PL & MG1_9_111PL & MG1_9_112PL & \
                    MG1_9_113PL & MG1_9_114PL & MG1_9_115PL & MG1_9_116PL)
// End of MG1_9:
// Beginning of MG110:
#if (G1_1PL >= G1_10PL) || (G1_1PL == 0)
#define  MG1_10_11PL    ~(1 << 0)
#else
#define  MG1_10_11PL    0xFFFF
#endif

#if (G1_2PL >= G1_10PL) || (G1_2PL == 0)
#define  MG1_10_12PL    ~(1 << 1)
#else
#define  MG1_10_12PL    0xFFFF
#endif

#if (G1_3PL >= G1_10PL) || (G1_3PL == 0)
#define  MG1_10_13PL    ~(1 << 2)
#else
#define  MG1_10_13PL    0xFFFF
#endif

#if (G1_4PL >= G1_10PL) || (G1_4PL == 0)
#define  MG1_10_14PL    ~(1 << 3)
#else
#define  MG1_10_14PL    0xFFFF
#endif

#if (G1_5PL >= G1_10PL) || (G1_5PL == 0)
#define  MG1_10_15PL    ~(1 << 4)
#else
#define  MG1_10_15PL    0xFFFF
#endif

#if (G1_6PL >= G1_10PL) || (G1_6PL == 0)
#define  MG1_10_16PL    ~(1 << 5)
#else
#define  MG1_10_16PL    0xFFFF
#endif

#if (G1_7PL >= G1_10PL) || (G1_7PL == 0)
#define  MG1_10_17PL    ~(1 << 6)
#else
#define  MG1_10_17PL    0xFFFF
#endif

#if (G1_8PL >= G1_10PL) || (G1_8PL == 0)
#define  MG1_10_18PL    ~(1 << 7)
#else
#define  MG1_10_18PL    0xFFFF
#endif

#if (G1_9PL >= G1_10PL) || (G1_9PL == 0)
#define  MG1_10_19PL    ~(1 << 8)
#else
#define  MG1_10_19PL    0xFFFF
#endif

#if (G1_11PL >= G1_10PL) || (G1_11PL == 0)
#define  MG1_10_111PL    ~(1 << 10)
#else
#define  MG1_10_111PL    0xFFFF
#endif

#if (G1_12PL >= G1_10PL) || (G1_12PL == 0)
#define  MG1_10_112PL    ~(1 << 11)
#else
#define  MG1_10_112PL    0xFFFF
#endif

#if (G1_13PL >= G1_10PL) || (G1_13PL == 0)
#define  MG1_10_113PL    ~(1 << 12)
#else
#define  MG1_10_113PL    0xFFFF
#endif

#if (G1_14PL >= G1_10PL) || (G1_14PL == 0)
#define  MG1_10_114PL    ~(1 << 13)
#else
#define  MG1_10_114PL    0xFFFF
#endif

#if (G1_15PL >= G1_10PL) || (G1_15PL == 0)
#define  MG1_10_115PL    ~(1 << 14)
#else
#define  MG1_10_115PL    0xFFFF
#endif

#if (G1_16PL >= G1_10PL) || (G1_16PL == 0)
#define  MG1_10_116PL    ~(1 << 15)
#else
#define  MG1_10_116PL    0xFFFF
#endif

#define  MG1_10_110PL	0xFDFF
#define  MG1_10    (MG1_10_11PL & MG1_10_12PL & MG1_10_13PL & MG1_10_14PL & \
                    MG1_10_15PL & MG1_10_16PL & MG1_10_17PL & MG1_10_18PL & \
                    MG1_10_19PL & MG1_10_110PL & MG1_10_111PL & MG1_10_112PL & \
                    MG1_10_113PL & MG1_10_114PL & MG1_10_115PL & MG1_10_116PL)
// End of MG1_10:
// Beginning of MG111:
#if (G1_1PL >= G1_11PL) || (G1_1PL == 0)
#define  MG1_11_11PL    ~(1 << 0)
#else
#define  MG1_11_11PL    0xFFFF
#endif

#if (G1_2PL >= G1_11PL) || (G1_2PL == 0)
#define  MG1_11_12PL    ~(1 << 1)
#else
#define  MG1_11_12PL    0xFFFF
#endif

#if (G1_3PL >= G1_11PL) || (G1_3PL == 0)
#define  MG1_11_13PL    ~(1 << 2)
#else
#define  MG1_11_13PL    0xFFFF
#endif

#if (G1_4PL >= G1_11PL) || (G1_4PL == 0)
#define  MG1_11_14PL    ~(1 << 3)
#else
#define  MG1_11_14PL    0xFFFF
#endif

#if (G1_5PL >= G1_11PL) || (G1_5PL == 0)
#define  MG1_11_15PL    ~(1 << 4)
#else
#define  MG1_11_15PL    0xFFFF
#endif

#if (G1_6PL >= G1_11PL) || (G1_6PL == 0)
#define  MG1_11_16PL    ~(1 << 5)
#else
#define  MG1_11_16PL    0xFFFF
#endif

#if (G1_7PL >= G1_11PL) || (G1_7PL == 0)
#define  MG1_11_17PL    ~(1 << 6)
#else
#define  MG1_11_17PL    0xFFFF
#endif

#if (G1_8PL >= G1_11PL) || (G1_8PL == 0)
#define  MG1_11_18PL    ~(1 << 7)
#else
#define  MG1_11_18PL    0xFFFF
#endif

#if (G1_9PL >= G1_11PL) || (G1_9PL == 0)
#define  MG1_11_19PL    ~(1 << 8)
#else
#define  MG1_11_19PL    0xFFFF
#endif

#if (G1_10PL >= G1_11PL) || (G1_10PL == 0)
#define  MG1_11_110PL    ~(1 << 9)
#else
#define  MG1_11_110PL    0xFFFF
#endif

#if (G1_12PL >= G1_11PL) || (G1_12PL == 0)
#define  MG1_11_112PL    ~(1 << 11)
#else
#define  MG1_11_112PL    0xFFFF
#endif

#if (G1_13PL >= G1_11PL) || (G1_13PL == 0)
#define  MG1_11_113PL    ~(1 << 12)
#else
#define  MG1_11_113PL    0xFFFF
#endif

#if (G1_14PL >= G1_11PL) || (G1_14PL == 0)
#define  MG1_11_114PL    ~(1 << 13)
#else
#define  MG1_11_114PL    0xFFFF
#endif

#if (G1_15PL >= G1_11PL) || (G1_15PL == 0)
#define  MG1_11_115PL    ~(1 << 14)
#else
#define  MG1_11_115PL    0xFFFF
#endif

#if (G1_16PL >= G1_11PL) || (G1_16PL == 0)
#define  MG1_11_116PL    ~(1 << 15)
#else
#define  MG1_11_116PL    0xFFFF
#endif

#define  MG1_11_111PL	0xFBFF
#define  MG1_11    (MG1_11_11PL & MG1_11_12PL & MG1_11_13PL & MG1_11_14PL & \
                    MG1_11_15PL & MG1_11_16PL & MG1_11_17PL & MG1_11_18PL & \
                    MG1_11_19PL & MG1_11_110PL & MG1_11_111PL & MG1_11_112PL & \
                    MG1_11_113PL & MG1_11_114PL & MG1_11_115PL & MG1_11_116PL)
// End of MG1_11:
// Beginning of MG112:
#if (G1_1PL >= G1_12PL) || (G1_1PL == 0)
#define  MG1_12_11PL    ~(1 << 0)
#else
#define  MG1_12_11PL    0xFFFF
#endif

#if (G1_2PL >= G1_12PL) || (G1_2PL == 0)
#define  MG1_12_12PL    ~(1 << 1)
#else
#define  MG1_12_12PL    0xFFFF
#endif

#if (G1_3PL >= G1_12PL) || (G1_3PL == 0)
#define  MG1_12_13PL    ~(1 << 2)
#else
#define  MG1_12_13PL    0xFFFF
#endif

#if (G1_4PL >= G1_12PL) || (G1_4PL == 0)
#define  MG1_12_14PL    ~(1 << 3)
#else
#define  MG1_12_14PL    0xFFFF
#endif

#if (G1_5PL >= G1_12PL) || (G1_5PL == 0)
#define  MG1_12_15PL    ~(1 << 4)
#else
#define  MG1_12_15PL    0xFFFF
#endif

#if (G1_6PL >= G1_12PL) || (G1_6PL == 0)
#define  MG1_12_16PL    ~(1 << 5)
#else
#define  MG1_12_16PL    0xFFFF
#endif

#if (G1_7PL >= G1_12PL) || (G1_7PL == 0)
#define  MG1_12_17PL    ~(1 << 6)
#else
#define  MG1_12_17PL    0xFFFF
#endif

#if (G1_8PL >= G1_12PL) || (G1_8PL == 0)
#define  MG1_12_18PL    ~(1 << 7)
#else
#define  MG1_12_18PL    0xFFFF
#endif

#if (G1_9PL >= G1_12PL) || (G1_9PL == 0)
#define  MG1_12_19PL    ~(1 << 8)
#else
#define  MG1_12_19PL    0xFFFF
#endif

#if (G1_10PL >= G1_12PL) || (G1_10PL == 0)
#define  MG1_12_110PL    ~(1 << 9)
#else
#define  MG1_12_110PL    0xFFFF
#endif

#if (G1_11PL >= G1_12PL) || (G1_11PL == 0)
#define  MG1_12_111PL    ~(1 << 10)
#else
#define  MG1_12_111PL    0xFFFF
#endif

#if (G1_13PL >= G1_12PL) || (G1_13PL == 0)
#define  MG1_12_113PL    ~(1 << 12)
#else
#define  MG1_12_113PL    0xFFFF
#endif

#if (G1_14PL >= G1_12PL) || (G1_14PL == 0)
#define  MG1_12_114PL    ~(1 << 13)
#else
#define  MG1_12_114PL    0xFFFF
#endif

#if (G1_15PL >= G1_12PL) || (G1_15PL == 0)
#define  MG1_12_115PL    ~(1 << 14)
#else
#define  MG1_12_115PL    0xFFFF
#endif

#if (G1_16PL >= G1_12PL) || (G1_16PL == 0)
#define  MG1_12_116PL    ~(1 << 15)
#else
#define  MG1_12_116PL    0xFFFF
#endif

#define  MG1_12_112PL	0xF7FF
#define  MG1_12    (MG1_12_11PL & MG1_12_12PL & MG1_12_13PL & MG1_12_14PL & \
                    MG1_12_15PL & MG1_12_16PL & MG1_12_17PL & MG1_12_18PL & \
                    MG1_12_19PL & MG1_12_110PL & MG1_12_111PL & MG1_12_112PL & \
                    MG1_12_113PL & MG1_12_114PL & MG1_12_115PL & MG1_12_116PL)
// End of MG1_12:
// Beginning of MG113:
#if (G1_1PL >= G1_13PL) || (G1_1PL == 0)
#define  MG1_13_11PL    ~(1 << 0)
#else
#define  MG1_13_11PL    0xFFFF
#endif

#if (G1_2PL >= G1_13PL) || (G1_2PL == 0)
#define  MG1_13_12PL    ~(1 << 1)
#else
#define  MG1_13_12PL    0xFFFF
#endif

#if (G1_3PL >= G1_13PL) || (G1_3PL == 0)
#define  MG1_13_13PL    ~(1 << 2)
#else
#define  MG1_13_13PL    0xFFFF
#endif

#if (G1_4PL >= G1_13PL) || (G1_4PL == 0)
#define  MG1_13_14PL    ~(1 << 3)
#else
#define  MG1_13_14PL    0xFFFF
#endif

#if (G1_5PL >= G1_13PL) || (G1_5PL == 0)
#define  MG1_13_15PL    ~(1 << 4)
#else
#define  MG1_13_15PL    0xFFFF
#endif

#if (G1_6PL >= G1_13PL) || (G1_6PL == 0)
#define  MG1_13_16PL    ~(1 << 5)
#else
#define  MG1_13_16PL    0xFFFF
#endif

#if (G1_7PL >= G1_13PL) || (G1_7PL == 0)
#define  MG1_13_17PL    ~(1 << 6)
#else
#define  MG1_13_17PL    0xFFFF
#endif

#if (G1_8PL >= G1_13PL) || (G1_8PL == 0)
#define  MG1_13_18PL    ~(1 << 7)
#else
#define  MG1_13_18PL    0xFFFF
#endif

#if (G1_9PL >= G1_13PL) || (G1_9PL == 0)
#define  MG1_13_19PL    ~(1 << 8)
#else
#define  MG1_13_19PL    0xFFFF
#endif

#if (G1_10PL >= G1_13PL) || (G1_10PL == 0)
#define  MG1_13_110PL    ~(1 << 9)
#else
#define  MG1_13_110PL    0xFFFF
#endif

#if (G1_11PL >= G1_13PL) || (G1_11PL == 0)
#define  MG1_13_111PL    ~(1 << 10)
#else
#define  MG1_13_111PL    0xFFFF
#endif

#if (G1_12PL >= G1_13PL) || (G1_12PL == 0)
#define  MG1_13_112PL    ~(1 << 11)
#else
#define  MG1_13_112PL    0xFFFF
#endif

#if (G1_14PL >= G1_13PL) || (G1_14PL == 0)
#define  MG1_13_114PL    ~(1 << 13)
#else
#define  MG1_13_114PL    0xFFFF
#endif

#if (G1_15PL >= G1_13PL) || (G1_15PL == 0)
#define  MG1_13_115PL    ~(1 << 14)
#else
#define  MG1_13_115PL    0xFFFF
#endif

#if (G1_16PL >= G1_13PL) || (G1_16PL == 0)
#define  MG1_13_116PL    ~(1 << 15)
#else
#define  MG1_13_116PL    0xFFFF
#endif

#define  MG1_13_113PL	0xEFFF
#define  MG1_13    (MG1_13_11PL & MG1_13_12PL & MG1_13_13PL & MG1_13_14PL & \
                    MG1_13_15PL & MG1_13_16PL & MG1_13_17PL & MG1_13_18PL & \
                    MG1_13_19PL & MG1_13_110PL & MG1_13_111PL & MG1_13_112PL & \
                    MG1_13_113PL & MG1_13_114PL & MG1_13_115PL & MG1_13_116PL)
// End of MG1_13:
// Beginning of MG114:
#if (G1_1PL >= G1_14PL) || (G1_1PL == 0)
#define  MG1_14_11PL    ~(1 << 0)
#else
#define  MG1_14_11PL    0xFFFF
#endif

#if (G1_2PL >= G1_14PL) || (G1_2PL == 0)
#define  MG1_14_12PL    ~(1 << 1)
#else
#define  MG1_14_12PL    0xFFFF
#endif

#if (G1_3PL >= G1_14PL) || (G1_3PL == 0)
#define  MG1_14_13PL    ~(1 << 2)
#else
#define  MG1_14_13PL    0xFFFF
#endif

#if (G1_4PL >= G1_14PL) || (G1_4PL == 0)
#define  MG1_14_14PL    ~(1 << 3)
#else
#define  MG1_14_14PL    0xFFFF
#endif

#if (G1_5PL >= G1_14PL) || (G1_5PL == 0)
#define  MG1_14_15PL    ~(1 << 4)
#else
#define  MG1_14_15PL    0xFFFF
#endif

#if (G1_6PL >= G1_14PL) || (G1_6PL == 0)
#define  MG1_14_16PL    ~(1 << 5)
#else
#define  MG1_14_16PL    0xFFFF
#endif

#if (G1_7PL >= G1_14PL) || (G1_7PL == 0)
#define  MG1_14_17PL    ~(1 << 6)
#else
#define  MG1_14_17PL    0xFFFF
#endif

#if (G1_8PL >= G1_14PL) || (G1_8PL == 0)
#define  MG1_14_18PL    ~(1 << 7)
#else
#define  MG1_14_18PL    0xFFFF
#endif

#if (G1_9PL >= G1_14PL) || (G1_9PL == 0)
#define  MG1_14_19PL    ~(1 << 8)
#else
#define  MG1_14_19PL    0xFFFF
#endif

#if (G1_10PL >= G1_14PL) || (G1_10PL == 0)
#define  MG1_14_110PL    ~(1 << 9)
#else
#define  MG1_14_110PL    0xFFFF
#endif

#if (G1_11PL >= G1_14PL) || (G1_11PL == 0)
#define  MG1_14_111PL    ~(1 << 10)
#else
#define  MG1_14_111PL    0xFFFF
#endif

#if (G1_12PL >= G1_14PL) || (G1_12PL == 0)
#define  MG1_14_112PL    ~(1 << 11)
#else
#define  MG1_14_112PL    0xFFFF
#endif

#if (G1_13PL >= G1_14PL) || (G1_13PL == 0)
#define  MG1_14_113PL    ~(1 << 12)
#else
#define  MG1_14_113PL    0xFFFF
#endif

#if (G1_15PL >= G1_14PL) || (G1_15PL == 0)
#define  MG1_14_115PL    ~(1 << 14)
#else
#define  MG1_14_115PL    0xFFFF
#endif

#if (G1_16PL >= G1_14PL) || (G1_16PL == 0)
#define  MG1_14_116PL    ~(1 << 15)
#else
#define  MG1_14_116PL    0xFFFF
#endif

#define  MG1_14_114PL	0xDFFF
#define  MG1_14    (MG1_14_11PL & MG1_14_12PL & MG1_14_13PL & MG1_14_14PL & \
                    MG1_14_15PL & MG1_14_16PL & MG1_14_17PL & MG1_14_18PL & \
                    MG1_14_19PL & MG1_14_110PL & MG1_14_111PL & MG1_14_112PL & \
                    MG1_14_113PL & MG1_14_114PL & MG1_14_115PL & MG1_14_116PL)
// End of MG1_14:
// Beginning of MG115:
#if (G1_1PL >= G1_15PL) || (G1_1PL == 0)
#define  MG1_15_11PL    ~(1 << 0)
#else
#define  MG1_15_11PL    0xFFFF
#endif

#if (G1_2PL >= G1_15PL) || (G1_2PL == 0)
#define  MG1_15_12PL    ~(1 << 1)
#else
#define  MG1_15_12PL    0xFFFF
#endif

#if (G1_3PL >= G1_15PL) || (G1_3PL == 0)
#define  MG1_15_13PL    ~(1 << 2)
#else
#define  MG1_15_13PL    0xFFFF
#endif

#if (G1_4PL >= G1_15PL) || (G1_4PL == 0)
#define  MG1_15_14PL    ~(1 << 3)
#else
#define  MG1_15_14PL    0xFFFF
#endif

#if (G1_5PL >= G1_15PL) || (G1_5PL == 0)
#define  MG1_15_15PL    ~(1 << 4)
#else
#define  MG1_15_15PL    0xFFFF
#endif

#if (G1_6PL >= G1_15PL) || (G1_6PL == 0)
#define  MG1_15_16PL    ~(1 << 5)
#else
#define  MG1_15_16PL    0xFFFF
#endif

#if (G1_7PL >= G1_15PL) || (G1_7PL == 0)
#define  MG1_15_17PL    ~(1 << 6)
#else
#define  MG1_15_17PL    0xFFFF
#endif

#if (G1_8PL >= G1_15PL) || (G1_8PL == 0)
#define  MG1_15_18PL    ~(1 << 7)
#else
#define  MG1_15_18PL    0xFFFF
#endif

#if (G1_9PL >= G1_15PL) || (G1_9PL == 0)
#define  MG1_15_19PL    ~(1 << 8)
#else
#define  MG1_15_19PL    0xFFFF
#endif

#if (G1_10PL >= G1_15PL) || (G1_10PL == 0)
#define  MG1_15_110PL    ~(1 << 9)
#else
#define  MG1_15_110PL    0xFFFF
#endif

#if (G1_11PL >= G1_15PL) || (G1_11PL == 0)
#define  MG1_15_111PL    ~(1 << 10)
#else
#define  MG1_15_111PL    0xFFFF
#endif

#if (G1_12PL >= G1_15PL) || (G1_12PL == 0)
#define  MG1_15_112PL    ~(1 << 11)
#else
#define  MG1_15_112PL    0xFFFF
#endif

#if (G1_13PL >= G1_15PL) || (G1_13PL == 0)
#define  MG1_15_113PL    ~(1 << 12)
#else
#define  MG1_15_113PL    0xFFFF
#endif

#if (G1_14PL >= G1_15PL) || (G1_14PL == 0)
#define  MG1_15_114PL    ~(1 << 13)
#else
#define  MG1_15_114PL    0xFFFF
#endif

#if (G1_16PL >= G1_15PL) || (G1_16PL == 0)
#define  MG1_15_116PL    ~(1 << 15)
#else
#define  MG1_15_116PL    0xFFFF
#endif

#define  MG1_15_115PL	0xBFFF
#define  MG1_15    (MG1_15_11PL & MG1_15_12PL & MG1_15_13PL & MG1_15_14PL & \
                    MG1_15_15PL & MG1_15_16PL & MG1_15_17PL & MG1_15_18PL & \
                    MG1_15_19PL & MG1_15_110PL & MG1_15_111PL & MG1_15_112PL & \
                    MG1_15_113PL & MG1_15_114PL & MG1_15_115PL & MG1_15_116PL)
// End of MG1_15:
// Beginning of MG116:
#if (G1_1PL >= G1_16PL) || (G1_1PL == 0)
#define  MG1_16_11PL    ~(1 << 0)
#else
#define  MG1_16_11PL    0xFFFF
#endif

#if (G1_2PL >= G1_16PL) || (G1_2PL == 0)
#define  MG1_16_12PL    ~(1 << 1)
#else
#define  MG1_16_12PL    0xFFFF
#endif

#if (G1_3PL >= G1_16PL) || (G1_3PL == 0)
#define  MG1_16_13PL    ~(1 << 2)
#else
#define  MG1_16_13PL    0xFFFF
#endif

#if (G1_4PL >= G1_16PL) || (G1_4PL == 0)
#define  MG1_16_14PL    ~(1 << 3)
#else
#define  MG1_16_14PL    0xFFFF
#endif

#if (G1_5PL >= G1_16PL) || (G1_5PL == 0)
#define  MG1_16_15PL    ~(1 << 4)
#else
#define  MG1_16_15PL    0xFFFF
#endif

#if (G1_6PL >= G1_16PL) || (G1_6PL == 0)
#define  MG1_16_16PL    ~(1 << 5)
#else
#define  MG1_16_16PL    0xFFFF
#endif

#if (G1_7PL >= G1_16PL) || (G1_7PL == 0)
#define  MG1_16_17PL    ~(1 << 6)
#else
#define  MG1_16_17PL    0xFFFF
#endif

#if (G1_8PL >= G1_16PL) || (G1_8PL == 0)
#define  MG1_16_18PL    ~(1 << 7)
#else
#define  MG1_16_18PL    0xFFFF
#endif

#if (G1_9PL >= G1_16PL) || (G1_9PL == 0)
#define  MG1_16_19PL    ~(1 << 8)
#else
#define  MG1_16_19PL    0xFFFF
#endif

#if (G1_10PL >= G1_16PL) || (G1_10PL == 0)
#define  MG1_16_110PL    ~(1 << 9)
#else
#define  MG1_16_110PL    0xFFFF
#endif

#if (G1_11PL >= G1_16PL) || (G1_11PL == 0)
#define  MG1_16_111PL    ~(1 << 10)
#else
#define  MG1_16_111PL    0xFFFF
#endif

#if (G1_12PL >= G1_16PL) || (G1_12PL == 0)
#define  MG1_16_112PL    ~(1 << 11)
#else
#define  MG1_16_112PL    0xFFFF
#endif

#if (G1_13PL >= G1_16PL) || (G1_13PL == 0)
#define  MG1_16_113PL    ~(1 << 12)
#else
#define  MG1_16_113PL    0xFFFF
#endif

#if (G1_14PL >= G1_16PL) || (G1_14PL == 0)
#define  MG1_16_114PL    ~(1 << 13)
#else
#define  MG1_16_114PL    0xFFFF
#endif

#if (G1_15PL >= G1_16PL) || (G1_15PL == 0)
#define  MG1_16_115PL    ~(1 << 14)
#else
#define  MG1_16_115PL    0xFFFF
#endif

#define  MG1_16_116PL	0x7FFF
#define  MG1_16    (MG1_16_11PL & MG1_16_12PL & MG1_16_13PL & MG1_16_14PL & \
                    MG1_16_15PL & MG1_16_16PL & MG1_16_17PL & MG1_16_18PL & \
                    MG1_16_19PL & MG1_16_110PL & MG1_16_111PL & MG1_16_112PL & \
                    MG1_16_113PL & MG1_16_114PL & MG1_16_115PL & MG1_16_116PL)
// End of MG1_16:


//-------------------------------------------------------------------------------
// Automatically generate PIEIER2 interrupt masks MG21 to MG216:

// Beginning of MG21:
#if (G2_2PL >= G2_1PL) || (G2_2PL == 0)
#define  MG2_1_12PL    ~(1 << 1)
#else
#define  MG2_1_12PL    0xFFFF
#endif

#if (G2_3PL >= G2_1PL) || (G2_3PL == 0)
#define  MG2_1_13PL    ~(1 << 2)
#else
#define  MG2_1_13PL    0xFFFF
#endif

#if (G2_4PL >= G2_1PL) || (G2_4PL == 0)
#define  MG2_1_14PL    ~(1 << 3)
#else
#define  MG2_1_14PL    0xFFFF
#endif

#if (G2_5PL >= G2_1PL) || (G2_5PL == 0)
#define  MG2_1_15PL    ~(1 << 4)
#else
#define  MG2_1_15PL    0xFFFF
#endif

#if (G2_6PL >= G2_1PL) || (G2_6PL == 0)
#define  MG2_1_16PL    ~(1 << 5)
#else
#define  MG2_1_16PL    0xFFFF
#endif

#if (G2_7PL >= G2_1PL) || (G2_7PL == 0)
#define  MG2_1_17PL    ~(1 << 6)
#else
#define  MG2_1_17PL    0xFFFF
#endif

#if (G2_8PL >= G2_1PL) || (G2_8PL == 0)
#define  MG2_1_18PL    ~(1 << 7)
#else
#define  MG2_1_18PL    0xFFFF
#endif

#if (G2_9PL >= G2_1PL) || (G2_9PL == 0)
#define  MG2_1_19PL    ~(1 << 8)
#else
#define  MG2_1_19PL    0xFFFF
#endif

#if (G2_10PL >= G2_1PL) || (G2_10PL == 0)
#define  MG2_1_110PL    ~(1 << 9)
#else
#define  MG2_1_110PL    0xFFFF
#endif

#if (G2_11PL >= G2_1PL) || (G2_11PL == 0)
#define  MG2_1_111PL    ~(1 << 10)
#else
#define  MG2_1_111PL    0xFFFF
#endif

#if (G2_12PL >= G2_1PL) || (G2_12PL == 0)
#define  MG2_1_112PL    ~(1 << 11)
#else
#define  MG2_1_112PL    0xFFFF
#endif

#if (G2_13PL >= G2_1PL) || (G2_13PL == 0)
#define  MG2_1_113PL    ~(1 << 12)
#else
#define  MG2_1_113PL    0xFFFF
#endif

#if (G2_14PL >= G2_1PL) || (G2_14PL == 0)
#define  MG2_1_114PL    ~(1 << 13)
#else
#define  MG2_1_114PL    0xFFFF
#endif

#if (G2_15PL >= G2_1PL) || (G2_15PL == 0)
#define  MG2_1_115PL    ~(1 << 14)
#else
#define  MG2_1_115PL    0xFFFF
#endif

#if (G2_16PL >= G2_1PL) || (G2_16PL == 0)
#define  MG2_1_116PL    ~(1 << 15)
#else
#define  MG2_1_116PL    0xFFFF
#endif

#define  MG2_1_11PL	0xFFFE
#define  MG2_1    (MG2_1_11PL & MG2_1_12PL & MG2_1_13PL & MG2_1_14PL & \
                    MG2_1_15PL & MG2_1_16PL & MG2_1_17PL & MG2_1_18PL & \
                    MG2_1_19PL & MG2_1_110PL & MG2_1_111PL & MG2_1_112PL & \
                    MG2_1_113PL & MG2_1_114PL & MG2_1_115PL & MG2_1_116PL)
// End of MG2_1:
// Beginning of MG22:
#if (G2_1PL >= G2_2PL) || (G2_1PL == 0)
#define  MG2_2_11PL    ~(1 << 0)
#else
#define  MG2_2_11PL    0xFFFF
#endif

#if (G2_3PL >= G2_2PL) || (G2_3PL == 0)
#define  MG2_2_13PL    ~(1 << 2)
#else
#define  MG2_2_13PL    0xFFFF
#endif

#if (G2_4PL >= G2_2PL) || (G2_4PL == 0)
#define  MG2_2_14PL    ~(1 << 3)
#else
#define  MG2_2_14PL    0xFFFF
#endif

#if (G2_5PL >= G2_2PL) || (G2_5PL == 0)
#define  MG2_2_15PL    ~(1 << 4)
#else
#define  MG2_2_15PL    0xFFFF
#endif

#if (G2_6PL >= G2_2PL) || (G2_6PL == 0)
#define  MG2_2_16PL    ~(1 << 5)
#else
#define  MG2_2_16PL    0xFFFF
#endif

#if (G2_7PL >= G2_2PL) || (G2_7PL == 0)
#define  MG2_2_17PL    ~(1 << 6)
#else
#define  MG2_2_17PL    0xFFFF
#endif

#if (G2_8PL >= G2_2PL) || (G2_8PL == 0)
#define  MG2_2_18PL    ~(1 << 7)
#else
#define  MG2_2_18PL    0xFFFF
#endif

#if (G2_9PL >= G2_2PL) || (G2_9PL == 0)
#define  MG2_2_19PL    ~(1 << 8)
#else
#define  MG2_2_19PL    0xFFFF
#endif

#if (G2_10PL >= G2_2PL) || (G2_10PL == 0)
#define  MG2_2_110PL    ~(1 << 9)
#else
#define  MG2_2_110PL    0xFFFF
#endif

#if (G2_11PL >= G2_2PL) || (G2_11PL == 0)
#define  MG2_2_111PL    ~(1 << 10)
#else
#define  MG2_2_111PL    0xFFFF
#endif

#if (G2_12PL >= G2_2PL) || (G2_12PL == 0)
#define  MG2_2_112PL    ~(1 << 11)
#else
#define  MG2_2_112PL    0xFFFF
#endif

#if (G2_13PL >= G2_2PL) || (G2_13PL == 0)
#define  MG2_2_113PL    ~(1 << 12)
#else
#define  MG2_2_113PL    0xFFFF
#endif

#if (G2_14PL >= G2_2PL) || (G2_14PL == 0)
#define  MG2_2_114PL    ~(1 << 13)
#else
#define  MG2_2_114PL    0xFFFF
#endif

#if (G2_15PL >= G2_2PL) || (G2_15PL == 0)
#define  MG2_2_115PL    ~(1 << 14)
#else
#define  MG2_2_115PL    0xFFFF
#endif

#if (G2_16PL >= G2_2PL) || (G2_16PL == 0)
#define  MG2_2_116PL    ~(1 << 15)
#else
#define  MG2_2_116PL    0xFFFF
#endif

#define  MG2_2_12PL	0xFFFD
#define  MG2_2    (MG2_2_11PL & MG2_2_12PL & MG2_2_13PL & MG2_2_14PL & \
                    MG2_2_15PL & MG2_2_16PL & MG2_2_17PL & MG2_2_18PL & \
                    MG2_2_19PL & MG2_2_110PL & MG2_2_111PL & MG2_2_112PL & \
                    MG2_2_113PL & MG2_2_114PL & MG2_2_115PL & MG2_2_116PL)
// End of MG2_2:
// Beginning of MG23:
#if (G2_1PL >= G2_3PL) || (G2_1PL == 0)
#define  MG2_3_11PL    ~(1 << 0)
#else
#define  MG2_3_11PL    0xFFFF
#endif

#if (G2_2PL >= G2_3PL) || (G2_2PL == 0)
#define  MG2_3_12PL    ~(1 << 1)
#else
#define  MG2_3_12PL    0xFFFF
#endif

#if (G2_4PL >= G2_3PL) || (G2_4PL == 0)
#define  MG2_3_14PL    ~(1 << 3)
#else
#define  MG2_3_14PL    0xFFFF
#endif

#if (G2_5PL >= G2_3PL) || (G2_5PL == 0)
#define  MG2_3_15PL    ~(1 << 4)
#else
#define  MG2_3_15PL    0xFFFF
#endif

#if (G2_6PL >= G2_3PL) || (G2_6PL == 0)
#define  MG2_3_16PL    ~(1 << 5)
#else
#define  MG2_3_16PL    0xFFFF
#endif

#if (G2_7PL >= G2_3PL) || (G2_7PL == 0)
#define  MG2_3_17PL    ~(1 << 6)
#else
#define  MG2_3_17PL    0xFFFF
#endif

#if (G2_8PL >= G2_3PL) || (G2_8PL == 0)
#define  MG2_3_18PL    ~(1 << 7)
#else
#define  MG2_3_18PL    0xFFFF
#endif

#if (G2_9PL >= G2_3PL) || (G2_9PL == 0)
#define  MG2_3_19PL    ~(1 << 8)
#else
#define  MG2_3_19PL    0xFFFF
#endif

#if (G2_10PL >= G2_3PL) || (G2_10PL == 0)
#define  MG2_3_110PL    ~(1 << 9)
#else
#define  MG2_3_110PL    0xFFFF
#endif

#if (G2_11PL >= G2_3PL) || (G2_11PL == 0)
#define  MG2_3_111PL    ~(1 << 10)
#else
#define  MG2_3_111PL    0xFFFF
#endif

#if (G2_12PL >= G2_3PL) || (G2_12PL == 0)
#define  MG2_3_112PL    ~(1 << 11)
#else
#define  MG2_3_112PL    0xFFFF
#endif

#if (G2_13PL >= G2_3PL) || (G2_13PL == 0)
#define  MG2_3_113PL    ~(1 << 12)
#else
#define  MG2_3_113PL    0xFFFF
#endif

#if (G2_14PL >= G2_3PL) || (G2_14PL == 0)
#define  MG2_3_114PL    ~(1 << 13)
#else
#define  MG2_3_114PL    0xFFFF
#endif

#if (G2_15PL >= G2_3PL) || (G2_15PL == 0)
#define  MG2_3_115PL    ~(1 << 14)
#else
#define  MG2_3_115PL    0xFFFF
#endif

#if (G2_16PL >= G2_3PL) || (G2_16PL == 0)
#define  MG2_3_116PL    ~(1 << 15)
#else
#define  MG2_3_116PL    0xFFFF
#endif

#define  MG2_3_13PL	0xFFFB
#define  MG2_3    (MG2_3_11PL & MG2_3_12PL & MG2_3_13PL & MG2_3_14PL & \
                    MG2_3_15PL & MG2_3_16PL & MG2_3_17PL & MG2_3_18PL & \
                    MG2_3_19PL & MG2_3_110PL & MG2_3_111PL & MG2_3_112PL & \
                    MG2_3_113PL & MG2_3_114PL & MG2_3_115PL & MG2_3_116PL)
// End of MG2_3:
// Beginning of MG24:
#if (G2_1PL >= G2_4PL) || (G2_1PL == 0)
#define  MG2_4_11PL    ~(1 << 0)
#else
#define  MG2_4_11PL    0xFFFF
#endif

#if (G2_2PL >= G2_4PL) || (G2_2PL == 0)
#define  MG2_4_12PL    ~(1 << 1)
#else
#define  MG2_4_12PL    0xFFFF
#endif

#if (G2_3PL >= G2_4PL) || (G2_3PL == 0)
#define  MG2_4_13PL    ~(1 << 2)
#else
#define  MG2_4_13PL    0xFFFF
#endif

#if (G2_5PL >= G2_4PL) || (G2_5PL == 0)
#define  MG2_4_15PL    ~(1 << 4)
#else
#define  MG2_4_15PL    0xFFFF
#endif

#if (G2_6PL >= G2_4PL) || (G2_6PL == 0)
#define  MG2_4_16PL    ~(1 << 5)
#else
#define  MG2_4_16PL    0xFFFF
#endif

#if (G2_7PL >= G2_4PL) || (G2_7PL == 0)
#define  MG2_4_17PL    ~(1 << 6)
#else
#define  MG2_4_17PL    0xFFFF
#endif

#if (G2_8PL >= G2_4PL) || (G2_8PL == 0)
#define  MG2_4_18PL    ~(1 << 7)
#else
#define  MG2_4_18PL    0xFFFF
#endif

#if (G2_9PL >= G2_4PL) || (G2_9PL == 0)
#define  MG2_4_19PL    ~(1 << 8)
#else
#define  MG2_4_19PL    0xFFFF
#endif

#if (G2_10PL >= G2_4PL) || (G2_10PL == 0)
#define  MG2_4_110PL    ~(1 << 9)
#else
#define  MG2_4_110PL    0xFFFF
#endif

#if (G2_11PL >= G2_4PL) || (G2_11PL == 0)
#define  MG2_4_111PL    ~(1 << 10)
#else
#define  MG2_4_111PL    0xFFFF
#endif

#if (G2_12PL >= G2_4PL) || (G2_12PL == 0)
#define  MG2_4_112PL    ~(1 << 11)
#else
#define  MG2_4_112PL    0xFFFF
#endif

#if (G2_13PL >= G2_4PL) || (G2_13PL == 0)
#define  MG2_4_113PL    ~(1 << 12)
#else
#define  MG2_4_113PL    0xFFFF
#endif

#if (G2_14PL >= G2_4PL) || (G2_14PL == 0)
#define  MG2_4_114PL    ~(1 << 13)
#else
#define  MG2_4_114PL    0xFFFF
#endif

#if (G2_15PL >= G2_4PL) || (G2_15PL == 0)
#define  MG2_4_115PL    ~(1 << 14)
#else
#define  MG2_4_115PL    0xFFFF
#endif

#if (G2_16PL >= G2_4PL) || (G2_16PL == 0)
#define  MG2_4_116PL    ~(1 << 15)
#else
#define  MG2_4_116PL    0xFFFF
#endif

#define  MG2_4_14PL	0xFFF7
#define  MG2_4    (MG2_4_11PL & MG2_4_12PL & MG2_4_13PL & MG2_4_14PL & \
                    MG2_4_15PL & MG2_4_16PL & MG2_4_17PL & MG2_4_18PL & \
                    MG2_4_19PL & MG2_4_110PL & MG2_4_111PL & MG2_4_112PL & \
                    MG2_4_113PL & MG2_4_114PL & MG2_4_115PL & MG2_4_116PL)
// End of MG2_4:
// Beginning of MG25:
#if (G2_1PL >= G2_5PL) || (G2_1PL == 0)
#define  MG2_5_11PL    ~(1 << 0)
#else
#define  MG2_5_11PL    0xFFFF
#endif

#if (G2_2PL >= G2_5PL) || (G2_2PL == 0)
#define  MG2_5_12PL    ~(1 << 1)
#else
#define  MG2_5_12PL    0xFFFF
#endif

#if (G2_3PL >= G2_5PL) || (G2_3PL == 0)
#define  MG2_5_13PL    ~(1 << 2)
#else
#define  MG2_5_13PL    0xFFFF
#endif

#if (G2_4PL >= G2_5PL) || (G2_4PL == 0)
#define  MG2_5_14PL    ~(1 << 3)
#else
#define  MG2_5_14PL    0xFFFF
#endif

#if (G2_6PL >= G2_5PL) || (G2_6PL == 0)
#define  MG2_5_16PL    ~(1 << 5)
#else
#define  MG2_5_16PL    0xFFFF
#endif

#if (G2_7PL >= G2_5PL) || (G2_7PL == 0)
#define  MG2_5_17PL    ~(1 << 6)
#else
#define  MG2_5_17PL    0xFFFF
#endif

#if (G2_8PL >= G2_5PL) || (G2_8PL == 0)
#define  MG2_5_18PL    ~(1 << 7)
#else
#define  MG2_5_18PL    0xFFFF
#endif

#if (G2_9PL >= G2_5PL) || (G2_9PL == 0)
#define  MG2_5_19PL    ~(1 << 8)
#else
#define  MG2_5_19PL    0xFFFF
#endif

#if (G2_10PL >= G2_5PL) || (G2_10PL == 0)
#define  MG2_5_110PL    ~(1 << 9)
#else
#define  MG2_5_110PL    0xFFFF
#endif

#if (G2_11PL >= G2_5PL) || (G2_11PL == 0)
#define  MG2_5_111PL    ~(1 << 10)
#else
#define  MG2_5_111PL    0xFFFF
#endif

#if (G2_12PL >= G2_5PL) || (G2_12PL == 0)
#define  MG2_5_112PL    ~(1 << 11)
#else
#define  MG2_5_112PL    0xFFFF
#endif

#if (G2_13PL >= G2_5PL) || (G2_13PL == 0)
#define  MG2_5_113PL    ~(1 << 12)
#else
#define  MG2_5_113PL    0xFFFF
#endif

#if (G2_14PL >= G2_5PL) || (G2_14PL == 0)
#define  MG2_5_114PL    ~(1 << 13)
#else
#define  MG2_5_114PL    0xFFFF
#endif

#if (G2_15PL >= G2_5PL) || (G2_15PL == 0)
#define  MG2_5_115PL    ~(1 << 14)
#else
#define  MG2_5_115PL    0xFFFF
#endif

#if (G2_16PL >= G2_5PL) || (G2_16PL == 0)
#define  MG2_5_116PL    ~(1 << 15)
#else
#define  MG2_5_116PL    0xFFFF
#endif

#define  MG2_5_15PL	0xFFEF
#define  MG2_5    (MG2_5_11PL & MG2_5_12PL & MG2_5_13PL & MG2_5_14PL & \
                    MG2_5_15PL & MG2_5_16PL & MG2_5_17PL & MG2_5_18PL & \
                    MG2_5_19PL & MG2_5_110PL & MG2_5_111PL & MG2_5_112PL & \
                    MG2_5_113PL & MG2_5_114PL & MG2_5_115PL & MG2_5_116PL)
// End of MG2_5:
// Beginning of MG26:
#if (G2_1PL >= G2_6PL) || (G2_1PL == 0)
#define  MG2_6_11PL    ~(1 << 0)
#else
#define  MG2_6_11PL    0xFFFF
#endif

#if (G2_2PL >= G2_6PL) || (G2_2PL == 0)
#define  MG2_6_12PL    ~(1 << 1)
#else
#define  MG2_6_12PL    0xFFFF
#endif

#if (G2_3PL >= G2_6PL) || (G2_3PL == 0)
#define  MG2_6_13PL    ~(1 << 2)
#else
#define  MG2_6_13PL    0xFFFF
#endif

#if (G2_4PL >= G2_6PL) || (G2_4PL == 0)
#define  MG2_6_14PL    ~(1 << 3)
#else
#define  MG2_6_14PL    0xFFFF
#endif

#if (G2_5PL >= G2_6PL) || (G2_5PL == 0)
#define  MG2_6_15PL    ~(1 << 4)
#else
#define  MG2_6_15PL    0xFFFF
#endif

#if (G2_7PL >= G2_6PL) || (G2_7PL == 0)
#define  MG2_6_17PL    ~(1 << 6)
#else
#define  MG2_6_17PL    0xFFFF
#endif

#if (G2_8PL >= G2_6PL) || (G2_8PL == 0)
#define  MG2_6_18PL    ~(1 << 7)
#else
#define  MG2_6_18PL    0xFFFF
#endif

#if (G2_9PL >= G2_6PL) || (G2_9PL == 0)
#define  MG2_6_19PL    ~(1 << 8)
#else
#define  MG2_6_19PL    0xFFFF
#endif

#if (G2_10PL >= G2_6PL) || (G2_10PL == 0)
#define  MG2_6_110PL    ~(1 << 9)
#else
#define  MG2_6_110PL    0xFFFF
#endif

#if (G2_11PL >= G2_6PL) || (G2_11PL == 0)
#define  MG2_6_111PL    ~(1 << 10)
#else
#define  MG2_6_111PL    0xFFFF
#endif

#if (G2_12PL >= G2_6PL) || (G2_12PL == 0)
#define  MG2_6_112PL    ~(1 << 11)
#else
#define  MG2_6_112PL    0xFFFF
#endif

#if (G2_13PL >= G2_6PL) || (G2_13PL == 0)
#define  MG2_6_113PL    ~(1 << 12)
#else
#define  MG2_6_113PL    0xFFFF
#endif

#if (G2_14PL >= G2_6PL) || (G2_14PL == 0)
#define  MG2_6_114PL    ~(1 << 13)
#else
#define  MG2_6_114PL    0xFFFF
#endif

#if (G2_15PL >= G2_6PL) || (G2_15PL == 0)
#define  MG2_6_115PL    ~(1 << 14)
#else
#define  MG2_6_115PL    0xFFFF
#endif

#if (G2_16PL >= G2_6PL) || (G2_16PL == 0)
#define  MG2_6_116PL    ~(1 << 15)
#else
#define  MG2_6_116PL    0xFFFF
#endif

#define  MG2_6_16PL	0xFFDF
#define  MG2_6    (MG2_6_11PL & MG2_6_12PL & MG2_6_13PL & MG2_6_14PL & \
                    MG2_6_15PL & MG2_6_16PL & MG2_6_17PL & MG2_6_18PL & \
                    MG2_6_19PL & MG2_6_110PL & MG2_6_111PL & MG2_6_112PL & \
                    MG2_6_113PL & MG2_6_114PL & MG2_6_115PL & MG2_6_116PL)
// End of MG2_6:
// Beginning of MG27:
#if (G2_1PL >= G2_7PL) || (G2_1PL == 0)
#define  MG2_7_11PL    ~(1 << 0)
#else
#define  MG2_7_11PL    0xFFFF
#endif

#if (G2_2PL >= G2_7PL) || (G2_2PL == 0)
#define  MG2_7_12PL    ~(1 << 1)
#else
#define  MG2_7_12PL    0xFFFF
#endif

#if (G2_3PL >= G2_7PL) || (G2_3PL == 0)
#define  MG2_7_13PL    ~(1 << 2)
#else
#define  MG2_7_13PL    0xFFFF
#endif

#if (G2_4PL >= G2_7PL) || (G2_4PL == 0)
#define  MG2_7_14PL    ~(1 << 3)
#else
#define  MG2_7_14PL    0xFFFF
#endif

#if (G2_5PL >= G2_7PL) || (G2_5PL == 0)
#define  MG2_7_15PL    ~(1 << 4)
#else
#define  MG2_7_15PL    0xFFFF
#endif

#if (G2_6PL >= G2_7PL) || (G2_6PL == 0)
#define  MG2_7_16PL    ~(1 << 5)
#else
#define  MG2_7_16PL    0xFFFF
#endif

#if (G2_8PL >= G2_7PL) || (G2_8PL == 0)
#define  MG2_7_18PL    ~(1 << 7)
#else
#define  MG2_7_18PL    0xFFFF
#endif

#if (G2_9PL >= G2_7PL) || (G2_9PL == 0)
#define  MG2_7_19PL    ~(1 << 8)
#else
#define  MG2_7_19PL    0xFFFF
#endif

#if (G2_10PL >= G2_7PL) || (G2_10PL == 0)
#define  MG2_7_110PL    ~(1 << 9)
#else
#define  MG2_7_110PL    0xFFFF
#endif

#if (G2_11PL >= G2_7PL) || (G2_11PL == 0)
#define  MG2_7_111PL    ~(1 << 10)
#else
#define  MG2_7_111PL    0xFFFF
#endif

#if (G2_12PL >= G2_7PL) || (G2_12PL == 0)
#define  MG2_7_112PL    ~(1 << 11)
#else
#define  MG2_7_112PL    0xFFFF
#endif

#if (G2_13PL >= G2_7PL) || (G2_13PL == 0)
#define  MG2_7_113PL    ~(1 << 12)
#else
#define  MG2_7_113PL    0xFFFF
#endif

#if (G2_14PL >= G2_7PL) || (G2_14PL == 0)
#define  MG2_7_114PL    ~(1 << 13)
#else
#define  MG2_7_114PL    0xFFFF
#endif

#if (G2_15PL >= G2_7PL) || (G2_15PL == 0)
#define  MG2_7_115PL    ~(1 << 14)
#else
#define  MG2_7_115PL    0xFFFF
#endif

#if (G2_16PL >= G2_7PL) || (G2_16PL == 0)
#define  MG2_7_116PL    ~(1 << 15)
#else
#define  MG2_7_116PL    0xFFFF
#endif

#define  MG2_7_17PL	0xFFBF
#define  MG2_7    (MG2_7_11PL & MG2_7_12PL & MG2_7_13PL & MG2_7_14PL & \
                    MG2_7_15PL & MG2_7_16PL & MG2_7_17PL & MG2_7_18PL & \
                    MG2_7_19PL & MG2_7_110PL & MG2_7_111PL & MG2_7_112PL & \
                    MG2_7_113PL & MG2_7_114PL & MG2_7_115PL & MG2_7_116PL)
// End of MG2_7:
// Beginning of MG28:
#if (G2_1PL >= G2_8PL) || (G2_1PL == 0)
#define  MG2_8_11PL    ~(1 << 0)
#else
#define  MG2_8_11PL    0xFFFF
#endif

#if (G2_2PL >= G2_8PL) || (G2_2PL == 0)
#define  MG2_8_12PL    ~(1 << 1)
#else
#define  MG2_8_12PL    0xFFFF
#endif

#if (G2_3PL >= G2_8PL) || (G2_3PL == 0)
#define  MG2_8_13PL    ~(1 << 2)
#else
#define  MG2_8_13PL    0xFFFF
#endif

#if (G2_4PL >= G2_8PL) || (G2_4PL == 0)
#define  MG2_8_14PL    ~(1 << 3)
#else
#define  MG2_8_14PL    0xFFFF
#endif

#if (G2_5PL >= G2_8PL) || (G2_5PL == 0)
#define  MG2_8_15PL    ~(1 << 4)
#else
#define  MG2_8_15PL    0xFFFF
#endif

#if (G2_6PL >= G2_8PL) || (G2_6PL == 0)
#define  MG2_8_16PL    ~(1 << 5)
#else
#define  MG2_8_16PL    0xFFFF
#endif

#if (G2_7PL >= G2_8PL) || (G2_7PL == 0)
#define  MG2_8_17PL    ~(1 << 6)
#else
#define  MG2_8_17PL    0xFFFF
#endif

#if (G2_9PL >= G2_8PL) || (G2_9PL == 0)
#define  MG2_8_19PL    ~(1 << 8)
#else
#define  MG2_8_19PL    0xFFFF
#endif

#if (G2_10PL >= G2_8PL) || (G2_10PL == 0)
#define  MG2_8_110PL    ~(1 << 9)
#else
#define  MG2_8_110PL    0xFFFF
#endif

#if (G2_11PL >= G2_8PL) || (G2_11PL == 0)
#define  MG2_8_111PL    ~(1 << 10)
#else
#define  MG2_8_111PL    0xFFFF
#endif

#if (G2_12PL >= G2_8PL) || (G2_12PL == 0)
#define  MG2_8_112PL    ~(1 << 11)
#else
#define  MG2_8_112PL    0xFFFF
#endif

#if (G2_13PL >= G2_8PL) || (G2_13PL == 0)
#define  MG2_8_113PL    ~(1 << 12)
#else
#define  MG2_8_113PL    0xFFFF
#endif

#if (G2_14PL >= G2_8PL) || (G2_14PL == 0)
#define  MG2_8_114PL    ~(1 << 13)
#else
#define  MG2_8_114PL    0xFFFF
#endif

#if (G2_15PL >= G2_8PL) || (G2_15PL == 0)
#define  MG2_8_115PL    ~(1 << 14)
#else
#define  MG2_8_115PL    0xFFFF
#endif

#if (G2_16PL >= G2_8PL) || (G2_16PL == 0)
#define  MG2_8_116PL    ~(1 << 15)
#else
#define  MG2_8_116PL    0xFFFF
#endif

#define  MG2_8_18PL	0xFF7F
#define  MG2_8    (MG2_8_11PL & MG2_8_12PL & MG2_8_13PL & MG2_8_14PL & \
                    MG2_8_15PL & MG2_8_16PL & MG2_8_17PL & MG2_8_18PL & \
                    MG2_8_19PL & MG2_8_110PL & MG2_8_111PL & MG2_8_112PL & \
                    MG2_8_113PL & MG2_8_114PL & MG2_8_115PL & MG2_8_116PL)
// End of MG2_8:
// Beginning of MG29:
#if (G2_1PL >= G2_9PL) || (G2_1PL == 0)
#define  MG2_9_11PL    ~(1 << 0)
#else
#define  MG2_9_11PL    0xFFFF
#endif

#if (G2_2PL >= G2_9PL) || (G2_2PL == 0)
#define  MG2_9_12PL    ~(1 << 1)
#else
#define  MG2_9_12PL    0xFFFF
#endif

#if (G2_3PL >= G2_9PL) || (G2_3PL == 0)
#define  MG2_9_13PL    ~(1 << 2)
#else
#define  MG2_9_13PL    0xFFFF
#endif

#if (G2_4PL >= G2_9PL) || (G2_4PL == 0)
#define  MG2_9_14PL    ~(1 << 3)
#else
#define  MG2_9_14PL    0xFFFF
#endif

#if (G2_5PL >= G2_9PL) || (G2_5PL == 0)
#define  MG2_9_15PL    ~(1 << 4)
#else
#define  MG2_9_15PL    0xFFFF
#endif

#if (G2_6PL >= G2_9PL) || (G2_6PL == 0)
#define  MG2_9_16PL    ~(1 << 5)
#else
#define  MG2_9_16PL    0xFFFF
#endif

#if (G2_7PL >= G2_9PL) || (G2_7PL == 0)
#define  MG2_9_17PL    ~(1 << 6)
#else
#define  MG2_9_17PL    0xFFFF
#endif

#if (G2_8PL >= G2_9PL) || (G2_8PL == 0)
#define  MG2_9_18PL    ~(1 << 7)
#else
#define  MG2_9_18PL    0xFFFF
#endif

#if (G2_10PL >= G2_9PL) || (G2_10PL == 0)
#define  MG2_9_110PL    ~(1 << 9)
#else
#define  MG2_9_110PL    0xFFFF
#endif

#if (G2_11PL >= G2_9PL) || (G2_11PL == 0)
#define  MG2_9_111PL    ~(1 << 10)
#else
#define  MG2_9_111PL    0xFFFF
#endif

#if (G2_12PL >= G2_9PL) || (G2_12PL == 0)
#define  MG2_9_112PL    ~(1 << 11)
#else
#define  MG2_9_112PL    0xFFFF
#endif

#if (G2_13PL >= G2_9PL) || (G2_13PL == 0)
#define  MG2_9_113PL    ~(1 << 12)
#else
#define  MG2_9_113PL    0xFFFF
#endif

#if (G2_14PL >= G2_9PL) || (G2_14PL == 0)
#define  MG2_9_114PL    ~(1 << 13)
#else
#define  MG2_9_114PL    0xFFFF
#endif

#if (G2_15PL >= G2_9PL) || (G2_15PL == 0)
#define  MG2_9_115PL    ~(1 << 14)
#else
#define  MG2_9_115PL    0xFFFF
#endif

#if (G2_16PL >= G2_9PL) || (G2_16PL == 0)
#define  MG2_9_116PL    ~(1 << 15)
#else
#define  MG2_9_116PL    0xFFFF
#endif

#define  MG2_9_19PL	0xFEFF
#define  MG2_9    (MG2_9_11PL & MG2_9_12PL & MG2_9_13PL & MG2_9_14PL & \
                    MG2_9_15PL & MG2_9_16PL & MG2_9_17PL & MG2_9_18PL & \
                    MG2_9_19PL & MG2_9_110PL & MG2_9_111PL & MG2_9_112PL & \
                    MG2_9_113PL & MG2_9_114PL & MG2_9_115PL & MG2_9_116PL)
// End of MG2_9:
// Beginning of MG210:
#if (G2_1PL >= G2_10PL) || (G2_1PL == 0)
#define  MG2_10_11PL    ~(1 << 0)
#else
#define  MG2_10_11PL    0xFFFF
#endif

#if (G2_2PL >= G2_10PL) || (G2_2PL == 0)
#define  MG2_10_12PL    ~(1 << 1)
#else
#define  MG2_10_12PL    0xFFFF
#endif

#if (G2_3PL >= G2_10PL) || (G2_3PL == 0)
#define  MG2_10_13PL    ~(1 << 2)
#else
#define  MG2_10_13PL    0xFFFF
#endif

#if (G2_4PL >= G2_10PL) || (G2_4PL == 0)
#define  MG2_10_14PL    ~(1 << 3)
#else
#define  MG2_10_14PL    0xFFFF
#endif

#if (G2_5PL >= G2_10PL) || (G2_5PL == 0)
#define  MG2_10_15PL    ~(1 << 4)
#else
#define  MG2_10_15PL    0xFFFF
#endif

#if (G2_6PL >= G2_10PL) || (G2_6PL == 0)
#define  MG2_10_16PL    ~(1 << 5)
#else
#define  MG2_10_16PL    0xFFFF
#endif

#if (G2_7PL >= G2_10PL) || (G2_7PL == 0)
#define  MG2_10_17PL    ~(1 << 6)
#else
#define  MG2_10_17PL    0xFFFF
#endif

#if (G2_8PL >= G2_10PL) || (G2_8PL == 0)
#define  MG2_10_18PL    ~(1 << 7)
#else
#define  MG2_10_18PL    0xFFFF
#endif

#if (G2_9PL >= G2_10PL) || (G2_9PL == 0)
#define  MG2_10_19PL    ~(1 << 8)
#else
#define  MG2_10_19PL    0xFFFF
#endif

#if (G2_11PL >= G2_10PL) || (G2_11PL == 0)
#define  MG2_10_111PL    ~(1 << 10)
#else
#define  MG2_10_111PL    0xFFFF
#endif

#if (G2_12PL >= G2_10PL) || (G2_12PL == 0)
#define  MG2_10_112PL    ~(1 << 11)
#else
#define  MG2_10_112PL    0xFFFF
#endif

#if (G2_13PL >= G2_10PL) || (G2_13PL == 0)
#define  MG2_10_113PL    ~(1 << 12)
#else
#define  MG2_10_113PL    0xFFFF
#endif

#if (G2_14PL >= G2_10PL) || (G2_14PL == 0)
#define  MG2_10_114PL    ~(1 << 13)
#else
#define  MG2_10_114PL    0xFFFF
#endif

#if (G2_15PL >= G2_10PL) || (G2_15PL == 0)
#define  MG2_10_115PL    ~(1 << 14)
#else
#define  MG2_10_115PL    0xFFFF
#endif

#if (G2_16PL >= G2_10PL) || (G2_16PL == 0)
#define  MG2_10_116PL    ~(1 << 15)
#else
#define  MG2_10_116PL    0xFFFF
#endif

#define  MG2_10_110PL	0xFDFF
#define  MG2_10    (MG2_10_11PL & MG2_10_12PL & MG2_10_13PL & MG2_10_14PL & \
                    MG2_10_15PL & MG2_10_16PL & MG2_10_17PL & MG2_10_18PL & \
                    MG2_10_19PL & MG2_10_110PL & MG2_10_111PL & MG2_10_112PL & \
                    MG2_10_113PL & MG2_10_114PL & MG2_10_115PL & MG2_10_116PL)
// End of MG2_10:
// Beginning of MG211:
#if (G2_1PL >= G2_11PL) || (G2_1PL == 0)
#define  MG2_11_11PL    ~(1 << 0)
#else
#define  MG2_11_11PL    0xFFFF
#endif

#if (G2_2PL >= G2_11PL) || (G2_2PL == 0)
#define  MG2_11_12PL    ~(1 << 1)
#else
#define  MG2_11_12PL    0xFFFF
#endif

#if (G2_3PL >= G2_11PL) || (G2_3PL == 0)
#define  MG2_11_13PL    ~(1 << 2)
#else
#define  MG2_11_13PL    0xFFFF
#endif

#if (G2_4PL >= G2_11PL) || (G2_4PL == 0)
#define  MG2_11_14PL    ~(1 << 3)
#else
#define  MG2_11_14PL    0xFFFF
#endif

#if (G2_5PL >= G2_11PL) || (G2_5PL == 0)
#define  MG2_11_15PL    ~(1 << 4)
#else
#define  MG2_11_15PL    0xFFFF
#endif

#if (G2_6PL >= G2_11PL) || (G2_6PL == 0)
#define  MG2_11_16PL    ~(1 << 5)
#else
#define  MG2_11_16PL    0xFFFF
#endif

#if (G2_7PL >= G2_11PL) || (G2_7PL == 0)
#define  MG2_11_17PL    ~(1 << 6)
#else
#define  MG2_11_17PL    0xFFFF
#endif

#if (G2_8PL >= G2_11PL) || (G2_8PL == 0)
#define  MG2_11_18PL    ~(1 << 7)
#else
#define  MG2_11_18PL    0xFFFF
#endif

#if (G2_9PL >= G2_11PL) || (G2_9PL == 0)
#define  MG2_11_19PL    ~(1 << 8)
#else
#define  MG2_11_19PL    0xFFFF
#endif

#if (G2_10PL >= G2_11PL) || (G2_10PL == 0)
#define  MG2_11_110PL    ~(1 << 9)
#else
#define  MG2_11_110PL    0xFFFF
#endif

#if (G2_12PL >= G2_11PL) || (G2_12PL == 0)
#define  MG2_11_112PL    ~(1 << 11)
#else
#define  MG2_11_112PL    0xFFFF
#endif

#if (G2_13PL >= G2_11PL) || (G2_13PL == 0)
#define  MG2_11_113PL    ~(1 << 12)
#else
#define  MG2_11_113PL    0xFFFF
#endif

#if (G2_14PL >= G2_11PL) || (G2_14PL == 0)
#define  MG2_11_114PL    ~(1 << 13)
#else
#define  MG2_11_114PL    0xFFFF
#endif

#if (G2_15PL >= G2_11PL) || (G2_15PL == 0)
#define  MG2_11_115PL    ~(1 << 14)
#else
#define  MG2_11_115PL    0xFFFF
#endif

#if (G2_16PL >= G2_11PL) || (G2_16PL == 0)
#define  MG2_11_116PL    ~(1 << 15)
#else
#define  MG2_11_116PL    0xFFFF
#endif

#define  MG2_11_111PL	0xFBFF
#define  MG2_11    (MG2_11_11PL & MG2_11_12PL & MG2_11_13PL & MG2_11_14PL & \
                    MG2_11_15PL & MG2_11_16PL & MG2_11_17PL & MG2_11_18PL & \
                    MG2_11_19PL & MG2_11_110PL & MG2_11_111PL & MG2_11_112PL & \
                    MG2_11_113PL & MG2_11_114PL & MG2_11_115PL & MG2_11_116PL)
// End of MG2_11:
// Beginning of MG212:
#if (G2_1PL >= G2_12PL) || (G2_1PL == 0)
#define  MG2_12_11PL    ~(1 << 0)
#else
#define  MG2_12_11PL    0xFFFF
#endif

#if (G2_2PL >= G2_12PL) || (G2_2PL == 0)
#define  MG2_12_12PL    ~(1 << 1)
#else
#define  MG2_12_12PL    0xFFFF
#endif

#if (G2_3PL >= G2_12PL) || (G2_3PL == 0)
#define  MG2_12_13PL    ~(1 << 2)
#else
#define  MG2_12_13PL    0xFFFF
#endif

#if (G2_4PL >= G2_12PL) || (G2_4PL == 0)
#define  MG2_12_14PL    ~(1 << 3)
#else
#define  MG2_12_14PL    0xFFFF
#endif

#if (G2_5PL >= G2_12PL) || (G2_5PL == 0)
#define  MG2_12_15PL    ~(1 << 4)
#else
#define  MG2_12_15PL    0xFFFF
#endif

#if (G2_6PL >= G2_12PL) || (G2_6PL == 0)
#define  MG2_12_16PL    ~(1 << 5)
#else
#define  MG2_12_16PL    0xFFFF
#endif

#if (G2_7PL >= G2_12PL) || (G2_7PL == 0)
#define  MG2_12_17PL    ~(1 << 6)
#else
#define  MG2_12_17PL    0xFFFF
#endif

#if (G2_8PL >= G2_12PL) || (G2_8PL == 0)
#define  MG2_12_18PL    ~(1 << 7)
#else
#define  MG2_12_18PL    0xFFFF
#endif

#if (G2_9PL >= G2_12PL) || (G2_9PL == 0)
#define  MG2_12_19PL    ~(1 << 8)
#else
#define  MG2_12_19PL    0xFFFF
#endif

#if (G2_10PL >= G2_12PL) || (G2_10PL == 0)
#define  MG2_12_110PL    ~(1 << 9)
#else
#define  MG2_12_110PL    0xFFFF
#endif

#if (G2_11PL >= G2_12PL) || (G2_11PL == 0)
#define  MG2_12_111PL    ~(1 << 10)
#else
#define  MG2_12_111PL    0xFFFF
#endif

#if (G2_13PL >= G2_12PL) || (G2_13PL == 0)
#define  MG2_12_113PL    ~(1 << 12)
#else
#define  MG2_12_113PL    0xFFFF
#endif

#if (G2_14PL >= G2_12PL) || (G2_14PL == 0)
#define  MG2_12_114PL    ~(1 << 13)
#else
#define  MG2_12_114PL    0xFFFF
#endif

#if (G2_15PL >= G2_12PL) || (G2_15PL == 0)
#define  MG2_12_115PL    ~(1 << 14)
#else
#define  MG2_12_115PL    0xFFFF
#endif

#if (G2_16PL >= G2_12PL) || (G2_16PL == 0)
#define  MG2_12_116PL    ~(1 << 15)
#else
#define  MG2_12_116PL    0xFFFF
#endif

#define  MG2_12_112PL	0xF7FF
#define  MG2_12    (MG2_12_11PL & MG2_12_12PL & MG2_12_13PL & MG2_12_14PL & \
                    MG2_12_15PL & MG2_12_16PL & MG2_12_17PL & MG2_12_18PL & \
                    MG2_12_19PL & MG2_12_110PL & MG2_12_111PL & MG2_12_112PL & \
                    MG2_12_113PL & MG2_12_114PL & MG2_12_115PL & MG2_12_116PL)
// End of MG2_12:
// Beginning of MG213:
#if (G2_1PL >= G2_13PL) || (G2_1PL == 0)
#define  MG2_13_11PL    ~(1 << 0)
#else
#define  MG2_13_11PL    0xFFFF
#endif

#if (G2_2PL >= G2_13PL) || (G2_2PL == 0)
#define  MG2_13_12PL    ~(1 << 1)
#else
#define  MG2_13_12PL    0xFFFF
#endif

#if (G2_3PL >= G2_13PL) || (G2_3PL == 0)
#define  MG2_13_13PL    ~(1 << 2)
#else
#define  MG2_13_13PL    0xFFFF
#endif

#if (G2_4PL >= G2_13PL) || (G2_4PL == 0)
#define  MG2_13_14PL    ~(1 << 3)
#else
#define  MG2_13_14PL    0xFFFF
#endif

#if (G2_5PL >= G2_13PL) || (G2_5PL == 0)
#define  MG2_13_15PL    ~(1 << 4)
#else
#define  MG2_13_15PL    0xFFFF
#endif

#if (G2_6PL >= G2_13PL) || (G2_6PL == 0)
#define  MG2_13_16PL    ~(1 << 5)
#else
#define  MG2_13_16PL    0xFFFF
#endif

#if (G2_7PL >= G2_13PL) || (G2_7PL == 0)
#define  MG2_13_17PL    ~(1 << 6)
#else
#define  MG2_13_17PL    0xFFFF
#endif

#if (G2_8PL >= G2_13PL) || (G2_8PL == 0)
#define  MG2_13_18PL    ~(1 << 7)
#else
#define  MG2_13_18PL    0xFFFF
#endif

#if (G2_9PL >= G2_13PL) || (G2_9PL == 0)
#define  MG2_13_19PL    ~(1 << 8)
#else
#define  MG2_13_19PL    0xFFFF
#endif

#if (G2_10PL >= G2_13PL) || (G2_10PL == 0)
#define  MG2_13_110PL    ~(1 << 9)
#else
#define  MG2_13_110PL    0xFFFF
#endif

#if (G2_11PL >= G2_13PL) || (G2_11PL == 0)
#define  MG2_13_111PL    ~(1 << 10)
#else
#define  MG2_13_111PL    0xFFFF
#endif

#if (G2_12PL >= G2_13PL) || (G2_12PL == 0)
#define  MG2_13_112PL    ~(1 << 11)
#else
#define  MG2_13_112PL    0xFFFF
#endif

#if (G2_14PL >= G2_13PL) || (G2_14PL == 0)
#define  MG2_13_114PL    ~(1 << 13)
#else
#define  MG2_13_114PL    0xFFFF
#endif

#if (G2_15PL >= G2_13PL) || (G2_15PL == 0)
#define  MG2_13_115PL    ~(1 << 14)
#else
#define  MG2_13_115PL    0xFFFF
#endif

#if (G2_16PL >= G2_13PL) || (G2_16PL == 0)
#define  MG2_13_116PL    ~(1 << 15)
#else
#define  MG2_13_116PL    0xFFFF
#endif

#define  MG2_13_113PL	0xEFFF
#define  MG2_13    (MG2_13_11PL & MG2_13_12PL & MG2_13_13PL & MG2_13_14PL & \
                    MG2_13_15PL & MG2_13_16PL & MG2_13_17PL & MG2_13_18PL & \
                    MG2_13_19PL & MG2_13_110PL & MG2_13_111PL & MG2_13_112PL & \
                    MG2_13_113PL & MG2_13_114PL & MG2_13_115PL & MG2_13_116PL)
// End of MG2_13:
// Beginning of MG214:
#if (G2_1PL >= G2_14PL) || (G2_1PL == 0)
#define  MG2_14_11PL    ~(1 << 0)
#else
#define  MG2_14_11PL    0xFFFF
#endif

#if (G2_2PL >= G2_14PL) || (G2_2PL == 0)
#define  MG2_14_12PL    ~(1 << 1)
#else
#define  MG2_14_12PL    0xFFFF
#endif

#if (G2_3PL >= G2_14PL) || (G2_3PL == 0)
#define  MG2_14_13PL    ~(1 << 2)
#else
#define  MG2_14_13PL    0xFFFF
#endif

#if (G2_4PL >= G2_14PL) || (G2_4PL == 0)
#define  MG2_14_14PL    ~(1 << 3)
#else
#define  MG2_14_14PL    0xFFFF
#endif

#if (G2_5PL >= G2_14PL) || (G2_5PL == 0)
#define  MG2_14_15PL    ~(1 << 4)
#else
#define  MG2_14_15PL    0xFFFF
#endif

#if (G2_6PL >= G2_14PL) || (G2_6PL == 0)
#define  MG2_14_16PL    ~(1 << 5)
#else
#define  MG2_14_16PL    0xFFFF
#endif

#if (G2_7PL >= G2_14PL) || (G2_7PL == 0)
#define  MG2_14_17PL    ~(1 << 6)
#else
#define  MG2_14_17PL    0xFFFF
#endif

#if (G2_8PL >= G2_14PL) || (G2_8PL == 0)
#define  MG2_14_18PL    ~(1 << 7)
#else
#define  MG2_14_18PL    0xFFFF
#endif

#if (G2_9PL >= G2_14PL) || (G2_9PL == 0)
#define  MG2_14_19PL    ~(1 << 8)
#else
#define  MG2_14_19PL    0xFFFF
#endif

#if (G2_10PL >= G2_14PL) || (G2_10PL == 0)
#define  MG2_14_110PL    ~(1 << 9)
#else
#define  MG2_14_110PL    0xFFFF
#endif

#if (G2_11PL >= G2_14PL) || (G2_11PL == 0)
#define  MG2_14_111PL    ~(1 << 10)
#else
#define  MG2_14_111PL    0xFFFF
#endif

#if (G2_12PL >= G2_14PL) || (G2_12PL == 0)
#define  MG2_14_112PL    ~(1 << 11)
#else
#define  MG2_14_112PL    0xFFFF
#endif

#if (G2_13PL >= G2_14PL) || (G2_13PL == 0)
#define  MG2_14_113PL    ~(1 << 12)
#else
#define  MG2_14_113PL    0xFFFF
#endif

#if (G2_15PL >= G2_14PL) || (G2_15PL == 0)
#define  MG2_14_115PL    ~(1 << 14)
#else
#define  MG2_14_115PL    0xFFFF
#endif

#if (G2_16PL >= G2_14PL) || (G2_16PL == 0)
#define  MG2_14_116PL    ~(1 << 15)
#else
#define  MG2_14_116PL    0xFFFF
#endif

#define  MG2_14_114PL	0xDFFF
#define  MG2_14    (MG2_14_11PL & MG2_14_12PL & MG2_14_13PL & MG2_14_14PL & \
                    MG2_14_15PL & MG2_14_16PL & MG2_14_17PL & MG2_14_18PL & \
                    MG2_14_19PL & MG2_14_110PL & MG2_14_111PL & MG2_14_112PL & \
                    MG2_14_113PL & MG2_14_114PL & MG2_14_115PL & MG2_14_116PL)
// End of MG2_14:
// Beginning of MG215:
#if (G2_1PL >= G2_15PL) || (G2_1PL == 0)
#define  MG2_15_11PL    ~(1 << 0)
#else
#define  MG2_15_11PL    0xFFFF
#endif

#if (G2_2PL >= G2_15PL) || (G2_2PL == 0)
#define  MG2_15_12PL    ~(1 << 1)
#else
#define  MG2_15_12PL    0xFFFF
#endif

#if (G2_3PL >= G2_15PL) || (G2_3PL == 0)
#define  MG2_15_13PL    ~(1 << 2)
#else
#define  MG2_15_13PL    0xFFFF
#endif

#if (G2_4PL >= G2_15PL) || (G2_4PL == 0)
#define  MG2_15_14PL    ~(1 << 3)
#else
#define  MG2_15_14PL    0xFFFF
#endif

#if (G2_5PL >= G2_15PL) || (G2_5PL == 0)
#define  MG2_15_15PL    ~(1 << 4)
#else
#define  MG2_15_15PL    0xFFFF
#endif

#if (G2_6PL >= G2_15PL) || (G2_6PL == 0)
#define  MG2_15_16PL    ~(1 << 5)
#else
#define  MG2_15_16PL    0xFFFF
#endif

#if (G2_7PL >= G2_15PL) || (G2_7PL == 0)
#define  MG2_15_17PL    ~(1 << 6)
#else
#define  MG2_15_17PL    0xFFFF
#endif

#if (G2_8PL >= G2_15PL) || (G2_8PL == 0)
#define  MG2_15_18PL    ~(1 << 7)
#else
#define  MG2_15_18PL    0xFFFF
#endif

#if (G2_9PL >= G2_15PL) || (G2_9PL == 0)
#define  MG2_15_19PL    ~(1 << 8)
#else
#define  MG2_15_19PL    0xFFFF
#endif

#if (G2_10PL >= G2_15PL) || (G2_10PL == 0)
#define  MG2_15_110PL    ~(1 << 9)
#else
#define  MG2_15_110PL    0xFFFF
#endif

#if (G2_11PL >= G2_15PL) || (G2_11PL == 0)
#define  MG2_15_111PL    ~(1 << 10)
#else
#define  MG2_15_111PL    0xFFFF
#endif

#if (G2_12PL >= G2_15PL) || (G2_12PL == 0)
#define  MG2_15_112PL    ~(1 << 11)
#else
#define  MG2_15_112PL    0xFFFF
#endif

#if (G2_13PL >= G2_15PL) || (G2_13PL == 0)
#define  MG2_15_113PL    ~(1 << 12)
#else
#define  MG2_15_113PL    0xFFFF
#endif

#if (G2_14PL >= G2_15PL) || (G2_14PL == 0)
#define  MG2_15_114PL    ~(1 << 13)
#else
#define  MG2_15_114PL    0xFFFF
#endif

#if (G2_16PL >= G2_15PL) || (G2_16PL == 0)
#define  MG2_15_116PL    ~(1 << 15)
#else
#define  MG2_15_116PL    0xFFFF
#endif

#define  MG2_15_115PL	0xBFFF
#define  MG2_15    (MG2_15_11PL & MG2_15_12PL & MG2_15_13PL & MG2_15_14PL & \
                    MG2_15_15PL & MG2_15_16PL & MG2_15_17PL & MG2_15_18PL & \
                    MG2_15_19PL & MG2_15_110PL & MG2_15_111PL & MG2_15_112PL & \
                    MG2_15_113PL & MG2_15_114PL & MG2_15_115PL & MG2_15_116PL)
// End of MG2_15:
// Beginning of MG216:
#if (G2_1PL >= G2_16PL) || (G2_1PL == 0)
#define  MG2_16_11PL    ~(1 << 0)
#else
#define  MG2_16_11PL    0xFFFF
#endif

#if (G2_2PL >= G2_16PL) || (G2_2PL == 0)
#define  MG2_16_12PL    ~(1 << 1)
#else
#define  MG2_16_12PL    0xFFFF
#endif

#if (G2_3PL >= G2_16PL) || (G2_3PL == 0)
#define  MG2_16_13PL    ~(1 << 2)
#else
#define  MG2_16_13PL    0xFFFF
#endif

#if (G2_4PL >= G2_16PL) || (G2_4PL == 0)
#define  MG2_16_14PL    ~(1 << 3)
#else
#define  MG2_16_14PL    0xFFFF
#endif

#if (G2_5PL >= G2_16PL) || (G2_5PL == 0)
#define  MG2_16_15PL    ~(1 << 4)
#else
#define  MG2_16_15PL    0xFFFF
#endif

#if (G2_6PL >= G2_16PL) || (G2_6PL == 0)
#define  MG2_16_16PL    ~(1 << 5)
#else
#define  MG2_16_16PL    0xFFFF
#endif

#if (G2_7PL >= G2_16PL) || (G2_7PL == 0)
#define  MG2_16_17PL    ~(1 << 6)
#else
#define  MG2_16_17PL    0xFFFF
#endif

#if (G2_8PL >= G2_16PL) || (G2_8PL == 0)
#define  MG2_16_18PL    ~(1 << 7)
#else
#define  MG2_16_18PL    0xFFFF
#endif

#if (G2_9PL >= G2_16PL) || (G2_9PL == 0)
#define  MG2_16_19PL    ~(1 << 8)
#else
#define  MG2_16_19PL    0xFFFF
#endif

#if (G2_10PL >= G2_16PL) || (G2_10PL == 0)
#define  MG2_16_110PL    ~(1 << 9)
#else
#define  MG2_16_110PL    0xFFFF
#endif

#if (G2_11PL >= G2_16PL) || (G2_11PL == 0)
#define  MG2_16_111PL    ~(1 << 10)
#else
#define  MG2_16_111PL    0xFFFF
#endif

#if (G2_12PL >= G2_16PL) || (G2_12PL == 0)
#define  MG2_16_112PL    ~(1 << 11)
#else
#define  MG2_16_112PL    0xFFFF
#endif

#if (G2_13PL >= G2_16PL) || (G2_13PL == 0)
#define  MG2_16_113PL    ~(1 << 12)
#else
#define  MG2_16_113PL    0xFFFF
#endif

#if (G2_14PL >= G2_16PL) || (G2_14PL == 0)
#define  MG2_16_114PL    ~(1 << 13)
#else
#define  MG2_16_114PL    0xFFFF
#endif

#if (G2_15PL >= G2_16PL) || (G2_15PL == 0)
#define  MG2_16_115PL    ~(1 << 14)
#else
#define  MG2_16_115PL    0xFFFF
#endif

#define  MG2_16_116PL	0x7FFF
#define  MG2_16    (MG2_16_11PL & MG2_16_12PL & MG2_16_13PL & MG2_16_14PL & \
                    MG2_16_15PL & MG2_16_16PL & MG2_16_17PL & MG2_16_18PL & \
                    MG2_16_19PL & MG2_16_110PL & MG2_16_111PL & MG2_16_112PL & \
                    MG2_16_113PL & MG2_16_114PL & MG2_16_115PL & MG2_16_116PL)
// End of MG2_16:


//-------------------------------------------------------------------------------
// Automatically generate PIEIER3 interrupt masks MG31 to MG316:

// Beginning of MG31:
#if (G3_2PL >= G3_1PL) || (G3_2PL == 0)
#define  MG3_1_12PL    ~(1 << 1)
#else
#define  MG3_1_12PL    0xFFFF
#endif

#if (G3_3PL >= G3_1PL) || (G3_3PL == 0)
#define  MG3_1_13PL    ~(1 << 2)
#else
#define  MG3_1_13PL    0xFFFF
#endif

#if (G3_4PL >= G3_1PL) || (G3_4PL == 0)
#define  MG3_1_14PL    ~(1 << 3)
#else
#define  MG3_1_14PL    0xFFFF
#endif

#if (G3_5PL >= G3_1PL) || (G3_5PL == 0)
#define  MG3_1_15PL    ~(1 << 4)
#else
#define  MG3_1_15PL    0xFFFF
#endif

#if (G3_6PL >= G3_1PL) || (G3_6PL == 0)
#define  MG3_1_16PL    ~(1 << 5)
#else
#define  MG3_1_16PL    0xFFFF
#endif

#if (G3_7PL >= G3_1PL) || (G3_7PL == 0)
#define  MG3_1_17PL    ~(1 << 6)
#else
#define  MG3_1_17PL    0xFFFF
#endif

#if (G3_8PL >= G3_1PL) || (G3_8PL == 0)
#define  MG3_1_18PL    ~(1 << 7)
#else
#define  MG3_1_18PL    0xFFFF
#endif

#if (G3_9PL >= G3_1PL) || (G3_9PL == 0)
#define  MG3_1_19PL    ~(1 << 8)
#else
#define  MG3_1_19PL    0xFFFF
#endif

#if (G3_10PL >= G3_1PL) || (G3_10PL == 0)
#define  MG3_1_110PL    ~(1 << 9)
#else
#define  MG3_1_110PL    0xFFFF
#endif

#if (G3_11PL >= G3_1PL) || (G3_11PL == 0)
#define  MG3_1_111PL    ~(1 << 10)
#else
#define  MG3_1_111PL    0xFFFF
#endif

#if (G3_12PL >= G3_1PL) || (G3_12PL == 0)
#define  MG3_1_112PL    ~(1 << 11)
#else
#define  MG3_1_112PL    0xFFFF
#endif

#if (G3_13PL >= G3_1PL) || (G3_13PL == 0)
#define  MG3_1_113PL    ~(1 << 12)
#else
#define  MG3_1_113PL    0xFFFF
#endif

#if (G3_14PL >= G3_1PL) || (G3_14PL == 0)
#define  MG3_1_114PL    ~(1 << 13)
#else
#define  MG3_1_114PL    0xFFFF
#endif

#if (G3_15PL >= G3_1PL) || (G3_15PL == 0)
#define  MG3_1_115PL    ~(1 << 14)
#else
#define  MG3_1_115PL    0xFFFF
#endif

#if (G3_16PL >= G3_1PL) || (G3_16PL == 0)
#define  MG3_1_116PL    ~(1 << 15)
#else
#define  MG3_1_116PL    0xFFFF
#endif

#define  MG3_1_11PL	0xFFFE
#define  MG3_1    (MG3_1_11PL & MG3_1_12PL & MG3_1_13PL & MG3_1_14PL & \
                    MG3_1_15PL & MG3_1_16PL & MG3_1_17PL & MG3_1_18PL & \
                    MG3_1_19PL & MG3_1_110PL & MG3_1_111PL & MG3_1_112PL & \
                    MG3_1_113PL & MG3_1_114PL & MG3_1_115PL & MG3_1_116PL)
// End of MG3_1:
// Beginning of MG32:
#if (G3_1PL >= G3_2PL) || (G3_1PL == 0)
#define  MG3_2_11PL    ~(1 << 0)
#else
#define  MG3_2_11PL    0xFFFF
#endif

#if (G3_3PL >= G3_2PL) || (G3_3PL == 0)
#define  MG3_2_13PL    ~(1 << 2)
#else
#define  MG3_2_13PL    0xFFFF
#endif

#if (G3_4PL >= G3_2PL) || (G3_4PL == 0)
#define  MG3_2_14PL    ~(1 << 3)
#else
#define  MG3_2_14PL    0xFFFF
#endif

#if (G3_5PL >= G3_2PL) || (G3_5PL == 0)
#define  MG3_2_15PL    ~(1 << 4)
#else
#define  MG3_2_15PL    0xFFFF
#endif

#if (G3_6PL >= G3_2PL) || (G3_6PL == 0)
#define  MG3_2_16PL    ~(1 << 5)
#else
#define  MG3_2_16PL    0xFFFF
#endif

#if (G3_7PL >= G3_2PL) || (G3_7PL == 0)
#define  MG3_2_17PL    ~(1 << 6)
#else
#define  MG3_2_17PL    0xFFFF
#endif

#if (G3_8PL >= G3_2PL) || (G3_8PL == 0)
#define  MG3_2_18PL    ~(1 << 7)
#else
#define  MG3_2_18PL    0xFFFF
#endif

#if (G3_9PL >= G3_2PL) || (G3_9PL == 0)
#define  MG3_2_19PL    ~(1 << 8)
#else
#define  MG3_2_19PL    0xFFFF
#endif

#if (G3_10PL >= G3_2PL) || (G3_10PL == 0)
#define  MG3_2_110PL    ~(1 << 9)
#else
#define  MG3_2_110PL    0xFFFF
#endif

#if (G3_11PL >= G3_2PL) || (G3_11PL == 0)
#define  MG3_2_111PL    ~(1 << 10)
#else
#define  MG3_2_111PL    0xFFFF
#endif

#if (G3_12PL >= G3_2PL) || (G3_12PL == 0)
#define  MG3_2_112PL    ~(1 << 11)
#else
#define  MG3_2_112PL    0xFFFF
#endif

#if (G3_13PL >= G3_2PL) || (G3_13PL == 0)
#define  MG3_2_113PL    ~(1 << 12)
#else
#define  MG3_2_113PL    0xFFFF
#endif

#if (G3_14PL >= G3_2PL) || (G3_14PL == 0)
#define  MG3_2_114PL    ~(1 << 13)
#else
#define  MG3_2_114PL    0xFFFF
#endif

#if (G3_15PL >= G3_2PL) || (G3_15PL == 0)
#define  MG3_2_115PL    ~(1 << 14)
#else
#define  MG3_2_115PL    0xFFFF
#endif

#if (G3_16PL >= G3_2PL) || (G3_16PL == 0)
#define  MG3_2_116PL    ~(1 << 15)
#else
#define  MG3_2_116PL    0xFFFF
#endif

#define  MG3_2_12PL	0xFFFD
#define  MG3_2    (MG3_2_11PL & MG3_2_12PL & MG3_2_13PL & MG3_2_14PL & \
                    MG3_2_15PL & MG3_2_16PL & MG3_2_17PL & MG3_2_18PL & \
                    MG3_2_19PL & MG3_2_110PL & MG3_2_111PL & MG3_2_112PL & \
                    MG3_2_113PL & MG3_2_114PL & MG3_2_115PL & MG3_2_116PL)
// End of MG3_2:
// Beginning of MG33:
#if (G3_1PL >= G3_3PL) || (G3_1PL == 0)
#define  MG3_3_11PL    ~(1 << 0)
#else
#define  MG3_3_11PL    0xFFFF
#endif

#if (G3_2PL >= G3_3PL) || (G3_2PL == 0)
#define  MG3_3_12PL    ~(1 << 1)
#else
#define  MG3_3_12PL    0xFFFF
#endif

#if (G3_4PL >= G3_3PL) || (G3_4PL == 0)
#define  MG3_3_14PL    ~(1 << 3)
#else
#define  MG3_3_14PL    0xFFFF
#endif

#if (G3_5PL >= G3_3PL) || (G3_5PL == 0)
#define  MG3_3_15PL    ~(1 << 4)
#else
#define  MG3_3_15PL    0xFFFF
#endif

#if (G3_6PL >= G3_3PL) || (G3_6PL == 0)
#define  MG3_3_16PL    ~(1 << 5)
#else
#define  MG3_3_16PL    0xFFFF
#endif

#if (G3_7PL >= G3_3PL) || (G3_7PL == 0)
#define  MG3_3_17PL    ~(1 << 6)
#else
#define  MG3_3_17PL    0xFFFF
#endif

#if (G3_8PL >= G3_3PL) || (G3_8PL == 0)
#define  MG3_3_18PL    ~(1 << 7)
#else
#define  MG3_3_18PL    0xFFFF
#endif

#if (G3_9PL >= G3_3PL) || (G3_9PL == 0)
#define  MG3_3_19PL    ~(1 << 8)
#else
#define  MG3_3_19PL    0xFFFF
#endif

#if (G3_10PL >= G3_3PL) || (G3_10PL == 0)
#define  MG3_3_110PL    ~(1 << 9)
#else
#define  MG3_3_110PL    0xFFFF
#endif

#if (G3_11PL >= G3_3PL) || (G3_11PL == 0)
#define  MG3_3_111PL    ~(1 << 10)
#else
#define  MG3_3_111PL    0xFFFF
#endif

#if (G3_12PL >= G3_3PL) || (G3_12PL == 0)
#define  MG3_3_112PL    ~(1 << 11)
#else
#define  MG3_3_112PL    0xFFFF
#endif

#if (G3_13PL >= G3_3PL) || (G3_13PL == 0)
#define  MG3_3_113PL    ~(1 << 12)
#else
#define  MG3_3_113PL    0xFFFF
#endif

#if (G3_14PL >= G3_3PL) || (G3_14PL == 0)
#define  MG3_3_114PL    ~(1 << 13)
#else
#define  MG3_3_114PL    0xFFFF
#endif

#if (G3_15PL >= G3_3PL) || (G3_15PL == 0)
#define  MG3_3_115PL    ~(1 << 14)
#else
#define  MG3_3_115PL    0xFFFF
#endif

#if (G3_16PL >= G3_3PL) || (G3_16PL == 0)
#define  MG3_3_116PL    ~(1 << 15)
#else
#define  MG3_3_116PL    0xFFFF
#endif

#define  MG3_3_13PL	0xFFFB
#define  MG3_3    (MG3_3_11PL & MG3_3_12PL & MG3_3_13PL & MG3_3_14PL & \
                    MG3_3_15PL & MG3_3_16PL & MG3_3_17PL & MG3_3_18PL & \
                    MG3_3_19PL & MG3_3_110PL & MG3_3_111PL & MG3_3_112PL & \
                    MG3_3_113PL & MG3_3_114PL & MG3_3_115PL & MG3_3_116PL)
// End of MG3_3:
// Beginning of MG34:
#if (G3_1PL >= G3_4PL) || (G3_1PL == 0)
#define  MG3_4_11PL    ~(1 << 0)
#else
#define  MG3_4_11PL    0xFFFF
#endif

#if (G3_2PL >= G3_4PL) || (G3_2PL == 0)
#define  MG3_4_12PL    ~(1 << 1)
#else
#define  MG3_4_12PL    0xFFFF
#endif

#if (G3_3PL >= G3_4PL) || (G3_3PL == 0)
#define  MG3_4_13PL    ~(1 << 2)
#else
#define  MG3_4_13PL    0xFFFF
#endif

#if (G3_5PL >= G3_4PL) || (G3_5PL == 0)
#define  MG3_4_15PL    ~(1 << 4)
#else
#define  MG3_4_15PL    0xFFFF
#endif

#if (G3_6PL >= G3_4PL) || (G3_6PL == 0)
#define  MG3_4_16PL    ~(1 << 5)
#else
#define  MG3_4_16PL    0xFFFF
#endif

#if (G3_7PL >= G3_4PL) || (G3_7PL == 0)
#define  MG3_4_17PL    ~(1 << 6)
#else
#define  MG3_4_17PL    0xFFFF
#endif

#if (G3_8PL >= G3_4PL) || (G3_8PL == 0)
#define  MG3_4_18PL    ~(1 << 7)
#else
#define  MG3_4_18PL    0xFFFF
#endif

#if (G3_9PL >= G3_4PL) || (G3_9PL == 0)
#define  MG3_4_19PL    ~(1 << 8)
#else
#define  MG3_4_19PL    0xFFFF
#endif

#if (G3_10PL >= G3_4PL) || (G3_10PL == 0)
#define  MG3_4_110PL    ~(1 << 9)
#else
#define  MG3_4_110PL    0xFFFF
#endif

#if (G3_11PL >= G3_4PL) || (G3_11PL == 0)
#define  MG3_4_111PL    ~(1 << 10)
#else
#define  MG3_4_111PL    0xFFFF
#endif

#if (G3_12PL >= G3_4PL) || (G3_12PL == 0)
#define  MG3_4_112PL    ~(1 << 11)
#else
#define  MG3_4_112PL    0xFFFF
#endif

#if (G3_13PL >= G3_4PL) || (G3_13PL == 0)
#define  MG3_4_113PL    ~(1 << 12)
#else
#define  MG3_4_113PL    0xFFFF
#endif

#if (G3_14PL >= G3_4PL) || (G3_14PL == 0)
#define  MG3_4_114PL    ~(1 << 13)
#else
#define  MG3_4_114PL    0xFFFF
#endif

#if (G3_15PL >= G3_4PL) || (G3_15PL == 0)
#define  MG3_4_115PL    ~(1 << 14)
#else
#define  MG3_4_115PL    0xFFFF
#endif

#if (G3_16PL >= G3_4PL) || (G3_16PL == 0)
#define  MG3_4_116PL    ~(1 << 15)
#else
#define  MG3_4_116PL    0xFFFF
#endif

#define  MG3_4_14PL	0xFFF7
#define  MG3_4    (MG3_4_11PL & MG3_4_12PL & MG3_4_13PL & MG3_4_14PL & \
                    MG3_4_15PL & MG3_4_16PL & MG3_4_17PL & MG3_4_18PL & \
                    MG3_4_19PL & MG3_4_110PL & MG3_4_111PL & MG3_4_112PL & \
                    MG3_4_113PL & MG3_4_114PL & MG3_4_115PL & MG3_4_116PL)
// End of MG3_4:
// Beginning of MG35:
#if (G3_1PL >= G3_5PL) || (G3_1PL == 0)
#define  MG3_5_11PL    ~(1 << 0)
#else
#define  MG3_5_11PL    0xFFFF
#endif

#if (G3_2PL >= G3_5PL) || (G3_2PL == 0)
#define  MG3_5_12PL    ~(1 << 1)
#else
#define  MG3_5_12PL    0xFFFF
#endif

#if (G3_3PL >= G3_5PL) || (G3_3PL == 0)
#define  MG3_5_13PL    ~(1 << 2)
#else
#define  MG3_5_13PL    0xFFFF
#endif

#if (G3_4PL >= G3_5PL) || (G3_4PL == 0)
#define  MG3_5_14PL    ~(1 << 3)
#else
#define  MG3_5_14PL    0xFFFF
#endif

#if (G3_6PL >= G3_5PL) || (G3_6PL == 0)
#define  MG3_5_16PL    ~(1 << 5)
#else
#define  MG3_5_16PL    0xFFFF
#endif

#if (G3_7PL >= G3_5PL) || (G3_7PL == 0)
#define  MG3_5_17PL    ~(1 << 6)
#else
#define  MG3_5_17PL    0xFFFF
#endif

#if (G3_8PL >= G3_5PL) || (G3_8PL == 0)
#define  MG3_5_18PL    ~(1 << 7)
#else
#define  MG3_5_18PL    0xFFFF
#endif

#if (G3_9PL >= G3_5PL) || (G3_9PL == 0)
#define  MG3_5_19PL    ~(1 << 8)
#else
#define  MG3_5_19PL    0xFFFF
#endif

#if (G3_10PL >= G3_5PL) || (G3_10PL == 0)
#define  MG3_5_110PL    ~(1 << 9)
#else
#define  MG3_5_110PL    0xFFFF
#endif

#if (G3_11PL >= G3_5PL) || (G3_11PL == 0)
#define  MG3_5_111PL    ~(1 << 10)
#else
#define  MG3_5_111PL    0xFFFF
#endif

#if (G3_12PL >= G3_5PL) || (G3_12PL == 0)
#define  MG3_5_112PL    ~(1 << 11)
#else
#define  MG3_5_112PL    0xFFFF
#endif

#if (G3_13PL >= G3_5PL) || (G3_13PL == 0)
#define  MG3_5_113PL    ~(1 << 12)
#else
#define  MG3_5_113PL    0xFFFF
#endif

#if (G3_14PL >= G3_5PL) || (G3_14PL == 0)
#define  MG3_5_114PL    ~(1 << 13)
#else
#define  MG3_5_114PL    0xFFFF
#endif

#if (G3_15PL >= G3_5PL) || (G3_15PL == 0)
#define  MG3_5_115PL    ~(1 << 14)
#else
#define  MG3_5_115PL    0xFFFF
#endif

#if (G3_16PL >= G3_5PL) || (G3_16PL == 0)
#define  MG3_5_116PL    ~(1 << 15)
#else
#define  MG3_5_116PL    0xFFFF
#endif

#define  MG3_5_15PL	0xFFEF
#define  MG3_5    (MG3_5_11PL & MG3_5_12PL & MG3_5_13PL & MG3_5_14PL & \
                    MG3_5_15PL & MG3_5_16PL & MG3_5_17PL & MG3_5_18PL & \
                    MG3_5_19PL & MG3_5_110PL & MG3_5_111PL & MG3_5_112PL & \
                    MG3_5_113PL & MG3_5_114PL & MG3_5_115PL & MG3_5_116PL)
// End of MG3_5:
// Beginning of MG36:
#if (G3_1PL >= G3_6PL) || (G3_1PL == 0)
#define  MG3_6_11PL    ~(1 << 0)
#else
#define  MG3_6_11PL    0xFFFF
#endif

#if (G3_2PL >= G3_6PL) || (G3_2PL == 0)
#define  MG3_6_12PL    ~(1 << 1)
#else
#define  MG3_6_12PL    0xFFFF
#endif

#if (G3_3PL >= G3_6PL) || (G3_3PL == 0)
#define  MG3_6_13PL    ~(1 << 2)
#else
#define  MG3_6_13PL    0xFFFF
#endif

#if (G3_4PL >= G3_6PL) || (G3_4PL == 0)
#define  MG3_6_14PL    ~(1 << 3)
#else
#define  MG3_6_14PL    0xFFFF
#endif

#if (G3_5PL >= G3_6PL) || (G3_5PL == 0)
#define  MG3_6_15PL    ~(1 << 4)
#else
#define  MG3_6_15PL    0xFFFF
#endif

#if (G3_7PL >= G3_6PL) || (G3_7PL == 0)
#define  MG3_6_17PL    ~(1 << 6)
#else
#define  MG3_6_17PL    0xFFFF
#endif

#if (G3_8PL >= G3_6PL) || (G3_8PL == 0)
#define  MG3_6_18PL    ~(1 << 7)
#else
#define  MG3_6_18PL    0xFFFF
#endif

#if (G3_9PL >= G3_6PL) || (G3_9PL == 0)
#define  MG3_6_19PL    ~(1 << 8)
#else
#define  MG3_6_19PL    0xFFFF
#endif

#if (G3_10PL >= G3_6PL) || (G3_10PL == 0)
#define  MG3_6_110PL    ~(1 << 9)
#else
#define  MG3_6_110PL    0xFFFF
#endif

#if (G3_11PL >= G3_6PL) || (G3_11PL == 0)
#define  MG3_6_111PL    ~(1 << 10)
#else
#define  MG3_6_111PL    0xFFFF
#endif

#if (G3_12PL >= G3_6PL) || (G3_12PL == 0)
#define  MG3_6_112PL    ~(1 << 11)
#else
#define  MG3_6_112PL    0xFFFF
#endif

#if (G3_13PL >= G3_6PL) || (G3_13PL == 0)
#define  MG3_6_113PL    ~(1 << 12)
#else
#define  MG3_6_113PL    0xFFFF
#endif

#if (G3_14PL >= G3_6PL) || (G3_14PL == 0)
#define  MG3_6_114PL    ~(1 << 13)
#else
#define  MG3_6_114PL    0xFFFF
#endif

#if (G3_15PL >= G3_6PL) || (G3_15PL == 0)
#define  MG3_6_115PL    ~(1 << 14)
#else
#define  MG3_6_115PL    0xFFFF
#endif

#if (G3_16PL >= G3_6PL) || (G3_16PL == 0)
#define  MG3_6_116PL    ~(1 << 15)
#else
#define  MG3_6_116PL    0xFFFF
#endif

#define  MG3_6_16PL	0xFFDF
#define  MG3_6    (MG3_6_11PL & MG3_6_12PL & MG3_6_13PL & MG3_6_14PL & \
                    MG3_6_15PL & MG3_6_16PL & MG3_6_17PL & MG3_6_18PL & \
                    MG3_6_19PL & MG3_6_110PL & MG3_6_111PL & MG3_6_112PL & \
                    MG3_6_113PL & MG3_6_114PL & MG3_6_115PL & MG3_6_116PL)
// End of MG3_6:
// Beginning of MG37:
#if (G3_1PL >= G3_7PL) || (G3_1PL == 0)
#define  MG3_7_11PL    ~(1 << 0)
#else
#define  MG3_7_11PL    0xFFFF
#endif

#if (G3_2PL >= G3_7PL) || (G3_2PL == 0)
#define  MG3_7_12PL    ~(1 << 1)
#else
#define  MG3_7_12PL    0xFFFF
#endif

#if (G3_3PL >= G3_7PL) || (G3_3PL == 0)
#define  MG3_7_13PL    ~(1 << 2)
#else
#define  MG3_7_13PL    0xFFFF
#endif

#if (G3_4PL >= G3_7PL) || (G3_4PL == 0)
#define  MG3_7_14PL    ~(1 << 3)
#else
#define  MG3_7_14PL    0xFFFF
#endif

#if (G3_5PL >= G3_7PL) || (G3_5PL == 0)
#define  MG3_7_15PL    ~(1 << 4)
#else
#define  MG3_7_15PL    0xFFFF
#endif

#if (G3_6PL >= G3_7PL) || (G3_6PL == 0)
#define  MG3_7_16PL    ~(1 << 5)
#else
#define  MG3_7_16PL    0xFFFF
#endif

#if (G3_8PL >= G3_7PL) || (G3_8PL == 0)
#define  MG3_7_18PL    ~(1 << 7)
#else
#define  MG3_7_18PL    0xFFFF
#endif

#if (G3_9PL >= G3_7PL) || (G3_9PL == 0)
#define  MG3_7_19PL    ~(1 << 8)
#else
#define  MG3_7_19PL    0xFFFF
#endif

#if (G3_10PL >= G3_7PL) || (G3_10PL == 0)
#define  MG3_7_110PL    ~(1 << 9)
#else
#define  MG3_7_110PL    0xFFFF
#endif

#if (G3_11PL >= G3_7PL) || (G3_11PL == 0)
#define  MG3_7_111PL    ~(1 << 10)
#else
#define  MG3_7_111PL    0xFFFF
#endif

#if (G3_12PL >= G3_7PL) || (G3_12PL == 0)
#define  MG3_7_112PL    ~(1 << 11)
#else
#define  MG3_7_112PL    0xFFFF
#endif

#if (G3_13PL >= G3_7PL) || (G3_13PL == 0)
#define  MG3_7_113PL    ~(1 << 12)
#else
#define  MG3_7_113PL    0xFFFF
#endif

#if (G3_14PL >= G3_7PL) || (G3_14PL == 0)
#define  MG3_7_114PL    ~(1 << 13)
#else
#define  MG3_7_114PL    0xFFFF
#endif

#if (G3_15PL >= G3_7PL) || (G3_15PL == 0)
#define  MG3_7_115PL    ~(1 << 14)
#else
#define  MG3_7_115PL    0xFFFF
#endif

#if (G3_16PL >= G3_7PL) || (G3_16PL == 0)
#define  MG3_7_116PL    ~(1 << 15)
#else
#define  MG3_7_116PL    0xFFFF
#endif

#define  MG3_7_17PL	0xFFBF
#define  MG3_7    (MG3_7_11PL & MG3_7_12PL & MG3_7_13PL & MG3_7_14PL & \
                    MG3_7_15PL & MG3_7_16PL & MG3_7_17PL & MG3_7_18PL & \
                    MG3_7_19PL & MG3_7_110PL & MG3_7_111PL & MG3_7_112PL & \
                    MG3_7_113PL & MG3_7_114PL & MG3_7_115PL & MG3_7_116PL)
// End of MG3_7:
// Beginning of MG38:
#if (G3_1PL >= G3_8PL) || (G3_1PL == 0)
#define  MG3_8_11PL    ~(1 << 0)
#else
#define  MG3_8_11PL    0xFFFF
#endif

#if (G3_2PL >= G3_8PL) || (G3_2PL == 0)
#define  MG3_8_12PL    ~(1 << 1)
#else
#define  MG3_8_12PL    0xFFFF
#endif

#if (G3_3PL >= G3_8PL) || (G3_3PL == 0)
#define  MG3_8_13PL    ~(1 << 2)
#else
#define  MG3_8_13PL    0xFFFF
#endif

#if (G3_4PL >= G3_8PL) || (G3_4PL == 0)
#define  MG3_8_14PL    ~(1 << 3)
#else
#define  MG3_8_14PL    0xFFFF
#endif

#if (G3_5PL >= G3_8PL) || (G3_5PL == 0)
#define  MG3_8_15PL    ~(1 << 4)
#else
#define  MG3_8_15PL    0xFFFF
#endif

#if (G3_6PL >= G3_8PL) || (G3_6PL == 0)
#define  MG3_8_16PL    ~(1 << 5)
#else
#define  MG3_8_16PL    0xFFFF
#endif

#if (G3_7PL >= G3_8PL) || (G3_7PL == 0)
#define  MG3_8_17PL    ~(1 << 6)
#else
#define  MG3_8_17PL    0xFFFF
#endif

#if (G3_9PL >= G3_8PL) || (G3_9PL == 0)
#define  MG3_8_19PL    ~(1 << 8)
#else
#define  MG3_8_19PL    0xFFFF
#endif

#if (G3_10PL >= G3_8PL) || (G3_10PL == 0)
#define  MG3_8_110PL    ~(1 << 9)
#else
#define  MG3_8_110PL    0xFFFF
#endif

#if (G3_11PL >= G3_8PL) || (G3_11PL == 0)
#define  MG3_8_111PL    ~(1 << 10)
#else
#define  MG3_8_111PL    0xFFFF
#endif

#if (G3_12PL >= G3_8PL) || (G3_12PL == 0)
#define  MG3_8_112PL    ~(1 << 11)
#else
#define  MG3_8_112PL    0xFFFF
#endif

#if (G3_13PL >= G3_8PL) || (G3_13PL == 0)
#define  MG3_8_113PL    ~(1 << 12)
#else
#define  MG3_8_113PL    0xFFFF
#endif

#if (G3_14PL >= G3_8PL) || (G3_14PL == 0)
#define  MG3_8_114PL    ~(1 << 13)
#else
#define  MG3_8_114PL    0xFFFF
#endif

#if (G3_15PL >= G3_8PL) || (G3_15PL == 0)
#define  MG3_8_115PL    ~(1 << 14)
#else
#define  MG3_8_115PL    0xFFFF
#endif

#if (G3_16PL >= G3_8PL) || (G3_16PL == 0)
#define  MG3_8_116PL    ~(1 << 15)
#else
#define  MG3_8_116PL    0xFFFF
#endif

#define  MG3_8_18PL	0xFF7F
#define  MG3_8    (MG3_8_11PL & MG3_8_12PL & MG3_8_13PL & MG3_8_14PL & \
                    MG3_8_15PL & MG3_8_16PL & MG3_8_17PL & MG3_8_18PL & \
                    MG3_8_19PL & MG3_8_110PL & MG3_8_111PL & MG3_8_112PL & \
                    MG3_8_113PL & MG3_8_114PL & MG3_8_115PL & MG3_8_116PL)
// End of MG3_8:
// Beginning of MG39:
#if (G3_1PL >= G3_9PL) || (G3_1PL == 0)
#define  MG3_9_11PL    ~(1 << 0)
#else
#define  MG3_9_11PL    0xFFFF
#endif

#if (G3_2PL >= G3_9PL) || (G3_2PL == 0)
#define  MG3_9_12PL    ~(1 << 1)
#else
#define  MG3_9_12PL    0xFFFF
#endif

#if (G3_3PL >= G3_9PL) || (G3_3PL == 0)
#define  MG3_9_13PL    ~(1 << 2)
#else
#define  MG3_9_13PL    0xFFFF
#endif

#if (G3_4PL >= G3_9PL) || (G3_4PL == 0)
#define  MG3_9_14PL    ~(1 << 3)
#else
#define  MG3_9_14PL    0xFFFF
#endif

#if (G3_5PL >= G3_9PL) || (G3_5PL == 0)
#define  MG3_9_15PL    ~(1 << 4)
#else
#define  MG3_9_15PL    0xFFFF
#endif

#if (G3_6PL >= G3_9PL) || (G3_6PL == 0)
#define  MG3_9_16PL    ~(1 << 5)
#else
#define  MG3_9_16PL    0xFFFF
#endif

#if (G3_7PL >= G3_9PL) || (G3_7PL == 0)
#define  MG3_9_17PL    ~(1 << 6)
#else
#define  MG3_9_17PL    0xFFFF
#endif

#if (G3_8PL >= G3_9PL) || (G3_8PL == 0)
#define  MG3_9_18PL    ~(1 << 7)
#else
#define  MG3_9_18PL    0xFFFF
#endif

#if (G3_10PL >= G3_9PL) || (G3_10PL == 0)
#define  MG3_9_110PL    ~(1 << 9)
#else
#define  MG3_9_110PL    0xFFFF
#endif

#if (G3_11PL >= G3_9PL) || (G3_11PL == 0)
#define  MG3_9_111PL    ~(1 << 10)
#else
#define  MG3_9_111PL    0xFFFF
#endif

#if (G3_12PL >= G3_9PL) || (G3_12PL == 0)
#define  MG3_9_112PL    ~(1 << 11)
#else
#define  MG3_9_112PL    0xFFFF
#endif

#if (G3_13PL >= G3_9PL) || (G3_13PL == 0)
#define  MG3_9_113PL    ~(1 << 12)
#else
#define  MG3_9_113PL    0xFFFF
#endif

#if (G3_14PL >= G3_9PL) || (G3_14PL == 0)
#define  MG3_9_114PL    ~(1 << 13)
#else
#define  MG3_9_114PL    0xFFFF
#endif

#if (G3_15PL >= G3_9PL) || (G3_15PL == 0)
#define  MG3_9_115PL    ~(1 << 14)
#else
#define  MG3_9_115PL    0xFFFF
#endif

#if (G3_16PL >= G3_9PL) || (G3_16PL == 0)
#define  MG3_9_116PL    ~(1 << 15)
#else
#define  MG3_9_116PL    0xFFFF
#endif

#define  MG3_9_19PL	0xFEFF
#define  MG3_9    (MG3_9_11PL & MG3_9_12PL & MG3_9_13PL & MG3_9_14PL & \
                    MG3_9_15PL & MG3_9_16PL & MG3_9_17PL & MG3_9_18PL & \
                    MG3_9_19PL & MG3_9_110PL & MG3_9_111PL & MG3_9_112PL & \
                    MG3_9_113PL & MG3_9_114PL & MG3_9_115PL & MG3_9_116PL)
// End of MG3_9:
// Beginning of MG310:
#if (G3_1PL >= G3_10PL) || (G3_1PL == 0)
#define  MG3_10_11PL    ~(1 << 0)
#else
#define  MG3_10_11PL    0xFFFF
#endif

#if (G3_2PL >= G3_10PL) || (G3_2PL == 0)
#define  MG3_10_12PL    ~(1 << 1)
#else
#define  MG3_10_12PL    0xFFFF
#endif

#if (G3_3PL >= G3_10PL) || (G3_3PL == 0)
#define  MG3_10_13PL    ~(1 << 2)
#else
#define  MG3_10_13PL    0xFFFF
#endif

#if (G3_4PL >= G3_10PL) || (G3_4PL == 0)
#define  MG3_10_14PL    ~(1 << 3)
#else
#define  MG3_10_14PL    0xFFFF
#endif

#if (G3_5PL >= G3_10PL) || (G3_5PL == 0)
#define  MG3_10_15PL    ~(1 << 4)
#else
#define  MG3_10_15PL    0xFFFF
#endif

#if (G3_6PL >= G3_10PL) || (G3_6PL == 0)
#define  MG3_10_16PL    ~(1 << 5)
#else
#define  MG3_10_16PL    0xFFFF
#endif

#if (G3_7PL >= G3_10PL) || (G3_7PL == 0)
#define  MG3_10_17PL    ~(1 << 6)
#else
#define  MG3_10_17PL    0xFFFF
#endif

#if (G3_8PL >= G3_10PL) || (G3_8PL == 0)
#define  MG3_10_18PL    ~(1 << 7)
#else
#define  MG3_10_18PL    0xFFFF
#endif

#if (G3_9PL >= G3_10PL) || (G3_9PL == 0)
#define  MG3_10_19PL    ~(1 << 8)
#else
#define  MG3_10_19PL    0xFFFF
#endif

#if (G3_11PL >= G3_10PL) || (G3_11PL == 0)
#define  MG3_10_111PL    ~(1 << 10)
#else
#define  MG3_10_111PL    0xFFFF
#endif

#if (G3_12PL >= G3_10PL) || (G3_12PL == 0)
#define  MG3_10_112PL    ~(1 << 11)
#else
#define  MG3_10_112PL    0xFFFF
#endif

#if (G3_13PL >= G3_10PL) || (G3_13PL == 0)
#define  MG3_10_113PL    ~(1 << 12)
#else
#define  MG3_10_113PL    0xFFFF
#endif

#if (G3_14PL >= G3_10PL) || (G3_14PL == 0)
#define  MG3_10_114PL    ~(1 << 13)
#else
#define  MG3_10_114PL    0xFFFF
#endif

#if (G3_15PL >= G3_10PL) || (G3_15PL == 0)
#define  MG3_10_115PL    ~(1 << 14)
#else
#define  MG3_10_115PL    0xFFFF
#endif

#if (G3_16PL >= G3_10PL) || (G3_16PL == 0)
#define  MG3_10_116PL    ~(1 << 15)
#else
#define  MG3_10_116PL    0xFFFF
#endif

#define  MG3_10_110PL	0xFDFF
#define  MG3_10    (MG3_10_11PL & MG3_10_12PL & MG3_10_13PL & MG3_10_14PL & \
                    MG3_10_15PL & MG3_10_16PL & MG3_10_17PL & MG3_10_18PL & \
                    MG3_10_19PL & MG3_10_110PL & MG3_10_111PL & MG3_10_112PL & \
                    MG3_10_113PL & MG3_10_114PL & MG3_10_115PL & MG3_10_116PL)
// End of MG3_10:
// Beginning of MG311:
#if (G3_1PL >= G3_11PL) || (G3_1PL == 0)
#define  MG3_11_11PL    ~(1 << 0)
#else
#define  MG3_11_11PL    0xFFFF
#endif

#if (G3_2PL >= G3_11PL) || (G3_2PL == 0)
#define  MG3_11_12PL    ~(1 << 1)
#else
#define  MG3_11_12PL    0xFFFF
#endif

#if (G3_3PL >= G3_11PL) || (G3_3PL == 0)
#define  MG3_11_13PL    ~(1 << 2)
#else
#define  MG3_11_13PL    0xFFFF
#endif

#if (G3_4PL >= G3_11PL) || (G3_4PL == 0)
#define  MG3_11_14PL    ~(1 << 3)
#else
#define  MG3_11_14PL    0xFFFF
#endif

#if (G3_5PL >= G3_11PL) || (G3_5PL == 0)
#define  MG3_11_15PL    ~(1 << 4)
#else
#define  MG3_11_15PL    0xFFFF
#endif

#if (G3_6PL >= G3_11PL) || (G3_6PL == 0)
#define  MG3_11_16PL    ~(1 << 5)
#else
#define  MG3_11_16PL    0xFFFF
#endif

#if (G3_7PL >= G3_11PL) || (G3_7PL == 0)
#define  MG3_11_17PL    ~(1 << 6)
#else
#define  MG3_11_17PL    0xFFFF
#endif

#if (G3_8PL >= G3_11PL) || (G3_8PL == 0)
#define  MG3_11_18PL    ~(1 << 7)
#else
#define  MG3_11_18PL    0xFFFF
#endif

#if (G3_9PL >= G3_11PL) || (G3_9PL == 0)
#define  MG3_11_19PL    ~(1 << 8)
#else
#define  MG3_11_19PL    0xFFFF
#endif

#if (G3_10PL >= G3_11PL) || (G3_10PL == 0)
#define  MG3_11_110PL    ~(1 << 9)
#else
#define  MG3_11_110PL    0xFFFF
#endif

#if (G3_12PL >= G3_11PL) || (G3_12PL == 0)
#define  MG3_11_112PL    ~(1 << 11)
#else
#define  MG3_11_112PL    0xFFFF
#endif

#if (G3_13PL >= G3_11PL) || (G3_13PL == 0)
#define  MG3_11_113PL    ~(1 << 12)
#else
#define  MG3_11_113PL    0xFFFF
#endif

#if (G3_14PL >= G3_11PL) || (G3_14PL == 0)
#define  MG3_11_114PL    ~(1 << 13)
#else
#define  MG3_11_114PL    0xFFFF
#endif

#if (G3_15PL >= G3_11PL) || (G3_15PL == 0)
#define  MG3_11_115PL    ~(1 << 14)
#else
#define  MG3_11_115PL    0xFFFF
#endif

#if (G3_16PL >= G3_11PL) || (G3_16PL == 0)
#define  MG3_11_116PL    ~(1 << 15)
#else
#define  MG3_11_116PL    0xFFFF
#endif

#define  MG3_11_111PL	0xFBFF
#define  MG3_11    (MG3_11_11PL & MG3_11_12PL & MG3_11_13PL & MG3_11_14PL & \
                    MG3_11_15PL & MG3_11_16PL & MG3_11_17PL & MG3_11_18PL & \
                    MG3_11_19PL & MG3_11_110PL & MG3_11_111PL & MG3_11_112PL & \
                    MG3_11_113PL & MG3_11_114PL & MG3_11_115PL & MG3_11_116PL)
// End of MG3_11:
// Beginning of MG312:
#if (G3_1PL >= G3_12PL) || (G3_1PL == 0)
#define  MG3_12_11PL    ~(1 << 0)
#else
#define  MG3_12_11PL    0xFFFF
#endif

#if (G3_2PL >= G3_12PL) || (G3_2PL == 0)
#define  MG3_12_12PL    ~(1 << 1)
#else
#define  MG3_12_12PL    0xFFFF
#endif

#if (G3_3PL >= G3_12PL) || (G3_3PL == 0)
#define  MG3_12_13PL    ~(1 << 2)
#else
#define  MG3_12_13PL    0xFFFF
#endif

#if (G3_4PL >= G3_12PL) || (G3_4PL == 0)
#define  MG3_12_14PL    ~(1 << 3)
#else
#define  MG3_12_14PL    0xFFFF
#endif

#if (G3_5PL >= G3_12PL) || (G3_5PL == 0)
#define  MG3_12_15PL    ~(1 << 4)
#else
#define  MG3_12_15PL    0xFFFF
#endif

#if (G3_6PL >= G3_12PL) || (G3_6PL == 0)
#define  MG3_12_16PL    ~(1 << 5)
#else
#define  MG3_12_16PL    0xFFFF
#endif

#if (G3_7PL >= G3_12PL) || (G3_7PL == 0)
#define  MG3_12_17PL    ~(1 << 6)
#else
#define  MG3_12_17PL    0xFFFF
#endif

#if (G3_8PL >= G3_12PL) || (G3_8PL == 0)
#define  MG3_12_18PL    ~(1 << 7)
#else
#define  MG3_12_18PL    0xFFFF
#endif

#if (G3_9PL >= G3_12PL) || (G3_9PL == 0)
#define  MG3_12_19PL    ~(1 << 8)
#else
#define  MG3_12_19PL    0xFFFF
#endif

#if (G3_10PL >= G3_12PL) || (G3_10PL == 0)
#define  MG3_12_110PL    ~(1 << 9)
#else
#define  MG3_12_110PL    0xFFFF
#endif

#if (G3_11PL >= G3_12PL) || (G3_11PL == 0)
#define  MG3_12_111PL    ~(1 << 10)
#else
#define  MG3_12_111PL    0xFFFF
#endif

#if (G3_13PL >= G3_12PL) || (G3_13PL == 0)
#define  MG3_12_113PL    ~(1 << 12)
#else
#define  MG3_12_113PL    0xFFFF
#endif

#if (G3_14PL >= G3_12PL) || (G3_14PL == 0)
#define  MG3_12_114PL    ~(1 << 13)
#else
#define  MG3_12_114PL    0xFFFF
#endif

#if (G3_15PL >= G3_12PL) || (G3_15PL == 0)
#define  MG3_12_115PL    ~(1 << 14)
#else
#define  MG3_12_115PL    0xFFFF
#endif

#if (G3_16PL >= G3_12PL) || (G3_16PL == 0)
#define  MG3_12_116PL    ~(1 << 15)
#else
#define  MG3_12_116PL    0xFFFF
#endif

#define  MG3_12_112PL	0xF7FF
#define  MG3_12    (MG3_12_11PL & MG3_12_12PL & MG3_12_13PL & MG3_12_14PL & \
                    MG3_12_15PL & MG3_12_16PL & MG3_12_17PL & MG3_12_18PL & \
                    MG3_12_19PL & MG3_12_110PL & MG3_12_111PL & MG3_12_112PL & \
                    MG3_12_113PL & MG3_12_114PL & MG3_12_115PL & MG3_12_116PL)
// End of MG3_12:
// Beginning of MG313:
#if (G3_1PL >= G3_13PL) || (G3_1PL == 0)
#define  MG3_13_11PL    ~(1 << 0)
#else
#define  MG3_13_11PL    0xFFFF
#endif

#if (G3_2PL >= G3_13PL) || (G3_2PL == 0)
#define  MG3_13_12PL    ~(1 << 1)
#else
#define  MG3_13_12PL    0xFFFF
#endif

#if (G3_3PL >= G3_13PL) || (G3_3PL == 0)
#define  MG3_13_13PL    ~(1 << 2)
#else
#define  MG3_13_13PL    0xFFFF
#endif

#if (G3_4PL >= G3_13PL) || (G3_4PL == 0)
#define  MG3_13_14PL    ~(1 << 3)
#else
#define  MG3_13_14PL    0xFFFF
#endif

#if (G3_5PL >= G3_13PL) || (G3_5PL == 0)
#define  MG3_13_15PL    ~(1 << 4)
#else
#define  MG3_13_15PL    0xFFFF
#endif

#if (G3_6PL >= G3_13PL) || (G3_6PL == 0)
#define  MG3_13_16PL    ~(1 << 5)
#else
#define  MG3_13_16PL    0xFFFF
#endif

#if (G3_7PL >= G3_13PL) || (G3_7PL == 0)
#define  MG3_13_17PL    ~(1 << 6)
#else
#define  MG3_13_17PL    0xFFFF
#endif

#if (G3_8PL >= G3_13PL) || (G3_8PL == 0)
#define  MG3_13_18PL    ~(1 << 7)
#else
#define  MG3_13_18PL    0xFFFF
#endif

#if (G3_9PL >= G3_13PL) || (G3_9PL == 0)
#define  MG3_13_19PL    ~(1 << 8)
#else
#define  MG3_13_19PL    0xFFFF
#endif

#if (G3_10PL >= G3_13PL) || (G3_10PL == 0)
#define  MG3_13_110PL    ~(1 << 9)
#else
#define  MG3_13_110PL    0xFFFF
#endif

#if (G3_11PL >= G3_13PL) || (G3_11PL == 0)
#define  MG3_13_111PL    ~(1 << 10)
#else
#define  MG3_13_111PL    0xFFFF
#endif

#if (G3_12PL >= G3_13PL) || (G3_12PL == 0)
#define  MG3_13_112PL    ~(1 << 11)
#else
#define  MG3_13_112PL    0xFFFF
#endif

#if (G3_14PL >= G3_13PL) || (G3_14PL == 0)
#define  MG3_13_114PL    ~(1 << 13)
#else
#define  MG3_13_114PL    0xFFFF
#endif

#if (G3_15PL >= G3_13PL) || (G3_15PL == 0)
#define  MG3_13_115PL    ~(1 << 14)
#else
#define  MG3_13_115PL    0xFFFF
#endif

#if (G3_16PL >= G3_13PL) || (G3_16PL == 0)
#define  MG3_13_116PL    ~(1 << 15)
#else
#define  MG3_13_116PL    0xFFFF
#endif

#define  MG3_13_113PL	0xEFFF
#define  MG3_13    (MG3_13_11PL & MG3_13_12PL & MG3_13_13PL & MG3_13_14PL & \
                    MG3_13_15PL & MG3_13_16PL & MG3_13_17PL & MG3_13_18PL & \
                    MG3_13_19PL & MG3_13_110PL & MG3_13_111PL & MG3_13_112PL & \
                    MG3_13_113PL & MG3_13_114PL & MG3_13_115PL & MG3_13_116PL)
// End of MG3_13:
// Beginning of MG314:
#if (G3_1PL >= G3_14PL) || (G3_1PL == 0)
#define  MG3_14_11PL    ~(1 << 0)
#else
#define  MG3_14_11PL    0xFFFF
#endif

#if (G3_2PL >= G3_14PL) || (G3_2PL == 0)
#define  MG3_14_12PL    ~(1 << 1)
#else
#define  MG3_14_12PL    0xFFFF
#endif

#if (G3_3PL >= G3_14PL) || (G3_3PL == 0)
#define  MG3_14_13PL    ~(1 << 2)
#else
#define  MG3_14_13PL    0xFFFF
#endif

#if (G3_4PL >= G3_14PL) || (G3_4PL == 0)
#define  MG3_14_14PL    ~(1 << 3)
#else
#define  MG3_14_14PL    0xFFFF
#endif

#if (G3_5PL >= G3_14PL) || (G3_5PL == 0)
#define  MG3_14_15PL    ~(1 << 4)
#else
#define  MG3_14_15PL    0xFFFF
#endif

#if (G3_6PL >= G3_14PL) || (G3_6PL == 0)
#define  MG3_14_16PL    ~(1 << 5)
#else
#define  MG3_14_16PL    0xFFFF
#endif

#if (G3_7PL >= G3_14PL) || (G3_7PL == 0)
#define  MG3_14_17PL    ~(1 << 6)
#else
#define  MG3_14_17PL    0xFFFF
#endif

#if (G3_8PL >= G3_14PL) || (G3_8PL == 0)
#define  MG3_14_18PL    ~(1 << 7)
#else
#define  MG3_14_18PL    0xFFFF
#endif

#if (G3_9PL >= G3_14PL) || (G3_9PL == 0)
#define  MG3_14_19PL    ~(1 << 8)
#else
#define  MG3_14_19PL    0xFFFF
#endif

#if (G3_10PL >= G3_14PL) || (G3_10PL == 0)
#define  MG3_14_110PL    ~(1 << 9)
#else
#define  MG3_14_110PL    0xFFFF
#endif

#if (G3_11PL >= G3_14PL) || (G3_11PL == 0)
#define  MG3_14_111PL    ~(1 << 10)
#else
#define  MG3_14_111PL    0xFFFF
#endif

#if (G3_12PL >= G3_14PL) || (G3_12PL == 0)
#define  MG3_14_112PL    ~(1 << 11)
#else
#define  MG3_14_112PL    0xFFFF
#endif

#if (G3_13PL >= G3_14PL) || (G3_13PL == 0)
#define  MG3_14_113PL    ~(1 << 12)
#else
#define  MG3_14_113PL    0xFFFF
#endif

#if (G3_15PL >= G3_14PL) || (G3_15PL == 0)
#define  MG3_14_115PL    ~(1 << 14)
#else
#define  MG3_14_115PL    0xFFFF
#endif

#if (G3_16PL >= G3_14PL) || (G3_16PL == 0)
#define  MG3_14_116PL    ~(1 << 15)
#else
#define  MG3_14_116PL    0xFFFF
#endif

#define  MG3_14_114PL	0xDFFF
#define  MG3_14    (MG3_14_11PL & MG3_14_12PL & MG3_14_13PL & MG3_14_14PL & \
                    MG3_14_15PL & MG3_14_16PL & MG3_14_17PL & MG3_14_18PL & \
                    MG3_14_19PL & MG3_14_110PL & MG3_14_111PL & MG3_14_112PL & \
                    MG3_14_113PL & MG3_14_114PL & MG3_14_115PL & MG3_14_116PL)
// End of MG3_14:
// Beginning of MG315:
#if (G3_1PL >= G3_15PL) || (G3_1PL == 0)
#define  MG3_15_11PL    ~(1 << 0)
#else
#define  MG3_15_11PL    0xFFFF
#endif

#if (G3_2PL >= G3_15PL) || (G3_2PL == 0)
#define  MG3_15_12PL    ~(1 << 1)
#else
#define  MG3_15_12PL    0xFFFF
#endif

#if (G3_3PL >= G3_15PL) || (G3_3PL == 0)
#define  MG3_15_13PL    ~(1 << 2)
#else
#define  MG3_15_13PL    0xFFFF
#endif

#if (G3_4PL >= G3_15PL) || (G3_4PL == 0)
#define  MG3_15_14PL    ~(1 << 3)
#else
#define  MG3_15_14PL    0xFFFF
#endif

#if (G3_5PL >= G3_15PL) || (G3_5PL == 0)
#define  MG3_15_15PL    ~(1 << 4)
#else
#define  MG3_15_15PL    0xFFFF
#endif

#if (G3_6PL >= G3_15PL) || (G3_6PL == 0)
#define  MG3_15_16PL    ~(1 << 5)
#else
#define  MG3_15_16PL    0xFFFF
#endif

#if (G3_7PL >= G3_15PL) || (G3_7PL == 0)
#define  MG3_15_17PL    ~(1 << 6)
#else
#define  MG3_15_17PL    0xFFFF
#endif

#if (G3_8PL >= G3_15PL) || (G3_8PL == 0)
#define  MG3_15_18PL    ~(1 << 7)
#else
#define  MG3_15_18PL    0xFFFF
#endif

#if (G3_9PL >= G3_15PL) || (G3_9PL == 0)
#define  MG3_15_19PL    ~(1 << 8)
#else
#define  MG3_15_19PL    0xFFFF
#endif

#if (G3_10PL >= G3_15PL) || (G3_10PL == 0)
#define  MG3_15_110PL    ~(1 << 9)
#else
#define  MG3_15_110PL    0xFFFF
#endif

#if (G3_11PL >= G3_15PL) || (G3_11PL == 0)
#define  MG3_15_111PL    ~(1 << 10)
#else
#define  MG3_15_111PL    0xFFFF
#endif

#if (G3_12PL >= G3_15PL) || (G3_12PL == 0)
#define  MG3_15_112PL    ~(1 << 11)
#else
#define  MG3_15_112PL    0xFFFF
#endif

#if (G3_13PL >= G3_15PL) || (G3_13PL == 0)
#define  MG3_15_113PL    ~(1 << 12)
#else
#define  MG3_15_113PL    0xFFFF
#endif

#if (G3_14PL >= G3_15PL) || (G3_14PL == 0)
#define  MG3_15_114PL    ~(1 << 13)
#else
#define  MG3_15_114PL    0xFFFF
#endif

#if (G3_16PL >= G3_15PL) || (G3_16PL == 0)
#define  MG3_15_116PL    ~(1 << 15)
#else
#define  MG3_15_116PL    0xFFFF
#endif

#define  MG3_15_115PL	0xBFFF
#define  MG3_15    (MG3_15_11PL & MG3_15_12PL & MG3_15_13PL & MG3_15_14PL & \
                    MG3_15_15PL & MG3_15_16PL & MG3_15_17PL & MG3_15_18PL & \
                    MG3_15_19PL & MG3_15_110PL & MG3_15_111PL & MG3_15_112PL & \
                    MG3_15_113PL & MG3_15_114PL & MG3_15_115PL & MG3_15_116PL)
// End of MG3_15:
// Beginning of MG316:
#if (G3_1PL >= G3_16PL) || (G3_1PL == 0)
#define  MG3_16_11PL    ~(1 << 0)
#else
#define  MG3_16_11PL    0xFFFF
#endif

#if (G3_2PL >= G3_16PL) || (G3_2PL == 0)
#define  MG3_16_12PL    ~(1 << 1)
#else
#define  MG3_16_12PL    0xFFFF
#endif

#if (G3_3PL >= G3_16PL) || (G3_3PL == 0)
#define  MG3_16_13PL    ~(1 << 2)
#else
#define  MG3_16_13PL    0xFFFF
#endif

#if (G3_4PL >= G3_16PL) || (G3_4PL == 0)
#define  MG3_16_14PL    ~(1 << 3)
#else
#define  MG3_16_14PL    0xFFFF
#endif

#if (G3_5PL >= G3_16PL) || (G3_5PL == 0)
#define  MG3_16_15PL    ~(1 << 4)
#else
#define  MG3_16_15PL    0xFFFF
#endif

#if (G3_6PL >= G3_16PL) || (G3_6PL == 0)
#define  MG3_16_16PL    ~(1 << 5)
#else
#define  MG3_16_16PL    0xFFFF
#endif

#if (G3_7PL >= G3_16PL) || (G3_7PL == 0)
#define  MG3_16_17PL    ~(1 << 6)
#else
#define  MG3_16_17PL    0xFFFF
#endif

#if (G3_8PL >= G3_16PL) || (G3_8PL == 0)
#define  MG3_16_18PL    ~(1 << 7)
#else
#define  MG3_16_18PL    0xFFFF
#endif

#if (G3_9PL >= G3_16PL) || (G3_9PL == 0)
#define  MG3_16_19PL    ~(1 << 8)
#else
#define  MG3_16_19PL    0xFFFF
#endif

#if (G3_10PL >= G3_16PL) || (G3_10PL == 0)
#define  MG3_16_110PL    ~(1 << 9)
#else
#define  MG3_16_110PL    0xFFFF
#endif

#if (G3_11PL >= G3_16PL) || (G3_11PL == 0)
#define  MG3_16_111PL    ~(1 << 10)
#else
#define  MG3_16_111PL    0xFFFF
#endif

#if (G3_12PL >= G3_16PL) || (G3_12PL == 0)
#define  MG3_16_112PL    ~(1 << 11)
#else
#define  MG3_16_112PL    0xFFFF
#endif

#if (G3_13PL >= G3_16PL) || (G3_13PL == 0)
#define  MG3_16_113PL    ~(1 << 12)
#else
#define  MG3_16_113PL    0xFFFF
#endif

#if (G3_14PL >= G3_16PL) || (G3_14PL == 0)
#define  MG3_16_114PL    ~(1 << 13)
#else
#define  MG3_16_114PL    0xFFFF
#endif

#if (G3_15PL >= G3_16PL) || (G3_15PL == 0)
#define  MG3_16_115PL    ~(1 << 14)
#else
#define  MG3_16_115PL    0xFFFF
#endif

#define  MG3_16_116PL	0x7FFF
#define  MG3_16    (MG3_16_11PL & MG3_16_12PL & MG3_16_13PL & MG3_16_14PL & \
                    MG3_16_15PL & MG3_16_16PL & MG3_16_17PL & MG3_16_18PL & \
                    MG3_16_19PL & MG3_16_110PL & MG3_16_111PL & MG3_16_112PL & \
                    MG3_16_113PL & MG3_16_114PL & MG3_16_115PL & MG3_16_116PL)
// End of MG3_16:


//-------------------------------------------------------------------------------
// Automatically generate PIEIER4 interrupt masks MG41 to MG416:

// Beginning of MG41:
#if (G4_2PL >= G4_1PL) || (G4_2PL == 0)
#define  MG4_1_12PL    ~(1 << 1)
#else
#define  MG4_1_12PL    0xFFFF
#endif

#if (G4_3PL >= G4_1PL) || (G4_3PL == 0)
#define  MG4_1_13PL    ~(1 << 2)
#else
#define  MG4_1_13PL    0xFFFF
#endif

#if (G4_4PL >= G4_1PL) || (G4_4PL == 0)
#define  MG4_1_14PL    ~(1 << 3)
#else
#define  MG4_1_14PL    0xFFFF
#endif

#if (G4_5PL >= G4_1PL) || (G4_5PL == 0)
#define  MG4_1_15PL    ~(1 << 4)
#else
#define  MG4_1_15PL    0xFFFF
#endif

#if (G4_6PL >= G4_1PL) || (G4_6PL == 0)
#define  MG4_1_16PL    ~(1 << 5)
#else
#define  MG4_1_16PL    0xFFFF
#endif

#if (G4_7PL >= G4_1PL) || (G4_7PL == 0)
#define  MG4_1_17PL    ~(1 << 6)
#else
#define  MG4_1_17PL    0xFFFF
#endif

#if (G4_8PL >= G4_1PL) || (G4_8PL == 0)
#define  MG4_1_18PL    ~(1 << 7)
#else
#define  MG4_1_18PL    0xFFFF
#endif

#if (G4_9PL >= G4_1PL) || (G4_9PL == 0)
#define  MG4_1_19PL    ~(1 << 8)
#else
#define  MG4_1_19PL    0xFFFF
#endif

#if (G4_10PL >= G4_1PL) || (G4_10PL == 0)
#define  MG4_1_110PL    ~(1 << 9)
#else
#define  MG4_1_110PL    0xFFFF
#endif

#if (G4_11PL >= G4_1PL) || (G4_11PL == 0)
#define  MG4_1_111PL    ~(1 << 10)
#else
#define  MG4_1_111PL    0xFFFF
#endif

#if (G4_12PL >= G4_1PL) || (G4_12PL == 0)
#define  MG4_1_112PL    ~(1 << 11)
#else
#define  MG4_1_112PL    0xFFFF
#endif

#if (G4_13PL >= G4_1PL) || (G4_13PL == 0)
#define  MG4_1_113PL    ~(1 << 12)
#else
#define  MG4_1_113PL    0xFFFF
#endif

#if (G4_14PL >= G4_1PL) || (G4_14PL == 0)
#define  MG4_1_114PL    ~(1 << 13)
#else
#define  MG4_1_114PL    0xFFFF
#endif

#if (G4_15PL >= G4_1PL) || (G4_15PL == 0)
#define  MG4_1_115PL    ~(1 << 14)
#else
#define  MG4_1_115PL    0xFFFF
#endif

#if (G4_16PL >= G4_1PL) || (G4_16PL == 0)
#define  MG4_1_116PL    ~(1 << 15)
#else
#define  MG4_1_116PL    0xFFFF
#endif

#define  MG4_1_11PL	0xFFFE
#define  MG4_1    (MG4_1_11PL & MG4_1_12PL & MG4_1_13PL & MG4_1_14PL & \
                    MG4_1_15PL & MG4_1_16PL & MG4_1_17PL & MG4_1_18PL & \
                    MG4_1_19PL & MG4_1_110PL & MG4_1_111PL & MG4_1_112PL & \
                    MG4_1_113PL & MG4_1_114PL & MG4_1_115PL & MG4_1_116PL)
// End of MG4_1:
// Beginning of MG42:
#if (G4_1PL >= G4_2PL) || (G4_1PL == 0)
#define  MG4_2_11PL    ~(1 << 0)
#else
#define  MG4_2_11PL    0xFFFF
#endif

#if (G4_3PL >= G4_2PL) || (G4_3PL == 0)
#define  MG4_2_13PL    ~(1 << 2)
#else
#define  MG4_2_13PL    0xFFFF
#endif

#if (G4_4PL >= G4_2PL) || (G4_4PL == 0)
#define  MG4_2_14PL    ~(1 << 3)
#else
#define  MG4_2_14PL    0xFFFF
#endif

#if (G4_5PL >= G4_2PL) || (G4_5PL == 0)
#define  MG4_2_15PL    ~(1 << 4)
#else
#define  MG4_2_15PL    0xFFFF
#endif

#if (G4_6PL >= G4_2PL) || (G4_6PL == 0)
#define  MG4_2_16PL    ~(1 << 5)
#else
#define  MG4_2_16PL    0xFFFF
#endif

#if (G4_7PL >= G4_2PL) || (G4_7PL == 0)
#define  MG4_2_17PL    ~(1 << 6)
#else
#define  MG4_2_17PL    0xFFFF
#endif

#if (G4_8PL >= G4_2PL) || (G4_8PL == 0)
#define  MG4_2_18PL    ~(1 << 7)
#else
#define  MG4_2_18PL    0xFFFF
#endif

#if (G4_9PL >= G4_2PL) || (G4_9PL == 0)
#define  MG4_2_19PL    ~(1 << 8)
#else
#define  MG4_2_19PL    0xFFFF
#endif

#if (G4_10PL >= G4_2PL) || (G4_10PL == 0)
#define  MG4_2_110PL    ~(1 << 9)
#else
#define  MG4_2_110PL    0xFFFF
#endif

#if (G4_11PL >= G4_2PL) || (G4_11PL == 0)
#define  MG4_2_111PL    ~(1 << 10)
#else
#define  MG4_2_111PL    0xFFFF
#endif

#if (G4_12PL >= G4_2PL) || (G4_12PL == 0)
#define  MG4_2_112PL    ~(1 << 11)
#else
#define  MG4_2_112PL    0xFFFF
#endif

#if (G4_13PL >= G4_2PL) || (G4_13PL == 0)
#define  MG4_2_113PL    ~(1 << 12)
#else
#define  MG4_2_113PL    0xFFFF
#endif

#if (G4_14PL >= G4_2PL) || (G4_14PL == 0)
#define  MG4_2_114PL    ~(1 << 13)
#else
#define  MG4_2_114PL    0xFFFF
#endif

#if (G4_15PL >= G4_2PL) || (G4_15PL == 0)
#define  MG4_2_115PL    ~(1 << 14)
#else
#define  MG4_2_115PL    0xFFFF
#endif

#if (G4_16PL >= G4_2PL) || (G4_16PL == 0)
#define  MG4_2_116PL    ~(1 << 15)
#else
#define  MG4_2_116PL    0xFFFF
#endif

#define  MG4_2_12PL	0xFFFD
#define  MG4_2    (MG4_2_11PL & MG4_2_12PL & MG4_2_13PL & MG4_2_14PL & \
                    MG4_2_15PL & MG4_2_16PL & MG4_2_17PL & MG4_2_18PL & \
                    MG4_2_19PL & MG4_2_110PL & MG4_2_111PL & MG4_2_112PL & \
                    MG4_2_113PL & MG4_2_114PL & MG4_2_115PL & MG4_2_116PL)
// End of MG4_2:
// Beginning of MG43:
#if (G4_1PL >= G4_3PL) || (G4_1PL == 0)
#define  MG4_3_11PL    ~(1 << 0)
#else
#define  MG4_3_11PL    0xFFFF
#endif

#if (G4_2PL >= G4_3PL) || (G4_2PL == 0)
#define  MG4_3_12PL    ~(1 << 1)
#else
#define  MG4_3_12PL    0xFFFF
#endif

#if (G4_4PL >= G4_3PL) || (G4_4PL == 0)
#define  MG4_3_14PL    ~(1 << 3)
#else
#define  MG4_3_14PL    0xFFFF
#endif

#if (G4_5PL >= G4_3PL) || (G4_5PL == 0)
#define  MG4_3_15PL    ~(1 << 4)
#else
#define  MG4_3_15PL    0xFFFF
#endif

#if (G4_6PL >= G4_3PL) || (G4_6PL == 0)
#define  MG4_3_16PL    ~(1 << 5)
#else
#define  MG4_3_16PL    0xFFFF
#endif

#if (G4_7PL >= G4_3PL) || (G4_7PL == 0)
#define  MG4_3_17PL    ~(1 << 6)
#else
#define  MG4_3_17PL    0xFFFF
#endif

#if (G4_8PL >= G4_3PL) || (G4_8PL == 0)
#define  MG4_3_18PL    ~(1 << 7)
#else
#define  MG4_3_18PL    0xFFFF
#endif

#if (G4_9PL >= G4_3PL) || (G4_9PL == 0)
#define  MG4_3_19PL    ~(1 << 8)
#else
#define  MG4_3_19PL    0xFFFF
#endif

#if (G4_10PL >= G4_3PL) || (G4_10PL == 0)
#define  MG4_3_110PL    ~(1 << 9)
#else
#define  MG4_3_110PL    0xFFFF
#endif

#if (G4_11PL >= G4_3PL) || (G4_11PL == 0)
#define  MG4_3_111PL    ~(1 << 10)
#else
#define  MG4_3_111PL    0xFFFF
#endif

#if (G4_12PL >= G4_3PL) || (G4_12PL == 0)
#define  MG4_3_112PL    ~(1 << 11)
#else
#define  MG4_3_112PL    0xFFFF
#endif

#if (G4_13PL >= G4_3PL) || (G4_13PL == 0)
#define  MG4_3_113PL    ~(1 << 12)
#else
#define  MG4_3_113PL    0xFFFF
#endif

#if (G4_14PL >= G4_3PL) || (G4_14PL == 0)
#define  MG4_3_114PL    ~(1 << 13)
#else
#define  MG4_3_114PL    0xFFFF
#endif

#if (G4_15PL >= G4_3PL) || (G4_15PL == 0)
#define  MG4_3_115PL    ~(1 << 14)
#else
#define  MG4_3_115PL    0xFFFF
#endif

#if (G4_16PL >= G4_3PL) || (G4_16PL == 0)
#define  MG4_3_116PL    ~(1 << 15)
#else
#define  MG4_3_116PL    0xFFFF
#endif

#define  MG4_3_13PL	0xFFFB
#define  MG4_3    (MG4_3_11PL & MG4_3_12PL & MG4_3_13PL & MG4_3_14PL & \
                    MG4_3_15PL & MG4_3_16PL & MG4_3_17PL & MG4_3_18PL & \
                    MG4_3_19PL & MG4_3_110PL & MG4_3_111PL & MG4_3_112PL & \
                    MG4_3_113PL & MG4_3_114PL & MG4_3_115PL & MG4_3_116PL)
// End of MG4_3:
// Beginning of MG44:
#if (G4_1PL >= G4_4PL) || (G4_1PL == 0)
#define  MG4_4_11PL    ~(1 << 0)
#else
#define  MG4_4_11PL    0xFFFF
#endif

#if (G4_2PL >= G4_4PL) || (G4_2PL == 0)
#define  MG4_4_12PL    ~(1 << 1)
#else
#define  MG4_4_12PL    0xFFFF
#endif

#if (G4_3PL >= G4_4PL) || (G4_3PL == 0)
#define  MG4_4_13PL    ~(1 << 2)
#else
#define  MG4_4_13PL    0xFFFF
#endif

#if (G4_5PL >= G4_4PL) || (G4_5PL == 0)
#define  MG4_4_15PL    ~(1 << 4)
#else
#define  MG4_4_15PL    0xFFFF
#endif

#if (G4_6PL >= G4_4PL) || (G4_6PL == 0)
#define  MG4_4_16PL    ~(1 << 5)
#else
#define  MG4_4_16PL    0xFFFF
#endif

#if (G4_7PL >= G4_4PL) || (G4_7PL == 0)
#define  MG4_4_17PL    ~(1 << 6)
#else
#define  MG4_4_17PL    0xFFFF
#endif

#if (G4_8PL >= G4_4PL) || (G4_8PL == 0)
#define  MG4_4_18PL    ~(1 << 7)
#else
#define  MG4_4_18PL    0xFFFF
#endif

#if (G4_9PL >= G4_4PL) || (G4_9PL == 0)
#define  MG4_4_19PL    ~(1 << 8)
#else
#define  MG4_4_19PL    0xFFFF
#endif

#if (G4_10PL >= G4_4PL) || (G4_10PL == 0)
#define  MG4_4_110PL    ~(1 << 9)
#else
#define  MG4_4_110PL    0xFFFF
#endif

#if (G4_11PL >= G4_4PL) || (G4_11PL == 0)
#define  MG4_4_111PL    ~(1 << 10)
#else
#define  MG4_4_111PL    0xFFFF
#endif

#if (G4_12PL >= G4_4PL) || (G4_12PL == 0)
#define  MG4_4_112PL    ~(1 << 11)
#else
#define  MG4_4_112PL    0xFFFF
#endif

#if (G4_13PL >= G4_4PL) || (G4_13PL == 0)
#define  MG4_4_113PL    ~(1 << 12)
#else
#define  MG4_4_113PL    0xFFFF
#endif

#if (G4_14PL >= G4_4PL) || (G4_14PL == 0)
#define  MG4_4_114PL    ~(1 << 13)
#else
#define  MG4_4_114PL    0xFFFF
#endif

#if (G4_15PL >= G4_4PL) || (G4_15PL == 0)
#define  MG4_4_115PL    ~(1 << 14)
#else
#define  MG4_4_115PL    0xFFFF
#endif

#if (G4_16PL >= G4_4PL) || (G4_16PL == 0)
#define  MG4_4_116PL    ~(1 << 15)
#else
#define  MG4_4_116PL    0xFFFF
#endif

#define  MG4_4_14PL	0xFFF7
#define  MG4_4    (MG4_4_11PL & MG4_4_12PL & MG4_4_13PL & MG4_4_14PL & \
                    MG4_4_15PL & MG4_4_16PL & MG4_4_17PL & MG4_4_18PL & \
                    MG4_4_19PL & MG4_4_110PL & MG4_4_111PL & MG4_4_112PL & \
                    MG4_4_113PL & MG4_4_114PL & MG4_4_115PL & MG4_4_116PL)
// End of MG4_4:
// Beginning of MG45:
#if (G4_1PL >= G4_5PL) || (G4_1PL == 0)
#define  MG4_5_11PL    ~(1 << 0)
#else
#define  MG4_5_11PL    0xFFFF
#endif

#if (G4_2PL >= G4_5PL) || (G4_2PL == 0)
#define  MG4_5_12PL    ~(1 << 1)
#else
#define  MG4_5_12PL    0xFFFF
#endif

#if (G4_3PL >= G4_5PL) || (G4_3PL == 0)
#define  MG4_5_13PL    ~(1 << 2)
#else
#define  MG4_5_13PL    0xFFFF
#endif

#if (G4_4PL >= G4_5PL) || (G4_4PL == 0)
#define  MG4_5_14PL    ~(1 << 3)
#else
#define  MG4_5_14PL    0xFFFF
#endif

#if (G4_6PL >= G4_5PL) || (G4_6PL == 0)
#define  MG4_5_16PL    ~(1 << 5)
#else
#define  MG4_5_16PL    0xFFFF
#endif

#if (G4_7PL >= G4_5PL) || (G4_7PL == 0)
#define  MG4_5_17PL    ~(1 << 6)
#else
#define  MG4_5_17PL    0xFFFF
#endif

#if (G4_8PL >= G4_5PL) || (G4_8PL == 0)
#define  MG4_5_18PL    ~(1 << 7)
#else
#define  MG4_5_18PL    0xFFFF
#endif

#if (G4_9PL >= G4_5PL) || (G4_9PL == 0)
#define  MG4_5_19PL    ~(1 << 8)
#else
#define  MG4_5_19PL    0xFFFF
#endif

#if (G4_10PL >= G4_5PL) || (G4_10PL == 0)
#define  MG4_5_110PL    ~(1 << 9)
#else
#define  MG4_5_110PL    0xFFFF
#endif

#if (G4_11PL >= G4_5PL) || (G4_11PL == 0)
#define  MG4_5_111PL    ~(1 << 10)
#else
#define  MG4_5_111PL    0xFFFF
#endif

#if (G4_12PL >= G4_5PL) || (G4_12PL == 0)
#define  MG4_5_112PL    ~(1 << 11)
#else
#define  MG4_5_112PL    0xFFFF
#endif

#if (G4_13PL >= G4_5PL) || (G4_13PL == 0)
#define  MG4_5_113PL    ~(1 << 12)
#else
#define  MG4_5_113PL    0xFFFF
#endif

#if (G4_14PL >= G4_5PL) || (G4_14PL == 0)
#define  MG4_5_114PL    ~(1 << 13)
#else
#define  MG4_5_114PL    0xFFFF
#endif

#if (G4_15PL >= G4_5PL) || (G4_15PL == 0)
#define  MG4_5_115PL    ~(1 << 14)
#else
#define  MG4_5_115PL    0xFFFF
#endif

#if (G4_16PL >= G4_5PL) || (G4_16PL == 0)
#define  MG4_5_116PL    ~(1 << 15)
#else
#define  MG4_5_116PL    0xFFFF
#endif

#define  MG4_5_15PL	0xFFEF
#define  MG4_5    (MG4_5_11PL & MG4_5_12PL & MG4_5_13PL & MG4_5_14PL & \
                    MG4_5_15PL & MG4_5_16PL & MG4_5_17PL & MG4_5_18PL & \
                    MG4_5_19PL & MG4_5_110PL & MG4_5_111PL & MG4_5_112PL & \
                    MG4_5_113PL & MG4_5_114PL & MG4_5_115PL & MG4_5_116PL)
// End of MG4_5:
// Beginning of MG46:
#if (G4_1PL >= G4_6PL) || (G4_1PL == 0)
#define  MG4_6_11PL    ~(1 << 0)
#else
#define  MG4_6_11PL    0xFFFF
#endif

#if (G4_2PL >= G4_6PL) || (G4_2PL == 0)
#define  MG4_6_12PL    ~(1 << 1)
#else
#define  MG4_6_12PL    0xFFFF
#endif

#if (G4_3PL >= G4_6PL) || (G4_3PL == 0)
#define  MG4_6_13PL    ~(1 << 2)
#else
#define  MG4_6_13PL    0xFFFF
#endif

#if (G4_4PL >= G4_6PL) || (G4_4PL == 0)
#define  MG4_6_14PL    ~(1 << 3)
#else
#define  MG4_6_14PL    0xFFFF
#endif

#if (G4_5PL >= G4_6PL) || (G4_5PL == 0)
#define  MG4_6_15PL    ~(1 << 4)
#else
#define  MG4_6_15PL    0xFFFF
#endif

#if (G4_7PL >= G4_6PL) || (G4_7PL == 0)
#define  MG4_6_17PL    ~(1 << 6)
#else
#define  MG4_6_17PL    0xFFFF
#endif

#if (G4_8PL >= G4_6PL) || (G4_8PL == 0)
#define  MG4_6_18PL    ~(1 << 7)
#else
#define  MG4_6_18PL    0xFFFF
#endif

#if (G4_9PL >= G4_6PL) || (G4_9PL == 0)
#define  MG4_6_19PL    ~(1 << 8)
#else
#define  MG4_6_19PL    0xFFFF
#endif

#if (G4_10PL >= G4_6PL) || (G4_10PL == 0)
#define  MG4_6_110PL    ~(1 << 9)
#else
#define  MG4_6_110PL    0xFFFF
#endif

#if (G4_11PL >= G4_6PL) || (G4_11PL == 0)
#define  MG4_6_111PL    ~(1 << 10)
#else
#define  MG4_6_111PL    0xFFFF
#endif

#if (G4_12PL >= G4_6PL) || (G4_12PL == 0)
#define  MG4_6_112PL    ~(1 << 11)
#else
#define  MG4_6_112PL    0xFFFF
#endif

#if (G4_13PL >= G4_6PL) || (G4_13PL == 0)
#define  MG4_6_113PL    ~(1 << 12)
#else
#define  MG4_6_113PL    0xFFFF
#endif

#if (G4_14PL >= G4_6PL) || (G4_14PL == 0)
#define  MG4_6_114PL    ~(1 << 13)
#else
#define  MG4_6_114PL    0xFFFF
#endif

#if (G4_15PL >= G4_6PL) || (G4_15PL == 0)
#define  MG4_6_115PL    ~(1 << 14)
#else
#define  MG4_6_115PL    0xFFFF
#endif

#if (G4_16PL >= G4_6PL) || (G4_16PL == 0)
#define  MG4_6_116PL    ~(1 << 15)
#else
#define  MG4_6_116PL    0xFFFF
#endif

#define  MG4_6_16PL	0xFFDF
#define  MG4_6    (MG4_6_11PL & MG4_6_12PL & MG4_6_13PL & MG4_6_14PL & \
                    MG4_6_15PL & MG4_6_16PL & MG4_6_17PL & MG4_6_18PL & \
                    MG4_6_19PL & MG4_6_110PL & MG4_6_111PL & MG4_6_112PL & \
                    MG4_6_113PL & MG4_6_114PL & MG4_6_115PL & MG4_6_116PL)
// End of MG4_6:
// Beginning of MG47:
#if (G4_1PL >= G4_7PL) || (G4_1PL == 0)
#define  MG4_7_11PL    ~(1 << 0)
#else
#define  MG4_7_11PL    0xFFFF
#endif

#if (G4_2PL >= G4_7PL) || (G4_2PL == 0)
#define  MG4_7_12PL    ~(1 << 1)
#else
#define  MG4_7_12PL    0xFFFF
#endif

#if (G4_3PL >= G4_7PL) || (G4_3PL == 0)
#define  MG4_7_13PL    ~(1 << 2)
#else
#define  MG4_7_13PL    0xFFFF
#endif

#if (G4_4PL >= G4_7PL) || (G4_4PL == 0)
#define  MG4_7_14PL    ~(1 << 3)
#else
#define  MG4_7_14PL    0xFFFF
#endif

#if (G4_5PL >= G4_7PL) || (G4_5PL == 0)
#define  MG4_7_15PL    ~(1 << 4)
#else
#define  MG4_7_15PL    0xFFFF
#endif

#if (G4_6PL >= G4_7PL) || (G4_6PL == 0)
#define  MG4_7_16PL    ~(1 << 5)
#else
#define  MG4_7_16PL    0xFFFF
#endif

#if (G4_8PL >= G4_7PL) || (G4_8PL == 0)
#define  MG4_7_18PL    ~(1 << 7)
#else
#define  MG4_7_18PL    0xFFFF
#endif

#if (G4_9PL >= G4_7PL) || (G4_9PL == 0)
#define  MG4_7_19PL    ~(1 << 8)
#else
#define  MG4_7_19PL    0xFFFF
#endif

#if (G4_10PL >= G4_7PL) || (G4_10PL == 0)
#define  MG4_7_110PL    ~(1 << 9)
#else
#define  MG4_7_110PL    0xFFFF
#endif

#if (G4_11PL >= G4_7PL) || (G4_11PL == 0)
#define  MG4_7_111PL    ~(1 << 10)
#else
#define  MG4_7_111PL    0xFFFF
#endif

#if (G4_12PL >= G4_7PL) || (G4_12PL == 0)
#define  MG4_7_112PL    ~(1 << 11)
#else
#define  MG4_7_112PL    0xFFFF
#endif

#if (G4_13PL >= G4_7PL) || (G4_13PL == 0)
#define  MG4_7_113PL    ~(1 << 12)
#else
#define  MG4_7_113PL    0xFFFF
#endif

#if (G4_14PL >= G4_7PL) || (G4_14PL == 0)
#define  MG4_7_114PL    ~(1 << 13)
#else
#define  MG4_7_114PL    0xFFFF
#endif

#if (G4_15PL >= G4_7PL) || (G4_15PL == 0)
#define  MG4_7_115PL    ~(1 << 14)
#else
#define  MG4_7_115PL    0xFFFF
#endif

#if (G4_16PL >= G4_7PL) || (G4_16PL == 0)
#define  MG4_7_116PL    ~(1 << 15)
#else
#define  MG4_7_116PL    0xFFFF
#endif

#define  MG4_7_17PL	0xFFBF
#define  MG4_7    (MG4_7_11PL & MG4_7_12PL & MG4_7_13PL & MG4_7_14PL & \
                    MG4_7_15PL & MG4_7_16PL & MG4_7_17PL & MG4_7_18PL & \
                    MG4_7_19PL & MG4_7_110PL & MG4_7_111PL & MG4_7_112PL & \
                    MG4_7_113PL & MG4_7_114PL & MG4_7_115PL & MG4_7_116PL)
// End of MG4_7:
// Beginning of MG48:
#if (G4_1PL >= G4_8PL) || (G4_1PL == 0)
#define  MG4_8_11PL    ~(1 << 0)
#else
#define  MG4_8_11PL    0xFFFF
#endif

#if (G4_2PL >= G4_8PL) || (G4_2PL == 0)
#define  MG4_8_12PL    ~(1 << 1)
#else
#define  MG4_8_12PL    0xFFFF
#endif

#if (G4_3PL >= G4_8PL) || (G4_3PL == 0)
#define  MG4_8_13PL    ~(1 << 2)
#else
#define  MG4_8_13PL    0xFFFF
#endif

#if (G4_4PL >= G4_8PL) || (G4_4PL == 0)
#define  MG4_8_14PL    ~(1 << 3)
#else
#define  MG4_8_14PL    0xFFFF
#endif

#if (G4_5PL >= G4_8PL) || (G4_5PL == 0)
#define  MG4_8_15PL    ~(1 << 4)
#else
#define  MG4_8_15PL    0xFFFF
#endif

#if (G4_6PL >= G4_8PL) || (G4_6PL == 0)
#define  MG4_8_16PL    ~(1 << 5)
#else
#define  MG4_8_16PL    0xFFFF
#endif

#if (G4_7PL >= G4_8PL) || (G4_7PL == 0)
#define  MG4_8_17PL    ~(1 << 6)
#else
#define  MG4_8_17PL    0xFFFF
#endif

#if (G4_9PL >= G4_8PL) || (G4_9PL == 0)
#define  MG4_8_19PL    ~(1 << 8)
#else
#define  MG4_8_19PL    0xFFFF
#endif

#if (G4_10PL >= G4_8PL) || (G4_10PL == 0)
#define  MG4_8_110PL    ~(1 << 9)
#else
#define  MG4_8_110PL    0xFFFF
#endif

#if (G4_11PL >= G4_8PL) || (G4_11PL == 0)
#define  MG4_8_111PL    ~(1 << 10)
#else
#define  MG4_8_111PL    0xFFFF
#endif

#if (G4_12PL >= G4_8PL) || (G4_12PL == 0)
#define  MG4_8_112PL    ~(1 << 11)
#else
#define  MG4_8_112PL    0xFFFF
#endif

#if (G4_13PL >= G4_8PL) || (G4_13PL == 0)
#define  MG4_8_113PL    ~(1 << 12)
#else
#define  MG4_8_113PL    0xFFFF
#endif

#if (G4_14PL >= G4_8PL) || (G4_14PL == 0)
#define  MG4_8_114PL    ~(1 << 13)
#else
#define  MG4_8_114PL    0xFFFF
#endif

#if (G4_15PL >= G4_8PL) || (G4_15PL == 0)
#define  MG4_8_115PL    ~(1 << 14)
#else
#define  MG4_8_115PL    0xFFFF
#endif

#if (G4_16PL >= G4_8PL) || (G4_16PL == 0)
#define  MG4_8_116PL    ~(1 << 15)
#else
#define  MG4_8_116PL    0xFFFF
#endif

#define  MG4_8_18PL	0xFF7F
#define  MG4_8    (MG4_8_11PL & MG4_8_12PL & MG4_8_13PL & MG4_8_14PL & \
                    MG4_8_15PL & MG4_8_16PL & MG4_8_17PL & MG4_8_18PL & \
                    MG4_8_19PL & MG4_8_110PL & MG4_8_111PL & MG4_8_112PL & \
                    MG4_8_113PL & MG4_8_114PL & MG4_8_115PL & MG4_8_116PL)
// End of MG4_8:
// Beginning of MG49:
#if (G4_1PL >= G4_9PL) || (G4_1PL == 0)
#define  MG4_9_11PL    ~(1 << 0)
#else
#define  MG4_9_11PL    0xFFFF
#endif

#if (G4_2PL >= G4_9PL) || (G4_2PL == 0)
#define  MG4_9_12PL    ~(1 << 1)
#else
#define  MG4_9_12PL    0xFFFF
#endif

#if (G4_3PL >= G4_9PL) || (G4_3PL == 0)
#define  MG4_9_13PL    ~(1 << 2)
#else
#define  MG4_9_13PL    0xFFFF
#endif

#if (G4_4PL >= G4_9PL) || (G4_4PL == 0)
#define  MG4_9_14PL    ~(1 << 3)
#else
#define  MG4_9_14PL    0xFFFF
#endif

#if (G4_5PL >= G4_9PL) || (G4_5PL == 0)
#define  MG4_9_15PL    ~(1 << 4)
#else
#define  MG4_9_15PL    0xFFFF
#endif

#if (G4_6PL >= G4_9PL) || (G4_6PL == 0)
#define  MG4_9_16PL    ~(1 << 5)
#else
#define  MG4_9_16PL    0xFFFF
#endif

#if (G4_7PL >= G4_9PL) || (G4_7PL == 0)
#define  MG4_9_17PL    ~(1 << 6)
#else
#define  MG4_9_17PL    0xFFFF
#endif

#if (G4_8PL >= G4_9PL) || (G4_8PL == 0)
#define  MG4_9_18PL    ~(1 << 7)
#else
#define  MG4_9_18PL    0xFFFF
#endif

#if (G4_10PL >= G4_9PL) || (G4_10PL == 0)
#define  MG4_9_110PL    ~(1 << 9)
#else
#define  MG4_9_110PL    0xFFFF
#endif

#if (G4_11PL >= G4_9PL) || (G4_11PL == 0)
#define  MG4_9_111PL    ~(1 << 10)
#else
#define  MG4_9_111PL    0xFFFF
#endif

#if (G4_12PL >= G4_9PL) || (G4_12PL == 0)
#define  MG4_9_112PL    ~(1 << 11)
#else
#define  MG4_9_112PL    0xFFFF
#endif

#if (G4_13PL >= G4_9PL) || (G4_13PL == 0)
#define  MG4_9_113PL    ~(1 << 12)
#else
#define  MG4_9_113PL    0xFFFF
#endif

#if (G4_14PL >= G4_9PL) || (G4_14PL == 0)
#define  MG4_9_114PL    ~(1 << 13)
#else
#define  MG4_9_114PL    0xFFFF
#endif

#if (G4_15PL >= G4_9PL) || (G4_15PL == 0)
#define  MG4_9_115PL    ~(1 << 14)
#else
#define  MG4_9_115PL    0xFFFF
#endif

#if (G4_16PL >= G4_9PL) || (G4_16PL == 0)
#define  MG4_9_116PL    ~(1 << 15)
#else
#define  MG4_9_116PL    0xFFFF
#endif

#define  MG4_9_19PL	0xFEFF
#define  MG4_9    (MG4_9_11PL & MG4_9_12PL & MG4_9_13PL & MG4_9_14PL & \
                    MG4_9_15PL & MG4_9_16PL & MG4_9_17PL & MG4_9_18PL & \
                    MG4_9_19PL & MG4_9_110PL & MG4_9_111PL & MG4_9_112PL & \
                    MG4_9_113PL & MG4_9_114PL & MG4_9_115PL & MG4_9_116PL)
// End of MG4_9:
// Beginning of MG410:
#if (G4_1PL >= G4_10PL) || (G4_1PL == 0)
#define  MG4_10_11PL    ~(1 << 0)
#else
#define  MG4_10_11PL    0xFFFF
#endif

#if (G4_2PL >= G4_10PL) || (G4_2PL == 0)
#define  MG4_10_12PL    ~(1 << 1)
#else
#define  MG4_10_12PL    0xFFFF
#endif

#if (G4_3PL >= G4_10PL) || (G4_3PL == 0)
#define  MG4_10_13PL    ~(1 << 2)
#else
#define  MG4_10_13PL    0xFFFF
#endif

#if (G4_4PL >= G4_10PL) || (G4_4PL == 0)
#define  MG4_10_14PL    ~(1 << 3)
#else
#define  MG4_10_14PL    0xFFFF
#endif

#if (G4_5PL >= G4_10PL) || (G4_5PL == 0)
#define  MG4_10_15PL    ~(1 << 4)
#else
#define  MG4_10_15PL    0xFFFF
#endif

#if (G4_6PL >= G4_10PL) || (G4_6PL == 0)
#define  MG4_10_16PL    ~(1 << 5)
#else
#define  MG4_10_16PL    0xFFFF
#endif

#if (G4_7PL >= G4_10PL) || (G4_7PL == 0)
#define  MG4_10_17PL    ~(1 << 6)
#else
#define  MG4_10_17PL    0xFFFF
#endif

#if (G4_8PL >= G4_10PL) || (G4_8PL == 0)
#define  MG4_10_18PL    ~(1 << 7)
#else
#define  MG4_10_18PL    0xFFFF
#endif

#if (G4_9PL >= G4_10PL) || (G4_9PL == 0)
#define  MG4_10_19PL    ~(1 << 8)
#else
#define  MG4_10_19PL    0xFFFF
#endif

#if (G4_11PL >= G4_10PL) || (G4_11PL == 0)
#define  MG4_10_111PL    ~(1 << 10)
#else
#define  MG4_10_111PL    0xFFFF
#endif

#if (G4_12PL >= G4_10PL) || (G4_12PL == 0)
#define  MG4_10_112PL    ~(1 << 11)
#else
#define  MG4_10_112PL    0xFFFF
#endif

#if (G4_13PL >= G4_10PL) || (G4_13PL == 0)
#define  MG4_10_113PL    ~(1 << 12)
#else
#define  MG4_10_113PL    0xFFFF
#endif

#if (G4_14PL >= G4_10PL) || (G4_14PL == 0)
#define  MG4_10_114PL    ~(1 << 13)
#else
#define  MG4_10_114PL    0xFFFF
#endif

#if (G4_15PL >= G4_10PL) || (G4_15PL == 0)
#define  MG4_10_115PL    ~(1 << 14)
#else
#define  MG4_10_115PL    0xFFFF
#endif

#if (G4_16PL >= G4_10PL) || (G4_16PL == 0)
#define  MG4_10_116PL    ~(1 << 15)
#else
#define  MG4_10_116PL    0xFFFF
#endif

#define  MG4_10_110PL	0xFDFF
#define  MG4_10    (MG4_10_11PL & MG4_10_12PL & MG4_10_13PL & MG4_10_14PL & \
                    MG4_10_15PL & MG4_10_16PL & MG4_10_17PL & MG4_10_18PL & \
                    MG4_10_19PL & MG4_10_110PL & MG4_10_111PL & MG4_10_112PL & \
                    MG4_10_113PL & MG4_10_114PL & MG4_10_115PL & MG4_10_116PL)
// End of MG4_10:
// Beginning of MG411:
#if (G4_1PL >= G4_11PL) || (G4_1PL == 0)
#define  MG4_11_11PL    ~(1 << 0)
#else
#define  MG4_11_11PL    0xFFFF
#endif

#if (G4_2PL >= G4_11PL) || (G4_2PL == 0)
#define  MG4_11_12PL    ~(1 << 1)
#else
#define  MG4_11_12PL    0xFFFF
#endif

#if (G4_3PL >= G4_11PL) || (G4_3PL == 0)
#define  MG4_11_13PL    ~(1 << 2)
#else
#define  MG4_11_13PL    0xFFFF
#endif

#if (G4_4PL >= G4_11PL) || (G4_4PL == 0)
#define  MG4_11_14PL    ~(1 << 3)
#else
#define  MG4_11_14PL    0xFFFF
#endif

#if (G4_5PL >= G4_11PL) || (G4_5PL == 0)
#define  MG4_11_15PL    ~(1 << 4)
#else
#define  MG4_11_15PL    0xFFFF
#endif

#if (G4_6PL >= G4_11PL) || (G4_6PL == 0)
#define  MG4_11_16PL    ~(1 << 5)
#else
#define  MG4_11_16PL    0xFFFF
#endif

#if (G4_7PL >= G4_11PL) || (G4_7PL == 0)
#define  MG4_11_17PL    ~(1 << 6)
#else
#define  MG4_11_17PL    0xFFFF
#endif

#if (G4_8PL >= G4_11PL) || (G4_8PL == 0)
#define  MG4_11_18PL    ~(1 << 7)
#else
#define  MG4_11_18PL    0xFFFF
#endif

#if (G4_9PL >= G4_11PL) || (G4_9PL == 0)
#define  MG4_11_19PL    ~(1 << 8)
#else
#define  MG4_11_19PL    0xFFFF
#endif

#if (G4_10PL >= G4_11PL) || (G4_10PL == 0)
#define  MG4_11_110PL    ~(1 << 9)
#else
#define  MG4_11_110PL    0xFFFF
#endif

#if (G4_12PL >= G4_11PL) || (G4_12PL == 0)
#define  MG4_11_112PL    ~(1 << 11)
#else
#define  MG4_11_112PL    0xFFFF
#endif

#if (G4_13PL >= G4_11PL) || (G4_13PL == 0)
#define  MG4_11_113PL    ~(1 << 12)
#else
#define  MG4_11_113PL    0xFFFF
#endif

#if (G4_14PL >= G4_11PL) || (G4_14PL == 0)
#define  MG4_11_114PL    ~(1 << 13)
#else
#define  MG4_11_114PL    0xFFFF
#endif

#if (G4_15PL >= G4_11PL) || (G4_15PL == 0)
#define  MG4_11_115PL    ~(1 << 14)
#else
#define  MG4_11_115PL    0xFFFF
#endif

#if (G4_16PL >= G4_11PL) || (G4_16PL == 0)
#define  MG4_11_116PL    ~(1 << 15)
#else
#define  MG4_11_116PL    0xFFFF
#endif

#define  MG4_11_111PL	0xFBFF
#define  MG4_11    (MG4_11_11PL & MG4_11_12PL & MG4_11_13PL & MG4_11_14PL & \
                    MG4_11_15PL & MG4_11_16PL & MG4_11_17PL & MG4_11_18PL & \
                    MG4_11_19PL & MG4_11_110PL & MG4_11_111PL & MG4_11_112PL & \
                    MG4_11_113PL & MG4_11_114PL & MG4_11_115PL & MG4_11_116PL)
// End of MG4_11:
// Beginning of MG412:
#if (G4_1PL >= G4_12PL) || (G4_1PL == 0)
#define  MG4_12_11PL    ~(1 << 0)
#else
#define  MG4_12_11PL    0xFFFF
#endif

#if (G4_2PL >= G4_12PL) || (G4_2PL == 0)
#define  MG4_12_12PL    ~(1 << 1)
#else
#define  MG4_12_12PL    0xFFFF
#endif

#if (G4_3PL >= G4_12PL) || (G4_3PL == 0)
#define  MG4_12_13PL    ~(1 << 2)
#else
#define  MG4_12_13PL    0xFFFF
#endif

#if (G4_4PL >= G4_12PL) || (G4_4PL == 0)
#define  MG4_12_14PL    ~(1 << 3)
#else
#define  MG4_12_14PL    0xFFFF
#endif

#if (G4_5PL >= G4_12PL) || (G4_5PL == 0)
#define  MG4_12_15PL    ~(1 << 4)
#else
#define  MG4_12_15PL    0xFFFF
#endif

#if (G4_6PL >= G4_12PL) || (G4_6PL == 0)
#define  MG4_12_16PL    ~(1 << 5)
#else
#define  MG4_12_16PL    0xFFFF
#endif

#if (G4_7PL >= G4_12PL) || (G4_7PL == 0)
#define  MG4_12_17PL    ~(1 << 6)
#else
#define  MG4_12_17PL    0xFFFF
#endif

#if (G4_8PL >= G4_12PL) || (G4_8PL == 0)
#define  MG4_12_18PL    ~(1 << 7)
#else
#define  MG4_12_18PL    0xFFFF
#endif

#if (G4_9PL >= G4_12PL) || (G4_9PL == 0)
#define  MG4_12_19PL    ~(1 << 8)
#else
#define  MG4_12_19PL    0xFFFF
#endif

#if (G4_10PL >= G4_12PL) || (G4_10PL == 0)
#define  MG4_12_110PL    ~(1 << 9)
#else
#define  MG4_12_110PL    0xFFFF
#endif

#if (G4_11PL >= G4_12PL) || (G4_11PL == 0)
#define  MG4_12_111PL    ~(1 << 10)
#else
#define  MG4_12_111PL    0xFFFF
#endif

#if (G4_13PL >= G4_12PL) || (G4_13PL == 0)
#define  MG4_12_113PL    ~(1 << 12)
#else
#define  MG4_12_113PL    0xFFFF
#endif

#if (G4_14PL >= G4_12PL) || (G4_14PL == 0)
#define  MG4_12_114PL    ~(1 << 13)
#else
#define  MG4_12_114PL    0xFFFF
#endif

#if (G4_15PL >= G4_12PL) || (G4_15PL == 0)
#define  MG4_12_115PL    ~(1 << 14)
#else
#define  MG4_12_115PL    0xFFFF
#endif

#if (G4_16PL >= G4_12PL) || (G4_16PL == 0)
#define  MG4_12_116PL    ~(1 << 15)
#else
#define  MG4_12_116PL    0xFFFF
#endif

#define  MG4_12_112PL	0xF7FF
#define  MG4_12    (MG4_12_11PL & MG4_12_12PL & MG4_12_13PL & MG4_12_14PL & \
                    MG4_12_15PL & MG4_12_16PL & MG4_12_17PL & MG4_12_18PL & \
                    MG4_12_19PL & MG4_12_110PL & MG4_12_111PL & MG4_12_112PL & \
                    MG4_12_113PL & MG4_12_114PL & MG4_12_115PL & MG4_12_116PL)
// End of MG4_12:
// Beginning of MG413:
#if (G4_1PL >= G4_13PL) || (G4_1PL == 0)
#define  MG4_13_11PL    ~(1 << 0)
#else
#define  MG4_13_11PL    0xFFFF
#endif

#if (G4_2PL >= G4_13PL) || (G4_2PL == 0)
#define  MG4_13_12PL    ~(1 << 1)
#else
#define  MG4_13_12PL    0xFFFF
#endif

#if (G4_3PL >= G4_13PL) || (G4_3PL == 0)
#define  MG4_13_13PL    ~(1 << 2)
#else
#define  MG4_13_13PL    0xFFFF
#endif

#if (G4_4PL >= G4_13PL) || (G4_4PL == 0)
#define  MG4_13_14PL    ~(1 << 3)
#else
#define  MG4_13_14PL    0xFFFF
#endif

#if (G4_5PL >= G4_13PL) || (G4_5PL == 0)
#define  MG4_13_15PL    ~(1 << 4)
#else
#define  MG4_13_15PL    0xFFFF
#endif

#if (G4_6PL >= G4_13PL) || (G4_6PL == 0)
#define  MG4_13_16PL    ~(1 << 5)
#else
#define  MG4_13_16PL    0xFFFF
#endif

#if (G4_7PL >= G4_13PL) || (G4_7PL == 0)
#define  MG4_13_17PL    ~(1 << 6)
#else
#define  MG4_13_17PL    0xFFFF
#endif

#if (G4_8PL >= G4_13PL) || (G4_8PL == 0)
#define  MG4_13_18PL    ~(1 << 7)
#else
#define  MG4_13_18PL    0xFFFF
#endif

#if (G4_9PL >= G4_13PL) || (G4_9PL == 0)
#define  MG4_13_19PL    ~(1 << 8)
#else
#define  MG4_13_19PL    0xFFFF
#endif

#if (G4_10PL >= G4_13PL) || (G4_10PL == 0)
#define  MG4_13_110PL    ~(1 << 9)
#else
#define  MG4_13_110PL    0xFFFF
#endif

#if (G4_11PL >= G4_13PL) || (G4_11PL == 0)
#define  MG4_13_111PL    ~(1 << 10)
#else
#define  MG4_13_111PL    0xFFFF
#endif

#if (G4_12PL >= G4_13PL) || (G4_12PL == 0)
#define  MG4_13_112PL    ~(1 << 11)
#else
#define  MG4_13_112PL    0xFFFF
#endif

#if (G4_14PL >= G4_13PL) || (G4_14PL == 0)
#define  MG4_13_114PL    ~(1 << 13)
#else
#define  MG4_13_114PL    0xFFFF
#endif

#if (G4_15PL >= G4_13PL) || (G4_15PL == 0)
#define  MG4_13_115PL    ~(1 << 14)
#else
#define  MG4_13_115PL    0xFFFF
#endif

#if (G4_16PL >= G4_13PL) || (G4_16PL == 0)
#define  MG4_13_116PL    ~(1 << 15)
#else
#define  MG4_13_116PL    0xFFFF
#endif

#define  MG4_13_113PL	0xEFFF
#define  MG4_13    (MG4_13_11PL & MG4_13_12PL & MG4_13_13PL & MG4_13_14PL & \
                    MG4_13_15PL & MG4_13_16PL & MG4_13_17PL & MG4_13_18PL & \
                    MG4_13_19PL & MG4_13_110PL & MG4_13_111PL & MG4_13_112PL & \
                    MG4_13_113PL & MG4_13_114PL & MG4_13_115PL & MG4_13_116PL)
// End of MG4_13:
// Beginning of MG414:
#if (G4_1PL >= G4_14PL) || (G4_1PL == 0)
#define  MG4_14_11PL    ~(1 << 0)
#else
#define  MG4_14_11PL    0xFFFF
#endif

#if (G4_2PL >= G4_14PL) || (G4_2PL == 0)
#define  MG4_14_12PL    ~(1 << 1)
#else
#define  MG4_14_12PL    0xFFFF
#endif

#if (G4_3PL >= G4_14PL) || (G4_3PL == 0)
#define  MG4_14_13PL    ~(1 << 2)
#else
#define  MG4_14_13PL    0xFFFF
#endif

#if (G4_4PL >= G4_14PL) || (G4_4PL == 0)
#define  MG4_14_14PL    ~(1 << 3)
#else
#define  MG4_14_14PL    0xFFFF
#endif

#if (G4_5PL >= G4_14PL) || (G4_5PL == 0)
#define  MG4_14_15PL    ~(1 << 4)
#else
#define  MG4_14_15PL    0xFFFF
#endif

#if (G4_6PL >= G4_14PL) || (G4_6PL == 0)
#define  MG4_14_16PL    ~(1 << 5)
#else
#define  MG4_14_16PL    0xFFFF
#endif

#if (G4_7PL >= G4_14PL) || (G4_7PL == 0)
#define  MG4_14_17PL    ~(1 << 6)
#else
#define  MG4_14_17PL    0xFFFF
#endif

#if (G4_8PL >= G4_14PL) || (G4_8PL == 0)
#define  MG4_14_18PL    ~(1 << 7)
#else
#define  MG4_14_18PL    0xFFFF
#endif

#if (G4_9PL >= G4_14PL) || (G4_9PL == 0)
#define  MG4_14_19PL    ~(1 << 8)
#else
#define  MG4_14_19PL    0xFFFF
#endif

#if (G4_10PL >= G4_14PL) || (G4_10PL == 0)
#define  MG4_14_110PL    ~(1 << 9)
#else
#define  MG4_14_110PL    0xFFFF
#endif

#if (G4_11PL >= G4_14PL) || (G4_11PL == 0)
#define  MG4_14_111PL    ~(1 << 10)
#else
#define  MG4_14_111PL    0xFFFF
#endif

#if (G4_12PL >= G4_14PL) || (G4_12PL == 0)
#define  MG4_14_112PL    ~(1 << 11)
#else
#define  MG4_14_112PL    0xFFFF
#endif

#if (G4_13PL >= G4_14PL) || (G4_13PL == 0)
#define  MG4_14_113PL    ~(1 << 12)
#else
#define  MG4_14_113PL    0xFFFF
#endif

#if (G4_15PL >= G4_14PL) || (G4_15PL == 0)
#define  MG4_14_115PL    ~(1 << 14)
#else
#define  MG4_14_115PL    0xFFFF
#endif

#if (G4_16PL >= G4_14PL) || (G4_16PL == 0)
#define  MG4_14_116PL    ~(1 << 15)
#else
#define  MG4_14_116PL    0xFFFF
#endif

#define  MG4_14_114PL	0xDFFF
#define  MG4_14    (MG4_14_11PL & MG4_14_12PL & MG4_14_13PL & MG4_14_14PL & \
                    MG4_14_15PL & MG4_14_16PL & MG4_14_17PL & MG4_14_18PL & \
                    MG4_14_19PL & MG4_14_110PL & MG4_14_111PL & MG4_14_112PL & \
                    MG4_14_113PL & MG4_14_114PL & MG4_14_115PL & MG4_14_116PL)
// End of MG4_14:
// Beginning of MG415:
#if (G4_1PL >= G4_15PL) || (G4_1PL == 0)
#define  MG4_15_11PL    ~(1 << 0)
#else
#define  MG4_15_11PL    0xFFFF
#endif

#if (G4_2PL >= G4_15PL) || (G4_2PL == 0)
#define  MG4_15_12PL    ~(1 << 1)
#else
#define  MG4_15_12PL    0xFFFF
#endif

#if (G4_3PL >= G4_15PL) || (G4_3PL == 0)
#define  MG4_15_13PL    ~(1 << 2)
#else
#define  MG4_15_13PL    0xFFFF
#endif

#if (G4_4PL >= G4_15PL) || (G4_4PL == 0)
#define  MG4_15_14PL    ~(1 << 3)
#else
#define  MG4_15_14PL    0xFFFF
#endif

#if (G4_5PL >= G4_15PL) || (G4_5PL == 0)
#define  MG4_15_15PL    ~(1 << 4)
#else
#define  MG4_15_15PL    0xFFFF
#endif

#if (G4_6PL >= G4_15PL) || (G4_6PL == 0)
#define  MG4_15_16PL    ~(1 << 5)
#else
#define  MG4_15_16PL    0xFFFF
#endif

#if (G4_7PL >= G4_15PL) || (G4_7PL == 0)
#define  MG4_15_17PL    ~(1 << 6)
#else
#define  MG4_15_17PL    0xFFFF
#endif

#if (G4_8PL >= G4_15PL) || (G4_8PL == 0)
#define  MG4_15_18PL    ~(1 << 7)
#else
#define  MG4_15_18PL    0xFFFF
#endif

#if (G4_9PL >= G4_15PL) || (G4_9PL == 0)
#define  MG4_15_19PL    ~(1 << 8)
#else
#define  MG4_15_19PL    0xFFFF
#endif

#if (G4_10PL >= G4_15PL) || (G4_10PL == 0)
#define  MG4_15_110PL    ~(1 << 9)
#else
#define  MG4_15_110PL    0xFFFF
#endif

#if (G4_11PL >= G4_15PL) || (G4_11PL == 0)
#define  MG4_15_111PL    ~(1 << 10)
#else
#define  MG4_15_111PL    0xFFFF
#endif

#if (G4_12PL >= G4_15PL) || (G4_12PL == 0)
#define  MG4_15_112PL    ~(1 << 11)
#else
#define  MG4_15_112PL    0xFFFF
#endif

#if (G4_13PL >= G4_15PL) || (G4_13PL == 0)
#define  MG4_15_113PL    ~(1 << 12)
#else
#define  MG4_15_113PL    0xFFFF
#endif

#if (G4_14PL >= G4_15PL) || (G4_14PL == 0)
#define  MG4_15_114PL    ~(1 << 13)
#else
#define  MG4_15_114PL    0xFFFF
#endif

#if (G4_16PL >= G4_15PL) || (G4_16PL == 0)
#define  MG4_15_116PL    ~(1 << 15)
#else
#define  MG4_15_116PL    0xFFFF
#endif

#define  MG4_15_115PL	0xBFFF
#define  MG4_15    (MG4_15_11PL & MG4_15_12PL & MG4_15_13PL & MG4_15_14PL & \
                    MG4_15_15PL & MG4_15_16PL & MG4_15_17PL & MG4_15_18PL & \
                    MG4_15_19PL & MG4_15_110PL & MG4_15_111PL & MG4_15_112PL & \
                    MG4_15_113PL & MG4_15_114PL & MG4_15_115PL & MG4_15_116PL)
// End of MG4_15:
// Beginning of MG416:
#if (G4_1PL >= G4_16PL) || (G4_1PL == 0)
#define  MG4_16_11PL    ~(1 << 0)
#else
#define  MG4_16_11PL    0xFFFF
#endif

#if (G4_2PL >= G4_16PL) || (G4_2PL == 0)
#define  MG4_16_12PL    ~(1 << 1)
#else
#define  MG4_16_12PL    0xFFFF
#endif

#if (G4_3PL >= G4_16PL) || (G4_3PL == 0)
#define  MG4_16_13PL    ~(1 << 2)
#else
#define  MG4_16_13PL    0xFFFF
#endif

#if (G4_4PL >= G4_16PL) || (G4_4PL == 0)
#define  MG4_16_14PL    ~(1 << 3)
#else
#define  MG4_16_14PL    0xFFFF
#endif

#if (G4_5PL >= G4_16PL) || (G4_5PL == 0)
#define  MG4_16_15PL    ~(1 << 4)
#else
#define  MG4_16_15PL    0xFFFF
#endif

#if (G4_6PL >= G4_16PL) || (G4_6PL == 0)
#define  MG4_16_16PL    ~(1 << 5)
#else
#define  MG4_16_16PL    0xFFFF
#endif

#if (G4_7PL >= G4_16PL) || (G4_7PL == 0)
#define  MG4_16_17PL    ~(1 << 6)
#else
#define  MG4_16_17PL    0xFFFF
#endif

#if (G4_8PL >= G4_16PL) || (G4_8PL == 0)
#define  MG4_16_18PL    ~(1 << 7)
#else
#define  MG4_16_18PL    0xFFFF
#endif

#if (G4_9PL >= G4_16PL) || (G4_9PL == 0)
#define  MG4_16_19PL    ~(1 << 8)
#else
#define  MG4_16_19PL    0xFFFF
#endif

#if (G4_10PL >= G4_16PL) || (G4_10PL == 0)
#define  MG4_16_110PL    ~(1 << 9)
#else
#define  MG4_16_110PL    0xFFFF
#endif

#if (G4_11PL >= G4_16PL) || (G4_11PL == 0)
#define  MG4_16_111PL    ~(1 << 10)
#else
#define  MG4_16_111PL    0xFFFF
#endif

#if (G4_12PL >= G4_16PL) || (G4_12PL == 0)
#define  MG4_16_112PL    ~(1 << 11)
#else
#define  MG4_16_112PL    0xFFFF
#endif

#if (G4_13PL >= G4_16PL) || (G4_13PL == 0)
#define  MG4_16_113PL    ~(1 << 12)
#else
#define  MG4_16_113PL    0xFFFF
#endif

#if (G4_14PL >= G4_16PL) || (G4_14PL == 0)
#define  MG4_16_114PL    ~(1 << 13)
#else
#define  MG4_16_114PL    0xFFFF
#endif

#if (G4_15PL >= G4_16PL) || (G4_15PL == 0)
#define  MG4_16_115PL    ~(1 << 14)
#else
#define  MG4_16_115PL    0xFFFF
#endif

#define  MG4_16_116PL	0x7FFF
#define  MG4_16    (MG4_16_11PL & MG4_16_12PL & MG4_16_13PL & MG4_16_14PL & \
                    MG4_16_15PL & MG4_16_16PL & MG4_16_17PL & MG4_16_18PL & \
                    MG4_16_19PL & MG4_16_110PL & MG4_16_111PL & MG4_16_112PL & \
                    MG4_16_113PL & MG4_16_114PL & MG4_16_115PL & MG4_16_116PL)
// End of MG4_16:


//-------------------------------------------------------------------------------
// Automatically generate PIEIER5 interrupt masks MG51 to MG516:

// Beginning of MG51:
#if (G5_2PL >= G5_1PL) || (G5_2PL == 0)
#define  MG5_1_12PL    ~(1 << 1)
#else
#define  MG5_1_12PL    0xFFFF
#endif

#if (G5_3PL >= G5_1PL) || (G5_3PL == 0)
#define  MG5_1_13PL    ~(1 << 2)
#else
#define  MG5_1_13PL    0xFFFF
#endif

#if (G5_4PL >= G5_1PL) || (G5_4PL == 0)
#define  MG5_1_14PL    ~(1 << 3)
#else
#define  MG5_1_14PL    0xFFFF
#endif

#if (G5_5PL >= G5_1PL) || (G5_5PL == 0)
#define  MG5_1_15PL    ~(1 << 4)
#else
#define  MG5_1_15PL    0xFFFF
#endif

#if (G5_6PL >= G5_1PL) || (G5_6PL == 0)
#define  MG5_1_16PL    ~(1 << 5)
#else
#define  MG5_1_16PL    0xFFFF
#endif

#if (G5_7PL >= G5_1PL) || (G5_7PL == 0)
#define  MG5_1_17PL    ~(1 << 6)
#else
#define  MG5_1_17PL    0xFFFF
#endif

#if (G5_8PL >= G5_1PL) || (G5_8PL == 0)
#define  MG5_1_18PL    ~(1 << 7)
#else
#define  MG5_1_18PL    0xFFFF
#endif

#if (G5_9PL >= G5_1PL) || (G5_9PL == 0)
#define  MG5_1_19PL    ~(1 << 8)
#else
#define  MG5_1_19PL    0xFFFF
#endif

#if (G5_10PL >= G5_1PL) || (G5_10PL == 0)
#define  MG5_1_110PL    ~(1 << 9)
#else
#define  MG5_1_110PL    0xFFFF
#endif

#if (G5_11PL >= G5_1PL) || (G5_11PL == 0)
#define  MG5_1_111PL    ~(1 << 10)
#else
#define  MG5_1_111PL    0xFFFF
#endif

#if (G5_12PL >= G5_1PL) || (G5_12PL == 0)
#define  MG5_1_112PL    ~(1 << 11)
#else
#define  MG5_1_112PL    0xFFFF
#endif

#if (G5_13PL >= G5_1PL) || (G5_13PL == 0)
#define  MG5_1_113PL    ~(1 << 12)
#else
#define  MG5_1_113PL    0xFFFF
#endif

#if (G5_14PL >= G5_1PL) || (G5_14PL == 0)
#define  MG5_1_114PL    ~(1 << 13)
#else
#define  MG5_1_114PL    0xFFFF
#endif

#if (G5_15PL >= G5_1PL) || (G5_15PL == 0)
#define  MG5_1_115PL    ~(1 << 14)
#else
#define  MG5_1_115PL    0xFFFF
#endif

#if (G5_16PL >= G5_1PL) || (G5_16PL == 0)
#define  MG5_1_116PL    ~(1 << 15)
#else
#define  MG5_1_116PL    0xFFFF
#endif

#define  MG5_1_11PL	0xFFFE
#define  MG5_1    (MG5_1_11PL & MG5_1_12PL & MG5_1_13PL & MG5_1_14PL & \
                    MG5_1_15PL & MG5_1_16PL & MG5_1_17PL & MG5_1_18PL & \
                    MG5_1_19PL & MG5_1_110PL & MG5_1_111PL & MG5_1_112PL & \
                    MG5_1_113PL & MG5_1_114PL & MG5_1_115PL & MG5_1_116PL)
// End of MG5_1:
// Beginning of MG52:
#if (G5_1PL >= G5_2PL) || (G5_1PL == 0)
#define  MG5_2_11PL    ~(1 << 0)
#else
#define  MG5_2_11PL    0xFFFF
#endif

#if (G5_3PL >= G5_2PL) || (G5_3PL == 0)
#define  MG5_2_13PL    ~(1 << 2)
#else
#define  MG5_2_13PL    0xFFFF
#endif

#if (G5_4PL >= G5_2PL) || (G5_4PL == 0)
#define  MG5_2_14PL    ~(1 << 3)
#else
#define  MG5_2_14PL    0xFFFF
#endif

#if (G5_5PL >= G5_2PL) || (G5_5PL == 0)
#define  MG5_2_15PL    ~(1 << 4)
#else
#define  MG5_2_15PL    0xFFFF
#endif

#if (G5_6PL >= G5_2PL) || (G5_6PL == 0)
#define  MG5_2_16PL    ~(1 << 5)
#else
#define  MG5_2_16PL    0xFFFF
#endif

#if (G5_7PL >= G5_2PL) || (G5_7PL == 0)
#define  MG5_2_17PL    ~(1 << 6)
#else
#define  MG5_2_17PL    0xFFFF
#endif

#if (G5_8PL >= G5_2PL) || (G5_8PL == 0)
#define  MG5_2_18PL    ~(1 << 7)
#else
#define  MG5_2_18PL    0xFFFF
#endif

#if (G5_9PL >= G5_2PL) || (G5_9PL == 0)
#define  MG5_2_19PL    ~(1 << 8)
#else
#define  MG5_2_19PL    0xFFFF
#endif

#if (G5_10PL >= G5_2PL) || (G5_10PL == 0)
#define  MG5_2_110PL    ~(1 << 9)
#else
#define  MG5_2_110PL    0xFFFF
#endif

#if (G5_11PL >= G5_2PL) || (G5_11PL == 0)
#define  MG5_2_111PL    ~(1 << 10)
#else
#define  MG5_2_111PL    0xFFFF
#endif

#if (G5_12PL >= G5_2PL) || (G5_12PL == 0)
#define  MG5_2_112PL    ~(1 << 11)
#else
#define  MG5_2_112PL    0xFFFF
#endif

#if (G5_13PL >= G5_2PL) || (G5_13PL == 0)
#define  MG5_2_113PL    ~(1 << 12)
#else
#define  MG5_2_113PL    0xFFFF
#endif

#if (G5_14PL >= G5_2PL) || (G5_14PL == 0)
#define  MG5_2_114PL    ~(1 << 13)
#else
#define  MG5_2_114PL    0xFFFF
#endif

#if (G5_15PL >= G5_2PL) || (G5_15PL == 0)
#define  MG5_2_115PL    ~(1 << 14)
#else
#define  MG5_2_115PL    0xFFFF
#endif

#if (G5_16PL >= G5_2PL) || (G5_16PL == 0)
#define  MG5_2_116PL    ~(1 << 15)
#else
#define  MG5_2_116PL    0xFFFF
#endif

#define  MG5_2_12PL	0xFFFD
#define  MG5_2    (MG5_2_11PL & MG5_2_12PL & MG5_2_13PL & MG5_2_14PL & \
                    MG5_2_15PL & MG5_2_16PL & MG5_2_17PL & MG5_2_18PL & \
                    MG5_2_19PL & MG5_2_110PL & MG5_2_111PL & MG5_2_112PL & \
                    MG5_2_113PL & MG5_2_114PL & MG5_2_115PL & MG5_2_116PL)
// End of MG5_2:
// Beginning of MG53:
#if (G5_1PL >= G5_3PL) || (G5_1PL == 0)
#define  MG5_3_11PL    ~(1 << 0)
#else
#define  MG5_3_11PL    0xFFFF
#endif

#if (G5_2PL >= G5_3PL) || (G5_2PL == 0)
#define  MG5_3_12PL    ~(1 << 1)
#else
#define  MG5_3_12PL    0xFFFF
#endif

#if (G5_4PL >= G5_3PL) || (G5_4PL == 0)
#define  MG5_3_14PL    ~(1 << 3)
#else
#define  MG5_3_14PL    0xFFFF
#endif

#if (G5_5PL >= G5_3PL) || (G5_5PL == 0)
#define  MG5_3_15PL    ~(1 << 4)
#else
#define  MG5_3_15PL    0xFFFF
#endif

#if (G5_6PL >= G5_3PL) || (G5_6PL == 0)
#define  MG5_3_16PL    ~(1 << 5)
#else
#define  MG5_3_16PL    0xFFFF
#endif

#if (G5_7PL >= G5_3PL) || (G5_7PL == 0)
#define  MG5_3_17PL    ~(1 << 6)
#else
#define  MG5_3_17PL    0xFFFF
#endif

#if (G5_8PL >= G5_3PL) || (G5_8PL == 0)
#define  MG5_3_18PL    ~(1 << 7)
#else
#define  MG5_3_18PL    0xFFFF
#endif

#if (G5_9PL >= G5_3PL) || (G5_9PL == 0)
#define  MG5_3_19PL    ~(1 << 8)
#else
#define  MG5_3_19PL    0xFFFF
#endif

#if (G5_10PL >= G5_3PL) || (G5_10PL == 0)
#define  MG5_3_110PL    ~(1 << 9)
#else
#define  MG5_3_110PL    0xFFFF
#endif

#if (G5_11PL >= G5_3PL) || (G5_11PL == 0)
#define  MG5_3_111PL    ~(1 << 10)
#else
#define  MG5_3_111PL    0xFFFF
#endif

#if (G5_12PL >= G5_3PL) || (G5_12PL == 0)
#define  MG5_3_112PL    ~(1 << 11)
#else
#define  MG5_3_112PL    0xFFFF
#endif

#if (G5_13PL >= G5_3PL) || (G5_13PL == 0)
#define  MG5_3_113PL    ~(1 << 12)
#else
#define  MG5_3_113PL    0xFFFF
#endif

#if (G5_14PL >= G5_3PL) || (G5_14PL == 0)
#define  MG5_3_114PL    ~(1 << 13)
#else
#define  MG5_3_114PL    0xFFFF
#endif

#if (G5_15PL >= G5_3PL) || (G5_15PL == 0)
#define  MG5_3_115PL    ~(1 << 14)
#else
#define  MG5_3_115PL    0xFFFF
#endif

#if (G5_16PL >= G5_3PL) || (G5_16PL == 0)
#define  MG5_3_116PL    ~(1 << 15)
#else
#define  MG5_3_116PL    0xFFFF
#endif

#define  MG5_3_13PL	0xFFFB
#define  MG5_3    (MG5_3_11PL & MG5_3_12PL & MG5_3_13PL & MG5_3_14PL & \
                    MG5_3_15PL & MG5_3_16PL & MG5_3_17PL & MG5_3_18PL & \
                    MG5_3_19PL & MG5_3_110PL & MG5_3_111PL & MG5_3_112PL & \
                    MG5_3_113PL & MG5_3_114PL & MG5_3_115PL & MG5_3_116PL)
// End of MG5_3:
// Beginning of MG54:
#if (G5_1PL >= G5_4PL) || (G5_1PL == 0)
#define  MG5_4_11PL    ~(1 << 0)
#else
#define  MG5_4_11PL    0xFFFF
#endif

#if (G5_2PL >= G5_4PL) || (G5_2PL == 0)
#define  MG5_4_12PL    ~(1 << 1)
#else
#define  MG5_4_12PL    0xFFFF
#endif

#if (G5_3PL >= G5_4PL) || (G5_3PL == 0)
#define  MG5_4_13PL    ~(1 << 2)
#else
#define  MG5_4_13PL    0xFFFF
#endif

#if (G5_5PL >= G5_4PL) || (G5_5PL == 0)
#define  MG5_4_15PL    ~(1 << 4)
#else
#define  MG5_4_15PL    0xFFFF
#endif

#if (G5_6PL >= G5_4PL) || (G5_6PL == 0)
#define  MG5_4_16PL    ~(1 << 5)
#else
#define  MG5_4_16PL    0xFFFF
#endif

#if (G5_7PL >= G5_4PL) || (G5_7PL == 0)
#define  MG5_4_17PL    ~(1 << 6)
#else
#define  MG5_4_17PL    0xFFFF
#endif

#if (G5_8PL >= G5_4PL) || (G5_8PL == 0)
#define  MG5_4_18PL    ~(1 << 7)
#else
#define  MG5_4_18PL    0xFFFF
#endif

#if (G5_9PL >= G5_4PL) || (G5_9PL == 0)
#define  MG5_4_19PL    ~(1 << 8)
#else
#define  MG5_4_19PL    0xFFFF
#endif

#if (G5_10PL >= G5_4PL) || (G5_10PL == 0)
#define  MG5_4_110PL    ~(1 << 9)
#else
#define  MG5_4_110PL    0xFFFF
#endif

#if (G5_11PL >= G5_4PL) || (G5_11PL == 0)
#define  MG5_4_111PL    ~(1 << 10)
#else
#define  MG5_4_111PL    0xFFFF
#endif

#if (G5_12PL >= G5_4PL) || (G5_12PL == 0)
#define  MG5_4_112PL    ~(1 << 11)
#else
#define  MG5_4_112PL    0xFFFF
#endif

#if (G5_13PL >= G5_4PL) || (G5_13PL == 0)
#define  MG5_4_113PL    ~(1 << 12)
#else
#define  MG5_4_113PL    0xFFFF
#endif

#if (G5_14PL >= G5_4PL) || (G5_14PL == 0)
#define  MG5_4_114PL    ~(1 << 13)
#else
#define  MG5_4_114PL    0xFFFF
#endif

#if (G5_15PL >= G5_4PL) || (G5_15PL == 0)
#define  MG5_4_115PL    ~(1 << 14)
#else
#define  MG5_4_115PL    0xFFFF
#endif

#if (G5_16PL >= G5_4PL) || (G5_16PL == 0)
#define  MG5_4_116PL    ~(1 << 15)
#else
#define  MG5_4_116PL    0xFFFF
#endif

#define  MG5_4_14PL	0xFFF7
#define  MG5_4    (MG5_4_11PL & MG5_4_12PL & MG5_4_13PL & MG5_4_14PL & \
                    MG5_4_15PL & MG5_4_16PL & MG5_4_17PL & MG5_4_18PL & \
                    MG5_4_19PL & MG5_4_110PL & MG5_4_111PL & MG5_4_112PL & \
                    MG5_4_113PL & MG5_4_114PL & MG5_4_115PL & MG5_4_116PL)
// End of MG5_4:
// Beginning of MG55:
#if (G5_1PL >= G5_5PL) || (G5_1PL == 0)
#define  MG5_5_11PL    ~(1 << 0)
#else
#define  MG5_5_11PL    0xFFFF
#endif

#if (G5_2PL >= G5_5PL) || (G5_2PL == 0)
#define  MG5_5_12PL    ~(1 << 1)
#else
#define  MG5_5_12PL    0xFFFF
#endif

#if (G5_3PL >= G5_5PL) || (G5_3PL == 0)
#define  MG5_5_13PL    ~(1 << 2)
#else
#define  MG5_5_13PL    0xFFFF
#endif

#if (G5_4PL >= G5_5PL) || (G5_4PL == 0)
#define  MG5_5_14PL    ~(1 << 3)
#else
#define  MG5_5_14PL    0xFFFF
#endif

#if (G5_6PL >= G5_5PL) || (G5_6PL == 0)
#define  MG5_5_16PL    ~(1 << 5)
#else
#define  MG5_5_16PL    0xFFFF
#endif

#if (G5_7PL >= G5_5PL) || (G5_7PL == 0)
#define  MG5_5_17PL    ~(1 << 6)
#else
#define  MG5_5_17PL    0xFFFF
#endif

#if (G5_8PL >= G5_5PL) || (G5_8PL == 0)
#define  MG5_5_18PL    ~(1 << 7)
#else
#define  MG5_5_18PL    0xFFFF
#endif

#if (G5_9PL >= G5_5PL) || (G5_9PL == 0)
#define  MG5_5_19PL    ~(1 << 8)
#else
#define  MG5_5_19PL    0xFFFF
#endif

#if (G5_10PL >= G5_5PL) || (G5_10PL == 0)
#define  MG5_5_110PL    ~(1 << 9)
#else
#define  MG5_5_110PL    0xFFFF
#endif

#if (G5_11PL >= G5_5PL) || (G5_11PL == 0)
#define  MG5_5_111PL    ~(1 << 10)
#else
#define  MG5_5_111PL    0xFFFF
#endif

#if (G5_12PL >= G5_5PL) || (G5_12PL == 0)
#define  MG5_5_112PL    ~(1 << 11)
#else
#define  MG5_5_112PL    0xFFFF
#endif

#if (G5_13PL >= G5_5PL) || (G5_13PL == 0)
#define  MG5_5_113PL    ~(1 << 12)
#else
#define  MG5_5_113PL    0xFFFF
#endif

#if (G5_14PL >= G5_5PL) || (G5_14PL == 0)
#define  MG5_5_114PL    ~(1 << 13)
#else
#define  MG5_5_114PL    0xFFFF
#endif

#if (G5_15PL >= G5_5PL) || (G5_15PL == 0)
#define  MG5_5_115PL    ~(1 << 14)
#else
#define  MG5_5_115PL    0xFFFF
#endif

#if (G5_16PL >= G5_5PL) || (G5_16PL == 0)
#define  MG5_5_116PL    ~(1 << 15)
#else
#define  MG5_5_116PL    0xFFFF
#endif

#define  MG5_5_15PL	0xFFEF
#define  MG5_5    (MG5_5_11PL & MG5_5_12PL & MG5_5_13PL & MG5_5_14PL & \
                    MG5_5_15PL & MG5_5_16PL & MG5_5_17PL & MG5_5_18PL & \
                    MG5_5_19PL & MG5_5_110PL & MG5_5_111PL & MG5_5_112PL & \
                    MG5_5_113PL & MG5_5_114PL & MG5_5_115PL & MG5_5_116PL)
// End of MG5_5:
// Beginning of MG56:
#if (G5_1PL >= G5_6PL) || (G5_1PL == 0)
#define  MG5_6_11PL    ~(1 << 0)
#else
#define  MG5_6_11PL    0xFFFF
#endif

#if (G5_2PL >= G5_6PL) || (G5_2PL == 0)
#define  MG5_6_12PL    ~(1 << 1)
#else
#define  MG5_6_12PL    0xFFFF
#endif

#if (G5_3PL >= G5_6PL) || (G5_3PL == 0)
#define  MG5_6_13PL    ~(1 << 2)
#else
#define  MG5_6_13PL    0xFFFF
#endif

#if (G5_4PL >= G5_6PL) || (G5_4PL == 0)
#define  MG5_6_14PL    ~(1 << 3)
#else
#define  MG5_6_14PL    0xFFFF
#endif

#if (G5_5PL >= G5_6PL) || (G5_5PL == 0)
#define  MG5_6_15PL    ~(1 << 4)
#else
#define  MG5_6_15PL    0xFFFF
#endif

#if (G5_7PL >= G5_6PL) || (G5_7PL == 0)
#define  MG5_6_17PL    ~(1 << 6)
#else
#define  MG5_6_17PL    0xFFFF
#endif

#if (G5_8PL >= G5_6PL) || (G5_8PL == 0)
#define  MG5_6_18PL    ~(1 << 7)
#else
#define  MG5_6_18PL    0xFFFF
#endif

#if (G5_9PL >= G5_6PL) || (G5_9PL == 0)
#define  MG5_6_19PL    ~(1 << 8)
#else
#define  MG5_6_19PL    0xFFFF
#endif

#if (G5_10PL >= G5_6PL) || (G5_10PL == 0)
#define  MG5_6_110PL    ~(1 << 9)
#else
#define  MG5_6_110PL    0xFFFF
#endif

#if (G5_11PL >= G5_6PL) || (G5_11PL == 0)
#define  MG5_6_111PL    ~(1 << 10)
#else
#define  MG5_6_111PL    0xFFFF
#endif

#if (G5_12PL >= G5_6PL) || (G5_12PL == 0)
#define  MG5_6_112PL    ~(1 << 11)
#else
#define  MG5_6_112PL    0xFFFF
#endif

#if (G5_13PL >= G5_6PL) || (G5_13PL == 0)
#define  MG5_6_113PL    ~(1 << 12)
#else
#define  MG5_6_113PL    0xFFFF
#endif

#if (G5_14PL >= G5_6PL) || (G5_14PL == 0)
#define  MG5_6_114PL    ~(1 << 13)
#else
#define  MG5_6_114PL    0xFFFF
#endif

#if (G5_15PL >= G5_6PL) || (G5_15PL == 0)
#define  MG5_6_115PL    ~(1 << 14)
#else
#define  MG5_6_115PL    0xFFFF
#endif

#if (G5_16PL >= G5_6PL) || (G5_16PL == 0)
#define  MG5_6_116PL    ~(1 << 15)
#else
#define  MG5_6_116PL    0xFFFF
#endif

#define  MG5_6_16PL	0xFFDF
#define  MG5_6    (MG5_6_11PL & MG5_6_12PL & MG5_6_13PL & MG5_6_14PL & \
                    MG5_6_15PL & MG5_6_16PL & MG5_6_17PL & MG5_6_18PL & \
                    MG5_6_19PL & MG5_6_110PL & MG5_6_111PL & MG5_6_112PL & \
                    MG5_6_113PL & MG5_6_114PL & MG5_6_115PL & MG5_6_116PL)
// End of MG5_6:
// Beginning of MG57:
#if (G5_1PL >= G5_7PL) || (G5_1PL == 0)
#define  MG5_7_11PL    ~(1 << 0)
#else
#define  MG5_7_11PL    0xFFFF
#endif

#if (G5_2PL >= G5_7PL) || (G5_2PL == 0)
#define  MG5_7_12PL    ~(1 << 1)
#else
#define  MG5_7_12PL    0xFFFF
#endif

#if (G5_3PL >= G5_7PL) || (G5_3PL == 0)
#define  MG5_7_13PL    ~(1 << 2)
#else
#define  MG5_7_13PL    0xFFFF
#endif

#if (G5_4PL >= G5_7PL) || (G5_4PL == 0)
#define  MG5_7_14PL    ~(1 << 3)
#else
#define  MG5_7_14PL    0xFFFF
#endif

#if (G5_5PL >= G5_7PL) || (G5_5PL == 0)
#define  MG5_7_15PL    ~(1 << 4)
#else
#define  MG5_7_15PL    0xFFFF
#endif

#if (G5_6PL >= G5_7PL) || (G5_6PL == 0)
#define  MG5_7_16PL    ~(1 << 5)
#else
#define  MG5_7_16PL    0xFFFF
#endif

#if (G5_8PL >= G5_7PL) || (G5_8PL == 0)
#define  MG5_7_18PL    ~(1 << 7)
#else
#define  MG5_7_18PL    0xFFFF
#endif

#if (G5_9PL >= G5_7PL) || (G5_9PL == 0)
#define  MG5_7_19PL    ~(1 << 8)
#else
#define  MG5_7_19PL    0xFFFF
#endif

#if (G5_10PL >= G5_7PL) || (G5_10PL == 0)
#define  MG5_7_110PL    ~(1 << 9)
#else
#define  MG5_7_110PL    0xFFFF
#endif

#if (G5_11PL >= G5_7PL) || (G5_11PL == 0)
#define  MG5_7_111PL    ~(1 << 10)
#else
#define  MG5_7_111PL    0xFFFF
#endif

#if (G5_12PL >= G5_7PL) || (G5_12PL == 0)
#define  MG5_7_112PL    ~(1 << 11)
#else
#define  MG5_7_112PL    0xFFFF
#endif

#if (G5_13PL >= G5_7PL) || (G5_13PL == 0)
#define  MG5_7_113PL    ~(1 << 12)
#else
#define  MG5_7_113PL    0xFFFF
#endif

#if (G5_14PL >= G5_7PL) || (G5_14PL == 0)
#define  MG5_7_114PL    ~(1 << 13)
#else
#define  MG5_7_114PL    0xFFFF
#endif

#if (G5_15PL >= G5_7PL) || (G5_15PL == 0)
#define  MG5_7_115PL    ~(1 << 14)
#else
#define  MG5_7_115PL    0xFFFF
#endif

#if (G5_16PL >= G5_7PL) || (G5_16PL == 0)
#define  MG5_7_116PL    ~(1 << 15)
#else
#define  MG5_7_116PL    0xFFFF
#endif

#define  MG5_7_17PL	0xFFBF
#define  MG5_7    (MG5_7_11PL & MG5_7_12PL & MG5_7_13PL & MG5_7_14PL & \
                    MG5_7_15PL & MG5_7_16PL & MG5_7_17PL & MG5_7_18PL & \
                    MG5_7_19PL & MG5_7_110PL & MG5_7_111PL & MG5_7_112PL & \
                    MG5_7_113PL & MG5_7_114PL & MG5_7_115PL & MG5_7_116PL)
// End of MG5_7:
// Beginning of MG58:
#if (G5_1PL >= G5_8PL) || (G5_1PL == 0)
#define  MG5_8_11PL    ~(1 << 0)
#else
#define  MG5_8_11PL    0xFFFF
#endif

#if (G5_2PL >= G5_8PL) || (G5_2PL == 0)
#define  MG5_8_12PL    ~(1 << 1)
#else
#define  MG5_8_12PL    0xFFFF
#endif

#if (G5_3PL >= G5_8PL) || (G5_3PL == 0)
#define  MG5_8_13PL    ~(1 << 2)
#else
#define  MG5_8_13PL    0xFFFF
#endif

#if (G5_4PL >= G5_8PL) || (G5_4PL == 0)
#define  MG5_8_14PL    ~(1 << 3)
#else
#define  MG5_8_14PL    0xFFFF
#endif

#if (G5_5PL >= G5_8PL) || (G5_5PL == 0)
#define  MG5_8_15PL    ~(1 << 4)
#else
#define  MG5_8_15PL    0xFFFF
#endif

#if (G5_6PL >= G5_8PL) || (G5_6PL == 0)
#define  MG5_8_16PL    ~(1 << 5)
#else
#define  MG5_8_16PL    0xFFFF
#endif

#if (G5_7PL >= G5_8PL) || (G5_7PL == 0)
#define  MG5_8_17PL    ~(1 << 6)
#else
#define  MG5_8_17PL    0xFFFF
#endif

#if (G5_9PL >= G5_8PL) || (G5_9PL == 0)
#define  MG5_8_19PL    ~(1 << 8)
#else
#define  MG5_8_19PL    0xFFFF
#endif

#if (G5_10PL >= G5_8PL) || (G5_10PL == 0)
#define  MG5_8_110PL    ~(1 << 9)
#else
#define  MG5_8_110PL    0xFFFF
#endif

#if (G5_11PL >= G5_8PL) || (G5_11PL == 0)
#define  MG5_8_111PL    ~(1 << 10)
#else
#define  MG5_8_111PL    0xFFFF
#endif

#if (G5_12PL >= G5_8PL) || (G5_12PL == 0)
#define  MG5_8_112PL    ~(1 << 11)
#else
#define  MG5_8_112PL    0xFFFF
#endif

#if (G5_13PL >= G5_8PL) || (G5_13PL == 0)
#define  MG5_8_113PL    ~(1 << 12)
#else
#define  MG5_8_113PL    0xFFFF
#endif

#if (G5_14PL >= G5_8PL) || (G5_14PL == 0)
#define  MG5_8_114PL    ~(1 << 13)
#else
#define  MG5_8_114PL    0xFFFF
#endif

#if (G5_15PL >= G5_8PL) || (G5_15PL == 0)
#define  MG5_8_115PL    ~(1 << 14)
#else
#define  MG5_8_115PL    0xFFFF
#endif

#if (G5_16PL >= G5_8PL) || (G5_16PL == 0)
#define  MG5_8_116PL    ~(1 << 15)
#else
#define  MG5_8_116PL    0xFFFF
#endif

#define  MG5_8_18PL	0xFF7F
#define  MG5_8    (MG5_8_11PL & MG5_8_12PL & MG5_8_13PL & MG5_8_14PL & \
                    MG5_8_15PL & MG5_8_16PL & MG5_8_17PL & MG5_8_18PL & \
                    MG5_8_19PL & MG5_8_110PL & MG5_8_111PL & MG5_8_112PL & \
                    MG5_8_113PL & MG5_8_114PL & MG5_8_115PL & MG5_8_116PL)
// End of MG5_8:
// Beginning of MG59:
#if (G5_1PL >= G5_9PL) || (G5_1PL == 0)
#define  MG5_9_11PL    ~(1 << 0)
#else
#define  MG5_9_11PL    0xFFFF
#endif

#if (G5_2PL >= G5_9PL) || (G5_2PL == 0)
#define  MG5_9_12PL    ~(1 << 1)
#else
#define  MG5_9_12PL    0xFFFF
#endif

#if (G5_3PL >= G5_9PL) || (G5_3PL == 0)
#define  MG5_9_13PL    ~(1 << 2)
#else
#define  MG5_9_13PL    0xFFFF
#endif

#if (G5_4PL >= G5_9PL) || (G5_4PL == 0)
#define  MG5_9_14PL    ~(1 << 3)
#else
#define  MG5_9_14PL    0xFFFF
#endif

#if (G5_5PL >= G5_9PL) || (G5_5PL == 0)
#define  MG5_9_15PL    ~(1 << 4)
#else
#define  MG5_9_15PL    0xFFFF
#endif

#if (G5_6PL >= G5_9PL) || (G5_6PL == 0)
#define  MG5_9_16PL    ~(1 << 5)
#else
#define  MG5_9_16PL    0xFFFF
#endif

#if (G5_7PL >= G5_9PL) || (G5_7PL == 0)
#define  MG5_9_17PL    ~(1 << 6)
#else
#define  MG5_9_17PL    0xFFFF
#endif

#if (G5_8PL >= G5_9PL) || (G5_8PL == 0)
#define  MG5_9_18PL    ~(1 << 7)
#else
#define  MG5_9_18PL    0xFFFF
#endif

#if (G5_10PL >= G5_9PL) || (G5_10PL == 0)
#define  MG5_9_110PL    ~(1 << 9)
#else
#define  MG5_9_110PL    0xFFFF
#endif

#if (G5_11PL >= G5_9PL) || (G5_11PL == 0)
#define  MG5_9_111PL    ~(1 << 10)
#else
#define  MG5_9_111PL    0xFFFF
#endif

#if (G5_12PL >= G5_9PL) || (G5_12PL == 0)
#define  MG5_9_112PL    ~(1 << 11)
#else
#define  MG5_9_112PL    0xFFFF
#endif

#if (G5_13PL >= G5_9PL) || (G5_13PL == 0)
#define  MG5_9_113PL    ~(1 << 12)
#else
#define  MG5_9_113PL    0xFFFF
#endif

#if (G5_14PL >= G5_9PL) || (G5_14PL == 0)
#define  MG5_9_114PL    ~(1 << 13)
#else
#define  MG5_9_114PL    0xFFFF
#endif

#if (G5_15PL >= G5_9PL) || (G5_15PL == 0)
#define  MG5_9_115PL    ~(1 << 14)
#else
#define  MG5_9_115PL    0xFFFF
#endif

#if (G5_16PL >= G5_9PL) || (G5_16PL == 0)
#define  MG5_9_116PL    ~(1 << 15)
#else
#define  MG5_9_116PL    0xFFFF
#endif

#define  MG5_9_19PL	0xFEFF
#define  MG5_9    (MG5_9_11PL & MG5_9_12PL & MG5_9_13PL & MG5_9_14PL & \
                    MG5_9_15PL & MG5_9_16PL & MG5_9_17PL & MG5_9_18PL & \
                    MG5_9_19PL & MG5_9_110PL & MG5_9_111PL & MG5_9_112PL & \
                    MG5_9_113PL & MG5_9_114PL & MG5_9_115PL & MG5_9_116PL)
// End of MG5_9:
// Beginning of MG510:
#if (G5_1PL >= G5_10PL) || (G5_1PL == 0)
#define  MG5_10_11PL    ~(1 << 0)
#else
#define  MG5_10_11PL    0xFFFF
#endif

#if (G5_2PL >= G5_10PL) || (G5_2PL == 0)
#define  MG5_10_12PL    ~(1 << 1)
#else
#define  MG5_10_12PL    0xFFFF
#endif

#if (G5_3PL >= G5_10PL) || (G5_3PL == 0)
#define  MG5_10_13PL    ~(1 << 2)
#else
#define  MG5_10_13PL    0xFFFF
#endif

#if (G5_4PL >= G5_10PL) || (G5_4PL == 0)
#define  MG5_10_14PL    ~(1 << 3)
#else
#define  MG5_10_14PL    0xFFFF
#endif

#if (G5_5PL >= G5_10PL) || (G5_5PL == 0)
#define  MG5_10_15PL    ~(1 << 4)
#else
#define  MG5_10_15PL    0xFFFF
#endif

#if (G5_6PL >= G5_10PL) || (G5_6PL == 0)
#define  MG5_10_16PL    ~(1 << 5)
#else
#define  MG5_10_16PL    0xFFFF
#endif

#if (G5_7PL >= G5_10PL) || (G5_7PL == 0)
#define  MG5_10_17PL    ~(1 << 6)
#else
#define  MG5_10_17PL    0xFFFF
#endif

#if (G5_8PL >= G5_10PL) || (G5_8PL == 0)
#define  MG5_10_18PL    ~(1 << 7)
#else
#define  MG5_10_18PL    0xFFFF
#endif

#if (G5_9PL >= G5_10PL) || (G5_9PL == 0)
#define  MG5_10_19PL    ~(1 << 8)
#else
#define  MG5_10_19PL    0xFFFF
#endif

#if (G5_11PL >= G5_10PL) || (G5_11PL == 0)
#define  MG5_10_111PL    ~(1 << 10)
#else
#define  MG5_10_111PL    0xFFFF
#endif

#if (G5_12PL >= G5_10PL) || (G5_12PL == 0)
#define  MG5_10_112PL    ~(1 << 11)
#else
#define  MG5_10_112PL    0xFFFF
#endif

#if (G5_13PL >= G5_10PL) || (G5_13PL == 0)
#define  MG5_10_113PL    ~(1 << 12)
#else
#define  MG5_10_113PL    0xFFFF
#endif

#if (G5_14PL >= G5_10PL) || (G5_14PL == 0)
#define  MG5_10_114PL    ~(1 << 13)
#else
#define  MG5_10_114PL    0xFFFF
#endif

#if (G5_15PL >= G5_10PL) || (G5_15PL == 0)
#define  MG5_10_115PL    ~(1 << 14)
#else
#define  MG5_10_115PL    0xFFFF
#endif

#if (G5_16PL >= G5_10PL) || (G5_16PL == 0)
#define  MG5_10_116PL    ~(1 << 15)
#else
#define  MG5_10_116PL    0xFFFF
#endif

#define  MG5_10_110PL	0xFDFF
#define  MG5_10    (MG5_10_11PL & MG5_10_12PL & MG5_10_13PL & MG5_10_14PL & \
                    MG5_10_15PL & MG5_10_16PL & MG5_10_17PL & MG5_10_18PL & \
                    MG5_10_19PL & MG5_10_110PL & MG5_10_111PL & MG5_10_112PL & \
                    MG5_10_113PL & MG5_10_114PL & MG5_10_115PL & MG5_10_116PL)
// End of MG5_10:
// Beginning of MG511:
#if (G5_1PL >= G5_11PL) || (G5_1PL == 0)
#define  MG5_11_11PL    ~(1 << 0)
#else
#define  MG5_11_11PL    0xFFFF
#endif

#if (G5_2PL >= G5_11PL) || (G5_2PL == 0)
#define  MG5_11_12PL    ~(1 << 1)
#else
#define  MG5_11_12PL    0xFFFF
#endif

#if (G5_3PL >= G5_11PL) || (G5_3PL == 0)
#define  MG5_11_13PL    ~(1 << 2)
#else
#define  MG5_11_13PL    0xFFFF
#endif

#if (G5_4PL >= G5_11PL) || (G5_4PL == 0)
#define  MG5_11_14PL    ~(1 << 3)
#else
#define  MG5_11_14PL    0xFFFF
#endif

#if (G5_5PL >= G5_11PL) || (G5_5PL == 0)
#define  MG5_11_15PL    ~(1 << 4)
#else
#define  MG5_11_15PL    0xFFFF
#endif

#if (G5_6PL >= G5_11PL) || (G5_6PL == 0)
#define  MG5_11_16PL    ~(1 << 5)
#else
#define  MG5_11_16PL    0xFFFF
#endif

#if (G5_7PL >= G5_11PL) || (G5_7PL == 0)
#define  MG5_11_17PL    ~(1 << 6)
#else
#define  MG5_11_17PL    0xFFFF
#endif

#if (G5_8PL >= G5_11PL) || (G5_8PL == 0)
#define  MG5_11_18PL    ~(1 << 7)
#else
#define  MG5_11_18PL    0xFFFF
#endif

#if (G5_9PL >= G5_11PL) || (G5_9PL == 0)
#define  MG5_11_19PL    ~(1 << 8)
#else
#define  MG5_11_19PL    0xFFFF
#endif

#if (G5_10PL >= G5_11PL) || (G5_10PL == 0)
#define  MG5_11_110PL    ~(1 << 9)
#else
#define  MG5_11_110PL    0xFFFF
#endif

#if (G5_12PL >= G5_11PL) || (G5_12PL == 0)
#define  MG5_11_112PL    ~(1 << 11)
#else
#define  MG5_11_112PL    0xFFFF
#endif

#if (G5_13PL >= G5_11PL) || (G5_13PL == 0)
#define  MG5_11_113PL    ~(1 << 12)
#else
#define  MG5_11_113PL    0xFFFF
#endif

#if (G5_14PL >= G5_11PL) || (G5_14PL == 0)
#define  MG5_11_114PL    ~(1 << 13)
#else
#define  MG5_11_114PL    0xFFFF
#endif

#if (G5_15PL >= G5_11PL) || (G5_15PL == 0)
#define  MG5_11_115PL    ~(1 << 14)
#else
#define  MG5_11_115PL    0xFFFF
#endif

#if (G5_16PL >= G5_11PL) || (G5_16PL == 0)
#define  MG5_11_116PL    ~(1 << 15)
#else
#define  MG5_11_116PL    0xFFFF
#endif

#define  MG5_11_111PL	0xFBFF
#define  MG5_11    (MG5_11_11PL & MG5_11_12PL & MG5_11_13PL & MG5_11_14PL & \
                    MG5_11_15PL & MG5_11_16PL & MG5_11_17PL & MG5_11_18PL & \
                    MG5_11_19PL & MG5_11_110PL & MG5_11_111PL & MG5_11_112PL & \
                    MG5_11_113PL & MG5_11_114PL & MG5_11_115PL & MG5_11_116PL)
// End of MG5_11:
// Beginning of MG512:
#if (G5_1PL >= G5_12PL) || (G5_1PL == 0)
#define  MG5_12_11PL    ~(1 << 0)
#else
#define  MG5_12_11PL    0xFFFF
#endif

#if (G5_2PL >= G5_12PL) || (G5_2PL == 0)
#define  MG5_12_12PL    ~(1 << 1)
#else
#define  MG5_12_12PL    0xFFFF
#endif

#if (G5_3PL >= G5_12PL) || (G5_3PL == 0)
#define  MG5_12_13PL    ~(1 << 2)
#else
#define  MG5_12_13PL    0xFFFF
#endif

#if (G5_4PL >= G5_12PL) || (G5_4PL == 0)
#define  MG5_12_14PL    ~(1 << 3)
#else
#define  MG5_12_14PL    0xFFFF
#endif

#if (G5_5PL >= G5_12PL) || (G5_5PL == 0)
#define  MG5_12_15PL    ~(1 << 4)
#else
#define  MG5_12_15PL    0xFFFF
#endif

#if (G5_6PL >= G5_12PL) || (G5_6PL == 0)
#define  MG5_12_16PL    ~(1 << 5)
#else
#define  MG5_12_16PL    0xFFFF
#endif

#if (G5_7PL >= G5_12PL) || (G5_7PL == 0)
#define  MG5_12_17PL    ~(1 << 6)
#else
#define  MG5_12_17PL    0xFFFF
#endif

#if (G5_8PL >= G5_12PL) || (G5_8PL == 0)
#define  MG5_12_18PL    ~(1 << 7)
#else
#define  MG5_12_18PL    0xFFFF
#endif

#if (G5_9PL >= G5_12PL) || (G5_9PL == 0)
#define  MG5_12_19PL    ~(1 << 8)
#else
#define  MG5_12_19PL    0xFFFF
#endif

#if (G5_10PL >= G5_12PL) || (G5_10PL == 0)
#define  MG5_12_110PL    ~(1 << 9)
#else
#define  MG5_12_110PL    0xFFFF
#endif

#if (G5_11PL >= G5_12PL) || (G5_11PL == 0)
#define  MG5_12_111PL    ~(1 << 10)
#else
#define  MG5_12_111PL    0xFFFF
#endif

#if (G5_13PL >= G5_12PL) || (G5_13PL == 0)
#define  MG5_12_113PL    ~(1 << 12)
#else
#define  MG5_12_113PL    0xFFFF
#endif

#if (G5_14PL >= G5_12PL) || (G5_14PL == 0)
#define  MG5_12_114PL    ~(1 << 13)
#else
#define  MG5_12_114PL    0xFFFF
#endif

#if (G5_15PL >= G5_12PL) || (G5_15PL == 0)
#define  MG5_12_115PL    ~(1 << 14)
#else
#define  MG5_12_115PL    0xFFFF
#endif

#if (G5_16PL >= G5_12PL) || (G5_16PL == 0)
#define  MG5_12_116PL    ~(1 << 15)
#else
#define  MG5_12_116PL    0xFFFF
#endif

#define  MG5_12_112PL	0xF7FF
#define  MG5_12    (MG5_12_11PL & MG5_12_12PL & MG5_12_13PL & MG5_12_14PL & \
                    MG5_12_15PL & MG5_12_16PL & MG5_12_17PL & MG5_12_18PL & \
                    MG5_12_19PL & MG5_12_110PL & MG5_12_111PL & MG5_12_112PL & \
                    MG5_12_113PL & MG5_12_114PL & MG5_12_115PL & MG5_12_116PL)
// End of MG5_12:
// Beginning of MG513:
#if (G5_1PL >= G5_13PL) || (G5_1PL == 0)
#define  MG5_13_11PL    ~(1 << 0)
#else
#define  MG5_13_11PL    0xFFFF
#endif

#if (G5_2PL >= G5_13PL) || (G5_2PL == 0)
#define  MG5_13_12PL    ~(1 << 1)
#else
#define  MG5_13_12PL    0xFFFF
#endif

#if (G5_3PL >= G5_13PL) || (G5_3PL == 0)
#define  MG5_13_13PL    ~(1 << 2)
#else
#define  MG5_13_13PL    0xFFFF
#endif

#if (G5_4PL >= G5_13PL) || (G5_4PL == 0)
#define  MG5_13_14PL    ~(1 << 3)
#else
#define  MG5_13_14PL    0xFFFF
#endif

#if (G5_5PL >= G5_13PL) || (G5_5PL == 0)
#define  MG5_13_15PL    ~(1 << 4)
#else
#define  MG5_13_15PL    0xFFFF
#endif

#if (G5_6PL >= G5_13PL) || (G5_6PL == 0)
#define  MG5_13_16PL    ~(1 << 5)
#else
#define  MG5_13_16PL    0xFFFF
#endif

#if (G5_7PL >= G5_13PL) || (G5_7PL == 0)
#define  MG5_13_17PL    ~(1 << 6)
#else
#define  MG5_13_17PL    0xFFFF
#endif

#if (G5_8PL >= G5_13PL) || (G5_8PL == 0)
#define  MG5_13_18PL    ~(1 << 7)
#else
#define  MG5_13_18PL    0xFFFF
#endif

#if (G5_9PL >= G5_13PL) || (G5_9PL == 0)
#define  MG5_13_19PL    ~(1 << 8)
#else
#define  MG5_13_19PL    0xFFFF
#endif

#if (G5_10PL >= G5_13PL) || (G5_10PL == 0)
#define  MG5_13_110PL    ~(1 << 9)
#else
#define  MG5_13_110PL    0xFFFF
#endif

#if (G5_11PL >= G5_13PL) || (G5_11PL == 0)
#define  MG5_13_111PL    ~(1 << 10)
#else
#define  MG5_13_111PL    0xFFFF
#endif

#if (G5_12PL >= G5_13PL) || (G5_12PL == 0)
#define  MG5_13_112PL    ~(1 << 11)
#else
#define  MG5_13_112PL    0xFFFF
#endif

#if (G5_14PL >= G5_13PL) || (G5_14PL == 0)
#define  MG5_13_114PL    ~(1 << 13)
#else
#define  MG5_13_114PL    0xFFFF
#endif

#if (G5_15PL >= G5_13PL) || (G5_15PL == 0)
#define  MG5_13_115PL    ~(1 << 14)
#else
#define  MG5_13_115PL    0xFFFF
#endif

#if (G5_16PL >= G5_13PL) || (G5_16PL == 0)
#define  MG5_13_116PL    ~(1 << 15)
#else
#define  MG5_13_116PL    0xFFFF
#endif

#define  MG5_13_113PL	0xEFFF
#define  MG5_13    (MG5_13_11PL & MG5_13_12PL & MG5_13_13PL & MG5_13_14PL & \
                    MG5_13_15PL & MG5_13_16PL & MG5_13_17PL & MG5_13_18PL & \
                    MG5_13_19PL & MG5_13_110PL & MG5_13_111PL & MG5_13_112PL & \
                    MG5_13_113PL & MG5_13_114PL & MG5_13_115PL & MG5_13_116PL)
// End of MG5_13:
// Beginning of MG514:
#if (G5_1PL >= G5_14PL) || (G5_1PL == 0)
#define  MG5_14_11PL    ~(1 << 0)
#else
#define  MG5_14_11PL    0xFFFF
#endif

#if (G5_2PL >= G5_14PL) || (G5_2PL == 0)
#define  MG5_14_12PL    ~(1 << 1)
#else
#define  MG5_14_12PL    0xFFFF
#endif

#if (G5_3PL >= G5_14PL) || (G5_3PL == 0)
#define  MG5_14_13PL    ~(1 << 2)
#else
#define  MG5_14_13PL    0xFFFF
#endif

#if (G5_4PL >= G5_14PL) || (G5_4PL == 0)
#define  MG5_14_14PL    ~(1 << 3)
#else
#define  MG5_14_14PL    0xFFFF
#endif

#if (G5_5PL >= G5_14PL) || (G5_5PL == 0)
#define  MG5_14_15PL    ~(1 << 4)
#else
#define  MG5_14_15PL    0xFFFF
#endif

#if (G5_6PL >= G5_14PL) || (G5_6PL == 0)
#define  MG5_14_16PL    ~(1 << 5)
#else
#define  MG5_14_16PL    0xFFFF
#endif

#if (G5_7PL >= G5_14PL) || (G5_7PL == 0)
#define  MG5_14_17PL    ~(1 << 6)
#else
#define  MG5_14_17PL    0xFFFF
#endif

#if (G5_8PL >= G5_14PL) || (G5_8PL == 0)
#define  MG5_14_18PL    ~(1 << 7)
#else
#define  MG5_14_18PL    0xFFFF
#endif

#if (G5_9PL >= G5_14PL) || (G5_9PL == 0)
#define  MG5_14_19PL    ~(1 << 8)
#else
#define  MG5_14_19PL    0xFFFF
#endif

#if (G5_10PL >= G5_14PL) || (G5_10PL == 0)
#define  MG5_14_110PL    ~(1 << 9)
#else
#define  MG5_14_110PL    0xFFFF
#endif

#if (G5_11PL >= G5_14PL) || (G5_11PL == 0)
#define  MG5_14_111PL    ~(1 << 10)
#else
#define  MG5_14_111PL    0xFFFF
#endif

#if (G5_12PL >= G5_14PL) || (G5_12PL == 0)
#define  MG5_14_112PL    ~(1 << 11)
#else
#define  MG5_14_112PL    0xFFFF
#endif

#if (G5_13PL >= G5_14PL) || (G5_13PL == 0)
#define  MG5_14_113PL    ~(1 << 12)
#else
#define  MG5_14_113PL    0xFFFF
#endif

#if (G5_15PL >= G5_14PL) || (G5_15PL == 0)
#define  MG5_14_115PL    ~(1 << 14)
#else
#define  MG5_14_115PL    0xFFFF
#endif

#if (G5_16PL >= G5_14PL) || (G5_16PL == 0)
#define  MG5_14_116PL    ~(1 << 15)
#else
#define  MG5_14_116PL    0xFFFF
#endif

#define  MG5_14_114PL	0xDFFF
#define  MG5_14    (MG5_14_11PL & MG5_14_12PL & MG5_14_13PL & MG5_14_14PL & \
                    MG5_14_15PL & MG5_14_16PL & MG5_14_17PL & MG5_14_18PL & \
                    MG5_14_19PL & MG5_14_110PL & MG5_14_111PL & MG5_14_112PL & \
                    MG5_14_113PL & MG5_14_114PL & MG5_14_115PL & MG5_14_116PL)
// End of MG5_14:
// Beginning of MG515:
#if (G5_1PL >= G5_15PL) || (G5_1PL == 0)
#define  MG5_15_11PL    ~(1 << 0)
#else
#define  MG5_15_11PL    0xFFFF
#endif

#if (G5_2PL >= G5_15PL) || (G5_2PL == 0)
#define  MG5_15_12PL    ~(1 << 1)
#else
#define  MG5_15_12PL    0xFFFF
#endif

#if (G5_3PL >= G5_15PL) || (G5_3PL == 0)
#define  MG5_15_13PL    ~(1 << 2)
#else
#define  MG5_15_13PL    0xFFFF
#endif

#if (G5_4PL >= G5_15PL) || (G5_4PL == 0)
#define  MG5_15_14PL    ~(1 << 3)
#else
#define  MG5_15_14PL    0xFFFF
#endif

#if (G5_5PL >= G5_15PL) || (G5_5PL == 0)
#define  MG5_15_15PL    ~(1 << 4)
#else
#define  MG5_15_15PL    0xFFFF
#endif

#if (G5_6PL >= G5_15PL) || (G5_6PL == 0)
#define  MG5_15_16PL    ~(1 << 5)
#else
#define  MG5_15_16PL    0xFFFF
#endif

#if (G5_7PL >= G5_15PL) || (G5_7PL == 0)
#define  MG5_15_17PL    ~(1 << 6)
#else
#define  MG5_15_17PL    0xFFFF
#endif

#if (G5_8PL >= G5_15PL) || (G5_8PL == 0)
#define  MG5_15_18PL    ~(1 << 7)
#else
#define  MG5_15_18PL    0xFFFF
#endif

#if (G5_9PL >= G5_15PL) || (G5_9PL == 0)
#define  MG5_15_19PL    ~(1 << 8)
#else
#define  MG5_15_19PL    0xFFFF
#endif

#if (G5_10PL >= G5_15PL) || (G5_10PL == 0)
#define  MG5_15_110PL    ~(1 << 9)
#else
#define  MG5_15_110PL    0xFFFF
#endif

#if (G5_11PL >= G5_15PL) || (G5_11PL == 0)
#define  MG5_15_111PL    ~(1 << 10)
#else
#define  MG5_15_111PL    0xFFFF
#endif

#if (G5_12PL >= G5_15PL) || (G5_12PL == 0)
#define  MG5_15_112PL    ~(1 << 11)
#else
#define  MG5_15_112PL    0xFFFF
#endif

#if (G5_13PL >= G5_15PL) || (G5_13PL == 0)
#define  MG5_15_113PL    ~(1 << 12)
#else
#define  MG5_15_113PL    0xFFFF
#endif

#if (G5_14PL >= G5_15PL) || (G5_14PL == 0)
#define  MG5_15_114PL    ~(1 << 13)
#else
#define  MG5_15_114PL    0xFFFF
#endif

#if (G5_16PL >= G5_15PL) || (G5_16PL == 0)
#define  MG5_15_116PL    ~(1 << 15)
#else
#define  MG5_15_116PL    0xFFFF
#endif

#define  MG5_15_115PL	0xBFFF
#define  MG5_15    (MG5_15_11PL & MG5_15_12PL & MG5_15_13PL & MG5_15_14PL & \
                    MG5_15_15PL & MG5_15_16PL & MG5_15_17PL & MG5_15_18PL & \
                    MG5_15_19PL & MG5_15_110PL & MG5_15_111PL & MG5_15_112PL & \
                    MG5_15_113PL & MG5_15_114PL & MG5_15_115PL & MG5_15_116PL)
// End of MG5_15:
// Beginning of MG516:
#if (G5_1PL >= G5_16PL) || (G5_1PL == 0)
#define  MG5_16_11PL    ~(1 << 0)
#else
#define  MG5_16_11PL    0xFFFF
#endif

#if (G5_2PL >= G5_16PL) || (G5_2PL == 0)
#define  MG5_16_12PL    ~(1 << 1)
#else
#define  MG5_16_12PL    0xFFFF
#endif

#if (G5_3PL >= G5_16PL) || (G5_3PL == 0)
#define  MG5_16_13PL    ~(1 << 2)
#else
#define  MG5_16_13PL    0xFFFF
#endif

#if (G5_4PL >= G5_16PL) || (G5_4PL == 0)
#define  MG5_16_14PL    ~(1 << 3)
#else
#define  MG5_16_14PL    0xFFFF
#endif

#if (G5_5PL >= G5_16PL) || (G5_5PL == 0)
#define  MG5_16_15PL    ~(1 << 4)
#else
#define  MG5_16_15PL    0xFFFF
#endif

#if (G5_6PL >= G5_16PL) || (G5_6PL == 0)
#define  MG5_16_16PL    ~(1 << 5)
#else
#define  MG5_16_16PL    0xFFFF
#endif

#if (G5_7PL >= G5_16PL) || (G5_7PL == 0)
#define  MG5_16_17PL    ~(1 << 6)
#else
#define  MG5_16_17PL    0xFFFF
#endif

#if (G5_8PL >= G5_16PL) || (G5_8PL == 0)
#define  MG5_16_18PL    ~(1 << 7)
#else
#define  MG5_16_18PL    0xFFFF
#endif

#if (G5_9PL >= G5_16PL) || (G5_9PL == 0)
#define  MG5_16_19PL    ~(1 << 8)
#else
#define  MG5_16_19PL    0xFFFF
#endif

#if (G5_10PL >= G5_16PL) || (G5_10PL == 0)
#define  MG5_16_110PL    ~(1 << 9)
#else
#define  MG5_16_110PL    0xFFFF
#endif

#if (G5_11PL >= G5_16PL) || (G5_11PL == 0)
#define  MG5_16_111PL    ~(1 << 10)
#else
#define  MG5_16_111PL    0xFFFF
#endif

#if (G5_12PL >= G5_16PL) || (G5_12PL == 0)
#define  MG5_16_112PL    ~(1 << 11)
#else
#define  MG5_16_112PL    0xFFFF
#endif

#if (G5_13PL >= G5_16PL) || (G5_13PL == 0)
#define  MG5_16_113PL    ~(1 << 12)
#else
#define  MG5_16_113PL    0xFFFF
#endif

#if (G5_14PL >= G5_16PL) || (G5_14PL == 0)
#define  MG5_16_114PL    ~(1 << 13)
#else
#define  MG5_16_114PL    0xFFFF
#endif

#if (G5_15PL >= G5_16PL) || (G5_15PL == 0)
#define  MG5_16_115PL    ~(1 << 14)
#else
#define  MG5_16_115PL    0xFFFF
#endif

#define  MG5_16_116PL	0x7FFF
#define  MG5_16    (MG5_16_11PL & MG5_16_12PL & MG5_16_13PL & MG5_16_14PL & \
                    MG5_16_15PL & MG5_16_16PL & MG5_16_17PL & MG5_16_18PL & \
                    MG5_16_19PL & MG5_16_110PL & MG5_16_111PL & MG5_16_112PL & \
                    MG5_16_113PL & MG5_16_114PL & MG5_16_115PL & MG5_16_116PL)
// End of MG5_16:


//-------------------------------------------------------------------------------
// Automatically generate PIEIER6 interrupt masks MG61 to MG616:

// Beginning of MG61:
#if (G6_2PL >= G6_1PL) || (G6_2PL == 0)
#define  MG6_1_12PL    ~(1 << 1)
#else
#define  MG6_1_12PL    0xFFFF
#endif

#if (G6_3PL >= G6_1PL) || (G6_3PL == 0)
#define  MG6_1_13PL    ~(1 << 2)
#else
#define  MG6_1_13PL    0xFFFF
#endif

#if (G6_4PL >= G6_1PL) || (G6_4PL == 0)
#define  MG6_1_14PL    ~(1 << 3)
#else
#define  MG6_1_14PL    0xFFFF
#endif

#if (G6_5PL >= G6_1PL) || (G6_5PL == 0)
#define  MG6_1_15PL    ~(1 << 4)
#else
#define  MG6_1_15PL    0xFFFF
#endif

#if (G6_6PL >= G6_1PL) || (G6_6PL == 0)
#define  MG6_1_16PL    ~(1 << 5)
#else
#define  MG6_1_16PL    0xFFFF
#endif

#if (G6_7PL >= G6_1PL) || (G6_7PL == 0)
#define  MG6_1_17PL    ~(1 << 6)
#else
#define  MG6_1_17PL    0xFFFF
#endif

#if (G6_8PL >= G6_1PL) || (G6_8PL == 0)
#define  MG6_1_18PL    ~(1 << 7)
#else
#define  MG6_1_18PL    0xFFFF
#endif

#if (G6_9PL >= G6_1PL) || (G6_9PL == 0)
#define  MG6_1_19PL    ~(1 << 8)
#else
#define  MG6_1_19PL    0xFFFF
#endif

#if (G6_10PL >= G6_1PL) || (G6_10PL == 0)
#define  MG6_1_110PL    ~(1 << 9)
#else
#define  MG6_1_110PL    0xFFFF
#endif

#if (G6_11PL >= G6_1PL) || (G6_11PL == 0)
#define  MG6_1_111PL    ~(1 << 10)
#else
#define  MG6_1_111PL    0xFFFF
#endif

#if (G6_12PL >= G6_1PL) || (G6_12PL == 0)
#define  MG6_1_112PL    ~(1 << 11)
#else
#define  MG6_1_112PL    0xFFFF
#endif

#if (G6_13PL >= G6_1PL) || (G6_13PL == 0)
#define  MG6_1_113PL    ~(1 << 12)
#else
#define  MG6_1_113PL    0xFFFF
#endif

#if (G6_14PL >= G6_1PL) || (G6_14PL == 0)
#define  MG6_1_114PL    ~(1 << 13)
#else
#define  MG6_1_114PL    0xFFFF
#endif

#if (G6_15PL >= G6_1PL) || (G6_15PL == 0)
#define  MG6_1_115PL    ~(1 << 14)
#else
#define  MG6_1_115PL    0xFFFF
#endif

#if (G6_16PL >= G6_1PL) || (G6_16PL == 0)
#define  MG6_1_116PL    ~(1 << 15)
#else
#define  MG6_1_116PL    0xFFFF
#endif

#define  MG6_1_11PL	0xFFFE
#define  MG6_1    (MG6_1_11PL & MG6_1_12PL & MG6_1_13PL & MG6_1_14PL & \
                    MG6_1_15PL & MG6_1_16PL & MG6_1_17PL & MG6_1_18PL & \
                    MG6_1_19PL & MG6_1_110PL & MG6_1_111PL & MG6_1_112PL & \
                    MG6_1_113PL & MG6_1_114PL & MG6_1_115PL & MG6_1_116PL)
// End of MG6_1:
// Beginning of MG62:
#if (G6_1PL >= G6_2PL) || (G6_1PL == 0)
#define  MG6_2_11PL    ~(1 << 0)
#else
#define  MG6_2_11PL    0xFFFF
#endif

#if (G6_3PL >= G6_2PL) || (G6_3PL == 0)
#define  MG6_2_13PL    ~(1 << 2)
#else
#define  MG6_2_13PL    0xFFFF
#endif

#if (G6_4PL >= G6_2PL) || (G6_4PL == 0)
#define  MG6_2_14PL    ~(1 << 3)
#else
#define  MG6_2_14PL    0xFFFF
#endif

#if (G6_5PL >= G6_2PL) || (G6_5PL == 0)
#define  MG6_2_15PL    ~(1 << 4)
#else
#define  MG6_2_15PL    0xFFFF
#endif

#if (G6_6PL >= G6_2PL) || (G6_6PL == 0)
#define  MG6_2_16PL    ~(1 << 5)
#else
#define  MG6_2_16PL    0xFFFF
#endif

#if (G6_7PL >= G6_2PL) || (G6_7PL == 0)
#define  MG6_2_17PL    ~(1 << 6)
#else
#define  MG6_2_17PL    0xFFFF
#endif

#if (G6_8PL >= G6_2PL) || (G6_8PL == 0)
#define  MG6_2_18PL    ~(1 << 7)
#else
#define  MG6_2_18PL    0xFFFF
#endif

#if (G6_9PL >= G6_2PL) || (G6_9PL == 0)
#define  MG6_2_19PL    ~(1 << 8)
#else
#define  MG6_2_19PL    0xFFFF
#endif

#if (G6_10PL >= G6_2PL) || (G6_10PL == 0)
#define  MG6_2_110PL    ~(1 << 9)
#else
#define  MG6_2_110PL    0xFFFF
#endif

#if (G6_11PL >= G6_2PL) || (G6_11PL == 0)
#define  MG6_2_111PL    ~(1 << 10)
#else
#define  MG6_2_111PL    0xFFFF
#endif

#if (G6_12PL >= G6_2PL) || (G6_12PL == 0)
#define  MG6_2_112PL    ~(1 << 11)
#else
#define  MG6_2_112PL    0xFFFF
#endif

#if (G6_13PL >= G6_2PL) || (G6_13PL == 0)
#define  MG6_2_113PL    ~(1 << 12)
#else
#define  MG6_2_113PL    0xFFFF
#endif

#if (G6_14PL >= G6_2PL) || (G6_14PL == 0)
#define  MG6_2_114PL    ~(1 << 13)
#else
#define  MG6_2_114PL    0xFFFF
#endif

#if (G6_15PL >= G6_2PL) || (G6_15PL == 0)
#define  MG6_2_115PL    ~(1 << 14)
#else
#define  MG6_2_115PL    0xFFFF
#endif

#if (G6_16PL >= G6_2PL) || (G6_16PL == 0)
#define  MG6_2_116PL    ~(1 << 15)
#else
#define  MG6_2_116PL    0xFFFF
#endif

#define  MG6_2_12PL	0xFFFD
#define  MG6_2    (MG6_2_11PL & MG6_2_12PL & MG6_2_13PL & MG6_2_14PL & \
                    MG6_2_15PL & MG6_2_16PL & MG6_2_17PL & MG6_2_18PL & \
                    MG6_2_19PL & MG6_2_110PL & MG6_2_111PL & MG6_2_112PL & \
                    MG6_2_113PL & MG6_2_114PL & MG6_2_115PL & MG6_2_116PL)
// End of MG6_2:
// Beginning of MG63:
#if (G6_1PL >= G6_3PL) || (G6_1PL == 0)
#define  MG6_3_11PL    ~(1 << 0)
#else
#define  MG6_3_11PL    0xFFFF
#endif

#if (G6_2PL >= G6_3PL) || (G6_2PL == 0)
#define  MG6_3_12PL    ~(1 << 1)
#else
#define  MG6_3_12PL    0xFFFF
#endif

#if (G6_4PL >= G6_3PL) || (G6_4PL == 0)
#define  MG6_3_14PL    ~(1 << 3)
#else
#define  MG6_3_14PL    0xFFFF
#endif

#if (G6_5PL >= G6_3PL) || (G6_5PL == 0)
#define  MG6_3_15PL    ~(1 << 4)
#else
#define  MG6_3_15PL    0xFFFF
#endif

#if (G6_6PL >= G6_3PL) || (G6_6PL == 0)
#define  MG6_3_16PL    ~(1 << 5)
#else
#define  MG6_3_16PL    0xFFFF
#endif

#if (G6_7PL >= G6_3PL) || (G6_7PL == 0)
#define  MG6_3_17PL    ~(1 << 6)
#else
#define  MG6_3_17PL    0xFFFF
#endif

#if (G6_8PL >= G6_3PL) || (G6_8PL == 0)
#define  MG6_3_18PL    ~(1 << 7)
#else
#define  MG6_3_18PL    0xFFFF
#endif

#if (G6_9PL >= G6_3PL) || (G6_9PL == 0)
#define  MG6_3_19PL    ~(1 << 8)
#else
#define  MG6_3_19PL    0xFFFF
#endif

#if (G6_10PL >= G6_3PL) || (G6_10PL == 0)
#define  MG6_3_110PL    ~(1 << 9)
#else
#define  MG6_3_110PL    0xFFFF
#endif

#if (G6_11PL >= G6_3PL) || (G6_11PL == 0)
#define  MG6_3_111PL    ~(1 << 10)
#else
#define  MG6_3_111PL    0xFFFF
#endif

#if (G6_12PL >= G6_3PL) || (G6_12PL == 0)
#define  MG6_3_112PL    ~(1 << 11)
#else
#define  MG6_3_112PL    0xFFFF
#endif

#if (G6_13PL >= G6_3PL) || (G6_13PL == 0)
#define  MG6_3_113PL    ~(1 << 12)
#else
#define  MG6_3_113PL    0xFFFF
#endif

#if (G6_14PL >= G6_3PL) || (G6_14PL == 0)
#define  MG6_3_114PL    ~(1 << 13)
#else
#define  MG6_3_114PL    0xFFFF
#endif

#if (G6_15PL >= G6_3PL) || (G6_15PL == 0)
#define  MG6_3_115PL    ~(1 << 14)
#else
#define  MG6_3_115PL    0xFFFF
#endif

#if (G6_16PL >= G6_3PL) || (G6_16PL == 0)
#define  MG6_3_116PL    ~(1 << 15)
#else
#define  MG6_3_116PL    0xFFFF
#endif

#define  MG6_3_13PL	0xFFFB
#define  MG6_3    (MG6_3_11PL & MG6_3_12PL & MG6_3_13PL & MG6_3_14PL & \
                    MG6_3_15PL & MG6_3_16PL & MG6_3_17PL & MG6_3_18PL & \
                    MG6_3_19PL & MG6_3_110PL & MG6_3_111PL & MG6_3_112PL & \
                    MG6_3_113PL & MG6_3_114PL & MG6_3_115PL & MG6_3_116PL)
// End of MG6_3:
// Beginning of MG64:
#if (G6_1PL >= G6_4PL) || (G6_1PL == 0)
#define  MG6_4_11PL    ~(1 << 0)
#else
#define  MG6_4_11PL    0xFFFF
#endif

#if (G6_2PL >= G6_4PL) || (G6_2PL == 0)
#define  MG6_4_12PL    ~(1 << 1)
#else
#define  MG6_4_12PL    0xFFFF
#endif

#if (G6_3PL >= G6_4PL) || (G6_3PL == 0)
#define  MG6_4_13PL    ~(1 << 2)
#else
#define  MG6_4_13PL    0xFFFF
#endif

#if (G6_5PL >= G6_4PL) || (G6_5PL == 0)
#define  MG6_4_15PL    ~(1 << 4)
#else
#define  MG6_4_15PL    0xFFFF
#endif

#if (G6_6PL >= G6_4PL) || (G6_6PL == 0)
#define  MG6_4_16PL    ~(1 << 5)
#else
#define  MG6_4_16PL    0xFFFF
#endif

#if (G6_7PL >= G6_4PL) || (G6_7PL == 0)
#define  MG6_4_17PL    ~(1 << 6)
#else
#define  MG6_4_17PL    0xFFFF
#endif

#if (G6_8PL >= G6_4PL) || (G6_8PL == 0)
#define  MG6_4_18PL    ~(1 << 7)
#else
#define  MG6_4_18PL    0xFFFF
#endif

#if (G6_9PL >= G6_4PL) || (G6_9PL == 0)
#define  MG6_4_19PL    ~(1 << 8)
#else
#define  MG6_4_19PL    0xFFFF
#endif

#if (G6_10PL >= G6_4PL) || (G6_10PL == 0)
#define  MG6_4_110PL    ~(1 << 9)
#else
#define  MG6_4_110PL    0xFFFF
#endif

#if (G6_11PL >= G6_4PL) || (G6_11PL == 0)
#define  MG6_4_111PL    ~(1 << 10)
#else
#define  MG6_4_111PL    0xFFFF
#endif

#if (G6_12PL >= G6_4PL) || (G6_12PL == 0)
#define  MG6_4_112PL    ~(1 << 11)
#else
#define  MG6_4_112PL    0xFFFF
#endif

#if (G6_13PL >= G6_4PL) || (G6_13PL == 0)
#define  MG6_4_113PL    ~(1 << 12)
#else
#define  MG6_4_113PL    0xFFFF
#endif

#if (G6_14PL >= G6_4PL) || (G6_14PL == 0)
#define  MG6_4_114PL    ~(1 << 13)
#else
#define  MG6_4_114PL    0xFFFF
#endif

#if (G6_15PL >= G6_4PL) || (G6_15PL == 0)
#define  MG6_4_115PL    ~(1 << 14)
#else
#define  MG6_4_115PL    0xFFFF
#endif

#if (G6_16PL >= G6_4PL) || (G6_16PL == 0)
#define  MG6_4_116PL    ~(1 << 15)
#else
#define  MG6_4_116PL    0xFFFF
#endif

#define  MG6_4_14PL	0xFFF7
#define  MG6_4    (MG6_4_11PL & MG6_4_12PL & MG6_4_13PL & MG6_4_14PL & \
                    MG6_4_15PL & MG6_4_16PL & MG6_4_17PL & MG6_4_18PL & \
                    MG6_4_19PL & MG6_4_110PL & MG6_4_111PL & MG6_4_112PL & \
                    MG6_4_113PL & MG6_4_114PL & MG6_4_115PL & MG6_4_116PL)
// End of MG6_4:
// Beginning of MG65:
#if (G6_1PL >= G6_5PL) || (G6_1PL == 0)
#define  MG6_5_11PL    ~(1 << 0)
#else
#define  MG6_5_11PL    0xFFFF
#endif

#if (G6_2PL >= G6_5PL) || (G6_2PL == 0)
#define  MG6_5_12PL    ~(1 << 1)
#else
#define  MG6_5_12PL    0xFFFF
#endif

#if (G6_3PL >= G6_5PL) || (G6_3PL == 0)
#define  MG6_5_13PL    ~(1 << 2)
#else
#define  MG6_5_13PL    0xFFFF
#endif

#if (G6_4PL >= G6_5PL) || (G6_4PL == 0)
#define  MG6_5_14PL    ~(1 << 3)
#else
#define  MG6_5_14PL    0xFFFF
#endif

#if (G6_6PL >= G6_5PL) || (G6_6PL == 0)
#define  MG6_5_16PL    ~(1 << 5)
#else
#define  MG6_5_16PL    0xFFFF
#endif

#if (G6_7PL >= G6_5PL) || (G6_7PL == 0)
#define  MG6_5_17PL    ~(1 << 6)
#else
#define  MG6_5_17PL    0xFFFF
#endif

#if (G6_8PL >= G6_5PL) || (G6_8PL == 0)
#define  MG6_5_18PL    ~(1 << 7)
#else
#define  MG6_5_18PL    0xFFFF
#endif

#if (G6_9PL >= G6_5PL) || (G6_9PL == 0)
#define  MG6_5_19PL    ~(1 << 8)
#else
#define  MG6_5_19PL    0xFFFF
#endif

#if (G6_10PL >= G6_5PL) || (G6_10PL == 0)
#define  MG6_5_110PL    ~(1 << 9)
#else
#define  MG6_5_110PL    0xFFFF
#endif

#if (G6_11PL >= G6_5PL) || (G6_11PL == 0)
#define  MG6_5_111PL    ~(1 << 10)
#else
#define  MG6_5_111PL    0xFFFF
#endif

#if (G6_12PL >= G6_5PL) || (G6_12PL == 0)
#define  MG6_5_112PL    ~(1 << 11)
#else
#define  MG6_5_112PL    0xFFFF
#endif

#if (G6_13PL >= G6_5PL) || (G6_13PL == 0)
#define  MG6_5_113PL    ~(1 << 12)
#else
#define  MG6_5_113PL    0xFFFF
#endif

#if (G6_14PL >= G6_5PL) || (G6_14PL == 0)
#define  MG6_5_114PL    ~(1 << 13)
#else
#define  MG6_5_114PL    0xFFFF
#endif

#if (G6_15PL >= G6_5PL) || (G6_15PL == 0)
#define  MG6_5_115PL    ~(1 << 14)
#else
#define  MG6_5_115PL    0xFFFF
#endif

#if (G6_16PL >= G6_5PL) || (G6_16PL == 0)
#define  MG6_5_116PL    ~(1 << 15)
#else
#define  MG6_5_116PL    0xFFFF
#endif

#define  MG6_5_15PL	0xFFEF
#define  MG6_5    (MG6_5_11PL & MG6_5_12PL & MG6_5_13PL & MG6_5_14PL & \
                    MG6_5_15PL & MG6_5_16PL & MG6_5_17PL & MG6_5_18PL & \
                    MG6_5_19PL & MG6_5_110PL & MG6_5_111PL & MG6_5_112PL & \
                    MG6_5_113PL & MG6_5_114PL & MG6_5_115PL & MG6_5_116PL)
// End of MG6_5:
// Beginning of MG66:
#if (G6_1PL >= G6_6PL) || (G6_1PL == 0)
#define  MG6_6_11PL    ~(1 << 0)
#else
#define  MG6_6_11PL    0xFFFF
#endif

#if (G6_2PL >= G6_6PL) || (G6_2PL == 0)
#define  MG6_6_12PL    ~(1 << 1)
#else
#define  MG6_6_12PL    0xFFFF
#endif

#if (G6_3PL >= G6_6PL) || (G6_3PL == 0)
#define  MG6_6_13PL    ~(1 << 2)
#else
#define  MG6_6_13PL    0xFFFF
#endif

#if (G6_4PL >= G6_6PL) || (G6_4PL == 0)
#define  MG6_6_14PL    ~(1 << 3)
#else
#define  MG6_6_14PL    0xFFFF
#endif

#if (G6_5PL >= G6_6PL) || (G6_5PL == 0)
#define  MG6_6_15PL    ~(1 << 4)
#else
#define  MG6_6_15PL    0xFFFF
#endif

#if (G6_7PL >= G6_6PL) || (G6_7PL == 0)
#define  MG6_6_17PL    ~(1 << 6)
#else
#define  MG6_6_17PL    0xFFFF
#endif

#if (G6_8PL >= G6_6PL) || (G6_8PL == 0)
#define  MG6_6_18PL    ~(1 << 7)
#else
#define  MG6_6_18PL    0xFFFF
#endif

#if (G6_9PL >= G6_6PL) || (G6_9PL == 0)
#define  MG6_6_19PL    ~(1 << 8)
#else
#define  MG6_6_19PL    0xFFFF
#endif

#if (G6_10PL >= G6_6PL) || (G6_10PL == 0)
#define  MG6_6_110PL    ~(1 << 9)
#else
#define  MG6_6_110PL    0xFFFF
#endif

#if (G6_11PL >= G6_6PL) || (G6_11PL == 0)
#define  MG6_6_111PL    ~(1 << 10)
#else
#define  MG6_6_111PL    0xFFFF
#endif

#if (G6_12PL >= G6_6PL) || (G6_12PL == 0)
#define  MG6_6_112PL    ~(1 << 11)
#else
#define  MG6_6_112PL    0xFFFF
#endif

#if (G6_13PL >= G6_6PL) || (G6_13PL == 0)
#define  MG6_6_113PL    ~(1 << 12)
#else
#define  MG6_6_113PL    0xFFFF
#endif

#if (G6_14PL >= G6_6PL) || (G6_14PL == 0)
#define  MG6_6_114PL    ~(1 << 13)
#else
#define  MG6_6_114PL    0xFFFF
#endif

#if (G6_15PL >= G6_6PL) || (G6_15PL == 0)
#define  MG6_6_115PL    ~(1 << 14)
#else
#define  MG6_6_115PL    0xFFFF
#endif

#if (G6_16PL >= G6_6PL) || (G6_16PL == 0)
#define  MG6_6_116PL    ~(1 << 15)
#else
#define  MG6_6_116PL    0xFFFF
#endif

#define  MG6_6_16PL	0xFFDF
#define  MG6_6    (MG6_6_11PL & MG6_6_12PL & MG6_6_13PL & MG6_6_14PL & \
                    MG6_6_15PL & MG6_6_16PL & MG6_6_17PL & MG6_6_18PL & \
                    MG6_6_19PL & MG6_6_110PL & MG6_6_111PL & MG6_6_112PL & \
                    MG6_6_113PL & MG6_6_114PL & MG6_6_115PL & MG6_6_116PL)
// End of MG6_6:
// Beginning of MG67:
#if (G6_1PL >= G6_7PL) || (G6_1PL == 0)
#define  MG6_7_11PL    ~(1 << 0)
#else
#define  MG6_7_11PL    0xFFFF
#endif

#if (G6_2PL >= G6_7PL) || (G6_2PL == 0)
#define  MG6_7_12PL    ~(1 << 1)
#else
#define  MG6_7_12PL    0xFFFF
#endif

#if (G6_3PL >= G6_7PL) || (G6_3PL == 0)
#define  MG6_7_13PL    ~(1 << 2)
#else
#define  MG6_7_13PL    0xFFFF
#endif

#if (G6_4PL >= G6_7PL) || (G6_4PL == 0)
#define  MG6_7_14PL    ~(1 << 3)
#else
#define  MG6_7_14PL    0xFFFF
#endif

#if (G6_5PL >= G6_7PL) || (G6_5PL == 0)
#define  MG6_7_15PL    ~(1 << 4)
#else
#define  MG6_7_15PL    0xFFFF
#endif

#if (G6_6PL >= G6_7PL) || (G6_6PL == 0)
#define  MG6_7_16PL    ~(1 << 5)
#else
#define  MG6_7_16PL    0xFFFF
#endif

#if (G6_8PL >= G6_7PL) || (G6_8PL == 0)
#define  MG6_7_18PL    ~(1 << 7)
#else
#define  MG6_7_18PL    0xFFFF
#endif

#if (G6_9PL >= G6_7PL) || (G6_9PL == 0)
#define  MG6_7_19PL    ~(1 << 8)
#else
#define  MG6_7_19PL    0xFFFF
#endif

#if (G6_10PL >= G6_7PL) || (G6_10PL == 0)
#define  MG6_7_110PL    ~(1 << 9)
#else
#define  MG6_7_110PL    0xFFFF
#endif

#if (G6_11PL >= G6_7PL) || (G6_11PL == 0)
#define  MG6_7_111PL    ~(1 << 10)
#else
#define  MG6_7_111PL    0xFFFF
#endif

#if (G6_12PL >= G6_7PL) || (G6_12PL == 0)
#define  MG6_7_112PL    ~(1 << 11)
#else
#define  MG6_7_112PL    0xFFFF
#endif

#if (G6_13PL >= G6_7PL) || (G6_13PL == 0)
#define  MG6_7_113PL    ~(1 << 12)
#else
#define  MG6_7_113PL    0xFFFF
#endif

#if (G6_14PL >= G6_7PL) || (G6_14PL == 0)
#define  MG6_7_114PL    ~(1 << 13)
#else
#define  MG6_7_114PL    0xFFFF
#endif

#if (G6_15PL >= G6_7PL) || (G6_15PL == 0)
#define  MG6_7_115PL    ~(1 << 14)
#else
#define  MG6_7_115PL    0xFFFF
#endif

#if (G6_16PL >= G6_7PL) || (G6_16PL == 0)
#define  MG6_7_116PL    ~(1 << 15)
#else
#define  MG6_7_116PL    0xFFFF
#endif

#define  MG6_7_17PL	0xFFBF
#define  MG6_7    (MG6_7_11PL & MG6_7_12PL & MG6_7_13PL & MG6_7_14PL & \
                    MG6_7_15PL & MG6_7_16PL & MG6_7_17PL & MG6_7_18PL & \
                    MG6_7_19PL & MG6_7_110PL & MG6_7_111PL & MG6_7_112PL & \
                    MG6_7_113PL & MG6_7_114PL & MG6_7_115PL & MG6_7_116PL)
// End of MG6_7:
// Beginning of MG68:
#if (G6_1PL >= G6_8PL) || (G6_1PL == 0)
#define  MG6_8_11PL    ~(1 << 0)
#else
#define  MG6_8_11PL    0xFFFF
#endif

#if (G6_2PL >= G6_8PL) || (G6_2PL == 0)
#define  MG6_8_12PL    ~(1 << 1)
#else
#define  MG6_8_12PL    0xFFFF
#endif

#if (G6_3PL >= G6_8PL) || (G6_3PL == 0)
#define  MG6_8_13PL    ~(1 << 2)
#else
#define  MG6_8_13PL    0xFFFF
#endif

#if (G6_4PL >= G6_8PL) || (G6_4PL == 0)
#define  MG6_8_14PL    ~(1 << 3)
#else
#define  MG6_8_14PL    0xFFFF
#endif

#if (G6_5PL >= G6_8PL) || (G6_5PL == 0)
#define  MG6_8_15PL    ~(1 << 4)
#else
#define  MG6_8_15PL    0xFFFF
#endif

#if (G6_6PL >= G6_8PL) || (G6_6PL == 0)
#define  MG6_8_16PL    ~(1 << 5)
#else
#define  MG6_8_16PL    0xFFFF
#endif

#if (G6_7PL >= G6_8PL) || (G6_7PL == 0)
#define  MG6_8_17PL    ~(1 << 6)
#else
#define  MG6_8_17PL    0xFFFF
#endif

#if (G6_9PL >= G6_8PL) || (G6_9PL == 0)
#define  MG6_8_19PL    ~(1 << 8)
#else
#define  MG6_8_19PL    0xFFFF
#endif

#if (G6_10PL >= G6_8PL) || (G6_10PL == 0)
#define  MG6_8_110PL    ~(1 << 9)
#else
#define  MG6_8_110PL    0xFFFF
#endif

#if (G6_11PL >= G6_8PL) || (G6_11PL == 0)
#define  MG6_8_111PL    ~(1 << 10)
#else
#define  MG6_8_111PL    0xFFFF
#endif

#if (G6_12PL >= G6_8PL) || (G6_12PL == 0)
#define  MG6_8_112PL    ~(1 << 11)
#else
#define  MG6_8_112PL    0xFFFF
#endif

#if (G6_13PL >= G6_8PL) || (G6_13PL == 0)
#define  MG6_8_113PL    ~(1 << 12)
#else
#define  MG6_8_113PL    0xFFFF
#endif

#if (G6_14PL >= G6_8PL) || (G6_14PL == 0)
#define  MG6_8_114PL    ~(1 << 13)
#else
#define  MG6_8_114PL    0xFFFF
#endif

#if (G6_15PL >= G6_8PL) || (G6_15PL == 0)
#define  MG6_8_115PL    ~(1 << 14)
#else
#define  MG6_8_115PL    0xFFFF
#endif

#if (G6_16PL >= G6_8PL) || (G6_16PL == 0)
#define  MG6_8_116PL    ~(1 << 15)
#else
#define  MG6_8_116PL    0xFFFF
#endif

#define  MG6_8_18PL	0xFF7F
#define  MG6_8    (MG6_8_11PL & MG6_8_12PL & MG6_8_13PL & MG6_8_14PL & \
                    MG6_8_15PL & MG6_8_16PL & MG6_8_17PL & MG6_8_18PL & \
                    MG6_8_19PL & MG6_8_110PL & MG6_8_111PL & MG6_8_112PL & \
                    MG6_8_113PL & MG6_8_114PL & MG6_8_115PL & MG6_8_116PL)
// End of MG6_8:
// Beginning of MG69:
#if (G6_1PL >= G6_9PL) || (G6_1PL == 0)
#define  MG6_9_11PL    ~(1 << 0)
#else
#define  MG6_9_11PL    0xFFFF
#endif

#if (G6_2PL >= G6_9PL) || (G6_2PL == 0)
#define  MG6_9_12PL    ~(1 << 1)
#else
#define  MG6_9_12PL    0xFFFF
#endif

#if (G6_3PL >= G6_9PL) || (G6_3PL == 0)
#define  MG6_9_13PL    ~(1 << 2)
#else
#define  MG6_9_13PL    0xFFFF
#endif

#if (G6_4PL >= G6_9PL) || (G6_4PL == 0)
#define  MG6_9_14PL    ~(1 << 3)
#else
#define  MG6_9_14PL    0xFFFF
#endif

#if (G6_5PL >= G6_9PL) || (G6_5PL == 0)
#define  MG6_9_15PL    ~(1 << 4)
#else
#define  MG6_9_15PL    0xFFFF
#endif

#if (G6_6PL >= G6_9PL) || (G6_6PL == 0)
#define  MG6_9_16PL    ~(1 << 5)
#else
#define  MG6_9_16PL    0xFFFF
#endif

#if (G6_7PL >= G6_9PL) || (G6_7PL == 0)
#define  MG6_9_17PL    ~(1 << 6)
#else
#define  MG6_9_17PL    0xFFFF
#endif

#if (G6_8PL >= G6_9PL) || (G6_8PL == 0)
#define  MG6_9_18PL    ~(1 << 7)
#else
#define  MG6_9_18PL    0xFFFF
#endif

#if (G6_10PL >= G6_9PL) || (G6_10PL == 0)
#define  MG6_9_110PL    ~(1 << 9)
#else
#define  MG6_9_110PL    0xFFFF
#endif

#if (G6_11PL >= G6_9PL) || (G6_11PL == 0)
#define  MG6_9_111PL    ~(1 << 10)
#else
#define  MG6_9_111PL    0xFFFF
#endif

#if (G6_12PL >= G6_9PL) || (G6_12PL == 0)
#define  MG6_9_112PL    ~(1 << 11)
#else
#define  MG6_9_112PL    0xFFFF
#endif

#if (G6_13PL >= G6_9PL) || (G6_13PL == 0)
#define  MG6_9_113PL    ~(1 << 12)
#else
#define  MG6_9_113PL    0xFFFF
#endif

#if (G6_14PL >= G6_9PL) || (G6_14PL == 0)
#define  MG6_9_114PL    ~(1 << 13)
#else
#define  MG6_9_114PL    0xFFFF
#endif

#if (G6_15PL >= G6_9PL) || (G6_15PL == 0)
#define  MG6_9_115PL    ~(1 << 14)
#else
#define  MG6_9_115PL    0xFFFF
#endif

#if (G6_16PL >= G6_9PL) || (G6_16PL == 0)
#define  MG6_9_116PL    ~(1 << 15)
#else
#define  MG6_9_116PL    0xFFFF
#endif

#define  MG6_9_19PL	0xFEFF
#define  MG6_9    (MG6_9_11PL & MG6_9_12PL & MG6_9_13PL & MG6_9_14PL & \
                    MG6_9_15PL & MG6_9_16PL & MG6_9_17PL & MG6_9_18PL & \
                    MG6_9_19PL & MG6_9_110PL & MG6_9_111PL & MG6_9_112PL & \
                    MG6_9_113PL & MG6_9_114PL & MG6_9_115PL & MG6_9_116PL)
// End of MG6_9:
// Beginning of MG610:
#if (G6_1PL >= G6_10PL) || (G6_1PL == 0)
#define  MG6_10_11PL    ~(1 << 0)
#else
#define  MG6_10_11PL    0xFFFF
#endif

#if (G6_2PL >= G6_10PL) || (G6_2PL == 0)
#define  MG6_10_12PL    ~(1 << 1)
#else
#define  MG6_10_12PL    0xFFFF
#endif

#if (G6_3PL >= G6_10PL) || (G6_3PL == 0)
#define  MG6_10_13PL    ~(1 << 2)
#else
#define  MG6_10_13PL    0xFFFF
#endif

#if (G6_4PL >= G6_10PL) || (G6_4PL == 0)
#define  MG6_10_14PL    ~(1 << 3)
#else
#define  MG6_10_14PL    0xFFFF
#endif

#if (G6_5PL >= G6_10PL) || (G6_5PL == 0)
#define  MG6_10_15PL    ~(1 << 4)
#else
#define  MG6_10_15PL    0xFFFF
#endif

#if (G6_6PL >= G6_10PL) || (G6_6PL == 0)
#define  MG6_10_16PL    ~(1 << 5)
#else
#define  MG6_10_16PL    0xFFFF
#endif

#if (G6_7PL >= G6_10PL) || (G6_7PL == 0)
#define  MG6_10_17PL    ~(1 << 6)
#else
#define  MG6_10_17PL    0xFFFF
#endif

#if (G6_8PL >= G6_10PL) || (G6_8PL == 0)
#define  MG6_10_18PL    ~(1 << 7)
#else
#define  MG6_10_18PL    0xFFFF
#endif

#if (G6_9PL >= G6_10PL) || (G6_9PL == 0)
#define  MG6_10_19PL    ~(1 << 8)
#else
#define  MG6_10_19PL    0xFFFF
#endif

#if (G6_11PL >= G6_10PL) || (G6_11PL == 0)
#define  MG6_10_111PL    ~(1 << 10)
#else
#define  MG6_10_111PL    0xFFFF
#endif

#if (G6_12PL >= G6_10PL) || (G6_12PL == 0)
#define  MG6_10_112PL    ~(1 << 11)
#else
#define  MG6_10_112PL    0xFFFF
#endif

#if (G6_13PL >= G6_10PL) || (G6_13PL == 0)
#define  MG6_10_113PL    ~(1 << 12)
#else
#define  MG6_10_113PL    0xFFFF
#endif

#if (G6_14PL >= G6_10PL) || (G6_14PL == 0)
#define  MG6_10_114PL    ~(1 << 13)
#else
#define  MG6_10_114PL    0xFFFF
#endif

#if (G6_15PL >= G6_10PL) || (G6_15PL == 0)
#define  MG6_10_115PL    ~(1 << 14)
#else
#define  MG6_10_115PL    0xFFFF
#endif

#if (G6_16PL >= G6_10PL) || (G6_16PL == 0)
#define  MG6_10_116PL    ~(1 << 15)
#else
#define  MG6_10_116PL    0xFFFF
#endif

#define  MG6_10_110PL	0xFDFF
#define  MG6_10    (MG6_10_11PL & MG6_10_12PL & MG6_10_13PL & MG6_10_14PL & \
                    MG6_10_15PL & MG6_10_16PL & MG6_10_17PL & MG6_10_18PL & \
                    MG6_10_19PL & MG6_10_110PL & MG6_10_111PL & MG6_10_112PL & \
                    MG6_10_113PL & MG6_10_114PL & MG6_10_115PL & MG6_10_116PL)
// End of MG6_10:
// Beginning of MG611:
#if (G6_1PL >= G6_11PL) || (G6_1PL == 0)
#define  MG6_11_11PL    ~(1 << 0)
#else
#define  MG6_11_11PL    0xFFFF
#endif

#if (G6_2PL >= G6_11PL) || (G6_2PL == 0)
#define  MG6_11_12PL    ~(1 << 1)
#else
#define  MG6_11_12PL    0xFFFF
#endif

#if (G6_3PL >= G6_11PL) || (G6_3PL == 0)
#define  MG6_11_13PL    ~(1 << 2)
#else
#define  MG6_11_13PL    0xFFFF
#endif

#if (G6_4PL >= G6_11PL) || (G6_4PL == 0)
#define  MG6_11_14PL    ~(1 << 3)
#else
#define  MG6_11_14PL    0xFFFF
#endif

#if (G6_5PL >= G6_11PL) || (G6_5PL == 0)
#define  MG6_11_15PL    ~(1 << 4)
#else
#define  MG6_11_15PL    0xFFFF
#endif

#if (G6_6PL >= G6_11PL) || (G6_6PL == 0)
#define  MG6_11_16PL    ~(1 << 5)
#else
#define  MG6_11_16PL    0xFFFF
#endif

#if (G6_7PL >= G6_11PL) || (G6_7PL == 0)
#define  MG6_11_17PL    ~(1 << 6)
#else
#define  MG6_11_17PL    0xFFFF
#endif

#if (G6_8PL >= G6_11PL) || (G6_8PL == 0)
#define  MG6_11_18PL    ~(1 << 7)
#else
#define  MG6_11_18PL    0xFFFF
#endif

#if (G6_9PL >= G6_11PL) || (G6_9PL == 0)
#define  MG6_11_19PL    ~(1 << 8)
#else
#define  MG6_11_19PL    0xFFFF
#endif

#if (G6_10PL >= G6_11PL) || (G6_10PL == 0)
#define  MG6_11_110PL    ~(1 << 9)
#else
#define  MG6_11_110PL    0xFFFF
#endif

#if (G6_12PL >= G6_11PL) || (G6_12PL == 0)
#define  MG6_11_112PL    ~(1 << 11)
#else
#define  MG6_11_112PL    0xFFFF
#endif

#if (G6_13PL >= G6_11PL) || (G6_13PL == 0)
#define  MG6_11_113PL    ~(1 << 12)
#else
#define  MG6_11_113PL    0xFFFF
#endif

#if (G6_14PL >= G6_11PL) || (G6_14PL == 0)
#define  MG6_11_114PL    ~(1 << 13)
#else
#define  MG6_11_114PL    0xFFFF
#endif

#if (G6_15PL >= G6_11PL) || (G6_15PL == 0)
#define  MG6_11_115PL    ~(1 << 14)
#else
#define  MG6_11_115PL    0xFFFF
#endif

#if (G6_16PL >= G6_11PL) || (G6_16PL == 0)
#define  MG6_11_116PL    ~(1 << 15)
#else
#define  MG6_11_116PL    0xFFFF
#endif

#define  MG6_11_111PL	0xFBFF
#define  MG6_11    (MG6_11_11PL & MG6_11_12PL & MG6_11_13PL & MG6_11_14PL & \
                    MG6_11_15PL & MG6_11_16PL & MG6_11_17PL & MG6_11_18PL & \
                    MG6_11_19PL & MG6_11_110PL & MG6_11_111PL & MG6_11_112PL & \
                    MG6_11_113PL & MG6_11_114PL & MG6_11_115PL & MG6_11_116PL)
// End of MG6_11:
// Beginning of MG612:
#if (G6_1PL >= G6_12PL) || (G6_1PL == 0)
#define  MG6_12_11PL    ~(1 << 0)
#else
#define  MG6_12_11PL    0xFFFF
#endif

#if (G6_2PL >= G6_12PL) || (G6_2PL == 0)
#define  MG6_12_12PL    ~(1 << 1)
#else
#define  MG6_12_12PL    0xFFFF
#endif

#if (G6_3PL >= G6_12PL) || (G6_3PL == 0)
#define  MG6_12_13PL    ~(1 << 2)
#else
#define  MG6_12_13PL    0xFFFF
#endif

#if (G6_4PL >= G6_12PL) || (G6_4PL == 0)
#define  MG6_12_14PL    ~(1 << 3)
#else
#define  MG6_12_14PL    0xFFFF
#endif

#if (G6_5PL >= G6_12PL) || (G6_5PL == 0)
#define  MG6_12_15PL    ~(1 << 4)
#else
#define  MG6_12_15PL    0xFFFF
#endif

#if (G6_6PL >= G6_12PL) || (G6_6PL == 0)
#define  MG6_12_16PL    ~(1 << 5)
#else
#define  MG6_12_16PL    0xFFFF
#endif

#if (G6_7PL >= G6_12PL) || (G6_7PL == 0)
#define  MG6_12_17PL    ~(1 << 6)
#else
#define  MG6_12_17PL    0xFFFF
#endif

#if (G6_8PL >= G6_12PL) || (G6_8PL == 0)
#define  MG6_12_18PL    ~(1 << 7)
#else
#define  MG6_12_18PL    0xFFFF
#endif

#if (G6_9PL >= G6_12PL) || (G6_9PL == 0)
#define  MG6_12_19PL    ~(1 << 8)
#else
#define  MG6_12_19PL    0xFFFF
#endif

#if (G6_10PL >= G6_12PL) || (G6_10PL == 0)
#define  MG6_12_110PL    ~(1 << 9)
#else
#define  MG6_12_110PL    0xFFFF
#endif

#if (G6_11PL >= G6_12PL) || (G6_11PL == 0)
#define  MG6_12_111PL    ~(1 << 10)
#else
#define  MG6_12_111PL    0xFFFF
#endif

#if (G6_13PL >= G6_12PL) || (G6_13PL == 0)
#define  MG6_12_113PL    ~(1 << 12)
#else
#define  MG6_12_113PL    0xFFFF
#endif

#if (G6_14PL >= G6_12PL) || (G6_14PL == 0)
#define  MG6_12_114PL    ~(1 << 13)
#else
#define  MG6_12_114PL    0xFFFF
#endif

#if (G6_15PL >= G6_12PL) || (G6_15PL == 0)
#define  MG6_12_115PL    ~(1 << 14)
#else
#define  MG6_12_115PL    0xFFFF
#endif

#if (G6_16PL >= G6_12PL) || (G6_16PL == 0)
#define  MG6_12_116PL    ~(1 << 15)
#else
#define  MG6_12_116PL    0xFFFF
#endif

#define  MG6_12_112PL	0xF7FF
#define  MG6_12    (MG6_12_11PL & MG6_12_12PL & MG6_12_13PL & MG6_12_14PL & \
                    MG6_12_15PL & MG6_12_16PL & MG6_12_17PL & MG6_12_18PL & \
                    MG6_12_19PL & MG6_12_110PL & MG6_12_111PL & MG6_12_112PL & \
                    MG6_12_113PL & MG6_12_114PL & MG6_12_115PL & MG6_12_116PL)
// End of MG6_12:
// Beginning of MG613:
#if (G6_1PL >= G6_13PL) || (G6_1PL == 0)
#define  MG6_13_11PL    ~(1 << 0)
#else
#define  MG6_13_11PL    0xFFFF
#endif

#if (G6_2PL >= G6_13PL) || (G6_2PL == 0)
#define  MG6_13_12PL    ~(1 << 1)
#else
#define  MG6_13_12PL    0xFFFF
#endif

#if (G6_3PL >= G6_13PL) || (G6_3PL == 0)
#define  MG6_13_13PL    ~(1 << 2)
#else
#define  MG6_13_13PL    0xFFFF
#endif

#if (G6_4PL >= G6_13PL) || (G6_4PL == 0)
#define  MG6_13_14PL    ~(1 << 3)
#else
#define  MG6_13_14PL    0xFFFF
#endif

#if (G6_5PL >= G6_13PL) || (G6_5PL == 0)
#define  MG6_13_15PL    ~(1 << 4)
#else
#define  MG6_13_15PL    0xFFFF
#endif

#if (G6_6PL >= G6_13PL) || (G6_6PL == 0)
#define  MG6_13_16PL    ~(1 << 5)
#else
#define  MG6_13_16PL    0xFFFF
#endif

#if (G6_7PL >= G6_13PL) || (G6_7PL == 0)
#define  MG6_13_17PL    ~(1 << 6)
#else
#define  MG6_13_17PL    0xFFFF
#endif

#if (G6_8PL >= G6_13PL) || (G6_8PL == 0)
#define  MG6_13_18PL    ~(1 << 7)
#else
#define  MG6_13_18PL    0xFFFF
#endif

#if (G6_9PL >= G6_13PL) || (G6_9PL == 0)
#define  MG6_13_19PL    ~(1 << 8)
#else
#define  MG6_13_19PL    0xFFFF
#endif

#if (G6_10PL >= G6_13PL) || (G6_10PL == 0)
#define  MG6_13_110PL    ~(1 << 9)
#else
#define  MG6_13_110PL    0xFFFF
#endif

#if (G6_11PL >= G6_13PL) || (G6_11PL == 0)
#define  MG6_13_111PL    ~(1 << 10)
#else
#define  MG6_13_111PL    0xFFFF
#endif

#if (G6_12PL >= G6_13PL) || (G6_12PL == 0)
#define  MG6_13_112PL    ~(1 << 11)
#else
#define  MG6_13_112PL    0xFFFF
#endif

#if (G6_14PL >= G6_13PL) || (G6_14PL == 0)
#define  MG6_13_114PL    ~(1 << 13)
#else
#define  MG6_13_114PL    0xFFFF
#endif

#if (G6_15PL >= G6_13PL) || (G6_15PL == 0)
#define  MG6_13_115PL    ~(1 << 14)
#else
#define  MG6_13_115PL    0xFFFF
#endif

#if (G6_16PL >= G6_13PL) || (G6_16PL == 0)
#define  MG6_13_116PL    ~(1 << 15)
#else
#define  MG6_13_116PL    0xFFFF
#endif

#define  MG6_13_113PL	0xEFFF
#define  MG6_13    (MG6_13_11PL & MG6_13_12PL & MG6_13_13PL & MG6_13_14PL & \
                    MG6_13_15PL & MG6_13_16PL & MG6_13_17PL & MG6_13_18PL & \
                    MG6_13_19PL & MG6_13_110PL & MG6_13_111PL & MG6_13_112PL & \
                    MG6_13_113PL & MG6_13_114PL & MG6_13_115PL & MG6_13_116PL)
// End of MG6_13:
// Beginning of MG614:
#if (G6_1PL >= G6_14PL) || (G6_1PL == 0)
#define  MG6_14_11PL    ~(1 << 0)
#else
#define  MG6_14_11PL    0xFFFF
#endif

#if (G6_2PL >= G6_14PL) || (G6_2PL == 0)
#define  MG6_14_12PL    ~(1 << 1)
#else
#define  MG6_14_12PL    0xFFFF
#endif

#if (G6_3PL >= G6_14PL) || (G6_3PL == 0)
#define  MG6_14_13PL    ~(1 << 2)
#else
#define  MG6_14_13PL    0xFFFF
#endif

#if (G6_4PL >= G6_14PL) || (G6_4PL == 0)
#define  MG6_14_14PL    ~(1 << 3)
#else
#define  MG6_14_14PL    0xFFFF
#endif

#if (G6_5PL >= G6_14PL) || (G6_5PL == 0)
#define  MG6_14_15PL    ~(1 << 4)
#else
#define  MG6_14_15PL    0xFFFF
#endif

#if (G6_6PL >= G6_14PL) || (G6_6PL == 0)
#define  MG6_14_16PL    ~(1 << 5)
#else
#define  MG6_14_16PL    0xFFFF
#endif

#if (G6_7PL >= G6_14PL) || (G6_7PL == 0)
#define  MG6_14_17PL    ~(1 << 6)
#else
#define  MG6_14_17PL    0xFFFF
#endif

#if (G6_8PL >= G6_14PL) || (G6_8PL == 0)
#define  MG6_14_18PL    ~(1 << 7)
#else
#define  MG6_14_18PL    0xFFFF
#endif

#if (G6_9PL >= G6_14PL) || (G6_9PL == 0)
#define  MG6_14_19PL    ~(1 << 8)
#else
#define  MG6_14_19PL    0xFFFF
#endif

#if (G6_10PL >= G6_14PL) || (G6_10PL == 0)
#define  MG6_14_110PL    ~(1 << 9)
#else
#define  MG6_14_110PL    0xFFFF
#endif

#if (G6_11PL >= G6_14PL) || (G6_11PL == 0)
#define  MG6_14_111PL    ~(1 << 10)
#else
#define  MG6_14_111PL    0xFFFF
#endif

#if (G6_12PL >= G6_14PL) || (G6_12PL == 0)
#define  MG6_14_112PL    ~(1 << 11)
#else
#define  MG6_14_112PL    0xFFFF
#endif

#if (G6_13PL >= G6_14PL) || (G6_13PL == 0)
#define  MG6_14_113PL    ~(1 << 12)
#else
#define  MG6_14_113PL    0xFFFF
#endif

#if (G6_15PL >= G6_14PL) || (G6_15PL == 0)
#define  MG6_14_115PL    ~(1 << 14)
#else
#define  MG6_14_115PL    0xFFFF
#endif

#if (G6_16PL >= G6_14PL) || (G6_16PL == 0)
#define  MG6_14_116PL    ~(1 << 15)
#else
#define  MG6_14_116PL    0xFFFF
#endif

#define  MG6_14_114PL	0xDFFF
#define  MG6_14    (MG6_14_11PL & MG6_14_12PL & MG6_14_13PL & MG6_14_14PL & \
                    MG6_14_15PL & MG6_14_16PL & MG6_14_17PL & MG6_14_18PL & \
                    MG6_14_19PL & MG6_14_110PL & MG6_14_111PL & MG6_14_112PL & \
                    MG6_14_113PL & MG6_14_114PL & MG6_14_115PL & MG6_14_116PL)
// End of MG6_14:
// Beginning of MG615:
#if (G6_1PL >= G6_15PL) || (G6_1PL == 0)
#define  MG6_15_11PL    ~(1 << 0)
#else
#define  MG6_15_11PL    0xFFFF
#endif

#if (G6_2PL >= G6_15PL) || (G6_2PL == 0)
#define  MG6_15_12PL    ~(1 << 1)
#else
#define  MG6_15_12PL    0xFFFF
#endif

#if (G6_3PL >= G6_15PL) || (G6_3PL == 0)
#define  MG6_15_13PL    ~(1 << 2)
#else
#define  MG6_15_13PL    0xFFFF
#endif

#if (G6_4PL >= G6_15PL) || (G6_4PL == 0)
#define  MG6_15_14PL    ~(1 << 3)
#else
#define  MG6_15_14PL    0xFFFF
#endif

#if (G6_5PL >= G6_15PL) || (G6_5PL == 0)
#define  MG6_15_15PL    ~(1 << 4)
#else
#define  MG6_15_15PL    0xFFFF
#endif

#if (G6_6PL >= G6_15PL) || (G6_6PL == 0)
#define  MG6_15_16PL    ~(1 << 5)
#else
#define  MG6_15_16PL    0xFFFF
#endif

#if (G6_7PL >= G6_15PL) || (G6_7PL == 0)
#define  MG6_15_17PL    ~(1 << 6)
#else
#define  MG6_15_17PL    0xFFFF
#endif

#if (G6_8PL >= G6_15PL) || (G6_8PL == 0)
#define  MG6_15_18PL    ~(1 << 7)
#else
#define  MG6_15_18PL    0xFFFF
#endif

#if (G6_9PL >= G6_15PL) || (G6_9PL == 0)
#define  MG6_15_19PL    ~(1 << 8)
#else
#define  MG6_15_19PL    0xFFFF
#endif

#if (G6_10PL >= G6_15PL) || (G6_10PL == 0)
#define  MG6_15_110PL    ~(1 << 9)
#else
#define  MG6_15_110PL    0xFFFF
#endif

#if (G6_11PL >= G6_15PL) || (G6_11PL == 0)
#define  MG6_15_111PL    ~(1 << 10)
#else
#define  MG6_15_111PL    0xFFFF
#endif

#if (G6_12PL >= G6_15PL) || (G6_12PL == 0)
#define  MG6_15_112PL    ~(1 << 11)
#else
#define  MG6_15_112PL    0xFFFF
#endif

#if (G6_13PL >= G6_15PL) || (G6_13PL == 0)
#define  MG6_15_113PL    ~(1 << 12)
#else
#define  MG6_15_113PL    0xFFFF
#endif

#if (G6_14PL >= G6_15PL) || (G6_14PL == 0)
#define  MG6_15_114PL    ~(1 << 13)
#else
#define  MG6_15_114PL    0xFFFF
#endif

#if (G6_16PL >= G6_15PL) || (G6_16PL == 0)
#define  MG6_15_116PL    ~(1 << 15)
#else
#define  MG6_15_116PL    0xFFFF
#endif

#define  MG6_15_115PL	0xBFFF
#define  MG6_15    (MG6_15_11PL & MG6_15_12PL & MG6_15_13PL & MG6_15_14PL & \
                    MG6_15_15PL & MG6_15_16PL & MG6_15_17PL & MG6_15_18PL & \
                    MG6_15_19PL & MG6_15_110PL & MG6_15_111PL & MG6_15_112PL & \
                    MG6_15_113PL & MG6_15_114PL & MG6_15_115PL & MG6_15_116PL)
// End of MG6_15:
// Beginning of MG616:
#if (G6_1PL >= G6_16PL) || (G6_1PL == 0)
#define  MG6_16_11PL    ~(1 << 0)
#else
#define  MG6_16_11PL    0xFFFF
#endif

#if (G6_2PL >= G6_16PL) || (G6_2PL == 0)
#define  MG6_16_12PL    ~(1 << 1)
#else
#define  MG6_16_12PL    0xFFFF
#endif

#if (G6_3PL >= G6_16PL) || (G6_3PL == 0)
#define  MG6_16_13PL    ~(1 << 2)
#else
#define  MG6_16_13PL    0xFFFF
#endif

#if (G6_4PL >= G6_16PL) || (G6_4PL == 0)
#define  MG6_16_14PL    ~(1 << 3)
#else
#define  MG6_16_14PL    0xFFFF
#endif

#if (G6_5PL >= G6_16PL) || (G6_5PL == 0)
#define  MG6_16_15PL    ~(1 << 4)
#else
#define  MG6_16_15PL    0xFFFF
#endif

#if (G6_6PL >= G6_16PL) || (G6_6PL == 0)
#define  MG6_16_16PL    ~(1 << 5)
#else
#define  MG6_16_16PL    0xFFFF
#endif

#if (G6_7PL >= G6_16PL) || (G6_7PL == 0)
#define  MG6_16_17PL    ~(1 << 6)
#else
#define  MG6_16_17PL    0xFFFF
#endif

#if (G6_8PL >= G6_16PL) || (G6_8PL == 0)
#define  MG6_16_18PL    ~(1 << 7)
#else
#define  MG6_16_18PL    0xFFFF
#endif

#if (G6_9PL >= G6_16PL) || (G6_9PL == 0)
#define  MG6_16_19PL    ~(1 << 8)
#else
#define  MG6_16_19PL    0xFFFF
#endif

#if (G6_10PL >= G6_16PL) || (G6_10PL == 0)
#define  MG6_16_110PL    ~(1 << 9)
#else
#define  MG6_16_110PL    0xFFFF
#endif

#if (G6_11PL >= G6_16PL) || (G6_11PL == 0)
#define  MG6_16_111PL    ~(1 << 10)
#else
#define  MG6_16_111PL    0xFFFF
#endif

#if (G6_12PL >= G6_16PL) || (G6_12PL == 0)
#define  MG6_16_112PL    ~(1 << 11)
#else
#define  MG6_16_112PL    0xFFFF
#endif

#if (G6_13PL >= G6_16PL) || (G6_13PL == 0)
#define  MG6_16_113PL    ~(1 << 12)
#else
#define  MG6_16_113PL    0xFFFF
#endif

#if (G6_14PL >= G6_16PL) || (G6_14PL == 0)
#define  MG6_16_114PL    ~(1 << 13)
#else
#define  MG6_16_114PL    0xFFFF
#endif

#if (G6_15PL >= G6_16PL) || (G6_15PL == 0)
#define  MG6_16_115PL    ~(1 << 14)
#else
#define  MG6_16_115PL    0xFFFF
#endif

#define  MG6_16_116PL	0x7FFF
#define  MG6_16    (MG6_16_11PL & MG6_16_12PL & MG6_16_13PL & MG6_16_14PL & \
                    MG6_16_15PL & MG6_16_16PL & MG6_16_17PL & MG6_16_18PL & \
                    MG6_16_19PL & MG6_16_110PL & MG6_16_111PL & MG6_16_112PL & \
                    MG6_16_113PL & MG6_16_114PL & MG6_16_115PL & MG6_16_116PL)
// End of MG6_16:


//-------------------------------------------------------------------------------
// Automatically generate PIEIER7 interrupt masks MG71 to MG716:

// Beginning of MG71:
#if (G7_2PL >= G7_1PL) || (G7_2PL == 0)
#define  MG7_1_12PL    ~(1 << 1)
#else
#define  MG7_1_12PL    0xFFFF
#endif

#if (G7_3PL >= G7_1PL) || (G7_3PL == 0)
#define  MG7_1_13PL    ~(1 << 2)
#else
#define  MG7_1_13PL    0xFFFF
#endif

#if (G7_4PL >= G7_1PL) || (G7_4PL == 0)
#define  MG7_1_14PL    ~(1 << 3)
#else
#define  MG7_1_14PL    0xFFFF
#endif

#if (G7_5PL >= G7_1PL) || (G7_5PL == 0)
#define  MG7_1_15PL    ~(1 << 4)
#else
#define  MG7_1_15PL    0xFFFF
#endif

#if (G7_6PL >= G7_1PL) || (G7_6PL == 0)
#define  MG7_1_16PL    ~(1 << 5)
#else
#define  MG7_1_16PL    0xFFFF
#endif

#if (G7_7PL >= G7_1PL) || (G7_7PL == 0)
#define  MG7_1_17PL    ~(1 << 6)
#else
#define  MG7_1_17PL    0xFFFF
#endif

#if (G7_8PL >= G7_1PL) || (G7_8PL == 0)
#define  MG7_1_18PL    ~(1 << 7)
#else
#define  MG7_1_18PL    0xFFFF
#endif

#if (G7_9PL >= G7_1PL) || (G7_9PL == 0)
#define  MG7_1_19PL    ~(1 << 8)
#else
#define  MG7_1_19PL    0xFFFF
#endif

#if (G7_10PL >= G7_1PL) || (G7_10PL == 0)
#define  MG7_1_110PL    ~(1 << 9)
#else
#define  MG7_1_110PL    0xFFFF
#endif

#if (G7_11PL >= G7_1PL) || (G7_11PL == 0)
#define  MG7_1_111PL    ~(1 << 10)
#else
#define  MG7_1_111PL    0xFFFF
#endif

#if (G7_12PL >= G7_1PL) || (G7_12PL == 0)
#define  MG7_1_112PL    ~(1 << 11)
#else
#define  MG7_1_112PL    0xFFFF
#endif

#if (G7_13PL >= G7_1PL) || (G7_13PL == 0)
#define  MG7_1_113PL    ~(1 << 12)
#else
#define  MG7_1_113PL    0xFFFF
#endif

#if (G7_14PL >= G7_1PL) || (G7_14PL == 0)
#define  MG7_1_114PL    ~(1 << 13)
#else
#define  MG7_1_114PL    0xFFFF
#endif

#if (G7_15PL >= G7_1PL) || (G7_15PL == 0)
#define  MG7_1_115PL    ~(1 << 14)
#else
#define  MG7_1_115PL    0xFFFF
#endif

#if (G7_16PL >= G7_1PL) || (G7_16PL == 0)
#define  MG7_1_116PL    ~(1 << 15)
#else
#define  MG7_1_116PL    0xFFFF
#endif

#define  MG7_1_11PL	0xFFFE
#define  MG7_1    (MG7_1_11PL & MG7_1_12PL & MG7_1_13PL & MG7_1_14PL & \
                    MG7_1_15PL & MG7_1_16PL & MG7_1_17PL & MG7_1_18PL & \
                    MG7_1_19PL & MG7_1_110PL & MG7_1_111PL & MG7_1_112PL & \
                    MG7_1_113PL & MG7_1_114PL & MG7_1_115PL & MG7_1_116PL)
// End of MG7_1:
// Beginning of MG72:
#if (G7_1PL >= G7_2PL) || (G7_1PL == 0)
#define  MG7_2_11PL    ~(1 << 0)
#else
#define  MG7_2_11PL    0xFFFF
#endif

#if (G7_3PL >= G7_2PL) || (G7_3PL == 0)
#define  MG7_2_13PL    ~(1 << 2)
#else
#define  MG7_2_13PL    0xFFFF
#endif

#if (G7_4PL >= G7_2PL) || (G7_4PL == 0)
#define  MG7_2_14PL    ~(1 << 3)
#else
#define  MG7_2_14PL    0xFFFF
#endif

#if (G7_5PL >= G7_2PL) || (G7_5PL == 0)
#define  MG7_2_15PL    ~(1 << 4)
#else
#define  MG7_2_15PL    0xFFFF
#endif

#if (G7_6PL >= G7_2PL) || (G7_6PL == 0)
#define  MG7_2_16PL    ~(1 << 5)
#else
#define  MG7_2_16PL    0xFFFF
#endif

#if (G7_7PL >= G7_2PL) || (G7_7PL == 0)
#define  MG7_2_17PL    ~(1 << 6)
#else
#define  MG7_2_17PL    0xFFFF
#endif

#if (G7_8PL >= G7_2PL) || (G7_8PL == 0)
#define  MG7_2_18PL    ~(1 << 7)
#else
#define  MG7_2_18PL    0xFFFF
#endif

#if (G7_9PL >= G7_2PL) || (G7_9PL == 0)
#define  MG7_2_19PL    ~(1 << 8)
#else
#define  MG7_2_19PL    0xFFFF
#endif

#if (G7_10PL >= G7_2PL) || (G7_10PL == 0)
#define  MG7_2_110PL    ~(1 << 9)
#else
#define  MG7_2_110PL    0xFFFF
#endif

#if (G7_11PL >= G7_2PL) || (G7_11PL == 0)
#define  MG7_2_111PL    ~(1 << 10)
#else
#define  MG7_2_111PL    0xFFFF
#endif

#if (G7_12PL >= G7_2PL) || (G7_12PL == 0)
#define  MG7_2_112PL    ~(1 << 11)
#else
#define  MG7_2_112PL    0xFFFF
#endif

#if (G7_13PL >= G7_2PL) || (G7_13PL == 0)
#define  MG7_2_113PL    ~(1 << 12)
#else
#define  MG7_2_113PL    0xFFFF
#endif

#if (G7_14PL >= G7_2PL) || (G7_14PL == 0)
#define  MG7_2_114PL    ~(1 << 13)
#else
#define  MG7_2_114PL    0xFFFF
#endif

#if (G7_15PL >= G7_2PL) || (G7_15PL == 0)
#define  MG7_2_115PL    ~(1 << 14)
#else
#define  MG7_2_115PL    0xFFFF
#endif

#if (G7_16PL >= G7_2PL) || (G7_16PL == 0)
#define  MG7_2_116PL    ~(1 << 15)
#else
#define  MG7_2_116PL    0xFFFF
#endif

#define  MG7_2_12PL	0xFFFD
#define  MG7_2    (MG7_2_11PL & MG7_2_12PL & MG7_2_13PL & MG7_2_14PL & \
                    MG7_2_15PL & MG7_2_16PL & MG7_2_17PL & MG7_2_18PL & \
                    MG7_2_19PL & MG7_2_110PL & MG7_2_111PL & MG7_2_112PL & \
                    MG7_2_113PL & MG7_2_114PL & MG7_2_115PL & MG7_2_116PL)
// End of MG7_2:
// Beginning of MG73:
#if (G7_1PL >= G7_3PL) || (G7_1PL == 0)
#define  MG7_3_11PL    ~(1 << 0)
#else
#define  MG7_3_11PL    0xFFFF
#endif

#if (G7_2PL >= G7_3PL) || (G7_2PL == 0)
#define  MG7_3_12PL    ~(1 << 1)
#else
#define  MG7_3_12PL    0xFFFF
#endif

#if (G7_4PL >= G7_3PL) || (G7_4PL == 0)
#define  MG7_3_14PL    ~(1 << 3)
#else
#define  MG7_3_14PL    0xFFFF
#endif

#if (G7_5PL >= G7_3PL) || (G7_5PL == 0)
#define  MG7_3_15PL    ~(1 << 4)
#else
#define  MG7_3_15PL    0xFFFF
#endif

#if (G7_6PL >= G7_3PL) || (G7_6PL == 0)
#define  MG7_3_16PL    ~(1 << 5)
#else
#define  MG7_3_16PL    0xFFFF
#endif

#if (G7_7PL >= G7_3PL) || (G7_7PL == 0)
#define  MG7_3_17PL    ~(1 << 6)
#else
#define  MG7_3_17PL    0xFFFF
#endif

#if (G7_8PL >= G7_3PL) || (G7_8PL == 0)
#define  MG7_3_18PL    ~(1 << 7)
#else
#define  MG7_3_18PL    0xFFFF
#endif

#if (G7_9PL >= G7_3PL) || (G7_9PL == 0)
#define  MG7_3_19PL    ~(1 << 8)
#else
#define  MG7_3_19PL    0xFFFF
#endif

#if (G7_10PL >= G7_3PL) || (G7_10PL == 0)
#define  MG7_3_110PL    ~(1 << 9)
#else
#define  MG7_3_110PL    0xFFFF
#endif

#if (G7_11PL >= G7_3PL) || (G7_11PL == 0)
#define  MG7_3_111PL    ~(1 << 10)
#else
#define  MG7_3_111PL    0xFFFF
#endif

#if (G7_12PL >= G7_3PL) || (G7_12PL == 0)
#define  MG7_3_112PL    ~(1 << 11)
#else
#define  MG7_3_112PL    0xFFFF
#endif

#if (G7_13PL >= G7_3PL) || (G7_13PL == 0)
#define  MG7_3_113PL    ~(1 << 12)
#else
#define  MG7_3_113PL    0xFFFF
#endif

#if (G7_14PL >= G7_3PL) || (G7_14PL == 0)
#define  MG7_3_114PL    ~(1 << 13)
#else
#define  MG7_3_114PL    0xFFFF
#endif

#if (G7_15PL >= G7_3PL) || (G7_15PL == 0)
#define  MG7_3_115PL    ~(1 << 14)
#else
#define  MG7_3_115PL    0xFFFF
#endif

#if (G7_16PL >= G7_3PL) || (G7_16PL == 0)
#define  MG7_3_116PL    ~(1 << 15)
#else
#define  MG7_3_116PL    0xFFFF
#endif

#define  MG7_3_13PL	0xFFFB
#define  MG7_3    (MG7_3_11PL & MG7_3_12PL & MG7_3_13PL & MG7_3_14PL & \
                    MG7_3_15PL & MG7_3_16PL & MG7_3_17PL & MG7_3_18PL & \
                    MG7_3_19PL & MG7_3_110PL & MG7_3_111PL & MG7_3_112PL & \
                    MG7_3_113PL & MG7_3_114PL & MG7_3_115PL & MG7_3_116PL)
// End of MG7_3:
// Beginning of MG74:
#if (G7_1PL >= G7_4PL) || (G7_1PL == 0)
#define  MG7_4_11PL    ~(1 << 0)
#else
#define  MG7_4_11PL    0xFFFF
#endif

#if (G7_2PL >= G7_4PL) || (G7_2PL == 0)
#define  MG7_4_12PL    ~(1 << 1)
#else
#define  MG7_4_12PL    0xFFFF
#endif

#if (G7_3PL >= G7_4PL) || (G7_3PL == 0)
#define  MG7_4_13PL    ~(1 << 2)
#else
#define  MG7_4_13PL    0xFFFF
#endif

#if (G7_5PL >= G7_4PL) || (G7_5PL == 0)
#define  MG7_4_15PL    ~(1 << 4)
#else
#define  MG7_4_15PL    0xFFFF
#endif

#if (G7_6PL >= G7_4PL) || (G7_6PL == 0)
#define  MG7_4_16PL    ~(1 << 5)
#else
#define  MG7_4_16PL    0xFFFF
#endif

#if (G7_7PL >= G7_4PL) || (G7_7PL == 0)
#define  MG7_4_17PL    ~(1 << 6)
#else
#define  MG7_4_17PL    0xFFFF
#endif

#if (G7_8PL >= G7_4PL) || (G7_8PL == 0)
#define  MG7_4_18PL    ~(1 << 7)
#else
#define  MG7_4_18PL    0xFFFF
#endif

#if (G7_9PL >= G7_4PL) || (G7_9PL == 0)
#define  MG7_4_19PL    ~(1 << 8)
#else
#define  MG7_4_19PL    0xFFFF
#endif

#if (G7_10PL >= G7_4PL) || (G7_10PL == 0)
#define  MG7_4_110PL    ~(1 << 9)
#else
#define  MG7_4_110PL    0xFFFF
#endif

#if (G7_11PL >= G7_4PL) || (G7_11PL == 0)
#define  MG7_4_111PL    ~(1 << 10)
#else
#define  MG7_4_111PL    0xFFFF
#endif

#if (G7_12PL >= G7_4PL) || (G7_12PL == 0)
#define  MG7_4_112PL    ~(1 << 11)
#else
#define  MG7_4_112PL    0xFFFF
#endif

#if (G7_13PL >= G7_4PL) || (G7_13PL == 0)
#define  MG7_4_113PL    ~(1 << 12)
#else
#define  MG7_4_113PL    0xFFFF
#endif

#if (G7_14PL >= G7_4PL) || (G7_14PL == 0)
#define  MG7_4_114PL    ~(1 << 13)
#else
#define  MG7_4_114PL    0xFFFF
#endif

#if (G7_15PL >= G7_4PL) || (G7_15PL == 0)
#define  MG7_4_115PL    ~(1 << 14)
#else
#define  MG7_4_115PL    0xFFFF
#endif

#if (G7_16PL >= G7_4PL) || (G7_16PL == 0)
#define  MG7_4_116PL    ~(1 << 15)
#else
#define  MG7_4_116PL    0xFFFF
#endif

#define  MG7_4_14PL	0xFFF7
#define  MG7_4    (MG7_4_11PL & MG7_4_12PL & MG7_4_13PL & MG7_4_14PL & \
                    MG7_4_15PL & MG7_4_16PL & MG7_4_17PL & MG7_4_18PL & \
                    MG7_4_19PL & MG7_4_110PL & MG7_4_111PL & MG7_4_112PL & \
                    MG7_4_113PL & MG7_4_114PL & MG7_4_115PL & MG7_4_116PL)
// End of MG7_4:
// Beginning of MG75:
#if (G7_1PL >= G7_5PL) || (G7_1PL == 0)
#define  MG7_5_11PL    ~(1 << 0)
#else
#define  MG7_5_11PL    0xFFFF
#endif

#if (G7_2PL >= G7_5PL) || (G7_2PL == 0)
#define  MG7_5_12PL    ~(1 << 1)
#else
#define  MG7_5_12PL    0xFFFF
#endif

#if (G7_3PL >= G7_5PL) || (G7_3PL == 0)
#define  MG7_5_13PL    ~(1 << 2)
#else
#define  MG7_5_13PL    0xFFFF
#endif

#if (G7_4PL >= G7_5PL) || (G7_4PL == 0)
#define  MG7_5_14PL    ~(1 << 3)
#else
#define  MG7_5_14PL    0xFFFF
#endif

#if (G7_6PL >= G7_5PL) || (G7_6PL == 0)
#define  MG7_5_16PL    ~(1 << 5)
#else
#define  MG7_5_16PL    0xFFFF
#endif

#if (G7_7PL >= G7_5PL) || (G7_7PL == 0)
#define  MG7_5_17PL    ~(1 << 6)
#else
#define  MG7_5_17PL    0xFFFF
#endif

#if (G7_8PL >= G7_5PL) || (G7_8PL == 0)
#define  MG7_5_18PL    ~(1 << 7)
#else
#define  MG7_5_18PL    0xFFFF
#endif

#if (G7_9PL >= G7_5PL) || (G7_9PL == 0)
#define  MG7_5_19PL    ~(1 << 8)
#else
#define  MG7_5_19PL    0xFFFF
#endif

#if (G7_10PL >= G7_5PL) || (G7_10PL == 0)
#define  MG7_5_110PL    ~(1 << 9)
#else
#define  MG7_5_110PL    0xFFFF
#endif

#if (G7_11PL >= G7_5PL) || (G7_11PL == 0)
#define  MG7_5_111PL    ~(1 << 10)
#else
#define  MG7_5_111PL    0xFFFF
#endif

#if (G7_12PL >= G7_5PL) || (G7_12PL == 0)
#define  MG7_5_112PL    ~(1 << 11)
#else
#define  MG7_5_112PL    0xFFFF
#endif

#if (G7_13PL >= G7_5PL) || (G7_13PL == 0)
#define  MG7_5_113PL    ~(1 << 12)
#else
#define  MG7_5_113PL    0xFFFF
#endif

#if (G7_14PL >= G7_5PL) || (G7_14PL == 0)
#define  MG7_5_114PL    ~(1 << 13)
#else
#define  MG7_5_114PL    0xFFFF
#endif

#if (G7_15PL >= G7_5PL) || (G7_15PL == 0)
#define  MG7_5_115PL    ~(1 << 14)
#else
#define  MG7_5_115PL    0xFFFF
#endif

#if (G7_16PL >= G7_5PL) || (G7_16PL == 0)
#define  MG7_5_116PL    ~(1 << 15)
#else
#define  MG7_5_116PL    0xFFFF
#endif

#define  MG7_5_15PL	0xFFEF
#define  MG7_5    (MG7_5_11PL & MG7_5_12PL & MG7_5_13PL & MG7_5_14PL & \
                    MG7_5_15PL & MG7_5_16PL & MG7_5_17PL & MG7_5_18PL & \
                    MG7_5_19PL & MG7_5_110PL & MG7_5_111PL & MG7_5_112PL & \
                    MG7_5_113PL & MG7_5_114PL & MG7_5_115PL & MG7_5_116PL)
// End of MG7_5:
// Beginning of MG76:
#if (G7_1PL >= G7_6PL) || (G7_1PL == 0)
#define  MG7_6_11PL    ~(1 << 0)
#else
#define  MG7_6_11PL    0xFFFF
#endif

#if (G7_2PL >= G7_6PL) || (G7_2PL == 0)
#define  MG7_6_12PL    ~(1 << 1)
#else
#define  MG7_6_12PL    0xFFFF
#endif

#if (G7_3PL >= G7_6PL) || (G7_3PL == 0)
#define  MG7_6_13PL    ~(1 << 2)
#else
#define  MG7_6_13PL    0xFFFF
#endif

#if (G7_4PL >= G7_6PL) || (G7_4PL == 0)
#define  MG7_6_14PL    ~(1 << 3)
#else
#define  MG7_6_14PL    0xFFFF
#endif

#if (G7_5PL >= G7_6PL) || (G7_5PL == 0)
#define  MG7_6_15PL    ~(1 << 4)
#else
#define  MG7_6_15PL    0xFFFF
#endif

#if (G7_7PL >= G7_6PL) || (G7_7PL == 0)
#define  MG7_6_17PL    ~(1 << 6)
#else
#define  MG7_6_17PL    0xFFFF
#endif

#if (G7_8PL >= G7_6PL) || (G7_8PL == 0)
#define  MG7_6_18PL    ~(1 << 7)
#else
#define  MG7_6_18PL    0xFFFF
#endif

#if (G7_9PL >= G7_6PL) || (G7_9PL == 0)
#define  MG7_6_19PL    ~(1 << 8)
#else
#define  MG7_6_19PL    0xFFFF
#endif

#if (G7_10PL >= G7_6PL) || (G7_10PL == 0)
#define  MG7_6_110PL    ~(1 << 9)
#else
#define  MG7_6_110PL    0xFFFF
#endif

#if (G7_11PL >= G7_6PL) || (G7_11PL == 0)
#define  MG7_6_111PL    ~(1 << 10)
#else
#define  MG7_6_111PL    0xFFFF
#endif

#if (G7_12PL >= G7_6PL) || (G7_12PL == 0)
#define  MG7_6_112PL    ~(1 << 11)
#else
#define  MG7_6_112PL    0xFFFF
#endif

#if (G7_13PL >= G7_6PL) || (G7_13PL == 0)
#define  MG7_6_113PL    ~(1 << 12)
#else
#define  MG7_6_113PL    0xFFFF
#endif

#if (G7_14PL >= G7_6PL) || (G7_14PL == 0)
#define  MG7_6_114PL    ~(1 << 13)
#else
#define  MG7_6_114PL    0xFFFF
#endif

#if (G7_15PL >= G7_6PL) || (G7_15PL == 0)
#define  MG7_6_115PL    ~(1 << 14)
#else
#define  MG7_6_115PL    0xFFFF
#endif

#if (G7_16PL >= G7_6PL) || (G7_16PL == 0)
#define  MG7_6_116PL    ~(1 << 15)
#else
#define  MG7_6_116PL    0xFFFF
#endif

#define  MG7_6_16PL	0xFFDF
#define  MG7_6    (MG7_6_11PL & MG7_6_12PL & MG7_6_13PL & MG7_6_14PL & \
                    MG7_6_15PL & MG7_6_16PL & MG7_6_17PL & MG7_6_18PL & \
                    MG7_6_19PL & MG7_6_110PL & MG7_6_111PL & MG7_6_112PL & \
                    MG7_6_113PL & MG7_6_114PL & MG7_6_115PL & MG7_6_116PL)
// End of MG7_6:
// Beginning of MG77:
#if (G7_1PL >= G7_7PL) || (G7_1PL == 0)
#define  MG7_7_11PL    ~(1 << 0)
#else
#define  MG7_7_11PL    0xFFFF
#endif

#if (G7_2PL >= G7_7PL) || (G7_2PL == 0)
#define  MG7_7_12PL    ~(1 << 1)
#else
#define  MG7_7_12PL    0xFFFF
#endif

#if (G7_3PL >= G7_7PL) || (G7_3PL == 0)
#define  MG7_7_13PL    ~(1 << 2)
#else
#define  MG7_7_13PL    0xFFFF
#endif

#if (G7_4PL >= G7_7PL) || (G7_4PL == 0)
#define  MG7_7_14PL    ~(1 << 3)
#else
#define  MG7_7_14PL    0xFFFF
#endif

#if (G7_5PL >= G7_7PL) || (G7_5PL == 0)
#define  MG7_7_15PL    ~(1 << 4)
#else
#define  MG7_7_15PL    0xFFFF
#endif

#if (G7_6PL >= G7_7PL) || (G7_6PL == 0)
#define  MG7_7_16PL    ~(1 << 5)
#else
#define  MG7_7_16PL    0xFFFF
#endif

#if (G7_8PL >= G7_7PL) || (G7_8PL == 0)
#define  MG7_7_18PL    ~(1 << 7)
#else
#define  MG7_7_18PL    0xFFFF
#endif

#if (G7_9PL >= G7_7PL) || (G7_9PL == 0)
#define  MG7_7_19PL    ~(1 << 8)
#else
#define  MG7_7_19PL    0xFFFF
#endif

#if (G7_10PL >= G7_7PL) || (G7_10PL == 0)
#define  MG7_7_110PL    ~(1 << 9)
#else
#define  MG7_7_110PL    0xFFFF
#endif

#if (G7_11PL >= G7_7PL) || (G7_11PL == 0)
#define  MG7_7_111PL    ~(1 << 10)
#else
#define  MG7_7_111PL    0xFFFF
#endif

#if (G7_12PL >= G7_7PL) || (G7_12PL == 0)
#define  MG7_7_112PL    ~(1 << 11)
#else
#define  MG7_7_112PL    0xFFFF
#endif

#if (G7_13PL >= G7_7PL) || (G7_13PL == 0)
#define  MG7_7_113PL    ~(1 << 12)
#else
#define  MG7_7_113PL    0xFFFF
#endif

#if (G7_14PL >= G7_7PL) || (G7_14PL == 0)
#define  MG7_7_114PL    ~(1 << 13)
#else
#define  MG7_7_114PL    0xFFFF
#endif

#if (G7_15PL >= G7_7PL) || (G7_15PL == 0)
#define  MG7_7_115PL    ~(1 << 14)
#else
#define  MG7_7_115PL    0xFFFF
#endif

#if (G7_16PL >= G7_7PL) || (G7_16PL == 0)
#define  MG7_7_116PL    ~(1 << 15)
#else
#define  MG7_7_116PL    0xFFFF
#endif

#define  MG7_7_17PL	0xFFBF
#define  MG7_7    (MG7_7_11PL & MG7_7_12PL & MG7_7_13PL & MG7_7_14PL & \
                    MG7_7_15PL & MG7_7_16PL & MG7_7_17PL & MG7_7_18PL & \
                    MG7_7_19PL & MG7_7_110PL & MG7_7_111PL & MG7_7_112PL & \
                    MG7_7_113PL & MG7_7_114PL & MG7_7_115PL & MG7_7_116PL)
// End of MG7_7:
// Beginning of MG78:
#if (G7_1PL >= G7_8PL) || (G7_1PL == 0)
#define  MG7_8_11PL    ~(1 << 0)
#else
#define  MG7_8_11PL    0xFFFF
#endif

#if (G7_2PL >= G7_8PL) || (G7_2PL == 0)
#define  MG7_8_12PL    ~(1 << 1)
#else
#define  MG7_8_12PL    0xFFFF
#endif

#if (G7_3PL >= G7_8PL) || (G7_3PL == 0)
#define  MG7_8_13PL    ~(1 << 2)
#else
#define  MG7_8_13PL    0xFFFF
#endif

#if (G7_4PL >= G7_8PL) || (G7_4PL == 0)
#define  MG7_8_14PL    ~(1 << 3)
#else
#define  MG7_8_14PL    0xFFFF
#endif

#if (G7_5PL >= G7_8PL) || (G7_5PL == 0)
#define  MG7_8_15PL    ~(1 << 4)
#else
#define  MG7_8_15PL    0xFFFF
#endif

#if (G7_6PL >= G7_8PL) || (G7_6PL == 0)
#define  MG7_8_16PL    ~(1 << 5)
#else
#define  MG7_8_16PL    0xFFFF
#endif

#if (G7_7PL >= G7_8PL) || (G7_7PL == 0)
#define  MG7_8_17PL    ~(1 << 6)
#else
#define  MG7_8_17PL    0xFFFF
#endif

#if (G7_9PL >= G7_8PL) || (G7_9PL == 0)
#define  MG7_8_19PL    ~(1 << 8)
#else
#define  MG7_8_19PL    0xFFFF
#endif

#if (G7_10PL >= G7_8PL) || (G7_10PL == 0)
#define  MG7_8_110PL    ~(1 << 9)
#else
#define  MG7_8_110PL    0xFFFF
#endif

#if (G7_11PL >= G7_8PL) || (G7_11PL == 0)
#define  MG7_8_111PL    ~(1 << 10)
#else
#define  MG7_8_111PL    0xFFFF
#endif

#if (G7_12PL >= G7_8PL) || (G7_12PL == 0)
#define  MG7_8_112PL    ~(1 << 11)
#else
#define  MG7_8_112PL    0xFFFF
#endif

#if (G7_13PL >= G7_8PL) || (G7_13PL == 0)
#define  MG7_8_113PL    ~(1 << 12)
#else
#define  MG7_8_113PL    0xFFFF
#endif

#if (G7_14PL >= G7_8PL) || (G7_14PL == 0)
#define  MG7_8_114PL    ~(1 << 13)
#else
#define  MG7_8_114PL    0xFFFF
#endif

#if (G7_15PL >= G7_8PL) || (G7_15PL == 0)
#define  MG7_8_115PL    ~(1 << 14)
#else
#define  MG7_8_115PL    0xFFFF
#endif

#if (G7_16PL >= G7_8PL) || (G7_16PL == 0)
#define  MG7_8_116PL    ~(1 << 15)
#else
#define  MG7_8_116PL    0xFFFF
#endif

#define  MG7_8_18PL	0xFF7F
#define  MG7_8    (MG7_8_11PL & MG7_8_12PL & MG7_8_13PL & MG7_8_14PL & \
                    MG7_8_15PL & MG7_8_16PL & MG7_8_17PL & MG7_8_18PL & \
                    MG7_8_19PL & MG7_8_110PL & MG7_8_111PL & MG7_8_112PL & \
                    MG7_8_113PL & MG7_8_114PL & MG7_8_115PL & MG7_8_116PL)
// End of MG7_8:
// Beginning of MG79:
#if (G7_1PL >= G7_9PL) || (G7_1PL == 0)
#define  MG7_9_11PL    ~(1 << 0)
#else
#define  MG7_9_11PL    0xFFFF
#endif

#if (G7_2PL >= G7_9PL) || (G7_2PL == 0)
#define  MG7_9_12PL    ~(1 << 1)
#else
#define  MG7_9_12PL    0xFFFF
#endif

#if (G7_3PL >= G7_9PL) || (G7_3PL == 0)
#define  MG7_9_13PL    ~(1 << 2)
#else
#define  MG7_9_13PL    0xFFFF
#endif

#if (G7_4PL >= G7_9PL) || (G7_4PL == 0)
#define  MG7_9_14PL    ~(1 << 3)
#else
#define  MG7_9_14PL    0xFFFF
#endif

#if (G7_5PL >= G7_9PL) || (G7_5PL == 0)
#define  MG7_9_15PL    ~(1 << 4)
#else
#define  MG7_9_15PL    0xFFFF
#endif

#if (G7_6PL >= G7_9PL) || (G7_6PL == 0)
#define  MG7_9_16PL    ~(1 << 5)
#else
#define  MG7_9_16PL    0xFFFF
#endif

#if (G7_7PL >= G7_9PL) || (G7_7PL == 0)
#define  MG7_9_17PL    ~(1 << 6)
#else
#define  MG7_9_17PL    0xFFFF
#endif

#if (G7_8PL >= G7_9PL) || (G7_8PL == 0)
#define  MG7_9_18PL    ~(1 << 7)
#else
#define  MG7_9_18PL    0xFFFF
#endif

#if (G7_10PL >= G7_9PL) || (G7_10PL == 0)
#define  MG7_9_110PL    ~(1 << 9)
#else
#define  MG7_9_110PL    0xFFFF
#endif

#if (G7_11PL >= G7_9PL) || (G7_11PL == 0)
#define  MG7_9_111PL    ~(1 << 10)
#else
#define  MG7_9_111PL    0xFFFF
#endif

#if (G7_12PL >= G7_9PL) || (G7_12PL == 0)
#define  MG7_9_112PL    ~(1 << 11)
#else
#define  MG7_9_112PL    0xFFFF
#endif

#if (G7_13PL >= G7_9PL) || (G7_13PL == 0)
#define  MG7_9_113PL    ~(1 << 12)
#else
#define  MG7_9_113PL    0xFFFF
#endif

#if (G7_14PL >= G7_9PL) || (G7_14PL == 0)
#define  MG7_9_114PL    ~(1 << 13)
#else
#define  MG7_9_114PL    0xFFFF
#endif

#if (G7_15PL >= G7_9PL) || (G7_15PL == 0)
#define  MG7_9_115PL    ~(1 << 14)
#else
#define  MG7_9_115PL    0xFFFF
#endif

#if (G7_16PL >= G7_9PL) || (G7_16PL == 0)
#define  MG7_9_116PL    ~(1 << 15)
#else
#define  MG7_9_116PL    0xFFFF
#endif

#define  MG7_9_19PL	0xFEFF
#define  MG7_9    (MG7_9_11PL & MG7_9_12PL & MG7_9_13PL & MG7_9_14PL & \
                    MG7_9_15PL & MG7_9_16PL & MG7_9_17PL & MG7_9_18PL & \
                    MG7_9_19PL & MG7_9_110PL & MG7_9_111PL & MG7_9_112PL & \
                    MG7_9_113PL & MG7_9_114PL & MG7_9_115PL & MG7_9_116PL)
// End of MG7_9:
// Beginning of MG710:
#if (G7_1PL >= G7_10PL) || (G7_1PL == 0)
#define  MG7_10_11PL    ~(1 << 0)
#else
#define  MG7_10_11PL    0xFFFF
#endif

#if (G7_2PL >= G7_10PL) || (G7_2PL == 0)
#define  MG7_10_12PL    ~(1 << 1)
#else
#define  MG7_10_12PL    0xFFFF
#endif

#if (G7_3PL >= G7_10PL) || (G7_3PL == 0)
#define  MG7_10_13PL    ~(1 << 2)
#else
#define  MG7_10_13PL    0xFFFF
#endif

#if (G7_4PL >= G7_10PL) || (G7_4PL == 0)
#define  MG7_10_14PL    ~(1 << 3)
#else
#define  MG7_10_14PL    0xFFFF
#endif

#if (G7_5PL >= G7_10PL) || (G7_5PL == 0)
#define  MG7_10_15PL    ~(1 << 4)
#else
#define  MG7_10_15PL    0xFFFF
#endif

#if (G7_6PL >= G7_10PL) || (G7_6PL == 0)
#define  MG7_10_16PL    ~(1 << 5)
#else
#define  MG7_10_16PL    0xFFFF
#endif

#if (G7_7PL >= G7_10PL) || (G7_7PL == 0)
#define  MG7_10_17PL    ~(1 << 6)
#else
#define  MG7_10_17PL    0xFFFF
#endif

#if (G7_8PL >= G7_10PL) || (G7_8PL == 0)
#define  MG7_10_18PL    ~(1 << 7)
#else
#define  MG7_10_18PL    0xFFFF
#endif

#if (G7_9PL >= G7_10PL) || (G7_9PL == 0)
#define  MG7_10_19PL    ~(1 << 8)
#else
#define  MG7_10_19PL    0xFFFF
#endif

#if (G7_11PL >= G7_10PL) || (G7_11PL == 0)
#define  MG7_10_111PL    ~(1 << 10)
#else
#define  MG7_10_111PL    0xFFFF
#endif

#if (G7_12PL >= G7_10PL) || (G7_12PL == 0)
#define  MG7_10_112PL    ~(1 << 11)
#else
#define  MG7_10_112PL    0xFFFF
#endif

#if (G7_13PL >= G7_10PL) || (G7_13PL == 0)
#define  MG7_10_113PL    ~(1 << 12)
#else
#define  MG7_10_113PL    0xFFFF
#endif

#if (G7_14PL >= G7_10PL) || (G7_14PL == 0)
#define  MG7_10_114PL    ~(1 << 13)
#else
#define  MG7_10_114PL    0xFFFF
#endif

#if (G7_15PL >= G7_10PL) || (G7_15PL == 0)
#define  MG7_10_115PL    ~(1 << 14)
#else
#define  MG7_10_115PL    0xFFFF
#endif

#if (G7_16PL >= G7_10PL) || (G7_16PL == 0)
#define  MG7_10_116PL    ~(1 << 15)
#else
#define  MG7_10_116PL    0xFFFF
#endif

#define  MG7_10_110PL	0xFDFF
#define  MG7_10    (MG7_10_11PL & MG7_10_12PL & MG7_10_13PL & MG7_10_14PL & \
                    MG7_10_15PL & MG7_10_16PL & MG7_10_17PL & MG7_10_18PL & \
                    MG7_10_19PL & MG7_10_110PL & MG7_10_111PL & MG7_10_112PL & \
                    MG7_10_113PL & MG7_10_114PL & MG7_10_115PL & MG7_10_116PL)
// End of MG7_10:
// Beginning of MG711:
#if (G7_1PL >= G7_11PL) || (G7_1PL == 0)
#define  MG7_11_11PL    ~(1 << 0)
#else
#define  MG7_11_11PL    0xFFFF
#endif

#if (G7_2PL >= G7_11PL) || (G7_2PL == 0)
#define  MG7_11_12PL    ~(1 << 1)
#else
#define  MG7_11_12PL    0xFFFF
#endif

#if (G7_3PL >= G7_11PL) || (G7_3PL == 0)
#define  MG7_11_13PL    ~(1 << 2)
#else
#define  MG7_11_13PL    0xFFFF
#endif

#if (G7_4PL >= G7_11PL) || (G7_4PL == 0)
#define  MG7_11_14PL    ~(1 << 3)
#else
#define  MG7_11_14PL    0xFFFF
#endif

#if (G7_5PL >= G7_11PL) || (G7_5PL == 0)
#define  MG7_11_15PL    ~(1 << 4)
#else
#define  MG7_11_15PL    0xFFFF
#endif

#if (G7_6PL >= G7_11PL) || (G7_6PL == 0)
#define  MG7_11_16PL    ~(1 << 5)
#else
#define  MG7_11_16PL    0xFFFF
#endif

#if (G7_7PL >= G7_11PL) || (G7_7PL == 0)
#define  MG7_11_17PL    ~(1 << 6)
#else
#define  MG7_11_17PL    0xFFFF
#endif

#if (G7_8PL >= G7_11PL) || (G7_8PL == 0)
#define  MG7_11_18PL    ~(1 << 7)
#else
#define  MG7_11_18PL    0xFFFF
#endif

#if (G7_9PL >= G7_11PL) || (G7_9PL == 0)
#define  MG7_11_19PL    ~(1 << 8)
#else
#define  MG7_11_19PL    0xFFFF
#endif

#if (G7_10PL >= G7_11PL) || (G7_10PL == 0)
#define  MG7_11_110PL    ~(1 << 9)
#else
#define  MG7_11_110PL    0xFFFF
#endif

#if (G7_12PL >= G7_11PL) || (G7_12PL == 0)
#define  MG7_11_112PL    ~(1 << 11)
#else
#define  MG7_11_112PL    0xFFFF
#endif

#if (G7_13PL >= G7_11PL) || (G7_13PL == 0)
#define  MG7_11_113PL    ~(1 << 12)
#else
#define  MG7_11_113PL    0xFFFF
#endif

#if (G7_14PL >= G7_11PL) || (G7_14PL == 0)
#define  MG7_11_114PL    ~(1 << 13)
#else
#define  MG7_11_114PL    0xFFFF
#endif

#if (G7_15PL >= G7_11PL) || (G7_15PL == 0)
#define  MG7_11_115PL    ~(1 << 14)
#else
#define  MG7_11_115PL    0xFFFF
#endif

#if (G7_16PL >= G7_11PL) || (G7_16PL == 0)
#define  MG7_11_116PL    ~(1 << 15)
#else
#define  MG7_11_116PL    0xFFFF
#endif

#define  MG7_11_111PL	0xFBFF
#define  MG7_11    (MG7_11_11PL & MG7_11_12PL & MG7_11_13PL & MG7_11_14PL & \
                    MG7_11_15PL & MG7_11_16PL & MG7_11_17PL & MG7_11_18PL & \
                    MG7_11_19PL & MG7_11_110PL & MG7_11_111PL & MG7_11_112PL & \
                    MG7_11_113PL & MG7_11_114PL & MG7_11_115PL & MG7_11_116PL)
// End of MG7_11:
// Beginning of MG712:
#if (G7_1PL >= G7_12PL) || (G7_1PL == 0)
#define  MG7_12_11PL    ~(1 << 0)
#else
#define  MG7_12_11PL    0xFFFF
#endif

#if (G7_2PL >= G7_12PL) || (G7_2PL == 0)
#define  MG7_12_12PL    ~(1 << 1)
#else
#define  MG7_12_12PL    0xFFFF
#endif

#if (G7_3PL >= G7_12PL) || (G7_3PL == 0)
#define  MG7_12_13PL    ~(1 << 2)
#else
#define  MG7_12_13PL    0xFFFF
#endif

#if (G7_4PL >= G7_12PL) || (G7_4PL == 0)
#define  MG7_12_14PL    ~(1 << 3)
#else
#define  MG7_12_14PL    0xFFFF
#endif

#if (G7_5PL >= G7_12PL) || (G7_5PL == 0)
#define  MG7_12_15PL    ~(1 << 4)
#else
#define  MG7_12_15PL    0xFFFF
#endif

#if (G7_6PL >= G7_12PL) || (G7_6PL == 0)
#define  MG7_12_16PL    ~(1 << 5)
#else
#define  MG7_12_16PL    0xFFFF
#endif

#if (G7_7PL >= G7_12PL) || (G7_7PL == 0)
#define  MG7_12_17PL    ~(1 << 6)
#else
#define  MG7_12_17PL    0xFFFF
#endif

#if (G7_8PL >= G7_12PL) || (G7_8PL == 0)
#define  MG7_12_18PL    ~(1 << 7)
#else
#define  MG7_12_18PL    0xFFFF
#endif

#if (G7_9PL >= G7_12PL) || (G7_9PL == 0)
#define  MG7_12_19PL    ~(1 << 8)
#else
#define  MG7_12_19PL    0xFFFF
#endif

#if (G7_10PL >= G7_12PL) || (G7_10PL == 0)
#define  MG7_12_110PL    ~(1 << 9)
#else
#define  MG7_12_110PL    0xFFFF
#endif

#if (G7_11PL >= G7_12PL) || (G7_11PL == 0)
#define  MG7_12_111PL    ~(1 << 10)
#else
#define  MG7_12_111PL    0xFFFF
#endif

#if (G7_13PL >= G7_12PL) || (G7_13PL == 0)
#define  MG7_12_113PL    ~(1 << 12)
#else
#define  MG7_12_113PL    0xFFFF
#endif

#if (G7_14PL >= G7_12PL) || (G7_14PL == 0)
#define  MG7_12_114PL    ~(1 << 13)
#else
#define  MG7_12_114PL    0xFFFF
#endif

#if (G7_15PL >= G7_12PL) || (G7_15PL == 0)
#define  MG7_12_115PL    ~(1 << 14)
#else
#define  MG7_12_115PL    0xFFFF
#endif

#if (G7_16PL >= G7_12PL) || (G7_16PL == 0)
#define  MG7_12_116PL    ~(1 << 15)
#else
#define  MG7_12_116PL    0xFFFF
#endif

#define  MG7_12_112PL	0xF7FF
#define  MG7_12    (MG7_12_11PL & MG7_12_12PL & MG7_12_13PL & MG7_12_14PL & \
                    MG7_12_15PL & MG7_12_16PL & MG7_12_17PL & MG7_12_18PL & \
                    MG7_12_19PL & MG7_12_110PL & MG7_12_111PL & MG7_12_112PL & \
                    MG7_12_113PL & MG7_12_114PL & MG7_12_115PL & MG7_12_116PL)
// End of MG7_12:
// Beginning of MG713:
#if (G7_1PL >= G7_13PL) || (G7_1PL == 0)
#define  MG7_13_11PL    ~(1 << 0)
#else
#define  MG7_13_11PL    0xFFFF
#endif

#if (G7_2PL >= G7_13PL) || (G7_2PL == 0)
#define  MG7_13_12PL    ~(1 << 1)
#else
#define  MG7_13_12PL    0xFFFF
#endif

#if (G7_3PL >= G7_13PL) || (G7_3PL == 0)
#define  MG7_13_13PL    ~(1 << 2)
#else
#define  MG7_13_13PL    0xFFFF
#endif

#if (G7_4PL >= G7_13PL) || (G7_4PL == 0)
#define  MG7_13_14PL    ~(1 << 3)
#else
#define  MG7_13_14PL    0xFFFF
#endif

#if (G7_5PL >= G7_13PL) || (G7_5PL == 0)
#define  MG7_13_15PL    ~(1 << 4)
#else
#define  MG7_13_15PL    0xFFFF
#endif

#if (G7_6PL >= G7_13PL) || (G7_6PL == 0)
#define  MG7_13_16PL    ~(1 << 5)
#else
#define  MG7_13_16PL    0xFFFF
#endif

#if (G7_7PL >= G7_13PL) || (G7_7PL == 0)
#define  MG7_13_17PL    ~(1 << 6)
#else
#define  MG7_13_17PL    0xFFFF
#endif

#if (G7_8PL >= G7_13PL) || (G7_8PL == 0)
#define  MG7_13_18PL    ~(1 << 7)
#else
#define  MG7_13_18PL    0xFFFF
#endif

#if (G7_9PL >= G7_13PL) || (G7_9PL == 0)
#define  MG7_13_19PL    ~(1 << 8)
#else
#define  MG7_13_19PL    0xFFFF
#endif

#if (G7_10PL >= G7_13PL) || (G7_10PL == 0)
#define  MG7_13_110PL    ~(1 << 9)
#else
#define  MG7_13_110PL    0xFFFF
#endif

#if (G7_11PL >= G7_13PL) || (G7_11PL == 0)
#define  MG7_13_111PL    ~(1 << 10)
#else
#define  MG7_13_111PL    0xFFFF
#endif

#if (G7_12PL >= G7_13PL) || (G7_12PL == 0)
#define  MG7_13_112PL    ~(1 << 11)
#else
#define  MG7_13_112PL    0xFFFF
#endif

#if (G7_14PL >= G7_13PL) || (G7_14PL == 0)
#define  MG7_13_114PL    ~(1 << 13)
#else
#define  MG7_13_114PL    0xFFFF
#endif

#if (G7_15PL >= G7_13PL) || (G7_15PL == 0)
#define  MG7_13_115PL    ~(1 << 14)
#else
#define  MG7_13_115PL    0xFFFF
#endif

#if (G7_16PL >= G7_13PL) || (G7_16PL == 0)
#define  MG7_13_116PL    ~(1 << 15)
#else
#define  MG7_13_116PL    0xFFFF
#endif

#define  MG7_13_113PL	0xEFFF
#define  MG7_13    (MG7_13_11PL & MG7_13_12PL & MG7_13_13PL & MG7_13_14PL & \
                    MG7_13_15PL & MG7_13_16PL & MG7_13_17PL & MG7_13_18PL & \
                    MG7_13_19PL & MG7_13_110PL & MG7_13_111PL & MG7_13_112PL & \
                    MG7_13_113PL & MG7_13_114PL & MG7_13_115PL & MG7_13_116PL)
// End of MG7_13:
// Beginning of MG714:
#if (G7_1PL >= G7_14PL) || (G7_1PL == 0)
#define  MG7_14_11PL    ~(1 << 0)
#else
#define  MG7_14_11PL    0xFFFF
#endif

#if (G7_2PL >= G7_14PL) || (G7_2PL == 0)
#define  MG7_14_12PL    ~(1 << 1)
#else
#define  MG7_14_12PL    0xFFFF
#endif

#if (G7_3PL >= G7_14PL) || (G7_3PL == 0)
#define  MG7_14_13PL    ~(1 << 2)
#else
#define  MG7_14_13PL    0xFFFF
#endif

#if (G7_4PL >= G7_14PL) || (G7_4PL == 0)
#define  MG7_14_14PL    ~(1 << 3)
#else
#define  MG7_14_14PL    0xFFFF
#endif

#if (G7_5PL >= G7_14PL) || (G7_5PL == 0)
#define  MG7_14_15PL    ~(1 << 4)
#else
#define  MG7_14_15PL    0xFFFF
#endif

#if (G7_6PL >= G7_14PL) || (G7_6PL == 0)
#define  MG7_14_16PL    ~(1 << 5)
#else
#define  MG7_14_16PL    0xFFFF
#endif

#if (G7_7PL >= G7_14PL) || (G7_7PL == 0)
#define  MG7_14_17PL    ~(1 << 6)
#else
#define  MG7_14_17PL    0xFFFF
#endif

#if (G7_8PL >= G7_14PL) || (G7_8PL == 0)
#define  MG7_14_18PL    ~(1 << 7)
#else
#define  MG7_14_18PL    0xFFFF
#endif

#if (G7_9PL >= G7_14PL) || (G7_9PL == 0)
#define  MG7_14_19PL    ~(1 << 8)
#else
#define  MG7_14_19PL    0xFFFF
#endif

#if (G7_10PL >= G7_14PL) || (G7_10PL == 0)
#define  MG7_14_110PL    ~(1 << 9)
#else
#define  MG7_14_110PL    0xFFFF
#endif

#if (G7_11PL >= G7_14PL) || (G7_11PL == 0)
#define  MG7_14_111PL    ~(1 << 10)
#else
#define  MG7_14_111PL    0xFFFF
#endif

#if (G7_12PL >= G7_14PL) || (G7_12PL == 0)
#define  MG7_14_112PL    ~(1 << 11)
#else
#define  MG7_14_112PL    0xFFFF
#endif

#if (G7_13PL >= G7_14PL) || (G7_13PL == 0)
#define  MG7_14_113PL    ~(1 << 12)
#else
#define  MG7_14_113PL    0xFFFF
#endif

#if (G7_15PL >= G7_14PL) || (G7_15PL == 0)
#define  MG7_14_115PL    ~(1 << 14)
#else
#define  MG7_14_115PL    0xFFFF
#endif

#if (G7_16PL >= G7_14PL) || (G7_16PL == 0)
#define  MG7_14_116PL    ~(1 << 15)
#else
#define  MG7_14_116PL    0xFFFF
#endif

#define  MG7_14_114PL	0xDFFF
#define  MG7_14    (MG7_14_11PL & MG7_14_12PL & MG7_14_13PL & MG7_14_14PL & \
                    MG7_14_15PL & MG7_14_16PL & MG7_14_17PL & MG7_14_18PL & \
                    MG7_14_19PL & MG7_14_110PL & MG7_14_111PL & MG7_14_112PL & \
                    MG7_14_113PL & MG7_14_114PL & MG7_14_115PL & MG7_14_116PL)
// End of MG7_14:
// Beginning of MG715:
#if (G7_1PL >= G7_15PL) || (G7_1PL == 0)
#define  MG7_15_11PL    ~(1 << 0)
#else
#define  MG7_15_11PL    0xFFFF
#endif

#if (G7_2PL >= G7_15PL) || (G7_2PL == 0)
#define  MG7_15_12PL    ~(1 << 1)
#else
#define  MG7_15_12PL    0xFFFF
#endif

#if (G7_3PL >= G7_15PL) || (G7_3PL == 0)
#define  MG7_15_13PL    ~(1 << 2)
#else
#define  MG7_15_13PL    0xFFFF
#endif

#if (G7_4PL >= G7_15PL) || (G7_4PL == 0)
#define  MG7_15_14PL    ~(1 << 3)
#else
#define  MG7_15_14PL    0xFFFF
#endif

#if (G7_5PL >= G7_15PL) || (G7_5PL == 0)
#define  MG7_15_15PL    ~(1 << 4)
#else
#define  MG7_15_15PL    0xFFFF
#endif

#if (G7_6PL >= G7_15PL) || (G7_6PL == 0)
#define  MG7_15_16PL    ~(1 << 5)
#else
#define  MG7_15_16PL    0xFFFF
#endif

#if (G7_7PL >= G7_15PL) || (G7_7PL == 0)
#define  MG7_15_17PL    ~(1 << 6)
#else
#define  MG7_15_17PL    0xFFFF
#endif

#if (G7_8PL >= G7_15PL) || (G7_8PL == 0)
#define  MG7_15_18PL    ~(1 << 7)
#else
#define  MG7_15_18PL    0xFFFF
#endif

#if (G7_9PL >= G7_15PL) || (G7_9PL == 0)
#define  MG7_15_19PL    ~(1 << 8)
#else
#define  MG7_15_19PL    0xFFFF
#endif

#if (G7_10PL >= G7_15PL) || (G7_10PL == 0)
#define  MG7_15_110PL    ~(1 << 9)
#else
#define  MG7_15_110PL    0xFFFF
#endif

#if (G7_11PL >= G7_15PL) || (G7_11PL == 0)
#define  MG7_15_111PL    ~(1 << 10)
#else
#define  MG7_15_111PL    0xFFFF
#endif

#if (G7_12PL >= G7_15PL) || (G7_12PL == 0)
#define  MG7_15_112PL    ~(1 << 11)
#else
#define  MG7_15_112PL    0xFFFF
#endif

#if (G7_13PL >= G7_15PL) || (G7_13PL == 0)
#define  MG7_15_113PL    ~(1 << 12)
#else
#define  MG7_15_113PL    0xFFFF
#endif

#if (G7_14PL >= G7_15PL) || (G7_14PL == 0)
#define  MG7_15_114PL    ~(1 << 13)
#else
#define  MG7_15_114PL    0xFFFF
#endif

#if (G7_16PL >= G7_15PL) || (G7_16PL == 0)
#define  MG7_15_116PL    ~(1 << 15)
#else
#define  MG7_15_116PL    0xFFFF
#endif

#define  MG7_15_115PL	0xBFFF
#define  MG7_15    (MG7_15_11PL & MG7_15_12PL & MG7_15_13PL & MG7_15_14PL & \
                    MG7_15_15PL & MG7_15_16PL & MG7_15_17PL & MG7_15_18PL & \
                    MG7_15_19PL & MG7_15_110PL & MG7_15_111PL & MG7_15_112PL & \
                    MG7_15_113PL & MG7_15_114PL & MG7_15_115PL & MG7_15_116PL)
// End of MG7_15:
// Beginning of MG716:
#if (G7_1PL >= G7_16PL) || (G7_1PL == 0)
#define  MG7_16_11PL    ~(1 << 0)
#else
#define  MG7_16_11PL    0xFFFF
#endif

#if (G7_2PL >= G7_16PL) || (G7_2PL == 0)
#define  MG7_16_12PL    ~(1 << 1)
#else
#define  MG7_16_12PL    0xFFFF
#endif

#if (G7_3PL >= G7_16PL) || (G7_3PL == 0)
#define  MG7_16_13PL    ~(1 << 2)
#else
#define  MG7_16_13PL    0xFFFF
#endif

#if (G7_4PL >= G7_16PL) || (G7_4PL == 0)
#define  MG7_16_14PL    ~(1 << 3)
#else
#define  MG7_16_14PL    0xFFFF
#endif

#if (G7_5PL >= G7_16PL) || (G7_5PL == 0)
#define  MG7_16_15PL    ~(1 << 4)
#else
#define  MG7_16_15PL    0xFFFF
#endif

#if (G7_6PL >= G7_16PL) || (G7_6PL == 0)
#define  MG7_16_16PL    ~(1 << 5)
#else
#define  MG7_16_16PL    0xFFFF
#endif

#if (G7_7PL >= G7_16PL) || (G7_7PL == 0)
#define  MG7_16_17PL    ~(1 << 6)
#else
#define  MG7_16_17PL    0xFFFF
#endif

#if (G7_8PL >= G7_16PL) || (G7_8PL == 0)
#define  MG7_16_18PL    ~(1 << 7)
#else
#define  MG7_16_18PL    0xFFFF
#endif

#if (G7_9PL >= G7_16PL) || (G7_9PL == 0)
#define  MG7_16_19PL    ~(1 << 8)
#else
#define  MG7_16_19PL    0xFFFF
#endif

#if (G7_10PL >= G7_16PL) || (G7_10PL == 0)
#define  MG7_16_110PL    ~(1 << 9)
#else
#define  MG7_16_110PL    0xFFFF
#endif

#if (G7_11PL >= G7_16PL) || (G7_11PL == 0)
#define  MG7_16_111PL    ~(1 << 10)
#else
#define  MG7_16_111PL    0xFFFF
#endif

#if (G7_12PL >= G7_16PL) || (G7_12PL == 0)
#define  MG7_16_112PL    ~(1 << 11)
#else
#define  MG7_16_112PL    0xFFFF
#endif

#if (G7_13PL >= G7_16PL) || (G7_13PL == 0)
#define  MG7_16_113PL    ~(1 << 12)
#else
#define  MG7_16_113PL    0xFFFF
#endif

#if (G7_14PL >= G7_16PL) || (G7_14PL == 0)
#define  MG7_16_114PL    ~(1 << 13)
#else
#define  MG7_16_114PL    0xFFFF
#endif

#if (G7_15PL >= G7_16PL) || (G7_15PL == 0)
#define  MG7_16_115PL    ~(1 << 14)
#else
#define  MG7_16_115PL    0xFFFF
#endif

#define  MG7_16_116PL	0x7FFF
#define  MG7_16    (MG7_16_11PL & MG7_16_12PL & MG7_16_13PL & MG7_16_14PL & \
                    MG7_16_15PL & MG7_16_16PL & MG7_16_17PL & MG7_16_18PL & \
                    MG7_16_19PL & MG7_16_110PL & MG7_16_111PL & MG7_16_112PL & \
                    MG7_16_113PL & MG7_16_114PL & MG7_16_115PL & MG7_16_116PL)
// End of MG7_16:


//-------------------------------------------------------------------------------
// Automatically generate PIEIER8 interrupt masks MG81 to MG816:

// Beginning of MG81:
#if (G8_2PL >= G8_1PL) || (G8_2PL == 0)
#define  MG8_1_12PL    ~(1 << 1)
#else
#define  MG8_1_12PL    0xFFFF
#endif

#if (G8_3PL >= G8_1PL) || (G8_3PL == 0)
#define  MG8_1_13PL    ~(1 << 2)
#else
#define  MG8_1_13PL    0xFFFF
#endif

#if (G8_4PL >= G8_1PL) || (G8_4PL == 0)
#define  MG8_1_14PL    ~(1 << 3)
#else
#define  MG8_1_14PL    0xFFFF
#endif

#if (G8_5PL >= G8_1PL) || (G8_5PL == 0)
#define  MG8_1_15PL    ~(1 << 4)
#else
#define  MG8_1_15PL    0xFFFF
#endif

#if (G8_6PL >= G8_1PL) || (G8_6PL == 0)
#define  MG8_1_16PL    ~(1 << 5)
#else
#define  MG8_1_16PL    0xFFFF
#endif

#if (G8_7PL >= G8_1PL) || (G8_7PL == 0)
#define  MG8_1_17PL    ~(1 << 6)
#else
#define  MG8_1_17PL    0xFFFF
#endif

#if (G8_8PL >= G8_1PL) || (G8_8PL == 0)
#define  MG8_1_18PL    ~(1 << 7)
#else
#define  MG8_1_18PL    0xFFFF
#endif

#if (G8_9PL >= G8_1PL) || (G8_9PL == 0)
#define  MG8_1_19PL    ~(1 << 8)
#else
#define  MG8_1_19PL    0xFFFF
#endif

#if (G8_10PL >= G8_1PL) || (G8_10PL == 0)
#define  MG8_1_110PL    ~(1 << 9)
#else
#define  MG8_1_110PL    0xFFFF
#endif

#if (G8_11PL >= G8_1PL) || (G8_11PL == 0)
#define  MG8_1_111PL    ~(1 << 10)
#else
#define  MG8_1_111PL    0xFFFF
#endif

#if (G8_12PL >= G8_1PL) || (G8_12PL == 0)
#define  MG8_1_112PL    ~(1 << 11)
#else
#define  MG8_1_112PL    0xFFFF
#endif

#if (G8_13PL >= G8_1PL) || (G8_13PL == 0)
#define  MG8_1_113PL    ~(1 << 12)
#else
#define  MG8_1_113PL    0xFFFF
#endif

#if (G8_14PL >= G8_1PL) || (G8_14PL == 0)
#define  MG8_1_114PL    ~(1 << 13)
#else
#define  MG8_1_114PL    0xFFFF
#endif

#if (G8_15PL >= G8_1PL) || (G8_15PL == 0)
#define  MG8_1_115PL    ~(1 << 14)
#else
#define  MG8_1_115PL    0xFFFF
#endif

#if (G8_16PL >= G8_1PL) || (G8_16PL == 0)
#define  MG8_1_116PL    ~(1 << 15)
#else
#define  MG8_1_116PL    0xFFFF
#endif

#define  MG8_1_11PL	0xFFFE
#define  MG8_1    (MG8_1_11PL & MG8_1_12PL & MG8_1_13PL & MG8_1_14PL & \
                    MG8_1_15PL & MG8_1_16PL & MG8_1_17PL & MG8_1_18PL & \
                    MG8_1_19PL & MG8_1_110PL & MG8_1_111PL & MG8_1_112PL & \
                    MG8_1_113PL & MG8_1_114PL & MG8_1_115PL & MG8_1_116PL)
// End of MG8_1:
// Beginning of MG82:
#if (G8_1PL >= G8_2PL) || (G8_1PL == 0)
#define  MG8_2_11PL    ~(1 << 0)
#else
#define  MG8_2_11PL    0xFFFF
#endif

#if (G8_3PL >= G8_2PL) || (G8_3PL == 0)
#define  MG8_2_13PL    ~(1 << 2)
#else
#define  MG8_2_13PL    0xFFFF
#endif

#if (G8_4PL >= G8_2PL) || (G8_4PL == 0)
#define  MG8_2_14PL    ~(1 << 3)
#else
#define  MG8_2_14PL    0xFFFF
#endif

#if (G8_5PL >= G8_2PL) || (G8_5PL == 0)
#define  MG8_2_15PL    ~(1 << 4)
#else
#define  MG8_2_15PL    0xFFFF
#endif

#if (G8_6PL >= G8_2PL) || (G8_6PL == 0)
#define  MG8_2_16PL    ~(1 << 5)
#else
#define  MG8_2_16PL    0xFFFF
#endif

#if (G8_7PL >= G8_2PL) || (G8_7PL == 0)
#define  MG8_2_17PL    ~(1 << 6)
#else
#define  MG8_2_17PL    0xFFFF
#endif

#if (G8_8PL >= G8_2PL) || (G8_8PL == 0)
#define  MG8_2_18PL    ~(1 << 7)
#else
#define  MG8_2_18PL    0xFFFF
#endif

#if (G8_9PL >= G8_2PL) || (G8_9PL == 0)
#define  MG8_2_19PL    ~(1 << 8)
#else
#define  MG8_2_19PL    0xFFFF
#endif

#if (G8_10PL >= G8_2PL) || (G8_10PL == 0)
#define  MG8_2_110PL    ~(1 << 9)
#else
#define  MG8_2_110PL    0xFFFF
#endif

#if (G8_11PL >= G8_2PL) || (G8_11PL == 0)
#define  MG8_2_111PL    ~(1 << 10)
#else
#define  MG8_2_111PL    0xFFFF
#endif

#if (G8_12PL >= G8_2PL) || (G8_12PL == 0)
#define  MG8_2_112PL    ~(1 << 11)
#else
#define  MG8_2_112PL    0xFFFF
#endif

#if (G8_13PL >= G8_2PL) || (G8_13PL == 0)
#define  MG8_2_113PL    ~(1 << 12)
#else
#define  MG8_2_113PL    0xFFFF
#endif

#if (G8_14PL >= G8_2PL) || (G8_14PL == 0)
#define  MG8_2_114PL    ~(1 << 13)
#else
#define  MG8_2_114PL    0xFFFF
#endif

#if (G8_15PL >= G8_2PL) || (G8_15PL == 0)
#define  MG8_2_115PL    ~(1 << 14)
#else
#define  MG8_2_115PL    0xFFFF
#endif

#if (G8_16PL >= G8_2PL) || (G8_16PL == 0)
#define  MG8_2_116PL    ~(1 << 15)
#else
#define  MG8_2_116PL    0xFFFF
#endif

#define  MG8_2_12PL	0xFFFD
#define  MG8_2    (MG8_2_11PL & MG8_2_12PL & MG8_2_13PL & MG8_2_14PL & \
                    MG8_2_15PL & MG8_2_16PL & MG8_2_17PL & MG8_2_18PL & \
                    MG8_2_19PL & MG8_2_110PL & MG8_2_111PL & MG8_2_112PL & \
                    MG8_2_113PL & MG8_2_114PL & MG8_2_115PL & MG8_2_116PL)
// End of MG8_2:
// Beginning of MG83:
#if (G8_1PL >= G8_3PL) || (G8_1PL == 0)
#define  MG8_3_11PL    ~(1 << 0)
#else
#define  MG8_3_11PL    0xFFFF
#endif

#if (G8_2PL >= G8_3PL) || (G8_2PL == 0)
#define  MG8_3_12PL    ~(1 << 1)
#else
#define  MG8_3_12PL    0xFFFF
#endif

#if (G8_4PL >= G8_3PL) || (G8_4PL == 0)
#define  MG8_3_14PL    ~(1 << 3)
#else
#define  MG8_3_14PL    0xFFFF
#endif

#if (G8_5PL >= G8_3PL) || (G8_5PL == 0)
#define  MG8_3_15PL    ~(1 << 4)
#else
#define  MG8_3_15PL    0xFFFF
#endif

#if (G8_6PL >= G8_3PL) || (G8_6PL == 0)
#define  MG8_3_16PL    ~(1 << 5)
#else
#define  MG8_3_16PL    0xFFFF
#endif

#if (G8_7PL >= G8_3PL) || (G8_7PL == 0)
#define  MG8_3_17PL    ~(1 << 6)
#else
#define  MG8_3_17PL    0xFFFF
#endif

#if (G8_8PL >= G8_3PL) || (G8_8PL == 0)
#define  MG8_3_18PL    ~(1 << 7)
#else
#define  MG8_3_18PL    0xFFFF
#endif

#if (G8_9PL >= G8_3PL) || (G8_9PL == 0)
#define  MG8_3_19PL    ~(1 << 8)
#else
#define  MG8_3_19PL    0xFFFF
#endif

#if (G8_10PL >= G8_3PL) || (G8_10PL == 0)
#define  MG8_3_110PL    ~(1 << 9)
#else
#define  MG8_3_110PL    0xFFFF
#endif

#if (G8_11PL >= G8_3PL) || (G8_11PL == 0)
#define  MG8_3_111PL    ~(1 << 10)
#else
#define  MG8_3_111PL    0xFFFF
#endif

#if (G8_12PL >= G8_3PL) || (G8_12PL == 0)
#define  MG8_3_112PL    ~(1 << 11)
#else
#define  MG8_3_112PL    0xFFFF
#endif

#if (G8_13PL >= G8_3PL) || (G8_13PL == 0)
#define  MG8_3_113PL    ~(1 << 12)
#else
#define  MG8_3_113PL    0xFFFF
#endif

#if (G8_14PL >= G8_3PL) || (G8_14PL == 0)
#define  MG8_3_114PL    ~(1 << 13)
#else
#define  MG8_3_114PL    0xFFFF
#endif

#if (G8_15PL >= G8_3PL) || (G8_15PL == 0)
#define  MG8_3_115PL    ~(1 << 14)
#else
#define  MG8_3_115PL    0xFFFF
#endif

#if (G8_16PL >= G8_3PL) || (G8_16PL == 0)
#define  MG8_3_116PL    ~(1 << 15)
#else
#define  MG8_3_116PL    0xFFFF
#endif

#define  MG8_3_13PL	0xFFFB
#define  MG8_3    (MG8_3_11PL & MG8_3_12PL & MG8_3_13PL & MG8_3_14PL & \
                    MG8_3_15PL & MG8_3_16PL & MG8_3_17PL & MG8_3_18PL & \
                    MG8_3_19PL & MG8_3_110PL & MG8_3_111PL & MG8_3_112PL & \
                    MG8_3_113PL & MG8_3_114PL & MG8_3_115PL & MG8_3_116PL)
// End of MG8_3:
// Beginning of MG84:
#if (G8_1PL >= G8_4PL) || (G8_1PL == 0)
#define  MG8_4_11PL    ~(1 << 0)
#else
#define  MG8_4_11PL    0xFFFF
#endif

#if (G8_2PL >= G8_4PL) || (G8_2PL == 0)
#define  MG8_4_12PL    ~(1 << 1)
#else
#define  MG8_4_12PL    0xFFFF
#endif

#if (G8_3PL >= G8_4PL) || (G8_3PL == 0)
#define  MG8_4_13PL    ~(1 << 2)
#else
#define  MG8_4_13PL    0xFFFF
#endif

#if (G8_5PL >= G8_4PL) || (G8_5PL == 0)
#define  MG8_4_15PL    ~(1 << 4)
#else
#define  MG8_4_15PL    0xFFFF
#endif

#if (G8_6PL >= G8_4PL) || (G8_6PL == 0)
#define  MG8_4_16PL    ~(1 << 5)
#else
#define  MG8_4_16PL    0xFFFF
#endif

#if (G8_7PL >= G8_4PL) || (G8_7PL == 0)
#define  MG8_4_17PL    ~(1 << 6)
#else
#define  MG8_4_17PL    0xFFFF
#endif

#if (G8_8PL >= G8_4PL) || (G8_8PL == 0)
#define  MG8_4_18PL    ~(1 << 7)
#else
#define  MG8_4_18PL    0xFFFF
#endif

#if (G8_9PL >= G8_4PL) || (G8_9PL == 0)
#define  MG8_4_19PL    ~(1 << 8)
#else
#define  MG8_4_19PL    0xFFFF
#endif

#if (G8_10PL >= G8_4PL) || (G8_10PL == 0)
#define  MG8_4_110PL    ~(1 << 9)
#else
#define  MG8_4_110PL    0xFFFF
#endif

#if (G8_11PL >= G8_4PL) || (G8_11PL == 0)
#define  MG8_4_111PL    ~(1 << 10)
#else
#define  MG8_4_111PL    0xFFFF
#endif

#if (G8_12PL >= G8_4PL) || (G8_12PL == 0)
#define  MG8_4_112PL    ~(1 << 11)
#else
#define  MG8_4_112PL    0xFFFF
#endif

#if (G8_13PL >= G8_4PL) || (G8_13PL == 0)
#define  MG8_4_113PL    ~(1 << 12)
#else
#define  MG8_4_113PL    0xFFFF
#endif

#if (G8_14PL >= G8_4PL) || (G8_14PL == 0)
#define  MG8_4_114PL    ~(1 << 13)
#else
#define  MG8_4_114PL    0xFFFF
#endif

#if (G8_15PL >= G8_4PL) || (G8_15PL == 0)
#define  MG8_4_115PL    ~(1 << 14)
#else
#define  MG8_4_115PL    0xFFFF
#endif

#if (G8_16PL >= G8_4PL) || (G8_16PL == 0)
#define  MG8_4_116PL    ~(1 << 15)
#else
#define  MG8_4_116PL    0xFFFF
#endif

#define  MG8_4_14PL	0xFFF7
#define  MG8_4    (MG8_4_11PL & MG8_4_12PL & MG8_4_13PL & MG8_4_14PL & \
                    MG8_4_15PL & MG8_4_16PL & MG8_4_17PL & MG8_4_18PL & \
                    MG8_4_19PL & MG8_4_110PL & MG8_4_111PL & MG8_4_112PL & \
                    MG8_4_113PL & MG8_4_114PL & MG8_4_115PL & MG8_4_116PL)
// End of MG8_4:
// Beginning of MG85:
#if (G8_1PL >= G8_5PL) || (G8_1PL == 0)
#define  MG8_5_11PL    ~(1 << 0)
#else
#define  MG8_5_11PL    0xFFFF
#endif

#if (G8_2PL >= G8_5PL) || (G8_2PL == 0)
#define  MG8_5_12PL    ~(1 << 1)
#else
#define  MG8_5_12PL    0xFFFF
#endif

#if (G8_3PL >= G8_5PL) || (G8_3PL == 0)
#define  MG8_5_13PL    ~(1 << 2)
#else
#define  MG8_5_13PL    0xFFFF
#endif

#if (G8_4PL >= G8_5PL) || (G8_4PL == 0)
#define  MG8_5_14PL    ~(1 << 3)
#else
#define  MG8_5_14PL    0xFFFF
#endif

#if (G8_6PL >= G8_5PL) || (G8_6PL == 0)
#define  MG8_5_16PL    ~(1 << 5)
#else
#define  MG8_5_16PL    0xFFFF
#endif

#if (G8_7PL >= G8_5PL) || (G8_7PL == 0)
#define  MG8_5_17PL    ~(1 << 6)
#else
#define  MG8_5_17PL    0xFFFF
#endif

#if (G8_8PL >= G8_5PL) || (G8_8PL == 0)
#define  MG8_5_18PL    ~(1 << 7)
#else
#define  MG8_5_18PL    0xFFFF
#endif

#if (G8_9PL >= G8_5PL) || (G8_9PL == 0)
#define  MG8_5_19PL    ~(1 << 8)
#else
#define  MG8_5_19PL    0xFFFF
#endif

#if (G8_10PL >= G8_5PL) || (G8_10PL == 0)
#define  MG8_5_110PL    ~(1 << 9)
#else
#define  MG8_5_110PL    0xFFFF
#endif

#if (G8_11PL >= G8_5PL) || (G8_11PL == 0)
#define  MG8_5_111PL    ~(1 << 10)
#else
#define  MG8_5_111PL    0xFFFF
#endif

#if (G8_12PL >= G8_5PL) || (G8_12PL == 0)
#define  MG8_5_112PL    ~(1 << 11)
#else
#define  MG8_5_112PL    0xFFFF
#endif

#if (G8_13PL >= G8_5PL) || (G8_13PL == 0)
#define  MG8_5_113PL    ~(1 << 12)
#else
#define  MG8_5_113PL    0xFFFF
#endif

#if (G8_14PL >= G8_5PL) || (G8_14PL == 0)
#define  MG8_5_114PL    ~(1 << 13)
#else
#define  MG8_5_114PL    0xFFFF
#endif

#if (G8_15PL >= G8_5PL) || (G8_15PL == 0)
#define  MG8_5_115PL    ~(1 << 14)
#else
#define  MG8_5_115PL    0xFFFF
#endif

#if (G8_16PL >= G8_5PL) || (G8_16PL == 0)
#define  MG8_5_116PL    ~(1 << 15)
#else
#define  MG8_5_116PL    0xFFFF
#endif

#define  MG8_5_15PL	0xFFEF
#define  MG8_5    (MG8_5_11PL & MG8_5_12PL & MG8_5_13PL & MG8_5_14PL & \
                    MG8_5_15PL & MG8_5_16PL & MG8_5_17PL & MG8_5_18PL & \
                    MG8_5_19PL & MG8_5_110PL & MG8_5_111PL & MG8_5_112PL & \
                    MG8_5_113PL & MG8_5_114PL & MG8_5_115PL & MG8_5_116PL)
// End of MG8_5:
// Beginning of MG86:
#if (G8_1PL >= G8_6PL) || (G8_1PL == 0)
#define  MG8_6_11PL    ~(1 << 0)
#else
#define  MG8_6_11PL    0xFFFF
#endif

#if (G8_2PL >= G8_6PL) || (G8_2PL == 0)
#define  MG8_6_12PL    ~(1 << 1)
#else
#define  MG8_6_12PL    0xFFFF
#endif

#if (G8_3PL >= G8_6PL) || (G8_3PL == 0)
#define  MG8_6_13PL    ~(1 << 2)
#else
#define  MG8_6_13PL    0xFFFF
#endif

#if (G8_4PL >= G8_6PL) || (G8_4PL == 0)
#define  MG8_6_14PL    ~(1 << 3)
#else
#define  MG8_6_14PL    0xFFFF
#endif

#if (G8_5PL >= G8_6PL) || (G8_5PL == 0)
#define  MG8_6_15PL    ~(1 << 4)
#else
#define  MG8_6_15PL    0xFFFF
#endif

#if (G8_7PL >= G8_6PL) || (G8_7PL == 0)
#define  MG8_6_17PL    ~(1 << 6)
#else
#define  MG8_6_17PL    0xFFFF
#endif

#if (G8_8PL >= G8_6PL) || (G8_8PL == 0)
#define  MG8_6_18PL    ~(1 << 7)
#else
#define  MG8_6_18PL    0xFFFF
#endif

#if (G8_9PL >= G8_6PL) || (G8_9PL == 0)
#define  MG8_6_19PL    ~(1 << 8)
#else
#define  MG8_6_19PL    0xFFFF
#endif

#if (G8_10PL >= G8_6PL) || (G8_10PL == 0)
#define  MG8_6_110PL    ~(1 << 9)
#else
#define  MG8_6_110PL    0xFFFF
#endif

#if (G8_11PL >= G8_6PL) || (G8_11PL == 0)
#define  MG8_6_111PL    ~(1 << 10)
#else
#define  MG8_6_111PL    0xFFFF
#endif

#if (G8_12PL >= G8_6PL) || (G8_12PL == 0)
#define  MG8_6_112PL    ~(1 << 11)
#else
#define  MG8_6_112PL    0xFFFF
#endif

#if (G8_13PL >= G8_6PL) || (G8_13PL == 0)
#define  MG8_6_113PL    ~(1 << 12)
#else
#define  MG8_6_113PL    0xFFFF
#endif

#if (G8_14PL >= G8_6PL) || (G8_14PL == 0)
#define  MG8_6_114PL    ~(1 << 13)
#else
#define  MG8_6_114PL    0xFFFF
#endif

#if (G8_15PL >= G8_6PL) || (G8_15PL == 0)
#define  MG8_6_115PL    ~(1 << 14)
#else
#define  MG8_6_115PL    0xFFFF
#endif

#if (G8_16PL >= G8_6PL) || (G8_16PL == 0)
#define  MG8_6_116PL    ~(1 << 15)
#else
#define  MG8_6_116PL    0xFFFF
#endif

#define  MG8_6_16PL	0xFFDF
#define  MG8_6    (MG8_6_11PL & MG8_6_12PL & MG8_6_13PL & MG8_6_14PL & \
                    MG8_6_15PL & MG8_6_16PL & MG8_6_17PL & MG8_6_18PL & \
                    MG8_6_19PL & MG8_6_110PL & MG8_6_111PL & MG8_6_112PL & \
                    MG8_6_113PL & MG8_6_114PL & MG8_6_115PL & MG8_6_116PL)
// End of MG8_6:
// Beginning of MG87:
#if (G8_1PL >= G8_7PL) || (G8_1PL == 0)
#define  MG8_7_11PL    ~(1 << 0)
#else
#define  MG8_7_11PL    0xFFFF
#endif

#if (G8_2PL >= G8_7PL) || (G8_2PL == 0)
#define  MG8_7_12PL    ~(1 << 1)
#else
#define  MG8_7_12PL    0xFFFF
#endif

#if (G8_3PL >= G8_7PL) || (G8_3PL == 0)
#define  MG8_7_13PL    ~(1 << 2)
#else
#define  MG8_7_13PL    0xFFFF
#endif

#if (G8_4PL >= G8_7PL) || (G8_4PL == 0)
#define  MG8_7_14PL    ~(1 << 3)
#else
#define  MG8_7_14PL    0xFFFF
#endif

#if (G8_5PL >= G8_7PL) || (G8_5PL == 0)
#define  MG8_7_15PL    ~(1 << 4)
#else
#define  MG8_7_15PL    0xFFFF
#endif

#if (G8_6PL >= G8_7PL) || (G8_6PL == 0)
#define  MG8_7_16PL    ~(1 << 5)
#else
#define  MG8_7_16PL    0xFFFF
#endif

#if (G8_8PL >= G8_7PL) || (G8_8PL == 0)
#define  MG8_7_18PL    ~(1 << 7)
#else
#define  MG8_7_18PL    0xFFFF
#endif

#if (G8_9PL >= G8_7PL) || (G8_9PL == 0)
#define  MG8_7_19PL    ~(1 << 8)
#else
#define  MG8_7_19PL    0xFFFF
#endif

#if (G8_10PL >= G8_7PL) || (G8_10PL == 0)
#define  MG8_7_110PL    ~(1 << 9)
#else
#define  MG8_7_110PL    0xFFFF
#endif

#if (G8_11PL >= G8_7PL) || (G8_11PL == 0)
#define  MG8_7_111PL    ~(1 << 10)
#else
#define  MG8_7_111PL    0xFFFF
#endif

#if (G8_12PL >= G8_7PL) || (G8_12PL == 0)
#define  MG8_7_112PL    ~(1 << 11)
#else
#define  MG8_7_112PL    0xFFFF
#endif

#if (G8_13PL >= G8_7PL) || (G8_13PL == 0)
#define  MG8_7_113PL    ~(1 << 12)
#else
#define  MG8_7_113PL    0xFFFF
#endif

#if (G8_14PL >= G8_7PL) || (G8_14PL == 0)
#define  MG8_7_114PL    ~(1 << 13)
#else
#define  MG8_7_114PL    0xFFFF
#endif

#if (G8_15PL >= G8_7PL) || (G8_15PL == 0)
#define  MG8_7_115PL    ~(1 << 14)
#else
#define  MG8_7_115PL    0xFFFF
#endif

#if (G8_16PL >= G8_7PL) || (G8_16PL == 0)
#define  MG8_7_116PL    ~(1 << 15)
#else
#define  MG8_7_116PL    0xFFFF
#endif

#define  MG8_7_17PL	0xFFBF
#define  MG8_7    (MG8_7_11PL & MG8_7_12PL & MG8_7_13PL & MG8_7_14PL & \
                    MG8_7_15PL & MG8_7_16PL & MG8_7_17PL & MG8_7_18PL & \
                    MG8_7_19PL & MG8_7_110PL & MG8_7_111PL & MG8_7_112PL & \
                    MG8_7_113PL & MG8_7_114PL & MG8_7_115PL & MG8_7_116PL)
// End of MG8_7:
// Beginning of MG88:
#if (G8_1PL >= G8_8PL) || (G8_1PL == 0)
#define  MG8_8_11PL    ~(1 << 0)
#else
#define  MG8_8_11PL    0xFFFF
#endif

#if (G8_2PL >= G8_8PL) || (G8_2PL == 0)
#define  MG8_8_12PL    ~(1 << 1)
#else
#define  MG8_8_12PL    0xFFFF
#endif

#if (G8_3PL >= G8_8PL) || (G8_3PL == 0)
#define  MG8_8_13PL    ~(1 << 2)
#else
#define  MG8_8_13PL    0xFFFF
#endif

#if (G8_4PL >= G8_8PL) || (G8_4PL == 0)
#define  MG8_8_14PL    ~(1 << 3)
#else
#define  MG8_8_14PL    0xFFFF
#endif

#if (G8_5PL >= G8_8PL) || (G8_5PL == 0)
#define  MG8_8_15PL    ~(1 << 4)
#else
#define  MG8_8_15PL    0xFFFF
#endif

#if (G8_6PL >= G8_8PL) || (G8_6PL == 0)
#define  MG8_8_16PL    ~(1 << 5)
#else
#define  MG8_8_16PL    0xFFFF
#endif

#if (G8_7PL >= G8_8PL) || (G8_7PL == 0)
#define  MG8_8_17PL    ~(1 << 6)
#else
#define  MG8_8_17PL    0xFFFF
#endif

#if (G8_9PL >= G8_8PL) || (G8_9PL == 0)
#define  MG8_8_19PL    ~(1 << 8)
#else
#define  MG8_8_19PL    0xFFFF
#endif

#if (G8_10PL >= G8_8PL) || (G8_10PL == 0)
#define  MG8_8_110PL    ~(1 << 9)
#else
#define  MG8_8_110PL    0xFFFF
#endif

#if (G8_11PL >= G8_8PL) || (G8_11PL == 0)
#define  MG8_8_111PL    ~(1 << 10)
#else
#define  MG8_8_111PL    0xFFFF
#endif

#if (G8_12PL >= G8_8PL) || (G8_12PL == 0)
#define  MG8_8_112PL    ~(1 << 11)
#else
#define  MG8_8_112PL    0xFFFF
#endif

#if (G8_13PL >= G8_8PL) || (G8_13PL == 0)
#define  MG8_8_113PL    ~(1 << 12)
#else
#define  MG8_8_113PL    0xFFFF
#endif

#if (G8_14PL >= G8_8PL) || (G8_14PL == 0)
#define  MG8_8_114PL    ~(1 << 13)
#else
#define  MG8_8_114PL    0xFFFF
#endif

#if (G8_15PL >= G8_8PL) || (G8_15PL == 0)
#define  MG8_8_115PL    ~(1 << 14)
#else
#define  MG8_8_115PL    0xFFFF
#endif

#if (G8_16PL >= G8_8PL) || (G8_16PL == 0)
#define  MG8_8_116PL    ~(1 << 15)
#else
#define  MG8_8_116PL    0xFFFF
#endif

#define  MG8_8_18PL	0xFF7F
#define  MG8_8    (MG8_8_11PL & MG8_8_12PL & MG8_8_13PL & MG8_8_14PL & \
                    MG8_8_15PL & MG8_8_16PL & MG8_8_17PL & MG8_8_18PL & \
                    MG8_8_19PL & MG8_8_110PL & MG8_8_111PL & MG8_8_112PL & \
                    MG8_8_113PL & MG8_8_114PL & MG8_8_115PL & MG8_8_116PL)
// End of MG8_8:
// Beginning of MG89:
#if (G8_1PL >= G8_9PL) || (G8_1PL == 0)
#define  MG8_9_11PL    ~(1 << 0)
#else
#define  MG8_9_11PL    0xFFFF
#endif

#if (G8_2PL >= G8_9PL) || (G8_2PL == 0)
#define  MG8_9_12PL    ~(1 << 1)
#else
#define  MG8_9_12PL    0xFFFF
#endif

#if (G8_3PL >= G8_9PL) || (G8_3PL == 0)
#define  MG8_9_13PL    ~(1 << 2)
#else
#define  MG8_9_13PL    0xFFFF
#endif

#if (G8_4PL >= G8_9PL) || (G8_4PL == 0)
#define  MG8_9_14PL    ~(1 << 3)
#else
#define  MG8_9_14PL    0xFFFF
#endif

#if (G8_5PL >= G8_9PL) || (G8_5PL == 0)
#define  MG8_9_15PL    ~(1 << 4)
#else
#define  MG8_9_15PL    0xFFFF
#endif

#if (G8_6PL >= G8_9PL) || (G8_6PL == 0)
#define  MG8_9_16PL    ~(1 << 5)
#else
#define  MG8_9_16PL    0xFFFF
#endif

#if (G8_7PL >= G8_9PL) || (G8_7PL == 0)
#define  MG8_9_17PL    ~(1 << 6)
#else
#define  MG8_9_17PL    0xFFFF
#endif

#if (G8_8PL >= G8_9PL) || (G8_8PL == 0)
#define  MG8_9_18PL    ~(1 << 7)
#else
#define  MG8_9_18PL    0xFFFF
#endif

#if (G8_10PL >= G8_9PL) || (G8_10PL == 0)
#define  MG8_9_110PL    ~(1 << 9)
#else
#define  MG8_9_110PL    0xFFFF
#endif

#if (G8_11PL >= G8_9PL) || (G8_11PL == 0)
#define  MG8_9_111PL    ~(1 << 10)
#else
#define  MG8_9_111PL    0xFFFF
#endif

#if (G8_12PL >= G8_9PL) || (G8_12PL == 0)
#define  MG8_9_112PL    ~(1 << 11)
#else
#define  MG8_9_112PL    0xFFFF
#endif

#if (G8_13PL >= G8_9PL) || (G8_13PL == 0)
#define  MG8_9_113PL    ~(1 << 12)
#else
#define  MG8_9_113PL    0xFFFF
#endif

#if (G8_14PL >= G8_9PL) || (G8_14PL == 0)
#define  MG8_9_114PL    ~(1 << 13)
#else
#define  MG8_9_114PL    0xFFFF
#endif

#if (G8_15PL >= G8_9PL) || (G8_15PL == 0)
#define  MG8_9_115PL    ~(1 << 14)
#else
#define  MG8_9_115PL    0xFFFF
#endif

#if (G8_16PL >= G8_9PL) || (G8_16PL == 0)
#define  MG8_9_116PL    ~(1 << 15)
#else
#define  MG8_9_116PL    0xFFFF
#endif

#define  MG8_9_19PL	0xFEFF
#define  MG8_9    (MG8_9_11PL & MG8_9_12PL & MG8_9_13PL & MG8_9_14PL & \
                    MG8_9_15PL & MG8_9_16PL & MG8_9_17PL & MG8_9_18PL & \
                    MG8_9_19PL & MG8_9_110PL & MG8_9_111PL & MG8_9_112PL & \
                    MG8_9_113PL & MG8_9_114PL & MG8_9_115PL & MG8_9_116PL)
// End of MG8_9:
// Beginning of MG810:
#if (G8_1PL >= G8_10PL) || (G8_1PL == 0)
#define  MG8_10_11PL    ~(1 << 0)
#else
#define  MG8_10_11PL    0xFFFF
#endif

#if (G8_2PL >= G8_10PL) || (G8_2PL == 0)
#define  MG8_10_12PL    ~(1 << 1)
#else
#define  MG8_10_12PL    0xFFFF
#endif

#if (G8_3PL >= G8_10PL) || (G8_3PL == 0)
#define  MG8_10_13PL    ~(1 << 2)
#else
#define  MG8_10_13PL    0xFFFF
#endif

#if (G8_4PL >= G8_10PL) || (G8_4PL == 0)
#define  MG8_10_14PL    ~(1 << 3)
#else
#define  MG8_10_14PL    0xFFFF
#endif

#if (G8_5PL >= G8_10PL) || (G8_5PL == 0)
#define  MG8_10_15PL    ~(1 << 4)
#else
#define  MG8_10_15PL    0xFFFF
#endif

#if (G8_6PL >= G8_10PL) || (G8_6PL == 0)
#define  MG8_10_16PL    ~(1 << 5)
#else
#define  MG8_10_16PL    0xFFFF
#endif

#if (G8_7PL >= G8_10PL) || (G8_7PL == 0)
#define  MG8_10_17PL    ~(1 << 6)
#else
#define  MG8_10_17PL    0xFFFF
#endif

#if (G8_8PL >= G8_10PL) || (G8_8PL == 0)
#define  MG8_10_18PL    ~(1 << 7)
#else
#define  MG8_10_18PL    0xFFFF
#endif

#if (G8_9PL >= G8_10PL) || (G8_9PL == 0)
#define  MG8_10_19PL    ~(1 << 8)
#else
#define  MG8_10_19PL    0xFFFF
#endif

#if (G8_11PL >= G8_10PL) || (G8_11PL == 0)
#define  MG8_10_111PL    ~(1 << 10)
#else
#define  MG8_10_111PL    0xFFFF
#endif

#if (G8_12PL >= G8_10PL) || (G8_12PL == 0)
#define  MG8_10_112PL    ~(1 << 11)
#else
#define  MG8_10_112PL    0xFFFF
#endif

#if (G8_13PL >= G8_10PL) || (G8_13PL == 0)
#define  MG8_10_113PL    ~(1 << 12)
#else
#define  MG8_10_113PL    0xFFFF
#endif

#if (G8_14PL >= G8_10PL) || (G8_14PL == 0)
#define  MG8_10_114PL    ~(1 << 13)
#else
#define  MG8_10_114PL    0xFFFF
#endif

#if (G8_15PL >= G8_10PL) || (G8_15PL == 0)
#define  MG8_10_115PL    ~(1 << 14)
#else
#define  MG8_10_115PL    0xFFFF
#endif

#if (G8_16PL >= G8_10PL) || (G8_16PL == 0)
#define  MG8_10_116PL    ~(1 << 15)
#else
#define  MG8_10_116PL    0xFFFF
#endif

#define  MG8_10_110PL	0xFDFF
#define  MG8_10    (MG8_10_11PL & MG8_10_12PL & MG8_10_13PL & MG8_10_14PL & \
                    MG8_10_15PL & MG8_10_16PL & MG8_10_17PL & MG8_10_18PL & \
                    MG8_10_19PL & MG8_10_110PL & MG8_10_111PL & MG8_10_112PL & \
                    MG8_10_113PL & MG8_10_114PL & MG8_10_115PL & MG8_10_116PL)
// End of MG8_10:
// Beginning of MG811:
#if (G8_1PL >= G8_11PL) || (G8_1PL == 0)
#define  MG8_11_11PL    ~(1 << 0)
#else
#define  MG8_11_11PL    0xFFFF
#endif

#if (G8_2PL >= G8_11PL) || (G8_2PL == 0)
#define  MG8_11_12PL    ~(1 << 1)
#else
#define  MG8_11_12PL    0xFFFF
#endif

#if (G8_3PL >= G8_11PL) || (G8_3PL == 0)
#define  MG8_11_13PL    ~(1 << 2)
#else
#define  MG8_11_13PL    0xFFFF
#endif

#if (G8_4PL >= G8_11PL) || (G8_4PL == 0)
#define  MG8_11_14PL    ~(1 << 3)
#else
#define  MG8_11_14PL    0xFFFF
#endif

#if (G8_5PL >= G8_11PL) || (G8_5PL == 0)
#define  MG8_11_15PL    ~(1 << 4)
#else
#define  MG8_11_15PL    0xFFFF
#endif

#if (G8_6PL >= G8_11PL) || (G8_6PL == 0)
#define  MG8_11_16PL    ~(1 << 5)
#else
#define  MG8_11_16PL    0xFFFF
#endif

#if (G8_7PL >= G8_11PL) || (G8_7PL == 0)
#define  MG8_11_17PL    ~(1 << 6)
#else
#define  MG8_11_17PL    0xFFFF
#endif

#if (G8_8PL >= G8_11PL) || (G8_8PL == 0)
#define  MG8_11_18PL    ~(1 << 7)
#else
#define  MG8_11_18PL    0xFFFF
#endif

#if (G8_9PL >= G8_11PL) || (G8_9PL == 0)
#define  MG8_11_19PL    ~(1 << 8)
#else
#define  MG8_11_19PL    0xFFFF
#endif

#if (G8_10PL >= G8_11PL) || (G8_10PL == 0)
#define  MG8_11_110PL    ~(1 << 9)
#else
#define  MG8_11_110PL    0xFFFF
#endif

#if (G8_12PL >= G8_11PL) || (G8_12PL == 0)
#define  MG8_11_112PL    ~(1 << 11)
#else
#define  MG8_11_112PL    0xFFFF
#endif

#if (G8_13PL >= G8_11PL) || (G8_13PL == 0)
#define  MG8_11_113PL    ~(1 << 12)
#else
#define  MG8_11_113PL    0xFFFF
#endif

#if (G8_14PL >= G8_11PL) || (G8_14PL == 0)
#define  MG8_11_114PL    ~(1 << 13)
#else
#define  MG8_11_114PL    0xFFFF
#endif

#if (G8_15PL >= G8_11PL) || (G8_15PL == 0)
#define  MG8_11_115PL    ~(1 << 14)
#else
#define  MG8_11_115PL    0xFFFF
#endif

#if (G8_16PL >= G8_11PL) || (G8_16PL == 0)
#define  MG8_11_116PL    ~(1 << 15)
#else
#define  MG8_11_116PL    0xFFFF
#endif

#define  MG8_11_111PL	0xFBFF
#define  MG8_11    (MG8_11_11PL & MG8_11_12PL & MG8_11_13PL & MG8_11_14PL & \
                    MG8_11_15PL & MG8_11_16PL & MG8_11_17PL & MG8_11_18PL & \
                    MG8_11_19PL & MG8_11_110PL & MG8_11_111PL & MG8_11_112PL & \
                    MG8_11_113PL & MG8_11_114PL & MG8_11_115PL & MG8_11_116PL)
// End of MG8_11:
// Beginning of MG812:
#if (G8_1PL >= G8_12PL) || (G8_1PL == 0)
#define  MG8_12_11PL    ~(1 << 0)
#else
#define  MG8_12_11PL    0xFFFF
#endif

#if (G8_2PL >= G8_12PL) || (G8_2PL == 0)
#define  MG8_12_12PL    ~(1 << 1)
#else
#define  MG8_12_12PL    0xFFFF
#endif

#if (G8_3PL >= G8_12PL) || (G8_3PL == 0)
#define  MG8_12_13PL    ~(1 << 2)
#else
#define  MG8_12_13PL    0xFFFF
#endif

#if (G8_4PL >= G8_12PL) || (G8_4PL == 0)
#define  MG8_12_14PL    ~(1 << 3)
#else
#define  MG8_12_14PL    0xFFFF
#endif

#if (G8_5PL >= G8_12PL) || (G8_5PL == 0)
#define  MG8_12_15PL    ~(1 << 4)
#else
#define  MG8_12_15PL    0xFFFF
#endif

#if (G8_6PL >= G8_12PL) || (G8_6PL == 0)
#define  MG8_12_16PL    ~(1 << 5)
#else
#define  MG8_12_16PL    0xFFFF
#endif

#if (G8_7PL >= G8_12PL) || (G8_7PL == 0)
#define  MG8_12_17PL    ~(1 << 6)
#else
#define  MG8_12_17PL    0xFFFF
#endif

#if (G8_8PL >= G8_12PL) || (G8_8PL == 0)
#define  MG8_12_18PL    ~(1 << 7)
#else
#define  MG8_12_18PL    0xFFFF
#endif

#if (G8_9PL >= G8_12PL) || (G8_9PL == 0)
#define  MG8_12_19PL    ~(1 << 8)
#else
#define  MG8_12_19PL    0xFFFF
#endif

#if (G8_10PL >= G8_12PL) || (G8_10PL == 0)
#define  MG8_12_110PL    ~(1 << 9)
#else
#define  MG8_12_110PL    0xFFFF
#endif

#if (G8_11PL >= G8_12PL) || (G8_11PL == 0)
#define  MG8_12_111PL    ~(1 << 10)
#else
#define  MG8_12_111PL    0xFFFF
#endif

#if (G8_13PL >= G8_12PL) || (G8_13PL == 0)
#define  MG8_12_113PL    ~(1 << 12)
#else
#define  MG8_12_113PL    0xFFFF
#endif

#if (G8_14PL >= G8_12PL) || (G8_14PL == 0)
#define  MG8_12_114PL    ~(1 << 13)
#else
#define  MG8_12_114PL    0xFFFF
#endif

#if (G8_15PL >= G8_12PL) || (G8_15PL == 0)
#define  MG8_12_115PL    ~(1 << 14)
#else
#define  MG8_12_115PL    0xFFFF
#endif

#if (G8_16PL >= G8_12PL) || (G8_16PL == 0)
#define  MG8_12_116PL    ~(1 << 15)
#else
#define  MG8_12_116PL    0xFFFF
#endif

#define  MG8_12_112PL	0xF7FF
#define  MG8_12    (MG8_12_11PL & MG8_12_12PL & MG8_12_13PL & MG8_12_14PL & \
                    MG8_12_15PL & MG8_12_16PL & MG8_12_17PL & MG8_12_18PL & \
                    MG8_12_19PL & MG8_12_110PL & MG8_12_111PL & MG8_12_112PL & \
                    MG8_12_113PL & MG8_12_114PL & MG8_12_115PL & MG8_12_116PL)
// End of MG8_12:
// Beginning of MG813:
#if (G8_1PL >= G8_13PL) || (G8_1PL == 0)
#define  MG8_13_11PL    ~(1 << 0)
#else
#define  MG8_13_11PL    0xFFFF
#endif

#if (G8_2PL >= G8_13PL) || (G8_2PL == 0)
#define  MG8_13_12PL    ~(1 << 1)
#else
#define  MG8_13_12PL    0xFFFF
#endif

#if (G8_3PL >= G8_13PL) || (G8_3PL == 0)
#define  MG8_13_13PL    ~(1 << 2)
#else
#define  MG8_13_13PL    0xFFFF
#endif

#if (G8_4PL >= G8_13PL) || (G8_4PL == 0)
#define  MG8_13_14PL    ~(1 << 3)
#else
#define  MG8_13_14PL    0xFFFF
#endif

#if (G8_5PL >= G8_13PL) || (G8_5PL == 0)
#define  MG8_13_15PL    ~(1 << 4)
#else
#define  MG8_13_15PL    0xFFFF
#endif

#if (G8_6PL >= G8_13PL) || (G8_6PL == 0)
#define  MG8_13_16PL    ~(1 << 5)
#else
#define  MG8_13_16PL    0xFFFF
#endif

#if (G8_7PL >= G8_13PL) || (G8_7PL == 0)
#define  MG8_13_17PL    ~(1 << 6)
#else
#define  MG8_13_17PL    0xFFFF
#endif

#if (G8_8PL >= G8_13PL) || (G8_8PL == 0)
#define  MG8_13_18PL    ~(1 << 7)
#else
#define  MG8_13_18PL    0xFFFF
#endif

#if (G8_9PL >= G8_13PL) || (G8_9PL == 0)
#define  MG8_13_19PL    ~(1 << 8)
#else
#define  MG8_13_19PL    0xFFFF
#endif

#if (G8_10PL >= G8_13PL) || (G8_10PL == 0)
#define  MG8_13_110PL    ~(1 << 9)
#else
#define  MG8_13_110PL    0xFFFF
#endif

#if (G8_11PL >= G8_13PL) || (G8_11PL == 0)
#define  MG8_13_111PL    ~(1 << 10)
#else
#define  MG8_13_111PL    0xFFFF
#endif

#if (G8_12PL >= G8_13PL) || (G8_12PL == 0)
#define  MG8_13_112PL    ~(1 << 11)
#else
#define  MG8_13_112PL    0xFFFF
#endif

#if (G8_14PL >= G8_13PL) || (G8_14PL == 0)
#define  MG8_13_114PL    ~(1 << 13)
#else
#define  MG8_13_114PL    0xFFFF
#endif

#if (G8_15PL >= G8_13PL) || (G8_15PL == 0)
#define  MG8_13_115PL    ~(1 << 14)
#else
#define  MG8_13_115PL    0xFFFF
#endif

#if (G8_16PL >= G8_13PL) || (G8_16PL == 0)
#define  MG8_13_116PL    ~(1 << 15)
#else
#define  MG8_13_116PL    0xFFFF
#endif

#define  MG8_13_113PL	0xEFFF
#define  MG8_13    (MG8_13_11PL & MG8_13_12PL & MG8_13_13PL & MG8_13_14PL & \
                    MG8_13_15PL & MG8_13_16PL & MG8_13_17PL & MG8_13_18PL & \
                    MG8_13_19PL & MG8_13_110PL & MG8_13_111PL & MG8_13_112PL & \
                    MG8_13_113PL & MG8_13_114PL & MG8_13_115PL & MG8_13_116PL)
// End of MG8_13:
// Beginning of MG814:
#if (G8_1PL >= G8_14PL) || (G8_1PL == 0)
#define  MG8_14_11PL    ~(1 << 0)
#else
#define  MG8_14_11PL    0xFFFF
#endif

#if (G8_2PL >= G8_14PL) || (G8_2PL == 0)
#define  MG8_14_12PL    ~(1 << 1)
#else
#define  MG8_14_12PL    0xFFFF
#endif

#if (G8_3PL >= G8_14PL) || (G8_3PL == 0)
#define  MG8_14_13PL    ~(1 << 2)
#else
#define  MG8_14_13PL    0xFFFF
#endif

#if (G8_4PL >= G8_14PL) || (G8_4PL == 0)
#define  MG8_14_14PL    ~(1 << 3)
#else
#define  MG8_14_14PL    0xFFFF
#endif

#if (G8_5PL >= G8_14PL) || (G8_5PL == 0)
#define  MG8_14_15PL    ~(1 << 4)
#else
#define  MG8_14_15PL    0xFFFF
#endif

#if (G8_6PL >= G8_14PL) || (G8_6PL == 0)
#define  MG8_14_16PL    ~(1 << 5)
#else
#define  MG8_14_16PL    0xFFFF
#endif

#if (G8_7PL >= G8_14PL) || (G8_7PL == 0)
#define  MG8_14_17PL    ~(1 << 6)
#else
#define  MG8_14_17PL    0xFFFF
#endif

#if (G8_8PL >= G8_14PL) || (G8_8PL == 0)
#define  MG8_14_18PL    ~(1 << 7)
#else
#define  MG8_14_18PL    0xFFFF
#endif

#if (G8_9PL >= G8_14PL) || (G8_9PL == 0)
#define  MG8_14_19PL    ~(1 << 8)
#else
#define  MG8_14_19PL    0xFFFF
#endif

#if (G8_10PL >= G8_14PL) || (G8_10PL == 0)
#define  MG8_14_110PL    ~(1 << 9)
#else
#define  MG8_14_110PL    0xFFFF
#endif

#if (G8_11PL >= G8_14PL) || (G8_11PL == 0)
#define  MG8_14_111PL    ~(1 << 10)
#else
#define  MG8_14_111PL    0xFFFF
#endif

#if (G8_12PL >= G8_14PL) || (G8_12PL == 0)
#define  MG8_14_112PL    ~(1 << 11)
#else
#define  MG8_14_112PL    0xFFFF
#endif

#if (G8_13PL >= G8_14PL) || (G8_13PL == 0)
#define  MG8_14_113PL    ~(1 << 12)
#else
#define  MG8_14_113PL    0xFFFF
#endif

#if (G8_15PL >= G8_14PL) || (G8_15PL == 0)
#define  MG8_14_115PL    ~(1 << 14)
#else
#define  MG8_14_115PL    0xFFFF
#endif

#if (G8_16PL >= G8_14PL) || (G8_16PL == 0)
#define  MG8_14_116PL    ~(1 << 15)
#else
#define  MG8_14_116PL    0xFFFF
#endif

#define  MG8_14_114PL	0xDFFF
#define  MG8_14    (MG8_14_11PL & MG8_14_12PL & MG8_14_13PL & MG8_14_14PL & \
                    MG8_14_15PL & MG8_14_16PL & MG8_14_17PL & MG8_14_18PL & \
                    MG8_14_19PL & MG8_14_110PL & MG8_14_111PL & MG8_14_112PL & \
                    MG8_14_113PL & MG8_14_114PL & MG8_14_115PL & MG8_14_116PL)
// End of MG8_14:
// Beginning of MG815:
#if (G8_1PL >= G8_15PL) || (G8_1PL == 0)
#define  MG8_15_11PL    ~(1 << 0)
#else
#define  MG8_15_11PL    0xFFFF
#endif

#if (G8_2PL >= G8_15PL) || (G8_2PL == 0)
#define  MG8_15_12PL    ~(1 << 1)
#else
#define  MG8_15_12PL    0xFFFF
#endif

#if (G8_3PL >= G8_15PL) || (G8_3PL == 0)
#define  MG8_15_13PL    ~(1 << 2)
#else
#define  MG8_15_13PL    0xFFFF
#endif

#if (G8_4PL >= G8_15PL) || (G8_4PL == 0)
#define  MG8_15_14PL    ~(1 << 3)
#else
#define  MG8_15_14PL    0xFFFF
#endif

#if (G8_5PL >= G8_15PL) || (G8_5PL == 0)
#define  MG8_15_15PL    ~(1 << 4)
#else
#define  MG8_15_15PL    0xFFFF
#endif

#if (G8_6PL >= G8_15PL) || (G8_6PL == 0)
#define  MG8_15_16PL    ~(1 << 5)
#else
#define  MG8_15_16PL    0xFFFF
#endif

#if (G8_7PL >= G8_15PL) || (G8_7PL == 0)
#define  MG8_15_17PL    ~(1 << 6)
#else
#define  MG8_15_17PL    0xFFFF
#endif

#if (G8_8PL >= G8_15PL) || (G8_8PL == 0)
#define  MG8_15_18PL    ~(1 << 7)
#else
#define  MG8_15_18PL    0xFFFF
#endif

#if (G8_9PL >= G8_15PL) || (G8_9PL == 0)
#define  MG8_15_19PL    ~(1 << 8)
#else
#define  MG8_15_19PL    0xFFFF
#endif

#if (G8_10PL >= G8_15PL) || (G8_10PL == 0)
#define  MG8_15_110PL    ~(1 << 9)
#else
#define  MG8_15_110PL    0xFFFF
#endif

#if (G8_11PL >= G8_15PL) || (G8_11PL == 0)
#define  MG8_15_111PL    ~(1 << 10)
#else
#define  MG8_15_111PL    0xFFFF
#endif

#if (G8_12PL >= G8_15PL) || (G8_12PL == 0)
#define  MG8_15_112PL    ~(1 << 11)
#else
#define  MG8_15_112PL    0xFFFF
#endif

#if (G8_13PL >= G8_15PL) || (G8_13PL == 0)
#define  MG8_15_113PL    ~(1 << 12)
#else
#define  MG8_15_113PL    0xFFFF
#endif

#if (G8_14PL >= G8_15PL) || (G8_14PL == 0)
#define  MG8_15_114PL    ~(1 << 13)
#else
#define  MG8_15_114PL    0xFFFF
#endif

#if (G8_16PL >= G8_15PL) || (G8_16PL == 0)
#define  MG8_15_116PL    ~(1 << 15)
#else
#define  MG8_15_116PL    0xFFFF
#endif

#define  MG8_15_115PL	0xBFFF
#define  MG8_15    (MG8_15_11PL & MG8_15_12PL & MG8_15_13PL & MG8_15_14PL & \
                    MG8_15_15PL & MG8_15_16PL & MG8_15_17PL & MG8_15_18PL & \
                    MG8_15_19PL & MG8_15_110PL & MG8_15_111PL & MG8_15_112PL & \
                    MG8_15_113PL & MG8_15_114PL & MG8_15_115PL & MG8_15_116PL)
// End of MG8_15:
// Beginning of MG816:
#if (G8_1PL >= G8_16PL) || (G8_1PL == 0)
#define  MG8_16_11PL    ~(1 << 0)
#else
#define  MG8_16_11PL    0xFFFF
#endif

#if (G8_2PL >= G8_16PL) || (G8_2PL == 0)
#define  MG8_16_12PL    ~(1 << 1)
#else
#define  MG8_16_12PL    0xFFFF
#endif

#if (G8_3PL >= G8_16PL) || (G8_3PL == 0)
#define  MG8_16_13PL    ~(1 << 2)
#else
#define  MG8_16_13PL    0xFFFF
#endif

#if (G8_4PL >= G8_16PL) || (G8_4PL == 0)
#define  MG8_16_14PL    ~(1 << 3)
#else
#define  MG8_16_14PL    0xFFFF
#endif

#if (G8_5PL >= G8_16PL) || (G8_5PL == 0)
#define  MG8_16_15PL    ~(1 << 4)
#else
#define  MG8_16_15PL    0xFFFF
#endif

#if (G8_6PL >= G8_16PL) || (G8_6PL == 0)
#define  MG8_16_16PL    ~(1 << 5)
#else
#define  MG8_16_16PL    0xFFFF
#endif

#if (G8_7PL >= G8_16PL) || (G8_7PL == 0)
#define  MG8_16_17PL    ~(1 << 6)
#else
#define  MG8_16_17PL    0xFFFF
#endif

#if (G8_8PL >= G8_16PL) || (G8_8PL == 0)
#define  MG8_16_18PL    ~(1 << 7)
#else
#define  MG8_16_18PL    0xFFFF
#endif

#if (G8_9PL >= G8_16PL) || (G8_9PL == 0)
#define  MG8_16_19PL    ~(1 << 8)
#else
#define  MG8_16_19PL    0xFFFF
#endif

#if (G8_10PL >= G8_16PL) || (G8_10PL == 0)
#define  MG8_16_110PL    ~(1 << 9)
#else
#define  MG8_16_110PL    0xFFFF
#endif

#if (G8_11PL >= G8_16PL) || (G8_11PL == 0)
#define  MG8_16_111PL    ~(1 << 10)
#else
#define  MG8_16_111PL    0xFFFF
#endif

#if (G8_12PL >= G8_16PL) || (G8_12PL == 0)
#define  MG8_16_112PL    ~(1 << 11)
#else
#define  MG8_16_112PL    0xFFFF
#endif

#if (G8_13PL >= G8_16PL) || (G8_13PL == 0)
#define  MG8_16_113PL    ~(1 << 12)
#else
#define  MG8_16_113PL    0xFFFF
#endif

#if (G8_14PL >= G8_16PL) || (G8_14PL == 0)
#define  MG8_16_114PL    ~(1 << 13)
#else
#define  MG8_16_114PL    0xFFFF
#endif

#if (G8_15PL >= G8_16PL) || (G8_15PL == 0)
#define  MG8_16_115PL    ~(1 << 14)
#else
#define  MG8_16_115PL    0xFFFF
#endif

#define  MG8_16_116PL	0x7FFF
#define  MG8_16    (MG8_16_11PL & MG8_16_12PL & MG8_16_13PL & MG8_16_14PL & \
                    MG8_16_15PL & MG8_16_16PL & MG8_16_17PL & MG8_16_18PL & \
                    MG8_16_19PL & MG8_16_110PL & MG8_16_111PL & MG8_16_112PL & \
                    MG8_16_113PL & MG8_16_114PL & MG8_16_115PL & MG8_16_116PL)
// End of MG8_16:


//-------------------------------------------------------------------------------
// Automatically generate PIEIER9 interrupt masks MG91 to MG916:

// Beginning of MG91:
#if (G9_2PL >= G9_1PL) || (G9_2PL == 0)
#define  MG9_1_12PL    ~(1 << 1)
#else
#define  MG9_1_12PL    0xFFFF
#endif

#if (G9_3PL >= G9_1PL) || (G9_3PL == 0)
#define  MG9_1_13PL    ~(1 << 2)
#else
#define  MG9_1_13PL    0xFFFF
#endif

#if (G9_4PL >= G9_1PL) || (G9_4PL == 0)
#define  MG9_1_14PL    ~(1 << 3)
#else
#define  MG9_1_14PL    0xFFFF
#endif

#if (G9_5PL >= G9_1PL) || (G9_5PL == 0)
#define  MG9_1_15PL    ~(1 << 4)
#else
#define  MG9_1_15PL    0xFFFF
#endif

#if (G9_6PL >= G9_1PL) || (G9_6PL == 0)
#define  MG9_1_16PL    ~(1 << 5)
#else
#define  MG9_1_16PL    0xFFFF
#endif

#if (G9_7PL >= G9_1PL) || (G9_7PL == 0)
#define  MG9_1_17PL    ~(1 << 6)
#else
#define  MG9_1_17PL    0xFFFF
#endif

#if (G9_8PL >= G9_1PL) || (G9_8PL == 0)
#define  MG9_1_18PL    ~(1 << 7)
#else
#define  MG9_1_18PL    0xFFFF
#endif

#if (G9_9PL >= G9_1PL) || (G9_9PL == 0)
#define  MG9_1_19PL    ~(1 << 8)
#else
#define  MG9_1_19PL    0xFFFF
#endif

#if (G9_10PL >= G9_1PL) || (G9_10PL == 0)
#define  MG9_1_110PL    ~(1 << 9)
#else
#define  MG9_1_110PL    0xFFFF
#endif

#if (G9_11PL >= G9_1PL) || (G9_11PL == 0)
#define  MG9_1_111PL    ~(1 << 10)
#else
#define  MG9_1_111PL    0xFFFF
#endif

#if (G9_12PL >= G9_1PL) || (G9_12PL == 0)
#define  MG9_1_112PL    ~(1 << 11)
#else
#define  MG9_1_112PL    0xFFFF
#endif

#if (G9_13PL >= G9_1PL) || (G9_13PL == 0)
#define  MG9_1_113PL    ~(1 << 12)
#else
#define  MG9_1_113PL    0xFFFF
#endif

#if (G9_14PL >= G9_1PL) || (G9_14PL == 0)
#define  MG9_1_114PL    ~(1 << 13)
#else
#define  MG9_1_114PL    0xFFFF
#endif

#if (G9_15PL >= G9_1PL) || (G9_15PL == 0)
#define  MG9_1_115PL    ~(1 << 14)
#else
#define  MG9_1_115PL    0xFFFF
#endif

#if (G9_16PL >= G9_1PL) || (G9_16PL == 0)
#define  MG9_1_116PL    ~(1 << 15)
#else
#define  MG9_1_116PL    0xFFFF
#endif

#define  MG9_1_11PL	0xFFFE
#define  MG9_1    (MG9_1_11PL & MG9_1_12PL & MG9_1_13PL & MG9_1_14PL & \
                    MG9_1_15PL & MG9_1_16PL & MG9_1_17PL & MG9_1_18PL & \
                    MG9_1_19PL & MG9_1_110PL & MG9_1_111PL & MG9_1_112PL & \
                    MG9_1_113PL & MG9_1_114PL & MG9_1_115PL & MG9_1_116PL)
// End of MG9_1:
// Beginning of MG92:
#if (G9_1PL >= G9_2PL) || (G9_1PL == 0)
#define  MG9_2_11PL    ~(1 << 0)
#else
#define  MG9_2_11PL    0xFFFF
#endif

#if (G9_3PL >= G9_2PL) || (G9_3PL == 0)
#define  MG9_2_13PL    ~(1 << 2)
#else
#define  MG9_2_13PL    0xFFFF
#endif

#if (G9_4PL >= G9_2PL) || (G9_4PL == 0)
#define  MG9_2_14PL    ~(1 << 3)
#else
#define  MG9_2_14PL    0xFFFF
#endif

#if (G9_5PL >= G9_2PL) || (G9_5PL == 0)
#define  MG9_2_15PL    ~(1 << 4)
#else
#define  MG9_2_15PL    0xFFFF
#endif

#if (G9_6PL >= G9_2PL) || (G9_6PL == 0)
#define  MG9_2_16PL    ~(1 << 5)
#else
#define  MG9_2_16PL    0xFFFF
#endif

#if (G9_7PL >= G9_2PL) || (G9_7PL == 0)
#define  MG9_2_17PL    ~(1 << 6)
#else
#define  MG9_2_17PL    0xFFFF
#endif

#if (G9_8PL >= G9_2PL) || (G9_8PL == 0)
#define  MG9_2_18PL    ~(1 << 7)
#else
#define  MG9_2_18PL    0xFFFF
#endif

#if (G9_9PL >= G9_2PL) || (G9_9PL == 0)
#define  MG9_2_19PL    ~(1 << 8)
#else
#define  MG9_2_19PL    0xFFFF
#endif

#if (G9_10PL >= G9_2PL) || (G9_10PL == 0)
#define  MG9_2_110PL    ~(1 << 9)
#else
#define  MG9_2_110PL    0xFFFF
#endif

#if (G9_11PL >= G9_2PL) || (G9_11PL == 0)
#define  MG9_2_111PL    ~(1 << 10)
#else
#define  MG9_2_111PL    0xFFFF
#endif

#if (G9_12PL >= G9_2PL) || (G9_12PL == 0)
#define  MG9_2_112PL    ~(1 << 11)
#else
#define  MG9_2_112PL    0xFFFF
#endif

#if (G9_13PL >= G9_2PL) || (G9_13PL == 0)
#define  MG9_2_113PL    ~(1 << 12)
#else
#define  MG9_2_113PL    0xFFFF
#endif

#if (G9_14PL >= G9_2PL) || (G9_14PL == 0)
#define  MG9_2_114PL    ~(1 << 13)
#else
#define  MG9_2_114PL    0xFFFF
#endif

#if (G9_15PL >= G9_2PL) || (G9_15PL == 0)
#define  MG9_2_115PL    ~(1 << 14)
#else
#define  MG9_2_115PL    0xFFFF
#endif

#if (G9_16PL >= G9_2PL) || (G9_16PL == 0)
#define  MG9_2_116PL    ~(1 << 15)
#else
#define  MG9_2_116PL    0xFFFF
#endif

#define  MG9_2_12PL	0xFFFD
#define  MG9_2    (MG9_2_11PL & MG9_2_12PL & MG9_2_13PL & MG9_2_14PL & \
                    MG9_2_15PL & MG9_2_16PL & MG9_2_17PL & MG9_2_18PL & \
                    MG9_2_19PL & MG9_2_110PL & MG9_2_111PL & MG9_2_112PL & \
                    MG9_2_113PL & MG9_2_114PL & MG9_2_115PL & MG9_2_116PL)
// End of MG9_2:
// Beginning of MG93:
#if (G9_1PL >= G9_3PL) || (G9_1PL == 0)
#define  MG9_3_11PL    ~(1 << 0)
#else
#define  MG9_3_11PL    0xFFFF
#endif

#if (G9_2PL >= G9_3PL) || (G9_2PL == 0)
#define  MG9_3_12PL    ~(1 << 1)
#else
#define  MG9_3_12PL    0xFFFF
#endif

#if (G9_4PL >= G9_3PL) || (G9_4PL == 0)
#define  MG9_3_14PL    ~(1 << 3)
#else
#define  MG9_3_14PL    0xFFFF
#endif

#if (G9_5PL >= G9_3PL) || (G9_5PL == 0)
#define  MG9_3_15PL    ~(1 << 4)
#else
#define  MG9_3_15PL    0xFFFF
#endif

#if (G9_6PL >= G9_3PL) || (G9_6PL == 0)
#define  MG9_3_16PL    ~(1 << 5)
#else
#define  MG9_3_16PL    0xFFFF
#endif

#if (G9_7PL >= G9_3PL) || (G9_7PL == 0)
#define  MG9_3_17PL    ~(1 << 6)
#else
#define  MG9_3_17PL    0xFFFF
#endif

#if (G9_8PL >= G9_3PL) || (G9_8PL == 0)
#define  MG9_3_18PL    ~(1 << 7)
#else
#define  MG9_3_18PL    0xFFFF
#endif

#if (G9_9PL >= G9_3PL) || (G9_9PL == 0)
#define  MG9_3_19PL    ~(1 << 8)
#else
#define  MG9_3_19PL    0xFFFF
#endif

#if (G9_10PL >= G9_3PL) || (G9_10PL == 0)
#define  MG9_3_110PL    ~(1 << 9)
#else
#define  MG9_3_110PL    0xFFFF
#endif

#if (G9_11PL >= G9_3PL) || (G9_11PL == 0)
#define  MG9_3_111PL    ~(1 << 10)
#else
#define  MG9_3_111PL    0xFFFF
#endif

#if (G9_12PL >= G9_3PL) || (G9_12PL == 0)
#define  MG9_3_112PL    ~(1 << 11)
#else
#define  MG9_3_112PL    0xFFFF
#endif

#if (G9_13PL >= G9_3PL) || (G9_13PL == 0)
#define  MG9_3_113PL    ~(1 << 12)
#else
#define  MG9_3_113PL    0xFFFF
#endif

#if (G9_14PL >= G9_3PL) || (G9_14PL == 0)
#define  MG9_3_114PL    ~(1 << 13)
#else
#define  MG9_3_114PL    0xFFFF
#endif

#if (G9_15PL >= G9_3PL) || (G9_15PL == 0)
#define  MG9_3_115PL    ~(1 << 14)
#else
#define  MG9_3_115PL    0xFFFF
#endif

#if (G9_16PL >= G9_3PL) || (G9_16PL == 0)
#define  MG9_3_116PL    ~(1 << 15)
#else
#define  MG9_3_116PL    0xFFFF
#endif

#define  MG9_3_13PL	0xFFFB
#define  MG9_3    (MG9_3_11PL & MG9_3_12PL & MG9_3_13PL & MG9_3_14PL & \
                    MG9_3_15PL & MG9_3_16PL & MG9_3_17PL & MG9_3_18PL & \
                    MG9_3_19PL & MG9_3_110PL & MG9_3_111PL & MG9_3_112PL & \
                    MG9_3_113PL & MG9_3_114PL & MG9_3_115PL & MG9_3_116PL)
// End of MG9_3:
// Beginning of MG94:
#if (G9_1PL >= G9_4PL) || (G9_1PL == 0)
#define  MG9_4_11PL    ~(1 << 0)
#else
#define  MG9_4_11PL    0xFFFF
#endif

#if (G9_2PL >= G9_4PL) || (G9_2PL == 0)
#define  MG9_4_12PL    ~(1 << 1)
#else
#define  MG9_4_12PL    0xFFFF
#endif

#if (G9_3PL >= G9_4PL) || (G9_3PL == 0)
#define  MG9_4_13PL    ~(1 << 2)
#else
#define  MG9_4_13PL    0xFFFF
#endif

#if (G9_5PL >= G9_4PL) || (G9_5PL == 0)
#define  MG9_4_15PL    ~(1 << 4)
#else
#define  MG9_4_15PL    0xFFFF
#endif

#if (G9_6PL >= G9_4PL) || (G9_6PL == 0)
#define  MG9_4_16PL    ~(1 << 5)
#else
#define  MG9_4_16PL    0xFFFF
#endif

#if (G9_7PL >= G9_4PL) || (G9_7PL == 0)
#define  MG9_4_17PL    ~(1 << 6)
#else
#define  MG9_4_17PL    0xFFFF
#endif

#if (G9_8PL >= G9_4PL) || (G9_8PL == 0)
#define  MG9_4_18PL    ~(1 << 7)
#else
#define  MG9_4_18PL    0xFFFF
#endif

#if (G9_9PL >= G9_4PL) || (G9_9PL == 0)
#define  MG9_4_19PL    ~(1 << 8)
#else
#define  MG9_4_19PL    0xFFFF
#endif

#if (G9_10PL >= G9_4PL) || (G9_10PL == 0)
#define  MG9_4_110PL    ~(1 << 9)
#else
#define  MG9_4_110PL    0xFFFF
#endif

#if (G9_11PL >= G9_4PL) || (G9_11PL == 0)
#define  MG9_4_111PL    ~(1 << 10)
#else
#define  MG9_4_111PL    0xFFFF
#endif

#if (G9_12PL >= G9_4PL) || (G9_12PL == 0)
#define  MG9_4_112PL    ~(1 << 11)
#else
#define  MG9_4_112PL    0xFFFF
#endif

#if (G9_13PL >= G9_4PL) || (G9_13PL == 0)
#define  MG9_4_113PL    ~(1 << 12)
#else
#define  MG9_4_113PL    0xFFFF
#endif

#if (G9_14PL >= G9_4PL) || (G9_14PL == 0)
#define  MG9_4_114PL    ~(1 << 13)
#else
#define  MG9_4_114PL    0xFFFF
#endif

#if (G9_15PL >= G9_4PL) || (G9_15PL == 0)
#define  MG9_4_115PL    ~(1 << 14)
#else
#define  MG9_4_115PL    0xFFFF
#endif

#if (G9_16PL >= G9_4PL) || (G9_16PL == 0)
#define  MG9_4_116PL    ~(1 << 15)
#else
#define  MG9_4_116PL    0xFFFF
#endif

#define  MG9_4_14PL	0xFFF7
#define  MG9_4    (MG9_4_11PL & MG9_4_12PL & MG9_4_13PL & MG9_4_14PL & \
                    MG9_4_15PL & MG9_4_16PL & MG9_4_17PL & MG9_4_18PL & \
                    MG9_4_19PL & MG9_4_110PL & MG9_4_111PL & MG9_4_112PL & \
                    MG9_4_113PL & MG9_4_114PL & MG9_4_115PL & MG9_4_116PL)
// End of MG9_4:
// Beginning of MG95:
#if (G9_1PL >= G9_5PL) || (G9_1PL == 0)
#define  MG9_5_11PL    ~(1 << 0)
#else
#define  MG9_5_11PL    0xFFFF
#endif

#if (G9_2PL >= G9_5PL) || (G9_2PL == 0)
#define  MG9_5_12PL    ~(1 << 1)
#else
#define  MG9_5_12PL    0xFFFF
#endif

#if (G9_3PL >= G9_5PL) || (G9_3PL == 0)
#define  MG9_5_13PL    ~(1 << 2)
#else
#define  MG9_5_13PL    0xFFFF
#endif

#if (G9_4PL >= G9_5PL) || (G9_4PL == 0)
#define  MG9_5_14PL    ~(1 << 3)
#else
#define  MG9_5_14PL    0xFFFF
#endif

#if (G9_6PL >= G9_5PL) || (G9_6PL == 0)
#define  MG9_5_16PL    ~(1 << 5)
#else
#define  MG9_5_16PL    0xFFFF
#endif

#if (G9_7PL >= G9_5PL) || (G9_7PL == 0)
#define  MG9_5_17PL    ~(1 << 6)
#else
#define  MG9_5_17PL    0xFFFF
#endif

#if (G9_8PL >= G9_5PL) || (G9_8PL == 0)
#define  MG9_5_18PL    ~(1 << 7)
#else
#define  MG9_5_18PL    0xFFFF
#endif

#if (G9_9PL >= G9_5PL) || (G9_9PL == 0)
#define  MG9_5_19PL    ~(1 << 8)
#else
#define  MG9_5_19PL    0xFFFF
#endif

#if (G9_10PL >= G9_5PL) || (G9_10PL == 0)
#define  MG9_5_110PL    ~(1 << 9)
#else
#define  MG9_5_110PL    0xFFFF
#endif

#if (G9_11PL >= G9_5PL) || (G9_11PL == 0)
#define  MG9_5_111PL    ~(1 << 10)
#else
#define  MG9_5_111PL    0xFFFF
#endif

#if (G9_12PL >= G9_5PL) || (G9_12PL == 0)
#define  MG9_5_112PL    ~(1 << 11)
#else
#define  MG9_5_112PL    0xFFFF
#endif

#if (G9_13PL >= G9_5PL) || (G9_13PL == 0)
#define  MG9_5_113PL    ~(1 << 12)
#else
#define  MG9_5_113PL    0xFFFF
#endif

#if (G9_14PL >= G9_5PL) || (G9_14PL == 0)
#define  MG9_5_114PL    ~(1 << 13)
#else
#define  MG9_5_114PL    0xFFFF
#endif

#if (G9_15PL >= G9_5PL) || (G9_15PL == 0)
#define  MG9_5_115PL    ~(1 << 14)
#else
#define  MG9_5_115PL    0xFFFF
#endif

#if (G9_16PL >= G9_5PL) || (G9_16PL == 0)
#define  MG9_5_116PL    ~(1 << 15)
#else
#define  MG9_5_116PL    0xFFFF
#endif

#define  MG9_5_15PL	0xFFEF
#define  MG9_5    (MG9_5_11PL & MG9_5_12PL & MG9_5_13PL & MG9_5_14PL & \
                    MG9_5_15PL & MG9_5_16PL & MG9_5_17PL & MG9_5_18PL & \
                    MG9_5_19PL & MG9_5_110PL & MG9_5_111PL & MG9_5_112PL & \
                    MG9_5_113PL & MG9_5_114PL & MG9_5_115PL & MG9_5_116PL)
// End of MG9_5:
// Beginning of MG96:
#if (G9_1PL >= G9_6PL) || (G9_1PL == 0)
#define  MG9_6_11PL    ~(1 << 0)
#else
#define  MG9_6_11PL    0xFFFF
#endif

#if (G9_2PL >= G9_6PL) || (G9_2PL == 0)
#define  MG9_6_12PL    ~(1 << 1)
#else
#define  MG9_6_12PL    0xFFFF
#endif

#if (G9_3PL >= G9_6PL) || (G9_3PL == 0)
#define  MG9_6_13PL    ~(1 << 2)
#else
#define  MG9_6_13PL    0xFFFF
#endif

#if (G9_4PL >= G9_6PL) || (G9_4PL == 0)
#define  MG9_6_14PL    ~(1 << 3)
#else
#define  MG9_6_14PL    0xFFFF
#endif

#if (G9_5PL >= G9_6PL) || (G9_5PL == 0)
#define  MG9_6_15PL    ~(1 << 4)
#else
#define  MG9_6_15PL    0xFFFF
#endif

#if (G9_7PL >= G9_6PL) || (G9_7PL == 0)
#define  MG9_6_17PL    ~(1 << 6)
#else
#define  MG9_6_17PL    0xFFFF
#endif

#if (G9_8PL >= G9_6PL) || (G9_8PL == 0)
#define  MG9_6_18PL    ~(1 << 7)
#else
#define  MG9_6_18PL    0xFFFF
#endif

#if (G9_9PL >= G9_6PL) || (G9_9PL == 0)
#define  MG9_6_19PL    ~(1 << 8)
#else
#define  MG9_6_19PL    0xFFFF
#endif

#if (G9_10PL >= G9_6PL) || (G9_10PL == 0)
#define  MG9_6_110PL    ~(1 << 9)
#else
#define  MG9_6_110PL    0xFFFF
#endif

#if (G9_11PL >= G9_6PL) || (G9_11PL == 0)
#define  MG9_6_111PL    ~(1 << 10)
#else
#define  MG9_6_111PL    0xFFFF
#endif

#if (G9_12PL >= G9_6PL) || (G9_12PL == 0)
#define  MG9_6_112PL    ~(1 << 11)
#else
#define  MG9_6_112PL    0xFFFF
#endif

#if (G9_13PL >= G9_6PL) || (G9_13PL == 0)
#define  MG9_6_113PL    ~(1 << 12)
#else
#define  MG9_6_113PL    0xFFFF
#endif

#if (G9_14PL >= G9_6PL) || (G9_14PL == 0)
#define  MG9_6_114PL    ~(1 << 13)
#else
#define  MG9_6_114PL    0xFFFF
#endif

#if (G9_15PL >= G9_6PL) || (G9_15PL == 0)
#define  MG9_6_115PL    ~(1 << 14)
#else
#define  MG9_6_115PL    0xFFFF
#endif

#if (G9_16PL >= G9_6PL) || (G9_16PL == 0)
#define  MG9_6_116PL    ~(1 << 15)
#else
#define  MG9_6_116PL    0xFFFF
#endif

#define  MG9_6_16PL	0xFFDF
#define  MG9_6    (MG9_6_11PL & MG9_6_12PL & MG9_6_13PL & MG9_6_14PL & \
                    MG9_6_15PL & MG9_6_16PL & MG9_6_17PL & MG9_6_18PL & \
                    MG9_6_19PL & MG9_6_110PL & MG9_6_111PL & MG9_6_112PL & \
                    MG9_6_113PL & MG9_6_114PL & MG9_6_115PL & MG9_6_116PL)
// End of MG9_6:
// Beginning of MG97:
#if (G9_1PL >= G9_7PL) || (G9_1PL == 0)
#define  MG9_7_11PL    ~(1 << 0)
#else
#define  MG9_7_11PL    0xFFFF
#endif

#if (G9_2PL >= G9_7PL) || (G9_2PL == 0)
#define  MG9_7_12PL    ~(1 << 1)
#else
#define  MG9_7_12PL    0xFFFF
#endif

#if (G9_3PL >= G9_7PL) || (G9_3PL == 0)
#define  MG9_7_13PL    ~(1 << 2)
#else
#define  MG9_7_13PL    0xFFFF
#endif

#if (G9_4PL >= G9_7PL) || (G9_4PL == 0)
#define  MG9_7_14PL    ~(1 << 3)
#else
#define  MG9_7_14PL    0xFFFF
#endif

#if (G9_5PL >= G9_7PL) || (G9_5PL == 0)
#define  MG9_7_15PL    ~(1 << 4)
#else
#define  MG9_7_15PL    0xFFFF
#endif

#if (G9_6PL >= G9_7PL) || (G9_6PL == 0)
#define  MG9_7_16PL    ~(1 << 5)
#else
#define  MG9_7_16PL    0xFFFF
#endif

#if (G9_8PL >= G9_7PL) || (G9_8PL == 0)
#define  MG9_7_18PL    ~(1 << 7)
#else
#define  MG9_7_18PL    0xFFFF
#endif

#if (G9_9PL >= G9_7PL) || (G9_9PL == 0)
#define  MG9_7_19PL    ~(1 << 8)
#else
#define  MG9_7_19PL    0xFFFF
#endif

#if (G9_10PL >= G9_7PL) || (G9_10PL == 0)
#define  MG9_7_110PL    ~(1 << 9)
#else
#define  MG9_7_110PL    0xFFFF
#endif

#if (G9_11PL >= G9_7PL) || (G9_11PL == 0)
#define  MG9_7_111PL    ~(1 << 10)
#else
#define  MG9_7_111PL    0xFFFF
#endif

#if (G9_12PL >= G9_7PL) || (G9_12PL == 0)
#define  MG9_7_112PL    ~(1 << 11)
#else
#define  MG9_7_112PL    0xFFFF
#endif

#if (G9_13PL >= G9_7PL) || (G9_13PL == 0)
#define  MG9_7_113PL    ~(1 << 12)
#else
#define  MG9_7_113PL    0xFFFF
#endif

#if (G9_14PL >= G9_7PL) || (G9_14PL == 0)
#define  MG9_7_114PL    ~(1 << 13)
#else
#define  MG9_7_114PL    0xFFFF
#endif

#if (G9_15PL >= G9_7PL) || (G9_15PL == 0)
#define  MG9_7_115PL    ~(1 << 14)
#else
#define  MG9_7_115PL    0xFFFF
#endif

#if (G9_16PL >= G9_7PL) || (G9_16PL == 0)
#define  MG9_7_116PL    ~(1 << 15)
#else
#define  MG9_7_116PL    0xFFFF
#endif

#define  MG9_7_17PL	0xFFBF
#define  MG9_7    (MG9_7_11PL & MG9_7_12PL & MG9_7_13PL & MG9_7_14PL & \
                    MG9_7_15PL & MG9_7_16PL & MG9_7_17PL & MG9_7_18PL & \
                    MG9_7_19PL & MG9_7_110PL & MG9_7_111PL & MG9_7_112PL & \
                    MG9_7_113PL & MG9_7_114PL & MG9_7_115PL & MG9_7_116PL)
// End of MG9_7:
// Beginning of MG98:
#if (G9_1PL >= G9_8PL) || (G9_1PL == 0)
#define  MG9_8_11PL    ~(1 << 0)
#else
#define  MG9_8_11PL    0xFFFF
#endif

#if (G9_2PL >= G9_8PL) || (G9_2PL == 0)
#define  MG9_8_12PL    ~(1 << 1)
#else
#define  MG9_8_12PL    0xFFFF
#endif

#if (G9_3PL >= G9_8PL) || (G9_3PL == 0)
#define  MG9_8_13PL    ~(1 << 2)
#else
#define  MG9_8_13PL    0xFFFF
#endif

#if (G9_4PL >= G9_8PL) || (G9_4PL == 0)
#define  MG9_8_14PL    ~(1 << 3)
#else
#define  MG9_8_14PL    0xFFFF
#endif

#if (G9_5PL >= G9_8PL) || (G9_5PL == 0)
#define  MG9_8_15PL    ~(1 << 4)
#else
#define  MG9_8_15PL    0xFFFF
#endif

#if (G9_6PL >= G9_8PL) || (G9_6PL == 0)
#define  MG9_8_16PL    ~(1 << 5)
#else
#define  MG9_8_16PL    0xFFFF
#endif

#if (G9_7PL >= G9_8PL) || (G9_7PL == 0)
#define  MG9_8_17PL    ~(1 << 6)
#else
#define  MG9_8_17PL    0xFFFF
#endif

#if (G9_9PL >= G9_8PL) || (G9_9PL == 0)
#define  MG9_8_19PL    ~(1 << 8)
#else
#define  MG9_8_19PL    0xFFFF
#endif

#if (G9_10PL >= G9_8PL) || (G9_10PL == 0)
#define  MG9_8_110PL    ~(1 << 9)
#else
#define  MG9_8_110PL    0xFFFF
#endif

#if (G9_11PL >= G9_8PL) || (G9_11PL == 0)
#define  MG9_8_111PL    ~(1 << 10)
#else
#define  MG9_8_111PL    0xFFFF
#endif

#if (G9_12PL >= G9_8PL) || (G9_12PL == 0)
#define  MG9_8_112PL    ~(1 << 11)
#else
#define  MG9_8_112PL    0xFFFF
#endif

#if (G9_13PL >= G9_8PL) || (G9_13PL == 0)
#define  MG9_8_113PL    ~(1 << 12)
#else
#define  MG9_8_113PL    0xFFFF
#endif

#if (G9_14PL >= G9_8PL) || (G9_14PL == 0)
#define  MG9_8_114PL    ~(1 << 13)
#else
#define  MG9_8_114PL    0xFFFF
#endif

#if (G9_15PL >= G9_8PL) || (G9_15PL == 0)
#define  MG9_8_115PL    ~(1 << 14)
#else
#define  MG9_8_115PL    0xFFFF
#endif

#if (G9_16PL >= G9_8PL) || (G9_16PL == 0)
#define  MG9_8_116PL    ~(1 << 15)
#else
#define  MG9_8_116PL    0xFFFF
#endif

#define  MG9_8_18PL	0xFF7F
#define  MG9_8    (MG9_8_11PL & MG9_8_12PL & MG9_8_13PL & MG9_8_14PL & \
                    MG9_8_15PL & MG9_8_16PL & MG9_8_17PL & MG9_8_18PL & \
                    MG9_8_19PL & MG9_8_110PL & MG9_8_111PL & MG9_8_112PL & \
                    MG9_8_113PL & MG9_8_114PL & MG9_8_115PL & MG9_8_116PL)
// End of MG9_8:
// Beginning of MG99:
#if (G9_1PL >= G9_9PL) || (G9_1PL == 0)
#define  MG9_9_11PL    ~(1 << 0)
#else
#define  MG9_9_11PL    0xFFFF
#endif

#if (G9_2PL >= G9_9PL) || (G9_2PL == 0)
#define  MG9_9_12PL    ~(1 << 1)
#else
#define  MG9_9_12PL    0xFFFF
#endif

#if (G9_3PL >= G9_9PL) || (G9_3PL == 0)
#define  MG9_9_13PL    ~(1 << 2)
#else
#define  MG9_9_13PL    0xFFFF
#endif

#if (G9_4PL >= G9_9PL) || (G9_4PL == 0)
#define  MG9_9_14PL    ~(1 << 3)
#else
#define  MG9_9_14PL    0xFFFF
#endif

#if (G9_5PL >= G9_9PL) || (G9_5PL == 0)
#define  MG9_9_15PL    ~(1 << 4)
#else
#define  MG9_9_15PL    0xFFFF
#endif

#if (G9_6PL >= G9_9PL) || (G9_6PL == 0)
#define  MG9_9_16PL    ~(1 << 5)
#else
#define  MG9_9_16PL    0xFFFF
#endif

#if (G9_7PL >= G9_9PL) || (G9_7PL == 0)
#define  MG9_9_17PL    ~(1 << 6)
#else
#define  MG9_9_17PL    0xFFFF
#endif

#if (G9_8PL >= G9_9PL) || (G9_8PL == 0)
#define  MG9_9_18PL    ~(1 << 7)
#else
#define  MG9_9_18PL    0xFFFF
#endif

#if (G9_10PL >= G9_9PL) || (G9_10PL == 0)
#define  MG9_9_110PL    ~(1 << 9)
#else
#define  MG9_9_110PL    0xFFFF
#endif

#if (G9_11PL >= G9_9PL) || (G9_11PL == 0)
#define  MG9_9_111PL    ~(1 << 10)
#else
#define  MG9_9_111PL    0xFFFF
#endif

#if (G9_12PL >= G9_9PL) || (G9_12PL == 0)
#define  MG9_9_112PL    ~(1 << 11)
#else
#define  MG9_9_112PL    0xFFFF
#endif

#if (G9_13PL >= G9_9PL) || (G9_13PL == 0)
#define  MG9_9_113PL    ~(1 << 12)
#else
#define  MG9_9_113PL    0xFFFF
#endif

#if (G9_14PL >= G9_9PL) || (G9_14PL == 0)
#define  MG9_9_114PL    ~(1 << 13)
#else
#define  MG9_9_114PL    0xFFFF
#endif

#if (G9_15PL >= G9_9PL) || (G9_15PL == 0)
#define  MG9_9_115PL    ~(1 << 14)
#else
#define  MG9_9_115PL    0xFFFF
#endif

#if (G9_16PL >= G9_9PL) || (G9_16PL == 0)
#define  MG9_9_116PL    ~(1 << 15)
#else
#define  MG9_9_116PL    0xFFFF
#endif

#define  MG9_9_19PL	0xFEFF
#define  MG9_9    (MG9_9_11PL & MG9_9_12PL & MG9_9_13PL & MG9_9_14PL & \
                    MG9_9_15PL & MG9_9_16PL & MG9_9_17PL & MG9_9_18PL & \
                    MG9_9_19PL & MG9_9_110PL & MG9_9_111PL & MG9_9_112PL & \
                    MG9_9_113PL & MG9_9_114PL & MG9_9_115PL & MG9_9_116PL)
// End of MG9_9:
// Beginning of MG910:
#if (G9_1PL >= G9_10PL) || (G9_1PL == 0)
#define  MG9_10_11PL    ~(1 << 0)
#else
#define  MG9_10_11PL    0xFFFF
#endif

#if (G9_2PL >= G9_10PL) || (G9_2PL == 0)
#define  MG9_10_12PL    ~(1 << 1)
#else
#define  MG9_10_12PL    0xFFFF
#endif

#if (G9_3PL >= G9_10PL) || (G9_3PL == 0)
#define  MG9_10_13PL    ~(1 << 2)
#else
#define  MG9_10_13PL    0xFFFF
#endif

#if (G9_4PL >= G9_10PL) || (G9_4PL == 0)
#define  MG9_10_14PL    ~(1 << 3)
#else
#define  MG9_10_14PL    0xFFFF
#endif

#if (G9_5PL >= G9_10PL) || (G9_5PL == 0)
#define  MG9_10_15PL    ~(1 << 4)
#else
#define  MG9_10_15PL    0xFFFF
#endif

#if (G9_6PL >= G9_10PL) || (G9_6PL == 0)
#define  MG9_10_16PL    ~(1 << 5)
#else
#define  MG9_10_16PL    0xFFFF
#endif

#if (G9_7PL >= G9_10PL) || (G9_7PL == 0)
#define  MG9_10_17PL    ~(1 << 6)
#else
#define  MG9_10_17PL    0xFFFF
#endif

#if (G9_8PL >= G9_10PL) || (G9_8PL == 0)
#define  MG9_10_18PL    ~(1 << 7)
#else
#define  MG9_10_18PL    0xFFFF
#endif

#if (G9_9PL >= G9_10PL) || (G9_9PL == 0)
#define  MG9_10_19PL    ~(1 << 8)
#else
#define  MG9_10_19PL    0xFFFF
#endif

#if (G9_11PL >= G9_10PL) || (G9_11PL == 0)
#define  MG9_10_111PL    ~(1 << 10)
#else
#define  MG9_10_111PL    0xFFFF
#endif

#if (G9_12PL >= G9_10PL) || (G9_12PL == 0)
#define  MG9_10_112PL    ~(1 << 11)
#else
#define  MG9_10_112PL    0xFFFF
#endif

#if (G9_13PL >= G9_10PL) || (G9_13PL == 0)
#define  MG9_10_113PL    ~(1 << 12)
#else
#define  MG9_10_113PL    0xFFFF
#endif

#if (G9_14PL >= G9_10PL) || (G9_14PL == 0)
#define  MG9_10_114PL    ~(1 << 13)
#else
#define  MG9_10_114PL    0xFFFF
#endif

#if (G9_15PL >= G9_10PL) || (G9_15PL == 0)
#define  MG9_10_115PL    ~(1 << 14)
#else
#define  MG9_10_115PL    0xFFFF
#endif

#if (G9_16PL >= G9_10PL) || (G9_16PL == 0)
#define  MG9_10_116PL    ~(1 << 15)
#else
#define  MG9_10_116PL    0xFFFF
#endif

#define  MG9_10_110PL	0xFDFF
#define  MG9_10    (MG9_10_11PL & MG9_10_12PL & MG9_10_13PL & MG9_10_14PL & \
                    MG9_10_15PL & MG9_10_16PL & MG9_10_17PL & MG9_10_18PL & \
                    MG9_10_19PL & MG9_10_110PL & MG9_10_111PL & MG9_10_112PL & \
                    MG9_10_113PL & MG9_10_114PL & MG9_10_115PL & MG9_10_116PL)
// End of MG9_10:
// Beginning of MG911:
#if (G9_1PL >= G9_11PL) || (G9_1PL == 0)
#define  MG9_11_11PL    ~(1 << 0)
#else
#define  MG9_11_11PL    0xFFFF
#endif

#if (G9_2PL >= G9_11PL) || (G9_2PL == 0)
#define  MG9_11_12PL    ~(1 << 1)
#else
#define  MG9_11_12PL    0xFFFF
#endif

#if (G9_3PL >= G9_11PL) || (G9_3PL == 0)
#define  MG9_11_13PL    ~(1 << 2)
#else
#define  MG9_11_13PL    0xFFFF
#endif

#if (G9_4PL >= G9_11PL) || (G9_4PL == 0)
#define  MG9_11_14PL    ~(1 << 3)
#else
#define  MG9_11_14PL    0xFFFF
#endif

#if (G9_5PL >= G9_11PL) || (G9_5PL == 0)
#define  MG9_11_15PL    ~(1 << 4)
#else
#define  MG9_11_15PL    0xFFFF
#endif

#if (G9_6PL >= G9_11PL) || (G9_6PL == 0)
#define  MG9_11_16PL    ~(1 << 5)
#else
#define  MG9_11_16PL    0xFFFF
#endif

#if (G9_7PL >= G9_11PL) || (G9_7PL == 0)
#define  MG9_11_17PL    ~(1 << 6)
#else
#define  MG9_11_17PL    0xFFFF
#endif

#if (G9_8PL >= G9_11PL) || (G9_8PL == 0)
#define  MG9_11_18PL    ~(1 << 7)
#else
#define  MG9_11_18PL    0xFFFF
#endif

#if (G9_9PL >= G9_11PL) || (G9_9PL == 0)
#define  MG9_11_19PL    ~(1 << 8)
#else
#define  MG9_11_19PL    0xFFFF
#endif

#if (G9_10PL >= G9_11PL) || (G9_10PL == 0)
#define  MG9_11_110PL    ~(1 << 9)
#else
#define  MG9_11_110PL    0xFFFF
#endif

#if (G9_12PL >= G9_11PL) || (G9_12PL == 0)
#define  MG9_11_112PL    ~(1 << 11)
#else
#define  MG9_11_112PL    0xFFFF
#endif

#if (G9_13PL >= G9_11PL) || (G9_13PL == 0)
#define  MG9_11_113PL    ~(1 << 12)
#else
#define  MG9_11_113PL    0xFFFF
#endif

#if (G9_14PL >= G9_11PL) || (G9_14PL == 0)
#define  MG9_11_114PL    ~(1 << 13)
#else
#define  MG9_11_114PL    0xFFFF
#endif

#if (G9_15PL >= G9_11PL) || (G9_15PL == 0)
#define  MG9_11_115PL    ~(1 << 14)
#else
#define  MG9_11_115PL    0xFFFF
#endif

#if (G9_16PL >= G9_11PL) || (G9_16PL == 0)
#define  MG9_11_116PL    ~(1 << 15)
#else
#define  MG9_11_116PL    0xFFFF
#endif

#define  MG9_11_111PL	0xFBFF
#define  MG9_11    (MG9_11_11PL & MG9_11_12PL & MG9_11_13PL & MG9_11_14PL & \
                    MG9_11_15PL & MG9_11_16PL & MG9_11_17PL & MG9_11_18PL & \
                    MG9_11_19PL & MG9_11_110PL & MG9_11_111PL & MG9_11_112PL & \
                    MG9_11_113PL & MG9_11_114PL & MG9_11_115PL & MG9_11_116PL)
// End of MG9_11:
// Beginning of MG912:
#if (G9_1PL >= G9_12PL) || (G9_1PL == 0)
#define  MG9_12_11PL    ~(1 << 0)
#else
#define  MG9_12_11PL    0xFFFF
#endif

#if (G9_2PL >= G9_12PL) || (G9_2PL == 0)
#define  MG9_12_12PL    ~(1 << 1)
#else
#define  MG9_12_12PL    0xFFFF
#endif

#if (G9_3PL >= G9_12PL) || (G9_3PL == 0)
#define  MG9_12_13PL    ~(1 << 2)
#else
#define  MG9_12_13PL    0xFFFF
#endif

#if (G9_4PL >= G9_12PL) || (G9_4PL == 0)
#define  MG9_12_14PL    ~(1 << 3)
#else
#define  MG9_12_14PL    0xFFFF
#endif

#if (G9_5PL >= G9_12PL) || (G9_5PL == 0)
#define  MG9_12_15PL    ~(1 << 4)
#else
#define  MG9_12_15PL    0xFFFF
#endif

#if (G9_6PL >= G9_12PL) || (G9_6PL == 0)
#define  MG9_12_16PL    ~(1 << 5)
#else
#define  MG9_12_16PL    0xFFFF
#endif

#if (G9_7PL >= G9_12PL) || (G9_7PL == 0)
#define  MG9_12_17PL    ~(1 << 6)
#else
#define  MG9_12_17PL    0xFFFF
#endif

#if (G9_8PL >= G9_12PL) || (G9_8PL == 0)
#define  MG9_12_18PL    ~(1 << 7)
#else
#define  MG9_12_18PL    0xFFFF
#endif

#if (G9_9PL >= G9_12PL) || (G9_9PL == 0)
#define  MG9_12_19PL    ~(1 << 8)
#else
#define  MG9_12_19PL    0xFFFF
#endif

#if (G9_10PL >= G9_12PL) || (G9_10PL == 0)
#define  MG9_12_110PL    ~(1 << 9)
#else
#define  MG9_12_110PL    0xFFFF
#endif

#if (G9_11PL >= G9_12PL) || (G9_11PL == 0)
#define  MG9_12_111PL    ~(1 << 10)
#else
#define  MG9_12_111PL    0xFFFF
#endif

#if (G9_13PL >= G9_12PL) || (G9_13PL == 0)
#define  MG9_12_113PL    ~(1 << 12)
#else
#define  MG9_12_113PL    0xFFFF
#endif

#if (G9_14PL >= G9_12PL) || (G9_14PL == 0)
#define  MG9_12_114PL    ~(1 << 13)
#else
#define  MG9_12_114PL    0xFFFF
#endif

#if (G9_15PL >= G9_12PL) || (G9_15PL == 0)
#define  MG9_12_115PL    ~(1 << 14)
#else
#define  MG9_12_115PL    0xFFFF
#endif

#if (G9_16PL >= G9_12PL) || (G9_16PL == 0)
#define  MG9_12_116PL    ~(1 << 15)
#else
#define  MG9_12_116PL    0xFFFF
#endif

#define  MG9_12_112PL	0xF7FF
#define  MG9_12    (MG9_12_11PL & MG9_12_12PL & MG9_12_13PL & MG9_12_14PL & \
                    MG9_12_15PL & MG9_12_16PL & MG9_12_17PL & MG9_12_18PL & \
                    MG9_12_19PL & MG9_12_110PL & MG9_12_111PL & MG9_12_112PL & \
                    MG9_12_113PL & MG9_12_114PL & MG9_12_115PL & MG9_12_116PL)
// End of MG9_12:
// Beginning of MG913:
#if (G9_1PL >= G9_13PL) || (G9_1PL == 0)
#define  MG9_13_11PL    ~(1 << 0)
#else
#define  MG9_13_11PL    0xFFFF
#endif

#if (G9_2PL >= G9_13PL) || (G9_2PL == 0)
#define  MG9_13_12PL    ~(1 << 1)
#else
#define  MG9_13_12PL    0xFFFF
#endif

#if (G9_3PL >= G9_13PL) || (G9_3PL == 0)
#define  MG9_13_13PL    ~(1 << 2)
#else
#define  MG9_13_13PL    0xFFFF
#endif

#if (G9_4PL >= G9_13PL) || (G9_4PL == 0)
#define  MG9_13_14PL    ~(1 << 3)
#else
#define  MG9_13_14PL    0xFFFF
#endif

#if (G9_5PL >= G9_13PL) || (G9_5PL == 0)
#define  MG9_13_15PL    ~(1 << 4)
#else
#define  MG9_13_15PL    0xFFFF
#endif

#if (G9_6PL >= G9_13PL) || (G9_6PL == 0)
#define  MG9_13_16PL    ~(1 << 5)
#else
#define  MG9_13_16PL    0xFFFF
#endif

#if (G9_7PL >= G9_13PL) || (G9_7PL == 0)
#define  MG9_13_17PL    ~(1 << 6)
#else
#define  MG9_13_17PL    0xFFFF
#endif

#if (G9_8PL >= G9_13PL) || (G9_8PL == 0)
#define  MG9_13_18PL    ~(1 << 7)
#else
#define  MG9_13_18PL    0xFFFF
#endif

#if (G9_9PL >= G9_13PL) || (G9_9PL == 0)
#define  MG9_13_19PL    ~(1 << 8)
#else
#define  MG9_13_19PL    0xFFFF
#endif

#if (G9_10PL >= G9_13PL) || (G9_10PL == 0)
#define  MG9_13_110PL    ~(1 << 9)
#else
#define  MG9_13_110PL    0xFFFF
#endif

#if (G9_11PL >= G9_13PL) || (G9_11PL == 0)
#define  MG9_13_111PL    ~(1 << 10)
#else
#define  MG9_13_111PL    0xFFFF
#endif

#if (G9_12PL >= G9_13PL) || (G9_12PL == 0)
#define  MG9_13_112PL    ~(1 << 11)
#else
#define  MG9_13_112PL    0xFFFF
#endif

#if (G9_14PL >= G9_13PL) || (G9_14PL == 0)
#define  MG9_13_114PL    ~(1 << 13)
#else
#define  MG9_13_114PL    0xFFFF
#endif

#if (G9_15PL >= G9_13PL) || (G9_15PL == 0)
#define  MG9_13_115PL    ~(1 << 14)
#else
#define  MG9_13_115PL    0xFFFF
#endif

#if (G9_16PL >= G9_13PL) || (G9_16PL == 0)
#define  MG9_13_116PL    ~(1 << 15)
#else
#define  MG9_13_116PL    0xFFFF
#endif

#define  MG9_13_113PL	0xEFFF
#define  MG9_13    (MG9_13_11PL & MG9_13_12PL & MG9_13_13PL & MG9_13_14PL & \
                    MG9_13_15PL & MG9_13_16PL & MG9_13_17PL & MG9_13_18PL & \
                    MG9_13_19PL & MG9_13_110PL & MG9_13_111PL & MG9_13_112PL & \
                    MG9_13_113PL & MG9_13_114PL & MG9_13_115PL & MG9_13_116PL)
// End of MG9_13:
// Beginning of MG914:
#if (G9_1PL >= G9_14PL) || (G9_1PL == 0)
#define  MG9_14_11PL    ~(1 << 0)
#else
#define  MG9_14_11PL    0xFFFF
#endif

#if (G9_2PL >= G9_14PL) || (G9_2PL == 0)
#define  MG9_14_12PL    ~(1 << 1)
#else
#define  MG9_14_12PL    0xFFFF
#endif

#if (G9_3PL >= G9_14PL) || (G9_3PL == 0)
#define  MG9_14_13PL    ~(1 << 2)
#else
#define  MG9_14_13PL    0xFFFF
#endif

#if (G9_4PL >= G9_14PL) || (G9_4PL == 0)
#define  MG9_14_14PL    ~(1 << 3)
#else
#define  MG9_14_14PL    0xFFFF
#endif

#if (G9_5PL >= G9_14PL) || (G9_5PL == 0)
#define  MG9_14_15PL    ~(1 << 4)
#else
#define  MG9_14_15PL    0xFFFF
#endif

#if (G9_6PL >= G9_14PL) || (G9_6PL == 0)
#define  MG9_14_16PL    ~(1 << 5)
#else
#define  MG9_14_16PL    0xFFFF
#endif

#if (G9_7PL >= G9_14PL) || (G9_7PL == 0)
#define  MG9_14_17PL    ~(1 << 6)
#else
#define  MG9_14_17PL    0xFFFF
#endif

#if (G9_8PL >= G9_14PL) || (G9_8PL == 0)
#define  MG9_14_18PL    ~(1 << 7)
#else
#define  MG9_14_18PL    0xFFFF
#endif

#if (G9_9PL >= G9_14PL) || (G9_9PL == 0)
#define  MG9_14_19PL    ~(1 << 8)
#else
#define  MG9_14_19PL    0xFFFF
#endif

#if (G9_10PL >= G9_14PL) || (G9_10PL == 0)
#define  MG9_14_110PL    ~(1 << 9)
#else
#define  MG9_14_110PL    0xFFFF
#endif

#if (G9_11PL >= G9_14PL) || (G9_11PL == 0)
#define  MG9_14_111PL    ~(1 << 10)
#else
#define  MG9_14_111PL    0xFFFF
#endif

#if (G9_12PL >= G9_14PL) || (G9_12PL == 0)
#define  MG9_14_112PL    ~(1 << 11)
#else
#define  MG9_14_112PL    0xFFFF
#endif

#if (G9_13PL >= G9_14PL) || (G9_13PL == 0)
#define  MG9_14_113PL    ~(1 << 12)
#else
#define  MG9_14_113PL    0xFFFF
#endif

#if (G9_15PL >= G9_14PL) || (G9_15PL == 0)
#define  MG9_14_115PL    ~(1 << 14)
#else
#define  MG9_14_115PL    0xFFFF
#endif

#if (G9_16PL >= G9_14PL) || (G9_16PL == 0)
#define  MG9_14_116PL    ~(1 << 15)
#else
#define  MG9_14_116PL    0xFFFF
#endif

#define  MG9_14_114PL	0xDFFF
#define  MG9_14    (MG9_14_11PL & MG9_14_12PL & MG9_14_13PL & MG9_14_14PL & \
                    MG9_14_15PL & MG9_14_16PL & MG9_14_17PL & MG9_14_18PL & \
                    MG9_14_19PL & MG9_14_110PL & MG9_14_111PL & MG9_14_112PL & \
                    MG9_14_113PL & MG9_14_114PL & MG9_14_115PL & MG9_14_116PL)
// End of MG9_14:
// Beginning of MG915:
#if (G9_1PL >= G9_15PL) || (G9_1PL == 0)
#define  MG9_15_11PL    ~(1 << 0)
#else
#define  MG9_15_11PL    0xFFFF
#endif

#if (G9_2PL >= G9_15PL) || (G9_2PL == 0)
#define  MG9_15_12PL    ~(1 << 1)
#else
#define  MG9_15_12PL    0xFFFF
#endif

#if (G9_3PL >= G9_15PL) || (G9_3PL == 0)
#define  MG9_15_13PL    ~(1 << 2)
#else
#define  MG9_15_13PL    0xFFFF
#endif

#if (G9_4PL >= G9_15PL) || (G9_4PL == 0)
#define  MG9_15_14PL    ~(1 << 3)
#else
#define  MG9_15_14PL    0xFFFF
#endif

#if (G9_5PL >= G9_15PL) || (G9_5PL == 0)
#define  MG9_15_15PL    ~(1 << 4)
#else
#define  MG9_15_15PL    0xFFFF
#endif

#if (G9_6PL >= G9_15PL) || (G9_6PL == 0)
#define  MG9_15_16PL    ~(1 << 5)
#else
#define  MG9_15_16PL    0xFFFF
#endif

#if (G9_7PL >= G9_15PL) || (G9_7PL == 0)
#define  MG9_15_17PL    ~(1 << 6)
#else
#define  MG9_15_17PL    0xFFFF
#endif

#if (G9_8PL >= G9_15PL) || (G9_8PL == 0)
#define  MG9_15_18PL    ~(1 << 7)
#else
#define  MG9_15_18PL    0xFFFF
#endif

#if (G9_9PL >= G9_15PL) || (G9_9PL == 0)
#define  MG9_15_19PL    ~(1 << 8)
#else
#define  MG9_15_19PL    0xFFFF
#endif

#if (G9_10PL >= G9_15PL) || (G9_10PL == 0)
#define  MG9_15_110PL    ~(1 << 9)
#else
#define  MG9_15_110PL    0xFFFF
#endif

#if (G9_11PL >= G9_15PL) || (G9_11PL == 0)
#define  MG9_15_111PL    ~(1 << 10)
#else
#define  MG9_15_111PL    0xFFFF
#endif

#if (G9_12PL >= G9_15PL) || (G9_12PL == 0)
#define  MG9_15_112PL    ~(1 << 11)
#else
#define  MG9_15_112PL    0xFFFF
#endif

#if (G9_13PL >= G9_15PL) || (G9_13PL == 0)
#define  MG9_15_113PL    ~(1 << 12)
#else
#define  MG9_15_113PL    0xFFFF
#endif

#if (G9_14PL >= G9_15PL) || (G9_14PL == 0)
#define  MG9_15_114PL    ~(1 << 13)
#else
#define  MG9_15_114PL    0xFFFF
#endif

#if (G9_16PL >= G9_15PL) || (G9_16PL == 0)
#define  MG9_15_116PL    ~(1 << 15)
#else
#define  MG9_15_116PL    0xFFFF
#endif

#define  MG9_15_115PL	0xBFFF
#define  MG9_15    (MG9_15_11PL & MG9_15_12PL & MG9_15_13PL & MG9_15_14PL & \
                    MG9_15_15PL & MG9_15_16PL & MG9_15_17PL & MG9_15_18PL & \
                    MG9_15_19PL & MG9_15_110PL & MG9_15_111PL & MG9_15_112PL & \
                    MG9_15_113PL & MG9_15_114PL & MG9_15_115PL & MG9_15_116PL)
// End of MG9_15:
// Beginning of MG916:
#if (G9_1PL >= G9_16PL) || (G9_1PL == 0)
#define  MG9_16_11PL    ~(1 << 0)
#else
#define  MG9_16_11PL    0xFFFF
#endif

#if (G9_2PL >= G9_16PL) || (G9_2PL == 0)
#define  MG9_16_12PL    ~(1 << 1)
#else
#define  MG9_16_12PL    0xFFFF
#endif

#if (G9_3PL >= G9_16PL) || (G9_3PL == 0)
#define  MG9_16_13PL    ~(1 << 2)
#else
#define  MG9_16_13PL    0xFFFF
#endif

#if (G9_4PL >= G9_16PL) || (G9_4PL == 0)
#define  MG9_16_14PL    ~(1 << 3)
#else
#define  MG9_16_14PL    0xFFFF
#endif

#if (G9_5PL >= G9_16PL) || (G9_5PL == 0)
#define  MG9_16_15PL    ~(1 << 4)
#else
#define  MG9_16_15PL    0xFFFF
#endif

#if (G9_6PL >= G9_16PL) || (G9_6PL == 0)
#define  MG9_16_16PL    ~(1 << 5)
#else
#define  MG9_16_16PL    0xFFFF
#endif

#if (G9_7PL >= G9_16PL) || (G9_7PL == 0)
#define  MG9_16_17PL    ~(1 << 6)
#else
#define  MG9_16_17PL    0xFFFF
#endif

#if (G9_8PL >= G9_16PL) || (G9_8PL == 0)
#define  MG9_16_18PL    ~(1 << 7)
#else
#define  MG9_16_18PL    0xFFFF
#endif

#if (G9_9PL >= G9_16PL) || (G9_9PL == 0)
#define  MG9_16_19PL    ~(1 << 8)
#else
#define  MG9_16_19PL    0xFFFF
#endif

#if (G9_10PL >= G9_16PL) || (G9_10PL == 0)
#define  MG9_16_110PL    ~(1 << 9)
#else
#define  MG9_16_110PL    0xFFFF
#endif

#if (G9_11PL >= G9_16PL) || (G9_11PL == 0)
#define  MG9_16_111PL    ~(1 << 10)
#else
#define  MG9_16_111PL    0xFFFF
#endif

#if (G9_12PL >= G9_16PL) || (G9_12PL == 0)
#define  MG9_16_112PL    ~(1 << 11)
#else
#define  MG9_16_112PL    0xFFFF
#endif

#if (G9_13PL >= G9_16PL) || (G9_13PL == 0)
#define  MG9_16_113PL    ~(1 << 12)
#else
#define  MG9_16_113PL    0xFFFF
#endif

#if (G9_14PL >= G9_16PL) || (G9_14PL == 0)
#define  MG9_16_114PL    ~(1 << 13)
#else
#define  MG9_16_114PL    0xFFFF
#endif

#if (G9_15PL >= G9_16PL) || (G9_15PL == 0)
#define  MG9_16_115PL    ~(1 << 14)
#else
#define  MG9_16_115PL    0xFFFF
#endif

#define  MG9_16_116PL	0x7FFF
#define  MG9_16    (MG9_16_11PL & MG9_16_12PL & MG9_16_13PL & MG9_16_14PL & \
                    MG9_16_15PL & MG9_16_16PL & MG9_16_17PL & MG9_16_18PL & \
                    MG9_16_19PL & MG9_16_110PL & MG9_16_111PL & MG9_16_112PL & \
                    MG9_16_113PL & MG9_16_114PL & MG9_16_115PL & MG9_16_116PL)
// End of MG9_16:


//-------------------------------------------------------------------------------
// Automatically generate PIEIER10 interrupt masks MG101 to MG1016:

// Beginning of MG101:
#if (G10_2PL >= G10_1PL) || (G10_2PL == 0)
#define  MG10_1_12PL    ~(1 << 1)
#else
#define  MG10_1_12PL    0xFFFF
#endif

#if (G10_3PL >= G10_1PL) || (G10_3PL == 0)
#define  MG10_1_13PL    ~(1 << 2)
#else
#define  MG10_1_13PL    0xFFFF
#endif

#if (G10_4PL >= G10_1PL) || (G10_4PL == 0)
#define  MG10_1_14PL    ~(1 << 3)
#else
#define  MG10_1_14PL    0xFFFF
#endif

#if (G10_5PL >= G10_1PL) || (G10_5PL == 0)
#define  MG10_1_15PL    ~(1 << 4)
#else
#define  MG10_1_15PL    0xFFFF
#endif

#if (G10_6PL >= G10_1PL) || (G10_6PL == 0)
#define  MG10_1_16PL    ~(1 << 5)
#else
#define  MG10_1_16PL    0xFFFF
#endif

#if (G10_7PL >= G10_1PL) || (G10_7PL == 0)
#define  MG10_1_17PL    ~(1 << 6)
#else
#define  MG10_1_17PL    0xFFFF
#endif

#if (G10_8PL >= G10_1PL) || (G10_8PL == 0)
#define  MG10_1_18PL    ~(1 << 7)
#else
#define  MG10_1_18PL    0xFFFF
#endif

#if (G10_9PL >= G10_1PL) || (G10_9PL == 0)
#define  MG10_1_19PL    ~(1 << 8)
#else
#define  MG10_1_19PL    0xFFFF
#endif

#if (G10_10PL >= G10_1PL) || (G10_10PL == 0)
#define  MG10_1_110PL    ~(1 << 9)
#else
#define  MG10_1_110PL    0xFFFF
#endif

#if (G10_11PL >= G10_1PL) || (G10_11PL == 0)
#define  MG10_1_111PL    ~(1 << 10)
#else
#define  MG10_1_111PL    0xFFFF
#endif

#if (G10_12PL >= G10_1PL) || (G10_12PL == 0)
#define  MG10_1_112PL    ~(1 << 11)
#else
#define  MG10_1_112PL    0xFFFF
#endif

#if (G10_13PL >= G10_1PL) || (G10_13PL == 0)
#define  MG10_1_113PL    ~(1 << 12)
#else
#define  MG10_1_113PL    0xFFFF
#endif

#if (G10_14PL >= G10_1PL) || (G10_14PL == 0)
#define  MG10_1_114PL    ~(1 << 13)
#else
#define  MG10_1_114PL    0xFFFF
#endif

#if (G10_15PL >= G10_1PL) || (G10_15PL == 0)
#define  MG10_1_115PL    ~(1 << 14)
#else
#define  MG10_1_115PL    0xFFFF
#endif

#if (G10_16PL >= G10_1PL) || (G10_16PL == 0)
#define  MG10_1_116PL    ~(1 << 15)
#else
#define  MG10_1_116PL    0xFFFF
#endif

#define  MG10_1_11PL	0xFFFE
#define  MG10_1    (MG10_1_11PL & MG10_1_12PL & MG10_1_13PL & MG10_1_14PL & \
                    MG10_1_15PL & MG10_1_16PL & MG10_1_17PL & MG10_1_18PL & \
                    MG10_1_19PL & MG10_1_110PL & MG10_1_111PL & MG10_1_112PL & \
                    MG10_1_113PL & MG10_1_114PL & MG10_1_115PL & MG10_1_116PL)
// End of MG10_1:
// Beginning of MG102:
#if (G10_1PL >= G10_2PL) || (G10_1PL == 0)
#define  MG10_2_11PL    ~(1 << 0)
#else
#define  MG10_2_11PL    0xFFFF
#endif

#if (G10_3PL >= G10_2PL) || (G10_3PL == 0)
#define  MG10_2_13PL    ~(1 << 2)
#else
#define  MG10_2_13PL    0xFFFF
#endif

#if (G10_4PL >= G10_2PL) || (G10_4PL == 0)
#define  MG10_2_14PL    ~(1 << 3)
#else
#define  MG10_2_14PL    0xFFFF
#endif

#if (G10_5PL >= G10_2PL) || (G10_5PL == 0)
#define  MG10_2_15PL    ~(1 << 4)
#else
#define  MG10_2_15PL    0xFFFF
#endif

#if (G10_6PL >= G10_2PL) || (G10_6PL == 0)
#define  MG10_2_16PL    ~(1 << 5)
#else
#define  MG10_2_16PL    0xFFFF
#endif

#if (G10_7PL >= G10_2PL) || (G10_7PL == 0)
#define  MG10_2_17PL    ~(1 << 6)
#else
#define  MG10_2_17PL    0xFFFF
#endif

#if (G10_8PL >= G10_2PL) || (G10_8PL == 0)
#define  MG10_2_18PL    ~(1 << 7)
#else
#define  MG10_2_18PL    0xFFFF
#endif

#if (G10_9PL >= G10_2PL) || (G10_9PL == 0)
#define  MG10_2_19PL    ~(1 << 8)
#else
#define  MG10_2_19PL    0xFFFF
#endif

#if (G10_10PL >= G10_2PL) || (G10_10PL == 0)
#define  MG10_2_110PL    ~(1 << 9)
#else
#define  MG10_2_110PL    0xFFFF
#endif

#if (G10_11PL >= G10_2PL) || (G10_11PL == 0)
#define  MG10_2_111PL    ~(1 << 10)
#else
#define  MG10_2_111PL    0xFFFF
#endif

#if (G10_12PL >= G10_2PL) || (G10_12PL == 0)
#define  MG10_2_112PL    ~(1 << 11)
#else
#define  MG10_2_112PL    0xFFFF
#endif

#if (G10_13PL >= G10_2PL) || (G10_13PL == 0)
#define  MG10_2_113PL    ~(1 << 12)
#else
#define  MG10_2_113PL    0xFFFF
#endif

#if (G10_14PL >= G10_2PL) || (G10_14PL == 0)
#define  MG10_2_114PL    ~(1 << 13)
#else
#define  MG10_2_114PL    0xFFFF
#endif

#if (G10_15PL >= G10_2PL) || (G10_15PL == 0)
#define  MG10_2_115PL    ~(1 << 14)
#else
#define  MG10_2_115PL    0xFFFF
#endif

#if (G10_16PL >= G10_2PL) || (G10_16PL == 0)
#define  MG10_2_116PL    ~(1 << 15)
#else
#define  MG10_2_116PL    0xFFFF
#endif

#define  MG10_2_12PL	0xFFFD
#define  MG10_2    (MG10_2_11PL & MG10_2_12PL & MG10_2_13PL & MG10_2_14PL & \
                    MG10_2_15PL & MG10_2_16PL & MG10_2_17PL & MG10_2_18PL & \
                    MG10_2_19PL & MG10_2_110PL & MG10_2_111PL & MG10_2_112PL & \
                    MG10_2_113PL & MG10_2_114PL & MG10_2_115PL & MG10_2_116PL)
// End of MG10_2:
// Beginning of MG103:
#if (G10_1PL >= G10_3PL) || (G10_1PL == 0)
#define  MG10_3_11PL    ~(1 << 0)
#else
#define  MG10_3_11PL    0xFFFF
#endif

#if (G10_2PL >= G10_3PL) || (G10_2PL == 0)
#define  MG10_3_12PL    ~(1 << 1)
#else
#define  MG10_3_12PL    0xFFFF
#endif

#if (G10_4PL >= G10_3PL) || (G10_4PL == 0)
#define  MG10_3_14PL    ~(1 << 3)
#else
#define  MG10_3_14PL    0xFFFF
#endif

#if (G10_5PL >= G10_3PL) || (G10_5PL == 0)
#define  MG10_3_15PL    ~(1 << 4)
#else
#define  MG10_3_15PL    0xFFFF
#endif

#if (G10_6PL >= G10_3PL) || (G10_6PL == 0)
#define  MG10_3_16PL    ~(1 << 5)
#else
#define  MG10_3_16PL    0xFFFF
#endif

#if (G10_7PL >= G10_3PL) || (G10_7PL == 0)
#define  MG10_3_17PL    ~(1 << 6)
#else
#define  MG10_3_17PL    0xFFFF
#endif

#if (G10_8PL >= G10_3PL) || (G10_8PL == 0)
#define  MG10_3_18PL    ~(1 << 7)
#else
#define  MG10_3_18PL    0xFFFF
#endif

#if (G10_9PL >= G10_3PL) || (G10_9PL == 0)
#define  MG10_3_19PL    ~(1 << 8)
#else
#define  MG10_3_19PL    0xFFFF
#endif

#if (G10_10PL >= G10_3PL) || (G10_10PL == 0)
#define  MG10_3_110PL    ~(1 << 9)
#else
#define  MG10_3_110PL    0xFFFF
#endif

#if (G10_11PL >= G10_3PL) || (G10_11PL == 0)
#define  MG10_3_111PL    ~(1 << 10)
#else
#define  MG10_3_111PL    0xFFFF
#endif

#if (G10_12PL >= G10_3PL) || (G10_12PL == 0)
#define  MG10_3_112PL    ~(1 << 11)
#else
#define  MG10_3_112PL    0xFFFF
#endif

#if (G10_13PL >= G10_3PL) || (G10_13PL == 0)
#define  MG10_3_113PL    ~(1 << 12)
#else
#define  MG10_3_113PL    0xFFFF
#endif

#if (G10_14PL >= G10_3PL) || (G10_14PL == 0)
#define  MG10_3_114PL    ~(1 << 13)
#else
#define  MG10_3_114PL    0xFFFF
#endif

#if (G10_15PL >= G10_3PL) || (G10_15PL == 0)
#define  MG10_3_115PL    ~(1 << 14)
#else
#define  MG10_3_115PL    0xFFFF
#endif

#if (G10_16PL >= G10_3PL) || (G10_16PL == 0)
#define  MG10_3_116PL    ~(1 << 15)
#else
#define  MG10_3_116PL    0xFFFF
#endif

#define  MG10_3_13PL	0xFFFB
#define  MG10_3    (MG10_3_11PL & MG10_3_12PL & MG10_3_13PL & MG10_3_14PL & \
                    MG10_3_15PL & MG10_3_16PL & MG10_3_17PL & MG10_3_18PL & \
                    MG10_3_19PL & MG10_3_110PL & MG10_3_111PL & MG10_3_112PL & \
                    MG10_3_113PL & MG10_3_114PL & MG10_3_115PL & MG10_3_116PL)
// End of MG10_3:
// Beginning of MG104:
#if (G10_1PL >= G10_4PL) || (G10_1PL == 0)
#define  MG10_4_11PL    ~(1 << 0)
#else
#define  MG10_4_11PL    0xFFFF
#endif

#if (G10_2PL >= G10_4PL) || (G10_2PL == 0)
#define  MG10_4_12PL    ~(1 << 1)
#else
#define  MG10_4_12PL    0xFFFF
#endif

#if (G10_3PL >= G10_4PL) || (G10_3PL == 0)
#define  MG10_4_13PL    ~(1 << 2)
#else
#define  MG10_4_13PL    0xFFFF
#endif

#if (G10_5PL >= G10_4PL) || (G10_5PL == 0)
#define  MG10_4_15PL    ~(1 << 4)
#else
#define  MG10_4_15PL    0xFFFF
#endif

#if (G10_6PL >= G10_4PL) || (G10_6PL == 0)
#define  MG10_4_16PL    ~(1 << 5)
#else
#define  MG10_4_16PL    0xFFFF
#endif

#if (G10_7PL >= G10_4PL) || (G10_7PL == 0)
#define  MG10_4_17PL    ~(1 << 6)
#else
#define  MG10_4_17PL    0xFFFF
#endif

#if (G10_8PL >= G10_4PL) || (G10_8PL == 0)
#define  MG10_4_18PL    ~(1 << 7)
#else
#define  MG10_4_18PL    0xFFFF
#endif

#if (G10_9PL >= G10_4PL) || (G10_9PL == 0)
#define  MG10_4_19PL    ~(1 << 8)
#else
#define  MG10_4_19PL    0xFFFF
#endif

#if (G10_10PL >= G10_4PL) || (G10_10PL == 0)
#define  MG10_4_110PL    ~(1 << 9)
#else
#define  MG10_4_110PL    0xFFFF
#endif

#if (G10_11PL >= G10_4PL) || (G10_11PL == 0)
#define  MG10_4_111PL    ~(1 << 10)
#else
#define  MG10_4_111PL    0xFFFF
#endif

#if (G10_12PL >= G10_4PL) || (G10_12PL == 0)
#define  MG10_4_112PL    ~(1 << 11)
#else
#define  MG10_4_112PL    0xFFFF
#endif

#if (G10_13PL >= G10_4PL) || (G10_13PL == 0)
#define  MG10_4_113PL    ~(1 << 12)
#else
#define  MG10_4_113PL    0xFFFF
#endif

#if (G10_14PL >= G10_4PL) || (G10_14PL == 0)
#define  MG10_4_114PL    ~(1 << 13)
#else
#define  MG10_4_114PL    0xFFFF
#endif

#if (G10_15PL >= G10_4PL) || (G10_15PL == 0)
#define  MG10_4_115PL    ~(1 << 14)
#else
#define  MG10_4_115PL    0xFFFF
#endif

#if (G10_16PL >= G10_4PL) || (G10_16PL == 0)
#define  MG10_4_116PL    ~(1 << 15)
#else
#define  MG10_4_116PL    0xFFFF
#endif

#define  MG10_4_14PL	0xFFF7
#define  MG10_4    (MG10_4_11PL & MG10_4_12PL & MG10_4_13PL & MG10_4_14PL & \
                    MG10_4_15PL & MG10_4_16PL & MG10_4_17PL & MG10_4_18PL & \
                    MG10_4_19PL & MG10_4_110PL & MG10_4_111PL & MG10_4_112PL & \
                    MG10_4_113PL & MG10_4_114PL & MG10_4_115PL & MG10_4_116PL)
// End of MG10_4:
// Beginning of MG105:
#if (G10_1PL >= G10_5PL) || (G10_1PL == 0)
#define  MG10_5_11PL    ~(1 << 0)
#else
#define  MG10_5_11PL    0xFFFF
#endif

#if (G10_2PL >= G10_5PL) || (G10_2PL == 0)
#define  MG10_5_12PL    ~(1 << 1)
#else
#define  MG10_5_12PL    0xFFFF
#endif

#if (G10_3PL >= G10_5PL) || (G10_3PL == 0)
#define  MG10_5_13PL    ~(1 << 2)
#else
#define  MG10_5_13PL    0xFFFF
#endif

#if (G10_4PL >= G10_5PL) || (G10_4PL == 0)
#define  MG10_5_14PL    ~(1 << 3)
#else
#define  MG10_5_14PL    0xFFFF
#endif

#if (G10_6PL >= G10_5PL) || (G10_6PL == 0)
#define  MG10_5_16PL    ~(1 << 5)
#else
#define  MG10_5_16PL    0xFFFF
#endif

#if (G10_7PL >= G10_5PL) || (G10_7PL == 0)
#define  MG10_5_17PL    ~(1 << 6)
#else
#define  MG10_5_17PL    0xFFFF
#endif

#if (G10_8PL >= G10_5PL) || (G10_8PL == 0)
#define  MG10_5_18PL    ~(1 << 7)
#else
#define  MG10_5_18PL    0xFFFF
#endif

#if (G10_9PL >= G10_5PL) || (G10_9PL == 0)
#define  MG10_5_19PL    ~(1 << 8)
#else
#define  MG10_5_19PL    0xFFFF
#endif

#if (G10_10PL >= G10_5PL) || (G10_10PL == 0)
#define  MG10_5_110PL    ~(1 << 9)
#else
#define  MG10_5_110PL    0xFFFF
#endif

#if (G10_11PL >= G10_5PL) || (G10_11PL == 0)
#define  MG10_5_111PL    ~(1 << 10)
#else
#define  MG10_5_111PL    0xFFFF
#endif

#if (G10_12PL >= G10_5PL) || (G10_12PL == 0)
#define  MG10_5_112PL    ~(1 << 11)
#else
#define  MG10_5_112PL    0xFFFF
#endif

#if (G10_13PL >= G10_5PL) || (G10_13PL == 0)
#define  MG10_5_113PL    ~(1 << 12)
#else
#define  MG10_5_113PL    0xFFFF
#endif

#if (G10_14PL >= G10_5PL) || (G10_14PL == 0)
#define  MG10_5_114PL    ~(1 << 13)
#else
#define  MG10_5_114PL    0xFFFF
#endif

#if (G10_15PL >= G10_5PL) || (G10_15PL == 0)
#define  MG10_5_115PL    ~(1 << 14)
#else
#define  MG10_5_115PL    0xFFFF
#endif

#if (G10_16PL >= G10_5PL) || (G10_16PL == 0)
#define  MG10_5_116PL    ~(1 << 15)
#else
#define  MG10_5_116PL    0xFFFF
#endif

#define  MG10_5_15PL	0xFFEF
#define  MG10_5    (MG10_5_11PL & MG10_5_12PL & MG10_5_13PL & MG10_5_14PL & \
                    MG10_5_15PL & MG10_5_16PL & MG10_5_17PL & MG10_5_18PL & \
                    MG10_5_19PL & MG10_5_110PL & MG10_5_111PL & MG10_5_112PL & \
                    MG10_5_113PL & MG10_5_114PL & MG10_5_115PL & MG10_5_116PL)
// End of MG10_5:
// Beginning of MG106:
#if (G10_1PL >= G10_6PL) || (G10_1PL == 0)
#define  MG10_6_11PL    ~(1 << 0)
#else
#define  MG10_6_11PL    0xFFFF
#endif

#if (G10_2PL >= G10_6PL) || (G10_2PL == 0)
#define  MG10_6_12PL    ~(1 << 1)
#else
#define  MG10_6_12PL    0xFFFF
#endif

#if (G10_3PL >= G10_6PL) || (G10_3PL == 0)
#define  MG10_6_13PL    ~(1 << 2)
#else
#define  MG10_6_13PL    0xFFFF
#endif

#if (G10_4PL >= G10_6PL) || (G10_4PL == 0)
#define  MG10_6_14PL    ~(1 << 3)
#else
#define  MG10_6_14PL    0xFFFF
#endif

#if (G10_5PL >= G10_6PL) || (G10_5PL == 0)
#define  MG10_6_15PL    ~(1 << 4)
#else
#define  MG10_6_15PL    0xFFFF
#endif

#if (G10_7PL >= G10_6PL) || (G10_7PL == 0)
#define  MG10_6_17PL    ~(1 << 6)
#else
#define  MG10_6_17PL    0xFFFF
#endif

#if (G10_8PL >= G10_6PL) || (G10_8PL == 0)
#define  MG10_6_18PL    ~(1 << 7)
#else
#define  MG10_6_18PL    0xFFFF
#endif

#if (G10_9PL >= G10_6PL) || (G10_9PL == 0)
#define  MG10_6_19PL    ~(1 << 8)
#else
#define  MG10_6_19PL    0xFFFF
#endif

#if (G10_10PL >= G10_6PL) || (G10_10PL == 0)
#define  MG10_6_110PL    ~(1 << 9)
#else
#define  MG10_6_110PL    0xFFFF
#endif

#if (G10_11PL >= G10_6PL) || (G10_11PL == 0)
#define  MG10_6_111PL    ~(1 << 10)
#else
#define  MG10_6_111PL    0xFFFF
#endif

#if (G10_12PL >= G10_6PL) || (G10_12PL == 0)
#define  MG10_6_112PL    ~(1 << 11)
#else
#define  MG10_6_112PL    0xFFFF
#endif

#if (G10_13PL >= G10_6PL) || (G10_13PL == 0)
#define  MG10_6_113PL    ~(1 << 12)
#else
#define  MG10_6_113PL    0xFFFF
#endif

#if (G10_14PL >= G10_6PL) || (G10_14PL == 0)
#define  MG10_6_114PL    ~(1 << 13)
#else
#define  MG10_6_114PL    0xFFFF
#endif

#if (G10_15PL >= G10_6PL) || (G10_15PL == 0)
#define  MG10_6_115PL    ~(1 << 14)
#else
#define  MG10_6_115PL    0xFFFF
#endif

#if (G10_16PL >= G10_6PL) || (G10_16PL == 0)
#define  MG10_6_116PL    ~(1 << 15)
#else
#define  MG10_6_116PL    0xFFFF
#endif

#define  MG10_6_16PL	0xFFDF
#define  MG10_6    (MG10_6_11PL & MG10_6_12PL & MG10_6_13PL & MG10_6_14PL & \
                    MG10_6_15PL & MG10_6_16PL & MG10_6_17PL & MG10_6_18PL & \
                    MG10_6_19PL & MG10_6_110PL & MG10_6_111PL & MG10_6_112PL & \
                    MG10_6_113PL & MG10_6_114PL & MG10_6_115PL & MG10_6_116PL)
// End of MG10_6:
// Beginning of MG107:
#if (G10_1PL >= G10_7PL) || (G10_1PL == 0)
#define  MG10_7_11PL    ~(1 << 0)
#else
#define  MG10_7_11PL    0xFFFF
#endif

#if (G10_2PL >= G10_7PL) || (G10_2PL == 0)
#define  MG10_7_12PL    ~(1 << 1)
#else
#define  MG10_7_12PL    0xFFFF
#endif

#if (G10_3PL >= G10_7PL) || (G10_3PL == 0)
#define  MG10_7_13PL    ~(1 << 2)
#else
#define  MG10_7_13PL    0xFFFF
#endif

#if (G10_4PL >= G10_7PL) || (G10_4PL == 0)
#define  MG10_7_14PL    ~(1 << 3)
#else
#define  MG10_7_14PL    0xFFFF
#endif

#if (G10_5PL >= G10_7PL) || (G10_5PL == 0)
#define  MG10_7_15PL    ~(1 << 4)
#else
#define  MG10_7_15PL    0xFFFF
#endif

#if (G10_6PL >= G10_7PL) || (G10_6PL == 0)
#define  MG10_7_16PL    ~(1 << 5)
#else
#define  MG10_7_16PL    0xFFFF
#endif

#if (G10_8PL >= G10_7PL) || (G10_8PL == 0)
#define  MG10_7_18PL    ~(1 << 7)
#else
#define  MG10_7_18PL    0xFFFF
#endif

#if (G10_9PL >= G10_7PL) || (G10_9PL == 0)
#define  MG10_7_19PL    ~(1 << 8)
#else
#define  MG10_7_19PL    0xFFFF
#endif

#if (G10_10PL >= G10_7PL) || (G10_10PL == 0)
#define  MG10_7_110PL    ~(1 << 9)
#else
#define  MG10_7_110PL    0xFFFF
#endif

#if (G10_11PL >= G10_7PL) || (G10_11PL == 0)
#define  MG10_7_111PL    ~(1 << 10)
#else
#define  MG10_7_111PL    0xFFFF
#endif

#if (G10_12PL >= G10_7PL) || (G10_12PL == 0)
#define  MG10_7_112PL    ~(1 << 11)
#else
#define  MG10_7_112PL    0xFFFF
#endif

#if (G10_13PL >= G10_7PL) || (G10_13PL == 0)
#define  MG10_7_113PL    ~(1 << 12)
#else
#define  MG10_7_113PL    0xFFFF
#endif

#if (G10_14PL >= G10_7PL) || (G10_14PL == 0)
#define  MG10_7_114PL    ~(1 << 13)
#else
#define  MG10_7_114PL    0xFFFF
#endif

#if (G10_15PL >= G10_7PL) || (G10_15PL == 0)
#define  MG10_7_115PL    ~(1 << 14)
#else
#define  MG10_7_115PL    0xFFFF
#endif

#if (G10_16PL >= G10_7PL) || (G10_16PL == 0)
#define  MG10_7_116PL    ~(1 << 15)
#else
#define  MG10_7_116PL    0xFFFF
#endif

#define  MG10_7_17PL	0xFFBF
#define  MG10_7    (MG10_7_11PL & MG10_7_12PL & MG10_7_13PL & MG10_7_14PL & \
                    MG10_7_15PL & MG10_7_16PL & MG10_7_17PL & MG10_7_18PL & \
                    MG10_7_19PL & MG10_7_110PL & MG10_7_111PL & MG10_7_112PL & \
                    MG10_7_113PL & MG10_7_114PL & MG10_7_115PL & MG10_7_116PL)
// End of MG10_7:
// Beginning of MG108:
#if (G10_1PL >= G10_8PL) || (G10_1PL == 0)
#define  MG10_8_11PL    ~(1 << 0)
#else
#define  MG10_8_11PL    0xFFFF
#endif

#if (G10_2PL >= G10_8PL) || (G10_2PL == 0)
#define  MG10_8_12PL    ~(1 << 1)
#else
#define  MG10_8_12PL    0xFFFF
#endif

#if (G10_3PL >= G10_8PL) || (G10_3PL == 0)
#define  MG10_8_13PL    ~(1 << 2)
#else
#define  MG10_8_13PL    0xFFFF
#endif

#if (G10_4PL >= G10_8PL) || (G10_4PL == 0)
#define  MG10_8_14PL    ~(1 << 3)
#else
#define  MG10_8_14PL    0xFFFF
#endif

#if (G10_5PL >= G10_8PL) || (G10_5PL == 0)
#define  MG10_8_15PL    ~(1 << 4)
#else
#define  MG10_8_15PL    0xFFFF
#endif

#if (G10_6PL >= G10_8PL) || (G10_6PL == 0)
#define  MG10_8_16PL    ~(1 << 5)
#else
#define  MG10_8_16PL    0xFFFF
#endif

#if (G10_7PL >= G10_8PL) || (G10_7PL == 0)
#define  MG10_8_17PL    ~(1 << 6)
#else
#define  MG10_8_17PL    0xFFFF
#endif

#if (G10_9PL >= G10_8PL) || (G10_9PL == 0)
#define  MG10_8_19PL    ~(1 << 8)
#else
#define  MG10_8_19PL    0xFFFF
#endif

#if (G10_10PL >= G10_8PL) || (G10_10PL == 0)
#define  MG10_8_110PL    ~(1 << 9)
#else
#define  MG10_8_110PL    0xFFFF
#endif

#if (G10_11PL >= G10_8PL) || (G10_11PL == 0)
#define  MG10_8_111PL    ~(1 << 10)
#else
#define  MG10_8_111PL    0xFFFF
#endif

#if (G10_12PL >= G10_8PL) || (G10_12PL == 0)
#define  MG10_8_112PL    ~(1 << 11)
#else
#define  MG10_8_112PL    0xFFFF
#endif

#if (G10_13PL >= G10_8PL) || (G10_13PL == 0)
#define  MG10_8_113PL    ~(1 << 12)
#else
#define  MG10_8_113PL    0xFFFF
#endif

#if (G10_14PL >= G10_8PL) || (G10_14PL == 0)
#define  MG10_8_114PL    ~(1 << 13)
#else
#define  MG10_8_114PL    0xFFFF
#endif

#if (G10_15PL >= G10_8PL) || (G10_15PL == 0)
#define  MG10_8_115PL    ~(1 << 14)
#else
#define  MG10_8_115PL    0xFFFF
#endif

#if (G10_16PL >= G10_8PL) || (G10_16PL == 0)
#define  MG10_8_116PL    ~(1 << 15)
#else
#define  MG10_8_116PL    0xFFFF
#endif

#define  MG10_8_18PL	0xFF7F
#define  MG10_8    (MG10_8_11PL & MG10_8_12PL & MG10_8_13PL & MG10_8_14PL & \
                    MG10_8_15PL & MG10_8_16PL & MG10_8_17PL & MG10_8_18PL & \
                    MG10_8_19PL & MG10_8_110PL & MG10_8_111PL & MG10_8_112PL & \
                    MG10_8_113PL & MG10_8_114PL & MG10_8_115PL & MG10_8_116PL)
// End of MG10_8:
// Beginning of MG109:
#if (G10_1PL >= G10_9PL) || (G10_1PL == 0)
#define  MG10_9_11PL    ~(1 << 0)
#else
#define  MG10_9_11PL    0xFFFF
#endif

#if (G10_2PL >= G10_9PL) || (G10_2PL == 0)
#define  MG10_9_12PL    ~(1 << 1)
#else
#define  MG10_9_12PL    0xFFFF
#endif

#if (G10_3PL >= G10_9PL) || (G10_3PL == 0)
#define  MG10_9_13PL    ~(1 << 2)
#else
#define  MG10_9_13PL    0xFFFF
#endif

#if (G10_4PL >= G10_9PL) || (G10_4PL == 0)
#define  MG10_9_14PL    ~(1 << 3)
#else
#define  MG10_9_14PL    0xFFFF
#endif

#if (G10_5PL >= G10_9PL) || (G10_5PL == 0)
#define  MG10_9_15PL    ~(1 << 4)
#else
#define  MG10_9_15PL    0xFFFF
#endif

#if (G10_6PL >= G10_9PL) || (G10_6PL == 0)
#define  MG10_9_16PL    ~(1 << 5)
#else
#define  MG10_9_16PL    0xFFFF
#endif

#if (G10_7PL >= G10_9PL) || (G10_7PL == 0)
#define  MG10_9_17PL    ~(1 << 6)
#else
#define  MG10_9_17PL    0xFFFF
#endif

#if (G10_8PL >= G10_9PL) || (G10_8PL == 0)
#define  MG10_9_18PL    ~(1 << 7)
#else
#define  MG10_9_18PL    0xFFFF
#endif

#if (G10_10PL >= G10_9PL) || (G10_10PL == 0)
#define  MG10_9_110PL    ~(1 << 9)
#else
#define  MG10_9_110PL    0xFFFF
#endif

#if (G10_11PL >= G10_9PL) || (G10_11PL == 0)
#define  MG10_9_111PL    ~(1 << 10)
#else
#define  MG10_9_111PL    0xFFFF
#endif

#if (G10_12PL >= G10_9PL) || (G10_12PL == 0)
#define  MG10_9_112PL    ~(1 << 11)
#else
#define  MG10_9_112PL    0xFFFF
#endif

#if (G10_13PL >= G10_9PL) || (G10_13PL == 0)
#define  MG10_9_113PL    ~(1 << 12)
#else
#define  MG10_9_113PL    0xFFFF
#endif

#if (G10_14PL >= G10_9PL) || (G10_14PL == 0)
#define  MG10_9_114PL    ~(1 << 13)
#else
#define  MG10_9_114PL    0xFFFF
#endif

#if (G10_15PL >= G10_9PL) || (G10_15PL == 0)
#define  MG10_9_115PL    ~(1 << 14)
#else
#define  MG10_9_115PL    0xFFFF
#endif

#if (G10_16PL >= G10_9PL) || (G10_16PL == 0)
#define  MG10_9_116PL    ~(1 << 15)
#else
#define  MG10_9_116PL    0xFFFF
#endif

#define  MG10_9_19PL	0xFEFF
#define  MG10_9    (MG10_9_11PL & MG10_9_12PL & MG10_9_13PL & MG10_9_14PL & \
                    MG10_9_15PL & MG10_9_16PL & MG10_9_17PL & MG10_9_18PL & \
                    MG10_9_19PL & MG10_9_110PL & MG10_9_111PL & MG10_9_112PL & \
                    MG10_9_113PL & MG10_9_114PL & MG10_9_115PL & MG10_9_116PL)
// End of MG10_9:
// Beginning of MG1010:
#if (G10_1PL >= G10_10PL) || (G10_1PL == 0)
#define  MG10_10_11PL    ~(1 << 0)
#else
#define  MG10_10_11PL    0xFFFF
#endif

#if (G10_2PL >= G10_10PL) || (G10_2PL == 0)
#define  MG10_10_12PL    ~(1 << 1)
#else
#define  MG10_10_12PL    0xFFFF
#endif

#if (G10_3PL >= G10_10PL) || (G10_3PL == 0)
#define  MG10_10_13PL    ~(1 << 2)
#else
#define  MG10_10_13PL    0xFFFF
#endif

#if (G10_4PL >= G10_10PL) || (G10_4PL == 0)
#define  MG10_10_14PL    ~(1 << 3)
#else
#define  MG10_10_14PL    0xFFFF
#endif

#if (G10_5PL >= G10_10PL) || (G10_5PL == 0)
#define  MG10_10_15PL    ~(1 << 4)
#else
#define  MG10_10_15PL    0xFFFF
#endif

#if (G10_6PL >= G10_10PL) || (G10_6PL == 0)
#define  MG10_10_16PL    ~(1 << 5)
#else
#define  MG10_10_16PL    0xFFFF
#endif

#if (G10_7PL >= G10_10PL) || (G10_7PL == 0)
#define  MG10_10_17PL    ~(1 << 6)
#else
#define  MG10_10_17PL    0xFFFF
#endif

#if (G10_8PL >= G10_10PL) || (G10_8PL == 0)
#define  MG10_10_18PL    ~(1 << 7)
#else
#define  MG10_10_18PL    0xFFFF
#endif

#if (G10_9PL >= G10_10PL) || (G10_9PL == 0)
#define  MG10_10_19PL    ~(1 << 8)
#else
#define  MG10_10_19PL    0xFFFF
#endif

#if (G10_11PL >= G10_10PL) || (G10_11PL == 0)
#define  MG10_10_111PL    ~(1 << 10)
#else
#define  MG10_10_111PL    0xFFFF
#endif

#if (G10_12PL >= G10_10PL) || (G10_12PL == 0)
#define  MG10_10_112PL    ~(1 << 11)
#else
#define  MG10_10_112PL    0xFFFF
#endif

#if (G10_13PL >= G10_10PL) || (G10_13PL == 0)
#define  MG10_10_113PL    ~(1 << 12)
#else
#define  MG10_10_113PL    0xFFFF
#endif

#if (G10_14PL >= G10_10PL) || (G10_14PL == 0)
#define  MG10_10_114PL    ~(1 << 13)
#else
#define  MG10_10_114PL    0xFFFF
#endif

#if (G10_15PL >= G10_10PL) || (G10_15PL == 0)
#define  MG10_10_115PL    ~(1 << 14)
#else
#define  MG10_10_115PL    0xFFFF
#endif

#if (G10_16PL >= G10_10PL) || (G10_16PL == 0)
#define  MG10_10_116PL    ~(1 << 15)
#else
#define  MG10_10_116PL    0xFFFF
#endif

#define  MG10_10_110PL	0xFDFF
#define  MG10_10    (MG10_10_11PL & MG10_10_12PL & MG10_10_13PL & MG10_10_14PL & \
                    MG10_10_15PL & MG10_10_16PL & MG10_10_17PL & MG10_10_18PL & \
                    MG10_10_19PL & MG10_10_110PL & MG10_10_111PL & MG10_10_112PL & \
                    MG10_10_113PL & MG10_10_114PL & MG10_10_115PL & MG10_10_116PL)
// End of MG10_10:
// Beginning of MG1011:
#if (G10_1PL >= G10_11PL) || (G10_1PL == 0)
#define  MG10_11_11PL    ~(1 << 0)
#else
#define  MG10_11_11PL    0xFFFF
#endif

#if (G10_2PL >= G10_11PL) || (G10_2PL == 0)
#define  MG10_11_12PL    ~(1 << 1)
#else
#define  MG10_11_12PL    0xFFFF
#endif

#if (G10_3PL >= G10_11PL) || (G10_3PL == 0)
#define  MG10_11_13PL    ~(1 << 2)
#else
#define  MG10_11_13PL    0xFFFF
#endif

#if (G10_4PL >= G10_11PL) || (G10_4PL == 0)
#define  MG10_11_14PL    ~(1 << 3)
#else
#define  MG10_11_14PL    0xFFFF
#endif

#if (G10_5PL >= G10_11PL) || (G10_5PL == 0)
#define  MG10_11_15PL    ~(1 << 4)
#else
#define  MG10_11_15PL    0xFFFF
#endif

#if (G10_6PL >= G10_11PL) || (G10_6PL == 0)
#define  MG10_11_16PL    ~(1 << 5)
#else
#define  MG10_11_16PL    0xFFFF
#endif

#if (G10_7PL >= G10_11PL) || (G10_7PL == 0)
#define  MG10_11_17PL    ~(1 << 6)
#else
#define  MG10_11_17PL    0xFFFF
#endif

#if (G10_8PL >= G10_11PL) || (G10_8PL == 0)
#define  MG10_11_18PL    ~(1 << 7)
#else
#define  MG10_11_18PL    0xFFFF
#endif

#if (G10_9PL >= G10_11PL) || (G10_9PL == 0)
#define  MG10_11_19PL    ~(1 << 8)
#else
#define  MG10_11_19PL    0xFFFF
#endif

#if (G10_10PL >= G10_11PL) || (G10_10PL == 0)
#define  MG10_11_110PL    ~(1 << 9)
#else
#define  MG10_11_110PL    0xFFFF
#endif

#if (G10_12PL >= G10_11PL) || (G10_12PL == 0)
#define  MG10_11_112PL    ~(1 << 11)
#else
#define  MG10_11_112PL    0xFFFF
#endif

#if (G10_13PL >= G10_11PL) || (G10_13PL == 0)
#define  MG10_11_113PL    ~(1 << 12)
#else
#define  MG10_11_113PL    0xFFFF
#endif

#if (G10_14PL >= G10_11PL) || (G10_14PL == 0)
#define  MG10_11_114PL    ~(1 << 13)
#else
#define  MG10_11_114PL    0xFFFF
#endif

#if (G10_15PL >= G10_11PL) || (G10_15PL == 0)
#define  MG10_11_115PL    ~(1 << 14)
#else
#define  MG10_11_115PL    0xFFFF
#endif

#if (G10_16PL >= G10_11PL) || (G10_16PL == 0)
#define  MG10_11_116PL    ~(1 << 15)
#else
#define  MG10_11_116PL    0xFFFF
#endif

#define  MG10_11_111PL	0xFBFF
#define  MG10_11    (MG10_11_11PL & MG10_11_12PL & MG10_11_13PL & MG10_11_14PL & \
                    MG10_11_15PL & MG10_11_16PL & MG10_11_17PL & MG10_11_18PL & \
                    MG10_11_19PL & MG10_11_110PL & MG10_11_111PL & MG10_11_112PL & \
                    MG10_11_113PL & MG10_11_114PL & MG10_11_115PL & MG10_11_116PL)
// End of MG10_11:
// Beginning of MG1012:
#if (G10_1PL >= G10_12PL) || (G10_1PL == 0)
#define  MG10_12_11PL    ~(1 << 0)
#else
#define  MG10_12_11PL    0xFFFF
#endif

#if (G10_2PL >= G10_12PL) || (G10_2PL == 0)
#define  MG10_12_12PL    ~(1 << 1)
#else
#define  MG10_12_12PL    0xFFFF
#endif

#if (G10_3PL >= G10_12PL) || (G10_3PL == 0)
#define  MG10_12_13PL    ~(1 << 2)
#else
#define  MG10_12_13PL    0xFFFF
#endif

#if (G10_4PL >= G10_12PL) || (G10_4PL == 0)
#define  MG10_12_14PL    ~(1 << 3)
#else
#define  MG10_12_14PL    0xFFFF
#endif

#if (G10_5PL >= G10_12PL) || (G10_5PL == 0)
#define  MG10_12_15PL    ~(1 << 4)
#else
#define  MG10_12_15PL    0xFFFF
#endif

#if (G10_6PL >= G10_12PL) || (G10_6PL == 0)
#define  MG10_12_16PL    ~(1 << 5)
#else
#define  MG10_12_16PL    0xFFFF
#endif

#if (G10_7PL >= G10_12PL) || (G10_7PL == 0)
#define  MG10_12_17PL    ~(1 << 6)
#else
#define  MG10_12_17PL    0xFFFF
#endif

#if (G10_8PL >= G10_12PL) || (G10_8PL == 0)
#define  MG10_12_18PL    ~(1 << 7)
#else
#define  MG10_12_18PL    0xFFFF
#endif

#if (G10_9PL >= G10_12PL) || (G10_9PL == 0)
#define  MG10_12_19PL    ~(1 << 8)
#else
#define  MG10_12_19PL    0xFFFF
#endif

#if (G10_10PL >= G10_12PL) || (G10_10PL == 0)
#define  MG10_12_110PL    ~(1 << 9)
#else
#define  MG10_12_110PL    0xFFFF
#endif

#if (G10_11PL >= G10_12PL) || (G10_11PL == 0)
#define  MG10_12_111PL    ~(1 << 10)
#else
#define  MG10_12_111PL    0xFFFF
#endif

#if (G10_13PL >= G10_12PL) || (G10_13PL == 0)
#define  MG10_12_113PL    ~(1 << 12)
#else
#define  MG10_12_113PL    0xFFFF
#endif

#if (G10_14PL >= G10_12PL) || (G10_14PL == 0)
#define  MG10_12_114PL    ~(1 << 13)
#else
#define  MG10_12_114PL    0xFFFF
#endif

#if (G10_15PL >= G10_12PL) || (G10_15PL == 0)
#define  MG10_12_115PL    ~(1 << 14)
#else
#define  MG10_12_115PL    0xFFFF
#endif

#if (G10_16PL >= G10_12PL) || (G10_16PL == 0)
#define  MG10_12_116PL    ~(1 << 15)
#else
#define  MG10_12_116PL    0xFFFF
#endif

#define  MG10_12_112PL	0xF7FF
#define  MG10_12    (MG10_12_11PL & MG10_12_12PL & MG10_12_13PL & MG10_12_14PL & \
                    MG10_12_15PL & MG10_12_16PL & MG10_12_17PL & MG10_12_18PL & \
                    MG10_12_19PL & MG10_12_110PL & MG10_12_111PL & MG10_12_112PL & \
                    MG10_12_113PL & MG10_12_114PL & MG10_12_115PL & MG10_12_116PL)
// End of MG10_12:
// Beginning of MG1013:
#if (G10_1PL >= G10_13PL) || (G10_1PL == 0)
#define  MG10_13_11PL    ~(1 << 0)
#else
#define  MG10_13_11PL    0xFFFF
#endif

#if (G10_2PL >= G10_13PL) || (G10_2PL == 0)
#define  MG10_13_12PL    ~(1 << 1)
#else
#define  MG10_13_12PL    0xFFFF
#endif

#if (G10_3PL >= G10_13PL) || (G10_3PL == 0)
#define  MG10_13_13PL    ~(1 << 2)
#else
#define  MG10_13_13PL    0xFFFF
#endif

#if (G10_4PL >= G10_13PL) || (G10_4PL == 0)
#define  MG10_13_14PL    ~(1 << 3)
#else
#define  MG10_13_14PL    0xFFFF
#endif

#if (G10_5PL >= G10_13PL) || (G10_5PL == 0)
#define  MG10_13_15PL    ~(1 << 4)
#else
#define  MG10_13_15PL    0xFFFF
#endif

#if (G10_6PL >= G10_13PL) || (G10_6PL == 0)
#define  MG10_13_16PL    ~(1 << 5)
#else
#define  MG10_13_16PL    0xFFFF
#endif

#if (G10_7PL >= G10_13PL) || (G10_7PL == 0)
#define  MG10_13_17PL    ~(1 << 6)
#else
#define  MG10_13_17PL    0xFFFF
#endif

#if (G10_8PL >= G10_13PL) || (G10_8PL == 0)
#define  MG10_13_18PL    ~(1 << 7)
#else
#define  MG10_13_18PL    0xFFFF
#endif

#if (G10_9PL >= G10_13PL) || (G10_9PL == 0)
#define  MG10_13_19PL    ~(1 << 8)
#else
#define  MG10_13_19PL    0xFFFF
#endif

#if (G10_10PL >= G10_13PL) || (G10_10PL == 0)
#define  MG10_13_110PL    ~(1 << 9)
#else
#define  MG10_13_110PL    0xFFFF
#endif

#if (G10_11PL >= G10_13PL) || (G10_11PL == 0)
#define  MG10_13_111PL    ~(1 << 10)
#else
#define  MG10_13_111PL    0xFFFF
#endif

#if (G10_12PL >= G10_13PL) || (G10_12PL == 0)
#define  MG10_13_112PL    ~(1 << 11)
#else
#define  MG10_13_112PL    0xFFFF
#endif

#if (G10_14PL >= G10_13PL) || (G10_14PL == 0)
#define  MG10_13_114PL    ~(1 << 13)
#else
#define  MG10_13_114PL    0xFFFF
#endif

#if (G10_15PL >= G10_13PL) || (G10_15PL == 0)
#define  MG10_13_115PL    ~(1 << 14)
#else
#define  MG10_13_115PL    0xFFFF
#endif

#if (G10_16PL >= G10_13PL) || (G10_16PL == 0)
#define  MG10_13_116PL    ~(1 << 15)
#else
#define  MG10_13_116PL    0xFFFF
#endif

#define  MG10_13_113PL	0xEFFF
#define  MG10_13    (MG10_13_11PL & MG10_13_12PL & MG10_13_13PL & MG10_13_14PL & \
                    MG10_13_15PL & MG10_13_16PL & MG10_13_17PL & MG10_13_18PL & \
                    MG10_13_19PL & MG10_13_110PL & MG10_13_111PL & MG10_13_112PL & \
                    MG10_13_113PL & MG10_13_114PL & MG10_13_115PL & MG10_13_116PL)
// End of MG10_13:
// Beginning of MG1014:
#if (G10_1PL >= G10_14PL) || (G10_1PL == 0)
#define  MG10_14_11PL    ~(1 << 0)
#else
#define  MG10_14_11PL    0xFFFF
#endif

#if (G10_2PL >= G10_14PL) || (G10_2PL == 0)
#define  MG10_14_12PL    ~(1 << 1)
#else
#define  MG10_14_12PL    0xFFFF
#endif

#if (G10_3PL >= G10_14PL) || (G10_3PL == 0)
#define  MG10_14_13PL    ~(1 << 2)
#else
#define  MG10_14_13PL    0xFFFF
#endif

#if (G10_4PL >= G10_14PL) || (G10_4PL == 0)
#define  MG10_14_14PL    ~(1 << 3)
#else
#define  MG10_14_14PL    0xFFFF
#endif

#if (G10_5PL >= G10_14PL) || (G10_5PL == 0)
#define  MG10_14_15PL    ~(1 << 4)
#else
#define  MG10_14_15PL    0xFFFF
#endif

#if (G10_6PL >= G10_14PL) || (G10_6PL == 0)
#define  MG10_14_16PL    ~(1 << 5)
#else
#define  MG10_14_16PL    0xFFFF
#endif

#if (G10_7PL >= G10_14PL) || (G10_7PL == 0)
#define  MG10_14_17PL    ~(1 << 6)
#else
#define  MG10_14_17PL    0xFFFF
#endif

#if (G10_8PL >= G10_14PL) || (G10_8PL == 0)
#define  MG10_14_18PL    ~(1 << 7)
#else
#define  MG10_14_18PL    0xFFFF
#endif

#if (G10_9PL >= G10_14PL) || (G10_9PL == 0)
#define  MG10_14_19PL    ~(1 << 8)
#else
#define  MG10_14_19PL    0xFFFF
#endif

#if (G10_10PL >= G10_14PL) || (G10_10PL == 0)
#define  MG10_14_110PL    ~(1 << 9)
#else
#define  MG10_14_110PL    0xFFFF
#endif

#if (G10_11PL >= G10_14PL) || (G10_11PL == 0)
#define  MG10_14_111PL    ~(1 << 10)
#else
#define  MG10_14_111PL    0xFFFF
#endif

#if (G10_12PL >= G10_14PL) || (G10_12PL == 0)
#define  MG10_14_112PL    ~(1 << 11)
#else
#define  MG10_14_112PL    0xFFFF
#endif

#if (G10_13PL >= G10_14PL) || (G10_13PL == 0)
#define  MG10_14_113PL    ~(1 << 12)
#else
#define  MG10_14_113PL    0xFFFF
#endif

#if (G10_15PL >= G10_14PL) || (G10_15PL == 0)
#define  MG10_14_115PL    ~(1 << 14)
#else
#define  MG10_14_115PL    0xFFFF
#endif

#if (G10_16PL >= G10_14PL) || (G10_16PL == 0)
#define  MG10_14_116PL    ~(1 << 15)
#else
#define  MG10_14_116PL    0xFFFF
#endif

#define  MG10_14_114PL	0xDFFF
#define  MG10_14    (MG10_14_11PL & MG10_14_12PL & MG10_14_13PL & MG10_14_14PL & \
                    MG10_14_15PL & MG10_14_16PL & MG10_14_17PL & MG10_14_18PL & \
                    MG10_14_19PL & MG10_14_110PL & MG10_14_111PL & MG10_14_112PL & \
                    MG10_14_113PL & MG10_14_114PL & MG10_14_115PL & MG10_14_116PL)
// End of MG10_14:
// Beginning of MG1015:
#if (G10_1PL >= G10_15PL) || (G10_1PL == 0)
#define  MG10_15_11PL    ~(1 << 0)
#else
#define  MG10_15_11PL    0xFFFF
#endif

#if (G10_2PL >= G10_15PL) || (G10_2PL == 0)
#define  MG10_15_12PL    ~(1 << 1)
#else
#define  MG10_15_12PL    0xFFFF
#endif

#if (G10_3PL >= G10_15PL) || (G10_3PL == 0)
#define  MG10_15_13PL    ~(1 << 2)
#else
#define  MG10_15_13PL    0xFFFF
#endif

#if (G10_4PL >= G10_15PL) || (G10_4PL == 0)
#define  MG10_15_14PL    ~(1 << 3)
#else
#define  MG10_15_14PL    0xFFFF
#endif

#if (G10_5PL >= G10_15PL) || (G10_5PL == 0)
#define  MG10_15_15PL    ~(1 << 4)
#else
#define  MG10_15_15PL    0xFFFF
#endif

#if (G10_6PL >= G10_15PL) || (G10_6PL == 0)
#define  MG10_15_16PL    ~(1 << 5)
#else
#define  MG10_15_16PL    0xFFFF
#endif

#if (G10_7PL >= G10_15PL) || (G10_7PL == 0)
#define  MG10_15_17PL    ~(1 << 6)
#else
#define  MG10_15_17PL    0xFFFF
#endif

#if (G10_8PL >= G10_15PL) || (G10_8PL == 0)
#define  MG10_15_18PL    ~(1 << 7)
#else
#define  MG10_15_18PL    0xFFFF
#endif

#if (G10_9PL >= G10_15PL) || (G10_9PL == 0)
#define  MG10_15_19PL    ~(1 << 8)
#else
#define  MG10_15_19PL    0xFFFF
#endif

#if (G10_10PL >= G10_15PL) || (G10_10PL == 0)
#define  MG10_15_110PL    ~(1 << 9)
#else
#define  MG10_15_110PL    0xFFFF
#endif

#if (G10_11PL >= G10_15PL) || (G10_11PL == 0)
#define  MG10_15_111PL    ~(1 << 10)
#else
#define  MG10_15_111PL    0xFFFF
#endif

#if (G10_12PL >= G10_15PL) || (G10_12PL == 0)
#define  MG10_15_112PL    ~(1 << 11)
#else
#define  MG10_15_112PL    0xFFFF
#endif

#if (G10_13PL >= G10_15PL) || (G10_13PL == 0)
#define  MG10_15_113PL    ~(1 << 12)
#else
#define  MG10_15_113PL    0xFFFF
#endif

#if (G10_14PL >= G10_15PL) || (G10_14PL == 0)
#define  MG10_15_114PL    ~(1 << 13)
#else
#define  MG10_15_114PL    0xFFFF
#endif

#if (G10_16PL >= G10_15PL) || (G10_16PL == 0)
#define  MG10_15_116PL    ~(1 << 15)
#else
#define  MG10_15_116PL    0xFFFF
#endif

#define  MG10_15_115PL	0xBFFF
#define  MG10_15    (MG10_15_11PL & MG10_15_12PL & MG10_15_13PL & MG10_15_14PL & \
                    MG10_15_15PL & MG10_15_16PL & MG10_15_17PL & MG10_15_18PL & \
                    MG10_15_19PL & MG10_15_110PL & MG10_15_111PL & MG10_15_112PL & \
                    MG10_15_113PL & MG10_15_114PL & MG10_15_115PL & MG10_15_116PL)
// End of MG10_15:
// Beginning of MG1016:
#if (G10_1PL >= G10_16PL) || (G10_1PL == 0)
#define  MG10_16_11PL    ~(1 << 0)
#else
#define  MG10_16_11PL    0xFFFF
#endif

#if (G10_2PL >= G10_16PL) || (G10_2PL == 0)
#define  MG10_16_12PL    ~(1 << 1)
#else
#define  MG10_16_12PL    0xFFFF
#endif

#if (G10_3PL >= G10_16PL) || (G10_3PL == 0)
#define  MG10_16_13PL    ~(1 << 2)
#else
#define  MG10_16_13PL    0xFFFF
#endif

#if (G10_4PL >= G10_16PL) || (G10_4PL == 0)
#define  MG10_16_14PL    ~(1 << 3)
#else
#define  MG10_16_14PL    0xFFFF
#endif

#if (G10_5PL >= G10_16PL) || (G10_5PL == 0)
#define  MG10_16_15PL    ~(1 << 4)
#else
#define  MG10_16_15PL    0xFFFF
#endif

#if (G10_6PL >= G10_16PL) || (G10_6PL == 0)
#define  MG10_16_16PL    ~(1 << 5)
#else
#define  MG10_16_16PL    0xFFFF
#endif

#if (G10_7PL >= G10_16PL) || (G10_7PL == 0)
#define  MG10_16_17PL    ~(1 << 6)
#else
#define  MG10_16_17PL    0xFFFF
#endif

#if (G10_8PL >= G10_16PL) || (G10_8PL == 0)
#define  MG10_16_18PL    ~(1 << 7)
#else
#define  MG10_16_18PL    0xFFFF
#endif

#if (G10_9PL >= G10_16PL) || (G10_9PL == 0)
#define  MG10_16_19PL    ~(1 << 8)
#else
#define  MG10_16_19PL    0xFFFF
#endif

#if (G10_10PL >= G10_16PL) || (G10_10PL == 0)
#define  MG10_16_110PL    ~(1 << 9)
#else
#define  MG10_16_110PL    0xFFFF
#endif

#if (G10_11PL >= G10_16PL) || (G10_11PL == 0)
#define  MG10_16_111PL    ~(1 << 10)
#else
#define  MG10_16_111PL    0xFFFF
#endif

#if (G10_12PL >= G10_16PL) || (G10_12PL == 0)
#define  MG10_16_112PL    ~(1 << 11)
#else
#define  MG10_16_112PL    0xFFFF
#endif

#if (G10_13PL >= G10_16PL) || (G10_13PL == 0)
#define  MG10_16_113PL    ~(1 << 12)
#else
#define  MG10_16_113PL    0xFFFF
#endif

#if (G10_14PL >= G10_16PL) || (G10_14PL == 0)
#define  MG10_16_114PL    ~(1 << 13)
#else
#define  MG10_16_114PL    0xFFFF
#endif

#if (G10_15PL >= G10_16PL) || (G10_15PL == 0)
#define  MG10_16_115PL    ~(1 << 14)
#else
#define  MG10_16_115PL    0xFFFF
#endif

#define  MG10_16_116PL	0x7FFF
#define  MG10_16    (MG10_16_11PL & MG10_16_12PL & MG10_16_13PL & MG10_16_14PL & \
                    MG10_16_15PL & MG10_16_16PL & MG10_16_17PL & MG10_16_18PL & \
                    MG10_16_19PL & MG10_16_110PL & MG10_16_111PL & MG10_16_112PL & \
                    MG10_16_113PL & MG10_16_114PL & MG10_16_115PL & MG10_16_116PL)
// End of MG10_16:


//-------------------------------------------------------------------------------
// Automatically generate PIEIER11 interrupt masks MG111 to MG1116:

// Beginning of MG111:
#if (G11_2PL >= G11_1PL) || (G11_2PL == 0)
#define  MG11_1_12PL    ~(1 << 1)
#else
#define  MG11_1_12PL    0xFFFF
#endif

#if (G11_3PL >= G11_1PL) || (G11_3PL == 0)
#define  MG11_1_13PL    ~(1 << 2)
#else
#define  MG11_1_13PL    0xFFFF
#endif

#if (G11_4PL >= G11_1PL) || (G11_4PL == 0)
#define  MG11_1_14PL    ~(1 << 3)
#else
#define  MG11_1_14PL    0xFFFF
#endif

#if (G11_5PL >= G11_1PL) || (G11_5PL == 0)
#define  MG11_1_15PL    ~(1 << 4)
#else
#define  MG11_1_15PL    0xFFFF
#endif

#if (G11_6PL >= G11_1PL) || (G11_6PL == 0)
#define  MG11_1_16PL    ~(1 << 5)
#else
#define  MG11_1_16PL    0xFFFF
#endif

#if (G11_7PL >= G11_1PL) || (G11_7PL == 0)
#define  MG11_1_17PL    ~(1 << 6)
#else
#define  MG11_1_17PL    0xFFFF
#endif

#if (G11_8PL >= G11_1PL) || (G11_8PL == 0)
#define  MG11_1_18PL    ~(1 << 7)
#else
#define  MG11_1_18PL    0xFFFF
#endif

#if (G11_9PL >= G11_1PL) || (G11_9PL == 0)
#define  MG11_1_19PL    ~(1 << 8)
#else
#define  MG11_1_19PL    0xFFFF
#endif

#if (G11_10PL >= G11_1PL) || (G11_10PL == 0)
#define  MG11_1_110PL    ~(1 << 9)
#else
#define  MG11_1_110PL    0xFFFF
#endif

#if (G11_11PL >= G11_1PL) || (G11_11PL == 0)
#define  MG11_1_111PL    ~(1 << 10)
#else
#define  MG11_1_111PL    0xFFFF
#endif

#if (G11_12PL >= G11_1PL) || (G11_12PL == 0)
#define  MG11_1_112PL    ~(1 << 11)
#else
#define  MG11_1_112PL    0xFFFF
#endif

#if (G11_13PL >= G11_1PL) || (G11_13PL == 0)
#define  MG11_1_113PL    ~(1 << 12)
#else
#define  MG11_1_113PL    0xFFFF
#endif

#if (G11_14PL >= G11_1PL) || (G11_14PL == 0)
#define  MG11_1_114PL    ~(1 << 13)
#else
#define  MG11_1_114PL    0xFFFF
#endif

#if (G11_15PL >= G11_1PL) || (G11_15PL == 0)
#define  MG11_1_115PL    ~(1 << 14)
#else
#define  MG11_1_115PL    0xFFFF
#endif

#if (G11_16PL >= G11_1PL) || (G11_16PL == 0)
#define  MG11_1_116PL    ~(1 << 15)
#else
#define  MG11_1_116PL    0xFFFF
#endif

#define  MG11_1_11PL	0xFFFE
#define  MG11_1    (MG11_1_11PL & MG11_1_12PL & MG11_1_13PL & MG11_1_14PL & \
                    MG11_1_15PL & MG11_1_16PL & MG11_1_17PL & MG11_1_18PL & \
                    MG11_1_19PL & MG11_1_110PL & MG11_1_111PL & MG11_1_112PL & \
                    MG11_1_113PL & MG11_1_114PL & MG11_1_115PL & MG11_1_116PL)
// End of MG11_1:
// Beginning of MG112:
#if (G11_1PL >= G11_2PL) || (G11_1PL == 0)
#define  MG11_2_11PL    ~(1 << 0)
#else
#define  MG11_2_11PL    0xFFFF
#endif

#if (G11_3PL >= G11_2PL) || (G11_3PL == 0)
#define  MG11_2_13PL    ~(1 << 2)
#else
#define  MG11_2_13PL    0xFFFF
#endif

#if (G11_4PL >= G11_2PL) || (G11_4PL == 0)
#define  MG11_2_14PL    ~(1 << 3)
#else
#define  MG11_2_14PL    0xFFFF
#endif

#if (G11_5PL >= G11_2PL) || (G11_5PL == 0)
#define  MG11_2_15PL    ~(1 << 4)
#else
#define  MG11_2_15PL    0xFFFF
#endif

#if (G11_6PL >= G11_2PL) || (G11_6PL == 0)
#define  MG11_2_16PL    ~(1 << 5)
#else
#define  MG11_2_16PL    0xFFFF
#endif

#if (G11_7PL >= G11_2PL) || (G11_7PL == 0)
#define  MG11_2_17PL    ~(1 << 6)
#else
#define  MG11_2_17PL    0xFFFF
#endif

#if (G11_8PL >= G11_2PL) || (G11_8PL == 0)
#define  MG11_2_18PL    ~(1 << 7)
#else
#define  MG11_2_18PL    0xFFFF
#endif

#if (G11_9PL >= G11_2PL) || (G11_9PL == 0)
#define  MG11_2_19PL    ~(1 << 8)
#else
#define  MG11_2_19PL    0xFFFF
#endif

#if (G11_10PL >= G11_2PL) || (G11_10PL == 0)
#define  MG11_2_110PL    ~(1 << 9)
#else
#define  MG11_2_110PL    0xFFFF
#endif

#if (G11_11PL >= G11_2PL) || (G11_11PL == 0)
#define  MG11_2_111PL    ~(1 << 10)
#else
#define  MG11_2_111PL    0xFFFF
#endif

#if (G11_12PL >= G11_2PL) || (G11_12PL == 0)
#define  MG11_2_112PL    ~(1 << 11)
#else
#define  MG11_2_112PL    0xFFFF
#endif

#if (G11_13PL >= G11_2PL) || (G11_13PL == 0)
#define  MG11_2_113PL    ~(1 << 12)
#else
#define  MG11_2_113PL    0xFFFF
#endif

#if (G11_14PL >= G11_2PL) || (G11_14PL == 0)
#define  MG11_2_114PL    ~(1 << 13)
#else
#define  MG11_2_114PL    0xFFFF
#endif

#if (G11_15PL >= G11_2PL) || (G11_15PL == 0)
#define  MG11_2_115PL    ~(1 << 14)
#else
#define  MG11_2_115PL    0xFFFF
#endif

#if (G11_16PL >= G11_2PL) || (G11_16PL == 0)
#define  MG11_2_116PL    ~(1 << 15)
#else
#define  MG11_2_116PL    0xFFFF
#endif

#define  MG11_2_12PL	0xFFFD
#define  MG11_2    (MG11_2_11PL & MG11_2_12PL & MG11_2_13PL & MG11_2_14PL & \
                    MG11_2_15PL & MG11_2_16PL & MG11_2_17PL & MG11_2_18PL & \
                    MG11_2_19PL & MG11_2_110PL & MG11_2_111PL & MG11_2_112PL & \
                    MG11_2_113PL & MG11_2_114PL & MG11_2_115PL & MG11_2_116PL)
// End of MG11_2:
// Beginning of MG113:
#if (G11_1PL >= G11_3PL) || (G11_1PL == 0)
#define  MG11_3_11PL    ~(1 << 0)
#else
#define  MG11_3_11PL    0xFFFF
#endif

#if (G11_2PL >= G11_3PL) || (G11_2PL == 0)
#define  MG11_3_12PL    ~(1 << 1)
#else
#define  MG11_3_12PL    0xFFFF
#endif

#if (G11_4PL >= G11_3PL) || (G11_4PL == 0)
#define  MG11_3_14PL    ~(1 << 3)
#else
#define  MG11_3_14PL    0xFFFF
#endif

#if (G11_5PL >= G11_3PL) || (G11_5PL == 0)
#define  MG11_3_15PL    ~(1 << 4)
#else
#define  MG11_3_15PL    0xFFFF
#endif

#if (G11_6PL >= G11_3PL) || (G11_6PL == 0)
#define  MG11_3_16PL    ~(1 << 5)
#else
#define  MG11_3_16PL    0xFFFF
#endif

#if (G11_7PL >= G11_3PL) || (G11_7PL == 0)
#define  MG11_3_17PL    ~(1 << 6)
#else
#define  MG11_3_17PL    0xFFFF
#endif

#if (G11_8PL >= G11_3PL) || (G11_8PL == 0)
#define  MG11_3_18PL    ~(1 << 7)
#else
#define  MG11_3_18PL    0xFFFF
#endif

#if (G11_9PL >= G11_3PL) || (G11_9PL == 0)
#define  MG11_3_19PL    ~(1 << 8)
#else
#define  MG11_3_19PL    0xFFFF
#endif

#if (G11_10PL >= G11_3PL) || (G11_10PL == 0)
#define  MG11_3_110PL    ~(1 << 9)
#else
#define  MG11_3_110PL    0xFFFF
#endif

#if (G11_11PL >= G11_3PL) || (G11_11PL == 0)
#define  MG11_3_111PL    ~(1 << 10)
#else
#define  MG11_3_111PL    0xFFFF
#endif

#if (G11_12PL >= G11_3PL) || (G11_12PL == 0)
#define  MG11_3_112PL    ~(1 << 11)
#else
#define  MG11_3_112PL    0xFFFF
#endif

#if (G11_13PL >= G11_3PL) || (G11_13PL == 0)
#define  MG11_3_113PL    ~(1 << 12)
#else
#define  MG11_3_113PL    0xFFFF
#endif

#if (G11_14PL >= G11_3PL) || (G11_14PL == 0)
#define  MG11_3_114PL    ~(1 << 13)
#else
#define  MG11_3_114PL    0xFFFF
#endif

#if (G11_15PL >= G11_3PL) || (G11_15PL == 0)
#define  MG11_3_115PL    ~(1 << 14)
#else
#define  MG11_3_115PL    0xFFFF
#endif

#if (G11_16PL >= G11_3PL) || (G11_16PL == 0)
#define  MG11_3_116PL    ~(1 << 15)
#else
#define  MG11_3_116PL    0xFFFF
#endif

#define  MG11_3_13PL	0xFFFB
#define  MG11_3    (MG11_3_11PL & MG11_3_12PL & MG11_3_13PL & MG11_3_14PL & \
                    MG11_3_15PL & MG11_3_16PL & MG11_3_17PL & MG11_3_18PL & \
                    MG11_3_19PL & MG11_3_110PL & MG11_3_111PL & MG11_3_112PL & \
                    MG11_3_113PL & MG11_3_114PL & MG11_3_115PL & MG11_3_116PL)
// End of MG11_3:
// Beginning of MG114:
#if (G11_1PL >= G11_4PL) || (G11_1PL == 0)
#define  MG11_4_11PL    ~(1 << 0)
#else
#define  MG11_4_11PL    0xFFFF
#endif

#if (G11_2PL >= G11_4PL) || (G11_2PL == 0)
#define  MG11_4_12PL    ~(1 << 1)
#else
#define  MG11_4_12PL    0xFFFF
#endif

#if (G11_3PL >= G11_4PL) || (G11_3PL == 0)
#define  MG11_4_13PL    ~(1 << 2)
#else
#define  MG11_4_13PL    0xFFFF
#endif

#if (G11_5PL >= G11_4PL) || (G11_5PL == 0)
#define  MG11_4_15PL    ~(1 << 4)
#else
#define  MG11_4_15PL    0xFFFF
#endif

#if (G11_6PL >= G11_4PL) || (G11_6PL == 0)
#define  MG11_4_16PL    ~(1 << 5)
#else
#define  MG11_4_16PL    0xFFFF
#endif

#if (G11_7PL >= G11_4PL) || (G11_7PL == 0)
#define  MG11_4_17PL    ~(1 << 6)
#else
#define  MG11_4_17PL    0xFFFF
#endif

#if (G11_8PL >= G11_4PL) || (G11_8PL == 0)
#define  MG11_4_18PL    ~(1 << 7)
#else
#define  MG11_4_18PL    0xFFFF
#endif

#if (G11_9PL >= G11_4PL) || (G11_9PL == 0)
#define  MG11_4_19PL    ~(1 << 8)
#else
#define  MG11_4_19PL    0xFFFF
#endif

#if (G11_10PL >= G11_4PL) || (G11_10PL == 0)
#define  MG11_4_110PL    ~(1 << 9)
#else
#define  MG11_4_110PL    0xFFFF
#endif

#if (G11_11PL >= G11_4PL) || (G11_11PL == 0)
#define  MG11_4_111PL    ~(1 << 10)
#else
#define  MG11_4_111PL    0xFFFF
#endif

#if (G11_12PL >= G11_4PL) || (G11_12PL == 0)
#define  MG11_4_112PL    ~(1 << 11)
#else
#define  MG11_4_112PL    0xFFFF
#endif

#if (G11_13PL >= G11_4PL) || (G11_13PL == 0)
#define  MG11_4_113PL    ~(1 << 12)
#else
#define  MG11_4_113PL    0xFFFF
#endif

#if (G11_14PL >= G11_4PL) || (G11_14PL == 0)
#define  MG11_4_114PL    ~(1 << 13)
#else
#define  MG11_4_114PL    0xFFFF
#endif

#if (G11_15PL >= G11_4PL) || (G11_15PL == 0)
#define  MG11_4_115PL    ~(1 << 14)
#else
#define  MG11_4_115PL    0xFFFF
#endif

#if (G11_16PL >= G11_4PL) || (G11_16PL == 0)
#define  MG11_4_116PL    ~(1 << 15)
#else
#define  MG11_4_116PL    0xFFFF
#endif

#define  MG11_4_14PL	0xFFF7
#define  MG11_4    (MG11_4_11PL & MG11_4_12PL & MG11_4_13PL & MG11_4_14PL & \
                    MG11_4_15PL & MG11_4_16PL & MG11_4_17PL & MG11_4_18PL & \
                    MG11_4_19PL & MG11_4_110PL & MG11_4_111PL & MG11_4_112PL & \
                    MG11_4_113PL & MG11_4_114PL & MG11_4_115PL & MG11_4_116PL)
// End of MG11_4:
// Beginning of MG115:
#if (G11_1PL >= G11_5PL) || (G11_1PL == 0)
#define  MG11_5_11PL    ~(1 << 0)
#else
#define  MG11_5_11PL    0xFFFF
#endif

#if (G11_2PL >= G11_5PL) || (G11_2PL == 0)
#define  MG11_5_12PL    ~(1 << 1)
#else
#define  MG11_5_12PL    0xFFFF
#endif

#if (G11_3PL >= G11_5PL) || (G11_3PL == 0)
#define  MG11_5_13PL    ~(1 << 2)
#else
#define  MG11_5_13PL    0xFFFF
#endif

#if (G11_4PL >= G11_5PL) || (G11_4PL == 0)
#define  MG11_5_14PL    ~(1 << 3)
#else
#define  MG11_5_14PL    0xFFFF
#endif

#if (G11_6PL >= G11_5PL) || (G11_6PL == 0)
#define  MG11_5_16PL    ~(1 << 5)
#else
#define  MG11_5_16PL    0xFFFF
#endif

#if (G11_7PL >= G11_5PL) || (G11_7PL == 0)
#define  MG11_5_17PL    ~(1 << 6)
#else
#define  MG11_5_17PL    0xFFFF
#endif

#if (G11_8PL >= G11_5PL) || (G11_8PL == 0)
#define  MG11_5_18PL    ~(1 << 7)
#else
#define  MG11_5_18PL    0xFFFF
#endif

#if (G11_9PL >= G11_5PL) || (G11_9PL == 0)
#define  MG11_5_19PL    ~(1 << 8)
#else
#define  MG11_5_19PL    0xFFFF
#endif

#if (G11_10PL >= G11_5PL) || (G11_10PL == 0)
#define  MG11_5_110PL    ~(1 << 9)
#else
#define  MG11_5_110PL    0xFFFF
#endif

#if (G11_11PL >= G11_5PL) || (G11_11PL == 0)
#define  MG11_5_111PL    ~(1 << 10)
#else
#define  MG11_5_111PL    0xFFFF
#endif

#if (G11_12PL >= G11_5PL) || (G11_12PL == 0)
#define  MG11_5_112PL    ~(1 << 11)
#else
#define  MG11_5_112PL    0xFFFF
#endif

#if (G11_13PL >= G11_5PL) || (G11_13PL == 0)
#define  MG11_5_113PL    ~(1 << 12)
#else
#define  MG11_5_113PL    0xFFFF
#endif

#if (G11_14PL >= G11_5PL) || (G11_14PL == 0)
#define  MG11_5_114PL    ~(1 << 13)
#else
#define  MG11_5_114PL    0xFFFF
#endif

#if (G11_15PL >= G11_5PL) || (G11_15PL == 0)
#define  MG11_5_115PL    ~(1 << 14)
#else
#define  MG11_5_115PL    0xFFFF
#endif

#if (G11_16PL >= G11_5PL) || (G11_16PL == 0)
#define  MG11_5_116PL    ~(1 << 15)
#else
#define  MG11_5_116PL    0xFFFF
#endif

#define  MG11_5_15PL	0xFFEF
#define  MG11_5    (MG11_5_11PL & MG11_5_12PL & MG11_5_13PL & MG11_5_14PL & \
                    MG11_5_15PL & MG11_5_16PL & MG11_5_17PL & MG11_5_18PL & \
                    MG11_5_19PL & MG11_5_110PL & MG11_5_111PL & MG11_5_112PL & \
                    MG11_5_113PL & MG11_5_114PL & MG11_5_115PL & MG11_5_116PL)
// End of MG11_5:
// Beginning of MG116:
#if (G11_1PL >= G11_6PL) || (G11_1PL == 0)
#define  MG11_6_11PL    ~(1 << 0)
#else
#define  MG11_6_11PL    0xFFFF
#endif

#if (G11_2PL >= G11_6PL) || (G11_2PL == 0)
#define  MG11_6_12PL    ~(1 << 1)
#else
#define  MG11_6_12PL    0xFFFF
#endif

#if (G11_3PL >= G11_6PL) || (G11_3PL == 0)
#define  MG11_6_13PL    ~(1 << 2)
#else
#define  MG11_6_13PL    0xFFFF
#endif

#if (G11_4PL >= G11_6PL) || (G11_4PL == 0)
#define  MG11_6_14PL    ~(1 << 3)
#else
#define  MG11_6_14PL    0xFFFF
#endif

#if (G11_5PL >= G11_6PL) || (G11_5PL == 0)
#define  MG11_6_15PL    ~(1 << 4)
#else
#define  MG11_6_15PL    0xFFFF
#endif

#if (G11_7PL >= G11_6PL) || (G11_7PL == 0)
#define  MG11_6_17PL    ~(1 << 6)
#else
#define  MG11_6_17PL    0xFFFF
#endif

#if (G11_8PL >= G11_6PL) || (G11_8PL == 0)
#define  MG11_6_18PL    ~(1 << 7)
#else
#define  MG11_6_18PL    0xFFFF
#endif

#if (G11_9PL >= G11_6PL) || (G11_9PL == 0)
#define  MG11_6_19PL    ~(1 << 8)
#else
#define  MG11_6_19PL    0xFFFF
#endif

#if (G11_10PL >= G11_6PL) || (G11_10PL == 0)
#define  MG11_6_110PL    ~(1 << 9)
#else
#define  MG11_6_110PL    0xFFFF
#endif

#if (G11_11PL >= G11_6PL) || (G11_11PL == 0)
#define  MG11_6_111PL    ~(1 << 10)
#else
#define  MG11_6_111PL    0xFFFF
#endif

#if (G11_12PL >= G11_6PL) || (G11_12PL == 0)
#define  MG11_6_112PL    ~(1 << 11)
#else
#define  MG11_6_112PL    0xFFFF
#endif

#if (G11_13PL >= G11_6PL) || (G11_13PL == 0)
#define  MG11_6_113PL    ~(1 << 12)
#else
#define  MG11_6_113PL    0xFFFF
#endif

#if (G11_14PL >= G11_6PL) || (G11_14PL == 0)
#define  MG11_6_114PL    ~(1 << 13)
#else
#define  MG11_6_114PL    0xFFFF
#endif

#if (G11_15PL >= G11_6PL) || (G11_15PL == 0)
#define  MG11_6_115PL    ~(1 << 14)
#else
#define  MG11_6_115PL    0xFFFF
#endif

#if (G11_16PL >= G11_6PL) || (G11_16PL == 0)
#define  MG11_6_116PL    ~(1 << 15)
#else
#define  MG11_6_116PL    0xFFFF
#endif

#define  MG11_6_16PL	0xFFDF
#define  MG11_6    (MG11_6_11PL & MG11_6_12PL & MG11_6_13PL & MG11_6_14PL & \
                    MG11_6_15PL & MG11_6_16PL & MG11_6_17PL & MG11_6_18PL & \
                    MG11_6_19PL & MG11_6_110PL & MG11_6_111PL & MG11_6_112PL & \
                    MG11_6_113PL & MG11_6_114PL & MG11_6_115PL & MG11_6_116PL)
// End of MG11_6:
// Beginning of MG117:
#if (G11_1PL >= G11_7PL) || (G11_1PL == 0)
#define  MG11_7_11PL    ~(1 << 0)
#else
#define  MG11_7_11PL    0xFFFF
#endif

#if (G11_2PL >= G11_7PL) || (G11_2PL == 0)
#define  MG11_7_12PL    ~(1 << 1)
#else
#define  MG11_7_12PL    0xFFFF
#endif

#if (G11_3PL >= G11_7PL) || (G11_3PL == 0)
#define  MG11_7_13PL    ~(1 << 2)
#else
#define  MG11_7_13PL    0xFFFF
#endif

#if (G11_4PL >= G11_7PL) || (G11_4PL == 0)
#define  MG11_7_14PL    ~(1 << 3)
#else
#define  MG11_7_14PL    0xFFFF
#endif

#if (G11_5PL >= G11_7PL) || (G11_5PL == 0)
#define  MG11_7_15PL    ~(1 << 4)
#else
#define  MG11_7_15PL    0xFFFF
#endif

#if (G11_6PL >= G11_7PL) || (G11_6PL == 0)
#define  MG11_7_16PL    ~(1 << 5)
#else
#define  MG11_7_16PL    0xFFFF
#endif

#if (G11_8PL >= G11_7PL) || (G11_8PL == 0)
#define  MG11_7_18PL    ~(1 << 7)
#else
#define  MG11_7_18PL    0xFFFF
#endif

#if (G11_9PL >= G11_7PL) || (G11_9PL == 0)
#define  MG11_7_19PL    ~(1 << 8)
#else
#define  MG11_7_19PL    0xFFFF
#endif

#if (G11_10PL >= G11_7PL) || (G11_10PL == 0)
#define  MG11_7_110PL    ~(1 << 9)
#else
#define  MG11_7_110PL    0xFFFF
#endif

#if (G11_11PL >= G11_7PL) || (G11_11PL == 0)
#define  MG11_7_111PL    ~(1 << 10)
#else
#define  MG11_7_111PL    0xFFFF
#endif

#if (G11_12PL >= G11_7PL) || (G11_12PL == 0)
#define  MG11_7_112PL    ~(1 << 11)
#else
#define  MG11_7_112PL    0xFFFF
#endif

#if (G11_13PL >= G11_7PL) || (G11_13PL == 0)
#define  MG11_7_113PL    ~(1 << 12)
#else
#define  MG11_7_113PL    0xFFFF
#endif

#if (G11_14PL >= G11_7PL) || (G11_14PL == 0)
#define  MG11_7_114PL    ~(1 << 13)
#else
#define  MG11_7_114PL    0xFFFF
#endif

#if (G11_15PL >= G11_7PL) || (G11_15PL == 0)
#define  MG11_7_115PL    ~(1 << 14)
#else
#define  MG11_7_115PL    0xFFFF
#endif

#if (G11_16PL >= G11_7PL) || (G11_16PL == 0)
#define  MG11_7_116PL    ~(1 << 15)
#else
#define  MG11_7_116PL    0xFFFF
#endif

#define  MG11_7_17PL	0xFFBF
#define  MG11_7    (MG11_7_11PL & MG11_7_12PL & MG11_7_13PL & MG11_7_14PL & \
                    MG11_7_15PL & MG11_7_16PL & MG11_7_17PL & MG11_7_18PL & \
                    MG11_7_19PL & MG11_7_110PL & MG11_7_111PL & MG11_7_112PL & \
                    MG11_7_113PL & MG11_7_114PL & MG11_7_115PL & MG11_7_116PL)
// End of MG11_7:
// Beginning of MG118:
#if (G11_1PL >= G11_8PL) || (G11_1PL == 0)
#define  MG11_8_11PL    ~(1 << 0)
#else
#define  MG11_8_11PL    0xFFFF
#endif

#if (G11_2PL >= G11_8PL) || (G11_2PL == 0)
#define  MG11_8_12PL    ~(1 << 1)
#else
#define  MG11_8_12PL    0xFFFF
#endif

#if (G11_3PL >= G11_8PL) || (G11_3PL == 0)
#define  MG11_8_13PL    ~(1 << 2)
#else
#define  MG11_8_13PL    0xFFFF
#endif

#if (G11_4PL >= G11_8PL) || (G11_4PL == 0)
#define  MG11_8_14PL    ~(1 << 3)
#else
#define  MG11_8_14PL    0xFFFF
#endif

#if (G11_5PL >= G11_8PL) || (G11_5PL == 0)
#define  MG11_8_15PL    ~(1 << 4)
#else
#define  MG11_8_15PL    0xFFFF
#endif

#if (G11_6PL >= G11_8PL) || (G11_6PL == 0)
#define  MG11_8_16PL    ~(1 << 5)
#else
#define  MG11_8_16PL    0xFFFF
#endif

#if (G11_7PL >= G11_8PL) || (G11_7PL == 0)
#define  MG11_8_17PL    ~(1 << 6)
#else
#define  MG11_8_17PL    0xFFFF
#endif

#if (G11_9PL >= G11_8PL) || (G11_9PL == 0)
#define  MG11_8_19PL    ~(1 << 8)
#else
#define  MG11_8_19PL    0xFFFF
#endif

#if (G11_10PL >= G11_8PL) || (G11_10PL == 0)
#define  MG11_8_110PL    ~(1 << 9)
#else
#define  MG11_8_110PL    0xFFFF
#endif

#if (G11_11PL >= G11_8PL) || (G11_11PL == 0)
#define  MG11_8_111PL    ~(1 << 10)
#else
#define  MG11_8_111PL    0xFFFF
#endif

#if (G11_12PL >= G11_8PL) || (G11_12PL == 0)
#define  MG11_8_112PL    ~(1 << 11)
#else
#define  MG11_8_112PL    0xFFFF
#endif

#if (G11_13PL >= G11_8PL) || (G11_13PL == 0)
#define  MG11_8_113PL    ~(1 << 12)
#else
#define  MG11_8_113PL    0xFFFF
#endif

#if (G11_14PL >= G11_8PL) || (G11_14PL == 0)
#define  MG11_8_114PL    ~(1 << 13)
#else
#define  MG11_8_114PL    0xFFFF
#endif

#if (G11_15PL >= G11_8PL) || (G11_15PL == 0)
#define  MG11_8_115PL    ~(1 << 14)
#else
#define  MG11_8_115PL    0xFFFF
#endif

#if (G11_16PL >= G11_8PL) || (G11_16PL == 0)
#define  MG11_8_116PL    ~(1 << 15)
#else
#define  MG11_8_116PL    0xFFFF
#endif

#define  MG11_8_18PL	0xFF7F
#define  MG11_8    (MG11_8_11PL & MG11_8_12PL & MG11_8_13PL & MG11_8_14PL & \
                    MG11_8_15PL & MG11_8_16PL & MG11_8_17PL & MG11_8_18PL & \
                    MG11_8_19PL & MG11_8_110PL & MG11_8_111PL & MG11_8_112PL & \
                    MG11_8_113PL & MG11_8_114PL & MG11_8_115PL & MG11_8_116PL)
// End of MG11_8:
// Beginning of MG119:
#if (G11_1PL >= G11_9PL) || (G11_1PL == 0)
#define  MG11_9_11PL    ~(1 << 0)
#else
#define  MG11_9_11PL    0xFFFF
#endif

#if (G11_2PL >= G11_9PL) || (G11_2PL == 0)
#define  MG11_9_12PL    ~(1 << 1)
#else
#define  MG11_9_12PL    0xFFFF
#endif

#if (G11_3PL >= G11_9PL) || (G11_3PL == 0)
#define  MG11_9_13PL    ~(1 << 2)
#else
#define  MG11_9_13PL    0xFFFF
#endif

#if (G11_4PL >= G11_9PL) || (G11_4PL == 0)
#define  MG11_9_14PL    ~(1 << 3)
#else
#define  MG11_9_14PL    0xFFFF
#endif

#if (G11_5PL >= G11_9PL) || (G11_5PL == 0)
#define  MG11_9_15PL    ~(1 << 4)
#else
#define  MG11_9_15PL    0xFFFF
#endif

#if (G11_6PL >= G11_9PL) || (G11_6PL == 0)
#define  MG11_9_16PL    ~(1 << 5)
#else
#define  MG11_9_16PL    0xFFFF
#endif

#if (G11_7PL >= G11_9PL) || (G11_7PL == 0)
#define  MG11_9_17PL    ~(1 << 6)
#else
#define  MG11_9_17PL    0xFFFF
#endif

#if (G11_8PL >= G11_9PL) || (G11_8PL == 0)
#define  MG11_9_18PL    ~(1 << 7)
#else
#define  MG11_9_18PL    0xFFFF
#endif

#if (G11_10PL >= G11_9PL) || (G11_10PL == 0)
#define  MG11_9_110PL    ~(1 << 9)
#else
#define  MG11_9_110PL    0xFFFF
#endif

#if (G11_11PL >= G11_9PL) || (G11_11PL == 0)
#define  MG11_9_111PL    ~(1 << 10)
#else
#define  MG11_9_111PL    0xFFFF
#endif

#if (G11_12PL >= G11_9PL) || (G11_12PL == 0)
#define  MG11_9_112PL    ~(1 << 11)
#else
#define  MG11_9_112PL    0xFFFF
#endif

#if (G11_13PL >= G11_9PL) || (G11_13PL == 0)
#define  MG11_9_113PL    ~(1 << 12)
#else
#define  MG11_9_113PL    0xFFFF
#endif

#if (G11_14PL >= G11_9PL) || (G11_14PL == 0)
#define  MG11_9_114PL    ~(1 << 13)
#else
#define  MG11_9_114PL    0xFFFF
#endif

#if (G11_15PL >= G11_9PL) || (G11_15PL == 0)
#define  MG11_9_115PL    ~(1 << 14)
#else
#define  MG11_9_115PL    0xFFFF
#endif

#if (G11_16PL >= G11_9PL) || (G11_16PL == 0)
#define  MG11_9_116PL    ~(1 << 15)
#else
#define  MG11_9_116PL    0xFFFF
#endif

#define  MG11_9_19PL	0xFEFF
#define  MG11_9    (MG11_9_11PL & MG11_9_12PL & MG11_9_13PL & MG11_9_14PL & \
                    MG11_9_15PL & MG11_9_16PL & MG11_9_17PL & MG11_9_18PL & \
                    MG11_9_19PL & MG11_9_110PL & MG11_9_111PL & MG11_9_112PL & \
                    MG11_9_113PL & MG11_9_114PL & MG11_9_115PL & MG11_9_116PL)
// End of MG11_9:
// Beginning of MG1110:
#if (G11_1PL >= G11_10PL) || (G11_1PL == 0)
#define  MG11_10_11PL    ~(1 << 0)
#else
#define  MG11_10_11PL    0xFFFF
#endif

#if (G11_2PL >= G11_10PL) || (G11_2PL == 0)
#define  MG11_10_12PL    ~(1 << 1)
#else
#define  MG11_10_12PL    0xFFFF
#endif

#if (G11_3PL >= G11_10PL) || (G11_3PL == 0)
#define  MG11_10_13PL    ~(1 << 2)
#else
#define  MG11_10_13PL    0xFFFF
#endif

#if (G11_4PL >= G11_10PL) || (G11_4PL == 0)
#define  MG11_10_14PL    ~(1 << 3)
#else
#define  MG11_10_14PL    0xFFFF
#endif

#if (G11_5PL >= G11_10PL) || (G11_5PL == 0)
#define  MG11_10_15PL    ~(1 << 4)
#else
#define  MG11_10_15PL    0xFFFF
#endif

#if (G11_6PL >= G11_10PL) || (G11_6PL == 0)
#define  MG11_10_16PL    ~(1 << 5)
#else
#define  MG11_10_16PL    0xFFFF
#endif

#if (G11_7PL >= G11_10PL) || (G11_7PL == 0)
#define  MG11_10_17PL    ~(1 << 6)
#else
#define  MG11_10_17PL    0xFFFF
#endif

#if (G11_8PL >= G11_10PL) || (G11_8PL == 0)
#define  MG11_10_18PL    ~(1 << 7)
#else
#define  MG11_10_18PL    0xFFFF
#endif

#if (G11_9PL >= G11_10PL) || (G11_9PL == 0)
#define  MG11_10_19PL    ~(1 << 8)
#else
#define  MG11_10_19PL    0xFFFF
#endif

#if (G11_11PL >= G11_10PL) || (G11_11PL == 0)
#define  MG11_10_111PL    ~(1 << 10)
#else
#define  MG11_10_111PL    0xFFFF
#endif

#if (G11_12PL >= G11_10PL) || (G11_12PL == 0)
#define  MG11_10_112PL    ~(1 << 11)
#else
#define  MG11_10_112PL    0xFFFF
#endif

#if (G11_13PL >= G11_10PL) || (G11_13PL == 0)
#define  MG11_10_113PL    ~(1 << 12)
#else
#define  MG11_10_113PL    0xFFFF
#endif

#if (G11_14PL >= G11_10PL) || (G11_14PL == 0)
#define  MG11_10_114PL    ~(1 << 13)
#else
#define  MG11_10_114PL    0xFFFF
#endif

#if (G11_15PL >= G11_10PL) || (G11_15PL == 0)
#define  MG11_10_115PL    ~(1 << 14)
#else
#define  MG11_10_115PL    0xFFFF
#endif

#if (G11_16PL >= G11_10PL) || (G11_16PL == 0)
#define  MG11_10_116PL    ~(1 << 15)
#else
#define  MG11_10_116PL    0xFFFF
#endif

#define  MG11_10_110PL	0xFDFF
#define  MG11_10    (MG11_10_11PL & MG11_10_12PL & MG11_10_13PL & MG11_10_14PL & \
                    MG11_10_15PL & MG11_10_16PL & MG11_10_17PL & MG11_10_18PL & \
                    MG11_10_19PL & MG11_10_110PL & MG11_10_111PL & MG11_10_112PL & \
                    MG11_10_113PL & MG11_10_114PL & MG11_10_115PL & MG11_10_116PL)
// End of MG11_10:
// Beginning of MG1111:
#if (G11_1PL >= G11_11PL) || (G11_1PL == 0)
#define  MG11_11_11PL    ~(1 << 0)
#else
#define  MG11_11_11PL    0xFFFF
#endif

#if (G11_2PL >= G11_11PL) || (G11_2PL == 0)
#define  MG11_11_12PL    ~(1 << 1)
#else
#define  MG11_11_12PL    0xFFFF
#endif

#if (G11_3PL >= G11_11PL) || (G11_3PL == 0)
#define  MG11_11_13PL    ~(1 << 2)
#else
#define  MG11_11_13PL    0xFFFF
#endif

#if (G11_4PL >= G11_11PL) || (G11_4PL == 0)
#define  MG11_11_14PL    ~(1 << 3)
#else
#define  MG11_11_14PL    0xFFFF
#endif

#if (G11_5PL >= G11_11PL) || (G11_5PL == 0)
#define  MG11_11_15PL    ~(1 << 4)
#else
#define  MG11_11_15PL    0xFFFF
#endif

#if (G11_6PL >= G11_11PL) || (G11_6PL == 0)
#define  MG11_11_16PL    ~(1 << 5)
#else
#define  MG11_11_16PL    0xFFFF
#endif

#if (G11_7PL >= G11_11PL) || (G11_7PL == 0)
#define  MG11_11_17PL    ~(1 << 6)
#else
#define  MG11_11_17PL    0xFFFF
#endif

#if (G11_8PL >= G11_11PL) || (G11_8PL == 0)
#define  MG11_11_18PL    ~(1 << 7)
#else
#define  MG11_11_18PL    0xFFFF
#endif

#if (G11_9PL >= G11_11PL) || (G11_9PL == 0)
#define  MG11_11_19PL    ~(1 << 8)
#else
#define  MG11_11_19PL    0xFFFF
#endif

#if (G11_10PL >= G11_11PL) || (G11_10PL == 0)
#define  MG11_11_110PL    ~(1 << 9)
#else
#define  MG11_11_110PL    0xFFFF
#endif

#if (G11_12PL >= G11_11PL) || (G11_12PL == 0)
#define  MG11_11_112PL    ~(1 << 11)
#else
#define  MG11_11_112PL    0xFFFF
#endif

#if (G11_13PL >= G11_11PL) || (G11_13PL == 0)
#define  MG11_11_113PL    ~(1 << 12)
#else
#define  MG11_11_113PL    0xFFFF
#endif

#if (G11_14PL >= G11_11PL) || (G11_14PL == 0)
#define  MG11_11_114PL    ~(1 << 13)
#else
#define  MG11_11_114PL    0xFFFF
#endif

#if (G11_15PL >= G11_11PL) || (G11_15PL == 0)
#define  MG11_11_115PL    ~(1 << 14)
#else
#define  MG11_11_115PL    0xFFFF
#endif

#if (G11_16PL >= G11_11PL) || (G11_16PL == 0)
#define  MG11_11_116PL    ~(1 << 15)
#else
#define  MG11_11_116PL    0xFFFF
#endif

#define  MG11_11_111PL	0xFBFF
#define  MG11_11    (MG11_11_11PL & MG11_11_12PL & MG11_11_13PL & MG11_11_14PL & \
                    MG11_11_15PL & MG11_11_16PL & MG11_11_17PL & MG11_11_18PL & \
                    MG11_11_19PL & MG11_11_110PL & MG11_11_111PL & MG11_11_112PL & \
                    MG11_11_113PL & MG11_11_114PL & MG11_11_115PL & MG11_11_116PL)
// End of MG11_11:
// Beginning of MG1112:
#if (G11_1PL >= G11_12PL) || (G11_1PL == 0)
#define  MG11_12_11PL    ~(1 << 0)
#else
#define  MG11_12_11PL    0xFFFF
#endif

#if (G11_2PL >= G11_12PL) || (G11_2PL == 0)
#define  MG11_12_12PL    ~(1 << 1)
#else
#define  MG11_12_12PL    0xFFFF
#endif

#if (G11_3PL >= G11_12PL) || (G11_3PL == 0)
#define  MG11_12_13PL    ~(1 << 2)
#else
#define  MG11_12_13PL    0xFFFF
#endif

#if (G11_4PL >= G11_12PL) || (G11_4PL == 0)
#define  MG11_12_14PL    ~(1 << 3)
#else
#define  MG11_12_14PL    0xFFFF
#endif

#if (G11_5PL >= G11_12PL) || (G11_5PL == 0)
#define  MG11_12_15PL    ~(1 << 4)
#else
#define  MG11_12_15PL    0xFFFF
#endif

#if (G11_6PL >= G11_12PL) || (G11_6PL == 0)
#define  MG11_12_16PL    ~(1 << 5)
#else
#define  MG11_12_16PL    0xFFFF
#endif

#if (G11_7PL >= G11_12PL) || (G11_7PL == 0)
#define  MG11_12_17PL    ~(1 << 6)
#else
#define  MG11_12_17PL    0xFFFF
#endif

#if (G11_8PL >= G11_12PL) || (G11_8PL == 0)
#define  MG11_12_18PL    ~(1 << 7)
#else
#define  MG11_12_18PL    0xFFFF
#endif

#if (G11_9PL >= G11_12PL) || (G11_9PL == 0)
#define  MG11_12_19PL    ~(1 << 8)
#else
#define  MG11_12_19PL    0xFFFF
#endif

#if (G11_10PL >= G11_12PL) || (G11_10PL == 0)
#define  MG11_12_110PL    ~(1 << 9)
#else
#define  MG11_12_110PL    0xFFFF
#endif

#if (G11_11PL >= G11_12PL) || (G11_11PL == 0)
#define  MG11_12_111PL    ~(1 << 10)
#else
#define  MG11_12_111PL    0xFFFF
#endif

#if (G11_13PL >= G11_12PL) || (G11_13PL == 0)
#define  MG11_12_113PL    ~(1 << 12)
#else
#define  MG11_12_113PL    0xFFFF
#endif

#if (G11_14PL >= G11_12PL) || (G11_14PL == 0)
#define  MG11_12_114PL    ~(1 << 13)
#else
#define  MG11_12_114PL    0xFFFF
#endif

#if (G11_15PL >= G11_12PL) || (G11_15PL == 0)
#define  MG11_12_115PL    ~(1 << 14)
#else
#define  MG11_12_115PL    0xFFFF
#endif

#if (G11_16PL >= G11_12PL) || (G11_16PL == 0)
#define  MG11_12_116PL    ~(1 << 15)
#else
#define  MG11_12_116PL    0xFFFF
#endif

#define  MG11_12_112PL	0xF7FF
#define  MG11_12    (MG11_12_11PL & MG11_12_12PL & MG11_12_13PL & MG11_12_14PL & \
                    MG11_12_15PL & MG11_12_16PL & MG11_12_17PL & MG11_12_18PL & \
                    MG11_12_19PL & MG11_12_110PL & MG11_12_111PL & MG11_12_112PL & \
                    MG11_12_113PL & MG11_12_114PL & MG11_12_115PL & MG11_12_116PL)
// End of MG11_12:
// Beginning of MG1113:
#if (G11_1PL >= G11_13PL) || (G11_1PL == 0)
#define  MG11_13_11PL    ~(1 << 0)
#else
#define  MG11_13_11PL    0xFFFF
#endif

#if (G11_2PL >= G11_13PL) || (G11_2PL == 0)
#define  MG11_13_12PL    ~(1 << 1)
#else
#define  MG11_13_12PL    0xFFFF
#endif

#if (G11_3PL >= G11_13PL) || (G11_3PL == 0)
#define  MG11_13_13PL    ~(1 << 2)
#else
#define  MG11_13_13PL    0xFFFF
#endif

#if (G11_4PL >= G11_13PL) || (G11_4PL == 0)
#define  MG11_13_14PL    ~(1 << 3)
#else
#define  MG11_13_14PL    0xFFFF
#endif

#if (G11_5PL >= G11_13PL) || (G11_5PL == 0)
#define  MG11_13_15PL    ~(1 << 4)
#else
#define  MG11_13_15PL    0xFFFF
#endif

#if (G11_6PL >= G11_13PL) || (G11_6PL == 0)
#define  MG11_13_16PL    ~(1 << 5)
#else
#define  MG11_13_16PL    0xFFFF
#endif

#if (G11_7PL >= G11_13PL) || (G11_7PL == 0)
#define  MG11_13_17PL    ~(1 << 6)
#else
#define  MG11_13_17PL    0xFFFF
#endif

#if (G11_8PL >= G11_13PL) || (G11_8PL == 0)
#define  MG11_13_18PL    ~(1 << 7)
#else
#define  MG11_13_18PL    0xFFFF
#endif

#if (G11_9PL >= G11_13PL) || (G11_9PL == 0)
#define  MG11_13_19PL    ~(1 << 8)
#else
#define  MG11_13_19PL    0xFFFF
#endif

#if (G11_10PL >= G11_13PL) || (G11_10PL == 0)
#define  MG11_13_110PL    ~(1 << 9)
#else
#define  MG11_13_110PL    0xFFFF
#endif

#if (G11_11PL >= G11_13PL) || (G11_11PL == 0)
#define  MG11_13_111PL    ~(1 << 10)
#else
#define  MG11_13_111PL    0xFFFF
#endif

#if (G11_12PL >= G11_13PL) || (G11_12PL == 0)
#define  MG11_13_112PL    ~(1 << 11)
#else
#define  MG11_13_112PL    0xFFFF
#endif

#if (G11_14PL >= G11_13PL) || (G11_14PL == 0)
#define  MG11_13_114PL    ~(1 << 13)
#else
#define  MG11_13_114PL    0xFFFF
#endif

#if (G11_15PL >= G11_13PL) || (G11_15PL == 0)
#define  MG11_13_115PL    ~(1 << 14)
#else
#define  MG11_13_115PL    0xFFFF
#endif

#if (G11_16PL >= G11_13PL) || (G11_16PL == 0)
#define  MG11_13_116PL    ~(1 << 15)
#else
#define  MG11_13_116PL    0xFFFF
#endif

#define  MG11_13_113PL	0xEFFF
#define  MG11_13    (MG11_13_11PL & MG11_13_12PL & MG11_13_13PL & MG11_13_14PL & \
                    MG11_13_15PL & MG11_13_16PL & MG11_13_17PL & MG11_13_18PL & \
                    MG11_13_19PL & MG11_13_110PL & MG11_13_111PL & MG11_13_112PL & \
                    MG11_13_113PL & MG11_13_114PL & MG11_13_115PL & MG11_13_116PL)
// End of MG11_13:
// Beginning of MG1114:
#if (G11_1PL >= G11_14PL) || (G11_1PL == 0)
#define  MG11_14_11PL    ~(1 << 0)
#else
#define  MG11_14_11PL    0xFFFF
#endif

#if (G11_2PL >= G11_14PL) || (G11_2PL == 0)
#define  MG11_14_12PL    ~(1 << 1)
#else
#define  MG11_14_12PL    0xFFFF
#endif

#if (G11_3PL >= G11_14PL) || (G11_3PL == 0)
#define  MG11_14_13PL    ~(1 << 2)
#else
#define  MG11_14_13PL    0xFFFF
#endif

#if (G11_4PL >= G11_14PL) || (G11_4PL == 0)
#define  MG11_14_14PL    ~(1 << 3)
#else
#define  MG11_14_14PL    0xFFFF
#endif

#if (G11_5PL >= G11_14PL) || (G11_5PL == 0)
#define  MG11_14_15PL    ~(1 << 4)
#else
#define  MG11_14_15PL    0xFFFF
#endif

#if (G11_6PL >= G11_14PL) || (G11_6PL == 0)
#define  MG11_14_16PL    ~(1 << 5)
#else
#define  MG11_14_16PL    0xFFFF
#endif

#if (G11_7PL >= G11_14PL) || (G11_7PL == 0)
#define  MG11_14_17PL    ~(1 << 6)
#else
#define  MG11_14_17PL    0xFFFF
#endif

#if (G11_8PL >= G11_14PL) || (G11_8PL == 0)
#define  MG11_14_18PL    ~(1 << 7)
#else
#define  MG11_14_18PL    0xFFFF
#endif

#if (G11_9PL >= G11_14PL) || (G11_9PL == 0)
#define  MG11_14_19PL    ~(1 << 8)
#else
#define  MG11_14_19PL    0xFFFF
#endif

#if (G11_10PL >= G11_14PL) || (G11_10PL == 0)
#define  MG11_14_110PL    ~(1 << 9)
#else
#define  MG11_14_110PL    0xFFFF
#endif

#if (G11_11PL >= G11_14PL) || (G11_11PL == 0)
#define  MG11_14_111PL    ~(1 << 10)
#else
#define  MG11_14_111PL    0xFFFF
#endif

#if (G11_12PL >= G11_14PL) || (G11_12PL == 0)
#define  MG11_14_112PL    ~(1 << 11)
#else
#define  MG11_14_112PL    0xFFFF
#endif

#if (G11_13PL >= G11_14PL) || (G11_13PL == 0)
#define  MG11_14_113PL    ~(1 << 12)
#else
#define  MG11_14_113PL    0xFFFF
#endif

#if (G11_15PL >= G11_14PL) || (G11_15PL == 0)
#define  MG11_14_115PL    ~(1 << 14)
#else
#define  MG11_14_115PL    0xFFFF
#endif

#if (G11_16PL >= G11_14PL) || (G11_16PL == 0)
#define  MG11_14_116PL    ~(1 << 15)
#else
#define  MG11_14_116PL    0xFFFF
#endif

#define  MG11_14_114PL	0xDFFF
#define  MG11_14    (MG11_14_11PL & MG11_14_12PL & MG11_14_13PL & MG11_14_14PL & \
                    MG11_14_15PL & MG11_14_16PL & MG11_14_17PL & MG11_14_18PL & \
                    MG11_14_19PL & MG11_14_110PL & MG11_14_111PL & MG11_14_112PL & \
                    MG11_14_113PL & MG11_14_114PL & MG11_14_115PL & MG11_14_116PL)
// End of MG11_14:
// Beginning of MG1115:
#if (G11_1PL >= G11_15PL) || (G11_1PL == 0)
#define  MG11_15_11PL    ~(1 << 0)
#else
#define  MG11_15_11PL    0xFFFF
#endif

#if (G11_2PL >= G11_15PL) || (G11_2PL == 0)
#define  MG11_15_12PL    ~(1 << 1)
#else
#define  MG11_15_12PL    0xFFFF
#endif

#if (G11_3PL >= G11_15PL) || (G11_3PL == 0)
#define  MG11_15_13PL    ~(1 << 2)
#else
#define  MG11_15_13PL    0xFFFF
#endif

#if (G11_4PL >= G11_15PL) || (G11_4PL == 0)
#define  MG11_15_14PL    ~(1 << 3)
#else
#define  MG11_15_14PL    0xFFFF
#endif

#if (G11_5PL >= G11_15PL) || (G11_5PL == 0)
#define  MG11_15_15PL    ~(1 << 4)
#else
#define  MG11_15_15PL    0xFFFF
#endif

#if (G11_6PL >= G11_15PL) || (G11_6PL == 0)
#define  MG11_15_16PL    ~(1 << 5)
#else
#define  MG11_15_16PL    0xFFFF
#endif

#if (G11_7PL >= G11_15PL) || (G11_7PL == 0)
#define  MG11_15_17PL    ~(1 << 6)
#else
#define  MG11_15_17PL    0xFFFF
#endif

#if (G11_8PL >= G11_15PL) || (G11_8PL == 0)
#define  MG11_15_18PL    ~(1 << 7)
#else
#define  MG11_15_18PL    0xFFFF
#endif

#if (G11_9PL >= G11_15PL) || (G11_9PL == 0)
#define  MG11_15_19PL    ~(1 << 8)
#else
#define  MG11_15_19PL    0xFFFF
#endif

#if (G11_10PL >= G11_15PL) || (G11_10PL == 0)
#define  MG11_15_110PL    ~(1 << 9)
#else
#define  MG11_15_110PL    0xFFFF
#endif

#if (G11_11PL >= G11_15PL) || (G11_11PL == 0)
#define  MG11_15_111PL    ~(1 << 10)
#else
#define  MG11_15_111PL    0xFFFF
#endif

#if (G11_12PL >= G11_15PL) || (G11_12PL == 0)
#define  MG11_15_112PL    ~(1 << 11)
#else
#define  MG11_15_112PL    0xFFFF
#endif

#if (G11_13PL >= G11_15PL) || (G11_13PL == 0)
#define  MG11_15_113PL    ~(1 << 12)
#else
#define  MG11_15_113PL    0xFFFF
#endif

#if (G11_14PL >= G11_15PL) || (G11_14PL == 0)
#define  MG11_15_114PL    ~(1 << 13)
#else
#define  MG11_15_114PL    0xFFFF
#endif

#if (G11_16PL >= G11_15PL) || (G11_16PL == 0)
#define  MG11_15_116PL    ~(1 << 15)
#else
#define  MG11_15_116PL    0xFFFF
#endif

#define  MG11_15_115PL	0xBFFF
#define  MG11_15    (MG11_15_11PL & MG11_15_12PL & MG11_15_13PL & MG11_15_14PL & \
                    MG11_15_15PL & MG11_15_16PL & MG11_15_17PL & MG11_15_18PL & \
                    MG11_15_19PL & MG11_15_110PL & MG11_15_111PL & MG11_15_112PL & \
                    MG11_15_113PL & MG11_15_114PL & MG11_15_115PL & MG11_15_116PL)
// End of MG11_15:
// Beginning of MG1116:
#if (G11_1PL >= G11_16PL) || (G11_1PL == 0)
#define  MG11_16_11PL    ~(1 << 0)
#else
#define  MG11_16_11PL    0xFFFF
#endif

#if (G11_2PL >= G11_16PL) || (G11_2PL == 0)
#define  MG11_16_12PL    ~(1 << 1)
#else
#define  MG11_16_12PL    0xFFFF
#endif

#if (G11_3PL >= G11_16PL) || (G11_3PL == 0)
#define  MG11_16_13PL    ~(1 << 2)
#else
#define  MG11_16_13PL    0xFFFF
#endif

#if (G11_4PL >= G11_16PL) || (G11_4PL == 0)
#define  MG11_16_14PL    ~(1 << 3)
#else
#define  MG11_16_14PL    0xFFFF
#endif

#if (G11_5PL >= G11_16PL) || (G11_5PL == 0)
#define  MG11_16_15PL    ~(1 << 4)
#else
#define  MG11_16_15PL    0xFFFF
#endif

#if (G11_6PL >= G11_16PL) || (G11_6PL == 0)
#define  MG11_16_16PL    ~(1 << 5)
#else
#define  MG11_16_16PL    0xFFFF
#endif

#if (G11_7PL >= G11_16PL) || (G11_7PL == 0)
#define  MG11_16_17PL    ~(1 << 6)
#else
#define  MG11_16_17PL    0xFFFF
#endif

#if (G11_8PL >= G11_16PL) || (G11_8PL == 0)
#define  MG11_16_18PL    ~(1 << 7)
#else
#define  MG11_16_18PL    0xFFFF
#endif

#if (G11_9PL >= G11_16PL) || (G11_9PL == 0)
#define  MG11_16_19PL    ~(1 << 8)
#else
#define  MG11_16_19PL    0xFFFF
#endif

#if (G11_10PL >= G11_16PL) || (G11_10PL == 0)
#define  MG11_16_110PL    ~(1 << 9)
#else
#define  MG11_16_110PL    0xFFFF
#endif

#if (G11_11PL >= G11_16PL) || (G11_11PL == 0)
#define  MG11_16_111PL    ~(1 << 10)
#else
#define  MG11_16_111PL    0xFFFF
#endif

#if (G11_12PL >= G11_16PL) || (G11_12PL == 0)
#define  MG11_16_112PL    ~(1 << 11)
#else
#define  MG11_16_112PL    0xFFFF
#endif

#if (G11_13PL >= G11_16PL) || (G11_13PL == 0)
#define  MG11_16_113PL    ~(1 << 12)
#else
#define  MG11_16_113PL    0xFFFF
#endif

#if (G11_14PL >= G11_16PL) || (G11_14PL == 0)
#define  MG11_16_114PL    ~(1 << 13)
#else
#define  MG11_16_114PL    0xFFFF
#endif

#if (G11_15PL >= G11_16PL) || (G11_15PL == 0)
#define  MG11_16_115PL    ~(1 << 14)
#else
#define  MG11_16_115PL    0xFFFF
#endif

#define  MG11_16_116PL	0x7FFF
#define  MG11_16    (MG11_16_11PL & MG11_16_12PL & MG11_16_13PL & MG11_16_14PL & \
                    MG11_16_15PL & MG11_16_16PL & MG11_16_17PL & MG11_16_18PL & \
                    MG11_16_19PL & MG11_16_110PL & MG11_16_111PL & MG11_16_112PL & \
                    MG11_16_113PL & MG11_16_114PL & MG11_16_115PL & MG11_16_116PL)
// End of MG11_16:


//-------------------------------------------------------------------------------
// Automatically generate PIEIER12 interrupt masks MG121 to MG1216:

// Beginning of MG121:
#if (G12_2PL >= G12_1PL) || (G12_2PL == 0)
#define  MG12_1_12PL    ~(1 << 1)
#else
#define  MG12_1_12PL    0xFFFF
#endif

#if (G12_3PL >= G12_1PL) || (G12_3PL == 0)
#define  MG12_1_13PL    ~(1 << 2)
#else
#define  MG12_1_13PL    0xFFFF
#endif

#if (G12_4PL >= G12_1PL) || (G12_4PL == 0)
#define  MG12_1_14PL    ~(1 << 3)
#else
#define  MG12_1_14PL    0xFFFF
#endif

#if (G12_5PL >= G12_1PL) || (G12_5PL == 0)
#define  MG12_1_15PL    ~(1 << 4)
#else
#define  MG12_1_15PL    0xFFFF
#endif

#if (G12_6PL >= G12_1PL) || (G12_6PL == 0)
#define  MG12_1_16PL    ~(1 << 5)
#else
#define  MG12_1_16PL    0xFFFF
#endif

#if (G12_7PL >= G12_1PL) || (G12_7PL == 0)
#define  MG12_1_17PL    ~(1 << 6)
#else
#define  MG12_1_17PL    0xFFFF
#endif

#if (G12_8PL >= G12_1PL) || (G12_8PL == 0)
#define  MG12_1_18PL    ~(1 << 7)
#else
#define  MG12_1_18PL    0xFFFF
#endif

#if (G12_9PL >= G12_1PL) || (G12_9PL == 0)
#define  MG12_1_19PL    ~(1 << 8)
#else
#define  MG12_1_19PL    0xFFFF
#endif

#if (G12_10PL >= G12_1PL) || (G12_10PL == 0)
#define  MG12_1_110PL    ~(1 << 9)
#else
#define  MG12_1_110PL    0xFFFF
#endif

#if (G12_11PL >= G12_1PL) || (G12_11PL == 0)
#define  MG12_1_111PL    ~(1 << 10)
#else
#define  MG12_1_111PL    0xFFFF
#endif

#if (G12_12PL >= G12_1PL) || (G12_12PL == 0)
#define  MG12_1_112PL    ~(1 << 11)
#else
#define  MG12_1_112PL    0xFFFF
#endif

#if (G12_13PL >= G12_1PL) || (G12_13PL == 0)
#define  MG12_1_113PL    ~(1 << 12)
#else
#define  MG12_1_113PL    0xFFFF
#endif

#if (G12_14PL >= G12_1PL) || (G12_14PL == 0)
#define  MG12_1_114PL    ~(1 << 13)
#else
#define  MG12_1_114PL    0xFFFF
#endif

#if (G12_15PL >= G12_1PL) || (G12_15PL == 0)
#define  MG12_1_115PL    ~(1 << 14)
#else
#define  MG12_1_115PL    0xFFFF
#endif

#if (G12_16PL >= G12_1PL) || (G12_16PL == 0)
#define  MG12_1_116PL    ~(1 << 15)
#else
#define  MG12_1_116PL    0xFFFF
#endif

#define  MG12_1_11PL	0xFFFE
#define  MG12_1    (MG12_1_11PL & MG12_1_12PL & MG12_1_13PL & MG12_1_14PL & \
                    MG12_1_15PL & MG12_1_16PL & MG12_1_17PL & MG12_1_18PL & \
                    MG12_1_19PL & MG12_1_110PL & MG12_1_111PL & MG12_1_112PL & \
                    MG12_1_113PL & MG12_1_114PL & MG12_1_115PL & MG12_1_116PL)
// End of MG12_1:
// Beginning of MG122:
#if (G12_1PL >= G12_2PL) || (G12_1PL == 0)
#define  MG12_2_11PL    ~(1 << 0)
#else
#define  MG12_2_11PL    0xFFFF
#endif

#if (G12_3PL >= G12_2PL) || (G12_3PL == 0)
#define  MG12_2_13PL    ~(1 << 2)
#else
#define  MG12_2_13PL    0xFFFF
#endif

#if (G12_4PL >= G12_2PL) || (G12_4PL == 0)
#define  MG12_2_14PL    ~(1 << 3)
#else
#define  MG12_2_14PL    0xFFFF
#endif

#if (G12_5PL >= G12_2PL) || (G12_5PL == 0)
#define  MG12_2_15PL    ~(1 << 4)
#else
#define  MG12_2_15PL    0xFFFF
#endif

#if (G12_6PL >= G12_2PL) || (G12_6PL == 0)
#define  MG12_2_16PL    ~(1 << 5)
#else
#define  MG12_2_16PL    0xFFFF
#endif

#if (G12_7PL >= G12_2PL) || (G12_7PL == 0)
#define  MG12_2_17PL    ~(1 << 6)
#else
#define  MG12_2_17PL    0xFFFF
#endif

#if (G12_8PL >= G12_2PL) || (G12_8PL == 0)
#define  MG12_2_18PL    ~(1 << 7)
#else
#define  MG12_2_18PL    0xFFFF
#endif

#if (G12_9PL >= G12_2PL) || (G12_9PL == 0)
#define  MG12_2_19PL    ~(1 << 8)
#else
#define  MG12_2_19PL    0xFFFF
#endif

#if (G12_10PL >= G12_2PL) || (G12_10PL == 0)
#define  MG12_2_110PL    ~(1 << 9)
#else
#define  MG12_2_110PL    0xFFFF
#endif

#if (G12_11PL >= G12_2PL) || (G12_11PL == 0)
#define  MG12_2_111PL    ~(1 << 10)
#else
#define  MG12_2_111PL    0xFFFF
#endif

#if (G12_12PL >= G12_2PL) || (G12_12PL == 0)
#define  MG12_2_112PL    ~(1 << 11)
#else
#define  MG12_2_112PL    0xFFFF
#endif

#if (G12_13PL >= G12_2PL) || (G12_13PL == 0)
#define  MG12_2_113PL    ~(1 << 12)
#else
#define  MG12_2_113PL    0xFFFF
#endif

#if (G12_14PL >= G12_2PL) || (G12_14PL == 0)
#define  MG12_2_114PL    ~(1 << 13)
#else
#define  MG12_2_114PL    0xFFFF
#endif

#if (G12_15PL >= G12_2PL) || (G12_15PL == 0)
#define  MG12_2_115PL    ~(1 << 14)
#else
#define  MG12_2_115PL    0xFFFF
#endif

#if (G12_16PL >= G12_2PL) || (G12_16PL == 0)
#define  MG12_2_116PL    ~(1 << 15)
#else
#define  MG12_2_116PL    0xFFFF
#endif

#define  MG12_2_12PL	0xFFFD
#define  MG12_2    (MG12_2_11PL & MG12_2_12PL & MG12_2_13PL & MG12_2_14PL & \
                    MG12_2_15PL & MG12_2_16PL & MG12_2_17PL & MG12_2_18PL & \
                    MG12_2_19PL & MG12_2_110PL & MG12_2_111PL & MG12_2_112PL & \
                    MG12_2_113PL & MG12_2_114PL & MG12_2_115PL & MG12_2_116PL)
// End of MG12_2:
// Beginning of MG123:
#if (G12_1PL >= G12_3PL) || (G12_1PL == 0)
#define  MG12_3_11PL    ~(1 << 0)
#else
#define  MG12_3_11PL    0xFFFF
#endif

#if (G12_2PL >= G12_3PL) || (G12_2PL == 0)
#define  MG12_3_12PL    ~(1 << 1)
#else
#define  MG12_3_12PL    0xFFFF
#endif

#if (G12_4PL >= G12_3PL) || (G12_4PL == 0)
#define  MG12_3_14PL    ~(1 << 3)
#else
#define  MG12_3_14PL    0xFFFF
#endif

#if (G12_5PL >= G12_3PL) || (G12_5PL == 0)
#define  MG12_3_15PL    ~(1 << 4)
#else
#define  MG12_3_15PL    0xFFFF
#endif

#if (G12_6PL >= G12_3PL) || (G12_6PL == 0)
#define  MG12_3_16PL    ~(1 << 5)
#else
#define  MG12_3_16PL    0xFFFF
#endif

#if (G12_7PL >= G12_3PL) || (G12_7PL == 0)
#define  MG12_3_17PL    ~(1 << 6)
#else
#define  MG12_3_17PL    0xFFFF
#endif

#if (G12_8PL >= G12_3PL) || (G12_8PL == 0)
#define  MG12_3_18PL    ~(1 << 7)
#else
#define  MG12_3_18PL    0xFFFF
#endif

#if (G12_9PL >= G12_3PL) || (G12_9PL == 0)
#define  MG12_3_19PL    ~(1 << 8)
#else
#define  MG12_3_19PL    0xFFFF
#endif

#if (G12_10PL >= G12_3PL) || (G12_10PL == 0)
#define  MG12_3_110PL    ~(1 << 9)
#else
#define  MG12_3_110PL    0xFFFF
#endif

#if (G12_11PL >= G12_3PL) || (G12_11PL == 0)
#define  MG12_3_111PL    ~(1 << 10)
#else
#define  MG12_3_111PL    0xFFFF
#endif

#if (G12_12PL >= G12_3PL) || (G12_12PL == 0)
#define  MG12_3_112PL    ~(1 << 11)
#else
#define  MG12_3_112PL    0xFFFF
#endif

#if (G12_13PL >= G12_3PL) || (G12_13PL == 0)
#define  MG12_3_113PL    ~(1 << 12)
#else
#define  MG12_3_113PL    0xFFFF
#endif

#if (G12_14PL >= G12_3PL) || (G12_14PL == 0)
#define  MG12_3_114PL    ~(1 << 13)
#else
#define  MG12_3_114PL    0xFFFF
#endif

#if (G12_15PL >= G12_3PL) || (G12_15PL == 0)
#define  MG12_3_115PL    ~(1 << 14)
#else
#define  MG12_3_115PL    0xFFFF
#endif

#if (G12_16PL >= G12_3PL) || (G12_16PL == 0)
#define  MG12_3_116PL    ~(1 << 15)
#else
#define  MG12_3_116PL    0xFFFF
#endif

#define  MG12_3_13PL	0xFFFB
#define  MG12_3    (MG12_3_11PL & MG12_3_12PL & MG12_3_13PL & MG12_3_14PL & \
                    MG12_3_15PL & MG12_3_16PL & MG12_3_17PL & MG12_3_18PL & \
                    MG12_3_19PL & MG12_3_110PL & MG12_3_111PL & MG12_3_112PL & \
                    MG12_3_113PL & MG12_3_114PL & MG12_3_115PL & MG12_3_116PL)
// End of MG12_3:
// Beginning of MG124:
#if (G12_1PL >= G12_4PL) || (G12_1PL == 0)
#define  MG12_4_11PL    ~(1 << 0)
#else
#define  MG12_4_11PL    0xFFFF
#endif

#if (G12_2PL >= G12_4PL) || (G12_2PL == 0)
#define  MG12_4_12PL    ~(1 << 1)
#else
#define  MG12_4_12PL    0xFFFF
#endif

#if (G12_3PL >= G12_4PL) || (G12_3PL == 0)
#define  MG12_4_13PL    ~(1 << 2)
#else
#define  MG12_4_13PL    0xFFFF
#endif

#if (G12_5PL >= G12_4PL) || (G12_5PL == 0)
#define  MG12_4_15PL    ~(1 << 4)
#else
#define  MG12_4_15PL    0xFFFF
#endif

#if (G12_6PL >= G12_4PL) || (G12_6PL == 0)
#define  MG12_4_16PL    ~(1 << 5)
#else
#define  MG12_4_16PL    0xFFFF
#endif

#if (G12_7PL >= G12_4PL) || (G12_7PL == 0)
#define  MG12_4_17PL    ~(1 << 6)
#else
#define  MG12_4_17PL    0xFFFF
#endif

#if (G12_8PL >= G12_4PL) || (G12_8PL == 0)
#define  MG12_4_18PL    ~(1 << 7)
#else
#define  MG12_4_18PL    0xFFFF
#endif

#if (G12_9PL >= G12_4PL) || (G12_9PL == 0)
#define  MG12_4_19PL    ~(1 << 8)
#else
#define  MG12_4_19PL    0xFFFF
#endif

#if (G12_10PL >= G12_4PL) || (G12_10PL == 0)
#define  MG12_4_110PL    ~(1 << 9)
#else
#define  MG12_4_110PL    0xFFFF
#endif

#if (G12_11PL >= G12_4PL) || (G12_11PL == 0)
#define  MG12_4_111PL    ~(1 << 10)
#else
#define  MG12_4_111PL    0xFFFF
#endif

#if (G12_12PL >= G12_4PL) || (G12_12PL == 0)
#define  MG12_4_112PL    ~(1 << 11)
#else
#define  MG12_4_112PL    0xFFFF
#endif

#if (G12_13PL >= G12_4PL) || (G12_13PL == 0)
#define  MG12_4_113PL    ~(1 << 12)
#else
#define  MG12_4_113PL    0xFFFF
#endif

#if (G12_14PL >= G12_4PL) || (G12_14PL == 0)
#define  MG12_4_114PL    ~(1 << 13)
#else
#define  MG12_4_114PL    0xFFFF
#endif

#if (G12_15PL >= G12_4PL) || (G12_15PL == 0)
#define  MG12_4_115PL    ~(1 << 14)
#else
#define  MG12_4_115PL    0xFFFF
#endif

#if (G12_16PL >= G12_4PL) || (G12_16PL == 0)
#define  MG12_4_116PL    ~(1 << 15)
#else
#define  MG12_4_116PL    0xFFFF
#endif

#define  MG12_4_14PL	0xFFF7
#define  MG12_4    (MG12_4_11PL & MG12_4_12PL & MG12_4_13PL & MG12_4_14PL & \
                    MG12_4_15PL & MG12_4_16PL & MG12_4_17PL & MG12_4_18PL & \
                    MG12_4_19PL & MG12_4_110PL & MG12_4_111PL & MG12_4_112PL & \
                    MG12_4_113PL & MG12_4_114PL & MG12_4_115PL & MG12_4_116PL)
// End of MG12_4:
// Beginning of MG125:
#if (G12_1PL >= G12_5PL) || (G12_1PL == 0)
#define  MG12_5_11PL    ~(1 << 0)
#else
#define  MG12_5_11PL    0xFFFF
#endif

#if (G12_2PL >= G12_5PL) || (G12_2PL == 0)
#define  MG12_5_12PL    ~(1 << 1)
#else
#define  MG12_5_12PL    0xFFFF
#endif

#if (G12_3PL >= G12_5PL) || (G12_3PL == 0)
#define  MG12_5_13PL    ~(1 << 2)
#else
#define  MG12_5_13PL    0xFFFF
#endif

#if (G12_4PL >= G12_5PL) || (G12_4PL == 0)
#define  MG12_5_14PL    ~(1 << 3)
#else
#define  MG12_5_14PL    0xFFFF
#endif

#if (G12_6PL >= G12_5PL) || (G12_6PL == 0)
#define  MG12_5_16PL    ~(1 << 5)
#else
#define  MG12_5_16PL    0xFFFF
#endif

#if (G12_7PL >= G12_5PL) || (G12_7PL == 0)
#define  MG12_5_17PL    ~(1 << 6)
#else
#define  MG12_5_17PL    0xFFFF
#endif

#if (G12_8PL >= G12_5PL) || (G12_8PL == 0)
#define  MG12_5_18PL    ~(1 << 7)
#else
#define  MG12_5_18PL    0xFFFF
#endif

#if (G12_9PL >= G12_5PL) || (G12_9PL == 0)
#define  MG12_5_19PL    ~(1 << 8)
#else
#define  MG12_5_19PL    0xFFFF
#endif

#if (G12_10PL >= G12_5PL) || (G12_10PL == 0)
#define  MG12_5_110PL    ~(1 << 9)
#else
#define  MG12_5_110PL    0xFFFF
#endif

#if (G12_11PL >= G12_5PL) || (G12_11PL == 0)
#define  MG12_5_111PL    ~(1 << 10)
#else
#define  MG12_5_111PL    0xFFFF
#endif

#if (G12_12PL >= G12_5PL) || (G12_12PL == 0)
#define  MG12_5_112PL    ~(1 << 11)
#else
#define  MG12_5_112PL    0xFFFF
#endif

#if (G12_13PL >= G12_5PL) || (G12_13PL == 0)
#define  MG12_5_113PL    ~(1 << 12)
#else
#define  MG12_5_113PL    0xFFFF
#endif

#if (G12_14PL >= G12_5PL) || (G12_14PL == 0)
#define  MG12_5_114PL    ~(1 << 13)
#else
#define  MG12_5_114PL    0xFFFF
#endif

#if (G12_15PL >= G12_5PL) || (G12_15PL == 0)
#define  MG12_5_115PL    ~(1 << 14)
#else
#define  MG12_5_115PL    0xFFFF
#endif

#if (G12_16PL >= G12_5PL) || (G12_16PL == 0)
#define  MG12_5_116PL    ~(1 << 15)
#else
#define  MG12_5_116PL    0xFFFF
#endif

#define  MG12_5_15PL	0xFFEF
#define  MG12_5    (MG12_5_11PL & MG12_5_12PL & MG12_5_13PL & MG12_5_14PL & \
                    MG12_5_15PL & MG12_5_16PL & MG12_5_17PL & MG12_5_18PL & \
                    MG12_5_19PL & MG12_5_110PL & MG12_5_111PL & MG12_5_112PL & \
                    MG12_5_113PL & MG12_5_114PL & MG12_5_115PL & MG12_5_116PL)
// End of MG12_5:
// Beginning of MG126:
#if (G12_1PL >= G12_6PL) || (G12_1PL == 0)
#define  MG12_6_11PL    ~(1 << 0)
#else
#define  MG12_6_11PL    0xFFFF
#endif

#if (G12_2PL >= G12_6PL) || (G12_2PL == 0)
#define  MG12_6_12PL    ~(1 << 1)
#else
#define  MG12_6_12PL    0xFFFF
#endif

#if (G12_3PL >= G12_6PL) || (G12_3PL == 0)
#define  MG12_6_13PL    ~(1 << 2)
#else
#define  MG12_6_13PL    0xFFFF
#endif

#if (G12_4PL >= G12_6PL) || (G12_4PL == 0)
#define  MG12_6_14PL    ~(1 << 3)
#else
#define  MG12_6_14PL    0xFFFF
#endif

#if (G12_5PL >= G12_6PL) || (G12_5PL == 0)
#define  MG12_6_15PL    ~(1 << 4)
#else
#define  MG12_6_15PL    0xFFFF
#endif

#if (G12_7PL >= G12_6PL) || (G12_7PL == 0)
#define  MG12_6_17PL    ~(1 << 6)
#else
#define  MG12_6_17PL    0xFFFF
#endif

#if (G12_8PL >= G12_6PL) || (G12_8PL == 0)
#define  MG12_6_18PL    ~(1 << 7)
#else
#define  MG12_6_18PL    0xFFFF
#endif

#if (G12_9PL >= G12_6PL) || (G12_9PL == 0)
#define  MG12_6_19PL    ~(1 << 8)
#else
#define  MG12_6_19PL    0xFFFF
#endif

#if (G12_10PL >= G12_6PL) || (G12_10PL == 0)
#define  MG12_6_110PL    ~(1 << 9)
#else
#define  MG12_6_110PL    0xFFFF
#endif

#if (G12_11PL >= G12_6PL) || (G12_11PL == 0)
#define  MG12_6_111PL    ~(1 << 10)
#else
#define  MG12_6_111PL    0xFFFF
#endif

#if (G12_12PL >= G12_6PL) || (G12_12PL == 0)
#define  MG12_6_112PL    ~(1 << 11)
#else
#define  MG12_6_112PL    0xFFFF
#endif

#if (G12_13PL >= G12_6PL) || (G12_13PL == 0)
#define  MG12_6_113PL    ~(1 << 12)
#else
#define  MG12_6_113PL    0xFFFF
#endif

#if (G12_14PL >= G12_6PL) || (G12_14PL == 0)
#define  MG12_6_114PL    ~(1 << 13)
#else
#define  MG12_6_114PL    0xFFFF
#endif

#if (G12_15PL >= G12_6PL) || (G12_15PL == 0)
#define  MG12_6_115PL    ~(1 << 14)
#else
#define  MG12_6_115PL    0xFFFF
#endif

#if (G12_16PL >= G12_6PL) || (G12_16PL == 0)
#define  MG12_6_116PL    ~(1 << 15)
#else
#define  MG12_6_116PL    0xFFFF
#endif

#define  MG12_6_16PL	0xFFDF
#define  MG12_6    (MG12_6_11PL & MG12_6_12PL & MG12_6_13PL & MG12_6_14PL & \
                    MG12_6_15PL & MG12_6_16PL & MG12_6_17PL & MG12_6_18PL & \
                    MG12_6_19PL & MG12_6_110PL & MG12_6_111PL & MG12_6_112PL & \
                    MG12_6_113PL & MG12_6_114PL & MG12_6_115PL & MG12_6_116PL)
// End of MG12_6:
// Beginning of MG127:
#if (G12_1PL >= G12_7PL) || (G12_1PL == 0)
#define  MG12_7_11PL    ~(1 << 0)
#else
#define  MG12_7_11PL    0xFFFF
#endif

#if (G12_2PL >= G12_7PL) || (G12_2PL == 0)
#define  MG12_7_12PL    ~(1 << 1)
#else
#define  MG12_7_12PL    0xFFFF
#endif

#if (G12_3PL >= G12_7PL) || (G12_3PL == 0)
#define  MG12_7_13PL    ~(1 << 2)
#else
#define  MG12_7_13PL    0xFFFF
#endif

#if (G12_4PL >= G12_7PL) || (G12_4PL == 0)
#define  MG12_7_14PL    ~(1 << 3)
#else
#define  MG12_7_14PL    0xFFFF
#endif

#if (G12_5PL >= G12_7PL) || (G12_5PL == 0)
#define  MG12_7_15PL    ~(1 << 4)
#else
#define  MG12_7_15PL    0xFFFF
#endif

#if (G12_6PL >= G12_7PL) || (G12_6PL == 0)
#define  MG12_7_16PL    ~(1 << 5)
#else
#define  MG12_7_16PL    0xFFFF
#endif

#if (G12_8PL >= G12_7PL) || (G12_8PL == 0)
#define  MG12_7_18PL    ~(1 << 7)
#else
#define  MG12_7_18PL    0xFFFF
#endif

#if (G12_9PL >= G12_7PL) || (G12_9PL == 0)
#define  MG12_7_19PL    ~(1 << 8)
#else
#define  MG12_7_19PL    0xFFFF
#endif

#if (G12_10PL >= G12_7PL) || (G12_10PL == 0)
#define  MG12_7_110PL    ~(1 << 9)
#else
#define  MG12_7_110PL    0xFFFF
#endif

#if (G12_11PL >= G12_7PL) || (G12_11PL == 0)
#define  MG12_7_111PL    ~(1 << 10)
#else
#define  MG12_7_111PL    0xFFFF
#endif

#if (G12_12PL >= G12_7PL) || (G12_12PL == 0)
#define  MG12_7_112PL    ~(1 << 11)
#else
#define  MG12_7_112PL    0xFFFF
#endif

#if (G12_13PL >= G12_7PL) || (G12_13PL == 0)
#define  MG12_7_113PL    ~(1 << 12)
#else
#define  MG12_7_113PL    0xFFFF
#endif

#if (G12_14PL >= G12_7PL) || (G12_14PL == 0)
#define  MG12_7_114PL    ~(1 << 13)
#else
#define  MG12_7_114PL    0xFFFF
#endif

#if (G12_15PL >= G12_7PL) || (G12_15PL == 0)
#define  MG12_7_115PL    ~(1 << 14)
#else
#define  MG12_7_115PL    0xFFFF
#endif

#if (G12_16PL >= G12_7PL) || (G12_16PL == 0)
#define  MG12_7_116PL    ~(1 << 15)
#else
#define  MG12_7_116PL    0xFFFF
#endif

#define  MG12_7_17PL	0xFFBF
#define  MG12_7    (MG12_7_11PL & MG12_7_12PL & MG12_7_13PL & MG12_7_14PL & \
                    MG12_7_15PL & MG12_7_16PL & MG12_7_17PL & MG12_7_18PL & \
                    MG12_7_19PL & MG12_7_110PL & MG12_7_111PL & MG12_7_112PL & \
                    MG12_7_113PL & MG12_7_114PL & MG12_7_115PL & MG12_7_116PL)
// End of MG12_7:
// Beginning of MG128:
#if (G12_1PL >= G12_8PL) || (G12_1PL == 0)
#define  MG12_8_11PL    ~(1 << 0)
#else
#define  MG12_8_11PL    0xFFFF
#endif

#if (G12_2PL >= G12_8PL) || (G12_2PL == 0)
#define  MG12_8_12PL    ~(1 << 1)
#else
#define  MG12_8_12PL    0xFFFF
#endif

#if (G12_3PL >= G12_8PL) || (G12_3PL == 0)
#define  MG12_8_13PL    ~(1 << 2)
#else
#define  MG12_8_13PL    0xFFFF
#endif

#if (G12_4PL >= G12_8PL) || (G12_4PL == 0)
#define  MG12_8_14PL    ~(1 << 3)
#else
#define  MG12_8_14PL    0xFFFF
#endif

#if (G12_5PL >= G12_8PL) || (G12_5PL == 0)
#define  MG12_8_15PL    ~(1 << 4)
#else
#define  MG12_8_15PL    0xFFFF
#endif

#if (G12_6PL >= G12_8PL) || (G12_6PL == 0)
#define  MG12_8_16PL    ~(1 << 5)
#else
#define  MG12_8_16PL    0xFFFF
#endif

#if (G12_7PL >= G12_8PL) || (G12_7PL == 0)
#define  MG12_8_17PL    ~(1 << 6)
#else
#define  MG12_8_17PL    0xFFFF
#endif

#if (G12_9PL >= G12_8PL) || (G12_9PL == 0)
#define  MG12_8_19PL    ~(1 << 8)
#else
#define  MG12_8_19PL    0xFFFF
#endif

#if (G12_10PL >= G12_8PL) || (G12_10PL == 0)
#define  MG12_8_110PL    ~(1 << 9)
#else
#define  MG12_8_110PL    0xFFFF
#endif

#if (G12_11PL >= G12_8PL) || (G12_11PL == 0)
#define  MG12_8_111PL    ~(1 << 10)
#else
#define  MG12_8_111PL    0xFFFF
#endif

#if (G12_12PL >= G12_8PL) || (G12_12PL == 0)
#define  MG12_8_112PL    ~(1 << 11)
#else
#define  MG12_8_112PL    0xFFFF
#endif

#if (G12_13PL >= G12_8PL) || (G12_13PL == 0)
#define  MG12_8_113PL    ~(1 << 12)
#else
#define  MG12_8_113PL    0xFFFF
#endif

#if (G12_14PL >= G12_8PL) || (G12_14PL == 0)
#define  MG12_8_114PL    ~(1 << 13)
#else
#define  MG12_8_114PL    0xFFFF
#endif

#if (G12_15PL >= G12_8PL) || (G12_15PL == 0)
#define  MG12_8_115PL    ~(1 << 14)
#else
#define  MG12_8_115PL    0xFFFF
#endif

#if (G12_16PL >= G12_8PL) || (G12_16PL == 0)
#define  MG12_8_116PL    ~(1 << 15)
#else
#define  MG12_8_116PL    0xFFFF
#endif

#define  MG12_8_18PL	0xFF7F
#define  MG12_8    (MG12_8_11PL & MG12_8_12PL & MG12_8_13PL & MG12_8_14PL & \
                    MG12_8_15PL & MG12_8_16PL & MG12_8_17PL & MG12_8_18PL & \
                    MG12_8_19PL & MG12_8_110PL & MG12_8_111PL & MG12_8_112PL & \
                    MG12_8_113PL & MG12_8_114PL & MG12_8_115PL & MG12_8_116PL)
// End of MG12_8:
// Beginning of MG129:
#if (G12_1PL >= G12_9PL) || (G12_1PL == 0)
#define  MG12_9_11PL    ~(1 << 0)
#else
#define  MG12_9_11PL    0xFFFF
#endif

#if (G12_2PL >= G12_9PL) || (G12_2PL == 0)
#define  MG12_9_12PL    ~(1 << 1)
#else
#define  MG12_9_12PL    0xFFFF
#endif

#if (G12_3PL >= G12_9PL) || (G12_3PL == 0)
#define  MG12_9_13PL    ~(1 << 2)
#else
#define  MG12_9_13PL    0xFFFF
#endif

#if (G12_4PL >= G12_9PL) || (G12_4PL == 0)
#define  MG12_9_14PL    ~(1 << 3)
#else
#define  MG12_9_14PL    0xFFFF
#endif

#if (G12_5PL >= G12_9PL) || (G12_5PL == 0)
#define  MG12_9_15PL    ~(1 << 4)
#else
#define  MG12_9_15PL    0xFFFF
#endif

#if (G12_6PL >= G12_9PL) || (G12_6PL == 0)
#define  MG12_9_16PL    ~(1 << 5)
#else
#define  MG12_9_16PL    0xFFFF
#endif

#if (G12_7PL >= G12_9PL) || (G12_7PL == 0)
#define  MG12_9_17PL    ~(1 << 6)
#else
#define  MG12_9_17PL    0xFFFF
#endif

#if (G12_8PL >= G12_9PL) || (G12_8PL == 0)
#define  MG12_9_18PL    ~(1 << 7)
#else
#define  MG12_9_18PL    0xFFFF
#endif

#if (G12_10PL >= G12_9PL) || (G12_10PL == 0)
#define  MG12_9_110PL    ~(1 << 9)
#else
#define  MG12_9_110PL    0xFFFF
#endif

#if (G12_11PL >= G12_9PL) || (G12_11PL == 0)
#define  MG12_9_111PL    ~(1 << 10)
#else
#define  MG12_9_111PL    0xFFFF
#endif

#if (G12_12PL >= G12_9PL) || (G12_12PL == 0)
#define  MG12_9_112PL    ~(1 << 11)
#else
#define  MG12_9_112PL    0xFFFF
#endif

#if (G12_13PL >= G12_9PL) || (G12_13PL == 0)
#define  MG12_9_113PL    ~(1 << 12)
#else
#define  MG12_9_113PL    0xFFFF
#endif

#if (G12_14PL >= G12_9PL) || (G12_14PL == 0)
#define  MG12_9_114PL    ~(1 << 13)
#else
#define  MG12_9_114PL    0xFFFF
#endif

#if (G12_15PL >= G12_9PL) || (G12_15PL == 0)
#define  MG12_9_115PL    ~(1 << 14)
#else
#define  MG12_9_115PL    0xFFFF
#endif

#if (G12_16PL >= G12_9PL) || (G12_16PL == 0)
#define  MG12_9_116PL    ~(1 << 15)
#else
#define  MG12_9_116PL    0xFFFF
#endif

#define  MG12_9_19PL	0xFEFF
#define  MG12_9    (MG12_9_11PL & MG12_9_12PL & MG12_9_13PL & MG12_9_14PL & \
                    MG12_9_15PL & MG12_9_16PL & MG12_9_17PL & MG12_9_18PL & \
                    MG12_9_19PL & MG12_9_110PL & MG12_9_111PL & MG12_9_112PL & \
                    MG12_9_113PL & MG12_9_114PL & MG12_9_115PL & MG12_9_116PL)
// End of MG12_9:
// Beginning of MG1210:
#if (G12_1PL >= G12_10PL) || (G12_1PL == 0)
#define  MG12_10_11PL    ~(1 << 0)
#else
#define  MG12_10_11PL    0xFFFF
#endif

#if (G12_2PL >= G12_10PL) || (G12_2PL == 0)
#define  MG12_10_12PL    ~(1 << 1)
#else
#define  MG12_10_12PL    0xFFFF
#endif

#if (G12_3PL >= G12_10PL) || (G12_3PL == 0)
#define  MG12_10_13PL    ~(1 << 2)
#else
#define  MG12_10_13PL    0xFFFF
#endif

#if (G12_4PL >= G12_10PL) || (G12_4PL == 0)
#define  MG12_10_14PL    ~(1 << 3)
#else
#define  MG12_10_14PL    0xFFFF
#endif

#if (G12_5PL >= G12_10PL) || (G12_5PL == 0)
#define  MG12_10_15PL    ~(1 << 4)
#else
#define  MG12_10_15PL    0xFFFF
#endif

#if (G12_6PL >= G12_10PL) || (G12_6PL == 0)
#define  MG12_10_16PL    ~(1 << 5)
#else
#define  MG12_10_16PL    0xFFFF
#endif

#if (G12_7PL >= G12_10PL) || (G12_7PL == 0)
#define  MG12_10_17PL    ~(1 << 6)
#else
#define  MG12_10_17PL    0xFFFF
#endif

#if (G12_8PL >= G12_10PL) || (G12_8PL == 0)
#define  MG12_10_18PL    ~(1 << 7)
#else
#define  MG12_10_18PL    0xFFFF
#endif

#if (G12_9PL >= G12_10PL) || (G12_9PL == 0)
#define  MG12_10_19PL    ~(1 << 8)
#else
#define  MG12_10_19PL    0xFFFF
#endif

#if (G12_11PL >= G12_10PL) || (G12_11PL == 0)
#define  MG12_10_111PL    ~(1 << 10)
#else
#define  MG12_10_111PL    0xFFFF
#endif

#if (G12_12PL >= G12_10PL) || (G12_12PL == 0)
#define  MG12_10_112PL    ~(1 << 11)
#else
#define  MG12_10_112PL    0xFFFF
#endif

#if (G12_13PL >= G12_10PL) || (G12_13PL == 0)
#define  MG12_10_113PL    ~(1 << 12)
#else
#define  MG12_10_113PL    0xFFFF
#endif

#if (G12_14PL >= G12_10PL) || (G12_14PL == 0)
#define  MG12_10_114PL    ~(1 << 13)
#else
#define  MG12_10_114PL    0xFFFF
#endif

#if (G12_15PL >= G12_10PL) || (G12_15PL == 0)
#define  MG12_10_115PL    ~(1 << 14)
#else
#define  MG12_10_115PL    0xFFFF
#endif

#if (G12_16PL >= G12_10PL) || (G12_16PL == 0)
#define  MG12_10_116PL    ~(1 << 15)
#else
#define  MG12_10_116PL    0xFFFF
#endif

#define  MG12_10_110PL	0xFDFF
#define  MG12_10    (MG12_10_11PL & MG12_10_12PL & MG12_10_13PL & MG12_10_14PL & \
                    MG12_10_15PL & MG12_10_16PL & MG12_10_17PL & MG12_10_18PL & \
                    MG12_10_19PL & MG12_10_110PL & MG12_10_111PL & MG12_10_112PL & \
                    MG12_10_113PL & MG12_10_114PL & MG12_10_115PL & MG12_10_116PL)
// End of MG12_10:
// Beginning of MG1211:
#if (G12_1PL >= G12_11PL) || (G12_1PL == 0)
#define  MG12_11_11PL    ~(1 << 0)
#else
#define  MG12_11_11PL    0xFFFF
#endif

#if (G12_2PL >= G12_11PL) || (G12_2PL == 0)
#define  MG12_11_12PL    ~(1 << 1)
#else
#define  MG12_11_12PL    0xFFFF
#endif

#if (G12_3PL >= G12_11PL) || (G12_3PL == 0)
#define  MG12_11_13PL    ~(1 << 2)
#else
#define  MG12_11_13PL    0xFFFF
#endif

#if (G12_4PL >= G12_11PL) || (G12_4PL == 0)
#define  MG12_11_14PL    ~(1 << 3)
#else
#define  MG12_11_14PL    0xFFFF
#endif

#if (G12_5PL >= G12_11PL) || (G12_5PL == 0)
#define  MG12_11_15PL    ~(1 << 4)
#else
#define  MG12_11_15PL    0xFFFF
#endif

#if (G12_6PL >= G12_11PL) || (G12_6PL == 0)
#define  MG12_11_16PL    ~(1 << 5)
#else
#define  MG12_11_16PL    0xFFFF
#endif

#if (G12_7PL >= G12_11PL) || (G12_7PL == 0)
#define  MG12_11_17PL    ~(1 << 6)
#else
#define  MG12_11_17PL    0xFFFF
#endif

#if (G12_8PL >= G12_11PL) || (G12_8PL == 0)
#define  MG12_11_18PL    ~(1 << 7)
#else
#define  MG12_11_18PL    0xFFFF
#endif

#if (G12_9PL >= G12_11PL) || (G12_9PL == 0)
#define  MG12_11_19PL    ~(1 << 8)
#else
#define  MG12_11_19PL    0xFFFF
#endif

#if (G12_10PL >= G12_11PL) || (G12_10PL == 0)
#define  MG12_11_110PL    ~(1 << 9)
#else
#define  MG12_11_110PL    0xFFFF
#endif

#if (G12_12PL >= G12_11PL) || (G12_12PL == 0)
#define  MG12_11_112PL    ~(1 << 11)
#else
#define  MG12_11_112PL    0xFFFF
#endif

#if (G12_13PL >= G12_11PL) || (G12_13PL == 0)
#define  MG12_11_113PL    ~(1 << 12)
#else
#define  MG12_11_113PL    0xFFFF
#endif

#if (G12_14PL >= G12_11PL) || (G12_14PL == 0)
#define  MG12_11_114PL    ~(1 << 13)
#else
#define  MG12_11_114PL    0xFFFF
#endif

#if (G12_15PL >= G12_11PL) || (G12_15PL == 0)
#define  MG12_11_115PL    ~(1 << 14)
#else
#define  MG12_11_115PL    0xFFFF
#endif

#if (G12_16PL >= G12_11PL) || (G12_16PL == 0)
#define  MG12_11_116PL    ~(1 << 15)
#else
#define  MG12_11_116PL    0xFFFF
#endif

#define  MG12_11_111PL	0xFBFF
#define  MG12_11    (MG12_11_11PL & MG12_11_12PL & MG12_11_13PL & MG12_11_14PL & \
                    MG12_11_15PL & MG12_11_16PL & MG12_11_17PL & MG12_11_18PL & \
                    MG12_11_19PL & MG12_11_110PL & MG12_11_111PL & MG12_11_112PL & \
                    MG12_11_113PL & MG12_11_114PL & MG12_11_115PL & MG12_11_116PL)
// End of MG12_11:
// Beginning of MG1212:
#if (G12_1PL >= G12_12PL) || (G12_1PL == 0)
#define  MG12_12_11PL    ~(1 << 0)
#else
#define  MG12_12_11PL    0xFFFF
#endif

#if (G12_2PL >= G12_12PL) || (G12_2PL == 0)
#define  MG12_12_12PL    ~(1 << 1)
#else
#define  MG12_12_12PL    0xFFFF
#endif

#if (G12_3PL >= G12_12PL) || (G12_3PL == 0)
#define  MG12_12_13PL    ~(1 << 2)
#else
#define  MG12_12_13PL    0xFFFF
#endif

#if (G12_4PL >= G12_12PL) || (G12_4PL == 0)
#define  MG12_12_14PL    ~(1 << 3)
#else
#define  MG12_12_14PL    0xFFFF
#endif

#if (G12_5PL >= G12_12PL) || (G12_5PL == 0)
#define  MG12_12_15PL    ~(1 << 4)
#else
#define  MG12_12_15PL    0xFFFF
#endif

#if (G12_6PL >= G12_12PL) || (G12_6PL == 0)
#define  MG12_12_16PL    ~(1 << 5)
#else
#define  MG12_12_16PL    0xFFFF
#endif

#if (G12_7PL >= G12_12PL) || (G12_7PL == 0)
#define  MG12_12_17PL    ~(1 << 6)
#else
#define  MG12_12_17PL    0xFFFF
#endif

#if (G12_8PL >= G12_12PL) || (G12_8PL == 0)
#define  MG12_12_18PL    ~(1 << 7)
#else
#define  MG12_12_18PL    0xFFFF
#endif

#if (G12_9PL >= G12_12PL) || (G12_9PL == 0)
#define  MG12_12_19PL    ~(1 << 8)
#else
#define  MG12_12_19PL    0xFFFF
#endif

#if (G12_10PL >= G12_12PL) || (G12_10PL == 0)
#define  MG12_12_110PL    ~(1 << 9)
#else
#define  MG12_12_110PL    0xFFFF
#endif

#if (G12_11PL >= G12_12PL) || (G12_11PL == 0)
#define  MG12_12_111PL    ~(1 << 10)
#else
#define  MG12_12_111PL    0xFFFF
#endif

#if (G12_13PL >= G12_12PL) || (G12_13PL == 0)
#define  MG12_12_113PL    ~(1 << 12)
#else
#define  MG12_12_113PL    0xFFFF
#endif

#if (G12_14PL >= G12_12PL) || (G12_14PL == 0)
#define  MG12_12_114PL    ~(1 << 13)
#else
#define  MG12_12_114PL    0xFFFF
#endif

#if (G12_15PL >= G12_12PL) || (G12_15PL == 0)
#define  MG12_12_115PL    ~(1 << 14)
#else
#define  MG12_12_115PL    0xFFFF
#endif

#if (G12_16PL >= G12_12PL) || (G12_16PL == 0)
#define  MG12_12_116PL    ~(1 << 15)
#else
#define  MG12_12_116PL    0xFFFF
#endif

#define  MG12_12_112PL	0xF7FF
#define  MG12_12    (MG12_12_11PL & MG12_12_12PL & MG12_12_13PL & MG12_12_14PL & \
                    MG12_12_15PL & MG12_12_16PL & MG12_12_17PL & MG12_12_18PL & \
                    MG12_12_19PL & MG12_12_110PL & MG12_12_111PL & MG12_12_112PL & \
                    MG12_12_113PL & MG12_12_114PL & MG12_12_115PL & MG12_12_116PL)
// End of MG12_12:
// Beginning of MG1213:
#if (G12_1PL >= G12_13PL) || (G12_1PL == 0)
#define  MG12_13_11PL    ~(1 << 0)
#else
#define  MG12_13_11PL    0xFFFF
#endif

#if (G12_2PL >= G12_13PL) || (G12_2PL == 0)
#define  MG12_13_12PL    ~(1 << 1)
#else
#define  MG12_13_12PL    0xFFFF
#endif

#if (G12_3PL >= G12_13PL) || (G12_3PL == 0)
#define  MG12_13_13PL    ~(1 << 2)
#else
#define  MG12_13_13PL    0xFFFF
#endif

#if (G12_4PL >= G12_13PL) || (G12_4PL == 0)
#define  MG12_13_14PL    ~(1 << 3)
#else
#define  MG12_13_14PL    0xFFFF
#endif

#if (G12_5PL >= G12_13PL) || (G12_5PL == 0)
#define  MG12_13_15PL    ~(1 << 4)
#else
#define  MG12_13_15PL    0xFFFF
#endif

#if (G12_6PL >= G12_13PL) || (G12_6PL == 0)
#define  MG12_13_16PL    ~(1 << 5)
#else
#define  MG12_13_16PL    0xFFFF
#endif

#if (G12_7PL >= G12_13PL) || (G12_7PL == 0)
#define  MG12_13_17PL    ~(1 << 6)
#else
#define  MG12_13_17PL    0xFFFF
#endif

#if (G12_8PL >= G12_13PL) || (G12_8PL == 0)
#define  MG12_13_18PL    ~(1 << 7)
#else
#define  MG12_13_18PL    0xFFFF
#endif

#if (G12_9PL >= G12_13PL) || (G12_9PL == 0)
#define  MG12_13_19PL    ~(1 << 8)
#else
#define  MG12_13_19PL    0xFFFF
#endif

#if (G12_10PL >= G12_13PL) || (G12_10PL == 0)
#define  MG12_13_110PL    ~(1 << 9)
#else
#define  MG12_13_110PL    0xFFFF
#endif

#if (G12_11PL >= G12_13PL) || (G12_11PL == 0)
#define  MG12_13_111PL    ~(1 << 10)
#else
#define  MG12_13_111PL    0xFFFF
#endif

#if (G12_12PL >= G12_13PL) || (G12_12PL == 0)
#define  MG12_13_112PL    ~(1 << 11)
#else
#define  MG12_13_112PL    0xFFFF
#endif

#if (G12_14PL >= G12_13PL) || (G12_14PL == 0)
#define  MG12_13_114PL    ~(1 << 13)
#else
#define  MG12_13_114PL    0xFFFF
#endif

#if (G12_15PL >= G12_13PL) || (G12_15PL == 0)
#define  MG12_13_115PL    ~(1 << 14)
#else
#define  MG12_13_115PL    0xFFFF
#endif

#if (G12_16PL >= G12_13PL) || (G12_16PL == 0)
#define  MG12_13_116PL    ~(1 << 15)
#else
#define  MG12_13_116PL    0xFFFF
#endif

#define  MG12_13_113PL	0xEFFF
#define  MG12_13    (MG12_13_11PL & MG12_13_12PL & MG12_13_13PL & MG12_13_14PL & \
                    MG12_13_15PL & MG12_13_16PL & MG12_13_17PL & MG12_13_18PL & \
                    MG12_13_19PL & MG12_13_110PL & MG12_13_111PL & MG12_13_112PL & \
                    MG12_13_113PL & MG12_13_114PL & MG12_13_115PL & MG12_13_116PL)
// End of MG12_13:
// Beginning of MG1214:
#if (G12_1PL >= G12_14PL) || (G12_1PL == 0)
#define  MG12_14_11PL    ~(1 << 0)
#else
#define  MG12_14_11PL    0xFFFF
#endif

#if (G12_2PL >= G12_14PL) || (G12_2PL == 0)
#define  MG12_14_12PL    ~(1 << 1)
#else
#define  MG12_14_12PL    0xFFFF
#endif

#if (G12_3PL >= G12_14PL) || (G12_3PL == 0)
#define  MG12_14_13PL    ~(1 << 2)
#else
#define  MG12_14_13PL    0xFFFF
#endif

#if (G12_4PL >= G12_14PL) || (G12_4PL == 0)
#define  MG12_14_14PL    ~(1 << 3)
#else
#define  MG12_14_14PL    0xFFFF
#endif

#if (G12_5PL >= G12_14PL) || (G12_5PL == 0)
#define  MG12_14_15PL    ~(1 << 4)
#else
#define  MG12_14_15PL    0xFFFF
#endif

#if (G12_6PL >= G12_14PL) || (G12_6PL == 0)
#define  MG12_14_16PL    ~(1 << 5)
#else
#define  MG12_14_16PL    0xFFFF
#endif

#if (G12_7PL >= G12_14PL) || (G12_7PL == 0)
#define  MG12_14_17PL    ~(1 << 6)
#else
#define  MG12_14_17PL    0xFFFF
#endif

#if (G12_8PL >= G12_14PL) || (G12_8PL == 0)
#define  MG12_14_18PL    ~(1 << 7)
#else
#define  MG12_14_18PL    0xFFFF
#endif

#if (G12_9PL >= G12_14PL) || (G12_9PL == 0)
#define  MG12_14_19PL    ~(1 << 8)
#else
#define  MG12_14_19PL    0xFFFF
#endif

#if (G12_10PL >= G12_14PL) || (G12_10PL == 0)
#define  MG12_14_110PL    ~(1 << 9)
#else
#define  MG12_14_110PL    0xFFFF
#endif

#if (G12_11PL >= G12_14PL) || (G12_11PL == 0)
#define  MG12_14_111PL    ~(1 << 10)
#else
#define  MG12_14_111PL    0xFFFF
#endif

#if (G12_12PL >= G12_14PL) || (G12_12PL == 0)
#define  MG12_14_112PL    ~(1 << 11)
#else
#define  MG12_14_112PL    0xFFFF
#endif

#if (G12_13PL >= G12_14PL) || (G12_13PL == 0)
#define  MG12_14_113PL    ~(1 << 12)
#else
#define  MG12_14_113PL    0xFFFF
#endif

#if (G12_15PL >= G12_14PL) || (G12_15PL == 0)
#define  MG12_14_115PL    ~(1 << 14)
#else
#define  MG12_14_115PL    0xFFFF
#endif

#if (G12_16PL >= G12_14PL) || (G12_16PL == 0)
#define  MG12_14_116PL    ~(1 << 15)
#else
#define  MG12_14_116PL    0xFFFF
#endif

#define  MG12_14_114PL	0xDFFF
#define  MG12_14    (MG12_14_11PL & MG12_14_12PL & MG12_14_13PL & MG12_14_14PL & \
                    MG12_14_15PL & MG12_14_16PL & MG12_14_17PL & MG12_14_18PL & \
                    MG12_14_19PL & MG12_14_110PL & MG12_14_111PL & MG12_14_112PL & \
                    MG12_14_113PL & MG12_14_114PL & MG12_14_115PL & MG12_14_116PL)
// End of MG12_14:
// Beginning of MG1215:
#if (G12_1PL >= G12_15PL) || (G12_1PL == 0)
#define  MG12_15_11PL    ~(1 << 0)
#else
#define  MG12_15_11PL    0xFFFF
#endif

#if (G12_2PL >= G12_15PL) || (G12_2PL == 0)
#define  MG12_15_12PL    ~(1 << 1)
#else
#define  MG12_15_12PL    0xFFFF
#endif

#if (G12_3PL >= G12_15PL) || (G12_3PL == 0)
#define  MG12_15_13PL    ~(1 << 2)
#else
#define  MG12_15_13PL    0xFFFF
#endif

#if (G12_4PL >= G12_15PL) || (G12_4PL == 0)
#define  MG12_15_14PL    ~(1 << 3)
#else
#define  MG12_15_14PL    0xFFFF
#endif

#if (G12_5PL >= G12_15PL) || (G12_5PL == 0)
#define  MG12_15_15PL    ~(1 << 4)
#else
#define  MG12_15_15PL    0xFFFF
#endif

#if (G12_6PL >= G12_15PL) || (G12_6PL == 0)
#define  MG12_15_16PL    ~(1 << 5)
#else
#define  MG12_15_16PL    0xFFFF
#endif

#if (G12_7PL >= G12_15PL) || (G12_7PL == 0)
#define  MG12_15_17PL    ~(1 << 6)
#else
#define  MG12_15_17PL    0xFFFF
#endif

#if (G12_8PL >= G12_15PL) || (G12_8PL == 0)
#define  MG12_15_18PL    ~(1 << 7)
#else
#define  MG12_15_18PL    0xFFFF
#endif

#if (G12_9PL >= G12_15PL) || (G12_9PL == 0)
#define  MG12_15_19PL    ~(1 << 8)
#else
#define  MG12_15_19PL    0xFFFF
#endif

#if (G12_10PL >= G12_15PL) || (G12_10PL == 0)
#define  MG12_15_110PL    ~(1 << 9)
#else
#define  MG12_15_110PL    0xFFFF
#endif

#if (G12_11PL >= G12_15PL) || (G12_11PL == 0)
#define  MG12_15_111PL    ~(1 << 10)
#else
#define  MG12_15_111PL    0xFFFF
#endif

#if (G12_12PL >= G12_15PL) || (G12_12PL == 0)
#define  MG12_15_112PL    ~(1 << 11)
#else
#define  MG12_15_112PL    0xFFFF
#endif

#if (G12_13PL >= G12_15PL) || (G12_13PL == 0)
#define  MG12_15_113PL    ~(1 << 12)
#else
#define  MG12_15_113PL    0xFFFF
#endif

#if (G12_14PL >= G12_15PL) || (G12_14PL == 0)
#define  MG12_15_114PL    ~(1 << 13)
#else
#define  MG12_15_114PL    0xFFFF
#endif

#if (G12_16PL >= G12_15PL) || (G12_16PL == 0)
#define  MG12_15_116PL    ~(1 << 15)
#else
#define  MG12_15_116PL    0xFFFF
#endif

#define  MG12_15_115PL	0xBFFF
#define  MG12_15    (MG12_15_11PL & MG12_15_12PL & MG12_15_13PL & MG12_15_14PL & \
                    MG12_15_15PL & MG12_15_16PL & MG12_15_17PL & MG12_15_18PL & \
                    MG12_15_19PL & MG12_15_110PL & MG12_15_111PL & MG12_15_112PL & \
                    MG12_15_113PL & MG12_15_114PL & MG12_15_115PL & MG12_15_116PL)
// End of MG12_15:
// Beginning of MG1216:
#if (G12_1PL >= G12_16PL) || (G12_1PL == 0)
#define  MG12_16_11PL    ~(1 << 0)
#else
#define  MG12_16_11PL    0xFFFF
#endif

#if (G12_2PL >= G12_16PL) || (G12_2PL == 0)
#define  MG12_16_12PL    ~(1 << 1)
#else
#define  MG12_16_12PL    0xFFFF
#endif

#if (G12_3PL >= G12_16PL) || (G12_3PL == 0)
#define  MG12_16_13PL    ~(1 << 2)
#else
#define  MG12_16_13PL    0xFFFF
#endif

#if (G12_4PL >= G12_16PL) || (G12_4PL == 0)
#define  MG12_16_14PL    ~(1 << 3)
#else
#define  MG12_16_14PL    0xFFFF
#endif

#if (G12_5PL >= G12_16PL) || (G12_5PL == 0)
#define  MG12_16_15PL    ~(1 << 4)
#else
#define  MG12_16_15PL    0xFFFF
#endif

#if (G12_6PL >= G12_16PL) || (G12_6PL == 0)
#define  MG12_16_16PL    ~(1 << 5)
#else
#define  MG12_16_16PL    0xFFFF
#endif

#if (G12_7PL >= G12_16PL) || (G12_7PL == 0)
#define  MG12_16_17PL    ~(1 << 6)
#else
#define  MG12_16_17PL    0xFFFF
#endif

#if (G12_8PL >= G12_16PL) || (G12_8PL == 0)
#define  MG12_16_18PL    ~(1 << 7)
#else
#define  MG12_16_18PL    0xFFFF
#endif

#if (G12_9PL >= G12_16PL) || (G12_9PL == 0)
#define  MG12_16_19PL    ~(1 << 8)
#else
#define  MG12_16_19PL    0xFFFF
#endif

#if (G12_10PL >= G12_16PL) || (G12_10PL == 0)
#define  MG12_16_110PL    ~(1 << 9)
#else
#define  MG12_16_110PL    0xFFFF
#endif

#if (G12_11PL >= G12_16PL) || (G12_11PL == 0)
#define  MG12_16_111PL    ~(1 << 10)
#else
#define  MG12_16_111PL    0xFFFF
#endif

#if (G12_12PL >= G12_16PL) || (G12_12PL == 0)
#define  MG12_16_112PL    ~(1 << 11)
#else
#define  MG12_16_112PL    0xFFFF
#endif

#if (G12_13PL >= G12_16PL) || (G12_13PL == 0)
#define  MG12_16_113PL    ~(1 << 12)
#else
#define  MG12_16_113PL    0xFFFF
#endif

#if (G12_14PL >= G12_16PL) || (G12_14PL == 0)
#define  MG12_16_114PL    ~(1 << 13)
#else
#define  MG12_16_114PL    0xFFFF
#endif

#if (G12_15PL >= G12_16PL) || (G12_15PL == 0)
#define  MG12_16_115PL    ~(1 << 14)
#else
#define  MG12_16_115PL    0xFFFF
#endif

#define  MG12_16_116PL	0x7FFF
#define  MG12_16    (MG12_16_11PL & MG12_16_12PL & MG12_16_13PL & MG12_16_14PL & \
                    MG12_16_15PL & MG12_16_16PL & MG12_16_17PL & MG12_16_18PL & \
                    MG12_16_19PL & MG12_16_110PL & MG12_16_111PL & MG12_16_112PL & \
                    MG12_16_113PL & MG12_16_114PL & MG12_16_115PL & MG12_16_116PL)
// End of MG12_16:


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif // eof

//===========================================================================
// End of File.
//===========================================================================
