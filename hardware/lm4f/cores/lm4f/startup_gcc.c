//*****************************************************************************
//
// startup_gcc.c - Startup code for use with GNU tools.
//
// Copyright (c) 2009-2012 Texas Instruments Incorporated.  All rights reserved.
// Software License Agreement
// 
// Texas Instruments (TI) is supplying this software for use solely and
// exclusively on TI's microcontroller products. The software is owned by
// TI and/or its suppliers, and is protected under applicable copyright
// laws. You may not combine this software with "viral" open-source
// software in order to form a larger program.
// 
// THIS SOFTWARE IS PROVIDED "AS IS" AND WITH ALL FAULTS.
// NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT
// NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. TI SHALL NOT, UNDER ANY
// CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR CONSEQUENTIAL
// DAMAGES, FOR ANY REASON WHATSOEVER.
// 
// This is part of revision 9107 of the RDK-IDM-SBC Firmware Package.
//
//*****************************************************************************
#include "Energia.h"
//*****************************************************************************
//
// Forward declaration of the default fault handlers.
//
//*****************************************************************************
void ResetISR(void);
static void NmiSR(void);
static void FaultISR(void);
static void IntDefaultHandler(void);

//*****************************************************************************
//
// The entry point for the application.
//
//*****************************************************************************
extern int main(void);
extern void UART0IntHandler(void);
//*****************************************************************************
//
// Reserve space for the system stack.
//
//*****************************************************************************
static unsigned long pulStack[128];

//*****************************************************************************
//
// The vector table.  Note that the proper constructs must be placed on this to
// ensure that it ends up at physical address 0x0000.0000.
//
//*****************************************************************************
__attribute__ ((section(".isr_vector")))
void (* const g_pfnVectors[])(void) =
{
        (void (*)(void))((unsigned long)pulStack + sizeof(pulStack)),
        // The initial stack pointer
        ResetISR,                               // The reset handler
        NmiSR,                                  // The NMI handler
        FaultISR,                               // The hard fault handler
        IntDefaultHandler,                      // The MPU fault handler
        IntDefaultHandler,                      // The bus fault handler
        IntDefaultHandler,                      // The usage fault handler
        0,                                      // Reserved
        0,                                      // Reserved
        0,                                      // Reserved
        0,                                      // Reserved
        IntDefaultHandler,                      // SVCall handler
        IntDefaultHandler,                      // Debug monitor handler
        0,                                      // Reserved
        IntDefaultHandler,                      // The PendSV handler
        IntDefaultHandler,                      // The SysTick handler
        IntDefaultHandler,                      // GPIO Port A
        IntDefaultHandler,                      // GPIO Port B
        IntDefaultHandler,                      // GPIO Port C
        IntDefaultHandler,                      // GPIO Port D
        IntDefaultHandler,                      // GPIO Port E
        UART0IntHandler,                        // UART0 Rx and Tx
        IntDefaultHandler,                      // UART1 Rx and Tx
        IntDefaultHandler,                      // SSI0 Rx and Tx
        IntDefaultHandler,                      // I2C0 Master and Slave
        IntDefaultHandler,                      // PWM Fault
        IntDefaultHandler,                      // PWM Generator 0
        IntDefaultHandler,                      // PWM Generator 1
        IntDefaultHandler,                      // PWM Generator 2
        IntDefaultHandler,                      // Quadrature Encoder 0
        IntDefaultHandler,                      // ADC Sequence 0
        IntDefaultHandler,                      // ADC Sequence 1
        IntDefaultHandler,                      // ADC Sequence 2
        IntDefaultHandler,                      // ADC Sequence 3
        IntDefaultHandler,                      // Watchdog timer
        IntDefaultHandler,                      // Timer 0 subtimer A
        IntDefaultHandler,                      // Timer 0 subtimer B
        IntDefaultHandler,                      // Timer 1 subtimer A
        IntDefaultHandler,                      // Timer 1 subtimer B
        IntDefaultHandler,                      // Timer 2 subtimer A
        IntDefaultHandler,                      // Timer 2 subtimer B
        IntDefaultHandler,                      // Analog Comparator 0
        IntDefaultHandler,                      // Analog Comparator 1
        IntDefaultHandler,                      // Analog Comparator 2
        IntDefaultHandler,                      // System Control (PLL, OSC, BO)
        IntDefaultHandler,                      // FLASH Control
        IntDefaultHandler,                      // GPIO Port F
        IntDefaultHandler,                      // GPIO Port G
        IntDefaultHandler,                      // GPIO Port H
        IntDefaultHandler,                      // UART2 Rx and Tx
        IntDefaultHandler,                      // SSI1 Rx and Tx
        IntDefaultHandler,                      // Timer 3 subtimer A
        IntDefaultHandler,                      // Timer 3 subtimer B
        IntDefaultHandler,                      // I2C1 Master and Slave
        IntDefaultHandler,                      // Quadrature Encoder 1
        IntDefaultHandler,                      // CAN0
        IntDefaultHandler,                      // CAN1
        IntDefaultHandler,                      // CAN2
        IntDefaultHandler,                      // Ethernet
        IntDefaultHandler,                      // Hibernate
        IntDefaultHandler,                      // USB0
        IntDefaultHandler,                      // PWM Generator 3
        IntDefaultHandler,                      // uDMA Software Transfer
        IntDefaultHandler,                      // uDMA Error
        IntDefaultHandler,                      // ADC1 Sequence 0
        IntDefaultHandler,                      // ADC1 Sequence 1
        IntDefaultHandler,                      // ADC1 Sequence 2
        IntDefaultHandler,                      // ADC1 Sequence 3
        IntDefaultHandler,                      // I2S0
        IntDefaultHandler,                      // External Bus Interface 0
        IntDefaultHandler                       // GPIO Port J
};

//*****************************************************************************
//
// The following are constructs created by the linker, indicating where the
// the "data" and "bss" segments reside in memory.  The initializers for the
// for the "data" segment resides immediately following the "text" segment.
//
//*****************************************************************************
extern unsigned long _etext;
extern unsigned long _data;
extern unsigned long _edata;
extern unsigned long _bss;
extern unsigned long _ebss;

//*****************************************************************************
//
// This is the code that gets called when the processor first starts execution
// following a reset event.  Only the absolutely necessary set is performed,
// after which the application supplied entry() routine is called.  Any fancy
// actions (such as making decisions based on the reset cause register, and
// resetting the bits in that register) are left solely in the hands of the
// application.
//
//*****************************************************************************
void
ResetISR(void)
{
    unsigned long *pulSrc, *pulDest;

    //
    // Copy the data segment initializers from flash to SRAM.
    //
    pulSrc = &_etext;
    for(pulDest = &_data; pulDest < &_edata; )
    {
        *pulDest++ = *pulSrc++;
    }

    //
    // Zero fill the bss segment.
    //
    __asm("    ldr     r0, =_bss\n"
            "    ldr     r1, =_ebss\n"
            "    mov     r2, #0\n"
            "    .thumb_func\n"
            "zero_loop:\n"
            "        cmp     r0, r1\n"
            "        it      lt\n"
            "        strlt   r2, [r0], #4\n"
            "        blt     zero_loop");

    //
    // Call the application's entry point.
    //
    main();
}

//*****************************************************************************
//
// This is the code that gets called when the processor receives a NMI.  This
// simply enters an infinite loop, preserving the system state for examination
// by a debugger.
//
//*****************************************************************************
static void
NmiSR(void)
{
    //
    // Enter an infinite loop.
    //
    while(1)
    {
        pinMode(RED_LED, OUTPUT);
        digitalWrite(RED_LED, HIGH);
    }
}

//*****************************************************************************
//
// This is the code that gets called when the processor receives a fault
// interrupt.  This simply enters an infinite loop, preserving the system state
// for examination by a debugger.
//
//*****************************************************************************
static void
FaultISR(void)
{
    //
    // Enter an infinite loop.
    //
    while(1)
    {
                    pinMode(RED_LED, OUTPUT);
    digitalWrite(RED_LED, HIGH);
    }
}

//*****************************************************************************
//
// This is the code that gets called when the processor receives an unexpected
// interrupt.  This simply enters an infinite loop, preserving the system state
// for examination by a debugger.
//
//*****************************************************************************
static void
IntDefaultHandler(void)
{
    //
    // Go into an infinite loop.
    //
    while(1)
    {
                        pinMode(RED_LED, OUTPUT);
    digitalWrite(RED_LED, HIGH);
    }
}
