/* 
 *  Copyright (c) 2008 Texas Instruments. All rights reserved. 
 *  This program and the accompanying materials are made available under the 
 *  terms of the Eclipse Public License v1.0 and Eclipse Distribution License
 *  v. 1.0 which accompanies this distribution. The Eclipse Public License is
 *  available at http://www.eclipse.org/legal/epl-v10.html and the Eclipse
 *  Distribution License is available at 
 *  http://www.eclipse.org/org/documents/edl-v10.php.
 *
 *  Contributors:
 *      Texas Instruments - initial implementation
 * */

#ifndef xdc_runtime_System__internal_h
#define xdc_runtime_System__internal_h

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  ======== System__internal.h ========
 *  This header defines internal implementation details that are shared
 *  between System.c and System.xdt and SHOULD NOT be included by any other
 *  files.  The declarations in this file are subject to incompatible
 *  changes in any release; only clients of System.h are kept compatible.
 *
 *  Note: because this header is included in the generated .c file, we must 
 *  be careful to only use fully qualified names (e.g., xdc_UInt32 rather 
 *  than just UInt32)
 */

/*
 *  ======== xdc_runtime_System_{I|U}Num ========
 *  Maximum sized (un)signed integer that can be formated by System_printf
 *
 *  {I|U}Arg can't be used because we need to be able to handle a long or
 *  a pointer (not just an int or a pointer).
 *  
 *  These internal declarations are here rather than in System.h to ensure 
 *  that targets _without_ 64-bit support can still use System
 */
#if ((xdc_target__bitsPerChar * xdc_target__sizeof_Ptr) > 32)
typedef xdc_UInt64      xdc_runtime_System_UNum;
typedef xdc_Int64       xdc_runtime_System_INum;
#else
typedef xdc_UInt32      xdc_runtime_System_UNum;
typedef xdc_Int32       xdc_runtime_System_INum;
#endif

/*
 *  ======== xdc_runtime_System_formatNum__I ========
 *  This internal function is used to convert all integral numbers to a
 *  character string.  It's implementation is in System.c.
 */
extern xdc_Char *xdc_runtime_System_formatNum__I(xdc_Char *,
                     xdc_runtime_System_UNum, xdc_Int, xdc_Int);


#ifdef __cplusplus
}
#endif

#endif
/*
 *  @(#) xdc.runtime; 2, 1, 0,0; 4-24-2015 12:34:13; /db/ztree/library/trees/xdc/xdc-A71/src/packages/
 */

