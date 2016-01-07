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
		@ echo GCC: Compile adi.c
		@ $(COMPILER_TOOL) -mthumb -mcpu=cortex-m3 -Os -Wall -fno-strict-aliasing -pedantic -ffunction-sections -fdata-sections -std=c99 -c --asm -g -isystem $(MAKEFILE_DIR)../../.. -o "adi.o" $(MAKEFILE_DIR)../../../driverlib/adi.c
		@ echo GCC: Compile aon_batmon.c
		@ $(COMPILER_TOOL) -mthumb -mcpu=cortex-m3 -Os -Wall -fno-strict-aliasing -pedantic -ffunction-sections -fdata-sections -std=c99 -c --asm -g -isystem $(MAKEFILE_DIR)../../.. -o "aon_batmon.o" $(MAKEFILE_DIR)../../../driverlib/aon_batmon.c
		@ echo GCC: Compile aon_event.c
		@ $(COMPILER_TOOL) -mthumb -mcpu=cortex-m3 -Os -Wall -fno-strict-aliasing -pedantic -ffunction-sections -fdata-sections -std=c99 -c --asm -g -isystem $(MAKEFILE_DIR)../../.. -o "aon_event.o" $(MAKEFILE_DIR)../../../driverlib/aon_event.c
		@ echo GCC: Compile aon_ioc.c
		@ $(COMPILER_TOOL) -mthumb -mcpu=cortex-m3 -Os -Wall -fno-strict-aliasing -pedantic -ffunction-sections -fdata-sections -std=c99 -c --asm -g -isystem $(MAKEFILE_DIR)../../.. -o "aon_ioc.o" $(MAKEFILE_DIR)../../../driverlib/aon_ioc.c
		@ echo GCC: Compile aon_rtc.c
		@ $(COMPILER_TOOL) -mthumb -mcpu=cortex-m3 -Os -Wall -fno-strict-aliasing -pedantic -ffunction-sections -fdata-sections -std=c99 -c --asm -g -isystem $(MAKEFILE_DIR)../../.. -o "aon_rtc.o" $(MAKEFILE_DIR)../../../driverlib/aon_rtc.c
		@ echo GCC: Compile aon_wuc.c
		@ $(COMPILER_TOOL) -mthumb -mcpu=cortex-m3 -Os -Wall -fno-strict-aliasing -pedantic -ffunction-sections -fdata-sections -std=c99 -c --asm -g -isystem $(MAKEFILE_DIR)../../.. -o "aon_wuc.o" $(MAKEFILE_DIR)../../../driverlib/aon_wuc.c
		@ echo GCC: Compile aux_adc.c
		@ $(COMPILER_TOOL) -mthumb -mcpu=cortex-m3 -Os -Wall -fno-strict-aliasing -pedantic -ffunction-sections -fdata-sections -std=c99 -c --asm -g -isystem $(MAKEFILE_DIR)../../.. -o "aux_adc.o" $(MAKEFILE_DIR)../../../driverlib/aux_adc.c
		@ echo GCC: Compile aux_smph.c
		@ $(COMPILER_TOOL) -mthumb -mcpu=cortex-m3 -Os -Wall -fno-strict-aliasing -pedantic -ffunction-sections -fdata-sections -std=c99 -c --asm -g -isystem $(MAKEFILE_DIR)../../.. -o "aux_smph.o" $(MAKEFILE_DIR)../../../driverlib/aux_smph.c
		@ echo GCC: Compile aux_tdc.c
		@ $(COMPILER_TOOL) -mthumb -mcpu=cortex-m3 -Os -Wall -fno-strict-aliasing -pedantic -ffunction-sections -fdata-sections -std=c99 -c --asm -g -isystem $(MAKEFILE_DIR)../../.. -o "aux_tdc.o" $(MAKEFILE_DIR)../../../driverlib/aux_tdc.c
		@ echo GCC: Compile aux_timer.c
		@ $(COMPILER_TOOL) -mthumb -mcpu=cortex-m3 -Os -Wall -fno-strict-aliasing -pedantic -ffunction-sections -fdata-sections -std=c99 -c --asm -g -isystem $(MAKEFILE_DIR)../../.. -o "aux_timer.o" $(MAKEFILE_DIR)../../../driverlib/aux_timer.c
		@ echo GCC: Compile aux_wuc.c
		@ $(COMPILER_TOOL) -mthumb -mcpu=cortex-m3 -Os -Wall -fno-strict-aliasing -pedantic -ffunction-sections -fdata-sections -std=c99 -c --asm -g -isystem $(MAKEFILE_DIR)../../.. -o "aux_wuc.o" $(MAKEFILE_DIR)../../../driverlib/aux_wuc.c
		@ echo GCC: Compile ccfgread.c
		@ $(COMPILER_TOOL) -mthumb -mcpu=cortex-m3 -Os -Wall -fno-strict-aliasing -pedantic -ffunction-sections -fdata-sections -std=c99 -c --asm -g -isystem $(MAKEFILE_DIR)../../.. -o "ccfgread.o" $(MAKEFILE_DIR)../../../driverlib/ccfgread.c
		@ echo GCC: Compile chipinfo.c
		@ $(COMPILER_TOOL) -mthumb -mcpu=cortex-m3 -Os -Wall -fno-strict-aliasing -pedantic -ffunction-sections -fdata-sections -std=c99 -c --asm -g -isystem $(MAKEFILE_DIR)../../.. -o "chipinfo.o" $(MAKEFILE_DIR)../../../driverlib/chipinfo.c
		@ echo GCC: Compile cpu.c
		@ $(COMPILER_TOOL) -mthumb -mcpu=cortex-m3 -Os -Wall -fno-strict-aliasing -pedantic -ffunction-sections -fdata-sections -std=c99 -c --asm -g -isystem $(MAKEFILE_DIR)../../.. -o "cpu.o" $(MAKEFILE_DIR)../../../driverlib/cpu.c
		@ echo GCC: Compile crypto.c
		@ $(COMPILER_TOOL) -mthumb -mcpu=cortex-m3 -Os -Wall -fno-strict-aliasing -pedantic -ffunction-sections -fdata-sections -std=c99 -c --asm -g -isystem $(MAKEFILE_DIR)../../.. -o "crypto.o" $(MAKEFILE_DIR)../../../driverlib/crypto.c
		@ echo GCC: Compile ddi.c
		@ $(COMPILER_TOOL) -mthumb -mcpu=cortex-m3 -Os -Wall -fno-strict-aliasing -pedantic -ffunction-sections -fdata-sections -std=c99 -c --asm -g -isystem $(MAKEFILE_DIR)../../.. -o "ddi.o" $(MAKEFILE_DIR)../../../driverlib/ddi.c
		@ echo GCC: Compile debug.c
		@ $(COMPILER_TOOL) -mthumb -mcpu=cortex-m3 -Os -Wall -fno-strict-aliasing -pedantic -ffunction-sections -fdata-sections -std=c99 -c --asm -g -isystem $(MAKEFILE_DIR)../../.. -o "debug.o" $(MAKEFILE_DIR)../../../driverlib/debug.c
		@ echo GCC: Compile driverlib_release.c
		@ $(COMPILER_TOOL) -mthumb -mcpu=cortex-m3 -Os -Wall -fno-strict-aliasing -pedantic -ffunction-sections -fdata-sections -std=c99 -c --asm -g -isystem $(MAKEFILE_DIR)../../.. -o "driverlib_release.o" $(MAKEFILE_DIR)../../../driverlib/driverlib_release.c
		@ echo GCC: Compile event.c
		@ $(COMPILER_TOOL) -mthumb -mcpu=cortex-m3 -Os -Wall -fno-strict-aliasing -pedantic -ffunction-sections -fdata-sections -std=c99 -c --asm -g -isystem $(MAKEFILE_DIR)../../.. -o "event.o" $(MAKEFILE_DIR)../../../driverlib/event.c
		@ echo GCC: Compile flash.c
		@ $(COMPILER_TOOL) -mthumb -mcpu=cortex-m3 -Os -Wall -fno-strict-aliasing -pedantic -ffunction-sections -fdata-sections -std=c99 -c --asm -g -isystem $(MAKEFILE_DIR)../../.. -o "flash.o" $(MAKEFILE_DIR)../../../driverlib/flash.c
		@ echo GCC: Compile gpio.c
		@ $(COMPILER_TOOL) -mthumb -mcpu=cortex-m3 -Os -Wall -fno-strict-aliasing -pedantic -ffunction-sections -fdata-sections -std=c99 -c --asm -g -isystem $(MAKEFILE_DIR)../../.. -o "gpio.o" $(MAKEFILE_DIR)../../../driverlib/gpio.c
		@ echo GCC: Compile i2c.c
		@ $(COMPILER_TOOL) -mthumb -mcpu=cortex-m3 -Os -Wall -fno-strict-aliasing -pedantic -ffunction-sections -fdata-sections -std=c99 -c --asm -g -isystem $(MAKEFILE_DIR)../../.. -o "i2c.o" $(MAKEFILE_DIR)../../../driverlib/i2c.c
		@ echo GCC: Compile i2s.c
		@ $(COMPILER_TOOL) -mthumb -mcpu=cortex-m3 -Os -Wall -fno-strict-aliasing -pedantic -ffunction-sections -fdata-sections -std=c99 -c --asm -g -isystem $(MAKEFILE_DIR)../../.. -o "i2s.o" $(MAKEFILE_DIR)../../../driverlib/i2s.c
		@ echo GCC: Compile interrupt.c
		@ $(COMPILER_TOOL) -mthumb -mcpu=cortex-m3 -Os -Wall -fno-strict-aliasing -pedantic -ffunction-sections -fdata-sections -std=c99 -c --asm -g -isystem $(MAKEFILE_DIR)../../.. -o "interrupt.o" $(MAKEFILE_DIR)../../../driverlib/interrupt.c
		@ echo GCC: Compile ioc.c
		@ $(COMPILER_TOOL) -mthumb -mcpu=cortex-m3 -Os -Wall -fno-strict-aliasing -pedantic -ffunction-sections -fdata-sections -std=c99 -c --asm -g -isystem $(MAKEFILE_DIR)../../.. -o "ioc.o" $(MAKEFILE_DIR)../../../driverlib/ioc.c
		@ echo GCC: Compile osc.c
		@ $(COMPILER_TOOL) -mthumb -mcpu=cortex-m3 -Os -Wall -fno-strict-aliasing -pedantic -ffunction-sections -fdata-sections -std=c99 -c --asm -g -isystem $(MAKEFILE_DIR)../../.. -o "osc.o" $(MAKEFILE_DIR)../../../driverlib/osc.c
		@ echo GCC: Compile prcm.c
		@ $(COMPILER_TOOL) -mthumb -mcpu=cortex-m3 -Os -Wall -fno-strict-aliasing -pedantic -ffunction-sections -fdata-sections -std=c99 -c --asm -g -isystem $(MAKEFILE_DIR)../../.. -o "prcm.o" $(MAKEFILE_DIR)../../../driverlib/prcm.c
		@ echo GCC: Compile pwr_ctrl.c
		@ $(COMPILER_TOOL) -mthumb -mcpu=cortex-m3 -Os -Wall -fno-strict-aliasing -pedantic -ffunction-sections -fdata-sections -std=c99 -c --asm -g -isystem $(MAKEFILE_DIR)../../.. -o "pwr_ctrl.o" $(MAKEFILE_DIR)../../../driverlib/pwr_ctrl.c
		@ echo GCC: Compile rfc.c
		@ $(COMPILER_TOOL) -mthumb -mcpu=cortex-m3 -Os -Wall -fno-strict-aliasing -pedantic -ffunction-sections -fdata-sections -std=c99 -c --asm -g -isystem $(MAKEFILE_DIR)../../.. -o "rfc.o" $(MAKEFILE_DIR)../../../driverlib/rfc.c
		@ echo GCC: Compile rom_crypto.c
		@ $(COMPILER_TOOL) -mthumb -mcpu=cortex-m3 -Os -Wall -fno-strict-aliasing -pedantic -ffunction-sections -fdata-sections -std=c99 -c --asm -g -isystem $(MAKEFILE_DIR)../../.. -o "rom_crypto.o" $(MAKEFILE_DIR)../../../driverlib/rom_crypto.c
		@ echo GCC: Compile setup.c
		@ $(COMPILER_TOOL) -mthumb -mcpu=cortex-m3 -Os -Wall -fno-strict-aliasing -pedantic -ffunction-sections -fdata-sections -std=c99 -c --asm -g -isystem $(MAKEFILE_DIR)../../.. -o "setup.o" $(MAKEFILE_DIR)../../../driverlib/setup.c
		@ echo GCC: Compile smph.c
		@ $(COMPILER_TOOL) -mthumb -mcpu=cortex-m3 -Os -Wall -fno-strict-aliasing -pedantic -ffunction-sections -fdata-sections -std=c99 -c --asm -g -isystem $(MAKEFILE_DIR)../../.. -o "smph.o" $(MAKEFILE_DIR)../../../driverlib/smph.c
		@ echo GCC: Compile ssi.c
		@ $(COMPILER_TOOL) -mthumb -mcpu=cortex-m3 -Os -Wall -fno-strict-aliasing -pedantic -ffunction-sections -fdata-sections -std=c99 -c --asm -g -isystem $(MAKEFILE_DIR)../../.. -o "ssi.o" $(MAKEFILE_DIR)../../../driverlib/ssi.c
		@ echo GCC: Compile systick.c
		@ $(COMPILER_TOOL) -mthumb -mcpu=cortex-m3 -Os -Wall -fno-strict-aliasing -pedantic -ffunction-sections -fdata-sections -std=c99 -c --asm -g -isystem $(MAKEFILE_DIR)../../.. -o "systick.o" $(MAKEFILE_DIR)../../../driverlib/systick.c
		@ echo GCC: Compile sys_ctrl.c
		@ $(COMPILER_TOOL) -mthumb -mcpu=cortex-m3 -Os -Wall -fno-strict-aliasing -pedantic -ffunction-sections -fdata-sections -std=c99 -c --asm -g -isystem $(MAKEFILE_DIR)../../.. -o "sys_ctrl.o" $(MAKEFILE_DIR)../../../driverlib/sys_ctrl.c
		@ echo GCC: Compile timer.c
		@ $(COMPILER_TOOL) -mthumb -mcpu=cortex-m3 -Os -Wall -fno-strict-aliasing -pedantic -ffunction-sections -fdata-sections -std=c99 -c --asm -g -isystem $(MAKEFILE_DIR)../../.. -o "timer.o" $(MAKEFILE_DIR)../../../driverlib/timer.c
		@ echo GCC: Compile trng.c
		@ $(COMPILER_TOOL) -mthumb -mcpu=cortex-m3 -Os -Wall -fno-strict-aliasing -pedantic -ffunction-sections -fdata-sections -std=c99 -c --asm -g -isystem $(MAKEFILE_DIR)../../.. -o "trng.o" $(MAKEFILE_DIR)../../../driverlib/trng.c
		@ echo GCC: Compile uart.c
		@ $(COMPILER_TOOL) -mthumb -mcpu=cortex-m3 -Os -Wall -fno-strict-aliasing -pedantic -ffunction-sections -fdata-sections -std=c99 -c --asm -g -isystem $(MAKEFILE_DIR)../../.. -o "uart.o" $(MAKEFILE_DIR)../../../driverlib/uart.c
		@ echo GCC: Compile udma.c
		@ $(COMPILER_TOOL) -mthumb -mcpu=cortex-m3 -Os -Wall -fno-strict-aliasing -pedantic -ffunction-sections -fdata-sections -std=c99 -c --asm -g -isystem $(MAKEFILE_DIR)../../.. -o "udma.o" $(MAKEFILE_DIR)../../../driverlib/udma.c
		@ echo GCC: Compile vims.c
		@ $(COMPILER_TOOL) -mthumb -mcpu=cortex-m3 -Os -Wall -fno-strict-aliasing -pedantic -ffunction-sections -fdata-sections -std=c99 -c --asm -g -isystem $(MAKEFILE_DIR)../../.. -o "vims.o" $(MAKEFILE_DIR)../../../driverlib/vims.c
		@ echo GCC: Compile watchdog.c
		@ $(COMPILER_TOOL) -mthumb -mcpu=cortex-m3 -Os -Wall -fno-strict-aliasing -pedantic -ffunction-sections -fdata-sections -std=c99 -c --asm -g -isystem $(MAKEFILE_DIR)../../.. -o "watchdog.o" $(MAKEFILE_DIR)../../../driverlib/watchdog.c
		@ echo GCC: Archive driverlib.lib
		@ $(ARCHIVER_TOOL) rcs $(MAKEFILE_DIR)driverlib.lib $(MAKEFILE_DIR)adi.o $(MAKEFILE_DIR)aon_batmon.o $(MAKEFILE_DIR)aon_event.o $(MAKEFILE_DIR)aon_ioc.o $(MAKEFILE_DIR)aon_rtc.o $(MAKEFILE_DIR)aon_wuc.o $(MAKEFILE_DIR)aux_adc.o $(MAKEFILE_DIR)aux_smph.o $(MAKEFILE_DIR)aux_tdc.o $(MAKEFILE_DIR)aux_timer.o $(MAKEFILE_DIR)aux_wuc.o $(MAKEFILE_DIR)ccfgread.o $(MAKEFILE_DIR)chipinfo.o $(MAKEFILE_DIR)cpu.o $(MAKEFILE_DIR)crypto.o $(MAKEFILE_DIR)ddi.o $(MAKEFILE_DIR)debug.o $(MAKEFILE_DIR)driverlib_release.o $(MAKEFILE_DIR)event.o $(MAKEFILE_DIR)flash.o $(MAKEFILE_DIR)gpio.o $(MAKEFILE_DIR)i2c.o $(MAKEFILE_DIR)i2s.o $(MAKEFILE_DIR)interrupt.o $(MAKEFILE_DIR)ioc.o $(MAKEFILE_DIR)osc.o $(MAKEFILE_DIR)prcm.o $(MAKEFILE_DIR)pwr_ctrl.o $(MAKEFILE_DIR)rfc.o $(MAKEFILE_DIR)rom_crypto.o $(MAKEFILE_DIR)setup.o $(MAKEFILE_DIR)smph.o $(MAKEFILE_DIR)ssi.o $(MAKEFILE_DIR)systick.o $(MAKEFILE_DIR)sys_ctrl.o $(MAKEFILE_DIR)timer.o $(MAKEFILE_DIR)trng.o $(MAKEFILE_DIR)uart.o $(MAKEFILE_DIR)udma.o $(MAKEFILE_DIR)vims.o $(MAKEFILE_DIR)watchdog.o
		@ rm -f $(MAKEFILE_DIR)*.o

# Deletes previous output and temporary files
clean :
		@ rm -fR $(MAKEFILE_DIR)*.o
		@ rm -fR $(MAKEFILE_DIR)*.lib
