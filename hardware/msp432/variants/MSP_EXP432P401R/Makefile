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
IPATH=. ../inc ../inc/CMSIS

#
# The default rule, which causes the driver library to be built.
#
all: lib/${COMPILER}-cm4f
all: lib/${COMPILER}-cm4f/emt432LP.m4fg.a
all:
	cp lib/${COMPILER}-cm4f/emt432LP.m4fg.a lib/youremt432LP.m4fg.lib
#
# The rule to clean out all the build products.
#
clean:
	@rm -rf lib/${COMPILER}-cm4f ${wildcard *~}
	@rm lib/youremt432LP.m4fg.lib
objclean:
	@rm -f lib/${COMPILER}-cm4f/*.o
	@rm -f lib/${COMPILER}-cm4f/*.d
#
# The rule to create the target directory.
#
lib/${COMPILER}-cm4f:
	@mkdir -p lib/${COMPILER}-cm4f

#
# Rules for building the driver library.
#
lib/${COMPILER}-cm4f/emt432LP.m4fg.a: lib/${COMPILER}-cm4f/pins.o
lib/${COMPILER}-cm4f/emt432LP.m4fg.a: lib/${COMPILER}-cm4f/Board_init.o

#
# Include the automatically generated dependency files.
#
ifneq (${MAKECMDGOALS},clean)
-include ${wildcard lib/${COMPILER}-cm4f/*.d} __dummy__
endif
