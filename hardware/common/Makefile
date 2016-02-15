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
BOARD_DIR := $(APPLICATION_PATH)/hardware/$(PLATFORM)/variants/$(BOARD)
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


ifeq ($(BUILD_DRVLIB),true)
export PATH := $(CCROOT)/bin:$(PATH)
DRV_LIB := $(APPLICATION_PATH)/hardware/$(PLATFORM)/cores/$(PLATFORM)/driverlib/yourlibdriverlib.a
else
DRV_LIB := $(APPLICATION_PATH)/hardware/$(PLATFORM)/cores/$(PLATFORM)/driverlib/libdriverlib.a
endif

# Use the preprocessor to find the dependencies. What we are really after is what libraries the Sketch depends on
define deps
$(foreach SRC, $1, $(shell $(CC) $(MCU_FLAG) $(CCOPTS) -MM $(CFLAGS) $(SDK_INCS) $(CFG_INCS) $(SRC)))
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
	# Store the current dependencies for use later on
	$(eval LIBDIRS += $(_LIBDIRS)) \
	# Compute the source files
	$(eval _SRCS += $(wildcard $(patsubst %,%*.cpp,$(_LIBDIRS)))),)
endef

define size
$(eval _SIZE = $(shell $(SIZE) $(MAINSKETCH).elf))
$(eval $(info Binary sketch size: $(word 7, $(_SIZE)) bytes (of a $(FLASH_SIZE) byte maximum)))
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
endef

include $(APPLICATION_PATH)/hardware/$(PLATFORM)/Plat.mk

WIRING_DIR := $(APPLICATION_PATH)/hardware/emt/ti/runtime/wiring/
ARCH_LIB_PATH := $(APPLICATION_PATH)/hardware/$(PLATFORM)/libraries
ARCH_CORE_PATH := $(APPLICATION_PATH)/hardware/$(PLATFORM)/cores/$(PLATFORM)
DRV_LIB_PATH := $(APPLICATION_PATH)/hardware/$(PLATFORM)/cores/$(PLATFORM)/driverlib
ifeq ($(OS),Windows_NT)
COMMON_CORE_DIR := $(APPLICATION_PATH)\hardware\emt
else
COMMON_CORE_DIR := $(APPLICATION_PATH)/hardware/emt
endif

ifeq ($(OS),Windows_NT)
ARCH_EMT_DIR := $(COMMON_CORE_DIR)\ti\runtime\wiring\$(PLAT)
else
ARCH_EMT_DIR := $(COMMON_CORE_DIR)/ti/runtime/wiring/$(PLAT)
endif

DIRS := $(ARCH_LIB_PATH) $(COMMON_LIB_PATH) $(USER_LIB_PATH) $(BOARD_DIR) $(CORES) $(ARCH_CORE_PATH)
INCLUDE_DIRS = $(foreach dir, $(DIRS), ${sort ${dir ${wildcard ${dir}/*/ ${dir}/*/utility/}}})
# Exclude driverlib path from include paths
INCLUDE_DIRS := $(filter-out $(DRV_LIB_PATH)/, $(INCLUDE_DIRS))
INCLUDE_DIRS += $(COMMON_CORE_DIR) $(ARCH_EMT_DIR) $(WIRING_DIR)
CFLAGS += $(foreach includedir,$(INCLUDE_DIRS),-I$(includedir))


CFLAGS += -ffunction-sections -fdata-sections -DARDUINO=101 -DBOARD_$(BOARD) -DENERGIA=$(ENERGIA_VERSION) $(MCU_FLAG) $(VFP)
CPPFLAGS += -fno-exceptions -fno-rtti

# define TI-RTOS and Energia wiring headers based on CLOSURE above
CFG_INCS = -I "$(CLOSURE)" -I "$(CLOSURE)"

# C compiler-specific options and commands
#    --cmd-file=...  - use the options defined in the specified file
#    -g              - compile for debug
#
CCOPTS  = -Os @"$(COMMON_CORE_DIR)/ti/runtime/wiring/$(PLAT)/compiler.opt"
CC      = $(CCROOT)/bin/arm-none-eabi-gcc -c
LINK    = $(CCROOT)/bin/arm-none-eabi-gcc $(CCOPTS) -nostartfiles -Wl,--no-wchar-size-warning -Wl,-static -Wl,--gc-sections -L"$(CLOSURE)" -L"$(CCROOT)/lib"
SIZE := $(CCROOT)/bin/arm-none-eabi-size
CORE_FROM_SOURCE = no

SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, %.obj, $(SRC))


ifeq ($(CORE_FROM_SOURCE), yes)
CORE_CPP_SRCS = $(wildcard $(ARCH_CORE_PATH)/*.cpp)
OBJ += $(patsubst $(APPLICATION_PATH)/%.cpp,build/%.o,$(CORE_CPP_SRCS))

CORE_C_SRCS = $(wildcard $(ARCH_CORE_PATH)/*.c)
OBJ += $(patsubst $(APPLICATION_PATH)/%.c,build/%.o,$(CORE_C_SRCS))

CORE_COMMON_C_SRCS = $(wildcard $(COMMON_CORE_DIR)/*.c)
OBJ += $(patsubst $(APPLICATION_PATH)/%.c,build/%.o,$(CORE_COMMON_C_SRCS))

CORE_COMMON_AS_SRCS = $(wildcard $(COMMON_CORE_PATH)/*.S)
OBJ += $(patsubst $(APPLICATION_PATH)/%.S,build/%.o,$(CORE_COMMON_AS_SRCS))

CORE_COMMON_CPP_SRCS = $(wildcard $(COMMON_CORE_DIR)/*.cpp)
OBJ += $(patsubst $(APPLICATION_PATH)/%.cpp,build/%.o,$(CORE_COMMON_CPP_SRCS))
endif


$(eval $(call compute_dependencies, $(MAINSKETCH) $(EXTRA_SOURCES)))
$(eval $(call compute_srcs))

LD_FLAGS += -L$(COMMON_CORE_DIR)/ti/runtime/wiring/$(PLAT) -L$(COMMON_CORE_DIR)/ti/runtime/wiring/$(PLAT)/variants/$(BOARD) -L$(COMMON_CORE_DIR) $(MCU_FLAG) -L$(APPLICATION_PATH)/hardware/$(PLATFORM)/variants/$(BOARD) -L$(APPLICATION_PATH)/hardware/common/libs 
# build rules
all: $(MAINSKETCH).bin

%.bin: %.elf
ifndef OBJCOPY
else
	$(info Creating $@)
	$(OBJCOPY) $(OBJCOPY_FLAGS) $< $@
endif
ifeq ($(OS),Windows_NT)
	xcopy $(ARCH_EMT_DIR)\configPkg\package\cfg\energia_*.rov.xs . /Y 
else
	cp $(ARCH_EMT_DIR)/configPkg/package/cfg/energia_*.rov.xs .
endif
	$(call size)
	$(info >>>> Done <<<<)

driverlib:
ifeq ($(BUILD_DRVLIB),true)
#$(MAKE) -C $(ARCH_CORE_PATH)/driverlib clean
	$(MAKE) -C $(ARCH_CORE_PATH)/driverlib
endif

$(MAINSKETCH).elf: driverlib $(OBJ)
	@echo armlink $(OBJ)
	$(LINK) $(OBJ) -Wl,-T"$(COMMON_CORE_DIR)/ti/runtime/wiring/$(PLAT)/linker.cmd" $(LD_FLAGS) $(DRV_LIB) $(SDK_LIBS) -lstdc++ -lgcc -lc -lm -lnosys -Wl,-Map=$(MAINSKETCH).map -o $@

%.obj: %.cpp
	@echo armcl $*.cpp
	$(CC) $(CCOPTS) $(CFLAGS) $(CPPFLAGS) -I "$(CCROOT)/include" $(CFG_INCS) $(SDK_INCS) $< -o $@

#Core libraries and core sources
build/%.o: $(APPLICATION_PATH)/%.c
ifeq ($(OS),Windows_NT)
	$(shell mkdir $(dir $(subst /,\,$@)) >nul 2>nul)
else
	@mkdir -p $(dir $@)
endif
	$(info Compiling $@)
	$(CC) $(CCOPTS) $(CFLAGS) -I "$(CCROOT)/include" $(CFG_INCS) $(SDK_INCS) $< -o $@

build/%.o: $(APPLICATION_PATH)/%.S
ifeq ($(OS),Windows_NT)
	$(shell mkdir $(dir $(subst /,\,$@)) >nul 2>nul)
else
	@mkdir -p $(dir $@)
endif
	$(info Compiling $@)
	$(CC) $(CCOPTS) $(CFLAGS) -I "$(CCROOT)/include" $(CFG_INCS) $(SDK_INCS) $< -o $@

build/%.o: $(APPLICATION_PATH)/%.cpp
ifeq ($(OS),Windows_NT)
	$(shell mkdir $(dir $(subst /,\,$@)) >nul 2>nul)
else
	@mkdir -p $(dir $@)
endif
	$(info Compiling $@)
	$(CC) $(CCOPTS) $(CFLAGS) $(CPPFLAGS) -I "$(CCROOT)/include" $(CFG_INCS) $(SDK_INCS) $< -o $@

# User libraries
build/user_libs/%.o: $(USER_LIB_PATH)/%.c
ifeq ($(OS),Windows_NT)
	$(shell mkdir $(dir $(subst /,\,$@)) >nul 2>nul)
else
	@mkdir -p $(dir $@)
endif
	$(info Compiling $@)
	$(CC) $(CCOPTS) $(CFLAGS) -I "$(CCROOT)/include" $(CFG_INCS) $(SDK_INCS) $< -o $@

build/user_libs/%.o: $(USER_LIB_PATH)/%.S
ifeq ($(OS),Windows_NT)
	$(shell mkdir $(dir $(subst /,\,$@)) >nul 2>nul)
else
	@mkdir -p $(dir $@)
endif
	$(info Compiling $@)
	$(CC) $(CCOPTS) $(ASFLAGS) -I "$(CCROOT)/include" $(CFG_INCS) $(SDK_INCS) $< -o $@

build/user_libs/%.o: $(USER_LIB_PATH)/%.cpp
ifeq ($(OS),Windows_NT)
	$(shell mkdir $(dir $(subst /,\,$@)) >nul 2>nul)
else
	@mkdir -p $(dir $@)
endif
	$(info Compiling $@)
	$(CC) $(CCOPTS) $(CFLAGS) $(CPPFLAGS) -I "$(CCROOT)/include" $(CFG_INCS) $(SDK_INCS) $< -o $@

clean:
	$(info >>>> Clean <<<<)
	$(RM)
ifeq ($(OS),Windows_NT)
	$(shell del /f *.obj *.elf *.map *.bin >nul 2>nul)
else
	@rm -f *.obj *.elf *.map *.bin
endif

.PHONY: upload
upload: $(MAINSKETCH).bin
	$(shell cd $(CCROOT)/bin; $(UPLOAD_COMMAND))
