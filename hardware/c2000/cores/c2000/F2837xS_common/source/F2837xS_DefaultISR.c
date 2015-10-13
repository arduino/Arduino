//###########################################################################
//
// FILE:   F2837xS_DefaultISR.c
//
// TITLE:  F2837xS Device Default Interrupt Service Routines
//
//###########################################################################
// $TI Release: F2837xS Support Library v170 $
// $Release Date: Mon Sep 21 16:56:07 CDT 2015 $
// $Copyright: Copyright (C) 2014-2015 Texas Instruments Incorporated -
//             http://www.ti.com/ ALL RIGHTS RESERVED $
//###########################################################################

#include "F2837xS_device.h"       // F2837xS Header File Include File
#include "F2837xS_Examples.h"     // F2837xS Examples Include File

//---------------------------------------------------------------------------
// CPU Timer 1 Interrupt
interrupt void TIMER1_ISR(void)
{
    // Insert ISR Code here

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// CPU Timer 2 Interrupt
interrupt void TIMER2_ISR(void)
{
    // Insert ISR Code here

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// Datalogging Interrupt
interrupt void DATALOG_ISR(void)
{
    // Insert ISR Code here

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// RTOS Interrupt
interrupt void RTOS_ISR(void)
{
    // Insert ISR Code here

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// Emulation Interrupt
interrupt void EMU_ISR(void)
{
    // Insert ISR Code here

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// Non-Maskable Interrupt
interrupt void NMI_ISR(void)
{
    // Insert ISR Code here

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// Illegal Operation Trap
interrupt void ILLEGAL_ISR(void)
{
    // Insert ISR Code here

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// User Defined Trap 1
interrupt void USER1_ISR(void)
{
    // Insert ISR Code here

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// User Defined Trap 2
interrupt void USER2_ISR(void)
{
    // Insert ISR Code here

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// User Defined Trap 3
interrupt void USER3_ISR(void)
{
    // Insert ISR Code here

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// User Defined Trap 4
interrupt void USER4_ISR(void)
{
    // Insert ISR Code here

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// User Defined Trap 5
interrupt void USER5_ISR(void)
{
    // Insert ISR Code here

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// User Defined Trap 6
interrupt void USER6_ISR(void)
{
    // Insert ISR Code here

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// User Defined Trap 7
interrupt void USER7_ISR(void)
{
    // Insert ISR Code here

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// User Defined Trap 8
interrupt void USER8_ISR(void)
{
    // Insert ISR Code here

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// User Defined Trap 9
interrupt void USER9_ISR(void)
{
    // Insert ISR Code here

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// User Defined Trap 10
interrupt void USER10_ISR(void)
{
    // Insert ISR Code here

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// User Defined Trap 11
interrupt void USER11_ISR(void)
{
    // Insert ISR Code here

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// User Defined Trap 12
interrupt void USER12_ISR(void)
{
    // Insert ISR Code here

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 1.1 - ADCA Interrupt 1
interrupt void ADCA1_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 1.2 - ADCB Interrupt 1
interrupt void ADCB1_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 1.3 - ADCC Interrupt 1
interrupt void ADCC1_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 1.4 - XINT1 Interrupt
interrupt void XINT1_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 1.5 - XINT2 Interrupt
interrupt void XINT2_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 1.6 - ADCD Interrupt 1
interrupt void ADCD1_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 1.7 - Timer 0 Interrupt
interrupt void TIMER0_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 1.8 - Standby and Halt Wakeup Interrupt
interrupt void WAKE_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 2.1 - ePWM1 Trip Zone Interrupt
interrupt void EPWM1_TZ_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 2.2 - ePWM2 Trip Zone Interrupt
interrupt void EPWM2_TZ_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 2.3 - ePWM3 Trip Zone Interrupt
interrupt void EPWM3_TZ_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 2.4 - ePWM4 Trip Zone Interrupt
interrupt void EPWM4_TZ_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 2.5 - ePWM5 Trip Zone Interrupt
interrupt void EPWM5_TZ_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 2.6 - ePWM6 Trip Zone Interrupt
interrupt void EPWM6_TZ_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 2.7 - ePWM7 Trip Zone Interrupt
interrupt void EPWM7_TZ_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 2.8 - ePWM8 Trip Zone Interrupt
interrupt void EPWM8_TZ_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 3.1 - ePWM1 Interrupt
interrupt void EPWM1_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 3.2 - ePWM2 Interrupt
interrupt void EPWM2_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 3.3 - ePWM3 Interrupt
interrupt void EPWM3_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 3.4 - ePWM4 Interrupt
interrupt void EPWM4_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 3.5 - ePWM5 Interrupt
interrupt void EPWM5_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 3.6 - ePWM6 Interrupt
interrupt void EPWM6_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 3.7 - ePWM7 Interrupt
interrupt void EPWM7_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 3.8 - ePWM8 Interrupt
interrupt void EPWM8_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 4.1 - eCAP1 Interrupt
interrupt void ECAP1_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP4;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 4.2 - eCAP2 Interrupt
interrupt void ECAP2_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP4;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 4.3 - eCAP3 Interrupt
interrupt void ECAP3_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP4;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 4.4 - eCAP4 Interrupt
interrupt void ECAP4_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP4;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 4.5 - eCAP5 Interrupt
interrupt void ECAP5_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP4;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 4.6 - eCAP6 Interrupt
interrupt void ECAP6_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP4;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 5.1 - eQEP1 Interrupt
interrupt void EQEP1_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP5;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 5.2 - eQEP2 Interrupt
interrupt void EQEP2_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP5;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 5.3 - eQEP3 Interrupt
interrupt void EQEP3_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP5;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 6.1 - SPIA Receive Interrupt
interrupt void SPIA_RX_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP6;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 6.2 - SPIA Transmit Interrupt
interrupt void SPIA_TX_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP6;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 6.3 - SPIB Receive Interrupt
interrupt void SPIB_RX_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP6;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 6.4 - SPIB Transmit Interrupt
interrupt void SPIB_TX_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP6;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 6.5 - McBSPA Receive Interrupt
interrupt void MCBSPA_RX_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP6;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 6.6 - McBSPA Transmit Interrupt
interrupt void MCBSPA_TX_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP6;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 6.7 - McBSPB Receive Interrupt
interrupt void MCBSPB_RX_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP6;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 6.8 - McBSPB Transmit Interrupt
interrupt void MCBSPB_TX_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP6;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 7.1 - DMA Channel 1 Interrupt
interrupt void DMA_CH1_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP7;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 7.2 - DMA Channel 2 Interrupt
interrupt void DMA_CH2_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP7;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 7.3 - DMA Channel 3 Interrupt
interrupt void DMA_CH3_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP7;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 7.4 - DMA Channel 4 Interrupt
interrupt void DMA_CH4_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP7;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 7.5 - DMA Channel 5 Interrupt
interrupt void DMA_CH5_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP7;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 7.6 - DMA Channel 6 Interrupt
interrupt void DMA_CH6_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP7;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 8.1 - I2CA Interrupt 1
interrupt void I2CA_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP8;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 8.2 - I2CA Interrupt 2
interrupt void I2CA_FIFO_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP8;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 8.3 - I2CB Interrupt 1
interrupt void I2CB_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP8;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 8.4 - I2CB Interrupt 2
interrupt void I2CB_FIFO_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP8;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 8.5 - SCIC Receive Interrupt
interrupt void SCIC_RX_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP8;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 8.6 - SCIC Transmit Interrupt
interrupt void SCIC_TX_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP8;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 8.7 - SCID Receive Interrupt
interrupt void SCID_RX_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP8;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 8.8 - SCID Transmit Interrupt
interrupt void SCID_TX_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP8;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 9.1 - SCIA Receive Interrupt
interrupt void SCIA_RX_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 9.2 - SCIA Transmit Interrupt
interrupt void SCIA_TX_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 9.3 - SCIB Receive Interrupt
interrupt void SCIB_RX_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 9.4 - SCIB Transmit Interrupt
interrupt void SCIB_TX_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 9.5 - CANA Interrupt 0
interrupt void CANA0_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 9.6 - CANA Interrupt 1
interrupt void CANA1_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 9.7 - CANB Interrupt 0
interrupt void CANB0_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 9.8 - CANB Interrupt 1
interrupt void CANB1_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 10.1 - ADCA Event Interrupt
interrupt void ADCA_EVT_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP10;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 10.2 - ADCA Interrupt 2
interrupt void ADCA2_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP10;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 10.3 - ADCA Interrupt 3
interrupt void ADCA3_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP10;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 10.4 - ADCA Interrupt 4
interrupt void ADCA4_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP10;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 10.5 - ADCB Event Interrupt
interrupt void ADCB_EVT_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP10;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 10.6 - ADCB Interrupt 2
interrupt void ADCB2_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP10;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 10.7 - ADCB Interrupt 3
interrupt void ADCB3_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP10;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 10.8 - ADCB Interrupt 4
interrupt void ADCB4_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP10;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 11.1 - CLA1 Interrupt 1
interrupt void CLA1_1_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP11;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 11.2 - CLA1 Interrupt 2
interrupt void CLA1_2_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP11;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 11.3 - CLA1 Interrupt 3
interrupt void CLA1_3_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP11;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 11.4 - CLA1 Interrupt 4
interrupt void CLA1_4_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP11;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 11.5 - CLA1 Interrupt 5
interrupt void CLA1_5_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP11;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 11.6 - CLA1 Interrupt 6
interrupt void CLA1_6_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP11;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 11.7 - CLA1 Interrupt 7
interrupt void CLA1_7_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP11;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 11.8 - CLA1 Interrupt 8
interrupt void CLA1_8_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP11;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 12.1 - XINT3 Interrupt
interrupt void XINT3_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP12;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 12.2 - XINT4 Interrupt
interrupt void XINT4_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP12;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 12.3 - XINT5 Interrupt
interrupt void XINT5_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP12;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 12.6 - VCU Interrupt
interrupt void VCU_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP12;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 12.7 - FPU Overflow Interrupt
interrupt void FPU_OVERFLOW_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP12;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 12.8 - FPU Underflow Interrupt
interrupt void FPU_UNDERFLOW_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP12;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 1.13 - IPC Interrupt 0
interrupt void IPC0_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 1.14 - IPC Interrupt 1
interrupt void IPC1_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 1.15 - IPC Interrupt 2
interrupt void IPC2_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 1.16 - IPC Interrupt 3
interrupt void IPC3_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 2.9 - ePWM9 Trip Zone Interrupt
interrupt void EPWM9_TZ_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 2.10 - ePWM10 Trip Zone Interrupt
interrupt void EPWM10_TZ_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 2.11 - ePWM11 Trip Zone Interrupt
interrupt void EPWM11_TZ_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 2.12 - ePWM12 Trip Zone Interrupt
interrupt void EPWM12_TZ_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 3.9 - ePWM9 Interrupt
interrupt void EPWM9_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 3.10 - ePWM10 Interrupt
interrupt void EPWM10_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 3.11 - ePWM11 Interrupt
interrupt void EPWM11_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 3.12 - ePWM12 Interrupt
interrupt void EPWM12_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 5.9 - SD1 Interrupt
interrupt void SD1_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP5;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 5.10 - SD2 Interrupt
interrupt void SD2_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP5;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 6.9 - SPIC Receive Interrupt
interrupt void SPIC_RX_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP6;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 6.10 - SPIC Transmit Interrupt
interrupt void SPIC_TX_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP6;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 8.15 - uPPA Interrupt
interrupt void UPPA_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP8;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 9.15 - USBA Interrupt
interrupt void USBA_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 10.9 - ADCC Event Interrupt
interrupt void ADCC_EVT_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP10;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 10.10 - ADCC Interrupt 2
interrupt void ADCC2_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP10;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 10.11 - ADCC Interrupt 3
interrupt void ADCC3_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP10;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 10.12 - ADCC Interrupt 4
interrupt void ADCC4_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP10;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 10.13 - ADCD Event Interrupt
interrupt void ADCD_EVT_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP10;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 10.14 - ADCD Interrupt 2
interrupt void ADCD2_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP10;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 10.15 - ADCD Interrupt 3
interrupt void ADCD3_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP10;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 10.16 - ADCD Interrupt 4
interrupt void ADCD4_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP10;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 12.9 - EMIF Error Interrupt
interrupt void EMIF_ERROR_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP12;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 12.10 - RAM Correctable Error Interrupt
interrupt void RAM_CORRECTABLE_ERROR_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP12;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 12.11 - Flash Correctable Error Interrupt
interrupt void FLASH_CORRECTABLE_ERROR_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP12;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 12.12 - RAM Access Violation Interrupt
interrupt void RAM_ACCESS_VIOLATION_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP12;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 12.13 - System PLL Slip Interrupt
interrupt void SYS_PLL_SLIP_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP12;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 12.14 - Auxiliary PLL Slip Interrupt
interrupt void AUX_PLL_SLIP_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP12;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 12.15 - CLA Overflow Interrupt
interrupt void CLA_OVERFLOW_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP12;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// 12.16 - CLA Underflow Interrupt
interrupt void CLA_UNDERFLOW_ISR(void)
{
    // Insert ISR Code here

    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP12;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

//---------------------------------------------------------------------------
// Catch-all Default ISRs:

// Reserved ISR
interrupt void PIE_RESERVED_ISR(void)
{
    asm ("      ESTOP0");
    for(;;);
}

// Only does a return
interrupt void EMPTY_ISR(void)
{

}

// Unused ISR
interrupt void NOTUSED_ISR(void)
{
    asm ("      ESTOP0");
    for(;;);
}

