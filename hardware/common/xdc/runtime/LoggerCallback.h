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

#ifndef xdc_runtime_LoggerCallback__include
#define xdc_runtime_LoggerCallback__include

#ifndef __nested__
#define __nested__
#define xdc_runtime_LoggerCallback__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define xdc_runtime_LoggerCallback___VERS 160


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/IInstance.h>
#include <xdc/runtime/package/package.defs.h>

#include <xdc/runtime/ILogger.h>
#include <xdc/runtime/Log.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */

/* OutputFxn */
typedef xdc_Void (*xdc_runtime_LoggerCallback_OutputFxn)(xdc_UArg, xdc_runtime_Log_EventRec*, xdc_Int);

/* CreateInstFxn */
typedef xdc_UArg (*xdc_runtime_LoggerCallback_CreateInstFxn)(xdc_UArg);


/*
 * ======== INTERNAL DEFINITIONS ========
 */


/*
 * ======== MODULE-WIDE CONFIGS ========
 */

/* Module__diagsEnabled */
typedef xdc_Bits32 CT__xdc_runtime_LoggerCallback_Module__diagsEnabled;
__extern __FAR__ const CT__xdc_runtime_LoggerCallback_Module__diagsEnabled xdc_runtime_LoggerCallback_Module__diagsEnabled__C;

/* Module__diagsIncluded */
typedef xdc_Bits32 CT__xdc_runtime_LoggerCallback_Module__diagsIncluded;
__extern __FAR__ const CT__xdc_runtime_LoggerCallback_Module__diagsIncluded xdc_runtime_LoggerCallback_Module__diagsIncluded__C;

/* Module__diagsMask */
typedef xdc_Bits16 *CT__xdc_runtime_LoggerCallback_Module__diagsMask;
__extern __FAR__ const CT__xdc_runtime_LoggerCallback_Module__diagsMask xdc_runtime_LoggerCallback_Module__diagsMask__C;

/* Module__gateObj */
typedef xdc_Ptr CT__xdc_runtime_LoggerCallback_Module__gateObj;
__extern __FAR__ const CT__xdc_runtime_LoggerCallback_Module__gateObj xdc_runtime_LoggerCallback_Module__gateObj__C;

/* Module__gatePrms */
typedef xdc_Ptr CT__xdc_runtime_LoggerCallback_Module__gatePrms;
__extern __FAR__ const CT__xdc_runtime_LoggerCallback_Module__gatePrms xdc_runtime_LoggerCallback_Module__gatePrms__C;

/* Module__id */
typedef xdc_runtime_Types_ModuleId CT__xdc_runtime_LoggerCallback_Module__id;
__extern __FAR__ const CT__xdc_runtime_LoggerCallback_Module__id xdc_runtime_LoggerCallback_Module__id__C;

/* Module__loggerDefined */
typedef xdc_Bool CT__xdc_runtime_LoggerCallback_Module__loggerDefined;
__extern __FAR__ const CT__xdc_runtime_LoggerCallback_Module__loggerDefined xdc_runtime_LoggerCallback_Module__loggerDefined__C;

/* Module__loggerObj */
typedef xdc_Ptr CT__xdc_runtime_LoggerCallback_Module__loggerObj;
__extern __FAR__ const CT__xdc_runtime_LoggerCallback_Module__loggerObj xdc_runtime_LoggerCallback_Module__loggerObj__C;

/* Module__loggerFxn0 */
typedef xdc_runtime_Types_LoggerFxn0 CT__xdc_runtime_LoggerCallback_Module__loggerFxn0;
__extern __FAR__ const CT__xdc_runtime_LoggerCallback_Module__loggerFxn0 xdc_runtime_LoggerCallback_Module__loggerFxn0__C;

/* Module__loggerFxn1 */
typedef xdc_runtime_Types_LoggerFxn1 CT__xdc_runtime_LoggerCallback_Module__loggerFxn1;
__extern __FAR__ const CT__xdc_runtime_LoggerCallback_Module__loggerFxn1 xdc_runtime_LoggerCallback_Module__loggerFxn1__C;

/* Module__loggerFxn2 */
typedef xdc_runtime_Types_LoggerFxn2 CT__xdc_runtime_LoggerCallback_Module__loggerFxn2;
__extern __FAR__ const CT__xdc_runtime_LoggerCallback_Module__loggerFxn2 xdc_runtime_LoggerCallback_Module__loggerFxn2__C;

/* Module__loggerFxn4 */
typedef xdc_runtime_Types_LoggerFxn4 CT__xdc_runtime_LoggerCallback_Module__loggerFxn4;
__extern __FAR__ const CT__xdc_runtime_LoggerCallback_Module__loggerFxn4 xdc_runtime_LoggerCallback_Module__loggerFxn4__C;

/* Module__loggerFxn8 */
typedef xdc_runtime_Types_LoggerFxn8 CT__xdc_runtime_LoggerCallback_Module__loggerFxn8;
__extern __FAR__ const CT__xdc_runtime_LoggerCallback_Module__loggerFxn8 xdc_runtime_LoggerCallback_Module__loggerFxn8__C;

/* Module__startupDoneFxn */
typedef xdc_Bool (*CT__xdc_runtime_LoggerCallback_Module__startupDoneFxn)(void);
__extern __FAR__ const CT__xdc_runtime_LoggerCallback_Module__startupDoneFxn xdc_runtime_LoggerCallback_Module__startupDoneFxn__C;

/* Object__count */
typedef xdc_Int CT__xdc_runtime_LoggerCallback_Object__count;
__extern __FAR__ const CT__xdc_runtime_LoggerCallback_Object__count xdc_runtime_LoggerCallback_Object__count__C;

/* Object__heap */
typedef xdc_runtime_IHeap_Handle CT__xdc_runtime_LoggerCallback_Object__heap;
__extern __FAR__ const CT__xdc_runtime_LoggerCallback_Object__heap xdc_runtime_LoggerCallback_Object__heap__C;

/* Object__sizeof */
typedef xdc_SizeT CT__xdc_runtime_LoggerCallback_Object__sizeof;
__extern __FAR__ const CT__xdc_runtime_LoggerCallback_Object__sizeof xdc_runtime_LoggerCallback_Object__sizeof__C;

/* Object__table */
typedef xdc_Ptr CT__xdc_runtime_LoggerCallback_Object__table;
__extern __FAR__ const CT__xdc_runtime_LoggerCallback_Object__table xdc_runtime_LoggerCallback_Object__table__C;

/* outputFxn */
#define xdc_runtime_LoggerCallback_outputFxn (xdc_runtime_LoggerCallback_outputFxn__C)
typedef xdc_runtime_LoggerCallback_OutputFxn CT__xdc_runtime_LoggerCallback_outputFxn;
__extern __FAR__ const CT__xdc_runtime_LoggerCallback_outputFxn xdc_runtime_LoggerCallback_outputFxn__C;

/* createInstFxn */
#define xdc_runtime_LoggerCallback_createInstFxn (xdc_runtime_LoggerCallback_createInstFxn__C)
typedef xdc_runtime_LoggerCallback_CreateInstFxn CT__xdc_runtime_LoggerCallback_createInstFxn;
__extern __FAR__ const CT__xdc_runtime_LoggerCallback_createInstFxn xdc_runtime_LoggerCallback_createInstFxn__C;


/*
 * ======== PER-INSTANCE TYPES ========
 */

/* Params */
struct xdc_runtime_LoggerCallback_Params {
    size_t __size;
    const void *__self;
    void *__fxns;
    xdc_runtime_IInstance_Params *instance;
    xdc_UArg arg;
    xdc_runtime_IInstance_Params __iprms;
};

/* Struct */
struct xdc_runtime_LoggerCallback_Struct {
    const xdc_runtime_LoggerCallback_Fxns__ *__fxns;
    xdc_Bool __f0;
    xdc_UArg __f1;
    xdc_UArg __f2;
    xdc_runtime_Types_CordAddr __name;
};


/*
 * ======== VIRTUAL FUNCTIONS ========
 */

/* Fxns__ */
struct xdc_runtime_LoggerCallback_Fxns__ {
    xdc_runtime_Types_Base* __base;
    const xdc_runtime_Types_SysFxns2 *__sysp;
    xdc_Bool (*enable)(xdc_runtime_LoggerCallback_Handle);
    xdc_Bool (*disable)(xdc_runtime_LoggerCallback_Handle);
    xdc_Void (*write0)(xdc_runtime_LoggerCallback_Handle, xdc_runtime_Log_Event, xdc_runtime_Types_ModuleId);
    xdc_Void (*write1)(xdc_runtime_LoggerCallback_Handle, xdc_runtime_Log_Event, xdc_runtime_Types_ModuleId, xdc_IArg);
    xdc_Void (*write2)(xdc_runtime_LoggerCallback_Handle, xdc_runtime_Log_Event, xdc_runtime_Types_ModuleId, xdc_IArg, xdc_IArg);
    xdc_Void (*write4)(xdc_runtime_LoggerCallback_Handle, xdc_runtime_Log_Event, xdc_runtime_Types_ModuleId, xdc_IArg, xdc_IArg, xdc_IArg, xdc_IArg);
    xdc_Void (*write8)(xdc_runtime_LoggerCallback_Handle, xdc_runtime_Log_Event, xdc_runtime_Types_ModuleId, xdc_IArg, xdc_IArg, xdc_IArg, xdc_IArg, xdc_IArg, xdc_IArg, xdc_IArg, xdc_IArg);
    xdc_runtime_Types_SysFxns2 __sfxns;
};

/* Module__FXNS__C */
__extern const xdc_runtime_LoggerCallback_Fxns__ xdc_runtime_LoggerCallback_Module__FXNS__C;


/*
 * ======== FUNCTION DECLARATIONS ========
 */

/* Module_startup */
#define xdc_runtime_LoggerCallback_Module_startup xdc_runtime_LoggerCallback_Module_startup__E
xdc__CODESECT(xdc_runtime_LoggerCallback_Module_startup__E, "xdc_runtime_LoggerCallback_Module_startup")
__extern xdc_Int xdc_runtime_LoggerCallback_Module_startup__E( xdc_Int state );
xdc__CODESECT(xdc_runtime_LoggerCallback_Module_startup__F, "xdc_runtime_LoggerCallback_Module_startup")
__extern xdc_Int xdc_runtime_LoggerCallback_Module_startup__F( xdc_Int state );

/* Instance_init__E */
xdc__CODESECT(xdc_runtime_LoggerCallback_Instance_init__E, "xdc_runtime_LoggerCallback_Instance_init")
__extern xdc_Void xdc_runtime_LoggerCallback_Instance_init__E(xdc_runtime_LoggerCallback_Object *, const xdc_runtime_LoggerCallback_Params *);

/* Handle__label__S */
xdc__CODESECT(xdc_runtime_LoggerCallback_Handle__label__S, "xdc_runtime_LoggerCallback_Handle__label__S")
__extern xdc_runtime_Types_Label *xdc_runtime_LoggerCallback_Handle__label__S( xdc_Ptr obj, xdc_runtime_Types_Label *lab );

/* Module__startupDone__S */
xdc__CODESECT(xdc_runtime_LoggerCallback_Module__startupDone__S, "xdc_runtime_LoggerCallback_Module__startupDone__S")
__extern xdc_Bool xdc_runtime_LoggerCallback_Module__startupDone__S( void );

/* Object__create__S */
xdc__CODESECT(xdc_runtime_LoggerCallback_Object__create__S, "xdc_runtime_LoggerCallback_Object__create__S")
__extern xdc_Ptr xdc_runtime_LoggerCallback_Object__create__S( xdc_Ptr __oa, xdc_SizeT __osz, xdc_Ptr __aa, const xdc_UChar *__pa, xdc_SizeT __psz, xdc_runtime_Error_Block *__eb );

/* create */
xdc__CODESECT(xdc_runtime_LoggerCallback_create, "xdc_runtime_LoggerCallback_create")
__extern xdc_runtime_LoggerCallback_Handle xdc_runtime_LoggerCallback_create( const xdc_runtime_LoggerCallback_Params *__prms, xdc_runtime_Error_Block *__eb );

/* construct */
xdc__CODESECT(xdc_runtime_LoggerCallback_construct, "xdc_runtime_LoggerCallback_construct")
__extern void xdc_runtime_LoggerCallback_construct( xdc_runtime_LoggerCallback_Struct *__obj, const xdc_runtime_LoggerCallback_Params *__prms );

/* Object__delete__S */
xdc__CODESECT(xdc_runtime_LoggerCallback_Object__delete__S, "xdc_runtime_LoggerCallback_Object__delete__S")
__extern xdc_Void xdc_runtime_LoggerCallback_Object__delete__S( xdc_Ptr instp );

/* delete */
xdc__CODESECT(xdc_runtime_LoggerCallback_delete, "xdc_runtime_LoggerCallback_delete")
__extern void xdc_runtime_LoggerCallback_delete(xdc_runtime_LoggerCallback_Handle *instp);

/* Object__destruct__S */
xdc__CODESECT(xdc_runtime_LoggerCallback_Object__destruct__S, "xdc_runtime_LoggerCallback_Object__destruct__S")
__extern xdc_Void xdc_runtime_LoggerCallback_Object__destruct__S( xdc_Ptr objp );

/* destruct */
xdc__CODESECT(xdc_runtime_LoggerCallback_destruct, "xdc_runtime_LoggerCallback_destruct")
__extern void xdc_runtime_LoggerCallback_destruct(xdc_runtime_LoggerCallback_Struct *obj);

/* Object__get__S */
xdc__CODESECT(xdc_runtime_LoggerCallback_Object__get__S, "xdc_runtime_LoggerCallback_Object__get__S")
__extern xdc_Ptr xdc_runtime_LoggerCallback_Object__get__S( xdc_Ptr oarr, xdc_Int i );

/* Object__first__S */
xdc__CODESECT(xdc_runtime_LoggerCallback_Object__first__S, "xdc_runtime_LoggerCallback_Object__first__S")
__extern xdc_Ptr xdc_runtime_LoggerCallback_Object__first__S( void );

/* Object__next__S */
xdc__CODESECT(xdc_runtime_LoggerCallback_Object__next__S, "xdc_runtime_LoggerCallback_Object__next__S")
__extern xdc_Ptr xdc_runtime_LoggerCallback_Object__next__S( xdc_Ptr obj );

/* Params__init__S */
xdc__CODESECT(xdc_runtime_LoggerCallback_Params__init__S, "xdc_runtime_LoggerCallback_Params__init__S")
__extern xdc_Void xdc_runtime_LoggerCallback_Params__init__S( xdc_Ptr dst, const xdc_Void *src, xdc_SizeT psz, xdc_SizeT isz );

/* enable__E */
#define xdc_runtime_LoggerCallback_enable xdc_runtime_LoggerCallback_enable__E
xdc__CODESECT(xdc_runtime_LoggerCallback_enable__E, "xdc_runtime_LoggerCallback_enable")
__extern xdc_Bool xdc_runtime_LoggerCallback_enable__E( xdc_runtime_LoggerCallback_Handle __inst );

/* disable__E */
#define xdc_runtime_LoggerCallback_disable xdc_runtime_LoggerCallback_disable__E
xdc__CODESECT(xdc_runtime_LoggerCallback_disable__E, "xdc_runtime_LoggerCallback_disable")
__extern xdc_Bool xdc_runtime_LoggerCallback_disable__E( xdc_runtime_LoggerCallback_Handle __inst );

/* write0__E */
#define xdc_runtime_LoggerCallback_write0 xdc_runtime_LoggerCallback_write0__E
xdc__CODESECT(xdc_runtime_LoggerCallback_write0__E, "xdc_runtime_LoggerCallback_write0")
__extern xdc_Void xdc_runtime_LoggerCallback_write0__E( xdc_runtime_LoggerCallback_Handle __inst, xdc_runtime_Log_Event evt, xdc_runtime_Types_ModuleId mid );

/* write1__E */
#define xdc_runtime_LoggerCallback_write1 xdc_runtime_LoggerCallback_write1__E
xdc__CODESECT(xdc_runtime_LoggerCallback_write1__E, "xdc_runtime_LoggerCallback_write1")
__extern xdc_Void xdc_runtime_LoggerCallback_write1__E( xdc_runtime_LoggerCallback_Handle __inst, xdc_runtime_Log_Event evt, xdc_runtime_Types_ModuleId mid, xdc_IArg a1 );

/* write2__E */
#define xdc_runtime_LoggerCallback_write2 xdc_runtime_LoggerCallback_write2__E
xdc__CODESECT(xdc_runtime_LoggerCallback_write2__E, "xdc_runtime_LoggerCallback_write2")
__extern xdc_Void xdc_runtime_LoggerCallback_write2__E( xdc_runtime_LoggerCallback_Handle __inst, xdc_runtime_Log_Event evt, xdc_runtime_Types_ModuleId mid, xdc_IArg a1, xdc_IArg a2 );

/* write4__E */
#define xdc_runtime_LoggerCallback_write4 xdc_runtime_LoggerCallback_write4__E
xdc__CODESECT(xdc_runtime_LoggerCallback_write4__E, "xdc_runtime_LoggerCallback_write4")
__extern xdc_Void xdc_runtime_LoggerCallback_write4__E( xdc_runtime_LoggerCallback_Handle __inst, xdc_runtime_Log_Event evt, xdc_runtime_Types_ModuleId mid, xdc_IArg a1, xdc_IArg a2, xdc_IArg a3, xdc_IArg a4 );

/* write8__E */
#define xdc_runtime_LoggerCallback_write8 xdc_runtime_LoggerCallback_write8__E
xdc__CODESECT(xdc_runtime_LoggerCallback_write8__E, "xdc_runtime_LoggerCallback_write8")
__extern xdc_Void xdc_runtime_LoggerCallback_write8__E( xdc_runtime_LoggerCallback_Handle __inst, xdc_runtime_Log_Event evt, xdc_runtime_Types_ModuleId mid, xdc_IArg a1, xdc_IArg a2, xdc_IArg a3, xdc_IArg a4, xdc_IArg a5, xdc_IArg a6, xdc_IArg a7, xdc_IArg a8 );


/*
 * ======== CONVERTORS ========
 */

/* Module_upCast */
static inline xdc_runtime_ILogger_Module xdc_runtime_LoggerCallback_Module_upCast( void )
{
    return (xdc_runtime_ILogger_Module)&xdc_runtime_LoggerCallback_Module__FXNS__C;
}

/* Module_to_xdc_runtime_ILogger */
#define xdc_runtime_LoggerCallback_Module_to_xdc_runtime_ILogger xdc_runtime_LoggerCallback_Module_upCast

/* Handle_upCast */
static inline xdc_runtime_ILogger_Handle xdc_runtime_LoggerCallback_Handle_upCast( xdc_runtime_LoggerCallback_Handle i )
{
    return (xdc_runtime_ILogger_Handle)i;
}

/* Handle_to_xdc_runtime_ILogger */
#define xdc_runtime_LoggerCallback_Handle_to_xdc_runtime_ILogger xdc_runtime_LoggerCallback_Handle_upCast

/* Handle_downCast */
static inline xdc_runtime_LoggerCallback_Handle xdc_runtime_LoggerCallback_Handle_downCast( xdc_runtime_ILogger_Handle i )
{
    xdc_runtime_ILogger_Handle i2 = (xdc_runtime_ILogger_Handle)i;
    return (void*)i2->__fxns == (void*)&xdc_runtime_LoggerCallback_Module__FXNS__C ? (xdc_runtime_LoggerCallback_Handle)i : 0;
}

/* Handle_from_xdc_runtime_ILogger */
#define xdc_runtime_LoggerCallback_Handle_from_xdc_runtime_ILogger xdc_runtime_LoggerCallback_Handle_downCast


/*
 * ======== SYSTEM FUNCTIONS ========
 */

/* Module_startupDone */
#define xdc_runtime_LoggerCallback_Module_startupDone() xdc_runtime_LoggerCallback_Module__startupDone__S()

/* Object_heap */
#define xdc_runtime_LoggerCallback_Object_heap() xdc_runtime_LoggerCallback_Object__heap__C

/* Module_heap */
#define xdc_runtime_LoggerCallback_Module_heap() xdc_runtime_LoggerCallback_Object__heap__C

/* Module_id */
static inline CT__xdc_runtime_LoggerCallback_Module__id xdc_runtime_LoggerCallback_Module_id( void ) 
{
    return xdc_runtime_LoggerCallback_Module__id__C;
}

/* Module_hasMask */
static inline xdc_Bool xdc_runtime_LoggerCallback_Module_hasMask( void ) 
{
    return xdc_runtime_LoggerCallback_Module__diagsMask__C != NULL;
}

/* Module_getMask */
static inline xdc_Bits16 xdc_runtime_LoggerCallback_Module_getMask( void ) 
{
    return xdc_runtime_LoggerCallback_Module__diagsMask__C != NULL ? *xdc_runtime_LoggerCallback_Module__diagsMask__C : 0;
}

/* Module_setMask */
static inline xdc_Void xdc_runtime_LoggerCallback_Module_setMask( xdc_Bits16 mask ) 
{
    if (xdc_runtime_LoggerCallback_Module__diagsMask__C != NULL) *xdc_runtime_LoggerCallback_Module__diagsMask__C = mask;
}

/* Params_init */
static inline void xdc_runtime_LoggerCallback_Params_init( xdc_runtime_LoggerCallback_Params *prms ) 
{
    if (prms) {
        xdc_runtime_LoggerCallback_Params__init__S(prms, 0, sizeof(xdc_runtime_LoggerCallback_Params), sizeof(xdc_runtime_IInstance_Params));
    }
}

/* Params_copy */
static inline void xdc_runtime_LoggerCallback_Params_copy(xdc_runtime_LoggerCallback_Params *dst, const xdc_runtime_LoggerCallback_Params *src) 
{
    if (dst) {
        xdc_runtime_LoggerCallback_Params__init__S(dst, (const void *)src, sizeof(xdc_runtime_LoggerCallback_Params), sizeof(xdc_runtime_IInstance_Params));
    }
}

/* Object_count */
#define xdc_runtime_LoggerCallback_Object_count() xdc_runtime_LoggerCallback_Object__count__C

/* Object_sizeof */
#define xdc_runtime_LoggerCallback_Object_sizeof() xdc_runtime_LoggerCallback_Object__sizeof__C

/* Object_get */
static inline xdc_runtime_LoggerCallback_Handle xdc_runtime_LoggerCallback_Object_get(xdc_runtime_LoggerCallback_Instance_State *oarr, int i) 
{
    return (xdc_runtime_LoggerCallback_Handle)xdc_runtime_LoggerCallback_Object__get__S(oarr, i);
}

/* Object_first */
static inline xdc_runtime_LoggerCallback_Handle xdc_runtime_LoggerCallback_Object_first( void )
{
    return (xdc_runtime_LoggerCallback_Handle)xdc_runtime_LoggerCallback_Object__first__S();
}

/* Object_next */
static inline xdc_runtime_LoggerCallback_Handle xdc_runtime_LoggerCallback_Object_next( xdc_runtime_LoggerCallback_Object *obj )
{
    return (xdc_runtime_LoggerCallback_Handle)xdc_runtime_LoggerCallback_Object__next__S(obj);
}

/* Handle_label */
static inline xdc_runtime_Types_Label *xdc_runtime_LoggerCallback_Handle_label( xdc_runtime_LoggerCallback_Handle inst, xdc_runtime_Types_Label *lab )
{
    return xdc_runtime_LoggerCallback_Handle__label__S(inst, lab);
}

/* Handle_name */
static inline xdc_String xdc_runtime_LoggerCallback_Handle_name( xdc_runtime_LoggerCallback_Handle inst )
{
    xdc_runtime_Types_Label lab;
    return xdc_runtime_LoggerCallback_Handle__label__S(inst, &lab)->iname;
}

/* handle */
static inline xdc_runtime_LoggerCallback_Handle xdc_runtime_LoggerCallback_handle( xdc_runtime_LoggerCallback_Struct *str )
{
    return (xdc_runtime_LoggerCallback_Handle)str;
}

/* struct */
static inline xdc_runtime_LoggerCallback_Struct *xdc_runtime_LoggerCallback_struct( xdc_runtime_LoggerCallback_Handle inst )
{
    return (xdc_runtime_LoggerCallback_Struct*)inst;
}


/*
 * ======== EPILOGUE ========
 */

#ifdef xdc_runtime_LoggerCallback__top__
#undef __nested__
#endif

#endif /* xdc_runtime_LoggerCallback__include */


/*
 * ======== STATE STRUCTURES ========
 */

#if defined(__config__) || (!defined(__nested__) && defined(xdc_runtime_LoggerCallback__internalaccess))

#ifndef xdc_runtime_LoggerCallback__include_state
#define xdc_runtime_LoggerCallback__include_state

/* Object */
struct xdc_runtime_LoggerCallback_Object {
    const xdc_runtime_LoggerCallback_Fxns__ *__fxns;
    xdc_Bool enabled;
    xdc_UArg context;
    xdc_UArg arg;
};

#endif /* xdc_runtime_LoggerCallback__include_state */

#endif


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(xdc_runtime_LoggerCallback__nolocalnames)

#ifndef xdc_runtime_LoggerCallback__localnames__done
#define xdc_runtime_LoggerCallback__localnames__done

/* module prefix */
#define LoggerCallback_Instance xdc_runtime_LoggerCallback_Instance
#define LoggerCallback_Handle xdc_runtime_LoggerCallback_Handle
#define LoggerCallback_Module xdc_runtime_LoggerCallback_Module
#define LoggerCallback_Object xdc_runtime_LoggerCallback_Object
#define LoggerCallback_Struct xdc_runtime_LoggerCallback_Struct
#define LoggerCallback_OutputFxn xdc_runtime_LoggerCallback_OutputFxn
#define LoggerCallback_CreateInstFxn xdc_runtime_LoggerCallback_CreateInstFxn
#define LoggerCallback_Instance_State xdc_runtime_LoggerCallback_Instance_State
#define LoggerCallback_outputFxn xdc_runtime_LoggerCallback_outputFxn
#define LoggerCallback_createInstFxn xdc_runtime_LoggerCallback_createInstFxn
#define LoggerCallback_Params xdc_runtime_LoggerCallback_Params
#define LoggerCallback_enable xdc_runtime_LoggerCallback_enable
#define LoggerCallback_disable xdc_runtime_LoggerCallback_disable
#define LoggerCallback_write0 xdc_runtime_LoggerCallback_write0
#define LoggerCallback_write1 xdc_runtime_LoggerCallback_write1
#define LoggerCallback_write2 xdc_runtime_LoggerCallback_write2
#define LoggerCallback_write4 xdc_runtime_LoggerCallback_write4
#define LoggerCallback_write8 xdc_runtime_LoggerCallback_write8
#define LoggerCallback_Module_name xdc_runtime_LoggerCallback_Module_name
#define LoggerCallback_Module_id xdc_runtime_LoggerCallback_Module_id
#define LoggerCallback_Module_startup xdc_runtime_LoggerCallback_Module_startup
#define LoggerCallback_Module_startupDone xdc_runtime_LoggerCallback_Module_startupDone
#define LoggerCallback_Module_hasMask xdc_runtime_LoggerCallback_Module_hasMask
#define LoggerCallback_Module_getMask xdc_runtime_LoggerCallback_Module_getMask
#define LoggerCallback_Module_setMask xdc_runtime_LoggerCallback_Module_setMask
#define LoggerCallback_Object_heap xdc_runtime_LoggerCallback_Object_heap
#define LoggerCallback_Module_heap xdc_runtime_LoggerCallback_Module_heap
#define LoggerCallback_construct xdc_runtime_LoggerCallback_construct
#define LoggerCallback_create xdc_runtime_LoggerCallback_create
#define LoggerCallback_handle xdc_runtime_LoggerCallback_handle
#define LoggerCallback_struct xdc_runtime_LoggerCallback_struct
#define LoggerCallback_Handle_label xdc_runtime_LoggerCallback_Handle_label
#define LoggerCallback_Handle_name xdc_runtime_LoggerCallback_Handle_name
#define LoggerCallback_Instance_init xdc_runtime_LoggerCallback_Instance_init
#define LoggerCallback_Object_count xdc_runtime_LoggerCallback_Object_count
#define LoggerCallback_Object_get xdc_runtime_LoggerCallback_Object_get
#define LoggerCallback_Object_first xdc_runtime_LoggerCallback_Object_first
#define LoggerCallback_Object_next xdc_runtime_LoggerCallback_Object_next
#define LoggerCallback_Object_sizeof xdc_runtime_LoggerCallback_Object_sizeof
#define LoggerCallback_Params_copy xdc_runtime_LoggerCallback_Params_copy
#define LoggerCallback_Params_init xdc_runtime_LoggerCallback_Params_init
#define LoggerCallback_delete xdc_runtime_LoggerCallback_delete
#define LoggerCallback_destruct xdc_runtime_LoggerCallback_destruct
#define LoggerCallback_Module_upCast xdc_runtime_LoggerCallback_Module_upCast
#define LoggerCallback_Module_to_xdc_runtime_ILogger xdc_runtime_LoggerCallback_Module_to_xdc_runtime_ILogger
#define LoggerCallback_Handle_upCast xdc_runtime_LoggerCallback_Handle_upCast
#define LoggerCallback_Handle_to_xdc_runtime_ILogger xdc_runtime_LoggerCallback_Handle_to_xdc_runtime_ILogger
#define LoggerCallback_Handle_downCast xdc_runtime_LoggerCallback_Handle_downCast
#define LoggerCallback_Handle_from_xdc_runtime_ILogger xdc_runtime_LoggerCallback_Handle_from_xdc_runtime_ILogger

#endif /* xdc_runtime_LoggerCallback__localnames__done */
#endif
/*
 *  @(#) xdc.runtime; 2, 1, 0,0; 4-24-2015 12:34:13; /db/ztree/library/trees/xdc/xdc-A71/src/packages/
 */

