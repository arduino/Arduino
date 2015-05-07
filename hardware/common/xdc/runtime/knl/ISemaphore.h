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
 *     PER-INSTANCE TYPES
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

#ifndef xdc_runtime_knl_ISemaphore__include
#define xdc_runtime_knl_ISemaphore__include

#ifndef __nested__
#define __nested__
#define xdc_runtime_knl_ISemaphore__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define xdc_runtime_knl_ISemaphore___VERS 160


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/IInstance.h>
#include <xdc/runtime/knl/package/package.defs.h>

#include <xdc/runtime/Error.h>
#include <xdc/runtime/IModule.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */

/* PendStatus */
enum xdc_runtime_knl_ISemaphore_PendStatus {
    xdc_runtime_knl_ISemaphore_PendStatus_ERROR = -1,
    xdc_runtime_knl_ISemaphore_PendStatus_TIMEOUT = 0,
    xdc_runtime_knl_ISemaphore_PendStatus_SUCCESS = 1
};
typedef enum xdc_runtime_knl_ISemaphore_PendStatus xdc_runtime_knl_ISemaphore_PendStatus;

/* FOREVER */
#define xdc_runtime_knl_ISemaphore_FOREVER (~(0))

/* Mode */
enum xdc_runtime_knl_ISemaphore_Mode {
    xdc_runtime_knl_ISemaphore_Mode_COUNTING,
    xdc_runtime_knl_ISemaphore_Mode_BINARY
};
typedef enum xdc_runtime_knl_ISemaphore_Mode xdc_runtime_knl_ISemaphore_Mode;


/*
 * ======== PER-INSTANCE TYPES ========
 */

/* Params */
struct xdc_runtime_knl_ISemaphore_Params {
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
struct xdc_runtime_knl_ISemaphore_Fxns__ {
    xdc_runtime_Types_Base* __base;
    const xdc_runtime_Types_SysFxns2 *__sysp;
    xdc_Int (*pend)(void*, xdc_UInt, xdc_runtime_Error_Block*);
    xdc_Bool (*post)(void*, xdc_runtime_Error_Block*);
    xdc_runtime_Types_SysFxns2 __sfxns;
};

/* Interface__BASE__C */
__extern const xdc_runtime_Types_Base xdc_runtime_knl_ISemaphore_Interface__BASE__C;


/*
 * ======== FUNCTION STUBS ========
 */

/* create */
xdc__CODESECT(xdc_runtime_knl_ISemaphore_create, "xdc_runtime_knl_ISemaphore_create")
__extern xdc_runtime_knl_ISemaphore_Handle xdc_runtime_knl_ISemaphore_create(xdc_runtime_knl_ISemaphore_Module, const xdc_runtime_knl_ISemaphore_Params *, xdc_runtime_Error_Block *__eb);

/* delete */
xdc__CODESECT(xdc_runtime_knl_ISemaphore_delete, "xdc_runtime_knl_ISemaphore_delete")
__extern xdc_Void xdc_runtime_knl_ISemaphore_delete(xdc_runtime_knl_ISemaphore_Handle *);

/* Handle_to_Module */
static inline xdc_runtime_knl_ISemaphore_Module xdc_runtime_knl_ISemaphore_Handle_to_Module( xdc_runtime_knl_ISemaphore_Handle inst )
{
    return inst->__fxns;
}

/* Handle_label */
static inline xdc_runtime_Types_Label *xdc_runtime_knl_ISemaphore_Handle_label( xdc_runtime_knl_ISemaphore_Handle inst, xdc_runtime_Types_Label *lab )
{
    return inst->__fxns->__sysp->__label(inst, lab);
}

/* Module_id */
static inline xdc_runtime_Types_ModuleId xdc_runtime_knl_ISemaphore_Module_id( xdc_runtime_knl_ISemaphore_Module mod )
{
    return mod->__sysp->__mid;
}

/* pend */
static inline xdc_Int xdc_runtime_knl_ISemaphore_pend( xdc_runtime_knl_ISemaphore_Handle __inst, xdc_UInt timeout, xdc_runtime_Error_Block *eb )
{
    return __inst->__fxns->pend((void*)__inst, timeout, eb);
}

/* post */
static inline xdc_Bool xdc_runtime_knl_ISemaphore_post( xdc_runtime_knl_ISemaphore_Handle __inst, xdc_runtime_Error_Block *eb )
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
typedef xdc_Int (*xdc_runtime_knl_ISemaphore_pend_FxnT)(xdc_Void *, xdc_UInt, xdc_runtime_Error_Block*);
static inline xdc_runtime_knl_ISemaphore_pend_FxnT xdc_runtime_knl_ISemaphore_pend_fxnP( xdc_runtime_knl_ISemaphore_Handle __inst )
{
    return (xdc_runtime_knl_ISemaphore_pend_FxnT)__inst->__fxns->pend;
}

/* post_{FxnT,fxnP} */
typedef xdc_Bool (*xdc_runtime_knl_ISemaphore_post_FxnT)(xdc_Void *, xdc_runtime_Error_Block*);
static inline xdc_runtime_knl_ISemaphore_post_FxnT xdc_runtime_knl_ISemaphore_post_fxnP( xdc_runtime_knl_ISemaphore_Handle __inst )
{
    return (xdc_runtime_knl_ISemaphore_post_FxnT)__inst->__fxns->post;
}


/*
 * ======== EPILOGUE ========
 */

#ifdef xdc_runtime_knl_ISemaphore__top__
#undef __nested__
#endif

#endif /* xdc_runtime_knl_ISemaphore__include */


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(xdc_runtime_knl_ISemaphore__nolocalnames)

#ifndef xdc_runtime_knl_ISemaphore__localnames__done
#define xdc_runtime_knl_ISemaphore__localnames__done

/* module prefix */
#define ISemaphore_Instance xdc_runtime_knl_ISemaphore_Instance
#define ISemaphore_Handle xdc_runtime_knl_ISemaphore_Handle
#define ISemaphore_Module xdc_runtime_knl_ISemaphore_Module
#define ISemaphore_PendStatus xdc_runtime_knl_ISemaphore_PendStatus
#define ISemaphore_FOREVER xdc_runtime_knl_ISemaphore_FOREVER
#define ISemaphore_Mode xdc_runtime_knl_ISemaphore_Mode
#define ISemaphore_PendStatus_ERROR xdc_runtime_knl_ISemaphore_PendStatus_ERROR
#define ISemaphore_PendStatus_TIMEOUT xdc_runtime_knl_ISemaphore_PendStatus_TIMEOUT
#define ISemaphore_PendStatus_SUCCESS xdc_runtime_knl_ISemaphore_PendStatus_SUCCESS
#define ISemaphore_Mode_COUNTING xdc_runtime_knl_ISemaphore_Mode_COUNTING
#define ISemaphore_Mode_BINARY xdc_runtime_knl_ISemaphore_Mode_BINARY
#define ISemaphore_Params xdc_runtime_knl_ISemaphore_Params
#define ISemaphore_pend xdc_runtime_knl_ISemaphore_pend
#define ISemaphore_pend_fxnP xdc_runtime_knl_ISemaphore_pend_fxnP
#define ISemaphore_pend_FxnT xdc_runtime_knl_ISemaphore_pend_FxnT
#define ISemaphore_post xdc_runtime_knl_ISemaphore_post
#define ISemaphore_post_fxnP xdc_runtime_knl_ISemaphore_post_fxnP
#define ISemaphore_post_FxnT xdc_runtime_knl_ISemaphore_post_FxnT
#define ISemaphore_Module_name xdc_runtime_knl_ISemaphore_Module_name
#define ISemaphore_delete xdc_runtime_knl_ISemaphore_delete
#define ISemaphore_Handle_label xdc_runtime_knl_ISemaphore_Handle_label
#define ISemaphore_Handle_to_Module xdc_runtime_knl_ISemaphore_Handle_to_Module

#endif /* xdc_runtime_knl_ISemaphore__localnames__done */
#endif
/*
 *  @(#) xdc.runtime.knl; 1, 0, 0,0; 4-24-2015 12:34:16; /db/ztree/library/trees/xdc/xdc-A71/src/packages/
 */

