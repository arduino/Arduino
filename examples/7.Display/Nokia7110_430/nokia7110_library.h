//
//  nokia7110_library.h
//  Library header
//  ----------------------------------
//  Developed with embedXcode
//
//  Project Nokia7110_430b
//  Created by Rei VILO on 26/05/12
//  Copyright (c) 2012 http://embeddedcomputing.weebly.com
//

// Core library
#if defined (__AVR_ATmega328P__) || defined(__AVR_ATmega2560__) // Arduino specific
#include "WProgram.h" // #include "Arduino.h" for Arduino 1.0
#elif defined(__32MX320F128H__) || defined(__32MX795F512L__) // chipKIT specific 
#include "WProgram.h"
#elif defined(__AVR_ATmega644P__) // Wiring specific
#include "Wiring.h"
#elif defined(__MSP430G2452__) || defined(__MSP430G2553__) || defined(__MSP430G2231__) // LaunchPad specific
#include "Energia.h"
#elif defined(MCU_STM32F103RB) || defined(MCU_STM32F103ZE) || defined(MCU_STM32F103CB) || defined(MCU_STM32F103RE) // Maple specific
#include "WProgram.h"	
#endif

#ifndef LCD_430_nokia7110_library_h
#define LCD_430_nokia7110_library_h

//
//namespace nokia7110 {
    
    unsigned char PNONE;
    
    typedef enum {
        lcd_command = 0,        // Array of one or more commands
        lcd_data = 1,           // Array of one or more bytes of data
        lcd_data_repeat = 2     // One byte of data repeated
    } lcd_cmd_type;
    
    template <volatile unsigned char &_SP, unsigned char _CLK, unsigned char _DATA, volatile unsigned char &_CP, unsigned char _DC, volatile unsigned char &_EP, unsigned char _CE, volatile unsigned char &_RP, unsigned char _RST, unsigned _RD>
    struct Nokia7110
    {
        void write(const unsigned char *cmd, unsigned len, const lcd_cmd_type type = lcd_data);
        void reset(void);
        void init(void);
        void home(void);
        void pos(unsigned char x, unsigned char y);
        void clear(unsigned char x = 0);
        void fill(unsigned x, unsigned y, unsigned w, unsigned h, unsigned char z);
        void bitmap(const unsigned char *bmp, signed char x, signed char y, unsigned char w, unsigned char h);
        inline void bitmap(const unsigned char *bmp, signed char x, signed char y) { bitmap(bmp + 2, x, y, bmp[0], bmp[1]); };
        void print(char c);
        inline void print(unsigned char x, unsigned char y, char c) { pos(x, y); print(c); };
        void print(const char *s);
        inline void print(unsigned char x, unsigned char y, const char *s) { pos(x, y); print(s); };
        void print(const char *s, unsigned char m);
        void printv(unsigned char x, unsigned char y, char *s);
        void pd12(unsigned n, unsigned x, unsigned y);
    };
    
    template <volatile unsigned char &_SP, unsigned char _CLK, unsigned char _DATA, volatile unsigned char &_CP, unsigned char _DC, volatile unsigned char &_EP, unsigned char _CE, volatile unsigned char &_RP, unsigned char _RST, unsigned _RD>
    void Nokia7110<_SP, _CLK, _DATA, _CP, _DC, _EP, _CE, _RP, _RST, _RD>::write(const unsigned char *cmd, unsigned len, const lcd_cmd_type type)
    {
        register unsigned mask;
        
        if (&_EP != &PNONE) _EP &= ~_CE;
        do {
            mask = 0x0080;
            do {
                if (*cmd & mask) {
                    _SP |= _DATA;
                    _SP &= ~_CLK;
                } else {
                    _SP &= ~(_CLK | _DATA);
                }
                _SP |= _CLK;
                mask >>= 1;
            } while (!(mask & 1));
            if (&_CP == &PNONE) {
                __delay_cycles(_DC);
            } else {
                if (!type) _CP &= ~_DC;
            }
            if (*cmd & mask) {
                _SP |= _DATA;
                _SP &= ~_CLK;
            } else {
                _SP &= ~(_CLK | _DATA);
            }
            _SP |= _CLK;
            if (&_CP != &PNONE) _CP |= _DC;
            if (!(type & 2)) ++cmd;
        } while (--len);
        if (&_EP != &PNONE) _EP |= _CE;
    }
    
    template <volatile unsigned char &_SP, unsigned char _CLK, unsigned char _DATA, volatile unsigned char &_CP, unsigned char _DC, volatile unsigned char &_EP, unsigned char _CE, volatile unsigned char &_RP, unsigned char _RST, unsigned _RD>
    void Nokia7110<_SP, _CLK, _DATA, _CP, _DC, _EP, _CE, _RP, _RST, _RD>::reset(void)
    {
        if (&_RP == &PNONE) {
            // --- Set initial state of CLK, DC and CE as needed
            // * = output used for reset
            if (&_CP == &PNONE) {
                if (&_EP != &PNONE) {        // CLK*, DATA, CE
                    _EP |= _CE;
                } // else                   // CLK*, DATA
            } else {
                if (&_EP != &PNONE) {        // CLK, DATA, DC*, CE
                    if (&_SP == &_EP) {
                        _SP |= (_CLK | _CE);
                    } else {
                        _SP |= _CLK;
                        _EP |= _CE;
                    }
                } else {                    // CLK, DATA, DC*
                    _SP |= _CLK;
                }
            }
            // --- Reset pulse on CLK or DC as needed
            if (&_CP == &PNONE) {            // No DC port, use CLK to reset
                _SP &= ~_CLK;
                __delay_cycles(_RD);
                _SP |= _CLK;
            } else {                        // Use DC to reset
                _CP &= ~_DC;
                __delay_cycles(_RD);
                _CP |= _DC;
            }
        } else {
            _RP &= ~_RST;
            if (&_EP != &PNONE) {
                if (&_SP == &_EP) {
                    _SP |= (_CLK | _CE);
                } else {
                    _SP |= _CLK;
                    _EP |= _CE;
                }
            } else {
                _SP |= _CLK;
            }
            __delay_cycles(_RD);
            _RP |= _RST;
        }
        __delay_cycles(_RD);
    }
    
    template <volatile unsigned char &_SP, unsigned char _CLK, unsigned char _DATA, volatile unsigned char &_CP, unsigned char _DC, volatile unsigned char &_EP, unsigned char _CE, volatile unsigned char &_RP, unsigned char _RST, unsigned _RD>
    void Nokia7110<_SP, _CLK, _DATA, _CP, _DC, _EP, _CE, _RP, _RST, _RD>::init(void)
    {
        static const unsigned char init[] = {
            0xA6, //Display: Normal
            0xA3, //LCD Bias Settings: 1/7
            0xA1, //ADC Selection: Reverse
            0xC0, //Common Output: Normal Direction
            //0xC8, //Common Output: Upside Down
            0x22, //Set the V5 output Voltage
            0x81, //Set Electronic Volume Register
            0x2E, //Power Controller Set
            // Booster circuit: ON
            // Voltage regulator circuit: ON
            // Voltage follower circuit: OFF
            0x2F, //Power Controller Set
            // Voltage follower circuit: ON
            0xE3, //Non-OPeration Command
            0x40, //Set the start line
            0xAF, //LCD On
            //0xA5, //Display All Points: ON
            0xA4, //Display All Points: NORMAL
        };
        
        write(init, sizeof(init), lcd_command);
    }
    
    template <volatile unsigned char &_SP, unsigned char _CLK, unsigned char _DATA, volatile unsigned char &_CP, unsigned char _DC, volatile unsigned char &_EP, unsigned char _CE, volatile unsigned char &_RP, unsigned char _RST, unsigned _RD>
    void Nokia7110<_SP, _CLK, _DATA, _CP, _DC, _EP, _CE, _RP, _RST, _RD>::home(void)
    {
        static const unsigned char home[] = { 0xB0, 0x11, 0x02 };
        write(home, sizeof(home), lcd_command);
    }
    
    template <volatile unsigned char &_SP, unsigned char _CLK, unsigned char _DATA, volatile unsigned char &_CP, unsigned char _DC, volatile unsigned char &_EP, unsigned char _CE, volatile unsigned char &_RP, unsigned char _RST, unsigned _RD>
    void Nokia7110<_SP, _CLK, _DATA, _CP, _DC, _EP, _CE, _RP, _RST, _RD>::pos(unsigned char x, unsigned char y)
    {
        unsigned char c[3];
        x += 18;
        c[0] = 0xB0 | y;
        c[1] = 0x10 | (x >> 4);
        c[2] = x & 0x0F;
        write(c, sizeof(c), lcd_command);
    }
    
    template <volatile unsigned char &_SP, unsigned char _CLK, unsigned char _DATA, volatile unsigned char &_CP, unsigned char _DC, volatile unsigned char &_EP, unsigned char _CE, volatile unsigned char &_RP, unsigned char _RST, unsigned _RD>
    void Nokia7110<_SP, _CLK, _DATA, _CP, _DC, _EP, _CE, _RP, _RST, _RD>::clear(unsigned char x)
    {
        for(unsigned y = 0; y < 9; ++y) {
            pos(0, y);
            write(&x, 96, lcd_data_repeat);
        }
    }
    
    template <volatile unsigned char &_SP, unsigned char _CLK, unsigned char _DATA, volatile unsigned char &_CP, unsigned char _DC, volatile unsigned char &_EP, unsigned char _CE, volatile unsigned char &_RP, unsigned char _RST, unsigned _RD>
    void Nokia7110<_SP, _CLK, _DATA, _CP, _DC, _EP, _CE, _RP, _RST, _RD>::fill(unsigned x, unsigned y, unsigned w, unsigned h, unsigned char z)
    {
        unsigned yy = y + h;
        unsigned char c[3];
        x += 18;
        c[1] = 0x10 | (x >> 4);
        c[2] = (x & 0x0F);
        for(;y < yy; ++y) {
            c[0] = 0xB0 | y;
            write(c, sizeof(c), lcd_command);
            write(&z, w, lcd_data_repeat);
        }
    }
    
    template <volatile unsigned char &_SP, unsigned char _CLK, unsigned char _DATA, volatile unsigned char &_CP, unsigned char _DC, volatile unsigned char &_EP, unsigned char _CE, volatile unsigned char &_RP, unsigned char _RST, unsigned _RD>
    void Nokia7110<_SP, _CLK, _DATA, _CP, _DC, _EP, _CE, _RP, _RST, _RD>::bitmap(const unsigned char *bmp, signed char x, signed char y, unsigned char w, unsigned char h)
    {
        unsigned char c[3];
        unsigned char ww;
        if (x < 0) {
            ww = w + x;
            bmp -= x;
            x = 0;
        } else if (x + w >= 96) {
            ww = (96 - x);
        } else {
            ww = w;
        }
        x += 18;
        c[0] = 0xB0 | y;
        c[1] = 0x10 | (x >> 4);
        c[2] = x & 0x0F;
        while (h--) {
            write(c, sizeof(c), lcd_command);
            write(bmp, ww);
            bmp += w;
            ++c[0];
        }
    }
    
    static const unsigned char font[96][5] = {
        0x00, 0x00, 0x00, 0x00, 0x00, //
        0x00, 0x00, 0x5F, 0x00, 0x00, // !
        0x00, 0x07, 0x00, 0x07, 0x00, // "
        0x14, 0x7F, 0x14, 0x7F, 0x14, // #
        0x24, 0x2A, 0x7F, 0x2A, 0x12, // $
        0x23, 0x13, 0x08, 0x64, 0x62, // %
        0x36, 0x49, 0x56, 0x20, 0x50, // &
        0x00, 0x08, 0x07, 0x03, 0x00, // '
        0x00, 0x1C, 0x22, 0x41, 0x00, // (
        0x00, 0x41, 0x22, 0x1C, 0x00, // )
        0x2A, 0x1C, 0x7F, 0x1C, 0x2A, // *
        0x08, 0x08, 0x3E, 0x08, 0x08, // +
        0x00, 0x40, 0x38, 0x18, 0x00, // ,
        0x08, 0x08, 0x08, 0x08, 0x08, // -
        0x00, 0x00, 0x60, 0x60, 0x00, // .
        0x20, 0x10, 0x08, 0x04, 0x02, // /
        0x3E, 0x51, 0x49, 0x45, 0x3E, // 0
        0x00, 0x42, 0x7F, 0x40, 0x00, // 1
        0x42, 0x61, 0x51, 0x49, 0x46, // 2
        0x21, 0x41, 0x49, 0x4D, 0x33, // 3
        0x18, 0x14, 0x12, 0x7F, 0x10, // 4
        0x27, 0x45, 0x45, 0x45, 0x39, // 5
        0x3C, 0x4A, 0x49, 0x49, 0x30, // 6
        0x41, 0x21, 0x11, 0x09, 0x07, // 7
        0x36, 0x49, 0x49, 0x49, 0x36, // 8
        0x06, 0x49, 0x49, 0x29, 0x1E, // 9
        0x00, 0x00, 0x14, 0x00, 0x00, // :
        0x00, 0x00, 0x40, 0x34, 0x00, // ;
        0x00, 0x08, 0x14, 0x22, 0x41, // <
        0x14, 0x14, 0x14, 0x14, 0x14, // =
        0x00, 0x41, 0x22, 0x14, 0x08, // >
        0x02, 0x01, 0x51, 0x09, 0x06, // ?
        0x3E, 0x41, 0x5D, 0x59, 0x4E, // @
        0x7C, 0x12, 0x11, 0x12, 0x7C, // A
        0x7F, 0x49, 0x49, 0x49, 0x36, // B
        0x3E, 0x41, 0x41, 0x41, 0x22, // C
        0x7F, 0x41, 0x41, 0x41, 0x3E, // D
        0x7F, 0x49, 0x49, 0x49, 0x41, // E
        0x7F, 0x09, 0x09, 0x09, 0x01, // F
        0x3E, 0x41, 0x49, 0x49, 0x7A, // G
        0x7F, 0x08, 0x08, 0x08, 0x7F, // H
        0x00, 0x41, 0x7F, 0x41, 0x00, // I
        0x20, 0x40, 0x41, 0x3F, 0x01, // J
        0x7F, 0x08, 0x14, 0x22, 0x41, // K
        0x7F, 0x40, 0x40, 0x40, 0x40, // L
        0x7F, 0x02, 0x1C, 0x02, 0x7F, // M
        0x7F, 0x04, 0x08, 0x10, 0x7F, // N
        0x3E, 0x41, 0x41, 0x41, 0x3E, // O
        0x7F, 0x09, 0x09, 0x09, 0x06, // P
        0x3E, 0x41, 0x51, 0x21, 0x5E, // Q
        0x7F, 0x09, 0x19, 0x29, 0x46, // R
        0x26, 0x49, 0x49, 0x49, 0x32, // S
        0x01, 0x01, 0x7F, 0x01, 0x01, // T
        0x3F, 0x40, 0x40, 0x40, 0x3F, // U
        0x1F, 0x20, 0x40, 0x20, 0x1F, // V
        0x3F, 0x40, 0x38, 0x40, 0x3F, // W
        0x63, 0x14, 0x08, 0x14, 0x63, // X
        0x03, 0x04, 0x78, 0x04, 0x03, // Y
        0x61, 0x51, 0x49, 0x45, 0x43, // Z
        0x00, 0x7F, 0x41, 0x41, 0x41, // [
        0x02, 0x04, 0x08, 0x10, 0x20, // '\'
        0x00, 0x41, 0x41, 0x41, 0x7F, // ]
        0x04, 0x02, 0x01, 0x02, 0x04, // ^
        0x80, 0x80, 0x80, 0x80, 0x80, // _
        0x00, 0x03, 0x07, 0x08, 0x00, // '
        0x20, 0x54, 0x54, 0x54, 0x78, // a
        0x7F, 0x28, 0x44, 0x44, 0x38, // b
        0x38, 0x44, 0x44, 0x44, 0x28, // c
        0x38, 0x44, 0x44, 0x28, 0x7F, // d
        0x38, 0x54, 0x54, 0x54, 0x18, // e
        0x00, 0x08, 0x7E, 0x09, 0x02, // f
        0x18, 0xA4, 0xA4, 0xA4, 0x7C, // g
        0x7F, 0x08, 0x04, 0x04, 0x78, // h
        0x00, 0x44, 0x7D, 0x40, 0x00, // i
        0x00, 0x20, 0x40, 0x40, 0x3D, // j
        0x00, 0x7F, 0x10, 0x28, 0x44, // k
        0x00, 0x41, 0x7F, 0x40, 0x00, // l
        0x7C, 0x04, 0x78, 0x04, 0x78, // m
        0x7C, 0x08, 0x04, 0x04, 0x78, // n
        0x38, 0x44, 0x44, 0x44, 0x38, // o
        0xFC, 0x18, 0x24, 0x24, 0x18, // p
        0x18, 0x24, 0x24, 0x18, 0xFC, // q
        0x7C, 0x08, 0x04, 0x04, 0x08, // r
        0x48, 0x54, 0x54, 0x54, 0x24, // s
        0x04, 0x04, 0x3F, 0x44, 0x24, // t
        0x3C, 0x40, 0x40, 0x20, 0x7C, // u
        0x1C, 0x20, 0x40, 0x20, 0x1C, // v
        0x3C, 0x40, 0x30, 0x40, 0x3C, // w
        0x44, 0x28, 0x10, 0x28, 0x44, // x
        0x4C, 0x90, 0x90, 0x90, 0x7C, // y
        0x44, 0x64, 0x54, 0x4C, 0x44, // z
        0x00, 0x08, 0x36, 0x41, 0x00, // {
        0x00, 0x00, 0x77, 0x00, 0x00, // |
        0x00, 0x41, 0x36, 0x08, 0x00, // }
        0x02, 0x01, 0x02, 0x04, 0x02, // ~
        0x00, 0x06, 0x09, 0x09, 0x06, // degrees
    };
    
    template <volatile unsigned char &_SP, unsigned char _CLK, unsigned char _DATA, volatile unsigned char &_CP, unsigned char _DC, volatile unsigned char &_EP, unsigned char _CE, volatile unsigned char &_RP, unsigned char _RST, unsigned _RD>
    void Nokia7110<_SP, _CLK, _DATA, _CP, _DC, _EP, _CE, _RP, _RST, _RD>::print(char c)
    {
        write(&font[c - 32][0], 5);
        write(&font[0][0], 1);
    }
    
    template <volatile unsigned char &_SP, unsigned char _CLK, unsigned char _DATA, volatile unsigned char &_CP, unsigned char _DC, volatile unsigned char &_EP, unsigned char _CE, volatile unsigned char &_RP, unsigned char _RST, unsigned _RD>
    void Nokia7110<_SP, _CLK, _DATA, _CP, _DC, _EP, _CE, _RP, _RST, _RD>::print(const char *s)
    {
        while (*s) {
            write(&font[*s - 32][0], 5);
            write(&font[0][0], 1);
            ++s;
        }
    }
    
    template <volatile unsigned char &_SP, unsigned char _CLK, unsigned char _DATA, volatile unsigned char &_CP, unsigned char _DC, volatile unsigned char &_EP, unsigned char _CE, volatile unsigned char &_RP, unsigned char _RST, unsigned _RD>
    void Nokia7110<_SP, _CLK, _DATA, _CP, _DC, _EP, _CE, _RP, _RST, _RD>::print(const char *s, unsigned char m)
    {
        unsigned char c;
        while (*s) {
            c = font[*s - 32][0] ^ m; write(&c, 1);
            c = font[*s - 32][1] ^ m; write(&c, 1);
            c = font[*s - 32][2] ^ m; write(&c, 1);
            c = font[*s - 32][3] ^ m; write(&c, 1);
            c = font[*s - 32][4] ^ m; write(&c, 1);
            write(&m, 1);
            ++s;
        }
    }
    
    template <volatile unsigned char &_SP, unsigned char _CLK, unsigned char _DATA, volatile unsigned char &_CP, unsigned char _DC, volatile unsigned char &_EP, unsigned char _CE, volatile unsigned char &_RP, unsigned char _RST, unsigned _RD>
    void Nokia7110<_SP, _CLK, _DATA, _CP, _DC, _EP, _CE, _RP, _RST, _RD>::printv(unsigned char x, unsigned char y, char *s)
    {
        while (*s) {
            pos(x, y);
            ++y;
            write(&font[*s - 32][0], 5);
            write(&font[0][0], 1);
            ++s;
        }
    }
    
    static const unsigned char num11x16[19][11 * 2] = {
        0x00,0xF0,0xFC,0xFE,0x06,0x02,0x06,0xFE,0xFC,0xF0,0x00, // 0
        0x00,0x07,0x1F,0x3F,0x30,0x20,0x30,0x3F,0x1F,0x07,0x00,
        0x00,0x00,0x08,0x0C,0xFC,0xFE,0xFE,0x00,0x00,0x00,0x00, // 1
        0x00,0x20,0x20,0x20,0x3F,0x3F,0x3F,0x20,0x20,0x20,0x00,
        0x00,0x0C,0x0E,0x06,0x02,0x02,0x86,0xFE,0x7C,0x38,0x00, // 2
        0x00,0x30,0x38,0x3C,0x36,0x33,0x31,0x30,0x30,0x38,0x00,
        0x00,0x0C,0x0E,0x86,0x82,0x82,0xC6,0xFE,0x7C,0x38,0x00, // 3
        0x00,0x18,0x38,0x30,0x20,0x20,0x31,0x3F,0x1F,0x0E,0x00,
        0x00,0x00,0xC0,0x20,0x18,0x04,0xFE,0xFE,0xFE,0x00,0x00, // 4
        0x00,0x03,0x02,0x02,0x02,0x22,0x3F,0x3F,0x3F,0x22,0x02,
        0x00,0x00,0x7E,0x7E,0x46,0x46,0xC6,0xC6,0x86,0x00,0x00, // 5
        0x00,0x18,0x38,0x30,0x20,0x20,0x30,0x3F,0x1F,0x0F,0x00,
        0x00,0xC0,0xF0,0xF8,0xFC,0x4C,0xC6,0xC2,0x82,0x00,0x00, // 6
        0x00,0x0F,0x1F,0x3F,0x30,0x20,0x30,0x3F,0x1F,0x0F,0x00,
        0x00,0x06,0x06,0x06,0x06,0x06,0xC6,0xF6,0x3E,0x0E,0x00, // 7
        0x00,0x00,0x00,0x30,0x3C,0x0F,0x03,0x00,0x00,0x00,0x00,
        0x00,0x38,0x7C,0xFE,0xC6,0x82,0xC6,0xFE,0x7C,0x38,0x00, // 8
        0x00,0x0E,0x1F,0x3F,0x31,0x20,0x31,0x3F,0x1F,0x0E,0x00,
        0x00,0x78,0xFC,0xFE,0x86,0x02,0x86,0xFE,0xFC,0xF8,0x00, // 9
        0x00,0x00,0x00,0x21,0x21,0x31,0x1D,0x1F,0x0F,0x03,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // <space>
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x70,0x70,0x70,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // :
        0x00,0x0E,0x0E,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // .
        0x00,0x38,0x38,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0xC0,0x30,0x0C,0x00,0x00,0x00,0x00, // /
        0x00,0x30,0x0C,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80, // -
        0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
        0x00,0x18,0x3C,0x66,0x66,0x3C,0x18,0x00,0x00,0x00,0x00, // <degrees>
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0xF0,0xF8,0x0C,0x06,0x02,0x02,0x02,0x02,0x0E,0x0C,0x00, // C
        0x03,0x07,0x0C,0x18,0x10,0x10,0x10,0x10,0x1C,0x0C,0x00,
        0xFE,0xFE,0x42,0x42,0x42,0x42,0x42,0x42,0x00,0x00,0x00, // F
        0x1F,0x1F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0xFE,0xFE,0x40,0xE0,0xB0,0x18,0x0C,0x06,0x02,0x00,0x00, // K
        0x1F,0x1F,0x00,0x00,0x01,0x03,0x06,0x0C,0x18,0x10,0x00
    };
    
    template <volatile unsigned char &_SP, unsigned char _CLK, unsigned char _DATA, volatile unsigned char &_CP, unsigned char _DC, volatile unsigned char &_EP, unsigned char _CE, volatile unsigned char &_RP, unsigned char _RST, unsigned _RD>
    void Nokia7110<_SP, _CLK, _DATA, _CP, _DC, _EP, _CE, _RP, _RST, _RD>::pd12(unsigned n, unsigned x, unsigned y)
    {
        pos(x, y);   write(num11x16[n], 11, lcd_data);
        pos(x, ++y); write(num11x16[n] + 11, 11, lcd_data);
    }
    
//} // namespace


#endif
