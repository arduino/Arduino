#ifndef BOARD_H
#define BOARD_H

#include "config.h"

// USARTs

#define USART_0        USARTF1
#define USART_0_PORT   PORTF
#define USART_0_RD_PIN 6
#define USART_0_WR_PIN 7
#if !defined BAUD_RATE
 #define BAUD_RATE      57600L
#endif

// LED

#define LED_PORT       PORTE
#define LED_DDR        LED_PORT.DIR
#define LED_OUT        LED_PORT.OUT
#define LED            6
#define LED_GND        7

#endif // BOARD_H

