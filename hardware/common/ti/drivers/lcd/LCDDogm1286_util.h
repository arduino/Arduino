/*
 * Copyright (c) 2015, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/** ============================================================================
 *  \internal
 *  @file       LCDDogm1286_util.h
 *
 *  @brief      Utility functions used by the LCD driver
 *              for a DOGM128W-6 LCD display.
 *
 *  ============================================================================
 */

#ifndef ti_drivers_lcd_LCDDogm1286_util__include
#define ti_drivers_lcd_LCDDogm1286_util__include

#ifdef __cplusplus
extern "C" {
#endif

/*! \internal
 *  @brief   Returns the length a c-string in number of characters by looking
 *           for the end-of-string character '<tt>\\0</tt>'.
 *           Multiply by \b LCD_CHAR_WIDTH to get length in pixels.
 *
 *  @param    pcStr  null-terminated string whose character length
 *                   is determined.
 *
 *  @return   The length of \e pcStr
 */
extern unsigned char LCD_getStringLength(const char *pcStr);

/*! \internal
 *  @brief    This function returns the character length an integer will use on
 *            the LCD display. For example, \e i32Number = 215 returns 3
 *            and \e i32Number = --215 returns 4 (add one for the minus character).
 *            Multiply result of LCD_getIntLength() by \b LCD_CHAR_WIDTH to
 *            determine the number of pixels needed by \e i32Number.
 *
 *  @param    i32Number  the number whose character length is determined.
 *
 *  @param    uiRadix    numerical base of \e i32Number.
 *
 *  @return   The character length of \e i32Number.
 */
extern unsigned char LCD_getIntLength(int i32Number, unsigned char uiRadix);

/*! \internal
 *  @brief    This function returns the character length a float will need on the
 *            LCD display. This function is used by LCD_bufferPrintFloat() and
 *            LCD_bufferPrintFloatAligned(). \e ucDecimals must be provided to
 *            limit the number of decimals.
 *
 *  @param    fNumber     the number whose character length is determined.
 *
 *  @param    ucDecimals  the desired number of decimals to use (maximum 10).
 *
 *  @return   The character length of \e fNumber.
 */
extern unsigned char LCD_getFloatLength(float fNumber, unsigned char ucDecimals);

/*! \internal
 *  @brief  Function that converts a 16 bit number to ASCII
 *
 *  @param  uiNum    The value to be converted to a string.
 *
 *  @param  buf      Pointer to memory where to store the resulting null-terminated string.
 *
 *  @param  uiRadix  Numerical base used to represent the value as a string, between 2 and 36,
 *                   where 10 means decimal base, 16 hexadecimal, 8 octal, and 2 binary.
 *
 *  @return  void
 */
extern void _itoa(unsigned int uiNum, unsigned char *buf, unsigned char uiRadix);


/* Do not interfere with the app if they include the family Hwi module */
#undef ti_sysbios_family_arm_m3_Hwi__nolocalnames

#ifdef __cplusplus
}
#endif

#endif /* ti_drivers_lcd_LCDDogm1286_util__include */
