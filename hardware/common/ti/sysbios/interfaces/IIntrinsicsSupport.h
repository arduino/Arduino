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

#ifndef ti_sysbios_interfaces_IIntrinsicsSupport__include
#define ti_sysbios_interfaces_IIntrinsicsSupport__include

#ifndef __nested__
#define __nested__
#define ti_sysbios_interfaces_IIntrinsicsSupport__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define ti_sysbios_interfaces_IIntrinsicsSupport___VERS 160


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <ti/sysbios/interfaces/package/package.defs.h>

#include <xdc/runtime/IModule.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */


/*
 * ======== VIRTUAL FUNCTIONS ========
 */

/* Fxns__ */
struct ti_sysbios_interfaces_IIntrinsicsSupport_Fxns__ {
    xdc_runtime_Types_Base* __base;
    const xdc_runtime_Types_SysFxns2 *__sysp;
    xdc_UInt (*maxbit)(xdc_UInt);
    xdc_runtime_Types_SysFxns2 __sfxns;
};

/* Interface__BASE__C */
__extern const xdc_runtime_Types_Base ti_sysbios_interfaces_IIntrinsicsSupport_Interface__BASE__C;


/*
 * ======== FUNCTION STUBS ========
 */

/* Module_id */
static inline xdc_runtime_Types_ModuleId ti_sysbios_interfaces_IIntrinsicsSupport_Module_id( ti_sysbios_interfaces_IIntrinsicsSupport_Module mod )
{
    return mod->__sysp->__mid;
}

/* maxbit */
static inline xdc_UInt ti_sysbios_interfaces_IIntrinsicsSupport_maxbit( ti_sysbios_interfaces_IIntrinsicsSupport_Module __inst, xdc_UInt bits )
{
    return __inst->maxbit(bits);
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

/* maxbit_{FxnT,fxnP} */
typedef xdc_UInt (*ti_sysbios_interfaces_IIntrinsicsSupport_maxbit_FxnT)(xdc_UInt);
static inline ti_sysbios_interfaces_IIntrinsicsSupport_maxbit_FxnT ti_sysbios_interfaces_IIntrinsicsSupport_maxbit_fxnP( ti_sysbios_interfaces_IIntrinsicsSupport_Module __inst )
{
    return (ti_sysbios_interfaces_IIntrinsicsSupport_maxbit_FxnT)__inst->maxbit;
}


/*
 * ======== EPILOGUE ========
 */

#ifdef ti_sysbios_interfaces_IIntrinsicsSupport__top__
#undef __nested__
#endif

#endif /* ti_sysbios_interfaces_IIntrinsicsSupport__include */


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(ti_sysbios_interfaces_IIntrinsicsSupport__nolocalnames)

#ifndef ti_sysbios_interfaces_IIntrinsicsSupport__localnames__done
#define ti_sysbios_interfaces_IIntrinsicsSupport__localnames__done

/* module prefix */
#define IIntrinsicsSupport_Module ti_sysbios_interfaces_IIntrinsicsSupport_Module
#define IIntrinsicsSupport_maxbit ti_sysbios_interfaces_IIntrinsicsSupport_maxbit
#define IIntrinsicsSupport_maxbit_fxnP ti_sysbios_interfaces_IIntrinsicsSupport_maxbit_fxnP
#define IIntrinsicsSupport_maxbit_FxnT ti_sysbios_interfaces_IIntrinsicsSupport_maxbit_FxnT
#define IIntrinsicsSupport_Module_name ti_sysbios_interfaces_IIntrinsicsSupport_Module_name

#endif /* ti_sysbios_interfaces_IIntrinsicsSupport__localnames__done */
#endif
