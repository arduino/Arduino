# define CC3200 SDK libs and headers based on definitions above
#SDK_LIBS := $(APPLICATION_PATH)/hardware/cc3200emt/cc3200-sdk/simplelink/gcc/exe/libsimplelink.a \
#           $(APPLICATION_PATH)/hardware/cc3200emt/cc3200-sdk/oslib/gcc/exe/libtirtos.a

#SDK_INCS := -I$(APPLICATION_PATH)/hardware/cc3200emt/cc3200-sdk/simplelink/include \
#           -I$(APPLICATION_PATH)/hardware/cc3200emt/cc3200-sdk

SDK_INCS := -I$(APPLICATION_PATH)/hardware/cc3200emt/cores/cc3200emt/driverlib -I$(APPLICATION_PATH)/hardware/cc3200emt/cores/cc3200emt/inc

#VFP := -mcpu=cortex-m4 -mfloat-abi=soft
VFP := -mfloat-abi=soft

CPPFLAGS +=-DSL_PLATFORM_MULTI_THREADED
CFLAGS += -DSL_PLATFORM_MULTI_THREADED -DF_CPU=$(F_CPU) -D__CC3200R1MXRGCR__ -Dxdc__nolocalstring=1
OBJCOPY = $(CCROOT)/bin/arm-none-eabi-objcopy
OBJCOPY_FLAGS = -O binary
PLAT := cc3200
