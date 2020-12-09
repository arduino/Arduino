/* Copyright (c) 2012 Joerg Wunsch
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

/*
 * This file is included by <avr/io.h> whenever compiling for an Xmega
 * device.  It abstracts certain features common to the Xmega device
 * families.
 */

#ifndef _AVR_XMEGA_H
#define _AVR_XMEGA_H

#ifdef __DOXYGEN__
/**
 \def _PROTECTED_WRITE
 \ingroup avr_io

 Write value \c value to IO register \c reg that is protected through
 the Xmega configuration change protection (CCP) mechanism.  This
 implements the timed sequence that is required for CCP.

 Example to modify the CPU clock:
 \code
 #include <avr/io.h>

 _PROTECTED_WRITE(CLK_PSCTRL, CLK_PSADIV0_bm);
 _PROTECTED_WRITE(CLK_CTRL, CLK_SCLKSEL0_bm);
 \endcode
 */
#define _PROTECTED_WRITE(reg, value)

/**
 \def _PROTECTED_WRITE_SPM
 \ingroup avr_io

 Write value \c value to register \c reg that is protected through
 the Xmega configuration change protection (CCP) key for self
 programming (SPM).  This implements the timed sequence that is
 required for CCP.

 Example to modify the CPU clock:
 \code
 #include <avr/io.h>

 _PROTECTED_WRITE_SPM(NVMCTRL_CTRLA, NVMCTRL_CMD_PAGEERASEWRITE_gc);
 \endcode
 */
#define _PROTECTED_WRITE_SPM(reg, value)

#else  /* !__DOXYGEN__ */

#define _PROTECTED_WRITE(reg, value)				\
  __asm__ __volatile__("out %[ccp], %[ccp_ioreg]" "\n\t"	\
		       "sts %[ioreg], %[val]"			\
		       :					\
		       : [ccp] "I" (_SFR_IO_ADDR(CCP)),		\
			 [ccp_ioreg] "d" ((uint8_t)CCP_IOREG_gc),	\
			 [ioreg] "n" (_SFR_MEM_ADDR(reg)),	\
			 [val] "r" ((uint8_t)value))

#define _PROTECTED_WRITE_SPM(reg, value) \
  __asm__ __volatile__("out %[ccp], %[ccp_spm_mask]" "\n\t" \
                       "sts %[ioreg], %[val]"               \
                       :                                    \
                       : [ccp]          "I" (_SFR_IO_ADDR(CCP)), \
                         [ccp_spm_mask] "d" ((uint8_t)CCP_SPM_gc), \
                         [ioreg]        "n" (_SFR_MEM_ADDR(reg)), \
                         [val]          "r" ((uint8_t)value))
#endif /* DOXYGEN */

#endif /* _AVR_XMEGA_H */
