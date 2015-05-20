/*
 *  Do not modify this file; it is automatically 
 *  generated and any modifications will be overwritten.
 *
 * @(#) xdc-A71
 */

#ifndef ti_sysbios_family_arm_HwiCommon__INTERNAL__
#define ti_sysbios_family_arm_HwiCommon__INTERNAL__

#ifndef ti_sysbios_family_arm_HwiCommon__internalaccess
#define ti_sysbios_family_arm_HwiCommon__internalaccess
#endif

#include <ti/sysbios/family/arm/HwiCommon.h>

#undef xdc_FILE__
#ifndef xdc_FILE
#define xdc_FILE__ NULL
#else
#define xdc_FILE__ xdc_FILE
#endif

/* enable */
#undef ti_sysbios_family_arm_HwiCommon_enable
#define ti_sysbios_family_arm_HwiCommon_enable ti_sysbios_family_arm_HwiCommon_enable__E

/* disable */
#undef ti_sysbios_family_arm_HwiCommon_disable
#define ti_sysbios_family_arm_HwiCommon_disable ti_sysbios_family_arm_HwiCommon_disable__E

/* restore */
#undef ti_sysbios_family_arm_HwiCommon_restore
#define ti_sysbios_family_arm_HwiCommon_restore ti_sysbios_family_arm_HwiCommon_restore__E

/* enableFIQ */
#undef ti_sysbios_family_arm_HwiCommon_enableFIQ
#define ti_sysbios_family_arm_HwiCommon_enableFIQ ti_sysbios_family_arm_HwiCommon_enableFIQ__E

/* disableFIQ */
#undef ti_sysbios_family_arm_HwiCommon_disableFIQ
#define ti_sysbios_family_arm_HwiCommon_disableFIQ ti_sysbios_family_arm_HwiCommon_disableFIQ__E

/* restoreFIQ */
#undef ti_sysbios_family_arm_HwiCommon_restoreFIQ
#define ti_sysbios_family_arm_HwiCommon_restoreFIQ ti_sysbios_family_arm_HwiCommon_restoreFIQ__E

/* enableIRQ */
#undef ti_sysbios_family_arm_HwiCommon_enableIRQ
#define ti_sysbios_family_arm_HwiCommon_enableIRQ ti_sysbios_family_arm_HwiCommon_enableIRQ__E

/* disableIRQ */
#undef ti_sysbios_family_arm_HwiCommon_disableIRQ
#define ti_sysbios_family_arm_HwiCommon_disableIRQ ti_sysbios_family_arm_HwiCommon_disableIRQ__E

/* restoreIRQ */
#undef ti_sysbios_family_arm_HwiCommon_restoreIRQ
#define ti_sysbios_family_arm_HwiCommon_restoreIRQ ti_sysbios_family_arm_HwiCommon_restoreIRQ__E

/* getTaskSP */
#undef ti_sysbios_family_arm_HwiCommon_getTaskSP
#define ti_sysbios_family_arm_HwiCommon_getTaskSP ti_sysbios_family_arm_HwiCommon_getTaskSP__E

/* switchFromBootStack */
#undef ti_sysbios_family_arm_HwiCommon_switchFromBootStack
#define ti_sysbios_family_arm_HwiCommon_switchFromBootStack ti_sysbios_family_arm_HwiCommon_switchFromBootStack__E

/* switchToSystemMode */
#define HwiCommon_switchToSystemMode ti_sysbios_family_arm_HwiCommon_switchToSystemMode__I

/* enableA */
#define HwiCommon_enableA ti_sysbios_family_arm_HwiCommon_enableA__I

/* disableA */
#define HwiCommon_disableA ti_sysbios_family_arm_HwiCommon_disableA__I

/* restoreA */
#define HwiCommon_restoreA ti_sysbios_family_arm_HwiCommon_restoreA__I

/* enableFIQA */
#define HwiCommon_enableFIQA ti_sysbios_family_arm_HwiCommon_enableFIQA__I

/* disableFIQA */
#define HwiCommon_disableFIQA ti_sysbios_family_arm_HwiCommon_disableFIQA__I

/* restoreFIQA */
#define HwiCommon_restoreFIQA ti_sysbios_family_arm_HwiCommon_restoreFIQA__I

/* enableIRQA */
#define HwiCommon_enableIRQA ti_sysbios_family_arm_HwiCommon_enableIRQA__I

/* disableIRQA */
#define HwiCommon_disableIRQA ti_sysbios_family_arm_HwiCommon_disableIRQA__I

/* restoreIRQA */
#define HwiCommon_restoreIRQA ti_sysbios_family_arm_HwiCommon_restoreIRQA__I

/* swiHandler */
#define HwiCommon_swiHandler ti_sysbios_family_arm_HwiCommon_swiHandler__I

/* Module_startup */
#undef ti_sysbios_family_arm_HwiCommon_Module_startup
#define ti_sysbios_family_arm_HwiCommon_Module_startup ti_sysbios_family_arm_HwiCommon_Module_startup__E

/* Instance_init */
#undef ti_sysbios_family_arm_HwiCommon_Instance_init
#define ti_sysbios_family_arm_HwiCommon_Instance_init ti_sysbios_family_arm_HwiCommon_Instance_init__E

/* Instance_finalize */
#undef ti_sysbios_family_arm_HwiCommon_Instance_finalize
#define ti_sysbios_family_arm_HwiCommon_Instance_finalize ti_sysbios_family_arm_HwiCommon_Instance_finalize__E

/* module */
#define HwiCommon_module ((ti_sysbios_family_arm_HwiCommon_Module_State *)(xdc__MODOBJADDR__(ti_sysbios_family_arm_HwiCommon_Module__state__V)))
#if !defined(__cplusplus) || !defined(ti_sysbios_family_arm_HwiCommon__cplusplus)
#define module ((ti_sysbios_family_arm_HwiCommon_Module_State *)(xdc__MODOBJADDR__(ti_sysbios_family_arm_HwiCommon_Module__state__V)))
#endif
/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_family_arm_HwiCommon_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_family_arm_HwiCommon_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_family_arm_HwiCommon_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_family_arm_HwiCommon_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_family_arm_HwiCommon_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_family_arm_HwiCommon_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_family_arm_HwiCommon_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_family_arm_HwiCommon_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_family_arm_HwiCommon_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_family_arm_HwiCommon_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_family_arm_HwiCommon_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_family_arm_HwiCommon_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_family_arm_HwiCommon_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_sysbios_family_arm_HwiCommon_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_family_arm_HwiCommon_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_family_arm_HwiCommon_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_family_arm_HwiCommon_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_family_arm_HwiCommon_Module_GateProxy_query


#endif /* ti_sysbios_family_arm_HwiCommon__INTERNAL____ */
