/* Generated automatically by the program `genflags'
   from the machine description file `md'.  */

#ifndef GCC_INSN_FLAGS_H
#define GCC_INSN_FLAGS_H

#define HAVE_pushqi1 1
#define HAVE_pushqq1 1
#define HAVE_pushuqq1 1
#define HAVE_pushhi1_insn 1
#define HAVE_load_qi_libgcc (avr_load_libgcc_p (operands[0]) \
   && REG_P (XEXP (operands[0], 0)) \
   && REG_Z == REGNO (XEXP (operands[0], 0)))
#define HAVE_load_qq_libgcc (avr_load_libgcc_p (operands[0]) \
   && REG_P (XEXP (operands[0], 0)) \
   && REG_Z == REGNO (XEXP (operands[0], 0)))
#define HAVE_load_uqq_libgcc (avr_load_libgcc_p (operands[0]) \
   && REG_P (XEXP (operands[0], 0)) \
   && REG_Z == REGNO (XEXP (operands[0], 0)))
#define HAVE_load_hi_libgcc (avr_load_libgcc_p (operands[0]) \
   && REG_P (XEXP (operands[0], 0)) \
   && REG_Z == REGNO (XEXP (operands[0], 0)))
#define HAVE_load_hq_libgcc (avr_load_libgcc_p (operands[0]) \
   && REG_P (XEXP (operands[0], 0)) \
   && REG_Z == REGNO (XEXP (operands[0], 0)))
#define HAVE_load_uhq_libgcc (avr_load_libgcc_p (operands[0]) \
   && REG_P (XEXP (operands[0], 0)) \
   && REG_Z == REGNO (XEXP (operands[0], 0)))
#define HAVE_load_ha_libgcc (avr_load_libgcc_p (operands[0]) \
   && REG_P (XEXP (operands[0], 0)) \
   && REG_Z == REGNO (XEXP (operands[0], 0)))
#define HAVE_load_uha_libgcc (avr_load_libgcc_p (operands[0]) \
   && REG_P (XEXP (operands[0], 0)) \
   && REG_Z == REGNO (XEXP (operands[0], 0)))
#define HAVE_load_si_libgcc (avr_load_libgcc_p (operands[0]) \
   && REG_P (XEXP (operands[0], 0)) \
   && REG_Z == REGNO (XEXP (operands[0], 0)))
#define HAVE_load_sq_libgcc (avr_load_libgcc_p (operands[0]) \
   && REG_P (XEXP (operands[0], 0)) \
   && REG_Z == REGNO (XEXP (operands[0], 0)))
#define HAVE_load_usq_libgcc (avr_load_libgcc_p (operands[0]) \
   && REG_P (XEXP (operands[0], 0)) \
   && REG_Z == REGNO (XEXP (operands[0], 0)))
#define HAVE_load_sa_libgcc (avr_load_libgcc_p (operands[0]) \
   && REG_P (XEXP (operands[0], 0)) \
   && REG_Z == REGNO (XEXP (operands[0], 0)))
#define HAVE_load_usa_libgcc (avr_load_libgcc_p (operands[0]) \
   && REG_P (XEXP (operands[0], 0)) \
   && REG_Z == REGNO (XEXP (operands[0], 0)))
#define HAVE_load_sf_libgcc (avr_load_libgcc_p (operands[0]) \
   && REG_P (XEXP (operands[0], 0)) \
   && REG_Z == REGNO (XEXP (operands[0], 0)))
#define HAVE_load_psi_libgcc (avr_load_libgcc_p (operands[0]) \
   && REG_P (XEXP (operands[0], 0)) \
   && REG_Z == REGNO (XEXP (operands[0], 0)))
#define HAVE_xload8qi_A (can_create_pseudo_p() \
   && !avr_xload_libgcc_p (QImode) \
   && avr_mem_memx_p (operands[1]) \
   && REG_P (XEXP (operands[1], 0)))
#define HAVE_xload8qq_A (can_create_pseudo_p() \
   && !avr_xload_libgcc_p (QQmode) \
   && avr_mem_memx_p (operands[1]) \
   && REG_P (XEXP (operands[1], 0)))
#define HAVE_xload8uqq_A (can_create_pseudo_p() \
   && !avr_xload_libgcc_p (UQQmode) \
   && avr_mem_memx_p (operands[1]) \
   && REG_P (XEXP (operands[1], 0)))
#define HAVE_xloadqi_A (can_create_pseudo_p() \
   && avr_mem_memx_p (operands[1]) \
   && REG_P (XEXP (operands[1], 0)))
#define HAVE_xloadqq_A (can_create_pseudo_p() \
   && avr_mem_memx_p (operands[1]) \
   && REG_P (XEXP (operands[1], 0)))
#define HAVE_xloaduqq_A (can_create_pseudo_p() \
   && avr_mem_memx_p (operands[1]) \
   && REG_P (XEXP (operands[1], 0)))
#define HAVE_xloadhi_A (can_create_pseudo_p() \
   && avr_mem_memx_p (operands[1]) \
   && REG_P (XEXP (operands[1], 0)))
#define HAVE_xloadhq_A (can_create_pseudo_p() \
   && avr_mem_memx_p (operands[1]) \
   && REG_P (XEXP (operands[1], 0)))
#define HAVE_xloaduhq_A (can_create_pseudo_p() \
   && avr_mem_memx_p (operands[1]) \
   && REG_P (XEXP (operands[1], 0)))
#define HAVE_xloadha_A (can_create_pseudo_p() \
   && avr_mem_memx_p (operands[1]) \
   && REG_P (XEXP (operands[1], 0)))
#define HAVE_xloaduha_A (can_create_pseudo_p() \
   && avr_mem_memx_p (operands[1]) \
   && REG_P (XEXP (operands[1], 0)))
#define HAVE_xloadsi_A (can_create_pseudo_p() \
   && avr_mem_memx_p (operands[1]) \
   && REG_P (XEXP (operands[1], 0)))
#define HAVE_xloadsq_A (can_create_pseudo_p() \
   && avr_mem_memx_p (operands[1]) \
   && REG_P (XEXP (operands[1], 0)))
#define HAVE_xloadusq_A (can_create_pseudo_p() \
   && avr_mem_memx_p (operands[1]) \
   && REG_P (XEXP (operands[1], 0)))
#define HAVE_xloadsa_A (can_create_pseudo_p() \
   && avr_mem_memx_p (operands[1]) \
   && REG_P (XEXP (operands[1], 0)))
#define HAVE_xloadusa_A (can_create_pseudo_p() \
   && avr_mem_memx_p (operands[1]) \
   && REG_P (XEXP (operands[1], 0)))
#define HAVE_xloadsf_A (can_create_pseudo_p() \
   && avr_mem_memx_p (operands[1]) \
   && REG_P (XEXP (operands[1], 0)))
#define HAVE_xloadpsi_A (can_create_pseudo_p() \
   && avr_mem_memx_p (operands[1]) \
   && REG_P (XEXP (operands[1], 0)))
#define HAVE_xloadqi_8 (!avr_xload_libgcc_p (QImode))
#define HAVE_xloadqq_8 (!avr_xload_libgcc_p (QQmode))
#define HAVE_xloaduqq_8 (!avr_xload_libgcc_p (UQQmode))
#define HAVE_xload_qi_libgcc (avr_xload_libgcc_p (QImode))
#define HAVE_xload_qq_libgcc (avr_xload_libgcc_p (QQmode))
#define HAVE_xload_uqq_libgcc (avr_xload_libgcc_p (UQQmode))
#define HAVE_xload_hi_libgcc (avr_xload_libgcc_p (HImode))
#define HAVE_xload_hq_libgcc (avr_xload_libgcc_p (HQmode))
#define HAVE_xload_uhq_libgcc (avr_xload_libgcc_p (UHQmode))
#define HAVE_xload_ha_libgcc (avr_xload_libgcc_p (HAmode))
#define HAVE_xload_uha_libgcc (avr_xload_libgcc_p (UHAmode))
#define HAVE_xload_si_libgcc (avr_xload_libgcc_p (SImode))
#define HAVE_xload_sq_libgcc (avr_xload_libgcc_p (SQmode))
#define HAVE_xload_usq_libgcc (avr_xload_libgcc_p (USQmode))
#define HAVE_xload_sa_libgcc (avr_xload_libgcc_p (SAmode))
#define HAVE_xload_usa_libgcc (avr_xload_libgcc_p (USAmode))
#define HAVE_xload_sf_libgcc (avr_xload_libgcc_p (SFmode))
#define HAVE_xload_psi_libgcc (avr_xload_libgcc_p (PSImode))
#define HAVE_movqi_insn (register_operand (operands[0], QImode) \
    || reg_or_0_operand (operands[1], QImode))
#define HAVE_movqq_insn (register_operand (operands[0], QQmode) \
    || reg_or_0_operand (operands[1], QQmode))
#define HAVE_movuqq_insn (register_operand (operands[0], UQQmode) \
    || reg_or_0_operand (operands[1], UQQmode))
#define HAVE_movhi_sp_r 1
#define HAVE_movmem_qi 1
#define HAVE_movmem_hi 1
#define HAVE_movmemx_qi 1
#define HAVE_movmemx_hi 1
#define HAVE_addqi3 1
#define HAVE_addqq3 1
#define HAVE_adduqq3 1
#define HAVE_addhi3_clobber 1
#define HAVE_addhq3_clobber 1
#define HAVE_adduhq3_clobber 1
#define HAVE_addha3_clobber 1
#define HAVE_adduha3_clobber 1
#define HAVE_addsi3 1
#define HAVE_addsq3 1
#define HAVE_addusq3 1
#define HAVE_addsa3 1
#define HAVE_addusa3 1
#define HAVE_addpsi3 1
#define HAVE_subpsi3 1
#define HAVE_subqi3 1
#define HAVE_subqq3 1
#define HAVE_subuqq3 1
#define HAVE_subhi3 1
#define HAVE_subhq3 1
#define HAVE_subuhq3 1
#define HAVE_subha3 1
#define HAVE_subuha3 1
#define HAVE_subsi3 1
#define HAVE_subsq3 1
#define HAVE_subusq3 1
#define HAVE_subsa3 1
#define HAVE_subusa3 1
#define HAVE_smulqi3_highpart (AVR_HAVE_MUL)
#define HAVE_umulqi3_highpart (AVR_HAVE_MUL)
#define HAVE_mulqihi3 (AVR_HAVE_MUL)
#define HAVE_umulqihi3 (AVR_HAVE_MUL)
#define HAVE_usmulqihi3 (AVR_HAVE_MUL)
#define HAVE_mulsqihi3 (AVR_HAVE_MUL)
#define HAVE_muluqihi3 (AVR_HAVE_MUL)
#define HAVE_muloqihi3 (AVR_HAVE_MUL)
#define HAVE_divmodqi4 1
#define HAVE_udivmodqi4 1
#define HAVE_divmodhi4 1
#define HAVE_udivmodhi4 1
#define HAVE_divmodpsi4 1
#define HAVE_udivmodpsi4 1
#define HAVE_divmodsi4 1
#define HAVE_udivmodsi4 1
#define HAVE_andqi3 1
#define HAVE_andhi3 1
#define HAVE_andpsi3 1
#define HAVE_andsi3 1
#define HAVE_iorqi3 1
#define HAVE_iorhi3 1
#define HAVE_iorpsi3 1
#define HAVE_iorsi3 1
#define HAVE_xorqi3 1
#define HAVE_xorhi3 1
#define HAVE_xorpsi3 1
#define HAVE_xorsi3 1
#define HAVE_ashlhi3 1
#define HAVE_ashlhq3 1
#define HAVE_ashluhq3 1
#define HAVE_ashlha3 1
#define HAVE_ashluha3 1
#define HAVE_ashlsi3 1
#define HAVE_ashlsq3 1
#define HAVE_ashlusq3 1
#define HAVE_ashlsa3 1
#define HAVE_ashlusa3 1
#define HAVE_ashrqi3 1
#define HAVE_ashrqq3 1
#define HAVE_ashruqq3 1
#define HAVE_ashrhi3 1
#define HAVE_ashrhq3 1
#define HAVE_ashruhq3 1
#define HAVE_ashrha3 1
#define HAVE_ashruha3 1
#define HAVE_ashrpsi3 1
#define HAVE_ashrsi3 1
#define HAVE_ashrsq3 1
#define HAVE_ashrusq3 1
#define HAVE_ashrsa3 1
#define HAVE_ashrusa3 1
#define HAVE_lshrhi3 1
#define HAVE_lshrhq3 1
#define HAVE_lshruhq3 1
#define HAVE_lshrha3 1
#define HAVE_lshruha3 1
#define HAVE_lshrpsi3 1
#define HAVE_lshrsi3 1
#define HAVE_lshrsq3 1
#define HAVE_lshrusq3 1
#define HAVE_lshrsa3 1
#define HAVE_lshrusa3 1
#define HAVE_absqi2 1
#define HAVE_abssf2 1
#define HAVE_negqi2 1
#define HAVE_neghi2 1
#define HAVE_negpsi2 1
#define HAVE_negsi2 1
#define HAVE_negsf2 1
#define HAVE_one_cmplqi2 1
#define HAVE_one_cmplhi2 1
#define HAVE_one_cmplpsi2 1
#define HAVE_one_cmplsi2 1
#define HAVE_extendqihi2 1
#define HAVE_extendqipsi2 1
#define HAVE_extendqisi2 1
#define HAVE_extendhipsi2 1
#define HAVE_extendhisi2 1
#define HAVE_extendpsisi2 1
#define HAVE_zero_extendqihi2 1
#define HAVE_zero_extendqipsi2 1
#define HAVE_zero_extendqisi2 1
#define HAVE_zero_extendhipsi2 1
#define HAVE_n_extendhipsi2 1
#define HAVE_zero_extendhisi2 1
#define HAVE_zero_extendpsisi2 1
#define HAVE_zero_extendqidi2 1
#define HAVE_zero_extendhidi2 1
#define HAVE_zero_extendsidi2 1
#define HAVE_cmpqi3 1
#define HAVE_cmpqq3 1
#define HAVE_cmpuqq3 1
#define HAVE_cmphi3 1
#define HAVE_cmphq3 1
#define HAVE_cmpuhq3 1
#define HAVE_cmpha3 1
#define HAVE_cmpuha3 1
#define HAVE_branch 1
#define HAVE_branch_unspec 1
#define HAVE_difficult_branch 1
#define HAVE_rvbranch 1
#define HAVE_difficult_rvbranch 1
#define HAVE_jump 1
#define HAVE_call_insn 1
#define HAVE_call_value_insn 1
#define HAVE_nop 1
#define HAVE_casesi_qi_sequence (optimize \
   && avr_casei_sequence_check_operands (operands))
#define HAVE_casesi_hi_sequence (optimize \
   && avr_casei_sequence_check_operands (operands))
#define HAVE_sez 1
#define HAVE_popqi 1
#define HAVE_cli_sei 1
#define HAVE_call_prologue_saves 1
#define HAVE_epilogue_restores 1
#define HAVE_return (reload_completed && avr_simple_epilogue ())
#define HAVE_return_from_epilogue (reload_completed \
   && cfun->machine \
   && !(cfun->machine->is_interrupt || cfun->machine->is_signal) \
   && !cfun->machine->is_naked)
#define HAVE_return_from_interrupt_epilogue (reload_completed \
   && cfun->machine \
   && (cfun->machine->is_interrupt || cfun->machine->is_signal) \
   && !cfun->machine->is_naked)
#define HAVE_return_from_naked_epilogue (reload_completed \
   && cfun->machine \
   && cfun->machine->is_naked)
#define HAVE_delay_cycles_1 1
#define HAVE_delay_cycles_2 1
#define HAVE_delay_cycles_3 1
#define HAVE_delay_cycles_4 1
#define HAVE_insert_bits 1
#define HAVE_copysignsf3 1
#define HAVE_fmul_insn (AVR_HAVE_MUL)
#define HAVE_fmuls_insn (AVR_HAVE_MUL)
#define HAVE_fmulsu_insn (AVR_HAVE_MUL)
#define HAVE_fractuqqqq2 1
#define HAVE_fracthqqq2 1
#define HAVE_fractuhqqq2 1
#define HAVE_fracthaqq2 1
#define HAVE_fractuhaqq2 1
#define HAVE_fractsqqq2 1
#define HAVE_fractusqqq2 1
#define HAVE_fractsaqq2 1
#define HAVE_fractusaqq2 1
#define HAVE_fractdqqq2 1
#define HAVE_fractudqqq2 1
#define HAVE_fractdaqq2 1
#define HAVE_fractudaqq2 1
#define HAVE_fracttaqq2 1
#define HAVE_fractutaqq2 1
#define HAVE_fractqiqq2 1
#define HAVE_fracthiqq2 1
#define HAVE_fractsiqq2 1
#define HAVE_fractdiqq2 1
#define HAVE_fractqquqq2 1
#define HAVE_fracthquqq2 1
#define HAVE_fractuhquqq2 1
#define HAVE_fracthauqq2 1
#define HAVE_fractuhauqq2 1
#define HAVE_fractsquqq2 1
#define HAVE_fractusquqq2 1
#define HAVE_fractsauqq2 1
#define HAVE_fractusauqq2 1
#define HAVE_fractdquqq2 1
#define HAVE_fractudquqq2 1
#define HAVE_fractdauqq2 1
#define HAVE_fractudauqq2 1
#define HAVE_fracttauqq2 1
#define HAVE_fractutauqq2 1
#define HAVE_fractqiuqq2 1
#define HAVE_fracthiuqq2 1
#define HAVE_fractsiuqq2 1
#define HAVE_fractdiuqq2 1
#define HAVE_fractqqhq2 1
#define HAVE_fractuqqhq2 1
#define HAVE_fractuhqhq2 1
#define HAVE_fracthahq2 1
#define HAVE_fractuhahq2 1
#define HAVE_fractsqhq2 1
#define HAVE_fractusqhq2 1
#define HAVE_fractsahq2 1
#define HAVE_fractusahq2 1
#define HAVE_fractdqhq2 1
#define HAVE_fractudqhq2 1
#define HAVE_fractdahq2 1
#define HAVE_fractudahq2 1
#define HAVE_fracttahq2 1
#define HAVE_fractutahq2 1
#define HAVE_fractqihq2 1
#define HAVE_fracthihq2 1
#define HAVE_fractsihq2 1
#define HAVE_fractdihq2 1
#define HAVE_fractqquhq2 1
#define HAVE_fractuqquhq2 1
#define HAVE_fracthquhq2 1
#define HAVE_fracthauhq2 1
#define HAVE_fractuhauhq2 1
#define HAVE_fractsquhq2 1
#define HAVE_fractusquhq2 1
#define HAVE_fractsauhq2 1
#define HAVE_fractusauhq2 1
#define HAVE_fractdquhq2 1
#define HAVE_fractudquhq2 1
#define HAVE_fractdauhq2 1
#define HAVE_fractudauhq2 1
#define HAVE_fracttauhq2 1
#define HAVE_fractutauhq2 1
#define HAVE_fractqiuhq2 1
#define HAVE_fracthiuhq2 1
#define HAVE_fractsiuhq2 1
#define HAVE_fractdiuhq2 1
#define HAVE_fractqqha2 1
#define HAVE_fractuqqha2 1
#define HAVE_fracthqha2 1
#define HAVE_fractuhqha2 1
#define HAVE_fractuhaha2 1
#define HAVE_fractsqha2 1
#define HAVE_fractusqha2 1
#define HAVE_fractsaha2 1
#define HAVE_fractusaha2 1
#define HAVE_fractdqha2 1
#define HAVE_fractudqha2 1
#define HAVE_fractdaha2 1
#define HAVE_fractudaha2 1
#define HAVE_fracttaha2 1
#define HAVE_fractutaha2 1
#define HAVE_fractqiha2 1
#define HAVE_fracthiha2 1
#define HAVE_fractsiha2 1
#define HAVE_fractdiha2 1
#define HAVE_fractqquha2 1
#define HAVE_fractuqquha2 1
#define HAVE_fracthquha2 1
#define HAVE_fractuhquha2 1
#define HAVE_fracthauha2 1
#define HAVE_fractsquha2 1
#define HAVE_fractusquha2 1
#define HAVE_fractsauha2 1
#define HAVE_fractusauha2 1
#define HAVE_fractdquha2 1
#define HAVE_fractudquha2 1
#define HAVE_fractdauha2 1
#define HAVE_fractudauha2 1
#define HAVE_fracttauha2 1
#define HAVE_fractutauha2 1
#define HAVE_fractqiuha2 1
#define HAVE_fracthiuha2 1
#define HAVE_fractsiuha2 1
#define HAVE_fractdiuha2 1
#define HAVE_fractqqsq2 1
#define HAVE_fractuqqsq2 1
#define HAVE_fracthqsq2 1
#define HAVE_fractuhqsq2 1
#define HAVE_fracthasq2 1
#define HAVE_fractuhasq2 1
#define HAVE_fractusqsq2 1
#define HAVE_fractsasq2 1
#define HAVE_fractusasq2 1
#define HAVE_fractdqsq2 1
#define HAVE_fractudqsq2 1
#define HAVE_fractdasq2 1
#define HAVE_fractudasq2 1
#define HAVE_fracttasq2 1
#define HAVE_fractutasq2 1
#define HAVE_fractqisq2 1
#define HAVE_fracthisq2 1
#define HAVE_fractsisq2 1
#define HAVE_fractdisq2 1
#define HAVE_fractqqusq2 1
#define HAVE_fractuqqusq2 1
#define HAVE_fracthqusq2 1
#define HAVE_fractuhqusq2 1
#define HAVE_fracthausq2 1
#define HAVE_fractuhausq2 1
#define HAVE_fractsqusq2 1
#define HAVE_fractsausq2 1
#define HAVE_fractusausq2 1
#define HAVE_fractdqusq2 1
#define HAVE_fractudqusq2 1
#define HAVE_fractdausq2 1
#define HAVE_fractudausq2 1
#define HAVE_fracttausq2 1
#define HAVE_fractutausq2 1
#define HAVE_fractqiusq2 1
#define HAVE_fracthiusq2 1
#define HAVE_fractsiusq2 1
#define HAVE_fractdiusq2 1
#define HAVE_fractqqsa2 1
#define HAVE_fractuqqsa2 1
#define HAVE_fracthqsa2 1
#define HAVE_fractuhqsa2 1
#define HAVE_fracthasa2 1
#define HAVE_fractuhasa2 1
#define HAVE_fractsqsa2 1
#define HAVE_fractusqsa2 1
#define HAVE_fractusasa2 1
#define HAVE_fractdqsa2 1
#define HAVE_fractudqsa2 1
#define HAVE_fractdasa2 1
#define HAVE_fractudasa2 1
#define HAVE_fracttasa2 1
#define HAVE_fractutasa2 1
#define HAVE_fractqisa2 1
#define HAVE_fracthisa2 1
#define HAVE_fractsisa2 1
#define HAVE_fractdisa2 1
#define HAVE_fractqqusa2 1
#define HAVE_fractuqqusa2 1
#define HAVE_fracthqusa2 1
#define HAVE_fractuhqusa2 1
#define HAVE_fracthausa2 1
#define HAVE_fractuhausa2 1
#define HAVE_fractsqusa2 1
#define HAVE_fractusqusa2 1
#define HAVE_fractsausa2 1
#define HAVE_fractdqusa2 1
#define HAVE_fractudqusa2 1
#define HAVE_fractdausa2 1
#define HAVE_fractudausa2 1
#define HAVE_fracttausa2 1
#define HAVE_fractutausa2 1
#define HAVE_fractqiusa2 1
#define HAVE_fracthiusa2 1
#define HAVE_fractsiusa2 1
#define HAVE_fractdiusa2 1
#define HAVE_fractqqdq2 1
#define HAVE_fractuqqdq2 1
#define HAVE_fracthqdq2 1
#define HAVE_fractuhqdq2 1
#define HAVE_fracthadq2 1
#define HAVE_fractuhadq2 1
#define HAVE_fractsqdq2 1
#define HAVE_fractusqdq2 1
#define HAVE_fractsadq2 1
#define HAVE_fractusadq2 1
#define HAVE_fractudqdq2 1
#define HAVE_fractdadq2 1
#define HAVE_fractudadq2 1
#define HAVE_fracttadq2 1
#define HAVE_fractutadq2 1
#define HAVE_fractqidq2 1
#define HAVE_fracthidq2 1
#define HAVE_fractsidq2 1
#define HAVE_fractdidq2 1
#define HAVE_fractqqudq2 1
#define HAVE_fractuqqudq2 1
#define HAVE_fracthqudq2 1
#define HAVE_fractuhqudq2 1
#define HAVE_fracthaudq2 1
#define HAVE_fractuhaudq2 1
#define HAVE_fractsqudq2 1
#define HAVE_fractusqudq2 1
#define HAVE_fractsaudq2 1
#define HAVE_fractusaudq2 1
#define HAVE_fractdqudq2 1
#define HAVE_fractdaudq2 1
#define HAVE_fractudaudq2 1
#define HAVE_fracttaudq2 1
#define HAVE_fractutaudq2 1
#define HAVE_fractqiudq2 1
#define HAVE_fracthiudq2 1
#define HAVE_fractsiudq2 1
#define HAVE_fractdiudq2 1
#define HAVE_fractqqda2 1
#define HAVE_fractuqqda2 1
#define HAVE_fracthqda2 1
#define HAVE_fractuhqda2 1
#define HAVE_fracthada2 1
#define HAVE_fractuhada2 1
#define HAVE_fractsqda2 1
#define HAVE_fractusqda2 1
#define HAVE_fractsada2 1
#define HAVE_fractusada2 1
#define HAVE_fractdqda2 1
#define HAVE_fractudqda2 1
#define HAVE_fractudada2 1
#define HAVE_fracttada2 1
#define HAVE_fractutada2 1
#define HAVE_fractqida2 1
#define HAVE_fracthida2 1
#define HAVE_fractsida2 1
#define HAVE_fractdida2 1
#define HAVE_fractqquda2 1
#define HAVE_fractuqquda2 1
#define HAVE_fracthquda2 1
#define HAVE_fractuhquda2 1
#define HAVE_fracthauda2 1
#define HAVE_fractuhauda2 1
#define HAVE_fractsquda2 1
#define HAVE_fractusquda2 1
#define HAVE_fractsauda2 1
#define HAVE_fractusauda2 1
#define HAVE_fractdquda2 1
#define HAVE_fractudquda2 1
#define HAVE_fractdauda2 1
#define HAVE_fracttauda2 1
#define HAVE_fractutauda2 1
#define HAVE_fractqiuda2 1
#define HAVE_fracthiuda2 1
#define HAVE_fractsiuda2 1
#define HAVE_fractdiuda2 1
#define HAVE_fractqqta2 1
#define HAVE_fractuqqta2 1
#define HAVE_fracthqta2 1
#define HAVE_fractuhqta2 1
#define HAVE_fracthata2 1
#define HAVE_fractuhata2 1
#define HAVE_fractsqta2 1
#define HAVE_fractusqta2 1
#define HAVE_fractsata2 1
#define HAVE_fractusata2 1
#define HAVE_fractdqta2 1
#define HAVE_fractudqta2 1
#define HAVE_fractdata2 1
#define HAVE_fractudata2 1
#define HAVE_fractutata2 1
#define HAVE_fractqita2 1
#define HAVE_fracthita2 1
#define HAVE_fractsita2 1
#define HAVE_fractdita2 1
#define HAVE_fractqquta2 1
#define HAVE_fractuqquta2 1
#define HAVE_fracthquta2 1
#define HAVE_fractuhquta2 1
#define HAVE_fracthauta2 1
#define HAVE_fractuhauta2 1
#define HAVE_fractsquta2 1
#define HAVE_fractusquta2 1
#define HAVE_fractsauta2 1
#define HAVE_fractusauta2 1
#define HAVE_fractdquta2 1
#define HAVE_fractudquta2 1
#define HAVE_fractdauta2 1
#define HAVE_fractudauta2 1
#define HAVE_fracttauta2 1
#define HAVE_fractqiuta2 1
#define HAVE_fracthiuta2 1
#define HAVE_fractsiuta2 1
#define HAVE_fractdiuta2 1
#define HAVE_fractqqqi2 1
#define HAVE_fractuqqqi2 1
#define HAVE_fracthqqi2 1
#define HAVE_fractuhqqi2 1
#define HAVE_fracthaqi2 1
#define HAVE_fractuhaqi2 1
#define HAVE_fractsqqi2 1
#define HAVE_fractusqqi2 1
#define HAVE_fractsaqi2 1
#define HAVE_fractusaqi2 1
#define HAVE_fractdqqi2 1
#define HAVE_fractudqqi2 1
#define HAVE_fractdaqi2 1
#define HAVE_fractudaqi2 1
#define HAVE_fracttaqi2 1
#define HAVE_fractutaqi2 1
#define HAVE_fracthiqi2 1
#define HAVE_fractsiqi2 1
#define HAVE_fractdiqi2 1
#define HAVE_fractqqhi2 1
#define HAVE_fractuqqhi2 1
#define HAVE_fracthqhi2 1
#define HAVE_fractuhqhi2 1
#define HAVE_fracthahi2 1
#define HAVE_fractuhahi2 1
#define HAVE_fractsqhi2 1
#define HAVE_fractusqhi2 1
#define HAVE_fractsahi2 1
#define HAVE_fractusahi2 1
#define HAVE_fractdqhi2 1
#define HAVE_fractudqhi2 1
#define HAVE_fractdahi2 1
#define HAVE_fractudahi2 1
#define HAVE_fracttahi2 1
#define HAVE_fractutahi2 1
#define HAVE_fractqihi2 1
#define HAVE_fractsihi2 1
#define HAVE_fractdihi2 1
#define HAVE_fractqqsi2 1
#define HAVE_fractuqqsi2 1
#define HAVE_fracthqsi2 1
#define HAVE_fractuhqsi2 1
#define HAVE_fracthasi2 1
#define HAVE_fractuhasi2 1
#define HAVE_fractsqsi2 1
#define HAVE_fractusqsi2 1
#define HAVE_fractsasi2 1
#define HAVE_fractusasi2 1
#define HAVE_fractdqsi2 1
#define HAVE_fractudqsi2 1
#define HAVE_fractdasi2 1
#define HAVE_fractudasi2 1
#define HAVE_fracttasi2 1
#define HAVE_fractutasi2 1
#define HAVE_fractqisi2 1
#define HAVE_fracthisi2 1
#define HAVE_fractdisi2 1
#define HAVE_fractqqdi2 1
#define HAVE_fractuqqdi2 1
#define HAVE_fracthqdi2 1
#define HAVE_fractuhqdi2 1
#define HAVE_fracthadi2 1
#define HAVE_fractuhadi2 1
#define HAVE_fractsqdi2 1
#define HAVE_fractusqdi2 1
#define HAVE_fractsadi2 1
#define HAVE_fractusadi2 1
#define HAVE_fractdqdi2 1
#define HAVE_fractudqdi2 1
#define HAVE_fractdadi2 1
#define HAVE_fractudadi2 1
#define HAVE_fracttadi2 1
#define HAVE_fractutadi2 1
#define HAVE_fractqidi2 1
#define HAVE_fracthidi2 1
#define HAVE_fractsidi2 1
#define HAVE_fractunsuqqqq2 1
#define HAVE_fractunshqqq2 1
#define HAVE_fractunsuhqqq2 1
#define HAVE_fractunshaqq2 1
#define HAVE_fractunsuhaqq2 1
#define HAVE_fractunssqqq2 1
#define HAVE_fractunsusqqq2 1
#define HAVE_fractunssaqq2 1
#define HAVE_fractunsusaqq2 1
#define HAVE_fractunsdqqq2 1
#define HAVE_fractunsudqqq2 1
#define HAVE_fractunsdaqq2 1
#define HAVE_fractunsudaqq2 1
#define HAVE_fractunstaqq2 1
#define HAVE_fractunsutaqq2 1
#define HAVE_fractunsqiqq2 1
#define HAVE_fractunshiqq2 1
#define HAVE_fractunssiqq2 1
#define HAVE_fractunsdiqq2 1
#define HAVE_fractunsqquqq2 1
#define HAVE_fractunshquqq2 1
#define HAVE_fractunsuhquqq2 1
#define HAVE_fractunshauqq2 1
#define HAVE_fractunsuhauqq2 1
#define HAVE_fractunssquqq2 1
#define HAVE_fractunsusquqq2 1
#define HAVE_fractunssauqq2 1
#define HAVE_fractunsusauqq2 1
#define HAVE_fractunsdquqq2 1
#define HAVE_fractunsudquqq2 1
#define HAVE_fractunsdauqq2 1
#define HAVE_fractunsudauqq2 1
#define HAVE_fractunstauqq2 1
#define HAVE_fractunsutauqq2 1
#define HAVE_fractunsqiuqq2 1
#define HAVE_fractunshiuqq2 1
#define HAVE_fractunssiuqq2 1
#define HAVE_fractunsdiuqq2 1
#define HAVE_fractunsqqhq2 1
#define HAVE_fractunsuqqhq2 1
#define HAVE_fractunsuhqhq2 1
#define HAVE_fractunshahq2 1
#define HAVE_fractunsuhahq2 1
#define HAVE_fractunssqhq2 1
#define HAVE_fractunsusqhq2 1
#define HAVE_fractunssahq2 1
#define HAVE_fractunsusahq2 1
#define HAVE_fractunsdqhq2 1
#define HAVE_fractunsudqhq2 1
#define HAVE_fractunsdahq2 1
#define HAVE_fractunsudahq2 1
#define HAVE_fractunstahq2 1
#define HAVE_fractunsutahq2 1
#define HAVE_fractunsqihq2 1
#define HAVE_fractunshihq2 1
#define HAVE_fractunssihq2 1
#define HAVE_fractunsdihq2 1
#define HAVE_fractunsqquhq2 1
#define HAVE_fractunsuqquhq2 1
#define HAVE_fractunshquhq2 1
#define HAVE_fractunshauhq2 1
#define HAVE_fractunsuhauhq2 1
#define HAVE_fractunssquhq2 1
#define HAVE_fractunsusquhq2 1
#define HAVE_fractunssauhq2 1
#define HAVE_fractunsusauhq2 1
#define HAVE_fractunsdquhq2 1
#define HAVE_fractunsudquhq2 1
#define HAVE_fractunsdauhq2 1
#define HAVE_fractunsudauhq2 1
#define HAVE_fractunstauhq2 1
#define HAVE_fractunsutauhq2 1
#define HAVE_fractunsqiuhq2 1
#define HAVE_fractunshiuhq2 1
#define HAVE_fractunssiuhq2 1
#define HAVE_fractunsdiuhq2 1
#define HAVE_fractunsqqha2 1
#define HAVE_fractunsuqqha2 1
#define HAVE_fractunshqha2 1
#define HAVE_fractunsuhqha2 1
#define HAVE_fractunsuhaha2 1
#define HAVE_fractunssqha2 1
#define HAVE_fractunsusqha2 1
#define HAVE_fractunssaha2 1
#define HAVE_fractunsusaha2 1
#define HAVE_fractunsdqha2 1
#define HAVE_fractunsudqha2 1
#define HAVE_fractunsdaha2 1
#define HAVE_fractunsudaha2 1
#define HAVE_fractunstaha2 1
#define HAVE_fractunsutaha2 1
#define HAVE_fractunsqiha2 1
#define HAVE_fractunshiha2 1
#define HAVE_fractunssiha2 1
#define HAVE_fractunsdiha2 1
#define HAVE_fractunsqquha2 1
#define HAVE_fractunsuqquha2 1
#define HAVE_fractunshquha2 1
#define HAVE_fractunsuhquha2 1
#define HAVE_fractunshauha2 1
#define HAVE_fractunssquha2 1
#define HAVE_fractunsusquha2 1
#define HAVE_fractunssauha2 1
#define HAVE_fractunsusauha2 1
#define HAVE_fractunsdquha2 1
#define HAVE_fractunsudquha2 1
#define HAVE_fractunsdauha2 1
#define HAVE_fractunsudauha2 1
#define HAVE_fractunstauha2 1
#define HAVE_fractunsutauha2 1
#define HAVE_fractunsqiuha2 1
#define HAVE_fractunshiuha2 1
#define HAVE_fractunssiuha2 1
#define HAVE_fractunsdiuha2 1
#define HAVE_fractunsqqsq2 1
#define HAVE_fractunsuqqsq2 1
#define HAVE_fractunshqsq2 1
#define HAVE_fractunsuhqsq2 1
#define HAVE_fractunshasq2 1
#define HAVE_fractunsuhasq2 1
#define HAVE_fractunsusqsq2 1
#define HAVE_fractunssasq2 1
#define HAVE_fractunsusasq2 1
#define HAVE_fractunsdqsq2 1
#define HAVE_fractunsudqsq2 1
#define HAVE_fractunsdasq2 1
#define HAVE_fractunsudasq2 1
#define HAVE_fractunstasq2 1
#define HAVE_fractunsutasq2 1
#define HAVE_fractunsqisq2 1
#define HAVE_fractunshisq2 1
#define HAVE_fractunssisq2 1
#define HAVE_fractunsdisq2 1
#define HAVE_fractunsqqusq2 1
#define HAVE_fractunsuqqusq2 1
#define HAVE_fractunshqusq2 1
#define HAVE_fractunsuhqusq2 1
#define HAVE_fractunshausq2 1
#define HAVE_fractunsuhausq2 1
#define HAVE_fractunssqusq2 1
#define HAVE_fractunssausq2 1
#define HAVE_fractunsusausq2 1
#define HAVE_fractunsdqusq2 1
#define HAVE_fractunsudqusq2 1
#define HAVE_fractunsdausq2 1
#define HAVE_fractunsudausq2 1
#define HAVE_fractunstausq2 1
#define HAVE_fractunsutausq2 1
#define HAVE_fractunsqiusq2 1
#define HAVE_fractunshiusq2 1
#define HAVE_fractunssiusq2 1
#define HAVE_fractunsdiusq2 1
#define HAVE_fractunsqqsa2 1
#define HAVE_fractunsuqqsa2 1
#define HAVE_fractunshqsa2 1
#define HAVE_fractunsuhqsa2 1
#define HAVE_fractunshasa2 1
#define HAVE_fractunsuhasa2 1
#define HAVE_fractunssqsa2 1
#define HAVE_fractunsusqsa2 1
#define HAVE_fractunsusasa2 1
#define HAVE_fractunsdqsa2 1
#define HAVE_fractunsudqsa2 1
#define HAVE_fractunsdasa2 1
#define HAVE_fractunsudasa2 1
#define HAVE_fractunstasa2 1
#define HAVE_fractunsutasa2 1
#define HAVE_fractunsqisa2 1
#define HAVE_fractunshisa2 1
#define HAVE_fractunssisa2 1
#define HAVE_fractunsdisa2 1
#define HAVE_fractunsqqusa2 1
#define HAVE_fractunsuqqusa2 1
#define HAVE_fractunshqusa2 1
#define HAVE_fractunsuhqusa2 1
#define HAVE_fractunshausa2 1
#define HAVE_fractunsuhausa2 1
#define HAVE_fractunssqusa2 1
#define HAVE_fractunsusqusa2 1
#define HAVE_fractunssausa2 1
#define HAVE_fractunsdqusa2 1
#define HAVE_fractunsudqusa2 1
#define HAVE_fractunsdausa2 1
#define HAVE_fractunsudausa2 1
#define HAVE_fractunstausa2 1
#define HAVE_fractunsutausa2 1
#define HAVE_fractunsqiusa2 1
#define HAVE_fractunshiusa2 1
#define HAVE_fractunssiusa2 1
#define HAVE_fractunsdiusa2 1
#define HAVE_fractunsqqdq2 1
#define HAVE_fractunsuqqdq2 1
#define HAVE_fractunshqdq2 1
#define HAVE_fractunsuhqdq2 1
#define HAVE_fractunshadq2 1
#define HAVE_fractunsuhadq2 1
#define HAVE_fractunssqdq2 1
#define HAVE_fractunsusqdq2 1
#define HAVE_fractunssadq2 1
#define HAVE_fractunsusadq2 1
#define HAVE_fractunsudqdq2 1
#define HAVE_fractunsdadq2 1
#define HAVE_fractunsudadq2 1
#define HAVE_fractunstadq2 1
#define HAVE_fractunsutadq2 1
#define HAVE_fractunsqidq2 1
#define HAVE_fractunshidq2 1
#define HAVE_fractunssidq2 1
#define HAVE_fractunsdidq2 1
#define HAVE_fractunsqqudq2 1
#define HAVE_fractunsuqqudq2 1
#define HAVE_fractunshqudq2 1
#define HAVE_fractunsuhqudq2 1
#define HAVE_fractunshaudq2 1
#define HAVE_fractunsuhaudq2 1
#define HAVE_fractunssqudq2 1
#define HAVE_fractunsusqudq2 1
#define HAVE_fractunssaudq2 1
#define HAVE_fractunsusaudq2 1
#define HAVE_fractunsdqudq2 1
#define HAVE_fractunsdaudq2 1
#define HAVE_fractunsudaudq2 1
#define HAVE_fractunstaudq2 1
#define HAVE_fractunsutaudq2 1
#define HAVE_fractunsqiudq2 1
#define HAVE_fractunshiudq2 1
#define HAVE_fractunssiudq2 1
#define HAVE_fractunsdiudq2 1
#define HAVE_fractunsqqda2 1
#define HAVE_fractunsuqqda2 1
#define HAVE_fractunshqda2 1
#define HAVE_fractunsuhqda2 1
#define HAVE_fractunshada2 1
#define HAVE_fractunsuhada2 1
#define HAVE_fractunssqda2 1
#define HAVE_fractunsusqda2 1
#define HAVE_fractunssada2 1
#define HAVE_fractunsusada2 1
#define HAVE_fractunsdqda2 1
#define HAVE_fractunsudqda2 1
#define HAVE_fractunsudada2 1
#define HAVE_fractunstada2 1
#define HAVE_fractunsutada2 1
#define HAVE_fractunsqida2 1
#define HAVE_fractunshida2 1
#define HAVE_fractunssida2 1
#define HAVE_fractunsdida2 1
#define HAVE_fractunsqquda2 1
#define HAVE_fractunsuqquda2 1
#define HAVE_fractunshquda2 1
#define HAVE_fractunsuhquda2 1
#define HAVE_fractunshauda2 1
#define HAVE_fractunsuhauda2 1
#define HAVE_fractunssquda2 1
#define HAVE_fractunsusquda2 1
#define HAVE_fractunssauda2 1
#define HAVE_fractunsusauda2 1
#define HAVE_fractunsdquda2 1
#define HAVE_fractunsudquda2 1
#define HAVE_fractunsdauda2 1
#define HAVE_fractunstauda2 1
#define HAVE_fractunsutauda2 1
#define HAVE_fractunsqiuda2 1
#define HAVE_fractunshiuda2 1
#define HAVE_fractunssiuda2 1
#define HAVE_fractunsdiuda2 1
#define HAVE_fractunsqqta2 1
#define HAVE_fractunsuqqta2 1
#define HAVE_fractunshqta2 1
#define HAVE_fractunsuhqta2 1
#define HAVE_fractunshata2 1
#define HAVE_fractunsuhata2 1
#define HAVE_fractunssqta2 1
#define HAVE_fractunsusqta2 1
#define HAVE_fractunssata2 1
#define HAVE_fractunsusata2 1
#define HAVE_fractunsdqta2 1
#define HAVE_fractunsudqta2 1
#define HAVE_fractunsdata2 1
#define HAVE_fractunsudata2 1
#define HAVE_fractunsutata2 1
#define HAVE_fractunsqita2 1
#define HAVE_fractunshita2 1
#define HAVE_fractunssita2 1
#define HAVE_fractunsdita2 1
#define HAVE_fractunsqquta2 1
#define HAVE_fractunsuqquta2 1
#define HAVE_fractunshquta2 1
#define HAVE_fractunsuhquta2 1
#define HAVE_fractunshauta2 1
#define HAVE_fractunsuhauta2 1
#define HAVE_fractunssquta2 1
#define HAVE_fractunsusquta2 1
#define HAVE_fractunssauta2 1
#define HAVE_fractunsusauta2 1
#define HAVE_fractunsdquta2 1
#define HAVE_fractunsudquta2 1
#define HAVE_fractunsdauta2 1
#define HAVE_fractunsudauta2 1
#define HAVE_fractunstauta2 1
#define HAVE_fractunsqiuta2 1
#define HAVE_fractunshiuta2 1
#define HAVE_fractunssiuta2 1
#define HAVE_fractunsdiuta2 1
#define HAVE_fractunsqqqi2 1
#define HAVE_fractunsuqqqi2 1
#define HAVE_fractunshqqi2 1
#define HAVE_fractunsuhqqi2 1
#define HAVE_fractunshaqi2 1
#define HAVE_fractunsuhaqi2 1
#define HAVE_fractunssqqi2 1
#define HAVE_fractunsusqqi2 1
#define HAVE_fractunssaqi2 1
#define HAVE_fractunsusaqi2 1
#define HAVE_fractunsdqqi2 1
#define HAVE_fractunsudqqi2 1
#define HAVE_fractunsdaqi2 1
#define HAVE_fractunsudaqi2 1
#define HAVE_fractunstaqi2 1
#define HAVE_fractunsutaqi2 1
#define HAVE_fractunshiqi2 1
#define HAVE_fractunssiqi2 1
#define HAVE_fractunsdiqi2 1
#define HAVE_fractunsqqhi2 1
#define HAVE_fractunsuqqhi2 1
#define HAVE_fractunshqhi2 1
#define HAVE_fractunsuhqhi2 1
#define HAVE_fractunshahi2 1
#define HAVE_fractunsuhahi2 1
#define HAVE_fractunssqhi2 1
#define HAVE_fractunsusqhi2 1
#define HAVE_fractunssahi2 1
#define HAVE_fractunsusahi2 1
#define HAVE_fractunsdqhi2 1
#define HAVE_fractunsudqhi2 1
#define HAVE_fractunsdahi2 1
#define HAVE_fractunsudahi2 1
#define HAVE_fractunstahi2 1
#define HAVE_fractunsutahi2 1
#define HAVE_fractunsqihi2 1
#define HAVE_fractunssihi2 1
#define HAVE_fractunsdihi2 1
#define HAVE_fractunsqqsi2 1
#define HAVE_fractunsuqqsi2 1
#define HAVE_fractunshqsi2 1
#define HAVE_fractunsuhqsi2 1
#define HAVE_fractunshasi2 1
#define HAVE_fractunsuhasi2 1
#define HAVE_fractunssqsi2 1
#define HAVE_fractunsusqsi2 1
#define HAVE_fractunssasi2 1
#define HAVE_fractunsusasi2 1
#define HAVE_fractunsdqsi2 1
#define HAVE_fractunsudqsi2 1
#define HAVE_fractunsdasi2 1
#define HAVE_fractunsudasi2 1
#define HAVE_fractunstasi2 1
#define HAVE_fractunsutasi2 1
#define HAVE_fractunsqisi2 1
#define HAVE_fractunshisi2 1
#define HAVE_fractunsdisi2 1
#define HAVE_fractunsqqdi2 1
#define HAVE_fractunsuqqdi2 1
#define HAVE_fractunshqdi2 1
#define HAVE_fractunsuhqdi2 1
#define HAVE_fractunshadi2 1
#define HAVE_fractunsuhadi2 1
#define HAVE_fractunssqdi2 1
#define HAVE_fractunsusqdi2 1
#define HAVE_fractunssadi2 1
#define HAVE_fractunsusadi2 1
#define HAVE_fractunsdqdi2 1
#define HAVE_fractunsudqdi2 1
#define HAVE_fractunsdadi2 1
#define HAVE_fractunsudadi2 1
#define HAVE_fractunstadi2 1
#define HAVE_fractunsutadi2 1
#define HAVE_fractunsqidi2 1
#define HAVE_fractunshidi2 1
#define HAVE_fractunssidi2 1
#define HAVE_ssaddqq3 1
#define HAVE_sssubqq3 1
#define HAVE_ssaddhq3 1
#define HAVE_sssubhq3 1
#define HAVE_ssaddha3 1
#define HAVE_sssubha3 1
#define HAVE_ssaddsa3 1
#define HAVE_sssubsa3 1
#define HAVE_ssaddsq3 1
#define HAVE_sssubsq3 1
#define HAVE_usadduqq3 1
#define HAVE_ussubuqq3 1
#define HAVE_usadduhq3 1
#define HAVE_ussubuhq3 1
#define HAVE_usadduha3 1
#define HAVE_ussubuha3 1
#define HAVE_usaddusa3 1
#define HAVE_ussubusa3 1
#define HAVE_usaddusq3 1
#define HAVE_ussubusq3 1
#define HAVE_ssnegqq2 1
#define HAVE_ssabsqq2 1
#define HAVE_mulqq3_enh (AVR_HAVE_MUL)
#define HAVE_muluqq3_enh (AVR_HAVE_MUL)
#define HAVE_roundqq3_const 1
#define HAVE_roundhq3_const 1
#define HAVE_roundha3_const 1
#define HAVE_roundsa3_const 1
#define HAVE_roundsq3_const 1
#define HAVE_rounduqq3_const 1
#define HAVE_rounduhq3_const 1
#define HAVE_rounduha3_const 1
#define HAVE_roundusa3_const 1
#define HAVE_roundusq3_const 1
#define HAVE_adddi3_insn (avr_have_dimode)
#define HAVE_adddq3_insn (avr_have_dimode)
#define HAVE_addudq3_insn (avr_have_dimode)
#define HAVE_addda3_insn (avr_have_dimode)
#define HAVE_adduda3_insn (avr_have_dimode)
#define HAVE_addta3_insn (avr_have_dimode)
#define HAVE_adduta3_insn (avr_have_dimode)
#define HAVE_adddi3_const8_insn (avr_have_dimode)
#define HAVE_adddi3_const_insn (avr_have_dimode \
   && !s8_operand (operands[0], VOIDmode))
#define HAVE_adddq3_const_insn (avr_have_dimode \
   && !s8_operand (operands[0], VOIDmode))
#define HAVE_addudq3_const_insn (avr_have_dimode \
   && !s8_operand (operands[0], VOIDmode))
#define HAVE_addda3_const_insn (avr_have_dimode \
   && !s8_operand (operands[0], VOIDmode))
#define HAVE_adduda3_const_insn (avr_have_dimode \
   && !s8_operand (operands[0], VOIDmode))
#define HAVE_addta3_const_insn (avr_have_dimode \
   && !s8_operand (operands[0], VOIDmode))
#define HAVE_adduta3_const_insn (avr_have_dimode \
   && !s8_operand (operands[0], VOIDmode))
#define HAVE_subdi3_insn (avr_have_dimode)
#define HAVE_subdq3_insn (avr_have_dimode)
#define HAVE_subudq3_insn (avr_have_dimode)
#define HAVE_subda3_insn (avr_have_dimode)
#define HAVE_subuda3_insn (avr_have_dimode)
#define HAVE_subta3_insn (avr_have_dimode)
#define HAVE_subuta3_insn (avr_have_dimode)
#define HAVE_subdi3_const_insn (avr_have_dimode)
#define HAVE_subdq3_const_insn (avr_have_dimode)
#define HAVE_subudq3_const_insn (avr_have_dimode)
#define HAVE_subda3_const_insn (avr_have_dimode)
#define HAVE_subuda3_const_insn (avr_have_dimode)
#define HAVE_subta3_const_insn (avr_have_dimode)
#define HAVE_subuta3_const_insn (avr_have_dimode)
#define HAVE_ssadddq3_insn (avr_have_dimode)
#define HAVE_sssubdq3_insn (avr_have_dimode)
#define HAVE_ssaddda3_insn (avr_have_dimode)
#define HAVE_sssubda3_insn (avr_have_dimode)
#define HAVE_ssaddta3_insn (avr_have_dimode)
#define HAVE_sssubta3_insn (avr_have_dimode)
#define HAVE_ssadddq3_const_insn (avr_have_dimode)
#define HAVE_sssubdq3_const_insn (avr_have_dimode)
#define HAVE_ssaddda3_const_insn (avr_have_dimode)
#define HAVE_sssubda3_const_insn (avr_have_dimode)
#define HAVE_ssaddta3_const_insn (avr_have_dimode)
#define HAVE_sssubta3_const_insn (avr_have_dimode)
#define HAVE_usaddudq3_insn (avr_have_dimode)
#define HAVE_ussubudq3_insn (avr_have_dimode)
#define HAVE_usadduda3_insn (avr_have_dimode)
#define HAVE_ussubuda3_insn (avr_have_dimode)
#define HAVE_usadduta3_insn (avr_have_dimode)
#define HAVE_ussubuta3_insn (avr_have_dimode)
#define HAVE_usaddudq3_const_insn (avr_have_dimode)
#define HAVE_ussubudq3_const_insn (avr_have_dimode)
#define HAVE_usadduda3_const_insn (avr_have_dimode)
#define HAVE_ussubuda3_const_insn (avr_have_dimode)
#define HAVE_usadduta3_const_insn (avr_have_dimode)
#define HAVE_ussubuta3_const_insn (avr_have_dimode)
#define HAVE_negdi2_insn (avr_have_dimode)
#define HAVE_compare_di2 (avr_have_dimode)
#define HAVE_compare_dq2 (avr_have_dimode)
#define HAVE_compare_udq2 (avr_have_dimode)
#define HAVE_compare_da2 (avr_have_dimode)
#define HAVE_compare_uda2 (avr_have_dimode)
#define HAVE_compare_ta2 (avr_have_dimode)
#define HAVE_compare_uta2 (avr_have_dimode)
#define HAVE_compare_const8_di2 (avr_have_dimode)
#define HAVE_compare_const_di2 (avr_have_dimode \
   && !s8_operand (operands[0], VOIDmode))
#define HAVE_compare_const_dq2 (avr_have_dimode \
   && !s8_operand (operands[0], VOIDmode))
#define HAVE_compare_const_udq2 (avr_have_dimode \
   && !s8_operand (operands[0], VOIDmode))
#define HAVE_compare_const_da2 (avr_have_dimode \
   && !s8_operand (operands[0], VOIDmode))
#define HAVE_compare_const_uda2 (avr_have_dimode \
   && !s8_operand (operands[0], VOIDmode))
#define HAVE_compare_const_ta2 (avr_have_dimode \
   && !s8_operand (operands[0], VOIDmode))
#define HAVE_compare_const_uta2 (avr_have_dimode \
   && !s8_operand (operands[0], VOIDmode))
#define HAVE_ashldi3_insn (avr_have_dimode)
#define HAVE_ashrdi3_insn (avr_have_dimode)
#define HAVE_lshrdi3_insn (avr_have_dimode)
#define HAVE_rotldi3_insn (avr_have_dimode)
#define HAVE_ashldq3_insn (avr_have_dimode)
#define HAVE_ashrdq3_insn (avr_have_dimode)
#define HAVE_lshrdq3_insn (avr_have_dimode)
#define HAVE_rotldq3_insn (avr_have_dimode)
#define HAVE_ashludq3_insn (avr_have_dimode)
#define HAVE_ashrudq3_insn (avr_have_dimode)
#define HAVE_lshrudq3_insn (avr_have_dimode)
#define HAVE_rotludq3_insn (avr_have_dimode)
#define HAVE_ashlda3_insn (avr_have_dimode)
#define HAVE_ashrda3_insn (avr_have_dimode)
#define HAVE_lshrda3_insn (avr_have_dimode)
#define HAVE_rotlda3_insn (avr_have_dimode)
#define HAVE_ashluda3_insn (avr_have_dimode)
#define HAVE_ashruda3_insn (avr_have_dimode)
#define HAVE_lshruda3_insn (avr_have_dimode)
#define HAVE_rotluda3_insn (avr_have_dimode)
#define HAVE_ashlta3_insn (avr_have_dimode)
#define HAVE_ashrta3_insn (avr_have_dimode)
#define HAVE_lshrta3_insn (avr_have_dimode)
#define HAVE_rotlta3_insn (avr_have_dimode)
#define HAVE_ashluta3_insn (avr_have_dimode)
#define HAVE_ashruta3_insn (avr_have_dimode)
#define HAVE_lshruta3_insn (avr_have_dimode)
#define HAVE_rotluta3_insn (avr_have_dimode)
#define HAVE_mulsidi3_insn (avr_have_dimode \
   && AVR_HAVE_MUL)
#define HAVE_umulsidi3_insn (avr_have_dimode \
   && AVR_HAVE_MUL)
#define HAVE_nonlocal_goto_receiver 1
#define HAVE_nonlocal_goto 1
#define HAVE_pushcqi1 1
#define HAVE_pushhi1 1
#define HAVE_pushchi1 1
#define HAVE_pushha1 1
#define HAVE_pushuha1 1
#define HAVE_pushhq1 1
#define HAVE_pushuhq1 1
#define HAVE_pushsi1 1
#define HAVE_pushcsi1 1
#define HAVE_pushsa1 1
#define HAVE_pushusa1 1
#define HAVE_pushsq1 1
#define HAVE_pushusq1 1
#define HAVE_pushdi1 1
#define HAVE_pushcdi1 1
#define HAVE_pushda1 1
#define HAVE_pushuda1 1
#define HAVE_pushdq1 1
#define HAVE_pushudq1 1
#define HAVE_pushta1 1
#define HAVE_pushuta1 1
#define HAVE_pushsf1 1
#define HAVE_pushsc1 1
#define HAVE_pushpsi1 1
#define HAVE_loadqi_libgcc (avr_load_libgcc_p (operands[1]))
#define HAVE_loadqq_libgcc (avr_load_libgcc_p (operands[1]))
#define HAVE_loaduqq_libgcc (avr_load_libgcc_p (operands[1]))
#define HAVE_loadhi_libgcc (avr_load_libgcc_p (operands[1]))
#define HAVE_loadhq_libgcc (avr_load_libgcc_p (operands[1]))
#define HAVE_loaduhq_libgcc (avr_load_libgcc_p (operands[1]))
#define HAVE_loadha_libgcc (avr_load_libgcc_p (operands[1]))
#define HAVE_loaduha_libgcc (avr_load_libgcc_p (operands[1]))
#define HAVE_loadsi_libgcc (avr_load_libgcc_p (operands[1]))
#define HAVE_loadsq_libgcc (avr_load_libgcc_p (operands[1]))
#define HAVE_loadusq_libgcc (avr_load_libgcc_p (operands[1]))
#define HAVE_loadsa_libgcc (avr_load_libgcc_p (operands[1]))
#define HAVE_loadusa_libgcc (avr_load_libgcc_p (operands[1]))
#define HAVE_loadsf_libgcc (avr_load_libgcc_p (operands[1]))
#define HAVE_loadpsi_libgcc (avr_load_libgcc_p (operands[1]))
#define HAVE_movqi 1
#define HAVE_movqq 1
#define HAVE_movuqq 1
#define HAVE_movhi 1
#define HAVE_movhq 1
#define HAVE_movuhq 1
#define HAVE_movha 1
#define HAVE_movuha 1
#define HAVE_movsi 1
#define HAVE_movsq 1
#define HAVE_movusq 1
#define HAVE_movsa 1
#define HAVE_movusa 1
#define HAVE_movsf 1
#define HAVE_movpsi 1
#define HAVE_movmemhi 1
#define HAVE_setmemhi 1
#define HAVE_strlenhi 1
#define HAVE_addhi3 1
#define HAVE_addhq3 1
#define HAVE_adduhq3 1
#define HAVE_addha3 1
#define HAVE_adduha3 1
#define HAVE_mulqi3 1
#define HAVE_mulqi3_call 1
#define HAVE_mulhi3 1
#define HAVE_mulhi3_call 1
#define HAVE_mulsi3 (AVR_HAVE_MUL)
#define HAVE_muluqisi3 (AVR_HAVE_MUL)
#define HAVE_muluhisi3 (AVR_HAVE_MUL)
#define HAVE_mulsqisi3 (AVR_HAVE_MUL)
#define HAVE_mulshisi3 (AVR_HAVE_MUL)
#define HAVE_mulohisi3 (AVR_HAVE_MUL)
#define HAVE_mulhisi3 (AVR_HAVE_MUL)
#define HAVE_umulhisi3 (AVR_HAVE_MUL)
#define HAVE_usmulhisi3 (AVR_HAVE_MUL)
#define HAVE_smulhi3_highpart (AVR_HAVE_MUL)
#define HAVE_umulhi3_highpart (AVR_HAVE_MUL)
#define HAVE_mulpsi3 (AVR_HAVE_MUL)
#define HAVE_mulsqipsi3 (AVR_HAVE_MUL)
#define HAVE_rotlqi3 1
#define HAVE_rotlqi3_4 1
#define HAVE_rotlhi3 1
#define HAVE_rotlpsi3 1
#define HAVE_rotlsi3 1
#define HAVE_ashlqi3 1
#define HAVE_ashlqq3 1
#define HAVE_ashluqq3 1
#define HAVE_ashlpsi3 1
#define HAVE_lshrqi3 1
#define HAVE_lshrqq3 1
#define HAVE_lshruqq3 1
#define HAVE_cbranchqi4 1
#define HAVE_cbranchqq4 1
#define HAVE_cbranchuqq4 1
#define HAVE_cbranchhi4 1
#define HAVE_cbranchsi4 1
#define HAVE_cbranchpsi4 1
#define HAVE_cbranchhq4 1
#define HAVE_cbranchuhq4 1
#define HAVE_cbranchha4 1
#define HAVE_cbranchuha4 1
#define HAVE_cbranchsq4 1
#define HAVE_cbranchusq4 1
#define HAVE_cbranchsa4 1
#define HAVE_cbranchusa4 1
#define HAVE_call 1
#define HAVE_sibcall 1
#define HAVE_call_value 1
#define HAVE_sibcall_value 1
#define HAVE_indirect_jump 1
#define HAVE_casesi 1
#define HAVE_enable_interrupt 1
#define HAVE_disable_interrupt 1
#define HAVE_prologue 1
#define HAVE_epilogue 1
#define HAVE_sibcall_epilogue 1
#define HAVE_flash_segment1 1
#define HAVE_flash_segment 1
#define HAVE_parityhi2 1
#define HAVE_paritysi2 1
#define HAVE_popcounthi2 1
#define HAVE_popcountsi2 1
#define HAVE_clzhi2 1
#define HAVE_clzsi2 1
#define HAVE_ctzhi2 1
#define HAVE_ctzsi2 1
#define HAVE_ffshi2 1
#define HAVE_ffssi2 1
#define HAVE_bswapsi2 1
#define HAVE_nopv 1
#define HAVE_sleep 1
#define HAVE_wdr 1
#define HAVE_fmul 1
#define HAVE_fmuls 1
#define HAVE_fmulsu 1
#define HAVE_insv (optimize)
#define HAVE_extzv 1
#define HAVE_usneguqq2 1
#define HAVE_usneguhq2 1
#define HAVE_usneguha2 1
#define HAVE_usnegusa2 1
#define HAVE_usnegusq2 1
#define HAVE_ssabshq2 1
#define HAVE_ssneghq2 1
#define HAVE_ssabsha2 1
#define HAVE_ssnegha2 1
#define HAVE_ssabssa2 1
#define HAVE_ssnegsa2 1
#define HAVE_ssabssq2 1
#define HAVE_ssnegsq2 1
#define HAVE_mulqq3 1
#define HAVE_muluqq3 1
#define HAVE_mulqq3_nomul (!AVR_HAVE_MUL)
#define HAVE_muluqq3_nomul (!AVR_HAVE_MUL)
#define HAVE_mulhq3 (AVR_HAVE_MUL)
#define HAVE_muluhq3 (AVR_HAVE_MUL)
#define HAVE_mulha3 (AVR_HAVE_MUL)
#define HAVE_muluha3 (AVR_HAVE_MUL)
#define HAVE_mulsa3 (AVR_HAVE_MUL)
#define HAVE_mulusa3 (AVR_HAVE_MUL)
#define HAVE_udivqq3 1
#define HAVE_divqq3 1
#define HAVE_udivuqq3 1
#define HAVE_divuqq3 1
#define HAVE_udivhq3 1
#define HAVE_divhq3 1
#define HAVE_udivuhq3 1
#define HAVE_divuhq3 1
#define HAVE_udivha3 1
#define HAVE_divha3 1
#define HAVE_udivuha3 1
#define HAVE_divuha3 1
#define HAVE_udivsa3 1
#define HAVE_divsa3 1
#define HAVE_udivusa3 1
#define HAVE_divusa3 1
#define HAVE_roundqq3 1
#define HAVE_roundhq3 1
#define HAVE_roundha3 1
#define HAVE_roundsa3 1
#define HAVE_roundsq3 1
#define HAVE_rounduqq3 1
#define HAVE_rounduhq3 1
#define HAVE_rounduha3 1
#define HAVE_roundusa3 1
#define HAVE_roundusq3 1
#define HAVE_adddi3 (avr_have_dimode)
#define HAVE_adddq3 (avr_have_dimode)
#define HAVE_addudq3 (avr_have_dimode)
#define HAVE_addda3 (avr_have_dimode)
#define HAVE_adduda3 (avr_have_dimode)
#define HAVE_addta3 (avr_have_dimode)
#define HAVE_adduta3 (avr_have_dimode)
#define HAVE_subdi3 (avr_have_dimode)
#define HAVE_subdq3 (avr_have_dimode)
#define HAVE_subudq3 (avr_have_dimode)
#define HAVE_subda3 (avr_have_dimode)
#define HAVE_subuda3 (avr_have_dimode)
#define HAVE_subta3 (avr_have_dimode)
#define HAVE_subuta3 (avr_have_dimode)
#define HAVE_ssadddq3 (avr_have_dimode)
#define HAVE_sssubdq3 (avr_have_dimode)
#define HAVE_ssaddda3 (avr_have_dimode)
#define HAVE_sssubda3 (avr_have_dimode)
#define HAVE_ssaddta3 (avr_have_dimode)
#define HAVE_sssubta3 (avr_have_dimode)
#define HAVE_usaddudq3 (avr_have_dimode)
#define HAVE_ussubudq3 (avr_have_dimode)
#define HAVE_usadduda3 (avr_have_dimode)
#define HAVE_ussubuda3 (avr_have_dimode)
#define HAVE_usadduta3 (avr_have_dimode)
#define HAVE_ussubuta3 (avr_have_dimode)
#define HAVE_negdi2 (avr_have_dimode)
#define HAVE_conditional_jump (avr_have_dimode)
#define HAVE_cbranchdi4 (avr_have_dimode)
#define HAVE_cbranchdq4 (avr_have_dimode)
#define HAVE_cbranchudq4 (avr_have_dimode)
#define HAVE_cbranchda4 (avr_have_dimode)
#define HAVE_cbranchuda4 (avr_have_dimode)
#define HAVE_cbranchta4 (avr_have_dimode)
#define HAVE_cbranchuta4 (avr_have_dimode)
#define HAVE_ashldi3 (avr_have_dimode)
#define HAVE_ashrdi3 (avr_have_dimode)
#define HAVE_lshrdi3 (avr_have_dimode)
#define HAVE_rotldi3 (avr_have_dimode)
#define HAVE_ashldq3 (avr_have_dimode)
#define HAVE_ashrdq3 (avr_have_dimode)
#define HAVE_lshrdq3 (avr_have_dimode)
#define HAVE_rotldq3 (avr_have_dimode)
#define HAVE_ashludq3 (avr_have_dimode)
#define HAVE_ashrudq3 (avr_have_dimode)
#define HAVE_lshrudq3 (avr_have_dimode)
#define HAVE_rotludq3 (avr_have_dimode)
#define HAVE_ashlda3 (avr_have_dimode)
#define HAVE_ashrda3 (avr_have_dimode)
#define HAVE_lshrda3 (avr_have_dimode)
#define HAVE_rotlda3 (avr_have_dimode)
#define HAVE_ashluda3 (avr_have_dimode)
#define HAVE_ashruda3 (avr_have_dimode)
#define HAVE_lshruda3 (avr_have_dimode)
#define HAVE_rotluda3 (avr_have_dimode)
#define HAVE_ashlta3 (avr_have_dimode)
#define HAVE_ashrta3 (avr_have_dimode)
#define HAVE_lshrta3 (avr_have_dimode)
#define HAVE_rotlta3 (avr_have_dimode)
#define HAVE_ashluta3 (avr_have_dimode)
#define HAVE_ashruta3 (avr_have_dimode)
#define HAVE_lshruta3 (avr_have_dimode)
#define HAVE_rotluta3 (avr_have_dimode)
#define HAVE_mulsidi3 (avr_have_dimode \
   && AVR_HAVE_MUL)
#define HAVE_umulsidi3 (avr_have_dimode \
   && AVR_HAVE_MUL)
extern rtx        gen_pushqi1                        (rtx);
extern rtx        gen_pushqq1                        (rtx);
extern rtx        gen_pushuqq1                       (rtx);
extern rtx        gen_pushhi1_insn                   (rtx);
extern rtx        gen_load_qi_libgcc                 (rtx);
extern rtx        gen_load_qq_libgcc                 (rtx);
extern rtx        gen_load_uqq_libgcc                (rtx);
extern rtx        gen_load_hi_libgcc                 (rtx);
extern rtx        gen_load_hq_libgcc                 (rtx);
extern rtx        gen_load_uhq_libgcc                (rtx);
extern rtx        gen_load_ha_libgcc                 (rtx);
extern rtx        gen_load_uha_libgcc                (rtx);
extern rtx        gen_load_si_libgcc                 (rtx);
extern rtx        gen_load_sq_libgcc                 (rtx);
extern rtx        gen_load_usq_libgcc                (rtx);
extern rtx        gen_load_sa_libgcc                 (rtx);
extern rtx        gen_load_usa_libgcc                (rtx);
extern rtx        gen_load_sf_libgcc                 (rtx);
extern rtx        gen_load_psi_libgcc                (rtx);
extern rtx        gen_xload8qi_A                     (rtx, rtx);
extern rtx        gen_xload8qq_A                     (rtx, rtx);
extern rtx        gen_xload8uqq_A                    (rtx, rtx);
extern rtx        gen_xloadqi_A                      (rtx, rtx);
extern rtx        gen_xloadqq_A                      (rtx, rtx);
extern rtx        gen_xloaduqq_A                     (rtx, rtx);
extern rtx        gen_xloadhi_A                      (rtx, rtx);
extern rtx        gen_xloadhq_A                      (rtx, rtx);
extern rtx        gen_xloaduhq_A                     (rtx, rtx);
extern rtx        gen_xloadha_A                      (rtx, rtx);
extern rtx        gen_xloaduha_A                     (rtx, rtx);
extern rtx        gen_xloadsi_A                      (rtx, rtx);
extern rtx        gen_xloadsq_A                      (rtx, rtx);
extern rtx        gen_xloadusq_A                     (rtx, rtx);
extern rtx        gen_xloadsa_A                      (rtx, rtx);
extern rtx        gen_xloadusa_A                     (rtx, rtx);
extern rtx        gen_xloadsf_A                      (rtx, rtx);
extern rtx        gen_xloadpsi_A                     (rtx, rtx);
extern rtx        gen_xloadqi_8                      (rtx, rtx);
extern rtx        gen_xloadqq_8                      (rtx, rtx);
extern rtx        gen_xloaduqq_8                     (rtx, rtx);
extern rtx        gen_xload_qi_libgcc                (void);
extern rtx        gen_xload_qq_libgcc                (void);
extern rtx        gen_xload_uqq_libgcc               (void);
extern rtx        gen_xload_hi_libgcc                (void);
extern rtx        gen_xload_hq_libgcc                (void);
extern rtx        gen_xload_uhq_libgcc               (void);
extern rtx        gen_xload_ha_libgcc                (void);
extern rtx        gen_xload_uha_libgcc               (void);
extern rtx        gen_xload_si_libgcc                (void);
extern rtx        gen_xload_sq_libgcc                (void);
extern rtx        gen_xload_usq_libgcc               (void);
extern rtx        gen_xload_sa_libgcc                (void);
extern rtx        gen_xload_usa_libgcc               (void);
extern rtx        gen_xload_sf_libgcc                (void);
extern rtx        gen_xload_psi_libgcc               (void);
extern rtx        gen_movqi_insn                     (rtx, rtx);
extern rtx        gen_movqq_insn                     (rtx, rtx);
extern rtx        gen_movuqq_insn                    (rtx, rtx);
extern rtx        gen_movhi_sp_r                     (rtx, rtx, rtx);
extern rtx        gen_movmem_qi                      (rtx, rtx, rtx);
extern rtx        gen_movmem_hi                      (rtx, rtx, rtx);
extern rtx        gen_movmemx_qi                     (rtx, rtx);
extern rtx        gen_movmemx_hi                     (rtx, rtx);
extern rtx        gen_addqi3                         (rtx, rtx, rtx);
extern rtx        gen_addqq3                         (rtx, rtx, rtx);
extern rtx        gen_adduqq3                        (rtx, rtx, rtx);
extern rtx        gen_addhi3_clobber                 (rtx, rtx, rtx);
extern rtx        gen_addhq3_clobber                 (rtx, rtx, rtx);
extern rtx        gen_adduhq3_clobber                (rtx, rtx, rtx);
extern rtx        gen_addha3_clobber                 (rtx, rtx, rtx);
extern rtx        gen_adduha3_clobber                (rtx, rtx, rtx);
extern rtx        gen_addsi3                         (rtx, rtx, rtx);
extern rtx        gen_addsq3                         (rtx, rtx, rtx);
extern rtx        gen_addusq3                        (rtx, rtx, rtx);
extern rtx        gen_addsa3                         (rtx, rtx, rtx);
extern rtx        gen_addusa3                        (rtx, rtx, rtx);
extern rtx        gen_addpsi3                        (rtx, rtx, rtx);
extern rtx        gen_subpsi3                        (rtx, rtx, rtx);
extern rtx        gen_subqi3                         (rtx, rtx, rtx);
extern rtx        gen_subqq3                         (rtx, rtx, rtx);
extern rtx        gen_subuqq3                        (rtx, rtx, rtx);
extern rtx        gen_subhi3                         (rtx, rtx, rtx);
extern rtx        gen_subhq3                         (rtx, rtx, rtx);
extern rtx        gen_subuhq3                        (rtx, rtx, rtx);
extern rtx        gen_subha3                         (rtx, rtx, rtx);
extern rtx        gen_subuha3                        (rtx, rtx, rtx);
extern rtx        gen_subsi3                         (rtx, rtx, rtx);
extern rtx        gen_subsq3                         (rtx, rtx, rtx);
extern rtx        gen_subusq3                        (rtx, rtx, rtx);
extern rtx        gen_subsa3                         (rtx, rtx, rtx);
extern rtx        gen_subusa3                        (rtx, rtx, rtx);
extern rtx        gen_smulqi3_highpart               (rtx, rtx, rtx);
extern rtx        gen_umulqi3_highpart               (rtx, rtx, rtx);
extern rtx        gen_mulqihi3                       (rtx, rtx, rtx);
extern rtx        gen_umulqihi3                      (rtx, rtx, rtx);
extern rtx        gen_usmulqihi3                     (rtx, rtx, rtx);
extern rtx        gen_mulsqihi3                      (rtx, rtx, rtx);
extern rtx        gen_muluqihi3                      (rtx, rtx, rtx);
extern rtx        gen_muloqihi3                      (rtx, rtx, rtx);
extern rtx        gen_divmodqi4                      (rtx, rtx, rtx, rtx);
extern rtx        gen_udivmodqi4                     (rtx, rtx, rtx, rtx);
extern rtx        gen_divmodhi4                      (rtx, rtx, rtx, rtx);
extern rtx        gen_udivmodhi4                     (rtx, rtx, rtx, rtx);
extern rtx        gen_divmodpsi4                     (rtx, rtx, rtx, rtx);
extern rtx        gen_udivmodpsi4                    (rtx, rtx, rtx, rtx);
extern rtx        gen_divmodsi4                      (rtx, rtx, rtx, rtx);
extern rtx        gen_udivmodsi4                     (rtx, rtx, rtx, rtx);
extern rtx        gen_andqi3                         (rtx, rtx, rtx);
extern rtx        gen_andhi3                         (rtx, rtx, rtx);
extern rtx        gen_andpsi3                        (rtx, rtx, rtx);
extern rtx        gen_andsi3                         (rtx, rtx, rtx);
extern rtx        gen_iorqi3                         (rtx, rtx, rtx);
extern rtx        gen_iorhi3                         (rtx, rtx, rtx);
extern rtx        gen_iorpsi3                        (rtx, rtx, rtx);
extern rtx        gen_iorsi3                         (rtx, rtx, rtx);
extern rtx        gen_xorqi3                         (rtx, rtx, rtx);
extern rtx        gen_xorhi3                         (rtx, rtx, rtx);
extern rtx        gen_xorpsi3                        (rtx, rtx, rtx);
extern rtx        gen_xorsi3                         (rtx, rtx, rtx);
extern rtx        gen_ashlhi3                        (rtx, rtx, rtx);
extern rtx        gen_ashlhq3                        (rtx, rtx, rtx);
extern rtx        gen_ashluhq3                       (rtx, rtx, rtx);
extern rtx        gen_ashlha3                        (rtx, rtx, rtx);
extern rtx        gen_ashluha3                       (rtx, rtx, rtx);
extern rtx        gen_ashlsi3                        (rtx, rtx, rtx);
extern rtx        gen_ashlsq3                        (rtx, rtx, rtx);
extern rtx        gen_ashlusq3                       (rtx, rtx, rtx);
extern rtx        gen_ashlsa3                        (rtx, rtx, rtx);
extern rtx        gen_ashlusa3                       (rtx, rtx, rtx);
extern rtx        gen_ashrqi3                        (rtx, rtx, rtx);
extern rtx        gen_ashrqq3                        (rtx, rtx, rtx);
extern rtx        gen_ashruqq3                       (rtx, rtx, rtx);
extern rtx        gen_ashrhi3                        (rtx, rtx, rtx);
extern rtx        gen_ashrhq3                        (rtx, rtx, rtx);
extern rtx        gen_ashruhq3                       (rtx, rtx, rtx);
extern rtx        gen_ashrha3                        (rtx, rtx, rtx);
extern rtx        gen_ashruha3                       (rtx, rtx, rtx);
extern rtx        gen_ashrpsi3                       (rtx, rtx, rtx);
extern rtx        gen_ashrsi3                        (rtx, rtx, rtx);
extern rtx        gen_ashrsq3                        (rtx, rtx, rtx);
extern rtx        gen_ashrusq3                       (rtx, rtx, rtx);
extern rtx        gen_ashrsa3                        (rtx, rtx, rtx);
extern rtx        gen_ashrusa3                       (rtx, rtx, rtx);
extern rtx        gen_lshrhi3                        (rtx, rtx, rtx);
extern rtx        gen_lshrhq3                        (rtx, rtx, rtx);
extern rtx        gen_lshruhq3                       (rtx, rtx, rtx);
extern rtx        gen_lshrha3                        (rtx, rtx, rtx);
extern rtx        gen_lshruha3                       (rtx, rtx, rtx);
extern rtx        gen_lshrpsi3                       (rtx, rtx, rtx);
extern rtx        gen_lshrsi3                        (rtx, rtx, rtx);
extern rtx        gen_lshrsq3                        (rtx, rtx, rtx);
extern rtx        gen_lshrusq3                       (rtx, rtx, rtx);
extern rtx        gen_lshrsa3                        (rtx, rtx, rtx);
extern rtx        gen_lshrusa3                       (rtx, rtx, rtx);
extern rtx        gen_absqi2                         (rtx, rtx);
extern rtx        gen_abssf2                         (rtx, rtx);
extern rtx        gen_negqi2                         (rtx, rtx);
extern rtx        gen_neghi2                         (rtx, rtx);
extern rtx        gen_negpsi2                        (rtx, rtx);
extern rtx        gen_negsi2                         (rtx, rtx);
extern rtx        gen_negsf2                         (rtx, rtx);
extern rtx        gen_one_cmplqi2                    (rtx, rtx);
extern rtx        gen_one_cmplhi2                    (rtx, rtx);
extern rtx        gen_one_cmplpsi2                   (rtx, rtx);
extern rtx        gen_one_cmplsi2                    (rtx, rtx);
extern rtx        gen_extendqihi2                    (rtx, rtx);
extern rtx        gen_extendqipsi2                   (rtx, rtx);
extern rtx        gen_extendqisi2                    (rtx, rtx);
extern rtx        gen_extendhipsi2                   (rtx, rtx);
extern rtx        gen_extendhisi2                    (rtx, rtx);
extern rtx        gen_extendpsisi2                   (rtx, rtx);
extern rtx        gen_zero_extendqihi2               (rtx, rtx);
extern rtx        gen_zero_extendqipsi2              (rtx, rtx);
extern rtx        gen_zero_extendqisi2               (rtx, rtx);
extern rtx        gen_zero_extendhipsi2              (rtx, rtx);
extern rtx        gen_n_extendhipsi2                 (rtx, rtx, rtx);
extern rtx        gen_zero_extendhisi2               (rtx, rtx);
extern rtx        gen_zero_extendpsisi2              (rtx, rtx);
extern rtx        gen_zero_extendqidi2               (rtx, rtx);
extern rtx        gen_zero_extendhidi2               (rtx, rtx);
extern rtx        gen_zero_extendsidi2               (rtx, rtx);
extern rtx        gen_cmpqi3                         (rtx, rtx);
extern rtx        gen_cmpqq3                         (rtx, rtx);
extern rtx        gen_cmpuqq3                        (rtx, rtx);
extern rtx        gen_cmphi3                         (rtx, rtx);
extern rtx        gen_cmphq3                         (rtx, rtx);
extern rtx        gen_cmpuhq3                        (rtx, rtx);
extern rtx        gen_cmpha3                         (rtx, rtx);
extern rtx        gen_cmpuha3                        (rtx, rtx);
extern rtx        gen_branch                         (rtx, rtx);
extern rtx        gen_branch_unspec                  (rtx, rtx);
extern rtx        gen_difficult_branch               (rtx, rtx);
extern rtx        gen_rvbranch                       (rtx, rtx);
extern rtx        gen_difficult_rvbranch             (rtx, rtx);
extern rtx        gen_jump                           (rtx);
extern rtx        gen_call_insn                      (rtx, rtx, rtx);
extern rtx        gen_call_value_insn                (rtx, rtx, rtx, rtx);
extern rtx        gen_nop                            (void);
extern rtx        gen_casesi_qi_sequence             (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_casesi_hi_sequence             (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sez                            (void);
extern rtx        gen_popqi                          (rtx);
extern rtx        gen_cli_sei                        (rtx, rtx);
extern rtx        gen_call_prologue_saves            (rtx, rtx);
extern rtx        gen_epilogue_restores              (rtx);
extern rtx        gen_return                         (void);
extern rtx        gen_return_from_epilogue           (void);
extern rtx        gen_return_from_interrupt_epilogue (void);
extern rtx        gen_return_from_naked_epilogue     (void);
extern rtx        gen_delay_cycles_1                 (rtx, rtx);
extern rtx        gen_delay_cycles_2                 (rtx, rtx);
extern rtx        gen_delay_cycles_3                 (rtx, rtx);
extern rtx        gen_delay_cycles_4                 (rtx, rtx);
extern rtx        gen_insert_bits                    (rtx, rtx, rtx, rtx);
extern rtx        gen_copysignsf3                    (rtx, rtx, rtx);
extern rtx        gen_fmul_insn                      (rtx, rtx, rtx);
extern rtx        gen_fmuls_insn                     (rtx, rtx, rtx);
extern rtx        gen_fmulsu_insn                    (rtx, rtx, rtx);
static inline rtx gen_fractqqqq2                     (rtx, rtx);
static inline rtx
gen_fractqqqq2(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b))
{
  return 0;
}
extern rtx        gen_fractuqqqq2                    (rtx, rtx);
extern rtx        gen_fracthqqq2                     (rtx, rtx);
extern rtx        gen_fractuhqqq2                    (rtx, rtx);
extern rtx        gen_fracthaqq2                     (rtx, rtx);
extern rtx        gen_fractuhaqq2                    (rtx, rtx);
extern rtx        gen_fractsqqq2                     (rtx, rtx);
extern rtx        gen_fractusqqq2                    (rtx, rtx);
extern rtx        gen_fractsaqq2                     (rtx, rtx);
extern rtx        gen_fractusaqq2                    (rtx, rtx);
extern rtx        gen_fractdqqq2                     (rtx, rtx);
extern rtx        gen_fractudqqq2                    (rtx, rtx);
extern rtx        gen_fractdaqq2                     (rtx, rtx);
extern rtx        gen_fractudaqq2                    (rtx, rtx);
extern rtx        gen_fracttaqq2                     (rtx, rtx);
extern rtx        gen_fractutaqq2                    (rtx, rtx);
extern rtx        gen_fractqiqq2                     (rtx, rtx);
extern rtx        gen_fracthiqq2                     (rtx, rtx);
extern rtx        gen_fractsiqq2                     (rtx, rtx);
extern rtx        gen_fractdiqq2                     (rtx, rtx);
extern rtx        gen_fractqquqq2                    (rtx, rtx);
static inline rtx gen_fractuqquqq2                   (rtx, rtx);
static inline rtx
gen_fractuqquqq2(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b))
{
  return 0;
}
extern rtx        gen_fracthquqq2                    (rtx, rtx);
extern rtx        gen_fractuhquqq2                   (rtx, rtx);
extern rtx        gen_fracthauqq2                    (rtx, rtx);
extern rtx        gen_fractuhauqq2                   (rtx, rtx);
extern rtx        gen_fractsquqq2                    (rtx, rtx);
extern rtx        gen_fractusquqq2                   (rtx, rtx);
extern rtx        gen_fractsauqq2                    (rtx, rtx);
extern rtx        gen_fractusauqq2                   (rtx, rtx);
extern rtx        gen_fractdquqq2                    (rtx, rtx);
extern rtx        gen_fractudquqq2                   (rtx, rtx);
extern rtx        gen_fractdauqq2                    (rtx, rtx);
extern rtx        gen_fractudauqq2                   (rtx, rtx);
extern rtx        gen_fracttauqq2                    (rtx, rtx);
extern rtx        gen_fractutauqq2                   (rtx, rtx);
extern rtx        gen_fractqiuqq2                    (rtx, rtx);
extern rtx        gen_fracthiuqq2                    (rtx, rtx);
extern rtx        gen_fractsiuqq2                    (rtx, rtx);
extern rtx        gen_fractdiuqq2                    (rtx, rtx);
extern rtx        gen_fractqqhq2                     (rtx, rtx);
extern rtx        gen_fractuqqhq2                    (rtx, rtx);
static inline rtx gen_fracthqhq2                     (rtx, rtx);
static inline rtx
gen_fracthqhq2(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b))
{
  return 0;
}
extern rtx        gen_fractuhqhq2                    (rtx, rtx);
extern rtx        gen_fracthahq2                     (rtx, rtx);
extern rtx        gen_fractuhahq2                    (rtx, rtx);
extern rtx        gen_fractsqhq2                     (rtx, rtx);
extern rtx        gen_fractusqhq2                    (rtx, rtx);
extern rtx        gen_fractsahq2                     (rtx, rtx);
extern rtx        gen_fractusahq2                    (rtx, rtx);
extern rtx        gen_fractdqhq2                     (rtx, rtx);
extern rtx        gen_fractudqhq2                    (rtx, rtx);
extern rtx        gen_fractdahq2                     (rtx, rtx);
extern rtx        gen_fractudahq2                    (rtx, rtx);
extern rtx        gen_fracttahq2                     (rtx, rtx);
extern rtx        gen_fractutahq2                    (rtx, rtx);
extern rtx        gen_fractqihq2                     (rtx, rtx);
extern rtx        gen_fracthihq2                     (rtx, rtx);
extern rtx        gen_fractsihq2                     (rtx, rtx);
extern rtx        gen_fractdihq2                     (rtx, rtx);
extern rtx        gen_fractqquhq2                    (rtx, rtx);
extern rtx        gen_fractuqquhq2                   (rtx, rtx);
extern rtx        gen_fracthquhq2                    (rtx, rtx);
static inline rtx gen_fractuhquhq2                   (rtx, rtx);
static inline rtx
gen_fractuhquhq2(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b))
{
  return 0;
}
extern rtx        gen_fracthauhq2                    (rtx, rtx);
extern rtx        gen_fractuhauhq2                   (rtx, rtx);
extern rtx        gen_fractsquhq2                    (rtx, rtx);
extern rtx        gen_fractusquhq2                   (rtx, rtx);
extern rtx        gen_fractsauhq2                    (rtx, rtx);
extern rtx        gen_fractusauhq2                   (rtx, rtx);
extern rtx        gen_fractdquhq2                    (rtx, rtx);
extern rtx        gen_fractudquhq2                   (rtx, rtx);
extern rtx        gen_fractdauhq2                    (rtx, rtx);
extern rtx        gen_fractudauhq2                   (rtx, rtx);
extern rtx        gen_fracttauhq2                    (rtx, rtx);
extern rtx        gen_fractutauhq2                   (rtx, rtx);
extern rtx        gen_fractqiuhq2                    (rtx, rtx);
extern rtx        gen_fracthiuhq2                    (rtx, rtx);
extern rtx        gen_fractsiuhq2                    (rtx, rtx);
extern rtx        gen_fractdiuhq2                    (rtx, rtx);
extern rtx        gen_fractqqha2                     (rtx, rtx);
extern rtx        gen_fractuqqha2                    (rtx, rtx);
extern rtx        gen_fracthqha2                     (rtx, rtx);
extern rtx        gen_fractuhqha2                    (rtx, rtx);
static inline rtx gen_fracthaha2                     (rtx, rtx);
static inline rtx
gen_fracthaha2(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b))
{
  return 0;
}
extern rtx        gen_fractuhaha2                    (rtx, rtx);
extern rtx        gen_fractsqha2                     (rtx, rtx);
extern rtx        gen_fractusqha2                    (rtx, rtx);
extern rtx        gen_fractsaha2                     (rtx, rtx);
extern rtx        gen_fractusaha2                    (rtx, rtx);
extern rtx        gen_fractdqha2                     (rtx, rtx);
extern rtx        gen_fractudqha2                    (rtx, rtx);
extern rtx        gen_fractdaha2                     (rtx, rtx);
extern rtx        gen_fractudaha2                    (rtx, rtx);
extern rtx        gen_fracttaha2                     (rtx, rtx);
extern rtx        gen_fractutaha2                    (rtx, rtx);
extern rtx        gen_fractqiha2                     (rtx, rtx);
extern rtx        gen_fracthiha2                     (rtx, rtx);
extern rtx        gen_fractsiha2                     (rtx, rtx);
extern rtx        gen_fractdiha2                     (rtx, rtx);
extern rtx        gen_fractqquha2                    (rtx, rtx);
extern rtx        gen_fractuqquha2                   (rtx, rtx);
extern rtx        gen_fracthquha2                    (rtx, rtx);
extern rtx        gen_fractuhquha2                   (rtx, rtx);
extern rtx        gen_fracthauha2                    (rtx, rtx);
static inline rtx gen_fractuhauha2                   (rtx, rtx);
static inline rtx
gen_fractuhauha2(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b))
{
  return 0;
}
extern rtx        gen_fractsquha2                    (rtx, rtx);
extern rtx        gen_fractusquha2                   (rtx, rtx);
extern rtx        gen_fractsauha2                    (rtx, rtx);
extern rtx        gen_fractusauha2                   (rtx, rtx);
extern rtx        gen_fractdquha2                    (rtx, rtx);
extern rtx        gen_fractudquha2                   (rtx, rtx);
extern rtx        gen_fractdauha2                    (rtx, rtx);
extern rtx        gen_fractudauha2                   (rtx, rtx);
extern rtx        gen_fracttauha2                    (rtx, rtx);
extern rtx        gen_fractutauha2                   (rtx, rtx);
extern rtx        gen_fractqiuha2                    (rtx, rtx);
extern rtx        gen_fracthiuha2                    (rtx, rtx);
extern rtx        gen_fractsiuha2                    (rtx, rtx);
extern rtx        gen_fractdiuha2                    (rtx, rtx);
extern rtx        gen_fractqqsq2                     (rtx, rtx);
extern rtx        gen_fractuqqsq2                    (rtx, rtx);
extern rtx        gen_fracthqsq2                     (rtx, rtx);
extern rtx        gen_fractuhqsq2                    (rtx, rtx);
extern rtx        gen_fracthasq2                     (rtx, rtx);
extern rtx        gen_fractuhasq2                    (rtx, rtx);
static inline rtx gen_fractsqsq2                     (rtx, rtx);
static inline rtx
gen_fractsqsq2(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b))
{
  return 0;
}
extern rtx        gen_fractusqsq2                    (rtx, rtx);
extern rtx        gen_fractsasq2                     (rtx, rtx);
extern rtx        gen_fractusasq2                    (rtx, rtx);
extern rtx        gen_fractdqsq2                     (rtx, rtx);
extern rtx        gen_fractudqsq2                    (rtx, rtx);
extern rtx        gen_fractdasq2                     (rtx, rtx);
extern rtx        gen_fractudasq2                    (rtx, rtx);
extern rtx        gen_fracttasq2                     (rtx, rtx);
extern rtx        gen_fractutasq2                    (rtx, rtx);
extern rtx        gen_fractqisq2                     (rtx, rtx);
extern rtx        gen_fracthisq2                     (rtx, rtx);
extern rtx        gen_fractsisq2                     (rtx, rtx);
extern rtx        gen_fractdisq2                     (rtx, rtx);
extern rtx        gen_fractqqusq2                    (rtx, rtx);
extern rtx        gen_fractuqqusq2                   (rtx, rtx);
extern rtx        gen_fracthqusq2                    (rtx, rtx);
extern rtx        gen_fractuhqusq2                   (rtx, rtx);
extern rtx        gen_fracthausq2                    (rtx, rtx);
extern rtx        gen_fractuhausq2                   (rtx, rtx);
extern rtx        gen_fractsqusq2                    (rtx, rtx);
static inline rtx gen_fractusqusq2                   (rtx, rtx);
static inline rtx
gen_fractusqusq2(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b))
{
  return 0;
}
extern rtx        gen_fractsausq2                    (rtx, rtx);
extern rtx        gen_fractusausq2                   (rtx, rtx);
extern rtx        gen_fractdqusq2                    (rtx, rtx);
extern rtx        gen_fractudqusq2                   (rtx, rtx);
extern rtx        gen_fractdausq2                    (rtx, rtx);
extern rtx        gen_fractudausq2                   (rtx, rtx);
extern rtx        gen_fracttausq2                    (rtx, rtx);
extern rtx        gen_fractutausq2                   (rtx, rtx);
extern rtx        gen_fractqiusq2                    (rtx, rtx);
extern rtx        gen_fracthiusq2                    (rtx, rtx);
extern rtx        gen_fractsiusq2                    (rtx, rtx);
extern rtx        gen_fractdiusq2                    (rtx, rtx);
extern rtx        gen_fractqqsa2                     (rtx, rtx);
extern rtx        gen_fractuqqsa2                    (rtx, rtx);
extern rtx        gen_fracthqsa2                     (rtx, rtx);
extern rtx        gen_fractuhqsa2                    (rtx, rtx);
extern rtx        gen_fracthasa2                     (rtx, rtx);
extern rtx        gen_fractuhasa2                    (rtx, rtx);
extern rtx        gen_fractsqsa2                     (rtx, rtx);
extern rtx        gen_fractusqsa2                    (rtx, rtx);
static inline rtx gen_fractsasa2                     (rtx, rtx);
static inline rtx
gen_fractsasa2(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b))
{
  return 0;
}
extern rtx        gen_fractusasa2                    (rtx, rtx);
extern rtx        gen_fractdqsa2                     (rtx, rtx);
extern rtx        gen_fractudqsa2                    (rtx, rtx);
extern rtx        gen_fractdasa2                     (rtx, rtx);
extern rtx        gen_fractudasa2                    (rtx, rtx);
extern rtx        gen_fracttasa2                     (rtx, rtx);
extern rtx        gen_fractutasa2                    (rtx, rtx);
extern rtx        gen_fractqisa2                     (rtx, rtx);
extern rtx        gen_fracthisa2                     (rtx, rtx);
extern rtx        gen_fractsisa2                     (rtx, rtx);
extern rtx        gen_fractdisa2                     (rtx, rtx);
extern rtx        gen_fractqqusa2                    (rtx, rtx);
extern rtx        gen_fractuqqusa2                   (rtx, rtx);
extern rtx        gen_fracthqusa2                    (rtx, rtx);
extern rtx        gen_fractuhqusa2                   (rtx, rtx);
extern rtx        gen_fracthausa2                    (rtx, rtx);
extern rtx        gen_fractuhausa2                   (rtx, rtx);
extern rtx        gen_fractsqusa2                    (rtx, rtx);
extern rtx        gen_fractusqusa2                   (rtx, rtx);
extern rtx        gen_fractsausa2                    (rtx, rtx);
static inline rtx gen_fractusausa2                   (rtx, rtx);
static inline rtx
gen_fractusausa2(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b))
{
  return 0;
}
extern rtx        gen_fractdqusa2                    (rtx, rtx);
extern rtx        gen_fractudqusa2                   (rtx, rtx);
extern rtx        gen_fractdausa2                    (rtx, rtx);
extern rtx        gen_fractudausa2                   (rtx, rtx);
extern rtx        gen_fracttausa2                    (rtx, rtx);
extern rtx        gen_fractutausa2                   (rtx, rtx);
extern rtx        gen_fractqiusa2                    (rtx, rtx);
extern rtx        gen_fracthiusa2                    (rtx, rtx);
extern rtx        gen_fractsiusa2                    (rtx, rtx);
extern rtx        gen_fractdiusa2                    (rtx, rtx);
extern rtx        gen_fractqqdq2                     (rtx, rtx);
extern rtx        gen_fractuqqdq2                    (rtx, rtx);
extern rtx        gen_fracthqdq2                     (rtx, rtx);
extern rtx        gen_fractuhqdq2                    (rtx, rtx);
extern rtx        gen_fracthadq2                     (rtx, rtx);
extern rtx        gen_fractuhadq2                    (rtx, rtx);
extern rtx        gen_fractsqdq2                     (rtx, rtx);
extern rtx        gen_fractusqdq2                    (rtx, rtx);
extern rtx        gen_fractsadq2                     (rtx, rtx);
extern rtx        gen_fractusadq2                    (rtx, rtx);
static inline rtx gen_fractdqdq2                     (rtx, rtx);
static inline rtx
gen_fractdqdq2(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b))
{
  return 0;
}
extern rtx        gen_fractudqdq2                    (rtx, rtx);
extern rtx        gen_fractdadq2                     (rtx, rtx);
extern rtx        gen_fractudadq2                    (rtx, rtx);
extern rtx        gen_fracttadq2                     (rtx, rtx);
extern rtx        gen_fractutadq2                    (rtx, rtx);
extern rtx        gen_fractqidq2                     (rtx, rtx);
extern rtx        gen_fracthidq2                     (rtx, rtx);
extern rtx        gen_fractsidq2                     (rtx, rtx);
extern rtx        gen_fractdidq2                     (rtx, rtx);
extern rtx        gen_fractqqudq2                    (rtx, rtx);
extern rtx        gen_fractuqqudq2                   (rtx, rtx);
extern rtx        gen_fracthqudq2                    (rtx, rtx);
extern rtx        gen_fractuhqudq2                   (rtx, rtx);
extern rtx        gen_fracthaudq2                    (rtx, rtx);
extern rtx        gen_fractuhaudq2                   (rtx, rtx);
extern rtx        gen_fractsqudq2                    (rtx, rtx);
extern rtx        gen_fractusqudq2                   (rtx, rtx);
extern rtx        gen_fractsaudq2                    (rtx, rtx);
extern rtx        gen_fractusaudq2                   (rtx, rtx);
extern rtx        gen_fractdqudq2                    (rtx, rtx);
static inline rtx gen_fractudqudq2                   (rtx, rtx);
static inline rtx
gen_fractudqudq2(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b))
{
  return 0;
}
extern rtx        gen_fractdaudq2                    (rtx, rtx);
extern rtx        gen_fractudaudq2                   (rtx, rtx);
extern rtx        gen_fracttaudq2                    (rtx, rtx);
extern rtx        gen_fractutaudq2                   (rtx, rtx);
extern rtx        gen_fractqiudq2                    (rtx, rtx);
extern rtx        gen_fracthiudq2                    (rtx, rtx);
extern rtx        gen_fractsiudq2                    (rtx, rtx);
extern rtx        gen_fractdiudq2                    (rtx, rtx);
extern rtx        gen_fractqqda2                     (rtx, rtx);
extern rtx        gen_fractuqqda2                    (rtx, rtx);
extern rtx        gen_fracthqda2                     (rtx, rtx);
extern rtx        gen_fractuhqda2                    (rtx, rtx);
extern rtx        gen_fracthada2                     (rtx, rtx);
extern rtx        gen_fractuhada2                    (rtx, rtx);
extern rtx        gen_fractsqda2                     (rtx, rtx);
extern rtx        gen_fractusqda2                    (rtx, rtx);
extern rtx        gen_fractsada2                     (rtx, rtx);
extern rtx        gen_fractusada2                    (rtx, rtx);
extern rtx        gen_fractdqda2                     (rtx, rtx);
extern rtx        gen_fractudqda2                    (rtx, rtx);
static inline rtx gen_fractdada2                     (rtx, rtx);
static inline rtx
gen_fractdada2(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b))
{
  return 0;
}
extern rtx        gen_fractudada2                    (rtx, rtx);
extern rtx        gen_fracttada2                     (rtx, rtx);
extern rtx        gen_fractutada2                    (rtx, rtx);
extern rtx        gen_fractqida2                     (rtx, rtx);
extern rtx        gen_fracthida2                     (rtx, rtx);
extern rtx        gen_fractsida2                     (rtx, rtx);
extern rtx        gen_fractdida2                     (rtx, rtx);
extern rtx        gen_fractqquda2                    (rtx, rtx);
extern rtx        gen_fractuqquda2                   (rtx, rtx);
extern rtx        gen_fracthquda2                    (rtx, rtx);
extern rtx        gen_fractuhquda2                   (rtx, rtx);
extern rtx        gen_fracthauda2                    (rtx, rtx);
extern rtx        gen_fractuhauda2                   (rtx, rtx);
extern rtx        gen_fractsquda2                    (rtx, rtx);
extern rtx        gen_fractusquda2                   (rtx, rtx);
extern rtx        gen_fractsauda2                    (rtx, rtx);
extern rtx        gen_fractusauda2                   (rtx, rtx);
extern rtx        gen_fractdquda2                    (rtx, rtx);
extern rtx        gen_fractudquda2                   (rtx, rtx);
extern rtx        gen_fractdauda2                    (rtx, rtx);
static inline rtx gen_fractudauda2                   (rtx, rtx);
static inline rtx
gen_fractudauda2(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b))
{
  return 0;
}
extern rtx        gen_fracttauda2                    (rtx, rtx);
extern rtx        gen_fractutauda2                   (rtx, rtx);
extern rtx        gen_fractqiuda2                    (rtx, rtx);
extern rtx        gen_fracthiuda2                    (rtx, rtx);
extern rtx        gen_fractsiuda2                    (rtx, rtx);
extern rtx        gen_fractdiuda2                    (rtx, rtx);
extern rtx        gen_fractqqta2                     (rtx, rtx);
extern rtx        gen_fractuqqta2                    (rtx, rtx);
extern rtx        gen_fracthqta2                     (rtx, rtx);
extern rtx        gen_fractuhqta2                    (rtx, rtx);
extern rtx        gen_fracthata2                     (rtx, rtx);
extern rtx        gen_fractuhata2                    (rtx, rtx);
extern rtx        gen_fractsqta2                     (rtx, rtx);
extern rtx        gen_fractusqta2                    (rtx, rtx);
extern rtx        gen_fractsata2                     (rtx, rtx);
extern rtx        gen_fractusata2                    (rtx, rtx);
extern rtx        gen_fractdqta2                     (rtx, rtx);
extern rtx        gen_fractudqta2                    (rtx, rtx);
extern rtx        gen_fractdata2                     (rtx, rtx);
extern rtx        gen_fractudata2                    (rtx, rtx);
static inline rtx gen_fracttata2                     (rtx, rtx);
static inline rtx
gen_fracttata2(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b))
{
  return 0;
}
extern rtx        gen_fractutata2                    (rtx, rtx);
extern rtx        gen_fractqita2                     (rtx, rtx);
extern rtx        gen_fracthita2                     (rtx, rtx);
extern rtx        gen_fractsita2                     (rtx, rtx);
extern rtx        gen_fractdita2                     (rtx, rtx);
extern rtx        gen_fractqquta2                    (rtx, rtx);
extern rtx        gen_fractuqquta2                   (rtx, rtx);
extern rtx        gen_fracthquta2                    (rtx, rtx);
extern rtx        gen_fractuhquta2                   (rtx, rtx);
extern rtx        gen_fracthauta2                    (rtx, rtx);
extern rtx        gen_fractuhauta2                   (rtx, rtx);
extern rtx        gen_fractsquta2                    (rtx, rtx);
extern rtx        gen_fractusquta2                   (rtx, rtx);
extern rtx        gen_fractsauta2                    (rtx, rtx);
extern rtx        gen_fractusauta2                   (rtx, rtx);
extern rtx        gen_fractdquta2                    (rtx, rtx);
extern rtx        gen_fractudquta2                   (rtx, rtx);
extern rtx        gen_fractdauta2                    (rtx, rtx);
extern rtx        gen_fractudauta2                   (rtx, rtx);
extern rtx        gen_fracttauta2                    (rtx, rtx);
static inline rtx gen_fractutauta2                   (rtx, rtx);
static inline rtx
gen_fractutauta2(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b))
{
  return 0;
}
extern rtx        gen_fractqiuta2                    (rtx, rtx);
extern rtx        gen_fracthiuta2                    (rtx, rtx);
extern rtx        gen_fractsiuta2                    (rtx, rtx);
extern rtx        gen_fractdiuta2                    (rtx, rtx);
extern rtx        gen_fractqqqi2                     (rtx, rtx);
extern rtx        gen_fractuqqqi2                    (rtx, rtx);
extern rtx        gen_fracthqqi2                     (rtx, rtx);
extern rtx        gen_fractuhqqi2                    (rtx, rtx);
extern rtx        gen_fracthaqi2                     (rtx, rtx);
extern rtx        gen_fractuhaqi2                    (rtx, rtx);
extern rtx        gen_fractsqqi2                     (rtx, rtx);
extern rtx        gen_fractusqqi2                    (rtx, rtx);
extern rtx        gen_fractsaqi2                     (rtx, rtx);
extern rtx        gen_fractusaqi2                    (rtx, rtx);
extern rtx        gen_fractdqqi2                     (rtx, rtx);
extern rtx        gen_fractudqqi2                    (rtx, rtx);
extern rtx        gen_fractdaqi2                     (rtx, rtx);
extern rtx        gen_fractudaqi2                    (rtx, rtx);
extern rtx        gen_fracttaqi2                     (rtx, rtx);
extern rtx        gen_fractutaqi2                    (rtx, rtx);
static inline rtx gen_fractqiqi2                     (rtx, rtx);
static inline rtx
gen_fractqiqi2(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b))
{
  return 0;
}
extern rtx        gen_fracthiqi2                     (rtx, rtx);
extern rtx        gen_fractsiqi2                     (rtx, rtx);
extern rtx        gen_fractdiqi2                     (rtx, rtx);
extern rtx        gen_fractqqhi2                     (rtx, rtx);
extern rtx        gen_fractuqqhi2                    (rtx, rtx);
extern rtx        gen_fracthqhi2                     (rtx, rtx);
extern rtx        gen_fractuhqhi2                    (rtx, rtx);
extern rtx        gen_fracthahi2                     (rtx, rtx);
extern rtx        gen_fractuhahi2                    (rtx, rtx);
extern rtx        gen_fractsqhi2                     (rtx, rtx);
extern rtx        gen_fractusqhi2                    (rtx, rtx);
extern rtx        gen_fractsahi2                     (rtx, rtx);
extern rtx        gen_fractusahi2                    (rtx, rtx);
extern rtx        gen_fractdqhi2                     (rtx, rtx);
extern rtx        gen_fractudqhi2                    (rtx, rtx);
extern rtx        gen_fractdahi2                     (rtx, rtx);
extern rtx        gen_fractudahi2                    (rtx, rtx);
extern rtx        gen_fracttahi2                     (rtx, rtx);
extern rtx        gen_fractutahi2                    (rtx, rtx);
extern rtx        gen_fractqihi2                     (rtx, rtx);
static inline rtx gen_fracthihi2                     (rtx, rtx);
static inline rtx
gen_fracthihi2(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b))
{
  return 0;
}
extern rtx        gen_fractsihi2                     (rtx, rtx);
extern rtx        gen_fractdihi2                     (rtx, rtx);
extern rtx        gen_fractqqsi2                     (rtx, rtx);
extern rtx        gen_fractuqqsi2                    (rtx, rtx);
extern rtx        gen_fracthqsi2                     (rtx, rtx);
extern rtx        gen_fractuhqsi2                    (rtx, rtx);
extern rtx        gen_fracthasi2                     (rtx, rtx);
extern rtx        gen_fractuhasi2                    (rtx, rtx);
extern rtx        gen_fractsqsi2                     (rtx, rtx);
extern rtx        gen_fractusqsi2                    (rtx, rtx);
extern rtx        gen_fractsasi2                     (rtx, rtx);
extern rtx        gen_fractusasi2                    (rtx, rtx);
extern rtx        gen_fractdqsi2                     (rtx, rtx);
extern rtx        gen_fractudqsi2                    (rtx, rtx);
extern rtx        gen_fractdasi2                     (rtx, rtx);
extern rtx        gen_fractudasi2                    (rtx, rtx);
extern rtx        gen_fracttasi2                     (rtx, rtx);
extern rtx        gen_fractutasi2                    (rtx, rtx);
extern rtx        gen_fractqisi2                     (rtx, rtx);
extern rtx        gen_fracthisi2                     (rtx, rtx);
static inline rtx gen_fractsisi2                     (rtx, rtx);
static inline rtx
gen_fractsisi2(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b))
{
  return 0;
}
extern rtx        gen_fractdisi2                     (rtx, rtx);
extern rtx        gen_fractqqdi2                     (rtx, rtx);
extern rtx        gen_fractuqqdi2                    (rtx, rtx);
extern rtx        gen_fracthqdi2                     (rtx, rtx);
extern rtx        gen_fractuhqdi2                    (rtx, rtx);
extern rtx        gen_fracthadi2                     (rtx, rtx);
extern rtx        gen_fractuhadi2                    (rtx, rtx);
extern rtx        gen_fractsqdi2                     (rtx, rtx);
extern rtx        gen_fractusqdi2                    (rtx, rtx);
extern rtx        gen_fractsadi2                     (rtx, rtx);
extern rtx        gen_fractusadi2                    (rtx, rtx);
extern rtx        gen_fractdqdi2                     (rtx, rtx);
extern rtx        gen_fractudqdi2                    (rtx, rtx);
extern rtx        gen_fractdadi2                     (rtx, rtx);
extern rtx        gen_fractudadi2                    (rtx, rtx);
extern rtx        gen_fracttadi2                     (rtx, rtx);
extern rtx        gen_fractutadi2                    (rtx, rtx);
extern rtx        gen_fractqidi2                     (rtx, rtx);
extern rtx        gen_fracthidi2                     (rtx, rtx);
extern rtx        gen_fractsidi2                     (rtx, rtx);
static inline rtx gen_fractdidi2                     (rtx, rtx);
static inline rtx
gen_fractdidi2(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b))
{
  return 0;
}
static inline rtx gen_fractunsqqqq2                  (rtx, rtx);
static inline rtx
gen_fractunsqqqq2(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b))
{
  return 0;
}
extern rtx        gen_fractunsuqqqq2                 (rtx, rtx);
extern rtx        gen_fractunshqqq2                  (rtx, rtx);
extern rtx        gen_fractunsuhqqq2                 (rtx, rtx);
extern rtx        gen_fractunshaqq2                  (rtx, rtx);
extern rtx        gen_fractunsuhaqq2                 (rtx, rtx);
extern rtx        gen_fractunssqqq2                  (rtx, rtx);
extern rtx        gen_fractunsusqqq2                 (rtx, rtx);
extern rtx        gen_fractunssaqq2                  (rtx, rtx);
extern rtx        gen_fractunsusaqq2                 (rtx, rtx);
extern rtx        gen_fractunsdqqq2                  (rtx, rtx);
extern rtx        gen_fractunsudqqq2                 (rtx, rtx);
extern rtx        gen_fractunsdaqq2                  (rtx, rtx);
extern rtx        gen_fractunsudaqq2                 (rtx, rtx);
extern rtx        gen_fractunstaqq2                  (rtx, rtx);
extern rtx        gen_fractunsutaqq2                 (rtx, rtx);
extern rtx        gen_fractunsqiqq2                  (rtx, rtx);
extern rtx        gen_fractunshiqq2                  (rtx, rtx);
extern rtx        gen_fractunssiqq2                  (rtx, rtx);
extern rtx        gen_fractunsdiqq2                  (rtx, rtx);
extern rtx        gen_fractunsqquqq2                 (rtx, rtx);
static inline rtx gen_fractunsuqquqq2                (rtx, rtx);
static inline rtx
gen_fractunsuqquqq2(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b))
{
  return 0;
}
extern rtx        gen_fractunshquqq2                 (rtx, rtx);
extern rtx        gen_fractunsuhquqq2                (rtx, rtx);
extern rtx        gen_fractunshauqq2                 (rtx, rtx);
extern rtx        gen_fractunsuhauqq2                (rtx, rtx);
extern rtx        gen_fractunssquqq2                 (rtx, rtx);
extern rtx        gen_fractunsusquqq2                (rtx, rtx);
extern rtx        gen_fractunssauqq2                 (rtx, rtx);
extern rtx        gen_fractunsusauqq2                (rtx, rtx);
extern rtx        gen_fractunsdquqq2                 (rtx, rtx);
extern rtx        gen_fractunsudquqq2                (rtx, rtx);
extern rtx        gen_fractunsdauqq2                 (rtx, rtx);
extern rtx        gen_fractunsudauqq2                (rtx, rtx);
extern rtx        gen_fractunstauqq2                 (rtx, rtx);
extern rtx        gen_fractunsutauqq2                (rtx, rtx);
extern rtx        gen_fractunsqiuqq2                 (rtx, rtx);
extern rtx        gen_fractunshiuqq2                 (rtx, rtx);
extern rtx        gen_fractunssiuqq2                 (rtx, rtx);
extern rtx        gen_fractunsdiuqq2                 (rtx, rtx);
extern rtx        gen_fractunsqqhq2                  (rtx, rtx);
extern rtx        gen_fractunsuqqhq2                 (rtx, rtx);
static inline rtx gen_fractunshqhq2                  (rtx, rtx);
static inline rtx
gen_fractunshqhq2(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b))
{
  return 0;
}
extern rtx        gen_fractunsuhqhq2                 (rtx, rtx);
extern rtx        gen_fractunshahq2                  (rtx, rtx);
extern rtx        gen_fractunsuhahq2                 (rtx, rtx);
extern rtx        gen_fractunssqhq2                  (rtx, rtx);
extern rtx        gen_fractunsusqhq2                 (rtx, rtx);
extern rtx        gen_fractunssahq2                  (rtx, rtx);
extern rtx        gen_fractunsusahq2                 (rtx, rtx);
extern rtx        gen_fractunsdqhq2                  (rtx, rtx);
extern rtx        gen_fractunsudqhq2                 (rtx, rtx);
extern rtx        gen_fractunsdahq2                  (rtx, rtx);
extern rtx        gen_fractunsudahq2                 (rtx, rtx);
extern rtx        gen_fractunstahq2                  (rtx, rtx);
extern rtx        gen_fractunsutahq2                 (rtx, rtx);
extern rtx        gen_fractunsqihq2                  (rtx, rtx);
extern rtx        gen_fractunshihq2                  (rtx, rtx);
extern rtx        gen_fractunssihq2                  (rtx, rtx);
extern rtx        gen_fractunsdihq2                  (rtx, rtx);
extern rtx        gen_fractunsqquhq2                 (rtx, rtx);
extern rtx        gen_fractunsuqquhq2                (rtx, rtx);
extern rtx        gen_fractunshquhq2                 (rtx, rtx);
static inline rtx gen_fractunsuhquhq2                (rtx, rtx);
static inline rtx
gen_fractunsuhquhq2(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b))
{
  return 0;
}
extern rtx        gen_fractunshauhq2                 (rtx, rtx);
extern rtx        gen_fractunsuhauhq2                (rtx, rtx);
extern rtx        gen_fractunssquhq2                 (rtx, rtx);
extern rtx        gen_fractunsusquhq2                (rtx, rtx);
extern rtx        gen_fractunssauhq2                 (rtx, rtx);
extern rtx        gen_fractunsusauhq2                (rtx, rtx);
extern rtx        gen_fractunsdquhq2                 (rtx, rtx);
extern rtx        gen_fractunsudquhq2                (rtx, rtx);
extern rtx        gen_fractunsdauhq2                 (rtx, rtx);
extern rtx        gen_fractunsudauhq2                (rtx, rtx);
extern rtx        gen_fractunstauhq2                 (rtx, rtx);
extern rtx        gen_fractunsutauhq2                (rtx, rtx);
extern rtx        gen_fractunsqiuhq2                 (rtx, rtx);
extern rtx        gen_fractunshiuhq2                 (rtx, rtx);
extern rtx        gen_fractunssiuhq2                 (rtx, rtx);
extern rtx        gen_fractunsdiuhq2                 (rtx, rtx);
extern rtx        gen_fractunsqqha2                  (rtx, rtx);
extern rtx        gen_fractunsuqqha2                 (rtx, rtx);
extern rtx        gen_fractunshqha2                  (rtx, rtx);
extern rtx        gen_fractunsuhqha2                 (rtx, rtx);
static inline rtx gen_fractunshaha2                  (rtx, rtx);
static inline rtx
gen_fractunshaha2(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b))
{
  return 0;
}
extern rtx        gen_fractunsuhaha2                 (rtx, rtx);
extern rtx        gen_fractunssqha2                  (rtx, rtx);
extern rtx        gen_fractunsusqha2                 (rtx, rtx);
extern rtx        gen_fractunssaha2                  (rtx, rtx);
extern rtx        gen_fractunsusaha2                 (rtx, rtx);
extern rtx        gen_fractunsdqha2                  (rtx, rtx);
extern rtx        gen_fractunsudqha2                 (rtx, rtx);
extern rtx        gen_fractunsdaha2                  (rtx, rtx);
extern rtx        gen_fractunsudaha2                 (rtx, rtx);
extern rtx        gen_fractunstaha2                  (rtx, rtx);
extern rtx        gen_fractunsutaha2                 (rtx, rtx);
extern rtx        gen_fractunsqiha2                  (rtx, rtx);
extern rtx        gen_fractunshiha2                  (rtx, rtx);
extern rtx        gen_fractunssiha2                  (rtx, rtx);
extern rtx        gen_fractunsdiha2                  (rtx, rtx);
extern rtx        gen_fractunsqquha2                 (rtx, rtx);
extern rtx        gen_fractunsuqquha2                (rtx, rtx);
extern rtx        gen_fractunshquha2                 (rtx, rtx);
extern rtx        gen_fractunsuhquha2                (rtx, rtx);
extern rtx        gen_fractunshauha2                 (rtx, rtx);
static inline rtx gen_fractunsuhauha2                (rtx, rtx);
static inline rtx
gen_fractunsuhauha2(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b))
{
  return 0;
}
extern rtx        gen_fractunssquha2                 (rtx, rtx);
extern rtx        gen_fractunsusquha2                (rtx, rtx);
extern rtx        gen_fractunssauha2                 (rtx, rtx);
extern rtx        gen_fractunsusauha2                (rtx, rtx);
extern rtx        gen_fractunsdquha2                 (rtx, rtx);
extern rtx        gen_fractunsudquha2                (rtx, rtx);
extern rtx        gen_fractunsdauha2                 (rtx, rtx);
extern rtx        gen_fractunsudauha2                (rtx, rtx);
extern rtx        gen_fractunstauha2                 (rtx, rtx);
extern rtx        gen_fractunsutauha2                (rtx, rtx);
extern rtx        gen_fractunsqiuha2                 (rtx, rtx);
extern rtx        gen_fractunshiuha2                 (rtx, rtx);
extern rtx        gen_fractunssiuha2                 (rtx, rtx);
extern rtx        gen_fractunsdiuha2                 (rtx, rtx);
extern rtx        gen_fractunsqqsq2                  (rtx, rtx);
extern rtx        gen_fractunsuqqsq2                 (rtx, rtx);
extern rtx        gen_fractunshqsq2                  (rtx, rtx);
extern rtx        gen_fractunsuhqsq2                 (rtx, rtx);
extern rtx        gen_fractunshasq2                  (rtx, rtx);
extern rtx        gen_fractunsuhasq2                 (rtx, rtx);
static inline rtx gen_fractunssqsq2                  (rtx, rtx);
static inline rtx
gen_fractunssqsq2(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b))
{
  return 0;
}
extern rtx        gen_fractunsusqsq2                 (rtx, rtx);
extern rtx        gen_fractunssasq2                  (rtx, rtx);
extern rtx        gen_fractunsusasq2                 (rtx, rtx);
extern rtx        gen_fractunsdqsq2                  (rtx, rtx);
extern rtx        gen_fractunsudqsq2                 (rtx, rtx);
extern rtx        gen_fractunsdasq2                  (rtx, rtx);
extern rtx        gen_fractunsudasq2                 (rtx, rtx);
extern rtx        gen_fractunstasq2                  (rtx, rtx);
extern rtx        gen_fractunsutasq2                 (rtx, rtx);
extern rtx        gen_fractunsqisq2                  (rtx, rtx);
extern rtx        gen_fractunshisq2                  (rtx, rtx);
extern rtx        gen_fractunssisq2                  (rtx, rtx);
extern rtx        gen_fractunsdisq2                  (rtx, rtx);
extern rtx        gen_fractunsqqusq2                 (rtx, rtx);
extern rtx        gen_fractunsuqqusq2                (rtx, rtx);
extern rtx        gen_fractunshqusq2                 (rtx, rtx);
extern rtx        gen_fractunsuhqusq2                (rtx, rtx);
extern rtx        gen_fractunshausq2                 (rtx, rtx);
extern rtx        gen_fractunsuhausq2                (rtx, rtx);
extern rtx        gen_fractunssqusq2                 (rtx, rtx);
static inline rtx gen_fractunsusqusq2                (rtx, rtx);
static inline rtx
gen_fractunsusqusq2(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b))
{
  return 0;
}
extern rtx        gen_fractunssausq2                 (rtx, rtx);
extern rtx        gen_fractunsusausq2                (rtx, rtx);
extern rtx        gen_fractunsdqusq2                 (rtx, rtx);
extern rtx        gen_fractunsudqusq2                (rtx, rtx);
extern rtx        gen_fractunsdausq2                 (rtx, rtx);
extern rtx        gen_fractunsudausq2                (rtx, rtx);
extern rtx        gen_fractunstausq2                 (rtx, rtx);
extern rtx        gen_fractunsutausq2                (rtx, rtx);
extern rtx        gen_fractunsqiusq2                 (rtx, rtx);
extern rtx        gen_fractunshiusq2                 (rtx, rtx);
extern rtx        gen_fractunssiusq2                 (rtx, rtx);
extern rtx        gen_fractunsdiusq2                 (rtx, rtx);
extern rtx        gen_fractunsqqsa2                  (rtx, rtx);
extern rtx        gen_fractunsuqqsa2                 (rtx, rtx);
extern rtx        gen_fractunshqsa2                  (rtx, rtx);
extern rtx        gen_fractunsuhqsa2                 (rtx, rtx);
extern rtx        gen_fractunshasa2                  (rtx, rtx);
extern rtx        gen_fractunsuhasa2                 (rtx, rtx);
extern rtx        gen_fractunssqsa2                  (rtx, rtx);
extern rtx        gen_fractunsusqsa2                 (rtx, rtx);
static inline rtx gen_fractunssasa2                  (rtx, rtx);
static inline rtx
gen_fractunssasa2(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b))
{
  return 0;
}
extern rtx        gen_fractunsusasa2                 (rtx, rtx);
extern rtx        gen_fractunsdqsa2                  (rtx, rtx);
extern rtx        gen_fractunsudqsa2                 (rtx, rtx);
extern rtx        gen_fractunsdasa2                  (rtx, rtx);
extern rtx        gen_fractunsudasa2                 (rtx, rtx);
extern rtx        gen_fractunstasa2                  (rtx, rtx);
extern rtx        gen_fractunsutasa2                 (rtx, rtx);
extern rtx        gen_fractunsqisa2                  (rtx, rtx);
extern rtx        gen_fractunshisa2                  (rtx, rtx);
extern rtx        gen_fractunssisa2                  (rtx, rtx);
extern rtx        gen_fractunsdisa2                  (rtx, rtx);
extern rtx        gen_fractunsqqusa2                 (rtx, rtx);
extern rtx        gen_fractunsuqqusa2                (rtx, rtx);
extern rtx        gen_fractunshqusa2                 (rtx, rtx);
extern rtx        gen_fractunsuhqusa2                (rtx, rtx);
extern rtx        gen_fractunshausa2                 (rtx, rtx);
extern rtx        gen_fractunsuhausa2                (rtx, rtx);
extern rtx        gen_fractunssqusa2                 (rtx, rtx);
extern rtx        gen_fractunsusqusa2                (rtx, rtx);
extern rtx        gen_fractunssausa2                 (rtx, rtx);
static inline rtx gen_fractunsusausa2                (rtx, rtx);
static inline rtx
gen_fractunsusausa2(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b))
{
  return 0;
}
extern rtx        gen_fractunsdqusa2                 (rtx, rtx);
extern rtx        gen_fractunsudqusa2                (rtx, rtx);
extern rtx        gen_fractunsdausa2                 (rtx, rtx);
extern rtx        gen_fractunsudausa2                (rtx, rtx);
extern rtx        gen_fractunstausa2                 (rtx, rtx);
extern rtx        gen_fractunsutausa2                (rtx, rtx);
extern rtx        gen_fractunsqiusa2                 (rtx, rtx);
extern rtx        gen_fractunshiusa2                 (rtx, rtx);
extern rtx        gen_fractunssiusa2                 (rtx, rtx);
extern rtx        gen_fractunsdiusa2                 (rtx, rtx);
extern rtx        gen_fractunsqqdq2                  (rtx, rtx);
extern rtx        gen_fractunsuqqdq2                 (rtx, rtx);
extern rtx        gen_fractunshqdq2                  (rtx, rtx);
extern rtx        gen_fractunsuhqdq2                 (rtx, rtx);
extern rtx        gen_fractunshadq2                  (rtx, rtx);
extern rtx        gen_fractunsuhadq2                 (rtx, rtx);
extern rtx        gen_fractunssqdq2                  (rtx, rtx);
extern rtx        gen_fractunsusqdq2                 (rtx, rtx);
extern rtx        gen_fractunssadq2                  (rtx, rtx);
extern rtx        gen_fractunsusadq2                 (rtx, rtx);
static inline rtx gen_fractunsdqdq2                  (rtx, rtx);
static inline rtx
gen_fractunsdqdq2(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b))
{
  return 0;
}
extern rtx        gen_fractunsudqdq2                 (rtx, rtx);
extern rtx        gen_fractunsdadq2                  (rtx, rtx);
extern rtx        gen_fractunsudadq2                 (rtx, rtx);
extern rtx        gen_fractunstadq2                  (rtx, rtx);
extern rtx        gen_fractunsutadq2                 (rtx, rtx);
extern rtx        gen_fractunsqidq2                  (rtx, rtx);
extern rtx        gen_fractunshidq2                  (rtx, rtx);
extern rtx        gen_fractunssidq2                  (rtx, rtx);
extern rtx        gen_fractunsdidq2                  (rtx, rtx);
extern rtx        gen_fractunsqqudq2                 (rtx, rtx);
extern rtx        gen_fractunsuqqudq2                (rtx, rtx);
extern rtx        gen_fractunshqudq2                 (rtx, rtx);
extern rtx        gen_fractunsuhqudq2                (rtx, rtx);
extern rtx        gen_fractunshaudq2                 (rtx, rtx);
extern rtx        gen_fractunsuhaudq2                (rtx, rtx);
extern rtx        gen_fractunssqudq2                 (rtx, rtx);
extern rtx        gen_fractunsusqudq2                (rtx, rtx);
extern rtx        gen_fractunssaudq2                 (rtx, rtx);
extern rtx        gen_fractunsusaudq2                (rtx, rtx);
extern rtx        gen_fractunsdqudq2                 (rtx, rtx);
static inline rtx gen_fractunsudqudq2                (rtx, rtx);
static inline rtx
gen_fractunsudqudq2(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b))
{
  return 0;
}
extern rtx        gen_fractunsdaudq2                 (rtx, rtx);
extern rtx        gen_fractunsudaudq2                (rtx, rtx);
extern rtx        gen_fractunstaudq2                 (rtx, rtx);
extern rtx        gen_fractunsutaudq2                (rtx, rtx);
extern rtx        gen_fractunsqiudq2                 (rtx, rtx);
extern rtx        gen_fractunshiudq2                 (rtx, rtx);
extern rtx        gen_fractunssiudq2                 (rtx, rtx);
extern rtx        gen_fractunsdiudq2                 (rtx, rtx);
extern rtx        gen_fractunsqqda2                  (rtx, rtx);
extern rtx        gen_fractunsuqqda2                 (rtx, rtx);
extern rtx        gen_fractunshqda2                  (rtx, rtx);
extern rtx        gen_fractunsuhqda2                 (rtx, rtx);
extern rtx        gen_fractunshada2                  (rtx, rtx);
extern rtx        gen_fractunsuhada2                 (rtx, rtx);
extern rtx        gen_fractunssqda2                  (rtx, rtx);
extern rtx        gen_fractunsusqda2                 (rtx, rtx);
extern rtx        gen_fractunssada2                  (rtx, rtx);
extern rtx        gen_fractunsusada2                 (rtx, rtx);
extern rtx        gen_fractunsdqda2                  (rtx, rtx);
extern rtx        gen_fractunsudqda2                 (rtx, rtx);
static inline rtx gen_fractunsdada2                  (rtx, rtx);
static inline rtx
gen_fractunsdada2(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b))
{
  return 0;
}
extern rtx        gen_fractunsudada2                 (rtx, rtx);
extern rtx        gen_fractunstada2                  (rtx, rtx);
extern rtx        gen_fractunsutada2                 (rtx, rtx);
extern rtx        gen_fractunsqida2                  (rtx, rtx);
extern rtx        gen_fractunshida2                  (rtx, rtx);
extern rtx        gen_fractunssida2                  (rtx, rtx);
extern rtx        gen_fractunsdida2                  (rtx, rtx);
extern rtx        gen_fractunsqquda2                 (rtx, rtx);
extern rtx        gen_fractunsuqquda2                (rtx, rtx);
extern rtx        gen_fractunshquda2                 (rtx, rtx);
extern rtx        gen_fractunsuhquda2                (rtx, rtx);
extern rtx        gen_fractunshauda2                 (rtx, rtx);
extern rtx        gen_fractunsuhauda2                (rtx, rtx);
extern rtx        gen_fractunssquda2                 (rtx, rtx);
extern rtx        gen_fractunsusquda2                (rtx, rtx);
extern rtx        gen_fractunssauda2                 (rtx, rtx);
extern rtx        gen_fractunsusauda2                (rtx, rtx);
extern rtx        gen_fractunsdquda2                 (rtx, rtx);
extern rtx        gen_fractunsudquda2                (rtx, rtx);
extern rtx        gen_fractunsdauda2                 (rtx, rtx);
static inline rtx gen_fractunsudauda2                (rtx, rtx);
static inline rtx
gen_fractunsudauda2(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b))
{
  return 0;
}
extern rtx        gen_fractunstauda2                 (rtx, rtx);
extern rtx        gen_fractunsutauda2                (rtx, rtx);
extern rtx        gen_fractunsqiuda2                 (rtx, rtx);
extern rtx        gen_fractunshiuda2                 (rtx, rtx);
extern rtx        gen_fractunssiuda2                 (rtx, rtx);
extern rtx        gen_fractunsdiuda2                 (rtx, rtx);
extern rtx        gen_fractunsqqta2                  (rtx, rtx);
extern rtx        gen_fractunsuqqta2                 (rtx, rtx);
extern rtx        gen_fractunshqta2                  (rtx, rtx);
extern rtx        gen_fractunsuhqta2                 (rtx, rtx);
extern rtx        gen_fractunshata2                  (rtx, rtx);
extern rtx        gen_fractunsuhata2                 (rtx, rtx);
extern rtx        gen_fractunssqta2                  (rtx, rtx);
extern rtx        gen_fractunsusqta2                 (rtx, rtx);
extern rtx        gen_fractunssata2                  (rtx, rtx);
extern rtx        gen_fractunsusata2                 (rtx, rtx);
extern rtx        gen_fractunsdqta2                  (rtx, rtx);
extern rtx        gen_fractunsudqta2                 (rtx, rtx);
extern rtx        gen_fractunsdata2                  (rtx, rtx);
extern rtx        gen_fractunsudata2                 (rtx, rtx);
static inline rtx gen_fractunstata2                  (rtx, rtx);
static inline rtx
gen_fractunstata2(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b))
{
  return 0;
}
extern rtx        gen_fractunsutata2                 (rtx, rtx);
extern rtx        gen_fractunsqita2                  (rtx, rtx);
extern rtx        gen_fractunshita2                  (rtx, rtx);
extern rtx        gen_fractunssita2                  (rtx, rtx);
extern rtx        gen_fractunsdita2                  (rtx, rtx);
extern rtx        gen_fractunsqquta2                 (rtx, rtx);
extern rtx        gen_fractunsuqquta2                (rtx, rtx);
extern rtx        gen_fractunshquta2                 (rtx, rtx);
extern rtx        gen_fractunsuhquta2                (rtx, rtx);
extern rtx        gen_fractunshauta2                 (rtx, rtx);
extern rtx        gen_fractunsuhauta2                (rtx, rtx);
extern rtx        gen_fractunssquta2                 (rtx, rtx);
extern rtx        gen_fractunsusquta2                (rtx, rtx);
extern rtx        gen_fractunssauta2                 (rtx, rtx);
extern rtx        gen_fractunsusauta2                (rtx, rtx);
extern rtx        gen_fractunsdquta2                 (rtx, rtx);
extern rtx        gen_fractunsudquta2                (rtx, rtx);
extern rtx        gen_fractunsdauta2                 (rtx, rtx);
extern rtx        gen_fractunsudauta2                (rtx, rtx);
extern rtx        gen_fractunstauta2                 (rtx, rtx);
static inline rtx gen_fractunsutauta2                (rtx, rtx);
static inline rtx
gen_fractunsutauta2(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b))
{
  return 0;
}
extern rtx        gen_fractunsqiuta2                 (rtx, rtx);
extern rtx        gen_fractunshiuta2                 (rtx, rtx);
extern rtx        gen_fractunssiuta2                 (rtx, rtx);
extern rtx        gen_fractunsdiuta2                 (rtx, rtx);
extern rtx        gen_fractunsqqqi2                  (rtx, rtx);
extern rtx        gen_fractunsuqqqi2                 (rtx, rtx);
extern rtx        gen_fractunshqqi2                  (rtx, rtx);
extern rtx        gen_fractunsuhqqi2                 (rtx, rtx);
extern rtx        gen_fractunshaqi2                  (rtx, rtx);
extern rtx        gen_fractunsuhaqi2                 (rtx, rtx);
extern rtx        gen_fractunssqqi2                  (rtx, rtx);
extern rtx        gen_fractunsusqqi2                 (rtx, rtx);
extern rtx        gen_fractunssaqi2                  (rtx, rtx);
extern rtx        gen_fractunsusaqi2                 (rtx, rtx);
extern rtx        gen_fractunsdqqi2                  (rtx, rtx);
extern rtx        gen_fractunsudqqi2                 (rtx, rtx);
extern rtx        gen_fractunsdaqi2                  (rtx, rtx);
extern rtx        gen_fractunsudaqi2                 (rtx, rtx);
extern rtx        gen_fractunstaqi2                  (rtx, rtx);
extern rtx        gen_fractunsutaqi2                 (rtx, rtx);
static inline rtx gen_fractunsqiqi2                  (rtx, rtx);
static inline rtx
gen_fractunsqiqi2(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b))
{
  return 0;
}
extern rtx        gen_fractunshiqi2                  (rtx, rtx);
extern rtx        gen_fractunssiqi2                  (rtx, rtx);
extern rtx        gen_fractunsdiqi2                  (rtx, rtx);
extern rtx        gen_fractunsqqhi2                  (rtx, rtx);
extern rtx        gen_fractunsuqqhi2                 (rtx, rtx);
extern rtx        gen_fractunshqhi2                  (rtx, rtx);
extern rtx        gen_fractunsuhqhi2                 (rtx, rtx);
extern rtx        gen_fractunshahi2                  (rtx, rtx);
extern rtx        gen_fractunsuhahi2                 (rtx, rtx);
extern rtx        gen_fractunssqhi2                  (rtx, rtx);
extern rtx        gen_fractunsusqhi2                 (rtx, rtx);
extern rtx        gen_fractunssahi2                  (rtx, rtx);
extern rtx        gen_fractunsusahi2                 (rtx, rtx);
extern rtx        gen_fractunsdqhi2                  (rtx, rtx);
extern rtx        gen_fractunsudqhi2                 (rtx, rtx);
extern rtx        gen_fractunsdahi2                  (rtx, rtx);
extern rtx        gen_fractunsudahi2                 (rtx, rtx);
extern rtx        gen_fractunstahi2                  (rtx, rtx);
extern rtx        gen_fractunsutahi2                 (rtx, rtx);
extern rtx        gen_fractunsqihi2                  (rtx, rtx);
static inline rtx gen_fractunshihi2                  (rtx, rtx);
static inline rtx
gen_fractunshihi2(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b))
{
  return 0;
}
extern rtx        gen_fractunssihi2                  (rtx, rtx);
extern rtx        gen_fractunsdihi2                  (rtx, rtx);
extern rtx        gen_fractunsqqsi2                  (rtx, rtx);
extern rtx        gen_fractunsuqqsi2                 (rtx, rtx);
extern rtx        gen_fractunshqsi2                  (rtx, rtx);
extern rtx        gen_fractunsuhqsi2                 (rtx, rtx);
extern rtx        gen_fractunshasi2                  (rtx, rtx);
extern rtx        gen_fractunsuhasi2                 (rtx, rtx);
extern rtx        gen_fractunssqsi2                  (rtx, rtx);
extern rtx        gen_fractunsusqsi2                 (rtx, rtx);
extern rtx        gen_fractunssasi2                  (rtx, rtx);
extern rtx        gen_fractunsusasi2                 (rtx, rtx);
extern rtx        gen_fractunsdqsi2                  (rtx, rtx);
extern rtx        gen_fractunsudqsi2                 (rtx, rtx);
extern rtx        gen_fractunsdasi2                  (rtx, rtx);
extern rtx        gen_fractunsudasi2                 (rtx, rtx);
extern rtx        gen_fractunstasi2                  (rtx, rtx);
extern rtx        gen_fractunsutasi2                 (rtx, rtx);
extern rtx        gen_fractunsqisi2                  (rtx, rtx);
extern rtx        gen_fractunshisi2                  (rtx, rtx);
static inline rtx gen_fractunssisi2                  (rtx, rtx);
static inline rtx
gen_fractunssisi2(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b))
{
  return 0;
}
extern rtx        gen_fractunsdisi2                  (rtx, rtx);
extern rtx        gen_fractunsqqdi2                  (rtx, rtx);
extern rtx        gen_fractunsuqqdi2                 (rtx, rtx);
extern rtx        gen_fractunshqdi2                  (rtx, rtx);
extern rtx        gen_fractunsuhqdi2                 (rtx, rtx);
extern rtx        gen_fractunshadi2                  (rtx, rtx);
extern rtx        gen_fractunsuhadi2                 (rtx, rtx);
extern rtx        gen_fractunssqdi2                  (rtx, rtx);
extern rtx        gen_fractunsusqdi2                 (rtx, rtx);
extern rtx        gen_fractunssadi2                  (rtx, rtx);
extern rtx        gen_fractunsusadi2                 (rtx, rtx);
extern rtx        gen_fractunsdqdi2                  (rtx, rtx);
extern rtx        gen_fractunsudqdi2                 (rtx, rtx);
extern rtx        gen_fractunsdadi2                  (rtx, rtx);
extern rtx        gen_fractunsudadi2                 (rtx, rtx);
extern rtx        gen_fractunstadi2                  (rtx, rtx);
extern rtx        gen_fractunsutadi2                 (rtx, rtx);
extern rtx        gen_fractunsqidi2                  (rtx, rtx);
extern rtx        gen_fractunshidi2                  (rtx, rtx);
extern rtx        gen_fractunssidi2                  (rtx, rtx);
static inline rtx gen_fractunsdidi2                  (rtx, rtx);
static inline rtx
gen_fractunsdidi2(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b))
{
  return 0;
}
extern rtx        gen_ssaddqq3                       (rtx, rtx, rtx);
extern rtx        gen_sssubqq3                       (rtx, rtx, rtx);
extern rtx        gen_ssaddhq3                       (rtx, rtx, rtx);
extern rtx        gen_sssubhq3                       (rtx, rtx, rtx);
extern rtx        gen_ssaddha3                       (rtx, rtx, rtx);
extern rtx        gen_sssubha3                       (rtx, rtx, rtx);
extern rtx        gen_ssaddsa3                       (rtx, rtx, rtx);
extern rtx        gen_sssubsa3                       (rtx, rtx, rtx);
extern rtx        gen_ssaddsq3                       (rtx, rtx, rtx);
extern rtx        gen_sssubsq3                       (rtx, rtx, rtx);
extern rtx        gen_usadduqq3                      (rtx, rtx, rtx);
extern rtx        gen_ussubuqq3                      (rtx, rtx, rtx);
extern rtx        gen_usadduhq3                      (rtx, rtx, rtx);
extern rtx        gen_ussubuhq3                      (rtx, rtx, rtx);
extern rtx        gen_usadduha3                      (rtx, rtx, rtx);
extern rtx        gen_ussubuha3                      (rtx, rtx, rtx);
extern rtx        gen_usaddusa3                      (rtx, rtx, rtx);
extern rtx        gen_ussubusa3                      (rtx, rtx, rtx);
extern rtx        gen_usaddusq3                      (rtx, rtx, rtx);
extern rtx        gen_ussubusq3                      (rtx, rtx, rtx);
extern rtx        gen_ssnegqq2                       (rtx, rtx);
extern rtx        gen_ssabsqq2                       (rtx, rtx);
extern rtx        gen_mulqq3_enh                     (rtx, rtx, rtx);
extern rtx        gen_muluqq3_enh                    (rtx, rtx, rtx);
extern rtx        gen_roundqq3_const                 (rtx, rtx, rtx);
extern rtx        gen_roundhq3_const                 (rtx, rtx, rtx);
extern rtx        gen_roundha3_const                 (rtx, rtx, rtx);
extern rtx        gen_roundsa3_const                 (rtx, rtx, rtx);
extern rtx        gen_roundsq3_const                 (rtx, rtx, rtx);
extern rtx        gen_rounduqq3_const                (rtx, rtx, rtx);
extern rtx        gen_rounduhq3_const                (rtx, rtx, rtx);
extern rtx        gen_rounduha3_const                (rtx, rtx, rtx);
extern rtx        gen_roundusa3_const                (rtx, rtx, rtx);
extern rtx        gen_roundusq3_const                (rtx, rtx, rtx);
extern rtx        gen_adddi3_insn                    (void);
extern rtx        gen_adddq3_insn                    (void);
extern rtx        gen_addudq3_insn                   (void);
extern rtx        gen_addda3_insn                    (void);
extern rtx        gen_adduda3_insn                   (void);
extern rtx        gen_addta3_insn                    (void);
extern rtx        gen_adduta3_insn                   (void);
extern rtx        gen_adddi3_const8_insn             (void);
extern rtx        gen_adddi3_const_insn              (rtx);
extern rtx        gen_adddq3_const_insn              (rtx);
extern rtx        gen_addudq3_const_insn             (rtx);
extern rtx        gen_addda3_const_insn              (rtx);
extern rtx        gen_adduda3_const_insn             (rtx);
extern rtx        gen_addta3_const_insn              (rtx);
extern rtx        gen_adduta3_const_insn             (rtx);
extern rtx        gen_subdi3_insn                    (void);
extern rtx        gen_subdq3_insn                    (void);
extern rtx        gen_subudq3_insn                   (void);
extern rtx        gen_subda3_insn                    (void);
extern rtx        gen_subuda3_insn                   (void);
extern rtx        gen_subta3_insn                    (void);
extern rtx        gen_subuta3_insn                   (void);
extern rtx        gen_subdi3_const_insn              (rtx);
extern rtx        gen_subdq3_const_insn              (rtx);
extern rtx        gen_subudq3_const_insn             (rtx);
extern rtx        gen_subda3_const_insn              (rtx);
extern rtx        gen_subuda3_const_insn             (rtx);
extern rtx        gen_subta3_const_insn              (rtx);
extern rtx        gen_subuta3_const_insn             (rtx);
extern rtx        gen_ssadddq3_insn                  (void);
extern rtx        gen_sssubdq3_insn                  (void);
extern rtx        gen_ssaddda3_insn                  (void);
extern rtx        gen_sssubda3_insn                  (void);
extern rtx        gen_ssaddta3_insn                  (void);
extern rtx        gen_sssubta3_insn                  (void);
extern rtx        gen_ssadddq3_const_insn            (rtx);
extern rtx        gen_sssubdq3_const_insn            (rtx);
extern rtx        gen_ssaddda3_const_insn            (rtx);
extern rtx        gen_sssubda3_const_insn            (rtx);
extern rtx        gen_ssaddta3_const_insn            (rtx);
extern rtx        gen_sssubta3_const_insn            (rtx);
extern rtx        gen_usaddudq3_insn                 (void);
extern rtx        gen_ussubudq3_insn                 (void);
extern rtx        gen_usadduda3_insn                 (void);
extern rtx        gen_ussubuda3_insn                 (void);
extern rtx        gen_usadduta3_insn                 (void);
extern rtx        gen_ussubuta3_insn                 (void);
extern rtx        gen_usaddudq3_const_insn           (rtx);
extern rtx        gen_ussubudq3_const_insn           (rtx);
extern rtx        gen_usadduda3_const_insn           (rtx);
extern rtx        gen_ussubuda3_const_insn           (rtx);
extern rtx        gen_usadduta3_const_insn           (rtx);
extern rtx        gen_ussubuta3_const_insn           (rtx);
extern rtx        gen_negdi2_insn                    (void);
extern rtx        gen_compare_di2                    (void);
extern rtx        gen_compare_dq2                    (void);
extern rtx        gen_compare_udq2                   (void);
extern rtx        gen_compare_da2                    (void);
extern rtx        gen_compare_uda2                   (void);
extern rtx        gen_compare_ta2                    (void);
extern rtx        gen_compare_uta2                   (void);
extern rtx        gen_compare_const8_di2             (void);
extern rtx        gen_compare_const_di2              (rtx);
extern rtx        gen_compare_const_dq2              (rtx);
extern rtx        gen_compare_const_udq2             (rtx);
extern rtx        gen_compare_const_da2              (rtx);
extern rtx        gen_compare_const_uda2             (rtx);
extern rtx        gen_compare_const_ta2              (rtx);
extern rtx        gen_compare_const_uta2             (rtx);
extern rtx        gen_ashldi3_insn                   (void);
extern rtx        gen_ashrdi3_insn                   (void);
extern rtx        gen_lshrdi3_insn                   (void);
extern rtx        gen_rotldi3_insn                   (void);
extern rtx        gen_ashldq3_insn                   (void);
extern rtx        gen_ashrdq3_insn                   (void);
extern rtx        gen_lshrdq3_insn                   (void);
extern rtx        gen_rotldq3_insn                   (void);
extern rtx        gen_ashludq3_insn                  (void);
extern rtx        gen_ashrudq3_insn                  (void);
extern rtx        gen_lshrudq3_insn                  (void);
extern rtx        gen_rotludq3_insn                  (void);
extern rtx        gen_ashlda3_insn                   (void);
extern rtx        gen_ashrda3_insn                   (void);
extern rtx        gen_lshrda3_insn                   (void);
extern rtx        gen_rotlda3_insn                   (void);
extern rtx        gen_ashluda3_insn                  (void);
extern rtx        gen_ashruda3_insn                  (void);
extern rtx        gen_lshruda3_insn                  (void);
extern rtx        gen_rotluda3_insn                  (void);
extern rtx        gen_ashlta3_insn                   (void);
extern rtx        gen_ashrta3_insn                   (void);
extern rtx        gen_lshrta3_insn                   (void);
extern rtx        gen_rotlta3_insn                   (void);
extern rtx        gen_ashluta3_insn                  (void);
extern rtx        gen_ashruta3_insn                  (void);
extern rtx        gen_lshruta3_insn                  (void);
extern rtx        gen_rotluta3_insn                  (void);
extern rtx        gen_mulsidi3_insn                  (void);
extern rtx        gen_umulsidi3_insn                 (void);
extern rtx        gen_nonlocal_goto_receiver         (void);
extern rtx        gen_nonlocal_goto                  (rtx, rtx, rtx, rtx);
extern rtx        gen_pushcqi1                       (rtx);
extern rtx        gen_pushhi1                        (rtx);
extern rtx        gen_pushchi1                       (rtx);
extern rtx        gen_pushha1                        (rtx);
extern rtx        gen_pushuha1                       (rtx);
extern rtx        gen_pushhq1                        (rtx);
extern rtx        gen_pushuhq1                       (rtx);
extern rtx        gen_pushsi1                        (rtx);
extern rtx        gen_pushcsi1                       (rtx);
extern rtx        gen_pushsa1                        (rtx);
extern rtx        gen_pushusa1                       (rtx);
extern rtx        gen_pushsq1                        (rtx);
extern rtx        gen_pushusq1                       (rtx);
extern rtx        gen_pushdi1                        (rtx);
extern rtx        gen_pushcdi1                       (rtx);
extern rtx        gen_pushda1                        (rtx);
extern rtx        gen_pushuda1                       (rtx);
extern rtx        gen_pushdq1                        (rtx);
extern rtx        gen_pushudq1                       (rtx);
extern rtx        gen_pushta1                        (rtx);
extern rtx        gen_pushuta1                       (rtx);
extern rtx        gen_pushsf1                        (rtx);
extern rtx        gen_pushsc1                        (rtx);
extern rtx        gen_pushpsi1                       (rtx);
extern rtx        gen_loadqi_libgcc                  (rtx, rtx);
extern rtx        gen_loadqq_libgcc                  (rtx, rtx);
extern rtx        gen_loaduqq_libgcc                 (rtx, rtx);
extern rtx        gen_loadhi_libgcc                  (rtx, rtx);
extern rtx        gen_loadhq_libgcc                  (rtx, rtx);
extern rtx        gen_loaduhq_libgcc                 (rtx, rtx);
extern rtx        gen_loadha_libgcc                  (rtx, rtx);
extern rtx        gen_loaduha_libgcc                 (rtx, rtx);
extern rtx        gen_loadsi_libgcc                  (rtx, rtx);
extern rtx        gen_loadsq_libgcc                  (rtx, rtx);
extern rtx        gen_loadusq_libgcc                 (rtx, rtx);
extern rtx        gen_loadsa_libgcc                  (rtx, rtx);
extern rtx        gen_loadusa_libgcc                 (rtx, rtx);
extern rtx        gen_loadsf_libgcc                  (rtx, rtx);
extern rtx        gen_loadpsi_libgcc                 (rtx, rtx);
extern rtx        gen_movqi                          (rtx, rtx);
extern rtx        gen_movqq                          (rtx, rtx);
extern rtx        gen_movuqq                         (rtx, rtx);
extern rtx        gen_movhi                          (rtx, rtx);
extern rtx        gen_movhq                          (rtx, rtx);
extern rtx        gen_movuhq                         (rtx, rtx);
extern rtx        gen_movha                          (rtx, rtx);
extern rtx        gen_movuha                         (rtx, rtx);
extern rtx        gen_movsi                          (rtx, rtx);
extern rtx        gen_movsq                          (rtx, rtx);
extern rtx        gen_movusq                         (rtx, rtx);
extern rtx        gen_movsa                          (rtx, rtx);
extern rtx        gen_movusa                         (rtx, rtx);
extern rtx        gen_movsf                          (rtx, rtx);
extern rtx        gen_movpsi                         (rtx, rtx);
extern rtx        gen_movmemhi                       (rtx, rtx, rtx, rtx);
extern rtx        gen_setmemhi                       (rtx, rtx, rtx, rtx);
extern rtx        gen_strlenhi                       (rtx, rtx, rtx, rtx);
extern rtx        gen_addhi3                         (rtx, rtx, rtx);
extern rtx        gen_addhq3                         (rtx, rtx, rtx);
extern rtx        gen_adduhq3                        (rtx, rtx, rtx);
extern rtx        gen_addha3                         (rtx, rtx, rtx);
extern rtx        gen_adduha3                        (rtx, rtx, rtx);
extern rtx        gen_mulqi3                         (rtx, rtx, rtx);
extern rtx        gen_mulqi3_call                    (rtx, rtx, rtx);
extern rtx        gen_mulhi3                         (rtx, rtx, rtx);
extern rtx        gen_mulhi3_call                    (rtx, rtx, rtx);
extern rtx        gen_mulsi3                         (rtx, rtx, rtx);
extern rtx        gen_muluqisi3                      (rtx, rtx, rtx);
extern rtx        gen_muluhisi3                      (rtx, rtx, rtx);
extern rtx        gen_mulsqisi3                      (rtx, rtx, rtx);
extern rtx        gen_mulshisi3                      (rtx, rtx, rtx);
extern rtx        gen_mulohisi3                      (rtx, rtx, rtx);
extern rtx        gen_mulhisi3                       (rtx, rtx, rtx);
extern rtx        gen_umulhisi3                      (rtx, rtx, rtx);
extern rtx        gen_usmulhisi3                     (rtx, rtx, rtx);
extern rtx        gen_smulhi3_highpart               (rtx, rtx, rtx);
extern rtx        gen_umulhi3_highpart               (rtx, rtx, rtx);
extern rtx        gen_mulpsi3                        (rtx, rtx, rtx);
extern rtx        gen_mulsqipsi3                     (rtx, rtx, rtx);
extern rtx        gen_rotlqi3                        (rtx, rtx, rtx);
extern rtx        gen_rotlqi3_4                      (rtx, rtx);
extern rtx        gen_rotlhi3                        (rtx, rtx, rtx);
extern rtx        gen_rotlpsi3                       (rtx, rtx, rtx);
extern rtx        gen_rotlsi3                        (rtx, rtx, rtx);
extern rtx        gen_ashlqi3                        (rtx, rtx, rtx);
extern rtx        gen_ashlqq3                        (rtx, rtx, rtx);
extern rtx        gen_ashluqq3                       (rtx, rtx, rtx);
extern rtx        gen_ashlpsi3                       (rtx, rtx, rtx);
extern rtx        gen_lshrqi3                        (rtx, rtx, rtx);
extern rtx        gen_lshrqq3                        (rtx, rtx, rtx);
extern rtx        gen_lshruqq3                       (rtx, rtx, rtx);
extern rtx        gen_cbranchqi4                     (rtx, rtx, rtx, rtx);
extern rtx        gen_cbranchqq4                     (rtx, rtx, rtx, rtx);
extern rtx        gen_cbranchuqq4                    (rtx, rtx, rtx, rtx);
extern rtx        gen_cbranchhi4                     (rtx, rtx, rtx, rtx);
extern rtx        gen_cbranchsi4                     (rtx, rtx, rtx, rtx);
extern rtx        gen_cbranchpsi4                    (rtx, rtx, rtx, rtx);
extern rtx        gen_cbranchhq4                     (rtx, rtx, rtx, rtx);
extern rtx        gen_cbranchuhq4                    (rtx, rtx, rtx, rtx);
extern rtx        gen_cbranchha4                     (rtx, rtx, rtx, rtx);
extern rtx        gen_cbranchuha4                    (rtx, rtx, rtx, rtx);
extern rtx        gen_cbranchsq4                     (rtx, rtx, rtx, rtx);
extern rtx        gen_cbranchusq4                    (rtx, rtx, rtx, rtx);
extern rtx        gen_cbranchsa4                     (rtx, rtx, rtx, rtx);
extern rtx        gen_cbranchusa4                    (rtx, rtx, rtx, rtx);
extern rtx        gen_call                           (rtx, rtx);
extern rtx        gen_sibcall                        (rtx, rtx);
extern rtx        gen_call_value                     (rtx, rtx, rtx);
extern rtx        gen_sibcall_value                  (rtx, rtx, rtx);
extern rtx        gen_indirect_jump                  (rtx);
extern rtx        gen_casesi                         (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_enable_interrupt               (void);
extern rtx        gen_disable_interrupt              (void);
extern rtx        gen_prologue                       (void);
extern rtx        gen_epilogue                       (void);
extern rtx        gen_sibcall_epilogue               (void);
extern rtx        gen_flash_segment1                 (rtx, rtx, rtx);
extern rtx        gen_flash_segment                  (rtx, rtx);
extern rtx        gen_parityhi2                      (rtx, rtx);
extern rtx        gen_paritysi2                      (rtx, rtx);
extern rtx        gen_popcounthi2                    (rtx, rtx);
extern rtx        gen_popcountsi2                    (rtx, rtx);
extern rtx        gen_clzhi2                         (rtx, rtx);
extern rtx        gen_clzsi2                         (rtx, rtx);
extern rtx        gen_ctzhi2                         (rtx, rtx);
extern rtx        gen_ctzsi2                         (rtx, rtx);
extern rtx        gen_ffshi2                         (rtx, rtx);
extern rtx        gen_ffssi2                         (rtx, rtx);
extern rtx        gen_bswapsi2                       (rtx, rtx);
extern rtx        gen_nopv                           (rtx);
extern rtx        gen_sleep                          (void);
extern rtx        gen_wdr                            (void);
extern rtx        gen_fmul                           (rtx, rtx, rtx);
extern rtx        gen_fmuls                          (rtx, rtx, rtx);
extern rtx        gen_fmulsu                         (rtx, rtx, rtx);
extern rtx        gen_insv                           (rtx, rtx, rtx, rtx);
extern rtx        gen_extzv                          (rtx, rtx, rtx, rtx);
extern rtx        gen_usneguqq2                      (rtx, rtx);
extern rtx        gen_usneguhq2                      (rtx, rtx);
extern rtx        gen_usneguha2                      (rtx, rtx);
extern rtx        gen_usnegusa2                      (rtx, rtx);
extern rtx        gen_usnegusq2                      (rtx, rtx);
extern rtx        gen_ssabshq2                       (rtx, rtx);
extern rtx        gen_ssneghq2                       (rtx, rtx);
extern rtx        gen_ssabsha2                       (rtx, rtx);
extern rtx        gen_ssnegha2                       (rtx, rtx);
extern rtx        gen_ssabssa2                       (rtx, rtx);
extern rtx        gen_ssnegsa2                       (rtx, rtx);
extern rtx        gen_ssabssq2                       (rtx, rtx);
extern rtx        gen_ssnegsq2                       (rtx, rtx);
extern rtx        gen_mulqq3                         (rtx, rtx, rtx);
extern rtx        gen_muluqq3                        (rtx, rtx, rtx);
extern rtx        gen_mulqq3_nomul                   (rtx, rtx, rtx);
extern rtx        gen_muluqq3_nomul                  (rtx, rtx, rtx);
extern rtx        gen_mulhq3                         (rtx, rtx, rtx);
extern rtx        gen_muluhq3                        (rtx, rtx, rtx);
extern rtx        gen_mulha3                         (rtx, rtx, rtx);
extern rtx        gen_muluha3                        (rtx, rtx, rtx);
extern rtx        gen_mulsa3                         (rtx, rtx, rtx);
extern rtx        gen_mulusa3                        (rtx, rtx, rtx);
extern rtx        gen_udivqq3                        (rtx, rtx, rtx);
extern rtx        gen_divqq3                         (rtx, rtx, rtx);
extern rtx        gen_udivuqq3                       (rtx, rtx, rtx);
extern rtx        gen_divuqq3                        (rtx, rtx, rtx);
extern rtx        gen_udivhq3                        (rtx, rtx, rtx);
extern rtx        gen_divhq3                         (rtx, rtx, rtx);
extern rtx        gen_udivuhq3                       (rtx, rtx, rtx);
extern rtx        gen_divuhq3                        (rtx, rtx, rtx);
extern rtx        gen_udivha3                        (rtx, rtx, rtx);
extern rtx        gen_divha3                         (rtx, rtx, rtx);
extern rtx        gen_udivuha3                       (rtx, rtx, rtx);
extern rtx        gen_divuha3                        (rtx, rtx, rtx);
extern rtx        gen_udivsa3                        (rtx, rtx, rtx);
extern rtx        gen_divsa3                         (rtx, rtx, rtx);
extern rtx        gen_udivusa3                       (rtx, rtx, rtx);
extern rtx        gen_divusa3                        (rtx, rtx, rtx);
extern rtx        gen_roundqq3                       (rtx, rtx, rtx);
extern rtx        gen_roundhq3                       (rtx, rtx, rtx);
extern rtx        gen_roundha3                       (rtx, rtx, rtx);
extern rtx        gen_roundsa3                       (rtx, rtx, rtx);
extern rtx        gen_roundsq3                       (rtx, rtx, rtx);
extern rtx        gen_rounduqq3                      (rtx, rtx, rtx);
extern rtx        gen_rounduhq3                      (rtx, rtx, rtx);
extern rtx        gen_rounduha3                      (rtx, rtx, rtx);
extern rtx        gen_roundusa3                      (rtx, rtx, rtx);
extern rtx        gen_roundusq3                      (rtx, rtx, rtx);
extern rtx        gen_adddi3                         (rtx, rtx, rtx);
extern rtx        gen_adddq3                         (rtx, rtx, rtx);
extern rtx        gen_addudq3                        (rtx, rtx, rtx);
extern rtx        gen_addda3                         (rtx, rtx, rtx);
extern rtx        gen_adduda3                        (rtx, rtx, rtx);
extern rtx        gen_addta3                         (rtx, rtx, rtx);
extern rtx        gen_adduta3                        (rtx, rtx, rtx);
extern rtx        gen_subdi3                         (rtx, rtx, rtx);
extern rtx        gen_subdq3                         (rtx, rtx, rtx);
extern rtx        gen_subudq3                        (rtx, rtx, rtx);
extern rtx        gen_subda3                         (rtx, rtx, rtx);
extern rtx        gen_subuda3                        (rtx, rtx, rtx);
extern rtx        gen_subta3                         (rtx, rtx, rtx);
extern rtx        gen_subuta3                        (rtx, rtx, rtx);
extern rtx        gen_ssadddq3                       (rtx, rtx, rtx);
extern rtx        gen_sssubdq3                       (rtx, rtx, rtx);
extern rtx        gen_ssaddda3                       (rtx, rtx, rtx);
extern rtx        gen_sssubda3                       (rtx, rtx, rtx);
extern rtx        gen_ssaddta3                       (rtx, rtx, rtx);
extern rtx        gen_sssubta3                       (rtx, rtx, rtx);
extern rtx        gen_usaddudq3                      (rtx, rtx, rtx);
extern rtx        gen_ussubudq3                      (rtx, rtx, rtx);
extern rtx        gen_usadduda3                      (rtx, rtx, rtx);
extern rtx        gen_ussubuda3                      (rtx, rtx, rtx);
extern rtx        gen_usadduta3                      (rtx, rtx, rtx);
extern rtx        gen_ussubuta3                      (rtx, rtx, rtx);
extern rtx        gen_negdi2                         (rtx, rtx);
extern rtx        gen_conditional_jump               (rtx, rtx);
extern rtx        gen_cbranchdi4                     (rtx, rtx, rtx, rtx);
extern rtx        gen_cbranchdq4                     (rtx, rtx, rtx, rtx);
extern rtx        gen_cbranchudq4                    (rtx, rtx, rtx, rtx);
extern rtx        gen_cbranchda4                     (rtx, rtx, rtx, rtx);
extern rtx        gen_cbranchuda4                    (rtx, rtx, rtx, rtx);
extern rtx        gen_cbranchta4                     (rtx, rtx, rtx, rtx);
extern rtx        gen_cbranchuta4                    (rtx, rtx, rtx, rtx);
extern rtx        gen_ashldi3                        (rtx, rtx, rtx);
extern rtx        gen_ashrdi3                        (rtx, rtx, rtx);
extern rtx        gen_lshrdi3                        (rtx, rtx, rtx);
extern rtx        gen_rotldi3                        (rtx, rtx, rtx);
extern rtx        gen_ashldq3                        (rtx, rtx, rtx);
extern rtx        gen_ashrdq3                        (rtx, rtx, rtx);
extern rtx        gen_lshrdq3                        (rtx, rtx, rtx);
extern rtx        gen_rotldq3                        (rtx, rtx, rtx);
extern rtx        gen_ashludq3                       (rtx, rtx, rtx);
extern rtx        gen_ashrudq3                       (rtx, rtx, rtx);
extern rtx        gen_lshrudq3                       (rtx, rtx, rtx);
extern rtx        gen_rotludq3                       (rtx, rtx, rtx);
extern rtx        gen_ashlda3                        (rtx, rtx, rtx);
extern rtx        gen_ashrda3                        (rtx, rtx, rtx);
extern rtx        gen_lshrda3                        (rtx, rtx, rtx);
extern rtx        gen_rotlda3                        (rtx, rtx, rtx);
extern rtx        gen_ashluda3                       (rtx, rtx, rtx);
extern rtx        gen_ashruda3                       (rtx, rtx, rtx);
extern rtx        gen_lshruda3                       (rtx, rtx, rtx);
extern rtx        gen_rotluda3                       (rtx, rtx, rtx);
extern rtx        gen_ashlta3                        (rtx, rtx, rtx);
extern rtx        gen_ashrta3                        (rtx, rtx, rtx);
extern rtx        gen_lshrta3                        (rtx, rtx, rtx);
extern rtx        gen_rotlta3                        (rtx, rtx, rtx);
extern rtx        gen_ashluta3                       (rtx, rtx, rtx);
extern rtx        gen_ashruta3                       (rtx, rtx, rtx);
extern rtx        gen_lshruta3                       (rtx, rtx, rtx);
extern rtx        gen_rotluta3                       (rtx, rtx, rtx);
extern rtx        gen_mulsidi3                       (rtx, rtx, rtx);
extern rtx        gen_umulsidi3                      (rtx, rtx, rtx);

#endif /* GCC_INSN_FLAGS_H */
