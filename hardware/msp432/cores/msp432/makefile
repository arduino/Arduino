#
#  This library requires the installation directory of each of the
#  following prerequisite components:
#      CCROOT  - the TI arm compiler (version 5.1.5 or above)
#      SDKROOT - the CC3200 simplelink SDK (version 1.0.0 patched for C++)
#      XDCROOT - XDCtools (version 3.30.05 or above)
#      TIRTOS  - TI-RTOS for cc3200 (version 2.10.01 or above)
#      TINK2   - the packages/ folder in the tink2 product (version 1.0.0.5
#                or above)
#
#  For example, on Windows, these might be set as follows:
#      CCROOT  = "C:/ti/ccs6.0.190/ccsv6/tools/compiler/arm_5.1.5"
#      SDKROOT = "C:/ti/CC3200SDK"
#      XDCROOT = "C:/ti/xdctools_3_30_05_60_core"
#      TIRTOS  = "C:/ti/tirtos_simplelink_2_10_01_38"
#      TINK2   = "C:/ti/tink2_1_00_00_05/packages"
#
TREE_ROOT = $(firstword $(subst /src/, /src/,$(CURDIR)))

# modify the following to suit your environment
CCROOT  = $(TOOLS)/vendors/ti/arm/5.1.5/Linux
SDKROOT = $(wildcard $(TREE_ROOT)/imports/CC3200SDK_*)
XDCROOT = $(wildcard $(TREES)/xdcprod/xdcprod-t61/product/Linux/xdctools*)
TIRTOS  = $(wildcard $(TREES)/zumaprod/zumaprod-d38/exports/tirtos_full_*/)
TINK2   = $(TREE_ROOT)/src

# define SYSBIOS based on settings above
SYSBIOS = $(wildcard $(TIRTOS)/products/bios_*)

# define commands used below
CC = $(CCROOT)/bin/armcl
AR = $(CCROOT)/bin/armar
ifneq (,$(wildcard $(XDCROOT)/bin/rm.exe))
    RMDIR = $(XDCROOT)/bin/rm -rf
else
    RMDIR = rm -rf
endif

CCRTOPTS = -mv7M4 --code_state=16 --float_support=vfplib --abi=eabi -me
CCOPTS = -g --gcc --diag_warning=225

DEFS = --define=PART_CC3200 --define=cc3200 \
       --define=CCWARE --define=SL_FULL --define=SL_PLATFORM_MULTI_THREADED 

INCS = --include_path=$(CCROOT)/include \
       --include_path="${XDCROOT}/packages" \
       --include_path="${TIRTOS}/packages" \
       --include_path="${SYSBIOS}/packages" \
       --include_path="${SDKROOT}/cc3200-sdk" \
       --include_path="${SDKROOT}/cc3200-sdk/driverlib" \
       --include_path="${SDKROOT}/cc3200-sdk/inc" \
       --include_path="${SDKROOT}/cc3200-sdk/oslib" \
       --include_path="${SDKROOT}/cc3200-sdk/simplelink/include" \
       --include_path="${TINK2}"

C_OBJS = $(patsubst %.c, lib/%.obj, $(wildcard *.c))
CPP_OBJS = $(patsubst %.cpp, lib/%.obj, $(wildcard *.cpp))

LIB = lib/tink.runtime.wiring.lib
ifeq (,$(wildcard lib))
    $(shell mkdir lib)
endif

lib/%.obj: %.c
	@echo cc $<
	$(CC) $(CCRTOPTS) $(CCOPTS) $(DEFS) $(INCS) $< -fr lib

lib/%.obj: %.cpp
	@echo cpp $<
	$(CC) $(CCRTOPTS) $(CCOPTS) $(DEFS) $(INCS) $< -fr lib

all: $(LIB)

$(LIB): $(C_OBJS) $(CPP_OBJS)
	@echo 'Building $@'
	@echo 'Invoking: ARM Archiver'
	$(AR) r "${LIB}" $(C_OBJS) $(CPP_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

clean:
	-@$(RMDIR) lib; mkdir lib
