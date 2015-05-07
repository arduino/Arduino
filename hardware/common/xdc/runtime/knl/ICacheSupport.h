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

#ifndef xdc_runtime_knl_ICacheSupport__include
#define xdc_runtime_knl_ICacheSupport__include

#ifndef __nested__
#define __nested__
#define xdc_runtime_knl_ICacheSupport__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define xdc_runtime_knl_ICacheSupport___VERS 160


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/knl/package/package.defs.h>

#include <xdc/runtime/Error.h>
#include <xdc/runtime/IModule.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */


/*
 * ======== VIRTUAL FUNCTIONS ========
 */

/* Fxns__ */
struct xdc_runtime_knl_ICacheSupport_Fxns__ {
    xdc_runtime_Types_Base* __base;
    const xdc_runtime_Types_SysFxns2 *__sysp;
    xdc_Bool (*inv)(xdc_Ptr, xdc_SizeT, xdc_Bool, xdc_runtime_Error_Block*);
    xdc_Bool (*wb)(xdc_Ptr, xdc_SizeT, xdc_Bool, xdc_runtime_Error_Block*);
    xdc_Bool (*wbInv)(xdc_Ptr, xdc_SizeT, xdc_Bool, xdc_runtime_Error_Block*);
    xdc_Bool (*wait)(xdc_runtime_Error_Block*);
    xdc_runtime_Types_SysFxns2 __sfxns;
};

/* Interface__BASE__C */
__extern const xdc_runtime_Types_Base xdc_runtime_knl_ICacheSupport_Interface__BASE__C;


/*
 * ======== FUNCTION STUBS ========
 */

/* Module_id */
static inline xdc_runtime_Types_ModuleId xdc_runtime_knl_ICacheSupport_Module_id( xdc_runtime_knl_ICacheSupport_Module mod )
{
    return mod->__sysp->__mid;
}

/* inv */
static inline xdc_Bool xdc_runtime_knl_ICacheSupport_inv( xdc_runtime_knl_ICacheSupport_Module __inst, xdc_Ptr blockPtr, xdc_SizeT byteCnt, xdc_Bool wait, xdc_runtime_Error_Block *eb )
{
    return __inst->inv(blockPtr, byteCnt, wait, eb);
}

/* wb */
static inline xdc_Bool xdc_runtime_knl_ICacheSupport_wb( xdc_runtime_knl_ICacheSupport_Module __inst, xdc_Ptr blockPtr, xdc_SizeT byteCnt, xdc_Bool wait, xdc_runtime_Error_Block *eb )
{
    return __inst->wb(blockPtr, byteCnt, wait, eb);
}

/* wbInv */
static inline xdc_Bool xdc_runtime_knl_ICacheSupport_wbInv( xdc_runtime_knl_ICacheSupport_Module __inst, xdc_Ptr blockPtr, xdc_SizeT byteCnt, xdc_Bool wait, xdc_runtime_Error_Block *eb )
{
    return __inst->wbInv(blockPtr, byteCnt, wait, eb);
}

/* wait */
static inline xdc_Bool xdc_runtime_knl_ICacheSupport_wait( xdc_runtime_knl_ICacheSupport_Module __inst, xdc_runtime_Error_Block *eb )
{
    return __inst->wait(eb);
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

/* inv_{FxnT,fxnP} */
typedef xdc_Bool (*xdc_runtime_knl_ICacheSupport_inv_FxnT)(xdc_Ptr, xdc_SizeT, xdc_Bool, xdc_runtime_Error_Block*);
static inline xdc_runtime_knl_ICacheSupport_inv_FxnT xdc_runtime_knl_ICacheSupport_inv_fxnP( xdc_runtime_knl_ICacheSupport_Module __inst )
{
    return (xdc_runtime_knl_ICacheSupport_inv_FxnT)__inst->inv;
}

/* wb_{FxnT,fxnP} */
typedef xdc_Bool (*xdc_runtime_knl_ICacheSupport_wb_FxnT)(xdc_Ptr, xdc_SizeT, xdc_Bool, xdc_runtime_Error_Block*);
static inline xdc_runtime_knl_ICacheSupport_wb_FxnT xdc_runtime_knl_ICacheSupport_wb_fxnP( xdc_runtime_knl_ICacheSupport_Module __inst )
{
    return (xdc_runtime_knl_ICacheSupport_wb_FxnT)__inst->wb;
}

/* wbInv_{FxnT,fxnP} */
typedef xdc_Bool (*xdc_runtime_knl_ICacheSupport_wbInv_FxnT)(xdc_Ptr, xdc_SizeT, xdc_Bool, xdc_runtime_Error_Block*);
static inline xdc_runtime_knl_ICacheSupport_wbInv_FxnT xdc_runtime_knl_ICacheSupport_wbInv_fxnP( xdc_runtime_knl_ICacheSupport_Module __inst )
{
    return (xdc_runtime_knl_ICacheSupport_wbInv_FxnT)__inst->wbInv;
}

/* wait_{FxnT,fxnP} */
typedef xdc_Bool (*xdc_runtime_knl_ICacheSupport_wait_FxnT)(xdc_runtime_Error_Block*);
static inline xdc_runtime_knl_ICacheSupport_wait_FxnT xdc_runtime_knl_ICacheSupport_wait_fxnP( xdc_runtime_knl_ICacheSupport_Module __inst )
{
    return (xdc_runtime_knl_ICacheSupport_wait_FxnT)__inst->wait;
}


/*
 * ======== EPILOGUE ========
 */

#ifdef xdc_runtime_knl_ICacheSupport__top__
#undef __nested__
#endif

#endif /* xdc_runtime_knl_ICacheSupport__include */


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(xdc_runtime_knl_ICacheSupport__nolocalnames)

#ifndef xdc_runtime_knl_ICacheSupport__localnames__done
#define xdc_runtime_knl_ICacheSupport__localnames__done

/* module prefix */
#define ICacheSupport_Module xdc_runtime_knl_ICacheSupport_Module
#define ICacheSupport_inv xdc_runtime_knl_ICacheSupport_inv
#define ICacheSupport_inv_fxnP xdc_runtime_knl_ICacheSupport_inv_fxnP
#define ICacheSupport_inv_FxnT xdc_runtime_knl_ICacheSupport_inv_FxnT
#define ICacheSupport_wb xdc_runtime_knl_ICacheSupport_wb
#define ICacheSupport_wb_fxnP xdc_runtime_knl_ICacheSupport_wb_fxnP
#define ICacheSupport_wb_FxnT xdc_runtime_knl_ICacheSupport_wb_FxnT
#define ICacheSupport_wbInv xdc_runtime_knl_ICacheSupport_wbInv
#define ICacheSupport_wbInv_fxnP xdc_runtime_knl_ICacheSupport_wbInv_fxnP
#define ICacheSupport_wbInv_FxnT xdc_runtime_knl_ICacheSupport_wbInv_FxnT
#define ICacheSupport_wait xdc_runtime_knl_ICacheSupport_wait
#define ICacheSupport_wait_fxnP xdc_runtime_knl_ICacheSupport_wait_fxnP
#define ICacheSupport_wait_FxnT xdc_runtime_knl_ICacheSupport_wait_FxnT
#define ICacheSupport_Module_name xdc_runtime_knl_ICacheSupport_Module_name

#endif /* xdc_runtime_knl_ICacheSupport__localnames__done */
#endif
/*
 *  @(#) xdc.runtime.knl; 1, 0, 0,0; 4-24-2015 12:34:16; /db/ztree/library/trees/xdc/xdc-A71/src/packages/
 */

