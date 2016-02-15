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
		@ rm -f $(MAKEFILE_DIR)*.o
		@ echo KEIL: Compile adi.c
		@ $(COMPILER_TOOL) -c --cpu Cortex-M3 -D__EVAL --li -O3 --apcs=interwork -I$(MAKEFILE_DIR)../../.. --c99 --reduce_paths -Drvmdk -o "adi.o" $(MAKEFILE_DIR)../../../driverlib/adi.c
		@ echo KEIL: Compile aon_batmon.c
		@ $(COMPILER_TOOL) -c --cpu Cortex-M3 -D__EVAL --li -O3 --apcs=interwork -I$(MAKEFILE_DIR)../../.. --c99 --reduce_paths -Drvmdk -o "aon_batmon.o" $(MAKEFILE_DIR)../../../driverlib/aon_batmon.c
		@ echo KEIL: Compile aon_event.c
		@ $(COMPILER_TOOL) -c --cpu Cortex-M3 -D__EVAL --li -O3 --apcs=interwork -I$(MAKEFILE_DIR)../../.. --c99 --reduce_paths -Drvmdk -o "aon_event.o" $(MAKEFILE_DIR)../../../driverlib/aon_event.c
		@ echo KEIL: Compile aon_ioc.c
		@ $(COMPILER_TOOL) -c --cpu Cortex-M3 -D__EVAL --li -O3 --apcs=interwork -I$(MAKEFILE_DIR)../../.. --c99 --reduce_paths -Drvmdk -o "aon_ioc.o" $(MAKEFILE_DIR)../../../driverlib/aon_ioc.c
		@ echo KEIL: Compile aon_rtc.c
		@ $(COMPILER_TOOL) -c --cpu Cortex-M3 -D__EVAL --li -O3 --apcs=interwork -I$(MAKEFILE_DIR)../../.. --c99 --reduce_paths -Drvmdk -o "aon_rtc.o" $(MAKEFILE_DIR)../../../driverlib/aon_rtc.c
		@ echo KEIL: Compile aon_wuc.c
		@ $(COMPILER_TOOL) -c --cpu Cortex-M3 -D__EVAL --li -O3 --apcs=interwork -I$(MAKEFILE_DIR)../../.. --c99 --reduce_paths -Drvmdk -o "aon_wuc.o" $(MAKEFILE_DIR)../../../driverlib/aon_wuc.c
		@ echo KEIL: Compile aux_adc.c
		@ $(COMPILER_TOOL) -c --cpu Cortex-M3 -D__EVAL --li -O3 --apcs=interwork -I$(MAKEFILE_DIR)../../.. --c99 --reduce_paths -Drvmdk -o "aux_adc.o" $(MAKEFILE_DIR)../../../driverlib/aux_adc.c
		@ echo KEIL: Compile aux_smph.c
		@ $(COMPILER_TOOL) -c --cpu Cortex-M3 -D__EVAL --li -O3 --apcs=interwork -I$(MAKEFILE_DIR)../../.. --c99 --reduce_paths -Drvmdk -o "aux_smph.o" $(MAKEFILE_DIR)../../../driverlib/aux_smph.c
		@ echo KEIL: Compile aux_tdc.c
		@ $(COMPILER_TOOL) -c --cpu Cortex-M3 -D__EVAL --li -O3 --apcs=interwork -I$(MAKEFILE_DIR)../../.. --c99 --reduce_paths -Drvmdk -o "aux_tdc.o" $(MAKEFILE_DIR)../../../driverlib/aux_tdc.c
		@ echo KEIL: Compile aux_timer.c
		@ $(COMPILER_TOOL) -c --cpu Cortex-M3 -D__EVAL --li -O3 --apcs=interwork -I$(MAKEFILE_DIR)../../.. --c99 --reduce_paths -Drvmdk -o "aux_timer.o" $(MAKEFILE_DIR)../../../driverlib/aux_timer.c
		@ echo KEIL: Compile aux_wuc.c
		@ $(COMPILER_TOOL) -c --cpu Cortex-M3 -D__EVAL --li -O3 --apcs=interwork -I$(MAKEFILE_DIR)../../.. --c99 --reduce_paths -Drvmdk -o "aux_wuc.o" $(MAKEFILE_DIR)../../../driverlib/aux_wuc.c
		@ echo KEIL: Compile ccfgread.c
		@ $(COMPILER_TOOL) -c --cpu Cortex-M3 -D__EVAL --li -O3 --apcs=interwork -I$(MAKEFILE_DIR)../../.. --c99 --reduce_paths -Drvmdk -o "ccfgread.o" $(MAKEFILE_DIR)../../../driverlib/ccfgread.c
		@ echo KEIL: Compile chipinfo.c
		@ $(COMPILER_TOOL) -c --cpu Cortex-M3 -D__EVAL --li -O3 --apcs=interwork -I$(MAKEFILE_DIR)../../.. --c99 --reduce_paths -Drvmdk -o "chipinfo.o" $(MAKEFILE_DIR)../../../driverlib/chipinfo.c
		@ echo KEIL: Compile cpu.c
		@ $(COMPILER_TOOL) -c --cpu Cortex-M3 -D__EVAL --li -O3 --apcs=interwork -I$(MAKEFILE_DIR)../../.. --c99 --reduce_paths -Drvmdk -o "cpu.o" $(MAKEFILE_DIR)../../../driverlib/cpu.c
		@ echo KEIL: Compile crypto.c
		@ $(COMPILER_TOOL) -c --cpu Cortex-M3 -D__EVAL --li -O3 --apcs=interwork -I$(MAKEFILE_DIR)../../.. --c99 --reduce_paths -Drvmdk -o "crypto.o" $(MAKEFILE_DIR)../../../driverlib/crypto.c
		@ echo KEIL: Compile ddi.c
		@ $(COMPILER_TOOL) -c --cpu Cortex-M3 -D__EVAL --li -O3 --apcs=interwork -I$(MAKEFILE_DIR)../../.. --c99 --reduce_paths -Drvmdk -o "ddi.o" $(MAKEFILE_DIR)../../../driverlib/ddi.c
		@ echo KEIL: Compile debug.c
		@ $(COMPILER_TOOL) -c --cpu Cortex-M3 -D__EVAL --li -O3 --apcs=interwork -I$(MAKEFILE_DIR)../../.. --c99 --reduce_paths -Drvmdk -o "debug.o" $(MAKEFILE_DIR)../../../driverlib/debug.c
		@ echo KEIL: Compile driverlib_release.c
		@ $(COMPILER_TOOL) -c --cpu Cortex-M3 -D__EVAL --li -O3 --apcs=interwork -I$(MAKEFILE_DIR)../../.. --c99 --reduce_paths -Drvmdk -o "driverlib_release.o" $(MAKEFILE_DIR)../../../driverlib/driverlib_release.c
		@ echo KEIL: Compile event.c
		@ $(COMPILER_TOOL) -c --cpu Cortex-M3 -D__EVAL --li -O3 --apcs=interwork -I$(MAKEFILE_DIR)../../.. --c99 --reduce_paths -Drvmdk -o "event.o" $(MAKEFILE_DIR)../../../driverlib/event.c
		@ echo KEIL: Compile flash.c
		@ $(COMPILER_TOOL) -c --cpu Cortex-M3 -D__EVAL --li -O3 --apcs=interwork -I$(MAKEFILE_DIR)../../.. --c99 --reduce_paths -Drvmdk -o "flash.o" $(MAKEFILE_DIR)../../../driverlib/flash.c
		@ echo KEIL: Compile gpio.c
		@ $(COMPILER_TOOL) -c --cpu Cortex-M3 -D__EVAL --li -O3 --apcs=interwork -I$(MAKEFILE_DIR)../../.. --c99 --reduce_paths -Drvmdk -o "gpio.o" $(MAKEFILE_DIR)../../../driverlib/gpio.c
		@ echo KEIL: Compile i2c.c
		@ $(COMPILER_TOOL) -c --cpu Cortex-M3 -D__EVAL --li -O3 --apcs=interwork -I$(MAKEFILE_DIR)../../.. --c99 --reduce_paths -Drvmdk -o "i2c.o" $(MAKEFILE_DIR)../../../driverlib/i2c.c
		@ echo KEIL: Compile i2s.c
		@ $(COMPILER_TOOL) -c --cpu Cortex-M3 -D__EVAL --li -O3 --apcs=interwork -I$(MAKEFILE_DIR)../../.. --c99 --reduce_paths -Drvmdk -o "i2s.o" $(MAKEFILE_DIR)../../../driverlib/i2s.c
		@ echo KEIL: Compile interrupt.c
		@ $(COMPILER_TOOL) -c --cpu Cortex-M3 -D__EVAL --li -O3 --apcs=interwork -I$(MAKEFILE_DIR)../../.. --c99 --reduce_paths -Drvmdk -o "interrupt.o" $(MAKEFILE_DIR)../../../driverlib/interrupt.c
		@ echo KEIL: Compile ioc.c
		@ $(COMPILER_TOOL) -c --cpu Cortex-M3 -D__EVAL --li -O3 --apcs=interwork -I$(MAKEFILE_DIR)../../.. --c99 --reduce_paths -Drvmdk -o "ioc.o" $(MAKEFILE_DIR)../../../driverlib/ioc.c
		@ echo KEIL: Compile osc.c
		@ $(COMPILER_TOOL) -c --cpu Cortex-M3 -D__EVAL --li -O3 --apcs=interwork -I$(MAKEFILE_DIR)../../.. --c99 --reduce_paths -Drvmdk -o "osc.o" $(MAKEFILE_DIR)../../../driverlib/osc.c
		@ echo KEIL: Compile prcm.c
		@ $(COMPILER_TOOL) -c --cpu Cortex-M3 -D__EVAL --li -O3 --apcs=interwork -I$(MAKEFILE_DIR)../../.. --c99 --reduce_paths -Drvmdk -o "prcm.o" $(MAKEFILE_DIR)../../../driverlib/prcm.c
		@ echo KEIL: Compile pwr_ctrl.c
		@ $(COMPILER_TOOL) -c --cpu Cortex-M3 -D__EVAL --li -O3 --apcs=interwork -I$(MAKEFILE_DIR)../../.. --c99 --reduce_paths -Drvmdk -o "pwr_ctrl.o" $(MAKEFILE_DIR)../../../driverlib/pwr_ctrl.c
		@ echo KEIL: Compile rfc.c
		@ $(COMPILER_TOOL) -c --cpu Cortex-M3 -D__EVAL --li -O3 --apcs=interwork -I$(MAKEFILE_DIR)../../.. --c99 --reduce_paths -Drvmdk -o "rfc.o" $(MAKEFILE_DIR)../../../driverlib/rfc.c
		@ echo KEIL: Compile rom_crypto.c
		@ $(COMPILER_TOOL) -c --cpu Cortex-M3 -D__EVAL --li -O3 --apcs=interwork -I$(MAKEFILE_DIR)../../.. --c99 --reduce_paths -Drvmdk -o "rom_crypto.o" $(MAKEFILE_DIR)../../../driverlib/rom_crypto.c
		@ echo KEIL: Compile setup.c
		@ $(COMPILER_TOOL) -c --cpu Cortex-M3 -D__EVAL --li -O3 --apcs=interwork -I$(MAKEFILE_DIR)../../.. --c99 --reduce_paths -Drvmdk -o "setup.o" $(MAKEFILE_DIR)../../../driverlib/setup.c
		@ echo KEIL: Compile smph.c
		@ $(COMPILER_TOOL) -c --cpu Cortex-M3 -D__EVAL --li -O3 --apcs=interwork -I$(MAKEFILE_DIR)../../.. --c99 --reduce_paths -Drvmdk -o "smph.o" $(MAKEFILE_DIR)../../../driverlib/smph.c
		@ echo KEIL: Compile ssi.c
		@ $(COMPILER_TOOL) -c --cpu Cortex-M3 -D__EVAL --li -O3 --apcs=interwork -I$(MAKEFILE_DIR)../../.. --c99 --reduce_paths -Drvmdk -o "ssi.o" $(MAKEFILE_DIR)../../../driverlib/ssi.c
		@ echo KEIL: Compile systick.c
		@ $(COMPILER_TOOL) -c --cpu Cortex-M3 -D__EVAL --li -O3 --apcs=interwork -I$(MAKEFILE_DIR)../../.. --c99 --reduce_paths -Drvmdk -o "systick.o" $(MAKEFILE_DIR)../../../driverlib/systick.c
		@ echo KEIL: Compile sys_ctrl.c
		@ $(COMPILER_TOOL) -c --cpu Cortex-M3 -D__EVAL --li -O3 --apcs=interwork -I$(MAKEFILE_DIR)../../.. --c99 --reduce_paths -Drvmdk -o "sys_ctrl.o" $(MAKEFILE_DIR)../../../driverlib/sys_ctrl.c
		@ echo KEIL: Compile timer.c
		@ $(COMPILER_TOOL) -c --cpu Cortex-M3 -D__EVAL --li -O3 --apcs=interwork -I$(MAKEFILE_DIR)../../.. --c99 --reduce_paths -Drvmdk -o "timer.o" $(MAKEFILE_DIR)../../../driverlib/timer.c
		@ echo KEIL: Compile trng.c
		@ $(COMPILER_TOOL) -c --cpu Cortex-M3 -D__EVAL --li -O3 --apcs=interwork -I$(MAKEFILE_DIR)../../.. --c99 --reduce_paths -Drvmdk -o "trng.o" $(MAKEFILE_DIR)../../../driverlib/trng.c
		@ echo KEIL: Compile uart.c
		@ $(COMPILER_TOOL) -c --cpu Cortex-M3 -D__EVAL --li -O3 --apcs=interwork -I$(MAKEFILE_DIR)../../.. --c99 --reduce_paths -Drvmdk -o "uart.o" $(MAKEFILE_DIR)../../../driverlib/uart.c
		@ echo KEIL: Compile udma.c
		@ $(COMPILER_TOOL) -c --cpu Cortex-M3 -D__EVAL --li -O3 --apcs=interwork -I$(MAKEFILE_DIR)../../.. --c99 --reduce_paths -Drvmdk -o "udma.o" $(MAKEFILE_DIR)../../../driverlib/udma.c
		@ echo KEIL: Compile vims.c
		@ $(COMPILER_TOOL) -c --cpu Cortex-M3 -D__EVAL --li -O3 --apcs=interwork -I$(MAKEFILE_DIR)../../.. --c99 --reduce_paths -Drvmdk -o "vims.o" $(MAKEFILE_DIR)../../../driverlib/vims.c
		@ echo KEIL: Compile watchdog.c
		@ $(COMPILER_TOOL) -c --cpu Cortex-M3 -D__EVAL --li -O3 --apcs=interwork -I$(MAKEFILE_DIR)../../.. --c99 --reduce_paths -Drvmdk -o "watchdog.o" $(MAKEFILE_DIR)../../../driverlib/watchdog.c
		@ echo KEIL: Archive driverlib.lib
		@ $(ARCHIVER_TOOL) --create $(MAKEFILE_DIR)driverlib.lib $(MAKEFILE_DIR)adi.o $(MAKEFILE_DIR)aon_batmon.o $(MAKEFILE_DIR)aon_event.o $(MAKEFILE_DIR)aon_ioc.o $(MAKEFILE_DIR)aon_rtc.o $(MAKEFILE_DIR)aon_wuc.o $(MAKEFILE_DIR)aux_adc.o $(MAKEFILE_DIR)aux_smph.o $(MAKEFILE_DIR)aux_tdc.o $(MAKEFILE_DIR)aux_timer.o $(MAKEFILE_DIR)aux_wuc.o $(MAKEFILE_DIR)ccfgread.o $(MAKEFILE_DIR)chipinfo.o $(MAKEFILE_DIR)cpu.o $(MAKEFILE_DIR)crypto.o $(MAKEFILE_DIR)ddi.o $(MAKEFILE_DIR)debug.o $(MAKEFILE_DIR)driverlib_release.o $(MAKEFILE_DIR)event.o $(MAKEFILE_DIR)flash.o $(MAKEFILE_DIR)gpio.o $(MAKEFILE_DIR)i2c.o $(MAKEFILE_DIR)i2s.o $(MAKEFILE_DIR)interrupt.o $(MAKEFILE_DIR)ioc.o $(MAKEFILE_DIR)osc.o $(MAKEFILE_DIR)prcm.o $(MAKEFILE_DIR)pwr_ctrl.o $(MAKEFILE_DIR)rfc.o $(MAKEFILE_DIR)rom_crypto.o $(MAKEFILE_DIR)setup.o $(MAKEFILE_DIR)smph.o $(MAKEFILE_DIR)ssi.o $(MAKEFILE_DIR)systick.o $(MAKEFILE_DIR)sys_ctrl.o $(MAKEFILE_DIR)timer.o $(MAKEFILE_DIR)trng.o $(MAKEFILE_DIR)uart.o $(MAKEFILE_DIR)udma.o $(MAKEFILE_DIR)vims.o $(MAKEFILE_DIR)watchdog.o
		@ rm -f $(MAKEFILE_DIR)*.o

# Deletes previous output and temporary files
clean :
		@ rm -fR $(MAKEFILE_DIR)*.o
		@ rm -fR $(MAKEFILE_DIR)*.lib
