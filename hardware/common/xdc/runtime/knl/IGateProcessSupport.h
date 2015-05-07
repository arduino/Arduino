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
 *     CONVERTORS
 *     
 *     EPILOGUE
 *     PREFIX ALIASES
 */


/*
 * ======== PROLOGUE ========
 */

#ifndef xdc_runtime_knl_IGateProcessSupport__include
#define xdc_runtime_knl_IGateProcessSupport__include

#ifndef __nested__
#define __nested__
#define xdc_runtime_knl_IGateProcessSupport__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define xdc_runtime_knl_IGateProcessSupport___VERS 160


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/IInstance.h>
#include <xdc/runtime/knl/package/package.defs.h>

#include <xdc/runtime/Error.h>
#include <xdc/runtime/knl/IGateThreadSupport.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */

/* Q_BLOCKING */
#define xdc_runtime_knl_IGateProcessSupport_Q_BLOCKING (1)

/* Q_PREEMPTING */
#define xdc_runtime_knl_IGateProcessSupport_Q_PREEMPTING (2)

/* GETREFCOUNT_FAILED */
#define xdc_runtime_knl_IGateProcessSupport_GETREFCOUNT_FAILED (-1)


/*
 * ======== PER-INSTANCE TYPES ========
 */

/* Params */
struct xdc_runtime_knl_IGateProcessSupport_Params {
    size_t __size;
    const void *__self;
    void *__fxns;
    xdc_runtime_IInstance_Params *instance;
    xdc_Int key;
};


/*
 * ======== VIRTUAL FUNCTIONS ========
 */

/* Fxns__ */
struct xdc_runtime_knl_IGateProcessSupport_Fxns__ {
    xdc_runtime_Types_Base* __base;
    const xdc_runtime_Types_SysFxns2 *__sysp;
    xdc_Bool (*query)(xdc_Int);
    xdc_IArg (*enter)(void*);
    xdc_Void (*leave)(void*, xdc_IArg);
    xdc_Int (*getReferenceCount)(void*, xdc_runtime_Error_Block*);
    xdc_runtime_Types_SysFxns2 __sfxns;
};

/* Interface__BASE__C */
__extern const xdc_runtime_Types_Base xdc_runtime_knl_IGateProcessSupport_Interface__BASE__C;


/*
 * ======== FUNCTION STUBS ========
 */

/* create */
xdc__CODESECT(xdc_runtime_knl_IGateProcessSupport_create, "xdc_runtime_knl_IGateProcessSupport_create")
__extern xdc_runtime_knl_IGateProcessSupport_Handle xdc_runtime_knl_IGateProcessSupport_create(xdc_runtime_knl_IGateProcessSupport_Module, const xdc_runtime_knl_IGateProcessSupport_Params *, xdc_runtime_Error_Block *__eb);

/* delete */
xdc__CODESECT(xdc_runtime_knl_IGateProcessSupport_delete, "xdc_runtime_knl_IGateProcessSupport_delete")
__extern xdc_Void xdc_runtime_knl_IGateProcessSupport_delete(xdc_runtime_knl_IGateProcessSupport_Handle *);

/* Handle_to_Module */
static inline xdc_runtime_knl_IGateProcessSupport_Module xdc_runtime_knl_IGateProcessSupport_Handle_to_Module( xdc_runtime_knl_IGateProcessSupport_Handle inst )
{
    return inst->__fxns;
}

/* Handle_label */
static inline xdc_runtime_Types_Label *xdc_runtime_knl_IGateProcessSupport_Handle_label( xdc_runtime_knl_IGateProcessSupport_Handle inst, xdc_runtime_Types_Label *lab )
{
    return inst->__fxns->__sysp->__label(inst, lab);
}

/* Module_id */
static inline xdc_runtime_Types_ModuleId xdc_runtime_knl_IGateProcessSupport_Module_id( xdc_runtime_knl_IGateProcessSupport_Module mod )
{
    return mod->__sysp->__mid;
}

/* query */
static inline xdc_Bool xdc_runtime_knl_IGateProcessSupport_query( xdc_runtime_knl_IGateProcessSupport_Module __inst, xdc_Int qual )
{
    return __inst->query(qual);
}

/* enter */
static inline xdc_IArg xdc_runtime_knl_IGateProcessSupport_enter( xdc_runtime_knl_IGateProcessSupport_Handle __inst )
{
    return __inst->__fxns->enter((void*)__inst);
}

/* leave */
static inline xdc_Void xdc_runtime_knl_IGateProcessSupport_leave( xdc_runtime_knl_IGateProcessSupport_Handle __inst, xdc_IArg key )
{
    __inst->__fxns->leave((void*)__inst, key);
}

/* getReferenceCount */
static inline xdc_Int xdc_runtime_knl_IGateProcessSupport_getReferenceCount( xdc_runtime_knl_IGateProcessSupport_Handle __inst, xdc_runtime_Error_Block *err )
{
    return __inst->__fxns->getReferenceCount((void*)__inst, err);
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

/* query_{FxnT,fxnP} */
typedef xdc_Bool (*xdc_runtime_knl_IGateProcessSupport_query_FxnT)(xdc_Int);
static inline xdc_runtime_knl_IGateProcessSupport_query_FxnT xdc_runtime_knl_IGateProcessSupport_query_fxnP( xdc_runtime_knl_IGateProcessSupport_Module __inst )
{
    return (xdc_runtime_knl_IGateProcessSupport_query_FxnT)__inst->query;
}

/* enter_{FxnT,fxnP} */
typedef xdc_IArg (*xdc_runtime_knl_IGateProcessSupport_enter_FxnT)(xdc_Void *);
static inline xdc_runtime_knl_IGateProcessSupport_enter_FxnT xdc_runtime_knl_IGateProcessSupport_enter_fxnP( xdc_runtime_knl_IGateProcessSupport_Handle __inst )
{
    return (xdc_runtime_knl_IGateProcessSupport_enter_FxnT)__inst->__fxns->enter;
}

/* leave_{FxnT,fxnP} */
typedef xdc_Void (*xdc_runtime_knl_IGateProcessSupport_leave_FxnT)(xdc_Void *, xdc_IArg);
static inline xdc_runtime_knl_IGateProcessSupport_leave_FxnT xdc_runtime_knl_IGateProcessSupport_leave_fxnP( xdc_runtime_knl_IGateProcessSupport_Handle __inst )
{
    return (xdc_runtime_knl_IGateProcessSupport_leave_FxnT)__inst->__fxns->leave;
}

/* getReferenceCount_{FxnT,fxnP} */
typedef xdc_Int (*xdc_runtime_knl_IGateProcessSupport_getReferenceCount_FxnT)(xdc_Void *, xdc_runtime_Error_Block*);
static inline xdc_runtime_knl_IGateProcessSupport_getReferenceCount_FxnT xdc_runtime_knl_IGateProcessSupport_getReferenceCount_fxnP( xdc_runtime_knl_IGateProcessSupport_Handle __inst )
{
    return (xdc_runtime_knl_IGateProcessSupport_getReferenceCount_FxnT)__inst->__fxns->getReferenceCount;
}


/*
 * ======== CONVERTORS ========
 */

/* Module_upCast */
static inline xdc_runtime_knl_IGateThreadSupport_Module xdc_runtime_knl_IGateProcessSupport_Module_upCast( xdc_runtime_knl_IGateProcessSupport_Module m )
{
    return(xdc_runtime_knl_IGateThreadSupport_Module)m;
}

/* Module_to_xdc_runtime_knl_IGateThreadSupport */
#define xdc_runtime_knl_IGateProcessSupport_Module_to_xdc_runtime_knl_IGateThreadSupport xdc_runtime_knl_IGateProcessSupport_Module_upCast

/* Module_downCast */
static inline xdc_runtime_knl_IGateProcessSupport_Module xdc_runtime_knl_IGateProcessSupport_Module_downCast( xdc_runtime_knl_IGateThreadSupport_Module m )
{
    xdc_runtime_Types_Base* b; for (b = m->__base; b; b = b->base) {
        if (b == &xdc_runtime_knl_IGateProcessSupport_Interface__BASE__C) return (xdc_runtime_knl_IGateProcessSupport_Module)m;
    } return 0;
}

/* Module_from_xdc_runtime_knl_IGateThreadSupport */
#define xdc_runtime_knl_IGateProcessSupport_Module_from_xdc_runtime_knl_IGateThreadSupport xdc_runtime_knl_IGateProcessSupport_Module_downCast

/* Handle_upCast */
static inline xdc_runtime_knl_IGateThreadSupport_Handle xdc_runtime_knl_IGateProcessSupport_Handle_upCast( xdc_runtime_knl_IGateProcessSupport_Handle i )
{
    return (xdc_runtime_knl_IGateThreadSupport_Handle)i;
}

/* Handle_to_xdc_runtime_knl_IGateThreadSupport */
#define xdc_runtime_knl_IGateProcessSupport_Handle_to_xdc_runtime_knl_IGateThreadSupport xdc_runtime_knl_IGateProcessSupport_Handle_upCast

/* Handle_downCast */
static inline xdc_runtime_knl_IGateProcessSupport_Handle xdc_runtime_knl_IGateProcessSupport_Handle_downCast( xdc_runtime_knl_IGateThreadSupport_Handle i )
{
    xdc_runtime_knl_IGateThreadSupport_Handle i2 = (xdc_runtime_knl_IGateThreadSupport_Handle)i;
    xdc_runtime_Types_Base* b; for (b = i2->__fxns->__base; b; b = b->base) {
        if (b == &xdc_runtime_knl_IGateProcessSupport_Interface__BASE__C) return (xdc_runtime_knl_IGateProcessSupport_Handle)i;
    } return 0;
}

/* Handle_from_xdc_runtime_knl_IGateThreadSupport */
#define xdc_runtime_knl_IGateProcessSupport_Handle_from_xdc_runtime_knl_IGateThreadSupport xdc_runtime_knl_IGateProcessSupport_Handle_downCast

/* Module_upCast2 */
static inline xdc_runtime_IGateProvider_Module xdc_runtime_knl_IGateProcessSupport_Module_upCast2( xdc_runtime_knl_IGateProcessSupport_Module m )
{
    return(xdc_runtime_IGateProvider_Module)m;
}

/* Module_to_xdc_runtime_IGateProvider */
#define xdc_runtime_knl_IGateProcessSupport_Module_to_xdc_runtime_IGateProvider xdc_runtime_knl_IGateProcessSupport_Module_upCast2

/* Module_downCast2 */
static inline xdc_runtime_knl_IGateProcessSupport_Module xdc_runtime_knl_IGateProcessSupport_Module_downCast2( xdc_runtime_IGateProvider_Module m )
{
    xdc_runtime_Types_Base* b; for (b = m->__base; b; b = b->base) {
        if (b == &xdc_runtime_knl_IGateProcessSupport_Interface__BASE__C) return (xdc_runtime_knl_IGateProcessSupport_Module)m;
    } return 0;
}

/* Module_from_xdc_runtime_IGateProvider */
#define xdc_runtime_knl_IGateProcessSupport_Module_from_xdc_runtime_IGateProvider xdc_runtime_knl_IGateProcessSupport_Module_downCast2

/* Handle_upCast2 */
static inline xdc_runtime_IGateProvider_Handle xdc_runtime_knl_IGateProcessSupport_Handle_upCast2( xdc_runtime_knl_IGateProcessSupport_Handle i )
{
    return (xdc_runtime_IGateProvider_Handle)i;
}

/* Handle_to_xdc_runtime_IGateProvider */
#define xdc_runtime_knl_IGateProcessSupport_Handle_to_xdc_runtime_IGateProvider xdc_runtime_knl_IGateProcessSupport_Handle_upCast2

/* Handle_downCast2 */
static inline xdc_runtime_knl_IGateProcessSupport_Handle xdc_runtime_knl_IGateProcessSupport_Handle_downCast2( xdc_runtime_IGateProvider_Handle i )
{
    xdc_runtime_IGateProvider_Handle i2 = (xdc_runtime_IGateProvider_Handle)i;
    xdc_runtime_Types_Base* b; for (b = i2->__fxns->__base; b; b = b->base) {
        if (b == &xdc_runtime_knl_IGateProcessSupport_Interface__BASE__C) return (xdc_runtime_knl_IGateProcessSupport_Handle)i;
    } return 0;
}

/* Handle_from_xdc_runtime_IGateProvider */
#define xdc_runtime_knl_IGateProcessSupport_Handle_from_xdc_runtime_IGateProvider xdc_runtime_knl_IGateProcessSupport_Handle_downCast2


/*
 * ======== EPILOGUE ========
 */

#ifdef xdc_runtime_knl_IGateProcessSupport__top__
#undef __nested__
#endif

#endif /* xdc_runtime_knl_IGateProcessSupport__include */


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(xdc_runtime_knl_IGateProcessSupport__nolocalnames)

#ifndef xdc_runtime_knl_IGateProcessSupport__localnames__done
#define xdc_runtime_knl_IGateProcessSupport__localnames__done

/* module prefix */
#define IGateProcessSupport_Instance xdc_runtime_knl_IGateProcessSupport_Instance
#define IGateProcessSupport_Handle xdc_runtime_knl_IGateProcessSupport_Handle
#define IGateProcessSupport_Module xdc_runtime_knl_IGateProcessSupport_Module
#define IGateProcessSupport_Q_BLOCKING xdc_runtime_knl_IGateProcessSupport_Q_BLOCKING
#define IGateProcessSupport_Q_PREEMPTING xdc_runtime_knl_IGateProcessSupport_Q_PREEMPTING
#define IGateProcessSupport_GETREFCOUNT_FAILED xdc_runtime_knl_IGateProcessSupport_GETREFCOUNT_FAILED
#define IGateProcessSupport_Params xdc_runtime_knl_IGateProcessSupport_Params
#define IGateProcessSupport_query xdc_runtime_knl_IGateProcessSupport_query
#define IGateProcessSupport_query_fxnP xdc_runtime_knl_IGateProcessSupport_query_fxnP
#define IGateProcessSupport_query_FxnT xdc_runtime_knl_IGateProcessSupport_query_FxnT
#define IGateProcessSupport_enter xdc_runtime_knl_IGateProcessSupport_enter
#define IGateProcessSupport_enter_fxnP xdc_runtime_knl_IGateProcessSupport_enter_fxnP
#define IGateProcessSupport_enter_FxnT xdc_runtime_knl_IGateProcessSupport_enter_FxnT
#define IGateProcessSupport_leave xdc_runtime_knl_IGateProcessSupport_leave
#define IGateProcessSupport_leave_fxnP xdc_runtime_knl_IGateProcessSupport_leave_fxnP
#define IGateProcessSupport_leave_FxnT xdc_runtime_knl_IGateProcessSupport_leave_FxnT
#define IGateProcessSupport_getReferenceCount xdc_runtime_knl_IGateProcessSupport_getReferenceCount
#define IGateProcessSupport_getReferenceCount_fxnP xdc_runtime_knl_IGateProcessSupport_getReferenceCount_fxnP
#define IGateProcessSupport_getReferenceCount_FxnT xdc_runtime_knl_IGateProcessSupport_getReferenceCount_FxnT
#define IGateProcessSupport_Module_name xdc_runtime_knl_IGateProcessSupport_Module_name
#define IGateProcessSupport_create xdc_runtime_knl_IGateProcessSupport_create
#define IGateProcessSupport_delete xdc_runtime_knl_IGateProcessSupport_delete
#define IGateProcessSupport_Handle_label xdc_runtime_knl_IGateProcessSupport_Handle_label
#define IGateProcessSupport_Handle_to_Module xdc_runtime_knl_IGateProcessSupport_Handle_to_Module
#define IGateProcessSupport_Module_upCast xdc_runtime_knl_IGateProcessSupport_Module_upCast
#define IGateProcessSupport_Module_to_xdc_runtime_knl_IGateThreadSupport xdc_runtime_knl_IGateProcessSupport_Module_to_xdc_runtime_knl_IGateThreadSupport
#define IGateProcessSupport_Module_downCast xdc_runtime_knl_IGateProcessSupport_Module_downCast
#define IGateProcessSupport_Module_from_xdc_runtime_knl_IGateThreadSupport xdc_runtime_knl_IGateProcessSupport_Module_from_xdc_runtime_knl_IGateThreadSupport
#define IGateProcessSupport_Handle_upCast xdc_runtime_knl_IGateProcessSupport_Handle_upCast
#define IGateProcessSupport_Handle_to_xdc_runtime_knl_IGateThreadSupport xdc_runtime_knl_IGateProcessSupport_Handle_to_xdc_runtime_knl_IGateThreadSupport
#define IGateProcessSupport_Handle_downCast xdc_runtime_knl_IGateProcessSupport_Handle_downCast
#define IGateProcessSupport_Handle_from_xdc_runtime_knl_IGateThreadSupport xdc_runtime_knl_IGateProcessSupport_Handle_from_xdc_runtime_knl_IGateThreadSupport
#define IGateProcessSupport_Module_upCast2 xdc_runtime_knl_IGateProcessSupport_Module_upCast2
#define IGateProcessSupport_Module_to_xdc_runtime_IGateProvider xdc_runtime_knl_IGateProcessSupport_Module_to_xdc_runtime_IGateProvider
#define IGateProcessSupport_Module_downCast2 xdc_runtime_knl_IGateProcessSupport_Module_downCast2
#define IGateProcessSupport_Module_from_xdc_runtime_IGateProvider xdc_runtime_knl_IGateProcessSupport_Module_from_xdc_runtime_IGateProvider
#define IGateProcessSupport_Handle_upCast2 xdc_runtime_knl_IGateProcessSupport_Handle_upCast2
#define IGateProcessSupport_Handle_to_xdc_runtime_IGateProvider xdc_runtime_knl_IGateProcessSupport_Handle_to_xdc_runtime_IGateProvider
#define IGateProcessSupport_Handle_downCast2 xdc_runtime_knl_IGateProcessSupport_Handle_downCast2
#define IGateProcessSupport_Handle_from_xdc_runtime_IGateProvider xdc_runtime_knl_IGateProcessSupport_Handle_from_xdc_runtime_IGateProvider

#endif /* xdc_runtime_knl_IGateProcessSupport__localnames__done */
#endif
/*
 *  @(#) xdc.runtime.knl; 1, 0, 0,0; 4-24-2015 12:34:16; /db/ztree/library/trees/xdc/xdc-A71/src/packages/
 */

