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

#ifndef ti_sysbios_interfaces_ITaskSupport__include
#define ti_sysbios_interfaces_ITaskSupport__include

#ifndef __nested__
#define __nested__
#define ti_sysbios_interfaces_ITaskSupport__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define ti_sysbios_interfaces_ITaskSupport___VERS 160


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

/* FuncPtr */
typedef xdc_Void (*ti_sysbios_interfaces_ITaskSupport_FuncPtr)(void);


/*
 * ======== VIRTUAL FUNCTIONS ========
 */

/* Fxns__ */
struct ti_sysbios_interfaces_ITaskSupport_Fxns__ {
    xdc_runtime_Types_Base* __base;
    const xdc_runtime_Types_SysFxns2 *__sysp;
    xdc_Ptr (*start)(xdc_Ptr, ti_sysbios_interfaces_ITaskSupport_FuncPtr, ti_sysbios_interfaces_ITaskSupport_FuncPtr, xdc_runtime_Error_Block*);
    xdc_Void (*swap)(xdc_Ptr*, xdc_Ptr*);
    xdc_Bool (*checkStack)(xdc_Char*, xdc_SizeT);
    xdc_SizeT (*stackUsed)(xdc_Char*, xdc_SizeT);
    xdc_UInt (*getStackAlignment)(void);
    xdc_SizeT (*getDefaultStackSize)(void);
    xdc_runtime_Types_SysFxns2 __sfxns;
};

/* Interface__BASE__C */
__extern const xdc_runtime_Types_Base ti_sysbios_interfaces_ITaskSupport_Interface__BASE__C;


/*
 * ======== FUNCTION STUBS ========
 */

/* Module_id */
static inline xdc_runtime_Types_ModuleId ti_sysbios_interfaces_ITaskSupport_Module_id( ti_sysbios_interfaces_ITaskSupport_Module mod )
{
    return mod->__sysp->__mid;
}

/* start */
static inline xdc_Ptr ti_sysbios_interfaces_ITaskSupport_start( ti_sysbios_interfaces_ITaskSupport_Module __inst, xdc_Ptr curTask, ti_sysbios_interfaces_ITaskSupport_FuncPtr enter, ti_sysbios_interfaces_ITaskSupport_FuncPtr exit, xdc_runtime_Error_Block *eb )
{
    return __inst->start(curTask, enter, exit, eb);
}

/* swap */
static inline xdc_Void ti_sysbios_interfaces_ITaskSupport_swap( ti_sysbios_interfaces_ITaskSupport_Module __inst, xdc_Ptr *oldtskContext, xdc_Ptr *newtskContext )
{
    __inst->swap(oldtskContext, newtskContext);
}

/* checkStack */
static inline xdc_Bool ti_sysbios_interfaces_ITaskSupport_checkStack( ti_sysbios_interfaces_ITaskSupport_Module __inst, xdc_Char *stack, xdc_SizeT size )
{
    return __inst->checkStack(stack, size);
}

/* stackUsed */
static inline xdc_SizeT ti_sysbios_interfaces_ITaskSupport_stackUsed( ti_sysbios_interfaces_ITaskSupport_Module __inst, xdc_Char *stack, xdc_SizeT size )
{
    return __inst->stackUsed(stack, size);
}

/* getStackAlignment */
static inline xdc_UInt ti_sysbios_interfaces_ITaskSupport_getStackAlignment( ti_sysbios_interfaces_ITaskSupport_Module __inst )
{
    return __inst->getStackAlignment();
}

/* getDefaultStackSize */
static inline xdc_SizeT ti_sysbios_interfaces_ITaskSupport_getDefaultStackSize( ti_sysbios_interfaces_ITaskSupport_Module __inst )
{
    return __inst->getDefaultStackSize();
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

/* start_{FxnT,fxnP} */
typedef xdc_Ptr (*ti_sysbios_interfaces_ITaskSupport_start_FxnT)(xdc_Ptr, ti_sysbios_interfaces_ITaskSupport_FuncPtr, ti_sysbios_interfaces_ITaskSupport_FuncPtr, xdc_runtime_Error_Block*);
static inline ti_sysbios_interfaces_ITaskSupport_start_FxnT ti_sysbios_interfaces_ITaskSupport_start_fxnP( ti_sysbios_interfaces_ITaskSupport_Module __inst )
{
    return (ti_sysbios_interfaces_ITaskSupport_start_FxnT)__inst->start;
}

/* swap_{FxnT,fxnP} */
typedef xdc_Void (*ti_sysbios_interfaces_ITaskSupport_swap_FxnT)(xdc_Ptr*, xdc_Ptr*);
static inline ti_sysbios_interfaces_ITaskSupport_swap_FxnT ti_sysbios_interfaces_ITaskSupport_swap_fxnP( ti_sysbios_interfaces_ITaskSupport_Module __inst )
{
    return (ti_sysbios_interfaces_ITaskSupport_swap_FxnT)__inst->swap;
}

/* checkStack_{FxnT,fxnP} */
typedef xdc_Bool (*ti_sysbios_interfaces_ITaskSupport_checkStack_FxnT)(xdc_Char*, xdc_SizeT);
static inline ti_sysbios_interfaces_ITaskSupport_checkStack_FxnT ti_sysbios_interfaces_ITaskSupport_checkStack_fxnP( ti_sysbios_interfaces_ITaskSupport_Module __inst )
{
    return (ti_sysbios_interfaces_ITaskSupport_checkStack_FxnT)__inst->checkStack;
}

/* stackUsed_{FxnT,fxnP} */
typedef xdc_SizeT (*ti_sysbios_interfaces_ITaskSupport_stackUsed_FxnT)(xdc_Char*, xdc_SizeT);
static inline ti_sysbios_interfaces_ITaskSupport_stackUsed_FxnT ti_sysbios_interfaces_ITaskSupport_stackUsed_fxnP( ti_sysbios_interfaces_ITaskSupport_Module __inst )
{
    return (ti_sysbios_interfaces_ITaskSupport_stackUsed_FxnT)__inst->stackUsed;
}

/* getStackAlignment_{FxnT,fxnP} */
typedef xdc_UInt (*ti_sysbios_interfaces_ITaskSupport_getStackAlignment_FxnT)(void);
static inline ti_sysbios_interfaces_ITaskSupport_getStackAlignment_FxnT ti_sysbios_interfaces_ITaskSupport_getStackAlignment_fxnP( ti_sysbios_interfaces_ITaskSupport_Module __inst )
{
    return (ti_sysbios_interfaces_ITaskSupport_getStackAlignment_FxnT)__inst->getStackAlignment;
}

/* getDefaultStackSize_{FxnT,fxnP} */
typedef xdc_SizeT (*ti_sysbios_interfaces_ITaskSupport_getDefaultStackSize_FxnT)(void);
static inline ti_sysbios_interfaces_ITaskSupport_getDefaultStackSize_FxnT ti_sysbios_interfaces_ITaskSupport_getDefaultStackSize_fxnP( ti_sysbios_interfaces_ITaskSupport_Module __inst )
{
    return (ti_sysbios_interfaces_ITaskSupport_getDefaultStackSize_FxnT)__inst->getDefaultStackSize;
}


/*
 * ======== EPILOGUE ========
 */

#ifdef ti_sysbios_interfaces_ITaskSupport__top__
#undef __nested__
#endif

#endif /* ti_sysbios_interfaces_ITaskSupport__include */


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(ti_sysbios_interfaces_ITaskSupport__nolocalnames)

#ifndef ti_sysbios_interfaces_ITaskSupport__localnames__done
#define ti_sysbios_interfaces_ITaskSupport__localnames__done

/* module prefix */
#define ITaskSupport_Module ti_sysbios_interfaces_ITaskSupport_Module
#define ITaskSupport_FuncPtr ti_sysbios_interfaces_ITaskSupport_FuncPtr
#define ITaskSupport_start ti_sysbios_interfaces_ITaskSupport_start
#define ITaskSupport_start_fxnP ti_sysbios_interfaces_ITaskSupport_start_fxnP
#define ITaskSupport_start_FxnT ti_sysbios_interfaces_ITaskSupport_start_FxnT
#define ITaskSupport_swap ti_sysbios_interfaces_ITaskSupport_swap
#define ITaskSupport_swap_fxnP ti_sysbios_interfaces_ITaskSupport_swap_fxnP
#define ITaskSupport_swap_FxnT ti_sysbios_interfaces_ITaskSupport_swap_FxnT
#define ITaskSupport_checkStack ti_sysbios_interfaces_ITaskSupport_checkStack
#define ITaskSupport_checkStack_fxnP ti_sysbios_interfaces_ITaskSupport_checkStack_fxnP
#define ITaskSupport_checkStack_FxnT ti_sysbios_interfaces_ITaskSupport_checkStack_FxnT
#define ITaskSupport_stackUsed ti_sysbios_interfaces_ITaskSupport_stackUsed
#define ITaskSupport_stackUsed_fxnP ti_sysbios_interfaces_ITaskSupport_stackUsed_fxnP
#define ITaskSupport_stackUsed_FxnT ti_sysbios_interfaces_ITaskSupport_stackUsed_FxnT
#define ITaskSupport_getStackAlignment ti_sysbios_interfaces_ITaskSupport_getStackAlignment
#define ITaskSupport_getStackAlignment_fxnP ti_sysbios_interfaces_ITaskSupport_getStackAlignment_fxnP
#define ITaskSupport_getStackAlignment_FxnT ti_sysbios_interfaces_ITaskSupport_getStackAlignment_FxnT
#define ITaskSupport_getDefaultStackSize ti_sysbios_interfaces_ITaskSupport_getDefaultStackSize
#define ITaskSupport_getDefaultStackSize_fxnP ti_sysbios_interfaces_ITaskSupport_getDefaultStackSize_fxnP
#define ITaskSupport_getDefaultStackSize_FxnT ti_sysbios_interfaces_ITaskSupport_getDefaultStackSize_FxnT
#define ITaskSupport_Module_name ti_sysbios_interfaces_ITaskSupport_Module_name

#endif /* ti_sysbios_interfaces_ITaskSupport__localnames__done */
#endif
