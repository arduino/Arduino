//
// LCD_screen.cpp
// Class library C++ code
// ----------------------------------
// Developed with embedXcode
// http://embedXcode.weebly.com
//
// Project LCD_screen_main
//
// Created by Rei VILO, mars 06, 2013 18:12
// embedXcode.weebly.com
//
//
// Copyright © Rei VILO, 2013
// License All rights reserved
//
// See LCD_screen.h and ReadMe.txt for references
//
// Library header
#include "LCD_screen.h"
// Code
LCD_screen::LCD_screen()
{
    _fontSize       = 0;
    _fontSolid      = true;
    _penSolid       = false;
    _flagRead       = false;
    _flagStorage    = false;
    _touchTrim      = 0;
}
void LCD_screen::showInformation(uint16_t x0, uint16_t y0)
{
    setFontSize(2);
    gText(x0, y0, "LCD_screen Library Suite");
    y0 += fontSizeY()+1;
    setFontSize(1);
    gText(x0, y0, "release " + String(LCD_SCREEN_RELEASE/100) + "." + String(LCD_SCREEN_RELEASE/10%10) + String(LCD_SCREEN_RELEASE%10));
    y0 += fontSizeY()+1;
    gText(x0, y0, "(c) Rei Vilo, 2013");
    y0 += fontSizeY()+1;
    setFontSize(0);
    gText(x0, y0, "reivilofischertechnik.weebly.com");
    y0 += fontSizeY()+1;
    gText(x0, y0, "Screen:   " + WhoAmI());
    y0 += fontSizeY()+1;
    gText(x0, y0, "Pixels:   " + String(screenSizeX()) + " x " + String(screenSizeY()));
    y0 += fontSizeY()+1;
    gText(x0, y0, "Readable: " + String((isReadable()) ? "yes" : "no"));
    y0 += fontSizeY()+1;
    gText(x0, y0, "Touch:    " + String((isTouch()) ? "yes" : "no"));
    y0 += fontSizeY()+1;
    gText(x0, y0, "Storage:  " + String((isStorage()) ? "yes" : "no"));
    y0 += fontSizeY()+1;
}
void LCD_screen::clear(uint16_t colour)
{
    uint8_t oldOrientation = _orientation;
    bool oldPenSolid = _penSolid;
    setOrientation(0);
    setPenSolid();
    rectangle(0, 0, screenSizeX()-1, screenSizeY()-1, colour);
    setOrientation(oldOrientation);
    setPenSolid(oldPenSolid);
}
void LCD_screen::setOrientation(uint8_t orientation)
{
    _orientation = orientation % 4;
}
uint8_t LCD_screen::getOrientation()
{
    return _orientation;
}
uint16_t LCD_screen::screenSizeX()
{
    switch (_orientation) {
        case 0:
        case 2:
            return _screenWidth;
            break;
        case 1:
        case 3:
            return _screenHeigth;
            break;
    }
}
uint16_t LCD_screen::screenSizeY()
{
    switch (_orientation) {
        case 0:
        case 2:
            return _screenHeigth;
            break;
        case 1:
        case 3:
            return _screenWidth;
            break;
    }
}
void LCD_screen::circle(uint16_t x0, uint16_t y0, uint16_t radius, uint16_t colour)
{
    int16_t f = 1 - radius;
    int16_t ddF_x = 1;
    int16_t ddF_y = -2 * radius;
    int16_t x = 0;
    int16_t y = radius;
    if (_penSolid == false) {
        point(x0, y0+radius, colour);
        point(x0, y0-radius, colour);
        point(x0+radius, y0, colour);
        point(x0-radius, y0, colour);
        while (x<y) {
            if (f >= 0) {
                y--;
                ddF_y += 2;
                f += ddF_y;
            }
            x++;
            ddF_x += 2;
            f += ddF_x;
            point(x0 + x, y0 + y, colour);
            point(x0 - x, y0 + y, colour);
            point(x0 + x, y0 - y, colour);
            point(x0 - x, y0 - y, colour);
            point(x0 + y, y0 + x, colour);
            point(x0 - y, y0 + x, colour);
            point(x0 + y, y0 - x, colour);
            point(x0 - y, y0 - x, colour);
        }
    } else {
        while (x<y) {
            if (f >= 0) {
                y--;
                ddF_y += 2;
                f += ddF_y;
            }
            x++;
            ddF_x += 2;
            f += ddF_x;
            line(x0 + x, y0 + y, x0 - x, y0 + y, colour);
            line(x0 + x, y0 - y, x0 - x, y0 - y, colour);
            line(x0 + y, y0 - x, x0 + y, y0 + x, colour);
            line(x0 - y, y0 - x, x0 - y, y0 + x, colour);
        }
        setPenSolid(true);
        rectangle(x0-x, y0-y, x0+x, y0+y, colour);
    }
}
void LCD_screen::dLine(uint16_t x0, uint16_t y0, uint16_t dx, uint16_t dy, uint16_t colour)
{
    line(x0, y0, x0+dx-1, y0+dy-1, colour);
}
void LCD_screen::line(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t colour)
{
    if ((x1 == x2) && (y1 == y2)) {
        _setPoint(x1, y1, colour);
    } else if ((x1 == x2) || (y1 == y2)) {
        _fastFill(x1, y1, x2, y2, colour);
    } else {
        int16_t wx1 = (int16_t)x1;
        int16_t wx2 = (int16_t)x2;
        int16_t wy1 = (int16_t)y1;
        int16_t wy2 = (int16_t)y2;
        boolean flag = abs(wy2 - wy1) > abs(wx2 - wx1);
        if (flag) {
            _swap(wx1, wy1);
            _swap(wx2, wy2);
        }
        if (wx1 > wx2) {
            _swap(wx1, wx2);
            _swap(wy1, wy2);
        }
        int16_t dx = wx2 - wx1;
        int16_t dy = abs(wy2 - wy1);
        int16_t err = dx / 2;
        int16_t ystep;
        if (wy1 < wy2) ystep = 1;
        else ystep = -1;
        for (; wx1<=wx2; wx1++) {
            if (flag) _setPoint(wy1, wx1, colour);
            else _setPoint(wx1, wy1, colour);
            err -= dy;
            if (err < 0) {
                wy1 += ystep;
                err += dx;
            }
        }
    }
}
void LCD_screen::setPenSolid(bool flag)
{
    _penSolid = flag;
}
void LCD_screen::point(uint16_t x1, uint16_t y1, uint16_t colour)
{
    _setPoint(x1, y1, colour);
}
void LCD_screen::rectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t colour)
{
    if (_penSolid == false) {
        line(x1, y1, x1, y2, colour);
        line(x1, y1, x2, y1, colour);
        line(x1, y2, x2, y2, colour);
        line(x2, y1, x2, y2, colour);
    } else {
        _fastFill(x1, y1, x2, y2, colour);
    }
}
void LCD_screen::dRectangle(uint16_t x0, uint16_t y0, uint16_t dx, uint16_t dy, uint16_t colour)
{
    rectangle(x0, y0, x0+dx-1, y0+dy-1, colour);
}
void LCD_screen::_triangleArea(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t x3, uint16_t y3, uint16_t colour)
{
    int16_t wx1 = (int16_t)x1;
    int16_t wy1 = (int16_t)y1;
    int16_t wx2 = (int16_t)x2;
    int16_t wy2 = (int16_t)y2;
    int16_t wx3 = (int16_t)x3;
    int16_t wy3 = (int16_t)y3;
    int16_t wx4 = wx1;
    int16_t wy4 = wy1;
    int16_t wx5 = wx1;
    int16_t wy5 = wy1;
    bool changed1 = false;
    bool changed2 = false;
    int16_t dx1 = abs(wx2 - wx1);
    int16_t dy1 = abs(wy2 - wy1);
    int16_t dx2 = abs(wx3 - wx1);
    int16_t dy2 = abs(wy3 - wy1);
    int16_t signx1 = (wx2 >= wx1) ? +1 : -1;
    int16_t signx2 = (wx3 >= wx1) ? +1 : -1;
    int16_t signy1 = (wy2 >= wy1) ? +1 : -1;
    int16_t signy2 = (wy3 >= wy1) ? +1 : -1;
    if (dy1 > dx1) {
        _swap(dx1, dy1);
        changed1 = true;
    }
    if (dy2 > dx2) {
        _swap(dx2, dy2);
        changed2 = true;
    }
    int16_t e1 = 2 * dy1 - dx1;
    int16_t e2 = 2 * dy2 - dx2;
    for (int i = 0; i <= dx1; i++) {
        line(wx4, wy4, wx5, wy5, colour);
        while (e1 >= 0) {
            if (changed1) wx4 += signx1;
            else wy4 += signy1;
            e1 = e1 - 2 * dx1;
        }
        if (changed1) wy4 += signy1;
        else wx4 += signx1;
        e1 = e1 + 2 * dy1;
        while (wy5 != wy4) {
            while (e2 >= 0) {
                if (changed2) wx5 += signx2;
                else wy5 += signy2;
                e2 = e2 - 2 * dx2;
            }
            if (changed2) wy5 += signy2;
            else wx5 += signx2;
            e2 = e2 + 2 * dy2;
        }
    }
}
void LCD_screen::triangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t x3, uint16_t y3, uint16_t colour)
{
    if (_penSolid) {
        bool b = true;
        while (b) {
            b = false;
            if ((b == false) && (y1 > y2)) {
                _swap(x1, x2);
                _swap(y1, y2);
                b = true;
            }
            if ((b == false) && (y2 > y3)) {
                _swap(x3, x2);
                _swap(y3, y2);
                b = true;
            }
        }
        if (y2 == y3) {
            _triangleArea(x1, y1, x2, y2, x3, y3, colour);
        } else if (y1 == y2) {
            _triangleArea(x3, y3, x1, y1, x2, y2, colour);
        } else {
            uint16_t x4 = (uint16_t)( (int32_t)x1 + (y2 - y1) * (x3 - x1) / (y3 - y1) );
            uint16_t y4 = y2;
            _triangleArea(x1, y1, x2, y2, x4, y4, colour);
            _triangleArea(x3, y3, x2, y2, x4, y4, colour);
        }
    } else {
        line(x1, y1, x2, y2, colour);
        line(x2, y2, x3, y3, colour);
        line(x3, y3, x1, y1, colour);
    }
}
bool LCD_screen::_inValue(int16_t value, int16_t valueLow, int16_t valueHigh)
{
    if (valueLow <= valueHigh) return ((valueLow <= value) && (value < valueHigh));
    else return ((valueHigh <= value) && (value < valueLow));
}
bool LCD_screen::_inCycle(int16_t value, int16_t valueLow, int16_t valueHigh)
{
    if (valueLow <= valueHigh) return ((valueLow < value) && (value < valueHigh));
    else return ((valueHigh <= value) != (value < valueLow));
}
bool LCD_screen::_inSector(int16_t valueStart, int16_t valueEnd, int16_t sectorLow, int16_t sectorHigh,
                           int16_t criteriaStart, int16_t criteriaEnd, int16_t criteriaLow, int16_t criteriaHigh,
                           int16_t criteria)
{
    bool flag = false;
    flag |= !_inValue(valueStart, sectorLow, sectorHigh) && _inValue(valueEnd, sectorLow, sectorHigh) && _inValue(criteria, criteriaLow, criteriaEnd);
    flag |= _inValue(valueStart, sectorLow, sectorHigh) && _inValue(valueEnd, sectorLow, sectorHigh) && _inValue(criteria, criteriaStart, criteriaEnd);
    flag |= _inValue(valueStart, sectorLow, sectorHigh) && !_inValue(valueEnd, sectorLow, sectorHigh) && _inValue(criteria, criteriaStart, criteriaHigh);
    flag |= ((valueStart <= sectorLow) && (sectorHigh <= valueEnd)) || ((sectorHigh <= valueEnd)  && (valueEnd   <= valueStart)) || ((valueStart <= sectorLow) && (valueEnd   <= valueStart));
    return flag;
}
void LCD_screen::arc(uint16_t x0, uint16_t y0, uint16_t radius, uint16_t start, uint16_t end, uint16_t colour)
{ ; }
void LCD_screen::setFontSolid(bool flag)
{
    _fontSolid = flag;
}
uint16_t LCD_screen::calculateColour(uint8_t red, uint8_t green, uint8_t blue)
{
    return (red >> 3) << 11 | (green >> 2) << 5 | (blue >> 3);
}
void LCD_screen::splitColour(uint16_t rgb, uint8_t &red, uint8_t &green, uint8_t &blue)
{
    red   = (rgb & 0b1111100000000000) >> 11 << 3;
    green = (rgb & 0b0000011111100000) >>  5 << 2;
    blue  = (rgb & 0b0000000000011111)       << 3;
}
uint16_t LCD_screen::halveColour(uint16_t rgb) {
    return ((rgb & 0b1111100000000000) >> 12 << 11 | \
            (rgb & 0b0000011111100000) >>  6 <<  5 | \
            (rgb & 0b0000000000011111) >>  1);
}
uint16_t LCD_screen::averageColour(uint16_t rgb1, uint16_t rgb2)
{
    uint8_t r1, g1, b1, r2, g2, b2;
    uint16_t r, g, b;
    splitColour(rgb1, r1, g1, b1);
    splitColour(rgb2, r2, g2, b2);
    r = (uint16_t)(r1 + r2)/2;
    g = (uint16_t)(g1 + g2)/2;
    b = (uint16_t)(b1 + b2)/2;
    return calculateColour((uint8_t)r, (uint8_t)g, (uint8_t)b);
}
uint16_t LCD_screen::reverseColour(uint16_t rgb) {
    return (uint16_t)(rgb ^ 0b1111111111111111);
}
bool LCD_screen::isTouch()
{
    return (_touchTrim > 0);
}
bool LCD_screen::isReadable()
{
    return _flagRead;
}
bool LCD_screen::isStorage()
{
    return _flagStorage;
}
uint16_t LCD_screen::readPixel(uint16_t x1, uint16_t y1)
{
    return 0;
}
void LCD_screen::copyPaste(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t dx, uint16_t dy)
{
}
void LCD_screen::copyArea(uint16_t x0, uint16_t y0, uint16_t dx, uint16_t dy, uint32_t &address)
{
}
void LCD_screen::pasteArea(uint16_t x0, uint16_t y0, uint16_t dx, uint16_t dy, uint32_t &address, bool option)
{
}
void LCD_screen::_displayTarget(uint16_t x0, uint16_t y0, uint16_t colour)
{
    setPenSolid(false);
    circle(x0, y0, 8, colour);
    circle(x0, y0, 7, colour);
    circle(x0, y0, 6, colour);
}
bool LCD_screen::getTouch(uint16_t &x, uint16_t &y, uint16_t &z)
{
    if (_touchTrim == 0) return false;
    uint16_t x0, y0, z0;
    _getRawTouch(x0, y0, z0);
    z = z0;
    if (z > _touchTrim) {
        x0 = _check(x0, _touchXmin, _touchXmax);
        y0 = _check(y0, _touchYmin, _touchYmax);
        switch (_orientation) {
            case 0:
                x = map(x0, _touchXmin, _touchXmax, 0, _screenWidth);
                y = map(y0, _touchYmin, _touchYmax, 0, _screenHeigth);
                break;
            case 1:
                x = map(y0, _touchYmin, _touchYmax, 0, _screenHeigth);
                y = map(x0, _touchXmin, _touchXmax, _screenWidth, 0);
                break;
            case 2:
                x = map(x0, _touchXmin, _touchXmax, _screenWidth, 0);
                y = map(y0, _touchYmin, _touchYmax, _screenHeigth, 0);
                break;
            case 3:
                x = map(y0, _touchYmin, _touchYmax, _screenHeigth, 0);
                y = map(x0, _touchXmin, _touchXmax, 0, _screenWidth);
                break;
        }
        return true;
    } else {
        return false;
    }
}
void LCD_screen::calibrateTouch()
{
    if (_touchTrim == 0) return;
    uint16_t x00, y00, x10, x01, x11, y10, y01, y11, z0;
    uint16_t x0, x1, y0, y1;
    uint8_t  old = _orientation;
    setOrientation(0);
    clear();
    setFontSize(0);
    gText(screenSizeX()/2-17*fontSizeX()/2, screenSizeY()/2-fontSizeY(), "TOUCH CALIBRATION", redColour, blackColour);
    gText(screenSizeX()/2-16*fontSizeX()/2, screenSizeY()/2,             "Press the centre", redColour, blackColour);
    gText(screenSizeX()/2-17*fontSizeX()/2, screenSizeY()/2+fontSizeY(), "of the red circle", redColour, blackColour);
    _displayTarget(10, 10, redColour);
    z0 = 0;
    do _getRawTouch(x00, y00, z0); while (z0<_touchTrim);
    _displayTarget(10, 10, greenColour);
    delay(500);
    _displayTarget(_screenWidth-10, 10, redColour);
    z0 = 0;
    do _getRawTouch(x10, y10, z0); while (z0<_touchTrim);
    _displayTarget(_screenWidth-10, 10, greenColour);
    delay(500);
    _displayTarget(_screenWidth-10, _screenHeigth-10, redColour);
    z0 = 0;
    do _getRawTouch(x11, y11, z0); while (z0<_touchTrim);
    _displayTarget(_screenWidth-10, _screenHeigth-10, greenColour);
    delay(500);
    _displayTarget(10, _screenHeigth-10, redColour);
    z0 = 0;
    do _getRawTouch(x01, y01, z0); while (z0<_touchTrim);
    _displayTarget(10, _screenHeigth-10, greenColour);
    x0 = (x00+x01)/2;
    x1 = (x10+x11)/2;
    y0 = (y00+y10)/2;
    y1 = (y01+y11)/2;
    _touchXmin = x0 - 10 * (x1-x0) / (_screenWidth -10-10);
    _touchXmax = x1 + 10 * (x1-x0) / (_screenWidth -10-10);
    _touchYmin = y0 - 10 * (y1-y0) / (_screenHeigth-10-10);
    _touchYmax = y1 + 10 * (y1-y0) / (_screenHeigth-10-10);
    Serial.println("touch calibration");
    Serial.print("_touchXmin =");
    Serial.print(_touchXmin, DEC);
    Serial.println(";");
    Serial.print("_touchXmax =");
    Serial.print(_touchXmax, DEC);
    Serial.println(";");
    Serial.print("_touchYmin =");
    Serial.print(_touchYmin, DEC);
    Serial.println(";");
    Serial.print("_touchYmax =");
    Serial.print(_touchYmax, DEC);
    Serial.println(";");
    clear();
    setOrientation(old);
}
void LCD_screen::_swap(uint16_t &a, uint16_t &b)
{
    uint16_t w = a;
    a = b;
    b = w;
}
void LCD_screen::_swap(int16_t &a, int16_t &b)
{
    int16_t w = a;
    a = b;
    b = w;
}
void LCD_screen::_swap(uint8_t &a, uint8_t &b)
{
    uint8_t w = a;
    a = b;
    b = w;
}
uint16_t LCD_screen::_check(uint16_t x0, uint16_t xmin, uint16_t xmax)
{
    if (xmin < xmax) {
        if (x0 < xmin) return xmin;
        else if (x0 > xmax) return xmax;
        else return x0;
    } else {
        if (x0 < xmax) return xmax;
        else if (x0 > xmin) return xmin;
        else return x0;
    }
}
