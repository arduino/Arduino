/*
 *  Do not modify this file; it is automatically 
 *  generated and any modifications will be overwritten.
 *
 * @(#) xdc-A71
 */

#ifndef ti_sysbios_knl_Task__INTERNAL__
#define ti_sysbios_knl_Task__INTERNAL__

#ifndef ti_sysbios_knl_Task__internalaccess
#define ti_sysbios_knl_Task__internalaccess
#endif

#include <ti/sysbios/knl/Task.h>

#undef xdc_FILE__
#ifndef xdc_FILE
#define xdc_FILE__ NULL
#else
#define xdc_FILE__ xdc_FILE
#endif

/* startup */
#undef ti_sysbios_knl_Task_startup
#define ti_sysbios_knl_Task_startup ti_sysbios_knl_Task_startup__E

/* enabled */
#undef ti_sysbios_knl_Task_enabled
#define ti_sysbios_knl_Task_enabled ti_sysbios_knl_Task_enabled__E

/* unlockSched */
#undef ti_sysbios_knl_Task_unlockSched
#define ti_sysbios_knl_Task_unlockSched ti_sysbios_knl_Task_unlockSched__E

/* disable */
#undef ti_sysbios_knl_Task_disable
#define ti_sysbios_knl_Task_disable ti_sysbios_knl_Task_disable__E

/* enable */
#undef ti_sysbios_knl_Task_enable
#define ti_sysbios_knl_Task_enable ti_sysbios_knl_Task_enable__E

/* restore */
#undef ti_sysbios_knl_Task_restore
#define ti_sysbios_knl_Task_restore ti_sysbios_knl_Task_restore__E

/* restoreHwi */
#undef ti_sysbios_knl_Task_restoreHwi
#define ti_sysbios_knl_Task_restoreHwi ti_sysbios_knl_Task_restoreHwi__E

/* self */
#undef ti_sysbios_knl_Task_self
#define ti_sysbios_knl_Task_self ti_sysbios_knl_Task_self__E

/* checkStacks */
#undef ti_sysbios_knl_Task_checkStacks
#define ti_sysbios_knl_Task_checkStacks ti_sysbios_knl_Task_checkStacks__E

/* exit */
#undef ti_sysbios_knl_Task_exit
#define ti_sysbios_knl_Task_exit ti_sysbios_knl_Task_exit__E

/* sleep */
#undef ti_sysbios_knl_Task_sleep
#define ti_sysbios_knl_Task_sleep ti_sysbios_knl_Task_sleep__E

/* yield */
#undef ti_sysbios_knl_Task_yield
#define ti_sysbios_knl_Task_yield ti_sysbios_knl_Task_yield__E

/* getIdleTask */
#undef ti_sysbios_knl_Task_getIdleTask
#define ti_sysbios_knl_Task_getIdleTask ti_sysbios_knl_Task_getIdleTask__E

/* getIdleTaskHandle */
#undef ti_sysbios_knl_Task_getIdleTaskHandle
#define ti_sysbios_knl_Task_getIdleTaskHandle ti_sysbios_knl_Task_getIdleTaskHandle__E

/* startCore */
#undef ti_sysbios_knl_Task_startCore
#define ti_sysbios_knl_Task_startCore ti_sysbios_knl_Task_startCore__E

/* getArg0 */
#undef ti_sysbios_knl_Task_getArg0
#define ti_sysbios_knl_Task_getArg0 ti_sysbios_knl_Task_getArg0__E

/* getArg1 */
#undef ti_sysbios_knl_Task_getArg1
#define ti_sysbios_knl_Task_getArg1 ti_sysbios_knl_Task_getArg1__E

/* getEnv */
#undef ti_sysbios_knl_Task_getEnv
#define ti_sysbios_knl_Task_getEnv ti_sysbios_knl_Task_getEnv__E

/* getFunc */
#undef ti_sysbios_knl_Task_getFunc
#define ti_sysbios_knl_Task_getFunc ti_sysbios_knl_Task_getFunc__E

/* getHookContext */
#undef ti_sysbios_knl_Task_getHookContext
#define ti_sysbios_knl_Task_getHookContext ti_sysbios_knl_Task_getHookContext__E

/* getPri */
#undef ti_sysbios_knl_Task_getPri
#define ti_sysbios_knl_Task_getPri ti_sysbios_knl_Task_getPri__E

/* setArg0 */
#undef ti_sysbios_knl_Task_setArg0
#define ti_sysbios_knl_Task_setArg0 ti_sysbios_knl_Task_setArg0__E

/* setArg1 */
#undef ti_sysbios_knl_Task_setArg1
#define ti_sysbios_knl_Task_setArg1 ti_sysbios_knl_Task_setArg1__E

/* setEnv */
#undef ti_sysbios_knl_Task_setEnv
#define ti_sysbios_knl_Task_setEnv ti_sysbios_knl_Task_setEnv__E

/* setHookContext */
#undef ti_sysbios_knl_Task_setHookContext
#define ti_sysbios_knl_Task_setHookContext ti_sysbios_knl_Task_setHookContext__E

/* setPri */
#undef ti_sysbios_knl_Task_setPri
#define ti_sysbios_knl_Task_setPri ti_sysbios_knl_Task_setPri__E

/* stat */
#undef ti_sysbios_knl_Task_stat
#define ti_sysbios_knl_Task_stat ti_sysbios_knl_Task_stat__E

/* getMode */
#undef ti_sysbios_knl_Task_getMode
#define ti_sysbios_knl_Task_getMode ti_sysbios_knl_Task_getMode__E

/* setAffinity */
#undef ti_sysbios_knl_Task_setAffinity
#define ti_sysbios_knl_Task_setAffinity ti_sysbios_knl_Task_setAffinity__E

/* getAffinity */
#undef ti_sysbios_knl_Task_getAffinity
#define ti_sysbios_knl_Task_getAffinity ti_sysbios_knl_Task_getAffinity__E

/* block */
#undef ti_sysbios_knl_Task_block
#define ti_sysbios_knl_Task_block ti_sysbios_knl_Task_block__E

/* unblock */
#undef ti_sysbios_knl_Task_unblock
#define ti_sysbios_knl_Task_unblock ti_sysbios_knl_Task_unblock__E

/* blockI */
#undef ti_sysbios_knl_Task_blockI
#define ti_sysbios_knl_Task_blockI ti_sysbios_knl_Task_blockI__E

/* unblockI */
#undef ti_sysbios_knl_Task_unblockI
#define ti_sysbios_knl_Task_unblockI ti_sysbios_knl_Task_unblockI__E

/* schedule */
#define Task_schedule ti_sysbios_knl_Task_schedule__I

/* enter */
#define Task_enter ti_sysbios_knl_Task_enter__I

/* sleepTimeout */
#define Task_sleepTimeout ti_sysbios_knl_Task_sleepTimeout__I

/* postInit */
#define Task_postInit ti_sysbios_knl_Task_postInit__I

/* allBlockedFunction */
#define Task_allBlockedFunction ti_sysbios_knl_Task_allBlockedFunction__I

/* deleteTerminatedTasksFunc */
#define Task_deleteTerminatedTasksFunc ti_sysbios_knl_Task_deleteTerminatedTasksFunc__I

/* processVitalTaskFlag */
#define Task_processVitalTaskFlag ti_sysbios_knl_Task_processVitalTaskFlag__I

/* Module_startup */
#undef ti_sysbios_knl_Task_Module_startup
#define ti_sysbios_knl_Task_Module_startup ti_sysbios_knl_Task_Module_startup__E

/* Instance_init */
#undef ti_sysbios_knl_Task_Instance_init
#define ti_sysbios_knl_Task_Instance_init ti_sysbios_knl_Task_Instance_init__E

/* Instance_finalize */
#undef ti_sysbios_knl_Task_Instance_finalize
#define ti_sysbios_knl_Task_Instance_finalize ti_sysbios_knl_Task_Instance_finalize__E

/* module */
#define Task_module ((ti_sysbios_knl_Task_Module_State *)(xdc__MODOBJADDR__(ti_sysbios_knl_Task_Module__state__V)))
#if !defined(__cplusplus) || !defined(ti_sysbios_knl_Task__cplusplus)
#define module ((ti_sysbios_knl_Task_Module_State *)(xdc__MODOBJADDR__(ti_sysbios_knl_Task_Module__state__V)))
#endif
/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_knl_Task_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_knl_Task_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_knl_Task_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_knl_Task_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_knl_Task_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_knl_Task_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_knl_Task_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_knl_Task_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_knl_Task_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_knl_Task_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_knl_Task_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_knl_Task_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_knl_Task_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_sysbios_knl_Task_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_knl_Task_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_knl_Task_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_knl_Task_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_knl_Task_Module_GateProxy_query

/* Object__sizingError */
#line 1 "Error_inconsistent_object_size_in_ti.sysbios.knl.Task"
typedef char ti_sysbios_knl_Task_Object__sizingError[sizeof(ti_sysbios_knl_Task_Object) > sizeof(ti_sysbios_knl_Task_Struct) ? -1 : 1];


#endif /* ti_sysbios_knl_Task__INTERNAL____ */
