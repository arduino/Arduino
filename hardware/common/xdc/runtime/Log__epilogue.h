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
 *  ======== Log__epilogue.h ========
 *  Implementation of the Log_* macros
 *
 *  The implementation below relies on eight symbols defined by every module
 *  header.  Each of these symbols is a reference to a constant defined in a
 *  separate compilation unit.  The values of these constants are as follows:
 *
 *      Module__MID     - the module's ID (see Text.xs)
 *      Module__LOGOBJ  - the module's logger instance object
 *      Module__LOGFXN0 - the module's logger's write0 function
 *      Module__LOGFXN1 - the module's logger's write1 function 
 *      Module__LOGFXN2 - the module's logger's write2 function
 *      Module__LOGFXN4 - the module's logger's write4 function
 *      Module__LOGFXN8 - the module's logger's write8 function
 *      Module__LOGDEF  - 0 if the module has a logger, non-zero otherwise
 */

/*
 *  Define flags for compiling out all Log calls
 *
 *  The intent of these flags is to allow users to completely optimize logging
 *  out of their code even when not using whole program optimization. This is
 *  implemented by controlling the definitions of the Log macros. This will
 *  only affect code compiled with the flag(s) set, so it will not disable 
 *  logging in any precompiled libraries.
 *
 *  The DISABLE_ALL flag will have the effect of disabling all Log put, write, 
 *  print, error, warning, and info log calls. The flag just has to be defined,
 *  we give it a value of zero or one to use in the macros.
 *
 *  There are additional flags which can be used to disable all log calls
 *  "except for". We use the presence of the DISABLE_ALL flag and the presence
 *  of any ENABLE_ERROR, ENABLE_INFO, or ENABLE_WARNING flags to compute the
 *  value of ENABLE_ERROR, etc., as zero or one.
 *
 *  We ensure that all of the flags are ultimately defined and given a zero or
 *  one value. Then the macro definitions are conditional on the value of the
 *  appropriate flag.
 */

/* 
 * If DISABLE_ALL is defined, give it the value 1, and assign values to all
 * of the ENABLE flags based on whether they've been defined or not.
 */
#ifdef xdc_runtime_Log_DISABLE_ALL

#define xdc_runtime_Log_DISABLE_ALL 1

#ifndef xdc_runtime_Log_ENABLE_ERROR
#define xdc_runtime_Log_ENABLE_ERROR 0
#else
#define xdc_runtime_Log_ENABLE_ERROR 1
#endif

#ifndef xdc_runtime_Log_ENABLE_WARNING
#define xdc_runtime_Log_ENABLE_WARNING 0
#else
#define xdc_runtime_Log_ENABLE_WARNING 1
#endif

#ifndef xdc_runtime_Log_ENABLE_INFO
#define xdc_runtime_Log_ENABLE_INFO 0
#else
#define xdc_runtime_Log_ENABLE_INFO 1
#endif

/*
 * If DISABLE_ALL has not been defined, just define it to 0 and define
 * all of the ENABLE flags to 1.
 */
#else
#define xdc_runtime_Log_DISABLE_ALL     0
#define xdc_runtime_Log_ENABLE_ERROR    1
#define xdc_runtime_Log_ENABLE_WARNING  1
#define xdc_runtime_Log_ENABLE_INFO     1
#endif

/*
 *  ======== xdc_runtime_Log_getMask ========
 */
#define xdc_runtime_Log_getMask(evt) ((xdc_runtime_Diags_Mask)((evt) & 0x0000ffff))

/*
 *  ======== xdc_runtime_Log_getRope ========
 */
#define xdc_runtime_Log_getRope(evt) ((xdc_runtime_Types_RopeId)((evt) >> 16))

/*
 *  ======== xdc_runtime_Log_getEventId ========
 */
#define xdc_runtime_Log_getEventId(evt) \
    ((xdc_runtime_Log_EventId)((evt) >> 16))

/*
 *  ======== xdc_runtime_Log_doPut* ========
 *  The 'doPut' macros are the real implementation of the Log_put* APIs.
 *  The Log_put* macros are just stubs which point to these definitions. We do
 *  this so that we can disable the Log_put* APIs but still leave their
 *  functionality available for any other Log macros which use them. 
 *
 *  For example, if the flags DISABLE_ALL and ENABLE_ERROR are set, we want
 *  to disable the Log_put* macros, but not the Log_error* macros which are
 *  also built on top of these 'doPut' macros.
 */
#define xdc_runtime_Log_doPut0(evt, mid) \
    Module__LOGFXN0(Module__LOGOBJ, (evt), (mid))

#define xdc_runtime_Log_doPut1(evt, mid, a1) \
    Module__LOGFXN1(Module__LOGOBJ, (evt), (mid), (a1))

#define xdc_runtime_Log_doPut2(evt, mid, a1, a2) \
    Module__LOGFXN2(Module__LOGOBJ, (evt), (mid), (a1), (a2)) 

#define xdc_runtime_Log_doPut4(evt, mid, a1, a2, a3, a4) \
    Module__LOGFXN4(Module__LOGOBJ, (evt), (mid), (a1), (a2), (a3), (a4))

#define xdc_runtime_Log_doPut8(evt, mid, a1, a2, a3, a4, a5, a6, a7, a8) \
    Module__LOGFXN8(Module__LOGOBJ, (evt), (mid), (a1), (a2), (a3), (a4), \
                    (a5), (a6), (a7), (a8))
   
/*
 *  ======== xdc_runtime_Log_put* ========
 *  See Log_doPut*
 */
#if (!xdc_runtime_Log_DISABLE_ALL)

#define xdc_runtime_Log_put0(evt, mid) \
    xdc_runtime_Log_doPut0(evt, mid)

#define xdc_runtime_Log_put1(evt, mid, a1) \
    xdc_runtime_Log_doPut1(evt, mid, a1)

#define xdc_runtime_Log_put2(evt, mid, a1, a2) \
    xdc_runtime_Log_doPut2(evt, mid, a1, a2)

#define xdc_runtime_Log_put4(evt, mid, a1, a2, a3, a4) \
    xdc_runtime_Log_doPut4(evt, mid, a1, a2, a3, a4)

#define xdc_runtime_Log_put8(evt, mid, a1, a2, a3, a4, a5, a6, a7, a8) \
    xdc_runtime_Log_doPut8(evt, mid, a1, a2, a3, a4, a5, a6, a7, a8)

# else

#define xdc_runtime_Log_put0(evt, mid)
#define xdc_runtime_Log_put1(evt, mid, a1)
#define xdc_runtime_Log_put2(evt, mid, a1, a2)
#define xdc_runtime_Log_put4(evt, mid, a1, a2, a3, a4)
#define xdc_runtime_Log_put8(evt, mid, a1, a2, a3, a4, a5, a6, a7, a8)

#endif

/*
 *  ======== xdc_runtime_Log_doWrite* ========
 *  The real implementations of the Log_write* APIs. See Log_doPut* for an
 *  explanation of why we stub-out the Log_put* and Log_write* APIs.
 */

#define xdc_runtime_Log_doWrite0(evt) \
    ((Module__LOGDEF && xdc_runtime_Diags_query(evt)) ? \
        (xdc_runtime_Log_doPut0((evt), Module__MID)) : (void)0 \
    )
    
#define xdc_runtime_Log_doWrite1(evt, a1) \
    ((Module__LOGDEF && xdc_runtime_Diags_query(evt)) ? \
        (xdc_runtime_Log_doPut1((evt), Module__MID, (a1))) : (void)0 \
    )
     
#define xdc_runtime_Log_doWrite2(evt, a1, a2) \
    ((Module__LOGDEF && xdc_runtime_Diags_query(evt)) ? \
        (xdc_runtime_Log_doPut2((evt), Module__MID, (a1), (a2))) : (void)0 \
    )
    
#define xdc_runtime_Log_doWrite3(evt, a1, a2, a3) \
    xdc_runtime_Log_doWrite4(evt, a1, a2, a3, 0)

#define xdc_runtime_Log_doWrite4(evt, a1, a2, a3, a4) \
    ((Module__LOGDEF && xdc_runtime_Diags_query(evt)) ? \
        xdc_runtime_Log_doPut4((evt), Module__MID, (a1), (a2), \
            (a3), (a4)) : (void)0 \
    )

#define xdc_runtime_Log_doWrite5(evt, a1, a2, a3, a4, a5) \
    xdc_runtime_Log_doWrite8(evt, a1, a2, a3, a4, a5, 0, 0, 0)
#define xdc_runtime_Log_doWrite6(evt, a1, a2, a3, a4, a5, a6) \
    xdc_runtime_Log_doWrite8(evt, a1, a2, a3, a4, a5, a6, 0, 0)
#define xdc_runtime_Log_doWrite7(evt, a1, a2, a3, a4, a5, a6, a7) \
    xdc_runtime_Log_doWrite8(evt, a1, a2, a3, a4, a5, a6, a7, 0)

#define xdc_runtime_Log_doWrite8(evt, a1, a2, a3, a4, a5, a6, a7, a8) \
    ((Module__LOGDEF && xdc_runtime_Diags_query(evt)) ? \
        xdc_runtime_Log_doPut8((evt), Module__MID, \
            (a1), (a2), (a3), (a4), (a5), (a6), (a7), (a8)) : (void)0 \
    )

/*
 *  ======== xdc_runtime_Log_write* ========
 *  See Log_doWrite*
 */
#if (!xdc_runtime_Log_DISABLE_ALL)
 
#define xdc_runtime_Log_write0(evt) \
    xdc_runtime_Log_doWrite0(evt)
    
#define xdc_runtime_Log_write1(evt, a1) \
    xdc_runtime_Log_doWrite1(evt, a1)
    
#define xdc_runtime_Log_write2(evt, a1, a2) \
    xdc_runtime_Log_doWrite2(evt, a1, a2)
    
#define xdc_runtime_Log_write3(evt, a1, a2, a3) \
    xdc_runtime_Log_doWrite3(evt, a1, a2, a3)

#define xdc_runtime_Log_write4(evt, a1, a2, a3, a4) \
    xdc_runtime_Log_doWrite4(evt, a1, a2, a3, a4)

#define xdc_runtime_Log_write5(evt, a1, a2, a3, a4, a5) \
    xdc_runtime_Log_doWrite5(evt, a1, a2, a3, a4, a5)
    
#define xdc_runtime_Log_write6(evt, a1, a2, a3, a4, a5, a6) \
    xdc_runtime_Log_doWrite6(evt, a1, a2, a3, a4, a5, a6)
    
#define xdc_runtime_Log_write7(evt, a1, a2, a3, a4, a5, a6, a7) \
    xdc_runtime_Log_doWrite7(evt, a1, a2, a3, a4, a5, a6, a7)

#define xdc_runtime_Log_write8(evt, a1, a2, a3, a4, a5, a6, a7, a8) \
    xdc_runtime_Log_doWrite8(evt, a1, a2, a3, a4, a5, a6, a7, a8)
    
#else

#define xdc_runtime_Log_write0(evt)
#define xdc_runtime_Log_write1(evt, a1)  
#define xdc_runtime_Log_write2(evt, a1, a2)
#define xdc_runtime_Log_write3(evt, a1, a2, a3)
#define xdc_runtime_Log_write4(evt, a1, a2, a3, a4)
#define xdc_runtime_Log_write5(evt, a1, a2, a3, a4, a5)
#define xdc_runtime_Log_write6(evt, a1, a2, a3, a4, a5, a6)
#define xdc_runtime_Log_write7(evt, a1, a2, a3, a4, a5, a6, a7)
#define xdc_runtime_Log_write8(evt, a1, a2, a3, a4, a5, a6, a7, a8)

#endif
  
/*
 *  ======== xdc_runtime_Log_print* ========
 *  Since "print" events do not have a rope, we use 0 (an invalid rope value)
 *  as the event Id and construct a Log_Event to pass to Log_put. This has the 
 *  benefit that the Log_Event is equal to just the mask: (0 | mask). For this 
 *  reason, we simply pass the 'mask' as the first argument to 'put'.
 *
 *  Each print function is mapped to a call to appropriate 'put' function.
 *  print0 -> put1
 *  print1 -> put2
 *  print2 -> print3 -> put4
 *  print3 -> put4
 *  print4 -> print6 -> put8
 *  print5 -> print6 -> put8
 *  print6 -> put8
 */
#if (!xdc_runtime_Log_DISABLE_ALL)
 
#define xdc_runtime_Log_print0(mask, fmt) \
    ((Module__LOGDEF && xdc_runtime_Diags_query(mask)) ? \
        xdc_runtime_Log_doPut1(mask, Module__MID, (IArg) fmt) : (void)0 \
    )
    
#define xdc_runtime_Log_print1(mask, fmt, a1) \
    ( (Module__LOGDEF && xdc_runtime_Diags_query(mask)) ? \
        xdc_runtime_Log_doPut2(mask, Module__MID, (IArg) fmt, (a1)) : (void)0 \
    )
    
#define xdc_runtime_Log_print2(mask, fmt, a1, a2) \
    xdc_runtime_Log_print3(mask, fmt, a1, a2, 0)

#define xdc_runtime_Log_print3(mask, fmt, a1, a2, a3) \
    ((Module__LOGDEF && xdc_runtime_Diags_query(mask)) ? \
        xdc_runtime_Log_doPut4(mask, Module__MID, (IArg) fmt, \
                             (a1), (a2), (a3)) : (void)0 \
    )

#define xdc_runtime_Log_print4(mask, fmt, a1, a2, a3, a4) \
    xdc_runtime_Log_print6(mask, fmt, a1, a2, a3, a4, 0, 0)
#define xdc_runtime_Log_print5(mask, fmt, a1, a2, a3, a4, a5) \
    xdc_runtime_Log_print6(mask, fmt, a1, a2, a3, a4, a5, 0)

#define xdc_runtime_Log_print6(mask, fmt, a1, a2, a3, a4, a5, a6) \
    ((Module__LOGDEF && xdc_runtime_Diags_query(mask)) ?    \
        xdc_runtime_Log_doPut8(mask, Module__MID, \
            (IArg)fmt, (a1), (a2), (a3), (a4), (a5), (a6), 0) : (void)0  \
    )

#else

#define xdc_runtime_Log_print0(mask, fmt)
#define xdc_runtime_Log_print1(mask, fmt, a1)
#define xdc_runtime_Log_print2(mask, fmt, a1, a2)
#define xdc_runtime_Log_print3(mask, fmt, a1, a2, a3)
#define xdc_runtime_Log_print4(mask, fmt, a1, a2, a3, a4)
#define xdc_runtime_Log_print5(mask, fmt, a1, a2, a3, a4, a5)
#define xdc_runtime_Log_print6(mask, fmt, a1, a2, a3, a4, a5, a6)

#endif    

/*
 *  ======== xdc_runtime_Log_error* ========
 *  Log an error event
 */
#if xdc_runtime_Log_ENABLE_ERROR
 
#define xdc_runtime_Log_error0(fmt) \
    xdc_runtime_Log_error1(fmt,0)
        
#define xdc_runtime_Log_error1(fmt, a1) \
    ((Module__LOGDEF && xdc_runtime_Diags_query(Log_L_error)) ? \
        xdc_runtime_Log_doPut4((Log_L_error), Module__MID, \
            (IArg) xdc_FILE__, (IArg)__LINE__, (IArg)fmt, (a1)) : (void)0 \
    )       
    
#define xdc_runtime_Log_error2(fmt, a1, a2) \
    xdc_runtime_Log_error5(fmt, a1, a2, 0, 0, 0)
#define xdc_runtime_Log_error3(fmt, a1, a2, a3) \
    xdc_runtime_Log_error5(fmt, a1, a2, a3, 0, 0)
#define xdc_runtime_Log_error4(fmt, a1, a2, a3, a4) \
    xdc_runtime_Log_error5(fmt, a1, a2, a3, a4, 0)
    
#define xdc_runtime_Log_error5(fmt, a1, a2, a3, a4, a5) \
    ((Module__LOGDEF && xdc_runtime_Diags_query(Log_L_error)) ? \
        xdc_runtime_Log_doPut8((Log_L_error), Module__MID, (IArg) xdc_FILE__, \
             (IArg)__LINE__, (IArg)fmt, (a1), (a2), (a3), \
             (a4), (a5)) : (void)0 \
    )

#else

#define xdc_runtime_Log_error0(fmt)
#define xdc_runtime_Log_error1(fmt, a1)
#define xdc_runtime_Log_error2(fmt, a1, a2)
#define xdc_runtime_Log_error3(fmt, a1, a2, a3)
#define xdc_runtime_Log_error4(fmt, a1, a2, a3, a4)
#define xdc_runtime_Log_error5(fmt, a1, a2, a3, a4, a5)

#endif
    
/*
 *  ======== xdc_runtime_Log_warning* ========
 *  Log a warning event
 */
#if xdc_runtime_Log_ENABLE_WARNING
 
#define xdc_runtime_Log_warning0(fmt) \
    xdc_runtime_Log_warning1(fmt,0)
    
#define xdc_runtime_Log_warning1(fmt, a1) \
    ((Module__LOGDEF && xdc_runtime_Diags_query(Log_L_warning)) ? \
        xdc_runtime_Log_doPut4((Log_L_warning), Module__MID, \
            (IArg) xdc_FILE__, (IArg) __LINE__, (IArg) fmt, a1) : (void)0 \
    )
    
#define xdc_runtime_Log_warning2(fmt, a1, a2) \
    xdc_runtime_Log_warning5(fmt, a1, a2, 0, 0, 0)
#define xdc_runtime_Log_warning3(fmt, a1, a2, a3) \
    xdc_runtime_Log_warning5(fmt, a1, a2, a3, 0, 0)
#define xdc_runtime_Log_warning4(fmt, a1, a2, a3, a4) \
    xdc_runtime_Log_warning5(fmt, a1, a2, a3, a4, 0)
    
#define xdc_runtime_Log_warning5(fmt, a1, a2, a3, a4, a5) \
    ((Module__LOGDEF && xdc_runtime_Diags_query(Log_L_warning)) ? \
        xdc_runtime_Log_doPut8((Log_L_warning), Module__MID, (IArg) xdc_FILE__, \
            (IArg) __LINE__, (IArg) fmt, (a1), (a2), (a3), \
            (a4), (a5)) : (void)0 \
    )

#else

#define xdc_runtime_Log_warning0(fmt)
#define xdc_runtime_Log_warning1(fmt, a1)
#define xdc_runtime_Log_warning2(fmt, a1, a2)
#define xdc_runtime_Log_warning3(fmt, a1, a2, a3)
#define xdc_runtime_Log_warning4(fmt, a1, a2, a3, a4)
#define xdc_runtime_Log_warning5(fmt, a1, a2, a3, a4, a5)

#endif
    
/*
 *  ======== xdc_runtime_Log_info* ========
 *  Log an informational event
 */
#if xdc_runtime_Log_ENABLE_INFO

#define xdc_runtime_Log_info0(fmt) \
    xdc_runtime_Log_info1(fmt,0)
    
#define xdc_runtime_Log_info1(fmt, a1) \
    ((Module__LOGDEF && xdc_runtime_Diags_query(Log_L_info)) ? \
        xdc_runtime_Log_doPut4((Log_L_info), Module__MID, (IArg) xdc_FILE__, \
             (IArg) __LINE__, (IArg) fmt, (a1)) : (void)0 \
    )       
    
#define xdc_runtime_Log_info2(fmt, a1, a2) \
    xdc_runtime_Log_info5(fmt, a1, a2, 0, 0, 0)
#define xdc_runtime_Log_info3(fmt, a1, a2, a3) \
    xdc_runtime_Log_info5(fmt, a1, a2, a3, 0, 0)
#define xdc_runtime_Log_info4(fmt, a1, a2, a3, a4) \
    xdc_runtime_Log_info5(fmt, a1, a2, a3, a4, 0)
    
#define xdc_runtime_Log_info5(fmt, a1, a2, a3, a4, a5) \
    ((Module__LOGDEF && xdc_runtime_Diags_query(Log_L_info)) ? \
        xdc_runtime_Log_doPut8((Log_L_info), Module__MID, (IArg) xdc_FILE__, \
            (IArg) __LINE__, (IArg) fmt, (a1), (a2), (a3), \
            (a4), (a5)) : (void)0 \
    )

#else

#define xdc_runtime_Log_info0(fmt)
#define xdc_runtime_Log_info1(fmt, a1)
#define xdc_runtime_Log_info2(fmt, a1, a2)
#define xdc_runtime_Log_info3(fmt, a1, a2, a3)
#define xdc_runtime_Log_info4(fmt, a1, a2, a3, a4)
#define xdc_runtime_Log_info5(fmt, a1, a2, a3, a4, a5)

#endif
/*
 *  @(#) xdc.runtime; 2, 1, 0,0; 4-24-2015 12:34:12; /db/ztree/library/trees/xdc/xdc-A71/src/packages/
 */

