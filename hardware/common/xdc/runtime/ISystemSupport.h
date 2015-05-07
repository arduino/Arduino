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

#ifndef xdc_runtime_ISystemSupport__include
#define xdc_runtime_ISystemSupport__include

#ifndef __nested__
#define __nested__
#define xdc_runtime_ISystemSupport__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define xdc_runtime_ISystemSupport___VERS 160


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/package/package.defs.h>

#include <xdc/runtime/IModule.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */


/*
 * ======== VIRTUAL FUNCTIONS ========
 */

/* Fxns__ */
struct xdc_runtime_ISystemSupport_Fxns__ {
    xdc_runtime_Types_Base* __base;
    const xdc_runtime_Types_SysFxns2 *__sysp;
    xdc_Void (*abort)(xdc_CString);
    xdc_Void (*exit)(xdc_Int);
    xdc_Void (*flush)(void);
    xdc_Void (*putch)(xdc_Char);
    xdc_Bool (*ready)(void);
    xdc_runtime_Types_SysFxns2 __sfxns;
};

/* Interface__BASE__C */
__extern const xdc_runtime_Types_Base xdc_runtime_ISystemSupport_Interface__BASE__C;


/*
 * ======== FUNCTION STUBS ========
 */

/* Module_id */
static inline xdc_runtime_Types_ModuleId xdc_runtime_ISystemSupport_Module_id( xdc_runtime_ISystemSupport_Module mod )
{
    return mod->__sysp->__mid;
}

/* abort */
static inline xdc_Void xdc_runtime_ISystemSupport_abort( xdc_runtime_ISystemSupport_Module __inst, xdc_CString str )
{
    __inst->abort(str);
}

/* exit */
static inline xdc_Void xdc_runtime_ISystemSupport_exit( xdc_runtime_ISystemSupport_Module __inst, xdc_Int stat )
{
    __inst->exit(stat);
}

/* flush */
static inline xdc_Void xdc_runtime_ISystemSupport_flush( xdc_runtime_ISystemSupport_Module __inst )
{
    __inst->flush();
}

/* putch */
static inline xdc_Void xdc_runtime_ISystemSupport_putch( xdc_runtime_ISystemSupport_Module __inst, xdc_Char ch )
{
    __inst->putch(ch);
}

/* ready */
static inline xdc_Bool xdc_runtime_ISystemSupport_ready( xdc_runtime_ISystemSupport_Module __inst )
{
    return __inst->ready();
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

/* abort_{FxnT,fxnP} */
typedef xdc_Void (*xdc_runtime_ISystemSupport_abort_FxnT)(xdc_CString);
static inline xdc_runtime_ISystemSupport_abort_FxnT xdc_runtime_ISystemSupport_abort_fxnP( xdc_runtime_ISystemSupport_Module __inst )
{
    return (xdc_runtime_ISystemSupport_abort_FxnT)__inst->abort;
}

/* exit_{FxnT,fxnP} */
typedef xdc_Void (*xdc_runtime_ISystemSupport_exit_FxnT)(xdc_Int);
static inline xdc_runtime_ISystemSupport_exit_FxnT xdc_runtime_ISystemSupport_exit_fxnP( xdc_runtime_ISystemSupport_Module __inst )
{
    return (xdc_runtime_ISystemSupport_exit_FxnT)__inst->exit;
}

/* flush_{FxnT,fxnP} */
typedef xdc_Void (*xdc_runtime_ISystemSupport_flush_FxnT)(void);
static inline xdc_runtime_ISystemSupport_flush_FxnT xdc_runtime_ISystemSupport_flush_fxnP( xdc_runtime_ISystemSupport_Module __inst )
{
    return (xdc_runtime_ISystemSupport_flush_FxnT)__inst->flush;
}

/* putch_{FxnT,fxnP} */
typedef xdc_Void (*xdc_runtime_ISystemSupport_putch_FxnT)(xdc_Char);
static inline xdc_runtime_ISystemSupport_putch_FxnT xdc_runtime_ISystemSupport_putch_fxnP( xdc_runtime_ISystemSupport_Module __inst )
{
    return (xdc_runtime_ISystemSupport_putch_FxnT)__inst->putch;
}

/* ready_{FxnT,fxnP} */
typedef xdc_Bool (*xdc_runtime_ISystemSupport_ready_FxnT)(void);
static inline xdc_runtime_ISystemSupport_ready_FxnT xdc_runtime_ISystemSupport_ready_fxnP( xdc_runtime_ISystemSupport_Module __inst )
{
    return (xdc_runtime_ISystemSupport_ready_FxnT)__inst->ready;
}


/*
 * ======== EPILOGUE ========
 */

#ifdef xdc_runtime_ISystemSupport__top__
#undef __nested__
#endif

#endif /* xdc_runtime_ISystemSupport__include */


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(xdc_runtime_ISystemSupport__nolocalnames)

#ifndef xdc_runtime_ISystemSupport__localnames__done
#define xdc_runtime_ISystemSupport__localnames__done

/* module prefix */
#define ISystemSupport_Module xdc_runtime_ISystemSupport_Module
#define ISystemSupport_abort xdc_runtime_ISystemSupport_abort
#define ISystemSupport_abort_fxnP xdc_runtime_ISystemSupport_abort_fxnP
#define ISystemSupport_abort_FxnT xdc_runtime_ISystemSupport_abort_FxnT
#define ISystemSupport_exit xdc_runtime_ISystemSupport_exit
#define ISystemSupport_exit_fxnP xdc_runtime_ISystemSupport_exit_fxnP
#define ISystemSupport_exit_FxnT xdc_runtime_ISystemSupport_exit_FxnT
#define ISystemSupport_flush xdc_runtime_ISystemSupport_flush
#define ISystemSupport_flush_fxnP xdc_runtime_ISystemSupport_flush_fxnP
#define ISystemSupport_flush_FxnT xdc_runtime_ISystemSupport_flush_FxnT
#define ISystemSupport_putch xdc_runtime_ISystemSupport_putch
#define ISystemSupport_putch_fxnP xdc_runtime_ISystemSupport_putch_fxnP
#define ISystemSupport_putch_FxnT xdc_runtime_ISystemSupport_putch_FxnT
#define ISystemSupport_ready xdc_runtime_ISystemSupport_ready
#define ISystemSupport_ready_fxnP xdc_runtime_ISystemSupport_ready_fxnP
#define ISystemSupport_ready_FxnT xdc_runtime_ISystemSupport_ready_FxnT
#define ISystemSupport_Module_name xdc_runtime_ISystemSupport_Module_name

#endif /* xdc_runtime_ISystemSupport__localnames__done */
#endif
/*
 *  @(#) xdc.runtime; 2, 1, 0,0; 4-24-2015 12:34:12; /db/ztree/library/trees/xdc/xdc-A71/src/packages/
 */

