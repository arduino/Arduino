//*****************************************************************************
//
// Copyright (C) 2012 - 2015 Texas Instruments Incorporated - http://www.ti.com/
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
// MSP432 Family CMSIS Definitions
//
//****************************************************************************

#ifndef CMSIS_CCS_H_
#define CMSIS_CCS_H_

//*****************************************************************************
// CMSIS-compatible instruction calls
//*****************************************************************************

#ifndef __cplusplus
// No Operation
__attribute__( ( always_inline ) ) static inline void __nop(void)
{
	__asm("  nop");
}

__attribute__( ( always_inline ) ) static inline void __NOP(void)
{
	__asm("  nop");
}

// Wait For Interrupt
__attribute__( ( always_inline ) ) static inline void __wfi(void)
{
	__asm("  wfi");
}

// Wait For Event
__attribute__( ( always_inline ) ) static inline void __wfe(void)
{
	__asm("  wfe");
}
#endif

// Enable Interrupts
__attribute__( ( always_inline ) ) static inline void __enable_irq(void)
{
	__asm("  cpsie i");
}

// Disable Interrupts
__attribute__( ( always_inline ) ) static inline void __disable_irq(void)
{
	__asm("  cpsid i");
}

// Data Synchronization Barrier
__attribute__( ( always_inline ) ) static inline void __DSB(void)
{
	__asm("  dsb");
}

#if (0)
// Get Main Stack Pointer
static inline uint32_t __get_MSP(void)
{
	register uint32_t result;
	//__asm ("  mrs result, msp");
	return(result);
}

// Set Main Stack Pointer
static inline void __set_MSP(uint32_t topOfMainStack)
{
	asm(" .global topOfMainStack");
	__asm ("  msr msp, topOfMainStack");
}


// Get Priority Mask
static inline uint32_t __get_PRIMASK(void)
{
	uint32_t result;
	__asm ("  mrs result, primask");
	return(result);
}


// Set Priority Mask
static inline void __set_PRIMASK(uint32_t priMask)
{
	__asm ("  msr primask, priMask");
}
#endif


//
// 	v5e, v6, Cortex-M3, Cortex-M4, Cortex-R4, and Cortex-A8 compiler intrinsics
//
#define __CLZ		_norm
#define __SXTB		_sxtb
#define __SXTH		_sxth
#define __UXTB		_uxtb
#define __UXTH		_uxth
//  CCS supports intrinsics to take advantage of the shift operand left/right
//	  before saturation extension of SSAT, but CMSIS does not take advantage
//	  of those, so tell the compiler to use a sat & shift left with a shift
//	  value of 0 whenever it encounters an SSAT
#define __SSAT(VAL, BITPOS) \
	_ssatl(VAL , 0, BITPOS)

//
//  Only define M4 based intrinsics if we're not using an M4
//
#if defined (__TI_TMS470_V7M4__)
//		
//	V5E, V6, Cortex-M4, Cortex-R4, and Cortex-A8 compiler intrinsics
//
#define __QADD		_sadd
#define __QDADD		_sdadd
#define __QDSUB		_sdsub
#define	__SMLABB	_smlabb
#define	__SMLABT	_smlabt
#define __SMLALBB	_smlalbb
#define __SMLALBT	_smlalbt
#define __SMLALTB	_smlaltb
#define __SMLALTT	_smlaltt
#define __SMLATB	_smlatb
#define __SMLATT	_smlatt
#define __SMLAWB	_smlawb
#define __SMLAWT	_smlawt

#define __SMULBB	_smulbb
#define __SMULBT	_smulbt
#define __SMULTB	_smultb
#define __SMULTT	_smultt
#define __SMULWB	_smulwb
#define __SMULWT	_smulwt
#define __QSUB		_ssub
#define __SUBC		_subc

//
//	v6, Cortex-M4, Cortex-R4, and Cortex-A8 compiler intrinsics
//
#define __SHASX		_shaddsubx
#define __SHSAX		_shsubaddx
#define __PKHBT		_pkhbt
#define __PKHTB		_pkhtb
#define __QADD16	_qadd16
#define __QADD8		_qadd8
#define __QSUB16	_qsub16
#define __QSUB8		_qsub8
#define __QASX		_saddsubx
#define __QSAX		_qsubaddx
#define __SADD16	_sadd16
#define __SADD8		_sadd8
#define __SASX		_saddsubx
#define __SEL		_sel
#define __SHADD16	_shadd16
#define __SHADD8	_shadd8
#define __SHSUB16	_shsub16
#define __SHSUB8	_shsub8
#define __SMLAD		_smlad
#define __SMLADX	_smladx
#define __SMLALD	_smlald
#define __SMLALDX	_smlaldx
#define __SMLSD		_smlsd
#define __SMLSDX	_smlsdx
#define __SMLSLD	_smlsld
#define __SMLSLDX	_smlsldx
#define __SMMLA		_smmla
#define __SMMLAR	_smmlar
#define __SMMLS		_smmls
#define __SMMLSR	_smmlsr
#define __SMMUL		_smmul
#define __SMMULR	_smmulr
#define __SMUAD		_smuad
#define __SMUADX	_smuadx
#define __SMUSD		_smusd
#define __SMUSDX	_smusdx
#define __SSAT16	_ssat16
#define __SSUB16	_ssub16
#define __SSUB8		_ssub8
#define __SSAX		_ssubaddx
#define __SXTAB		_sxtab
#define __SXTAB16	_sxtab16
#define __SXTAH		_sxtah
#define __UMAAL		_umaal
#define __UADD16	_uadd16
#define __UADD8		_uadd8
#define __UHADD16	_uhadd16
#define __UHADD8	_uhadd8
#define __UASX		_uaddsubx
#define __UHSUB16	_uhsub16
#define __UHSUB8	_uhsub8
#define __UQADD16	_uqadd16
#define __UQADD8	_uqadd8
#define __UQASX		_uqaddsubx
#define __UQSUB16	_uqsub16
#define __UQSUB8	_uqsub8
#define __UQSAX		_uqsubaddx
#define __USAD8		_usad8
#define __USAT16	_usat16
#define __USUB16	_usub16
#define __USUB8		_usub8
#define __USAX		_usubaddx
#define __UXTAB		_uxtab
#define __UXTAB16	_uxtab16
#define __UXTAH		_uxtah
#define __UXTB16	_uxtb16
#endif /*__TI_TMS470_V7M4__*/

#endif /*CMSIS_CCS_H_*/
