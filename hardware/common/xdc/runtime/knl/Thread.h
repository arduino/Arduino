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

#ifndef xdc_runtime_knl_Thread__include
#define xdc_runtime_knl_Thread__include

#ifndef __nested__
#define __nested__
#define xdc_runtime_knl_Thread__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define xdc_runtime_knl_Thread___VERS 160


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/IInstance.h>
#include <xdc/runtime/knl/package/package.defs.h>

#include <xdc/runtime/Error.h>
#include <xdc/runtime/Assert.h>
#include <xdc/runtime/knl/IThreadSupport.h>
#include <xdc/runtime/IModule.h>
#include <xdc/runtime/knl/package/Thread_Proxy.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */

/* Priority */
enum xdc_runtime_knl_Thread_Priority {
    xdc_runtime_knl_Thread_Priority_INVALID,
    xdc_runtime_knl_Thread_Priority_LOWEST,
    xdc_runtime_knl_Thread_Priority_BELOW_NORMAL,
    xdc_runtime_knl_Thread_Priority_NORMAL,
    xdc_runtime_knl_Thread_Priority_ABOVE_NORMAL,
    xdc_runtime_knl_Thread_Priority_HIGHEST
};
typedef enum xdc_runtime_knl_Thread_Priority xdc_runtime_knl_Thread_Priority;

/* INVALID_OS_PRIORITY */
#define xdc_runtime_knl_Thread_INVALID_OS_PRIORITY (0)

/* GETPRI_FAILED */
#define xdc_runtime_knl_Thread_GETPRI_FAILED (-2)

/* CompStatus */
enum xdc_runtime_knl_Thread_CompStatus {
    xdc_runtime_knl_Thread_CompStatus_ERROR = -2,
    xdc_runtime_knl_Thread_CompStatus_LOWER = -1,
    xdc_runtime_knl_Thread_CompStatus_EQUAL = 0,
    xdc_runtime_knl_Thread_CompStatus_HIGHER = 1
};
typedef enum xdc_runtime_knl_Thread_CompStatus xdc_runtime_knl_Thread_CompStatus;

/* RunFxn */
typedef xdc_Void (*xdc_runtime_knl_Thread_RunFxn)(xdc_IArg);

/* Stat */
struct xdc_runtime_knl_Thread_Stat {
    xdc_SizeT stackSize;
    xdc_SizeT stackUsed;
};


/*
 * ======== CREATE ARGS ========
 */

/* Args__create */
typedef struct xdc_runtime_knl_Thread_Args__create {
    xdc_runtime_knl_Thread_RunFxn fxn;
} xdc_runtime_knl_Thread_Args__create;


/*
 * ======== INTERNAL DEFINITIONS ========
 */


/*
 * ======== MODULE-WIDE CONFIGS ========
 */

/* Module__diagsEnabled */
typedef xdc_Bits32 CT__xdc_runtime_knl_Thread_Module__diagsEnabled;
__extern __FAR__ const CT__xdc_runtime_knl_Thread_Module__diagsEnabled xdc_runtime_knl_Thread_Module__diagsEnabled__C;

/* Module__diagsIncluded */
typedef xdc_Bits32 CT__xdc_runtime_knl_Thread_Module__diagsIncluded;
__extern __FAR__ const CT__xdc_runtime_knl_Thread_Module__diagsIncluded xdc_runtime_knl_Thread_Module__diagsIncluded__C;

/* Module__diagsMask */
typedef xdc_Bits16 *CT__xdc_runtime_knl_Thread_Module__diagsMask;
__extern __FAR__ const CT__xdc_runtime_knl_Thread_Module__diagsMask xdc_runtime_knl_Thread_Module__diagsMask__C;

/* Module__gateObj */
typedef xdc_Ptr CT__xdc_runtime_knl_Thread_Module__gateObj;
__extern __FAR__ const CT__xdc_runtime_knl_Thread_Module__gateObj xdc_runtime_knl_Thread_Module__gateObj__C;

/* Module__gatePrms */
typedef xdc_Ptr CT__xdc_runtime_knl_Thread_Module__gatePrms;
__extern __FAR__ const CT__xdc_runtime_knl_Thread_Module__gatePrms xdc_runtime_knl_Thread_Module__gatePrms__C;

/* Module__id */
typedef xdc_runtime_Types_ModuleId CT__xdc_runtime_knl_Thread_Module__id;
__extern __FAR__ const CT__xdc_runtime_knl_Thread_Module__id xdc_runtime_knl_Thread_Module__id__C;

/* Module__loggerDefined */
typedef xdc_Bool CT__xdc_runtime_knl_Thread_Module__loggerDefined;
__extern __FAR__ const CT__xdc_runtime_knl_Thread_Module__loggerDefined xdc_runtime_knl_Thread_Module__loggerDefined__C;

/* Module__loggerObj */
typedef xdc_Ptr CT__xdc_runtime_knl_Thread_Module__loggerObj;
__extern __FAR__ const CT__xdc_runtime_knl_Thread_Module__loggerObj xdc_runtime_knl_Thread_Module__loggerObj__C;

/* Module__loggerFxn0 */
typedef xdc_runtime_Types_LoggerFxn0 CT__xdc_runtime_knl_Thread_Module__loggerFxn0;
__extern __FAR__ const CT__xdc_runtime_knl_Thread_Module__loggerFxn0 xdc_runtime_knl_Thread_Module__loggerFxn0__C;

/* Module__loggerFxn1 */
typedef xdc_runtime_Types_LoggerFxn1 CT__xdc_runtime_knl_Thread_Module__loggerFxn1;
__extern __FAR__ const CT__xdc_runtime_knl_Thread_Module__loggerFxn1 xdc_runtime_knl_Thread_Module__loggerFxn1__C;

/* Module__loggerFxn2 */
typedef xdc_runtime_Types_LoggerFxn2 CT__xdc_runtime_knl_Thread_Module__loggerFxn2;
__extern __FAR__ const CT__xdc_runtime_knl_Thread_Module__loggerFxn2 xdc_runtime_knl_Thread_Module__loggerFxn2__C;

/* Module__loggerFxn4 */
typedef xdc_runtime_Types_LoggerFxn4 CT__xdc_runtime_knl_Thread_Module__loggerFxn4;
__extern __FAR__ const CT__xdc_runtime_knl_Thread_Module__loggerFxn4 xdc_runtime_knl_Thread_Module__loggerFxn4__C;

/* Module__loggerFxn8 */
typedef xdc_runtime_Types_LoggerFxn8 CT__xdc_runtime_knl_Thread_Module__loggerFxn8;
__extern __FAR__ const CT__xdc_runtime_knl_Thread_Module__loggerFxn8 xdc_runtime_knl_Thread_Module__loggerFxn8__C;

/* Module__startupDoneFxn */
typedef xdc_Bool (*CT__xdc_runtime_knl_Thread_Module__startupDoneFxn)(void);
__extern __FAR__ const CT__xdc_runtime_knl_Thread_Module__startupDoneFxn xdc_runtime_knl_Thread_Module__startupDoneFxn__C;

/* Object__count */
typedef xdc_Int CT__xdc_runtime_knl_Thread_Object__count;
__extern __FAR__ const CT__xdc_runtime_knl_Thread_Object__count xdc_runtime_knl_Thread_Object__count__C;

/* Object__heap */
typedef xdc_runtime_IHeap_Handle CT__xdc_runtime_knl_Thread_Object__heap;
__extern __FAR__ const CT__xdc_runtime_knl_Thread_Object__heap xdc_runtime_knl_Thread_Object__heap__C;

/* Object__sizeof */
typedef xdc_SizeT CT__xdc_runtime_knl_Thread_Object__sizeof;
__extern __FAR__ const CT__xdc_runtime_knl_Thread_Object__sizeof xdc_runtime_knl_Thread_Object__sizeof__C;

/* Object__table */
typedef xdc_Ptr CT__xdc_runtime_knl_Thread_Object__table;
__extern __FAR__ const CT__xdc_runtime_knl_Thread_Object__table xdc_runtime_knl_Thread_Object__table__C;

/* A_zeroTimeout */
#define xdc_runtime_knl_Thread_A_zeroTimeout (xdc_runtime_knl_Thread_A_zeroTimeout__C)
typedef xdc_runtime_Assert_Id CT__xdc_runtime_knl_Thread_A_zeroTimeout;
__extern __FAR__ const CT__xdc_runtime_knl_Thread_A_zeroTimeout xdc_runtime_knl_Thread_A_zeroTimeout__C;

/* defaultStackSize */
#ifdef xdc_runtime_knl_Thread_defaultStackSize__D
#define xdc_runtime_knl_Thread_defaultStackSize (xdc_runtime_knl_Thread_defaultStackSize__D)
#else
#define xdc_runtime_knl_Thread_defaultStackSize (xdc_runtime_knl_Thread_defaultStackSize__C)
typedef xdc_SizeT CT__xdc_runtime_knl_Thread_defaultStackSize;
__extern __FAR__ const CT__xdc_runtime_knl_Thread_defaultStackSize xdc_runtime_knl_Thread_defaultStackSize__C;
#endif


/*
 * ======== PER-INSTANCE TYPES ========
 */

/* Params */
struct xdc_runtime_knl_Thread_Params {
    size_t __size;
    const void *__self;
    void *__fxns;
    xdc_runtime_IInstance_Params *instance;
    xdc_IArg arg;
    xdc_runtime_knl_Thread_Priority priority;
    xdc_Int osPriority;
    xdc_SizeT stackSize;
    xdc_Ptr tls;
    xdc_runtime_IInstance_Params __iprms;
};

/* Struct */
struct xdc_runtime_knl_Thread_Struct {
    xdc_runtime_knl_Thread_Proxy_Handle __f0;
    xdc_Ptr __f1;
    xdc_runtime_Types_CordAddr __name;
};


/*
 * ======== FUNCTION DECLARATIONS ========
 */

/* Module_startup */
#define xdc_runtime_knl_Thread_Module_startup( state ) (-1)

/* Instance_init__E */
xdc__CODESECT(xdc_runtime_knl_Thread_Instance_init__E, "xdc_runtime_knl_Thread_Instance_init")
__extern xdc_Int xdc_runtime_knl_Thread_Instance_init__E(xdc_runtime_knl_Thread_Object *, xdc_runtime_knl_Thread_RunFxn fxn, const xdc_runtime_knl_Thread_Params *, xdc_runtime_Error_Block *);

/* Instance_finalize__E */
xdc__CODESECT(xdc_runtime_knl_Thread_Instance_finalize__E, "xdc_runtime_knl_Thread_Instance_finalize")
__extern void xdc_runtime_knl_Thread_Instance_finalize__E( xdc_runtime_knl_Thread_Object* , int );

/* Handle__label__S */
xdc__CODESECT(xdc_runtime_knl_Thread_Handle__label__S, "xdc_runtime_knl_Thread_Handle__label__S")
__extern xdc_runtime_Types_Label *xdc_runtime_knl_Thread_Handle__label__S( xdc_Ptr obj, xdc_runtime_Types_Label *lab );

/* Module__startupDone__S */
xdc__CODESECT(xdc_runtime_knl_Thread_Module__startupDone__S, "xdc_runtime_knl_Thread_Module__startupDone__S")
__extern xdc_Bool xdc_runtime_knl_Thread_Module__startupDone__S( void );

/* Object__create__S */
xdc__CODESECT(xdc_runtime_knl_Thread_Object__create__S, "xdc_runtime_knl_Thread_Object__create__S")
__extern xdc_Ptr xdc_runtime_knl_Thread_Object__create__S( xdc_Ptr __oa, xdc_SizeT __osz, xdc_Ptr __aa, const xdc_UChar *__pa, xdc_SizeT __psz, xdc_runtime_Error_Block *__eb );

/* create */
xdc__CODESECT(xdc_runtime_knl_Thread_create, "xdc_runtime_knl_Thread_create")
__extern xdc_runtime_knl_Thread_Handle xdc_runtime_knl_Thread_create( xdc_runtime_knl_Thread_RunFxn fxn, const xdc_runtime_knl_Thread_Params *__prms, xdc_runtime_Error_Block *__eb );

/* construct */
xdc__CODESECT(xdc_runtime_knl_Thread_construct, "xdc_runtime_knl_Thread_construct")
__extern void xdc_runtime_knl_Thread_construct( xdc_runtime_knl_Thread_Struct *__obj, xdc_runtime_knl_Thread_RunFxn fxn, const xdc_runtime_knl_Thread_Params *__prms, xdc_runtime_Error_Block *__eb );

/* Object__delete__S */
xdc__CODESECT(xdc_runtime_knl_Thread_Object__delete__S, "xdc_runtime_knl_Thread_Object__delete__S")
__extern xdc_Void xdc_runtime_knl_Thread_Object__delete__S( xdc_Ptr instp );

/* delete */
xdc__CODESECT(xdc_runtime_knl_Thread_delete, "xdc_runtime_knl_Thread_delete")
__extern void xdc_runtime_knl_Thread_delete(xdc_runtime_knl_Thread_Handle *instp);

/* Object__destruct__S */
xdc__CODESECT(xdc_runtime_knl_Thread_Object__destruct__S, "xdc_runtime_knl_Thread_Object__destruct__S")
__extern xdc_Void xdc_runtime_knl_Thread_Object__destruct__S( xdc_Ptr objp );

/* destruct */
xdc__CODESECT(xdc_runtime_knl_Thread_destruct, "xdc_runtime_knl_Thread_destruct")
__extern void xdc_runtime_knl_Thread_destruct(xdc_runtime_knl_Thread_Struct *obj);

/* Object__get__S */
xdc__CODESECT(xdc_runtime_knl_Thread_Object__get__S, "xdc_runtime_knl_Thread_Object__get__S")
__extern xdc_Ptr xdc_runtime_knl_Thread_Object__get__S( xdc_Ptr oarr, xdc_Int i );

/* Object__first__S */
xdc__CODESECT(xdc_runtime_knl_Thread_Object__first__S, "xdc_runtime_knl_Thread_Object__first__S")
__extern xdc_Ptr xdc_runtime_knl_Thread_Object__first__S( void );

/* Object__next__S */
xdc__CODESECT(xdc_runtime_knl_Thread_Object__next__S, "xdc_runtime_knl_Thread_Object__next__S")
__extern xdc_Ptr xdc_runtime_knl_Thread_Object__next__S( xdc_Ptr obj );

/* Params__init__S */
xdc__CODESECT(xdc_runtime_knl_Thread_Params__init__S, "xdc_runtime_knl_Thread_Params__init__S")
__extern xdc_Void xdc_runtime_knl_Thread_Params__init__S( xdc_Ptr dst, const xdc_Void *src, xdc_SizeT psz, xdc_SizeT isz );

/* self__E */
#define xdc_runtime_knl_Thread_self xdc_runtime_knl_Thread_self__E
xdc__CODESECT(xdc_runtime_knl_Thread_self__E, "xdc_runtime_knl_Thread_self")
__extern xdc_runtime_knl_Thread_Handle xdc_runtime_knl_Thread_self__E( xdc_runtime_Error_Block *eb );

/* start__E */
#define xdc_runtime_knl_Thread_start xdc_runtime_knl_Thread_start__E
xdc__CODESECT(xdc_runtime_knl_Thread_start__E, "xdc_runtime_knl_Thread_start")
__extern xdc_Bool xdc_runtime_knl_Thread_start__E( xdc_runtime_Error_Block *eb );

/* yield__E */
#define xdc_runtime_knl_Thread_yield xdc_runtime_knl_Thread_yield__E
xdc__CODESECT(xdc_runtime_knl_Thread_yield__E, "xdc_runtime_knl_Thread_yield")
__extern xdc_Bool xdc_runtime_knl_Thread_yield__E( xdc_runtime_Error_Block *eb );

/* compareOsPriorities__E */
#define xdc_runtime_knl_Thread_compareOsPriorities xdc_runtime_knl_Thread_compareOsPriorities__E
xdc__CODESECT(xdc_runtime_knl_Thread_compareOsPriorities__E, "xdc_runtime_knl_Thread_compareOsPriorities")
__extern xdc_Int xdc_runtime_knl_Thread_compareOsPriorities__E( xdc_Int p1, xdc_Int p2, xdc_runtime_Error_Block *eb );

/* sleep__E */
#define xdc_runtime_knl_Thread_sleep xdc_runtime_knl_Thread_sleep__E
xdc__CODESECT(xdc_runtime_knl_Thread_sleep__E, "xdc_runtime_knl_Thread_sleep")
__extern xdc_Bool xdc_runtime_knl_Thread_sleep__E( xdc_UInt timeout, xdc_runtime_Error_Block *eb );

/* join__E */
#define xdc_runtime_knl_Thread_join xdc_runtime_knl_Thread_join__E
xdc__CODESECT(xdc_runtime_knl_Thread_join__E, "xdc_runtime_knl_Thread_join")
__extern xdc_Bool xdc_runtime_knl_Thread_join__E( xdc_runtime_knl_Thread_Handle __inst, xdc_runtime_Error_Block *eb );

/* getPriority__E */
#define xdc_runtime_knl_Thread_getPriority xdc_runtime_knl_Thread_getPriority__E
xdc__CODESECT(xdc_runtime_knl_Thread_getPriority__E, "xdc_runtime_knl_Thread_getPriority")
__extern xdc_runtime_knl_Thread_Priority xdc_runtime_knl_Thread_getPriority__E( xdc_runtime_knl_Thread_Handle __inst, xdc_runtime_Error_Block *eb );

/* setPriority__E */
#define xdc_runtime_knl_Thread_setPriority xdc_runtime_knl_Thread_setPriority__E
xdc__CODESECT(xdc_runtime_knl_Thread_setPriority__E, "xdc_runtime_knl_Thread_setPriority")
__extern xdc_Bool xdc_runtime_knl_Thread_setPriority__E( xdc_runtime_knl_Thread_Handle __inst, xdc_runtime_knl_Thread_Priority newPri, xdc_runtime_Error_Block *eb );

/* getOsPriority__E */
#define xdc_runtime_knl_Thread_getOsPriority xdc_runtime_knl_Thread_getOsPriority__E
xdc__CODESECT(xdc_runtime_knl_Thread_getOsPriority__E, "xdc_runtime_knl_Thread_getOsPriority")
__extern xdc_Int xdc_runtime_knl_Thread_getOsPriority__E( xdc_runtime_knl_Thread_Handle __inst, xdc_runtime_Error_Block *eb );

/* setOsPriority__E */
#define xdc_runtime_knl_Thread_setOsPriority xdc_runtime_knl_Thread_setOsPriority__E
xdc__CODESECT(xdc_runtime_knl_Thread_setOsPriority__E, "xdc_runtime_knl_Thread_setOsPriority")
__extern xdc_Bool xdc_runtime_knl_Thread_setOsPriority__E( xdc_runtime_knl_Thread_Handle __inst, xdc_Int newPri, xdc_runtime_Error_Block *eb );

/* getOsHandle__E */
#define xdc_runtime_knl_Thread_getOsHandle xdc_runtime_knl_Thread_getOsHandle__E
xdc__CODESECT(xdc_runtime_knl_Thread_getOsHandle__E, "xdc_runtime_knl_Thread_getOsHandle")
__extern xdc_Ptr xdc_runtime_knl_Thread_getOsHandle__E( xdc_runtime_knl_Thread_Handle __inst );

/* getTls__E */
#define xdc_runtime_knl_Thread_getTls xdc_runtime_knl_Thread_getTls__E
xdc__CODESECT(xdc_runtime_knl_Thread_getTls__E, "xdc_runtime_knl_Thread_getTls")
__extern xdc_Ptr xdc_runtime_knl_Thread_getTls__E( xdc_runtime_knl_Thread_Handle __inst );

/* setTls__E */
#define xdc_runtime_knl_Thread_setTls xdc_runtime_knl_Thread_setTls__E
xdc__CODESECT(xdc_runtime_knl_Thread_setTls__E, "xdc_runtime_knl_Thread_setTls")
__extern xdc_Void xdc_runtime_knl_Thread_setTls__E( xdc_runtime_knl_Thread_Handle __inst, xdc_Ptr tls );

/* stat__E */
#define xdc_runtime_knl_Thread_stat xdc_runtime_knl_Thread_stat__E
xdc__CODESECT(xdc_runtime_knl_Thread_stat__E, "xdc_runtime_knl_Thread_stat")
__extern xdc_Bool xdc_runtime_knl_Thread_stat__E( xdc_runtime_knl_Thread_Handle __inst, xdc_runtime_knl_Thread_Stat *buf, xdc_runtime_Error_Block *eb );


/*
 * ======== SYSTEM FUNCTIONS ========
 */

/* Module_startupDone */
#define xdc_runtime_knl_Thread_Module_startupDone() xdc_runtime_knl_Thread_Module__startupDone__S()

/* Object_heap */
#define xdc_runtime_knl_Thread_Object_heap() xdc_runtime_knl_Thread_Object__heap__C

/* Module_heap */
#define xdc_runtime_knl_Thread_Module_heap() xdc_runtime_knl_Thread_Object__heap__C

/* Module_id */
static inline CT__xdc_runtime_knl_Thread_Module__id xdc_runtime_knl_Thread_Module_id( void ) 
{
    return xdc_runtime_knl_Thread_Module__id__C;
}

/* Module_hasMask */
static inline xdc_Bool xdc_runtime_knl_Thread_Module_hasMask( void ) 
{
    return xdc_runtime_knl_Thread_Module__diagsMask__C != NULL;
}

/* Module_getMask */
static inline xdc_Bits16 xdc_runtime_knl_Thread_Module_getMask( void ) 
{
    return xdc_runtime_knl_Thread_Module__diagsMask__C != NULL ? *xdc_runtime_knl_Thread_Module__diagsMask__C : 0;
}

/* Module_setMask */
static inline xdc_Void xdc_runtime_knl_Thread_Module_setMask( xdc_Bits16 mask ) 
{
    if (xdc_runtime_knl_Thread_Module__diagsMask__C != NULL) *xdc_runtime_knl_Thread_Module__diagsMask__C = mask;
}

/* Params_init */
static inline void xdc_runtime_knl_Thread_Params_init( xdc_runtime_knl_Thread_Params *prms ) 
{
    if (prms) {
        xdc_runtime_knl_Thread_Params__init__S(prms, 0, sizeof(xdc_runtime_knl_Thread_Params), sizeof(xdc_runtime_IInstance_Params));
    }
}

/* Params_copy */
static inline void xdc_runtime_knl_Thread_Params_copy(xdc_runtime_knl_Thread_Params *dst, const xdc_runtime_knl_Thread_Params *src) 
{
    if (dst) {
        xdc_runtime_knl_Thread_Params__init__S(dst, (const void *)src, sizeof(xdc_runtime_knl_Thread_Params), sizeof(xdc_runtime_IInstance_Params));
    }
}

/* Object_count */
#define xdc_runtime_knl_Thread_Object_count() xdc_runtime_knl_Thread_Object__count__C

/* Object_sizeof */
#define xdc_runtime_knl_Thread_Object_sizeof() xdc_runtime_knl_Thread_Object__sizeof__C

/* Object_get */
static inline xdc_runtime_knl_Thread_Handle xdc_runtime_knl_Thread_Object_get(xdc_runtime_knl_Thread_Instance_State *oarr, int i) 
{
    return (xdc_runtime_knl_Thread_Handle)xdc_runtime_knl_Thread_Object__get__S(oarr, i);
}

/* Object_first */
static inline xdc_runtime_knl_Thread_Handle xdc_runtime_knl_Thread_Object_first( void )
{
    return (xdc_runtime_knl_Thread_Handle)xdc_runtime_knl_Thread_Object__first__S();
}

/* Object_next */
static inline xdc_runtime_knl_Thread_Handle xdc_runtime_knl_Thread_Object_next( xdc_runtime_knl_Thread_Object *obj )
{
    return (xdc_runtime_knl_Thread_Handle)xdc_runtime_knl_Thread_Object__next__S(obj);
}

/* Handle_label */
static inline xdc_runtime_Types_Label *xdc_runtime_knl_Thread_Handle_label( xdc_runtime_knl_Thread_Handle inst, xdc_runtime_Types_Label *lab )
{
    return xdc_runtime_knl_Thread_Handle__label__S(inst, lab);
}

/* Handle_name */
static inline xdc_String xdc_runtime_knl_Thread_Handle_name( xdc_runtime_knl_Thread_Handle inst )
{
    xdc_runtime_Types_Label lab;
    return xdc_runtime_knl_Thread_Handle__label__S(inst, &lab)->iname;
}

/* handle */
static inline xdc_runtime_knl_Thread_Handle xdc_runtime_knl_Thread_handle( xdc_runtime_knl_Thread_Struct *str )
{
    return (xdc_runtime_knl_Thread_Handle)str;
}

/* struct */
static inline xdc_runtime_knl_Thread_Struct *xdc_runtime_knl_Thread_struct( xdc_runtime_knl_Thread_Handle inst )
{
    return (xdc_runtime_knl_Thread_Struct*)inst;
}


/*
 * ======== EPILOGUE ========
 */

#ifdef xdc_runtime_knl_Thread__top__
#undef __nested__
#endif

#endif /* xdc_runtime_knl_Thread__include */


/*
 * ======== STATE STRUCTURES ========
 */

#if defined(__config__) || (!defined(__nested__) && defined(xdc_runtime_knl_Thread__internalaccess))

#ifndef xdc_runtime_knl_Thread__include_state
#define xdc_runtime_knl_Thread__include_state

/* Object */
struct xdc_runtime_knl_Thread_Object {
    xdc_runtime_knl_Thread_Proxy_Handle proxyHandle;
    xdc_Ptr tls;
};

#endif /* xdc_runtime_knl_Thread__include_state */

#endif


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(xdc_runtime_knl_Thread__nolocalnames)

#ifndef xdc_runtime_knl_Thread__localnames__done
#define xdc_runtime_knl_Thread__localnames__done

/* module prefix */
#define Thread_Instance xdc_runtime_knl_Thread_Instance
#define Thread_Handle xdc_runtime_knl_Thread_Handle
#define Thread_Module xdc_runtime_knl_Thread_Module
#define Thread_Object xdc_runtime_knl_Thread_Object
#define Thread_Struct xdc_runtime_knl_Thread_Struct
#define Thread_Priority xdc_runtime_knl_Thread_Priority
#define Thread_INVALID_OS_PRIORITY xdc_runtime_knl_Thread_INVALID_OS_PRIORITY
#define Thread_GETPRI_FAILED xdc_runtime_knl_Thread_GETPRI_FAILED
#define Thread_CompStatus xdc_runtime_knl_Thread_CompStatus
#define Thread_RunFxn xdc_runtime_knl_Thread_RunFxn
#define Thread_Stat xdc_runtime_knl_Thread_Stat
#define Thread_Instance_State xdc_runtime_knl_Thread_Instance_State
#define Thread_Priority_INVALID xdc_runtime_knl_Thread_Priority_INVALID
#define Thread_Priority_LOWEST xdc_runtime_knl_Thread_Priority_LOWEST
#define Thread_Priority_BELOW_NORMAL xdc_runtime_knl_Thread_Priority_BELOW_NORMAL
#define Thread_Priority_NORMAL xdc_runtime_knl_Thread_Priority_NORMAL
#define Thread_Priority_ABOVE_NORMAL xdc_runtime_knl_Thread_Priority_ABOVE_NORMAL
#define Thread_Priority_HIGHEST xdc_runtime_knl_Thread_Priority_HIGHEST
#define Thread_CompStatus_ERROR xdc_runtime_knl_Thread_CompStatus_ERROR
#define Thread_CompStatus_LOWER xdc_runtime_knl_Thread_CompStatus_LOWER
#define Thread_CompStatus_EQUAL xdc_runtime_knl_Thread_CompStatus_EQUAL
#define Thread_CompStatus_HIGHER xdc_runtime_knl_Thread_CompStatus_HIGHER
#define Thread_A_zeroTimeout xdc_runtime_knl_Thread_A_zeroTimeout
#define Thread_defaultStackSize xdc_runtime_knl_Thread_defaultStackSize
#define Thread_Params xdc_runtime_knl_Thread_Params
#define Thread_self xdc_runtime_knl_Thread_self
#define Thread_start xdc_runtime_knl_Thread_start
#define Thread_yield xdc_runtime_knl_Thread_yield
#define Thread_compareOsPriorities xdc_runtime_knl_Thread_compareOsPriorities
#define Thread_sleep xdc_runtime_knl_Thread_sleep
#define Thread_join xdc_runtime_knl_Thread_join
#define Thread_getPriority xdc_runtime_knl_Thread_getPriority
#define Thread_setPriority xdc_runtime_knl_Thread_setPriority
#define Thread_getOsPriority xdc_runtime_knl_Thread_getOsPriority
#define Thread_setOsPriority xdc_runtime_knl_Thread_setOsPriority
#define Thread_getOsHandle xdc_runtime_knl_Thread_getOsHandle
#define Thread_getTls xdc_runtime_knl_Thread_getTls
#define Thread_setTls xdc_runtime_knl_Thread_setTls
#define Thread_stat xdc_runtime_knl_Thread_stat
#define Thread_Module_name xdc_runtime_knl_Thread_Module_name
#define Thread_Module_id xdc_runtime_knl_Thread_Module_id
#define Thread_Module_startup xdc_runtime_knl_Thread_Module_startup
#define Thread_Module_startupDone xdc_runtime_knl_Thread_Module_startupDone
#define Thread_Module_hasMask xdc_runtime_knl_Thread_Module_hasMask
#define Thread_Module_getMask xdc_runtime_knl_Thread_Module_getMask
#define Thread_Module_setMask xdc_runtime_knl_Thread_Module_setMask
#define Thread_Object_heap xdc_runtime_knl_Thread_Object_heap
#define Thread_Module_heap xdc_runtime_knl_Thread_Module_heap
#define Thread_construct xdc_runtime_knl_Thread_construct
#define Thread_create xdc_runtime_knl_Thread_create
#define Thread_handle xdc_runtime_knl_Thread_handle
#define Thread_struct xdc_runtime_knl_Thread_struct
#define Thread_Handle_label xdc_runtime_knl_Thread_Handle_label
#define Thread_Handle_name xdc_runtime_knl_Thread_Handle_name
#define Thread_Instance_init xdc_runtime_knl_Thread_Instance_init
#define Thread_Object_count xdc_runtime_knl_Thread_Object_count
#define Thread_Object_get xdc_runtime_knl_Thread_Object_get
#define Thread_Object_first xdc_runtime_knl_Thread_Object_first
#define Thread_Object_next xdc_runtime_knl_Thread_Object_next
#define Thread_Object_sizeof xdc_runtime_knl_Thread_Object_sizeof
#define Thread_Params_copy xdc_runtime_knl_Thread_Params_copy
#define Thread_Params_init xdc_runtime_knl_Thread_Params_init
#define Thread_Instance_finalize xdc_runtime_knl_Thread_Instance_finalize
#define Thread_delete xdc_runtime_knl_Thread_delete
#define Thread_destruct xdc_runtime_knl_Thread_destruct

/* proxies */
#include <xdc/runtime/knl/package/Thread_Proxy.h>

#endif /* xdc_runtime_knl_Thread__localnames__done */
#endif
/*
 *  @(#) xdc.runtime.knl; 1, 0, 0,0; 4-24-2015 12:34:17; /db/ztree/library/trees/xdc/xdc-A71/src/packages/
 */

