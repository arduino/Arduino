/*
 * (c)2012 Michael Duane Rice All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer. Redistributions in binary
 * form must reproduce the above copyright notice, this list of conditions
 * and the following disclaimer in the documentation and/or other materials
 * provided with the distribution. Neither the name of the copyright holders
 * nor the names of contributors may be used to endorse or promote products
 * derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

/* $Id$ */

/**
    Daylight Saving function for the European Union. To utilize this function, you must
    \code #include <util/eu_dst.h> \endcode
    and
    \code set_dst(eu_dst); \endcode

    Given the time stamp and time zone parameters provided, the Daylight Saving function must
    return a value appropriate for the tm structures' tm_isdst element. That is...

    0 : If Daylight Saving is not in effect.

    -1 : If it cannot be determined if Daylight Saving is in effect.

    A positive integer : Represents the number of seconds a clock is advanced for Daylight Saving.
    This will typically be ONE_HOUR.

    Daylight Saving 'rules' are subject to frequent change. For production applications it is
    recommended to write your own DST function, which uses 'rules' obtained from, and modifiable by,
    the end user ( perhaps stored in EEPROM ).
*/

#ifndef EU_DST_H
#define EU_DST_H

#ifdef __cplusplus
extern          "C" {
#endif

#include <time.h>
#include <inttypes.h>

    int             eu_dst(const time_t * timer, int32_t * z) {
        struct tm       tmptr;
        uint8_t         month, mday, hour, day_of_week, d;
        int             n;

        /* obtain the variables */
                        gmtime_r(timer, &tmptr);
                        month = tmptr.tm_mon;
                        day_of_week = tmptr.tm_wday;
                        mday = tmptr.tm_mday - 1;
                        hour = tmptr.tm_hour;

        if              ((month > MARCH) && (month < OCTOBER))
                            return ONE_HOUR;

        if              (month < MARCH)
                            return 0;
        if              (month > OCTOBER)
                            return 0;

        /* determine mday of last Sunday */
                        n = tmptr.tm_mday - 1;
                        n -= day_of_week;
                        n += 7;
                        d = n % 7;  /* date of first Sunday */

                        n = 31 - d;
                        n /= 7; /* number of Sundays left in the month */

                        d = d + 7 * n;  /* mday of final Sunday */

        if              (month == MARCH) {
            if (d < mday)
                return 0;
            if (d > mday)
                return ONE_HOUR;
            if (hour < 2)
                return 0;
            return ONE_HOUR;
        }
        if              (d < mday)
                            return ONE_HOUR;
        if              (d > mday)
                            return 0;
        if              (hour < 2)
                            return ONE_HOUR;
                        return 0;

    }

#ifdef __cplusplus
}
#endif

#endif
