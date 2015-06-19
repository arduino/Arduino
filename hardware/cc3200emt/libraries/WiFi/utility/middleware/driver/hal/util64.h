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

#ifndef __UTIL64__H__
#define __UTIL64__H__

#include "cc_types.h"

/* Construct to refer to timer tick or a generic value */
struct u64_val {    
        u32 hi_32;
        u32 lo_32;
};

/* Construct to refer to a time (absolute or interval) */
struct u64_time {
        u32 secs;   /* Range: 0 to 0xFFFFFFFF secs */
        u32 nsec;   /* Range: 0 to  999999999 nsec */
};

/* Add (32bit) nano-second values. Result may indicate a 'carry' second */
void util_u32_nsec_add(u32 nsec_1, u32 nsec_2, struct u64_time *result);

/* Add two time values */
void util_u64_time_add(const struct u64_time *time_1,
                       const struct u64_time *time_2, 
                       struct u64_time       *result);

/* Add two 32bit data values. Result may indicate a 'carry' value */
void util_u32_data_add(u32 data_1, u32 data_2, struct u64_val *result);

/* Add two 64bit data values. */
void util_u64_data_add(struct u64_val *value1, struct u64_val *value2, 
                       struct u64_val *result);

/* Subtract 32bit nsec values. Result may indicate a 'borrow' value.
   A 'borrow' value is 0xFFFFFFFF.
*/
void util_u32_nsec_sub(u32 from_nsec, u32 this_nsec,
                       struct u64_time *result);

/* Subtract 32bit nsec values. Result may indicate a 'borrow' second.
   A 'borrow' second is 0xFFFFFFFF. */
void util_u64_time_sub(struct u64_time *from,
                       struct u64_time *this,
                       struct u64_time *outp);

/* Returns: 1 for val1 > val2; 0 for val1 = val2; -1 for val1 < val2 */
i32 util_u32_data_cmp(u32 val1, u32 val2);

/* Returns: 1 for val1 > val2; 0 for val1 = val2; -1 for val1 < val2 */
i32 util_u64_data_cmp(struct u64_val *u64_val1,
                             struct u64_val *u64_val2);

/* TBD: u64 sub */

#endif  /*__UTIL64_H__*/
