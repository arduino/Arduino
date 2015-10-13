/*--------------------------------------------------------*/
/* F021\Init.h                                            */
/*                                                        */
/* Copyright (c) 2009-2011 Texas Instruments Incorporated */
/*                                                        */
/* F021 Flash API v1.00                                   */
/*--------------------------------------------------------*/

#pragma once

/*!
    \file F021\Init.h
    \brief 
*/
#ifndef FAPI_INIT_H_
#define FAPI_INIT_H_

typedef struct 
{
   Fapi_TiOtpBytesType   *m_poTiOtpBaseAddress;
   Fapi_FmcRegistersType *m_poFlashControlRegisters;
   uint8 m_u8MainBankWidth;
   uint8 m_u8EeBankWidth;
   uint8 m_u8MainEccWidth;
   uint8 m_u8EeEccWidth;
   uint8 m_u8CurrentRwait;
   uint8 m_u8CurrentEwait;
   uint16 m_u16HclkFrequency;
} Fapi_InitStruct;

#endif /* FAPI_FLASH_STATE_MACHINE_H_ */
