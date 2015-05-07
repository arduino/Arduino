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

#ifndef xdc_runtime_IFilterLogger__include
#define xdc_runtime_IFilterLogger__include

#ifndef __nested__
#define __nested__
#define xdc_runtime_IFilterLogger__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define xdc_runtime_IFilterLogger___VERS 160


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/IInstance.h>
#include <xdc/runtime/package/package.defs.h>

#include <xdc/runtime/ILogger.h>
#include <xdc/runtime/Diags.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */


/*
 * ======== PER-INSTANCE TYPES ========
 */

/* Params */
struct xdc_runtime_IFilterLogger_Params {
    size_t __size;
    const void *__self;
    void *__fxns;
    xdc_runtime_IInstance_Params *instance;
};


/*
 * ======== VIRTUAL FUNCTIONS ========
 */

/* Fxns__ */
struct xdc_runtime_IFilterLogger_Fxns__ {
    xdc_runtime_Types_Base* __base;
    const xdc_runtime_Types_SysFxns2 *__sysp;
    xdc_Bool (*enable)(void*);
    xdc_Bool (*disable)(void*);
    xdc_Void (*write0)(void*, xdc_runtime_Log_Event, xdc_runtime_Types_ModuleId);
    xdc_Void (*write1)(void*, xdc_runtime_Log_Event, xdc_runtime_Types_ModuleId, xdc_IArg);
    xdc_Void (*write2)(void*, xdc_runtime_Log_Event, xdc_runtime_Types_ModuleId, xdc_IArg, xdc_IArg);
    xdc_Void (*write4)(void*, xdc_runtime_Log_Event, xdc_runtime_Types_ModuleId, xdc_IArg, xdc_IArg, xdc_IArg, xdc_IArg);
    xdc_Void (*write8)(void*, xdc_runtime_Log_Event, xdc_runtime_Types_ModuleId, xdc_IArg, xdc_IArg, xdc_IArg, xdc_IArg, xdc_IArg, xdc_IArg, xdc_IArg, xdc_IArg);
    xdc_Void (*setFilterLevel)(void*, xdc_runtime_Diags_Mask, xdc_runtime_Diags_EventLevel);
    xdc_runtime_Diags_Mask (*getFilterLevel)(void*, xdc_runtime_Diags_EventLevel);
    xdc_runtime_Types_SysFxns2 __sfxns;
};

/* Interface__BASE__C */
__extern const xdc_runtime_Types_Base xdc_runtime_IFilterLogger_Interface__BASE__C;


/*
 * ======== FUNCTION STUBS ========
 */

/* create */
xdc__CODESECT(xdc_runtime_IFilterLogger_create, "xdc_runtime_IFilterLogger_create")
__extern xdc_runtime_IFilterLogger_Handle xdc_runtime_IFilterLogger_create(xdc_runtime_IFilterLogger_Module, const xdc_runtime_IFilterLogger_Params *, xdc_runtime_Error_Block *__eb);

/* delete */
xdc__CODESECT(xdc_runtime_IFilterLogger_delete, "xdc_runtime_IFilterLogger_delete")
__extern xdc_Void xdc_runtime_IFilterLogger_delete(xdc_runtime_IFilterLogger_Handle *);

/* Handle_to_Module */
static inline xdc_runtime_IFilterLogger_Module xdc_runtime_IFilterLogger_Handle_to_Module( xdc_runtime_IFilterLogger_Handle inst )
{
    return inst->__fxns;
}

/* Handle_label */
static inline xdc_runtime_Types_Label *xdc_runtime_IFilterLogger_Handle_label( xdc_runtime_IFilterLogger_Handle inst, xdc_runtime_Types_Label *lab )
{
    return inst->__fxns->__sysp->__label(inst, lab);
}

/* Module_id */
static inline xdc_runtime_Types_ModuleId xdc_runtime_IFilterLogger_Module_id( xdc_runtime_IFilterLogger_Module mod )
{
    return mod->__sysp->__mid;
}

/* enable */
static inline xdc_Bool xdc_runtime_IFilterLogger_enable( xdc_runtime_IFilterLogger_Handle __inst )
{
    return __inst->__fxns->enable((void*)__inst);
}

/* disable */
static inline xdc_Bool xdc_runtime_IFilterLogger_disable( xdc_runtime_IFilterLogger_Handle __inst )
{
    return __inst->__fxns->disable((void*)__inst);
}

/* write0 */
static inline xdc_Void xdc_runtime_IFilterLogger_write0( xdc_runtime_IFilterLogger_Handle __inst, xdc_runtime_Log_Event evt, xdc_runtime_Types_ModuleId mid )
{
    __inst->__fxns->write0((void*)__inst, evt, mid);
}

/* write1 */
static inline xdc_Void xdc_runtime_IFilterLogger_write1( xdc_runtime_IFilterLogger_Handle __inst, xdc_runtime_Log_Event evt, xdc_runtime_Types_ModuleId mid, xdc_IArg a1 )
{
    __inst->__fxns->write1((void*)__inst, evt, mid, a1);
}

/* write2 */
static inline xdc_Void xdc_runtime_IFilterLogger_write2( xdc_runtime_IFilterLogger_Handle __inst, xdc_runtime_Log_Event evt, xdc_runtime_Types_ModuleId mid, xdc_IArg a1, xdc_IArg a2 )
{
    __inst->__fxns->write2((void*)__inst, evt, mid, a1, a2);
}

/* write4 */
static inline xdc_Void xdc_runtime_IFilterLogger_write4( xdc_runtime_IFilterLogger_Handle __inst, xdc_runtime_Log_Event evt, xdc_runtime_Types_ModuleId mid, xdc_IArg a1, xdc_IArg a2, xdc_IArg a3, xdc_IArg a4 )
{
    __inst->__fxns->write4((void*)__inst, evt, mid, a1, a2, a3, a4);
}

/* write8 */
static inline xdc_Void xdc_runtime_IFilterLogger_write8( xdc_runtime_IFilterLogger_Handle __inst, xdc_runtime_Log_Event evt, xdc_runtime_Types_ModuleId mid, xdc_IArg a1, xdc_IArg a2, xdc_IArg a3, xdc_IArg a4, xdc_IArg a5, xdc_IArg a6, xdc_IArg a7, xdc_IArg a8 )
{
    __inst->__fxns->write8((void*)__inst, evt, mid, a1, a2, a3, a4, a5, a6, a7, a8);
}

/* setFilterLevel */
static inline xdc_Void xdc_runtime_IFilterLogger_setFilterLevel( xdc_runtime_IFilterLogger_Handle __inst, xdc_runtime_Diags_Mask mask, xdc_runtime_Diags_EventLevel filterLevel )
{
    __inst->__fxns->setFilterLevel((void*)__inst, mask, filterLevel);
}

/* getFilterLevel */
static inline xdc_runtime_Diags_Mask xdc_runtime_IFilterLogger_getFilterLevel( xdc_runtime_IFilterLogger_Handle __inst, xdc_runtime_Diags_EventLevel level )
{
    return __inst->__fxns->getFilterLevel((void*)__inst, level);
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
typedef xdc_Bool (*xdc_runtime_IFilterLogger_enable_FxnT)(xdc_Void *);
static inline xdc_runtime_IFilterLogger_enable_FxnT xdc_runtime_IFilterLogger_enable_fxnP( xdc_runtime_IFilterLogger_Handle __inst )
{
    return (xdc_runtime_IFilterLogger_enable_FxnT)__inst->__fxns->enable;
}

/* disable_{FxnT,fxnP} */
typedef xdc_Bool (*xdc_runtime_IFilterLogger_disable_FxnT)(xdc_Void *);
static inline xdc_runtime_IFilterLogger_disable_FxnT xdc_runtime_IFilterLogger_disable_fxnP( xdc_runtime_IFilterLogger_Handle __inst )
{
    return (xdc_runtime_IFilterLogger_disable_FxnT)__inst->__fxns->disable;
}

/* write0_{FxnT,fxnP} */
typedef xdc_Void (*xdc_runtime_IFilterLogger_write0_FxnT)(xdc_Void *, xdc_runtime_Log_Event, xdc_runtime_Types_ModuleId);
static inline xdc_runtime_IFilterLogger_write0_FxnT xdc_runtime_IFilterLogger_write0_fxnP( xdc_runtime_IFilterLogger_Handle __inst )
{
    return (xdc_runtime_IFilterLogger_write0_FxnT)__inst->__fxns->write0;
}

/* write1_{FxnT,fxnP} */
typedef xdc_Void (*xdc_runtime_IFilterLogger_write1_FxnT)(xdc_Void *, xdc_runtime_Log_Event, xdc_runtime_Types_ModuleId, xdc_IArg);
static inline xdc_runtime_IFilterLogger_write1_FxnT xdc_runtime_IFilterLogger_write1_fxnP( xdc_runtime_IFilterLogger_Handle __inst )
{
    return (xdc_runtime_IFilterLogger_write1_FxnT)__inst->__fxns->write1;
}

/* write2_{FxnT,fxnP} */
typedef xdc_Void (*xdc_runtime_IFilterLogger_write2_FxnT)(xdc_Void *, xdc_runtime_Log_Event, xdc_runtime_Types_ModuleId, xdc_IArg, xdc_IArg);
static inline xdc_runtime_IFilterLogger_write2_FxnT xdc_runtime_IFilterLogger_write2_fxnP( xdc_runtime_IFilterLogger_Handle __inst )
{
    return (xdc_runtime_IFilterLogger_write2_FxnT)__inst->__fxns->write2;
}

/* write4_{FxnT,fxnP} */
typedef xdc_Void (*xdc_runtime_IFilterLogger_write4_FxnT)(xdc_Void *, xdc_runtime_Log_Event, xdc_runtime_Types_ModuleId, xdc_IArg, xdc_IArg, xdc_IArg, xdc_IArg);
static inline xdc_runtime_IFilterLogger_write4_FxnT xdc_runtime_IFilterLogger_write4_fxnP( xdc_runtime_IFilterLogger_Handle __inst )
{
    return (xdc_runtime_IFilterLogger_write4_FxnT)__inst->__fxns->write4;
}

/* write8_{FxnT,fxnP} */
typedef xdc_Void (*xdc_runtime_IFilterLogger_write8_FxnT)(xdc_Void *, xdc_runtime_Log_Event, xdc_runtime_Types_ModuleId, xdc_IArg, xdc_IArg, xdc_IArg, xdc_IArg, xdc_IArg, xdc_IArg, xdc_IArg, xdc_IArg);
static inline xdc_runtime_IFilterLogger_write8_FxnT xdc_runtime_IFilterLogger_write8_fxnP( xdc_runtime_IFilterLogger_Handle __inst )
{
    return (xdc_runtime_IFilterLogger_write8_FxnT)__inst->__fxns->write8;
}

/* setFilterLevel_{FxnT,fxnP} */
typedef xdc_Void (*xdc_runtime_IFilterLogger_setFilterLevel_FxnT)(xdc_Void *, xdc_runtime_Diags_Mask, xdc_runtime_Diags_EventLevel);
static inline xdc_runtime_IFilterLogger_setFilterLevel_FxnT xdc_runtime_IFilterLogger_setFilterLevel_fxnP( xdc_runtime_IFilterLogger_Handle __inst )
{
    return (xdc_runtime_IFilterLogger_setFilterLevel_FxnT)__inst->__fxns->setFilterLevel;
}

/* getFilterLevel_{FxnT,fxnP} */
typedef xdc_runtime_Diags_Mask (*xdc_runtime_IFilterLogger_getFilterLevel_FxnT)(xdc_Void *, xdc_runtime_Diags_EventLevel);
static inline xdc_runtime_IFilterLogger_getFilterLevel_FxnT xdc_runtime_IFilterLogger_getFilterLevel_fxnP( xdc_runtime_IFilterLogger_Handle __inst )
{
    return (xdc_runtime_IFilterLogger_getFilterLevel_FxnT)__inst->__fxns->getFilterLevel;
}


/*
 * ======== CONVERTORS ========
 */

/* Module_upCast */
static inline xdc_runtime_ILogger_Module xdc_runtime_IFilterLogger_Module_upCast( xdc_runtime_IFilterLogger_Module m )
{
    return(xdc_runtime_ILogger_Module)m;
}

/* Module_to_xdc_runtime_ILogger */
#define xdc_runtime_IFilterLogger_Module_to_xdc_runtime_ILogger xdc_runtime_IFilterLogger_Module_upCast

/* Module_downCast */
static inline xdc_runtime_IFilterLogger_Module xdc_runtime_IFilterLogger_Module_downCast( xdc_runtime_ILogger_Module m )
{
    xdc_runtime_Types_Base* b; for (b = m->__base; b; b = b->base) {
        if (b == &xdc_runtime_IFilterLogger_Interface__BASE__C) return (xdc_runtime_IFilterLogger_Module)m;
    } return 0;
}

/* Module_from_xdc_runtime_ILogger */
#define xdc_runtime_IFilterLogger_Module_from_xdc_runtime_ILogger xdc_runtime_IFilterLogger_Module_downCast

/* Handle_upCast */
static inline xdc_runtime_ILogger_Handle xdc_runtime_IFilterLogger_Handle_upCast( xdc_runtime_IFilterLogger_Handle i )
{
    return (xdc_runtime_ILogger_Handle)i;
}

/* Handle_to_xdc_runtime_ILogger */
#define xdc_runtime_IFilterLogger_Handle_to_xdc_runtime_ILogger xdc_runtime_IFilterLogger_Handle_upCast

/* Handle_downCast */
static inline xdc_runtime_IFilterLogger_Handle xdc_runtime_IFilterLogger_Handle_downCast( xdc_runtime_ILogger_Handle i )
{
    xdc_runtime_ILogger_Handle i2 = (xdc_runtime_ILogger_Handle)i;
    xdc_runtime_Types_Base* b; for (b = i2->__fxns->__base; b; b = b->base) {
        if (b == &xdc_runtime_IFilterLogger_Interface__BASE__C) return (xdc_runtime_IFilterLogger_Handle)i;
    } return 0;
}

/* Handle_from_xdc_runtime_ILogger */
#define xdc_runtime_IFilterLogger_Handle_from_xdc_runtime_ILogger xdc_runtime_IFilterLogger_Handle_downCast


/*
 * ======== EPILOGUE ========
 */

#ifdef xdc_runtime_IFilterLogger__top__
#undef __nested__
#endif

#endif /* xdc_runtime_IFilterLogger__include */


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(xdc_runtime_IFilterLogger__nolocalnames)

#ifndef xdc_runtime_IFilterLogger__localnames__done
#define xdc_runtime_IFilterLogger__localnames__done

/* module prefix */
#define IFilterLogger_Instance xdc_runtime_IFilterLogger_Instance
#define IFilterLogger_Handle xdc_runtime_IFilterLogger_Handle
#define IFilterLogger_Module xdc_runtime_IFilterLogger_Module
#define IFilterLogger_Params xdc_runtime_IFilterLogger_Params
#define IFilterLogger_enable xdc_runtime_IFilterLogger_enable
#define IFilterLogger_enable_fxnP xdc_runtime_IFilterLogger_enable_fxnP
#define IFilterLogger_enable_FxnT xdc_runtime_IFilterLogger_enable_FxnT
#define IFilterLogger_disable xdc_runtime_IFilterLogger_disable
#define IFilterLogger_disable_fxnP xdc_runtime_IFilterLogger_disable_fxnP
#define IFilterLogger_disable_FxnT xdc_runtime_IFilterLogger_disable_FxnT
#define IFilterLogger_write0 xdc_runtime_IFilterLogger_write0
#define IFilterLogger_write0_fxnP xdc_runtime_IFilterLogger_write0_fxnP
#define IFilterLogger_write0_FxnT xdc_runtime_IFilterLogger_write0_FxnT
#define IFilterLogger_write1 xdc_runtime_IFilterLogger_write1
#define IFilterLogger_write1_fxnP xdc_runtime_IFilterLogger_write1_fxnP
#define IFilterLogger_write1_FxnT xdc_runtime_IFilterLogger_write1_FxnT
#define IFilterLogger_write2 xdc_runtime_IFilterLogger_write2
#define IFilterLogger_write2_fxnP xdc_runtime_IFilterLogger_write2_fxnP
#define IFilterLogger_write2_FxnT xdc_runtime_IFilterLogger_write2_FxnT
#define IFilterLogger_write4 xdc_runtime_IFilterLogger_write4
#define IFilterLogger_write4_fxnP xdc_runtime_IFilterLogger_write4_fxnP
#define IFilterLogger_write4_FxnT xdc_runtime_IFilterLogger_write4_FxnT
#define IFilterLogger_write8 xdc_runtime_IFilterLogger_write8
#define IFilterLogger_write8_fxnP xdc_runtime_IFilterLogger_write8_fxnP
#define IFilterLogger_write8_FxnT xdc_runtime_IFilterLogger_write8_FxnT
#define IFilterLogger_setFilterLevel xdc_runtime_IFilterLogger_setFilterLevel
#define IFilterLogger_setFilterLevel_fxnP xdc_runtime_IFilterLogger_setFilterLevel_fxnP
#define IFilterLogger_setFilterLevel_FxnT xdc_runtime_IFilterLogger_setFilterLevel_FxnT
#define IFilterLogger_getFilterLevel xdc_runtime_IFilterLogger_getFilterLevel
#define IFilterLogger_getFilterLevel_fxnP xdc_runtime_IFilterLogger_getFilterLevel_fxnP
#define IFilterLogger_getFilterLevel_FxnT xdc_runtime_IFilterLogger_getFilterLevel_FxnT
#define IFilterLogger_Module_name xdc_runtime_IFilterLogger_Module_name
#define IFilterLogger_delete xdc_runtime_IFilterLogger_delete
#define IFilterLogger_Handle_label xdc_runtime_IFilterLogger_Handle_label
#define IFilterLogger_Handle_to_Module xdc_runtime_IFilterLogger_Handle_to_Module
#define IFilterLogger_Module_upCast xdc_runtime_IFilterLogger_Module_upCast
#define IFilterLogger_Module_to_xdc_runtime_ILogger xdc_runtime_IFilterLogger_Module_to_xdc_runtime_ILogger
#define IFilterLogger_Module_downCast xdc_runtime_IFilterLogger_Module_downCast
#define IFilterLogger_Module_from_xdc_runtime_ILogger xdc_runtime_IFilterLogger_Module_from_xdc_runtime_ILogger
#define IFilterLogger_Handle_upCast xdc_runtime_IFilterLogger_Handle_upCast
#define IFilterLogger_Handle_to_xdc_runtime_ILogger xdc_runtime_IFilterLogger_Handle_to_xdc_runtime_ILogger
#define IFilterLogger_Handle_downCast xdc_runtime_IFilterLogger_Handle_downCast
#define IFilterLogger_Handle_from_xdc_runtime_ILogger xdc_runtime_IFilterLogger_Handle_from_xdc_runtime_ILogger

#endif /* xdc_runtime_IFilterLogger__localnames__done */
#endif
/*
 *  @(#) xdc.runtime; 2, 1, 0,0; 4-24-2015 12:34:12; /db/ztree/library/trees/xdc/xdc-A71/src/packages/
 */

