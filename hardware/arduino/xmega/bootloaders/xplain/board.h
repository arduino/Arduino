#ifndef BOARD_H
#define BOARD_H

#include "config.h"

// USARTs

#define USART_0        USARTC0
#define USART_0_PORT   PORTC
#define USART_0_RD_PIN 2
#define USART_0_WR_PIN 3
#define BAUD_RATE      9600UL

#define USART_1        USARTD0
#define USART_1_PORT   PORTD
#define USART_1_RD_PIN 2
#define USART_1_WR_PIN 3
#define BAUD_RATE_1    57600UL

#define USART_2        USARTD1
#define USART_2_PORT   PORTD
#define USART_2_RD_PIN 6
#define USART_2_WR_PIN 7
#define BAUD_RATE_2    57600UL

// BOOT ACTION SELECTION

#define BL_PORT        PORTF
#define BL_DIR         BL_PORT.DIR
#define BL_IN          BL_PORT.IN
#define BL_OUT         BL_PORT.OUT

#define BL_0_PIN       0
#define BL_1_PIN       1
#define BL_2_PIN       2
#define APP_PIN        3


// LED

#define LED_PORT PORTE
#define LED_OUT  LED_PORT.OUT
#define LED      6
#define LED_GND  7

#endif // BOARD_H
