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

#ifndef ti_sysbios_interfaces_ICache__include
#define ti_sysbios_interfaces_ICache__include

#ifndef __nested__
#define __nested__
#define ti_sysbios_interfaces_ICache__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define ti_sysbios_interfaces_ICache___VERS 160


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <ti/sysbios/interfaces/package/package.defs.h>

#include <xdc/runtime/IModule.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */

/* Type */
enum ti_sysbios_interfaces_ICache_Type {
    ti_sysbios_interfaces_ICache_Type_L1P = 0x1,
    ti_sysbios_interfaces_ICache_Type_L1D = 0x2,
    ti_sysbios_interfaces_ICache_Type_L1 = 0x3,
    ti_sysbios_interfaces_ICache_Type_L2P = 0x4,
    ti_sysbios_interfaces_ICache_Type_L2D = 0x8,
    ti_sysbios_interfaces_ICache_Type_L2 = 0xC,
    ti_sysbios_interfaces_ICache_Type_ALLP = 0x5,
    ti_sysbios_interfaces_ICache_Type_ALLD = 0xA,
    ti_sysbios_interfaces_ICache_Type_ALL = 0x7fff
};
typedef enum ti_sysbios_interfaces_ICache_Type ti_sysbios_interfaces_ICache_Type;


/*
 * ======== VIRTUAL FUNCTIONS ========
 */

/* Fxns__ */
struct ti_sysbios_interfaces_ICache_Fxns__ {
    xdc_runtime_Types_Base* __base;
    const xdc_runtime_Types_SysFxns2 *__sysp;
    xdc_Void (*enable)(xdc_Bits16);
    xdc_Void (*disable)(xdc_Bits16);
    xdc_Void (*inv)(xdc_Ptr, xdc_SizeT, xdc_Bits16, xdc_Bool);
    xdc_Void (*wb)(xdc_Ptr, xdc_SizeT, xdc_Bits16, xdc_Bool);
    xdc_Void (*wbInv)(xdc_Ptr, xdc_SizeT, xdc_Bits16, xdc_Bool);
    xdc_Void (*wbAll)(void);
    xdc_Void (*wbInvAll)(void);
    xdc_Void (*wait)(void);
    xdc_runtime_Types_SysFxns2 __sfxns;
};

/* Interface__BASE__C */
__extern const xdc_runtime_Types_Base ti_sysbios_interfaces_ICache_Interface__BASE__C;


/*
 * ======== FUNCTION STUBS ========
 */

/* Module_id */
static inline xdc_runtime_Types_ModuleId ti_sysbios_interfaces_ICache_Module_id( ti_sysbios_interfaces_ICache_Module mod )
{
    return mod->__sysp->__mid;
}

/* enable */
static inline xdc_Void ti_sysbios_interfaces_ICache_enable( ti_sysbios_interfaces_ICache_Module __inst, xdc_Bits16 type )
{
    __inst->enable(type);
}

/* disable */
static inline xdc_Void ti_sysbios_interfaces_ICache_disable( ti_sysbios_interfaces_ICache_Module __inst, xdc_Bits16 type )
{
    __inst->disable(type);
}

/* inv */
static inline xdc_Void ti_sysbios_interfaces_ICache_inv( ti_sysbios_interfaces_ICache_Module __inst, xdc_Ptr blockPtr, xdc_SizeT byteCnt, xdc_Bits16 type, xdc_Bool wait )
{
    __inst->inv(blockPtr, byteCnt, type, wait);
}

/* wb */
static inline xdc_Void ti_sysbios_interfaces_ICache_wb( ti_sysbios_interfaces_ICache_Module __inst, xdc_Ptr blockPtr, xdc_SizeT byteCnt, xdc_Bits16 type, xdc_Bool wait )
{
    __inst->wb(blockPtr, byteCnt, type, wait);
}

/* wbInv */
static inline xdc_Void ti_sysbios_interfaces_ICache_wbInv( ti_sysbios_interfaces_ICache_Module __inst, xdc_Ptr blockPtr, xdc_SizeT byteCnt, xdc_Bits16 type, xdc_Bool wait )
{
    __inst->wbInv(blockPtr, byteCnt, type, wait);
}

/* wbAll */
static inline xdc_Void ti_sysbios_interfaces_ICache_wbAll( ti_sysbios_interfaces_ICache_Module __inst )
{
    __inst->wbAll();
}

/* wbInvAll */
static inline xdc_Void ti_sysbios_interfaces_ICache_wbInvAll( ti_sysbios_interfaces_ICache_Module __inst )
{
    __inst->wbInvAll();
}

/* wait */
static inline xdc_Void ti_sysbios_interfaces_ICache_wait( ti_sysbios_interfaces_ICache_Module __inst )
{
    __inst->wait();
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
typedef xdc_Void (*ti_sysbios_interfaces_ICache_enable_FxnT)(xdc_Bits16);
static inline ti_sysbios_interfaces_ICache_enable_FxnT ti_sysbios_interfaces_ICache_enable_fxnP( ti_sysbios_interfaces_ICache_Module __inst )
{
    return (ti_sysbios_interfaces_ICache_enable_FxnT)__inst->enable;
}

/* disable_{FxnT,fxnP} */
typedef xdc_Void (*ti_sysbios_interfaces_ICache_disable_FxnT)(xdc_Bits16);
static inline ti_sysbios_interfaces_ICache_disable_FxnT ti_sysbios_interfaces_ICache_disable_fxnP( ti_sysbios_interfaces_ICache_Module __inst )
{
    return (ti_sysbios_interfaces_ICache_disable_FxnT)__inst->disable;
}

/* inv_{FxnT,fxnP} */
typedef xdc_Void (*ti_sysbios_interfaces_ICache_inv_FxnT)(xdc_Ptr, xdc_SizeT, xdc_Bits16, xdc_Bool);
static inline ti_sysbios_interfaces_ICache_inv_FxnT ti_sysbios_interfaces_ICache_inv_fxnP( ti_sysbios_interfaces_ICache_Module __inst )
{
    return (ti_sysbios_interfaces_ICache_inv_FxnT)__inst->inv;
}

/* wb_{FxnT,fxnP} */
typedef xdc_Void (*ti_sysbios_interfaces_ICache_wb_FxnT)(xdc_Ptr, xdc_SizeT, xdc_Bits16, xdc_Bool);
static inline ti_sysbios_interfaces_ICache_wb_FxnT ti_sysbios_interfaces_ICache_wb_fxnP( ti_sysbios_interfaces_ICache_Module __inst )
{
    return (ti_sysbios_interfaces_ICache_wb_FxnT)__inst->wb;
}

/* wbInv_{FxnT,fxnP} */
typedef xdc_Void (*ti_sysbios_interfaces_ICache_wbInv_FxnT)(xdc_Ptr, xdc_SizeT, xdc_Bits16, xdc_Bool);
static inline ti_sysbios_interfaces_ICache_wbInv_FxnT ti_sysbios_interfaces_ICache_wbInv_fxnP( ti_sysbios_interfaces_ICache_Module __inst )
{
    return (ti_sysbios_interfaces_ICache_wbInv_FxnT)__inst->wbInv;
}

/* wbAll_{FxnT,fxnP} */
typedef xdc_Void (*ti_sysbios_interfaces_ICache_wbAll_FxnT)(void);
static inline ti_sysbios_interfaces_ICache_wbAll_FxnT ti_sysbios_interfaces_ICache_wbAll_fxnP( ti_sysbios_interfaces_ICache_Module __inst )
{
    return (ti_sysbios_interfaces_ICache_wbAll_FxnT)__inst->wbAll;
}

/* wbInvAll_{FxnT,fxnP} */
typedef xdc_Void (*ti_sysbios_interfaces_ICache_wbInvAll_FxnT)(void);
static inline ti_sysbios_interfaces_ICache_wbInvAll_FxnT ti_sysbios_interfaces_ICache_wbInvAll_fxnP( ti_sysbios_interfaces_ICache_Module __inst )
{
    return (ti_sysbios_interfaces_ICache_wbInvAll_FxnT)__inst->wbInvAll;
}

/* wait_{FxnT,fxnP} */
typedef xdc_Void (*ti_sysbios_interfaces_ICache_wait_FxnT)(void);
static inline ti_sysbios_interfaces_ICache_wait_FxnT ti_sysbios_interfaces_ICache_wait_fxnP( ti_sysbios_interfaces_ICache_Module __inst )
{
    return (ti_sysbios_interfaces_ICache_wait_FxnT)__inst->wait;
}


/*
 * ======== EPILOGUE ========
 */

#ifdef ti_sysbios_interfaces_ICache__top__
#undef __nested__
#endif

#endif /* ti_sysbios_interfaces_ICache__include */


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(ti_sysbios_interfaces_ICache__nolocalnames)

#ifndef ti_sysbios_interfaces_ICache__localnames__done
#define ti_sysbios_interfaces_ICache__localnames__done

/* module prefix */
#define ICache_Module ti_sysbios_interfaces_ICache_Module
#define ICache_Type ti_sysbios_interfaces_ICache_Type
#define ICache_Type_L1P ti_sysbios_interfaces_ICache_Type_L1P
#define ICache_Type_L1D ti_sysbios_interfaces_ICache_Type_L1D
#define ICache_Type_L1 ti_sysbios_interfaces_ICache_Type_L1
#define ICache_Type_L2P ti_sysbios_interfaces_ICache_Type_L2P
#define ICache_Type_L2D ti_sysbios_interfaces_ICache_Type_L2D
#define ICache_Type_L2 ti_sysbios_interfaces_ICache_Type_L2
#define ICache_Type_ALLP ti_sysbios_interfaces_ICache_Type_ALLP
#define ICache_Type_ALLD ti_sysbios_interfaces_ICache_Type_ALLD
#define ICache_Type_ALL ti_sysbios_interfaces_ICache_Type_ALL
#define ICache_enable ti_sysbios_interfaces_ICache_enable
#define ICache_enable_fxnP ti_sysbios_interfaces_ICache_enable_fxnP
#define ICache_enable_FxnT ti_sysbios_interfaces_ICache_enable_FxnT
#define ICache_disable ti_sysbios_interfaces_ICache_disable
#define ICache_disable_fxnP ti_sysbios_interfaces_ICache_disable_fxnP
#define ICache_disable_FxnT ti_sysbios_interfaces_ICache_disable_FxnT
#define ICache_inv ti_sysbios_interfaces_ICache_inv
#define ICache_inv_fxnP ti_sysbios_interfaces_ICache_inv_fxnP
#define ICache_inv_FxnT ti_sysbios_interfaces_ICache_inv_FxnT
#define ICache_wb ti_sysbios_interfaces_ICache_wb
#define ICache_wb_fxnP ti_sysbios_interfaces_ICache_wb_fxnP
#define ICache_wb_FxnT ti_sysbios_interfaces_ICache_wb_FxnT
#define ICache_wbInv ti_sysbios_interfaces_ICache_wbInv
#define ICache_wbInv_fxnP ti_sysbios_interfaces_ICache_wbInv_fxnP
#define ICache_wbInv_FxnT ti_sysbios_interfaces_ICache_wbInv_FxnT
#define ICache_wbAll ti_sysbios_interfaces_ICache_wbAll
#define ICache_wbAll_fxnP ti_sysbios_interfaces_ICache_wbAll_fxnP
#define ICache_wbAll_FxnT ti_sysbios_interfaces_ICache_wbAll_FxnT
#define ICache_wbInvAll ti_sysbios_interfaces_ICache_wbInvAll
#define ICache_wbInvAll_fxnP ti_sysbios_interfaces_ICache_wbInvAll_fxnP
#define ICache_wbInvAll_FxnT ti_sysbios_interfaces_ICache_wbInvAll_FxnT
#define ICache_wait ti_sysbios_interfaces_ICache_wait
#define ICache_wait_fxnP ti_sysbios_interfaces_ICache_wait_fxnP
#define ICache_wait_FxnT ti_sysbios_interfaces_ICache_wait_FxnT
#define ICache_Module_name ti_sysbios_interfaces_ICache_Module_name

#endif /* ti_sysbios_interfaces_ICache__localnames__done */
#endif
