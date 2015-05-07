#******************************************************************************
#
# Makefile.driverlib-cm4f - Rules for building the driver library.
#
# Copyright (c) 2005-2012 Texas Instruments Incorporated.  All rights reserved.
# Software License Agreement
# 
# Texas Instruments (TI) is supplying this software for use solely and
# exclusively on TI's microcontroller products. The software is owned by
# TI and/or its suppliers, and is protected under applicable copyright
# laws. You may not combine this software with "viral" open-source
# software in order to form a larger program.
# 
# THIS SOFTWARE IS PROVIDED "AS IS" AND WITH ALL FAULTS.
# NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT
# NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
# A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. TI SHALL NOT, UNDER ANY
# CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR CONSEQUENTIAL
# DAMAGES, FOR ANY REASON WHATSOEVER.
# 
# This is part of revision 9453 of the Stellaris Peripheral Driver Library.
#
#******************************************************************************

#
# Defines the directory suffix that this project uses.
#
SUFFIX=-cm4f

#
# Set the processor variant.
#
VARIANT=cm4f
TARGET=TARGET_IS_MSP432P4XX
PART=__MSP432P401R__
#
# The base directory for StellarisWare.
#
ROOT=.

#
# Include the common make definitions.
#
include ${ROOT}/makedefs

#
# Where to find header files that do not live in the source directory.
#
IPATH=. ../inc ../inc/CMSIS MSP432P4xx

#
# The default rule, which causes the driver library to be built.
#
all: ${COMPILER}-cm4f
all: ${COMPILER}-cm4f/libdriver-cm4f.a
all:
	cp ${COMPILER}-cm4f/libdriver-cm4f.a yourlibdriverlib.a
#
# The rule to clean out all the build products.
#
clean:
	@rm -rf ${COMPILER}-cm4f ${wildcard *~}

objclean:
	@rm -f ${COMPILER}-cm4f/*.o
	@rm -f ${COMPILER}-cm4f/*.d
#
# The rule to create the target directory.
#
${COMPILER}-cm4f:
	@mkdir -p ${COMPILER}-cm4f

#
# Rules for building the driver library.
#
${COMPILER}-cm4f/libdriver-cm4f.a: ${COMPILER}-cm4f/adc14.o
${COMPILER}-cm4f/libdriver-cm4f.a: ${COMPILER}-cm4f/aes256.o
${COMPILER}-cm4f/libdriver-cm4f.a: ${COMPILER}-cm4f/comp_e.o
${COMPILER}-cm4f/libdriver-cm4f.a: ${COMPILER}-cm4f/cpu.o
${COMPILER}-cm4f/libdriver-cm4f.a: ${COMPILER}-cm4f/crc32.o
${COMPILER}-cm4f/libdriver-cm4f.a: ${COMPILER}-cm4f/cs.o
${COMPILER}-cm4f/libdriver-cm4f.a: ${COMPILER}-cm4f/dma.o
${COMPILER}-cm4f/libdriver-cm4f.a: ${COMPILER}-cm4f/flash.o
${COMPILER}-cm4f/libdriver-cm4f.a: ${COMPILER}-cm4f/fpu.o
${COMPILER}-cm4f/libdriver-cm4f.a: ${COMPILER}-cm4f/gpio.o
${COMPILER}-cm4f/libdriver-cm4f.a: ${COMPILER}-cm4f/i2c.o
${COMPILER}-cm4f/libdriver-cm4f.a: ${COMPILER}-cm4f/interrupt.o
${COMPILER}-cm4f/libdriver-cm4f.a: ${COMPILER}-cm4f/mpu.o
${COMPILER}-cm4f/libdriver-cm4f.a: ${COMPILER}-cm4f/pcm.o
${COMPILER}-cm4f/libdriver-cm4f.a: ${COMPILER}-cm4f/pmap.o
${COMPILER}-cm4f/libdriver-cm4f.a: ${COMPILER}-cm4f/pss.o
${COMPILER}-cm4f/libdriver-cm4f.a: ${COMPILER}-cm4f/ref_a.o
${COMPILER}-cm4f/libdriver-cm4f.a: ${COMPILER}-cm4f/reset.o
${COMPILER}-cm4f/libdriver-cm4f.a: ${COMPILER}-cm4f/rtc_c.o
${COMPILER}-cm4f/libdriver-cm4f.a: ${COMPILER}-cm4f/spi.o
${COMPILER}-cm4f/libdriver-cm4f.a: ${COMPILER}-cm4f/sysctl.o
${COMPILER}-cm4f/libdriver-cm4f.a: ${COMPILER}-cm4f/systick.o
${COMPILER}-cm4f/libdriver-cm4f.a: ${COMPILER}-cm4f/timer32.o
${COMPILER}-cm4f/libdriver-cm4f.a: ${COMPILER}-cm4f/timer_a.o
${COMPILER}-cm4f/libdriver-cm4f.a: ${COMPILER}-cm4f/uart.o
${COMPILER}-cm4f/libdriver-cm4f.a: ${COMPILER}-cm4f/wdt_a.o

#
# Include the automatically generated dependency files.
#
ifneq (${MAKECMDGOALS},clean)
-include ${wildcard ${COMPILER}-cm4f/*.d} __dummy__
endif
