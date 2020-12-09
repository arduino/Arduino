/* Copyright (c) 2002, Marek Michalkiewicz
   Copyright (c) 2004,2005,2007 Joerg Wunsch
   Copyright (c) 2007  Florin-Viorel Petrov
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.

   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in
     the documentation and/or other materials provided with the
     distribution.

   * Neither the name of the copyright holders nor the names of
     contributors may be used to endorse or promote products derived
     from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE. */

/* $Id$ */

#ifndef _UTIL_DELAY_H_
#define _UTIL_DELAY_H_ 1

#ifndef __DOXYGEN__
#  ifndef __HAS_DELAY_CYCLES
#    define __HAS_DELAY_CYCLES 1
#  endif
#endif  /* __DOXYGEN__ */

#include <inttypes.h>
#include <util/delay_basic.h>
#include <math.h>

/** \file */
/** \defgroup util_delay <util/delay.h>: Convenience functions for busy-wait delay loops
    \code
    #define F_CPU 1000000UL  // 1 MHz
    //#define F_CPU 14.7456E6
    #include <util/delay.h>
    \endcode

    \note As an alternative method, it is possible to pass the
    F_CPU macro down to the compiler from the Makefile.
    Obviously, in that case, no \c \#define statement should be
    used.

    The functions in this header file are wrappers around the basic
    busy-wait functions from <util/delay_basic.h>.  They are meant as
    convenience functions where actual time values can be specified
    rather than a number of cycles to wait for.  The idea behind is
    that compile-time constant expressions will be eliminated by
    compiler optimization so floating-point expressions can be used
    to calculate the number of delay cycles needed based on the CPU
    frequency passed by the macro F_CPU.

    \note In order for these functions to work as intended, compiler
    optimizations <em>must</em> be enabled, and the delay time
    <em>must</em> be an expression that is a known constant at
    compile-time.  If these requirements are not met, the resulting
    delay will be much longer (and basically unpredictable), and
    applications that otherwise do not use floating-point calculations
    will experience severe code bloat by the floating-point library
    routines linked into the application.

    The functions available allow the specification of microsecond, and
    millisecond delays directly, using the application-supplied macro
    F_CPU as the CPU clock frequency (in Hertz).

*/

#if !defined(__DOXYGEN__)
static __inline__ void _delay_us(double __us) __attribute__((__always_inline__));
static __inline__ void _delay_ms(double __ms) __attribute__((__always_inline__));
#endif

#ifndef F_CPU
/* prevent compiler error by supplying a default */
# warning "F_CPU not defined for <util/delay.h>"
/** \ingroup util_delay
    \def F_CPU
    \brief CPU frequency in Hz

    The macro F_CPU specifies the CPU frequency to be considered by
    the delay macros.  This macro is normally supplied by the
    environment (e.g. from within a project header, or the project's
    Makefile).  The value 1 MHz here is only provided as a "vanilla"
    fallback if no such user-provided definition could be found.

    In terms of the delay functions, the CPU frequency can be given as
    a floating-point constant (e.g. 3.6864E6 for 3.6864 MHz).
    However, the macros in <util/setbaud.h> require it to be an
    integer value.
 */
# define F_CPU 1000000UL
#endif

#ifndef __OPTIMIZE__
# warning "Compiler optimizations disabled; functions from <util/delay.h> won't work as designed"
#endif

#if __HAS_DELAY_CYCLES && defined(__OPTIMIZE__) && \
  !defined(__DELAY_BACKWARD_COMPATIBLE__) &&	   \
  __STDC_HOSTED__
#  include <math.h>
#endif

/**
   \ingroup util_delay

   Perform a delay of \c __ms milliseconds, using _delay_loop_2().

   The macro F_CPU is supposed to be defined to a
   constant defining the CPU clock frequency (in Hertz).

   The maximal possible delay is 262.14 ms / F_CPU in MHz.

   When the user request delay which exceed the maximum possible one,
   _delay_ms() provides a decreased resolution functionality. In this
   mode _delay_ms() will work with a resolution of 1/10 ms, providing
   delays up to 6.5535 seconds (independent from CPU frequency).  The
   user will not be informed about decreased resolution.

   If the avr-gcc toolchain has __builtin_avr_delay_cycles()
   support, maximal possible delay is 4294967.295 ms/ F_CPU in MHz. For
   values greater than the maximal possible delay, overflows results in
   no delay i.e., 0ms.

   Conversion of \c __ms into clock cycles may not always result in
   integer.  By default, the clock cycles rounded up to next
   integer. This ensures that the user gets at least \c __ms
   microseconds of delay.

   Alternatively, by defining the macro \c __DELAY_ROUND_DOWN__, or
   \c __DELAY_ROUND_CLOSEST__, before including this header file, the
   algorithm can be made to round down, or round to closest integer,
   respectively.

   \note

   The implementation of _delay_ms() based on
   __builtin_avr_delay_cycles() is not backward compatible with older
   implementations.  In order to get functionality backward compatible
   with previous versions, the macro \c "__DELAY_BACKWARD_COMPATIBLE__"
   must be defined before including this header file. Also, the
   backward compatible algorithm will be chosen if the code is
   compiled in a <em>freestanding environment</em> (GCC option
   \c -ffreestanding), as the math functions required for rounding are
   not available to the compiler then.

 */
void
_delay_ms(double __ms)
{
	double __tmp ;
#if __HAS_DELAY_CYCLES && defined(__OPTIMIZE__) && \
  !defined(__DELAY_BACKWARD_COMPATIBLE__) &&	   \
  __STDC_HOSTED__
	uint32_t __ticks_dc;
	extern void __builtin_avr_delay_cycles(unsigned long);
	__tmp = ((F_CPU) / 1e3) * __ms;

	#if defined(__DELAY_ROUND_DOWN__)
		__ticks_dc = (uint32_t)fabs(__tmp);

	#elif defined(__DELAY_ROUND_CLOSEST__)
		__ticks_dc = (uint32_t)(fabs(__tmp)+0.5);

	#else
		//round up by default
		__ticks_dc = (uint32_t)(ceil(fabs(__tmp)));
	#endif

	__builtin_avr_delay_cycles(__ticks_dc);

#else
	uint16_t __ticks;
	__tmp = ((F_CPU) / 4e3) * __ms;
	if (__tmp < 1.0)
		__ticks = 1;
	else if (__tmp > 65535)
	{
		//	__ticks = requested delay in 1/10 ms
		__ticks = (uint16_t) (__ms * 10.0);
		while(__ticks)
		{
			// wait 1/10 ms
			_delay_loop_2(((F_CPU) / 4e3) / 10);
			__ticks --;
		}
		return;
	}
	else
		__ticks = (uint16_t)__tmp;
	_delay_loop_2(__ticks);
#endif
}

/**
   \ingroup util_delay

   Perform a delay of \c __us microseconds, using _delay_loop_1().

   The macro F_CPU is supposed to be defined to a
   constant defining the CPU clock frequency (in Hertz).

   The maximal possible delay is 768 us / F_CPU in MHz.

   If the user requests a delay greater than the maximal possible one,
   _delay_us() will automatically call _delay_ms() instead.  The user
   will not be informed about this case.

   If the avr-gcc toolchain has __builtin_avr_delay_cycles()
   support, maximal possible delay is 4294967.295 us/ F_CPU in MHz. For
   values greater than the maximal possible delay, overflow results in
   no delay i.e., 0us.

   Conversion of \c __us into clock cycles may not always result in
   integer.  By default, the clock cycles rounded up to next
   integer. This ensures that the user gets at least \c __us
   microseconds of delay.

   Alternatively, by defining the macro \c __DELAY_ROUND_DOWN__, or
   \c __DELAY_ROUND_CLOSEST__, before including this header file, the
   algorithm can be made to round down, or round to closest integer,
   respectively.

   \note

   The implementation of _delay_ms() based on
   __builtin_avr_delay_cycles() is not backward compatible with older
   implementations.  In order to get functionality backward compatible
   with previous versions, the macro \c __DELAY_BACKWARD_COMPATIBLE__
   must be defined before including this header file. Also, the
   backward compatible algorithm will be chosen if the code is
   compiled in a <em>freestanding environment</em> (GCC option
   \c -ffreestanding), as the math functions required for rounding are
   not available to the compiler then.

 */
void
_delay_us(double __us)
{
	double __tmp ;
#if __HAS_DELAY_CYCLES && defined(__OPTIMIZE__) && \
  !defined(__DELAY_BACKWARD_COMPATIBLE__) &&	   \
  __STDC_HOSTED__
	uint32_t __ticks_dc;
	extern void __builtin_avr_delay_cycles(unsigned long);
	__tmp = ((F_CPU) / 1e6) * __us;

	#if defined(__DELAY_ROUND_DOWN__)
		__ticks_dc = (uint32_t)fabs(__tmp);

	#elif defined(__DELAY_ROUND_CLOSEST__)
		__ticks_dc = (uint32_t)(fabs(__tmp)+0.5);

	#else
		//round up by default
		__ticks_dc = (uint32_t)(ceil(fabs(__tmp)));
	#endif

	__builtin_avr_delay_cycles(__ticks_dc);

#else
	uint8_t __ticks;
	double __tmp2 ;
	__tmp = ((F_CPU) / 3e6) * __us;
	__tmp2 = ((F_CPU) / 4e6) * __us;
	if (__tmp < 1.0)
		__ticks = 1;
	else if (__tmp2 > 65535)
	{
		_delay_ms(__us / 1000.0);
	}
	else if (__tmp > 255)
	{
		uint16_t __ticks=(uint16_t)__tmp2;
		_delay_loop_2(__ticks);
		return;
	}
	else
		__ticks = (uint8_t)__tmp;
	_delay_loop_1(__ticks);
#endif
}


#endif /* _UTIL_DELAY_H_ */
