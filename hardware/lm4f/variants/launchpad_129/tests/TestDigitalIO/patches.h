#include "pins_energia.h" 

patch_t patches[] = {
    {-1,"Booster Pack 1 X8 and X9", 0,0},
    {PH_2,"PH_2", PF_3,"PF_3"},
    {PH_3,"PH_3", PG_0,"PG_0"},
    {PD_1,"PD_1", PL_5,"PL_5"},
    {PD_0,"PD_0", PL_0,"PL_0"},
    {PN_2,"PN_2", PL_1,"PL_1"},
    {PN_3,"PN_3", PL_2,"PL_2"},
    {PP_2,"PP_2", PL_3,"PL_3"},

    {-1,"Booster Pack 1 X8 and X9", 0,0},
    {PE_0,"PE_0", PC_4,"PC_4"},
    {PE_1,"PE_1", PC_5,"PC_5"},
    {PE_2,"PE_2", PC_6,"PC_6"},
    {PE_3,"PE_3", PE_5,"PE_5"},
    {PD_7,"PD_7", PD_3,"PD_3"},
    {PA_6,"PA_6", PC_7,"PC_7"},
    {PM_4,"PM_4", PB_2,"PB_2"},
    {PM_5,"PM_5", PB_3,"PB_3"},
    {PF_1,"PF_1", PL_4,"PL_4"},

    {-1,"Booster Pack 2 X6 and X7", 0,0},
    {PM_7,"PM_7", PK_4,"PK_4"},
    {PP_5,"PP_5", PK_5,"PK_5"},
    {PA_7,"PA_7", PM_0,"PM_0"},
    {PQ_2,"PQ_2", PM_2,"PM_2"},
    {PQ_3,"PQ_3", PH_0,"PH_0"},
    {PP_3,"PP_3", PH_1,"PH_1"},
    {PQ_1,"PQ_1", PK_6,"PK_6"},
    {PM_6,"PM_6", PK_7,"PK_7"},
    {PM_1,"PM_1", PG_1,"PG_1"},

    {-1,"Booster Pack 2 X6 and X7", 0,0},
    {PB_4,"PB_4", PP_0,"PP_0"},
    {PB_5,"PB_5", PP_1,"PP_1"},
    {PK_0,"PK_0", PD_4,"PD_4"},
    {PK_1,"PK_1", PD_5,"PD_5"},
    {PK_2,"PK_2", PQ_0,"PQ_0"},
    {PK_3,"PK_3", PP_4,"PP_4"},
    {PA_4,"PA_4", PN_5,"PN_5"},
    {PA_5,"PA_5", PN_4,"PN_4"},

    { 0,"", 0,""}
};

/*
not connected
PD_2,"PD_2"
PE_4,"PE_4"
PF_0,"PF_0"
PF_4,"PF_4"
PJ_0,"PJ_0"
PJ_1,"PJ_1"
PN_0,"PN_0"
PN_1,"PN_1"

*/


// grep "static const uint8_t.*P._" pins_energia.h | sed "s/;/ /" | awk '{ print "/* " $4 " - " $6 " */"}' | grep "_" | sort
// grep "static const uint8_t.*P._" pins_energia.h | sed "s/;/ /" | awk '{ print  $6 ",\"" $4 "\""}' | grep "_" | sort -t',' -k2
