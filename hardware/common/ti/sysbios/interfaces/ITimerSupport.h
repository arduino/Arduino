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
 *     
 *     EPILOGUE
 *     PREFIX ALIASES
 */


/*
 * ======== PROLOGUE ========
 */

#ifndef ti_sysbios_interfaces_ITimerSupport__include
#define ti_sysbios_interfaces_ITimerSupport__include

#ifndef __nested__
#define __nested__
#define ti_sysbios_interfaces_ITimerSupport__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define ti_sysbios_interfaces_ITimerSupport___VERS 160


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <ti/sysbios/interfaces/package/package.defs.h>

#include <xdc/runtime/Error.h>
#include <xdc/runtime/IModule.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */


/*
 * ======== VIRTUAL FUNCTIONS ========
 */

/* Fxns__ */
struct ti_sysbios_interfaces_ITimerSupport_Fxns__ {
    xdc_runtime_Types_Base* __base;
    const xdc_runtime_Types_SysFxns2 *__sysp;
    xdc_Void (*enable)(xdc_UInt, xdc_runtime_Error_Block*);
    xdc_runtime_Types_SysFxns2 __sfxns;
};

/* Interface__BASE__C */
__extern const xdc_runtime_Types_Base ti_sysbios_interfaces_ITimerSupport_Interface__BASE__C;


/*
 * ======== FUNCTION STUBS ========
 */

/* Module_id */
static inline xdc_runtime_Types_ModuleId ti_sysbios_interfaces_ITimerSupport_Module_id( ti_sysbios_interfaces_ITimerSupport_Module mod )
{
    return mod->__sysp->__mid;
}

/* enable */
static inline xdc_Void ti_sysbios_interfaces_ITimerSupport_enable( ti_sysbios_interfaces_ITimerSupport_Module __inst, xdc_UInt timerId, xdc_runtime_Error_Block *eb )
{
    __inst->enable(timerId, eb);
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

/* enable_{FxnT,fxnP} */
typedef xdc_Void (*ti_sysbios_interfaces_ITimerSupport_enable_FxnT)(xdc_UInt, xdc_runtime_Error_Block*);
static inline ti_sysbios_interfaces_ITimerSupport_enable_FxnT ti_sysbios_interfaces_ITimerSupport_enable_fxnP( ti_sysbios_interfaces_ITimerSupport_Module __inst )
{
    return (ti_sysbios_interfaces_ITimerSupport_enable_FxnT)__inst->enable;
}


/*
 * ======== EPILOGUE ========
 */

#ifdef ti_sysbios_interfaces_ITimerSupport__top__
#undef __nested__
#endif

#endif /* ti_sysbios_interfaces_ITimerSupport__include */


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(ti_sysbios_interfaces_ITimerSupport__nolocalnames)

#ifndef ti_sysbios_interfaces_ITimerSupport__localnames__done
#define ti_sysbios_interfaces_ITimerSupport__localnames__done

/* module prefix */
#define ITimerSupport_Module ti_sysbios_interfaces_ITimerSupport_Module
#define ITimerSupport_enable ti_sysbios_interfaces_ITimerSupport_enable
#define ITimerSupport_enable_fxnP ti_sysbios_interfaces_ITimerSupport_enable_fxnP
#define ITimerSupport_enable_FxnT ti_sysbios_interfaces_ITimerSupport_enable_FxnT
#define ITimerSupport_Module_name ti_sysbios_interfaces_ITimerSupport_Module_name

#endif /* ti_sysbios_interfaces_ITimerSupport__localnames__done */
#endif
