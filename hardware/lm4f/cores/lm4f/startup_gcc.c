//*****************************************************************************
//
// startup_gcc.c - Startup code for use with GNU tools.
//
// Copyright (c) 2009-2012 Texas Instruments Incorporated.  All rights reserved.
// Software License Agreement
// 
//   Redistribution and use in source and binary forms, with or without
//   modification, are permitted provided that the following conditions
//   are met:
// 
//   Redistributions of source code must retain the above copyright
//   notice, this list of conditions and the following disclaimer.
// 
//   Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the
//   documentation and/or other materials provided with the  
//   distribution.
// 
//   Neither the name of Texas Instruments Incorporated nor the names of
//   its contributors may be used to endorse or promote products derived
//   from this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//*****************************************************************************

#include "Energia.h"
#include "inc/hw_types.h"
#include "inc/hw_nvic.h"
#include <stdio.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
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
extern void GPIOAIntHandler(void);
extern void GPIOBIntHandler(void);
extern void GPIOCIntHandler(void);
extern void GPIODIntHandler(void);
extern void GPIOEIntHandler(void);
extern void GPIOFIntHandler(void);
extern void GPIOGIntHandler(void);
extern void GPIOHIntHandler(void);
extern void GPIOJIntHandler(void);
extern void GPIOKIntHandler(void);
extern void GPIOLIntHandler(void);
extern void GPIOMIntHandler(void);
extern void GPIONIntHandler(void);
extern void GPIOPIntHandler(void);
extern void GPIOQIntHandler(void);
#ifdef TARGET_IS_SNOWFLAKE_RA0
extern void GPIORIntHandler(void);
extern void GPIOSIntHandler(void);
extern void GPIOTIntHandler(void);
#endif
extern void lwIPEthernetIntHandler(void) __attribute__((weak));
extern void SysTickIntHandler(void);

/*
 * create some overridable default signal handlers
 */
__attribute__((weak)) void UARTIntHandler(void) {}
__attribute__((weak)) void UARTIntHandler1(void) {}
__attribute__((weak)) void UARTIntHandler2(void) {}
__attribute__((weak)) void UARTIntHandler3(void) {}
__attribute__((weak)) void UARTIntHandler4(void) {}
__attribute__((weak)) void UARTIntHandler5(void) {}
__attribute__((weak)) void UARTIntHandler6(void) {}
__attribute__((weak)) void UARTIntHandler7(void) {}
__attribute__((weak)) void ToneIntHandler(void) {}
__attribute__((weak)) void I2CIntHandler(void) {}
__attribute__((weak)) void Timer5IntHandler(void) {}
//*****************************************************************************
// System stack start determined by ldscript, normally highest ram address
//*****************************************************************************
extern unsigned _estack;

//*****************************************************************************
//
// The vector table.  Note that the proper constructs must be placed on this to
// ensure that it ends up at physical address 0x0000.0000.
//
//*****************************************************************************

#ifdef TARGET_IS_BLIZZARD_RB1
__attribute__ ((section(".isr_vector")))
void (* const g_pfnVectors[])(void) =
{
   (void *)&_estack,                        // The initial stack pointer, 0x20008000 32K
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
    SysTickIntHandler,                      // The SysTick handler
    GPIOAIntHandler,                        // GPIO Port A
    GPIOBIntHandler,                        // GPIO Port B
    GPIOCIntHandler,                        // GPIO Port C
    GPIODIntHandler,                        // GPIO Port D
    GPIOEIntHandler,                        // GPIO Port E
    UARTIntHandler,                         // UART0 Rx and Tx
    UARTIntHandler1,                        // UART1 Rx and Tx
    IntDefaultHandler,                      // SSI0 Rx and Tx
    I2CIntHandler,                          // I2C0 Master and Slave
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
    GPIOFIntHandler,                        // GPIO Port F
    GPIOGIntHandler,                        // GPIO Port G
    GPIOHIntHandler,                        // GPIO Port H
    UARTIntHandler2,                        // UART2 Rx and Tx
    IntDefaultHandler,                      // SSI1 Rx and Tx
    IntDefaultHandler,                      // Timer 3 subtimer A
    IntDefaultHandler,                      // Timer 3 subtimer B
    I2CIntHandler,                          // I2C1 Master and Slave
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
    GPIOJIntHandler,                        // GPIO Port J
    GPIOKIntHandler,                        // GPIO Port K
    GPIOLIntHandler,                        // GPIO Port L
    IntDefaultHandler,                      // SSI2 Rx and Tx
    IntDefaultHandler,                      // SSI3 Rx and Tx
    UARTIntHandler3,                        // UART3 Rx and Tx
    UARTIntHandler4,                        // UART4 Rx and Tx
    UARTIntHandler5,                        // UART5 Rx and Tx
    UARTIntHandler6,                        // UART6 Rx and Tx
    UARTIntHandler7,                        // UART7 Rx and Tx
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    I2CIntHandler,                          // I2C2 Master and Slave
    I2CIntHandler,                          // I2C3 Master and Slave
    ToneIntHandler,                         // Timer 4 subtimer A
    IntDefaultHandler,                      // Timer 4 subtimer B
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    Timer5IntHandler,                       // Timer 5 subtimer A
    IntDefaultHandler,                      // Timer 5 subtimer B
    IntDefaultHandler,                      // Wide Timer 0 subtimer A
    IntDefaultHandler,                      // Wide Timer 0 subtimer B
    IntDefaultHandler,                      // Wide Timer 1 subtimer A
    IntDefaultHandler,                      // Wide Timer 1 subtimer B
    IntDefaultHandler,                      // Wide Timer 2 subtimer A
    IntDefaultHandler,                      // Wide Timer 2 subtimer B
    IntDefaultHandler,                      // Wide Timer 3 subtimer A
    IntDefaultHandler,                      // Wide Timer 3 subtimer B
    IntDefaultHandler,                      // Wide Timer 4 subtimer A
    IntDefaultHandler,                      // Wide Timer 4 subtimer B
    IntDefaultHandler,                      // Wide Timer 5 subtimer A
    IntDefaultHandler,                      // Wide Timer 5 subtimer B
    IntDefaultHandler,                      // FPU
    IntDefaultHandler,                      // PECI 0
    IntDefaultHandler,                      // LPC 0
    IntDefaultHandler,                      // I2C4 Master and Slave
    IntDefaultHandler,                      // I2C5 Master and Slave
    GPIOMIntHandler,                        // GPIO Port M
    GPIONIntHandler,                        // GPIO Port N
    IntDefaultHandler,                      // Quadrature Encoder 2
    IntDefaultHandler,                      // Fan 0
    0,                                      // Reserved
    GPIOPIntHandler,                        // GPIO Port P (Summary or P0)
    GPIOPIntHandler,                        // GPIO Port P1
    GPIOPIntHandler,                        // GPIO Port P2
    GPIOPIntHandler,                        // GPIO Port P3
    GPIOPIntHandler,                        // GPIO Port P4
    GPIOPIntHandler,                        // GPIO Port P5
    GPIOPIntHandler,                        // GPIO Port P6
    GPIOPIntHandler,                        // GPIO Port P7
    GPIOQIntHandler,                        // GPIO Port Q (Summary or Q0)
    GPIOQIntHandler,                        // GPIO Port Q1
    GPIOQIntHandler,                        // GPIO Port Q2
    GPIOQIntHandler,                        // GPIO Port Q3
    GPIOQIntHandler,                        // GPIO Port Q4
    GPIOQIntHandler,                        // GPIO Port Q5
    GPIOQIntHandler,                        // GPIO Port Q6
    GPIOQIntHandler,                        // GPIO Port Q7
    IntDefaultHandler,                      // GPIO Port R
    IntDefaultHandler,                      // GPIO Port S
    IntDefaultHandler,                      // PWM 1 Generator 0
    IntDefaultHandler,                      // PWM 1 Generator 1
    IntDefaultHandler,                      // PWM 1 Generator 2
    IntDefaultHandler,                      // PWM 1 Generator 3
    IntDefaultHandler                       // PWM 1 Fault
};
#else
__attribute__ ((section(".isr_vector")))
void (* const g_pfnVectors[])(void) =
{
    (void *)&_estack,                       // The initial stack pointer
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
    SysTickIntHandler,                      // The SysTick handler
    GPIOAIntHandler,                        // GPIO Port A
    GPIOBIntHandler,                        // GPIO Port B
    GPIOCIntHandler,                        // GPIO Port C
    GPIODIntHandler,                        // GPIO Port D
    GPIOEIntHandler,                        // GPIO Port E
    UARTIntHandler,                         // UART0 Rx and Tx
    UARTIntHandler1,                        // UART1 Rx and Tx
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
    GPIOFIntHandler,                        // GPIO Port F
    GPIOGIntHandler,                        // GPIO Port G
    GPIOHIntHandler,                        // GPIO Port H
    UARTIntHandler2,                        // UART2 Rx and Tx
    IntDefaultHandler,                      // SSI1 Rx and Tx
    IntDefaultHandler,                      // Timer 3 subtimer A
    IntDefaultHandler,                      // Timer 3 subtimer B
    IntDefaultHandler,                      // I2C1 Master and Slave
    IntDefaultHandler,                      // CAN0
    IntDefaultHandler,                      // CAN1
    lwIPEthernetIntHandler,                 // Ethernet
    IntDefaultHandler,                      // Hibernate
    IntDefaultHandler,                      // USB0
    IntDefaultHandler,                      // PWM Generator 3
    IntDefaultHandler,                      // uDMA Software Transfer
    IntDefaultHandler,                      // uDMA Error
    IntDefaultHandler,                      // ADC1 Sequence 0
    IntDefaultHandler,                      // ADC1 Sequence 1
    IntDefaultHandler,                      // ADC1 Sequence 2
    IntDefaultHandler,                      // ADC1 Sequence 3
    IntDefaultHandler,                      // External Bus Interface 0
    GPIOJIntHandler,                        // GPIO Port J
    GPIOKIntHandler,                        // GPIO Port K
    GPIOLIntHandler,                        // GPIO Port L
    IntDefaultHandler,                      // SSI2 Rx and Tx
    IntDefaultHandler,                      // SSI3 Rx and Tx
    UARTIntHandler3,                        // UART3 Rx and Tx
    UARTIntHandler4,                        // UART4 Rx and Tx
    UARTIntHandler5,                        // UART5 Rx and Tx
    UARTIntHandler6,                        // UART6 Rx and Tx
    UARTIntHandler7,                        // UART7 Rx and Tx
    IntDefaultHandler,                      // I2C2 Master and Slave
    IntDefaultHandler,                      // I2C3 Master and Slave
    ToneIntHandler,                         // Timer 4 subtimer A
    IntDefaultHandler,                      // Timer 4 subtimer B
    Timer5IntHandler,                       // Timer 5 subtimer A
    IntDefaultHandler,                      // Timer 5 subtimer B
    IntDefaultHandler,                      // FPU
    0,                                      // Reserved
    0,                                      // Reserved
    IntDefaultHandler,                      // I2C4 Master and Slave
    IntDefaultHandler,                      // I2C5 Master and Slave
    GPIOMIntHandler,                        // GPIO Port M
    GPIONIntHandler,                        // GPIO Port N
    0,                                      // Reserved
    IntDefaultHandler,                      // Tamper
    GPIOPIntHandler,                        // GPIO Port P (Summary or P0)
    GPIOPIntHandler,                        // GPIO Port P1
    GPIOPIntHandler,                        // GPIO Port P2
    GPIOPIntHandler,                        // GPIO Port P3
    GPIOPIntHandler,                        // GPIO Port P4
    GPIOPIntHandler,                        // GPIO Port P5
    GPIOPIntHandler,                        // GPIO Port P6
    GPIOPIntHandler,                        // GPIO Port P7
    GPIOQIntHandler,                        // GPIO Port Q (Summary or Q0)
    GPIOQIntHandler,                        // GPIO Port Q1
    GPIOQIntHandler,                        // GPIO Port Q2
    GPIOQIntHandler,                        // GPIO Port Q3
    GPIOQIntHandler,                        // GPIO Port Q4
    GPIOQIntHandler,                        // GPIO Port Q5
    GPIOQIntHandler,                        // GPIO Port Q6
    GPIOQIntHandler,                        // GPIO Port Q7
    GPIORIntHandler,                        // GPIO Port R
    GPIOSIntHandler,                        // GPIO Port S
    IntDefaultHandler,                      // SHA/MD5 0
    IntDefaultHandler,                      // AES 0
    IntDefaultHandler,                      // DES3DES 0
    IntDefaultHandler,                      // LCD Controller 0
    IntDefaultHandler,                      // Timer 6 subtimer A
    IntDefaultHandler,                      // Timer 6 subtimer B
    IntDefaultHandler,                      // Timer 7 subtimer A
    IntDefaultHandler,                      // Timer 7 subtimer B
    IntDefaultHandler,                      // I2C6 Master and Slave
    IntDefaultHandler,                      // I2C7 Master and Slave
    IntDefaultHandler,                      // HIM Scan Matrix Keyboard 0
    IntDefaultHandler,                      // One Wire 0
    IntDefaultHandler,                      // HIM PS/2 0
    IntDefaultHandler,                      // HIM LED Sequencer 0
    IntDefaultHandler,                      // HIM Consumer IR 0
    IntDefaultHandler,                      // I2C8 Master and Slave
    IntDefaultHandler,                      // I2C9 Master and Slave
    GPIOTIntHandler                         // GPIO Port T
};
#endif
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
extern void (*__preinit_array_start[])(void);
extern void (*__preinit_array_end[])(void);
extern void (*__init_array_start[])(void);
extern void (*__init_array_end[])(void);
extern void _init(void);


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
void ResetISR(void) {
    unsigned long *pulSrc, *pulDest;
    unsigned i, cnt;

    //
    // Copy the data segment initializers from flash to SRAM.
    //
    pulSrc = &_etext;
    for (pulDest = &_data; pulDest < &_edata;) {
        *pulDest++ = *pulSrc++;
    }

    //
    // Zero fill the bss segment.
    //
    __asm(  "    ldr     r0, =_bss\n"
            "    ldr     r1, =_ebss\n"
            "    mov     r2, #0\n"
            "    .thumb_func\n"
            "1:\n"
            "    cmp     r0, r1\n"
            "    it      lt\n"
            "    strlt   r2, [r0], #4\n"
            "    blt     1b"
    );
    (void)_bss; (void)_ebss; // get rid of unused warnings

    //
    // Enable the floating-point unit before calling c++ ctors
    //

    HWREG(NVIC_CPAC) = ((HWREG(NVIC_CPAC) &
                         ~(NVIC_CPAC_CP10_M | NVIC_CPAC_CP11_M)) |
                         NVIC_CPAC_CP10_FULL | NVIC_CPAC_CP11_FULL);

    //
    // call any global c++ ctors
    //
    cnt = __preinit_array_end - __preinit_array_start;
    for (i = 0; i < cnt; i++)
        __preinit_array_start[i]();

    _init();

    cnt = __init_array_end - __init_array_start;
    for (i = 0; i < cnt; i++)
        __init_array_start[i]();

    //
    // call 'C' entry point, Energia never returns from main
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
static void NmiSR(void) {
    //
    // Enter an infinite loop.
    //
    while (1) {
        ; // trap NMI
    }
}

//*****************************************************************************
//
// This is the code that gets called when the processor receives a fault
// interrupt.  This simply enters an infinite loop, preserving the system state
// for examination by a debugger.
//
//*****************************************************************************
static void FaultISR(void) {
    //
    // Enter an infinite loop.
    //
    while (1) {
        ; // trap FAULT
    }
}

//*****************************************************************************
//
// This is the code that gets called when the processor receives an unexpected
// interrupt.  This simply enters an infinite loop, preserving the system state
// for examination by a debugger.
//
//*****************************************************************************
static void IntDefaultHandler(void) {
    //
    // Go into an infinite loop.
    //
    while (1) {
        ; // trap any handler not defined
    }
}

/* syscall stuff */
void *__dso_handle = 0;

/**
 * _sbrk - newlib memory allocation routine
 */
typedef char *caddr_t;

caddr_t _sbrk (int incr)
{
    double current_sp;
    extern char end asm ("end"); /* Defined by linker */
    static char * heap_end;
    char * prev_heap_end;

    if (heap_end == NULL) {
        heap_end = &end; /* first ram address after bss and data */
    }

    prev_heap_end = heap_end;

    // simplistic approach to prevent the heap from corrupting the stack
    // TBD: review for alternatives
    if ( heap_end + incr < (caddr_t)&current_sp ) {
        heap_end += incr;
        return (caddr_t) prev_heap_end;
    }
    else {
        return NULL;
    }
}

extern int link( char *cOld, char *cNew )
{
    return -1 ;
}

extern int _close( int file )
{
    return -1 ;
}

extern int _fstat( int file, struct stat *st )
{
    st->st_mode = S_IFCHR ;

    return 0 ;
}

extern int _isatty( int file )
{
    return 1 ;
}

extern int _lseek( int file, int ptr, int dir )
{
    return 0 ;
}

extern int _read(int file, char *ptr, int len)
{
    return 0 ;
}

extern int _write( int file, char *ptr, int len )
{
    return len;
}

extern void _kill( int pid, int sig )
{
    return ;
}

extern int _getpid ( void )
{
    return -1 ;
}

/*
extern void _exit (void)
{

}
*/
