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
 *     FUNCTION DECLARATIONS
 *     SYSTEM FUNCTIONS
 *     
 *     EPILOGUE
 *     STATE STRUCTURES
 *     PREFIX ALIASES
 */


/*
 * ======== PROLOGUE ========
 */

#ifndef ti_sysbios_family_arm_cc26xx_Alarm__include
#define ti_sysbios_family_arm_cc26xx_Alarm__include

#ifndef __nested__
#define __nested__
#define ti_sysbios_family_arm_cc26xx_Alarm__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define ti_sysbios_family_arm_cc26xx_Alarm___VERS 160


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/IInstance.h>
#include <ti/sysbios/family/arm/cc26xx/package/package.defs.h>

#include <ti/sysbios/knl/Clock.h>
#include <xdc/runtime/IModule.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */

/* FuncPtr */
typedef xdc_Void (*ti_sysbios_family_arm_cc26xx_Alarm_FuncPtr)(xdc_UArg);


/*
 * ======== CREATE ARGS ========
 */

/* Args__create */
typedef struct ti_sysbios_family_arm_cc26xx_Alarm_Args__create {
    ti_sysbios_family_arm_cc26xx_Alarm_FuncPtr alarmFxn;
    xdc_UArg arg;
} ti_sysbios_family_arm_cc26xx_Alarm_Args__create;


/*
 * ======== INTERNAL DEFINITIONS ========
 */


/*
 * ======== MODULE-WIDE CONFIGS ========
 */

/* Module__diagsEnabled */
typedef xdc_Bits32 CT__ti_sysbios_family_arm_cc26xx_Alarm_Module__diagsEnabled;
__extern __FAR__ const CT__ti_sysbios_family_arm_cc26xx_Alarm_Module__diagsEnabled ti_sysbios_family_arm_cc26xx_Alarm_Module__diagsEnabled__C;

/* Module__diagsIncluded */
typedef xdc_Bits32 CT__ti_sysbios_family_arm_cc26xx_Alarm_Module__diagsIncluded;
__extern __FAR__ const CT__ti_sysbios_family_arm_cc26xx_Alarm_Module__diagsIncluded ti_sysbios_family_arm_cc26xx_Alarm_Module__diagsIncluded__C;

/* Module__diagsMask */
typedef xdc_Bits16 *CT__ti_sysbios_family_arm_cc26xx_Alarm_Module__diagsMask;
__extern __FAR__ const CT__ti_sysbios_family_arm_cc26xx_Alarm_Module__diagsMask ti_sysbios_family_arm_cc26xx_Alarm_Module__diagsMask__C;

/* Module__gateObj */
typedef xdc_Ptr CT__ti_sysbios_family_arm_cc26xx_Alarm_Module__gateObj;
__extern __FAR__ const CT__ti_sysbios_family_arm_cc26xx_Alarm_Module__gateObj ti_sysbios_family_arm_cc26xx_Alarm_Module__gateObj__C;

/* Module__gatePrms */
typedef xdc_Ptr CT__ti_sysbios_family_arm_cc26xx_Alarm_Module__gatePrms;
__extern __FAR__ const CT__ti_sysbios_family_arm_cc26xx_Alarm_Module__gatePrms ti_sysbios_family_arm_cc26xx_Alarm_Module__gatePrms__C;

/* Module__id */
typedef xdc_runtime_Types_ModuleId CT__ti_sysbios_family_arm_cc26xx_Alarm_Module__id;
__extern __FAR__ const CT__ti_sysbios_family_arm_cc26xx_Alarm_Module__id ti_sysbios_family_arm_cc26xx_Alarm_Module__id__C;

/* Module__loggerDefined */
typedef xdc_Bool CT__ti_sysbios_family_arm_cc26xx_Alarm_Module__loggerDefined;
__extern __FAR__ const CT__ti_sysbios_family_arm_cc26xx_Alarm_Module__loggerDefined ti_sysbios_family_arm_cc26xx_Alarm_Module__loggerDefined__C;

/* Module__loggerObj */
typedef xdc_Ptr CT__ti_sysbios_family_arm_cc26xx_Alarm_Module__loggerObj;
__extern __FAR__ const CT__ti_sysbios_family_arm_cc26xx_Alarm_Module__loggerObj ti_sysbios_family_arm_cc26xx_Alarm_Module__loggerObj__C;

/* Module__loggerFxn0 */
typedef xdc_runtime_Types_LoggerFxn0 CT__ti_sysbios_family_arm_cc26xx_Alarm_Module__loggerFxn0;
__extern __FAR__ const CT__ti_sysbios_family_arm_cc26xx_Alarm_Module__loggerFxn0 ti_sysbios_family_arm_cc26xx_Alarm_Module__loggerFxn0__C;

/* Module__loggerFxn1 */
typedef xdc_runtime_Types_LoggerFxn1 CT__ti_sysbios_family_arm_cc26xx_Alarm_Module__loggerFxn1;
__extern __FAR__ const CT__ti_sysbios_family_arm_cc26xx_Alarm_Module__loggerFxn1 ti_sysbios_family_arm_cc26xx_Alarm_Module__loggerFxn1__C;

/* Module__loggerFxn2 */
typedef xdc_runtime_Types_LoggerFxn2 CT__ti_sysbios_family_arm_cc26xx_Alarm_Module__loggerFxn2;
__extern __FAR__ const CT__ti_sysbios_family_arm_cc26xx_Alarm_Module__loggerFxn2 ti_sysbios_family_arm_cc26xx_Alarm_Module__loggerFxn2__C;

/* Module__loggerFxn4 */
typedef xdc_runtime_Types_LoggerFxn4 CT__ti_sysbios_family_arm_cc26xx_Alarm_Module__loggerFxn4;
__extern __FAR__ const CT__ti_sysbios_family_arm_cc26xx_Alarm_Module__loggerFxn4 ti_sysbios_family_arm_cc26xx_Alarm_Module__loggerFxn4__C;

/* Module__loggerFxn8 */
typedef xdc_runtime_Types_LoggerFxn8 CT__ti_sysbios_family_arm_cc26xx_Alarm_Module__loggerFxn8;
__extern __FAR__ const CT__ti_sysbios_family_arm_cc26xx_Alarm_Module__loggerFxn8 ti_sysbios_family_arm_cc26xx_Alarm_Module__loggerFxn8__C;

/* Module__startupDoneFxn */
typedef xdc_Bool (*CT__ti_sysbios_family_arm_cc26xx_Alarm_Module__startupDoneFxn)(void);
__extern __FAR__ const CT__ti_sysbios_family_arm_cc26xx_Alarm_Module__startupDoneFxn ti_sysbios_family_arm_cc26xx_Alarm_Module__startupDoneFxn__C;

/* Object__count */
typedef xdc_Int CT__ti_sysbios_family_arm_cc26xx_Alarm_Object__count;
__extern __FAR__ const CT__ti_sysbios_family_arm_cc26xx_Alarm_Object__count ti_sysbios_family_arm_cc26xx_Alarm_Object__count__C;

/* Object__heap */
typedef xdc_runtime_IHeap_Handle CT__ti_sysbios_family_arm_cc26xx_Alarm_Object__heap;
__extern __FAR__ const CT__ti_sysbios_family_arm_cc26xx_Alarm_Object__heap ti_sysbios_family_arm_cc26xx_Alarm_Object__heap__C;

/* Object__sizeof */
typedef xdc_SizeT CT__ti_sysbios_family_arm_cc26xx_Alarm_Object__sizeof;
__extern __FAR__ const CT__ti_sysbios_family_arm_cc26xx_Alarm_Object__sizeof ti_sysbios_family_arm_cc26xx_Alarm_Object__sizeof__C;

/* Object__table */
typedef xdc_Ptr CT__ti_sysbios_family_arm_cc26xx_Alarm_Object__table;
__extern __FAR__ const CT__ti_sysbios_family_arm_cc26xx_Alarm_Object__table ti_sysbios_family_arm_cc26xx_Alarm_Object__table__C;


/*
 * ======== PER-INSTANCE TYPES ========
 */

/* Params */
struct ti_sysbios_family_arm_cc26xx_Alarm_Params {
    size_t __size;
    const void *__self;
    void *__fxns;
    xdc_runtime_IInstance_Params *instance;
    xdc_runtime_IInstance_Params __iprms;
};

/* Struct */
struct ti_sysbios_family_arm_cc26xx_Alarm_Struct {
    xdc_UInt64 __f0;
    ti_sysbios_knl_Clock_Struct __f1;
    xdc_runtime_Types_CordAddr __name;
};


/*
 * ======== FUNCTION DECLARATIONS ========
 */

/* Module_startup */
#define ti_sysbios_family_arm_cc26xx_Alarm_Module_startup( state ) (-1)

/* Instance_init__E */
xdc__CODESECT(ti_sysbios_family_arm_cc26xx_Alarm_Instance_init__E, "ti_sysbios_family_arm_cc26xx_Alarm_Instance_init")
__extern xdc_Void ti_sysbios_family_arm_cc26xx_Alarm_Instance_init__E(ti_sysbios_family_arm_cc26xx_Alarm_Object *, ti_sysbios_family_arm_cc26xx_Alarm_FuncPtr alarmFxn, xdc_UArg arg, const ti_sysbios_family_arm_cc26xx_Alarm_Params *);

/* Instance_finalize__E */
xdc__CODESECT(ti_sysbios_family_arm_cc26xx_Alarm_Instance_finalize__E, "ti_sysbios_family_arm_cc26xx_Alarm_Instance_finalize")
__extern void ti_sysbios_family_arm_cc26xx_Alarm_Instance_finalize__E( ti_sysbios_family_arm_cc26xx_Alarm_Object* );

/* Handle__label__S */
xdc__CODESECT(ti_sysbios_family_arm_cc26xx_Alarm_Handle__label__S, "ti_sysbios_family_arm_cc26xx_Alarm_Handle__label__S")
__extern xdc_runtime_Types_Label *ti_sysbios_family_arm_cc26xx_Alarm_Handle__label__S( xdc_Ptr obj, xdc_runtime_Types_Label *lab );

/* Module__startupDone__S */
xdc__CODESECT(ti_sysbios_family_arm_cc26xx_Alarm_Module__startupDone__S, "ti_sysbios_family_arm_cc26xx_Alarm_Module__startupDone__S")
__extern xdc_Bool ti_sysbios_family_arm_cc26xx_Alarm_Module__startupDone__S( void );

/* Object__create__S */
xdc__CODESECT(ti_sysbios_family_arm_cc26xx_Alarm_Object__create__S, "ti_sysbios_family_arm_cc26xx_Alarm_Object__create__S")
__extern xdc_Ptr ti_sysbios_family_arm_cc26xx_Alarm_Object__create__S( xdc_Ptr __oa, xdc_SizeT __osz, xdc_Ptr __aa, const xdc_UChar *__pa, xdc_SizeT __psz, xdc_runtime_Error_Block *__eb );

/* create */
xdc__CODESECT(ti_sysbios_family_arm_cc26xx_Alarm_create, "ti_sysbios_family_arm_cc26xx_Alarm_create")
__extern ti_sysbios_family_arm_cc26xx_Alarm_Handle ti_sysbios_family_arm_cc26xx_Alarm_create( ti_sysbios_family_arm_cc26xx_Alarm_FuncPtr alarmFxn, xdc_UArg arg, const ti_sysbios_family_arm_cc26xx_Alarm_Params *__prms, xdc_runtime_Error_Block *__eb );

/* construct */
xdc__CODESECT(ti_sysbios_family_arm_cc26xx_Alarm_construct, "ti_sysbios_family_arm_cc26xx_Alarm_construct")
__extern void ti_sysbios_family_arm_cc26xx_Alarm_construct( ti_sysbios_family_arm_cc26xx_Alarm_Struct *__obj, ti_sysbios_family_arm_cc26xx_Alarm_FuncPtr alarmFxn, xdc_UArg arg, const ti_sysbios_family_arm_cc26xx_Alarm_Params *__prms );

/* Object__delete__S */
xdc__CODESECT(ti_sysbios_family_arm_cc26xx_Alarm_Object__delete__S, "ti_sysbios_family_arm_cc26xx_Alarm_Object__delete__S")
__extern xdc_Void ti_sysbios_family_arm_cc26xx_Alarm_Object__delete__S( xdc_Ptr instp );

/* delete */
xdc__CODESECT(ti_sysbios_family_arm_cc26xx_Alarm_delete, "ti_sysbios_family_arm_cc26xx_Alarm_delete")
__extern void ti_sysbios_family_arm_cc26xx_Alarm_delete(ti_sysbios_family_arm_cc26xx_Alarm_Handle *instp);

/* Object__destruct__S */
xdc__CODESECT(ti_sysbios_family_arm_cc26xx_Alarm_Object__destruct__S, "ti_sysbios_family_arm_cc26xx_Alarm_Object__destruct__S")
__extern xdc_Void ti_sysbios_family_arm_cc26xx_Alarm_Object__destruct__S( xdc_Ptr objp );

/* destruct */
xdc__CODESECT(ti_sysbios_family_arm_cc26xx_Alarm_destruct, "ti_sysbios_family_arm_cc26xx_Alarm_destruct")
__extern void ti_sysbios_family_arm_cc26xx_Alarm_destruct(ti_sysbios_family_arm_cc26xx_Alarm_Struct *obj);

/* Object__get__S */
xdc__CODESECT(ti_sysbios_family_arm_cc26xx_Alarm_Object__get__S, "ti_sysbios_family_arm_cc26xx_Alarm_Object__get__S")
__extern xdc_Ptr ti_sysbios_family_arm_cc26xx_Alarm_Object__get__S( xdc_Ptr oarr, xdc_Int i );

/* Object__first__S */
xdc__CODESECT(ti_sysbios_family_arm_cc26xx_Alarm_Object__first__S, "ti_sysbios_family_arm_cc26xx_Alarm_Object__first__S")
__extern xdc_Ptr ti_sysbios_family_arm_cc26xx_Alarm_Object__first__S( void );

/* Object__next__S */
xdc__CODESECT(ti_sysbios_family_arm_cc26xx_Alarm_Object__next__S, "ti_sysbios_family_arm_cc26xx_Alarm_Object__next__S")
__extern xdc_Ptr ti_sysbios_family_arm_cc26xx_Alarm_Object__next__S( xdc_Ptr obj );

/* Params__init__S */
xdc__CODESECT(ti_sysbios_family_arm_cc26xx_Alarm_Params__init__S, "ti_sysbios_family_arm_cc26xx_Alarm_Params__init__S")
__extern xdc_Void ti_sysbios_family_arm_cc26xx_Alarm_Params__init__S( xdc_Ptr dst, const xdc_Void *src, xdc_SizeT psz, xdc_SizeT isz );

/* getCount__E */
#define ti_sysbios_family_arm_cc26xx_Alarm_getCount ti_sysbios_family_arm_cc26xx_Alarm_getCount__E
xdc__CODESECT(ti_sysbios_family_arm_cc26xx_Alarm_getCount__E, "ti_sysbios_family_arm_cc26xx_Alarm_getCount")
__extern xdc_UInt64 ti_sysbios_family_arm_cc26xx_Alarm_getCount__E( void );

/* set__E */
#define ti_sysbios_family_arm_cc26xx_Alarm_set ti_sysbios_family_arm_cc26xx_Alarm_set__E
xdc__CODESECT(ti_sysbios_family_arm_cc26xx_Alarm_set__E, "ti_sysbios_family_arm_cc26xx_Alarm_set")
__extern xdc_Bool ti_sysbios_family_arm_cc26xx_Alarm_set__E( ti_sysbios_family_arm_cc26xx_Alarm_Handle __inst, xdc_UInt64 countRTC );

/* setFunc__E */
#define ti_sysbios_family_arm_cc26xx_Alarm_setFunc ti_sysbios_family_arm_cc26xx_Alarm_setFunc__E
xdc__CODESECT(ti_sysbios_family_arm_cc26xx_Alarm_setFunc__E, "ti_sysbios_family_arm_cc26xx_Alarm_setFunc")
__extern xdc_Void ti_sysbios_family_arm_cc26xx_Alarm_setFunc__E( ti_sysbios_family_arm_cc26xx_Alarm_Handle __inst, ti_sysbios_family_arm_cc26xx_Alarm_FuncPtr fxn, xdc_UArg arg );

/* stop__E */
#define ti_sysbios_family_arm_cc26xx_Alarm_stop ti_sysbios_family_arm_cc26xx_Alarm_stop__E
xdc__CODESECT(ti_sysbios_family_arm_cc26xx_Alarm_stop__E, "ti_sysbios_family_arm_cc26xx_Alarm_stop")
__extern xdc_Void ti_sysbios_family_arm_cc26xx_Alarm_stop__E( ti_sysbios_family_arm_cc26xx_Alarm_Handle __inst );


/*
 * ======== SYSTEM FUNCTIONS ========
 */

/* Module_startupDone */
#define ti_sysbios_family_arm_cc26xx_Alarm_Module_startupDone() ti_sysbios_family_arm_cc26xx_Alarm_Module__startupDone__S()

/* Object_heap */
#define ti_sysbios_family_arm_cc26xx_Alarm_Object_heap() ti_sysbios_family_arm_cc26xx_Alarm_Object__heap__C

/* Module_heap */
#define ti_sysbios_family_arm_cc26xx_Alarm_Module_heap() ti_sysbios_family_arm_cc26xx_Alarm_Object__heap__C

/* Module_id */
static inline CT__ti_sysbios_family_arm_cc26xx_Alarm_Module__id ti_sysbios_family_arm_cc26xx_Alarm_Module_id( void ) 
{
    return ti_sysbios_family_arm_cc26xx_Alarm_Module__id__C;
}

/* Module_hasMask */
static inline xdc_Bool ti_sysbios_family_arm_cc26xx_Alarm_Module_hasMask( void ) 
{
    return ti_sysbios_family_arm_cc26xx_Alarm_Module__diagsMask__C != NULL;
}

/* Module_getMask */
static inline xdc_Bits16 ti_sysbios_family_arm_cc26xx_Alarm_Module_getMask( void ) 
{
    return ti_sysbios_family_arm_cc26xx_Alarm_Module__diagsMask__C != NULL ? *ti_sysbios_family_arm_cc26xx_Alarm_Module__diagsMask__C : 0;
}

/* Module_setMask */
static inline xdc_Void ti_sysbios_family_arm_cc26xx_Alarm_Module_setMask( xdc_Bits16 mask ) 
{
    if (ti_sysbios_family_arm_cc26xx_Alarm_Module__diagsMask__C != NULL) *ti_sysbios_family_arm_cc26xx_Alarm_Module__diagsMask__C = mask;
}

/* Params_init */
static inline void ti_sysbios_family_arm_cc26xx_Alarm_Params_init( ti_sysbios_family_arm_cc26xx_Alarm_Params *prms ) 
{
    if (prms) {
        ti_sysbios_family_arm_cc26xx_Alarm_Params__init__S(prms, 0, sizeof(ti_sysbios_family_arm_cc26xx_Alarm_Params), sizeof(xdc_runtime_IInstance_Params));
    }
}

/* Params_copy */
static inline void ti_sysbios_family_arm_cc26xx_Alarm_Params_copy(ti_sysbios_family_arm_cc26xx_Alarm_Params *dst, const ti_sysbios_family_arm_cc26xx_Alarm_Params *src) 
{
    if (dst) {
        ti_sysbios_family_arm_cc26xx_Alarm_Params__init__S(dst, (const void *)src, sizeof(ti_sysbios_family_arm_cc26xx_Alarm_Params), sizeof(xdc_runtime_IInstance_Params));
    }
}

/* Object_count */
#define ti_sysbios_family_arm_cc26xx_Alarm_Object_count() ti_sysbios_family_arm_cc26xx_Alarm_Object__count__C

/* Object_sizeof */
#define ti_sysbios_family_arm_cc26xx_Alarm_Object_sizeof() ti_sysbios_family_arm_cc26xx_Alarm_Object__sizeof__C

/* Object_get */
static inline ti_sysbios_family_arm_cc26xx_Alarm_Handle ti_sysbios_family_arm_cc26xx_Alarm_Object_get(ti_sysbios_family_arm_cc26xx_Alarm_Instance_State *oarr, int i) 
{
    return (ti_sysbios_family_arm_cc26xx_Alarm_Handle)ti_sysbios_family_arm_cc26xx_Alarm_Object__get__S(oarr, i);
}

/* Object_first */
static inline ti_sysbios_family_arm_cc26xx_Alarm_Handle ti_sysbios_family_arm_cc26xx_Alarm_Object_first( void )
{
    return (ti_sysbios_family_arm_cc26xx_Alarm_Handle)ti_sysbios_family_arm_cc26xx_Alarm_Object__first__S();
}

/* Object_next */
static inline ti_sysbios_family_arm_cc26xx_Alarm_Handle ti_sysbios_family_arm_cc26xx_Alarm_Object_next( ti_sysbios_family_arm_cc26xx_Alarm_Object *obj )
{
    return (ti_sysbios_family_arm_cc26xx_Alarm_Handle)ti_sysbios_family_arm_cc26xx_Alarm_Object__next__S(obj);
}

/* Handle_label */
static inline xdc_runtime_Types_Label *ti_sysbios_family_arm_cc26xx_Alarm_Handle_label( ti_sysbios_family_arm_cc26xx_Alarm_Handle inst, xdc_runtime_Types_Label *lab )
{
    return ti_sysbios_family_arm_cc26xx_Alarm_Handle__label__S(inst, lab);
}

/* Handle_name */
static inline xdc_String ti_sysbios_family_arm_cc26xx_Alarm_Handle_name( ti_sysbios_family_arm_cc26xx_Alarm_Handle inst )
{
    xdc_runtime_Types_Label lab;
    return ti_sysbios_family_arm_cc26xx_Alarm_Handle__label__S(inst, &lab)->iname;
}

/* handle */
static inline ti_sysbios_family_arm_cc26xx_Alarm_Handle ti_sysbios_family_arm_cc26xx_Alarm_handle( ti_sysbios_family_arm_cc26xx_Alarm_Struct *str )
{
    return (ti_sysbios_family_arm_cc26xx_Alarm_Handle)str;
}

/* struct */
static inline ti_sysbios_family_arm_cc26xx_Alarm_Struct *ti_sysbios_family_arm_cc26xx_Alarm_struct( ti_sysbios_family_arm_cc26xx_Alarm_Handle inst )
{
    return (ti_sysbios_family_arm_cc26xx_Alarm_Struct*)inst;
}


/*
 * ======== EPILOGUE ========
 */

#ifdef ti_sysbios_family_arm_cc26xx_Alarm__top__
#undef __nested__
#endif

#endif /* ti_sysbios_family_arm_cc26xx_Alarm__include */


/*
 * ======== STATE STRUCTURES ========
 */

#if defined(__config__) || (!defined(__nested__) && defined(ti_sysbios_family_arm_cc26xx_Alarm__internalaccess))

#ifndef ti_sysbios_family_arm_cc26xx_Alarm__include_state
#define ti_sysbios_family_arm_cc26xx_Alarm__include_state

/* Object */
struct ti_sysbios_family_arm_cc26xx_Alarm_Object {
    xdc_UInt64 rtcCount;
    char __dummy;
};

/* Instance_State_clockObj */
__extern __FAR__ const xdc_SizeT ti_sysbios_family_arm_cc26xx_Alarm_Instance_State_clockObj__O;
static inline ti_sysbios_knl_Clock_Handle ti_sysbios_family_arm_cc26xx_Alarm_Instance_State_clockObj(ti_sysbios_family_arm_cc26xx_Alarm_Object *obj)
{
    return (ti_sysbios_knl_Clock_Handle)(((char*)obj) + ti_sysbios_family_arm_cc26xx_Alarm_Instance_State_clockObj__O);
}

#endif /* ti_sysbios_family_arm_cc26xx_Alarm__include_state */

#endif


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(ti_sysbios_family_arm_cc26xx_Alarm__nolocalnames)

#ifndef ti_sysbios_family_arm_cc26xx_Alarm__localnames__done
#define ti_sysbios_family_arm_cc26xx_Alarm__localnames__done

/* module prefix */
#define Alarm_Instance ti_sysbios_family_arm_cc26xx_Alarm_Instance
#define Alarm_Handle ti_sysbios_family_arm_cc26xx_Alarm_Handle
#define Alarm_Module ti_sysbios_family_arm_cc26xx_Alarm_Module
#define Alarm_Object ti_sysbios_family_arm_cc26xx_Alarm_Object
#define Alarm_Struct ti_sysbios_family_arm_cc26xx_Alarm_Struct
#define Alarm_FuncPtr ti_sysbios_family_arm_cc26xx_Alarm_FuncPtr
#define Alarm_Instance_State ti_sysbios_family_arm_cc26xx_Alarm_Instance_State
#define Alarm_Instance_State_clockObj ti_sysbios_family_arm_cc26xx_Alarm_Instance_State_clockObj
#define Alarm_Params ti_sysbios_family_arm_cc26xx_Alarm_Params
#define Alarm_getCount ti_sysbios_family_arm_cc26xx_Alarm_getCount
#define Alarm_set ti_sysbios_family_arm_cc26xx_Alarm_set
#define Alarm_setFunc ti_sysbios_family_arm_cc26xx_Alarm_setFunc
#define Alarm_stop ti_sysbios_family_arm_cc26xx_Alarm_stop
#define Alarm_Module_name ti_sysbios_family_arm_cc26xx_Alarm_Module_name
#define Alarm_Module_id ti_sysbios_family_arm_cc26xx_Alarm_Module_id
#define Alarm_Module_startup ti_sysbios_family_arm_cc26xx_Alarm_Module_startup
#define Alarm_Module_startupDone ti_sysbios_family_arm_cc26xx_Alarm_Module_startupDone
#define Alarm_Module_hasMask ti_sysbios_family_arm_cc26xx_Alarm_Module_hasMask
#define Alarm_Module_getMask ti_sysbios_family_arm_cc26xx_Alarm_Module_getMask
#define Alarm_Module_setMask ti_sysbios_family_arm_cc26xx_Alarm_Module_setMask
#define Alarm_Object_heap ti_sysbios_family_arm_cc26xx_Alarm_Object_heap
#define Alarm_Module_heap ti_sysbios_family_arm_cc26xx_Alarm_Module_heap
#define Alarm_construct ti_sysbios_family_arm_cc26xx_Alarm_construct
#define Alarm_create ti_sysbios_family_arm_cc26xx_Alarm_create
#define Alarm_handle ti_sysbios_family_arm_cc26xx_Alarm_handle
#define Alarm_struct ti_sysbios_family_arm_cc26xx_Alarm_struct
#define Alarm_Handle_label ti_sysbios_family_arm_cc26xx_Alarm_Handle_label
#define Alarm_Handle_name ti_sysbios_family_arm_cc26xx_Alarm_Handle_name
#define Alarm_Instance_init ti_sysbios_family_arm_cc26xx_Alarm_Instance_init
#define Alarm_Object_count ti_sysbios_family_arm_cc26xx_Alarm_Object_count
#define Alarm_Object_get ti_sysbios_family_arm_cc26xx_Alarm_Object_get
#define Alarm_Object_first ti_sysbios_family_arm_cc26xx_Alarm_Object_first
#define Alarm_Object_next ti_sysbios_family_arm_cc26xx_Alarm_Object_next
#define Alarm_Object_sizeof ti_sysbios_family_arm_cc26xx_Alarm_Object_sizeof
#define Alarm_Params_copy ti_sysbios_family_arm_cc26xx_Alarm_Params_copy
#define Alarm_Params_init ti_sysbios_family_arm_cc26xx_Alarm_Params_init
#define Alarm_Instance_finalize ti_sysbios_family_arm_cc26xx_Alarm_Instance_finalize
#define Alarm_delete ti_sysbios_family_arm_cc26xx_Alarm_delete
#define Alarm_destruct ti_sysbios_family_arm_cc26xx_Alarm_destruct

#endif /* ti_sysbios_family_arm_cc26xx_Alarm__localnames__done */
#endif
