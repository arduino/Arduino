/*--------------------------------------------------------*/
/* F021\Constants\Constants.h                             */
/*                                                        */
/* Copyright (c) 2009-2011 Texas Instruments Incorporated */
/*                                                        */
/* F021 Flash API v1.53                                   */
/*--------------------------------------------------------*/

/*!
    \file F021\Constants\Constants.h
    \brief A set of Constant Values.
*/
#ifndef F021_CONSTANTS_H_
#define F021_CONSTANTS_H_

#if defined(_CONCERTO)
    #include "Concerto.h"
#elif defined(_F2837xD)
    #include "F2837xD.h"
#else
    #include "FMC.h"
#endif



/*!
    \brief Define to map the direct access to the TI OTP memory.
*/
#define F021_TIOTP_BASE_ADDRESS ((Fapi_TiOtpBytesType *)(F021_PROGRAM_TIOTP_OFFSET + F021_TIOTP_SETTINGS_BASE))

/*!
    \brief Define to map the direct access to the FMC registers.
*/
#define F021_CPU0_BASE_ADDRESS ((Fapi_FmcRegistersType *)F021_CPU0_REGISTER_ADDRESS)

#endif /* F021_CONSTANTS_H_ */
