#
#  Example makefile to build a simple CC3200 executable using:
#      o a "closure" of a pre-configured TI-RTOS with MT wiring
#      o the CC3200 simplelink SDK, and
#      o the TI arm compiler
#
TREE_ROOT = $(firstword $(subst /src/, /src/,$(CURDIR)))

# external pre-requisites (modify these to suit your environment):
#    CLOSURE - location of the output of the "closure" tool applied
#              to some configuration of TI-RTOS
#    SDKROOT - installation directory of the CC3200 SDK
#    CCROOT  - installation directory of the TI Arm compiler
#

# (if present) include definitions of the macros described above
include Variables.mk
BOARD_DIR := $(APPLICATION_PATH)/hardware/$(PLATFORM)/targets/$(BOARD)
include $(BOARD_DIR)/Board.mk

ifeq ($(OS),Windows_NT)
$(shell set CYGWIN = nodosfilewarning)
RM = $(shell rmdir /S /Q build >nul 2>nul)
MKDIR = mkdir
SHELL = C:/Windows/System32/cmd.exe
else
RM = rm -rf build
MKDIR = mkdir -p
endif

$(info CCROOT $(CCROOT))
$(info SDKROOT $(SDKROOT))
$(info CLOSURE $(CLOSURE))
$(info MAINSKETCH $(MAINSKETCH))

# Use the preprocessor to find the dependencies. What we are really after is what libraries the Sketch depends on
define deps
$(foreach SRC, $1, $(shell $(CC) $(MCU_FLAG) $(CCOPTS) -MM $(CPPFLAGS) $(SRC)))
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

define size
$(eval _SIZE = $(shell $(SIZE) $(MAINSKETCH).elf))
$(eval $(info Binary sketch size: $(word 10, $(_SIZE)) bytes (of a $(FLASH_SIZE) byte maximum)))
endef

define compute_srcs
$(eval DEP_LIB_C_SRCS = $(wildcard $(patsubst %,%*.S,$(LIBDIRS))))
$(eval TMP_OBJS = $(patsubst $(APPLICATION_PATH)/%.S,build/%.o,$(DEP_LIB_C_SRCS)))
$(eval OBJ += $(patsubst $(USER_LIB_PATH)/%.S,build/user_libs/%.o,$(TMP_OBJS)))
$(eval DEP_LIB_C_SRCS = $(wildcard $(patsubst %,%*.c,$(LIBDIRS))))
$(eval TMP_OBJS = $(patsubst $(APPLICATION_PATH)/%.c,build/%.o,$(DEP_LIB_C_SRCS)))
$(eval OBJ += $(patsubst $(USER_LIB_PATH)/%.c,build/user_libs/%.o,$(TMP_OBJS)))
$(eval DEP_LIB_CPP_SRCS = $(wildcard $(patsubst %,%*.cpp,$(LIBDIRS))))
$(eval TMP_OBJS = $(patsubst $(APPLICATION_PATH)/%.cpp,build/%.o,$(DEP_LIB_CPP_SRCS)))
$(eval OBJ += $(patsubst $(USER_LIB_PATH)/%.cpp,build/user_libs/%.o,$(TMP_OBJS)))
$(info $(OBJS))
endef

CPPFLAGS = $(SDK_INCS) $(CFG_INCS)
BOARD_DIR := $(APPLICATION_PATH)/hardware/$(PLATFORM)/$(BOARD)
COMMON_LIB_PATH := $(APPLICATION_PATH)/libraries
ARCH_LIB_PATH := $(APPLICATION_PATH)/cores/$(ARCH)/libraries
ARCH_CORE_PATH := $(APPLICATION_PATH)/cores/$(ARCH)
COMMON_CORE_DIR := $(APPLICATION_PATH)/cores/Common
DIRS := $(COMMON_LIB_PATH) $(USER_LIB_PATH) $(BOARD_DIR) $(CORES) $(ARCH_CORE_PATH) $(COMMON_CORE_DIR) $(ARCH_LIB_PATH)
INCLUDE_DIRS = $(foreach dir, $(DIRS), ${sort ${dir ${wildcard ${dir}/*/ ${dir}/*/utility/}}})
CPPFLAGS += $(foreach includedir,$(INCLUDE_DIRS),-I$(includedir))

# define CC3200 SDK libs and headers based on definitions above
SDK_LIBS = "$(SDKROOT)/cc3200-sdk/simplelink/gcc/exe/libsimplelink.a" \
           "$(SDKROOT)/cc3200-sdk/oslib/gcc/exe/libtirtos.a" \
           "$(SDKROOT)/cc3200-sdk/driverlib/gcc/exe/libdriver.a"

SDK_INCS = -I"$(SDKROOT)/cc3200-sdk/simplelink/include" \
           -I"$(SDKROOT)/cc3200-sdk"

CPPFLAGS += -DARDUINO=101 -DENERGIA=14
#$(info SDK_INCS= $(SDK_INCS))
#$(info $(CPPFLAGS))

# define TI-RTOS and Energia wiring headers based on CLOSURE above
CFG_INCS = -I "$(CLOSURE)" -I "$(CLOSURE)/src" \
           -I "$(CLOSURE)/tink/runtime/wiring" 

# C compiler-specific options and commands
#    --cmd-file=...  - use the options defined in the specified file
#    -g              - compile for debug
#
CCOPTS  = -Os @"$(CLOSURE)/compiler.opt" -g -D cc3200=1 -D CCWARE=1
CC      = $(CCROOT)/bin/arm-none-eabi-gcc -c
LINK    = $(CCROOT)/bin/arm-none-eabi-gcc $(CCOPTS) -nostartfiles -Wl,--no-wchar-size-warning -Wl,-static -Wl,--gc-sections -L"$(CLOSURE)" -L"$(CCROOT)/lib"
OBJCOPY = $(CCROOT)/bin/arm-none-eabi-objcopy
OBJCOPY_FLAGS = -O binary
SIZE := $(CCROOT)/bin/arm-none-eabi-size

SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, %.obj, $(SRC))

$(eval $(call compute_dependencies, $(MAINSKETCH) $(EXTRA_SOURCES)))
$(eval $(call compute_srcs))

$(info sources $(SRC))
$(info objects $(OBJ))

#CPPFLAGS += $(foreach includedir,$(INCLUDE_DIRS),-I$(includedir))

# build rules
all: $(MAINSKETCH).bin

%.bin: %.elf
	$(info Creating $@)
	@$(OBJCOPY) $(OBJCOPY_FLAGS) $< $@
	$(call size)
	$(info >>>> Done <<<<)

$(MAINSKETCH).elf: $(OBJ)
	@echo armlink $(OBJ)
	$(LINK) $(OBJ) -Wl,-T"$(CLOSURE)/linker.cmd" $(SDK_LIBS) -lstdc++ -lgcc -lc -lm -lnosys -Wl,-Map=$*.map -o $@

%.obj: %.cpp
	@echo armcl $*.cpp
	$(CC) $(CCOPTS) $(CPPFLAGS) -I "$(CCROOT)/include" $(CFG_INCS) $(SDK_INCS) $< -o $@

# User libraries
build/user_libs/%.o: $(USER_LIB_PATH)/%.c
ifeq ($(OS),Windows_NT)
	$(shell mkdir $(dir $(subst /,\,$@)) >nul 2>nul)
else
	@mkdir -p $(dir $@)
endif
	$(info Compiling $@)
	$(CC) $(CCOPTS) $(CFLAGS) $(CPPFLAGS) -I "$(CCROOT)/include" $(CFG_INCS) $(SDK_INCS) $< -o $@

build/user_libs/%.o: $(USER_LIB_PATH)/%.S
ifeq ($(OS),Windows_NT)
	$(shell mkdir $(dir $(subst /,\,$@)) >nul 2>nul)
else
	@mkdir -p $(dir $@)
endif
	$(info Compiling $@)
	$(CC) $(CCOPTS) $(ASFLAGS) $(CPPFLAGS) -I "$(CCROOT)/include" $(CFG_INCS) $(SDK_INCS) $< -o $@

build/user_libs/%.o: $(USER_LIB_PATH)/%.cpp
ifeq ($(OS),Windows_NT)
	$(shell mkdir $(dir $(subst /,\,$@)) >nul 2>nul)
else
	@mkdir -p $(dir $@)
endif
	$(info Compiling $@)
	$(CC) $(CCOPTS) $(CPPFLAGS) -I "$(CCROOT)/include" $(CFG_INCS) $(SDK_INCS) $< -o $@

clean:
	@rm -f *.obj *.elf *.map *.bin

.PHONY: upload
upload:
	$(shell cd $(CCROOT)/bin; $(UPLOAD_COMMAND))
