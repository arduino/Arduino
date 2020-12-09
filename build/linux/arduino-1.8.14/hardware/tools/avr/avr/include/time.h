/*
 * (C)2012 Michael Duane Rice All rights reserved.
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

/** \file */

/**    \defgroup avr_time <time.h>: Time
    \code #include <time.h> \endcode
    <h3>Introduction to the Time functions</h3>
    This file declares the time functions implemented in \c avr-libc.

    The implementation aspires to conform with ISO/IEC 9899 (C90). However, due to limitations of the
    target processor and the nature of its development environment, a practical implementation must
    of necessity deviate from the standard.



    Section 7.23.2.1 clock()
    The type clock_t, the macro CLOCKS_PER_SEC, and the function clock() are not implemented. We
    consider these items belong to operating system code, or to application code when no operating
    system is present.

    Section 7.23.2.3 mktime()
    The standard specifies that mktime() should return (time_t) -1, if the time cannot be represented.
    This implementation always returns a 'best effort' representation.

    Section 7.23.2.4 time()
    The standard specifies that time() should return (time_t) -1, if the time is not available.
    Since the application must initialize the time system, this functionality is not implemented.

    Section 7.23.2.2, difftime()
    Due to the lack of a 64 bit double, the function difftime() returns a long integer. In most cases
    this change will be invisible to the user, handled automatically by the compiler.

    Section 7.23.1.4 struct tm
    Per the standard, struct tm->tm_isdst is greater than zero when Daylight Saving time is in effect.
    This implementation further specifies that, when positive, the value of tm_isdst represents
    the amount time is advanced during Daylight Saving time.

    Section 7.23.3.5 strftime()
    Only the 'C' locale is supported, therefore the modifiers 'E' and 'O' are ignored.
    The 'Z' conversion is also ignored, due to the lack of time zone name.

    In addition to the above departures from the standard, there are some behaviors which are different
    from what is often expected, though allowed under the standard.

    There is no 'platform standard' method to obtain the current time, time zone, or
    daylight savings 'rules' in the AVR environment. Therefore the application must initialize
    the time system with this information. The functions set_zone(), set_dst(), and
    set_system_time() are provided for initialization. Once initialized, system time is maintained by
    calling the function system_tick() at one second intervals.

    Though not specified in the standard, it is often expected that time_t is a signed integer
    representing an offset in seconds from Midnight Jan 1 1970... i.e. 'Unix time'. This implementation
    uses an unsigned 32 bit integer offset from Midnight Jan 1 2000. The use of this 'epoch' helps to
    simplify the conversion functions, while the 32 bit value allows time to be properly represented
    until Tue Feb 7 06:28:15 2136 UTC. The macros UNIX_OFFSET and NTP_OFFSET are defined to assist in
    converting to and from Unix and NTP time stamps.

    Unlike desktop counterparts, it is impractical to implement or maintain the 'zoneinfo' database.
    Therefore no attempt is made to account for time zone, daylight saving, or leap seconds in past dates.
    All calculations are made according to the currently configured time zone and daylight saving 'rule'.

    In addition to C standard functions, re-entrant versions of ctime(), asctime(), gmtime() and
    localtime() are provided which, in addition to being re-entrant, have the property of claiming
    less permanent storage in RAM. An additional time conversion, isotime() and its re-entrant version,
    uses far less storage than either ctime() or asctime().

    Along with the usual smattering of utility functions, such as is_leap_year(), this library includes
    a set of functions related the sun and moon, as well as sidereal time functions.
*/

#ifndef TIME_H
#define TIME_H

#ifdef __cplusplus
extern          "C" {
#endif

#include <inttypes.h>
#include <stdlib.h>

    /** \ingroup avr_time */
    /* @{ */

    /**
        time_t represents seconds elapsed from Midnight, Jan 1 2000 UTC (the Y2K 'epoch').
        Its range allows this implementation to represent time up to Tue Feb 7 06:28:15 2136 UTC.
    */
    typedef uint32_t time_t;

    /**
    The time function returns the systems current time stamp.
    If timer is not a null pointer, the return value is also assigned to the object it points to.
    */
    time_t          time(time_t *timer);

    /**
    The difftime function returns the difference between two binary time stamps,
    time1 - time0.
    */
    int32_t         difftime(time_t time1, time_t time0);


    /**
        The tm structure contains a representation of time 'broken down' into components of the
        Gregorian calendar.

        The value of tm_isdst is zero if Daylight Saving Time is not in effect, and is negative if
        the information is not available.

        When Daylight Saving Time is in effect, the value represents the number of
        seconds the clock is advanced.

        See the set_dst() function for more information about Daylight Saving.

    */
    struct tm {
        int8_t          tm_sec; /**< seconds after the minute - [ 0 to 59 ] */
        int8_t          tm_min; /**< minutes after the hour - [ 0 to 59 ] */
        int8_t          tm_hour; /**< hours since midnight - [ 0 to 23 ] */
        int8_t          tm_mday; /**< day of the month - [ 1 to 31 ] */
        int8_t          tm_wday; /**< days since Sunday - [ 0 to 6 ] */
        int8_t          tm_mon; /**< months since January - [ 0 to 11 ] */
        int16_t         tm_year; /**< years since 1900 */
        int16_t         tm_yday; /**< days since January 1 - [ 0 to 365 ] */
        int16_t         tm_isdst; /**< Daylight Saving Time flag */
    };

#ifndef __DOXYGEN__
    /* We have to provide clock_t / CLOCKS_PER_SEC so that libstdc++-v3 can
       be built.  We define CLOCKS_PER_SEC via a symbol _CLOCKS_PER_SEC_
       so that the user can provide the value on the link line, which should
       result in little or no run-time overhead compared with a constant.  */
    typedef unsigned long clock_t;
    extern char *_CLOCKS_PER_SEC_;
#define CLOCKS_PER_SEC ((clock_t) _CLOCKS_PER_SEC_)
    extern clock_t clock(void);
#endif	/* !__DOXYGEN__ */

    /**
    This function 'compiles' the elements of a broken-down time structure, returning a binary time stamp.
    The elements of timeptr are interpreted as representing Local Time.

    The original values of the tm_wday and tm_yday elements of the structure are ignored,
    and the original values of the other elements are not restricted to the ranges stated for struct tm.

    On successful completion, the values of all elements of timeptr are set to the appropriate range.
    */
    time_t          mktime(struct tm * timeptr);

    /**
    This function 'compiles' the elements of a broken-down time structure, returning a binary time stamp.
    The elements of timeptr are interpreted as representing UTC.

    The original values of the tm_wday and tm_yday elements of the structure are ignored,
    and the original values of the other elements are not restricted to the ranges stated for struct tm.

    Unlike mktime(), this function DOES NOT modify the elements of timeptr.
    */
    time_t          mk_gmtime(const struct tm * timeptr);

    /**
    The gmtime function converts the time stamp pointed to by timer into broken-down time,
    expressed as UTC.
    */
    struct tm      *gmtime(const time_t * timer);

    /**
        Re entrant version of gmtime().
    */
    void            gmtime_r(const time_t * timer, struct tm * timeptr);

    /**
    The localtime function converts the time stamp pointed to by timer into broken-down time,
    expressed as Local time.
    */
    struct tm      *localtime(const time_t * timer);

    /**
        Re entrant version of localtime().
    */
    void            localtime_r(const time_t * timer, struct tm * timeptr);

    /**
    The asctime function converts the broken-down time of timeptr, into an ascii string in the form

        Sun Mar 23 01:03:52 2013
    */
    char           *asctime(const struct tm * timeptr);

    /**
        Re entrant version of asctime().
    */
    void            asctime_r(const struct tm * timeptr, char *buf);

    /**
        The ctime function is equivalent to asctime(localtime(timer))
    */
    char           *ctime(const time_t * timer);

    /**
        Re entrant version of ctime().
    */
    void            ctime_r(const time_t * timer, char *buf);

    /**
    The isotime function constructs an ascii string in the form
        \code2013-03-23 01:03:52\endcode
    */
    char           *isotime(const struct tm * tmptr);

    /**
        Re entrant version of isotime()
    */
    void            isotime_r(const struct tm *, char *);

    /**
    A complete description of strftime() is beyond the pale of this document.
    Refer to ISO/IEC document 9899 for details.

    All conversions are made using the 'C Locale', ignoring the E or O modifiers. Due to the lack of
    a time zone 'name', the 'Z' conversion is also ignored.
    */
    size_t          strftime(char *s, size_t maxsize, const char *format, const struct tm * timeptr);

    /**
        Specify the Daylight Saving function.

        The Daylight Saving function should examine its parameters to determine whether
        Daylight Saving is in effect, and return a value appropriate for tm_isdst.

        Working examples for the USA and the EU are available..

            \code #include <util/eu_dst.h>\endcode
            for the European Union, and
            \code #include <util/usa_dst.h>\endcode
            for the United States

        If a Daylight Saving function is not specified, the system will ignore Daylight Saving.
    */
    void            set_dst(int (*) (const time_t *, int32_t *));

    /**
        Set the 'time zone'. The parameter is given in seconds East of the Prime Meridian.
        Example for New York City:
        \code set_zone(-5 * ONE_HOUR);\endcode

        If the time zone is not set, the time system will operate in UTC only.
    */
    void            set_zone(int32_t);

    /**
        Initialize the system time. Examples are...

        From a Clock / Calendar type RTC:
        \code
        struct tm rtc_time;

        read_rtc(&rtc_time);
        rtc_time.tm_isdst = 0;
        set_system_time( mktime(&rtc_time) );
        \endcode

        From a Network Time Protocol time stamp:
        \code
        set_system_time(ntp_timestamp - NTP_OFFSET);
        \endcode

        From a UNIX time stamp:
         \code
        set_system_time(unix_timestamp - UNIX_OFFSET);
        \endcode

    */
    void            set_system_time(time_t timestamp);

    /**
        Maintain the system time by calling this function at a rate of 1 Hertz.

        It is anticipated that this function will typically be called from within an
        Interrupt Service Routine, (though that is not required). It therefore includes code which
        makes it simple to use from within a 'Naked' ISR, avoiding the cost of saving and restoring
        all the cpu registers.

        Such an ISR may resemble the following example...
        \code
            ISR(RTC_OVF_vect, ISR_NAKED)
            {
                system_tick();
                reti();
            }
        \endcode
    */
    void            system_tick(void);

    /**
        Enumerated labels for the days of the week.
    */
    enum _WEEK_DAYS_ {
        SUNDAY,
        MONDAY,
        TUESDAY,
        WEDNESDAY,
        THURSDAY,
        FRIDAY,
        SATURDAY
    };

    /**
        Enumerated labels for the months.
    */
    enum _MONTHS_ {
        JANUARY,
        FEBRUARY,
        MARCH,
        APRIL,
        MAY,
        JUNE,
        JULY,
        AUGUST,
        SEPTEMBER,
        OCTOBER,
        NOVEMBER,
        DECEMBER
    };

    /**
        Return 1 if year is a leap year, zero if it is not.
    */
    uint8_t         is_leap_year(int16_t year);

    /**
        Return the length of month, given the year and month, where month is in the range 1 to 12.
     */
    uint8_t         month_length(int16_t year, uint8_t month);

    /**
        Return the calendar week of year, where week 1 is considered to begin on the
        day of week specified by 'start'. The returned value may range from zero to 52.
    */
    uint8_t         week_of_year(const struct tm * timeptr, uint8_t start);

    /**
        Return the calendar week of month, where the first week is considered to begin on the
        day of week specified by 'start'. The returned value may range from zero to 5.
    */
    uint8_t         week_of_month(const struct tm * timeptr, uint8_t start);

    /**
        Structure which represents a date as a year, week number of that year, and day of week.
        See http://en.wikipedia.org/wiki/ISO_week_date for more information.
    */
    struct week_date {
        int year; /**< year number (Gregorian calendar) */
        int week; /**< week number (#1 is where first Thursday is in) */
        int day; /**< day within week */
    };

    /**
        Return a week_date structure with the ISO_8601 week based date corresponding to the given
        year and day of year. See http://en.wikipedia.org/wiki/ISO_week_date for more
        information.
    */
    struct week_date * iso_week_date( int year, int yday);

    /**
        Re-entrant version of iso-week_date.
    */
    void iso_week_date_r( int year, int yday, struct week_date *);

    /**
        Convert a Y2K time stamp into a FAT file system time stamp.
    */
    uint32_t        fatfs_time(const struct tm * timeptr);

    /** One hour, expressed in seconds */
#define ONE_HOUR 3600

    /** Angular degree, expressed in arc seconds */
#define ONE_DEGREE 3600

    /** One day, expressed in seconds */
#define ONE_DAY 86400

    /** Difference between the Y2K and the UNIX epochs, in seconds. To convert a Y2K
        timestamp to UNIX...
        \code
        long unix;
        time_t y2k;

        y2k = time(NULL);
        unix = y2k + UNIX_OFFSET;
        \endcode
    */
#define UNIX_OFFSET 946684800

    /** Difference between the Y2K and the NTP epochs, in seconds. To convert a Y2K
        timestamp to NTP...
        \code
        unsigned long ntp;
        time_t y2k;

        y2k = time(NULL);
        ntp = y2k + NTP_OFFSET;
        \endcode
    */
#define NTP_OFFSET 3155673600

    /*
     * ===================================================================
     *                              Ephemera
     */

    /**
        Set the geographic coordinates of the 'observer', for use with several of the
        following functions. Parameters are passed as seconds of North Latitude, and seconds
        of East Longitude.

        For New York City...
        \code set_position( 40.7142 * ONE_DEGREE, -74.0064 * ONE_DEGREE); \endcode
    */
    void            set_position(int32_t latitude, int32_t longitude);

    /**
        Computes the difference between apparent solar time and mean solar time.
        The returned value is in seconds.
    */
    int16_t         equation_of_time(const time_t * timer);

    /**
        Computes the amount of time the sun is above the horizon, at the location of the observer.

        NOTE: At observer locations inside a polar circle, this value can be zero during the winter,
        and can exceed ONE_DAY during the summer.

        The returned value is in seconds.
    */
    int32_t         daylight_seconds(const time_t * timer);

    /**
        Computes the time of solar noon, at the location of the observer.
    */
    time_t          solar_noon(const time_t * timer);

    /**
        Return the time of sunrise, at the location of the observer. See the note about daylight_seconds().
    */
    time_t          sun_rise(const time_t * timer);

    /**
        Return the time of sunset, at the location of the observer. See the note about daylight_seconds().
    */
    time_t          sun_set(const time_t * timer);

    /** Returns the declination of the sun in radians. */
    double          solar_declination(const time_t * timer);

    /**
        Returns an approximation to the phase of the moon.
        The sign of the returned value indicates a waning or waxing phase.
        The magnitude of the returned value indicates the percentage illumination.
    */
    int8_t          moon_phase(const time_t * timer);

    /**
        Returns Greenwich Mean Sidereal Time, as seconds into the sidereal day.
        The returned value will range from 0 through 86399 seconds.
    */
    unsigned long   gm_sidereal(const time_t * timer);

    /**
        Returns Local Mean Sidereal Time, as seconds into the sidereal day.
        The returned value will range from 0 through 86399 seconds.
    */
    unsigned long   lm_sidereal(const time_t * timer);

    /* @} */
#ifdef __cplusplus
}
#endif

#endif              /* TIME_H  */
