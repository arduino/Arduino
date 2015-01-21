#******************************************************************************
#
# Makefile - Rules for building the driver library.
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
# The base directory
#
ROOT=../../

#
# Include the common make definitions.
#
include ${ROOT}/tools/gcc_scripts/makedefs

#
# Where to find header files that do not live in the source directory.
#
VPATH=..

#
# Where to find header files that do not live in the source directory.
#
IPATH= ..
IPATH+= ../../

#
# The default rule, which causes the driver library to be built.
#
all: ${OBJDIR} ${BINDIR}
all: ${BINDIR}/libdriver.a

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
# Rules for building the driver library.
#
${BINDIR}/libdriver.a: ${OBJDIR}/adc.o
${BINDIR}/libdriver.a: ${OBJDIR}/aes.o
${BINDIR}/libdriver.a: ${OBJDIR}/camera.o
${BINDIR}/libdriver.a: ${OBJDIR}/cpu.o
${BINDIR}/libdriver.a: ${OBJDIR}/crc.o
${BINDIR}/libdriver.a: ${OBJDIR}/des.o
${BINDIR}/libdriver.a: ${OBJDIR}/flash.o
${BINDIR}/libdriver.a: ${OBJDIR}/gpio.o
${BINDIR}/libdriver.a: ${OBJDIR}/hwspinlock.o
${BINDIR}/libdriver.a: ${OBJDIR}/i2c.o
${BINDIR}/libdriver.a: ${OBJDIR}/interrupt.o
${BINDIR}/libdriver.a: ${OBJDIR}/i2s.o
${BINDIR}/libdriver.a: ${OBJDIR}/pin.o
${BINDIR}/libdriver.a: ${OBJDIR}/prcm.o
${BINDIR}/libdriver.a: ${OBJDIR}/sdhost.o
${BINDIR}/libdriver.a: ${OBJDIR}/shamd5.o
${BINDIR}/libdriver.a: ${OBJDIR}/spi.o
${BINDIR}/libdriver.a: ${OBJDIR}/systick.o
${BINDIR}/libdriver.a: ${OBJDIR}/timer.o
${BINDIR}/libdriver.a: ${OBJDIR}/uart.o
${BINDIR}/libdriver.a: ${OBJDIR}/udma.o
${BINDIR}/libdriver.a: ${OBJDIR}/utils.o
${BINDIR}/libdriver.a: ${OBJDIR}/wdt.o

#
# Include the automatically generated dependency files.
#
ifneq (${MAKECMDGOALS},clean)
-include ${wildcard ${OBJDIR}/*.d} __dummy__
endif
