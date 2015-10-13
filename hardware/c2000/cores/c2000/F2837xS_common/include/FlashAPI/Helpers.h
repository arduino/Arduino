/*--------------------------------------------------------*/
/* F021\Helpers.h                                         */
/*                                                        */
/* Copyright (c) 2009-2011 Texas Instruments Incorporated */
/*                                                        */
/* F021 Flash API v1.00                                   */
/*--------------------------------------------------------*/

/*!
    \file F021\Helpers.h
    \brief A set of helper Macros.

    These helper Macros are to facilitate common
    operations.
*/
#ifndef F021_HELPERS_H_
#define F021_HELPERS_H_

/*!
    \brief Quick Register referencing macro
*/
#define REGISTER(mRegister) (* (volatile uint32 *)(mRegister))

#define FAPI_WRITE_LOCKED_FSM_REGISTER(mRegister,mValue)                                      \
	{                                                                                         \
		Fapi_GlobalInit.m_poFlashControlRegisters->FsmWrEna.FSM_WR_ENA_BITS.WR_ENA    = 0x5U; \
		mRegister = mValue;                                                                   \
		Fapi_GlobalInit.m_poFlashControlRegisters->FsmWrEna.FSM_WR_ENA_BITS.WR_ENA    = 0x2U; \
    }


#if defined(_LITTLE_ENDIAN)
    #define EI16(idx)            (idx ^ 1)
    #define EI8(idx)             (idx ^ 3)
#else
	#define EI16(idx)            (idx)
	#define EI8(idx)             (idx)
#endif

#endif /* F021_HELPERS_H_ */
