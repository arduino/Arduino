/* Copyright (c) 2009, Atmel Corporation
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

/* avr/signature.h - Signature API */

#ifndef _AVR_SIGNATURE_H_
#define _AVR_SIGNATURE_H_ 1

/** \file */
/** \defgroup avr_signature <avr/signature.h>: Signature Support

    \par Introduction

    The <avr/signature.h> header file allows the user to automatically
    and easily include the device's signature data in a special section of
    the final linked ELF file.
    
    This value can then be used by programming software to compare the on-device
    signature with the signature recorded in the ELF file to look for a match
    before programming the device.
    
    \par API Usage Example

    Usage is very simple; just include the header file:
    
    \code
    #include <avr/signature.h>
    \endcode
    
    This will declare a constant unsigned char array and it is initialized with
    the three signature bytes, MSB first, that are defined in the device I/O
    header file. This array is then placed in the .signature section in the
    resulting linked ELF file.
    
    The three signature bytes that are used to initialize the array are 
    these defined macros in the device I/O header file, from MSB to LSB:
    SIGNATURE_2, SIGNATURE_1, SIGNATURE_0.
    
    This header file should only be included once in an application.
*/

#ifndef __ASSEMBLER__

#include <avr/io.h>

#if defined(SIGNATURE_0) && defined(SIGNATURE_1) && defined(SIGNATURE_2)

const unsigned char __signature[3]
__attribute__((__used__, __section__(".signature"))) =
        { SIGNATURE_2, SIGNATURE_1, SIGNATURE_0 };

#endif  /* defined(SIGNATURE_0) && defined(SIGNATURE_1) && defined(SIGNATURE_2) */

#endif  /* __ASSEMBLER__ */

#endif  /* _AVR_SIGNATURE_H_ */
