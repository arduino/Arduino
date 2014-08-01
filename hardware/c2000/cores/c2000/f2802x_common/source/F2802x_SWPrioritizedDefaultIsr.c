// TI File $Revision: /main/3 $
// Checkin $Date: July 6, 2009   16:52:04 $
//###########################################################################
//
// FILE:    DSP2802x_SWPrioritizedDefaultIsr.c
//
// TITLE:   DSP2802x Device Default Software Prioritized Interrupt Service Routines.
//
//###########################################################################
//
// $TI Release: 2802x C/C++ Header Files and Peripheral Examples V1.29 $
// $Release Date: January 11, 2011 $
//###########################################################################

#include "F2802x_Device.h"     // Headerfile Include File
#include "f2802x_common/include/f2802x_examples.h"   // Examples Include File
#include "f2802x_common/include/F2802x_SWPrioritizedIsrLevels.h"

// Connected to INT13 of CPU (use MINT13 mask):
#if (INT13PL != 0)
interrupt void INT13_ISR(void)      // INT13 or CPU-Timer1
{
     IER |= MINT13;                 // Set "global" priority
     EINT;

  // Insert ISR Code here

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
     asm ("      ESTOP0");
     for(;;);
}
#endif

// Connected to INT14 of CPU (use MINT14 mask):
#if (INT14PL != 0)
interrupt void INT14_ISR(void)     // INT14 or CPU-Timer2
{
   IER |= MINT14;                  // Set "global" priority
   EINT;

   // Insert ISR Code here.......

   // Next two lines for debug only to halt the processor here
   // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);
}
#endif

// Connected to INT15 of CPU (use MINT15 mask):
#if (INT15PL != 0)
interrupt void DATALOG_ISR(void)   // Datalogging interrupt
{
    IER |= MINT15;                 // Set "global" priority
    EINT;

      // Insert ISR Code here.......

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}
#endif

// Connected to INT16 of CPU (use MINT16 mask):
#if (INT16PL != 0)
interrupt void RTOSINT_ISR(void)   // RTOS interrupt
{
    IER |= MINT16;                 // Set "global" priority
    EINT;

      // Insert ISR Code here.......

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}
#endif

// Connected to EMUINT of CPU (non-maskable):
interrupt void EMUINT_ISR(void)    // Emulation interrupt
{
    EINT;

      // Insert ISR Code here.......

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// Connected to NMI of CPU (non-maskable):
interrupt void NMI_ISR(void)      // Non-maskable interrupt
{
    EINT;

      // Insert ISR Code here.......

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

interrupt void ILLEGAL_ISR(void)   // Illegal operation TRAP
{
    EINT;

      // Insert ISR Code here.......

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

interrupt void USER1_ISR(void)     // User Defined trap 1
{
    EINT;

      // Insert ISR Code here.......

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

interrupt void USER2_ISR(void)     // User Defined trap 2
{
    EINT;

      // Insert ISR Code here.......

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

interrupt void USER3_ISR(void)     // User Defined trap 3
{
    EINT;

      // Insert ISR Code here.......

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

interrupt void USER4_ISR(void)     // User Defined trap 4
{
    EINT;

      // Insert ISR Code here.......

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

interrupt void USER5_ISR(void)     // User Defined trap 5
{
    EINT;

      // Insert ISR Code here.......

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

interrupt void USER6_ISR(void)     // User Defined trap 6
{
    EINT;

      // Insert ISR Code here.......

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

interrupt void USER7_ISR(void)     // User Defined trap 7
{
    EINT;

      // Insert ISR Code here.......

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

interrupt void USER8_ISR(void)     // User Defined trap 8
{
    EINT;

      // Insert ISR Code here.......

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

interrupt void USER9_ISR(void)     // User Defined trap 9
{
    EINT;

      // Insert ISR Code here.......

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

interrupt void USER10_ISR(void)    // User Defined trap 10
{
    EINT;

      // Insert ISR Code here.......

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

interrupt void USER11_ISR(void)    // User Defined trap 11
{
    EINT;

      // Insert ISR Code here.......

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

interrupt void USER12_ISR(void)     // User Defined trap 12
{
    EINT;

      // Insert ISR Code here.......

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}

// -----------------------------------------------------------
// PIE Group 1 - MUXed into CPU INT1
// -----------------------------------------------------------

// Connected to PIEIER1_1 (use MINT1 and MG11 masks):
#if (G11PL != 0)
interrupt void ADCINT1_ISR( void )     // ADC
{
    // Set interrupt priority:
    volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER1.all;
    IER |= M_INT1;
    IER    &= MINT1;                         // Set "global" priority
    PieCtrlRegs.PIEIER1.all &= MG11;   // Set "group"  priority
    PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
    EINT;

      // Insert ISR Code here.......

    // Restore registers saved:
    DINT;
    PieCtrlRegs.PIEIER1.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);

}
#endif

// Connected to PIEIER1_2 (use MINT1 and MG12 masks):
#if (G12PL != 0)
interrupt void ADCINT2_ISR( void )    // ADC
{
    // Set interrupt priority:
    volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER1.all;
    IER |= M_INT1;
    IER    &= MINT1;                         // Set "global" priority
    PieCtrlRegs.PIEIER1.all &= MG12;   // Set "group"  priority
    PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
    EINT;

      // Insert ISR Code here.......

    // Restore registers saved:
    DINT;
    PieCtrlRegs.PIEIER1.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);

}
#endif


// Connected to PIEIER1_4 (use MINT1 and MG14 masks):
#if (G14PL != 0)
interrupt void  XINT1_ISR(void)
{
    // Set interrupt priority:
    volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER1.all;
    IER |= MINT1;                      // Set "global" priority
    PieCtrlRegs.PIEIER1.all &= MG14;   // Set "group"  priority
    PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
    EINT;

    // Restore registers saved:
    DINT;
    PieCtrlRegs.PIEIER1.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}
#endif

// Connected to PIEIER1_5 (use MINT1 and MG15 masks):
#if (G15PL != 0)
interrupt void  XINT2_ISR(void)
{
    // Set interrupt priority:
    volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER1.all;
    IER |= MINT1;                      // Set "global" priority
    PieCtrlRegs.PIEIER1.all &= MG15;   // Set "group"  priority
    PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
    EINT;

      // Insert ISR Code here.......

    // Restore registers saved:
    DINT;
    PieCtrlRegs.PIEIER1.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}
#endif

// Connected to PIEIER1_6 (use MINT1 and MG16 masks):
#if (G16PL != 0)
interrupt void  ADCINT9_ISR(void)     // ADC
{
    // Set interrupt priority:
    volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER1.all;
    IER |= M_INT1;
    IER    &= MINT1;                      // Set "global" priority
    PieCtrlRegs.PIEIER1.all &= MG16;   // Set "group"  priority
    PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
    EINT;

      // Insert ISR Code here.......

    // Restore registers saved:
    DINT;
    PieCtrlRegs.PIEIER1.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);

}
#endif

// Connected to PIEIER1_7 (use MINT1 and MG17 masks):
#if (G17PL != 0)
interrupt void  TINT0_ISR(void)      // CPU-Timer 0
{
    // Set interrupt priority:
    volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER1.all;
    IER |= M_INT1;
    IER    &= MINT1;                         // Set "global" priority
    PieCtrlRegs.PIEIER1.all &= MG17;   // Set "group"  priority
    PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
    EINT;

      // Insert ISR Code here.......

      // Restore registers saved:
    DINT;
    PieCtrlRegs.PIEIER1.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}
#endif

// Connected to PIEIER1_8 (use MINT1 and MG18 masks):
#if (G18PL != 0)
interrupt void  WAKEINT_ISR(void)      // WD/LPM
{
    // Set interrupt priority:
    volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER1.all;
    IER |= M_INT1;
    IER    &= MINT1;                         // Set "global" priority
    PieCtrlRegs.PIEIER1.all &= MG18;   // Set "group"  priority
    PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
    EINT;

      // Insert ISR Code here.......

    // Restore registers saved:
    DINT;
    PieCtrlRegs.PIEIER1.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}
#endif

// -----------------------------------------------------------
// PIE Group 2 - MUXed into CPU INT2
// -----------------------------------------------------------

// Connected to PIEIER2_1 (use MINT2 and MG21 masks):
#if (G21PL != 0)
interrupt void EPWM1_TZINT_ISR(void)    // EPwm1 Trip Zone
{
    // Set interrupt priority:
    volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER2.all;
    IER |= M_INT2;
    IER    &= MINT2;                         // Set "global" priority
    PieCtrlRegs.PIEIER2.all &= MG21;   // Set "group"  priority
    PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
    EINT;

      // Insert ISR Code here.......

    // Restore registers saved:
    DINT;
    PieCtrlRegs.PIEIER2.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}
#endif

// Connected to PIEIER2_2 (use MINT2 and MG22 masks):
#if (G22PL != 0)
interrupt void EPWM2_TZINT_ISR(void)    // EPwm2 Trip Zone
{
    // Set interrupt priority:
    volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER2.all;
    IER |= M_INT2;
    IER    &= MINT2;                         // Set "global" priority
    PieCtrlRegs.PIEIER2.all &= MG22;   // Set "group"  priority
    PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
    EINT;

      // Insert ISR Code here.......

    // Restore registers saved:
    DINT;
    PieCtrlRegs.PIEIER2.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}
#endif

// Connected to PIEIER2_3 (use MINT2 and MG23 masks):
#if (G23PL != 0)
interrupt void EPWM3_TZINT_ISR(void)    // EPwm3 Trip Zone
{
    // Set interrupt priority:
    volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER2.all;
    IER |= M_INT2;
    IER    &= MINT2;                         // Set "global" priority
    PieCtrlRegs.PIEIER2.all &= MG23;   // Set "group"  priority
    PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
    EINT;

      // Insert ISR Code here.......

    // Restore registers saved:
    DINT;
    PieCtrlRegs.PIEIER2.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);

}
#endif

// Connected to PIEIER2_4 (use MINT2 and MG24 masks):
#if (G24PL != 0)
interrupt void EPWM4_TZINT_ISR(void)    // EPwm4 Trip Zone
{
    // Set interrupt priority:
    volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER2.all;
    IER |= M_INT2;
    IER    &= MINT2;                          // Set "global" priority
    PieCtrlRegs.PIEIER2.all &= MG24;    // Set "group"  priority
    PieCtrlRegs.PIEACK.all = 0xFFFF;    // Enable PIE interrupts
    EINT;

      // Insert ISR Code here.......

    // Restore registers saved:
    DINT;
    PieCtrlRegs.PIEIER2.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);

}
#endif

// -----------------------------------------------------------
// PIE Group 3 - MUXed into CPU INT3
// -----------------------------------------------------------

// Connected to PIEIER3_1 (use MINT3 and MG31 masks):
#if (G31PL != 0)
interrupt void EPWM1_INT_ISR(void)     // EPwm1 Interrupt
{
    // Set interrupt priority:
    volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER3.all;
    IER |= M_INT3;
    IER    &= MINT3;                         // Set "global" priority
    PieCtrlRegs.PIEIER3.all &= MG31;   // Set "group"  priority
    PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
    EINT;

      // Insert ISR Code here.......

    // Restore registers saved:
    DINT;
    PieCtrlRegs.PIEIER3.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}
#endif

// Connected to PIEIER3_2 (use MINT3 and MG32 masks):
#if (G32PL != 0)
interrupt void EPWM2_INT_ISR(void)     // EPwm2 Interrupt
{
    // Set interrupt priority:
    volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER3.all;
    IER |= M_INT3;
    IER    &= MINT3;                         // Set "global" priority
    PieCtrlRegs.PIEIER3.all &= MG32;   // Set "group"  priority
    PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
    EINT;

      // Insert ISR Code here.......

    // Restore registers saved:
    DINT;
    PieCtrlRegs.PIEIER3.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);

}
#endif

// Connected to PIEIER3_3 (use MINT3 and MG33 masks):
#if (G33PL != 0)
interrupt void EPWM3_INT_ISR(void)     // EPwm3 Interrupt
{
    // Set interrupt priority:
    volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER3.all;
    IER |= M_INT3;
    IER    &= MINT3;                          // Set "global" priority
    PieCtrlRegs.PIEIER3.all &= MG33;   // Set "group"  priority
    PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
    EINT;

      // Insert ISR Code here.......

    // Restore registers saved:
    DINT;
    PieCtrlRegs.PIEIER3.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);

}
#endif

// Connected to PIEIER3_4 (use MINT3 and MG34 masks):
#if (G34PL != 0)
interrupt void EPWM4_INT_ISR(void)     // EPwm4 Interrupt
{
    // Set interrupt priority:
    volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER3.all;
    IER |= M_INT3;
    IER    &= MINT3;                         // Set "global" priority
    PieCtrlRegs.PIEIER3.all &= MG34;   // Set "group"  priority
    PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
    EINT;

      // Insert ISR Code here.......

    // Restore registers saved:
    DINT;
    PieCtrlRegs.PIEIER3.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);

}
#endif

// -----------------------------------------------------------
// PIE Group 4 - MUXed into CPU INT4
// -----------------------------------------------------------

// Connected to PIEIER4_1 (use MINT4 and MG41 masks):
#if (G41PL != 0)
interrupt void ECAP1_INT_ISR(void)     // eCAP1 Interrupt
{
    // Set interrupt priority:
    volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER4.all;
    IER |= M_INT4;
    IER    &= MINT4;                         // Set "global" priority
    PieCtrlRegs.PIEIER4.all &= MG41;   // Set "group"  priority
    PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
    EINT;

      // Insert ISR Code here.......

    // Restore registers saved:
    DINT;
    PieCtrlRegs.PIEIER4.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);

}
#endif

// -----------------------------------------------------------
// PIE Group 5 - MUXed into CPU INT5
// -----------------------------------------------------------

// -----------------------------------------------------------
// PIE Group 6 - MUXed into CPU INT6
// -----------------------------------------------------------

// Connected to PIEIER6_1 (use MINT6 and MG61 masks):
#if (G61PL != 0)
interrupt void SPIRXINTA_ISR(void)    // SPI-A
{
    // Set interrupt priority:
    volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER6.all;
    IER |= M_INT6;
    IER    &= MINT6;                         // Set "global" priority
    PieCtrlRegs.PIEIER6.all &= MG61;   // Set "group"  priority
    PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
    EINT;

      // Insert ISR Code here.......

    // Restore registers saved:
    DINT;
    PieCtrlRegs.PIEIER6.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);

}
#endif

// Connected to PIEIER6_2 (use MINT6 and MG62 masks):
#if (G62PL != 0)
interrupt void SPITXINTA_ISR(void)     // SPI-A
{
    // Set interrupt priority:
    volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER6.all;
    IER |= M_INT6;
    IER    &= MINT6;                         // Set "global" priority
    PieCtrlRegs.PIEIER6.all &= MG62;   // Set "group"  priority
    PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
    EINT;

      // Insert ISR Code here.......

    // Restore registers saved:
    DINT;
    PieCtrlRegs.PIEIER6.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}
#endif

// -----------------------------------------------------------
// PIE Group 7 - MUXed into CPU INT7
// -----------------------------------------------------------

// -----------------------------------------------------------
// PIE Group 8 - MUXed into CPU INT8
// -----------------------------------------------------------

// Connected to PIEIER8_1 (use MINT8 and MG81 masks):
#if (G81PL != 0)
interrupt void I2CINT1A_ISR(void)    // I2C-A
{
    // Set interrupt priority:
    volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER8.all;
    IER |= M_INT8;
    IER    &= MINT8;                         // Set "global" priority
    PieCtrlRegs.PIEIER6.all &= MG81;   // Set "group"  priority
    PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
    EINT;

      // Insert ISR Code here.......

    // Restore registers saved:
    DINT;
    PieCtrlRegs.PIEIER8.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);

}
#endif

// Connected to PIEIER8_2 (use MINT8 and MG82 masks):
#if (G82PL != 0)
interrupt void I2CINT2A_ISR(void)     // I2C-A
{
    // Set interrupt priority:
    volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER8.all;
    IER |= M_INT8;
    IER    &= MINT8;                         // Set "global" priority
    PieCtrlRegs.PIEIER6.all &= MG82;   // Set "group"  priority
    PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
    EINT;

      // Insert ISR Code here.......

    // Restore registers saved:
    DINT;
    PieCtrlRegs.PIEIER8.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);

}
#endif

// -----------------------------------------------------------
// PIE Group 9 - MUXed into CPU INT9
// -----------------------------------------------------------

// Connected to PIEIER9_1 (use MINT9 and MG91 masks):
#if (G91PL != 0)
interrupt void SCIRXINTA_ISR(void)     // SCI-A
{
    // Set interrupt priority:
    volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER9.all;
    IER |= M_INT9;
    IER    &= MINT9;                          // Set "global" priority
    PieCtrlRegs.PIEIER9.all &= MG91;   // Set "group"  priority
    PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
    EINT;

      // Insert ISR Code here.......

    // Restore registers saved:
    DINT;
    PieCtrlRegs.PIEIER9.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);

}
#endif

// Connected to PIEIER9_2 (use MINT9 and MG92 masks):
#if (G92PL != 0)
interrupt void SCITXINTA_ISR(void)     // SCI-A
{
    // Set interrupt priority:
    volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER9.all;
    IER |= M_INT9;
    IER    &= MINT9;                         // Set "global" priority
    PieCtrlRegs.PIEIER9.all &= MG92;   // Set "group"  priority
    PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
    EINT;

      // Insert ISR Code here.......

    // Restore registers saved:
    DINT;
    PieCtrlRegs.PIEIER9.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);

}
#endif

// -----------------------------------------------------------
// PIE Group 10 - MUXed into CPU INT10
// -----------------------------------------------------------

/* Uncomment the below if ADCINT1 and ADCINT2 in the 10.1 and 10.2
   PIE interrupt spaces are enabled. Then comment out the equivalent
   1.1 and 1.2 interrupt service routines. */
/*
// Connected to PIEIER10_1 (use MINT10 and MG101 masks):
#if (G101PL != 0)
interrupt void  ADCINT1_ISR(void)      // ADC
{
    // Set interrupt priority:
    volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER10.all;
    IER |= MINT10;                     // Set "global" priority
    PieCtrlRegs.PIEIER10.all &= MG101; // Set "group"  priority
    PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
    EINT;

    // Restore registers saved:
    DINT;
    PieCtrlRegs.PIEIER10.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}
#endif

// Connected to PIEIER10_2 (use MINT10 and MG102 masks):
#if (G102PL != 0)
interrupt void  ADCINT2_ISR(void)      // ADC
{
    // Set interrupt priority:
    volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER10.all;
    IER |= MINT10;                     // Set "global" priority
    PieCtrlRegs.PIEIER10.all &= MG102; // Set "group"  priority
    PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
    EINT;

    // Restore registers saved:
    DINT;
    PieCtrlRegs.PIEIER10.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}
#endif

*/
// Connected to PIEIER10_3 (use MINT10 and MG103 masks):
#if (G103PL != 0)
interrupt void  ADCINT3_ISR(void)      // ADC
{
    // Set interrupt priority:
    volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER10.all;
    IER |= MINT10;                     // Set "global" priority
    PieCtrlRegs.PIEIER10.all &= MG103; // Set "group"  priority
    PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
    EINT;

    // Restore registers saved:
    DINT;
    PieCtrlRegs.PIEIER10.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}
#endif

// Connected to PIEIER10_4 (use MINT10 and MG104 masks):
#if (G104PL != 0)
interrupt void  ADCINT4_ISR(void)      // ADC
{
    // Set interrupt priority:
    volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER10.all;
    IER |= MINT10;                     // Set "global" priority
    PieCtrlRegs.PIEIER10.all &= MG104; // Set "group"  priority
    PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
    EINT;

    // Restore registers saved:
    DINT;
    PieCtrlRegs.PIEIER10.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}
#endif

// Connected to PIEIER10_5 (use MINT10 and MG105 masks):
#if (G105PL != 0)
interrupt void  ADCINT5_ISR(void)      // ADC
{
    // Set interrupt priority:
    volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER10.all;
    IER |= MINT10;                     // Set "global" priority
    PieCtrlRegs.PIEIER10.all &= MG105; // Set "group"  priority
    PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
    EINT;

      // Insert ISR Code here.......

    // Restore registers saved:
    DINT;
    PieCtrlRegs.PIEIER10.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}
#endif

// Connected to PIEIER10_6 (use MINT10 and MG106 masks):
#if (G106PL != 0)
interrupt void  ADCINT6_ISR(void)     // ADC
{
    // Set interrupt priority:
    volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER10.all;
    IER |= M_INT10;
    IER    &= MINT10;                     // Set "global" priority
    PieCtrlRegs.PIEIER10.all &= MG106; // Set "group"  priority
    PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
    EINT;

      // Insert ISR Code here.......

    // Restore registers saved:
    DINT;
    PieCtrlRegs.PIEIER10.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);

}
#endif

// Connected to PIEIER10_7 (use MINT10 and MG107 masks):
#if (G107PL != 0)
interrupt void  ADCINT7_ISR(void)      // ADC
{
    // Set interrupt priority:
    volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER10.all;
    IER |= M_INT10;
    IER    &= MINT10;                         // Set "global" priority
    PieCtrlRegs.PIEIER10.all &= MG107; // Set "group"  priority
    PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
    EINT;

      // Insert ISR Code here.......

      // Restore registers saved:
    DINT;
    PieCtrlRegs.PIEIER10.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}
#endif

// Connected to PIEIER10_8 (use MINT10 and MG108 masks):
#if (G108PL != 0)
interrupt void  ADCINT8_ISR(void)      // ADC
{
    // Set interrupt priority:
    volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER10.all;
    IER |= M_INT10;
    IER    &= MINT10;                         // Set "global" priority
    PieCtrlRegs.PIEIER10.all &= MG108; // Set "group"  priority
    PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
    EINT;

      // Insert ISR Code here.......

    // Restore registers saved:
    DINT;
    PieCtrlRegs.PIEIER10.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);
}
#endif


// -----------------------------------------------------------
// PIE Group 11 - MUXed into CPU INT11
// -----------------------------------------------------------

// -----------------------------------------------------------
// PIE Group 12 - MUXed into CPU INT12
// -----------------------------------------------------------

// Connected to PIEIER12_1 (use MINT12 and MG121 masks):
#if (G121PL != 0)
interrupt void XINT3_ISR(void)     // External interrupt
{
    // Set interrupt priority:
    volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER12.all;
    IER |= M_INT12;
    IER    &= MINT12;                          // Set "global" priority
    PieCtrlRegs.PIEIER12.all &= MG121;   // Set "group"  priority
    PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
    EINT;

      // Insert ISR Code here.......

    // Restore registers saved:
    DINT;
    PieCtrlRegs.PIEIER12.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    asm ("      ESTOP0");
    for(;;);

}
#endif

//---------------------------------------------------------------------------
// Catch All Default ISRs:
//

interrupt void PIE_RESERVED(void)  // Reserved space.  For test.
{
  asm ("      ESTOP0");
  for(;;);
}

interrupt void rsvd_ISR(void)      // For test
{
  asm ("      ESTOP0");
  for(;;);
}

//===========================================================================
// No more.
//===========================================================================
