#******************************************************************************
#
# Makefile - Rules for building the FreeRTOS Library.
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
ROOT=../../

#
# Include the common make definitions.
#
include ${ROOT}/tools/gcc_scripts/makedefs

#
# The FreeRTOS base directory.
#
RTOS_SOURCE_DIR=../../third_party/FreeRTOS

#
# Where to find header files that do not live in the current directory.
#
IPATH=../
IPATH+=${RTOS_SOURCE_DIR}
IPATH+=${RTOS_SOURCE_DIR}/../../driverlib/
IPATH+=${RTOS_SOURCE_DIR}/../../inc/
IPATH+=${RTOS_SOURCE_DIR}/source
IPATH+=${RTOS_SOURCE_DIR}/source/include
IPATH+=${RTOS_SOURCE_DIR}/source/portable/MemMang
IPATH+=${RTOS_SOURCE_DIR}/source/portable/GCC/ARM_CM4

#
# Where to find source files that do not live in the current directory.
#
VPATH=../
VPATH+=${RTOS_SOURCE_DIR}
VPATH+=${RTOS_SOURCE_DIR}/source
VPATH+=${RTOS_SOURCE_DIR}/source/portable/MemMang
VPATH+=${RTOS_SOURCE_DIR}/source/portable/GCC/ARM_CM4

#
# Required object file
#
OBJS= ${OBJDIR}/croutine.o    \
      ${OBJDIR}/list.o        \
      ${OBJDIR}/queue.o       \
      ${OBJDIR}/tasks.o       \
      ${OBJDIR}/port.o        \
      ${OBJDIR}/timers.o      \
      ${OBJDIR}/heap_3.o      \
      ${OBJDIR}/osi_freertos.o

#
# The default rule, which causes init to be built.
#
all: ${OBJDIR} ${BINDIR} \
     ${BINDIR}/FreeRTOS.a
	 
#
# The rule to clean out all the build products.
#
clean:
	@rm -rf ${OBJDIR} ${wildcard *~}
	@rm -rf ${BINDIR} ${wildcard *~}
	
#
# The rule to create the target directories.
#
${OBJDIR}:
	@mkdir -p ${OBJDIR}

${BINDIR}:
	@mkdir -p ${BINDIR}

#
# Rules for building the FreeRTOS library.
#
${BINDIR}/FreeRTOS.a: ${OBJS}

#
# Include the automatically generated dependency files.
#
ifneq (${MAKECMDGOALS},clean)
-include ${wildcard ${COMPILER}/*.d} __dummy__
endif


	 



