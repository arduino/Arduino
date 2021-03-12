/* Copyright (c) 2002, 2003, 2004, 2007 Marek Michalkiewicz
   Copyright (c) 2005, 2006 Bjoern Haase
   Copyright (c) 2008 Atmel Corporation
   Copyright (c) 2008 Wouter van Gulik
   Copyright (c) 2009 Dmitry Xmelkov
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

#ifndef _AVR_EEPROM_H_
#define _AVR_EEPROM_H_ 1

#include <avr/io.h>

#if !E2END && !defined(__DOXYGEN__) && !defined(__COMPILING_AVR_LIBC__)
# warning "Device does not have EEPROM available."
#else

#if defined (EEAR) && !defined (EEARL) && !defined (EEARH)
#define EEARL EEAR
#endif

#ifndef	__ASSEMBLER__

#include <stddef.h>	/* size_t */
#include <stdint.h>

/** \defgroup avr_eeprom <avr/eeprom.h>: EEPROM handling
    \code #include <avr/eeprom.h> \endcode

    This header file declares the interface to some simple library
    routines suitable for handling the data EEPROM contained in the
    AVR microcontrollers.  The implementation uses a simple polled
    mode interface.  Applications that require interrupt-controlled
    EEPROM access to ensure that no time will be wasted in spinloops
    will have to deploy their own implementation.

    \par Notes:

    - In addition to the write functions there is a set of update ones.
    This functions read each byte first and skip the burning if the
    old value is the same with new.  The scaning direction is from
    high address to low, to obtain quick return in common cases.

    - All of the read/write functions first make sure the EEPROM is
    ready to be accessed.  Since this may cause long delays if a
    write operation is still pending, time-critical applications
    should first poll the EEPROM e. g. using eeprom_is_ready() before
    attempting any actual I/O.  But this functions are not wait until
    SELFPRGEN in SPMCSR becomes zero.  Do this manually, if your
    softwate contains the Flash burning.

    - As these functions modify IO registers, they are known to be
    non-reentrant.  If any of these functions are used from both,
    standard and interrupt context, the applications must ensure
    proper protection (e.g. by disabling interrupts before accessing
    them).

    - All write functions force erase_and_write programming mode.
    
    - For Xmega the EEPROM start address is 0, like other architectures.
    The reading functions add the 0x2000 value to use EEPROM mapping into
    data space.
 */

#ifdef __cplusplus
extern "C" {
#endif

#ifndef	__ATTR_PURE__
# ifdef	 __DOXYGEN__
#  define __ATTR_PURE__
# else
#  define __ATTR_PURE__  __attribute__((__pure__))
# endif
#endif

/** \def EEMEM
    \ingroup avr_eeprom
    Attribute expression causing a variable to be allocated within the
    .eeprom section.	*/
#define EEMEM __attribute__((section(".eeprom")))

/** \def eeprom_is_ready
    \ingroup avr_eeprom
    \returns 1 if EEPROM is ready for a new read/write operation, 0 if not.
 */
#if	defined (__DOXYGEN__)
# define eeprom_is_ready()
#elif	defined (NVM_STATUS)
# define eeprom_is_ready()	bit_is_clear (NVM_STATUS, NVM_NVMBUSY_bp)
#elif	defined (NVMCTRL_STATUS)
# define eeprom_is_ready()	bit_is_clear (NVMCTRL_STATUS, NVMCTRL_EEBUSY_bp)
#elif	defined (DEECR)
# define eeprom_is_ready()	bit_is_clear (DEECR, BSY)
#elif	defined (EEPE)
# define eeprom_is_ready()	bit_is_clear (EECR, EEPE)
#else
# define eeprom_is_ready()	bit_is_clear (EECR, EEWE)
#endif


/** \def eeprom_busy_wait
    \ingroup avr_eeprom
    Loops until the eeprom is no longer busy.
    \returns Nothing.
 */ 	 
#define eeprom_busy_wait() do {} while (!eeprom_is_ready())


/** \ingroup avr_eeprom
    Read one byte from EEPROM address \a __p.
 */
uint8_t eeprom_read_byte (const uint8_t *__p) __ATTR_PURE__;

/** \ingroup avr_eeprom
    Read one 16-bit word (little endian) from EEPROM address \a __p.
 */
uint16_t eeprom_read_word (const uint16_t *__p) __ATTR_PURE__;

/** \ingroup avr_eeprom
    Read one 32-bit double word (little endian) from EEPROM address \a __p.
 */
uint32_t eeprom_read_dword (const uint32_t *__p) __ATTR_PURE__;

/** \ingroup avr_eeprom
    Read one float value (little endian) from EEPROM address \a __p.
 */
float eeprom_read_float (const float *__p) __ATTR_PURE__;

/** \ingroup avr_eeprom
    Read a block of \a __n bytes from EEPROM address \a __src to SRAM
    \a __dst.
 */
void eeprom_read_block (void *__dst, const void *__src, size_t __n);


/** \ingroup avr_eeprom
    Write a byte \a __value to EEPROM address \a __p.
 */
void eeprom_write_byte (uint8_t *__p, uint8_t __value);

/** \ingroup avr_eeprom
    Write a word \a __value to EEPROM address \a __p.
 */
void eeprom_write_word (uint16_t *__p, uint16_t __value);

/** \ingroup avr_eeprom
    Write a 32-bit double word \a __value to EEPROM address \a __p.
 */
void eeprom_write_dword (uint32_t *__p, uint32_t __value);

/** \ingroup avr_eeprom
    Write a float \a __value to EEPROM address \a __p.
 */
void eeprom_write_float (float *__p, float __value);

/** \ingroup avr_eeprom
    Write a block of \a __n bytes to EEPROM address \a __dst from \a __src.
    \note The argument order is mismatch with common functions like strcpy().
 */
void eeprom_write_block (const void *__src, void *__dst, size_t __n);


/** \ingroup avr_eeprom
    Update a byte \a __value to EEPROM address \a __p.
 */
void eeprom_update_byte (uint8_t *__p, uint8_t __value);

/** \ingroup avr_eeprom
    Update a word \a __value to EEPROM address \a __p.
 */
void eeprom_update_word (uint16_t *__p, uint16_t __value);

/** \ingroup avr_eeprom
    Update a 32-bit double word \a __value to EEPROM address \a __p.
 */
void eeprom_update_dword (uint32_t *__p, uint32_t __value);

/** \ingroup avr_eeprom
    Update a float \a __value to EEPROM address \a __p.
 */
void eeprom_update_float (float *__p, float __value);

/** \ingroup avr_eeprom
    Update a block of \a __n bytes to EEPROM address \a __dst from \a __src.
    \note The argument order is mismatch with common functions like strcpy().
 */
void eeprom_update_block (const void *__src, void *__dst, size_t __n);


/** \name IAR C compatibility defines	*/
/*@{*/

/** \def _EEPUT
    \ingroup avr_eeprom
    Write a byte to EEPROM. Compatibility define for IAR C.	*/
#define _EEPUT(addr, val) eeprom_write_byte ((uint8_t *)(addr), (uint8_t)(val))

/** \def __EEPUT
    \ingroup avr_eeprom
    Write a byte to EEPROM. Compatibility define for IAR C.	*/
#define __EEPUT(addr, val) eeprom_write_byte ((uint8_t *)(addr), (uint8_t)(val))

/** \def _EEGET
    \ingroup avr_eeprom
    Read a byte from EEPROM. Compatibility define for IAR C.	*/
#define _EEGET(var, addr) (var) = eeprom_read_byte ((const uint8_t *)(addr))

/** \def __EEGET
    \ingroup avr_eeprom
    Read a byte from EEPROM. Compatibility define for IAR C.	*/
#define __EEGET(var, addr) (var) = eeprom_read_byte ((const uint8_t *)(addr))

/*@}*/

#ifdef __cplusplus
}
#endif

#endif	/* !__ASSEMBLER__ */
#endif	/* E2END || defined(__DOXYGEN__) || defined(__COMPILING_AVR_LIBC__) */
#endif	/* !_AVR_EEPROM_H_ */
