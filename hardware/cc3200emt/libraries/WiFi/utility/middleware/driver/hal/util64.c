//*****************************************************************************
//
// Copyright (C) 2014 Texas Instruments Incorporated - http://www.ti.com/ 
// 
// 
//  Redistribution and use in source and binary forms, with or without 
//  modification, are permitted provided that the following conditions 
//  are met:
//
//    Redistributions of source code must retain the above copyright 
//    notice, this list of conditions and the following disclaimer.
//
//    Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the 
//    documentation and/or other materials provided with the   
//    distribution.
//
//    Neither the name of Texas Instruments Incorporated nor the names of
//    its contributors may be used to endorse or promote products derived
//    from this software without specific prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
//  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
//  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
//  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
//  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
//  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
//  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
//  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
//  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
//  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
//  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//*****************************************************************************

#include "util64.h"

#define NSEC_VAL_FOR_1SEC    1000000000  /* Move this to a common file  */

void util_u32_nsec_add(u32 nsec_1, u32 nsec_2, struct u64_time *result)
{
        /* 1 sec overflow check: v1 nsec + v2 nsec > 1000000000 nanoseconds */
        if(nsec_1 + nsec_2 >= NSEC_VAL_FOR_1SEC) {
                result->nsec  = nsec_1 + nsec_2;
                result->nsec -= NSEC_VAL_FOR_1SEC;
                result->secs  = 1;                            /* Carry flag */
        } else {
                /* Simple 32bits addition without any carry flag / overflow */
                result->nsec  = nsec_1 +  nsec_2;
                result->secs  = 0;
        }

        return;
}

void util_u64_time_add(const struct u64_time *time_1, 
                       const struct u64_time *time_2, 
                       struct u64_time       *result)
{
        util_u32_nsec_add(time_1->nsec, time_2->nsec, result);
        
        result->secs += time_1->secs + time_2->secs;

        return;
}

void util_u32_data_add(u32 data_1, u32 data_2, struct u64_val *result)
{
        /* 32bit overflow check: v1 + v2 > 0xFFFFFFFF => v1 > 0xFFFFFFFF - v2 */
        if(data_1 > ~data_2) {
                /* exceeds by => v1 + v2 - (0xFFFFFFFF + 1) = v1 - (~v2 + 1)  */
                result->lo_32  = data_1 - ~data_2 - 1;
                result->hi_32  = 1;                             /* Carry flag */
        } else {
                /* Simple 32bits addition without any carry flag and overflow */
                result->lo_32  = data_1 +  data_2;
                result->hi_32  = 0;
        }

        return;
}

void util_u64_data_add(struct u64_val *value1, struct u64_val *value2, 
                       struct u64_val *result)
{
        util_u32_data_add(value1->lo_32, value2->lo_32, result);

        result->hi_32 += value1->hi_32 + value2->hi_32;

        return;
}

void util_u32_nsec_sub(u32 from_nsec, u32 this_nsec,
                       struct u64_time *result)
{
        if(from_nsec < this_nsec) {
                result->nsec  = NSEC_VAL_FOR_1SEC + from_nsec;
                result->nsec -= this_nsec;
                result->secs  = 0xFFFFFFFF;
        } else {
                result->nsec  = from_nsec - this_nsec;
                result->secs  = 0;
        }

        return;
}

void util_u64_time_sub(struct u64_time *from,
                       struct u64_time *this,
                       struct u64_time *outp)
{
        util_u32_nsec_sub(from->nsec, this->nsec, outp);

        if(from->secs < this->secs + (0xFFFFFFFF == outp->secs)? 1 : 0)
                outp->secs  = 0xFFFFFFFF;
        else
                outp->secs += from->secs - this->secs;

        return;
}

/* Returns: 1 for val1 > val2; 0 for val1 = val2; -1 for val1 < val2 */
i32 util_u32_data_cmp(u32 val1, u32 val2)
{
        i32 rv = -1;

        if(val1 == val2)
                rv = 0;
        else if(val1 > val2)
                rv = 1;

        return rv;
}

/* Returns: 1 for val1 > val2; 0 for val1 = val2; -1 for val1 < val2 */
i32 util_u64_data_cmp(struct u64_val *u64_val1, 
                             struct u64_val *u64_val2)
{
        i32 rv = -1;

        if(u64_val1->hi_32 == u64_val2->hi_32)
                rv = util_u32_data_cmp(u64_val1->lo_32, u64_val2->lo_32);
        else if(u64_val1->hi_32 > u64_val2->hi_32)
                rv = 1;

        return rv;
}
/* TBD: u64 sub */
