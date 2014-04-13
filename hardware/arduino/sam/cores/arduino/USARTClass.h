/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef _USART_CLASS_
#define _USART_CLASS_

#include "HardwareSerial.h"
#include "RingBuffer.h"

// Includes Atmel CMSIS
#include <chip.h>

// Define config for Serialx.begin(baud, config);
// Note that these modes are only applicable for USART module
#define SERIAL_5N1 ( US_MR_CHRL_5_BIT | US_MR_PAR_NO | US_MR_NBSTOP_1_BIT )
#define SERIAL_6N1 ( US_MR_CHRL_6_BIT | US_MR_PAR_NO | US_MR_NBSTOP_1_BIT )
#define SERIAL_7N1 ( US_MR_CHRL_7_BIT | US_MR_PAR_NO | US_MR_NBSTOP_1_BIT )
#define SERIAL_8N1 ( US_MR_CHRL_8_BIT | US_MR_PAR_NO | US_MR_NBSTOP_1_BIT )

#define SERIAL_5N15 ( US_MR_CHRL_5_BIT | US_MR_PAR_NO | US_MR_NBSTOP_1_5_BIT )
#define SERIAL_6N15 ( US_MR_CHRL_6_BIT | US_MR_PAR_NO | US_MR_NBSTOP_1_5_BIT )
#define SERIAL_7N15 ( US_MR_CHRL_7_BIT | US_MR_PAR_NO | US_MR_NBSTOP_1_5_BIT )
#define SERIAL_8N15 ( US_MR_CHRL_8_BIT | US_MR_PAR_NO | US_MR_NBSTOP_1_5_BIT )

#define SERIAL_5N2 ( US_MR_CHRL_5_BIT | US_MR_PAR_NO | US_MR_NBSTOP_2_BIT )
#define SERIAL_6N2 ( US_MR_CHRL_6_BIT | US_MR_PAR_NO | US_MR_NBSTOP_2_BIT )
#define SERIAL_7N2 ( US_MR_CHRL_7_BIT | US_MR_PAR_NO | US_MR_NBSTOP_2_BIT )
#define SERIAL_8N2 ( US_MR_CHRL_8_BIT | US_MR_PAR_NO | US_MR_NBSTOP_2_BIT )

#define SERIAL_5E1 ( US_MR_CHRL_5_BIT | US_MR_PAR_EVEN | US_MR_NBSTOP_1_BIT )
#define SERIAL_6E1 ( US_MR_CHRL_6_BIT | US_MR_PAR_EVEN | US_MR_NBSTOP_1_BIT )
#define SERIAL_7E1 ( US_MR_CHRL_7_BIT | US_MR_PAR_EVEN | US_MR_NBSTOP_1_BIT )
#define SERIAL_8E1 ( US_MR_CHRL_8_BIT | US_MR_PAR_EVEN | US_MR_NBSTOP_1_BIT )

#define SERIAL_5E15 ( US_MR_CHRL_5_BIT | US_MR_PAR_EVEN | US_MR_NBSTOP_1_5_BIT )
#define SERIAL_6E15 ( US_MR_CHRL_6_BIT | US_MR_PAR_EVEN | US_MR_NBSTOP_1_5_BIT )
#define SERIAL_7E15 ( US_MR_CHRL_7_BIT | US_MR_PAR_EVEN | US_MR_NBSTOP_1_5_BIT )
#define SERIAL_8E15 ( US_MR_CHRL_8_BIT | US_MR_PAR_EVEN | US_MR_NBSTOP_1_5_BIT )

#define SERIAL_5E2 ( US_MR_CHRL_5_BIT | US_MR_PAR_EVEN | US_MR_NBSTOP_2_BIT )
#define SERIAL_6E2 ( US_MR_CHRL_6_BIT | US_MR_PAR_EVEN | US_MR_NBSTOP_2_BIT )
#define SERIAL_7E2 ( US_MR_CHRL_7_BIT | US_MR_PAR_EVEN | US_MR_NBSTOP_2_BIT )
#define SERIAL_8E2 ( US_MR_CHRL_8_BIT | US_MR_PAR_EVEN | US_MR_NBSTOP_2_BIT )

#define SERIAL_5O1 ( US_MR_CHRL_5_BIT | US_MR_PAR_ODD | US_MR_NBSTOP_1_BIT )
#define SERIAL_6O1 ( US_MR_CHRL_6_BIT | US_MR_PAR_ODD | US_MR_NBSTOP_1_BIT )
#define SERIAL_7O1 ( US_MR_CHRL_7_BIT | US_MR_PAR_ODD | US_MR_NBSTOP_1_BIT )
#define SERIAL_8O1 ( US_MR_CHRL_8_BIT | US_MR_PAR_ODD | US_MR_NBSTOP_1_BIT )

#define SERIAL_5O15 ( US_MR_CHRL_5_BIT | US_MR_PAR_ODD | US_MR_NBSTOP_1_5_BIT )
#define SERIAL_6O15 ( US_MR_CHRL_6_BIT | US_MR_PAR_ODD | US_MR_NBSTOP_1_5_BIT )
#define SERIAL_7O15 ( US_MR_CHRL_7_BIT | US_MR_PAR_ODD | US_MR_NBSTOP_1_5_BIT )
#define SERIAL_8O15 ( US_MR_CHRL_8_BIT | US_MR_PAR_ODD | US_MR_NBSTOP_1_5_BIT )

#define SERIAL_5O2 ( US_MR_CHRL_5_BIT | US_MR_PAR_ODD | US_MR_NBSTOP_2_BIT )
#define SERIAL_6O2 ( US_MR_CHRL_6_BIT | US_MR_PAR_ODD | US_MR_NBSTOP_2_BIT )
#define SERIAL_7O2 ( US_MR_CHRL_7_BIT | US_MR_PAR_ODD | US_MR_NBSTOP_2_BIT )
#define SERIAL_8O2 ( US_MR_CHRL_8_BIT | US_MR_PAR_ODD | US_MR_NBSTOP_2_BIT )

#define SERIAL_5M1 ( US_MR_CHRL_5_BIT | US_MR_PAR_MARK | US_MR_NBSTOP_1_BIT )
#define SERIAL_6M1 ( US_MR_CHRL_6_BIT | US_MR_PAR_MARK | US_MR_NBSTOP_1_BIT )
#define SERIAL_7M1 ( US_MR_CHRL_7_BIT | US_MR_PAR_MARK | US_MR_NBSTOP_1_BIT )
#define SERIAL_8M1 ( US_MR_CHRL_8_BIT | US_MR_PAR_MARK | US_MR_NBSTOP_1_BIT )

#define SERIAL_5M15 ( US_MR_CHRL_5_BIT | US_MR_PAR_MARK | US_MR_NBSTOP_1_5_BIT )
#define SERIAL_6M15 ( US_MR_CHRL_6_BIT | US_MR_PAR_MARK | US_MR_NBSTOP_1_5_BIT )
#define SERIAL_7M15 ( US_MR_CHRL_7_BIT | US_MR_PAR_MARK | US_MR_NBSTOP_1_5_BIT )
#define SERIAL_8M15 ( US_MR_CHRL_8_BIT | US_MR_PAR_MARK | US_MR_NBSTOP_1_5_BIT )

#define SERIAL_5M2 ( US_MR_CHRL_5_BIT | US_MR_PAR_MARK | US_MR_NBSTOP_2_BIT )
#define SERIAL_6M2 ( US_MR_CHRL_6_BIT | US_MR_PAR_MARK | US_MR_NBSTOP_2_BIT )
#define SERIAL_7M2 ( US_MR_CHRL_7_BIT | US_MR_PAR_MARK | US_MR_NBSTOP_2_BIT )
#define SERIAL_8M2 ( US_MR_CHRL_8_BIT | US_MR_PAR_MARK | US_MR_NBSTOP_2_BIT )

#define SERIAL_5S1 ( US_MR_CHRL_5_BIT | US_MR_PAR_SPACE | US_MR_NBSTOP_1_BIT )
#define SERIAL_6S1 ( US_MR_CHRL_6_BIT | US_MR_PAR_SPACE | US_MR_NBSTOP_1_BIT )
#define SERIAL_7S1 ( US_MR_CHRL_7_BIT | US_MR_PAR_SPACE | US_MR_NBSTOP_1_BIT )
#define SERIAL_8S1 ( US_MR_CHRL_8_BIT | US_MR_PAR_SPACE | US_MR_NBSTOP_1_BIT )

#define SERIAL_5S15 ( US_MR_CHRL_5_BIT | US_MR_PAR_SPACE | US_MR_NBSTOP_1_5_BIT )
#define SERIAL_6S15 ( US_MR_CHRL_6_BIT | US_MR_PAR_SPACE | US_MR_NBSTOP_1_5_BIT )
#define SERIAL_7S15 ( US_MR_CHRL_7_BIT | US_MR_PAR_SPACE | US_MR_NBSTOP_1_5_BIT )
#define SERIAL_8S15 ( US_MR_CHRL_8_BIT | US_MR_PAR_SPACE | US_MR_NBSTOP_1_5_BIT )

#define SERIAL_5S2 ( US_MR_CHRL_5_BIT | US_MR_PAR_SPACE | US_MR_NBSTOP_2_BIT )
#define SERIAL_6S2 ( US_MR_CHRL_6_BIT | US_MR_PAR_SPACE | US_MR_NBSTOP_2_BIT )
#define SERIAL_7S2 ( US_MR_CHRL_7_BIT | US_MR_PAR_SPACE | US_MR_NBSTOP_2_BIT )
#define SERIAL_8S2 ( US_MR_CHRL_8_BIT | US_MR_PAR_SPACE | US_MR_NBSTOP_2_BIT )

// Defines for 9-bit modes ready for future implementation
/*
#ifdef SERIAL_9BIT_SUPPORT 
#pragma message("NOTE: 9-bit serial mode enabled")
#define SERIAL_9N1  ( US_MR_MODE9 | US_MR_PAR_NO | US_MR_NBSTOP_1_BIT )
#define SERIAL_9N15 ( US_MR_MODE9 | US_MR_PAR_NO | US_MR_NBSTOP_1_5_BIT )
#define SERIAL_9N2  ( US_MR_MODE9 | US_MR_PAR_NO | US_MR_NBSTOP_2_BIT )

#define SERIAL_9E1  ( US_MR_MODE9 | US_MR_PAR_EVEN | US_MR_NBSTOP_1_BIT )
#define SERIAL_9E15 ( US_MR_MODE9 | US_MR_PAR_EVEN | US_MR_NBSTOP_1_5_BIT )
#define SERIAL_9E2  ( US_MR_MODE9 | US_MR_PAR_EVEN | US_MR_NBSTOP_2_BIT )

#define SERIAL_9O1  ( US_MR_MODE9 | US_MR_PAR_ODD | US_MR_NBSTOP_1_BIT )
#define SERIAL_9O15 ( US_MR_MODE9 | US_MR_PAR_ODD | US_MR_NBSTOP_1_5_BIT )
#define SERIAL_9O2  ( US_MR_MODE9 | US_MR_PAR_ODD | US_MR_NBSTOP_2_BIT )

#define SERIAL_9M1  ( US_MR_MODE9 | US_MR_PAR_MARK | US_MR_NBSTOP_1_BIT )
#define SERIAL_9M15 ( US_MR_MODE9 | US_MR_PAR_MARK | US_MR_NBSTOP_1_5_BIT )
#define SERIAL_9M2  ( US_MR_MODE9 | US_MR_PAR_MARK | US_MR_NBSTOP_2_BIT )

#define SERIAL_9S1  ( US_MR_MODE9 | US_MR_PAR_SPACE | US_MR_NBSTOP_1_BIT )
#define SERIAL_9S15 ( US_MR_MODE9 | US_MR_PAR_SPACE | US_MR_NBSTOP_1_5_BIT )
#define SERIAL_9S2  ( US_MR_MODE9 | US_MR_PAR_SPACE | US_MR_NBSTOP_2_BIT )
#endif
*/

class USARTClass : public HardwareSerial
{
  protected:
    RingBuffer *_rx_buffer ;

  protected:
    Usart* _pUsart ;
    IRQn_Type _dwIrq ;
    uint32_t _dwId ;

  public:
    USARTClass( Usart* pUsart, IRQn_Type dwIrq, uint32_t dwId, RingBuffer* pRx_buffer ) ;

    void begin( const uint32_t dwBaudRate ) ;
    void begin( const uint32_t dwBaudRate , const uint32_t config ) ;
    void end( void ) ;
    int available( void ) ;
    int peek( void ) ;
    int read( void ) ;
    void flush( void ) ;
    size_t write( const uint8_t c ) ;

    void IrqHandler( void ) ;

#if defined __GNUC__ /* GCC CS3 */
    using Print::write ; // pull in write(str) and write(buf, size) from Print
#elif defined __ICCARM__ /* IAR Ewarm 5.41+ */
//    virtual void write( const char *str ) ;
//    virtual void write( const uint8_t *buffer, size_t size ) ;
#endif

    operator bool() { return true; }; // USART always active
};

#endif // _USART_CLASS_
