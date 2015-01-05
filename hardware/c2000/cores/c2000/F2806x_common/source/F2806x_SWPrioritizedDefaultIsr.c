//###########################################################################
//
// FILE:    F2806x_SWPrioritizedDefaultIsr.c
//
// TITLE:   F2806x Device Default Software Prioritized Interrupt Service Routines.
//
//###########################################################################
// $TI Release: 2806x C/C++ Header Files V1.10 $
// $Release Date: April 7, 2011 $
//###########################################################################

#include "F2806x_Device.h"     // F2806x Headerfile Include File
#include "F2806x_Examples.h"   // F2806x Examples Include File
#include "F2806x_common/include/F2806x_SWPrioritizedIsrLevels.h"

// Connected to INT13 of CPU (use MINT13 mask):
// Note CPU-Timer1 is reserved for TI use, however XINT13
// ISR can be used by the user.
#if (INT13PL != 0)
__interrupt void INT13_ISR(void)     // INT13 or CPU-Timer1
{
	 IER |= MINT13;                 // Set "global" priority
	 EINT;

  // Insert ISR Code here

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
    __asm ("      ESTOP0");
     for(;;);
}
#endif

// Connected to INT14 of CPU (use MINT14 mask):
#if (INT14PL != 0)
__interrupt void INT14_ISR(void)     // CPU-Timer2
{
   IER |= MINT14;                  // Set "global" priority
   EINT;

   // Insert ISR Code here.......

   // Next two lines for debug only to halt the processor here
   // Remove after inserting ISR Code
  __asm ("      ESTOP0");
   for(;;);
}
#endif

// Connected to INT15 of CPU (use MINT15 mask):
#if (INT15PL != 0)
__interrupt void DATALOG_ISR(void)   // Datalogging interrupt
{
	IER |= MINT15;                 // Set "global" priority
	EINT;

  	// Insert ISR Code here.......

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);
}
#endif

// Connected to INT16 of CPU (use MINT16 mask):
#if (INT16PL != 0)
__interrupt void RTOSINT_ISR(void)   // RTOS interrupt
{
	IER |= MINT16;                 // Set "global" priority
	EINT;

  	// Insert ISR Code here.......

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);
}
#endif

// Connected to EMUINT of CPU (non-maskable):
__interrupt void EMUINT_ISR(void)    // Emulation interrupt
{
	EINT;

  	// Insert ISR Code here.......

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);
}

// Connected to NMI of CPU (non-maskable):
__interrupt void NMI_ISR(void)      // Non-maskable interrupt
{
	EINT;

  	// Insert ISR Code here.......

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);
}

__interrupt void ILLEGAL_ISR(void)   // Illegal operation TRAP
{
	EINT;

  	// Insert ISR Code here.......

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);
}

__interrupt void USER1_ISR(void)     // User Defined trap 1
{
	EINT;

  	// Insert ISR Code here.......

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);
}

__interrupt void USER2_ISR(void)     // User Defined trap 2
{
	EINT;

  	// Insert ISR Code here.......

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);
}

__interrupt void USER3_ISR(void)     // User Defined trap 3
{
	EINT;

  	// Insert ISR Code here.......

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);
}

__interrupt void USER4_ISR(void)     // User Defined trap 4
{
	EINT;

  	// Insert ISR Code here.......

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);
}

__interrupt void USER5_ISR(void)     // User Defined trap 5
{
	EINT;

  	// Insert ISR Code here.......

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);
}

__interrupt void USER6_ISR(void)     // User Defined trap 6
{
	EINT;

  	// Insert ISR Code here.......

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);
}

__interrupt void USER7_ISR(void)     // User Defined trap 7
{
	EINT;

  	// Insert ISR Code here.......

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);
}

__interrupt void USER8_ISR(void)     // User Defined trap 8
{
	EINT;

  	// Insert ISR Code here.......

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);
}

__interrupt void USER9_ISR(void)     // User Defined trap 9
{
	EINT;

  	// Insert ISR Code here.......

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);
}

__interrupt void USER10_ISR(void)    // User Defined trap 10
{
	EINT;

  	// Insert ISR Code here.......

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);
}

__interrupt void USER11_ISR(void)    // User Defined trap 11
{
	EINT;

  	// Insert ISR Code here.......

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);
}

__interrupt void USER12_ISR(void)     // User Defined trap 12
{
	EINT;

  	// Insert ISR Code here.......

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);
}

// -----------------------------------------------------------
// PIE Group 1 - MUXed into CPU INT1
// -----------------------------------------------------------

// Connected to PIEIER1_1 (use MINT1 and MG11 masks):
#if (G11PL != 0)
__interrupt void ADCINT1_ISR( void )     // ADC
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER1.all;
	IER |= M_INT1;
	IER	&= MINT1;	  	               // Set "global" priority
	PieCtrlRegs.PIEIER1.all &= MG11;   // Set "group"  priority
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
	EINT;

  	// Insert ISR Code here.......

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER1.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);

}
#endif

// Connected to PIEIER1_2 (use MINT1 and MG12 masks):
#if (G12PL != 0)
__interrupt void ADCINT2_ISR( void )    // ADC
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER1.all;
	IER |= M_INT1;
	IER	&= MINT1;	  	               // Set "global" priority
	PieCtrlRegs.PIEIER1.all &= MG12;   // Set "group"  priority
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
	EINT;

  	// Insert ISR Code here.......

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER1.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);

}
#endif

// Connected to PIEIER1_4 (use MINT1 and MG14 masks):
#if (G14PL != 0)
__interrupt void  XINT1_ISR(void)
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
   __asm ("      ESTOP0");
    for(;;);
}
#endif

// Connected to PIEIER1_5 (use MINT1 and MG15 masks):
#if (G15PL != 0)
__interrupt void  XINT2_ISR(void)
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
   __asm ("      ESTOP0");
    for(;;);
}
#endif

// Connected to PIEIER1_6 (use MINT1 and MG16 masks):
#if (G16PL != 0)
__interrupt void  ADCINT9_ISR(void)     // ADC
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER1.all;
	IER |= M_INT1;
	IER	&= MINT1;                      // Set "global" priority
	PieCtrlRegs.PIEIER1.all &= MG16;   // Set "group"  priority
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
	EINT;

  	// Insert ISR Code here.......

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER1.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);

}
#endif

// Connected to PIEIER1_7 (use MINT1 and MG17 masks):
#if (G17PL != 0)
__interrupt void  TINT0_ISR(void)      // CPU-Timer 0
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER1.all;
	IER |= M_INT1;
	IER	&= MINT1;	  	               // Set "global" priority
	PieCtrlRegs.PIEIER1.all &= MG17;   // Set "group"  priority
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
	EINT;

  	// Insert ISR Code here.......

  	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER1.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);
}
#endif

// Connected to PIEIER1_8 (use MINT1 and MG18 masks):
#if (G18PL != 0)
__interrupt void  WAKEINT_ISR(void)      // WD/LPM
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER1.all;
	IER |= M_INT1;
	IER	&= MINT1;	  	               // Set "global" priority
	PieCtrlRegs.PIEIER1.all &= MG18;   // Set "group"  priority
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
	EINT;

  	// Insert ISR Code here.......

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER1.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);
}
#endif

// -----------------------------------------------------------
// PIE Group 2 - MUXed into CPU INT2
// -----------------------------------------------------------

// Connected to PIEIER2_1 (use MINT2 and MG21 masks):
#if (G21PL != 0)
__interrupt void EPWM1_TZINT_ISR(void)    // ePWM1 Trip Zone
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER2.all;
	IER |= M_INT2;
	IER	&= MINT2;	  	               // Set "global" priority
	PieCtrlRegs.PIEIER2.all &= MG21;   // Set "group"  priority
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
	EINT;

  	// Insert ISR Code here.......

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER2.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);
}
#endif

// Connected to PIEIER2_2 (use MINT2 and MG22 masks):
#if (G22PL != 0)
__interrupt void EPWM2_TZINT_ISR(void)    // ePWM2 Trip Zone
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER2.all;
	IER |= M_INT2;
	IER	&= MINT2;	  	               // Set "global" priority
	PieCtrlRegs.PIEIER2.all &= MG22;   // Set "group"  priority
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
	EINT;

  	// Insert ISR Code here.......

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER2.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);
}
#endif

// Connected to PIEIER2_3 (use MINT2 and MG23 masks):
#if (G23PL != 0)
__interrupt void EPWM3_TZINT_ISR(void)    // ePWM3 Trip Zone
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER2.all;
	IER |= M_INT2;
	IER	&= MINT2;	  	               // Set "global" priority
	PieCtrlRegs.PIEIER2.all &= MG23;   // Set "group"  priority
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
	EINT;

  	// Insert ISR Code here.......

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER2.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);

}
#endif

// Connected to PIEIER2_4 (use MINT2 and MG24 masks):
#if (G24PL != 0)
__interrupt void EPWM4_TZINT_ISR(void)    // ePWM4 Trip Zone
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER2.all;
	IER |= M_INT2;
	IER	&= MINT2;	  	                // Set "global" priority
	PieCtrlRegs.PIEIER2.all &= MG24;    // Set "group"  priority
	PieCtrlRegs.PIEACK.all = 0xFFFF;    // Enable PIE interrupts
	EINT;

  	// Insert ISR Code here.......

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER2.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);

}
#endif

// Connected to PIEIER2_5 (use MINT2 and MG25 masks):
#if (G25PL != 0)
__interrupt void EPWM5_TZINT_ISR(void)    // ePWM5 Trip Zone
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER2.all;
	IER |= M_INT2;
	IER	&= MINT2;	  	                // Set "global" priority
	PieCtrlRegs.PIEIER2.all &= MG25;    // Set "group"  priority
	PieCtrlRegs.PIEACK.all = 0xFFFF;    // Enable PIE interrupts
	EINT;

  	// Insert ISR Code here.......

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER2.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);

}
#endif

// Connected to PIEIER2_6 (use MINT2 and MG26 masks):
#if (G26PL != 0)
__interrupt void EPWM6_TZINT_ISR(void)    // ePWM6 Trip Zone
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER2.all;
	IER |= M_INT2;
	IER	&= MINT2;	  	                // Set "global" priority
	PieCtrlRegs.PIEIER2.all &= MG26;    // Set "group"  priority
	PieCtrlRegs.PIEACK.all = 0xFFFF;    // Enable PIE interrupts
	EINT;

  	// Insert ISR Code here.......

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER2.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);

}
#endif

// Connected to PIEIER2_7 (use MINT2 and MG27 masks):
#if (G27PL != 0)
__interrupt void EPWM7_TZINT_ISR(void)    // ePWM7 Trip Zone
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER2.all;
	IER |= M_INT2;
	IER	&= MINT2;	  	                // Set "global" priority
	PieCtrlRegs.PIEIER2.all &= MG27;    // Set "group"  priority
	PieCtrlRegs.PIEACK.all = 0xFFFF;    // Enable PIE interrupts
	EINT;

  	// Insert ISR Code here.......

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER2.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);

}
#endif

// Connected to PIEIER2_8 (use MINT2 and MG28 masks):
#if (G28PL != 0)
__interrupt void EPWM8_TZINT_ISR(void)    // ePWM8 Trip Zone
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER2.all;
	IER |= M_INT2;
	IER	&= MINT2;	  	                // Set "global" priority
	PieCtrlRegs.PIEIER2.all &= MG28;    // Set "group"  priority
	PieCtrlRegs.PIEACK.all = 0xFFFF;    // Enable PIE interrupts
	EINT;

  	// Insert ISR Code here.......

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER2.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);

}
#endif

// -----------------------------------------------------------
// PIE Group 3 - MUXed into CPU INT3
// -----------------------------------------------------------

// Connected to PIEIER3_1 (use MINT3 and MG31 masks):
#if (G31PL != 0)
__interrupt void EPWM1_INT_ISR(void)     // ePWM1 Interrupt
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER3.all;
	IER |= M_INT3;
	IER	&= MINT3;	  	               // Set "global" priority
	PieCtrlRegs.PIEIER3.all &= MG31;   // Set "group"  priority
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
	EINT;

  	// Insert ISR Code here.......

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER3.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);
}
#endif

// Connected to PIEIER3_2 (use MINT3 and MG32 masks):
#if (G32PL != 0)
__interrupt void EPWM2_INT_ISR(void)     // ePWM2 Interrupt
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER3.all;
	IER |= M_INT3;
	IER	&= MINT3;	  	               // Set "global" priority
	PieCtrlRegs.PIEIER3.all &= MG32;   // Set "group"  priority
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
	EINT;

  	// Insert ISR Code here.......

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER3.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);

}
#endif

// Connected to PIEIER3_3 (use MINT3 and MG33 masks):
#if (G33PL != 0)
__interrupt void EPWM3_INT_ISR(void)     // ePWM3 Interrupt
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER3.all;
	IER |= M_INT3;
	IER	&= MINT3;	  	                // Set "global" priority
	PieCtrlRegs.PIEIER3.all &= MG33;   // Set "group"  priority
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
	EINT;

  	// Insert ISR Code here.......

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER3.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);

}
#endif

// Connected to PIEIER3_4 (use MINT3 and MG34 masks):
#if (G34PL != 0)
__interrupt void EPWM4_INT_ISR(void)     // ePWM4 Interrupt
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER3.all;
	IER |= M_INT3;
	IER	&= MINT3;	  	               // Set "global" priority
	PieCtrlRegs.PIEIER3.all &= MG34;   // Set "group"  priority
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
	EINT;

  	// Insert ISR Code here.......

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER3.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);

}
#endif

// Connected to PIEIER3_5 (use MINT3 and MG35 masks):
#if (G35PL != 0)
__interrupt void EPWM5_INT_ISR(void)     // ePWM5 Interrupt
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER3.all;
	IER |= M_INT3;
	IER	&= MINT3;	  	               // Set "global" priority
	PieCtrlRegs.PIEIER3.all &= MG35;   // Set "group"  priority
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
	EINT;

  	// Insert ISR Code here.......

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER3.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);

}
#endif

// Connected to PIEIER3_6 (use MINT3 and MG36 masks):
#if (G36PL != 0)
__interrupt void EPWM6_INT_ISR(void)     // ePWM6 Interrupt
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER3.all;
	IER |= M_INT3;
	IER	&= MINT3;	  	               // Set "global" priority
	PieCtrlRegs.PIEIER3.all &= MG36;   // Set "group"  priority
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
	EINT;

  	// Insert ISR Code here.......

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER3.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);

}
#endif

// Connected to PIEIER3_7 (use MINT3 and MG37 masks):
#if (G37PL != 0)
__interrupt void EPWM7_INT_ISR(void)     // ePWM7 Interrupt
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER3.all;
	IER |= M_INT3;
	IER	&= MINT3;	  	               // Set "global" priority
	PieCtrlRegs.PIEIER3.all &= MG37;   // Set "group"  priority
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
	EINT;

  	// Insert ISR Code here.......

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER3.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);

}
#endif

// Connected to PIEIER3_8 (use MINT3 and MG38 masks):
#if (G38PL != 0)
__interrupt void EPWM8_INT_ISR(void)     // ePWM8 Interrupt
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER3.all;
	IER |= M_INT3;
	IER	&= MINT3;	  	               // Set "global" priority
	PieCtrlRegs.PIEIER3.all &= MG38;   // Set "group"  priority
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
	EINT;

  	// Insert ISR Code here.......

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER3.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);

}
#endif

// -----------------------------------------------------------
// PIE Group 4 - MUXed into CPU INT4
// -----------------------------------------------------------

// Connected to PIEIER4_1 (use MINT4 and MG41 masks):
#if (G41PL != 0)
__interrupt void ECAP1_INT_ISR(void)     // eCAP1 Interrupt
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER4.all;
	IER |= M_INT4;
	IER	&= MINT4;	  	               // Set "global" priority
	PieCtrlRegs.PIEIER4.all &= MG41;   // Set "group"  priority
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
	EINT;

  	// Insert ISR Code here.......

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER4.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);

}
#endif

// Connected to PIEIER4_2 (use MINT4 and MG42 masks):
#if (G42PL != 0)
__interrupt void ECAP2_INT_ISR(void)     // eCAP2 Interrupt
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER4.all;
	IER |= M_INT4;
	IER	&= MINT4;	  	               // Set "global" priority
	PieCtrlRegs.PIEIER4.all &= MG42;   // Set "group"  priority
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
	EINT;

  	// Insert ISR Code here.......

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER4.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);

}
#endif

// Connected to PIEIER4_3 (use MINT4 and MG43 masks):
#if (G43PL != 0)
__interrupt void ECAP3_INT_ISR(void)     // eCAP3 Interrupt
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER4.all;
	IER |= M_INT4;
	IER	&= MINT4;	  	               // Set "global" priority
	PieCtrlRegs.PIEIER4.all &= MG43;   // Set "group"  priority
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
	EINT;

  	// Insert ISR Code here.......

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER4.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);

}
#endif

// Connected to PIEIER4_3 (use MINT4 and MG47 masks):
#if (G47PL != 0)
__interrupt void HRCAP1_INT_ISR(void)     // HRCAP1 Interrupt
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER4.all;
	IER |= M_INT4;
	IER	&= MINT4;	  	               // Set "global" priority
	PieCtrlRegs.PIEIER4.all &= MG47;   // Set "group"  priority
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
	EINT;

  	// Insert ISR Code here.......

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER4.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);

}
#endif

// Connected to PIEIER4_3 (use MINT4 and MG48 masks):
#if (G48PL != 0)
__interrupt void HRCAP2_INT_ISR(void)     // HRCAP2 Interrupt
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER4.all;
	IER |= M_INT4;
	IER	&= MINT4;	  	               // Set "global" priority
	PieCtrlRegs.PIEIER4.all &= MG48;   // Set "group"  priority
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
	EINT;

  	// Insert ISR Code here.......

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER4.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);

}
#endif

// -----------------------------------------------------------
// PIE Group 5 - MUXed into CPU INT5
// -----------------------------------------------------------

// Connected to PIEIER5_1 (use MINT5 and MG51 masks):
#if (G51PL != 0)
__interrupt void EQEP1_INT_ISR(void)     // eQEP1 Interrupt
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER5.all;
	IER |= M_INT5;
	IER	&= MINT5;	  	               // Set "global" priority
	PieCtrlRegs.PIEIER5.all &= MG51;   // Set "group"  priority
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
	EINT;

  	// Insert ISR Code here.......

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER5.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);

}
#endif

// Connected to PIEIER5_2 (use MINT5 and MG52 masks):
#if (G52PL != 0)
__interrupt void EQEP2_INT_ISR(void)     // eQEP2 Interrupt
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER5.all;
	IER |= M_INT5;
	IER	&= MINT5;	  	               // Set "global" priority
	PieCtrlRegs.PIEIER5.all &= MG52;   // Set "group"  priority
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
	EINT;

  	// Insert ISR Code here.......

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER5.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);

}
#endif

// Connected to PIEIER5_2 (use MINT5 and MG54 masks):
#if (G54PL != 0)
__interrupt void HRCAP3_INT_ISR(void)     // HRCAP3 Interrupt
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER5.all;
	IER |= M_INT5;
	IER	&= MINT5;	  	               // Set "global" priority
	PieCtrlRegs.PIEIER5.all &= MG54;   // Set "group"  priority
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
	EINT;

  	// Insert ISR Code here.......

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER5.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);

}
#endif

// Connected to PIEIER5_2 (use MINT5 and MG55 masks):
#if (G55PL != 0)
__interrupt void HRCAP4_INT_ISR(void)     // HRCAP4 Interrupt
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER5.all;
	IER |= M_INT5;
	IER	&= MINT5;	  	               // Set "global" priority
	PieCtrlRegs.PIEIER5.all &= MG55;   // Set "group"  priority
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
	EINT;

  	// Insert ISR Code here.......

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER5.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);

}
#endif

// Connected to PIEIER5_2 (use MINT5 and MG58 masks):
#if (G58PL != 0)
__interrupt void USB0_INT_ISR(void)     // USB0 Interrupt
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER5.all;
	IER |= M_INT5;
	IER	&= MINT5;	  	               // Set "global" priority
	PieCtrlRegs.PIEIER5.all &= MG58;   // Set "group"  priority
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
	EINT;

  	// Insert ISR Code here.......

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER5.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);

}
#endif

// -----------------------------------------------------------
// PIE Group 6 - MUXed into CPU INT6
// -----------------------------------------------------------

// Connected to PIEIER6_1 (use MINT6 and MG61 masks):
#if (G61PL != 0)
__interrupt void SPIRXINTA_ISR(void)    // SPI-A
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER6.all;
	IER |= M_INT6;
	IER	&= MINT6;	  	               // Set "global" priority
	PieCtrlRegs.PIEIER6.all &= MG61;   // Set "group"  priority
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
	EINT;

  	// Insert ISR Code here.......

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER6.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);

}
#endif

// Connected to PIEIER6_2 (use MINT6 and MG62 masks):
#if (G62PL != 0)
__interrupt void SPITXINTA_ISR(void)     // SPI-A
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER6.all;
	IER |= M_INT6;
	IER	&= MINT6;	  	               // Set "global" priority
	PieCtrlRegs.PIEIER6.all &= MG62;   // Set "group"  priority
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
	EINT;

  	// Insert ISR Code here.......

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER6.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);
}
#endif

// Connected to PIEIER6_3 (use MINT6 and MG63 masks):
#if (G63PL != 0)
__interrupt void SPIRXINTB_ISR(void)    // SPI-B
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER6.all;
	IER |= M_INT6;
	IER	&= MINT6;	  	               // Set "global" priority
	PieCtrlRegs.PIEIER6.all &= MG63;   // Set "group"  priority
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
	EINT;

  	// Insert ISR Code here.......

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER6.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);

}
#endif

// Connected to PIEIER6_4 (use MINT6 and MG64 masks):
#if (G64PL != 0)
__interrupt void SPITXINTB_ISR(void)     // SPI-A
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER6.all;
	IER |= M_INT6;
	IER	&= MINT6;	  	               // Set "global" priority
	PieCtrlRegs.PIEIER6.all &= MG64;   // Set "group"  priority
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
	EINT;

  	// Insert ISR Code here.......

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER6.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);
}
#endif

// Connected to PIEIER6_5 (use MINT6 and MG65 masks):
#if (G65PL != 0)
__interrupt void MRINTA_ISR(void)     // McBSP-A
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER6.all;
	IER |= M_INT6;
	IER	&= MINT6;	  	               // Set "global" priority
	PieCtrlRegs.PIEIER6.all &= MG65;   // Set "group"  priority
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
	EINT;

  	// Insert ISR Code here.......

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER6.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);
}
#endif

// Connected to PIEIER6_6 (use MINT6 and MG66 masks):
#if (G66PL != 0)
__interrupt void MXINTA_ISR(void)     // McBSP=A
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER6.all;
	IER |= M_INT6;
	IER	&= MINT6;	  	               // Set "global" priority
	PieCtrlRegs.PIEIER6.all &= MG66;   // Set "group"  priority
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
	EINT;

  	// Insert ISR Code here.......

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER6.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);
}
#endif

// -----------------------------------------------------------
// PIE Group 7 - MUXed into CPU INT7
// -----------------------------------------------------------

// Connected to PIEIER7_1 (use MINT7 and MG71 masks):
#if (G71PL != 0)
__interrupt void DINTCH1_ISR(void)     // DMA CH1
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER7.all;
	IER |= M_INT7;
	IER	&= MINT7;	  	               // Set "global" priority
	PieCtrlRegs.PIEIER7.all &= MG71;   // Set "group"  priority
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
	EINT;

  	// Insert ISR Code here.......

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER7.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);
}

#endif
// Connected to PIEIER7_2 (use MINT7 and MG72 masks):
#if (G72PL != 0)
__interrupt void DINTCH2_ISR(void)     // DMA CH2
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER7.all;
	IER |= M_INT7;
	IER	&= MINT7;	  	               // Set "global" priority
	PieCtrlRegs.PIEIER7.all &= MG72;   // Set "group"  priority
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
	EINT;

  	// Insert ISR Code here.......

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER7.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);
}

#endif
// Connected to PIEIER7_3 (use MINT7 and MG73 masks):
#if (G73PL != 0)
__interrupt void DINTCH3_ISR(void)     // DMA CH3
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER7.all;
	IER |= M_INT7;
	IER	&= MINT7;	  	               // Set "global" priority
	PieCtrlRegs.PIEIER7.all &= MG73;   // Set "group"  priority
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
	EINT;

  	// Insert ISR Code here.......

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER7.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);
}
#endif

// Connected to PIEIER7_4 (use MINT7 and MG74 masks):
#if (G74PL != 0)
__interrupt void DINTCH4_ISR(void)     // DMA CH4
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER7.all;
	IER |= M_INT7;
	IER	&= MINT7;	  	               // Set "global" priority
	PieCtrlRegs.PIEIER7.all &= MG74;   // Set "group"  priority
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
	EINT;

  	// Insert ISR Code here.......

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER7.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);
}
#endif

// Connected to PIEIER7_5 (use MINT7 and MG75 masks):
#if (G75PL != 0)
__interrupt void DINTCH5_ISR(void)     // DMA CH5
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER7.all;
	IER |= M_INT7;
	IER	&= MINT7;	  	               // Set "global" priority
	PieCtrlRegs.PIEIER7.all &= MG75;   // Set "group"  priority
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
	EINT;

  	// Insert ISR Code here.......

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER7.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);
}
#endif

// Connected to PIEIER7_6 (use MINT7 and MG76 masks):
#if (G76PL != 0)
__interrupt void DINTCH6_ISR(void)     // DMA CH6
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER7.all;
	IER |= M_INT7;
	IER	&= MINT7;	  	               // Set "global" priority
	PieCtrlRegs.PIEIER7.all &= MG76;   // Set "group"  priority
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
	EINT;

  	// Insert ISR Code here.......

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER7.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);
}
#endif

// -----------------------------------------------------------
// PIE Group 8 - MUXed into CPU INT8
// -----------------------------------------------------------

// Connected to PIEIER8_1 (use MINT8 and MG81 masks):
#if (G81PL != 0)
__interrupt void I2CINT1A_ISR(void)    // I2C-A
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER8.all;
	IER |= M_INT8;
	IER	&= MINT8;	  	               // Set "global" priority
	PieCtrlRegs.PIEIER6.all &= MG81;   // Set "group"  priority
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
	EINT;

  	// Insert ISR Code here.......

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER8.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);

}
#endif

// Connected to PIEIER8_2 (use MINT8 and MG82 masks):
#if (G82PL != 0)
__interrupt void I2CINT2A_ISR(void)     // I2C-A
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER8.all;
	IER |= M_INT8;
	IER	&= MINT8;	  	               // Set "global" priority
	PieCtrlRegs.PIEIER6.all &= MG82;   // Set "group"  priority
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
	EINT;

  	// Insert ISR Code here.......

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER8.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);

}
#endif

// -----------------------------------------------------------
// PIE Group 9 - MUXed into CPU INT9
// -----------------------------------------------------------

// Connected to PIEIER9_1 (use MINT9 and MG91 masks):
#if (G91PL != 0)
__interrupt void SCIRXINTA_ISR(void)     // SCI-A
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER9.all;
	IER |= M_INT9;
	IER	&= MINT9;	  	                // Set "global" priority
	PieCtrlRegs.PIEIER9.all &= MG91;   // Set "group"  priority
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
	EINT;

  	// Insert ISR Code here.......

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER9.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);

}
#endif

// Connected to PIEIER9_2 (use MINT9 and MG92 masks):
#if (G92PL != 0)
__interrupt void SCITXINTA_ISR(void)     // SCI-A
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER9.all;
	IER |= M_INT9;
	IER	&= MINT9;	  	               // Set "global" priority
	PieCtrlRegs.PIEIER9.all &= MG92;   // Set "group"  priority
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
	EINT;

  	// Insert ISR Code here.......

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER9.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);

}
#endif

// Connected to PIEIER9_3 (use MINT9 and MG93 masks):
#if (G93PL != 0)
__interrupt void SCIRXINTB_ISR(void)     // SCI-B
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER9.all;
	IER |= M_INT9;
	IER	&= MINT9;	  	               // Set "global" priority
	PieCtrlRegs.PIEIER9.all &= MG93;   // Set "group"  priority
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
	EINT;

  	// Insert ISR Code here.......

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER9.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);

}
#endif

// Connected to PIEIER9_4 (use MINT9 and MG94 masks):
#if (G94PL != 0)
__interrupt void SCITXINTB_ISR(void)     // SCI-B
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER9.all;
	IER |= M_INT9;
	IER	&= MINT9;	  	               // Set "global" priority
	PieCtrlRegs.PIEIER9.all &= MG94;   // Set "group"  priority
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
	EINT;

  	// Insert ISR Code here.......

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER9.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);

}
#endif

// Connected to PIEIER9_5 (use MINT9 and MG95 masks):
#if (G95PL != 0)
__interrupt void ECAN0INTA_ISR(void)    // eCAN-A
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER9.all;
	IER |= M_INT9;
	IER	&= MINT9;	  	               // Set "global" priority
	PieCtrlRegs.PIEIER9.all &= MG95;   // Set "group"  priority
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
	EINT;

  	// Insert ISR Code here.......

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER9.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);

}
#endif

// Connected to PIEIER9_6 (use MINT9 and MG96 masks):
#if (G96PL != 0)
__interrupt void ECAN1INTA_ISR(void)    // eCAN-A
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER9.all;
	IER |= M_INT9;
	IER	&= MINT9;	  	               // Set "global" priority
	PieCtrlRegs.PIEIER9.all &= MG96;   // Set "group"  priority
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
	EINT;

  	// Insert ISR Code here.......

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER9.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
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
__interrupt void  ADCINT1_ISR(void)      // ADC
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
   __asm ("      ESTOP0");
    for(;;);
}
#endif

// Connected to PIEIER10_2 (use MINT10 and MG102 masks):
#if (G102PL != 0)
__interrupt void  ADCINT2_ISR(void)      // ADC
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
   __asm ("      ESTOP0");
    for(;;);
}
#endif

*/

// Connected to PIEIER10_3 (use MINT10 and MG103 masks):
#if (G103PL != 0)
__interrupt void  ADCINT3_ISR(void)      // ADC
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
   __asm ("      ESTOP0");
    for(;;);
}
#endif

// Connected to PIEIER10_4 (use MINT10 and MG104 masks):
#if (G104PL != 0)
__interrupt void  ADCINT4_ISR(void)      // ADC
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
   __asm ("      ESTOP0");
    for(;;);
}
#endif

// Connected to PIEIER10_5 (use MINT10 and MG105 masks):
#if (G105PL != 0)
__interrupt void  ADCINT5_ISR(void)      // ADC
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
   __asm ("      ESTOP0");
    for(;;);
}
#endif

// Connected to PIEIER10_6 (use MINT10 and MG106 masks):
#if (G106PL != 0)
__interrupt void  ADCINT6_ISR(void)     // ADC
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER10.all;
	IER |= M_INT10;
	IER	&= MINT10;                     // Set "global" priority
	PieCtrlRegs.PIEIER10.all &= MG106; // Set "group"  priority
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
	EINT;

  	// Insert ISR Code here.......

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER10.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);

}
#endif

// Connected to PIEIER10_7 (use MINT10 and MG107 masks):
#if (G107PL != 0)
__interrupt void  ADCINT7_ISR(void)      // ADC
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER10.all;
	IER |= M_INT10;
	IER	&= MINT10;	  	               // Set "global" priority
	PieCtrlRegs.PIEIER10.all &= MG107; // Set "group"  priority
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
	EINT;

  	// Insert ISR Code here.......

  	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER10.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);
}
#endif

// Connected to PIEIER10_8 (use MINT10 and MG108 masks):
#if (G108PL != 0)
__interrupt void  ADCINT8_ISR(void)      // ADC
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER10.all;
	IER |= M_INT10;
	IER	&= MINT10;	  	               // Set "global" priority
	PieCtrlRegs.PIEIER10.all &= MG108; // Set "group"  priority
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
	EINT;

  	// Insert ISR Code here.......

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER10.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);
}
#endif


// -----------------------------------------------------------
// PIE Group 11 - MUXed into CPU INT11
// -----------------------------------------------------------

// Connected to PIEIER11_1 (use MINT11 and MG111 masks):
#if (G111PL != 0)
__interrupt void  CLA1_INT1_ISR(void)      // CLA1
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER11.all;
	IER |= MINT11;                     // Set "global" priority
	PieCtrlRegs.PIEIER11.all &= MG111; // Set "group"  priority
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
	EINT;

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER11.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);
}
#endif

// Connected to PIEIER11_2 (use MINT11 and MG112 masks):
#if (G112PL != 0)
__interrupt void  CLA1_INT2_ISR(void)      // CLA1
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER11.all;
	IER |= MINT11;                     // Set "global" priority
	PieCtrlRegs.PIEIER11.all &= MG112; // Set "group"  priority
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
	EINT;

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER11.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);
}
#endif

// Connected to PIEIER11_3 (use MINT11 and MG113 masks):
#if (G113PL != 0)
__interrupt void  CLA1_INT3_ISR(void)      // CLA1
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER11.all;
	IER |= MINT11;                     // Set "global" priority
	PieCtrlRegs.PIEIER11.all &= MG113; // Set "group"  priority
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
	EINT;

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER11.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);
}
#endif

// Connected to PIEIER11_4 (use MINT11 and MG114 masks):
#if (G114PL != 0)
__interrupt void  CLA1_INT4_ISR(void)      // CLA1
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER11.all;
	IER |= MINT11;                     // Set "global" priority
	PieCtrlRegs.PIEIER11.all &= MG114; // Set "group"  priority
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
	EINT;

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER11.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);
}
#endif

// Connected to PIEIER11_5 (use MINT11 and MG115 masks):
#if (G115PL != 0)
__interrupt void  CLA1_INT5_ISR(void)      // CLA1
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER11.all;
	IER |= MINT11;                     // Set "global" priority
	PieCtrlRegs.PIEIER11.all &= MG115; // Set "group"  priority
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
	EINT;

  	// Insert ISR Code here.......

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER11.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);
}
#endif

// Connected to PIEIER11_6 (use MINT11 and MG116 masks):
#if (G116PL != 0)
__interrupt void  CLA1_INT6_ISR(void)     // CLA1
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER11.all;
	IER |= M_INT11;
	IER	&= MINT11;                     // Set "global" priority
	PieCtrlRegs.PIEIER11.all &= MG116; // Set "group"  priority
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
	EINT;

  	// Insert ISR Code here.......

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER11.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);

}
#endif

// Connected to PIEIER11_7 (use MINT11 and MG117 masks):
#if (G117PL != 0)
__interrupt void  CLA1_INT7_ISR(void)      // CLA1
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER11.all;
	IER |= M_INT11;
	IER	&= MINT11;	  	               // Set "global" priority
	PieCtrlRegs.PIEIER11.all &= MG117; // Set "group"  priority
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
	EINT;

  	// Insert ISR Code here.......

  	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER11.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);
}
#endif

// Connected to PIEIER11_8 (use MINT11 and MG118 masks):
#if (G118PL != 0)
__interrupt void  CLA1_INT8_ISR(void)      // CLA1
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER11.all;
	IER |= M_INT11;
	IER	&= MINT11;	  	               // Set "global" priority
	PieCtrlRegs.PIEIER11.all &= MG118; // Set "group"  priority
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts
	EINT;

  	// Insert ISR Code here.......

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER11.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);
}
#endif

// -----------------------------------------------------------
// PIE Group 12 - MUXed into CPU INT12
// -----------------------------------------------------------

// Connected to PIEIER12_1 (use MINT12 and MG121 masks):
#if (G121PL != 0)
__interrupt void XINT3_ISR(void)     // External interrupt
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER12.all;
	IER |= M_INT12;
	IER	&= MINT12;	  	                // Set "global" priority
	PieCtrlRegs.PIEIER12.all &= MG121;  // Set "group"  priority
	PieCtrlRegs.PIEACK.all = 0xFFFF;    // Enable PIE interrupts
	EINT;

  	// Insert ISR Code here.......

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER12.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);

}
#endif

// Connected to PIEIER12_7 (use MINT12 and MG127 masks):
#if (G127PL != 0)
__interrupt void LVF_ISR(void)     // CLA1
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER12.all;
	IER |= M_INT12;
	IER	&= MINT12;	  	                // Set "global" priority
	PieCtrlRegs.PIEIER12.all &= MG127;  // Set "group"  priority
	PieCtrlRegs.PIEACK.all = 0xFFFF;    // Enable PIE interrupts
	EINT;

  	// Insert ISR Code here.......

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER12.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);

}
#endif

// Connected to PIEIER12_8 (use MINT12 and MG128 masks):
#if (G128PL != 0)
__interrupt void LUF_ISR(void)     // CLA1
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER12.all;
	IER |= M_INT12;
	IER	&= MINT12;	  	                // Set "global" priority
	PieCtrlRegs.PIEIER12.all &= MG128;  // Set "group"  priority
	PieCtrlRegs.PIEACK.all = 0xFFFF;    // Enable PIE interrupts
	EINT;

  	// Insert ISR Code here.......

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER12.all = TempPIEIER;

    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
   __asm ("      ESTOP0");
    for(;;);

}
#endif

//---------------------------------------------------------------------------
// Catch All Default ISRs:
//


__interrupt void PIE_RESERVED(void)  // Reserved space.  For test.
{
 __asm ("      ESTOP0");
  for(;;);
}

__interrupt void INT_NOTUSED_ISR(void)  // Reserved space.  For test.
{
 __asm ("      ESTOP0");
  for(;;);
}

__interrupt void rsvd_ISR(void)      // For test
{
 __asm ("      ESTOP0");
  for(;;);
}

//===========================================================================
// No more.
//===========================================================================
