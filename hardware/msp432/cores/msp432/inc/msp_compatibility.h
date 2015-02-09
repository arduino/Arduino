//*****************************************************************************
//
// Copyright (C) 2013 - 2014 Texas Instruments Incorporated - http://www.ti.com/
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
//
//  Redistributions of source code must retain the above copyright
//  notice, this list of conditions and the following disclaimer.
//
//  Redistributions in binary form must reproduce the above copyright
//  notice, this list of conditions and the following disclaimer in the
//  documentation and/or other materials provided with the
//  distribution.
//
//  Neither the name of Texas Instruments Incorporated nor the names of
//  its contributors may be used to endorse or promote products derived
//  from this software without specific prior written permission.
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
// MSP430 intrinsic redefinitions for use with MSP432 Family Devices
//
//****************************************************************************

// Intrinsics with ARM equivalents
#if defined ( __TMS470__ ) /* TI CGT Compiler */

#include <cmsis_ccs.h>

#define __sleep()                       __wfi()
#define __deep_sleep()                  { (*((volatile uint32_t *)(0xE000ED10))) |= 0x00000004; __wfi(); (*((volatile uint32_t *)(0xE000ED10))) &= ~0x00000004; }
#define __low_power_mode_off_on_exit()  { (*((volatile uint32_t *)(0xE000ED10))) &= ~0x00000002; }
#define __get_SP_register()             __get_MSP()
#define __set_SP_register(x)            __set_MSP(x)
#define __get_interrupt_state()         __get_PRIMASK()
#define __set_interrupt_state(x)        __set_PRIMASK(x)
#define __enable_interrupt()            _enable_interrupts()
#define __enable_interrupts()           _enable_interrupts()
#define __disable_interrupt()           _disable_interrupts()
#define __disable_interrupts()          _disable_interrupts()
#define __no_operation()                __asm("  nop")

#elif defined ( __ICCARM__ )  /* IAR Compiler */

#include <stdint.h>

#define __INLINE                        inline
#include <cmsis_iar.h>

#define __sleep()                       __WFI()
#define __deep_sleep()                  { (*((volatile uint32_t *)(0xE000ED10))) |= 0x00000004; __WFI(); (*((volatile uint32_t *)(0xE000ED10))) &= ~0x00000004; }
#define __low_power_mode_off_on_exit()  { (*((volatile uint32_t *)(0xE000ED10))) &= ~0x00000002; }
#define __get_SP_register()             __get_MSP()
#define __set_SP_register()             __set_MSP()
#define __get_interrupt_state()         __get_PRIMASK()
#define __set_interrupt_state(x)        __set_PRIMASK(x)
#define __enable_interrupt()            __asm("  cpsie i")
#define __enable_interrupts()           __asm("  cpsie i")
#define __disable_interrupt()           __asm("  cpsid i")
#define __disable_interrupts()          __asm("  cpsid i")
#define __no_operation()                __asm("  nop")

// Intrinsics without ARM equivalents
#define __bcd_add_short(x,y)            { while(1); /* Using not-supported MSP430 intrinsic. No replacement available. */ }
#define __bcd_add_long(x,y)             { while(1); /* Using not-supported MSP430 intrinsic. No replacement available. */ }
#define __bcd_add_long_long(x,y)        { while(1); /* Using not-supported MSP430 intrinsic. No replacement available. */ }
#define __even_in_range(x,y)            { while(1); /* Using not-supported MSP430 intrinsic. No replacement available. */ }
#define __data20_write_char(x,y)        { while(1); /* Using not-supported MSP430 intrinsic. No replacement available. */ }
#define __data20_write_short(x,y)       { while(1); /* Using not-supported MSP430 intrinsic. No replacement available. */ }
#define __data20_write_long(x,y)        { while(1); /* Using not-supported MSP430 intrinsic. No replacement available. */ }
#define __never_executed()              { while(1); /* Using not-supported MSP430 intrinsic. No replacement available. */ }
#define __op_code()                     { while(1); /* Using not-supported MSP430 intrinsic. No replacement available. */ }
#define __code_distance()               { while(1); /* Using not-supported MSP430 intrinsic. No replacement available. */ }
#define __bic_SR_register(x)            { while(1); /* Using not-supported MSP430 intrinsic. No replacement available. */ }
#define __bis_SR_register(x)            { while(1); /* Using not-supported MSP430 intrinsic. No replacement available. */ }
#define __bis_SR_register_on_exit(x)    { while(1); /* Using not-supported MSP430 intrinsic. Recommended to write to SCS_SCR register. */ }
#define __bic_SR_register_on_exit(x)    { while(1); /* Using not-supported MSP430 intrinsic. Recommended to write to SCS_SCR register. */ }

#elif defined ( __CC_ARM ) /* ARM Compiler */

#define __sleep()                       __wfi
#define __deep_sleep()                  { (*((volatile uint32_t *)(0xE000ED10))) |= 0x00000004; __wfi(); (*((volatile uint32_t *)(0xE000ED10))) &= ~0x00000004; }
#define __low_power_mode_off_on_exit()  { (*((volatile uint32_t *)(0xE000ED10))) &= ~0x00000002; }
#define __get_SP_register()             __get_MSP()
#define __set_SP_register(x)            __set_MSP(x)
#define __get_interrupt_state()         __get_PRIMASK()
#define __set_interrupt_state(x)        __set_PRIMASK(x)
#define __enable_interrupt()            __asm("  cpsie i")
#define __enable_interrupts()           __asm("  cpsie i")
#define __disable_interrupt()           __asm("  cpsid i")
#define __disable_interrupts()          __asm("  cpsid i")
#define __no_operation()                __asm("  nop")

// Intrinsics without ARM equivalents
#define __bcd_add_short(x,y)            { while(1); /* Using not-supported MSP430 intrinsic. No replacement available. */ }
#define __bcd_add_long(x,y)             { while(1); /* Using not-supported MSP430 intrinsic. No replacement available. */ }
#define __bcd_add_long_long(x,y)        { while(1); /* Using not-supported MSP430 intrinsic. No replacement available. */ }
#define __even_in_range(x,y)            { while(1); /* Using not-supported MSP430 intrinsic. No replacement available. */ }
#define __data20_write_char(x,y)        { while(1); /* Using not-supported MSP430 intrinsic. No replacement available. */ }
#define __data20_write_short(x,y)       { while(1); /* Using not-supported MSP430 intrinsic. No replacement available. */ }
#define __data20_write_long(x,y)        { while(1); /* Using not-supported MSP430 intrinsic. No replacement available. */ }
#define __never_executed()              { while(1); /* Using not-supported MSP430 intrinsic. No replacement available. */ }
#define __op_code()                     { while(1); /* Using not-supported MSP430 intrinsic. No replacement available. */ }
#define __code_distance()               { while(1); /* Using not-supported MSP430 intrinsic. No replacement available. */ }
#define __bic_SR_register(x)            { while(1); /* Using not-supported MSP430 intrinsic. No replacement available. */ }
#define __bis_SR_register(x)            { while(1); /* Using not-supported MSP430 intrinsic. No replacement available. */ }
#define __bis_SR_register_on_exit(x)    { while(1); /* Using not-supported MSP430 intrinsic. Recommended to write to SCS_SCR register. */ }
#define __bic_SR_register_on_exit(x)    { while(1); /* Using not-supported MSP430 intrinsic. Recommended to write to SCS_SCR register. */ }

#elif defined ( __GNUC__ ) /* GCC Compiler */

#define __sleep()                       __wfi()
#define __deep_sleep()                  { (*((volatile uint32_t *)(0xE000ED10))) |= 0x00000004; __wfi(); (*((volatile uint32_t *)(0xE000ED10))) &= ~0x00000004; }
#define __low_power_mode_off_on_exit()  { (*((volatile uint32_t *)(0xE000ED10))) &= ~0x00000002; }
#define __get_SP_register()             __get_MSP()
#define __set_SP_register(x)            __set_MSP(x)
#define __get_interrupt_state()         __get_PRIMASK()
#define __set_interrupt_state(x)        __set_PRIMASK(x)
#define __enable_interrupt()            __asm("  cpsie i")
#define __enable_interrupts()           __asm("  cpsie i")
#define __disable_interrupt()           __asm("  cpsid i")
#define __disable_interrupts()          __asm("  cpsid i")
#define __no_operation()                __asm("  nop")

// Intrinsics without ARM equivalents
#define __bcd_add_short(x,y)            { while(1); /* Using not-supported MSP430 intrinsic. No replacement available. */ }
#define __bcd_add_long(x,y)             { while(1); /* Using not-supported MSP430 intrinsic. No replacement available. */ }
#define __bcd_add_long_long(x,y)        { while(1); /* Using not-supported MSP430 intrinsic. No replacement available. */ }
#define __even_in_range(x,y)            { while(1); /* Using not-supported MSP430 intrinsic. No replacement available. */ }
#define __data20_write_char(x,y)        { while(1); /* Using not-supported MSP430 intrinsic. No replacement available. */ }
#define __data20_write_short(x,y)       { while(1); /* Using not-supported MSP430 intrinsic. No replacement available. */ }
#define __data20_write_long(x,y)        { while(1); /* Using not-supported MSP430 intrinsic. No replacement available. */ }
#define __never_executed()              { while(1); /* Using not-supported MSP430 intrinsic. No replacement available. */ }
#define __op_code()                     { while(1); /* Using not-supported MSP430 intrinsic. No replacement available. */ }
#define __code_distance()               { while(1); /* Using not-supported MSP430 intrinsic. No replacement available. */ }
#define __bic_SR_register(x)            { while(1); /* Using not-supported MSP430 intrinsic. No replacement available. */ }
#define __bis_SR_register(x)            { while(1); /* Using not-supported MSP430 intrinsic. No replacement available. */ }
#define __bis_SR_register_on_exit(x)    { while(1); /* Using not-supported MSP430 intrinsic. Recommended to write to SCS_SCR register. */ }
#define __bic_SR_register_on_exit(x)    { while(1); /* Using not-supported MSP430 intrinsic. Recommended to write to SCS_SCR register. */ }

#endif

// Intrinsics without ARM equivalents
#define __low_power_mode_0()            { __sleep(); }
#define __low_power_mode_1()            { __sleep(); }
#define __low_power_mode_2()            { __sleep(); }
#define __low_power_mode_3()            { __deep_sleep(); }
#define __low_power_mode_4()            { __deep_sleep(); }
#define __data16_read_addr(x)           (*((volatile uint32_t *)(x)))
#define __data20_read_char(x)           (*((volatile uint8_t *)(x)))
#define __data20_read_short(x)          (*((volatile uint16_t *)(x)))
#define __data20_read_long(x)           (*((volatile uint32_t *)(x)))
#define __data16_write_addr(x,y)        { (*((volatile uint32_t *)(x))) }
#define __get_SR_register()             0
#define __get_SR_register_on_exit()     0
