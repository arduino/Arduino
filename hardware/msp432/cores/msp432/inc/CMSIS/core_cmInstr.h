/**************************************************************************//**
 * @file     core_cmInstr.h
 * @brief    CMSIS Cortex-M Core Instruction Access Header File
 * @version  V4.20
 * @date     02. July 2015
 ******************************************************************************/
/* Copyright (c) 2009 - 2015 ARM LIMITED

   All rights reserved.
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:
   - Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.
   - Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in the
     documentation and/or other materials provided with the distribution.
   - Neither the name of ARM nor the names of its contributors may be used
     to endorse or promote products derived from this software without
     specific prior written permission.
   *
   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
   ARE DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDERS AND CONTRIBUTORS BE
   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
   POSSIBILITY OF SUCH DAMAGE.
   ---------------------------------------------------------------------------*/


#if   defined ( __ICCARM__ )
 #pragma system_include         /* treat file as system include file for MISRA check */
#elif (__ARMCC_VERSION >= 6010050)
  #pragma clang system_header   /* treat file as system include file */
#endif

#ifndef __CORE_CMINSTR_H
#define __CORE_CMINSTR_H


/* ##########################  Core Instruction Access  ######################### */
/** \defgroup CMSIS_Core_InstructionInterface CMSIS Core Instruction Interface
  Access to dedicated instructions
  @{
*/

#if   defined ( __CC_ARM )         /*------------------ RealView Compiler -----------------*/
  #include <cmsis_armcc.h>

#elif (__ARMCC_VERSION >= 6010050) /*------------------ ARM Compiler V6 -------------------*/
  #include <cmsis_armcc_V6.h>

#elif defined ( __GNUC__ )         /*------------------ GNU Compiler ----------------------*/
  #include <cmsis_gcc.h>

#elif defined ( __ICCARM__ )       /*------------------ ICC Compiler ----------------------*/
  #include <cmsis_iar.h>

#elif defined ( __TMS470__ )       /*------------------ TI CCS Compiler -------------------*/
  #include <cmsis_ccs.h>

#elif defined ( __TASKING__ )      /*------------------ TASKING Compiler ------------------*/
    /*
     * The CMSIS functions have been implemented as intrinsics in the compiler.
     * Please use "carm -?i" to get an up to date list of all intrinsics,
     * Including the CMSIS ones.
   */

#elif defined ( __CSMC__ )         /*------------------ COSMIC Compiler -------------------*/
  #include <cmsis_csm.h>

#endif

/*@}*/ /* end of group CMSIS_Core_InstructionInterface */

#endif /* __CORE_CMINSTR_H */
