//
// LCD_screen_font.cpp
// Class library C++ code
// ----------------------------------
// Developed with embedXcode
// http://embedXcode.weebly.com
//
// Project LCD_screen_font_main
//
// Created by Rei VILO, May 30, 2013
// embedXcode.weebly.com
//
//
// Copyright © Rei VILO, 2013
// License All rights reserved
//
// See LCD_screen_font.h and ReadMe.txt for references
//
// Library header
#include "LCD_screen_font.h"
LCD_screen_font::LCD_screen_font()
{
    ;
}
void LCD_screen_font::setFontSize(uint8_t size)
{
    if (size < MAX_FONT_SIZE) _fontSize = size;
    else _fontSize = MAX_FONT_SIZE -1;
}
uint8_t LCD_screen_font::fontMax()
{
    return MAX_FONT_SIZE;
}
uint8_t LCD_screen_font::fontSizeX()
{
#if (MAX_FONT_SIZE > 0)
    if (_fontSize == 0) return 6;
#if (MAX_FONT_SIZE > 1)
    else if (_fontSize == 1) return 8;
#if (MAX_FONT_SIZE > 2)
    else if (_fontSize == 2) return 12;
#if (MAX_FONT_SIZE > 3)
    else if (_fontSize == 3) return 16;
#endif
#endif
#endif
#endif
    else return 0;
}
uint8_t LCD_screen_font::fontSizeY()
{
#if (MAX_FONT_SIZE > 0)
    if (_fontSize == 0) return 8;
#if (MAX_FONT_SIZE > 1)
    else if (_fontSize == 1) return 12;
#if (MAX_FONT_SIZE > 2)
    else if (_fontSize == 2) return 16;
#if (MAX_FONT_SIZE > 3)
    else if (_fontSize == 3) return 24;
#endif
#endif
#endif
#endif
    else return 0;
}
uint8_t LCD_screen_font::_getCharacter(uint8_t c, uint8_t i) {
#if defined(ENERGIA)
#if (MAX_FONT_SIZE > 0)
    if (_fontSize == 0) return Terminal6x8e[c][i];
#if (MAX_FONT_SIZE > 1)
    else if (_fontSize == 1) return Terminal8x12e[c][i];
#if (MAX_FONT_SIZE > 2)
    else if (_fontSize == 2) return Terminal12x16e[c][i];
#if (MAX_FONT_SIZE > 3)
    else if (_fontSize == 3) return Terminal16x24e[c][i];
#endif
#endif
#endif
#endif
    else return 0;
#else
#if (MAX_FONT_SIZE > 0)
    if (_fontSize == 0) return pgm_read_byte(&Terminal6x8e[c][i]);
#if (MAX_FONT_SIZE > 1)
    else if (_fontSize == 1) return pgm_read_byte(&Terminal8x12e[c][i]);
#if (MAX_FONT_SIZE > 2)
    else if (_fontSize == 2) return pgm_read_byte(&Terminal12x16e[c][i]);
#if (MAX_FONT_SIZE > 3)
    else if (_fontSize == 3) return pgm_read_byte(&Terminal16x24e[c][i]);
#endif
#endif
#endif
#endif
    else return 0;
#endif
}
void LCD_screen_font::gText(uint16_t x0, uint16_t y0,
                            String s,
                            uint16_t textColour, uint16_t backColour,
                            uint8_t ix, uint8_t iy)
{
    uint8_t c;
    uint8_t line, line1, line2, line3;
    uint16_t x, y;
    uint8_t i, j, k;
    if ((ix > 1) || (iy > 1) || !_fontSolid) {
        if ((_fontSize == 0) && ((ix > 1) || (iy > 1))) {
            bool oldPenSolid = _penSolid;
            setPenSolid(true);
            for (k=0; k<s.length(); k++) {
                x = x0 + 6 * k * ix;
                y = y0;
                c = s.charAt(k)-' ';
                for ( i=0; i<6; i++ ) {
                    line = _getCharacter(c, i);
                    for ( j = 0; j<8; j++) {
                        if (bitRead(line, j)) rectangle(x+i*ix, y+j*iy, x+i*ix+ix-1, y+j*iy+iy-1, textColour);
                        else if (_fontSolid)  rectangle(x+i*ix, y+j*iy, x+i*ix+ix-1, y+j*iy+iy-1, backColour);
                    }
                }
            }
            setPenSolid(oldPenSolid);
        } else {
#if (MAX_FONT_SIZE > 0)
            if (_fontSize == 0) {
                for (k=0; k<s.length(); k++) {
                    c = s.charAt(k)-' ';
                    for (i=0; i<6; i++) {
                        line = _getCharacter(c, i);
                        for (j=0; j<8; j++)
                            if (bitRead(line, j)) point(x0 + 6*k + i, y0 + j, textColour);
                            else if (_fontSolid)  point(x0 + 6*k + i, y0 + j, backColour);
                    }
                }
            }
#if (MAX_FONT_SIZE > 1)
            else if (_fontSize == 1) {
                for (k=0; k<s.length(); k++) {
                    c = s.charAt(k)-' ';
                    for (i=0; i<8; i++) {
                        line = _getCharacter(c, 2*i);
                        line1 =_getCharacter(c, 2*i+1);
                        for (j=0; j<8; j++) {
                            if (bitRead(line, j)) point(x0 + 8*k + i, y0 + j, textColour);
                            else if (_fontSolid)  point(x0 + 8*k + i, y0 + j, backColour);
                            if (bitRead(line1, j))  point(x0 + 8*k + i, y0 +8 + j, textColour);
                            else if ((_fontSolid) && (j<4)) point(x0 + 8*k + i, y0 +8 + j, backColour);
                        }
                    }
                }
            }
#if (MAX_FONT_SIZE > 2)
            else if (_fontSize == 2) {
                for (k=0; k<s.length(); k++) {
                    c = s.charAt(k)-' ';
                    for (i=0; i<12; i++) {
                        line = _getCharacter(c, 2*i);
                        line1 =_getCharacter(c, 2*i+1);
                        for (j=0; j<8; j++) {
                            if (bitRead(line, j))  point(x0 + 12*k + i, y0 + j,    textColour);
                            else if (_fontSolid)   point(x0 + 12*k + i, y0 + j,    backColour);
                            if (bitRead(line1, j)) point(x0 + 12*k + i, y0 +8 + j, textColour);
                            else if (_fontSolid)   point(x0 + 12*k + i, y0 +8 + j, backColour);
                        }
                    }
                }
            }
#if (MAX_FONT_SIZE > 3)
            else if (_fontSize == 3) {
                for (k=0; k<s.length(); k++) {
                    c = s.charAt(k)-' ';
                    for (i=0; i<16; i++) {
                        line  =_getCharacter(c, 3*i);
                        line1 =_getCharacter(c, 3*i+1);
                        line2 =_getCharacter(c, 3*i+2);
                        for (j=0; j<8; j++) {
                            if (bitRead(line, j))  point(x0 + 16*k + i, y0 + j,     textColour);
                            else if (_fontSolid)   point(x0 + 16*k + i, y0 + j,     backColour);
                            if (bitRead(line1, j)) point(x0 + 16*k + i, y0 +8 + j,  textColour);
                            else if (_fontSolid)   point(x0 + 16*k + i, y0 +8 + j,  backColour);
                            if (bitRead(line2, j)) point(x0 + 16*k + i, y0 +16 + j, textColour);
                            else if (_fontSolid)   point(x0 + 16*k + i, y0 +16 + j, backColour);
                        }
                    }
                }
            }
#endif
#endif
#endif
#endif
        }
    } else {
        uint8_t c;
        uint8_t line, line1;
        uint16_t x, y;
        uint8_t i, j, k;
        uint8_t highTextColour = highByte(textColour);
        uint8_t lowTextColour = lowByte(textColour);
        uint8_t highBackColour = highByte(backColour);
        uint8_t lowBackColour = lowByte(backColour);
#if (MAX_FONT_SIZE > 0)
        if (_fontSize == 0) {
            for (k=0; k<s.length(); k++) {
                c = s.charAt(k)-' ';
                _setWindow(x0 +fontSizeX()*k, y0, x0 +fontSizeX()*(k+1)-1, y0+fontSizeY()-1);
                for (j=0; j<8; j++) {
                    for (i=0; i<6; i++) {
                        line = _getCharacter(c, i);
                        if (bitRead(line, j)) {
                            _writeData88(highTextColour, lowTextColour);
                        } else {
                            _writeData88(highBackColour, lowBackColour);
                        }
                    }
                }
            }
        }
#if (MAX_FONT_SIZE > 1)
        else if (_fontSize == 1) {
            for (k=0; k<s.length(); k++) {
                c = s.charAt(k)-' ';
                _setWindow(x0 +fontSizeX()*k, y0, x0 +fontSizeX()*(k+1)-1, y0+fontSizeY()-1);
                for (j=0; j<8; j++) {
                    for (i=0; i<8; i++) {
                        line = _getCharacter(c, 2*i);
                        if (bitRead(line, j)) {
                            _writeData88(highTextColour, lowTextColour);
                        } else {
                            _writeData88(highBackColour, lowBackColour);
                        }
                    }
                }
                for (j=0; j<4; j++) {
                    for (i=0; i<8; i++) {
                        line = _getCharacter(c, 2*i+1);
                        if (bitRead(line, j)) {
                            _writeData88(highTextColour, lowTextColour);
                        } else {
                            _writeData88(highBackColour, lowBackColour);
                        }
                    }
                }
            }
        }
#if (MAX_FONT_SIZE > 2)
        else if (_fontSize == 2) {
            for (k=0; k<s.length(); k++) {
                c = s.charAt(k)-' ';
                _setWindow(x0 +fontSizeX()*k, y0, x0 +fontSizeX()*(k+1)-1, y0+fontSizeY()-1);
                for (j=0; j<8; j++) {
                    for (i=0; i<12; i++) {
                        line = _getCharacter(c, 2*i);
                        if (bitRead(line, j)) {
                            _writeData88(highTextColour, lowTextColour);
                        } else {
                            _writeData88(highBackColour, lowBackColour);
                        }
                    }
                }
                for (j=0; j<8; j++) {
                    for (i=0; i<12; i++) {
                        line = _getCharacter(c, 2*i+1);
                        if (bitRead(line, j)) {
                            _writeData88(highTextColour, lowTextColour);
                        } else {
                            _writeData88(highBackColour, lowBackColour);
                        }
                    }
                }
            }
        }
#if (MAX_FONT_SIZE > 3)
        else if (_fontSize == 3) {
            for (k=0; k<s.length(); k++) {
                c = s.charAt(k)-' ';
                _setWindow(x0 +fontSizeX()*k, y0, x0 +fontSizeX()*(k+1)-1, y0+fontSizeY()-1);
                for (j=0; j<8; j++) {
                    for (i=0; i<16; i++) {
                        line = _getCharacter(c, 3*i);
                        if (bitRead(line, j)) {
                            _writeData88(highTextColour, lowTextColour);
                        } else {
                            _writeData88(highBackColour, lowBackColour);
                        }
                    }
                }
                for (j=0; j<8; j++) {
                    for (i=0; i<16; i++) {
                        line = _getCharacter(c, 3*i+1);
                        if (bitRead(line, j)) {
                            _writeData88(highTextColour, lowTextColour);
                        } else {
                            _writeData88(highBackColour, lowBackColour);
                        }
                    }
                }
                for (j=0; j<8; j++) {
                    for (i=0; i<16; i++) {
                        line = _getCharacter(c, 3*i+2);
                        if (bitRead(line, j)) {
                            _writeData88(highTextColour, lowTextColour);
                        } else {
                            _writeData88(highBackColour, lowBackColour);
                        }
                    }
                }
            }
        }
#endif
#endif
#endif
#endif
    }
}
