/*
 *  Do not modify this file; it is automatically 
 *  generated and any modifications will be overwritten.
 *
 * @(#) xdc-A71
 */

#ifndef ti_sysbios_knl_Swi__INTERNAL__
#define ti_sysbios_knl_Swi__INTERNAL__

#ifndef ti_sysbios_knl_Swi__internalaccess
#define ti_sysbios_knl_Swi__internalaccess
#endif

#include <ti/sysbios/knl/Swi.h>

#undef xdc_FILE__
#ifndef xdc_FILE
#define xdc_FILE__ NULL
#else
#define xdc_FILE__ xdc_FILE
#endif

/* startup */
#undef ti_sysbios_knl_Swi_startup
#define ti_sysbios_knl_Swi_startup ti_sysbios_knl_Swi_startup__E

/* enabled */
#undef ti_sysbios_knl_Swi_enabled
#define ti_sysbios_knl_Swi_enabled ti_sysbios_knl_Swi_enabled__E

/* unlockSched */
#undef ti_sysbios_knl_Swi_unlockSched
#define ti_sysbios_knl_Swi_unlockSched ti_sysbios_knl_Swi_unlockSched__E

/* disable */
#undef ti_sysbios_knl_Swi_disable
#define ti_sysbios_knl_Swi_disable ti_sysbios_knl_Swi_disable__E

/* enable */
#undef ti_sysbios_knl_Swi_enable
#define ti_sysbios_knl_Swi_enable ti_sysbios_knl_Swi_enable__E

/* restore */
#undef ti_sysbios_knl_Swi_restore
#define ti_sysbios_knl_Swi_restore ti_sysbios_knl_Swi_restore__E

/* restoreHwi */
#undef ti_sysbios_knl_Swi_restoreHwi
#define ti_sysbios_knl_Swi_restoreHwi ti_sysbios_knl_Swi_restoreHwi__E

/* self */
#undef ti_sysbios_knl_Swi_self
#define ti_sysbios_knl_Swi_self ti_sysbios_knl_Swi_self__E

/* getTrigger */
#undef ti_sysbios_knl_Swi_getTrigger
#define ti_sysbios_knl_Swi_getTrigger ti_sysbios_knl_Swi_getTrigger__E

/* raisePri */
#undef ti_sysbios_knl_Swi_raisePri
#define ti_sysbios_knl_Swi_raisePri ti_sysbios_knl_Swi_raisePri__E

/* restorePri */
#undef ti_sysbios_knl_Swi_restorePri
#define ti_sysbios_knl_Swi_restorePri ti_sysbios_knl_Swi_restorePri__E

/* andn */
#undef ti_sysbios_knl_Swi_andn
#define ti_sysbios_knl_Swi_andn ti_sysbios_knl_Swi_andn__E

/* dec */
#undef ti_sysbios_knl_Swi_dec
#define ti_sysbios_knl_Swi_dec ti_sysbios_knl_Swi_dec__E

/* getHookContext */
#undef ti_sysbios_knl_Swi_getHookContext
#define ti_sysbios_knl_Swi_getHookContext ti_sysbios_knl_Swi_getHookContext__E

/* setHookContext */
#undef ti_sysbios_knl_Swi_setHookContext
#define ti_sysbios_knl_Swi_setHookContext ti_sysbios_knl_Swi_setHookContext__E

/* getPri */
#undef ti_sysbios_knl_Swi_getPri
#define ti_sysbios_knl_Swi_getPri ti_sysbios_knl_Swi_getPri__E

/* getFunc */
#undef ti_sysbios_knl_Swi_getFunc
#define ti_sysbios_knl_Swi_getFunc ti_sysbios_knl_Swi_getFunc__E

/* getAttrs */
#undef ti_sysbios_knl_Swi_getAttrs
#define ti_sysbios_knl_Swi_getAttrs ti_sysbios_knl_Swi_getAttrs__E

/* setAttrs */
#undef ti_sysbios_knl_Swi_setAttrs
#define ti_sysbios_knl_Swi_setAttrs ti_sysbios_knl_Swi_setAttrs__E

/* inc */
#undef ti_sysbios_knl_Swi_inc
#define ti_sysbios_knl_Swi_inc ti_sysbios_knl_Swi_inc__E

/* or */
#undef ti_sysbios_knl_Swi_or
#define ti_sysbios_knl_Swi_or ti_sysbios_knl_Swi_or__E

/* post */
#undef ti_sysbios_knl_Swi_post
#define ti_sysbios_knl_Swi_post ti_sysbios_knl_Swi_post__E

/* schedule */
#define Swi_schedule ti_sysbios_knl_Swi_schedule__I

/* runLoop */
#define Swi_runLoop ti_sysbios_knl_Swi_runLoop__I

/* run */
#define Swi_run ti_sysbios_knl_Swi_run__I

/* postInit */
#define Swi_postInit ti_sysbios_knl_Swi_postInit__I

/* restoreSMP */
#define Swi_restoreSMP ti_sysbios_knl_Swi_restoreSMP__I

/* Module_startup */
#undef ti_sysbios_knl_Swi_Module_startup
#define ti_sysbios_knl_Swi_Module_startup ti_sysbios_knl_Swi_Module_startup__E

/* Instance_init */
#undef ti_sysbios_knl_Swi_Instance_init
#define ti_sysbios_knl_Swi_Instance_init ti_sysbios_knl_Swi_Instance_init__E

/* Instance_finalize */
#undef ti_sysbios_knl_Swi_Instance_finalize
#define ti_sysbios_knl_Swi_Instance_finalize ti_sysbios_knl_Swi_Instance_finalize__E

/* module */
#define Swi_module ((ti_sysbios_knl_Swi_Module_State *)(xdc__MODOBJADDR__(ti_sysbios_knl_Swi_Module__state__V)))
#if !defined(__cplusplus) || !defined(ti_sysbios_knl_Swi__cplusplus)
#define module ((ti_sysbios_knl_Swi_Module_State *)(xdc__MODOBJADDR__(ti_sysbios_knl_Swi_Module__state__V)))
#endif
/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_knl_Swi_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_knl_Swi_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_knl_Swi_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_knl_Swi_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_knl_Swi_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_knl_Swi_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_knl_Swi_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_knl_Swi_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_knl_Swi_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_knl_Swi_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_knl_Swi_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_knl_Swi_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_knl_Swi_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_sysbios_knl_Swi_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_knl_Swi_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_knl_Swi_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_knl_Swi_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_knl_Swi_Module_GateProxy_query

/* Object__sizingError */
#line 1 "Error_inconsistent_object_size_in_ti.sysbios.knl.Swi"
typedef char ti_sysbios_knl_Swi_Object__sizingError[sizeof(ti_sysbios_knl_Swi_Object) > sizeof(ti_sysbios_knl_Swi_Struct) ? -1 : 1];


#endif /* ti_sysbios_knl_Swi__INTERNAL____ */
