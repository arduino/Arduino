//###########################################################################
//
// FILE:   F2837xS_pievect.h
//
// TITLE:  F2837xS Device PIE Vector Table Definitions
//
//###########################################################################
// $TI Release: F2837xS Support Library v170 $
// $Release Date: Mon Sep 21 16:56:07 CDT 2015 $
// $Copyright: Copyright (C) 2014-2015 Texas Instruments Incorporated -
//             http://www.ti.com/ ALL RIGHTS RESERVED $
//###########################################################################

#ifndef F2837xS_PIE_VECT_H
#define F2837xS_PIE_VECT_H
#ifdef __cplusplus
extern "C" {
#endif

//---------------------------------------------------------------------------
// PIE Interrupt Vector Table Definition:
// Create a user type called PINT (pointer to interrupt):

typedef __interrupt void (*PINT)(void);

// Define Vector Table:
struct PIE_VECT_TABLE {
    PINT  PIE1_RESERVED_INT;                          // Reserved 
    PINT  PIE2_RESERVED_INT;                          // Reserved 
    PINT  PIE3_RESERVED_INT;                          // Reserved 
    PINT  PIE4_RESERVED_INT;                          // Reserved 
    PINT  PIE5_RESERVED_INT;                          // Reserved 
    PINT  PIE6_RESERVED_INT;                          // Reserved 
    PINT  PIE7_RESERVED_INT;                          // Reserved 
    PINT  PIE8_RESERVED_INT;                          // Reserved 
    PINT  PIE9_RESERVED_INT;                          // Reserved 
    PINT  PIE10_RESERVED_INT;                         // Reserved 
    PINT  PIE11_RESERVED_INT;                         // Reserved 
    PINT  PIE12_RESERVED_INT;                         // Reserved 
    PINT  PIE13_RESERVED_INT;                         // Reserved 
    PINT  TIMER1_INT;                                 // CPU Timer 1 Interrupt 
    PINT  TIMER2_INT;                                 // CPU Timer 2 Interrupt 
    PINT  DATALOG_INT;                                // Datalogging Interrupt 
    PINT  RTOS_INT;                                   // RTOS Interrupt 
    PINT  EMU_INT;                                    // Emulation Interrupt 
    PINT  NMI_INT;                                    // Non-Maskable Interrupt 
    PINT  ILLEGAL_INT;                                // Illegal Operation Trap 
    PINT  USER1_INT;                                  // User Defined Trap 1 
    PINT  USER2_INT;                                  // User Defined Trap 2 
    PINT  USER3_INT;                                  // User Defined Trap 3 
    PINT  USER4_INT;                                  // User Defined Trap 4 
    PINT  USER5_INT;                                  // User Defined Trap 5 
    PINT  USER6_INT;                                  // User Defined Trap 6 
    PINT  USER7_INT;                                  // User Defined Trap 7 
    PINT  USER8_INT;                                  // User Defined Trap 8 
    PINT  USER9_INT;                                  // User Defined Trap 9 
    PINT  USER10_INT;                                 // User Defined Trap 10 
    PINT  USER11_INT;                                 // User Defined Trap 11 
    PINT  USER12_INT;                                 // User Defined Trap 12 
    PINT  ADCA1_INT;                                  // 1.1 - ADCA Interrupt 1 
    PINT  ADCB1_INT;                                  // 1.2 - ADCB Interrupt 1 
    PINT  ADCC1_INT;                                  // 1.3 - ADCC Interrupt 1 
    PINT  XINT1_INT;                                  // 1.4 - XINT1 Interrupt 
    PINT  XINT2_INT;                                  // 1.5 - XINT2 Interrupt 
    PINT  ADCD1_INT;                                  // 1.6 - ADCD Interrupt 1 
    PINT  TIMER0_INT;                                 // 1.7 - Timer 0 Interrupt 
    PINT  WAKE_INT;                                   // 1.8 - Standby and Halt Wakeup Interrupt 
    PINT  EPWM1_TZ_INT;                               // 2.1 - ePWM1 Trip Zone Interrupt 
    PINT  EPWM2_TZ_INT;                               // 2.2 - ePWM2 Trip Zone Interrupt 
    PINT  EPWM3_TZ_INT;                               // 2.3 - ePWM3 Trip Zone Interrupt 
    PINT  EPWM4_TZ_INT;                               // 2.4 - ePWM4 Trip Zone Interrupt 
    PINT  EPWM5_TZ_INT;                               // 2.5 - ePWM5 Trip Zone Interrupt 
    PINT  EPWM6_TZ_INT;                               // 2.6 - ePWM6 Trip Zone Interrupt 
    PINT  EPWM7_TZ_INT;                               // 2.7 - ePWM7 Trip Zone Interrupt 
    PINT  EPWM8_TZ_INT;                               // 2.8 - ePWM8 Trip Zone Interrupt 
    PINT  EPWM1_INT;                                  // 3.1 - ePWM1 Interrupt 
    PINT  EPWM2_INT;                                  // 3.2 - ePWM2 Interrupt 
    PINT  EPWM3_INT;                                  // 3.3 - ePWM3 Interrupt 
    PINT  EPWM4_INT;                                  // 3.4 - ePWM4 Interrupt 
    PINT  EPWM5_INT;                                  // 3.5 - ePWM5 Interrupt 
    PINT  EPWM6_INT;                                  // 3.6 - ePWM6 Interrupt 
    PINT  EPWM7_INT;                                  // 3.7 - ePWM7 Interrupt 
    PINT  EPWM8_INT;                                  // 3.8 - ePWM8 Interrupt 
    PINT  ECAP1_INT;                                  // 4.1 - eCAP1 Interrupt 
    PINT  ECAP2_INT;                                  // 4.2 - eCAP2 Interrupt 
    PINT  ECAP3_INT;                                  // 4.3 - eCAP3 Interrupt 
    PINT  ECAP4_INT;                                  // 4.4 - eCAP4 Interrupt 
    PINT  ECAP5_INT;                                  // 4.5 - eCAP5 Interrupt 
    PINT  ECAP6_INT;                                  // 4.6 - eCAP6 Interrupt 
    PINT  PIE14_RESERVED_INT;                         // 4.7 - Reserved 
    PINT  PIE15_RESERVED_INT;                         // 4.8 - Reserved 
    PINT  EQEP1_INT;                                  // 5.1 - eQEP1 Interrupt 
    PINT  EQEP2_INT;                                  // 5.2 - eQEP2 Interrupt 
    PINT  EQEP3_INT;                                  // 5.3 - eQEP3 Interrupt 
    PINT  PIE16_RESERVED_INT;                         // 5.4 - Reserved 
    PINT  PIE17_RESERVED_INT;                         // 5.5 - Reserved 
    PINT  PIE18_RESERVED_INT;                         // 5.6 - Reserved 
    PINT  PIE19_RESERVED_INT;                         // 5.7 - Reserved 
    PINT  PIE20_RESERVED_INT;                         // 5.8 - Reserved 
    PINT  SPIA_RX_INT;                                // 6.1 - SPIA Receive Interrupt 
    PINT  SPIA_TX_INT;                                // 6.2 - SPIA Transmit Interrupt 
    PINT  SPIB_RX_INT;                                // 6.3 - SPIB Receive Interrupt 
    PINT  SPIB_TX_INT;                                // 6.4 - SPIB Transmit Interrupt 
    PINT  MCBSPA_RX_INT;                              // 6.5 - McBSPA Receive Interrupt 
    PINT  MCBSPA_TX_INT;                              // 6.6 - McBSPA Transmit Interrupt 
    PINT  MCBSPB_RX_INT;                              // 6.7 - McBSPB Receive Interrupt 
    PINT  MCBSPB_TX_INT;                              // 6.8 - McBSPB Transmit Interrupt 
    PINT  DMA_CH1_INT;                                // 7.1 - DMA Channel 1 Interrupt 
    PINT  DMA_CH2_INT;                                // 7.2 - DMA Channel 2 Interrupt 
    PINT  DMA_CH3_INT;                                // 7.3 - DMA Channel 3 Interrupt 
    PINT  DMA_CH4_INT;                                // 7.4 - DMA Channel 4 Interrupt 
    PINT  DMA_CH5_INT;                                // 7.5 - DMA Channel 5 Interrupt 
    PINT  DMA_CH6_INT;                                // 7.6 - DMA Channel 6 Interrupt 
    PINT  PIE21_RESERVED_INT;                         // 7.7 - Reserved 
    PINT  PIE22_RESERVED_INT;                         // 7.8 - Reserved 
    PINT  I2CA_INT;                                   // 8.1 - I2CA Interrupt 1 
    PINT  I2CA_FIFO_INT;                              // 8.2 - I2CA Interrupt 2 
    PINT  I2CB_INT;                                   // 8.3 - I2CB Interrupt 1 
    PINT  I2CB_FIFO_INT;                              // 8.4 - I2CB Interrupt 2 
    PINT  SCIC_RX_INT;                                // 8.5 - SCIC Receive Interrupt 
    PINT  SCIC_TX_INT;                                // 8.6 - SCIC Transmit Interrupt 
    PINT  SCID_RX_INT;                                // 8.7 - SCID Receive Interrupt 
    PINT  SCID_TX_INT;                                // 8.8 - SCID Transmit Interrupt 
    PINT  SCIA_RX_INT;                                // 9.1 - SCIA Receive Interrupt 
    PINT  SCIA_TX_INT;                                // 9.2 - SCIA Transmit Interrupt 
    PINT  SCIB_RX_INT;                                // 9.3 - SCIB Receive Interrupt 
    PINT  SCIB_TX_INT;                                // 9.4 - SCIB Transmit Interrupt 
    PINT  CANA0_INT;                                  // 9.5 - CANA Interrupt 0 
    PINT  CANA1_INT;                                  // 9.6 - CANA Interrupt 1 
    PINT  CANB0_INT;                                  // 9.7 - CANB Interrupt 0 
    PINT  CANB1_INT;                                  // 9.8 - CANB Interrupt 1 
    PINT  ADCA_EVT_INT;                               // 10.1 - ADCA Event Interrupt 
    PINT  ADCA2_INT;                                  // 10.2 - ADCA Interrupt 2 
    PINT  ADCA3_INT;                                  // 10.3 - ADCA Interrupt 3 
    PINT  ADCA4_INT;                                  // 10.4 - ADCA Interrupt 4 
    PINT  ADCB_EVT_INT;                               // 10.5 - ADCB Event Interrupt 
    PINT  ADCB2_INT;                                  // 10.6 - ADCB Interrupt 2 
    PINT  ADCB3_INT;                                  // 10.7 - ADCB Interrupt 3 
    PINT  ADCB4_INT;                                  // 10.8 - ADCB Interrupt 4 
    PINT  CLA1_1_INT;                                 // 11.1 - CLA1 Interrupt 1 
    PINT  CLA1_2_INT;                                 // 11.2 - CLA1 Interrupt 2 
    PINT  CLA1_3_INT;                                 // 11.3 - CLA1 Interrupt 3 
    PINT  CLA1_4_INT;                                 // 11.4 - CLA1 Interrupt 4 
    PINT  CLA1_5_INT;                                 // 11.5 - CLA1 Interrupt 5 
    PINT  CLA1_6_INT;                                 // 11.6 - CLA1 Interrupt 6 
    PINT  CLA1_7_INT;                                 // 11.7 - CLA1 Interrupt 7 
    PINT  CLA1_8_INT;                                 // 11.8 - CLA1 Interrupt 8 
    PINT  XINT3_INT;                                  // 12.1 - XINT3 Interrupt 
    PINT  XINT4_INT;                                  // 12.2 - XINT4 Interrupt 
    PINT  XINT5_INT;                                  // 12.3 - XINT5 Interrupt 
    PINT  PIE23_RESERVED_INT;                         // 12.4 - Reserved 
    PINT  PIE24_RESERVED_INT;                         // 12.5 - Reserved 
    PINT  VCU_INT;                                    // 12.6 - VCU Interrupt 
    PINT  FPU_OVERFLOW_INT;                           // 12.7 - FPU Overflow Interrupt 
    PINT  FPU_UNDERFLOW_INT;                          // 12.8 - FPU Underflow Interrupt 
    PINT  PIE25_RESERVED_INT;                         // 1.9 - Reserved 
    PINT  PIE26_RESERVED_INT;                         // 1.10 - Reserved 
    PINT  PIE27_RESERVED_INT;                         // 1.11 - Reserved 
    PINT  PIE28_RESERVED_INT;                         // 1.12 - Reserved 
    PINT  IPC0_INT;                                   // 1.13 - IPC Interrupt 0 
    PINT  IPC1_INT;                                   // 1.14 - IPC Interrupt 1 
    PINT  IPC2_INT;                                   // 1.15 - IPC Interrupt 2 
    PINT  IPC3_INT;                                   // 1.16 - IPC Interrupt 3 
    PINT  EPWM9_TZ_INT;                               // 2.9 - ePWM9 Trip Zone Interrupt 
    PINT  EPWM10_TZ_INT;                              // 2.10 - ePWM10 Trip Zone Interrupt 
    PINT  EPWM11_TZ_INT;                              // 2.11 - ePWM11 Trip Zone Interrupt 
    PINT  EPWM12_TZ_INT;                              // 2.12 - ePWM12 Trip Zone Interrupt 
    PINT  PIE29_RESERVED_INT;                         // 2.13 - Reserved 
    PINT  PIE30_RESERVED_INT;                         // 2.14 - Reserved 
    PINT  PIE31_RESERVED_INT;                         // 2.15 - Reserved 
    PINT  PIE32_RESERVED_INT;                         // 2.16 - Reserved 
    PINT  EPWM9_INT;                                  // 3.9 - ePWM9 Interrupt 
    PINT  EPWM10_INT;                                 // 3.10 - ePWM10 Interrupt 
    PINT  EPWM11_INT;                                 // 3.11 - ePWM11 Interrupt 
    PINT  EPWM12_INT;                                 // 3.12 - ePWM12 Interrupt 
    PINT  PIE33_RESERVED_INT;                         // 3.13 - Reserved 
    PINT  PIE34_RESERVED_INT;                         // 3.14 - Reserved 
    PINT  PIE35_RESERVED_INT;                         // 3.15 - Reserved 
    PINT  PIE36_RESERVED_INT;                         // 3.16 - Reserved 
    PINT  PIE37_RESERVED_INT;                         // 4.9 - Reserved 
    PINT  PIE38_RESERVED_INT;                         // 4.10 - Reserved 
    PINT  PIE39_RESERVED_INT;                         // 4.11 - Reserved 
    PINT  PIE40_RESERVED_INT;                         // 4.12 - Reserved 
    PINT  PIE41_RESERVED_INT;                         // 4.13 - Reserved 
    PINT  PIE42_RESERVED_INT;                         // 4.14 - Reserved 
    PINT  PIE43_RESERVED_INT;                         // 4.15 - Reserved 
    PINT  PIE44_RESERVED_INT;                         // 4.16 - Reserved 
    PINT  SD1_INT;                                    // 5.9 - SD1 Interrupt 
    PINT  SD2_INT;                                    // 5.10 - SD2 Interrupt 
    PINT  PIE45_RESERVED_INT;                         // 5.11 - Reserved 
    PINT  PIE46_RESERVED_INT;                         // 5.12 - Reserved 
    PINT  PIE47_RESERVED_INT;                         // 5.13 - Reserved 
    PINT  PIE48_RESERVED_INT;                         // 5.14 - Reserved 
    PINT  PIE49_RESERVED_INT;                         // 5.15 - Reserved 
    PINT  PIE50_RESERVED_INT;                         // 5.16 - Reserved 
    PINT  SPIC_RX_INT;                                // 6.9 - SPIC Receive Interrupt 
    PINT  SPIC_TX_INT;                                // 6.10 - SPIC Transmit Interrupt 
    PINT  PIE51_RESERVED_INT;                         // 6.11 - Reserved 
    PINT  PIE52_RESERVED_INT;                         // 6.12 - Reserved 
    PINT  PIE53_RESERVED_INT;                         // 6.13 - Reserved 
    PINT  PIE54_RESERVED_INT;                         // 6.14 - Reserved 
    PINT  PIE55_RESERVED_INT;                         // 6.15 - Reserved 
    PINT  PIE56_RESERVED_INT;                         // 6.16 - Reserved 
    PINT  PIE57_RESERVED_INT;                         // 7.9 - Reserved 
    PINT  PIE58_RESERVED_INT;                         // 7.10 - Reserved 
    PINT  PIE59_RESERVED_INT;                         // 7.11 - Reserved 
    PINT  PIE60_RESERVED_INT;                         // 7.12 - Reserved 
    PINT  PIE61_RESERVED_INT;                         // 7.13 - Reserved 
    PINT  PIE62_RESERVED_INT;                         // 7.14 - Reserved 
    PINT  PIE63_RESERVED_INT;                         // 7.15 - Reserved 
    PINT  PIE64_RESERVED_INT;                         // 7.16 - Reserved 
    PINT  PIE65_RESERVED_INT;                         // 8.9 - Reserved 
    PINT  PIE66_RESERVED_INT;                         // 8.10 - Reserved 
    PINT  PIE67_RESERVED_INT;                         // 8.11 - Reserved 
    PINT  PIE68_RESERVED_INT;                         // 8.12 - Reserved 
    PINT  PIE69_RESERVED_INT;                         // 8.13 - Reserved 
    PINT  PIE70_RESERVED_INT;                         // 8.14 - Reserved 
    PINT  UPPA_INT;                                   // 8.15 - uPPA Interrupt 
    PINT  PIE71_RESERVED_INT;                         // 8.16 - Reserved 
    PINT  PIE72_RESERVED_INT;                         // 9.9 - Reserved 
    PINT  PIE73_RESERVED_INT;                         // 9.10 - Reserved 
    PINT  PIE74_RESERVED_INT;                         // 9.11 - Reserved 
    PINT  PIE75_RESERVED_INT;                         // 9.12 - Reserved 
    PINT  PIE76_RESERVED_INT;                         // 9.13 - Reserved 
    PINT  PIE77_RESERVED_INT;                         // 9.14 - Reserved 
    PINT  USBA_INT;                                   // 9.15 - USBA Interrupt 
    PINT  PIE78_RESERVED_INT;                         // 9.16 - Reserved 
    PINT  ADCC_EVT_INT;                               // 10.9 - ADCC Event Interrupt 
    PINT  ADCC2_INT;                                  // 10.10 - ADCC Interrupt 2 
    PINT  ADCC3_INT;                                  // 10.11 - ADCC Interrupt 3 
    PINT  ADCC4_INT;                                  // 10.12 - ADCC Interrupt 4 
    PINT  ADCD_EVT_INT;                               // 10.13 - ADCD Event Interrupt 
    PINT  ADCD2_INT;                                  // 10.14 - ADCD Interrupt 2 
    PINT  ADCD3_INT;                                  // 10.15 - ADCD Interrupt 3 
    PINT  ADCD4_INT;                                  // 10.16 - ADCD Interrupt 4 
    PINT  PIE79_RESERVED_INT;                         // 11.9 - Reserved 
    PINT  PIE80_RESERVED_INT;                         // 11.10 - Reserved 
    PINT  PIE81_RESERVED_INT;                         // 11.11 - Reserved 
    PINT  PIE82_RESERVED_INT;                         // 11.12 - Reserved 
    PINT  PIE83_RESERVED_INT;                         // 11.13 - Reserved 
    PINT  PIE84_RESERVED_INT;                         // 11.14 - Reserved 
    PINT  PIE85_RESERVED_INT;                         // 11.15 - Reserved 
    PINT  PIE86_RESERVED_INT;                         // 11.16 - Reserved 
    PINT  EMIF_ERROR_INT;                             // 12.9 - EMIF Error Interrupt 
    PINT  RAM_CORRECTABLE_ERROR_INT;                  // 12.10 - RAM Correctable Error Interrupt 
    PINT  FLASH_CORRECTABLE_ERROR_INT;                // 12.11 - Flash Correctable Error Interrupt 
    PINT  RAM_ACCESS_VIOLATION_INT;                   // 12.12 - RAM Access Violation Interrupt 
    PINT  SYS_PLL_SLIP_INT;                           // 12.13 - System PLL Slip Interrupt 
    PINT  AUX_PLL_SLIP_INT;                           // 12.14 - Auxiliary PLL Slip Interrupt 
    PINT  CLA_OVERFLOW_INT;                           // 12.15 - CLA Overflow Interrupt 
    PINT  CLA_UNDERFLOW_INT;                          // 12.16 - CLA Underflow Interrupt 
};

//---------------------------------------------------------------------------
// PieVect External References & Function Declarations:
//

extern volatile struct PIE_VECT_TABLE PieVectTable;

#ifdef __cplusplus
}
#endif                                                /* extern "C" */


#endif                                                // end of F2837xS_PIEVECT_H definition
//===========================================================================
// End of file.
//===========================================================================
