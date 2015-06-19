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

#ifndef ti_sysbios_family_arm_m3_Hwi__include
#define ti_sysbios_family_arm_m3_Hwi__include

#ifndef __nested__
#define __nested__
#define ti_sysbios_family_arm_m3_Hwi__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define ti_sysbios_family_arm_m3_Hwi___VERS 160


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/IInstance.h>
#include <ti/sysbios/family/arm/m3/Hwi__prologue.h>
#include <ti/sysbios/family/arm/m3/package/package.defs.h>

#include <xdc/runtime/Diags.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/Assert.h>
#include <xdc/runtime/Error.h>
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/interfaces/IHwi.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */

/* FuncPtr */
typedef ti_sysbios_interfaces_IHwi_FuncPtr ti_sysbios_family_arm_m3_Hwi_FuncPtr;

/* Irp */
typedef ti_sysbios_interfaces_IHwi_Irp ti_sysbios_family_arm_m3_Hwi_Irp;

/* HookSet */
typedef ti_sysbios_interfaces_IHwi_HookSet ti_sysbios_family_arm_m3_Hwi_HookSet;

/* MaskingOption */
typedef ti_sysbios_interfaces_IHwi_MaskingOption ti_sysbios_family_arm_m3_Hwi_MaskingOption;

/* StackInfo */
typedef ti_sysbios_interfaces_IHwi_StackInfo ti_sysbios_family_arm_m3_Hwi_StackInfo;

/* VectorFuncPtr */
typedef xdc_Void (*ti_sysbios_family_arm_m3_Hwi_VectorFuncPtr)(xdc_Void);

/* ExceptionHookFuncPtr */
typedef xdc_Void (*ti_sysbios_family_arm_m3_Hwi_ExceptionHookFuncPtr)(ti_sysbios_family_arm_m3_Hwi_ExcContext*);

/* CCR */
struct ti_sysbios_family_arm_m3_Hwi_CCR {
    xdc_Bits8 STKALIGN;
    xdc_Bits8 BFHFNMIGN;
    xdc_Bits8 DIV_0_TRP;
    xdc_Bits8 UNALIGN_TRP;
    xdc_Bits8 USERSETMPEND;
    xdc_Bits8 NONEBASETHRDENA;
};

/* NVIC */
typedef xdc_UInt32 __T1_ti_sysbios_family_arm_m3_Hwi_NVIC__RES_20;
typedef xdc_UInt32 __ARRAY1_ti_sysbios_family_arm_m3_Hwi_NVIC__RES_20[56];
typedef __ARRAY1_ti_sysbios_family_arm_m3_Hwi_NVIC__RES_20 __TA_ti_sysbios_family_arm_m3_Hwi_NVIC__RES_20;
typedef xdc_UInt32 __T1_ti_sysbios_family_arm_m3_Hwi_NVIC__ISER;
typedef xdc_UInt32 __ARRAY1_ti_sysbios_family_arm_m3_Hwi_NVIC__ISER[8];
typedef __ARRAY1_ti_sysbios_family_arm_m3_Hwi_NVIC__ISER __TA_ti_sysbios_family_arm_m3_Hwi_NVIC__ISER;
typedef xdc_UInt32 __T1_ti_sysbios_family_arm_m3_Hwi_NVIC__RES_120;
typedef xdc_UInt32 __ARRAY1_ti_sysbios_family_arm_m3_Hwi_NVIC__RES_120[24];
typedef __ARRAY1_ti_sysbios_family_arm_m3_Hwi_NVIC__RES_120 __TA_ti_sysbios_family_arm_m3_Hwi_NVIC__RES_120;
typedef xdc_UInt32 __T1_ti_sysbios_family_arm_m3_Hwi_NVIC__ICER;
typedef xdc_UInt32 __ARRAY1_ti_sysbios_family_arm_m3_Hwi_NVIC__ICER[8];
typedef __ARRAY1_ti_sysbios_family_arm_m3_Hwi_NVIC__ICER __TA_ti_sysbios_family_arm_m3_Hwi_NVIC__ICER;
typedef xdc_UInt32 __T1_ti_sysbios_family_arm_m3_Hwi_NVIC__RES_1A0;
typedef xdc_UInt32 __ARRAY1_ti_sysbios_family_arm_m3_Hwi_NVIC__RES_1A0[24];
typedef __ARRAY1_ti_sysbios_family_arm_m3_Hwi_NVIC__RES_1A0 __TA_ti_sysbios_family_arm_m3_Hwi_NVIC__RES_1A0;
typedef xdc_UInt32 __T1_ti_sysbios_family_arm_m3_Hwi_NVIC__ISPR;
typedef xdc_UInt32 __ARRAY1_ti_sysbios_family_arm_m3_Hwi_NVIC__ISPR[8];
typedef __ARRAY1_ti_sysbios_family_arm_m3_Hwi_NVIC__ISPR __TA_ti_sysbios_family_arm_m3_Hwi_NVIC__ISPR;
typedef xdc_UInt32 __T1_ti_sysbios_family_arm_m3_Hwi_NVIC__RES_220;
typedef xdc_UInt32 __ARRAY1_ti_sysbios_family_arm_m3_Hwi_NVIC__RES_220[24];
typedef __ARRAY1_ti_sysbios_family_arm_m3_Hwi_NVIC__RES_220 __TA_ti_sysbios_family_arm_m3_Hwi_NVIC__RES_220;
typedef xdc_UInt32 __T1_ti_sysbios_family_arm_m3_Hwi_NVIC__ICPR;
typedef xdc_UInt32 __ARRAY1_ti_sysbios_family_arm_m3_Hwi_NVIC__ICPR[8];
typedef __ARRAY1_ti_sysbios_family_arm_m3_Hwi_NVIC__ICPR __TA_ti_sysbios_family_arm_m3_Hwi_NVIC__ICPR;
typedef xdc_UInt32 __T1_ti_sysbios_family_arm_m3_Hwi_NVIC__RES_2A0;
typedef xdc_UInt32 __ARRAY1_ti_sysbios_family_arm_m3_Hwi_NVIC__RES_2A0[24];
typedef __ARRAY1_ti_sysbios_family_arm_m3_Hwi_NVIC__RES_2A0 __TA_ti_sysbios_family_arm_m3_Hwi_NVIC__RES_2A0;
typedef xdc_UInt32 __T1_ti_sysbios_family_arm_m3_Hwi_NVIC__IABR;
typedef xdc_UInt32 __ARRAY1_ti_sysbios_family_arm_m3_Hwi_NVIC__IABR[8];
typedef __ARRAY1_ti_sysbios_family_arm_m3_Hwi_NVIC__IABR __TA_ti_sysbios_family_arm_m3_Hwi_NVIC__IABR;
typedef xdc_UInt32 __T1_ti_sysbios_family_arm_m3_Hwi_NVIC__RES_320;
typedef xdc_UInt32 __ARRAY1_ti_sysbios_family_arm_m3_Hwi_NVIC__RES_320[56];
typedef __ARRAY1_ti_sysbios_family_arm_m3_Hwi_NVIC__RES_320 __TA_ti_sysbios_family_arm_m3_Hwi_NVIC__RES_320;
typedef xdc_UInt8 __T1_ti_sysbios_family_arm_m3_Hwi_NVIC__IPR;
typedef xdc_UInt8 __ARRAY1_ti_sysbios_family_arm_m3_Hwi_NVIC__IPR[240];
typedef __ARRAY1_ti_sysbios_family_arm_m3_Hwi_NVIC__IPR __TA_ti_sysbios_family_arm_m3_Hwi_NVIC__IPR;
typedef xdc_UInt32 __T1_ti_sysbios_family_arm_m3_Hwi_NVIC__RES_4F0;
typedef xdc_UInt32 __ARRAY1_ti_sysbios_family_arm_m3_Hwi_NVIC__RES_4F0[516];
typedef __ARRAY1_ti_sysbios_family_arm_m3_Hwi_NVIC__RES_4F0 __TA_ti_sysbios_family_arm_m3_Hwi_NVIC__RES_4F0;
typedef xdc_UInt8 __T1_ti_sysbios_family_arm_m3_Hwi_NVIC__SHPR;
typedef xdc_UInt8 __ARRAY1_ti_sysbios_family_arm_m3_Hwi_NVIC__SHPR[12];
typedef __ARRAY1_ti_sysbios_family_arm_m3_Hwi_NVIC__SHPR __TA_ti_sysbios_family_arm_m3_Hwi_NVIC__SHPR;
typedef xdc_UInt32 __T1_ti_sysbios_family_arm_m3_Hwi_NVIC__RES_D74;
typedef xdc_UInt32 __ARRAY1_ti_sysbios_family_arm_m3_Hwi_NVIC__RES_D74[5];
typedef __ARRAY1_ti_sysbios_family_arm_m3_Hwi_NVIC__RES_D74 __TA_ti_sysbios_family_arm_m3_Hwi_NVIC__RES_D74;
typedef xdc_UInt32 __T1_ti_sysbios_family_arm_m3_Hwi_NVIC__RES_D8C;
typedef xdc_UInt32 __ARRAY1_ti_sysbios_family_arm_m3_Hwi_NVIC__RES_D8C[93];
typedef __ARRAY1_ti_sysbios_family_arm_m3_Hwi_NVIC__RES_D8C __TA_ti_sysbios_family_arm_m3_Hwi_NVIC__RES_D8C;
typedef xdc_UInt32 __T1_ti_sysbios_family_arm_m3_Hwi_NVIC__RES_F04;
typedef xdc_UInt32 __ARRAY1_ti_sysbios_family_arm_m3_Hwi_NVIC__RES_F04[12];
typedef __ARRAY1_ti_sysbios_family_arm_m3_Hwi_NVIC__RES_F04 __TA_ti_sysbios_family_arm_m3_Hwi_NVIC__RES_F04;
typedef xdc_UInt32 __T1_ti_sysbios_family_arm_m3_Hwi_NVIC__RES_F48;
typedef xdc_UInt32 __ARRAY1_ti_sysbios_family_arm_m3_Hwi_NVIC__RES_F48[34];
typedef __ARRAY1_ti_sysbios_family_arm_m3_Hwi_NVIC__RES_F48 __TA_ti_sysbios_family_arm_m3_Hwi_NVIC__RES_F48;
struct ti_sysbios_family_arm_m3_Hwi_NVIC {
    xdc_UInt32 RES_00;
    xdc_UInt32 ICTR;
    xdc_UInt32 RES_08;
    xdc_UInt32 RES_0C;
    xdc_UInt32 STCSR;
    xdc_UInt32 STRVR;
    xdc_UInt32 STCVR;
    xdc_UInt32 STCALIB;
    __TA_ti_sysbios_family_arm_m3_Hwi_NVIC__RES_20 RES_20;
    __TA_ti_sysbios_family_arm_m3_Hwi_NVIC__ISER ISER;
    __TA_ti_sysbios_family_arm_m3_Hwi_NVIC__RES_120 RES_120;
    __TA_ti_sysbios_family_arm_m3_Hwi_NVIC__ICER ICER;
    __TA_ti_sysbios_family_arm_m3_Hwi_NVIC__RES_1A0 RES_1A0;
    __TA_ti_sysbios_family_arm_m3_Hwi_NVIC__ISPR ISPR;
    __TA_ti_sysbios_family_arm_m3_Hwi_NVIC__RES_220 RES_220;
    __TA_ti_sysbios_family_arm_m3_Hwi_NVIC__ICPR ICPR;
    __TA_ti_sysbios_family_arm_m3_Hwi_NVIC__RES_2A0 RES_2A0;
    __TA_ti_sysbios_family_arm_m3_Hwi_NVIC__IABR IABR;
    __TA_ti_sysbios_family_arm_m3_Hwi_NVIC__RES_320 RES_320;
    __TA_ti_sysbios_family_arm_m3_Hwi_NVIC__IPR IPR;
    __TA_ti_sysbios_family_arm_m3_Hwi_NVIC__RES_4F0 RES_4F0;
    xdc_UInt32 CPUIDBR;
    xdc_UInt32 ICSR;
    xdc_UInt32 VTOR;
    xdc_UInt32 AIRCR;
    xdc_UInt32 SCR;
    xdc_UInt32 CCR;
    __TA_ti_sysbios_family_arm_m3_Hwi_NVIC__SHPR SHPR;
    xdc_UInt32 SHCSR;
    xdc_UInt8 MMFSR;
    xdc_UInt8 BFSR;
    xdc_UInt16 UFSR;
    xdc_UInt32 HFSR;
    xdc_UInt32 DFSR;
    xdc_UInt32 MMAR;
    xdc_UInt32 BFAR;
    xdc_UInt32 AFSR;
    xdc_UInt32 PFR0;
    xdc_UInt32 PFR1;
    xdc_UInt32 DFR0;
    xdc_UInt32 AFR0;
    xdc_UInt32 MMFR0;
    xdc_UInt32 MMFR1;
    xdc_UInt32 MMFR2;
    xdc_UInt32 MMFR3;
    xdc_UInt32 ISAR0;
    xdc_UInt32 ISAR1;
    xdc_UInt32 ISAR2;
    xdc_UInt32 ISAR3;
    xdc_UInt32 ISAR4;
    __TA_ti_sysbios_family_arm_m3_Hwi_NVIC__RES_D74 RES_D74;
    xdc_UInt32 CPACR;
    __TA_ti_sysbios_family_arm_m3_Hwi_NVIC__RES_D8C RES_D8C;
    xdc_UInt32 STI;
    __TA_ti_sysbios_family_arm_m3_Hwi_NVIC__RES_F04 RES_F04;
    xdc_UInt32 FPCCR;
    xdc_UInt32 FPCAR;
    xdc_UInt32 FPDSCR;
    xdc_UInt32 MVFR0;
    xdc_UInt32 MVFR1;
    __TA_ti_sysbios_family_arm_m3_Hwi_NVIC__RES_F48 RES_F48;
    xdc_UInt32 PID4;
    xdc_UInt32 PID5;
    xdc_UInt32 PID6;
    xdc_UInt32 PID7;
    xdc_UInt32 PID0;
    xdc_UInt32 PID1;
    xdc_UInt32 PID2;
    xdc_UInt32 PID3;
    xdc_UInt32 CID0;
    xdc_UInt32 CID1;
    xdc_UInt32 CID2;
    xdc_UInt32 CID3;
};

/* nvic */
#define ti_sysbios_family_arm_m3_Hwi_nvic ti_sysbios_family_arm_m3_Hwi_nvic
__extern volatile ti_sysbios_family_arm_m3_Hwi_NVIC ti_sysbios_family_arm_m3_Hwi_nvic;

/* vnvic */
#define ti_sysbios_family_arm_m3_Hwi_vnvic ti_sysbios_family_arm_m3_Hwi_vnvic
__extern volatile ti_sysbios_family_arm_m3_Hwi_NVIC ti_sysbios_family_arm_m3_Hwi_vnvic;

/* ExcContext */
struct ti_sysbios_family_arm_m3_Hwi_ExcContext {
    ti_sysbios_BIOS_ThreadType threadType;
    xdc_Ptr threadHandle;
    xdc_Ptr threadStack;
    xdc_SizeT threadStackSize;
    xdc_Ptr r0;
    xdc_Ptr r1;
    xdc_Ptr r2;
    xdc_Ptr r3;
    xdc_Ptr r4;
    xdc_Ptr r5;
    xdc_Ptr r6;
    xdc_Ptr r7;
    xdc_Ptr r8;
    xdc_Ptr r9;
    xdc_Ptr r10;
    xdc_Ptr r11;
    xdc_Ptr r12;
    xdc_Ptr sp;
    xdc_Ptr lr;
    xdc_Ptr pc;
    xdc_Ptr psr;
    xdc_Ptr ICSR;
    xdc_Ptr MMFSR;
    xdc_Ptr BFSR;
    xdc_Ptr UFSR;
    xdc_Ptr HFSR;
    xdc_Ptr DFSR;
    xdc_Ptr MMAR;
    xdc_Ptr BFAR;
    xdc_Ptr AFSR;
};

/* ExcHandlerFuncPtr */
typedef xdc_Void (*ti_sysbios_family_arm_m3_Hwi_ExcHandlerFuncPtr)(xdc_UInt*, xdc_UInt);

/* MaskingOption_NONE */
#define ti_sysbios_family_arm_m3_Hwi_MaskingOption_NONE ti_sysbios_interfaces_IHwi_MaskingOption_NONE

/* MaskingOption_ALL */
#define ti_sysbios_family_arm_m3_Hwi_MaskingOption_ALL ti_sysbios_interfaces_IHwi_MaskingOption_ALL

/* MaskingOption_SELF */
#define ti_sysbios_family_arm_m3_Hwi_MaskingOption_SELF ti_sysbios_interfaces_IHwi_MaskingOption_SELF

/* MaskingOption_BITMASK */
#define ti_sysbios_family_arm_m3_Hwi_MaskingOption_BITMASK ti_sysbios_interfaces_IHwi_MaskingOption_BITMASK

/* MaskingOption_LOWER */
#define ti_sysbios_family_arm_m3_Hwi_MaskingOption_LOWER ti_sysbios_interfaces_IHwi_MaskingOption_LOWER


/*
 * ======== CREATE ARGS ========
 */

/* Args__create */
typedef struct ti_sysbios_family_arm_m3_Hwi_Args__create {
    xdc_Int intNum;
    ti_sysbios_interfaces_IHwi_FuncPtr hwiFxn;
} ti_sysbios_family_arm_m3_Hwi_Args__create;


/*
 * ======== INTERNAL DEFINITIONS ========
 */

/* HandlerFuncPtr */
typedef xdc_Void (*ti_sysbios_family_arm_m3_Hwi_HandlerFuncPtr)(ti_sysbios_family_arm_m3_Hwi_Handle, xdc_UInt);

/* Instance_State */
typedef xdc_Ptr __T1_ti_sysbios_family_arm_m3_Hwi_Instance_State__hookEnv;
typedef xdc_Ptr *__ARRAY1_ti_sysbios_family_arm_m3_Hwi_Instance_State__hookEnv;
typedef __ARRAY1_ti_sysbios_family_arm_m3_Hwi_Instance_State__hookEnv __TA_ti_sysbios_family_arm_m3_Hwi_Instance_State__hookEnv;

/* Module_State */
typedef xdc_Bool __T1_ti_sysbios_family_arm_m3_Hwi_Module_State__excActive;
typedef xdc_Bool *__ARRAY1_ti_sysbios_family_arm_m3_Hwi_Module_State__excActive;
typedef __ARRAY1_ti_sysbios_family_arm_m3_Hwi_Module_State__excActive __TA_ti_sysbios_family_arm_m3_Hwi_Module_State__excActive;
typedef ti_sysbios_family_arm_m3_Hwi_ExcContext *__T1_ti_sysbios_family_arm_m3_Hwi_Module_State__excContext;
typedef ti_sysbios_family_arm_m3_Hwi_ExcContext **__ARRAY1_ti_sysbios_family_arm_m3_Hwi_Module_State__excContext;
typedef __ARRAY1_ti_sysbios_family_arm_m3_Hwi_Module_State__excContext __TA_ti_sysbios_family_arm_m3_Hwi_Module_State__excContext;
typedef xdc_Ptr __T1_ti_sysbios_family_arm_m3_Hwi_Module_State__excStack;
typedef xdc_Ptr *__ARRAY1_ti_sysbios_family_arm_m3_Hwi_Module_State__excStack;
typedef __ARRAY1_ti_sysbios_family_arm_m3_Hwi_Module_State__excStack __TA_ti_sysbios_family_arm_m3_Hwi_Module_State__excStack;
typedef xdc_UInt8 __T1_ti_sysbios_family_arm_m3_Hwi_Module_State__intAffinity;
typedef xdc_UInt8 *__ARRAY1_ti_sysbios_family_arm_m3_Hwi_Module_State__intAffinity;
typedef __ARRAY1_ti_sysbios_family_arm_m3_Hwi_Module_State__intAffinity __TA_ti_sysbios_family_arm_m3_Hwi_Module_State__intAffinity;
typedef xdc_UInt32 __T1_ti_sysbios_family_arm_m3_Hwi_Module_State__intAffinityMasks;
typedef xdc_UInt32 *__ARRAY1_ti_sysbios_family_arm_m3_Hwi_Module_State__intAffinityMasks;
typedef __ARRAY1_ti_sysbios_family_arm_m3_Hwi_Module_State__intAffinityMasks __T2_ti_sysbios_family_arm_m3_Hwi_Module_State__intAffinityMasks;
typedef xdc_UInt32 **__ARRAY2_ti_sysbios_family_arm_m3_Hwi_Module_State__intAffinityMasks;
typedef __ARRAY2_ti_sysbios_family_arm_m3_Hwi_Module_State__intAffinityMasks __TA_ti_sysbios_family_arm_m3_Hwi_Module_State__intAffinityMasks;


/*
 * ======== MODULE-WIDE CONFIGS ========
 */

/* Module__diagsEnabled */
typedef xdc_Bits32 CT__ti_sysbios_family_arm_m3_Hwi_Module__diagsEnabled;
__extern __FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_Module__diagsEnabled ti_sysbios_family_arm_m3_Hwi_Module__diagsEnabled__C;

/* Module__diagsIncluded */
typedef xdc_Bits32 CT__ti_sysbios_family_arm_m3_Hwi_Module__diagsIncluded;
__extern __FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_Module__diagsIncluded ti_sysbios_family_arm_m3_Hwi_Module__diagsIncluded__C;

/* Module__diagsMask */
typedef xdc_Bits16 *CT__ti_sysbios_family_arm_m3_Hwi_Module__diagsMask;
__extern __FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_Module__diagsMask ti_sysbios_family_arm_m3_Hwi_Module__diagsMask__C;

/* Module__gateObj */
typedef xdc_Ptr CT__ti_sysbios_family_arm_m3_Hwi_Module__gateObj;
__extern __FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_Module__gateObj ti_sysbios_family_arm_m3_Hwi_Module__gateObj__C;

/* Module__gatePrms */
typedef xdc_Ptr CT__ti_sysbios_family_arm_m3_Hwi_Module__gatePrms;
__extern __FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_Module__gatePrms ti_sysbios_family_arm_m3_Hwi_Module__gatePrms__C;

/* Module__id */
typedef xdc_runtime_Types_ModuleId CT__ti_sysbios_family_arm_m3_Hwi_Module__id;
__extern __FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_Module__id ti_sysbios_family_arm_m3_Hwi_Module__id__C;

/* Module__loggerDefined */
typedef xdc_Bool CT__ti_sysbios_family_arm_m3_Hwi_Module__loggerDefined;
__extern __FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_Module__loggerDefined ti_sysbios_family_arm_m3_Hwi_Module__loggerDefined__C;

/* Module__loggerObj */
typedef xdc_Ptr CT__ti_sysbios_family_arm_m3_Hwi_Module__loggerObj;
__extern __FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_Module__loggerObj ti_sysbios_family_arm_m3_Hwi_Module__loggerObj__C;

/* Module__loggerFxn0 */
typedef xdc_runtime_Types_LoggerFxn0 CT__ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn0;
__extern __FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn0 ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn0__C;

/* Module__loggerFxn1 */
typedef xdc_runtime_Types_LoggerFxn1 CT__ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn1;
__extern __FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn1 ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn1__C;

/* Module__loggerFxn2 */
typedef xdc_runtime_Types_LoggerFxn2 CT__ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn2;
__extern __FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn2 ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn2__C;

/* Module__loggerFxn4 */
typedef xdc_runtime_Types_LoggerFxn4 CT__ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn4;
__extern __FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn4 ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn4__C;

/* Module__loggerFxn8 */
typedef xdc_runtime_Types_LoggerFxn8 CT__ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn8;
__extern __FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn8 ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn8__C;

/* Module__startupDoneFxn */
typedef xdc_Bool (*CT__ti_sysbios_family_arm_m3_Hwi_Module__startupDoneFxn)(void);
__extern __FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_Module__startupDoneFxn ti_sysbios_family_arm_m3_Hwi_Module__startupDoneFxn__C;

/* Object__count */
typedef xdc_Int CT__ti_sysbios_family_arm_m3_Hwi_Object__count;
__extern __FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_Object__count ti_sysbios_family_arm_m3_Hwi_Object__count__C;

/* Object__heap */
typedef xdc_runtime_IHeap_Handle CT__ti_sysbios_family_arm_m3_Hwi_Object__heap;
__extern __FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_Object__heap ti_sysbios_family_arm_m3_Hwi_Object__heap__C;

/* Object__sizeof */
typedef xdc_SizeT CT__ti_sysbios_family_arm_m3_Hwi_Object__sizeof;
__extern __FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_Object__sizeof ti_sysbios_family_arm_m3_Hwi_Object__sizeof__C;

/* Object__table */
typedef xdc_Ptr CT__ti_sysbios_family_arm_m3_Hwi_Object__table;
__extern __FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_Object__table ti_sysbios_family_arm_m3_Hwi_Object__table__C;

/* dispatcherAutoNestingSupport */
#ifdef ti_sysbios_family_arm_m3_Hwi_dispatcherAutoNestingSupport__D
#define ti_sysbios_family_arm_m3_Hwi_dispatcherAutoNestingSupport (ti_sysbios_family_arm_m3_Hwi_dispatcherAutoNestingSupport__D)
#else
#define ti_sysbios_family_arm_m3_Hwi_dispatcherAutoNestingSupport (ti_sysbios_family_arm_m3_Hwi_dispatcherAutoNestingSupport__C)
typedef xdc_Bool CT__ti_sysbios_family_arm_m3_Hwi_dispatcherAutoNestingSupport;
__extern __FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_dispatcherAutoNestingSupport ti_sysbios_family_arm_m3_Hwi_dispatcherAutoNestingSupport__C;
#endif

/* dispatcherSwiSupport */
#ifdef ti_sysbios_family_arm_m3_Hwi_dispatcherSwiSupport__D
#define ti_sysbios_family_arm_m3_Hwi_dispatcherSwiSupport (ti_sysbios_family_arm_m3_Hwi_dispatcherSwiSupport__D)
#else
#define ti_sysbios_family_arm_m3_Hwi_dispatcherSwiSupport (ti_sysbios_family_arm_m3_Hwi_dispatcherSwiSupport__C)
typedef xdc_Bool CT__ti_sysbios_family_arm_m3_Hwi_dispatcherSwiSupport;
__extern __FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_dispatcherSwiSupport ti_sysbios_family_arm_m3_Hwi_dispatcherSwiSupport__C;
#endif

/* dispatcherTaskSupport */
#ifdef ti_sysbios_family_arm_m3_Hwi_dispatcherTaskSupport__D
#define ti_sysbios_family_arm_m3_Hwi_dispatcherTaskSupport (ti_sysbios_family_arm_m3_Hwi_dispatcherTaskSupport__D)
#else
#define ti_sysbios_family_arm_m3_Hwi_dispatcherTaskSupport (ti_sysbios_family_arm_m3_Hwi_dispatcherTaskSupport__C)
typedef xdc_Bool CT__ti_sysbios_family_arm_m3_Hwi_dispatcherTaskSupport;
__extern __FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_dispatcherTaskSupport ti_sysbios_family_arm_m3_Hwi_dispatcherTaskSupport__C;
#endif

/* dispatcherIrpTrackingSupport */
#ifdef ti_sysbios_family_arm_m3_Hwi_dispatcherIrpTrackingSupport__D
#define ti_sysbios_family_arm_m3_Hwi_dispatcherIrpTrackingSupport (ti_sysbios_family_arm_m3_Hwi_dispatcherIrpTrackingSupport__D)
#else
#define ti_sysbios_family_arm_m3_Hwi_dispatcherIrpTrackingSupport (ti_sysbios_family_arm_m3_Hwi_dispatcherIrpTrackingSupport__C)
typedef xdc_Bool CT__ti_sysbios_family_arm_m3_Hwi_dispatcherIrpTrackingSupport;
__extern __FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_dispatcherIrpTrackingSupport ti_sysbios_family_arm_m3_Hwi_dispatcherIrpTrackingSupport__C;
#endif

/* NUM_INTERRUPTS */
#ifdef ti_sysbios_family_arm_m3_Hwi_NUM_INTERRUPTS__D
#define ti_sysbios_family_arm_m3_Hwi_NUM_INTERRUPTS (ti_sysbios_family_arm_m3_Hwi_NUM_INTERRUPTS__D)
#else
#define ti_sysbios_family_arm_m3_Hwi_NUM_INTERRUPTS (ti_sysbios_family_arm_m3_Hwi_NUM_INTERRUPTS__C)
typedef xdc_Int CT__ti_sysbios_family_arm_m3_Hwi_NUM_INTERRUPTS;
__extern __FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_NUM_INTERRUPTS ti_sysbios_family_arm_m3_Hwi_NUM_INTERRUPTS__C;
#endif

/* NUM_PRIORITIES */
#ifdef ti_sysbios_family_arm_m3_Hwi_NUM_PRIORITIES__D
#define ti_sysbios_family_arm_m3_Hwi_NUM_PRIORITIES (ti_sysbios_family_arm_m3_Hwi_NUM_PRIORITIES__D)
#else
#define ti_sysbios_family_arm_m3_Hwi_NUM_PRIORITIES (ti_sysbios_family_arm_m3_Hwi_NUM_PRIORITIES__C)
typedef xdc_Int CT__ti_sysbios_family_arm_m3_Hwi_NUM_PRIORITIES;
__extern __FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_NUM_PRIORITIES ti_sysbios_family_arm_m3_Hwi_NUM_PRIORITIES__C;
#endif

/* LM_begin */
#define ti_sysbios_family_arm_m3_Hwi_LM_begin (ti_sysbios_family_arm_m3_Hwi_LM_begin__C)
typedef xdc_runtime_Log_Event CT__ti_sysbios_family_arm_m3_Hwi_LM_begin;
__extern __FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_LM_begin ti_sysbios_family_arm_m3_Hwi_LM_begin__C;

/* LD_end */
#define ti_sysbios_family_arm_m3_Hwi_LD_end (ti_sysbios_family_arm_m3_Hwi_LD_end__C)
typedef xdc_runtime_Log_Event CT__ti_sysbios_family_arm_m3_Hwi_LD_end;
__extern __FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_LD_end ti_sysbios_family_arm_m3_Hwi_LD_end__C;

/* A_unsupportedMaskingOption */
#define ti_sysbios_family_arm_m3_Hwi_A_unsupportedMaskingOption (ti_sysbios_family_arm_m3_Hwi_A_unsupportedMaskingOption__C)
typedef xdc_runtime_Assert_Id CT__ti_sysbios_family_arm_m3_Hwi_A_unsupportedMaskingOption;
__extern __FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_A_unsupportedMaskingOption ti_sysbios_family_arm_m3_Hwi_A_unsupportedMaskingOption__C;

/* E_alreadyDefined */
#define ti_sysbios_family_arm_m3_Hwi_E_alreadyDefined (ti_sysbios_family_arm_m3_Hwi_E_alreadyDefined__C)
typedef xdc_runtime_Error_Id CT__ti_sysbios_family_arm_m3_Hwi_E_alreadyDefined;
__extern __FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_E_alreadyDefined ti_sysbios_family_arm_m3_Hwi_E_alreadyDefined__C;

/* E_hwiLimitExceeded */
#define ti_sysbios_family_arm_m3_Hwi_E_hwiLimitExceeded (ti_sysbios_family_arm_m3_Hwi_E_hwiLimitExceeded__C)
typedef xdc_runtime_Error_Id CT__ti_sysbios_family_arm_m3_Hwi_E_hwiLimitExceeded;
__extern __FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_E_hwiLimitExceeded ti_sysbios_family_arm_m3_Hwi_E_hwiLimitExceeded__C;

/* E_exception */
#define ti_sysbios_family_arm_m3_Hwi_E_exception (ti_sysbios_family_arm_m3_Hwi_E_exception__C)
typedef xdc_runtime_Error_Id CT__ti_sysbios_family_arm_m3_Hwi_E_exception;
__extern __FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_E_exception ti_sysbios_family_arm_m3_Hwi_E_exception__C;

/* E_noIsr */
#define ti_sysbios_family_arm_m3_Hwi_E_noIsr (ti_sysbios_family_arm_m3_Hwi_E_noIsr__C)
typedef xdc_runtime_Error_Id CT__ti_sysbios_family_arm_m3_Hwi_E_noIsr;
__extern __FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_E_noIsr ti_sysbios_family_arm_m3_Hwi_E_noIsr__C;

/* E_NMI */
#define ti_sysbios_family_arm_m3_Hwi_E_NMI (ti_sysbios_family_arm_m3_Hwi_E_NMI__C)
typedef xdc_runtime_Error_Id CT__ti_sysbios_family_arm_m3_Hwi_E_NMI;
__extern __FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_E_NMI ti_sysbios_family_arm_m3_Hwi_E_NMI__C;

/* E_hardFault */
#define ti_sysbios_family_arm_m3_Hwi_E_hardFault (ti_sysbios_family_arm_m3_Hwi_E_hardFault__C)
typedef xdc_runtime_Error_Id CT__ti_sysbios_family_arm_m3_Hwi_E_hardFault;
__extern __FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_E_hardFault ti_sysbios_family_arm_m3_Hwi_E_hardFault__C;

/* E_memFault */
#define ti_sysbios_family_arm_m3_Hwi_E_memFault (ti_sysbios_family_arm_m3_Hwi_E_memFault__C)
typedef xdc_runtime_Error_Id CT__ti_sysbios_family_arm_m3_Hwi_E_memFault;
__extern __FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_E_memFault ti_sysbios_family_arm_m3_Hwi_E_memFault__C;

/* E_busFault */
#define ti_sysbios_family_arm_m3_Hwi_E_busFault (ti_sysbios_family_arm_m3_Hwi_E_busFault__C)
typedef xdc_runtime_Error_Id CT__ti_sysbios_family_arm_m3_Hwi_E_busFault;
__extern __FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_E_busFault ti_sysbios_family_arm_m3_Hwi_E_busFault__C;

/* E_usageFault */
#define ti_sysbios_family_arm_m3_Hwi_E_usageFault (ti_sysbios_family_arm_m3_Hwi_E_usageFault__C)
typedef xdc_runtime_Error_Id CT__ti_sysbios_family_arm_m3_Hwi_E_usageFault;
__extern __FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_E_usageFault ti_sysbios_family_arm_m3_Hwi_E_usageFault__C;

/* E_svCall */
#define ti_sysbios_family_arm_m3_Hwi_E_svCall (ti_sysbios_family_arm_m3_Hwi_E_svCall__C)
typedef xdc_runtime_Error_Id CT__ti_sysbios_family_arm_m3_Hwi_E_svCall;
__extern __FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_E_svCall ti_sysbios_family_arm_m3_Hwi_E_svCall__C;

/* E_debugMon */
#define ti_sysbios_family_arm_m3_Hwi_E_debugMon (ti_sysbios_family_arm_m3_Hwi_E_debugMon__C)
typedef xdc_runtime_Error_Id CT__ti_sysbios_family_arm_m3_Hwi_E_debugMon;
__extern __FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_E_debugMon ti_sysbios_family_arm_m3_Hwi_E_debugMon__C;

/* E_reserved */
#define ti_sysbios_family_arm_m3_Hwi_E_reserved (ti_sysbios_family_arm_m3_Hwi_E_reserved__C)
typedef xdc_runtime_Error_Id CT__ti_sysbios_family_arm_m3_Hwi_E_reserved;
__extern __FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_E_reserved ti_sysbios_family_arm_m3_Hwi_E_reserved__C;

/* nullIsrFunc */
#define ti_sysbios_family_arm_m3_Hwi_nullIsrFunc (ti_sysbios_family_arm_m3_Hwi_nullIsrFunc__C)
typedef ti_sysbios_family_arm_m3_Hwi_VectorFuncPtr CT__ti_sysbios_family_arm_m3_Hwi_nullIsrFunc;
__extern __FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_nullIsrFunc ti_sysbios_family_arm_m3_Hwi_nullIsrFunc__C;

/* excHandlerFunc */
#define ti_sysbios_family_arm_m3_Hwi_excHandlerFunc (ti_sysbios_family_arm_m3_Hwi_excHandlerFunc__C)
typedef ti_sysbios_family_arm_m3_Hwi_ExcHandlerFuncPtr CT__ti_sysbios_family_arm_m3_Hwi_excHandlerFunc;
__extern __FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_excHandlerFunc ti_sysbios_family_arm_m3_Hwi_excHandlerFunc__C;

/* excHookFunc */
#define ti_sysbios_family_arm_m3_Hwi_excHookFunc (ti_sysbios_family_arm_m3_Hwi_excHookFunc__C)
typedef ti_sysbios_family_arm_m3_Hwi_ExceptionHookFuncPtr CT__ti_sysbios_family_arm_m3_Hwi_excHookFunc;
__extern __FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_excHookFunc ti_sysbios_family_arm_m3_Hwi_excHookFunc__C;

/* excHookFuncs */
#define ti_sysbios_family_arm_m3_Hwi_excHookFuncs (ti_sysbios_family_arm_m3_Hwi_excHookFuncs__C)
typedef ti_sysbios_family_arm_m3_Hwi_ExceptionHookFuncPtr __T1_ti_sysbios_family_arm_m3_Hwi_excHookFuncs;
typedef ti_sysbios_family_arm_m3_Hwi_ExceptionHookFuncPtr *__ARRAY1_ti_sysbios_family_arm_m3_Hwi_excHookFuncs;
typedef __ARRAY1_ti_sysbios_family_arm_m3_Hwi_excHookFuncs __TA_ti_sysbios_family_arm_m3_Hwi_excHookFuncs;
typedef __TA_ti_sysbios_family_arm_m3_Hwi_excHookFuncs CT__ti_sysbios_family_arm_m3_Hwi_excHookFuncs;
__extern __FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_excHookFuncs ti_sysbios_family_arm_m3_Hwi_excHookFuncs__C;

/* disablePriority */
#ifdef ti_sysbios_family_arm_m3_Hwi_disablePriority__D
#define ti_sysbios_family_arm_m3_Hwi_disablePriority (ti_sysbios_family_arm_m3_Hwi_disablePriority__D)
#else
#define ti_sysbios_family_arm_m3_Hwi_disablePriority (ti_sysbios_family_arm_m3_Hwi_disablePriority__C)
typedef xdc_UInt CT__ti_sysbios_family_arm_m3_Hwi_disablePriority;
__extern __FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_disablePriority ti_sysbios_family_arm_m3_Hwi_disablePriority__C;
#endif

/* priGroup */
#ifdef ti_sysbios_family_arm_m3_Hwi_priGroup__D
#define ti_sysbios_family_arm_m3_Hwi_priGroup (ti_sysbios_family_arm_m3_Hwi_priGroup__D)
#else
#define ti_sysbios_family_arm_m3_Hwi_priGroup (ti_sysbios_family_arm_m3_Hwi_priGroup__C)
typedef xdc_UInt CT__ti_sysbios_family_arm_m3_Hwi_priGroup;
__extern __FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_priGroup ti_sysbios_family_arm_m3_Hwi_priGroup__C;
#endif

/* numSparseInterrupts */
#ifdef ti_sysbios_family_arm_m3_Hwi_numSparseInterrupts__D
#define ti_sysbios_family_arm_m3_Hwi_numSparseInterrupts (ti_sysbios_family_arm_m3_Hwi_numSparseInterrupts__D)
#else
#define ti_sysbios_family_arm_m3_Hwi_numSparseInterrupts (ti_sysbios_family_arm_m3_Hwi_numSparseInterrupts__C)
typedef xdc_UInt CT__ti_sysbios_family_arm_m3_Hwi_numSparseInterrupts;
__extern __FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_numSparseInterrupts ti_sysbios_family_arm_m3_Hwi_numSparseInterrupts__C;
#endif

/* swiDisable */
#define ti_sysbios_family_arm_m3_Hwi_swiDisable (ti_sysbios_family_arm_m3_Hwi_swiDisable__C)
typedef xdc_UInt (*CT__ti_sysbios_family_arm_m3_Hwi_swiDisable)(void);
__extern __FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_swiDisable ti_sysbios_family_arm_m3_Hwi_swiDisable__C;

/* swiRestoreHwi */
#define ti_sysbios_family_arm_m3_Hwi_swiRestoreHwi (ti_sysbios_family_arm_m3_Hwi_swiRestoreHwi__C)
typedef xdc_Void (*CT__ti_sysbios_family_arm_m3_Hwi_swiRestoreHwi)(xdc_UInt);
__extern __FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_swiRestoreHwi ti_sysbios_family_arm_m3_Hwi_swiRestoreHwi__C;

/* taskDisable */
#define ti_sysbios_family_arm_m3_Hwi_taskDisable (ti_sysbios_family_arm_m3_Hwi_taskDisable__C)
typedef xdc_UInt (*CT__ti_sysbios_family_arm_m3_Hwi_taskDisable)(void);
__extern __FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_taskDisable ti_sysbios_family_arm_m3_Hwi_taskDisable__C;

/* taskRestoreHwi */
#define ti_sysbios_family_arm_m3_Hwi_taskRestoreHwi (ti_sysbios_family_arm_m3_Hwi_taskRestoreHwi__C)
typedef xdc_Void (*CT__ti_sysbios_family_arm_m3_Hwi_taskRestoreHwi)(xdc_UInt);
__extern __FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_taskRestoreHwi ti_sysbios_family_arm_m3_Hwi_taskRestoreHwi__C;

/* ccr */
#ifdef ti_sysbios_family_arm_m3_Hwi_ccr__D
#define ti_sysbios_family_arm_m3_Hwi_ccr (ti_sysbios_family_arm_m3_Hwi_ccr__D)
#else
#define ti_sysbios_family_arm_m3_Hwi_ccr (ti_sysbios_family_arm_m3_Hwi_ccr__C)
typedef xdc_UInt32 CT__ti_sysbios_family_arm_m3_Hwi_ccr;
__extern __FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_ccr ti_sysbios_family_arm_m3_Hwi_ccr__C;
#endif

/* hooks */
#define ti_sysbios_family_arm_m3_Hwi_hooks (ti_sysbios_family_arm_m3_Hwi_hooks__C)
typedef ti_sysbios_family_arm_m3_Hwi_HookSet __T1_ti_sysbios_family_arm_m3_Hwi_hooks;
typedef struct { int length; ti_sysbios_family_arm_m3_Hwi_HookSet *elem; } __ARRAY1_ti_sysbios_family_arm_m3_Hwi_hooks;
typedef __ARRAY1_ti_sysbios_family_arm_m3_Hwi_hooks __TA_ti_sysbios_family_arm_m3_Hwi_hooks;
typedef __TA_ti_sysbios_family_arm_m3_Hwi_hooks CT__ti_sysbios_family_arm_m3_Hwi_hooks;
__extern __FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_hooks ti_sysbios_family_arm_m3_Hwi_hooks__C;


/*
 * ======== PER-INSTANCE TYPES ========
 */

/* Params */
struct ti_sysbios_family_arm_m3_Hwi_Params {
    size_t __size;
    const void *__self;
    void *__fxns;
    xdc_runtime_IInstance_Params *instance;
    ti_sysbios_interfaces_IHwi_MaskingOption maskSetting;
    xdc_UArg arg;
    xdc_Bool enableInt;
    xdc_Int eventId;
    xdc_Int priority;
    xdc_Bool useDispatcher;
    xdc_runtime_IInstance_Params __iprms;
};

/* Struct */
struct ti_sysbios_family_arm_m3_Hwi_Struct {
    const ti_sysbios_family_arm_m3_Hwi_Fxns__ *__fxns;
    xdc_UArg __f0;
    ti_sysbios_family_arm_m3_Hwi_FuncPtr __f1;
    ti_sysbios_family_arm_m3_Hwi_Irp __f2;
    xdc_UInt8 __f3;
    xdc_Int16 __f4;
    __TA_ti_sysbios_family_arm_m3_Hwi_Instance_State__hookEnv __f5;
    xdc_runtime_Types_CordAddr __name;
};


/*
 * ======== VIRTUAL FUNCTIONS ========
 */

/* Fxns__ */
struct ti_sysbios_family_arm_m3_Hwi_Fxns__ {
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
    ti_sysbios_interfaces_IHwi_FuncPtr (*getFunc)(ti_sysbios_family_arm_m3_Hwi_Handle, xdc_UArg*);
    xdc_Void (*setFunc)(ti_sysbios_family_arm_m3_Hwi_Handle, ti_sysbios_interfaces_IHwi_FuncPtr, xdc_UArg);
    xdc_Ptr (*getHookContext)(ti_sysbios_family_arm_m3_Hwi_Handle, xdc_Int);
    xdc_Void (*setHookContext)(ti_sysbios_family_arm_m3_Hwi_Handle, xdc_Int, xdc_Ptr);
    ti_sysbios_interfaces_IHwi_Irp (*getIrp)(ti_sysbios_family_arm_m3_Hwi_Handle);
    xdc_runtime_Types_SysFxns2 __sfxns;
};

/* Module__FXNS__C */
__extern const ti_sysbios_family_arm_m3_Hwi_Fxns__ ti_sysbios_family_arm_m3_Hwi_Module__FXNS__C;


/*
 * ======== FUNCTION DECLARATIONS ========
 */

/* Module_startup */
#define ti_sysbios_family_arm_m3_Hwi_Module_startup ti_sysbios_family_arm_m3_Hwi_Module_startup__E
xdc__CODESECT(ti_sysbios_family_arm_m3_Hwi_Module_startup__E, "ti_sysbios_family_arm_m3_Hwi_Module_startup")
__extern xdc_Int ti_sysbios_family_arm_m3_Hwi_Module_startup__E( xdc_Int state );
xdc__CODESECT(ti_sysbios_family_arm_m3_Hwi_Module_startup__F, "ti_sysbios_family_arm_m3_Hwi_Module_startup")
__extern xdc_Int ti_sysbios_family_arm_m3_Hwi_Module_startup__F( xdc_Int state );

/* Instance_init__E */
xdc__CODESECT(ti_sysbios_family_arm_m3_Hwi_Instance_init__E, "ti_sysbios_family_arm_m3_Hwi_Instance_init")
__extern xdc_Int ti_sysbios_family_arm_m3_Hwi_Instance_init__E(ti_sysbios_family_arm_m3_Hwi_Object *, xdc_Int intNum, ti_sysbios_interfaces_IHwi_FuncPtr hwiFxn, const ti_sysbios_family_arm_m3_Hwi_Params *, xdc_runtime_Error_Block *);

/* Instance_finalize__E */
xdc__CODESECT(ti_sysbios_family_arm_m3_Hwi_Instance_finalize__E, "ti_sysbios_family_arm_m3_Hwi_Instance_finalize")
__extern void ti_sysbios_family_arm_m3_Hwi_Instance_finalize__E( ti_sysbios_family_arm_m3_Hwi_Object* , int );

/* Handle__label__S */
xdc__CODESECT(ti_sysbios_family_arm_m3_Hwi_Handle__label__S, "ti_sysbios_family_arm_m3_Hwi_Handle__label__S")
__extern xdc_runtime_Types_Label *ti_sysbios_family_arm_m3_Hwi_Handle__label__S( xdc_Ptr obj, xdc_runtime_Types_Label *lab );

/* Module__startupDone__S */
xdc__CODESECT(ti_sysbios_family_arm_m3_Hwi_Module__startupDone__S, "ti_sysbios_family_arm_m3_Hwi_Module__startupDone__S")
__extern xdc_Bool ti_sysbios_family_arm_m3_Hwi_Module__startupDone__S( void );

/* Object__create__S */
xdc__CODESECT(ti_sysbios_family_arm_m3_Hwi_Object__create__S, "ti_sysbios_family_arm_m3_Hwi_Object__create__S")
__extern xdc_Ptr ti_sysbios_family_arm_m3_Hwi_Object__create__S( xdc_Ptr __oa, xdc_SizeT __osz, xdc_Ptr __aa, const xdc_UChar *__pa, xdc_SizeT __psz, xdc_runtime_Error_Block *__eb );

/* create */
xdc__CODESECT(ti_sysbios_family_arm_m3_Hwi_create, "ti_sysbios_family_arm_m3_Hwi_create")
__extern ti_sysbios_family_arm_m3_Hwi_Handle ti_sysbios_family_arm_m3_Hwi_create( xdc_Int intNum, ti_sysbios_interfaces_IHwi_FuncPtr hwiFxn, const ti_sysbios_family_arm_m3_Hwi_Params *__prms, xdc_runtime_Error_Block *__eb );

/* construct */
xdc__CODESECT(ti_sysbios_family_arm_m3_Hwi_construct, "ti_sysbios_family_arm_m3_Hwi_construct")
__extern void ti_sysbios_family_arm_m3_Hwi_construct( ti_sysbios_family_arm_m3_Hwi_Struct *__obj, xdc_Int intNum, ti_sysbios_interfaces_IHwi_FuncPtr hwiFxn, const ti_sysbios_family_arm_m3_Hwi_Params *__prms, xdc_runtime_Error_Block *__eb );

/* Object__delete__S */
xdc__CODESECT(ti_sysbios_family_arm_m3_Hwi_Object__delete__S, "ti_sysbios_family_arm_m3_Hwi_Object__delete__S")
__extern xdc_Void ti_sysbios_family_arm_m3_Hwi_Object__delete__S( xdc_Ptr instp );

/* delete */
xdc__CODESECT(ti_sysbios_family_arm_m3_Hwi_delete, "ti_sysbios_family_arm_m3_Hwi_delete")
__extern void ti_sysbios_family_arm_m3_Hwi_delete(ti_sysbios_family_arm_m3_Hwi_Handle *instp);

/* Object__destruct__S */
xdc__CODESECT(ti_sysbios_family_arm_m3_Hwi_Object__destruct__S, "ti_sysbios_family_arm_m3_Hwi_Object__destruct__S")
__extern xdc_Void ti_sysbios_family_arm_m3_Hwi_Object__destruct__S( xdc_Ptr objp );

/* destruct */
xdc__CODESECT(ti_sysbios_family_arm_m3_Hwi_destruct, "ti_sysbios_family_arm_m3_Hwi_destruct")
__extern void ti_sysbios_family_arm_m3_Hwi_destruct(ti_sysbios_family_arm_m3_Hwi_Struct *obj);

/* Object__get__S */
xdc__CODESECT(ti_sysbios_family_arm_m3_Hwi_Object__get__S, "ti_sysbios_family_arm_m3_Hwi_Object__get__S")
__extern xdc_Ptr ti_sysbios_family_arm_m3_Hwi_Object__get__S( xdc_Ptr oarr, xdc_Int i );

/* Object__first__S */
xdc__CODESECT(ti_sysbios_family_arm_m3_Hwi_Object__first__S, "ti_sysbios_family_arm_m3_Hwi_Object__first__S")
__extern xdc_Ptr ti_sysbios_family_arm_m3_Hwi_Object__first__S( void );

/* Object__next__S */
xdc__CODESECT(ti_sysbios_family_arm_m3_Hwi_Object__next__S, "ti_sysbios_family_arm_m3_Hwi_Object__next__S")
__extern xdc_Ptr ti_sysbios_family_arm_m3_Hwi_Object__next__S( xdc_Ptr obj );

/* Params__init__S */
xdc__CODESECT(ti_sysbios_family_arm_m3_Hwi_Params__init__S, "ti_sysbios_family_arm_m3_Hwi_Params__init__S")
__extern xdc_Void ti_sysbios_family_arm_m3_Hwi_Params__init__S( xdc_Ptr dst, const xdc_Void *src, xdc_SizeT psz, xdc_SizeT isz );

/* getStackInfo__E */
#define ti_sysbios_family_arm_m3_Hwi_getStackInfo ti_sysbios_family_arm_m3_Hwi_getStackInfo__E
xdc__CODESECT(ti_sysbios_family_arm_m3_Hwi_getStackInfo__E, "ti_sysbios_family_arm_m3_Hwi_getStackInfo")
__extern xdc_Bool ti_sysbios_family_arm_m3_Hwi_getStackInfo__E( ti_sysbios_interfaces_IHwi_StackInfo *stkInfo, xdc_Bool computeStackDepth );

/* getCoreStackInfo__E */
#define ti_sysbios_family_arm_m3_Hwi_getCoreStackInfo ti_sysbios_family_arm_m3_Hwi_getCoreStackInfo__E
xdc__CODESECT(ti_sysbios_family_arm_m3_Hwi_getCoreStackInfo__E, "ti_sysbios_family_arm_m3_Hwi_getCoreStackInfo")
__extern xdc_Bool ti_sysbios_family_arm_m3_Hwi_getCoreStackInfo__E( ti_sysbios_interfaces_IHwi_StackInfo *stkInfo, xdc_Bool computeStackDepth, xdc_UInt coreId );

/* startup__E */
#define ti_sysbios_family_arm_m3_Hwi_startup ti_sysbios_family_arm_m3_Hwi_startup__E
xdc__CODESECT(ti_sysbios_family_arm_m3_Hwi_startup__E, "ti_sysbios_family_arm_m3_Hwi_startup")
__extern xdc_Void ti_sysbios_family_arm_m3_Hwi_startup__E( void );

/* switchFromBootStack__E */
#define ti_sysbios_family_arm_m3_Hwi_switchFromBootStack ti_sysbios_family_arm_m3_Hwi_switchFromBootStack__E
xdc__CODESECT(ti_sysbios_family_arm_m3_Hwi_switchFromBootStack__E, "ti_sysbios_family_arm_m3_Hwi_switchFromBootStack")
__extern xdc_Void ti_sysbios_family_arm_m3_Hwi_switchFromBootStack__E( void );

/* post__E */
#define ti_sysbios_family_arm_m3_Hwi_post ti_sysbios_family_arm_m3_Hwi_post__E
xdc__CODESECT(ti_sysbios_family_arm_m3_Hwi_post__E, "ti_sysbios_family_arm_m3_Hwi_post")
__extern xdc_Void ti_sysbios_family_arm_m3_Hwi_post__E( xdc_UInt intNum );

/* getTaskSP__E */
#define ti_sysbios_family_arm_m3_Hwi_getTaskSP ti_sysbios_family_arm_m3_Hwi_getTaskSP__E
xdc__CODESECT(ti_sysbios_family_arm_m3_Hwi_getTaskSP__E, "ti_sysbios_family_arm_m3_Hwi_getTaskSP")
__extern xdc_Char *ti_sysbios_family_arm_m3_Hwi_getTaskSP__E( void );

/* disableInterrupt__E */
#define ti_sysbios_family_arm_m3_Hwi_disableInterrupt ti_sysbios_family_arm_m3_Hwi_disableInterrupt__E
xdc__CODESECT(ti_sysbios_family_arm_m3_Hwi_disableInterrupt__E, "ti_sysbios_family_arm_m3_Hwi_disableInterrupt")
__extern xdc_UInt ti_sysbios_family_arm_m3_Hwi_disableInterrupt__E( xdc_UInt intNum );

/* enableInterrupt__E */
#define ti_sysbios_family_arm_m3_Hwi_enableInterrupt ti_sysbios_family_arm_m3_Hwi_enableInterrupt__E
xdc__CODESECT(ti_sysbios_family_arm_m3_Hwi_enableInterrupt__E, "ti_sysbios_family_arm_m3_Hwi_enableInterrupt")
__extern xdc_UInt ti_sysbios_family_arm_m3_Hwi_enableInterrupt__E( xdc_UInt intNum );

/* restoreInterrupt__E */
#define ti_sysbios_family_arm_m3_Hwi_restoreInterrupt ti_sysbios_family_arm_m3_Hwi_restoreInterrupt__E
xdc__CODESECT(ti_sysbios_family_arm_m3_Hwi_restoreInterrupt__E, "ti_sysbios_family_arm_m3_Hwi_restoreInterrupt")
__extern xdc_Void ti_sysbios_family_arm_m3_Hwi_restoreInterrupt__E( xdc_UInt intNum, xdc_UInt key );

/* clearInterrupt__E */
#define ti_sysbios_family_arm_m3_Hwi_clearInterrupt ti_sysbios_family_arm_m3_Hwi_clearInterrupt__E
xdc__CODESECT(ti_sysbios_family_arm_m3_Hwi_clearInterrupt__E, "ti_sysbios_family_arm_m3_Hwi_clearInterrupt")
__extern xdc_Void ti_sysbios_family_arm_m3_Hwi_clearInterrupt__E( xdc_UInt intNum );

/* getFunc__E */
#define ti_sysbios_family_arm_m3_Hwi_getFunc ti_sysbios_family_arm_m3_Hwi_getFunc__E
xdc__CODESECT(ti_sysbios_family_arm_m3_Hwi_getFunc__E, "ti_sysbios_family_arm_m3_Hwi_getFunc")
__extern ti_sysbios_interfaces_IHwi_FuncPtr ti_sysbios_family_arm_m3_Hwi_getFunc__E( ti_sysbios_family_arm_m3_Hwi_Handle __inst, xdc_UArg *arg );

/* setFunc__E */
#define ti_sysbios_family_arm_m3_Hwi_setFunc ti_sysbios_family_arm_m3_Hwi_setFunc__E
xdc__CODESECT(ti_sysbios_family_arm_m3_Hwi_setFunc__E, "ti_sysbios_family_arm_m3_Hwi_setFunc")
__extern xdc_Void ti_sysbios_family_arm_m3_Hwi_setFunc__E( ti_sysbios_family_arm_m3_Hwi_Handle __inst, ti_sysbios_interfaces_IHwi_FuncPtr fxn, xdc_UArg arg );

/* getHookContext__E */
#define ti_sysbios_family_arm_m3_Hwi_getHookContext ti_sysbios_family_arm_m3_Hwi_getHookContext__E
xdc__CODESECT(ti_sysbios_family_arm_m3_Hwi_getHookContext__E, "ti_sysbios_family_arm_m3_Hwi_getHookContext")
__extern xdc_Ptr ti_sysbios_family_arm_m3_Hwi_getHookContext__E( ti_sysbios_family_arm_m3_Hwi_Handle __inst, xdc_Int id );

/* setHookContext__E */
#define ti_sysbios_family_arm_m3_Hwi_setHookContext ti_sysbios_family_arm_m3_Hwi_setHookContext__E
xdc__CODESECT(ti_sysbios_family_arm_m3_Hwi_setHookContext__E, "ti_sysbios_family_arm_m3_Hwi_setHookContext")
__extern xdc_Void ti_sysbios_family_arm_m3_Hwi_setHookContext__E( ti_sysbios_family_arm_m3_Hwi_Handle __inst, xdc_Int id, xdc_Ptr hookContext );

/* getIrp__E */
#define ti_sysbios_family_arm_m3_Hwi_getIrp ti_sysbios_family_arm_m3_Hwi_getIrp__E
xdc__CODESECT(ti_sysbios_family_arm_m3_Hwi_getIrp__E, "ti_sysbios_family_arm_m3_Hwi_getIrp")
__extern ti_sysbios_interfaces_IHwi_Irp ti_sysbios_family_arm_m3_Hwi_getIrp__E( ti_sysbios_family_arm_m3_Hwi_Handle __inst );

/* disableFxn__E */
#define ti_sysbios_family_arm_m3_Hwi_disableFxn ti_sysbios_family_arm_m3_Hwi_disableFxn__E
xdc__CODESECT(ti_sysbios_family_arm_m3_Hwi_disableFxn__E, "ti_sysbios_family_arm_m3_Hwi_disableFxn")
__extern xdc_UInt ti_sysbios_family_arm_m3_Hwi_disableFxn__E( void );

/* enableFxn__E */
#define ti_sysbios_family_arm_m3_Hwi_enableFxn ti_sysbios_family_arm_m3_Hwi_enableFxn__E
xdc__CODESECT(ti_sysbios_family_arm_m3_Hwi_enableFxn__E, "ti_sysbios_family_arm_m3_Hwi_enableFxn")
__extern xdc_UInt ti_sysbios_family_arm_m3_Hwi_enableFxn__E( void );

/* restoreFxn__E */
#define ti_sysbios_family_arm_m3_Hwi_restoreFxn ti_sysbios_family_arm_m3_Hwi_restoreFxn__E
xdc__CODESECT(ti_sysbios_family_arm_m3_Hwi_restoreFxn__E, "ti_sysbios_family_arm_m3_Hwi_restoreFxn")
__extern xdc_Void ti_sysbios_family_arm_m3_Hwi_restoreFxn__E( xdc_UInt key );

/* plug__E */
#define ti_sysbios_family_arm_m3_Hwi_plug ti_sysbios_family_arm_m3_Hwi_plug__E
xdc__CODESECT(ti_sysbios_family_arm_m3_Hwi_plug__E, "ti_sysbios_family_arm_m3_Hwi_plug")
__extern xdc_Void ti_sysbios_family_arm_m3_Hwi_plug__E( xdc_UInt intNum, xdc_Void *fxn );

/* getHandle__E */
#define ti_sysbios_family_arm_m3_Hwi_getHandle ti_sysbios_family_arm_m3_Hwi_getHandle__E
xdc__CODESECT(ti_sysbios_family_arm_m3_Hwi_getHandle__E, "ti_sysbios_family_arm_m3_Hwi_getHandle")
__extern ti_sysbios_family_arm_m3_Hwi_Handle ti_sysbios_family_arm_m3_Hwi_getHandle__E( xdc_UInt intNum );

/* setPriority__E */
#define ti_sysbios_family_arm_m3_Hwi_setPriority ti_sysbios_family_arm_m3_Hwi_setPriority__E
xdc__CODESECT(ti_sysbios_family_arm_m3_Hwi_setPriority__E, "ti_sysbios_family_arm_m3_Hwi_setPriority")
__extern xdc_Void ti_sysbios_family_arm_m3_Hwi_setPriority__E( xdc_UInt intNum, xdc_UInt priority );

/* excSetBuffers__E */
#define ti_sysbios_family_arm_m3_Hwi_excSetBuffers ti_sysbios_family_arm_m3_Hwi_excSetBuffers__E
xdc__CODESECT(ti_sysbios_family_arm_m3_Hwi_excSetBuffers__E, "ti_sysbios_family_arm_m3_Hwi_excSetBuffers")
__extern xdc_Void ti_sysbios_family_arm_m3_Hwi_excSetBuffers__E( xdc_Ptr excContextBuffer, xdc_Ptr excStackBuffer );

/* initNVIC__E */
#define ti_sysbios_family_arm_m3_Hwi_initNVIC ti_sysbios_family_arm_m3_Hwi_initNVIC__E
xdc__CODESECT(ti_sysbios_family_arm_m3_Hwi_initNVIC__E, "ti_sysbios_family_arm_m3_Hwi_initNVIC")
__extern xdc_Void ti_sysbios_family_arm_m3_Hwi_initNVIC__E( void );

/* initStacks__E */
#define ti_sysbios_family_arm_m3_Hwi_initStacks ti_sysbios_family_arm_m3_Hwi_initStacks__E
xdc__CODESECT(ti_sysbios_family_arm_m3_Hwi_initStacks__E, "ti_sysbios_family_arm_m3_Hwi_initStacks")
__extern xdc_Void ti_sysbios_family_arm_m3_Hwi_initStacks__E( xdc_Ptr hwiStack );

/* flushVnvic__E */
#define ti_sysbios_family_arm_m3_Hwi_flushVnvic ti_sysbios_family_arm_m3_Hwi_flushVnvic__E
xdc__CODESECT(ti_sysbios_family_arm_m3_Hwi_flushVnvic__E, "ti_sysbios_family_arm_m3_Hwi_flushVnvic")
__extern xdc_Void ti_sysbios_family_arm_m3_Hwi_flushVnvic__E( void );

/* reconfig__E */
#define ti_sysbios_family_arm_m3_Hwi_reconfig ti_sysbios_family_arm_m3_Hwi_reconfig__E
xdc__CODESECT(ti_sysbios_family_arm_m3_Hwi_reconfig__E, "ti_sysbios_family_arm_m3_Hwi_reconfig")
__extern xdc_Void ti_sysbios_family_arm_m3_Hwi_reconfig__E( ti_sysbios_family_arm_m3_Hwi_Handle __inst, ti_sysbios_family_arm_m3_Hwi_FuncPtr fxn, const ti_sysbios_family_arm_m3_Hwi_Params *params );

/* postInit__I */
#define ti_sysbios_family_arm_m3_Hwi_postInit ti_sysbios_family_arm_m3_Hwi_postInit__I
xdc__CODESECT(ti_sysbios_family_arm_m3_Hwi_postInit__I, "ti_sysbios_family_arm_m3_Hwi_postInit")
__extern xdc_Int ti_sysbios_family_arm_m3_Hwi_postInit__I( ti_sysbios_family_arm_m3_Hwi_Object *hwi, xdc_runtime_Error_Block *eb );

/* updateNvic__I */
#define ti_sysbios_family_arm_m3_Hwi_updateNvic ti_sysbios_family_arm_m3_Hwi_updateNvic__I
xdc__CODESECT(ti_sysbios_family_arm_m3_Hwi_updateNvic__I, "ti_sysbios_family_arm_m3_Hwi_updateNvic")
__extern xdc_Void ti_sysbios_family_arm_m3_Hwi_updateNvic__I( xdc_UInt intNum );

/* excHandlerAsm__I */
#define ti_sysbios_family_arm_m3_Hwi_excHandlerAsm ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I
xdc__CODESECT(ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I, "ti_sysbios_family_arm_m3_Hwi_excHandlerAsm")
__extern xdc_Void ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I( void );

/* excHandler__I */
#define ti_sysbios_family_arm_m3_Hwi_excHandler ti_sysbios_family_arm_m3_Hwi_excHandler__I
xdc__CODESECT(ti_sysbios_family_arm_m3_Hwi_excHandler__I, "ti_sysbios_family_arm_m3_Hwi_excHandler")
__extern xdc_Void ti_sysbios_family_arm_m3_Hwi_excHandler__I( xdc_UInt *excStack, xdc_UInt lr );

/* excHandlerMin__I */
#define ti_sysbios_family_arm_m3_Hwi_excHandlerMin ti_sysbios_family_arm_m3_Hwi_excHandlerMin__I
xdc__CODESECT(ti_sysbios_family_arm_m3_Hwi_excHandlerMin__I, "ti_sysbios_family_arm_m3_Hwi_excHandlerMin")
__extern xdc_Void ti_sysbios_family_arm_m3_Hwi_excHandlerMin__I( xdc_UInt *excStack, xdc_UInt lr );

/* excHandlerMax__I */
#define ti_sysbios_family_arm_m3_Hwi_excHandlerMax ti_sysbios_family_arm_m3_Hwi_excHandlerMax__I
xdc__CODESECT(ti_sysbios_family_arm_m3_Hwi_excHandlerMax__I, "ti_sysbios_family_arm_m3_Hwi_excHandlerMax")
__extern xdc_Void ti_sysbios_family_arm_m3_Hwi_excHandlerMax__I( xdc_UInt *excStack, xdc_UInt lr );

/* excFillContext__I */
#define ti_sysbios_family_arm_m3_Hwi_excFillContext ti_sysbios_family_arm_m3_Hwi_excFillContext__I
xdc__CODESECT(ti_sysbios_family_arm_m3_Hwi_excFillContext__I, "ti_sysbios_family_arm_m3_Hwi_excFillContext")
__extern xdc_Void ti_sysbios_family_arm_m3_Hwi_excFillContext__I( xdc_UInt *excStack );

/* excNmi__I */
#define ti_sysbios_family_arm_m3_Hwi_excNmi ti_sysbios_family_arm_m3_Hwi_excNmi__I
xdc__CODESECT(ti_sysbios_family_arm_m3_Hwi_excNmi__I, "ti_sysbios_family_arm_m3_Hwi_excNmi")
__extern xdc_Void ti_sysbios_family_arm_m3_Hwi_excNmi__I( xdc_UInt *excStack );

/* excHardFault__I */
#define ti_sysbios_family_arm_m3_Hwi_excHardFault ti_sysbios_family_arm_m3_Hwi_excHardFault__I
xdc__CODESECT(ti_sysbios_family_arm_m3_Hwi_excHardFault__I, "ti_sysbios_family_arm_m3_Hwi_excHardFault")
__extern xdc_Void ti_sysbios_family_arm_m3_Hwi_excHardFault__I( xdc_UInt *excStack );

/* excMemFault__I */
#define ti_sysbios_family_arm_m3_Hwi_excMemFault ti_sysbios_family_arm_m3_Hwi_excMemFault__I
xdc__CODESECT(ti_sysbios_family_arm_m3_Hwi_excMemFault__I, "ti_sysbios_family_arm_m3_Hwi_excMemFault")
__extern xdc_Void ti_sysbios_family_arm_m3_Hwi_excMemFault__I( xdc_UInt *excStack );

/* excBusFault__I */
#define ti_sysbios_family_arm_m3_Hwi_excBusFault ti_sysbios_family_arm_m3_Hwi_excBusFault__I
xdc__CODESECT(ti_sysbios_family_arm_m3_Hwi_excBusFault__I, "ti_sysbios_family_arm_m3_Hwi_excBusFault")
__extern xdc_Void ti_sysbios_family_arm_m3_Hwi_excBusFault__I( xdc_UInt *excStack );

/* excUsageFault__I */
#define ti_sysbios_family_arm_m3_Hwi_excUsageFault ti_sysbios_family_arm_m3_Hwi_excUsageFault__I
xdc__CODESECT(ti_sysbios_family_arm_m3_Hwi_excUsageFault__I, "ti_sysbios_family_arm_m3_Hwi_excUsageFault")
__extern xdc_Void ti_sysbios_family_arm_m3_Hwi_excUsageFault__I( xdc_UInt *excStack );

/* excSvCall__I */
#define ti_sysbios_family_arm_m3_Hwi_excSvCall ti_sysbios_family_arm_m3_Hwi_excSvCall__I
xdc__CODESECT(ti_sysbios_family_arm_m3_Hwi_excSvCall__I, "ti_sysbios_family_arm_m3_Hwi_excSvCall")
__extern xdc_Void ti_sysbios_family_arm_m3_Hwi_excSvCall__I( xdc_UInt *excStack );

/* excDebugMon__I */
#define ti_sysbios_family_arm_m3_Hwi_excDebugMon ti_sysbios_family_arm_m3_Hwi_excDebugMon__I
xdc__CODESECT(ti_sysbios_family_arm_m3_Hwi_excDebugMon__I, "ti_sysbios_family_arm_m3_Hwi_excDebugMon")
__extern xdc_Void ti_sysbios_family_arm_m3_Hwi_excDebugMon__I( xdc_UInt *excStack );

/* excReserved__I */
#define ti_sysbios_family_arm_m3_Hwi_excReserved ti_sysbios_family_arm_m3_Hwi_excReserved__I
xdc__CODESECT(ti_sysbios_family_arm_m3_Hwi_excReserved__I, "ti_sysbios_family_arm_m3_Hwi_excReserved")
__extern xdc_Void ti_sysbios_family_arm_m3_Hwi_excReserved__I( xdc_UInt *excStack, xdc_UInt excNum );

/* excNoIsr__I */
#define ti_sysbios_family_arm_m3_Hwi_excNoIsr ti_sysbios_family_arm_m3_Hwi_excNoIsr__I
xdc__CODESECT(ti_sysbios_family_arm_m3_Hwi_excNoIsr__I, "ti_sysbios_family_arm_m3_Hwi_excNoIsr")
__extern xdc_Void ti_sysbios_family_arm_m3_Hwi_excNoIsr__I( xdc_UInt *excStack, xdc_UInt excNum );

/* excDumpRegs__I */
#define ti_sysbios_family_arm_m3_Hwi_excDumpRegs ti_sysbios_family_arm_m3_Hwi_excDumpRegs__I
xdc__CODESECT(ti_sysbios_family_arm_m3_Hwi_excDumpRegs__I, "ti_sysbios_family_arm_m3_Hwi_excDumpRegs")
__extern xdc_Void ti_sysbios_family_arm_m3_Hwi_excDumpRegs__I( xdc_UInt lr );

/* pendSV__I */
#define ti_sysbios_family_arm_m3_Hwi_pendSV ti_sysbios_family_arm_m3_Hwi_pendSV__I
xdc__CODESECT(ti_sysbios_family_arm_m3_Hwi_pendSV__I, "ti_sysbios_family_arm_m3_Hwi_pendSV")
__extern xdc_Void ti_sysbios_family_arm_m3_Hwi_pendSV__I( void );

/* dispatch__I */
#define ti_sysbios_family_arm_m3_Hwi_dispatch ti_sysbios_family_arm_m3_Hwi_dispatch__I
xdc__CODESECT(ti_sysbios_family_arm_m3_Hwi_dispatch__I, "ti_sysbios_family_arm_m3_Hwi_dispatch")
__extern xdc_Void ti_sysbios_family_arm_m3_Hwi_dispatch__I( void );

/* cc26xxRomInitNVIC__I */
#define ti_sysbios_family_arm_m3_Hwi_cc26xxRomInitNVIC ti_sysbios_family_arm_m3_Hwi_cc26xxRomInitNVIC__I
xdc__CODESECT(ti_sysbios_family_arm_m3_Hwi_cc26xxRomInitNVIC__I, "ti_sysbios_family_arm_m3_Hwi_cc26xxRomInitNVIC")
__extern xdc_Void ti_sysbios_family_arm_m3_Hwi_cc26xxRomInitNVIC__I( void );

/* dispatchC__I */
#define ti_sysbios_family_arm_m3_Hwi_dispatchC ti_sysbios_family_arm_m3_Hwi_dispatchC__I
xdc__CODESECT(ti_sysbios_family_arm_m3_Hwi_dispatchC__I, "ti_sysbios_family_arm_m3_Hwi_dispatchC")
__extern xdc_UInt ti_sysbios_family_arm_m3_Hwi_dispatchC__I( ti_sysbios_family_arm_m3_Hwi_Irp irp, xdc_UInt32 dummy1, xdc_UInt32 dummy2, ti_sysbios_family_arm_m3_Hwi_Object *hwi );

/* doSwiRestore__I */
#define ti_sysbios_family_arm_m3_Hwi_doSwiRestore ti_sysbios_family_arm_m3_Hwi_doSwiRestore__I
xdc__CODESECT(ti_sysbios_family_arm_m3_Hwi_doSwiRestore__I, "ti_sysbios_family_arm_m3_Hwi_doSwiRestore")
__extern xdc_Void ti_sysbios_family_arm_m3_Hwi_doSwiRestore__I( xdc_UInt tskKey );

/* doTaskRestore__I */
#define ti_sysbios_family_arm_m3_Hwi_doTaskRestore ti_sysbios_family_arm_m3_Hwi_doTaskRestore__I
xdc__CODESECT(ti_sysbios_family_arm_m3_Hwi_doTaskRestore__I, "ti_sysbios_family_arm_m3_Hwi_doTaskRestore")
__extern xdc_Void ti_sysbios_family_arm_m3_Hwi_doTaskRestore__I( xdc_UInt tskKey );


/*
 * ======== CONVERTORS ========
 */

/* Module_upCast */
static inline ti_sysbios_interfaces_IHwi_Module ti_sysbios_family_arm_m3_Hwi_Module_upCast( void )
{
    return (ti_sysbios_interfaces_IHwi_Module)&ti_sysbios_family_arm_m3_Hwi_Module__FXNS__C;
}

/* Module_to_ti_sysbios_interfaces_IHwi */
#define ti_sysbios_family_arm_m3_Hwi_Module_to_ti_sysbios_interfaces_IHwi ti_sysbios_family_arm_m3_Hwi_Module_upCast

/* Handle_upCast */
static inline ti_sysbios_interfaces_IHwi_Handle ti_sysbios_family_arm_m3_Hwi_Handle_upCast( ti_sysbios_family_arm_m3_Hwi_Handle i )
{
    return (ti_sysbios_interfaces_IHwi_Handle)i;
}

/* Handle_to_ti_sysbios_interfaces_IHwi */
#define ti_sysbios_family_arm_m3_Hwi_Handle_to_ti_sysbios_interfaces_IHwi ti_sysbios_family_arm_m3_Hwi_Handle_upCast

/* Handle_downCast */
static inline ti_sysbios_family_arm_m3_Hwi_Handle ti_sysbios_family_arm_m3_Hwi_Handle_downCast( ti_sysbios_interfaces_IHwi_Handle i )
{
    ti_sysbios_interfaces_IHwi_Handle i2 = (ti_sysbios_interfaces_IHwi_Handle)i;
    return (void*)i2->__fxns == (void*)&ti_sysbios_family_arm_m3_Hwi_Module__FXNS__C ? (ti_sysbios_family_arm_m3_Hwi_Handle)i : 0;
}

/* Handle_from_ti_sysbios_interfaces_IHwi */
#define ti_sysbios_family_arm_m3_Hwi_Handle_from_ti_sysbios_interfaces_IHwi ti_sysbios_family_arm_m3_Hwi_Handle_downCast


/*
 * ======== SYSTEM FUNCTIONS ========
 */

/* Module_startupDone */
#define ti_sysbios_family_arm_m3_Hwi_Module_startupDone() ti_sysbios_family_arm_m3_Hwi_Module__startupDone__S()

/* Object_heap */
#define ti_sysbios_family_arm_m3_Hwi_Object_heap() ti_sysbios_family_arm_m3_Hwi_Object__heap__C

/* Module_heap */
#define ti_sysbios_family_arm_m3_Hwi_Module_heap() ti_sysbios_family_arm_m3_Hwi_Object__heap__C

/* Module_id */
static inline CT__ti_sysbios_family_arm_m3_Hwi_Module__id ti_sysbios_family_arm_m3_Hwi_Module_id( void ) 
{
    return ti_sysbios_family_arm_m3_Hwi_Module__id__C;
}

/* Module_hasMask */
static inline xdc_Bool ti_sysbios_family_arm_m3_Hwi_Module_hasMask( void ) 
{
    return ti_sysbios_family_arm_m3_Hwi_Module__diagsMask__C != NULL;
}

/* Module_getMask */
static inline xdc_Bits16 ti_sysbios_family_arm_m3_Hwi_Module_getMask( void ) 
{
    return ti_sysbios_family_arm_m3_Hwi_Module__diagsMask__C != NULL ? *ti_sysbios_family_arm_m3_Hwi_Module__diagsMask__C : 0;
}

/* Module_setMask */
static inline xdc_Void ti_sysbios_family_arm_m3_Hwi_Module_setMask( xdc_Bits16 mask ) 
{
    if (ti_sysbios_family_arm_m3_Hwi_Module__diagsMask__C != NULL) *ti_sysbios_family_arm_m3_Hwi_Module__diagsMask__C = mask;
}

/* Params_init */
static inline void ti_sysbios_family_arm_m3_Hwi_Params_init( ti_sysbios_family_arm_m3_Hwi_Params *prms ) 
{
    if (prms) {
        ti_sysbios_family_arm_m3_Hwi_Params__init__S(prms, 0, sizeof(ti_sysbios_family_arm_m3_Hwi_Params), sizeof(xdc_runtime_IInstance_Params));
    }
}

/* Params_copy */
static inline void ti_sysbios_family_arm_m3_Hwi_Params_copy(ti_sysbios_family_arm_m3_Hwi_Params *dst, const ti_sysbios_family_arm_m3_Hwi_Params *src) 
{
    if (dst) {
        ti_sysbios_family_arm_m3_Hwi_Params__init__S(dst, (const void *)src, sizeof(ti_sysbios_family_arm_m3_Hwi_Params), sizeof(xdc_runtime_IInstance_Params));
    }
}

/* Object_count */
#define ti_sysbios_family_arm_m3_Hwi_Object_count() ti_sysbios_family_arm_m3_Hwi_Object__count__C

/* Object_sizeof */
#define ti_sysbios_family_arm_m3_Hwi_Object_sizeof() ti_sysbios_family_arm_m3_Hwi_Object__sizeof__C

/* Object_get */
static inline ti_sysbios_family_arm_m3_Hwi_Handle ti_sysbios_family_arm_m3_Hwi_Object_get(ti_sysbios_family_arm_m3_Hwi_Instance_State *oarr, int i) 
{
    return (ti_sysbios_family_arm_m3_Hwi_Handle)ti_sysbios_family_arm_m3_Hwi_Object__get__S(oarr, i);
}

/* Object_first */
static inline ti_sysbios_family_arm_m3_Hwi_Handle ti_sysbios_family_arm_m3_Hwi_Object_first( void )
{
    return (ti_sysbios_family_arm_m3_Hwi_Handle)ti_sysbios_family_arm_m3_Hwi_Object__first__S();
}

/* Object_next */
static inline ti_sysbios_family_arm_m3_Hwi_Handle ti_sysbios_family_arm_m3_Hwi_Object_next( ti_sysbios_family_arm_m3_Hwi_Object *obj )
{
    return (ti_sysbios_family_arm_m3_Hwi_Handle)ti_sysbios_family_arm_m3_Hwi_Object__next__S(obj);
}

/* Handle_label */
static inline xdc_runtime_Types_Label *ti_sysbios_family_arm_m3_Hwi_Handle_label( ti_sysbios_family_arm_m3_Hwi_Handle inst, xdc_runtime_Types_Label *lab )
{
    return ti_sysbios_family_arm_m3_Hwi_Handle__label__S(inst, lab);
}

/* Handle_name */
static inline xdc_String ti_sysbios_family_arm_m3_Hwi_Handle_name( ti_sysbios_family_arm_m3_Hwi_Handle inst )
{
    xdc_runtime_Types_Label lab;
    return ti_sysbios_family_arm_m3_Hwi_Handle__label__S(inst, &lab)->iname;
}

/* handle */
static inline ti_sysbios_family_arm_m3_Hwi_Handle ti_sysbios_family_arm_m3_Hwi_handle( ti_sysbios_family_arm_m3_Hwi_Struct *str )
{
    return (ti_sysbios_family_arm_m3_Hwi_Handle)str;
}

/* struct */
static inline ti_sysbios_family_arm_m3_Hwi_Struct *ti_sysbios_family_arm_m3_Hwi_struct( ti_sysbios_family_arm_m3_Hwi_Handle inst )
{
    return (ti_sysbios_family_arm_m3_Hwi_Struct*)inst;
}


/*
 * ======== EPILOGUE ========
 */

#include <ti/sysbios/family/arm/m3/Hwi__epilogue.h>

#ifdef ti_sysbios_family_arm_m3_Hwi__top__
#undef __nested__
#endif

#endif /* ti_sysbios_family_arm_m3_Hwi__include */


/*
 * ======== STATE STRUCTURES ========
 */

#if defined(__config__) || (!defined(__nested__) && defined(ti_sysbios_family_arm_m3_Hwi__internalaccess))

#ifndef ti_sysbios_family_arm_m3_Hwi__include_state
#define ti_sysbios_family_arm_m3_Hwi__include_state

/* Module_State */
struct ti_sysbios_family_arm_m3_Hwi_Module_State {
    xdc_Char *taskSP;
    __TA_ti_sysbios_family_arm_m3_Hwi_Module_State__excActive excActive;
    __TA_ti_sysbios_family_arm_m3_Hwi_Module_State__excContext excContext;
    __TA_ti_sysbios_family_arm_m3_Hwi_Module_State__excStack excStack;
    xdc_Ptr isrStack;
    xdc_Ptr isrStackBase;
    xdc_SizeT isrStackSize;
    xdc_Ptr vectorTableBase;
    xdc_UInt swiTaskKeys;
    xdc_Ptr dispatchTable;
    volatile xdc_Bool vnvicFlushRequired;
    __TA_ti_sysbios_family_arm_m3_Hwi_Module_State__intAffinity intAffinity;
    __TA_ti_sysbios_family_arm_m3_Hwi_Module_State__intAffinityMasks intAffinityMasks;
};

/* Module__state__V */
extern struct ti_sysbios_family_arm_m3_Hwi_Module_State__ ti_sysbios_family_arm_m3_Hwi_Module__state__V;

/* Object */
struct ti_sysbios_family_arm_m3_Hwi_Object {
    const ti_sysbios_family_arm_m3_Hwi_Fxns__ *__fxns;
    xdc_UArg arg;
    ti_sysbios_family_arm_m3_Hwi_FuncPtr fxn;
    ti_sysbios_family_arm_m3_Hwi_Irp irp;
    xdc_UInt8 priority;
    xdc_Int16 intNum;
    __TA_ti_sysbios_family_arm_m3_Hwi_Instance_State__hookEnv hookEnv;
};

#endif /* ti_sysbios_family_arm_m3_Hwi__include_state */

#endif


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(ti_sysbios_family_arm_m3_Hwi__nolocalnames)

#ifndef ti_sysbios_family_arm_m3_Hwi__localnames__done
#define ti_sysbios_family_arm_m3_Hwi__localnames__done

/* module prefix */
#define Hwi_Instance ti_sysbios_family_arm_m3_Hwi_Instance
#define Hwi_Handle ti_sysbios_family_arm_m3_Hwi_Handle
#define Hwi_Module ti_sysbios_family_arm_m3_Hwi_Module
#define Hwi_Object ti_sysbios_family_arm_m3_Hwi_Object
#define Hwi_Struct ti_sysbios_family_arm_m3_Hwi_Struct
#define Hwi_FuncPtr ti_sysbios_family_arm_m3_Hwi_FuncPtr
#define Hwi_Irp ti_sysbios_family_arm_m3_Hwi_Irp
#define Hwi_HookSet ti_sysbios_family_arm_m3_Hwi_HookSet
#define Hwi_MaskingOption ti_sysbios_family_arm_m3_Hwi_MaskingOption
#define Hwi_StackInfo ti_sysbios_family_arm_m3_Hwi_StackInfo
#define Hwi_VectorFuncPtr ti_sysbios_family_arm_m3_Hwi_VectorFuncPtr
#define Hwi_ExceptionHookFuncPtr ti_sysbios_family_arm_m3_Hwi_ExceptionHookFuncPtr
#define Hwi_CCR ti_sysbios_family_arm_m3_Hwi_CCR
#define Hwi_NVIC ti_sysbios_family_arm_m3_Hwi_NVIC
#define Hwi_nvic ti_sysbios_family_arm_m3_Hwi_nvic
#define Hwi_vnvic ti_sysbios_family_arm_m3_Hwi_vnvic
#define Hwi_ExcContext ti_sysbios_family_arm_m3_Hwi_ExcContext
#define Hwi_ExcHandlerFuncPtr ti_sysbios_family_arm_m3_Hwi_ExcHandlerFuncPtr
#define Hwi_HandlerFuncPtr ti_sysbios_family_arm_m3_Hwi_HandlerFuncPtr
#define Hwi_Instance_State ti_sysbios_family_arm_m3_Hwi_Instance_State
#define Hwi_Module_State ti_sysbios_family_arm_m3_Hwi_Module_State
#define Hwi_MaskingOption_NONE ti_sysbios_family_arm_m3_Hwi_MaskingOption_NONE
#define Hwi_MaskingOption_ALL ti_sysbios_family_arm_m3_Hwi_MaskingOption_ALL
#define Hwi_MaskingOption_SELF ti_sysbios_family_arm_m3_Hwi_MaskingOption_SELF
#define Hwi_MaskingOption_BITMASK ti_sysbios_family_arm_m3_Hwi_MaskingOption_BITMASK
#define Hwi_MaskingOption_LOWER ti_sysbios_family_arm_m3_Hwi_MaskingOption_LOWER
#define Hwi_dispatcherAutoNestingSupport ti_sysbios_family_arm_m3_Hwi_dispatcherAutoNestingSupport
#define Hwi_dispatcherSwiSupport ti_sysbios_family_arm_m3_Hwi_dispatcherSwiSupport
#define Hwi_dispatcherTaskSupport ti_sysbios_family_arm_m3_Hwi_dispatcherTaskSupport
#define Hwi_dispatcherIrpTrackingSupport ti_sysbios_family_arm_m3_Hwi_dispatcherIrpTrackingSupport
#define Hwi_NUM_INTERRUPTS ti_sysbios_family_arm_m3_Hwi_NUM_INTERRUPTS
#define Hwi_NUM_PRIORITIES ti_sysbios_family_arm_m3_Hwi_NUM_PRIORITIES
#define Hwi_LM_begin ti_sysbios_family_arm_m3_Hwi_LM_begin
#define Hwi_LD_end ti_sysbios_family_arm_m3_Hwi_LD_end
#define Hwi_A_unsupportedMaskingOption ti_sysbios_family_arm_m3_Hwi_A_unsupportedMaskingOption
#define Hwi_E_alreadyDefined ti_sysbios_family_arm_m3_Hwi_E_alreadyDefined
#define Hwi_E_hwiLimitExceeded ti_sysbios_family_arm_m3_Hwi_E_hwiLimitExceeded
#define Hwi_E_exception ti_sysbios_family_arm_m3_Hwi_E_exception
#define Hwi_E_noIsr ti_sysbios_family_arm_m3_Hwi_E_noIsr
#define Hwi_E_NMI ti_sysbios_family_arm_m3_Hwi_E_NMI
#define Hwi_E_hardFault ti_sysbios_family_arm_m3_Hwi_E_hardFault
#define Hwi_E_memFault ti_sysbios_family_arm_m3_Hwi_E_memFault
#define Hwi_E_busFault ti_sysbios_family_arm_m3_Hwi_E_busFault
#define Hwi_E_usageFault ti_sysbios_family_arm_m3_Hwi_E_usageFault
#define Hwi_E_svCall ti_sysbios_family_arm_m3_Hwi_E_svCall
#define Hwi_E_debugMon ti_sysbios_family_arm_m3_Hwi_E_debugMon
#define Hwi_E_reserved ti_sysbios_family_arm_m3_Hwi_E_reserved
#define Hwi_nullIsrFunc ti_sysbios_family_arm_m3_Hwi_nullIsrFunc
#define Hwi_excHandlerFunc ti_sysbios_family_arm_m3_Hwi_excHandlerFunc
#define Hwi_excHookFunc ti_sysbios_family_arm_m3_Hwi_excHookFunc
#define Hwi_excHookFuncs ti_sysbios_family_arm_m3_Hwi_excHookFuncs
#define Hwi_disablePriority ti_sysbios_family_arm_m3_Hwi_disablePriority
#define Hwi_priGroup ti_sysbios_family_arm_m3_Hwi_priGroup
#define Hwi_numSparseInterrupts ti_sysbios_family_arm_m3_Hwi_numSparseInterrupts
#define Hwi_swiDisable ti_sysbios_family_arm_m3_Hwi_swiDisable
#define Hwi_swiRestoreHwi ti_sysbios_family_arm_m3_Hwi_swiRestoreHwi
#define Hwi_taskDisable ti_sysbios_family_arm_m3_Hwi_taskDisable
#define Hwi_taskRestoreHwi ti_sysbios_family_arm_m3_Hwi_taskRestoreHwi
#define Hwi_ccr ti_sysbios_family_arm_m3_Hwi_ccr
#define Hwi_hooks ti_sysbios_family_arm_m3_Hwi_hooks
#define Hwi_Params ti_sysbios_family_arm_m3_Hwi_Params
#define Hwi_getStackInfo ti_sysbios_family_arm_m3_Hwi_getStackInfo
#define Hwi_getCoreStackInfo ti_sysbios_family_arm_m3_Hwi_getCoreStackInfo
#define Hwi_startup ti_sysbios_family_arm_m3_Hwi_startup
#define Hwi_switchFromBootStack ti_sysbios_family_arm_m3_Hwi_switchFromBootStack
#define Hwi_post ti_sysbios_family_arm_m3_Hwi_post
#define Hwi_getTaskSP ti_sysbios_family_arm_m3_Hwi_getTaskSP
#define Hwi_disableInterrupt ti_sysbios_family_arm_m3_Hwi_disableInterrupt
#define Hwi_enableInterrupt ti_sysbios_family_arm_m3_Hwi_enableInterrupt
#define Hwi_restoreInterrupt ti_sysbios_family_arm_m3_Hwi_restoreInterrupt
#define Hwi_clearInterrupt ti_sysbios_family_arm_m3_Hwi_clearInterrupt
#define Hwi_getFunc ti_sysbios_family_arm_m3_Hwi_getFunc
#define Hwi_setFunc ti_sysbios_family_arm_m3_Hwi_setFunc
#define Hwi_getHookContext ti_sysbios_family_arm_m3_Hwi_getHookContext
#define Hwi_setHookContext ti_sysbios_family_arm_m3_Hwi_setHookContext
#define Hwi_getIrp ti_sysbios_family_arm_m3_Hwi_getIrp
#define Hwi_disable ti_sysbios_family_arm_m3_Hwi_disable
#define Hwi_enable ti_sysbios_family_arm_m3_Hwi_enable
#define Hwi_restore ti_sysbios_family_arm_m3_Hwi_restore
#define Hwi_disableFxn ti_sysbios_family_arm_m3_Hwi_disableFxn
#define Hwi_enableFxn ti_sysbios_family_arm_m3_Hwi_enableFxn
#define Hwi_restoreFxn ti_sysbios_family_arm_m3_Hwi_restoreFxn
#define Hwi_plug ti_sysbios_family_arm_m3_Hwi_plug
#define Hwi_getHandle ti_sysbios_family_arm_m3_Hwi_getHandle
#define Hwi_setPriority ti_sysbios_family_arm_m3_Hwi_setPriority
#define Hwi_excSetBuffers ti_sysbios_family_arm_m3_Hwi_excSetBuffers
#define Hwi_initNVIC ti_sysbios_family_arm_m3_Hwi_initNVIC
#define Hwi_initStacks ti_sysbios_family_arm_m3_Hwi_initStacks
#define Hwi_flushVnvic ti_sysbios_family_arm_m3_Hwi_flushVnvic
#define Hwi_reconfig ti_sysbios_family_arm_m3_Hwi_reconfig
#define Hwi_Module_name ti_sysbios_family_arm_m3_Hwi_Module_name
#define Hwi_Module_id ti_sysbios_family_arm_m3_Hwi_Module_id
#define Hwi_Module_startup ti_sysbios_family_arm_m3_Hwi_Module_startup
#define Hwi_Module_startupDone ti_sysbios_family_arm_m3_Hwi_Module_startupDone
#define Hwi_Module_hasMask ti_sysbios_family_arm_m3_Hwi_Module_hasMask
#define Hwi_Module_getMask ti_sysbios_family_arm_m3_Hwi_Module_getMask
#define Hwi_Module_setMask ti_sysbios_family_arm_m3_Hwi_Module_setMask
#define Hwi_Object_heap ti_sysbios_family_arm_m3_Hwi_Object_heap
#define Hwi_Module_heap ti_sysbios_family_arm_m3_Hwi_Module_heap
#define Hwi_construct ti_sysbios_family_arm_m3_Hwi_construct
#define Hwi_create ti_sysbios_family_arm_m3_Hwi_create
#define Hwi_handle ti_sysbios_family_arm_m3_Hwi_handle
#define Hwi_struct ti_sysbios_family_arm_m3_Hwi_struct
#define Hwi_Handle_label ti_sysbios_family_arm_m3_Hwi_Handle_label
#define Hwi_Handle_name ti_sysbios_family_arm_m3_Hwi_Handle_name
#define Hwi_Instance_init ti_sysbios_family_arm_m3_Hwi_Instance_init
#define Hwi_Object_count ti_sysbios_family_arm_m3_Hwi_Object_count
#define Hwi_Object_get ti_sysbios_family_arm_m3_Hwi_Object_get
#define Hwi_Object_first ti_sysbios_family_arm_m3_Hwi_Object_first
#define Hwi_Object_next ti_sysbios_family_arm_m3_Hwi_Object_next
#define Hwi_Object_sizeof ti_sysbios_family_arm_m3_Hwi_Object_sizeof
#define Hwi_Params_copy ti_sysbios_family_arm_m3_Hwi_Params_copy
#define Hwi_Params_init ti_sysbios_family_arm_m3_Hwi_Params_init
#define Hwi_Instance_finalize ti_sysbios_family_arm_m3_Hwi_Instance_finalize
#define Hwi_delete ti_sysbios_family_arm_m3_Hwi_delete
#define Hwi_destruct ti_sysbios_family_arm_m3_Hwi_destruct
#define Hwi_Module_upCast ti_sysbios_family_arm_m3_Hwi_Module_upCast
#define Hwi_Module_to_ti_sysbios_interfaces_IHwi ti_sysbios_family_arm_m3_Hwi_Module_to_ti_sysbios_interfaces_IHwi
#define Hwi_Handle_upCast ti_sysbios_family_arm_m3_Hwi_Handle_upCast
#define Hwi_Handle_to_ti_sysbios_interfaces_IHwi ti_sysbios_family_arm_m3_Hwi_Handle_to_ti_sysbios_interfaces_IHwi
#define Hwi_Handle_downCast ti_sysbios_family_arm_m3_Hwi_Handle_downCast
#define Hwi_Handle_from_ti_sysbios_interfaces_IHwi ti_sysbios_family_arm_m3_Hwi_Handle_from_ti_sysbios_interfaces_IHwi

#endif /* ti_sysbios_family_arm_m3_Hwi__localnames__done */
#endif
