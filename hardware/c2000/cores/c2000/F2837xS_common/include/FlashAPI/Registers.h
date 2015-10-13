/*--------------------------------------------------------*/
/* F021\Registers.h                                       */
/*                                                        */
/* Copyright (c) 2009-2011 Texas Instruments Incorporated */
/*                                                        */
/* F021 Flash API v1.00                                   */
/*--------------------------------------------------------*/

/*!
    \file F021\Registers.h
    \brief A complete mapping of the F021 Flash Registers

    Allows named access to the F021 Flash Registers.
*/
#ifndef F021_REGISTERS_H_
#define F021_REGISTERS_H_

#include "Types.h"

#if defined(_F2837xD)
    #include "Registers_C28x.h"
#elif defined(_C28X)
    #include "Registers_Concerto_C28x.h"
#elif defined(_CONCERTO)
    #include  "Registers_Concerto_Cortex.h"  
#elif defined(_LITTLE_ENDIAN)
    #include "Registers_FMC_LE.h"
#else    
    #include "Registers_FMC_BE.h"
#endif
    
#endif /*F021_REGISTERS_H_*/
