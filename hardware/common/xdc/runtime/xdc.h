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
/*
 * ======== xdc.h ========
 *  All generated public module headers include this file
 */

#ifndef XDC__
#define XDC__

/*
 *  ======== __CONC__ ========
 *  Concatenate the specified tokens to create a new single token
 */
#define __CONC2__(x,y) x ## y
#define __CONC__(x,y) __CONC2__(x,y)

/*
 *  ======== __STR__ ========
 *  Stringify the specified arguement
 */
#define __STR2__(x) #x
#define __STR__(x) __STR2__(x)

/*
 *  ======== xdc_FILE__ ========
 *  Alternative to __FILE__ which defaults to NULL
 *
 *  We define our own symbol in lieu of the standard __FILE__
 *  so we can avoid embedding lots of static strings in applications
 *  that use Error and Assert.
 *
 *  Both Error and Assert use xdc_FILE__ and ALL module internal headers
 *  redefine xdc_FILE__ to be NULL, unless xdc_FILE is defined.  If xdc_FILE
 *  is defined, xdc-FILE__ has the same value assigned to xdc_FILE.  So, by
 *  default, Error and Asserts in modules do *not* provide a file name.
 *
 *  Since this header in included in all module public headers, "non-module"
 *  clients of Error and Assert *will*, by default, provide a file name
 *  string.  To eliminate these embedded strings, add the following line
 *  before all module headers:
 *      #define xdc_FILE    NULL
 *
 *  Module creators may opt to define xdc_FILE as the string to use in
 *  Error and Assert messages.  For example, adding the following line
 *  to a module's implementation (before the inclusion of the module's
 *  internal header) will cause the standard __FILE__ to be
 *  used in lieu of NULL in Error and Assert calls:
 *      #define xdc_FILE    __FILE__
 *
 */
#ifndef xdc_FILE__
#ifdef xdc_FILE
#define xdc_FILE__ xdc_FILE
#else
#define xdc_FILE__ __FILE__
#endif
#endif

/*
 *  ======== xdc_LINE ========
 *  Standard file-line-number string for identifying a call site
 */
#ifdef xdc_FILE
#define xdc_LINE (xdc_runtime_Types_RopeAddr)"\"" xdc_FILE "\", line " __STR__(__LINE__)
#else
#define xdc_LINE (xdc_runtime_Types_RopeAddr)"\"" __FILE__ "\", line " __STR__(__LINE__)
#endif

#endif /* XDC__ */






/*
 *  @(#) xdc.runtime; 2, 1, 0,0; 4-24-2015 12:34:13; /db/ztree/library/trees/xdc/xdc-A71/src/packages/
 */

