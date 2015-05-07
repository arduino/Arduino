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
 *     CREATE ARGS
 *     PER-INSTANCE TYPES
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

#ifndef xdc_runtime_knl_ISemThreadSupport__include
#define xdc_runtime_knl_ISemThreadSupport__include

#ifndef __nested__
#define __nested__
#define xdc_runtime_knl_ISemThreadSupport__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define xdc_runtime_knl_ISemThreadSupport___VERS 160


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/IInstance.h>
#include <xdc/runtime/knl/package/package.defs.h>

#include <xdc/runtime/knl/ISemaphore.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */

/* PendStatus */
typedef xdc_runtime_knl_ISemaphore_PendStatus xdc_runtime_knl_ISemThreadSupport_PendStatus;

/* FOREVER */
#define xdc_runtime_knl_ISemThreadSupport_FOREVER (~(0))

/* Mode */
typedef xdc_runtime_knl_ISemaphore_Mode xdc_runtime_knl_ISemThreadSupport_Mode;

/* PendStatus_ERROR */
#define xdc_runtime_knl_ISemThreadSupport_PendStatus_ERROR xdc_runtime_knl_ISemaphore_PendStatus_ERROR

/* PendStatus_TIMEOUT */
#define xdc_runtime_knl_ISemThreadSupport_PendStatus_TIMEOUT xdc_runtime_knl_ISemaphore_PendStatus_TIMEOUT

/* PendStatus_SUCCESS */
#define xdc_runtime_knl_ISemThreadSupport_PendStatus_SUCCESS xdc_runtime_knl_ISemaphore_PendStatus_SUCCESS

/* Mode_COUNTING */
#define xdc_runtime_knl_ISemThreadSupport_Mode_COUNTING xdc_runtime_knl_ISemaphore_Mode_COUNTING

/* Mode_BINARY */
#define xdc_runtime_knl_ISemThreadSupport_Mode_BINARY xdc_runtime_knl_ISemaphore_Mode_BINARY


/*
 * ======== CREATE ARGS ========
 */

/* Args__create */
typedef struct xdc_runtime_knl_ISemThreadSupport_Args__create {
    xdc_Int count;
} xdc_runtime_knl_ISemThreadSupport_Args__create;


/*
 * ======== PER-INSTANCE TYPES ========
 */

/* Params */
struct xdc_runtime_knl_ISemThreadSupport_Params {
    size_t __size;
    const void *__self;
    void *__fxns;
    xdc_runtime_IInstance_Params *instance;
    xdc_runtime_knl_ISemaphore_Mode mode;
};


/*
 * ======== VIRTUAL FUNCTIONS ========
 */

/* Fxns__ */
struct xdc_runtime_knl_ISemThreadSupport_Fxns__ {
    xdc_runtime_Types_Base* __base;
    const xdc_runtime_Types_SysFxns2 *__sysp;
    xdc_Int (*pend)(void*, xdc_UInt, xdc_runtime_Error_Block*);
    xdc_Bool (*post)(void*, xdc_runtime_Error_Block*);
    xdc_runtime_Types_SysFxns2 __sfxns;
};

/* Interface__BASE__C */
__extern const xdc_runtime_Types_Base xdc_runtime_knl_ISemThreadSupport_Interface__BASE__C;


/*
 * ======== FUNCTION STUBS ========
 */

/* create */
xdc__CODESECT(xdc_runtime_knl_ISemThreadSupport_create, "xdc_runtime_knl_ISemThreadSupport_create")
__extern xdc_runtime_knl_ISemThreadSupport_Handle xdc_runtime_knl_ISemThreadSupport_create(xdc_runtime_knl_ISemThreadSupport_Module, xdc_Int count, const xdc_runtime_knl_ISemThreadSupport_Params *, xdc_runtime_Error_Block *__eb);

/* delete */
xdc__CODESECT(xdc_runtime_knl_ISemThreadSupport_delete, "xdc_runtime_knl_ISemThreadSupport_delete")
__extern xdc_Void xdc_runtime_knl_ISemThreadSupport_delete(xdc_runtime_knl_ISemThreadSupport_Handle *);

/* Handle_to_Module */
static inline xdc_runtime_knl_ISemThreadSupport_Module xdc_runtime_knl_ISemThreadSupport_Handle_to_Module( xdc_runtime_knl_ISemThreadSupport_Handle inst )
{
    return inst->__fxns;
}

/* Handle_label */
static inline xdc_runtime_Types_Label *xdc_runtime_knl_ISemThreadSupport_Handle_label( xdc_runtime_knl_ISemThreadSupport_Handle inst, xdc_runtime_Types_Label *lab )
{
    return inst->__fxns->__sysp->__label(inst, lab);
}

/* Module_id */
static inline xdc_runtime_Types_ModuleId xdc_runtime_knl_ISemThreadSupport_Module_id( xdc_runtime_knl_ISemThreadSupport_Module mod )
{
    return mod->__sysp->__mid;
}

/* pend */
static inline xdc_Int xdc_runtime_knl_ISemThreadSupport_pend( xdc_runtime_knl_ISemThreadSupport_Handle __inst, xdc_UInt timeout, xdc_runtime_Error_Block *eb )
{
    return __inst->__fxns->pend((void*)__inst, timeout, eb);
}

/* post */
static inline xdc_Bool xdc_runtime_knl_ISemThreadSupport_post( xdc_runtime_knl_ISemThreadSupport_Handle __inst, xdc_runtime_Error_Block *eb )
{
    return __inst->__fxns->post((void*)__inst, eb);
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

/* pend_{FxnT,fxnP} */
typedef xdc_Int (*xdc_runtime_knl_ISemThreadSupport_pend_FxnT)(xdc_Void *, xdc_UInt, xdc_runtime_Error_Block*);
static inline xdc_runtime_knl_ISemThreadSupport_pend_FxnT xdc_runtime_knl_ISemThreadSupport_pend_fxnP( xdc_runtime_knl_ISemThreadSupport_Handle __inst )
{
    return (xdc_runtime_knl_ISemThreadSupport_pend_FxnT)__inst->__fxns->pend;
}

/* post_{FxnT,fxnP} */
typedef xdc_Bool (*xdc_runtime_knl_ISemThreadSupport_post_FxnT)(xdc_Void *, xdc_runtime_Error_Block*);
static inline xdc_runtime_knl_ISemThreadSupport_post_FxnT xdc_runtime_knl_ISemThreadSupport_post_fxnP( xdc_runtime_knl_ISemThreadSupport_Handle __inst )
{
    return (xdc_runtime_knl_ISemThreadSupport_post_FxnT)__inst->__fxns->post;
}


/*
 * ======== CONVERTORS ========
 */

/* Module_upCast */
static inline xdc_runtime_knl_ISemaphore_Module xdc_runtime_knl_ISemThreadSupport_Module_upCast( xdc_runtime_knl_ISemThreadSupport_Module m )
{
    return(xdc_runtime_knl_ISemaphore_Module)m;
}

/* Module_to_xdc_runtime_knl_ISemaphore */
#define xdc_runtime_knl_ISemThreadSupport_Module_to_xdc_runtime_knl_ISemaphore xdc_runtime_knl_ISemThreadSupport_Module_upCast

/* Module_downCast */
static inline xdc_runtime_knl_ISemThreadSupport_Module xdc_runtime_knl_ISemThreadSupport_Module_downCast( xdc_runtime_knl_ISemaphore_Module m )
{
    xdc_runtime_Types_Base* b; for (b = m->__base; b; b = b->base) {
        if (b == &xdc_runtime_knl_ISemThreadSupport_Interface__BASE__C) return (xdc_runtime_knl_ISemThreadSupport_Module)m;
    } return 0;
}

/* Module_from_xdc_runtime_knl_ISemaphore */
#define xdc_runtime_knl_ISemThreadSupport_Module_from_xdc_runtime_knl_ISemaphore xdc_runtime_knl_ISemThreadSupport_Module_downCast

/* Handle_upCast */
static inline xdc_runtime_knl_ISemaphore_Handle xdc_runtime_knl_ISemThreadSupport_Handle_upCast( xdc_runtime_knl_ISemThreadSupport_Handle i )
{
    return (xdc_runtime_knl_ISemaphore_Handle)i;
}

/* Handle_to_xdc_runtime_knl_ISemaphore */
#define xdc_runtime_knl_ISemThreadSupport_Handle_to_xdc_runtime_knl_ISemaphore xdc_runtime_knl_ISemThreadSupport_Handle_upCast

/* Handle_downCast */
static inline xdc_runtime_knl_ISemThreadSupport_Handle xdc_runtime_knl_ISemThreadSupport_Handle_downCast( xdc_runtime_knl_ISemaphore_Handle i )
{
    xdc_runtime_knl_ISemaphore_Handle i2 = (xdc_runtime_knl_ISemaphore_Handle)i;
    xdc_runtime_Types_Base* b; for (b = i2->__fxns->__base; b; b = b->base) {
        if (b == &xdc_runtime_knl_ISemThreadSupport_Interface__BASE__C) return (xdc_runtime_knl_ISemThreadSupport_Handle)i;
    } return 0;
}

/* Handle_from_xdc_runtime_knl_ISemaphore */
#define xdc_runtime_knl_ISemThreadSupport_Handle_from_xdc_runtime_knl_ISemaphore xdc_runtime_knl_ISemThreadSupport_Handle_downCast


/*
 * ======== EPILOGUE ========
 */

#ifdef xdc_runtime_knl_ISemThreadSupport__top__
#undef __nested__
#endif

#endif /* xdc_runtime_knl_ISemThreadSupport__include */


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(xdc_runtime_knl_ISemThreadSupport__nolocalnames)

#ifndef xdc_runtime_knl_ISemThreadSupport__localnames__done
#define xdc_runtime_knl_ISemThreadSupport__localnames__done

/* module prefix */
#define ISemThreadSupport_Instance xdc_runtime_knl_ISemThreadSupport_Instance
#define ISemThreadSupport_Handle xdc_runtime_knl_ISemThreadSupport_Handle
#define ISemThreadSupport_Module xdc_runtime_knl_ISemThreadSupport_Module
#define ISemThreadSupport_PendStatus xdc_runtime_knl_ISemThreadSupport_PendStatus
#define ISemThreadSupport_FOREVER xdc_runtime_knl_ISemThreadSupport_FOREVER
#define ISemThreadSupport_Mode xdc_runtime_knl_ISemThreadSupport_Mode
#define ISemThreadSupport_PendStatus_ERROR xdc_runtime_knl_ISemThreadSupport_PendStatus_ERROR
#define ISemThreadSupport_PendStatus_TIMEOUT xdc_runtime_knl_ISemThreadSupport_PendStatus_TIMEOUT
#define ISemThreadSupport_PendStatus_SUCCESS xdc_runtime_knl_ISemThreadSupport_PendStatus_SUCCESS
#define ISemThreadSupport_Mode_COUNTING xdc_runtime_knl_ISemThreadSupport_Mode_COUNTING
#define ISemThreadSupport_Mode_BINARY xdc_runtime_knl_ISemThreadSupport_Mode_BINARY
#define ISemThreadSupport_Params xdc_runtime_knl_ISemThreadSupport_Params
#define ISemThreadSupport_pend xdc_runtime_knl_ISemThreadSupport_pend
#define ISemThreadSupport_pend_fxnP xdc_runtime_knl_ISemThreadSupport_pend_fxnP
#define ISemThreadSupport_pend_FxnT xdc_runtime_knl_ISemThreadSupport_pend_FxnT
#define ISemThreadSupport_post xdc_runtime_knl_ISemThreadSupport_post
#define ISemThreadSupport_post_fxnP xdc_runtime_knl_ISemThreadSupport_post_fxnP
#define ISemThreadSupport_post_FxnT xdc_runtime_knl_ISemThreadSupport_post_FxnT
#define ISemThreadSupport_Module_name xdc_runtime_knl_ISemThreadSupport_Module_name
#define ISemThreadSupport_create xdc_runtime_knl_ISemThreadSupport_create
#define ISemThreadSupport_delete xdc_runtime_knl_ISemThreadSupport_delete
#define ISemThreadSupport_Handle_label xdc_runtime_knl_ISemThreadSupport_Handle_label
#define ISemThreadSupport_Handle_to_Module xdc_runtime_knl_ISemThreadSupport_Handle_to_Module
#define ISemThreadSupport_Module_upCast xdc_runtime_knl_ISemThreadSupport_Module_upCast
#define ISemThreadSupport_Module_to_xdc_runtime_knl_ISemaphore xdc_runtime_knl_ISemThreadSupport_Module_to_xdc_runtime_knl_ISemaphore
#define ISemThreadSupport_Module_downCast xdc_runtime_knl_ISemThreadSupport_Module_downCast
#define ISemThreadSupport_Module_from_xdc_runtime_knl_ISemaphore xdc_runtime_knl_ISemThreadSupport_Module_from_xdc_runtime_knl_ISemaphore
#define ISemThreadSupport_Handle_upCast xdc_runtime_knl_ISemThreadSupport_Handle_upCast
#define ISemThreadSupport_Handle_to_xdc_runtime_knl_ISemaphore xdc_runtime_knl_ISemThreadSupport_Handle_to_xdc_runtime_knl_ISemaphore
#define ISemThreadSupport_Handle_downCast xdc_runtime_knl_ISemThreadSupport_Handle_downCast
#define ISemThreadSupport_Handle_from_xdc_runtime_knl_ISemaphore xdc_runtime_knl_ISemThreadSupport_Handle_from_xdc_runtime_knl_ISemaphore

#endif /* xdc_runtime_knl_ISemThreadSupport__localnames__done */
#endif
/*
 *  @(#) xdc.runtime.knl; 1, 0, 0,0; 4-24-2015 12:34:16; /db/ztree/library/trees/xdc/xdc-A71/src/packages/
 */

