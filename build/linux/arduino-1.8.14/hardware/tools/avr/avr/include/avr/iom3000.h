/* Copyright (c) 2010, Atmel Corporation
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

/* avr/iom3000.h - definitions for M3000 from Intelligent Motion Systems . */

/* This file should only be included from <avr/io.h>, never directly. */

#ifndef _AVR_IO_H_
#  error "Include <avr/io.h> instead of this file."
#endif

#ifndef _AVR_IOXXX_H_
#  define _AVR_IOXXX_H_ "iom3000.h"
#else
#  error "Attempt to include more than one <avr/ioXXX.h> file."
#endif 


#ifndef _AVR_IOM3000_H_
#define _AVR_IOM3000_H_ 1

/* Registers and associated bit numbers */

#define IPD _SFR_IO16(0x00)
#define IPDL _SFR_IO8(0x00)
#define IPDH _SFR_IO8(0x01)
#define IPA _SFR_IO16(0x02)
#define IPAL _SFR_IO8(0x02)
#define IPAH _SFR_IO8(0x03)
#define IPCR _SFR_IO8(0x04)
#define ADRSLT _SFR_IO16(0x05)
#define ADRSLTL _SFR_IO8(0x05)  /* Alias. */
#define ADRSLTH _SFR_IO8(0x06)  /* Alias. */
#define ADRSLTLO _SFR_IO8(0x05) /* Name according to datasheet. */
#define ADRSLTHI _SFR_IO8(0x06) /* Name according to datasheet. */
#define ADCSR _SFR_IO8(0x07)
#define AMUXCTL _SFR_IO8(0x0B)
#define MSPCR _SFR_IO8(0x0C)
#define USPCR _SFR_IO8(0x0C)
#define MSPSR _SFR_IO8(0x0D)
#define USPSR _SFR_IO8(0x0D)
#define MSPDR _SFR_IO8(0x0E)
#define USPDR _SFR_IO8(0x0E)
#define WDTCR _SFR_IO8(0x0F)
#define USR _SFR_IO8(0x11)
#define UCRA _SFR_IO8(0x12)
#define UCRB _SFR_IO8(0x13)
#define UBRR _SFR_IO8(0x14)
#define UBRRL _SFR_IO8(0x14)  /* Alias. */
#define UBRRH _SFR_IO8(0x15)  /* Alias. */
#define UBRRLO _SFR_IO8(0x14) /* Name according to datasheet. */
#define UBRRHI _SFR_IO8(0x15) /* Name according to datasheet. */
#define GIFR _SFR_IO8(0x16) 
#define GIMSK _SFR_IO8(0x17)
#define DACVAL _SFR_IO16(0x18)
#define DACVALL _SFR_IO8(0x18)  /* Alias. */
#define DACVALH _SFR_IO8(0x19)  /* Alias. */
#define DACVALLO _SFR_IO8(0x18) /* Name according to datasheet. */
#define DACVALHI _SFR_IO8(0x19) /* Name according to datasheet. */
#define BGPPIN _SFR_IO8(0x1A)
#define BGPDDR _SFR_IO8(0x1B)
#define BGPPORT _SFR_IO8(0x1C)
#define AGPPIN _SFR_IO8(0x1D)
#define AGPDDR _SFR_IO8(0x1E)
#define AGPPORT _SFR_IO8(0x1F)
#define EXTCCR1A _SFR_IO8(0x20)
#define EXTCCR1B _SFR_IO8(0x21)
#define EXTCNT1 _SFR_IO16(0x22)
#define EXTCNT1L _SFR_IO8(0x22)
#define EXTCNT1H _SFR_IO8(0x23)
#define EXOCR1A _SFR_IO16(0x24)
#define EXOCR1AL _SFR_IO8(0x24)
#define EXOCR1AH _SFR_IO8(0x25)
#define EXOCR1B _SFR_IO16(0x26)
#define EXOCR1BL _SFR_IO8(0x26)
#define EXOCR1BH _SFR_IO8(0x27)
#define EXTIFR _SFR_IO8(0x2A)
#define EXTIMSK _SFR_IO8(0x2B)
#define EXTCNT _SFR_IO8(0x2C)
#define EXTCCR0 _SFR_IO8(0x2D)
#define CGPPIN _SFR_IO8(0x30)
#define CGPDDR _SFR_IO8(0x31)
#define CGPPORT _SFR_IO8(0x32)
#define MCSR _SFR_IO8(0x33)


#define CDIVCAN _SFR_MEM8(0x100)
#define CBTR1 _SFR_MEM8(0x101)
#define CBTR2 _SFR_MEM8(0x102)
#define CBTR3 _SFR_MEM8(0x103)
#define CMCR _SFR_MEM8(0x104)
#define CRAFEN _SFR_MEM8(0x105)
#define CTARR _SFR_MEM8(0x106)
#define CIER _SFR_MEM8(0x107)
#define CCFLG _SFR_MEM8(0x108)
#define CCISR _SFR_MEM8(0x109)
#define CIDAH0 _SFR_MEM8(0x10A)
#define CIDAH1 _SFR_MEM8(0x10B)
#define CEFR _SFR_MEM8(0x10C)
#define CRXERR _SFR_MEM8(0x10D)
#define CTXERR _SFR_MEM8(0x10E)
#define CVER _SFR_MEM8(0x10F)
#define CIDAC0R _SFR_MEM32(0x110)
#define CIDM0R _SFR_MEM32(0x114)
#define CIDAC1R _SFR_MEM32(0x118)
#define CIDM1R _SFR_MEM32(0x11C)
#define CIDAC2R _SFR_MEM32(0x120)
#define CIDM2R _SFR_MEM32(0x124)
#define CIDAC3R _SFR_MEM32(0x128)
#define CIDM3R _SFR_MEM32(0x12C)
#define CIDAC4R _SFR_MEM32(0x130)
#define CIDM4R _SFR_MEM32(0x134)
#define CIDAC5R _SFR_MEM32(0x138)
#define CIDM5R _SFR_MEM32(0x13C)
#define CIDAC6R _SFR_MEM32(0x140)
#define CIDM6R _SFR_MEM32(0x144)
#define CTXB0 ((volatile uint8_t [16])(0x150))
#define CTXB1 ((volatile uint8_t [16])(0x160))
#define CTXB2 ((volatile uint8_t [16])(0x170))
#define CRXB0 ((volatile uint8_t [16])(0x180))
#define CRXB1 ((volatile uint8_t [16])(0x190))
#define PWMMSK _SFR_MEM8(0x200)
#define PWMPER _SFR_MEM8(0x201)
#define PWMSFRQ _SFR_MEM8(0x202)
#define PWMCTL _SFR_MEM8(0x203)
#define CURIRUN _SFR_MEM8(0x204)
#define CURIRED _SFR_MEM8(0x205)
#define CURRDLY _SFR_MEM16(0x206)
#define VELLOW1 _SFR_MEM8(0x208)
#define VELLOW2 _SFR_MEM8(0x209)
#define VELLOW3 _SFR_MEM8(0x20A)
#define VELHI1 _SFR_MEM8(0x20B)
#define VELHI2 _SFR_MEM8(0x20C)
#define VELHI3 _SFR_MEM8(0x20D)
#define VELDEC1 _SFR_MEM8(0x20E)
#define VELDEC2 _SFR_MEM8(0x20F)
#define VELDEC3 _SFR_MEM8(0x210)
#define VELACC1 _SFR_MEM8(0x211)
#define VELACC2 _SFR_MEM8(0x212)
#define VELACC3 _SFR_MEM8(0x213)
#define VELCVEL _SFR_MEM8(0x214)
/*
#define VELCVEL _SFR_MEM8(0x215)
#define VELCVEL _SFR_MEM8(0x216)
*/
#define VELTVEL _SFR_MEM8(0x217)
/*
#define VELTVEL _SFR_MEM8(0x218)
#define VELTVEL _SFR_MEM8(0x219)
*/
#define VELVGCTL _SFR_MEM8(0x21A)
#define VELSTB _SFR_MEM8(0x21B)
#define VELIFLG _SFR_MEM8(0x21C)
#define VELIMSK _SFR_MEM8(0x21D)
#define IDXTRT _SFR_MEM32(0x21E)
#define IDXENT _SFR_MEM32(0x222)
#define IDXMSDT _SFR_MEM16(0x226)
#define IDXPOT _SFR_MEM32(0x228)
#define IDXPOS _SFR_MEM32(0x22C)
#define IDXENC _SFR_MEM32(0x230)
#define IDXCTRL _SFR_MEM8(0x234)
#define IDXSTRB _SFR_MEM8(0x235)
#define IDXCPTP _SFR_MEM32(0x236)
#define IDXIFLG _SFR_MEM8(0x23A)
#define IDXIMSK _SFR_MEM8(0x23B)
#define SCIO _SFR_MEM8(0x23C)
#define SCSW _SFR_MEM8(0x23D)
#define SCRF _SFR_MEM32(0x23E)
#define IOF _SFR_MEM8(0x242)
#define MSELR _SFR_MEM8(0x243)
#define STAT _SFR_MEM8(0x244)
#define SPWMCTL _SFR_MEM8(0x245)
#define SINDAC _SFR_MEM16(0x280)
#define SINDACL _SFR_MEM8(0x280)
#define SINDACH _SFR_MEM8(0x281)
#define COSDAC _SFR_MEM8(0x282)
#define COSDACL _SFR_MEM8(0x282)
#define COSDACH _SFR_MEM8(0x283)
#define GAINDAC _SFR_MEM8(0x284)
#define DACCTRL _SFR_MEM8(0x285)
#define INTCCR1A _SFR_MEM8(0x800)
#define INTCCR1B _SFR_MEM8(0x801)
#define INTCNT1 _SFR_MEM16(0x802)
#define INTCNT1L _SFR_MEM8(0x802)
#define INTCNT1H _SFR_MEM8(0x803)
#define INOCR1A _SFR_MEM16(0x804)
#define INOCR1AL _SFR_MEM8(0x804)
#define INOCR1AH _SFR_MEM8(0x805)
#define INOCR1B _SFR_MEM16(0x806)  /* Data sheet says 0x807-0x808, but I believe this is wrong due to conflict with INTCNT. */
#define INOCR1BL _SFR_MEM8(0x806)
#define INOCR1BH _SFR_MEM8(0x807)
#define INTCNT _SFR_MEM8(0x808)
#define INTCCR0 _SFR_MEM8(0x809)
#define INTIFR _SFR_MEM8(0x80A)
#define INTIMSK _SFR_MEM8(0x80B)


/* Constants */
#define RAMSTART     0x1000
#define RAMEND       0x1FFF    /* Last On-Chip SRAM Location */
#define E2END        0x0
#define E2PAGESIZE   0
#define FLASHEND     0xFFFF
#define _VECTORS_SIZE 0


#endif  /* _AVR_IOM3000_H_ */

