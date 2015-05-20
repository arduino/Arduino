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

#ifndef ti_sysbios_interfaces_IRomDevice__include
#define ti_sysbios_interfaces_IRomDevice__include

#ifndef __nested__
#define __nested__
#define ti_sysbios_interfaces_IRomDevice__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define ti_sysbios_interfaces_IRomDevice___VERS 160


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
struct ti_sysbios_interfaces_IRomDevice_Fxns__ {
    xdc_runtime_Types_Base* __base;
    const xdc_runtime_Types_SysFxns2 *__sysp;
    xdc_UInt (*getRevision)(void);
    xdc_Void (*checkRevision)(void);
    xdc_runtime_Types_SysFxns2 __sfxns;
};

/* Interface__BASE__C */
__extern const xdc_runtime_Types_Base ti_sysbios_interfaces_IRomDevice_Interface__BASE__C;


/*
 * ======== FUNCTION STUBS ========
 */

/* Module_id */
static inline xdc_runtime_Types_ModuleId ti_sysbios_interfaces_IRomDevice_Module_id( ti_sysbios_interfaces_IRomDevice_Module mod )
{
    return mod->__sysp->__mid;
}

/* getRevision */
static inline xdc_UInt ti_sysbios_interfaces_IRomDevice_getRevision( ti_sysbios_interfaces_IRomDevice_Module __inst )
{
    return __inst->getRevision();
}

/* checkRevision */
static inline xdc_Void ti_sysbios_interfaces_IRomDevice_checkRevision( ti_sysbios_interfaces_IRomDevice_Module __inst )
{
    __inst->checkRevision();
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

/* getRevision_{FxnT,fxnP} */
typedef xdc_UInt (*ti_sysbios_interfaces_IRomDevice_getRevision_FxnT)(void);
static inline ti_sysbios_interfaces_IRomDevice_getRevision_FxnT ti_sysbios_interfaces_IRomDevice_getRevision_fxnP( ti_sysbios_interfaces_IRomDevice_Module __inst )
{
    return (ti_sysbios_interfaces_IRomDevice_getRevision_FxnT)__inst->getRevision;
}

/* checkRevision_{FxnT,fxnP} */
typedef xdc_Void (*ti_sysbios_interfaces_IRomDevice_checkRevision_FxnT)(void);
static inline ti_sysbios_interfaces_IRomDevice_checkRevision_FxnT ti_sysbios_interfaces_IRomDevice_checkRevision_fxnP( ti_sysbios_interfaces_IRomDevice_Module __inst )
{
    return (ti_sysbios_interfaces_IRomDevice_checkRevision_FxnT)__inst->checkRevision;
}


/*
 * ======== EPILOGUE ========
 */

#ifdef ti_sysbios_interfaces_IRomDevice__top__
#undef __nested__
#endif

#endif /* ti_sysbios_interfaces_IRomDevice__include */


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(ti_sysbios_interfaces_IRomDevice__nolocalnames)

#ifndef ti_sysbios_interfaces_IRomDevice__localnames__done
#define ti_sysbios_interfaces_IRomDevice__localnames__done

/* module prefix */
#define IRomDevice_Module ti_sysbios_interfaces_IRomDevice_Module
#define IRomDevice_getRevision ti_sysbios_interfaces_IRomDevice_getRevision
#define IRomDevice_getRevision_fxnP ti_sysbios_interfaces_IRomDevice_getRevision_fxnP
#define IRomDevice_getRevision_FxnT ti_sysbios_interfaces_IRomDevice_getRevision_FxnT
#define IRomDevice_checkRevision ti_sysbios_interfaces_IRomDevice_checkRevision
#define IRomDevice_checkRevision_fxnP ti_sysbios_interfaces_IRomDevice_checkRevision_fxnP
#define IRomDevice_checkRevision_FxnT ti_sysbios_interfaces_IRomDevice_checkRevision_FxnT
#define IRomDevice_Module_name ti_sysbios_interfaces_IRomDevice_Module_name

#endif /* ti_sysbios_interfaces_IRomDevice__localnames__done */
#endif
