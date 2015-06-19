/*
 *  Do not modify this file; it is automatically 
 *  generated and any modifications will be overwritten.
 *
 * @(#) xdc-A71
 */

/*
 * ======== GENERATED SECTIONS ========
 *     
 *     PROLOGUE
 *     INCLUDES
 *     
 *     VIRTUAL FUNCTIONS
 *     FUNCTION STUBS
 *     FUNCTION SELECTORS
 *     CONVERTORS
 *     
 *     EPILOGUE
 *     PREFIX ALIASES
 */


/*
 * ======== PROLOGUE ========
 */

#ifndef ti_sysbios_interfaces_ITimestamp__include
#define ti_sysbios_interfaces_ITimestamp__include

#ifndef __nested__
#define __nested__
#define ti_sysbios_interfaces_ITimestamp__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define ti_sysbios_interfaces_ITimestamp___VERS 160


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <ti/sysbios/interfaces/package/package.defs.h>

#include <xdc/runtime/Types.h>
#include <xdc/runtime/ITimestampProvider.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */


/*
 * ======== VIRTUAL FUNCTIONS ========
 */

/* Fxns__ */
struct ti_sysbios_interfaces_ITimestamp_Fxns__ {
    xdc_runtime_Types_Base* __base;
    const xdc_runtime_Types_SysFxns2 *__sysp;
    xdc_Bits32 (*get32)(void);
    xdc_Void (*get64)(xdc_runtime_Types_Timestamp64*);
    xdc_Void (*getFreq)(xdc_runtime_Types_FreqHz*);
    xdc_runtime_Types_SysFxns2 __sfxns;
};

/* Interface__BASE__C */
__extern const xdc_runtime_Types_Base ti_sysbios_interfaces_ITimestamp_Interface__BASE__C;


/*
 * ======== FUNCTION STUBS ========
 */

/* Module_id */
static inline xdc_runtime_Types_ModuleId ti_sysbios_interfaces_ITimestamp_Module_id( ti_sysbios_interfaces_ITimestamp_Module mod )
{
    return mod->__sysp->__mid;
}


/*
 * ======== FUNCTION SELECTORS ========
 */

/* These functions return function pointers for module and instance functions.
 * The functions accept modules and instances declared as types defined in this
 * interface, but they return functions defined for the actual objects passed
 * as parameters. These functions are not invoked by any generated code or
 * XDCtools internal code.
 */

/* get32_{FxnT,fxnP} */
typedef xdc_Bits32 (*ti_sysbios_interfaces_ITimestamp_get32_FxnT)(void);
static inline ti_sysbios_interfaces_ITimestamp_get32_FxnT ti_sysbios_interfaces_ITimestamp_get32_fxnP( ti_sysbios_interfaces_ITimestamp_Module __inst )
{
    return (ti_sysbios_interfaces_ITimestamp_get32_FxnT)__inst->get32;
}

/* get64_{FxnT,fxnP} */
typedef xdc_Void (*ti_sysbios_interfaces_ITimestamp_get64_FxnT)(xdc_runtime_Types_Timestamp64*);
static inline ti_sysbios_interfaces_ITimestamp_get64_FxnT ti_sysbios_interfaces_ITimestamp_get64_fxnP( ti_sysbios_interfaces_ITimestamp_Module __inst )
{
    return (ti_sysbios_interfaces_ITimestamp_get64_FxnT)__inst->get64;
}

/* getFreq_{FxnT,fxnP} */
typedef xdc_Void (*ti_sysbios_interfaces_ITimestamp_getFreq_FxnT)(xdc_runtime_Types_FreqHz*);
static inline ti_sysbios_interfaces_ITimestamp_getFreq_FxnT ti_sysbios_interfaces_ITimestamp_getFreq_fxnP( ti_sysbios_interfaces_ITimestamp_Module __inst )
{
    return (ti_sysbios_interfaces_ITimestamp_getFreq_FxnT)__inst->getFreq;
}


/*
 * ======== CONVERTORS ========
 */

/* Module_upCast */
static inline xdc_runtime_ITimestampProvider_Module ti_sysbios_interfaces_ITimestamp_Module_upCast( ti_sysbios_interfaces_ITimestamp_Module m )
{
    return(xdc_runtime_ITimestampProvider_Module)m;
}

/* Module_to_xdc_runtime_ITimestampProvider */
#define ti_sysbios_interfaces_ITimestamp_Module_to_xdc_runtime_ITimestampProvider ti_sysbios_interfaces_ITimestamp_Module_upCast

/* Module_downCast */
static inline ti_sysbios_interfaces_ITimestamp_Module ti_sysbios_interfaces_ITimestamp_Module_downCast( xdc_runtime_ITimestampProvider_Module m )
{
    xdc_runtime_Types_Base* b; for (b = m->__base; b; b = b->base) {
        if (b == &ti_sysbios_interfaces_ITimestamp_Interface__BASE__C) return (ti_sysbios_interfaces_ITimestamp_Module)m;
    } return 0;
}

/* Module_from_xdc_runtime_ITimestampProvider */
#define ti_sysbios_interfaces_ITimestamp_Module_from_xdc_runtime_ITimestampProvider ti_sysbios_interfaces_ITimestamp_Module_downCast

/* Module_upCast2 */
static inline xdc_runtime_ITimestampClient_Module ti_sysbios_interfaces_ITimestamp_Module_upCast2( ti_sysbios_interfaces_ITimestamp_Module m )
{
    return(xdc_runtime_ITimestampClient_Module)m;
}

/* Module_to_xdc_runtime_ITimestampClient */
#define ti_sysbios_interfaces_ITimestamp_Module_to_xdc_runtime_ITimestampClient ti_sysbios_interfaces_ITimestamp_Module_upCast2

/* Module_downCast2 */
static inline ti_sysbios_interfaces_ITimestamp_Module ti_sysbios_interfaces_ITimestamp_Module_downCast2( xdc_runtime_ITimestampClient_Module m )
{
    xdc_runtime_Types_Base* b; for (b = m->__base; b; b = b->base) {
        if (b == &ti_sysbios_interfaces_ITimestamp_Interface__BASE__C) return (ti_sysbios_interfaces_ITimestamp_Module)m;
    } return 0;
}

/* Module_from_xdc_runtime_ITimestampClient */
#define ti_sysbios_interfaces_ITimestamp_Module_from_xdc_runtime_ITimestampClient ti_sysbios_interfaces_ITimestamp_Module_downCast2


/*
 * ======== EPILOGUE ========
 */

#ifdef ti_sysbios_interfaces_ITimestamp__top__
#undef __nested__
#endif

#endif /* ti_sysbios_interfaces_ITimestamp__include */


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(ti_sysbios_interfaces_ITimestamp__nolocalnames)

#ifndef ti_sysbios_interfaces_ITimestamp__localnames__done
#define ti_sysbios_interfaces_ITimestamp__localnames__done

/* module prefix */
#define ITimestamp_Module ti_sysbios_interfaces_ITimestamp_Module
#define ITimestamp_get32 ti_sysbios_interfaces_ITimestamp_get32
#define ITimestamp_get32_fxnP ti_sysbios_interfaces_ITimestamp_get32_fxnP
#define ITimestamp_get32_FxnT ti_sysbios_interfaces_ITimestamp_get32_FxnT
#define ITimestamp_get64 ti_sysbios_interfaces_ITimestamp_get64
#define ITimestamp_get64_fxnP ti_sysbios_interfaces_ITimestamp_get64_fxnP
#define ITimestamp_get64_FxnT ti_sysbios_interfaces_ITimestamp_get64_FxnT
#define ITimestamp_getFreq ti_sysbios_interfaces_ITimestamp_getFreq
#define ITimestamp_getFreq_fxnP ti_sysbios_interfaces_ITimestamp_getFreq_fxnP
#define ITimestamp_getFreq_FxnT ti_sysbios_interfaces_ITimestamp_getFreq_FxnT
#define ITimestamp_Module_name ti_sysbios_interfaces_ITimestamp_Module_name
#define ITimestamp_Module_upCast ti_sysbios_interfaces_ITimestamp_Module_upCast
#define ITimestamp_Module_to_xdc_runtime_ITimestampProvider ti_sysbios_interfaces_ITimestamp_Module_to_xdc_runtime_ITimestampProvider
#define ITimestamp_Module_downCast ti_sysbios_interfaces_ITimestamp_Module_downCast
#define ITimestamp_Module_from_xdc_runtime_ITimestampProvider ti_sysbios_interfaces_ITimestamp_Module_from_xdc_runtime_ITimestampProvider
#define ITimestamp_Module_upCast2 ti_sysbios_interfaces_ITimestamp_Module_upCast2
#define ITimestamp_Module_to_xdc_runtime_ITimestampClient ti_sysbios_interfaces_ITimestamp_Module_to_xdc_runtime_ITimestampClient
#define ITimestamp_Module_downCast2 ti_sysbios_interfaces_ITimestamp_Module_downCast2
#define ITimestamp_Module_from_xdc_runtime_ITimestampClient ti_sysbios_interfaces_ITimestamp_Module_from_xdc_runtime_ITimestampClient

#endif /* ti_sysbios_interfaces_ITimestamp__localnames__done */
#endif
