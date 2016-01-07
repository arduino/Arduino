# Get directory of this makefile
MAKEFILE_DIR := $(dir $(lastword $(MAKEFILE_LIST)))

# Specify the default makedefs file, which can be overridden at the command line
MAKEDEFS = $(MAKEFILE_DIR)makedefs
include $(MAKEDEFS)

# Always builds phony rules
.PHONY: all clean

# Builds driverlib.lib
all :
		@ rm -f $(MAKEFILE_DIR)driverlib.lib
		@ rm -f $(MAKEFILE_DIR)*.obj
		@ echo CCS: Compile adi.c
		@ $(COMPILER_TOOL) -mv7M3 --code_state=16 --abi=eabi -me --opt_level=3 --opt_for_speed=0 --include_path=$(COMPILER_INCL) --include_path="$(MAKEFILE_DIR)../../.." -g --gcc --define=ccs --display_error_number --diag_warning=225 --gen_func_subsections=on --preproc_with_compile "$(MAKEFILE_DIR)../../../driverlib/adi.c"
		@ echo CCS: Compile aon_batmon.c
		@ $(COMPILER_TOOL) -mv7M3 --code_state=16 --abi=eabi -me --opt_level=3 --opt_for_speed=0 --include_path=$(COMPILER_INCL) --include_path="$(MAKEFILE_DIR)../../.." -g --gcc --define=ccs --display_error_number --diag_warning=225 --gen_func_subsections=on --preproc_with_compile "$(MAKEFILE_DIR)../../../driverlib/aon_batmon.c"
		@ echo CCS: Compile aon_event.c
		@ $(COMPILER_TOOL) -mv7M3 --code_state=16 --abi=eabi -me --opt_level=3 --opt_for_speed=0 --include_path=$(COMPILER_INCL) --include_path="$(MAKEFILE_DIR)../../.." -g --gcc --define=ccs --display_error_number --diag_warning=225 --gen_func_subsections=on --preproc_with_compile "$(MAKEFILE_DIR)../../../driverlib/aon_event.c"
		@ echo CCS: Compile aon_ioc.c
		@ $(COMPILER_TOOL) -mv7M3 --code_state=16 --abi=eabi -me --opt_level=3 --opt_for_speed=0 --include_path=$(COMPILER_INCL) --include_path="$(MAKEFILE_DIR)../../.." -g --gcc --define=ccs --display_error_number --diag_warning=225 --gen_func_subsections=on --preproc_with_compile "$(MAKEFILE_DIR)../../../driverlib/aon_ioc.c"
		@ echo CCS: Compile aon_rtc.c
		@ $(COMPILER_TOOL) -mv7M3 --code_state=16 --abi=eabi -me --opt_level=3 --opt_for_speed=0 --include_path=$(COMPILER_INCL) --include_path="$(MAKEFILE_DIR)../../.." -g --gcc --define=ccs --display_error_number --diag_warning=225 --gen_func_subsections=on --preproc_with_compile "$(MAKEFILE_DIR)../../../driverlib/aon_rtc.c"
		@ echo CCS: Compile aon_wuc.c
		@ $(COMPILER_TOOL) -mv7M3 --code_state=16 --abi=eabi -me --opt_level=3 --opt_for_speed=0 --include_path=$(COMPILER_INCL) --include_path="$(MAKEFILE_DIR)../../.." -g --gcc --define=ccs --display_error_number --diag_warning=225 --gen_func_subsections=on --preproc_with_compile "$(MAKEFILE_DIR)../../../driverlib/aon_wuc.c"
		@ echo CCS: Compile aux_adc.c
		@ $(COMPILER_TOOL) -mv7M3 --code_state=16 --abi=eabi -me --opt_level=3 --opt_for_speed=0 --include_path=$(COMPILER_INCL) --include_path="$(MAKEFILE_DIR)../../.." -g --gcc --define=ccs --display_error_number --diag_warning=225 --gen_func_subsections=on --preproc_with_compile "$(MAKEFILE_DIR)../../../driverlib/aux_adc.c"
		@ echo CCS: Compile aux_smph.c
		@ $(COMPILER_TOOL) -mv7M3 --code_state=16 --abi=eabi -me --opt_level=3 --opt_for_speed=0 --include_path=$(COMPILER_INCL) --include_path="$(MAKEFILE_DIR)../../.." -g --gcc --define=ccs --display_error_number --diag_warning=225 --gen_func_subsections=on --preproc_with_compile "$(MAKEFILE_DIR)../../../driverlib/aux_smph.c"
		@ echo CCS: Compile aux_tdc.c
		@ $(COMPILER_TOOL) -mv7M3 --code_state=16 --abi=eabi -me --opt_level=3 --opt_for_speed=0 --include_path=$(COMPILER_INCL) --include_path="$(MAKEFILE_DIR)../../.." -g --gcc --define=ccs --display_error_number --diag_warning=225 --gen_func_subsections=on --preproc_with_compile "$(MAKEFILE_DIR)../../../driverlib/aux_tdc.c"
		@ echo CCS: Compile aux_timer.c
		@ $(COMPILER_TOOL) -mv7M3 --code_state=16 --abi=eabi -me --opt_level=3 --opt_for_speed=0 --include_path=$(COMPILER_INCL) --include_path="$(MAKEFILE_DIR)../../.." -g --gcc --define=ccs --display_error_number --diag_warning=225 --gen_func_subsections=on --preproc_with_compile "$(MAKEFILE_DIR)../../../driverlib/aux_timer.c"
		@ echo CCS: Compile aux_wuc.c
		@ $(COMPILER_TOOL) -mv7M3 --code_state=16 --abi=eabi -me --opt_level=3 --opt_for_speed=0 --include_path=$(COMPILER_INCL) --include_path="$(MAKEFILE_DIR)../../.." -g --gcc --define=ccs --display_error_number --diag_warning=225 --gen_func_subsections=on --preproc_with_compile "$(MAKEFILE_DIR)../../../driverlib/aux_wuc.c"
		@ echo CCS: Compile ccfgread.c
		@ $(COMPILER_TOOL) -mv7M3 --code_state=16 --abi=eabi -me --opt_level=3 --opt_for_speed=0 --include_path=$(COMPILER_INCL) --include_path="$(MAKEFILE_DIR)../../.." -g --gcc --define=ccs --display_error_number --diag_warning=225 --gen_func_subsections=on --preproc_with_compile "$(MAKEFILE_DIR)../../../driverlib/ccfgread.c"
		@ echo CCS: Compile chipinfo.c
		@ $(COMPILER_TOOL) -mv7M3 --code_state=16 --abi=eabi -me --opt_level=3 --opt_for_speed=0 --include_path=$(COMPILER_INCL) --include_path="$(MAKEFILE_DIR)../../.." -g --gcc --define=ccs --display_error_number --diag_warning=225 --gen_func_subsections=on --preproc_with_compile "$(MAKEFILE_DIR)../../../driverlib/chipinfo.c"
		@ echo CCS: Compile cpu.c
		@ $(COMPILER_TOOL) -mv7M3 --code_state=16 --abi=eabi -me --opt_level=3 --opt_for_speed=0 --include_path=$(COMPILER_INCL) --include_path="$(MAKEFILE_DIR)../../.." -g --gcc --define=ccs --display_error_number --diag_warning=225 --gen_func_subsections=on --preproc_with_compile "$(MAKEFILE_DIR)../../../driverlib/cpu.c"
		@ echo CCS: Compile crypto.c
		@ $(COMPILER_TOOL) -mv7M3 --code_state=16 --abi=eabi -me --opt_level=3 --opt_for_speed=0 --include_path=$(COMPILER_INCL) --include_path="$(MAKEFILE_DIR)../../.." -g --gcc --define=ccs --display_error_number --diag_warning=225 --gen_func_subsections=on --preproc_with_compile "$(MAKEFILE_DIR)../../../driverlib/crypto.c"
		@ echo CCS: Compile ddi.c
		@ $(COMPILER_TOOL) -mv7M3 --code_state=16 --abi=eabi -me --opt_level=3 --opt_for_speed=0 --include_path=$(COMPILER_INCL) --include_path="$(MAKEFILE_DIR)../../.." -g --gcc --define=ccs --display_error_number --diag_warning=225 --gen_func_subsections=on --preproc_with_compile "$(MAKEFILE_DIR)../../../driverlib/ddi.c"
		@ echo CCS: Compile debug.c
		@ $(COMPILER_TOOL) -mv7M3 --code_state=16 --abi=eabi -me --opt_level=3 --opt_for_speed=0 --include_path=$(COMPILER_INCL) --include_path="$(MAKEFILE_DIR)../../.." -g --gcc --define=ccs --display_error_number --diag_warning=225 --gen_func_subsections=on --preproc_with_compile "$(MAKEFILE_DIR)../../../driverlib/debug.c"
		@ echo CCS: Compile driverlib_release.c
		@ $(COMPILER_TOOL) -mv7M3 --code_state=16 --abi=eabi -me --opt_level=3 --opt_for_speed=0 --include_path=$(COMPILER_INCL) --include_path="$(MAKEFILE_DIR)../../.." -g --gcc --define=ccs --display_error_number --diag_warning=225 --gen_func_subsections=on --preproc_with_compile "$(MAKEFILE_DIR)../../../driverlib/driverlib_release.c"
		@ echo CCS: Compile event.c
		@ $(COMPILER_TOOL) -mv7M3 --code_state=16 --abi=eabi -me --opt_level=3 --opt_for_speed=0 --include_path=$(COMPILER_INCL) --include_path="$(MAKEFILE_DIR)../../.." -g --gcc --define=ccs --display_error_number --diag_warning=225 --gen_func_subsections=on --preproc_with_compile "$(MAKEFILE_DIR)../../../driverlib/event.c"
		@ echo CCS: Compile flash.c
		@ $(COMPILER_TOOL) -mv7M3 --code_state=16 --abi=eabi -me --opt_level=3 --opt_for_speed=0 --include_path=$(COMPILER_INCL) --include_path="$(MAKEFILE_DIR)../../.." -g --gcc --define=ccs --display_error_number --diag_warning=225 --gen_func_subsections=on --preproc_with_compile "$(MAKEFILE_DIR)../../../driverlib/flash.c"
		@ echo CCS: Compile gpio.c
		@ $(COMPILER_TOOL) -mv7M3 --code_state=16 --abi=eabi -me --opt_level=3 --opt_for_speed=0 --include_path=$(COMPILER_INCL) --include_path="$(MAKEFILE_DIR)../../.." -g --gcc --define=ccs --display_error_number --diag_warning=225 --gen_func_subsections=on --preproc_with_compile "$(MAKEFILE_DIR)../../../driverlib/gpio.c"
		@ echo CCS: Compile i2c.c
		@ $(COMPILER_TOOL) -mv7M3 --code_state=16 --abi=eabi -me --opt_level=3 --opt_for_speed=0 --include_path=$(COMPILER_INCL) --include_path="$(MAKEFILE_DIR)../../.." -g --gcc --define=ccs --display_error_number --diag_warning=225 --gen_func_subsections=on --preproc_with_compile "$(MAKEFILE_DIR)../../../driverlib/i2c.c"
		@ echo CCS: Compile i2s.c
		@ $(COMPILER_TOOL) -mv7M3 --code_state=16 --abi=eabi -me --opt_level=3 --opt_for_speed=0 --include_path=$(COMPILER_INCL) --include_path="$(MAKEFILE_DIR)../../.." -g --gcc --define=ccs --display_error_number --diag_warning=225 --gen_func_subsections=on --preproc_with_compile "$(MAKEFILE_DIR)../../../driverlib/i2s.c"
		@ echo CCS: Compile interrupt.c
		@ $(COMPILER_TOOL) -mv7M3 --code_state=16 --abi=eabi -me --opt_level=3 --opt_for_speed=0 --include_path=$(COMPILER_INCL) --include_path="$(MAKEFILE_DIR)../../.." -g --gcc --define=ccs --display_error_number --diag_warning=225 --gen_func_subsections=on --preproc_with_compile "$(MAKEFILE_DIR)../../../driverlib/interrupt.c"
		@ echo CCS: Compile ioc.c
		@ $(COMPILER_TOOL) -mv7M3 --code_state=16 --abi=eabi -me --opt_level=3 --opt_for_speed=0 --include_path=$(COMPILER_INCL) --include_path="$(MAKEFILE_DIR)../../.." -g --gcc --define=ccs --display_error_number --diag_warning=225 --gen_func_subsections=on --preproc_with_compile "$(MAKEFILE_DIR)../../../driverlib/ioc.c"
		@ echo CCS: Compile osc.c
		@ $(COMPILER_TOOL) -mv7M3 --code_state=16 --abi=eabi -me --opt_level=3 --opt_for_speed=0 --include_path=$(COMPILER_INCL) --include_path="$(MAKEFILE_DIR)../../.." -g --gcc --define=ccs --display_error_number --diag_warning=225 --gen_func_subsections=on --preproc_with_compile "$(MAKEFILE_DIR)../../../driverlib/osc.c"
		@ echo CCS: Compile prcm.c
		@ $(COMPILER_TOOL) -mv7M3 --code_state=16 --abi=eabi -me --opt_level=3 --opt_for_speed=0 --include_path=$(COMPILER_INCL) --include_path="$(MAKEFILE_DIR)../../.." -g --gcc --define=ccs --display_error_number --diag_warning=225 --gen_func_subsections=on --preproc_with_compile "$(MAKEFILE_DIR)../../../driverlib/prcm.c"
		@ echo CCS: Compile pwr_ctrl.c
		@ $(COMPILER_TOOL) -mv7M3 --code_state=16 --abi=eabi -me --opt_level=3 --opt_for_speed=0 --include_path=$(COMPILER_INCL) --include_path="$(MAKEFILE_DIR)../../.." -g --gcc --define=ccs --display_error_number --diag_warning=225 --gen_func_subsections=on --preproc_with_compile "$(MAKEFILE_DIR)../../../driverlib/pwr_ctrl.c"
		@ echo CCS: Compile rfc.c
		@ $(COMPILER_TOOL) -mv7M3 --code_state=16 --abi=eabi -me --opt_level=3 --opt_for_speed=0 --include_path=$(COMPILER_INCL) --include_path="$(MAKEFILE_DIR)../../.." -g --gcc --define=ccs --display_error_number --diag_warning=225 --gen_func_subsections=on --preproc_with_compile "$(MAKEFILE_DIR)../../../driverlib/rfc.c"
		@ echo CCS: Compile rom_crypto.c
		@ $(COMPILER_TOOL) -mv7M3 --code_state=16 --abi=eabi -me --opt_level=3 --opt_for_speed=0 --include_path=$(COMPILER_INCL) --include_path="$(MAKEFILE_DIR)../../.." -g --gcc --define=ccs --display_error_number --diag_warning=225 --gen_func_subsections=on --preproc_with_compile "$(MAKEFILE_DIR)../../../driverlib/rom_crypto.c"
		@ echo CCS: Compile setup.c
		@ $(COMPILER_TOOL) -mv7M3 --code_state=16 --abi=eabi -me --opt_level=3 --opt_for_speed=0 --include_path=$(COMPILER_INCL) --include_path="$(MAKEFILE_DIR)../../.." -g --gcc --define=ccs --display_error_number --diag_warning=225 --gen_func_subsections=on --preproc_with_compile "$(MAKEFILE_DIR)../../../driverlib/setup.c"
		@ echo CCS: Compile smph.c
		@ $(COMPILER_TOOL) -mv7M3 --code_state=16 --abi=eabi -me --opt_level=3 --opt_for_speed=0 --include_path=$(COMPILER_INCL) --include_path="$(MAKEFILE_DIR)../../.." -g --gcc --define=ccs --display_error_number --diag_warning=225 --gen_func_subsections=on --preproc_with_compile "$(MAKEFILE_DIR)../../../driverlib/smph.c"
		@ echo CCS: Compile ssi.c
		@ $(COMPILER_TOOL) -mv7M3 --code_state=16 --abi=eabi -me --opt_level=3 --opt_for_speed=0 --include_path=$(COMPILER_INCL) --include_path="$(MAKEFILE_DIR)../../.." -g --gcc --define=ccs --display_error_number --diag_warning=225 --gen_func_subsections=on --preproc_with_compile "$(MAKEFILE_DIR)../../../driverlib/ssi.c"
		@ echo CCS: Compile systick.c
		@ $(COMPILER_TOOL) -mv7M3 --code_state=16 --abi=eabi -me --opt_level=3 --opt_for_speed=0 --include_path=$(COMPILER_INCL) --include_path="$(MAKEFILE_DIR)../../.." -g --gcc --define=ccs --display_error_number --diag_warning=225 --gen_func_subsections=on --preproc_with_compile "$(MAKEFILE_DIR)../../../driverlib/systick.c"
		@ echo CCS: Compile sys_ctrl.c
		@ $(COMPILER_TOOL) -mv7M3 --code_state=16 --abi=eabi -me --opt_level=3 --opt_for_speed=0 --include_path=$(COMPILER_INCL) --include_path="$(MAKEFILE_DIR)../../.." -g --gcc --define=ccs --display_error_number --diag_warning=225 --gen_func_subsections=on --preproc_with_compile "$(MAKEFILE_DIR)../../../driverlib/sys_ctrl.c"
		@ echo CCS: Compile timer.c
		@ $(COMPILER_TOOL) -mv7M3 --code_state=16 --abi=eabi -me --opt_level=3 --opt_for_speed=0 --include_path=$(COMPILER_INCL) --include_path="$(MAKEFILE_DIR)../../.." -g --gcc --define=ccs --display_error_number --diag_warning=225 --gen_func_subsections=on --preproc_with_compile "$(MAKEFILE_DIR)../../../driverlib/timer.c"
		@ echo CCS: Compile trng.c
		@ $(COMPILER_TOOL) -mv7M3 --code_state=16 --abi=eabi -me --opt_level=3 --opt_for_speed=0 --include_path=$(COMPILER_INCL) --include_path="$(MAKEFILE_DIR)../../.." -g --gcc --define=ccs --display_error_number --diag_warning=225 --gen_func_subsections=on --preproc_with_compile "$(MAKEFILE_DIR)../../../driverlib/trng.c"
		@ echo CCS: Compile uart.c
		@ $(COMPILER_TOOL) -mv7M3 --code_state=16 --abi=eabi -me --opt_level=3 --opt_for_speed=0 --include_path=$(COMPILER_INCL) --include_path="$(MAKEFILE_DIR)../../.." -g --gcc --define=ccs --display_error_number --diag_warning=225 --gen_func_subsections=on --preproc_with_compile "$(MAKEFILE_DIR)../../../driverlib/uart.c"
		@ echo CCS: Compile udma.c
		@ $(COMPILER_TOOL) -mv7M3 --code_state=16 --abi=eabi -me --opt_level=3 --opt_for_speed=0 --include_path=$(COMPILER_INCL) --include_path="$(MAKEFILE_DIR)../../.." -g --gcc --define=ccs --display_error_number --diag_warning=225 --gen_func_subsections=on --preproc_with_compile "$(MAKEFILE_DIR)../../../driverlib/udma.c"
		@ echo CCS: Compile vims.c
		@ $(COMPILER_TOOL) -mv7M3 --code_state=16 --abi=eabi -me --opt_level=3 --opt_for_speed=0 --include_path=$(COMPILER_INCL) --include_path="$(MAKEFILE_DIR)../../.." -g --gcc --define=ccs --display_error_number --diag_warning=225 --gen_func_subsections=on --preproc_with_compile "$(MAKEFILE_DIR)../../../driverlib/vims.c"
		@ echo CCS: Compile watchdog.c
		@ $(COMPILER_TOOL) -mv7M3 --code_state=16 --abi=eabi -me --opt_level=3 --opt_for_speed=0 --include_path=$(COMPILER_INCL) --include_path="$(MAKEFILE_DIR)../../.." -g --gcc --define=ccs --display_error_number --diag_warning=225 --gen_func_subsections=on --preproc_with_compile "$(MAKEFILE_DIR)../../../driverlib/watchdog.c"
		@ echo CCS: Archive driverlib.lib
		@ $(ARCHIVER_TOOL) r "driverlib.lib" "$(MAKEFILE_DIR)adi.obj" "$(MAKEFILE_DIR)aon_batmon.obj" "$(MAKEFILE_DIR)aon_event.obj" "$(MAKEFILE_DIR)aon_ioc.obj" "$(MAKEFILE_DIR)aon_rtc.obj" "$(MAKEFILE_DIR)aon_wuc.obj" "$(MAKEFILE_DIR)aux_adc.obj" "$(MAKEFILE_DIR)aux_smph.obj" "$(MAKEFILE_DIR)aux_tdc.obj" "$(MAKEFILE_DIR)aux_timer.obj" "$(MAKEFILE_DIR)aux_wuc.obj" "$(MAKEFILE_DIR)ccfgread.obj" "$(MAKEFILE_DIR)chipinfo.obj" "$(MAKEFILE_DIR)cpu.obj" "$(MAKEFILE_DIR)crypto.obj" "$(MAKEFILE_DIR)ddi.obj" "$(MAKEFILE_DIR)debug.obj" "$(MAKEFILE_DIR)driverlib_release.obj" "$(MAKEFILE_DIR)event.obj" "$(MAKEFILE_DIR)flash.obj" "$(MAKEFILE_DIR)gpio.obj" "$(MAKEFILE_DIR)i2c.obj" "$(MAKEFILE_DIR)i2s.obj" "$(MAKEFILE_DIR)interrupt.obj" "$(MAKEFILE_DIR)ioc.obj" "$(MAKEFILE_DIR)osc.obj" "$(MAKEFILE_DIR)prcm.obj" "$(MAKEFILE_DIR)pwr_ctrl.obj" "$(MAKEFILE_DIR)rfc.obj" "$(MAKEFILE_DIR)rom_crypto.obj" "$(MAKEFILE_DIR)setup.obj" "$(MAKEFILE_DIR)smph.obj" "$(MAKEFILE_DIR)ssi.obj" "$(MAKEFILE_DIR)systick.obj" "$(MAKEFILE_DIR)sys_ctrl.obj" "$(MAKEFILE_DIR)timer.obj" "$(MAKEFILE_DIR)trng.obj" "$(MAKEFILE_DIR)uart.obj" "$(MAKEFILE_DIR)udma.obj" "$(MAKEFILE_DIR)vims.obj" "$(MAKEFILE_DIR)watchdog.obj"
		@ rm -f $(MAKEFILE_DIR)*.obj

# Deletes previous output and temporary files
clean :
		@ rm -fR $(MAKEFILE_DIR)*.obj
		@ rm -fR $(MAKEFILE_DIR)*.lib
