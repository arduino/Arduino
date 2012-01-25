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

/* $Id: eeprom.h 2211 2011-02-14 14:04:25Z aboyapati $ */

#ifndef _AVR_EEPROM_H_
#define _AVR_EEPROM_H_ 1

#include <avr/io.h>

#if !E2END && !defined(__DOXYGEN__) && !defined(__COMPILING_AVR_LIBC__)
# warning "Device does not have EEPROM available."
#else

#ifndef	__DOXYGEN__

#if defined (__AVR_AT94K__)
# define _EEPROM_SUFFIX _at94k
#elif defined (__AVR_AT43USB320__)
# define _EEPROM_SUFFIX _43u320
#elif defined (__AVR_AT43USB355__)
# define _EEPROM_SUFFIX _43u355
#elif defined (__AVR_AT76C711__)
# define _EEPROM_SUFFIX _76c711
#elif defined (__AVR_AT86RF401__)
# define _EEPROM_SUFFIX _86r401
#elif defined (__AVR_AT90PWM1__)
# define _EEPROM_SUFFIX _90pwm1
#elif defined (__AVR_AT90PWM2__)
# define _EEPROM_SUFFIX _90pwm2
#elif defined (__AVR_AT90PWM2B__)
# define _EEPROM_SUFFIX _90pwm2b
#elif defined (__AVR_AT90PWM3__)
# define _EEPROM_SUFFIX _90pwm3
#elif defined (__AVR_AT90PWM3B__)
# define _EEPROM_SUFFIX _90pwm3b
#elif defined (__AVR_AT90PWM216__)
# define _EEPROM_SUFFIX _90pwm216
#elif defined (__AVR_AT90PWM316__)
# define _EEPROM_SUFFIX _90pwm316
#elif defined (__AVR_AT90PWM161__)
# define _EEPROM_SUFFIX _90pwm161
#elif defined (__AVR_AT90PWM81__)
# define _EEPROM_SUFFIX _90pwm81
#elif defined (__AVR_ATmega16M1__)
# define _EEPROM_SUFFIX  _m16m1
#elif defined (__AVR_ATmega8U2__)
# define _EEPROM_SUFFIX  _m8u2
#elif defined (__AVR_ATmega16U2__)
# define _EEPROM_SUFFIX  _m16u2
#elif defined (__AVR_ATmega16U4__)
# define _EEPROM_SUFFIX  _m16u4
#elif defined (__AVR_ATmega32C1__)
# define _EEPROM_SUFFIX  _m32c1
#elif defined (__AVR_ATmega32M1__)
# define _EEPROM_SUFFIX  _m32m1
#elif defined (__AVR_ATmega32U2__)
# define _EEPROM_SUFFIX  _m32u2
#elif defined (__AVR_ATmega32U4__)
# define _EEPROM_SUFFIX  _m32u4
#elif defined (__AVR_ATmega32U6__)
# define _EEPROM_SUFFIX  _m32u6
#elif defined (__AVR_ATmega64C1__)
# define _EEPROM_SUFFIX  _m64c1
#elif defined (__AVR_ATmega64M1__)
# define _EEPROM_SUFFIX  _m64m1
#elif defined (__AVR_ATmega128__)
# define _EEPROM_SUFFIX  _m128
#elif defined (__AVR_ATmega128A__)
# define _EEPROM_SUFFIX  _m128a
#elif defined (__AVR_ATmega1280__)
# define _EEPROM_SUFFIX  _m1280
#elif defined (__AVR_ATmega1281__)
# define _EEPROM_SUFFIX  _m1281
#elif defined (__AVR_ATmega1284__)
# define _EEPROM_SUFFIX  _m1284
#elif defined (__AVR_ATmega1284P__)
# define _EEPROM_SUFFIX  _m1284p
#elif defined (__AVR_ATmega128RFA1__)
# define _EEPROM_SUFFIX  _m128rfa1
#elif defined (__AVR_ATmega128RFA2__)
# define _EEPROM_SUFFIX  _m128rfa2
#elif defined (__AVR_ATmega128RFR2__)
# define _EEPROM_SUFFIX  _m128rfr2
#elif defined (__AVR_ATmega256RFA2__)
# define _EEPROM_SUFFIX  _m256rfa2
#elif defined (__AVR_ATmega256RFR2__)
# define _EEPROM_SUFFIX  _m256rfr2
#elif defined (__AVR_ATmega2560__)
# define _EEPROM_SUFFIX  _m2560
#elif defined (__AVR_ATmega2561__)
# define _EEPROM_SUFFIX  _m2561
#elif defined (__AVR_AT90CAN32__)
# define _EEPROM_SUFFIX _can32
#elif defined (__AVR_AT90CAN64__)
# define _EEPROM_SUFFIX _can64
#elif defined (__AVR_AT90CAN128__)
# define _EEPROM_SUFFIX _can128
#elif defined (__AVR_AT90USB82__)
# define _EEPROM_SUFFIX _usb82
#elif defined (__AVR_AT90USB162__)
# define _EEPROM_SUFFIX _usb162
#elif defined (__AVR_AT90USB646__)
# define _EEPROM_SUFFIX _usb646
#elif defined (__AVR_AT90USB647__)
# define _EEPROM_SUFFIX _usb647
#elif defined (__AVR_AT90USB1286__)
# define _EEPROM_SUFFIX _usb1286
#elif defined (__AVR_AT90USB1287__)
# define _EEPROM_SUFFIX _usb1287
#elif defined (__AVR_ATmega64RFA2__)
# define _EEPROM_SUFFIX  _m64rfa2
#elif defined (__AVR_ATmega64RFR2__)
# define _EEPROM_SUFFIX  _m64rfr2
#elif defined (__AVR_ATmega64__)
# define _EEPROM_SUFFIX  _m64
#elif defined (__AVR_ATmega64A__)
# define _EEPROM_SUFFIX  _m64a
#elif defined (__AVR_ATmega640__)
# define _EEPROM_SUFFIX  _m640
#elif defined (__AVR_ATmega644__)
# define _EEPROM_SUFFIX  _m644
#elif defined (__AVR_ATmega644A__)
# define _EEPROM_SUFFIX  _m644a
#elif defined (__AVR_ATmega644P__)
# define _EEPROM_SUFFIX  _m644p
#elif defined (__AVR_ATmega644PA__)
# define _EEPROM_SUFFIX  _m644pa
#elif defined (__AVR_ATmega645__)
# define _EEPROM_SUFFIX  _m645
#elif defined (__AVR_ATmega645A__)
# define _EEPROM_SUFFIX  _m645a
#elif defined (__AVR_ATmega645P__)
# define _EEPROM_SUFFIX  _m645p
#elif defined (__AVR_ATmega6450__)
# define _EEPROM_SUFFIX  _m6450
#elif defined (__AVR_ATmega6450A__)
# define _EEPROM_SUFFIX  _m6450a
#elif defined (__AVR_ATmega6450P__)
# define _EEPROM_SUFFIX  _m6450p
#elif defined (__AVR_ATmega649__)
# define _EEPROM_SUFFIX  _m649
#elif defined (__AVR_ATmega649A__)
# define _EEPROM_SUFFIX  _m649a
#elif defined (__AVR_ATmega649P__)
# define _EEPROM_SUFFIX  _m649p
#elif defined (__AVR_ATmega6490__)
# define _EEPROM_SUFFIX  _m6490
#elif defined (__AVR_ATmega6490A__)
# define _EEPROM_SUFFIX  _m6490a
#elif defined (__AVR_ATmega6490P__)
# define _EEPROM_SUFFIX  _m6490p
#elif defined (__AVR_ATmega103__)
# define _EEPROM_SUFFIX  _m103
#elif defined (__AVR_ATmega32__)
# define _EEPROM_SUFFIX  _m32
#elif defined (__AVR_ATmega32A__)
# define _EEPROM_SUFFIX  _m32a
#elif defined (__AVR_ATmega323__)
# define _EEPROM_SUFFIX  _m323
#elif defined (__AVR_ATmega324A__)
# define _EEPROM_SUFFIX  _m324a
#elif defined (__AVR_ATmega324P__)
# define _EEPROM_SUFFIX  _m324p
#elif defined (__AVR_ATmega324PA__)
# define _EEPROM_SUFFIX  _m324pa
#elif defined (__AVR_ATmega325__)
# define _EEPROM_SUFFIX  _m325
#elif defined (__AVR_ATmega325A__)
# define _EEPROM_SUFFIX  _m325a
#elif defined (__AVR_ATmega325P__)
# define _EEPROM_SUFFIX  _m325p
#elif defined (__AVR_ATmega325PA__)
# define _EEPROM_SUFFIX  _m325pa 
#elif defined (__AVR_ATmega3250__)
# define _EEPROM_SUFFIX  _m3250
#elif defined (__AVR_ATmega3250A__)
# define _EEPROM_SUFFIX  _m3250a
#elif defined (__AVR_ATmega3250P__)
# define _EEPROM_SUFFIX  _m3250p
#elif defined (__AVR_ATmega3250PA__)
# define _EEPROM_SUFFIX  _m3250pa
#elif defined (__AVR_ATmega328__)
# define _EEPROM_SUFFIX  _m328
#elif defined (__AVR_ATmega328P__)
# define _EEPROM_SUFFIX  _m328p
#elif defined (__AVR_ATmega329__)
# define _EEPROM_SUFFIX  _m329
#elif defined (__AVR_ATmega329A__)
# define _EEPROM_SUFFIX  _m329a
#elif defined (__AVR_ATmega329P__)
# define _EEPROM_SUFFIX  _m329p
#elif defined (__AVR_ATmega329PA__)
# define _EEPROM_SUFFIX  _m329pa
#elif defined (__AVR_ATmega3290__)
# define _EEPROM_SUFFIX  _m3290
#elif defined (__AVR_ATmega3290A__)
# define _EEPROM_SUFFIX  _m3290a
#elif defined (__AVR_ATmega3290P__)
# define _EEPROM_SUFFIX  _m3290p
#elif defined (__AVR_ATmega3290PA__)
# define _EEPROM_SUFFIX  _m3290pa
#elif defined (__AVR_ATmega32HVB__)
# define _EEPROM_SUFFIX  _m32hvb
#elif defined (__AVR_ATmega32HVBREVB__)
# define _EEPROM_SUFFIX  _m32hvbrevb
#elif defined (__AVR_ATmega64HVE__)
# define _EEPROM_SUFFIX  _m64hve
#elif defined (__AVR_ATmega406__)
# define _EEPROM_SUFFIX  _m406
#elif defined (__AVR_ATmega16__)
# define _EEPROM_SUFFIX  _m16
#elif defined (__AVR_ATmega16A__)
# define _EEPROM_SUFFIX  _m16a
#elif defined (__AVR_ATmega161__)
# define _EEPROM_SUFFIX  _m161
#elif defined (__AVR_ATmega162__)
# define _EEPROM_SUFFIX  _m162
#elif defined (__AVR_ATmega163__)
# define _EEPROM_SUFFIX  _m163
#elif defined (__AVR_ATmega164__)
# define _EEPROM_SUFFIX  _m164
#elif defined (__AVR_ATmega164P__)
# define _EEPROM_SUFFIX  _m164p
#elif defined (__AVR_ATmega164PA__)
# define _EEPROM_SUFFIX  _m164pa
#elif defined (__AVR_ATmega165__)
# define _EEPROM_SUFFIX  _m165
#elif defined (__AVR_ATmega165A__)
# define _EEPROM_SUFFIX  _m165a
#elif defined (__AVR_ATmega165P__)
# define _EEPROM_SUFFIX  _m165p
#elif defined (__AVR_ATmega165PA__)
# define _EEPROM_SUFFIX  _m165pa
#elif defined (__AVR_ATmega168__)
# define _EEPROM_SUFFIX  _m168
#elif defined (__AVR_ATmega168A__)
# define _EEPROM_SUFFIX  _m168a
#elif defined (__AVR_ATmega168P__)
# define _EEPROM_SUFFIX  _m168p
#elif defined (__AVR_ATmega168PA__)
# define _EEPROM_SUFFIX  _m168pa
#elif defined (__AVR_ATmega169__)
# define _EEPROM_SUFFIX  _m169
#elif defined (__AVR_ATmega169A__)
# define _EEPROM_SUFFIX  _m169a
#elif defined (__AVR_ATmega169P__)
# define _EEPROM_SUFFIX  _m169p
#elif defined (__AVR_ATmega169PA__)
# define _EEPROM_SUFFIX  _m169pa
#elif defined (__AVR_ATmega8HVA__)
# define _EEPROM_SUFFIX  _m8hva
#elif defined (__AVR_ATmega16HVA__)
# define _EEPROM_SUFFIX  _m16hva
#elif defined (__AVR_ATmega16HVA2__)
# define _EEPROM_SUFFIX  _m16hva2
#elif defined (__AVR_ATmega16HVB__)
# define _EEPROM_SUFFIX  _m16hvb
#elif defined (__AVR_ATmega16HVBREVB__)
# define _EEPROM_SUFFIX  _m16hvbrevb
#elif defined (__AVR_ATmega8__)
# define _EEPROM_SUFFIX  _m8
#elif defined (__AVR_ATmega8A__)
# define _EEPROM_SUFFIX  _m8a
#elif defined (__AVR_ATmega48__)
# define _EEPROM_SUFFIX  _m48
#elif defined (__AVR_ATmega48A__)
# define _EEPROM_SUFFIX  _m48a
#elif defined (__AVR_ATmega48PA__)
# define _EEPROM_SUFFIX  _m48pa
#elif defined (__AVR_ATmega48P__)
# define _EEPROM_SUFFIX  _m48p
#elif defined (__AVR_ATmega88__)
# define _EEPROM_SUFFIX  _m88
#elif defined (__AVR_ATmega88A__)
# define _EEPROM_SUFFIX  _m88a
#elif defined (__AVR_ATmega88P__)
# define _EEPROM_SUFFIX  _m88p
#elif defined (__AVR_ATmega88PA__)
# define _EEPROM_SUFFIX  _m88pa
#elif defined (__AVR_ATmega8515__)
# define _EEPROM_SUFFIX  _m8515
#elif defined (__AVR_ATmega8535__)
# define _EEPROM_SUFFIX  _m8535
#elif defined (__AVR_AT90S8535__)
# define _EEPROM_SUFFIX  _8535
#elif defined (__AVR_AT90C8534__)
# define _EEPROM_SUFFIX  _8534
#elif defined (__AVR_AT90S8515__)
# define _EEPROM_SUFFIX  _8515
#elif defined (__AVR_AT90S4434__)
# define _EEPROM_SUFFIX  _4434
#elif defined (__AVR_AT90S4433__)
# define _EEPROM_SUFFIX  _4433
#elif defined (__AVR_AT90S4414__)
# define _EEPROM_SUFFIX  _4414
#elif defined (__AVR_ATtiny22__)
# define _EEPROM_SUFFIX _tn22
#elif defined (__AVR_ATtiny26__)
# define _EEPROM_SUFFIX _tn26
#elif defined (__AVR_AT90S2343__)
# define _EEPROM_SUFFIX  _2343
#elif defined (__AVR_AT90S2333__)
# define _EEPROM_SUFFIX  _2333
#elif defined (__AVR_AT90S2323__)
# define _EEPROM_SUFFIX  _2323
#elif defined (__AVR_AT90S2313__)
# define _EEPROM_SUFFIX  _2313
#elif defined (__AVR_ATtiny2313__)
# define _EEPROM_SUFFIX _tn2313
#elif defined (__AVR_ATtiny2313A__)
# define _EEPROM_SUFFIX _tn2313a
#elif defined (__AVR_ATtiny4313__)
# define _EEPROM_SUFFIX _tn4313
#elif defined (__AVR_ATtiny13__)
# define _EEPROM_SUFFIX _tn13
#elif defined (__AVR_ATtiny13A__)
# define _EEPROM_SUFFIX _tn13a
#elif defined (__AVR_ATtiny25__)
# define _EEPROM_SUFFIX _tn25
#elif defined (__AVR_ATtiny45__)
# define _EEPROM_SUFFIX _tn45
#elif defined (__AVR_ATtiny85__)
# define _EEPROM_SUFFIX _tn85
#elif defined (__AVR_ATtiny24__)
# define _EEPROM_SUFFIX _tn24
#elif defined (__AVR_ATtiny24A__)
# define _EEPROM_SUFFIX _tn24a
#elif defined (__AVR_ATtiny44__)
# define _EEPROM_SUFFIX _tn44
#elif defined (__AVR_ATtiny44A__)
# define _EEPROM_SUFFIX _tn44a
#elif defined (__AVR_ATtiny84__)
# define _EEPROM_SUFFIX _tn84
#elif defined (__AVR_ATtiny84A__)
# define _EEPROM_SUFFIX _tn84a
#elif defined (__AVR_ATtiny261__)
# define _EEPROM_SUFFIX _tn261
#elif defined (__AVR_ATtiny261A__)
# define _EEPROM_SUFFIX _tn261a
#elif defined (__AVR_ATtiny461__)
# define _EEPROM_SUFFIX _tn461
#elif defined (__AVR_ATtiny461A__)
# define _EEPROM_SUFFIX _tn461a
#elif defined (__AVR_ATtiny861__)
# define _EEPROM_SUFFIX _tn861
#elif defined (__AVR_ATtiny861A__)
# define _EEPROM_SUFFIX _tn861a
#elif defined (__AVR_ATtiny43U__)
# define _EEPROM_SUFFIX _tn43u
#elif defined (__AVR_ATtiny48__)
# define _EEPROM_SUFFIX _tn48
#elif defined (__AVR_ATtiny80__)
# define _EEPROM_SUFFIX _tn80
#elif defined (__AVR_ATtiny88__)
# define _EEPROM_SUFFIX _tn88
#elif defined (__AVR_ATtiny87__)
# define _EEPROM_SUFFIX _tn87
#elif defined (__AVR_ATtiny167__)
# define _EEPROM_SUFFIX _tn167
#elif defined (__AVR_ATtiny1634__)
# define _EEPROM_SUFFIX _tn1634
#elif defined (__AVR_AT90SCR100__)
# define _EEPROM_SUFFIX _90scr100
#elif defined (__AVR_ATxmega16A4__)
# define _EEPROM_SUFFIX   _x16a4
#elif defined (__AVR_ATxmega16A4U__)
# define _EEPROM_SUFFIX   _x16a4u
#elif defined (__AVR_ATxmega16C4__)
# define _EEPROM_SUFFIX   _x16c4
#elif defined (__AVR_ATxmega16D4__)
# define _EEPROM_SUFFIX   _x16d4
#elif defined (__AVR_ATxmega32A4__)
# define _EEPROM_SUFFIX   _x32a4
#elif defined (__AVR_ATxmega32A4U__)
# define _EEPROM_SUFFIX   _x32a4u
#elif defined (__AVR_ATxmega32C4__)
# define _EEPROM_SUFFIX   _x32c4
#elif defined (__AVR_ATxmega32D4__)
# define _EEPROM_SUFFIX   _x32d4
#elif defined (__AVR_ATxmega32X1__)
# define _EEPROM_SUFFIX   _x32x1
#elif defined (__AVR_ATxmega64A1__)
# define _EEPROM_SUFFIX   _x64a1
#elif defined (__AVR_ATxmega64A1U__)
# define _EEPROM_SUFFIX   _x64a1u
#elif defined (__AVR_ATxmega64A3__)
# define _EEPROM_SUFFIX   _x64a3
#elif defined (__AVR_ATxmega64A3U__)
# define _EEPROM_SUFFIX   _x64a3u
#elif defined (__AVR_ATxmega64A4U__)
# define _EEPROM_SUFFIX   _x64a4u
#elif defined (__AVR_ATxmega64B1__)
# define _EEPROM_SUFFIX   _x64b1
#elif defined (__AVR_ATxmega64B3__)
# define _EEPROM_SUFFIX   _x64b3
#elif defined (__AVR_ATxmega64D3__)
# define _EEPROM_SUFFIX   _x64d3
#elif defined (__AVR_ATxmega64D4__)
# define _EEPROM_SUFFIX   _x64d4
#elif defined (__AVR_ATxmega128A1__)
# define _EEPROM_SUFFIX   _x128a1
#elif defined (__AVR_ATxmega128A1U__)
# define _EEPROM_SUFFIX   _x128a1u
#elif defined (__AVR_ATxmega128A4U__)
# define _EEPROM_SUFFIX   _x128a4u
#elif defined (__AVR_ATxmega128A3__)
# define _EEPROM_SUFFIX   _x128a3
#elif defined (__AVR_ATxmega128A3U__)
# define _EEPROM_SUFFIX   _x128a3u
#elif defined (__AVR_ATxmega128B1__)
# define _EEPROM_SUFFIX   _x128b1
#elif defined (__AVR_ATxmega128B3__)
# define _EEPROM_SUFFIX   _x128b3
#elif defined (__AVR_ATxmega128C3__)
# define _EEPROM_SUFFIX   _x128c3
#elif defined (__AVR_ATxmega128D3__)
# define _EEPROM_SUFFIX   _x128d3
#elif defined (__AVR_ATxmega128D4__)
# define _EEPROM_SUFFIX   _x128d4
#elif defined (__AVR_ATxmega192A3__)
# define _EEPROM_SUFFIX   _x192a3
#elif defined (__AVR_ATxmega192A3U__)
# define _EEPROM_SUFFIX   _x192a3u
#elif defined (__AVR_ATxmega192D3__)
# define _EEPROM_SUFFIX   _x192d3
#elif defined (__AVR_ATxmega256A3__)
# define _EEPROM_SUFFIX   _x256a3
#elif defined (__AVR_ATxmega256A3U__)
# define _EEPROM_SUFFIX   _x256a3u
#elif defined (__AVR_ATxmega256A3B__)
# define _EEPROM_SUFFIX   _x256a3b
#elif defined (__AVR_ATxmega256A3BU__)
# define _EEPROM_SUFFIX   _x256a3bu
#elif defined (__AVR_ATxmega256C3__)
# define _EEPROM_SUFFIX   _x256c3
#elif defined (__AVR_ATxmega256D3__)
# define _EEPROM_SUFFIX   _x256d3
#elif defined (__AVR_ATxmega384C3__)
# define _EEPROM_SUFFIX   _x384c3
#elif defined (__AVR_ATxmega384D3__)
# define _EEPROM_SUFFIX   _x384d3
#elif defined (__AVR_ATA6289__)
# define _EEPROM_SUFFIX _a6289
/* avr1: the following only supported for assembler programs */
#elif defined (__AVR_ATtiny28__)
# define _EEPROM_SUFFIX _tn28
#elif defined (__AVR_AT90S1200__)
# define _EEPROM_SUFFIX  _1200
#elif defined (__AVR_ATtiny15__)
# define _EEPROM_SUFFIX _tn15
#elif defined (__AVR_ATtiny12__)
# define _EEPROM_SUFFIX _tn12
#elif defined (__AVR_ATtiny11__)
# define _EEPROM_SUFFIX _tn11
#else
# define _EEPROM_SUFFIX		_UNKNOWN
#endif

#define _EEPROM_CONCAT1(s1, s2)     s1 ## s2
#define _EEPROM_CONCAT2(s1, s2)     _EEPROM_CONCAT1 (s1, s2)

#define eeprom_read_byte      _EEPROM_CONCAT2 (__eerd_byte, _EEPROM_SUFFIX)
#define eeprom_read_word      _EEPROM_CONCAT2 (__eerd_word, _EEPROM_SUFFIX)
#define eeprom_read_dword     _EEPROM_CONCAT2 (__eerd_dword, _EEPROM_SUFFIX)
#define eeprom_read_float     _EEPROM_CONCAT2 (__eerd_float, _EEPROM_SUFFIX)
#define eeprom_read_block     _EEPROM_CONCAT2 (__eerd_block, _EEPROM_SUFFIX)

#define eeprom_write_byte     _EEPROM_CONCAT2 (__eewr_byte, _EEPROM_SUFFIX)
#define eeprom_write_word     _EEPROM_CONCAT2 (__eewr_word, _EEPROM_SUFFIX)
#define eeprom_write_dword    _EEPROM_CONCAT2 (__eewr_dword, _EEPROM_SUFFIX)
#define eeprom_write_float    _EEPROM_CONCAT2 (__eewr_float, _EEPROM_SUFFIX)
#define eeprom_write_block    _EEPROM_CONCAT2 (__eewr_block, _EEPROM_SUFFIX)

#define eeprom_update_byte    _EEPROM_CONCAT2 (__eeupd_byte, _EEPROM_SUFFIX)
#define eeprom_update_word    _EEPROM_CONCAT2 (__eeupd_word, _EEPROM_SUFFIX)
#define eeprom_update_dword   _EEPROM_CONCAT2 (__eeupd_dword, _EEPROM_SUFFIX)
#define eeprom_update_float   _EEPROM_CONCAT2 (__eeupd_float, _EEPROM_SUFFIX)
#define eeprom_update_block   _EEPROM_CONCAT2 (__eeupd_block, _EEPROM_SUFFIX)

#endif	/* !__DOXYGEN__ */

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
#elif	defined (__AVR_XMEGA__) && __AVR_XMEGA__
# define eeprom_is_ready()	bit_is_clear (NVM_STATUS, NVM_NVMBUSY_bp)
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
