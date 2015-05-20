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
 *     MODULE-WIDE CONFIGS
 *     PER-INSTANCE TYPES
 *     VIRTUAL FUNCTIONS
 *     FUNCTION DECLARATIONS
 *     CONVERTORS
 *     SYSTEM FUNCTIONS
 *     
 *     EPILOGUE
 *     PREFIX ALIASES
 */


/*
 * ======== PROLOGUE ========
 */

#ifndef ti_sysbios_hal_Hwi_HwiProxy__include
#define ti_sysbios_hal_Hwi_HwiProxy__include

#ifndef __nested__
#define __nested__
#define ti_sysbios_hal_Hwi_HwiProxy__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define ti_sysbios_hal_Hwi_HwiProxy___VERS 160


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/IInstance.h>
#include <ti/sysbios/hal/package/package.defs.h>

#include <ti/sysbios/interfaces/IHwi.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */

/* FuncPtr */
typedef ti_sysbios_interfaces_IHwi_FuncPtr ti_sysbios_hal_Hwi_HwiProxy_FuncPtr;

/* Irp */
typedef ti_sysbios_interfaces_IHwi_Irp ti_sysbios_hal_Hwi_HwiProxy_Irp;

/* HookSet */
typedef ti_sysbios_interfaces_IHwi_HookSet ti_sysbios_hal_Hwi_HwiProxy_HookSet;

/* MaskingOption */
typedef ti_sysbios_interfaces_IHwi_MaskingOption ti_sysbios_hal_Hwi_HwiProxy_MaskingOption;

/* StackInfo */
typedef ti_sysbios_interfaces_IHwi_StackInfo ti_sysbios_hal_Hwi_HwiProxy_StackInfo;


/*
 * ======== CREATE ARGS ========
 */

/* Args__create */
typedef struct ti_sysbios_hal_Hwi_HwiProxy_Args__create {
    xdc_Int intNum;
    ti_sysbios_interfaces_IHwi_FuncPtr hwiFxn;
} ti_sysbios_hal_Hwi_HwiProxy_Args__create;


/*
 * ======== MODULE-WIDE CONFIGS ========
 */

/* Module__diagsEnabled */
typedef xdc_Bits32 CT__ti_sysbios_hal_Hwi_HwiProxy_Module__diagsEnabled;
__extern __FAR__ const CT__ti_sysbios_hal_Hwi_HwiProxy_Module__diagsEnabled ti_sysbios_hal_Hwi_HwiProxy_Module__diagsEnabled__C;

/* Module__diagsIncluded */
typedef xdc_Bits32 CT__ti_sysbios_hal_Hwi_HwiProxy_Module__diagsIncluded;
__extern __FAR__ const CT__ti_sysbios_hal_Hwi_HwiProxy_Module__diagsIncluded ti_sysbios_hal_Hwi_HwiProxy_Module__diagsIncluded__C;

/* Module__diagsMask */
typedef xdc_Bits16 *CT__ti_sysbios_hal_Hwi_HwiProxy_Module__diagsMask;
__extern __FAR__ const CT__ti_sysbios_hal_Hwi_HwiProxy_Module__diagsMask ti_sysbios_hal_Hwi_HwiProxy_Module__diagsMask__C;

/* Module__gateObj */
typedef xdc_Ptr CT__ti_sysbios_hal_Hwi_HwiProxy_Module__gateObj;
__extern __FAR__ const CT__ti_sysbios_hal_Hwi_HwiProxy_Module__gateObj ti_sysbios_hal_Hwi_HwiProxy_Module__gateObj__C;

/* Module__gatePrms */
typedef xdc_Ptr CT__ti_sysbios_hal_Hwi_HwiProxy_Module__gatePrms;
__extern __FAR__ const CT__ti_sysbios_hal_Hwi_HwiProxy_Module__gatePrms ti_sysbios_hal_Hwi_HwiProxy_Module__gatePrms__C;

/* Module__id */
typedef xdc_runtime_Types_ModuleId CT__ti_sysbios_hal_Hwi_HwiProxy_Module__id;
__extern __FAR__ const CT__ti_sysbios_hal_Hwi_HwiProxy_Module__id ti_sysbios_hal_Hwi_HwiProxy_Module__id__C;

/* Module__loggerDefined */
typedef xdc_Bool CT__ti_sysbios_hal_Hwi_HwiProxy_Module__loggerDefined;
__extern __FAR__ const CT__ti_sysbios_hal_Hwi_HwiProxy_Module__loggerDefined ti_sysbios_hal_Hwi_HwiProxy_Module__loggerDefined__C;

/* Module__loggerObj */
typedef xdc_Ptr CT__ti_sysbios_hal_Hwi_HwiProxy_Module__loggerObj;
__extern __FAR__ const CT__ti_sysbios_hal_Hwi_HwiProxy_Module__loggerObj ti_sysbios_hal_Hwi_HwiProxy_Module__loggerObj__C;

/* Module__loggerFxn0 */
typedef xdc_runtime_Types_LoggerFxn0 CT__ti_sysbios_hal_Hwi_HwiProxy_Module__loggerFxn0;
__extern __FAR__ const CT__ti_sysbios_hal_Hwi_HwiProxy_Module__loggerFxn0 ti_sysbios_hal_Hwi_HwiProxy_Module__loggerFxn0__C;

/* Module__loggerFxn1 */
typedef xdc_runtime_Types_LoggerFxn1 CT__ti_sysbios_hal_Hwi_HwiProxy_Module__loggerFxn1;
__extern __FAR__ const CT__ti_sysbios_hal_Hwi_HwiProxy_Module__loggerFxn1 ti_sysbios_hal_Hwi_HwiProxy_Module__loggerFxn1__C;

/* Module__loggerFxn2 */
typedef xdc_runtime_Types_LoggerFxn2 CT__ti_sysbios_hal_Hwi_HwiProxy_Module__loggerFxn2;
__extern __FAR__ const CT__ti_sysbios_hal_Hwi_HwiProxy_Module__loggerFxn2 ti_sysbios_hal_Hwi_HwiProxy_Module__loggerFxn2__C;

/* Module__loggerFxn4 */
typedef xdc_runtime_Types_LoggerFxn4 CT__ti_sysbios_hal_Hwi_HwiProxy_Module__loggerFxn4;
__extern __FAR__ const CT__ti_sysbios_hal_Hwi_HwiProxy_Module__loggerFxn4 ti_sysbios_hal_Hwi_HwiProxy_Module__loggerFxn4__C;

/* Module__loggerFxn8 */
typedef xdc_runtime_Types_LoggerFxn8 CT__ti_sysbios_hal_Hwi_HwiProxy_Module__loggerFxn8;
__extern __FAR__ const CT__ti_sysbios_hal_Hwi_HwiProxy_Module__loggerFxn8 ti_sysbios_hal_Hwi_HwiProxy_Module__loggerFxn8__C;

/* Module__startupDoneFxn */
typedef xdc_Bool (*CT__ti_sysbios_hal_Hwi_HwiProxy_Module__startupDoneFxn)(void);
__extern __FAR__ const CT__ti_sysbios_hal_Hwi_HwiProxy_Module__startupDoneFxn ti_sysbios_hal_Hwi_HwiProxy_Module__startupDoneFxn__C;

/* Object__count */
typedef xdc_Int CT__ti_sysbios_hal_Hwi_HwiProxy_Object__count;
__extern __FAR__ const CT__ti_sysbios_hal_Hwi_HwiProxy_Object__count ti_sysbios_hal_Hwi_HwiProxy_Object__count__C;

/* Object__heap */
typedef xdc_runtime_IHeap_Handle CT__ti_sysbios_hal_Hwi_HwiProxy_Object__heap;
__extern __FAR__ const CT__ti_sysbios_hal_Hwi_HwiProxy_Object__heap ti_sysbios_hal_Hwi_HwiProxy_Object__heap__C;

/* Object__sizeof */
typedef xdc_SizeT CT__ti_sysbios_hal_Hwi_HwiProxy_Object__sizeof;
__extern __FAR__ const CT__ti_sysbios_hal_Hwi_HwiProxy_Object__sizeof ti_sysbios_hal_Hwi_HwiProxy_Object__sizeof__C;

/* Object__table */
typedef xdc_Ptr CT__ti_sysbios_hal_Hwi_HwiProxy_Object__table;
__extern __FAR__ const CT__ti_sysbios_hal_Hwi_HwiProxy_Object__table ti_sysbios_hal_Hwi_HwiProxy_Object__table__C;

/* dispatcherAutoNestingSupport */
#ifdef ti_sysbios_hal_Hwi_HwiProxy_dispatcherAutoNestingSupport__D
#define ti_sysbios_hal_Hwi_HwiProxy_dispatcherAutoNestingSupport (ti_sysbios_hal_Hwi_HwiProxy_dispatcherAutoNestingSupport__D)
#else
#define ti_sysbios_hal_Hwi_HwiProxy_dispatcherAutoNestingSupport (ti_sysbios_hal_Hwi_HwiProxy_dispatcherAutoNestingSupport__C)
typedef xdc_Bool CT__ti_sysbios_hal_Hwi_HwiProxy_dispatcherAutoNestingSupport;
__extern __FAR__ const CT__ti_sysbios_hal_Hwi_HwiProxy_dispatcherAutoNestingSupport ti_sysbios_hal_Hwi_HwiProxy_dispatcherAutoNestingSupport__C;
#endif

/* dispatcherSwiSupport */
#ifdef ti_sysbios_hal_Hwi_HwiProxy_dispatcherSwiSupport__D
#define ti_sysbios_hal_Hwi_HwiProxy_dispatcherSwiSupport (ti_sysbios_hal_Hwi_HwiProxy_dispatcherSwiSupport__D)
#else
#define ti_sysbios_hal_Hwi_HwiProxy_dispatcherSwiSupport (ti_sysbios_hal_Hwi_HwiProxy_dispatcherSwiSupport__C)
typedef xdc_Bool CT__ti_sysbios_hal_Hwi_HwiProxy_dispatcherSwiSupport;
__extern __FAR__ const CT__ti_sysbios_hal_Hwi_HwiProxy_dispatcherSwiSupport ti_sysbios_hal_Hwi_HwiProxy_dispatcherSwiSupport__C;
#endif

/* dispatcherTaskSupport */
#ifdef ti_sysbios_hal_Hwi_HwiProxy_dispatcherTaskSupport__D
#define ti_sysbios_hal_Hwi_HwiProxy_dispatcherTaskSupport (ti_sysbios_hal_Hwi_HwiProxy_dispatcherTaskSupport__D)
#else
#define ti_sysbios_hal_Hwi_HwiProxy_dispatcherTaskSupport (ti_sysbios_hal_Hwi_HwiProxy_dispatcherTaskSupport__C)
typedef xdc_Bool CT__ti_sysbios_hal_Hwi_HwiProxy_dispatcherTaskSupport;
__extern __FAR__ const CT__ti_sysbios_hal_Hwi_HwiProxy_dispatcherTaskSupport ti_sysbios_hal_Hwi_HwiProxy_dispatcherTaskSupport__C;
#endif

/* dispatcherIrpTrackingSupport */
#ifdef ti_sysbios_hal_Hwi_HwiProxy_dispatcherIrpTrackingSupport__D
#define ti_sysbios_hal_Hwi_HwiProxy_dispatcherIrpTrackingSupport (ti_sysbios_hal_Hwi_HwiProxy_dispatcherIrpTrackingSupport__D)
#else
#define ti_sysbios_hal_Hwi_HwiProxy_dispatcherIrpTrackingSupport (ti_sysbios_hal_Hwi_HwiProxy_dispatcherIrpTrackingSupport__C)
typedef xdc_Bool CT__ti_sysbios_hal_Hwi_HwiProxy_dispatcherIrpTrackingSupport;
__extern __FAR__ const CT__ti_sysbios_hal_Hwi_HwiProxy_dispatcherIrpTrackingSupport ti_sysbios_hal_Hwi_HwiProxy_dispatcherIrpTrackingSupport__C;
#endif


/*
 * ======== PER-INSTANCE TYPES ========
 */

/* Params */
struct ti_sysbios_hal_Hwi_HwiProxy_Params {
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
struct ti_sysbios_hal_Hwi_HwiProxy_Struct {
    const ti_sysbios_hal_Hwi_HwiProxy_Fxns__ *__fxns;
    xdc_runtime_Types_CordAddr __name;
};


/*
 * ======== VIRTUAL FUNCTIONS ========
 */

/* Fxns__ */
struct ti_sysbios_hal_Hwi_HwiProxy_Fxns__ {
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
    ti_sysbios_interfaces_IHwi_FuncPtr (*getFunc)(ti_sysbios_hal_Hwi_HwiProxy_Handle, xdc_UArg*);
    xdc_Void (*setFunc)(ti_sysbios_hal_Hwi_HwiProxy_Handle, ti_sysbios_interfaces_IHwi_FuncPtr, xdc_UArg);
    xdc_Ptr (*getHookContext)(ti_sysbios_hal_Hwi_HwiProxy_Handle, xdc_Int);
    xdc_Void (*setHookContext)(ti_sysbios_hal_Hwi_HwiProxy_Handle, xdc_Int, xdc_Ptr);
    ti_sysbios_interfaces_IHwi_Irp (*getIrp)(ti_sysbios_hal_Hwi_HwiProxy_Handle);
    xdc_runtime_Types_SysFxns2 __sfxns;
};

/* Module__FXNS__C */
__extern const ti_sysbios_hal_Hwi_HwiProxy_Fxns__ ti_sysbios_hal_Hwi_HwiProxy_Module__FXNS__C;


/*
 * ======== FUNCTION DECLARATIONS ========
 */

/* Module_startup */
#define ti_sysbios_hal_Hwi_HwiProxy_Module_startup( state ) (-1)

/* Handle__label__S */
xdc__CODESECT(ti_sysbios_hal_Hwi_HwiProxy_Handle__label__S, "ti_sysbios_hal_Hwi_HwiProxy_Handle__label__S")
__extern xdc_runtime_Types_Label *ti_sysbios_hal_Hwi_HwiProxy_Handle__label__S( xdc_Ptr obj, xdc_runtime_Types_Label *lab );

/* Module__startupDone__S */
xdc__CODESECT(ti_sysbios_hal_Hwi_HwiProxy_Module__startupDone__S, "ti_sysbios_hal_Hwi_HwiProxy_Module__startupDone__S")
__extern xdc_Bool ti_sysbios_hal_Hwi_HwiProxy_Module__startupDone__S( void );

/* Object__create__S */
xdc__CODESECT(ti_sysbios_hal_Hwi_HwiProxy_Object__create__S, "ti_sysbios_hal_Hwi_HwiProxy_Object__create__S")
__extern xdc_Ptr ti_sysbios_hal_Hwi_HwiProxy_Object__create__S( xdc_Ptr __oa, xdc_SizeT __osz, xdc_Ptr __aa, const xdc_UChar *__pa, xdc_SizeT __psz, xdc_runtime_Error_Block *__eb );

/* create */
xdc__CODESECT(ti_sysbios_hal_Hwi_HwiProxy_create, "ti_sysbios_hal_Hwi_HwiProxy_create")
__extern ti_sysbios_hal_Hwi_HwiProxy_Handle ti_sysbios_hal_Hwi_HwiProxy_create( xdc_Int intNum, ti_sysbios_interfaces_IHwi_FuncPtr hwiFxn, const ti_sysbios_hal_Hwi_HwiProxy_Params *__prms, xdc_runtime_Error_Block *__eb );

/* Object__delete__S */
xdc__CODESECT(ti_sysbios_hal_Hwi_HwiProxy_Object__delete__S, "ti_sysbios_hal_Hwi_HwiProxy_Object__delete__S")
__extern xdc_Void ti_sysbios_hal_Hwi_HwiProxy_Object__delete__S( xdc_Ptr instp );

/* delete */
xdc__CODESECT(ti_sysbios_hal_Hwi_HwiProxy_delete, "ti_sysbios_hal_Hwi_HwiProxy_delete")
__extern void ti_sysbios_hal_Hwi_HwiProxy_delete(ti_sysbios_hal_Hwi_HwiProxy_Handle *instp);

/* Object__destruct__S */
xdc__CODESECT(ti_sysbios_hal_Hwi_HwiProxy_Object__destruct__S, "ti_sysbios_hal_Hwi_HwiProxy_Object__destruct__S")
__extern xdc_Void ti_sysbios_hal_Hwi_HwiProxy_Object__destruct__S( xdc_Ptr objp );

/* Object__get__S */
xdc__CODESECT(ti_sysbios_hal_Hwi_HwiProxy_Object__get__S, "ti_sysbios_hal_Hwi_HwiProxy_Object__get__S")
__extern xdc_Ptr ti_sysbios_hal_Hwi_HwiProxy_Object__get__S( xdc_Ptr oarr, xdc_Int i );

/* Object__first__S */
xdc__CODESECT(ti_sysbios_hal_Hwi_HwiProxy_Object__first__S, "ti_sysbios_hal_Hwi_HwiProxy_Object__first__S")
__extern xdc_Ptr ti_sysbios_hal_Hwi_HwiProxy_Object__first__S( void );

/* Object__next__S */
xdc__CODESECT(ti_sysbios_hal_Hwi_HwiProxy_Object__next__S, "ti_sysbios_hal_Hwi_HwiProxy_Object__next__S")
__extern xdc_Ptr ti_sysbios_hal_Hwi_HwiProxy_Object__next__S( xdc_Ptr obj );

/* Params__init__S */
xdc__CODESECT(ti_sysbios_hal_Hwi_HwiProxy_Params__init__S, "ti_sysbios_hal_Hwi_HwiProxy_Params__init__S")
__extern xdc_Void ti_sysbios_hal_Hwi_HwiProxy_Params__init__S( xdc_Ptr dst, const xdc_Void *src, xdc_SizeT psz, xdc_SizeT isz );

/* Proxy__abstract__S */
xdc__CODESECT(ti_sysbios_hal_Hwi_HwiProxy_Proxy__abstract__S, "ti_sysbios_hal_Hwi_HwiProxy_Proxy__abstract__S")
__extern xdc_Bool ti_sysbios_hal_Hwi_HwiProxy_Proxy__abstract__S( void );

/* Proxy__delegate__S */
xdc__CODESECT(ti_sysbios_hal_Hwi_HwiProxy_Proxy__delegate__S, "ti_sysbios_hal_Hwi_HwiProxy_Proxy__delegate__S")
__extern xdc_Ptr ti_sysbios_hal_Hwi_HwiProxy_Proxy__delegate__S( void );

/* getStackInfo__E */
#define ti_sysbios_hal_Hwi_HwiProxy_getStackInfo ti_sysbios_hal_Hwi_HwiProxy_getStackInfo__E
xdc__CODESECT(ti_sysbios_hal_Hwi_HwiProxy_getStackInfo__E, "ti_sysbios_hal_Hwi_HwiProxy_getStackInfo")
__extern xdc_Bool ti_sysbios_hal_Hwi_HwiProxy_getStackInfo__E( ti_sysbios_interfaces_IHwi_StackInfo *stkInfo, xdc_Bool computeStackDepth );

/* getCoreStackInfo__E */
#define ti_sysbios_hal_Hwi_HwiProxy_getCoreStackInfo ti_sysbios_hal_Hwi_HwiProxy_getCoreStackInfo__E
xdc__CODESECT(ti_sysbios_hal_Hwi_HwiProxy_getCoreStackInfo__E, "ti_sysbios_hal_Hwi_HwiProxy_getCoreStackInfo")
__extern xdc_Bool ti_sysbios_hal_Hwi_HwiProxy_getCoreStackInfo__E( ti_sysbios_interfaces_IHwi_StackInfo *stkInfo, xdc_Bool computeStackDepth, xdc_UInt coreId );

/* startup__E */
#define ti_sysbios_hal_Hwi_HwiProxy_startup ti_sysbios_hal_Hwi_HwiProxy_startup__E
xdc__CODESECT(ti_sysbios_hal_Hwi_HwiProxy_startup__E, "ti_sysbios_hal_Hwi_HwiProxy_startup")
__extern xdc_Void ti_sysbios_hal_Hwi_HwiProxy_startup__E( void );

/* disable__E */
#define ti_sysbios_hal_Hwi_HwiProxy_disable ti_sysbios_hal_Hwi_HwiProxy_disable__E
xdc__CODESECT(ti_sysbios_hal_Hwi_HwiProxy_disable__E, "ti_sysbios_hal_Hwi_HwiProxy_disable")
__extern xdc_UInt ti_sysbios_hal_Hwi_HwiProxy_disable__E( void );

/* enable__E */
#define ti_sysbios_hal_Hwi_HwiProxy_enable ti_sysbios_hal_Hwi_HwiProxy_enable__E
xdc__CODESECT(ti_sysbios_hal_Hwi_HwiProxy_enable__E, "ti_sysbios_hal_Hwi_HwiProxy_enable")
__extern xdc_UInt ti_sysbios_hal_Hwi_HwiProxy_enable__E( void );

/* restore__E */
#define ti_sysbios_hal_Hwi_HwiProxy_restore ti_sysbios_hal_Hwi_HwiProxy_restore__E
xdc__CODESECT(ti_sysbios_hal_Hwi_HwiProxy_restore__E, "ti_sysbios_hal_Hwi_HwiProxy_restore")
__extern xdc_Void ti_sysbios_hal_Hwi_HwiProxy_restore__E( xdc_UInt key );

/* switchFromBootStack__E */
#define ti_sysbios_hal_Hwi_HwiProxy_switchFromBootStack ti_sysbios_hal_Hwi_HwiProxy_switchFromBootStack__E
xdc__CODESECT(ti_sysbios_hal_Hwi_HwiProxy_switchFromBootStack__E, "ti_sysbios_hal_Hwi_HwiProxy_switchFromBootStack")
__extern xdc_Void ti_sysbios_hal_Hwi_HwiProxy_switchFromBootStack__E( void );

/* post__E */
#define ti_sysbios_hal_Hwi_HwiProxy_post ti_sysbios_hal_Hwi_HwiProxy_post__E
xdc__CODESECT(ti_sysbios_hal_Hwi_HwiProxy_post__E, "ti_sysbios_hal_Hwi_HwiProxy_post")
__extern xdc_Void ti_sysbios_hal_Hwi_HwiProxy_post__E( xdc_UInt intNum );

/* getTaskSP__E */
#define ti_sysbios_hal_Hwi_HwiProxy_getTaskSP ti_sysbios_hal_Hwi_HwiProxy_getTaskSP__E
xdc__CODESECT(ti_sysbios_hal_Hwi_HwiProxy_getTaskSP__E, "ti_sysbios_hal_Hwi_HwiProxy_getTaskSP")
__extern xdc_Char *ti_sysbios_hal_Hwi_HwiProxy_getTaskSP__E( void );

/* disableInterrupt__E */
#define ti_sysbios_hal_Hwi_HwiProxy_disableInterrupt ti_sysbios_hal_Hwi_HwiProxy_disableInterrupt__E
xdc__CODESECT(ti_sysbios_hal_Hwi_HwiProxy_disableInterrupt__E, "ti_sysbios_hal_Hwi_HwiProxy_disableInterrupt")
__extern xdc_UInt ti_sysbios_hal_Hwi_HwiProxy_disableInterrupt__E( xdc_UInt intNum );

/* enableInterrupt__E */
#define ti_sysbios_hal_Hwi_HwiProxy_enableInterrupt ti_sysbios_hal_Hwi_HwiProxy_enableInterrupt__E
xdc__CODESECT(ti_sysbios_hal_Hwi_HwiProxy_enableInterrupt__E, "ti_sysbios_hal_Hwi_HwiProxy_enableInterrupt")
__extern xdc_UInt ti_sysbios_hal_Hwi_HwiProxy_enableInterrupt__E( xdc_UInt intNum );

/* restoreInterrupt__E */
#define ti_sysbios_hal_Hwi_HwiProxy_restoreInterrupt ti_sysbios_hal_Hwi_HwiProxy_restoreInterrupt__E
xdc__CODESECT(ti_sysbios_hal_Hwi_HwiProxy_restoreInterrupt__E, "ti_sysbios_hal_Hwi_HwiProxy_restoreInterrupt")
__extern xdc_Void ti_sysbios_hal_Hwi_HwiProxy_restoreInterrupt__E( xdc_UInt intNum, xdc_UInt key );

/* clearInterrupt__E */
#define ti_sysbios_hal_Hwi_HwiProxy_clearInterrupt ti_sysbios_hal_Hwi_HwiProxy_clearInterrupt__E
xdc__CODESECT(ti_sysbios_hal_Hwi_HwiProxy_clearInterrupt__E, "ti_sysbios_hal_Hwi_HwiProxy_clearInterrupt")
__extern xdc_Void ti_sysbios_hal_Hwi_HwiProxy_clearInterrupt__E( xdc_UInt intNum );

/* getFunc__E */
#define ti_sysbios_hal_Hwi_HwiProxy_getFunc ti_sysbios_hal_Hwi_HwiProxy_getFunc__E
xdc__CODESECT(ti_sysbios_hal_Hwi_HwiProxy_getFunc__E, "ti_sysbios_hal_Hwi_HwiProxy_getFunc")
__extern ti_sysbios_interfaces_IHwi_FuncPtr ti_sysbios_hal_Hwi_HwiProxy_getFunc__E( ti_sysbios_hal_Hwi_HwiProxy_Handle __inst, xdc_UArg *arg );

/* setFunc__E */
#define ti_sysbios_hal_Hwi_HwiProxy_setFunc ti_sysbios_hal_Hwi_HwiProxy_setFunc__E
xdc__CODESECT(ti_sysbios_hal_Hwi_HwiProxy_setFunc__E, "ti_sysbios_hal_Hwi_HwiProxy_setFunc")
__extern xdc_Void ti_sysbios_hal_Hwi_HwiProxy_setFunc__E( ti_sysbios_hal_Hwi_HwiProxy_Handle __inst, ti_sysbios_interfaces_IHwi_FuncPtr fxn, xdc_UArg arg );

/* getHookContext__E */
#define ti_sysbios_hal_Hwi_HwiProxy_getHookContext ti_sysbios_hal_Hwi_HwiProxy_getHookContext__E
xdc__CODESECT(ti_sysbios_hal_Hwi_HwiProxy_getHookContext__E, "ti_sysbios_hal_Hwi_HwiProxy_getHookContext")
__extern xdc_Ptr ti_sysbios_hal_Hwi_HwiProxy_getHookContext__E( ti_sysbios_hal_Hwi_HwiProxy_Handle __inst, xdc_Int id );

/* setHookContext__E */
#define ti_sysbios_hal_Hwi_HwiProxy_setHookContext ti_sysbios_hal_Hwi_HwiProxy_setHookContext__E
xdc__CODESECT(ti_sysbios_hal_Hwi_HwiProxy_setHookContext__E, "ti_sysbios_hal_Hwi_HwiProxy_setHookContext")
__extern xdc_Void ti_sysbios_hal_Hwi_HwiProxy_setHookContext__E( ti_sysbios_hal_Hwi_HwiProxy_Handle __inst, xdc_Int id, xdc_Ptr hookContext );

/* getIrp__E */
#define ti_sysbios_hal_Hwi_HwiProxy_getIrp ti_sysbios_hal_Hwi_HwiProxy_getIrp__E
xdc__CODESECT(ti_sysbios_hal_Hwi_HwiProxy_getIrp__E, "ti_sysbios_hal_Hwi_HwiProxy_getIrp")
__extern ti_sysbios_interfaces_IHwi_Irp ti_sysbios_hal_Hwi_HwiProxy_getIrp__E( ti_sysbios_hal_Hwi_HwiProxy_Handle __inst );


/*
 * ======== CONVERTORS ========
 */

/* Module_upCast */
static inline ti_sysbios_interfaces_IHwi_Module ti_sysbios_hal_Hwi_HwiProxy_Module_upCast( void )
{
    return (ti_sysbios_interfaces_IHwi_Module)ti_sysbios_hal_Hwi_HwiProxy_Proxy__delegate__S();
}

/* Module_to_ti_sysbios_interfaces_IHwi */
#define ti_sysbios_hal_Hwi_HwiProxy_Module_to_ti_sysbios_interfaces_IHwi ti_sysbios_hal_Hwi_HwiProxy_Module_upCast

/* Handle_upCast */
static inline ti_sysbios_interfaces_IHwi_Handle ti_sysbios_hal_Hwi_HwiProxy_Handle_upCast( ti_sysbios_hal_Hwi_HwiProxy_Handle i )
{
    return (ti_sysbios_interfaces_IHwi_Handle)i;
}

/* Handle_to_ti_sysbios_interfaces_IHwi */
#define ti_sysbios_hal_Hwi_HwiProxy_Handle_to_ti_sysbios_interfaces_IHwi ti_sysbios_hal_Hwi_HwiProxy_Handle_upCast

/* Handle_downCast */
static inline ti_sysbios_hal_Hwi_HwiProxy_Handle ti_sysbios_hal_Hwi_HwiProxy_Handle_downCast( ti_sysbios_interfaces_IHwi_Handle i )
{
    ti_sysbios_interfaces_IHwi_Handle i2 = (ti_sysbios_interfaces_IHwi_Handle)i;
if (ti_sysbios_hal_Hwi_HwiProxy_Proxy__abstract__S()) return (ti_sysbios_hal_Hwi_HwiProxy_Handle)i;
    return (void*)i2->__fxns == (void*)ti_sysbios_hal_Hwi_HwiProxy_Proxy__delegate__S() ? (ti_sysbios_hal_Hwi_HwiProxy_Handle)i : 0;
}

/* Handle_from_ti_sysbios_interfaces_IHwi */
#define ti_sysbios_hal_Hwi_HwiProxy_Handle_from_ti_sysbios_interfaces_IHwi ti_sysbios_hal_Hwi_HwiProxy_Handle_downCast


/*
 * ======== SYSTEM FUNCTIONS ========
 */

/* Module_startupDone */
#define ti_sysbios_hal_Hwi_HwiProxy_Module_startupDone() ti_sysbios_hal_Hwi_HwiProxy_Module__startupDone__S()

/* Object_heap */
#define ti_sysbios_hal_Hwi_HwiProxy_Object_heap() ti_sysbios_hal_Hwi_HwiProxy_Object__heap__C

/* Module_heap */
#define ti_sysbios_hal_Hwi_HwiProxy_Module_heap() ti_sysbios_hal_Hwi_HwiProxy_Object__heap__C

/* Module_id */
static inline CT__ti_sysbios_hal_Hwi_HwiProxy_Module__id ti_sysbios_hal_Hwi_HwiProxy_Module_id( void ) 
{
    return ti_sysbios_hal_Hwi_HwiProxy_Module__id__C;
}

/* Proxy_abstract */
#define ti_sysbios_hal_Hwi_HwiProxy_Proxy_abstract() ti_sysbios_hal_Hwi_HwiProxy_Proxy__abstract__S()

/* Proxy_delegate */
#define ti_sysbios_hal_Hwi_HwiProxy_Proxy_delegate() ((ti_sysbios_interfaces_IHwi_Module)ti_sysbios_hal_Hwi_HwiProxy_Proxy__delegate__S())

/* Params_init */
static inline void ti_sysbios_hal_Hwi_HwiProxy_Params_init( ti_sysbios_hal_Hwi_HwiProxy_Params *prms ) 
{
    if (prms) {
        ti_sysbios_hal_Hwi_HwiProxy_Params__init__S(prms, 0, sizeof(ti_sysbios_hal_Hwi_HwiProxy_Params), sizeof(xdc_runtime_IInstance_Params));
    }
}

/* Params_copy */
static inline void ti_sysbios_hal_Hwi_HwiProxy_Params_copy(ti_sysbios_hal_Hwi_HwiProxy_Params *dst, const ti_sysbios_hal_Hwi_HwiProxy_Params *src) 
{
    if (dst) {
        ti_sysbios_hal_Hwi_HwiProxy_Params__init__S(dst, (const void *)src, sizeof(ti_sysbios_hal_Hwi_HwiProxy_Params), sizeof(xdc_runtime_IInstance_Params));
    }
}


/*
 * ======== EPILOGUE ========
 */

#ifdef ti_sysbios_hal_Hwi_HwiProxy__top__
#undef __nested__
#endif

#endif /* ti_sysbios_hal_Hwi_HwiProxy__include */


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(ti_sysbios_hal_Hwi_HwiProxy__nolocalnames)

#ifndef ti_sysbios_hal_Hwi_HwiProxy__localnames__done
#define ti_sysbios_hal_Hwi_HwiProxy__localnames__done

/* module prefix */
#define Hwi_HwiProxy_Instance ti_sysbios_hal_Hwi_HwiProxy_Instance
#define Hwi_HwiProxy_Handle ti_sysbios_hal_Hwi_HwiProxy_Handle
#define Hwi_HwiProxy_Module ti_sysbios_hal_Hwi_HwiProxy_Module
#define Hwi_HwiProxy_Object ti_sysbios_hal_Hwi_HwiProxy_Object
#define Hwi_HwiProxy_Struct ti_sysbios_hal_Hwi_HwiProxy_Struct
#define Hwi_HwiProxy_FuncPtr ti_sysbios_hal_Hwi_HwiProxy_FuncPtr
#define Hwi_HwiProxy_Irp ti_sysbios_hal_Hwi_HwiProxy_Irp
#define Hwi_HwiProxy_HookSet ti_sysbios_hal_Hwi_HwiProxy_HookSet
#define Hwi_HwiProxy_MaskingOption ti_sysbios_hal_Hwi_HwiProxy_MaskingOption
#define Hwi_HwiProxy_StackInfo ti_sysbios_hal_Hwi_HwiProxy_StackInfo
#define Hwi_HwiProxy_dispatcherAutoNestingSupport ti_sysbios_hal_Hwi_HwiProxy_dispatcherAutoNestingSupport
#define Hwi_HwiProxy_dispatcherSwiSupport ti_sysbios_hal_Hwi_HwiProxy_dispatcherSwiSupport
#define Hwi_HwiProxy_dispatcherTaskSupport ti_sysbios_hal_Hwi_HwiProxy_dispatcherTaskSupport
#define Hwi_HwiProxy_dispatcherIrpTrackingSupport ti_sysbios_hal_Hwi_HwiProxy_dispatcherIrpTrackingSupport
#define Hwi_HwiProxy_Params ti_sysbios_hal_Hwi_HwiProxy_Params
#define Hwi_HwiProxy_getStackInfo ti_sysbios_hal_Hwi_HwiProxy_getStackInfo
#define Hwi_HwiProxy_getCoreStackInfo ti_sysbios_hal_Hwi_HwiProxy_getCoreStackInfo
#define Hwi_HwiProxy_startup ti_sysbios_hal_Hwi_HwiProxy_startup
#define Hwi_HwiProxy_disable ti_sysbios_hal_Hwi_HwiProxy_disable
#define Hwi_HwiProxy_enable ti_sysbios_hal_Hwi_HwiProxy_enable
#define Hwi_HwiProxy_restore ti_sysbios_hal_Hwi_HwiProxy_restore
#define Hwi_HwiProxy_switchFromBootStack ti_sysbios_hal_Hwi_HwiProxy_switchFromBootStack
#define Hwi_HwiProxy_post ti_sysbios_hal_Hwi_HwiProxy_post
#define Hwi_HwiProxy_getTaskSP ti_sysbios_hal_Hwi_HwiProxy_getTaskSP
#define Hwi_HwiProxy_disableInterrupt ti_sysbios_hal_Hwi_HwiProxy_disableInterrupt
#define Hwi_HwiProxy_enableInterrupt ti_sysbios_hal_Hwi_HwiProxy_enableInterrupt
#define Hwi_HwiProxy_restoreInterrupt ti_sysbios_hal_Hwi_HwiProxy_restoreInterrupt
#define Hwi_HwiProxy_clearInterrupt ti_sysbios_hal_Hwi_HwiProxy_clearInterrupt
#define Hwi_HwiProxy_getFunc ti_sysbios_hal_Hwi_HwiProxy_getFunc
#define Hwi_HwiProxy_setFunc ti_sysbios_hal_Hwi_HwiProxy_setFunc
#define Hwi_HwiProxy_getHookContext ti_sysbios_hal_Hwi_HwiProxy_getHookContext
#define Hwi_HwiProxy_setHookContext ti_sysbios_hal_Hwi_HwiProxy_setHookContext
#define Hwi_HwiProxy_getIrp ti_sysbios_hal_Hwi_HwiProxy_getIrp
#define Hwi_HwiProxy_Module_name ti_sysbios_hal_Hwi_HwiProxy_Module_name
#define Hwi_HwiProxy_Module_id ti_sysbios_hal_Hwi_HwiProxy_Module_id
#define Hwi_HwiProxy_Module_startup ti_sysbios_hal_Hwi_HwiProxy_Module_startup
#define Hwi_HwiProxy_Module_startupDone ti_sysbios_hal_Hwi_HwiProxy_Module_startupDone
#define Hwi_HwiProxy_Module_hasMask ti_sysbios_hal_Hwi_HwiProxy_Module_hasMask
#define Hwi_HwiProxy_Module_getMask ti_sysbios_hal_Hwi_HwiProxy_Module_getMask
#define Hwi_HwiProxy_Module_setMask ti_sysbios_hal_Hwi_HwiProxy_Module_setMask
#define Hwi_HwiProxy_Object_heap ti_sysbios_hal_Hwi_HwiProxy_Object_heap
#define Hwi_HwiProxy_Module_heap ti_sysbios_hal_Hwi_HwiProxy_Module_heap
#define Hwi_HwiProxy_construct ti_sysbios_hal_Hwi_HwiProxy_construct
#define Hwi_HwiProxy_create ti_sysbios_hal_Hwi_HwiProxy_create
#define Hwi_HwiProxy_handle ti_sysbios_hal_Hwi_HwiProxy_handle
#define Hwi_HwiProxy_struct ti_sysbios_hal_Hwi_HwiProxy_struct
#define Hwi_HwiProxy_Handle_label ti_sysbios_hal_Hwi_HwiProxy_Handle_label
#define Hwi_HwiProxy_Handle_name ti_sysbios_hal_Hwi_HwiProxy_Handle_name
#define Hwi_HwiProxy_Instance_init ti_sysbios_hal_Hwi_HwiProxy_Instance_init
#define Hwi_HwiProxy_Object_count ti_sysbios_hal_Hwi_HwiProxy_Object_count
#define Hwi_HwiProxy_Object_get ti_sysbios_hal_Hwi_HwiProxy_Object_get
#define Hwi_HwiProxy_Object_first ti_sysbios_hal_Hwi_HwiProxy_Object_first
#define Hwi_HwiProxy_Object_next ti_sysbios_hal_Hwi_HwiProxy_Object_next
#define Hwi_HwiProxy_Object_sizeof ti_sysbios_hal_Hwi_HwiProxy_Object_sizeof
#define Hwi_HwiProxy_Params_copy ti_sysbios_hal_Hwi_HwiProxy_Params_copy
#define Hwi_HwiProxy_Params_init ti_sysbios_hal_Hwi_HwiProxy_Params_init
#define Hwi_HwiProxy_Instance_State ti_sysbios_hal_Hwi_HwiProxy_Instance_State
#define Hwi_HwiProxy_Instance_finalize ti_sysbios_hal_Hwi_HwiProxy_Instance_finalize
#define Hwi_HwiProxy_Proxy_abstract ti_sysbios_hal_Hwi_HwiProxy_Proxy_abstract
#define Hwi_HwiProxy_Proxy_delegate ti_sysbios_hal_Hwi_HwiProxy_Proxy_delegate
#define Hwi_HwiProxy_delete ti_sysbios_hal_Hwi_HwiProxy_delete
#define Hwi_HwiProxy_destruct ti_sysbios_hal_Hwi_HwiProxy_destruct
#define Hwi_HwiProxy_Module_upCast ti_sysbios_hal_Hwi_HwiProxy_Module_upCast
#define Hwi_HwiProxy_Module_to_ti_sysbios_interfaces_IHwi ti_sysbios_hal_Hwi_HwiProxy_Module_to_ti_sysbios_interfaces_IHwi
#define Hwi_HwiProxy_Handle_upCast ti_sysbios_hal_Hwi_HwiProxy_Handle_upCast
#define Hwi_HwiProxy_Handle_to_ti_sysbios_interfaces_IHwi ti_sysbios_hal_Hwi_HwiProxy_Handle_to_ti_sysbios_interfaces_IHwi
#define Hwi_HwiProxy_Handle_downCast ti_sysbios_hal_Hwi_HwiProxy_Handle_downCast
#define Hwi_HwiProxy_Handle_from_ti_sysbios_interfaces_IHwi ti_sysbios_hal_Hwi_HwiProxy_Handle_from_ti_sysbios_interfaces_IHwi

#endif /* ti_sysbios_hal_Hwi_HwiProxy__localnames__done */
#endif
