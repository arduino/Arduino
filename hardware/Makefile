# Makefile for the Wiring++ framework
#
# Copyright (c) 2013, Robert Wessels
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met: 
#
# 1. Redistributions of source code must retain the above copyright notice, this
#   list of conditions and the following disclaimer. 
# 2. Redistributions in binary form must reproduce the above copyright notice,
#   this list of conditions and the following disclaimer in the documentation
#   and/or other materials provided with the distribution. 
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
# ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
# DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
# ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
# (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
# LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
# ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
# SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
# The views and conclusions contained in the software and documentation are those
# of the authors and should not be interpreted as representing official policies, 
# either expressed or implied, of the FreeBSD Project.

######################################
include Variables.mk
BOARD_PATH := $(APPLICATION_PATH)/hardware/$(PLATFORM)/variants/$(BOARD)
$(info Loading board: $(BOARD_PATH)/Board.mk)
ifeq (,$(wildcard $(BOARD_PATH)/Board.mk))
$(error Missing Board.mk in $(BOARD_PATH))
endif
include $(BOARD_PATH)/Board.mk
ARCH_CORE_PATH := $(APPLICATION_PATH)/hardware/$(ARCH)
$(info Loading architecture: $(ARCH_CORE_PATH)/Arch.mk)
ifeq (,$(wildcard $(ARCH_CORE_PATH)/Arch.mk))
$(error Missing Arch.mk in $(ARCH_CORE_PATH))
endif
include $(ARCH_CORE_PATH)/Arch.mk

ifeq ($(OS),Windows_NT)
$(shell set CYGWIN = nodosfilewarning)
RM = $(shell rmdir /S /Q build >nul 2>nul)
MKDIR = mkdir
SHELL = C:/Windows/System32/cmd.exe
else
RM = rm -rf build
MKDIR = mkdir -p
endif
######################################

BOARD_PATH := $(APPLICATION_PATH)/hardware/$(PLATFORM)/variants/$(BOARD)
#COMMON_LIB_PATH := $(APPLICATION_PATH)/libraries
ARCH_LIB_PATH := $(APPLICATION_PATH)/hardware/$(ARCH)/libraries
ARCH_CORE_PATH := $(APPLICATION_PATH)/hardware/$(ARCH)/cores/$(ARCH)
#COMMON_CORE_PATH := $(APPLICATION_PATH)/cores/Common
#DIRS := $(COMMON_LIB_PATH) $(USER_LIB_PATH) $(BOARD_PATH) $(CORES) $(ARCH_CORE_PATH) $(COMMON_CORE_PATH) $(ARCH_LIB_PATH)
DIRS := $(USER_LIB_PATH) $(BOARD_PATH) $(CORES) $(ARCH_CORE_PATH) $(ARCH_LIB_PATH)
INCLUDE_DIRS = $(foreach dir, $(DIRS), ${sort ${dir ${wildcard ${dir}/*/ ${dir}/*/utility/}}})
INCLUDE_LIST += $(foreach includedir,$(INCLUDE_DIRS),-I$(includedir))
######################################

# Use the preprocessor to find the dependencies. What we are really after is what libraries the Sketch depends on
define deps
$(foreach SRC, $1, $(shell $(CC) $(MCU_FLAG) -MM $(INCLUDE_LIST) $(CPPFLAGS) $(SRC)))
endef

# (Ab)use the dependency tree to figure out what libraries the file in question depends on and add them to LIBSRCS
define get_lib_dirs
$(if $(findstring libraries, ${1}), \
	$(eval _LIBDIRS = $(filter-out ${1}, $(_LIBDIRS))) \
	$(eval _LIBDIRS += ${1}))
endef

# Recursively compute library dependencies for the sources passed as argument
# Initially the Sketch files are passed to this function
# It will then recurse until no further dependencies are found
# Libraries can depend on libraries can depend on libraries etc
define compute_dependencies
$(eval _LIBDIRS :=)
$(eval _SRCS := ${1})
# Compute dependencies for the sources
$(eval _LIBDEP = $(call deps, $(_SRCS)))
# Compute the library directories for dependencies
$(foreach dep, $(dir $(_LIBDEP)), $(call get_lib_dirs, $(dep)))
# Filter out any library directories we already know about
$(eval _LIBDIRS = $(filter-out $(LIBDIRS), $(_LIBDIRS)))
# If there are dependencies then find out if they depend on anything otherwise fall through and return
$(if $(_LIBDIRS), \
	# Include the utility directory in the search for dependencies
	$(eval _LIBDIRS += $(addsuffix utility/,$(_LIBDIRS))) \
	# Store the current dependencies for use later on
	$(eval LIBDIRS += $(_LIBDIRS)) \
	# Compute the source files
	$(eval _SRCS = $(wildcard $(patsubst %,%*.c,$(_LIBDIRS)))) \
	$(eval _SRCS += $(wildcard $(patsubst %,%*.cpp,$(_LIBDIRS)))) \
	# Recursively call this function to compute dependencies for the source files
	$(call compute_dependencies, $(_SRCS)),)
endef

ifeq ($(OS),Windows_NT)
define size
$(eval _SIZE = $(word 7, $(shell $(SIZE) build/$(SKETCH_NAME).elf)))
$(eval _PCTUSED = $(shell cmd /c set /a $(_SIZE)*100/$(FLASH_SIZE)))
$(eval $(info Binary sketch size: $(_SIZE) bytes (of a $(FLASH_SIZE) byte maximum) - $(_PCTUSED)% used))
endef
else
define size
$(eval _SIZE = $(word 7, $(shell $(SIZE) build/$(SKETCH_NAME).elf)))
$(eval _PCTUSED = $(shell echo $$(($(_SIZE)*100/$(FLASH_SIZE)))))
$(eval $(info Binary sketch size: $(_SIZE) bytes (of a $(FLASH_SIZE) byte maximum) - $(_PCTUSED)% used))
endef
endif

define compute_srcs
$(eval DEP_LIB_C_SRCS = $(wildcard $(patsubst %,%*.S,$(LIBDIRS))))
$(eval TMP_OBJS = $(patsubst $(APPLICATION_PATH)/%.S,build/%.o,$(DEP_LIB_C_SRCS)))
$(eval OBJS += $(patsubst $(USER_LIB_PATH)/%.S,build/user_libs/%.o,$(TMP_OBJS)))
$(eval DEP_LIB_C_SRCS = $(wildcard $(patsubst %,%*.c,$(LIBDIRS))))
$(eval TMP_OBJS = $(patsubst $(APPLICATION_PATH)/%.c,build/%.o,$(DEP_LIB_C_SRCS)))
$(eval OBJS += $(patsubst $(USER_LIB_PATH)/%.c,build/user_libs/%.o,$(TMP_OBJS)))
$(eval DEP_LIB_CPP_SRCS = $(wildcard $(patsubst %,%*.cpp,$(LIBDIRS))))
$(eval TMP_OBJS = $(patsubst $(APPLICATION_PATH)/%.cpp,build/%.o,$(DEP_LIB_CPP_SRCS)))
$(eval OBJS += $(patsubst $(USER_LIB_PATH)/%.cpp,build/user_libs/%.o,$(TMP_OBJS)))
endef

######################################
CORE_C_SRCS = $(wildcard $(ARCH_CORE_PATH)/*.c)
OBJS += $(patsubst $(APPLICATION_PATH)/%.c,build/%.o,$(CORE_C_SRCS))

CORE_AS_SRCS = $(wildcard $(ARCH_CORE_PATH)/*.S)
OBJS += $(patsubst $(APPLICATION_PATH)/%.S,build/%.o,$(CORE_AS_SRCS))

CORE_CPP_SRCS = $(wildcard $(ARCH_CORE_PATH)/*.cpp)
OBJS += $(patsubst $(APPLICATION_PATH)/%.cpp,build/%.o,$(CORE_CPP_SRCS))

#CORE_COMMON_C_SRCS = $(wildcard $(COMMON_CORE_PATH)/*.c)
#OBJS += $(patsubst $(APPLICATION_PATH)/%.c,build/%.o,$(CORE_COMMON_C_SRCS))

#CORE_COMMON_AS_SRCS = $(wildcard $(COMMON_CORE_PATH)/*.S)
#OBJS += $(patsubst $(APPLICATION_PATH)/%.S,build/%.o,$(CORE_COMMON_AS_SRCS))

#CORE_COMMON_CPP_SRCS = $(wildcard $(COMMON_CORE_PATH)/*.cpp)
#OBJS += $(patsubst $(APPLICATION_PATH)/%.cpp,build/%.o,$(CORE_COMMON_CPP_SRCS))

BOARD_CPP_SRCS = $(wildcard $(BOARD_PATH)/*.cpp)
OBJS += $(patsubst $(APPLICATION_PATH)/%.cpp,build/%.o,$(BOARD_CPP_SRCS))

OBJS += $(patsubst %.c,build/%.o,$(EXTRA_SOURCES))

OBJS += $(patsubst %.S,build/%.o,$(EXTRA_SOURCES))

OBJS += $(patsubst %.cpp,build/%.o,$(EXTRA_SOURCES) $(addsuffix .cpp, $(SKETCH_NAME)))

# Compute library dependencies for the Sketch files
$(eval $(call compute_dependencies, $(addsuffix .cpp, $(SKETCH_NAME)) $(EXTRA_SOURCES)))
$(eval $(call compute_srcs))

######################################
all: build/$(SKETCH_NAME).bin

build/$(SKETCH_NAME).elf: build/libEnergia.a
	$(info Linking $@)
	$(VERBOSE)$(CC) $(LDFLAGS) -o $@ -Lbuild build/libEnergia.a -lc -lm

%.bin: %.elf
	$(info Creating $@)
	$(VERBOSE)$(OBJCOPY) $(OBJCOPY_FLAGS) $< $@
	$(VERBOSE)$(OBJDUMP) -h -S $< > build/$(SKETCH_NAME).lss
	$(call size)
	$(info >>>> Done <<<<)

build/libEnergia.a: $(OBJS)
	$(info Linking $@)
	$(VERBOSE)$(AR) rcs $@ $(OBJS)

# Sketch sources
build/%.o: %.c
ifeq ($(OS),Windows_NT)
	$(shell mkdir $(dir $(subst /,\,$@)) >nul 2>nul)
else
	@mkdir -p $(dir $@)
endif
	$(info Compiling $@)
	$(VERBOSE)$(CC) $(MCU_FLAG) $(CFLAGS) $(INCLUDE_LIST) -c -o $@ $<

build/%.o: %.S
ifeq ($(OS),Windows_NT)
	$(shell mkdir $(dir $(subst /,\,$@)) >nul 2>nul)
else
	@mkdir -p $(dir $@)
endif
	$(info Compiling $@)
	$(VERBOSE)$(CC) $(MCU_FLAG) $(ASFLAGS) $(INCLUDE_LIST) -c -o $@ $<

build/%.o: %.cpp
ifeq ($(OS),Windows_NT)
	$(shell mkdir $(dir $(subst /,\,$@)) >nul 2>nul)
else
	@mkdir -p $(dir $@)
endif
	$(info Compiling $@)
	$(VERBOSE)$(CXX) $(MCU_FLAG) $(CPPFLAGS) $(INCLUDE_LIST) -c -o $@ $<

# Core libraries and core sources
build/%.o: $(APPLICATION_PATH)/%.c
ifeq ($(OS),Windows_NT)
	$(shell mkdir $(dir $(subst /,\,$@)) >nul 2>nul)
else
	@mkdir -p $(dir $@)
endif
	$(info Compiling $@)
	$(VERBOSE)$(CC) $(MCU_FLAG) $(CFLAGS) $(INCLUDE_LIST) -c -o $@ $<

build/%.o: $(APPLICATION_PATH)/%.S
ifeq ($(OS),Windows_NT)
	$(shell mkdir $(dir $(subst /,\,$@)) >nul 2>nul)
else
	@mkdir -p $(dir $@)
endif
	$(info Compiling $@)
	$(VERBOSE)$(CC) $(MCU_FLAG) $(ASFLAGS) $(INCLUDE_LIST) -c -o $@ $<

build/%.o: $(APPLICATION_PATH)/%.cpp
ifeq ($(OS),Windows_NT)
	$(shell mkdir $(dir $(subst /,\,$@)) >nul 2>nul)
else
	@mkdir -p $(dir $@)
endif
	$(info Compiling $@)
	$(VERBOSE)$(CXX) $(MCU_FLAG) $(CPPFLAGS) $(INCLUDE_LIST) -c -o $@ $<

# User libraries
build/user_libs/%.o: $(USER_LIB_PATH)/%.c
ifeq ($(OS),Windows_NT)
	$(shell mkdir $(dir $(subst /,\,$@)) >nul 2>nul)
else
	@mkdir -p $(dir $@)
endif
	$(info Compiling $@)
	$(VERBOSE)$(CC) $(MCU_FLAG) $(CFLAGS) $(INCLUDE_LIST) -c -o $@ $<

build/user_libs/%.o: $(USER_LIB_PATH)/%.S
ifeq ($(OS),Windows_NT)
	$(shell mkdir $(dir $(subst /,\,$@)) >nul 2>nul)
else
	@mkdir -p $(dir $@)
endif
	$(info Compiling $@)
	$(VERBOSE)$(CC) $(MCU_FLAG) $(ASFLAGS) $(INCLUDE_LIST) -c -o $@ $<

build/user_libs/%.o: $(USER_LIB_PATH)/%.cpp
ifeq ($(OS),Windows_NT)
	$(shell mkdir $(dir $(subst /,\,$@)) >nul 2>nul)
else
	@mkdir -p $(dir $@)
endif
	$(info Compiling $@)
	$(VERBOSE)$(CXX) $(MCU_FLAG) $(CPPFLAGS) $(INCLUDE_LIST) -c -o $@ $<

.PHONY: clean
clean:
	$(info >>>> Clean <<<<)
	$(RM)

.PHONY: upload
upload: build/$(SKETCH_NAME).bin
	$(UPLOAD_COMMAND)
