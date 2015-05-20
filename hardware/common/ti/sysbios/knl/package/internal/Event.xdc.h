/*
 *  Do not modify this file; it is automatically 
 *  generated and any modifications will be overwritten.
 *
 * @(#) xdc-A71
 */

#ifndef ti_sysbios_knl_Event__INTERNAL__
#define ti_sysbios_knl_Event__INTERNAL__

#ifndef ti_sysbios_knl_Event__internalaccess
#define ti_sysbios_knl_Event__internalaccess
#endif

#include <ti/sysbios/knl/Event.h>

#undef xdc_FILE__
#ifndef xdc_FILE
#define xdc_FILE__ NULL
#else
#define xdc_FILE__ xdc_FILE
#endif

/* pend */
#undef ti_sysbios_knl_Event_pend
#define ti_sysbios_knl_Event_pend ti_sysbios_knl_Event_pend__E

/* post */
#undef ti_sysbios_knl_Event_post
#define ti_sysbios_knl_Event_post ti_sysbios_knl_Event_post__E

/* getPostedEvents */
#undef ti_sysbios_knl_Event_getPostedEvents
#define ti_sysbios_knl_Event_getPostedEvents ti_sysbios_knl_Event_getPostedEvents__E

/* sync */
#undef ti_sysbios_knl_Event_sync
#define ti_sysbios_knl_Event_sync ti_sysbios_knl_Event_sync__E

/* pendTimeout */
#define Event_pendTimeout ti_sysbios_knl_Event_pendTimeout__I

/* checkEvents */
#define Event_checkEvents ti_sysbios_knl_Event_checkEvents__I

/* Module_startup */
#undef ti_sysbios_knl_Event_Module_startup
#define ti_sysbios_knl_Event_Module_startup ti_sysbios_knl_Event_Module_startup__E

/* Instance_init */
#undef ti_sysbios_knl_Event_Instance_init
#define ti_sysbios_knl_Event_Instance_init ti_sysbios_knl_Event_Instance_init__E

/* Instance_finalize */
#undef ti_sysbios_knl_Event_Instance_finalize
#define ti_sysbios_knl_Event_Instance_finalize ti_sysbios_knl_Event_Instance_finalize__E

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_knl_Event_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_knl_Event_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_knl_Event_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_knl_Event_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_knl_Event_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_knl_Event_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_knl_Event_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_knl_Event_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_knl_Event_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_knl_Event_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_knl_Event_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_knl_Event_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_knl_Event_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_sysbios_knl_Event_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_knl_Event_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_knl_Event_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_knl_Event_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_knl_Event_Module_GateProxy_query

/* Object__sizingError */
#line 1 "Error_inconsistent_object_size_in_ti.sysbios.knl.Event"
typedef char ti_sysbios_knl_Event_Object__sizingError[sizeof(ti_sysbios_knl_Event_Object) > sizeof(ti_sysbios_knl_Event_Struct) ? -1 : 1];


#endif /* ti_sysbios_knl_Event__INTERNAL____ */
