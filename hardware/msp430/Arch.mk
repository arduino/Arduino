######################################
# Common amongst all boards for this architecture
CFLAGS := -Os -DF_CPU=$(F_CPU) -g -Os -w -Wall -ffunction-sections -fdata-sections -DARDUINO=101 -DENERGIA=12 $(EXTRA_CFLAGS)
CPPFLAGS := $(CFLAGS) -fno-threadsafe-statics -funsigned-bitfields -fpack-struct -fshort-enums -fno-exceptions -fno-rtti
ASFLAGS := -DF_CPU=$(F_CPU) -x assembler-with-cpp
LDFLAGS := $(MCU_FLAG) -Os -Wl,--gc-sections,-u,main $(EXTRA_LDFLAGS)
TOOLS_PATH := $(APPLICATION_PATH)/hardware/tools/msp430/bin
CC := $(TOOLS_PATH)/msp430-gcc
CXX := $(TOOLS_PATH)/msp430-g++
AR := $(TOOLS_PATH)/msp430-ar
SIZE := $(TOOLS_PATH)/msp430-size
MSPDEBUG := LD_LIBRARY_PATH=$(APPLICATION_PATH)/hardware/tools/msp430/mspdebug $(LD_LIBRARY_PATH) $(APPLICATION_PATH)/hardware/tools/msp430/mspdebug/mspdebug
OBJCOPY := $(TOOLS_PATH)/msp430-objcopy
OBJCOPY_FLAGS := -O ihex -R .eeprom
OBJDUMP := $(TOOLS_PATH)/msp430-objdump
######################################
