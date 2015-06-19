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
 *     INTERNAL DEFINITIONS
 *     MODULE-WIDE CONFIGS
 *     PER-INSTANCE TYPES
 *     VIRTUAL FUNCTIONS
 *     FUNCTION DECLARATIONS
 *     CONVERTORS
 *     SYSTEM FUNCTIONS
 *     
 *     EPILOGUE
 *     STATE STRUCTURES
 *     PREFIX ALIASES
 */


/*
 * ======== PROLOGUE ========
 */

#ifndef ti_sysbios_hal_Hwi__include
#define ti_sysbios_hal_Hwi__include

#ifndef __nested__
#define __nested__
#define ti_sysbios_hal_Hwi__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define ti_sysbios_hal_Hwi___VERS 160


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/IInstance.h>
#include <ti/sysbios/hal/Hwi__prologue.h>
#include <ti/sysbios/hal/package/package.defs.h>

#include <xdc/runtime/Error.h>
#include <ti/sysbios/interfaces/IHwi.h>
#include <ti/sysbios/hal/package/Hwi_HwiProxy.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */

/* FuncPtr */
typedef ti_sysbios_interfaces_IHwi_FuncPtr ti_sysbios_hal_Hwi_FuncPtr;

/* Irp */
typedef ti_sysbios_interfaces_IHwi_Irp ti_sysbios_hal_Hwi_Irp;

/* HookSet */
typedef ti_sysbios_interfaces_IHwi_HookSet ti_sysbios_hal_Hwi_HookSet;

/* MaskingOption */
typedef ti_sysbios_interfaces_IHwi_MaskingOption ti_sysbios_hal_Hwi_MaskingOption;

/* StackInfo */
typedef ti_sysbios_interfaces_IHwi_StackInfo ti_sysbios_hal_Hwi_StackInfo;

/* MaskingOption_NONE */
#define ti_sysbios_hal_Hwi_MaskingOption_NONE ti_sysbios_interfaces_IHwi_MaskingOption_NONE

/* MaskingOption_ALL */
#define ti_sysbios_hal_Hwi_MaskingOption_ALL ti_sysbios_interfaces_IHwi_MaskingOption_ALL

/* MaskingOption_SELF */
#define ti_sysbios_hal_Hwi_MaskingOption_SELF ti_sysbios_interfaces_IHwi_MaskingOption_SELF

/* MaskingOption_BITMASK */
#define ti_sysbios_hal_Hwi_MaskingOption_BITMASK ti_sysbios_interfaces_IHwi_MaskingOption_BITMASK

/* MaskingOption_LOWER */
#define ti_sysbios_hal_Hwi_MaskingOption_LOWER ti_sysbios_interfaces_IHwi_MaskingOption_LOWER


/*
 * ======== CREATE ARGS ========
 */

/* Args__create */
typedef struct ti_sysbios_hal_Hwi_Args__create {
    xdc_Int intNum;
    ti_sysbios_hal_Hwi_FuncPtr hwiFxn;
} ti_sysbios_hal_Hwi_Args__create;


/*
 * ======== INTERNAL DEFINITIONS ========
 */


/*
 * ======== MODULE-WIDE CONFIGS ========
 */

/* Module__diagsEnabled */
typedef xdc_Bits32 CT__ti_sysbios_hal_Hwi_Module__diagsEnabled;
__extern __FAR__ const CT__ti_sysbios_hal_Hwi_Module__diagsEnabled ti_sysbios_hal_Hwi_Module__diagsEnabled__C;

/* Module__diagsIncluded */
typedef xdc_Bits32 CT__ti_sysbios_hal_Hwi_Module__diagsIncluded;
__extern __FAR__ const CT__ti_sysbios_hal_Hwi_Module__diagsIncluded ti_sysbios_hal_Hwi_Module__diagsIncluded__C;

/* Module__diagsMask */
typedef xdc_Bits16 *CT__ti_sysbios_hal_Hwi_Module__diagsMask;
__extern __FAR__ const CT__ti_sysbios_hal_Hwi_Module__diagsMask ti_sysbios_hal_Hwi_Module__diagsMask__C;

/* Module__gateObj */
typedef xdc_Ptr CT__ti_sysbios_hal_Hwi_Module__gateObj;
__extern __FAR__ const CT__ti_sysbios_hal_Hwi_Module__gateObj ti_sysbios_hal_Hwi_Module__gateObj__C;

/* Module__gatePrms */
typedef xdc_Ptr CT__ti_sysbios_hal_Hwi_Module__gatePrms;
__extern __FAR__ const CT__ti_sysbios_hal_Hwi_Module__gatePrms ti_sysbios_hal_Hwi_Module__gatePrms__C;

/* Module__id */
typedef xdc_runtime_Types_ModuleId CT__ti_sysbios_hal_Hwi_Module__id;
__extern __FAR__ const CT__ti_sysbios_hal_Hwi_Module__id ti_sysbios_hal_Hwi_Module__id__C;

/* Module__loggerDefined */
typedef xdc_Bool CT__ti_sysbios_hal_Hwi_Module__loggerDefined;
__extern __FAR__ const CT__ti_sysbios_hal_Hwi_Module__loggerDefined ti_sysbios_hal_Hwi_Module__loggerDefined__C;

/* Module__loggerObj */
typedef xdc_Ptr CT__ti_sysbios_hal_Hwi_Module__loggerObj;
__extern __FAR__ const CT__ti_sysbios_hal_Hwi_Module__loggerObj ti_sysbios_hal_Hwi_Module__loggerObj__C;

/* Module__loggerFxn0 */
typedef xdc_runtime_Types_LoggerFxn0 CT__ti_sysbios_hal_Hwi_Module__loggerFxn0;
__extern __FAR__ const CT__ti_sysbios_hal_Hwi_Module__loggerFxn0 ti_sysbios_hal_Hwi_Module__loggerFxn0__C;

/* Module__loggerFxn1 */
typedef xdc_runtime_Types_LoggerFxn1 CT__ti_sysbios_hal_Hwi_Module__loggerFxn1;
__extern __FAR__ const CT__ti_sysbios_hal_Hwi_Module__loggerFxn1 ti_sysbios_hal_Hwi_Module__loggerFxn1__C;

/* Module__loggerFxn2 */
typedef xdc_runtime_Types_LoggerFxn2 CT__ti_sysbios_hal_Hwi_Module__loggerFxn2;
__extern __FAR__ const CT__ti_sysbios_hal_Hwi_Module__loggerFxn2 ti_sysbios_hal_Hwi_Module__loggerFxn2__C;

/* Module__loggerFxn4 */
typedef xdc_runtime_Types_LoggerFxn4 CT__ti_sysbios_hal_Hwi_Module__loggerFxn4;
__extern __FAR__ const CT__ti_sysbios_hal_Hwi_Module__loggerFxn4 ti_sysbios_hal_Hwi_Module__loggerFxn4__C;

/* Module__loggerFxn8 */
typedef xdc_runtime_Types_LoggerFxn8 CT__ti_sysbios_hal_Hwi_Module__loggerFxn8;
__extern __FAR__ const CT__ti_sysbios_hal_Hwi_Module__loggerFxn8 ti_sysbios_hal_Hwi_Module__loggerFxn8__C;

/* Module__startupDoneFxn */
typedef xdc_Bool (*CT__ti_sysbios_hal_Hwi_Module__startupDoneFxn)(void);
__extern __FAR__ const CT__ti_sysbios_hal_Hwi_Module__startupDoneFxn ti_sysbios_hal_Hwi_Module__startupDoneFxn__C;

/* Object__count */
typedef xdc_Int CT__ti_sysbios_hal_Hwi_Object__count;
__extern __FAR__ const CT__ti_sysbios_hal_Hwi_Object__count ti_sysbios_hal_Hwi_Object__count__C;

/* Object__heap */
typedef xdc_runtime_IHeap_Handle CT__ti_sysbios_hal_Hwi_Object__heap;
__extern __FAR__ const CT__ti_sysbios_hal_Hwi_Object__heap ti_sysbios_hal_Hwi_Object__heap__C;

/* Object__sizeof */
typedef xdc_SizeT CT__ti_sysbios_hal_Hwi_Object__sizeof;
__extern __FAR__ const CT__ti_sysbios_hal_Hwi_Object__sizeof ti_sysbios_hal_Hwi_Object__sizeof__C;

/* Object__table */
typedef xdc_Ptr CT__ti_sysbios_hal_Hwi_Object__table;
__extern __FAR__ const CT__ti_sysbios_hal_Hwi_Object__table ti_sysbios_hal_Hwi_Object__table__C;

/* dispatcherAutoNestingSupport */
#ifdef ti_sysbios_hal_Hwi_dispatcherAutoNestingSupport__D
#define ti_sysbios_hal_Hwi_dispatcherAutoNestingSupport (ti_sysbios_hal_Hwi_dispatcherAutoNestingSupport__D)
#else
#define ti_sysbios_hal_Hwi_dispatcherAutoNestingSupport (ti_sysbios_hal_Hwi_dispatcherAutoNestingSupport__C)
typedef xdc_Bool CT__ti_sysbios_hal_Hwi_dispatcherAutoNestingSupport;
__extern __FAR__ const CT__ti_sysbios_hal_Hwi_dispatcherAutoNestingSupport ti_sysbios_hal_Hwi_dispatcherAutoNestingSupport__C;
#endif

/* dispatcherSwiSupport */
#ifdef ti_sysbios_hal_Hwi_dispatcherSwiSupport__D
#define ti_sysbios_hal_Hwi_dispatcherSwiSupport (ti_sysbios_hal_Hwi_dispatcherSwiSupport__D)
#else
#define ti_sysbios_hal_Hwi_dispatcherSwiSupport (ti_sysbios_hal_Hwi_dispatcherSwiSupport__C)
typedef xdc_Bool CT__ti_sysbios_hal_Hwi_dispatcherSwiSupport;
__extern __FAR__ const CT__ti_sysbios_hal_Hwi_dispatcherSwiSupport ti_sysbios_hal_Hwi_dispatcherSwiSupport__C;
#endif

/* dispatcherTaskSupport */
#ifdef ti_sysbios_hal_Hwi_dispatcherTaskSupport__D
#define ti_sysbios_hal_Hwi_dispatcherTaskSupport (ti_sysbios_hal_Hwi_dispatcherTaskSupport__D)
#else
#define ti_sysbios_hal_Hwi_dispatcherTaskSupport (ti_sysbios_hal_Hwi_dispatcherTaskSupport__C)
typedef xdc_Bool CT__ti_sysbios_hal_Hwi_dispatcherTaskSupport;
__extern __FAR__ const CT__ti_sysbios_hal_Hwi_dispatcherTaskSupport ti_sysbios_hal_Hwi_dispatcherTaskSupport__C;
#endif

/* dispatcherIrpTrackingSupport */
#ifdef ti_sysbios_hal_Hwi_dispatcherIrpTrackingSupport__D
#define ti_sysbios_hal_Hwi_dispatcherIrpTrackingSupport (ti_sysbios_hal_Hwi_dispatcherIrpTrackingSupport__D)
#else
#define ti_sysbios_hal_Hwi_dispatcherIrpTrackingSupport (ti_sysbios_hal_Hwi_dispatcherIrpTrackingSupport__C)
typedef xdc_Bool CT__ti_sysbios_hal_Hwi_dispatcherIrpTrackingSupport;
__extern __FAR__ const CT__ti_sysbios_hal_Hwi_dispatcherIrpTrackingSupport ti_sysbios_hal_Hwi_dispatcherIrpTrackingSupport__C;
#endif

/* E_stackOverflow */
#define ti_sysbios_hal_Hwi_E_stackOverflow (ti_sysbios_hal_Hwi_E_stackOverflow__C)
typedef xdc_runtime_Error_Id CT__ti_sysbios_hal_Hwi_E_stackOverflow;
__extern __FAR__ const CT__ti_sysbios_hal_Hwi_E_stackOverflow ti_sysbios_hal_Hwi_E_stackOverflow__C;


/*
 * ======== PER-INSTANCE TYPES ========
 */

/* Params */
struct ti_sysbios_hal_Hwi_Params {
    size_t __size;
    const void *__self;
    void *__fxns;
    xdc_runtime_IInstance_Params *instance;
    ti_sysbios_interfaces_IHwi_MaskingOption maskSetting;
    xdc_UArg arg;
    xdc_Bool enableInt;
    xdc_Int eventId;
    xdc_Int priority;
    xdc_runtime_IInstance_Params __iprms;
};

/* Struct */
struct ti_sysbios_hal_Hwi_Struct {
    const ti_sysbios_hal_Hwi_Fxns__ *__fxns;
    ti_sysbios_hal_Hwi_HwiProxy_Handle __f0;
    xdc_runtime_Types_CordAddr __name;
};


/*
 * ======== VIRTUAL FUNCTIONS ========
 */

/* Fxns__ */
struct ti_sysbios_hal_Hwi_Fxns__ {
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
    ti_sysbios_interfaces_IHwi_FuncPtr (*getFunc)(ti_sysbios_hal_Hwi_Handle, xdc_UArg*);
    xdc_Void (*setFunc)(ti_sysbios_hal_Hwi_Handle, ti_sysbios_interfaces_IHwi_FuncPtr, xdc_UArg);
    xdc_Ptr (*getHookContext)(ti_sysbios_hal_Hwi_Handle, xdc_Int);
    xdc_Void (*setHookContext)(ti_sysbios_hal_Hwi_Handle, xdc_Int, xdc_Ptr);
    ti_sysbios_interfaces_IHwi_Irp (*getIrp)(ti_sysbios_hal_Hwi_Handle);
    xdc_runtime_Types_SysFxns2 __sfxns;
};

/* Module__FXNS__C */
__extern const ti_sysbios_hal_Hwi_Fxns__ ti_sysbios_hal_Hwi_Module__FXNS__C;


/*
 * ======== FUNCTION DECLARATIONS ========
 */

/* Module_startup */
#define ti_sysbios_hal_Hwi_Module_startup ti_sysbios_hal_Hwi_Module_startup__E
xdc__CODESECT(ti_sysbios_hal_Hwi_Module_startup__E, "ti_sysbios_hal_Hwi_Module_startup")
__extern xdc_Int ti_sysbios_hal_Hwi_Module_startup__E( xdc_Int state );
xdc__CODESECT(ti_sysbios_hal_Hwi_Module_startup__F, "ti_sysbios_hal_Hwi_Module_startup")
__extern xdc_Int ti_sysbios_hal_Hwi_Module_startup__F( xdc_Int state );

/* Instance_init__E */
xdc__CODESECT(ti_sysbios_hal_Hwi_Instance_init__E, "ti_sysbios_hal_Hwi_Instance_init")
__extern xdc_Int ti_sysbios_hal_Hwi_Instance_init__E(ti_sysbios_hal_Hwi_Object *, xdc_Int intNum, ti_sysbios_hal_Hwi_FuncPtr hwiFxn, const ti_sysbios_hal_Hwi_Params *, xdc_runtime_Error_Block *);

/* Instance_finalize__E */
xdc__CODESECT(ti_sysbios_hal_Hwi_Instance_finalize__E, "ti_sysbios_hal_Hwi_Instance_finalize")
__extern void ti_sysbios_hal_Hwi_Instance_finalize__E( ti_sysbios_hal_Hwi_Object* , int );

/* Handle__label__S */
xdc__CODESECT(ti_sysbios_hal_Hwi_Handle__label__S, "ti_sysbios_hal_Hwi_Handle__label__S")
__extern xdc_runtime_Types_Label *ti_sysbios_hal_Hwi_Handle__label__S( xdc_Ptr obj, xdc_runtime_Types_Label *lab );

/* Module__startupDone__S */
xdc__CODESECT(ti_sysbios_hal_Hwi_Module__startupDone__S, "ti_sysbios_hal_Hwi_Module__startupDone__S")
__extern xdc_Bool ti_sysbios_hal_Hwi_Module__startupDone__S( void );

/* Object__create__S */
xdc__CODESECT(ti_sysbios_hal_Hwi_Object__create__S, "ti_sysbios_hal_Hwi_Object__create__S")
__extern xdc_Ptr ti_sysbios_hal_Hwi_Object__create__S( xdc_Ptr __oa, xdc_SizeT __osz, xdc_Ptr __aa, const xdc_UChar *__pa, xdc_SizeT __psz, xdc_runtime_Error_Block *__eb );

/* create */
xdc__CODESECT(ti_sysbios_hal_Hwi_create, "ti_sysbios_hal_Hwi_create")
__extern ti_sysbios_hal_Hwi_Handle ti_sysbios_hal_Hwi_create( xdc_Int intNum, ti_sysbios_hal_Hwi_FuncPtr hwiFxn, const ti_sysbios_hal_Hwi_Params *__prms, xdc_runtime_Error_Block *__eb );

/* construct */
xdc__CODESECT(ti_sysbios_hal_Hwi_construct, "ti_sysbios_hal_Hwi_construct")
__extern void ti_sysbios_hal_Hwi_construct( ti_sysbios_hal_Hwi_Struct *__obj, xdc_Int intNum, ti_sysbios_hal_Hwi_FuncPtr hwiFxn, const ti_sysbios_hal_Hwi_Params *__prms, xdc_runtime_Error_Block *__eb );

/* Object__delete__S */
xdc__CODESECT(ti_sysbios_hal_Hwi_Object__delete__S, "ti_sysbios_hal_Hwi_Object__delete__S")
__extern xdc_Void ti_sysbios_hal_Hwi_Object__delete__S( xdc_Ptr instp );

/* delete */
xdc__CODESECT(ti_sysbios_hal_Hwi_delete, "ti_sysbios_hal_Hwi_delete")
__extern void ti_sysbios_hal_Hwi_delete(ti_sysbios_hal_Hwi_Handle *instp);

/* Object__destruct__S */
xdc__CODESECT(ti_sysbios_hal_Hwi_Object__destruct__S, "ti_sysbios_hal_Hwi_Object__destruct__S")
__extern xdc_Void ti_sysbios_hal_Hwi_Object__destruct__S( xdc_Ptr objp );

/* destruct */
xdc__CODESECT(ti_sysbios_hal_Hwi_destruct, "ti_sysbios_hal_Hwi_destruct")
__extern void ti_sysbios_hal_Hwi_destruct(ti_sysbios_hal_Hwi_Struct *obj);

/* Object__get__S */
xdc__CODESECT(ti_sysbios_hal_Hwi_Object__get__S, "ti_sysbios_hal_Hwi_Object__get__S")
__extern xdc_Ptr ti_sysbios_hal_Hwi_Object__get__S( xdc_Ptr oarr, xdc_Int i );

/* Object__first__S */
xdc__CODESECT(ti_sysbios_hal_Hwi_Object__first__S, "ti_sysbios_hal_Hwi_Object__first__S")
__extern xdc_Ptr ti_sysbios_hal_Hwi_Object__first__S( void );

/* Object__next__S */
xdc__CODESECT(ti_sysbios_hal_Hwi_Object__next__S, "ti_sysbios_hal_Hwi_Object__next__S")
__extern xdc_Ptr ti_sysbios_hal_Hwi_Object__next__S( xdc_Ptr obj );

/* Params__init__S */
xdc__CODESECT(ti_sysbios_hal_Hwi_Params__init__S, "ti_sysbios_hal_Hwi_Params__init__S")
__extern xdc_Void ti_sysbios_hal_Hwi_Params__init__S( xdc_Ptr dst, const xdc_Void *src, xdc_SizeT psz, xdc_SizeT isz );

/* getStackInfo__E */
#define ti_sysbios_hal_Hwi_getStackInfo ti_sysbios_hal_Hwi_getStackInfo__E
xdc__CODESECT(ti_sysbios_hal_Hwi_getStackInfo__E, "ti_sysbios_hal_Hwi_getStackInfo")
__extern xdc_Bool ti_sysbios_hal_Hwi_getStackInfo__E( ti_sysbios_interfaces_IHwi_StackInfo *stkInfo, xdc_Bool computeStackDepth );

/* getCoreStackInfo__E */
#define ti_sysbios_hal_Hwi_getCoreStackInfo ti_sysbios_hal_Hwi_getCoreStackInfo__E
xdc__CODESECT(ti_sysbios_hal_Hwi_getCoreStackInfo__E, "ti_sysbios_hal_Hwi_getCoreStackInfo")
__extern xdc_Bool ti_sysbios_hal_Hwi_getCoreStackInfo__E( ti_sysbios_interfaces_IHwi_StackInfo *stkInfo, xdc_Bool computeStackDepth, xdc_UInt coreId );

/* startup__E */
#define ti_sysbios_hal_Hwi_startup ti_sysbios_hal_Hwi_startup__E
xdc__CODESECT(ti_sysbios_hal_Hwi_startup__E, "ti_sysbios_hal_Hwi_startup")
__extern xdc_Void ti_sysbios_hal_Hwi_startup__E( void );

/* switchFromBootStack__E */
#define ti_sysbios_hal_Hwi_switchFromBootStack ti_sysbios_hal_Hwi_switchFromBootStack__E
xdc__CODESECT(ti_sysbios_hal_Hwi_switchFromBootStack__E, "ti_sysbios_hal_Hwi_switchFromBootStack")
__extern xdc_Void ti_sysbios_hal_Hwi_switchFromBootStack__E( void );

/* post__E */
#define ti_sysbios_hal_Hwi_post ti_sysbios_hal_Hwi_post__E
xdc__CODESECT(ti_sysbios_hal_Hwi_post__E, "ti_sysbios_hal_Hwi_post")
__extern xdc_Void ti_sysbios_hal_Hwi_post__E( xdc_UInt intNum );

/* getTaskSP__E */
#define ti_sysbios_hal_Hwi_getTaskSP ti_sysbios_hal_Hwi_getTaskSP__E
xdc__CODESECT(ti_sysbios_hal_Hwi_getTaskSP__E, "ti_sysbios_hal_Hwi_getTaskSP")
__extern xdc_Char *ti_sysbios_hal_Hwi_getTaskSP__E( void );

/* disableInterrupt__E */
#define ti_sysbios_hal_Hwi_disableInterrupt ti_sysbios_hal_Hwi_disableInterrupt__E
xdc__CODESECT(ti_sysbios_hal_Hwi_disableInterrupt__E, "ti_sysbios_hal_Hwi_disableInterrupt")
__extern xdc_UInt ti_sysbios_hal_Hwi_disableInterrupt__E( xdc_UInt intNum );

/* enableInterrupt__E */
#define ti_sysbios_hal_Hwi_enableInterrupt ti_sysbios_hal_Hwi_enableInterrupt__E
xdc__CODESECT(ti_sysbios_hal_Hwi_enableInterrupt__E, "ti_sysbios_hal_Hwi_enableInterrupt")
__extern xdc_UInt ti_sysbios_hal_Hwi_enableInterrupt__E( xdc_UInt intNum );

/* restoreInterrupt__E */
#define ti_sysbios_hal_Hwi_restoreInterrupt ti_sysbios_hal_Hwi_restoreInterrupt__E
xdc__CODESECT(ti_sysbios_hal_Hwi_restoreInterrupt__E, "ti_sysbios_hal_Hwi_restoreInterrupt")
__extern xdc_Void ti_sysbios_hal_Hwi_restoreInterrupt__E( xdc_UInt intNum, xdc_UInt key );

/* clearInterrupt__E */
#define ti_sysbios_hal_Hwi_clearInterrupt ti_sysbios_hal_Hwi_clearInterrupt__E
xdc__CODESECT(ti_sysbios_hal_Hwi_clearInterrupt__E, "ti_sysbios_hal_Hwi_clearInterrupt")
__extern xdc_Void ti_sysbios_hal_Hwi_clearInterrupt__E( xdc_UInt intNum );

/* getFunc__E */
#define ti_sysbios_hal_Hwi_getFunc ti_sysbios_hal_Hwi_getFunc__E
xdc__CODESECT(ti_sysbios_hal_Hwi_getFunc__E, "ti_sysbios_hal_Hwi_getFunc")
__extern ti_sysbios_interfaces_IHwi_FuncPtr ti_sysbios_hal_Hwi_getFunc__E( ti_sysbios_hal_Hwi_Handle __inst, xdc_UArg *arg );

/* setFunc__E */
#define ti_sysbios_hal_Hwi_setFunc ti_sysbios_hal_Hwi_setFunc__E
xdc__CODESECT(ti_sysbios_hal_Hwi_setFunc__E, "ti_sysbios_hal_Hwi_setFunc")
__extern xdc_Void ti_sysbios_hal_Hwi_setFunc__E( ti_sysbios_hal_Hwi_Handle __inst, ti_sysbios_interfaces_IHwi_FuncPtr fxn, xdc_UArg arg );

/* getIrp__E */
#define ti_sysbios_hal_Hwi_getIrp ti_sysbios_hal_Hwi_getIrp__E
xdc__CODESECT(ti_sysbios_hal_Hwi_getIrp__E, "ti_sysbios_hal_Hwi_getIrp")
__extern ti_sysbios_interfaces_IHwi_Irp ti_sysbios_hal_Hwi_getIrp__E( ti_sysbios_hal_Hwi_Handle __inst );

/* getHookContext__E */
#define ti_sysbios_hal_Hwi_getHookContext ti_sysbios_hal_Hwi_getHookContext__E
xdc__CODESECT(ti_sysbios_hal_Hwi_getHookContext__E, "ti_sysbios_hal_Hwi_getHookContext")
__extern xdc_Ptr ti_sysbios_hal_Hwi_getHookContext__E( ti_sysbios_hal_Hwi_Handle __inst, xdc_Int id );

/* setHookContext__E */
#define ti_sysbios_hal_Hwi_setHookContext ti_sysbios_hal_Hwi_setHookContext__E
xdc__CODESECT(ti_sysbios_hal_Hwi_setHookContext__E, "ti_sysbios_hal_Hwi_setHookContext")
__extern xdc_Void ti_sysbios_hal_Hwi_setHookContext__E( ti_sysbios_hal_Hwi_Handle __inst, xdc_Int id, xdc_Ptr hookContext );


/*
 * ======== CONVERTORS ========
 */

/* Module_upCast */
static inline ti_sysbios_interfaces_IHwi_Module ti_sysbios_hal_Hwi_Module_upCast( void )
{
    return (ti_sysbios_interfaces_IHwi_Module)&ti_sysbios_hal_Hwi_Module__FXNS__C;
}

/* Module_to_ti_sysbios_interfaces_IHwi */
#define ti_sysbios_hal_Hwi_Module_to_ti_sysbios_interfaces_IHwi ti_sysbios_hal_Hwi_Module_upCast

/* Handle_upCast */
static inline ti_sysbios_interfaces_IHwi_Handle ti_sysbios_hal_Hwi_Handle_upCast( ti_sysbios_hal_Hwi_Handle i )
{
    return (ti_sysbios_interfaces_IHwi_Handle)i;
}

/* Handle_to_ti_sysbios_interfaces_IHwi */
#define ti_sysbios_hal_Hwi_Handle_to_ti_sysbios_interfaces_IHwi ti_sysbios_hal_Hwi_Handle_upCast

/* Handle_downCast */
static inline ti_sysbios_hal_Hwi_Handle ti_sysbios_hal_Hwi_Handle_downCast( ti_sysbios_interfaces_IHwi_Handle i )
{
    ti_sysbios_interfaces_IHwi_Handle i2 = (ti_sysbios_interfaces_IHwi_Handle)i;
    return (void*)i2->__fxns == (void*)&ti_sysbios_hal_Hwi_Module__FXNS__C ? (ti_sysbios_hal_Hwi_Handle)i : 0;
}

/* Handle_from_ti_sysbios_interfaces_IHwi */
#define ti_sysbios_hal_Hwi_Handle_from_ti_sysbios_interfaces_IHwi ti_sysbios_hal_Hwi_Handle_downCast


/*
 * ======== SYSTEM FUNCTIONS ========
 */

/* Module_startupDone */
#define ti_sysbios_hal_Hwi_Module_startupDone() ti_sysbios_hal_Hwi_Module__startupDone__S()

/* Object_heap */
#define ti_sysbios_hal_Hwi_Object_heap() ti_sysbios_hal_Hwi_Object__heap__C

/* Module_heap */
#define ti_sysbios_hal_Hwi_Module_heap() ti_sysbios_hal_Hwi_Object__heap__C

/* Module_id */
static inline CT__ti_sysbios_hal_Hwi_Module__id ti_sysbios_hal_Hwi_Module_id( void ) 
{
    return ti_sysbios_hal_Hwi_Module__id__C;
}

/* Module_hasMask */
static inline xdc_Bool ti_sysbios_hal_Hwi_Module_hasMask( void ) 
{
    return ti_sysbios_hal_Hwi_Module__diagsMask__C != NULL;
}

/* Module_getMask */
static inline xdc_Bits16 ti_sysbios_hal_Hwi_Module_getMask( void ) 
{
    return ti_sysbios_hal_Hwi_Module__diagsMask__C != NULL ? *ti_sysbios_hal_Hwi_Module__diagsMask__C : 0;
}

/* Module_setMask */
static inline xdc_Void ti_sysbios_hal_Hwi_Module_setMask( xdc_Bits16 mask ) 
{
    if (ti_sysbios_hal_Hwi_Module__diagsMask__C != NULL) *ti_sysbios_hal_Hwi_Module__diagsMask__C = mask;
}

/* Params_init */
static inline void ti_sysbios_hal_Hwi_Params_init( ti_sysbios_hal_Hwi_Params *prms ) 
{
    if (prms) {
        ti_sysbios_hal_Hwi_Params__init__S(prms, 0, sizeof(ti_sysbios_hal_Hwi_Params), sizeof(xdc_runtime_IInstance_Params));
    }
}

/* Params_copy */
static inline void ti_sysbios_hal_Hwi_Params_copy(ti_sysbios_hal_Hwi_Params *dst, const ti_sysbios_hal_Hwi_Params *src) 
{
    if (dst) {
        ti_sysbios_hal_Hwi_Params__init__S(dst, (const void *)src, sizeof(ti_sysbios_hal_Hwi_Params), sizeof(xdc_runtime_IInstance_Params));
    }
}

/* Object_count */
#define ti_sysbios_hal_Hwi_Object_count() ti_sysbios_hal_Hwi_Object__count__C

/* Object_sizeof */
#define ti_sysbios_hal_Hwi_Object_sizeof() ti_sysbios_hal_Hwi_Object__sizeof__C

/* Object_get */
static inline ti_sysbios_hal_Hwi_Handle ti_sysbios_hal_Hwi_Object_get(ti_sysbios_hal_Hwi_Instance_State *oarr, int i) 
{
    return (ti_sysbios_hal_Hwi_Handle)ti_sysbios_hal_Hwi_Object__get__S(oarr, i);
}

/* Object_first */
static inline ti_sysbios_hal_Hwi_Handle ti_sysbios_hal_Hwi_Object_first( void )
{
    return (ti_sysbios_hal_Hwi_Handle)ti_sysbios_hal_Hwi_Object__first__S();
}

/* Object_next */
static inline ti_sysbios_hal_Hwi_Handle ti_sysbios_hal_Hwi_Object_next( ti_sysbios_hal_Hwi_Object *obj )
{
    return (ti_sysbios_hal_Hwi_Handle)ti_sysbios_hal_Hwi_Object__next__S(obj);
}

/* Handle_label */
static inline xdc_runtime_Types_Label *ti_sysbios_hal_Hwi_Handle_label( ti_sysbios_hal_Hwi_Handle inst, xdc_runtime_Types_Label *lab )
{
    return ti_sysbios_hal_Hwi_Handle__label__S(inst, lab);
}

/* Handle_name */
static inline xdc_String ti_sysbios_hal_Hwi_Handle_name( ti_sysbios_hal_Hwi_Handle inst )
{
    xdc_runtime_Types_Label lab;
    return ti_sysbios_hal_Hwi_Handle__label__S(inst, &lab)->iname;
}

/* handle */
static inline ti_sysbios_hal_Hwi_Handle ti_sysbios_hal_Hwi_handle( ti_sysbios_hal_Hwi_Struct *str )
{
    return (ti_sysbios_hal_Hwi_Handle)str;
}

/* struct */
static inline ti_sysbios_hal_Hwi_Struct *ti_sysbios_hal_Hwi_struct( ti_sysbios_hal_Hwi_Handle inst )
{
    return (ti_sysbios_hal_Hwi_Struct*)inst;
}


/*
 * ======== EPILOGUE ========
 */

#include <ti/sysbios/hal/Hwi__epilogue.h>

#ifdef ti_sysbios_hal_Hwi__top__
#undef __nested__
#endif

#endif /* ti_sysbios_hal_Hwi__include */


/*
 * ======== STATE STRUCTURES ========
 */

#if defined(__config__) || (!defined(__nested__) && defined(ti_sysbios_hal_Hwi__internalaccess))

#ifndef ti_sysbios_hal_Hwi__include_state
#define ti_sysbios_hal_Hwi__include_state

/* Object */
struct ti_sysbios_hal_Hwi_Object {
    const ti_sysbios_hal_Hwi_Fxns__ *__fxns;
    ti_sysbios_hal_Hwi_HwiProxy_Handle pi;
};

#endif /* ti_sysbios_hal_Hwi__include_state */

#endif


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(ti_sysbios_hal_Hwi__nolocalnames)

#ifndef ti_sysbios_hal_Hwi__localnames__done
#define ti_sysbios_hal_Hwi__localnames__done

/* module prefix */
#define Hwi_Instance ti_sysbios_hal_Hwi_Instance
#define Hwi_Handle ti_sysbios_hal_Hwi_Handle
#define Hwi_Module ti_sysbios_hal_Hwi_Module
#define Hwi_Object ti_sysbios_hal_Hwi_Object
#define Hwi_Struct ti_sysbios_hal_Hwi_Struct
#define Hwi_FuncPtr ti_sysbios_hal_Hwi_FuncPtr
#define Hwi_Irp ti_sysbios_hal_Hwi_Irp
#define Hwi_HookSet ti_sysbios_hal_Hwi_HookSet
#define Hwi_MaskingOption ti_sysbios_hal_Hwi_MaskingOption
#define Hwi_StackInfo ti_sysbios_hal_Hwi_StackInfo
#define Hwi_Instance_State ti_sysbios_hal_Hwi_Instance_State
#define Hwi_MaskingOption_NONE ti_sysbios_hal_Hwi_MaskingOption_NONE
#define Hwi_MaskingOption_ALL ti_sysbios_hal_Hwi_MaskingOption_ALL
#define Hwi_MaskingOption_SELF ti_sysbios_hal_Hwi_MaskingOption_SELF
#define Hwi_MaskingOption_BITMASK ti_sysbios_hal_Hwi_MaskingOption_BITMASK
#define Hwi_MaskingOption_LOWER ti_sysbios_hal_Hwi_MaskingOption_LOWER
#define Hwi_dispatcherAutoNestingSupport ti_sysbios_hal_Hwi_dispatcherAutoNestingSupport
#define Hwi_dispatcherSwiSupport ti_sysbios_hal_Hwi_dispatcherSwiSupport
#define Hwi_dispatcherTaskSupport ti_sysbios_hal_Hwi_dispatcherTaskSupport
#define Hwi_dispatcherIrpTrackingSupport ti_sysbios_hal_Hwi_dispatcherIrpTrackingSupport
#define Hwi_E_stackOverflow ti_sysbios_hal_Hwi_E_stackOverflow
#define Hwi_Params ti_sysbios_hal_Hwi_Params
#define Hwi_getStackInfo ti_sysbios_hal_Hwi_getStackInfo
#define Hwi_getCoreStackInfo ti_sysbios_hal_Hwi_getCoreStackInfo
#define Hwi_startup ti_sysbios_hal_Hwi_startup
#define Hwi_switchFromBootStack ti_sysbios_hal_Hwi_switchFromBootStack
#define Hwi_post ti_sysbios_hal_Hwi_post
#define Hwi_getTaskSP ti_sysbios_hal_Hwi_getTaskSP
#define Hwi_disableInterrupt ti_sysbios_hal_Hwi_disableInterrupt
#define Hwi_enableInterrupt ti_sysbios_hal_Hwi_enableInterrupt
#define Hwi_restoreInterrupt ti_sysbios_hal_Hwi_restoreInterrupt
#define Hwi_clearInterrupt ti_sysbios_hal_Hwi_clearInterrupt
#define Hwi_getFunc ti_sysbios_hal_Hwi_getFunc
#define Hwi_setFunc ti_sysbios_hal_Hwi_setFunc
#define Hwi_getIrp ti_sysbios_hal_Hwi_getIrp
#define Hwi_disable ti_sysbios_hal_Hwi_disable
#define Hwi_enable ti_sysbios_hal_Hwi_enable
#define Hwi_restore ti_sysbios_hal_Hwi_restore
#define Hwi_getHookContext ti_sysbios_hal_Hwi_getHookContext
#define Hwi_setHookContext ti_sysbios_hal_Hwi_setHookContext
#define Hwi_Module_name ti_sysbios_hal_Hwi_Module_name
#define Hwi_Module_id ti_sysbios_hal_Hwi_Module_id
#define Hwi_Module_startup ti_sysbios_hal_Hwi_Module_startup
#define Hwi_Module_startupDone ti_sysbios_hal_Hwi_Module_startupDone
#define Hwi_Module_hasMask ti_sysbios_hal_Hwi_Module_hasMask
#define Hwi_Module_getMask ti_sysbios_hal_Hwi_Module_getMask
#define Hwi_Module_setMask ti_sysbios_hal_Hwi_Module_setMask
#define Hwi_Object_heap ti_sysbios_hal_Hwi_Object_heap
#define Hwi_Module_heap ti_sysbios_hal_Hwi_Module_heap
#define Hwi_construct ti_sysbios_hal_Hwi_construct
#define Hwi_create ti_sysbios_hal_Hwi_create
#define Hwi_handle ti_sysbios_hal_Hwi_handle
#define Hwi_struct ti_sysbios_hal_Hwi_struct
#define Hwi_Handle_label ti_sysbios_hal_Hwi_Handle_label
#define Hwi_Handle_name ti_sysbios_hal_Hwi_Handle_name
#define Hwi_Instance_init ti_sysbios_hal_Hwi_Instance_init
#define Hwi_Object_count ti_sysbios_hal_Hwi_Object_count
#define Hwi_Object_get ti_sysbios_hal_Hwi_Object_get
#define Hwi_Object_first ti_sysbios_hal_Hwi_Object_first
#define Hwi_Object_next ti_sysbios_hal_Hwi_Object_next
#define Hwi_Object_sizeof ti_sysbios_hal_Hwi_Object_sizeof
#define Hwi_Params_copy ti_sysbios_hal_Hwi_Params_copy
#define Hwi_Params_init ti_sysbios_hal_Hwi_Params_init
#define Hwi_Instance_finalize ti_sysbios_hal_Hwi_Instance_finalize
#define Hwi_delete ti_sysbios_hal_Hwi_delete
#define Hwi_destruct ti_sysbios_hal_Hwi_destruct
#define Hwi_Module_upCast ti_sysbios_hal_Hwi_Module_upCast
#define Hwi_Module_to_ti_sysbios_interfaces_IHwi ti_sysbios_hal_Hwi_Module_to_ti_sysbios_interfaces_IHwi
#define Hwi_Handle_upCast ti_sysbios_hal_Hwi_Handle_upCast
#define Hwi_Handle_to_ti_sysbios_interfaces_IHwi ti_sysbios_hal_Hwi_Handle_to_ti_sysbios_interfaces_IHwi
#define Hwi_Handle_downCast ti_sysbios_hal_Hwi_Handle_downCast
#define Hwi_Handle_from_ti_sysbios_interfaces_IHwi ti_sysbios_hal_Hwi_Handle_from_ti_sysbios_interfaces_IHwi

/* proxies */
#include <ti/sysbios/hal/package/Hwi_HwiProxy.h>

#endif /* ti_sysbios_hal_Hwi__localnames__done */
#endif
