/*-
 * Copyright (c) 1990, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * Posix rand_r function added May 1999 by Wes Peters <wes@softweyr.com>.
 *
 * $Id$
 */

/*
 * From:
static char sccsid[] = "@(#)rand.c	8.1 (Berkeley) 6/14/93";
 */
#ifndef RANDOM_MAX
#define RANDOM_MAX 0x7FFFFFFF
#endif

#include <stdlib.h>

static long
do_random(unsigned long *ctx)
{
    /*
     * Compute x = (7^5 * x) mod (2^31 - 1)
     * wihout overflowing 31 bits:
     *      (2^31 - 1) = 127773 * (7^5) + 2836
     * From "Random number generators: good ones are hard to find",
     * Park and Miller, Communications of the ACM, vol. 31, no. 10,
     * October 1988, p. 1195.
     */
    long hi, lo, x;

    x = *ctx;
    /* Can't be initialized with 0, so use another value. */
    if (x == 0)
        x = 123459876L;
    hi = x / 127773L;
    lo = x % 127773L;
    x = 16807L * lo - 2836L * hi;
    if (x < 0)
        x += 0x7fffffffL;
    return ((*ctx = x) % ((unsigned long)RANDOM_MAX + 1));
}


long
random_r(unsigned long *ctx)
{
    return do_random(ctx);
}


static unsigned long next = 1;

long
random(void)
{
    return do_random(&next);
}

void
srandom(unsigned long seed)
{
    next = seed;
}

