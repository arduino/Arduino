#ifndef BOARD_INLINES_H
#define BOARD_INLINES_H

// Functions

void app_start(void); // TODO: Move this to a #include

static inline void SetBootloaderPinDirections() {
    #if defined BL_PORT
        PORTCFG.MPCMASK = 0xFF; //do this for all pins of the following command
        BL_PORT.PIN0CTRL = WIRED_AND_PULL;
    #endif

    #if defined BL_0_PIN
        BL_DIR &= ~_BV(BL_0_PIN);
        BL_OUT |=  _BV(BL_0_PIN);
    #endif

    #if defined BL_1_PIN
        BL_DIR &= ~_BV(BL_1_PIN);
        BL_OUT |=  _BV(BL_1_PIN);
    #endif

    #if defined BL_2_PIN
        BL_DIR &= ~_BV(BL_2_PIN);
        BL_OUT |=  _BV(BL_2_PIN);
    #endif

    #if defined APP_PIN
        BL_DIR &= ~_BV(APP_PIN);
        BL_OUT |=  _BV(APP_PIN);
    #endif
}

static inline uint8_t GetBootUart() {

    #if TARGET_xplain == TARGET
        // Light LED's next to buttons that do something.
        LED_PORT.OUT = 0xF0;
    #endif

    #if defined APP_PIN
        while (1) {
    #endif

    /* check which UART should be used for booting */
    #if defined BL_0_PIN
        if(bit_is_clear(BL_IN, BL_0_PIN)) {
            return 0;
        }
    #endif
    #if defined BL_1_PIN
        if(bit_is_clear(BL_IN, BL_1_PIN)) {
            return 1;
        }
    #endif
    #if defined BL_2_PIN
        if(bit_is_clear(BL_IN, BL_2_PIN)) {
            return 2;
        }
    #endif
        /* no UART was selected */
    #if START_APP_IF_FLASH_PROGRAMED
        /* if flash is programmed already, start app, otherwise, start bootloader */
        if(pgm_read_byte_near(0x0000) == 0xFF) {
            app_start();
        }
    #endif
    #if defined APP_PIN
        if(bit_is_clear(BL_IN, APP_PIN)) {
            app_start();
        }
    #endif

    #if defined APP_PIN
        }
    #endif

    /* default to uart 0 */
    return 0;
}

static inline void InitBootUart(int bootuart) {
    // bootuart should be set, if not, start app.
    if ( -1 == bootuart ) {
        app_start();
    }

    #if defined BL_0_PIN
        LED_PORT.OUT = ~( 1 << bootuart );
    #endif


    USART0_SET_DIR();
    USART0_SET_BAUD(BAUD_RATE);
    USART0_RX_ENABLE();
    USART0_TX_ENABLE();
    USART0_SET_TO_8N1();

#if defined USART_1
    USART1_SET_DIR();
    USART1_SET_BAUD(BAUD_RATE_1);
    USART1_RX_ENABLE();
    USART1_TX_ENABLE();
    USART1_SET_TO_8N1();
#endif

#if defined USART_2
    USART2_SET_DIR();
    USART2_SET_BAUD(BAUD_RATE_2);
    USART2_RX_ENABLE();
    USART2_TX_ENABLE();
    USART2_SET_TO_8N1();
#endif
}

static inline void SuppressLineNoise() {
    #if LINE_NOISE_PIN
        /* Enable internal pull-up resistor on pin D0 (RX), in order
        to supress line noise that prevents the bootloader from
        timing out (DAM: 20070509) */
        DDR_LINE_NOISE  &= ~_BV(LINE_NOISE_PIN);
        PORT_LINE_NOISE |= _BV(LINE_NOISE_PIN);
    #endif
}

void InitLed(void)
{
    /* set LED pin as output */
    PORTCFG.MPCMASK = 0xFF; //do this for all pins of the following command
    LED_PORT.PIN0CTRL = WIRED_AND_PULL;

    LED_PORT.DIR      = 0xFF;
    LED_PORT.OUT      = 0xFF;
}

static inline void flash_led(uint8_t count)
{
    while (count--) {
        LED_PORT.OUTTGL = 0xFF;
        delay_ms(200);
        LED_PORT.OUTTGL = 0xFF;
        delay_ms(200);
    }
}

#endif // BOARD_INLINES_H
