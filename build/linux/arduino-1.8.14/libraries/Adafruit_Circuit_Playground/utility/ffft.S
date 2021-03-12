#ifdef __AVR__
;-----------------------------------------------------------------------------;
; Fixed-point FFT routines for megaAVRs                        (C)ChaN, 2005
;-----------------------------------------------------------------------------;
; * This program is opened under license policy of following trems.
;
;  Copyright (C) 2005, ChaN, all right reserved.
;
; * This program is a free software and there is NO WARRANTY.
; * No restriction on use. You can use, modify and redistribute it for
;   personal, non-profit or commercial use UNDER YOUR RESPONSIBILITY.
; * Redistributions of source code must retain the above copyright notice.
;
;-----------------------------------------------------------------------------;
;
; void fft_input (const int16_t *array_src, complex_t *array_bfly);
; void fft_execute (complex_t *array_bfly);
; void fft_output (complex_t *array_bfly, uint16_t *array_dst);
;
;  <array_src>: Wave form to be processed.
;  <array_bfly>: Complex array for butterfly operations.
;  <array_dst>: Spectrum output buffer.
;
; These functions must be called in sequence to do a DFT in FFT algorithm.
; fft_input() fills the complex array with a wave form to prepare butterfly
; operations. A hamming window is applied at the same time.
; fft_execute() executes the butterfly operations.
; fft_output() re-orders the results, converts the complex spectrum into
; scalar spectrum and output it in linear scale.
;
;----------------------------------------------------------------------------;
; THIS CODE HAS BEEN MODIFIED FROM ITS ORIGINAL FORM - it is pared down
; to handle 64 points only, for the Circuit Playground microphone library.
; Original FFFT code can be found on GitHub.
;----------------------------------------------------------------------------;

.list

#define FFT_N 64
#define FFT_B 6

#define T0L  r0
#define T0H r1
#define T2L r2
#define T2H r3
#define T4L r4
#define T4H r5
#define T6L r6
#define T6H r7
#define T8L r8
#define T8H r9
#define T10L  r10
#define T10H  r11
#define T12L  r12
#define T12H  r13
#define T14L  r14
#define T14H  r15
#define AL  r16
#define AH  r17
#define BL  r18
#define BH  r19
#define CL  r20
#define CH  r21
#define DL  r22
#define DH  r23
#define EL  r24
#define EH  r25
#define XL  r26
#define XH  r27
#define YL  r28
#define YH  r29
#define ZL  r30
#define ZH  r31

.macro  ldiw  dh,dl, abs
  ldi \dl, lo8(\abs)
  ldi \dh, hi8(\abs)
.endm

.macro  subiw dh,dl, abs
  subi  \dl, lo8(\abs)
  sbci  \dh, hi8(\abs)
.endm

.macro  addw  dh,dl, sh,sl
  add \dl, \sl
  adc \dh, \sh
.endm

.macro  addd  d3,d2,d1,d0, s3,s2,s1,s0
  add \d0, \s0
  adc \d1, \s1
  adc \d2, \s2
  adc \d3, \s3
.endm

.macro  subw  dh,dl, sh,sl
  sub \dl, \sl
  sbc \dh, \sh
.endm

.macro  subd  d3,d2,d1,d0, s3,s2,s1,s0
  sub \d0, \s0
  sbc \d1, \s1
  sbc \d2, \s2
  sbc \d3, \s3
.endm

.macro  lddw  dh,dl, src
  ldd \dl, \src
  ldd \dh, \src+1
.endm

.macro  ldw dh,dl, src
  ld  \dl, \src
  ld  \dh, \src
.endm

.macro  stw dst, sh,sl
  st  \dst, \sl
  st  \dst, \sh
.endm

.macro  clrw  dh, dl
  clr \dh
  clr \dl
.endm

.macro  lsrw  dh, dl
  lsr \dh
  ror \dl
.endm

.macro  asrw  dh, dl
  asr \dh
  ror \dl
.endm

.macro  lslw  dh, dl
  lsl \dl
  rol \dh
.endm

.macro  pushw dh, dl
  push  \dh
  push  \dl
.endm

.macro  popw  dh, dl
  pop \dl
  pop \dh
.endm

.macro  lpmw  dh,dl, src
  lpm \dl, \src
  lpm \dh, \src
.endm

.macro  rjne  lbl
  breq  99f
  rjmp  \lbl
99:
.endm

.macro  FMULS16 d3,d2,d1,d0 ,s1h,s1l, s2h,s2l ;Fractional Multiply (19clk)
  fmuls \s1h, \s2h
  movw  \d2, T0L
  fmul  \s1l, \s2l
  movw  \d0, T0L
  adc \d2, EH ;EH: zero reg.
  fmulsu  \s1h, \s2l
  sbc \d3, EH
  add \d1, T0L
  adc \d2, T0H
  adc \d3, EH
  fmulsu  \s2h, \s1l
  sbc \d3, EH
  add \d1, T0L
  adc \d2, T0H
  adc \d3, EH
.endm

.macro  SQRT32  ; 32bit square root (526..542clk)
  clr T6L
  clr T6H
  clr T8L
  clr T8H
  ldi BL, 1
  ldi BH, 0
  clr CL
  clr CH
  ldi DH, 16
90: lsl T2L
  rol T2H
  rol T4L
  rol T4H
  rol T6L
  rol T6H
  rol T8L
  rol T8H
  lsl T2L
  rol T2H
  rol T4L
  rol T4H
  rol T6L
  rol T6H
  rol T8L
  rol T8H
  brpl  91f
  add T6L, BL
  adc T6H, BH
  adc T8L, CL
  adc T8H, CH
  rjmp  92f
91: sub T6L, BL
  sbc T6H, BH
  sbc T8L, CL
  sbc T8H, CH
92: lsl BL
  rol BH
  rol CL
  andi  BL, 0b11111000
  ori BL, 0b00000101
  sbrc  T8H, 7
  subi  BL, 2
  dec DH
  brne  90b
  lsr CL
  ror BH
  ror BL
  lsr CL
  ror BH
  ror BL
.endm

;----------------------------------------------------------------------------;
; Constant Tables

.global tbl_window
tbl_window:	; tbl_window[] = ... (This is a Hamming window)
	.dc.w	2621, 2693, 2910, 3270, 3768, 4401, 5161, 6042, 7036, 8132, 9320, 10588, 11926, 13318, 14753, 16216
	.dc.w	17694, 19171, 20634, 22069, 23462, 24799, 26068, 27256, 28352, 29345, 30226, 30987, 31619, 32117, 32477, 32694
	.dc.w	32766, 32694, 32477, 32117, 31619, 30987, 30226, 29345, 28352, 27256, 26068, 24799, 23462, 22069, 20634, 19171
	.dc.w	17694, 16216, 14753, 13318, 11926, 10588, 9320, 8132, 7036, 6042, 5161, 4401, 3768, 3270, 2910, 2693
tbl_cos_sin:	; Table of {cos(x),sin(x)}, (0 <= x < pi, in FFT_N/2 steps)
	.dc.w	32767, 0, 32609, 3211, 32137, 6392, 31356, 9511, 30272, 12539, 28897, 15446, 27244, 18204, 25329, 20787
	.dc.w	23169, 23169, 20787, 25329, 18204, 27244, 15446, 28897, 12539, 30272, 9511, 31356, 6392, 32137, 3211, 32609
	.dc.w	0, 32766, -3211, 32609, -6392, 32137, -9511, 31356, -12539, 30272, -15446, 28897, -18204, 27244, -20787, 25329
	.dc.w	-23169, 23169, -25329, 20787, -27244, 18204, -28897, 15446, -30272, 12539, -31356, 9511, -32137, 6392, -32609, 3211
tbl_bitrev:		; tbl_bitrev[] = ...
	.dc.w	0*4, 32*4, 16*4, 48*4, 8*4, 40*4, 24*4, 56*4, 4*4, 36*4, 20*4, 52*4, 12*4, 44*4, 28*4, 60*4
	.dc.w	2*4, 34*4, 18*4, 50*4, 10*4, 42*4, 26*4, 58*4, 6*4, 38*4, 22*4, 54*4, 14*4, 46*4, 30*4, 62*4

;----------------------------------------------------------------------------;
.global fft_input
.func fft_input
fft_input:
	pushw	T2H,T2L
	pushw	AH,AL
	pushw	YH,YL

	movw	XL, EL				;X = array_src;
	movw	YL, DL				;Y = array_bfly;
	clr	EH				;Zero
	ldiw	ZH,ZL, tbl_window		;Z = &tbl_window[0];
	ldiw	AH,AL, FFT_N			;A = FFT_N;
1:	lpmw	BH,BL, Z+			;B = *Z++; (window)
	ldw	CH,CL, X+			;C = *X++; (I-axis)
	FMULS16	DH,DL,T2H,T2L, BH,BL, CH,CL	;D = B * C;
	stw	Y+, DH,DL			;*Y++ = D;
	stw	Y+, DH,DL			;*Y++ = D;
	subiw	AH,AL, 1			;while(--A)
	brne	1b				;/

	popw	YH,YL
	popw	AH,AL
	popw	T2H,T2L
	clr	r1
	ret
.endfunc

;----------------------------------------------------------------------------;
.global fft_execute
.func fft_execute
fft_execute:
	pushw	T2H,T2L
	pushw	T4H,T4L
	pushw	T6H,T6L
	pushw	T8H,T8L
	pushw	T10H,T10L
	pushw	T12H,T12L
	pushw	T14H,T14L
	pushw	AH,AL
	pushw	YH,YL

	movw	ZL, EL				;Z = array_bfly;
	ldiw	EH,EL, 1			;E = 1;
	ldiw	XH,XL, FFT_N/2			;X = FFT_N/2;
1:	ldi	AL, 4				;T12 = E; (angular speed)
	mul	EL, AL				;
	movw	T12L, T0L			;
	mul	EH, AL				;
	add	T12H, T0L			;/
	movw	T14L, EL			;T14 = E;
	pushw	EH,EL
	movw	YL, ZL				;Z = &array_bfly[0];
	mul	XL, AL				;Y = &array_bfly[X];
	addw	YH,YL, T0H,T0L			;
	mul	XH, AL				;
	add	YH, T0L				;/
	pushw	ZH,ZL
2:	clrw	T10H,T10L			;T10 = 0 (angle)
	clr	EH				;Zero reg.
3:	lddw	AH,AL, Z+0			;A = *Z - *Y; *Z++ += *Y;
	asrw	AH,AL				;
	lddw	DH,DL, Y+0			;
	asrw	DH,DL				;
	movw	CL, AL				;
	subw	AH,AL, DH,DL			;
	addw	CH,CL, DH,DL			;
	stw	Z+, CH,CL			;/
	lddw	BH,BL, Z+0			;B = *Z - *Y; *Z++ += *Y;
	asrw	BH,BL				;
	lddw	DH,DL, Y+2			;
	asrw	DH,DL				;
	movw	CL, BL				;
	subw	BH,BL, DH,DL			;
	addw	CH,CL, DH,DL			;
	stw	Z+, CH,CL			;/
	movw	T0L, ZL
	ldiw	ZH,ZL, tbl_cos_sin		;C = cos(T10); D = sin(T10);
	addw	ZH,ZL, T10H,T10L		;
	lpmw	CH,CL, Z+			;
	lpmw	DH,DL, Z+			;/
	movw	ZL, T0L
	FMULS16	T4H,T4L,T2H,T2L, AH,AL, CH,CL	;*Y++ = A * C + B * D;
	FMULS16	T8H,T8L,T6H,T6L, BH,BL, DH,DL	;
	addd	T4H,T4L,T2H,T2L, T8H,T8L,T6H,T6L;
	stw	Y+, T4H,T4L			;/
	FMULS16	T4H,T4L,T2H,T2L, BH,BL, CH,CL 	;*Y++ = B * C - A * D;
	FMULS16	T8H,T8L,T6H,T6L, AH,AL, DH,DL 	;
	subd	T4H,T4L,T2H,T2L, T8H,T8L,T6H,T6L;
	stw	Y+, T4H,T4L			;/
	addw	T10H,T10L, T12H,T12L		;T10 += T12; (next angle)
#if FFT_N >= 128
	sbrs	T10H, FFT_B - 7			;while(T10 < pi)
#else
	sbrs	T10L, FFT_B + 1
#endif
	rjmp	3b				;/
	ldi	AL, 4				;Y += X; Z += X; (skip split segment)
	mul	XL, AL
	addw	YH,YL, T0H,T0L			;
	addw	ZH,ZL, T0H,T0L			;
	mul	XH, AL				;
	add	YH, T0L				;
	add	ZH, T0L				;/
	ldi	EL, 1				;while(--T14)
	subw	T14H,T14L, EH,EL		;
	rjne	2b				;/
	popw	ZH,ZL
	popw	EH,EL
	lslw	EH,EL				;E *= 2;
	lsrw	XH,XL				;while(X /= 2)
	adiw	XL, 0				;
	rjne	1b				;/

	popw	YH,YL
	popw	AH,AL
	popw	T14H,T14L
	popw	T12H,T12L
	popw	T10H,T10L
	popw	T8H,T8L
	popw	T6H,T6L
	popw	T4H,T4L
	popw	T2H,T2L
;	clr	r1
	ret
.endfunc

;----------------------------------------------------------------------------;
.global fft_output
.func fft_output
fft_output:
	pushw	T2H,T2L
	pushw	T4H,T4L
	pushw	T6H,T6L
	pushw	T8H,T8L
	pushw	T10H,T10L
	pushw	AH,AL
	pushw	YH,YL

	movw	T10L, EL			;T10 = array_bfly;
	movw	YL, DL				;Y = array_output;
	ldiw	ZH,ZL, tbl_bitrev		;Z = tbl_bitrev;
	clr	EH				;Zero
	ldiw	AH,AL, FFT_N / 2		;A = FFT_N / 2; (plus only)
1:	lpmw	XH,XL, Z+			;X = *Z++;
	addw	XH,XL, T10H,T10L		;X += array_bfly;
	ldw	BH,BL, X+			;B = *X++;
	ldw	CH,CL, X+			;C = *X++;
	FMULS16	T4H,T4L,T2H,T2L, BH,BL, BH,BL	;T4:T2 = B * B;
	FMULS16	T8H,T8L,T6H,T6L, CH,CL, CH,CL	;T8:T6 = C * C;
	addd	T4H,T4L,T2H,T2L, T8H,T8L,T6H,T6L;T4:T2 += T8:T6;
	SQRT32					;B = sqrt(T4:T2);
	stw	Y+, BH,BL			;*Y++ = B;
	subiw	AH,AL, 1			;while(--A)
	rjne	1b				;/

	popw	YH,YL
	popw	AH,AL
	popw	T10H,T10L
	popw	T8H,T8L
	popw	T6H,T6L
	popw	T4H,T4L
	popw	T2H,T2L
	clr	r1
	ret
.endfunc

;----------------------------------------------------------------------------;
.global fmuls_f
.func fmuls_f
fmuls_f:
	movw	CL, EL				;C = E;
	clr	EH	;Zero
	FMULS16	ZH,ZL,XH,XL, CH,CL, DH,DL	;Z:X = C * D;
	movw	EL, ZL
	clr	r1
	ret
.endfunc

#endif // __AVR__

#ifdef __SAMD21G18A__
.cpu cortex-m0plus
.fpu softvfp
#endif

#ifdef NRF52840_XXAA
.cpu cortex-m4
#endif