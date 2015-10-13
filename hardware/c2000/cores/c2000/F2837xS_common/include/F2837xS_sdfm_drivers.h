//###########################################################################
//
// FILE:   F2837xS_sdfm_drivers.h
//
// TITLE:  Defines and Macros for the SDFM driver Controller
//
//###########################################################################
// $TI Release: F2837xS Support Library v170 $
// $Release Date: Mon Sep 21 16:56:07 CDT 2015 $
// $Copyright: Copyright (C) 2014-2015 Texas Instruments Incorporated -
//             http://www.ti.com/ ALL RIGHTS RESERVED $
//###########################################################################

#ifndef F2837xS_SDFM_DRIVERS_H
#define F2837xS_SDFM_DRIVERS_H


#ifdef __cplusplus
extern "C" {
#endif

//*****************************************************************************
// This is used to select either SDFM module 1 & SDFM module 2
//*****************************************************************************
#define SDFM1 	1    //Can be used to select SDFM module 1
#define SDFM2	2    //Can be used to select SDFM module 2

//*****************************************************************************
// Max OSR values of different modules
//*****************************************************************************
#define COMPARATOR_MAX_OSR 32    //Max OSR for comparator
#define DATA_FILTER_MAX_OSR 256  //Max OSR for Data filter


//*****************************************************************************
// Different Input Control modes
// These values can be passed as argument to Sdfm_configureInputCtrl()
//*****************************************************************************

#define MODE_0 	0    //Used to select Mode0 : Modulator clock rate = Modulator data rate
#define MODE_1	1    //Used to select MODE1 : Modulator clock rate = (Modulator data rate / 2)
#define MODE_2	2    //Used to select MODE2 : Manchester encoded data (Modulator clock is encoded into data)
#define MODE_3	3    //Used to select MODE3 : Modulator clock rate = (2 x Modulator data rate)

//*****************************************************************************
// The following are values that can be passed to following functions
//
// (1) Sdfm_configureInputCtrl()
// (2) Sdfm_configureComparator()
// (3) Sdfm_configureData_filter()
// (4) Sdfm_configureInterrupt()
//*****************************************************************************
#define FILTER1			0x01   //Used to select filter1 for either comparator, Data filter
#define FILTER2			0x02   //Used to select filter2 for either comparator, Data filter
#define FILTER3			0x04   //Used to select filter3 for either comparator, Data filter
#define FILTER4			0x08   //Used to select filter4 for either comparator, Data filter


//*****************************************************************************
// The following are values that can be passed to Sdfm_configureData_filter()
//*****************************************************************************
#define FILTER_DISABLE 0    //Used to disable filter
#define FILTER_ENABLE  1    //Used to enable  filter


//*****************************************************************************
// The following are values that can be passed to following functions
//
// (1) Sdfm_configureComparator()
// (2) Sdfm_configureData_filter()
//*****************************************************************************
#define SINCFAST		0x00   //Used to select Sincfast filter type for either comparator, Data filter
#define SINC1			0x01   //Used to select Sinc1 filter type for either comparator, Data filter
#define SINC2			0x02   //Used to select Sinc2 filter type for either comparator, Data filter
#define SINC3			0x03   //Used to select Sinc3 filter type for either comparator, Data filter


//*****************************************************************************
// Enable / Disable High-level threshold interrupt for Comparator filter output
// These values can be passed as argument to Sdfm_configureInterrupt()
//*****************************************************************************
#define IEH_DISABLE	0    //Used to disable over value interrupt to CPU
#define IEH_ENABLE	1    //Used to enable  over value interrupt to CPU

//*****************************************************************************
// Enable / Disable Low-level threshold interrupt for Comparator filter output
// These values can be passed as argument to Sdfm_configureInterrupt()
//*****************************************************************************
#define IEL_DISABLE	0    //Used to disable under value interrupt to CPU
#define IEL_ENABLE	1    //Used to enable  under value interrupt to CPU

//*****************************************************************************
//Enable / Disable modulator failure interrupt
// These values can be passed as argument to Sdfm_configureInterrupt()
//*****************************************************************************
#define MFIE_DISABLE 0    //Used to disable modulator failure interrupt to CPU
#define MFIE_ENABLE  1    //Used to enable  modulator failure interrupt to CPU

//*****************************************************************************
// Enable / Disable Acknowledge flag
// These values can be passed as argument to Sdfm_configureInterrupt()
//*****************************************************************************
#define AE_DISABLE 0    //Used to disable new filter data acknowledge interrupt to CPU
#define AE_ENABLE  1    //Used to enable  new filter data acknowledge interrupt to CPU



//*****************************************************************************
// Sinc Filter Reset enable / disable for External Reset from PWM Compare
// output
// This following value can be passed to Sdfm_configureExternalreset()
//*****************************************************************************
#define FILTER_1_EXT_RESET_DISABLE		0
#define FILTER_1_EXT_RESET_ENABLE		1
#define FILTER_2_EXT_RESET_DISABLE		0
#define FILTER_2_EXT_RESET_ENABLE		1
#define FILTER_3_EXT_RESET_DISABLE		0
#define FILTER_3_EXT_RESET_ENABLE		1
#define FILTER_4_EXT_RESET_DISABLE		0
#define FILTER_4_EXT_RESET_ENABLE		1

//*****************************************************************************
// Filter ouput data can be represented in 16 bit (or) 32 bit format
// This value can be passed to Sdfm_configureData_filter()
//*****************************************************************************
#define DATA_16_BIT		0	 //Data stored in 16b 2's complement
#define DATA_32_BIT 	1	 //Data stored in 32b 2's complement


//*****************************************************************************
// Macro to read the SDFM1 filter data in 16 bit format
//*****************************************************************************
#define SDFM1_READ_FILTER1_DATA_16BIT 	*(Uint16 *)0x5E17
#define SDFM1_READ_FILTER2_DATA_16BIT 	*(Uint16 *)0x5E27
#define SDFM1_READ_FILTER3_DATA_16BIT 	*(Uint16 *)0x5E37
#define SDFM1_READ_FILTER4_DATA_16BIT 	*(Uint16 *)0x5E47

//*****************************************************************************
// Macro to read the SDFM1 filter data in 32 bit format
//*****************************************************************************
#define SDFM1_READ_FILTER1_DATA_32BIT	*(Uint32 *)0x5E16
#define SDFM1_READ_FILTER2_DATA_32BIT	*(Uint32 *)0x5E26
#define SDFM1_READ_FILTER3_DATA_32BIT	*(Uint32 *)0x5E36
#define SDFM1_READ_FILTER4_DATA_32BIT	*(Uint32 *)0x5E46

//*****************************************************************************
// Macro to read the SDFM2 filter data in 16 bit format
//*****************************************************************************
#define SDFM2_READ_FILTER1_DATA_16BIT 	*(Uint16 *)0x5E97
#define SDFM2_READ_FILTER2_DATA_16BIT 	*(Uint16 *)0x5EA7
#define SDFM2_READ_FILTER3_DATA_16BIT 	*(Uint16 *)0x5EB7
#define SDFM2_READ_FILTER4_DATA_16BIT 	*(Uint16 *)0x5EC7

//*****************************************************************************
// Macro to read the SDFM2 filter data in 32 bit format
//*****************************************************************************
#define SDFM2_READ_FILTER1_DATA_32BIT 	*(Uint16 *)0x5E96
#define SDFM2_READ_FILTER2_DATA_32BIT 	*(Uint16 *)0x5EA6
#define SDFM2_READ_FILTER3_DATA_32BIT 	*(Uint16 *)0x5EB6
#define SDFM2_READ_FILTER4_DATA_32BIT 	*(Uint16 *)0x5EC6

//*****************************************************************************
// The following are defines for different OSR values
//*****************************************************************************
#define OSR_1     0
#define OSR_2     1
#define OSR_3     2
#define OSR_4     3
#define OSR_5     4
#define OSR_6     5
#define OSR_7     6
#define OSR_8     7
#define OSR_9     8
#define OSR_10     9
#define OSR_11     10
#define OSR_12     11
#define OSR_13     12
#define OSR_14     13
#define OSR_15     14
#define OSR_16     15
#define OSR_17     16
#define OSR_18     17
#define OSR_19     18
#define OSR_20     19
#define OSR_21     20
#define OSR_22     21
#define OSR_23     22
#define OSR_24     23
#define OSR_25     24
#define OSR_26     25
#define OSR_27     26
#define OSR_28     27
#define OSR_29     28
#define OSR_30     29
#define OSR_31     30
#define OSR_32     31
#define OSR_33     32
#define OSR_34     33
#define OSR_35     34
#define OSR_36     35
#define OSR_37     36
#define OSR_38     37
#define OSR_39     38
#define OSR_40     39
#define OSR_41     40
#define OSR_42     41
#define OSR_43     42
#define OSR_44     43
#define OSR_45     44
#define OSR_46     45
#define OSR_47     46
#define OSR_48     47
#define OSR_49     48
#define OSR_50     49
#define OSR_51     50
#define OSR_52     51
#define OSR_53     52
#define OSR_54     53
#define OSR_55     54
#define OSR_56     55
#define OSR_57     56
#define OSR_58     57
#define OSR_59     58
#define OSR_60     59
#define OSR_61     60
#define OSR_62     61
#define OSR_63     62
#define OSR_64     63
#define OSR_65     64
#define OSR_66     65
#define OSR_67     66
#define OSR_68     67
#define OSR_69     68
#define OSR_70     69
#define OSR_71     70
#define OSR_72     71
#define OSR_73     72
#define OSR_74     73
#define OSR_75     74
#define OSR_76     75
#define OSR_77     76
#define OSR_78     77
#define OSR_79     78
#define OSR_80     79
#define OSR_81     80
#define OSR_82     81
#define OSR_83     82
#define OSR_84     83
#define OSR_85     84
#define OSR_86     85
#define OSR_87     86
#define OSR_88     87
#define OSR_89     88
#define OSR_90     89
#define OSR_91     90
#define OSR_92     91
#define OSR_93     92
#define OSR_94     93
#define OSR_95     94
#define OSR_96     95
#define OSR_97     96
#define OSR_98     97
#define OSR_99     98
#define OSR_100     99
#define OSR_101     100
#define OSR_102     101
#define OSR_103     102
#define OSR_104     103
#define OSR_105     104
#define OSR_106     105
#define OSR_107     106
#define OSR_108     107
#define OSR_109     108
#define OSR_110     109
#define OSR_111     110
#define OSR_112     111
#define OSR_113     112
#define OSR_114     113
#define OSR_115     114
#define OSR_116     115
#define OSR_117     116
#define OSR_118     117
#define OSR_119     118
#define OSR_120     119
#define OSR_121     120
#define OSR_122     121
#define OSR_123     122
#define OSR_124     123
#define OSR_125     124
#define OSR_126     125
#define OSR_127     126
#define OSR_128     127
#define OSR_129     128
#define OSR_130     129
#define OSR_131     130
#define OSR_132     131
#define OSR_133     132
#define OSR_134     133
#define OSR_135     134
#define OSR_136     135
#define OSR_137     136
#define OSR_138     137
#define OSR_139     138
#define OSR_140     139
#define OSR_141     140
#define OSR_142     141
#define OSR_143     142
#define OSR_144     143
#define OSR_145     144
#define OSR_146     145
#define OSR_147     146
#define OSR_148     147
#define OSR_149     148
#define OSR_150     149
#define OSR_151     150
#define OSR_152     151
#define OSR_153     152
#define OSR_154     153
#define OSR_155     154
#define OSR_156     155
#define OSR_157     156
#define OSR_158     157
#define OSR_159     158
#define OSR_160     159
#define OSR_161     160
#define OSR_162     161
#define OSR_163     162
#define OSR_164     163
#define OSR_165     164
#define OSR_166     165
#define OSR_167     166
#define OSR_168     167
#define OSR_169     168
#define OSR_170     169
#define OSR_171     170
#define OSR_172     171
#define OSR_173     172
#define OSR_174     173
#define OSR_175     174
#define OSR_176     175
#define OSR_177     176
#define OSR_178     177
#define OSR_179     178
#define OSR_180     179
#define OSR_181     180
#define OSR_182     181
#define OSR_183     182
#define OSR_184     183
#define OSR_185     184
#define OSR_186     185
#define OSR_187     186
#define OSR_188     187
#define OSR_189     188
#define OSR_190     189
#define OSR_191     190
#define OSR_192     191
#define OSR_193     192
#define OSR_194     193
#define OSR_195     194
#define OSR_196     195
#define OSR_197     196
#define OSR_198     197
#define OSR_199     198
#define OSR_200     199
#define OSR_201     200
#define OSR_202     201
#define OSR_203     202
#define OSR_204     203
#define OSR_205     204
#define OSR_206     205
#define OSR_207     206
#define OSR_208     207
#define OSR_209     208
#define OSR_210     209
#define OSR_211     210
#define OSR_212     211
#define OSR_213     212
#define OSR_214     213
#define OSR_215     214
#define OSR_216     215
#define OSR_217     216
#define OSR_218     217
#define OSR_219     218
#define OSR_220     219
#define OSR_221     220
#define OSR_222     221
#define OSR_223     222
#define OSR_224     223
#define OSR_225     224
#define OSR_226     225
#define OSR_227     226
#define OSR_228     227
#define OSR_229     228
#define OSR_230     229
#define OSR_231     230
#define OSR_232     231
#define OSR_233     232
#define OSR_234     233
#define OSR_235     234
#define OSR_236     235
#define OSR_237     236
#define OSR_238     237
#define OSR_239     238
#define OSR_240     239
#define OSR_241     240
#define OSR_242     241
#define OSR_243     242
#define OSR_244     243
#define OSR_245     244
#define OSR_246     245
#define OSR_247     246
#define OSR_248     247
#define OSR_249     248
#define OSR_250     249
#define OSR_251     250
#define OSR_252     251
#define OSR_253     252
#define OSR_254     253
#define OSR_255     254
#define OSR_256     255

//*****************************************************************************
// The following are defines for different OSR values
//*****************************************************************************
#define SHIFT_0_BITS    0
#define SHIFT_1_BITS    1
#define SHIFT_2_BITS    2
#define SHIFT_3_BITS    3
#define SHIFT_4_BITS    4
#define SHIFT_5_BITS    5
#define SHIFT_6_BITS    6
#define SHIFT_7_BITS    7
#define SHIFT_8_BITS    8
#define SHIFT_9_BITS    9
#define SHIFT_10_BITS    10
#define SHIFT_11_BITS    11
#define SHIFT_12_BITS    12
#define SHIFT_13_BITS    13
#define SHIFT_14_BITS    14
#define SHIFT_15_BITS    15
#define SHIFT_16_BITS    16
#define SHIFT_17_BITS    17
#define SHIFT_18_BITS    18
#define SHIFT_19_BITS    19
#define SHIFT_20_BITS    20
#define SHIFT_21_BITS    21
#define SHIFT_22_BITS    22
#define SHIFT_23_BITS    23
#define SHIFT_24_BITS    24
#define SHIFT_25_BITS    25
#define SHIFT_26_BITS    26
#define SHIFT_27_BITS    27
#define SHIFT_28_BITS    28
#define SHIFT_29_BITS    29
#define SHIFT_30_BITS    30
#define SHIFT_31_BITS    31

//*****************************************************************************
// Function prototypes
//*****************************************************************************

extern void Sdfm_configureInputCtrl(Uint16 SDFM_number, Uint16 Filter_number, Uint16 mode);
extern void Sdfm_configureComparator(Uint16 SDFM_number, Uint16 Filter_number, Uint16 Filter_type, Uint16 OSR, Uint16 HLT, Uint16 LLT);
extern void Sdfm_configureData_filter(Uint16 sdfmNumber, Uint16 filterNumber, Uint16 Filter_switch, Uint16 filterType, Uint16 OSR, Uint16 DR_switch, Uint16 shift_bits);
extern void Sdfm_enableMFE(Uint16 SDFM_number);
extern void Sdfm_disableMFE(Uint16 SDFM_number);
extern void Sdfm_configureInterrupt(Uint16 SDFM_number, Uint16 Filter_number,Uint16 IEH_Switch, Uint16 IEL_Switch, Uint16 MFIE_Switch, Uint16 AE_Switch);
extern void Sdfm_enableMIE(Uint16 SDFM_number);
extern void Sdfm_disableMIE(Uint16 SDFM_number);
extern void Sdfm_configureExternalreset(Uint16 SDFM_number, Uint16 filter1_Config_ext_reset, Uint16 filter2_Config_ext_reset, Uint16 filter3_Config_ext_reset, Uint16 filter4_Config_ext_reset);

extern Uint32 Sdfm_readFlagRegister(Uint16 SDFM_number);
extern void Sdfm_clearFlagRegister(Uint16 sdfmNumber,Uint32 sdfmReadFlagRegister);

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif   // - end of F2837xS_SDFM_DRIVERS_H
