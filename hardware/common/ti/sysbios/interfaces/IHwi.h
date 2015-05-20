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
 *     
 *     EPILOGUE
 *     PREFIX ALIASES
 */


/*
 * ======== PROLOGUE ========
 */

#ifndef ti_sysbios_interfaces_IHwi__include
#define ti_sysbios_interfaces_IHwi__include

#ifndef __nested__
#define __nested__
#define ti_sysbios_interfaces_IHwi__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define ti_sysbios_interfaces_IHwi___VERS 160


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/IInstance.h>
#include <ti/sysbios/interfaces/package/package.defs.h>

#include <xdc/runtime/Error.h>
#include <xdc/runtime/IModule.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */

/* FuncPtr */
typedef xdc_Void (*ti_sysbios_interfaces_IHwi_FuncPtr)(xdc_UArg);

/* Irp */
typedef xdc_UArg ti_sysbios_interfaces_IHwi_Irp;

/* HookSet */
struct ti_sysbios_interfaces_IHwi_HookSet {
    xdc_Void (*registerFxn)(xdc_Int);
    xdc_Void (*createFxn)(ti_sysbios_interfaces_IHwi_Handle, xdc_runtime_Error_Block*);
    xdc_Void (*beginFxn)(ti_sysbios_interfaces_IHwi_Handle);
    xdc_Void (*endFxn)(ti_sysbios_interfaces_IHwi_Handle);
    xdc_Void (*deleteFxn)(ti_sysbios_interfaces_IHwi_Handle);
};

/* MaskingOption */
enum ti_sysbios_interfaces_IHwi_MaskingOption {
    ti_sysbios_interfaces_IHwi_MaskingOption_NONE,
    ti_sysbios_interfaces_IHwi_MaskingOption_ALL,
    ti_sysbios_interfaces_IHwi_MaskingOption_SELF,
    ti_sysbios_interfaces_IHwi_MaskingOption_BITMASK,
    ti_sysbios_interfaces_IHwi_MaskingOption_LOWER
};
typedef enum ti_sysbios_interfaces_IHwi_MaskingOption ti_sysbios_interfaces_IHwi_MaskingOption;

/* StackInfo */
struct ti_sysbios_interfaces_IHwi_StackInfo {
    xdc_SizeT hwiStackPeak;
    xdc_SizeT hwiStackSize;
    xdc_Ptr hwiStackBase;
};


/*
 * ======== CREATE ARGS ========
 */

/* Args__create */
typedef struct ti_sysbios_interfaces_IHwi_Args__create {
    xdc_Int intNum;
    ti_sysbios_interfaces_IHwi_FuncPtr hwiFxn;
} ti_sysbios_interfaces_IHwi_Args__create;


/*
 * ======== PER-INSTANCE TYPES ========
 */

/* Params */
struct ti_sysbios_interfaces_IHwi_Params {
    size_t __size;
    const void *__self;
    void *__fxns;
    xdc_runtime_IInstance_Params *instance;
    ti_sysbios_interfaces_IHwi_MaskingOption maskSetting;
    xdc_UArg arg;
    xdc_Bool enableInt;
    xdc_Int eventId;
    xdc_Int priority;
};


/*
 * ======== VIRTUAL FUNCTIONS ========
 */

/* Fxns__ */
struct ti_sysbios_interfaces_IHwi_Fxns__ {
    xdc_runtime_Types_Base* __base;
    const xdc_runtime_Types_SysFxns2 *__sysp;
    xdc_Bool (*getStackInfo)(ti_sysbios_interfaces_IHwi_StackInfo*, xdc_Bool);
    xdc_Bool (*getCoreStackInfo)(ti_sysbios_interfaces_IHwi_StackInfo*, xdc_Bool, xdc_UInt);
    xdc_Void (*startup)(void);
    xdc_UInt (*disable)(void);
    xdc_UInt (*enable)(void);
    xdc_Void (*restore)(xdc_UInt);
    xdc_Void (*switchFromBootStack)(void);
    xdc_Void (*post)(xdc_UInt);
    xdc_Char *(*getTaskSP)(void);
    xdc_UInt (*disableInterrupt)(xdc_UInt);
    xdc_UInt (*enableInterrupt)(xdc_UInt);
    xdc_Void (*restoreInterrupt)(xdc_UInt, xdc_UInt);
    xdc_Void (*clearInterrupt)(xdc_UInt);
    ti_sysbios_interfaces_IHwi_FuncPtr (*getFunc)(void*, xdc_UArg*);
    xdc_Void (*setFunc)(void*, ti_sysbios_interfaces_IHwi_FuncPtr, xdc_UArg);
    xdc_Ptr (*getHookContext)(void*, xdc_Int);
    xdc_Void (*setHookContext)(void*, xdc_Int, xdc_Ptr);
    ti_sysbios_interfaces_IHwi_Irp (*getIrp)(void*);
    xdc_runtime_Types_SysFxns2 __sfxns;
};

/* Interface__BASE__C */
__extern const xdc_runtime_Types_Base ti_sysbios_interfaces_IHwi_Interface__BASE__C;


/*
 * ======== FUNCTION STUBS ========
 */

/* create */
xdc__CODESECT(ti_sysbios_interfaces_IHwi_create, "ti_sysbios_interfaces_IHwi_create")
__extern ti_sysbios_interfaces_IHwi_Handle ti_sysbios_interfaces_IHwi_create(ti_sysbios_interfaces_IHwi_Module, xdc_Int intNum, ti_sysbios_interfaces_IHwi_FuncPtr hwiFxn, const ti_sysbios_interfaces_IHwi_Params *, xdc_runtime_Error_Block *__eb);

/* delete */
xdc__CODESECT(ti_sysbios_interfaces_IHwi_delete, "ti_sysbios_interfaces_IHwi_delete")
__extern xdc_Void ti_sysbios_interfaces_IHwi_delete(ti_sysbios_interfaces_IHwi_Handle *);

/* Handle_to_Module */
static inline ti_sysbios_interfaces_IHwi_Module ti_sysbios_interfaces_IHwi_Handle_to_Module( ti_sysbios_interfaces_IHwi_Handle inst )
{
    return inst->__fxns;
}

/* Handle_label */
static inline xdc_runtime_Types_Label *ti_sysbios_interfaces_IHwi_Handle_label( ti_sysbios_interfaces_IHwi_Handle inst, xdc_runtime_Types_Label *lab )
{
    return inst->__fxns->__sysp->__label(inst, lab);
}

/* Module_id */
static inline xdc_runtime_Types_ModuleId ti_sysbios_interfaces_IHwi_Module_id( ti_sysbios_interfaces_IHwi_Module mod )
{
    return mod->__sysp->__mid;
}

/* getStackInfo */
static inline xdc_Bool ti_sysbios_interfaces_IHwi_getStackInfo( ti_sysbios_interfaces_IHwi_Module __inst, ti_sysbios_interfaces_IHwi_StackInfo *stkInfo, xdc_Bool computeStackDepth )
{
    return __inst->getStackInfo(stkInfo, computeStackDepth);
}

/* getCoreStackInfo */
static inline xdc_Bool ti_sysbios_interfaces_IHwi_getCoreStackInfo( ti_sysbios_interfaces_IHwi_Module __inst, ti_sysbios_interfaces_IHwi_StackInfo *stkInfo, xdc_Bool computeStackDepth, xdc_UInt coreId )
{
    return __inst->getCoreStackInfo(stkInfo, computeStackDepth, coreId);
}

/* startup */
static inline xdc_Void ti_sysbios_interfaces_IHwi_startup( ti_sysbios_interfaces_IHwi_Module __inst )
{
    __inst->startup();
}

/* disable */
static inline xdc_UInt ti_sysbios_interfaces_IHwi_disable( ti_sysbios_interfaces_IHwi_Module __inst )
{
    return __inst->disable();
}

/* enable */
static inline xdc_UInt ti_sysbios_interfaces_IHwi_enable( ti_sysbios_interfaces_IHwi_Module __inst )
{
    return __inst->enable();
}

/* restore */
static inline xdc_Void ti_sysbios_interfaces_IHwi_restore( ti_sysbios_interfaces_IHwi_Module __inst, xdc_UInt key )
{
    __inst->restore(key);
}

/* switchFromBootStack */
static inline xdc_Void ti_sysbios_interfaces_IHwi_switchFromBootStack( ti_sysbios_interfaces_IHwi_Module __inst )
{
    __inst->switchFromBootStack();
}

/* post */
static inline xdc_Void ti_sysbios_interfaces_IHwi_post( ti_sysbios_interfaces_IHwi_Module __inst, xdc_UInt intNum )
{
    __inst->post(intNum);
}

/* getTaskSP */
static inline xdc_Char *ti_sysbios_interfaces_IHwi_getTaskSP( ti_sysbios_interfaces_IHwi_Module __inst )
{
    return __inst->getTaskSP();
}

/* disableInterrupt */
static inline xdc_UInt ti_sysbios_interfaces_IHwi_disableInterrupt( ti_sysbios_interfaces_IHwi_Module __inst, xdc_UInt intNum )
{
    return __inst->disableInterrupt(intNum);
}

/* enableInterrupt */
static inline xdc_UInt ti_sysbios_interfaces_IHwi_enableInterrupt( ti_sysbios_interfaces_IHwi_Module __inst, xdc_UInt intNum )
{
    return __inst->enableInterrupt(intNum);
}

/* restoreInterrupt */
static inline xdc_Void ti_sysbios_interfaces_IHwi_restoreInterrupt( ti_sysbios_interfaces_IHwi_Module __inst, xdc_UInt intNum, xdc_UInt key )
{
    __inst->restoreInterrupt(intNum, key);
}

/* clearInterrupt */
static inline xdc_Void ti_sysbios_interfaces_IHwi_clearInterrupt( ti_sysbios_interfaces_IHwi_Module __inst, xdc_UInt intNum )
{
    __inst->clearInterrupt(intNum);
}

/* getFunc */
static inline ti_sysbios_interfaces_IHwi_FuncPtr ti_sysbios_interfaces_IHwi_getFunc( ti_sysbios_interfaces_IHwi_Handle __inst, xdc_UArg *arg )
{
    return __inst->__fxns->getFunc((void*)__inst, arg);
}

/* setFunc */
static inline xdc_Void ti_sysbios_interfaces_IHwi_setFunc( ti_sysbios_interfaces_IHwi_Handle __inst, ti_sysbios_interfaces_IHwi_FuncPtr fxn, xdc_UArg arg )
{
    __inst->__fxns->setFunc((void*)__inst, fxn, arg);
}

/* getHookContext */
static inline xdc_Ptr ti_sysbios_interfaces_IHwi_getHookContext( ti_sysbios_interfaces_IHwi_Handle __inst, xdc_Int id )
{
    return __inst->__fxns->getHookContext((void*)__inst, id);
}

/* setHookContext */
static inline xdc_Void ti_sysbios_interfaces_IHwi_setHookContext( ti_sysbios_interfaces_IHwi_Handle __inst, xdc_Int id, xdc_Ptr hookContext )
{
    __inst->__fxns->setHookContext((void*)__inst, id, hookContext);
}

/* getIrp */
static inline ti_sysbios_interfaces_IHwi_Irp ti_sysbios_interfaces_IHwi_getIrp( ti_sysbios_interfaces_IHwi_Handle __inst )
{
    return __inst->__fxns->getIrp((void*)__inst);
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

/* getStackInfo_{FxnT,fxnP} */
typedef xdc_Bool (*ti_sysbios_interfaces_IHwi_getStackInfo_FxnT)(ti_sysbios_interfaces_IHwi_StackInfo*, xdc_Bool);
static inline ti_sysbios_interfaces_IHwi_getStackInfo_FxnT ti_sysbios_interfaces_IHwi_getStackInfo_fxnP( ti_sysbios_interfaces_IHwi_Module __inst )
{
    return (ti_sysbios_interfaces_IHwi_getStackInfo_FxnT)__inst->getStackInfo;
}

/* getCoreStackInfo_{FxnT,fxnP} */
typedef xdc_Bool (*ti_sysbios_interfaces_IHwi_getCoreStackInfo_FxnT)(ti_sysbios_interfaces_IHwi_StackInfo*, xdc_Bool, xdc_UInt);
static inline ti_sysbios_interfaces_IHwi_getCoreStackInfo_FxnT ti_sysbios_interfaces_IHwi_getCoreStackInfo_fxnP( ti_sysbios_interfaces_IHwi_Module __inst )
{
    return (ti_sysbios_interfaces_IHwi_getCoreStackInfo_FxnT)__inst->getCoreStackInfo;
}

/* startup_{FxnT,fxnP} */
typedef xdc_Void (*ti_sysbios_interfaces_IHwi_startup_FxnT)(void);
static inline ti_sysbios_interfaces_IHwi_startup_FxnT ti_sysbios_interfaces_IHwi_startup_fxnP( ti_sysbios_interfaces_IHwi_Module __inst )
{
    return (ti_sysbios_interfaces_IHwi_startup_FxnT)__inst->startup;
}

/* disable_{FxnT,fxnP} */
typedef xdc_UInt (*ti_sysbios_interfaces_IHwi_disable_FxnT)(void);
static inline ti_sysbios_interfaces_IHwi_disable_FxnT ti_sysbios_interfaces_IHwi_disable_fxnP( ti_sysbios_interfaces_IHwi_Module __inst )
{
    return (ti_sysbios_interfaces_IHwi_disable_FxnT)__inst->disable;
}

/* enable_{FxnT,fxnP} */
typedef xdc_UInt (*ti_sysbios_interfaces_IHwi_enable_FxnT)(void);
static inline ti_sysbios_interfaces_IHwi_enable_FxnT ti_sysbios_interfaces_IHwi_enable_fxnP( ti_sysbios_interfaces_IHwi_Module __inst )
{
    return (ti_sysbios_interfaces_IHwi_enable_FxnT)__inst->enable;
}

/* restore_{FxnT,fxnP} */
typedef xdc_Void (*ti_sysbios_interfaces_IHwi_restore_FxnT)(xdc_UInt);
static inline ti_sysbios_interfaces_IHwi_restore_FxnT ti_sysbios_interfaces_IHwi_restore_fxnP( ti_sysbios_interfaces_IHwi_Module __inst )
{
    return (ti_sysbios_interfaces_IHwi_restore_FxnT)__inst->restore;
}

/* switchFromBootStack_{FxnT,fxnP} */
typedef xdc_Void (*ti_sysbios_interfaces_IHwi_switchFromBootStack_FxnT)(void);
static inline ti_sysbios_interfaces_IHwi_switchFromBootStack_FxnT ti_sysbios_interfaces_IHwi_switchFromBootStack_fxnP( ti_sysbios_interfaces_IHwi_Module __inst )
{
    return (ti_sysbios_interfaces_IHwi_switchFromBootStack_FxnT)__inst->switchFromBootStack;
}

/* post_{FxnT,fxnP} */
typedef xdc_Void (*ti_sysbios_interfaces_IHwi_post_FxnT)(xdc_UInt);
static inline ti_sysbios_interfaces_IHwi_post_FxnT ti_sysbios_interfaces_IHwi_post_fxnP( ti_sysbios_interfaces_IHwi_Module __inst )
{
    return (ti_sysbios_interfaces_IHwi_post_FxnT)__inst->post;
}

/* getTaskSP_{FxnT,fxnP} */
typedef xdc_Char *(*ti_sysbios_interfaces_IHwi_getTaskSP_FxnT)(void);
static inline ti_sysbios_interfaces_IHwi_getTaskSP_FxnT ti_sysbios_interfaces_IHwi_getTaskSP_fxnP( ti_sysbios_interfaces_IHwi_Module __inst )
{
    return (ti_sysbios_interfaces_IHwi_getTaskSP_FxnT)__inst->getTaskSP;
}

/* disableInterrupt_{FxnT,fxnP} */
typedef xdc_UInt (*ti_sysbios_interfaces_IHwi_disableInterrupt_FxnT)(xdc_UInt);
static inline ti_sysbios_interfaces_IHwi_disableInterrupt_FxnT ti_sysbios_interfaces_IHwi_disableInterrupt_fxnP( ti_sysbios_interfaces_IHwi_Module __inst )
{
    return (ti_sysbios_interfaces_IHwi_disableInterrupt_FxnT)__inst->disableInterrupt;
}

/* enableInterrupt_{FxnT,fxnP} */
typedef xdc_UInt (*ti_sysbios_interfaces_IHwi_enableInterrupt_FxnT)(xdc_UInt);
static inline ti_sysbios_interfaces_IHwi_enableInterrupt_FxnT ti_sysbios_interfaces_IHwi_enableInterrupt_fxnP( ti_sysbios_interfaces_IHwi_Module __inst )
{
    return (ti_sysbios_interfaces_IHwi_enableInterrupt_FxnT)__inst->enableInterrupt;
}

/* restoreInterrupt_{FxnT,fxnP} */
typedef xdc_Void (*ti_sysbios_interfaces_IHwi_restoreInterrupt_FxnT)(xdc_UInt, xdc_UInt);
static inline ti_sysbios_interfaces_IHwi_restoreInterrupt_FxnT ti_sysbios_interfaces_IHwi_restoreInterrupt_fxnP( ti_sysbios_interfaces_IHwi_Module __inst )
{
    return (ti_sysbios_interfaces_IHwi_restoreInterrupt_FxnT)__inst->restoreInterrupt;
}

/* clearInterrupt_{FxnT,fxnP} */
typedef xdc_Void (*ti_sysbios_interfaces_IHwi_clearInterrupt_FxnT)(xdc_UInt);
static inline ti_sysbios_interfaces_IHwi_clearInterrupt_FxnT ti_sysbios_interfaces_IHwi_clearInterrupt_fxnP( ti_sysbios_interfaces_IHwi_Module __inst )
{
    return (ti_sysbios_interfaces_IHwi_clearInterrupt_FxnT)__inst->clearInterrupt;
}

/* getFunc_{FxnT,fxnP} */
typedef ti_sysbios_interfaces_IHwi_FuncPtr (*ti_sysbios_interfaces_IHwi_getFunc_FxnT)(xdc_Void *, xdc_UArg*);
static inline ti_sysbios_interfaces_IHwi_getFunc_FxnT ti_sysbios_interfaces_IHwi_getFunc_fxnP( ti_sysbios_interfaces_IHwi_Handle __inst )
{
    return (ti_sysbios_interfaces_IHwi_getFunc_FxnT)__inst->__fxns->getFunc;
}

/* setFunc_{FxnT,fxnP} */
typedef xdc_Void (*ti_sysbios_interfaces_IHwi_setFunc_FxnT)(xdc_Void *, ti_sysbios_interfaces_IHwi_FuncPtr, xdc_UArg);
static inline ti_sysbios_interfaces_IHwi_setFunc_FxnT ti_sysbios_interfaces_IHwi_setFunc_fxnP( ti_sysbios_interfaces_IHwi_Handle __inst )
{
    return (ti_sysbios_interfaces_IHwi_setFunc_FxnT)__inst->__fxns->setFunc;
}

/* getHookContext_{FxnT,fxnP} */
typedef xdc_Ptr (*ti_sysbios_interfaces_IHwi_getHookContext_FxnT)(xdc_Void *, xdc_Int);
static inline ti_sysbios_interfaces_IHwi_getHookContext_FxnT ti_sysbios_interfaces_IHwi_getHookContext_fxnP( ti_sysbios_interfaces_IHwi_Handle __inst )
{
    return (ti_sysbios_interfaces_IHwi_getHookContext_FxnT)__inst->__fxns->getHookContext;
}

/* setHookContext_{FxnT,fxnP} */
typedef xdc_Void (*ti_sysbios_interfaces_IHwi_setHookContext_FxnT)(xdc_Void *, xdc_Int, xdc_Ptr);
static inline ti_sysbios_interfaces_IHwi_setHookContext_FxnT ti_sysbios_interfaces_IHwi_setHookContext_fxnP( ti_sysbios_interfaces_IHwi_Handle __inst )
{
    return (ti_sysbios_interfaces_IHwi_setHookContext_FxnT)__inst->__fxns->setHookContext;
}

/* getIrp_{FxnT,fxnP} */
typedef ti_sysbios_interfaces_IHwi_Irp (*ti_sysbios_interfaces_IHwi_getIrp_FxnT)(xdc_Void *);
static inline ti_sysbios_interfaces_IHwi_getIrp_FxnT ti_sysbios_interfaces_IHwi_getIrp_fxnP( ti_sysbios_interfaces_IHwi_Handle __inst )
{
    return (ti_sysbios_interfaces_IHwi_getIrp_FxnT)__inst->__fxns->getIrp;
}


/*
 * ======== EPILOGUE ========
 */

#ifdef ti_sysbios_interfaces_IHwi__top__
#undef __nested__
#endif

#endif /* ti_sysbios_interfaces_IHwi__include */


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(ti_sysbios_interfaces_IHwi__nolocalnames)

#ifndef ti_sysbios_interfaces_IHwi__localnames__done
#define ti_sysbios_interfaces_IHwi__localnames__done

/* module prefix */
#define IHwi_Instance ti_sysbios_interfaces_IHwi_Instance
#define IHwi_Handle ti_sysbios_interfaces_IHwi_Handle
#define IHwi_Module ti_sysbios_interfaces_IHwi_Module
#define IHwi_FuncPtr ti_sysbios_interfaces_IHwi_FuncPtr
#define IHwi_Irp ti_sysbios_interfaces_IHwi_Irp
#define IHwi_HookSet ti_sysbios_interfaces_IHwi_HookSet
#define IHwi_MaskingOption ti_sysbios_interfaces_IHwi_MaskingOption
#define IHwi_StackInfo ti_sysbios_interfaces_IHwi_StackInfo
#define IHwi_MaskingOption_NONE ti_sysbios_interfaces_IHwi_MaskingOption_NONE
#define IHwi_MaskingOption_ALL ti_sysbios_interfaces_IHwi_MaskingOption_ALL
#define IHwi_MaskingOption_SELF ti_sysbios_interfaces_IHwi_MaskingOption_SELF
#define IHwi_MaskingOption_BITMASK ti_sysbios_interfaces_IHwi_MaskingOption_BITMASK
#define IHwi_MaskingOption_LOWER ti_sysbios_interfaces_IHwi_MaskingOption_LOWER
#define IHwi_Params ti_sysbios_interfaces_IHwi_Params
#define IHwi_getStackInfo ti_sysbios_interfaces_IHwi_getStackInfo
#define IHwi_getStackInfo_fxnP ti_sysbios_interfaces_IHwi_getStackInfo_fxnP
#define IHwi_getStackInfo_FxnT ti_sysbios_interfaces_IHwi_getStackInfo_FxnT
#define IHwi_getCoreStackInfo ti_sysbios_interfaces_IHwi_getCoreStackInfo
#define IHwi_getCoreStackInfo_fxnP ti_sysbios_interfaces_IHwi_getCoreStackInfo_fxnP
#define IHwi_getCoreStackInfo_FxnT ti_sysbios_interfaces_IHwi_getCoreStackInfo_FxnT
#define IHwi_startup ti_sysbios_interfaces_IHwi_startup
#define IHwi_startup_fxnP ti_sysbios_interfaces_IHwi_startup_fxnP
#define IHwi_startup_FxnT ti_sysbios_interfaces_IHwi_startup_FxnT
#define IHwi_disable ti_sysbios_interfaces_IHwi_disable
#define IHwi_disable_fxnP ti_sysbios_interfaces_IHwi_disable_fxnP
#define IHwi_disable_FxnT ti_sysbios_interfaces_IHwi_disable_FxnT
#define IHwi_enable ti_sysbios_interfaces_IHwi_enable
#define IHwi_enable_fxnP ti_sysbios_interfaces_IHwi_enable_fxnP
#define IHwi_enable_FxnT ti_sysbios_interfaces_IHwi_enable_FxnT
#define IHwi_restore ti_sysbios_interfaces_IHwi_restore
#define IHwi_restore_fxnP ti_sysbios_interfaces_IHwi_restore_fxnP
#define IHwi_restore_FxnT ti_sysbios_interfaces_IHwi_restore_FxnT
#define IHwi_switchFromBootStack ti_sysbios_interfaces_IHwi_switchFromBootStack
#define IHwi_switchFromBootStack_fxnP ti_sysbios_interfaces_IHwi_switchFromBootStack_fxnP
#define IHwi_switchFromBootStack_FxnT ti_sysbios_interfaces_IHwi_switchFromBootStack_FxnT
#define IHwi_post ti_sysbios_interfaces_IHwi_post
#define IHwi_post_fxnP ti_sysbios_interfaces_IHwi_post_fxnP
#define IHwi_post_FxnT ti_sysbios_interfaces_IHwi_post_FxnT
#define IHwi_getTaskSP ti_sysbios_interfaces_IHwi_getTaskSP
#define IHwi_getTaskSP_fxnP ti_sysbios_interfaces_IHwi_getTaskSP_fxnP
#define IHwi_getTaskSP_FxnT ti_sysbios_interfaces_IHwi_getTaskSP_FxnT
#define IHwi_disableInterrupt ti_sysbios_interfaces_IHwi_disableInterrupt
#define IHwi_disableInterrupt_fxnP ti_sysbios_interfaces_IHwi_disableInterrupt_fxnP
#define IHwi_disableInterrupt_FxnT ti_sysbios_interfaces_IHwi_disableInterrupt_FxnT
#define IHwi_enableInterrupt ti_sysbios_interfaces_IHwi_enableInterrupt
#define IHwi_enableInterrupt_fxnP ti_sysbios_interfaces_IHwi_enableInterrupt_fxnP
#define IHwi_enableInterrupt_FxnT ti_sysbios_interfaces_IHwi_enableInterrupt_FxnT
#define IHwi_restoreInterrupt ti_sysbios_interfaces_IHwi_restoreInterrupt
#define IHwi_restoreInterrupt_fxnP ti_sysbios_interfaces_IHwi_restoreInterrupt_fxnP
#define IHwi_restoreInterrupt_FxnT ti_sysbios_interfaces_IHwi_restoreInterrupt_FxnT
#define IHwi_clearInterrupt ti_sysbios_interfaces_IHwi_clearInterrupt
#define IHwi_clearInterrupt_fxnP ti_sysbios_interfaces_IHwi_clearInterrupt_fxnP
#define IHwi_clearInterrupt_FxnT ti_sysbios_interfaces_IHwi_clearInterrupt_FxnT
#define IHwi_getFunc ti_sysbios_interfaces_IHwi_getFunc
#define IHwi_getFunc_fxnP ti_sysbios_interfaces_IHwi_getFunc_fxnP
#define IHwi_getFunc_FxnT ti_sysbios_interfaces_IHwi_getFunc_FxnT
#define IHwi_setFunc ti_sysbios_interfaces_IHwi_setFunc
#define IHwi_setFunc_fxnP ti_sysbios_interfaces_IHwi_setFunc_fxnP
#define IHwi_setFunc_FxnT ti_sysbios_interfaces_IHwi_setFunc_FxnT
#define IHwi_getHookContext ti_sysbios_interfaces_IHwi_getHookContext
#define IHwi_getHookContext_fxnP ti_sysbios_interfaces_IHwi_getHookContext_fxnP
#define IHwi_getHookContext_FxnT ti_sysbios_interfaces_IHwi_getHookContext_FxnT
#define IHwi_setHookContext ti_sysbios_interfaces_IHwi_setHookContext
#define IHwi_setHookContext_fxnP ti_sysbios_interfaces_IHwi_setHookContext_fxnP
#define IHwi_setHookContext_FxnT ti_sysbios_interfaces_IHwi_setHookContext_FxnT
#define IHwi_getIrp ti_sysbios_interfaces_IHwi_getIrp
#define IHwi_getIrp_fxnP ti_sysbios_interfaces_IHwi_getIrp_fxnP
#define IHwi_getIrp_FxnT ti_sysbios_interfaces_IHwi_getIrp_FxnT
#define IHwi_Module_name ti_sysbios_interfaces_IHwi_Module_name
#define IHwi_create ti_sysbios_interfaces_IHwi_create
#define IHwi_delete ti_sysbios_interfaces_IHwi_delete
#define IHwi_Handle_label ti_sysbios_interfaces_IHwi_Handle_label
#define IHwi_Handle_to_Module ti_sysbios_interfaces_IHwi_Handle_to_Module

#endif /* ti_sysbios_interfaces_IHwi__localnames__done */
#endif
