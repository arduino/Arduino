#******************************************************************************
#
# Makefile - Rules for building the SimpleLink library.
#
#  Copyright (C) 2014 Texas Instruments Incorporated - http:#www.ti.com/
#
#
#  Redistribution and use in source and binary forms, with or without
#  modification, are permitted provided that the following conditions
#  are met:
#
#    Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
#
#    Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the
#    distribution.
#
#    Neither the name of Texas Instruments Incorporated nor the names of
#    its contributors may be used to endorse or promote products derived
#    from this software without specific prior written permission.
#
#  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
#  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
#  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
#  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
#  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
#  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
#  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
#  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
#  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
#  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
#  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
#*****************************************************************************

#
# The base directory.
#
ROOT=../..

#
# Set the target based on command line parameter 'target'.
#
# If target is set to NONOS then build a non-os version of SimpleLink Library
# else an os version 
#
ifneq "${target}" "NONOS"
TARGET=${BINDIR}/libsimplelink.a
OBJDIR=obj_os
else
TARGET=${BINDIR}/libsimplelink_nonos.a
OBJDIR=obj_nonos
endif

#
# Include the common make definitions.
#
include ${ROOT}/tools/gcc_scripts/makedefs


ifneq "${target}" "NONOS"
CFLAGS+=-DSL_PLATFORM_MULTI_THREADED
endif

CFLAGS+=-DSL_FULL
	

#
# Where to find source files that do not live in this directory.
#
VPATH=..
VPATH+=../source

#
# Where to find header files that do not live in the source directory.
#
IPATH=..
IPATH+=../..
IPATH+=../include
IPATH+=../source
IPATH+=../../oslib
IPATH+=../../driverlib
IPATH+=../../inc

#
# The default rule, which causes the driver library to be built.
#
all: ${OBJDIR} ${BINDIR}
all: ${TARGET}



#
# The rule to clean out all the build products.
#
clean:
	@rm -rf obj_nonos ${wildcard *~}
	@rm -rf obj_os    ${wildcard *~}
	@rm -rf ${BINDIR} ${wildcard *~}


#
# The rule to create the target directories.
#
${OBJDIR}:
	@mkdir -p ${OBJDIR}

${BINDIR}:
	@mkdir -p ${BINDIR}


#
# Rules for building the Simplelink library with os support.
#
${TARGET}: ${OBJDIR}/cc_pal.o
${TARGET}: ${OBJDIR}/device.o
${TARGET}: ${OBJDIR}/driver.o
${TARGET}: ${OBJDIR}/flowcont.o
${TARGET}: ${OBJDIR}/netapp.o
${TARGET}: ${OBJDIR}/netcfg.o
${TARGET}: ${OBJDIR}/nonos.o
${TARGET}: ${OBJDIR}/fs.o
${TARGET}: ${OBJDIR}/socket.o
${TARGET}: ${OBJDIR}/spawn.o
${TARGET}: ${OBJDIR}/wlan.o


#
# Include the automatically generated dependency files.
#
ifneq (${MAKECMDGOALS},clean)
-include ${wildcard ${OBJDIR}/*.d} __dummy__
endif
