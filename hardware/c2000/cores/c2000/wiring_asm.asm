;  ************************************************************************
;  *	wiring_asm.asm
;  *
;  *	Arduino core files for C2000
;  *		Copyright (c) 2012 Trey German. All right reserved.
;  *
;  *
;  ***********************************************************************
;  Derived from:
;  wiring_digital.c - digital input and output functions
;  Part of Arduino - http://www.arduino.cc/
;
;  Copyright (c) 2005-2006 David A. Mellis
;
;  This library is free software; you can redistribute it and/or
;  modify it under the terms of the GNU Lesser General Public
;  License as published by the Free Software Foundation; either
;  version 2.1 of the License, or (at your option) any later version.
;
;  This library is distributed in the hope that it will be useful,
;  but WITHOUT ANY WARRANTY; without even the implied warranty of
;  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
;  Lesser General Public License for more details.
;
;  You should have received a copy of the GNU Lesser General
;  Public License along with this library; if not, write to the
;  Free Software Foundation, Inc., 59 Temple Place, Suite 330,
;  Boston, MA  02111-1307  USA


       .def _DSP28x_usDelay
       .sect "ramfuncs"

        .global  __DSP28x_usDelay
_DSP28x_usDelay:
        SUB    ACC,#1
        BF     _DSP28x_usDelay,GEQ    ;; Loop if ACC >= 0
        LRETR

;There is a 9/10 cycle overhead and each loop
;takes five cycles. The LoopCount is given by
;the following formula:
;  DELAY_CPU_CYCLES = 9 + 5*LoopCount
; LoopCount = (DELAY_CPU_CYCLES - 9) / 5
; The macro DELAY_US(A) performs this calculation for you
